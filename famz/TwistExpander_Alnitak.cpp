#include "TwistExpander_Alnitak.hpp"
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

TwistExpander_Alnitak::TwistExpander_Alnitak()
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

void TwistExpander_Alnitak::KDF_A(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Alnitak_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Alnitak_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Alnitak::KDF_B(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Alnitak_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Alnitak_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Alnitak::KDF_C(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Alnitak_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Alnitak_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Alnitak::KDF_D(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Alnitak_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Alnitak_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Alnitak_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Alnitak::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x98D103125470C0ADULL;
    std::uint64_t aIngress = 0xB798DCABF8C727C5ULL;
    std::uint64_t aCarry = 0x8724FD3E3BB9CFC4ULL;

    std::uint64_t aWandererA = 0x9881A39A46697063ULL;
    std::uint64_t aWandererB = 0xDAA8DA325845A043ULL;
    std::uint64_t aWandererC = 0xDAC67B60D9C65F71ULL;
    std::uint64_t aWandererD = 0xE2D0C2762277072FULL;
    std::uint64_t aWandererE = 0xCB3274BE10EA64B6ULL;
    std::uint64_t aWandererF = 0xB1B3A025DF48B3FCULL;
    std::uint64_t aWandererG = 0xB26B342A7715272DULL;
    std::uint64_t aWandererH = 0xA5C6E9E69EE95E33ULL;
    std::uint64_t aWandererI = 0x94B09DC88DEBDB71ULL;
    std::uint64_t aWandererJ = 0x9CD13F146CA5BC2AULL;
    std::uint64_t aWandererK = 0xCDE8920B83ADA592ULL;

    //
    // KeyRotate A
    //
    aPrevious = 0xEE03B48C97ADFB24ULL;
    aIngress = 0xC4EFB7938712B78FULL;
    aCarry = 0xB6E50C4F4F5C14CFULL;
    aWandererA = 0xD04CFD8B1465769FULL;
    aWandererB = 0xC5409448876497E5ULL;
    aWandererC = 0xE726A4C0CAC6F3A3ULL;
    aWandererD = 0xCAAC59A592350391ULL;
    aWandererE = 0xDAD31A79189EEE1DULL;
    aWandererF = 0xF696E6E9E5371824ULL;
    aWandererG = 0xE2B51DEB1DEE7DBAULL;
    aWandererH = 0xA81188977995CF4DULL;
    aWandererI = 0xEE66CDE4FE106F1EULL;
    aWandererJ = 0xD08C40FF89008BF6ULL;
    aWandererK = 0xCFD067F63F860D10ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateAConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneB, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xDE8D1C67A4B8D722ULL;
    aIngress = 0x91E93F752602DB30ULL;
    aCarry = 0xA6F0B151591A4A8DULL;
    aWandererA = 0xA0FDA9FEB3081446ULL;
    aWandererB = 0xBD962AE47A92715DULL;
    aWandererC = 0xCDDCA358D023A8D2ULL;
    aWandererD = 0xEBA974B116B8A5D2ULL;
    aWandererE = 0x9D110632B39A17D3ULL;
    aWandererF = 0xFDBE30CADD9DF3F3ULL;
    aWandererG = 0xBA105EA1961637C9ULL;
    aWandererH = 0xABB95ABC1288CCF3ULL;
    aWandererI = 0x8768C7953BEB1FF0ULL;
    aWandererJ = 0xB8574C4DBAEE5640ULL;
    aWandererK = 0xF08A8BC38B491DB7ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants), &(pWorkSpace->mDomainBundle.mKeyRotateBSalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xE6579570BD481754ULL;
    aIngress = 0x8991119084C5FC4EULL;
    aCarry = 0xB9D56B85B8F930A3ULL;
    aWandererA = 0xAA6ED19C7C522E55ULL;
    aWandererB = 0x92CDB01AFE15846FULL;
    aWandererC = 0xBF1A792ACE9987D7ULL;
    aWandererD = 0x8A6B994DDE713F7AULL;
    aWandererE = 0x92491E2CD9434C9BULL;
    aWandererF = 0xBD9D98907C8CC408ULL;
    aWandererG = 0xE460716A7AD770C4ULL;
    aWandererH = 0x94DB124F0A26430CULL;
    aWandererI = 0xFEF9DF3017118951ULL;
    aWandererJ = 0x89AA504CE01B943FULL;
    aWandererK = 0xEC8BBB1A0452CA3BULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnAConstants), &(mDomainBundleInbuilt.mKeySpawnASalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xEDD6C7FCBE2A47D9ULL;
    aIngress = 0x9711639A6A290752ULL;
    aCarry = 0xC9BAD55F3D132890ULL;
    aWandererA = 0xDCEE42682FB4C338ULL;
    aWandererB = 0x839530C6C26127CBULL;
    aWandererC = 0x8FB2FC64E23080A8ULL;
    aWandererD = 0xA82BF9E375C0CB3CULL;
    aWandererE = 0xC52E005014FDDDD4ULL;
    aWandererF = 0xC40548A368674E0AULL;
    aWandererG = 0xB10D71955DF7056AULL;
    aWandererH = 0x90110485E87AFDB4ULL;
    aWandererI = 0x86F35C6E512352BBULL;
    aWandererJ = 0xF46B7CB258AE2D41ULL;
    aWandererK = 0x915326F10BBA3850ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnBConstants), &(mDomainBundleInbuilt.mKeySpawnBSalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants), &(pWorkSpace->mDomainBundle.mKeySpawnBSalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xE3D0C138A3224B1DULL;
    aIngress = 0xEA8F5650A51A7C85ULL;
    aCarry = 0x9DF37C5BA2AD73CCULL;
    aWandererA = 0x8917980C57375A4FULL;
    aWandererB = 0x99F8E605BD065BD3ULL;
    aWandererC = 0xCBDD33B270D4A2AFULL;
    aWandererD = 0xD4C6643116A5EE47ULL;
    aWandererE = 0xBBAD16450986DB4AULL;
    aWandererF = 0xC22D1F2E8D5649C9ULL;
    aWandererG = 0x90B897A93EB5C8D6ULL;
    aWandererH = 0xDFFD151E751C76B6ULL;
    aWandererI = 0xC6363FD3C09C1ABEULL;
    aWandererJ = 0x95E89727F10BA560ULL;
    aWandererK = 0xF4B7ED704288EF71ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mTwistConstants), &(pWorkSpace->mDomainBundle.mTwistSalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xDE05214C0BA489FDULL;
    aIngress = 0xE49E1A80DA6F81E8ULL;
    aCarry = 0xCBA0F99130A3B8ECULL;
    aWandererA = 0xF25AFBAC4B46FC1DULL;
    aWandererB = 0xB077C725980A3109ULL;
    aWandererC = 0xF40CC25FC4AC80B4ULL;
    aWandererD = 0x92803E736ACF3A8BULL;
    aWandererE = 0xE7EB5B578B60917FULL;
    aWandererF = 0xC9A99012807A3D23ULL;
    aWandererG = 0xC1B2BE1A66E88031ULL;
    aWandererH = 0x995C854C9054DE77ULL;
    aWandererI = 0xAC25841F32085062ULL;
    aWandererJ = 0x961FA0861B5C6ECBULL;
    aWandererK = 0xBDDB6E2123A46144ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mSeedSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xBDF1930DAE2309FAULL;
    aIngress = 0xCEB82928F7FCFF88ULL;
    aCarry = 0xEA1D1FD7406691F5ULL;
    aWandererA = 0xA92F472FA57F3C60ULL;
    aWandererB = 0xFF18BFB641991402ULL;
    aWandererC = 0xCDD7B3244BC4C7ADULL;
    aWandererD = 0xD5A1F1A740BDA286ULL;
    aWandererE = 0xF209672CB61CC9DBULL;
    aWandererF = 0xC1BCFD371E274882ULL;
    aWandererG = 0xDAA592489CDF69D3ULL;
    aWandererH = 0xB248C0DE8CB20B90ULL;
    aWandererI = 0xA80094688EC2BA35ULL;
    aWandererJ = 0xB2CD183691BE15CAULL;
    aWandererK = 0xA409394B24CE2933ULL;
    //
    TwistExpander_Alnitak_Arx::SEED_A(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alnitak_Arx::SEED_B(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alnitak_Arx::SEED_C(pWorkSpace,
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
    TwistExpander_Alnitak_Arx::SEED_D(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alnitak_Arx::SEED_E(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alnitak_Arx::SEED_F(pWorkSpace,
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
    TwistExpander_Alnitak_Arx::SEED_G(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alnitak_Arx::SEED_H(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alnitak_Arx::SEED_I(pWorkSpace,
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
    TwistExpander_Alnitak_Arx::SEED_J(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alnitak_Arx::SEED_K(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alnitak_Arx::SEED_L(pWorkSpace,
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
    TwistExpander_Alnitak_Arx::SEED_M(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alnitak_Arx::SEED_N(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Alnitak_Arx::KEY_A_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alnitak_Arx::KEY_A_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alnitak_Arx::KEY_A_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alnitak_Arx::KEY_A_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alnitak_Arx::KEY_A_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alnitak_Arx::KEY_A_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alnitak_Arx::KEY_A_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alnitak_Arx::KEY_A_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alnitak_Arx::KEY_B_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alnitak_Arx::KEY_B_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alnitak_Arx::KEY_B_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alnitak_Arx::KEY_B_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alnitak_Arx::KEY_B_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alnitak_Arx::KEY_B_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alnitak_Arx::KEY_B_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alnitak_Arx::KEY_B_H(pWorkSpace,
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

void TwistExpander_Alnitak::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB8D3372811320BC8ULL; std::uint64_t aIngress = 0xD6383C76B6ABB8D3ULL; std::uint64_t aCarry = 0xCC77418DC3D93695ULL;

    std::uint64_t aWandererA = 0x903C735C3E0ABD24ULL; std::uint64_t aWandererB = 0xA0A1001AF9A1F11AULL; std::uint64_t aWandererC = 0x919CAE74E8296126ULL; std::uint64_t aWandererD = 0x8945A9E3C5519763ULL;
    std::uint64_t aWandererE = 0xD3C12EFE7CED83A0ULL; std::uint64_t aWandererF = 0x8F24B3194DEA7203ULL; std::uint64_t aWandererG = 0xB2EB8FFC5C278FB8ULL; std::uint64_t aWandererH = 0xA0C9A22074D48071ULL;
    std::uint64_t aWandererI = 0x80042138D08AAFC1ULL; std::uint64_t aWandererJ = 0xCB1864FD867B075DULL; std::uint64_t aWandererK = 0xE4FFB372A14C93D8ULL;

    // [twist]
        aPrevious = 0x90CC5CC0CC34BEAAULL;
        aCarry = 0xD28D8545A2D5C4E0ULL;
        aWandererA = 0xB93B6140BA7F1E4FULL;
        aWandererB = 0xE316581E7A59D741ULL;
        aWandererC = 0xEF9BDCA3530576C4ULL;
        aWandererD = 0xDD681F5E419A7351ULL;
        aWandererE = 0xE930BBF92FC17F03ULL;
        aWandererF = 0xDD272A4A5496D71BULL;
        aWandererG = 0xA0E0FDA80552DF2BULL;
        aWandererH = 0xE1DC14A2BE0CAAFAULL;
        aWandererI = 0xF50544D3186DA08DULL;
        aWandererJ = 0xB077BA8E800716DAULL;
        aWandererK = 0xD32B8002D410B55FULL;
    TwistExpander_Alnitak_Arx::TWIST_A(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alnitak_Arx::TWIST_B(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alnitak_Arx::TWIST_C(pWorkSpace,
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
    TwistExpander_Alnitak_Arx::TWIST_D(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alnitak_Arx::TWIST_E(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alnitak_Arx::TWIST_F(pWorkSpace,
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
    TwistExpander_Alnitak_Arx::TWIST_G(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alnitak_Arx::TWIST_H(pWorkSpace,
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

void TwistExpander_Alnitak::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Alnitak_Arx::GROW_A_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Alnitak_Arx::GROW_A_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Alnitak_Arx::GROW_A_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Alnitak_Arx::GROW_A_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Alnitak::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Alnitak_Arx::GROW_B_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Alnitak_Arx::GROW_B_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Alnitak_Arx::GROW_B_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Alnitak_Arx::GROW_B_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Alnitak::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 6 of 33
    // Exploration cases: 0
    // Structural maximin 557 / 674; family total 2804
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
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 47U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3648U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4188U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7879U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1870U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1915U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 137U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1825U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1735U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 47U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 92U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1555U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 6 of 33
    // Exploration cases: 0
    // Structural maximin 554 / 674; family total 2804
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
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3198U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3108U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6979U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3378U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 700U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1240U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 745U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 475U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 970U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 610U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1195U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 880U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Alnitak::kKeyRotateASalts = {
    {
        {
            0x6CF86CC8FC459044ULL, 0xA2AA7E01FE751248ULL, 0x8C63AF404B048CBBULL, 0x2C077D13D643E412ULL, 
            0x9973566501595B2AULL, 0x648A1B5399CB4A4AULL, 0xDCC7D1E342CB3043ULL, 0x90093D4117821F65ULL, 
            0xB5E6A01D1D5EDF3DULL, 0x284BAAA1F591C694ULL, 0x7DAE3B61E2752251ULL, 0x7046B44CE93FAF49ULL, 
            0x0AD441FE6C0168E4ULL, 0xA463C2D87C0B837AULL, 0x82CDCE65A677A98DULL, 0xF6C31F5FFDB14B3DULL, 
            0xAC6029124F057BAEULL, 0x19FD7184BA7990E4ULL, 0x3894E01DC0591993ULL, 0x9504C86CF67C9336ULL, 
            0x6807AA56BA4D91A0ULL, 0xE3E7B8648CC2B084ULL, 0xBD018051A7D735D2ULL, 0x7B56B03F915EACADULL, 
            0x7307ACE193ACC5BBULL, 0x0603D30D69ADD22AULL, 0x4139AC3E99403577ULL, 0x8163FF430DF48AA5ULL, 
            0x7878F8F192269BC6ULL, 0xDDEC22DA11955A74ULL, 0x3BCFA78B3D2ED738ULL, 0x414408BBA4228BC0ULL
        },
        {
            0x9D0C4253ED464CF6ULL, 0x5027571814C51E86ULL, 0x6C7C5C06C9FCF485ULL, 0x0ED54C37BC19AE43ULL, 
            0x72EB1708CA5780ADULL, 0xC659ED34DC3D83AAULL, 0x50A17D11FC13F365ULL, 0x171688F8B3DE16B1ULL, 
            0x62D571F43DD80E98ULL, 0xA25812A63B469594ULL, 0x7A530701C61C11F2ULL, 0x58C02786CDC1F749ULL, 
            0x7374BBE1FF377331ULL, 0x195204371B32B501ULL, 0x805E9FE1C51040ABULL, 0x97858AB7DFCDDC67ULL, 
            0x01B4C6508D8C3E69ULL, 0x7D9349E146B8A47AULL, 0x0F54736162CE9800ULL, 0xC15FC6BA814BC4ACULL, 
            0x31CD115EF2C3BDFDULL, 0x6B2142CFDB78A105ULL, 0x69574422F3F35A32ULL, 0x08F635E04723E285ULL, 
            0xBF52F1FC6B06508EULL, 0x9856BF4B4040C2FBULL, 0x52AABE9D09115E3CULL, 0xE9ED9E7A22424F5BULL, 
            0x9E801A57DAC8F1FFULL, 0xDC847131C4B2CF05ULL, 0x36A426D7DCED6121ULL, 0x173D25F34CF74CB8ULL
        },
        {
            0xBE3FA4222244A8BEULL, 0xDE2AF5A64D652C30ULL, 0x0A69CF1B75370088ULL, 0x8B2C7DDE3475A261ULL, 
            0xB770B43F205ECCDAULL, 0x75DB29D7BD39CC41ULL, 0x8B33F6420090B9F0ULL, 0x52AD5BC1F8D99620ULL, 
            0xBC6BCDB2FF0E9066ULL, 0x2FF18F76E7A536C7ULL, 0x39D10C04E7F33D49ULL, 0xC42215967DDA9008ULL, 
            0x9C9E26ACB7ED8865ULL, 0x03BEA9FE0BC7363EULL, 0xD23ACCB2D3A3D1BFULL, 0xD12EF468D93DE8D4ULL, 
            0x1C945DFE4CE39119ULL, 0xDCE894016C43B4D0ULL, 0x76655CFD0E456C16ULL, 0xECFB57763FE3CBBEULL, 
            0xE95FE9B786702893ULL, 0x48BB0B4EF214E38BULL, 0x32C6587A0BDE0192ULL, 0xCA6D1CFB9FF46C3FULL, 
            0xFA5A95033DC1A12FULL, 0xEF381B471BB60EE2ULL, 0x91DDB17595B34E09ULL, 0x3FA897DCDC258EDFULL, 
            0x01014CE394E72E8CULL, 0xA53187CA57EF4CAAULL, 0x3B5A45C8C2632988ULL, 0x9A4FAFD6BFC96AFAULL
        },
        {
            0xC2BAC980C76ADED4ULL, 0xB759527E59999C09ULL, 0xB5DF59EFC76A8EF9ULL, 0xD7784AAD4CD0C122ULL, 
            0xB528626D19DCDFCDULL, 0xB092D8013BBA5D3CULL, 0xEE123B209DF7724AULL, 0x9CCD468268650E02ULL, 
            0xBA1510C54A09CDD2ULL, 0x206B78E095A4A8C5ULL, 0x2D3E6544D094C6B1ULL, 0xCE609BD908FBC02DULL, 
            0x4A5DBB0B10C41A30ULL, 0x84810A19C14CAD79ULL, 0x23C22C5B83B77991ULL, 0x19021C801B8206A9ULL, 
            0x6A47F3EF3847EA6FULL, 0x354DE9105F78FFEEULL, 0x290FF674FFDE1CD5ULL, 0x185ADC63617B8EFDULL, 
            0x45F1FA86135D8792ULL, 0x59CB3294ABAE2950ULL, 0xC7036D5E7A4E4DFEULL, 0x40B98C30C3323420ULL, 
            0x57477F14C13B0B75ULL, 0xA70747E873DC691CULL, 0xF1749705EBA98302ULL, 0x64E5CB41BB07C73AULL, 
            0x1432A29642E5C065ULL, 0x5EDA852458BF806EULL, 0xE2BC82BF0AE54E0CULL, 0x29B6027705B4D4E3ULL
        },
        {
            0x44F491A469716D67ULL, 0xF9255544E347795EULL, 0x7B6F02A0FEC0F60EULL, 0x3FE1B6403CA0C5C7ULL, 
            0x4818175508C1C90AULL, 0x76D7248E4B8C2F11ULL, 0xF4CCE54BF3F9017EULL, 0xC5F90D6EFC5187EEULL, 
            0x2AC1AEAC81D56B48ULL, 0x245B5243D1DF48F1ULL, 0x42294F3D6F9E9F10ULL, 0x845A46E431BB6E30ULL, 
            0x98391489FF8EE9D0ULL, 0x3259831B9C81C9C6ULL, 0xCED0846A1DAF2D70ULL, 0xC66E05BF3C234765ULL, 
            0x41D101828A7162B7ULL, 0xD5814E9D569FBDC3ULL, 0xB21B649B835D4DD6ULL, 0xC3C30D0B8B1FB028ULL, 
            0x22F92F4155FD26FAULL, 0x9A492BF44E715DDBULL, 0x7F17362CCEF79878ULL, 0x84EAF2970CE831EAULL, 
            0x1D0BCEC737C1784EULL, 0x4356445EA8DCC246ULL, 0x46475572C8C506AEULL, 0x881D500D109E5283ULL, 
            0x8511DDCC09F0B71AULL, 0x56C646B0C607056CULL, 0xC507806F98D1713EULL, 0xC02229C928C9EFFAULL
        },
        {
            0x9AA4E40F4516290EULL, 0xED5BDCC7A6F0D3D0ULL, 0xDACAF2DE8398C782ULL, 0x194549459AF51612ULL, 
            0x3EE3583A233AF5BAULL, 0x381B9CBB7E4815FBULL, 0xFCE67F8ECE1CAFDDULL, 0xDE3E4833D409E264ULL, 
            0x5F5F92E0ED3C6A4BULL, 0x09B9A6A08D299F3BULL, 0xDF4E9A68BD2CB954ULL, 0x93E50199701DA4F5ULL, 
            0xB68F7CFA2ABE8A2BULL, 0x34A54E36A1C29E9EULL, 0x1E7CA798850D77D1ULL, 0xB7A65CE5D3F25A2BULL, 
            0xE64952EA4B62A992ULL, 0xA2019D33BFD69EA7ULL, 0x60BD7921B4BD5F93ULL, 0x355AFF4660B5093BULL, 
            0x44E18F270FCC0B5FULL, 0xC420B13947CC7EA0ULL, 0x95937D9356623495ULL, 0xAD27FD25FD3FAC90ULL, 
            0x1CD373B256875DFAULL, 0x3F9F5E80C75DD9F5ULL, 0x40E00F12522D6D94ULL, 0x74105A8338C46623ULL, 
            0x08D41D106712A126ULL, 0xDC1A18B7DE0987A3ULL, 0x10953657245C7566ULL, 0xCCA10D142B594FA7ULL
        }
    },
    {
        {
            0xC4D94DB376AF586BULL, 0xA23985EB7BA2BD38ULL, 0x3C520D6BE511713FULL, 0x6A6D7A4AB31E994FULL, 
            0x0E2BC2CFAFA58EC6ULL, 0x6D9BF327DC127482ULL, 0x5111E61A05A68D8EULL, 0x8C1E4570E36253DBULL, 
            0x31825F60A3A8227BULL, 0x6063477F83DF140BULL, 0xA76918CCFDD8F107ULL, 0xF752A1E75CFF878EULL, 
            0x17B133B61F18DD2DULL, 0x0783ED34773E2235ULL, 0xE102CD55723C481EULL, 0xE40F3A908383D1F7ULL, 
            0x6D7D64FFF5CC6EC0ULL, 0x42BB487506314BBAULL, 0xF541876B7F5002F4ULL, 0xC9A88ADEF053EEBCULL, 
            0xE9F1EB21C121E936ULL, 0xED33E149F17416ACULL, 0xC3ED3A937FAC88AEULL, 0x8874D084E1128307ULL, 
            0x4A13D325C012AB4FULL, 0x1E74379B89F6ABACULL, 0xB28BA87CE8F44782ULL, 0x31B4B383371DB0DFULL, 
            0x4F9E968D17A85BF4ULL, 0x9654F149597E7D4BULL, 0x65C5FD572128505CULL, 0x81554ACF8A49141EULL
        },
        {
            0xD42FF9FFAEAB49D3ULL, 0x9E3C607367A8B8F7ULL, 0x8C918112215E0E58ULL, 0xFEF75C328C796B80ULL, 
            0x22C70B4FC82ED04EULL, 0x85B2154FBAEC2FC9ULL, 0xAC878BF503B497A7ULL, 0xBA3D203E0F3E694CULL, 
            0xAEF9B1AFE810CDA4ULL, 0xCC4AEB37A19CDA2BULL, 0x5D0AD3F0A3ADD3D1ULL, 0xF7A93D98B1937D9FULL, 
            0x506A2243CEB90683ULL, 0xB55F568BBC6FE3EAULL, 0x66B00CD59390F438ULL, 0x5698C93047C6188FULL, 
            0xFCB2AE98779AC524ULL, 0x9EC394CF9C1BB649ULL, 0x3DC4FEB5FA022C83ULL, 0xB5C966514647B9A0ULL, 
            0x9040E92A10DF032AULL, 0x300E8786F49B9132ULL, 0x29CD5FA5F114B2C3ULL, 0x79A4523BBF751B33ULL, 
            0x28AA1ADD5CD8443BULL, 0x23841FFAA944F803ULL, 0xB982F8C046457182ULL, 0x5379DA73A90EF83CULL, 
            0x734314EDC28B8D85ULL, 0x13C91DABD6BF8CDDULL, 0x5F5827F03FC2792CULL, 0x571858B8C110F4B9ULL
        },
        {
            0x8C232D04531AD3CEULL, 0x2E8C3B02CCB3F900ULL, 0x0802FE37B93D21CAULL, 0xE8A3E8B1812DEDF0ULL, 
            0x7118FE3F2F72DC53ULL, 0x19E28DEBB8A38C29ULL, 0xEDFE517DA15865E7ULL, 0x40FCB24348E42D9EULL, 
            0x72CA093AFC822F4EULL, 0x5644CB660DB7CB66ULL, 0x2E838486C6D86D15ULL, 0x619A3583DBD41C10ULL, 
            0x2FC651528C7814A1ULL, 0xE34F67413AA2B2F2ULL, 0xC76A7B0CACD1348DULL, 0x5603B97AA678F105ULL, 
            0x5B0D6592D6B62F44ULL, 0x19F18AE5B2868C71ULL, 0x3B7C0E1CB1A4BF03ULL, 0x27B36921776624A3ULL, 
            0xFB913BB09D2DD460ULL, 0x750EC843A7035E9FULL, 0xEE0237EA8FDDFD13ULL, 0x0B9AC51FB04C61D9ULL, 
            0x09C4ACA58D0F76E5ULL, 0x614166EB663E71ACULL, 0x83C98DD868688F39ULL, 0x8CEFCF3EA0FAC0A4ULL, 
            0x64C615DC3DE11AA4ULL, 0x01AA53FE6A459657ULL, 0x8CCBA8BC1362A109ULL, 0xE6828C34C0330DD5ULL
        },
        {
            0xFB1EA8CA4E23B94DULL, 0xCAF731320D8544C2ULL, 0xFA1A0007D626B001ULL, 0xCD99A9E9E78D11ABULL, 
            0xAFFFD158C023453BULL, 0xA520979FD32E8486ULL, 0xAE58A16D449B3617ULL, 0x61CA29CD63EE5124ULL, 
            0x616AC7A9CBFD4328ULL, 0x3B470B6A8F466E2BULL, 0xC06F6109F422F281ULL, 0x3E3DDBB91D00065EULL, 
            0x216948E8C1A8F958ULL, 0xE9F9016C3F0DC447ULL, 0xAFB1DFE7C00A9422ULL, 0x3E403FDD89C72CF5ULL, 
            0x73927D2DA6DAB616ULL, 0xAC437C511427FBCFULL, 0xE6CC030022897147ULL, 0x9344A354292735E1ULL, 
            0xB69B4A02FB8A8503ULL, 0x56A6CB4894A0F5B9ULL, 0x487091C65D48DC16ULL, 0x055CD8AF346F853DULL, 
            0xFE3D1B3522986CC2ULL, 0x55C6AC3F1B1D29BEULL, 0xCEC13F755A4BB014ULL, 0x99496A630D1E53FBULL, 
            0x895C515FEED7932DULL, 0x414EE0FEC807FF28ULL, 0x86D60DC68FADA708ULL, 0xAAA8F587299676C7ULL
        },
        {
            0x3BF95E58D1965EC1ULL, 0x5031A822965FF16FULL, 0x6A683B9106899D71ULL, 0x097904EEB1B59BE5ULL, 
            0x6C14714FA4DEB28DULL, 0x633B64D445F3B7EBULL, 0x3C9E2B256B03DAB4ULL, 0x1F16DDE26109C4E0ULL, 
            0x05B7D30346EC3C84ULL, 0x5F4B7DA0707780EBULL, 0xA013F02D173A0CD2ULL, 0x8DF878A6BB5D2923ULL, 
            0x21EC7D88DD23BDF7ULL, 0xB33AF5195D226E23ULL, 0x8CF40967935AE393ULL, 0x9F300C3394F996BFULL, 
            0xABEFAA1091D59E3AULL, 0xCD2C821B2FA1C218ULL, 0x3C3CC63AC30F29EAULL, 0xA8375A40D40973F7ULL, 
            0x6AEBA2C63B1D56A7ULL, 0x50E9F0B8E2E74D8CULL, 0x43C671577C162677ULL, 0x97A007A9451E3E57ULL, 
            0x537EDDD0807286EBULL, 0x472D02AE4958EC8FULL, 0xF0655B4E338433B1ULL, 0x1930009833D7E4D3ULL, 
            0x70D3AE6EDAB0C313ULL, 0x092BEF75C9DF2C8EULL, 0x4B3E2FD31DEFF0F5ULL, 0x95F433574A12D609ULL
        },
        {
            0x930DE9088C0BB9C6ULL, 0xB6F618BA60FAE95BULL, 0x098758F94356A1E6ULL, 0x7E9976D44AB9F761ULL, 
            0xF6075987D828DFDAULL, 0xE333A18D558AE7D1ULL, 0xE138493E66EC44A0ULL, 0x05E6DBD29FAF8FC1ULL, 
            0x85124E7FD7F27530ULL, 0xBD2319EF5AAE07B7ULL, 0x5E8B094E4A877B23ULL, 0xDB670B8BEF0621F0ULL, 
            0x1563FDFC4F480F21ULL, 0x4A8FA1662103D197ULL, 0xBACDCB4B376201E3ULL, 0x7BBE5A7D6770E6D8ULL, 
            0x75E8F5F5D97D5F8BULL, 0x987783DE02D999AFULL, 0xCFC3D3171C09E0BDULL, 0xAF4100A5271450D2ULL, 
            0xF58D5240A79452B4ULL, 0xB273420179601F82ULL, 0x9A8EEDC0C0EAE139ULL, 0x1C60171AD4CB208CULL, 
            0xA0D44642264EFA6EULL, 0x6D1832DAB5EED080ULL, 0xEA55635FCF620595ULL, 0xB24FF8CF41F44CF2ULL, 
            0x8B864BFD13860E9FULL, 0x5B12388894A2DF30ULL, 0x8D47C152D53A282AULL, 0xDB501969C444E6ADULL
        }
    },
    {
        {
            0x655B472340FCA7FEULL, 0x2C25C9068822DF33ULL, 0x2796BE4FD382F889ULL, 0x0F3C12F13F48AC9CULL, 
            0x13BE4E454DE989B1ULL, 0x2A1CA6BD1936DCEAULL, 0x5F5FC8CEE39EA1DAULL, 0x9C4F3C6153683099ULL, 
            0xC4D1CABE1FB7C7F9ULL, 0xA827B683850056F3ULL, 0x56EA5BAC4DA92A0CULL, 0x413D6EB2810189FAULL, 
            0xE6305EFD552E4294ULL, 0xE8F89F19BDBD0E5DULL, 0x8BA57D362F6FCA1DULL, 0xA3BA2E72C97092FEULL, 
            0x3EC65B25F82629BBULL, 0x2FB4BEDDC66834A8ULL, 0xFE03459DDB100225ULL, 0xDEFB5744D1864A24ULL, 
            0x3EE8807055B8B092ULL, 0x3290C73C59330E58ULL, 0x751B053232CFD607ULL, 0x72B22850F19E7039ULL, 
            0x4D94A99AE45B450AULL, 0x32C47BC6A965F045ULL, 0xDF662621164D0790ULL, 0x25ED895C381F8719ULL, 
            0xFB595BAFAE13996BULL, 0x52C5DF4F14BA8038ULL, 0x3648D71C9E0F3324ULL, 0xFDD7368BA094981DULL
        },
        {
            0x8F2B8D394431A2D7ULL, 0x9AF33874DC8BB2CAULL, 0x5E915687B5AD510AULL, 0xF244C437F480E727ULL, 
            0x9DA8CC37B215ABB2ULL, 0x81C5445CF55E87D4ULL, 0x50DC7FA4050E4330ULL, 0x6388690785AC7D4BULL, 
            0x90D095DAC0B21FC5ULL, 0x29D7794527E234FBULL, 0xC282698F26FD4037ULL, 0x88186E81BD7A6F95ULL, 
            0xF2DB9330B52E1C0CULL, 0x7F6EC75C56ED0DB0ULL, 0xB7A87FC56B733608ULL, 0xDFFC47472D6C30B3ULL, 
            0x5A885408C7A782ACULL, 0x402F773DA6FE586EULL, 0x4100EDF31DF8F782ULL, 0xB0732A32BAA48871ULL, 
            0x657C31D5D43E3D3CULL, 0x4DCD09587BD21B38ULL, 0x4265983DC412DD9CULL, 0x0837EEE8266BE6CEULL, 
            0xF1BB883511DBF5B2ULL, 0x21E6B2D62AA81B7EULL, 0xA54E6E03526569DAULL, 0x4B31C38F8DF727A5ULL, 
            0x380E3DB9C4233EADULL, 0x9AECBBEA6025E8FEULL, 0x06B2AB0436A6BB26ULL, 0xF97FD73BC22414E5ULL
        },
        {
            0xC9FBE90B3A9458EAULL, 0x85952253DE42890AULL, 0x31CC2C2D5EFF16F4ULL, 0x73F46B5B9377C0B5ULL, 
            0x14598B732321320FULL, 0xCB87F604F5A19EDAULL, 0x7C87947B0FE9AE5EULL, 0x198AA832F9E370A4ULL, 
            0x56AAAAC1001F9225ULL, 0x201C30019B75F4D8ULL, 0x3A262BD30EE7B90FULL, 0xC46E05E97BA25FCFULL, 
            0xD249FD71FFDB4774ULL, 0xBF1C2B753BB60455ULL, 0x0606DA5DB9C5ED62ULL, 0x7B986416F58DED8CULL, 
            0xD5D5AE677F5E4FC9ULL, 0x7B2D38EED8089C35ULL, 0x61F706220083AEEBULL, 0xC9BC2A82502FABD3ULL, 
            0x3FB52EFCB8758A6BULL, 0xB5E54A7C419320F7ULL, 0xB566C639273CF4D4ULL, 0x1FF88C7D4DCCDB8BULL, 
            0xCE66857499A31A6EULL, 0xAAD483632C8C4F34ULL, 0x992A9B2DF178E3CFULL, 0x7721C87E121BCA3AULL, 
            0xF3D8430E07180A85ULL, 0xD5D8A7968D58DE49ULL, 0x060833CB5745AB67ULL, 0xD20B1B06E77532B2ULL
        },
        {
            0x663448E4A967778FULL, 0xDC4D1DCB87839E21ULL, 0xECF23B5B413BDAECULL, 0x09DA3CFE317523D9ULL, 
            0x879C0A98FA682B6DULL, 0x794E20CD73FE753EULL, 0xEF136D934B9205A1ULL, 0x635409C692049CEBULL, 
            0x07A3A7B375A0D360ULL, 0x39AC68357B8A1C93ULL, 0x11987BAE124FE825ULL, 0xA21A92A9424061E6ULL, 
            0xAABD81CF6D9F75DBULL, 0xA1EA862A8F0F27DFULL, 0xF544458E64871E4EULL, 0x7A82CA68DED39CA1ULL, 
            0x550D018FFE2FE62EULL, 0x6CF0C552D9C93014ULL, 0x6605D74D1F212089ULL, 0x34D9A6B3F42EAB9CULL, 
            0x6D5745162A6422CBULL, 0x30A0276EDD1D0C7EULL, 0x0AE204BDECD16ED5ULL, 0x91342346B3CC6B99ULL, 
            0xAB292C28B7B2D8C5ULL, 0xE0800D9C7F38E671ULL, 0xA1B5DF8184599536ULL, 0x844ECBDD1F31FAB6ULL, 
            0xBC9A851AFD014821ULL, 0x4D9C23AF41AAE4D2ULL, 0x62D47E19F99D9478ULL, 0x0CC44407D6129BEEULL
        },
        {
            0xFFCC16AFC0458DBCULL, 0xFF57710FEF4EDDDBULL, 0xB2997FFCDE716E44ULL, 0x8F238C767D09D898ULL, 
            0x02D2883BD282E015ULL, 0xB55988B2F4E572C2ULL, 0x84ABC95DEAE1AD99ULL, 0xD2D66388A145D908ULL, 
            0xAA6DBE2A044EEB82ULL, 0x36B3AB090BEF10D2ULL, 0x105E343D8F55C8C9ULL, 0x32D651F67855E56DULL, 
            0x4851B8A504B9BAEAULL, 0x0D039F6F13B3D5EFULL, 0xC4D07FEEB2BEDEE8ULL, 0x317D31025C6AC211ULL, 
            0xF064C1988884BD40ULL, 0x92653AA5A2482837ULL, 0x551CDD2FB8745138ULL, 0x6F64453DC4C4AC3FULL, 
            0x34F21059CB32EE14ULL, 0xAB9F1C10674EA592ULL, 0xAD7144721EF2B446ULL, 0xFBEE75EACF92E29FULL, 
            0xEC09497E30833121ULL, 0x5D95A250CD03D118ULL, 0x024A8FD27BCFD6F0ULL, 0xCDA4ECA185056238ULL, 
            0x63FDE48E5D45D27EULL, 0x4659276DB1466895ULL, 0xCB6B6F2B1F196176ULL, 0xDEEC9EB51A7941DFULL
        },
        {
            0x8569D0890311B66AULL, 0x24073DEDF8609C37ULL, 0xC97E2E1FD112DFE7ULL, 0x44BD5C447819476EULL, 
            0x5A12CF3F27CED4ABULL, 0x68C59EE6B171309CULL, 0x7CD0F2E30F317D0BULL, 0x2E6E06BBD24B2A3EULL, 
            0xAB62BD7F7AB0FB63ULL, 0x6CC555113DA565D6ULL, 0xC7594B4529845F23ULL, 0xF88867C5ED3C4454ULL, 
            0xA620253B23A16AF2ULL, 0xFAB0132E5923270DULL, 0x55534BF2541C6566ULL, 0xD5525396D172D23EULL, 
            0x071B825F87709BF8ULL, 0x3B661AF7E66EB23CULL, 0x165F2FE00106EDDEULL, 0xA1180BFAF0B9B04FULL, 
            0x4A63A3074EFDE525ULL, 0x30E544E0F7FE53E7ULL, 0x895FA72052272378ULL, 0x8145FD36E0A24F60ULL, 
            0x17B6AD6D41CBDBE2ULL, 0x36D9C1A62909BDA9ULL, 0xAFB8CE2A2C12E004ULL, 0xB44791E713347833ULL, 
            0x46660A218681F81DULL, 0x9A428598F629BD7EULL, 0x4BF3723DF0BFE1F1ULL, 0xB67416E14616840AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alnitak::kKeyRotateAConstants = {
    0x6B82D343BBC4FBE4ULL,
    0xD4F71A745106588FULL,
    0xF57518A1A0A7EED5ULL,
    0x6B82D343BBC4FBE4ULL,
    0xD4F71A745106588FULL,
    0xF57518A1A0A7EED5ULL,
    0x690AA157046F4E30ULL,
    0x007225ED5B053337ULL,
    0x81,
    0xE1,
    0x38,
    0xEC,
    0xD0,
    0x81,
    0x6B,
    0x56
};

const TwistDomainSaltSet TwistExpander_Alnitak::kKeyRotateBSalts = {
    {
        {
            0xFA6EED89D454C889ULL, 0x89F75E015D40193BULL, 0xCD9795F8C99C5D77ULL, 0x4F598EE9E6B33EA6ULL, 
            0xD2D4F4C759358847ULL, 0xDCAE34E086258CDBULL, 0x1AFF569249AC73E5ULL, 0x14A6E55F79285828ULL, 
            0x77D8B3A0AB0B9EBFULL, 0xB07C69C731CB62C0ULL, 0x8FD4C947573BDE7BULL, 0x3A6BC820D9B75124ULL, 
            0xF601A4F429ABA1BCULL, 0xBA6DD40D20DD35FBULL, 0xA8415E53F40754F2ULL, 0x86434F332DA93088ULL, 
            0x7BDECD1B76CA8ACEULL, 0x45094D2B8864AC76ULL, 0x9002901D9C082749ULL, 0xCE157D6F9B11012BULL, 
            0xD26F7C6141BD26F2ULL, 0x2780B84A4E0108EBULL, 0x3E3FDBED89C34EF6ULL, 0x1D7CFF198D381A83ULL, 
            0x985FC592F2C2E2C2ULL, 0x392847331204D478ULL, 0x378DD1DFD1AEA669ULL, 0x13F2A6842D952DB1ULL, 
            0xD725E45B41C9F276ULL, 0x6BC592165AEE184DULL, 0x8FA3C922F5D8218AULL, 0x1D173D7C6FDCD547ULL
        },
        {
            0x80BCD8FF0251D3D8ULL, 0x540944BEA248EA68ULL, 0xEA008E710A069E9BULL, 0x4D09786065759048ULL, 
            0x6DDE6858E9845972ULL, 0x119B2C6729FBDD1EULL, 0x94A127D78F5C1ED5ULL, 0xA479E30AF54DF7A5ULL, 
            0x6C1CF711754C60A7ULL, 0x9182B3D0EC38FB8CULL, 0x73BD9D5EBB9F4851ULL, 0x3D8AAAE623E0B4A4ULL, 
            0x5B68DFAE5B004DFAULL, 0x8F0EED334971960AULL, 0xCF775FC6136EDA7BULL, 0x46760A0C147B0B7EULL, 
            0xC29A6F538B6892B0ULL, 0x39BB9F3B20AD69F2ULL, 0x38516C288D593894ULL, 0xFE6E6DCE2BE20439ULL, 
            0x21A6F8370C8E9BA3ULL, 0xC6502CCBC76B432FULL, 0x4C30F87790719BF2ULL, 0x9A43E814201169DDULL, 
            0xF3EBE73D58E26223ULL, 0x219918CA8B01322EULL, 0xFFDC124CFA0EE092ULL, 0x3FC1045779497E45ULL, 
            0xA310FC4CCDD0D0E0ULL, 0xBF5C1122091613A0ULL, 0xA532A02B30E5B8D6ULL, 0x808A387357AA0FC2ULL
        },
        {
            0x2CF54DA5C839F3E4ULL, 0x03A72C45831EB9D0ULL, 0xB924423B5815EFFAULL, 0xFBBB58822596FFB9ULL, 
            0x48D12A34CC22444EULL, 0x6460CBBC6D4ACF78ULL, 0xF370C2FBCDAC325AULL, 0x21BE628CB380B4A1ULL, 
            0x598FEDF9A4CECBCEULL, 0x6C9CB2AB245A4A05ULL, 0xA11167B4DDBEE285ULL, 0x603965BD83630362ULL, 
            0x759D64BEA8F13D63ULL, 0x982B7FA2319D2B40ULL, 0x2D40C46943DD651BULL, 0x2FD1C07A94236823ULL, 
            0xA3E6808E3E38EFE4ULL, 0x75B6F6C902D8022BULL, 0x4B357EAEF8E89D54ULL, 0xE5249ED99EF9C1CEULL, 
            0xDE5BACA54FFA55F3ULL, 0x406B0FCB563AF06EULL, 0x98BA7E44CAC787E2ULL, 0x077572C324C454FEULL, 
            0xFFDEEA6FF2D03660ULL, 0xE409ECB734ED2D5BULL, 0x0C8B602D2A1C439FULL, 0xD0716A0033588EC9ULL, 
            0x39B1A997359A6AC7ULL, 0x31DBFE5A26CE114DULL, 0xF1F783D0A38F8400ULL, 0x7842F70FB2A62EE7ULL
        },
        {
            0x082BFCE2612B11A3ULL, 0x89A56C2706807BA6ULL, 0xC5AA468A71020C84ULL, 0x0A6718E52591C73FULL, 
            0x983A26EFA30498A0ULL, 0x5DF653AC3995B788ULL, 0x62B0C4F3EC0AB262ULL, 0x2E67421761793809ULL, 
            0xAB9666F25A4E03D2ULL, 0xC374D7F53AF8B818ULL, 0xD92C635C85D2E92FULL, 0xA9D9E724279BE199ULL, 
            0x925FF8F1EAB81137ULL, 0x84FE7DF3E2671476ULL, 0x33A6DE090E99BD03ULL, 0x5329D652F5569C71ULL, 
            0x643D2A454CCBFAF4ULL, 0xE4251FC1C6E683D7ULL, 0x0365862994EA41DDULL, 0xE8D74D55AFC37471ULL, 
            0xEA53D2D69CF53B7BULL, 0xD16B9352282E3C01ULL, 0xE67C5A60FEB68F33ULL, 0x298856882FE06EC0ULL, 
            0x7AE480AAEC216D21ULL, 0xB4BEAEF4ABAD4488ULL, 0x59097D3C43A6F610ULL, 0xE97F03AB070E9FE9ULL, 
            0xA22143F098F2016FULL, 0x93889B9B2D89C92DULL, 0xE503B1E88939F328ULL, 0x8FF760A660208C95ULL
        },
        {
            0xAF29E64DA985101DULL, 0xA8A1881A7789B784ULL, 0xD8042A4D20AC392DULL, 0xEC99CFCA0D806D05ULL, 
            0xD85410E5AE4EC58AULL, 0x4EF287500C2C199BULL, 0xF19703230288F0F1ULL, 0x84CC86F356D4F709ULL, 
            0x78560E005B5C5797ULL, 0xFD376988EB511691ULL, 0x7F5F77527E4FC38DULL, 0x871EFAF9669F4DE6ULL, 
            0x4A4491ADA678D80CULL, 0xD0D6CA8DA375AD67ULL, 0x81500D0F80B95073ULL, 0x836ACFAE8594E2AEULL, 
            0xCE0EDCDC068392D3ULL, 0x4FBFC2DB67010A11ULL, 0xBD20BB0FBF05FEAEULL, 0x775DDF0C07BDB2D4ULL, 
            0x3C0BE004AD642247ULL, 0x1D96F1292A4D2C2DULL, 0xE485CC12BFA4F2E8ULL, 0x447A50BEFA2ABC05ULL, 
            0x1ECB2E7B80F90CB3ULL, 0x1CE867E154CCBCC4ULL, 0xDF797782B00B3650ULL, 0xEE4D60DFAE10B705ULL, 
            0x82D8426335A30EA7ULL, 0x63AC40E81D550146ULL, 0x7F5035923B40CC85ULL, 0x5592CAC2161EDA80ULL
        },
        {
            0x5C508DF4BBA935AAULL, 0x1A75648B3D8A1320ULL, 0x8BF9C148EA10283BULL, 0x948956D0898AE40CULL, 
            0x70F4DE1212F9A473ULL, 0x372027D3EE3156A0ULL, 0xA88995CEC9FAE8B5ULL, 0x0D99E4CFE8F0D34CULL, 
            0x28991C591D682D54ULL, 0xD6898D5ABD3A5AACULL, 0x203F7C827F314396ULL, 0x3B505BEABC8CC91BULL, 
            0x8E4173AE20FF3DB4ULL, 0x6DB79812951445D5ULL, 0x0C987D61427347B3ULL, 0xB08242212322E28CULL, 
            0x92E4ECBAAF3D8EE3ULL, 0x44A67246927A41FAULL, 0x42A733BA403D2269ULL, 0x5B5389552BD14C78ULL, 
            0x57CA8BB1C94ACACCULL, 0xD0B755A320F18B2BULL, 0x596CD58B764F8800ULL, 0x8D334A66C73674B5ULL, 
            0xBFA6A9BF6F07FDFAULL, 0x94D4BAE36B4447A2ULL, 0x1DAEC6FA17D5E49FULL, 0x14991F7B44E6D9FFULL, 
            0x68902B8A57758D3DULL, 0xF410D5B4F5E81868ULL, 0xCF38AA7B204026BBULL, 0x886863E92AAAAD97ULL
        }
    },
    {
        {
            0xB083EBA6239A2DB4ULL, 0x86AA831F25C8BAEFULL, 0xC82DE636D6C98F57ULL, 0xBDBC8C4D36611BADULL, 
            0xA491E6FD130E412BULL, 0x20A69FB2C83C08F0ULL, 0x2CFA339BE5C435ACULL, 0xA7A2AFE0DD6F7273ULL, 
            0x78A55C1ABD3D03B1ULL, 0x735E5CE060F09832ULL, 0xC2ED6A779BC62FA5ULL, 0xA5CEA6EE52829BE9ULL, 
            0xF40637BC8A40BC8AULL, 0x1463907B6867B86FULL, 0x11D0B310A13EB0C7ULL, 0x0968FDA04D01E035ULL, 
            0xCD8BBDD0348411E0ULL, 0xF3E9D14323C0BF60ULL, 0x40BE535DEE009D55ULL, 0x2DF14F9C516ED870ULL, 
            0x5B60341F03286A21ULL, 0xBD5CEC6E2920ACCCULL, 0x87B61EFCFA0F93C3ULL, 0xD95EFA60338F0032ULL, 
            0xDBA24EE2BC5F59D5ULL, 0x5CACD631533B8E0DULL, 0xCC4B96F43FD550DBULL, 0x0452054CD596739CULL, 
            0xE992947D10EC1E14ULL, 0x1C810CBB37814F16ULL, 0x17CFEBC1F214913CULL, 0x9B2106723B9E9CFAULL
        },
        {
            0x77C61DECD366AC4EULL, 0x51B1D06CF52C3FF5ULL, 0x50EFF8585FCD91A9ULL, 0x86DAE110648DD791ULL, 
            0xC660C75932D00B28ULL, 0xA49C894F00330831ULL, 0x0928C094D2638A7EULL, 0xDF9FBB5D5F8934F4ULL, 
            0xBCE55EF7FE7D3C7DULL, 0x724A05DCB6F28966ULL, 0xC6F56CB506D123EDULL, 0xE54DA167AA80A3C4ULL, 
            0x3A619E7061B8AA81ULL, 0xA1BDB3DC9BD30DF5ULL, 0x185B9CC0BCB3695CULL, 0x9830E838A8878EE9ULL, 
            0x63A241A9225A8206ULL, 0x28706793B9753FD4ULL, 0x2A1FB0873FF1E7CDULL, 0x80AD7DF9267073B1ULL, 
            0x0DF2AC03BCC1A1D2ULL, 0x2EAC74E6AE674BCFULL, 0x68007923D94C0622ULL, 0x31A109CB076B179EULL, 
            0x4C5600931C9B7408ULL, 0x6F5581CEC2E59C03ULL, 0x3B7BF72CA3B207A8ULL, 0x8B963BECFDFC5C13ULL, 
            0xC0196093F04F33C4ULL, 0x3D3A372EC77541E3ULL, 0xD71F589093619E68ULL, 0xD37CBBE593A484D9ULL
        },
        {
            0x46325D69DDF5EC40ULL, 0xCDE421F956B6B2D8ULL, 0xD4D61CE9B4A4E7D6ULL, 0xE6AF64F1A9E3D35FULL, 
            0x4AB4F019E590811FULL, 0x5C21AE34B98C4951ULL, 0xB9EDC8E64D662F66ULL, 0xF1D7BE18A397AF42ULL, 
            0x0719C52001648212ULL, 0x4DD2A932A3688D1DULL, 0x9CFEF00B127D46B7ULL, 0x10F38423B75FA6A4ULL, 
            0xB5A9B4682EAEC630ULL, 0x7441658D31E086FCULL, 0x548EC053016403EEULL, 0x1EB73D77E881A7A0ULL, 
            0xCE0947F8B878307EULL, 0x2D0932212654EC8BULL, 0x3D34ADD52E8A1E26ULL, 0x572371DFD9270B2EULL, 
            0x1FCE7343E3855003ULL, 0x7A6D039241069ED9ULL, 0x73DF791BCE72F31FULL, 0x3CB1EAC2F511D875ULL, 
            0x31988B65CDBE908AULL, 0xDE954A64F49C15F1ULL, 0x5BF4301DBB0F75C6ULL, 0x44912CE449092E8EULL, 
            0xF4547063447A4A1AULL, 0x7A89A7A9AE7FD129ULL, 0x9FF1AA20943E223BULL, 0xEE4750D63865A5EBULL
        },
        {
            0x183FF92A05E6DC0DULL, 0x79D6EFC7E6EDF073ULL, 0x01B8CCF6397B2969ULL, 0x4575631BFE16AA32ULL, 
            0x7CDFBB5059CF2DA5ULL, 0xF5D05B179D3CD0DAULL, 0xE82E8D182F936A0FULL, 0x31A6BAD3CC7C45AEULL, 
            0xFD41548553900592ULL, 0xFAC87052DE4E531EULL, 0x24791A7EBB2B35D0ULL, 0x335130A73E92FF77ULL, 
            0x3C71FA3CC6D0E4FAULL, 0xA7638E130DFCD546ULL, 0x39215E6E59BBE3C1ULL, 0x7149206BD711C26BULL, 
            0x352071EF1D07E48DULL, 0x87A21692D47C5FDFULL, 0xA418CDB033C863F9ULL, 0xDA5768A0808CEEA6ULL, 
            0x69F5BE1DCAB4BA2AULL, 0x6E41ADE6C966BF36ULL, 0xCD781CB7858A013FULL, 0xE9854FBECAD0170FULL, 
            0x500A1178E577C8EAULL, 0x468007A70231D623ULL, 0x153567116308EA66ULL, 0x298B1A9FBA94A49EULL, 
            0x43191DE3AECC2468ULL, 0x3251E6B921715F41ULL, 0x8462C42276899F80ULL, 0x3C67097B12DB3D56ULL
        },
        {
            0x9304AF7311DEA0B8ULL, 0xD4DB810DFC68B8F1ULL, 0x5A303E0238405B7AULL, 0xEF8513B117F634D4ULL, 
            0x3EDE1780BD5C0880ULL, 0xB27A430EC6A01924ULL, 0xF7CE596BEC52F3E5ULL, 0xD6466009CF2DFB2EULL, 
            0x8D1F2D9EEDD3C5DFULL, 0xDAE853C9DD9F9740ULL, 0x77B5734736FD73D8ULL, 0x9549D886F4AA9E19ULL, 
            0x8312586740CF8C79ULL, 0x467F5B1F967F4FF2ULL, 0xF659D3BEE022BD16ULL, 0xACE4D90A12EB4E6CULL, 
            0x67F4761A143DE556ULL, 0xC779F4B470B18F64ULL, 0xFD84AC927352F64EULL, 0x2EB9DAC11D334C9EULL, 
            0x71E3627EBAF59C7DULL, 0xB9E512B15A692344ULL, 0x3AA8902C4FEF9955ULL, 0xB1C41131459A4C2CULL, 
            0xB2B37A9E9D55228DULL, 0x852292C8F7BDE07FULL, 0x07CE0C811F6FC876ULL, 0x106EF6FCEA78DD15ULL, 
            0x92DD583F658FBFC9ULL, 0xA54EC2D5B0BCF485ULL, 0xD5EAEC7F2EDE61B8ULL, 0xC950856060F5CDFBULL
        },
        {
            0x08D43F4E03914F7FULL, 0x48518430B9057F1EULL, 0x6C15D604B4323D17ULL, 0x68E01D33F82ACDCAULL, 
            0x14264960A3911F9CULL, 0x260AC38E81E83CBDULL, 0xFF2162D2FE01B604ULL, 0xA405772400240A3FULL, 
            0xF8B266A8DA2D21E9ULL, 0x49A78663FA3BECE8ULL, 0xB6324728A350A519ULL, 0x4448799912AE2D62ULL, 
            0x0A6208D9853F3276ULL, 0x2BBD2F93EF7FE4D0ULL, 0xC9393A5BA366978EULL, 0x85A61C6D03B60D4CULL, 
            0xC0C89995FA501665ULL, 0xAF223D54F09D80EDULL, 0xA4D59A6D8B583B12ULL, 0x087B80E48820C330ULL, 
            0xE6252188376D13A3ULL, 0x19DDA782F770E860ULL, 0x70DB25438C3601D0ULL, 0xEA6AAB696842DDE3ULL, 
            0xD643A87908799FBCULL, 0xCA0FB2B8DE7638A5ULL, 0x46A04AB3A27633FBULL, 0xCAE81D91D0CA8776ULL, 
            0x5084EFE08CB00830ULL, 0x0C010A77DBD02C8AULL, 0xDB95C0563F3876FBULL, 0x3D64882E79F0AC67ULL
        }
    },
    {
        {
            0x83600B1A663FFB81ULL, 0x31B56C1C62526AD9ULL, 0x875A89A3F0C0FBD2ULL, 0xE4151667DED12A37ULL, 
            0x84BA9FF0E8B39FECULL, 0xEFDF7EB44BFBB194ULL, 0x8F986DE8FD6D5B27ULL, 0x0760657E5FB5E08FULL, 
            0xFB60EB4C636E2C92ULL, 0x91564F36C949FDD1ULL, 0x56200290A4A87868ULL, 0x759E224E6E5A4C0DULL, 
            0x725B9D6C4E5B1131ULL, 0x4E55F76E3FCBEA37ULL, 0x51DEACE433888147ULL, 0x83E8CD4E0F11C33AULL, 
            0x1850340D80CA94DCULL, 0x837433D3E1B0734BULL, 0x45B0B67D640A83C3ULL, 0x18660F775B934F1FULL, 
            0x9A672A1D8ED831FEULL, 0x43CDF5C7A248BF6EULL, 0xCDBE8028869B4006ULL, 0xB810FDBA80194941ULL, 
            0x9C6644C59D7CD3B3ULL, 0xAAE1E8A074306F33ULL, 0x29C698CEE94AE9B4ULL, 0x5DF228E36A63FE54ULL, 
            0xD5302D4786FBBFB1ULL, 0x4E4EA3C911F17635ULL, 0x3B6C08354801BC72ULL, 0x9006991F52040031ULL
        },
        {
            0x79D2CEBC6ACD1C50ULL, 0x18CB4A1606823006ULL, 0xF1DE89589DA08C61ULL, 0x49BCFA08C367F2B0ULL, 
            0x06DAC34466DA9218ULL, 0xE39B16047C5EE960ULL, 0x01015651BE17A4E0ULL, 0xF1C3B830A6F71738ULL, 
            0xF645D82766B14E83ULL, 0xB658B9FC361E90AFULL, 0x28AF640C15479219ULL, 0x37189DDC25ACD933ULL, 
            0x0BE073D4BDDB03EAULL, 0x8A3A36A6FFC76511ULL, 0x9CA200D539ED44F7ULL, 0x34119C87F54EB271ULL, 
            0x39A860B145DDE209ULL, 0x35DC3CCDA60CC5E3ULL, 0xB5C9DF7F01837673ULL, 0xC035DD7F5A7F1E95ULL, 
            0x5581255BD76AB9E3ULL, 0x52576AB8E303CECBULL, 0xD91580460D05D12FULL, 0xB62B9CC0F0579012ULL, 
            0x369CD2F5B535B52CULL, 0xAF2107A9D700F7C4ULL, 0x7C90E749A5289292ULL, 0x1C530DFDC6EB2358ULL, 
            0xCB2EF88DE89298F8ULL, 0x78CD6018462C585FULL, 0x2131360344161A25ULL, 0xCB397A8E3EC3264AULL
        },
        {
            0x1D94155B48DCAB9EULL, 0x74E984A759BE2BBFULL, 0x2898B854B02A9D28ULL, 0xFD305DA8320CF0E5ULL, 
            0xEF8321D5B22745C1ULL, 0x5DFD43888457AD28ULL, 0x36DBC2C6FBCFE2B8ULL, 0x0770CFCAD67C65BBULL, 
            0x99A65EF8915A341FULL, 0x4A1C81CFE544B79FULL, 0x754F092CE34ECEFAULL, 0x8792FA9C5775667DULL, 
            0x02B3D358B05CEC43ULL, 0x870F636AD7025956ULL, 0x300A9BB78757CC66ULL, 0x97AD8FA64D9FA34FULL, 
            0xEEAC802075F1E644ULL, 0x8763596DC8B863F6ULL, 0x6BA5DAF76DD6D35AULL, 0xEE49A99DECB20B38ULL, 
            0x6D5DEE7F953D4FC6ULL, 0x771C395C16343125ULL, 0xA8D25402D1F092A0ULL, 0xF9519EDE3156A08EULL, 
            0xB9E62A4E87554877ULL, 0xEFDF7AF755330EA9ULL, 0x7B75EECC4FFE596BULL, 0xBF5F549BB7A76A29ULL, 
            0xDB060A42230400E0ULL, 0xE9135B3F5F37C36BULL, 0x91B8027156B3ACAFULL, 0x8E4BE47AEC7DF9B6ULL
        },
        {
            0x3CC28015B0F5DEB0ULL, 0x269EB08125D7D5B9ULL, 0x8E92A31778888527ULL, 0xA46721C67006C024ULL, 
            0xB5E83D3C594D76A0ULL, 0x48906B7C04554F1EULL, 0xF07D7A2AFCC2E1DBULL, 0x8B605733E28210E4ULL, 
            0x98873324CDC947DAULL, 0xA0F2B0AA51D3668EULL, 0xC4169ACA1D45C648ULL, 0xC42060E1D09946CBULL, 
            0xCFE805A5676E1496ULL, 0x55ED89F8A088CDE4ULL, 0x3B21DC9AFD3CD8F7ULL, 0x8F6A1BE460CF2772ULL, 
            0xD86E555587F1CB00ULL, 0xF76250FE6E06837AULL, 0x2D46997E5B2D0FB9ULL, 0x3C62845D1ABC7D25ULL, 
            0xE41F72AFECE76C7EULL, 0xCB89624C45030CE0ULL, 0x418D9A60207361B4ULL, 0x1B9A1476EF3FAF64ULL, 
            0xAC9F47DDF107D0EDULL, 0x193227AA297E037DULL, 0xF97B20507CA5DF69ULL, 0xE6A78E801D6E750BULL, 
            0xB4F16A5845150F6DULL, 0xAE0CA38953B28E48ULL, 0x239508347E395A70ULL, 0xEDE1AD0FD652DC77ULL
        },
        {
            0xAA1646E19570B9AEULL, 0xCB57B2548B7FBBA8ULL, 0x6CA0385509781203ULL, 0x74EAD05B41F9499EULL, 
            0xFB8302CDBCE05234ULL, 0xB1B0F384C8724782ULL, 0xD0B8B59C8E701EB8ULL, 0xFE55F08925D21F0DULL, 
            0x629F9641C4CA1335ULL, 0x8C40D0106EB14403ULL, 0xAD521A2FFCBC552EULL, 0x9AC56B1EEA071F9AULL, 
            0xCE827ED2940F3AA9ULL, 0xA318D592E59DE19AULL, 0x0B4776BF90057E59ULL, 0x04407EC9E9890582ULL, 
            0x9C0419B70217FB41ULL, 0x0E23DB5D2CD77C68ULL, 0xE46AD42ED876B1DBULL, 0x58550F4F8466D4F6ULL, 
            0x9F841C66A51E3B1FULL, 0x0EC6421B069DA7CFULL, 0x52B25B11B5CADAA5ULL, 0x7D54100FC539BDBEULL, 
            0x1FFA439E1C23323BULL, 0x0A7728191E2ACF74ULL, 0xE5F339C53D76553BULL, 0xE94EB4CFC8A9A03DULL, 
            0x923E1A924EA7316CULL, 0x1C0E5D7DBC9F193DULL, 0x2D746CEDC8494B6EULL, 0x13DB494A4FC1D3EFULL
        },
        {
            0x6DF8D6311A7C9E93ULL, 0x2D534F0CA75D3BE0ULL, 0x15BACA38F07DC621ULL, 0xE3DF9B1466C0A1A7ULL, 
            0xE7D1A6B11C1BA1EEULL, 0x4A1B3AF764AB1A24ULL, 0xBEDBE7BDE117FCC7ULL, 0x98CBACA88B5DE667ULL, 
            0x1EABB9F3DBDAC05CULL, 0x479CCF5D06ED4DE1ULL, 0xA6AE7AFC5C8AC03BULL, 0xF632894B3B18609AULL, 
            0x6672E120F87666B6ULL, 0x705DF7749534273BULL, 0xE08B200B38D8AA04ULL, 0x5296163E3A857FF5ULL, 
            0x6D96C1C79B1D6414ULL, 0x23040A788698CCD8ULL, 0xF1B9CF13CC7321D4ULL, 0x16F8462B0568A863ULL, 
            0xC1F0085F0A7B57A9ULL, 0x7C9FD1BA2E267592ULL, 0x1841A79A837523D2ULL, 0x491D9E321692DA44ULL, 
            0x0448D4034F092825ULL, 0x172B5E5A081C25F3ULL, 0x685921665AD30B2BULL, 0xBE3B317BBA3D73A9ULL, 
            0x28F9E8167E0F9C2BULL, 0xD1B4C4839E42E684ULL, 0xE54E23B75207420BULL, 0x488EFEC0609B9929ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alnitak::kKeyRotateBConstants = {
    0xFAD72C138B1D5241ULL,
    0x388B892DD7CC2A13ULL,
    0x4AB895694B4E1154ULL,
    0xFAD72C138B1D5241ULL,
    0x388B892DD7CC2A13ULL,
    0x4AB895694B4E1154ULL,
    0xA0ACC9A1EB01E031ULL,
    0x8AA9CB9B86F34564ULL,
    0xAA,
    0xA1,
    0x34,
    0x5B,
    0x31,
    0xDB,
    0xF1,
    0xFC
};

const TwistDomainSaltSet TwistExpander_Alnitak::kKeySpawnASalts = {
    {
        {
            0x01AF0F2369BA709DULL, 0xA8EBC899615DF948ULL, 0x624CC8A18880CAEAULL, 0x5F3A5D33BD1574C2ULL, 
            0x14F3C759764A6A41ULL, 0x1BC8E46A5F4F131BULL, 0x6ACD35D246841DACULL, 0x8F2382A0924E97CFULL, 
            0x812EF972F8AE9A88ULL, 0xBCB5B5C82F8DB867ULL, 0xB8A2D5E2C898AE4EULL, 0xFAC66EF9B82D7328ULL, 
            0xC9AE4D4B593F3914ULL, 0xE84CC9F01A48CB03ULL, 0xA5672191F773D6DEULL, 0xED5A92430CEB3B4EULL, 
            0x92CC689FCF87DCC5ULL, 0xB9237736745B320CULL, 0x04B35165A748B297ULL, 0x22ECCE58C00DEC26ULL, 
            0x22391C05B8169E56ULL, 0x1353EE22D952477BULL, 0xDF7E53C81D598B45ULL, 0x6E202DC610A6075EULL, 
            0x1F702FB1FC694F42ULL, 0xE646B3C191471FC3ULL, 0xB690C142B135787DULL, 0x5DF71D7FDA29FC71ULL, 
            0x021B273F7498C554ULL, 0x61F6790B869F46F2ULL, 0x87C0D76A6340455CULL, 0x023F7565056B0457ULL
        },
        {
            0x25800CA6255C2E11ULL, 0xD47398F8466C13BFULL, 0x01034907FD5F4E30ULL, 0xE1E9B14BD07F324DULL, 
            0xB5C3C37C6D6CC72DULL, 0x2301893165812E94ULL, 0x2DC6C5497AC8227EULL, 0xEB3AF7474C1BAC7EULL, 
            0xF31FC3C7A90AC553ULL, 0xE859A79876670517ULL, 0xF978E04CDD78106CULL, 0x187FB54B07B87C63ULL, 
            0xF11E004E147C9846ULL, 0xA89115D3A40F3F8EULL, 0x9E6D7C798885EABDULL, 0xB70D2C9872B77CFFULL, 
            0xD8679C753D8E59CBULL, 0xDE0E96AA30CAA48EULL, 0x3DBB421CE9E004BCULL, 0x1F77F5595BEA7347ULL, 
            0x805DC2272E056E23ULL, 0x56470DA4B74ABF04ULL, 0x5CDB41C6EDACD5DAULL, 0xE7ECF0E00116021EULL, 
            0xCFBB2522C7E45980ULL, 0xFDCE55985E607607ULL, 0x2A9E4BA5BAAB3E7AULL, 0x9C76A2E6F1F0F95AULL, 
            0xE963B3CEF5DD9ECBULL, 0x278C464FC8C5688AULL, 0x0E29A752C1BC06E1ULL, 0xFFCD7C79CB28EA0CULL
        },
        {
            0x4F386F2A2C7D566AULL, 0xA4AE404C10043C2EULL, 0xDABC95F18ED13F21ULL, 0x9886CE66B083CA67ULL, 
            0x41B6ABE7075F1055ULL, 0x8BBADAD57232EF89ULL, 0x69FBF9A334FC8CD6ULL, 0xD64C6C04F2DE6589ULL, 
            0x3FD5F36E6D8DABA4ULL, 0x23EE32691E2DDEB6ULL, 0x51FEB7E9510403CAULL, 0x2E5A2383CDCF6B77ULL, 
            0x583799B0491D8067ULL, 0xAF4628F1185AFAE3ULL, 0x6543749261B9706DULL, 0xBEB8E37578242AB8ULL, 
            0x87D9AAC293DB1D11ULL, 0xF03B8E470893E721ULL, 0xB0EE42CF6A6EB225ULL, 0x31FB284805CC18BAULL, 
            0x888D2089CC975D46ULL, 0x24C6D7A5023C9303ULL, 0xF2611F27940EE39DULL, 0xEF66D49B06A4DB39ULL, 
            0x1ED8EB0882501BB8ULL, 0xA5B6D5EDA2332F01ULL, 0xC1F965FDC8CC8168ULL, 0xC301E10960EBDD2AULL, 
            0xE2507E83A0CE5251ULL, 0x9EF8927D36549942ULL, 0x21826CCAC8B2A971ULL, 0x9723EFEC55F53F53ULL
        },
        {
            0x7EA581155376B536ULL, 0x811910A86F057945ULL, 0x474EB971110F7ECEULL, 0x4CE4FABDB92A575BULL, 
            0x43F3C40C64B156EDULL, 0x1D028045AB95AEBAULL, 0x6CB9B23D6B56E231ULL, 0xA7D08FE989F79809ULL, 
            0xDF0244A97EBB6917ULL, 0x117AE269B1E9FDEBULL, 0xDF49441D66BB21F1ULL, 0x636D263CCE72B438ULL, 
            0x85D5E8576651E9A5ULL, 0x82C97446E0CCE637ULL, 0x591A235844885692ULL, 0x84770AA78E35C1B1ULL, 
            0x732C547296A53D3DULL, 0x1431152170CA4B65ULL, 0x8A0967F2D7A11459ULL, 0xA35CC1F97FD73F65ULL, 
            0x92FB7761578B2936ULL, 0x3B7267457AF013C8ULL, 0x3873C3856C09A73CULL, 0x4E129301F6A08ECFULL, 
            0xD2143B6367BBF7ABULL, 0x34FD270D76BBDD07ULL, 0xBDCEA03AEAC0A91BULL, 0x01494FE9B28A55BAULL, 
            0x10907C022DFBAB10ULL, 0x5537864ADCD0D7E6ULL, 0x74C12E0AD279BAF6ULL, 0x370D35CBFBFF1A8CULL
        },
        {
            0x4C5EF3D0B9599549ULL, 0x721BAFDAAAEB9347ULL, 0x7C3D9D863478EAF9ULL, 0xDC818440C00AF532ULL, 
            0x33B9015CA7C7D013ULL, 0x3A00BBB3F7B53C22ULL, 0x61D4B01A8699BD57ULL, 0x93DB3EB24AEB9F97ULL, 
            0xEBB39C80A0F957B5ULL, 0x24E9B500B108D703ULL, 0x98A2A4E0C82F7E23ULL, 0x751C2262917A825FULL, 
            0x5DA046DF336885EBULL, 0xADD9B7AF905C8714ULL, 0xCE7649DCC60698DDULL, 0xC78D134D573E2FB5ULL, 
            0xDB5D7B99C6B70FE6ULL, 0xF7EC2AE62F9556F4ULL, 0x14FB6135869A2476ULL, 0x62F819ADB30CD6D7ULL, 
            0x9DA27FE786E68392ULL, 0xE9409514BF109A6FULL, 0x457343F6226A98A8ULL, 0xB9B6BB28354649C2ULL, 
            0x512DF489FFC257B3ULL, 0x74A1E3D26D107DCEULL, 0xC854EAE9C51BD325ULL, 0xF940F768F3DBFD31ULL, 
            0xF85454B1312E1547ULL, 0x416561DBFD9DBDFAULL, 0xE40A2EE97E73227DULL, 0xDB19EEB732BABBCCULL
        },
        {
            0x3E6C41B8F313CCDAULL, 0x833261E8F388FB8AULL, 0xCCF0D5191577070BULL, 0x05F10F677146E5CCULL, 
            0x272E5C1F2BC4F864ULL, 0xBAB1A6A3CE58DAD4ULL, 0x44D81A81B5F34124ULL, 0x272A13CF000DA82DULL, 
            0xBC72B8D774D77F1AULL, 0xC76B40CA29422E10ULL, 0xF050FF088168994EULL, 0x9CE921B2C414EB1FULL, 
            0xC7E222C8148F59CDULL, 0x25B0924E116CF66FULL, 0xEEF90F88C67B8DB5ULL, 0xCDF2C734426CAF37ULL, 
            0x49DA5C3103587CD3ULL, 0xB5B9F2B18CCE956BULL, 0xDA7C573847145E83ULL, 0x04D960827FB7FA98ULL, 
            0xCFB180EEBC534C2DULL, 0x430BE067FBB2D85CULL, 0xAA7427F383BD83D0ULL, 0x976EB89E48DC9AE1ULL, 
            0x68819D51856AC6B8ULL, 0x8D5A0BC3AB192715ULL, 0x8A75B511FBDAF67DULL, 0xAFE49E2FDE0D3C12ULL, 
            0xF3E4E9AB5A45F0F7ULL, 0xDC3FEA51861B2F90ULL, 0x7B28626F7569E5AEULL, 0xB5EB6A1C98681DE5ULL
        }
    },
    {
        {
            0x023A501663296835ULL, 0x25EAB15A0ACD9CC8ULL, 0xE200764E7A019AFBULL, 0xAC7B4AAF9B3EA0E7ULL, 
            0x64AE8C50CA1CECF7ULL, 0x174D6BAEFAD6697DULL, 0x68D0267935E863C8ULL, 0x1A3A78E17E819F5EULL, 
            0x18D1D4B7AE69DFC0ULL, 0x87298F23F983057AULL, 0x0A992239F0BE2153ULL, 0x65DA91DC8A61A5E6ULL, 
            0x1D20DE240D2E7E46ULL, 0x89753883CD5F8703ULL, 0x48F78ACCE51C6387ULL, 0x1B02C5EF57C3DC77ULL, 
            0xAB9CD0DF535D9D48ULL, 0x1BB022A91C276D2DULL, 0x4D09AA280347173FULL, 0xC6CCF95F82B043F6ULL, 
            0x4E92B19C3CFC472DULL, 0xC4438480372DB0E3ULL, 0x279932CC13734DE5ULL, 0x02849BF6701EA1C0ULL, 
            0xDB315DEB80A7F015ULL, 0x59E1EB791118856FULL, 0x9202A4500D131ECAULL, 0x9CA7BF4C36F42E18ULL, 
            0xB2BDCB6ED59C1B49ULL, 0xE7CD21BAC75655E1ULL, 0x3D4F3FDDF5EEE0F3ULL, 0x63A689467EF90835ULL
        },
        {
            0x65689874B4A9E17FULL, 0x3E1C393385FE8CF6ULL, 0x0538E8A0AE0F4216ULL, 0x43076AD4ECF84B19ULL, 
            0x535E3FC1616AA1A0ULL, 0x07C153628AB549A8ULL, 0xA827C3F5675952D8ULL, 0x4F6200E6281726B5ULL, 
            0x964560707F9DFADEULL, 0x2ED9D0FA84D0C06CULL, 0x6082945E6FDB5D78ULL, 0xC7E37D45F59D19CEULL, 
            0x7B795A99E7952FD4ULL, 0xE7DED0295AE66C0FULL, 0x3764AD87E3ABE26BULL, 0xA3756F3607C20EF0ULL, 
            0x43732BA63113B06BULL, 0x2D967DDD96674325ULL, 0xAA0B69972E7F6DEAULL, 0x1362FED6BF4366E3ULL, 
            0x7BEFFE44EF8DD981ULL, 0x7F705516C060DD85ULL, 0xF72B003FE7070142ULL, 0x06EA0FBEC4363C20ULL, 
            0x8205C11447C5ED33ULL, 0x9D94C78A5D55F64AULL, 0xA302A11F01A45391ULL, 0x2B7CEAC3BD3C2A3EULL, 
            0x9946672E2001D1ADULL, 0x805F641F12B1156CULL, 0x2A33779F631A57BCULL, 0x5B115492BD272ABDULL
        },
        {
            0xA0163731079125F1ULL, 0x77B11851B3D69427ULL, 0x1C3E717F8001301FULL, 0xC697D76EA09C37BDULL, 
            0x973A41264771CBAAULL, 0x25BB5DB944BDEB35ULL, 0xE011D2925C5F45F7ULL, 0xCDE28ABF3159DE46ULL, 
            0xECF42F5E1DF457CAULL, 0x271F761BE42269A2ULL, 0xB857E114F7D0B84AULL, 0xAFFFA812214B22E6ULL, 
            0x933B7252A5B8293EULL, 0x5982851BD1C6965AULL, 0x502834CF76B46794ULL, 0xFAAA19AF6BC84559ULL, 
            0xB8F79CC127ED3BE3ULL, 0xC2825596E149C0BDULL, 0x30006CE1810F3D22ULL, 0x3CF9349FCF03E77AULL, 
            0xC039BE11EE62723AULL, 0xB0BE0422758D03D8ULL, 0x787994524EFA4A02ULL, 0xEDEBD7EC33696089ULL, 
            0x483C3DC3D8B73493ULL, 0x3A54B378912C7409ULL, 0x7797660CDDD7705DULL, 0xB3FBCFA5CE803EE1ULL, 
            0xD3FB04CE61CB52AAULL, 0x67B8D6FF235701A6ULL, 0x551E0E03206BB707ULL, 0x9EDAA31BDA412C2BULL
        },
        {
            0x844E89A54AE018AEULL, 0x319B9432474AEFAFULL, 0xC0364522D3F4514DULL, 0xC76C8E28553CFD21ULL, 
            0x0F7438185D9897AAULL, 0xB460B0AF499E59AFULL, 0x7BF4260DD63E8503ULL, 0x24FC84BB505321F5ULL, 
            0x5D3AC93E9574FB42ULL, 0xF904DC2A1F222242ULL, 0xC2DCD77888735A00ULL, 0xD4FCFEF0FBABA9B3ULL, 
            0xDDBEED0762D0367AULL, 0x7BF0C55ECD14A931ULL, 0x0A2D552F60E5F26DULL, 0x6D1559F22556A05EULL, 
            0x48DD8595438AC141ULL, 0xCE6D5A7EC1489CC4ULL, 0x1D2B998F6649E86AULL, 0xD045F5E6DBD28D38ULL, 
            0x4EFCAD153E573C7CULL, 0x2D30EE66137ACB11ULL, 0x1B895FC593FF0E83ULL, 0x2429DA36099FDFA6ULL, 
            0x4EDA71904B903F52ULL, 0x1012F26A159D4200ULL, 0x221457656677356FULL, 0x980C9DDF78C44D62ULL, 
            0xB4979DE5A200427BULL, 0xAFDD7C66124CF412ULL, 0x41400190BD3C4014ULL, 0x6B9998C0FB68FFB4ULL
        },
        {
            0xDD564CF6CC856C20ULL, 0x3996991D0FB6BC4CULL, 0xDB0829DFEA076619ULL, 0xA6E40C8AED7E36DBULL, 
            0x6A26C725DBE0D6B2ULL, 0xC8C166F78ED888B4ULL, 0x005F58F451BB4D20ULL, 0x5BDCF9FB8B79D14EULL, 
            0x5A475A4520A6FD03ULL, 0x254793270752C186ULL, 0x3DDDFC4A16F3E83CULL, 0x7EC65DA4A9AE33C8ULL, 
            0xEDC657F4FA5AFF0AULL, 0xA1144B3400267746ULL, 0xDFDC055DD78F4D4DULL, 0x81C163147D277980ULL, 
            0x8FCDF554EB351289ULL, 0x2912F8D48AC704EEULL, 0xA16A4061A07D3A22ULL, 0xDDF14F9721947083ULL, 
            0x715FEB034255B1CCULL, 0x114C0C0DFD07405FULL, 0xA897334AFAE8DB59ULL, 0xC8ADE0CBED8C5955ULL, 
            0x1D939CC0C4EED0D0ULL, 0x37B3419B87F7A74CULL, 0x9CBAAA33E2336A5FULL, 0x778C1871BE82793AULL, 
            0xA59C393DDEB1D537ULL, 0x174671B16FD29A5EULL, 0x30FE98965E231C9FULL, 0x5A5227C800B29842ULL
        },
        {
            0x90E6578762ADB78CULL, 0x6FF7E29E034FDF78ULL, 0x8059D37F1ED37021ULL, 0x15B742BFFB1562F7ULL, 
            0x50AB0E17A9F4FB10ULL, 0x9B64D84B2EAE9185ULL, 0x2C4B8575E728C93BULL, 0x411498C0BC9DF636ULL, 
            0x64E00F468A13CC7CULL, 0x30E1D66B52E6C8DAULL, 0x816CDA18577E2AEAULL, 0x34DB88F14099689BULL, 
            0x09848EAB36BB9E71ULL, 0x2C11ED00A3BFEE42ULL, 0xCDE2BF8029BDE1E0ULL, 0x55DB49CC07594892ULL, 
            0xD22BC38A92BCCBE8ULL, 0xD8BD2FDEE7C27B79ULL, 0xEA3D6C2D862F1EE3ULL, 0x8F39AAF0431F82ECULL, 
            0x877AB5FD1895D2F9ULL, 0x2EE5BA76ADE345D8ULL, 0x85AB91B26729369EULL, 0x619AFCED45792CB0ULL, 
            0x4D415582E1B112ECULL, 0x3B404F7E84C7D101ULL, 0x375543CB1429212AULL, 0x63EA564C55CBD920ULL, 
            0x863930F9C589C5B0ULL, 0xFB7ED1964B4393C1ULL, 0x7EF1A06C02AA49F9ULL, 0x40034624FF30CF44ULL
        }
    },
    {
        {
            0x2B6FE6C2B1BF5A01ULL, 0x0FFA4842FFB62B93ULL, 0xB0135DC1CC862C93ULL, 0xAD39612B8164702AULL, 
            0x0B1BB3855019589CULL, 0xAF3CE0B5BC84B560ULL, 0x2BED6C7CF244932DULL, 0x8F6C503A0FC400E4ULL, 
            0xF40AF19CFDAA2F95ULL, 0x4E626C801FA08771ULL, 0x9E9782441C6E5433ULL, 0xB6F1A7DC0C93FFF8ULL, 
            0x35F2B80EFE0BE481ULL, 0x04179E3E4888582AULL, 0xA96CC1894A58356EULL, 0xFE4AE1B146C5F8B0ULL, 
            0xB22CAE0858503C55ULL, 0x399C9905743A33C7ULL, 0xF20FE136FF0D4B18ULL, 0xB4F5F2AD0D3E39D2ULL, 
            0x86375A2C24308C73ULL, 0xA252A5E2257822C3ULL, 0x1E68446D84E57153ULL, 0x1F858CA6EB0C6F9FULL, 
            0x743A72C46FE7AE94ULL, 0xB969B204F1969A32ULL, 0xDD57E6365161AC63ULL, 0x73E8A40E54F13E49ULL, 
            0x803C1267061B5D91ULL, 0xB3BC2D034B539EEEULL, 0x19BDFA50784642FDULL, 0x64C6DE7C06812A0AULL
        },
        {
            0x4562693ED58C9988ULL, 0xF6566138A8A17B43ULL, 0xDA3C18E96E8D406CULL, 0x532C3544E114FADEULL, 
            0xAF4ABBB7023A5F1EULL, 0xF98B950B7B051B47ULL, 0xF7ECC91EF8B804D7ULL, 0x26742CCB9967F08DULL, 
            0xF4B598A7B48F5B70ULL, 0xD191A12F6F0E3A38ULL, 0x465D841846FCD45EULL, 0xC74519ADC37CC036ULL, 
            0x6DF36D42241C8682ULL, 0x8E22F4A398812059ULL, 0xD4D963E4FCB1A9A4ULL, 0x870B8FD524C9A565ULL, 
            0xFDB62765D2A815A7ULL, 0x149C4DA23A52B410ULL, 0xD32187F0201CFEABULL, 0x08B5F11068399DD7ULL, 
            0x279F1C4205B682FEULL, 0x0E17926B428BFADEULL, 0xA5E161AC07A6F652ULL, 0xE7FD54BD63CC50F6ULL, 
            0xCDFFE179ECED7178ULL, 0xC039198F96006178ULL, 0x289E89045485F46FULL, 0xA2D5B99B0382967BULL, 
            0x9E4E6B83F4983DB6ULL, 0x2C915E05B2212E53ULL, 0x6D485BFD2F975471ULL, 0x09A6A1AA4975572FULL
        },
        {
            0x461B0B5912B11BE2ULL, 0x3D3A97F623A4B087ULL, 0xF6EFE84B31866F13ULL, 0x2FF176D6F2A12C89ULL, 
            0xB05E640ACB809521ULL, 0x914A607D4D5E4568ULL, 0x2CC8DC75E0FAD8A3ULL, 0x66C7EE9E9E2EADBBULL, 
            0x11C69D38CD854F8FULL, 0x15160D1E54F749DEULL, 0xD3A28C21D8077E53ULL, 0xEBD71AABD4B4733BULL, 
            0x179281F3C758936BULL, 0x02DA6B90F88BB421ULL, 0x563D20D79ADCF4DEULL, 0xAA0605B57395A951ULL, 
            0x6A294E7A067842D4ULL, 0x8CA71588EA6E0BB8ULL, 0x04F9F979AD0EF4E7ULL, 0x45EE89CA093CA5E4ULL, 
            0x37B4584774B47757ULL, 0x7B65860ADAE7B62DULL, 0xB1259179932D5642ULL, 0xE22D7556A63CFE1BULL, 
            0xACA1D63FAAE813BFULL, 0xD8A7280B6E16F2E0ULL, 0xCF3EAC7A3E0352A0ULL, 0xD1FDB7466BEFD694ULL, 
            0x7FB76EC36DFFCEEAULL, 0xD2987F47CEE6BA41ULL, 0xFA8F5B34CD733B40ULL, 0xB1A8C2E6E8462B82ULL
        },
        {
            0x6EECAE2340E0E009ULL, 0x87736FF7D492577AULL, 0x376C3080B0D30E73ULL, 0xFD0CB2C4FCAC7B95ULL, 
            0xD6B1AA4C4E52FCF0ULL, 0xE1D26AD38B9F3953ULL, 0x3148831814D237BDULL, 0xE1223EBD2F64EFD4ULL, 
            0x6E83F81D991CB54DULL, 0xCD13CCDF471AFFE5ULL, 0x6F017C5AB5676B3DULL, 0xB5B58FCCA0160318ULL, 
            0xF994409E3089C6C0ULL, 0x3B864546232B739DULL, 0xA673AF8EF6E96171ULL, 0xFBF8730B95DFB029ULL, 
            0xFD4DA8098BA43C88ULL, 0x9E50D07ADEBEBAC5ULL, 0xCFEB40E9BD0B3665ULL, 0xA5C84BC13579692EULL, 
            0xAE845A0495729F09ULL, 0xE0F49032A13DFD61ULL, 0xA9D2D2414DEE2746ULL, 0x9B72455394C867A1ULL, 
            0x9D0725BF332DF1B3ULL, 0x876AAEDBF6119CC1ULL, 0xCAFB627870DF1F42ULL, 0x32BD6D93DC7B99E9ULL, 
            0x48B60AACE20F707CULL, 0x7BD2373DBE54588BULL, 0x755FD452EF590B89ULL, 0x8E9153C8FAA5916DULL
        },
        {
            0xD80CFF0A9F143705ULL, 0xEE473281B08D31C4ULL, 0xA792803C00962E32ULL, 0x3EA8BAE63E85874AULL, 
            0xFFBB964E4085ABB7ULL, 0x3A12AB4F6A08F4D1ULL, 0x7B2F45B9F1D92C2CULL, 0xA2A665315ED6FA4BULL, 
            0x9B2897170FDCDF19ULL, 0x59EAD9D443073063ULL, 0xFAEE9194122F3BE6ULL, 0xD3442FDC9E92A5B3ULL, 
            0x5D50C042318B56D2ULL, 0x68B29A0BF30C2262ULL, 0x029C4FAF1738FCE0ULL, 0x58294B2BFC90E0F5ULL, 
            0x921173163599AC0DULL, 0x3C80C04091C1A660ULL, 0xF4B451B7C0115632ULL, 0x83003D8D2A80F380ULL, 
            0x6C02140DDF81EE12ULL, 0x2FE4F8D6C426F5B2ULL, 0xF17B4D794D2D3BB5ULL, 0xB702CEBA2126C273ULL, 
            0x054908EB59EC0977ULL, 0x711A2B28A5C9F62AULL, 0x766286D1602BB3BCULL, 0x9AB1870A4683D52DULL, 
            0x0735831501718062ULL, 0x0ED1252997AB2396ULL, 0xEA0AC60BA0F7CA8DULL, 0x7BDE84299AAD7D6EULL
        },
        {
            0x3B84D37ED9D82067ULL, 0x1140807AF0F89CF4ULL, 0xAC17E8601F89A481ULL, 0xF2C51093487FE278ULL, 
            0x447D70029D3B4850ULL, 0xA4C40FEF4C760D4BULL, 0xC0AEACBACCE5E6BCULL, 0x90EADD398E74E2CEULL, 
            0xFAA71B2565B2D31EULL, 0x7A34845008E98F18ULL, 0xAEA3E42B5146BF40ULL, 0x08C8054581F94CC1ULL, 
            0x3506667B141A0431ULL, 0x23013C5142F5B9FEULL, 0x6F9612D035895F10ULL, 0xAEFC858B10EF4888ULL, 
            0x4EEE4653DD3432AEULL, 0x21BA1D3DF9024559ULL, 0xB3EE2ED6BAED6C82ULL, 0xCA0F00A542331FBAULL, 
            0x38B6D1C3B4FBA1DDULL, 0xF3EFA6802BD6E474ULL, 0x58E2EB68B011C6ABULL, 0xA0F89098DB00A25BULL, 
            0x414479AC69BC0AFCULL, 0x0AF41D0AE6644B4FULL, 0x07D94744D4CFA178ULL, 0xDBA76F54DC67F9E9ULL, 
            0xDFACE315A3DAFC24ULL, 0xDB7ABBCE05B6DB8BULL, 0x3EB4DDC18D0C4B4BULL, 0x2A7885AC7B781FD8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alnitak::kKeySpawnAConstants = {
    0xDE67EED3F3173D24ULL,
    0x2AEE0AA21B36FB9BULL,
    0x19C62E5A7F12842BULL,
    0xDE67EED3F3173D24ULL,
    0x2AEE0AA21B36FB9BULL,
    0x19C62E5A7F12842BULL,
    0x68E52288DE56A2BBULL,
    0x6A6F214CE205B2EAULL,
    0xA4,
    0x72,
    0xC3,
    0x11,
    0x38,
    0xD2,
    0x4D,
    0x05
};

const TwistDomainSaltSet TwistExpander_Alnitak::kKeySpawnBSalts = {
    {
        {
            0xBCB3172C918ADB4DULL, 0x967EC7F6F159E5FCULL, 0xE420FB2DCB8FA431ULL, 0xA494B2616F3013C6ULL, 
            0xDD2336B2662F87A0ULL, 0x825DE5E191CDE60FULL, 0xA8DCF625BB87F7D6ULL, 0x7DE41FEEA80E2568ULL, 
            0x68448BEECC461DF0ULL, 0x1E2EE8B1B01B1FE4ULL, 0x3F1BA6B2D184890AULL, 0x0232ED0244565A3CULL, 
            0xA7E28ACA8F866C17ULL, 0x7B4333EEA29D9230ULL, 0x782D33347A7C57FCULL, 0xADDB98766420E1BAULL, 
            0x9F71C9BB41E4B0DDULL, 0x623D9BE9B08F7F6CULL, 0x12E1BBC0C9159605ULL, 0xF322E6973FBC4A4CULL, 
            0xB3E738ACFA2394EFULL, 0x74A1808F522A0086ULL, 0xB69A89CDB4A43C6BULL, 0x0AB02E2BCC5F0CE4ULL, 
            0x3DB4985876BD1261ULL, 0xEE9BECBDADB30C88ULL, 0x52CF78C9A64D039BULL, 0x55A719FB5A985E67ULL, 
            0x08A53B5783058F2FULL, 0xD3FFD01DB59B1949ULL, 0x9D5332CBD08EAFB1ULL, 0x69439CAAB39B9C2FULL
        },
        {
            0xF12DA95E41D366B3ULL, 0x51AE39C002A1B14AULL, 0x0A9FEEADAEE9879CULL, 0xB30438E370FDB02BULL, 
            0xF3D8ECEE640C374EULL, 0x186E06A8A0C0DFCFULL, 0x7A5FE81C530C1579ULL, 0xF34E4688282A386EULL, 
            0x7AFABC7EA48A939DULL, 0xA942DEDE5F61CB99ULL, 0x6A3C4D1DA345C013ULL, 0xC4D69DC74F68FE55ULL, 
            0x050AEB683B3F6CCDULL, 0xEBB36C7097AD2B7FULL, 0xE8107AB7F5762981ULL, 0xA01994D779FCEBBCULL, 
            0x247F7F68628B68E0ULL, 0x853F120302E79551ULL, 0x0E75AB2A8E3109EEULL, 0x43252ACA58F14C6FULL, 
            0xBD660A89D3426F6DULL, 0xDF82E2F8DFDDB346ULL, 0x7433D9B76639B066ULL, 0x68A438D2823692F5ULL, 
            0x0242C72886FDC3CFULL, 0x89E2CCA2A5492943ULL, 0x11DBAB5C5EF6C2DDULL, 0x76F180D7E47A1C01ULL, 
            0x28F86FEE73138190ULL, 0xAC46C39AE88A2A7EULL, 0x04DD94EDFCCDC6DAULL, 0xB8B0788DD1FD4D21ULL
        },
        {
            0xB7FEEEFF368321D0ULL, 0xB4A1878D5AA5CC4AULL, 0x91167A0467B16BAFULL, 0xA9D7746F77FC5A3AULL, 
            0x8A25698AADC26C60ULL, 0xCA268491690ADE43ULL, 0xDA4D77FFAF75884EULL, 0x04EC75718305FB09ULL, 
            0xAF0966F97C5C3BD2ULL, 0xA7242303D80D9BA4ULL, 0x5472F88AF6474946ULL, 0xFD36782CBB4D4B64ULL, 
            0x1099B9269DBBB1EBULL, 0x5181B42D666D7C43ULL, 0x96A6B7316FAAD8CDULL, 0x284A34C76C4539B2ULL, 
            0xE251F6C2838D281DULL, 0xBFD7CDF0FFEA27AFULL, 0x72D793B4B85565F4ULL, 0xA96AD72650745662ULL, 
            0x9D2BCAA867495123ULL, 0xCC28A276DECD0372ULL, 0x61703CA2307A96F9ULL, 0x8A9A86E732C2E4E7ULL, 
            0x522D49CC0F88B3AAULL, 0xCCA4F6BC340991CFULL, 0xD0D8D6EFA3F44E51ULL, 0xA0C9294E0F778A01ULL, 
            0x3DD5DB0BDEC5DF36ULL, 0xB71CFE3AAC0FF1BEULL, 0x872907A9B40A9AC8ULL, 0xC7B51F655733AA68ULL
        },
        {
            0x9C3C738953F77BA2ULL, 0xF69E597164F8B56FULL, 0xDDB890DC69D26974ULL, 0xFB7D5891AEFF9ED8ULL, 
            0x044931375107A2BCULL, 0xBE1E88CDD66E2122ULL, 0xF20DB1A393B266FFULL, 0xD6EC791CD0E2B555ULL, 
            0xEBD25503241D7617ULL, 0x9E347B87123BCD05ULL, 0xF7EB4DFBBCE88C58ULL, 0xD17C15687EE3C9E8ULL, 
            0x69ADCF9DD90D9342ULL, 0x6758172159F46517ULL, 0x4342B4259E957FC5ULL, 0xE55C7C7017958F20ULL, 
            0x0D19898FABCC93F0ULL, 0x98D15890E81D8BE2ULL, 0x2D74DCCFF8AE20C5ULL, 0xD00FFAD6A0B38929ULL, 
            0x8CE9A3658209D61AULL, 0x9CA8F37E4243FB97ULL, 0xAAE384C634EDF32BULL, 0x467CCE59D8CCA561ULL, 
            0x8CFCA9A0AC6A77B5ULL, 0xC4E3C20FD6433E48ULL, 0x1D9808787218D094ULL, 0xFC615A27791223BEULL, 
            0xFCB5486B52D3A383ULL, 0xC3A801DC6A8178AEULL, 0x9D964189E9181D51ULL, 0x7DC70D0FCDE4834FULL
        },
        {
            0x3277896EAC681CE0ULL, 0x0BBEDAE7ADBB4636ULL, 0xC53BA6CE7C227BB5ULL, 0x997B0EAFA8CEC99CULL, 
            0x09796B08051C930FULL, 0x000D786627F73CDBULL, 0xA49D41D27BCB2FDFULL, 0x52793FA2851FF971ULL, 
            0xDCAEF46F47ADAF92ULL, 0xFFF5F77D56A6E622ULL, 0xCCDA7386363DD900ULL, 0xE71E83FAC867EEBAULL, 
            0xFB5FEBA498397C12ULL, 0x7C5B12E0BCA5EB68ULL, 0x6EBB52471EAA5B95ULL, 0x87F808C3A63AD1FBULL, 
            0x21982F32B6826FD2ULL, 0x493C818E19547BEDULL, 0x51C2D5FCE10419DAULL, 0xBD7CCCE563740E68ULL, 
            0x5B202CDE098C655DULL, 0x379EF2A2E07C058FULL, 0x369D84A9833CFB12ULL, 0x6F2A7604872719CEULL, 
            0x48323603AB6B2977ULL, 0xEA2EF3851AB91A36ULL, 0x40FCF2CAF449157AULL, 0x027F51282603F5B3ULL, 
            0x6530EA8EFD016B86ULL, 0x23E6B8D43151E3D6ULL, 0x5973469D16F44D17ULL, 0xB683C20DAC6E4FF2ULL
        },
        {
            0x6FF7A20E49B1B2C8ULL, 0xBEBB40AE12CAC737ULL, 0x86571B8F357E52B4ULL, 0x8B3F4CB8DAFCAE5EULL, 
            0xA34DB3DC1FD7C5F6ULL, 0x7A1A47D2B17C505CULL, 0x6042D6F509A6196DULL, 0xA3C9817F76009ABBULL, 
            0x98D222282506BA5FULL, 0xA62F76E50CAAABC0ULL, 0xF3F5316D22017578ULL, 0xDB5EADBADDEF62EAULL, 
            0xEE7F88B93A95C3E8ULL, 0xEBC5C9B3ED7B03CBULL, 0xFD058086992C6F39ULL, 0x99E8A90C7675E100ULL, 
            0x4C73D7C16033BEFEULL, 0x0806858EAF1708D0ULL, 0xB2D1FC2D9587505CULL, 0x749DDCAE3C370EABULL, 
            0x6F66ADBD1F33456DULL, 0xF1D28AB30E6DBDD9ULL, 0xB9BA58AA8A526820ULL, 0x530C23417EAE2529ULL, 
            0x01C2DF718598AB7FULL, 0xD7FF9D36332CF341ULL, 0x3DF2B423FC875466ULL, 0x641AA096DB6BBB17ULL, 
            0x9B5CC6A0C687372EULL, 0x1FD9E09195732CFFULL, 0xC00FEFCEEF0BA474ULL, 0x05F7E3228ADB59E2ULL
        }
    },
    {
        {
            0xF61F7CC7B1E094DFULL, 0xBD6F249F7C16FCE8ULL, 0xE82233DF1CD2F985ULL, 0xFD35A470244979C4ULL, 
            0x48453F7C14521146ULL, 0xF5FEA0547F75CED4ULL, 0x0EEA0DFA1E06EB72ULL, 0x7BD001A07878A787ULL, 
            0xCFA72E8B99B81D7CULL, 0xA64C1B00001D62A4ULL, 0x58A4C63B013286C2ULL, 0xC5EA1AB959434698ULL, 
            0xF60CB6912CD3E9D6ULL, 0x252F55510AE2CC85ULL, 0x63810256964183C0ULL, 0x490E47ADEE8410A9ULL, 
            0xBBFC1A43A0602040ULL, 0x0C79EDA4B33E4445ULL, 0xD30448020B276326ULL, 0xF17BC240301DBD57ULL, 
            0xC4B07071D9DF7E92ULL, 0x0A30345CF8516954ULL, 0x23F1E7598FCE6975ULL, 0xB4C75C18AB8F1A6EULL, 
            0x501B70032E5FE320ULL, 0x90D65E12FE0572C8ULL, 0xC991876607E0C095ULL, 0xAEDCA69175AB8A0CULL, 
            0x7AC7019A2FB9E5A8ULL, 0x69F53CE7C2C21C87ULL, 0x148C028C2397CDF8ULL, 0xCDFE403A624F9CA0ULL
        },
        {
            0xCE8F96CE298ADA30ULL, 0xA67EE22B224AE30EULL, 0xA161DC7AEB60817AULL, 0xCCE57989A5074F37ULL, 
            0xF68B343C0D39B54BULL, 0x5D87F11A1A860107ULL, 0xBCD2ED11E3282E9CULL, 0x649DB1E417CEE245ULL, 
            0x3898EB1A0CBB89FBULL, 0x8FF4FAB3D4619247ULL, 0xCF6736C103FC9D4FULL, 0x280A8577E30BB78AULL, 
            0x71F6B1F21D4CFBD9ULL, 0x34567748B0FD58ABULL, 0xE3E0DA9797BF9074ULL, 0x19E6F8DB4A6D1581ULL, 
            0x421BF40F5F911A09ULL, 0xCBC1DD3F4311F092ULL, 0x82E12531D3B04FA9ULL, 0x8B3449894968C6DFULL, 
            0x8BC05D8690441881ULL, 0x8A4D6AFD58C82D82ULL, 0x9B026B85E79F814AULL, 0xD8336B4C927F96F2ULL, 
            0x7322ADDB489A681FULL, 0x68D26D0E24A05415ULL, 0x0495A7AE2EB409DEULL, 0x64899E73B33CDCCAULL, 
            0x7460D098F19DDD96ULL, 0xCAEF524D818D23FCULL, 0x61D141825C6E1E5FULL, 0x45EE67CA07A99D53ULL
        },
        {
            0x4D2168FE871E827FULL, 0x4A6D64B3737AA05BULL, 0x1027CEA156D3D9EDULL, 0x88D530D857CE8467ULL, 
            0xCF4589EB31E1F450ULL, 0xAF5E0D42C8736D76ULL, 0x1971069D80E8933BULL, 0xBDBF5B7432C00D7FULL, 
            0x95E470D333C0895BULL, 0xDA1E475BE6E86428ULL, 0xDD0F8E3AA272C7A7ULL, 0xC00FCB0AAC7DE18FULL, 
            0xBD0D62DC77EB798BULL, 0x71B3D45B93B99F42ULL, 0x147D7E8273813080ULL, 0xBF3B7EAB76A85DB1ULL, 
            0x7D01C47CDEB91617ULL, 0x2E9413971A4D9B44ULL, 0xDFA38AB38EC00008ULL, 0x5F275F35657245ACULL, 
            0x4BBBDF95696BE58CULL, 0x84913DA72422A76CULL, 0xEBC267A43F13DDE4ULL, 0xA72D440073DC1388ULL, 
            0xDC9D2EFEBEDBEC5DULL, 0xC1743E6D5B7157A6ULL, 0xD97ED897221FAD56ULL, 0xB7F3C42BD73539CDULL, 
            0xDFA11865A98A1724ULL, 0x036F55109D3E3FC4ULL, 0x94883468B8A70B14ULL, 0xE329E9FA2D8D2C62ULL
        },
        {
            0xFD86B554F515D1D5ULL, 0x56B243FB9EBE8569ULL, 0x84B4D1CEF7E8A21AULL, 0xA07AE075BA2173CEULL, 
            0xE1FAC5A1B2CED02EULL, 0x4F9FE03180951493ULL, 0xC15EC88FFE798E9FULL, 0x55C1540D7C756898ULL, 
            0x63CA4810AFC0DD1CULL, 0xBBDC1187499261B0ULL, 0x87BE762B248A89CDULL, 0x5BD21F33F5DCB31DULL, 
            0x7A67E7923F1C0554ULL, 0x1FE61E35761DBD7DULL, 0x10C9CB5847067B84ULL, 0xBEAD780544E13EACULL, 
            0xF2A9F9C65A76A697ULL, 0x171F1BDD6F08B33FULL, 0x6910E1A580B82E56ULL, 0x60DF7675A82E4D6CULL, 
            0x91722339478589AFULL, 0x2964EC60184A1D09ULL, 0x446F5B25CAC7570AULL, 0xA5CBF4F939FD92F6ULL, 
            0xCB2AE599B7571678ULL, 0x83864EAEC2927F32ULL, 0x0F0B6130329D30F8ULL, 0x36800446E2BC4876ULL, 
            0x3FCD93BF1D4098BAULL, 0x3F470CD5CB746E35ULL, 0x108AF0B700D80FD1ULL, 0xBB32FBD444CE5797ULL
        },
        {
            0xACCDBB4C8C2CC0BAULL, 0x7E83B74FAF32F736ULL, 0xD4209F86F8D7EE7DULL, 0x8DEA6BA8412FD68BULL, 
            0x22E333AFF5AFE6EFULL, 0x21401230F0ECB3F8ULL, 0xAC08CA72304C2CE8ULL, 0x1D365E6586479CD8ULL, 
            0x17FABA81B7FF590BULL, 0xADDD8F2ACE2E6C32ULL, 0x5BBA36D6A8547EFDULL, 0x39E71B9FA0F9FC37ULL, 
            0xC643112E6147769FULL, 0xEC5BC952FFA8B152ULL, 0x15065F4E80B9986CULL, 0x94C21331A214A76AULL, 
            0x27FCCB2C209BC019ULL, 0x08911F18A24126A6ULL, 0xCD08CBB5BC3239B2ULL, 0x34305B1685058A3DULL, 
            0xFB32583E102FB992ULL, 0x48C974D58B263E54ULL, 0xC503686FBC4B235BULL, 0xBF7AA62FAAA0E48BULL, 
            0x02C964F7B664EE23ULL, 0xFA9FE2B151E9C382ULL, 0xED1CF44CFC7E2A88ULL, 0x5776C652F531C77BULL, 
            0x695B08D6A5C9491CULL, 0xC1A0513D323569E2ULL, 0x13D647832A70E6D9ULL, 0x2CE7F2C80371C450ULL
        },
        {
            0xE98B583ECF38ACCBULL, 0xD27941D5D3533F6BULL, 0x6853BB9918FE49D3ULL, 0x1C3B59F370A95894ULL, 
            0xD137CA94B3A5D4CCULL, 0xD0B118EED6100050ULL, 0x67FA9B649D490468ULL, 0x7F8122A287304C85ULL, 
            0x48279F7D26400D88ULL, 0x7CF56E42136621F6ULL, 0xDD58749DABA8F5BAULL, 0x9AC8C25084358476ULL, 
            0xCF82E7CFCCD543CDULL, 0x402D8A89B2401FE6ULL, 0xF3EF04C93565C3E2ULL, 0x4A24E4FB97CE5F73ULL, 
            0xE438DC0F00E467F5ULL, 0x9C55B8FE2DCB938FULL, 0x8889E492A597267FULL, 0x8BB49CACA9551733ULL, 
            0xE3065E684935BEAFULL, 0xDFA3636BCD327A6EULL, 0x037D47095BE26434ULL, 0x952DBE8D23D9BA0DULL, 
            0x53447AE72643AAA1ULL, 0x0A6E0E44F1B3EBEAULL, 0x45950CBBD7C89E42ULL, 0x32611BC1C8B75DEDULL, 
            0x423A9B42A9CF7D32ULL, 0xDF74E4291CC3A373ULL, 0x1481A387029514B1ULL, 0x1F113B7FC6B6B980ULL
        }
    },
    {
        {
            0xB30F1562E4DA09FDULL, 0x75BB6D504A232E88ULL, 0xC48C602FEB641F90ULL, 0xEA3958C54188054BULL, 
            0xF3FB539D15227692ULL, 0xB51E4B5CD439F2C3ULL, 0x7C37173C45138961ULL, 0x997B46550F5908F3ULL, 
            0x7FD4007BA1104750ULL, 0xB025BC5D5BC6B9F0ULL, 0xE27D428935594229ULL, 0xC2A76E34714FF8CFULL, 
            0x7C130645F4208017ULL, 0x95433147C6D22DA3ULL, 0x8FDD3A21C1862975ULL, 0x0AD581E6F1A05CC0ULL, 
            0xE12B6436526DC313ULL, 0xE54A4D32D7703631ULL, 0x0663BB27E6BE939FULL, 0x5C1DCA4F22B79F08ULL, 
            0x0B349379CC60A901ULL, 0x630B2BB8415B4505ULL, 0xAC7DA468DB4CD32CULL, 0xD92F2C0B60344580ULL, 
            0x1CFF8103080015DFULL, 0xF842610462567FEAULL, 0x7F787ED43FB9DFD1ULL, 0xDDC505EF47A09D57ULL, 
            0x167636374860BB88ULL, 0xB45DE781416AA91BULL, 0xD247B1C0E68DD6E7ULL, 0x66534A97EAAD79F0ULL
        },
        {
            0xD124EF553D1BE965ULL, 0xE245FF3DD7D8946AULL, 0x08E07C4C5936BF29ULL, 0x723FC51793869DACULL, 
            0x26BF8BC3AB57723BULL, 0x16F2996CE2F83B0CULL, 0x3860DB4FCAC46F04ULL, 0xCA57509560316A97ULL, 
            0x88D7AA46C9D4FCD4ULL, 0x07C44E2BC7073A6CULL, 0x6DFBBDAFDCF66E36ULL, 0x463DE9EB6B900B7EULL, 
            0x45480BE1BF79B7C5ULL, 0xF004DB4F59F08787ULL, 0x38BD8BE31D0F5CD1ULL, 0x3C905087A8C87F97ULL, 
            0xF331184EBA535153ULL, 0x4B11A13D52F111D1ULL, 0x6525CF3D84B2DA19ULL, 0xB090FFC488C8F0D3ULL, 
            0xD7CF240E6A79F99DULL, 0xBA0EF41417F16822ULL, 0xEF78BFA469220280ULL, 0xB9188B792686D0CFULL, 
            0x127A1D16F7B7D11CULL, 0x07818B0D217A189DULL, 0xC5DBA217B1A704ADULL, 0x62B92ED6550555C7ULL, 
            0x9A09AB056D7E396AULL, 0x97DE840EBFF6D178ULL, 0x599110C2F715A589ULL, 0x2745D882E7D71032ULL
        },
        {
            0x10E1A7FFBCB5F668ULL, 0x728E24737BE2DA6AULL, 0xB32E3EE53E1C5EA4ULL, 0xFD00CA10578C2EF0ULL, 
            0x6E0CEC6B00534AECULL, 0xC05E93E939D158BDULL, 0x086972389AFF86BFULL, 0x215E7E888A91CA8EULL, 
            0x01278FFC890ED9BEULL, 0xD69649AB5967B896ULL, 0x7B083A5F777FC669ULL, 0xFDDDD5EAD3AD9D1BULL, 
            0xB07C86AECC4EDEBAULL, 0xDE9AA14AC04CDB80ULL, 0xE896A826A67C1C39ULL, 0x570498C73F74D15DULL, 
            0x0C1F361BB25AD741ULL, 0x8BCC913813F5ACCFULL, 0xC86E6F261AF9D029ULL, 0xBF8132C73D4FCAA8ULL, 
            0x7D0070A9733D551EULL, 0x947C94D71459CA68ULL, 0xD26CE09F9E510111ULL, 0x132ED11326450AD2ULL, 
            0x4925E99C4AD020CCULL, 0x0DC7DCBD8F429924ULL, 0x676A466D33561E86ULL, 0x5E8C5F62BDF38F4BULL, 
            0x0A068D093FE6402EULL, 0x1C503829E67BC333ULL, 0x6BC34D166242AE5EULL, 0xFBDBD639BC9897CDULL
        },
        {
            0x8D831D495943452CULL, 0xE92456D48A9D86A7ULL, 0xA9B3B08931058840ULL, 0x3C761EACD2FC8FC0ULL, 
            0xE220305AD6F06557ULL, 0x187B7ED6E600F2B0ULL, 0x26CDA554898695FCULL, 0x970463E10055DD6AULL, 
            0x48274A6B0D1E60ACULL, 0x3C965ABE8C9748BEULL, 0x2CDF9DFDB6F174B1ULL, 0x906C201909EF3018ULL, 
            0x49622F6553344629ULL, 0xD3040A2A98239AD1ULL, 0xD1913BD5432E6FAEULL, 0x6DDA1A03E65C755FULL, 
            0x236EE662096FD2EFULL, 0xA68C1BA76C3155DAULL, 0x5C8CA2BE579BB3C6ULL, 0xFADB51B406DABEE7ULL, 
            0xCD2002F8CD9E560CULL, 0xFECCB27C1202EA12ULL, 0x98B95F1075CD951AULL, 0xF20D6813D71838ADULL, 
            0xFC5926A06D7711AEULL, 0xAC196E9803B6BB65ULL, 0xCD88477689507F65ULL, 0x431407EE377B54C3ULL, 
            0xED3EE6C81742396FULL, 0x2441788BC46EF831ULL, 0x5D271EF6F91BD72AULL, 0x49D85A30BB48474CULL
        },
        {
            0x8622715E1261697EULL, 0x5CF45C961488B563ULL, 0x25D98725406DA4B9ULL, 0xF3CDBFEC326BF7D6ULL, 
            0x8EAE7C7DCC4A6174ULL, 0xB9229F8E146A8B42ULL, 0x577EE12A60FE22D0ULL, 0x7FEE64CA65D04E85ULL, 
            0x5B4F766D08C5C831ULL, 0xA5908FC07E54EDD8ULL, 0xCB5B64002C024BBEULL, 0xC7D3D933F4B018B8ULL, 
            0x3741E47F5C2BA751ULL, 0x5EE7B31719927183ULL, 0xA5310D3B2088E32FULL, 0xAF64F54854E0878BULL, 
            0x7F5A282C5FA392F6ULL, 0x83E345A9C6EA7F12ULL, 0x6C0D36A1E99064E3ULL, 0xA3C0A3033E92589EULL, 
            0x1E51685C663C9C0DULL, 0x33B8A44726C6B435ULL, 0x4E49A442F4739915ULL, 0x114BAE547A8B8830ULL, 
            0xF62A0C505EB90FE6ULL, 0x6BB56187053A3093ULL, 0xD0D0979165B4585CULL, 0xD965229518CFF976ULL, 
            0xF7C7A41BD36EA8C2ULL, 0x43491E00A92FE827ULL, 0xA5CFBA4BD71D7D79ULL, 0x302689100086DECFULL
        },
        {
            0x7FCD6936537ED410ULL, 0xF18281DEABC7E30CULL, 0x9B71BAD71327EF40ULL, 0x1EA4AC7D567E92B2ULL, 
            0xB496C67CBCD5A869ULL, 0x49883D4AE52F46D7ULL, 0x4484CA300D85CB60ULL, 0xA78CF117C336843DULL, 
            0x186045F790A239B7ULL, 0xAA70E728FCC0BCC3ULL, 0x7C19E1F74515F21DULL, 0x2AFCC66FA58AA4C4ULL, 
            0x10BA33EE0E46AD06ULL, 0x05FE976A98034493ULL, 0xD36703553E610C91ULL, 0x0EB55C68CEAF939BULL, 
            0xA77AE1C19C84499EULL, 0xDE8B448EEFC4FD60ULL, 0x2A199547EBDFF894ULL, 0xE957483C2F82BCECULL, 
            0x77D9A125B60E85DDULL, 0x221DC4325858BE20ULL, 0x9D1313CE5E71F7B2ULL, 0x17E5C56219545D19ULL, 
            0x3A1F72BD3604378FULL, 0x67184699054E94F6ULL, 0x6D2F01916B31C4E3ULL, 0x77B98E80E3724401ULL, 
            0x6EA24F922FA87564ULL, 0x90FF5DAD3CF01EE8ULL, 0x5E0167E55D760B79ULL, 0x4B2FBA2EAAAD9C62ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alnitak::kKeySpawnBConstants = {
    0x124E256E3A16BC07ULL,
    0x0CC2315ACA9A23B3ULL,
    0xAA3EA7811AD657F7ULL,
    0x124E256E3A16BC07ULL,
    0x0CC2315ACA9A23B3ULL,
    0xAA3EA7811AD657F7ULL,
    0xE61FB24BFC98CA83ULL,
    0x7D3C8800527506B5ULL,
    0x79,
    0x16,
    0xE5,
    0xB8,
    0xE9,
    0x8C,
    0x07,
    0xFF
};

const TwistDomainSaltSet TwistExpander_Alnitak::kSeedSalts = {
    {
        {
            0x03089CF7C2B4B85DULL, 0x9F9D11DDC60C5452ULL, 0x60FE9A96101006BEULL, 0x110532686C125F4EULL, 
            0x731CAF0EE69842C0ULL, 0xDD26D49F411DC096ULL, 0x5AD41BF38E8D43F7ULL, 0x2B3B619DB94394BEULL, 
            0x67E5DB06BF094F1AULL, 0x2D8604B57570B634ULL, 0x315157B59D1CD82AULL, 0xA02AE9E734D9E892ULL, 
            0x1F157834D38A5B98ULL, 0xD6F3D6A6240C546EULL, 0x7C2E1864796BE7CEULL, 0x02574278255188D1ULL, 
            0xBA6E50EA9E146610ULL, 0x40E2648C6E62D66AULL, 0x250CE945400C5827ULL, 0xA4456C2FB43AE6B7ULL, 
            0x027F11074BC0F08AULL, 0xEA5E9ED5F9B12768ULL, 0x07F1610CE630B2DBULL, 0xE0AF2196B94887BBULL, 
            0xE54B9BD096C53B6EULL, 0x2849AA86DF91CD19ULL, 0x65B1420906A54DA2ULL, 0x69E50E8A930E62A5ULL, 
            0x31FB29BD89056730ULL, 0x16E6CCD79252EEB1ULL, 0xC43881F652A59436ULL, 0xB6E36BEF3B239466ULL
        },
        {
            0x7AE6D9BD7D4941C9ULL, 0x6FD4BD0BF477ECD2ULL, 0xDE36592310777965ULL, 0xA0E7B57477D2E802ULL, 
            0x6F12C500BF7D6848ULL, 0x01494F941E88151BULL, 0xE324021C17C3DC00ULL, 0xD4F3562A02FDAFF8ULL, 
            0xEF4778DC89A018BCULL, 0x1EA70B4BA0046A91ULL, 0xC632221572A8F11EULL, 0xE8335EA30726B5B2ULL, 
            0x41C7C62069A638CBULL, 0x44FB5475EFB65A1FULL, 0x7B3F7750A3CD76C0ULL, 0x3A8152F51755BAFDULL, 
            0x3B8E66C659386CA7ULL, 0xE6D5EE98F528EDABULL, 0xAE3100AC26890583ULL, 0x7173784A079BA22DULL, 
            0x29DDA16D8C8ED3A4ULL, 0x7FB47864F416F51EULL, 0x9B8881B3B0EB3137ULL, 0xCA53758E03DDBD78ULL, 
            0x2EFD97C67AA1327EULL, 0x2492A7BB8718DE2EULL, 0xEA2D4F4630A88E4BULL, 0x7606D22221C1CD17ULL, 
            0x55AE498C8D9F4C68ULL, 0x0128692F3F724906ULL, 0x2CF6C0C090721521ULL, 0xC27A6279F809C2FFULL
        },
        {
            0xF72BC2D80AAFB3A9ULL, 0x3A69EA66AC27A2B7ULL, 0xF84C897ADE434AF3ULL, 0x1A46CA9D171D19DCULL, 
            0x7A8EC48050D21E9BULL, 0xE5C20C3B66019DF9ULL, 0x4E3EE43E8FF8325AULL, 0xD09AD89628344BB1ULL, 
            0x599F006EE8BCF933ULL, 0x141FF7C16276B233ULL, 0x3C661B09DD5DE0F6ULL, 0xFA7D0D3B9AD323A3ULL, 
            0x8580BFE894FED212ULL, 0xE29DD1DBF2020FF7ULL, 0xF8C4140500593DDFULL, 0x216DC41672EADF06ULL, 
            0x2A9AD212287987C9ULL, 0x6591EB9640516FC9ULL, 0x2CF6B91FA17D430DULL, 0x1652E5D2EF50E1ADULL, 
            0x6EC0800EE7B957C6ULL, 0x582F671CC4BB8913ULL, 0x958E04FF372EE07BULL, 0xD53D11B046E3DA06ULL, 
            0xADF37C025868B9D2ULL, 0xE3E92398977881B8ULL, 0x9BC78DDFBE2C55B2ULL, 0xA2D233D62A63897AULL, 
            0x87EAEDED2D897F1CULL, 0x2963BF8494042D11ULL, 0xB72C92F36BBD8BD1ULL, 0xBA030FCD11FD35A0ULL
        },
        {
            0x57574CB194A4FB6AULL, 0xD9F94638992DDF06ULL, 0x5ABE7DB2AACFDF55ULL, 0xF33F5A43D7F0DCA8ULL, 
            0xEFAA97FD4F114F9BULL, 0x7540D0EA962F15E2ULL, 0xD0199E49E2B7ADB6ULL, 0x4A0BB36638FAD2CBULL, 
            0xE64F1229D4C760ACULL, 0xBE2D2082ED24C7ABULL, 0x3270C21DED8270D9ULL, 0xE12F68648B08CB00ULL, 
            0x80E5AFE322222E43ULL, 0x2346F09F3B265AEFULL, 0xFC408CA01CB7D11BULL, 0xA30784F2879C3E66ULL, 
            0x938FF79F80484400ULL, 0xD01A613DD7649E9FULL, 0xF48960360A19E135ULL, 0x2E87CFAAF80D3E6FULL, 
            0xC3AC9D338575A115ULL, 0x64D25A18402CC87AULL, 0xE2FD1ED3D8CEA463ULL, 0xF2E9BBC6646E6AAFULL, 
            0xFF465D333525F1ADULL, 0x0084E5BF601D1594ULL, 0xD69489E6F328DBFDULL, 0xCF621356767EE0A0ULL, 
            0xF6E76C879A145A37ULL, 0xF1A99BA22A83CC2CULL, 0xDF8CF7C5D5EFE49FULL, 0x6183B07F57B653ACULL
        },
        {
            0x09EF9C3B2DA0548BULL, 0x0003E7EED94B0342ULL, 0x859D65BB3BB0B0BCULL, 0x4322890595919564ULL, 
            0x3904C83D41D812C6ULL, 0x268AFE3026EA4279ULL, 0xF22F31260FEB8467ULL, 0xD9E8D5EBFE441BD5ULL, 
            0x4DFB8D3969E44596ULL, 0x4DD62CCD5DFCFDA9ULL, 0x519DABB4B4427119ULL, 0x04FEE63949BCB7E3ULL, 
            0x16860A68B8FA86EBULL, 0x192B9ACD6DAD5453ULL, 0x64540FC630B9435AULL, 0xD2C42F1D73A0A73AULL, 
            0xE572F7CDFB684530ULL, 0xCC4C5DA8A8230D70ULL, 0x83CBF3E6701D3EDAULL, 0xF6F91C02640239A3ULL, 
            0xDE1E7D4861DA0C93ULL, 0x256BADEA1B9A6ED1ULL, 0x46A3B3D70841D3C0ULL, 0x276ADB49155774AFULL, 
            0x30EB2025906BA141ULL, 0x44B5D71C381F43ACULL, 0x681AFD1FBFB06C32ULL, 0x100B6377D8286A89ULL, 
            0x0E80FD6CE15F7215ULL, 0x67254AB238297D2DULL, 0x5804490E55EE8EB5ULL, 0x2DB32F437387AC8CULL
        },
        {
            0x3F3DF7B53594ED71ULL, 0xF85591074BE11A59ULL, 0xD8DD3A1CE40A3A1CULL, 0xE936B1B4E45F195BULL, 
            0x6D18F618A0A047ECULL, 0x80315ED750A27AE9ULL, 0x35B17EB3180F11B1ULL, 0x3402A65558EABB78ULL, 
            0xD17CD2E8CB279612ULL, 0x280FBABC27C5DC7EULL, 0xEEA1DF02350D881CULL, 0xB8242FB7ED33F20AULL, 
            0x11DBD1552D960A3FULL, 0xFB8A98E85202E33AULL, 0x1E25A1D9E21EAEAAULL, 0x25F59DC45E52F700ULL, 
            0xF0E6826DCD2A96F1ULL, 0x4A8E305C7B1849D4ULL, 0xBD8775760124598CULL, 0x151CA1B22B37F1D4ULL, 
            0x74259532ADDD2C77ULL, 0x93AC076944E54F08ULL, 0x83CAE5B1859E2B0BULL, 0x8B1DA5EDD9C6A81EULL, 
            0x23ACFFD1305DE6ECULL, 0xF3E145C79DEC4A91ULL, 0xA51DEEBDE7F1F6F0ULL, 0x259DDBA3E11088F1ULL, 
            0x4C374DB92F130EFEULL, 0xF77A90CEA27FFE13ULL, 0xF8259DF8A6E1D960ULL, 0x77870DEF90D3A2E9ULL
        }
    },
    {
        {
            0x6F01C3280F548843ULL, 0xABB3E3A58A6EEC04ULL, 0x56ADF5A329261840ULL, 0x76F42F5CBDD0C73FULL, 
            0x5F9145C359D7DC31ULL, 0xD4AF445B25ACBBB5ULL, 0x42B353719AD22EF9ULL, 0x6E99616B71A422B9ULL, 
            0x4E0D6FADD408F987ULL, 0x2294FAB95479BEA6ULL, 0x71B564B5705651B7ULL, 0xDB2B3DA72FD48BE9ULL, 
            0xBAEF1525349F9395ULL, 0xF9407061FCB7159AULL, 0x41E708CA36FE07F9ULL, 0x5D54E6648390CBEFULL, 
            0xF11C0B7FAD63B835ULL, 0x45D211A230A799D4ULL, 0x3EA3D9E659FC9419ULL, 0x3FC8CF28F39FC7EEULL, 
            0xE5FBFCC2EC1E8FE2ULL, 0x73040EA106BF3807ULL, 0x730BD34A981E70F7ULL, 0x73EED05491F08ABCULL, 
            0x29144E7BC255569CULL, 0x0ED133C29BA853ECULL, 0x080EAE207507AB5DULL, 0x9D523F75C36C1329ULL, 
            0x45C861177D7F9C4FULL, 0x76C4285F856D2DEAULL, 0x03805F2530E72444ULL, 0x40DC4F0968F19A40ULL
        },
        {
            0xDC5F813A6028F22BULL, 0x30BDCD50CD4D94C5ULL, 0x9C9E688CFC256840ULL, 0xDD1F741B4D63E8BCULL, 
            0x00713300833E9D62ULL, 0xC80D48146668131CULL, 0x684842477DE2C51EULL, 0x45E683B060993F89ULL, 
            0x5808C5421977AB91ULL, 0x2A32B25EA5B6121AULL, 0xDEC4B85F99D1CBF3ULL, 0x4D21C0806712367DULL, 
            0x24BBA3D81CBB22B1ULL, 0xD7CF3EA95AF172FCULL, 0xEEFD25BFC7B11218ULL, 0x624CAFA73286984CULL, 
            0x250B221951AEEBCFULL, 0xF01B548403D48044ULL, 0x20602E172DB248D3ULL, 0x6FE313F54755A51FULL, 
            0xC30FC9D1F50E3730ULL, 0xC1786353E739530EULL, 0x9C90A91E39B15C68ULL, 0x7E1EB640ED241C28ULL, 
            0x4BC9B1BE1D3F6FB7ULL, 0xC3159A66A9173715ULL, 0xEB689C1A810FF20FULL, 0xD83A2CAC4E90B3C4ULL, 
            0x42A292EA762269FFULL, 0x39837C686279F8B8ULL, 0x77E337D4CA5C3445ULL, 0xEE10E8786F490359ULL
        },
        {
            0x8FF3DF9004F8FA05ULL, 0x6971439501C83100ULL, 0x12D173F1B6B200BBULL, 0x33B5040780C4D91CULL, 
            0x5E9ED66F0A24C909ULL, 0x140C7C307AEBCDACULL, 0xDC70DE5C10CFCB26ULL, 0x5B8BE7A01C3686F9ULL, 
            0xE280F5A1DEF2C9E6ULL, 0x7EC4A8F2B4F925A8ULL, 0xBE2B71159F956D07ULL, 0x4E7DF2D14F22AF2BULL, 
            0xF94D30674703B616ULL, 0x12ABD2D490497349ULL, 0x7740DB7CC9D9B5BEULL, 0x5D4C2B8341C5B9EEULL, 
            0x7C0013257E395025ULL, 0x707E53D46BD54FC8ULL, 0x3F3CC6E0EE6F32FBULL, 0x9A075167E97D661EULL, 
            0xE9F50FA726CBBF04ULL, 0x62C992E85026C8F7ULL, 0x2D7969A9E9EC5C9EULL, 0x261B12858B53B49AULL, 
            0xC762743EB5CF7D68ULL, 0x44F6A7647B2FAD0EULL, 0xC45AC220F35F3D7BULL, 0x0284E969E3A6D9D1ULL, 
            0x9E46702DCE79587CULL, 0xABDD3049CC525D55ULL, 0xFE45B88B409F1096ULL, 0xB7BEB8BBB329B0A6ULL
        },
        {
            0x2CD1A04560FDA962ULL, 0x699957486814617EULL, 0xFEA6FC0D4D252079ULL, 0xEE1497654325F6B2ULL, 
            0x861582648423386AULL, 0xB985EB704F869CDAULL, 0xCEA1E09CB0C58846ULL, 0x5E48259A62AE6701ULL, 
            0xFA4AE718E37538CCULL, 0x33C98CA1EEAB5836ULL, 0x9841454EE27C7A83ULL, 0x961DD8E68375594CULL, 
            0xEDBAC83579C78823ULL, 0xFCB992235B93A18CULL, 0x918DA802D1420859ULL, 0xBF41E3A5275FB327ULL, 
            0xC37C40DA829EFDE7ULL, 0x899A701BC67CB4D7ULL, 0x44FEB30B4A704356ULL, 0xB4A7909FCF40F495ULL, 
            0x0C809B3E5C2B8C08ULL, 0x52674D997DA028AAULL, 0x10561726187E18FBULL, 0x0985EE1F7A196A73ULL, 
            0xF8EE687577775898ULL, 0xE9022944849D2113ULL, 0xA55CB6DDA7105251ULL, 0xA7B2FD5E3E468ED0ULL, 
            0x087F9A6F2B5B879CULL, 0xDBCF825EE98AF67EULL, 0xE8D6773671101149ULL, 0x13B261C0EEBA1506ULL
        },
        {
            0xF496CBDDF35285AEULL, 0x180DD8CA7B796EA7ULL, 0xE3231C9A64502A0FULL, 0xCF31D5F968BEABF0ULL, 
            0xE37E92861C743520ULL, 0xC6BEA3CA382674A5ULL, 0x6DCD36436F8CB223ULL, 0x193F196F3E995F5CULL, 
            0xBD3D5ADE79EB900EULL, 0x01A3423AA473F5B8ULL, 0xFF480F1BA615DC03ULL, 0xDCE37A163BD39AB4ULL, 
            0xE63930CF4922E2F3ULL, 0xA292C75E583B4B82ULL, 0xAE845A8EBA39EE2CULL, 0x16DD7498DDCF7FB3ULL, 
            0xCF146B9C02C6DE6DULL, 0x6CA84D465D1D634BULL, 0xEC1BC973C02998A5ULL, 0x47BD61379CB9C16CULL, 
            0x64BE9F4325C7B52FULL, 0x9F0767A9ACABAA65ULL, 0x4C46E45108D32A10ULL, 0xC06937D1120A9D1EULL, 
            0xCE932ACC0769AB32ULL, 0x3142D67C3B7D4E49ULL, 0xC069DEA3AEA96180ULL, 0x600B8A36694CEC66ULL, 
            0x70C04DDCBAEB7A9EULL, 0x3131380BE5A2D9B3ULL, 0xF88EFBB1F85B11C8ULL, 0xEA8D4A71E04F47A7ULL
        },
        {
            0xA8B3F1259C1FC9D9ULL, 0x4A6FEC9DCB86A95DULL, 0x321E1B159F4CFFE0ULL, 0xDC3A31C517269FAFULL, 
            0x4A14FAEB052ADEF9ULL, 0x9DAF70B4719DA204ULL, 0x04333C43A76EAB73ULL, 0xA368ADD8C77B7BE8ULL, 
            0xCBFF848B9DFDF4EAULL, 0xCA2DD8EC62DB7BF0ULL, 0x81EF33B21DF4EB26ULL, 0x5A3FC4217576C9E5ULL, 
            0xC9A8FC40CC3CD046ULL, 0xE79CE523ACA7348DULL, 0x2EB441A9EDF68F1CULL, 0x50A6084EE979AEF7ULL, 
            0x57D407A36395A041ULL, 0x7F3F3B772BC5C59DULL, 0xA114261ACE352684ULL, 0x01B73E363D233E8BULL, 
            0xAFAF5879A868A546ULL, 0xB86793A94FFA96FCULL, 0x30889D6035280961ULL, 0x6130737B99CB52A4ULL, 
            0xC693FFBC536822DCULL, 0x6F808B2DBF1709B7ULL, 0x7D12A82F567F0D4CULL, 0x7A0A467414697C6CULL, 
            0xD5B2D6B24E2C8969ULL, 0x92D1BFFD39B8FAF1ULL, 0x43A781C3636D1AA5ULL, 0xD50C4CC22B6256C1ULL
        }
    },
    {
        {
            0xCCA5372E646B0680ULL, 0xD8528FB89C4405AEULL, 0xA9E52A3AF61F5298ULL, 0xBDAAC261BCB265D7ULL, 
            0xAF44FBF6C51D7D66ULL, 0xD55B0C12FBF68481ULL, 0x0C034F0A541E8892ULL, 0x8B4B6A2A5459C8FEULL, 
            0xCB3D9E9189787D92ULL, 0xECD8CFFE9CDA8465ULL, 0x38288017BCE0085FULL, 0x8D43C02B4BFBCE1DULL, 
            0x69062EB9E6BB8030ULL, 0xD00BDEAC9209E308ULL, 0xFB0344EA4B4589F8ULL, 0x399641381EF12AC7ULL, 
            0xA8C8172E40273B81ULL, 0x38F1477E54F7094DULL, 0x0A370A44FF005220ULL, 0x0B1F47232247449DULL, 
            0xE596D19E0F60A06AULL, 0xC2B8830FE982365BULL, 0x9E65A4D29E4E4963ULL, 0x6BAF2E1EA98F5FC8ULL, 
            0x11290E00A8C65B38ULL, 0xCA45EDDC483BE391ULL, 0x6E23629F034544A1ULL, 0xB3731C10FDF44B57ULL, 
            0x256C933233A1CCC9ULL, 0xC9AAC9B3C1AB6988ULL, 0xCC60EE001EF5E511ULL, 0x5168BB10D5FC579CULL
        },
        {
            0x97190C8E97BDF608ULL, 0x5BE06D296A66B7BBULL, 0xE07A7422265E87A0ULL, 0x0BC21657FFB6D4C2ULL, 
            0x1BF3EAAE9435D123ULL, 0x757912C95BB9C98FULL, 0x237FC65C91E2B9A0ULL, 0xDC3F8448F094379DULL, 
            0x91674614DD7B7C06ULL, 0x52676F9F80E991BEULL, 0x36D293511D5A63D2ULL, 0xB5A23141F69E9572ULL, 
            0x2E2581A2D29BEA03ULL, 0xD3E6A8D6B1558FB6ULL, 0x60D2068FEE557216ULL, 0x8DDE237421856585ULL, 
            0x80BBF0C01477830DULL, 0xB0D051174FE292F6ULL, 0xD1C18F79A1EDE9B6ULL, 0x7DDC4FFBCC08F7AAULL, 
            0xEE3FA8AE694A025EULL, 0xB224530BF517BF00ULL, 0x8091F7EF63C68756ULL, 0xAC01422E21AB0D99ULL, 
            0x347F8AE255DAF351ULL, 0xE81883CCDACFE9BDULL, 0xAB7EB977AAED8BBCULL, 0x6B9B2EDD042013B0ULL, 
            0xACD472502F0538BBULL, 0x458BF67664986549ULL, 0x008F1176D25BAC12ULL, 0x1FF8BCAFE2EFA9E0ULL
        },
        {
            0xC28A5A1887F6558EULL, 0xFE9D2BB417801AEDULL, 0x17E508F102074C67ULL, 0xD1ED0234C82E1E40ULL, 
            0x69451C174A3C23FAULL, 0xF894D9614682BD17ULL, 0x7E2D2759BD77B345ULL, 0x5325F1AAEEAA91E1ULL, 
            0x32BE0F768BA1CDB2ULL, 0x9DF3AF105E603DB1ULL, 0xB8E3A30953122D61ULL, 0x0F2B6C2651AB10E4ULL, 
            0xEF6717E722C88EF3ULL, 0x604093AB336EE674ULL, 0x2CBA2DB4118A3FE3ULL, 0xC43B68C9CA2FA35CULL, 
            0x8364A1E631EA2DDCULL, 0x930ABD11C19DF32DULL, 0xB2DA9205531E3424ULL, 0x5E6F05E1C23F9793ULL, 
            0x8C309CE1A446B1C6ULL, 0xE7E5D74EBBC9A160ULL, 0x0E8764E9B3EDF1BCULL, 0xA8AB00107D60A48DULL, 
            0x36EAAFB1539A1B28ULL, 0xE55F8AF213BDAC9AULL, 0xF01CA634646304E3ULL, 0x9EA2F642D2EFFCA6ULL, 
            0x3B6DF0E5D905ABC0ULL, 0x2FE5925483D6FCE1ULL, 0x2036F4C0D3C05519ULL, 0xDB84E63EDCCB29D8ULL
        },
        {
            0xFD9BE9A604B73FFBULL, 0xA302D9C70B3E3750ULL, 0xF1C48A6A0746FD76ULL, 0xC63D880028903537ULL, 
            0xCFB16DAF02275252ULL, 0x0E0D00908C12F1CFULL, 0x6675CDE6EECAEE8BULL, 0x8D5030210C2D8CBFULL, 
            0x2A34E39FD119D9B9ULL, 0xA76C54F1BE438447ULL, 0xE666800E3DECE854ULL, 0x5BFE77CAAE4C5E0FULL, 
            0x8A4598DB5F99BB6FULL, 0x75E3CCF9A6424D01ULL, 0xFF7E28C3C85C0F96ULL, 0xC6740AC0493755DBULL, 
            0xED4AC5F39263D4CDULL, 0x87A8A912AE0E4BF7ULL, 0xBD55F3F4ED29A68BULL, 0xB0A1E74630E7144AULL, 
            0x8A5233D8E44B6979ULL, 0x00331E5B53DB6310ULL, 0x8567DEAE7240C3D7ULL, 0xC379D3FB9AA03C43ULL, 
            0x142E05CEF69B9E9BULL, 0x01C2747A70194DA6ULL, 0xA0EF09D6E99E1414ULL, 0xEBEB492C1CD92368ULL, 
            0x3D627CA44EDE09B2ULL, 0x3994D9E7C4D1FCD8ULL, 0xC1F48C0915992303ULL, 0x09D6EC7689FD2E76ULL
        },
        {
            0x54D6C4B0D41DEFD3ULL, 0xFB26B3B71B8098EDULL, 0x6CABD288C396B5C9ULL, 0xB82C13F9F7DEDB3DULL, 
            0x66F835976E436BF8ULL, 0x17366ACED9A17698ULL, 0xE7A49C85ADD452E4ULL, 0x928BBB6998FB1CE5ULL, 
            0x20700C22298CF978ULL, 0x3F29C90CBEC026FAULL, 0x37442E8474227452ULL, 0x10FABB7BD7C4877BULL, 
            0xB1BAE190BAED6DFFULL, 0x06B25186299D69DCULL, 0xC96CD3060D47C779ULL, 0xBFAEAAD63E8583C7ULL, 
            0x541C0E46388774C1ULL, 0xE85FD30F6CAA8DB2ULL, 0x2D12D7B9782C370BULL, 0x5F377307C5DDFF67ULL, 
            0x0E789664DF855AC7ULL, 0xCC65BF4AB048FB67ULL, 0x9EF6375DEFCDEF26ULL, 0xF1D08EB693CFF3E2ULL, 
            0xB51109C865A6426BULL, 0x3FA390FE4A965AFCULL, 0x8808C1E8706350CAULL, 0xEA31AD91982DC3C2ULL, 
            0x22CAF3CBAC98E630ULL, 0x046428AC7E6445FBULL, 0xA0C0762016F81A68ULL, 0x9CBEF59DB4EE21FFULL
        },
        {
            0x36F4F5360DA8C345ULL, 0x8921ED65C68EC079ULL, 0xEAE6D701CBA3A894ULL, 0x286D5733A5351B63ULL, 
            0xFF50D0C776621567ULL, 0x513C21058F2AC366ULL, 0x702F724BFFA197EDULL, 0xDFA0EBEF7D519116ULL, 
            0x720452595EBF1217ULL, 0x12C34DD8B87C7820ULL, 0xE472230BF38640F0ULL, 0x8FD3233E9ED0B075ULL, 
            0x89E8D8CBDBBCD16FULL, 0xC4304152B03D46ABULL, 0xD83C7FCE5B0FE573ULL, 0x644075BE7E8E6D62ULL, 
            0x2A11907100CDEB27ULL, 0x22E70F758CE25A1FULL, 0x3C2E759537EFA56DULL, 0xD2DBE13772F4CD9FULL, 
            0xBEA71927FA748B20ULL, 0x4351760325CDAD6FULL, 0x2D43066EE032397AULL, 0xFD8B083E29FCE747ULL, 
            0x3B769340CC64BB70ULL, 0x481DD7C2B394A969ULL, 0x5F2A6130DE19AFCEULL, 0xED68C04E9E0BAC5CULL, 
            0xA36A28E54B8102D8ULL, 0x94CA1DDE08ED590CULL, 0x3D616D6CA31F97E2ULL, 0xF43A4273A5092CE7ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alnitak::kSeedConstants = {
    0xFC1F866D303B1B3BULL,
    0xBD29D7344A4892DCULL,
    0xDAF56448D8772E51ULL,
    0xFC1F866D303B1B3BULL,
    0xBD29D7344A4892DCULL,
    0xDAF56448D8772E51ULL,
    0xAFE37D32241C997FULL,
    0x775E7955B9B1400BULL,
    0x2B,
    0x4A,
    0xDA,
    0xBD,
    0xBF,
    0x68,
    0x5D,
    0x83
};

const TwistDomainSaltSet TwistExpander_Alnitak::kTwistSalts = {
    {
        {
            0x2B6EBD02D7D9B067ULL, 0xA75EBF6318754E86ULL, 0xD1B4FE9F523BED9EULL, 0x62F4BA63CA81853CULL, 
            0xC935B74F1704FF2AULL, 0x154C180B0665FC50ULL, 0x12A06772A0219192ULL, 0x5B7E1F4F3AF49FA3ULL, 
            0x2EC57E51AB7D2B85ULL, 0xEEEC97D6E0F11F47ULL, 0x71D7340DF1BBB230ULL, 0xBDAEEED2FE314B57ULL, 
            0x7455630BB5BC2D19ULL, 0x09CF7AF34FA30593ULL, 0x1906227AE9E4E60DULL, 0x927087C6A9E5EC5FULL, 
            0x3F8AEB16348DE2DFULL, 0xF3F7F2B8EB85E295ULL, 0xF3C28FD6A4AB343AULL, 0xBFDE02C4393FB650ULL, 
            0x5AC2A3EC96654240ULL, 0x557A84B61A578114ULL, 0x456C3E6182D2ED5DULL, 0x1B5F00E97CF98102ULL, 
            0xC53CAE63803D9AE0ULL, 0xFCE9BB713D8187CEULL, 0x924D5D2D8BFF26D7ULL, 0x68FB2A3247801D50ULL, 
            0xD9BEECBBA74F3F9CULL, 0x5CF236165415592FULL, 0x59883A82D342208DULL, 0x151E98330E96FC0BULL
        },
        {
            0x844FA2415DD51D65ULL, 0x7A7FA0E340E64974ULL, 0xD4BB6F68E5C3C0ECULL, 0xFDCA4877EA28B0B3ULL, 
            0x62189E96E0B2DE24ULL, 0x548DE7E916283811ULL, 0x2BAB7AB25319B69AULL, 0x0F7681BE7CAE7A46ULL, 
            0x6DB1B5029145E60BULL, 0x8FFB37628A76580DULL, 0x62F7305AB93A8FB4ULL, 0x28E22D7791F6BF63ULL, 
            0x032238A1B58E5940ULL, 0x9D0598225C9D9BF0ULL, 0x0880EE25E1B9BF3AULL, 0x5CBF15E4C752EE56ULL, 
            0x7F04C465FF359183ULL, 0x05A452CF0DEB53D9ULL, 0x2C61668CFC7902D2ULL, 0x4FBF858A94A4D119ULL, 
            0xEAAECA537FC8EED5ULL, 0xE6CE221F310F0397ULL, 0xD3B359AC583D12C9ULL, 0xAEAB0FA324C99E1BULL, 
            0x8325E6225A45376BULL, 0x7A87352695B69CA8ULL, 0x50771E31EED3326DULL, 0xD7DAE59551417165ULL, 
            0x789774FB401CB5F6ULL, 0xDD691AC7B796012AULL, 0x15F6A7704754C2C9ULL, 0xE663DA7A07FB00C5ULL
        },
        {
            0xBDBD884987A5A1B2ULL, 0x5DE6271465BD1067ULL, 0x9286AAF3F9232823ULL, 0xA949FE0832750534ULL, 
            0x0D2541E03C3FE99AULL, 0x6EC2C77C89004515ULL, 0xDED62A51F6382183ULL, 0x34572E2BAA9B273AULL, 
            0x6E3A8B40141E9216ULL, 0x98F20BC640142513ULL, 0x2E8E4CDB9283FDDBULL, 0x939B4276B99F7267ULL, 
            0xD4CBA9CE04C3805EULL, 0xEC1608F86CDA268DULL, 0xA567A78FAA037122ULL, 0xEB774ACB6439567CULL, 
            0x0A47E34B1103B193ULL, 0x8726C493416ACA75ULL, 0x549451555C198905ULL, 0xC269CF6B32025931ULL, 
            0x3EF6E09C81899DDBULL, 0xEE33D23C14619B0CULL, 0x3C52CAD6AA604EC7ULL, 0xBB58919BF8F79C12ULL, 
            0x56C75C8732FAF586ULL, 0xADC55B0AA4F3DD04ULL, 0x5A65C7C280C37C76ULL, 0xC286859B689C6405ULL, 
            0x45F4F10135645AFDULL, 0x08FEB0A96DD3E69AULL, 0x2FCEAB3AD4575D0CULL, 0x30A3A957CE0E6542ULL
        },
        {
            0x2519B0FC7DCBBAF4ULL, 0x73D9EE51FEAF37D7ULL, 0x10BF0B9A8169F98DULL, 0xA288E919525042BFULL, 
            0xD5B0814D9E74F4C4ULL, 0x3B6A97056E049B02ULL, 0x56DC1162705493BAULL, 0x5E0270DE9F2B7338ULL, 
            0xD21BF9F57F6874F1ULL, 0x746AA825FAB66046ULL, 0x29EB1728BA7B0DF1ULL, 0x4EE40A4A94EDC3DAULL, 
            0x603B633BF7E8F2F2ULL, 0xE4C96D95E6556F24ULL, 0xFDDBFFD7F9466CA2ULL, 0x40A476A34EF52353ULL, 
            0x216923B40AFF7EB7ULL, 0x0F575D3326790764ULL, 0x2C14719181F7148BULL, 0x949C4AE04CBDD1D2ULL, 
            0x7A2339BBAFEFEB7BULL, 0x464553300CCE103CULL, 0x70118E518DD8F2F5ULL, 0x49E0ED35EB525556ULL, 
            0x3283962F31458871ULL, 0x60EAE8F5CCDA9F39ULL, 0xB4982E13B7D052F3ULL, 0x71E0EFEC2DEB7330ULL, 
            0x7FF8F17EB50765CFULL, 0x9CF5294B2956B7B9ULL, 0x1D2A222FE74EE622ULL, 0xFAE2826B889A4CDEULL
        },
        {
            0xC5D91E7FCA69514EULL, 0x77B7107849560662ULL, 0x8CC3405091664F76ULL, 0x9A63C2D7AA442396ULL, 
            0x9A9A11939792E55CULL, 0x220C9C25998810C6ULL, 0x89066E692A19DEADULL, 0x677DD721832E6497ULL, 
            0x9961E5B7F0C341C8ULL, 0x27D4C24191393637ULL, 0x15687804BDEF2331ULL, 0xA7D60D0A359228E3ULL, 
            0x7FA5706FB6AC25FFULL, 0xE92C84C2EED97C84ULL, 0x7563D1E6E9D69C2DULL, 0x8BCE8C74AA48326CULL, 
            0xCCEA1D43168AF659ULL, 0xE2732C90CBC7DE7EULL, 0x49C9FBFDEF686CE8ULL, 0x88D5F4D61C52565FULL, 
            0xAA9EA45C87BD8E47ULL, 0xF30C81CAB7D91D26ULL, 0xF5CE1C4F9C870652ULL, 0x28F3711EEF9F9D68ULL, 
            0xD9F07027F798ED5AULL, 0x83FE78A7254CCD71ULL, 0xC85FB99FF544048EULL, 0x883D925DE790EBF4ULL, 
            0xD43C8A22061453EFULL, 0xF25798CAB9B21599ULL, 0xD5807DB347D003A8ULL, 0x3F6799F0538F8387ULL
        },
        {
            0xFF93B038601ABB2BULL, 0x426D73E526D0736CULL, 0x27730CC83B9DBFD0ULL, 0xFF28764A63BDE711ULL, 
            0x8E4A4CC63E7D54C1ULL, 0xADD3163497010CE8ULL, 0xCAD5E985BEEB3EE5ULL, 0xF4C6B333FDF8A8F3ULL, 
            0xFFC917C27A407298ULL, 0xEFC9BDBBB86F7BDEULL, 0xBAFB34E3A02350FCULL, 0xA8ECB782D12B4E0EULL, 
            0x228D3217822CFAB8ULL, 0x95F054E4AFD90A1AULL, 0x1E846074D60E2797ULL, 0xD015690E9E2BBF82ULL, 
            0x49792F1C3BB6DB7CULL, 0xFB66AB6C5565CE45ULL, 0x66EB6EB9A35B9140ULL, 0x626FBAAFD5ACFAC8ULL, 
            0xD22317FAE6383E8FULL, 0xD52BCBDCCF969B1BULL, 0xC87A2DB293A3E953ULL, 0xDDDDAE453DAF6A9CULL, 
            0x182320D9152068DFULL, 0xBCA4403A341FF327ULL, 0x96054D25C4CB393CULL, 0x780700375BB09B5FULL, 
            0x67EDC9451DDC90B2ULL, 0x9E2E2172225D626DULL, 0x6FE0A3FBB62E1AF5ULL, 0x1661E10B13367F35ULL
        }
    },
    {
        {
            0x9182703C620304E8ULL, 0xD2850692639FB964ULL, 0xFF7A578A9EE9A517ULL, 0x0146CF81CC539940ULL, 
            0x6FFB187DF3CF5C15ULL, 0x09674B263144D665ULL, 0x0FAA772CA7AC29B8ULL, 0x2F21E1F6DB548EC0ULL, 
            0x7EA37E317FAC2334ULL, 0x199292A4ACC416F9ULL, 0x16045DBB6AFBC9AEULL, 0xBDF32DE6C8B5F45DULL, 
            0x87CA1554EEAD234CULL, 0xFDE3536848667A8EULL, 0x43CA8A781A4D334BULL, 0x32C05F0A4949C8F1ULL, 
            0xAD9AE84CDE55002FULL, 0x047990D6EE124EC0ULL, 0x42364CE08222073EULL, 0xDAC9208111AF46BCULL, 
            0xC6549DEF0E94FAB3ULL, 0x6E7050F19DEAD7B2ULL, 0xC1B5B6A8069CE199ULL, 0xEC2CEA3D47C472C2ULL, 
            0x74F5428973C306CEULL, 0xE470A9B6389014DBULL, 0xD23B161AA2EAF0EEULL, 0x2703FF728256AF2FULL, 
            0x36245091FFB35D65ULL, 0xCECDE1A25E5C1E06ULL, 0x6A8D9D9B34E22CDCULL, 0xE10595C5A764FBB3ULL
        },
        {
            0x6DEB33F8F683323CULL, 0x1DA01A6562331522ULL, 0xE91932F04CDB4548ULL, 0xB327B7B4804A2699ULL, 
            0x79C3A16B0E855FA3ULL, 0x818953CDB6E0D674ULL, 0x2FB4F2254A7AF889ULL, 0x7E39E2BEDF2CC640ULL, 
            0xBE0C9C3DE936BF36ULL, 0x56334495F11D554AULL, 0x11D7FDE82121D397ULL, 0x9CA543DC2A3F8C0DULL, 
            0xB007FFBB58CDC786ULL, 0xE5300AB9C36DA712ULL, 0x9BE227076635EDAAULL, 0x42A65AB4F2CFD8D7ULL, 
            0x646D636C2677F7BCULL, 0x4E3F71BEB9AD28DBULL, 0x0A9DB06682880E79ULL, 0xB1298FA45071BD06ULL, 
            0x5696CEB14882A5FAULL, 0x13AECBBA1CA10C58ULL, 0xAD4D3E6981CEF456ULL, 0x1904172D84F3EB8BULL, 
            0x4E543AA570216C2AULL, 0x1181DBF17057AF7CULL, 0x2469A578EB511096ULL, 0x144182B0D9E7A088ULL, 
            0x15E45CE26343FE30ULL, 0x73A59E22B0C9F986ULL, 0xA18A3ED90FF20117ULL, 0xBE76571F5CBBA152ULL
        },
        {
            0xC8D03218C8B4D4CBULL, 0xE26BB88D84F08BA3ULL, 0x76CEEB3161B272E7ULL, 0x0017F4B1369A0344ULL, 
            0xE2C322211F6A7EBEULL, 0x42C68392518A5575ULL, 0xAB9BCC5F7E2D87F6ULL, 0xCBDB38745ACB59B1ULL, 
            0x13171FF98ED903ADULL, 0x8CC8BC2B746F5092ULL, 0x0EDEABFD666F13C8ULL, 0x3BE136DAD982B99FULL, 
            0xB8FFE40DE9326C46ULL, 0xD04E71B6B4DAA2F3ULL, 0x919CCE433895FB7FULL, 0x9ADA509104044FB0ULL, 
            0x264FA9C5295D860EULL, 0x406C0A49BF30819CULL, 0x1208D6E35CD6489CULL, 0xE6F2F97A1813D6AAULL, 
            0x279D86070A63E9C6ULL, 0x4A9CCEC8B818A3A5ULL, 0xCF986DFCA271C21AULL, 0xEA17620CC3645A27ULL, 
            0xAA432C31FD9AE466ULL, 0x15943ECDC8ACDCE8ULL, 0xC76D260D30FEA844ULL, 0xE592DE611156D611ULL, 
            0x9672EE58E471E712ULL, 0x468400D6204A95DCULL, 0x5833B9A1B513B0A3ULL, 0xA4BBCDCD1F1019F8ULL
        },
        {
            0x9AE1A3565F78B846ULL, 0x3FAACACCC1FD6BB8ULL, 0xDD934C955C5B3836ULL, 0xF848F22EABB8AD70ULL, 
            0x3457A241DEC7CED5ULL, 0x9731DB82756F931DULL, 0x91AFA16B932616B7ULL, 0xA8E9586563E7B144ULL, 
            0x52C2AA1F7B755974ULL, 0xE33A80BEC76587C4ULL, 0x71A6037A81AA8D17ULL, 0x2459409BD134736AULL, 
            0x43DC366A98D1AD28ULL, 0x7FEDB9C3D244CAC2ULL, 0x6747DC030F6AF290ULL, 0xAB11FFB01BE1E07BULL, 
            0xE08451A832C44C43ULL, 0x049D0329DA81B73AULL, 0xD2870E04B037F9ADULL, 0x6C948DF67811B458ULL, 
            0x2C0B73F6FA8434B2ULL, 0x503CB06EE3AE602AULL, 0x614554AD6DE3FE0CULL, 0xCC8775501BAAC491ULL, 
            0x3542F22CE33CB5DEULL, 0x36D9705340CA0C86ULL, 0x2E494733032CFFFFULL, 0x0B9DFF7818A8A78DULL, 
            0xB868A1945D53C61BULL, 0x8948F655E0777B38ULL, 0x5DA8103B07FDBEB9ULL, 0x67D0EFF12FC42AFCULL
        },
        {
            0x02AD11CF096B87A3ULL, 0xC4F2479DBA8AD68DULL, 0x9E08860F4D9C89D6ULL, 0x456C1CFF548DD565ULL, 
            0xDE6A7B00E8F7CC51ULL, 0xECF7BD27D342AAF4ULL, 0x5E5CE1B033C58794ULL, 0xE109D315A06B3636ULL, 
            0x88EA2EAD257696B9ULL, 0xE25EE5CC277AA264ULL, 0xD7E0B3B20C30B5C1ULL, 0xC642B49686701B7CULL, 
            0x8133984F1659D74DULL, 0xA112DE39C8F75620ULL, 0xBE3DC93833497F0DULL, 0xE8A3AD689D93DC80ULL, 
            0xB4C95DF30FA68671ULL, 0x1EF6A54EA396E3DAULL, 0x0C672B24D539DC14ULL, 0x6936EC131FC14450ULL, 
            0x6E7760B469E706A2ULL, 0x06350E8CEE2073C0ULL, 0x990D744E0FB99420ULL, 0xD697F006E0E89FE9ULL, 
            0xBD17ABEC0EE0D595ULL, 0x677560803510E39BULL, 0xD0ECEB7F761B06BDULL, 0x6FE1B1F8D2E52AB8ULL, 
            0xD8D21C15A5476251ULL, 0x45E440E407C6DF87ULL, 0x0F8FD4E2EBDADD74ULL, 0x766952B4E9F2395EULL
        },
        {
            0x2EA6C78F00F6DCE6ULL, 0xE32C208C9747864DULL, 0x20902C371BF5F15FULL, 0x5CD9D2EC42224DBDULL, 
            0x22373596B9EEBD71ULL, 0x45B34852BB9328B5ULL, 0x7CAB98F5A2D19692ULL, 0x847150D7BE259A48ULL, 
            0xAFA157B1D19ADEE9ULL, 0x366AC668384ADBD9ULL, 0x635ACFD6C06428AEULL, 0x97D89AEE6282C8ECULL, 
            0x14B766F0C62799F2ULL, 0x63AF33B37A2D03C5ULL, 0x5AB1824B60687D00ULL, 0xFE81858130CC6ADDULL, 
            0x2F2F2CFDB41ACB27ULL, 0x479EB97ED93974BFULL, 0x7C7859E88FF6AC9DULL, 0x924D0CC2951AF357ULL, 
            0xB7BA64F40B79B3A4ULL, 0x2A782F8BC123FF14ULL, 0x0DC7209D902A2C4AULL, 0xC24E00E97D38FE46ULL, 
            0xCB7BFEBF9787BB63ULL, 0xE6A90BC793E2F114ULL, 0xE01E2B4B9FEA3539ULL, 0xE813507869DE54A6ULL, 
            0x031F419B89A53674ULL, 0x254D199A38881DB4ULL, 0x0224295699EA4D49ULL, 0x03B9F5DDE246AAF1ULL
        }
    },
    {
        {
            0x52B411483ED5C9ADULL, 0xBDBA2D0172DC28F8ULL, 0x8EEE1772572F24FAULL, 0x25028C194B37107CULL, 
            0xA5D155FD7DE4CBBBULL, 0xAA2B7C8C45149DAEULL, 0xE52160356FE6DD5CULL, 0xDB617F4722C740B5ULL, 
            0x4C88CE280A3FF30FULL, 0x709E44611DC4781CULL, 0x79FDFFD3B700FE2BULL, 0x083C1A26830E3AD6ULL, 
            0x02969AA293BEBD1FULL, 0x8DCEE67DA1224B18ULL, 0x4135E0803997A813ULL, 0x77C9A31214B3F683ULL, 
            0x5F8FF544558AED6EULL, 0xC307A37122027272ULL, 0x27BFFEE51B73DE04ULL, 0x83484A92F851F4FAULL, 
            0xF0D400B744A0A35FULL, 0x6FCA740FEB77B29EULL, 0x79ADBEE21AE6E397ULL, 0xA36796DEF031F29BULL, 
            0xB675FF66D4EF4D47ULL, 0x3B76ED6FD1070D2DULL, 0x4762E04F4C6746E3ULL, 0x93F092C71FC3920EULL, 
            0x7801F4FE516B6A88ULL, 0xFF00AB214FE420A6ULL, 0xBC9A77CEE738CDDDULL, 0x329BC0EEB605E301ULL
        },
        {
            0x64816A4F24689C71ULL, 0x4B34E91620A6009BULL, 0x7C8E31DAE382A64FULL, 0xCAD4C93A71C3AEDFULL, 
            0xF5085569DE953F75ULL, 0xB93B26E345D711DCULL, 0x45B11BDBCE5963EFULL, 0xC5A781B0B6AF7822ULL, 
            0xE6F0738EC1C749FCULL, 0x4981880E71232599ULL, 0x5AE559EAFC34EB98ULL, 0xBCE52518B13B4C4DULL, 
            0xB1D20235D60E8E36ULL, 0x27B47CB7D119AB4DULL, 0xBFB2B4EFDE6DF8F8ULL, 0xD0665AED89BC9DAEULL, 
            0xFFC11D4478F8619DULL, 0x4B91052DD99EBE0DULL, 0xA3A6321EA4867F69ULL, 0xB673B73974AA05D3ULL, 
            0x3F95A06645E6EB27ULL, 0xD8E24650226D41CBULL, 0xDFF999C4693572C4ULL, 0xDF48C64E02E13582ULL, 
            0x8F30EA2A12F9862EULL, 0x4EEA7F579644AB24ULL, 0x10D9B7C5B8DEAE43ULL, 0x03200AC3720CD935ULL, 
            0xF75BDBA10A2DF0F1ULL, 0x1F01AE3453465EE0ULL, 0x4E2194C3F34A46E9ULL, 0xDE7B881619528F4AULL
        },
        {
            0x81CDED7485B9B8C8ULL, 0x499BE39175BE65F1ULL, 0xCD99F36452E2DE17ULL, 0xD5C8453ED78D640DULL, 
            0x7E209274F406EB65ULL, 0x37AA877DB8382C46ULL, 0x7A138C1DD31D1A09ULL, 0x9C6B030014D1AB0FULL, 
            0x3D8971BAC5E9049CULL, 0x41F7B4BA14E26FE8ULL, 0x7981786EC6D47D68ULL, 0xF3301C42F28D8E24ULL, 
            0x061FFD5344DFC573ULL, 0x131F06E175BEF754ULL, 0x73AE5D349D743B28ULL, 0x2E4EC1BE1A6777A9ULL, 
            0x639E1563BE5ACB06ULL, 0x7036DF613EE78003ULL, 0x1736B9CB389A1F96ULL, 0x560FD87B4379AC08ULL, 
            0xBEF9A75E7D616958ULL, 0x3E2CC592D24A30DEULL, 0xD6397314C60B400DULL, 0x0A3E52669FDCC8E6ULL, 
            0x7909642EFAE15628ULL, 0xABB0A3F2399D46DAULL, 0xEAE74BA3505F7A7EULL, 0x36A05E27248D84D8ULL, 
            0x9E350C9B61A1E994ULL, 0xE6B947C88B3C64C8ULL, 0x8E0DE31420E65EE8ULL, 0x23564B463C968E1BULL
        },
        {
            0x18A1E2D5DD5F2390ULL, 0x680C70FBA4576522ULL, 0x0CD552E9F947E465ULL, 0xA722F0C95465E7D7ULL, 
            0x2C7C5A7A24CE8675ULL, 0xEBD62237EB0713ECULL, 0x9864DE5BE22E3B60ULL, 0x3668F0EA4DDA5ECFULL, 
            0xCD44497723EA3150ULL, 0x0E29219EB5755A9AULL, 0x5370BE68DC692325ULL, 0xBB0D198AE561E36CULL, 
            0x0C5633E8ACBB97DEULL, 0xA661DEC524638EBDULL, 0x31FF1D96560C78DEULL, 0xB416783F295E1038ULL, 
            0x6F04F8B131E445B8ULL, 0xB4C65492D6F450A0ULL, 0xC8152102366BB01FULL, 0x9FD7B85A907E5EAFULL, 
            0x991778FC8B16C10FULL, 0x14B6744B1C3AC114ULL, 0xBFFB57A716BC0E62ULL, 0xC429F253DD3B077BULL, 
            0xD76F6576B1D48D51ULL, 0x73894C9556599666ULL, 0x1EB4267188F6BD38ULL, 0xF99614F23AD586F3ULL, 
            0x38585B2565A41207ULL, 0xC7A7254EEC5019D6ULL, 0xA452240033A11116ULL, 0xA3D85B3BFB2B34B2ULL
        },
        {
            0x308DAFE9ADBF707FULL, 0x4B305A5CC16B36AAULL, 0xB95184217ACF2482ULL, 0x268DD4D6C8154727ULL, 
            0xED81465B988BD367ULL, 0x7A4CD6A2D8E6889DULL, 0x731294CCF29B4EB7ULL, 0x1D82252193A79293ULL, 
            0x9B14E3D01E95576DULL, 0x733D1D9DE85B9B04ULL, 0xA77D32CD73D8A0C7ULL, 0x8C8880CF54D3D8C6ULL, 
            0xA59C844E220B8B80ULL, 0xE9FB35BED1600D3DULL, 0xA67B48FE2E577B70ULL, 0xC7D8189D9FF46652ULL, 
            0xFBD391B88C96C3BBULL, 0xE294626A935A660FULL, 0xC05CA17424A9373AULL, 0x6A5D24528F2C279EULL, 
            0x03715180B2B716B7ULL, 0x66774ED094393B4BULL, 0x74651E05EA8F0AE6ULL, 0x75CD132BC1F19004ULL, 
            0x2C6545E6C5E3ABA0ULL, 0x2C8CB651BF1A50F7ULL, 0x13C5193F8DE8606BULL, 0x25345B5C45DBCA3EULL, 
            0x213047948573FF03ULL, 0x65B97C242093E005ULL, 0xE86AF80FFD18232AULL, 0x5F6547E1FB678F3FULL
        },
        {
            0xCAF741BA4211136EULL, 0x5C5B26D1486C3FF6ULL, 0xA185738F39462F27ULL, 0xB0D1F1EA9156CFD8ULL, 
            0x06C008DAB2632F9AULL, 0x219E5E37236B342FULL, 0xF3BF8A54D9F742C0ULL, 0xB3C11B618F854794ULL, 
            0xCF125FDFBE7654BAULL, 0x292D0EAE2BA2B3D8ULL, 0x90A9358358B08E4BULL, 0x39AA928C04B3ABB9ULL, 
            0xF5073C6F3349FBDEULL, 0xE5F7B14F377FA3ECULL, 0xF2263B0FCD3F60A1ULL, 0x5FE94965DC6D4935ULL, 
            0x78C73B63BBE24356ULL, 0x0EA609A96DF0D680ULL, 0x35E4D7B2CCB71408ULL, 0xF48DDF2BB9A8FE13ULL, 
            0x759C874FE62E3103ULL, 0x99A16B37767FC8F6ULL, 0x279699D8D154F176ULL, 0xFEC367D9026589F7ULL, 
            0x8194F9EA65E14C1DULL, 0x58F2C9C7F2D59C41ULL, 0xCE48A4D18D3AA3DBULL, 0x2B1CEC927E18F544ULL, 
            0xB736A5161B4A3ADAULL, 0xAE88E4E52A8EC6FCULL, 0x7ACF46B1C7140230ULL, 0x4E476651117E4CE7ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alnitak::kTwistConstants = {
    0x777F8EAC2C4F69F1ULL,
    0x31ECE0B4B0C00759ULL,
    0xB295B7D58C127D2EULL,
    0x777F8EAC2C4F69F1ULL,
    0x31ECE0B4B0C00759ULL,
    0xB295B7D58C127D2EULL,
    0xCD2A55D9D8C43828ULL,
    0x48DAE9DC98A80823ULL,
    0xE3,
    0x83,
    0x91,
    0x4C,
    0x34,
    0x11,
    0x90,
    0x49
};

