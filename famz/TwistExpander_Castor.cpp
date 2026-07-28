#include "TwistExpander_Castor.hpp"
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

TwistExpander_Castor::TwistExpander_Castor()
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

void TwistExpander_Castor::KDF_A(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Castor_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Castor_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Castor_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Castor_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Castor::KDF_B(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Castor_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Castor_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Castor_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Castor_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Castor::KDF_C(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Castor_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Castor_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Castor_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Castor_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Castor::KDF_D(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Castor_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Castor_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Castor_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Castor_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Castor::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x9697AE0B42948816ULL;
    std::uint64_t aIngress = 0x8BD76B36FEEE7F18ULL;
    std::uint64_t aCarry = 0xEB2C9E78760D2BF0ULL;

    std::uint64_t aWandererA = 0xA0764FA331790AFEULL;
    std::uint64_t aWandererB = 0x8AAFB90113E14581ULL;
    std::uint64_t aWandererC = 0xD6523DA40ED3997FULL;
    std::uint64_t aWandererD = 0x9A5598F019E678B8ULL;
    std::uint64_t aWandererE = 0xE9B381E7ED059DA8ULL;
    std::uint64_t aWandererF = 0x9710B4F5E9E2751EULL;
    std::uint64_t aWandererG = 0xCD311EF3E22CFAD7ULL;
    std::uint64_t aWandererH = 0xE585C5DBD3C77ECDULL;
    std::uint64_t aWandererI = 0x8CB56B128EFA0613ULL;
    std::uint64_t aWandererJ = 0xF68F156C2474AB17ULL;
    std::uint64_t aWandererK = 0x9B35AB9C453384B7ULL;

    //
    // KeyRotate A
    //
    aPrevious = 0x875AF7145C548C3BULL;
    aIngress = 0xEA8E2E70D57A65EEULL;
    aCarry = 0xC4A00E99E5E6A30EULL;
    aWandererA = 0xCCF108A98A7CBE91ULL;
    aWandererB = 0xFA9826F959D8BD60ULL;
    aWandererC = 0xB48312045A3B2C16ULL;
    aWandererD = 0xD65797E73927AC4CULL;
    aWandererE = 0x94C627944EC34379ULL;
    aWandererF = 0xDD3EAE9A81435F95ULL;
    aWandererG = 0x9EC1137B377E8C13ULL;
    aWandererH = 0xBA72AECD2574E581ULL;
    aWandererI = 0xC9533D9A387DB20DULL;
    aWandererJ = 0xAC6C2614A74EA437ULL;
    aWandererK = 0xEA2C21AC4B9889D5ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateAConstants), &(pWorkSpace->mDomainBundle.mKeyRotateASalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xC10C46BA6CCD69EEULL;
    aIngress = 0xF6F0492492480607ULL;
    aCarry = 0xCC9767CAAE1AF012ULL;
    aWandererA = 0x8ED5A78E616B7968ULL;
    aWandererB = 0xA3A51303D01B4F29ULL;
    aWandererC = 0xDB8B23A7FF7F1819ULL;
    aWandererD = 0xD85E876A10952033ULL;
    aWandererE = 0xE4149C6B1E0C5292ULL;
    aWandererF = 0x80513168AB12C515ULL;
    aWandererG = 0xBAB3E4A5CFAA6B5CULL;
    aWandererH = 0xBFC61B6722E4C153ULL;
    aWandererI = 0x9D4142411F7854EBULL;
    aWandererJ = 0xDF37E078480A51A2ULL;
    aWandererK = 0xC9259BBEA3D8B90DULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants), &(pWorkSpace->mDomainBundle.mKeyRotateBSalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xC50EB5ED207D1A91ULL;
    aIngress = 0xE9D1B861D405BB43ULL;
    aCarry = 0x8620F9D0C1E9F928ULL;
    aWandererA = 0xF8A7D71CD534A45AULL;
    aWandererB = 0xBD74159D050F3B86ULL;
    aWandererC = 0xB0E6C56D10BBED68ULL;
    aWandererD = 0xF4CEE1282A3C565CULL;
    aWandererE = 0xEB6B86D8DF7E9DE6ULL;
    aWandererF = 0xB9C66AD7C7CE1A81ULL;
    aWandererG = 0xFF10DF91F8A2D686ULL;
    aWandererH = 0x830FEFB4D0414D1AULL;
    aWandererI = 0xD206FA342B8352FAULL;
    aWandererJ = 0xE2E036D5462E07D9ULL;
    aWandererK = 0xB4E6D0AD4BB0548CULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnAConstants), &(mDomainBundleInbuilt.mKeySpawnASalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants), &(pWorkSpace->mDomainBundle.mKeySpawnASalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeySpawnAConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xAC24EF68374C61E6ULL;
    aIngress = 0xABF1FAA51926D380ULL;
    aCarry = 0x8C2D1144679B2A91ULL;
    aWandererA = 0xF8C8C559E08082B5ULL;
    aWandererB = 0x83110C55D0163A21ULL;
    aWandererC = 0xE3824EBD62C337DFULL;
    aWandererD = 0xA37D180DD71CA327ULL;
    aWandererE = 0xB572F14BA37D1379ULL;
    aWandererF = 0xE8BEA67071B118D4ULL;
    aWandererG = 0xDDA9FABE71B1C4D4ULL;
    aWandererH = 0xA5EA8EC353E3390DULL;
    aWandererI = 0x9B9DF6A09C2F5334ULL;
    aWandererJ = 0xE7D3D18AFFC6A9E4ULL;
    aWandererK = 0xA4DB2CF86C4F5616ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnBConstants), &(mDomainBundleInbuilt.mKeySpawnBSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneB, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xA2DF93A1098B081DULL;
    aIngress = 0xEC7A6F8CF9F7DABAULL;
    aCarry = 0xB5FCD394B9072B9EULL;
    aWandererA = 0xC7F01BAB036F029BULL;
    aWandererB = 0xD3FCEB5E5B684F42ULL;
    aWandererC = 0xC34BAD9FB35CFEE3ULL;
    aWandererD = 0xB4387FC382DCEE46ULL;
    aWandererE = 0xFF096DEF2FC497D3ULL;
    aWandererF = 0xC88960565E286BF0ULL;
    aWandererG = 0xB4DBF49962E1F26EULL;
    aWandererH = 0xB38E82568C3BDCDFULL;
    aWandererI = 0x96314C07B589B5A1ULL;
    aWandererJ = 0xCC9C300FB077D21AULL;
    aWandererK = 0xD8AF95CE40258B25ULL;
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mTwistConstants), &(pWorkSpace->mDomainBundle.mTwistSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mTwistSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0x9FC407DCDE8D5519ULL;
    aIngress = 0xCD56C3ECD82E1545ULL;
    aCarry = 0xBB554D5F2672A50CULL;
    aWandererA = 0x984D3AAE210499C4ULL;
    aWandererB = 0xF671E47E99EC4EBDULL;
    aWandererC = 0x96F804CFB4E4BBCFULL;
    aWandererD = 0x8B2D07C88465DAC7ULL;
    aWandererE = 0xBEA2A153D63FAA05ULL;
    aWandererF = 0xB46C87AFF208D31BULL;
    aWandererG = 0x97B4EB29734A9492ULL;
    aWandererH = 0xD5F71A039FB308F6ULL;
    aWandererI = 0x93066CF4928F484AULL;
    aWandererJ = 0xE68033E24959A403ULL;
    aWandererK = 0x99E926ED6A66D03DULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mSeedConstants), &(pWorkSpace->mDomainBundle.mSeedSalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mSeedSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xD6C0F535DCDD73DCULL;
    aIngress = 0x9BDB88C35C1943AFULL;
    aCarry = 0xA2325014840A8F32ULL;
    aWandererA = 0x94788E0DC843C848ULL;
    aWandererB = 0xD42259307B02A1DDULL;
    aWandererC = 0xB61D201E0FEDFCEFULL;
    aWandererD = 0xC9245DA10C4448FDULL;
    aWandererE = 0xD7E77828725AE110ULL;
    aWandererF = 0x91F9F04B73BB5344ULL;
    aWandererG = 0xEBB7F42F2D117AFBULL;
    aWandererH = 0xBB871172CF1B7EC1ULL;
    aWandererI = 0xE79A74CA4D1FF14EULL;
    aWandererJ = 0xB5165E433C4AB25BULL;
    aWandererK = 0xF3576AC8429E82CEULL;
    //
    TwistExpander_Castor_Arx::SEED_A(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Castor_Arx::SEED_B(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Castor_Arx::SEED_C(pWorkSpace,
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
    TwistExpander_Castor_Arx::SEED_D(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Castor_Arx::SEED_E(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Castor_Arx::SEED_F(pWorkSpace,
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
    TwistExpander_Castor_Arx::SEED_G(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Castor_Arx::SEED_H(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Castor_Arx::SEED_I(pWorkSpace,
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
    TwistExpander_Castor_Arx::SEED_J(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Castor_Arx::SEED_K(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Castor_Arx::SEED_L(pWorkSpace,
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
    TwistExpander_Castor_Arx::SEED_M(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Castor_Arx::SEED_N(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Castor_Arx::KEY_A_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Castor_Arx::KEY_A_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Castor_Arx::KEY_A_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Castor_Arx::KEY_A_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Castor_Arx::KEY_A_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Castor_Arx::KEY_A_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Castor_Arx::KEY_A_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Castor_Arx::KEY_A_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Castor_Arx::KEY_B_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Castor_Arx::KEY_B_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Castor_Arx::KEY_B_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Castor_Arx::KEY_B_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Castor_Arx::KEY_B_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Castor_Arx::KEY_B_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Castor_Arx::KEY_B_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Castor_Arx::KEY_B_H(pWorkSpace,
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

void TwistExpander_Castor::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xDB36411979A24573ULL; std::uint64_t aIngress = 0xC548F6A704D34D9AULL; std::uint64_t aCarry = 0x84158B5128E9E9CBULL;

    std::uint64_t aWandererA = 0x9858BAF0389A46D8ULL; std::uint64_t aWandererB = 0xB3CE25CCE5C7F230ULL; std::uint64_t aWandererC = 0xB48855FA9618E4B5ULL; std::uint64_t aWandererD = 0x956617E946322944ULL;
    std::uint64_t aWandererE = 0x8F1524030CED5B35ULL; std::uint64_t aWandererF = 0xBCE6EE89556392D0ULL; std::uint64_t aWandererG = 0x96FB9A7CB473424BULL; std::uint64_t aWandererH = 0x857228E85523B7E4ULL;
    std::uint64_t aWandererI = 0xEEFC0F77C02DFDBBULL; std::uint64_t aWandererJ = 0x983CACB3EAF97DA8ULL; std::uint64_t aWandererK = 0xAB7C7B71D95A7403ULL;

    // [twist]
        aPrevious = 0x850534079B254A1AULL;
        aCarry = 0xD7C2282492A3A411ULL;
        aWandererA = 0xF81028E192A8D988ULL;
        aWandererB = 0x90614AFBEFB5FE77ULL;
        aWandererC = 0xEE5DE5F262217119ULL;
        aWandererD = 0xD739CB9AE5757951ULL;
        aWandererE = 0xB212DA603518BE84ULL;
        aWandererF = 0x9260475A0F7B67CAULL;
        aWandererG = 0xB7EBEC803D7E4629ULL;
        aWandererH = 0xD01A2CFBE2A130BAULL;
        aWandererI = 0x887C001F6D925D7DULL;
        aWandererJ = 0xCD688D20F3DD5C66ULL;
        aWandererK = 0x97D6BC9ABA323A31ULL;
    TwistExpander_Castor_Arx::TWIST_A(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Castor_Arx::TWIST_B(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Castor_Arx::TWIST_C(pWorkSpace,
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
    TwistExpander_Castor_Arx::TWIST_D(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Castor_Arx::TWIST_E(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Castor_Arx::TWIST_F(pWorkSpace,
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
    TwistExpander_Castor_Arx::TWIST_G(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Castor_Arx::TWIST_H(pWorkSpace,
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

void TwistExpander_Castor::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Castor_Arx::GROW_A_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Castor_Arx::GROW_A_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Castor_Arx::GROW_A_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Castor_Arx::GROW_A_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Castor::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Castor_Arx::GROW_B_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Castor_Arx::GROW_B_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Castor_Arx::GROW_B_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Castor_Arx::GROW_B_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Castor::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 16 of 33
    // Exploration cases: 0
    // Structural maximin 523 / 674; family total 8031
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
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4188U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3828U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7879U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8149U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1330U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1600U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1555U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 92U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1870U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1780U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 2U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1825U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 16 of 33
    // Exploration cases: 0
    // Structural maximin 522 / 674; family total 8097
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
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3198U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7519U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7339U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7609U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 430U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 925U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 655U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 700U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 475U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 745U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 520U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 610U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Castor::kKeyRotateASalts = {
    {
        {
            0x61B89C7DAA782A14ULL, 0x6ECA5C51B7057338ULL, 0xD7FC3554EFA0519AULL, 0x52051A5A54473102ULL, 
            0xE9ECCF4CC3101D37ULL, 0xA215C7599C88ED1BULL, 0x71EE6B3DB35F31F4ULL, 0x89F702A74B9CF934ULL, 
            0x39FC98F9E3407787ULL, 0x95BC4C3ED09F84B0ULL, 0x17AFB3D2A79249DBULL, 0xEBE2391EF1CB74C7ULL, 
            0x9BB3230A679C890EULL, 0xAF3F028A5AB25079ULL, 0x8CA938E6AB0DE78AULL, 0x6D2328311079415AULL, 
            0xFAA0903FDA0C0046ULL, 0x575F33331F0080B8ULL, 0xBCA10EA3CC35ADA7ULL, 0x0711AAB4F770A83CULL, 
            0x8C931ED880E070B5ULL, 0x94F656E57E565B23ULL, 0x325EB531BFB2D566ULL, 0x84810A9DF915C7E1ULL, 
            0x4BF1EB90F3D1926BULL, 0x2967405175A3B407ULL, 0x55E4B6E157A1180EULL, 0x3FC4C05A669C053FULL, 
            0x4862212DD8F85E3BULL, 0xD8B12DA3FBDF1678ULL, 0xA3B0FB08A3F9CE1FULL, 0xF52D717D72A96A8DULL
        },
        {
            0x8976BE71D20A3646ULL, 0x144783414EDA1055ULL, 0xE4FAC33C13412D2FULL, 0x5BD6CE9C6F1B32B4ULL, 
            0xC489D551A469E549ULL, 0x24FF715CCAC87E50ULL, 0x549943A1B44CD7ABULL, 0x057FC18CF4053F7DULL, 
            0xEF4887157865ED6DULL, 0x572BF6DB59280824ULL, 0xB6FC77ED665D384EULL, 0x73BAA2F33A96ADF2ULL, 
            0xBFFA87B8A082812CULL, 0x3C10710EDE1EF0AFULL, 0x68724F297C525C2FULL, 0xB18ADA6F0BE78A65ULL, 
            0x9972CD6E87A1BEDCULL, 0xEFE4A1B0B06A9296ULL, 0x89CFC8FBCA8B5796ULL, 0x514E9DE42999DB96ULL, 
            0xD5F697F9B1AAA029ULL, 0x9D58F6AC2BAC4F32ULL, 0xDD49BBFCABF328C8ULL, 0xB4A69BDE1B6D8116ULL, 
            0x1C87C403BE45A7B9ULL, 0xB3D72E8B34B712C5ULL, 0x716B9468EA595B36ULL, 0xE247F39DFFB934C7ULL, 
            0xB5886A0FBA7F7021ULL, 0x48F592C0BDD25648ULL, 0x0E9323F680143EAEULL, 0xEA326454E28CF354ULL
        },
        {
            0x2FD785A9AA44C0E2ULL, 0x12339471CD50A813ULL, 0xD18C4472AA3179E4ULL, 0x7BC253F63DD819AAULL, 
            0xA3C5C4C612EA4E23ULL, 0xDF3223231167FF26ULL, 0xCD3C56963F53E44BULL, 0x22011B58F7315F93ULL, 
            0xCA8DD86578894416ULL, 0xE2E370D305653E5FULL, 0x8DB19049961B23BBULL, 0xF611AE507EF4A9F6ULL, 
            0xE676CB22C9777D33ULL, 0x6B1ACD602FA013CCULL, 0x4D9599CB64A4436FULL, 0x38975F22F98EEDE5ULL, 
            0xB3B5F366E8C92F3AULL, 0xC3EFF5ABDCC132D9ULL, 0xE8BA5FBC8E150BC8ULL, 0x72B77CE6ED641FFEULL, 
            0xF93B10EA552D75A9ULL, 0x4C1F211865877568ULL, 0xC9E99C9C166444B3ULL, 0xE3C25AB0BC8704EEULL, 
            0xB41125F18D955310ULL, 0x578CFABC5DFEDA75ULL, 0xE9C68FB7169ED4DAULL, 0xB64009BC2198AE65ULL, 
            0xB61A2C75A9C300BEULL, 0x48EB2F2A97D67BD1ULL, 0x0E6528E881979792ULL, 0xAB16394FF20A2D19ULL
        },
        {
            0x6E6ADDC8E1508E76ULL, 0x56E8536203057FE5ULL, 0x2EC2FE19C855CD9CULL, 0xC34735EEFFDD5BD7ULL, 
            0x4958AF55E10994ABULL, 0x2847F0E94215099BULL, 0xA6649388E79E4904ULL, 0x51BBF9CEF0ABF4E7ULL, 
            0x399435344329F94AULL, 0x6C4B95896A283DBFULL, 0xFC6D768ED5E74684ULL, 0xCA82514752F12CB8ULL, 
            0x0A6C9F8E74E27AFDULL, 0x73069ACA67074F59ULL, 0x945D77508AD76C7EULL, 0xCEE273A78BBD2BB9ULL, 
            0x0D90C4E0EF8D24A8ULL, 0x162EB77CC34D2501ULL, 0x1D4F21405040AB3DULL, 0xDDFD89DD4CBF5EA2ULL, 
            0x19406A9C77E90B98ULL, 0x187DF653D6720CE3ULL, 0x7ECE0086BE466395ULL, 0x459C663389FA4AA1ULL, 
            0x093660AAEE177D18ULL, 0x2F6ABAED1CE5CDA4ULL, 0xC6C400F34D339165ULL, 0x801500BF964275BEULL, 
            0xCF522666D943B46DULL, 0x0A6E06FD3C1D88DBULL, 0xBE143FF9C959AC48ULL, 0x88813D8198DC07F8ULL
        },
        {
            0xA223516225E5BE45ULL, 0xE9B7F12B566DB2F0ULL, 0xCCAA41C105448373ULL, 0x832AF6F8A20BB863ULL, 
            0x9CB9A57180202318ULL, 0x5DA91B834472D2A2ULL, 0xE32DB4C18EA34327ULL, 0xDAA3E718AD85C346ULL, 
            0xF6C783892A13B620ULL, 0x796579438A62F2B3ULL, 0x8B65392B1DD71634ULL, 0x98D4FB754004DC23ULL, 
            0x91133DB781DD5873ULL, 0x33F4D4A60947365DULL, 0x8A784D7ECCD61EB5ULL, 0x47A8B7319699803DULL, 
            0x5A39BC3B5603529EULL, 0x14192B4AE054FCC6ULL, 0x4820804CA7ADB70EULL, 0x7A118E573D1F735FULL, 
            0xED4EA22A22EC59CAULL, 0xDF4CAE2FB35A8821ULL, 0xB67EB52DD6B55A93ULL, 0xCB0B630B87D01C78ULL, 
            0x6FE22E445C4E1A97ULL, 0xDFEBD099F4D47BCBULL, 0x151168200C82CAA0ULL, 0xB7B048FA7B31542BULL, 
            0x68DE0AC0D69DAE38ULL, 0xFCC0FBFFB0E26197ULL, 0x39EA8F88B1818504ULL, 0x295FD1B0900EEC76ULL
        },
        {
            0xC3D993056724FDD2ULL, 0x25B88A6633AA39D3ULL, 0x780A143A43FD11D9ULL, 0x52D8EB6A171EDD05ULL, 
            0xCBE1EE1A0CCC8013ULL, 0xCBC0288001E630A9ULL, 0xC71F7363A9AF8D1EULL, 0x8D34E958ABFFB52BULL, 
            0xE668ACAB51F51D10ULL, 0x4D772F7E284D05BDULL, 0x59CE8CEC39A04637ULL, 0x80ABDCD57190DE1FULL, 
            0x846E2B80845345F7ULL, 0x6C50B8EE6D273EB4ULL, 0x9306127E0B27B220ULL, 0x59271226D369CBA5ULL, 
            0x124A9C18B430EEAEULL, 0x90B380F3774DADDFULL, 0xBCFB4B23D04B471AULL, 0x213BFFD66F4CB218ULL, 
            0x6072DBE3AC6523B8ULL, 0x09A9A5B1F02466AFULL, 0x49A16E56C24A1B2DULL, 0x35D067215B2DEBCFULL, 
            0xAC9A5B3E7D05E42AULL, 0x1D4CEF784E25C087ULL, 0xB91E3F8D798C8971ULL, 0x2D26B6F9566CEDB8ULL, 
            0x00BAD2AB9AE85849ULL, 0x7D459E81DFC80F9AULL, 0x2C5212FA3B25739AULL, 0x06740FD6BD497306ULL
        }
    },
    {
        {
            0x17FB227981091376ULL, 0xC996FE7BA4526F38ULL, 0xFCD70CC75A865D42ULL, 0x4925F3AD5910808AULL, 
            0x8E1347960DB8EB47ULL, 0x7299640639D837F9ULL, 0xB4C3953D8AEF573AULL, 0x5190EEAD8DB199CBULL, 
            0x4D77B00F76D12EE8ULL, 0xDE3C477B57991BAAULL, 0x623B50E777ED17BCULL, 0x4E5F085D3CFB4F99ULL, 
            0xC497C8E85633CA16ULL, 0xDEB06FEF6CBAE7A8ULL, 0x69ED11D98F91B785ULL, 0x76EE0F5BC43CF1D1ULL, 
            0xDF3F6288D5C8DC0EULL, 0x8AC4EFB85B59F781ULL, 0x87019764C2F8B420ULL, 0xBD661F393AA3CF58ULL, 
            0x8CF98238A445520BULL, 0x8E44F4120365CE0AULL, 0x67BB269E15B5F1B8ULL, 0x7C179CC515C53148ULL, 
            0x0CB906069E341652ULL, 0x7CD19250DA4DE757ULL, 0x1733E6525B4DF376ULL, 0xAF6B6BBD87DEA64FULL, 
            0xCA631B3F219EBC78ULL, 0xABC3BDD62CEDA823ULL, 0xF72BDCA360DC6D0EULL, 0xF69F57E52798EAD7ULL
        },
        {
            0x04FB68DB87766E84ULL, 0x8498942FEA811261ULL, 0x8246F38AE48239F1ULL, 0xFED2C6BEB66DA57BULL, 
            0xF09E6308B8C78ADEULL, 0xB67CEC381E31C992ULL, 0xCCA554F599BECAB0ULL, 0x168E4FDA7337CF24ULL, 
            0xF06ACB76A288138FULL, 0xFC6BECD0215F7502ULL, 0xCC750F5A955EC85AULL, 0xE83705C8DEDFBB4AULL, 
            0xA8FBEEE75D29B052ULL, 0xDA74FB4FB2191A4AULL, 0xD17C6E3EA8AD4DEFULL, 0x3D7B363D02C8B03BULL, 
            0x876089109EA625BCULL, 0xBE05F040E48BFCC0ULL, 0xBB4DAE3FD70FB087ULL, 0x4A7D0CB5125B066DULL, 
            0xFBA0EEA1BA68F4DEULL, 0xDFAD2CD27C610923ULL, 0x508B187B4C17DDF2ULL, 0x6080ADA44F170829ULL, 
            0x4648506225142C55ULL, 0xD69F76E2458F7995ULL, 0xA715CEDE2C76F448ULL, 0xF56651B27EAC530AULL, 
            0x5F57718441BE2997ULL, 0x388826BCCC1F3C75ULL, 0xB250C21137E491E2ULL, 0xB32985D49E571376ULL
        },
        {
            0x3B6E2AAFE58C8016ULL, 0xDC7BE41D74600310ULL, 0xF0055DA1696408D1ULL, 0x8C7A35CF7E0E0D1EULL, 
            0x4C8B0284B798A259ULL, 0x95EA0939E263EF72ULL, 0xEEB780818BE7F2BEULL, 0xFD03610CDFA485B5ULL, 
            0x889FAE88423B8A8BULL, 0x0B34648B428ECD2AULL, 0x3A2463307E1F45B8ULL, 0xF2D299F8DF92BC0DULL, 
            0xD92A6C6C52C6B0DAULL, 0xFB41C218F3302AD0ULL, 0xE9AE642F4E831AAEULL, 0x9510E6CB8753B7F0ULL, 
            0xE9D7C208C14BA525ULL, 0x4F9CB6F2AF982BA4ULL, 0x98236A6B48832C7BULL, 0x8D7C2AC37F59FBCEULL, 
            0x38EEB20088E9D360ULL, 0x6633FAA7EC8DA5E4ULL, 0x67EF02B942DCE03AULL, 0xEB49720A40584D1CULL, 
            0x96BBA8ACBA6E4B86ULL, 0x2DACBF01AD6EF80CULL, 0x8F0237EAD75E2ADEULL, 0x83E0EF808B37A35BULL, 
            0x591E16D1CEB01885ULL, 0x274732E73BA6A91FULL, 0x156094896CD5CE75ULL, 0x32583926016AE2B1ULL
        },
        {
            0xC30BA40A3BF640CEULL, 0x748C632282172B82ULL, 0x422AF78BC96D71ABULL, 0x6221DD141068F252ULL, 
            0x7C3D9275D706D003ULL, 0xCB092D6BD006621AULL, 0x5B176B914AD0B901ULL, 0x61CB2CCEFECD454EULL, 
            0xA794A36A5CD8E4AEULL, 0x88EAA6149C6548C1ULL, 0x34679402E49A4F6BULL, 0xCC018C9D5DE040EEULL, 
            0x23F1ABC645F29A3DULL, 0xE0A0F71EBE785170ULL, 0x28D523B35974CAA9ULL, 0x0739C15768EF6A39ULL, 
            0xFA1CFBFC8887B0F7ULL, 0xF70CB5A3431CC1B3ULL, 0x59A6E184AF9C1DFFULL, 0xDC7125BA4FDEA7D8ULL, 
            0x3343ED006C4357EDULL, 0x3A7C9F06E8A3C93FULL, 0x041669DA055DB90FULL, 0xA6E23F631BF797FCULL, 
            0x68ECF283BD83EA49ULL, 0x04B0A7511637FD38ULL, 0xD9697C96D33EC0DAULL, 0xFB7FC670378B0939ULL, 
            0x7591A223B170101EULL, 0xA185958798F53E6BULL, 0xAD313FB6C334B431ULL, 0x55F8CF43E2D619B1ULL
        },
        {
            0xBFE54B196574B00DULL, 0x3AC2C7E655C17D9BULL, 0x8EB290E2F705A002ULL, 0x77B19F1E59B088F2ULL, 
            0x962A87C251ED6463ULL, 0x4EB8E81D9EF86C68ULL, 0x14DBCA8D9FB95C9AULL, 0x3CAF94D193D0DF97ULL, 
            0x0BE4187DE27D78E0ULL, 0xDAAACF9EA29F951EULL, 0x9EE871B2ED22B39FULL, 0x7326D900A7FDC605ULL, 
            0x0127FFCEB3A10919ULL, 0xD78C6C2C39259636ULL, 0x6B1FA9724EEC7250ULL, 0x0313C13B4DA6B548ULL, 
            0xB86B74C4E8ADB974ULL, 0x252554CD6D23B639ULL, 0x71475FA0E16396BEULL, 0xBF82298FEDF7B989ULL, 
            0xCB894351A439965FULL, 0x0C6FE049E506B86EULL, 0xC2D08A87CD02F56BULL, 0xE3028F2FA5840832ULL, 
            0xAB4DDA3F5AEB68E2ULL, 0x6C7D924DAC191071ULL, 0x00B6D55F99F7DB62ULL, 0x6DF1B74FF0095F23ULL, 
            0xFF64CC41A8A1BEBAULL, 0x1CC99EFC95F079D3ULL, 0xF6D6ABC7C8217E69ULL, 0x4A3F3CCBC0526D27ULL
        },
        {
            0xAA763D597F0A3FDCULL, 0x31ED6112838235B8ULL, 0xF171D7F5043CCA2AULL, 0x2ACE9776826D6CE3ULL, 
            0x75934949A88F3C48ULL, 0xB8C6803EFB46618FULL, 0xCEE35060AAF0812DULL, 0xE4C72E529728AC8CULL, 
            0xE51C83EE6F07F575ULL, 0xDCAA40F0CF1C36DDULL, 0x2AF2F78A430B7B62ULL, 0x344A267DE19DF13DULL, 
            0xA8102FF7EE976400ULL, 0x3CE2CA17E1E48CC9ULL, 0x19A51792D2DFAFB8ULL, 0xEDC3DFD59649F19BULL, 
            0x335910AE57B7C6CFULL, 0x3D5DF0E85C635BE9ULL, 0xCBB0644FEB8D5D89ULL, 0x620F654247E93A8EULL, 
            0x013ED8AE9C553938ULL, 0x7DCF19AE7A5E0CB8ULL, 0x6F6A49861AAFBAF1ULL, 0xCAB6C6C112093DFBULL, 
            0x29269F3FBC913E60ULL, 0x33C5BB5B514B4BC0ULL, 0x0C966CA674E47407ULL, 0xF7774FCE61C6024EULL, 
            0xFBEC090FB8BD47C7ULL, 0x8862396C2FB0F620ULL, 0x448D13A05A5155A7ULL, 0x1D910F2EFB59727CULL
        }
    },
    {
        {
            0x62F4B894FDCA974AULL, 0xF7710A8403F982EEULL, 0x67C97DE25560FAAEULL, 0x8AA3FDF2A28FDB36ULL, 
            0x1F3808089FF20C4BULL, 0xFE7A1576E040761CULL, 0x1AE3A4DB52FBE31BULL, 0xA2E97694A4567270ULL, 
            0x8E59999DE238E927ULL, 0xE8756C85D0C85716ULL, 0xBAFB3140822FE21FULL, 0x77D657E8CD380ED7ULL, 
            0x4CB001A59870F7C8ULL, 0xAB79E45F9F69E2A3ULL, 0x1BA1BBEEA22086B8ULL, 0x38C403ECB81296ABULL, 
            0x3BE918986D13A970ULL, 0x18BEDBF712E8B64AULL, 0x13162B80E3004162ULL, 0x7B229F3600E33BC2ULL, 
            0xB5AA2F4B9E3228F1ULL, 0x7F2436AAC737D31FULL, 0x627ECBA3882020E3ULL, 0x78E66F57BE42B362ULL, 
            0xA61CAED41CACC9C7ULL, 0x45E4240C2B3ACD5EULL, 0x928938818F91F043ULL, 0xC872B6151F7D7AC3ULL, 
            0x9F51410C6E834BCDULL, 0x58DA038A053D7332ULL, 0x6BECCE97474049E9ULL, 0xFC11ABFD41D50DF2ULL
        },
        {
            0x66AAD9F5EE73C61AULL, 0x0260A32D8677D33FULL, 0x0E2D45FEB3FBF293ULL, 0xF37CBC78347CE3A5ULL, 
            0x7BA1D93A2ED5C9F5ULL, 0x9AF8DF73B66FD149ULL, 0xA6CE7888FF9CECA6ULL, 0x27F573CF9C2E20A0ULL, 
            0xCE6E1CF1C3819C21ULL, 0xB529C9C3471C2855ULL, 0xE4C4F899DF3A0AF1ULL, 0x0904C4975CBCF3F8ULL, 
            0x7B17BD8A39440654ULL, 0x966D72CA85E7C227ULL, 0x8C3FFB9C5D2EE9F0ULL, 0x00402E48F875A8CAULL, 
            0x14EF225AC5D7CCB4ULL, 0x0A217B26C859E1AEULL, 0x4CBB0DFA7E6E65B3ULL, 0x989104E58030475BULL, 
            0xAD4333C92741B52FULL, 0x97A4F1D674EE22F4ULL, 0xFCF0168A18580BA0ULL, 0x76C8155F7D4D0B12ULL, 
            0xE719CD7CA1011F20ULL, 0x62C02915023FEBD0ULL, 0x02A397560D50B714ULL, 0x1DCF2299EDEBA4F2ULL, 
            0xD4E5A6CC4D8DD6D7ULL, 0xDD7B7B6B0D6EC02EULL, 0x640AB78A1B262617ULL, 0xEFEC4BF91264A881ULL
        },
        {
            0x8E35EABBB050FAB4ULL, 0xDCBABC1FC34DA49DULL, 0x8BC144E4ECC505EDULL, 0x086B5DE0AA5AB5CBULL, 
            0x3C73701CF222B669ULL, 0x69E954B9154697F2ULL, 0x399FF32196041FD6ULL, 0xBD07F0EEAD03C4AFULL, 
            0xF2B8CC217D87CCC4ULL, 0x79779ED953104CAEULL, 0xF0A16067CD054AEDULL, 0x1745ED28EECB11B3ULL, 
            0xB2886F10618DD9B5ULL, 0x57E39D28EFB04E57ULL, 0x5394DE2CC91C9389ULL, 0xEFCFD1A19483C526ULL, 
            0xB8D96F65AF13DB2AULL, 0xCBFA408DB082A58BULL, 0x1791C7DA1AD5668BULL, 0x89CE3794998E76DDULL, 
            0x7269D6728AEC9BF2ULL, 0x7863F745B72376CDULL, 0x05ADB3D4081816C6ULL, 0x1FD72ED133608201ULL, 
            0xEE8B18226D190FDBULL, 0xAC2A0858808C2934ULL, 0xB75A4C2740758654ULL, 0x806A25AA8AE9D68AULL, 
            0xBF64B405F4388E5FULL, 0xC2FD86F7A610E7C4ULL, 0xF7962552D6FB7E7CULL, 0x39D52529E0F8EF9BULL
        },
        {
            0xF3A06398C3B5F477ULL, 0x8B134C9FADF24C04ULL, 0x08725EABF2138FAFULL, 0xAF94AFD079FAA787ULL, 
            0x34256C03F6931245ULL, 0x293B859564BDD4BBULL, 0xE68DD19EB66FD265ULL, 0x3DCD09148769C3A9ULL, 
            0x630DE437B6DBD873ULL, 0xE6CC6CCBC9206FF6ULL, 0x463E8EACA27222E0ULL, 0x7B42413CA42F930BULL, 
            0x346D1C6A01C27B10ULL, 0x744457A0CB6399D5ULL, 0xA7286A647BCF5789ULL, 0x1163566B0927D5A8ULL, 
            0xE9D3021BD99A890EULL, 0xA2E988CFA3B57ADAULL, 0x53E9E3A0E065E7FAULL, 0x97CD89D6CA913230ULL, 
            0x664C3E0778E8D5A0ULL, 0xBEB20D7C9861E992ULL, 0x8F75FACA7BA66CDCULL, 0x849A43133D2C3CDCULL, 
            0x36B7027D661F8FAFULL, 0xF155FF460F155F4BULL, 0x7EC95B8F9F69B144ULL, 0xE452101156EE6EB0ULL, 
            0x28DD8E2CE50D2541ULL, 0x945E69871775A1D2ULL, 0xECFE67EA346474D5ULL, 0x1531D0B8814A08E2ULL
        },
        {
            0x4789BB154496C98AULL, 0x5DE23037E66B1800ULL, 0xD0C7D22D56A6F3E9ULL, 0x116A50ABC38EBBD5ULL, 
            0xCDBAD6875B678BB3ULL, 0x040AA640EFB56115ULL, 0x8811041524856F34ULL, 0xAA5F4BA0D93ED9ACULL, 
            0x8784366E919E905BULL, 0x01306BBECE72CC4BULL, 0x65AEEA2BAC2D6B11ULL, 0xA570DA9E242332D1ULL, 
            0xFC6F1CD9442212B4ULL, 0x10B889EFA7141F19ULL, 0x10F570E12655AFA9ULL, 0xF963FB59C8C87416ULL, 
            0x80981E12ADB4CC7EULL, 0xCCA080A8F1E2ABA0ULL, 0xCBF8BC2454674858ULL, 0xF981E8E1166C9F2FULL, 
            0xE30C59CCA4CB9190ULL, 0x39F3D4F4F1D78D8BULL, 0xC287CFEE07880C5DULL, 0x5F631D9AFD615766ULL, 
            0x02E5CEAF15F5C7A6ULL, 0x3125160320A590A7ULL, 0xBC303BCDAE03C4F7ULL, 0x66961DD959149D74ULL, 
            0x4430E472B7E86C4AULL, 0xE28908F7D8ECF860ULL, 0xC91B5AEB7099D128ULL, 0x86E125A5573C2A6BULL
        },
        {
            0x5D0835D2FA07ACB1ULL, 0x53B43F2DF56279D6ULL, 0xF43310E35158B549ULL, 0x5D519F35DF874076ULL, 
            0xDF70DC9B4FBE5C40ULL, 0xEFB79C86A8B956A0ULL, 0xA2E2F507BF01648CULL, 0x9714FDB2DBD62A57ULL, 
            0xE056536F3EC7DB63ULL, 0x627CD70A66DC2C03ULL, 0xB5BA5D068A9930D6ULL, 0xA3AA53A97BBDE72CULL, 
            0x9D429AE6DF026B0AULL, 0x545691C12C2010FBULL, 0x401221938FD2EEE7ULL, 0xC53CD2AF08DFBC47ULL, 
            0xF8ACE9A06915AACBULL, 0xE001C0F7EC63D425ULL, 0x384BEB6CB8987F6FULL, 0xA8F744583BD5190FULL, 
            0x396EDEA9A0D393A0ULL, 0x52A39C1B88496110ULL, 0x7157E75C511C6D17ULL, 0x5B344F338BBF9C3BULL, 
            0x0F2E642D56588C8CULL, 0x74A47AE632FC1867ULL, 0x8284F21411998BEBULL, 0xBE3889147FB1B5D7ULL, 
            0x5D1D0A4094E3A909ULL, 0x36BF4792976C1627ULL, 0x20A41D8A73CC4334ULL, 0x8DD5BB7C5A28CC33ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Castor::kKeyRotateAConstants = {
    0xE84EC00ACD98FB09ULL,
    0x4B2B5444C982BF3AULL,
    0x797464260A0157E9ULL,
    0xE84EC00ACD98FB09ULL,
    0x4B2B5444C982BF3AULL,
    0x797464260A0157E9ULL,
    0x19B95D19B19B4DBCULL,
    0x10337007E0645E86ULL,
    0x39,
    0x0D,
    0x08,
    0x8F,
    0x25,
    0x94,
    0xB8,
    0xD2
};

const TwistDomainSaltSet TwistExpander_Castor::kKeyRotateBSalts = {
    {
        {
            0xE0DDFA9F36F4294CULL, 0x2CCE327351E1E011ULL, 0x10279D79775E9974ULL, 0x85548CFFF1FE064DULL, 
            0xF3C3BD1DF76C54CDULL, 0xCD7BF5C8AC60AFB4ULL, 0x603B2817D7CA2276ULL, 0xB91C4BB39537CB64ULL, 
            0xD72C87D4B28DDACAULL, 0xB135FFF2002F61C1ULL, 0xEBC8BD798F57F973ULL, 0x8BD102B6D82C427CULL, 
            0x72F7499754D102BFULL, 0x9BF63CA1F4966BECULL, 0x22A81292EDD177A9ULL, 0x6D7CC045EF05B6ACULL, 
            0x2236D326916B95B7ULL, 0x57F91D2DAA72366BULL, 0xF968AB2F5196DC10ULL, 0x337781BBEE6E4E04ULL, 
            0xF734B69838B4CB90ULL, 0xDBC19AD440955223ULL, 0x26DB9DE3CD097540ULL, 0x85DEEC2FBF708B07ULL, 
            0xEFDF949775010156ULL, 0xA7ADFC930F606786ULL, 0x26578AB2174BF3DDULL, 0x316BA5FAB8E5B7C8ULL, 
            0xBC1A1BB78510720FULL, 0xC9C1619FC53F6028ULL, 0x42F88BEA81384E7DULL, 0x46EEA0C79965BC10ULL
        },
        {
            0x7E3D6DCAD4C18A1CULL, 0x04C14DF84243F53AULL, 0x5249A41BB02B2FF6ULL, 0x1DAC0C7943B050FFULL, 
            0x70CADD4B59DDAA76ULL, 0x709878CAC981F3A6ULL, 0x772F6A1CE2FFAAD6ULL, 0xA6C00FA44E9D54E4ULL, 
            0x8C573BDF20E21259ULL, 0xDE19F101CCD6025CULL, 0x5B7C61327DE6AF79ULL, 0x67CE8B8691377772ULL, 
            0xC8FB59D3032DE542ULL, 0x9CA534BFAC5D084AULL, 0x3384017232AEBF68ULL, 0xDA2694CF8FA8744DULL, 
            0x26D9F616B0600A02ULL, 0x2499F6B7FC35A3ADULL, 0xDFD58BA216EDD04CULL, 0xA0BFA4BD1E336462ULL, 
            0x18B8FFA97BF40E0BULL, 0x2C61D6F7C72CE844ULL, 0x6408CBA62918A979ULL, 0xC8C108CB73BF840CULL, 
            0x2DCD99DFCECD7B32ULL, 0xB3493F2B36125D6EULL, 0x1B7A6E0DB842CDEFULL, 0xF5C577A72880F615ULL, 
            0x2D1AD31F5F8CBF0EULL, 0xB70D9C49580B4EF8ULL, 0xA6009C95F0885CF7ULL, 0xA3F0F80DC617AA16ULL
        },
        {
            0xC5F746BF7AF211F3ULL, 0xF484EBBCF8309A0EULL, 0x13808D80A6FD87DDULL, 0x3178A795D57109C5ULL, 
            0x9F15721D3E28F1AAULL, 0xAA6635EFCA831443ULL, 0x8C9B484F7562C147ULL, 0xB983956A77F55879ULL, 
            0x9B39D62811E7AC9AULL, 0x50FA07E41D20D03EULL, 0x75C32AA163EA5E6FULL, 0xEA8A4D01ABBFDC25ULL, 
            0x200B219EF922C9FCULL, 0x4FB500AAC22073ECULL, 0xC7038288EB418E2AULL, 0xFE27D95F84228F88ULL, 
            0x2E0D07E52202A793ULL, 0x961FC9065BA27A70ULL, 0xEFC61BF3FB9388DAULL, 0x7D9B07664F517DAEULL, 
            0xEF2DB8750F6BE65CULL, 0x1D51D17E14D9E79DULL, 0xF7F895534DECACC4ULL, 0xAC20A7495BDBE2FFULL, 
            0x3C45BE679D0BE36BULL, 0xA96D576313278DA8ULL, 0x9C517659D4EA13E6ULL, 0x67DAC7BC0BB20211ULL, 
            0x55C6BA436B19C3B1ULL, 0xCE0646491796B577ULL, 0xB103A360844A48B3ULL, 0x540CDFD90C5A8368ULL
        },
        {
            0xDD441EB0337F23D2ULL, 0xB872E48EFA04354AULL, 0x16D4C089941F7238ULL, 0x5E3AF0F81B0CCE0BULL, 
            0x41721686FA0E5972ULL, 0x1109058B887A24A1ULL, 0x1A5DF3AE67C0B69FULL, 0xCBA184C2F40B47D1ULL, 
            0x27A3D7160A31CBBEULL, 0x355D2E544C0F1DD3ULL, 0x7251810935857360ULL, 0xCD1D3683AD9F3707ULL, 
            0xE739EB2EDDBDF837ULL, 0x367AE8A21834334AULL, 0x2E7B5B833EC38C13ULL, 0xF67D4EAD2F47AFCAULL, 
            0xB62960EE2A3DFC35ULL, 0x878BF1C5AB3747A2ULL, 0x29F2426A548D9F97ULL, 0x05AEFE2762BD9090ULL, 
            0xB6677C85F7538AF4ULL, 0x9DAD418D5D4FB098ULL, 0x840DA5C4EE5C9BA4ULL, 0x70FC4212D2CB35AAULL, 
            0xA117F5E78F825131ULL, 0x9262D86CE2FC15E1ULL, 0x250C4C3380BDFABBULL, 0x7F79FD7DD3801E6DULL, 
            0xBE8F6836CABE45B6ULL, 0x7D37C2CFD8DDC7EAULL, 0x76C98DF0CFC01EE2ULL, 0x31AE97C56CDF6A99ULL
        },
        {
            0x84BDD57CF710276CULL, 0xC8953A1D670329C6ULL, 0x109C232085A726C5ULL, 0xE14875EFA87DF0CDULL, 
            0xDD32FF6C5573A689ULL, 0x6231AA7F1A863FADULL, 0x8D03D674873B31B7ULL, 0x0F2E18A50C7AA40BULL, 
            0xD3499F126464771BULL, 0x184FE7F24F3C5A32ULL, 0xC2B2BB98F763798CULL, 0x0AA25C4ECE354253ULL, 
            0x8F06741168622946ULL, 0xB9775E9977BB2B14ULL, 0x20DB4F6EF29A4054ULL, 0xF940EA9B23906DE0ULL, 
            0x679BC89EBB3346A8ULL, 0x7896863EAB028B4AULL, 0x80027351EBE45B3FULL, 0xF751AF99C4B46589ULL, 
            0x954CD302561A7E5CULL, 0x559D504CA6208974ULL, 0x95703A9B3B5939F7ULL, 0x4A45D65FE3214BD1ULL, 
            0x41FEBEA13772823DULL, 0x7CBD2E3B6DB179DEULL, 0x216893826726CD2CULL, 0xC710EB7B9B31DFD2ULL, 
            0x1EED96F4B0571532ULL, 0x8475EBE48FDC8A7CULL, 0x6C764F9B9C471CC9ULL, 0x90625850EF12F595ULL
        },
        {
            0x5248D31044E31777ULL, 0x0A6036E251581AAAULL, 0x3A711C01F3FB11D6ULL, 0xE8163645FC58AC57ULL, 
            0xC73D60B1C52A3A75ULL, 0x41E4E17273E7005BULL, 0xE81F59BBAB27FB61ULL, 0x5BAB3C3B2A5FC064ULL, 
            0x971343707A55D94DULL, 0xA5FCBD3FB3F3C5E1ULL, 0x2C1B0F40B880E8C7ULL, 0x22473CCB186E5791ULL, 
            0xCD0C5EEFF53C35EFULL, 0xFC860FBCF8D862D3ULL, 0x4404356A74A19DA3ULL, 0x9231A1DDF70A1F41ULL, 
            0x26B796D9E8797DF9ULL, 0x99058C6E85614656ULL, 0x09BBF6E3FD03AB25ULL, 0x86EED722BAC27A4AULL, 
            0x17E0FD570C152C22ULL, 0xF895FE4E2E57811FULL, 0xD5195EC03612F481ULL, 0x880B6213FDF4F504ULL, 
            0xFE9A05719531BB89ULL, 0xB69ABA8BFA26E2AFULL, 0x247246A5DC4D37F2ULL, 0x9DBC99BE01D60373ULL, 
            0xCBC8ACDA0450C131ULL, 0x689DB6D2DCF6B2CBULL, 0x52A6F162E810F1ADULL, 0xC25D6ECDCB3D2A03ULL
        }
    },
    {
        {
            0xD6C44E4C9BF56984ULL, 0x839507FC8BB978BDULL, 0x11146EE300A1C975ULL, 0x6B9C24224C2BF251ULL, 
            0x0BC96EFB036544DAULL, 0xBB99143337034962ULL, 0x9DF91A36186887CFULL, 0xB6A7BDB62BB39960ULL, 
            0x5F8A1EB89E8E496CULL, 0x71970D5F43EEDFF0ULL, 0xF4D398F4A5DCFCC5ULL, 0x759E37968BF000FBULL, 
            0xE4B7FB4C5F7BB2AEULL, 0xB1C3DFC387770548ULL, 0xC4B83394A18BA9CCULL, 0x5FE9054EE06B061EULL, 
            0xAB32CCD06F704586ULL, 0xF77EBFA537F590E1ULL, 0x3481D287D001E514ULL, 0x5212A9A3F2EFE637ULL, 
            0x402DEAFCCA197E03ULL, 0x5B07D613FD3B51FBULL, 0xDE61D1D56C04DD51ULL, 0xADDE87FA80B3029CULL, 
            0xA38FCFE9DE5F659EULL, 0x38D293CBBEEA4218ULL, 0xFDD230487A7FD854ULL, 0xD8823F574C16400BULL, 
            0x34797D198DA039C2ULL, 0xB8972C94939597A4ULL, 0xEB0CE6A3CDAE3C77ULL, 0xF77787A7D81D9351ULL
        },
        {
            0x9800F0AACC4B2148ULL, 0x89861C87AAEAD288ULL, 0x2080F2B70114E6DCULL, 0x67136B7035050D74ULL, 
            0x94E5A5BDCAF4491BULL, 0x65DDD9608149F9FEULL, 0xEF26F3AC62B7E1B1ULL, 0x8F31D167663F117DULL, 
            0xB5E741710690A1C1ULL, 0x362D4246E8D7F0D8ULL, 0x5B92309CE619E187ULL, 0x2A2BA2647E5DC50DULL, 
            0xF3E1C02A00C5045FULL, 0x2A62875903475CD0ULL, 0xE3F87B05CEAAD005ULL, 0xFA8377D4FB0CBAB2ULL, 
            0xF1288D6BBF670080ULL, 0x7074B5FA9D0E76D7ULL, 0xCDF2A7B93BB5432AULL, 0x3867A955350BCD09ULL, 
            0xCBE8579EC5EB47E8ULL, 0x6BD06FE745B43303ULL, 0x9F32F6BE1CD2C434ULL, 0x8D9F6809B3E78605ULL, 
            0xF5F5BCC4A9166CA5ULL, 0xC135348694DA0DF1ULL, 0xF994D74A32121D46ULL, 0x3BA459E80186BE39ULL, 
            0x1402488EBCFAFB9CULL, 0x2B0D9F353F62970BULL, 0xC3D1AF74D4AE0065ULL, 0x85F746B2D96D3D0DULL
        },
        {
            0xBCE15D40F712EB54ULL, 0xFFFD2785CE61429EULL, 0x79D1F3D2840F4372ULL, 0xE5B45BDA9D851288ULL, 
            0xF0A6CDFCCD97EF87ULL, 0xED3026344CA7989DULL, 0xE743E28914126567ULL, 0x7E5FA61A5C77938CULL, 
            0x85914D735605D8ADULL, 0x1A6CF7665F559A54ULL, 0xE79134EB2DA6E082ULL, 0x3367F7CF6BFAAB60ULL, 
            0x977B7E4ACEEFC75CULL, 0x9CA24507327DB11FULL, 0x5C311CE56B21E1E3ULL, 0x727D24A03358247DULL, 
            0xC93B10A0D8B0350EULL, 0xF87E3ED7A3842800ULL, 0xEB4FA66473AB2116ULL, 0x2C6B0AB6FF22E3DEULL, 
            0x2036FE1A75E841D5ULL, 0x74AE623A709E75A0ULL, 0x03CE735C78680758ULL, 0x6A00526D73745D70ULL, 
            0x97B1D00693288F87ULL, 0x236FE03DDE4502FCULL, 0x4F60812B8113E957ULL, 0x89E6279A23BFE1D4ULL, 
            0xED52081F49330DFAULL, 0xA7000E0F90DEDFA3ULL, 0xD270BBAB6577CD9BULL, 0x4D70AA11A21FED06ULL
        },
        {
            0x17B99B630EA1227DULL, 0x9049FB15A120F56DULL, 0x33B596553CFFD98EULL, 0x7D264F4E6058BC75ULL, 
            0x4C08B5DBA1C585CBULL, 0x0BACEF56FDECBBA4ULL, 0x9762AD5EDC93AE62ULL, 0x8FCC3FC64F37DE75ULL, 
            0x62C56CF5BF5AE019ULL, 0xCDAF8A742393D4F0ULL, 0x5131D9B754EAD67FULL, 0xC5AAD153CCA802A8ULL, 
            0x8B37681B5F65567EULL, 0xDDC0260609A88B85ULL, 0xC85D92728AE1C060ULL, 0x22599C71E1F48F3DULL, 
            0x4DAA65AE8C0C927EULL, 0x74AC3EAA778EFF49ULL, 0xD0DFE1F407762066ULL, 0xBBB4E766ACA57896ULL, 
            0xF33CE6791B57EE51ULL, 0x248FB38FBDAFB5D5ULL, 0x92CFF0242DC02F36ULL, 0x3153067D77372F09ULL, 
            0xE6B2ECE848804771ULL, 0xD862669E7EC17809ULL, 0xD7E0A2243BCC7266ULL, 0x49A003AE695D0ED8ULL, 
            0x29BC28B8089EB372ULL, 0x518B3E4F65D05419ULL, 0x63465620C23FD719ULL, 0x53E441BE20A2A6D3ULL
        },
        {
            0xA8356A620E93274DULL, 0xE9FB1A7BEB93D99EULL, 0xD0988D10DD42BC82ULL, 0xC803885263500EDFULL, 
            0xD901ABAFD98E2001ULL, 0x331675EE86B50DE5ULL, 0x17DEE2414AF42CF2ULL, 0x3B7904A15D5B8ABCULL, 
            0xC2F93DAA3711D170ULL, 0x3826EBA4E9C3199EULL, 0xD638F07717DFAF86ULL, 0x2B148B41D5382E92ULL, 
            0xD45257B53085D2D0ULL, 0xD2C2BAF1DA7FE2E8ULL, 0xA20F2AF57D7B7817ULL, 0xD9E0D9CB1781D93CULL, 
            0x637EC6EF69308B21ULL, 0xEA1B6133F3120CE6ULL, 0x64F9BC3419E409E4ULL, 0x7F965A0FCAF30A01ULL, 
            0x146918031EDE0E5CULL, 0x645E7D0FBAF3738AULL, 0x0CE0B77FA7EFF335ULL, 0x00251E1305225BA1ULL, 
            0x742198B5DE3D20C5ULL, 0x2B70E3BD10AD780DULL, 0x36F9ED9944DE78C1ULL, 0x5B62C9EEED92A77FULL, 
            0x091AFCFB0143FAD7ULL, 0x1CF8E8CA5E240732ULL, 0xF952E032D5A31B2EULL, 0x3F5FDDA15A71D639ULL
        },
        {
            0x7E9703426C91D725ULL, 0xBC745F33AE508B8DULL, 0xDAE89C02559321C7ULL, 0xC2906D4A9A6BA0AAULL, 
            0xDF00A5D06E9E86F9ULL, 0x925AE8328F4E0918ULL, 0xDF44F6F500934309ULL, 0x80FBDBFFAA9C51CFULL, 
            0x56C1A479E72C585BULL, 0xD8EEB094AE8F532DULL, 0xE978AD1D1E935074ULL, 0x79C836B85FD63D7EULL, 
            0xAB306EAE80077BF0ULL, 0x6EC518D5BDBD858DULL, 0x145EBCFDBD3586D9ULL, 0x62CC319480D628F2ULL, 
            0x9BEBCD6BCAE178E7ULL, 0x33E5DF68341652C8ULL, 0xEE23F6F5C70F6F25ULL, 0x5F7AEC3B5D8E8540ULL, 
            0xA31E256C304AEB94ULL, 0x3C99D632F3671E4DULL, 0xE1F9A1E6F6667399ULL, 0xB99E5B218CEF27D9ULL, 
            0x1B6847DC7F857993ULL, 0x86903D8F185C643BULL, 0x518517DAA0AF6FADULL, 0xE4584064C76947CEULL, 
            0x4E22DF82B8A4CF56ULL, 0x6A5FAE99937F07E6ULL, 0x50E34F24F47F1DC0ULL, 0x202139A3E7F8DE45ULL
        }
    },
    {
        {
            0x9622821ABF82B7BDULL, 0xE07B6A20B5E062E9ULL, 0xFBFC9241EB07F11EULL, 0x5C0BAF9CD2BA6CC0ULL, 
            0xDE6423580520EC1DULL, 0x4F2213376FD57528ULL, 0x7DA3EE9BE023D796ULL, 0x9CC7FDEB551D891EULL, 
            0xEF7813EB73FFAE0DULL, 0xB39647A625047687ULL, 0x4268570ACB536EA0ULL, 0x4400F7083826CA4BULL, 
            0x310D925B47F94E95ULL, 0x29854F5A2DD76FFEULL, 0x3A1C5A042D66BD6BULL, 0xA7C70B0000CF0C91ULL, 
            0xBFC27D977FF83AF6ULL, 0x5B1E89379B1BCF04ULL, 0xF38B93C28C8B305EULL, 0x602AAB73AF1903E9ULL, 
            0xAB59EBDD28D5A02AULL, 0x6934ACFF268EFD83ULL, 0x562426AAFADF0F18ULL, 0xE7ECAAB5F6AC6E85ULL, 
            0x55CDA3494792156CULL, 0xAB8215C24BDA3699ULL, 0x0EB6BD06ABFCBC99ULL, 0xED8F896090D41D50ULL, 
            0xC22CF2141152CB75ULL, 0xA626D09EF06B5E0CULL, 0xEF8C526FC7FA51D2ULL, 0x8FB348A19A511819ULL
        },
        {
            0x9C82437A8ECD1604ULL, 0xF9D6426C6CB69B22ULL, 0x190C21DBA8E7105FULL, 0x9495583341570838ULL, 
            0x3E707A4B969DF109ULL, 0xC0F14BF71FB57A50ULL, 0xB3C97E6DDE08E278ULL, 0x83EFE18092FF1451ULL, 
            0xEE3237DCD8ABF3ADULL, 0xE03813CEB53A8537ULL, 0x4D3BB01BCE58E616ULL, 0x99646C8948BB5E75ULL, 
            0x347BD0CBA8F22872ULL, 0x1D79C8B3B79CACE4ULL, 0xD0A7EC25435ED996ULL, 0x6A75901309063628ULL, 
            0x69FB4859BA2600EDULL, 0x507C1D98B815E369ULL, 0x7BBB18540B570015ULL, 0xF7D3283D8AFEA7F7ULL, 
            0x883D55421095958AULL, 0x6452270BD12293D9ULL, 0x43DF2A826656213EULL, 0xF2D5B8F00EC934BDULL, 
            0xE0592283F5B348B6ULL, 0xDBF3B85EA87F679FULL, 0x22D34E3A30577304ULL, 0x53A68EDA59B7A5BFULL, 
            0x3D49F4CE8C6B81DDULL, 0xCA713890A2C3C5CFULL, 0xCB52E0B5BA3AE002ULL, 0x8898E9DB3F572B57ULL
        },
        {
            0x93B0F267CDB0564CULL, 0x22CF4ACD807095BFULL, 0xAE9A1F5AE09130A9ULL, 0x1EF92CE7969B534AULL, 
            0x5C0998617110DB7BULL, 0x1A901539C587C34FULL, 0x7DF75C0EEDA1EAEAULL, 0x48C960C0B5C9A919ULL, 
            0x9C369D85FD30034CULL, 0xEBD07C3598EB1F62ULL, 0xFB066E8567A98FCAULL, 0x1C4EA233A29141B1ULL, 
            0x5CFFADB57CF041A7ULL, 0x1EBC3532412205B0ULL, 0x4D00CA14819290D9ULL, 0x0643C5D8A2863E1FULL, 
            0xD7B38D21C3D68EE8ULL, 0x57B5C2F379F68BD0ULL, 0xB01E8C42801E046EULL, 0xBEA26496363B26B6ULL, 
            0xED746471BBA80A96ULL, 0x38D852985442BC51ULL, 0xB91151B489AD1ABBULL, 0x7F76689132287DA3ULL, 
            0x1AE29374153113FCULL, 0x2DDBE86152292D63ULL, 0x5F3ECFD54BA2DECFULL, 0xAF229ACEBBB7154DULL, 
            0xB0A9CBF5CB0A8E80ULL, 0x461424D84F25A47AULL, 0x5BAC81B520DE2DA8ULL, 0x470BEBDE55368E17ULL
        },
        {
            0xBEF6F52D75DBF46EULL, 0x827026C38B6974E4ULL, 0xE8ABE0FD50EC5A68ULL, 0xDE8CA539625AD21AULL, 
            0x1BCAB33EFB120F16ULL, 0x88CC2F9CFEA8022CULL, 0xD6BA5B99CF3040E4ULL, 0x9E56A4DAB41445CDULL, 
            0x51F0A09F55320A84ULL, 0xCC70EDF9B6C357EFULL, 0xE002701FAEF1F95CULL, 0x6E0FCEA33F660F51ULL, 
            0x8116089F171E616CULL, 0x881849A926788B94ULL, 0x76182929B563BDA2ULL, 0x10FA1296D41367E3ULL, 
            0x6617FFAFFB99E1EDULL, 0x6C183160FC52B395ULL, 0x61D89DBBF25C744EULL, 0xEDA1BB93963D4CF2ULL, 
            0x560C825300230661ULL, 0x3B40560B1C489275ULL, 0xD3D0AFFAC0C77192ULL, 0x039CB9F88D73D726ULL, 
            0xC1AB064E82885DB5ULL, 0xEB66FEB73D347B82ULL, 0x13B7EA27CAD10FE4ULL, 0xB5A12D054C52C7D9ULL, 
            0x86C627DC125EA013ULL, 0xA9EE7E706A302414ULL, 0x24A1030DAD10D34DULL, 0x0D97DC1EE1CF32E6ULL
        },
        {
            0x884E7EB8553B0FE6ULL, 0xB001E9E581633B8BULL, 0xBA1FB56F108D6BD3ULL, 0x832B61ABD947BC3AULL, 
            0xC89CFA83A95A094DULL, 0xE4A0656C11BBD480ULL, 0xD74714545A46ED24ULL, 0x163BE341960C22E2ULL, 
            0xDCD676AD848C4948ULL, 0x2DF1DBC315AF34F5ULL, 0x772E83610D6B55B6ULL, 0x482113A89D066DF4ULL, 
            0xA3DD3DA3F8D8E948ULL, 0xD8D0F93DC247449FULL, 0x5251C2D97A1B90A3ULL, 0xF234E60D26675139ULL, 
            0xB9CF6F3F558AD19FULL, 0xFF09F484B4DA8415ULL, 0x7814BD626016E175ULL, 0x5F4AFAB9E520130CULL, 
            0xC8F3868373C4277DULL, 0x1069632878164A6FULL, 0xC1443C252A88DA49ULL, 0xFA9F4A810D84B9E8ULL, 
            0xF2F029C0B927D05DULL, 0x851FC4EA3220173BULL, 0x0AA12F54F2BA9478ULL, 0x139E371EE072650BULL, 
            0xD34F98CE50ED4F51ULL, 0x8689E08FB17B8EA3ULL, 0xFFB8D3ECF45989E7ULL, 0x8DAE610EF5BFACBAULL
        },
        {
            0x5EE9C80AA46054D8ULL, 0x338E5BFE5B8D11ACULL, 0x55A19BD5D15E0F0FULL, 0x57B4F22DAAE4C26FULL, 
            0xEBB7D8FFBB36A3A5ULL, 0x4854D740E643E66FULL, 0x39E39D2E72C52F32ULL, 0xE1442E20BA9B802FULL, 
            0xDAB85DB22C04A758ULL, 0x3A4A8B8700264E61ULL, 0x1253B12358108DCCULL, 0x31E7661790C79A29ULL, 
            0x32E5A6C48B44AC12ULL, 0xD71F76BF06041E65ULL, 0x48AC3565BE5AA891ULL, 0x39007010BB75C51BULL, 
            0xBADB56F3330BFFB6ULL, 0xE83F2C22BEBB4DC8ULL, 0xE733E443D8E055B4ULL, 0x413C8A30A5430D2BULL, 
            0x2C2F0CFD65C83F96ULL, 0xC3E14A01F62AA99FULL, 0xB959A37F124707DCULL, 0xEDF7DD81C1004989ULL, 
            0x32EDDE1AF0FEC9C9ULL, 0x0D84362A0DE2127BULL, 0x10534CB03F9EABCDULL, 0x7EA443F712FE9123ULL, 
            0xB4664EECC162A401ULL, 0x45C4BAB2E9E561E1ULL, 0x0E054055039699C0ULL, 0x25F7BD35DCD43108ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Castor::kKeyRotateBConstants = {
    0x29CCBDF88BD89724ULL,
    0xC9978009415142EBULL,
    0x37A890FEA574534BULL,
    0x29CCBDF88BD89724ULL,
    0xC9978009415142EBULL,
    0x37A890FEA574534BULL,
    0x928E1FBF83202809ULL,
    0x920F2B7DCFE41EBFULL,
    0x30,
    0x91,
    0x12,
    0x88,
    0x4D,
    0x4E,
    0xC5,
    0x16
};

const TwistDomainSaltSet TwistExpander_Castor::kKeySpawnASalts = {
    {
        {
            0xD1AC3EC5F2066A95ULL, 0xF46B6AF7939B4595ULL, 0x5AAE661C68FCC6DEULL, 0x67A450281D0D9D44ULL, 
            0x82752F8079FB8C21ULL, 0x46760AE9FAF0EA7CULL, 0x5F122B20A63B5A9EULL, 0x51D4E68CD76DAA9AULL, 
            0x281AF3EEA319EEAEULL, 0x36DEDD6EEC5DD66AULL, 0xA220601CF151AA7DULL, 0xEB882F86D1E6ACE4ULL, 
            0x5147B3E124DBD0E1ULL, 0xAB84C5B9C9210C4CULL, 0xA65B2B4CF4AC35F5ULL, 0x805F35E12E362F69ULL, 
            0xDED9CAF5BF8D1D4AULL, 0x74884CB160BF3BA9ULL, 0x5CCB02099D78C913ULL, 0x2D200ABE7731A7A2ULL, 
            0x76E4D913A9D4F8C4ULL, 0x0461901573AAAF0CULL, 0xC3EBC1A116BD3F4FULL, 0xD632471595F43AB9ULL, 
            0x2F8F3058F62875CFULL, 0x6640A2A2E41656F9ULL, 0xD52D9F400C345818ULL, 0x11D5429AF839F285ULL, 
            0xD153B4B1A33C7051ULL, 0xE60812DD318E3820ULL, 0x24532647BA92CC45ULL, 0x16750DF6C4179978ULL
        },
        {
            0xBCEAE98D1E0C3BA4ULL, 0x44B40F8C4A8FB08CULL, 0x750982A2282061F5ULL, 0xE84F29877B5FC6C2ULL, 
            0x378AC27949429BB9ULL, 0xFBA2015B064AEE84ULL, 0x42B3593CBE0A2F57ULL, 0x13E0A0D4FEAE24DFULL, 
            0x8790F88B6FBB95F0ULL, 0x695C30C8CFAA3E3FULL, 0xC22E7400F619DB51ULL, 0x9BB1C04E48273120ULL, 
            0xDAA26BCC3B6B65C4ULL, 0x7EA43484B3FD8EC9ULL, 0x488944869758EB63ULL, 0xAB0FF83EB2C95831ULL, 
            0x79C807DA291CF4F5ULL, 0xF8CE52D94FF50F3FULL, 0x21AF34614B2BD533ULL, 0xD86C074E4081668CULL, 
            0x8B27B7857426EEB9ULL, 0x406ABEDB23A4DF0EULL, 0x5CC47504E9D84ECFULL, 0xD2C8E8CB0E7F2C6EULL, 
            0x68E97AC80D8F15E3ULL, 0xF92DAECCACAD1585ULL, 0xF71BEF4FADA35A79ULL, 0x4CEEE8023C9D8CBDULL, 
            0x1864F6754067F3F5ULL, 0xA870724857A5E8A4ULL, 0xFA4FCC582A72D2C3ULL, 0xE3D4DE05E47BE7FCULL
        },
        {
            0x930E1BD57B355A39ULL, 0x275A43107BCCCC3BULL, 0x06B59A49EA4C43A7ULL, 0x944B58040DD26BC6ULL, 
            0xBD0B1111E881721FULL, 0x5E8300FA0058922FULL, 0xAA36A8F4EB7DB209ULL, 0xC23E533387386B44ULL, 
            0x32BDEAB79242782CULL, 0x5DB789F16A837DB9ULL, 0x082578A7A773AE49ULL, 0x0F2CDD02194DF85EULL, 
            0x51D6DE7FEA08A88DULL, 0x2144201E898F4A97ULL, 0x4446A5C5FF5BB1BCULL, 0x0E759B3783B6494AULL, 
            0x82191DECB23493CEULL, 0xF092FEB39FE0B0BCULL, 0x5CE82102BCE46EA4ULL, 0x1B4384BFE3BD9A53ULL, 
            0x036C325A51054A91ULL, 0xB1C022C4B2708B6CULL, 0x1AA8D0B3AA1AED11ULL, 0xD45687D0ADB71B82ULL, 
            0xF491F88ADB5E6CEFULL, 0xED8D5E0D878A1353ULL, 0x1D2D343CE11B8809ULL, 0xFEB1C24764A9B9A1ULL, 
            0x015EAD40C0EDB843ULL, 0xFCCCB00E38DCB995ULL, 0xA2BCA6818D71F996ULL, 0xE13B86E89D32CDF0ULL
        },
        {
            0xCA17CD7ECA585980ULL, 0x9A51A6984A704CEEULL, 0x3CAC43EF90A630D3ULL, 0xCDFC4B08FC73D187ULL, 
            0xFCAFCDF281411B2BULL, 0x694EFBB521B713DAULL, 0x22731E10FD8432DBULL, 0x3030CDB3EAC7E831ULL, 
            0x798041C575AB9511ULL, 0xD3F63F7BD54C274FULL, 0xB9581240E6925746ULL, 0x0FB3207E60E9E361ULL, 
            0xDEA432F59D2B34DDULL, 0x3FC327DCB5A6805CULL, 0xDB8050AD52BBC9F1ULL, 0x95C78F95597B0EDDULL, 
            0xD09C7233CE74C88AULL, 0x7003F30F34572820ULL, 0x0868E5E8FE84BE92ULL, 0xD45AB3DF398D8EFAULL, 
            0x1991BE8F12ACF17DULL, 0x89E339DA31E2B8F1ULL, 0x9CEFA289212BBC5EULL, 0x8A32E7C21649F9EDULL, 
            0xE73F0A7E014D3FDBULL, 0xEE14977C968FD0FBULL, 0x9B111245AD512449ULL, 0xA5AB76E9C7459A82ULL, 
            0xC0E8672A207FD2C8ULL, 0x0F7B819F73ECA71FULL, 0x80D1B90960EC09D6ULL, 0xAC14C731E2D38126ULL
        },
        {
            0xCF79E90ED90D349BULL, 0xB3DE10A01B66BA97ULL, 0x471BA42937729D60ULL, 0x5A3131DB0A22E4CDULL, 
            0x3CB4C585C82D5528ULL, 0xBC6267C86AE9EE92ULL, 0xD0A0ED3B770ABCDBULL, 0xB42EDCD1415FA767ULL, 
            0x8784E6FD07534D29ULL, 0x6EE57518777E507CULL, 0x8554A95A79DD3785ULL, 0x80261CCF00028D2EULL, 
            0x7A44824751578937ULL, 0x8820B3AD4CE37EE6ULL, 0x82AEFC728A40BE04ULL, 0xE28E5EC714588EE4ULL, 
            0x4C08FFF068704DD3ULL, 0x6785A33746F5CCB3ULL, 0xB45322C4A7D57D4DULL, 0xBF1CF5072432E5C6ULL, 
            0xD7599E538050917EULL, 0x4136796781084AE3ULL, 0xD0A757E00560E254ULL, 0x9ED411DF41A0A483ULL, 
            0xAEC6FBEF73C6970DULL, 0xBFAAD91FE87DFE44ULL, 0xE63EDDD0B42693F7ULL, 0xF4F01B67F86F8FDAULL, 
            0x584351288E3D390AULL, 0xC484ED47D6E011A6ULL, 0x8C97877B5D46EEEFULL, 0x08B37324B4F60145ULL
        },
        {
            0xCE981AC7CD6BE333ULL, 0xB1857F6C24B8CA1CULL, 0xBE410B0B41648380ULL, 0xBE47B03A75A8FF50ULL, 
            0x1ACE1430BFC3DC6FULL, 0x4145F0B07F4E35ADULL, 0x883BA98E0B17A173ULL, 0x4ADAC2DD716ABCE4ULL, 
            0xF6F170EA343FE811ULL, 0x0E4F27AD42C776C9ULL, 0xF47AEC3A5727459BULL, 0x6551322F499C1D60ULL, 
            0x4196D3FC46216581ULL, 0x7918F2B61AEDED2FULL, 0x1251ECB0044951C4ULL, 0x7B9F021AF23AD161ULL, 
            0x2A8472EAE209757AULL, 0x44B5DE033BD39CC8ULL, 0x0C329D9EB5AE76C4ULL, 0xA3F660C08EA7BDB1ULL, 
            0x98794FA47072DC06ULL, 0x8CE6C501090C93B0ULL, 0xBED24FD71C6CBE8BULL, 0x83ADFD83F1B5674EULL, 
            0x8D5A3FB2BBEE353FULL, 0x1150CBA4A070AC1FULL, 0xA432C131BFF8AE1CULL, 0xDCE2EC42D6D98301ULL, 
            0x1A999E5040F636ACULL, 0xC4873C7E423DE765ULL, 0x730AEAA44A7A2805ULL, 0x445D2EB65D7B962FULL
        }
    },
    {
        {
            0x3ECCE4CF0F2D58D7ULL, 0x168376226F1D8714ULL, 0x8A2D138FE15F931FULL, 0xFDC4007DE59BB1B3ULL, 
            0x4DFCBB2AE9FBE4A9ULL, 0xC64057BB35F50987ULL, 0x4DAA938F92528EAEULL, 0xB1382B16C0063245ULL, 
            0x784E86898693B70CULL, 0x5110D9A2AD64146DULL, 0x54811D2F7FEA8052ULL, 0x0298FF129698CA63ULL, 
            0xECDD79D9A74CABADULL, 0x404D01CEA100AFF6ULL, 0xE20156FED199E520ULL, 0xEE7EECCD33DE1FA8ULL, 
            0xFC03580971A2922FULL, 0x46C2412A89157DF9ULL, 0x6DF0E092EA253CADULL, 0x7DA8E6709CB7C2DBULL, 
            0x3750984C72ECF2A1ULL, 0x45EEBFF8CAAF6339ULL, 0x66B69367E8DBB859ULL, 0x9F3FF1A23FF1A098ULL, 
            0xF1DCF4F7F4E093EBULL, 0x74873776A16D6E08ULL, 0xC03C0FFEC8CF31DCULL, 0x6FB8CB1E4C74E61CULL, 
            0x719759B8FEF69FD5ULL, 0xA1466D932DA53FA2ULL, 0x8FA24E668F95BBBAULL, 0x19E8A23D9D780740ULL
        },
        {
            0x667751D94A585D89ULL, 0x813A49B9090A2B9CULL, 0xC0A199DED6E8F803ULL, 0x356AC15EC99FB810ULL, 
            0x4A4DCFD8CC09840DULL, 0xB21A270CA749C81AULL, 0x6F4E5B5746761F72ULL, 0x82DC4CCDE7ACF934ULL, 
            0xAD13FC3E7979C16AULL, 0xFE8825AD963CFB07ULL, 0x11053F306A117F69ULL, 0x5CA212992B4CA2CAULL, 
            0xE34CA35DBF039F20ULL, 0x7CFF3F7DA05B7B43ULL, 0x69413FFDCFDF36ECULL, 0xFB19B762F3578E95ULL, 
            0x56BEEE81A9928A5AULL, 0xBFD89B0AA7547616ULL, 0x3BDB558E2179A52BULL, 0xAB89B780AB9F0D41ULL, 
            0xDF3CBE788981270DULL, 0xC0D5DDEC49580DA4ULL, 0xF8084CE3809E3C32ULL, 0x877E55B9099C5D04ULL, 
            0x3AA0218C9F54E624ULL, 0xACA3FBEDA4991BE5ULL, 0x4A17DE2E74F2394AULL, 0x87B5A947E9664736ULL, 
            0x69778D63E5306444ULL, 0xC430EF8F76326378ULL, 0xE82E54BC1A5C38F5ULL, 0x6EE3A9C3FB1DA580ULL
        },
        {
            0x0D10D6CD24031D27ULL, 0xEE7DA6E0CA61CCE6ULL, 0xC87A2BC7900C8738ULL, 0x8BBC484BDD7FEAA3ULL, 
            0x9245492834819E9AULL, 0x4C73E38FCB83D658ULL, 0x826895BB458C8C3EULL, 0x92299AE6C2257D29ULL, 
            0x9E2E5A5E576CCCBBULL, 0x4696F22000A4D7F8ULL, 0x04832D50A5EC48FCULL, 0xCC506AC185852E34ULL, 
            0xAEBF952429AD2F95ULL, 0xF888300F7D930C4AULL, 0x6AB82E59F23A08BDULL, 0x72BC295BC4413B24ULL, 
            0xFCD0F115D3E2BC35ULL, 0x2B0BEF70AA86DB67ULL, 0x1196181049228261ULL, 0x5E8D138FD5FE429CULL, 
            0x54BE15C37D521B70ULL, 0xEF73CC078B289E51ULL, 0x8F8B162C182CD432ULL, 0x8A0853057A3D760CULL, 
            0xA821E740344D5CCAULL, 0xBAD9D60C271D2D0DULL, 0x40C851C7C09F34DCULL, 0xF569890B700F0710ULL, 
            0x3A3FA4C3CA9F6313ULL, 0xED477E71B2A15ECEULL, 0x580C7A3E86F9B710ULL, 0xF53410AEFF0B2968ULL
        },
        {
            0x4F019B8C739EB38FULL, 0xDC768324FA30023FULL, 0x7BB688E38FAFC083ULL, 0xABC62AD6C3688758ULL, 
            0x1CA7536299D8F94CULL, 0x6BBEE3BCA17DE40FULL, 0x9F7937D6F5BA23AAULL, 0x6D2AF854A1F093BAULL, 
            0xDD488DF47366900FULL, 0x78B1D5B12F94ACD6ULL, 0x6C9594B79E75FA58ULL, 0x50F4BC17E2BB1973ULL, 
            0xA4B90C1DB07BC550ULL, 0x06D851AFF36F71F9ULL, 0x6D7DFCB045DD1CFFULL, 0xDFCA263240FC5102ULL, 
            0x0695EE868347A06EULL, 0xA67403C0758132F8ULL, 0x13BE26BB4ED201A9ULL, 0xE005591DD0ECDE6DULL, 
            0xBC40F7D8D28005FEULL, 0xC90791A05DE102BAULL, 0xA4542C590325AFB8ULL, 0xDB24F5FE481D724CULL, 
            0x86B28F9ADD72CF55ULL, 0x932DA02842C6C307ULL, 0x8F7D0B0FA7F635FFULL, 0x29C3FFFB0A30BD1DULL, 
            0x115FE4AA579C4BB3ULL, 0x9846847AF5396321ULL, 0xF7DAD3CA005E3E50ULL, 0x0005622A563E136CULL
        },
        {
            0x8943655843886520ULL, 0x35AB91C34BE8E3FFULL, 0x598E6CB81910261AULL, 0x5270D8B2B3F20083ULL, 
            0x8F64B30E2604532FULL, 0x44BA3BF42C6938DFULL, 0x6AF6296E9029E28EULL, 0xCFCF443597FF3BCFULL, 
            0x375525A800CB3265ULL, 0x1BB9989D3518900AULL, 0xB38ED330EC483CA9ULL, 0xCB3A5AF6C7930F45ULL, 
            0xCD2DEC06044B811DULL, 0x5737086DF031E461ULL, 0xC6F54B33BCB63645ULL, 0x2D4C54749BD4EE89ULL, 
            0x2E3ECF5E4CC94B08ULL, 0xF73FD1746C6585AAULL, 0xBE6A98932AD31378ULL, 0xD37DE89C8BF024A9ULL, 
            0x22A8D514103335E7ULL, 0x645CB65D37ED56F5ULL, 0xFF8BD681ED360C02ULL, 0x6FDB497213771FA4ULL, 
            0x258F7273144C764AULL, 0xCE582DD766BF746EULL, 0x041C792A5BAC5CB1ULL, 0xEF9740BB1E8E3AE4ULL, 
            0x05655AB29DB9C251ULL, 0x8BDD004198859242ULL, 0xD7ED89056C442B44ULL, 0x62BEB1F2D1526B55ULL
        },
        {
            0x0E24CA47BC09D14EULL, 0x082BF3520BAB50F3ULL, 0x389DA7AE1D59A197ULL, 0x5E05781E7091D38DULL, 
            0x9D4028E1B22A865CULL, 0xD456A0922A17508AULL, 0x2DA416B6E67DE3EAULL, 0x3AC0DDE1DCC0E8CFULL, 
            0xC444816F381CA710ULL, 0xE7A8AC68281A31D7ULL, 0xFDF64C8776133FBEULL, 0x71376D25787E6D9CULL, 
            0xE01A3D4BDD99CE2DULL, 0x5EDA3DDEE1D4B075ULL, 0x5FB6D7BEB4141EFFULL, 0x79BF0DF49B018443ULL, 
            0x37A9CF8972E8AC27ULL, 0x74E7C2A79230DAF7ULL, 0xEC8CCEE9DEC0A6BFULL, 0xB9C8A8A6B107D43DULL, 
            0x0864DCE58CF82629ULL, 0xE92C871D5EADFFBFULL, 0x0305FC0D03EE9FCDULL, 0x3CA670FBAB745A88ULL, 
            0x59338CF392FA9A5FULL, 0x8A15EF1B45ADB506ULL, 0x4A548550A7102B9FULL, 0x764EAF63F4A743BCULL, 
            0x3FA70567CEE4F318ULL, 0xBB90C2A020584545ULL, 0xCAD22D7BB9D1310EULL, 0x0D1663B88D219176ULL
        }
    },
    {
        {
            0xF7A689D57BE962A4ULL, 0x21507EA2591B9758ULL, 0x1C37543978289355ULL, 0x9D596F96771FACB0ULL, 
            0xA36B3BDB8441DDECULL, 0xD5CD6F45082056F2ULL, 0xAD0AB2933A6A6DB2ULL, 0xF62B52961C1EC073ULL, 
            0x203BFAF540C3AC74ULL, 0x2228EF4ECBE7767BULL, 0x19BCFA99BEAC26B5ULL, 0xB5718B315CE12B93ULL, 
            0x9FFD7594D03EA4A4ULL, 0x3715E7C09A3BEDE7ULL, 0xCB03CD9DFC8827C6ULL, 0x0BE98E4D98481FE6ULL, 
            0x532A3946DBF8EEF6ULL, 0x8EAE47A14E9ACF05ULL, 0x77E8AE5CA267D86FULL, 0x00F36EE9BCF5D3F7ULL, 
            0xE03574255AEECB79ULL, 0x66496400EC47628DULL, 0xAC9E592883981604ULL, 0x3831EB0C80ED37EDULL, 
            0x365FCA13917DF8BAULL, 0xFDA344D21A040F88ULL, 0x871350E314C5414EULL, 0x4CF3DFC12FBBAB55ULL, 
            0x4BFB60ED0FF3EA5CULL, 0xFADD048A5E0843D7ULL, 0x8539A398BE1C5480ULL, 0x81D0A2C3B99D07D6ULL
        },
        {
            0xB10F376C172A8887ULL, 0xC716291011F4F5D2ULL, 0x9B7366DCC35D6FF2ULL, 0x1D2747F23D25ED7DULL, 
            0xEA0CBD71AEF74F97ULL, 0x454BE95B97C97418ULL, 0x2EAEBFEEC5C5BD56ULL, 0xEDFC39133851318FULL, 
            0xDC473312F1C43F21ULL, 0xB1162E8B47482B1AULL, 0x095C86BE058FB289ULL, 0x50F51B8E79E2BD36ULL, 
            0xD4E0DD7E7ECF3E69ULL, 0xCD5F1BDD9279947FULL, 0x3A99F0726F248C57ULL, 0x31C3E0098082BC97ULL, 
            0x931A72769147D6D3ULL, 0x6D693FCCA516D7F1ULL, 0xB229E60A97DDE050ULL, 0xB63360053F18943FULL, 
            0xA09114D1199844BCULL, 0x9BBFAA791DC3580CULL, 0xEC53AF9B5E4E5005ULL, 0x584893CAD7B8CED8ULL, 
            0x637DD2B276D4230BULL, 0x817315B60819E69BULL, 0xB7D030B1F4EA432AULL, 0x0D94EE432DDCD1B0ULL, 
            0x9FC6AA6D093D9D43ULL, 0xB002CA1E316EFF92ULL, 0xAF68CD7FF95CF993ULL, 0xCCDE7EC075870F03ULL
        },
        {
            0xAFC1C874B02C34F5ULL, 0x00A6A4D3FC6B5FCBULL, 0xD185AE0C03A7E2A0ULL, 0x7AD8609FC1B4A2B4ULL, 
            0x7C9E7EE60AEBC051ULL, 0x30EBCEF749EFC83EULL, 0xEB6DAE97FCBE9763ULL, 0x466C062B95DD1C16ULL, 
            0xD0628D473F8B8370ULL, 0xAD34951EB3CD4361ULL, 0xE6F8DF2432668C46ULL, 0xF01D63AB4A1AC6E5ULL, 
            0x4FD8BF97DD88AEDCULL, 0x17967BA059B6FDE0ULL, 0xFA50A81762C1991EULL, 0xBFD79E7652774360ULL, 
            0x01B595BB184D42FCULL, 0xFA86F6C5C4FCD04CULL, 0xFCCD82BC3A391ED5ULL, 0xFDAD3518F398D704ULL, 
            0xF4F27C6DAA30D9EDULL, 0x334D17C76659F3ACULL, 0x870E8351BE450D42ULL, 0x62393A968A17999DULL, 
            0x2FD9161D915B9EF9ULL, 0x6CADC02C45013F9CULL, 0x625A61F1DAD09284ULL, 0xF99FEC1667DBC569ULL, 
            0x6C655A331D5B123DULL, 0xB3AD3339B525E05AULL, 0x42B3B667C1961F76ULL, 0x6E03114CC32BCF6EULL
        },
        {
            0xC6D6C70AD8202768ULL, 0x7242705F1ADCA372ULL, 0x7AEB7E5B7740598BULL, 0x8560299A8F89B8D7ULL, 
            0xC7B1D4F95B091FECULL, 0x93C8A66C63E435BBULL, 0x1B175B6124D8BB90ULL, 0x6AA94C348596B5D3ULL, 
            0x5D888461E19B38A2ULL, 0xBDAD2C9D960B4187ULL, 0xE6EEAA88E067C473ULL, 0x57400423733E7952ULL, 
            0xEE494CD0FDA0D155ULL, 0xF90C923B4808EBC0ULL, 0xAE038B8DAC8C51F2ULL, 0xADF0BC8DF51AF0FBULL, 
            0xAB34CAD70806E4C6ULL, 0xBBAE226328E0984CULL, 0xB983853E3A8356CFULL, 0xA5FE8217B7B1EB80ULL, 
            0xDE9BBCD48723DEE1ULL, 0xAED2CFDCBC743F58ULL, 0xE77E5EB874AD9CABULL, 0xF68D4E6C4EC3ED89ULL, 
            0xC1B7F9157E857060ULL, 0x54C1B869ACB3CC35ULL, 0x7F77CDCE737B9C3FULL, 0x4DD6458AA8FD5418ULL, 
            0xC051055BE2E5ABC1ULL, 0xA422055CBA28F897ULL, 0x83110544F01FA34CULL, 0x1BCD1F41B42791CAULL
        },
        {
            0xCD24485CCEB23A11ULL, 0xEC1022986CFDB016ULL, 0xFE8CFFDEBE42E19FULL, 0x377E1D7294B61A1AULL, 
            0xE2F5688BCC6778C3ULL, 0xB9D40DE28FACAC10ULL, 0x67A9998063981AEEULL, 0x5B1CEF3EACFAF5ECULL, 
            0x01681905D9D1D61CULL, 0x9A2F1EAB582F4916ULL, 0x4A92742B6A3B769EULL, 0xA65AC2DA986B0490ULL, 
            0xA6D567F1137413B5ULL, 0x66C897881D611EAEULL, 0xA657545F2473CF4AULL, 0x1878E8F55C3304A5ULL, 
            0xBA0FB3CB038A8F6EULL, 0x122A4773475CDB4FULL, 0x47AB95947E370D4BULL, 0x57D3D98F7E7FF0C3ULL, 
            0x27FF78D3F60812F6ULL, 0xE0591FAF2291D2DDULL, 0x5A09CC02E70F23DBULL, 0x92C9CD38982231E9ULL, 
            0x68215FCC3AAE468DULL, 0x8876E6C54593F45CULL, 0x837A95E9E501B3E9ULL, 0x541A50F17310A0F2ULL, 
            0x31490D1CE34F89D4ULL, 0x8D04EA40D8913CCDULL, 0xC1F11721A7CDAB4EULL, 0xCEEAC146DA9A4091ULL
        },
        {
            0xDE2F628BD72B5222ULL, 0x61BE60D4681A2941ULL, 0xAAFD0C8496792260ULL, 0x3378CC48CE742DABULL, 
            0x37134B9F4297852EULL, 0x33522E73282261CEULL, 0x5C43C8D01E1096E9ULL, 0x5EA276E14C96A6BFULL, 
            0x7BEA3B0059B7F76FULL, 0x61004B676436E7F2ULL, 0x791B2B7BD217141CULL, 0x2B31B210E47F0C57ULL, 
            0xBB466667AFBFEAFBULL, 0x3EF89C19FCD4F7B7ULL, 0xC17B0FA029D235A2ULL, 0x3ED09C32527A885BULL, 
            0xA5008897A5794DB7ULL, 0x27B2B60585F4F4FAULL, 0xFC080D77111C9545ULL, 0x9F6156F6DF780292ULL, 
            0x26DE83C1488CB229ULL, 0x6F5CC359AE2720D9ULL, 0xE82FBF1E5CD84A64ULL, 0x8A8EAF175ADDFEB0ULL, 
            0xA96B80FE488336F0ULL, 0x0FE32F5844FE1673ULL, 0x918EDBC8CC41E421ULL, 0x8A4060ED504569A1ULL, 
            0xB75F1EC2878127B1ULL, 0x2667EE3C6A987E97ULL, 0x8FFB6374C5F7404CULL, 0xFBEB2BA581AAD0D1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Castor::kKeySpawnAConstants = {
    0x2621A838405125B8ULL,
    0x34C6BF4DF9D8DE85ULL,
    0x65CA1A0EABEDCAD8ULL,
    0x2621A838405125B8ULL,
    0x34C6BF4DF9D8DE85ULL,
    0x65CA1A0EABEDCAD8ULL,
    0x1546F3BF89CDAC27ULL,
    0x7F29C94AFF533AD3ULL,
    0x1C,
    0xD4,
    0xD7,
    0x52,
    0xA8,
    0x86,
    0x30,
    0x5A
};

const TwistDomainSaltSet TwistExpander_Castor::kKeySpawnBSalts = {
    {
        {
            0xF40F6701A1CB64E3ULL, 0x969BF168C5C03498ULL, 0xE048E752BB0C1B85ULL, 0xA0B01780549D2B9EULL, 
            0x8ED3523CD4CD16B7ULL, 0x49385161B5183D73ULL, 0xE96719FB6C8A9E75ULL, 0xCC4A6FBA07D27FC1ULL, 
            0x2FEAEEC8B4DD90A9ULL, 0xEE843A548E070B46ULL, 0xD869826BD4E073FDULL, 0x767DAEA603BF19E8ULL, 
            0xCCABA896FD5AFD55ULL, 0x5633F2ACCB04D559ULL, 0xD960442477C84F54ULL, 0x968B9562D7A73D5BULL, 
            0x3815449574F6603EULL, 0xF795BA8796638B6CULL, 0x362D80A182CA37DBULL, 0x098AA21A10745D98ULL, 
            0xE56D87B2AA4F17ABULL, 0x3ADE40C2310F894AULL, 0x6F98E953FAC5E7BEULL, 0xCFF9B7762F11C140ULL, 
            0xF564F95CA76EF3F0ULL, 0x39526CD57BEB3F1EULL, 0xB4002517C82DF00AULL, 0x395272076327EAC3ULL, 
            0x0E64D88A741FDCAAULL, 0xDEAB3F676F360281ULL, 0xCC23C42999ECF871ULL, 0x3916F0A020901BA9ULL
        },
        {
            0xDF117B7A7C9C8393ULL, 0x82CF455908716305ULL, 0x56A3A5DDAE405346ULL, 0x3A72DCCCF5445BC1ULL, 
            0x48E296709D0BA081ULL, 0x74F70043F590A45CULL, 0xB489CDB9D0FD0E53ULL, 0x11FDB04C5E920253ULL, 
            0x5F2D430F73C98F02ULL, 0xAF15888200884168ULL, 0x0324FAE85B73F508ULL, 0x6EA0BC81079BCEB3ULL, 
            0x036F2A55146A105FULL, 0xD34617411FC5C8EFULL, 0x6988AAC9A611CBD4ULL, 0x2551712D60F193BBULL, 
            0x8F6E219917E5BC78ULL, 0x4C981080C3A24377ULL, 0x1A5890CABADE9CA4ULL, 0xDCF9E66814211FBCULL, 
            0xB10605DD665A69D1ULL, 0x98E75334C3C813FBULL, 0xA88088EF23C06A7DULL, 0x8ED11BA745D3555AULL, 
            0xB031B968BFE553BBULL, 0xDF7CE3808B134252ULL, 0x5482C49F3F109F5AULL, 0x5498FC2C82FBEEBDULL, 
            0x6F61563332FD0F2DULL, 0x9A227B322D6E59D4ULL, 0x420B43C454668C61ULL, 0x735F7DE4B0A89E30ULL
        },
        {
            0xE3CDF52EAB97D60FULL, 0x765521B36B94AFA6ULL, 0xAB33C703D5053CE9ULL, 0xE9FE7AC7EC4FB551ULL, 
            0x4FCFC38EAEA74498ULL, 0x9612AA6C2EDFE9E0ULL, 0x37DC74E1CFCCFCD9ULL, 0x839318E8FC3899EBULL, 
            0x3437460DEB9D5F6EULL, 0x5059999008035638ULL, 0x85C79ADA6C329B07ULL, 0x31F8AA34CD0FE9E5ULL, 
            0x92C434806F6391D7ULL, 0xCF7FD368335D0773ULL, 0x009F9EB8DBB08ACCULL, 0xACD24D054863E920ULL, 
            0x53C9F64B193E606BULL, 0x4199C7063ED2C10CULL, 0x19B753908175EEAAULL, 0x422F5B3F6E176E33ULL, 
            0xE8B0DA26A6AD9480ULL, 0x999B1D65F1EFD1EBULL, 0xD1C347A63A3C51DFULL, 0xEB15DF83EFB7EAA3ULL, 
            0x49983A6C80166221ULL, 0x9AE31F39E331EA19ULL, 0x570C7C2F36847849ULL, 0xCAF0B60BF5FDC51DULL, 
            0xC90F2D939F257C22ULL, 0xE3EA6C04585D99DAULL, 0x71D14E951194670DULL, 0xAD16718750632120ULL
        },
        {
            0x926E7D5FA396A950ULL, 0x6E03CD47F9427595ULL, 0x7343AEDC6C96961CULL, 0x7498E8A924FF8E20ULL, 
            0xAF6D2EB424A3ED1CULL, 0x0937B8B7BA06BD23ULL, 0x928EC8D4980B66B9ULL, 0x5880C90CC70CB8CCULL, 
            0xFD65D33F7FC74284ULL, 0x1897817F4C4BAB1FULL, 0x4EE31043DD5663E7ULL, 0xDFE19FF1625A9448ULL, 
            0x70312295B9646CACULL, 0x93F4155A495E8B8EULL, 0x013A2BC46A757891ULL, 0xCF5B03ED1412C169ULL, 
            0x411368100AE98118ULL, 0x98D587C5AF34B1A3ULL, 0x827268DAA12AA91AULL, 0x0502C0F1B4AD5686ULL, 
            0x4D569017027A31E3ULL, 0xEDE38F0CD96A0663ULL, 0xC3F9E1CE1DCB68BDULL, 0x953855B2D39F60BDULL, 
            0xC9BF1B6CF529DF16ULL, 0xF52C764633B60CF2ULL, 0xC67B5BA7D6008B10ULL, 0x62848BCEB7C4EE50ULL, 
            0x343E30746AB6AC2FULL, 0x9A2232979071B093ULL, 0x2C06F0841552E7DDULL, 0x74DCC76A6F232BA9ULL
        },
        {
            0xF85C91ECD3F2B396ULL, 0xD6A278B8FD9FE23EULL, 0xE89A3FB30F31C23CULL, 0x4CF20FCB9AB9F46AULL, 
            0x68402166A291B742ULL, 0x05D75595C0A8472BULL, 0x7B248BA14A466BA6ULL, 0xED061D2531037B80ULL, 
            0x92B05F9188710EB9ULL, 0x9CFB6FC3166ADB83ULL, 0x1F9697C49294FEADULL, 0x69934CC0F0EE2194ULL, 
            0x56C59BFC43387B2FULL, 0x8D61FD5616526758ULL, 0x72A89E8D1B6D82E1ULL, 0xA2363BD4D1A7DE7DULL, 
            0xCC6AE19C458D407EULL, 0x199AD3B33DA9C58AULL, 0x00333BF9932CDDA0ULL, 0xA6ED13F47390CFA6ULL, 
            0x4158E1A471B17059ULL, 0x10D3E7C1EA026FC2ULL, 0x4FF902CF855BE283ULL, 0xC46B38F5D056E0DAULL, 
            0xA9C3D16BE6545E0AULL, 0xDF8CB341C01EEA9DULL, 0xC393CAA6738FD08EULL, 0x0E7012E0CBB23DF5ULL, 
            0x76EC545C72367747ULL, 0xC73EB3BFE2B4536FULL, 0x71CD90E60404591AULL, 0x88738BEA776B1A10ULL
        },
        {
            0x42CE0F4C75070076ULL, 0xBA45291273C3D839ULL, 0xF148AF3F21E7D91EULL, 0x6CABB09FD97E9BCBULL, 
            0xD2FFA4E2E34C333DULL, 0x1D7D18737C1EE90EULL, 0xCD0B195635E27F7AULL, 0x102DDF543058C4D8ULL, 
            0x5CA79CA2ADBEF8ECULL, 0x2F4A1CDC8FFDA781ULL, 0xB727FADF24B2B82AULL, 0xC751A17E4A394C7AULL, 
            0x705417A03F339148ULL, 0x7BDA2D762F686228ULL, 0x73C8DE115D1420D2ULL, 0x318F9A90807105B9ULL, 
            0x20994262FFAAC195ULL, 0xE1022F6C003B77FCULL, 0xC09F0C9A9D3D5222ULL, 0x164EEE9FEA2595D3ULL, 
            0x34371C8929A863E5ULL, 0xE1988DFA62ADC54CULL, 0x54751DA186120D55ULL, 0xCB009E5905721C34ULL, 
            0x790A7D3995A00A07ULL, 0x2A1BE5DE401A1CC8ULL, 0x94E3AD6633E0A1F2ULL, 0xD7CE3B701F1FB3CDULL, 
            0xC524C90935E90FF3ULL, 0x7AD4214489349F37ULL, 0x4235CAB980B73382ULL, 0x237F4A37CB8070DFULL
        }
    },
    {
        {
            0x7790E1AEFAA72862ULL, 0xB7130D7C2625342EULL, 0x15B677DE53BBFB1EULL, 0x11370820EACBF659ULL, 
            0x691BCF50F02BD309ULL, 0x9038CFB624851691ULL, 0x2AC72BD668BCAFDDULL, 0x8B1B697BBE9218D7ULL, 
            0x00C02F0BC305EA4FULL, 0xC96B08425EC0D26BULL, 0xE428E62450F09A03ULL, 0x8DABB47273FE5EDEULL, 
            0xF25986D876268527ULL, 0x50410C8787F0F098ULL, 0xF201E81790B1B3DFULL, 0xFB4395C5FF771F22ULL, 
            0xE56379A08C935E07ULL, 0x9313C4B546E7965FULL, 0x49EE7A00FEA0D9D5ULL, 0xA26DB9067D255613ULL, 
            0x404E600A1B168FC4ULL, 0x59C1ECE9D8C9F8A8ULL, 0x7C9C49B981F149E1ULL, 0x69B4FA91855F561EULL, 
            0xDDF6036551C0415DULL, 0x9E54099E79675571ULL, 0x1AE26A834C44392CULL, 0x306DBA063055E6BFULL, 
            0x5D5D1F29D57FD261ULL, 0x18E438A73A35E02CULL, 0x5FD08068B19E28B3ULL, 0x9CF6A762ECA2F7AEULL
        },
        {
            0x98D87CF6DC240BA5ULL, 0x8ACDE66602F95F90ULL, 0x3786D9F4E17CEA01ULL, 0x0D82AE3D0D4E5548ULL, 
            0xD114D6B68E1F4918ULL, 0xDAC0D4D892D12E2DULL, 0x2C26284AEDF01D96ULL, 0x7EC62D05C41D8BC6ULL, 
            0xF3B5E42AEB5AB8A5ULL, 0xBAD29FAE86E8A741ULL, 0xBF9474F476CB884CULL, 0x9C516610CB14CE71ULL, 
            0x902C0039DBDF971EULL, 0xA3F5E934E7635C8EULL, 0x2F37C6A669EBE5BAULL, 0x72A15537A644AD06ULL, 
            0x98370993F7272A0DULL, 0x0D3AC69BD0BBFFB6ULL, 0x1A07740CE19BEF54ULL, 0x0C9D6582B37DD52FULL, 
            0x3304837693F6E038ULL, 0x02C969B0E0D24AC9ULL, 0xF7C31AA13CE15368ULL, 0x52CCAE727BE70C90ULL, 
            0x8E3BB97815E71053ULL, 0x9A6DE236C6A5698AULL, 0x16C3774FDB74ECC9ULL, 0x63899A04C1593821ULL, 
            0xC01FB2C22B76FAECULL, 0x6C92EBE0DB569C73ULL, 0xC02AD92FBCEA6A46ULL, 0x2200AE012319D5CFULL
        },
        {
            0x2981D5F7CFBCD078ULL, 0x140E45A62B379861ULL, 0x2D03DF23A0DCF7F8ULL, 0xBBFA7BE8CBB21728ULL, 
            0xDC65D1BD4E5811CDULL, 0xF731518C07FC7CA8ULL, 0xBEBB3EE76607F51EULL, 0x5AB28587B9C778A5ULL, 
            0xA16B6AE86CB11BB6ULL, 0xEB1C6890F6D1B65FULL, 0x6D8BCB70CF56084DULL, 0xB9F8AA20C0A37C8AULL, 
            0x4D0A03B3869FE9E7ULL, 0x5D6B58E8DC157BC0ULL, 0x162BD0D3B697824BULL, 0xD35F58250A43E16EULL, 
            0x34F74C71DECBA3F5ULL, 0x0045B27BF31CB396ULL, 0xB8A1DBD857670185ULL, 0x0591CF8BA521442CULL, 
            0x083ECD170D5C09F4ULL, 0x1825B9E9A452A8D0ULL, 0x7BF029FB527606D3ULL, 0x791CC6B9A017E695ULL, 
            0xF18D3AA52B40841CULL, 0x8C3AA83B7AE11BC7ULL, 0x8A29A2CFF61664E4ULL, 0x1D9C1876CE76027AULL, 
            0x44D5C6E37973EF8DULL, 0xE91FF078F65EB120ULL, 0xD07BDC3B8CFC0642ULL, 0x9F72E203C4837331ULL
        },
        {
            0x635B4BEA993BD703ULL, 0x601AD71737721A7AULL, 0x6A8003B6495FC3AEULL, 0x598F1CBD5756DDB6ULL, 
            0x48B8A17BA5C6BD34ULL, 0x279FBC2341289037ULL, 0x5946259CB8B9C4A7ULL, 0xC65E26A816D6AFB8ULL, 
            0x806D68A24C931E26ULL, 0xE7BB74C757F526F1ULL, 0x2CD3C86F264C083CULL, 0x0C98800D006AB01EULL, 
            0x2BEA60BDC34F7169ULL, 0x3718CC0D71CA8B72ULL, 0xA04DCD932D136D34ULL, 0x4CA432D36182811FULL, 
            0xF038A55C4B6D0687ULL, 0x2759969E559323B0ULL, 0x7F0699CF5B6928CAULL, 0x157A7F7194750E10ULL, 
            0x1A822E690EF87F96ULL, 0x385C4989FF311C56ULL, 0xBD79BE2DADF6AB51ULL, 0x3BA05952862336F7ULL, 
            0x21947F6AD2B4FE4BULL, 0x817D3AB137900F53ULL, 0x157E8C0EB7AFC3BBULL, 0x86F2742D8ACD3338ULL, 
            0x62FBFF8FA5A39DE8ULL, 0x051A029AC8610BAAULL, 0x719AB055ABEBC850ULL, 0xD5A91F9613B623F4ULL
        },
        {
            0x33B833029946D2E4ULL, 0xB61A466CFD46E38EULL, 0xF6345778CE3D9DB2ULL, 0x8A113569A1B468FFULL, 
            0xE4233870D2FB7E9EULL, 0x25B39A4D1FF41CD3ULL, 0x013DA2601F63A444ULL, 0xB9726AA25790C6FAULL, 
            0x10D814725CB82F16ULL, 0xCBF0B0822D66E6AAULL, 0xB337821062FD8CD1ULL, 0x10203B2BF26D3877ULL, 
            0xADC1CB481DF3051CULL, 0x77967F53EC5D6F49ULL, 0x6065D50360E5A1E4ULL, 0x190BEE35A0F01282ULL, 
            0x872B447DD8CB2035ULL, 0xD2B28D4364A3211BULL, 0x3F08A50ED2BD5046ULL, 0x49E41FABC5656F23ULL, 
            0x1B85921C14D415A7ULL, 0xAB9CB6986136E4A9ULL, 0x6C5213A65A5E491DULL, 0x29371DDDBB8FFF46ULL, 
            0xC402E4483914080AULL, 0xC88EAA7AEC280209ULL, 0x9B5D1F715AAD76A8ULL, 0x66180E3976272F69ULL, 
            0xB417AC0206E5372AULL, 0x8678EA42CDC9A0D7ULL, 0x26EFCE604D2474CCULL, 0x4207904E2DF61E94ULL
        },
        {
            0x78B98BFB01B1340DULL, 0xA568D6A5BB698D6FULL, 0xC94AF060EA960C60ULL, 0xE50D554B35862B7CULL, 
            0xDB125F6E588A3D09ULL, 0xCCB9DF489B49321AULL, 0xBFA5D9B293397F18ULL, 0xDAB7E5A1DF601E9FULL, 
            0xF62AE099C6EFECCBULL, 0x6327518683E5928AULL, 0x451B8E95118161A7ULL, 0x671714B7DE8BB798ULL, 
            0x26888028431F0204ULL, 0xC7C12C950CFAA48AULL, 0xDD82BF2673B85C24ULL, 0xAF5F03E2C39DD50FULL, 
            0x93251E06AED6FA1BULL, 0x9C061A07FB3AB29AULL, 0x09A0030E04171EA7ULL, 0x5A6DE3989E88C26BULL, 
            0x6490E842231562D2ULL, 0xC56FC789E4842B4FULL, 0x96575CEA23D7796DULL, 0xCC896560B6A9C43DULL, 
            0xEA1ED6BBE46E2BC0ULL, 0x031B5E1A970B7613ULL, 0xB66AA7F69268E0FEULL, 0x4ED35B44E485261BULL, 
            0x96581F1BEBED6E80ULL, 0x94E56BB183510382ULL, 0x1D238E9810D057A4ULL, 0x79460725F9AA8479ULL
        }
    },
    {
        {
            0xA30DCA484594EC6EULL, 0xAB0A7B6E13D2F3DEULL, 0x20854D27E1EDD6EFULL, 0x11B78227D178DA7FULL, 
            0xC836BC7E3B290F9BULL, 0xDAD94A17C0EEF14CULL, 0x3D6DE0609D31ABB4ULL, 0xE09828D52CFA86CAULL, 
            0xC7093FE4F55B64DDULL, 0xC7D09196F70E572BULL, 0x7DC3EF130194CA82ULL, 0x618DDD63E4852816ULL, 
            0xF9292A078A306F8EULL, 0x18221264DF2B15E0ULL, 0x6E387370FE296A19ULL, 0x15D3D9EACC539936ULL, 
            0x51A68A565C2D5DFAULL, 0x1D0BE1F9CEAA132CULL, 0x9154C6B9874EEC7FULL, 0xEE76F8E6D276E872ULL, 
            0x7D1778298740D724ULL, 0x241B2D34DBDD6F45ULL, 0x0C1814E13D479E7AULL, 0x2F14AC1777E50CEBULL, 
            0x714CBF5BD3C4C2E4ULL, 0x8A9E33CCEC7144EEULL, 0x756A4CD17DE16976ULL, 0xC76D7F40231FA4B5ULL, 
            0xF314D0AE94A29898ULL, 0x63DFAD856886595FULL, 0x533C72539CD4BB67ULL, 0x118AE5963A10B9BBULL
        },
        {
            0x89CD7B681941D3F2ULL, 0xBD11C9319E3B79E0ULL, 0x4EE226E479D4E543ULL, 0x6E56E4101810E266ULL, 
            0x6C2BC1ED01B8CF44ULL, 0x26684883BFA6E15BULL, 0x24250D2D4CBB0194ULL, 0xE15A8B29229608C6ULL, 
            0x240860D76543E44AULL, 0xAE96ADCEB7622CDDULL, 0x6E6F755B66561523ULL, 0x3132DF923F6F6294ULL, 
            0x961ED135944A51B9ULL, 0xE14726FFABB62D4FULL, 0x949EDCB4922056EFULL, 0x09A77FA91B0CD6DEULL, 
            0x5CF2C7BAB7B2CAF9ULL, 0x6C2F2214348210CAULL, 0xD56C8A0B4F0A6691ULL, 0x0299AB24C038DCFDULL, 
            0x30C5F45FCCD3BB7CULL, 0x2D43A391FCCD8B3EULL, 0x4F18B7C65BDEAE45ULL, 0x4BEE1D68FC9F18B5ULL, 
            0xB87D4D466100F24FULL, 0x7BB59655D4283483ULL, 0x51CBDB8DD7D81598ULL, 0x5985201378F2288BULL, 
            0x7A163564E8EC89DDULL, 0x39FD223126B0DDDBULL, 0x83B710E0E2E202CEULL, 0xACE09AB73DC8BBC4ULL
        },
        {
            0x8E6A8191A2B8018AULL, 0xE7E3AA0C37BCEC0CULL, 0x14140C7CFD3CCC32ULL, 0x4C1085F4A9B88FC6ULL, 
            0xD4BE62AFF2DC36D5ULL, 0xD8D8625DDBDF2F6AULL, 0xA58A71B9BE1C9F41ULL, 0xB52A9C7A717DB054ULL, 
            0x39F8454F65A94937ULL, 0x54F1C5E680963A26ULL, 0x79A14482185EBF22ULL, 0x0B345A819206D609ULL, 
            0x4E74DABC049F4078ULL, 0xA3196BE0B7AF6B0DULL, 0x0AFA0E1EE8CB7533ULL, 0xFB05CBA8CBA20881ULL, 
            0x66969BE433FB0F6FULL, 0x06556FC8CEEC72CAULL, 0xB5CED5D3696E7357ULL, 0xC0242700509E7C9AULL, 
            0x5B871BB1C9FAB08BULL, 0xCC8128F4426AA621ULL, 0x772816B05AB17423ULL, 0x0A0FABEF9466473DULL, 
            0xD13A383E67951D62ULL, 0x4ED4DFE1050A1511ULL, 0x79E8CFCC40AB785AULL, 0x9790564A24FA404AULL, 
            0x92564D0531AD2ABCULL, 0x7C5B5F5CCB53A021ULL, 0xF67F6F83AB15C9C8ULL, 0x8935E02951BC6111ULL
        },
        {
            0x8C51A5AF7AFD1AB3ULL, 0x3625868832701E0EULL, 0x1C76A0DB97FDE0DBULL, 0x139F85AFFE50713EULL, 
            0x048173BC93956680ULL, 0xF1479A10A485E80DULL, 0x077DB76CAE3929ADULL, 0x1426B845822FA7D4ULL, 
            0xAB52C621BEF23566ULL, 0x0DBCE678CD9EF528ULL, 0x1AF8971DB55DF8DCULL, 0x37B45C2C3AFB0A98ULL, 
            0x69A56A3862828F31ULL, 0x04487925B8C31D75ULL, 0x5C71C253EA53745AULL, 0xB046195D0BCB8540ULL, 
            0x997E4644A97A0A2EULL, 0xBCDF534A531337D0ULL, 0x6A95C3C8DB9BE89CULL, 0x33AC81FC2A68AA07ULL, 
            0x2A5348BCFE46B49BULL, 0x6C2C012EB71492D5ULL, 0x7994305CB4104F47ULL, 0x6B59924BFD64B04FULL, 
            0x9493B0484483A94DULL, 0xE32973E2F025B210ULL, 0xCCD9CA10A0589C62ULL, 0xAC32DBEE9A1BF6A0ULL, 
            0xF6907DD77EE1BE2DULL, 0x95EBA5D65B35004FULL, 0x6369F6ED1E2ABE2EULL, 0x39B7EDC94978734CULL
        },
        {
            0xE278FB4D2EE62A49ULL, 0x4FE2944C4B754D8DULL, 0x37F142FC1916ED29ULL, 0x4574985907F3C1E4ULL, 
            0x4860F72FC9B6AE55ULL, 0x3CA7C9CE73B14F07ULL, 0xC6A92E71BBDF947EULL, 0xA25626837D354CBAULL, 
            0x12DBBEA14F12B072ULL, 0x791AB4BF8A62BE5AULL, 0x62C351BC484D3472ULL, 0xC42E2FCC284B7E26ULL, 
            0x2F9DD3E20E5F8D72ULL, 0xE6C78E30F962A386ULL, 0x5F98246E9DD20DB9ULL, 0x5D0474979CD2E602ULL, 
            0x96440F0F2C7B66E5ULL, 0x3BD3EEC1FDA1899FULL, 0x15EA3B89A5DAD3D9ULL, 0x5ACD41F307AC6C8DULL, 
            0x7058C063D5441FCFULL, 0x1CABE14FFDDC5B7CULL, 0xDE3F4B4EC6CA8D21ULL, 0xC2C871A2B74F64BCULL, 
            0xDB017704E67CBADBULL, 0x6ECB866AAFE621D9ULL, 0xBBB3FFC36CEDC509ULL, 0xC68873DA3792A3EAULL, 
            0xFCD116259E9C2F31ULL, 0x4768916F02AD1066ULL, 0x24633B01B5ADE64FULL, 0x600C683D6606964AULL
        },
        {
            0xC8A9121A140A4F67ULL, 0xBA775F0956DA261BULL, 0xFA7BABACFCCCC7AFULL, 0x75DF520435A5152FULL, 
            0xCCEBD005CC097D19ULL, 0x7B406111D5688517ULL, 0xBB51C849F2D1213CULL, 0xA095E4D972E2EF5CULL, 
            0x1124ADA1A3A41144ULL, 0xAB43A9D5B5C924D8ULL, 0x90E13C6CD0283A8AULL, 0x7D4ED5E21144BC28ULL, 
            0xA9F61AAB693024F9ULL, 0x3EC26C4E0BF3282CULL, 0xE112FDC0DB50F77DULL, 0xC7E43BE717A30D14ULL, 
            0x92D210D620940FD8ULL, 0xFFD1349E7F53AF87ULL, 0x8B43D1AD407A3949ULL, 0xBEAB226C4123AB6BULL, 
            0xE4F2FCBA83AE3BF5ULL, 0xDDE05BADB35C4D72ULL, 0xDB7D096B16921F4DULL, 0x531556EF2A45B1F2ULL, 
            0x604FB4C80DBDE5C2ULL, 0x443F1B9C3EA847D3ULL, 0x7799EF51200A2D1AULL, 0x2E14422DB2E94488ULL, 
            0x7A5BF1AD2A14821FULL, 0x47930A583082158FULL, 0x34EB168966F7587EULL, 0x35A83CC52B631270ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Castor::kKeySpawnBConstants = {
    0x48B0A55A65634574ULL,
    0x2F23B0E5C9F02A2FULL,
    0xF19715AE0A4597B2ULL,
    0x48B0A55A65634574ULL,
    0x2F23B0E5C9F02A2FULL,
    0xF19715AE0A4597B2ULL,
    0x20792E6257ADD319ULL,
    0xB5BED544C5794C8AULL,
    0x81,
    0x87,
    0x7A,
    0x0B,
    0x58,
    0x41,
    0xCE,
    0x3F
};

const TwistDomainSaltSet TwistExpander_Castor::kSeedSalts = {
    {
        {
            0x61B311809248BB76ULL, 0xB51F0EDE924C1D22ULL, 0x2F9CECB11BF37AF6ULL, 0x697636DA8A1FE2E0ULL, 
            0xD02EDBD64EA715ADULL, 0x27A0DCCD1EFE1506ULL, 0x82A825A0A14E6730ULL, 0x5ED83764F7EBF7EAULL, 
            0x93E527015B2FA47FULL, 0x55A02253AC8C4ECFULL, 0xE15D2EE62A823259ULL, 0xEB2EF5D5C6132BF0ULL, 
            0xAA7EA37C926E4A99ULL, 0xD2288602849E62D1ULL, 0xC98C96A0E5AC4619ULL, 0xD3E18FB7E6CF3F3CULL, 
            0x00817968EAF105DEULL, 0x2DCADD25F707DDC9ULL, 0x542E3CC0C5A00536ULL, 0x6C06B5ECDB85ADDBULL, 
            0x44F5F212D3F5D1C9ULL, 0x40933557F3A5A78AULL, 0x87479C4CA6C61E7BULL, 0x3979C74A842A8377ULL, 
            0x55EBE42A154B8288ULL, 0x868E3CF1609EEBBDULL, 0x6B32ACC4F5A818F8ULL, 0x0A5CE405FA626969ULL, 
            0xC092703FCD586723ULL, 0x50DA0ED098314726ULL, 0xC85345163A23BDD3ULL, 0x0CE66ECA65C6CCA6ULL
        },
        {
            0x9829731A9224D3E1ULL, 0xDE350D6B5D7D3792ULL, 0x9BAFC9D602632BF1ULL, 0x8D59AFA23A4C7CC3ULL, 
            0x2436D25D35C4BFA8ULL, 0xCF1B9CC00A5838BBULL, 0x810BB0F0B6B97227ULL, 0xA7B969B72E98ED7FULL, 
            0x469758678C493558ULL, 0xA962453728E14FBBULL, 0xE5F85650F2667749ULL, 0xA0F43EEE292AE45AULL, 
            0xB3303D490DAAA628ULL, 0x4F7CB4CBFCF33A6CULL, 0x4DDD90660EB85B1DULL, 0xD2731CFDB25072DDULL, 
            0xF89061F0DABE39E1ULL, 0xC08B6099A0CD2C5BULL, 0x439865010A90CDBEULL, 0xBFC7703B91B29DAAULL, 
            0xD0FAAF3FDD6AE3C6ULL, 0x255623A32567A70FULL, 0xA8A8448B93DBBD61ULL, 0x588BC39613056A8CULL, 
            0xBB86B84C488C0150ULL, 0xA30A42D36B6F14A6ULL, 0x8E6D26B1D74FFC70ULL, 0x841E442FA31B42D0ULL, 
            0xEEDBE2EF76BF0175ULL, 0x8F8F37DE21F59AD8ULL, 0xEEA04DDEC06C5787ULL, 0x7D2219AEBED65CF6ULL
        },
        {
            0xE08E463DB8C4C3F3ULL, 0x094AF1592063DE9CULL, 0xE2CCDA556DEE3DCFULL, 0x25F011C283719D9DULL, 
            0xD7B38488F4211AAFULL, 0x6C5D35D0EAC90705ULL, 0x93FA78264468745CULL, 0xD25EF13183E1D03DULL, 
            0xED96DF6C416717C6ULL, 0x6C3608B55B0B2563ULL, 0x5B2D80F24E354CFCULL, 0xDCCC5F5750152758ULL, 
            0x440673DD567F46A8ULL, 0x276D9C22CA15345CULL, 0x754F6715CD9864A1ULL, 0x9A50EA66C5FB2AEDULL, 
            0xF129A543E6F2A367ULL, 0xF053AC911311053BULL, 0x53D8DC21B952B9B5ULL, 0xF47984E6CB7DC879ULL, 
            0xFD1FC57E309F8261ULL, 0x62786EF4A204CC9EULL, 0x8B725F80237F1E2CULL, 0xDA98D329A989BB07ULL, 
            0xB91AB36F62B0B470ULL, 0xDFD595388E8D99B2ULL, 0xA5465F5DC82285C3ULL, 0x0EB3439A5654D21FULL, 
            0x9D2E2653298ED1EAULL, 0x9E315B70E0A178F1ULL, 0x4C9E2D337E7E31BAULL, 0x1CA3DEE308C81E0EULL
        },
        {
            0x73D3BC9772ED80DDULL, 0x1B8222A51E49CC00ULL, 0x3919C3EE12CB78FFULL, 0xCD5C9D39A89C52D5ULL, 
            0x3DD05A70B8CF68AAULL, 0x60D00E4DD31B42CCULL, 0xD14EF83E58BAA050ULL, 0xBD5ACC08423C0CC7ULL, 
            0xCFACC5E025473ED9ULL, 0xA7FD71142D870B1AULL, 0xFB1C32E72F81C858ULL, 0x12BC5D86FD8CB75CULL, 
            0x4584C9AF160E260BULL, 0x3EC96B84CA85936AULL, 0x8B37C7EAF609A9C3ULL, 0x6A731C131BDAC44AULL, 
            0x9CCFE7CFA73B827CULL, 0x6ADB5D57EC00469BULL, 0x3248517B946829C3ULL, 0xB00E8C3C32928E64ULL, 
            0xA9B95343D9527229ULL, 0x98BA6483508638D6ULL, 0xA0FB7446A9D52173ULL, 0x372BC80BD9EEEB15ULL, 
            0x739B40D0B96F635FULL, 0x367A4B95ED5210ABULL, 0x3B26B4439C87CE37ULL, 0x0082EDE74A57D957ULL, 
            0x76AA3F0BE00420EBULL, 0x50C649E43D08F156ULL, 0xF319740FE2145A24ULL, 0xDD2826701665A4B8ULL
        },
        {
            0xAEA4C2E35BECA4CCULL, 0xDD507BD4291330BEULL, 0x18842DD8CC48DD45ULL, 0xE00D9A221C48691DULL, 
            0xD26F3C9E5464ADEAULL, 0xF038B1694935F628ULL, 0x27FD1111E6319D98ULL, 0x74AED042342A817BULL, 
            0x8CA89E9D159D1C71ULL, 0x6456B51CAF461F46ULL, 0x374D32CED22A170BULL, 0x1B29D5A995537AA9ULL, 
            0x719BDCEFD59D0AFDULL, 0x7743ACF37B5FB877ULL, 0x0718D4BF88662038ULL, 0x29C2F7782BEA40A5ULL, 
            0x23EEB330345A8EB1ULL, 0xD545C7FC9AD5C15EULL, 0xBE53EF57CCBFCD20ULL, 0x9A1832DF43F4025DULL, 
            0x07CE6A7713A4FA9DULL, 0x534EAAA35DF796F2ULL, 0xCC18A5C21FC676A4ULL, 0x772450104D023A77ULL, 
            0x567234A02B2EBB71ULL, 0xE25655B9A5BB0CA5ULL, 0xA6003B1CE15C3327ULL, 0xE7A28C41C5FF79AFULL, 
            0x4CC02DF5F7EB4E11ULL, 0xD38E691C46B89409ULL, 0x7C71FD3B73B2A072ULL, 0xB1597BE3828F1C57ULL
        },
        {
            0xE15D25585CB823BEULL, 0x3481052AC6C175E5ULL, 0xB6AF2294F7D17EC7ULL, 0x0483E69D64747E6DULL, 
            0x9DA6456E262689EAULL, 0x0910CED1F9928B97ULL, 0x9F7A319A7050581AULL, 0x8778FA92DECC5299ULL, 
            0xE94ED3EC62536D83ULL, 0x9AE27590475FC462ULL, 0x8859F16B67C7531CULL, 0x6BFD22D9A4F78690ULL, 
            0x682FD4BD28EF514BULL, 0x75050D47DBEF88ABULL, 0x570A91C17A0D29E7ULL, 0x7FF0EA42DA465328ULL, 
            0x85DEAB150F67A952ULL, 0xD22765E32EF96763ULL, 0x7677905325340390ULL, 0x7EE3FDC62D034EDFULL, 
            0x9EAE4F7CF55BED26ULL, 0xF54276BB92B72AA6ULL, 0x56F8F9147E2FEFF0ULL, 0xAD43C8D4423AE0E6ULL, 
            0x73B9B2D3A39558A3ULL, 0x663A348D7E952592ULL, 0x6F4FB9DCE6077520ULL, 0xD52903AA8F655EA1ULL, 
            0x8654F3D377E93D9AULL, 0x2D4217CDEE511B43ULL, 0xAD4BFDE36B9E32DAULL, 0xFE304D6D6C756C77ULL
        }
    },
    {
        {
            0x1A8A8C92046F84D9ULL, 0x78472192F01D1319ULL, 0x1F48FC06BE4DA6F8ULL, 0xEEF539A5BF463984ULL, 
            0x8F322E69A839E9EFULL, 0x6FAE419B1EF19B4BULL, 0x859586BF9813BA88ULL, 0x06E39E04DA836F3CULL, 
            0x735F5BC7C97382ABULL, 0x8134BB24C5D43775ULL, 0x60B0ADF8DAAE491DULL, 0x54BBAF514FD76D7CULL, 
            0xB4A8064F223C2060ULL, 0xE8EF958233D62161ULL, 0xD623B21F2ABF8F70ULL, 0x3CE621D2E72C9844ULL, 
            0x5DBE4F25517F923CULL, 0xE1A77D73E6D6D846ULL, 0xC63BC8D2AABEBDFBULL, 0xD65ACAA894798013ULL, 
            0x8FF7323B2FDED521ULL, 0xDB7E16638E4AF54BULL, 0x18E11ABB9EBE73D0ULL, 0x86A6C4D559638B8DULL, 
            0x7C3F9FEE83742CE9ULL, 0x4863F8D8DFF22E45ULL, 0xDD4C8007AF256BF9ULL, 0x47C92F5CFC34EA9EULL, 
            0xA5FD9F4811DC95B3ULL, 0x9AADAF2EF008C3BCULL, 0x6709C0333405E5A1ULL, 0xB5D49C6B7DDCC19DULL
        },
        {
            0x13639ACA32F4B0F7ULL, 0xC74015C1530075E6ULL, 0x39D647BCCE3F35C9ULL, 0xD0572D6CEB98D479ULL, 
            0x7C7A278E88739F6EULL, 0xD1A4454EAD695275ULL, 0xE27142FAAFF4EBCEULL, 0x603E4DBF1B48E4DDULL, 
            0x6A206A588DFC8A9EULL, 0xABC61DA4574AEC66ULL, 0x3BAC29F054DE4688ULL, 0xEB4D6903516D167FULL, 
            0x8D8519F9E6BA2308ULL, 0x56D8851EAC43ED65ULL, 0xA5ED845444D58622ULL, 0xB9A7BDB503369EF5ULL, 
            0x88D4E4DB0F27A757ULL, 0xEB85918D556733FDULL, 0x9BBCC4CFA2F45A4FULL, 0x878B03B522B78D02ULL, 
            0xB654056AB52A3161ULL, 0xFE04463FF512DEB8ULL, 0xC8B3DD12E41308B1ULL, 0xD02AEA5D9085B59AULL, 
            0xC7F5DDF48CD5CF70ULL, 0xAE4067385B9583F8ULL, 0xB69CC454BAA17425ULL, 0x3AD98636740368A6ULL, 
            0x4FCA2111AFC1E4AEULL, 0x0EE0DEF7164C3A14ULL, 0xFF6437CAE4A0FAEFULL, 0x92F971DC48C477F8ULL
        },
        {
            0xD802B00E715F402AULL, 0x8D54C2C40BBA561EULL, 0x22B16C909FF679A9ULL, 0x45C8004B3EF19AB8ULL, 
            0x3D1F26FBBD2273D1ULL, 0x1AC389D67C546266ULL, 0x785D71B6CC0A68F4ULL, 0xE4C68C7A5F457F63ULL, 
            0x8CBBBD6948ADD4A7ULL, 0x8B71ABE0AD39C18BULL, 0x356698EED074BA5DULL, 0x8626FFB4C4F65AEAULL, 
            0xB963AFCC6847427BULL, 0xAC5FB8A610F889E7ULL, 0x2920850AB45A5217ULL, 0x038115964697A544ULL, 
            0xEAAB523B4CFE6393ULL, 0x304A730B799AC724ULL, 0x84043969797874F6ULL, 0x6BEDF0E5B3761CEEULL, 
            0x3BDF60F74BDF99DEULL, 0x4842AED0BFBB85D3ULL, 0xCFBC1DFCBE355749ULL, 0xC723F499DF38FF60ULL, 
            0x30EA916CA9084B3FULL, 0x1CF966BB08074446ULL, 0xB43BA96C5516E412ULL, 0x7FA8C3E13EB5B196ULL, 
            0xB16BA79A50DC8EC6ULL, 0x95930291AAC900E1ULL, 0xA3A34CA68A14D66AULL, 0x96D158E8DE511F91ULL
        },
        {
            0x4439FAF602511755ULL, 0xB73A96C703B26856ULL, 0x6C582C6D8A1AAE6BULL, 0x2015251D9A904DC4ULL, 
            0x0A8A38BE38A6680DULL, 0x7E7343A06C30FCDAULL, 0x779B829CF462BB7EULL, 0xD610D1854CB74715ULL, 
            0x83D15CD02DFCB343ULL, 0xD9235F1B1A8243D7ULL, 0xD8B06544E9C4F99EULL, 0xB12FB69B72082F04ULL, 
            0xE097589B3E439770ULL, 0x408EFB79985233EBULL, 0x313932ABEE9A2723ULL, 0x2AB8308317CBC06AULL, 
            0xD9557054B19989F5ULL, 0x8B75F27F54CC8580ULL, 0x0C42388A9C0F69D5ULL, 0x22C0EE8E2FCA6666ULL, 
            0xF91E7D6043BE085FULL, 0x988F7091E3C8AD7EULL, 0x0B721D7F588340B0ULL, 0xB423D9D173C70015ULL, 
            0x1C4085DFDF7703EEULL, 0x042FCBE0C698FC3DULL, 0x5538350D92643E08ULL, 0x4073888745FE306AULL, 
            0x1A0DAE2B2827AA53ULL, 0x6159087A63788016ULL, 0x338A15CBC7748276ULL, 0x19CF024F652E879BULL
        },
        {
            0xAEDC33511324BD4EULL, 0xC739917EB50C50B0ULL, 0x30AFECF7E9F4DA61ULL, 0x5D26E688F660FD95ULL, 
            0x227ECC3E8AEB5D03ULL, 0xF0E72A097C83FD12ULL, 0x3366A087C191BC55ULL, 0xB6ABFEE12BA68080ULL, 
            0xF9057038BD214B05ULL, 0xAE8F403576EA6445ULL, 0xD4F216738CA2BFE7ULL, 0x42B541B86115A722ULL, 
            0x93865684880FA6F6ULL, 0x21FD75067D1657AEULL, 0x2AE783930AF0C66EULL, 0xEF9A39F630A03327ULL, 
            0xA4EA5D709FEBDBFDULL, 0xA07CA6499FF066DBULL, 0x1E26ADDD39B06A92ULL, 0x8FAC4542F6D62ABFULL, 
            0x6F4B168F388DF587ULL, 0xD65CB4542DEFCFC0ULL, 0xFB96CF80D7021022ULL, 0xD1BF57554198E69BULL, 
            0x1D7B0EFA946C764EULL, 0x183D373CFDB7E09CULL, 0xE64954D3C7B0C454ULL, 0x7EED493CDA36157EULL, 
            0xF4225EB895E24591ULL, 0xC6A8AC6731D7A48EULL, 0x43FDC165FE297522ULL, 0x0CBC805BD7A1FE5EULL
        },
        {
            0x8BE0BD18B39BF295ULL, 0x4BFDDEFB0FB582F3ULL, 0x2A54F094F1C23096ULL, 0x216E7CB234823C16ULL, 
            0xE55FE6D0B53181B2ULL, 0x427502E3B2F6B1ECULL, 0x0867D735C13DC844ULL, 0x512EBE6886BB5DE3ULL, 
            0x8D1E93376A62B0EFULL, 0x56A619425C81B3BDULL, 0xE34164A8C6C0FA6CULL, 0x7E2B2A27982B1795ULL, 
            0xEB59945E544A7C84ULL, 0xB851D255E839FB5AULL, 0xEF5F18138E697946ULL, 0x9519FE4D7CF95A7EULL, 
            0x5608FA7ACC581800ULL, 0x1E9AACEE661F56D1ULL, 0x50A9961049B3C980ULL, 0xFF289463F40EE830ULL, 
            0xAD2451A87DBEBD03ULL, 0x613ADEAB8B4A6F7FULL, 0xDB0E62C6455E097DULL, 0x27225D9D782D23E8ULL, 
            0xB186C5C3280915A8ULL, 0xB6E8281F3C9EE754ULL, 0xE7A0218B55B7D391ULL, 0x9D55B98ED473433DULL, 
            0x4ADC664811AFFF21ULL, 0xE397F208A2606293ULL, 0xC9E3B0B8CB4E9C66ULL, 0x8903EA555C9C9812ULL
        }
    },
    {
        {
            0x9953B31D2ADF5664ULL, 0x6A1435F66111F6D7ULL, 0x0624694E69FE7C26ULL, 0x459B9E286E0C8BF3ULL, 
            0x62EA6B8094BFFB74ULL, 0x0E957586F4498DC1ULL, 0xF29634B55B35F559ULL, 0x43EC13E130F0D15CULL, 
            0x90DA1ADCED606238ULL, 0xFFB25B38890AEF5BULL, 0x92A977E6693B5F9CULL, 0x98838E363CC3235AULL, 
            0x38F14DA2250424B4ULL, 0xD319D02FAA4CF728ULL, 0xC6055BA65AAF4162ULL, 0x463E973F7A5A79E7ULL, 
            0x904E432469187950ULL, 0x03CA17B3678C6CFCULL, 0x3DBD7DA02D12AB31ULL, 0xF0DEBA66867DD81DULL, 
            0x09C1650488BD4957ULL, 0x6709BB126DC900F3ULL, 0xC3FEB035F8EF3AE0ULL, 0xE535FBF5802EBEE2ULL, 
            0xF318CBC0B11440B3ULL, 0xB5FBB4693D63CD79ULL, 0xC6AF56D9F93D6EB4ULL, 0x90C7B61B47F8E7D2ULL, 
            0xE6D980C2EE19E26FULL, 0x37BD82AF41109053ULL, 0x7932A3B967B46C79ULL, 0x84234C3E1A96521FULL
        },
        {
            0xB617A9097D7E4DECULL, 0x87702F5073C32377ULL, 0xE71AB6E11B6A4AB8ULL, 0x09C94491EBEC36E4ULL, 
            0x8229299C83B6BD34ULL, 0x09E08AE6E8366D8AULL, 0x572A3FE2627136F1ULL, 0xBED039BFE1FF82AAULL, 
            0x3523432F449736F1ULL, 0x0782C19CD34D33C0ULL, 0xA745410D6605F681ULL, 0x3A681EF4F5D4ED9BULL, 
            0xCCD3B80D74310129ULL, 0xE31FC2843267BF5DULL, 0x17981FE241E28574ULL, 0x37F5F7E7F19B3232ULL, 
            0x87C649C6F7379784ULL, 0x0531500315C523E2ULL, 0xCBE882A412BFAA77ULL, 0x2734E7694B7A4491ULL, 
            0x89F7A0CD8CB76EA1ULL, 0xA810976599FD16C2ULL, 0xC3185FDA10462ACDULL, 0x4A4A7D697362714EULL, 
            0x4942B71155E6282FULL, 0xAF4EFB8D0CC8448EULL, 0x7AA2F4125D9DBE50ULL, 0xF90827F4F2CCF065ULL, 
            0xC5A5DEA0B9A58327ULL, 0x992FA80294C55B42ULL, 0xFF9C450F440E63E0ULL, 0xEAD011863FB63202ULL
        },
        {
            0x272CF627D13DD8C0ULL, 0xF51007155F2CBDDCULL, 0xBC87514BF65AF015ULL, 0xC3E69BB171366BF6ULL, 
            0xFB640152FD08D054ULL, 0xC430A80176936F80ULL, 0x036928EFAD2BFB3DULL, 0x6D02DD20581B81F2ULL, 
            0x30F34FE4A439F92BULL, 0xE9F74112A928D02AULL, 0x5E51100A36E658C4ULL, 0xB7779882289BA2DAULL, 
            0x16EA20C3E01DB542ULL, 0x68FE91957115FCC0ULL, 0x8D4699C4E4B25571ULL, 0x0E96E461D3FF521FULL, 
            0x6438F7F805B2B5F8ULL, 0xC1CD3E937B1F8C28ULL, 0xECF2967EDE66ABF7ULL, 0x397A6434084B4C94ULL, 
            0x4985AA158BC37E5DULL, 0x9E5611BF79F1CC3EULL, 0xDB898777DFC538FBULL, 0xDC823066B1F25E20ULL, 
            0x13F766C0E057E04EULL, 0x7B7B3718366BACA2ULL, 0x88D8AFBC1EA0C824ULL, 0xEF24A7DF831EB36FULL, 
            0x27968C60B9A6CDAAULL, 0x508D605B0BD12B7DULL, 0x95C304CBA8B47AE6ULL, 0x8482AEF162934F87ULL
        },
        {
            0xDE4960862C28C967ULL, 0x408FF3C17EF1FD6AULL, 0x7E5B6ACCA0F3546EULL, 0xBF11232F16F49020ULL, 
            0x8866D27EDD95EBB4ULL, 0x6C2A364E163BE71FULL, 0x817290824F880E89ULL, 0xDA644368F4C8BFD4ULL, 
            0x10F11962A25EBA24ULL, 0xC8B4681B6948414FULL, 0x2431873585A31B1CULL, 0xF14F60CFD49C39F8ULL, 
            0x3E47F91A3E5BCC9FULL, 0xDA2A670CBFC4F8FBULL, 0x1E4592EECCB95DF3ULL, 0x7D16260EE2B119A2ULL, 
            0x0D3F81ED0004AF66ULL, 0x720BEB425F09A1C0ULL, 0x43522AA8EAE3B6BFULL, 0xF4D8755A1F9799A0ULL, 
            0x6863C6801A5AEC14ULL, 0x25439BA67003CAF7ULL, 0xDDACA8C30AE2B757ULL, 0xAB878DB25A9C044BULL, 
            0x0C6A95222D9C3E85ULL, 0x0057417D967C5A3EULL, 0xE340221EA555FAAFULL, 0x85B081E48332F6DBULL, 
            0xF94E581A19DF038DULL, 0x4049625B47FBFD00ULL, 0x88E039F1A2BD1E25ULL, 0xDCEE1FA960F32FD1ULL
        },
        {
            0xD1132ACF6E149EC1ULL, 0xF772584D82911CF4ULL, 0x07709F4D747B53CCULL, 0x71BECB7D58E506E7ULL, 
            0xBC13962A8A523B8CULL, 0x01206E1EF9B46BA1ULL, 0x24D4F79EFF1BC6D0ULL, 0xCDCB73D675880A7EULL, 
            0xC057E45D88014713ULL, 0xB4990E13EDEEDA9AULL, 0x35FFBBE271AC9539ULL, 0x321B8C8C6FA80A41ULL, 
            0x89E519F385B47E21ULL, 0x90850B247338DCEFULL, 0x37032189186BF8E6ULL, 0x4D6C1E9ABDD109E1ULL, 
            0xC021A464E8388B9AULL, 0x4D4FC9E0ABEAE799ULL, 0x472FCF6E1FF34A3CULL, 0x2DB2D3EE1D88451CULL, 
            0xE00FE0650F7CF8E2ULL, 0x38D999606E040392ULL, 0x6A044F1A6ECBB43EULL, 0x9570AA93133D840EULL, 
            0xD758532EAB693F81ULL, 0x7ABD0BBDC0EEF128ULL, 0xD4CF21C14BC23E7BULL, 0x5A39F6E6A1C58865ULL, 
            0x9C88FA4C99E3BE0CULL, 0xBBFDC8DFA8CA5467ULL, 0xC1BE79BDD16D5D2BULL, 0x87C418335168E6E7ULL
        },
        {
            0xD765B469B42B22D2ULL, 0x14177E48192E62C5ULL, 0xA202743C570064E6ULL, 0x8682873407DC735EULL, 
            0x3A0A800A2885AB93ULL, 0xA87832E7293AD215ULL, 0x57250C0AC50A5574ULL, 0xF11B8513D2E3ED14ULL, 
            0xBA84E90A95C2FB2FULL, 0x917E816A3D7D2490ULL, 0xFF78AAF4F30EEF0FULL, 0xC52F410CCC2B4C31ULL, 
            0xDAA26B6932F8EEBBULL, 0x6413803A1B14E6F5ULL, 0xE9396766C5A81A26ULL, 0x12711038224A78EEULL, 
            0x85CF932119AB7535ULL, 0xC8B2CCB25F66C440ULL, 0xBF4DE0B3993E5A8BULL, 0x9D7221CF363A2EBCULL, 
            0x6A9ACE3D9BC8E919ULL, 0xE9F9F285D78917ACULL, 0xD5B7B0C8119C618DULL, 0x5E479F3E93AB642FULL, 
            0xBFAB80A65E389E5CULL, 0x5F363DBD73EE973DULL, 0xAAE9DF733EAE66BFULL, 0xD9F1073A5D24A061ULL, 
            0x1EBE95BA1F3C9A46ULL, 0x7C3820FA92ECE416ULL, 0x9A14C573F461CE76ULL, 0x9704898BDC475A46ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Castor::kSeedConstants = {
    0x6D2C9AFC80A71D4EULL,
    0xE7739E3CCBA0B8A1ULL,
    0x67FB629503EE9E75ULL,
    0x6D2C9AFC80A71D4EULL,
    0xE7739E3CCBA0B8A1ULL,
    0x67FB629503EE9E75ULL,
    0xFFBFF22018628FF4ULL,
    0xE945E0D486B0A5A1ULL,
    0xDD,
    0xB8,
    0x50,
    0x2D,
    0x70,
    0x77,
    0xE0,
    0x8E
};

const TwistDomainSaltSet TwistExpander_Castor::kTwistSalts = {
    {
        {
            0x722D50C25E590D0BULL, 0x0F70DEBC4E29FD32ULL, 0xAD95D53F423739AEULL, 0x6D617CF0ADC83B9EULL, 
            0x1C0492B6E6FACF60ULL, 0x01682F79BC565E58ULL, 0xDC1D771AB7114895ULL, 0xC04C7D06CC4AE5EFULL, 
            0xFCA8F4A90E080EB8ULL, 0xFC9243468CF76B7DULL, 0x5A9AEBB470E23978ULL, 0xECBF6E41A382BA3BULL, 
            0xABFA09A9BD678EB1ULL, 0xC6936BB5F65A207CULL, 0x98722477C03AF42DULL, 0xCC49597DAFC99633ULL, 
            0x8A713142B2D83DF3ULL, 0x2FEDEB7B0D475B6FULL, 0xC6521B0861E67E0FULL, 0x75E398B62F42D480ULL, 
            0xD15C580D53FCC272ULL, 0x3F0DD000770BD139ULL, 0x47E64D504D66D4FFULL, 0xC852A90C5A1712DDULL, 
            0xFB412D0AF53B7788ULL, 0xEAC7A28D1286BC99ULL, 0x6C5338535D78E0A3ULL, 0xF068ED6518A07DA9ULL, 
            0x3BAA819BC132902EULL, 0x69DB8C53242F62C8ULL, 0xABD9055682993FC9ULL, 0x44A6D28BBECC7BB5ULL
        },
        {
            0x8210D4FA54BA3E8CULL, 0xD6210579868FA387ULL, 0x28F368961D2C0103ULL, 0x279B5CAC51A44DC5ULL, 
            0x31A00E2A787A92DBULL, 0x77360373274975FDULL, 0xD15CDF03DF784966ULL, 0xBE432AFB7345820BULL, 
            0xD40E6076938FFE24ULL, 0xD93A9BDBCCEF1C73ULL, 0xF0744785934979C0ULL, 0x899C414D9F5F9107ULL, 
            0xD1585A2805938FC3ULL, 0x2BA7D0A28BAD3238ULL, 0x5DDAC6B74EB3E41CULL, 0x1A9AAA21DB0EDDA1ULL, 
            0xB467F8AC23E1B8C0ULL, 0x5F91259CADD0D329ULL, 0x429222133F75E554ULL, 0x27A221A8A716A009ULL, 
            0x9B90FE38B616C4C4ULL, 0xF8F97B2A56C8DE37ULL, 0x21CA6423A0EEDA39ULL, 0xB0B2FA302F38561FULL, 
            0x8157FF5A482B811AULL, 0x56CCCFB1E5A39061ULL, 0x0A3A36BFDBACCBB5ULL, 0x4B776BDA7ED2A68AULL, 
            0xA61639FEE3FCDE20ULL, 0x040CFA212039375EULL, 0xFC0C1928E02DEED3ULL, 0xA1DE5621406E45E5ULL
        },
        {
            0x15864357EB7237C7ULL, 0x6E779773D08D70E0ULL, 0x055B290937D9F1F6ULL, 0xF0AD0C0DA4E607E2ULL, 
            0x3E38E6BAB5C851A9ULL, 0xE2A20CF5FCE2CA36ULL, 0x78A023D213EA599AULL, 0x6A7162F9D092FE1DULL, 
            0xAE67A04547FED585ULL, 0xF0469189E66673DCULL, 0x839AF137599E2F7DULL, 0x22DD7827162D8F0EULL, 
            0xF2D78D3967E2B7B3ULL, 0x0E86164BD1D36122ULL, 0x653F800CB5BD85C8ULL, 0x66287CD64854CF6AULL, 
            0xFBB167AFA56508B4ULL, 0x7B45A936CF1F3B74ULL, 0x249EE5D44875B229ULL, 0x15364AE3114A9261ULL, 
            0xABE218F7F3A477DCULL, 0x51C744FEDEAA954DULL, 0x8389293776ADD0F5ULL, 0xBD70CD0AF74AF2B1ULL, 
            0x81B368A24FBDB324ULL, 0x33DF5B8CC82ED51EULL, 0x328CF138804C889BULL, 0xEE6E24CF6575320AULL, 
            0x0BF80BC4283FE179ULL, 0x8CB101FC0AA38A82ULL, 0xEB6E073CD5F19CCFULL, 0x36C7D411652737BBULL
        },
        {
            0x90845F22959227E9ULL, 0x007EA2E34EC74447ULL, 0x90051E2A50554A4FULL, 0x1ECAEE7002311844ULL, 
            0xA845259F54C0A9C9ULL, 0xD866FC62DFAFE29BULL, 0x21E0F5954DC4DC31ULL, 0x71604B1531684A55ULL, 
            0x4B6037AA6757EB96ULL, 0x92A19F9082C65338ULL, 0x1EA3890F57385882ULL, 0x8CE61201A352DDFAULL, 
            0x721B0BA858D49EDEULL, 0x8EDCBA975CE3C411ULL, 0x26EB0347BD6AE1FBULL, 0x5E4565CAC47B72FCULL, 
            0x8BFC9358EF70C95FULL, 0x4628C92D129233E0ULL, 0x89313835EEF74171ULL, 0x8BA2A1845C3CDE70ULL, 
            0x12267763BA917F4CULL, 0x803208C31D6A29CAULL, 0xBED6F764A454F06FULL, 0xF89E9D09D9AAC766ULL, 
            0x8A6C2E3ECBBF886AULL, 0xDBE8B5D224434751ULL, 0xE471FC2A26DB523BULL, 0xEE79FFDB3F66BA3CULL, 
            0xC94AA71B0A5E42B2ULL, 0xD8E82EF6A39B286EULL, 0x42510AAC70C863AFULL, 0x24A6734387065FFCULL
        },
        {
            0x314448445E34A947ULL, 0xAA3CE64988C1A73DULL, 0x27F128BDFDE8D851ULL, 0xAFDD9AF8AAF4D366ULL, 
            0xB382BFCA4BBDF26CULL, 0x8F4CA7B03CC3097FULL, 0x18CF991D6CB23FC2ULL, 0x24681D208C70406AULL, 
            0xA8E168ABF7070901ULL, 0xB3C14DF2F1C5E779ULL, 0xFD0427F0701D65FCULL, 0xFDCA9EDD615B4E89ULL, 
            0x1C1BA970FA87989BULL, 0x5BB1FB50965448B3ULL, 0xD238865BCC79DAA1ULL, 0xE1F0FE168A6138BCULL, 
            0x4AE73920E8644D62ULL, 0x92ACA150BD69B387ULL, 0x72022E3B72D39A74ULL, 0x92FCFDEEAA66FE5FULL, 
            0x20923C6F3DE0F3D7ULL, 0x56CBF6B6690C766DULL, 0x079E474240649EE8ULL, 0x701A3B472351A2EAULL, 
            0x770494740C8D010DULL, 0xC9971ACDA0616C3DULL, 0x246D572063C0BDA7ULL, 0x9D0D1B2258179E58ULL, 
            0x359EDFB9EB64A7ABULL, 0x5AF99900A69955E1ULL, 0xF1439D76840A1C89ULL, 0x0E13594C6CEE347FULL
        },
        {
            0xAE5D02F2EEB15EA8ULL, 0x03F194B5B6B783AFULL, 0xA2FF267EA352221AULL, 0x1EC55540FB0CA6BBULL, 
            0x1CC96551814F2D68ULL, 0xAAEC200DB28728A7ULL, 0xE978A1DA81E245A1ULL, 0x7005849F3772A00AULL, 
            0xE8A79A9398DD0B4CULL, 0xB5DC3DC2DF04F370ULL, 0x431D75698F71FBD0ULL, 0xE36B303811B370E4ULL, 
            0x47012DD22C5D12FFULL, 0x2B540BCDFFA53915ULL, 0x4EDD42A3AA29F3C5ULL, 0xB2C86B29CB9EF410ULL, 
            0xFB3D78178A578D37ULL, 0x780DB29394F97028ULL, 0x38A736CF6E058D37ULL, 0x9BB453D794DE1356ULL, 
            0x49A6B831AF1BFE6AULL, 0x3366C246E7E3BC79ULL, 0x0C42A72117734F23ULL, 0xA7773A10EB264796ULL, 
            0x1C72487EE521207DULL, 0x390220220FD45AC9ULL, 0x524710F5F32436CFULL, 0x4395CBAFA8A6E6D5ULL, 
            0x7317CF36927DA26AULL, 0x6B42EBCAB0F56176ULL, 0x86E5A0EE32360C18ULL, 0xF66EC5AF7D0046FAULL
        }
    },
    {
        {
            0x3FF3A0251AEDB553ULL, 0xE75565CED3229626ULL, 0x4C22DDD069922D68ULL, 0x66FE645967745579ULL, 
            0x3D22D8E9813E969CULL, 0x460E8F7224258AF0ULL, 0xE5FDBB1521AA185DULL, 0x87E980A1B1A1704CULL, 
            0xDED50BEC5FA3D6A6ULL, 0x9CA5130A56B7E204ULL, 0x604B85E0018EBA76ULL, 0x9E59E52700056B71ULL, 
            0xC6E9A080DBBDA939ULL, 0xE52896DD4D509482ULL, 0x6CF7C81D08C55ACEULL, 0x520B5D45070762C7ULL, 
            0xECA596CA69AF687FULL, 0x2E66604E072325A0ULL, 0xC698A301E9B62E1BULL, 0x9EB5DE33979E62E8ULL, 
            0xABD3CF9244220D21ULL, 0xEB69AF36B5BC052EULL, 0x45473B74353F116DULL, 0xD9683883C1844BA6ULL, 
            0x40FE8476AB1EA6B0ULL, 0xC5229EB83640DE50ULL, 0xE6B9B41F8D8ADDF0ULL, 0x233F66B4EA2A52EEULL, 
            0x74B8390F9D55E873ULL, 0x2CC036050A1BBB15ULL, 0xDDA13E6843A2C91AULL, 0x60FBBAC144CC8E61ULL
        },
        {
            0x91F7B734745C5A1CULL, 0xBC8DB6A3A556FC34ULL, 0x85BF892CB046883AULL, 0x973005807175A806ULL, 
            0x04FEEB330A534A68ULL, 0xA98C6FDEEE9AB69AULL, 0x3C4745DC6FE194A3ULL, 0xAFDF5C677F255FA6ULL, 
            0x1083FD59BEBC1998ULL, 0x99FE76065FF1520CULL, 0x2F9DA69924FB741CULL, 0x3A193DFCF42044FAULL, 
            0xD36D9FF5590FD725ULL, 0x4999140E172226CDULL, 0xE914349602482CBCULL, 0x9BD743376C175AFDULL, 
            0xBDEEC0D3253E02DBULL, 0x52CC5BCC1E8D0BAAULL, 0xB8C08179225494F4ULL, 0x86CAE67BE45725DCULL, 
            0xD88A2D1F69077FBCULL, 0xED2497F87B44D7A8ULL, 0xF8F6C80BDE49A521ULL, 0x911F160A3CA9FF35ULL, 
            0x0FBF1D82B6E345C5ULL, 0xE3FFE99CFEB9DA6BULL, 0x1CFCCF70F3638B02ULL, 0x8994C192CAC4027FULL, 
            0x4B3CA3959BDD0073ULL, 0xE9EE3AB092B27F7BULL, 0x014FA8361BD5C133ULL, 0xFA1BA1DA8DDA6382ULL
        },
        {
            0x1881349ABB408E6BULL, 0x30865EFC06B34556ULL, 0xDDCE56D742B091D0ULL, 0x9F4C55F360D2A510ULL, 
            0xBAC7AD4E0DE824F6ULL, 0xAFF38FDB4B811447ULL, 0xAB9C06C61AF98D92ULL, 0x5453C828321DC3A6ULL, 
            0xC524BDEE12FE5481ULL, 0xDE7309BCEF5F9297ULL, 0x9AF5938648844B5FULL, 0x351F1924B2E391FFULL, 
            0xB21BDE2C021229ECULL, 0xF48C8C43FD31F674ULL, 0xAA5606CA1D6698CEULL, 0xBC7FF639430C3885ULL, 
            0x99A06B4B08D348D3ULL, 0x4732C09BA6D344E7ULL, 0x86210C950DD969DCULL, 0xFCB3F553145E3A71ULL, 
            0xB562DD28D4FBC2E3ULL, 0xDE0A1324414D0127ULL, 0xB05664BCCB00D134ULL, 0xCA0B9DEE9D334C03ULL, 
            0x3B4FF1FE48C61866ULL, 0x536F8A5D27448FBBULL, 0xB54D651D5AE39297ULL, 0x514C7ACFC12A19FFULL, 
            0x6CBC35AB014369E2ULL, 0x4C84ACFE22524CD0ULL, 0xE63C9A196469F285ULL, 0x4A9647E67C806AE7ULL
        },
        {
            0x2023D67D343E7F90ULL, 0x319BAA48DA117B98ULL, 0x17BD3E66B382C076ULL, 0xCB195722EC493894ULL, 
            0x8FDC466451474F59ULL, 0x49E7CC09D73A7C33ULL, 0x155235C052883A28ULL, 0x9D646A9494E9CC92ULL, 
            0x062A5927D0FE78C7ULL, 0xB7BF5A96DED7C505ULL, 0x9E8EC99FDF205D9DULL, 0x542DDEA6967B8768ULL, 
            0x3687D227F490051DULL, 0x86EE77AFD2A9712FULL, 0x87723B68BBB1FDADULL, 0x7B5A4C17167C3460ULL, 
            0x951EDDDCEC9C4394ULL, 0xC50446F67749F984ULL, 0x49B01A8D88FAEDD4ULL, 0x5C157D35B3168480ULL, 
            0x5FFBCCD448260EDBULL, 0x2098A46B1E47E755ULL, 0x2F9393AB87A45F06ULL, 0x7FF1462C5CF996F7ULL, 
            0xD7C289458A0E4B7FULL, 0xC07BF08ACF2A4054ULL, 0xCF50D88AA0AAF450ULL, 0x7AB014B13489A179ULL, 
            0x750E4C28BC887144ULL, 0x7C814640BACC8516ULL, 0xCF126B78BA2ECD70ULL, 0x89B644953E4039D0ULL
        },
        {
            0xC2351174EC2F38C2ULL, 0xC167723067A3C651ULL, 0x150B9A7C6F2E2AF9ULL, 0x14C4FE659CC66212ULL, 
            0xA8F0C5843821CD31ULL, 0xD95B8A5F128E284DULL, 0xC6F9D23AE814C3F2ULL, 0xC68C6FAB62F9A208ULL, 
            0x8BD139F274BAEF0BULL, 0x3F1A94DE1A009791ULL, 0x0764E89517FD6327ULL, 0x1198480C15635166ULL, 
            0x13953A2BB6D2837CULL, 0xCEBA700238F02FE7ULL, 0x773C28EADEE71B50ULL, 0x8574E81407AFE1BDULL, 
            0xF58C27986DB825C9ULL, 0x7A5F798173C0DF05ULL, 0xC4361421BD67851CULL, 0xCECB40DE4792233BULL, 
            0xCE5344D927535ADAULL, 0x5216E013EC701F13ULL, 0x9A63608C8AE74A78ULL, 0x4438E976A2BB5C5CULL, 
            0xFAA50B6DB73989F1ULL, 0x430E6821A8F7DF9DULL, 0x016F796DCB0634A1ULL, 0x56FAE2872465E6F1ULL, 
            0xDEF8570D8B3B5E54ULL, 0xD793D18DA435B75DULL, 0xD4AA106100015240ULL, 0xF5AD0E7C8DBA800AULL
        },
        {
            0xA29EB3210EDA5B42ULL, 0x181B1FE9E59649DAULL, 0xD105ECA84AC11E56ULL, 0x77F899C163C065DCULL, 
            0x5A7DE749F68D9E96ULL, 0xE7E54700BBD4228CULL, 0xB70ADD47AEF49201ULL, 0x9B3AB893CB304CBCULL, 
            0x37948F2178910700ULL, 0x2AC643CF0AF82E6FULL, 0x043D1095DAEB900FULL, 0xC351320DA9A1B8EEULL, 
            0x13A74A1E4C140EC7ULL, 0x5BB6B913A7CAC223ULL, 0x196B175BE94B3756ULL, 0x61F1A601677D19C6ULL, 
            0x9348ACB9B6A15F7BULL, 0x9AF204FD844EAB5AULL, 0x50D9D276C3B7E41CULL, 0x4EB93605B667C8BFULL, 
            0x0237F743C2D2161DULL, 0x90CDB2D40C00C65EULL, 0x0A93A7CBE762445BULL, 0xF3AA5C016C622747ULL, 
            0x9E3E679E412DF8C0ULL, 0x13C55563694AF95AULL, 0x5F5F1FB27847F2D7ULL, 0x7DD624533EC32030ULL, 
            0x173955811517CF93ULL, 0x0A25B32A715B0108ULL, 0x0336FFD4F185BAD7ULL, 0x00CBC749F4AB935CULL
        }
    },
    {
        {
            0x2AA597B21AB53E76ULL, 0xFF4D5415769ACB5DULL, 0x99776CAE7473B3D4ULL, 0xBE08F62D752A548BULL, 
            0xEE52C39BF24FE766ULL, 0xD9597455D1738A90ULL, 0x6B3EBFC609A498E6ULL, 0x4D5DBB4F40D80BCFULL, 
            0xD1A051C85ECE4548ULL, 0x78B4E4167CC73836ULL, 0xA984A13EB253A1DCULL, 0x5D42C418BBD5D951ULL, 
            0x6DD3E24E4885A6F7ULL, 0xF975DF0C140A6B2EULL, 0x88716E97B4249958ULL, 0xA9E5D312DA954AACULL, 
            0x14FE61DA5BC71DB7ULL, 0xBFD97B8F3F384B53ULL, 0xC38936C177045224ULL, 0xBB7455E97253108FULL, 
            0x5D9B4774A62EE64AULL, 0xE131D44282E849BEULL, 0xFFC1221C6B78964BULL, 0x3000A9C97214B324ULL, 
            0x66B131DF9AD535ABULL, 0x88FF24AC0205CC41ULL, 0x29FC56AA2BFDAFD9ULL, 0xA962B941301F312DULL, 
            0x930DA375BAC9B449ULL, 0x10036D0C5FE421B2ULL, 0x176F6324054D781BULL, 0xD0323ABCCF687D50ULL
        },
        {
            0xBA175237D6BCB171ULL, 0xCBB416956190D21CULL, 0x721CC5EBDA85BE6BULL, 0xA1F8471446779EB1ULL, 
            0x642C8DE6A5943477ULL, 0xFF7AFE0CDC3893BAULL, 0xE97C0BB13DAC1190ULL, 0xD085DAF18E538CC9ULL, 
            0x23178DA21074DBDDULL, 0x4DC5538AFB6DA8ADULL, 0xA26AEED234911CCAULL, 0x5B37462EFEE0A12FULL, 
            0x0D604700CBD4FF43ULL, 0x98CB7B97F538DBA4ULL, 0x2FFC433B5BF90E36ULL, 0x7695BC6C47454015ULL, 
            0xD35E1D0F54F22E1DULL, 0x9E6D00BD0CD088B4ULL, 0x4F9E6CE7D9E20EABULL, 0xC04FCA9825D256E0ULL, 
            0xE4BF13FD51A072F5ULL, 0xF98721632E5D779CULL, 0xEDF4F465DB2704C8ULL, 0x22FDD342543156C1ULL, 
            0xE0FD27D8A8ACA3D9ULL, 0xA38ED64C334D1AB3ULL, 0x4795AE7364A6845FULL, 0x9B86F30DEA544EE4ULL, 
            0x272A19FB6980BD1FULL, 0x9B34AB25D7FB3399ULL, 0xA5CF65A3CD9FBDF5ULL, 0x50E777DD415D3D5DULL
        },
        {
            0x2623D05D07038A36ULL, 0xBD0DF55EF4231AFBULL, 0xB1F936CEC50FBCEDULL, 0xA9FD9DBF4EC74233ULL, 
            0xAF008856EED92EEDULL, 0x27C6EAE63FF7BC7AULL, 0x36DCFB9E4F2C29EBULL, 0x77DB861963EEC133ULL, 
            0xB73AAFFE04DA88CBULL, 0x633861E898E4DC86ULL, 0x943AE554ECA6D1CCULL, 0x686167DFDC9983D2ULL, 
            0x8E6E5B928DFD6641ULL, 0x0408DE48FB5AB4C9ULL, 0xE849CD009D2E8C1CULL, 0xC96FC95E3BB4D59CULL, 
            0xAB109E39B8491E73ULL, 0x1B875FF29B2D570BULL, 0xD6C954A298B1E115ULL, 0x304BC76A3692D9DAULL, 
            0x026D5A7003C7CE69ULL, 0xD9D0FD30D1F66E47ULL, 0x2BD6F59FD93D466DULL, 0xDC2FF8E8091076E2ULL, 
            0x2B5DFC1E1544C3F0ULL, 0xA0F66756CC4351C2ULL, 0x2032F3B692D77AE8ULL, 0x75D51BD916989138ULL, 
            0xFE4271661EB39697ULL, 0x0935FF53FEF77CF4ULL, 0xD0798155F51FC050ULL, 0x9CA28B3872A6C3D8ULL
        },
        {
            0xA649D169DAD5BDA0ULL, 0xF556B5BC7C467B9AULL, 0xCE470D59C22A285DULL, 0xB9DBC2E516B835D8ULL, 
            0x45A042DE238D4051ULL, 0x9A18175608497AB0ULL, 0xD38A495C5D2C6CC6ULL, 0x4DA30DB471DB4DF9ULL, 
            0x87C108BAED303555ULL, 0xF32F7CB4A2AB41D1ULL, 0x461D76351657E91CULL, 0x7C9712642D6CA691ULL, 
            0x884B21B880696C28ULL, 0xD3F2B05CE4B19497ULL, 0xBF55C0AFB296A285ULL, 0xA7C4F390023C3972ULL, 
            0x523E7D4708D54601ULL, 0x3E91D0F209B22AC0ULL, 0x41875B901E89E354ULL, 0xCEC8D5F1A5B43A00ULL, 
            0x0CC0A3E1EB3DF946ULL, 0x947F5655E87108A0ULL, 0x06F9B5FFE2B1AA20ULL, 0x8E8F024A7035C3FCULL, 
            0xF2AA94A57B21260DULL, 0x8FE1492F64B4026EULL, 0x5ACDAD73C11B5BC9ULL, 0xFC69DA95663933CBULL, 
            0x3B30C9E3E667AA1EULL, 0x9CCEB6EAFE043D71ULL, 0x0D8C191B32230A30ULL, 0xBEC00B8D81432F75ULL
        },
        {
            0xA86AD32D3A2FE552ULL, 0xAB7BC8CB30053AF5ULL, 0xEB9319C4B544F9A4ULL, 0x8D52E72BE19A3DE8ULL, 
            0x1FF36BD6C8C785D7ULL, 0x9756E6D052F9A614ULL, 0x51F853AA5FB5B4F0ULL, 0x015ABAB41711378FULL, 
            0x35DE0E46359A0902ULL, 0xEC6A0BD35E44401AULL, 0x2F5C320845088024ULL, 0x7F744CCE8FEAC0FFULL, 
            0x4D1E5E3BC42E8C15ULL, 0xA0B10E6AD8452674ULL, 0x5EC45DE313FCC5B6ULL, 0x491162115005603AULL, 
            0xDAA9262F695FB233ULL, 0x0025860671EC9DF9ULL, 0xA85B3F2ED9149131ULL, 0xF129AA485EA6CEF0ULL, 
            0xE73B1129994BA770ULL, 0xF974C225311CE6E1ULL, 0x19E9A2CF71B2D5C3ULL, 0x2AFF2CF857D1DF17ULL, 
            0x9E6564BF1F0DAFC9ULL, 0xCE9F2781F5F469CDULL, 0xD93F409FD77E55FFULL, 0x18AD7CD60FB79D0EULL, 
            0xF39FC2C4BE4AA20BULL, 0xB995D064E0938E96ULL, 0xE00377FAF9CC5967ULL, 0xEADEF96C50B51C6CULL
        },
        {
            0x2E791BF1E38B36E8ULL, 0x4284056E18AB6066ULL, 0x6CF567FD5F2CD500ULL, 0x4B9364EA39F3051FULL, 
            0xAB9DD1B5C09EE6C3ULL, 0xD739C2CC38AFC4F3ULL, 0x3C3C8D7B58A0912CULL, 0x8236282C5441C2FCULL, 
            0xA3894CEAE631CC1FULL, 0x2644483BE523EFB2ULL, 0x9A22F0B4A19BA958ULL, 0x82D858F1F31545C1ULL, 
            0x15E7AF9848747651ULL, 0x5A1D3AD120346CF9ULL, 0xDED428FB66C240F9ULL, 0x6E6B7883FFE4B74EULL, 
            0xB7D84B30E89F8E60ULL, 0xD467C338F9A11AA4ULL, 0xBCBAABC3D7D2BAC6ULL, 0x822368AC82298129ULL, 
            0x33F12AF03DB53B12ULL, 0x91E9FB660E08E35CULL, 0xD95AE495A0BC3750ULL, 0x7C5114085CCE2096ULL, 
            0x0196FD620C5E1352ULL, 0x7AFB5A826C94B91EULL, 0xBB6D4225B27A9AA8ULL, 0x88338D0BB3782CB7ULL, 
            0x798879D4E85C35CCULL, 0x3F0630B0291820EFULL, 0xF8B0D9F4AB831F81ULL, 0xF4E09E3C41C23550ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Castor::kTwistConstants = {
    0xEC095457E4EA3E36ULL,
    0xD1FC4A873FEA6CCBULL,
    0xA40A771B2E870C95ULL,
    0xEC095457E4EA3E36ULL,
    0xD1FC4A873FEA6CCBULL,
    0xA40A771B2E870C95ULL,
    0x4F42650CC4F6B0D9ULL,
    0xBBBE8530BEAC2AADULL,
    0x1A,
    0xEF,
    0xB6,
    0xC6,
    0x81,
    0xD3,
    0xBD,
    0x71
};

