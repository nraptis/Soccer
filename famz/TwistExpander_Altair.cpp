#include "TwistExpander_Altair.hpp"
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

TwistExpander_Altair::TwistExpander_Altair()
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

void TwistExpander_Altair::KDF_A(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Altair_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Altair_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Altair_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Altair_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Altair::KDF_B(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Altair_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Altair_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Altair_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Altair_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Altair::KDF_C(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Altair_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Altair_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Altair_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Altair_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Altair::KDF_D(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Altair_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Altair_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Altair_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Altair_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Altair::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB5E310FF0D38911AULL;
    std::uint64_t aIngress = 0xB54394F249FD23E9ULL;
    std::uint64_t aCarry = 0xEC5180AA87FE0C86ULL;

    std::uint64_t aWandererA = 0xFF00003B764863D4ULL;
    std::uint64_t aWandererB = 0xEA183ADB211E9752ULL;
    std::uint64_t aWandererC = 0xC49DCA16BEF805DBULL;
    std::uint64_t aWandererD = 0x9720471F96AD2BF9ULL;
    std::uint64_t aWandererE = 0xBC24DF4EF9E6EBD4ULL;
    std::uint64_t aWandererF = 0xE579AA860D8AB85BULL;
    std::uint64_t aWandererG = 0xEC45434904E7278EULL;
    std::uint64_t aWandererH = 0xF0F9375720CD654CULL;
    std::uint64_t aWandererI = 0xB0EC669CF72B56AFULL;
    std::uint64_t aWandererJ = 0xD905E800C9A9D863ULL;
    std::uint64_t aWandererK = 0xA1790EB1F21A371DULL;

    //
    // KeyRotate A
    //
    aPrevious = 0x9C30E6EFC6D05F59ULL;
    aIngress = 0xB72756883109D4AEULL;
    aCarry = 0x89916F183821720EULL;
    aWandererA = 0xC75C1AC9E366165CULL;
    aWandererB = 0x82C0F5893EAB932CULL;
    aWandererC = 0xBFFE7FF55D7D89D7ULL;
    aWandererD = 0xDFBD8D19B6EBF32CULL;
    aWandererE = 0xAE40DF8962123EF0ULL;
    aWandererF = 0xE3A1F42CDE759EB8ULL;
    aWandererG = 0xC9DF3F90EB7C91A4ULL;
    aWandererH = 0xFA9BB55ECF3877B1ULL;
    aWandererI = 0xE4C23E9B52AD1F12ULL;
    aWandererJ = 0x9CD06BE23FD5D6A3ULL;
    aWandererK = 0xD55CB8902B2E77B8ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateAConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xA5DF398A9028D7DFULL;
    aIngress = 0xAB93A9E6E0183595ULL;
    aCarry = 0xF21E64CFA4B3761CULL;
    aWandererA = 0xD07B5089204B40F5ULL;
    aWandererB = 0xEC76C2AC2C5A6AF6ULL;
    aWandererC = 0xC7C280FEBE9E3C22ULL;
    aWandererD = 0xBCA773B89385C13BULL;
    aWandererE = 0xC5C62EBCF0BEFB8FULL;
    aWandererF = 0xF6522A9DD62FCB9DULL;
    aWandererG = 0x82EF913069B18FFAULL;
    aWandererH = 0xD59C323169BB3BB6ULL;
    aWandererI = 0xFAE85688E6769D64ULL;
    aWandererJ = 0x84FE72952045F548ULL;
    aWandererK = 0xB6559B49D000E8D7ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants), &(pWorkSpace->mDomainBundle.mKeyRotateBSalts), pSnowLaneB, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0x8BF98074768FD42FULL;
    aIngress = 0xAF1A567D8AEA963DULL;
    aCarry = 0x9D19AA132081D109ULL;
    aWandererA = 0x9EFE244F6126404DULL;
    aWandererB = 0x9B48B68255DBB982ULL;
    aWandererC = 0x814A4EF878F0BDF9ULL;
    aWandererD = 0xE63EACD70722812AULL;
    aWandererE = 0x8EDD4566898D5AC7ULL;
    aWandererF = 0xEA5D8D9DF237C2ACULL;
    aWandererG = 0xF29D189C8E05F770ULL;
    aWandererH = 0xF44D8D5B2E9D98CFULL;
    aWandererI = 0xD452C3189404D62EULL;
    aWandererJ = 0xA8903EADF98816B8ULL;
    aWandererK = 0xDA54ECD0C29EAED8ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnAConstants), &(mDomainBundleInbuilt.mKeySpawnASalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnAConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants), &(pWorkSpace->mDomainBundle.mKeySpawnASalts), pSnowLaneB, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xEEE41AE086B8061AULL;
    aIngress = 0xA396EC1C84BE892DULL;
    aCarry = 0xA677161FC58DC6EEULL;
    aWandererA = 0x884DE0C3E4C11497ULL;
    aWandererB = 0xCD30550441194436ULL;
    aWandererC = 0x9CC97FE981556461ULL;
    aWandererD = 0xE25463911E0E9202ULL;
    aWandererE = 0xE91E8DD5EBB81751ULL;
    aWandererF = 0x86B0F6A36D78ED92ULL;
    aWandererG = 0x88F05499CE0C3C79ULL;
    aWandererH = 0x9CE8AC6570709C00ULL;
    aWandererI = 0xE99F2890B210F4BEULL;
    aWandererJ = 0xA74319BBBE25E732ULL;
    aWandererK = 0x9CC4F574FE87CD40ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnBConstants), &(mDomainBundleInbuilt.mKeySpawnBSalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xA76BC809391E5BD7ULL;
    aIngress = 0x80044D92A9CD3F41ULL;
    aCarry = 0xB4A050B9AFD8547DULL;
    aWandererA = 0x941754DB82331047ULL;
    aWandererB = 0x88281E8B8582EABCULL;
    aWandererC = 0xDBFCCF6B70407159ULL;
    aWandererD = 0x85D61C770702C8FFULL;
    aWandererE = 0xF11A1A567C0DFD21ULL;
    aWandererF = 0xA4462796D1676BEFULL;
    aWandererG = 0xC6D1372F7788DAABULL;
    aWandererH = 0xA80D55F07076BEC9ULL;
    aWandererI = 0xCC5033389B7D2085ULL;
    aWandererJ = 0x8DA48760DE07FD9BULL;
    aWandererK = 0xF43AA311476AE3BAULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mTwistSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xE322FBD05CCAD1FEULL;
    aIngress = 0xC37B81C9126263D3ULL;
    aCarry = 0x9D867DF2FAECB2C2ULL;
    aWandererA = 0x88380D83E312FB90ULL;
    aWandererB = 0xBEDA384C53BE3EA2ULL;
    aWandererC = 0xD877534EF28CFDC7ULL;
    aWandererD = 0xC63A0118CCE0AC80ULL;
    aWandererE = 0xDC506BBA4552156FULL;
    aWandererF = 0xD51BDB8911F4C138ULL;
    aWandererG = 0x8B57A548EE4C353AULL;
    aWandererH = 0x819CE5660D112480ULL;
    aWandererI = 0xF874421FA4CEFCFBULL;
    aWandererJ = 0x9F21CC4A696DBA58ULL;
    aWandererK = 0xDD5F2614780E9607ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mSeedConstants), &(pWorkSpace->mDomainBundle.mSeedSalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xA8B3333169E2AC42ULL;
    aIngress = 0xABED44ACEC867B21ULL;
    aCarry = 0xEF8AE804B2631E4EULL;
    aWandererA = 0xFC5AAAB9F9732BF3ULL;
    aWandererB = 0xBBA1FC7BB7A165FDULL;
    aWandererC = 0xECF8522C420589B7ULL;
    aWandererD = 0xEF9376FDBC43AC23ULL;
    aWandererE = 0xD97E4F7FC8C27AD2ULL;
    aWandererF = 0x95EE77CD13C25EE3ULL;
    aWandererG = 0xE592C7A62D962227ULL;
    aWandererH = 0x84A185EDC9DF62CAULL;
    aWandererI = 0xB94DB14B6399A45CULL;
    aWandererJ = 0xE6CA69EEF26E555BULL;
    aWandererK = 0x80D92D98E69808B5ULL;
    //
    TwistExpander_Altair_Arx::SEED_A(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Altair_Arx::SEED_B(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Altair_Arx::SEED_C(pWorkSpace,
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
    TwistExpander_Altair_Arx::SEED_D(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Altair_Arx::SEED_E(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Altair_Arx::SEED_F(pWorkSpace,
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
    TwistExpander_Altair_Arx::SEED_G(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Altair_Arx::SEED_H(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Altair_Arx::SEED_I(pWorkSpace,
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
    TwistExpander_Altair_Arx::SEED_J(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Altair_Arx::SEED_K(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Altair_Arx::SEED_L(pWorkSpace,
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
    TwistExpander_Altair_Arx::SEED_M(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Altair_Arx::SEED_N(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Altair_Arx::KEY_A_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Altair_Arx::KEY_A_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Altair_Arx::KEY_A_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Altair_Arx::KEY_A_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Altair_Arx::KEY_A_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Altair_Arx::KEY_A_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Altair_Arx::KEY_A_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Altair_Arx::KEY_A_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Altair_Arx::KEY_B_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Altair_Arx::KEY_B_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Altair_Arx::KEY_B_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Altair_Arx::KEY_B_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Altair_Arx::KEY_B_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Altair_Arx::KEY_B_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Altair_Arx::KEY_B_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Altair_Arx::KEY_B_H(pWorkSpace,
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

void TwistExpander_Altair::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xC3A7C97B74257176ULL; std::uint64_t aIngress = 0xC73B5C8503F5DDA4ULL; std::uint64_t aCarry = 0x8FBA4FFC6D55513CULL;

    std::uint64_t aWandererA = 0x8BFEBD39235132C9ULL; std::uint64_t aWandererB = 0xB88F2F03EE984E76ULL; std::uint64_t aWandererC = 0x9D2AD41590D1F7B8ULL; std::uint64_t aWandererD = 0xEF05E120F0321CE7ULL;
    std::uint64_t aWandererE = 0x80D43229150D0FB4ULL; std::uint64_t aWandererF = 0xA9CD85915E3E9052ULL; std::uint64_t aWandererG = 0xA4FD9B9640AE8B3FULL; std::uint64_t aWandererH = 0xC2490A6A8F64306FULL;
    std::uint64_t aWandererI = 0x970F4893C8D56D1AULL; std::uint64_t aWandererJ = 0x801F370569E19EEEULL; std::uint64_t aWandererK = 0xBBD2ACCCCC55BC81ULL;

    // [twist]
        aPrevious = 0xCA95E9CFADF183AFULL;
        aCarry = 0xD388233351C89C3DULL;
        aWandererA = 0xE92F6D69D45AE06DULL;
        aWandererB = 0xACDAAC3437666EA7ULL;
        aWandererC = 0x9AEC8569313A3F64ULL;
        aWandererD = 0xB6CD1385C3CD9EDDULL;
        aWandererE = 0xE86AFDAFB901BB58ULL;
        aWandererF = 0xCD623DAD467B5272ULL;
        aWandererG = 0xDBE2C602B153087DULL;
        aWandererH = 0x8DE2E7BC8B1626C2ULL;
        aWandererI = 0xFAAA898DE317E8ABULL;
        aWandererJ = 0xD285A771A130FB93ULL;
        aWandererK = 0xAAB5D750B5DA16CEULL;
    TwistExpander_Altair_Arx::TWIST_A(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Altair_Arx::TWIST_B(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Altair_Arx::TWIST_C(pWorkSpace,
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
    TwistExpander_Altair_Arx::TWIST_D(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Altair_Arx::TWIST_E(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Altair_Arx::TWIST_F(pWorkSpace,
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
    TwistExpander_Altair_Arx::TWIST_G(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Altair_Arx::TWIST_H(pWorkSpace,
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

void TwistExpander_Altair::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Altair_Arx::GROW_A_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Altair_Arx::GROW_A_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Altair_Arx::GROW_A_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Altair_Arx::GROW_A_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Altair::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Altair_Arx::GROW_B_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Altair_Arx::GROW_B_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Altair_Arx::GROW_B_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Altair_Arx::GROW_B_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Altair::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 7 of 33
    // Exploration cases: 0
    // Structural maximin 555 / 674; family total 3387
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
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3828U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4098U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8149U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7789U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1465U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 92U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1780U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1375U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 137U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1915U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1735U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1330U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 7 of 33
    // Exploration cases: 0
    // Structural maximin 553 / 674; family total 3374
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
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7249U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7159U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7429U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3018U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 925U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 610U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 790U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 835U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1195U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1015U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 880U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 430U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1285U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Altair::kKeyRotateASalts = {
    {
        {
            0x0F9FC59E07DB9036ULL, 0x934E4F128172F7BCULL, 0x3247B1756765A585ULL, 0x181CAC64658B7873ULL, 
            0x1134295C0B2600CDULL, 0xE6D6F39558C07AEEULL, 0x4861A9B74A05719FULL, 0x84819CFD9B15B459ULL, 
            0x35BF02346F857E98ULL, 0x7F546D8440B2A458ULL, 0xF08E0ECCFB4BA2DFULL, 0x855B94E429031A49ULL, 
            0xE28E7F95BAD1F45FULL, 0x12530A7B368D47BDULL, 0x29017EA331C5FED2ULL, 0x510D991807A5179DULL, 
            0xCC90CF69F420C116ULL, 0xAEC228AD93EFF0A0ULL, 0xCAEBEE993B73AE72ULL, 0xAB5487B21E897F63ULL, 
            0x4361F0317AF940F9ULL, 0x412469C0AF69DC44ULL, 0x1CB055E330E61D3FULL, 0x4AF37F6E8333F3FFULL, 
            0xE5FBF64C12753C76ULL, 0x2F948A2F47339FE2ULL, 0x3467FAB3D61C37F1ULL, 0x9AD956DA32908E01ULL, 
            0xED7AD31E140BB4AAULL, 0xB267CF846AB67A8AULL, 0xD8F58971A8672A73ULL, 0x41A1A1D11A6EB872ULL
        },
        {
            0xA58824CB591A75C4ULL, 0xD1D22BF45E5DC558ULL, 0x94A7BA26056C9AD6ULL, 0x924335A3E60AAF92ULL, 
            0x393AD96BE83D984BULL, 0x4759A101D8E1F81BULL, 0x510FB0A44460B9CCULL, 0x3EB97AA4693EDC84ULL, 
            0x3C6009A3C3C15440ULL, 0xDE6C8B09AF5DE129ULL, 0xC1E717B75E90A1ADULL, 0xD15BDEAA4C540259ULL, 
            0x8E139D0973C0F5D1ULL, 0x4A38B3BE4559B94EULL, 0x8F87885EB7AED44BULL, 0x222C9B411C92B186ULL, 
            0xB7436B1669180A8FULL, 0x80CA3146C2A42FF3ULL, 0x20CCDDB27DAEE0A6ULL, 0x8A9B493359ABF94EULL, 
            0x4090B61C030B6D70ULL, 0x59B83103C57BCEA9ULL, 0xC409ACCF58484D1CULL, 0x199492B20794F547ULL, 
            0xAC7C51386556CB98ULL, 0x0F7466A507AE3293ULL, 0x6B50D1F69CE5E921ULL, 0x7ABDEFF5343AC278ULL, 
            0x9AC7AE23E0DF821FULL, 0x9E53218CDF9FD0B4ULL, 0x9B735F007148F19AULL, 0xBC12DFDDEEE66482ULL
        },
        {
            0xBCDCBAA156CFC28DULL, 0x18F5BABC650BB49CULL, 0x065C3F4186A7185AULL, 0xD72BD409E026B283ULL, 
            0x0487DC4A776C2120ULL, 0x77E4001DA7F70626ULL, 0x99A06DB0A2DAE15AULL, 0xB1EC339C49713595ULL, 
            0xB50CCFD6CE0A9542ULL, 0x45116BDA8B429793ULL, 0x83D777C5224A3920ULL, 0x3BAB6E2F6283DF97ULL, 
            0x07B98FEB8D931B01ULL, 0x6C41AA637D76B5C5ULL, 0xD064E0C533A356A9ULL, 0x6BB30C8302705463ULL, 
            0x7B72A93C2215C57DULL, 0x88022FD0D6D1937CULL, 0x34946CBDBB2B977BULL, 0xF840A0B548C2D0FAULL, 
            0x7F4B180B1C507D1FULL, 0xE3372EAFA0C7AD01ULL, 0x269E03B4B078EAEBULL, 0x8B5CD0049B4F7FC1ULL, 
            0xA9875FF39D4C48A0ULL, 0xE707F8295EC62A79ULL, 0x6346DD179DEF3B31ULL, 0x60AC72CAEB31426AULL, 
            0x1258515C06BC6104ULL, 0x8C327F997C21CA6DULL, 0x36990E0B40B458ACULL, 0x8A0CAEE3A5DF7501ULL
        },
        {
            0x627B4BDA0F6EA5ACULL, 0x451C29997B94A7C9ULL, 0xA4D00FD2428065A1ULL, 0xD0F84978856846E7ULL, 
            0x287EBB2F89A55D95ULL, 0x7ED5B33B4B33267CULL, 0x61AC212B71CB2885ULL, 0xFE308E1258A21FDAULL, 
            0xB3EEB8DA7315FE3AULL, 0x8AC44AA4D9CA38F0ULL, 0x87909446B7DE5894ULL, 0x1C3F067A3B732876ULL, 
            0x9CBED12FEFC0F75DULL, 0xBA56458D4BF7A629ULL, 0x7ABBA10BBB08A6DFULL, 0xF72E0355019ECE56ULL, 
            0xED8488E7414A61F0ULL, 0x5BC4D7DDE4D4CB20ULL, 0xE0894D8CCED13DADULL, 0x603E181BDACA087FULL, 
            0x1C84CCF6C05B5386ULL, 0x4D4BB14AA0C26F13ULL, 0x2F3229B184D21DEBULL, 0x9363D60A14059C72ULL, 
            0x59AD0A318B4505D8ULL, 0xC72394279AD71DEFULL, 0x0068CAFF4207F783ULL, 0x967878D32DB1ED7EULL, 
            0x2247EEE2423CBD59ULL, 0xA02A2EA9ACFFF10BULL, 0xA3A079EB1184753AULL, 0x8BE0DBA490075985ULL
        },
        {
            0x7AC476B9EC34D8A5ULL, 0xD1579F65A35F9152ULL, 0xC643C56E425E74C3ULL, 0xD34A0CE393AA2EFEULL, 
            0xF01B61BAEFDBDC81ULL, 0x6AED0252B4EE4E5EULL, 0x8337C6B34DC2922DULL, 0x78D6B1A358BEDD8CULL, 
            0x5580CED1F3247D94ULL, 0xF63016BB59C09EEEULL, 0xF0FAB9B1617C2C81ULL, 0xB71A6420FCD7A817ULL, 
            0x6366CD0AB2C67DF0ULL, 0x53E2136AD24300AAULL, 0xE4BE3D4086F009E4ULL, 0x635A52C7AA3804F0ULL, 
            0x4FF5C36280EFB93DULL, 0x0CED9FCF859C932FULL, 0xA53F5891B8F7240BULL, 0x6859F6DCD8D1F7C5ULL, 
            0xDC8B0E96AB1C097EULL, 0xACAB363D0C573F79ULL, 0x54DEE406BB067F20ULL, 0x587D9DCB0FBC58D8ULL, 
            0x04F770859D618884ULL, 0x90C2456B68FED6D9ULL, 0x3F8C7E31BB5C7EDBULL, 0x61719D2B68984646ULL, 
            0xD656358CC6B00A6EULL, 0x46378BE9038166F3ULL, 0x7C0CBEC1A6C5C9DDULL, 0x176EB47AAF075A60ULL
        },
        {
            0x64B9DF987EAF195CULL, 0x371BAEFB6433D09AULL, 0x5FFCC361D8986E7CULL, 0xEC848321926A2C09ULL, 
            0xFD891CB744E5A54DULL, 0xFEFBC5D657ABA20BULL, 0x8A0CCB7ED702C16EULL, 0x3B61950D4BAAEE23ULL, 
            0x0C672852FCE72149ULL, 0xF751DA5B4CDE0145ULL, 0xA745962B099A19E4ULL, 0xDEBF83BD63E4F97BULL, 
            0xF910350CC06D62BFULL, 0xF739A1D017FA5230ULL, 0xDCDC268349DC8797ULL, 0x9B30C6005883AC65ULL, 
            0x4FD0C9198B622AEDULL, 0xF1422FFBA01ADA94ULL, 0x34332132EE9F8BB4ULL, 0x85A3C634A2490DC1ULL, 
            0x41A7DB4ACD903F8AULL, 0x6E712BD31672EA89ULL, 0x8265B129BB4AB2BAULL, 0x5B549FC91CD77ABAULL, 
            0x9BE695614B50A14EULL, 0x480C186E5901FFB8ULL, 0xEB37D1FF8B195785ULL, 0x37969C9FB1CA6620ULL, 
            0xD38DEBF0AEBA13CDULL, 0x05B3C26F98CE78B3ULL, 0xD700AE42317548D2ULL, 0x3B344FBF9AAA5CE0ULL
        }
    },
    {
        {
            0x69EED5012D6B4837ULL, 0xF2F927416DB22B04ULL, 0x6E64113B767D174AULL, 0x03BE74D0B7AC5322ULL, 
            0x0959672F2713C683ULL, 0x13D7316CFF579B64ULL, 0xFD20971265AB0C8EULL, 0x2EC7B9EB2831021EULL, 
            0x60DFE375C81F7B6AULL, 0x5BF67D7ABC5D1235ULL, 0x8A3B09282A0D4C8EULL, 0x608F7CD4C1489009ULL, 
            0x4A10EDDD3F70EA1AULL, 0x3965F8FF92D19726ULL, 0x2F7721B66C8FA4A1ULL, 0x6C3E8C57C2D9AF6FULL, 
            0x77079991B6BF662CULL, 0x69DCAEF7787460A0ULL, 0x6AA6BD2BA5B00350ULL, 0xE996486F4206AA30ULL, 
            0x37A2B4828BE7762FULL, 0x64B6CA503E844480ULL, 0x13015EB8FD597B62ULL, 0x621D101917F6A58EULL, 
            0x0E347074C3EDFDEEULL, 0x05DF2CE97629CA90ULL, 0x75720C721BAAA435ULL, 0x4DD392AD57A3A550ULL, 
            0x314FB2BB2FA82E48ULL, 0x7C8E63DE48238055ULL, 0x2BC244B3952587D2ULL, 0xB4DC646B14D2C01DULL
        },
        {
            0x116F89B381229FD8ULL, 0x4788C3973917DDA1ULL, 0x4AC98459F3133BC1ULL, 0x6FA69CA10A543368ULL, 
            0x9EDC941DC0E11354ULL, 0xCEADF6965049F54FULL, 0x7C7C0810E68663A5ULL, 0xE9CFB9030C323507ULL, 
            0x2DD54AC93F30CF7BULL, 0x76981B1D97BB842AULL, 0x46B2B0C5D8507D82ULL, 0xD7BFF47AC874FE95ULL, 
            0xFA80A70D05E3E95DULL, 0x874EE2F057899488ULL, 0x49ED2B3BF374D0CCULL, 0x2291B1577DE402B4ULL, 
            0xCDB0267579F2D15FULL, 0x2C45958974DE2E94ULL, 0x8EB2A82FEDB9719CULL, 0xCA748D5F24F52529ULL, 
            0xE0715114259CD110ULL, 0x7F13D15DB178AFBCULL, 0x0C097EA88FCA7E3BULL, 0xAF2B443EA518397FULL, 
            0x768BB9BA2050B676ULL, 0x6942B359134162BFULL, 0xC869054C419C2395ULL, 0x1B68FC7360C68CA5ULL, 
            0x9246D70529FA683DULL, 0xFF4B7FE51A737E9FULL, 0xEFB6B5DDBEE90BE5ULL, 0x586D32D3BF851A0EULL
        },
        {
            0xB1CB59DB022691F9ULL, 0xEDB9741A6DF179BFULL, 0x8171F183566ADA8AULL, 0x99264ED75CB7629AULL, 
            0x7F4BD2906AC2BD39ULL, 0x1140E60018573785ULL, 0xAC42AFFBD6021109ULL, 0xADF689EC98761232ULL, 
            0x8C18F26CCBDDBFCAULL, 0xBBC6839CADA78F6FULL, 0x874E2137C476F81DULL, 0x33C30292ED0367E5ULL, 
            0xF615827079A71C6BULL, 0x9023D0B1624F9040ULL, 0xC3564607FAC625E2ULL, 0x6054161AE1402532ULL, 
            0x7A645CDCB349247BULL, 0x0B0478D894FFFD6BULL, 0x594B5C47AAFBABB2ULL, 0x1FCD9DE933453BA9ULL, 
            0x670318048EC83695ULL, 0x0D6423DD4F89731AULL, 0x02D2892F553D8352ULL, 0xF66CA059677EE300ULL, 
            0x6F0C787E7580C6A6ULL, 0xA24CFE61B3C4961BULL, 0xB6B68709BFF5555DULL, 0x11615F304DD3ED09ULL, 
            0x1E7232973717368DULL, 0xFA268038CBEBCFFFULL, 0x45541600466190B2ULL, 0x74CB7820BDA9021EULL
        },
        {
            0x387206ED24E8B822ULL, 0xB176AB1306442E4AULL, 0xD70FC159134B5BF2ULL, 0xFB86DA9098C82D11ULL, 
            0x01BBE2D6F5449B7AULL, 0x211E8C8B0FA20158ULL, 0xFEEE1E314693AE76ULL, 0xE887831B4920214DULL, 
            0x2B996979DD44120FULL, 0xBF6F93D1975E18BDULL, 0x9743172B1D498283ULL, 0x2AAB55DD5A2284B6ULL, 
            0x9ADE5B143594E625ULL, 0xEB51547C6B469926ULL, 0x6329B66CFF3AEA17ULL, 0x852CE02AA9AC1CD7ULL, 
            0x52032FAEBB76EAADULL, 0x5CED433782ABD619ULL, 0x9E76338CBF5E18CDULL, 0x1EF790EAE1B41417ULL, 
            0xBD1FF3F60F1E4142ULL, 0xBB090D2A66ED29DCULL, 0xE8A0446F1772046EULL, 0xFA12B7CD9CF3E377ULL, 
            0x230B78447335CCA8ULL, 0x213ADEB3EC7B0FCCULL, 0x174F1036E827CA5AULL, 0x6D3417928C61097EULL, 
            0xD6C788248B613353ULL, 0xE9351B5C8CCE6E99ULL, 0x337F04A721BE1BC7ULL, 0x40EB308554E10290ULL
        },
        {
            0x12EE8F879E3FC7AFULL, 0x3AA1946CB197E340ULL, 0x82732EFFF12B1308ULL, 0x46F1BBA84481B988ULL, 
            0x84F12A7AA400DC24ULL, 0xC9C0AFE6D38A7494ULL, 0x30C0DD26C38DAE9CULL, 0x53694371F9F71495ULL, 
            0x5961709424B3CD8BULL, 0xB0EF1EEE2087B59CULL, 0x4868E8D769A9C09BULL, 0xDA1F1EDF42EB5F40ULL, 
            0xF671F5579F909805ULL, 0x6DB72B6172CF6CF5ULL, 0x373C340B55BACEF4ULL, 0xBB0DCAABD633C648ULL, 
            0x6A16F215F4F6E4F0ULL, 0xAB904D37E4752292ULL, 0x1AE067CF2086BABAULL, 0x1158AF6B18649808ULL, 
            0xC0C9D92F764F31FDULL, 0xEDA8A2D1AF8BE163ULL, 0x256A77BEC07ED406ULL, 0x88AFBFD05B729EA0ULL, 
            0x1523A2E0F7422BD6ULL, 0x4D7861940FE84993ULL, 0x8FC75AC0193BF563ULL, 0x62D595BD0197FC85ULL, 
            0x86E2C70C565A1662ULL, 0xB86762DF85661D5DULL, 0x0B6874C50688B388ULL, 0x384CF7A15E7BCCD3ULL
        },
        {
            0xE052CC86FE967D82ULL, 0xF39DBDB94EADD630ULL, 0x31FD3F91D1F5075FULL, 0x24038C38CFCF2893ULL, 
            0x244A2FB1CF6580B7ULL, 0x5548793EECA7FE70ULL, 0x69626B8A1DD6095FULL, 0x6B3B5400CC748444ULL, 
            0x2C354EAE4D10DFF3ULL, 0xF25C1EA4AB44B72BULL, 0x0087052FE332DE79ULL, 0x45402725DAC146D1ULL, 
            0xBFC424F1FC8A9545ULL, 0x21B8E8A4DEFC4C46ULL, 0x075D2EC2D7B13E1BULL, 0x6E89F83A3D404AC9ULL, 
            0x1709C04CDED20D64ULL, 0x1F0C2188336A1FD8ULL, 0x2DEE8C65EAE51690ULL, 0x82ADAD9CC52271F3ULL, 
            0x76FD886ECF97CCBDULL, 0x48FFF12B55487C86ULL, 0xD0386C0C6EF3C1EEULL, 0x862777544151210CULL, 
            0xD9EE602CAC4781CCULL, 0x41C0511FA2522E28ULL, 0xC2A8AC9C0CB41F8DULL, 0xE5D3D64E44EAD23AULL, 
            0xBC3952BE8B2381B4ULL, 0x7E6E877F00A7AE40ULL, 0x28C51621D8E85AB2ULL, 0x98AC2B4C9B60C1EFULL
        }
    },
    {
        {
            0xC4B90A8D59621674ULL, 0x703704362E03A7ABULL, 0xCE50BBBA47A21B86ULL, 0x19E650097B7D77BCULL, 
            0xA75DCD3E46FE226FULL, 0xD7A14E9884C88A3BULL, 0x91102C018C897CFDULL, 0xFB9CAFF83B12BC36ULL, 
            0xBFD8036CFAC7854AULL, 0x357A98931BDEF551ULL, 0x5009424EC564DAF8ULL, 0x15A3BA2788995E93ULL, 
            0xEEE436E5DD9E0D20ULL, 0x94E037B5A17BCDC0ULL, 0x9150171D56933265ULL, 0x4DD9162747C1BB99ULL, 
            0x6863F8F91F660D45ULL, 0xE5D18A3145F76245ULL, 0x5DB0088FC1380586ULL, 0x2E2AF3DCA0AC9B80ULL, 
            0x1DD092620E082F8DULL, 0x4B3ACD0D0EB63AC9ULL, 0x6D8CF08A013561ADULL, 0x20C8B018233B8075ULL, 
            0x5A83EF310D434B7EULL, 0xC7A859F6E4E1460EULL, 0xFB41A29A456F86A1ULL, 0x54ABB913116F6982ULL, 
            0xBD156F7EEB7EE9A7ULL, 0x13CE6D36F5E80F18ULL, 0xF649CC8195E4F968ULL, 0xD715CF93D253FF74ULL
        },
        {
            0x3E436A679995CDD6ULL, 0x41AFE514514DB02BULL, 0xA4F1266BE1426E08ULL, 0x0BB3512857022622ULL, 
            0xF4FEB1191BB6258BULL, 0x125C76D1F5848DF1ULL, 0xC88E753AA5A48FCDULL, 0x1C78F6528DF404F3ULL, 
            0xA67484FA2B8005DFULL, 0xE95F6766D5732547ULL, 0x4D15226A3CF26D18ULL, 0x5F6C424C59AFBBC9ULL, 
            0x462E9A841AA4F430ULL, 0xB177FF624776404FULL, 0xFE6838C6AF8F5049ULL, 0xBC0B1646A6CFDEF3ULL, 
            0xC13CD330FB3AF60BULL, 0x41C3B349FDD1C6EEULL, 0xFB8A473D21AB78C3ULL, 0x88ECDEE750B6BC8FULL, 
            0xFE783B05D2E34161ULL, 0x38EB5E4D673CF1B6ULL, 0x5BFC137224BA243AULL, 0x59D2D5BB43F71DC0ULL, 
            0xAE23216FD9AB3B1FULL, 0x55C3AADDACE6F440ULL, 0x3BC9C58E52FCB642ULL, 0x5E464A4CC3FE7DC2ULL, 
            0xA1B89F0C3C169600ULL, 0xB805FF8193EB2FABULL, 0xBE17FEC3C1F2FDEBULL, 0xA4FDA125BEC7741EULL
        },
        {
            0x4A44D95E4C47A01BULL, 0xC3B886CF117C377BULL, 0xB1CFBA514B4A1EE0ULL, 0xEEED5125D9F0D007ULL, 
            0xB4A04CDB22330F04ULL, 0x3AAB16D836C7D343ULL, 0xA9845A797B1FAC92ULL, 0xC229A8394898C752ULL, 
            0x26A1DC086361F8CEULL, 0x6C7FB460800B6A49ULL, 0xDD3EF9055EBAD69CULL, 0x8F20D8CF412C18F4ULL, 
            0x6FD9B3C4A796009DULL, 0xA7DE963825D6AA0DULL, 0x5555556A635B3DC6ULL, 0xD3FDEE783640C3C9ULL, 
            0x0D5730E9318CBF62ULL, 0x6CDB981EA16A01A5ULL, 0x9E1140B7FE78F8F3ULL, 0xC67C6386EBB880D7ULL, 
            0xDD5DE8A243488FB8ULL, 0x2C7E89B1B430078EULL, 0x5896D72E061B7DF9ULL, 0x76FCEE14E2253CB5ULL, 
            0xD4098FBAC228B374ULL, 0xDE8E2226F6F5A664ULL, 0x2B9784DD70E9AAD1ULL, 0xDAD8DEB6FD344646ULL, 
            0xD87BDCA86D2B30C7ULL, 0xB26657431B7D4DB1ULL, 0x490B82A24953F7F0ULL, 0x60365B45BCFB911FULL
        },
        {
            0xDA97968B0EFFE351ULL, 0x883AF238EDCA4D59ULL, 0x0F34F34BC20BEA49ULL, 0xE814296CBD68F299ULL, 
            0x88D6099833EF3972ULL, 0xC678DC0D39F086C9ULL, 0x50FEC0FAC38CE88EULL, 0x78FA347A1A964952ULL, 
            0x31480467A8648D15ULL, 0xC5FC9799299A95D0ULL, 0x791B03B631D349F5ULL, 0x9CAB72F70D572A4CULL, 
            0x36EF211392B9410FULL, 0xA25128F1BB54B5C8ULL, 0xBC8D379BFB90F4CFULL, 0xD4BB054038F4F2B9ULL, 
            0x0BB551F34A26CA3EULL, 0x16368B1991211FFAULL, 0xADDA8DD0CB1029FDULL, 0x6FAEBA2593634A04ULL, 
            0xAEF8C33BCC0E5EBFULL, 0xA5036A5AF6D47AECULL, 0x3B89DFF3BFFA2CCCULL, 0xFE35B6B3E13F9544ULL, 
            0x15FF0191181B63AFULL, 0x45709C4F11261A88ULL, 0x0B8F3B84067935E1ULL, 0xB873ED4A5070DE8CULL, 
            0x5F78F96BC2CD4148ULL, 0x3DDEA7A6538CFC52ULL, 0x41E78560ACB6E3FBULL, 0x2628AFFBE006EAD0ULL
        },
        {
            0xBAF6CEC83CDC3CF2ULL, 0xC8EB2180C2DB4B6CULL, 0xC7A606B61FED2920ULL, 0xF13BD9AF8083E78BULL, 
            0xABF7C456C246B5E7ULL, 0x111BF4B5871DB12BULL, 0x5432CF86C5312435ULL, 0xB7B55E3EF12B395CULL, 
            0xEDB1D6E05A1BD816ULL, 0x7C8306E5D8E918E8ULL, 0x067BC0551865002CULL, 0x353C5A1AEF3812E0ULL, 
            0x2DF2B5F2193E7DB7ULL, 0xD838CCF50543B2BCULL, 0xBBD7399AF62555E3ULL, 0x8F968085D9C8C61CULL, 
            0x1CA6E45653D6D982ULL, 0xA6ADCD55EDDDD529ULL, 0x6F64FEE0D1A7BF28ULL, 0x5049DD617DB227DEULL, 
            0xEC306BEE01DB04A7ULL, 0x2856D7A777E1D27FULL, 0xD47CC4E9847FF57FULL, 0x733DF192953874FBULL, 
            0x7E9607B9A09B5C14ULL, 0xAC1F341F978E25BCULL, 0x498F594B2F6C105DULL, 0xDF1917BA52552BBDULL, 
            0x7F57F8D994FE62CDULL, 0xEB2D63AB0AF289F4ULL, 0x1CDB7714CEE7FA85ULL, 0x3BE821CA47525C4AULL
        },
        {
            0x146CC1E6BA9BDCDEULL, 0x0F8F7FC6759B4498ULL, 0x7810102BE515388EULL, 0x5E65800A0A925CA3ULL, 
            0x73F9FD4F7FA127DBULL, 0x74055355FBA1BD0CULL, 0xEA97015A96886450ULL, 0x529252280E080010ULL, 
            0x2CBDF81F3673B8DDULL, 0x22661BD9A03CE0DAULL, 0xF9B1D50FE6EA7239ULL, 0x58A165CFEDF60726ULL, 
            0x2CB1BB8DACDA229BULL, 0xA5F953CD301F9271ULL, 0xDDC112FF3E4DB1A9ULL, 0xB1EB1312E18500CFULL, 
            0x793A97693AE19065ULL, 0x1F5C0789E950F8B1ULL, 0xF863F40F73E70D1DULL, 0xBE07AA9A758B50A8ULL, 
            0x93C1307527B70F75ULL, 0xC05C5A0C633F7D73ULL, 0x53E8E4297A4A2B1AULL, 0xB9DD1D3FA93E6332ULL, 
            0x4E5ADAFE0DBB099DULL, 0xBC5258C87ED86366ULL, 0x3107488461C4749EULL, 0x909AE952E8925023ULL, 
            0x8025D458DDC25A14ULL, 0x928E1E8705F9F661ULL, 0xEB6BEB5D6D9F193CULL, 0x00129AAE07812879ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Altair::kKeyRotateAConstants = {
    0x9901E77E88E84DE5ULL,
    0x14B8F85EA9FB6EF1ULL,
    0xCBF5D79D51599787ULL,
    0x9901E77E88E84DE5ULL,
    0x14B8F85EA9FB6EF1ULL,
    0xCBF5D79D51599787ULL,
    0xCE90E4DC7D8E9084ULL,
    0x94D191F319CD680DULL,
    0x74,
    0x80,
    0xDE,
    0x5C,
    0x98,
    0x83,
    0xA7,
    0xEF
};

const TwistDomainSaltSet TwistExpander_Altair::kKeyRotateBSalts = {
    {
        {
            0x0F111F61FB1F038EULL, 0xD01B6333E103E0AFULL, 0xFCF114A1243187AFULL, 0xBB0DE62956B205E0ULL, 
            0xA3CC28D00988DC6AULL, 0x37866E3930311B06ULL, 0xD7EF44BC29B1AE54ULL, 0x5FA07ACA918C5C31ULL, 
            0x60F63F24F7475978ULL, 0x6F53264A8AB93C2DULL, 0x65CFF64F4650B0CBULL, 0xAF884CD27B15BE92ULL, 
            0x145CD0A7E9561067ULL, 0x2A1FF6E845F93C3BULL, 0x01D01D4213F0CE24ULL, 0x3B478B970FF9BF06ULL, 
            0xD14C618D807F1908ULL, 0x34717020B7CD8E58ULL, 0x4BFBA9490B11D207ULL, 0x3D5BD191AC4518E9ULL, 
            0xEEB21F477B4A997AULL, 0x1CF1A3C115FFAE51ULL, 0x92A56D0CF936759CULL, 0x2280D09EA0E487B6ULL, 
            0x4029C8ADB9B13458ULL, 0x88B95A2E06B0D4B7ULL, 0x65113D7C4CF4A7D5ULL, 0xD05B4BC846C384C9ULL, 
            0x4FB78061BFA87F71ULL, 0xA217DF1393FA8BBBULL, 0xA41FFD71902453ABULL, 0xFF7C53085541DD95ULL
        },
        {
            0x6B5CD7B0AF32AB1AULL, 0xDFA0A4D475E66D43ULL, 0x4A36BC63AE60DA38ULL, 0x45A91A9D2A367BB9ULL, 
            0x6677EC0A6840C7ACULL, 0x5E529F2488911B2EULL, 0xAB7B3E7AE0357B13ULL, 0x6BFA33BF9E51C67AULL, 
            0xF70F995A81816D7EULL, 0x7F5F91075442840DULL, 0x524FFF78E390E4AEULL, 0x7CEF2CF5981E872CULL, 
            0x27D306258249B1E3ULL, 0x2C74F77B1FFBAA3FULL, 0xF082959114729743ULL, 0x494994DBC27F4F8BULL, 
            0xC98901AB364A74A2ULL, 0x22635CEFC82C38EAULL, 0x8D59086E51B89AB6ULL, 0xBE3D2ADDF69A940DULL, 
            0x01B5B8FA16038FF4ULL, 0xBD808E0B25A7C8F4ULL, 0x2D6A85EB1129CFB7ULL, 0xF2C93562029C86ACULL, 
            0xBB6E27465C0B9BB9ULL, 0xF54C307139970A5EULL, 0x95C03A33FE99C322ULL, 0xA8BC8E1EF7EB9C01ULL, 
            0xCCF277D2610B3F6BULL, 0x085081C2ADE6463EULL, 0xC16F08D92FE754E4ULL, 0x4436CFAC0B5CFBDEULL
        },
        {
            0x3ADFDA11C024B8EDULL, 0x9C2A85A6A29663C3ULL, 0x558E92CA6BC8581DULL, 0xB4D938AF18673A10ULL, 
            0xD183CB36B67A63DAULL, 0x0F996DF342D4FDC0ULL, 0xB58A06FC17ACDAE9ULL, 0xA198408952A2B4C3ULL, 
            0x4789525CD92A5ADAULL, 0x969A327D20BE0655ULL, 0x5B824B8B5452689CULL, 0xE11F1399D222EF71ULL, 
            0x52EAFCE8CDEEE299ULL, 0x25E6D2DE9C1743B2ULL, 0x94FAC12540F5D437ULL, 0x5B9D69F1A0B3BA80ULL, 
            0x04ED445E01E74C7DULL, 0x37B6D9A8D3ED5D1CULL, 0xAF154298C6336367ULL, 0xFE5A45752F2406F0ULL, 
            0xDEFB6FED6D7DE44EULL, 0x124C4F576DCB68B3ULL, 0xA25A4C9662221B54ULL, 0x7A10B5416C56E809ULL, 
            0x6B8A7374E3D802E1ULL, 0x5746E91C9F3C6451ULL, 0x29D1085B40A58B98ULL, 0xB88081841B61FCE3ULL, 
            0x9E746FF44A9E9623ULL, 0x8786EE6BEC6EB1F5ULL, 0x254B0060A7814020ULL, 0x5F89181CEB472B9BULL
        },
        {
            0xFCCBCEED16CE1152ULL, 0x63FF7F5CEA58D469ULL, 0xBDF427BF27F99937ULL, 0x797BFB1FEB3EBD98ULL, 
            0xFB6EAD1D61061D09ULL, 0x809602051A8A803EULL, 0x02D054CA3C99E7A8ULL, 0xA2C791E0F933BA8EULL, 
            0xC3C640FC2CF01546ULL, 0x2F9D209D84FF9AA8ULL, 0xE6581FC32A8FDD34ULL, 0x392F74243EFBAA1EULL, 
            0x256583777575EB78ULL, 0x37D34391B6C864BCULL, 0xA687A681E7918ECFULL, 0x1571A1EC37116109ULL, 
            0x67F50282351A9D6EULL, 0xBFE7E584CEEC9700ULL, 0x41707B6DF42AD1F9ULL, 0x9BC87E91F18E4FCEULL, 
            0x312D4C62412C91E3ULL, 0xA574AB39344B1C39ULL, 0x12E5B3BA4269568DULL, 0x34F5F99F1EEF5A23ULL, 
            0xC9726E87A639BCE7ULL, 0x045AD323C1470748ULL, 0xCEE18258CD6F0095ULL, 0xE86B5C328D0C639DULL, 
            0x123AD64C9BA29814ULL, 0xC1335F01DD9F5C0BULL, 0xE87075E6704C31AFULL, 0x4A076206DD9E3A0BULL
        },
        {
            0xE56CF202B2C6B4F9ULL, 0x0845048A217C82F1ULL, 0x4EA107BABB3DF7EEULL, 0x83D163DDB9D907F7ULL, 
            0xFDCBDFCA375B7A5DULL, 0x91FC3A879CD02542ULL, 0x3B41465AA15EBEFAULL, 0x112D84E68F0D3F53ULL, 
            0xB7A06AA98F0DF2E9ULL, 0x4B9547D29086BB56ULL, 0x4D3CCBC9E5D0AC9BULL, 0x5E8A7D0B92FA5E9FULL, 
            0xD93237D14B1D5032ULL, 0x3ECB82AF5A4F1F28ULL, 0x199FFF36A6A8EA00ULL, 0x80D55538232122FAULL, 
            0x4786368D07C87038ULL, 0xBE6E810CF6A513BCULL, 0xD777A5683BACB51CULL, 0xB26BEAEA7754DF55ULL, 
            0xFBB9962707824028ULL, 0xEC6276B701DAF8D4ULL, 0x432A7D02016DBF6CULL, 0xB710BA07E92243E7ULL, 
            0x64B8265444C210B7ULL, 0x0F7F0728E7A11596ULL, 0x04D439C89F5AD5EAULL, 0x80A59DD071B292CEULL, 
            0xD008B0A421AD8A2EULL, 0x673DA69E3DF34BBFULL, 0xE9D0FDFEBF71852EULL, 0xDB03A55D539AD261ULL
        },
        {
            0x9E5D25F9BB75CEE8ULL, 0x8CF9F4C521068522ULL, 0xC02CF374033DB3B5ULL, 0x57F48CFF18A020C0ULL, 
            0x6C1D3C9C0FB9E875ULL, 0x7A5C1C9D7F71299FULL, 0x7E0C0882FE1EC424ULL, 0x354242049A00FBF5ULL, 
            0x417122F7AA55647BULL, 0xF685119F2CE4AF82ULL, 0x4D9C7A42EC329281ULL, 0x50EAFABDD6722A45ULL, 
            0xDC17FF017B0E1B20ULL, 0x3FC100F78B2DE8FCULL, 0xEEC97502B46AB6DCULL, 0x0DD128CD2D98CC6BULL, 
            0x4F45630E0EBB0F16ULL, 0x8E8E7CB5E5F640F9ULL, 0x2A64605D58A7AC72ULL, 0x18FAB745BCE77238ULL, 
            0x00121BAC59D1FBE2ULL, 0xA5D4B9EBC607B310ULL, 0xABA1759DE74E47B8ULL, 0xCC040005D4537674ULL, 
            0x0AB6535D0D80E592ULL, 0xC9552FF671E528EDULL, 0xA881AD468FBA83E6ULL, 0xDBCD8ECF79CF0E21ULL, 
            0xC2CE5E719BAF7E81ULL, 0x79FD11D2ACBD6721ULL, 0x8CC7FB985137FD1DULL, 0xC1FA7A43C3FAA2D4ULL
        }
    },
    {
        {
            0xF8B49C2B03BCD035ULL, 0x8FAD31015F9B0F84ULL, 0xEBFABFD1B8CD8B6FULL, 0x5FE94373674EEEFCULL, 
            0x33CC1C00DC616CF1ULL, 0x22595CCFD437E5C4ULL, 0x6DCDE465A1FDBE67ULL, 0xFBD875B2C68A4D25ULL, 
            0xA5E75E86BF4280DAULL, 0x59A86051429901EDULL, 0xAD7DF34EF02E4F8FULL, 0x46B0E9FCBBB53AECULL, 
            0x39AD0D8D9C37ECD1ULL, 0xC14DF62A6C0C1CE4ULL, 0x747C99DDE5BD7D55ULL, 0xA2CB71E1BFF1B1B6ULL, 
            0x8191FD1C787689F9ULL, 0xE97DAFEDCA01203AULL, 0x4CA71EDB1D956428ULL, 0xE84E15FADE06268CULL, 
            0xE2F781D468BA16BBULL, 0x17EC3882760183A9ULL, 0x85D0C16506AB5298ULL, 0x71AD30B3D250AE3BULL, 
            0xD01D4D09410E226FULL, 0xFF59B5C9270979D0ULL, 0xFFFCC026194CB2D9ULL, 0x3BEE22A1E5CF39C0ULL, 
            0xCC6B3896EE78DDBFULL, 0xF7F627D44C1D7814ULL, 0xDD0ABCD9D5999C4AULL, 0xA7DAAAFB4E95E8B2ULL
        },
        {
            0x60F99748126A3407ULL, 0x4CF1D92421BD40CCULL, 0x92DE9BDC0E3AC9F1ULL, 0x437EB301D06D3763ULL, 
            0x27226D9FDC9F728CULL, 0xD0CF3E1CBDCE5EAFULL, 0xD07FD474FE37728DULL, 0xC2ED1EBE31EF11E7ULL, 
            0x19C9A00D9B35AEFDULL, 0xC8EDB0FC819D2771ULL, 0xDA590C098374496FULL, 0x2D890EC0E93EF901ULL, 
            0x868532666695B66DULL, 0x866E31E4C4905EF6ULL, 0x6CDDE01917C9A869ULL, 0x03C9C796134B7695ULL, 
            0xACFE49318C905A03ULL, 0x64FFB7E99A8BC365ULL, 0x286351F43377DD63ULL, 0x313DCD25317C05ECULL, 
            0xB51B2EBC9E3DD775ULL, 0x4CC18CA2ABD3C95DULL, 0x61520F19B9B4BD72ULL, 0xDD81C786B3024D01ULL, 
            0x23628DCD88B11ECFULL, 0xC3299AA138E38866ULL, 0x80FFB96DD538F59AULL, 0x6AEE42F560316359ULL, 
            0xD8C2F503173FB594ULL, 0xDFFA424A8198969AULL, 0x2606B334C8CD3C33ULL, 0x9DB31B453247964EULL
        },
        {
            0xCE2C29E50C87A6F2ULL, 0x86FDF20326890F5CULL, 0xA579AB4A668DF773ULL, 0x34A19EC2064E3C43ULL, 
            0x16AC990D10B64538ULL, 0xED2063B7153CB13FULL, 0xC267EB49EF155D29ULL, 0x2451913A7F75A13DULL, 
            0x2F5E00727A59E17DULL, 0x991DB396C9608633ULL, 0xD5FAEF89353649E8ULL, 0x90935499FC98968CULL, 
            0x2FB1EAE149B12027ULL, 0x4F694BB27FCCFD61ULL, 0x19913A22902B6C8BULL, 0xF2BF2D827CCF5CC8ULL, 
            0x2E83937ACC4888ABULL, 0x5C1567AD9A522738ULL, 0x44AC60FB75326CE7ULL, 0xF1857871F29BB00EULL, 
            0x36E0F590D2C498E1ULL, 0xD0651714EF480D62ULL, 0xF3A5E3A80C9F1748ULL, 0xCCA4DFAB79C1D27BULL, 
            0xCFCED350A5FDA8EDULL, 0x937CA32E947A0307ULL, 0xA3F0BBF60B0EE471ULL, 0x80D61BDE33E80A66ULL, 
            0xD253BF7CB2A4C169ULL, 0x8CCF7AF6F55BC2F4ULL, 0xBB4ECC66FB70D956ULL, 0x961AB424491CC6BAULL
        },
        {
            0x3738C48D200A8D5AULL, 0x1100E853109EE5E4ULL, 0x8426875A4D008F08ULL, 0xDB7D7CB04304F914ULL, 
            0x14B0FD9FE45EE4E1ULL, 0x2FD83E953A1F12D0ULL, 0x0CCC28B669DADAB8ULL, 0x6941A3BF237D82D3ULL, 
            0xC72811C78E3A7632ULL, 0xE34E6159AA5F5ACFULL, 0xFD206CE2A31A5300ULL, 0x4497ADF210DA48A2ULL, 
            0x296A258E65C81754ULL, 0x306A25C11E157CBDULL, 0xF1F1AC0CF5F6B826ULL, 0xE3A5918BE0E073C3ULL, 
            0x72FE56BEAFC575ECULL, 0xB73D51E9A9B0CEF8ULL, 0x91923137E7352961ULL, 0x9DD343DC62611B1BULL, 
            0x8D6A56E6B4AA813EULL, 0x0E0D446C0F432196ULL, 0xAAE2CD3C0F079185ULL, 0xD0606D179DE7E2D4ULL, 
            0x97235AC3D77C29B6ULL, 0x6AA87C6530CCA2D6ULL, 0x649C73A55158BA88ULL, 0x9934023A6C8B4D32ULL, 
            0x17F3978240E7D2C2ULL, 0xF02DCE260DAA15F3ULL, 0x8BEF6EBBA306D117ULL, 0xDDBD9B6D52AC98C4ULL
        },
        {
            0x4781CE247A74F258ULL, 0xAF00AB0742DF9CEAULL, 0x38999D4994D43293ULL, 0x25ADAA787700CF06ULL, 
            0x05F6FA978E7476C1ULL, 0xCB5110CD193B2DEDULL, 0x53417728314FFD73ULL, 0x42E595871D897FDEULL, 
            0xB9C6569B8F6AF70BULL, 0x3D78F00C5FE83BD9ULL, 0xEDEEB7645DBE7E02ULL, 0x3FB8A77000C9022AULL, 
            0xC6725B6F6AACDBBEULL, 0xA752EBD52524B49DULL, 0x68A24C9F64373273ULL, 0xC5591B44CBF7251CULL, 
            0xFFFE269952CAA4D8ULL, 0x9414EA41E13513B7ULL, 0x0F5A1F979AEB41A7ULL, 0xFA7A4E9ADBE444C2ULL, 
            0x5FDE66470D152D4DULL, 0xB176A0E5AC9E4DDDULL, 0x6576AFF5714DC56BULL, 0xD0633B3A9FC2CE51ULL, 
            0x7B0083CD34289F0BULL, 0x74F43C753F3B0382ULL, 0xDFD9EAFA324171F3ULL, 0x388848AFA81ACEB8ULL, 
            0xF5EC98BBA56DBB0AULL, 0x42F5B978720314CEULL, 0xA66C45F383649B3AULL, 0x218C336E90DBABAFULL
        },
        {
            0x4D9CC6C5147F719BULL, 0x21B6435F75F550DAULL, 0xE82626FE9E7FDCD8ULL, 0x98FF9D45AB24A0ACULL, 
            0x0B8350F575DAC7B4ULL, 0x09562BD91F63892BULL, 0xD194B9AEFFEAD27EULL, 0x8444159E0D04EAE0ULL, 
            0x8EE2A2CE9615891BULL, 0x03AD73A72DBC30D0ULL, 0xB2E61B7E0249352BULL, 0xCD1E5A6B1A2B3EE7ULL, 
            0x8D7629815F07CC4BULL, 0xA8681079E97DB3B0ULL, 0xC1BAD52871EA0E92ULL, 0x167A8E25A5AB2459ULL, 
            0xE831DD921277E0CFULL, 0x6FB8BFD014094870ULL, 0x4C9BFED882F8C4FFULL, 0xB4DC60E317AE0955ULL, 
            0x787BCD808473F633ULL, 0xDFDE1862573C2887ULL, 0x1D613AE1EFA61496ULL, 0x5EC07F3EAB845116ULL, 
            0xE069EA41D9E14189ULL, 0xBE3A38A219E31A6AULL, 0xF5730E18A9D90BF3ULL, 0xA173F1E9EF4065C4ULL, 
            0xC3094AA4951F8F30ULL, 0xBB43955BCB4327ADULL, 0x0606C23FC7B2A42EULL, 0x71B669A4CAD13E7EULL
        }
    },
    {
        {
            0xA5D20DE647F72DFDULL, 0xFA0F76F125CCA245ULL, 0x4D6A2502A8A4B01DULL, 0xD557DD5C3807269FULL, 
            0x57CCAB460B3C53B9ULL, 0xD55294C855A68F40ULL, 0x9D6D6E9618229A55ULL, 0x105E0655E71411F3ULL, 
            0xBFA79B130FF6DD82ULL, 0x37210D6655550673ULL, 0x38F7C425CD8D5C1FULL, 0x7DCDE42608DDA318ULL, 
            0x6084342B86B09D5EULL, 0x4644633C062D4DC1ULL, 0x04650986F2827A22ULL, 0x569685C3BC179C3BULL, 
            0x8FD88864CE8EDED2ULL, 0x7B46F05CD1B31696ULL, 0xC388D87662A22B22ULL, 0x65A4E483E125734CULL, 
            0x90E80361CB138519ULL, 0x6256D81952A3D037ULL, 0x4ECE7E5FEF9CC50BULL, 0x32A53BDB3F40A064ULL, 
            0x8C41FE8A26A172E1ULL, 0x7945E483E0D4846EULL, 0x614978B5A1CCC67FULL, 0x630419938A459695ULL, 
            0x8B514B26844D5446ULL, 0x7DD92DA578F69D06ULL, 0xF5ACB72D2D471852ULL, 0x90AE9D7C8016E07FULL
        },
        {
            0xDB6F455B6543D027ULL, 0xBECF0D3FD47444EAULL, 0x9DF1D860BC88B12FULL, 0x0D7462C5B087977AULL, 
            0xD08D8749DDB45626ULL, 0x8074D4C5C8AF7D07ULL, 0x45D8A65C5E464B33ULL, 0x7F1FB0D06D7DB6D3ULL, 
            0x66D1E33448B7A223ULL, 0x07B69548A0B5B10CULL, 0xAB98B78E38863FDEULL, 0xA223F166717A11EBULL, 
            0x228717EFC93E628BULL, 0xBC78578F45922926ULL, 0x08197EBB2A164202ULL, 0x6C798B540ADAA086ULL, 
            0xE73A2AE505640458ULL, 0x770F0D15134E51D5ULL, 0xDAEEEFAA5595F06DULL, 0xD3321BE007B6C5DBULL, 
            0x365402172251F13BULL, 0x8B34EE527BD19EEFULL, 0xE1DFD28A5FA1997BULL, 0x17D0AE771B3076B1ULL, 
            0xF9E379E50ACB2A6DULL, 0xFBCF6E78AE1AF839ULL, 0xAC7C0445AEA21C03ULL, 0x5CA6BF93E9A46EA4ULL, 
            0xCB65E9DEB8B1CD05ULL, 0xE91FE7383C4E929EULL, 0xA09F1244B0D4981BULL, 0x6E4430323CFB2EB1ULL
        },
        {
            0xBE2E009205AA71F6ULL, 0x5D676BED4D0DD07AULL, 0xC9601A997C54C1A3ULL, 0x8E0E71E3066592B7ULL, 
            0x2BCF51E0C90019D5ULL, 0x7EAA708287C63787ULL, 0x0370CAF111909562ULL, 0x9C7F74DEBA24A51BULL, 
            0x3A1B1E5204198DCBULL, 0xDF2B8B3172DBA501ULL, 0xD063487E32170676ULL, 0xAD970DDCBB855D28ULL, 
            0x178E77148A051C35ULL, 0x79C82E59476D3305ULL, 0xE62420500BC10A9FULL, 0x7B87236A1E9105A6ULL, 
            0xF3DBF4A0992AFAF1ULL, 0x6CF12263EDC72C31ULL, 0x40D34BEDD804B4E9ULL, 0xD6D2486262E5CB7EULL, 
            0x583BF7FFFA99889EULL, 0xFE773A191C20E528ULL, 0x29B801D963D8FC3EULL, 0x67254BF73F970DC8ULL, 
            0x7042A96454375A11ULL, 0x7D32777745D64196ULL, 0xE9180C15EA9F03F1ULL, 0x15262B2779749128ULL, 
            0x831DC3DDC057058FULL, 0xDD6F88099A35389EULL, 0x3E32F7BEAA54A428ULL, 0x99B059B14D9463B5ULL
        },
        {
            0x12FA326FD8F067F7ULL, 0x55D12439ECAE4F6DULL, 0x3AAC71A159A83D3AULL, 0x381D31366AD4899EULL, 
            0x9495909BF19058C2ULL, 0x561CD4B7B91499B2ULL, 0xB691F37F43E3AD98ULL, 0xBE76CC7CE3173D46ULL, 
            0x6B563CFD356C4898ULL, 0x50133DA44DA59676ULL, 0x5C0A194BDFA5AF92ULL, 0xBD0B88533644771BULL, 
            0xFFCBFFD472333B21ULL, 0xE0D9B24C97977F90ULL, 0xAE8D8A39924632BCULL, 0xF0B020DC93465AF5ULL, 
            0xEDA18B72E3B4D24FULL, 0x0BF01A6A0CE033AEULL, 0xDB22B32BA3FD7035ULL, 0xA660D06E920F245EULL, 
            0x7D0ED61C293574EEULL, 0x8A18B368AE6ACB87ULL, 0x827CD6903127309CULL, 0x02C29507FEFCE570ULL, 
            0x847366A98078058EULL, 0x6C6E10B3ABC3BF83ULL, 0xFD61B441067E5CD6ULL, 0x4A2C27593AE35868ULL, 
            0xBC2B6B8752379A38ULL, 0xBAE3BDD198C43821ULL, 0x30C691A5F44FA600ULL, 0xF300ED91D9AE9259ULL
        },
        {
            0x9355A6B8CB31C9CBULL, 0x9B60BAC5FE91C9A6ULL, 0xDA2E8DC0A78D9226ULL, 0x9D1D97A14FAF9664ULL, 
            0x5172CC5D5980E9B7ULL, 0x3F7550334C58341DULL, 0x75682720D11ECEDDULL, 0xF81632CDCD25A932ULL, 
            0x5ED242A4BFED27A8ULL, 0x6B38CE40C412358EULL, 0x1C86C9DA9E6D4E11ULL, 0x9D5F7F0AF86BB15CULL, 
            0x49265948E607249AULL, 0xA1D84EF5ED58D721ULL, 0xF47167DC0B578173ULL, 0x0426AFDC802B5459ULL, 
            0x745A9918228BF307ULL, 0xF4039C5BAF172AB8ULL, 0x2C5E2600E66278ABULL, 0x00B4ED613638221CULL, 
            0x2CE887A3DCA742C7ULL, 0x10EAA9609C37CB4BULL, 0x30A0F54F1D7BFE1EULL, 0x52CEBF8F083FD8DAULL, 
            0x6157CE86AC6814BDULL, 0x73FB229E267B01D4ULL, 0xA225583EAF6DC4CAULL, 0xAB993F4776FD602DULL, 
            0x10F953DF1106E5F3ULL, 0xC88C8A4641458535ULL, 0xE11EF4C5DA9E521EULL, 0x586AED762BA505B4ULL
        },
        {
            0xACFDCAFB4F59D624ULL, 0x2B20B128E8F46E57ULL, 0x28D6D503A98FF883ULL, 0x9947C7753209104BULL, 
            0x6B9955C78051C8B3ULL, 0xB0D82DB93E4009BDULL, 0x18A830D48471AE4BULL, 0xFB0C7D96A38CBD1EULL, 
            0x844DA419BE871939ULL, 0x764F5E034ABD8823ULL, 0xD770D9282E9C061EULL, 0x246C57FD5AA4D13EULL, 
            0x00C4BCBA93260FA1ULL, 0x4723A7087DC08B73ULL, 0x11E4C8D41B979B35ULL, 0x079DC8EAA7289A57ULL, 
            0x886E7AED2DD4D6B8ULL, 0xBB996CA7E338ECF6ULL, 0xCF506B3ED16594B0ULL, 0x0E48DD17910A69D0ULL, 
            0x24BDB7E0F5A650D4ULL, 0xDC26F178B52169B2ULL, 0xD4BAC33FD2DDDB69ULL, 0x7C33AF5F45295C17ULL, 
            0xB934C6498A231CECULL, 0x222D69129CEC5621ULL, 0xA60A3344AEEC58CBULL, 0x6FD8983D05537314ULL, 
            0xEDCB182476247C95ULL, 0x9B9EDDC02F642FC2ULL, 0x648E46246A9F265EULL, 0x1A8EB44DAFAFF1DEULL
        }
    }
};

const TwistDomainConstants TwistExpander_Altair::kKeyRotateBConstants = {
    0x9F4B93AD5FDB19E5ULL,
    0xEF5762039CD488F0ULL,
    0x13AA490B3B934116ULL,
    0x9F4B93AD5FDB19E5ULL,
    0xEF5762039CD488F0ULL,
    0x13AA490B3B934116ULL,
    0x7A10F6ADECDAC215ULL,
    0xE6A1E0AB5E875CF6ULL,
    0x78,
    0xD8,
    0xDB,
    0x1B,
    0x0B,
    0x7F,
    0x47,
    0x7A
};

const TwistDomainSaltSet TwistExpander_Altair::kKeySpawnASalts = {
    {
        {
            0x2E83B3837A9651B9ULL, 0x01134E4EB6BD83EBULL, 0x15922106C7722C0FULL, 0x21ED2D352D4E6707ULL, 
            0x33FC21F014E6B8D5ULL, 0xC0938C4E11A60DD4ULL, 0x8C8A35C8698D865FULL, 0xC91C656165E499EAULL, 
            0xBD572A57005B340BULL, 0x956FBFF68A431966ULL, 0x7D4052F77A074415ULL, 0x2050460F16BA6A22ULL, 
            0xC562F66D76392EF1ULL, 0x3C1B6E9C680E302AULL, 0x81EE94C2DE201E37ULL, 0x1CBAA44B7F81C38CULL, 
            0xA2A25B6E6A8F16CFULL, 0xE29A78C81D1ECAFEULL, 0xB41898E6202F7CF5ULL, 0xDE0132A78B18472BULL, 
            0xA9C2950E4C4CC6D7ULL, 0x415A19AD55B4E5BEULL, 0xA18244B7FE670BC6ULL, 0xE587B4DB1CED69F8ULL, 
            0x306134FE089878B9ULL, 0xACE8412256AFBB1EULL, 0x5FDAE666989FA613ULL, 0x2E943BA0124E79CAULL, 
            0x47EB0FC3798C568FULL, 0x2FC9A73DD3B80660ULL, 0xEDE4E37086F5CDAEULL, 0xF9EA62FC19FDB3ABULL
        },
        {
            0x696E839783B0A327ULL, 0xB4E25D5AC4B424B3ULL, 0x4ECCA54A17D78E6AULL, 0x009BDC50FA4B1EC6ULL, 
            0x2FCB1E52F72AF56BULL, 0x6EC4FDA1E3263D65ULL, 0x43FFB65B1D8D633CULL, 0x4A7898DEC36C8199ULL, 
            0xC62C414B6C595215ULL, 0x11DE7383D3D95C30ULL, 0xBDEFEBE26418F6B9ULL, 0xABA05848A5580D03ULL, 
            0x256266D6F11180D0ULL, 0x5A8E51E3CEADBDD5ULL, 0x65ECC88F24520C99ULL, 0xBBA594BA181B1064ULL, 
            0x78D3DD05C9C730D0ULL, 0x64240FDD5740D502ULL, 0xD537A6CCAE021E26ULL, 0x10EBFA6BC6A99EA7ULL, 
            0x9D2A80B12E5E8F02ULL, 0xF7452B46DCC5DA24ULL, 0x5DD918CA8C517970ULL, 0xB8F533DDADA11F94ULL, 
            0x4B7662A53C16F02AULL, 0x11D94CAAC3B42E7DULL, 0x5815271A8B79E6EDULL, 0x05205E099C32E6B0ULL, 
            0x0EBF39D21915FE87ULL, 0xE65965B662EEEC0EULL, 0xA3EB0C0A708CFE9CULL, 0x0B2545213F8E9C59ULL
        },
        {
            0x47A1732BA1653C1BULL, 0x5773C94377C7034BULL, 0x2C8AE4EFDB447976ULL, 0xF0A13E138E920313ULL, 
            0x9090A3B71FA2CE29ULL, 0xE09B34F1EFA2AB55ULL, 0x5A365102F965A47CULL, 0xA53BDFFDDC0374E6ULL, 
            0xD93CE793AAAF5718ULL, 0x8933FCE23AAD3361ULL, 0xF29FFD28643FB94DULL, 0xC61B8AF3807B84F9ULL, 
            0x4A4170FBB2DA28BDULL, 0x5AA3CB490E10E54CULL, 0x3FD9844A47F445A8ULL, 0x215BD41C99D13060ULL, 
            0x22F876ED3069538AULL, 0x8A6C9869BE8D59EAULL, 0x670EB0A86944BB2DULL, 0x0EDA972D2AEF1CB6ULL, 
            0x4C271B2033193D0DULL, 0x243BCB3E821D82D2ULL, 0xE00985F637B42155ULL, 0xB99F5A06EB9B0744ULL, 
            0x8A860A57D3A49309ULL, 0x0F59BCC5CB0A4083ULL, 0x1C0F5F06D2F07699ULL, 0xD4DC04890876EB70ULL, 
            0x2B16603BF74B8E8EULL, 0x980996460B35398CULL, 0xD8066232E854FEC5ULL, 0x6A9A4A77AE3D1D18ULL
        },
        {
            0x0503E9F2A23F2B25ULL, 0xF57210EB386E2F75ULL, 0xC77E53DC894E6DBDULL, 0x4507F59DD7732742ULL, 
            0x11A07585D9B1EAC9ULL, 0xE218D62BB0AA4030ULL, 0x1B6CC572B95E0A9CULL, 0x18139196C7119A03ULL, 
            0xA8EF3E51E647F48CULL, 0x44026728EC39D1D4ULL, 0xD8DF56E959D3D2FCULL, 0x5DDE8A54C53C0BB6ULL, 
            0x501F1CCA76AF31E6ULL, 0x95D35E6E7293F4DFULL, 0x960A312C515C66F6ULL, 0x6A70F28445569868ULL, 
            0x78471A00DED20BB3ULL, 0x87EFF0DB4A89D3B5ULL, 0x9555A7F7291932C6ULL, 0x28E18131E1D24F01ULL, 
            0x929792E7FCC1CF0FULL, 0x4EFFFD0AD76909A2ULL, 0x90422D4DD0E07C59ULL, 0x322187D647A362A5ULL, 
            0x3208CABC4F659E71ULL, 0x10FAE931FC7F382FULL, 0xE645EAF217C225C0ULL, 0xB3F40862D1BC8CE9ULL, 
            0x6A410C165DFA9DF0ULL, 0x181723800F7060D3ULL, 0x98C925AB3081D34CULL, 0x328B5003F3318F5DULL
        },
        {
            0xDE5CF5D7C4CD6F2CULL, 0xBF8EB4F650934A5BULL, 0x72DA6D94C4A25D73ULL, 0x6747C1EBCDD039E7ULL, 
            0xE9621F35F984BE5FULL, 0xD15E787306091776ULL, 0xDF30C1C6B0127615ULL, 0x2119112F1495E0E4ULL, 
            0x1E133D7326B6AC52ULL, 0x77C9924694CE2AA5ULL, 0x8E0CC880CC111E96ULL, 0xB8453787282F23DBULL, 
            0xFD75BFD0198912D8ULL, 0xBA3726223DA95964ULL, 0xD80622E65EB3FB8CULL, 0xE3BC9278C09B38A5ULL, 
            0xE35DB84E21F8DBC4ULL, 0xAC987FA92A8D70BEULL, 0xD4B0B87A2702A7B7ULL, 0x25BA8A9BA5869A5CULL, 
            0x55E1BCB2943CD74EULL, 0x221240C33E5B6F26ULL, 0xB698B0289AF949ADULL, 0x7819B6C3C2621E0EULL, 
            0x70617C2C38130C4EULL, 0x4E96B31CD6159077ULL, 0xD5E99CE0066971B2ULL, 0x8654699F371C6B28ULL, 
            0x87F4FC1C15B14F79ULL, 0x55E52C6456FE3AF7ULL, 0xE223B09FDFB1459CULL, 0xAFEBE8387DF151BAULL
        },
        {
            0x4FB72350E5872D9FULL, 0x27375CAD2203A80CULL, 0xA8D3A9E90EB0E7F5ULL, 0x9B15B30EC5033B36ULL, 
            0x9399D67771012759ULL, 0xEA4FE83014877164ULL, 0x549D5383025CBB65ULL, 0xC39E55EC355ADC8EULL, 
            0xA1C50BADE7149B2EULL, 0xBEC020FD125C8E56ULL, 0x2985D0A43D9D0BCDULL, 0xA4486BF8E5B91F4BULL, 
            0xAE545BD9E9B3E263ULL, 0x6AF75EDBB26EF990ULL, 0x8BFBD32E1A0A959EULL, 0xBE74B2E47D29271FULL, 
            0xAB769B6AAD66183BULL, 0x2D15CCB20A32666DULL, 0xCC1897C50CF50009ULL, 0x15A7D9A11F5595E4ULL, 
            0x58AE3437308019DFULL, 0x3D42F8118B820D50ULL, 0x4CF61EE2B443B69FULL, 0xF846BF1566A0D95AULL, 
            0x629BF01DC5967F4CULL, 0x31AFE7DE648899A8ULL, 0x30DC7BDDDBDBC06DULL, 0xB94099286244DF80ULL, 
            0x7153C6E0D7CA204CULL, 0x7B73227503D340CCULL, 0x77BD5483DAA05DB9ULL, 0xB2F7F0A78B313DDEULL
        }
    },
    {
        {
            0xE250B0EE1AE6B0D3ULL, 0x0C168DC97F2D7212ULL, 0x0E3F0BD6068BB2EFULL, 0x1F335BAA7E322872ULL, 
            0x6AE2931D1C12B14DULL, 0x5FA0734AD52D26EBULL, 0xACEF15D374B2DD2DULL, 0x167D89E28DB3FD34ULL, 
            0x38158712194E42F3ULL, 0x229038463C86CDABULL, 0xFAEF94B625328C6AULL, 0x9ECDD4B6129A2730ULL, 
            0xF8A1F45851775BB3ULL, 0x29423A26F5641BC9ULL, 0x2F06F4C94BFA7913ULL, 0x9F06992E64E89363ULL, 
            0x29E7E7A028BB4311ULL, 0xEA0746BAEA98AFE0ULL, 0x98A1891F58531742ULL, 0x3618E8D66572DD54ULL, 
            0x10F3E4E254C31346ULL, 0x04D0FBB5A0D3977BULL, 0x526DBF14DFF89C5AULL, 0x8405B78FF00687E4ULL, 
            0xE70FAE0D584DDF07ULL, 0xBF4CFF32FCD8F9ADULL, 0xBB9C5296ED8A3829ULL, 0x1E256FDA73A74B0DULL, 
            0xF4D026678586DF83ULL, 0x5D43530616D58495ULL, 0x98C7B3D58F91C865ULL, 0xC7F26B618D23209CULL
        },
        {
            0x98783CF7625CDF9EULL, 0x890BCA78CDFCAE95ULL, 0xB9F08E642BFCCD01ULL, 0x8085B3F8CBAAB1C5ULL, 
            0x91B562725E63195DULL, 0xB86B2ECE959683B7ULL, 0xA72C428322BE4AB1ULL, 0x80686C4BAFC3D825ULL, 
            0x771C6C12F7E86574ULL, 0xF7D640C4E977B246ULL, 0x633DB5ACA6135397ULL, 0x5F2BA59777CA73D5ULL, 
            0x9CE5EC11118DBC97ULL, 0xFE4311492DA087BEULL, 0xEA7206E016396EA4ULL, 0xB0289BBEA584C144ULL, 
            0x1A58EA1661D670AFULL, 0x1DAE91FF7AFD6BF3ULL, 0xE4D5B9BBFEF4A7E1ULL, 0xE2002905308AE286ULL, 
            0x92101C14FEA54351ULL, 0x8C77B300A5712570ULL, 0x0176D415C49AB7D4ULL, 0xCE797A69CADB3962ULL, 
            0x2C7CC3D0466794DFULL, 0x8234A103569578DDULL, 0x0A323B5976E99409ULL, 0xEAC832F782DBA4A0ULL, 
            0xF2B548C8E302425BULL, 0x9A8110B5F65EAF84ULL, 0xCCB09F85D7854FACULL, 0x2D88A52A9460EF85ULL
        },
        {
            0x46AEEE96CD89491FULL, 0x397D2F524A00C34DULL, 0x3B6BB7A89096C714ULL, 0x64A89E7B9731D10BULL, 
            0xACD47FBBBC8FDB0BULL, 0xA606CE0B1EC47366ULL, 0xA404C58AE0206BD0ULL, 0x3D39F30C4EC5FF17ULL, 
            0x086CAE04F181B88CULL, 0xDB3A9790E9AF0C8FULL, 0x1FD19DA05F1E4381ULL, 0x9DBF8B7303B3F628ULL, 
            0xFD96C334F938A0ADULL, 0x23AC8032730FCC61ULL, 0x684D7FE3B5B17F96ULL, 0xFBFC0F35289FE68CULL, 
            0xD0D7BB16E18252DDULL, 0xDA3B037B114EFCA7ULL, 0xEE55E2FAD9DD807DULL, 0x6643B6A7F2AFF5BBULL, 
            0xC2217E7F4F270498ULL, 0x2F83815508346924ULL, 0x9E3263FCF1676B7AULL, 0x30AEA7A5A69BCB99ULL, 
            0x40142B48A38945C4ULL, 0x76A4D4242439B215ULL, 0x8DD567537894EEE3ULL, 0x7B18CA9C7D243288ULL, 
            0x0E82048846CA1C59ULL, 0xA1EC7D46C81692F6ULL, 0xAE86CA04D7D06CCAULL, 0xAA94E17246ABFD42ULL
        },
        {
            0x654733C5EF136AFEULL, 0x3BDDE0A1602DD270ULL, 0x422E65DA15B17E46ULL, 0x1C4BA3692C0C55ADULL, 
            0xFD992D394963A565ULL, 0x4D68DEED71CB236AULL, 0x9E52B517482EFD64ULL, 0x92E53145ACFED00BULL, 
            0xFA8A04A1F4BBBF06ULL, 0xEC19EA19F2A3077DULL, 0x37AD96F8B150793CULL, 0xFA97F03D2F191ADBULL, 
            0xE69E9EFA5BB36029ULL, 0x72E432F53FB17408ULL, 0xCC9847E527691DBBULL, 0xE6CC27069D989FBCULL, 
            0x8BDA74699C0A39BAULL, 0xCD1DE89C7BF82AFBULL, 0x54BC18B0FF8A9D79ULL, 0xCA649BBDA8063AAEULL, 
            0xA421756FBA056C83ULL, 0x1DDCE132F77514C3ULL, 0x8CEE14CB787D539DULL, 0xF4F0A8CA7AC260AFULL, 
            0x62640F5EB28C383EULL, 0xC5232C29A886577EULL, 0x3BC67826DB47CFFFULL, 0xA57CB142F45711EEULL, 
            0xC786C6C3F2D9BA70ULL, 0x2B1150CAE893AA70ULL, 0x6B9A6B4DB97771AEULL, 0xC10397E2E88B2B3CULL
        },
        {
            0x72EF2AB84DF0EB17ULL, 0xB5572EDFE23FF1A5ULL, 0xE36B1B5DB5ABC57DULL, 0x382B3C68E556873BULL, 
            0x9C15216F064AA5A7ULL, 0xE0A2027996F0798CULL, 0x70E9BCCAEC426257ULL, 0x37878144FB23A693ULL, 
            0xE6A7D7AFFA354D56ULL, 0x92F328E94C908DF2ULL, 0x1772434E275266E1ULL, 0x00B4C6E1BCB108C5ULL, 
            0x781D6061E765CA84ULL, 0xF55A80203163EF07ULL, 0x063418BC05871917ULL, 0x5A8EF5C6A3007D73ULL, 
            0x91C06B0A3660DF8DULL, 0x18158FD8CF64BEF7ULL, 0x4FC13F2605BD111AULL, 0x523573BA4816352AULL, 
            0x4DF29A0AD0DCF8F9ULL, 0x3ADF405E9A43BFE9ULL, 0x76A0A78EB197B4A9ULL, 0xADAFCF07B1ADD8F2ULL, 
            0x53B9B7255F01C361ULL, 0x8B1E2C89056D59DCULL, 0x733C773520C48F28ULL, 0x3AD526C43CCAD89BULL, 
            0xBE258DCD90A0C746ULL, 0xA602773386CAA8DFULL, 0xB7A6B6937BF4B0D4ULL, 0xCB139C9C3C628BADULL
        },
        {
            0x48EEC3AE91B0F3BBULL, 0x88172C47A9260137ULL, 0x4A510B6422A85415ULL, 0xDB0F2C29FD7E5544ULL, 
            0x75CBD087CACCF8C2ULL, 0x73C2069622527954ULL, 0xFBABE5FCC0BF323CULL, 0xC5D28495CD6F5FE1ULL, 
            0x24BECA70B9F3EC5AULL, 0x832B05DBABDD53CEULL, 0x35F09C3C8D6B7AF2ULL, 0x6F8C072563CE6781ULL, 
            0xB43FBF750500BA66ULL, 0xBF863D3D9885FE0DULL, 0x766E0B7736F8DB88ULL, 0xD4C15AA1661C5F05ULL, 
            0x4D5E022FEA58F8FCULL, 0xC07478D309409DA5ULL, 0x374BB8BEDBC87D9DULL, 0x09C65C219B08521EULL, 
            0xBA9E78B549C9E14FULL, 0xECF88B179E749F13ULL, 0x775EB626610E496DULL, 0x9FA06649024E03F9ULL, 
            0xD3AACC38BC263535ULL, 0x4C5D12023CECA9AAULL, 0xDA61E4ED02279EFEULL, 0xD9E5D825377392E4ULL, 
            0xF11933E73F600FADULL, 0x6AA4329808B97EB8ULL, 0x6B73E8ED2C9F8334ULL, 0xC169FDA753BF76B9ULL
        }
    },
    {
        {
            0x0E74CF89E3120483ULL, 0x4888A95606A18817ULL, 0xD25CE4BA2A0E9688ULL, 0x238D10780BD329D0ULL, 
            0x6BD286848FD89AFBULL, 0x444D88107F0D7F96ULL, 0x7DB3E6C5381272EFULL, 0xFAAE168D5DB7E332ULL, 
            0xC24D5EF40349271EULL, 0x6A843DCFD15606A1ULL, 0x1422C1690F4B1033ULL, 0x2B2552E6492D77BCULL, 
            0x78895179904307C1ULL, 0x66B9D4DBCC504690ULL, 0x1E5414448A409CE1ULL, 0xA51C73DDD5681DD0ULL, 
            0x0E88BFC695B4F1BEULL, 0xDA071DD4AA1332D3ULL, 0xB4AEF03F16DE23C2ULL, 0xEB8D8EDC48CDFDABULL, 
            0x010DD835B84E498EULL, 0xDC168D3344359F93ULL, 0xED06CDA772BE3494ULL, 0x5989CE1B84A05E51ULL, 
            0x065B917A6411A316ULL, 0xCB8AD98B17E590A7ULL, 0xA7209E74043B1A39ULL, 0x84C5553F615582A4ULL, 
            0x4B1C225048A30C5AULL, 0x75E9AB0C31B9B7E7ULL, 0x16A1BD5D04883B16ULL, 0xFC4D3544FC74AD9AULL
        },
        {
            0x8618B87D97656276ULL, 0x6F65C60B7FDD2D06ULL, 0xE883FD7BF20413AFULL, 0xD1E313839276A35EULL, 
            0x3CBD68CB861E4C29ULL, 0x0BDDD29CB94EB5A2ULL, 0x3617355856002E35ULL, 0x16D5E8909675D11CULL, 
            0xBD901B2AEA567A42ULL, 0xA75A438FEA40074EULL, 0xC242B0423A52CDBEULL, 0x630E759A6B36C322ULL, 
            0xF0AB4FFEDA327CD9ULL, 0xD048CEC4B13E57DEULL, 0x61D312D5BF997E34ULL, 0x02B3C10D315EF340ULL, 
            0xE70ECE55795A667AULL, 0xD8E22C806D70425AULL, 0xCBFBFD8E5AC57FA9ULL, 0x0B920C49FB55202DULL, 
            0x5F8B7AFF411658BCULL, 0xD8920CDB8FCE59EEULL, 0x9A665509E7A73F07ULL, 0x1CEA2457FA803807ULL, 
            0x96A5FA31AB36F455ULL, 0x501BA62ACE26A6B8ULL, 0x6E106470786EA7C0ULL, 0xEE35617CB035F788ULL, 
            0xDBEC8C2CB485B803ULL, 0xCBBB3EB16748B5A6ULL, 0xC13CAC63AAE8816BULL, 0x707AB0D11FE2C061ULL
        },
        {
            0x0204125F445F3692ULL, 0xABAF060BBF96F3BDULL, 0x5143748393F87305ULL, 0x9AB40923FC96F14EULL, 
            0x99BD8B672A3D5513ULL, 0x8D4B19F2117B3485ULL, 0xDD002A1A09516E5EULL, 0x0BCF83E66CDAA7F0ULL, 
            0x61D8A495F7A491B4ULL, 0x95AB6AE563602AB5ULL, 0xBDCBC765A17353F9ULL, 0xF1FDDBDC03A20783ULL, 
            0xD9AB6923AADE6E66ULL, 0xEC2DD49E2F4E674DULL, 0x81B0C5B5F53E8973ULL, 0x32B50E724AE563DAULL, 
            0x135BACDAD5100DE9ULL, 0xAC2AA57EF255BDCFULL, 0xB245BBA278EC8BE5ULL, 0xB365081352A44117ULL, 
            0xE4AA5999AA29BE12ULL, 0xB48F615B36B82A73ULL, 0x267A5F46EC3B6CF5ULL, 0xF1D0680DFC4B48B5ULL, 
            0x17A1E4406F07CB1DULL, 0x46FBBBC4E15BD446ULL, 0x9791533C39BA7E50ULL, 0xC725A23E6AACB77CULL, 
            0xE0B80DFB80860026ULL, 0x1E9B99512DD65AC7ULL, 0x3E3F04345003CC02ULL, 0x66227A48ABE33565ULL
        },
        {
            0x5B7C28C2B0F613F5ULL, 0x16B04B8A6E00EF2FULL, 0x5EEA7F53417AAF5BULL, 0xA422A725ED5AEB79ULL, 
            0x4724920F538A2D10ULL, 0xD537D50B6A016674ULL, 0xF257F5B5467E565FULL, 0x1EC419AE5144E080ULL, 
            0x1AF2CBB349BE0E04ULL, 0x44975A1A55C50321ULL, 0xFC7D3980335D69DEULL, 0x9DA6C0D2D34FF4EDULL, 
            0x7AB918BA163C78F3ULL, 0xE0AB86A311EB9953ULL, 0xCC41733C4543D1D7ULL, 0x4A51AB0E19464182ULL, 
            0x5FED19F9A38BC40CULL, 0x6624AF76680C2745ULL, 0xE0801CDDBB14E418ULL, 0x72A0B4B09B94EA23ULL, 
            0x1196458CC4019892ULL, 0x7020592FAE1DBBA9ULL, 0xF9AA9284F5864EA2ULL, 0xF37AFAE3044EF0AAULL, 
            0x7EA1888B4E5A1E25ULL, 0xF4FD68269615FC28ULL, 0x5BCD995F9F7F39C3ULL, 0x762D0FEEE9BC71A3ULL, 
            0x69A00157B56739D3ULL, 0x6E7DAF95F7FAE945ULL, 0x7665474881706AEAULL, 0xFCC3D9A7D8CFCD4CULL
        },
        {
            0xB41E79DB664BE670ULL, 0xE72224956277EF4CULL, 0x63A40765234DC04CULL, 0xD23DCED96A978546ULL, 
            0xF5B3BE37C47F0060ULL, 0xF1CB5C2604377A44ULL, 0xF7694DE7136C36EBULL, 0x78002AB2010044D8ULL, 
            0xCAD9FB79A2B6A7A7ULL, 0x2725115D23B66351ULL, 0xB683B5CC9010ABD7ULL, 0xA890A81CF33D4A67ULL, 
            0xFEAF588FA9DF0238ULL, 0x63A7F728F53DE9F7ULL, 0xD5F3D44874FB4402ULL, 0xA9F2675D99DCAD1AULL, 
            0x1A24D8DDD7F34F24ULL, 0xDC149213660EB88BULL, 0x4021060DC02042F2ULL, 0x91AB7F36DC8A3ED0ULL, 
            0x2D6E14140C4CB4D1ULL, 0x495BE9B08D9FFFC9ULL, 0x1398F98167EC1FD6ULL, 0x6BF70F3F5DCB58ACULL, 
            0x9318853B88722FF3ULL, 0xD4B1DC772A7553C9ULL, 0x2CDF46B3AA5056CEULL, 0x290BCED56C7785D7ULL, 
            0x156DDD75BD76E5CFULL, 0x3732B046B6315F0DULL, 0xC48F5F60DF48135FULL, 0x50DFDAA83AE74F2AULL
        },
        {
            0x633632BD93E0BDC6ULL, 0xDC87700AE443B5AEULL, 0x2BD089AC905917EFULL, 0x46C9248681FAFE7FULL, 
            0xB2BEA4AA2D8F0853ULL, 0x100B66B724963D07ULL, 0x70451EF3FD4744E0ULL, 0x9481A8521B714140ULL, 
            0xC43D625B5FCD74FCULL, 0x0DBAE225A33F080EULL, 0x85CC00D1EBF845BAULL, 0x57C95D440694FEB4ULL, 
            0xC7B07BA3DC0A38E8ULL, 0x50241E521A6DFD64ULL, 0xBAC747E7EA50B271ULL, 0xFCB016ADE3DE18E9ULL, 
            0x47D2BB17DE7737C4ULL, 0x5C897068675E72C4ULL, 0x071A790DCD66FFD7ULL, 0xDCDF0872EF5C3192ULL, 
            0x99B0B3E9F3FAC2A5ULL, 0x0C3B4292DCB114F7ULL, 0x62BCBBB27AD272A1ULL, 0x5735DEA47DB297D1ULL, 
            0x8C91B1D83716ACE8ULL, 0xA7A66F5520ED0821ULL, 0xA4C3EB8B82863806ULL, 0x8CD0F5B4B4A62A4AULL, 
            0xBC114F972D5EED85ULL, 0x646244A76BD4D801ULL, 0xF3B9498C3A7BC26CULL, 0xC22DC53AF39E224AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Altair::kKeySpawnAConstants = {
    0x2EE9B6B4653FB464ULL,
    0xA182BAB93ACF5F89ULL,
    0xA2A5263B667118D6ULL,
    0x2EE9B6B4653FB464ULL,
    0xA182BAB93ACF5F89ULL,
    0xA2A5263B667118D6ULL,
    0x38CC8DC6A4457E33ULL,
    0x2E051B2947C1C24DULL,
    0xF8,
    0x17,
    0xAE,
    0x2F,
    0xB1,
    0xD0,
    0x6A,
    0xDA
};

const TwistDomainSaltSet TwistExpander_Altair::kKeySpawnBSalts = {
    {
        {
            0xE78686A0BC688C72ULL, 0x37463501B4E48FBBULL, 0xCEAA2D823DCA9D94ULL, 0x221E21AE2F91641FULL, 
            0x5C124FCF7AAA5744ULL, 0x827AFC0C93BC47C6ULL, 0x1A3081F9EF5D88F5ULL, 0x89911CEA02C74A2CULL, 
            0xA05F88722EB5A496ULL, 0x4384131B35EC1FBAULL, 0x2F53AFE7AFFFC6A6ULL, 0x70B63515081A853DULL, 
            0x81BC777EE6F9B75AULL, 0xD1A96BB66304E754ULL, 0xF4B12E72D6E2AFB9ULL, 0x2AE9CE521CA2D3BEULL, 
            0xC9841ACBB4D52B7DULL, 0x00083927EBDECA2CULL, 0x60CAD66594B7B453ULL, 0x6210ED5CB8AFAEC1ULL, 
            0x209BD0C63F5C4826ULL, 0xD2891DA1626BF937ULL, 0xE1142D30BFB736C6ULL, 0x06B34553A5E89C94ULL, 
            0x383BDE19559CEB93ULL, 0xDD5685B530DD4271ULL, 0x7FF2479E8FC0A045ULL, 0x6AA8872142D89EC1ULL, 
            0xB0A1D9FDFB2754B3ULL, 0xA43DEE92D5D36CA7ULL, 0x7AB14A2110A9D4F7ULL, 0x8EA22512178DB7F9ULL
        },
        {
            0x731D0F3C3383BE15ULL, 0x553666B9F5391D3AULL, 0xAB260C2BF1C40279ULL, 0x5DCCDD5C0C080FC6ULL, 
            0x8C07D185BC90B8EAULL, 0x95B07DCC51085E13ULL, 0x04C34EA276571F46ULL, 0x1CC928FF039944A6ULL, 
            0xD33520802DB61BB8ULL, 0x80949056CBE819FEULL, 0x57819FFC861984F9ULL, 0x5601830F95F2FD15ULL, 
            0x24DDE5B16FC87D2CULL, 0xD38817AF09ED495EULL, 0x8737AD9E1F75ABF0ULL, 0x41985E0C0F7B2CF8ULL, 
            0xBF37567506E014B0ULL, 0x7EBB3BBCF51E5F38ULL, 0xAEEDFE958E0F6E57ULL, 0x380196910C223B20ULL, 
            0xFB7A060CEE9A0E1EULL, 0x2D10DD756717A2F6ULL, 0xF886FC5FD6B65EE1ULL, 0x4CC5B02BD4B7DC64ULL, 
            0xE96565B9335F02F4ULL, 0x78BCDEE579A61063ULL, 0x2F99042692C8F864ULL, 0xBC6BB7EBD095D128ULL, 
            0x83212C0323B34F28ULL, 0x466BCF0E095EDE40ULL, 0x36EB7A3DE3198A84ULL, 0x0CB81EE68FFACF81ULL
        },
        {
            0x4C5504E9B4F78EDEULL, 0xB0B8D5AC65A98887ULL, 0xC5B239CE7B1C100FULL, 0x6E90A5005D8943F9ULL, 
            0xBD384857B1979C14ULL, 0xBF7716F344E48116ULL, 0x179847A0AF62A7DCULL, 0x7BC69D072538A552ULL, 
            0x37F170F352ADB121ULL, 0xF408E358A89699C5ULL, 0xCFD6FB772E86C44CULL, 0x4E233A240344ED74ULL, 
            0xB88F9DC6495188D0ULL, 0x643F49C69F46D460ULL, 0xEE7041B7A3890211ULL, 0x7C26EEB34127974AULL, 
            0x91E5610FB3246808ULL, 0xFFFAF2170C1D6D4BULL, 0xB7690FCBE445D78EULL, 0x79713F381E9BD2E3ULL, 
            0xFCC7AF2BA0AB9A24ULL, 0x8B19622BCCB39FBEULL, 0x482C48A35DE5EB0EULL, 0x0D05244ED6AC1895ULL, 
            0x15AEF352450EEE18ULL, 0xD8CB804A453C8337ULL, 0x7A5E706DA239A3E9ULL, 0x2D8EE5293495D753ULL, 
            0x7A332B523DA26B72ULL, 0x6FAE6220DBE5A690ULL, 0x45478CF1089EF5E5ULL, 0x910D5C7AA71B25B5ULL
        },
        {
            0x955EBB9801FD9EF6ULL, 0x006714E25102F77DULL, 0xBEAF42EAAB4DFB0DULL, 0xCAD2CA2A47A0C66CULL, 
            0x9E4FD372BA0C3068ULL, 0x82D5FB10C8664AB0ULL, 0x8A1E311CAF534C33ULL, 0xE525BD2BD6F2B588ULL, 
            0x143D64097A58F77AULL, 0x98617D624C231418ULL, 0x585EE648E24912F5ULL, 0x909109189397FFA5ULL, 
            0x5F38235778484362ULL, 0x603C1A2FCC3F131FULL, 0x6E0DDDAA6F4A038EULL, 0xC3658A3FABBE5B9BULL, 
            0x37BE4A49EF861135ULL, 0xC61CD5DC6565D266ULL, 0x7DEA3FB365D26D19ULL, 0xCAAB688469D03CE8ULL, 
            0x4F8B579E51FAB9EFULL, 0x71906BCACBBD5003ULL, 0x127B2BFC718E1FF9ULL, 0xD2DABD8DBB083AA7ULL, 
            0xCAA638D7E964DD6BULL, 0x46D61A05DEAF4D91ULL, 0xEFE212823C89682AULL, 0xFBC29A1DF0A30F6DULL, 
            0x7B901513A6E5B024ULL, 0xDF72F9834A984E93ULL, 0x3573BBB662FD9882ULL, 0xAC52B507C88732C8ULL
        },
        {
            0x93363FCF5956E9C2ULL, 0xA8D117BDA3114218ULL, 0xD6269830B66F6A49ULL, 0x56F62981AEF48FDAULL, 
            0x38247C2EC105202AULL, 0x82C321671797244EULL, 0x4EF0C5836F271DECULL, 0x7AF077797B5E5786ULL, 
            0xEB6F8D06DF8F8F49ULL, 0x376BB877BA1EF4EDULL, 0x07CC3D323C232FD7ULL, 0x19E0A2380229F65DULL, 
            0xA476D9E46DB771D8ULL, 0x0AECD30EA0C4C050ULL, 0xCC32B96BF4ED901FULL, 0x048B315E2D43E7E7ULL, 
            0x76238C674F73B522ULL, 0x31B65C46EAF879BAULL, 0xEAA590E09C440644ULL, 0x202069276AF15439ULL, 
            0x706746DAC93CDB3FULL, 0xD235192084A2D476ULL, 0x332F81FA78DE69B2ULL, 0xD0D1446E6440B429ULL, 
            0xBD31C30154E910F6ULL, 0x34A2D058176DA903ULL, 0x6C17EC031D0EC990ULL, 0x3AEA2FB28DAD7322ULL, 
            0xB05C766CEAA1208CULL, 0x804CADCFA73896E6ULL, 0x6F0A9543C6AD3298ULL, 0xECA1E4B13CDAE518ULL
        },
        {
            0x3346291B65A2679CULL, 0xC74C4E4FB7CCDCEEULL, 0x7D921E644485B965ULL, 0xBA59484BCB97C3CCULL, 
            0x438C5C5705EE80F1ULL, 0xB84DCC73CF59C867ULL, 0xCA6F725472F005B0ULL, 0x9AB13619E15152DFULL, 
            0x8CD3C2F443F41298ULL, 0x8072CA9E18FF62DCULL, 0x5E959E811BC6F3D1ULL, 0x57B3DA720DD01DCFULL, 
            0xDE4B7A3DEED56246ULL, 0x7B75264D5744A3DFULL, 0x1218949ABA1CD930ULL, 0x0A1F5177EA1B53EFULL, 
            0xF0D107A7B85BF490ULL, 0x1197E84BC1A0A816ULL, 0xC388994D7F66A75CULL, 0xD90CB2A949F4F609ULL, 
            0xC0B367F901B0E157ULL, 0xB240F6391BFA2B24ULL, 0xD78FDE29AB6011B9ULL, 0xBCB5F2E3170525D9ULL, 
            0x4BEDDDAC52692DC7ULL, 0x5EE51C2D897678BBULL, 0x5B71CE274758869AULL, 0x67FCDC78523ABD18ULL, 
            0x234F398565FAF8E7ULL, 0x3B9A6266B6959AA5ULL, 0x261950B9B348613EULL, 0x922F17ED164069B4ULL
        }
    },
    {
        {
            0xBCED8030FD2F5EE1ULL, 0xC0A093CCD8C807BFULL, 0xC2418C1F7CCB163DULL, 0x0A45373B56715DA6ULL, 
            0x9E89A2C52B68533CULL, 0xA2BB1B81F349433AULL, 0x9096F5D071EE845FULL, 0x15C5E436568B6352ULL, 
            0x5835231DED4F499AULL, 0x994594F51123A377ULL, 0x44EAC5BF3523050BULL, 0xA895052887AF7950ULL, 
            0xB471519ABC817A9CULL, 0x1A098B5792727342ULL, 0x888070DD39BA4249ULL, 0x77F027D4347AB9C8ULL, 
            0x51C3CC0FDC653517ULL, 0x1FF8604CE54C4AC3ULL, 0xD05D2858487FE810ULL, 0xD573B090E0E4B36CULL, 
            0xF8CE8205213602FBULL, 0x779F5EF819425025ULL, 0x2019B972D691A764ULL, 0xBA3A8B13C59D64E7ULL, 
            0xBE11800EF3A84895ULL, 0x4290DB80CE79CE8AULL, 0x3488766F20722C9EULL, 0x0899FD1079D100E2ULL, 
            0x0B28704004F50128ULL, 0xD0AE7948A2400553ULL, 0xA477FC7A3946DFF2ULL, 0x817A800CA843278CULL
        },
        {
            0xA893A9F1332A31A1ULL, 0x4B125923BA673A6AULL, 0x6A8A660B89CA7C54ULL, 0x51C357CFFCB79EDAULL, 
            0x30737B1795FBBE7FULL, 0x75C1C7CA2AED958FULL, 0xB8212DA66C2EE466ULL, 0x85E101FB77B81E5DULL, 
            0xAC4267729BDE4CBAULL, 0x233622D120618F4BULL, 0x66EF94284049A0BBULL, 0x946AA9CE3C690870ULL, 
            0x2B83DEA8252246C9ULL, 0x2E4FCEC3B139F034ULL, 0x764B2EE0BD048667ULL, 0x45CB9174F3D8A4C1ULL, 
            0x2CFFE265619A9846ULL, 0x08226034AF9F88A3ULL, 0xC261114829871406ULL, 0x120DF59F10535E0CULL, 
            0x54B45A831CDE2B8BULL, 0xA0E1C0585F63F350ULL, 0x1F3F29370FB4897BULL, 0xA4BE285AAD9143D6ULL, 
            0xADF2FC6B5E019634ULL, 0xF605EB951F81483AULL, 0xA47547493CB66E81ULL, 0x190F4F1EA07FC0B2ULL, 
            0xD11212F6090740EDULL, 0x62C62B1A2BB4D9F7ULL, 0x5BA82A94DCD12754ULL, 0xCE4FBBE11BB90370ULL
        },
        {
            0x54FFADE3F17A2F1FULL, 0x60EC3400FFE8E6C5ULL, 0xBE9C2C83F66B706DULL, 0xC33DBD6121202C98ULL, 
            0x965CD0A0E14DE1BEULL, 0x6B27480CB7A36539ULL, 0xEA5D2BF0EE59D01FULL, 0x8D483EB6168447C0ULL, 
            0x9F5DDFFF51BFC33AULL, 0xDAEA5C6B1FAA8FBFULL, 0x5BF4A5A384B60D47ULL, 0xE6BE0E381001E04AULL, 
            0xCF654B502421F77CULL, 0x1FB36BEFA264D037ULL, 0xE528647DD530231DULL, 0xE970950054A29521ULL, 
            0x7E34434631F0124FULL, 0x8B6B2F16583E7485ULL, 0x07C7C4CAE55F7A58ULL, 0x5C8E3581A053CAB1ULL, 
            0xDB131DBBEAC5564FULL, 0x0B606D9369CC572EULL, 0xFA429B1C1C2FFEBBULL, 0x2923A6E44148942AULL, 
            0x88EEE579ADCE3CC6ULL, 0xCB5B0E5D0B2EBE41ULL, 0xD8AE1DF269E20785ULL, 0x2D9A2FF61A62A819ULL, 
            0xE5F51B64B32DE77CULL, 0x39FC64048595C58AULL, 0x540B7782C2F8F26BULL, 0x86BA8C10219AFE66ULL
        },
        {
            0xF834BF8CA38546C9ULL, 0x5716263797078EB6ULL, 0x70977B01D42CE331ULL, 0xE4990F5084771827ULL, 
            0x04490C98C4AFC12CULL, 0x10C452FA18CD7AFEULL, 0x4F03A305689C0A96ULL, 0xB243447AA3637FDCULL, 
            0x3E55956B711F2652ULL, 0xEEECC12B57CBF0C6ULL, 0x5F64F505C2B0E1FCULL, 0x78403B1F1717BE2AULL, 
            0x0C70B4A9143E622FULL, 0xC023028F37FE0AC8ULL, 0x28753A0617F87971ULL, 0xB6C05D5416EC8744ULL, 
            0x94F1AEC9E61C6D48ULL, 0x8435E29F2AF33957ULL, 0xF506FEE7C99B4868ULL, 0x00699F08533EFD04ULL, 
            0x87C4BB018D776764ULL, 0x799B1EB18B5F4462ULL, 0xBF82FB5A5F046F06ULL, 0xF59B603B1C6D29F7ULL, 
            0x2DB76CC89C8B0F31ULL, 0xD06690F54A1AF188ULL, 0xBC3F4B3B929E012DULL, 0x782E58D6CCAC6C97ULL, 
            0x214C7415144F2A48ULL, 0x6D48485DC37B3AF3ULL, 0x3CC61D375E96C460ULL, 0xF176D888DF39F16EULL
        },
        {
            0x8E8F03E5DAEA9F08ULL, 0x523C4611BE68A06EULL, 0x8A5828ADC1FBF3BFULL, 0x8265A6A710B28461ULL, 
            0x1F7A706538E3E23AULL, 0xDE8EF3C3C06B0179ULL, 0xAA837FF567231CA0ULL, 0x7C36C9793CFF827FULL, 
            0x860FBD4425F0DE93ULL, 0x660F98E7CE893A21ULL, 0x5EDE9DBF2D14901CULL, 0x8E5C00B5339FF146ULL, 
            0xBAA2813DBEF74C77ULL, 0x81E4D4774912FAB8ULL, 0x50D65BA5A6CCAB90ULL, 0x812BDBE7616EC8C4ULL, 
            0x0895EF4B52C62694ULL, 0xE8E33195BB925461ULL, 0xC42C2D8779F9689FULL, 0xB10C2E4381FDD70AULL, 
            0x58743E07FEBC2A4EULL, 0x24F89AC02FACCB3DULL, 0x42464A257C91A7BBULL, 0xAC09E3181D8896E5ULL, 
            0x12499005C681A48AULL, 0xEF9BE62D60C5A13BULL, 0x6A18821243790CFBULL, 0xBF4970B929B7B9EAULL, 
            0x0322561FA61D88DBULL, 0x7219E55E43A125CEULL, 0xDF9796589B40CECDULL, 0xB09361AB6C521CA5ULL
        },
        {
            0x513498A33C731452ULL, 0x5AAC661C6A5BB31FULL, 0x5FAC6CA542AC835FULL, 0x87DEA6A29CBAA7A3ULL, 
            0x372F86118AFB2678ULL, 0x85CDB4DFCF1EA898ULL, 0xA5B320123120EAE8ULL, 0x1D6B772C339357F5ULL, 
            0x16F804EFCFB21196ULL, 0x8BD997CE11E8F63DULL, 0xB573AEA5CABCE717ULL, 0x732F1CCA03797866ULL, 
            0x3198D902285359ADULL, 0x8FED4892CF926018ULL, 0xD31B90F4B2B2A028ULL, 0x74F174DF7D02BC97ULL, 
            0x8DD936C1BAE482CBULL, 0x5F35973D5C93A580ULL, 0x31D1E3DD01A1EE28ULL, 0x95FE966E8571F592ULL, 
            0xEE8CBD47C94257D5ULL, 0x1B1169F97BFF1340ULL, 0x57DB0391DE1BC6D6ULL, 0x1E0E0D2787B0D8BDULL, 
            0x9746ED43697ED302ULL, 0x47DA6AF2E3B0DBBEULL, 0xD4DF0178571FBA77ULL, 0x622643ED5AAC65AFULL, 
            0x6CB340ABA8B62BCAULL, 0x19E3D282B0931D33ULL, 0x6AA7C9311F9AD6E4ULL, 0x02EAD15DCB3AA0F0ULL
        }
    },
    {
        {
            0xF9D56F94B23CB189ULL, 0x426F05FFC18DE536ULL, 0xDDB2F6F260DE36BDULL, 0xC7053D4C192F44D4ULL, 
            0xFB65CFE823C3ADC8ULL, 0x92BF0E348690BCDCULL, 0x27B3B592E1360483ULL, 0xE5BD7FD4F3372C70ULL, 
            0xE6E28FA675F40233ULL, 0xC421273AAB8A56A9ULL, 0x71FFCADAD187EB5EULL, 0xB08074BA7B6459F5ULL, 
            0xBC30314CC09F401CULL, 0xA58B667002CEB8B3ULL, 0x9987DE80189BF105ULL, 0x0A9AB6882AFC07F2ULL, 
            0xF846243D660DF439ULL, 0x4163ABD2691837CBULL, 0x9F7AA1BDB3493EC9ULL, 0x43ADCC263FD3CC98ULL, 
            0x9797A7C359EE1641ULL, 0xE482FF96E0660970ULL, 0x653E4BA77B99985BULL, 0xD6DFFCE16E10551CULL, 
            0x30735C0978CD72D1ULL, 0x1E651E4C8A03D6ACULL, 0xB1EC4364C03A91D4ULL, 0x1A24E6F6B1349E67ULL, 
            0x6016FD5330216AF2ULL, 0x32D5C4F17249370BULL, 0x8AF3C921866F8F60ULL, 0xC8D772657207FC22ULL
        },
        {
            0x4828DAE6ABDCA0CFULL, 0x69A760F60BD2E5F6ULL, 0xA4FF360CF05CC65AULL, 0x4740BA87D03D0D97ULL, 
            0x4446CFE6E9431669ULL, 0x2819E87E15AC57B0ULL, 0x9391C851568908D3ULL, 0x5CDD27C2FBFABC4DULL, 
            0xBAF9C2228B2E302AULL, 0x97661A6AD47D441DULL, 0xAAD414EEA174476AULL, 0x0EB783B6D6BA377AULL, 
            0xE6133EC98CF95F2DULL, 0x6003B7882649C4B7ULL, 0x2B6507B21D0FB8ADULL, 0xCB4A478D80BBAE87ULL, 
            0xE4211832B9C6A3A1ULL, 0x06DEDBDAC482D4E8ULL, 0xA5A544E8A745C452ULL, 0xBAD0821FA729E4B5ULL, 
            0x7E5C2C227FB72882ULL, 0x2A54BEBBF10E4DDEULL, 0x0BEF41198392DC62ULL, 0x8D2FBD5FC15C3726ULL, 
            0x6813C8EEA2A8A0D2ULL, 0x19FFE64648D77B0DULL, 0x68AB5D7CCE464DF4ULL, 0xFD9C56A60C6A4095ULL, 
            0xAD5104915CA428BAULL, 0x49601C743ECADECCULL, 0xDB60897A87ADF4EEULL, 0x2EBEEE44B2053CCFULL
        },
        {
            0xAAD6A2275224198FULL, 0x20BDB1142DB0A0C3ULL, 0x40290F0FBA8D5345ULL, 0x292BF501DF2D888CULL, 
            0xF596F6138211D901ULL, 0xE2114B5507B6B021ULL, 0xB652A1654A215F52ULL, 0x7A5A8AB6566C414DULL, 
            0x5AD939FFA1AD4E55ULL, 0x36404C578A2C693AULL, 0x429CFA37DC9A96F2ULL, 0x929284AC7FEA6091ULL, 
            0xB0E99A8F7CDEE58DULL, 0x7D08134D6DDC56C7ULL, 0x7A518F5DAE556308ULL, 0x7F2CE7829E45713AULL, 
            0xE1A749BEF427AFBDULL, 0xC38FD36E1ED0C015ULL, 0x0AC1381FE8C23190ULL, 0x8DAA658F0F271325ULL, 
            0x190A296865189958ULL, 0xAB8DE3D541182F7EULL, 0x0743F395B351C329ULL, 0xA9AEC40207927CD1ULL, 
            0x67B49D8FAE070183ULL, 0x986D8E6A57874486ULL, 0x9D3AB4CF342A7636ULL, 0x7D643267DCABCCEEULL, 
            0x015207733F13760AULL, 0xA8632FE7ED60741AULL, 0x66AE5665DA813114ULL, 0xACA7A259B4592D31ULL
        },
        {
            0x79091FB51B7CD7AFULL, 0x2BA78485F37D19D4ULL, 0xD7D8A3B8411D2933ULL, 0x4CD755559785C4FBULL, 
            0xD69ADAEF1EE0D548ULL, 0xABE079310D623F1AULL, 0x32B6210A2291F049ULL, 0x685CCE784E450898ULL, 
            0x002A55A26B125096ULL, 0x122BA173C3FDC532ULL, 0xADABE70227EA65ACULL, 0xAD1F1563F3484EFFULL, 
            0x3FC0AC2A41C1853CULL, 0x44762F8B397C48BAULL, 0x70BBEC1DEF1A6E7BULL, 0xC23A6E4BBD50D35FULL, 
            0x3B09171A8A8F362EULL, 0xCA37612517B729E4ULL, 0xDF7EDE8A084DBE05ULL, 0xA056F7CC8F21FE94ULL, 
            0x44942F8EB9CE3B19ULL, 0x425E3DF130BABE19ULL, 0x7A669CE5410E0958ULL, 0xFEF311F1707B8EADULL, 
            0x0E29672490C8CA46ULL, 0x657A6FB55C998B23ULL, 0x6917237BEB9E4BEBULL, 0x12EE5F29CB8F2611ULL, 
            0xA40CF99BC39E8BCFULL, 0x6182AAC305553627ULL, 0x533203FE84817928ULL, 0x81095E987C893248ULL
        },
        {
            0x4B1DE5702F13CD6BULL, 0xA8B0F1637CB64125ULL, 0xF50B0A4C8F7A44ADULL, 0x0EBCC7D2D96CE207ULL, 
            0x5353A422FFCA56B0ULL, 0xA8643BA7CF7292A3ULL, 0x39785595A0B1F3F5ULL, 0x535ADBE2F0ECBD6FULL, 
            0x3E74B8DFE25C8964ULL, 0x896333EA7A411421ULL, 0x1A1EB2524AF4D302ULL, 0x8EE1298DF2E22F07ULL, 
            0x58B8800A4FA5C6CBULL, 0x11B56008695A982EULL, 0xD6366E7CBD77C68DULL, 0xD021E6B3178A1BEFULL, 
            0x11C107360827396FULL, 0x26D4E8C1238F1E5CULL, 0xF97DFAF47BCD6BC2ULL, 0xDD97256C85186ACFULL, 
            0xD75B6BB83906E4F5ULL, 0x39D1333BCED32A86ULL, 0x8167C3E2C7449BA4ULL, 0x4C268881F421AD45ULL, 
            0xDA232586274A0559ULL, 0xC1412316F7477E7AULL, 0x5417CA6A955DD2D0ULL, 0x24CE7A37B563EF0DULL, 
            0x71F681A8243DDEFFULL, 0x254C400D5E64B2BEULL, 0x664A44AAC5C4D19BULL, 0x7F21C0947AA588DAULL
        },
        {
            0x0EE6A15DA3316DC8ULL, 0x04CA751207EEE3CDULL, 0x3B2BF65CAA608290ULL, 0xF47F9979B1D76AF5ULL, 
            0x30181F4210849E90ULL, 0x0691D55A65FF7DF2ULL, 0x865F86068EA4633EULL, 0x50F43DB49DA56865ULL, 
            0x8CC3539914416C2FULL, 0xE748AE049627FE15ULL, 0xA2EBCD55984E3068ULL, 0x3ADA1786C66F238EULL, 
            0x88B2BBB888A4396BULL, 0xCC59DE3D4C8AA508ULL, 0x94A68260E53BB86DULL, 0xA291BFEA0E2D2A42ULL, 
            0xDF52B4FC5818A930ULL, 0xA91457329876B28EULL, 0x7A82B20CBDD64E75ULL, 0x181779447156092FULL, 
            0x79AC6EAAE230F689ULL, 0xD3F22A223A9C263FULL, 0xF48CE7B04B94349CULL, 0x3F7B67C58A6B6214ULL, 
            0x58F188C88B749EE0ULL, 0x4DB8F4FD8BDB61C7ULL, 0xF157E4ED17FE575AULL, 0x999413F7C9EE70EAULL, 
            0x119ACBB9F00538A3ULL, 0xCAD41A8F20B988B5ULL, 0xCD707139D17893A7ULL, 0x21701231B26D863EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Altair::kKeySpawnBConstants = {
    0x1D6A859A58EF7336ULL,
    0x230C0BB526895BA5ULL,
    0x6B816DEAF80A2D8BULL,
    0x1D6A859A58EF7336ULL,
    0x230C0BB526895BA5ULL,
    0x6B816DEAF80A2D8BULL,
    0x67FCBA3B3BE09205ULL,
    0xF095045C7A88AB88ULL,
    0x25,
    0x47,
    0x36,
    0xC5,
    0xD5,
    0x5B,
    0xA7,
    0x8E
};

const TwistDomainSaltSet TwistExpander_Altair::kSeedSalts = {
    {
        {
            0x8D113211ABD633DEULL, 0x68EB4AD0F27AD6B2ULL, 0x5ABB2350F3A01C6AULL, 0x79183AE60B49AD60ULL, 
            0x191361C0C7C8DFF4ULL, 0x1D7E7BFCA2A62B2BULL, 0x323B53400CDB42B1ULL, 0x864F6772AA6036EBULL, 
            0xD5361408B1EC2F4FULL, 0x734297774AB11CB3ULL, 0x06F17ABDECA1040DULL, 0x26434EFECBEA8769ULL, 
            0xD4157A1545F815DBULL, 0xAD596BF555903A21ULL, 0x896D146A57033BD9ULL, 0xBAF980299B4DC056ULL, 
            0x162B2ADB78B6A0C7ULL, 0xEF9F5345420F8382ULL, 0x96C165CD0ED494F0ULL, 0xACE614125FFDAE10ULL, 
            0x68E352DA48171088ULL, 0x0709C3EAB3535FA1ULL, 0x52381B2A515FA043ULL, 0x51C45492CE3C442AULL, 
            0x8B0A040A1A71AC6CULL, 0x30EBED50FEBBADBDULL, 0x85BC660750539A74ULL, 0xB4DEDD920946F09CULL, 
            0x4398470CDF82D1B4ULL, 0x4E63CBBFEF935329ULL, 0x6D5C2F408B004A98ULL, 0x5792D12AB836FC7AULL
        },
        {
            0xE84CEBB520FB6FE3ULL, 0x05CB1E7A1ED9141BULL, 0x3326CE031908BE23ULL, 0xCA3DEBFE279A97CAULL, 
            0x347749B98E8FDBF2ULL, 0xD8E40501D76CBE6FULL, 0x5B62BF3E26530191ULL, 0x9B127B60C99764B3ULL, 
            0x00FFED220ACFC53EULL, 0x42A9DF54355D9EE7ULL, 0x1ACA368773F9382AULL, 0xC465E99C10A6BF86ULL, 
            0x4F65A8819466B9CDULL, 0x7EFCA0564DDCD5E0ULL, 0x4B830918660511C4ULL, 0x463997C66A6A0CA9ULL, 
            0x27468BC480DDF205ULL, 0x65516E8CE277D1B6ULL, 0x33847481AD7E4F67ULL, 0x7E470377B21C7289ULL, 
            0x2F19FAFB1977C3F8ULL, 0xF7F4752EC84F7388ULL, 0xFA9A21B099700E81ULL, 0x27119D8C736D1CFDULL, 
            0x9D92BBC8856DDE4DULL, 0x129F462D5198AB5DULL, 0x6D9144AE363FBBD3ULL, 0x6894812270F25DC3ULL, 
            0x13495305452151D1ULL, 0x2AEDFAFA987F8811ULL, 0xB83E5011B527E197ULL, 0xE52D2DC41BE900CEULL
        },
        {
            0x29876FA21CCD1F4FULL, 0x65C6784EBCC7950BULL, 0x7A07B3DF8C587CE3ULL, 0x2C7972E001E2424BULL, 
            0x20484B83782EB082ULL, 0x8B6D190E4FFD7173ULL, 0xF00F6A12840E788CULL, 0xCB5043E1FB3E0611ULL, 
            0xE2AEFEE97DC4F7C4ULL, 0x035F9026FD1DBE0FULL, 0x2A9B40C7B4764501ULL, 0x51B42F4BA4C63E7AULL, 
            0x818948B1E22D7DBDULL, 0x6C8FF9B8C6DF5742ULL, 0xD3504688861218C9ULL, 0x0425BD8ED44E6739ULL, 
            0x9744BBC5B9F661DEULL, 0xC37158139600AFD0ULL, 0x2C94599469BD296CULL, 0x5A2F1D0DC1D3CFBDULL, 
            0x550D2EFBA366F072ULL, 0x550EB4E0CC8CFF32ULL, 0x4FC08AB5FFE8C5BAULL, 0xB1CACCFEE5E66616ULL, 
            0x7726C767F81915D3ULL, 0xB2690969BC4A127BULL, 0xE129C84B8847DCCAULL, 0xB6DA961FB2501BB8ULL, 
            0xE28C5C9326C9DA72ULL, 0x212AC63A5D23C9D6ULL, 0x9E9C729944DDA688ULL, 0xCE091AFD99FE71DAULL
        },
        {
            0x35A7142F168A3153ULL, 0x1F6B431B7AD42B7AULL, 0x6DEE6EA5591B5000ULL, 0x7BA28A6DDCEC7A1DULL, 
            0x949BA41CF9935BDCULL, 0x4A1D0C60B84417C5ULL, 0xC22F348349DD2CC0ULL, 0xB5410A5D5A568E0DULL, 
            0xCD0A7430EAE71FEEULL, 0xB9ED44E1C808C52BULL, 0x23968F90FBB16886ULL, 0x0C1724D337FA5560ULL, 
            0x9DFE885F0EA15114ULL, 0x70D11D8C694BE487ULL, 0x0E3D78E96AED5A3FULL, 0xD90B95E581DDB03EULL, 
            0xFAB8C69B954A77CFULL, 0x0C51116AE2AABFC9ULL, 0x3706801C9F178D3FULL, 0x1625C8274A95FC11ULL, 
            0x1B9AA61394FED667ULL, 0x8D5AE91C96C44BA7ULL, 0xDBAF0FA747ADCFFFULL, 0x7533B60BA7A0B410ULL, 
            0xE32BBA6ED3FB3D55ULL, 0xAEF2AC77972081F9ULL, 0x874B5739A1D44506ULL, 0xE89B17E9E2E58462ULL, 
            0xEFA902BA0282E99AULL, 0xC630A0EAD7746A1DULL, 0xB64F5C3F8A3E7B8AULL, 0xD51E40F7C0AC670DULL
        },
        {
            0x584CC160A6D90A0BULL, 0xC6AA302C6CAD8D14ULL, 0x45B385885708E259ULL, 0x6702B037172B3A23ULL, 
            0xFF7693832E5097C7ULL, 0x695BCEBFB68C2803ULL, 0x4FA94E7FA4180EE7ULL, 0x3879EB7E130C21C6ULL, 
            0xEDA53A656442ADB2ULL, 0x4029FA51CD59379CULL, 0x0DDB5829B35916EAULL, 0x74D9A08C4DE00284ULL, 
            0x19BDD5AB98B47232ULL, 0x0FD7117844EC557BULL, 0x2F10EA0ECEF5432CULL, 0x5DD6CE369F04039EULL, 
            0xEA6456A8A235DE00ULL, 0x6AFF8B11DED81712ULL, 0xF71C3CA7B9797C99ULL, 0x0FEDF4F17DF35885ULL, 
            0x02C60E9D271BCE62ULL, 0x27978FF0BF9C35E5ULL, 0x395A854A93B93091ULL, 0xE695415137AC26FDULL, 
            0x76763774F4AF2117ULL, 0x32B201AF2647E75EULL, 0x79B8C821ED86A276ULL, 0x10D57976262A7D60ULL, 
            0xE8CAAA25CC78EED7ULL, 0xADF9A8930E953C06ULL, 0x1E2347457E043E04ULL, 0x3F0E14BE35809C66ULL
        },
        {
            0xE131CD15F8CEBF22ULL, 0x3056BD05B36EAD40ULL, 0x22EAD26C22B8C820ULL, 0xE20504DE1DD0520EULL, 
            0xC9DF6E92D3BC312AULL, 0x674FBD5FDAE07618ULL, 0xC719E5BCDF5CFBB6ULL, 0xF0E4740D67DB3BB8ULL, 
            0x6353B5B97A02587CULL, 0x152908130E2B88E6ULL, 0x57BE81830726418CULL, 0xC569C57811A0C37CULL, 
            0x639AEF7A9C3083A9ULL, 0xE626B0F1F1BD27F6ULL, 0x2BDF23289C4BDEBAULL, 0xB12D34BD5482CD96ULL, 
            0xEE4BEFD28BFAE878ULL, 0x5DAEC565C77CFEFBULL, 0xBA4E75EF508A74B2ULL, 0x9984D8D160F7D627ULL, 
            0xB82001A5D53227BFULL, 0xA8361E0E26782DDFULL, 0x84F9707D9662BB74ULL, 0x4F816BC4E5C1E3ABULL, 
            0xDE8E16F34FDDEE1CULL, 0x9162068B1AC142F7ULL, 0x818C56D4D3A6A275ULL, 0xE518DBC363A6E01FULL, 
            0xA8A71E9D1EA0D7D4ULL, 0xD8632F3E311622EEULL, 0xEE55738E22BCE99CULL, 0xDE69B0AADCCFEB02ULL
        }
    },
    {
        {
            0x571BB4F9102191A2ULL, 0xCA43DC39CD777407ULL, 0x5AE8411E4FB87E0DULL, 0x239C71C4DC475DDCULL, 
            0xA92F9D5372ECCBFDULL, 0x22A2E2CC1A1B36BAULL, 0x779EABAADF4059A6ULL, 0xCC137D60830E8E56ULL, 
            0x416BAD3D36FC3314ULL, 0xF504BF722E63CD19ULL, 0x36A280C3F3CA70ECULL, 0x3E7A3002BB2DB4A9ULL, 
            0x0136BEB1243C27ACULL, 0xA38CAF43C410917AULL, 0x209AD6608D7575E5ULL, 0x3A6C042B45D9FCB7ULL, 
            0xEDF76D5BACED103CULL, 0x375AA60CAA163C33ULL, 0x92ECC441DC0BA9CFULL, 0x36972BBA7AB2586BULL, 
            0x190A5DAD8017BB49ULL, 0x677344D3D758EE05ULL, 0x781E7BC6045E5984ULL, 0x329BAF4FC6308EBBULL, 
            0xBF77FDE769CE88EFULL, 0xF61C90AE2E8717D1ULL, 0x29592BCA9EB2F3E6ULL, 0x351A0125ABDA4F7AULL, 
            0xAC45431105FA9728ULL, 0xAA8E072425452132ULL, 0x2428BB518513A204ULL, 0xA63106CB313BF2F5ULL
        },
        {
            0xBD191377B5BAE266ULL, 0xBEBA2861F65CB43FULL, 0x875DDCFDCF8ADB9FULL, 0x28E4EED8ECA26D52ULL, 
            0x90DE7C1D47B08131ULL, 0xECE84E330EF486B8ULL, 0xC275483E2972B1ECULL, 0x6B04521706AE8087ULL, 
            0x29EC2CA489C3AB32ULL, 0x695231B098180C56ULL, 0x249469F66D5E8787ULL, 0x8CE4A0EA45444E59ULL, 
            0xE33BC9A5A3BB0885ULL, 0xEC4D7C492B7AE5B0ULL, 0x53C63601BF35E864ULL, 0x17F943BAD0B7AF06ULL, 
            0xCAF47630AC77C090ULL, 0xB5D9A4C8EB7D7D1AULL, 0xE17F721949EEEA65ULL, 0x4AC2216DB1EF3FA5ULL, 
            0x68A814CC49640B6FULL, 0x09F1770082C32F54ULL, 0xA77B315B3C557DEDULL, 0x83EEB1DA38ADDF89ULL, 
            0x23C6098DD7D4FDAFULL, 0x051DEDFF4AFF4BBAULL, 0xABDA795429A88D82ULL, 0x7B2A11DE956B455EULL, 
            0xBAA0CF918481CA07ULL, 0x2D6CD766EF21ADBAULL, 0xDB63EEA271CF7493ULL, 0xAE43C773D8C892CDULL
        },
        {
            0xF19B08236BEE375CULL, 0x75DCA840B5B66774ULL, 0x9DB29D5E5336835EULL, 0xE9611F139AF6DA1FULL, 
            0xBDCC00C55FACE307ULL, 0xDD2C8B8E31F40A4BULL, 0x8032DD349A5DAA1EULL, 0xB6672DE7C68A2D73ULL, 
            0x62609C0A14B332B1ULL, 0x2FAE07CA0948C7CBULL, 0xF561FE8C80BC1880ULL, 0xF94327D0948276B3ULL, 
            0x7C61BF5548A4A9F3ULL, 0x1D29E2F430AA2192ULL, 0x241EE98991854F39ULL, 0xDCDDA6D4F13B9719ULL, 
            0x263B19D12742EEF5ULL, 0x393B2B2728643554ULL, 0xC3E6F3BCBD04F58BULL, 0xB91411037EA06232ULL, 
            0x0289A816FE9D05B0ULL, 0x9C07D6F7CD098B7CULL, 0x26EAF1D09E38D895ULL, 0xE082F5904A7721CCULL, 
            0x4B4BCC7E7DAFE1F9ULL, 0x2ABE65067DFCDFB6ULL, 0xD8388E6DDCEADBD0ULL, 0xAB83B838DCAA19CDULL, 
            0x74CF70714A4D322EULL, 0x0777784F6A7F354FULL, 0x15B98BBC5F988C13ULL, 0x4E2E9A4AEEF9A122ULL
        },
        {
            0xE9C58827F724B5FEULL, 0x761FAC746DA401B3ULL, 0xF24DDB8EAD027267ULL, 0x468C8A01D88B1955ULL, 
            0x0BB013B7F8487099ULL, 0xC8A5DDD8AF808FE2ULL, 0x373E415BEAA0FB70ULL, 0x86D2CC6D5A1D0844ULL, 
            0xE794700B24E41DE1ULL, 0x155DA5781416AF9AULL, 0xADD36347A2C05165ULL, 0xFB9391875428EA1FULL, 
            0xA3E8FD26CE2907D6ULL, 0x366B8D173AEE70FAULL, 0xB6035CAA74BED6CBULL, 0xCB74B040B9A90F94ULL, 
            0x6104829BB5DDC4FCULL, 0xAABAD10B63AB144DULL, 0xA092688A3657C0D9ULL, 0x17364106F5015FC2ULL, 
            0x494AD51A073E8586ULL, 0x1CE5EF97444B00CDULL, 0xAE0D119FFDD3AD5AULL, 0xE8DD33A6CC6A28EFULL, 
            0x331BCA2B2F14D24CULL, 0x1AA3A2377EA2C2E0ULL, 0xED15AFE2733EF42CULL, 0xCBEDCC668B88B6A0ULL, 
            0xACB6502CE81CDB9EULL, 0xB613971344D4F944ULL, 0x2647C352AFA4CD1BULL, 0x7857F9CD374526A0ULL
        },
        {
            0xD7C8C9DF9DD9E280ULL, 0x7EB8EB98B332BC18ULL, 0x906FD1126367DD4BULL, 0xF7062DBAE357585CULL, 
            0x5297E3F6024990D4ULL, 0xA0CFA87CBF55E57CULL, 0xE8557B19912BA82FULL, 0xADB5563A5F408D00ULL, 
            0xBB6AF185B4567769ULL, 0xC7B57F00E83D11EBULL, 0xEA81CEC1FEAF7F59ULL, 0x89B43EEAFCA49F07ULL, 
            0x52DAD99FBFCA1A2FULL, 0x0F4B9CCBF3D0CBCDULL, 0x7F593C1B37D147C7ULL, 0xE0105866AC69C7C8ULL, 
            0xF1A081EBFF22BFDDULL, 0xB6693BC0F797E08DULL, 0x5A37037480E6F6F9ULL, 0x3A9D8966D0EA92EEULL, 
            0x25CE1D8C8E742E7FULL, 0x9E7CC603E2B0DD67ULL, 0xDAF7003168BE1D3FULL, 0x041734B40B5838E1ULL, 
            0xAE2BD4BF03C407E4ULL, 0xA411E459C952E70AULL, 0xE2F1F0C14A6EC484ULL, 0xDB0142BD45B93333ULL, 
            0x38D02288F09704EFULL, 0x45C6C30B79C09D1DULL, 0xDEF2737045FFBC03ULL, 0x5ADCAF85ACFB62DDULL
        },
        {
            0xDF59FAC0D8D3CBD8ULL, 0xFABBDE5E9DA8DBD8ULL, 0x46D779EC13B2D426ULL, 0x5360C1CE6DBB64B0ULL, 
            0x0CA1045A9A11DCF6ULL, 0x809C8476B529B1B8ULL, 0x75444580626A9EB9ULL, 0xB67864163BB9E3ACULL, 
            0x27E14FC1FCC94E0EULL, 0xA064B1A39F93E1B9ULL, 0x883CCB025A5FF1EBULL, 0x1563E0D2BA296886ULL, 
            0x77BDA17809B53073ULL, 0x38CF0C7BE9B0BB9FULL, 0x13A0E3CFC53F2273ULL, 0x89255A12831369C7ULL, 
            0xB1DD63F6095A8101ULL, 0x7387F3A42BF0871CULL, 0x14B4FF54E039E8CBULL, 0x83C00D79D1C805E0ULL, 
            0x55BC2262636E1B6AULL, 0x28DEFAA106BDB380ULL, 0x51F554EE0CD11212ULL, 0x4133A4543E83DD4AULL, 
            0x64734383552CAC0BULL, 0x6E65DB303018E391ULL, 0x13F4FD17F62B2E8BULL, 0xB73980A462057055ULL, 
            0x5DFF204C23A2A5A7ULL, 0x0D4F2D51B8248F5FULL, 0x7C855E82A0A8A84CULL, 0x4E8F6889CB1A157EULL
        }
    },
    {
        {
            0xBA55CEA3555A2213ULL, 0x25B72670611E0D5FULL, 0x65824D27E3D6C73EULL, 0xED9A95A7EC11888EULL, 
            0x1A1D1C033FDF6116ULL, 0xF7B19FCBEB5ECAD0ULL, 0x3DBBFAF1138E2FFAULL, 0x074CF8B43E10EF6EULL, 
            0x263DC069A3CA2D81ULL, 0x98971B7C180FF60CULL, 0x8CDDFBD28B46B3E7ULL, 0x1200166D28273FFDULL, 
            0xE8C4448320B84166ULL, 0x461F99AB33298D23ULL, 0xC4E23CFF12570C9DULL, 0xF199466E8774F490ULL, 
            0x8A85F906D8A68268ULL, 0x4B803C96D16D3C37ULL, 0x73A948E6EEE5A082ULL, 0xB5CC2B4D42A5EE46ULL, 
            0x102C55CC89D04ED2ULL, 0xAB8C61B5F2817C5BULL, 0x5C4D2EF7A7CD225CULL, 0x2517465FD0FD66F5ULL, 
            0x33D03F793A325F8EULL, 0x4F0868ED6D2938C6ULL, 0xF72DB08B70848D0DULL, 0xC4E282DB77D9AE65ULL, 
            0xA8CE222B3993E15CULL, 0x55170E0952E960C3ULL, 0xC51C21C806988F7BULL, 0xD5FE7341F947B7A8ULL
        },
        {
            0xECEEB92BE87250A0ULL, 0xBAAD88FA00EB0E28ULL, 0x6056D6D8D92EACCAULL, 0x0FE0BC03BBBDF7F1ULL, 
            0x79723BB812A5895AULL, 0xE7312C7AD17C9976ULL, 0x1B9D433958B0B902ULL, 0x71E917E8F1F8CC5FULL, 
            0xDB78BAA9B85B6352ULL, 0x3029D4F16C8CAA95ULL, 0x970CD075E3873C0EULL, 0x67F44D7D9C4F738DULL, 
            0xDE463CCB5FFC7BD8ULL, 0x6FCF576BBFBEDBE1ULL, 0x9F121EE89E33AF64ULL, 0x973A13C23E77B8F3ULL, 
            0xD38005D36596AC1CULL, 0x6214A86D96A78D9AULL, 0xF0BB474DF3448905ULL, 0xEC6495A204CD7B9DULL, 
            0x7D54C4E48CCF68EFULL, 0x8BB4330C6F6BF25CULL, 0xA291DD440B325F42ULL, 0xE0BCC7E299625581ULL, 
            0xD96836EF88CB4C1CULL, 0x0BF5ADCB78F58BA2ULL, 0x634E446032AC65B9ULL, 0xDC602CDB24F0A32DULL, 
            0x05C6FC1CBEAD1671ULL, 0xCB84A6EA563779E9ULL, 0xA28D80D5D77E5749ULL, 0x0FF90A09ED771635ULL
        },
        {
            0xC07B60B257204A4BULL, 0xCBCDBC7DDABB48AFULL, 0x4570FC0434AC6FCDULL, 0x41BE1F6ED833A917ULL, 
            0xAFC7B5A1FDE2A05AULL, 0x1ADC90CBE2F125BFULL, 0xE927952A1E76393EULL, 0xDA68CE698A2EABD3ULL, 
            0x1EFCC05064A558D9ULL, 0x04F083B6496E8E8EULL, 0x302D9FD85FA3C204ULL, 0xB11B7A30DD90ED0CULL, 
            0xD1B2D3DEAD9C09FDULL, 0x349230445992A36EULL, 0x2B695A99A5DAACB5ULL, 0x54A4E3886E02419EULL, 
            0xE0C558F52875C5C9ULL, 0x2B3E356FE581C9BCULL, 0x55C6AAB7CF97E0B4ULL, 0xA49ABC8225562811ULL, 
            0xA8CF37B5570E2C18ULL, 0x1FC11B25D4B86ABFULL, 0x8F146312E6413882ULL, 0x1734FC515FD736BCULL, 
            0xCE915416BD302380ULL, 0x85F0061A7393D70EULL, 0x9E23EDE6975C827CULL, 0x01043401B4DF853DULL, 
            0x7B335AC4C421E71FULL, 0xF98BB4AABABE8E3BULL, 0x3C83F6EE9EAA4E10ULL, 0xAF6477EF67EA12F6ULL
        },
        {
            0x8F1EF180E9C1DD6BULL, 0xE89318FFCCAB1EF0ULL, 0x6C8678582C063B69ULL, 0x88983FEE4F151051ULL, 
            0x2B9B987399FF36E4ULL, 0x46AEE6FAA29BBF68ULL, 0xAFFB0638493BB6E1ULL, 0x776EEF07CBACEBD5ULL, 
            0x704F878429827436ULL, 0xC95A27D8773682F0ULL, 0x0F6235B73F5598EDULL, 0x74C8DD6A56744250ULL, 
            0xEA973E5114C7A33FULL, 0x6FEA743010E7B44AULL, 0x6AD749881E29EE9FULL, 0xD31935D604F09893ULL, 
            0xA99FE97BE262ACBFULL, 0x7D17E0A34436180FULL, 0x3768BEF3A3C71A73ULL, 0xAC4A33E37BBD123BULL, 
            0x65916C1475AAAE7EULL, 0x485FF95C0E9BDCE7ULL, 0xE0EFEDF339496AD6ULL, 0x7A99CFCF854F91C3ULL, 
            0x002309DEE3D49803ULL, 0xECF4DE2073759CB1ULL, 0xF57AFCF059188E65ULL, 0x0CFB61777589FA00ULL, 
            0x9C6404710476A214ULL, 0xC3C7A92064463751ULL, 0x0E18CCF84E7EA361ULL, 0x3A184019485C0CF5ULL
        },
        {
            0xE586345C8D1FE040ULL, 0xC600FB5F98D66FCAULL, 0x55EE2C4556CEEEEFULL, 0xBBEDBB86BD66F7E5ULL, 
            0x00A1D55875A7D449ULL, 0xAB9F50CCBE202608ULL, 0x4E299E52088FFA27ULL, 0x7A9052B847C6E5F3ULL, 
            0x08BF27236E00EA0AULL, 0xF2E462A0A904197EULL, 0xC864CAC570F0E818ULL, 0x39162415902C0CBAULL, 
            0x523CBA46152A861DULL, 0xB52C7019A3426C97ULL, 0x19CDAFA27FDF32A7ULL, 0xB4DC5AA27257C84EULL, 
            0x3192B3DAEA96B403ULL, 0x6510B12EB1567B00ULL, 0x90B11D3466127AD1ULL, 0xEA9ED516DEB074F6ULL, 
            0xEB2A5EE446205660ULL, 0x3350B2AA131B45B0ULL, 0x4F6E4BC3ADD088FDULL, 0x8B75089371027B14ULL, 
            0xC32F9AF1AFE2C2DBULL, 0x90C03076EF597A6BULL, 0xD00505FA1F159099ULL, 0x5F433C288D2E9E60ULL, 
            0x7C7C2C3F2D7C70E4ULL, 0x5B1588748623D1EFULL, 0x62F614513375385CULL, 0xE42A41D57EEF4E8FULL
        },
        {
            0xB9AA3247C12E6BD8ULL, 0x8D24F1C37200D6A4ULL, 0x98441CE98D104855ULL, 0xCFBFE4E3C632AC38ULL, 
            0x664D24102E922E7DULL, 0x70034F36CB37FDADULL, 0x9A3F9B57BE43696AULL, 0x69CF4D4A226A5F6BULL, 
            0x35386603F570659BULL, 0xF47805A5000CD5B5ULL, 0x201002FDAE8C7F7BULL, 0x3B4D0CD42D2CB0B1ULL, 
            0x323F28CA3F8B7B93ULL, 0x2F22F9094BAE470AULL, 0xCD2672C1B3077B13ULL, 0xCCD9A61A34E4445BULL, 
            0x03085D8234D6DFE8ULL, 0xA4B5E859666D6909ULL, 0x50F32D97F4FE534BULL, 0x17BCF0352B907187ULL, 
            0x8DA0E03DC03E088EULL, 0x49539629E863E818ULL, 0xA676D344300CECC3ULL, 0x32882DE342B37394ULL, 
            0x827D8BB9296CA400ULL, 0x549D0EBF726FCB07ULL, 0x1115CE7301AA8CEDULL, 0x8E2B77A3C0E34B59ULL, 
            0x1B83A7106D15B60CULL, 0xE5A4A540B4A9D564ULL, 0x74100F32787EC18DULL, 0xCEBFE527E0D504B0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Altair::kSeedConstants = {
    0x6EF3BF4C0F9D1A03ULL,
    0x25CBFDFDE935C298ULL,
    0xABA279D233E12211ULL,
    0x6EF3BF4C0F9D1A03ULL,
    0x25CBFDFDE935C298ULL,
    0xABA279D233E12211ULL,
    0xEEE626A1CEE38FD0ULL,
    0x4EDF185AD1A574B9ULL,
    0xCA,
    0x04,
    0x12,
    0x3B,
    0xA4,
    0x2C,
    0xD4,
    0xB5
};

const TwistDomainSaltSet TwistExpander_Altair::kTwistSalts = {
    {
        {
            0xD9F72A891999C023ULL, 0x3033DB057B1DD590ULL, 0xD564A4417A77016AULL, 0x8F7D1C39E0001A1FULL, 
            0x9DE3E8654163D7D7ULL, 0x0BC8EA4D331069DBULL, 0x0EB91EBA878891D2ULL, 0x952CF071B1230AE6ULL, 
            0xB231F44C81961BDCULL, 0x304604A9F5192215ULL, 0xBFF04AD81FF93CE7ULL, 0xF12D3AB8A6049C9BULL, 
            0xE4BF5979FAEB086FULL, 0xCC982E4D240A182AULL, 0x8A2FEF9CE7C1594FULL, 0x997378078FFF0765ULL, 
            0xB5F3B3D1D3AFFAE9ULL, 0x7D3FDF9A3FB9597CULL, 0xB8765C7DF8422AD7ULL, 0xEB1D41B17E9AB142ULL, 
            0xF629E10F3432259CULL, 0x44E26C62ADF7E639ULL, 0x196DD2B0D0415165ULL, 0x688187BB56535CD3ULL, 
            0x788D9CC45B66F6AFULL, 0xEEA0883423367A44ULL, 0x94A9E998FDEA868BULL, 0xDCC4CEFB6F9D1A30ULL, 
            0xB0DF365880FC8FD8ULL, 0x805809759D0715ECULL, 0x4139E1B8F2D8B3BFULL, 0x2B15F91F1CA9B607ULL
        },
        {
            0x6FC283EFDCAD5BA6ULL, 0x578A7EAA6A28264EULL, 0xA3FC7EDF817B3069ULL, 0x6AD294FD840796A1ULL, 
            0xC3A5C0878A0D83F9ULL, 0xF15AF9BA3E6A0E98ULL, 0xDED5400447A65235ULL, 0xEF970DC3A169098DULL, 
            0x998A9868FC49D442ULL, 0xF447DCB08AB7C753ULL, 0x8FBD87C0885F47CFULL, 0xAAE5C13ABCB5DA14ULL, 
            0x1A418238C02E256FULL, 0x27A3DF76AC7399AFULL, 0x1082D8FAA692C177ULL, 0xD61C15077CF914C7ULL, 
            0x55C02B6BB2FDE947ULL, 0x65CB06EABACD593CULL, 0xD437B2B98207858AULL, 0x00E3BCBD461D6724ULL, 
            0xC223726B1080EA20ULL, 0xB7BEEA1373AF2716ULL, 0x7F7218F16A253969ULL, 0x82E7CE6C4B5227E8ULL, 
            0xB13537237B0678CFULL, 0xA356635E98B97442ULL, 0xF55DEFADB51ED924ULL, 0x8BC4FD2C95A3ADB5ULL, 
            0x9CC646E29FD5C832ULL, 0x7CA60242478330C9ULL, 0xEE360D6CF29A6F51ULL, 0x6F9AB403036423A4ULL
        },
        {
            0x5047EE7ED88A4E30ULL, 0x5DC0E53A987ECC30ULL, 0xD55F1F353882903BULL, 0x32F8CDC153C28E2CULL, 
            0x7F4313B08C8C893EULL, 0x8C1F2E9E97731D3BULL, 0x6E178BF21F3A3543ULL, 0x1518262A31E28B5FULL, 
            0xFB5D6B4CB1B2261FULL, 0xC345682419B9B53CULL, 0x8ECFA3F6247F5866ULL, 0x4F8E4822CCB2C86DULL, 
            0x538B93C044B2E181ULL, 0xEC5DC91F36F0E6A1ULL, 0x34E7F7FFE7933B40ULL, 0x799AD2A168450207ULL, 
            0x3A6D5C9D4378AF19ULL, 0x87184EB249DA6B2BULL, 0x53E00A3AA5CEDBD4ULL, 0x185838790A753FC7ULL, 
            0x9555AF87729111C9ULL, 0x26CD042C2D48A78AULL, 0x22681FE57509604AULL, 0x64F72A4670FA0B31ULL, 
            0x36E8657F36FC4B9FULL, 0xC9A9B6DBB3351C23ULL, 0xDC621184367BFFBFULL, 0x2FDABEF630839FD0ULL, 
            0x0F6065D57DE329EEULL, 0xFDADC0B8CF2B8075ULL, 0xDB34DCB4D612AC5FULL, 0x44110F1E388A0083ULL
        },
        {
            0x6DD1C7D845F46E92ULL, 0xA9EC8B44F8FC73DBULL, 0xD39CEC863AC374D9ULL, 0xFBA1CBE5D0FB4F1AULL, 
            0x2D554CD3D0FF1144ULL, 0xF9B179B5D7C7C93CULL, 0xA573E32EFEF093CDULL, 0x5680D3785EF683E8ULL, 
            0x132DE4BBBF905EA0ULL, 0xD28ED735CF487B80ULL, 0x74FD70966B0590AFULL, 0x4D0301E04568EEE1ULL, 
            0xEDB40925697C804CULL, 0x1ED6E8C9BC0E6C95ULL, 0x9B3F770B987666F6ULL, 0xF04327EDA04D051CULL, 
            0x08FD2FD72C6A1DC0ULL, 0x5AAC7ED1CB15BF58ULL, 0x2B0D79DFD5EA3278ULL, 0x2124AE5FC80C8D0EULL, 
            0x41129FB90DC6545DULL, 0x3979F12AA11F9221ULL, 0x9A49370332CEFD2DULL, 0xA3919E6DAFF95FCAULL, 
            0x4BEA62C9EBAC79DAULL, 0x5D435B4A8F6301DDULL, 0x37D77CFE99FE7D83ULL, 0x94E9D8C21F19D298ULL, 
            0xDA112AC0BA41F801ULL, 0x07EF7911087A5CCEULL, 0x11639C4E61F9D734ULL, 0x4EAF37F55DFFC74BULL
        },
        {
            0xF0BE0D893FC5999DULL, 0xD396ED909ECE34E7ULL, 0xED8197ACCA08D4ADULL, 0xEE9289E03C06E1E0ULL, 
            0x63B8390997E973F5ULL, 0xE7D3C23800408B9DULL, 0x3724D2706DE83049ULL, 0xDA4A651BB58DA1FFULL, 
            0xC3B211EF7D736B82ULL, 0xEBF657AF8DCD8C95ULL, 0x2F5CBE4333A700A5ULL, 0x8D90562335769046ULL, 
            0x51FA9D212988BBA8ULL, 0xF3D2E7CCFD87DEBCULL, 0x984833783F0AFAC7ULL, 0x371588FE03632DD4ULL, 
            0x412DA40215DB33C0ULL, 0xFDEAE42812E9A8BDULL, 0x47BA8D5C72E070EDULL, 0x7ECF3D54BF232A8DULL, 
            0xB3596D01EEEF7AC8ULL, 0xF2425DE101744619ULL, 0x70F6AF8F478859A8ULL, 0xB5ADA59F47E77B98ULL, 
            0x23474D31C54E8B0FULL, 0xD0216497DF785078ULL, 0xF62B1F558C6B1793ULL, 0xC55E6D18B6361EDAULL, 
            0x34850C0EEB9C76E3ULL, 0x94431B41E941A778ULL, 0xF8140F3A459F1A8AULL, 0x6DFD9E9E10438223ULL
        },
        {
            0x99F35DD43388CF35ULL, 0xD0E5F673A61C5ACDULL, 0x65C2626355179C8EULL, 0xD6AEED1E3FD6D578ULL, 
            0x5400A3A55AC8B792ULL, 0x82057E5A88F71320ULL, 0x53D6D7C022AC4ED0ULL, 0xCD4360A8926E8125ULL, 
            0x3F92BF00A708C027ULL, 0x0BF8A7AA9940AB2FULL, 0x0C49DD2FF809D0F9ULL, 0x7BD2A9F430D044A6ULL, 
            0xFB912EB2B43181A3ULL, 0x0876535EAC25C5CEULL, 0x481D6586F0226A66ULL, 0x59F35CA88F08DE53ULL, 
            0xE519592C49E7C3C7ULL, 0xACCFB3A1185D023FULL, 0x6CB1D68BCCD00B3EULL, 0x669E41D322159852ULL, 
            0xAD68EFEFA9022835ULL, 0x61DBEB1AA385A729ULL, 0xF7AA2438F23E5ECFULL, 0xAC194EBF87648890ULL, 
            0x2972F0F5ABB5E290ULL, 0x4B037CF6EDFE56D9ULL, 0xE67D19F4816B0082ULL, 0x1BF6CCBE876844BEULL, 
            0x89AA392FD9FC41AFULL, 0x5963191C82F22A85ULL, 0x8AD8B1864626DEA7ULL, 0x277DF223D1790F97ULL
        }
    },
    {
        {
            0xC721E671E9D5C79EULL, 0xFBAD93D35A01CE5BULL, 0x0CEDB6EEA9B183BCULL, 0x693DEA1CC2591A9FULL, 
            0x55C3DE0D130D3C61ULL, 0x67BAD537D1EFF299ULL, 0x5140BC5D50BF9A24ULL, 0x53C237A2C3097284ULL, 
            0x6D24F81755E98400ULL, 0x7C547ECF5F52FAAAULL, 0xDA5FBD8441F5B6F4ULL, 0x73930C3C990D5FD9ULL, 
            0xDE12D1F7CEBDA96DULL, 0x7A5E86A1C46AAD9AULL, 0x3918FD34A380F4DFULL, 0xCB999B9AF8A4B77FULL, 
            0x7798D2C66741EAA3ULL, 0xDC718CDD58321A5FULL, 0x0A2B3FABE3C4AB9EULL, 0xE04E70189BAD7C53ULL, 
            0x5236386F82A83AA0ULL, 0xFC07C3E02AA5C486ULL, 0x3EA5AF8B9B1CF922ULL, 0x3C10A3F9C9D47132ULL, 
            0xB61D3D31E114B00AULL, 0x32C2E158B08A6E47ULL, 0xDB7BF51289A6B808ULL, 0x8AEEA556CD53FFEBULL, 
            0x76FC75AA95114137ULL, 0x03B6759A06C77E8FULL, 0x4857987707A10721ULL, 0xC10A17A9515F8AEDULL
        },
        {
            0x2D166BC1D57FACB7ULL, 0x5AB9E3AED971A00EULL, 0xD0B1E4DE008F10E6ULL, 0x1AFE1E32ABFB9505ULL, 
            0x810C44D2B568905FULL, 0x9E54414C7A06F30BULL, 0x2EAA759CA92C9182ULL, 0xB910B10563D917D8ULL, 
            0xD19ACD320890FC3AULL, 0x9F4DE9682A4777A0ULL, 0x6F7FE40F2637D275ULL, 0x0821A88236D0F568ULL, 
            0xA27921CDEF0C2A56ULL, 0x9E60D03B6A465896ULL, 0x26B7943F8B5C5662ULL, 0x574E3259AAAC69B5ULL, 
            0xFF5460D14F5BC133ULL, 0x280B98A1BB22FBDEULL, 0xD6AD6BA2B83F4EB9ULL, 0x8EA8E22C42261109ULL, 
            0xA65584A0416E5E96ULL, 0xF40FE6221ACBA418ULL, 0x81BB01435522D4ECULL, 0x9F8C18A58405F69AULL, 
            0x81060EE28953C6F3ULL, 0x2E1373BADAD70BBCULL, 0x9D6810EB746467B6ULL, 0x33A9DB5C26F1C8BDULL, 
            0xA01E280CE841DF37ULL, 0xF37AB72276E62B35ULL, 0xC2E739A341FDD6CFULL, 0x7BDA43733D17AAC9ULL
        },
        {
            0x8DD63944D114C6F3ULL, 0xF7407756CD496052ULL, 0xB009DFAC22283C38ULL, 0x5F6EFD78F405693EULL, 
            0xD4F5A9B5B7060CB7ULL, 0x51192E8028A7752BULL, 0x3F02E5F91190CAA9ULL, 0x6031AB354AC90795ULL, 
            0xE7C0A60E7085FD7DULL, 0xE3CB518608F1844EULL, 0x0CF74F6E5EF4C71FULL, 0x648A11099BB17B9DULL, 
            0x08BCB79E2BC4202FULL, 0xDB95E6F7CE5AEE16ULL, 0x2C7CA8FE6F13DE35ULL, 0x5832C545CB2E0527ULL, 
            0xA4CDC191ECEC6CA4ULL, 0x0EEBAF5B4215C290ULL, 0x7DE16A56B89954CEULL, 0x7EF8039B646F7FF5ULL, 
            0x1236B92AEF2A508DULL, 0xFCC90B6D51CD1E79ULL, 0xB53E0D6455670C36ULL, 0xE1585E72FA178958ULL, 
            0xB0F84BD5AC2CAFF5ULL, 0x6AF31EA4DDB95C9DULL, 0x1F4CCAE131CC072EULL, 0x011475E6478A697EULL, 
            0xFDDF307FEEFDCEC7ULL, 0xA23A0E0DCC07D8CEULL, 0xCACA40DC27B4F237ULL, 0x87F5AB0D6DE78C67ULL
        },
        {
            0x2AA409DFCE6E126EULL, 0x0B7618E89FDD534FULL, 0xF9698090070F292EULL, 0x9B3A18C065C6FFCFULL, 
            0x73905B80193A80B9ULL, 0x542E12BA8196CBEBULL, 0xB93FFC6CFF5EB588ULL, 0xED745CA39451B76DULL, 
            0x58DCD0A3DD18D362ULL, 0x577A1D1EB408153CULL, 0xB99828CE6BA5E768ULL, 0xD1E679061C71D22EULL, 
            0xCEE907AA47853E69ULL, 0x2F202C7A106274E5ULL, 0xE9954ED071BF6056ULL, 0xC23E87969C8D09A4ULL, 
            0x751661480EAF88E3ULL, 0x7E33EABD22B4FFDFULL, 0x99691DF68B8D7AE7ULL, 0x4CDA236EBB39FAC6ULL, 
            0x1759E57F5B0D3323ULL, 0xBD84B2D3D1A1FE4AULL, 0x192E473776540CA3ULL, 0xD387C5C5A849BEF1ULL, 
            0x3C1FC185282AB07FULL, 0x9F7CAC80EFA037BEULL, 0xEB184425564EE9BEULL, 0xEC7B4F1BF7E3E918ULL, 
            0x041AEEA1DB55A605ULL, 0xB1F5331F2A0A27D8ULL, 0x7DD69698C419A1F8ULL, 0xF74B7D9BDF665AA2ULL
        },
        {
            0x2DC9910DF5AD807BULL, 0x306A6AD29CA1FD1DULL, 0xA73AD8F7E17131FCULL, 0x2B3F73E44593A273ULL, 
            0x1D042A988391C5EBULL, 0x87D1F151551E065AULL, 0xC7C5592E5C04B52EULL, 0xDF0D4257019624C0ULL, 
            0x9EE22F423D50D031ULL, 0x233975DC31075D22ULL, 0xCA73C54A1C4A5D0DULL, 0xAC9E22AA720750E4ULL, 
            0x9191352449861F8AULL, 0xB7957AC5BEF1AD59ULL, 0x297AC0CA7DBB3442ULL, 0x813720866CF57E1AULL, 
            0x35774606D5C45240ULL, 0x6E82811A4CA12236ULL, 0xE6A471A93B9E66ECULL, 0xB2058976C2BA2DE6ULL, 
            0x6D883C2C51411340ULL, 0x14F0D95117525616ULL, 0x2A9C17459CA1F5B0ULL, 0xF0B4723702410D91ULL, 
            0x540184C58DAF848FULL, 0xB12A08DCEBFDF123ULL, 0xFB3CE55627F4C340ULL, 0xA942C3571415887EULL, 
            0x055D91A1FED1E782ULL, 0xAD81E6F86603D360ULL, 0xB4589D92C8F15691ULL, 0xCA0F6C832C5DFA82ULL
        },
        {
            0xBCC9C57AE344FA74ULL, 0xAA0DEC76B41B79FDULL, 0x32796E2AB9E909AFULL, 0x453811DC4ABE55FDULL, 
            0x47F441BD6EC493A0ULL, 0x3A6B6106C4B39A4DULL, 0xC1B8BDD7815AE48CULL, 0x2A1EFD2891D05A37ULL, 
            0x1B3F9EACA3582130ULL, 0x05FAA1A8C834CBAEULL, 0xD69229B7C1A162BEULL, 0x54683C01023C5B3BULL, 
            0x8D803D34D3DA3349ULL, 0xE03E3BD87188D373ULL, 0x3C862ADF92458AC4ULL, 0x800F95964303B821ULL, 
            0x82CC26427ADA42A8ULL, 0x7D2DFD4274990D37ULL, 0xF7329F2AD790B84FULL, 0xECAB12FDED7E27CAULL, 
            0x84544C3504B9CE6BULL, 0x242DAFA5704F986DULL, 0xFF172C1A435CE703ULL, 0x54E8CEC5AE75DC05ULL, 
            0x3BE46C22F79CD17CULL, 0x675C5EE2C03B1F37ULL, 0xF24726A38B2A801EULL, 0x184D9EA5B81F1C19ULL, 
            0x5A54149B35486149ULL, 0x5BBC9E2CC7FE47D6ULL, 0x82A8E0C0475F970DULL, 0xC38389BED445B767ULL
        }
    },
    {
        {
            0x1AF8E2367895AD7BULL, 0xD080049F4D8581E1ULL, 0xA4FD125457ACA5DBULL, 0xF0E0542CFE42822AULL, 
            0x6ADA416DB66F5EBCULL, 0xCFFCF0415036DD45ULL, 0xD0C5473B9FA8B131ULL, 0x10B01331999C0ACCULL, 
            0xA1C06CFBE3EF24F1ULL, 0x9DB0B3CAA5DD0A42ULL, 0x0924426717362073ULL, 0x34747708D0E70476ULL, 
            0xFCD4131B51C52691ULL, 0x6F45466D7F9BD551ULL, 0x49426FEE164BF458ULL, 0xF823B7A51BE780CCULL, 
            0x9074BB6C6F9905ABULL, 0xD9E022A9E4C87C75ULL, 0x640D924403C1BD35ULL, 0xD7035BBB0331DD97ULL, 
            0x4CE176D6C90A7FDAULL, 0x3D911CFF5BE7D8D1ULL, 0xB9014F19180354F6ULL, 0xBD4BFCCA41730DC4ULL, 
            0x7B88444EE6F0D660ULL, 0xEA9D2F7BC190E9EDULL, 0x16A0BA59E2B0CE40ULL, 0xDAA8E880FE540D8DULL, 
            0x9BE67F6B37E08802ULL, 0xDA17694DB1F24F38ULL, 0x0A44AAABB15D508EULL, 0x3D80A867B6325FB3ULL
        },
        {
            0x0C4328DE57AE4BF5ULL, 0x4FB3CFCC4D8FAAF3ULL, 0x04ABEC38D16BF8B8ULL, 0x9E144CFCF575E403ULL, 
            0xD9657F0FF429A058ULL, 0xBD2F99B48B017C09ULL, 0x69595CA0C8339FC1ULL, 0xC228CF06B9D81CDFULL, 
            0x1341AD0F15F6C1F7ULL, 0x09D990B7F38AFCE5ULL, 0xBE876F1DC71CEDF9ULL, 0xBCE251EE543AA981ULL, 
            0xA2CEC0F1FC397F9BULL, 0x59695CF3EF7A5970ULL, 0xD97787AF9328FDBBULL, 0x4725CE3915BB2CACULL, 
            0x7D819D152D13C769ULL, 0x4550BE3276BC3181ULL, 0x3CD3C412E6AC79C9ULL, 0xE51512669E4A04BEULL, 
            0xB0FB2881E7C4D4CEULL, 0xFD85AE5293FB1ADDULL, 0x3C603AFA27358DDAULL, 0x7E4A2A3F11566A50ULL, 
            0xA9212AD988ADA4FDULL, 0x7B75437F333447CAULL, 0xA885D0AC40FAA4BDULL, 0xB1587637631488D6ULL, 
            0xB59748D3F6A17E35ULL, 0x6824118F0E41379EULL, 0xFA856C342A132CD9ULL, 0x9FABE942E5DB22BFULL
        },
        {
            0xC0641B32B99CC6C3ULL, 0xC96A5DFC9927B618ULL, 0x328B1AF48A45E77CULL, 0xE83CE57E9F812C45ULL, 
            0x61717F2F4707D77CULL, 0xA0559C5826E6FE27ULL, 0x472BAFF346E3292FULL, 0xE9A2CE4C97B201E3ULL, 
            0xD807F34B2C4F501CULL, 0x3C81483925581AA1ULL, 0x3470CAF77F4F0F5FULL, 0x08B09A257F4CB371ULL, 
            0x53B3A9515C9A837EULL, 0x19409DD44927A4EAULL, 0xB9D4C8F635ADDDAFULL, 0x363B4346E3C4C012ULL, 
            0x932DCE13B6B700DAULL, 0x9DF83AD9FF02D3F9ULL, 0x60764DB990D6AA13ULL, 0x1E06F50A06FBD517ULL, 
            0xEAA3DC8C060A8C87ULL, 0xFC39043E981E7400ULL, 0x7BFA5207DB17AAF5ULL, 0xA142C68DD8CB36B4ULL, 
            0x761155EFB81D54F6ULL, 0xCE7D3F1E233CF75DULL, 0x380DB2AC60F488D8ULL, 0xC40CF27618F22007ULL, 
            0x53F6F30BA5295A3FULL, 0x657D6F00A292BEBEULL, 0x258E87FA95092BF1ULL, 0x1B3D1ACEB336BE06ULL
        },
        {
            0x11A92805D10B1C12ULL, 0x8A2840942F89D310ULL, 0x0FD97751C8799C50ULL, 0x6A3C5E4F52B53DA6ULL, 
            0x0144BCAA6F187987ULL, 0x1485E5E7E895ADAFULL, 0xA25926B4E48CDFCFULL, 0x014622556188CD45ULL, 
            0x27C14AF796A7501EULL, 0xFFE9E886F1D17835ULL, 0x4D3A09FAC6B7E21FULL, 0xDBDEE3CFF8102443ULL, 
            0x2BB077269598506FULL, 0x2BFBD79376D004DFULL, 0x2A440574383DCD20ULL, 0x5D7074722FD49EFAULL, 
            0x373F5FEE4E09B4ECULL, 0x66F0AACA3A31A7AEULL, 0xC82A9A3362C295A2ULL, 0x5D27371AE3134978ULL, 
            0x62F990F8C6654CB2ULL, 0x9FA99828281C5AC8ULL, 0x053E5FF2EEB53F91ULL, 0x0178BFAF459F47BCULL, 
            0x1AB2922FB42012FAULL, 0xB906DCBB27274A94ULL, 0xF898F15D4155B282ULL, 0xCAC206AB11D134C2ULL, 
            0xC5BF2640CBA6B3A3ULL, 0xC0B447C108394225ULL, 0xE2B83474E0224A00ULL, 0xB4E0AF8BE978CF08ULL
        },
        {
            0xB46995C717F3D018ULL, 0xCF834C6EA43C24DFULL, 0x77913E1B853D753FULL, 0xC4AE7B7B967C8643ULL, 
            0x3FD7903738CF3057ULL, 0x7A128DCA191001BDULL, 0xDB95A490B597EC85ULL, 0xF7D80B1E8C12B4BEULL, 
            0x83EBBBD8280BB586ULL, 0x471EAAADEC41A6D5ULL, 0xD205D698E4FE5115ULL, 0x9EA6C42144FEA4A5ULL, 
            0x354189C471770189ULL, 0xF1C0E9FAA4AF24ADULL, 0x9C3539CF7EB13825ULL, 0x5FB4CC87093CB202ULL, 
            0xD8DBE4B7F195FAFCULL, 0x26F6BCD0C8941764ULL, 0xBC1D38BECF99E302ULL, 0x387B7A1E772F7214ULL, 
            0x3DC40EF48CE028CDULL, 0x5B33F4FA5769A545ULL, 0x1A59A510A14B516FULL, 0x3DFE7D552CCEF056ULL, 
            0x14AA7B0C5D7B645BULL, 0x0E90AD2E91F082B7ULL, 0x5E42761F13BF56B8ULL, 0xAB34F4F296C173A9ULL, 
            0x2DD8AC6137D824B5ULL, 0x5924F94D531CF223ULL, 0x0F02301F54F21C11ULL, 0x391A80516BB4995FULL
        },
        {
            0x365675ACFEC9F59DULL, 0x767D5C640A221C50ULL, 0x9B69647BC18CB427ULL, 0x3B674377F0A5AC53ULL, 
            0xBB895733CC8617C3ULL, 0xDC6429EEF56FF309ULL, 0x57E33948A9AD36A8ULL, 0xAA1E6164D008736DULL, 
            0x173D006181EB2C47ULL, 0xB271828C8C46407EULL, 0x1378F50848FC2971ULL, 0x467A48FDF618018CULL, 
            0xFD286051FB064346ULL, 0xBDB9C64443594906ULL, 0x8476248D0D84F081ULL, 0xEA081B5EB476B1DDULL, 
            0xCAB9F1CC891AF0ADULL, 0x728A90F4AC4275B5ULL, 0x28C99524BD2C85CBULL, 0x9A87357A64CA9100ULL, 
            0x27F1F980C2EA3BF1ULL, 0x5000B3C3D8957106ULL, 0xD58D3A21CA9D7562ULL, 0xC205352B3C01FE6FULL, 
            0x2F11FB15B596B3BAULL, 0x3B36B0B5DF39C359ULL, 0xB86DD844DE65385DULL, 0x865DD3AAEB069BCAULL, 
            0x3F906CC88DCCCFA9ULL, 0x3BE7D26802FDDE15ULL, 0xE00E98488E65CE5DULL, 0xECFF7B301EB3F81AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Altair::kTwistConstants = {
    0x035212F16EEC8451ULL,
    0xBFC5FBB3B2211B32ULL,
    0x66AE507A27673F13ULL,
    0x035212F16EEC8451ULL,
    0xBFC5FBB3B2211B32ULL,
    0x66AE507A27673F13ULL,
    0x949BB881AA000C6FULL,
    0xCB18D64F00C3BA92ULL,
    0xA6,
    0xE6,
    0xBE,
    0xD0,
    0xC5,
    0xF3,
    0x3B,
    0x5E
};

