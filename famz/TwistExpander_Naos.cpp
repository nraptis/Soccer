#include "TwistExpander_Naos.hpp"
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

TwistExpander_Naos::TwistExpander_Naos()
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

void TwistExpander_Naos::KDF_A(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Naos_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Naos_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Naos_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Naos_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Naos::KDF_B(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Naos_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Naos_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Naos_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Naos_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Naos::KDF_C(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Naos_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Naos_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Naos_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Naos_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Naos::KDF_D(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Naos_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Naos_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Naos_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Naos_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Naos::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD49EF912056AECE3ULL;
    std::uint64_t aIngress = 0xC4C883A19274D22FULL;
    std::uint64_t aCarry = 0xB2015F7E81434D66ULL;

    std::uint64_t aWandererA = 0xAEF69F75388939F1ULL;
    std::uint64_t aWandererB = 0xE6E7BD26C7F3296FULL;
    std::uint64_t aWandererC = 0x854B5E8AE3B2A9A2ULL;
    std::uint64_t aWandererD = 0xAEFA8DB4390713C9ULL;
    std::uint64_t aWandererE = 0xF88636DC539C2884ULL;
    std::uint64_t aWandererF = 0xDC8922F2D618F5A3ULL;
    std::uint64_t aWandererG = 0xF189BE553203B1DFULL;
    std::uint64_t aWandererH = 0xDDFE7F0DC7CA41DAULL;
    std::uint64_t aWandererI = 0xEBF60BC4E50D216BULL;
    std::uint64_t aWandererJ = 0xFC3A773DBE99F15CULL;
    std::uint64_t aWandererK = 0xFE0FB6DA1DFCE3E9ULL;

    //
    // KeyRotate A
    //
    aPrevious = 0xF6C0C48CA00D1F2EULL;
    aIngress = 0xD9A7D8724FB3945BULL;
    aCarry = 0xCF7A3C52693D8E74ULL;
    aWandererA = 0xCE0DBB6BE5DA1F61ULL;
    aWandererB = 0x953BC948ADD0F269ULL;
    aWandererC = 0xA63768E583618271ULL;
    aWandererD = 0xCBE552DD26486FA2ULL;
    aWandererE = 0xC69F896AE3C835FEULL;
    aWandererF = 0x9C0FFD464FCE3204ULL;
    aWandererG = 0xD934E1B43FE053D9ULL;
    aWandererH = 0xE8171FBEBD24CE56ULL;
    aWandererI = 0xBC6C62A007F4DB57ULL;
    aWandererJ = 0x8643FE6F578EF7F0ULL;
    aWandererK = 0xACB2CDA1AA1AD535ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateAConstants), &(pWorkSpace->mDomainBundle.mKeyRotateASalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeyRotateAConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0x92142F2434FA8770ULL;
    aIngress = 0xDE7A553AD137DB52ULL;
    aCarry = 0xEF1F21F444885320ULL;
    aWandererA = 0x8F090B493AD2BC58ULL;
    aWandererB = 0xA88C4861B90BC751ULL;
    aWandererC = 0xB66F7F57E7248137ULL;
    aWandererD = 0xAD4F95A1FFBEC643ULL;
    aWandererE = 0x9508ACE761230779ULL;
    aWandererF = 0x8D473CA281638354ULL;
    aWandererG = 0x9733FC70843F0268ULL;
    aWandererH = 0xE150F5A3973DB1F5ULL;
    aWandererI = 0xCF0DC0EE5C19D07AULL;
    aWandererJ = 0xB79ABEBD4FD2FC74ULL;
    aWandererK = 0xA2D36EEBCF165DBAULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants), &(pWorkSpace->mDomainBundle.mKeyRotateBSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xA7E22A45BD863C19ULL;
    aIngress = 0xE95B3BE88111FF81ULL;
    aCarry = 0xCF81B43835473C44ULL;
    aWandererA = 0xEA2BE5B7F98B173EULL;
    aWandererB = 0xDD80DDAFC6454842ULL;
    aWandererC = 0xF85B206744BD469EULL;
    aWandererD = 0x9CC97C53B83EC4C7ULL;
    aWandererE = 0xFA9538807A8535E3ULL;
    aWandererF = 0x848BE7A8366B97DFULL;
    aWandererG = 0xE467EDD4482D507CULL;
    aWandererH = 0xCE300041E50D4F85ULL;
    aWandererI = 0xEA4B060DB9E8CFCDULL;
    aWandererJ = 0x985398702CB53606ULL;
    aWandererK = 0x87B3E2ABBEA33A88ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnAConstants), &(mDomainBundleInbuilt.mKeySpawnASalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xDA31535C05D79C0DULL;
    aIngress = 0xC2B751DF42155366ULL;
    aCarry = 0xE99DA7C83EA5305CULL;
    aWandererA = 0xC9D23B2342D7A0CAULL;
    aWandererB = 0xC0713D2033A6827EULL;
    aWandererC = 0xD1F5F15FCA160F0DULL;
    aWandererD = 0xE6516048CE87AE0EULL;
    aWandererE = 0xB24B13CF22D8238CULL;
    aWandererF = 0xE8F440CFBEF68CD0ULL;
    aWandererG = 0xE878D5459A6F1710ULL;
    aWandererH = 0xE4CBDCD77D7FB11BULL;
    aWandererI = 0xE4DA30D8E708999BULL;
    aWandererJ = 0xC1C74DD3803F0103ULL;
    aWandererK = 0x9537417A07CA9CE1ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnBConstants), &(mDomainBundleInbuilt.mKeySpawnBSalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants), &(pWorkSpace->mDomainBundle.mKeySpawnBSalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xECBB85DB8B64EAF7ULL;
    aIngress = 0xC05D2BF870C450BAULL;
    aCarry = 0xF3B1AAD8EBAD1110ULL;
    aWandererA = 0xAF84A35E0795A877ULL;
    aWandererB = 0xC03A784FF2228393ULL;
    aWandererC = 0x83D4C3FAE0BB3036ULL;
    aWandererD = 0x90C4E48039446D7FULL;
    aWandererE = 0xF0D211A55143473BULL;
    aWandererF = 0x808E02F08A68E8ABULL;
    aWandererG = 0xC9D8CCA9E9C110EAULL;
    aWandererH = 0xE9F9BBD44AD70A32ULL;
    aWandererI = 0xF7357FCDC196E3ABULL;
    aWandererJ = 0xE1687604D471AFFDULL;
    aWandererK = 0x93545138DA094BA5ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mTwistSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xEE730314BED84590ULL;
    aIngress = 0x9189318BD99C3661ULL;
    aCarry = 0xF6C3B680FE321001ULL;
    aWandererA = 0xCD3B7416B40856E7ULL;
    aWandererB = 0xD3DB6706EE5421E9ULL;
    aWandererC = 0x8C01FA6E98DF4DD3ULL;
    aWandererD = 0x8F874AF979E90B4DULL;
    aWandererE = 0xB74E67107728D8B4ULL;
    aWandererF = 0x801B631E2A7E7D93ULL;
    aWandererG = 0xAAB6915F7067E813ULL;
    aWandererH = 0xE9512792F68BFB6FULL;
    aWandererI = 0xA41246A8C93C83A9ULL;
    aWandererJ = 0xBC95B75CFD7DE31FULL;
    aWandererK = 0xCD2BDAE56A734657ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mSeedSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mSeedSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mSeedConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mSeedConstants), &(pWorkSpace->mDomainBundle.mSeedSalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xC67BC4AF87E9A6D7ULL;
    aIngress = 0xBEBE6FF277F7AC34ULL;
    aCarry = 0xA7C9449430B2E627ULL;
    aWandererA = 0xF550B3B2E470A889ULL;
    aWandererB = 0xE3126A6EE7968F54ULL;
    aWandererC = 0xDB7D9D7DFFAF4E08ULL;
    aWandererD = 0x89131356E566574FULL;
    aWandererE = 0x80111239A6E269F7ULL;
    aWandererF = 0xF49101609770C026ULL;
    aWandererG = 0x8E86F6A21E18303AULL;
    aWandererH = 0xC5C0748AE3B14BE4ULL;
    aWandererI = 0xC7B56757B4DB4FDEULL;
    aWandererJ = 0xB482EB29B67FADF5ULL;
    aWandererK = 0xEA9CF42CBAAE1A60ULL;
    //
    TwistExpander_Naos_Arx::SEED_A(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Naos_Arx::SEED_B(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Naos_Arx::SEED_C(pWorkSpace,
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
    TwistExpander_Naos_Arx::SEED_D(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Naos_Arx::SEED_E(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Naos_Arx::SEED_F(pWorkSpace,
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
    TwistExpander_Naos_Arx::SEED_G(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Naos_Arx::SEED_H(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Naos_Arx::SEED_I(pWorkSpace,
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
    TwistExpander_Naos_Arx::SEED_J(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Naos_Arx::SEED_K(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Naos_Arx::SEED_L(pWorkSpace,
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
    TwistExpander_Naos_Arx::SEED_M(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Naos_Arx::SEED_N(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Naos_Arx::KEY_A_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Naos_Arx::KEY_A_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Naos_Arx::KEY_A_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Naos_Arx::KEY_A_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Naos_Arx::KEY_A_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Naos_Arx::KEY_A_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Naos_Arx::KEY_A_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Naos_Arx::KEY_A_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Naos_Arx::KEY_B_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Naos_Arx::KEY_B_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Naos_Arx::KEY_B_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Naos_Arx::KEY_B_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Naos_Arx::KEY_B_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Naos_Arx::KEY_B_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Naos_Arx::KEY_B_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Naos_Arx::KEY_B_H(pWorkSpace,
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

void TwistExpander_Naos::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x8737BA36553B781DULL; std::uint64_t aIngress = 0xFFC450F70FC66C38ULL; std::uint64_t aCarry = 0x87A2C5057EC0CEB6ULL;

    std::uint64_t aWandererA = 0xC903A1323E611282ULL; std::uint64_t aWandererB = 0xACD827564C1B1EDBULL; std::uint64_t aWandererC = 0x88BC2B00011A499CULL; std::uint64_t aWandererD = 0xC77AABDDBEA2B207ULL;
    std::uint64_t aWandererE = 0xCE4E46A169B8DD2BULL; std::uint64_t aWandererF = 0x8464EB1847CA1B49ULL; std::uint64_t aWandererG = 0xA8E361E89D8B65C3ULL; std::uint64_t aWandererH = 0xDEB8061C0817A052ULL;
    std::uint64_t aWandererI = 0x9DC4E9733446C2F0ULL; std::uint64_t aWandererJ = 0xB8B9003FA3B943B0ULL; std::uint64_t aWandererK = 0xCD1BEA54EBF9C37AULL;

    // [twist]
        aPrevious = 0xE0C095FB5E54B430ULL;
        aCarry = 0xAE3278D651036EB5ULL;
        aWandererA = 0x8BAFA4E6F89B7E74ULL;
        aWandererB = 0xB0F5839D8187C4AEULL;
        aWandererC = 0xBD1AF41D6E676B08ULL;
        aWandererD = 0x9BE280878D65FA20ULL;
        aWandererE = 0xE66A2E6423F76AEDULL;
        aWandererF = 0x9B9641FDB951F038ULL;
        aWandererG = 0xDE16A59090F58C45ULL;
        aWandererH = 0xF3FA39B860DBF9E2ULL;
        aWandererI = 0xD5F1910520EA5324ULL;
        aWandererJ = 0xB9E52DBD80C0081AULL;
        aWandererK = 0x8FC24E63A19049C2ULL;
    TwistExpander_Naos_Arx::TWIST_A(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Naos_Arx::TWIST_B(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Naos_Arx::TWIST_C(pWorkSpace,
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
    TwistExpander_Naos_Arx::TWIST_D(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Naos_Arx::TWIST_E(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Naos_Arx::TWIST_F(pWorkSpace,
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
    TwistExpander_Naos_Arx::TWIST_G(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Naos_Arx::TWIST_H(pWorkSpace,
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

void TwistExpander_Naos::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Naos_Arx::GROW_A_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Naos_Arx::GROW_A_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Naos_Arx::GROW_A_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Naos_Arx::GROW_A_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Naos::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Naos_Arx::GROW_B_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Naos_Arx::GROW_B_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Naos_Arx::GROW_B_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Naos_Arx::GROW_B_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Naos::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 23 of 33
    // Exploration cases: 0
    // Structural maximin 516 / 674; family total 11831
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
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3738U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8059U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7789U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8149U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1780U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1915U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1645U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1375U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1510U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1465U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 92U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1330U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 23 of 33
    // Exploration cases: 0
    // Structural maximin 517 / 674; family total 11678
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
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7429U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3288U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7159U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7519U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1150U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 970U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 880U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 925U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1015U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 430U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 610U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 790U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Naos::kKeyRotateASalts = {
    {
        {
            0xC1003537D00B5E41ULL, 0xD9DC6025E877BA1EULL, 0xFB41DF6935DF8C11ULL, 0x6A51D4CFE92C7390ULL, 
            0xBC9F6665F3B4F5BDULL, 0xB1CE4BD16EFB3723ULL, 0x317A36888F4A4EA1ULL, 0x64D6FBC4A6D8550EULL, 
            0xB2D34418ADCE4998ULL, 0x4524A7AAC8C457F3ULL, 0x19B2D91A8C2FB899ULL, 0x4A9C7EF1C4073DCDULL, 
            0x314058DF00281391ULL, 0xFFE9A4CD99FBF4BBULL, 0x441996B71784A244ULL, 0xD20E2C52219637DAULL, 
            0xC1CA9CB77A2DF00EULL, 0xEBFFA6C676F341E6ULL, 0x9518FC9C88332A4FULL, 0x1BD93E6FEBEBFDEFULL, 
            0x71AC8E921A49BEACULL, 0x7B4E09671CAB95CEULL, 0xBE26F9FFC4007A3BULL, 0x3F8B0C6F6EECD5F7ULL, 
            0x99B567033E87A033ULL, 0xF242395EBB2999DDULL, 0xB6B288D01948B811ULL, 0x4FFC0EAF33EE7BA9ULL, 
            0x14CDC95E294EE8E2ULL, 0xA519FC862011C5CBULL, 0xD23D1C4318EA41D4ULL, 0x6483021230FE4BC2ULL
        },
        {
            0x0C83BFA2627DA032ULL, 0x514A0F47122BB432ULL, 0x9D98C4A1064D990FULL, 0xBF62BB4B7B95C19CULL, 
            0x159F8BBBB291FBB9ULL, 0xABD656AE3B615207ULL, 0x55A9247114D8907BULL, 0xDFC327A5A19335F3ULL, 
            0x5D3D9FE3FFE63C69ULL, 0x1EABAF920FF7C58AULL, 0xD88E68E99BDC477FULL, 0xAD95641A668E55D2ULL, 
            0x1BB40E7B1EA9C697ULL, 0x2725939D1C67F8F1ULL, 0x889D9481C5941FB9ULL, 0xD7A9F6969D282937ULL, 
            0x73959EB50532CFBFULL, 0x1D6BCEA7D56227B5ULL, 0x74B81CC4DFA1D7F8ULL, 0xC4E26DAEB12EB919ULL, 
            0x190FEF0F8D07D37BULL, 0xEC1955420FA753ADULL, 0x204E37B92E4B97D6ULL, 0xE9FBDFB0EA849533ULL, 
            0x3E0E6E69D1CF15C0ULL, 0x737CF414A2C3BAB2ULL, 0xDCC96196CC82D33AULL, 0x32E547230496FD46ULL, 
            0xA37A9E7EBF2D1232ULL, 0x8A6042042F0E97EEULL, 0x22C757161F331F1DULL, 0xF29340636428978FULL
        },
        {
            0x5DFEFDC0804DD981ULL, 0x879BE696EBC6B31CULL, 0x8EC31023359D98FFULL, 0x4BBE584D235694F7ULL, 
            0xAFA859AC362F1E58ULL, 0x3A248DC4FEFDD2CAULL, 0x0A398D76104638DBULL, 0xAD19407906AC6C80ULL, 
            0x6E757CB12F83440BULL, 0x4A512F7B39AC8EE1ULL, 0xEF17B1562FB0A4C0ULL, 0xFECF6DF3315E26C3ULL, 
            0x1EB6D33DEF9784A9ULL, 0x72B5D73D100A00E2ULL, 0xDF8EAAEE139892F3ULL, 0xE12CA7EA037AA274ULL, 
            0x75604B567138BCB7ULL, 0xBF605265D0CFB05FULL, 0x25B7F6D630BC81F2ULL, 0xAC4284A88DE58096ULL, 
            0xC04DA3507FB1615CULL, 0x4C9CC79453DB275BULL, 0xD932B07777EBCFD8ULL, 0xA3EEF3A4DC3F0EF9ULL, 
            0xA33A76393894DD5FULL, 0x6781669BFFCBFFEEULL, 0x27F3EE5CF17A82E0ULL, 0x3B2625EC491D0C96ULL, 
            0xEFA484D8B65055C2ULL, 0xA5CF833032F3CC0AULL, 0xF4ED8BF91B9A7D7FULL, 0xA3846F2BE4E1DC22ULL
        },
        {
            0x5C0D598E9B120A5DULL, 0x42D6B83A867915C5ULL, 0xD3FA136DADA24FD8ULL, 0x68C572B212398019ULL, 
            0xEB9F8275FBE26ABBULL, 0x711BEB68DCDE8C35ULL, 0x1FC398DAAF701C72ULL, 0xA6624AFD158A4BBAULL, 
            0xAAF4041D7B6988CCULL, 0x478FB534E22764FFULL, 0xD6AC02579FF2E812ULL, 0x949F88AD27EFA1FBULL, 
            0x86063C9D72F140DAULL, 0x5C36059C0EE68C66ULL, 0xFBF6ABDDBE507A79ULL, 0xCAF15FB161FBC617ULL, 
            0x91C62E9B2CC684C0ULL, 0xFE41D95151DCE440ULL, 0xD46499C3F2618B94ULL, 0x920F020DEFE18444ULL, 
            0x22560B6FD94C0EC9ULL, 0x04C9E75A3EE82006ULL, 0x8B006694DC8F49CEULL, 0x1943EB66E44B4E9DULL, 
            0xB901789C89153087ULL, 0x0997DC467222058DULL, 0x6393F61928928DC6ULL, 0x980797A41EC456BEULL, 
            0x8C2C95A88CD08A4DULL, 0x29EED03198C908B3ULL, 0x96ACD081B41EB690ULL, 0xF5D92019D90E0A4DULL
        },
        {
            0x41908474EB3B2FCDULL, 0xA9520C5100B4FA40ULL, 0xF827C49C1DBF0C82ULL, 0xF3B556FD726569DFULL, 
            0x99BCAAA0BCD32CACULL, 0xECFBB7A42ED612E0ULL, 0xDE9738121B4ED617ULL, 0x43BA3DCE17F6F7C4ULL, 
            0xA2B4B1A864451767ULL, 0x3810E0ADEABF3211ULL, 0xB91F8D33F4C43830ULL, 0xABA7CE87154A407EULL, 
            0xC629A9F8DF5680E7ULL, 0xFBE52CC6A6C83CE7ULL, 0x03495174D329B3CAULL, 0xB347688E1B28C730ULL, 
            0xE8A656344EEA1502ULL, 0x80A3363AC75D4C78ULL, 0x8462AA298A62C93CULL, 0xA52D958244BAC448ULL, 
            0xF9079009F8379F8DULL, 0xB9B0AF6BF8C0FC1FULL, 0xC24CF85DB4BB7851ULL, 0xACB3D9B97BF5D4A4ULL, 
            0x044E5A51CFB48FB7ULL, 0x212EAB73F0932806ULL, 0x1227C0E6E87F1FC4ULL, 0x9247CFD39C0176ADULL, 
            0x74E819FC58582CF3ULL, 0xDA39C3F593D223BBULL, 0x85E3E117E10E67C0ULL, 0x6745D1AC48899ACEULL
        },
        {
            0x59DECF5BD63455BBULL, 0xDC43B643DBF529CEULL, 0xC7F6F28F0A764BBFULL, 0x61FF24D80B3173B5ULL, 
            0xACBEC0B545A343B0ULL, 0xADC346A37C215DA0ULL, 0x0FC13A8D02D2902AULL, 0x181DE6C98A5CE034ULL, 
            0xFEC95C42B84D0177ULL, 0x3C56DD6A2E7B47E0ULL, 0x93D1AFBF9179F6D6ULL, 0x05A950BEB67CE162ULL, 
            0x47241393D4D9AFD4ULL, 0x9D343096ED0C65A8ULL, 0x81DA7DD0A3AC6372ULL, 0x6E7D8C82F975E6D6ULL, 
            0xAE721C05C80E7942ULL, 0x8745FD95DD7ECFD1ULL, 0x8AFA51E25390E16EULL, 0x83011A1CEFA7A5BEULL, 
            0xF3752D93548EA52BULL, 0x0ECD6C6F35D243DDULL, 0xD8FBC61BF468AD27ULL, 0xD41C9329FC13900FULL, 
            0x493A05DDAF883904ULL, 0x6BA7F3CBC547AFF4ULL, 0x7EF87C50FCA646B2ULL, 0xB07C6985ED652CADULL, 
            0x968061BCB798C9C0ULL, 0x25A070D224A1761BULL, 0x0BC2C6B9231E212DULL, 0xC26CBE667FDF6357ULL
        }
    },
    {
        {
            0x5C1A68C3517BD072ULL, 0x5587C076B8DC2C47ULL, 0x1820818AD64E1BDEULL, 0xC3C615354F95D7AAULL, 
            0xD7BC7CEB0818B278ULL, 0x032059C44DF3A0AEULL, 0x3133C3690DE8CFF0ULL, 0x20C9DF111D465B52ULL, 
            0x3555058CC0D1043AULL, 0xF5CF4CE7101560A7ULL, 0x218BB65E2D6BFBA0ULL, 0xBCA16BE393444B5FULL, 
            0xEE94C75CDE02F12BULL, 0x76C57E1542E773CEULL, 0x192DC96866CE8174ULL, 0x31A92A3F9BBF767DULL, 
            0xE396EEBC916D1427ULL, 0x06DDA1EEDAEC5DFCULL, 0x52AC12CAB4EA720FULL, 0x17C13690EC92DA18ULL, 
            0xE34311E689FBBE1FULL, 0x5F2B2CB2685F707FULL, 0xE14BF839D426F1E4ULL, 0x0481A85C0A732893ULL, 
            0x2A4C532FF9D6E416ULL, 0xEFB41BF5E17C1DC6ULL, 0xFA597AD301533C64ULL, 0xD15CFE1A120FE35CULL, 
            0x47727AF98F709F77ULL, 0x3E512FB96743C0D8ULL, 0x94A3D825608F6036ULL, 0xB8FA02169C52F6BFULL
        },
        {
            0xD8AA76865628A63CULL, 0x50D845F2BC57BA09ULL, 0xDCBA69AAC5DD6194ULL, 0xBB2538FB4DA3EF70ULL, 
            0x0830EAFB04A16281ULL, 0xE2A99C878DC39210ULL, 0x9FAC8EBD5F161686ULL, 0x552C9563D2609D59ULL, 
            0x805AEC3F1F8DFE39ULL, 0xF8D2D5911AB35F03ULL, 0x7CF4F998A5BA615DULL, 0xE9151A9252D7C669ULL, 
            0xBA3BD59784A6D773ULL, 0x12CC9D88ACCFE9F6ULL, 0x07E027928EC30A07ULL, 0x25C2F5007BAA59F2ULL, 
            0x5FC495A05CAE126FULL, 0x013DE2F91F247FC1ULL, 0x5BE54FDE23384A31ULL, 0x5EE70ED5BA49B730ULL, 
            0xE4AB1C7DEE98B8FFULL, 0x20B8F7F73C58AEDCULL, 0x2F66548122C61638ULL, 0x4E7EA22277C2F80FULL, 
            0x47186A455B8DA6C0ULL, 0xD0417A11377AA4D6ULL, 0x5E2CE14F7EC6C8A6ULL, 0x87F8CF073D3299A6ULL, 
            0x599C48FCAF9BB1D4ULL, 0xA3D73E692DC72A44ULL, 0x3060596DF969AA77ULL, 0x36259204034A3C54ULL
        },
        {
            0xFE7A7EDF6DE41C83ULL, 0x67B4E28112426BACULL, 0xCE6B4B25594BF133ULL, 0x41D57456C8307148ULL, 
            0xA2E225A6CDB97F67ULL, 0xD7B0E7CE7E413701ULL, 0x5F29931F990C8D90ULL, 0x15635659C19C9C99ULL, 
            0xB2772FCD2AC3C03AULL, 0x6DDFBF98245BD54DULL, 0x4EE7CCA02A13E40AULL, 0x585D4C979913104FULL, 
            0x2A2A09810605A619ULL, 0x3F641B6A66D6D59EULL, 0xD64934616787A720ULL, 0x08C58B73BB762346ULL, 
            0x87DFB96B89CA4886ULL, 0x75D93EB08D17C57AULL, 0x97A2B41A4A583E83ULL, 0x89B73ED682C33F78ULL, 
            0x097E6706771EF8DCULL, 0x592F70111E89F08EULL, 0xEB62089A227C004CULL, 0xACD51C4AF6040DD2ULL, 
            0xC639F9FE5420A982ULL, 0x17F043745915869AULL, 0x4E85E871E4E0C22CULL, 0xD7601A4C69EA06F2ULL, 
            0x3E12E3A794EEE048ULL, 0xCA36312E93F97B37ULL, 0xFAE1B0BB5C89F843ULL, 0xC7ED0E5ED91E7D62ULL
        },
        {
            0x845BC3607279DE97ULL, 0x34DAC3ADD5459834ULL, 0x0E64D2F4EF1DF12CULL, 0x19486D5EF3825164ULL, 
            0x09B198111E950B4DULL, 0x4BBC212508E007C6ULL, 0xF9666DA848E2F880ULL, 0x331165AEFDC5457FULL, 
            0xA0B9C0EB3A689CF0ULL, 0xF41D4D080752C768ULL, 0x5A450A148D01CB08ULL, 0x037709F8C12B968DULL, 
            0x8345EF4B67832411ULL, 0x1785DA087CCA15C8ULL, 0x15D189FB3A9C5079ULL, 0x1E5C3DC398EE7EA5ULL, 
            0xAF4B5E10AF99E379ULL, 0xDBC30CF6A70DC306ULL, 0x4925586A1284711DULL, 0xA15E8F32A07FA6E1ULL, 
            0x6B82A4B1657A9EA4ULL, 0x47AECB5D22AB84BDULL, 0x275521BF5AC92C1AULL, 0xCC543730BBB212BDULL, 
            0xC234FC288AA8105BULL, 0x959F565C01251057ULL, 0x98E49F97DFE8871AULL, 0x1562040ED968FFBCULL, 
            0x13A55EC13A72A01AULL, 0x754256D7BDE73E74ULL, 0xC58F706E853A7526ULL, 0xE1DC3EE3C3906CD1ULL
        },
        {
            0xFECACF98C79D09B7ULL, 0x3DEF8225946F0DD7ULL, 0x8CBA342FDE68D0D3ULL, 0xF5E7070F01CD44FDULL, 
            0x8FB2A65F99EB51F5ULL, 0x95EC30DC11CD9333ULL, 0xACE4F62F1BA18181ULL, 0x04E5FDB1F79D98B8ULL, 
            0x737AAD4291E1C13FULL, 0x4E84235538198CA1ULL, 0x7890BFC5A8B62512ULL, 0xAB237D2D7F8BFB6DULL, 
            0xF5A3A44D55B53525ULL, 0x38BA82DA183FD959ULL, 0xAD1DD78C2BF22971ULL, 0xD88139D518BF2E47ULL, 
            0xBAB555179D1FE17BULL, 0x0A0BD014F777BBA6ULL, 0x39CE7FBDC51EA3CCULL, 0x98E2F531B349CE1FULL, 
            0x72A5B8BB5D461350ULL, 0x040C42FCCF828BFAULL, 0x77BEEBCAB4163B9AULL, 0xB051B40DA4D53E54ULL, 
            0xB9BC45169A4F490AULL, 0x3EC49812C2850A04ULL, 0x69E7B4B936F91CAEULL, 0x7D6DF2FE2F1FD9ACULL, 
            0x9A2CA2E6A571382FULL, 0xBEB09EE860E1965CULL, 0x48ADB4448947330BULL, 0x8177C23A6B4E8851ULL
        },
        {
            0xF38C9CFBB3D680EAULL, 0x3B1F4479AB53585CULL, 0x0CD1249C22C62BAEULL, 0xFDD4313EC38FE663ULL, 
            0x2B2526D48FA37A4CULL, 0xB8B224931D224C76ULL, 0xE3F366DE453A3E0CULL, 0xB3F9494EABE6049EULL, 
            0xEE93A7A8AF14BD17ULL, 0xEAE8178E9BADB978ULL, 0x27AB7F9EB67B640CULL, 0x6C793E6C5B40184CULL, 
            0x44E7B6048E474D98ULL, 0x9DF481EF932297D5ULL, 0x0FD6CAB9B14A035EULL, 0x73C0DF71A7909C45ULL, 
            0x5BBB42B6A274F411ULL, 0xC194B6CC16A8CF4BULL, 0xA78D7918C642426EULL, 0xEDCAC9A8BB48E015ULL, 
            0x2393D105C9447C9EULL, 0x0CD838F909FDB303ULL, 0xEC450C12EB01351AULL, 0xC4CE7AE13A1C7E75ULL, 
            0xE3CEBB3ADB911DDBULL, 0xE7BA602EC5470117ULL, 0xBECABE6A24848254ULL, 0x405BE642F4855492ULL, 
            0xDB32175053D3C077ULL, 0x8C0B3797E18F6CE9ULL, 0x1BDD7CD67E9951F2ULL, 0xFC97948547943ACFULL
        }
    },
    {
        {
            0x21E61394B9AFAD60ULL, 0x6C10B5FDCD12C572ULL, 0x38CD4D2B949F6262ULL, 0x5238253168799C5AULL, 
            0x6712FF55EAA10447ULL, 0x9FAD62EBC36F4A0FULL, 0x711EA1CC8E30263BULL, 0x500C3D1FABF45EF3ULL, 
            0xF16F472B72B13413ULL, 0x5391729A832A450DULL, 0x4F20849EA5C87192ULL, 0xF8618225E97944E8ULL, 
            0xC21D8DE4A81904DBULL, 0x3DBC5DC72953875BULL, 0x9B702FB713762EC0ULL, 0x462A97F878CDCCFAULL, 
            0x476299A26B12610AULL, 0x28FCF91D62F1C43FULL, 0x9E6713D98A0DAAC1ULL, 0xB9828396CCC46161ULL, 
            0xC25966D96DA4AAEBULL, 0x83BC844941C3A7D5ULL, 0x8655B213EF1D8C8EULL, 0x9D0AA12388F7E5F6ULL, 
            0x95D4D1906478B45CULL, 0x85214BACF84555F3ULL, 0xA3D255C9A9D6A935ULL, 0xA21CE69FA47E9429ULL, 
            0xA41ECAF7403B1E57ULL, 0xF8E158AA55AD499DULL, 0x7697BEB4AA988335ULL, 0x95AB2E5A6A1913CAULL
        },
        {
            0x05A4B69F313BBD72ULL, 0xACA89B333A2D0996ULL, 0x0DF40A466CB2D3D5ULL, 0xD234E72C76804147ULL, 
            0xA9D6884BDE125914ULL, 0x5FEBFBE0469B98B5ULL, 0xDE6BF861D438C255ULL, 0x6804D8B77ECFFC50ULL, 
            0xB0BC082ECAD8A61FULL, 0xED796A84A3C5DF3DULL, 0x5534427CB45B6F6BULL, 0x30ED6AA0A2663877ULL, 
            0x08690E865CBC0B79ULL, 0x98EA2268FB6F3220ULL, 0x9DA59505573FA804ULL, 0xF8CC60A434126F21ULL, 
            0x21908DA8A155A6F8ULL, 0x42C10CCFD5BC917FULL, 0x37377AEA1E924FDBULL, 0xC8B541FFD4D1ECF7ULL, 
            0x2B038733B1A3F49FULL, 0x3B39027BCC14D6E6ULL, 0x1A937C6329C67625ULL, 0xCC2DC0D15F6509FEULL, 
            0x76978E98B9C7C2FCULL, 0x84959129E70DFDCCULL, 0x2500867D0D4E0CE2ULL, 0x9186F4221B44A862ULL, 
            0x07DACBF01402A47FULL, 0xA24E7426209096F6ULL, 0x427D6C65DD8A07FEULL, 0xAD9E4BF631452E05ULL
        },
        {
            0x8A535A8929350ABCULL, 0x7F0BCBD2F7657F9EULL, 0x7B52BF23BD6787F6ULL, 0x4433DAEB80844E02ULL, 
            0xC91FDE9D3DF6924CULL, 0x10284FAEF370B5CAULL, 0x210C93A922E1FE8EULL, 0xC0AB5E714ADB3E85ULL, 
            0xADBD377E1254312FULL, 0x26317314ECEAF79BULL, 0x4CE8BC4A923A31D7ULL, 0x75EC67DBCFEEAEB8ULL, 
            0xDE4AC4BBDE6E9954ULL, 0xDE1993010E7F86C2ULL, 0x1ED3CFAE138CBAA4ULL, 0x16BD1B8C0D3321B2ULL, 
            0x91C1EDE083995F12ULL, 0x440C965DC6955C2BULL, 0x8491190BDC5333DDULL, 0x609569AC501A2BA1ULL, 
            0x5C9630C01EC85AD7ULL, 0x1FF8926A9685D8B2ULL, 0x1D7B10802389AE10ULL, 0xFBA0593BCFF951DDULL, 
            0x57661CEE72A4B938ULL, 0xD8D527B69EF4FF52ULL, 0x9B9C1108A3A61575ULL, 0x234F9361484101CAULL, 
            0x4892CF20416E1BF6ULL, 0xB4FA06026B0A0A1EULL, 0x60B76221EFBAF387ULL, 0x8E121AC52DE7DC33ULL
        },
        {
            0x4A6476B19BB24BDFULL, 0x24D010B0F2397098ULL, 0xC8D0EDD12FFBDFB5ULL, 0x0E5DDE47BC83DB46ULL, 
            0x6278B5FAC8E0F714ULL, 0xB6E9BCA60535487FULL, 0x0D29D36304A07A5EULL, 0x40804F237CF435E0ULL, 
            0x72AFA668B572B917ULL, 0x80F6FEE4430A55ABULL, 0x3AF57E563362658AULL, 0x846FC89E5E05DB65ULL, 
            0x53E1CCE1D6F6070EULL, 0x878AE4E4DE17F17FULL, 0x4B415A4F8146095EULL, 0x7BD4663123101593ULL, 
            0x681992AF121A9698ULL, 0xCB61A428BD83A59CULL, 0x08A987821D17AA00ULL, 0x72F9132238377869ULL, 
            0xD23283FAEE1B4CB2ULL, 0xDA74550D775C41BCULL, 0x90193E904E37A87CULL, 0x9B279EC429916B24ULL, 
            0x8EBDFF7FA1A9BE48ULL, 0x4D771F46D7F34380ULL, 0x0A6C6260402A2304ULL, 0x6B2F536038FD72A2ULL, 
            0xB7BEC9886C493ECEULL, 0x0ECF6B5BA3096175ULL, 0x6AD3F0B558199FF9ULL, 0xD09257EB1CDC8824ULL
        },
        {
            0xB399C052CF220045ULL, 0xCB8BEB2126DCBB10ULL, 0x2F8FFC21A9C02D6CULL, 0x1D8DE71FA1461455ULL, 
            0x8467A6A6CA0F745EULL, 0x094C3818D0E8FD07ULL, 0xECB6856D96B4BE3EULL, 0x9FEE9B71480FD9D6ULL, 
            0x355CE944EDD8E7BCULL, 0x5CE82DB77929E69EULL, 0x4BEECC3F21D4F0AFULL, 0xFE75C47DB1ABF526ULL, 
            0x1F1BC2CE3D7A0871ULL, 0xA9462740A5EFC5CCULL, 0x7C73E89C8E9D346CULL, 0x291F600D4402E6D1ULL, 
            0xCEEDEDCCA2E41C6AULL, 0xF385FF387801DC45ULL, 0xA3CB58AAC8C85E3FULL, 0x72EAE58590FE9EC2ULL, 
            0x78D237E3DA99F792ULL, 0xEFEEB74180627337ULL, 0x1E6D0F6FC464D1FEULL, 0xA86455320B5BEF2FULL, 
            0xCD4990CCF47906ACULL, 0x7CEFA21589E5A04EULL, 0xED5ECB4283CF32DAULL, 0x2420D26AA3AC84E9ULL, 
            0x9A7756EDD260780AULL, 0x26A2A80520041E9BULL, 0xD8A47CBA742AED1FULL, 0x70F36CBBF5DD0A65ULL
        },
        {
            0x4A8EDAF9EC7A73BBULL, 0x4EDB9EAEC106B91AULL, 0xCE6A7705703F644AULL, 0x90A81E57D4A1A804ULL, 
            0xE8B11083DC448BFCULL, 0xB8F011D7DCAF99EFULL, 0x5B13DA595A97F958ULL, 0x05F690CB488F9551ULL, 
            0xC29A77F630AA9413ULL, 0x740E2FEF52689D9BULL, 0xABCE2A36E25F2952ULL, 0xB29BA58B609003FEULL, 
            0x779FC999525D34E5ULL, 0xFAFEE7AFED9F3777ULL, 0x1F5ED7034FD809C5ULL, 0xADFC601D854583B5ULL, 
            0xA9AD43BB5ECACF7DULL, 0xB94F3C02949651E5ULL, 0x3D0696CEBC0F7A5CULL, 0xB946C354AFB98378ULL, 
            0xFFC99A0F80C36998ULL, 0x61A8962ED119886CULL, 0x17613200C5392FDBULL, 0xFE14BA416FAF52F1ULL, 
            0xE57C6F129A9B96CDULL, 0xBC9250BF97A117AEULL, 0x1BF6C95497467900ULL, 0x38B5D5BD38075FE9ULL, 
            0x6EBCD653C3BCC5DDULL, 0x7577FE32160ADA6FULL, 0x383F8AAA595F6DE0ULL, 0x9405E408A2D18115ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Naos::kKeyRotateAConstants = {
    0x8DEE92F80F99D1CDULL,
    0x84BF6804D729BC98ULL,
    0x39926E5B5B214B3CULL,
    0x8DEE92F80F99D1CDULL,
    0x84BF6804D729BC98ULL,
    0x39926E5B5B214B3CULL,
    0x4C87DC670B61D298ULL,
    0x3FBB9575F83E2AD1ULL,
    0x53,
    0x94,
    0xC4,
    0x95,
    0x1D,
    0x87,
    0x02,
    0x01
};

const TwistDomainSaltSet TwistExpander_Naos::kKeyRotateBSalts = {
    {
        {
            0x6AA2C83E8207F5F5ULL, 0x175E2F1DD706A02CULL, 0xAA1C48D74D9866C2ULL, 0xE30DFB15A52B65EFULL, 
            0x461C6C3A872CA59BULL, 0xE99C71F6FA625B39ULL, 0x28AB7803128AE65EULL, 0x1DC4CC5C6851B586ULL, 
            0x0C33A60D88692AEEULL, 0x51395B269F4BB46EULL, 0xFF3A7C99276B4523ULL, 0xB25E04221D60B9D4ULL, 
            0x5B7CDE03AE670F5BULL, 0x342025D8D18DFEF2ULL, 0x6A544290D79D041AULL, 0x100E45577DE76D40ULL, 
            0x142015DE3E4A9BD1ULL, 0x073FFE9B597A161CULL, 0x02685F3E68238EA0ULL, 0x3C74DD1BCEE58855ULL, 
            0xF18582DAE84AB7AAULL, 0x77621AA165577A61ULL, 0xF58851EB4B0684B7ULL, 0xDECE2C426318FB27ULL, 
            0x2C92C07867FCD127ULL, 0xF87C8AA0BF7723ADULL, 0x165C690750AF99FAULL, 0x903D555958AD9ECAULL, 
            0xE12DBF1CF8CB90E2ULL, 0x2BDFFEE4F3CCC09AULL, 0x67616D9B76EB2647ULL, 0xD27C921CBE9D788DULL
        },
        {
            0xFB6BC168D04D2A23ULL, 0x99EA2C8F417E45D4ULL, 0xDCD245646858D848ULL, 0xE00EAC3FACE94576ULL, 
            0x45AA1FFF6D5263D1ULL, 0x1BD01DF8C10FEE9FULL, 0x9FEDFF636ADA6C05ULL, 0x87292D84B1731360ULL, 
            0x2D9E7494D95490F8ULL, 0xC1D765C16F2CA52DULL, 0x5DAAD06863DDA645ULL, 0x2619281CAD935A30ULL, 
            0x0F85494CF2583B24ULL, 0x4BCFA40EBDCD0CE5ULL, 0x704DFE7CD2BAEE93ULL, 0xF4D9E443640825DAULL, 
            0xCEA87757D1CBF8A8ULL, 0x0CE84148EA1E8A82ULL, 0x5CBDA2A27A50C7F4ULL, 0x7DB9BC59E11ECED9ULL, 
            0xD29D927CD8361551ULL, 0xFEE1E6DFBF8DC4ECULL, 0xDC007D37E262A06CULL, 0x28EA94C5CD9C1732ULL, 
            0x7CF34AADA0928019ULL, 0x8EEDCFF09BBEE06DULL, 0xF8CA9F2A5C6F994CULL, 0xC6A045966394C23AULL, 
            0x31770BD1A627E158ULL, 0x919B1E22AF5AAD37ULL, 0x5DB8AF92069550D3ULL, 0x51DA736713C84503ULL
        },
        {
            0x272EC51EB337830DULL, 0xCD98AACD4DAD3A5CULL, 0xAABD77816DC25D7AULL, 0xF9E96A578C0E6C53ULL, 
            0x51E4DF1C832FF906ULL, 0x3F91A9DC07459068ULL, 0xBF54A718B20657A5ULL, 0xC20F00D3B7ACBE05ULL, 
            0x7637EEFA5FCDEDB2ULL, 0x6267FF73633FE7B2ULL, 0xB47161C68BF74A91ULL, 0xB9AB8E45E0F51F7EULL, 
            0x86DDCF01F92D20C2ULL, 0x7CCC0A6E365D602AULL, 0xCAB89710557EDF68ULL, 0xF100212CBC89EFC4ULL, 
            0x1893DF4DDCD653E4ULL, 0xCC59F17D6384ADCBULL, 0x80998D6CF90187D5ULL, 0xAB01186630D2A260ULL, 
            0xF12AB6659707B924ULL, 0xADE5F5164CA062DEULL, 0x1821271B67A4BDEBULL, 0x98EF2F38E0174D1EULL, 
            0xF28A700ACEEE9C76ULL, 0x89AE000FE8BED722ULL, 0x80C9ABCBC82589B8ULL, 0x60B778000B8BDAC6ULL, 
            0x871FE48DD7F426C1ULL, 0x10C4A5DE240534E9ULL, 0xA01E1D722E36383DULL, 0xBF0F07D9E6408E10ULL
        },
        {
            0xD2A7111C8F9EE9ACULL, 0x740A1DBEB03440C9ULL, 0x0A31EF01AB6D63BFULL, 0x13BE625048BBAFC7ULL, 
            0x3ADC16EAB89427CDULL, 0xDC3C921FEF4EC04AULL, 0x39113864A648D361ULL, 0x181C4EF6F133A646ULL, 
            0xF4CD8F54B46EA4C3ULL, 0xFD80F40ED6DFCED4ULL, 0xAE0C885DE8B46EB2ULL, 0x525FA894C81FBFB0ULL, 
            0xBF9893DC910C11B0ULL, 0x88A8A8B9D8A5F075ULL, 0xB8C680306A3B0F92ULL, 0xF8A27572C390D339ULL, 
            0xED76BDB080515369ULL, 0x284BAB13258E75E3ULL, 0x15F51CA617831EFDULL, 0x1E7D37D77B715AB6ULL, 
            0x3BC05838083B4480ULL, 0x029932BFC58E6F47ULL, 0x5C5CEE2F2CFF565BULL, 0xF951AD4551FACA39ULL, 
            0x528BDA4BC28D3550ULL, 0x27D738C4AA631A6CULL, 0xF2C820E81F8917E9ULL, 0x8287AFB017499D31ULL, 
            0xC332F5E8D82E85E2ULL, 0x21E17C950DA5C3ECULL, 0x00626DA916F87957ULL, 0x6168F9EE38E77729ULL
        },
        {
            0x4B9BE8C1B60E851FULL, 0x31AC336C79675829ULL, 0xAE0E6788A579E45DULL, 0x545C0F655882893AULL, 
            0x9383BB9510EB6C6DULL, 0x9E946F2FEB7A6219ULL, 0xD44F6939D2DF6773ULL, 0xF9DF9888C9035E61ULL, 
            0xA8E22F4992E047BFULL, 0x75CD12CAFB5FC621ULL, 0xB2EF22A47A810C16ULL, 0xD570705546D7D86AULL, 
            0x37A9666B699A00CBULL, 0x4D22C000CE97B12DULL, 0x7E4D57EAA7BEE7DDULL, 0x55E439D6CE11F875ULL, 
            0x869225E66F4810C4ULL, 0xD9CFD3166E990199ULL, 0xB2E1D9A4760A3277ULL, 0x1AF652BB7298CA66ULL, 
            0x32C19EB312628529ULL, 0x675E56EB7923EF3EULL, 0x3C095D2EC155CBA4ULL, 0xAE0465D6DD01DFD1ULL, 
            0x921272544FD8EEF4ULL, 0x8C756FE08A1952D4ULL, 0x52388416BDF5DDC8ULL, 0xD5AD0CF2D1D11DB6ULL, 
            0xBDB7EEA3DC0011FAULL, 0x766463A6A289AA2AULL, 0xB5DA75C873F91B68ULL, 0x52394D0D8881C50AULL
        },
        {
            0x675D83C75267B950ULL, 0xDF522D4F1B880A45ULL, 0x8597213B8E74C90FULL, 0x2B374481A11E1565ULL, 
            0x2AE1FA07236B1565ULL, 0x60B86CABA404F795ULL, 0x61C20987A6E49248ULL, 0xF798A59A6460246CULL, 
            0xF2C53865A1F07588ULL, 0xE0DD560BA73E24ABULL, 0xC798467EE647B4B1ULL, 0x69BFD25FFAD38DDDULL, 
            0xB136104D6865774DULL, 0x1391DB8A69353860ULL, 0x110A3909D645C0E1ULL, 0x7495684C41AA6A17ULL, 
            0xE1E47BD8CD12A995ULL, 0x3EAB09D51AD6E890ULL, 0x6FB4D6EAA39662B3ULL, 0x516A05FC77BA5BD8ULL, 
            0xC2F9A602AF860E67ULL, 0xBFDE657FA2147B94ULL, 0x18538B6C1030E0C3ULL, 0x73BDF5E5C5D95F2DULL, 
            0xBC7D6350A3ACB161ULL, 0x8F7A8973730EFB71ULL, 0xB78518A9E9957162ULL, 0xBD5AEE151EC57E91ULL, 
            0x46F6F58DCA0108F7ULL, 0x3FCA81682637A3FEULL, 0x6089A8EB0A7628B8ULL, 0xBB7AF29690B5DB88ULL
        }
    },
    {
        {
            0x9E607AD901764322ULL, 0xA077D2FA924ED9B8ULL, 0xA558BD846CA360A6ULL, 0x5ED80D4DEB0F8FE9ULL, 
            0x8F68C673332B9843ULL, 0x8EC77542C1ED6576ULL, 0xEBD2D3F5B4BB472DULL, 0xA78C4ADDCFAEA69DULL, 
            0x8ECF87B1FB268AC0ULL, 0x691ECDCC667C26ECULL, 0x778F313A4FCFFF32ULL, 0xA9995E8C9D412B43ULL, 
            0x9978F72492A84846ULL, 0xB05A81ABF57E82E7ULL, 0x8077ECC980534541ULL, 0xF22F71ED4ECCDECCULL, 
            0x69B35E4A2FC55D06ULL, 0x392D9B2219411BECULL, 0xF6A1612D6CC84B0BULL, 0xF589F89E9136E44CULL, 
            0xBE0AD4B316863EB9ULL, 0x506E3B0483278741ULL, 0x10CB5FC30CB03642ULL, 0x049EFE378CC79F45ULL, 
            0x9406088EE52D49C4ULL, 0xBA0A567445E9B702ULL, 0x4F436B79B68FE75EULL, 0x3458635EB4EAB03BULL, 
            0x7175AEBB4F867B01ULL, 0x2FD30A66C6ECC978ULL, 0x98E72567BBD78E05ULL, 0xC8C75C1B20D8FF01ULL
        },
        {
            0xEAA7A030FDB41F98ULL, 0x1C76AA2E0FCC3A6BULL, 0x4368AC5B4263D583ULL, 0x9C169D750445769CULL, 
            0x68B1ED1B9350A3F4ULL, 0xBC20F82BBF762745ULL, 0xBD32578E5366E78CULL, 0xB48F5BA01E25B1A5ULL, 
            0x1633B885F29521E0ULL, 0x7852290705EE8FFFULL, 0x0678CA1AD2A0BA76ULL, 0x556DFA463FEF8443ULL, 
            0xC516C913A23217F6ULL, 0x5CD82592AEF4EA59ULL, 0xA9F8D243C9D21CCAULL, 0x6375748F68467BCBULL, 
            0x596609C02D02F199ULL, 0xAB78D5918EB09AB8ULL, 0xC46739C448A17708ULL, 0x16DDCCDCD2F5D86DULL, 
            0x6EF24E7AAA908E19ULL, 0x562557E89683FF0CULL, 0xD67C86B425DC1D82ULL, 0x58AA93F87A882CA8ULL, 
            0xE6F0FE3D4DD25DC1ULL, 0x6B00434232EEB853ULL, 0xF602D053A0DAC6B8ULL, 0x89D8371F65B2FE51ULL, 
            0xD492860BFCAEBA65ULL, 0xA8FFC1D1C5E54757ULL, 0x7F46BBE36CACB7B9ULL, 0x39EFEAB01C417B6BULL
        },
        {
            0xF027FD368B56C270ULL, 0xA4A0ED683A3A3852ULL, 0x7653814A65AB44DCULL, 0x4761AE6C399D3235ULL, 
            0xF61C0D0EA72CCFEDULL, 0x20ED446EC9CD9C71ULL, 0xB723C44A5DA132DCULL, 0xE6830FF183976A02ULL, 
            0xA96F82D7824BE43AULL, 0xC5935D872653D2FCULL, 0x214CB1EAEB0CF6C5ULL, 0xC02AEE9633B341D0ULL, 
            0xE5607BF2E5CE3487ULL, 0xF1D57F34940BBFD0ULL, 0x0E375AD3B4C8DC7EULL, 0x2EF9A84FC3BC398EULL, 
            0x376AE25C31BE8575ULL, 0x12AF621D6ED142F7ULL, 0x4AE931A2202A82BFULL, 0xE9E3457767165AD3ULL, 
            0xA9B4C047D45472E9ULL, 0xBBF5575D9D50812FULL, 0x785C6F3EDCF1C01BULL, 0xBCA04A4D880155F8ULL, 
            0x4224FD934518DA81ULL, 0x4C3BC40C420DB2AAULL, 0x13BF4550B9667B81ULL, 0x63F9137F4DC02935ULL, 
            0x3D49DDB254B623DAULL, 0x9DE7236BD2085B34ULL, 0x69959C5B0902D4A6ULL, 0x763ABD6097468489ULL
        },
        {
            0xA9FC426B727D8900ULL, 0x31E86E34F05F8E49ULL, 0x93C8DFE3CEEB340AULL, 0xB87584863A1C9F25ULL, 
            0x6F4F4713C7E32CEFULL, 0x99D55FFF2DC5CAC1ULL, 0xE830828D3B031E72ULL, 0x728721D8ABFBC0A3ULL, 
            0x42CE4B6E04BA54FDULL, 0x4EB232DD25FAB3A8ULL, 0x692DD79B0426E715ULL, 0xDDC730B13228A8FBULL, 
            0x7473771ADB25B6C1ULL, 0xC17556CC19064958ULL, 0xB67F9F2440079A42ULL, 0x923C497B0D8E3900ULL, 
            0x732595A22382680DULL, 0x78498C52240E5434ULL, 0x6AF406D9FA9B6C1BULL, 0x1F9B056AA5BCADC4ULL, 
            0x1DE8C165E19FE377ULL, 0x7A75A4CE67CB7EDCULL, 0x8B206280E9FE5ECDULL, 0x5AAE422F5B019A0FULL, 
            0x65FCA6366FFDDEE0ULL, 0x87031846030EA554ULL, 0xD3ECFB7D43EA5BE4ULL, 0xEBDAE16B6A3C4D05ULL, 
            0x2C83A32DF8CE7410ULL, 0xE7F03A5D71090DC7ULL, 0x9D34A304025027E2ULL, 0x2D71F09ED0DD03E5ULL
        },
        {
            0xAFC36353B303DE46ULL, 0x6AC928B22A2BB887ULL, 0x33053CDABD6F6B4AULL, 0x6A8329330AFE41C4ULL, 
            0x44F5EB67DA6ACEEDULL, 0x53D9F8DF747618AAULL, 0x62DB27DE566514ABULL, 0x001BFEBE67DFB09EULL, 
            0x8CDBE5E993DBEF92ULL, 0x1933176116FCCD7AULL, 0x70485536F0B86380ULL, 0xF5E5F08D459431FDULL, 
            0x9C0CFA5A1AD7C1F9ULL, 0x47C8D13F8F63C350ULL, 0xBA9441EFD4AC0531ULL, 0x6F3BB93436EE8DC4ULL, 
            0x33B946E68E1B2C00ULL, 0xAFC646C4759FF92BULL, 0x70E31D2C9818C00DULL, 0x398F5EBEA77EE0A5ULL, 
            0x6909667D77A93B5DULL, 0xD35815990010DB56ULL, 0xAF654CC2705AD647ULL, 0x6F46D2A19C789AF6ULL, 
            0x78F0C9053DCB7558ULL, 0x9BDA9331308075D6ULL, 0x30365BA6930ADC36ULL, 0x2729BF59547EA529ULL, 
            0xA28FD4465BBDE515ULL, 0x870E07E45E2AE103ULL, 0x7A00AC5F68A76370ULL, 0x76A187A8E074B900ULL
        },
        {
            0x1BC407FFAC4B9273ULL, 0x8D76E5CCA62E1BDFULL, 0x8562C2E4515F35D9ULL, 0x28824B301CF1BDF1ULL, 
            0xE3A55426BAD74381ULL, 0xD4B7E6BA53C3B20BULL, 0x517C5B3ACBDA9D60ULL, 0xF76630709BE73F43ULL, 
            0x5339451805572DD4ULL, 0xC03C53320D926AAAULL, 0xC181B0356C9B6CD0ULL, 0xF99D72282CBBD0E0ULL, 
            0xD37E4344A507BD92ULL, 0xEE894FDBA09F3506ULL, 0xF763CB6FBD4FAB4CULL, 0x50C7CB468E5BAB98ULL, 
            0x866B169FC1017550ULL, 0xECA7C14ADCBE021DULL, 0x53DF556AA9B3668AULL, 0x7EC6ACCE9F438563ULL, 
            0x86113A1DA56134D9ULL, 0xAF09C9D0590C11F2ULL, 0xE8317F6F2075383FULL, 0x9161FA9A47F58319ULL, 
            0x4309D4A2152AC8F3ULL, 0x48DFDE72FCDD5E9FULL, 0xE819AA4AEB3D9A0EULL, 0xE300E40E3458D5E6ULL, 
            0x01697DFCC8950489ULL, 0x256A46C3986F8D37ULL, 0xAEB89513C67C83E0ULL, 0x885188CD61F5817EULL
        }
    },
    {
        {
            0xA20226C675D8199CULL, 0x98A55A14CDF108FCULL, 0xC63A66C70CBEE300ULL, 0x095044997BEBBBB7ULL, 
            0x36445A7B9AD0F3A9ULL, 0x4B54B83AE5A826F3ULL, 0x200AA0422ADE4757ULL, 0xC3908D81E886354DULL, 
            0x6E768F4BA71FFD75ULL, 0xBF93008044DD4280ULL, 0x24FC36A4BFA029B9ULL, 0x315BBD59D9307444ULL, 
            0xEC99DC9B1CDA054BULL, 0xD8D384AD595D2D52ULL, 0x80C7102F39F302D3ULL, 0xE0CB236E0ADBB4FDULL, 
            0xE0623BD82F20C75CULL, 0xF30D494CD1E2816BULL, 0x639243CA9DA564D5ULL, 0xD967572D7BDFBBE4ULL, 
            0x770BA2F019B52BFFULL, 0x73AF76CFE7CD611CULL, 0x888A05B876BB46F0ULL, 0xF052562850BF1D8BULL, 
            0xFCC10E8D804F497BULL, 0xB7B973F94BC83C9FULL, 0xA9D00CE5AB5C5CF6ULL, 0x9CDB402BC1E87E64ULL, 
            0xC862E5CBEAEECE22ULL, 0x521A6F7708973F5AULL, 0x7216E27CE311BC48ULL, 0x29D01A181C076E22ULL
        },
        {
            0x2F9F13D870032DDDULL, 0x864E9D096746E9D9ULL, 0x7C5EAF76C6F1F367ULL, 0x3283CC3C703C4166ULL, 
            0x2D3DAEF0A1B53BEEULL, 0xA3AC73D9A98CA78DULL, 0xCF2BE76EDE361C3CULL, 0x58AF355FBBA8F5E9ULL, 
            0x0CCB05FF34672B27ULL, 0x5261C9AE7368E236ULL, 0x0948065810AFAC52ULL, 0x9DFAC52EC62DA879ULL, 
            0x951A2EDC0B4A9DB0ULL, 0xF96B373869C509C9ULL, 0x38FA3D41EA4098D6ULL, 0x0167F1335B62BEB7ULL, 
            0xCF726D5674DB47A8ULL, 0x24BF3442A7FA7D97ULL, 0xA8DA81C926839AE8ULL, 0x105CFC05231841E9ULL, 
            0x574E8800F98A8F6AULL, 0x177151F00F7576DFULL, 0xD6E3303A04FE92C0ULL, 0xDA662A7047E27EB9ULL, 
            0x468913408110BBA5ULL, 0x433BBA31CA42C845ULL, 0x80E4403B6A0E7905ULL, 0x817D6528B6D63CA7ULL, 
            0xBAE7CAA9F1FA9231ULL, 0x1A4A8031418C4FACULL, 0xB6CDDD5335416CC7ULL, 0x919C3A2409D8F22FULL
        },
        {
            0xD0EADF8F284FA30BULL, 0xCFFEF0BB49B9B6E6ULL, 0x7155E1EFF552C859ULL, 0xDBD97B0F9A77FB13ULL, 
            0x21BB26FA446268D1ULL, 0xC3F9AF639D9AC0EEULL, 0x02E876464B9400A7ULL, 0x69936C3CABD50EECULL, 
            0x4B63D34380E656D9ULL, 0x8233A74BCD75718AULL, 0x66361EBBB7ECFE12ULL, 0xECDE1467BEDE82E5ULL, 
            0xBFC11DEB3CA650B4ULL, 0x88F0D3561254CFD9ULL, 0x93DDCD75CA85D69EULL, 0x089162BECB662C33ULL, 
            0x6FBE901B3F65B71FULL, 0x1DB7EB700C1EE7D3ULL, 0xC079E293B6DB2E0FULL, 0xEDDE292B3A1C64DBULL, 
            0x09051FE063C7CA41ULL, 0xB9D0CB55B220685BULL, 0x2A8307D04EBF5017ULL, 0x420B2F21B10CA5D9ULL, 
            0xB729B6FC19F37A3DULL, 0x1B146C069E2E2624ULL, 0x0A3B98004DC638DEULL, 0x7CEE3F8C33BB1227ULL, 
            0x0CDE18AD8E1808BEULL, 0x95BCF29DFB67E72EULL, 0x209656C8C421608AULL, 0xFD6FFCAF3CD1FE0CULL
        },
        {
            0xD8AE116CA7E40FE5ULL, 0xC27642A26F6349FEULL, 0xA9537907C0F06AEBULL, 0x7757014EFC213C2DULL, 
            0x47B6D7A33840B151ULL, 0x25907E60B21F339FULL, 0xBEFD495459A90C58ULL, 0xD1329989D2164C34ULL, 
            0x15FDD7F4E33D6137ULL, 0x541B4EFE0E3E854EULL, 0x4290C413BFA1F38DULL, 0xE6A5EDE19B918410ULL, 
            0xD13F2FCCB01F89D5ULL, 0x6F11A8A7E24BCD07ULL, 0xD245416F1C991DAFULL, 0x6AD9B042F786E5CFULL, 
            0x99291F527DBA38AAULL, 0x30305A6C97ED0CCBULL, 0x5E2C9E3D7A0E9F64ULL, 0x88F4629CA19652DBULL, 
            0x66AE0167A58D98B7ULL, 0xB6B0B97180F8E561ULL, 0xCC92D6CED356CD90ULL, 0xBB63F531E1DE2F9CULL, 
            0x3CC4812FFCAE66EBULL, 0x4CAAE168F438A122ULL, 0x7B62D0EF60DD0E1BULL, 0xF98640CCEE2A484FULL, 
            0x7298C9D6D21C7326ULL, 0x67DB728EF8CE8D18ULL, 0xD3F89CA2C59918C1ULL, 0xFB218929A8A8C22FULL
        },
        {
            0x9D88C7AC57D00422ULL, 0x1BAB4D39EA3D8C1CULL, 0xBF44C89E96F3C6CCULL, 0x6F5970205D06D40AULL, 
            0xA00865E830FE63B2ULL, 0xC1EFE71865FF5B89ULL, 0x77B8D46B5AA7D94EULL, 0x680C176BE3605D5EULL, 
            0x2B2E32165A49F2C3ULL, 0xBD0C03CC96243730ULL, 0x06009F4D709E8731ULL, 0xEBDD0CF45C4ED2E9ULL, 
            0x9D16DC0F82FC95F5ULL, 0x2A9FC219E962102AULL, 0x318BEC05E4F72B98ULL, 0x278EEA50C7D38924ULL, 
            0x6D32548CF9C771CAULL, 0x89CD17563B9BB0FAULL, 0x37795406E0DA384CULL, 0xFFD3D7FCE5DDD969ULL, 
            0x8168D768D7ACCFA1ULL, 0xEDA9D8A255DA6845ULL, 0xCD89E96237D93E72ULL, 0x1E5D7CDA177DAE31ULL, 
            0xFC9602FC08B5FEAAULL, 0xC7551B688A0C812FULL, 0x2A34AAADA058AF49ULL, 0x7D3862C1EE70CE13ULL, 
            0xD56D9E25D6BBD3D6ULL, 0x60DA78AD164F95F6ULL, 0x816727129AEA8F55ULL, 0x3008C94F206A6B5CULL
        },
        {
            0x7407E1C2D45CFB8AULL, 0x68CB5A951AEF1740ULL, 0x8145EFCFD5B80100ULL, 0x8ED3C7D6F6F79F74ULL, 
            0x031EB0C9FBA8B2EBULL, 0x415E925518EC94BDULL, 0x560551C780F46050ULL, 0x9925984FB0A73D18ULL, 
            0x928AC4D91469FF5DULL, 0xAC5BD9128A27224BULL, 0x449BDBAA97F69E32ULL, 0xECFCF007256E07FEULL, 
            0x4A02E24CCE5C6FB3ULL, 0x1E2F3AC0E0ABBCCEULL, 0x5A647FC6A0759C51ULL, 0x1F9139CD9CE81FB1ULL, 
            0x85528AA9FF2310EFULL, 0xF4BC10F9E2757A69ULL, 0xF198C39F8F5A8CBEULL, 0x0A330A81880AC7CBULL, 
            0xE5A140E105CC09BBULL, 0xF62A82184E91AE4EULL, 0xA6AC41919797EBFAULL, 0xC54093DE8387B4EEULL, 
            0x2ABED941EAE3D94AULL, 0xE0F29058A08ACEB6ULL, 0xCFAA74D24BCA586EULL, 0x318058469FF27130ULL, 
            0xD0EEB6C605CDD758ULL, 0x7042009D97F64900ULL, 0x799CC0A10938935CULL, 0xD669602F3FB103F6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Naos::kKeyRotateBConstants = {
    0x2340A0932C2F62A4ULL,
    0xD0763DE898F8F4E4ULL,
    0x44482D7E79943285ULL,
    0x2340A0932C2F62A4ULL,
    0xD0763DE898F8F4E4ULL,
    0x44482D7E79943285ULL,
    0xF6C7F000B5422FCAULL,
    0x50D0AAA88F42AFCBULL,
    0xAD,
    0x40,
    0x89,
    0x30,
    0xE1,
    0x1C,
    0x82,
    0xA1
};

const TwistDomainSaltSet TwistExpander_Naos::kKeySpawnASalts = {
    {
        {
            0x528590438592D3FDULL, 0xADB4B04DF882CDE1ULL, 0xFFEB16C373E9E6A1ULL, 0xA5A28AB7BA19A39EULL, 
            0x676AA65E2CD4A224ULL, 0xBEC77E861FD63ECBULL, 0x25BE7ED18C2E64EEULL, 0xD5B76E659F212907ULL, 
            0x8E6D587A154FE1DAULL, 0x24AD47D3035D766EULL, 0x3441CE3CB1D98A24ULL, 0x9C5B9A46C7914C29ULL, 
            0x8466D96BD186E72AULL, 0x090128A06DA65306ULL, 0x8F36A9C0F1FC3C6AULL, 0x461E22D83D62E2C3ULL, 
            0x5332AAA0D743E6EAULL, 0xE6545DF58C398C7BULL, 0x5EA66FB9B0919E01ULL, 0xE016786D0A33F5D8ULL, 
            0x2D7F933647DD1F37ULL, 0xD6D5A514C99D9797ULL, 0xFBD4706E6B5D87C9ULL, 0x6BEAF3BB833C247FULL, 
            0x999945A135A7A40EULL, 0x0C5FB4E160252817ULL, 0xDEAC49CF6531F918ULL, 0x7169B010167CA763ULL, 
            0x8E17BFB8D45613D1ULL, 0x3822FBC719C7341EULL, 0x0B12C3ECCED421C0ULL, 0xCCDB9F0652A85815ULL
        },
        {
            0xD5366F857501E621ULL, 0x5BE9882649F528DEULL, 0x45C11AAB8A2D8931ULL, 0xD0476BBFE360E70FULL, 
            0x323FA86717E4954BULL, 0xF8CF2FB8DAA5EA1AULL, 0xAC27C3784CB65B7EULL, 0x0DA07BA41902ED71ULL, 
            0xE08B740344863720ULL, 0x677D398C2E389E43ULL, 0xC7ECAC2338538DCFULL, 0x95A076206AAAEDF4ULL, 
            0x62C17F61B3E6EA6BULL, 0x515C920E6A22A1A4ULL, 0x9411AF6A7F31BBA5ULL, 0x9BB6567224864A47ULL, 
            0xD51444084B50ABC9ULL, 0xC37F29903C22903CULL, 0xC365FD610A3EC0E6ULL, 0x0E702371A79D1E44ULL, 
            0x5654D750044D4FF4ULL, 0xD9C5A500145CB063ULL, 0x35B779C20FCCD842ULL, 0x82AA154EB2076AAFULL, 
            0xB841465D474C7FB8ULL, 0x3513D079F7A11B6AULL, 0x81D891446FA2F4D2ULL, 0x57E92433CED9BB14ULL, 
            0x55807E7CCA1AF380ULL, 0x3CA285DE1EB5CC25ULL, 0xC693EEB5A4F2B75DULL, 0x1262C0C1E68F3F40ULL
        },
        {
            0xB27DB10DE0B4F839ULL, 0x370355C853D3B162ULL, 0x1464E85E4639D7E0ULL, 0xA08EF9EA87940324ULL, 
            0x6DDE22FC710E8CE4ULL, 0xE909E8D13231D53CULL, 0x23EDC2138FADB0C4ULL, 0x5516C0C4D069B09FULL, 
            0x6A755894AB7959FAULL, 0x6DA045CF9A03464DULL, 0xC5EA1997C140A86DULL, 0xC582FE99C746F8C0ULL, 
            0x47D77D9621061867ULL, 0x0921949B59F53FD9ULL, 0x60E6F817A4EB90BEULL, 0xE0586C2199223E6AULL, 
            0x20282A0CB45C82DEULL, 0x4E3D1DA1CCD28547ULL, 0x0702FA8EB1B2BCD7ULL, 0x429BA3A79C49DEA3ULL, 
            0xB34FD54E19EF4F70ULL, 0xBA570293FD168131ULL, 0x54DECA36002FE2CCULL, 0x5B65B294C1D4ABB5ULL, 
            0x20C77166551B15CAULL, 0x895FEB91CD41957EULL, 0x1C025CCC85DFB7A2ULL, 0x65B31B904EE4447FULL, 
            0xF29432F522191C06ULL, 0x80D7F5C9D4649424ULL, 0x5FF6BB5E39ED07C3ULL, 0xB31FBBAE7ACADEEFULL
        },
        {
            0xB89E001A10DEADDBULL, 0x0404E9499BFBEACBULL, 0x788B9814C8F41550ULL, 0xB240078029D61DAAULL, 
            0xF1EBCC19086105F7ULL, 0x763F1D71C9B6D8CFULL, 0x6F8797C369BF06E5ULL, 0xEBC1DBC967E12D90ULL, 
            0x5A8EBD244BC03057ULL, 0xB820B4B08CF636BEULL, 0xAD88F7966B176903ULL, 0xC3616204CDEC6AF8ULL, 
            0x43DF02C5C7FB5EA9ULL, 0x202B830C0EB5A7D0ULL, 0x96012A67EE2FB3CBULL, 0x7C6FBE42A986395AULL, 
            0xC4983E32DCD507B0ULL, 0xC874A0948C751290ULL, 0xFBD9FA509A54A6D8ULL, 0xB9AA703F1BAD8E31ULL, 
            0xD0193587FF76D951ULL, 0x9136C03F3596A506ULL, 0x43F3DF17B582F0ADULL, 0x969289B7FE594A58ULL, 
            0x257026D854A6B5E5ULL, 0x7E8A54F7929FC989ULL, 0x72150DB1B837B130ULL, 0xD2DB9560FBE79EC1ULL, 
            0xC630DBFA7A3D3BDDULL, 0x486E0C9F0C9460E8ULL, 0x6D6ED6D3ECEEDAA7ULL, 0x249228E2ACA1C25EULL
        },
        {
            0xDC4B7B43403234E4ULL, 0x6F2F8BC8F5F21E95ULL, 0x9DBA5EF80240F8A5ULL, 0x9C23767D889BDF89ULL, 
            0xC8D5D95FAD861E1EULL, 0x1081A2728035FD85ULL, 0xFEA06A91B2B5FF6FULL, 0xBFA2321BAB35F499ULL, 
            0x03A9CBA352A2DCFCULL, 0x23328355D62A33AEULL, 0x0E7D76208EC5305BULL, 0x917D1BD2BE4B947BULL, 
            0x6FC2D80958735E04ULL, 0x4CB13B43057B6ED4ULL, 0xDB7515AA0A5B9A52ULL, 0xF527FDF9F64495C1ULL, 
            0xD9DE444BCCB36941ULL, 0x3D02781EC5CA1CECULL, 0x4B2A040F1144AB25ULL, 0x76E4D3678856FDC8ULL, 
            0x797DDD92DB1DA6CCULL, 0xBBA88BC2B1FABA86ULL, 0x25A22C65F6A2F256ULL, 0x562F254AEB82B0A6ULL, 
            0x56A88835F17BE01BULL, 0xE2FF014238B4141BULL, 0xAC91C7DA1C0AD630ULL, 0xF93B1ECCF5D182FFULL, 
            0xB4C2F73972B07FE8ULL, 0xC1AA5B409B4F79B8ULL, 0x00469D046323C268ULL, 0x917A2EEABFC9BC40ULL
        },
        {
            0x88AB381FEA48E1E5ULL, 0x738F80AAE1FC2EAFULL, 0xDBB73ACB268825A1ULL, 0xC42A2EBE074FC649ULL, 
            0x67F0A2D7399BCA1CULL, 0xB99F247810E137A7ULL, 0xEF34EACD6B60BB97ULL, 0x55262331811ED527ULL, 
            0x13985A762573B847ULL, 0x60A7A711B30D47C2ULL, 0x69E498811D41A170ULL, 0xCDF121DA90DFC527ULL, 
            0xC82A44E746B4D4F9ULL, 0x68932BF386FD43D7ULL, 0x915B604441BF1D40ULL, 0x952B3FF14F497A7FULL, 
            0x21F42330BFF52AB6ULL, 0x258FA6C1CB18F9C2ULL, 0x3DA7CAA5A1457962ULL, 0x2BB27FDE2093325CULL, 
            0x5F47358B9923DAFAULL, 0x900750C0F2F4E98AULL, 0x007F2300EB5EFB61ULL, 0xABED8588D1911B12ULL, 
            0x529B8685EE01F797ULL, 0xFB38013E1420C659ULL, 0x8041562A56F2BD99ULL, 0x3C581485D3CFA7D0ULL, 
            0xFE4BF295E95F5AC4ULL, 0x435EB923C0A6199AULL, 0x6906607C15DD125CULL, 0x879C930B7F6238FCULL
        }
    },
    {
        {
            0x95C23CA16276D465ULL, 0x8E8C4746425A1184ULL, 0x6CB80152A175AC54ULL, 0xD3E5B7ABD99E3711ULL, 
            0x05298C2664E1A08BULL, 0x93183B17B6002DD0ULL, 0xB9C6A1425D7BD255ULL, 0x8339F335A66E2D3DULL, 
            0x03934554968A3A11ULL, 0xA05C93553183D867ULL, 0xDAD4CA70B1D6A181ULL, 0xC269EB6065C2850EULL, 
            0x5587500E185844B9ULL, 0xB2240EAD54DF13C1ULL, 0xC6B7560C0907D67EULL, 0x3632F29FD84C4106ULL, 
            0xBC711AF3331479AAULL, 0x0295468AA00CFD04ULL, 0x8007948EBF88AD3AULL, 0x892420206ED80C6EULL, 
            0x4968EA3964185411ULL, 0xE043380EA42F659DULL, 0x545C94408BAC02B7ULL, 0x12E4AC45C75C452AULL, 
            0x4DEFE9F229DC3018ULL, 0x24C3439DD29F9D63ULL, 0x22B57CFB7C711FBCULL, 0x5142B0FF389561FAULL, 
            0x5E668D7D52743A6BULL, 0xCE1783F51C21186FULL, 0xABB0E054BD20B5AAULL, 0xFDEFC78F0C5822C2ULL
        },
        {
            0x4E0E5B756FA3493FULL, 0x2E801D3A89B5E9DCULL, 0xB8BF2EE23862A832ULL, 0xAEE46A9F5AC83338ULL, 
            0xE4730231D88EAF6AULL, 0x79A7217099C1B8EDULL, 0x73C0CE76C9229B28ULL, 0x4FF545CDEB0BE9C0ULL, 
            0x88F6F52F0342A974ULL, 0x883E3B97380E5B3FULL, 0xFB8773FCBE00B222ULL, 0x4538B137070A3108ULL, 
            0xAE9BCD9791CD1B56ULL, 0x9112682AC7231377ULL, 0xBD932F05C0883B0FULL, 0xA34BEB94C19850C7ULL, 
            0xFFD26C27B347FC17ULL, 0x1402A361702BCA80ULL, 0x9112BF9C44F5D023ULL, 0xDD34BE48D13C6D53ULL, 
            0x7FA2C3AFF8EFB975ULL, 0x4F27A95CF76074DDULL, 0xA1CAA64A3B12CE89ULL, 0x53DA81A144D214D7ULL, 
            0x1F2516475F3111F6ULL, 0x52341177F7539D60ULL, 0x5E676F457A1279C3ULL, 0xCD9B68459C5B02FCULL, 
            0x49F4506EAF94680DULL, 0xFCDCBD57A292B1C2ULL, 0x4AEB622C32AFFAAFULL, 0xFE9F0E70E2F5F33BULL
        },
        {
            0x7D755E0B244552FAULL, 0x2D8D6ADEA7AFAE89ULL, 0x26174D3E0BF7D061ULL, 0x9A08F48683E6A72FULL, 
            0xF47737FCF10C8642ULL, 0x7775A3F9FB52F5EAULL, 0xFD13092A6A574DECULL, 0x10B926BA736B2CC3ULL, 
            0xC41E14B4CB18F8BFULL, 0x91543D129D1960E8ULL, 0x375195E4920A3D1FULL, 0x09B5A2A09FBEA4E1ULL, 
            0xA3D49592A5CE32A6ULL, 0x81B785AEF5ED3674ULL, 0xBA026CABA7361B08ULL, 0x54FBA83D0B853C13ULL, 
            0x42C205C097108CF8ULL, 0x98DA4A1864D5AA68ULL, 0x9E33D6273F61E499ULL, 0x534A4C1C7BF83F44ULL, 
            0x9FFB5F7896F03CD8ULL, 0x9F5C55094904375BULL, 0x0B273E8C6CA38706ULL, 0x17169B0527C13270ULL, 
            0x21E764850C15DC38ULL, 0x48DDE43D6638D882ULL, 0x131F7610A35B1CD9ULL, 0x2145DF2E074755BDULL, 
            0x650D56F2F7237D8BULL, 0x71EA4D9566216F81ULL, 0xED405193018F79FEULL, 0x556F84D562AE7BAFULL
        },
        {
            0xF96D726645970066ULL, 0xC2C454B2EA01AD54ULL, 0x30ED4C3672BCD82CULL, 0xFEC69ECB3B2AEBFEULL, 
            0xFD2D37389BCAF822ULL, 0x8E124CBFCD4F5C4AULL, 0xDCF8CC74FB309C33ULL, 0x9CD5589088DB0435ULL, 
            0x003AD1CBA9CD6DAEULL, 0x083BCA7275E2AC41ULL, 0xE2253A819AD127A6ULL, 0xA481048ADDAA0542ULL, 
            0xCE1A581630B794EEULL, 0xFD58D2BF40C574A9ULL, 0x7B1877E3A4D70168ULL, 0xF03190F1AC40167FULL, 
            0x3418DD8E56EE5E20ULL, 0xCBA4665912ADBB9FULL, 0xB51BB2C69320179BULL, 0x47CA93AFCA2330ABULL, 
            0x05E871923D271347ULL, 0xD902B355D681218DULL, 0xE26FB320A85CC7A9ULL, 0x0B519F030468D351ULL, 
            0xD7A2E430C52DBBF5ULL, 0x5BEB99D60981BF75ULL, 0x3B58D05696EDD2D9ULL, 0x933C9D376859E55FULL, 
            0x213D0C004342D51EULL, 0xAD6ED0AD2FD21276ULL, 0x3DE1113BE4A63F77ULL, 0xBD9DC901F93645C6ULL
        },
        {
            0x478C15325FC6EEE9ULL, 0xD2C294BF23CD2813ULL, 0x4FA3744E3256D4B3ULL, 0xB7E3365008E9EE40ULL, 
            0x2EE00E7F2C25A8B4ULL, 0x24325665F33DC033ULL, 0x2A91A30376066608ULL, 0x2F049254EC0698ABULL, 
            0x80AA1F2958BBDEECULL, 0xF95A267B19116D94ULL, 0xBCF15D942CE0A144ULL, 0x5D21753B1E90BA17ULL, 
            0x2F14D285110ED46AULL, 0x7F88BF779D96C1FBULL, 0x24990AED12964376ULL, 0xB75EBBC422F85CFBULL, 
            0xC1FD07DD504E0DBFULL, 0x7852CE460F618502ULL, 0x5A2A528B25002B4AULL, 0xBACFEDA2C9FAAA73ULL, 
            0x8079AB0179DF8770ULL, 0x31D9CC0746A640D1ULL, 0x74A6230E96950343ULL, 0x5499FFACBF029E45ULL, 
            0xF2CDA68D2E961FE5ULL, 0x97F99DAA1F71B4C5ULL, 0xD4C2CD99207F905DULL, 0xCC6470C1F35BA34AULL, 
            0xEA6D7272C5F810F3ULL, 0x27DD4AF65FD6E9C2ULL, 0xC412533C76C9764DULL, 0x79E0A58E18202065ULL
        },
        {
            0x8AA3E767B73C1FCAULL, 0xA377C2B806299CF0ULL, 0x5EC697803C050DF1ULL, 0xD5B6F7F2654815F8ULL, 
            0xD55754ED6C76B76DULL, 0xFCA24187F65266A2ULL, 0x338A61FDE2FA0650ULL, 0xBB23AC8EE7FFDF0AULL, 
            0xB5F170D3F45E58E3ULL, 0xF366A65789F60358ULL, 0x8822124A07DB91A0ULL, 0x43BD5B299A6640C0ULL, 
            0xC3CC158B66B807B8ULL, 0x9B6AECE0357148E8ULL, 0xDD9F04B55DD8CF23ULL, 0x565BA5B621AE4EF1ULL, 
            0xFEF48441C31EB012ULL, 0xA87D0A6566B05189ULL, 0xE9397C7F3F3E7E0FULL, 0xAE2C4CC101A3BFC7ULL, 
            0x5584FB3572F56C4EULL, 0x3474C3884426F9A3ULL, 0x0DAE9DAB7A0E32E2ULL, 0x45FD5F13DDF28E52ULL, 
            0xD1802EEFB422A623ULL, 0x10D5C0838622C84CULL, 0x4664E9C28D34BE4EULL, 0x14A7CB7E9CAAED55ULL, 
            0xECD773F3AD7CC6A5ULL, 0x9B67524BF157D7D7ULL, 0xCD6D503F69EBD7E6ULL, 0x05BAA7E1A83B338BULL
        }
    },
    {
        {
            0x2152BAE71268CB50ULL, 0x5E2D6860837E25B6ULL, 0xCA53376053162B34ULL, 0x8E37C85297F6975AULL, 
            0xA39EA62C773B82F2ULL, 0x95DBAC583B3020D4ULL, 0x98F42D88879C3F0AULL, 0xC9B698E51B8B27F5ULL, 
            0x8330D2767C8E6A23ULL, 0x8EE68B3257E3475BULL, 0x1B2F19787854AA5EULL, 0x864877F3F5AE0B94ULL, 
            0xCE483CE881B62E3AULL, 0x9119142584F3A79FULL, 0xCD9DCBBB509CAC27ULL, 0x4958EB4D11FC9AB2ULL, 
            0x6D0E66C8257B58FBULL, 0x58DB99B4919A3EF8ULL, 0xD94DB94E477B85CAULL, 0x18C456F4EE726F92ULL, 
            0x7781C55D77FF65F8ULL, 0x7382DD5EED7D885AULL, 0xE2E396A0F3063E1DULL, 0xF4AD41DFEC02AB52ULL, 
            0x05CC234EEC31D528ULL, 0x61A2B3F8D7D4D507ULL, 0xDB6F4304E9D9C153ULL, 0xE4668ED2322DABE9ULL, 
            0x7A4A7F27E4705F4EULL, 0x400781AE27BFC879ULL, 0x4B808D41ACA3B095ULL, 0xEBB03F6F58AC8929ULL
        },
        {
            0xD44A58AF464EE927ULL, 0x51667046F08F9304ULL, 0x287B4D95390C8A7BULL, 0x960D89FB08D4F5BBULL, 
            0x99CEF795655568C9ULL, 0x7A532A94EBD2D25FULL, 0xB0511FB1D134106BULL, 0xD744CCCCE06BE116ULL, 
            0x5481537EDA240ACBULL, 0xB947E02413AFD53CULL, 0xF8E1152ACD1A149FULL, 0x411C95AA97471AC8ULL, 
            0x405BE423689466A3ULL, 0x85DE07ECB74502E2ULL, 0xCA3B535B3EEAC353ULL, 0x8FFFB58D535CC7D5ULL, 
            0x6B0A73F8763F2D9BULL, 0x1324A1107B7BA718ULL, 0xFFC75C195BE73C13ULL, 0xA0B5B99D25E1E1D9ULL, 
            0x6464B00181107913ULL, 0x1C197FD22A3D92B9ULL, 0x5695D53A058363E6ULL, 0xB9F804C7713C9AF7ULL, 
            0x5C21C1F0785D846DULL, 0x4F6BB72D6B761DA9ULL, 0x219E5012F4A94D26ULL, 0x6D9FD2FC669351C1ULL, 
            0x314714A5B1D54703ULL, 0xE1E6554B8DE48723ULL, 0x8444496188215759ULL, 0x02FBBED025E206E8ULL
        },
        {
            0x2F0DB3BBA2C9B044ULL, 0x6EB295F88CC226A7ULL, 0xCA35AAD9D1615E38ULL, 0x02BC95F697C1B3F7ULL, 
            0x2587E4BF290E3029ULL, 0xB9B0F9180075AD22ULL, 0xC6EEED422BA07E75ULL, 0x2FC5A55685A050C2ULL, 
            0x847B745B7B8FF4D9ULL, 0x4B45C24F59CDF1C1ULL, 0xF369AE0627F1A7B3ULL, 0xF1C095E25C2D72F8ULL, 
            0x8EC0E8F0086DF26EULL, 0x1F7B0880B417F504ULL, 0x857C63794B6A17E5ULL, 0x99139B20B182E95CULL, 
            0xD7FF0D87DE8E6697ULL, 0x08F3133DACCCF83EULL, 0xFFD8B134807F4354ULL, 0x6F269F8F3B1BF266ULL, 
            0xD0EDA5EA74D0BB8AULL, 0xD756590ECF113B4FULL, 0xCDF7C2BEF5AA33CEULL, 0x716424405E9E4477ULL, 
            0xF39989ACB422E2D4ULL, 0xE6ECF555A5A3B769ULL, 0xD6DD2737D27F4778ULL, 0xAA0FDB1A950B5999ULL, 
            0xAB616CDB4AD79583ULL, 0xA3174772BB1C984EULL, 0xC53E77AE5581DE0EULL, 0x681BF602A94574FEULL
        },
        {
            0xC726E7F432130E7FULL, 0x02A986C2BF1D9C08ULL, 0x8781D794E906D4EAULL, 0x519FC3AA086C614DULL, 
            0x79EB27F99765014CULL, 0x282E9D387649F20AULL, 0x5FAC4F8AC2F160DAULL, 0x529DD5F159068D67ULL, 
            0x85E3108724B59B10ULL, 0x7BAE05A0073008A1ULL, 0x043048D6C1A3F3E8ULL, 0xFF5EAD814F7D2F09ULL, 
            0x9100EF2E94A78B6EULL, 0x82624DABF30D8352ULL, 0xB623FD5F561F57D7ULL, 0x6094CFC63F02F0DCULL, 
            0x0B0EE8870C2D0688ULL, 0xB334CE0D0204EB5CULL, 0xAA37F8796170C9C9ULL, 0xD9606A50B466B848ULL, 
            0x11D1728AA2CE5823ULL, 0xC79DD8A16B65C295ULL, 0xE22EDEFA081B5663ULL, 0xD75531041980B64CULL, 
            0xDF1A3A47415315E5ULL, 0x20261B008F4D991AULL, 0xA0AC3B9CE4C4C4F7ULL, 0x4F12508FD20BA8DCULL, 
            0xCB95F8D917CB2C69ULL, 0xDBCA9F21825BC5ECULL, 0x7A77F2697061EFCBULL, 0xA3F95059532B58A6ULL
        },
        {
            0xA47807E93D7C8AB2ULL, 0xB9F1208DC0551084ULL, 0x2F69813114E66AB2ULL, 0xF3B9CFF30E550F88ULL, 
            0x4ABDF58F33EDB55EULL, 0xFC069A47E22E6134ULL, 0xBC3412A21AE58F8BULL, 0x88974C31B14DD858ULL, 
            0xD74A7DB7FF7FF460ULL, 0x3AA0E8DDCC72282AULL, 0xD746574D5FD87C2AULL, 0x545F5162FB19BDF9ULL, 
            0x48854FA499D2FA6FULL, 0x85B0F607909A3C01ULL, 0x1CA2D5961B54D926ULL, 0xDC18787CB7CCC9F7ULL, 
            0xCF8F91BF9D39839EULL, 0x6A17F2A673477588ULL, 0x884EB2DE38EAC338ULL, 0xA29A273A1C025A97ULL, 
            0xEDE95E5A77C72704ULL, 0x3494D05B4718132CULL, 0xF006A3515855913BULL, 0x9A7042A9BB0FBF43ULL, 
            0x806ACF399037E4F2ULL, 0x80F0FD0F1DA070A6ULL, 0xC4FBE48DEE26B432ULL, 0x6932D43B6201FF1DULL, 
            0x928A2914F33DDC98ULL, 0x2054F8006C22FB73ULL, 0x6F635752C1377153ULL, 0x119469940F66A93BULL
        },
        {
            0xB3FA73620AE0F8BBULL, 0x42A12F32D9F8A718ULL, 0xE694BD540A080D56ULL, 0x17CF16F8D1CBFB8DULL, 
            0x83357B6E50871CD8ULL, 0x3DAA886F6AF665F0ULL, 0x5104F5A74D7F6913ULL, 0xEEB3753E188B24D9ULL, 
            0xB25BD2D08A4E77D2ULL, 0xD8B28AC4DA4F47C2ULL, 0x3D6561D234FF2C2AULL, 0x17BA9FA6B647A415ULL, 
            0xCFD41220E1D9A4FCULL, 0x5BD071717F19F0D3ULL, 0x661E510A2AD8917BULL, 0xA56E288421A76B27ULL, 
            0x67EA53F11642717CULL, 0x20C826C4929B0742ULL, 0x62C96E60C074A090ULL, 0xDFFFC94960C6AFB4ULL, 
            0x8D4E96562907A535ULL, 0x64D4DDA4E2749F49ULL, 0x6A64BE6C67C01E57ULL, 0x648A166DB728CEBEULL, 
            0x7DE47F344D419D0DULL, 0x0AC83FBDA559133EULL, 0x1180BF3F3A10BF3DULL, 0x819CC6ABE1A167D6ULL, 
            0x5A2AB7AABA68B841ULL, 0x26DD3362938A0DE5ULL, 0xBA1C69FE9D2BF1E9ULL, 0x736DA4F23838C0D2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Naos::kKeySpawnAConstants = {
    0xD70C20882EFB4F89ULL,
    0x54D3FDD2F6D09DFBULL,
    0xD29258DA96FBEF88ULL,
    0xD70C20882EFB4F89ULL,
    0x54D3FDD2F6D09DFBULL,
    0xD29258DA96FBEF88ULL,
    0x47F1AB684C4E7DACULL,
    0x7D52CEC4E0B43D50ULL,
    0x1F,
    0xF8,
    0xD9,
    0x74,
    0x96,
    0xA5,
    0xB7,
    0xC1
};

const TwistDomainSaltSet TwistExpander_Naos::kKeySpawnBSalts = {
    {
        {
            0x83C1282CC5543317ULL, 0x6265A28F05176FAEULL, 0xE6AF3C005D909BE9ULL, 0x30146DEBBE14A0FDULL, 
            0x2C2772418169B8F9ULL, 0x43C4233025FAC28DULL, 0xAE728302F0019C8DULL, 0x9591014699F4B73DULL, 
            0x030B5245F32D476AULL, 0x9B6B6483D8FE648FULL, 0x3742B450C82BDDB4ULL, 0xCCF80F08CB303096ULL, 
            0x2B893A82F9F13EA0ULL, 0x0533A213FBFE474EULL, 0x49E2059568A2CD64ULL, 0xCE124A181054E57EULL, 
            0x840F53B4E0348DD0ULL, 0x58C51F51404C1742ULL, 0xF5EE46B021F9B97FULL, 0x4FB85955C7DFE4B9ULL, 
            0x8F545366DAC6209CULL, 0x3BE4D732CF068538ULL, 0x2375F9657DB068DCULL, 0x55F67E4A48241476ULL, 
            0xADF041726745E358ULL, 0x2699E41F4EA98E73ULL, 0xCE3E6C789448A1AAULL, 0x3AD48502A6089D3DULL, 
            0x8EC5086459B10E2CULL, 0x4DE8CD140D3C0D2DULL, 0x78F34BA1AC1DBE51ULL, 0x62357099D4B91ABBULL
        },
        {
            0xC29B19D5B4907F92ULL, 0xFF1F75E9E35EED69ULL, 0x7E65A3CAE0765905ULL, 0xD8A793A2F4E041B7ULL, 
            0x691558C2619031D3ULL, 0x94492072FB3C58BFULL, 0x80DBB5CD620B4862ULL, 0x2DEC5A48DB0FA10DULL, 
            0x282013E1CFA4C3E7ULL, 0x7CAB99BC911537C0ULL, 0x1F78962033234D5EULL, 0x11E52B0FF3045C5BULL, 
            0x49F61AD1516F4290ULL, 0xFBF26CC05370C239ULL, 0x9473A1F1CE2E45E8ULL, 0x53D6C124611FEF06ULL, 
            0xF2F983D24E1B2EA6ULL, 0xB39F2AB20D8B0184ULL, 0x85700440000BDFF6ULL, 0x32B6DEF51BAC4D75ULL, 
            0xA174E2B4502E69E0ULL, 0xE29CEC92977831C1ULL, 0x3E4AD1E690F6DA42ULL, 0x0465F0D08D49D71EULL, 
            0x9B8CDDBF5A746775ULL, 0x177F93FCA89B6B51ULL, 0x0B7A099ACDDFF4E0ULL, 0xDA7AA3302BCAC2ECULL, 
            0x13CEE3AC4F7B5D48ULL, 0x8B23E17CE5FBB2D4ULL, 0xAF546F8090E7496EULL, 0x00DEBF41089F904AULL
        },
        {
            0x37A9CCE475743EEEULL, 0xE1EE41CA457281F3ULL, 0x4EE9DD1E01EC3E30ULL, 0x98E2B2C32DCB8E3FULL, 
            0xAF793D17E872ABFFULL, 0x17F35F6A68922984ULL, 0xE843E9815F4EBD06ULL, 0xD4D80F281C5C88F4ULL, 
            0x93F822E4E31FCC34ULL, 0x46ACF91450B09E7CULL, 0x4C62D67C7E143119ULL, 0x3E0AA8C8605C25D6ULL, 
            0xAF7F3D47E167CB51ULL, 0x85ED97F52D359EBBULL, 0x28D536456BF990E8ULL, 0x49D33404025C9098ULL, 
            0x18691DC33ED01C44ULL, 0xA13FEC926A825F57ULL, 0xDA49C6B64503A72DULL, 0xEFA682763488F4B3ULL, 
            0x08F69ED3A89B7FA3ULL, 0x1093714ADC4368EBULL, 0xA3EDA560EDDD8ED6ULL, 0x19AB9234E7F3F774ULL, 
            0x19D60C2B0E79CC28ULL, 0xE2933B2F292FA2D9ULL, 0xB8114E690853F5B2ULL, 0x13B72D619941DAB5ULL, 
            0x147618B032835D68ULL, 0xCB71F7D572950D76ULL, 0x8E282ED784873E79ULL, 0x604879460EB7A216ULL
        },
        {
            0x7C6C74B50C257AD7ULL, 0x76CAA5F1A6AA4372ULL, 0x203C2E257CC85FC2ULL, 0x1946C74E2A94122FULL, 
            0x5F2FF89B9ADA15B9ULL, 0xEEBB4DB4C1FC7311ULL, 0xF41DD8EEEA973D52ULL, 0xA5A38C07BEBE6370ULL, 
            0xFB23346C6A610DE5ULL, 0x100AD2CCA58A20DFULL, 0x2394EE2A4489797FULL, 0x5A32C74517D3D1A9ULL, 
            0x2281C378C03E2C3DULL, 0x35C13776FAD69B31ULL, 0xC1AA47F38AF33B17ULL, 0xBB53582062BEA606ULL, 
            0x467FF6F1A62043AFULL, 0x0248A87EAD8F676DULL, 0x7106A42693FD777EULL, 0xB40EB8751F5B51F8ULL, 
            0xA2AB00F62BDF7FCCULL, 0x3BC6E0657C8C0187ULL, 0xC7289FC363F351F5ULL, 0x5EE8DFDDE9898D50ULL, 
            0x9EFBA23BB0C34875ULL, 0x127C0FC7C7AC80A3ULL, 0x3EC0728E4E8B5844ULL, 0x4DECAF6330D3F836ULL, 
            0xC9262E4A99562608ULL, 0x61C97B06D547EEDFULL, 0x820D3FD4BBCE7505ULL, 0x85E9EBC032B3230BULL
        },
        {
            0xBB960FC2EB6706FDULL, 0xD2CB6B04E4DC50EFULL, 0x44D6EB0DA7734FBCULL, 0xC73D27179EAF3BC8ULL, 
            0xC4D595AD1D5AD383ULL, 0x926EE8DC6D295F0EULL, 0x8ACC41C96C2BA267ULL, 0xA2213FA358FD87C4ULL, 
            0xB60208F55CF684EEULL, 0xE57514F95FE3AAF8ULL, 0x925335E0FA0E5B50ULL, 0x23BDBABB2C13F2C7ULL, 
            0x3BE4423E2B1479C2ULL, 0x372798FF988CEBBBULL, 0x99B8BF142D54EF6AULL, 0xE3584C856E65EBF6ULL, 
            0x1BCCEC59CF1C112DULL, 0x2F7F94D4A1A9091EULL, 0x046A4A5276A4F7BCULL, 0x20E61C6AD13BFD34ULL, 
            0x4AE657CA7E47E27FULL, 0x29B72BF95D78614FULL, 0xBDF7951464247CDFULL, 0xC56083EE0E337328ULL, 
            0x30E1EE82661C191AULL, 0xFEDB0F2AA2D08920ULL, 0x6CCDE60EDA93F721ULL, 0xB0D0913C468247FEULL, 
            0xD528C2BF1336EE87ULL, 0x986D67F0BDBE11C8ULL, 0xFED81AE43598E216ULL, 0x9086B3C24B7E7FBFULL
        },
        {
            0xD79918425052C2EDULL, 0x1584F93862ECE0F2ULL, 0xD33DAFC34A1A6B99ULL, 0x24A266E46C33670FULL, 
            0x66630195DC1F24F3ULL, 0x48D1CA7F6F270FDDULL, 0xDE6FA0E8218637C8ULL, 0x61F6ECA0FE1990A5ULL, 
            0x18F374DCA4891923ULL, 0x3D80152151246E37ULL, 0x00FC18FA3362FDCEULL, 0x7B4979220C9187E4ULL, 
            0x6E501557E70AA335ULL, 0x2FEB26524B97F3A6ULL, 0x1041BFEE10D5FC80ULL, 0x0697513B02197CE4ULL, 
            0x0724233BA327597AULL, 0x4F6A65EEF1C7C23AULL, 0xF4761C54D27468E6ULL, 0x2E9CB7111A8B50E0ULL, 
            0x748C2E3032C3CE0AULL, 0x18BA424E132D5026ULL, 0x9A85ED8EDB6D58EAULL, 0xB834E3BB14D156B7ULL, 
            0x7E4F7BC711B5ED81ULL, 0x429687ACDEA2842FULL, 0x67DFDFFFC7656AADULL, 0x6CB2A1467E22D2C8ULL, 
            0x01ECE62639DF195DULL, 0x1013F33A316DD55CULL, 0xD661558F7B85B0C9ULL, 0x88FF1219A6C5C6A9ULL
        }
    },
    {
        {
            0xB436090004E0C954ULL, 0x6EA7AD33445B2C27ULL, 0xC239BBAB7301FC89ULL, 0x26FF3E910F6C9ADBULL, 
            0x61BBDB91DDB958B2ULL, 0x306C66B0636E4DCFULL, 0x3A35FF8339924909ULL, 0xF35B5A528B577C86ULL, 
            0x5719AC819798E3EDULL, 0xCA23A1B610DCB54FULL, 0x5E388B8CF14AC855ULL, 0x71CD0CAF04A5F495ULL, 
            0x5BE210F6714FAFF1ULL, 0x6AC9993FEDBC8158ULL, 0xA52B0BDEC9533008ULL, 0x067B3732B91B89F0ULL, 
            0x7557A6DCD130866DULL, 0xA2609CAFC1C5EC63ULL, 0xC2C62A7AE81A253BULL, 0xDEBC0355714207AAULL, 
            0xDE782745730D430AULL, 0x338DFAFB055F9B8FULL, 0x1BDB9EC5B7D79B5CULL, 0x0CC849EEE6129C1BULL, 
            0x0B0DF883E4FC365FULL, 0x74D2494F060AFCD7ULL, 0x6DC5A2BF229259A3ULL, 0xE6F7C6EA18E49A7AULL, 
            0x3F9A94B5CFFF3F21ULL, 0xFBE9C41F1EE9AEEFULL, 0x95AE430A85A0A30EULL, 0xD379DB1102AF63C6ULL
        },
        {
            0x6CDEC78F7F1AE359ULL, 0xB74910C20A548595ULL, 0x5D209BD6DFE2F51CULL, 0xAF5ECFBB162DE6F0ULL, 
            0x3408C81CCEC06EA0ULL, 0xE1A54614EA261CDFULL, 0x4DE53451E9E3945BULL, 0xC354B708F9A65D14ULL, 
            0x4E089714F23F4B3EULL, 0x03B0ED90B4B33E75ULL, 0xFE036A8E654869CFULL, 0x44635FE38BD09E20ULL, 
            0x90CB2BEEBDC6133DULL, 0x7989708065FA7AECULL, 0xD5C88A2D8052312DULL, 0x007CBFB26992F8E7ULL, 
            0x2818DC38D8860487ULL, 0x073A607A521A0BF7ULL, 0xA272C1FB70AFDD5EULL, 0x90565F409EFDB288ULL, 
            0x9A312E0F7553D976ULL, 0xB24D123F91DA40D5ULL, 0x907B91F0DB717D9DULL, 0xA4D7F5BB2800720AULL, 
            0xF6CCC973D7DC6444ULL, 0x61FCEC3B44A43A95ULL, 0x5FB7602A674C7B47ULL, 0xA27E0A4F0F872E89ULL, 
            0xA6DDF033B98BAE4FULL, 0xCC3BC63CA0A9044EULL, 0xA870BA4EFA090BF9ULL, 0x7517F5867E6525D1ULL
        },
        {
            0x8B65919802279C49ULL, 0x90E608D7F81BCCBFULL, 0x145C5E606A80E9C8ULL, 0xD5A8B19797F3DB57ULL, 
            0xEACE703DED9639EEULL, 0x37D5B0EBC5C842B7ULL, 0x7C0898E6362399B5ULL, 0x003ED0436625F8A5ULL, 
            0x2AF4A0EA52673869ULL, 0x61B0040DA60D1ED9ULL, 0xAB78E6CC14BD36C9ULL, 0x7EAC9532A41D17E3ULL, 
            0x9DB32D3BE6F8B55CULL, 0x4657665963240002ULL, 0x22346969790110D6ULL, 0xBA6A9205132AAC4BULL, 
            0xD0BABD958AA93E32ULL, 0x650C8AB29730770EULL, 0x9B90AE0C022B6B66ULL, 0xB2510DD4074EDC51ULL, 
            0x78AADD1A3BE514A7ULL, 0x512B1EB53E934AF2ULL, 0x6008F9F967677BF8ULL, 0x587042197F658480ULL, 
            0xD5DB3C1A8F01B7BDULL, 0x2B2A8F715B068C3AULL, 0x334E4878E5C70399ULL, 0x93FB58B6221CF6CAULL, 
            0xA193318E6E8B009BULL, 0xB61362E45B807DD8ULL, 0xAD838ADC3260CC6EULL, 0x25771D27DE6F9F11ULL
        },
        {
            0xE76FB19DA1F07FBAULL, 0xA983396E94CF0863ULL, 0xEA16B17F4D49C8C2ULL, 0x91AA5E48918B7A10ULL, 
            0x73D751F3B893A04FULL, 0x9828E1AB662FA9C8ULL, 0xED1564C6052CFA61ULL, 0x7F9DBB03BE5A480DULL, 
            0xBF55128DCC5C6D5AULL, 0x661035BD380CBAA7ULL, 0xC0A41875F484015DULL, 0x0CC53589B5DD532AULL, 
            0x2FDA5CA14C42AFA2ULL, 0xACAF9114C240123CULL, 0x0A5E476D435DD5F9ULL, 0x8A8ED4F94833BC17ULL, 
            0x499475C6AB3C30B9ULL, 0x34F533627CA5FB01ULL, 0x7B05AD976452DCB6ULL, 0x51EA152910751E33ULL, 
            0x28F798ABEE26BD84ULL, 0x3FAF5BEDE5CBEF11ULL, 0x27E996B8F797FB35ULL, 0x8275DCA3B5453FE1ULL, 
            0x8258D6C91687B17DULL, 0x85B03E6A52E6E660ULL, 0x2291A15E828B3AEBULL, 0x863BFC70CD521245ULL, 
            0x53509CDC3FF62822ULL, 0x7EB6A1A4B6FA6B72ULL, 0x02047F566F8970D1ULL, 0x6CBEE12D8930AA08ULL
        },
        {
            0xC159CBD7FF09EC61ULL, 0xA7C3082805EA35C6ULL, 0x3C0E1BE1CE28AAA2ULL, 0xF2D1CC7CB6043008ULL, 
            0xA49B629C8DFB3EEFULL, 0xDA4C60987B98BD9FULL, 0x6E6DE3CF2BC62CBAULL, 0x854B4F1A2235A26DULL, 
            0xEE1EE1419C48B258ULL, 0x43B4CCD52CD9A36BULL, 0xB5DFDC78F12C6857ULL, 0x976067EEC021B34EULL, 
            0x8D399F7E8FA726BEULL, 0xA5C937BA18B696A0ULL, 0xE5EE42309FF43570ULL, 0x6226F18A31A90BBBULL, 
            0x73038A8BDD18DE48ULL, 0x7FBE21A2ADAAA1BBULL, 0x49BC3E2C794DCBE7ULL, 0x4DF99559FB9DC73BULL, 
            0xDC69B8375FBFC77BULL, 0x804501E3181D0173ULL, 0x930D0C65A225C7A3ULL, 0xBAAC02C7F9CB3194ULL, 
            0xC067CE392F7428BDULL, 0xC3E66941F46743F7ULL, 0x59535D342387B990ULL, 0x340B172F05B92845ULL, 
            0x3BFFD487287E0C89ULL, 0xD5BAD4EEC4FF0CB5ULL, 0xAFCD5A72B690A83DULL, 0x91EF5E2C721889A0ULL
        },
        {
            0x68B6DC7728964E97ULL, 0x18699BAA764DB989ULL, 0x860E52C79BE2A19CULL, 0x73DCDE17CF5E416EULL, 
            0x351B4DD05D18A82EULL, 0xA2266679754BCD6EULL, 0x8339C7ADD76C78A8ULL, 0x18997AD6E8F4BD59ULL, 
            0x7AC9B57D846EC9FFULL, 0x073B7F86D4CCCD57ULL, 0xF065FE007D80F9D8ULL, 0x8CF5391C4D734617ULL, 
            0x567EA12A9514B637ULL, 0xE90F10A21F4943BFULL, 0xB4E88983AEB67172ULL, 0x6A775C61D1531426ULL, 
            0xF006BA81DCC4BD94ULL, 0x6456C9A0EC42A78FULL, 0xD0B06AB54021D44DULL, 0xC742631DB5573D5EULL, 
            0xD7A860BF0A8A642DULL, 0xDC14FA4E318E5829ULL, 0x5D0F6655CF4BB38EULL, 0xB746C427CF86C6C5ULL, 
            0x3F28507650CC602AULL, 0xFBAE7D168C653E23ULL, 0x1B63B37C24509D02ULL, 0xD33CC56E5A0990C2ULL, 
            0xE2A1E873919B8EFCULL, 0xF640B89CDE941AADULL, 0x315272B23243C75EULL, 0x712FB5A25FEF32D2ULL
        }
    },
    {
        {
            0x74F93FA770929408ULL, 0x4AF668DBE84A3CF6ULL, 0x4915896BF70D7AC0ULL, 0x27B9FF7E246A869CULL, 
            0x943621467AED9B3AULL, 0xFD4F235D584071F8ULL, 0x8635978FA14A2A68ULL, 0x255289AADD22BB88ULL, 
            0x6CC0D92065E4D8B9ULL, 0x1410BFC2203A4D6DULL, 0xD2F7DAB21C507698ULL, 0x3B7F4DEA9CF83AABULL, 
            0x20167348ED1DD21BULL, 0xC8D921BDBC3D0E73ULL, 0x24B5E6101C560578ULL, 0xBA683D0CF690285CULL, 
            0xE394E386CE949A96ULL, 0xAE51DE4B20919988ULL, 0x7EAC6C3C149276C5ULL, 0x02A341D1668C68FDULL, 
            0x6BA544C028DDD7FFULL, 0x5260BB35231FB137ULL, 0xD1324BAAF1CE8B16ULL, 0xF1FC1E2103BA38C3ULL, 
            0xD90E151219D2C8D7ULL, 0xC915EBABE54F7834ULL, 0xAD01623380CB1A0AULL, 0x8C9BCECE83DF784CULL, 
            0x8C08601C63E61582ULL, 0x9CABAE02C24B6274ULL, 0x9E009619E27B960AULL, 0xB3693174854FDD02ULL
        },
        {
            0x964FB985B6ADCB41ULL, 0xD413880216A51BC1ULL, 0x0740010DF5812BEFULL, 0xE1FA4BBD8BB4B9B9ULL, 
            0xB0983FE282590EF4ULL, 0xFE9FD14B5FE7614AULL, 0xE37ECDAC157939B5ULL, 0xB7968300ABFF7BA9ULL, 
            0xA87B8716F36B1EFFULL, 0x06FBED1704712F25ULL, 0xCFCF5B5A0388A54AULL, 0xA2978D7B149B0F5EULL, 
            0xBB044F5381F0F201ULL, 0x08A961E99F9771CEULL, 0x752A680117035518ULL, 0x875FD45A136CDD66ULL, 
            0x71E3296FBE067298ULL, 0x8A0DF8940E879170ULL, 0xC092AC3B031A6EB8ULL, 0xB95E18AEECA314E6ULL, 
            0xF2BE83EF7C27A1CAULL, 0xFF74C41CAE2BFA14ULL, 0x2B796C0B12A903FFULL, 0x6E73BAE69C1B390AULL, 
            0xC2A75D9CC3D5CC7DULL, 0x4D15687E529B8033ULL, 0xE34F86D821551891ULL, 0xE8985885843219C4ULL, 
            0x4FBB50437297663FULL, 0xCB2D2D743D89C74AULL, 0x7A5136649AF9A552ULL, 0x6A7590AF7D0935F3ULL
        },
        {
            0x8D7BA4F450617B8BULL, 0xC8564D66D8F619FAULL, 0x7023B6831CB9602CULL, 0x7EDE38A30C0C7304ULL, 
            0x3F0A1467D9B648DFULL, 0x327F1030C6E6EE6BULL, 0xE893700CF930AAE4ULL, 0x33A903A79E27C8B7ULL, 
            0x29BBB55640C370ECULL, 0x4E9B79B86CC87F3BULL, 0x1A942597111A4998ULL, 0xFEF5C32B01F23C92ULL, 
            0x0CEAB6095201656CULL, 0x2E671DFBD03DEC13ULL, 0x30D205695C50209DULL, 0x7B3D9A543EA70962ULL, 
            0x95445548A1F64AD0ULL, 0x3148462F7072B252ULL, 0xCC3DD827A604662FULL, 0x9284AFC7165E1013ULL, 
            0x9B118A904F4C434DULL, 0x753638ADCC0659B4ULL, 0x2A33EE75CCDBBD20ULL, 0x5F71D998A99969A5ULL, 
            0x12A7BCC4D7196858ULL, 0x9337B363170791EBULL, 0x528EEE33BA1EFEB3ULL, 0xAE129CCA2331AF00ULL, 
            0x7B000C7055D6A671ULL, 0xEEADB66F2DB3395AULL, 0xBE9728CD325D415DULL, 0xF9AFF892EB55FD7BULL
        },
        {
            0x70127DCE1DB4693CULL, 0xCEDCD84FF55006EAULL, 0xA06276720C622D48ULL, 0x124B77EF93FFF864ULL, 
            0xF0C4DF74424DCB22ULL, 0xACDE01C815D21628ULL, 0x88DA34AE13918F32ULL, 0x3D6C981E6B838EF6ULL, 
            0x0AC4E36AD6A41826ULL, 0x3C0DBAD71B4D1CCFULL, 0x6929F7E6D4BBA394ULL, 0x171CD7B14DCBC4F0ULL, 
            0x30B9F5980F97D5F0ULL, 0xD12EE2D16C813584ULL, 0xF6A9A0E1F08C5A44ULL, 0xC1C3BAFB049D9651ULL, 
            0x6265E7739DF37719ULL, 0xFD6926DF5CDF0211ULL, 0x94EC25F42A60DA45ULL, 0x32CC48CB3A384DEFULL, 
            0xBBE90DE36F3274D5ULL, 0xAD5BDC779C219923ULL, 0x6A72BC39705DBFC7ULL, 0x4F9193F3EE580F73ULL, 
            0x545A526FF19CB1A0ULL, 0xAA56E65E1F81944DULL, 0x0410D840A2C1A7E4ULL, 0x73348D75B98A50ECULL, 
            0x1FD8BC3D17755000ULL, 0xE708C16E60A6450AULL, 0x2F8E365297AF8A5DULL, 0xD0D69038D1FFC822ULL
        },
        {
            0x4B2DB12C493FD764ULL, 0x428F9C23180D093FULL, 0x906D4BA2BF007B9BULL, 0xBF1D521DEB4306E1ULL, 
            0x37023400D93CB605ULL, 0xFECC211DF46E2B02ULL, 0x4EC4B0983E896DECULL, 0x638328792435BCC0ULL, 
            0x6C12CB3BA6A2C4B1ULL, 0xBABECF7D185353D4ULL, 0x89E67CCD50C6AC81ULL, 0xB9D78956180E839FULL, 
            0x3D6332AEFD9AEB57ULL, 0x0868B6E05EB7A831ULL, 0x4433C377656A2841ULL, 0xA99285B9401DFF3EULL, 
            0x487E07D2F450152CULL, 0x68D4ED811D3C64A2ULL, 0x6A560A16F35E0629ULL, 0x64912A10C6E93164ULL, 
            0xDD5105C6A77694F7ULL, 0xAA21F79C85BD718EULL, 0xF2D48F258862FE85ULL, 0x63928BC5209177B2ULL, 
            0x150FB235D573F492ULL, 0x82225E0C3D87F165ULL, 0x8CB33EA6DAA74831ULL, 0x194D2D2F861FED56ULL, 
            0xD09A9D40E52CA689ULL, 0x68109F9288465F43ULL, 0xF9135598EEC0F549ULL, 0x79924B20D29991EBULL
        },
        {
            0x7656EF9951FC148DULL, 0x33F3058D62008BE7ULL, 0xF64EB3A9739CB932ULL, 0x4A23BAFBD6926133ULL, 
            0xB6E9C14CB76F58E4ULL, 0x91CA813E84C75853ULL, 0xF4A3EE7D898F8A18ULL, 0x33EE592F4F2CC740ULL, 
            0x1CBE0B4529118AE8ULL, 0x9F89F72106A06F0BULL, 0xD5D4E269DFC61F48ULL, 0x5EB528695324B12BULL, 
            0x4C5FAC18E991E4FFULL, 0x4465A178CB09AE19ULL, 0x3C22C8A745EE4D81ULL, 0x259C65E9245B8468ULL, 
            0xEEAA5CFFD813E3A3ULL, 0xF7B25293FE7D1A06ULL, 0xB298F1B413F9A8AFULL, 0xCF69D02090A1CB34ULL, 
            0xEDCD88AF1EAD1FA4ULL, 0x1EB8710BAF48B901ULL, 0x826A914591C7AFCDULL, 0x30559259EF16E175ULL, 
            0xBF3C69588DE8B11DULL, 0x8827E410C8B77D85ULL, 0x4E942CB59DE56861ULL, 0x52A307ACB833112CULL, 
            0xAB00E2D36F9A6CB6ULL, 0x926710ABB6659B2BULL, 0x48704B2832A291E0ULL, 0xF7FFC3DD7BB32981ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Naos::kKeySpawnBConstants = {
    0x80AC119F52942C7AULL,
    0x0E07010EAE2A3CC4ULL,
    0x01278FAC2190AC19ULL,
    0x80AC119F52942C7AULL,
    0x0E07010EAE2A3CC4ULL,
    0x01278FAC2190AC19ULL,
    0xC1DBC0331C634754ULL,
    0xC5DC06AA8E887FCCULL,
    0x60,
    0x06,
    0xA4,
    0x66,
    0x2E,
    0xE2,
    0x5E,
    0x43
};

const TwistDomainSaltSet TwistExpander_Naos::kSeedSalts = {
    {
        {
            0x44B8AE0267155D5DULL, 0x8B78460D8E3A3940ULL, 0x7456D592177BDBAAULL, 0x928790754670D283ULL, 
            0xD522392AB6C00900ULL, 0xE219976FFA32B77CULL, 0x0477260D54DB5382ULL, 0x01C8A669ABE9870EULL, 
            0x8B9FBE4D95307B50ULL, 0x8833F03D23F930F7ULL, 0x35F083D8BD224627ULL, 0x97C0ABC56236FCC1ULL, 
            0xA317C56980691B2CULL, 0x9771318BF1B1BA89ULL, 0x59B6F022B6DF772DULL, 0x6F82233226E014FDULL, 
            0xC07BBC37999249D0ULL, 0xA4ACE2E9068BEEF7ULL, 0xC43AB901BA2BEC5BULL, 0x3D0019B23784B701ULL, 
            0xCDA304130B32CE05ULL, 0xA8D3013ABB1C2220ULL, 0xDC4EF481B6C25766ULL, 0xB9B598A4FE81C1CEULL, 
            0x23337B4FC7E6B6D5ULL, 0xA219223FAD2DED45ULL, 0x6E696BF22F73C19FULL, 0x93248FD92025F252ULL, 
            0xC2AB2CD0ADB56282ULL, 0xC75D3B20A48F8864ULL, 0x2DD0033E650F94D3ULL, 0x7F92AC73E4407547ULL
        },
        {
            0x065FD1C432ABD97EULL, 0xC6284F3C9FBC2031ULL, 0xB4A44ED38853F08AULL, 0x7B317798FCB0AE81ULL, 
            0x05684E7EE0D78D71ULL, 0x19019319EA5FCC9DULL, 0x7BA67518A370B8CBULL, 0x92B68FB36753D3D9ULL, 
            0xDD6F7D7E862E2649ULL, 0xCA2210751D461BCAULL, 0xDACB4A44EF881E9CULL, 0x9DB7EAF16E873810ULL, 
            0xCF8812C16B977749ULL, 0xED90626AA290B27CULL, 0x752DBC0D723A6CBCULL, 0x745C09CCC5C0A549ULL, 
            0xBC75070EC07C8B85ULL, 0x6CB4F235FD901E58ULL, 0xB4C439D3D475AF3EULL, 0x9C2EE7268DA66A18ULL, 
            0x7EC78C5B23EC4773ULL, 0x627A01606ECD8C28ULL, 0x2718CCCFF77B9FE3ULL, 0xA82C8E8551C89BCCULL, 
            0x6D3D4321230833A2ULL, 0x94C0DE780C771890ULL, 0xD6A7FC896DA69DBFULL, 0x9CD577ED2FF5D48BULL, 
            0x988E5784C65DF677ULL, 0xEE17F72A245441E8ULL, 0xAE9DC2FC37546839ULL, 0xCE4B2E48C049BDF2ULL
        },
        {
            0x60BE02A88A484391ULL, 0x4C9F01EE06836E21ULL, 0x9FF15598531F8E67ULL, 0x63BB2CFA08AF45B7ULL, 
            0xC98F2155D73BF76AULL, 0xAC046C46D5206AC3ULL, 0xBAAB5E32FAABF761ULL, 0x9A9F9188636554B3ULL, 
            0x795B4E10075C8B49ULL, 0x15925434EA98F2BFULL, 0x6BA51D0C7CE36787ULL, 0xDC57A578F994A8D8ULL, 
            0x4F33A63F35C04F52ULL, 0x2AC292F2FBD09E60ULL, 0x2D7C09A17B4994BEULL, 0x403246FE03808BD5ULL, 
            0x6DB349D8BEB4A614ULL, 0x03D6727A8DEC7E98ULL, 0x74BAA7EAA0B3F2BDULL, 0x0E96609822263EAAULL, 
            0xC09FF20589FCA22EULL, 0x52C422E2B07B0F0BULL, 0x27BAD51E66BD82B8ULL, 0xDB30B2C48B9D7D78ULL, 
            0xD101CC05A12EC3F1ULL, 0xE5A1B7C168CB0CABULL, 0x4D36A848B4627F2DULL, 0x89844AE4FDCEF61EULL, 
            0xA6261377A295968CULL, 0xAB96B7F05C7224D6ULL, 0xE97D1345ED17C55BULL, 0x21A646DD465C1DFDULL
        },
        {
            0x5CFEE3C86249A8E5ULL, 0xD6311E6011630EC6ULL, 0xAA70F2532D0417D2ULL, 0x33E5889C429123DFULL, 
            0x6F3E7933920B5DD0ULL, 0xD6F12F8BF614C413ULL, 0x686B4681FE1F7D3AULL, 0xC2AB699DBDC2A559ULL, 
            0x38AD748F2204931FULL, 0x603E6D916D1F7732ULL, 0x49C8F0F829660767ULL, 0xDC30817B0CBAFA03ULL, 
            0xCA8927281D2C7EA0ULL, 0xB39521D5DC59D64EULL, 0x7936D54607B2AE30ULL, 0x4B2C91588686A659ULL, 
            0x3560FAE39A412F0BULL, 0xF8B0E348F4221F3BULL, 0x99B983E3042823BDULL, 0x771652A844C04E88ULL, 
            0x296C30A337BDDC4AULL, 0xA978305A6C81CE0CULL, 0xA0308807D9EFC2F8ULL, 0xBED84FDD3EE1C643ULL, 
            0x3F6C1F34D5E34772ULL, 0x7B404F86887DEB84ULL, 0x238C68BDED85FC3EULL, 0x8FBAA4326CB765E0ULL, 
            0x938DC5D14DE33202ULL, 0x7393A53B0B077FCBULL, 0x5049AD4BAE1A9035ULL, 0xBB66255A30BB5F9BULL
        },
        {
            0x1FA3532CBB16FBE6ULL, 0x5CD59747A9B853E3ULL, 0xA7BE3FA6D02CEE88ULL, 0x9EBB45DA9D70673BULL, 
            0x09D7E816AB945ADDULL, 0x2F1FC4EF5ECAF9EAULL, 0xB36468FC95ABA818ULL, 0x74D5FB49DC7B9343ULL, 
            0x47BCA425361F2B53ULL, 0x72D7602EF9772D19ULL, 0x720F95410258775CULL, 0xB525785A8C91384AULL, 
            0x2AB4071E07D89893ULL, 0x77D5611E21AEC549ULL, 0x5F1CDF7CE027382CULL, 0xB8551A331DFDBC47ULL, 
            0x44CAC1AB2CA8016EULL, 0xC58E119C53486B99ULL, 0x1E742C8BD6ED6641ULL, 0xF646936D34747A08ULL, 
            0x725292D5A44E2B2AULL, 0xBC2825825269DB74ULL, 0x4EEA60448A0920E4ULL, 0x0F7F6B57E8CE2FC2ULL, 
            0xFD536D4BA7D4A19FULL, 0x58C2056C8ACB66F3ULL, 0x902C30297595DEDBULL, 0x513A3CC37F13AB37ULL, 
            0x858D9507AD679B3EULL, 0x8F362CEBA1E7CFC9ULL, 0xAAC69F77E21831D6ULL, 0x54C295F8FC68AE84ULL
        },
        {
            0x8DC58C14264651B7ULL, 0xF6A2F843F3147F37ULL, 0x88C96F984AA31965ULL, 0x3989F86AB153DA59ULL, 
            0xF264A6B8A79D3B64ULL, 0x96D460DD5D5FACC0ULL, 0x18164C95730B26E5ULL, 0x71A27F83F15FD28CULL, 
            0xFF5003979CA438EDULL, 0xC70BD6B85811AD84ULL, 0x0B8215991D1E17EDULL, 0x54531E79E69E37F6ULL, 
            0x6FEC7F8686B3F1D7ULL, 0x4A6A2C0599FF6F28ULL, 0xC249E7B5ED2931D7ULL, 0xB4C6D3129E5E2C96ULL, 
            0xE7F1C99F090A26C6ULL, 0x9F6396F4C846F38CULL, 0x940FA30BC06C749FULL, 0xEB5FF3C9D2A6D62EULL, 
            0x7C14963097D169FFULL, 0x60C7C0B17A857F17ULL, 0xA1965340DDEED557ULL, 0xBEB2F4A419E31048ULL, 
            0x0AA495C5D29E7BDCULL, 0xC191D304434B0364ULL, 0x590A50980CE9CEF3ULL, 0x5E98AE109FB639E4ULL, 
            0xB9C1E109276892C3ULL, 0xA43658A9079AEAA8ULL, 0x451BE04CF632B62BULL, 0x75B0E7066483690CULL
        }
    },
    {
        {
            0xFCCA3CD06CBF2AEAULL, 0x26CC3D9C797C5366ULL, 0x811167633B2A1410ULL, 0xC74616E21C8D6E3EULL, 
            0x3A3C185824E4BCC1ULL, 0xEC62B395B742FA4AULL, 0xE72882ADA453A4AAULL, 0x35F13C7B90D954A6ULL, 
            0xD08FEB0144190E69ULL, 0x305A8701F169A950ULL, 0x4F97D04C21E974DAULL, 0x717C2E41052E55D6ULL, 
            0xAAFCFF545ADB5583ULL, 0x76681F5B1DFBD43AULL, 0x862EEA5C0243D5C0ULL, 0x6C66F3E079B8E4E4ULL, 
            0xFF47CF520792B4C4ULL, 0xD5504FF03C318263ULL, 0x78BD915CF70E1C9DULL, 0xBA06FD9E65B0DB6AULL, 
            0xBD52E56E640D6EC1ULL, 0x31C655AD1B90DBF3ULL, 0x78DDFDF1BA91F9F4ULL, 0x051AE28D1196EFB1ULL, 
            0xB7F6CE8076725E76ULL, 0x47A634F55D54D39CULL, 0xDB7904EBC3B8C82CULL, 0x6FBF6E8DA38664CFULL, 
            0xFD6CD6AE9DA756A3ULL, 0x3DE47FE52C6359D8ULL, 0x1FE6D8C55E4F5C88ULL, 0xA881E4ED1956A4F7ULL
        },
        {
            0x6A0E19C79E5032A2ULL, 0x4D4CE6DDCA543254ULL, 0x0C346C400B3CE4CEULL, 0xE9D3357C1ABCDA9FULL, 
            0x4295A22C478BF507ULL, 0x5684549E269B60D8ULL, 0xAF14689160DA2DE7ULL, 0x7801E0971451B251ULL, 
            0xD88EC95D47F4E686ULL, 0x75D231D7D0CD1882ULL, 0x1DDD5DE0FFD91BCAULL, 0x0E008EEFFEE9CAD6ULL, 
            0xD9F24C9A16E5A4B4ULL, 0x58137D6CD69984C2ULL, 0x900CAF731D85614EULL, 0xAE5517259BB3F1A7ULL, 
            0xD89606760DE7FF2CULL, 0xE5256CBCD6AE665FULL, 0x230A9F3C1BD97256ULL, 0x4F7EF7D433E0FF81ULL, 
            0xD117F6E59F5F3D5EULL, 0xFEFD8FF3CC5B5CF4ULL, 0x1772A9F8BAE789C0ULL, 0x57683C8EF01147DDULL, 
            0xC40458C31864E22FULL, 0x622773DDC4EBE20EULL, 0xD4D9B85C322118DFULL, 0x37F6C918BD0EF3E8ULL, 
            0x972B313517670986ULL, 0xC9E06D7FC6FC7008ULL, 0x6188D085D341B8E7ULL, 0xDFA28CD59D15736FULL
        },
        {
            0xB28272DC79B985CEULL, 0x8E4B6BADDF3A4F18ULL, 0xC9E7FFF6C8D79651ULL, 0xBB97DE9E18710275ULL, 
            0x751570FC48670757ULL, 0x4AF7EF3CF0A9B1BEULL, 0xA999BDF3101FD323ULL, 0x2FF2B4D8BEFA4EA7ULL, 
            0xDF27D43A7CD789A4ULL, 0xEECF25CF20C5D34BULL, 0x53E986CE459ECED4ULL, 0xA7E59A14254C45E6ULL, 
            0x2ADF17B07C98A5B2ULL, 0x134119528843DBCDULL, 0xC039684248504C39ULL, 0xACFE0EA7ED18760DULL, 
            0xC5D1B4ED83320244ULL, 0xDC37DEE0A9B64BB5ULL, 0xF4265DFE12F1A042ULL, 0xFE7A01657CF972EFULL, 
            0x42147E027F86FF3AULL, 0x5865295E6909962AULL, 0xFB3F4F1B6C4697A7ULL, 0x79E4D7C630923313ULL, 
            0xF748B410A3E73402ULL, 0x71C26FA28664E86EULL, 0x006920408A3D3821ULL, 0x0D5BCDD87ADF8673ULL, 
            0x7BD526C650DF9173ULL, 0xC4BA0EDCDEB1C68AULL, 0xAAD48A061664F76DULL, 0xBD5914339A2D69E1ULL
        },
        {
            0x5E3858CE28AF4392ULL, 0x184AC01E9AA11B53ULL, 0x5FDF285F3DF3C533ULL, 0x4F333C41C06164DBULL, 
            0x23BD69161DF83D5CULL, 0x49F0B33FCFC2EA81ULL, 0xCA59DABD24333994ULL, 0xA041A1B82C6B985AULL, 
            0xF17C1A22E867278FULL, 0xFF7571C0BFCD67FCULL, 0x338669F9D80EF730ULL, 0x63BA4BEA794EA9EBULL, 
            0xEA8C158F2F1B496DULL, 0xA06CF972BA8EB602ULL, 0x1F2913BA7ED0FD00ULL, 0x662A9BC7A6ECC10BULL, 
            0x36D0DFBBDC5EEDFEULL, 0xDC7190934F4FF11DULL, 0xFC52104C7AD12F52ULL, 0xB5608C1CE18900FEULL, 
            0x36C41F833D2A89BFULL, 0xBD3E164F76EF517EULL, 0x30223E7C67BD710EULL, 0x133862631E6C9C2BULL, 
            0x97E915C9CD022756ULL, 0x30678C1CBAFBFCDDULL, 0x2B265F2A8DC51C22ULL, 0x734E2FBF54AEA2DFULL, 
            0x31D06FC3F6F919BDULL, 0xF13146EB6E24AB41ULL, 0x751103C958E9B87CULL, 0x435AC6CA5F4AC774ULL
        },
        {
            0x755E415B77613BAAULL, 0xE8616CE08FCDFC4AULL, 0xA62D9ECB0E8A5DD5ULL, 0xE552131B83A2A915ULL, 
            0x89EED89EA82EBDDAULL, 0x512ECA5488145532ULL, 0x6FB0392B55168C38ULL, 0xEA744EB12D787D34ULL, 
            0x270BFD9C92F62BD9ULL, 0xDA0DF6E348CEFD61ULL, 0xF39441D5DA78C67EULL, 0x8039CFAE78EF33FBULL, 
            0x811D1DBBAC059F9DULL, 0x9B974B79D0C8B579ULL, 0x6643276F3196AAFCULL, 0xD381A06AF6310AAAULL, 
            0x1D39A0DD62F25042ULL, 0x1A27E7DEF8278D78ULL, 0xEB5AB4CC11E60A8DULL, 0xFDD4BF4AC54600B0ULL, 
            0x66EA66A76D024E9CULL, 0x9E860564EB699EAAULL, 0x7AF1DA765B35EEC1ULL, 0xE2EA13E6E24040B5ULL, 
            0x33E4C48E90824D13ULL, 0x5089A1BEA0F47085ULL, 0xBA124C498A397970ULL, 0xF74DE27561651990ULL, 
            0xC9085D695EBB4B18ULL, 0x8A58BE5FEEC63CC8ULL, 0x8655AD2C8C5291E1ULL, 0x112D3BE5CA831D77ULL
        },
        {
            0x16EE8669074832CDULL, 0x258C20418D25F608ULL, 0xF7A9E42947138A6EULL, 0xC72C7E5E25C36BEEULL, 
            0x1872576B7B788055ULL, 0x5696B52601AF46BEULL, 0x07F8D2BE56D4CF87ULL, 0xD799816FA768FA7AULL, 
            0xBAE324A52567EEEEULL, 0xD5736371B8614D9BULL, 0xE15736467C2B88CBULL, 0xD770D871E6B480A3ULL, 
            0xEF56F57143E6931BULL, 0x238032B63F66FD24ULL, 0xD243166459148B5DULL, 0xBBB6E3DFAB13299AULL, 
            0xC2B85569617C2AD8ULL, 0xF517B8E9CB526BB8ULL, 0x1F6EA945343041CDULL, 0x158481FF3AAC0E74ULL, 
            0xEED7B78430CD68AFULL, 0x4C66C671C719C420ULL, 0x991A1AECBD98C4B2ULL, 0xF4CE8935DD1231F0ULL, 
            0x30F8E9CFBF48651FULL, 0x5F67683C31F6F2BBULL, 0x2F6CC48A84FBD168ULL, 0x535C7256EFF0BF8EULL, 
            0x13915DEC24127E40ULL, 0xF6774B367991DF37ULL, 0xDE787CA3491EA56BULL, 0x2C5E8C93E279C5EFULL
        }
    },
    {
        {
            0xE10A8BCEC9979E5DULL, 0xBCD5A4D77159A83EULL, 0x292697DA4F4FFA22ULL, 0xD4F3FEAE5F591A65ULL, 
            0x9240C7FDFCF7D569ULL, 0xBAC33D98EB072DA9ULL, 0x9B980DF705552FA9ULL, 0xCD8A75950A908E04ULL, 
            0xB5DE6676B6AED478ULL, 0xC23A28C170244A21ULL, 0x98FC99B712033C42ULL, 0x5500CFF5042784F2ULL, 
            0xDDFB4100BFF30D2DULL, 0x0F2FBEA647943842ULL, 0x22B807845A50B401ULL, 0xF04A8AA68F19F18EULL, 
            0xBB7C0F68E0A6E399ULL, 0x78175AA272D57BF1ULL, 0xB2BB0A842FEFECE9ULL, 0xB85C5B7FF928218EULL, 
            0x4F9CF9E68FBE4A01ULL, 0x60FA5B6737555779ULL, 0xF23C62AE301F5326ULL, 0xB1DA2E8BEBD69EB3ULL, 
            0x1916511F29CCC2F7ULL, 0x9E5C5644B5980015ULL, 0xB546DF9ADD7B0021ULL, 0x896F8A8A3B7D487CULL, 
            0x4612E609C8901BB2ULL, 0xCE1C9D4AFDCCFA7FULL, 0x8123689F2584CC69ULL, 0xFB3B159FF8190C36ULL
        },
        {
            0x6C6C2E7D4A074DF6ULL, 0x5D9251E15AEF4895ULL, 0x5B66C7FCAE823088ULL, 0x9C7DFC10F900A842ULL, 
            0x2CE241CC4C24E62DULL, 0x195B687A832ECAD3ULL, 0x53FD298EEF3128B6ULL, 0x59725AB320903EF9ULL, 
            0xBDEC097B369A975FULL, 0x58C38CCD09AAFD1EULL, 0x31D2DD199A6081C3ULL, 0x7BA54D881A58A68BULL, 
            0x58A4ED1E5E9B048BULL, 0xED05BC6634B3901CULL, 0xC3CB24E6E23248C9ULL, 0x98378F0380B9BE01ULL, 
            0x9E0005DE9049664FULL, 0x0018994CFD96F1D5ULL, 0x087C535AF677172BULL, 0x10DA9A71C2F6CDCAULL, 
            0x5C54D9365E2CC46AULL, 0x4D6F37999FC10C40ULL, 0x8FF719B7FC6078A0ULL, 0x85AB5F66299664CAULL, 
            0xEBE66382B4CD7F65ULL, 0x87DE632B655A0545ULL, 0xC5C762BD7D946463ULL, 0xCC6B604A2C947331ULL, 
            0x4D8C8BFF5ABA6B1AULL, 0x6845A71E2F52331CULL, 0x9A1D2E8D1FAD75C3ULL, 0x8565D9F13D811726ULL
        },
        {
            0x28C5CE576A20CF90ULL, 0x10186A2413A7FF21ULL, 0x43772D8C6EC4CF08ULL, 0x5C1051C31B0E6FC2ULL, 
            0x384D58040147102AULL, 0xF1E65640B6FF2F2CULL, 0xD52AA47A1225CDD0ULL, 0xEA4FA6BC03F95666ULL, 
            0x6E24210E8D9CAB1BULL, 0x5227315192C580EEULL, 0x53848DE696302C8BULL, 0xFB00B6DF7119CF0AULL, 
            0x20B3D1DFB68ABFE6ULL, 0x648F21653B23677BULL, 0x2C873EA1324A3B4FULL, 0x06D71F34C5D7D2FDULL, 
            0x3FDA932F20FCD3CFULL, 0xD311033B0C84D320ULL, 0x316482BF7C84161CULL, 0xC2690F64D51B122FULL, 
            0x08D2ECB8A1C1EE9AULL, 0x8DA009A53FA584C0ULL, 0x17851576AA5610C4ULL, 0x6D0C5D0125422450ULL, 
            0x5799BDDDAF4D414AULL, 0xEB8C01E1F1D3590FULL, 0x9646E1D9A9EB217BULL, 0x6E8A75EB2D6C06B6ULL, 
            0x0BB56029E650D0B7ULL, 0x0D9E5EC4220D131EULL, 0xA791D8E5D8419498ULL, 0xDC72DEB004174390ULL
        },
        {
            0x03CD32CA296134C2ULL, 0xB0561761F3565298ULL, 0xDC974D82E2E5B8B0ULL, 0xD2A06CFD3621BDA0ULL, 
            0x9F1E7D1689793A30ULL, 0x268354CF8D4CD985ULL, 0x01CC59975556683DULL, 0xE651059F30344779ULL, 
            0xF1B61B96A73D46E1ULL, 0x6C6F9B492D138E11ULL, 0x251791FFCB90D7BAULL, 0xD1940C51B80D4EEAULL, 
            0xA5C30551FEE57CC1ULL, 0xF508B402C5307842ULL, 0x34E2B1B279ADD4E4ULL, 0x20A842354E92EAA4ULL, 
            0xC254BE91C676CE1CULL, 0x108B691C48518E75ULL, 0x9EFBA06E88407CB3ULL, 0x373B5556E21D6C54ULL, 
            0x5FBEB1C53BFB3122ULL, 0x2BC9E4780E19B338ULL, 0x20BA0EBEE642DF8FULL, 0x8F5340D4C094CCF9ULL, 
            0x7B28F93CF393CE5CULL, 0x13C3E204470216CBULL, 0xF5751BC1C616998FULL, 0x206A81F8E399B42BULL, 
            0xBF5BFB074EE60716ULL, 0x3F2B131DB5081DD3ULL, 0x5441B412DD351D5AULL, 0xDEEE3D734985965EULL
        },
        {
            0x2C6550E934A265E3ULL, 0x3B4BEDEF69E5FF87ULL, 0x5D773FF6DF14A9E5ULL, 0xC3730598F6883C72ULL, 
            0x3B1735913909C29FULL, 0xBE4F78678C3297D1ULL, 0x2C683AE840F80748ULL, 0x2C929606631BFEB4ULL, 
            0x3E71902A09BF428BULL, 0x931B8DCD917AF670ULL, 0xA37FBCD7D792E6ECULL, 0xB84032B78E24976BULL, 
            0x14D0F5B0CAD6A859ULL, 0xF3AEC7F192091A4DULL, 0xD5ABE28CDC75DF40ULL, 0x1F7F1D86FAD7FBE2ULL, 
            0x2E257057049F7D0AULL, 0xB4A0881DB0CC6A4CULL, 0x1AE45ADB912CA795ULL, 0x3E20C3D5E4650C6DULL, 
            0x5D59F62F4A52D16DULL, 0xF351D3B4F01E4936ULL, 0x4F5FD2A59816A8C8ULL, 0xE87FF966B203E9CFULL, 
            0x9352B71C0E1395A0ULL, 0x5D1E3C7E3602CE41ULL, 0x8530F05EBBCD2046ULL, 0x49E9311631C03B7AULL, 
            0x9378600A993FF68AULL, 0x7199FF5C43B0D768ULL, 0x0B1BA608956B8F93ULL, 0x69194BD232618942ULL
        },
        {
            0x4F06371F9FC01D53ULL, 0x2615937683D9B176ULL, 0xB2ADDD786D5245E8ULL, 0xF78721C2B1A04871ULL, 
            0x777A8899BFCF1C7BULL, 0xA6628BEF3EF95E7FULL, 0x8BDC6C7BDBFDFE3BULL, 0x7E13FEED400C6452ULL, 
            0x8CEEADF40DB559BBULL, 0x1EEF908773358135ULL, 0x5DE9396D57847F73ULL, 0x06807DE13B22023FULL, 
            0x03F7E93ADFE14BBEULL, 0x4AB0FB700E231D82ULL, 0x12AEC4731A6C69EEULL, 0x5BD8DF935ACB57B1ULL, 
            0x93DE34E6E59FFE95ULL, 0x9E0CF59248D8A540ULL, 0xC7F66E3905E98484ULL, 0x6DD326AAFE711121ULL, 
            0xB4BAAC052921DC7DULL, 0x195FF5433D5B8A8DULL, 0xC0F1A4B044F897E8ULL, 0xC1D04784D740ABBCULL, 
            0x1B249E9BB9577DC0ULL, 0x4FAEF5E5957A5515ULL, 0xD2284FB20B65AC0EULL, 0x78A13D0632080A32ULL, 
            0x97D5F2CD13A28A54ULL, 0x0531F99B884594EAULL, 0x7BAEC25D2F5E1D1BULL, 0x325267BA4BC288ADULL
        }
    }
};

const TwistDomainConstants TwistExpander_Naos::kSeedConstants = {
    0x2DDCC144B9C3D56EULL,
    0xE85F768EFE4611D8ULL,
    0xCF6BFF812A44D407ULL,
    0x2DDCC144B9C3D56EULL,
    0xE85F768EFE4611D8ULL,
    0xCF6BFF812A44D407ULL,
    0x9A333AB165276B82ULL,
    0x64FFC1B538AE9E73ULL,
    0x2C,
    0xC8,
    0xF6,
    0x8A,
    0x1E,
    0x8F,
    0x6E,
    0x52
};

const TwistDomainSaltSet TwistExpander_Naos::kTwistSalts = {
    {
        {
            0xA6A7EA76769329AFULL, 0x412701EFF8030837ULL, 0x608C07C65D720FD6ULL, 0x7CE040163002FCA2ULL, 
            0xBC61C10B4BF16C72ULL, 0x4B32C0E3FC8008E5ULL, 0xAC4B4D289DEE87CEULL, 0x1F75F621CB2893F6ULL, 
            0x1771148330541CD0ULL, 0x41C7089A52C51BF1ULL, 0xF1D9733C1729C60FULL, 0x5F8BBC67D1A4D196ULL, 
            0x933B83EEFC46276FULL, 0xB2C7FE0A9755C033ULL, 0x2DE225523A734C52ULL, 0x8F0C53B387AF81B7ULL, 
            0xC63C1D065B7B1734ULL, 0xD73401C9B60F4238ULL, 0x2D4BEC26E501D024ULL, 0x24A95373B7A619ECULL, 
            0x883A01EF7789C2D5ULL, 0x5A448BBF22D5DB1DULL, 0x76583CCA0B02147FULL, 0xBEAB09DE4AE80EFBULL, 
            0x03F6F78D358E1783ULL, 0xDC8BC4D7FF54265EULL, 0xF29430D154C7B44BULL, 0x966E5887D1574A19ULL, 
            0x7D874254DE68B887ULL, 0xF097B65A2DB421FDULL, 0x2BEECE4A77DD2D7EULL, 0x3D79B57C55E14436ULL
        },
        {
            0x608C96B796C8046CULL, 0x70296D51A0911115ULL, 0xCFDFF13A676553C2ULL, 0x635F34DDAC37613BULL, 
            0xC1E5CEEB4B941ECDULL, 0x8C47CA7E08F5E46AULL, 0x192B6DD53948B44CULL, 0x79995FDF3F12AA05ULL, 
            0x97B05F58653609B0ULL, 0xF7F3A15B7EFB1280ULL, 0x6D545122A86EFBC1ULL, 0x26C46E407CABE01BULL, 
            0x296934598A39A00AULL, 0x5627F80476989D2BULL, 0xCB1FABD89D40B8E1ULL, 0xC704967307AFC480ULL, 
            0xAE6E135EAB64B00AULL, 0x5E78C888B66113FDULL, 0x6681935330BA843DULL, 0x694A5B31882C76DFULL, 
            0x0D57D763DB081E1AULL, 0x2FCFA0785B7377ACULL, 0x47BDE2F5280EDD96ULL, 0x05883970CA53C72FULL, 
            0xF00D391FE04D10A2ULL, 0x455B1097CA43493BULL, 0xE4E420177F4837DDULL, 0x1AC15AC6BDFABD24ULL, 
            0xAAAC74559DAF5B0BULL, 0x8C5B81B25D0C641DULL, 0xF1B1DB442FC445B0ULL, 0xBACB9DEB74203253ULL
        },
        {
            0x87F63C3405071579ULL, 0x47A9260E50BA7268ULL, 0x848A21093CE8D9B2ULL, 0xA3F3455AD75A8369ULL, 
            0x5CAE822246D77903ULL, 0x214F2118A706CCCAULL, 0x0D8BA4A5F6C221D4ULL, 0x4E6CF28C115A5DC6ULL, 
            0xC27BA378F8A029DBULL, 0x296A888968DEDE89ULL, 0xC6C322A512AA3C8FULL, 0x61DA0F12D0D6EFBEULL, 
            0x13D25B9A8001D4F2ULL, 0x41F1D72061F881DBULL, 0x98289F347FBEAD24ULL, 0x9543247DF88B6836ULL, 
            0x1E40703E5E1475A8ULL, 0xFE55C7507D51AE5DULL, 0x0B866B7FDEDD8BCEULL, 0x5343EDA74AFA4707ULL, 
            0x86ACECC9FD78AD0EULL, 0x77A483D72EDA57B6ULL, 0x2437DA45B56772B3ULL, 0xF3935128D7D7D33AULL, 
            0x22360A50DDC2E6F1ULL, 0x76844A813DB08926ULL, 0x6671DBABFF76DBB8ULL, 0x88E7C2923CE94FBBULL, 
            0x72E6E0DD9E51BE95ULL, 0x53BAF7C0A7A7901CULL, 0x9320953CDF93D3E9ULL, 0x79AF87257B6CDAB2ULL
        },
        {
            0x85E2201B36878B84ULL, 0x145FDE07A0FFFC6CULL, 0x1AFC1FC74ABC6F71ULL, 0x17BC79D205ED69DBULL, 
            0xF07FDCC9761A25C6ULL, 0x4F486080C776EF3FULL, 0x6F555393130D6C8DULL, 0xF1596BE9CD1972D7ULL, 
            0x184BDAF4F0E9F14CULL, 0x7642C95F11A9FA19ULL, 0x4AE218E3E8BD26CEULL, 0x941F0F06A2601D92ULL, 
            0xF871C15006418468ULL, 0x782FF61062883DB0ULL, 0xB264ECAFB3BC35B5ULL, 0x0DBB5DA2641B86E3ULL, 
            0x27C02AEA2D5DC17AULL, 0x416F5944CC14EC21ULL, 0x1E1E189E44511DDEULL, 0x53650B51E7F52BCDULL, 
            0x1EE01CD89F2D8EE7ULL, 0x4CD653B14FAA94EEULL, 0xCD29BFAC1E1D512DULL, 0x50F367F10DBC756BULL, 
            0xBFA62284821EE867ULL, 0x4968BE27FFAA2C2CULL, 0xC7A90A458C006810ULL, 0xFA57A68D7B6D4AF5ULL, 
            0xF27B0A4313FFA324ULL, 0x39D10347C3325FDBULL, 0xE3E1FC5B6095757EULL, 0xD977743E9AB4840CULL
        },
        {
            0x5C7270519F082D0DULL, 0x57BD976339BCD461ULL, 0x8D9C5F1993AD0FE0ULL, 0x26A911E8B53750DEULL, 
            0x6C15D6380D284CABULL, 0xC708F6B2C2BBD2C9ULL, 0x11A60B1A37D30FACULL, 0xB215FD6D024A5762ULL, 
            0xA3F3D44239A72D09ULL, 0xB210F35ED6D543AFULL, 0xDD2CD1758D94C8E5ULL, 0x6AD45E930B47FEABULL, 
            0x9851AF2BC0BA58AEULL, 0xB27BAF072D1EF091ULL, 0x95C4B3D5D9BB6BBBULL, 0xC3C0A40ACBBAD9FBULL, 
            0x4C404DFE1B2425E4ULL, 0xF01383E2751251B8ULL, 0xFC16E294493E87F1ULL, 0x5B263628C3FD197CULL, 
            0x11DBC2613FCCBDD2ULL, 0x67B0E91084F33150ULL, 0xFF529A840D49F902ULL, 0x47D23665A8B2FB74ULL, 
            0xE3DC399C6121983EULL, 0xAE0B8A76147BAFC8ULL, 0x97A05AE6A8B8CD8CULL, 0x22FC98429834A4AAULL, 
            0x03F698D1B0ECE3B3ULL, 0x4C73466A9469ED4CULL, 0x7F9C8CFC53FB4B48ULL, 0x59AB50722679C0A2ULL
        },
        {
            0x347D7A8F627D7668ULL, 0x042A55469D88B934ULL, 0x9352F3EDD63E9511ULL, 0x8919A30F420856CDULL, 
            0xE659736485887C50ULL, 0x31F60654A5F87FC8ULL, 0xEF1C6E9B09A45B59ULL, 0xB443F16C743C2676ULL, 
            0x977B5152301C1B84ULL, 0x42B593439D28CCE9ULL, 0x4D9247E7603DA508ULL, 0x5F884B13023CB46DULL, 
            0x31C37CE21FE63747ULL, 0x82865BFDF8DCAF20ULL, 0x5CB91E1224141FDAULL, 0xFAE3BDA580C30A86ULL, 
            0x9E5A30909967EB8CULL, 0x8528EAD56BD810ECULL, 0x1CF909CD41B57E00ULL, 0x17BF878296BFA1BAULL, 
            0x7E11FEEED43CFD78ULL, 0x24346B0E9EE3C7D4ULL, 0x7792294DA5FFA942ULL, 0xD753D669A3D036ECULL, 
            0xFE60E77221EEF412ULL, 0x4AAA27D747ADD125ULL, 0x35545435418E9E06ULL, 0xF578DA4625B9F368ULL, 
            0x670B163EC4493AE5ULL, 0x94B1AEE11CD2F8E7ULL, 0x651570651640A426ULL, 0x5BEA5063501EAADFULL
        }
    },
    {
        {
            0x1250919FC34DA870ULL, 0x52A80A467F04460EULL, 0x098DB176A05FF2ECULL, 0x44D0F29C59AB4963ULL, 
            0x9DD74D19BAF277E3ULL, 0xB7F73B9EC817214FULL, 0x9D3129854E0ED0BFULL, 0x247639861C717AF0ULL, 
            0x47D1B6A9D43E8CA8ULL, 0x71F82BE86474D2DAULL, 0x4D8E25DE32489601ULL, 0xDA13F11C4B9F7378ULL, 
            0x1D32A2C01CBBED6FULL, 0x9539F4EF75325749ULL, 0x43B58E8BE31462AFULL, 0xDA0F3C2F758852A9ULL, 
            0xA0273F11ED2B0DE7ULL, 0x43AD9A3B30CED334ULL, 0x32F1E7AE69403DFBULL, 0x485D1665E9C8B4A3ULL, 
            0xEDC850D6CA5F4356ULL, 0x8DCA6962D069EADEULL, 0xC77ADC67D46A9C1DULL, 0x13DF54596FC4BCFBULL, 
            0x7A17E17716370055ULL, 0x403673CA52E8B908ULL, 0x037B30A5E333C853ULL, 0x83FD86CF06137A64ULL, 
            0x5FA0EA45CC5832F1ULL, 0x423F14071AB93FB8ULL, 0xF6848826AE946111ULL, 0x350006AD4B8C243AULL
        },
        {
            0x2B5653DD21035F76ULL, 0x117D0AB174E633E0ULL, 0x6565FD14D3CEE20DULL, 0xFAFD5E17B412BD62ULL, 
            0x6D75EB188003916AULL, 0x6B6B5289A9279AFDULL, 0x20D0675289A55FA8ULL, 0xE4A6BABDA8EA5B0AULL, 
            0xC9A209F682C40668ULL, 0x031D3852CAFA0782ULL, 0x6047F79FA74EB285ULL, 0x803F384BE6626A96ULL, 
            0xDE3EFD2C340E8961ULL, 0xEFE3E2DE3240613AULL, 0xB54817C50740060AULL, 0x097D82BCF28627D6ULL, 
            0xF2C90F7EC87260E2ULL, 0x699EA6D4421590FBULL, 0x12BF9A19B5ED0BECULL, 0x98A8BC7E9D9F36DEULL, 
            0x9A95C9F180FC2F27ULL, 0xB4AA3DE8C9168CCEULL, 0xDA0CDAFA6CC29667ULL, 0xBA6D9FF7A165DA37ULL, 
            0xC5E5902784377D8DULL, 0x1AB0051E8ECB6533ULL, 0x0696F231B20BDC47ULL, 0xD96CE063B4F014F1ULL, 
            0x485CB8E8F34CB83AULL, 0x6F58B97E2A849915ULL, 0x4CF9C9B2386902F5ULL, 0x9E812DB20AB7333BULL
        },
        {
            0x08D4672159977BEAULL, 0x07F732431EC77741ULL, 0xCF7AC22A18D18CABULL, 0x0F6CA37DF53D9624ULL, 
            0xA12DA0D099DE725BULL, 0xFD748F831A65DE31ULL, 0x8EF26B647DFE8CEDULL, 0x1F55186E13DB30DBULL, 
            0x9E2F0CCFFE85102EULL, 0x33193EF89F2833DCULL, 0xCEF7B02A1B8EC45FULL, 0x92741823175A8F5DULL, 
            0x4FBF1C0677F53C91ULL, 0x7F9905BBF6B1B61EULL, 0xCE631454A5AD0B8EULL, 0x538F0370BA85132DULL, 
            0x356C0B56B19E97B0ULL, 0xF1CAEB2D82782EB5ULL, 0x6A87F8972B8FB7BBULL, 0x5380E2D24F77C552ULL, 
            0x05148D56CAB4335FULL, 0x1CC54581474AA517ULL, 0xFD2119AFA4A1B589ULL, 0xDAF9F98B04E63A40ULL, 
            0x50EDCDAD303A2E52ULL, 0xB9E9A6115DDEA75FULL, 0xFAC5C46ADEB1D249ULL, 0x2C70E881D62F968FULL, 
            0x741EB8B4F566E48AULL, 0x544DF53C8EAB9D1DULL, 0x67D1634E86FA6495ULL, 0x625B34D874524E68ULL
        },
        {
            0x145D2F8796F900DFULL, 0xF729CE3E7654813DULL, 0x37099CBCBD4F1AA4ULL, 0xEB8E1EB7A8E2F866ULL, 
            0xA0A51EAEF7AD3E45ULL, 0x09E444C29332233DULL, 0x1E0E07D5AC8779B4ULL, 0x628F4FA2E5D2A431ULL, 
            0xC6839D067BDCA241ULL, 0x446761C634DDD8C2ULL, 0x3D9ADB378ED6CE9CULL, 0xBC7728F881726A74ULL, 
            0x894788DC952D2FC2ULL, 0x2295D59E8ED724E7ULL, 0x7B53A3864B8704CFULL, 0x0371401AFC42053FULL, 
            0x8029F7097C7A93BFULL, 0xC34A0ED57D4F3AB7ULL, 0x0274EC6425791CD4ULL, 0xC81EFA3B6F613BF1ULL, 
            0xB91A67D2B82DA54AULL, 0xD144FB2F61612EA8ULL, 0x5DF873B0F64BD9B6ULL, 0x37B9A71033E5BC51ULL, 
            0xE38C882856A45C50ULL, 0xBD869E27694AB6CAULL, 0xAE188E23CE24E772ULL, 0xD7E87AD5C21DDCCAULL, 
            0x0F57971BD2C3FA34ULL, 0xBC31B4CBD4779436ULL, 0x2E02CF246689F60FULL, 0x7DEDABF46388A878ULL
        },
        {
            0xADBAFB19520C7985ULL, 0xDCEBF7B3093C4AFCULL, 0x7991FC5620FDD218ULL, 0x60C6638865B49ED9ULL, 
            0x6B3775EE83254AA0ULL, 0xF0DF67A998B8D877ULL, 0x304D223726BCD383ULL, 0xB7AA69A3AB1B4667ULL, 
            0x3907DFE3598C86AEULL, 0x19AB3732665D84EFULL, 0x1266C9CE7404110BULL, 0x182236DB0D2DA766ULL, 
            0xFC41F9E23560AEBAULL, 0x60B72AB78669085EULL, 0x011643B7D457505AULL, 0xF5DA1C22ECF1D77FULL, 
            0xB42DA890DFA95D63ULL, 0x58C566BB3CF7C585ULL, 0x6E39666F2F50A9E6ULL, 0xC6FE1463165CD72EULL, 
            0x5906D1B03D342683ULL, 0x27B2B8AE08F67E48ULL, 0x99A833662ED4743FULL, 0x3CE7C30BB9FA1506ULL, 
            0x9A84A7897D14DCA4ULL, 0xBEBE65546A3C72CAULL, 0xF762D97F2864D0E6ULL, 0x66B4183B1E2E82DBULL, 
            0x0FD108CAB1665B9CULL, 0x37467AC09665511DULL, 0xCFAB4A0DA4B61A4FULL, 0xAE0F0090425669B7ULL
        },
        {
            0xB5C6424394B4A65AULL, 0xBE9BD7722FA45BDEULL, 0xDD1503D9E157AE60ULL, 0x5AECE7518468581AULL, 
            0xBA7D46C29974D412ULL, 0x52062DA0520EE59FULL, 0x8030E62139C67E46ULL, 0x0FBB5D179741E238ULL, 
            0x22B27CA7E0FCECA7ULL, 0x1B42650C0526188CULL, 0x299F5720D44EE02AULL, 0x3A508C7306BA7FEEULL, 
            0xA19D7E134B540925ULL, 0x29B122B6AB113432ULL, 0x34A9455DD379C25BULL, 0x741258995DF50BA9ULL, 
            0xF496184E95E68FBBULL, 0x7CCF7B731CAF4498ULL, 0x926D93793636D143ULL, 0xF9BE852B8928C2F6ULL, 
            0x75442D557045CEFFULL, 0xF1824BDE322FA50CULL, 0x281E4AD38D39D23CULL, 0xEF3441FB31817431ULL, 
            0x2ACA26D2FAF71790ULL, 0x19A30D0F57D96D80ULL, 0xE0278EC188B97DEDULL, 0x1FBB8D3E071F9BE2ULL, 
            0x36131F151FE079C5ULL, 0x8C9CDEF0F87CEC1BULL, 0x686E1B9B27000E55ULL, 0x77B939A5B0ADC73AULL
        }
    },
    {
        {
            0x9200F9F9798A36FAULL, 0x0AA716872E27C387ULL, 0xEF8360C27090A5BDULL, 0xE3B3B1A5E3CD41E2ULL, 
            0x0169CE0692A0AF43ULL, 0x0C3F3C6ECC623A8DULL, 0xD8F7AA21014DA4AFULL, 0x51EBD830CE12EDCDULL, 
            0xE9E91A425BAA73E9ULL, 0xADB74F1CE4F584F2ULL, 0xB7607D80A0123954ULL, 0x34AC18F69750B18BULL, 
            0xD6ADE781200A37AAULL, 0x5AFDCD3981CC63EBULL, 0x8EBD927702CE35ABULL, 0x488BC6283FDE74F5ULL, 
            0x9206D283875047F5ULL, 0x17199488928A6197ULL, 0x3855617857775959ULL, 0xD6F9E25A6DBD1E85ULL, 
            0xD36A745375195891ULL, 0x6B5785C27170407BULL, 0xA339DD29D2EDBEFBULL, 0xDAFB67D01EF48B58ULL, 
            0x45D856784499F954ULL, 0x31E1BCBE81F9848AULL, 0x8D6B82D66BF9757AULL, 0xBF0B9952DED407D3ULL, 
            0x844D1FC05B06EDF2ULL, 0x7451196F74DB4E76ULL, 0xA959325FD739E3C0ULL, 0x0DD067344E18CB8EULL
        },
        {
            0xAA1CA6136885FD55ULL, 0x332D3247C4541830ULL, 0xCEC4DA0A39965114ULL, 0x48C5BDBF07D05E08ULL, 
            0x5F11B113D2CC2A5CULL, 0xB430413CA4921BF4ULL, 0x798405E82ABE4961ULL, 0xCC33E834AD7F9AF3ULL, 
            0x0E6B64429B7285A5ULL, 0xAE511524F129B211ULL, 0xD169054F79C39DC8ULL, 0x032E2D6183376D85ULL, 
            0x1DD66113A6DC41EFULL, 0xC4C926A76F75DC21ULL, 0xE38FA5C7B6836F88ULL, 0x665AFAEFD7CFBEA0ULL, 
            0x69E4744C8A8278A4ULL, 0xEE58BB929F5F0460ULL, 0x8B5EA8D0738D2B8FULL, 0x8731417FF9BEA6E6ULL, 
            0x2F3ABC88249A11D5ULL, 0x509D8B8D361C4697ULL, 0x2585C86CFC4DA63CULL, 0x9525BFE83DA3B1CDULL, 
            0xF3A12DFF943320F9ULL, 0xAF84B6776EDB9320ULL, 0xFE0B4F1079FF5E01ULL, 0x30EE64AA1666133EULL, 
            0xB942DCFB07CD9177ULL, 0x858786C61A086B43ULL, 0xDD446A26ABBA3FF6ULL, 0x264B7171F68E62D9ULL
        },
        {
            0x5DFFE5690FE5DCAAULL, 0xB2FC0913E590BFE1ULL, 0x02EF6B563D89766BULL, 0xD5B88BA506401D7DULL, 
            0xB6D1B6F71FB2BF43ULL, 0xD275065D08394ACCULL, 0xA70BF8DAF104FA5FULL, 0xE9170EC4125D4E17ULL, 
            0x749DD6CD22910C9FULL, 0xF77E3245713660C1ULL, 0x3F37A492B34DABC4ULL, 0x03F2DB8405F6B87DULL, 
            0x3DFFE9AA9B3402E2ULL, 0x2FB90F33883DE3C9ULL, 0x24A2ED0BC800CA29ULL, 0xFDB0E49828379E0AULL, 
            0xA7A3BAD540298134ULL, 0x37502E534F694C0AULL, 0xB8BB0DCAE805F402ULL, 0x210A721B88D0CB9CULL, 
            0xCD82F9A378FA90A7ULL, 0xAFD1E5331F14DA0FULL, 0xF0151FAAC6C3FDFFULL, 0xD9D777AEFE134C0BULL, 
            0x7B938E177B3781FCULL, 0x160798D83C83BB23ULL, 0x6BEB2F783B865426ULL, 0xEAC261F3537119E3ULL, 
            0xDB45372A14669411ULL, 0x3A42A54037533649ULL, 0x2776569802058E08ULL, 0xF9926E6CE67DF32FULL
        },
        {
            0xC1F94987B5451C37ULL, 0x9766A323D0BBBD94ULL, 0x1D548AAE22581F3CULL, 0x5E4C6F0ED019AFF9ULL, 
            0x44938C4C2B0FE322ULL, 0x60D76EEC085BBF9CULL, 0x7AB4D737632C4FA9ULL, 0xDB9E82F167BE9E7FULL, 
            0xBBED707ED022D78BULL, 0x7793235A5B7594C2ULL, 0xF920C462FCA05162ULL, 0x4876F98FD54EDD35ULL, 
            0x853F990FB7095F7EULL, 0xE1F0F124F9A67DC7ULL, 0x532F0D118E0D17FEULL, 0xBB6E55C49BC3A2BDULL, 
            0x09BB2ED658BEFB94ULL, 0x8E04D3C40A801E3AULL, 0xC82D5349B95EFA56ULL, 0x1708CA017EDB4DB3ULL, 
            0xF210CFF9382F3492ULL, 0x609DB16B640713C5ULL, 0xA93A7A1F7895940DULL, 0x25CFB6420CF81687ULL, 
            0x58387A9E2D386552ULL, 0xB91761A65C57D954ULL, 0x4AF5477AAC50046AULL, 0x585FD95943576280ULL, 
            0x2FD451B4B51B6D97ULL, 0x5185FBE5FCE1C58FULL, 0xCCBB14C4ACF9A02AULL, 0xC960CD1E44FF4759ULL
        },
        {
            0xD9C0682A525E6A44ULL, 0x320D69DADEF82A15ULL, 0x8085B4C2E79C5AA5ULL, 0x5058346B9261B6EAULL, 
            0x83940D77BC6ADEFDULL, 0x921E180C3AF212CDULL, 0xC00800AEA0EAE94AULL, 0x7EA4C92D319FB290ULL, 
            0xD3C137A8C89CB840ULL, 0xA2E4BC4A98B97C7BULL, 0x05E24567CB942BBCULL, 0x72B5B1E76BEDE15AULL, 
            0x9223D995DCE88A40ULL, 0x0A3E0FC9EAC69BB7ULL, 0xACA878CD0DE98C7BULL, 0x8B47FC289EB67533ULL, 
            0x9790C3250A257018ULL, 0x8471CAA4DBCDF5B5ULL, 0x20924E6ECE52B0EAULL, 0x1D7DB4E252C13C41ULL, 
            0x3612CCF6C71CFFB6ULL, 0x56A45B2E1FA35294ULL, 0xF6426FE5714F84D9ULL, 0x5C4C01AC3958D673ULL, 
            0x7ED0AEFB8DA11BACULL, 0x5802B9831167D64BULL, 0xD53919E4E0F02EE2ULL, 0x0E89D88658A6C0D0ULL, 
            0xB699226322588F8EULL, 0xFF59025F82C65645ULL, 0xA2B66F3809493EECULL, 0xF26E130154C40788ULL
        },
        {
            0x7A662401BEB2B049ULL, 0x2F61988EDD6F9367ULL, 0x8FFD9C09AE9A3C2CULL, 0x8A04E56B03763AD1ULL, 
            0x5156D973214096E7ULL, 0xCE84C3BD74ED43A7ULL, 0x5AA3E10141E0A886ULL, 0xE338C963EF7039D6ULL, 
            0x8C6B745C6B62F45BULL, 0x5E0B91BAFFB85235ULL, 0xFEE39FF3A6C0A4C2ULL, 0x20ECF47AC58E7801ULL, 
            0xC092DEB98FBE4C9DULL, 0xB5B49E32233FF396ULL, 0x44C5FCDABAE4D558ULL, 0xBD2F420A4C83DF51ULL, 
            0x9803C2ACDD63C2FEULL, 0x134F5BA1B952AE25ULL, 0x238224E8A88355E1ULL, 0x89AE4F4EC91EB579ULL, 
            0x150AAE05078FE569ULL, 0xC51A06CAAEAE8AC5ULL, 0x008DA884C7EFE29FULL, 0x0DC82D7D63568317ULL, 
            0xCF20EAFB8F5F23A4ULL, 0xCEBCC96A933D255BULL, 0xCBB43CD17B086A1AULL, 0x21BC03ABA8A14D64ULL, 
            0x70EDD3B1AB6855F4ULL, 0xD2E13A4C1B72E751ULL, 0x2007B6AF83FAF53EULL, 0x17A18B9DBD318B2DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Naos::kTwistConstants = {
    0xEFD6C3AB5066539BULL,
    0x61FF3E6B465DCA72ULL,
    0x374FEA5F5E002A65ULL,
    0xEFD6C3AB5066539BULL,
    0x61FF3E6B465DCA72ULL,
    0x374FEA5F5E002A65ULL,
    0x4E3DD43BA25DD43EULL,
    0xC0CE12E562F81FAEULL,
    0x40,
    0xD5,
    0x96,
    0xBE,
    0xEF,
    0x10,
    0xDF,
    0x34
};

