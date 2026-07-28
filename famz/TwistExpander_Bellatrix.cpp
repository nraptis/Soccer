#include "TwistExpander_Bellatrix.hpp"
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

TwistExpander_Bellatrix::TwistExpander_Bellatrix()
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

void TwistExpander_Bellatrix::KDF_A(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Bellatrix::KDF_B(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Bellatrix::KDF_C(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Bellatrix::KDF_D(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Bellatrix::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xC1B5A29A5457DAD9ULL;
    std::uint64_t aIngress = 0xD8BABFC9A8FBB1DBULL;
    std::uint64_t aCarry = 0xE23344E19904D59DULL;

    std::uint64_t aWandererA = 0xF5C2F0B4DA2C50F6ULL;
    std::uint64_t aWandererB = 0xC066CB7DE3B295E6ULL;
    std::uint64_t aWandererC = 0x9D0FB80C76928671ULL;
    std::uint64_t aWandererD = 0xF64E805B90B2A07CULL;
    std::uint64_t aWandererE = 0xDE0333493AD90FBDULL;
    std::uint64_t aWandererF = 0xF6ED3DC27FA5A363ULL;
    std::uint64_t aWandererG = 0x81EAF3DFEF970520ULL;
    std::uint64_t aWandererH = 0xCEC401A07CF194E8ULL;
    std::uint64_t aWandererI = 0xFA541298FC5C6DAFULL;
    std::uint64_t aWandererJ = 0xA0D6BEE05B341783ULL;
    std::uint64_t aWandererK = 0xAD6D590A17B9709AULL;

    //
    // KeyRotate A
    //
    aPrevious = 0xCFAA57E94EAC7145ULL;
    aIngress = 0xA7FA3E465222C048ULL;
    aCarry = 0xA4E7CD744811383DULL;
    aWandererA = 0x99E7D703F5DFE659ULL;
    aWandererB = 0x8132CEAA34C32AF9ULL;
    aWandererC = 0xF54610EC65E8BCB8ULL;
    aWandererD = 0xB45D85B277D23A9CULL;
    aWandererE = 0xBF557941E41E6AC8ULL;
    aWandererF = 0xE01C7C96A56C441DULL;
    aWandererG = 0xAC6C335020E4B4A2ULL;
    aWandererH = 0xAE8B9B55FCAAE5B0ULL;
    aWandererI = 0xA682506EF17FA485ULL;
    aWandererJ = 0xC62328464DA7E1EFULL;
    aWandererK = 0xF74FF02C2FCBA045ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateAConstants), &(pWorkSpace->mDomainBundle.mKeyRotateASalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeyRotateAConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xA5829D667E3B8B47ULL;
    aIngress = 0x87140A43721D46A5ULL;
    aCarry = 0x97CE9660E13A1A06ULL;
    aWandererA = 0xFA07353659BE2270ULL;
    aWandererB = 0x8DEFF28B037BCEDFULL;
    aWandererC = 0x900A63AFC4DD7268ULL;
    aWandererD = 0xAB90EBB9FE34E8B6ULL;
    aWandererE = 0xA8F482FDBED5D1DFULL;
    aWandererF = 0xC9BA0CD2A8A43EB7ULL;
    aWandererG = 0x8A93232B6C63DD61ULL;
    aWandererH = 0xE74D81A8295ED789ULL;
    aWandererI = 0xEF7B2C764D7F1226ULL;
    aWandererJ = 0xBC93ACB2550AABEFULL;
    aWandererK = 0xBC71E70B06751660ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants), &(pWorkSpace->mDomainBundle.mKeyRotateBSalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0x92752D4E923376CCULL;
    aIngress = 0x913CF56D8D008356ULL;
    aCarry = 0xB483837C2F2469CCULL;
    aWandererA = 0x9E591D0A583A0868ULL;
    aWandererB = 0xFD7327967271A7C6ULL;
    aWandererC = 0xCADA5D9BDE077A8DULL;
    aWandererD = 0xD49CA3205CEF709FULL;
    aWandererE = 0xA079900EDE407035ULL;
    aWandererF = 0xB4C1D7F37560E0B9ULL;
    aWandererG = 0xDD5860D3E6FF1B33ULL;
    aWandererH = 0xDB3B06DCD55DBE51ULL;
    aWandererI = 0xEBD22F4F48AFF079ULL;
    aWandererJ = 0xE6FF67EAAFF16CD0ULL;
    aWandererK = 0xD1B16E93F3A92368ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnAConstants), &(mDomainBundleInbuilt.mKeySpawnASalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants), &(pWorkSpace->mDomainBundle.mKeySpawnASalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeySpawnAConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xFF0A9CF83F8CB6F2ULL;
    aIngress = 0xF089D18DE7BB199AULL;
    aCarry = 0xE1D0BC29DCE73FD3ULL;
    aWandererA = 0x89E008DF7D17640CULL;
    aWandererB = 0xAB01E68262F0D713ULL;
    aWandererC = 0xD7B8E2A2706F9695ULL;
    aWandererD = 0xB6F7CD51BD8DA19DULL;
    aWandererE = 0xF02696963BA0F123ULL;
    aWandererF = 0x8F250CD7BF18CB82ULL;
    aWandererG = 0x9C393EA9DFD1E90AULL;
    aWandererH = 0xF9B87D319C457A84ULL;
    aWandererI = 0xC03E02DDC100B559ULL;
    aWandererJ = 0xACB9A0F8041EA623ULL;
    aWandererK = 0x871B6C8B62741224ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnBConstants), &(mDomainBundleInbuilt.mKeySpawnBSalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants), &(pWorkSpace->mDomainBundle.mKeySpawnBSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xD5430275B8A54A0BULL;
    aIngress = 0xD4D8CFD278FB3DBAULL;
    aCarry = 0xB08BF541E1A5449BULL;
    aWandererA = 0xABC77C36F4B8FDDAULL;
    aWandererB = 0xE1391AAB20EE7926ULL;
    aWandererC = 0x94C73532C1B02B14ULL;
    aWandererD = 0xDFE1E2866A62E3EBULL;
    aWandererE = 0xDDE0A933B720F6E8ULL;
    aWandererF = 0xA8C24793B5B7F846ULL;
    aWandererG = 0xD12DAC4AFB0DE785ULL;
    aWandererH = 0xDDFE13A91272CCA4ULL;
    aWandererI = 0xFF376FB45F8E54EDULL;
    aWandererJ = 0xE8C6FE3DF0B6B429ULL;
    aWandererK = 0xE85DF42ECB2F551CULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mTwistConstants), &(pWorkSpace->mDomainBundle.mTwistSalts), pSnowLaneB, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mTwistSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xBB2EC77244724F09ULL;
    aIngress = 0xE261A5FCB111D663ULL;
    aCarry = 0x8144B4A9232B2B55ULL;
    aWandererA = 0xA821A08253C6B68BULL;
    aWandererB = 0x930EE29AE3FF1160ULL;
    aWandererC = 0xC87E9A05E4C17B10ULL;
    aWandererD = 0xE7BEAA480B76EE85ULL;
    aWandererE = 0xBCC64EBD199FBD97ULL;
    aWandererF = 0xD7CE8E5B259653A7ULL;
    aWandererG = 0x98C95D111CCAA1B5ULL;
    aWandererH = 0xE64EAD2B123CADC1ULL;
    aWandererI = 0x8C80F7F99660B167ULL;
    aWandererJ = 0xE9B60526DAFC25E5ULL;
    aWandererK = 0xC1C4FAEF6CEE962EULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mSeedSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xDCBB764F95611686ULL;
    aIngress = 0x87B25C93D376A26CULL;
    aCarry = 0xF762127F0CCB87B8ULL;
    aWandererA = 0xDA1D3E174FAE9A85ULL;
    aWandererB = 0xA899E4C775A7E3FAULL;
    aWandererC = 0x8F440D3D0DA10B67ULL;
    aWandererD = 0xACE1137BA987A418ULL;
    aWandererE = 0xCEC86D3E6DB77A63ULL;
    aWandererF = 0xB71C2C5281B0EF70ULL;
    aWandererG = 0xB9920B1BD1FDE94FULL;
    aWandererH = 0xBD2DFD8C9FCF59B0ULL;
    aWandererI = 0xFAF8D4EBD06E19AFULL;
    aWandererJ = 0xD89DB87F9B686A88ULL;
    aWandererK = 0xEA207B649BBB5FF5ULL;
    //
    TwistExpander_Bellatrix_Arx::SEED_A(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Bellatrix_Arx::SEED_B(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Bellatrix_Arx::SEED_C(pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::SEED_D(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Bellatrix_Arx::SEED_E(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Bellatrix_Arx::SEED_F(pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::SEED_G(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Bellatrix_Arx::SEED_H(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Bellatrix_Arx::SEED_I(pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::SEED_J(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Bellatrix_Arx::SEED_K(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Bellatrix_Arx::SEED_L(pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::SEED_M(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Bellatrix_Arx::SEED_N(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Bellatrix_Arx::KEY_A_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Bellatrix_Arx::KEY_A_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Bellatrix_Arx::KEY_A_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Bellatrix_Arx::KEY_A_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Bellatrix_Arx::KEY_A_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Bellatrix_Arx::KEY_A_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Bellatrix_Arx::KEY_A_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Bellatrix_Arx::KEY_A_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Bellatrix_Arx::KEY_B_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Bellatrix_Arx::KEY_B_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Bellatrix_Arx::KEY_B_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Bellatrix_Arx::KEY_B_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Bellatrix_Arx::KEY_B_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Bellatrix_Arx::KEY_B_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Bellatrix_Arx::KEY_B_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Bellatrix_Arx::KEY_B_H(pWorkSpace,
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

void TwistExpander_Bellatrix::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE81935719466BA78ULL; std::uint64_t aIngress = 0xCD3A940A0D187D60ULL; std::uint64_t aCarry = 0xAB2452A0C0319947ULL;

    std::uint64_t aWandererA = 0xEEA6706C88257CB6ULL; std::uint64_t aWandererB = 0x87D846A6216B04FBULL; std::uint64_t aWandererC = 0xCA1B13660F8623F3ULL; std::uint64_t aWandererD = 0xB961EBE8BB14DEBFULL;
    std::uint64_t aWandererE = 0xF148185974D33672ULL; std::uint64_t aWandererF = 0x9363F5E56B1D1051ULL; std::uint64_t aWandererG = 0x8D1FB86006B6EFC2ULL; std::uint64_t aWandererH = 0x8756E3AB1D8CBD90ULL;
    std::uint64_t aWandererI = 0xCFC8AB67C45AFDC8ULL; std::uint64_t aWandererJ = 0xB085E36638A229C7ULL; std::uint64_t aWandererK = 0xCC90805DA0325E1BULL;

    // [twist]
        aPrevious = 0x8848F7FFB736B09EULL;
        aCarry = 0x919AC3032B01909FULL;
        aWandererA = 0x950B72887A267206ULL;
        aWandererB = 0x8D435C42B7146558ULL;
        aWandererC = 0xCD013B5C4A8084DEULL;
        aWandererD = 0xAD54D6422A0B395AULL;
        aWandererE = 0xAFAE12A34C31E601ULL;
        aWandererF = 0xF43952CEC8936099ULL;
        aWandererG = 0x9730320BD1509B36ULL;
        aWandererH = 0xF0EE03AAD9F81401ULL;
        aWandererI = 0xB7A6585B936E086CULL;
        aWandererJ = 0xC3A4392745BB8855ULL;
        aWandererK = 0xBCE82187143DEABCULL;
    TwistExpander_Bellatrix_Arx::TWIST_A(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Bellatrix_Arx::TWIST_B(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Bellatrix_Arx::TWIST_C(pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::TWIST_D(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Bellatrix_Arx::TWIST_E(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Bellatrix_Arx::TWIST_F(pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::TWIST_G(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Bellatrix_Arx::TWIST_H(pWorkSpace,
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

void TwistExpander_Bellatrix::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::GROW_A_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Bellatrix_Arx::GROW_A_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Bellatrix_Arx::GROW_A_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Bellatrix_Arx::GROW_A_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Bellatrix::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::GROW_B_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Bellatrix_Arx::GROW_B_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Bellatrix_Arx::GROW_B_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Bellatrix_Arx::GROW_B_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Bellatrix::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 12 of 33
    // Exploration cases: 0
    // Structural maximin 533 / 674; family total 5979
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
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7789U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 47U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3738U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4098U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1690U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 92U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2005U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1330U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1735U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1465U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1870U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 12 of 33
    // Exploration cases: 0
    // Structural maximin 529 / 674; family total 5951
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
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7519U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2838U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2928U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3288U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1105U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 610U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 790U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1285U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 655U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 835U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1150U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 565U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Bellatrix::kKeyRotateASalts = {
    {
        {
            0xF5FA9AB044AC7012ULL, 0x15ABC03378EBC545ULL, 0xFFAA559114496F17ULL, 0x059D12C719B849CEULL, 
            0xCD550F68791BBC61ULL, 0xE52D8C7A4662A2BEULL, 0x0B138E63ADD01E8DULL, 0x42DE835172C6878BULL, 
            0x47DABF123B186C47ULL, 0xF9BE46E1A12F7E65ULL, 0x051A24392371B25EULL, 0xFA9E076C97B00310ULL, 
            0x73C4A9D4C69C8B5AULL, 0x570F661239FDA656ULL, 0x2035D3399C068B14ULL, 0x1FF073127316534BULL, 
            0xFC9D2018B3D2B9E9ULL, 0x3065A918B2E445FEULL, 0x1DE2101CA0CE3617ULL, 0xAD3A3B2CB86AE9B0ULL, 
            0x8E685AB3D32BC1FAULL, 0x51E475077D872DBDULL, 0x421F5133A262D6CAULL, 0xFA9DEE4EF4805421ULL, 
            0x724ADDCFBFDC1D71ULL, 0x978AD39801858842ULL, 0x1D329ABF7BE04774ULL, 0xE95F315BA713661AULL, 
            0xD8F331494D6325DAULL, 0x113EDFDDE0DAD3F2ULL, 0x884CCE9763D08B8CULL, 0x4E85FF66E8A7D048ULL
        },
        {
            0x9D3F9D61C8D3269FULL, 0x06A2394362F3FA23ULL, 0x3DD029E57D357E06ULL, 0x686C49DFF09D87D0ULL, 
            0xC00C406DBABC5F0CULL, 0x84005CDE5C337669ULL, 0x3F2D6075D36EF613ULL, 0x3D7B72422E2E15EEULL, 
            0x8242B3B1B92A6B9BULL, 0x4051C509F1904F1DULL, 0xE66F8AEEA3685E29ULL, 0x32F2F4AD900E8E34ULL, 
            0xE064927ED94A7442ULL, 0xE82B239F13D215B7ULL, 0xF72F3A5C9C92B18DULL, 0xA43C8F58D5CBF096ULL, 
            0x84E1D9804705BA5FULL, 0x0B46F6793A615CBFULL, 0x54CB044500AC3E1AULL, 0x9E9C4D442F705E97ULL, 
            0xEFDDF4B1CECBC086ULL, 0x25732F96DB0742DAULL, 0x0F776D0F14335067ULL, 0x9DE65B6A03E80ED2ULL, 
            0x2300D0EA78BB2665ULL, 0x9E10DC2E4E8B2FF4ULL, 0x6B0BA01701947D84ULL, 0x3C3E145846D09FF0ULL, 
            0xB5C4F7D9615A5FA6ULL, 0xAFCF95F4E646F02CULL, 0x5B6973637C674B79ULL, 0x2FBD62C03C58D0FDULL
        },
        {
            0xD7CF3B807ED0456AULL, 0xA2D22517CB1B6B67ULL, 0x8DCC81D0D60C5243ULL, 0x33F7F41175439C1FULL, 
            0x4599BA0C9A3AB51BULL, 0x9EC6C26B7AE15F2AULL, 0x00FC11671D431D82ULL, 0xD0B4B1CE785D1D6CULL, 
            0x72C63572702C73E0ULL, 0x6580BB530E196719ULL, 0x7CE2E960DBA0C853ULL, 0xF76484AA550AB902ULL, 
            0x6BB6A6F1F60F9BA3ULL, 0xC388DDE06802ED17ULL, 0x4E1AD958D03AFD18ULL, 0x0E1D8C6340DBAA98ULL, 
            0xEDF58C4CA0BDB743ULL, 0x811E55B8D0FAB1DEULL, 0xC45F48A7BA375109ULL, 0xEB9ADFBA92CEAC90ULL, 
            0x3D1CBE81D482835FULL, 0x8406C6EFE275B833ULL, 0xD5624871343B8850ULL, 0x3E736DABD0F4E5CCULL, 
            0x740463C3ADAD918FULL, 0xB469E5617FB2C082ULL, 0x67561A525FFE45FDULL, 0x857F8CFCC122137EULL, 
            0xC8D383B0AC2AA382ULL, 0x49124C83F02F4215ULL, 0xE84A9AEC976A1810ULL, 0xC9F39F2FCBAEE2F5ULL
        },
        {
            0x587C8E641F56E1B0ULL, 0xF7A732EC2A54C56CULL, 0xEE297FB7EDCD92D9ULL, 0x9ABC46C5FC8D003EULL, 
            0xBA21E6E0A594AB3CULL, 0xE699EF1A91045B19ULL, 0xC7A23A84791731A4ULL, 0xEFB7121644992CDDULL, 
            0x27499A7650FED54DULL, 0x85EACC26C44A1F1AULL, 0xE0593246EB823597ULL, 0x699243624310A4F1ULL, 
            0x9A89FFCA728BD9F9ULL, 0x71F8AF9606247199ULL, 0xCB36D1E6C4DA468BULL, 0x102FFB0647C74D17ULL, 
            0xA04C2651481A5E67ULL, 0x79A36600D8410B80ULL, 0x16779C45CB6204E4ULL, 0x48CD917674C259CFULL, 
            0xF37EADD69228CF8FULL, 0xD463B7445D663780ULL, 0x0CAF964816630114ULL, 0x373A81DEDA01350CULL, 
            0x0C69042017F983BDULL, 0x46AEA8914EAA2294ULL, 0x36038102A3220E06ULL, 0x9E009F8B5931945DULL, 
            0x6EB7CC3C6AB622D4ULL, 0x09D8EAC0B8CAB7C4ULL, 0xC94CE5D25091D884ULL, 0xB089F5C3663311C5ULL
        },
        {
            0x14B703EF042B7247ULL, 0x7BBBD3E392DFAE46ULL, 0xD003822A7BAE53ABULL, 0x426BB6B20E6EC3D0ULL, 
            0xF51FC799EDFDCF74ULL, 0x5393EA220E724D4DULL, 0x473D4BE8A680EEB6ULL, 0x4F4021FA1E097944ULL, 
            0xBA1D1E01CB21B0FDULL, 0x32503896E69C6BF4ULL, 0xFEDEC83BE2A4AD7CULL, 0x6289406AB6376CB0ULL, 
            0x56F21A29FDE7767AULL, 0xAEC733F2FE24C463ULL, 0x65D8CD01F07C8DA2ULL, 0xC8253DF889C0830BULL, 
            0xDDEF6A05D2E10A9AULL, 0x9AA2ECEBEDE1205DULL, 0x5EF4D44179C796DDULL, 0x1C1D470354DD3F97ULL, 
            0x223C450330954CEFULL, 0xCF34373E06A5FCD7ULL, 0x1C9BEE82DB90219DULL, 0xD217547A0345B881ULL, 
            0x9D80CD91C217D582ULL, 0x8D6AB30159031166ULL, 0xC13DB5A9850AA487ULL, 0x6D0A4CB65F009AC5ULL, 
            0x3EB2F95BF27A703BULL, 0xACAF2C4AF041CE01ULL, 0x2220F1A4BA3C8D8EULL, 0x01F596AAE3C6E3E1ULL
        },
        {
            0x9C3D6EF61C49ADABULL, 0x2C71582B65A2CA7AULL, 0x78F468207DC51399ULL, 0x25C3BD5298C6A5ECULL, 
            0x87E0AEDD1DCF1760ULL, 0x7513A65EA8217A27ULL, 0xA790E56409025C20ULL, 0xF1246E5E7B5074E1ULL, 
            0x72D771F995C5DC18ULL, 0x6198D5E321497B47ULL, 0x4AE90D6568156584ULL, 0xA3CDFA971306C695ULL, 
            0x5F8075BD2C871B6DULL, 0xD9026CF77FD2E0C8ULL, 0xB36908B93CF2C96CULL, 0x32F4F8AD61EC21DBULL, 
            0x943B7C0C93633DABULL, 0x00B9D515FADEC84EULL, 0x261CA0F346A9AC26ULL, 0x9D80470701C8AE99ULL, 
            0x1EC7297E6CCA2A74ULL, 0xDAFA14615E53BF80ULL, 0x5536D0447E70DE82ULL, 0xF58A290145FF8B61ULL, 
            0x3D99913B5FF29EE7ULL, 0x247BA8992B51BC27ULL, 0x5F031AB39E71C4C7ULL, 0x5EA3239FE7E215F6ULL, 
            0x2C94DA6C01DD382DULL, 0xBB29AA2712071AC6ULL, 0xC9CFB5050BE7784FULL, 0xA872EA2CCF89B2C6ULL
        }
    },
    {
        {
            0x4F2D11B97BA6C3EEULL, 0x63007141C7A650E1ULL, 0x1248FEBA55DE2096ULL, 0x484B275190678D56ULL, 
            0xF0CB78EE85BC2299ULL, 0x08738F8B2641ADDDULL, 0x61FC9D945ACCA331ULL, 0xBFF97F776DED0AEEULL, 
            0xE0C3C9BB8E3617EDULL, 0x74B4ADC5C1896CBFULL, 0x2AEA78A326A8155AULL, 0x3B62A35F408CAB60ULL, 
            0x4460B4E4C0A11220ULL, 0xD92C6F2216CB21FEULL, 0xE959DBD952BD2892ULL, 0x2A648ADBB2D51261ULL, 
            0xE7A36F1C9103E4D0ULL, 0x5CF38FE6A8D27187ULL, 0xDD565195D0E184B2ULL, 0xB52A56790F59E5BCULL, 
            0x0E94810C2B5261A3ULL, 0xAB7449EAFB43390BULL, 0x3C465E9B3BB322CCULL, 0xFE7F9F444B26E239ULL, 
            0xB0DC13611CE04B45ULL, 0x8788E95F3D431EF4ULL, 0xB1D46635E74EE9ADULL, 0x498E633BF3425375ULL, 
            0xD48D8CADB780454AULL, 0x643006CBED4D7B6EULL, 0x418AE76389A5A979ULL, 0x68540C90E3BDF4E8ULL
        },
        {
            0x94AC8A376BB941D1ULL, 0x059EDEA6ACE29D10ULL, 0xF1B8FD83253010EEULL, 0xBF76D76523BF243CULL, 
            0x9484C01D546F83C2ULL, 0xE9496FE57B804A6EULL, 0xEF09069452085947ULL, 0x747DDB51C3487EC9ULL, 
            0x3825971E060A6B12ULL, 0x2D2063E5FB22E59AULL, 0xFDF02774DB5A41CBULL, 0x30B90A129B4F741DULL, 
            0x643C0304E6D64B67ULL, 0x881EEE6888C3FACEULL, 0xBB7B22179721B87AULL, 0x5312E534D26FE96DULL, 
            0xD7381EAA1ABDAEB1ULL, 0xC4D77DFCC2E2C8F8ULL, 0xFAD0348134725579ULL, 0xFE5C240C3E836B68ULL, 
            0x421A964382FF947BULL, 0x8F875E2D1EFC55B7ULL, 0x8C6B96053DC0BCCFULL, 0x418CF5BB2051E317ULL, 
            0xBED762B1F74735A7ULL, 0x3BDC0B17A8BB1914ULL, 0xD3361065F679F39BULL, 0xF2E43DFF81034884ULL, 
            0x8C6363E4C811B08EULL, 0xF9FF81EFC9E27E52ULL, 0xFCF264D1C978A0D0ULL, 0xE1DF8EC47BB005B4ULL
        },
        {
            0x0DD39C25AF760946ULL, 0xC193582B58BC6B71ULL, 0xC49D6DFE6AF9BCCDULL, 0x8490DECE4AF5FB6AULL, 
            0x177E6AA93901493EULL, 0x6919585A027AD2E1ULL, 0x86D88CBA2421A543ULL, 0x1568C4C8AADB6293ULL, 
            0xA8B9A36E8D1A61FEULL, 0x5540F5105D4960ACULL, 0xDB6247204785853CULL, 0x159AACF151961A36ULL, 
            0xB1AA3BD9AD23C82BULL, 0x29C4BF92D5B06EB0ULL, 0xB2F2EA28B6D9997EULL, 0xF2D0AE7FA3716D69ULL, 
            0x2654608C4AA39F3AULL, 0xE6B78F2DA1948F8FULL, 0x9F6BA01B2F7A9FAFULL, 0x8F59C9786868D2D5ULL, 
            0xC0B78A5CBF1DEF3FULL, 0xE6A8969F69B3E2E1ULL, 0x90ACB6EE95BED340ULL, 0x750C417DD3DA2E6CULL, 
            0xB03F1F1F0A907DF7ULL, 0xCF0A8C30149E8375ULL, 0x23FA79387F1E2B11ULL, 0x2CA16B48250CFDB2ULL, 
            0xBF23A9B330DB6A07ULL, 0xE2932465509A9CDFULL, 0xB060C01430AD1627ULL, 0xC00789662463B2E6ULL
        },
        {
            0xE75E9358EC91DBD5ULL, 0x4DD8FA7A2978C522ULL, 0x034FE21E2430663FULL, 0xDBAF8A783400A101ULL, 
            0x36597B2ED55857D2ULL, 0xEB8D0AA6C809F6A5ULL, 0xF835C30B95585A39ULL, 0x0D55AE910942906FULL, 
            0x2BBE9C585B6A0A1CULL, 0xDFDA619356889678ULL, 0x59A7918AE47FED90ULL, 0xDC2FEFB86764D981ULL, 
            0x62649B04C82C4FBAULL, 0xD02AB9D28CEEB7B6ULL, 0xC7E484B34A9093F5ULL, 0xECC7B0323B71D9DFULL, 
            0x1EB3389A58B14B5CULL, 0x6D4711A196DF6C56ULL, 0xA58E76A23587A043ULL, 0x5186200C20B620E5ULL, 
            0x06801F5327DE248CULL, 0x689429CB093F0C0DULL, 0xC474F6A2608E9897ULL, 0x223E123036F3765CULL, 
            0xF63F7189C619982CULL, 0x0FB95F54FC7E340DULL, 0x8B8927C138AB2C1FULL, 0x58E5D2DD7CBAA15FULL, 
            0xF5A4B935F35B68F6ULL, 0xB22A3330E983F817ULL, 0x8EB2F984AF7DDC65ULL, 0xDD984D8CBF209249ULL
        },
        {
            0x8776E28F5266FCF4ULL, 0x91CC3BE02343248CULL, 0x8FB89863A6688799ULL, 0xAB5FAFEF315E5248ULL, 
            0xD3E7080303BAEA98ULL, 0x7BA0607376E854B2ULL, 0x9964FD46840BA87AULL, 0x3A9A6FFE22E654B7ULL, 
            0x88D6B1CC4798ECCCULL, 0x1870CD61A2DAE5CDULL, 0x67952F5E026A4B67ULL, 0xB67C3C878CCF23CDULL, 
            0x2ABB0B7CE7649D5FULL, 0x4CFC6EDD64DC06E9ULL, 0x815883FC0563DF44ULL, 0xF3EA63ABFDA7A7CBULL, 
            0xC6408A99FD7118D3ULL, 0xAF377925F2569B0EULL, 0xC9CF3CE818F0A767ULL, 0xA23F52EC45D70EACULL, 
            0x5A429C904E482B35ULL, 0xCA6D088E9E262B18ULL, 0xFEE22D18AEDBC118ULL, 0xD7818F4E2167AF1AULL, 
            0xA12D2B36C272DFB7ULL, 0xC25DC2A1D2BFB8E4ULL, 0xE930FED7BD18B761ULL, 0x7987CDDC07AC25E4ULL, 
            0xC48DC7F900EDBB16ULL, 0x7C88DD562F5DD716ULL, 0xBABD4C35536FD600ULL, 0x4A73EE9A89973E19ULL
        },
        {
            0xC153A05FBA2C297DULL, 0x4DC749E807FB1184ULL, 0x4810CFFEA9D0B681ULL, 0x0DFC1DDC9312CF03ULL, 
            0xEFBFF008BA5DB21DULL, 0x520D7BFAA1850527ULL, 0x948668C6B2AB8FC4ULL, 0x0700F2E106BF03F0ULL, 
            0xDBD034B55F1C93B2ULL, 0x062528F7B2220898ULL, 0x8A454E1594349AA3ULL, 0xE8B444C5793F5BCAULL, 
            0xD6E027A67FAB95A7ULL, 0xC7217270EC1679C3ULL, 0xA8AE64370F363979ULL, 0xF2CCC3F016A63674ULL, 
            0xF7BF255A99AAFCE6ULL, 0xE8117D79FD419983ULL, 0x68E3487A582EEF77ULL, 0xC7FF70EC96886074ULL, 
            0xE1DDA10DB387F3EEULL, 0xD62CBE6B718183CFULL, 0x421AA930C477FDF7ULL, 0xA782C6F9911FD8CEULL, 
            0x261B6AC591D65277ULL, 0x54CB6374A6C540E1ULL, 0xC7D669F3E1E93363ULL, 0x915E033385F83231ULL, 
            0x6B10E0AF7956ABCDULL, 0xA161E836C4AD1D8FULL, 0xBDCD3CFBDDA9FC00ULL, 0x58E685856155092FULL
        }
    },
    {
        {
            0xC2848BAD7EE0FAC7ULL, 0xC5EC5060CA973CACULL, 0x767EF5DFF71650DFULL, 0x0EA8DF9176703D3FULL, 
            0xFB7777BD3441851BULL, 0xBB48B2F97092AFB8ULL, 0xAE18AFFF20A1B42DULL, 0x9231FB37F05D2E0BULL, 
            0x0CE29E5A533A8285ULL, 0xE0D8AD15AA19167EULL, 0x390404B48DEB7786ULL, 0xA0CCECC9E006BAC7ULL, 
            0xF9824A7C3BC23743ULL, 0xC2F7348877D0F3CDULL, 0x097E857B4151CD53ULL, 0x465CBA43D4B8E731ULL, 
            0x980EC70F72278A07ULL, 0x8384B95A68A52E8CULL, 0x4D39715BA904604DULL, 0x62DF410839E99957ULL, 
            0x8E98A1F3D6E1EB9BULL, 0xECFB3237D424E115ULL, 0xABBAAED7992CC22AULL, 0x04DB351626758035ULL, 
            0x8B23FEBE48AC4DC9ULL, 0xC4463FB872EFABB9ULL, 0xB76A6253A9E04BC2ULL, 0x7DC295FD41062C4CULL, 
            0x9649C00095C36142ULL, 0xE0830030A7E4D443ULL, 0x4BE3B41993E2AA57ULL, 0x031CEB4C98788DB4ULL
        },
        {
            0x36BA39E6CACA109DULL, 0xCAE5D3C559F3F2E6ULL, 0x25420E37F7023778ULL, 0x598DBE58E2CF0932ULL, 
            0x2B00B6DA4354F806ULL, 0x3E7112D619B298A3ULL, 0x6050FC835B63ECA4ULL, 0xBDCA343582D34C29ULL, 
            0x8DFC82FE34DA9C8DULL, 0x83C218229A9669ADULL, 0xAC91A298CA2B24B9ULL, 0xD12E8AFC9DCF631CULL, 
            0xB0C645679EA2FBA4ULL, 0xB09DA3252103AE0FULL, 0x571098657FC2574DULL, 0x9F5B3F51CC2053CBULL, 
            0xCF5C70C3395C0F45ULL, 0xEA6FA7ACED11016BULL, 0x02B2BE9E020B3916ULL, 0xE5CBA2F75AF46F4EULL, 
            0x4425F44F3B1CF934ULL, 0x3A4CEB08F493A1CDULL, 0xDEB019126AF31C11ULL, 0xA5F593216AC14155ULL, 
            0x8DB472AD41C4795FULL, 0xCEB6B015E672558BULL, 0x5DF9EF8ED9261166ULL, 0x5C467D8C9D092ECAULL, 
            0xA2345BD89F88B082ULL, 0x03CEADB704E57EE1ULL, 0x4EEABFD92449E9E6ULL, 0x1155982A37A0FCBFULL
        },
        {
            0x99CE9D82DA617126ULL, 0x09C74BDD9EFE03D5ULL, 0x871BF4E0377A82FBULL, 0x9551B6E1FAAFC472ULL, 
            0x36825290BCB4F762ULL, 0x56D80A1304D2A08EULL, 0x3D712D5DF1C60630ULL, 0xD73F92C932901BE9ULL, 
            0x8252352FDC6CA393ULL, 0x0F669D56E2998655ULL, 0xA054B1E9A021F61FULL, 0xF8EDA3216EF97101ULL, 
            0x63318CAEC188D112ULL, 0x2D518E5514AAD891ULL, 0xEE68F47DE7099496ULL, 0x89BE356552FA32F4ULL, 
            0x31FAFBC3F5E90E84ULL, 0x57CB855D005D6CAEULL, 0xC7725B1B1F889CE3ULL, 0x6C383B4EA736C2F9ULL, 
            0x183392769762F47CULL, 0xA9FD30869B6F0B82ULL, 0xB967C4A481E13DA3ULL, 0x8DAE4BD82C6235BEULL, 
            0x317FEBC0F5DA38DDULL, 0x64F5576FDACD3D2CULL, 0xD033CD3198F25EA4ULL, 0x54FB0954725B8C9AULL, 
            0xACEEF4767B1A14CAULL, 0xFE7E5C9C0F41D377ULL, 0x86B53B70F8E8B38AULL, 0x22622A231021C4D5ULL
        },
        {
            0x055361100E3E8C50ULL, 0x0D639118CC6D490DULL, 0x6B19C24FE3B264CAULL, 0xA6E42E900E4218D3ULL, 
            0x28EC7C9A40BA59FEULL, 0x9568DD93A4EC16ECULL, 0x1E520C12C2B05399ULL, 0x4D571BD739B793F9ULL, 
            0x61C33FC370D67984ULL, 0x90B5D5DB91B5132DULL, 0x43319341DB81BBABULL, 0xCD41EF27FD4D4A88ULL, 
            0x1ACB46392ADD0A27ULL, 0xD5F031850012D981ULL, 0x0A61FD3400F0F883ULL, 0xA7528557B854A8C0ULL, 
            0x57D56710A67C7B73ULL, 0x364AC07FFBB7DCAAULL, 0x71D7758E891C1343ULL, 0xAC1F1D8D1A74BB84ULL, 
            0x7994F692F6E392ACULL, 0x12DA0F83E1A56804ULL, 0x1D8B7D9CC27B30EFULL, 0x0B03EFAA9CC2BA4AULL, 
            0x100458CC06969F38ULL, 0xDC6304367C5B5E3DULL, 0x026EFC95DA85CF3EULL, 0x6DEEC8D07DE61876ULL, 
            0xDA3CC8297D9162CEULL, 0xF02DAB237AF19D77ULL, 0xF7C3D9B019351D33ULL, 0x646EC3124A93B045ULL
        },
        {
            0x55111D3CC358F333ULL, 0x69F561CF83CE16F4ULL, 0xF1A12073E878CA50ULL, 0xAC7892822C2EC631ULL, 
            0xF585949BDB522215ULL, 0x71A768A97E3D425CULL, 0x08CC6DC3D8165B73ULL, 0xD19142BDEE6F5CE9ULL, 
            0x375475BEAD6243BCULL, 0x79127D0874E4DA90ULL, 0x4845246E5E1F9A23ULL, 0x00F4423B640B4223ULL, 
            0x1EC77124C315F867ULL, 0x02F4D04B484A9001ULL, 0x0E594B0364AEC447ULL, 0x49E37074ED28FE17ULL, 
            0x56B67BE0B0EDAE6FULL, 0x405EC5EB64EEFCC0ULL, 0x9492ECBB57D84629ULL, 0x0795E72566957219ULL, 
            0xEBB143671F27D6D7ULL, 0x40836C23570F66F9ULL, 0x9EB473D847065B18ULL, 0xDDC55129E77BC52BULL, 
            0x8EA2C9C1E55F9EBDULL, 0x741D66D56105BA84ULL, 0xB28C09EF02FA1933ULL, 0xE62129047C57325EULL, 
            0x618876D93E46084CULL, 0x3238AB30DD31DD28ULL, 0xF14EF4807D9E6BACULL, 0x0F40832ADB975047ULL
        },
        {
            0xE432E52F89E39CC5ULL, 0xEFC080FB9923770EULL, 0x167A24B236136871ULL, 0x11D522BF160EEA9EULL, 
            0x7FAFDAFE61BA625AULL, 0x55D5CCB7A9586425ULL, 0x98703C59489DB618ULL, 0x45D5761029221CCAULL, 
            0xDB6CAA2030C81EE9ULL, 0xA0670464F3A5D4A9ULL, 0x9D1B49AF7FA40A10ULL, 0xD625550189E7D8BEULL, 
            0x883D12D5BC9C9BEAULL, 0x582491FF0A737093ULL, 0xD04F508B207B0B84ULL, 0xE8FA0949BF66E657ULL, 
            0xA150B0BCD5058E92ULL, 0x8AA804588C259331ULL, 0xA2A5DD350581B1B4ULL, 0xAB0F85764A7EDEE7ULL, 
            0xD84213C8C969F14FULL, 0x90C6399F2376738CULL, 0xE7C8197A042F79E2ULL, 0x7C9AF43E360B96C0ULL, 
            0x2F293B5FA6A06134ULL, 0x707C611D6D4B36E8ULL, 0xACF909B32B5EBB45ULL, 0xF879A89570D26496ULL, 
            0xE1D2C6B3547F5C98ULL, 0x9DD3E57D5373A551ULL, 0xE0930356420FC633ULL, 0xAD90034B64DACE8AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bellatrix::kKeyRotateAConstants = {
    0x0F4F50975943AE56ULL,
    0x0C08CD7B748FBFB5ULL,
    0x4BF6BED107DDB1E2ULL,
    0x0F4F50975943AE56ULL,
    0x0C08CD7B748FBFB5ULL,
    0x4BF6BED107DDB1E2ULL,
    0x305B6DB500EC07B2ULL,
    0xD62FC6B5094595A2ULL,
    0xB7,
    0x3C,
    0x84,
    0xF1,
    0x06,
    0x8B,
    0x1C,
    0xDA
};

const TwistDomainSaltSet TwistExpander_Bellatrix::kKeyRotateBSalts = {
    {
        {
            0xA61FB713F37DF3AFULL, 0xB45E5D189CCC5799ULL, 0xEB6B2B6347AA19C2ULL, 0x88B81377976C8502ULL, 
            0x18ABD9E25A728BC7ULL, 0x4A4130CE19D5C8D6ULL, 0x79FF9F5E2C72E894ULL, 0x1149D961CB179F54ULL, 
            0xA59624805BA9B0F5ULL, 0xC8433D09A2FE51E2ULL, 0x53C8A74887C53E9EULL, 0xE3A2E6635220E04AULL, 
            0xFF9E15470678BC44ULL, 0x2C9708FCA52ACF0BULL, 0x561FA3F097DDA31CULL, 0xC122B693FE609DABULL, 
            0xDE8E12FE7550A2D7ULL, 0x5F3460A0271232DFULL, 0x825ED07C646B8004ULL, 0x057CC0BB5D1BBA37ULL, 
            0xE019C9240ED8F199ULL, 0xCC0CA6DAE96688F7ULL, 0x96A78273C2DC2449ULL, 0x82B215F7ADD460D7ULL, 
            0xCD2C23BF7229036FULL, 0x4E26A9A5C825B8DAULL, 0xE6DD18F33A4FC618ULL, 0x286FAB7846374A07ULL, 
            0x210CD9B8C798280AULL, 0x0660AE1C387F5278ULL, 0x6010BAD6F6BF7A50ULL, 0xEB19FBFE41E2539FULL
        },
        {
            0xCFC06DE696C27D36ULL, 0xDF384E4772C67C35ULL, 0xF15A4544B26D87FCULL, 0x4182B97FAEDFD4D0ULL, 
            0x8845DFB4F79D30F6ULL, 0xA7925421190CBA05ULL, 0x55EBF18B5B924587ULL, 0xDA1EE034303419A6ULL, 
            0xA04BA86D398A8C3CULL, 0x428D8D6587F549A3ULL, 0xC7FD3D2E7E6C7772ULL, 0x1729E750F5874E60ULL, 
            0x6B4097FE8AF95B9FULL, 0x7898CFCF155DCD39ULL, 0x2BC79D5017906FD8ULL, 0xD401C99B18F6EE46ULL, 
            0x2C98A01CADCCCE0CULL, 0x8303D292BEA7640AULL, 0xFB6B72D9A6CCAE51ULL, 0x012926A99EDF86AEULL, 
            0x91A13460AD74A284ULL, 0x1143408A398A048CULL, 0xA424CD6A2973D92EULL, 0xD1181D0C50231ACAULL, 
            0x82826319D4F85590ULL, 0xCC242BD5768A5BD2ULL, 0x9DF4E64D9141CB66ULL, 0x727249D148F5DB8BULL, 
            0x6EEC72C5AFDE1FF9ULL, 0x17D29C1FDC1DD5F9ULL, 0xCC62DFABA4B75CFFULL, 0xC9EB44F1CAF3DC94ULL
        },
        {
            0xFFC323FE9FA73A30ULL, 0x10727B8C99558E28ULL, 0xF1AA62AE4DE77833ULL, 0xECAB8082F68A2ADAULL, 
            0x09E76044C091CE05ULL, 0x3E67F153A26943EFULL, 0xB0808301EF927AB4ULL, 0xA750E9A0DC13C06DULL, 
            0x11F0DFE22B8C1CA7ULL, 0xAFC77828CA9D9A65ULL, 0x1BAE9F665D65B0B5ULL, 0x9CF1A2F19A92AB1BULL, 
            0x434BD3E31C11FA6AULL, 0xA4D1CAC98F965A46ULL, 0xC2A967B3D270EA4AULL, 0x8BE0E141500E1F90ULL, 
            0xD5CF00BD471408A8ULL, 0x25B600C9CB512871ULL, 0x1CDC0E7A319A4CE3ULL, 0x48818046B0AA822CULL, 
            0xF1AF8FD80728675CULL, 0x3E3C98957CFE6816ULL, 0x0A158B1121877EFFULL, 0xF7B62FD02A4B482CULL, 
            0x5E7E0623A6DE5609ULL, 0x5FD3616946BC9F59ULL, 0xA937C8E48621CDEAULL, 0x93C57D14B90712C2ULL, 
            0xF6410C2BEDAB9B20ULL, 0x96FFE755C9111535ULL, 0x106E006114ECE7A5ULL, 0x677E9455331F23FBULL
        },
        {
            0x6AA6944454200DDBULL, 0xB2077B946D08B53FULL, 0x50788B6841FB1D05ULL, 0x043E5520CC1ED858ULL, 
            0x1AFDD81CD2AE6BB3ULL, 0x318B240D6B989083ULL, 0xB226E5F326CC5A95ULL, 0xB3383A154F751034ULL, 
            0xAD22F55EAC7D6860ULL, 0xB43F9C8CE74F1664ULL, 0x80632CD2107BE6CFULL, 0xE4EE60DBF67BE56AULL, 
            0x206A80711535DB36ULL, 0xB8B0484F17B3C2F4ULL, 0x51B2E6117AF1DCDEULL, 0x76C053540E6E3F63ULL, 
            0x9F2C9B84A6DCEB48ULL, 0x40B7C69346533A6DULL, 0xE4EB02AD22BB18B7ULL, 0x6753557B78C738D2ULL, 
            0x1D2B0A3CADB123ACULL, 0x82D95F3477BF59E7ULL, 0x6838BA96A6AC99C8ULL, 0x52ACE5C65F10E230ULL, 
            0x3632442273760064ULL, 0x2788FCC734E66497ULL, 0x1C67F0AE06682E28ULL, 0xE817D205248C317CULL, 
            0xA73904E5F65B2F05ULL, 0xEBA20B031B5707BDULL, 0x087152D1245670A1ULL, 0xE7E92A2EA8685824ULL
        },
        {
            0xEC7616E4E25F78FCULL, 0x5824576287195E13ULL, 0x51085C9F577B35E7ULL, 0xF9A2DE1962E50CE1ULL, 
            0xECD896CF50AD3AB4ULL, 0xAAFDEEBB97431309ULL, 0x33FF6D92AE05D4B1ULL, 0x3F046EF4EE6CB0A3ULL, 
            0xBECA1C3E327DFF56ULL, 0x90F301D94371CCF9ULL, 0x32CB41B110F41E54ULL, 0x326DD773C2961F30ULL, 
            0xF9CA08C072D5E600ULL, 0x3B5F845BAF20BDC9ULL, 0x0AD3ACC4E6121E10ULL, 0x7D8830B9150EBF2DULL, 
            0x0CD42623368AC2B7ULL, 0xB6A1389470EAFE37ULL, 0x226803587C880340ULL, 0xDDB3151CA6F5E4A7ULL, 
            0xC720DD1468045A48ULL, 0xC5F88BA673F3BC05ULL, 0x58ABD1B0B95AE19EULL, 0x92EFC55D51E21EDFULL, 
            0xBA8745CD9FC72C40ULL, 0xDBC9E72EC3EA84D8ULL, 0xAB401D5818F43B12ULL, 0x3ADECC4210CAE7B7ULL, 
            0xE605B972DEDD13F4ULL, 0x79CA4001D6E40133ULL, 0xC214C972030B3AE3ULL, 0x074CE95EBF4A94AFULL
        },
        {
            0xAA8F5F460409856BULL, 0xBBF7401117F26891ULL, 0xD09EF0CE26823420ULL, 0xE35E15D669262F2CULL, 
            0x095B94C82DB32F45ULL, 0xB411ECDA0A9D54DAULL, 0x888131401A182142ULL, 0x4DC27D6B112D4F47ULL, 
            0x133F1A966A5728DCULL, 0x87B24FDE8B2373EFULL, 0xB0F537CD38F6723AULL, 0x25D4E2324B08CA74ULL, 
            0x8BDF4ED4803EA383ULL, 0xB81F89F8BD9022FAULL, 0x583D16DFD383AEC4ULL, 0x1780474E11615CC3ULL, 
            0x78B69073A0E79F18ULL, 0x109C03B5B61C3D63ULL, 0xF914DB045988EDDCULL, 0x8BC71D187A2F54DCULL, 
            0x2D88F68814895DDCULL, 0xDEAA77A1F04827FCULL, 0x3E435B5588AF8151ULL, 0xE26EEFC6A7664A3AULL, 
            0xC7AAE2F320C24240ULL, 0x2708755AE4BCAB23ULL, 0xB80DC5D5C6E7DCF9ULL, 0x249CA6BF5A643845ULL, 
            0xAB4F9DD005FE9C27ULL, 0x4476C62C13374A27ULL, 0xF9C826E8A7531234ULL, 0x6BDFDDAB596FDBF6ULL
        }
    },
    {
        {
            0xFEE46FEAFA34C76EULL, 0xA26BD87070F13D1FULL, 0x396F64A40C1EB332ULL, 0x66D0EF25F912D42BULL, 
            0x37352C29F0C64396ULL, 0xF0ED577794CFDDF6ULL, 0xD74163F836443081ULL, 0x60271BFCFCCA6150ULL, 
            0xF8D107388A9E0193ULL, 0x34A1A4EDD04F24CEULL, 0xD338B569F5D556A9ULL, 0x9FF71CABBF4ED981ULL, 
            0x823A0CCE54C5AED5ULL, 0x4815A5B6240EC6E6ULL, 0x84F2F2002BF4B0E7ULL, 0xA330B6B61EBE00DAULL, 
            0xF342370EE22D509EULL, 0x12ACACF74727408FULL, 0x36E12786F7C32383ULL, 0xA3680F2A826BA26CULL, 
            0xCA6CF4D6ED1F866BULL, 0xF117D1FC5F86DF89ULL, 0x5DC2F9FBDD01F53CULL, 0xC787302817E0D278ULL, 
            0x091AE0C08E3D7C4BULL, 0x5E2733342758FC4EULL, 0x81E56D7FC80BB78EULL, 0x18DA4916471605DEULL, 
            0x00F4B6343C9102E8ULL, 0x0213FB3F88AFFD41ULL, 0xAC3A92DF37873211ULL, 0xF77704B0BBCD0089ULL
        },
        {
            0x8681BAE578FB959AULL, 0x9BFF39DDCCF779F2ULL, 0xA270952E0B062E86ULL, 0x21742C9F40086625ULL, 
            0x3B7FB3E435DC8377ULL, 0x96D296A265A85F19ULL, 0x09B96FB3A5F8916BULL, 0x6F70722DA8725D9EULL, 
            0x4CEEDC499FB7580DULL, 0xC148AD3B3FF36A2BULL, 0xD6738BCE1DE536F2ULL, 0x16BF54F2B51F5B9BULL, 
            0x297D18DE5C6A1F7FULL, 0xACF8FBD59588989DULL, 0x1BA6F574B7B50C8EULL, 0x741E9F6965897CCDULL, 
            0x382B38CB9CC31D42ULL, 0x51F7FFBBB6764E6EULL, 0x3567EF70BD412755ULL, 0x1AC92E5273EB6795ULL, 
            0x3EB4BDC150717A61ULL, 0x92BF54C37706D0DAULL, 0x33588D8390ADA662ULL, 0xEADB9087807DA4DCULL, 
            0x454113B9763AC1E0ULL, 0x569E3E88706A466AULL, 0xD7A0EA81A06733D6ULL, 0x50528D783E984748ULL, 
            0xDEDF4702230E2451ULL, 0x163E27717F89B324ULL, 0x6D43E7CA271D8C8FULL, 0x2F935F5E7DC47D7EULL
        },
        {
            0x752C20CBC6BD97B6ULL, 0x6EDDA31DB79BFBF3ULL, 0x05CB06BBE4B8C60AULL, 0xBCACF62871A897C1ULL, 
            0x874C14B467CEEB8FULL, 0x8E220F96EADDB821ULL, 0x07E22CF4B9880489ULL, 0x3B5FE4825AA96AC6ULL, 
            0xB80C2D66B53BBB95ULL, 0x9FAFF36FEBAA5D1AULL, 0xF6B48FCD1FF75E31ULL, 0xCA669AA131552765ULL, 
            0xC2AAFFCD49AB79B7ULL, 0x87E621C1E1C55929ULL, 0x296A12FA1DD23428ULL, 0xE2D16B822686463BULL, 
            0x939437CA0DCCDEEDULL, 0x91284B30207620CAULL, 0x0656E1DD93F2FEE2ULL, 0xD8699ED117D854B0ULL, 
            0x0C6A1A8E633EE9B2ULL, 0x6941A976F9153350ULL, 0xBBFC5F29DE8295C5ULL, 0x2A1A8F4EBFD6B41FULL, 
            0x50B18F8616557E90ULL, 0x919C51998E4968A4ULL, 0x4DEDA1AE8E2AC3A8ULL, 0xA7AAD7A4D2C12046ULL, 
            0x06D9197FEB77129FULL, 0x4E033F562900B012ULL, 0x154C08EB8BB9EB5BULL, 0xA5013CA565955AE3ULL
        },
        {
            0xCF7020B29F28F7B4ULL, 0x98F97914AA9A9050ULL, 0x3E78C9FFD1BB0850ULL, 0xED963871871D291AULL, 
            0xB15A69F1C1FA0385ULL, 0x2CBA106B4ADE0C33ULL, 0x89462331DFBBDFB8ULL, 0xD9931BB5CBD7F418ULL, 
            0xF60855A2B3F2E57BULL, 0x1F0343B852C78AFAULL, 0x0C237E498945F364ULL, 0x33D145D07B66B6DBULL, 
            0xEE8438F99EAE6AE6ULL, 0x8B2C13C4DAEEA4D8ULL, 0x0B13EC847FECB806ULL, 0x9C83732F68EC79B9ULL, 
            0x6D587D056F33FE88ULL, 0xCB9301375CBC4BF9ULL, 0xD16E16FCEE3B91B3ULL, 0x41202FA94E8FA72BULL, 
            0xAC96980C299B08B7ULL, 0xD77451D7CA8861B0ULL, 0x12FC5897571AC800ULL, 0x40C6D7D4AD6403C3ULL, 
            0x97053AB0282E5505ULL, 0x69FDDAEC967EA41FULL, 0xD830EA94725409EEULL, 0x110FF8095C099EA1ULL, 
            0x9200F62D5150FC8CULL, 0x4F9E1E64BBB14993ULL, 0xDD2295390E9FB5E4ULL, 0x210FA5AA8E5DCBECULL
        },
        {
            0xDBA8E59AC75800BFULL, 0xDB06B553A15B6385ULL, 0x90DAC0D441CB9479ULL, 0xFEF88B9DA2A1C2B6ULL, 
            0xF0F5EC5795F77AC4ULL, 0x968AA098FE88CD88ULL, 0xC491CE0E0B1511C0ULL, 0x067E93971C85B7F6ULL, 
            0x28800031C827F21BULL, 0x4C7926099526CDD3ULL, 0x358EA7F850F3DF7BULL, 0xC2169DEC55B81962ULL, 
            0x19BA24FD62C0158CULL, 0xA926293AB7A9BFC8ULL, 0x73B6CD8C29719AB9ULL, 0x1524029C0029AF7DULL, 
            0xB58DD254ACAFB32AULL, 0xF38F600A87F38BFFULL, 0x567E5BCAA95345DBULL, 0x94D8D707623B9C7CULL, 
            0xAC5ADA5155D45251ULL, 0x416914C5B5904479ULL, 0xA03D084855B6F7A9ULL, 0xA93FE535EB2A940AULL, 
            0xDDA934D6C503FE3FULL, 0x9575C62DA133B0DBULL, 0xA921B62FD5EC294BULL, 0x0FC8E80A3449DC08ULL, 
            0xF1F2DB2A20120FABULL, 0x1B4A233351C06741ULL, 0x0E4359EEB95A1615ULL, 0x1EDFA467C05833A9ULL
        },
        {
            0xFC9703531F306E7DULL, 0x5D5C4C0DD0D3EE05ULL, 0x731D2D423FA70A34ULL, 0x4164E5178B42B35AULL, 
            0xB8A79DEFC0F8B789ULL, 0xDF355B0E689A1B1CULL, 0x8C01210C72D3AF3FULL, 0x9C77AEF137E79659ULL, 
            0xDB3D023A94249365ULL, 0xD5612B6975A28DEDULL, 0xF6D6A89E0C9A0E45ULL, 0xCF441D5F37A9647FULL, 
            0x352D5157B16A3B86ULL, 0x6CAE957958778AFEULL, 0x062574C9FF0E557BULL, 0x04CFDD763D80DB58ULL, 
            0x1A21197E7C9E5D86ULL, 0x922B76F642411EA4ULL, 0x8601DAD5198557F2ULL, 0x8A70B6DE11DC1CF2ULL, 
            0x7748EEAF9FCE846CULL, 0x6E1A3B7311192E36ULL, 0x0256DFF9E603F6E1ULL, 0x6070AC6A20E648B9ULL, 
            0xA4E441278144D547ULL, 0xB37315403C4066D2ULL, 0x3FD5190BD0B70990ULL, 0x6D20548B02754E34ULL, 
            0x4C090CCFC7B2EDF8ULL, 0x74ADD674E1E53FA7ULL, 0x9761A2D6765C5F62ULL, 0x97F756F4009B1BA9ULL
        }
    },
    {
        {
            0x283D1664BEC56473ULL, 0x4B86A485A186C668ULL, 0x5EC134E7DA080008ULL, 0x4551019474770FF5ULL, 
            0x449DEF5BEC797F37ULL, 0xD7027D714D77B3ACULL, 0x87BA83A9780723C7ULL, 0xF1081E6E43FB325BULL, 
            0x5FA150C8470E601FULL, 0x6D4DDD7F115756CCULL, 0xF892C473A8C17C56ULL, 0xC032ABEA2E740473ULL, 
            0x9152B0FED2772F83ULL, 0x08B5B3720B668C04ULL, 0x3B840D752891F0D5ULL, 0xBB349AF4AF1F7AAFULL, 
            0x7AFC98DE026ED9C0ULL, 0x3834A5A6BDA0E8A8ULL, 0x3F81C57536E7D996ULL, 0xB3AF08F5091AD851ULL, 
            0x6F907CF0F5294533ULL, 0x3AD126524EC676EDULL, 0xA7764CDE4A863E75ULL, 0xA2F95B06C378AD49ULL, 
            0x2D3E0D5C82A007F6ULL, 0xD4B7417A03762985ULL, 0x5F6CDA8359A05CDEULL, 0xF861FD8BF5D466E6ULL, 
            0x0609E889CB0787D6ULL, 0xDD6134C50ED4D11FULL, 0x5E34B1E78165098DULL, 0xA7F1D5C11FCCDFB8ULL
        },
        {
            0x610005FD05BC3495ULL, 0x10CB384CFDBC9100ULL, 0xD78314D00EEBE705ULL, 0x6EE60F52709F3BADULL, 
            0x9FE9D4ABDB2F7E9AULL, 0xBA4F67DE81419461ULL, 0xD7589234B08EE2FEULL, 0x4333B25F7D021698ULL, 
            0x071EC9DEB22CA996ULL, 0xB694CD059F0BF6B2ULL, 0x6E6A4E181C09CB86ULL, 0x7A4B252DBFA1AD10ULL, 
            0xAF67640C67882D8AULL, 0x2CF22660B7E2A365ULL, 0x6E5FC5EC283AF2BEULL, 0xA2CC5CB28DAB6361ULL, 
            0xF188BEED87010CD3ULL, 0xE745EE22FFB43551ULL, 0x4BADEA262C5D4542ULL, 0xDBB27FC8951D2127ULL, 
            0xEB5B4CB458D4B893ULL, 0x70D2D87B09F57E6CULL, 0xEE9BDE0515A67E51ULL, 0xDB1897A6D2488661ULL, 
            0x2C1D99331BDEF6B9ULL, 0x1205C9D98B5F6A1AULL, 0x4B2862CFC431C152ULL, 0x74FCCF063E11C30EULL, 
            0xF24194C0275F1FECULL, 0x72C40E7EA2AE88E3ULL, 0x8F9AA6D4A31E95BFULL, 0xF6BEB291E656BB75ULL
        },
        {
            0x8E65F909B7A177A1ULL, 0x166792AE3D21D531ULL, 0x942EDB5D90AAB90AULL, 0xECFA2390D4EDF7E8ULL, 
            0x75C9B6389CAD80DAULL, 0xEA337F2C506E45F5ULL, 0xF0EE2095FB3B16F1ULL, 0x34A2753A6056E124ULL, 
            0x0122382346C36644ULL, 0x2EE69125B4277C55ULL, 0x2B65E3BE7010E76FULL, 0x6B7FA2319CE372E3ULL, 
            0x9F3A68BADEA08DC1ULL, 0x311E7E4FEC82FE00ULL, 0xA5BAE625F1DA2B3EULL, 0xAB8111A622AB1F76ULL, 
            0x72AD1A18A77E7523ULL, 0x8D9E9AC46C03CC8FULL, 0xBACB10F2A77AE49DULL, 0x4890626510FE6C45ULL, 
            0x9D5459B787534BC8ULL, 0x2C38F2A039623874ULL, 0xC96F92A8DD31DB6BULL, 0x7E830ADA52BBC59AULL, 
            0x6B2A0ABA8D767474ULL, 0x7F9856A604C8DCF9ULL, 0x0878F9BB06A753FBULL, 0x5D68449E5F14D70FULL, 
            0xC45A3622B6F72234ULL, 0x4F56D93A9C26A510ULL, 0x193C7A0CC958A818ULL, 0xC7903BB98543247CULL
        },
        {
            0xEE3351FD7192A1F3ULL, 0x4D76F3DD091BB1D7ULL, 0x9C59995DD47E6C2DULL, 0x241455F9AE775B59ULL, 
            0xE00426708EA9DD43ULL, 0xB8E137B45F807B49ULL, 0xAC9FF4F84FACECFCULL, 0x4D3F568EF6EBED7BULL, 
            0x3A91112320B076BDULL, 0xBDE507925022EA2AULL, 0x304A5464D86A8CEDULL, 0xFEE96770BA42A2A2ULL, 
            0x049DDA135D4C3191ULL, 0xFAFF1F6C2183FB07ULL, 0x3A7214AF3EB38A2EULL, 0x4C6A19185FE6375FULL, 
            0x65CAE4BA46C965FAULL, 0xF792197375183E80ULL, 0xDF3D94C77BB0A967ULL, 0xFB776E403807F33DULL, 
            0x56D79A60DF6E8A9FULL, 0xE0B2FB93675305A3ULL, 0x0D47D9C8B0B54A7BULL, 0xC3B3084304F4EE37ULL, 
            0xBBEB741D8C5B09CEULL, 0x03F3CBAC65F2822AULL, 0x14B362BE3D1F4497ULL, 0x54670D4C6AC0ECEDULL, 
            0x8DA7AE7FAED0553AULL, 0xC53CA9DAECD68AC7ULL, 0x8A5857CD626F6822ULL, 0xB079DE8D4326EC2BULL
        },
        {
            0xBC3D87FDED345B97ULL, 0xF9C5F8BCA4546A8EULL, 0x53A8904C399402CEULL, 0x74526330DD499CCAULL, 
            0x16E2F3D7E305C9FDULL, 0x0DEE14E670B9D76DULL, 0x4BD73BEEF87EAD12ULL, 0xA1A16751CA286183ULL, 
            0x5A560DB97889926FULL, 0x6CD1EDCD9441043CULL, 0x2FB5401A6DFF2F2EULL, 0x5BB7DA78C1E54A33ULL, 
            0x3C70DD7A4863DB65ULL, 0xA5416A94D023382FULL, 0x05DE3CEDE19A4BAEULL, 0x157B35BF75F0C60EULL, 
            0x3FDD08423CB2C3A8ULL, 0x7301C5A630D5382FULL, 0xB0F772F3DD8B9FFBULL, 0xB4A597CB472E7EDBULL, 
            0x27C0AE532017CFE7ULL, 0x7C68ABA4EA510FD3ULL, 0xFC7677AE0FE564B4ULL, 0x16B64822AD7BC565ULL, 
            0x55A08354F93B0776ULL, 0x9C817970D3BC3F30ULL, 0x0F048E3D37807469ULL, 0xC53575B204EE92FFULL, 
            0x425153880A77FD5DULL, 0x7473D11E95100DB3ULL, 0xF1148E917C825152ULL, 0xF949A14589EA13F6ULL
        },
        {
            0x876F75A84883A8C7ULL, 0xA3EF1E63A7F2A982ULL, 0x17A9DEB89F2E003BULL, 0x2F76F5827538D1F9ULL, 
            0xDF2B987778026909ULL, 0x8FC15E9B6EE634B3ULL, 0x4C07E00FB7A87376ULL, 0xF9B00C37C305DBF5ULL, 
            0xD1EEA83678AE92E3ULL, 0x95900B1D0EC523C6ULL, 0x327B9AF92319F4F3ULL, 0xC8ECBD66AEA8743AULL, 
            0xB51CC3ED045436C1ULL, 0x8B4FE84A29E19031ULL, 0x1C1DF1D33B899771ULL, 0x3C8F4FAEAB153F74ULL, 
            0x4FE9A20ED5E72A9BULL, 0xB412064684D59E55ULL, 0x8E5E7DE46177CE0FULL, 0xF52FFCB495BAE048ULL, 
            0xC50420722CABC31AULL, 0x8E8863EEE391E57FULL, 0xA821F9B3AF9137D5ULL, 0xA5D689932D412187ULL, 
            0xDD97946933BFAFC3ULL, 0xA465C6B6E94DF57EULL, 0xCC1E4DCCB36D6A64ULL, 0xD359FC9D543B32EAULL, 
            0xB51A79453D54C15BULL, 0x66057009AFCAD135ULL, 0x6B78E3D3780827DBULL, 0x91A2AC8CBB961F9FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bellatrix::kKeyRotateBConstants = {
    0x1AC0796E8B35A5DEULL,
    0x7BF6C05EC72E0A2CULL,
    0x32F8A3E1D07C19E9ULL,
    0x1AC0796E8B35A5DEULL,
    0x7BF6C05EC72E0A2CULL,
    0x32F8A3E1D07C19E9ULL,
    0x3A8E798BFC311ABDULL,
    0xA2FEE703CDBBD682ULL,
    0x7C,
    0xF1,
    0x10,
    0x11,
    0xDB,
    0x6E,
    0x70,
    0xFD
};

const TwistDomainSaltSet TwistExpander_Bellatrix::kKeySpawnASalts = {
    {
        {
            0x10540504D2543C6DULL, 0x99CB62C879662867ULL, 0x9A59657BE749E0AAULL, 0x86CF2CAA023F1E0FULL, 
            0xBB56CF2DFA62574DULL, 0x3611CAF2B96A5502ULL, 0xE6E44EF1FCD30FF2ULL, 0x990CDD5B0E6E232FULL, 
            0x55FE66D9F44BD4A5ULL, 0x685F580D78F44C2DULL, 0x32C9F553131EC3B4ULL, 0xD9E797E27F19FD91ULL, 
            0x09CB2FAEE7D6CBA3ULL, 0xE6566CA661BAC276ULL, 0x83578ABEE29E1611ULL, 0xE60DA8A883C4659AULL, 
            0x6F66958481EF8C92ULL, 0xD2194388654D835BULL, 0x99ACFBF6E8E809B1ULL, 0xF1EBC7A57F4E1729ULL, 
            0xF9E0F6B96DF85901ULL, 0xD72E0B01B001A6E1ULL, 0x74613FE6B2857D06ULL, 0x07866480C5E3597EULL, 
            0x676C3F822F4C1AE1ULL, 0xECECBD7ACBAE9D51ULL, 0x51E6FD01BAEE1723ULL, 0x94351077A94DBD88ULL, 
            0xD701D3BEFD44075CULL, 0x1F425E68DE69B9E0ULL, 0x8DAA64FF6216280CULL, 0xB924A70CF8DC7BBAULL
        },
        {
            0xF476FD5BE97FE622ULL, 0xBAAF1F88EFDD9858ULL, 0x93C922ED61065E63ULL, 0xC1AB66F0388DC6B5ULL, 
            0xC5E19EB194930497ULL, 0xDE3699EA141AEF93ULL, 0xD5225723FF74BF8AULL, 0x8708AF056C5187F3ULL, 
            0xE592A52FE5254EE9ULL, 0xC2F856074670A266ULL, 0xCD256A110F6ED57EULL, 0xFC648CA29AFD9D3CULL, 
            0x55CD0669019C6821ULL, 0x7127161436A338B2ULL, 0x33A858CE6E5D853BULL, 0x9E04A7A17FBAF089ULL, 
            0xEE34DCF0974805BFULL, 0x4FDAB2FA0445E3ACULL, 0x3995CCAF7F433103ULL, 0x9706C623E2F20E4CULL, 
            0x22EBA2DBD5D83E90ULL, 0x54C828808BEC9712ULL, 0x0A4AB3848DDAC0F4ULL, 0xD5324EEBE73209A4ULL, 
            0x04D126D29A695F6BULL, 0x8F79C37071D3CAF8ULL, 0x2D4FA7CFC498AE66ULL, 0x35FA2DF718BBE6E5ULL, 
            0xCB2316FE25D79684ULL, 0x8C125102F78DE3CDULL, 0xA6D9D528050399CEULL, 0x3F276A63D5EE4A6EULL
        },
        {
            0x8145854DB4D66E30ULL, 0x82A207B80E1E219DULL, 0xF240BAE7087102CDULL, 0x9CFCCD5DCC80CDA2ULL, 
            0xFB75F59691471BC4ULL, 0xC1118DE6EEDC6228ULL, 0x56FB92D5E2A92F90ULL, 0x1C5945C293B553BEULL, 
            0xC6C31C322254D0C2ULL, 0x486ACA30E9E136BAULL, 0x304D0EF8257ACF86ULL, 0xC6E52A7EB349CCAEULL, 
            0xB40014DFAD3A1F34ULL, 0xDFAE9C97C956524FULL, 0x860C277A523B1A3DULL, 0x4D54115D7CE20D56ULL, 
            0x32E530EFAD94D677ULL, 0x84D2688E16473EE6ULL, 0xB2BF8DE5472A2894ULL, 0xECD785349887AC7DULL, 
            0xD280322C21C16CAEULL, 0xEB8525E3217A0DF9ULL, 0x5A309EB9E52A0535ULL, 0xEA7A12AC5735D44FULL, 
            0x125B87E4BCF481D4ULL, 0xBC727AEFDEC759FFULL, 0xB2D4A39E1070BAB8ULL, 0x0EAAE29ED2EB8EF3ULL, 
            0x2FD197BF0AB907DEULL, 0x21EA637F4BF4A4D7ULL, 0xBD984DE503186497ULL, 0x66648821E44D050BULL
        },
        {
            0xA834D43A06941B40ULL, 0x25FE8FBB6EA8B85AULL, 0x5DF770E1248C512BULL, 0x4A2495F2E45596CDULL, 
            0x92C673568C78AF5DULL, 0x89EC86F5A7F921A5ULL, 0x3576393F55CEE70BULL, 0xFC461EB72E8FC777ULL, 
            0xA13F79542F4B7159ULL, 0xC7FF528680642577ULL, 0xEAC1F16E1E1C7346ULL, 0x6DBD60D86FE63DA7ULL, 
            0xAE7CE892AECFEB03ULL, 0xE386CE815F087993ULL, 0xE43B34C2290C0168ULL, 0x49784D6AE2DA5A34ULL, 
            0xF871A6E85C3D639FULL, 0x613D1492F380D8B7ULL, 0x77D0CA2CEC2C8426ULL, 0x81401DD57F91FC09ULL, 
            0x29294BF92267AD37ULL, 0x0E09AC8C0CE47BACULL, 0xD4EB50386E17BD11ULL, 0x94695A9659B8657EULL, 
            0x2F2472D5EF671F84ULL, 0xE0CDE753390C828BULL, 0xBC5295823D446C8BULL, 0xBDE14E13E1829847ULL, 
            0xF5E1E2B15B77A95CULL, 0x1EEF26A5E1DB8858ULL, 0x557803B8B04CCC50ULL, 0xA8902B344D4D0E28ULL
        },
        {
            0x5380CDDE5DE2F4FCULL, 0x15960099CE9C72ACULL, 0x34756987D2327C4EULL, 0xFDAE189A5A74539BULL, 
            0xA96BFC3772F9B8A2ULL, 0xFE292731B810D1A8ULL, 0x793D8C20062A0428ULL, 0x495860F4DB3E4CEBULL, 
            0x737C7F0B7D064292ULL, 0xE9905576B8EAC170ULL, 0x32D02828800A296BULL, 0x5D31F14732739178ULL, 
            0xC3DD6C634C7D6928ULL, 0x713830CD11606A92ULL, 0x2EEF85AF365E5B73ULL, 0x67A3570BB08F624BULL, 
            0x5433ED36172B8144ULL, 0x3113D4E9E1508277ULL, 0x704EE2FC11CC9145ULL, 0xD00983A12ACD0DCFULL, 
            0x470C090FAF0D1E27ULL, 0x12201B81FDA26992ULL, 0x2D001560BAC9B241ULL, 0x70689B78EF6D420BULL, 
            0x11CF9ED63559D6C1ULL, 0xDD0DCB786D57CFFFULL, 0x44CF46A8CCEEE1D6ULL, 0x084B0ACEEA650965ULL, 
            0x6AE037597AF16F9AULL, 0x3B504D273DDD930CULL, 0x422035C6B66D0695ULL, 0x5CAAD780C7DC90E2ULL
        },
        {
            0x98C451C909B54F7DULL, 0x52AC7BE53C6AA59CULL, 0xDAD03CD4BDBA343FULL, 0x5EA0EFCDD8025CF6ULL, 
            0x2172FB697C300A82ULL, 0x8BA7A44A43549E64ULL, 0xFE9C6334C39740DFULL, 0x391B7C21C01C972FULL, 
            0x698A183DA22EAEEDULL, 0x06F8A983A29F310AULL, 0x5B5EF2FAD8A81943ULL, 0x974524E92634AEA3ULL, 
            0x37272637F47482C2ULL, 0xF1CB25E97ED0F9BAULL, 0x46C5CC9A3CB7FEB9ULL, 0x5F36EEEE48CBBC7DULL, 
            0xF17ED9EF8B3C6467ULL, 0xB2820BB0E0655001ULL, 0xA5466F6BD45883D8ULL, 0xC52C574E4D5E1EF2ULL, 
            0x1A5D1A2337756881ULL, 0x1510016473AC7E80ULL, 0xFC6F3A241C5AB256ULL, 0xD251FFDE6F8E2D96ULL, 
            0x1EB5EBB06C55B91BULL, 0x6D318CCCB09C0F8EULL, 0x0E0B92F094ECB5D2ULL, 0xE71F2B1AFFE4C331ULL, 
            0xC7E2E838DE7D1E6DULL, 0x2BFDD3A5F308DE7FULL, 0xB605A4D6EC1D5FE3ULL, 0x4298B6BE37773708ULL
        }
    },
    {
        {
            0x732D20EBBFAE2AEDULL, 0x2DC704269DB43BE5ULL, 0x43D76724863D4C5BULL, 0xCBFF9AFC97AE979FULL, 
            0x5B192DBCDEC7C8D2ULL, 0x122CFDBB4421EB80ULL, 0x5B726B3233A0F89EULL, 0x7815F31EEF427E70ULL, 
            0x924FA6B64458575BULL, 0xD05600FCF450833AULL, 0xE69BA9249BAA2B14ULL, 0x9A70F3F676819763ULL, 
            0x4E10683307B5886CULL, 0x467BA778648370B0ULL, 0xD283E9954A8D378DULL, 0x64E316107B06B510ULL, 
            0xF1027FFD0B7530E1ULL, 0xFA1E3A9D79E1F459ULL, 0x8C86D6033DB55B08ULL, 0xB66952BE8F52D495ULL, 
            0xCAE8D266D8B9B734ULL, 0x617E58B98B908028ULL, 0x6C4D90B8E7006F7FULL, 0xC2103463CA86E264ULL, 
            0xEADB249B1C05F804ULL, 0x8CCC6B67BED3445EULL, 0xF8D8A5630A11D6BFULL, 0x754567223B4DAC26ULL, 
            0x518B29A73235B968ULL, 0x002292A3D8D24DE7ULL, 0xC46D4C7B9522FB2EULL, 0x8ABB916A6693DA19ULL
        },
        {
            0xECAC4D35BF0B0BDBULL, 0x31CF2883C40702E8ULL, 0xCF19D9587BCA182DULL, 0xA7F5AF587E501FEDULL, 
            0x37C536E0C06E962DULL, 0x2BC1C8847CDF4CD1ULL, 0xBF75907D910D05D5ULL, 0x33826A0691F57FD3ULL, 
            0x4085EA54BDF8BDE6ULL, 0x095726E112C5F759ULL, 0x98B9FD2B0E3664A5ULL, 0x5A969FD66BDE63A0ULL, 
            0xEAD07938CA0414A6ULL, 0xE99C649FE4E62063ULL, 0xF607A5379DC5589AULL, 0x57C863E520E1C960ULL, 
            0x24906E701C9376AAULL, 0x5A84D098E4205B97ULL, 0xCD08DF3BBEFC59B9ULL, 0x1AED6CF9EBB51823ULL, 
            0x7ACD9BD53472A3C1ULL, 0xBDBAAE30DAAE2452ULL, 0x93D4FC872E4EB913ULL, 0x46F2ACBEEE4BF58BULL, 
            0x608319277003ABC9ULL, 0x2C6FD92AE8AABA29ULL, 0x81DF5E8E8371D545ULL, 0xD75984EA285DEB15ULL, 
            0xE3AF43EE86543731ULL, 0x262D2BA68A733B73ULL, 0x0238D89A1BEA73D8ULL, 0x6FBC63B3DC7A38F8ULL
        },
        {
            0xCAAE32D1B96DEB63ULL, 0x0480AB9B66EFEB05ULL, 0xA43C68C4E41C6399ULL, 0xF345551FD7A760B4ULL, 
            0x7AECE6C07CD66002ULL, 0x567A5EFC6B98A58FULL, 0xBC5C5E52D984DC35ULL, 0xFA0222807D7BCEA6ULL, 
            0xAF2DDBC3E87404CFULL, 0x1BDA7616702078D8ULL, 0x0E60F34A742FCBF2ULL, 0x6F226430D8E03E5CULL, 
            0x799C45363EA78B27ULL, 0xCB6C939414E2CDB4ULL, 0xDE7E5AF7F5573A18ULL, 0xBECA580917F39F6CULL, 
            0x97CB202924CC83E5ULL, 0xCC518043FACD1D19ULL, 0xF13FE4FC4BE2F9DBULL, 0x03F985A606242706ULL, 
            0x8D792593488A3EFCULL, 0xB36255BD2983A742ULL, 0x17FD44E18A54F073ULL, 0xB4875947E0F357BAULL, 
            0x3C172D89B130CE16ULL, 0x24BDA249CD89CB2FULL, 0x5CF966632F542A1FULL, 0x0874580CCA7A9668ULL, 
            0xDCDCBF1B19A010E9ULL, 0xC6D86833121CB3C4ULL, 0x57BC167B38CECACFULL, 0x305E0A7C0BB0BE89ULL
        },
        {
            0xD068C109B702B703ULL, 0x8883BD54C078FF68ULL, 0x0F65AFB316D14017ULL, 0x6430051AAFD9D7CCULL, 
            0x99D5EF27DEF8497BULL, 0xD19315AA3B91ED2DULL, 0x636E2B81BC562F7DULL, 0x4B80131E3D13A336ULL, 
            0xCC568DAF124DB161ULL, 0x00F1AE2730F78D89ULL, 0xC2279650E8A2A08CULL, 0x05DD734E3E938062ULL, 
            0x98BE9F6DD3CC0F8CULL, 0xFD0FD1F98AB3CBB6ULL, 0xF3EC4E2A6A3FF641ULL, 0x25CA4F0973783D1AULL, 
            0x248D17C98795C376ULL, 0xE3E1249CE182FBBBULL, 0x67E21B55AFDC8962ULL, 0x4E4168C28AF8BCAFULL, 
            0xB58E062CD37453CDULL, 0x285D715320D35787ULL, 0xBFBB4150560C94FAULL, 0x3ED36176937D6F57ULL, 
            0xF9952E95CC38963FULL, 0x4C66B2639C8C930BULL, 0x77648DD4CA8418E0ULL, 0x3791D7C049C86150ULL, 
            0xC3BE0DD387FA1311ULL, 0xF3A81A24AC578FA3ULL, 0xF0997C35082D6894ULL, 0xB31378F7056D6A2BULL
        },
        {
            0x4E6E145A77D1A74CULL, 0x0EA345F4C0A4AF60ULL, 0x31044D0B19E5214AULL, 0x6F18AE09BF55D0B0ULL, 
            0x3DB698FD5E9BF655ULL, 0xA6E29973137F9939ULL, 0x60477506497A183FULL, 0x4F91DEE24F370307ULL, 
            0xC219BC878925DD8AULL, 0x73FC6C49D73AD3C0ULL, 0xEA066CAA043FD26CULL, 0xE003EECE7DB6D2AFULL, 
            0x5CA892AB690C2F3DULL, 0x020C2E5AB95F3262ULL, 0x796E2AD54E2CE6BBULL, 0x0CD2DFA0D9F543ACULL, 
            0xB8C1E272A1B22314ULL, 0x35A8C9CE2855B889ULL, 0x9AF0F2CD23FF4431ULL, 0x159FA5C722C8A16EULL, 
            0xFE0C90347FBF0427ULL, 0x25593E56DA28564EULL, 0x975D9978CBCC277AULL, 0x4A2474D75589B1E1ULL, 
            0x67E180CC0DF8B006ULL, 0xABFB69B02040D7F2ULL, 0x420C7251FB2BC203ULL, 0xE13850EEBD6C9E2BULL, 
            0x5FD9C10A36759B17ULL, 0xB00A61DCF27A24D2ULL, 0xD115478ACAFF9DCCULL, 0x0C54137D71F47E10ULL
        },
        {
            0xA413AFA046A8B832ULL, 0xB740DA295E118792ULL, 0xC3B26497C70E18F5ULL, 0xA58A078575319F69ULL, 
            0x7C6CC9D96475B267ULL, 0xE0298FD2A81B4A84ULL, 0x4EA89879F73C9975ULL, 0x40388A527764BA59ULL, 
            0xB855F2968F9CE97EULL, 0x444CAF953EE83422ULL, 0xE8CAF8A74EE90EE3ULL, 0x3E429FAC7B93CF99ULL, 
            0xFF2E1B723BE30C47ULL, 0x7B5092A76514F94CULL, 0x20DF3ADDB778115CULL, 0xA9465CB6F94086BBULL, 
            0x15C52CC49B2A3131ULL, 0x1A7FE407EDA7800BULL, 0x862F25FF6B06ED74ULL, 0xEE583C6DA3110277ULL, 
            0xE61719023E704FC4ULL, 0xD1CF3E1B9B8CD84EULL, 0x1C87132EC46D635EULL, 0x4120581ECDE2DDAAULL, 
            0x57C8FA25761E8249ULL, 0x82A061408294FDA0ULL, 0x9A272F0BF76D8F21ULL, 0x1F0D7477BFFDD82BULL, 
            0x236A3342B3C9592DULL, 0x93D9D630BEAEDF28ULL, 0x9C1CD55896044608ULL, 0xF244516E6883F759ULL
        }
    },
    {
        {
            0xDBA34B7744AE1C52ULL, 0x51E9B277A903EEC4ULL, 0xDDBAD5FDBE8C8C0EULL, 0x3A8283DEF236A90FULL, 
            0xE8A36D4B5F9DCB75ULL, 0x0D8B83F08D9D5C23ULL, 0xA3515FEA5A0BA635ULL, 0x80D0285684E8A5F4ULL, 
            0x71C4D4C6563F4F86ULL, 0x424428FE9DF8F48EULL, 0x732228F570664F79ULL, 0xD7ED7B7304FAA044ULL, 
            0x6F3D3F6391F3BA1AULL, 0x919AE323D1CC104DULL, 0x635E6B35F41C8C58ULL, 0x56E494C6993C08B4ULL, 
            0x48605AF9A5A9A542ULL, 0x84403E21B8C33009ULL, 0xC090EEF3595A395EULL, 0xF666836F80E27736ULL, 
            0x43FF32907EC50244ULL, 0x2CBEB4E31E77C590ULL, 0x2940D9B1264459F5ULL, 0x83DFED2D52169E8FULL, 
            0x0881249E895AF3D6ULL, 0xAF3EA393FC824719ULL, 0x060F0EE00DDAAEC8ULL, 0x32EACC1726D45E48ULL, 
            0x42E87E8FC19D2CA4ULL, 0x4A3F34BF79B685E4ULL, 0xD7150704B655BAF2ULL, 0x99D560EB7D9FFDB1ULL
        },
        {
            0x5EB5A0C073D43D94ULL, 0x9255E934F5DF7C29ULL, 0xAEF87F3504F21BAFULL, 0x4C77215FA039A63EULL, 
            0xFC268E82F9EF65D4ULL, 0xE7DD3B070BBE005BULL, 0xB62ACF07E4A61195ULL, 0xF8ED0C834ED0D78DULL, 
            0x846483B843292340ULL, 0x0D639516F857D499ULL, 0xE84D1037924489ADULL, 0x5FE37CC7F728637EULL, 
            0x9E5F6E393CB89249ULL, 0x285952E70CD566D1ULL, 0xB1B98BC9EE082B4AULL, 0xF8325E90B95AE3FCULL, 
            0x3356A89146D6A987ULL, 0xE02A453E7B33CFCBULL, 0xD8030E0A4A26DF3AULL, 0x0163417CDA5830DCULL, 
            0x450ECDE5230F317DULL, 0x30F5EC7FC0373F66ULL, 0x5E1360E8821F01DEULL, 0x1D136E9D0E4172A4ULL, 
            0x6A7FA473CCAF279FULL, 0x85F185C5278F0A96ULL, 0xCA1D24241408F0B9ULL, 0x2977BF8D6F884572ULL, 
            0x5DF1BA1EA6FA3E2AULL, 0xDB65153A4DB63AB2ULL, 0xB0538017545A4860ULL, 0xC4D0FF01AAE130A0ULL
        },
        {
            0x52730F0B708003F2ULL, 0x5A02F7701438A1A5ULL, 0x970FB3657E9D47ACULL, 0x0C88185DE4AEED22ULL, 
            0x4274A595D0FD00A7ULL, 0xE923FF65BE2CA6F6ULL, 0x5B6DCFF5534DC2F6ULL, 0xF5F9DEA9AC5CB603ULL, 
            0x09EF9758F5C5CD0EULL, 0x8CD9288EFCFC6C7CULL, 0xA826C2CC0EBC79B1ULL, 0xC980E3EBEA817775ULL, 
            0xBADAA96E782E0499ULL, 0x89469557AA8C265CULL, 0x3FDE06AFCDCFBA80ULL, 0x1B0D84040ACB9864ULL, 
            0x3C1CAE8F678402B1ULL, 0xC6011A07E69FB548ULL, 0x5D35A9E061E209EEULL, 0x7E8A26BD935F0A0DULL, 
            0x603FC8E28DF09F07ULL, 0xBBB52CB86EE0DD27ULL, 0x20B0E04F87D80534ULL, 0x6750944DA92278EFULL, 
            0x76884ECEACDA791BULL, 0xD11D97DBA1FD8124ULL, 0xB527F0B3752250F9ULL, 0x09C7699E3D53AB44ULL, 
            0x347F991CC70B086DULL, 0xD1CC9786035698D9ULL, 0x15F1DA336292348EULL, 0x0FB6A103A36334BEULL
        },
        {
            0xA3978687880636E0ULL, 0x91C08328240ADC52ULL, 0x6BDE0905C3722FF7ULL, 0x82EE26C24E14D95CULL, 
            0x13894D0B91CDC99FULL, 0x656DC63A403BC1ECULL, 0x0340E8137CC4F9A3ULL, 0xF27CDEBF04AA943FULL, 
            0x9A5B430946A96DFAULL, 0x27DC7E8BADD6712BULL, 0x70CEF7E645DDD52BULL, 0x62AE86B2E2CF5226ULL, 
            0x3264C61DC5B4DF96ULL, 0x3409D1002A1E272CULL, 0x4961C931881BCE8DULL, 0x3ECAF40270C6F28CULL, 
            0x511D2501A5A3D9F5ULL, 0x2F8F346880F69FEDULL, 0x423B176F0B99A048ULL, 0x179BA3440F91AAE9ULL, 
            0x5ED07299B46D71D8ULL, 0xDEF975D14CEEB22AULL, 0x4FC816D64DE78334ULL, 0x17FCC079EC9C1A14ULL, 
            0x57F5070CBF0BB86DULL, 0xAEE8FBE0E9779F72ULL, 0x85A584CA24529524ULL, 0x1A7E3D59FB2BD0EEULL, 
            0x26958261A1E9E0CCULL, 0x1AE46AFCFB215055ULL, 0x2A2736BCD2E64DE7ULL, 0xAF6C89732241B924ULL
        },
        {
            0xC86D8A320EF87554ULL, 0xF629E6D9AE8D0009ULL, 0x7F796365B5DCFB61ULL, 0xD67E3D2899272611ULL, 
            0x7DFCCAACC5ADE184ULL, 0xB77595FD87D86C46ULL, 0xD30CC2E855AA8CC8ULL, 0x7B2F87080FE50E5BULL, 
            0x40BADC1E515ECCE2ULL, 0x2D190321330018F7ULL, 0x507D9F81967D9641ULL, 0xD3E7FFD6068A6E73ULL, 
            0x79C82DCDA12B4964ULL, 0x2175DAEBC474275BULL, 0x258530303C830E06ULL, 0x37C0BB3CF2C5D977ULL, 
            0x84C21AEC31B4A556ULL, 0xC75463229E462D15ULL, 0x5B959E4BC050D318ULL, 0x471D2CA9305FA546ULL, 
            0x300B815D469D3687ULL, 0x98EE1A51F50A4DF9ULL, 0x59808DFDDFA66D7EULL, 0x93F261DB1A583D60ULL, 
            0xA404D357045FF489ULL, 0x06C9856161F36EBBULL, 0x8F76386BB9DAC6E0ULL, 0x277AB87CA9AEDCAAULL, 
            0x4EEAB28CF18A70E1ULL, 0xBA59E22C4F6B6F51ULL, 0x3D5F6783E5503B88ULL, 0x6AA804B33028F1EDULL
        },
        {
            0xA4563B1FE069C576ULL, 0xCED426CD0396BA82ULL, 0x2FC40D2068362B48ULL, 0xE5022C67C7A714B7ULL, 
            0x1607FC125485382EULL, 0xE2C8F48AC028C35AULL, 0x32B2C2F50831F18DULL, 0xC7D6065A7D5F60ECULL, 
            0x14C0DEDD723ED6CCULL, 0x47C7DD2584C37DFCULL, 0x1C4BE58A3B79F0EFULL, 0x2F6F47018FFF95F9ULL, 
            0x2218260E897CE9E8ULL, 0xBFE82F0916D3BC9AULL, 0xD1A090157364527CULL, 0x86FD261A21A523C8ULL, 
            0x488249D9017778ADULL, 0xD8F1C69DD7B7FF0FULL, 0xD5055B541910CE09ULL, 0xE601A77AA3584316ULL, 
            0xC250A0B65C5597A6ULL, 0xCD14045317AAA12BULL, 0x006C2DAE9A7B2ED8ULL, 0xE2D62C77FC8F75D6ULL, 
            0xD41221E9083BDFEEULL, 0x635BC4386A2E9E2FULL, 0x276A2DB38A2688F9ULL, 0x98046975B20AA178ULL, 
            0x95AA51FA89055FA6ULL, 0x81460EE5834BC9F2ULL, 0x13A816FC2DD6BEC1ULL, 0x5D5E078D1F3170B2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bellatrix::kKeySpawnAConstants = {
    0x1699FF996C706995ULL,
    0x7B915AA1CC3373A9ULL,
    0x59F37F0A16EC3DEDULL,
    0x1699FF996C706995ULL,
    0x7B915AA1CC3373A9ULL,
    0x59F37F0A16EC3DEDULL,
    0x2C983BB5D6E6163CULL,
    0x9A4442E26435626CULL,
    0x30,
    0x0A,
    0x1F,
    0x88,
    0x5E,
    0x24,
    0x4E,
    0xAB
};

const TwistDomainSaltSet TwistExpander_Bellatrix::kKeySpawnBSalts = {
    {
        {
            0x1F6A2F8EBEA2FB43ULL, 0x936A68CCC56DFD7EULL, 0xE1CA676BC619FB35ULL, 0x3D6625FC4A4DCB28ULL, 
            0x70FD524C7F0BC4FCULL, 0x4F0006286DA5895AULL, 0x430E98EBC6C80BB4ULL, 0xA00091C220DB7385ULL, 
            0xB8F77305AAFC22BEULL, 0x7AF997124C0A3C13ULL, 0xCCFCB78755E1AC99ULL, 0x57A7F925B305068CULL, 
            0x136B4D5734016D8DULL, 0xA2B4F18E76DF1ABFULL, 0x71B11F7C6411363FULL, 0x5B3E21D1DA190D8FULL, 
            0x84B51EF2BC79D4B9ULL, 0x1EFB99B9A64E4017ULL, 0xE2008468C8D19F54ULL, 0x5840F5D808C6F063ULL, 
            0xEBC68C38640C44B0ULL, 0xFBE636EEA755AA62ULL, 0xC993B3E8D5CD4A95ULL, 0x67813820F047EF95ULL, 
            0x9E2B851F948D79CBULL, 0x72A5F6F63950C7FAULL, 0x316C28AA2740C1EDULL, 0x7FF8CD9D38AEBCB1ULL, 
            0xD40DEA1E7CA5E696ULL, 0x1ED8350C8ABFBC09ULL, 0x1E08AF52C337726BULL, 0x1CBB00973F2B3BCAULL
        },
        {
            0x9946085A79F3ABE8ULL, 0x9E9225BC644AB2C0ULL, 0x4BCE5007FCFADC71ULL, 0xF01202130C64EEC5ULL, 
            0xDED45837AE3BD320ULL, 0x2D8D3E1A58F81077ULL, 0xC1222294D5E88534ULL, 0x9A63878B78E12B7BULL, 
            0xEEA624C842338C5FULL, 0x68F6D978E9ABFF6DULL, 0xC48F22E162151350ULL, 0xEF8A88FCAFEC16D2ULL, 
            0x8DB234A33A17E9F6ULL, 0x596249F9A21045D2ULL, 0xAFA38CB5CEB702CEULL, 0xB59DB370ECD5DAE3ULL, 
            0x9A5EA5D531246866ULL, 0x95E8E23F2F79B97EULL, 0x971E4555976E453BULL, 0xBA73703CCD332EF7ULL, 
            0x57586A378B7106DCULL, 0xBA13CF926C608939ULL, 0x93B889C71082FD96ULL, 0x1759B23F8C87D52AULL, 
            0xBE3AD31BDC050DD9ULL, 0xA1A62E33167ADB20ULL, 0x8167653B312483BBULL, 0xDB2348B9D3D6D099ULL, 
            0x60653991411AB1C3ULL, 0xB3E8914AE86F9BF0ULL, 0x203058ECA5D91F74ULL, 0x3AE80D2CBE32511DULL
        },
        {
            0x0421D767B4C92637ULL, 0xE5217BBA55EAF3E8ULL, 0x2CDB29ECDC07F072ULL, 0x9BB72331AA857771ULL, 
            0x70AC54AD1320648DULL, 0x89A3ECC9AE1DE5A4ULL, 0xF4AEAFC3E02FDC53ULL, 0x58C9ABD6D322F008ULL, 
            0xD6D02E21330B3249ULL, 0x85360A0C5C8957A3ULL, 0xAECDC9B8822B980CULL, 0x48C1BC9BC03073AEULL, 
            0x3DEAC3DEC8722AFDULL, 0x2BB7F9A2D819B0ECULL, 0x125220DF2E0D8A5EULL, 0x9D6530A8C3DB1928ULL, 
            0xAAE9220516B9DABAULL, 0x8795FBC68A774216ULL, 0x79AC4D78C81FF7BDULL, 0xDD06392634FE53BFULL, 
            0xE5E3080D3F830C06ULL, 0x82B7F65D43EDB4A9ULL, 0x42A5B3307129BEFDULL, 0x05D7E1BC107F0816ULL, 
            0x31E5EBE19FE8CAC3ULL, 0xAE6D58F43ABDC4C2ULL, 0x982F4C940F6EEF73ULL, 0x0E5E5481315A2DF9ULL, 
            0x891E14EC98F47D42ULL, 0x9307A3A2366D17B0ULL, 0xEB8DBDEBF5D4CFF0ULL, 0x07427EB4DAEB44B9ULL
        },
        {
            0x8C443288B8AA29C2ULL, 0xE57F7AC166E13AFBULL, 0xD504EE993866ED7BULL, 0x624A3F7E10725A5CULL, 
            0x584EAE9465A91105ULL, 0x8DEC73EB3029651FULL, 0x6040EE35E0C49195ULL, 0x29741BD5C11FDF17ULL, 
            0x208CAF748641975EULL, 0x550BA67DB55C15D4ULL, 0x9AF8A26A00C4F853ULL, 0xD9AB1551F6FD8362ULL, 
            0xC39FEC9B99500D0EULL, 0xD3E8177BDC0D09C6ULL, 0x0606CCFFA9C92BCCULL, 0x01956CA44B337DB5ULL, 
            0x760D56081D7CCF7AULL, 0x5FABD697E1AD1578ULL, 0x30384B9122FCF3B1ULL, 0xE95817A0A8677452ULL, 
            0x99DCF0E83E9462E5ULL, 0xD589B3C43B219256ULL, 0x1E03B3282BE1CC36ULL, 0x89798C969EFC6262ULL, 
            0xAEE546998625728EULL, 0xCF31F02B23596E9EULL, 0x09C3002FCE7D55F4ULL, 0xA8E5A623726EDC7EULL, 
            0x4D734F7C72C32414ULL, 0x5BBFE81EEC59E47BULL, 0x7248F31D59746E76ULL, 0x45BC0CC8E4484788ULL
        },
        {
            0xB8F17ADC78DC2502ULL, 0x933D48596B19521AULL, 0x4432113D1C0455A7ULL, 0xAA22DD1D265BFB6FULL, 
            0x115134EA2E430F54ULL, 0x921D7298608775B2ULL, 0x7397C72B0A2BD389ULL, 0xFDC0B533FE3EABFBULL, 
            0xB6DCE6D05CD47F8DULL, 0x4FAF955E7DA47015ULL, 0xCA1B85C5D59C067AULL, 0x124B10D781216452ULL, 
            0x33699C9D90A7EBABULL, 0x8920603845A719D9ULL, 0x4671919D6CAEC289ULL, 0xAA41E9FD1AE6CBB5ULL, 
            0x0314CF28F79E2DBDULL, 0x799C8C840D5474B8ULL, 0x51629B3846D35E67ULL, 0x83B22B8FCE834282ULL, 
            0x5B2A075659D3020EULL, 0x40E95E83C51343B6ULL, 0x356460A4A0E548CEULL, 0xFFAAEE6E7810171AULL, 
            0x4248842EC8521D38ULL, 0xF1660010192C066AULL, 0x9608135DDD24CBB3ULL, 0x31820FF28B48EDD3ULL, 
            0xD6302C6FCDDDF1B4ULL, 0x723CFCF7B7C10BC1ULL, 0xB781804D1906DDA6ULL, 0xBADFCC9152030092ULL
        },
        {
            0x01496CBEF9C4CF43ULL, 0x8C977A4955026B7FULL, 0xEA24861B18B78192ULL, 0x43AAFF2293A90846ULL, 
            0x06F8C7AFFE27C37EULL, 0x5822B3F88BD21835ULL, 0xD4F9A84BA5165661ULL, 0x544AE264D509F9CCULL, 
            0x4B01E399942EF2D4ULL, 0x6663786B9A677628ULL, 0x04ED8C0D3FDD99D2ULL, 0x6E86457331C3170EULL, 
            0x6AD6171CFF7C0274ULL, 0x49D716E3E82A578CULL, 0x5828CFC5E856534BULL, 0x52452769DF21D8CDULL, 
            0xE05CFCA220E21D49ULL, 0x388EDC8987FA97ECULL, 0x03DD1BD310233FA6ULL, 0x6DED180DFE22C16AULL, 
            0x2B9F273699DD14AAULL, 0x903FD0754B70F04FULL, 0x70D029BF5C43468BULL, 0xFCE70E554BADAC8DULL, 
            0xBBC1DD6BFA9DE772ULL, 0xFDE45CD928245D23ULL, 0x3F1DAA2A08F937A5ULL, 0x7B41250F7AFC5EE7ULL, 
            0xFEEB064FC9158C6DULL, 0xE5BA46DEBEAD0D0DULL, 0xA0706D6DA8BF771EULL, 0xFFD238821ADCEC07ULL
        }
    },
    {
        {
            0x33AD619A38A923DAULL, 0xC3F42054A35426C0ULL, 0x352189EB5B5A4252ULL, 0x2D6627E8091F4102ULL, 
            0x30A8188AAB1CAFA3ULL, 0x9FC27D5711703739ULL, 0x5BB03EDFCB1A8CA5ULL, 0x111F4BFA03027737ULL, 
            0x6021D084E4491CCEULL, 0xE910CB888D9E89C9ULL, 0x5CE9CF1CBD30B136ULL, 0x25B52012951B18B5ULL, 
            0xF2133B81EF82339BULL, 0x524A81B312C13AC7ULL, 0x52D0F10AAF4B1FC7ULL, 0xF7210668FEC96780ULL, 
            0xEDDB99D7B1A5BDC2ULL, 0xA306F7FD678AB4ABULL, 0xBCEB4C80E61228ECULL, 0x4A91934EE010A0E0ULL, 
            0x886261421EC59DE1ULL, 0x9C6BD25102D04C06ULL, 0x5515BBF899768D45ULL, 0x004242570A615DD1ULL, 
            0x830415D713C44C41ULL, 0xDAB62A20F4277A48ULL, 0xCAE82440B4BCC0C7ULL, 0x3636BD1C5CC96E01ULL, 
            0x29DAAEF6AF5B72B6ULL, 0x6A06EBC9DA5DB8DBULL, 0x7D2767DDD16DE3F8ULL, 0x8095CF0A29DF238FULL
        },
        {
            0x25F6665530CBA965ULL, 0x9FAB07F048CE596EULL, 0x3085F54E9B90CA87ULL, 0x680F742FB3479F61ULL, 
            0x19D1F4336B3212CFULL, 0x46E437098C25292FULL, 0x13E108B6DB4A9DDBULL, 0xC3ADC5E7DD7FA3B0ULL, 
            0x15726324A2D961ADULL, 0x44E3F64AC12860E3ULL, 0xF8B9E635CCB9554BULL, 0xF30BCBBBBB31F77AULL, 
            0x86D61F6798362D2BULL, 0x883F79D0CE703C38ULL, 0xD47725FAA1917251ULL, 0x75265B2E00DBDA6EULL, 
            0x57C4D006125EC6C4ULL, 0x4A8EB4DC390EFA45ULL, 0xC14FE524160A519FULL, 0x1FAF49DBB78CAF62ULL, 
            0x464A4604F6DAE14AULL, 0xD3CAA76456C7D1ADULL, 0xFA6333805C0FDA15ULL, 0x1F79EE665756FB3FULL, 
            0xEE1140DFD2D1BD76ULL, 0xD4A2652A31A9ED7FULL, 0xD87B13B7327C0034ULL, 0x5B4A5E04F43A5332ULL, 
            0xFC287B36F786CA0EULL, 0xA7008D055294C814ULL, 0x3C82C92E3CDE3375ULL, 0xAF3F071D9C13D3F5ULL
        },
        {
            0x169F099DE49DA739ULL, 0x1DF295042DE79BA7ULL, 0x167ABBDDD67C6F29ULL, 0xF89653F4E16CD8CCULL, 
            0xE5B118C4B25C33DDULL, 0x9544FF2FFA56AB61ULL, 0x7B5515B302F09952ULL, 0xB25CAB5AEEEC5B09ULL, 
            0xA84B55F39E774B66ULL, 0xE32966A9C0CC051DULL, 0x99F6B519EBF69D22ULL, 0xBAC020B0B77100BDULL, 
            0x2ED06592F71DC746ULL, 0x322CEA93A84A0547ULL, 0x2E83CC2DD201AE60ULL, 0x6B3F4209285C65A8ULL, 
            0xD533375D2D80D4E0ULL, 0x93C2349B5B5838BFULL, 0xC9A1806389FF8EA7ULL, 0xAA4F06FFC411C5CDULL, 
            0xB380F1C4C1B51929ULL, 0xCE42D844F618C0F0ULL, 0x59EAC4D22775051EULL, 0x25D8CBBBAA66C280ULL, 
            0xC7F3331E6E8B682EULL, 0x25F0E89D2BE06246ULL, 0x816E96F1EC58D09DULL, 0x9A2CDCEFDE0925D8ULL, 
            0xA7F7C49A100A718CULL, 0x018A18C1A8F39A0BULL, 0x49EF5AB9BD6A6F63ULL, 0x8D5065A1B3596880ULL
        },
        {
            0xCE80A725F59DC3EAULL, 0x6768BD6096DED5ACULL, 0x97AFB2DB95CFAE96ULL, 0x91EFE65451506CFAULL, 
            0x287B8CB6ECF1171BULL, 0x22FE26950314B7B5ULL, 0x9009EB7518E93EEDULL, 0x2B78DF48D1952E64ULL, 
            0x9DCC1E6EF13D7E00ULL, 0x2A1FC96B60A4C62EULL, 0x2C1A1109BB355EA5ULL, 0xDCAFBE15B7026B53ULL, 
            0x573F98E7C81095F3ULL, 0x6F879F68229EADC3ULL, 0xB86D0747CD519CD5ULL, 0x447FF83CC841DC4BULL, 
            0x70978460381F4AA3ULL, 0x0FF2ACECDF8425ADULL, 0x953A65691E617F0EULL, 0x72E364F9BDB01503ULL, 
            0x75FDCDAD1762E76AULL, 0x6CB1D13DA3057757ULL, 0x8EE0FA5FD0ECE566ULL, 0xCC153E3BFEFB01CBULL, 
            0x408BB8C47CB04DC3ULL, 0x2972FEC5B15AC2D3ULL, 0x1114E0C4ABA4A352ULL, 0x8F7E2F2C5210D20CULL, 
            0xC6CCA1A362FA7DA3ULL, 0xF17C48CE2DA5DC45ULL, 0xD0B40A710C8806EBULL, 0x18F3B321D636476DULL
        },
        {
            0xA6F96B123415FC40ULL, 0x3D1AFCA4EA5EFBECULL, 0x15036463CB286379ULL, 0x6B8D4DECA7992147ULL, 
            0x68528574CECFBFA9ULL, 0x5915BF92690949E5ULL, 0xCD90ACA8CECEE253ULL, 0xC300E5A55ED41175ULL, 
            0x450C743A5E2A5923ULL, 0xFCDEE27FDEDC07A9ULL, 0x6CEEFA75F521D274ULL, 0xF8648E08C5FCE0C2ULL, 
            0x7D0FCF434B12A4D5ULL, 0x96218353BA60B674ULL, 0xC12ADDAD7BD13FFEULL, 0x970FDFD9FA5BD510ULL, 
            0x20E7233CC6E09487ULL, 0x679F3C1C9727498AULL, 0x6793535D77FE9DA0ULL, 0x98999D276AF33C49ULL, 
            0xC369BB4729F6783DULL, 0x746265695C4870A4ULL, 0xD1A19A6AB950EA5EULL, 0x0BB3EA863FDA0BD4ULL, 
            0x8219033C01AFE877ULL, 0x5908B96BD626B5CAULL, 0xCCA3E8153F32B5FDULL, 0xF86D28F28B341432ULL, 
            0xE60344701CE421FCULL, 0xF79EFAC44B07E93EULL, 0x04C6C13E80594452ULL, 0xC9138C328758461AULL
        },
        {
            0xD0712F92A194E33DULL, 0x4C54F17B89658FF6ULL, 0xBFCF79DE06789530ULL, 0xD970B0CE228FA345ULL, 
            0x210F2FBEE5E4226CULL, 0xAEFDC1896530C37EULL, 0x02B5F8B65D3C076DULL, 0x9EDC2F6B2D8E0F1DULL, 
            0x0AAFD07FBA2EFE37ULL, 0x4DA6B581B5F8C874ULL, 0x03736BA178192541ULL, 0x38AAFAB10A30360DULL, 
            0x1CF7D0D2E07C1FDFULL, 0xEDD7222576443A70ULL, 0xAECE872A38428AF4ULL, 0xD015CEEA2E7D2CEEULL, 
            0xBC6B2C656405BBDEULL, 0x58D73923CF911C0AULL, 0xDF241DEA5201EB57ULL, 0x55E296D076A9EC04ULL, 
            0x5B5D3F4D53A7127EULL, 0x66980BC5B72F490CULL, 0x74B2A37F8A0A2F3FULL, 0xBA37C6C1F8A207E3ULL, 
            0x8FFAE7E620B4BFA3ULL, 0xE4973063EC3F937FULL, 0x768BE55693372556ULL, 0x701487E90ACEE5A9ULL, 
            0x1841DFFC34AE4397ULL, 0x963916646C8E980FULL, 0x0A62203EED5809B8ULL, 0x7EB9E075070FFCCEULL
        }
    },
    {
        {
            0xB60E7861FD6020A1ULL, 0xD4F559F60FD742F1ULL, 0xC2E33416A750247AULL, 0x90057149671F1B40ULL, 
            0x19C767EB815CB807ULL, 0x4C915B2C1D15F035ULL, 0x577566FFFFCBEF64ULL, 0xCAA4B2E55DB14230ULL, 
            0xF07C6D4D3E69E477ULL, 0x4469997B68AF519BULL, 0x687118295D8ADB0CULL, 0xCFC9C4EEBF967151ULL, 
            0x840D6FCC7FBE7B8FULL, 0x56980F899C6EEF71ULL, 0xAEEE14F0B92DFF0DULL, 0xA2917DDED7C3103CULL, 
            0xBD76A2AA6D73EA4CULL, 0xF3BD8EE3BAB82D86ULL, 0x09901DA08302D8F7ULL, 0x33BFE44A1A58BEAFULL, 
            0x4A567A558C713434ULL, 0xE9690312394B5BD7ULL, 0x3CF7651FCFA78539ULL, 0xBFFA6A6D3EE6AF6AULL, 
            0x915AC42CB2D39F84ULL, 0xF01B29C8C2B95DB8ULL, 0x08B7B23351AC45E0ULL, 0x8335855F18FE52C5ULL, 
            0xECC1747C7A35DFA4ULL, 0x9209A4FE2D9A9BA0ULL, 0x8DA982BF13A50631ULL, 0xA1240980CCB5C12FULL
        },
        {
            0xBB1253AF24619C9BULL, 0x9536D506D5C9531DULL, 0x11B2A84B941D4A07ULL, 0x0E3018BF3D5376ADULL, 
            0xE12F005934F0E25DULL, 0x74C40F61357C6068ULL, 0x481AFD0594FE29A7ULL, 0x8E234041E3F2EBC1ULL, 
            0xA291BF1FE66F26C8ULL, 0x3BCBBBBFF460C027ULL, 0xD1F5FFABC162BC83ULL, 0x196221926B876AB7ULL, 
            0x75C58AC3BD6C5C3CULL, 0x9E30DEC6D54C0BC7ULL, 0x2714B88F49E3E083ULL, 0xB2E9FFCF570DC13CULL, 
            0xE6D26DA8E064156AULL, 0x8853C23EE5B1AB33ULL, 0x575922F8E319C47AULL, 0x86958D9994332C71ULL, 
            0xED18CE1716A58B1EULL, 0x7748896CD4E44637ULL, 0x15D4FFFDC2B950CFULL, 0x5BD1DC1367A20BB1ULL, 
            0x7976C16BA4CEF772ULL, 0x96E8C74CDDCF53C1ULL, 0x4E1CFA481F11D02DULL, 0xD36F82FD07CB8D80ULL, 
            0xFCA3BE54CD70AA91ULL, 0x7F20198CCFFBABD7ULL, 0xE5B709553D2E9794ULL, 0x01DD0B4EE17B08F2ULL
        },
        {
            0xA7D859BD00BF28ECULL, 0xECA90C4429A41EFAULL, 0x15F887AD58438B9DULL, 0xE995B15CADEFED4DULL, 
            0xF0792D8A8F8A5129ULL, 0xDF77CA0B6F2CF94FULL, 0xD0265EE19F4DD29DULL, 0xCB5E98FD89158A02ULL, 
            0x532AC48271F45ED9ULL, 0xCD50BE5BAB4F477AULL, 0x31FDBBE1FA9157FAULL, 0x0D2E81ABC61CB0A4ULL, 
            0xB2D24D0CAAF0457FULL, 0x180E28049C8A6648ULL, 0x68A52FCE6C60FC4CULL, 0xF5F468112A4415D6ULL, 
            0x6C55F57FCC04525BULL, 0x6F16E74C2DDA640FULL, 0x4F21293949246F6FULL, 0x2E737B6E89A7E1A0ULL, 
            0x74F508A4DB3C2917ULL, 0xB829EC459ADBC47BULL, 0x05FCDDD033CB5E89ULL, 0x5794A481DAD91A26ULL, 
            0x2E6B5D0E6CB4A92DULL, 0xDF09BA5636FFB0BCULL, 0x549B292CD1C157FCULL, 0x57F1B9231CB0C9EBULL, 
            0x67DF0D47A9FF7844ULL, 0x2F273DF44BDF3E79ULL, 0x0774E222AEE5B820ULL, 0x6D7588F0D7BD318FULL
        },
        {
            0xDC74800C25E84A94ULL, 0xE417A14AF1E7DDBDULL, 0xB0D71C513CF0C0BDULL, 0x50C9405CD04887C0ULL, 
            0xD0261688D1DB4469ULL, 0xD4A31FD881293E04ULL, 0xF82E36563A0B1E2DULL, 0xB5D6C3CE8B15AF16ULL, 
            0x6954D71928CD7737ULL, 0x12AABAAD8ABF820EULL, 0x16A0260C2113CF6BULL, 0xEF841A12054D4035ULL, 
            0xDF1F77B1A426BFD3ULL, 0x3E4CF6B7ABE3F40BULL, 0x11DECBA17F712B61ULL, 0xD4353333044E2010ULL, 
            0xADB099E33A7C8A4DULL, 0xCFF5ACD2D809C41AULL, 0x528F62C65B6FC07DULL, 0xFC6F7D9CB89137C9ULL, 
            0xDAC77612EB504774ULL, 0xFD9DBD7BAD866CC7ULL, 0x6C61ADDBB6F737B8ULL, 0x730B64D49952EE8DULL, 
            0xE847D77454C2D160ULL, 0xDFD8AB7E629AEB08ULL, 0xF3DEE65C50C9702AULL, 0xF81556EF057337A0ULL, 
            0xC4D38F6636F8714EULL, 0xE722440C0C55E6F2ULL, 0xF521E37A92AE5033ULL, 0x35541A234F429728ULL
        },
        {
            0x4735C98C576C4248ULL, 0xE66D8025A9296B54ULL, 0x1CB8C438A1E4B3F3ULL, 0xD7474FC53E526A92ULL, 
            0x24C1CDB2967778A6ULL, 0x560D04BBFBDB2F2DULL, 0x41FA395C43811838ULL, 0x5C22AD8D27FA9606ULL, 
            0xC140DF720CCD2B15ULL, 0x80123898C925B0E6ULL, 0x3B52A04526467350ULL, 0x70E56258D99B99EAULL, 
            0xDCB32A93C4B418E1ULL, 0x3D708677E7CDCC64ULL, 0x7456156C898F4751ULL, 0xDE2E1B1FA51EB5F1ULL, 
            0x9C3A74D7CC9C683AULL, 0x5A173265987A7A94ULL, 0x6087FAD7E2B9A85EULL, 0x79E1F255773A7D25ULL, 
            0x3C0C3AE13FFD936CULL, 0x04E3986ED2D72267ULL, 0x2050781773167106ULL, 0xE33F88AD2796B7F5ULL, 
            0xB3364DCD15FEEF19ULL, 0xC86EC94D4C680035ULL, 0xB0857E2709B4CB5EULL, 0xC1C662655C27E8F4ULL, 
            0xB2831973E1049F61ULL, 0x2E2CBDCBD9C9B41EULL, 0xE277EA467CBE3862ULL, 0x18452C0CECBA3B18ULL
        },
        {
            0xF8176CC8135B9294ULL, 0xFB4D862904D12A66ULL, 0x159B49207C00E721ULL, 0x86E0698112A2BD3AULL, 
            0x224D0181FC7C03B1ULL, 0x9973EC90D6B772D6ULL, 0xCDCFF116FC73FCF4ULL, 0x984DA8F17BD74CD0ULL, 
            0x5FE1A2DC255C803EULL, 0x052762059158CC6DULL, 0xFA22E26C3516B025ULL, 0x11416971AED54A05ULL, 
            0x6DAF165298D24815ULL, 0x48077D4244793FA0ULL, 0x2E0BC4B9A300A701ULL, 0x74F4CE1C33105B6DULL, 
            0x20B99D2E64CAB658ULL, 0x5929956B122BF915ULL, 0x623ACB90AAB8DBEEULL, 0xF3A69702E10F1FF3ULL, 
            0x96929E5EDF1F1CDDULL, 0x05532BE0952469B6ULL, 0xFF1AC577C8A14830ULL, 0x6915D3E255675B64ULL, 
            0x2CBE7F6495C9D7E9ULL, 0xF954F35A68400D14ULL, 0xFEE71798276A80B8ULL, 0x228E374533061A66ULL, 
            0x64BE9999C9CBB79AULL, 0x31BF09263013BFE1ULL, 0xB77A53AC41515BFDULL, 0x5B524A37D624BB6CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bellatrix::kKeySpawnBConstants = {
    0x96437DD04CA38EBBULL,
    0xCBEA5DE64D5FE81EULL,
    0xD7C2418756C5A88BULL,
    0x96437DD04CA38EBBULL,
    0xCBEA5DE64D5FE81EULL,
    0xD7C2418756C5A88BULL,
    0x58763AF7665C44C4ULL,
    0xD4E28C23E094310FULL,
    0xC9,
    0x84,
    0xFD,
    0x2B,
    0x10,
    0xA9,
    0x56,
    0xF0
};

const TwistDomainSaltSet TwistExpander_Bellatrix::kSeedSalts = {
    {
        {
            0xD48BBFF2D669F7C0ULL, 0xCCD862AE18D441B5ULL, 0x256F057F6ACCE38DULL, 0x92F956E4A8CE0AFAULL, 
            0x7D0F025FD9055F29ULL, 0x560E182B9CF0CF36ULL, 0xD6313A26EA64CFD3ULL, 0x9B71620AACD347A7ULL, 
            0x4EB6596213CFEE21ULL, 0x206B4EB4C32409CAULL, 0xF2B4655B063B6BD9ULL, 0x8BF4B0F90BB236C1ULL, 
            0xA86CC358F8D90167ULL, 0xC10D04B284844C28ULL, 0x549B25C1B4E74624ULL, 0xF438B2B51FC526E2ULL, 
            0x02FDE469680EFD8CULL, 0xF3EC3946B737AF95ULL, 0xDED94E5C83F853B6ULL, 0x61D17CB6E3659694ULL, 
            0x179637AAE28E8158ULL, 0xD000DA3E005DD86EULL, 0x47911ADAE15FD07AULL, 0x2F0545F3A0AB4246ULL, 
            0x89C190FFF6853CF7ULL, 0x8820D1667685CC4EULL, 0xB4451888730C6AF1ULL, 0x706C15DFD1A84D03ULL, 
            0xC956202DBEA556DEULL, 0x6287FAC2CC291E47ULL, 0x2CA989B9A694AAA7ULL, 0x7E205CD8333E3368ULL
        },
        {
            0xF8264DC10FAEEB03ULL, 0xAA9D18CC023F56A2ULL, 0x4A32210CA291AFDFULL, 0xDF3853B81824A611ULL, 
            0x1B8B4B3DC06CC645ULL, 0xE73532DC1ACAE0A0ULL, 0x5802977196F78B20ULL, 0x18F5B9E6654B4BBDULL, 
            0x0DDA2113064A6075ULL, 0x7ADF68D7F8B6E68FULL, 0x660A983EC77B9BBAULL, 0xC5B243A06DD9212FULL, 
            0x1E29BB847C490330ULL, 0x8ED7C70ED3BC4F9BULL, 0x9EF171D7566A2EB9ULL, 0x0996B0404F5ACF1DULL, 
            0xA6783FEB3535C449ULL, 0xFE457A443A888902ULL, 0xF2C9452326D7F236ULL, 0xC0A5362C535CA480ULL, 
            0x86F554A2259AAA5CULL, 0x1EAB80A458B5EB24ULL, 0xCC82CACBC70B8A97ULL, 0xBF42C58E5691C8FDULL, 
            0x6C1B900C086FBDFFULL, 0xC660AED9E20A36B9ULL, 0x684866BC5A06F9CEULL, 0xE4D2EC3DD4E4C2FDULL, 
            0x950DE118214408DCULL, 0x45DD9B639F153DFAULL, 0x867FDF0DCC95E248ULL, 0xCADDDAD82A0F34D4ULL
        },
        {
            0xCCA360F193E3831EULL, 0x58578A2958863E36ULL, 0xFD9A71391DEDB884ULL, 0x9D31924E9C7F2905ULL, 
            0xA6A5359A20C7BF54ULL, 0x7709777D228B5406ULL, 0x02C0F386022CDF15ULL, 0x62751D0D7E4A877EULL, 
            0x745B84DF62B68CE9ULL, 0xFFF7C80E8B2543F6ULL, 0x82BA8459523B8019ULL, 0x760C777A2A06C983ULL, 
            0x7BBFDE22B2717D7BULL, 0xD88D212F54A2302BULL, 0xA763FF014533DDE1ULL, 0x86863BF00150BD52ULL, 
            0xEF1F95A9CB5A4284ULL, 0x8267CFFCDA3AA388ULL, 0x3A89D26A87D24B19ULL, 0x4F8C709270F6F669ULL, 
            0xAD4FB19DCEF35AA0ULL, 0x953AA16D431641E7ULL, 0x7070DCD0FDA8756EULL, 0x04892E73B69CED72ULL, 
            0xE08F82DC5404426CULL, 0x417D9225B707D8B9ULL, 0x48919F0F8A54B8FBULL, 0x81845D8199D8753DULL, 
            0x6F3C0C4DC3FB6266ULL, 0x2EE61A1EB01033F8ULL, 0x03C9BFF82D60FF57ULL, 0xCD155EE64A52441DULL
        },
        {
            0xD99175638246B1F1ULL, 0xA43C90A743D9447FULL, 0xC4244668897CDA3EULL, 0x4DF9C946809C45BAULL, 
            0xC30E76339AC583D5ULL, 0xE82F28CE467AD7FEULL, 0xE8BB993E28B5CA79ULL, 0xBB1E95CE4C7FB68BULL, 
            0xE36355210AFB254EULL, 0x58D6FC04FF7445E7ULL, 0x98124BE7D9832C4CULL, 0x8B31B3952FD10388ULL, 
            0x22064151BCBBA050ULL, 0xB91103DBB03C055BULL, 0x7DDB9A6BA779EC0AULL, 0xE7CED4B9067B256AULL, 
            0x493C43EA58E5DF81ULL, 0x362BAAAAC5F504FAULL, 0x1F0518D229797CCDULL, 0x8E4A5FD1FA32F841ULL, 
            0x2C61A07C54F6E501ULL, 0x3226FFA73262D5B7ULL, 0x143571A97C8894C0ULL, 0x5537BC23EC40DE98ULL, 
            0x02D64463ED393159ULL, 0x1FE0DE1C061617E2ULL, 0x8FFC043E9FADAE18ULL, 0x2DE070123102B003ULL, 
            0x49718D4A4B471D91ULL, 0x810BE3D1CB844FE3ULL, 0x633C904983FA8ED7ULL, 0x55992DE63AA1863CULL
        },
        {
            0x746FE3868D1483A9ULL, 0xFC69CA1A5993F2DEULL, 0x618B1C6AB5091BCBULL, 0xA4C0FB08D37F686BULL, 
            0xFE12E7B1A9A8D7D9ULL, 0xA42146B8785672C7ULL, 0x578E0A6857E700ECULL, 0x459AFBAA217697F8ULL, 
            0x832506D988F2E553ULL, 0xF192068A7A308539ULL, 0x3C4E56BA5D072040ULL, 0x2D7E02BA307B4A8EULL, 
            0xBD528888570F64B8ULL, 0xE164A3D9D5736184ULL, 0xB8E12C99810B379EULL, 0xC501DBCF41D5780CULL, 
            0x0ED33EBCCDAA75D7ULL, 0x1E05ABAE91C298E2ULL, 0x8F23B5DD06A66264ULL, 0x3CF71A9D0B358190ULL, 
            0xCE2800FFC663AED7ULL, 0xB26FF42F3FEB490AULL, 0x26708DE6D22C4F15ULL, 0x5B793A306D3B9632ULL, 
            0x02A0349BBAB6A6A7ULL, 0x499FF9699996125EULL, 0xD0B26863C118B688ULL, 0x60AD383806C43021ULL, 
            0x0C469550EC0C5844ULL, 0x48BC2858433F0392ULL, 0x054C1BB66B61D487ULL, 0x4E6C1C831795E873ULL
        },
        {
            0x94BB9B07D5B23CA2ULL, 0xF202B5996CACBDFFULL, 0xA7CD0C0701836762ULL, 0x6ABA73001593735FULL, 
            0x719456944F16CA38ULL, 0x30AE078C40264BFFULL, 0x591565D6BF7E1680ULL, 0xB4EE358BD0A9F129ULL, 
            0x3BECEB66C86F7C3FULL, 0x58519262F7A0B88EULL, 0x17CEA9E90DDF85DFULL, 0x2C53C7D95AE9AA08ULL, 
            0x0F1163CBB828BE5DULL, 0x1F274E4E9D22ACC4ULL, 0xCDEE6231B62229ABULL, 0x99CE97D9A3979D13ULL, 
            0x768DC039D86F3155ULL, 0x8D673902408A4E1DULL, 0xB2306CBFF4A34C5BULL, 0x0C0D79FCF61E08E8ULL, 
            0x72262D49D9A90E0FULL, 0x594492B6BD97D0F4ULL, 0xBBDDC029C72EC32BULL, 0x32F4B5F2810974CBULL, 
            0x76B16FBD032185E6ULL, 0x6D8F59F3BFE15F50ULL, 0x9E6FFA54980778D9ULL, 0x05F7B4D1EC4CA163ULL, 
            0xEACAA31DA8C00623ULL, 0x027C2E14E2361A99ULL, 0x15CB2EB29C2CB536ULL, 0x85911C54E9425400ULL
        }
    },
    {
        {
            0x087D9C5581C689EFULL, 0xBAD8FF079DE329CBULL, 0xE1F57E93A8F17150ULL, 0x85A59F292E9E2054ULL, 
            0xBD70C03EDFD7E6FEULL, 0x82FD11B3D1E86D0BULL, 0xEAAE9B5FA4D42DA4ULL, 0xA31668A55B17DFBBULL, 
            0x4CFAC8477C875A16ULL, 0x173FED7EE079D431ULL, 0xFDE0242897E6DF0AULL, 0x649FFC0F155BB16BULL, 
            0x451BA1397B055235ULL, 0xC803D0EA2C21D5E7ULL, 0x241A6BB0E56B9F3EULL, 0x53BC68ACB6CF7CF7ULL, 
            0xBD36E9A175FA73DCULL, 0x2F5248A1A0D7AC3DULL, 0x64A51758A2FB761BULL, 0x6D529B0DDEF96F3BULL, 
            0x2615A962E63D0F50ULL, 0xE22F2502FB339ABDULL, 0x9F54EA1D0CF01735ULL, 0xEC06EA6784D60A33ULL, 
            0x68169E466391CBB3ULL, 0xE1233DB72EE2140FULL, 0xCEBE6644781B4D6DULL, 0x8863AEA0179D8FFCULL, 
            0x17DE2B8E4830402DULL, 0x73741D083588CDF8ULL, 0x98085C6EF4DB525BULL, 0x8ECE571F713C3029ULL
        },
        {
            0xC534E7971E1AB978ULL, 0xB436E3E1C259D686ULL, 0x84479D4AB7A42032ULL, 0x5BC8BBBA35900287ULL, 
            0xF3B5FD43ED56FED1ULL, 0xF7ECE8C71C605A90ULL, 0x96FBAB578BCF8ECEULL, 0xB71081F6CDB8A603ULL, 
            0x03E7C8D692E04E93ULL, 0xADC12ACD69D80B4FULL, 0x8D2D3BE694323480ULL, 0x55ABD685F416938CULL, 
            0x3B663F79E8B5AB00ULL, 0x6B0BAE2B83E98160ULL, 0xB09628B4AAE8EE7FULL, 0x264AEF0FA720DAB7ULL, 
            0x15B1F7A2A20D355DULL, 0x251838C1E25E7E6DULL, 0xF2DA27C2FC5A4D05ULL, 0x410413563AF87A30ULL, 
            0xB91B2C6BF9970DA6ULL, 0x34AFB59F4004FB53ULL, 0xB447D46E9FD7822BULL, 0x8F0610952C6A6E2DULL, 
            0xFB212AFCECB2A1BAULL, 0xC8B737E58C856885ULL, 0xBF9CE044A33B30E8ULL, 0xE48A22BFE5A67446ULL, 
            0xA25D6E617B8C0BD8ULL, 0x62C34C928D085C12ULL, 0x8D39BE8BF2113326ULL, 0x89EB01882320C851ULL
        },
        {
            0x9FE35669E4579521ULL, 0x30ADFA6C74BACAE5ULL, 0xE264E267782A2078ULL, 0xC1DAF74CFAF5E18EULL, 
            0xCD07E7D861A095D2ULL, 0xC6834DDDCC8B84CDULL, 0x343B896973AD960FULL, 0x64A590A29D4660F4ULL, 
            0x951BEBBE361735C2ULL, 0xA030CEF56783575AULL, 0x675312A4E9840E3CULL, 0xFE5054F36D719561ULL, 
            0x63B33CFBC79FAB3DULL, 0xF5361964716B848EULL, 0x15AA10AEDFC156A6ULL, 0x4DDE604B3780EED7ULL, 
            0xFED11F3B67971751ULL, 0x92E765927A406206ULL, 0xE4A1F4355F258F46ULL, 0x9393EB133376FE5EULL, 
            0xA5257C1FC8B88C67ULL, 0xF5CF293CEE37AFF9ULL, 0x9C74A5456827BDF4ULL, 0x04A43F6C0070E3E4ULL, 
            0x0C5CC42B3A249B8DULL, 0xB90F84035104C8EEULL, 0x96C02D818E489A6EULL, 0x361B666282A04678ULL, 
            0x92CA8FE0A5CBE5A8ULL, 0xB66E57AAAB0538C1ULL, 0x230DCF51CE2B79FAULL, 0xF15B1EC55EE5B135ULL
        },
        {
            0x24B608F517755E96ULL, 0x1E324018BBD7213BULL, 0xF99324C460FB1A77ULL, 0x2F63A6601EF675EEULL, 
            0x43EAF6DAB135DB69ULL, 0x53C86F65EC346CE0ULL, 0xA2C70FF99022BDFDULL, 0x139BBBA3A5A06D6AULL, 
            0xA69FF6133EACD7FAULL, 0xFD76F1BCB90B5427ULL, 0xCC74ADB6C526AF8FULL, 0x1177063B4FF763C8ULL, 
            0xDFD3228D290FC842ULL, 0xEEC005DF99981C61ULL, 0xFB7E276C8BE8F2A3ULL, 0x6B8C9E6D13487CCFULL, 
            0xCB8DAA0F7C5DFE44ULL, 0x365937320536F20FULL, 0x3D687C51AB9A9E5FULL, 0xFEF461F42CA7A9A1ULL, 
            0x7B4D39B59CA2A9DEULL, 0x283E52264C2F41DEULL, 0x01AB9391A95C7397ULL, 0x7262E8B5A31DB2F7ULL, 
            0xBEA4E18E0E521FCAULL, 0x70FAD94743921BF9ULL, 0xB46BCB08914FE3D0ULL, 0x18746E10AD4056A3ULL, 
            0x8D9A28EDDDDFC811ULL, 0x2ACFB553E53CA96AULL, 0x821312E687146349ULL, 0x178591BF3D3D6F8FULL
        },
        {
            0x61D0C7EE5ADC5299ULL, 0x1B0C2A481CD1650FULL, 0xAC6D81FBEDB5C9EFULL, 0x2D57858EF894845FULL, 
            0xDC1E3E014D30D823ULL, 0xBA227F27039D4C45ULL, 0x6C973BC87FFEE749ULL, 0xA22E1FAB39D515C3ULL, 
            0x17845C21DF17FB0BULL, 0x5F79DF707310D112ULL, 0x4B913673113BB633ULL, 0xADF359C57847EEE6ULL, 
            0x55A143FB7BC00690ULL, 0x09A1FE65D23126E7ULL, 0x79B0B5AC8E3D5B05ULL, 0xD76A0FA7F3453C74ULL, 
            0x41576A4F1DDC7BA9ULL, 0x5BCBFF1B398B64FBULL, 0xA4FF252E1AD8D977ULL, 0xBBDA5467CB6743E8ULL, 
            0xFC44B2B158DA1F64ULL, 0xFCC9B66215075342ULL, 0x1811DCA1C9A61469ULL, 0x9B42F485FA057206ULL, 
            0x00FDFC3549B8EF7BULL, 0xC7679657B5A7B58EULL, 0xEA845A0375B55B59ULL, 0xFF896F2BCA0ABEC3ULL, 
            0xE58902EF6B364366ULL, 0xF8365A69E46E9682ULL, 0xA664D44B9D61318CULL, 0xEC008F97B952D9FFULL
        },
        {
            0x5FC8C2D2FC6DA8C3ULL, 0x0F5417014E72C3BEULL, 0x1115DBAC3D7EB095ULL, 0xA0EB8B77A1EDA82DULL, 
            0x75FC0DA59B59756BULL, 0x2E7875509BBEB8C8ULL, 0xA4855DE514D6836FULL, 0xD96ACD59C75ED0B2ULL, 
            0x7C4C8267754220BBULL, 0x0D0DB11E199F9C57ULL, 0xE14139647C773075ULL, 0x428E4F367F8BE0ACULL, 
            0x37547343A992A7E5ULL, 0xE09280AF39A15BF8ULL, 0x59C3F96D941803D4ULL, 0xDC448C74EAD98ABFULL, 
            0x2D6C80659106E5D6ULL, 0xDE26D6302BA52042ULL, 0xD29F93C942B19080ULL, 0xB0826EE94ECEA80AULL, 
            0x20FA550FDB601517ULL, 0xD6BC9FC5B429FEF7ULL, 0x1F8F633FEC953D87ULL, 0x41D54E702728B7D0ULL, 
            0x0341AE694B2C8CFDULL, 0x2718C6312A873613ULL, 0x476FE85AB85A61E1ULL, 0x0B6154DD06C540ACULL, 
            0xFADACD8A9D40D547ULL, 0xCECE0EEA0A331025ULL, 0x085B178D1DD2020BULL, 0xE3B27E0127CC5EA4ULL
        }
    },
    {
        {
            0x46F55C410F76EE5AULL, 0x4525D52CB56CAD94ULL, 0x324499576C345330ULL, 0x55F47BA1F4158AB5ULL, 
            0xFDF6E2B84CD165B7ULL, 0xF9F6BB9D8EE0DC66ULL, 0xBC1F3A6F5C718E6AULL, 0x0493D2FEE568AB17ULL, 
            0xFF5322A094568CB0ULL, 0x1E0894154CEEEA24ULL, 0xAD94B3B331F6F2E6ULL, 0x5A0E84DF90050135ULL, 
            0xC240E104E6D9D18EULL, 0xB358FD36A60CB91CULL, 0x3AC777613E8CD56CULL, 0x4C717672AB1B2B6DULL, 
            0x9AF7A64AED80E79AULL, 0x40CCD7149D18DDDFULL, 0xF62A2ADF12F63851ULL, 0x5369A7C2F7EA6567ULL, 
            0x713E66663998C5D8ULL, 0x77A4210BD81D74CBULL, 0xBF06CEF02A023E6DULL, 0xA924342D4574E47BULL, 
            0x4045ED5169A343E7ULL, 0x8CB4F5D8117776AEULL, 0x0B006E19A5F9C6D6ULL, 0xB6F9B092F82785B9ULL, 
            0x0061755BD185C051ULL, 0xB13C05753870910DULL, 0xB72C9896CAD1F573ULL, 0xEBBE0DC62F4F5E54ULL
        },
        {
            0x1D62A83AF4BF50B5ULL, 0xC1E46489F54BDFE6ULL, 0xA329219961F89B02ULL, 0x5855F473623C9629ULL, 
            0xFB25B014FA9B915DULL, 0x076418E5F7187B4FULL, 0xD337CC686174E79FULL, 0xBC7022299482C48FULL, 
            0x4E35BAAB079BA00EULL, 0x07A09C299A80E705ULL, 0xAB2CFFC30A0B7E66ULL, 0x1E602AFAE16881C5ULL, 
            0x0899A96066A8E0B7ULL, 0x32A55F5F7E668C1DULL, 0x1DCCEBD668E87878ULL, 0x0D42D65FD405BECEULL, 
            0x73DC12F738D56701ULL, 0x9820439CFF463DCFULL, 0x73EBAA74006E0775ULL, 0x8371AF51BF6E21E5ULL, 
            0x774533A6F5229B55ULL, 0xA0001F510D1F0A83ULL, 0x82E69BDCC96F11B0ULL, 0xA46FB49114598B62ULL, 
            0x79BF2C6509A66D40ULL, 0xD9E5D7B5FAEC9CA3ULL, 0x564DB79C8BF75AD6ULL, 0x2CCD20A71656D606ULL, 
            0x757E63DC569B9299ULL, 0x495F092BB019C797ULL, 0x2127F74EEDA45F90ULL, 0xC1A3DDF75D20CEC2ULL
        },
        {
            0xA9B7F15ADF83A931ULL, 0x245DEA712DB5F6ADULL, 0xFB51E639461B8E3EULL, 0x71EC09450CE4991AULL, 
            0x93404E0A47521447ULL, 0xADE3EF53740EFD03ULL, 0x66C5F77093434C43ULL, 0x63CCDD8088E6E012ULL, 
            0xF326D2860ABA0633ULL, 0x7A5428C3DCD32F7FULL, 0x478A8D5E1724B64BULL, 0x0820E6A559CA918FULL, 
            0xA9BB7D650E4100C3ULL, 0xF1F0265EE0174B45ULL, 0x652898FD9A1E3D94ULL, 0x60B390F1E5EBEE72ULL, 
            0x6F45476647B84381ULL, 0x33CFA25FF144444DULL, 0x96F57D801B278FECULL, 0x30B82E42DF512BEAULL, 
            0xAEADA69CD1803891ULL, 0x04D6D6C07472B678ULL, 0x974B2AB7F1076E8AULL, 0xE0D431FC3E2CC626ULL, 
            0x9A65291ED02A7211ULL, 0xC493FAC702E8B104ULL, 0x204DEB2BDD60A163ULL, 0x41AEBC3E467FF039ULL, 
            0x476C5F717DF22776ULL, 0xEB6D4631B0B6094AULL, 0xDD0D8773DE02476AULL, 0x12294971CE44AF97ULL
        },
        {
            0xF0EE20F1B0AE60EEULL, 0x3503449ED2D4B5E7ULL, 0x43453E66B9F8EF7EULL, 0xF666B5D885C6918EULL, 
            0x7C47A59B8957BC00ULL, 0x5A6064F885563ED6ULL, 0xBE8FD2EF70E3B0CEULL, 0xE7A3D880250087DDULL, 
            0xE2354CF7433D894BULL, 0x0714D2975A297078ULL, 0xD842BBD03901F31AULL, 0xA8883986BF2B242DULL, 
            0x1C0B5876DF9EFFCBULL, 0xD3AD84205BC6EE0BULL, 0x6E7812AFF2FA94D8ULL, 0x5589C514EB37188EULL, 
            0x878817591E6B820EULL, 0x787FA6F875FC48E6ULL, 0xF8A667B7B02F1E09ULL, 0x6C22D1A96B6C8440ULL, 
            0x750EC74D4DFE44C2ULL, 0x1A1CC3E8F0D935E4ULL, 0xDD6AAFE415D1F4C7ULL, 0x85500D645B7CED85ULL, 
            0x6EA83DFFB010BD62ULL, 0xAFFB4DA72A3FB611ULL, 0x8FE96D65EE17762CULL, 0x9C97F53BE606940CULL, 
            0xA600A2BA985B24FBULL, 0x7AEDF46450EC634AULL, 0x3C5450C3629EFF02ULL, 0xA35E87DA6FEEB9DEULL
        },
        {
            0x3FE38BC3CA1DC9D5ULL, 0x6385CFEFD9168E2EULL, 0x1E250A05AF3C8BABULL, 0x2D18E97C3162BBD3ULL, 
            0x158C63A9648A60C0ULL, 0xADA0FD41C3CBBEB0ULL, 0x04BE5C25A8C45026ULL, 0x974CB61FD6A6FA25ULL, 
            0x6D310FA59B41C14FULL, 0x1505D9A2F333CC0CULL, 0x67BEBB4130960B3BULL, 0x761661A2C7FF0E58ULL, 
            0xB245A40A32071911ULL, 0xAD77E0ADA8A3C3A9ULL, 0xA6A1C72E6510407BULL, 0xE4790837FD3B1867ULL, 
            0xA417AE51C31065D2ULL, 0x76CCD688D4340934ULL, 0x963976FC6E7486F2ULL, 0x389CA277AFE860E0ULL, 
            0x8B1A3C13491F780BULL, 0x47CF804022E5A9D0ULL, 0xC8DC17505DE99335ULL, 0x233D6A7A2EC530D6ULL, 
            0xD011683E74E83618ULL, 0x0690C7954A737F57ULL, 0x0AE3DB8FD067539DULL, 0x61ECC5CDF602879FULL, 
            0x1BAC8521003D096EULL, 0xECFE98F82B7223EDULL, 0xD0C71064D9DAA0CAULL, 0xCEE8315225ADFE12ULL
        },
        {
            0x0014C1EC077AF3B1ULL, 0xED5DDE09AA3D150DULL, 0xFF9EE67723861BD7ULL, 0xDC4F634828A419D2ULL, 
            0xE4C42C65F1718A71ULL, 0x3F52939F94FDE3F3ULL, 0x5EC84D801977E134ULL, 0x40D278B82A0C1D72ULL, 
            0x7AB544D100387751ULL, 0xF705D54025B8DB2BULL, 0x7FAB8010DFB6355EULL, 0x2F5C84F0114917B8ULL, 
            0x019D3CBE24F12431ULL, 0x6434E1D85F3BDF63ULL, 0x0C59D3963DB52840ULL, 0x304C7DDB54BC4224ULL, 
            0x172C6C0EFB6458A2ULL, 0xD28A6F72A9627494ULL, 0x4D9277B36353EBEDULL, 0xBEB1AACD7B2A2C50ULL, 
            0xAC6347B8FCC4D47EULL, 0xBA798FFC7AC7E3BFULL, 0xB9EA5F0A19FD307AULL, 0x50F56263E704441DULL, 
            0xAB1CB947889F2591ULL, 0x5D6C9656D03DF01DULL, 0x2DC8AAB1A13A6B8BULL, 0x3417DF7A0A19ADDCULL, 
            0xD35C896805692448ULL, 0x3AAAED30563BF213ULL, 0x36E471A78DB66F9DULL, 0x86BE0FF1CDBB17DAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bellatrix::kSeedConstants = {
    0x5EEB48AD49553C85ULL,
    0xE7114701E1F6F02FULL,
    0x314DC50D0BB0456AULL,
    0x5EEB48AD49553C85ULL,
    0xE7114701E1F6F02FULL,
    0x314DC50D0BB0456AULL,
    0xFCE51325271C0668ULL,
    0x7435C42FC0943F20ULL,
    0x63,
    0x68,
    0x7A,
    0xFC,
    0xB3,
    0x3A,
    0xDC,
    0xEA
};

const TwistDomainSaltSet TwistExpander_Bellatrix::kTwistSalts = {
    {
        {
            0xF360BC4B8A9929A4ULL, 0xD660C7598B384891ULL, 0x027B8BFCCE33F869ULL, 0xDCC11F2E77489F9DULL, 
            0x3ECBD063A2787CE8ULL, 0x558AEFB22C2AB271ULL, 0x599F71C5559B778BULL, 0x4DF37AE12848B837ULL, 
            0xE6D951A16311A188ULL, 0x575574DBEE30E5AAULL, 0x1A4B9F63D15CCE7FULL, 0xEF3A18C74699AAA3ULL, 
            0x9B3F086ABD4B3A55ULL, 0x4B31AD8AA9A118FDULL, 0x14997F5DE50D7455ULL, 0x3AE72D773E734DA1ULL, 
            0xBA0D3071D4CE20A6ULL, 0x81EF1180951382A4ULL, 0x6C2F5E7CA5060B40ULL, 0x9932BF01350B6813ULL, 
            0x722CDF941CF6F281ULL, 0x580E5A49DB3D7437ULL, 0xF23BF4AAD97288A4ULL, 0x2E0BC3C0F7B7B28CULL, 
            0x638CE85969FC0A73ULL, 0x0C099951C733CB87ULL, 0x9119B393C908713DULL, 0x5EF38FD9E857953CULL, 
            0x4C00FFD926FEF586ULL, 0xBA64D75F8D9B892EULL, 0x15E93338BF19CC5CULL, 0xE271E660C4ACD075ULL
        },
        {
            0x70ADC3EFD1449A9CULL, 0x41A4CE9172FA38CFULL, 0x229047ED3467104DULL, 0x4DE0E326DDABFC7EULL, 
            0x4BBD1D0BBDEE4029ULL, 0x9CB08711C0B6ED45ULL, 0xC6381BDBF3305F0CULL, 0xF7D5DD93C981D4D9ULL, 
            0xCCDCB20CF825608AULL, 0x84407948B8AEBB2DULL, 0xC898649FC3E3665EULL, 0x40CF7B387829EB85ULL, 
            0x5C383932A33D819FULL, 0xD3F2D472562FBBAEULL, 0xB8CEA005AD42EC88ULL, 0xF803CE37D1ACFD3CULL, 
            0x8092686C64329BB0ULL, 0x1178FC0F84997744ULL, 0x1EB713B2F89A56C0ULL, 0xB8408C7DB3207770ULL, 
            0xCB2ECCF9C9FACAB6ULL, 0xE44081CB4400F114ULL, 0x433B5D1536049A70ULL, 0x8B3CC51ABF2F40B8ULL, 
            0xDF5DFBAB1DC3A4BEULL, 0xAC6D45D9B69B235BULL, 0xF0DF15088D90A231ULL, 0xEA0A5A8E03C115DCULL, 
            0x41C172EF998C49AAULL, 0x1031F71ECAF8608CULL, 0xF88643EE6DD60DE1ULL, 0x75211777537372DFULL
        },
        {
            0xFDFECE80FB398458ULL, 0xF7DF28103A2905E9ULL, 0x0841EFCA477DD0A1ULL, 0x953EABD7003CBF9EULL, 
            0x43AC7498FB11D184ULL, 0xA3147E1AAD213478ULL, 0x5288BE2AA9D484F9ULL, 0xD0B2DD03093CE71AULL, 
            0x3DB11BD97D75585EULL, 0xB8ECB3C69F815FFCULL, 0x11BB6B24E8490720ULL, 0x2A5522921B89847BULL, 
            0x89CD3F736625304CULL, 0xF39DDE6EF62A2D61ULL, 0xB2878E715FF0D075ULL, 0x656D066ACEE691F2ULL, 
            0xA755FD3DA1BD190EULL, 0xCBD0ED01FAA8764CULL, 0x102553F791A2E5B1ULL, 0x12F453C6B60C6940ULL, 
            0x7F32C4859300D660ULL, 0x4645BE24071E490BULL, 0xE9F0D447A6F73DF5ULL, 0xA5905184C8276835ULL, 
            0xE099FCF33F661A01ULL, 0x32195AB05A2AC65DULL, 0xC8508750AA473D11ULL, 0x10F2FE70EFD6623DULL, 
            0xD306BD3861DCBE56ULL, 0xC216E795B545E1BFULL, 0x345CC14DEB6AA5BEULL, 0x805F111534B6855EULL
        },
        {
            0x5ED362DE6AD9E6ADULL, 0x6156036B01F11E3DULL, 0x1D82263FC9D5C6E4ULL, 0x8A0A306F125E7183ULL, 
            0xC9656C634F147057ULL, 0x8F693FB9507D7523ULL, 0x989D4AD29EC646B5ULL, 0x62EB7B196EF9BDFAULL, 
            0x70CD209818DF3E16ULL, 0xC4B2DFD306D4910DULL, 0x98283430857E55B2ULL, 0xD5E10C30CF3C94EEULL, 
            0x84E893854A2710F6ULL, 0xBFD8AA1B8EE22397ULL, 0x4C2918AC768F4932ULL, 0x9E4EB63EABE78E39ULL, 
            0x512574791FB178C2ULL, 0x13518B0083DFEDABULL, 0xE7D5FB50E9D37A49ULL, 0x4035359AA0A8DDE9ULL, 
            0x5BB73843B63A2045ULL, 0x258CDF3F335841ADULL, 0x737363E3B49AD97DULL, 0x5F492591465D983AULL, 
            0x97172CBB13703808ULL, 0xD315C974929C67DEULL, 0x060C23B49B26D27FULL, 0x12B5D9A9439EBDFAULL, 
            0x746C906767EC3458ULL, 0x212968C9F1930EC9ULL, 0x51C76958556633BAULL, 0xF0C12C67D7B3EE7CULL
        },
        {
            0x8291591312DCB467ULL, 0x60CA1E7A1875B865ULL, 0xF9DEFAC3AD9C1DA9ULL, 0xF1261222E1155094ULL, 
            0xD1FCFECA556EEAFFULL, 0xD72CF940A98E4BE9ULL, 0x529AB1A82AE5BA35ULL, 0x286239506326732FULL, 
            0x7D86960C33483C34ULL, 0x9AB49A3B09ED926BULL, 0x8098709F4ADAA732ULL, 0xBF6E3A55E5DDCE26ULL, 
            0xC222FB9060C76734ULL, 0x209AE8540D313CEEULL, 0x539A30E06A59AD42ULL, 0xE6095CC51EE670AAULL, 
            0x396758634B74339DULL, 0xC3870628CA4A8C07ULL, 0xC7CEFF2C293DC2C1ULL, 0x0AF7E5D9C0EC4ABFULL, 
            0xA6723CC10F85B6D0ULL, 0x87BFE15BFE2EFF4FULL, 0x1305F6FFBEB1D63EULL, 0x8578541167710A4CULL, 
            0x3C000C150B93F8A4ULL, 0x41D81EBC8F28ABE6ULL, 0x251F3C4B15FE92AFULL, 0xE175F1BF5338F378ULL, 
            0xB0D2A57343CF9378ULL, 0xE32AF1729EFDB1A2ULL, 0x349C317B4F40E6CCULL, 0x7D7D8728298E4C96ULL
        },
        {
            0xB1C16426E490DED2ULL, 0xFFE99C8D4E9B1252ULL, 0xCB74D15AD6A84EB8ULL, 0x68A4AEC6ADCDAEAFULL, 
            0x1E02AFBD7E94EB0FULL, 0xCFEBD199A1519D3FULL, 0x316266BDD4DDB3FFULL, 0x07442608574ED71EULL, 
            0x7E6B2905CB212965ULL, 0x725758EF240386E6ULL, 0x1B9D95B8FFC16A04ULL, 0x971C4E1EC1DE9994ULL, 
            0x4EAACE29F7A01603ULL, 0x5800415687754E13ULL, 0x85AD3224495BCC19ULL, 0x6982EA65B8C3D57CULL, 
            0xC5C3DF7F38611725ULL, 0x3EBD0B3F82238CCFULL, 0x3A54B67CA9BEF6D9ULL, 0xB3DFC38E94D17177ULL, 
            0x4C97720658CD81ACULL, 0x083980009FF7622BULL, 0xFD93A4BC3D9BEEC9ULL, 0xB47281E971AA160CULL, 
            0xA72BDEDD3B4EF0C5ULL, 0x83667D9E736B4479ULL, 0x2A555500324606CBULL, 0xDDBA484954856818ULL, 
            0x0BAD97FF71C70ABAULL, 0xD3EA717BD34C842DULL, 0x17D6AD4CF30F47A3ULL, 0xB0BDB9CBAC43C998ULL
        }
    },
    {
        {
            0x0DBC2C3A4E0A86FBULL, 0x8A5468F86468B068ULL, 0xFDAB182C9F293533ULL, 0x593505710DC8E256ULL, 
            0x9D1D9D90D40DA4D6ULL, 0xE0CEC53FB6B9561AULL, 0xD78F6FE68D6D8094ULL, 0x3B2FB4BD4D7C672EULL, 
            0xFBB7AC31A702465EULL, 0xDB15E83877986AF4ULL, 0x4D44C2652949F69DULL, 0xC76EF146EC6F9F2CULL, 
            0x5A490A035128A694ULL, 0x513D1FB8CA6408B9ULL, 0x0F00351E14A32887ULL, 0xA9AA18C8EE91D0BBULL, 
            0x4031A70EEEE7BA33ULL, 0x52369C17AF684782ULL, 0x2C075B46831DCF47ULL, 0x59E0335301B9867FULL, 
            0x34C1331501BA0199ULL, 0x7D39B839925DA14DULL, 0x8B542C7973DA708EULL, 0xF04DA642AC260449ULL, 
            0x46B022272E22F068ULL, 0x49CCD155BB99F1F5ULL, 0x69592664E0878B35ULL, 0xF33234115AD5E0BFULL, 
            0xAE9935C198FA9645ULL, 0xD7C2D95D3E45D9C6ULL, 0x7024B6B29AF4F86AULL, 0xB9441DDA7120A741ULL
        },
        {
            0x8B746EA529E203B7ULL, 0x0FB1BE1C2D868C09ULL, 0x6F2CBD2CAE84B07DULL, 0x3C54BF854F92E79FULL, 
            0x4068D533454989B8ULL, 0x6431D928C38D9EBFULL, 0x7AE166C445775B3FULL, 0x5B7CB7A7CC8D2C8FULL, 
            0x7CDA3DC8B65AF303ULL, 0x02AF7D28ADFA9C95ULL, 0x90D4565237F05EB1ULL, 0x338462441E2A7D34ULL, 
            0x89270A9150597B61ULL, 0xE04231F4D22CAF3DULL, 0x966D4C19A333904BULL, 0x4034563627DC9704ULL, 
            0x66EE00D74EE7E893ULL, 0xE18AEBCEFD83859DULL, 0x9201216DFE23B236ULL, 0x03538276595F47AAULL, 
            0xED2B7076ED4EDBFCULL, 0x9F836C3E9CEDA0F8ULL, 0xA9B21F7249C80E2FULL, 0xC9F0002A39EEA255ULL, 
            0x3A6094E43C937165ULL, 0x67BCB1725B0FE5E8ULL, 0x1B41F6D90ACBA712ULL, 0x962FD7D6F80D1B04ULL, 
            0xDC24CE3A85F50569ULL, 0x8F6D4E3827D12703ULL, 0xD6445D57AE1E75EDULL, 0xD0CC211D1095F1B2ULL
        },
        {
            0x115E0D9BBB21B32EULL, 0x3FA01E75FB49CE1EULL, 0x029C93C9CDCA6AEBULL, 0x443FD4591BE92E49ULL, 
            0x5CC738CC486E1391ULL, 0x42527BFAB9212D4DULL, 0x9991CEE54E112066ULL, 0xACFD7A9633298954ULL, 
            0xDB4AE0D9CEE4F1E0ULL, 0x2065CC30E3298FD0ULL, 0xB64314F98B252BA9ULL, 0xBD2EA9CEE289764FULL, 
            0x9C38A7900BAD5F46ULL, 0xB43DD1B008ECCAE8ULL, 0x5D46CC20C51E214FULL, 0xFE1DF61EC3FF6994ULL, 
            0xACE44AD2EAF97749ULL, 0x7BA0CEFADD536FB7ULL, 0xB65E4DA4B0D24548ULL, 0xA3491EC203622D25ULL, 
            0xF83213325AD47205ULL, 0x82864E6F7E93CC07ULL, 0x45E1E549D8C46EFEULL, 0x69DF9E615D7A624CULL, 
            0xEE08FF27CF89D247ULL, 0x3DF0121596FF61BEULL, 0x9DF312ECC2ABEE11ULL, 0x579FD71279120731ULL, 
            0x60D299601330EC1EULL, 0xC43592C78E4158BEULL, 0x1467A580C7E1EAF2ULL, 0xBCB8903E259BD404ULL
        },
        {
            0x17C34783BDFF7D0FULL, 0xBEB8223C48AD57B0ULL, 0x48FDD0FAEFE2E255ULL, 0x6B29FA1C903FD30CULL, 
            0x2E52FF7DC5385F01ULL, 0xB833C801C2638B23ULL, 0xBE209AFCD4FF6F6DULL, 0x2856E1AD3D9DFF94ULL, 
            0xAD1657FA5D588D9FULL, 0x3A308FC58C2E62A2ULL, 0x01BD5FA3042CA12CULL, 0xFD530101FD29F2CDULL, 
            0x0CEA91F8F148F89CULL, 0xBA8D2A261C956A56ULL, 0xA6EAB6DBA5FB31B2ULL, 0x8FDC10198E4EF4C4ULL, 
            0x48B3E374164170B8ULL, 0xB1B1D4854080B318ULL, 0x725D3B6098C20210ULL, 0x9BFDB6CE03819CA3ULL, 
            0x6104CA4A3CB59444ULL, 0x6D06ADF57FA8525AULL, 0xBBFECECC44D2497BULL, 0xE8F87B9992D27477ULL, 
            0xE29CA382EA48DDABULL, 0xF046838DA31C18D0ULL, 0x49A87847B33F7E1BULL, 0x6C570B5C86F5AD0DULL, 
            0x1167DD37AAD6C03CULL, 0x3AC75410FF5E44A2ULL, 0x5316A71AA5C45E31ULL, 0xDC7D55691AB36926ULL
        },
        {
            0x67A9F8A45BAECEF1ULL, 0x914059F2E03D9777ULL, 0x7A7063EE83FA498EULL, 0xB53E4E1F0CB9DAEEULL, 
            0x02F8FEC7A3209C67ULL, 0xA8DFA70553BD65D4ULL, 0x0314DB311C504E81ULL, 0x2FD8039AD73C47A9ULL, 
            0xA4A18DDD210B416CULL, 0xF34B162CE2AF7155ULL, 0x952316882A17173CULL, 0xEE61044B9BC42647ULL, 
            0x234F1B9A6F903809ULL, 0x4066BB5C2D0E3BD4ULL, 0x20AA67360B4EF53CULL, 0x296BB0B7E41DC54CULL, 
            0x9020265FA2B9D697ULL, 0x64D6156A36BB2A30ULL, 0xB77987ED392EA14DULL, 0x4BEAAF3FD41CCC79ULL, 
            0x2ACF1FDE880FBB29ULL, 0xC25EF4752A387197ULL, 0xE6A019F047F8B881ULL, 0x38CAE8CB96DACBEDULL, 
            0xB9EAE22D28C78B28ULL, 0xA830F86ECF15968FULL, 0x57EDA21DBEE964F8ULL, 0x5AA735817D67F696ULL, 
            0x152B8482344A085EULL, 0x3BFE08BD8C4C7103ULL, 0x7661D189A9414E6EULL, 0x855FBFF4D3DAF172ULL
        },
        {
            0xC8012FA552B810ADULL, 0xA2A49C175D93754EULL, 0x755AEEDF538C733BULL, 0x9BC1B74E8C631BBEULL, 
            0x5A96A67DD5AE1D55ULL, 0x6BB2E4A7CD066F88ULL, 0x5847BDF83255361CULL, 0x0F7DEEE32A561EBBULL, 
            0xA5123968BA850FC2ULL, 0x860E4FF5F66607AAULL, 0x3CD147A1AED15FF9ULL, 0x22D30B5C72F80D82ULL, 
            0x4A53CE576226AA69ULL, 0xCC41C3FD90924FCEULL, 0x5913390F859F0286ULL, 0x3F0C4A05E2BE1E24ULL, 
            0x2141A149F1862D94ULL, 0xF4CB678A808EC965ULL, 0x66F913BDACF7D5C7ULL, 0x94B6A817A3732A0BULL, 
            0x3D30784FAB0C9F06ULL, 0x36FB9BC1F44DD7E8ULL, 0xBB47705B7BADD28FULL, 0xA72F16CA22214955ULL, 
            0xB64AFD4A5267BC92ULL, 0x27932523878DE82AULL, 0xB78B0FE91F7A585DULL, 0x62CBEB6FF8E55FF0ULL, 
            0x4CDF7206D84DDC8EULL, 0xE1A8685997E55D0CULL, 0x8CF719A4F9F864BAULL, 0x2E60F5B34663527FULL
        }
    },
    {
        {
            0xA0CC229E99BD8EA9ULL, 0xAF34EF49C2917697ULL, 0x67A0CD97479E11B3ULL, 0x9041B69C40DA8212ULL, 
            0x8D6AB3D435BF4F28ULL, 0x3563F9FBAF42176DULL, 0xE94A5A4A0FC8F402ULL, 0x3046F4534470F5F3ULL, 
            0x6F30D7952A24887BULL, 0x9944ACA40B91205AULL, 0xCE4020DD1D393987ULL, 0x6F372F0EBA3D4E21ULL, 
            0x748BEB8180323506ULL, 0xAA80D25CDE694ACDULL, 0x66A0B633A0054F7CULL, 0xB9602EE61DFC1FB7ULL, 
            0x89ABC9A86874029DULL, 0x341C1C6715761008ULL, 0x2E5A1F5BD62584B9ULL, 0x86E2DA73EBF1DFA4ULL, 
            0x9492C9C77AA37648ULL, 0xE86B51E21C30E088ULL, 0x442C1D8606C53C2CULL, 0x7ADC815E84D29984ULL, 
            0x6D0FEC3BD20FD853ULL, 0x926FA06E82AE6E99ULL, 0x1B55946455B68577ULL, 0x248EEE92A44979DEULL, 
            0x6DE210AB29980237ULL, 0x9EC6F0AA53B98F9AULL, 0x6E41AB4FEFA799E7ULL, 0x3381B6E4C2D7D77CULL
        },
        {
            0xC11D461FAA218873ULL, 0xB0A0B7BF2DB51D16ULL, 0x36BDB0F7ABC0BE87ULL, 0xC19DE90BE836D05EULL, 
            0xFB2E60B938361F15ULL, 0xF2D852328254014EULL, 0xE2DBE3ED48EC2CD9ULL, 0x8BC498116C586F86ULL, 
            0x307E83D430B526DAULL, 0xEFDF464D18E9439EULL, 0x80A01B7403D19DD8ULL, 0x62EA84FC65294106ULL, 
            0x8D147C3AC780B802ULL, 0xF1B62D79F99BE5F6ULL, 0x46AC97CE9FE64017ULL, 0x100DEF45C55036A0ULL, 
            0xAC7B23C1179884DCULL, 0x0BF411FEF1E30943ULL, 0x9FD07C6E509858CBULL, 0x9E85B97D3517C7BAULL, 
            0x85E1AB24DA1B7774ULL, 0xCCAE863DE4C04205ULL, 0x62F64BE4527CBC13ULL, 0x4E88DD1A3166B437ULL, 
            0xA4F9A1422ABE2D33ULL, 0xEA52316F6E7B7322ULL, 0x18E0349DFFFC077BULL, 0xED976DF71198044BULL, 
            0x1326D6BBFDEB9073ULL, 0xE5F27F41CDFA51F3ULL, 0xA054ED8478C21891ULL, 0x77B9B52686F7E28FULL
        },
        {
            0x7BCEFC52939C8625ULL, 0xE852C02BE7A69776ULL, 0x91B3661095A2DAD3ULL, 0x5FB14022CB790305ULL, 
            0x834179523416527AULL, 0x6187E8E6420DBA69ULL, 0xE0F220E6E0C2EFF7ULL, 0x703164FD89CDDA4FULL, 
            0xF270A022AE0E7397ULL, 0x8887E65443E084D2ULL, 0xF42BA6D885EC7E92ULL, 0x4CF97CD77F5C7602ULL, 
            0xD82277D254EADA10ULL, 0x4307FFC5AB161AABULL, 0xC47CDC640EACEED2ULL, 0x8E2B797E4C0256A5ULL, 
            0xC28F322A476C276DULL, 0xD50877C63600F4E5ULL, 0xDFD39963D5F90264ULL, 0x1F497609267CC39FULL, 
            0x7E5157EA8131DF41ULL, 0x2018DAB8CAE410C8ULL, 0xCC13D222B2FCDC03ULL, 0xB723F8CF9F461430ULL, 
            0x7ED2C94EAAB69117ULL, 0x31C0EC41D15C98D9ULL, 0x0B48719BEAA01E16ULL, 0x56DC28BF003066A9ULL, 
            0x5C8F5509B6299F45ULL, 0x0F689954107ADF8FULL, 0x7CD17CE86F3D3532ULL, 0xD169BDCABDA5FFADULL
        },
        {
            0xD1CE42A9106AEB68ULL, 0x96581F241C2A2959ULL, 0xD98D2F797A7BF597ULL, 0xEE57D4762366DB31ULL, 
            0x672A9DE2AC7EB561ULL, 0xD255AF475037A944ULL, 0x5061C13E39E12EF9ULL, 0xABF374B66F0DF2B2ULL, 
            0x48C5D6905503C162ULL, 0x7126726F2A99CC56ULL, 0xB84EBCF94BE5D477ULL, 0x653543DA77E31542ULL, 
            0x7D15ABFA63B634BAULL, 0x8D5E7E67263C3D70ULL, 0x82CC654EDF3F1FC6ULL, 0x0CC76ABEF3717626ULL, 
            0x8E51925FCED20ED7ULL, 0xA8FC181E8625C6F7ULL, 0xC2ECD8D138DB43CDULL, 0x67D386CC2857FE89ULL, 
            0x3001E3A275D1644BULL, 0x3D1AEE59F0AF53BFULL, 0xF87B90F2CE82175EULL, 0xB94BEFCB6F0A5838ULL, 
            0x2D3CD1E44C1FAF2FULL, 0x9F4D092F5856B73CULL, 0xB3B714704C11478CULL, 0x9BFBFB807CDC4E11ULL, 
            0x4BA85D8A49FA6515ULL, 0x20D67E4E43ACBE8BULL, 0xD33EDC93D73A2C2EULL, 0x85CBD12ED880CB31ULL
        },
        {
            0x75B2A394573B7687ULL, 0x92455CD9C8537EB5ULL, 0x761C083F7C2FEEDBULL, 0x2B8DEEEF0D0237E3ULL, 
            0x97FEA5BF77C31A74ULL, 0x70A38964F315255BULL, 0x31C325F6054B15A3ULL, 0xFA6DC8F2D1184566ULL, 
            0xF8A6E24DA0F5F496ULL, 0xFC849896F1F9AEA9ULL, 0xFA71DB322E43ACF4ULL, 0xD7D430E90F80CB7DULL, 
            0xA1539B6F170BC996ULL, 0x30AC592AA625E71DULL, 0x12C00764F4550F42ULL, 0x96B08EFBEA9B670BULL, 
            0x8BF5E006143340E2ULL, 0x9200EC351AFFC04BULL, 0x795C5D5FF46229A9ULL, 0xAD0CC43CA2C7D898ULL, 
            0xEA3CF25E9921F82AULL, 0x20BB05B759B736F8ULL, 0x56BA501324355302ULL, 0xC4884BF560F89C36ULL, 
            0xBED889A70D8F9011ULL, 0x7D46AD9ED5421E7DULL, 0xCAFB36C77A104AD1ULL, 0xF29F9E9D82AD667AULL, 
            0x58B9BFCB23AFBD74ULL, 0x9D6885E3B08731E2ULL, 0xC13F391E2F5B9584ULL, 0x84F8F00FF8DD5C1AULL
        },
        {
            0x2444AE6D23359722ULL, 0x1BB76F533FBFBAE8ULL, 0x1DC8F7B5B724C935ULL, 0x49DA4A0A7C0EDFE5ULL, 
            0xA6976F537D559059ULL, 0xB93C7BA2339E491BULL, 0x4459C34F03B6FAD6ULL, 0x6C5CB044EAA76092ULL, 
            0xA9C2339E62F4F660ULL, 0x5D099A927C2060FEULL, 0x53CEC5F7AD4B12B7ULL, 0x0BF7F5EF1C26971DULL, 
            0x00A1762A47D81DACULL, 0x8ECB13C9949B472EULL, 0x50B62FDBE8C1D6CDULL, 0x78381A3CABE1BDDEULL, 
            0x6A067098F077DAFDULL, 0x5F098D5DA76DF91EULL, 0xC898C56AD14A28FEULL, 0xDBC41E2DB7DC65E2ULL, 
            0xC55C7FC46C5956B3ULL, 0xD6217CFC56F57C72ULL, 0x8E6009E7F157EF0CULL, 0x2D3104343D94EBD1ULL, 
            0x99DA70404D45EDE0ULL, 0x9F1C635CAC8910F2ULL, 0x011E5135682E597EULL, 0x5947706E305B450CULL, 
            0xB6074262DEB094DCULL, 0x8BBF95ED647F8999ULL, 0xD689B50F9E8813A7ULL, 0x3B5C504AB7281C32ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bellatrix::kTwistConstants = {
    0xB6E96FC8ED060243ULL,
    0xE45476D2BEBBE25DULL,
    0xF3B5AB262F7D0C2FULL,
    0xB6E96FC8ED060243ULL,
    0xE45476D2BEBBE25DULL,
    0xF3B5AB262F7D0C2FULL,
    0x645DD11B2AC5580DULL,
    0xF669C1A925035F42ULL,
    0xD3,
    0x78,
    0xC4,
    0xE2,
    0x93,
    0x6F,
    0x78,
    0x4F
};

