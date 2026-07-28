#include "TwistExpander_Sirius.hpp"
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

TwistExpander_Sirius::TwistExpander_Sirius()
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

void TwistExpander_Sirius::KDF_A(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Sirius_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Sirius_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Sirius_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Sirius_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Sirius::KDF_B(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Sirius_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Sirius_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Sirius_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Sirius_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Sirius::KDF_C(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Sirius_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Sirius_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Sirius_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Sirius_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Sirius::KDF_D(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Sirius_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Sirius_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Sirius_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Sirius_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Sirius::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF64AF755B061A3E4ULL;
    std::uint64_t aIngress = 0xEF8FB66C1D688ECDULL;
    std::uint64_t aCarry = 0xBFF28A3ED08FBD2CULL;

    std::uint64_t aWandererA = 0x85EC0C55875E3F0CULL;
    std::uint64_t aWandererB = 0xADFEC1F0307BED60ULL;
    std::uint64_t aWandererC = 0xEEF55D833EA268CFULL;
    std::uint64_t aWandererD = 0x9AC67B6C4794719CULL;
    std::uint64_t aWandererE = 0xB6101C5BC657D247ULL;
    std::uint64_t aWandererF = 0xC7BBEB259182E86AULL;
    std::uint64_t aWandererG = 0xD508C9E719C3E31BULL;
    std::uint64_t aWandererH = 0xE9B7D9AA6AF6570CULL;
    std::uint64_t aWandererI = 0x878D9FEE123E3AC2ULL;
    std::uint64_t aWandererJ = 0xEFD6D90B1BD98643ULL;
    std::uint64_t aWandererK = 0xECA5C0DD1A9FBE35ULL;

    //
    // KeyRotate A
    //
    aPrevious = 0xDE61D62D0643D56BULL;
    aIngress = 0xAAEF3A194F615D06ULL;
    aCarry = 0xEBCEB0891DDF9C5EULL;
    aWandererA = 0xCA4DA174966AE851ULL;
    aWandererB = 0xD7A15B9ACC1E3248ULL;
    aWandererC = 0xCCD81A8AB16466C6ULL;
    aWandererD = 0xD77DE10CAD5D2CA9ULL;
    aWandererE = 0x97391BEECBC5BEF5ULL;
    aWandererF = 0xA2E09F07A4BDE523ULL;
    aWandererG = 0xA4D71A89B4EAEF1CULL;
    aWandererH = 0xEAB5AC7B89F223CBULL;
    aWandererI = 0xF074B0B336CB7440ULL;
    aWandererJ = 0xD84A9DF052ACEEDBULL;
    aWandererK = 0xC9EA3C09598CD7B7ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateAConstants), &(pWorkSpace->mDomainBundle.mKeyRotateASalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0x9A74AAAF8E1399B2ULL;
    aIngress = 0x872FCAB254C171DCULL;
    aCarry = 0x815CDD560EDFF654ULL;
    aWandererA = 0xB6510D2E8B657F79ULL;
    aWandererB = 0xF683D6BC06C9EFB3ULL;
    aWandererC = 0xD4069AC9E230A94AULL;
    aWandererD = 0xED4990D859EEB6DBULL;
    aWandererE = 0xB2C2131B93E87D91ULL;
    aWandererF = 0xC1D67F76C8AEA256ULL;
    aWandererG = 0xDB943757AB1EF7CBULL;
    aWandererH = 0xE9CCDDFD09591351ULL;
    aWandererI = 0x9ADF80C858468EE7ULL;
    aWandererJ = 0x819046657759EB8AULL;
    aWandererK = 0xBA1423931A12E915ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xE618380155C69C68ULL;
    aIngress = 0xEAD55A8CBFFD8BBCULL;
    aCarry = 0xEC8517F3D91B9419ULL;
    aWandererA = 0x9951B7900047629CULL;
    aWandererB = 0xD7241C7BF4887125ULL;
    aWandererC = 0xEED15C2C12C99ECDULL;
    aWandererD = 0xED1048E8D8D93FBBULL;
    aWandererE = 0xC53DF226EE707854ULL;
    aWandererF = 0x998A994E177E7DFCULL;
    aWandererG = 0xBB23F87AB91B440DULL;
    aWandererH = 0xE2AE58597FCDB416ULL;
    aWandererI = 0xAA13053303634792ULL;
    aWandererJ = 0xC967BAF24EE4842EULL;
    aWandererK = 0xE8CFC31B5F636755ULL;
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants), &(pWorkSpace->mDomainBundle.mKeySpawnASalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeySpawnAConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xA4EA1CDD39388524ULL;
    aIngress = 0xCFA24132CCD20256ULL;
    aCarry = 0xB63F7FEF699D85DBULL;
    aWandererA = 0xE167FB95C0BAA6F4ULL;
    aWandererB = 0x852FC79D5A3EC2C4ULL;
    aWandererC = 0xA6FBB7D50A7A87CDULL;
    aWandererD = 0xA061EB4D23440BD9ULL;
    aWandererE = 0xB961EE26B29C535FULL;
    aWandererF = 0xCBE981F3C7DED407ULL;
    aWandererG = 0xD99243DA86F9718AULL;
    aWandererH = 0xC4B4208D16EA1B1CULL;
    aWandererI = 0xAB0EC2B0FCCACA20ULL;
    aWandererJ = 0x869B4E5FC4D95FFEULL;
    aWandererK = 0xACE8442402F36020ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnBConstants), &(mDomainBundleInbuilt.mKeySpawnBSalts), pSnowLaneB, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xE2CE2499A2695CA6ULL;
    aIngress = 0xC50049A75A77ED1AULL;
    aCarry = 0xE5CDF78514FA15DAULL;
    aWandererA = 0xD1909F044EE6C7C9ULL;
    aWandererB = 0xC9475FCCC7E890E3ULL;
    aWandererC = 0x9112E60A056782A7ULL;
    aWandererD = 0xE4530DC85E1E4DD6ULL;
    aWandererE = 0xB69A92A1DCC8CDE9ULL;
    aWandererF = 0xF7CBE323A2BE363BULL;
    aWandererG = 0x89537D00E196E78CULL;
    aWandererH = 0xB5A9C1CB661B0DFCULL;
    aWandererI = 0x92EAD78575A63DB2ULL;
    aWandererJ = 0x80144C371D2B7B2EULL;
    aWandererK = 0xAE470B969AE2E996ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mTwistSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xA138F19A5C23D6E7ULL;
    aIngress = 0xBDAF5C6C414F101EULL;
    aCarry = 0x96B8DAC9276985DDULL;
    aWandererA = 0xB3B08EE63FA3A258ULL;
    aWandererB = 0xB733B020D99A508FULL;
    aWandererC = 0xABD3A7F0DCFA2E9BULL;
    aWandererD = 0xC48ADE680993F025ULL;
    aWandererE = 0x9E76DADE8297DA2FULL;
    aWandererF = 0x876769DD6A377967ULL;
    aWandererG = 0x878576B52A19F1A8ULL;
    aWandererH = 0xE3D3774590304DCEULL;
    aWandererI = 0x824E41287A1BDB31ULL;
    aWandererJ = 0xB914D0147D54C9B0ULL;
    aWandererK = 0xEC219DA0D77547D7ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mSeedConstants), &(pWorkSpace->mDomainBundle.mSeedSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mSeedSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneB, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0x8277D7F16E979613ULL;
    aIngress = 0xCB81F8C91A3C8B0BULL;
    aCarry = 0xCD1A88D262B15ACCULL;
    aWandererA = 0xE1B6F290DBCCC011ULL;
    aWandererB = 0x8200E3E76C751211ULL;
    aWandererC = 0xD2C383B391BA01B9ULL;
    aWandererD = 0xDFCA84CE66A07404ULL;
    aWandererE = 0xE4E055AA1D7E382EULL;
    aWandererF = 0x871A95EF9BCA669EULL;
    aWandererG = 0xDC6A9B06A77654C1ULL;
    aWandererH = 0xD4D124D333D69543ULL;
    aWandererI = 0xFED3812E73EBA0B0ULL;
    aWandererJ = 0xEF33828B971435DAULL;
    aWandererK = 0xC62480FB60D37DBFULL;
    //
    TwistExpander_Sirius_Arx::SEED_A(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Sirius_Arx::SEED_B(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Sirius_Arx::SEED_C(pWorkSpace,
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
    TwistExpander_Sirius_Arx::SEED_D(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Sirius_Arx::SEED_E(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Sirius_Arx::SEED_F(pWorkSpace,
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
    TwistExpander_Sirius_Arx::SEED_G(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Sirius_Arx::SEED_H(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Sirius_Arx::SEED_I(pWorkSpace,
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
    TwistExpander_Sirius_Arx::SEED_J(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Sirius_Arx::SEED_K(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Sirius_Arx::SEED_L(pWorkSpace,
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
    TwistExpander_Sirius_Arx::SEED_M(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Sirius_Arx::SEED_N(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Sirius_Arx::KEY_A_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Sirius_Arx::KEY_A_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Sirius_Arx::KEY_A_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Sirius_Arx::KEY_A_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Sirius_Arx::KEY_A_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Sirius_Arx::KEY_A_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Sirius_Arx::KEY_A_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Sirius_Arx::KEY_A_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Sirius_Arx::KEY_B_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Sirius_Arx::KEY_B_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Sirius_Arx::KEY_B_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Sirius_Arx::KEY_B_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Sirius_Arx::KEY_B_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Sirius_Arx::KEY_B_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Sirius_Arx::KEY_B_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Sirius_Arx::KEY_B_H(pWorkSpace,
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

void TwistExpander_Sirius::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x859FA2D92C17E8DFULL; std::uint64_t aIngress = 0x8D3BA721AB3F7E33ULL; std::uint64_t aCarry = 0xAE8E81E585FBD843ULL;

    std::uint64_t aWandererA = 0xBC71079AD4EC964BULL; std::uint64_t aWandererB = 0xA69EA8E8A7E5524EULL; std::uint64_t aWandererC = 0xC8ED41066EADCB66ULL; std::uint64_t aWandererD = 0x9DC61011D90443A2ULL;
    std::uint64_t aWandererE = 0xC78F024C23646565ULL; std::uint64_t aWandererF = 0xDA931C5935B81BE0ULL; std::uint64_t aWandererG = 0xDBEF644A65496BD2ULL; std::uint64_t aWandererH = 0x9ACE74D74C4E967CULL;
    std::uint64_t aWandererI = 0x951F60F59BB84E9CULL; std::uint64_t aWandererJ = 0xE01FD05DD10346C5ULL; std::uint64_t aWandererK = 0xC62989874094FFDDULL;

    // [twist]
        aPrevious = 0xEF63D93451DBFD37ULL;
        aCarry = 0xEA1324DC6A040325ULL;
        aWandererA = 0xAE0865183C621A0AULL;
        aWandererB = 0x89FC507C60830C9CULL;
        aWandererC = 0x82695E06C1A8ADEFULL;
        aWandererD = 0xC2E37C2E1582C2ACULL;
        aWandererE = 0xE49E610A1B307F3FULL;
        aWandererF = 0xF107DF1C3E6201CEULL;
        aWandererG = 0xFABD3C038B9E562DULL;
        aWandererH = 0xF5E8338E4B5BB3C3ULL;
        aWandererI = 0xDE1D3E1F321E63BEULL;
        aWandererJ = 0x9FC8647C7DF4653EULL;
        aWandererK = 0x8E3994D30FC65E5CULL;
    TwistExpander_Sirius_Arx::TWIST_A(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Sirius_Arx::TWIST_B(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Sirius_Arx::TWIST_C(pWorkSpace,
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
    TwistExpander_Sirius_Arx::TWIST_D(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Sirius_Arx::TWIST_E(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Sirius_Arx::TWIST_F(pWorkSpace,
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
    TwistExpander_Sirius_Arx::TWIST_G(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Sirius_Arx::TWIST_H(pWorkSpace,
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

void TwistExpander_Sirius::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Sirius_Arx::GROW_A_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Sirius_Arx::GROW_A_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Sirius_Arx::GROW_A_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Sirius_Arx::GROW_A_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Sirius::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Sirius_Arx::GROW_B_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Sirius_Arx::GROW_B_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Sirius_Arx::GROW_B_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Sirius_Arx::GROW_B_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Sirius::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 31 of 33
    // Exploration cases: 0
    // Structural maximin 511 / 674; family total 15939
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
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4098U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7969U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3648U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3828U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1600U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1555U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 47U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1870U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1690U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1735U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1465U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 92U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 31 of 33
    // Exploration cases: 0
    // Structural maximin 510 / 674; family total 15925
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
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6979U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7159U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3378U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7069U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 925U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 970U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1240U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 790U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 610U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 835U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1060U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1105U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Sirius::kKeyRotateASalts = {
    {
        {
            0x3B892F55E544F85DULL, 0x18AFC50B93288FD7ULL, 0xE443E947ECA50322ULL, 0x4F995FDF4C016927ULL, 
            0x5C09FD3004F744D8ULL, 0xDE071BD597BC943CULL, 0x99845897BA86E117ULL, 0x2185028495690DBAULL, 
            0x2255DDE2FA485DBBULL, 0x17C4635AE8812B55ULL, 0x9416115F8F1E04BFULL, 0x83C75EBAE12662E9ULL, 
            0xD7B6284CF966B205ULL, 0x2054BAE57DCF4355ULL, 0x5C7755F15EF8CF26ULL, 0xCECBAEC753523CDFULL, 
            0xFF78DBC2580CFD9AULL, 0x77D0EE4703827971ULL, 0x7875E7564FB949DFULL, 0x0BE4911497EA522AULL, 
            0x01F3795F8105D7F7ULL, 0xC00CA4C3CCF0340CULL, 0xF9A2A7EC43A85AEEULL, 0xF49F58B605ACA151ULL, 
            0x020DA21D36B94696ULL, 0x558BE3EA5A96D709ULL, 0xCB4774105D0BAB33ULL, 0x22C567A2BF315B14ULL, 
            0x80485805FE18C6D9ULL, 0xA98C499AF1AA6E5AULL, 0xB2131946927302BCULL, 0x61C451C5FDCFA5C0ULL
        },
        {
            0xA4135087EE48585AULL, 0xE39E6AA1EA649F80ULL, 0x8F977D8EE032C8B8ULL, 0xB181FE803EF2E485ULL, 
            0x7711100187F002B1ULL, 0x7BC51C87D52999C4ULL, 0x146360FF9E16D863ULL, 0xFEE095D632F751BBULL, 
            0xCC0F0AD80898FFBFULL, 0x17A7F86FFE3FD507ULL, 0x5459E646C61A4E20ULL, 0x1026254CAC096663ULL, 
            0x2A98713B4313B824ULL, 0x283C2EEC2169B903ULL, 0x158F53B079146FE7ULL, 0x1B4E7F8CFA4106C5ULL, 
            0xC42F7905CE54F560ULL, 0x775137471F406AB3ULL, 0x00E2B8F7F081E79FULL, 0x7A911569681D5CE1ULL, 
            0x383BE1D1105E69CCULL, 0x5FEFED17978861ECULL, 0xC7ACBB2F9A57CC6EULL, 0x8DC181E44CD2CF82ULL, 
            0x439316595B360C1AULL, 0x04FD5B0F013AB944ULL, 0x6C64C8F05414D36CULL, 0x5C612F8F3847F358ULL, 
            0x43627F798A90E90DULL, 0x82EB129DD4B385E8ULL, 0x9E8FE78DF6B12548ULL, 0xA000E286956191F5ULL
        },
        {
            0x80CFBCBF919DAD7FULL, 0x6CB47B1B04B14ED0ULL, 0xB41F95F6CE743CF2ULL, 0xE85E9B8489327B87ULL, 
            0xF79AD2E9B3AAEC14ULL, 0x3EB1A8B76A32B956ULL, 0xC14E7F9CB92A9169ULL, 0x5A724281765CED65ULL, 
            0x7D9B69E023AE6BF2ULL, 0xACE8B0B3FAB6881DULL, 0x82035E7049AE8BBFULL, 0x38DB41C39FCC417EULL, 
            0x0300445A112DBD32ULL, 0xCD42812417534CDEULL, 0x1E4B75520E8895F4ULL, 0xDA2D809A6D167C4CULL, 
            0x48D4F6F2F2054795ULL, 0xBB4BB34863B59A8CULL, 0x696215738CB008F4ULL, 0xBBA8BE64C6F0F3AAULL, 
            0xDE4DB1A023FDDDF3ULL, 0xFCB53AA4585F3A74ULL, 0x0FD558ED15BC82C7ULL, 0xA9214A88EBDCC92BULL, 
            0x404E4D87AD10B908ULL, 0xAEF7921200BFFE72ULL, 0x6A5F203A5444C4E0ULL, 0x49BC3A8F918538F1ULL, 
            0xC5373D6F5446435AULL, 0xA8E24FBC472DAEDEULL, 0x400ED0729926857AULL, 0x62350B9A674D58C7ULL
        },
        {
            0xC4AF169E592CA78FULL, 0xE89F9683D79AA69EULL, 0x2C39140995CDD638ULL, 0x946DB1CC3AC5B415ULL, 
            0xE2C5781BFA3C17FBULL, 0xF9487DA1A16C8566ULL, 0x1AE8E017240A247CULL, 0xAD399DE6712C99AFULL, 
            0x5E789C64793F4D16ULL, 0x6B2375524284EE38ULL, 0xD02DABD9A25F5234ULL, 0x49A4FEBFFA1C94A9ULL, 
            0x4FC0A30877AFB36CULL, 0x7D22E9340509BC80ULL, 0xFEDB4E1A456AC6B8ULL, 0xD0768B036F5A7F3DULL, 
            0x6595D8625E91F68DULL, 0x8BE4D0DF11256876ULL, 0x9E868171390EA21AULL, 0xCA3DD5468CC4380BULL, 
            0x73A0D45FCEB9486CULL, 0x5A79860669CF4405ULL, 0x3B90AE73DE9D7B75ULL, 0x07B827CFEF94D533ULL, 
            0xE0E91DE44405BF85ULL, 0xB74D9720E28F9557ULL, 0xB59BAD75BCC9F51CULL, 0x1ED7530FC88BD2D2ULL, 
            0x9A1DF5BACEB0D98BULL, 0x4B5DCA8D6281E714ULL, 0xF705087B5E39B824ULL, 0x5BE2436FFE6DCE50ULL
        },
        {
            0x7F95FA18CA6BF5C8ULL, 0x90781542EF36D4CFULL, 0x695752153893C8F6ULL, 0xF0CECB6FFC5AEB7EULL, 
            0x6EA2FF3ECDBB9D1BULL, 0x93E6D416A8AB0462ULL, 0x61BBD6F1F5FBDBF1ULL, 0x064E65F6F11A3ED9ULL, 
            0x64D5BC71E2959187ULL, 0x976C8F52B688C6CDULL, 0x7998732819F839C9ULL, 0x7F3889284372F869ULL, 
            0x481ECDD92C3913C1ULL, 0x71D6C2A99C108121ULL, 0xECE9A8F8A44FDBB0ULL, 0x95B81C1E5169AC77ULL, 
            0xF3863E0BA77E5838ULL, 0xDA92DF354053A16FULL, 0xD6662875D1D557D3ULL, 0x0698A1D661AEBE4AULL, 
            0xA9E49FB704D19235ULL, 0x8903673D9ED642FBULL, 0x5AE4F0D67CBA2890ULL, 0xC9D6AD7FB471AB05ULL, 
            0xBDF5047D7041D7CEULL, 0xCC91B4DE1B0B15A7ULL, 0xB66D025103BECFE7ULL, 0xC9550F1169212BEBULL, 
            0xA184550FCDE69732ULL, 0x64C5292FBA478883ULL, 0x7768F9586C5FCE68ULL, 0x47A0AE583078D3FBULL
        },
        {
            0x545D46EE996FCAC2ULL, 0x196D300944B0D343ULL, 0x49F4224DB8935BD5ULL, 0x12F61D397F7367C3ULL, 
            0xDA286EE06BBF83A1ULL, 0x64F72B0816F53A25ULL, 0x1A2169AC9B64187AULL, 0x6AEEC84C8F6D3B22ULL, 
            0xD967144E017A2D49ULL, 0x82990ADF7EE4120CULL, 0x965125CB72A32455ULL, 0x68280DB9EA88A9E5ULL, 
            0xA76F864981A07214ULL, 0xDB8AB314AC973566ULL, 0xB159DFA9808EBFECULL, 0xFD84A770A3D68DB6ULL, 
            0x82614E7C7E2AFCE1ULL, 0xD8AC63B9D2C4730CULL, 0x00800E27CF555140ULL, 0x2B7E759FA72E5AA1ULL, 
            0xBADBB49E8ACF2DFFULL, 0x2A242BFDCE88814EULL, 0x2E91C986CB5F4120ULL, 0x2D826243F806F764ULL, 
            0xF356C7453893A2D0ULL, 0x35DA3D2C5822C9CBULL, 0x2F533EC8366723ADULL, 0x81D8CA77DAEF703CULL, 
            0x937A7FCF24E40B11ULL, 0x0DBF46978ED7EDCCULL, 0xE6EC7AA3CAEB0901ULL, 0xD3F4DF8DF47AB28BULL
        }
    },
    {
        {
            0x21091253314F791BULL, 0xA922616435A1E898ULL, 0x46A3287103B04EB1ULL, 0xDB84370108EB208AULL, 
            0x43FE9795D482BF7EULL, 0x5B1D220E1D7BF212ULL, 0x77AB11D2C05D38D9ULL, 0x0E309C0691A7E92BULL, 
            0xF9C5211AD2AA71BBULL, 0xA9B0EFDF0F6DAA5AULL, 0x79E461603AFDDCE3ULL, 0x5AAC6F04E1EF3B23ULL, 
            0x2372A264B78B812CULL, 0xBAF3BAD0A539B043ULL, 0xDA4117B7ED241925ULL, 0x7EAF1AD595CBC684ULL, 
            0x72EB0769EB6A91A4ULL, 0x2D8752A416A71961ULL, 0xE9DFDB499AFCAFF1ULL, 0xC1D210B50763FC60ULL, 
            0x973996705C4BC705ULL, 0x353EB9D7060BA6FFULL, 0x503E176DF2C6E46CULL, 0x1BF4ADD77AFF6E59ULL, 
            0x74281B2341A484F0ULL, 0x3FA5B52416942515ULL, 0x6271EEAAF43AD2BBULL, 0xA05C9C3D6805BF92ULL, 
            0x9B39A7344E06C2F5ULL, 0xE1562D6D1291A598ULL, 0xF7EB3CD61BAB3156ULL, 0x6FDBEC1FC2F44B75ULL
        },
        {
            0xCE259F8AA2E6AAC4ULL, 0x573FC306797A7417ULL, 0x54F21DAB4BEB7E88ULL, 0xF9DBAF87CD183858ULL, 
            0x0B44BC7B1A7C9DCAULL, 0x65FD73759F291A94ULL, 0x581C108DFD5AB45EULL, 0x9B4FC2AE3330F58FULL, 
            0x5BEE9FED5080F671ULL, 0xEF8543E3954DB0A5ULL, 0x9522D8A9263526EDULL, 0x82A8C82BB309CECBULL, 
            0xA620BE7F82CA1FF8ULL, 0xE4F6A623A3764594ULL, 0x4A9F897846A2DFD2ULL, 0x05F71756A91D95B7ULL, 
            0x1203F19CC5AD3518ULL, 0x2C75BDAB18C5AC5EULL, 0x2EBC44C58B80836EULL, 0x49B946355F79C4A0ULL, 
            0xFA58FAF74D062F98ULL, 0xE54756CEA9370452ULL, 0xF7A63FB1A92C76E4ULL, 0xC277F19CEAA4F28AULL, 
            0x85B067BBA9782571ULL, 0xA634476852AF2264ULL, 0x7337EA8E4011F104ULL, 0x9ED4B9D57107AA22ULL, 
            0x7BB5D15FDDAE1766ULL, 0x80F7FAF8FFD8DB48ULL, 0xC939E24491F0B82AULL, 0x9007BB92EA3ACAB3ULL
        },
        {
            0xE4A7F4E7AE24CC02ULL, 0x469EB31286459599ULL, 0xADAF5E24D062CC9AULL, 0xD1EF7554D6768D06ULL, 
            0x774102CB870E22BEULL, 0xBAE6879F54D25888ULL, 0x45CC04F1D9F05995ULL, 0x888F554F992A9B31ULL, 
            0x78F2C52AF4AAAC3CULL, 0x38906F177007FAA3ULL, 0x159A4F0D3144B24DULL, 0x70DC0B02BD003EE1ULL, 
            0x04A237668F4BEC7BULL, 0x1638ED83E491E32DULL, 0x76645AC03E0CC887ULL, 0xFFE0717639E486D0ULL, 
            0x4CE111250B9DF963ULL, 0x9FC1AC43910B8446ULL, 0x55E52679E891C224ULL, 0xAF7A48B391296998ULL, 
            0x86BBC642FDC678A4ULL, 0x0EFA97C8F0674C7BULL, 0x7162BF06602A59B6ULL, 0xC1524544C03B8D14ULL, 
            0x93235675FCB7F69AULL, 0x7B4ED2E02C210EA5ULL, 0xD5404BD3A0987712ULL, 0xA39C26261BDEA200ULL, 
            0xBD2F559F48D10520ULL, 0x9A40B4655EC98494ULL, 0x591198E9556FCFA5ULL, 0x99F39AEA5741623BULL
        },
        {
            0xACFC3CE036B50AC4ULL, 0xA1034B691F8727FFULL, 0xB168D528D3E7FE25ULL, 0xC17A6FE36E74ADB3ULL, 
            0xAA81A0C570094447ULL, 0xAC114D8041650F99ULL, 0x8EA3B6960AE98968ULL, 0x6780E9B66F8EE30DULL, 
            0x0DA7B44F32DC0DD3ULL, 0x6D59F676EFE590B8ULL, 0xCCD82DB17989CA27ULL, 0xFF4F16CEA0CD4DDAULL, 
            0x9463208A54A2B074ULL, 0xBBE1DB0A3991D4A9ULL, 0x7C0877995413BA9DULL, 0x5D40A8E8C893EEBEULL, 
            0xB65B3DF3AF7C1D16ULL, 0x6EA4E15D4045D725ULL, 0xF8F9991CB1363AF1ULL, 0x223099BDD6B2363AULL, 
            0xBCF7799DF9EBF096ULL, 0x6D15C41593018166ULL, 0x210EDCB06A82AC96ULL, 0xE7269B22949EFD2BULL, 
            0x36CCAFF0972A4F3CULL, 0x2E7FA3B1D38FFB0CULL, 0x2080CE9082D5A4CAULL, 0xD361914531E99323ULL, 
            0x8A69B3B6C5C164FAULL, 0x93B1BD30CE9D4DE2ULL, 0x108F97A0F2C5771BULL, 0xE982B7A480F63169ULL
        },
        {
            0x3B185EEE71C2EBF3ULL, 0xD8BD4D9031B840F7ULL, 0xADFABBFF1FB6A90DULL, 0x2F7A339C1829E4ABULL, 
            0xE168E86DA3C330FFULL, 0xCB117206C8548817ULL, 0xAEB1D3217F8A32D8ULL, 0xEE3B98DA96A454B9ULL, 
            0xB4DBA5BA4A385785ULL, 0x8947A3C4C865B40DULL, 0x6AE2B610EB401A95ULL, 0x4D62276EE288096DULL, 
            0x2527B6A8B077EA59ULL, 0xC96B12148A112444ULL, 0x22EC61AEA6C22D71ULL, 0x985B06531820DADAULL, 
            0xA72CB7F7FDC742DFULL, 0xE554809BA0E32488ULL, 0x56A04D26D4614F12ULL, 0x49DEAF4247962E72ULL, 
            0x45E3F1E76857EB67ULL, 0xD93F885444DC427FULL, 0xECAE774356F8C19CULL, 0x6FCBA0BE40A26D50ULL, 
            0x8A4072BC0141E8E0ULL, 0xB70721E1B4EBA2D5ULL, 0x93F2F21030EE4ECEULL, 0x8D12A8D3798D9BBAULL, 
            0x1BE7EE0C24B0D4ACULL, 0xB952D33D6840483CULL, 0xEA888FFC051FBB24ULL, 0xC02E800C6FE73579ULL
        },
        {
            0x562B2ACD708F4BABULL, 0x8871D03D99DA35E4ULL, 0xF396ECCE21EE1E1CULL, 0x4853A07C54364810ULL, 
            0x781CF9D9426951A9ULL, 0xB5FBC56AC7E1023DULL, 0x6E52D42B90BBDDA1ULL, 0x5DE6DAF845987788ULL, 
            0x98F53C1AB4AF5668ULL, 0x208210647D34CE1BULL, 0x778DA0916C7424F3ULL, 0xCB4599483AB34932ULL, 
            0x54EE9709FE851883ULL, 0x975202ACDC962264ULL, 0x6229D79345BA6C05ULL, 0x9F5A2D47DD06D13BULL, 
            0x9173C456748173D4ULL, 0xD2BA31A2DA8087FCULL, 0x83A1BEE96042880FULL, 0x1288BE42A0185208ULL, 
            0xB154713D8717BDCBULL, 0x4EA819FEEAB134DDULL, 0xF341F08490E2764BULL, 0x6C5B6A11F71F3E2DULL, 
            0x7F4A28E0693C52F0ULL, 0xF96CC2482F117CBAULL, 0x6C72B5E47E59277EULL, 0x7C90ACE177125974ULL, 
            0x7BACDE2A48ECA5B3ULL, 0xF0535489DB6049A0ULL, 0xA63D6452F5F5B034ULL, 0x3F8C4FE005EC6555ULL
        }
    },
    {
        {
            0x1C17D884B9F9539CULL, 0xC62F692757B25757ULL, 0x3DDF299980B2CCE5ULL, 0x55D040BA746E82A8ULL, 
            0x42B2F2AA27575D5DULL, 0x18BB745DDCEADC67ULL, 0xD2249AA2E367A3E2ULL, 0x7CB8C1308FA7DF8DULL, 
            0x8F426474590CBBEEULL, 0x380F672E65DBDC62ULL, 0x22A37913D21699D0ULL, 0x17C672ACDDD57C0FULL, 
            0x8EFCB00073EE33ABULL, 0x7708B09291AF67E1ULL, 0x750186D6A2D6375EULL, 0xD0E19C4F87159FCFULL, 
            0xFEAD7CB061014DC7ULL, 0x2808F77D04323548ULL, 0x93240D50C48912D0ULL, 0x5448110C38E3C9C7ULL, 
            0x078E6731A2C6D402ULL, 0x291C127C35FC25CFULL, 0x5A64FBD634B2F8C9ULL, 0xFDE99F07A104AA65ULL, 
            0x51441460BEE89F3AULL, 0x84E25E1FE2389CF8ULL, 0xC70C5EFB0852ABD1ULL, 0xD7C2BD60B67E8CD3ULL, 
            0x1DDEF458A3476165ULL, 0x5C71F401AFB25874ULL, 0xA70D323D9A60B7A1ULL, 0x03E101378B594B69ULL
        },
        {
            0xCD521AB9A0EC4940ULL, 0x6CCB199A0D03644BULL, 0x5C3694379A43BC1DULL, 0x9794123BC7185E87ULL, 
            0xB0EEE637D9478F58ULL, 0x4A5CF369567F86D1ULL, 0xF5D1FE786ED94502ULL, 0x54FBC7D1B7BBF312ULL, 
            0xA3BF69876FDE2074ULL, 0x153963414AAFE849ULL, 0x52FA6A7AF5E54BEBULL, 0x7C622F1E738809DBULL, 
            0x00C140AC2B3EB77CULL, 0xC4D17512664F4A23ULL, 0x571967B651804903ULL, 0x7475AA66AE4D9279ULL, 
            0xA2F568058B219E22ULL, 0x42070D54067564C4ULL, 0x29660D98A06C5184ULL, 0xCDCE8FA0E8DCA675ULL, 
            0xD9AA98CDDEA76C38ULL, 0x25F010CC8273A0CBULL, 0xD7ADE32A625FE805ULL, 0x0616667962731736ULL, 
            0xDAF1D27B0DE9205CULL, 0x4169EA02C10D09F9ULL, 0xC5E6B23BC837BF8EULL, 0x7D0F41168A43B4E0ULL, 
            0x3A2904E82EA289A2ULL, 0xEFA144997A016B56ULL, 0xDFF0D228B6BA3B0BULL, 0xDAE2D8AF44FE008FULL
        },
        {
            0xF5F7356259A6ED63ULL, 0x6FB6E90C845446E9ULL, 0xC527B8F5441A1CF8ULL, 0xADD3E91CAF63F898ULL, 
            0xFF79B96138D98E3DULL, 0x3C9F0C44C610A707ULL, 0x3B8BDD6F6B32103AULL, 0x21B021F1AA950E25ULL, 
            0x36FE68BC74FE7BB1ULL, 0x6F5C3B72A5BC50DCULL, 0x609CD91FD89290DBULL, 0x05A88AC0B0C31F2BULL, 
            0x82A063E0FE5C273FULL, 0x9D958D08578AD412ULL, 0x363E4446183BFFB4ULL, 0x27CE9F5F62019041ULL, 
            0x93BDA77539412B92ULL, 0xE5B7EEB24804A701ULL, 0xEA9203DE8EA18DB4ULL, 0x187956CF52B7A001ULL, 
            0xA855B53A16B1A1C1ULL, 0x8E972BB1F13779F6ULL, 0xCA5624FBDEAD325AULL, 0x75FADCA2E6C7574EULL, 
            0xEA83A66AFC8CB86AULL, 0xB6008FC4B90BED47ULL, 0x4E8AC6C86B4798D7ULL, 0xA7291E287615432AULL, 
            0x648457E48343605AULL, 0xCD4F13B3DD3490A7ULL, 0x782BE9FFBDAE7E70ULL, 0x218E15B60FB3B36BULL
        },
        {
            0x0D9DAFFCBD7F78C5ULL, 0x8332B14D2222890EULL, 0x03F1E7FC4BB7A0DCULL, 0x61F692A6B50644E5ULL, 
            0x6AEA91CE74296A8DULL, 0x6DA58A97C80AF279ULL, 0xA5A3C156BDF0BBBAULL, 0xD289FC1B8A11B8F8ULL, 
            0xB19618B9E9956E53ULL, 0x2667B17E35DB2A9FULL, 0xE62B099EE2D35B5CULL, 0xFA929A9D18884894ULL, 
            0x12CF771E28F77173ULL, 0x8813789D48D5EB69ULL, 0x18B4AD63D27D7EE4ULL, 0xCEC97B92C12E9602ULL, 
            0x51851CA610C86703ULL, 0x361304CF8F820E2FULL, 0x507A7D7DA1F5EBB8ULL, 0x449681DB73C24BD1ULL, 
            0xECF1523905A74598ULL, 0xAB43E68CF5D64BBDULL, 0xF43BEEDC28D89A93ULL, 0x1071F96F7107A1B2ULL, 
            0x38CEDE4EE07F012BULL, 0xC3E33862248254A0ULL, 0x8E02362F9C87B4F6ULL, 0x30B21D1654B9082FULL, 
            0xE9F67A87E2EA4249ULL, 0x3E89676EEC6CF069ULL, 0x8004EDBA4924F0CAULL, 0xBE72DB385CB08FE5ULL
        },
        {
            0xAE1858925BD38910ULL, 0xFEBDE2FCBA1282D5ULL, 0xCF227CD16C006C9EULL, 0xE73784453C2B1747ULL, 
            0x17EA7A706A356310ULL, 0xC8BF20C8873C606CULL, 0x975ABBA1AA6134EAULL, 0xA53439BFBF44EE6CULL, 
            0x92921E3CCEAADAECULL, 0xB442CF2599B4EA42ULL, 0x5B872292FC9986C6ULL, 0xC37C261B38B1F36AULL, 
            0xAA7549F0F4652734ULL, 0xADE4DAFB2A191DE4ULL, 0x78588BDBF5DACE7DULL, 0xA9EC70E35342087DULL, 
            0xBC10062FFD470D8FULL, 0xB175A92AD131479CULL, 0xDF32D75C7141EA3CULL, 0xA59532D007D95DF2ULL, 
            0xB6421B85054E471DULL, 0x01921996DEBC6603ULL, 0xB6AD311760A1E3F1ULL, 0x13054A0775F0F121ULL, 
            0xFBACBCB1340FADD5ULL, 0x776572753483CCA1ULL, 0x1B467C16460F232DULL, 0x6466DD757130E946ULL, 
            0x2993B4FC7CB607E5ULL, 0xC5D42505480CF54BULL, 0x3625AD0FF6993917ULL, 0x4975F694184B03ABULL
        },
        {
            0x16E21B08ACFC6BE8ULL, 0xA7A4F826C0587ECAULL, 0x37013E9842508C87ULL, 0xDC5F61C640FA7DF7ULL, 
            0xCB578AD069E7DFE5ULL, 0x90927F8EAD72930EULL, 0x7C9F3C83A50031A4ULL, 0x6C460E1C6C038424ULL, 
            0x60BF33E8F3B0C728ULL, 0xE2A5C565616724CAULL, 0xED6E762483AE5053ULL, 0x067D836461C72479ULL, 
            0x3AC97D86AEDE024DULL, 0x798EEE1EB2812DBEULL, 0xF05C1420CB51A317ULL, 0x4308775C1D9F7CD3ULL, 
            0x71BD2CD3685E1DF7ULL, 0xD94859AB3263B82BULL, 0x8EC90B2FF933B5AFULL, 0x2E6D98E513B6160FULL, 
            0x317EDA346A134AF3ULL, 0x96AED37117ED4795ULL, 0xE94441598FBC1B1BULL, 0xD24932B94BFF6EAEULL, 
            0xC04314359C3E9F80ULL, 0xF872F89E9E317090ULL, 0xE00D5FB84000650DULL, 0x33936D9A0DBB7D58ULL, 
            0xF5E97FF55DCF88D2ULL, 0xF2B92E5E1B6D15B9ULL, 0xEC34958F00127F5BULL, 0xAE8B3A2B928102FCULL
        }
    }
};

const TwistDomainConstants TwistExpander_Sirius::kKeyRotateAConstants = {
    0x7595190696DCD62CULL,
    0xC3209C91BC841EFCULL,
    0x2056A8D681D88FB7ULL,
    0x7595190696DCD62CULL,
    0xC3209C91BC841EFCULL,
    0x2056A8D681D88FB7ULL,
    0xB7D967CF0A236995ULL,
    0xDFDC9C2A8A4B83E7ULL,
    0x3B,
    0x94,
    0xC3,
    0x8E,
    0x7A,
    0xFF,
    0x01,
    0x51
};

const TwistDomainSaltSet TwistExpander_Sirius::kKeyRotateBSalts = {
    {
        {
            0xA3172D526CFA5180ULL, 0x6D2AF405ADB9C89DULL, 0x8A5A87009A634511ULL, 0xDE311967FE894387ULL, 
            0xA63D6AD8CB996566ULL, 0x81868C4282ED702EULL, 0x7AF916B827F06719ULL, 0x8943A51037BEBC52ULL, 
            0x89A09A9A06421F40ULL, 0x16889BE39998F269ULL, 0xFE2AE59E004F157FULL, 0xD452FD86262A0091ULL, 
            0x150DE8C06052F1A0ULL, 0x4D64DDF3EBCA6294ULL, 0x577639B301FDEFBAULL, 0x51C8B64C03FF16B4ULL, 
            0xDEFDF4E1F45102A6ULL, 0x3138AE83BC8BD2B3ULL, 0x35C68D1AD6A839ACULL, 0x066616CDE4025C7FULL, 
            0x37A9FF3482F9E88DULL, 0x01F93DA30A1F6A7DULL, 0x14022B2C1D71FAD4ULL, 0xE4FAFF2B3B54185CULL, 
            0xF4950FDA1A9529EDULL, 0xCFC57570635FE0AEULL, 0x1628E3D3555D5168ULL, 0x093C93E65D626D5EULL, 
            0x452C3EB0CDFD3E8CULL, 0xB17E03D3C9B6482AULL, 0xB7A173A22E1CBA7DULL, 0x03356E43EA3F71F4ULL
        },
        {
            0x8E03EE5D09EADC16ULL, 0x8744786874EA6CC7ULL, 0x070E788F9481445BULL, 0x4D5B2D5887FB89E4ULL, 
            0xB5F544A6920F621CULL, 0x693715BC954C6866ULL, 0xE7E6BF6F1659A3CFULL, 0xD95F6E0C7954A0C5ULL, 
            0x476BC9A19551D7F4ULL, 0x1B2F7D1247295727ULL, 0x686AADEB674421BBULL, 0x907CF75AEFC393DAULL, 
            0x73087BD13A7ACDC8ULL, 0x169F3CEAD411F81AULL, 0x2C382BBDEB5B6D66ULL, 0xC8EE23BB1E59F2C8ULL, 
            0xA9835930A0E16907ULL, 0x76839FDB87AFC02DULL, 0xFB79333DC4ECA529ULL, 0x0D54A4315E3EE8F6ULL, 
            0xA252F1A48151C624ULL, 0x71E436122CDB5528ULL, 0xD707B1F9D88DB5EBULL, 0x5073A758C5703DFBULL, 
            0x36517D0F0077E551ULL, 0x457970FFC8A2FBD0ULL, 0x13B80D0DAA27E3F8ULL, 0x8929948120260EE3ULL, 
            0x7FFF3508DDF09D95ULL, 0x99A4458A5F0C8120ULL, 0xAAD097183064757AULL, 0x726BC1041BB8E661ULL
        },
        {
            0xBBAEFE379C2EE6D6ULL, 0xB31A24D0736CE828ULL, 0xED545420760CD1F0ULL, 0x3964DE7B7A0DE1F5ULL, 
            0xB60F58B23A5BDF56ULL, 0x3F15F856C5D7AB95ULL, 0xCB54B34C22BE3831ULL, 0x375C3E07AE418DA8ULL, 
            0xA28D607B0D557305ULL, 0xB1B75CE21DB1CD23ULL, 0x70BC7C93C8492118ULL, 0xBC3C8A5F2503A023ULL, 
            0x8681E4EBFB65B48EULL, 0xC69BA3150F8FB482ULL, 0xC2DD850EC0B35171ULL, 0x52D63CD7457BFEA4ULL, 
            0xA17F8364C6D2E395ULL, 0x7F7ACF327AD12066ULL, 0x712C741E0ED5723DULL, 0x71E65655B30BC24FULL, 
            0x94432A33E4F59D18ULL, 0x41D27B7468FE0DEEULL, 0xDE016DD2ECAB7E9FULL, 0xC87EB723B4672CB2ULL, 
            0x55E0A9497832830EULL, 0x0EF6DC59F82AC76DULL, 0x88DE880538AE9B5FULL, 0x673693652E873714ULL, 
            0x1ECEC3010BD740B7ULL, 0x50FBA9192F51670AULL, 0x092085722D5E91E9ULL, 0x68B750B4A52FDF9FULL
        },
        {
            0x03688D68BADE1F05ULL, 0x6F6EB03B7E7462A1ULL, 0x417A11EDE4C2B593ULL, 0xCDB1C40F8DD8E69CULL, 
            0x5797786B2FBB142AULL, 0xF2B632B4846C31F6ULL, 0x17AFBC1A1AE042F3ULL, 0x3543D410ABB09E00ULL, 
            0x729EC1127BEA9E04ULL, 0x1391D6BC786595E1ULL, 0x04E0B35629FC7410ULL, 0xC1431B235422429BULL, 
            0x485C156BDB042294ULL, 0x9CAFD3507325D40BULL, 0x42B44F27A0EBE3B2ULL, 0xA4BBA5403E4B6ADFULL, 
            0x187F26E27DCF92F9ULL, 0xBA93F415D5D7BEFBULL, 0xE739D992414448F0ULL, 0xED3F3A12CCAF5908ULL, 
            0x21D2A929BC0F55FAULL, 0x5755BA7555E68064ULL, 0x9344BA9E4093DDD2ULL, 0x08FBF49CA468E50AULL, 
            0xF024D214E99140ABULL, 0xA975882D64DE76F9ULL, 0xB6AB5BEAD1F5E151ULL, 0x7C8E184B98B22D28ULL, 
            0xDE78BE4F75C026BFULL, 0x479EEE4DDD9D61A3ULL, 0x4B0F2A4A068840C0ULL, 0x1A2C77286CE7D147ULL
        },
        {
            0xE0219EA86B4AAE77ULL, 0xF2EE8BE971A8219BULL, 0xBE9D8B40DFDAF91EULL, 0x39E5BF757BD92185ULL, 
            0x4A3F001834F26EFAULL, 0x4C8867DA1F3A5F91ULL, 0x4FF6EDC78878F99AULL, 0xDE183477A6D05F35ULL, 
            0x686F4BBDABE69137ULL, 0xFD7D30FBF9499A6AULL, 0x89AF2ABD3D38F6A8ULL, 0x614D3FEAEA8AB98BULL, 
            0x8233AE64AA2A4FAFULL, 0xDA1D612D9EADED1DULL, 0xB4A83CFDC7D4020BULL, 0x17A1F0EB9008D4A1ULL, 
            0xDD7316F52D1DD018ULL, 0xAEBF48EEACF3D024ULL, 0x28C4B92C78BEAAE4ULL, 0x8897E08364D8C8A6ULL, 
            0x5D63D27E20A96106ULL, 0x81FC02326B4006C8ULL, 0xA94FB03FA8ADDB84ULL, 0x47D21732922783F1ULL, 
            0x1E583CA71698741AULL, 0x27C94DE889E1CF48ULL, 0x7529C54A5BF82614ULL, 0x1808F9EEF5B5CD92ULL, 
            0x9ED7AF138EE1A091ULL, 0x294AB74517C98D38ULL, 0xF99DB50EE319A8A0ULL, 0x6F2EF47B7C6F4A41ULL
        },
        {
            0x63836121060F8104ULL, 0x6C2C9673AB394D24ULL, 0x36F909B8DD788613ULL, 0x3799D46BF8C48565ULL, 
            0xFED984092FDA4F96ULL, 0xD23F454BBFC6A9BAULL, 0xBDA558CCC85D56FAULL, 0x42F1671AA5E5F4B5ULL, 
            0xB2D6695F8480B2F2ULL, 0x96D0F75704CE5DD3ULL, 0xDC7FC5894E32BDC9ULL, 0xFDD793E1D56C9B29ULL, 
            0x74B789B56B64671EULL, 0xE1D0A55421879DA2ULL, 0x70C0EA541BACDB70ULL, 0x9643F4B829334FBFULL, 
            0x8AFAAF8E6524DEC6ULL, 0x5D9398BFB95342A8ULL, 0x906A199AE6D7D4A4ULL, 0x30CF653DF5381B5BULL, 
            0xCAC6B72032B5811AULL, 0xA1531AB4CD3DCEC7ULL, 0xB19F6184F4B55397ULL, 0x3AFDD27E63859B4FULL, 
            0xE6FE334342C68368ULL, 0x829D75D712EF355AULL, 0x5F7D1ECF1FFA970CULL, 0x3C5E5F736D0D7740ULL, 
            0xDD18916227356AF0ULL, 0xC0DDE60FF20C3AABULL, 0x192E22011097F7C3ULL, 0x01B32F88F36BD16EULL
        }
    },
    {
        {
            0x46E3AE691BCD5C2CULL, 0xD704DAD8DC391943ULL, 0x1670C8A415BA59E4ULL, 0x4FB3396383C421ACULL, 
            0x9054FAA8541FE960ULL, 0x806DC875E8FC12A2ULL, 0x4372A4B4B0C76D5CULL, 0x3B1C2C7ADF4FB653ULL, 
            0x8276902017B57C2FULL, 0x67E5442E572EB2ABULL, 0xE9189844F8BA3403ULL, 0xC8FEFF7FA43E055FULL, 
            0x962C75BDA3C8938AULL, 0x76FB4431BCA8E40AULL, 0x8B40AB7B007B7B2EULL, 0x67B5458141A1F98CULL, 
            0x1F3C971EB53AF4C0ULL, 0xE4825CFA68D698F0ULL, 0x0481CBCEE60A2768ULL, 0xA08196D313CD2F98ULL, 
            0xB2B66DA1FFE956E1ULL, 0x3AF0E32D7648A05EULL, 0x754E8C339852AA94ULL, 0x02C1FA928E66C587ULL, 
            0xE1DA65F981761280ULL, 0xE1CAAAAF0B67C53AULL, 0x00DD6F8BF80265E3ULL, 0x1880009F0057C85BULL, 
            0xC83D4D136209F093ULL, 0x9093C78F5E59FC2AULL, 0x19A314A381986BBBULL, 0x6A52A83B5858597CULL
        },
        {
            0xA60B4B7637A8423BULL, 0x57BC3F33776B61F5ULL, 0x36D05183D4953846ULL, 0x0122440BCF44EE0FULL, 
            0x6C6EE7B57C7A51F4ULL, 0xC23EEFF11BD946F6ULL, 0x015401D08292820BULL, 0xB76A761C66BD1E96ULL, 
            0x7722D40A23A97B5EULL, 0xC000502000B3994EULL, 0xB67B8EA1601E1CFAULL, 0xDB1014E49DD0FC93ULL, 
            0x70C08AB7A018E213ULL, 0xDE60CE9E90FF167DULL, 0x321948F0EB4F8C9DULL, 0x7486E03817B19D25ULL, 
            0x232260CE8E23ABAAULL, 0xB46C71FEAAF6FDB1ULL, 0xD9AF1C8E2587F1AAULL, 0x9F073B69E13F9DF2ULL, 
            0x3037BBCB74FE090DULL, 0x863F66B5FB4EFEDFULL, 0xEEE11CF087A7BB85ULL, 0x2263F8557C8253A8ULL, 
            0x95723BF2A873787CULL, 0x608CF7CFAB7D671FULL, 0x55D0CA67AA4F8E9AULL, 0x07CCE862D986B7EEULL, 
            0xB73820E9890F8FFFULL, 0x889530C1CF417B32ULL, 0x16F4AEDA3A067B50ULL, 0xCC47FFDA34D177E9ULL
        },
        {
            0x6E830C98E75441BCULL, 0x82C4938CF20E40D4ULL, 0x7AA6FE9D22DD83C3ULL, 0x64C661FD92E9D132ULL, 
            0x75236D4F5C284EE0ULL, 0x528566503ADDB299ULL, 0x263930765FB61124ULL, 0x63273704A4FF5E6CULL, 
            0xF66BE3789E0E6DACULL, 0x098B5832B8BFDF85ULL, 0xFF3E8F4381C74106ULL, 0x8B708ADEB4B1479FULL, 
            0x099848BDE9FA9CCFULL, 0x7FEDA032C2812926ULL, 0x0DA8A4C542201FF7ULL, 0x13AECE1B6EABE3CFULL, 
            0xD19E736F02A2B157ULL, 0xA4232EA163A75D07ULL, 0xBA1FB08200E17024ULL, 0xF52F3729369617B2ULL, 
            0x28D434213DCB2B59ULL, 0x4D7D88C37058D95EULL, 0xB784C0CA0334D2C9ULL, 0x32033757DAB9BABCULL, 
            0x1202198D5B53A29FULL, 0x70168C3127105220ULL, 0xF2F198A2EA92EE00ULL, 0x3F6E47817BAD5448ULL, 
            0x9FE197B304CB0FDFULL, 0x7C03947476989CFDULL, 0x4AA45F001F7A3F42ULL, 0xC2072A43234F15E0ULL
        },
        {
            0x36463D43947AF3C4ULL, 0x9A1D3346204F6B38ULL, 0x84AE675C83B6E522ULL, 0x62C22A7C46438D17ULL, 
            0xE588CC94C7406755ULL, 0x8F12780576D8B1DCULL, 0x86E64AA914DBB951ULL, 0xCC406727E6A7A202ULL, 
            0x0C1DC8754C23A702ULL, 0xD8548F8FD25A2518ULL, 0x02059C2A4410119DULL, 0x34A6932DC47E22F4ULL, 
            0x4009A568F3DE650DULL, 0xB08FF6031E7EE2E1ULL, 0xA26136AEBC46ABB7ULL, 0x158FD8CD3EECD68EULL, 
            0x6047D643DAF9FBBEULL, 0x9847EDC6426FED86ULL, 0x03515473D14C2AACULL, 0x28B1A61656D701FFULL, 
            0xB898ADA7970724ABULL, 0x002D1F7741608E80ULL, 0x2B4CBADBDC245106ULL, 0xB55E61C15D2852E6ULL, 
            0x5D70642BFED889B5ULL, 0x8808DBF88B2DA5F0ULL, 0x9F9C5FE560146A23ULL, 0xAECC8026D97AA06FULL, 
            0x25F9E6489E50077DULL, 0x8DDE61CCE15426E0ULL, 0x79D76B22A19797EBULL, 0xE2F6CECA410A2F68ULL
        },
        {
            0xA31FC6F62C1A8FF8ULL, 0x1BAB076C1412B5ECULL, 0x4F1715D6113A8AA9ULL, 0x4099DC61F6BEA610ULL, 
            0x48E9082A024EFE0FULL, 0x550D06D75C48D548ULL, 0x03C4737248C659C8ULL, 0x81C6337366A0A48FULL, 
            0xBE977E51028680EEULL, 0xABF7F3FE57B4DA16ULL, 0x03ECD0AC7BC351EBULL, 0xA928F5D93214B6E6ULL, 
            0xD80B0C12234196DDULL, 0x3B712D8D51D7C5F2ULL, 0xCA04408BA4DCB488ULL, 0x3ABFDE84FDE52352ULL, 
            0xD002C3D6C966B4ABULL, 0x8DD50F4A3D77246DULL, 0xA8EAD9412AAAEC0CULL, 0xF7F9198EFC0E81BFULL, 
            0x2107A4ABB2C50532ULL, 0xC1D9403763C7689EULL, 0xEFDA513EC7EF5A43ULL, 0x48D961F8AD56B351ULL, 
            0x62EAA6318760F402ULL, 0x8E74AD0E85B0E565ULL, 0xB70704883C6B4DBCULL, 0xDDA96538B6BD3451ULL, 
            0xBFCEBE40C7EB3163ULL, 0xB7375A263BE40BECULL, 0xC0996E2ABD533960ULL, 0xB493353AEC54214BULL
        },
        {
            0xDFFE1C828482DBD2ULL, 0xCC2A6CF1B8D3E6BAULL, 0x0CC2C1CCAAA88F06ULL, 0x954CF671743C58D9ULL, 
            0x63AD778302A69B81ULL, 0x5B4F3EFE5EB3D88FULL, 0x440BC62D90554278ULL, 0x4446E18F18BEA7F0ULL, 
            0xD629CCA1C41577A3ULL, 0x79497E819B1059CCULL, 0x1933603BBAE0249AULL, 0x8BA89F73E871A65FULL, 
            0x2A90A60C829D4AE5ULL, 0xA1069B617206CD4AULL, 0x4122DFA14587A2E0ULL, 0x8B0D420D315BF06EULL, 
            0x381CC4A44D4EF63FULL, 0xE1CD46401132F9B8ULL, 0xD1B49726A775E419ULL, 0x5CA57EE2BADADE87ULL, 
            0xD479C607BF59B23BULL, 0xEE5E19196F86D8A4ULL, 0x58B9A4750CC02A58ULL, 0x3D552829551372E7ULL, 
            0xFC16B701C6C7028DULL, 0x55C55994582AB6C2ULL, 0x800DC8D4F4F373ADULL, 0xA3A636FDD387367FULL, 
            0xCA5EAEDF19DC2946ULL, 0x60FA88660E9CA433ULL, 0xB14E95AA42A1A912ULL, 0x83B24A4BC171FA8EULL
        }
    },
    {
        {
            0xEF03E08A1327B89BULL, 0x38BF8028533112D6ULL, 0x13673F83869F89D5ULL, 0x1626F9FA46B2451AULL, 
            0x83EB020488668A11ULL, 0x6C93DF16B07180A8ULL, 0x12103839658067E1ULL, 0x2060771C6862AEBCULL, 
            0x16B44C92BC044C99ULL, 0x261D7972FB8A5A43ULL, 0x77058B6E4E4D2A87ULL, 0x1414D34CBE16C00EULL, 
            0xCB695365F0B3AA5AULL, 0x4C44F82B556E6DA3ULL, 0x7119AF6DF5CB244DULL, 0x174FE1CAD757AEB8ULL, 
            0xD6374BC4C115CF82ULL, 0x5333981FA1279B8BULL, 0x1536DA887C3C59DFULL, 0x37B64F8B72B73827ULL, 
            0x31A84250BDCFD780ULL, 0x7E02C9F313E68F3CULL, 0x87F5B0A850D77A8AULL, 0xD3C9D6A8C32326DEULL, 
            0x7084222E507335EBULL, 0xF4AD4F74F97E0431ULL, 0xC85C279DE68D06D2ULL, 0x1B2A07D2B2C0C0B3ULL, 
            0x6B2E66F7A6B60394ULL, 0x65BC3185E6B60484ULL, 0xA1673C582C2EB0B6ULL, 0x1FC33D618578081EULL
        },
        {
            0xBC00EA9516B16D38ULL, 0x50C749B7728D0B82ULL, 0xBD9ACB3D58E6860EULL, 0x01A31290028C33DDULL, 
            0x8131E57E60DFA251ULL, 0xA972B8E52E814A1AULL, 0xA05C7CC57A9F5F43ULL, 0xC14722D35630F270ULL, 
            0x78D946478BFE0151ULL, 0xE4990B6E3D8D83A9ULL, 0xA4D422453B84F339ULL, 0xF525135B203EFB6DULL, 
            0xC06A84192D88CB19ULL, 0x35556393C50D4969ULL, 0xE054ED70231E8EA8ULL, 0xDF99F9276EE68E93ULL, 
            0xC0D6704EA41BBC6FULL, 0xAD9429311767DF92ULL, 0x279283A1D8815FE0ULL, 0xA46245023CD8E15BULL, 
            0xEAF909F47D515EDEULL, 0x432FDC3F2E063E2CULL, 0x3D3F6EE33CF783D8ULL, 0xAB38ADAE2C299580ULL, 
            0x324CFCA667DAA9F1ULL, 0x93FFF3F2435AE7D2ULL, 0x7BEDEDFD922A128DULL, 0xCD35C304F0999ED3ULL, 
            0x9DDC0EDBF49BCFD4ULL, 0x9A4A824C3B9CF82AULL, 0x59D032199EAB5455ULL, 0xE7F7AD7E5C6FAB8FULL
        },
        {
            0xCFBD47E78DEEEA4EULL, 0x0DDA15D22C3F5CC1ULL, 0x230E2E526691ADC6ULL, 0x22072A5A27C91CE5ULL, 
            0x80BB7697E079060DULL, 0x957462E77B4DDCBAULL, 0x3960D92521D286EDULL, 0xB4DE9AD7258BF572ULL, 
            0x03D4763D5BD83AFFULL, 0xC9F6BE02F90FF050ULL, 0x7D160D0AA6DD3B16ULL, 0xD8EB146CADAEE913ULL, 
            0x792326AF5D387908ULL, 0xAA7E64AEE731134CULL, 0x6A131B6BA06004F4ULL, 0x564ABA4EEE3858D7ULL, 
            0x0C33F9092F70264AULL, 0xB65665AFEC50B64DULL, 0x99EEC671F77341E9ULL, 0x9D467C9A28BA1BD5ULL, 
            0xC1C224FBCA818091ULL, 0x04AC90F87ED71C79ULL, 0x36599BCE452FE1A0ULL, 0x490E068349201FD2ULL, 
            0x9FCD67BC566809EBULL, 0xC6BEF5A428193499ULL, 0xC64D942111426400ULL, 0x7B57E7182F86B38CULL, 
            0xA19F0B8DB7822E3FULL, 0x6CC791DFA7F1D734ULL, 0xF46AF46F72ACECC3ULL, 0x99240DD2F3876213ULL
        },
        {
            0x7E2FB97B52C3DAE7ULL, 0x112149E57C305276ULL, 0xC88D19FC9B15F9B8ULL, 0xA3A719A5D8933F2AULL, 
            0x34F4CD909E3F8CC7ULL, 0x8111D09A5ECAF8ADULL, 0x808359D325BE7C8EULL, 0x7D8D5B973B816CF6ULL, 
            0xF08FAE5E304BD061ULL, 0x2DB63B3CF3EE6EF1ULL, 0x36434816C7F61945ULL, 0x7ED27BA644395A31ULL, 
            0x2468B8197D58779AULL, 0x60075AA1889A5DCCULL, 0xA191CA6202C2F92BULL, 0xFBAF9E526B0A5329ULL, 
            0x2A72DE45071D92E7ULL, 0x5536931ED209FB44ULL, 0x566B3237574697CDULL, 0x30ACDBC1B2A5E96FULL, 
            0x9CA9788B9239F304ULL, 0x2509AF85B5138DD0ULL, 0xE00C6D7E10503FAEULL, 0xDE4D4E604BB5C019ULL, 
            0x26924A4E2E81E804ULL, 0xC0F24E243C7579D2ULL, 0x2CDA637B1E63D6E8ULL, 0x84280914E7C68BC0ULL, 
            0x9D90656223C78532ULL, 0x4A4EB56AEC5C21C4ULL, 0xCA5B470033649DFEULL, 0x93E5A82A1CBAE539ULL
        },
        {
            0x09F599297212361BULL, 0xEB90D01C51A661C3ULL, 0x6F6CC2277E645ABAULL, 0x0DBD146958C754EEULL, 
            0xAB364B450CA52497ULL, 0x0C4B4BC416887B95ULL, 0x8C53C83594F84C59ULL, 0xA818F28A60493F07ULL, 
            0x8F1A9E2951F8CC2FULL, 0x0AEDD35ECD3DCAEBULL, 0xE44A557570BEB547ULL, 0x9C1DB4192D6D42B4ULL, 
            0x41775A1809692A99ULL, 0xA13FD4F8309CE9E9ULL, 0xD2E73A8E27138B2FULL, 0x7F5AEF9CCFDBF43BULL, 
            0x0757E4E7535B0AFAULL, 0xFC46E656D282E2B8ULL, 0x7B04E0B5D5F438FCULL, 0x367F340BB2F1CF35ULL, 
            0x2E2F07A5962FBE3DULL, 0x7327B2CED0D66C9FULL, 0x7BCEF8BAE85AA79CULL, 0x62FED2C58F41AFCCULL, 
            0xEA1D3FF159270F84ULL, 0x16F507238BD791DFULL, 0x842B9B489C4948D0ULL, 0x559B57482B6769C3ULL, 
            0x70730F56FF72EF76ULL, 0x07CA8B88C137B1E1ULL, 0x720D35D7B930B736ULL, 0x8C9B8768912824A0ULL
        },
        {
            0xF4F0DC52F110F6AEULL, 0x9E480373028FA64AULL, 0xFCE20445C579CE47ULL, 0xC1131B704E05E4D3ULL, 
            0x8E735907A9D0B9A7ULL, 0xEBAE40B98CCF61BAULL, 0x5BF1F91A5E8D91A3ULL, 0xDA99C55B3FDC3314ULL, 
            0xB59E5F47F99BB81EULL, 0x388BE9E9B7E93E78ULL, 0xB99EA2B1E6C34E13ULL, 0x5FE8D96C6EEBAE67ULL, 
            0x39691C2A3EA86EF7ULL, 0xD3BCBF720437EFFBULL, 0xB4A4C7750474D648ULL, 0x370F1806ECC15DA1ULL, 
            0x2A0F2D2BEC2D74CDULL, 0xF0330B02707EE7D9ULL, 0x4D9A718C06EED349ULL, 0x6736751A5D87FB16ULL, 
            0x5CF9FED872EFF2C7ULL, 0xEBA15772BB8C9320ULL, 0x7F28B40D6416FDEBULL, 0x6D7F91D39337BD66ULL, 
            0x78F1BE4CC4B3A768ULL, 0x5BDB4D5188AFA136ULL, 0xAABD97802F9896AAULL, 0xA48304A55350A468ULL, 
            0xA154040FF988BCB0ULL, 0x6F0E23597D780D4EULL, 0x02729707B6F9A15EULL, 0x04CB9B46B3419164ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Sirius::kKeyRotateBConstants = {
    0x81C9D1527BAE1F89ULL,
    0x8EAEC6E5A590A33DULL,
    0x3F12594B682396B0ULL,
    0x81C9D1527BAE1F89ULL,
    0x8EAEC6E5A590A33DULL,
    0x3F12594B682396B0ULL,
    0xB18F769A9BC65AE5ULL,
    0x062585C6577A2186ULL,
    0x2F,
    0xB1,
    0x34,
    0xE2,
    0x79,
    0xB6,
    0x09,
    0xB1
};

const TwistDomainSaltSet TwistExpander_Sirius::kKeySpawnASalts = {
    {
        {
            0x6B5DC3FB9EB8173BULL, 0x4AB59682F313B790ULL, 0xDBBD9D787EA2B928ULL, 0xAD29E86929F0DFC3ULL, 
            0x42BB8FD0F0D06A8DULL, 0x5ED8AD6D555D90EFULL, 0x1352E9A584601763ULL, 0x41B7B35550AB74ACULL, 
            0xD867F78D57AE3B22ULL, 0xA9495FC5E7848B5CULL, 0x8755F48DB5CF575BULL, 0x9AC707841B743E23ULL, 
            0x448E956307037DA3ULL, 0xFC209CCC4F26E167ULL, 0xA0436B7777A27DB4ULL, 0xEBB83DB66851CB1EULL, 
            0x27272214F27F1FABULL, 0xF008789FC3996ACDULL, 0x5B02DA2FC0ADB430ULL, 0x63C2EFAD91532A48ULL, 
            0x8EBF5628F06597F5ULL, 0xFB7ECAF912457E09ULL, 0x92DF733D6F8D9A80ULL, 0x45AB124BE32EAF24ULL, 
            0x1161D41713D9C88FULL, 0x0FE9EC82BBBD7C9AULL, 0x59AD670E2455687FULL, 0xA3188B32C7F2B386ULL, 
            0xF28918996E731874ULL, 0x31D0FAB81DFDB66FULL, 0xE1934D907E169402ULL, 0xF020E0FF935D7DC6ULL
        },
        {
            0xEE91E7799FB21B1CULL, 0xD75B1EB2813A0BC4ULL, 0x5F2D53D0F495F1AAULL, 0x64121F0448FE4EC1ULL, 
            0x9DE8D3E8875269C8ULL, 0xB9BBB846839D4225ULL, 0x61D9F0C283AD008FULL, 0xE677FE34935DA91BULL, 
            0xC0AFA1FD4D600891ULL, 0xB0836373F6262FB8ULL, 0x50299A5B90BAADF9ULL, 0x1ACC2D13CCE72185ULL, 
            0x049B3B554FCFEE32ULL, 0xB844ACE7370FA457ULL, 0x3B4EF70961B58EB0ULL, 0xF821D948BEF7CB62ULL, 
            0x7FFBD094407D6A9AULL, 0x0155BFCA9F16FE0DULL, 0x51C75FBC556D5749ULL, 0xBC2B91B52E44A407ULL, 
            0x510A19B96CC37C3FULL, 0xEDD4320B12616EB7ULL, 0x9BB04F19F0E814D5ULL, 0x2D94978C43181875ULL, 
            0xD7A2B5E506C1ABEDULL, 0x66C33BC8A9906F4CULL, 0xDD0FA2FFE9A0CC30ULL, 0xA6BE094F44F8668CULL, 
            0x37563481D3275930ULL, 0x3344ABC95FBC7379ULL, 0x2C3B9714F28BC87FULL, 0x4269482EB7294A5EULL
        },
        {
            0x869628739BCE2503ULL, 0x1E699B882F53A6FDULL, 0x799ECA16856E3AD5ULL, 0x4E6399D354EF9CD8ULL, 
            0x1F504FEC44EE96BEULL, 0x8939A13180EB2A55ULL, 0xFF2A71D33D4B0917ULL, 0xAA5129377F9FB312ULL, 
            0xF4E7EBD4F2D39A67ULL, 0x1EA4429D02DB62B2ULL, 0x955D59EC43D8AB0FULL, 0x2B5C64F5D94419C2ULL, 
            0x3710B7AE11FB18C4ULL, 0xCB33BB9F203C3282ULL, 0x685278FD44D6C4F1ULL, 0x068594E90D191711ULL, 
            0x4784BF6C1B14AECAULL, 0x79D04FF3839B23ACULL, 0x03AA9098783F9863ULL, 0x5CB78CDCC38E7B9CULL, 
            0x24C865DCDE1819C9ULL, 0x94FAEF8AB842897FULL, 0xF2502C6CD6437405ULL, 0xE85767DD160C4FF6ULL, 
            0xA431B6F379E8A52DULL, 0xCC03476F76942886ULL, 0xD4884B96C3E92CB1ULL, 0x051DDE1A6104365AULL, 
            0xFDA13B3830473B97ULL, 0xDE710AF19E32B10AULL, 0x1022EF95A5299724ULL, 0x33CA9CAA3F5A48D8ULL
        },
        {
            0xBC0C27BBDF4D4FB2ULL, 0xE43F72BC9CD6420FULL, 0x2AF9350B5EC63AE6ULL, 0x31A2AE839DFB69B8ULL, 
            0x78EA21D62E172F5BULL, 0xC867B06D64007957ULL, 0xC53C6E99186D4479ULL, 0x94B88FD905A393FAULL, 
            0xE18025F3D689D899ULL, 0x90E114A8EEFA2306ULL, 0x3609E478D8B9B72BULL, 0x675EC3E227AAFF60ULL, 
            0x361C5DCEF604C93CULL, 0x07A5773D8DC7E4EAULL, 0x2EA23CBD37280FACULL, 0xC737917516083A41ULL, 
            0x0052388B9CE6D4F1ULL, 0x8BFA396216761FA7ULL, 0xA1262CA5F6F53023ULL, 0x5EA6AF94740E3957ULL, 
            0x375CE6728E1FAA32ULL, 0x142A0DAF32A47389ULL, 0xF4CDD3161DC001AEULL, 0x35751205942638F4ULL, 
            0xB5F1900AAB49E5B7ULL, 0xD057A1ECCC0D7090ULL, 0x42129F5A698FED62ULL, 0xB1A1381373303312ULL, 
            0xF7A23E71E8220F75ULL, 0x6B4F96B381E8A83BULL, 0x0B1E4B07D07894A3ULL, 0x8891A9561F192011ULL
        },
        {
            0x7A5E9D4C39C35519ULL, 0x6DA939404D0EF1A5ULL, 0x8CBEF19B8C45E735ULL, 0x10F70747AFC3DD74ULL, 
            0x82692EA4B04275A6ULL, 0x6C8200E844DF05E5ULL, 0x26525846D1D9FECCULL, 0xB3461ED8E6BF83E7ULL, 
            0xCBD80FEAB188A177ULL, 0x1550DB42FD63A282ULL, 0x92AAD06AE81B44DEULL, 0x05F1935461781262ULL, 
            0xD1390376D161978BULL, 0x4C22D47F42BAFCC5ULL, 0x4CBEFC3B5B084463ULL, 0x9BD466FDDFEA5416ULL, 
            0x3872B8BC31A8B999ULL, 0x0E7052EAC375A540ULL, 0x5774455B081F7139ULL, 0x9DE2C4CEB0B2B9EEULL, 
            0x45AF7ACEA92F0BA2ULL, 0xD8FA8F4765E80280ULL, 0xB08DFAD9E02D71D6ULL, 0x54ACA6E5C603F301ULL, 
            0x467CEE4B44262AD6ULL, 0x6D98A840034C7640ULL, 0x990BD4980E6F68F3ULL, 0x86AF4BF982B812CEULL, 
            0xB6BE515068A5531BULL, 0xBBC7CBF9EE2F286AULL, 0x6E1963859611A8CCULL, 0x4016B30EAE0BE773ULL
        },
        {
            0x39922B98E9F4CE18ULL, 0x511D8BAB125DB2E0ULL, 0x2550AF86788E45A9ULL, 0x42BF0F9DB788D660ULL, 
            0x20F3012C916B49AAULL, 0x7ED07453C5F2E64CULL, 0xFF8C91C16F9171BEULL, 0x959770DC9A369913ULL, 
            0x709CBD708C3E78E4ULL, 0x517F693A83036139ULL, 0x6E9B02A5F45ED472ULL, 0x73917777A5BC3EEBULL, 
            0xA949253979341E7EULL, 0x243F7E3E75B243A6ULL, 0x0AB27165C7871BFCULL, 0xC1279948E756F93FULL, 
            0x6B9ECACF978FE305ULL, 0xBEAE123D784A0AD6ULL, 0x5F7F769B7E472A5CULL, 0xCC390A2A17CEC349ULL, 
            0x20A01D25A512C477ULL, 0xF8E7A929825D24FEULL, 0x5898BAF2849713C9ULL, 0xEDFEE48FB19B3C7AULL, 
            0x4040C64D96B2057EULL, 0x9F4CF2016AEC03E5ULL, 0xAFE415EAD2D1D430ULL, 0x31B506591C285FEAULL, 
            0x33002E83057B8123ULL, 0x61BEFFFE08A09568ULL, 0x0E2A9683BE8545F3ULL, 0x1E273C1D0FCD8172ULL
        }
    },
    {
        {
            0x076542ED35425ED3ULL, 0x2BC8DA2CEDD4F344ULL, 0x16702AA891F16313ULL, 0xC28798D01ED6BC96ULL, 
            0x359BC636431B8501ULL, 0xF2AEEB36D84CF387ULL, 0x941DF0574B2FC444ULL, 0x498C840054BC27EAULL, 
            0x6B94AADBCD2CF8D1ULL, 0x328B91DC1725FEDCULL, 0x7E1C50B8AA8F2215ULL, 0x7E433747F28333AAULL, 
            0xB884C10596A269DAULL, 0xF0213F1AB7F9AC10ULL, 0x5FD832506EF54109ULL, 0xF5388C61AEDC50E8ULL, 
            0xE418FD9A4C55995EULL, 0xFA773566751EA1C7ULL, 0x32867A1041FF3CABULL, 0x51132B97B00FCF80ULL, 
            0xF847396048C3C52DULL, 0xDCDAB9F874931378ULL, 0x227A28585D901CF7ULL, 0x3811E163458F7AD8ULL, 
            0x84DA06F708C9F31DULL, 0xA11AF0E5A46A3BBBULL, 0xDFDF9AE47B36DBE9ULL, 0xF6CD6159C40267D6ULL, 
            0xE1E9FF470D5B62EEULL, 0xBCAA3649EC9600C3ULL, 0xF13DF7EB2F720B04ULL, 0xFD6328441016D05CULL
        },
        {
            0x29FFA12D640434C5ULL, 0xF70C5A77C3542383ULL, 0x07BF6447CD08F243ULL, 0x00AE1DEC3B2CF75BULL, 
            0x9F60E57457EBC381ULL, 0xD45A39A43A8AD11CULL, 0x4A98DE27798961C9ULL, 0xE0EAA83FB328D537ULL, 
            0xCD1D72B58C255BADULL, 0x9A1B5E018E265728ULL, 0x0D4325BF9E85A412ULL, 0xEC1275DC9D97247FULL, 
            0x92EDF628EE5BD12FULL, 0x74932EEDB72E5BD7ULL, 0xA7554CADE753DE3CULL, 0xD0CD8AB34B4E44EAULL, 
            0xD66268B744FF6AD9ULL, 0x68273BB4454AF6DDULL, 0x1680099D32D23F5AULL, 0xA1381BCB38EDE3F5ULL, 
            0xCE8F07E148B3E301ULL, 0x2AE71E631C941496ULL, 0x4CED4C1191C026AEULL, 0x14AF58C9E0E48EACULL, 
            0xEC08C70F3A410CE3ULL, 0xFC243DEDAC91D8D6ULL, 0xC17FB813C6142C1DULL, 0x67841BF857505919ULL, 
            0x3E35E7F1710AE664ULL, 0x4DCC0542F991402EULL, 0x9B0998CB2F0A50CEULL, 0x41C14B6559511E95ULL
        },
        {
            0x50D5B5EE3213550DULL, 0xB847D3C9927D8CB3ULL, 0x831A6B31BF9C6490ULL, 0x80F9A118BCE26CFDULL, 
            0x52F36D5F558CD8F9ULL, 0x86B51777763EFC27ULL, 0x28BA6E9DE9886F25ULL, 0x393C09C63E615251ULL, 
            0x83E2226C12D72C3BULL, 0xF1DFBE6A6A89E2CDULL, 0xBDE1F0C2BE946D2CULL, 0x2F6F49A6740919D6ULL, 
            0x42D1FD1D4F507E88ULL, 0xC2CCECB41EE56B6BULL, 0x8032C7D526633C05ULL, 0x89410C834A86EAD5ULL, 
            0xEF56E1CCABECEADEULL, 0x82515F927EE97117ULL, 0xC4E18A260AE8D980ULL, 0x8A787B2DB7E6E98CULL, 
            0x6118BBA954E463A5ULL, 0x91D6A2B68A43467AULL, 0x5BF6849061A639F8ULL, 0x01D2A3E28E975DCEULL, 
            0x04D746A0753F51D9ULL, 0x1FA3DFEB85C13943ULL, 0x698600D676C79FA5ULL, 0x7205423CD18E3ED6ULL, 
            0x0B1106454918D156ULL, 0xA7A9B3648F6BF719ULL, 0xC15F6E326C73208DULL, 0x68C5C08A199EBE4AULL
        },
        {
            0x79E12D6992B31DB2ULL, 0x3F280A5DE409070AULL, 0x297FD2ABB8394D47ULL, 0xAB8451191F8C615EULL, 
            0x2475E1BEDF24F0A0ULL, 0xD3B6ABF1DC44D350ULL, 0x9FDE4E5343BCE2BAULL, 0x35A4A8FB7759742DULL, 
            0x12FA2F1B8A6AE8E2ULL, 0x8844D4D2E5356DF2ULL, 0xB1C44DBCE69E2521ULL, 0xDE66655B70D1766FULL, 
            0x3A0B142CE4798CEDULL, 0x6D12BB0AE9590199ULL, 0xA090C1FDBF2B34ACULL, 0x870B9960CF61F577ULL, 
            0x03468DC26221D318ULL, 0xA6DC3136FF469692ULL, 0x6412C75E683D6153ULL, 0x8B29D2B40A97A74DULL, 
            0xCCED7CC6A2553552ULL, 0x676B7506F1DD991FULL, 0x6AA9ACF4C07B9237ULL, 0x0EF68DD7AE9D9D46ULL, 
            0x72BF2B0F6F78AF12ULL, 0x37EE94D3B6104316ULL, 0x33A1BB766C73063BULL, 0x0FE3BA5760BFA320ULL, 
            0x7C704F5C5981B615ULL, 0xCAF05C8520A8B305ULL, 0xBA18DD05B1C3AB45ULL, 0xB620508433375D68ULL
        },
        {
            0xECAACEA6EE1481DAULL, 0x1471241836BFE846ULL, 0x1AAAD571CEDF16CAULL, 0x35EC8030A0C14782ULL, 
            0x7F6388518E1CCF3AULL, 0xB8B38B772ABE1170ULL, 0x129D731730522743ULL, 0xF395488E70380826ULL, 
            0xBE55218525624EC7ULL, 0xCE535D6A76A5E696ULL, 0x9581D112F63BEE43ULL, 0x6DA8577516FC6DEFULL, 
            0xBF041C93DFB904BCULL, 0x3B4EF63EE7120A01ULL, 0x684189B95793AA10ULL, 0x4E0D0E1F47AA7E7DULL, 
            0x9A0E2339B000AA46ULL, 0x97F3D0628F54327DULL, 0x4AF24A7ADC0A7980ULL, 0x246940FD9990C418ULL, 
            0xBC944B85D9F8E37BULL, 0x9E48C6F865F20065ULL, 0x3F9F5D6CAB88FAE1ULL, 0x5B1FC55879554499ULL, 
            0x983B45BC94A636EFULL, 0x847B8FB384A72BCFULL, 0xDAFB2262B4C430E5ULL, 0x507F4DE3C0FF0FEEULL, 
            0xDE97369BC2990A75ULL, 0x2BA7D2C1AA349E91ULL, 0xC637F52397CF8DDDULL, 0x18C967F2DB554CE3ULL
        },
        {
            0xD2EE2CBE4FE68534ULL, 0x4F29F7F2AD7747C6ULL, 0xB5682583F584D918ULL, 0x8CB486864293D346ULL, 
            0x3F52FC535765EFB8ULL, 0x7F70E88FCFB2B89AULL, 0xBA7FB30FBDBF11DAULL, 0x69C087B7F949ED78ULL, 
            0xA80371D0121FDFD1ULL, 0x1A79BC2DEF2D6968ULL, 0x8685F62F0D034DC7ULL, 0x34D0E9DC783B4B11ULL, 
            0x4A12CA814069B802ULL, 0x1B8BDBC2D75BAF96ULL, 0x9ED3077D334B3892ULL, 0xDDA760093EBD6A92ULL, 
            0x5CA2D7AA264CAB78ULL, 0xE2ACF7CE4A1006F8ULL, 0xACE7A2105B327BA4ULL, 0x72B79E5220B86B09ULL, 
            0x635EFCEC443EA01AULL, 0x6EC2503D4039BBFDULL, 0x27C30A00CC4DD7C1ULL, 0x729B9D468CFF5659ULL, 
            0xF818ECDFFC9D0485ULL, 0x94AC320C5722AC0FULL, 0xDDB8B9F34EA2809DULL, 0x55E79302B037CEF6ULL, 
            0x78DC1BD886D44C29ULL, 0xD3DBCEFDE452D930ULL, 0xC0816570E03FDA16ULL, 0xEA28D6181E944173ULL
        }
    },
    {
        {
            0x64654982393634CAULL, 0x6C85193A91D20AF9ULL, 0xB7A93DE28B696521ULL, 0x3B5CDA5F112160BDULL, 
            0x50C27E3DFF70A42DULL, 0xC13D0F7E9D80BF48ULL, 0x32565C63E572A2C7ULL, 0x11A917E3056416D9ULL, 
            0x18E12771DA778CF6ULL, 0x75B74E7DD6E2DFA5ULL, 0x8EC4E273A4942888ULL, 0xF14C448098030B7AULL, 
            0x5D87892150613A9EULL, 0xD4D7486683A57AC5ULL, 0x5B79E40216CDE3D0ULL, 0xA407B855A7CD392CULL, 
            0xB8CE939DB5D9B2B9ULL, 0x9603B63F33781B3CULL, 0x529AC19EE93D7EE9ULL, 0xA22985A1E838D7E6ULL, 
            0x9BDE9219C74E6345ULL, 0x32932B2ABD1059ECULL, 0xE904B1ECAD06653FULL, 0x7B4F6B7B3FEA4BCAULL, 
            0xEC7C14A749308EC9ULL, 0x14887E63132B8A04ULL, 0x8A8435128768DFD8ULL, 0x354135A15462D583ULL, 
            0x6CA1A13BA4B3BBCAULL, 0xC3D6B91B1560F978ULL, 0xD238355D9802B4F9ULL, 0x3F597F070558A2ACULL
        },
        {
            0x246BF68983DDC6E4ULL, 0x67D819DDC1E97D12ULL, 0xC52BA218DB39487FULL, 0xD2F73B2A2CA4B493ULL, 
            0x507598D6E9081087ULL, 0x4DC5DF6B82672904ULL, 0x6C30F127CDDD8DB7ULL, 0x505C7E345F8C6508ULL, 
            0x8407D5388E613B24ULL, 0x1F2E8793EEBCDCEFULL, 0x1B8C3089F7D65500ULL, 0x06F4A8B45757C269ULL, 
            0xECE4AFE7D3ADD6ADULL, 0x09A4EF23DDFDADD6ULL, 0xAADCDF9EE6BF4E93ULL, 0x74DF4EAE3876566CULL, 
            0x9CAE560F14BF21E9ULL, 0xBB2533E5BF27CDF3ULL, 0x324C2DD6CF5EE61DULL, 0x2A3BA3E5FF4B14A4ULL, 
            0xFB1EEABFB3C4F71FULL, 0x2E686812CB37FE85ULL, 0xE5B9B07496F7486EULL, 0x132A762D09B26665ULL, 
            0x2AF6D25E6387CC24ULL, 0xA25A032CA7928AD5ULL, 0x800F1EE3A4B9AF3BULL, 0xD24232244266B810ULL, 
            0x0970979104F542B2ULL, 0x7B215C764D5B9D9AULL, 0x9564CD2B1F382867ULL, 0xA01684C43EB821BEULL
        },
        {
            0x2769DAAE2779BBA5ULL, 0xAECCEA58AECDEDB1ULL, 0x2D0A694EDC0DA8ABULL, 0x7661AA6F6D54C5F5ULL, 
            0x41423E84DD2BA777ULL, 0xDE4F2210947F62DBULL, 0xDA74EB507994D6B9ULL, 0x882675363ADA5E27ULL, 
            0x3BAA5DF57730821BULL, 0xC734E4B380CF428FULL, 0x5F9668C90677ED12ULL, 0x744A8C1AF9AD19F7ULL, 
            0x3302891F257D43C9ULL, 0x58C107DB472CF10FULL, 0xB60AEBDB36B312EAULL, 0xBED0500968234FACULL, 
            0x85075044BF0B89FEULL, 0x22CCC75B93A7CF60ULL, 0x82CD879F748BD942ULL, 0x8F7EC730854AC603ULL, 
            0xAE6EB669214557F0ULL, 0x0A40EEF42B58A5BAULL, 0xC18B3D82DAAA6B3CULL, 0x0468A7EFE6917B30ULL, 
            0xFB156CACA912B2E6ULL, 0xFD1825531FBC6E27ULL, 0xA80366587B81692EULL, 0x5FDC19737E95F09BULL, 
            0x4250CCC68090EC03ULL, 0x1D66D91E3E9B506DULL, 0x81EB9586F4E673F6ULL, 0x9553200D685772CFULL
        },
        {
            0xE1B1C8CEEDF736FCULL, 0x51F862DA0D69FEC8ULL, 0xCE04995B267A7B46ULL, 0x198655DD9B750BCFULL, 
            0xA13D2DBE70C442F6ULL, 0x8DA762983274DC2CULL, 0x87D96C6F6551E96FULL, 0x77595B8145904E71ULL, 
            0x1881507DA11FD49AULL, 0x94B6D71E66A0D443ULL, 0xD53D2B91AED59D73ULL, 0x479F785204A64E48ULL, 
            0x770C2AAB556EC9FCULL, 0x236F8B2F5D379A89ULL, 0x490DE53F1267DF57ULL, 0xACD6BA1D92688689ULL, 
            0x9B5E0928B9319BB9ULL, 0xBF7E6787E40609A0ULL, 0xAE59FC14F8CCC94CULL, 0x056714E168951EC5ULL, 
            0x16238294E1230ECEULL, 0xFDC9BF40A466AE55ULL, 0x4382689CC79172E4ULL, 0x7870DA3A253FE235ULL, 
            0x27A4194EC25B01D1ULL, 0x5F4C696439133E35ULL, 0x84DF68521C5377D8ULL, 0x7F9AF2E1E1E4EFFBULL, 
            0x48E85CF31C8C4315ULL, 0x5DB0F92048BF6DF7ULL, 0x4AA256778E9FBB75ULL, 0x91F7EF7AB0EC83C8ULL
        },
        {
            0xB21969CBDCCDA3BEULL, 0x9EA4D74C95667238ULL, 0xD288D63755EE4ADBULL, 0x9429AA20C872313FULL, 
            0xB29DE41CEF30EF5CULL, 0xF79BC43BBCC13917ULL, 0x56055FF80C0E716FULL, 0x6F4EC48425F62A23ULL, 
            0xA03F6FB78E4EB3C8ULL, 0x43BBE4212E29B90DULL, 0x71E250198FA2D5A0ULL, 0xB69A7E908DB74F83ULL, 
            0x7EDBC2255E98768CULL, 0xAC962B1BB3732D93ULL, 0x4D6010ECF9D795BCULL, 0x35F6E61C78F32B02ULL, 
            0xE1F3EC54024386F1ULL, 0x1E197B3F14A1CB2DULL, 0xBA1172FB9F181AE4ULL, 0xF323EDBEA50A1B42ULL, 
            0xAAA27E6635DD5DCFULL, 0x5F96DFBC1CD8872FULL, 0x26E3B10827FED4B5ULL, 0x925E1B06B99B14FAULL, 
            0x703FAA1D5632B6AAULL, 0xF2BACB8ACBCBAEBBULL, 0x9E8C835BF3E780E0ULL, 0xAD3A03447DD476D1ULL, 
            0xDE29016F286BB17FULL, 0xAF3C5AA1B595CDE4ULL, 0x5B4EE53670DFFA0EULL, 0x15CDA1D1FE433EBAULL
        },
        {
            0xA835B0D069FEF701ULL, 0xC919C886E1C109D9ULL, 0xB5850ACD23542810ULL, 0x67B0B982E6AB2B9AULL, 
            0xAD4F7D6B569A0BFFULL, 0xDB6061B37C4F9137ULL, 0x179437A1AF25CDA6ULL, 0x1F16545596EF78ACULL, 
            0x910F5A4EBCA8E45FULL, 0x08B476978FE6B63EULL, 0x768AA5111709F055ULL, 0x4C74C575E6C43602ULL, 
            0x4DFBAD6A2550A337ULL, 0x768217F48DC6F721ULL, 0x0B5B4324BE63D0CDULL, 0x9E16225891AADF15ULL, 
            0xFA598AE83EFF3C24ULL, 0x0300A5395BC895CCULL, 0xF9AD9CE440B95EEAULL, 0x24CADB6FAC3C6187ULL, 
            0x772B07BAD5C1A23AULL, 0xA9AFABB152B68414ULL, 0x9993D48655212F3FULL, 0xBE77467FE4714BBEULL, 
            0x536051E9F745557EULL, 0x97000C23DB3F7BA3ULL, 0x9CB92637274A2EBDULL, 0xC76AE976115131BBULL, 
            0x159AA5CDDACD1718ULL, 0x617229379763B312ULL, 0x5913ED7F6C04D4E0ULL, 0x3B83F0073F74E343ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Sirius::kKeySpawnAConstants = {
    0xAC4C405412D6E2AFULL,
    0xD9151404639BDACCULL,
    0xCDFF38DEBB93C3D3ULL,
    0xAC4C405412D6E2AFULL,
    0xD9151404639BDACCULL,
    0xCDFF38DEBB93C3D3ULL,
    0x77702EE59603AA63ULL,
    0x53A44AA60A1405FAULL,
    0x24,
    0xA9,
    0x82,
    0x13,
    0x4D,
    0x6D,
    0xB8,
    0x7D
};

const TwistDomainSaltSet TwistExpander_Sirius::kKeySpawnBSalts = {
    {
        {
            0x0F133AAB3FDA5837ULL, 0xD210B4D6AAF7D8E1ULL, 0x2A1E4B28AB3A274BULL, 0x6AADF8FCF7F8F1C2ULL, 
            0x426ED90335AB6066ULL, 0x95CEFE360788583BULL, 0x3F50D2FC549CA649ULL, 0xCFB961B6269A767BULL, 
            0x6ADFF3A1186921F4ULL, 0x55E3A5681963C92EULL, 0xB190180F95CB1215ULL, 0x1782C5F9719AE77EULL, 
            0xD1A0E4C33CD80641ULL, 0x73EB0E84E08A29C5ULL, 0xF1875FD9809519FAULL, 0x8418AB8F2019BA2EULL, 
            0x05BC2291B6D1FF9FULL, 0x728010E3120999A5ULL, 0x3DB1793B16E6A383ULL, 0x7C44965B0B00A454ULL, 
            0xA75B03C7C51FF065ULL, 0x33D36D2C45740FF4ULL, 0x6A905136F1EBA56CULL, 0xE608336ADA43AD16ULL, 
            0xE2E418E3D529D852ULL, 0xCB89BDAEEAF355B7ULL, 0x51E1DDB2E15807A4ULL, 0x09266AD71BEE54B4ULL, 
            0x3EECA4857E64254FULL, 0x25EC611507CBCE43ULL, 0xABD1B319E7B502FDULL, 0x4BB7BA913FC52686ULL
        },
        {
            0xCDA15A29439213C1ULL, 0x8032ACE5C025A05FULL, 0xD172080D4C2D3D99ULL, 0xAE007AFD8375036BULL, 
            0xFA0BC38707E83F87ULL, 0x8422F984B849A6B9ULL, 0x74255AAD822FC5DFULL, 0x37F30A738A3D1263ULL, 
            0x67B4BA0A31F91FD3ULL, 0x7EFE969BF11023F0ULL, 0xC2A53CD4B6DA02B0ULL, 0xD10FB585B8DDC809ULL, 
            0x831D97B86FB08083ULL, 0x83D2E31ACAC31403ULL, 0x42EE0C1A258371F2ULL, 0x8C70B8DD1F2B837EULL, 
            0x3FA0A398DEE3777FULL, 0xB58B0E70F4D0F945ULL, 0xF7397390ABB7397EULL, 0x03041A3D412607A6ULL, 
            0x9366A6276BE4800EULL, 0x44FA555316502F49ULL, 0x1313BF26AD956ACAULL, 0xB16E31CE2211788CULL, 
            0x1140505156F3A9D1ULL, 0x20085532A31E0B4AULL, 0xE1CCBBF106532077ULL, 0x643B388ABBA08EAEULL, 
            0x973EDDCDAE2BBF2AULL, 0x6F4CE2210CF3087EULL, 0x241310078CED3DF8ULL, 0x9280649B09A22AB1ULL
        },
        {
            0x9F259895C43C60AFULL, 0x172ACECC700753D5ULL, 0x43C0AC0D72F1C259ULL, 0x8A60F7E960C898F9ULL, 
            0x518B016E06B9A806ULL, 0xCE0C92DAFB384AD5ULL, 0x1D708B35C9EA6392ULL, 0xBD9C822347DBCA60ULL, 
            0x2AC3925C1B583E9CULL, 0x453653E771F4D0E1ULL, 0x020E37EF6FB6608AULL, 0x00D2BF11F21F441EULL, 
            0x61F2CF16FA386C1CULL, 0x7B004E93C9DA169BULL, 0x427D3CCD1C20726AULL, 0x2AA3A5979218C154ULL, 
            0x483070543D13CBB0ULL, 0x8429472BCC331D93ULL, 0x3E726C588BB98512ULL, 0xB0E3D3C9B5C86C6AULL, 
            0x2C9991119642E5E0ULL, 0x54DC6C39E6652681ULL, 0x09D9A619E9A79C50ULL, 0xA4D166C08FF0835FULL, 
            0x22CC4660BB5A32E2ULL, 0xFD54D25C596DE978ULL, 0x774F6EAE49371D8BULL, 0x52E3D66AE4D8AB91ULL, 
            0x566AD93E72FD9B59ULL, 0x05D63E74C4B9855BULL, 0xEB439D131DD3C646ULL, 0xAA442F3F2851E20CULL
        },
        {
            0x7F410DE5FF7FDFE3ULL, 0xE010D994ACC9DFE4ULL, 0xD2E1C0D3886EB127ULL, 0x7445CAFDCA9ED754ULL, 
            0x0A35488CDE4D7A1FULL, 0x302AC6B6F67038A8ULL, 0xA5A15C20A54E5F39ULL, 0x089912685B159BFEULL, 
            0x68DD1E413426410BULL, 0xF4202491B400B70EULL, 0xDEE090CA1C0FDF91ULL, 0xC9BFD52131B2AB98ULL, 
            0x9FE3A446E0D80AF6ULL, 0x77576AACD68C861BULL, 0x7C3BEB1AEFB91249ULL, 0xAA267B36CD831437ULL, 
            0x85A6EB40C45996B7ULL, 0xD95279A97BCE2673ULL, 0xC6761681998EC06AULL, 0x3CB62E3A22734167ULL, 
            0x2C03F012DA8EFE79ULL, 0xC3D001C6DF594732ULL, 0x3D6E8FCD2678D528ULL, 0xFD0B1628CFB96C2DULL, 
            0x44F0658805FD06B9ULL, 0xABF3BCCE7D6B019BULL, 0x40199AE765857986ULL, 0x3B1722EEF1CBCC3BULL, 
            0xF015B486A7959F35ULL, 0x2ED573CE87042E88ULL, 0x9394B3FE37EE2932ULL, 0x6A678708E5E8B820ULL
        },
        {
            0xE5D68893325D0D64ULL, 0x071C8AC5E5DDC50CULL, 0xE736B01ED38D0293ULL, 0xEB265A5AE0045149ULL, 
            0x43FC9F06DDEC2C7DULL, 0xB214DF170276B749ULL, 0xC94E02F583868944ULL, 0xA8D1FFBEFC8A102BULL, 
            0xA8B2172D2F2834A9ULL, 0x54D3AF9FB0F98CCDULL, 0x96EB9C986F9D9B29ULL, 0x0F09423F6E3E346BULL, 
            0x5BB8E31331E3E342ULL, 0xC95224BA41A1EFE0ULL, 0x57FC02454DFB7DDCULL, 0x7715B8F292C4EB76ULL, 
            0x8A7F69D609491E80ULL, 0x9728A7FADE6D1BB9ULL, 0xB1C2AA4B770F7D23ULL, 0x19860B8C13080AE4ULL, 
            0x17D025C6E9A98B02ULL, 0x430FDC20790149E3ULL, 0x5C882C2310E5F706ULL, 0xE697A07A42BCA860ULL, 
            0x538A97B84ED793A9ULL, 0x76DCD832CA3187EEULL, 0x4AB898C8DF8FBAECULL, 0x92681FB15DE0E876ULL, 
            0xF3DB232281C72651ULL, 0xAD864801FDBFEB2AULL, 0x1E011187BB1FBD8AULL, 0xFA0256A9E407655CULL
        },
        {
            0x2BA899003C61045EULL, 0x41E23D6AFF967AE7ULL, 0xB35BF9F2EC0F8404ULL, 0x25C1E0CFFBC3339DULL, 
            0xFA1190949E8E7D23ULL, 0xCC6B0BC6E03E6DAFULL, 0x2B1E34BD79CFFA3DULL, 0x0B5419A33042D85EULL, 
            0x03E74F901AC2BAB7ULL, 0x5CE62B70AF047525ULL, 0x64236F557106F4F4ULL, 0x1ADE78CC2E8F50D2ULL, 
            0xF0FA4869ECA8A4EEULL, 0xA5FB1703E57B0358ULL, 0x95FC75D3047E88DEULL, 0x8A454BC9ECA10A85ULL, 
            0x89CA1FBA0FC2F7BCULL, 0x710E08B01085820FULL, 0x88300F5E48936CC1ULL, 0x7CE8D3AB0502D191ULL, 
            0x9F0F878CE1C34BDDULL, 0x8F37C959B8367359ULL, 0xDC9717F63AFD0629ULL, 0xAB69412E35534D87ULL, 
            0x6058E419D22364A3ULL, 0x84418C277E66B8F8ULL, 0x798C23FDD0301308ULL, 0xB90F93550E4FF61AULL, 
            0xF62EB2C3148621E8ULL, 0x0907F13FAA142A66ULL, 0x1759F162D29EC59CULL, 0xFE7E53DFAC07ABC2ULL
        }
    },
    {
        {
            0x5A30CB9DAB99A8CEULL, 0x104C40426BFA3185ULL, 0xEA657416BAF5B0F5ULL, 0xAF12F5EFD22D8939ULL, 
            0xC09237FA460D44DAULL, 0xE949B3DCB174161FULL, 0xD0968E8BA1C186FCULL, 0xDE951F212B6FA1FEULL, 
            0x175EE465DC55FA1EULL, 0xC0C6AAE1EA517A2CULL, 0x535B2C771E979069ULL, 0x82B5A483BF83B999ULL, 
            0xDCA8CB101BCFB171ULL, 0x5E3BB31E92EACF58ULL, 0x5542C0DD2ED2DFEAULL, 0x6DB9B358C5C7F649ULL, 
            0x41BE9C35D6B692A8ULL, 0x6848FC99FB999D62ULL, 0x506BE25448847D60ULL, 0xDF47E9416CE2842CULL, 
            0xA28CA0D8C38552A1ULL, 0x4602751D6BC9B32AULL, 0x5153CBFE5BC74FAEULL, 0x5D8BF29B2DEA3108ULL, 
            0xA9E56E3B5CF1ED83ULL, 0x9BDAD0B59265D608ULL, 0xB93D87F4E42AF249ULL, 0x9DEA64E6D7538B8CULL, 
            0xCA20B8EAFCF197BBULL, 0x86933713F7AA29A6ULL, 0xF886CF3788A1DA76ULL, 0x88B82B5925FB6414ULL
        },
        {
            0xDE00AFC5AF790CF1ULL, 0x93DD5EF0F09D45CEULL, 0x9A00747B213AA202ULL, 0xB32749378D0460A5ULL, 
            0x341CB53BD8B84D27ULL, 0xAEE495A1E87AA153ULL, 0x9576079B92E5D447ULL, 0x499AD21D8A82398BULL, 
            0x9C5659DBA769552BULL, 0x588579F4B52BA668ULL, 0x67CBC63469EFBBB8ULL, 0x6286C2C61321751CULL, 
            0xB99E564F707A298FULL, 0xB2B73E6446C5534CULL, 0xEB3569ADECE4A60DULL, 0x7C464068BE951E8BULL, 
            0x6B75C7BE21CEE418ULL, 0xBBFCE71874AA84DEULL, 0x812DB190A119D767ULL, 0xB33E2AAF2BCAD4CDULL, 
            0x48A37821648E4D57ULL, 0x8B6C4C6F8DAC6BD0ULL, 0x91BD390FD006BE2FULL, 0x4A4EF0F702EE4EA3ULL, 
            0xE440E9E334E63CAAULL, 0x6A98CB941168D08AULL, 0x202A0CAFF459CA37ULL, 0x0384C4B221201B1AULL, 
            0x95FAE4EF677EC37AULL, 0x23C2E90BEDA761FBULL, 0x9630D2B09662316AULL, 0x71B64B54A8DBE40DULL
        },
        {
            0xAACE6B822A151F46ULL, 0xCD245292AE5A848EULL, 0xB02C4EC60A6DA1B5ULL, 0x4B0680B22B86362BULL, 
            0xAD7477BD3C9824BBULL, 0xC0174D328E1BA9EBULL, 0x91455F7827CCF2E2ULL, 0xAE63EBFC33F5C5A2ULL, 
            0x960967C09D5517F2ULL, 0xC88146C489B4AEE4ULL, 0x3D98018D82CC8B4BULL, 0x153774AEE6B92551ULL, 
            0x74678A347F222056ULL, 0xA50C15EA8C6A0EE7ULL, 0x836B1CE04615CB56ULL, 0x7AB8462D1DFC5D07ULL, 
            0xECC2FD4EF2CEDF7AULL, 0x5BA1B6BF0DEE760AULL, 0x158B539B6E433446ULL, 0xF56182509A576BE9ULL, 
            0x1260B2E24ECB5980ULL, 0x031C96997901B8C3ULL, 0x47EA3FEA5A15D6B6ULL, 0x6699CE273CD99127ULL, 
            0x767B47C0CAAC89AFULL, 0x405AA26528552407ULL, 0xC4B75803FD86446CULL, 0xE19697911A5A8B3DULL, 
            0xD78DBEC1644EA437ULL, 0x3DEDB9BDCA64CFCAULL, 0x211E61FA42A9CCCDULL, 0x96F3BE9906DA11C6ULL
        },
        {
            0xAA92535C1A9FD679ULL, 0x6E87BE673B7C4A57ULL, 0x932377DC9890EE34ULL, 0x4BBA259C0DE70FB0ULL, 
            0x38C7E2D470B66A75ULL, 0x9FD6CE4B2D757A33ULL, 0xC2E09072FE6A8AB8ULL, 0x99B68BB7953CC622ULL, 
            0x3D67CDA05C6B6001ULL, 0x814FFE6E0F9B6707ULL, 0xEEE867DBF6EBB6CFULL, 0x2336747D09B6AB44ULL, 
            0x705CC70A37BE7663ULL, 0x2CC44794FA2993D1ULL, 0x66A967FBCAFB027DULL, 0x3F09E36A494B025FULL, 
            0x23D7D6B5EE303BE9ULL, 0x8B0B8AA2E7752197ULL, 0x34D393E359C2F6F7ULL, 0x9ACF9FC5EED41FA2ULL, 
            0xC050EEED58D1D282ULL, 0x12FFEDB51BFD057BULL, 0xB9E3122AE84C9719ULL, 0xB18C97AF827D027BULL, 
            0x9602E19CEDAA7727ULL, 0x5C59F2ECC6973199ULL, 0x2E02A069398F5FB5ULL, 0x57F909092779F117ULL, 
            0xFCEB53F58E8584F8ULL, 0x63EA139A479CA0C5ULL, 0x6A13D488E41E7A25ULL, 0xB1619F2BEABA525FULL
        },
        {
            0x674551E2924CC652ULL, 0xEAC324395A5421A2ULL, 0x160ACF5B91AFB0ABULL, 0x2A1089FBC32BBE30ULL, 
            0x136BDEFF61E1318DULL, 0x252184F9E21E9D28ULL, 0x86079D2ECECF35D6ULL, 0xA2FAE5769D7DD871ULL, 
            0xAA4AF27AC5C07526ULL, 0x7A321AC35288A930ULL, 0x7F3C86C6E4A86F1FULL, 0x979A24926EE90EF5ULL, 
            0x4CC697EC4DF480CCULL, 0xA27F5E33076F0581ULL, 0x447BF255A8B22EDDULL, 0xD916C89F342DAEA4ULL, 
            0x737D13D67E5ECF42ULL, 0x31B0970BE086E7CEULL, 0xD49DBD592D2EA483ULL, 0xF76631872B386EA8ULL, 
            0x44A6BDE15E17ED07ULL, 0x272A90F8E8D2CB36ULL, 0x663B47BFA4A46303ULL, 0x9269C976E20110A5ULL, 
            0x5A781A4E7B7EE67CULL, 0x393F7F8835E61583ULL, 0xD3C292A8451AF551ULL, 0x3766B95E35854BB6ULL, 
            0x24C906B78CA05C96ULL, 0x8D81D51E90DDD0BDULL, 0xDFC755295604ADFAULL, 0xC40D108F517D7ECBULL
        },
        {
            0x1E811D64EE178663ULL, 0x3DF317A4A8777602ULL, 0x20328E5B5A46D482ULL, 0x4BC84CB2FFAC9E86ULL, 
            0xA54925CA3E182166ULL, 0x46F78B938A0C7852ULL, 0xE6FC66C33766F735ULL, 0x62D7257AA62E573EULL, 
            0x5B5AFA6383BD644BULL, 0x053D616B50004E8EULL, 0x9C6D5342FFB66F8DULL, 0x1E9D3B9C915B3F92ULL, 
            0x3F3C1DA13F75E40FULL, 0x340131A454EF670EULL, 0x7CD5597031D13AA0ULL, 0xC1605557F66A6696ULL, 
            0xF776973295EE4CF0ULL, 0xF438588B435F97ABULL, 0x6C68ECE79CDB6ECBULL, 0xB5A9B92B2310C343ULL, 
            0xE06141B1768DC153ULL, 0xF9385F4F78FBD06AULL, 0x5610FA3F8A9C67B7ULL, 0x8506CB2864526D2EULL, 
            0xBFEFD0E56DDE8AE7ULL, 0x3C61AC74AF3C134FULL, 0xCDB5491D797BC107ULL, 0xD26818D04B538D5FULL, 
            0xA558F1C8C79259EDULL, 0x6A069D5EE1B7DD59ULL, 0xCAF7B2DECB77A851ULL, 0xE1CB57F8E348F4C4ULL
        }
    },
    {
        {
            0xB13BC89726CE14F4ULL, 0xA79F05456E144540ULL, 0x984C99AB39235B08ULL, 0x6DA64A9F19C05E34ULL, 
            0x43C15DFC9363274BULL, 0x8582727DA82D370EULL, 0xE9518222C8A7024EULL, 0x939551349E61E2D9ULL, 
            0xA709D7D267499FF9ULL, 0x24C8A1C078F9BE1FULL, 0xA395125188488F81ULL, 0xF47C0351AF3CAD8EULL, 
            0x5A3BB0062A9CC412ULL, 0x3B7701F65BF4AB7AULL, 0x5911FEC0ECC4B066ULL, 0xF19D82C8CCDC9E60ULL, 
            0xF446A2A41F9C5EA9ULL, 0xD5E961AA72C17637ULL, 0x99486943A819B179ULL, 0x3FD0213422D6C331ULL, 
            0xDC38876770BF296CULL, 0xED5C93F56923BFD9ULL, 0x42F8778003588A17ULL, 0x84D45FE572E22AB2ULL, 
            0x0E23591A8D1B3B0EULL, 0xDAF8365A65455A17ULL, 0x9DF10ABE922E8FAEULL, 0x68C4DB3102EF7A5FULL, 
            0x11F57D4347ED3DDFULL, 0xBD77527D7C80402DULL, 0x8270BEB07E9495EBULL, 0xBD416775C02D39A9ULL
        },
        {
            0x1CD4D248EAF33C94ULL, 0x0E119A32C714ED58ULL, 0x543928ED394FFC23ULL, 0xD457E3AB6FA153E3ULL, 
            0xD883D1500F6D470DULL, 0xD7F06E1D18EEABC7ULL, 0x579EDA765456E900ULL, 0x9D3795E9C0FD4CBFULL, 
            0xFC9D2BE7C23AD993ULL, 0x0F034CC8ED62E733ULL, 0xCAE50A434E8C38BFULL, 0x7C8BA0390F0B9E89ULL, 
            0x58536A61D9930A7FULL, 0xF1C1AC4401F5579CULL, 0x03F18AB83561D19BULL, 0xC068FB2991AC3D75ULL, 
            0x86055F0632A0E0F0ULL, 0xC694E8BF509CD395ULL, 0xE32A5EA6B8A01AC2ULL, 0xB90B2866B85CAC12ULL, 
            0xE9AFF3D508CF8F05ULL, 0x7032ED0203AD61A2ULL, 0x6558850E9E7A9BF2ULL, 0x6366832BF82171F5ULL, 
            0x70C4DC1C1757B580ULL, 0x20E7802CF1F948A4ULL, 0xCDB4639CBDD5D5C1ULL, 0xF9C72177FB1E3EF8ULL, 
            0x227297A69F025497ULL, 0xD914C1BE99CAB7BCULL, 0x3FD4BA9CF355D199ULL, 0x5DAD5E6C12BEFE34ULL
        },
        {
            0xD34C164ED69B76D0ULL, 0xA392DC73DF587B64ULL, 0xDBC3EAF120848F0BULL, 0x954F218C803D34D2ULL, 
            0xEE6F0C4E352C72E9ULL, 0xD5D5B492508E1C86ULL, 0x59A164FB3BC4FA82ULL, 0xE6F12C1FB926C2A5ULL, 
            0x2DEAE4D77BCDF706ULL, 0x01BEAA0176AD1779ULL, 0x1B431BEE49EFB2E5ULL, 0xD9ED6D73E1D60A59ULL, 
            0x759A4C4713AB6849ULL, 0x19CCCAAF46A7E026ULL, 0x8202E568F9285599ULL, 0x721F1B497DE88BC0ULL, 
            0xAE189432C93C67FCULL, 0x359E63D5939C2C46ULL, 0x77D6A21ADA419551ULL, 0x1C1D49A73D2C0F11ULL, 
            0x7B7EB6609CFFD537ULL, 0x5A61AA29ABF38F59ULL, 0xAC99F373A0F6B7C8ULL, 0xE027D13DBA6E112CULL, 
            0xBCAE84FB4321A387ULL, 0x7238CB52043E18B5ULL, 0x743BDFA7EF480C1AULL, 0x62380FACC8348418ULL, 
            0x4BCFE3EA078931FDULL, 0x218DDAE6F2879D4BULL, 0x691CD0030D2B7BCAULL, 0x5FCF86D3405656F5ULL
        },
        {
            0xB27F197AEC4C7538ULL, 0x1F2C0DCB32317DDAULL, 0xBBE602EDA86E04EBULL, 0x30C50A9000E8F5C8ULL, 
            0x6E498827A475733CULL, 0x9AA400944567CEDAULL, 0x251703F119BD6E37ULL, 0x4BBDA80E9EB7ED4DULL, 
            0xE4CE864538AB566EULL, 0xD5E51C7EE90535BAULL, 0x09FB59BA86CC5A38ULL, 0x1F4152A99BF501C3ULL, 
            0x41E0B407104945E2ULL, 0x114B7E17D00D86C9ULL, 0x18C629CFE0D0FE05ULL, 0xD97DFD7DB69A2483ULL, 
            0x9D46604A42FA01D8ULL, 0x18EDF94B72F1888CULL, 0x29BC5B698393D843ULL, 0xD047238B90F3B8A3ULL, 
            0xC1AC61D54A958C98ULL, 0xAECBA486D804A983ULL, 0x222400A724D899F4ULL, 0xF671AFE1175DF32AULL, 
            0x531E0BD6DD072E99ULL, 0xE52D4E1FB83A0F9EULL, 0x97F5F39BDB755065ULL, 0xD39524008B801471ULL, 
            0x628401B8167C9AB3ULL, 0x398C0D4A66118269ULL, 0x72972DDA2056A4FFULL, 0x73985D21CC3F7DC0ULL
        },
        {
            0x74EA0F401B0424F5ULL, 0x56CCF1D43F58496AULL, 0xBD52174F8969711AULL, 0xC36DBE77EE5C07B1ULL, 
            0x39E5E2809674B6AAULL, 0x17AB3BDE89998E6CULL, 0x4EFCB6F25827627CULL, 0xC1F9E0DC5B6ED989ULL, 
            0x875E9F4ABCB945DFULL, 0xE496CCD9EE798CD4ULL, 0xD4F3E65580C50F48ULL, 0x5A9D17E76A6CC8FDULL, 
            0x9BE530980287E952ULL, 0xC2E0A9FB5883050BULL, 0x9D8523A33F0662CAULL, 0x561C7284D98C0983ULL, 
            0xC56C30D186756BBCULL, 0xBF877451E2E80A61ULL, 0xCC63BA1269103545ULL, 0xC62B3709E52CBD3CULL, 
            0xEB7D7A2C94DD7420ULL, 0x2694FFCAA5004F75ULL, 0xCD480CCCDA5CCA76ULL, 0x45D3328757662087ULL, 
            0x13E44BF0BEA30F0CULL, 0x41E6BDB5E140E301ULL, 0x49AD084B373F1A60ULL, 0xB8EF7256B41BCDD6ULL, 
            0x1D9D54126AFDC372ULL, 0x545B32370C35C524ULL, 0x9EAC290FFB0B45F6ULL, 0xBBE5A8813DE702DEULL
        },
        {
            0x2926969F5A1E294EULL, 0x5B5A3E80FE019600ULL, 0xB739B49E72D495B7ULL, 0x74A6FA10C1F0F872ULL, 
            0x7742B6C70A9E2372ULL, 0xC21A6AA155D9DC88ULL, 0x0A32DF3C7917FBBDULL, 0x272CAA64CC1AA391ULL, 
            0x3AE4BBBE1C23118CULL, 0x1D21ACEEE243B802ULL, 0x033D73B74C8C8CB0ULL, 0xC9F0858EF0D5ED20ULL, 
            0xD7D232C220F86492ULL, 0x5FABB20C9668564DULL, 0xE675A939DA92DD35ULL, 0x772816EC9BF5D3CDULL, 
            0x375D3BAE56BB14F4ULL, 0x457C763C13D55695ULL, 0xFE4B12BCA25B52D5ULL, 0x8A5E251D70B1A44EULL, 
            0x87F06E46B0BE798CULL, 0x95E46C01F4337E38ULL, 0x3BA2481036F9C797ULL, 0x9774783655F21438ULL, 
            0x2410AFC904FC600AULL, 0x7CE77CC071AE0E8BULL, 0x4954BA4F645EE28DULL, 0x557497CB41E7D158ULL, 
            0x199FAFBE289FBBFEULL, 0x58B8DCAB1C47CE77ULL, 0x3A60CF670AE3FBBDULL, 0x91536653DA243853ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Sirius::kKeySpawnBConstants = {
    0x2A2B11D38CFD7A0FULL,
    0x310401DE07D115EEULL,
    0x46534AB288A600F7ULL,
    0x2A2B11D38CFD7A0FULL,
    0x310401DE07D115EEULL,
    0x46534AB288A600F7ULL,
    0x9836844395C543CAULL,
    0xD17351D61BF6F4ACULL,
    0xA3,
    0x16,
    0xE7,
    0x0C,
    0xD2,
    0x29,
    0x7A,
    0xBB
};

const TwistDomainSaltSet TwistExpander_Sirius::kSeedSalts = {
    {
        {
            0xC06DA197993380B7ULL, 0xBE907E088672B1E8ULL, 0x6580F9D141490CB9ULL, 0x1FAD16333CC2A3DEULL, 
            0x5C6493AD76858A6EULL, 0xC781E55EA906521DULL, 0xD4A3FFFC959A65D2ULL, 0x742E48E7C862D583ULL, 
            0x75E41C15937676B4ULL, 0xBC820AAD88758561ULL, 0xAB5FD9372EF25DD8ULL, 0xE4FFA0B1661E3438ULL, 
            0x4CB7D16318B78269ULL, 0x7CF3DAD4AA3B7F33ULL, 0xF92EE2E4A7C4D15CULL, 0x1D2B03D40C40C221ULL, 
            0xA8796F65F6CDA46FULL, 0xA55D45BC06358636ULL, 0x1CF19A940ED70D55ULL, 0x1B8B59BF6F675325ULL, 
            0x1CF1BAB8004E3503ULL, 0xC6458A46B354ABD3ULL, 0x4610CB2D8B027F3AULL, 0x41C6C7247BE8EF2FULL, 
            0x75482D1D7D0DDA52ULL, 0x49E84A843AA2C899ULL, 0xA62594EEA3C560B2ULL, 0xBCFB5A722487564CULL, 
            0xDA89D150DE8F8E16ULL, 0x6D8517F596E925F2ULL, 0xDABE013AC14FF56AULL, 0x92B51451E58F306EULL
        },
        {
            0x2658744526924252ULL, 0x202F15A60205456FULL, 0x225DB4657DFD9777ULL, 0x179B3B913E1E49E9ULL, 
            0xAC3B04632BCBADE4ULL, 0x623AB02517FA9B8FULL, 0xEA00A1B01CE2AA51ULL, 0x18A3DD5AC5D0049CULL, 
            0xA3490F3E50046758ULL, 0x6A05D825A2CBF63DULL, 0xE1D370F3A799B242ULL, 0xA5FD6F7D2930217EULL, 
            0xDB81128558B88C70ULL, 0x0D629E5CE09F6BE4ULL, 0xD7BE19D5875563D8ULL, 0x368187F849EAAEA4ULL, 
            0xE5F2244E235F38E7ULL, 0x552014E5BE0EA7A7ULL, 0xA7ABD779978163C8ULL, 0xFA3D9DF0728C22CEULL, 
            0x19F08507A08E8CF1ULL, 0x4655BB3DCFFF3F83ULL, 0xFC828E926ABAE2E0ULL, 0x8196603B9BD8CD0FULL, 
            0x07B7169212A3BF03ULL, 0xD1D1B5D36687620EULL, 0xAC112978F3D1CD81ULL, 0xECDD2774E350D4AEULL, 
            0xFC11D2F9E27F19B9ULL, 0x798BFFEABDD248F6ULL, 0x1BC9F2C109536F42ULL, 0x748B2D634A03D1C2ULL
        },
        {
            0xCF2B46D3561B3363ULL, 0x436C8FDE8D820B5DULL, 0x5E14D5C9A92DAA24ULL, 0xE74291AC85F3F53CULL, 
            0x85E70779E729CC29ULL, 0x2BF8B28BD42D89BDULL, 0x4A439F28E4357FEAULL, 0x3CEE160C348AB983ULL, 
            0xF08CB95C9E830CBDULL, 0xEE972217A602804BULL, 0x3B15C9B71E50DF72ULL, 0xE51769DAE13BF300ULL, 
            0xA6C62E4C12F52140ULL, 0xEDAD215A60173829ULL, 0xC02A4FF337363CCCULL, 0xADC596DB31BA2A42ULL, 
            0x7FC47853E7864A23ULL, 0x2FE1FC7C050BDAC7ULL, 0x749FB9D7B5B9F5F1ULL, 0xBE189AD22684E875ULL, 
            0x99B6E53DB8BCD0CDULL, 0xDC0DE36A52FBBF45ULL, 0x03070CCD5DF39D20ULL, 0x7499EC0B5668F524ULL, 
            0xBC9C3DDB331A4F95ULL, 0x2E0AF17CFAA825E4ULL, 0xD386E5A560BA5092ULL, 0x657BA43960CDCE2DULL, 
            0xEE1D9ED817C49593ULL, 0x497CB922CA2495DCULL, 0x17C60F4F11CBB283ULL, 0x96D7E932F814B5FEULL
        },
        {
            0xABD202AB5D442FF5ULL, 0x399BCBF1F2023380ULL, 0xDAEBDFA53BF21F42ULL, 0xA11655468D3E7C6DULL, 
            0x161E44B01179676DULL, 0x9C4E925B4D8428B5ULL, 0x0CA3F748A6F2551DULL, 0xA52FAB2A0E9D32FAULL, 
            0x82ED0D5556220B83ULL, 0xDC4E4518326FD99EULL, 0x81E220053A8CADE7ULL, 0x2684BA6C895FFBB6ULL, 
            0x01E58F2A90701E6DULL, 0x902B22178656D3ECULL, 0xF2A30CB15E1B637DULL, 0x87DE4BFBFC901683ULL, 
            0x2A4C0D3D45BF1C87ULL, 0x620707903FE27E01ULL, 0x27EA28DD2B781C20ULL, 0x6585B2FF982659FCULL, 
            0xC4080D14F7625820ULL, 0xAE5393FF894F89C5ULL, 0xD63C34F5E8B759C1ULL, 0x6873550FAFCA723CULL, 
            0x67217948B47A1A92ULL, 0xA7ABFB518C1ED5C2ULL, 0x3655AAC5A1C579AFULL, 0x77C392059CA901C1ULL, 
            0x24AFCCE7A48E8D02ULL, 0xCE46BB367E45E2FFULL, 0x8F8261B6CB6BD755ULL, 0xBF13A13C0F7CC9B5ULL
        },
        {
            0x41B731CED14442D8ULL, 0x56F6BBC2BDDD1B8CULL, 0x6788206F58485E5DULL, 0xB5C296F93EC95F01ULL, 
            0x42E4240A0495581EULL, 0x61424BC48379507FULL, 0x025CD7DA2213F884ULL, 0xB239B6D129A57549ULL, 
            0x1259A78BD35EB039ULL, 0x5006197FD834A513ULL, 0x05E6814937CDB9B2ULL, 0x304939FF70382324ULL, 
            0x20A489BA801DEAF5ULL, 0x7D8CF0E9C67FE18AULL, 0x5011A80E6ED6E147ULL, 0x2B775A1A94B9D1A0ULL, 
            0x647E40C46071E83FULL, 0x125947BEE6EEE0DCULL, 0xA9D0DBDAF888F080ULL, 0x326517F8BED02645ULL, 
            0x3D1EC37B7F4E4D87ULL, 0x161037DE42CEECC0ULL, 0x346DBBCD6945C7A3ULL, 0x35DEBFE0596B51A7ULL, 
            0x0C7BAE8DB6453DD1ULL, 0xC021DB74AF9D7072ULL, 0xCD7914F6A4C31FF7ULL, 0x333694C7672D69F7ULL, 
            0x588C56A13209BF16ULL, 0xDF1E8D8F042F09F4ULL, 0x9333B822A7CF8BCFULL, 0x60BD63FCDE7599C6ULL
        },
        {
            0xF85F2F64C841D84CULL, 0x540BFDFFFBDB1D8BULL, 0xD5278988C3B8FF38ULL, 0xEC5C4A485661CADCULL, 
            0x33C9316320667E59ULL, 0x7B180A6C5770DF6CULL, 0x95204FC538D8067EULL, 0xD2E9AF775A942FAFULL, 
            0x81B6B029AF68C057ULL, 0x50E5D087DCD2D361ULL, 0xDC5A4519AF289E55ULL, 0xC88DA34A3C17CC1FULL, 
            0xB0E5AE81F7FBB8DAULL, 0x20958FE3B4A56259ULL, 0x64DDD47B76FDC6D1ULL, 0x160364C304661DC2ULL, 
            0xCB781CB55DF30EDDULL, 0xA08E658F0903C3E9ULL, 0xCAB3E84C2DC65364ULL, 0xF24B28F16A5EE54EULL, 
            0x64408C74C1533D8CULL, 0xDCCC1043EC20D710ULL, 0xB9710B65C9C1F659ULL, 0xC1989FE5DD2A69C8ULL, 
            0x4021B90C1E3180AAULL, 0x2B32CD209F2800E2ULL, 0x7C084FC603DD50D3ULL, 0x05E3AC57C2FB8D43ULL, 
            0xF03C57F7E79CEEB3ULL, 0x3E22B91A810F6707ULL, 0x5733B7EBAFD51CF2ULL, 0x9FF8E6115257F7B5ULL
        }
    },
    {
        {
            0x46B68586E64A32E3ULL, 0xCE2500372E05A445ULL, 0xA0891D4DCD8ADE28ULL, 0x7BCF2442F54A3E60ULL, 
            0x520FF65C8DB17AD4ULL, 0xBDC119B339BA63ACULL, 0x7459113375111670ULL, 0xDB71F5E0645D193CULL, 
            0x12536AAA8AB9E797ULL, 0x1286F9A51ADE7702ULL, 0xC8327ABF18813E95ULL, 0xCFF59F5525AFB8BCULL, 
            0x884392676EB9B3F6ULL, 0x3EF00CADDB4EB6E7ULL, 0x28778F5DA9BDC6AEULL, 0xD797DE6C9F99DD11ULL, 
            0x62543E16ECBFAA0DULL, 0x884E4BBAE71C870CULL, 0x2349F7248EFA53FCULL, 0x274B3ACB09072E40ULL, 
            0xCB97BF13B7ECEB79ULL, 0x36FE44672EA02C80ULL, 0x41ECCBED9730DD0EULL, 0xFBA3D0483FAE16A7ULL, 
            0xB3EECD8D9A6DB468ULL, 0xB5E5321D0962639AULL, 0xED0FFFA2089E22B2ULL, 0xC0A2292F77D8ECBDULL, 
            0xA6F845198CEA8BBBULL, 0xFD117EF3731E5625ULL, 0xA3309D1CFDC12678ULL, 0xBEF4BDA26D75282BULL
        },
        {
            0xF20E238AB1DB55B6ULL, 0x3E4E083127E9CA58ULL, 0xD8CA7E5AE729F255ULL, 0x86879D28880C432FULL, 
            0xB26F9179A90AD1E7ULL, 0xBBE6396B414272A2ULL, 0x0D4B44E6186DF944ULL, 0xF137338C6B4470C5ULL, 
            0xC99B86A38D071806ULL, 0xC88E335C96FFB2B1ULL, 0x9AFD16C60028F48BULL, 0x126A50AA245DB7E2ULL, 
            0x40DA205B139A15A1ULL, 0x555E0D551E46B2D9ULL, 0x6F30CD0572D06FB5ULL, 0x56B9E679568117A8ULL, 
            0x1190E605A629CA91ULL, 0xB0D716619827139BULL, 0x54639536EC477CEAULL, 0xCC50FE0A8FDE7E46ULL, 
            0x656B70176A928C1CULL, 0xC246E52715EF883FULL, 0x52D2610F275DF49DULL, 0xEC53C7D07FCF35F4ULL, 
            0x40AE08346464D01CULL, 0xDAE7FB83A4D7AC14ULL, 0xF382F873DC607C55ULL, 0x6911391506E9C4EAULL, 
            0xADBC6DE0FB8DAC34ULL, 0xD45C926EE6DAA07FULL, 0x35571DC3FE0D23AAULL, 0x592DB57E65DE71CAULL
        },
        {
            0x603BC89AD2C125B5ULL, 0x5EED64EEC2E2A43EULL, 0xB07B21078D534033ULL, 0x4A1528BDC1EAEB6AULL, 
            0x1EA5B64B45E141B5ULL, 0x3A0185ED14C50229ULL, 0x48E1280B9378F430ULL, 0x237E893B7B1E2576ULL, 
            0x30F254982922127BULL, 0x625E3EF74F94E7A9ULL, 0x41A3DBF173F8FA6FULL, 0x0BFF15CCF3A9070AULL, 
            0xE94BF23BBA830696ULL, 0x86159950F4718BEFULL, 0x22F5197BF2B990A0ULL, 0x6967666C6FB07BACULL, 
            0xED4DD2AEEF182C7DULL, 0x889BF3F08915A319ULL, 0x5582EC2A8CD6355FULL, 0x1C7F3E77553BFF8BULL, 
            0xFA02ECE582137F42ULL, 0x245ADAA3257EB0CEULL, 0x03FC4A512A9E97B4ULL, 0x6FBDDB7E20CA895AULL, 
            0xB8FE6D1536B120A6ULL, 0xF2D7A3D10E866D3FULL, 0x08AD18F7D817BA89ULL, 0xD8E3F992C132BEFBULL, 
            0x26B12F90BF8B3F31ULL, 0xB5C7B14FF1375EE1ULL, 0xBE81055EBF2F684AULL, 0x457C2BAB2077F44DULL
        },
        {
            0xCA125644641218D5ULL, 0xC06F6516DBDAFA02ULL, 0xEB71BCC33B13EE27ULL, 0x051DB1AD2232DA12ULL, 
            0x206FDA98FD423DAEULL, 0x73043AC447E447E1ULL, 0x4E0E740CAB662038ULL, 0x545087E69D0EFBDFULL, 
            0x3875FEDD8326CA78ULL, 0x85171832255D4A34ULL, 0x2D57DA14CA045827ULL, 0x23EB746A5E47FE93ULL, 
            0xC1C916F6BED29ED4ULL, 0xF2FD9068F98FAF7AULL, 0x7C39C435F4901442ULL, 0x88959D7D68F0A32EULL, 
            0xA4BEC3615C6480BFULL, 0x2BBB2593778C2B3EULL, 0x70B83C96E1B04E14ULL, 0x6E6DAD722ABD744DULL, 
            0xDD47B1006D81886CULL, 0x4DEC789E88A1CB77ULL, 0xC8CE88B9F9213900ULL, 0xDDC8AF60637FAAE4ULL, 
            0x04D798132AD65580ULL, 0xA7478AFF360224B6ULL, 0x5F91208B7620C18CULL, 0x08D482C2F5D58A27ULL, 
            0x1A4E541D2FD3D828ULL, 0x55DC7662532F4942ULL, 0x7F2D51BE9BE96218ULL, 0x50068FFA004721CEULL
        },
        {
            0x994A5E7C69447D38ULL, 0x2D1D63606C59FE03ULL, 0x1E1066B82AD66D11ULL, 0xEDB7A7C23E6530DDULL, 
            0xCF6E8F65AB54C993ULL, 0x939FFD1F1C7007F6ULL, 0xE26E0DDA599FCEE6ULL, 0x54133AE037364F35ULL, 
            0x5B3066D4BD851ED0ULL, 0x216C2DD4B0DE5420ULL, 0x79BBCFE04E09BF83ULL, 0x505C5840F239FFF6ULL, 
            0x402D1F7AE83E7CB7ULL, 0x44565E4287E4974BULL, 0x06120D2845E7048AULL, 0xA3CC832FD7F8F9A3ULL, 
            0x3A6487C15E177F98ULL, 0x5B99F0979D6F9104ULL, 0x57B367FFFE337E74ULL, 0x0A04D78EA95E82BBULL, 
            0x67BDADBA7F5C54DCULL, 0x30A79F2A712D8FD0ULL, 0x061EEBAAF50D5A26ULL, 0x11019BCFD7CDC49EULL, 
            0xBD0ED76F87EE3A8FULL, 0x1A28C8FCC1AF2341ULL, 0xB3F46FE971F4251EULL, 0xB4E10FB228A1AECBULL, 
            0xC2E00DF05879494BULL, 0x419C5277CD0F3EE4ULL, 0xBB04FBEBAA68ED75ULL, 0x8C876F8906E81413ULL
        },
        {
            0xA05EABD4C3E8B4A1ULL, 0xCAC00D40D5E7A141ULL, 0xF6C6DE37DF846EC7ULL, 0x84C329C2BCA18E82ULL, 
            0x3347CA514C965697ULL, 0xDE43A3DF37672687ULL, 0x2A50A22624BCC4E6ULL, 0xEC24AE318B84200FULL, 
            0xA1B114AF7B31704BULL, 0xBD16C46B41964AEAULL, 0x272136AE875219E6ULL, 0xB95A4047AC645220ULL, 
            0xD9203A5CE9F5EADDULL, 0xE51714BE68132910ULL, 0x3DC5956A95E98BD7ULL, 0xBFFA0287B87EAA97ULL, 
            0xB5F2CE08ABFD1818ULL, 0xC50F4970F75C58C9ULL, 0x548F9FB8EBC17202ULL, 0xA70DC2EC6F43161EULL, 
            0x1B8FA838E1C8EEB8ULL, 0xB47308384103EAFCULL, 0xBA1B5E3D7B21D245ULL, 0xDB6C9A306DAA7EB1ULL, 
            0x6934CB016EB0FA43ULL, 0xE473D67EE5C2A79AULL, 0x252CBA90D29D846AULL, 0xFFF531EC47F90E50ULL, 
            0x2B6612B4C910AA67ULL, 0xED4806E0ACE89F18ULL, 0x049271BCE8BADC33ULL, 0xCAE0CBBD639B9AEEULL
        }
    },
    {
        {
            0x3AED09817A7E8D12ULL, 0x4A9D85F77A00618AULL, 0xB2C811F3D1E4205FULL, 0x00AAD7836E3BAD4AULL, 
            0xA3FA01046400664FULL, 0xAED0A0C588969D66ULL, 0xD475CAA33C28DA45ULL, 0x7EE134E238338BACULL, 
            0x0690744828CE44EEULL, 0xF4BD013695903CCDULL, 0x87F4E9BDF8637304ULL, 0x95FEA9490D729404ULL, 
            0x3EB828234CDC11FBULL, 0x5B50C6B593CFF273ULL, 0x1C1450A17B95B4B2ULL, 0x996AF3F364496539ULL, 
            0x8DDDE3AEA35123FBULL, 0xAA0E3FED712CC2A4ULL, 0x0B20285A062DD125ULL, 0x8FF8296229DE5F75ULL, 
            0x22BC2E3DBDF02067ULL, 0x3BC4592D730E46FEULL, 0xEC09C65796893F17ULL, 0xC0F20DE4B27F1E19ULL, 
            0x31C8BB48D1E1AF2CULL, 0x73197E8B49326FECULL, 0x91147F41F53B9596ULL, 0x07C89692ABFBDE3DULL, 
            0x70EE93395BC597E2ULL, 0xD90975FAB566446EULL, 0x342B1B96BCA1CFDCULL, 0xAC7CFFDE3AAA8118ULL
        },
        {
            0xAF4895A8C5A660DCULL, 0x75D29F9DB2475B9CULL, 0x86CDE5E9032055DDULL, 0x2508D6D72027ADA6ULL, 
            0x4B6637BA3E4AB968ULL, 0x396191A03FE7FBB2ULL, 0x9C06B41B5F223443ULL, 0xD86FE1719A351209ULL, 
            0x33A9D1429BC31597ULL, 0xE3AD9F3B71ED69DAULL, 0xEDB738019DE422E1ULL, 0x52EF6251B116E17EULL, 
            0xD072878F5E269EA7ULL, 0x9FD0C6186A499989ULL, 0x2D812A1991337F18ULL, 0x3BAFDA96498618F0ULL, 
            0x162BBF079859C1FFULL, 0x3BBD74B912130147ULL, 0x4B5967041419D340ULL, 0xA8ECE8DC4C10DC37ULL, 
            0xEB04A1B7D34F020EULL, 0xEBD0EC108BDD0096ULL, 0x0A3BCAF6F9857D13ULL, 0xAC62741ECF6199C6ULL, 
            0xBBB0317DB9B57938ULL, 0x8420FF9A8FF332EEULL, 0xBB492440AFEEADD9ULL, 0x985DFFE34D49D8ABULL, 
            0x83FCA164FA07B87DULL, 0xB197212F81C9FA9EULL, 0x26AF5EFB1BC0041CULL, 0xE828F6F4946BAAC6ULL
        },
        {
            0x7E12D20C1C36D5E0ULL, 0xB530DF21A814454CULL, 0x94C904171241C859ULL, 0xD0B1AB39A23951DDULL, 
            0x1E77C671785B9D67ULL, 0x01DE338A51279DB3ULL, 0x71F1A7EB3421E58DULL, 0x115377D0AD871C78ULL, 
            0xEC4F8831954161A0ULL, 0x854A3C71BB456B9EULL, 0xCD3599EC7B669A13ULL, 0xDD5F64074D4ECD07ULL, 
            0x60514B9783092E60ULL, 0x74CDE43570F16ABCULL, 0x54DAEDAC98252AA0ULL, 0x9A700820163D62BDULL, 
            0x7F00CAEA6F30AC84ULL, 0x067DA4F69E0B5C84ULL, 0x557730F541D9831DULL, 0xDCD66AAB3E12530BULL, 
            0x0DEA7D7BD6BB8D56ULL, 0x608367BC4AED6AE7ULL, 0xC47362E8E83C659CULL, 0x84B085D174144A2FULL, 
            0xD62DC54CF71B600EULL, 0xBC24C4514FAE097BULL, 0xEBECDBA2938681AFULL, 0xF7A0809664D5B075ULL, 
            0x14F465C74CBA0C3EULL, 0x2334F27733D595BDULL, 0x152EC0E6EA2532A6ULL, 0x8E210BDEFC35B4D8ULL
        },
        {
            0x34C61BBC3EC33568ULL, 0xA3001725E6EC7CC1ULL, 0x47C5CF3BC2C25948ULL, 0x672462B30A4D4415ULL, 
            0x3187028A42B66F9BULL, 0x7AD0D8755CAE318EULL, 0xFA3869129C8EC606ULL, 0xE4CCCB8883731422ULL, 
            0x555B99ED7F59788AULL, 0xA48E188D7AFE0B73ULL, 0x5319FEE7A933B428ULL, 0x17932B471B30DB48ULL, 
            0x56A9E9D61F8A1BA4ULL, 0xD2C1E11554C1945AULL, 0x276FFB29E53CD85FULL, 0x2EEE00FF905FA17EULL, 
            0xC374D2325EE0C5F3ULL, 0x79C48810FE5337A5ULL, 0x40AB9C5DBDE5AFF6ULL, 0x3C29A93AA8352381ULL, 
            0x3093DC6578411D7DULL, 0x65F1F22EB656D432ULL, 0x25868074B3AECB35ULL, 0xC71855C36BD8A744ULL, 
            0xB01204E2F86B1764ULL, 0x8C53866CFF9B8CC3ULL, 0xD34CA3D7360B3B80ULL, 0xB9512D1854DD76CAULL, 
            0xB949E4760EDE3A84ULL, 0x844543109E93A315ULL, 0xBBC9CA57DFE2310FULL, 0xE991BF3568D03CBEULL
        },
        {
            0x095516C6B553D139ULL, 0x8590FB9A9EA78D78ULL, 0x01C5AA1275493C39ULL, 0x0F2DF95C1E27B303ULL, 
            0x5D51EB643870F66BULL, 0xC215361D293271A2ULL, 0xED82B42BBE647AC0ULL, 0xCF44C6C5F47A3D43ULL, 
            0x8D6C6F4157B7B2D5ULL, 0x413592D11DB3F928ULL, 0xC5907A09E792736EULL, 0x7D67453CD2FCAFF6ULL, 
            0x8A4684BECD02CE91ULL, 0x94C0A88B53512D2AULL, 0x5F8DE0ECE11B10B3ULL, 0x460C21079D7093BAULL, 
            0xD1460CD4A581C2A6ULL, 0xFE7D5DC801A84375ULL, 0xFE2D1F19FA922D13ULL, 0x0422A8788740EF7AULL, 
            0xAB5074EC4C0E6559ULL, 0xF3FD7C63850B3A54ULL, 0x93C98980F080551BULL, 0xF6505C4C8E0D7467ULL, 
            0x2ECF1D96511CB697ULL, 0xFB668197CA46AD2EULL, 0x76AB129C9FB552D8ULL, 0x92AEDF563236A820ULL, 
            0x87C939BBB1E23203ULL, 0xEE7E34B74771A693ULL, 0x6526F745B70FC858ULL, 0xC205F757D17667DEULL
        },
        {
            0xBB82CC59A2EB12A3ULL, 0x9284339ECC5771F1ULL, 0xDB253F8616B9D986ULL, 0x8CD78D8EA52FF6A4ULL, 
            0xC923138DA99F7885ULL, 0xE13D89C2BC05B387ULL, 0x2C0299377C978DB4ULL, 0xE18208CBA4ED223FULL, 
            0xEDA9D15A59797F7FULL, 0xFB766D3480778C22ULL, 0x13946B4BA4880D93ULL, 0xAFAC78E5E0A5EB6CULL, 
            0x8F5FD5ACAC5840B6ULL, 0x972F27FAD69FA633ULL, 0xA53A874914C6D029ULL, 0x7A5A6CA094A7550EULL, 
            0x320807A46D35916AULL, 0x2394BB73DBC4D3F8ULL, 0x5375AC3ED2A626EAULL, 0xFE714A0C40B7DDFDULL, 
            0x0F8938BCFB04A0ABULL, 0x6B2B9E9F9FE25BBFULL, 0x7DE6F4F1C37EB71FULL, 0xA890753419D4478AULL, 
            0x778DD800FFC006CBULL, 0xA4A5B7740024E0D3ULL, 0x31FB9E215FE40861ULL, 0xCC2A74B6707B5AA0ULL, 
            0xE32CAF1D2D60F23AULL, 0x97CABE796D3754E8ULL, 0xA28219484BA12C00ULL, 0x13746E7C59012329ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Sirius::kSeedConstants = {
    0xB8E77332157BCD7DULL,
    0x4D3E12109FCECB13ULL,
    0xDA58FD077F5AEA21ULL,
    0xB8E77332157BCD7DULL,
    0x4D3E12109FCECB13ULL,
    0xDA58FD077F5AEA21ULL,
    0x63BBB43236A2413BULL,
    0xEE5B68BC4050E409ULL,
    0xE3,
    0x1D,
    0xB6,
    0x5C,
    0xF8,
    0x86,
    0x08,
    0xC3
};

const TwistDomainSaltSet TwistExpander_Sirius::kTwistSalts = {
    {
        {
            0x6BFA7D987BB2E168ULL, 0x214B47393C04BF09ULL, 0x3F0BA08E49EEA3BCULL, 0xA3F483834E6E0E55ULL, 
            0x9164CC95CC171363ULL, 0xAD1E633BE68B93B4ULL, 0x401F0E5EE5244272ULL, 0x4A2FAAE3C88F910DULL, 
            0xB51D7DA126447607ULL, 0x59C28A7F69146EB7ULL, 0xC08468962930BCEFULL, 0x9B3D242E1BA8681FULL, 
            0x090F37938D0615B3ULL, 0x31DBCF74A026E319ULL, 0xF79B439EC62EBBB7ULL, 0x0760D2246F146524ULL, 
            0x5C5A97F891E1480DULL, 0x25A45375D5423BAEULL, 0xE162A40A50FA8845ULL, 0x380B693053753CFBULL, 
            0x445180B10DC937D1ULL, 0x9FED2C9ADD2E8D68ULL, 0xFCF4B227C28F94D0ULL, 0xC3E4D82A510C5BD0ULL, 
            0xEE18BED08859C681ULL, 0x754A8E3EE9752122ULL, 0x467443A5DCF4BA95ULL, 0x51BD531F69D3FF8EULL, 
            0xDE2F26EDFCE76DDDULL, 0x648A88301EE703A7ULL, 0x57F06058B9C122D8ULL, 0x0795CC7C521AE665ULL
        },
        {
            0x74F1FB962EF4217EULL, 0x8EC2F824F6865E3DULL, 0x67A134445A13E52AULL, 0xE0B667EF6C73162CULL, 
            0x8A953E02D677A59DULL, 0xBA5009052701C4BDULL, 0xDB6EB84D0432B95FULL, 0x8CDAE0EA418543F7ULL, 
            0x2581B54789AC97ACULL, 0xFF1BA22F6904253FULL, 0x89C342ED16F84BE9ULL, 0x8B1C69E3F10C3036ULL, 
            0xF70D15CA6C470DD8ULL, 0x7F915C14DC2AE18CULL, 0x37D2D829F6D41DE5ULL, 0xAF01A57DD49A70BBULL, 
            0x6DA43AC1CFC94C10ULL, 0xC32077687674B1DAULL, 0x94CD4D731CE8E2B4ULL, 0x5E69AA34FE29F3D4ULL, 
            0xFF58D86353417B3AULL, 0xADC9450AAF95B577ULL, 0x01CF68577B6DE24BULL, 0x49B51C6469F88279ULL, 
            0xA66FF9454F894C71ULL, 0xC1CDD96BB4D4AD06ULL, 0x7CACBAC481AE2BCBULL, 0x62BB75216CC9BCFEULL, 
            0x7D730C28D9F5502CULL, 0xFE6FF368E3B41797ULL, 0x8D20BC3DB81F4D2CULL, 0x21C066455202E540ULL
        },
        {
            0x176394C67E8CC7EEULL, 0xF6732EBF61FF69BBULL, 0x5117C578D8A9B160ULL, 0x18E7BD4194BB694BULL, 
            0x2DAC4D45BE58131BULL, 0x27F6D9ACD1F7E6FFULL, 0x45FE5732A90DB63CULL, 0xD0287920D0898175ULL, 
            0x074C7B210825E5CBULL, 0x2104ACA8AAE920E4ULL, 0x6CC01426AEF5756FULL, 0xB510762FE51AC06EULL, 
            0xA9A0ED0812A465D6ULL, 0x22D268B3C3DC9E95ULL, 0xEC54027FBB172B13ULL, 0x553D82610B986E68ULL, 
            0x1FDB7D2863F75E42ULL, 0x4A3CD52721830603ULL, 0xD28D4B5D9FA9C6B1ULL, 0xAC26B20CFCDEDBC8ULL, 
            0x83F7501C4049E31AULL, 0x9D85D60B034693ACULL, 0x4172E85CD8E9F66AULL, 0x1FA6F21C9012FAD7ULL, 
            0x0351680B7EB1DD7FULL, 0x9077F68E972D326DULL, 0xDB8513E2CE9E2C5FULL, 0x472FF91F7058C3A5ULL, 
            0xFD5038D1DEE52302ULL, 0xBDDD39E7F0F03141ULL, 0x09E68AB91CE06A60ULL, 0xC44C3B580BB54989ULL
        },
        {
            0x20B4DB308B641542ULL, 0xA815CFED50E54FD1ULL, 0x8D7ABA2208195F6AULL, 0x499CC01212B0C807ULL, 
            0x3B58C77A860D7346ULL, 0x898083274EBE21E3ULL, 0xA62D14D2ACB3DFC2ULL, 0x11891D2D3F6C41EFULL, 
            0xE45842890230BCA6ULL, 0xB2DE1EC6D624BAE8ULL, 0x02E3330FB4459985ULL, 0x242636CE57A3D53CULL, 
            0x03A1345B65188C00ULL, 0x7439F4E9010D319AULL, 0x4851085EF90AB9E1ULL, 0xD705B8A667D8742EULL, 
            0xC46F2339F02FCFA0ULL, 0x547A1895623CF6C8ULL, 0x14E1156337F790A0ULL, 0xBC2D3AE8886E6DDAULL, 
            0xDE54F7DD8834FE1BULL, 0xA93ABAD46D6C7584ULL, 0xD9F2844CF9E22BD1ULL, 0xB67A73256333DC3BULL, 
            0x585F68464A23772FULL, 0xAD43F88CAA1510E2ULL, 0xBFA6CD23928CA56EULL, 0xEFACF0E24AD6753CULL, 
            0x943DE2DAA09DDEA9ULL, 0xE00E3F3AC96527ACULL, 0x07E830B15AF1EDC4ULL, 0xB7E4B89F90156D5CULL
        },
        {
            0x0875C96404E91D24ULL, 0xB255FA3DBD7778D9ULL, 0x4C2FD114AD31F5C7ULL, 0xBFF010DC8C952AA8ULL, 
            0xBC981D7AB1C39DBCULL, 0xB7DC2FC62CB941D7ULL, 0x1A5C2C3A6C17429DULL, 0x8EB15A58F754A922ULL, 
            0x5EDBA5FF7CE437C4ULL, 0x6E130458FDDD9A0EULL, 0x22D8D37E82CF6623ULL, 0xDDE87D619CEA3875ULL, 
            0x19976BF75B7B6FFFULL, 0x364A7A48313E559AULL, 0x17E121A9D5B7FCEEULL, 0xB8CB922245F53928ULL, 
            0x745B6C04B5918AF7ULL, 0xF620E221A8BA67C4ULL, 0xFE0B4C0A81126E3CULL, 0x791ECBE25C34DB62ULL, 
            0x80218A34DBAD84C0ULL, 0xC292205AB0DB4648ULL, 0x9DCC055587F7906FULL, 0x4837B8FD50AB3FC6ULL, 
            0xAD8D9923FCA48D66ULL, 0xC3E852400B6EF882ULL, 0x41436839019D28F5ULL, 0x1519CC5B920EDA3BULL, 
            0x30E5F7C4BEFBF911ULL, 0xF9E69322CFDFFCDFULL, 0x3B3455EAB8E3091FULL, 0xE82DC3715C62A44EULL
        },
        {
            0xCE8AFCC3C8DBD6F6ULL, 0x7E81830EA857CF9DULL, 0x0F7F4B5348839D8FULL, 0x398059DA8E8839CDULL, 
            0x8421371AE0BE04BDULL, 0x34C425A819856AF0ULL, 0xC2951579F6B6EDCCULL, 0xF47943A021D7D07DULL, 
            0x28FB34DD6CA8227AULL, 0x8EB2ABA6A42376A2ULL, 0x69E9489FDF27CE10ULL, 0xBDC6AC25C43D68D6ULL, 
            0xF080F5510F30F15BULL, 0x3DD758FBE9B90F4AULL, 0xB2ED617D97D60899ULL, 0x3FC466770FA7B95DULL, 
            0xA98E102B570AA8F0ULL, 0xF07EB84B895DCD18ULL, 0x4CC843716E6BFFE3ULL, 0xA018E96E1904A866ULL, 
            0x69569E821E43CAA4ULL, 0x174199C3A10CE74AULL, 0xFBFB8BAE96EF78D7ULL, 0x69815EACFA6D92E8ULL, 
            0x4D48F932D5105030ULL, 0x7A0BD54B7D08A79FULL, 0xB235CE8A2B349FE0ULL, 0x36627A59A4DCBDEDULL, 
            0xDCF750710DFA523EULL, 0x2A238972012E2F40ULL, 0xAAE8F2B3A02B9C8BULL, 0x38BE730A501D2877ULL
        }
    },
    {
        {
            0x9C10209B00F75526ULL, 0xD39029C7E7C5A51EULL, 0xBC328C74277FE3B4ULL, 0x5BFDBB1DBF4BCFC3ULL, 
            0xB279110D245FB44FULL, 0x51EE7809B07924FDULL, 0xCDDD51B7EE838CE3ULL, 0x687E58EABF7B35C4ULL, 
            0x603A4F2BA5B75AD2ULL, 0xC93EE07D25126273ULL, 0xF5DA91504E68FF25ULL, 0xC0A18441039EFBE7ULL, 
            0xD9314F07242A634EULL, 0xEAA708F462F12D20ULL, 0x0F7F1F9A90F97B8EULL, 0x39A0760CE6BD5BA3ULL, 
            0x263DAFBADB70D3E6ULL, 0x2192AA8648FDA145ULL, 0x5B01895ADE274DE7ULL, 0xDC46435C216735F8ULL, 
            0x8CA600B0926E6C54ULL, 0x94FA59FFB76252D8ULL, 0xAD9CA01F9AD21ADDULL, 0xCE5BADAF308A7012ULL, 
            0xD57572F526FF5525ULL, 0xAABE0F76FDE4AEE8ULL, 0x10D52B768D37B5BEULL, 0x9FC87643895C8897ULL, 
            0x942AD31583ACFC9DULL, 0x53F2B2F6F0EFE6B2ULL, 0xB4E9CFEBB9DB421CULL, 0x2765BE1697777415ULL
        },
        {
            0xB6ACA28306F42147ULL, 0x7D1B3569E0A9C78CULL, 0x957CC40199FA65A6ULL, 0xBA36C115B48FD2E4ULL, 
            0x8D45D0E52FB67916ULL, 0x1A2E68FB01FEE670ULL, 0xB78569E7990900E6ULL, 0x27E9C18C62D4D99CULL, 
            0xD197415A1DA0743CULL, 0xCB834673B7AC51FDULL, 0xBFB0854267A1C7FFULL, 0x17C2BB8DF66B8D19ULL, 
            0xB927D0B3BC3AF36FULL, 0xEB32EF18D84FFFAAULL, 0x8DA624A0F47B196CULL, 0x228F3B40D61A1936ULL, 
            0xEA86F05BE9810F69ULL, 0x0F39146CE201B6DCULL, 0x4549A6C964E84A4FULL, 0x5E38CDB5B0C9E8B6ULL, 
            0x2C82ECEA2D0E7B07ULL, 0xA222DA8A0BAA6999ULL, 0x7F333D8606D315D9ULL, 0xEC044C713003DD5FULL, 
            0xF94CAFCB95C56367ULL, 0x8A7CDC3CE487E84DULL, 0x8B8706D577E971EFULL, 0x854508C7AC58027AULL, 
            0xA8979AA42B9FD9A6ULL, 0x7E416895B5FE04DDULL, 0x7E00CC6109222669ULL, 0xA17E98C056717863ULL
        },
        {
            0x9241CD345384BB81ULL, 0xA34369E5F64CAA94ULL, 0x0441C3B181A9D95EULL, 0x519C4910FED1F638ULL, 
            0x208563CE48CFF239ULL, 0xDE2DE72818DDA22FULL, 0xBCB4B627033F4364ULL, 0x434B33F5CC013683ULL, 
            0x56B44E45621A8525ULL, 0xEF1543E46C7F7A4DULL, 0x6DFACF61D3C047B3ULL, 0xEB74E12C94F15523ULL, 
            0x01248471D5D954E4ULL, 0xD60F25C736353BBBULL, 0x5077384B45937C84ULL, 0xC91D9B849C9EB71AULL, 
            0x1F7C207F4CC60BF3ULL, 0xA64DB5DFF0C242CCULL, 0x47E316E0D1A63F92ULL, 0x475F77867F158252ULL, 
            0x2A5DAD544A98F3DDULL, 0xF47474A9A23C4A14ULL, 0xD273F35F1C6A6A84ULL, 0x06F2CD84851B35CCULL, 
            0xE61B67EF9B67C6D4ULL, 0x76EB8F8C11CCB919ULL, 0x730C291FC032CCE4ULL, 0x7A8519435B85EAAEULL, 
            0xF707B20A8FE7E26AULL, 0x1F0970D3993D80D8ULL, 0x1188BA05B85FC8BEULL, 0x3DC4CE82505D5FA2ULL
        },
        {
            0xD11CA64795837F1FULL, 0x41D836D0DFDE2A53ULL, 0xC3754C37B5811A9CULL, 0xA355A747BDCFE80FULL, 
            0x186BF16AB7978FEBULL, 0x5C55E5F992516844ULL, 0xB891FB23354AC748ULL, 0x0FD357631C180637ULL, 
            0x06AE3FC95B1F0AEBULL, 0xD7B649075E70FF85ULL, 0xB68BEDFDC2F81606ULL, 0xA7C69ADE3F2825A9ULL, 
            0xDF24C724360B2C70ULL, 0x69953B1DEE932D01ULL, 0xF69747FF7312B357ULL, 0x966E86BE6398E98BULL, 
            0xE1948D3DC18883A2ULL, 0xD1BB0AEDD631B379ULL, 0x9CD318F76647928FULL, 0x3305DA2FD534B1C1ULL, 
            0xF82E6EAC12F5C4CCULL, 0x5F6D91B2AA9969E6ULL, 0xBF2B1FF12154C989ULL, 0x717D5ECC6DE0E965ULL, 
            0xEA733509DA87D482ULL, 0x9DA4A116533643FCULL, 0x5E2261FDC02D02A5ULL, 0x830BF3CA8B76D10BULL, 
            0x03853C6AA29B006AULL, 0xF01795C77992572EULL, 0x8FFB11535E7DA3D3ULL, 0xBF202F3B05B1DDE5ULL
        },
        {
            0x429DA61E8BAC5F9BULL, 0x93522F19DA43DF14ULL, 0x6910C84A15A2D975ULL, 0xABCD2DB1BE20BAB6ULL, 
            0xCD6100CC85199325ULL, 0x607875DB4E681BB9ULL, 0x9D110B1A1141E158ULL, 0x42526A46CFA007F1ULL, 
            0xA81F4DCE9225A7C0ULL, 0x45C127A757E70864ULL, 0xC72AE2A619A72219ULL, 0x351AC9DE251F8FC7ULL, 
            0x86D6DEC1FFDF852CULL, 0x7F62BFA2763E3CD5ULL, 0xCDD088E39E563752ULL, 0x3CAC6E3C153620F0ULL, 
            0xCFED825BF955EDCAULL, 0x2F466CBB4207CCC5ULL, 0xD11A89ED7DF0D8DDULL, 0x90275C9B3C432867ULL, 
            0x00E0DD78FDB53AAFULL, 0xCBB9841BBB1F39AAULL, 0x9AA1CD60D97DC745ULL, 0x31100DADCA2911E9ULL, 
            0x3B2425D89A855476ULL, 0x6AE9C41E067ED7DFULL, 0xAA5C55E5AFC2E66EULL, 0x5B5FFDF9DC308046ULL, 
            0xF01BFEE8F205F9E7ULL, 0x9E35C6E79A27371CULL, 0x263707A2A073B8E7ULL, 0x86102EFC8B2FAF71ULL
        },
        {
            0x6CF975074DDD4843ULL, 0x86E584B3C6A18421ULL, 0x9697EDE8D60E24AFULL, 0x060145B337EA517AULL, 
            0x24BD553173778FA8ULL, 0x38B86E4A0E6AD23CULL, 0x204DA651B7A20130ULL, 0xEF33E4CD712C3C36ULL, 
            0x3544579BC7CBE6BAULL, 0x6F3CD60E80D72402ULL, 0x1B51459514736AEEULL, 0x9F89C62410F5E580ULL, 
            0x0D4C809C5EBE21F2ULL, 0x39E179F51856F769ULL, 0x2FB7BDE060DCCB45ULL, 0x2FB2428673F3D2EBULL, 
            0x76AAC0AB3E754D69ULL, 0xDFC1982FC4222471ULL, 0x5EEBAB084C2142F6ULL, 0x198A0CFF3BE9BE22ULL, 
            0x6E889CA35A76938FULL, 0x99CE7B1CFFBD5BD6ULL, 0x17545C3D7F89CB4AULL, 0x1313CEE90DB90F5DULL, 
            0x6EA291C688A441D8ULL, 0xD30111265ED4DB67ULL, 0x7968F1F0881E2288ULL, 0xBF1AC8BD47B1F687ULL, 
            0xB0209267D296D03EULL, 0x301DB0EEDD47D465ULL, 0xF73D74C02955D5A7ULL, 0xC0484D884368C550ULL
        }
    },
    {
        {
            0xBD9D838EFA9144A3ULL, 0xDE70BC1B70A44AECULL, 0x064D4A221A2EAC8FULL, 0xFCFFCD844B2D3527ULL, 
            0x3FB8C82DE697D5AEULL, 0x565CB46BBDCB9887ULL, 0xB308CE127E89105BULL, 0xEB29DE8A14BACA88ULL, 
            0xD26EA77F9B49D0F7ULL, 0x9508978AD8A5CF59ULL, 0xC84376C779CD6B5CULL, 0x0FEDA5A6B8E49B1FULL, 
            0x84570162E8E7F7A9ULL, 0xB56C7A954AFCDF11ULL, 0x1305DF841CC46D41ULL, 0x80064150988E2995ULL, 
            0x83870944F1D0646FULL, 0x089CFD58B884463DULL, 0x3FD7C12A1FCE043AULL, 0xEAB1C90CA51E1558ULL, 
            0x0F0D373108E9E6D2ULL, 0x86D1B356D1563B62ULL, 0xE578653F47D43AD9ULL, 0xDE67FF837E4F5576ULL, 
            0x7395A1ED640B0F57ULL, 0xABEC98CF49BFDBBEULL, 0xD79787B5826AAE93ULL, 0x703C78061E4E310FULL, 
            0x1ADCB9F313FBBA48ULL, 0xD7FF5F613A2618EDULL, 0xE4C97021686065AEULL, 0x22AE959E0FEE7383ULL
        },
        {
            0x259DADD96A218141ULL, 0x2BE2E5D2CD197156ULL, 0xD12AC2D3B59F8768ULL, 0xEF808AD79E2953E1ULL, 
            0x0637B33272DB0926ULL, 0x90BAB18731168768ULL, 0xB79FA28AAA4F1E96ULL, 0xC46A82CAD3DB0DC1ULL, 
            0x1C2CB5ED18608B90ULL, 0x2044245FFE47EC44ULL, 0x8D46FD6343DAA2CCULL, 0x2FFF7199E1F8E308ULL, 
            0xA0D2A1D457CCAECCULL, 0x1A23BDCBB39E39CBULL, 0x317C6EC296A9F7EAULL, 0x0B331009AFD79D0FULL, 
            0xF51B343FAA0CFECAULL, 0xAC1E8BA1BB2E5975ULL, 0x3B19E52721CA0D21ULL, 0xE58396CE9AC873FFULL, 
            0xEF81C6451CF761EFULL, 0x2EC1B8DEA3A6132AULL, 0xE1DF0445F4141EECULL, 0x1E43126C84740ADAULL, 
            0x26EB8E226BA4F094ULL, 0x499123E74244EEFCULL, 0x0A0E94ED8589BA3AULL, 0xEB814376986349C7ULL, 
            0x800A8E45D24C2075ULL, 0x11F67E7AAC010931ULL, 0x6EA1CEF8F8C506B5ULL, 0x66E5622B1446064BULL
        },
        {
            0x7CED0A9D893E4B81ULL, 0x32D34B2A4A32EE85ULL, 0x1B26C503CB937402ULL, 0x09402EB4E5D4E009ULL, 
            0x29A0A44B14947FFBULL, 0x26DFB6F0E745A736ULL, 0xFE661863002858B1ULL, 0xE38285A8844188EBULL, 
            0x53A13519978BDEC1ULL, 0x469D29AC16EE2E7EULL, 0x8028BC65D7FBDDF9ULL, 0xBB5D222B55A61FFDULL, 
            0xA33B81F025853533ULL, 0xCADFE793C9F782BBULL, 0x7E945836A9013C7DULL, 0xE1B6F3346783A9A7ULL, 
            0x35730615238C590CULL, 0xF26FC69A156909C7ULL, 0x7C5CF03AF4D7C02AULL, 0x843CCC765865AE67ULL, 
            0x2D44CB1B21870967ULL, 0x04F8A415A54C2FDFULL, 0x16186BD674334190ULL, 0xCD7D47A6D9BFD0BCULL, 
            0x638E3D701EE86D13ULL, 0x4B97136E47EA5A36ULL, 0x210124BBC8743859ULL, 0x86EC72F107981E1CULL, 
            0xC5FBE32E7AFAF717ULL, 0x7D29B9D17B9DB993ULL, 0x53F3634560FA6088ULL, 0xD6DFBF4BF40A96CAULL
        },
        {
            0xEC1227829A326377ULL, 0x3B53CD9590B58EB5ULL, 0xC85E3245FC02CBFCULL, 0xE8CFE81F4EB5D90FULL, 
            0x7DD96FD5FF94CCC1ULL, 0xB24BD352B4D221CCULL, 0x9A62116F2D97168EULL, 0xB34475DA04F0A597ULL, 
            0x9B9C42A40C1C9722ULL, 0x0480A600943D5E83ULL, 0xF4C8BA897C73F364ULL, 0x5AF9360C473BD754ULL, 
            0x64E13D19941DEAFCULL, 0x64646522B071B9A8ULL, 0x7847F7AC5DCB258FULL, 0x2C5A338D66E240CDULL, 
            0x45E5EEBAA17651A9ULL, 0xF653293C3AB84F96ULL, 0x0E65FDEDA62EE4D5ULL, 0x260827621ED86D06ULL, 
            0x9E7718AB07B8A50CULL, 0xCC56099A72D2299CULL, 0x4A0ABA06A8F7AB49ULL, 0x9EEF6D4EFBE277E5ULL, 
            0x1480B1DD37DD9A60ULL, 0x06F4E729F3B455A3ULL, 0x1D476391C3F0EAAAULL, 0xF3849880A2D19DAFULL, 
            0x8950D8E05292E2E9ULL, 0xBFDFF5723C4E61E6ULL, 0xD7234F494C6623BBULL, 0xCA98C29D5DB7C329ULL
        },
        {
            0xF2FFA7B105A8B39EULL, 0x590DC171A8211370ULL, 0xC3DA836F9DDFCA52ULL, 0x119404E274374E4EULL, 
            0x29BA3E3933A4D457ULL, 0x4268D1DF4F1CEB9AULL, 0xD4B5E178F2503C35ULL, 0x130EF9E5406D8068ULL, 
            0xC10629DC9FE8BE7FULL, 0x83E0DAAF87767518ULL, 0x085526F3F4473ADAULL, 0x865DDFC7CBEEA7C6ULL, 
            0x4B0D0C8C50CD7777ULL, 0xBC74A3F6A576FFDDULL, 0x8765EB9A944B3B76ULL, 0x0CFB75D39F243DCCULL, 
            0x2EE555292A4D32D9ULL, 0x54549BCFCC81E223ULL, 0x4186EE837CD7C4ADULL, 0xF3DE6A43117CB558ULL, 
            0x9C8A66567802AF2FULL, 0x00BC55785E42418EULL, 0x9019DDFA94E75477ULL, 0xA5E846E340923FD1ULL, 
            0x0F0EB8DB8CCF9D8DULL, 0xAA86F72A71737BBDULL, 0xAB4B54EB31C13803ULL, 0x0B0F98A3FBFB1D5EULL, 
            0x65FE4951565BC18FULL, 0x76060C58A38D0A65ULL, 0x25F1C0DBB1173039ULL, 0xB9C26A840556FF77ULL
        },
        {
            0x093E12D9BFD4AA9BULL, 0xF7781F96A9BFA5A6ULL, 0xD260577C1E55E927ULL, 0xD4DE256E1BD0C479ULL, 
            0x6D53A75DD1018532ULL, 0xAE6EA22E0292448EULL, 0xABB34E44B21C5806ULL, 0x2635D5DE0A6406F2ULL, 
            0xA46A977AB235B4E7ULL, 0xA904199261A73BFCULL, 0xD011903D9592271DULL, 0x9769E0BBC00F9DCDULL, 
            0xA8357B023F8DD2E6ULL, 0x46B282AD5735A50EULL, 0x836A42221E9E3B89ULL, 0xC524C1EEDA5A05E3ULL, 
            0x60A98F5C53FA8A11ULL, 0x19EBC9076DC1F4A0ULL, 0x8CF19493A0497BC5ULL, 0x3C530AA8C95476E9ULL, 
            0xF8ECF940E27A004DULL, 0x74CD0647DCDA4F65ULL, 0x52D3EFA2D2EF9637ULL, 0x906FFF18DD7CD894ULL, 
            0x92D202D839019EE6ULL, 0x4E31F2DE0711E63BULL, 0xA52CD7721A647BD7ULL, 0x3456142FEDB37AC6ULL, 
            0x661A729F523D359FULL, 0x7309B6A0A189C622ULL, 0x3509870CC5F9C1CBULL, 0x36AA5F1561787028ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Sirius::kTwistConstants = {
    0xB5BAEB5A53FFAFEFULL,
    0xF148EF9BEF4BDDDDULL,
    0x8B2543C9603CEF66ULL,
    0xB5BAEB5A53FFAFEFULL,
    0xF148EF9BEF4BDDDDULL,
    0x8B2543C9603CEF66ULL,
    0x48CD7CC91EDCB10EULL,
    0xF4CCEED59FDBA9B9ULL,
    0xB5,
    0x8A,
    0xBC,
    0x7D,
    0x0A,
    0xC0,
    0xD1,
    0x18
};

