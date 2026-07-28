#include "TwistExpander_Gemma.hpp"
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

TwistExpander_Gemma::TwistExpander_Gemma()
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

void TwistExpander_Gemma::KDF_A(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Gemma_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Gemma_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Gemma_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Gemma_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Gemma::KDF_B(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Gemma_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Gemma_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Gemma_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Gemma_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Gemma::KDF_C(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Gemma_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Gemma_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Gemma_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Gemma_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Gemma::KDF_D(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Gemma_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Gemma_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Gemma_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Gemma_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Gemma::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x8A0303DD4D48F0ACULL;
    std::uint64_t aIngress = 0xA787D2783CD09303ULL;
    std::uint64_t aCarry = 0xE2A3CE309C96BCD0ULL;

    std::uint64_t aWandererA = 0xE058A1FB818FD406ULL;
    std::uint64_t aWandererB = 0xB0EF7640127CB88EULL;
    std::uint64_t aWandererC = 0xC183BF7A840237C6ULL;
    std::uint64_t aWandererD = 0x96BA105932B9ADB0ULL;
    std::uint64_t aWandererE = 0xB5D232747361753AULL;
    std::uint64_t aWandererF = 0xF90087B1E4577BB9ULL;
    std::uint64_t aWandererG = 0xC3D0AD22C707134FULL;
    std::uint64_t aWandererH = 0xDD04F594B34E7595ULL;
    std::uint64_t aWandererI = 0xF29AAE04EB6B1760ULL;
    std::uint64_t aWandererJ = 0xE258FCF937963C17ULL;
    std::uint64_t aWandererK = 0xCCC002E752CB7B40ULL;

    //
    // KeyRotate A
    //
    aPrevious = 0xEB7F3FEF0404D7DDULL;
    aIngress = 0xE88ACE22C1584147ULL;
    aCarry = 0x940661E9DC368AB9ULL;
    aWandererA = 0xD3DE7B1B42F7D008ULL;
    aWandererB = 0xFA5904AAC5302A90ULL;
    aWandererC = 0xB272CF58EBC20B4FULL;
    aWandererD = 0x928293C2D2D00F35ULL;
    aWandererE = 0xB2913463967A3F0DULL;
    aWandererF = 0xA7C0AA3C3E3E14D6ULL;
    aWandererG = 0xB7B9EF22D53B0861ULL;
    aWandererH = 0xAE12B796BDBEF10CULL;
    aWandererI = 0xCEA738B6B86AE404ULL;
    aWandererJ = 0x996FE25E063D669AULL;
    aWandererK = 0xDF016C8B6F05A67DULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateAConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneB, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xF719063E28BE116FULL;
    aIngress = 0xF22ACE84173AA6D3ULL;
    aCarry = 0xBC6CE8F1A89F54B0ULL;
    aWandererA = 0xA1FC1078E076BC86ULL;
    aWandererB = 0x9E35A469C227B91FULL;
    aWandererC = 0x81488A71FBFC56ACULL;
    aWandererD = 0x920C0CE855BBA9D1ULL;
    aWandererE = 0xAF71616CD22755FCULL;
    aWandererF = 0xB3AE1DC996A4548DULL;
    aWandererG = 0x9F907D0EECA03B8AULL;
    aWandererH = 0xEF59B92BB281A97BULL;
    aWandererI = 0xAA5CC21EA634188CULL;
    aWandererJ = 0xB2B2FFBF815F674CULL;
    aWandererK = 0xFA806D78F05FB9B0ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xA3ED06CAC01FC23BULL;
    aIngress = 0x9ACBFABE2458A6E6ULL;
    aCarry = 0x8A27AB6DAA925CF0ULL;
    aWandererA = 0xCE6A82E49FB1B357ULL;
    aWandererB = 0x862267980C076527ULL;
    aWandererC = 0x8B81DD23E3CD35F7ULL;
    aWandererD = 0xF4880C44243D7066ULL;
    aWandererE = 0xB788771EDEF4CE40ULL;
    aWandererF = 0xF0754C9E9EF66FBCULL;
    aWandererG = 0x97E5F6A0CC2B7154ULL;
    aWandererH = 0xC6DFC10895ECB80BULL;
    aWandererI = 0x9BCE87384D6DBF19ULL;
    aWandererJ = 0x8FD0A859C845F5CEULL;
    aWandererK = 0xB8F9A0DF4E31A17CULL;
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0x8C73BE662D71FCCAULL;
    aIngress = 0xE0F2FFD6F24DDFFBULL;
    aCarry = 0xF828B24A1B081A07ULL;
    aWandererA = 0x921B548A896FA04AULL;
    aWandererB = 0x92E7EFDD9FCB11AEULL;
    aWandererC = 0x8E8E289FA0904FC3ULL;
    aWandererD = 0x9F9CF7AF402CA731ULL;
    aWandererE = 0xDFD85780104D6457ULL;
    aWandererF = 0xDD93E59B49096E05ULL;
    aWandererG = 0xC39322C4687A3A39ULL;
    aWandererH = 0x8548361A6DB1DCF4ULL;
    aWandererI = 0xBD6FC52B4791CDD1ULL;
    aWandererJ = 0xFF2E5EAEEC6CA42CULL;
    aWandererK = 0x81755D2CEF2DD63CULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnBConstants), &(mDomainBundleInbuilt.mKeySpawnBSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants), &(pWorkSpace->mDomainBundle.mKeySpawnBSalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0x907FFE60F4FAFD5FULL;
    aIngress = 0xCD1818507C38E9F2ULL;
    aCarry = 0xCDE574D39F9D7FA8ULL;
    aWandererA = 0xB67F6E625AD58F31ULL;
    aWandererB = 0x989EAE6CEA1AAB1BULL;
    aWandererC = 0xA4CAF5E167C2999DULL;
    aWandererD = 0xFDE1AEE8EDC04700ULL;
    aWandererE = 0xA19BDB632F88AEB5ULL;
    aWandererF = 0xE2B700E1038BC0C8ULL;
    aWandererG = 0x98E96A8B819EA70EULL;
    aWandererH = 0xA85E30ECA857FF31ULL;
    aWandererI = 0xF156FA5F1EA7381EULL;
    aWandererJ = 0xCD3352A3987D5F75ULL;
    aWandererK = 0x9429E3DB8FA12633ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mTwistConstants), &(pWorkSpace->mDomainBundle.mTwistSalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xD842F079EEB676FDULL;
    aIngress = 0x82134CE684F4A310ULL;
    aCarry = 0x971F61709FBA89A8ULL;
    aWandererA = 0xE99E161A424259ABULL;
    aWandererB = 0xF33D2AC9EB8C90F0ULL;
    aWandererC = 0xB8E8D7FBF9995879ULL;
    aWandererD = 0x9DF62CD42CB47B69ULL;
    aWandererE = 0xC32D2533046DD7CAULL;
    aWandererF = 0x853B09F401A81270ULL;
    aWandererG = 0xC4C6D5223AEFFBA5ULL;
    aWandererH = 0x9036F56FB45B696FULL;
    aWandererI = 0xECD2CE4319900487ULL;
    aWandererJ = 0xD46CB78C105CC0A3ULL;
    aWandererK = 0xDC77D037641DAD2DULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mSeedConstants), &(pWorkSpace->mDomainBundle.mSeedSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mSeedSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xD3A5F6EC58C4C3C0ULL;
    aIngress = 0xF39812243DF984F2ULL;
    aCarry = 0xAB24AB2E87F30391ULL;
    aWandererA = 0xCAE20073F2BA4814ULL;
    aWandererB = 0xF776409CAFBC4F9DULL;
    aWandererC = 0xD1A630CA49366917ULL;
    aWandererD = 0xF8ACCA82489ECAF2ULL;
    aWandererE = 0x9462B703F701A0A9ULL;
    aWandererF = 0x92837E801AFA04F6ULL;
    aWandererG = 0xA690C3D952700CCEULL;
    aWandererH = 0x96B535616B2A8652ULL;
    aWandererI = 0xA3B01B75F41A17C4ULL;
    aWandererJ = 0xE212BD907A69FC08ULL;
    aWandererK = 0xB53F42A072FC5C2BULL;
    //
    TwistExpander_Gemma_Arx::SEED_A(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Gemma_Arx::SEED_B(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Gemma_Arx::SEED_C(pWorkSpace,
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
    TwistExpander_Gemma_Arx::SEED_D(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Gemma_Arx::SEED_E(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Gemma_Arx::SEED_F(pWorkSpace,
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
    TwistExpander_Gemma_Arx::SEED_G(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Gemma_Arx::SEED_H(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Gemma_Arx::SEED_I(pWorkSpace,
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
    TwistExpander_Gemma_Arx::SEED_J(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Gemma_Arx::SEED_K(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Gemma_Arx::SEED_L(pWorkSpace,
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
    TwistExpander_Gemma_Arx::SEED_M(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Gemma_Arx::SEED_N(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Gemma_Arx::KEY_A_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Gemma_Arx::KEY_A_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Gemma_Arx::KEY_A_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Gemma_Arx::KEY_A_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Gemma_Arx::KEY_A_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Gemma_Arx::KEY_A_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Gemma_Arx::KEY_A_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Gemma_Arx::KEY_A_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Gemma_Arx::KEY_B_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Gemma_Arx::KEY_B_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Gemma_Arx::KEY_B_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Gemma_Arx::KEY_B_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Gemma_Arx::KEY_B_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Gemma_Arx::KEY_B_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Gemma_Arx::KEY_B_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Gemma_Arx::KEY_B_H(pWorkSpace,
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

void TwistExpander_Gemma::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xDB1A0EF7A04BCAB6ULL; std::uint64_t aIngress = 0x8E6D66DC66929D1BULL; std::uint64_t aCarry = 0x8D859647FCD15A90ULL;

    std::uint64_t aWandererA = 0xAEDC1168A02E5886ULL; std::uint64_t aWandererB = 0x956CD4AFB7BCC85EULL; std::uint64_t aWandererC = 0xA9C0337EEA6154CEULL; std::uint64_t aWandererD = 0x8DF1F2538605AB60ULL;
    std::uint64_t aWandererE = 0xE7D5B1A4178B809AULL; std::uint64_t aWandererF = 0xBBF2A5C0E748ADC8ULL; std::uint64_t aWandererG = 0xD812AF235027F8ECULL; std::uint64_t aWandererH = 0x9783287DDA52B376ULL;
    std::uint64_t aWandererI = 0xA95839FB224EFFD3ULL; std::uint64_t aWandererJ = 0x9C6A38D63F93DCD2ULL; std::uint64_t aWandererK = 0x80033CBF45FD41A8ULL;

    // [twist]
        aPrevious = 0xAE27B25D0F7DC6FEULL;
        aCarry = 0xEC678BD65E4FEFEFULL;
        aWandererA = 0xB2C2ED86F9F6EDEBULL;
        aWandererB = 0xD222539D15D118C2ULL;
        aWandererC = 0xDD607561B7D19A6BULL;
        aWandererD = 0xDB6D657E0805B538ULL;
        aWandererE = 0x87ACDDA4C0E61F12ULL;
        aWandererF = 0xE38549E099DEE1B9ULL;
        aWandererG = 0xBFEB12832967B93AULL;
        aWandererH = 0x8BCFDB8B30C32FD6ULL;
        aWandererI = 0x8640D836C0217A0FULL;
        aWandererJ = 0xA94C855D52D8D0D4ULL;
        aWandererK = 0xA0A899757FBD2EBEULL;
    TwistExpander_Gemma_Arx::TWIST_A(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Gemma_Arx::TWIST_B(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Gemma_Arx::TWIST_C(pWorkSpace,
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
    TwistExpander_Gemma_Arx::TWIST_D(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Gemma_Arx::TWIST_E(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Gemma_Arx::TWIST_F(pWorkSpace,
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
    TwistExpander_Gemma_Arx::TWIST_G(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Gemma_Arx::TWIST_H(pWorkSpace,
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

void TwistExpander_Gemma::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Gemma_Arx::GROW_A_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Gemma_Arx::GROW_A_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Gemma_Arx::GROW_A_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Gemma_Arx::GROW_A_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Gemma::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Gemma_Arx::GROW_B_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Gemma_Arx::GROW_B_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Gemma_Arx::GROW_B_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Gemma_Arx::GROW_B_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Gemma::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 28 of 33
    // Exploration cases: 0
    // Structural maximin 511 / 674; family total 14376
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
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7879U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7969U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3738U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3558U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1375U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1465U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1735U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1600U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1825U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 92U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1420U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 2005U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 28 of 33
    // Exploration cases: 0
    // Structural maximin 511 / 674; family total 14451
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
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2928U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7069U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3108U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3468U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 745U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 925U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 610U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
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
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 790U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1105U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1285U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 565U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1240U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Gemma::kKeyRotateASalts = {
    {
        {
            0x1CE74ADD2972B885ULL, 0x502D013D7EEF1095ULL, 0x8DC4F9E3EB200191ULL, 0x8D6A6151F404FD9FULL, 
            0x0B961C3F25F3394CULL, 0x68C109F3E3859EBDULL, 0xEEB1EC0AFC230C06ULL, 0x24B9324C2472643CULL, 
            0x2175C6FFEF6A8C26ULL, 0x14836697344A74B8ULL, 0x33C15DDD5A4F94AAULL, 0x38FD9ED81120788AULL, 
            0x5A6CBFC25A68853FULL, 0xD788445700A4B5D2ULL, 0x7B435C78A73AEFEBULL, 0xC248C84438230D1DULL, 
            0x24FE379A2617E5B1ULL, 0x1F29A15964473440ULL, 0xA67F675E58E5327DULL, 0x6226B52508CFD39DULL, 
            0xEB6F45065D452B9CULL, 0x84135443B6502BA0ULL, 0x5B0B27F928914455ULL, 0x357AD735938B7DD0ULL, 
            0xD80F0324F06EB4CFULL, 0xEEB8217BD1C42EA5ULL, 0x84FF970FE9B92F6FULL, 0x35CD49DD849B2738ULL, 
            0xE9207B2FEB8EF2EEULL, 0xA370AF1F8DB9E21DULL, 0x3CD0047C8FF54E83ULL, 0x2D8CE2FFBA1BED90ULL
        },
        {
            0xB356878B3D8A28EEULL, 0xB117BB1D65B3C50FULL, 0xC7B013ABD96A5316ULL, 0xA391E483073CF134ULL, 
            0xF6BF9805F9E671F2ULL, 0xA09B2EEE111460CEULL, 0xCD92CA3C64FA6001ULL, 0x887BE95A738E8EDBULL, 
            0x2964261AC7E3C409ULL, 0xFEA33815DE00BA76ULL, 0x92BD1902D5CCBAF1ULL, 0x1B824ABAACE20936ULL, 
            0x002445DF96D77A9AULL, 0xE8CE3B76B5556202ULL, 0x38A568A74FE7CB80ULL, 0x7081D646702FDE1FULL, 
            0xFE6F624009F3136AULL, 0xA73705C51C1A8CBEULL, 0x2881D46D32D82180ULL, 0x9471E45E0603BFB8ULL, 
            0x7B9E96573AE9338BULL, 0x78F6918CFDB39D6FULL, 0xFCD51489FBCE3D37ULL, 0x6892EE27B250FC3EULL, 
            0x4DBB6CBE38BC3415ULL, 0xC61A9A0E42C3D622ULL, 0xB3DA0B5C0AC04A9BULL, 0xBC2ED8D9E04D08B1ULL, 
            0x2EBBEAD1E3AF1D22ULL, 0x361A264350F65839ULL, 0xE2DFAF9F99EEF704ULL, 0xA20686E9306F357EULL
        },
        {
            0x422FA209F434F4E3ULL, 0x9266106CB4B88C38ULL, 0x21B1643C093069FCULL, 0x36DCFDDE5C991B2CULL, 
            0xFAF53DA40F101A3FULL, 0xFC7D9EFE0AA35D5CULL, 0x93ED1B6731032486ULL, 0xFBEFB0138AB87DDCULL, 
            0x42CE981AD559D99EULL, 0xAC6F1058805235D7ULL, 0xB0DC96046328CC4DULL, 0x6AD0785FA0880FC7ULL, 
            0x456F5E4FF73C9AC4ULL, 0x989CBAE37723C36BULL, 0xCB7F211EC908E591ULL, 0x83F2F26FDE2334A6ULL, 
            0x4C14A63ABF418B98ULL, 0x85E3681D2CD7D7A7ULL, 0x72E1AB941B5AA94EULL, 0xBAE0455B6EEF2B05ULL, 
            0xB8C9A9D087F14330ULL, 0xC331BC32A955D148ULL, 0x72F065D99F9AD34BULL, 0x0E13DB1A4BF47FB7ULL, 
            0x401C64E6553A6C33ULL, 0xECD0E378798D0D8CULL, 0x8561D51C7CFEAC57ULL, 0x353191A08EE76B36ULL, 
            0x043B2825B8926F66ULL, 0x174B73F16934DD25ULL, 0x0C73CDEF527DC964ULL, 0x7313ECF438898E61ULL
        },
        {
            0x703B0500C543CA0FULL, 0xB91F35B29683DDA2ULL, 0x009CA62ECD6D27AEULL, 0x7612E35DC673D7D6ULL, 
            0x2C9633C8015A883EULL, 0x62E959A124E779DDULL, 0x583105FDB0007744ULL, 0x89667418C209BC24ULL, 
            0xAC98FFDF583C37DAULL, 0xF8C31D360B2B3664ULL, 0xA19844825F536A2FULL, 0xA1C415200D00B501ULL, 
            0x764E32F60986A727ULL, 0x680DCE4D81F89F90ULL, 0xF98BC4854D3A0DE3ULL, 0x4707534EB6F70896ULL, 
            0x6BBD1BE84137D378ULL, 0x2524E0CF8B5E48DFULL, 0xC69296B1E89EA816ULL, 0x95720286078BDD3EULL, 
            0x6F42D3F4090B7752ULL, 0x9F2C328BD8D211B8ULL, 0x000C9B3A8B32FAC2ULL, 0xD38D58C547FC3DBEULL, 
            0xE9FBA324AABF6C59ULL, 0x4FC51F2178C79DACULL, 0xFD24BF3EDCAF9B53ULL, 0x82AD2BD7F5BDBB82ULL, 
            0x3EDD32F4BAF2EEF5ULL, 0x1AB324AC58A52589ULL, 0x241AD55748D43FC6ULL, 0x800AEFA1B532B052ULL
        },
        {
            0x4A026F29D0D9F8FEULL, 0x475723BB1010F9CDULL, 0x642088D0EBF86CA8ULL, 0x4EC6250AF3388369ULL, 
            0xD44408008BED6C00ULL, 0x602AD075EAF0BE78ULL, 0x663490171C737748ULL, 0x18072B474C52327CULL, 
            0x28672DFD43BC035FULL, 0x1C97A1D9AFF99BFEULL, 0x0325C63D9E882A17ULL, 0x78AEEF7F6F264D85ULL, 
            0x644231E70CC448BEULL, 0xAAF170A4E6456229ULL, 0x1D86FAFE1A54A5EFULL, 0x90A4A2555F6BDD6DULL, 
            0x3853D5F1610F987FULL, 0x4739E480365E9AC7ULL, 0xF59EB89BC57CC286ULL, 0xEB36EB2DA9E03585ULL, 
            0xC46D635B0670A221ULL, 0xC6D63B86BEAB5D4CULL, 0x17F447A1B5967E00ULL, 0xAC2F1A79D97404ACULL, 
            0x5C462F288CBDCC03ULL, 0xD5B08BB66F5CE374ULL, 0x9F2D98CA32D67284ULL, 0x72F51E64F46DB7FFULL, 
            0x846C4C8DC39EE093ULL, 0x97300F01879B84A6ULL, 0x11C771EB299A85A1ULL, 0x97A09F038715193CULL
        },
        {
            0x4792254305E2C220ULL, 0x84C02DC22D71DAF6ULL, 0x27B7E79393378421ULL, 0x0CBEFD0CA8A6661BULL, 
            0xCD0652B12BA42F64ULL, 0x02C160B8CAA0FBF2ULL, 0xA6C7E85A5CB88802ULL, 0x73F0EC9B55734EEAULL, 
            0x2CF94677137201D9ULL, 0x40A3A19787611386ULL, 0x834B3E0C0F827E4BULL, 0x1D5B37895145FECCULL, 
            0x98F247B92016D809ULL, 0x8F717018F4B156BAULL, 0x2457A45340DE66FEULL, 0x77C7147A7F1C0E4CULL, 
            0xC99C3B9A3093B798ULL, 0xF8D379B4112F9E94ULL, 0x71AFD0408F8AFFC9ULL, 0x2B9A9BC77E589D7EULL, 
            0x734BFA1DC9469699ULL, 0xC3535E8D7A5FC14EULL, 0xC2977AF6EABDAD0CULL, 0x0E9E4C3AF1819A8BULL, 
            0x5BA977E373EB633AULL, 0xE53FA28F0D540BFDULL, 0x284723BC52266A81ULL, 0xC7CBB850F28612F4ULL, 
            0xC871CB87F0A2A04BULL, 0x2D51ACCF4C5F555FULL, 0x161474DBE3E8CD73ULL, 0xF74A0DADC5ACCE15ULL
        }
    },
    {
        {
            0x75C4249875A6DB45ULL, 0xFA4DFB25848FA849ULL, 0x0B37330B4302F6AEULL, 0xB8897D16BC1E770CULL, 
            0x190402AD0861F441ULL, 0x12D4D44D83A3F543ULL, 0xF9EDDC218BC4B1EBULL, 0x8877A4F3E6B41B2AULL, 
            0x0123E11F3F9A9513ULL, 0x86C93F13847894D0ULL, 0xAE22FCE67E5494C2ULL, 0x144F4DF4FA869915ULL, 
            0x4F7C03AD614EF9AFULL, 0xB6E1F29637F70FAFULL, 0x95AAB73A6D3EF79FULL, 0x066D0C2010A8BFACULL, 
            0x6863FCE496F9A994ULL, 0xF177796A110FD012ULL, 0x10D9E33476F9CB04ULL, 0x359CA1DD925DA709ULL, 
            0x52D2B06AD4AB9D58ULL, 0x76079984388E412BULL, 0x2491DB65612386B1ULL, 0x5FD9D3ADCAB0817AULL, 
            0xE9884956362CB8F9ULL, 0x667EA7853539BD2DULL, 0x9845EA2E36E82244ULL, 0xB9D3F63EFC52C178ULL, 
            0xCB005E85AA26BD9EULL, 0x6445DDDC53617CACULL, 0xD583973E6A548607ULL, 0xFC2040B54A4F9734ULL
        },
        {
            0x1310125678256043ULL, 0x5BBC1F2C6EFDAFC0ULL, 0xB0D92FFB3BCCCB1BULL, 0x2C9BC8C953C0438CULL, 
            0xA2E63DE76FF946D9ULL, 0x2A6F00D5B0448DF8ULL, 0x1EAE2D74EE641E6DULL, 0xCFED4CCB87C252AAULL, 
            0xD7B4279424C3AF5BULL, 0x506F30AA3AE76470ULL, 0x3DDCFC63F74C2BAFULL, 0xA84964F0DE80345DULL, 
            0xBCF678E6CF57756CULL, 0xC25B4E1A8BE6DE5AULL, 0xDD9C4717DE7CA27FULL, 0xA0C759F10A04E417ULL, 
            0x6B2ED138FB320EE4ULL, 0xAC318E29D661CC5AULL, 0x76777E2B9DFBC2E5ULL, 0xF2F78AE64287F0CFULL, 
            0x9A8EDC97FEC30610ULL, 0x01CE0F4B7A4A3C18ULL, 0xF60DF079C8295BBDULL, 0xBA16006295599E22ULL, 
            0x53761498C34AED17ULL, 0x9E8D316FEAF97D7FULL, 0x9F237F1A63438C83ULL, 0x320BCE70E981149CULL, 
            0x274060408FA032B8ULL, 0xBFFC59D2BC904D37ULL, 0x9F799B7D4E075DD6ULL, 0x5E275D0FEBEEB600ULL
        },
        {
            0x8E75CF606B30A3BEULL, 0x78E2BCAD187E45A6ULL, 0xEF1EAB79E4C3AA20ULL, 0x6A5767CF3129561BULL, 
            0xD1C5811F125B403EULL, 0xD5E7E6A69ABE5370ULL, 0x71B38586704F5D6AULL, 0xFA1A7642165C8F5FULL, 
            0x2E1EC318F2641CD7ULL, 0xE12970F0EA780EF8ULL, 0x706C10978BF37AE8ULL, 0xE79673AEFFFFA4BEULL, 
            0xAD8CEAE2D5CBFFC8ULL, 0xB3AD407A6E5BF197ULL, 0x41FA084A642FCE81ULL, 0x4E05856FA8699E7DULL, 
            0x005366DF53AAC728ULL, 0x15B5CE8445724A2CULL, 0x43CD67F76A0DF42EULL, 0x80E1EDEAE03DA404ULL, 
            0xACD8163B827B3624ULL, 0x82BD5D049CF9BF0BULL, 0x11FE8AE19A63E71EULL, 0x67EC1E217706E8F4ULL, 
            0x334FF2618D1BCB2EULL, 0x91C01B142D2F2955ULL, 0x990D0F3E34E25BEAULL, 0x65EE60D1F2E62A6DULL, 
            0xC855E60F59FC323DULL, 0xA2DF42DB10DA7D1DULL, 0x5988823B710E52AAULL, 0x89EC63A89B443968ULL
        },
        {
            0x560831DA40C7A12CULL, 0x0619DF0A9CFD7D95ULL, 0x85E38B3403CF0CC6ULL, 0x06479048C10793D0ULL, 
            0x996ADD1814DB8360ULL, 0x6AACB4E984C3E316ULL, 0x571F894BDC8EF6EBULL, 0xBFC445DCA6296984ULL, 
            0xB43A805A585FD8B7ULL, 0x34B711DA5FF40B0BULL, 0x835569EE2F5BED0BULL, 0x1C92E9B9A34141B5ULL, 
            0x854B954AA6B785BBULL, 0x0B671B8EBD42CED9ULL, 0xD2C2722C6C61C0CFULL, 0xAC021F0A8D8B35ACULL, 
            0x2FE0D5EBC94893ECULL, 0x4CD9632A80516459ULL, 0x7C1A6736B1D54821ULL, 0x1C441F085739E029ULL, 
            0x9CED5FE669AB7371ULL, 0x6CA95B7186892F1FULL, 0xB1870B0B74A7C3DAULL, 0xBC7CEE80651D7A2FULL, 
            0x6D71820EDCF273E1ULL, 0x7631FFB550C40DE4ULL, 0x2AD8385CB5F741C5ULL, 0xF38A3051DD541D9CULL, 
            0x3FC513A3B22E1C5BULL, 0x2110B4E377AC491AULL, 0x5A46D49E53755B65ULL, 0x1FB1646E43795294ULL
        },
        {
            0x55CBD639E8CD8F28ULL, 0x9401096725EF59E2ULL, 0x908558FFBB708455ULL, 0x8DE31D8D84A4349DULL, 
            0x196799A8CC3B5EA7ULL, 0xAA56E3FB75940B7AULL, 0x33F32070E54BE2C9ULL, 0xC3DFA899365F1633ULL, 
            0xC4BEAFDC3CC748E8ULL, 0x5C0BF3F765E5A225ULL, 0x1E50190014BDCDFFULL, 0xEDCB3BD73DBD396AULL, 
            0x930EC2BD67A2F101ULL, 0xF743B128D649F050ULL, 0x79DE11ED35872D72ULL, 0x72D546F449477F23ULL, 
            0xD01D7A0D249B78DFULL, 0x6FA801D2D862CFFCULL, 0xB3B3EA9699A0D193ULL, 0xBBB0AA1CFC145064ULL, 
            0x9FB4744F6DC8B7E5ULL, 0xB5230F4D39DEA6CFULL, 0xCF6EC291FB39ED01ULL, 0xA513992A3975D3A1ULL, 
            0x37379938440DA004ULL, 0x54F2E7F941E62D31ULL, 0xF379758D04DF2FD2ULL, 0x9E4B58FA3864FF8AULL, 
            0x150B0828C0ADDD19ULL, 0x264371AD75193BDAULL, 0xD28DD05C26C98177ULL, 0xACE37BCDD00DED2EULL
        },
        {
            0x972D2271BFE0A05AULL, 0xEA2BFA70156EEA67ULL, 0xFDAB01B1DD84C750ULL, 0xC68E53D948EBC30EULL, 
            0xC75D2E489F9EA096ULL, 0x36524BD390031BA5ULL, 0xE5659ED2823C840EULL, 0x8220E1EF04751AEEULL, 
            0x6750B870BBA7E8F5ULL, 0x55DEAA8B75EBEC24ULL, 0x6D606AA5B3A60D15ULL, 0x175DE81D048DE806ULL, 
            0x292D5F369441A60CULL, 0x11F2094903C703AAULL, 0x80BA97B96041608BULL, 0x28D7D034E50D9703ULL, 
            0x976B2BFDF491E3B7ULL, 0x1068B00FC708A814ULL, 0x3230A350C8325B45ULL, 0x0D0FFE719B98610CULL, 
            0x2C58FCAE437D3A09ULL, 0x53AC9A0D9048354AULL, 0x5C43774BE0E5FA5DULL, 0x0597930ADA0E5861ULL, 
            0xB949FFD7D4D76BBEULL, 0x2CF8EF3E1DBBEE27ULL, 0x8A0B76F3A379A04BULL, 0xCF77DC7748B2A15DULL, 
            0xBB695CD1A89B8F13ULL, 0xACB5593D4075C1BFULL, 0x26FAF02862B6E8C7ULL, 0xE8DAB12B7AED4560ULL
        }
    },
    {
        {
            0x28A33020ECB70C40ULL, 0x5CC3D6320DB3CEA7ULL, 0x83C15971C958043DULL, 0xE146EC30BC511F18ULL, 
            0xC71B7057F85B8786ULL, 0x9C9A67929EEDCCD9ULL, 0xAD7A57D9B3BF9857ULL, 0xC8C47FE407DE3A60ULL, 
            0xDB58805D96C47257ULL, 0x668C348D107B5DBBULL, 0x494547CEE92443D7ULL, 0xBBCF5CFA96D3F531ULL, 
            0xC9D39B2077E18500ULL, 0x7B3BEF7C42123FB0ULL, 0x86108DD3F1C0F3C2ULL, 0x43E66400E334717BULL, 
            0x07EF54361B9C44FBULL, 0xAD9681B7B4CEC29FULL, 0x635849664CC87BCFULL, 0x57659131576EB97AULL, 
            0xFAA3596894A41624ULL, 0xF559026B8E894EE8ULL, 0xF6C24A29FA74C11EULL, 0x1F61C76074B070FBULL, 
            0xF9627B0BF8CA2C9AULL, 0xE7848408AB0857AFULL, 0x5EF4169C14ED5C11ULL, 0xBD1AE13F5718F5EFULL, 
            0x7703112DF008CBB5ULL, 0xEE82E9AE0943391AULL, 0x3851918BBB6E64D1ULL, 0x66984D610733F108ULL
        },
        {
            0xC2EC88BF2BE97DA4ULL, 0x4C5C90550D6748E9ULL, 0xB9E10323AA293D52ULL, 0x91547CB50357DA51ULL, 
            0xB8A5C39FD1FF6911ULL, 0xC1AF7FC49C46FECDULL, 0x24C060A2C78694EDULL, 0xF15532AE3261760CULL, 
            0xDDCBC7A7097CA89FULL, 0x881FB18DF1A2C0ADULL, 0x91D918D86AFD1DF7ULL, 0x3AA627FAC884B3D1ULL, 
            0x629E9B23D7BB8E70ULL, 0x961DD9393082D553ULL, 0x5E36C7D2EEAFD392ULL, 0x6DFCD92CC4D863AFULL, 
            0x0E7298A74627F13BULL, 0x1408F7F892F3444AULL, 0x456EA7FC4AC1B029ULL, 0xAD9237D0120AF0D4ULL, 
            0xF6DD7E0911CD6C20ULL, 0x0D9472DEBF513533ULL, 0x88D3B2D82B190C32ULL, 0xBD3317D72C683691ULL, 
            0x6F98CAE1B2441ABAULL, 0x87A8D4631322B75FULL, 0xFE1AEC64B98C5B67ULL, 0xA397259D52F763CFULL, 
            0x64F8E57A4A50C61BULL, 0xE3D11B90172F232BULL, 0xE1384EA2E7338167ULL, 0x878169DD642F5E12ULL
        },
        {
            0x83D17D79CB2070D7ULL, 0xB0415E0E5B3D9998ULL, 0x57AA8B606A6CC07EULL, 0xB98F57C5366A2B0CULL, 
            0x50FD85EF8EBCC6C4ULL, 0xEAF8C7453714AF71ULL, 0x5E8DD8273BFB7E48ULL, 0xD757C770C0EED54BULL, 
            0xCB2E8D9D68D6AFF5ULL, 0x7A0F5BA4D8FA9494ULL, 0xF5DFCC6F87372316ULL, 0x8D912F342F529CAFULL, 
            0xDFE47DB0CB88D43DULL, 0xD3C7B63574F96D34ULL, 0xD5E8ECE3B5269939ULL, 0x67217934AAD24166ULL, 
            0xB5A65140EDFA3FE6ULL, 0x4F69954A4D0F7CADULL, 0x2C429FA0A5E1E5C2ULL, 0x3ABE9166C6C03D05ULL, 
            0xB47E0BF63EA045CAULL, 0xD899584B2660B6A5ULL, 0x83E2F89798CA85FCULL, 0x4E4CCE07F9AC3401ULL, 
            0xB1EE95EA4EAEA399ULL, 0x9F2E119D51FD48CAULL, 0x4D02F0C726BDFE32ULL, 0x676805B1B2C7EE41ULL, 
            0x9E8A86A87B7146C5ULL, 0x7DD320ACDBA9C523ULL, 0x43CFD10FDC3E285DULL, 0x665E16ADE72A361CULL
        },
        {
            0xE20340D9E31BDD4BULL, 0x23BB2B2AF87E8F04ULL, 0xFF169B6A8A5F433EULL, 0xE53826B8472D0B15ULL, 
            0x7E10555A382C3455ULL, 0xA1CA3870D30933C5ULL, 0x567A1E009A935BE5ULL, 0x55466EE22BEF40DFULL, 
            0x4F062A3A877D95B6ULL, 0x9B82C8273B1B387DULL, 0xE285735D2A8CD395ULL, 0xF2CBB73E71DF845AULL, 
            0xA0AD4A75CFA332D8ULL, 0xEC2E3F48C529DA71ULL, 0x2873B4B104E2705BULL, 0xED3CB33A45E8D2AAULL, 
            0xFD8B9B3B06AEDBB3ULL, 0xF740EDA728B21DBCULL, 0xAC7264FB00E70904ULL, 0x084D527B1356821EULL, 
            0x80EA02EA00CFB9F3ULL, 0xBBE77DE039A75E49ULL, 0x55EAC4BA0D950DE8ULL, 0xDDE32B77564B002DULL, 
            0xE509861EB5C7525CULL, 0x1733266DE6899B41ULL, 0xE2F408E730389172ULL, 0xFCB766F41BE2E3F3ULL, 
            0xC1FAE436BD03E972ULL, 0x62B66BA142D8B28AULL, 0x5D379A2727AD09EBULL, 0x4412C2BF1931B4E1ULL
        },
        {
            0x99E5A79546343C69ULL, 0x0FD9F3C9198209F4ULL, 0x9F6E2A715EA821EAULL, 0x05E01D9ABA8D19DCULL, 
            0x06B87E52D63C4392ULL, 0xC6D33939681FAD6AULL, 0x02ED4FF9B0ED03F8ULL, 0xBE52DE6B5BF3A1B2ULL, 
            0x3F7AACE093C35064ULL, 0x6DB307893D99A78BULL, 0x71576BBD6FB8B22AULL, 0x2660F3BD6AFAEAA5ULL, 
            0xE91E66E08799EA36ULL, 0x06AA4D5383BD2B0FULL, 0x9390721AE53AAC18ULL, 0x67B86E708C0A80CAULL, 
            0x1E251E98BB0C3EC0ULL, 0x347D715AE8CBFF0CULL, 0xEF9B773B41273F5EULL, 0xC0C6257FA5F4AFDEULL, 
            0xD71950040E8D690BULL, 0x2C55801B27D6F411ULL, 0x5B3EA584C2825862ULL, 0x6E8A3E5AE96010A0ULL, 
            0xB32AC4CE689C41A9ULL, 0x63DED999DF65D9F1ULL, 0xF1F1E9F425FE1FFBULL, 0xB734B51DE04D8903ULL, 
            0xEE9DA35C3B6DCD4BULL, 0x8603FE490D55E2B8ULL, 0xC5A0FD6D14D4733CULL, 0x0D04EFA7B01142E7ULL
        },
        {
            0xF1BFE0EC25B9858BULL, 0x818E6A6E80E74447ULL, 0x4332EF1AD18FF40FULL, 0xAEC7906168CF9A90ULL, 
            0x88E752B6BCCE3D88ULL, 0x367950E726846CBBULL, 0xAAAAFDA91AA257E6ULL, 0x65319582B5C5D539ULL, 
            0xE4550C077D75A587ULL, 0x2B2B1C419E99F7DFULL, 0xAFE7E1C901961A14ULL, 0x16BE1DC65F631054ULL, 
            0xCEF387F308BBA615ULL, 0x40CE887EB143954DULL, 0x31EB1BEB36E85ED9ULL, 0x493FD01BEE0AFCE0ULL, 
            0x4E6021CED1B961FEULL, 0xFD2EF1C84CDA89E4ULL, 0xA08D8C28AE46D940ULL, 0x53D287CE8C2E72ADULL, 
            0x556A18284A9870C8ULL, 0x344E786F67C22777ULL, 0xA40A59DC4D70B2F1ULL, 0xDEBBBCE05DB0A625ULL, 
            0x478659E31CED80F4ULL, 0xA912297BA2B0A357ULL, 0xC2DDC8EA9EFCAC25ULL, 0x887EC05C5C7F8E48ULL, 
            0xCB71B3B3F5006877ULL, 0x66840170022812F7ULL, 0xD890FB787A321CDCULL, 0x9A0A7DDF0998E5AEULL
        }
    }
};

const TwistDomainConstants TwistExpander_Gemma::kKeyRotateAConstants = {
    0xF1BF06C53821CD3FULL,
    0x0EC4701723FF341FULL,
    0x32AC7C97EA94B1B9ULL,
    0xF1BF06C53821CD3FULL,
    0x0EC4701723FF341FULL,
    0x32AC7C97EA94B1B9ULL,
    0x00C7220EC09C85CFULL,
    0x5F39DE1E8505B62EULL,
    0xE1,
    0x47,
    0x98,
    0xDA,
    0xA2,
    0xC3,
    0x05,
    0x61
};

const TwistDomainSaltSet TwistExpander_Gemma::kKeyRotateBSalts = {
    {
        {
            0xA200C132298B58C6ULL, 0xF449A41E91736CD4ULL, 0xF4F4AE3A811A2B00ULL, 0xD13385707E57DE14ULL, 
            0x7794EDD8E23D7FC4ULL, 0xFB96C72D59E1666CULL, 0xE69A2C1E290A01E9ULL, 0xBB3EBA4EE5752BF7ULL, 
            0xBCF3B171D4740AFBULL, 0xA313F31B0D040C43ULL, 0x056ED808AF5A0FEFULL, 0x88FA2C61500678A3ULL, 
            0xEEA6E3ADE7E7C954ULL, 0xB41CB3277FD816E1ULL, 0x943CD35D232837F5ULL, 0x5FF58AC736C3DBDCULL, 
            0xFDEBE0AE9E0F1DABULL, 0x70AAEF9CE9A744BEULL, 0xA1ABA3379BFBB309ULL, 0xDBBAA857C5EA1D26ULL, 
            0x5EFF9383FDC38B21ULL, 0xDDAB890542DC7F2AULL, 0xF4DF3CF587783D39ULL, 0x564286C20D72EAC5ULL, 
            0x694666EE0BDAC3B9ULL, 0x58E30E1625EA2A10ULL, 0x34891A85EE5F08AFULL, 0x05EA15C200BFAA53ULL, 
            0x63DA847EDC431B30ULL, 0xB834DB08B991E827ULL, 0x513E703A9433A905ULL, 0xCF0DE46113CB9BD2ULL
        },
        {
            0x3650D9233B825B42ULL, 0xC6E2D447F2F2BC0EULL, 0xC7DF4F8B55A9F9EBULL, 0xDA9791B31F93F2F4ULL, 
            0x69ACC0695316FAC6ULL, 0xA5CF8C80E96DEB88ULL, 0x63FB42AA882EE004ULL, 0xC86A1DAE6F4A9A78ULL, 
            0x31A0DC8E7A7D0F6DULL, 0x5CDA91C9B2E31C1AULL, 0x696A5CF7AE1ACD34ULL, 0x96F548FB92BB2723ULL, 
            0xF6F95CD5A0F1BF1BULL, 0x663FE394DE76B9CEULL, 0xCCE195E4A70650E3ULL, 0x926770553BED3222ULL, 
            0xB4AEF84842CC0E9EULL, 0xD10016C68318795AULL, 0x4D38224111C7BCD1ULL, 0xF343A8F49E91C7AFULL, 
            0xC29FF91B7172683CULL, 0xF017E00156823241ULL, 0xE0FA1512795A8465ULL, 0xDAD77E134B401DD2ULL, 
            0x9983076BD16A0B39ULL, 0x3BDDB0D2C5C2B99CULL, 0xD29CB36463E2E6B1ULL, 0x7EBBC26CE3A5B0EBULL, 
            0x55A1015D73AE7AECULL, 0x7D14B5FEAF45699BULL, 0xB2AD109C721B5292ULL, 0x8FAAAFD095E3D076ULL
        },
        {
            0xFB5FDB42F46D1E25ULL, 0x15A0F0CA32815FD5ULL, 0x39258274ADF3394FULL, 0x026F822C04AD87B3ULL, 
            0xBA0C58E0AA9DA85FULL, 0xAD88C2080658C304ULL, 0x9E85DF7AAD9248FFULL, 0x6DA8ACB4683B168CULL, 
            0x46E4FF7B2AA0DBDBULL, 0x70C9A6E1D3D083D4ULL, 0xD6729BC5CF70DDB2ULL, 0x8C5EA67E7B2B6588ULL, 
            0xCA6677BD50B8F6BEULL, 0x221E34317B708742ULL, 0x96A9636B242B2F19ULL, 0xF266458D7BA89DC9ULL, 
            0xBFF8A8B841A71505ULL, 0x1D9BDDF6A02725AFULL, 0x19041961467608CAULL, 0x9018A2519D909C35ULL, 
            0xCBC66A9F1F290A09ULL, 0x9734D9D9BE9B22F4ULL, 0x00CDA3BE2FAB26E2ULL, 0xF957EBBECBB1F1F3ULL, 
            0xE8FDCFB9C5F38997ULL, 0x199BECE1670484A4ULL, 0xA7D90E11E3A43A54ULL, 0x7B2A3902CE542458ULL, 
            0x0784A35EC55182D0ULL, 0x232BE4DBFACCDFBAULL, 0x47D34059F94099EBULL, 0x28268C63B64C5FF1ULL
        },
        {
            0xC783A8B7C5DA72B5ULL, 0x7453F3FFC0A30888ULL, 0xFDD4A77856C66CB5ULL, 0xFA84DE0D6421C313ULL, 
            0x652231DCAB9DA367ULL, 0x54409A9ACE3463F5ULL, 0xA023A94B8626C8A9ULL, 0x2502E91E907E99E2ULL, 
            0xBBB5D7B729D1009FULL, 0x6AE3539B2BED5371ULL, 0xC560328C3A676EC3ULL, 0x9DB7ED751E94183FULL, 
            0xA80DDCBA6CEE8032ULL, 0x64AAC315191A9EB0ULL, 0xA58DEE28947D80FAULL, 0x6C13DB58B21E8654ULL, 
            0x89F21E6330099F5DULL, 0x8507EEDC26DFFDBAULL, 0x489767EBAD3903E6ULL, 0x2ED62B8510BB5E76ULL, 
            0xDF3CA09C77B39D36ULL, 0x5ED4F27C9C72E5F1ULL, 0x4589E9C37705418DULL, 0xB435E2BB96510002ULL, 
            0xEF65D4833968651EULL, 0xB08EA3DA20B4FA00ULL, 0x04E34A9036E074C0ULL, 0xF9AFDDE6E6F4C430ULL, 
            0xFB2FD8D8CA365563ULL, 0x9103E638FD249CF9ULL, 0x33EEF9261AC3DBF9ULL, 0xD552E5E7A48DE634ULL
        },
        {
            0x8789E6893330EA74ULL, 0x5AC1C4BFF06E37E1ULL, 0xB2BC0723486EEF3CULL, 0x04AC9BE025C8CF06ULL, 
            0x7576E49FF8350DE5ULL, 0x94BD642E4029CEEEULL, 0x55FFC7A8FE2A83CBULL, 0x2A0599F24D1C3AFCULL, 
            0x3DBBFE61AAF66566ULL, 0x2934DFE01A52F0A9ULL, 0x4C890ED0C5AF0B5DULL, 0x49B4690F7AF24FA5ULL, 
            0x46B076F6DC0C4E35ULL, 0xC21E1FFCCE266F49ULL, 0x9B223114EBD04DCAULL, 0x12D1215DCFCDFD41ULL, 
            0x62918E0AF68AA37AULL, 0x7F69067C6E90DB26ULL, 0x0E5F492A2763156BULL, 0x4B6D109211BC41F3ULL, 
            0x7CCAFA45F838793AULL, 0x40274A0417F1F703ULL, 0x84AF1E6005647162ULL, 0xA6491D65FB579A5FULL, 
            0xFC40C8783E12EB51ULL, 0x8493FDA4CD3CF748ULL, 0x2A06E77352C03FD4ULL, 0xD32265874DF9C210ULL, 
            0x903F1FA627990381ULL, 0x8F1714F4B5FA0CD7ULL, 0x7EAD0D6844BE63F9ULL, 0x4DBB24E62C297532ULL
        },
        {
            0xFF4D8A93BC8A9FB8ULL, 0x8798ED63B3618A4CULL, 0x6FE309672CC3A5B8ULL, 0x900AE91D66D70F01ULL, 
            0xF756E0DD84F26401ULL, 0xE97A4332B7581309ULL, 0x6130FD080BD917B5ULL, 0xCB61DF592745CE07ULL, 
            0xB0711FBB43A552ACULL, 0xDAF40F5757957FA2ULL, 0xEE6D96C97C933325ULL, 0x003EE59B62A9D630ULL, 
            0xB67E6AC9555BD2B1ULL, 0xED18F4D2DAB4C546ULL, 0x048AF213256C9319ULL, 0x8C9F50C3F0F10F5AULL, 
            0x052C4479C116B395ULL, 0xC19FD32623FDC654ULL, 0x2620B7FBE87C3B70ULL, 0x94266D5D8D08EBACULL, 
            0x0DCE774F9C316ECBULL, 0x46B4E630AD746908ULL, 0xBA0EA3A4F1A1ABC5ULL, 0xF259DEAE852E993FULL, 
            0xEBBE85E63C2895DEULL, 0x8950E36BE11B68DEULL, 0xE7A612682E60BEDAULL, 0x84BB34E5D447F270ULL, 
            0xB703CEA0811CEAD3ULL, 0x765024D77FE3ACA7ULL, 0x62FAFFEAA843C6B9ULL, 0x82B333A94B9E0384ULL
        }
    },
    {
        {
            0xA035C88EBDD01918ULL, 0x0C4390FE831B21A8ULL, 0x2A5D5793BB8DDD2BULL, 0x25C655D969890AD1ULL, 
            0x6AD97B539E4B9FBCULL, 0x7F73E24CB0018412ULL, 0xB19729446EBFD803ULL, 0xBEBBB7AFC56A5086ULL, 
            0xE08943E3354CAC1DULL, 0xB5FB049AE33A3207ULL, 0xFE416FF5184C07DAULL, 0x0E8174EC2043E4C4ULL, 
            0x33D40945599DA273ULL, 0xD750B6FC8A8440F5ULL, 0x1FB49C1D87E61DE1ULL, 0x5173B5BA98C4A0D5ULL, 
            0xB4518E70A688B27FULL, 0xFEC002E3CEEA0CCEULL, 0xA981F4EA6882295AULL, 0x191643074AAE5DAFULL, 
            0x4F262130074AC28CULL, 0xB16EA3A482B3AD65ULL, 0x1B6FF8A393587F43ULL, 0x20286E96F85863A9ULL, 
            0xB43D5807373B31BDULL, 0xAF5DFD944895BA90ULL, 0xD6542B9604C0C6ECULL, 0x92C4642824879584ULL, 
            0xCAF55FCA9D693B8EULL, 0x414EC66A98316BD2ULL, 0x2D3DAAF6B077C86EULL, 0xD0B8808C5DA4B278ULL
        },
        {
            0x641E103115119790ULL, 0xBB44B2956A735778ULL, 0x646A750ED0652CEFULL, 0x77C7D741F66DCCF9ULL, 
            0x1F7A20A32B18FA97ULL, 0xAE5D0434015FDCA4ULL, 0x723C8D9B8F618B90ULL, 0xEE885B3CC2EB7A25ULL, 
            0xB433F29E1C01B0ECULL, 0xD4E8099C70A7848CULL, 0x4F0ED8AEB696B074ULL, 0x2D5F1DB6ABD6DD30ULL, 
            0xA0FB34B723212802ULL, 0x82C172E842953A98ULL, 0xC3A152555C79D450ULL, 0xDBD84BDCADEFC6C1ULL, 
            0x11B6782AB3BF68DAULL, 0xE2777AE9D2C902FEULL, 0x95570D5147BC95B2ULL, 0x806216B388F39FA0ULL, 
            0x3D193F4B734A3522ULL, 0xA3D930B56B85B2C0ULL, 0x4C5DE5128B4471B2ULL, 0x902340F59F81E835ULL, 
            0x1795491EB9787151ULL, 0x697BEA3B404ED605ULL, 0xF4F0E0DE0F73402AULL, 0xF05C9DB2D0F7A5C1ULL, 
            0x5E8413997119116DULL, 0x21216D069DD7AD4CULL, 0xC544FE182B0D2CC2ULL, 0x529D16436A836AEEULL
        },
        {
            0x2F0DA03EAA167926ULL, 0x6F1D02915C89FD3AULL, 0x6927B785EAA01355ULL, 0xD302BCBD210DFF67ULL, 
            0xB69C45DB53F21184ULL, 0xE44C596890CE66B3ULL, 0x994F500FCE1971ECULL, 0x7AD5422F74F0A01FULL, 
            0x3147D864C43834F7ULL, 0x5708A6F0D8519CF8ULL, 0x0CE5FE819EA20E16ULL, 0x20BB0D97E0181C1FULL, 
            0xA6ECA4910A514CC9ULL, 0x94465B507EE53DFDULL, 0xC293B8B036E041A9ULL, 0xE89D4587A6450B6AULL, 
            0x3F10AB88480C99F0ULL, 0x2FA92631623F00FEULL, 0x496C4B4B5817A777ULL, 0x813517EBE0A89AECULL, 
            0xEC949C0364B001C1ULL, 0x75BCAE2E61CA6F32ULL, 0x23C4AD87CE9FC0F8ULL, 0xE271CFD34ADEDFA2ULL, 
            0xB157D2CDFB549A94ULL, 0x9642BCF93232718DULL, 0x0917354CE2CBC339ULL, 0x737789B40F25266EULL, 
            0x74314B900F9DF3D1ULL, 0xBED7C616CA1D7941ULL, 0x23D718C37C1A810EULL, 0x6B1BA1D288126505ULL
        },
        {
            0x210D8E19D6392FE6ULL, 0xC3718D996F4BF07FULL, 0x35B453BD24D20FEEULL, 0xE3DCAAA9188DEC9FULL, 
            0x9F5F152E8282FD39ULL, 0x08329F4FD22F9035ULL, 0xC88395E35833D668ULL, 0x0269A07113663787ULL, 
            0x821DFFB1E985516DULL, 0xDCFBB6D7DA53C4E1ULL, 0x42CEE0A2A0129B8CULL, 0xB7762A38F3DF78E1ULL, 
            0xDA6B37CBA2BF0B09ULL, 0xA8C1120A12DC3C2AULL, 0x1C443A0316099C01ULL, 0xD8494262ECDFCF87ULL, 
            0xFFEDEDF6DBCF5CBEULL, 0x51A3BED219AD2F5AULL, 0xAAC0BC7C6A5D75EDULL, 0x87217579156221FBULL, 
            0xBB5E7436C4C48A1EULL, 0xA9B7CAD1CC7BD9C5ULL, 0x76E3CCA86CB56664ULL, 0xBCA6F82335A4791EULL, 
            0x193627FD9B09BF9AULL, 0x322E0365DFAD6CBCULL, 0x6C5A7142338312C6ULL, 0x55D3C528FF75A62AULL, 
            0xEDA81EDF387DFB80ULL, 0xD36643F71C051BDCULL, 0x2F3C14966F78FD04ULL, 0x8D097C84E56E3677ULL
        },
        {
            0x39F8BAB1253D0FD8ULL, 0x409681FCFD797DE4ULL, 0x65ABE9178C71E400ULL, 0xE686D973B0684CE5ULL, 
            0xE7F52BD0C27E88EEULL, 0xB61ADF281A534F7AULL, 0xB3631D8406D4A20AULL, 0xC9DFBF7992D2F613ULL, 
            0xA4BF46F0E0C55C91ULL, 0x9A1111DA36107A5AULL, 0x15DFD9D7CE6E78E9ULL, 0x46E77F92F2D9D15CULL, 
            0x40F3345670872CD2ULL, 0x0390E0A5D916D79EULL, 0xE972D53136B2EE17ULL, 0x6E3F95A18B95B802ULL, 
            0x933DFDC6F8B835E3ULL, 0x48687DCD94268210ULL, 0xEF3EBC47175C11EBULL, 0x35DF14BD5185043BULL, 
            0x690E072F78A87B92ULL, 0xBF5DD8EBD8D5616BULL, 0x69137EE0436FE83AULL, 0xA75AE5E5101D49C5ULL, 
            0x62FEE17174326886ULL, 0x608F2C8C8D327C04ULL, 0xB09200AE87A896E5ULL, 0x22C345D633B6AB32ULL, 
            0x7776D41E447480DFULL, 0xB07998AABDED17FCULL, 0xE1329F4F00F5D6A1ULL, 0x26B240B8A6EFABE9ULL
        },
        {
            0xB95EFAAAD016C08EULL, 0x7D137300EFC545F1ULL, 0x08DD77407989F5B6ULL, 0x76375ECEA93639D9ULL, 
            0xFF6FA024DD8141A2ULL, 0x9D83BBF93EB26E2CULL, 0x636F8DD6B4502830ULL, 0xBFFFFBC0DCB36DE9ULL, 
            0xFBF90752926A0CA7ULL, 0xCF3CD2DD1681925BULL, 0x063C8BF3C8A1E144ULL, 0x03143C50A39E5E5BULL, 
            0x3879DC6FDE9A8694ULL, 0xE5D1BAD5EBE4FFABULL, 0xB1FC6F0939A29E8BULL, 0xAA343CD7E3A10B02ULL, 
            0xEFBE6ABA17877932ULL, 0x38BC27C5B2799F36ULL, 0xB8569C3FEB06BFEDULL, 0x9F37CF6ECDB5E5E2ULL, 
            0x2C5B582B4202DBCAULL, 0xFF95BC997B2AB5CEULL, 0x6D6CA37361F788F5ULL, 0x8565DFA386F8F91BULL, 
            0x8759CCF421CEE0F0ULL, 0xB50086114FED5994ULL, 0x2C3B1EFF322F1E78ULL, 0xC48AF27A033ECB58ULL, 
            0xE12D79A2BBAC4745ULL, 0x89DAEF4EC1AAD784ULL, 0x4B54EE549F5C1D42ULL, 0x117FC27C286A8407ULL
        }
    },
    {
        {
            0x64953D6E8AF71311ULL, 0xC317B403C8D2BD84ULL, 0x1E5D3EB0D7725937ULL, 0x185D5A2C9D6CA58EULL, 
            0x9271108B92A6A173ULL, 0xBED3FDAC9D75C0CEULL, 0x39FD220CB3559ADFULL, 0xF029A67385D64382ULL, 
            0xB83172872949E13EULL, 0x2AC6D422FA5FC60FULL, 0xE10AEC9C8505EC4CULL, 0x6C9DDD95D02FEC2AULL, 
            0x12095EAC594F1279ULL, 0x7F5E482379BF750FULL, 0x6962811D9DD0DA08ULL, 0xA040FDF574906AE4ULL, 
            0x9F889E557FAB3AA6ULL, 0x986D18C84406EFBBULL, 0x37D6D6185D19010EULL, 0xE96AC57B38518295ULL, 
            0x92B96886E97D646CULL, 0x5991BEA993F48C95ULL, 0x5F1888F3076D7390ULL, 0xC1FB114ECF3DCB86ULL, 
            0x3E123C0C75B54157ULL, 0x2B7D3271D5A3B488ULL, 0xA539ADB85CDDFC84ULL, 0x2A990528798AFA1EULL, 
            0x0C5C4E6F9F73F5C2ULL, 0xAF6B6E90BB11C27FULL, 0x6586593D6CD2E183ULL, 0x05C944CF5E0EE00EULL
        },
        {
            0xECEEFC36D39E804DULL, 0x50B6A89C4ADCFA75ULL, 0x8C9E36C17D141E8EULL, 0xE5F0D9BE6FD136FFULL, 
            0xC9707F2D94490549ULL, 0x69BDEE6C902D249BULL, 0x07683B64108B30B6ULL, 0x9F9871EB64D0D910ULL, 
            0x4F8727E7B30C13A8ULL, 0x4EDD129D3917CDD7ULL, 0xA76DE378D1347DC2ULL, 0x2579C463C0AD98F0ULL, 
            0xF9C5011B56B81E82ULL, 0x1B50D932355B27B9ULL, 0xC7121D0A4DB78614ULL, 0xBB24D382AF9C699DULL, 
            0x4577485B6543D1ECULL, 0x88D056F125200C1FULL, 0xAA56552A5DE06725ULL, 0x93F789407FC13AECULL, 
            0x321E5468C22C672CULL, 0xFC621DC0554E682FULL, 0xC529C25DA334BAFAULL, 0xFF90B8DAB0DC9BF0ULL, 
            0x650EFE135A93A821ULL, 0xE100D78139D1D68DULL, 0xC6F4650174DDFDDEULL, 0x5A1046874161F155ULL, 
            0x781A5AC0724ABA43ULL, 0xD8E07BB9D6F919B7ULL, 0x06BBFB972917ABDAULL, 0xA535B15E6AC491F3ULL
        },
        {
            0x7A26BA3CE28D831DULL, 0x8A1FCB6C3CBB8B34ULL, 0x1527E00775ACCD7AULL, 0x7882A594594EF2B0ULL, 
            0xA0D8CE90350BACB4ULL, 0x37DDF0D3EF54C981ULL, 0xB93F3155F8974DA7ULL, 0x551CDC1BD55BD586ULL, 
            0xBE45C33A5E12D353ULL, 0x8C64E45FBC890EE0ULL, 0xF93F6321D50D1351ULL, 0x9FB292FF5FB9C668ULL, 
            0xF31CF4BE18BBEC20ULL, 0xCA257F04DCB6A7D8ULL, 0xD2CDE9FB98784EFFULL, 0xDE83A002C941D3CAULL, 
            0x7D19F46F3352D576ULL, 0x53E3AD7CE370C4F5ULL, 0x24D69A6779EC132AULL, 0x1528699DB2E38BF8ULL, 
            0x0989F8A58A211AA8ULL, 0x86AE1A16525F2DDEULL, 0x560B114F6DADA954ULL, 0x4CF6535F279609F7ULL, 
            0x37027D4E9FF9167FULL, 0x761E01C6E923DB95ULL, 0x411F65E9AE4A442FULL, 0xC5C49E59FC1C7F7CULL, 
            0x36F4CDD11A3E7923ULL, 0xF3479B40368A7BEAULL, 0xB53F4382B7C145FEULL, 0x90AAF641138745EBULL
        },
        {
            0xB07B1A14E853A8BAULL, 0x7D0297716114EE22ULL, 0x24D50DD62999F891ULL, 0x7724C4DFD341BC98ULL, 
            0x207E99A9E5B66B22ULL, 0xE886AC170EFC1D4CULL, 0x3E15D0BA41ACAD28ULL, 0xD43A278207130CF6ULL, 
            0x01DD941D53A75979ULL, 0x368A31B89848D06DULL, 0x6E133C9A4ACE4EA2ULL, 0x9CE81A8AB90C509EULL, 
            0xFFFD266D3E300D7EULL, 0x632313C30FCE4C83ULL, 0xA7CA4637A96C50A6ULL, 0x31DD96097CB35CCDULL, 
            0xD6479EC1E43D4092ULL, 0x7DBC981CD529191AULL, 0xC6A15F19C163C64EULL, 0xE64A20C14E2711CAULL, 
            0x721578C27290860CULL, 0xBDCAA65975E873CEULL, 0x2292CCBBC0DBDAA2ULL, 0x462A87AE0ECF45D3ULL, 
            0x76193DB83CEAEA46ULL, 0xCCE2AB70601045DAULL, 0x4C9913C79B0C5967ULL, 0x0B88AFC92A3D9F23ULL, 
            0x4B090A22D4468A1BULL, 0xA60FDAEDAE1568DEULL, 0x6C34BCA91540668EULL, 0xB7F971B5697FB32EULL
        },
        {
            0x9D1E89A80AE67FE6ULL, 0x479CD45A04362065ULL, 0x261F5A992C2CD4A6ULL, 0x68316271BC8F3A33ULL, 
            0x337E8FF6997F9F77ULL, 0x3B4E3511D5570D5CULL, 0x884EC8A0B35FA78AULL, 0xA9F7DF22D96D4182ULL, 
            0x4FCAB85FB2F50A16ULL, 0x43A10583A0D63501ULL, 0xFCF4F4A9A32CD3DBULL, 0x880C524F4B9DE7F0ULL, 
            0xC9BC915B75A89AA5ULL, 0x62FBF2192CFD6239ULL, 0x30CD6097D4587876ULL, 0x8D7D7BF22D39D085ULL, 
            0x4C4DC487FD170E25ULL, 0xB4D55C08D9A1CDFEULL, 0xC0377DF20DE047A0ULL, 0xA45FD7DB7B49C128ULL, 
            0x9BA52C09708293C3ULL, 0x2DA5138C85BB6882ULL, 0x6FC5F72C2AF8F32AULL, 0xB27D7AEBBB998091ULL, 
            0x53BC78ABE3443587ULL, 0x85586F1D834163C9ULL, 0xD182BB574F388D97ULL, 0xA5389550CD84BFDFULL, 
            0xC0744C683B0AF3DEULL, 0x8C41FE8250300E75ULL, 0xD52AC49E3B36C5DFULL, 0x11AB8125724F62AFULL
        },
        {
            0xB49CD605E89DE254ULL, 0xF49F2F197780B569ULL, 0x91B1B4EB212DA3C8ULL, 0x6C7E6AB2DA5BFEE5ULL, 
            0xB4DCD3586EF0FAD9ULL, 0x14C6379614DB1F7AULL, 0x40F174BF89131D9CULL, 0x24BECCD7AEC67663ULL, 
            0x6D7B171C2C50C7BEULL, 0xA7EA6622152C111FULL, 0x750406ED3F7AB3E6ULL, 0xEE3B64D294E093C0ULL, 
            0x79A1D43B1A769FD7ULL, 0x877F0BB159746372ULL, 0xF8ED66B1808A4AF9ULL, 0xDB273F6484D36FA4ULL, 
            0x1D022509EEC04A7FULL, 0xB078B692EE9340CFULL, 0xE9FDE1519789A332ULL, 0xEF4C0D7197C17028ULL, 
            0x511E20D713CB14FEULL, 0x036DB1634C7594B8ULL, 0xF54283F94444CC8AULL, 0x9D91765145A78484ULL, 
            0xEA9DFD6953985225ULL, 0x6443B2327882124AULL, 0x7171827758CA9FCDULL, 0x1A5E13808A28BB62ULL, 
            0x8ED1662F24D18916ULL, 0x0CD6D97A884A437FULL, 0xA4B2CAD6078F1C0FULL, 0x4E713153642DB9D7ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Gemma::kKeyRotateBConstants = {
    0x03789E9742B45FC7ULL,
    0xC230BA149D5059CDULL,
    0xA28385C722B75EEAULL,
    0x03789E9742B45FC7ULL,
    0xC230BA149D5059CDULL,
    0xA28385C722B75EEAULL,
    0xB34927A27562E4C1ULL,
    0xD9CFF5AC3038BF82ULL,
    0x15,
    0xC9,
    0xCB,
    0x13,
    0x29,
    0xCE,
    0xC5,
    0x18
};

const TwistDomainSaltSet TwistExpander_Gemma::kKeySpawnASalts = {
    {
        {
            0xC6C6DD34A8AFCE6EULL, 0x936BA7B8332D57FEULL, 0xDB385EBDB7D78891ULL, 0x0F597A98A53F6996ULL, 
            0x58A788315F717FD9ULL, 0x34A01363E6D216CBULL, 0x96F72CDCCF57FA98ULL, 0x787608B85D3A7384ULL, 
            0xAE2EB8E549FB394EULL, 0x28DE08F40213E13FULL, 0x5B03F3F2E456C4DBULL, 0x103CF46F9C8F3EEFULL, 
            0xD4FD3DDD708CE6C9ULL, 0xFC68150DF6B2DED1ULL, 0x2039A77F99F502F9ULL, 0xBF5A7A4218D48BF7ULL, 
            0x8E62704E8C3F1CCDULL, 0xEFFF1DE009EB8477ULL, 0x6E231E83A60FD747ULL, 0x16A9EDC49C0A675BULL, 
            0x767FC0329D8A6C2DULL, 0x19AB3920CE4C9BA5ULL, 0x272BAB6A295A77FBULL, 0x0D5AD7B417A10EF0ULL, 
            0x4FD355BB8EA92BCEULL, 0xCD7F26EE6ED9CC6EULL, 0xC365BC66E1221D6AULL, 0x5C9B13B4E11790E0ULL, 
            0x1EC2F19E30C98E7FULL, 0xC4DFB67249045F9FULL, 0xD92DA6ACE2DE6441ULL, 0x42E79BA8662C9469ULL
        },
        {
            0x843B700DBA69947AULL, 0xA9458DB4C2E8297CULL, 0x7810CD1E36EFE55CULL, 0x4FC8C33850EA0808ULL, 
            0xDC51583B47F6E861ULL, 0x9D7EFCD04A76A711ULL, 0x8FFC0D463C4A1E80ULL, 0x6C60C6F97CDC9BABULL, 
            0xF36F756C30427AC2ULL, 0xCEE9309644D007C7ULL, 0xCC99CABFBE15FBF7ULL, 0xA914FE32235F6E42ULL, 
            0x0D8E9371B620000BULL, 0xC4F1C79333778FACULL, 0xFF750C660A2D6771ULL, 0x96EBF740FE1E216BULL, 
            0xDAFBC94F2A047CBCULL, 0x97FEE648B5103194ULL, 0x1424CA6FBEC59325ULL, 0x1CE54A96B379E6E0ULL, 
            0xF5BDD27DE866BA40ULL, 0x541DD463C52D1A46ULL, 0x7350C4368220CBCFULL, 0xEDF72572CD13849FULL, 
            0xCAD7A08E8A3FD0BFULL, 0x811DCD54997752F4ULL, 0x8458CC6A3052EE1BULL, 0x276286B454BF9B8FULL, 
            0x2889F484AFADA7B6ULL, 0x0C9CA7FA4D5AFE37ULL, 0x4D980D8BF7EBD7ADULL, 0x78647F3586E3FBBCULL
        },
        {
            0x0C04DE8D67DA28CEULL, 0x77B0B54F2DA2BF4CULL, 0x2263D5BB427533C6ULL, 0xCECE52C4EEF2CFF7ULL, 
            0x0638A7181326C76DULL, 0x7FBCEB25D4E92625ULL, 0xBB76D773078B1968ULL, 0x1D201325AD0792E0ULL, 
            0x37C8A1AD6E9F00D4ULL, 0xADF7DE6726BCAB71ULL, 0x12D57C400A6CA081ULL, 0xFB1398434F2AB1E0ULL, 
            0xFC0E251571F7306DULL, 0x74B893DC6997A043ULL, 0xEE09646D2A2F55F1ULL, 0xCCBD10FDF4DEBB56ULL, 
            0x6C769B11146279ECULL, 0x94A0458EEA6416FCULL, 0x8B8AD2EE8A333B33ULL, 0x87825CC33B8D08AFULL, 
            0x9821BB3FD52EEB5BULL, 0x4C3A975F7EDB547BULL, 0x1268D75CE7B2FE4FULL, 0xD26430DE48771E6CULL, 
            0x5834F05DD3A81213ULL, 0x6C7AE1D73AB96B9CULL, 0x015ED363A3FAAC40ULL, 0xEFE0A7C44C3572EBULL, 
            0x7BBB01880709E9EFULL, 0xED6FD24332E01B5AULL, 0xF1B3663944AC6FCDULL, 0xE264E9F6E1467162ULL
        },
        {
            0x1F3B029EA4A068E7ULL, 0x7B6C0B12683EA6AEULL, 0xA541260FA4314D59ULL, 0xE47D1A7DD2910590ULL, 
            0xB832D6495E6E585FULL, 0xECBD3B84A361194FULL, 0x0B184C82BEA8B153ULL, 0xFC19A9370A4D9820ULL, 
            0xDF8AADF99B138D6FULL, 0xC1F874844DB323F8ULL, 0x4999360866BB428EULL, 0xD59381807BE742DEULL, 
            0x1542EB09B5A0EDE4ULL, 0x73717433ECE897B9ULL, 0x91CA8DAB05C9E005ULL, 0x9200AAB07F106538ULL, 
            0xFC78F37FA25D5366ULL, 0xFA9DA0E33D587116ULL, 0x3E29640D3B28EB34ULL, 0x52546F7CD5B1DDD6ULL, 
            0x8D54D09593F9BB5CULL, 0x0F304664404DF817ULL, 0x25A0B03FC7350BE7ULL, 0xF5F2C51E86035EE4ULL, 
            0x02BE87D786451EE0ULL, 0x925E4BFDF333C511ULL, 0xED61747A02CAB5D9ULL, 0xA43F1CE8859318F1ULL, 
            0x6872351AE05DAF6DULL, 0xC28BDF046E663219ULL, 0x2D67C2BF713C73DDULL, 0xDAEE9106B71E3DE6ULL
        },
        {
            0x7A1EE85BBAED1BB8ULL, 0x79B109C8B2643958ULL, 0xE19FFF3B18207B8FULL, 0x83B4D183E2F645DAULL, 
            0xFB29B4B37921F7FEULL, 0x38A68E70F9885A2CULL, 0x61B68AC0E71C6E56ULL, 0x75E8F0E5E6158304ULL, 
            0x90A9478EA4A2581DULL, 0x1298887D0CDF0E89ULL, 0xBE5AE721F83A8EC2ULL, 0x5C388F231AA05339ULL, 
            0x6E3E7DFA2A341D86ULL, 0x497E35964AD35152ULL, 0x8F3420917EEC3C18ULL, 0x90DEFE212C22E785ULL, 
            0x634B2A7475F10742ULL, 0x4A4660D409E2A7EDULL, 0x67DB7FDAAEE420F0ULL, 0x74D37B4FA6573DD4ULL, 
            0xAF6604776892EFD1ULL, 0x874DC6EDC1E878D8ULL, 0x96620D2209BDC2EEULL, 0xDE01AA6DD51318E2ULL, 
            0x2E0C008DBCE8A0A7ULL, 0x97A3527A90E1CEA2ULL, 0x548190E59B48B44DULL, 0x9F1D03326FA872A7ULL, 
            0x48071AC4C23253E1ULL, 0x90B62094D2726FFEULL, 0x31458E60B71350FCULL, 0x6980EED9D3AB7FB4ULL
        },
        {
            0x3F221F07518BB956ULL, 0x52092DA5B4C802FBULL, 0x710BA1C80E29A698ULL, 0x8CEB45EF12776249ULL, 
            0x5AAF15F134D5B7B8ULL, 0xE21A022B248D2058ULL, 0x1919989DDF11230EULL, 0xC7810795B7B63C36ULL, 
            0x095E4637D28DB90CULL, 0x18C015B9548BECC6ULL, 0xCCF533FAE580215FULL, 0x22D8DA49EE575EA1ULL, 
            0x2F24168983E812DAULL, 0x29379CFDCA954E81ULL, 0x923A341357DAAC26ULL, 0x172F43637F6034B0ULL, 
            0xBB0B778119D39033ULL, 0xF6A3460E3928C325ULL, 0x0F2DB6558E9695E6ULL, 0x73C92AD9382767CAULL, 
            0xE4875755E7686C5DULL, 0xD587C5B69A3DC461ULL, 0x82D2DE619EA9BAADULL, 0x3DE7055E503F97E0ULL, 
            0xC4E6DCB36625FBD0ULL, 0xDB9AE3F7ED706577ULL, 0xCC4F21D8537CB0ADULL, 0xD809B1BD886D6FDDULL, 
            0x431DE8426D094FEAULL, 0x3CAE08A55EFDF394ULL, 0x6013A4FBE44E357CULL, 0x48CC48F19005D435ULL
        }
    },
    {
        {
            0xE5A693B0116B2B4AULL, 0xFF6C7364ADA7C615ULL, 0xCA50ECA70B569BBDULL, 0xB7B0D20A24B41EC4ULL, 
            0xC37168FB2655ACCDULL, 0xCDA520C30238B6AFULL, 0x619D66C6514599F0ULL, 0x7AFB2B7257E7CF21ULL, 
            0x8DF97CABDA682181ULL, 0xA733DAA76CE5B977ULL, 0x5F131DC45CEABF65ULL, 0x363A79D97F89DDCDULL, 
            0xA62213942D7BD43DULL, 0xA127ACCDE7676167ULL, 0x2BB4B823F7E1273BULL, 0x6F2D9F75A93E9CBCULL, 
            0xC2D8B0CCB8101A9AULL, 0x982E4CB736BF58EAULL, 0xB3D0D33311FC0D1BULL, 0x8E50E50A934D2A88ULL, 
            0xF7CC66D3C041A952ULL, 0xFEB94D697ED76989ULL, 0x50A5BB2DC030D176ULL, 0x55AB3A223E3BAA01ULL, 
            0x93C65807A247D198ULL, 0x4B449E31C0B5FD4AULL, 0x5E75E11114EEB053ULL, 0x05AD98DD515AFEABULL, 
            0x6FA1BB5E065D93F3ULL, 0x2269844A9770242EULL, 0x5E39B908B7EAEB3AULL, 0xB63036B6E324F3EBULL
        },
        {
            0x5B23E107264082B9ULL, 0x9F20F3166F269177ULL, 0x144C1FA64CD386E6ULL, 0x685AD646637B12F2ULL, 
            0x59BAAECAE11E5ECAULL, 0x05364BB94B31194BULL, 0x7D9DEF1AF6E3AA78ULL, 0x7CC4CA7F61052C4BULL, 
            0xE674937C8D40627BULL, 0x3344030C1BE6E6EBULL, 0x6CDCC8449DAF95CDULL, 0x27FA6CB4ABE4E643ULL, 
            0x9F29DE3686A1E1AFULL, 0xE94B18D867D189F2ULL, 0xFACB50F27BB061A5ULL, 0x66B17B0CFED57FF0ULL, 
            0x9BF029A41BA64ADEULL, 0x1E8435AA5870551FULL, 0x0309D13556A2465EULL, 0x5A02940FE3CB6648ULL, 
            0x71045AFA9E0412ABULL, 0xBC0A57BC68BDB1D9ULL, 0xDD45AF3507C964FEULL, 0x243D18EA1FB2D983ULL, 
            0x9F9462B11D6C5744ULL, 0xBBA3382B9F7EB9C4ULL, 0xF40CEDB5751836FBULL, 0x781A17C483C84F12ULL, 
            0xAC5D47520124CD14ULL, 0xB0151E4DEAF3DE0EULL, 0x902D90186CBA41B9ULL, 0xF368C34106D3B575ULL
        },
        {
            0x0E86055E647A973BULL, 0x6EDBF8AC6A87BC22ULL, 0xFD980B48B1D1BE0BULL, 0x364B0460DA2E5581ULL, 
            0x1F6CE48974C79D67ULL, 0xE2867EACC4EE5EB8ULL, 0xE7F48CFA8496D8A2ULL, 0x095979233FCA50CAULL, 
            0xCF836BD9A9D8BA68ULL, 0xE53CCB737D0805E4ULL, 0x5A6DB9FAA81E6F8BULL, 0xB2FC4B76D373898DULL, 
            0xD4B066A29D3ED12EULL, 0x92B567374D68D91CULL, 0xFFA29188DCC6C062ULL, 0xFFCE74C95BC0021EULL, 
            0x4C6FDB9979A28798ULL, 0x382019B07AE23859ULL, 0x69EE36EC1238A39BULL, 0x30B5F03D2D1DC401ULL, 
            0xF30AB5D366410E3AULL, 0xB0CADF6F17B00CD5ULL, 0x3CFF814AC0C9EC47ULL, 0xB978B0AAB6EBE592ULL, 
            0xA820321FFD3AE401ULL, 0x6CB1CE1158A11089ULL, 0x2338E8F271F73832ULL, 0x3B3BB23ECC385C0EULL, 
            0x681B8B03C50E42E8ULL, 0x8F6B109BF75D5EDDULL, 0x5F5FA9A9D02840A0ULL, 0xCB3D1BED1D9DEE5CULL
        },
        {
            0x1F116CF45AD716FEULL, 0xA1047FF981C8C55BULL, 0xB92222BE48AD6CA5ULL, 0x1E2AA4FF3123E93DULL, 
            0x7C0AE97848F2B42CULL, 0x558EF05DF6AB092DULL, 0xD9AFDAB27777E42FULL, 0x3264B12C46D1B322ULL, 
            0x41BA9FF9F9AD5E84ULL, 0x93D82575AF5D4DECULL, 0x886E08A6AEC48854ULL, 0x1768F232D2D1ADC5ULL, 
            0xF769390157F18829ULL, 0xA8A1F912B36D5BDAULL, 0x46CB01570711FA3BULL, 0x6ABF1E1A1F5ACEADULL, 
            0x36AD819243ADE453ULL, 0xC57B73BDCEA0D3BEULL, 0x515E71AEAC048E67ULL, 0x77D973DB1851D7F6ULL, 
            0xCFCACC479D56C5D9ULL, 0x0BAD543F757656B1ULL, 0x2D4A061BB9A5DFC2ULL, 0xA365FE9F9F75A0C8ULL, 
            0x982BB37EAC9DCDACULL, 0x50B741B1C8EFAA49ULL, 0xC5BC81F2555109F9ULL, 0x93D689813CE38A37ULL, 
            0x468A120ABF96B498ULL, 0x19B9BA67712072B0ULL, 0x08E9A14B14D4FB9CULL, 0xF27030D19E5D4381ULL
        },
        {
            0x50F34238F6E43A68ULL, 0x541837BAB39BBD04ULL, 0x97D78C931236B5D5ULL, 0xC8CF22AC0AF5887BULL, 
            0x17D8182357E458EBULL, 0x6595F51F7EB2ADC4ULL, 0xFC47D419E606D8D9ULL, 0x6F11A22A4FC5B981ULL, 
            0x99E74C315A4721E9ULL, 0x8BCDFC85F6B26172ULL, 0x21C700528FAC9313ULL, 0x0AA2291511EC223DULL, 
            0x8C11C9EB49FA0510ULL, 0xC8022CC551EFBA66ULL, 0x3E7973E4E57F7C4EULL, 0xCF574A33E680E35CULL, 
            0x07EB36475391F78FULL, 0x051B21BB70AAB600ULL, 0x67558A4499526C62ULL, 0xE55ADDEE3EDF0115ULL, 
            0xC325361CC52A049BULL, 0xED63CB37B2D55870ULL, 0x04B02E9E4C793312ULL, 0xFF0180C24A596E1EULL, 
            0x3BF1E7AACB88F992ULL, 0xCEBDD011B14412B5ULL, 0xCE22CA83D577A38BULL, 0xC6AF35F9E498C04FULL, 
            0xA219AD1D27F17314ULL, 0x409E97F6F2AB106EULL, 0x788CB8FD3589CC3FULL, 0xC6EECEAA48B81C40ULL
        },
        {
            0x63AD781BCF56B980ULL, 0x1D2D98C3436D0239ULL, 0x608309C3B066298AULL, 0xD79AC563CD3F48C6ULL, 
            0x57E00FE414F97C02ULL, 0x830E646FBBA3D583ULL, 0xE5C6AF9B521C76D1ULL, 0x6C7A522100754485ULL, 
            0x5418F7720854DF2BULL, 0xA2EED50283B96046ULL, 0xF54768C78FE62BDCULL, 0x1B52D1631A2D48C4ULL, 
            0x014F6BE7F666B144ULL, 0x1985528083108CB3ULL, 0x09A4A9115957D77EULL, 0xD45D6A999512B36BULL, 
            0xDADE4D725CC2230CULL, 0xF92F52E5E4AFA13CULL, 0x0DDA47B1D4BCE97BULL, 0xCE6F1A54553D90EEULL, 
            0xEBA13CBE5CBA6CD7ULL, 0x465F8D92FA70512CULL, 0xAE4E6A5B61637D38ULL, 0x578844E8EDFA1EC5ULL, 
            0x08507A92178242F1ULL, 0x85059E7D24B86EC1ULL, 0xF57EBE3B9580BFBDULL, 0x8D5EBED3CE1475B8ULL, 
            0xD25748609DD1C1ABULL, 0x99898B08F4B96CECULL, 0x9E2F0A2A0CB72709ULL, 0xA46B908C4318EE98ULL
        }
    },
    {
        {
            0x18E2B7C9EFBCBC18ULL, 0x8BD29534AA5FFBFDULL, 0x407F940004AF7D61ULL, 0xC65315A44E29F76DULL, 
            0x119EA44D591D4702ULL, 0x9CFAC01A2FA288DFULL, 0x6CA6A414FFAD8D7DULL, 0xCF30F0DD0EFF78FBULL, 
            0xA36B78A445C0FD34ULL, 0x182BAD7FD64BC977ULL, 0x3B71E9D090E99C80ULL, 0xD3DD728B76AFF9D5ULL, 
            0xF1D522BB61C6E273ULL, 0xA6B7B54ED14AFB3BULL, 0x58BA902D8A5B7744ULL, 0x2338658DCB473FE3ULL, 
            0xBA21F44F54042695ULL, 0xDB136399C792BD29ULL, 0x1914C2B13A1EE09EULL, 0x6562AE6865B43D6EULL, 
            0x88DAC7757C20C1ADULL, 0xFCBCEB1A325D462FULL, 0x52FE9A0710220041ULL, 0xE5952602ADB8DE2DULL, 
            0x6B6A932F532A97CBULL, 0x10482F6029FCFD17ULL, 0x0802D6C39E0462C2ULL, 0x286DA317BCE6819AULL, 
            0xB1CAF37856921B11ULL, 0xB7F6D5AB73DEEEDFULL, 0xE3C5883D6540670BULL, 0xCAD1C998AD751274ULL
        },
        {
            0x1488D35DA1DE4620ULL, 0x26F35D81E546FB0BULL, 0xC915F6994BEE8BF3ULL, 0xBAFF041DFE8BE42CULL, 
            0x24EBD96BB26E242CULL, 0xB1520C5A6CF9166CULL, 0xF11A940FC43ACE06ULL, 0xD6234DE8CA509689ULL, 
            0x2B85EAE99E3858B9ULL, 0x39AFFF201F56C2C8ULL, 0x831EA3B6C789F99EULL, 0xE4D18BE90DBF4D85ULL, 
            0xBEEDF0D47CC166C9ULL, 0xFCB74636043E3746ULL, 0x1DC87016D5CB8B08ULL, 0x61CEC42631373DB9ULL, 
            0xF789C8FC5C9F0844ULL, 0xE2FE1236061134CDULL, 0x98943BB6000B3152ULL, 0x92690C29087CB450ULL, 
            0x2E5F6A0F12C7F438ULL, 0xEC8FC00DBE21582FULL, 0x392D1EDEF4BB0194ULL, 0x487D37EEAA80851EULL, 
            0xFFFBC68E7188E487ULL, 0x348AB603DA4210C2ULL, 0xCABAA096E0E2ADFDULL, 0x2486B2A30629255DULL, 
            0x9A5BB3CA505EB515ULL, 0x6BF96F67229EC2A6ULL, 0x8798342BFF73F613ULL, 0xFCE5AF708AE3FD84ULL
        },
        {
            0x1179BC3716534C21ULL, 0x559C3FC3A6E7975FULL, 0x98B9789D9A5217C3ULL, 0xBFE6A8F9F2687715ULL, 
            0xE5F3A352E10F8192ULL, 0xA98C87CB0370DFB4ULL, 0xBD40679B657B122AULL, 0x0C4CFE08ACBD3AA2ULL, 
            0xC7EFA9BF86CA9BA4ULL, 0x479605825B7F87C8ULL, 0x28BE8F721F534A74ULL, 0xB76A343F5B334AA5ULL, 
            0x7D68CCDE2A9F60CFULL, 0x2C96DA83525F2608ULL, 0x60C2050E4CBCDC76ULL, 0x2B587FC04DF1E559ULL, 
            0x092BDF7477184626ULL, 0xE4AAC4AEC3FD3928ULL, 0x81FEF1E2C4556873ULL, 0x677AB937AAB3F1AAULL, 
            0xFF17AB1436D08BEFULL, 0xEDFDD762E5D33665ULL, 0x7F14AD429FDC9BE1ULL, 0xF376E86EA8DF9590ULL, 
            0x83CEE3963E4F6E55ULL, 0x655A4767565D29E9ULL, 0x5016C6CF211861BEULL, 0x7EE43407226CDEDEULL, 
            0xA00CDF9C737888D8ULL, 0xC780C7B186D6317CULL, 0x295C849A9DF86120ULL, 0x921252CBCE671B58ULL
        },
        {
            0x8327367151030322ULL, 0xB2EA545F3DA3F8C0ULL, 0xF9596AA8E9F04BC1ULL, 0x97795D483DA1DDA8ULL, 
            0xC07CE13BD0C92F94ULL, 0xE825C208859BE2D3ULL, 0x39490B7A42BF7190ULL, 0xAA374ACCB9286893ULL, 
            0x2611551DDE6A81A8ULL, 0x15996CD3EC172F73ULL, 0xF58510E2386F3FAFULL, 0xFE1E7D83AE782132ULL, 
            0x675D38F67E6CF7E5ULL, 0x0514330566FD11DCULL, 0xEFC142D079337316ULL, 0x08DA33F20C01FEE6ULL, 
            0x5D917CCF568ED89FULL, 0x7F3D7A55009BB9E4ULL, 0xA54C1EEA7BAFC23EULL, 0x260960E729639ECDULL, 
            0x2E69EE2415E8FC2BULL, 0x11CBAB1AEB4F1C06ULL, 0x2C306FB0393834EDULL, 0xDBE67628B2675DB2ULL, 
            0x30450543E847011DULL, 0x502080CA04D7C5ADULL, 0xCF20F5A1A931EE19ULL, 0x0181EBB6BB701158ULL, 
            0x4A1A391C6D08C134ULL, 0x6A7D51228D15D717ULL, 0x1D03E0E786FCBBB6ULL, 0xB40D9A4C074795A1ULL
        },
        {
            0x581914F0C8CC3FE9ULL, 0x0C10314605C59BA9ULL, 0xFFC67EC1E6F2443EULL, 0x625C8FA180958669ULL, 
            0xD758D692FFB84CBBULL, 0x6BEB21D084F7AA18ULL, 0x8994F08993830EACULL, 0xAE11266148533AC2ULL, 
            0x4D3BD95DAD2E3B7FULL, 0xFA3527B9FA16D774ULL, 0xE54F36F9FF1BF649ULL, 0x3B9A3722D2DFDAF1ULL, 
            0xF98AC6E435D35112ULL, 0xE61AD6BB737E2C5AULL, 0x91D676BCC0C460CAULL, 0x44666FB93AAA9598ULL, 
            0xF3F375797A2EEF04ULL, 0xC33EC925BE4FA391ULL, 0x9253801B22AC8789ULL, 0x212E636194C192D3ULL, 
            0xC6CCAF22A235E902ULL, 0xE9B9F8B27932C04AULL, 0x310953ED6FFA04E5ULL, 0x1E9134685DD0CA62ULL, 
            0xB2EEEA18DA226D2FULL, 0x87A3277997075EC6ULL, 0x7FF28391721FB7DEULL, 0x2D31C8A2F426220FULL, 
            0xEED91F93463C31D9ULL, 0x61C5988E1E46C20EULL, 0xB900D0C7BF7BA228ULL, 0x9BD7E5A505F54920ULL
        },
        {
            0xD3122071EB5BDDE3ULL, 0x1516CB6362C223C6ULL, 0x148954D2E1D1D1DBULL, 0xC6B7E78C671DF4A2ULL, 
            0x2349F2352CDE758DULL, 0xC5261996A9F081F0ULL, 0x8693C7B716A891B5ULL, 0x438176A3CA68B18CULL, 
            0x552A31086FF281CAULL, 0x6AFCA38F93A053C9ULL, 0xDA776F741AE77E11ULL, 0xC68D0CB30858CEBFULL, 
            0x10DFF71B9C27A809ULL, 0x9F50EE53724F1B5EULL, 0x8CF4620744483FC8ULL, 0x263FEDACD8E7CD88ULL, 
            0x8DF4CE2508A66E84ULL, 0x2E45331E12833578ULL, 0x2070C223C6B3ABBEULL, 0x17D41D3DE9940B9EULL, 
            0x53415A65B41DAB8EULL, 0x12E071C64DC4CBB8ULL, 0xAFFB10A20437E5E4ULL, 0xACEB729D60A64F45ULL, 
            0xD9033991CC5A00D4ULL, 0xF52E096A86894ABEULL, 0xB914FC197910EA06ULL, 0xDCC4D5CB1E0BEE1EULL, 
            0x6DFC8EDE0ABF1204ULL, 0x91F6C160BC7EE47CULL, 0x7F804FAE078477AAULL, 0x2B40A6D4BED93443ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Gemma::kKeySpawnAConstants = {
    0x6122C97CF9EEF225ULL,
    0xB109D5EB03E273C0ULL,
    0xCE88D1A6ABAB6981ULL,
    0x6122C97CF9EEF225ULL,
    0xB109D5EB03E273C0ULL,
    0xCE88D1A6ABAB6981ULL,
    0x97E292447DDB0D05ULL,
    0xC53BB6E4AAC98265ULL,
    0x69,
    0xE5,
    0xF2,
    0xC9,
    0x71,
    0xCF,
    0xA0,
    0x95
};

const TwistDomainSaltSet TwistExpander_Gemma::kKeySpawnBSalts = {
    {
        {
            0xE8FBB4F515AAFA17ULL, 0x81BC9FDE134B8966ULL, 0xD7A6D8DC64309DA4ULL, 0x6BCF79D63E5AD10EULL, 
            0x76C076F31A96C318ULL, 0x95D463D8AB5968D7ULL, 0x38E8BAF1EB41777AULL, 0x2CF2DEF4F29E05A8ULL, 
            0x25067345664192F4ULL, 0xB078C05B353BEC97ULL, 0xAED76662D8790D34ULL, 0x7EB0387668DFC6DBULL, 
            0xF6F5983F9926AF37ULL, 0x488CE40AE1A99EC6ULL, 0x7997FF18B37FA3BAULL, 0x67333D28F329964AULL, 
            0x4902507A05AD0FF4ULL, 0x7D95205A790FC4BBULL, 0xE19700CFB9E66415ULL, 0x8922C2C5B3D387CBULL, 
            0xA85C69A6F2F9EFC7ULL, 0x925DD08C7F794418ULL, 0x60120684FE39A178ULL, 0xBDFC4A568344A5E8ULL, 
            0xE972D61C435A7956ULL, 0x60EEEBE3FD30176DULL, 0xB17124408E79E7C1ULL, 0x7EF5644C7F9ABF2EULL, 
            0x2235FC7EFC2154DCULL, 0x832FD45C38A69AEAULL, 0xC86DF5FEC6C3881FULL, 0x5A94F2AC2E72372AULL
        },
        {
            0xC691DF3C9043D20DULL, 0xF2EFB6B32C0BD763ULL, 0x3163B832ACBAB8CDULL, 0x0DD5460447F98534ULL, 
            0xF4DCB24338949505ULL, 0xB7CA6DFBB6F3B18FULL, 0x196757E209399004ULL, 0x1BAE4F8DD36AB800ULL, 
            0x8F84E248CD0ECC1BULL, 0xFB650E9F4B78A56FULL, 0x89C3DA6C4A192452ULL, 0x873AC3E657A6EAB6ULL, 
            0x9233BA1F0DA5C46DULL, 0x6C43674E275C5D29ULL, 0x0F6A168143E56A81ULL, 0xF2B9BF39F3396A81ULL, 
            0xC4ADC5A598FF23E6ULL, 0x83848D36FA2024F2ULL, 0x900978EECE699382ULL, 0x8980D676BFDEBA34ULL, 
            0x2B0989930C271EE1ULL, 0x84E89F994243DC8AULL, 0x541D2E4246A537FAULL, 0x2F4A698267A30BD9ULL, 
            0x2ECF6B1335ACC328ULL, 0x5929580C4759DD6AULL, 0xC11B29661D4CB0E6ULL, 0x9D377120056DA702ULL, 
            0x62B29B7320B89BDCULL, 0x4BAAC4D5B5E462B1ULL, 0x5B1C7D6893BE620BULL, 0x3645AF570FB5C631ULL
        },
        {
            0xC6595265F1439C15ULL, 0x5F25167598444D12ULL, 0x57F10343F3A53499ULL, 0xDAF5C630D5C90AAAULL, 
            0x958329475945D9EDULL, 0x9FDA0F44D326D0BBULL, 0x6B09242FFD506AEEULL, 0x2C756BB781B9F5F7ULL, 
            0xC0797AC0D2917390ULL, 0x38D0D30B2B1CD49FULL, 0xAE57FA5AAC36008FULL, 0x43AF7203505F7812ULL, 
            0x2C4407E5F10B036DULL, 0x05F8E731FB37DF52ULL, 0x558775750A5EC3F6ULL, 0xA1D8D99588006C18ULL, 
            0x8363E40DA463C574ULL, 0x704F9084D00C0EB1ULL, 0x0940EB82D72ED30BULL, 0xEBBDE6579D22E5CAULL, 
            0xDCA2EAF0E1C6F9D3ULL, 0xF5FA6D900011E58BULL, 0xE975353FCB41CD97ULL, 0x237153EBF79900D4ULL, 
            0x5E34AEB433CD8CC8ULL, 0x583F46E7996BA928ULL, 0xD8A9A28F239D9CE0ULL, 0xC48F244BC6869CB8ULL, 
            0xD2756EE5A8E4F890ULL, 0xAF9320A7C9524334ULL, 0x183179F1AA5E6EC8ULL, 0xFAF67A8AAC9B3C26ULL
        },
        {
            0xE323D0AE73FF651BULL, 0x7CBB1FEBAA26D0F6ULL, 0x3336E5892EC9C7B4ULL, 0x0DB2FDA7B8977DD8ULL, 
            0x28B36EC1CF839CAAULL, 0x7DC3537F99C79F1CULL, 0x644F471B836EA698ULL, 0x5E7CF3C17E65BC1CULL, 
            0xFD8C495130E0D297ULL, 0x02C71B3654FC173DULL, 0x0556DD2E4E3908FBULL, 0xF0777652461E5B2DULL, 
            0x7729992804BECB6AULL, 0x1703567F4905938CULL, 0xB5BE3BC00D25775FULL, 0x3A5C9929106DB77BULL, 
            0xF49C3ACE060715B1ULL, 0xFFFE0339C339763DULL, 0x37BCD9D3C607E946ULL, 0xBBC9437913EA767BULL, 
            0x53F401C1FDD26201ULL, 0x25AD87B5464E359EULL, 0xFB7925B6C3EEA958ULL, 0x87BF0E42444CF4ACULL, 
            0x6B49CC5C0CBDE5C7ULL, 0x06217C817CF9318DULL, 0x813F1078DA052AE0ULL, 0x2DA546C81F7C7ECDULL, 
            0xD1D074F87F29ECE4ULL, 0x7BAE9D0C607F3889ULL, 0x0646795975B1780BULL, 0xEA7425D5E24E701FULL
        },
        {
            0x8514B88F751C9B04ULL, 0x52A8AF1A575BDC0FULL, 0x817B93D77C4DA151ULL, 0xF714F0C73EC0D58CULL, 
            0x63053609334875A3ULL, 0x1935018208164F01ULL, 0xC35721168C1FCCAEULL, 0x3083A29E5C3C8FD2ULL, 
            0xD67797EF64B8E6CFULL, 0x9A9685352D8BEDA6ULL, 0xDF68882DEA819C63ULL, 0x576658D516D18D35ULL, 
            0x62A1D7BC14755F1FULL, 0xBCDD8DD63E1DF0E9ULL, 0x71338B7343AC6C01ULL, 0x430DA53B6D92A284ULL, 
            0x3D205B81996043D1ULL, 0x072B98D0E0CBEA07ULL, 0xD802EE96D115251AULL, 0xC7CDA1F48E74E811ULL, 
            0x3910F569DC28AD03ULL, 0xA303EAFB886AD335ULL, 0x78FF24A73B9F0DD1ULL, 0xE48BAA24BFE4D09EULL, 
            0xA65C1B337419F458ULL, 0x380B6D6B74C48CE3ULL, 0x0163D9BA57DE03C0ULL, 0x605F7E4DCDA2B0E2ULL, 
            0xC3CD71B2A7262B58ULL, 0x0A52B2231FA00193ULL, 0xE554C9559AB02933ULL, 0x71C3F170FD28B95FULL
        },
        {
            0x38A0E573CEF45E92ULL, 0x912818437DA9B9B6ULL, 0xD9F07493CC0E6AB8ULL, 0x41FB998877215446ULL, 
            0x52B08B551AEB3DFCULL, 0x6F17C9CE39771E7AULL, 0x80BFF38B0D701082ULL, 0x3B53781E687BA7A8ULL, 
            0x1A8B3C15B560CB85ULL, 0x2BBB44C017E23984ULL, 0x3FC8929B1B1DB184ULL, 0x93479FAA39CEB513ULL, 
            0xA10C86270AAEB0E9ULL, 0x83D8BB58F717A356ULL, 0xAA223377D899FBBDULL, 0x80AA995EED02FC2FULL, 
            0xC2E4E9C739E2392FULL, 0x1983494A722A4253ULL, 0x966C5118A47F8733ULL, 0x28F8C8C8CA3F4DF9ULL, 
            0xD80AB2F050BF5590ULL, 0x7964827E85BCB092ULL, 0x1B4F0D9D2B4FF20BULL, 0x114756EEC1C9412CULL, 
            0x9DD4A3E8A8643270ULL, 0xE84B048446A461B3ULL, 0xC87B19645B18A9EAULL, 0xEB5629601773F3F1ULL, 
            0x4C60155BF8BC1E01ULL, 0x9B41A30DEC79CC5BULL, 0xE71250E3515C5184ULL, 0x8B42615530105476ULL
        }
    },
    {
        {
            0xA736F54573E85157ULL, 0x42834A3815428183ULL, 0x2DFFD865C30F02A7ULL, 0x7F341CFBCA64B537ULL, 
            0xECEDB3647C3594F7ULL, 0x95574285E464364CULL, 0xAD2C51B3A879EEF8ULL, 0xB602605768108D6EULL, 
            0x0F98AC300810DE76ULL, 0x8C2D633ECB375990ULL, 0x8478094131798302ULL, 0x89F0B33F66B3DB9BULL, 
            0xF64E78DD7176E66CULL, 0xC87B1C2B5F89027BULL, 0x662130ADF1AAAE4CULL, 0xB1DD6EF0FA135FF6ULL, 
            0x919F59595774656EULL, 0x0EB119201FD55B97ULL, 0x3E9655A1C866F2D5ULL, 0x64A29761F37A6104ULL, 
            0xB5387A4F5411722DULL, 0x663C7BD331D48579ULL, 0x4311069A8B37CD76ULL, 0xCC01C272672FB723ULL, 
            0x2F70E47725829C67ULL, 0x43D8BE1071A1E4A4ULL, 0xD78A4FD47438A99BULL, 0x386FB0229C004105ULL, 
            0x5C1E3BF2ABF76CFCULL, 0x9619E48D8EC4C85EULL, 0x984AE12F0D625909ULL, 0xE964E594A80CDB67ULL
        },
        {
            0xE3010D44DEC5D026ULL, 0xCFA1C4A3BEA06160ULL, 0xFB4EB93C7EC01BB0ULL, 0x8B42D05C77E4E132ULL, 
            0x3B8A4420DD03EC7BULL, 0x0004F14A6290BB28ULL, 0xD86E3F0AFDDF58C9ULL, 0x6111A53B6B542517ULL, 
            0x4608B6A0ABBEFA12ULL, 0xF9AA5EE7B2E5F10AULL, 0x45F17D148E20ABBFULL, 0xC9677E0372B35470ULL, 
            0xCDE6AFF448D5F342ULL, 0xD55CEEF5E2973147ULL, 0xEC59BAE6DD3F89B6ULL, 0x5561D927B9A8C0D1ULL, 
            0x912C13FA26B3E433ULL, 0x2073802EF5E0F10CULL, 0xACE18E8CC1218FBEULL, 0xCBBD831BC260B67EULL, 
            0x5F9D4101C912ABECULL, 0x8A07A4257F73D752ULL, 0x59159EE40192DAC6ULL, 0xDAAF10E35B802F2EULL, 
            0x3ACB7CFE7ACAED4FULL, 0x13A90B658F18A406ULL, 0x2F885A45289BC0DDULL, 0xD98F785CA5EDF2BAULL, 
            0xA1DD9D0CBD37654BULL, 0xD9500558B1C46900ULL, 0x6E346A19F1C62BF1ULL, 0x259076AE8A862B6AULL
        },
        {
            0x774DEA2FBF9C1094ULL, 0xCA31E42E9AD26270ULL, 0xFFC37A40ECB110B3ULL, 0x88A54B208DF41C3EULL, 
            0xCA6941587071164EULL, 0xC34A31D2B7A7A41CULL, 0x8282407D17D0B613ULL, 0x23D2D4F4BDC802E5ULL, 
            0x7007FCFBCE0BBB1EULL, 0x451D065FFF898B55ULL, 0x705409A8ACFD8200ULL, 0x433F4EAEF3CF043BULL, 
            0x971C45A18A6241B4ULL, 0x956E97A199038CB1ULL, 0x67B3D4C86ECFE557ULL, 0xA68A749700CF8CE5ULL, 
            0xC546B8E4ACA9E49FULL, 0x6BBDC8783B934E4AULL, 0x7C177B177CB0E519ULL, 0xF3417E8051FAD412ULL, 
            0x741ADDF6BC2BBD6BULL, 0x0E6944D9BC005276ULL, 0x828617AB719B7DACULL, 0x411F6DAE214C7D62ULL, 
            0x07D4F96539DFA53BULL, 0xB3A19B4A007B2699ULL, 0xA632BE3B3E4D69E6ULL, 0x1C1911957A626BB6ULL, 
            0xD372A7C5D41DE638ULL, 0x23F9DB73422E9CF6ULL, 0x39BB0078445097B8ULL, 0x9D68BEC1A2BD83A7ULL
        },
        {
            0x4BB3239E36442783ULL, 0xFF6539F3CC9670E1ULL, 0x3FAA2CC762663EB5ULL, 0xC2E218E1709B48ECULL, 
            0xE8266CA9409D7E44ULL, 0xF4E3A2F90205EC68ULL, 0xC00A3C2DDF8AA8CEULL, 0x0B5E06E5B44014BAULL, 
            0x905527CC451CCD82ULL, 0x574306479F9B6B93ULL, 0xEC01167B2613200DULL, 0xC45A6C424B385F90ULL, 
            0xF086C3CCDE924C93ULL, 0x68F87C580F2A113CULL, 0x1D2085536ED64ADBULL, 0x1A9F8DEF60A5454FULL, 
            0x85DE2BC80E61AB3DULL, 0xF3A3AEB58703CF78ULL, 0xB4558DC48F5E0298ULL, 0x67DE4A3F937C27D1ULL, 
            0xBC580D615F556FB8ULL, 0x335D94FCA3067FBBULL, 0x89E503D224E6F965ULL, 0x50B2DAD9EAC07754ULL, 
            0x22BC08D2F6B0C5EEULL, 0xB3E0678BDE63E8BCULL, 0x2310E51F7D117D2FULL, 0x8A6E4F4EEFE9B838ULL, 
            0xEFFB822A6FA403A1ULL, 0x8B5D20D85897438EULL, 0x2E87CDD798004BE6ULL, 0x90A9E3F6D01655FEULL
        },
        {
            0xB1AA79CE58A2964FULL, 0x3B9B613478C61CAEULL, 0x33CA802C73D9688DULL, 0xBB25370160CF0C41ULL, 
            0xA200838D593E2EA6ULL, 0x8FCE2A771E5684C3ULL, 0xAE17A9864C5F0C96ULL, 0xAF46CD0152205B42ULL, 
            0xC48BCF181EA34D83ULL, 0xFF743B869C910687ULL, 0x10D92FACA76F697EULL, 0x0CF151C6A85CF08DULL, 
            0x2B3747331FCE7945ULL, 0x3B12BC620F67CE8BULL, 0xC2F47297FCD6B8D2ULL, 0x04D171951A7000D6ULL, 
            0x9A75A62CE7186741ULL, 0xF3BAAFBDC6CB3287ULL, 0xEC7EA6F44DE5E984ULL, 0x7699BD881674F909ULL, 
            0x3768BEA41B921AE5ULL, 0xD10DBB737B53012EULL, 0x0A2A8F99809DEC93ULL, 0x2A04E9D16DBAA840ULL, 
            0x97311772FC850883ULL, 0xDB459730F2B352D2ULL, 0xD19A30D297465392ULL, 0x687CB0DB3BD1697BULL, 
            0x9977ACC17FB7EF7AULL, 0xBD3E92B7F3180835ULL, 0x3D1EDBF70E8E8661ULL, 0xF7E51814820BFE6DULL
        },
        {
            0x7EB2B868BE905AACULL, 0xEC3AF5CF67BFCFEDULL, 0xCAB08BD65B212DF8ULL, 0xB9C59943BBA7F20AULL, 
            0xFD87AB9E44DFC18BULL, 0x5AEE3F931F361012ULL, 0xD191DE878ACF9E98ULL, 0xFFDB457CC862E34BULL, 
            0xA9E96EB685CDEC63ULL, 0xAEA2EC363FE294FAULL, 0xFCA7F47D746C679DULL, 0x7D0DBD0A18A5DCA8ULL, 
            0xD55C3212C09A1857ULL, 0x931ED7C42DAD9590ULL, 0x999ACC82CAC515F4ULL, 0x9CEA2562156E4291ULL, 
            0xC76218A0A6A52FD2ULL, 0x532A3F75C892AE91ULL, 0x72ECC7B6825B7239ULL, 0x40A012C44F30A2DCULL, 
            0xF141A917BA7D4D09ULL, 0x7CC16268BB74DD1FULL, 0x8C6CE8D78DA16FEDULL, 0xD16E51E52606CB44ULL, 
            0x6278B02779D951DBULL, 0x395EBC155B68E6D8ULL, 0x6275E8F4895F16CFULL, 0x7EB71F9FA9F3A8A7ULL, 
            0x077B0355BEC8AAA9ULL, 0x3A8C648C0FC801AAULL, 0x632F292F6C382EAEULL, 0x67E1165304A17848ULL
        }
    },
    {
        {
            0x8B64AF16957968A8ULL, 0x609E3A35BA714AE6ULL, 0x071002207B207C21ULL, 0x8B4389C659B0E546ULL, 
            0x8772399F11808FDCULL, 0x0D48426CA05391B9ULL, 0x22AEBAC9AF81A166ULL, 0x0A524C0BD7D82ADBULL, 
            0x2599C0E430B50D64ULL, 0x3FC101DBF85B5262ULL, 0x4E159B6151D1D855ULL, 0xB6B6D94C3C257850ULL, 
            0x57E0E806B52C1AF1ULL, 0x9AA98D56B3888770ULL, 0x8654FAE4AE53ADD2ULL, 0x69488333B7B4757FULL, 
            0xD0647264619ADB84ULL, 0xCDC949BB6D51114BULL, 0x0D6D5B3E6AC0DB54ULL, 0xD61ED5E708C0DFC7ULL, 
            0x2ED73F9ED3E36DFCULL, 0x5EAE7836BF3BE611ULL, 0xF2FE04F449DF6859ULL, 0xBA387E8F0FF22A3DULL, 
            0x734DC9E364B0B7ABULL, 0x074FBE01F86E1C23ULL, 0x3D34031E77DCE6B4ULL, 0x0632BE4262BDC2EFULL, 
            0xC4E88FD6AFC0DC09ULL, 0x1C838B98D894EE34ULL, 0x46629B8FF4424465ULL, 0x5ABBED740D33143DULL
        },
        {
            0x9D5420A879AE944BULL, 0xD8DD3CC18306698CULL, 0xF45189F87C06CEACULL, 0x622CDDD8D77B64A1ULL, 
            0xD9586C1E600B0F80ULL, 0x0C460C985732CC26ULL, 0x95135AFD4F4F1526ULL, 0x97DB4D56E1714379ULL, 
            0xC2B28F6C61E3F4DFULL, 0xA04B7E5AF95C8612ULL, 0x12B1A93712439A43ULL, 0xCE8E91B06B8F5AB1ULL, 
            0x0A1194BA176B107DULL, 0x284B1B4A66BF167DULL, 0x34CA479BDDBDC13EULL, 0xFB17B177E70F2C16ULL, 
            0x1B3EBB12F28546DEULL, 0x0EEAD9C3D9ADCEC4ULL, 0x8794EC2CB654ADD5ULL, 0xFA539F1AA55858BDULL, 
            0x7826588C5C24F6A1ULL, 0xD0E767531A2E7094ULL, 0x54EF3E6BAF37170BULL, 0xD0F35295FB983C6AULL, 
            0x34035D111D00D275ULL, 0x89D7F832C37A7E05ULL, 0x11735EBC0B33153DULL, 0x19096D4B3DA69A79ULL, 
            0x91A68E579B988C2CULL, 0x81A49B841DCB19B8ULL, 0x3DD7BA118A5919B2ULL, 0x36A4C0320A98A855ULL
        },
        {
            0x5BB9A5D527B1328BULL, 0xA2286F800BFCA9DDULL, 0x73E06B6230390583ULL, 0x2F7C5E34FF11AA80ULL, 
            0xE6D1CD8378885870ULL, 0x724A69EABBD5D470ULL, 0x526E32ECCCAF44FFULL, 0xDE95F0D8B3D205EBULL, 
            0x2A47CBEEC0274A81ULL, 0xE9A7876A05CBDE13ULL, 0xFFAA2220552FA111ULL, 0x158D1C89C72F0FE9ULL, 
            0x522AF29B97BEA468ULL, 0x282207C28ACD5633ULL, 0x25C423286E6BDD01ULL, 0x17AD63733300D4A6ULL, 
            0x181CF15BBB574775ULL, 0x89AFA8F4E79FE580ULL, 0xF59242514238FCE3ULL, 0xC06EB893F2A4B052ULL, 
            0xA3F30DB4DFAB45C8ULL, 0x234ECA5A71A8B1DEULL, 0x976C5478767416C1ULL, 0x292AD6CAAAB0DF59ULL, 
            0x0710080BB7B74074ULL, 0xB34A290888C2F259ULL, 0x1F7F989E80EC8ECDULL, 0xBFAA5E4E6A741BBEULL, 
            0x76351971F809CB93ULL, 0x6F5D226CB76891F9ULL, 0xC298F5B6862E4AE9ULL, 0x068012E97580185FULL
        },
        {
            0x758238935C1EF38BULL, 0x8E326BB6D1DCFF4DULL, 0xB2C82B05B762BD43ULL, 0x3B7A3200A3C395E3ULL, 
            0x77E02AE8BFFB2BB6ULL, 0xA24E34F3EA6B53EFULL, 0x2292E7EC3BF3C57DULL, 0xD806E8E7521E2785ULL, 
            0x29C3B9AE88529C2BULL, 0x903D25C95AD41707ULL, 0x6B2AF40121C13433ULL, 0x062ACE531DFA8B77ULL, 
            0x2EF6FA0495AA0B93ULL, 0xF6005ED79279E0DBULL, 0x3FC1E6B17BF91A4FULL, 0xA5AE8266636DB816ULL, 
            0x7EDF43006793FC50ULL, 0xD3853CDD27BB0393ULL, 0x1D0A3A6EFE60EFA8ULL, 0x928DE80404995D7CULL, 
            0x1224848F4B79325CULL, 0xA5966FD9F909089AULL, 0xE36F85C7F0796071ULL, 0x8DCB5508092AEA20ULL, 
            0xE44B4C70E78CEB36ULL, 0x6D182D559CA5E818ULL, 0x9212520525A8C324ULL, 0x32E66026F5C8BD2EULL, 
            0xE4C1CD12B7CC742CULL, 0x39F6E86BF196F9ECULL, 0x625C8A3F377518D5ULL, 0x3E548A7DE6ED1405ULL
        },
        {
            0x36578A1C8B2141B8ULL, 0x4F729FD3013A7716ULL, 0xB799DECAC2773613ULL, 0x1D11A96805D9F4CAULL, 
            0xBDBEE4989FE30E5AULL, 0x576A654D18544C76ULL, 0x733B0340B8805256ULL, 0xBD2D5C04BC4ABEF9ULL, 
            0xAF3A7940D564BAF5ULL, 0x1EC4E115527D352FULL, 0x247DDD138D52DA45ULL, 0x7937926A842FDE16ULL, 
            0xE565678F01CB4457ULL, 0x47E3323E75910E94ULL, 0x6D43FE786F38A834ULL, 0xA474EEDE38B1FF13ULL, 
            0xAC3BB5C7F4153F5AULL, 0xA3681D3A19167C48ULL, 0x95B868A2FFED860BULL, 0x9C619FBE8AEB3E46ULL, 
            0x3BC9401E51D25B6DULL, 0x562C5C19E5243093ULL, 0xE8BEFF28799B97B6ULL, 0x8C80D494A2C15686ULL, 
            0x42997D160DAC102DULL, 0xEE07FEFF21D881BDULL, 0x38E26F31ADE1576BULL, 0xD135A2A719A91563ULL, 
            0x23B9DDDA87984C21ULL, 0xF102649C3C3B0428ULL, 0x41FDF73250E2236DULL, 0x14C96BAA654151FCULL
        },
        {
            0xB06A6AD2F92E5332ULL, 0x6C85CDE71FA24B82ULL, 0x6EB89D364E7F2C77ULL, 0xB8BE3FE0B15406C3ULL, 
            0x809FA9C60511C844ULL, 0x1B6882FDB3DDD446ULL, 0x23F41ECC99EBE665ULL, 0x67F798BE5DF85AAFULL, 
            0x8B42CBFBFF5035A0ULL, 0x54396C04F08E3904ULL, 0xBA3F1C885E1CA314ULL, 0xA71824E6779FA71AULL, 
            0x21D1ED71E30B24B7ULL, 0x6098171E88DCB688ULL, 0xFD8B215C9EBFFB2AULL, 0xB9EEBFA9633ACDA9ULL, 
            0x99F04DAC5B2385FAULL, 0x4F95DB771EF44011ULL, 0x3CACE5188BE0497BULL, 0x31934E5DDB231764ULL, 
            0xC792BC652BE1C55AULL, 0xC1A64361F8D5D325ULL, 0x8544002C3DE6195BULL, 0xEF88BFACF0817A4AULL, 
            0x8E9B9FB7D5E1B256ULL, 0xEA1A62C28683BFDFULL, 0x64FD0916EE418F0FULL, 0xAF0B0153C0D49A9DULL, 
            0x8ABA553DC88D6D1AULL, 0x424719F85FF40A2DULL, 0xA23A8FB6FD9B70C8ULL, 0x94CF050D4177F31AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Gemma::kKeySpawnBConstants = {
    0x59FF65F20268FC49ULL,
    0x534417467F84C992ULL,
    0x61EB8F8ADC3FE449ULL,
    0x59FF65F20268FC49ULL,
    0x534417467F84C992ULL,
    0x61EB8F8ADC3FE449ULL,
    0x0E4B201B3EC6BA18ULL,
    0x47EBEE122DD49EF1ULL,
    0xDB,
    0x1C,
    0x84,
    0xF4,
    0xE4,
    0x3B,
    0x0F,
    0x56
};

const TwistDomainSaltSet TwistExpander_Gemma::kSeedSalts = {
    {
        {
            0x66758D61FE83E5F8ULL, 0x2328FA6088168114ULL, 0xB40A74220603254CULL, 0x42A3306DB9898237ULL, 
            0x6C44921AAED9FBAAULL, 0xD3D147A0EA97D7F5ULL, 0x3ED5AA60C8C88172ULL, 0xD7CD0493B803FCA5ULL, 
            0xCC86AD16AAF4C466ULL, 0x6D8D4992E126B6DCULL, 0x371834365EA75369ULL, 0x00E64FF0BA4D52E1ULL, 
            0x7FB60DF9B65F47ECULL, 0x31A24041CBE8E348ULL, 0x7DC3C20882360F71ULL, 0xCA4E4F64AB5A7959ULL, 
            0x63CA73353B0DD05AULL, 0x603A13A34245F68BULL, 0xE4E0C496B2E483EAULL, 0x4904427AD5D39880ULL, 
            0x50B5BF43AEC7EF2FULL, 0x332BA77ADAD0479FULL, 0xC44D261D06443253ULL, 0x95858D9747DED469ULL, 
            0x8CD27119242EC69BULL, 0xBED696B0895D8CF4ULL, 0xBD53A556B79B6460ULL, 0x39111C8C86AA4C0FULL, 
            0xE228C2E0D765E295ULL, 0x7063256E3C8A367BULL, 0x5F8FA863EC5C144EULL, 0x899AC48CB8E6E59AULL
        },
        {
            0x0A89741E30D9E230ULL, 0x4AAD914E712E4703ULL, 0xC6C77158B45BF528ULL, 0xABDEB0D98716A4C9ULL, 
            0x210B5062688F1CBFULL, 0xD7DA7FDE5188F65AULL, 0x60F0C70E223A9735ULL, 0x70C0A1B5E09857A9ULL, 
            0x0DC06AAB85524784ULL, 0x7E9D24263E82467CULL, 0xA2C2C8B7D4841E24ULL, 0x3FE2259F8415BA21ULL, 
            0xDAD98F1A06F870B0ULL, 0x0494E704483D100DULL, 0x4B51D6C3847B9C48ULL, 0xC456E6450EFD500DULL, 
            0x03B5CB64C82FE7F8ULL, 0x52E8365BDB383AC5ULL, 0xB1E79A347F122FD8ULL, 0x6D05086EF8E6B300ULL, 
            0xFFA86ABC52C85CC8ULL, 0x4FDBE767F2AB4701ULL, 0x0D8C0D6B2A870A33ULL, 0x1CD18680FFD673C8ULL, 
            0x419D3949677117A6ULL, 0xC7902F3E8F3208F8ULL, 0x400676A37BD1FAECULL, 0xACCC4E5254D38B0EULL, 
            0xE416CF5103DC26B2ULL, 0xE4C081BB9EFA4828ULL, 0xFF200355111D8F3DULL, 0xB25D1E4E24FD5B2BULL
        },
        {
            0xF69FB5D4BA094B0BULL, 0x171A612722FA15C9ULL, 0x40A7A80A0CE3FFC4ULL, 0x8250D99F19E31E80ULL, 
            0x440EDFECFDED3885ULL, 0x8B9518AE145FBF15ULL, 0x1301325584C6052CULL, 0x27151C90FC158942ULL, 
            0xA1FA5B2E0838A4B0ULL, 0x8E301BADA68840DEULL, 0x91E49C19E87F0E1BULL, 0x3448DFBA88B644CFULL, 
            0xFB2C18F21A7D500CULL, 0xD9C34536B9F35100ULL, 0x2667EB8DB203C1AEULL, 0x5786646BD762DDE3ULL, 
            0x1E4C0658C8FDC16DULL, 0x6CD734BEBEFCDDA6ULL, 0xC029218103A1E47DULL, 0x02A1D1DBD10555F5ULL, 
            0xFA62B196ABC023DFULL, 0x3743FE41105ED06FULL, 0xC8A1C69ED30EAE8BULL, 0x54C6F4C3720A4921ULL, 
            0x400E3FC7C8CB4F55ULL, 0xBCD50A37D3958F65ULL, 0xDC17961E41A26A42ULL, 0xB40CD697F662358BULL, 
            0xE43BEE202E699444ULL, 0x829318565E975590ULL, 0xE3AA938B24C46260ULL, 0x973EDB0CEAAD3E18ULL
        },
        {
            0xF447C202867917B9ULL, 0x34E76A1AA7BC17ACULL, 0x4196513344E9A176ULL, 0xE02A27DED8871456ULL, 
            0xEF8621CE2C380E34ULL, 0xDA414F9D07EA4C84ULL, 0x7027682DA895CD23ULL, 0x5E193B84B559672AULL, 
            0xEBC1B274AB603D78ULL, 0xBE0E477AD7C4A5FDULL, 0x1E97D97FE36AAA4CULL, 0x37F05772897DAA44ULL, 
            0x03C2EB734D719961ULL, 0xD27E16EDFF56D30FULL, 0x9EEC1E2BE09A0761ULL, 0x780487F264FBCF66ULL, 
            0xCD26E56B03571F0FULL, 0x471834A4B9088670ULL, 0x38C5BF845C41FAA9ULL, 0x9ABAA1D71FD413A3ULL, 
            0x21C54EFCFFCFAEE9ULL, 0x6ED35E8756D4363AULL, 0xC6B681A793AA38ECULL, 0xCBFE47C28A27AB4BULL, 
            0xE4FD51FEF7B67749ULL, 0x8DBDFC5AA6996E44ULL, 0x08F2FDEB7E12F7EFULL, 0x259C95B841DA3160ULL, 
            0x146D351B3EC83C64ULL, 0xF23E1B1213994982ULL, 0xB0BE4849E53205E1ULL, 0x8F0CFCB880D6A380ULL
        },
        {
            0x2B46757496BBC150ULL, 0xC293865ADE7A718CULL, 0xA9B0AEF37B235228ULL, 0x178C1362BE3B8E6AULL, 
            0x43EE26FC45E783A6ULL, 0xCDB19C8C2037E9E2ULL, 0xD2DB858703B0FF6AULL, 0x46F0E3CAAC3FA4C9ULL, 
            0xB664FAF9D841E88EULL, 0xAD31A6C02C9CF607ULL, 0x8D3BC484CA57CC70ULL, 0x4B0BB2E0153A677EULL, 
            0xD93DDC3121AABE4BULL, 0x36716561020336FBULL, 0x808E782D15CD3C37ULL, 0x8C9EF1C7208A45B5ULL, 
            0x5802581E03340FE8ULL, 0xA71949E022729F1BULL, 0x05CDDB40D3A398AAULL, 0x15755E48BBE3E57AULL, 
            0x34F509F83AFB4724ULL, 0x44B759184E3FD910ULL, 0xEAD2349C09838876ULL, 0x212A426BA1577D93ULL, 
            0xC9C12620B4BBBAEEULL, 0x4FD5B920BC4AEF27ULL, 0x5E2F05DCC058E518ULL, 0x548F9D3AFF5807B9ULL, 
            0xCF04B2BF102148A8ULL, 0x0A6CF69EA05D0C93ULL, 0xC91902D896DC1A42ULL, 0xF24D4D82EBD12ECAULL
        },
        {
            0x2B116CF95938B631ULL, 0x65AE2305376DC805ULL, 0x40D0EC21F9DA3C41ULL, 0xCD8518F9ED92EECAULL, 
            0x97E52766B38B7639ULL, 0x2247A9FB2D33EE60ULL, 0x534D08D64509177DULL, 0xC78F6C83EDF2D5EDULL, 
            0x9B4992377AA7EE2AULL, 0xC1F8D7E6B34EA359ULL, 0x718B612C31039181ULL, 0x4FC13EC92A1C923AULL, 
            0xD872D01157C34BD0ULL, 0xBA970529AFFD46E4ULL, 0x135387B006A1FF7BULL, 0x223F937B092294A0ULL, 
            0xA81ADD53C4B8003DULL, 0xEBFCD335BDBEAB40ULL, 0xD966101EAC7C1863ULL, 0xFAB1F5AA2AFADE99ULL, 
            0x28B267D77D9DD5B7ULL, 0x2FE02DC39A1DB83DULL, 0xF54CF33F186706D1ULL, 0x875D319DA4205C8BULL, 
            0x3C4CA22C37C723C1ULL, 0xE29D3945BD0D07BCULL, 0xB4072F503913C1A8ULL, 0xEF0466FCF1A3A231ULL, 
            0x77709E48D5B96512ULL, 0x8AFDF6BC6CF10340ULL, 0xF429EAD205AC563CULL, 0x8363A467C956A3D7ULL
        }
    },
    {
        {
            0xB4DB190E526AA7A7ULL, 0x4102F1D6F248F209ULL, 0x150EC364287AAE12ULL, 0x12D74A81D47E7058ULL, 
            0x53FDF980BB8DC35CULL, 0x785BC36C5F748FFAULL, 0xBCA26BD81179F66CULL, 0x6ACDD995787B74F2ULL, 
            0x7868B700B30F7208ULL, 0x7C475D0B676A964DULL, 0x7DF9BD58AF87BBF0ULL, 0xC7D2796AE2594C67ULL, 
            0xA27093834FD85F09ULL, 0x54F79BA652FB1F96ULL, 0x4C6085A170F409E0ULL, 0x637AB461C96351F0ULL, 
            0xDF8EA451FEC71A50ULL, 0xEB079A56894A6867ULL, 0x1D3496632981679DULL, 0x63B77A4876BE9A92ULL, 
            0xC341E45568F5FFB4ULL, 0x3E0E1846BEBEFDA2ULL, 0x96C204A3345DB8CDULL, 0x0DDC5839A46AEFB2ULL, 
            0xAD4E231528B87B4FULL, 0x6D8ED30A4AB732E2ULL, 0xC60D250081155CF4ULL, 0xCB039DA18972362FULL, 
            0x55289C66A4A6DE5DULL, 0x3D7D28F10E3CA4F6ULL, 0xA2A1CB2BDAEC56F2ULL, 0xCE907566C380F353ULL
        },
        {
            0x4C9473F63D31C849ULL, 0xF41EC9D0E6C5A3FFULL, 0x524007FBDAD88A71ULL, 0x6606B83C2577EE2EULL, 
            0x26C4A95E8D620E4FULL, 0x6827047976C96233ULL, 0x5DD960E347BFFF1FULL, 0x1368011109EEF35DULL, 
            0x587B490465DBB460ULL, 0x03ADCF7DDA22417CULL, 0xB8439A91512E755EULL, 0x788D3EA9C5D075A7ULL, 
            0x7A891E6501FF4623ULL, 0x232C3C586F6C2A6CULL, 0xA9782B9A5A1C56F6ULL, 0x1E2B48884815B213ULL, 
            0x740825FD30470AEBULL, 0x2CA4B92ADCCBFCCCULL, 0x1E3DFE46DA6F6E24ULL, 0xEB51DC2528930306ULL, 
            0xF5503D81D1AEDF2CULL, 0x88DD9DB63717E2DFULL, 0x25021C1C1BA439E4ULL, 0x395222F050B4E8BCULL, 
            0x6522D94B146653C4ULL, 0x561CEBEAE4BC2A74ULL, 0x70ADDB6F65D8496EULL, 0xB6C91B2463E96AD1ULL, 
            0xDBC85E9F018CDB8EULL, 0x3E241E2B2738C012ULL, 0xA33C7B1290FFDF96ULL, 0xD6881A6C81890086ULL
        },
        {
            0xDB8B9CEEC336252FULL, 0xE1C7B68387DDEFE2ULL, 0x50BF51C54DFE5C53ULL, 0x64497203A3177375ULL, 
            0xF761BFC7F36C835FULL, 0xFA2191BB12037F0CULL, 0xBFE1EFD286138E97ULL, 0x6A7D53D326A27564ULL, 
            0x14F3B357172117BFULL, 0xD645A4C99835CEF0ULL, 0x8031A3473B0F8778ULL, 0x94B89C3551A1905DULL, 
            0xE6D333C10CFB0E55ULL, 0xA81BF9435CE389B4ULL, 0x7338443012C6534FULL, 0xEC6A7209BD1B3A31ULL, 
            0xE3D07937795CA882ULL, 0xC69D35531A6BD1B4ULL, 0x8EE51BB332D9E6AEULL, 0x9643BED27EFF8100ULL, 
            0x858AC61C2F77F935ULL, 0x29882953630EFDCBULL, 0x8003F2DF17EB463EULL, 0x41991C4F72CE788FULL, 
            0x6115B737A039E3AAULL, 0xC96EF4E6017ABAF4ULL, 0x2CC26E2BAEA4C1D2ULL, 0x406246E4614E8846ULL, 
            0xFC40C0EB79FDAC7DULL, 0xF923858B2ED7F52BULL, 0x553E861C9818B3D5ULL, 0xAD18E2E06247CDC6ULL
        },
        {
            0x3392C0464732337EULL, 0xD24156DDDB33127DULL, 0xB577FF06EDA09B0AULL, 0xE9ED5662FB93641DULL, 
            0x835DBB24BBB14A56ULL, 0x8AC8122FBABDE61AULL, 0x0C879EAD00BCDDCEULL, 0x81A8093C0CDA0ABCULL, 
            0x07F6EBA3F71175ABULL, 0xF19D02605DDA2628ULL, 0xED21A38778CADB11ULL, 0x382AF06AE82346AEULL, 
            0x74DDFF9ED3B0D010ULL, 0x6BC54D9AC0E4B412ULL, 0xB8149E2673D82103ULL, 0x2E409F246E819C65ULL, 
            0xA0AA08C7B7B2859AULL, 0x46528E678BA5B102ULL, 0xF8D98D3602B353D8ULL, 0x138CA42D6F368574ULL, 
            0x40EDE2053060EBA1ULL, 0xD5665E48CC64D8F9ULL, 0xF8AEEDAD452561A9ULL, 0x0EBF579C5ED7331BULL, 
            0x81408E8E6DDB3731ULL, 0x60582EF07FB9902DULL, 0x2DBDA2A1EF4C342FULL, 0x9075A5F71A987262ULL, 
            0x8C8434C20FD731ECULL, 0x6C1195552028CBEFULL, 0x456FFD733EB6B0BAULL, 0xB1C05915891AE14BULL
        },
        {
            0xECEF5E2D398E7099ULL, 0xB25D789883C01204ULL, 0x47C8FC2C6F519BDAULL, 0xD0EC4FD0C5146A8CULL, 
            0xAB4193D707B60086ULL, 0xD21DF3DF52A3A477ULL, 0x0E14CF1044750F87ULL, 0x8C8E11054212E9D9ULL, 
            0x6EB7651E5B5E2E28ULL, 0xE631871CE8F301ACULL, 0xCD0223D1194FED78ULL, 0x6A2AEA5FF6DC4B76ULL, 
            0x63E7635D37A07A78ULL, 0xCB70CEBF202EC598ULL, 0x69505A1E17AA7E40ULL, 0x6CDFBE263A9EC208ULL, 
            0x3F5A95BF86C45582ULL, 0xCA6B5EDB1121C31DULL, 0xE8C5F10A6D1FF3DDULL, 0x3CD908A93B16A1C7ULL, 
            0xD2E41BBFF90380AFULL, 0x5321CCD1287E9521ULL, 0x1492687334DA799FULL, 0x05C884FA4C9CAC51ULL, 
            0x910ED720987F3ABDULL, 0xB414BF942D50B8ACULL, 0xC33B6958D0BB37D2ULL, 0x5E284E45331CDE7FULL, 
            0x1FACC28088648CA5ULL, 0xB15AEF1B841D8A7DULL, 0xE2C730E03708CB8CULL, 0xD355CF51955FD3EDULL
        },
        {
            0xA9C1F32466A28B90ULL, 0x15A7F304639B0BC7ULL, 0x59C0111FAE76218AULL, 0xEBE3786B1453766FULL, 
            0xB532480108E81E3BULL, 0xF4083B19C758E061ULL, 0x404DE2CA3C6660DEULL, 0x0387A81D29733694ULL, 
            0x3F1553E4BA566778ULL, 0xD6C5527511565CBCULL, 0x258ED26D77BED481ULL, 0xCE6CC9C115CD27B5ULL, 
            0xA5194F9346867973ULL, 0x8E382CA22B53CA10ULL, 0xD1A0F9D6EF51B83EULL, 0x025B9BECF5462ABFULL, 
            0xFD88A810690EFB35ULL, 0x853C4DB6A9C5FE96ULL, 0x86BEDEEE5D26E065ULL, 0xE235DFE62148214DULL, 
            0x5041D7D4CA0BF1D6ULL, 0xD1934EA367829B40ULL, 0xAA2F392C634680E0ULL, 0xE8DEC913CDAA8283ULL, 
            0x781E6670506B6EA1ULL, 0x72C76E88A12C6C96ULL, 0x725FE8EA10717097ULL, 0x68484CCF97995828ULL, 
            0xF10F1711D69CC06CULL, 0xE98EC4B1C63256B9ULL, 0x03D6C085FFE3236CULL, 0xD585E54C2F237F66ULL
        }
    },
    {
        {
            0xF5D53543EFB92F64ULL, 0xA1A65DC2E3303228ULL, 0xE1ACD968DB46F2E9ULL, 0x1317DAE27D5C1D6CULL, 
            0x17AAF5EC5D0BEDCEULL, 0x4E8F43F2F3CED600ULL, 0xF81568AC84409105ULL, 0x5118446CBA01F6CFULL, 
            0xFD6194FD200E36EBULL, 0xD5F642C4829A0047ULL, 0x588641CE90E86717ULL, 0x4FFFD9D217A5AB36ULL, 
            0x4C5071AA81071C87ULL, 0xBE6FF9ED127B5A68ULL, 0xAE48924AF1796259ULL, 0x2B15518F88443D0CULL, 
            0x591B5707ECFCC810ULL, 0xF3F62E8E39B7D3E0ULL, 0xFDED594E10063701ULL, 0x326CB0FBBF58DAD0ULL, 
            0xCA13C75E436B9763ULL, 0x97AE5DE5FAE5A8BBULL, 0xE32B5B86A4283EE7ULL, 0xA3C11B9290163495ULL, 
            0xB3BAF0CF31E80751ULL, 0xAC968A025DBD8599ULL, 0xE6EC1978E0377625ULL, 0xD5B9F16A56B1DC36ULL, 
            0x36A56DDD6FB836EFULL, 0x1ADDE3639A9F48DDULL, 0x7AA1AFDB23E6893DULL, 0x487A23FC2D5882F1ULL
        },
        {
            0xB6FD554E2503EF08ULL, 0xB761DCCB64F23E32ULL, 0x991710E6A83D720EULL, 0xF72A4BBD43B905F4ULL, 
            0x35B79EE8189D59E8ULL, 0x780BBAB5183191C5ULL, 0x251AEC776F96FE7CULL, 0xF2C2E787D2EB96EAULL, 
            0x65D87DA69E0F0BD3ULL, 0x637042BE8E3145B5ULL, 0x9992847C34451C69ULL, 0xBDC88CCEF920E101ULL, 
            0x786C916DC2877B8DULL, 0x3C54897722CCFA63ULL, 0x8B6CC87241811BC4ULL, 0x568ABF3AB7DC0B3BULL, 
            0xBAA5DBD8206A01E2ULL, 0xC1972781235107CFULL, 0x0E8EFC40B1DCFDDAULL, 0x266C008861710AE6ULL, 
            0xBDE22C8CAA0A7A63ULL, 0xE22119E286FF73B4ULL, 0xE6A460260E3D150AULL, 0xE2AEE4CB47C58399ULL, 
            0x8B081F50CF352180ULL, 0x07F6788F814A07CAULL, 0xFED817AF00B87E70ULL, 0x0A06C443C31FA72CULL, 
            0x847A0575636710D2ULL, 0x5197CE181A477648ULL, 0xB7BE395D94523E9AULL, 0x85BDE519E4AE0802ULL
        },
        {
            0x7441458F98BF6003ULL, 0x009809D91ECE4EA5ULL, 0x457EC381E0B9D91EULL, 0xE90C83D92C0B6639ULL, 
            0xF3CCF13EFA43EB4BULL, 0xCFA71F5BEA90875EULL, 0x267C4EA07234A8F1ULL, 0x50BF31949B4E85A1ULL, 
            0x52CFFA29C5FF46ABULL, 0x1BBEC611CA8C7ADFULL, 0xD532E620584EAEF9ULL, 0x2D6027732CE21D36ULL, 
            0x9015715DEFB6405BULL, 0x2CAB57198A6AEA12ULL, 0xE7D2320FA582A292ULL, 0xD39176B2D6B7F951ULL, 
            0xBF488BEFA734E5B4ULL, 0xD020E584939ECFEBULL, 0xBCC00339EAE5FA0AULL, 0xD3609CCF52B5B49EULL, 
            0x53966EEE7DC7BA7EULL, 0xD4D8D8A695D731D7ULL, 0xD8792395B2ADC3ACULL, 0xE54F3B8F042C3C19ULL, 
            0x8CB7F7A365C59192ULL, 0x3B15064C4BAD3329ULL, 0x7A984F8BB4E3CF19ULL, 0x9488016796F851D6ULL, 
            0x5E7B3233398E402DULL, 0x2E0FF14517D4FD4EULL, 0xA071F7F57FFD6D3BULL, 0x5A01C35611B2C9E2ULL
        },
        {
            0xEBAF7E19BFC5F3BAULL, 0x86F9EF148C7AFD93ULL, 0x935963EACB4CD52AULL, 0xAF13C09E983CEAE9ULL, 
            0x040E5C740CC8F01EULL, 0x2BB1B14E0461B8B1ULL, 0x562A447252D4E5B3ULL, 0x4C40099131ABEA1AULL, 
            0x83810BE63176B746ULL, 0xD0C606D588F1FD69ULL, 0xE824B80AEFABEA5CULL, 0x9DF820A3FD46AC36ULL, 
            0xEB2CC5470E4265AAULL, 0x5B31349CEB1742FBULL, 0x20422CC7D6C11DCAULL, 0x1966A8E665B984FCULL, 
            0xD2598735534B4C89ULL, 0x0BAF36790ABE0366ULL, 0x4A78206C25D2F6A9ULL, 0xDC8BD726206DBBBEULL, 
            0x6934B627FA92983DULL, 0xC28310A585A25F4CULL, 0xAE0232C6D81D2885ULL, 0xA54A64D571CD735DULL, 
            0x8F60CB91E71AD9B7ULL, 0x1C96542DBBA1CF14ULL, 0xEFAF9FB0A88846EAULL, 0x76567744FF0811D2ULL, 
            0x36A345EF5CA95B3FULL, 0xB84853891CD75D86ULL, 0xA16695BE242A1F9EULL, 0x38A8C63F94E81E7BULL
        },
        {
            0x9E3B96D9D4A7C3DAULL, 0xA6740C0B782BF198ULL, 0x809C92D4519C35F8ULL, 0x92A23E901B261650ULL, 
            0xDC79EE64532E4D9AULL, 0xD5A3C7AD1B8079DCULL, 0xA4D90C79804A42BEULL, 0x277E3011B3FD398EULL, 
            0xAF19D956440C63D5ULL, 0x18FD0CA83C0832F2ULL, 0x303F57B67035C75AULL, 0x0D075AE59BB69751ULL, 
            0x3A6D92C44F6C5463ULL, 0x71260859D208FB82ULL, 0xD2549D5A4E8C7808ULL, 0x6AD85DD2ED01434EULL, 
            0x3C663E50345DF6F3ULL, 0xBFB9C6616EEAE4C9ULL, 0xDA26838A49E96AD4ULL, 0x06F1BD6B7A364711ULL, 
            0xE521EE27932937FFULL, 0x5B4F7E9CB37C9C05ULL, 0x9D867AA0352651CBULL, 0xE49665B0507E211BULL, 
            0x09ABEA56CC9FB0C8ULL, 0x42503FCFEB4CAAACULL, 0x43B73BA91B937D3AULL, 0xF338D26CB2A750ABULL, 
            0x91F91B3D59534FECULL, 0x117FD45B8F49EC9EULL, 0x91F8B330080EB731ULL, 0xC8B7C0EF9EDF450DULL
        },
        {
            0x61A6266448515D93ULL, 0xCBCE64FC801CCE8CULL, 0x38946C0DE7C74B10ULL, 0x9E6EF380C59DEA76ULL, 
            0xD5DB1EF0B868F3EFULL, 0x4E417AE91D6255C6ULL, 0x1473A01EEDE1BF76ULL, 0x3E6F6DE898B5ED8CULL, 
            0xD74A326829981387ULL, 0x11AAD344AEFFB027ULL, 0x0F9EFCB38700F639ULL, 0x3E4EC86241D5CAE7ULL, 
            0xC564C017089DFC25ULL, 0x87DE9D3DB2B3D2D4ULL, 0x56890AA3DF07A745ULL, 0x9C28703A9AD8400CULL, 
            0x5A221A0EDC2780B9ULL, 0x161848B8898164DCULL, 0x31AFF2DA0B5EAC96ULL, 0x0F4124E3281FE636ULL, 
            0xB6E8B1AEDD2D8D6EULL, 0xCE6C9CD9EA305468ULL, 0xDE4734153C625F10ULL, 0xE1A7687A42C1DB49ULL, 
            0xD45F67490C47C6C0ULL, 0x493E7EE389575415ULL, 0xF93875472B24ECA3ULL, 0x63AB0193939CB394ULL, 
            0x444CC2F4C52C0B3BULL, 0x1C205564DA85C115ULL, 0x9CA8D30ECF14F5E5ULL, 0x9904905BCFB64D27ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Gemma::kSeedConstants = {
    0x90C8481654001D79ULL,
    0x7E6CC111971B161CULL,
    0x403F6564365627DFULL,
    0x90C8481654001D79ULL,
    0x7E6CC111971B161CULL,
    0x403F6564365627DFULL,
    0xBF563A4AEFC252DFULL,
    0x49C3F4721F518545ULL,
    0x96,
    0x0A,
    0xCC,
    0xB6,
    0x77,
    0x28,
    0x6B,
    0xEF
};

const TwistDomainSaltSet TwistExpander_Gemma::kTwistSalts = {
    {
        {
            0xCC5145C564E6B824ULL, 0x90981C7EDBF5F5EDULL, 0xD76D70799E1768B4ULL, 0xCEDC1BF80611A558ULL, 
            0x3A8DE8FA70D834ABULL, 0xF152ACA7114AD6D8ULL, 0x525EEC9F206D8CF7ULL, 0xFD53D67A6B31EAAAULL, 
            0x7248C9FA29E4907AULL, 0xC2764F68AD8FD4D3ULL, 0xF4A846CFC7F8BB8BULL, 0x094DB4462C6A7006ULL, 
            0x913EDA2FD761849EULL, 0x3BDDAFFFE58191DAULL, 0x63887562C9A18DB3ULL, 0xF6EDD8120B824C6DULL, 
            0x44A9F971017A55BCULL, 0xF38FE6F13B725FB8ULL, 0xBCF3F2CEA5666BBDULL, 0xD749154C49CFDC89ULL, 
            0x4E01B67C7E999230ULL, 0x78D03C4F38E1DC3BULL, 0x6289D51CCDF5E6C7ULL, 0x62FE1ED5076750A2ULL, 
            0x8306EEB009D35F78ULL, 0x03B1AE016D576AE1ULL, 0xCCE83E7AB9B74C92ULL, 0xE5F86CF3F270D7F3ULL, 
            0x2634C855EE5FA58BULL, 0xB4B70B70A0C4B928ULL, 0xF87E5B55D0E8780AULL, 0xC3CE7D68348A4EF6ULL
        },
        {
            0x612B6768FEEC29B1ULL, 0xEDF99BF3EE2E9584ULL, 0x7E00AC09FDF34B57ULL, 0x56863F09E49B8EE6ULL, 
            0xAFA270214882D113ULL, 0x34646B0A85397BCAULL, 0xCA6E3BB9657B6EF3ULL, 0x79CEC6FA5A115128ULL, 
            0x61EC65DE687AEE67ULL, 0x3908F8E289270290ULL, 0x25A09EF11D5AF850ULL, 0xEA329D6453ABEFB2ULL, 
            0xEFD74BFE10BC80C8ULL, 0xE0CE40BF414232EBULL, 0x007F063A33AC00CCULL, 0x416AB045C57F8DEEULL, 
            0xB0C78997326B5F8BULL, 0x9380C2DF297750AEULL, 0x5685FFCA381108B7ULL, 0x286759840820A43AULL, 
            0xB1F266D2460A3243ULL, 0xFF8FCB877BB2A01BULL, 0x2DDB7972AD4B22DDULL, 0x272DBDEDCEFEFE67ULL, 
            0x122EAD10F6B2D140ULL, 0xD077CBA57B3683DBULL, 0xF38DDE880AEC4BC1ULL, 0x13E5D9D08F66E4ACULL, 
            0xC27FED683774089DULL, 0xA6F6FCBF8221AF2FULL, 0x04CA3DA4C4564F7EULL, 0x051A690A58856AFBULL
        },
        {
            0x4C9482886246C5C7ULL, 0x00AB05E8E8D17E4BULL, 0x030BDB9D9E5C7AB4ULL, 0xFA8D4A5B78246115ULL, 
            0x58FCE44D57F149AEULL, 0xAF24F3456CD8D5ACULL, 0x51CBC5C617174F1EULL, 0x91ED7BC9E96017CFULL, 
            0xAA2A3EA281FCFB3AULL, 0x36F05F606BB08E12ULL, 0xC46E6571C91ED059ULL, 0xFEFF04A09C0639B2ULL, 
            0x94059D660799A2CCULL, 0x086FDF80146FD2BEULL, 0x224488C9DF504992ULL, 0x3B3A49F8770557B1ULL, 
            0x03AEFE07E08C9CA8ULL, 0xFAB655674ADA78C1ULL, 0x92B6E1FDA0A17642ULL, 0x7299F54418DB6326ULL, 
            0x9CA428204C0623E4ULL, 0x0C8C0BC1C13F8A18ULL, 0xBE3DC244898DE497ULL, 0xD5B56CF74467B8ECULL, 
            0x8ACAC540BF38F778ULL, 0xEC8EF683E66ACC83ULL, 0x0CD9A4ACB0AB68CAULL, 0x752185671DD1F9C1ULL, 
            0xA09AED85D94AE169ULL, 0x79019DF2AE741FD8ULL, 0x330DAFB56816ED52ULL, 0x3153BA0EB00E262EULL
        },
        {
            0x148977E4535F8B07ULL, 0x935143F051E7C3A3ULL, 0x349726681BC7C6BCULL, 0x8691AC8BAC720EBDULL, 
            0x33EE3CD38864676AULL, 0x5367F1D7F9CE77BAULL, 0xB3B7D0F099171AA2ULL, 0xD272F4CEE2F5C973ULL, 
            0x50964E6AAF3EEB24ULL, 0x74E07963DE9C9100ULL, 0xF82273B2C27BB4D9ULL, 0x10A850181B99E86CULL, 
            0xD7C0C8FF29E8088EULL, 0x5AB5396F35AF5697ULL, 0xB1BA67B48D410209ULL, 0x0A6602B37F512644ULL, 
            0xBD3080D84DD48E63ULL, 0x3DF6F7171C12CB35ULL, 0xF7F7045B31588857ULL, 0xE7B90C4A9D643EA1ULL, 
            0x5E42780A469A248AULL, 0xB4FD4B85F3474F2AULL, 0x596F6D17CD81224BULL, 0x6F3782C29AE5AD15ULL, 
            0xC2DE33EC918C263AULL, 0x062ED9B07AB05BD3ULL, 0x1E001B395047A708ULL, 0xADC3753852DCA548ULL, 
            0x216F300316964AEDULL, 0x2F0DD0E3BAC4BB63ULL, 0x7ACB4B0EC1C107C1ULL, 0xFDED316D96C476FBULL
        },
        {
            0xA742F7B48ACD71F1ULL, 0xB5FEB619AE70D32DULL, 0x5FABC68128B4920DULL, 0x17F53A24C1A56A8CULL, 
            0x6AD14F98744CE7A6ULL, 0x6328449F2D5B4173ULL, 0xFC8360978FC9C1E7ULL, 0x0B40150351E3BAB6ULL, 
            0x51F9E5CD3D083BADULL, 0x09BD385E9932B3A6ULL, 0xE9E5974D7D711FD7ULL, 0xCAB911ECA5932891ULL, 
            0x770DC53F9384172CULL, 0x4B67F2F8E5A45963ULL, 0x475BF459DBDC93DBULL, 0x887DE892EFFD79F6ULL, 
            0xF7BEFEF65B534B90ULL, 0x8864D27E69E8C9F5ULL, 0xFADEBF9D2502A118ULL, 0x0C4D6B2E394A1D61ULL, 
            0xEBDD17D026BD867AULL, 0x1F1ABAAC980ADFC4ULL, 0x9EDB170013585165ULL, 0x9AA282CD3A9C94BFULL, 
            0xAB93E932900FA76FULL, 0x6A4FA063C9D0C032ULL, 0xC200CB56DBECC954ULL, 0x5D5E1BB2E50F5733ULL, 
            0x416216FB39A69AECULL, 0x5D97C1C60C0CDD2DULL, 0x37566B41358BE642ULL, 0x50DF2A4CE4987785ULL
        },
        {
            0x087C1091FC653884ULL, 0x6123099DA762E0BDULL, 0xA001B6BB0F57D3CCULL, 0x44670A9F20888922ULL, 
            0x60CD9E24550245DCULL, 0x511EEE4F283700F7ULL, 0x47642CA1BB7FE0ACULL, 0xD86AFD1744F18C37ULL, 
            0xEDA95B33B48B41B5ULL, 0xE6F1FA136652D914ULL, 0xB7CD52BB92189612ULL, 0x5327CE147A57FD17ULL, 
            0xA06F663DA0DD7552ULL, 0xAD706F4CCE0019C7ULL, 0x7B9162999C078045ULL, 0x860F6BD06483251EULL, 
            0x3F71CE7ECC4E1F7AULL, 0x1B61FB956D91D0CAULL, 0x645E9BA341314ECDULL, 0x10D90FA4F171EAE6ULL, 
            0xD9B0BEBF0FB4048CULL, 0xF5CF4DAE8FA6B765ULL, 0xE8CD4E02F87F4BBDULL, 0xBB0BADF2F8FEF021ULL, 
            0xA3F7B3979D2C7B5EULL, 0x93AA37433B1FB805ULL, 0xF0DE5D364FC545EDULL, 0x823330CAAC4336AEULL, 
            0x5EDE03AE8E8B3D55ULL, 0x134001E6CAB186F4ULL, 0xE8838464DED2EB4AULL, 0x58B893AAC45DDAB4ULL
        }
    },
    {
        {
            0x71C96502434E0CB1ULL, 0x2E7AECB036081E3FULL, 0xE0741558E4E5682FULL, 0xA9A90DE3E18BE4B8ULL, 
            0xAA569A0EEE437100ULL, 0x70645DDD14AF5E9FULL, 0x1887AE50CE17AED4ULL, 0x0EE7CCB39397C290ULL, 
            0xFD96EBD1264B3B90ULL, 0x85480CDBCBC2286AULL, 0x2E9A99B886FD9837ULL, 0xB84C3F40E5CF04BBULL, 
            0xD7CA96823031E57AULL, 0x6B73DE75599365BDULL, 0xE1A4677113D63389ULL, 0x8551481B386AE802ULL, 
            0x2C8D1E60046A01DFULL, 0xE0D86CF8B3AB382DULL, 0xEF49E55E52B8E73AULL, 0x8A3D671E87EF9F21ULL, 
            0xEA4DCE7D20EB1FA4ULL, 0x1EDC5278193F18E4ULL, 0xC7C96CD10D4CDBEDULL, 0xC74CFA162B5EBEA2ULL, 
            0xEB107AC4AECCF071ULL, 0xD63C37473DF32C58ULL, 0x758135BA8A634E7AULL, 0x22292D698BDF9799ULL, 
            0xCE6DCCD4D7A0FFF9ULL, 0x202F5E57C3423D86ULL, 0x01CE8FD48DA2EEDAULL, 0xD7DCF8A410F8B56CULL
        },
        {
            0xA060C461AB8BF03DULL, 0x0780EDA1279EC86DULL, 0x643EB7BB17FB2156ULL, 0xE5CAA6489CC63CC6ULL, 
            0x54CF04D1DC4F2EB2ULL, 0xCE7F1D785A6AA514ULL, 0x21C8FA84650EC012ULL, 0x6DF90FE1FF014C91ULL, 
            0xEA27664D93318FBCULL, 0xF1498DA7946FA9CCULL, 0xB94229B7FFCE2A20ULL, 0xF6832FB888816B5CULL, 
            0x46E14DEB8090047CULL, 0x9210F9F818A60F2CULL, 0xC0BCB93ECE505A73ULL, 0x66E2451FB5FF8B9AULL, 
            0x1106CE37A556669CULL, 0x85E564749EE0BA3FULL, 0x034A86D48C32BCC6ULL, 0x9A4FF87EB9745C37ULL, 
            0x59EE792BCC8541ACULL, 0xD673B7567CE11979ULL, 0x80C94EF32FE63DAEULL, 0x4A137D1E49D0AEB6ULL, 
            0xC2396FA8F2471A42ULL, 0x9870936B68E9A3F1ULL, 0x0D0038394BA31B2DULL, 0x4425C6222099744EULL, 
            0x883AEF3C126E8B25ULL, 0xA106355C28A9F8C8ULL, 0x5A44CCF294B735DEULL, 0x44134B2D698E2EB7ULL
        },
        {
            0xE9F3A8379340AB5EULL, 0xDFEFC36FEF2FEE3CULL, 0x29C69B22C1917822ULL, 0xB1433BB3D9831332ULL, 
            0x1470C303A19588D0ULL, 0x53E5A97707ABA019ULL, 0x669C238F577AE53EULL, 0x823DCC746CC17003ULL, 
            0x880BD43CFAC288E5ULL, 0x48043B3672479823ULL, 0x92928DEFF91DE9C8ULL, 0x9145D30A47F185A4ULL, 
            0x013A04F5213BABC4ULL, 0xD1E8B40FA52787C8ULL, 0x457D2D99337BF072ULL, 0x6721F0FE3967C026ULL, 
            0x40EA06A5928FA598ULL, 0x68B87B10AAB1A5C0ULL, 0xB4F647313120DD7DULL, 0x80D2DD89FF4F2692ULL, 
            0x89A61596C18404FEULL, 0xC6F10D43F34FE29AULL, 0x7F8522096B9104DEULL, 0x69E2C4D8F865B80BULL, 
            0x22B212D55DF89805ULL, 0x3C59955361138A7FULL, 0x7B4F02279A15A70AULL, 0xDE8EAFB970C65244ULL, 
            0x854466F12B39EB3CULL, 0x7EE06E2696B7F915ULL, 0x019D385A8FF119FAULL, 0xBF7EA3F4297511B8ULL
        },
        {
            0xEC4513808D4A2D58ULL, 0x809A07F1F6FC9ED6ULL, 0x4854F35008C12288ULL, 0xCCCFE093C11ACE83ULL, 
            0x47FF009C9312989DULL, 0x18EFA216BADA6F2CULL, 0x3D69A2D8DAF611B8ULL, 0x3C6116967FDC1641ULL, 
            0xB2C45BEDB5850231ULL, 0x58E3B9FFA15D2920ULL, 0xED1C643F288F18E4ULL, 0xD3832A9F31FDB35BULL, 
            0xFF350F392EFCD8B6ULL, 0xDCCE3035F3F7E76BULL, 0x1BF0CAB01F3025A4ULL, 0xF7AF5D04730ACBC1ULL, 
            0xED7F6C67475EFC10ULL, 0xF83D1EF0A8D6659CULL, 0x0207F7E56A504234ULL, 0x96423E489230F27BULL, 
            0x573ED9DD0B5DDBB1ULL, 0x17DFC2E7474C2FE7ULL, 0xB508F68A70CD5E8DULL, 0x269CE106112343CBULL, 
            0xFDA6F684BC7B92C7ULL, 0xA55596D91F60D50DULL, 0x23E8D24DF1DADFABULL, 0x14C4B7BB50652385ULL, 
            0x3BA7A03CA29EDD1AULL, 0x3A9661043FDED82BULL, 0x6EA8D2FA53B16392ULL, 0x7D7792B0F31983A7ULL
        },
        {
            0x0AF9E447812BDAADULL, 0x59B3C868B14AF549ULL, 0x7FD0510D7D192DA7ULL, 0x6B3C498D64D13A68ULL, 
            0x824D8E38B38BC8B6ULL, 0x53AA6E984DC4C3D5ULL, 0x2A68262F68E69D42ULL, 0xB9BD369A21AADED4ULL, 
            0x2D45B75BB2B72F62ULL, 0xD1A5664610F86233ULL, 0x9AEB1FB437F55902ULL, 0x2178D727EE6EE85DULL, 
            0x00B022E3CAC4FF1FULL, 0x6C586106B5B06177ULL, 0xE889862587ACCA0FULL, 0x8623CD9248C1939FULL, 
            0x1D04E7413B9332AEULL, 0xAA69E89AC7B9F3DAULL, 0xA074615BD6B6C5D9ULL, 0xA2E787FB7C60E1CCULL, 
            0x8F2B51D880FA75CAULL, 0xB33B80EB09A8A60AULL, 0x4A1F2717E9E51DB0ULL, 0xDD823EA39F9CC4F3ULL, 
            0x7B588EEB515C3718ULL, 0xFEFCCBD61DE65BE3ULL, 0x9CDB02E76B5DDA76ULL, 0xFFEDE901DA20A0E7ULL, 
            0xF62986183E9560E8ULL, 0x4CB68FEDDB78187FULL, 0x14A6771C2EEB42DDULL, 0x8421976F8B432051ULL
        },
        {
            0x445CEC8CC3FE07FDULL, 0xDE558A926C84DACBULL, 0xCCF064B567A0B962ULL, 0xE71730FBA3DD7376ULL, 
            0x94C814606AF10AC5ULL, 0x3A8905339388AFC9ULL, 0x4DAD82930A3BB80DULL, 0x968C9BE1A8E7AEB8ULL, 
            0xD912FB4998705BE2ULL, 0x688676467AF56864ULL, 0x74AEFFE9C9DC28C6ULL, 0x53BCE685344C0A19ULL, 
            0x2629B1ACE4E1E09DULL, 0xD3243BEC1D5F1FB6ULL, 0x7BCF29FE33AD276EULL, 0x0C3CE8A57A385EDFULL, 
            0x32E07238189545E3ULL, 0xD26DB07FCE123C92ULL, 0x5EAE73E3C376340CULL, 0x5015E1B9D6C0FB64ULL, 
            0x8DA6E1AC30AF546DULL, 0x1ACBBBD5C5B1F774ULL, 0xE9E03DF8A5C0BAA8ULL, 0x29D44AA2B6C1920FULL, 
            0x3874B73B4BCE3960ULL, 0x8F2E6CA477B7CB5BULL, 0x306FB473EFD9ABB5ULL, 0x74B3D7E087BE13A5ULL, 
            0x45C215052793BA85ULL, 0x3F93E2165575F019ULL, 0x996FD5427DA181E5ULL, 0x76311D7F05E1C7C0ULL
        }
    },
    {
        {
            0x516CAB529C3DE013ULL, 0xBB99882D90210144ULL, 0x023B5F31697C64C0ULL, 0x9952DC0BC63FD489ULL, 
            0x646F9247F6B3057BULL, 0x3F35AAB71DDACCFFULL, 0x2057564F8D7B423AULL, 0xC64E560FB244DDCAULL, 
            0x56AA83F5AC74C17DULL, 0x97A7DA1802031F38ULL, 0xBA6CC959BF3AE247ULL, 0x395B97E30064CC51ULL, 
            0x42F77EC60357D755ULL, 0x6640E924B66732F2ULL, 0xFF256D094EFD382AULL, 0xA9C145E72E872313ULL, 
            0x2E1B7A13F90A6ACFULL, 0x5E4309B3A718669AULL, 0x01E4CBF9275CD69DULL, 0x398690110B3B6486ULL, 
            0x8AE8862A44184D22ULL, 0xF1DF5022174812E4ULL, 0x9808235A20F7DA72ULL, 0x355DA83FA86DA372ULL, 
            0x57EAAEB244201789ULL, 0x1CD1AF1E4AFC459DULL, 0xE32053B1B0D1B359ULL, 0xFB1D91AC8D5EB7DDULL, 
            0xCD782D7E87D587F0ULL, 0x4FABBB654264D0EDULL, 0x5029DED56ADBD159ULL, 0x6D803D2B862180C0ULL
        },
        {
            0x0C8DC41013FB1644ULL, 0xB2BE140E79A2F357ULL, 0x23B8A0E00F97497BULL, 0x4BCC0EB09B219A10ULL, 
            0xFA7C80F668C5BEF8ULL, 0x9108D86629111640ULL, 0x041CD51916D42C76ULL, 0x815C75B8306D5DFAULL, 
            0x92C6B25CFA3560F4ULL, 0x4CA10ED466F978A7ULL, 0x87A8C615E68B2E73ULL, 0x8E78723786252CA5ULL, 
            0x9DC62495E02370F9ULL, 0xC7127D45537CB438ULL, 0xD235B68D19AFFF9EULL, 0x5526A251BFCDA7D5ULL, 
            0xB666E88FE9F48189ULL, 0xCCCA0156BBDA35E4ULL, 0xA893C1C7EF32A128ULL, 0xF51F475506EA104CULL, 
            0x0C4F4D9B8724CF56ULL, 0xEC8C2254051CF8B6ULL, 0x2A16C802DE78EB48ULL, 0x114EB9B204B2DE12ULL, 
            0x706EFBD343D3D463ULL, 0x3717AEE4BE34F9F0ULL, 0xEE11F32EAA31B1AAULL, 0x038E63699F8C7259ULL, 
            0x0264BBC1403AEA00ULL, 0xC80F2D34005EAEDBULL, 0xF0B3818C2E2E98ADULL, 0x2085FFE6DF6BF353ULL
        },
        {
            0xE9A0595531CA7CB0ULL, 0xA5F380DB7D99DFE8ULL, 0x151BB250C92F08E3ULL, 0x2F7D88C70477812FULL, 
            0x7269CFF71FCDBC48ULL, 0x6F1AD9A75FC9B177ULL, 0x3CF2D2B91FD268A0ULL, 0x34BCF53795EABCF3ULL, 
            0xBBB440B57A9E549EULL, 0xC02BA057E5499562ULL, 0xBFF4E420108307DCULL, 0x255F0EFB4AB0637DULL, 
            0x82895AA586DFAAF9ULL, 0xB8A8CEA99C308291ULL, 0xBE9553F5D96EC56BULL, 0xEBB8127B12AD7A64ULL, 
            0x15EE81D3CBCC9154ULL, 0xEC62C28F8F506C24ULL, 0x03D5E75856435DB9ULL, 0xDB16E4C00D9413E2ULL, 
            0xDECCFCCB3CC0915CULL, 0x4080AFB30D527369ULL, 0xE80741096B1FA944ULL, 0x62254C24117E793FULL, 
            0x67BEFAD5FD1BAE37ULL, 0xB8868C5C063E3087ULL, 0x9FDD68D7C565B39EULL, 0x7C628C4E61AFAD3DULL, 
            0x99E760B595765DE9ULL, 0xC6F3BF1C20CC8D35ULL, 0x3FDE2C6CB369D6EAULL, 0x38E44F577A279034ULL
        },
        {
            0x87928A8DDE6AE4B2ULL, 0x23F8E288790A92CEULL, 0x5CC2D0C505BFCD64ULL, 0x737E6260E997CFADULL, 
            0x24DC0682E903C5ADULL, 0x0AAD5068B8A9B35CULL, 0x470E4E90E197EEDBULL, 0xA67072A2B12097FAULL, 
            0x2C993189CC6CE763ULL, 0x91AF8ECFC725E40DULL, 0x515898342170C2F6ULL, 0x288E1DF49E8E08FAULL, 
            0xB3FB5F0B6F171889ULL, 0x737C633E4ABEF5E8ULL, 0xAB52723FAF22191EULL, 0x653D3F1D5BB11862ULL, 
            0x0157C59EA06A5C0FULL, 0x70FD461306D25F2CULL, 0x064985A82D8EFD4BULL, 0xC5355C6E37323C1BULL, 
            0x4FE5C4FAD6A03ACEULL, 0x0AF3C83E680B6EE3ULL, 0xF424E071591EE47CULL, 0xE0B7E420C52ADD47ULL, 
            0x723C911B58F222D4ULL, 0x32A7B5D037D7BDF5ULL, 0xDA4599ED2B9B5445ULL, 0xF7C9CBBF23357D74ULL, 
            0x468523F41CAEE859ULL, 0xFF44AAF6B409214BULL, 0x568624BAA91B50F9ULL, 0xB635169F26C50149ULL
        },
        {
            0x9A0E3CE938A83503ULL, 0x543D30A9600D559BULL, 0x2581FD2CD20159AEULL, 0x238C831B31CD773EULL, 
            0x300319CFFC78719BULL, 0xC3DB7B4AC19C3B7FULL, 0x8D77EB7C191ABD85ULL, 0x927CF8F855D839B3ULL, 
            0x241D1030BB2267A0ULL, 0xAEA3E0CC7B2DB362ULL, 0x0DC8116DA9FCDEC4ULL, 0x08B65006D009B277ULL, 
            0x90F4EED7346D1FCBULL, 0xD6D80B48789BFD69ULL, 0x360D868811834F56ULL, 0x6D12E0397185BC0DULL, 
            0x7FCBCFEC02E5D7CAULL, 0x108818A8B6E8DF13ULL, 0xE93C1E5D62826A0FULL, 0xDEC113BF8782F3D0ULL, 
            0x4CBD602131A5A754ULL, 0xDA347480102015AEULL, 0xB1CA992D5FF5A812ULL, 0x7C4D44E2588CED2EULL, 
            0xA9A4A63901F73176ULL, 0x7457CBAB01AD59F8ULL, 0x337D41BC99D45E53ULL, 0xC0E300E349EBB075ULL, 
            0xC740DBB882D08634ULL, 0x20699A9F1F20C479ULL, 0x9ED24E212B46A226ULL, 0xFF92B9327134A79CULL
        },
        {
            0x93BF8AE758EB5671ULL, 0x4F8C92BF42CD6A25ULL, 0xAB8E720CD02663DEULL, 0xC2C4A9505999D9B2ULL, 
            0x0863FAA28ABD3D86ULL, 0xC362855728577E52ULL, 0x85888CE50D39B059ULL, 0x6F16CF3665737210ULL, 
            0x5A89F268819B852AULL, 0x5096706DD321A000ULL, 0x8111E1FAC3EC1FA2ULL, 0x437FE42EDE5417EBULL, 
            0xDBF3C02DC48EE4C6ULL, 0xB14D90DC8DBA38C3ULL, 0xC9D487A49522BD2FULL, 0xF83E5AD91974C602ULL, 
            0xD4843885E46E9A81ULL, 0xC8B1EF1DB11663DEULL, 0x7C016DDA04832EA2ULL, 0xF604A2D0BA223465ULL, 
            0x8D186D7F60023B44ULL, 0x97B1BA1B0654C247ULL, 0x07A2B4E2F9CCB94AULL, 0xAE82A93DC150507EULL, 
            0x4A7D3405003E18CCULL, 0x48D35FD5A7860A6DULL, 0x160D42C095B93B26ULL, 0x5C89F259BA5A2680ULL, 
            0xEE2E21B4EA97FF3BULL, 0x60F534EE181CDCEFULL, 0x20EC02C777597F00ULL, 0x60643887E8D1BEA2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Gemma::kTwistConstants = {
    0x9A9DE69804675B1BULL,
    0x02552C92D82EE357ULL,
    0xBC0CB102A40254A2ULL,
    0x9A9DE69804675B1BULL,
    0x02552C92D82EE357ULL,
    0xBC0CB102A40254A2ULL,
    0x3AB6E34BFBB1A6F9ULL,
    0xEC5A2B7A797C10BAULL,
    0x6A,
    0x92,
    0x25,
    0x04,
    0xE9,
    0x80,
    0xFA,
    0x2B
};

