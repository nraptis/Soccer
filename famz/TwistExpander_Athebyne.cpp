#include "TwistExpander_Athebyne.hpp"
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

TwistExpander_Athebyne::TwistExpander_Athebyne()
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

void TwistExpander_Athebyne::KDF_A(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Athebyne_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Athebyne_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Athebyne::KDF_B(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Athebyne_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Athebyne_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Athebyne::KDF_C(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Athebyne_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Athebyne_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Athebyne::KDF_D(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Athebyne_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Athebyne_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Athebyne::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE53987EE2F530A32ULL;
    std::uint64_t aIngress = 0x8646E460676D9871ULL;
    std::uint64_t aCarry = 0x8B75A8D1214EFF99ULL;

    std::uint64_t aWandererA = 0xBF4AE152BC706472ULL;
    std::uint64_t aWandererB = 0xE2A67FEF0F4F5B9EULL;
    std::uint64_t aWandererC = 0xFDA2CBEAD3FC240CULL;
    std::uint64_t aWandererD = 0xF6A014C26A2CD8D8ULL;
    std::uint64_t aWandererE = 0xEE87E3BE0CAE6B77ULL;
    std::uint64_t aWandererF = 0xE61ED9AC3E232337ULL;
    std::uint64_t aWandererG = 0x86B37C111E0CA310ULL;
    std::uint64_t aWandererH = 0xE5B3A74175D65254ULL;
    std::uint64_t aWandererI = 0xE88C11B79BDBDC00ULL;
    std::uint64_t aWandererJ = 0xC641149859EC8EB3ULL;
    std::uint64_t aWandererK = 0x8E015C16432D6E53ULL;

    //
    // KeyRotate A
    //
    aPrevious = 0x8E047663253634ABULL;
    aIngress = 0x92E37AEA3FA0D8E5ULL;
    aCarry = 0xA0D557CEDA8EF082ULL;
    aWandererA = 0xC306F052BD6DCFF9ULL;
    aWandererB = 0xFEFDE917BF0F1B86ULL;
    aWandererC = 0xB245205416EBA915ULL;
    aWandererD = 0x8A5E7D286CD77AEAULL;
    aWandererE = 0x807B74EC2A9B2793ULL;
    aWandererF = 0xBDC859B0B37C0199ULL;
    aWandererG = 0xE6BE80BE3FE160B8ULL;
    aWandererH = 0xE10E7FBC81041FC7ULL;
    aWandererI = 0xF7CF760E3520AF6EULL;
    aWandererJ = 0xB045E8C50F36DA95ULL;
    aWandererK = 0xD5A5C5A6F0304CC0ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateAConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xC669017CEC96DD59ULL;
    aIngress = 0x96FCDAD01388DE02ULL;
    aCarry = 0xDC26994B71BAA22AULL;
    aWandererA = 0xEA177220094EB9A3ULL;
    aWandererB = 0xF63A7DBB01606127ULL;
    aWandererC = 0xBB130245CA0A5BA5ULL;
    aWandererD = 0xC9964F9F12A260E6ULL;
    aWandererE = 0xFD93FB9E771672F4ULL;
    aWandererF = 0xA78118D15B03FF58ULL;
    aWandererG = 0xE8AC0A1D39E692FEULL;
    aWandererH = 0xFB72EE70D30E9161ULL;
    aWandererI = 0xC2919D0E037739C9ULL;
    aWandererJ = 0xAE112E5BEE9900D0ULL;
    aWandererK = 0x9182A368D5AC59E3ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants), &(pWorkSpace->mDomainBundle.mKeyRotateBSalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xFD60B2149EAC23FEULL;
    aIngress = 0xF3611B7E990CF722ULL;
    aCarry = 0xA15179EF9A67F913ULL;
    aWandererA = 0x9C87E08329CC79CDULL;
    aWandererB = 0xA4A5B124BAE4DA46ULL;
    aWandererC = 0xA0CFE87EDBDD3EFEULL;
    aWandererD = 0xFACA919AD76D38EAULL;
    aWandererE = 0x9B58CAC278926C08ULL;
    aWandererF = 0xD92F31CA09D5F8FAULL;
    aWandererG = 0x964EBEA029C845A4ULL;
    aWandererH = 0x876ECAD4E598D02BULL;
    aWandererI = 0xE36B2A14ADBF6E4DULL;
    aWandererJ = 0xCB01E5600A27D986ULL;
    aWandererK = 0xEC415A624692C1FDULL;
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants), &(pWorkSpace->mDomainBundle.mKeySpawnASalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeySpawnAConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xE62377E2E526175AULL;
    aIngress = 0xDD41E1C9FCECDDDDULL;
    aCarry = 0x8701E6D3BA25E549ULL;
    aWandererA = 0xC5F10388203946AEULL;
    aWandererB = 0x99E7BB436F95738DULL;
    aWandererC = 0xF48320BE2D8DBD92ULL;
    aWandererD = 0xB878E22EDA904323ULL;
    aWandererE = 0xDA3DB54364E4A35BULL;
    aWandererF = 0xAB6BD72598173FF3ULL;
    aWandererG = 0xB7C99967C89F6FCAULL;
    aWandererH = 0xDE2A6B73F10834E9ULL;
    aWandererI = 0xD0262E33C3AFADAEULL;
    aWandererJ = 0x91CF99C094389285ULL;
    aWandererK = 0xF3EB1FB98C130E8AULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnBConstants), &(mDomainBundleInbuilt.mKeySpawnBSalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants), &(pWorkSpace->mDomainBundle.mKeySpawnBSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xB32CD6027EAC6210ULL;
    aIngress = 0xC1B1F5F4DCFCB808ULL;
    aCarry = 0x9E5B53B8478278C0ULL;
    aWandererA = 0xC9CC3C326AFFCD80ULL;
    aWandererB = 0xC0FCF886A543970BULL;
    aWandererC = 0x90F4357F6ED4FAD4ULL;
    aWandererD = 0xB3F21A4697D41FA5ULL;
    aWandererE = 0x8D8C45C7A8F5C8DDULL;
    aWandererF = 0xDF2F4B1C85A844D0ULL;
    aWandererG = 0xC9CEDA6DF2F6DF08ULL;
    aWandererH = 0x9B6C183AC9BAA557ULL;
    aWandererI = 0xEF216BAFC277BADFULL;
    aWandererJ = 0xC2781387BD367269ULL;
    aWandererK = 0xA6845732AC86D7A3ULL;
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mTwistConstants), &(pWorkSpace->mDomainBundle.mTwistSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mTwistSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xAA073663A67C07C9ULL;
    aIngress = 0x802C581159268158ULL;
    aCarry = 0xA9D920CE9900D0E8ULL;
    aWandererA = 0xBA85B1E620378A69ULL;
    aWandererB = 0xE259503F97F709E9ULL;
    aWandererC = 0xA6CFF400F89A9E83ULL;
    aWandererD = 0xD293F09D778D62E3ULL;
    aWandererE = 0x82C7C75761576703ULL;
    aWandererF = 0xBE312A7FFE02D166ULL;
    aWandererG = 0xC63986A4E764BA66ULL;
    aWandererH = 0xDB08F84764CA185DULL;
    aWandererI = 0xF0E4231225B72600ULL;
    aWandererJ = 0xBEE40FB9107A4FDFULL;
    aWandererK = 0xBC3482EFD955F44FULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mSeedSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mSeedSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mSeedConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mSeedConstants), &(pWorkSpace->mDomainBundle.mSeedSalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xBBE2C6D4E1D5DED3ULL;
    aIngress = 0xDC04B9016BF76428ULL;
    aCarry = 0xDEC2733294E15956ULL;
    aWandererA = 0xF795AF90854F6ACDULL;
    aWandererB = 0xAA21BF3AA1F9A347ULL;
    aWandererC = 0x808A98AD34B4437FULL;
    aWandererD = 0xE20E9C6926CCA6F4ULL;
    aWandererE = 0xCE8FFAA3BBCDF6A3ULL;
    aWandererF = 0xEFDC4818420A6BD3ULL;
    aWandererG = 0xC7A3CCC52B2B32E5ULL;
    aWandererH = 0xC429F4EE16408BBEULL;
    aWandererI = 0xB00DE8824BD7F78DULL;
    aWandererJ = 0xC745F29BF14F71C7ULL;
    aWandererK = 0xE14E14F8396F7B2AULL;
    //
    TwistExpander_Athebyne_Arx::SEED_A(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Athebyne_Arx::SEED_B(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Athebyne_Arx::SEED_C(pWorkSpace,
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
    TwistExpander_Athebyne_Arx::SEED_D(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Athebyne_Arx::SEED_E(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Athebyne_Arx::SEED_F(pWorkSpace,
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
    TwistExpander_Athebyne_Arx::SEED_G(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Athebyne_Arx::SEED_H(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Athebyne_Arx::SEED_I(pWorkSpace,
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
    TwistExpander_Athebyne_Arx::SEED_J(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Athebyne_Arx::SEED_K(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Athebyne_Arx::SEED_L(pWorkSpace,
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
    TwistExpander_Athebyne_Arx::SEED_M(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Athebyne_Arx::SEED_N(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Athebyne_Arx::KEY_A_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Athebyne_Arx::KEY_A_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Athebyne_Arx::KEY_A_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Athebyne_Arx::KEY_A_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Athebyne_Arx::KEY_A_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Athebyne_Arx::KEY_A_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Athebyne_Arx::KEY_A_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Athebyne_Arx::KEY_A_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Athebyne_Arx::KEY_B_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Athebyne_Arx::KEY_B_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Athebyne_Arx::KEY_B_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Athebyne_Arx::KEY_B_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Athebyne_Arx::KEY_B_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Athebyne_Arx::KEY_B_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Athebyne_Arx::KEY_B_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Athebyne_Arx::KEY_B_H(pWorkSpace,
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

void TwistExpander_Athebyne::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x8B130EC8824C6D8AULL; std::uint64_t aIngress = 0xD375D3CFDF7BAC2DULL; std::uint64_t aCarry = 0xED4DD266BE8D1097ULL;

    std::uint64_t aWandererA = 0xA9C785C2B4472F8DULL; std::uint64_t aWandererB = 0x9AE647A4E6664B4BULL; std::uint64_t aWandererC = 0xE5744A8B6B8EA358ULL; std::uint64_t aWandererD = 0x9985FDEF70F56EC5ULL;
    std::uint64_t aWandererE = 0x9128EBFF40EEDB3EULL; std::uint64_t aWandererF = 0xDA60CA60EC8A08FCULL; std::uint64_t aWandererG = 0xAE32A7464E605A10ULL; std::uint64_t aWandererH = 0xFE86B7E0DE91196FULL;
    std::uint64_t aWandererI = 0xDA4E5312B8454D55ULL; std::uint64_t aWandererJ = 0xDDD3A25193E3FE71ULL; std::uint64_t aWandererK = 0x9C24CBEFEC69391FULL;

    // [twist]
        aPrevious = 0xF1903F130938C7D7ULL;
        aCarry = 0xA171E0B5E3B04439ULL;
        aWandererA = 0xC05FC380A8DBE073ULL;
        aWandererB = 0xEE656D9B0C1643A9ULL;
        aWandererC = 0xFF077E1415B81BD4ULL;
        aWandererD = 0xE44EC63CC8A1213EULL;
        aWandererE = 0xE02A05FBC8B786DFULL;
        aWandererF = 0x9A0EC66D0399D6E6ULL;
        aWandererG = 0xD696F4E2E4558436ULL;
        aWandererH = 0x97CF9FA6599EFB53ULL;
        aWandererI = 0xB05A11AFB11D350FULL;
        aWandererJ = 0xFC198A63705AA5ECULL;
        aWandererK = 0xB087F653C1FEFD47ULL;
    TwistExpander_Athebyne_Arx::TWIST_A(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Athebyne_Arx::TWIST_B(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Athebyne_Arx::TWIST_C(pWorkSpace,
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
    TwistExpander_Athebyne_Arx::TWIST_D(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Athebyne_Arx::TWIST_E(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Athebyne_Arx::TWIST_F(pWorkSpace,
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
    TwistExpander_Athebyne_Arx::TWIST_G(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Athebyne_Arx::TWIST_H(pWorkSpace,
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

void TwistExpander_Athebyne::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Athebyne_Arx::GROW_A_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Athebyne_Arx::GROW_A_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Athebyne_Arx::GROW_A_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Athebyne_Arx::GROW_A_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Athebyne::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Athebyne_Arx::GROW_B_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Athebyne_Arx::GROW_B_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Athebyne_Arx::GROW_B_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Athebyne_Arx::GROW_B_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Athebyne::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 11 of 33
    // Exploration cases: 0
    // Structural maximin 534 / 674; family total 5410
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
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4008U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 137U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3828U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8059U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1645U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 47U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 137U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1375U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1330U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1555U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1870U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1420U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 11 of 33
    // Exploration cases: 0
    // Structural maximin 532 / 674; family total 5418
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
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3288U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3468U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7159U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7339U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 565U) & W_KEY1);
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
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 745U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 835U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 610U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 700U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1195U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 880U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 520U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 970U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Athebyne::kKeyRotateASalts = {
    {
        {
            0xD4E26FDBBEC75905ULL, 0xF14FD3DAD3D598EBULL, 0xCA0189B04AD9349BULL, 0x9540EC75B8A3583AULL, 
            0xAAD228D99B3CD0C1ULL, 0xA20A673D1CBA0E92ULL, 0x251ED60ADB8CC1FFULL, 0x50931A81F3749F1EULL, 
            0xC0478480B39685C6ULL, 0xAFE465FB7FC825C3ULL, 0x8AC1DD2D6B66F552ULL, 0xD9328A185599C51FULL, 
            0xDB6621D1F5D12C41ULL, 0x01416692B79C43B3ULL, 0xDDED053FD9EBCD47ULL, 0x026082630391DFEDULL, 
            0xEC34EDC64C8245C3ULL, 0xD9D354BA5C8565FDULL, 0xD85A26641DEDFE7EULL, 0xB63F20F95523CB66ULL, 
            0x51882E629F47E88AULL, 0xA0876BF98C03357FULL, 0xC29A9B10E15F9807ULL, 0x970772B808A45159ULL, 
            0xECD4B376D9EC76BAULL, 0xE1F9BDBFE92293A7ULL, 0x7F7AD753DED1464AULL, 0x8A6A41E42F75F0B6ULL, 
            0x466FEEEE323F9E43ULL, 0x6C58C4BD080DB632ULL, 0x11E810AC7365B898ULL, 0x2E7F5778C0D6BA0EULL
        },
        {
            0xA0A38CB85244A076ULL, 0xF79038C516599F7AULL, 0x5B3932F974D69FCFULL, 0xBF3D6455F68106DDULL, 
            0x32A34AEA56390BB9ULL, 0xFFDB724FE51DB8F0ULL, 0x16D89726726ED847ULL, 0x0E9E2F83A4CF50C9ULL, 
            0x07C2D929453A5177ULL, 0xA75F1B045013F49EULL, 0x988F6DF792C7F120ULL, 0x2D3A6E6C9113B5DDULL, 
            0x2AD30E96A54248DBULL, 0xB1200A7DE3FC51BDULL, 0x8A3D8C6834B07EAFULL, 0xE1A13359D750B5CBULL, 
            0x65E204C59C7AA8D4ULL, 0x960C9D31092DEF51ULL, 0xF266FF43844CDBA1ULL, 0xADE229717A809572ULL, 
            0xC8883BACC8BA2EF2ULL, 0xCFC8BF56A5088918ULL, 0x23C54349B9B35B03ULL, 0x3DC90245729D040CULL, 
            0xDEFA4442538E2E01ULL, 0x166B2105E7032D3AULL, 0x263D6E1D06C8E7F7ULL, 0xC203938AFB13AC89ULL, 
            0x7504DC0C1E4E6CE4ULL, 0x0F030E7FAF1B3602ULL, 0x0AB85210BB1ABD9EULL, 0xA43CA93E7B5E8DD7ULL
        },
        {
            0x56B70EEEEC1F2DB3ULL, 0x5E83739ED2834B7EULL, 0xF94C784F99B1348DULL, 0x117EBB78E9FA514CULL, 
            0xC6820B74F9713709ULL, 0x941A1563C4F1D2A7ULL, 0xD72DB97124E1C600ULL, 0x1CB081918F025B89ULL, 
            0x9E03DE71AE579864ULL, 0xF5E2D666F606A018ULL, 0x536A28A1FAF7A37BULL, 0x7EA0587CBF6C3144ULL, 
            0xF0BF1033D65A39E8ULL, 0x3AE9FDC22DE072C3ULL, 0xB8F557B34F7088B6ULL, 0x7406612951E0B9D2ULL, 
            0x6E760508A056634DULL, 0x32A200735007311CULL, 0x25678270F71D24ABULL, 0x9539B0639A2A025EULL, 
            0x5CD3A7319E180F02ULL, 0x8412F71CF9736B6DULL, 0x1A3D6A71A6E2C8CFULL, 0x9A13431F53A64C26ULL, 
            0x282461E38EDEB6A7ULL, 0xE7AF68796A04A0F9ULL, 0xC38BEA057C203FE4ULL, 0x90EAD9731D79C6A4ULL, 
            0x526BA9E9B44F888AULL, 0x2A6C3AF269C2A44BULL, 0xC4E1BA6E174D240AULL, 0x2B2571368762B7B9ULL
        },
        {
            0x16B125AD7B6FDC50ULL, 0xF0349E0434E1D335ULL, 0xD4CA0FD18EB15C62ULL, 0x3084B8A10A20A353ULL, 
            0xD5D46E12B4779D2AULL, 0xBFC5654FE2BDA49FULL, 0x3FA5C53512E82146ULL, 0xC2A1C0D500779E4CULL, 
            0x5B326AE8630F6A9EULL, 0xB29583E5DBBBC254ULL, 0xA5FF02E351923C9AULL, 0xA6464E069DC79EBBULL, 
            0xFDC8F15860E6F8B9ULL, 0x283A87E10F3CBC44ULL, 0x8D9B71087139115CULL, 0xB2829D70D7ADB63CULL, 
            0x87B3480AB69F22ADULL, 0x4A0547AB855A6930ULL, 0x21C76EF9532C7498ULL, 0xB2CCA48179D7A134ULL, 
            0x7277619C131D5BC0ULL, 0x181CE8522F9A6714ULL, 0x938C0061F0765F5CULL, 0x77B82E988E325596ULL, 
            0x62AA46B93E01D23FULL, 0xCB08DEEA0CDE55A0ULL, 0xAF6F4D0CBDC130E8ULL, 0x72A20553643AA0E5ULL, 
            0x296E894929B6B5EBULL, 0xF296681090AFB6FAULL, 0xFCF67170654F8F7DULL, 0x7D42904682BB43FCULL
        },
        {
            0x8163B13372666552ULL, 0x526575D58F6F176DULL, 0x97C4713CC8BE63F9ULL, 0xBFFCDF01F1CACA57ULL, 
            0xF854A64455FBADCFULL, 0x14202C591B449D0DULL, 0x341C694EB9EA44EFULL, 0x7110DE6F1AA4F22EULL, 
            0xFF9BE1D356610FADULL, 0xE3E79C8E8AC8DB7DULL, 0xEED61EEC54AEA98DULL, 0x1DE49EBA848410EAULL, 
            0x6FD728C7A210AF68ULL, 0x9B664468AA9F1942ULL, 0x9394EE45A42D6CB3ULL, 0x180D4B1985B09822ULL, 
            0x0D14A4428D0CB749ULL, 0x73406A4ABB6A267CULL, 0xD6DBB3F4D4C2DACAULL, 0x13A8F79C25B8A24DULL, 
            0x1DD0EAE50C5012C7ULL, 0x5D208A5C941CA3BDULL, 0x1A726C464D1B26A0ULL, 0xC6F15CE3223A3108ULL, 
            0x74337C6B1045B598ULL, 0xFE371F7FA225E0BAULL, 0x390972FB8E2D61A9ULL, 0x3B11B34CDC207A18ULL, 
            0x5D543E5649A62E5CULL, 0x17AE8D529B1ED49DULL, 0x01C51F25D2694CE3ULL, 0x2CCB82EF0EA72FD4ULL
        },
        {
            0x6557E2214E88C635ULL, 0x1BBCFCABA2FE26F9ULL, 0x2054CFB1AB64E4D3ULL, 0xB0E55181D28D394FULL, 
            0xA1582F231E5FAC0AULL, 0x90408E07871B516DULL, 0x99F0B89DEEBB4376ULL, 0x909224048B8821F9ULL, 
            0x2C4685A2AA674749ULL, 0x5D271B9544D82372ULL, 0x8771B0BD8139A493ULL, 0xFBF80A067F289205ULL, 
            0x6C91A96730D94C61ULL, 0xAC977796F3D23AE5ULL, 0xFE30235C3911FC92ULL, 0x2B6372FAED554E59ULL, 
            0x29021EB899A29005ULL, 0x9945DC9349AB374DULL, 0x2643DC92F9D63AF8ULL, 0xD02502E1E8D0BAD4ULL, 
            0x15B7E281CB3F51AAULL, 0x465B3697B22FB47FULL, 0xD4956B451CC935C0ULL, 0x73C250EED47F16FFULL, 
            0xBF07A9F6A4BAAA1DULL, 0x09DE5C7F127EC744ULL, 0x7BCC3217D3D62C68ULL, 0x1AE66861376501ACULL, 
            0xD9966C240B73D331ULL, 0xD3CFF1994723998AULL, 0xE2C928EFE3E7663EULL, 0x26C50F3CD72668A7ULL
        }
    },
    {
        {
            0xBF0E30382F82CFE5ULL, 0x9EFF95A65C8991ACULL, 0xF1684DA2D593A81EULL, 0xAEAA057743C8F166ULL, 
            0xD9A5CFED5DB9C791ULL, 0xF8A84B5B97995D13ULL, 0xF3B1E7E48E5E6484ULL, 0x99F35BB52D0FF28EULL, 
            0x32C60A59073B59DAULL, 0xB0ED27FE8F9B56EEULL, 0xED7E3AC2E110CB6DULL, 0xB3D641F9688DF858ULL, 
            0xEA02A6CD76286F2AULL, 0x8A78334C796E6AFFULL, 0xBD8F18EBA84A38F1ULL, 0x3CC3E154D81C0E01ULL, 
            0x1AF8CFD84440641DULL, 0x3E0C094C601E13C6ULL, 0x6014BE1143684AEDULL, 0x4B59642417478A0CULL, 
            0x96201EF87918B2C2ULL, 0x1C6B762ACB9FDF30ULL, 0x65EA3563FAC3BEA8ULL, 0xDB0B28F17B38A413ULL, 
            0x9CFCE6D6898054BDULL, 0x29187B613961B128ULL, 0x33F1EAEE88553B72ULL, 0x92E69C195CDC6B3BULL, 
            0x8F724F66BE95FA2CULL, 0x6CC5362F43A44D60ULL, 0xE7CA428FF68A5F50ULL, 0x9DCB4B923B2B7F16ULL
        },
        {
            0x2478B7BE30A0205EULL, 0x2BE65F6D65C87556ULL, 0x488849C2D8E24602ULL, 0x7E2496231C7265BBULL, 
            0xC6FFB2F80A8E39B1ULL, 0xB78AEB9C092D73A3ULL, 0x5CC7F12CA1FABCD3ULL, 0xA2AF126437804D68ULL, 
            0x0E4FEED0B4526A5DULL, 0xF34A289093FE5DA0ULL, 0x919581CBE97C498DULL, 0x970D4AA9326AE363ULL, 
            0x5E69A4C597A0653BULL, 0xE855921AAFBB0819ULL, 0x9211872C393682C5ULL, 0xCD3EA4C2C435C3D6ULL, 
            0xEBA53272F6FFC8A4ULL, 0xD4C65CF1C1FCC01FULL, 0xD87DA3FAFD85C0CDULL, 0x5B1B72E8C1E2F8ACULL, 
            0x2E82EAD36F88ECFBULL, 0x85393DE5B10E03EEULL, 0x243AF9D18355AF86ULL, 0xA29E0005B04CF071ULL, 
            0x5CA769B8E4D684A1ULL, 0x2E2F9C6871A9851BULL, 0x0B05A5C0022F6680ULL, 0xD7382EA6FB9C70A0ULL, 
            0xAE071DE692ED3FA0ULL, 0x9C0BD29F7363F902ULL, 0xD999919542801230ULL, 0xCA2DB52E2BE4ED52ULL
        },
        {
            0xC0575A5EAB67C897ULL, 0x15A13F456BECC9E5ULL, 0xD3EE6F277462ADD4ULL, 0x709E24FA2F197DDEULL, 
            0x2F44A2382E79EC0EULL, 0xB2AEC15663AF8F2BULL, 0x6FEAD54A6D8D522EULL, 0x6267F1434C18D417ULL, 
            0x909519F4335EB552ULL, 0xA415A5E14EBD9F54ULL, 0xB5708C580F8305E8ULL, 0xD766F9A6BE5617C1ULL, 
            0x2B7D169C23BB5806ULL, 0xE23AD4034EA0DC2DULL, 0x1A42A563689010CDULL, 0x1E9907E4744D33B6ULL, 
            0xFAE1B9961ADD802DULL, 0xF36D566F580F2716ULL, 0x34ABC5C5F998C428ULL, 0x32DF3C23C3FAC611ULL, 
            0x2431221E7AF22507ULL, 0x89744F2E65004B49ULL, 0xC720D0A490163546ULL, 0x90CD1CE9C16BFEA3ULL, 
            0xD39F181F52D0B3F2ULL, 0x5BD195B9F89F4597ULL, 0x388DF14C9B72BC18ULL, 0x696E61C274436E3AULL, 
            0x027CACA0F3BB2A93ULL, 0xDD8DBB27F63CA2C6ULL, 0x8C87D8C79922E694ULL, 0x2609FE723560D4D6ULL
        },
        {
            0x7CA16BE61CDFFDC2ULL, 0xEA364114C38BE3BCULL, 0x5403BEDFA547D4B6ULL, 0x94267B7A8F37DAD9ULL, 
            0x0936BEDF0A5CE055ULL, 0x117F44041F04E2EAULL, 0x6DE653789D7E5E12ULL, 0xFAC8A2269A9A020BULL, 
            0xB0334B3E517FFB37ULL, 0xE82AE92ED0972016ULL, 0x83B8CF88DE23B84CULL, 0x29A7BDCFBDCA6AF4ULL, 
            0x1E575EED8568751FULL, 0x82F12ADA78F22059ULL, 0x8F8B639109358B57ULL, 0x7F81A010188FAD81ULL, 
            0xADBE24755744A126ULL, 0xC81323F7AF32831FULL, 0xB996AC7C97CB2383ULL, 0xD84FB4AC4CAE4C59ULL, 
            0xFF0FB27344367AADULL, 0x0B221E76FF810AB0ULL, 0x934F1C808913F756ULL, 0x4A10F79C11BB0A8BULL, 
            0x2D4FAC0EBE7821EDULL, 0xAC6B4BF608254471ULL, 0x1010F2C19F14E6A9ULL, 0x25EFEACC30ABA24CULL, 
            0xB35F4C40177095DCULL, 0x896CB464EC9DDD77ULL, 0x85D5B901FF2C87F2ULL, 0x6A81F8F8F56D38E6ULL
        },
        {
            0xE998D944F585C2F7ULL, 0x186B504DC153F66FULL, 0x64DF718CA0D05566ULL, 0x828997EB4D1E0D8DULL, 
            0xFA90E1A03B50E081ULL, 0xE1F75298202DB158ULL, 0x1171E04BEA52C110ULL, 0xB351C630997300B5ULL, 
            0xE7D21AA4F31D6B18ULL, 0xD56701743E02801BULL, 0x2E9F7152C08828CDULL, 0x2CD4BE86DA591192ULL, 
            0x61AEC37DA14A5474ULL, 0x7252673E63443B5DULL, 0xA2BD076B905EF481ULL, 0x548A0B651BE7F6A4ULL, 
            0xAED5CE9C51391409ULL, 0x7BF02679FFAA07B6ULL, 0xC0682673F7DF97D8ULL, 0x22332BE92A7A27B4ULL, 
            0x6E7BB209661CEE5BULL, 0x081174286B1424BBULL, 0x93767A6F94901576ULL, 0x1BC8C47C71E7768AULL, 
            0xAFE33654F2F20A12ULL, 0xA1F1280A9C31B5ABULL, 0x7465E94CA9DD8E39ULL, 0x6E0E191881D7EA4AULL, 
            0xC94805F52F22F8CEULL, 0x8CF57BF64CE53D9EULL, 0xBA0687652AD94464ULL, 0xB2D42CC0ECA157D7ULL
        },
        {
            0x4083663AFD979B4DULL, 0x6466BD0A8248D017ULL, 0xA3091B62207A953CULL, 0x4A72F91A20AA8CC3ULL, 
            0xA85A09AFA99CF063ULL, 0x18170E09949B3C38ULL, 0xB9990D646B7F4589ULL, 0xD0D2784F2386D630ULL, 
            0x245B129E55F2F180ULL, 0x49F5E15E94525451ULL, 0x06E4FE0DC5F80700ULL, 0x847B04E1B201CE90ULL, 
            0xD79D37223A6FC4F5ULL, 0xA579C7D76BD46BEAULL, 0x5BB0B83A812FD518ULL, 0x2E8326F945F6BBA9ULL, 
            0x579A7BAF1BDFD025ULL, 0x2ACB70A26CA789D5ULL, 0x283AD4DC3D50CEF2ULL, 0xF788E6376F6C238BULL, 
            0x76266BD20761050BULL, 0xBEF6F18DEA3A46D0ULL, 0xA683C30071B54BC9ULL, 0x36588404209DE0F9ULL, 
            0x12ED5DBD32F147F9ULL, 0x824C0538E4F815AAULL, 0xBAF2F546D80DBBFEULL, 0x103DDA85749B769CULL, 
            0x452F332B9BC117F5ULL, 0x942FF8D24A9F0B50ULL, 0x621FF0521F9AADEDULL, 0xB5349547EE6AB420ULL
        }
    },
    {
        {
            0xABE55FA96084F2D3ULL, 0x2EBECE19C451C386ULL, 0x3EE4556282A0DF88ULL, 0x0EC798681F2443E1ULL, 
            0xA79A14A5578512BAULL, 0x37B50D121BD7651DULL, 0x72B5A98A0E12AF54ULL, 0xE129160E18AA1BE2ULL, 
            0x7DCDC782EDE278E3ULL, 0xBBA2C50FA9C9D1F9ULL, 0x8772194640B673E6ULL, 0x2A140DC86191BA0FULL, 
            0x781757EDAB212C10ULL, 0x6976D2F81B013BE2ULL, 0x5FE4EB536B23A297ULL, 0xFB5AA72801730E1FULL, 
            0x4167AC64F2A6075AULL, 0xC480C245C4360467ULL, 0x5ED3FD265B60EFB3ULL, 0xC5E49FC40282E2AAULL, 
            0xA0A4EC78E1FA1A60ULL, 0x87A24C77CAEFC919ULL, 0x241EE3A932F2D063ULL, 0x54621D2C7A357E41ULL, 
            0xDEC02A7F677BF270ULL, 0xB1DC19B9629DABB4ULL, 0x1AFF976BCC8EF513ULL, 0x9CE093D1F1F893F7ULL, 
            0xED90CFDD2DF2214BULL, 0x5884022071272F9AULL, 0x46A96EEFAF673F6DULL, 0xF809905908487257ULL
        },
        {
            0x0AD4FE33A13C9ABFULL, 0xF796DC8E5E9F3CC1ULL, 0xFFE98F9E8BEA1AA6ULL, 0x97EC9A5D2F92C6CFULL, 
            0x4E8119B85F8085CFULL, 0xB94F8B03E11B02E3ULL, 0xA570460424D77CFFULL, 0x60713C27AFF67C8BULL, 
            0xC5F2E22C9886BD0CULL, 0x213E0037A6776A03ULL, 0x2151571AD8973105ULL, 0x0F5BA7AFE633F699ULL, 
            0x944E14AD55814751ULL, 0xDB69B189321BB0E4ULL, 0x898E569E43CE57B8ULL, 0xB99E20FE71EC7030ULL, 
            0x0201E4A1197A77DBULL, 0x74843185568D5FC7ULL, 0x0FBB436A5852E3A3ULL, 0xFDCBCAC1E13C0F1AULL, 
            0x59B94F2E0D5ED05CULL, 0x9B19C77FB7AAEC73ULL, 0x879B61169A9CAEBCULL, 0x85C638022E78E9EDULL, 
            0x366060C0169D51B0ULL, 0xA56171D852E13A3EULL, 0xB44400AFDD91B698ULL, 0xBA5123A1F7885E7CULL, 
            0xE4FC9DDA74D8820AULL, 0x8619EA7BDA00FFBDULL, 0x3F134166A7DA0FC2ULL, 0xC605E1DB54D23BBCULL
        },
        {
            0xD4BF79823E88A601ULL, 0x2A265F931A6F827BULL, 0x748670D1FCD1FEA3ULL, 0xB638606BD2800E71ULL, 
            0x3D9E826407C3934EULL, 0x67AA4670F42C66C6ULL, 0x0EABD87EF292107DULL, 0xFC0878E8C60450D4ULL, 
            0x2588B6637F622AD9ULL, 0xAF3EA96DB21D2F1DULL, 0xE0783AE700CE28B5ULL, 0x08A036DBF4250BBAULL, 
            0x4B220CD4092B0BE2ULL, 0x8D4299EE32564247ULL, 0x1F97CA954EBA1D22ULL, 0x687B2BB52E30CE0FULL, 
            0x53BFEC4DE64B9D29ULL, 0xFFF7B86EA4488A2DULL, 0x28EC06FFC9E9FC8AULL, 0x7B973E0D427B72B2ULL, 
            0x233B0B3C3173F10BULL, 0x8B24B65D41346075ULL, 0x6BD2012852A368DBULL, 0x1DC13CF31D524F41ULL, 
            0x57FCEC820665A0F4ULL, 0xD08F1314EC8412C0ULL, 0xA73124F6522D3CECULL, 0xF61B5053BAA5353EULL, 
            0xE0C2FF88E4192819ULL, 0x16DED89CB1D0407CULL, 0xF0F0FAC90F02C12CULL, 0xC3B9FD24E367A9D5ULL
        },
        {
            0xB39D9D79049CFA50ULL, 0xF3306616E9B4AB00ULL, 0x894C2FC3A9A71127ULL, 0x78A4A6D80447D925ULL, 
            0xEEE630A492D7758DULL, 0xB35771B16EE3C9A4ULL, 0xFE4D71C8202A60CCULL, 0x999985BDA55AAC74ULL, 
            0xEA4A2EF835A7250FULL, 0xF5F30E8D73753FD1ULL, 0xCB6E01F742FCB5B1ULL, 0x723AFE30C570BE0DULL, 
            0xEE1D2AFC471F801BULL, 0x21357900B8C5F9F3ULL, 0x214DBEE47DFB7CCAULL, 0x865FA8DD8A7BA06BULL, 
            0x988AD3529FA7C5CBULL, 0x984EEFFB90E4282DULL, 0xEB97CF3C3B01E555ULL, 0x332D5D9CA848E67EULL, 
            0x178D1D37D51C8A7FULL, 0x2C6AEE5F3B041D02ULL, 0x21CE2B9501551B7DULL, 0x495BAD4B3E53B080ULL, 
            0xAA1B3F4D2709D2BBULL, 0x8003EAF62DF433CCULL, 0xBA81B5598B3583D2ULL, 0xD9C8616438A3DCBEULL, 
            0x73A4A095AB625E59ULL, 0x6F778144D4C3EDD1ULL, 0x86EF03845551ED7EULL, 0xDBD7CD9668D7328DULL
        },
        {
            0x6E20D7F0ADD403E6ULL, 0x67B0CA60C5E1405EULL, 0xE8FD4D8E166A477DULL, 0x6D9A04F752EAE426ULL, 
            0x0B60DB4720B6E1F5ULL, 0xF261DC7603040CBBULL, 0xBFFA6EAC339C73A8ULL, 0x9C5635AE95AC83F7ULL, 
            0x517207F24B79F0CAULL, 0x2D07C411544675CEULL, 0x9FE43AE161ACFFF6ULL, 0x96463E805F73BF69ULL, 
            0xFB3BA45F42BCE527ULL, 0x16715205B7B5AB79ULL, 0x4969175DD23B18F0ULL, 0x599D474721A9A325ULL, 
            0x11FB5BF14D7CBC68ULL, 0xE283114D375C91C9ULL, 0x1E7E6F923FC34199ULL, 0x01187775C81692D4ULL, 
            0x99A0F19DF66C079AULL, 0x10250F883EDA8DE9ULL, 0x77DE0AE0AEA2FAA6ULL, 0xFC9C2F79B8C8A28FULL, 
            0x215134F28448ECEEULL, 0x609B0EF7C4E35AD8ULL, 0x07A926A63DF8EF9CULL, 0x2455392147DBE1F8ULL, 
            0x23E509DE4609BF45ULL, 0xD3F38026C1F99712ULL, 0xE0044260DEE1CBA5ULL, 0x143A6173B358B26EULL
        },
        {
            0xE05A626336CAC1D8ULL, 0x38D3BC40730FE278ULL, 0xE2C86AB9A95A644EULL, 0x9644D54B2DD7DFE5ULL, 
            0x6EB1B89FC9465B10ULL, 0xC97DB117C485D7B3ULL, 0xB793F779FFD6987FULL, 0xC41E2616A2FCEBD2ULL, 
            0xD032E929BE001A53ULL, 0xA074699F231933DBULL, 0x75EA6B31201BE2E9ULL, 0x82C4D0A8000247E7ULL, 
            0x88C3735F5100A31CULL, 0xAEBFA0EC2BF62A75ULL, 0xC77DD96FD56FF32FULL, 0xF1C214338627878FULL, 
            0x170781497D862088ULL, 0xD3C4A7F5817B7F51ULL, 0xDD2E7E91868F543EULL, 0xF8478902FA2D528BULL, 
            0xCD655513E2A14088ULL, 0x08FE280737652F9DULL, 0x15B28E146FD26209ULL, 0x24FDAF571C71B365ULL, 
            0x91413C7496009E7BULL, 0xE5624035E25205D4ULL, 0x0921F00C8B535110ULL, 0x45F0A276B2912515ULL, 
            0x496379D5BCC8FBC9ULL, 0x6433A49059D5C5F1ULL, 0x3385D13D49C882FFULL, 0xAEFBD74268D5FB51ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Athebyne::kKeyRotateAConstants = {
    0xA348308F2BF002ACULL,
    0xDDBE0D672EA9DA19ULL,
    0xADA2AC9EAAC01E80ULL,
    0xA348308F2BF002ACULL,
    0xDDBE0D672EA9DA19ULL,
    0xADA2AC9EAAC01E80ULL,
    0xD1D4702257593B57ULL,
    0xBC8D40E4DD048163ULL,
    0x64,
    0xF8,
    0xBA,
    0xEB,
    0x15,
    0x7A,
    0x85,
    0xA9
};

const TwistDomainSaltSet TwistExpander_Athebyne::kKeyRotateBSalts = {
    {
        {
            0x7237BE47C9350817ULL, 0xA5DAF008E7867E43ULL, 0xEF5D1DE6446BE3E9ULL, 0xE00D487030BBE577ULL, 
            0xEE6F992D90204F17ULL, 0xE12FD75617193773ULL, 0x3E116F7BD83B2986ULL, 0x64FFD60076CB494AULL, 
            0x169924A209FAD6D8ULL, 0xD48CC119B241E580ULL, 0xB444D86CB3650EC1ULL, 0xA5E7A434F9988684ULL, 
            0x4357068D3A4A1783ULL, 0x7DDAFA9A4876D200ULL, 0x407627AE7165310FULL, 0xF69EF425E76A7392ULL, 
            0x92D80EE369BA7FC6ULL, 0x5A1D8D0C44BDD87FULL, 0x87F7B87B60A47512ULL, 0x85E2D7D5AFF82E2FULL, 
            0xA65A3DE165D29D8EULL, 0xB4D7900B3BDE3737ULL, 0x3B7B1828507C3089ULL, 0x482C77997C3ED901ULL, 
            0x04B1874ECF6FFBC4ULL, 0x0F43D64628DB82E3ULL, 0x62E35981FB40A217ULL, 0xDF1FF26F6209611CULL, 
            0x842C64EB26E3C6BEULL, 0xE3E8D3153521E346ULL, 0x137EA60E7ACA4475ULL, 0xA0571161811D4DB9ULL
        },
        {
            0xC588BA814DA07EBBULL, 0xCA6F6EBE0C2BDACBULL, 0x9308634DD4F6B4E9ULL, 0xFB384804699C8F00ULL, 
            0x86D66FD382BB3805ULL, 0xD24A828CC28E97A2ULL, 0xE47C3729BF7AE158ULL, 0x6E29731B80238A03ULL, 
            0x3B0F3FAC62D6EB14ULL, 0xD9BD2728354287BBULL, 0x5322A4CDC60ED015ULL, 0x936304760E369925ULL, 
            0xFC156ED6EF46D754ULL, 0x04484CE16E43C66EULL, 0x0A4048552A768779ULL, 0x5726F7E009D29DA5ULL, 
            0xFDD5E0120EA62330ULL, 0xDA71A8035F08270FULL, 0xB873B7B747D34D3BULL, 0xACFAC7CAE61702D8ULL, 
            0x339FECD0F74056F2ULL, 0xC10A421FD5FBF89FULL, 0xA127F4611832FF65ULL, 0xD99BDFC1786ABE4BULL, 
            0x32CDA4A0C9995965ULL, 0xD77A8AA110CE560EULL, 0xC8E9E57AA8A0E413ULL, 0x071D089274344830ULL, 
            0xA9C72B038EECDA2CULL, 0x7C343CFB6DF129F7ULL, 0x757761468B266BACULL, 0xA873736EE0BC7FA0ULL
        },
        {
            0x666D41A912ACD669ULL, 0x5759E3858AA79D14ULL, 0x20FEED9CFA0151A9ULL, 0xB81FF66357EE7AEAULL, 
            0x461E9E52976EBBC8ULL, 0x402C0EAAB821B841ULL, 0xDD46E14E5651CBCEULL, 0x508D788628915EE5ULL, 
            0x0B47D80096D452DBULL, 0xD65DA2ABFA9220EDULL, 0xDF09CD5E0157A183ULL, 0x327BD94FB4FADEF0ULL, 
            0x2EC998784E508715ULL, 0x413336314DF43CDBULL, 0x8814449E64C6037EULL, 0xF2A177A025D2C011ULL, 
            0xC9628E80DEEC1A75ULL, 0x518E13C751FF2228ULL, 0xB93560DA737C379BULL, 0x96A542E76A67121EULL, 
            0x892025A6FD20FBD9ULL, 0x0F6409B978A197CEULL, 0xCC7C05A796373D42ULL, 0xD51F316ED4F16A68ULL, 
            0x5907B653660A2EC4ULL, 0xF756936580637D85ULL, 0x02443925C57DD777ULL, 0x203423796A818C92ULL, 
            0xBE68984FCF368790ULL, 0x2872FD3DAA8065EAULL, 0x76579EFC3107994AULL, 0x8386735DB5FF2B44ULL
        },
        {
            0x2EDF23825EBB2FEAULL, 0x50FC318C3C4360C1ULL, 0xAF76CACA13B5A9B1ULL, 0x92AA8F03CE3CA805ULL, 
            0xA8095EDD9FD414AEULL, 0xEB2D64B414B60309ULL, 0xE00088878765E53FULL, 0x47357AC38E0B48DAULL, 
            0x51DF33A4383A7DCFULL, 0x4DFB23EC35FF1F1AULL, 0xA605EF262CCBB79DULL, 0x3544A01E94B71A70ULL, 
            0xB545A283D5E6AB1BULL, 0xCCF159693EF6A205ULL, 0x288F204EC3BED9B7ULL, 0xDDE33003E35646C3ULL, 
            0x022E229DE6B810BDULL, 0x54D8CD4C74A16818ULL, 0x55B08E3EF9B8B4EEULL, 0x53F10443C2126662ULL, 
            0xC148F000BECB3DF4ULL, 0x74D1D64A9F63FFEEULL, 0x1B03A529CCC29A48ULL, 0x3679D35E2662AC71ULL, 
            0x468B7F3B8E5B8DE1ULL, 0xB3143B5BA92B55A4ULL, 0x8C450182472626D6ULL, 0x394CEE2CEEA7599CULL, 
            0x7AE3C1D918E5ECB1ULL, 0xDC9A8DF75673E69AULL, 0xA9F7A60EB0B3C946ULL, 0x1F47CBD55A6DE3CFULL
        },
        {
            0x42FAA3585FA57EB9ULL, 0xD6E7EA200798B44AULL, 0x24801D57B433F8A0ULL, 0x32144292B7962BEDULL, 
            0x8A68ADEF39E0CD99ULL, 0x34B988527DCE69DFULL, 0x7BAB4927FD4EA13DULL, 0x29112C27B1EB8207ULL, 
            0x40CA9BCF9AA21158ULL, 0x1E83F7960BFCE047ULL, 0x5B97E11D751719D6ULL, 0xD0D5F376E4EEC03FULL, 
            0xEE153F0D89FAB122ULL, 0x356DFB7628ABECAAULL, 0xB38F1F1D438677E7ULL, 0x60978DE18692E0F0ULL, 
            0xFEA403A148C262D9ULL, 0xE4FD8924EE26395AULL, 0xD7A5AB582DB00F63ULL, 0xCE8548D7CBC0A656ULL, 
            0x197887B2A93946A6ULL, 0x1B343D453290ED67ULL, 0xDA456663A19133A8ULL, 0xACAADABAB9A3D99FULL, 
            0x61A677A64358EF17ULL, 0x38A3E485C0B847E7ULL, 0x6E88ADA4BC5B8E0CULL, 0x1983B7F8952E2C7DULL, 
            0x4009EA6758496B9CULL, 0x7A13102296C52EB7ULL, 0x495181B31DE6FB99ULL, 0x436120ACCBE24722ULL
        },
        {
            0x1769E4B9B1FAFE0FULL, 0xB25C130B920BAD15ULL, 0xF9FCE13147D2D4FFULL, 0x275B6EBC8F303256ULL, 
            0x3E702D603BC7498AULL, 0xC44699270AEC3AABULL, 0xD70FBDE81E612761ULL, 0xEE6F6ADD1A387B69ULL, 
            0xEAF4F1F3D7CCA790ULL, 0xC962FE9F00568EACULL, 0x4714DEA4574C7773ULL, 0x54134077E4F70DE2ULL, 
            0x98FC2DA2D8AC93D6ULL, 0x0D79698D282B240BULL, 0xB96D25BEE090D9A1ULL, 0xC27AF73AE0809E5EULL, 
            0xD089E6E55FE15C11ULL, 0x26D0D6BE6F323375ULL, 0x7352E31B2944A477ULL, 0x5561EEE6CAA5538DULL, 
            0x777A75B48E1004ECULL, 0x7F3E015F409D3504ULL, 0x1EBAE532D6588AE0ULL, 0x41868EC00575F517ULL, 
            0xF3065007E1816ACAULL, 0xCD28F6249AF35CF0ULL, 0xD2E64893FAA6EAC1ULL, 0x00FAAA777CA7D047ULL, 
            0xC2B2329F291BDB9AULL, 0x00BC488135B781D1ULL, 0xB56CEC3DF005625FULL, 0x380E51B0838A9C7EULL
        }
    },
    {
        {
            0x8497FECB393AA06CULL, 0x29FA545C0DF29E70ULL, 0x80A86F28AA9B5903ULL, 0xAADAB98BB66FAB76ULL, 
            0xE5A27F22BA31E137ULL, 0x0A55ADEDEAACD792ULL, 0xD2F6E6F1F6042335ULL, 0x14BAD01E1DD687F3ULL, 
            0x6A2B95801B389781ULL, 0x596B300010EBE044ULL, 0x5FA72A56D8C13DA4ULL, 0x4164F607126428C5ULL, 
            0xF93285975C2A7D36ULL, 0x5E052172082069CAULL, 0x10FB997A7B9BECBDULL, 0x79D50728D8806E9BULL, 
            0x1F4ECA47F94AC350ULL, 0xBF781863B912F075ULL, 0x472CEC2A80906592ULL, 0xF7E78D4495C5F6A4ULL, 
            0x6B407F05F5D60082ULL, 0x428FC88A9F485B2CULL, 0x7B1D4EE7AB599546ULL, 0x1F05C60F4561FDF5ULL, 
            0x3000FDD7766D8489ULL, 0xC8F9DC5B04FBAB5EULL, 0xE6C1C1C83D42D322ULL, 0xE82C7CB5E1551D6AULL, 
            0x424CDC940A414B29ULL, 0x44C0B73064258DAEULL, 0x31AA63DE12998D51ULL, 0x4C7538004B4CF4EDULL
        },
        {
            0x8172B49A8EC3535BULL, 0x803370B7BD740C2CULL, 0x3B66BB0C15C2D443ULL, 0xBDC723BBAA8C1D2AULL, 
            0x3A7FE83B10380F11ULL, 0x24E548648AA92381ULL, 0xE44CFAB6FB3EAF34ULL, 0x8AC138B89AF14DB6ULL, 
            0x74F8F6759B3C9B62ULL, 0x0CC26736B08AAFBCULL, 0xAAC30F9002F673C5ULL, 0xC185CD59101E737EULL, 
            0xF07FB58C7203A036ULL, 0x96C75F2BE633D02CULL, 0x0536D0F1779A2FA8ULL, 0xDBAD32FFE2B4FFDCULL, 
            0x49079D286F817CD1ULL, 0x84517C70B5A8E008ULL, 0x9B75F5977D88AD41ULL, 0x505AAAC424C2696CULL, 
            0x41F64F9CDD607041ULL, 0xD4A440487D31C821ULL, 0x0B0CE2752A9E2B88ULL, 0x093E99D99CEA2E01ULL, 
            0x42F5B1C7F2E69C52ULL, 0xBEA033FBB2FDFB98ULL, 0x0C8A9CCF66817704ULL, 0x743AE20041A991C1ULL, 
            0x4F8D9A507B9B97AFULL, 0x997B00C4754B5C55ULL, 0x978C381DD96E9C3EULL, 0xE5275F6B23B7AC06ULL
        },
        {
            0xFAB7944AB5D3D0BDULL, 0xE84B06580239D229ULL, 0xBF5EEF9826DC4486ULL, 0x8AEA8108141C056CULL, 
            0x2C5BD8150631A204ULL, 0x712754A8EEBA353DULL, 0xB2439D8A8D611C48ULL, 0x2B6A4C1A912A1748ULL, 
            0x071993C31B508A01ULL, 0x86BC169C267FD462ULL, 0xC817FCDE42ED357CULL, 0xEE86B030751FEED8ULL, 
            0x6AA52D5903459E7BULL, 0x3EE13E0D1D547E95ULL, 0xE1EE99B8A93FD451ULL, 0x2D74DD7C40830586ULL, 
            0x5729F57AD17B10D3ULL, 0x76B573861E111811ULL, 0xBEDC23C83805937CULL, 0xF1278CD1E812D21FULL, 
            0x7DCB472301094F00ULL, 0xC95E47E5848836C8ULL, 0x093A2A20ECF28925ULL, 0xED9B9C5B59B55433ULL, 
            0xC5CD6FBC96712EB1ULL, 0xBCDCFD1400115ACCULL, 0x629596F21BC51D79ULL, 0x59C75695B93B3D8AULL, 
            0x242FA5E679E92647ULL, 0x7C3535642096D8C8ULL, 0xAD0C0F3E2D4267FEULL, 0x822BA1CD551258FDULL
        },
        {
            0x66073A6FFD24B5B6ULL, 0x65EE216162B984A5ULL, 0xFC90949543E6AD95ULL, 0x42B890679545B80CULL, 
            0x863EFE91B45FF3A3ULL, 0xDD492C8C4E487434ULL, 0x593C3F657A91A5ACULL, 0xCFA49550A422A547ULL, 
            0xD0A9AE9CC19DC889ULL, 0x7AF85CB3A36B2DE4ULL, 0xA9F3061238BBD42FULL, 0x35BA9F3FCBE9E593ULL, 
            0x685A89725F14CB34ULL, 0x54D2FF98EC7C87C0ULL, 0xF453F907EA47F694ULL, 0xBAA9E4C2DCE0B9A4ULL, 
            0x54194A022D8DF788ULL, 0x9B7DA59CD91833C8ULL, 0x8A99EDFA68D35B2CULL, 0xE749B1FEAFDB40F2ULL, 
            0x909AD2BB4ED45616ULL, 0x3F217DC5EE8FC645ULL, 0x5EAEB593501FE82FULL, 0xA1C63805CD7B2935ULL, 
            0x1502F0039525AA09ULL, 0x492FB4E6E687FD7AULL, 0xE1A4317D20EC928CULL, 0xEEAB2FA187300004ULL, 
            0x35E6436A3934A58BULL, 0xAA5D7977611597E1ULL, 0xD274D762633857CAULL, 0xCD14880B8136DA69ULL
        },
        {
            0xB6850E93E2ADFA8FULL, 0x909001DB3A6AA9F5ULL, 0x53F83D720D492012ULL, 0x2F7F3B3F226BD9C3ULL, 
            0x6E8D21579F0A6343ULL, 0xFFB52126BCD7EDA0ULL, 0x99A22C57661BD347ULL, 0x00A69844F57C1F06ULL, 
            0x9D6F8E9B0D06B191ULL, 0x8F2D594F5B40735EULL, 0xB826A65889F58D25ULL, 0xD86AE188958ADDA4ULL, 
            0x2EA829CC054507B9ULL, 0xE6B99115BF22524EULL, 0x2315738EEB828508ULL, 0xB098C1B976E5152DULL, 
            0x29C99DCB26E979D8ULL, 0x9A773ED0BB71F400ULL, 0x15AC0B9E9EF802B5ULL, 0x47EBD0BB7F47F106ULL, 
            0xD7A534E46A43C0BDULL, 0xB379C178AA6FA4F5ULL, 0x4D7AC413BA0F750CULL, 0xF3BFDC1AE8E78A7DULL, 
            0xE3332E7F7568F79BULL, 0xE33ED0675DC0846DULL, 0xE47BBA9F1B1F9E4EULL, 0x9529B547ECD05C49ULL, 
            0x16F09651AAD69D52ULL, 0x3290BB9AA0338866ULL, 0x3F23B197B5347568ULL, 0xF499712A033F993CULL
        },
        {
            0xB8EEB4DF3868CDBAULL, 0xAE519F024C363934ULL, 0x375C0ACA9E4964A8ULL, 0xD10406EC99527651ULL, 
            0x072D5209FD625648ULL, 0x7F5D857347BA1DFFULL, 0x7D22994B7C2C9E48ULL, 0x7D34796B4D1FD41EULL, 
            0x0BD0729A1C33228DULL, 0xE354B928CE6E696BULL, 0xF8A27CE0CD72889CULL, 0x055D039B267F83AEULL, 
            0xE88A4B1A2536E2F2ULL, 0x43212E7E02479F60ULL, 0x3B647A4E9B8072B8ULL, 0x0528C19A04F81E28ULL, 
            0xD720C02CD561FA5BULL, 0xCB91E2DBB7FB4CC1ULL, 0xF6C3AD778A62D3AFULL, 0x25AC85709ACE0F23ULL, 
            0x17C8D0B74C0B8FA0ULL, 0x96DDB2562A640617ULL, 0x36A3F20203A27A13ULL, 0xB86F9D02A61FD89FULL, 
            0x652C023D289307DDULL, 0xAC290285AE617C0EULL, 0xA7E772D6A59591E7ULL, 0x556438431350544DULL, 
            0x2907D10055BBABD0ULL, 0x379B8A57EC4B9E74ULL, 0x4D75EC3A06CF917EULL, 0x8E06D0F52AF487F7ULL
        }
    },
    {
        {
            0xD495414086937984ULL, 0x31BBCD50003064C8ULL, 0x541C786A0BFD9E9EULL, 0x02A6E98269E16E54ULL, 
            0xB04E725F748E6DCBULL, 0xDB06332643A780A3ULL, 0xE8247E675BCCB2CFULL, 0x8C40B2455B7C9B0FULL, 
            0xB93E73BC3DC82EB2ULL, 0x8858D0D48913C949ULL, 0x0D263FC0E5DD9192ULL, 0x0AC9AE2819D1D169ULL, 
            0x70C3F37DA4276B73ULL, 0x5DDDCA4C24137EF0ULL, 0xE067D132224B0742ULL, 0xF44B4F9F5F090401ULL, 
            0xD320CEA89F4B4936ULL, 0x45456F6893AD83C8ULL, 0xF5E16C2E1D6AFE05ULL, 0x33A70EEE5ACD6909ULL, 
            0xFC3F7CCAC4930D81ULL, 0xFFC9EA28B962542CULL, 0x84A6AC644E202762ULL, 0xDFBB117112854CC9ULL, 
            0xE8C5C138191C6FB9ULL, 0xC81CA1A32C5E5E7DULL, 0xD4DCDE1AD98EDE01ULL, 0xA6FB31F10EA24021ULL, 
            0x1114DD8BE7BBED0FULL, 0x8D1D28BD379EF5A4ULL, 0x706A95C610B3F487ULL, 0xFFC54337FEC00E41ULL
        },
        {
            0x2FDFA7C7E9028C7AULL, 0x65459C3DE9F3D6B6ULL, 0x481EE1E7B7CA4170ULL, 0x1F29085F6493A79FULL, 
            0x735408665992CEDDULL, 0x434D29C5DC301BAAULL, 0xB87CDDD917AC4B36ULL, 0x24E9AD17CE587728ULL, 
            0x500B7E011D7230BBULL, 0x0F629AD721A7DF59ULL, 0x9F42FCF1E9D57301ULL, 0x965B64F6E6860A0CULL, 
            0x47C9862866922116ULL, 0x4A60E58EBE59B85AULL, 0x71611FAAFAD1C44BULL, 0x5F58C4BBEDB2EBEEULL, 
            0x592E94FC3EF6A4A8ULL, 0x63908A431FBDE02CULL, 0x2C914CFBBCCAAB00ULL, 0xA96376C70406D3BDULL, 
            0x4B3639A3DC13FB4DULL, 0xCCA3DED05591F7FEULL, 0xCC21F33546FFBA44ULL, 0x7C40C4FBCE8E52EBULL, 
            0x48C57E65558FA3AAULL, 0x75D4EED9081E2D68ULL, 0x7E318B30CFB87A85ULL, 0x77405B461857EE9BULL, 
            0x333CADF972862614ULL, 0xD21461F074D634E8ULL, 0xB3366C62E0D3CB0BULL, 0xC6B62A9278EA2328ULL
        },
        {
            0x13EE04AF58B0DAB4ULL, 0x1CBA4F720D44ECEDULL, 0xB425D8E69442530AULL, 0x062B1A8BD436F319ULL, 
            0xABC1F944F4B57384ULL, 0x0D4D7D9621D369FEULL, 0xAD7917F4F6119C28ULL, 0x4797227A1F3E17E4ULL, 
            0xDD5B403CB7325C1BULL, 0x7070D80C1FA0C126ULL, 0x0744ACAFDD730E1DULL, 0x5A675AE38E72BE28ULL, 
            0xE849C00249221DB7ULL, 0x2850E8714B70649CULL, 0xF4D3A6A89CBC022DULL, 0x2149EF2040ACA277ULL, 
            0xBAA25B96C5197A01ULL, 0x8027BAA9D0C265D7ULL, 0xB79278C65DD12CDBULL, 0xF614C1510CC710A0ULL, 
            0x894D84E20F4E5A2AULL, 0x45DFC2860D2B899CULL, 0xF2A56C8770C3561BULL, 0xF7CFA8FF3A75D942ULL, 
            0x11F3D97F7E578B1FULL, 0xEF8C4048F4C1C81CULL, 0x6CAF8F7E7A5C254BULL, 0xFFCBAE436FFA5FEFULL, 
            0xC275A969E2D4AA22ULL, 0xA28AC3C1B050EF3FULL, 0x152B116F32DF588CULL, 0xD419696DD1A0ADF0ULL
        },
        {
            0x16AC95DF0437D119ULL, 0x745F8A78C0052DF2ULL, 0x675DA41BDD9AA3B9ULL, 0x2D1D8844F3CFC036ULL, 
            0xE6F32DA174935539ULL, 0xC9B43E6645C94856ULL, 0xC0B9CFCFD7203E3AULL, 0xB6E01CDE3BF4821DULL, 
            0x9D126B56A3E8BE89ULL, 0x272BBE729FA7430DULL, 0xFB53EC3C5CAA5DC2ULL, 0x2A372C3F3642686AULL, 
            0xDA1FEAE5A43F4335ULL, 0xF0236DE78AD3F3FFULL, 0x6E26AE7B31D82ADCULL, 0x368A18F8F08D05C9ULL, 
            0x16C41450D74A2A93ULL, 0x410669A3DCFCFC79ULL, 0xDB4DCA1CE33C9F2CULL, 0xADDC7715F1C428D3ULL, 
            0x1A0135772368D717ULL, 0xE3780F06907A6DE9ULL, 0x95A7AAA082C9977CULL, 0xE5D203656AA4FEE3ULL, 
            0xD974F2E327C9DFCEULL, 0x94626996ACEADBD8ULL, 0xF8DBBA9B834F1C74ULL, 0xEB4499D2FE6B8C0CULL, 
            0x8D00B29E19068351ULL, 0x8CA77C8A46977ED5ULL, 0xB695CBE108754BCFULL, 0x1D7F27014EEFC0D4ULL
        },
        {
            0x088F7DBF9D37BC94ULL, 0x35FD387D57EE3D27ULL, 0x3F30D15AF9A4C398ULL, 0x764D3C10A1B8379AULL, 
            0x21466F0197BBEBF6ULL, 0x3F8A8A68970612CDULL, 0x8BB7EFD626515898ULL, 0x33C03A499D0B2896ULL, 
            0x4F7616B69717D082ULL, 0xD1B3C8428B2B0E0AULL, 0xD02354F7A5E070B3ULL, 0x1E11392473434447ULL, 
            0x77F7A3AA12EF5C2FULL, 0xA2D8C856362F14ECULL, 0xADE4D4B35C1A555CULL, 0x53E7DC16F8C1E072ULL, 
            0x172CD14FB4355F33ULL, 0xFA0F8E4CCCD3BA88ULL, 0x33103DDE63616E17ULL, 0x0C4662BB4E9B0CCCULL, 
            0x336BD62DCDBD70E7ULL, 0x83F30DCEE0E09DF8ULL, 0x6B0A613F2965D529ULL, 0xF3D7902EF10848D9ULL, 
            0x377B60CDDC756B84ULL, 0x4080F1078E1576FBULL, 0x8E57BB122C4E1EF1ULL, 0xBE6B2C002F17BB69ULL, 
            0xE9610E71EC22772BULL, 0xA13325DB27E22083ULL, 0x7FC82B6A4394207CULL, 0x6C28112C882E07A7ULL
        },
        {
            0x3437D1FA51DF1E00ULL, 0x918C7CC8C0AEEAF1ULL, 0x80D051CF5754832DULL, 0xAE41503A99DC9522ULL, 
            0x1126638B8D67F1AAULL, 0xC970F91F2884480AULL, 0x209426D59815DD0BULL, 0xBF2D089F80DBDC64ULL, 
            0x0D46871F8CE83474ULL, 0x73D38F0C6E051348ULL, 0x4B2018C93463C4FBULL, 0x649C79BEA4702FCAULL, 
            0x38DB93737F1FF72AULL, 0xE2B40FA3BEFFD915ULL, 0x508B58CA71A5EBFDULL, 0x2F243283D86A8D67ULL, 
            0x954B70373FA9BA60ULL, 0xF562E5E3CA6DCD58ULL, 0xF413B3CF746628FBULL, 0x35E9AD2426C16457ULL, 
            0x4126965E5682CDF1ULL, 0x0CFD6BF62C223AB1ULL, 0x7A3424B97C6A052FULL, 0x0DC7019664F370D4ULL, 
            0x6CCEEBFDFD17C7F8ULL, 0x15CCD99C68C1B9BEULL, 0xA12466C708989867ULL, 0xE10E0F3673D539BDULL, 
            0xDAAECEC0DE20124BULL, 0xE061E63416CD9B1CULL, 0x4A85780A6CDCADC3ULL, 0x2CFEDEA21D5EE735ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Athebyne::kKeyRotateBConstants = {
    0xF3D7EDD3F7C3F718ULL,
    0xD17A12CA12882FF6ULL,
    0x79149BD7CBE23099ULL,
    0xF3D7EDD3F7C3F718ULL,
    0xD17A12CA12882FF6ULL,
    0x79149BD7CBE23099ULL,
    0xEE48388AE099C0C1ULL,
    0x400A2B7C160372F2ULL,
    0x67,
    0xD9,
    0xD7,
    0x53,
    0x21,
    0x0D,
    0xA3,
    0xB9
};

const TwistDomainSaltSet TwistExpander_Athebyne::kKeySpawnASalts = {
    {
        {
            0x4D26D37A67EDD5DBULL, 0x53451F08BF094B02ULL, 0xC66821E29324BAE9ULL, 0x52F573E8E486CB2DULL, 
            0x8EAE3CCD7A34945AULL, 0x4CD989496E6BF3D2ULL, 0x58C748C9CECF2D91ULL, 0x6748EEF19B13D0CDULL, 
            0xDBA9BFBD39AD7B7AULL, 0xBAFE01284A824AA4ULL, 0x61BF821884738C70ULL, 0xCCC3517212EEE71BULL, 
            0x7A522E9BF0A87FB9ULL, 0x65BC1030A587AD9CULL, 0x651541331EA163A2ULL, 0x472FE2E0BF810A32ULL, 
            0xB1FFD7246910B434ULL, 0xBB82501411E91431ULL, 0x863E39EC80954ADFULL, 0x75B1EBBAB234E40EULL, 
            0x5194D3664E8023DDULL, 0x34642DE0B4C9A2BAULL, 0xDF9BD0B7773B384BULL, 0x0F9D671BCB55E9C9ULL, 
            0x6E3BD329A0C47B9AULL, 0xB337BFE372FC77C7ULL, 0x12FDA9205B7CED70ULL, 0x2AEC13FE9858D3FDULL, 
            0x11F5EDE610F70AF5ULL, 0x243847650DD6154DULL, 0x74D034D1BE57856BULL, 0xC45144E86AF48890ULL
        },
        {
            0x5E2C1B3897AD7D91ULL, 0x912D7539551DFC79ULL, 0xF2F566C6B43A98CAULL, 0xE612156F4213CD38ULL, 
            0x34A7E3BFDE9F0881ULL, 0xAE16E918BF195963ULL, 0xE3725C7EA1E1C00BULL, 0xACC6BCC94947F0B4ULL, 
            0x3CE598AE8A1B82EAULL, 0xF97E3F2E0B4C5A94ULL, 0x1372180B4663A53FULL, 0x18C782E5CC4FFCE1ULL, 
            0x042A7E3C0BAC3DA3ULL, 0x884550CF7BB938A7ULL, 0x4C8EDE2160A1D388ULL, 0xFF51F0AC656CE0D0ULL, 
            0xD95ADBC5C977ECA9ULL, 0xAF6E122DE81999BFULL, 0x720A8383223A723AULL, 0xF260B1624476DEA1ULL, 
            0xD7383FA177EF9042ULL, 0xD86C253C911EB634ULL, 0x8E6A2F01A5F013DAULL, 0x1933A4C7D1FC7E70ULL, 
            0xB0E568B714871FBFULL, 0xE115F446E3C44C91ULL, 0x65259DF954CFB1C4ULL, 0x25EC25F9DA69761AULL, 
            0xD5F4BBCB378EF45CULL, 0x4590D7B26F19D1F0ULL, 0x7EADED16E6CD755DULL, 0x2DEF2F7CC9AB2DFCULL
        },
        {
            0x287236EFAF78E57AULL, 0xD645D6F058448FE2ULL, 0x4409CDF41628EB52ULL, 0x493958B929829BAFULL, 
            0x50590850C5C4E2D5ULL, 0x2E70097723F36A43ULL, 0x0CAA60DD767183B1ULL, 0x8864CC95CF2030E4ULL, 
            0x70E8286F62BA2B92ULL, 0x2B81A237C2353829ULL, 0x5674A112C22F1889ULL, 0xC5A23D8A1B1A86E8ULL, 
            0x7447AFACB2618BD0ULL, 0xE7B30679A14E53A5ULL, 0x168D7F3D047F908BULL, 0x2A16A014053C1EA1ULL, 
            0x2F50BB59D8096B20ULL, 0x297B50FDD1F3653CULL, 0x5817CF5426AE250FULL, 0x1294A7E0E6FFF594ULL, 
            0xD20FD54F0E13C99EULL, 0x782545AFF687AFCAULL, 0x1682845ED9BAB530ULL, 0x6BA6BCDA4BBA23D3ULL, 
            0x42013F54766F1798ULL, 0xC213A1ABF11460F2ULL, 0xEE88251C1C4F0438ULL, 0x0E07E00288CD3A75ULL, 
            0x7EC69E20226891B2ULL, 0x2DB912DFB7DDCA0EULL, 0x9140D971485B14CBULL, 0xA2152CFD5A60A6A2ULL
        },
        {
            0x8DD9185D460FFAC3ULL, 0x729AA2BCBE3D38C8ULL, 0x8E71906A9285C7F2ULL, 0x56A36AF5361E0503ULL, 
            0xAB25F77771BE9D33ULL, 0x9C42FD1F6B9F492CULL, 0x79C643052D4BB062ULL, 0x60982AF5F9CD3E81ULL, 
            0x79BAAE76E8AF8BEEULL, 0x5CC4CAD0566D44C7ULL, 0x73A1EE5A4EB78BBDULL, 0x91D51647B0615204ULL, 
            0xB7C3D9C5A435DFF1ULL, 0xFCC614B74A018A44ULL, 0x78A663A9508C259CULL, 0x2E1C520AB44D37A6ULL, 
            0x804A16B1ABE58A29ULL, 0x3386F839907502EAULL, 0x5FF9840B9131CFB9ULL, 0x77A11DBF70357C20ULL, 
            0xB7A51B9111B01251ULL, 0xA3D94DD1B1A7A91FULL, 0xE55B55DC4786805AULL, 0x47D82D8C758D2D4BULL, 
            0xD0787549530CF0B2ULL, 0x7642AF28C6304C8BULL, 0x1BE460E4C76F8C04ULL, 0xD00FC5EC4DE97620ULL, 
            0xFE57546D3B39AD58ULL, 0x6F366F773145FCE4ULL, 0x8C0127C67D6DE360ULL, 0x442AA958ACC55266ULL
        },
        {
            0x76BEC788DB41DC60ULL, 0x1DCD43C0EADB3B9AULL, 0x8834D7E9E0D468F2ULL, 0x67EC3AC51FAFCE59ULL, 
            0x6ABCE6303425997DULL, 0xFC0F0F8207A7F94CULL, 0x569F3D22B9958BAFULL, 0x4742CD3ED3453655ULL, 
            0x2386C216DDC428F9ULL, 0x70BAF2955191A85DULL, 0x79C89E7EAC8F9795ULL, 0xA7938429820DB0F2ULL, 
            0x136EB19C726DB4C7ULL, 0x0BD6E6505590B54FULL, 0x06871C7EFE62F2C2ULL, 0xD190283CC354DB33ULL, 
            0xA3D40ECEF01C45B5ULL, 0x6CC2509498F69498ULL, 0x0047F5B44EFAC5A3ULL, 0x288B08F513AB33FEULL, 
            0x2B78696B14962D2BULL, 0x97498A9750CC3AA7ULL, 0x490F5D304B9C569EULL, 0x4BF1AB8E03E1BBCAULL, 
            0x8F53F4E8A90A4A92ULL, 0x9AADA8B259BF2437ULL, 0xA6E2EA3D616D6693ULL, 0x37B30DDA468862F0ULL, 
            0x9DF3892841AC91B0ULL, 0x83F2F439A5E46086ULL, 0x259B195758CCBA19ULL, 0x1CACB5B43399C75CULL
        },
        {
            0xC65BB289C1AAAAB1ULL, 0xED14CEE2E5654C5FULL, 0xB74BF0A0F7BA3457ULL, 0x26C44E66188859D5ULL, 
            0x43EC5657AD219F9DULL, 0x53F20A14365612F8ULL, 0x01A4C84456FED355ULL, 0xF6BD1BD41CD6F63FULL, 
            0xD32DBA3D20942EB3ULL, 0x1A3329B554E02858ULL, 0x713A91BC3B6F2267ULL, 0xA9262D3BB1960930ULL, 
            0x831C8B54EBFD0F38ULL, 0xFCAE8E1D5970AF19ULL, 0x8D96361526496479ULL, 0x1594BDC7932EDCC5ULL, 
            0xB8DD26DC5B914411ULL, 0x1A35F5D33D95C245ULL, 0x298A7C5A59FADCB2ULL, 0x4733DF81F23053A3ULL, 
            0xA50551CF6D25F6F4ULL, 0xC6568F5FB69AC079ULL, 0xF03D548DE7F40029ULL, 0xD59E2248E7F5281FULL, 
            0x71EA1D0C842E34B9ULL, 0xA46BEC0FACF8F526ULL, 0xB1D6705C42563565ULL, 0xBC6CFE2F320F2E5AULL, 
            0xB5E28E93044C71CFULL, 0x10EA28A84B1F73B1ULL, 0x1494DAC99128185DULL, 0x6EA74579AE15FE78ULL
        }
    },
    {
        {
            0x0E8A31B7BA0EF166ULL, 0xF041211422C345C9ULL, 0x1DB101295A58527BULL, 0xF64552B3BF7F2738ULL, 
            0xC8CFB056DBE0C2FAULL, 0xE3D55A97D49A56C0ULL, 0x2242C13DBE7139F1ULL, 0xF82E5847D8EE8002ULL, 
            0x52B04D69B206FE35ULL, 0x1F4B289DEB57E335ULL, 0x21C669395E837768ULL, 0x31ECE20867FF5941ULL, 
            0x06797CD51A62C021ULL, 0x0E71619F72220C70ULL, 0xBF9E2D61F9E14B2EULL, 0x4E821E0522D8C4D6ULL, 
            0x1B42AB4CCA048E04ULL, 0x936AFB2333EAF78FULL, 0xC3C03BB1328B8D41ULL, 0x90D3E7C8A1B390CBULL, 
            0x9644F99E4894F40BULL, 0x7744118B234401B6ULL, 0xD1CBA479FC5277A4ULL, 0x191BC3B4860BA7B4ULL, 
            0xE24D61C74C2AC78AULL, 0x7A29ACBF23D7CDCCULL, 0x9A08FD39D2C2BEF8ULL, 0xB914A11D5C106B56ULL, 
            0x73B6081A3FB31F6FULL, 0x2BB378160C98811BULL, 0x5BFAE9F2A42646B7ULL, 0x9C4C6B67DD929A7EULL
        },
        {
            0xDE1A075F8B24A763ULL, 0xC469B18940850AE4ULL, 0x6BB3B79C1E82E271ULL, 0xFA05D09C6C529287ULL, 
            0x8CE849B7862038F2ULL, 0xEDB41F0089AA4947ULL, 0x67E72DFC887486E5ULL, 0x1AD780078DD8F039ULL, 
            0xBEE0D4FF398FC0C7ULL, 0x8C7DAAB0CE79D891ULL, 0xC4DA064C3742AA19ULL, 0x0C8AE62FBD7D3E6EULL, 
            0x3D85B06CE12B3B6FULL, 0x9B0DF5405D5B7201ULL, 0x2858056382C435F9ULL, 0x9D80938EC60421ADULL, 
            0x4241495AFCC73B20ULL, 0x095A43BFCD93107EULL, 0xBB66856FCA6D5416ULL, 0x8FC90C0B85E0BA3AULL, 
            0x0A80D8E9176A0B59ULL, 0x076958FDDA26617CULL, 0xD4D120DF98E6A3B1ULL, 0x3C73659C2CE59882ULL, 
            0xA7297DA650C912FEULL, 0x1F279AF3E4EDB30EULL, 0x8EA5235D967EB34CULL, 0xD809C5B6D85DB262ULL, 
            0x75A1F5245CF85FBEULL, 0x3B3D742C740C71B9ULL, 0x390365A99BBFAD8AULL, 0x54F3596E8114F00AULL
        },
        {
            0xF68D3A11EAA8A4F9ULL, 0x48DE26FF7C2B015AULL, 0x1483A7929A1AD6D6ULL, 0x93CF2B7608CA6C74ULL, 
            0xFE979DBA95324613ULL, 0x0EE5FEF8440D403BULL, 0x54AD0A37C5F98130ULL, 0xD8E2E891CA0006F9ULL, 
            0xA2740D5D9C7F08C4ULL, 0x5AAE8E1C70AC74B4ULL, 0x851B241F582151B0ULL, 0x84F995CAEF772BA2ULL, 
            0xA4A8AC60FE3F8D2BULL, 0x2AB7C1A17F7BDDD0ULL, 0x5F548B1303943754ULL, 0xADA3A2051193D040ULL, 
            0x25DB14C61BEAB818ULL, 0xBFDAEBAE70B4315DULL, 0x1809B3CFB69A7E24ULL, 0x2C7DD06090F42D36ULL, 
            0xAA3156DF33A9E078ULL, 0x3A665ACEF99EA7D2ULL, 0xDA53B1368BC11749ULL, 0xAFBC222B26CD1E63ULL, 
            0xDFB89EB825B2B578ULL, 0x01564410E3E22A65ULL, 0xB8CDABE263E273B5ULL, 0x7EEEA88E6DB4D941ULL, 
            0x7DA6478041D1C508ULL, 0xF6307B9CA3AFE600ULL, 0x7525DABBB0FC431CULL, 0x1D3EBB4387340AB1ULL
        },
        {
            0x44C8F3ECC70D1C0DULL, 0xBF7AD7C931B0F36CULL, 0x6C3455A3FAE7C62BULL, 0xCEA3B745E935010DULL, 
            0xECA2D2BDFEAAE79EULL, 0x7D4FB29A615533E8ULL, 0x526D1A6EEE7E94AAULL, 0x0C34E3A97B0698E4ULL, 
            0x985756462198EB64ULL, 0xCBC2CBC33A82D040ULL, 0x073AF2D73F6AA012ULL, 0x12912F23AEF5CF9CULL, 
            0x0E9F7C38AB96027EULL, 0x87EFC85FAC140026ULL, 0xE9AE2E07AA52A276ULL, 0x69833ED8D73A8055ULL, 
            0x6F4599A15801A757ULL, 0xBFD97F0342D30F0AULL, 0x13B22C6843060128ULL, 0xC277BC4E39F2D34BULL, 
            0xFCBF29918051FDB7ULL, 0x7323C2C7724D5AF0ULL, 0x6D8B61D9F50A1D28ULL, 0xE3A2E04C48D61FABULL, 
            0xD786810112438E56ULL, 0x39980823F5467CDCULL, 0x98AF4091854CB8F9ULL, 0x3FBEAB1B2F6FBC16ULL, 
            0x9D5589672F504208ULL, 0x7D1CB473141BB53FULL, 0x160D84F73F5AF84FULL, 0x6DF3187E968139D5ULL
        },
        {
            0xBD999799EC389B3AULL, 0xE25C58C622ECDEA2ULL, 0x9A5B59C84213EBFCULL, 0x109C8D8FEF1CE1C1ULL, 
            0xFC2067AD9FD7EE52ULL, 0x076A699BACC1A163ULL, 0x2E9649E7CD846922ULL, 0x297B122893141F07ULL, 
            0xAC154A094F640CB5ULL, 0x3BC9135E2125AA15ULL, 0x42212FF7FE3BEB17ULL, 0xD579656CBA2F9611ULL, 
            0x160FBF968529E6F1ULL, 0x91E5A3B801C5535AULL, 0x30DB0AC319447914ULL, 0xD523E73306546082ULL, 
            0xD9D47C21268694D2ULL, 0x3E52AA094E0A3694ULL, 0x3FAEB0DB6AB5F89DULL, 0x0A53D2C929A49836ULL, 
            0x41E9FF3E0D2A397AULL, 0xB56520147BEB23A2ULL, 0x8C1C93FEB1D6EED7ULL, 0xB054748F7B88B781ULL, 
            0x71C8069597072670ULL, 0x78E2D9CADCF255CCULL, 0x714583DE88F18DE5ULL, 0x27B404B3D6579601ULL, 
            0x565FFAB8565DB252ULL, 0xE680E39CF16317B6ULL, 0x403D0EA58F99C4D5ULL, 0x62BF2B782AF8161BULL
        },
        {
            0xC1E12C8CE8ED2E86ULL, 0x1000C78472BFD621ULL, 0x2261B6FC76424F95ULL, 0xBE90A0AD4B336623ULL, 
            0x202C34AC2FAD53BCULL, 0x88201A8EC34FC89EULL, 0x15A9F46145FB1CFFULL, 0xC65A7633B834EB3DULL, 
            0x6886A2FEF9679A12ULL, 0x96B09B708E3346F7ULL, 0x71087513AA50863CULL, 0x22BE03F7E88BFBC4ULL, 
            0x7BEA7CD40530118EULL, 0x05DE703D8F5695D3ULL, 0x32D36042C2597992ULL, 0x9E4A4023729F3177ULL, 
            0x5D5EA947175675B0ULL, 0x18FC4E19B38B4F7FULL, 0x56FFD4C02B208798ULL, 0x355A3CA769749A55ULL, 
            0xF330678DFB8D0628ULL, 0xF51AB102D910D377ULL, 0x10B70D74FC8FB4C3ULL, 0x8669858AF8584A0CULL, 
            0x6FAB7A9E3308DEACULL, 0xBC4F24F9A783BB39ULL, 0xC1D502A6F4E5D401ULL, 0xDBEA23D89AAED9AEULL, 
            0xE60E0B162ED91537ULL, 0xC67D2A99A90B2A58ULL, 0x630BFA9547F40683ULL, 0x350CE47E9EC2B2E0ULL
        }
    },
    {
        {
            0xA66BC62F33182EDEULL, 0xA74B14E5134BFA44ULL, 0x01CA2EC718650280ULL, 0x58780EB37327219DULL, 
            0x1E4393FE4261CB4EULL, 0x09FA25B3A52F7E30ULL, 0x5317148754471B2BULL, 0x373383327B352B43ULL, 
            0x385C8D0A2FFF5115ULL, 0x012448130D95AB51ULL, 0xDC7B456D6ABD4DE3ULL, 0x715219BAC8F211D3ULL, 
            0xD9F71E6060AF7120ULL, 0x57C6D1637482459BULL, 0x243D0C93FE3466FDULL, 0x3184DBF1274ED862ULL, 
            0xA48A1A99F470E6A2ULL, 0x54BD60DE8E5FC3E6ULL, 0x43226D1A02BE0EADULL, 0xE77F0FF498D4A698ULL, 
            0xCF9BEB7A3AE545DBULL, 0x3C156082F7FCD389ULL, 0x2BAD54CE8FD5453CULL, 0x5B57BD00DC9592D1ULL, 
            0xE8FC4ADABBD6434CULL, 0x3191F027CE1E6CEFULL, 0x2EC027157C8B00BBULL, 0x008CE7356C9076AEULL, 
            0x927B33090F01EB56ULL, 0x92DE428D48BCEE37ULL, 0x7DC4AE988685C650ULL, 0xCF49D0493ABC81FAULL
        },
        {
            0x279777F5F3CA82EEULL, 0x77589DCC9D89BC5DULL, 0xF19803ADB68DEC77ULL, 0x3C3FF56EFB6F4669ULL, 
            0xD2AE03D9B7B034F4ULL, 0xAC8F67B7D52D25CEULL, 0xDBC1012EB6B114D1ULL, 0x26E93AB8B2D498A7ULL, 
            0x9E017654EF0F970CULL, 0xB4AC58B74E836CA1ULL, 0x52D2574D539F4F84ULL, 0x5C6AB8FFF5B9459DULL, 
            0x5948856F038C0E59ULL, 0xD25AEB4B88FD290FULL, 0x636666106D37DD3FULL, 0x3A72584102BA755FULL, 
            0x7987219C93D770F9ULL, 0x4DD9B8B58FCA625AULL, 0xABED5EA8C4C500A8ULL, 0x84771B977AE0742DULL, 
            0x00642ADB79D4046BULL, 0x6B85D188478F5C83ULL, 0x7E78BEF6786F0AB5ULL, 0x8F67DFE0333A88C0ULL, 
            0x63BA4A7792AD281DULL, 0x108E970649F8A67CULL, 0x760E2827C83EF1C2ULL, 0xF8A75031F008A5EBULL, 
            0x9F763FD614DE38BAULL, 0xFF152A1BE19BA3CDULL, 0x69415C25D58598A9ULL, 0x68AE44FE554C5E08ULL
        },
        {
            0xC88DC8EA322D3582ULL, 0xE87A88E90694893CULL, 0xA309F7193DEDE7DEULL, 0x3DA3ABFD58C164CFULL, 
            0xD821F6131956CA7FULL, 0x2C16468AF18522E1ULL, 0x0D4197A3B0DB7B87ULL, 0xB0BC44A0F5489727ULL, 
            0xDEE179AA9A460E32ULL, 0x061F2FFB946E2093ULL, 0xDB1F8D14F5746380ULL, 0x72F9152FF0916FB5ULL, 
            0xECB04E6B3A9AB451ULL, 0xF5871C4FADD4409BULL, 0xEC129ECFF13EF568ULL, 0xDB6D1647A810EF34ULL, 
            0xF5BD5E05823A9751ULL, 0xADB61AB08E83C870ULL, 0xA2123D684941CA5BULL, 0xA80CB299EDC4D8D2ULL, 
            0x6192EA05A12A196CULL, 0x872B78043F84CD29ULL, 0x2C36BA1F143C76CDULL, 0x87876C1E012DED2BULL, 
            0x16E5B6368A4E40C0ULL, 0x00E0469CA6772133ULL, 0x585CB88DA10A1497ULL, 0xECFFAF3DAF2F706DULL, 
            0x72D1BC2E270E70B5ULL, 0x01C7FB8495CA0AB6ULL, 0xC103ACE57C2C450CULL, 0x4442E053D3AD595FULL
        },
        {
            0x036DBF50C15B6352ULL, 0x4E2FA97C444C99E0ULL, 0x5A6186F415E08219ULL, 0x495B590C7CCF9B0EULL, 
            0x9EE2F027AFD94BDAULL, 0x1D3B90B6851419B8ULL, 0x05CBF38E89B0F8CDULL, 0x1E5E83B13C4ABD06ULL, 
            0x3A3C194FD55B861CULL, 0x0420DD13B36156CBULL, 0x9FD8B9F3857F19A2ULL, 0x624E3D0AE048E842ULL, 
            0xA1C580401CFBB1C1ULL, 0x7B7D9146DCBFDC5AULL, 0x4EC86FCC9BBBE711ULL, 0xBC8186F64D07BF4AULL, 
            0x90DECAF468266B1EULL, 0xFE3642F84B66802AULL, 0xF3D6894DFB85E2DCULL, 0x028BDA32F4FFCE7EULL, 
            0x53232BC8A9B90C01ULL, 0xB4A6FFBA8C8D72E5ULL, 0x4B45750E565642B0ULL, 0xC0F00C2FCDD085E2ULL, 
            0x32F001A8F397F715ULL, 0xA39ED444694670D7ULL, 0x4827D808E6ECD6CCULL, 0x08ADC8A828D5FFA9ULL, 
            0xCCABEBA0F6E9303EULL, 0xE22CCCC3F7060A10ULL, 0x845CD7044CE1ABE7ULL, 0x32ACED2CE38D1FF7ULL
        },
        {
            0xD599D0584F7E1076ULL, 0xFA7B67F2D04D0AAFULL, 0xB7A9FB6022238F26ULL, 0xA8C9E9A4FFAD51DDULL, 
            0xE9DE5013C74093EAULL, 0x0140DD5A8BD90DFEULL, 0x913D04674A4E9085ULL, 0x8254D20049F6BFB8ULL, 
            0x743A771B35FCBB98ULL, 0xFEA38A242AB24E56ULL, 0x42BEBC01BFC216A3ULL, 0xAF5D181C38CCFF77ULL, 
            0xE375859D59BA864DULL, 0xC8A4852696DB5ADEULL, 0x871210E5DEC93C1AULL, 0x8F40CCB30D2BF722ULL, 
            0xD4B497396580B3CBULL, 0xF829CACD8DF4E645ULL, 0x89CD21963C0F55E6ULL, 0x762075684FB00C03ULL, 
            0x27EC986941DB0A75ULL, 0x90FDB2065902AC0DULL, 0x6031A090D0DDC07AULL, 0x50C3B4472EDECCB9ULL, 
            0x3B422A7C840FF0B0ULL, 0x05BA5F45FD7E76B8ULL, 0x0870B22859906259ULL, 0x612CFAF38458638EULL, 
            0x6442F32C7ECC0420ULL, 0x8A274E876269C35BULL, 0xDA7AE89E981D7886ULL, 0x54A5F8C6763ABD43ULL
        },
        {
            0xFBE294EECC0369CCULL, 0x3F011462148B8444ULL, 0x4947DAF132B73C18ULL, 0xB862821A0A898391ULL, 
            0x0FD787D6B594A91DULL, 0x3AD7B096B0F9B988ULL, 0xE996C1812A59ACD0ULL, 0xAE02FFD58322CF21ULL, 
            0xA50A0367DC96724CULL, 0x3B340866645B01CAULL, 0x31577300CBE8212FULL, 0xDC20D4D2A43D9751ULL, 
            0xF4A22B1CC3D5B268ULL, 0xB8AD9576B672F8ACULL, 0x69A9007B2ABF064CULL, 0xFA504D066B05B18FULL, 
            0x2C4E7F6880AAC628ULL, 0x11F42706B42295FBULL, 0x3083BC6CFBCBF8A6ULL, 0x8BCE36223BAE7F04ULL, 
            0xDE1B649D7A81A5B0ULL, 0xF0BC7A8F553D726AULL, 0x592B80729E76DEE2ULL, 0xC86928C3056D7A2DULL, 
            0xC2B7EC10DFCD6D40ULL, 0xA8F149F395837113ULL, 0x2308D6BBBF26F031ULL, 0x677408CA511B15DDULL, 
            0xE55ABFEDB9E3AC68ULL, 0x9E2940AA94D0C079ULL, 0xFFF9304B6463AE20ULL, 0xEE003B712BC87539ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Athebyne::kKeySpawnAConstants = {
    0xB71ED863C4872F89ULL,
    0x899340ED7F32ADB0ULL,
    0x50951133D488A6BCULL,
    0xB71ED863C4872F89ULL,
    0x899340ED7F32ADB0ULL,
    0x50951133D488A6BCULL,
    0x199334535FC8BCDEULL,
    0x45785B65BA3AC518ULL,
    0x23,
    0x22,
    0x82,
    0xD8,
    0x7B,
    0xF4,
    0x52,
    0x11
};

const TwistDomainSaltSet TwistExpander_Athebyne::kKeySpawnBSalts = {
    {
        {
            0x50811A3D85DFC9C6ULL, 0x04D745E8B6B3F63CULL, 0x24D2D49FEF5843E3ULL, 0x479BE574F75F4877ULL, 
            0xBEBA04F866FFBE79ULL, 0xF3B3B6871504CB35ULL, 0x641769EBA2045A43ULL, 0x49040AFC0F948EF4ULL, 
            0x503F33A440C89A4EULL, 0xB27761C47FED563EULL, 0xEF1F932187A7B8ADULL, 0x15BD8C50DD2BC4A4ULL, 
            0xC1394320A9230360ULL, 0xABBB3B1AB0104B16ULL, 0x1696905B6B71ACC7ULL, 0x34266C7EC35CBEF3ULL, 
            0xCA11D5F7E7E53863ULL, 0xB6BA5169339C87BFULL, 0x0EA69B5244310F9EULL, 0x2588D896A7AFC9FEULL, 
            0x04364777AB209DF7ULL, 0xFCCBD42E95CFED76ULL, 0x1BB41CCB5314ADE8ULL, 0x37566BCAB04B6FC2ULL, 
            0x6DB9FEEA6433B327ULL, 0xE85832767089A1E5ULL, 0x7F53459F9CC4863DULL, 0xE592C69872624F33ULL, 
            0x40F874C96D196D90ULL, 0xF53AA59561BFD8D2ULL, 0x034B9961AC3E604AULL, 0xFFF8307CEE26D3DCULL
        },
        {
            0x7859CF5951EA9018ULL, 0xE76DC8F3EC171027ULL, 0x54690614F070DC31ULL, 0x140660CFAF3201C5ULL, 
            0x1D26842F9B57B03EULL, 0x2FFFFAE2ADA7DDEEULL, 0xFC49046C27A2F0CEULL, 0x5C2441E8D12EF402ULL, 
            0x5C3945DC249C1BAEULL, 0x5838A1E0BD9773BBULL, 0x4FD0A6806161FBF6ULL, 0xDCB68AD7E1139BF4ULL, 
            0x513D6FD2D56B01FEULL, 0x6D7E8658B2377C6EULL, 0x752587E8F9653726ULL, 0xD7A7696FF9E23B1CULL, 
            0x5F8B5A67555B337BULL, 0x3D362E96AF4629F0ULL, 0x38DAF5BEEA9FF134ULL, 0x16377CF607D35603ULL, 
            0x0FD26EB2C8D80EB5ULL, 0x46358D2AC3056BACULL, 0x6599AA3C1A15B6FBULL, 0xC68294B0081BB8D7ULL, 
            0xB01CD12C6E9EB7B6ULL, 0x6CF7A620C856B0BEULL, 0xE5AEFFD9E71DB3C9ULL, 0xCBBFF7F95B383815ULL, 
            0x0682C5C7D65F3C1EULL, 0x7BAA41E477034C27ULL, 0x33EEBC2254C3BB87ULL, 0xDB583C9574A82CE9ULL
        },
        {
            0x34F3FC752265BCC6ULL, 0x10077F209E655EEBULL, 0xF16606982205181DULL, 0x079D8DD3F4ADD87CULL, 
            0x63FEF77B5F31AA7FULL, 0x94C84877B71C4A92ULL, 0xD140B57A040024A2ULL, 0xE42483B2769B928AULL, 
            0xBD3A9860C71ECA7AULL, 0xFB1A8937E6FD0530ULL, 0xFFD70CA3DE2FF6F5ULL, 0xD509B585FFF1C941ULL, 
            0xD4785A2EF22D2408ULL, 0x0573F6A619B1C024ULL, 0x5A53F21C31EE0526ULL, 0xD15FA4EC5677A9CBULL, 
            0xDAEFB42CE507EC3FULL, 0x25CC48A50E188B85ULL, 0x407D72509DE86EB0ULL, 0x15CABD664604BDB0ULL, 
            0xF8AB050CDED805F6ULL, 0x5FC8AEB21579A854ULL, 0x01E69D21D3D59E4FULL, 0x5A284E6028924AEBULL, 
            0x883F13BDFA1E5764ULL, 0x08C8A4C458BC630FULL, 0xC9B51B266DF03A5CULL, 0x42CABFD293ADA555ULL, 
            0xD09BC1CBFA306DC7ULL, 0x9125A05392F5113FULL, 0x8CBF8E2CA6693FAAULL, 0x5692EED0FF2E2563ULL
        },
        {
            0x16DCCE3CB0E97C72ULL, 0x360296B96F815846ULL, 0x44BE948E111EC361ULL, 0xE2ADA8B42FAA2FB7ULL, 
            0x1AE24C05BDDF4D02ULL, 0xC9057E607F8FC359ULL, 0x23B6C17376CE2D54ULL, 0xD882DF7432C693FBULL, 
            0x3A7A4E1D671552B8ULL, 0x59202F5B7D3CF726ULL, 0x683FCE6E91E941EFULL, 0xC48CFD557E64F955ULL, 
            0x1202F4B375916296ULL, 0xF6420C6AEEFBA870ULL, 0x4A6D6BFE9FFD937BULL, 0x589CBEE8A8ED517BULL, 
            0xC5B0020B39953A47ULL, 0x0477EC50E115C0BFULL, 0x00CE3E52988710F4ULL, 0x07F5AF732FF06DE6ULL, 
            0xB87BDBB296155213ULL, 0x038CAF60284ED0F8ULL, 0x0E22061E4136D44AULL, 0x5A6391FE425BBE40ULL, 
            0xB9E98AF632CE6AF5ULL, 0x55E512404BADF25FULL, 0xF2DF590CF8AD7D79ULL, 0x4DDE1C9331E41B8DULL, 
            0x0E1F71AFC31AF468ULL, 0xE688CA303D340BE8ULL, 0x3D3F40F8E4506DBBULL, 0x1FFF217B36C600F0ULL
        },
        {
            0x905CB61DBB7A3AD5ULL, 0x0073AB9E4EB3A54FULL, 0xD0304D32F20974F3ULL, 0x6E765E17A0C538FEULL, 
            0xCCCB23FD2824F559ULL, 0x4CFB17247FAD74B0ULL, 0x8BE65DAE69B7BD06ULL, 0xB142F93F10F31B61ULL, 
            0xCDD7C79F25099CA1ULL, 0x42CC407DB83D2E44ULL, 0x6E15DFD39A46DC26ULL, 0x9815BA1CA54E24FEULL, 
            0x5FCBDFAF7C662124ULL, 0x7C713D816C029B08ULL, 0x813B417EFDE68ACEULL, 0xFC163177940AEAE9ULL, 
            0x2D19256B2E04ED03ULL, 0x00761A139816EFA7ULL, 0x1A7E9C6B60B00F1BULL, 0x4C166DE31DD3A0A6ULL, 
            0x47DD42E9C08978F1ULL, 0x42554FEB7B3B4563ULL, 0x100DD54193D60D8BULL, 0xC18E6E3A2B9FA177ULL, 
            0x90B1FEAAC183EA93ULL, 0xFC67C9973500F7EAULL, 0x3AB8240BD312126DULL, 0xF13187A621A31CE1ULL, 
            0x0C076B2817F30716ULL, 0x909149CF8DF48A61ULL, 0xA067196969201B90ULL, 0x87056B61B1C5A481ULL
        },
        {
            0x406CE30FF5AC6F26ULL, 0x2B4E14C9697D9992ULL, 0xAD00D93CF708FD5EULL, 0x04A6A302BE9145EEULL, 
            0x43D98D3EA4AA6AC4ULL, 0x49992FB5CA2C9439ULL, 0x670D030944AE0247ULL, 0x4F32F0A70924A795ULL, 
            0x2522E4D23A2717BDULL, 0xD759136752A7A1DFULL, 0x042810C5DEFDD3BBULL, 0xA2644D436915D969ULL, 
            0xC9DC98B3334A75C0ULL, 0x0748E4DD1B63A387ULL, 0xF250C7A69A37A499ULL, 0xBB79B2E847862210ULL, 
            0xB24DAA1FF4AD7746ULL, 0x8F1C8B4FBC15188EULL, 0x2F4BA5DBDF479350ULL, 0xE0F4E5557E5B4769ULL, 
            0x77F380D60E020906ULL, 0xB891C777672E3ED0ULL, 0xE97F98F266F498AFULL, 0xF91DC0D4877B7F3EULL, 
            0x129A56C9FC5A78B1ULL, 0x5AEDDB5FDCCD7E07ULL, 0xE98925D906BE67A0ULL, 0xD1E52859E3E8290DULL, 
            0x1346588AA3061352ULL, 0x7399CC90899174A3ULL, 0xD178C2D321ED1A09ULL, 0x820B22E6C4E8C152ULL
        }
    },
    {
        {
            0xAE13E28C2AEC83DAULL, 0x382035C764DD8F89ULL, 0xF0AC78DED45A05DEULL, 0xF1C4ADE0AEB533E7ULL, 
            0xF7436417EE8D813CULL, 0xEFA3543759982D16ULL, 0x4F10D3776BACA98BULL, 0xDE6B926C6F69A266ULL, 
            0x9674B383150F9BE2ULL, 0x4A3A44DA5CB07FB5ULL, 0x2D2EF0D58B14854AULL, 0x636660D9617FDD89ULL, 
            0x490FCC5FD6F79141ULL, 0x95C3A485B777A825ULL, 0xA9ADC0088F642343ULL, 0xFD21CAD180971006ULL, 
            0x9F179A487AF74C4CULL, 0x8F21C2F294012DCFULL, 0x2D30667DEB07647DULL, 0xF26505BAC77ED1D6ULL, 
            0x90A7CF12AF276DCEULL, 0x4B29788991B235BDULL, 0x169F119C5E1495D1ULL, 0x2D096F1733B2A085ULL, 
            0xFCC856E9028388E8ULL, 0xC4E9E42CE60F994DULL, 0x8A6E86D6ABEBB7A4ULL, 0xB268ADF81F44982AULL, 
            0xC99B82D3285F6906ULL, 0x7BCB99658C675EDDULL, 0x07FADC4EC95837A5ULL, 0x428E1782EB26E441ULL
        },
        {
            0x5861C70D58126055ULL, 0x7FC672F66C28FA75ULL, 0x66A9E93EF3E8098FULL, 0x8D2893C833065C3BULL, 
            0x9C807F50CF8DE2F7ULL, 0xB6AD5294F307E97BULL, 0x43F290006AFAB55BULL, 0xD4ED21AF0FB76B21ULL, 
            0x98FAD4FECA6B2FBDULL, 0x58DDF56191836C67ULL, 0x403EE187880F0ECDULL, 0xEE87C0ECCC81528DULL, 
            0x74D77D492F335E37ULL, 0xFE153265775F84F1ULL, 0xF0DAA3CB4369B915ULL, 0xC773C7CDA62741CDULL, 
            0x401ABCADC739FEC2ULL, 0x4D17E50979CBC2F2ULL, 0xFFD4FFF0C702D67BULL, 0x79610164BB312B5BULL, 
            0xC3558B3CB3AFCF83ULL, 0xDA780A9B176D9D3FULL, 0x0B18AB8260D2BEF1ULL, 0xF9F0927953A35A9EULL, 
            0xFF9A7E549525A61BULL, 0xAE7233E8985DDEC6ULL, 0x11B346A6362CAB37ULL, 0x4CC3BDC3DCEE73E7ULL, 
            0xC16C9E996949917CULL, 0x91C233B7BA025112ULL, 0x0C30503CDD9CBAB5ULL, 0x34C7E5FC7F4FCA69ULL
        },
        {
            0x154A0B72C14CE500ULL, 0x21C6903EB94A3765ULL, 0x15E647A6CE8A4D39ULL, 0x25E9D134DBEDD5AEULL, 
            0xFD188764306577F9ULL, 0xF163BCAAADB2C316ULL, 0x0AC3233ACEF04D7BULL, 0xFCD5087D462AC118ULL, 
            0xAB4ECE0BFFF1196EULL, 0xCF587164C0D97E2BULL, 0x9ABCAA06E76BAFE3ULL, 0xDC276C29E2E82F3BULL, 
            0xB5011DE2B641181BULL, 0x9CFC61E48EBAF4EFULL, 0xBE1BC692EE2DAA33ULL, 0xAFE75C472072182DULL, 
            0xEB5369AFFA84D528ULL, 0x925C16531A5D619DULL, 0x6E93742680C7329DULL, 0x6D9E2D5A036A7634ULL, 
            0x6C81E8468CA8471DULL, 0x27DC87C3594B0A00ULL, 0x19267B5B74858791ULL, 0xE7F60F2E7E40C44CULL, 
            0x0227854B67686CBDULL, 0x32E965AE24772804ULL, 0x2F76104196D4E383ULL, 0x3A3008F5250BE389ULL, 
            0x45184BD14CDE993CULL, 0x4A9A73A047DF396CULL, 0x2AD1616B0E4F7C15ULL, 0x8B11D7B32FFC4EE5ULL
        },
        {
            0x0CE94C348483DEB2ULL, 0x0AD34D87D09FECE2ULL, 0x7EACEEC57D00149EULL, 0xE538F00E14EB5628ULL, 
            0xDD5D8E3813C59621ULL, 0xF323FB0810ED1DE2ULL, 0x0340A8B18EA2DC2CULL, 0x9BCC058CFB298186ULL, 
            0x4B12797165F7C89DULL, 0xFADF0976BB20A51FULL, 0x3447067A9ADCEAFFULL, 0x8649673923CDFF41ULL, 
            0x0D85DB7EB75CD1D5ULL, 0xB2D84227AF69EEE6ULL, 0x4724D82DDA43D6E4ULL, 0x6200D9FC7A0A7505ULL, 
            0x214669E5B7668284ULL, 0xB1A9E904C7831704ULL, 0x9F91FC43836D0AD3ULL, 0x66801EFED89D2B85ULL, 
            0xD69C16A78509EF7FULL, 0xD5D53769A2277BF2ULL, 0x83E29C02DAF32162ULL, 0x12A1192FC90C3008ULL, 
            0x186C138AFD0348C7ULL, 0x5A50C4BEAC931B41ULL, 0x977824A7D64815ACULL, 0x5B801E6FF81A9DE4ULL, 
            0x45CE9A97C368492AULL, 0x3AACDD118AD77221ULL, 0x066E28C245AC289BULL, 0xAE7C5AE87C9C90F6ULL
        },
        {
            0x8EE236B6DBF9C503ULL, 0x53D9C6705C0371D0ULL, 0xBB819D7B763EC692ULL, 0xA88F8437EB4647C3ULL, 
            0x716A47BF919B5893ULL, 0x5475F3918B576BA4ULL, 0xD3303EA1130BF80BULL, 0x8EA3A25749CAD36BULL, 
            0x1D63E9D6283DF0CBULL, 0xF3366497ADCBA4C9ULL, 0x6714F9A42E15751CULL, 0x2BA626732220AC28ULL, 
            0xE64928346504F028ULL, 0x92A832F09652E049ULL, 0xF7ADE1BFFAD90D73ULL, 0x129253D235DFF718ULL, 
            0x2B8F1C80B8DE9124ULL, 0xAAE931EA1B9289FDULL, 0x5ED395B98C26E8BBULL, 0x59C86F29687D6579ULL, 
            0xBAD545B1B0A9A5C0ULL, 0x5517376779427A4FULL, 0x70F922C6C105B2D0ULL, 0x5C94336BFFB60B03ULL, 
            0x77DC2B41CFA9CAF1ULL, 0x5E10ACF04F49A49BULL, 0x9DB96A8894C41647ULL, 0xAE774C2323DCA803ULL, 
            0x7001BE0CFD525ACAULL, 0x745FEFBF848FA3E7ULL, 0x5ED78BC4B110B862ULL, 0xC21669187BF11B5AULL
        },
        {
            0xCACB99D86A48198DULL, 0xC264D4439844D5ACULL, 0x81F120E47965A469ULL, 0x3E659B9BE3EA593CULL, 
            0xEE5BC0761CDFE445ULL, 0x131F40FC514CD891ULL, 0x0B8077E6D73C99AEULL, 0x199372CA76DABBC2ULL, 
            0x9B477FD5C424DAE7ULL, 0xEF9F970533F88E42ULL, 0xF5B39430325194A3ULL, 0x6DA6040DF28905EBULL, 
            0x8BA831AE9A4C9D01ULL, 0xFA8023206AC85E0FULL, 0xC79251F1D7076526ULL, 0xE2D82A22200367F0ULL, 
            0x8272F4806835091FULL, 0x1C027EE2CB468F46ULL, 0x6E55D6C93AFC18D6ULL, 0xBF5E1E48F0DABFB2ULL, 
            0xBAB29EA4415542F1ULL, 0xADFE33C512A28485ULL, 0x5D49FED8FD8A24E4ULL, 0x6B04EA99BA63DBAEULL, 
            0x7B8B827B2E3B8B26ULL, 0x0993F122671D2A62ULL, 0xF36C22DB58D68837ULL, 0x53B3DEAAA5CF0FEEULL, 
            0x45EE89A3944EDC29ULL, 0x4AC2E65F0B394D43ULL, 0x2EEE058CB3FD185BULL, 0x17122934337CFD3BULL
        }
    },
    {
        {
            0xF2828AEDD07D0A2EULL, 0x2FF96F1381CE530EULL, 0x34DBC2D6A455F8A2ULL, 0x4606260CF9199DD4ULL, 
            0xF848212C7F9B80D6ULL, 0x0D3629176014AE5EULL, 0xB985C743451023C8ULL, 0x66A26EA977756B27ULL, 
            0xD6D2AD396EB9B8B1ULL, 0xB179EEB0A2DCFA1FULL, 0xD65B1EAEA489D315ULL, 0x304EE0872D8695A0ULL, 
            0x0D6FB25FFB21AB13ULL, 0x0E9D40F4433EC901ULL, 0xFB0935F6055DCE0FULL, 0x503F18FBEEA2868CULL, 
            0x5A355D13C1FD9199ULL, 0x5C5A860226B5CAF3ULL, 0xACDE66BD50831B01ULL, 0xEA688B5024E0063BULL, 
            0x49AC00B106F0E0C4ULL, 0xF1CC265EC387C040ULL, 0xA98F45CE3C98C024ULL, 0x100D232F5799CBFDULL, 
            0x78353D5C058DF045ULL, 0xF7C8BF6E474F5210ULL, 0xD43437230C5E9141ULL, 0x2A564FEDED10CDF9ULL, 
            0xCD0CE75D1CAD9657ULL, 0x1AFA92D13754B098ULL, 0x7392DED2DF9E2968ULL, 0x273E3E26FEAE67BDULL
        },
        {
            0xC8D5064045DE790EULL, 0x402F5FFD45FE538FULL, 0x6E82537685FBC81DULL, 0xD91CFF4A63FE4A57ULL, 
            0x0AB43AF752AEA73AULL, 0x21FCDC308FC78BB4ULL, 0xEED6AFCB8106A469ULL, 0x7ECD74B69FFDD3ACULL, 
            0xD44CB3CBDF0A5717ULL, 0x2DBB10FF034F8FD9ULL, 0x369EF15A8AAB5290ULL, 0xF67DC470D40BCF6BULL, 
            0x8E301E01AE87608FULL, 0xD5FFD167F1A9333EULL, 0x46D94EDB8466CFD1ULL, 0x031833D137A143ADULL, 
            0xB846C8DC013158E0ULL, 0xDE13D768008260A8ULL, 0x3981103A191E4308ULL, 0x6789A9FDC1270C9DULL, 
            0x37A3E9AEF26C0654ULL, 0xBA772138622727A5ULL, 0xE99C0A992FD1F868ULL, 0x53DA7100F4F55653ULL, 
            0x3FBE50C82377F6D8ULL, 0xCA063D62D02220B2ULL, 0xE7C9946E050DE1E7ULL, 0xE24D559BD04AC5B1ULL, 
            0x8D23FD5034469D09ULL, 0xA16976D1C72D28F9ULL, 0xE7A68B3E3017C1D4ULL, 0xD7E1364DED5AF290ULL
        },
        {
            0x1ADAC441C18D4DB2ULL, 0x6A16D2926BA94889ULL, 0x94010182E96FF7B6ULL, 0x1140E18A6C455A7DULL, 
            0xDC0048DFFF94434AULL, 0x9BA9D5F64CD5AF1FULL, 0xB29E4D7495F79920ULL, 0x6F7600E4B3C830D7ULL, 
            0x7759C11355BF00CAULL, 0xC7EFE941339D0DD6ULL, 0xA2AD26AE63175702ULL, 0x207E80B9B0BB3E91ULL, 
            0xB22626278B305ABCULL, 0x090A044D51E32395ULL, 0xF8E28E09B0A108E3ULL, 0xFDA39E4608F5CA60ULL, 
            0x1584AD4FEC69D4E1ULL, 0xA28F17B5D4111117ULL, 0xCAEC62C15BECE72CULL, 0xC4F17FA80E1F54AEULL, 
            0x86210F132E89E587ULL, 0xD32C1A124C740367ULL, 0xF21C8008112227FCULL, 0x6C4989A48075BFE8ULL, 
            0x70D99BFBA7B13167ULL, 0xF4844DE281A0184FULL, 0x6813B6EA6E041F3AULL, 0x090A77A896E31F09ULL, 
            0xFB97E799D69247DEULL, 0xDBCBEB2D0E6F5C9AULL, 0x8E5A36DA40BEE7CFULL, 0xF0BB820DC3019676ULL
        },
        {
            0xB4AC0140FB4B384FULL, 0x10E9A44E15A7C668ULL, 0x783FF2783CED2ABCULL, 0x172B2AF21EF9D23FULL, 
            0x9C6686A45485BA3AULL, 0xA80146990803745BULL, 0x7A0C2CC60FA1EE41ULL, 0x907DE3B20D21EFB4ULL, 
            0x1D0191B8B94EA18FULL, 0x6531AFA310F9C3C0ULL, 0xFF476E7AA40FE076ULL, 0xB4563CE5D2D513ADULL, 
            0x1F7923AEF3C93BB3ULL, 0x538996C6FE4E9241ULL, 0x6A43C3A4CE1F23BEULL, 0x7AEC8F64B84A3DEBULL, 
            0xA151CFA7DF5FAA60ULL, 0x9D096DD64D0B6E30ULL, 0x37395302F56F3D8FULL, 0xB48A366E38EE8D22ULL, 
            0x5D37A5368468255DULL, 0x610DE07B58F118FBULL, 0x1D5F2CA41ECB876DULL, 0x983949E2302CAF46ULL, 
            0x1C113A9ACAA9BB78ULL, 0xF8B500EB6E7E469DULL, 0xE79402FBE347A4F9ULL, 0x1F9599977F0D6944ULL, 
            0x58D3AF9046D5E800ULL, 0x17D603D7C49AE860ULL, 0x5D9375621460EB7DULL, 0xD209669C12FBF125ULL
        },
        {
            0x73CCF3A0F740C8F4ULL, 0xA967FC2FD7CA5DC4ULL, 0x69A6A272D59BE27DULL, 0x247935BD97D653ADULL, 
            0xCAA3B7AD8D9E0E5AULL, 0x1FC6E01623B7007EULL, 0xA69FBF54A4D7FDD1ULL, 0xFA5480E8A0B3AD7AULL, 
            0xAE6ADF9C74D64FA9ULL, 0x8D6CCA973304BA10ULL, 0xAED0F652B09E2F2EULL, 0xDE6F7C76AA954467ULL, 
            0x8F52603529EAFE7DULL, 0xF0601B8E1B50EB3DULL, 0x83CB25107F76A958ULL, 0xFA7098573ADE1201ULL, 
            0x5C63178CF5EBD11AULL, 0xE58FDB16D444E275ULL, 0x66321E84C2E907BDULL, 0x952E5BB3F677FF1BULL, 
            0x040313B823E89A97ULL, 0x030F0367898B088EULL, 0xAA8A2CD20CE8D0F3ULL, 0xE104A8D6CC49BB6FULL, 
            0x269918ED0DD42DF4ULL, 0xDC2F932C1399ADB3ULL, 0x237F4A78967FAB82ULL, 0x8530036DA4782C30ULL, 
            0x10BDBF2F00635C5AULL, 0xA5D04D12C795E904ULL, 0xC99679098CD80F5DULL, 0xCBE57EB819425701ULL
        },
        {
            0x99C9C72C97D0DBCDULL, 0x9054C6878BBA591CULL, 0x4A1AC548078368DFULL, 0x1AEDC59F11BA0814ULL, 
            0xB55A29E7AD9258B4ULL, 0xBB6F4101362B6790ULL, 0x41E581F07C50C1CAULL, 0xD455FE4CE9402CDDULL, 
            0x2051E09A721CCD81ULL, 0x3C29DEAFA3342A32ULL, 0x53C420B7DA87A55AULL, 0x97C65F73F79F8571ULL, 
            0xE3105E8B42B39619ULL, 0x210BF0AF578A4948ULL, 0x7279BE5D4C316EAAULL, 0x4585945FE64C9431ULL, 
            0x1492B3BDF9759121ULL, 0x31D3540FB7D51B2DULL, 0x4DB834CB39D26608ULL, 0x0A11844CAAC09BFDULL, 
            0xC17B6A2AD86DEC44ULL, 0x5DBBF53785955873ULL, 0x02FE03404F4E467EULL, 0x073CF230BFC568EEULL, 
            0xF9FF74BBC044C5FCULL, 0xA2BAED16EF7D1D53ULL, 0x4F3CC2B7CB295316ULL, 0x35594DBC32DB4EBCULL, 
            0x42872E23F449BF6DULL, 0x2F946E61E86440CAULL, 0x1217037A90F67A14ULL, 0xD4E2B29339BFFF7DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Athebyne::kKeySpawnBConstants = {
    0x877BA11C621821D2ULL,
    0x63F7C0AC93071064ULL,
    0xD2CEA6027104B65DULL,
    0x877BA11C621821D2ULL,
    0x63F7C0AC93071064ULL,
    0xD2CEA6027104B65DULL,
    0xB2EF281ADBAA2D2AULL,
    0xFF9DB80471CE4BA1ULL,
    0xF1,
    0xF2,
    0x73,
    0xAD,
    0x7C,
    0xDD,
    0xFE,
    0xAE
};

const TwistDomainSaltSet TwistExpander_Athebyne::kSeedSalts = {
    {
        {
            0xBB1CB756043C9F3BULL, 0x796F4AB898BCFAE4ULL, 0xF26A0D1AB21AE833ULL, 0xD7688B9A9F2727ADULL, 
            0xD53087B4BEC19D3DULL, 0xBA0AF59A38E2403CULL, 0x16499EDB10B4BF9CULL, 0x95533D291034163AULL, 
            0x7E7FDD8C5D625A41ULL, 0x207AD7AD483E1904ULL, 0x67E9ACD20F568343ULL, 0xA1C58B3475ED1796ULL, 
            0x07A2C200B2814924ULL, 0xDBD978A1574E7FF6ULL, 0x0C9831FAA8E1D08BULL, 0xB0FD1C7F0D0F45FDULL, 
            0xCDA83B2F89D48937ULL, 0x5F33A4A4EB1506E1ULL, 0xFFB7DF0E6180367FULL, 0x951B7159F228CE2CULL, 
            0x3E00C7D15E801510ULL, 0xB801EE474780498DULL, 0x3F677FC45C66AAFBULL, 0x47A46EE78F74FC1DULL, 
            0x94769AF89FA02C8CULL, 0xA1AA8ADAE0935287ULL, 0x0FB62C455A27E10AULL, 0x10BA57D49F3AD3CBULL, 
            0x4F5B35C6CE77228EULL, 0xF4FC18D692A862DEULL, 0x265BC6C89DFA696BULL, 0x27616CA81771F41EULL
        },
        {
            0x3B14C8E13F85D90EULL, 0xD108972F1927592CULL, 0x91443A2FAFB8C81EULL, 0xE816AAD728A4ADA5ULL, 
            0x0B08D70F5F4886D6ULL, 0x7FEF0DD0FEBB341CULL, 0xA46FC16740A8D3C1ULL, 0xC2EF0C3D729A0CA3ULL, 
            0xF2C7E3668FD4D95EULL, 0x7FB10B3AE4F29015ULL, 0x1143D9DF7D3CCDF8ULL, 0xC7670D7DAEB9B61DULL, 
            0x155ECEC730813DBBULL, 0x434DF472A2F61E68ULL, 0x7ACB69520E3619E7ULL, 0xBA8195ADD52AA72AULL, 
            0xF021EE8E10AE2212ULL, 0xFCAA0FE5656683A5ULL, 0x542719640D67F5ABULL, 0x991C09BF8C84AC0DULL, 
            0xA934327E5E25DEDDULL, 0x623505D3DAB9B072ULL, 0xF5BA1779429CD67CULL, 0xCEC28085C323E04CULL, 
            0x3A74E4E11FD5A706ULL, 0xBC7D2E9D5B94866BULL, 0xC078572AC7275057ULL, 0x81ADE3928F8042F8ULL, 
            0xF5A04AF4A8C12C13ULL, 0xE8B5161E5925E792ULL, 0x1A02EE6E99EA6086ULL, 0x7F53007BD93A79D7ULL
        },
        {
            0xB22E73161AEBDA7CULL, 0x1F032A45BA92021BULL, 0x12679665336D5663ULL, 0x71EC5717CDD87468ULL, 
            0x37A5E51924D923B9ULL, 0x26547F7DA383A431ULL, 0x0078ACE8BF40FFC0ULL, 0x33BEB261ED0AA9E4ULL, 
            0x4940F3ABD69FFCE2ULL, 0x969E48B213A13E1FULL, 0xF0ED7D9C6A43193AULL, 0x1CBD834B10E1DBECULL, 
            0x247F6131CF655144ULL, 0x8188012E17C67E22ULL, 0x862B7CE9A4B61D0DULL, 0xA145A07416A5EFC1ULL, 
            0x5C6F977CCD085396ULL, 0xCE78B043691476FDULL, 0x4059F1AB7143B3C9ULL, 0xFDF20E5E1A1114F2ULL, 
            0x6E734C41FC4CCD32ULL, 0xB608B202A888B54CULL, 0x9BE234D206BA70DAULL, 0x19FCA1A4E2AD835EULL, 
            0x4CD2A144C91B474AULL, 0x90BCA41C03E65626ULL, 0xC51352C4A35F8D05ULL, 0x629FD932F7B69256ULL, 
            0xA4BC78AEC3D45115ULL, 0x95BB94EC5B2BA966ULL, 0x05F089282EE412A4ULL, 0x8D01D3C8DACCABF6ULL
        },
        {
            0xEEC92DDB6834B6C1ULL, 0x771B85D5509FD0FDULL, 0x878208A27AA20549ULL, 0xCF7911373BE36AA3ULL, 
            0x263F8DF7A37BC835ULL, 0xD69B35D22551D08DULL, 0xAA6A90BF05D94651ULL, 0x88B3010B25A2BF22ULL, 
            0x31CC350CF9687BB3ULL, 0xA60671641444BB15ULL, 0x5399AD94B487943BULL, 0xF395F15FC8BB3B72ULL, 
            0x7CEC99B67678F5F0ULL, 0x32A75E8640B4FA31ULL, 0x0699D991638C3D60ULL, 0x91F89F59557137B5ULL, 
            0xC651F544993CD637ULL, 0xA9AB3F2CF0287FE5ULL, 0xA4F9CDFA2B030028ULL, 0x40E24E421990B88FULL, 
            0x5CC1FEC310EF6D29ULL, 0x25FB252647EE8B99ULL, 0xDC3618852704DE71ULL, 0x70572126AC1D90A0ULL, 
            0xFC3ADF827460575BULL, 0x8EDA965907CE177BULL, 0x06123FA389131E8EULL, 0x00652F35258B9FE2ULL, 
            0x0A4F6EDDCF49957EULL, 0xDF2F26FE22735923ULL, 0x77A009CEE5139938ULL, 0x4CA8945F469335D9ULL
        },
        {
            0xE4232EFE212C5FDEULL, 0x49935C64ECC57592ULL, 0x883FEB0BD48CFA0BULL, 0xFD3A6E5D56F783C0ULL, 
            0x3244A06CF102890BULL, 0x62F93967D4D9F1A1ULL, 0x5821FED2F3E821EAULL, 0x7C5B64DABF43F36BULL, 
            0xC8BC7F340E2C758FULL, 0xF11FF6A384D7BF36ULL, 0x7E626F865140484CULL, 0xAD57C4D3E033A931ULL, 
            0x00CDACB4D7A28885ULL, 0xBBA87D8764EC0807ULL, 0xC62B213C62C5B2F3ULL, 0x502B5F34DD03DB3CULL, 
            0xDE0F718749BABAC3ULL, 0x7A2CE573834BB722ULL, 0xB63342D9756F5648ULL, 0x6504F7BA3CE013D3ULL, 
            0x14AE17BDD972CCC6ULL, 0xC65853385C289AA6ULL, 0xC4A62284C47FEFB6ULL, 0xA841E0E252822BD2ULL, 
            0xA6D7BAC5F9D3E481ULL, 0x91676F6E000D3FD4ULL, 0x09E1E9002D0C5AA2ULL, 0x0FF46A312559F714ULL, 
            0x185D8248100B369EULL, 0xFD29C96CBFAA4B97ULL, 0xFABC11AE5B7FCB1CULL, 0xA71EE36169EA1111ULL
        },
        {
            0xDE6B1360A063F7D2ULL, 0x5B2CEE1D93A15A8DULL, 0xA9811D1137A715C0ULL, 0x13200A1B44D5F493ULL, 
            0x2310DBF10D299F40ULL, 0x93553E5E600649E3ULL, 0xDA4727D61951B1C5ULL, 0x441B39727CADFE3BULL, 
            0xA3801292FE4D3F16ULL, 0x6CE417191CC44F73ULL, 0x2C84B751BEF05FD0ULL, 0x3D80362027230D8AULL, 
            0x76485843C39A77E9ULL, 0x46F4F72A642C44DEULL, 0x7CCC096AC1B713B3ULL, 0xCC490B19018158FCULL, 
            0xB752280440E745AEULL, 0x7D41D06DEBBFC3FBULL, 0x5E8F4949A49012F9ULL, 0x0F55543B328763B8ULL, 
            0xBCBD30CBA3E7A375ULL, 0xDC1F55CC41CAA46BULL, 0x0D55FA680C5D386CULL, 0xBEBCF202043553F9ULL, 
            0x2B48DBE78C72ACCDULL, 0x91788FAC67EA5C7BULL, 0x1C0C3FFA0CCEB9F1ULL, 0x73F81C05753920B4ULL, 
            0xA416A70D7EFAE187ULL, 0xCF87B846E5BDFF20ULL, 0xD1F5F103BE86FA04ULL, 0x892A6B20467E1C2BULL
        }
    },
    {
        {
            0x77FFAE377DBCDF6FULL, 0xF0D3F57033C41FFAULL, 0xDCB55CD5445ECA9DULL, 0x12B558CC6191ACC5ULL, 
            0xBFB1F89389C911C1ULL, 0xDBC0A3887C487FDFULL, 0xC95E8F76B22EF919ULL, 0x104ED6108DCDF74FULL, 
            0x4AF44893939B3B36ULL, 0x1CEA0B9A7E7A343DULL, 0x952856E940DB0CA7ULL, 0x6795B1C76ADAFA42ULL, 
            0xC879122D4937F7E3ULL, 0x351B7AF1CD29260DULL, 0x69C191C04180D3F4ULL, 0x85943C2C23DF5B82ULL, 
            0x48A8F02085146256ULL, 0xA51E0CF33D8E5460ULL, 0x4D9D1574522C5A78ULL, 0x12941F983EAEF48FULL, 
            0x3839E3C1042BB045ULL, 0x944AF7791D7AFE0AULL, 0x2BEDF2AD2B99E970ULL, 0x529C2B6461CE4364ULL, 
            0x199591E9B54401BFULL, 0x7A481445B6014164ULL, 0x73FF73D1C9A7ED62ULL, 0x35A4A264F6409D88ULL, 
            0x32DBB7804D9D1EB1ULL, 0xBDBA484E279DD5A8ULL, 0xADE4F714F841D861ULL, 0xEC600150CEE204BEULL
        },
        {
            0xF2354A48E703A669ULL, 0x8B5AEB3DF5CE93A7ULL, 0xF10719BF3CBCD9A3ULL, 0x682C5AA6A523993CULL, 
            0x5CD9066B5C9A9701ULL, 0xB34CC150AF00FBB9ULL, 0x24AE4FD9E1193465ULL, 0xD4F91032B32CC2F8ULL, 
            0xDDF6A27F2CC8290AULL, 0x4F23ED37585CA785ULL, 0x1627D15751DF65AAULL, 0xA704602A0C10DC2DULL, 
            0x1DE4E2DFFE6DB882ULL, 0xBF31B2BAE20F7401ULL, 0xADC35B0D894C7EF4ULL, 0x393D8D6DC1035566ULL, 
            0x525F131F8D650EE1ULL, 0x0B8DF17701463257ULL, 0x2A0884951CA2205BULL, 0x1B1AC16A7B2E9B62ULL, 
            0x4DC5D29637195C7AULL, 0x9F391BA30826AB7DULL, 0x598AAC5D940BBA6BULL, 0x15FE443D82BE70EAULL, 
            0x9F71FF05109FD93AULL, 0xFD0DA6156466A1F3ULL, 0x31B54EE09E3D6CB9ULL, 0xCEFC3754FA9CB8DEULL, 
            0xB2E68D33A81FD56AULL, 0xB4AA487E18780A9BULL, 0x2E702E70E59DB2F8ULL, 0x9D40A9BF4F5589FEULL
        },
        {
            0x9AD1C3B15578AA60ULL, 0xF32E78AFB58AA3B7ULL, 0x1C688F07E0D6816AULL, 0x9645F25555A12668ULL, 
            0x9F58B0767CE876EDULL, 0x363C52FBF0BB751DULL, 0x257DD5F4F1D411A4ULL, 0xA7E5D29DA328E0F2ULL, 
            0xE94BDBA1639F0BF6ULL, 0x1550CC68854EDDDAULL, 0x280D33EFA7552187ULL, 0xDF3DDAE70B97CF21ULL, 
            0xC0F48B2E32EB0CB0ULL, 0x05203D82913688BBULL, 0xDB266E1A6A3B330EULL, 0xA6C69CDF8AC2324DULL, 
            0x5984541487307187ULL, 0x791A8A069A84D4A0ULL, 0x0A2EFD56A09CF6D8ULL, 0x50593361E1320CFFULL, 
            0xA08D9A0A40B164A5ULL, 0xD169FB643F10B258ULL, 0x7B534C7BB3BC5387ULL, 0x500954B0B1317152ULL, 
            0x08C4044F18BD8D0DULL, 0x097F448F500A8E6AULL, 0x63E2317D44456269ULL, 0x58B34035B49B6AEBULL, 
            0xD1E6F4737ED82030ULL, 0x28B063A08FB06E29ULL, 0xAEFA4BF72E1B315DULL, 0x1518CCA3221C76B6ULL
        },
        {
            0x23EAEFFB61DCBF22ULL, 0x69E07CCCC6B9C805ULL, 0x553E2CB9DFB40A91ULL, 0x1C6A3996DE166C86ULL, 
            0x5CCBAD0A1CE57301ULL, 0x9600EDD1491BDFB7ULL, 0xB33FFC42D32C75CDULL, 0x3E699142ACAF3287ULL, 
            0x60E553C412757A5CULL, 0x8F16F28325F00FC3ULL, 0xDA181CE7DAE84AA2ULL, 0x71819B97A50F2124ULL, 
            0x28E86D5C9665843EULL, 0xFE5C3F79CAA2A174ULL, 0x539A6918030FF531ULL, 0xB3D860FBA98812D0ULL, 
            0x32BF623F33A23E10ULL, 0xB469E470EE5E96D0ULL, 0xA5DE69C5F0123CADULL, 0xA79ECACD53D2C2E5ULL, 
            0x4289272411DF18B9ULL, 0x1E28940A41216952ULL, 0x06AB5349AFC7F648ULL, 0xF7713BF67621245EULL, 
            0xABDB427371AFF5A9ULL, 0xAC50863D61E2D706ULL, 0x33CD91E2DB34DA8BULL, 0xF2DF305D93AE68CEULL, 
            0xCB2215B75999FD67ULL, 0xC1EC7D94419C3AEEULL, 0xC42C710692AE8468ULL, 0x54CAA3D10980BCA9ULL
        },
        {
            0xA40EF91CB19BF862ULL, 0xE03B0A2B41105CA5ULL, 0xB6F9D1D55068755BULL, 0x36F98B7B88E99E18ULL, 
            0x4F00997AEE758DD2ULL, 0x9B0F6E93F9BB925AULL, 0x45059EEC6979AE99ULL, 0x00AA4622CD4E1B96ULL, 
            0x63282EA60E7EFB00ULL, 0x1DC07658EB96A945ULL, 0x41B585DF9D7F9F11ULL, 0xB6B691EC5835E67CULL, 
            0xC7AE1B9683DFD6EEULL, 0x54316B39D04B3B06ULL, 0xF048365B933EE186ULL, 0x2CDFCD0DC068DB13ULL, 
            0x9D42BE7B99F806A6ULL, 0x1DC29F9A9F165321ULL, 0x3641B893D74029AEULL, 0xCB25BCB55ED5321FULL, 
            0xE8B95698AA3F1CABULL, 0x84EABB04C0809798ULL, 0xC4CC7E1409DFCD7DULL, 0x658D9EEF7F16DB76ULL, 
            0xC5DC27B147ECEE67ULL, 0xA3A7508663A3ABC8ULL, 0x7A652EE216137879ULL, 0x7B685807FB55C5EDULL, 
            0x54C2CAB7F4FEEFC2ULL, 0xE0ED532758CF77C8ULL, 0x30C0B72A49EAA553ULL, 0xC08C723992CDA160ULL
        },
        {
            0xB2CB11068D3A981FULL, 0xA29CAF3D51A43AD8ULL, 0xBDDB9B9A05B0F475ULL, 0xCD02002491FA1756ULL, 
            0x9C0CCE3912F0B72DULL, 0x1DC505CAFC062420ULL, 0xC4C40E63CF51E056ULL, 0xE86EE3236F7133C4ULL, 
            0x1F5D2760CAC134FBULL, 0x37B1BD66A28EE222ULL, 0x0289BDD866645888ULL, 0xE0F69FD5280EF607ULL, 
            0xD9CA47CE57C2F53BULL, 0x2092FE42230137EAULL, 0xD18D2A874025C71EULL, 0x4499E92A2852A944ULL, 
            0x8BC80D998B39167FULL, 0x162986AF42BADA93ULL, 0xCF4D28BC965D8979ULL, 0xB61B89657242C086ULL, 
            0xC6ECB1428D42C181ULL, 0x7A4872D1ECE6661EULL, 0xA9617BE3332BCB71ULL, 0x699009F225CD9D34ULL, 
            0x39192EFA86BC40F0ULL, 0x6FABBE420B300E5EULL, 0x20D56226CC658913ULL, 0x7F8A5B0A77D32C07ULL, 
            0x5DD05C934F24D96FULL, 0x68DA91AAD63497EEULL, 0x357B1D7E3CBB26ABULL, 0xB8CE77AC44C5FDCAULL
        }
    },
    {
        {
            0xD3AC4484176F85DCULL, 0x8BF9BBE95B1B1900ULL, 0x6D93F7DB65C7DF37ULL, 0x2C87C4B9A87E6B7AULL, 
            0x7C114A9DC7335CD9ULL, 0xCD7D903756AB274FULL, 0xB8C16A52B055F0CBULL, 0x9081A116A9EE197FULL, 
            0xB44065E329753974ULL, 0x090A6F7288CEB5E8ULL, 0x047A3C53D353D268ULL, 0x761AAD0B3B253C4EULL, 
            0xEF5DA279490C490EULL, 0x13BF3A6241BA6F47ULL, 0xE75785F1767950CAULL, 0x77EF73E60CF33C87ULL, 
            0xD417C71F221BA7E9ULL, 0xBC6969B176B0AB47ULL, 0x31E21D6A93302964ULL, 0x20321CA37C464705ULL, 
            0x46A83EBA65C26746ULL, 0x52683E453888E44CULL, 0xE1B4C69E01F1D44CULL, 0xF53CECA7BB1A9389ULL, 
            0x1103B4785A8495A3ULL, 0x2072FC51639A1904ULL, 0x4F8DC498A133EEA3ULL, 0x6B5ED62775F9FD58ULL, 
            0x821860C0D07B8864ULL, 0x711CEF3057784F99ULL, 0xF6EF8769EC9EE5C7ULL, 0x45386C5A2C18993DULL
        },
        {
            0xABE7E228E1399E8FULL, 0x203ED33EE42420B4ULL, 0xAEAB4C0EAAB06EC6ULL, 0x6F7ACC1A6FA8507FULL, 
            0xF284970212CD8C16ULL, 0x4013781CB55832ABULL, 0x39157FD27128F228ULL, 0x604F4263307B6C39ULL, 
            0x383A9EA05FBD5727ULL, 0xAB4FB0550162B4FEULL, 0x5D247227908B040DULL, 0xA098348027588CD3ULL, 
            0xF2BFBB144123D101ULL, 0xED0CBC1A15EECD1BULL, 0x991FD931AC500F0AULL, 0xBA9A09DA90D7BFF8ULL, 
            0x054A172A5195CE37ULL, 0x066A53887EE71A88ULL, 0x86B1843933D6C0E1ULL, 0x4200F6DD0B78BAF6ULL, 
            0xE120E4E2E16D4876ULL, 0xA8EB62631A41746FULL, 0x5ADA8E3E0453E778ULL, 0x278D094F9DE7AD35ULL, 
            0xF0FD2BF2AFDBEC35ULL, 0x0C89970DDFDA9647ULL, 0x693A04A2722F0327ULL, 0xEE3741C14A26FF83ULL, 
            0xB6EB77091A3F9653ULL, 0x08DD8CE2F5E9BEC1ULL, 0xFAAD43C1C1F5CC72ULL, 0xC0E9E1498F904CD8ULL
        },
        {
            0x681DCFA0DE10D88FULL, 0x56ED2DF81A790CB2ULL, 0x72C31BA9FD230D33ULL, 0x1346246CB24E4640ULL, 
            0x11EE77E9014BD1A4ULL, 0xAF408C7BBFA476C1ULL, 0xE4692E7D7C820684ULL, 0x1B7A77FCB9F69CD0ULL, 
            0x37A1D41D9A28E329ULL, 0xFC9429D8D7327DDEULL, 0x8F729A339532A630ULL, 0x9DF17FD64D8B74ECULL, 
            0x67D974A5ABFB66B2ULL, 0x201E0BB05A932A77ULL, 0xE734071B519787D7ULL, 0xAFEF93EA102CD50FULL, 
            0x103C65691BCFFE90ULL, 0x1466E7435F2A9E02ULL, 0x0EFAC3954F34C313ULL, 0xCBA539C0FE1CA0BBULL, 
            0xC6CEF5B14AAC3286ULL, 0xD5115C95EDF8386DULL, 0xEA0005966E6E748FULL, 0xDC7A64C2B9F646F6ULL, 
            0x156E98137BA79F85ULL, 0xA60637159FF8B161ULL, 0x8A53DE4469E224CCULL, 0x22E340C6328F2E5FULL, 
            0xE33874802CD69A0CULL, 0x54FE9186C5A57A24ULL, 0x77D6DD1B3A6A7CFBULL, 0xE35725DA17BC4036ULL
        },
        {
            0x53D1DEC7CE531C65ULL, 0xA4D08E1C2800725CULL, 0x81A6162B57F33EADULL, 0x17F2EB06EF575838ULL, 
            0x5F9B8A1A4832F048ULL, 0x1A86E6CE2C79423DULL, 0x22B5C1DA94C2DEA6ULL, 0x5540F7061253F342ULL, 
            0xAF38AD0E9A19D741ULL, 0xB8A9711029F2125BULL, 0x3169A2F039EA2B3AULL, 0x6FCF4A4B82E1F7A3ULL, 
            0x4D14C6F2A7144DC9ULL, 0x91ADADC7EC2BCCFFULL, 0xE6BD558E8E78088EULL, 0xF19BA544CB679698ULL, 
            0xCFD606B76D5F95E4ULL, 0xA0E69428C05046B1ULL, 0x8E39D96026E7CC1EULL, 0x5E25417143922E5DULL, 
            0x67A377672CFF8B2CULL, 0xA080B5BF36CEA55BULL, 0x3EC8610F831C4DA5ULL, 0x5EEF3037E2954713ULL, 
            0xF12CE845B89BB765ULL, 0x37D1A4C3E6C8B8C4ULL, 0xC3D5423FAD558A3BULL, 0x1D499D67B22359B8ULL, 
            0xF0BB126E89AAA8BAULL, 0xB898E507A63DD548ULL, 0x4FB720190BDEBBBCULL, 0x235ADA31040934DFULL
        },
        {
            0xB61EDEAFE788901AULL, 0x2230405946F678ABULL, 0x0E1FD691B72B58D7ULL, 0xAC4A441644C22278ULL, 
            0x229BA1979C108ADAULL, 0xAF576D0F50ADED32ULL, 0xE5DEE69F338B6E94ULL, 0xAE8819C9684216A7ULL, 
            0x113AFE8B0FC2FFFBULL, 0x20C79AA4D2B069FCULL, 0x03D44974478E15EDULL, 0x4EF440BB4D17D368ULL, 
            0x227B3CB82A08AB9DULL, 0x5A43A3F2C535E9F3ULL, 0x2DA6109E4DC51362ULL, 0xCFB28855A32F2204ULL, 
            0x8B08A03945630B27ULL, 0x0EBF5C16EF52FAC3ULL, 0xA3EC6D0FECE9D698ULL, 0xC164991572E1D0ADULL, 
            0x1A86105F55166DFBULL, 0x5641B7C9AE0FFC44ULL, 0xFDA3A22530270563ULL, 0x704F7283B1104399ULL, 
            0xCE29812E70010BEAULL, 0x40F09FA31537F1CAULL, 0x0EF2B6620113E512ULL, 0x082F5C044D3B0E75ULL, 
            0x3CBDF8BBB9CFBDAAULL, 0xD2A1A48803A0EAE9ULL, 0xAD13AF30E66C7A0DULL, 0x62050F3A2467D0FDULL
        },
        {
            0x963C77644D0343C6ULL, 0xAEBC8D2FD481ACC9ULL, 0x6B01A2712F509848ULL, 0x39BD6B9561452AA3ULL, 
            0xCA50E5742502925FULL, 0xE4B6770976B5A2B9ULL, 0xD5C7A84AA22E53F9ULL, 0x9A77AA472B1D325AULL, 
            0x976435B251AA29FDULL, 0x4CD3E1A31EF63792ULL, 0xFAF5B7BE416DF641ULL, 0x362BEB2F989FF952ULL, 
            0xAA8CB259E79D4C08ULL, 0xFD3BDEADA07F940EULL, 0x25FBA58E974B410EULL, 0x4BB4343A9076114FULL, 
            0x828D87AD8F5335BFULL, 0x13B417B24A29DCC3ULL, 0xE61A4866823C7C6BULL, 0x33E493FE16D20BFFULL, 
            0x82316329F7DBD0C7ULL, 0xBA321CB44C3FA0B1ULL, 0xC93CB8C9513F49FBULL, 0xA4371AEBA2650F8BULL, 
            0x24A41EE0C5A6779BULL, 0x28041A4D435FA056ULL, 0x2F27DF9BC189CFAFULL, 0xFFB870C0F921FC7FULL, 
            0xF132C664CC98CD13ULL, 0xB6712CBAF297536EULL, 0x26644B2CF0D1D3ADULL, 0x5E92E30B6D307481ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Athebyne::kSeedConstants = {
    0xD067445D40B18B80ULL,
    0x76F708C0EAE01813ULL,
    0x7D34139965B0A1EAULL,
    0xD067445D40B18B80ULL,
    0x76F708C0EAE01813ULL,
    0x7D34139965B0A1EAULL,
    0xA7AC503272025802ULL,
    0x9DFABD5264C56A75ULL,
    0xD3,
    0xAD,
    0x5E,
    0x4C,
    0xAE,
    0xA5,
    0xCA,
    0xC9
};

const TwistDomainSaltSet TwistExpander_Athebyne::kTwistSalts = {
    {
        {
            0xF5F338B7D922A3ADULL, 0xFE3F4B36EC24BF08ULL, 0x34F7EE0DD0BA4921ULL, 0x2C169B423003113CULL, 
            0x83B8C2B28DC5B512ULL, 0xDFC2920476E8BDF3ULL, 0x737E3D26585A41D5ULL, 0xBB35A8B6C864FD0DULL, 
            0x83427B872E87868EULL, 0xCD2690EC05D62464ULL, 0xF4EE8062EEE08F08ULL, 0x2876D4F471ECC182ULL, 
            0xB98839BD2797DE45ULL, 0x95A40096902759EFULL, 0x61F4BCAACA669DF7ULL, 0xFFE92C28DADEFBDDULL, 
            0x3416F472787DA001ULL, 0x690785D1AEA91672ULL, 0xEF430E451087360FULL, 0x5CF1551C44F261B4ULL, 
            0x7EA485122D53FA70ULL, 0x176FA5929D1EFE21ULL, 0x88F366F7A4385146ULL, 0x57A31F32BE8C56DFULL, 
            0x2763B7D862EF6B16ULL, 0x323A96E1E64364BCULL, 0x2C4A5EF61064B29CULL, 0xFD058657A86B7468ULL, 
            0x3F481A8BA3BD3D17ULL, 0x7C2EB122CA9E358EULL, 0xAECC696E12CB48B2ULL, 0x5CEBF2599CFB0624ULL
        },
        {
            0xAC7E507C95A00BE9ULL, 0x2A2318B76C00740FULL, 0xFDE47A8691B0ED24ULL, 0x6B7992D3922E73C3ULL, 
            0x7A52D3C656426519ULL, 0x8BA9D33156ADA0BCULL, 0x4F8EED0B66A1F578ULL, 0x7D6993964AFACF55ULL, 
            0x9344E40BA1E0BE94ULL, 0xA2B8C6CBA07DB18FULL, 0x7CF76177222E5E61ULL, 0xC5086354B58006D3ULL, 
            0xE11DABAD381B01B7ULL, 0xB027BC52FFE4E8F6ULL, 0x21499C71B8F2719CULL, 0xDA28F140389A5A9AULL, 
            0x1CF432AFB672DC8EULL, 0x1C7C775455D89741ULL, 0xD9108BF266BFEFF2ULL, 0xC6C9C358F17078A2ULL, 
            0x0B0A909AF15AF389ULL, 0x7AF8390AFE3FC535ULL, 0xEE7C88AA4A90F9EDULL, 0x148B2FE26E1E3C73ULL, 
            0x287809BEFC2E22D5ULL, 0xF62B8304FE81283AULL, 0xEE55C9BE9667F222ULL, 0xBB9C78A78EAC34A3ULL, 
            0x7F45F313F9DDE0FEULL, 0x7CAEAC9765DE2F14ULL, 0x827EFAAAE13D3F6FULL, 0x204E5DBC6727B3D7ULL
        },
        {
            0x32374B4CF902BAEDULL, 0x9D42FE30B3FA4578ULL, 0x8E908E3D802BAB43ULL, 0x4F32AC383B6F10CBULL, 
            0xE29E8924E2FF97A2ULL, 0xE6F9DAA2B5A41642ULL, 0xA931B038277015C9ULL, 0x6CD145184F0E8C2BULL, 
            0x30E21B996777CC4EULL, 0x89E2E0CEAB5A24ABULL, 0xCC9DFA605CCB5323ULL, 0x4E521824C11DE9CAULL, 
            0x9A8F570B3E5C5F1FULL, 0xEFF8BBAB21070A79ULL, 0xE93ADBBC8D89F956ULL, 0x4251B9CAF9C50052ULL, 
            0x34F1DFB76FAEA2EBULL, 0xDA0CB7C750FADD7DULL, 0x755F92C1C8B83742ULL, 0xE4EAA40EF4BEC2CCULL, 
            0xE7F426133ACA1760ULL, 0xC6B94EEB2E0F1A33ULL, 0x6A24D1B6EF81FAEFULL, 0xE2D6E20665BB15EBULL, 
            0xF53DA92C8FE49558ULL, 0x8277E9B908608876ULL, 0x572BD77231402927ULL, 0x31C34A4753E42160ULL, 
            0x4CBB8F39B0F84452ULL, 0x2B37E58BE62C5262ULL, 0xEAD1FB070946E920ULL, 0x28E85577968B6738ULL
        },
        {
            0x442AFB66617BB47BULL, 0x5FAAB6ACA1DD8EE4ULL, 0x1FA7F1F36605D156ULL, 0x2ECE85BE59309E28ULL, 
            0xD29F424D21506152ULL, 0xCE1609B54181BF6AULL, 0xDE95784A90D5AE5BULL, 0x83682428421AAFD2ULL, 
            0x5D5095C6DF9C3E66ULL, 0x37FD1F33A8E70124ULL, 0x0AC32EB086B253B1ULL, 0xBE30B5BC9DF0EAE6ULL, 
            0x881E5FEE7F6FFBFCULL, 0x9C7CB13B16A45024ULL, 0xEEE9C0FEB9B72076ULL, 0x204D348DFCE9A73EULL, 
            0x4A35B98D8643062BULL, 0xA3BA6E2398FE2FD4ULL, 0xE236ACA5BDCEAD39ULL, 0xA04970B81E716B8DULL, 
            0x2D6167CC2860C457ULL, 0x902781DCC76B8330ULL, 0x5810454988B716FEULL, 0x15EDEEF50B3D8BC4ULL, 
            0x8B2139E70987AA9BULL, 0xEF09878B5831F58DULL, 0x498202DAB678AED4ULL, 0x52C246AD731E36D0ULL, 
            0xAE6DA3B14DDD4605ULL, 0xD7AF74426106FB62ULL, 0x349FF25AE025869CULL, 0x218780FB9E761A42ULL
        },
        {
            0x9043773DDE6F7624ULL, 0x733C5473158D4061ULL, 0x7776AA7E6AC426EDULL, 0xDF99ACF66E4F2249ULL, 
            0x45B0B7613110369DULL, 0x704D4D7A5B20741FULL, 0x17E68D7B675A9430ULL, 0xCDDABA9F1795477CULL, 
            0x8884A8C4C3725A53ULL, 0x0EAB0282FC05EAECULL, 0xEE37605E064B3147ULL, 0xFE273E4ADBEC912BULL, 
            0x9F79D136F60B46A1ULL, 0x40E5C2EE12746480ULL, 0xCC2C5969DFBE13ADULL, 0x6553C55443E5A7D6ULL, 
            0x543588F076F62FCDULL, 0xFCE37758F2325547ULL, 0x6929746B038537A5ULL, 0x5B647605FE6C68ADULL, 
            0xB2E156033022B2CFULL, 0x3F17EEC449FE4EECULL, 0x2B61531964FC0A51ULL, 0x6C664AA55931A83CULL, 
            0x306BE3D0ACFC34DFULL, 0x8CC0CB4107D9B30FULL, 0x5FD4D7D67A3656E3ULL, 0xC92AE8D5E275FC91ULL, 
            0x1EAF2C5A8E72B06EULL, 0x791B3820A5C496A4ULL, 0xF9BADD32C82D5849ULL, 0xB5119789110899CDULL
        },
        {
            0xC21B32FDCCE24EF7ULL, 0x84AD71480A441742ULL, 0x5A57D18B53287C36ULL, 0xB526F4A1E3C5F3BEULL, 
            0x96ECDB7F0B1FB7B1ULL, 0x51C46C24A20916F7ULL, 0x14BE04264F105B2FULL, 0x1FA21E24613A144BULL, 
            0x58B1568936DF9B12ULL, 0x8EDF11B42264EF8DULL, 0xFDB9B605AFBF17BEULL, 0xC13C73FFF2B472BCULL, 
            0xB04827B96FDA00BFULL, 0x88C8B49C96F1A97AULL, 0xED45ED939BD51785ULL, 0x66BEFFE2D62213D5ULL, 
            0x44C4DD535045B7BCULL, 0xCDD45B69A1E27799ULL, 0x691A5893B4F42495ULL, 0xD9E401007A126D38ULL, 
            0x355F5A9D478B0145ULL, 0xE8EDD97FD7F4B3CAULL, 0x3A644B0F725F9E42ULL, 0x880818F02C71B331ULL, 
            0xE3FE4851EF56634AULL, 0x78FDD9631B56582AULL, 0xFC081F425C533639ULL, 0xB35BC03A91A61657ULL, 
            0x47F1E4AD4451DDDEULL, 0xEEA76B94B22A0F76ULL, 0x1165DD0439EA289EULL, 0xE880588A805E1BF9ULL
        }
    },
    {
        {
            0xBE58BB94BED67252ULL, 0xCDC1EC7B8C98C0F3ULL, 0x9E6B410B5E9D4254ULL, 0xAF03C5E6B32A4D6AULL, 
            0x4867E53883F09091ULL, 0xCACFC33B6F9F5C4AULL, 0xCBBE2349E0AC97E8ULL, 0x9068EB2000F86C36ULL, 
            0x49F6B84BB54E94EEULL, 0x53343FE44F76C9E9ULL, 0x53A3EE7B0EF1F81CULL, 0x74F1866965AE3D43ULL, 
            0x03F5314232EEE09AULL, 0x5584BA657C6D6BCEULL, 0x1AEA8690FCAD0238ULL, 0x3705541883A2DCC9ULL, 
            0x610E2B4A81F9D317ULL, 0x67C52C64FDA5F350ULL, 0x06A78012B766CF50ULL, 0x5DB989E462F815AEULL, 
            0xEE94F7E299090DA2ULL, 0x2425D6FB9B17BD9DULL, 0xFB87BE99464037A9ULL, 0xDE8F096629C598A4ULL, 
            0x9DB8C965A71970A0ULL, 0xCC7B17322F834699ULL, 0x3F9868F1099888AEULL, 0x62EDCDAAFFFCD837ULL, 
            0xE161157A095CC80FULL, 0x4ABB1C639C7D9D16ULL, 0x8E26D97248F54937ULL, 0x6E0B26CA67FD0C5DULL
        },
        {
            0xFD1E8E53B8535A4EULL, 0xA81FC5E7C98387DBULL, 0xFA646885F670ACE5ULL, 0xF897B93E9781DFD3ULL, 
            0xB43B61DB4139C5ECULL, 0x650FD9A7F6E810BFULL, 0x2988ADCE3BE4B39BULL, 0x095723B8948BD75BULL, 
            0x5AAE5545ABC2D780ULL, 0x4CC854C938062F19ULL, 0xDEA53B06056AE5E9ULL, 0x6A32659171FD22DCULL, 
            0xE89401ECAC18337FULL, 0xABCE351D300362B4ULL, 0x661187DC754DA9D6ULL, 0x0C3C69E3E4C87B1CULL, 
            0x7FF66949CCDE9723ULL, 0x2084AA87555C9723ULL, 0xFD55486BEB84F022ULL, 0xB89A35678488C7FFULL, 
            0x26829A018A9A677AULL, 0xFCB85D2B735370A5ULL, 0xAEFF9E1EB95633A8ULL, 0x498006C5046C04A8ULL, 
            0xA15BD6995D9E435DULL, 0x5B7D73F0D731BDFAULL, 0x40AD8619C871F328ULL, 0xDA59EA3DDB336EF3ULL, 
            0x9C59E36C929C69B8ULL, 0xB6B8CFF32AA61801ULL, 0xBEF25A6A0B57678AULL, 0x54B946DE72B6D779ULL
        },
        {
            0x15F2BC69BE4563A5ULL, 0x57F680332316E0E8ULL, 0xBD5B1A5F865582A4ULL, 0x42229E186C0CF642ULL, 
            0xCC026BE00413CCBDULL, 0x9A35D6E7F8B370DCULL, 0xD001AA194E6475D1ULL, 0x244BD5C5FDE39454ULL, 
            0x8DB166C0D2E6E829ULL, 0xE1A9FE118E4B9881ULL, 0x2684B3AC1ADB7F38ULL, 0x9E7FF34C24B1E6BFULL, 
            0x5FB9E097F6C46B6FULL, 0x0FADFBD4D26DF5A4ULL, 0xB3F54F43F31E830EULL, 0x3CB1AE40038CE6EBULL, 
            0x5FC951F67D259C4AULL, 0x2D05A6BE5C71656CULL, 0x2A6283FF57B6B025ULL, 0x1FC0E131E51516AAULL, 
            0xD781FD266B06BFEFULL, 0x1B4DCD1AF3327F9AULL, 0xA5BD5DD589493B2EULL, 0xCCFF4991109C291CULL, 
            0xB9D6365ABD3C7A59ULL, 0xA0B4A022C71267D7ULL, 0x4F1C689515710CA8ULL, 0x23D9C85AA36C183FULL, 
            0x51C300404D484C51ULL, 0xD04B3E64788B2C40ULL, 0xEE8481F2E24ADE65ULL, 0x4F16D792E765A644ULL
        },
        {
            0xFD411F18B6D9B4D2ULL, 0xB015E7F42DF5F65EULL, 0xC86346F70ABCA707ULL, 0x70CFA055ADF25E8BULL, 
            0x5E8FF1F54E9A3A27ULL, 0xF1B3E033B0234874ULL, 0x511DB7CD2F1A0F20ULL, 0x19C98554458D6051ULL, 
            0xCE5B6681671726E4ULL, 0x3EDD4E1E17F404DEULL, 0xA4F9E6332C78C6C7ULL, 0xB26891225643D9E2ULL, 
            0xFDCAEA299578C5DDULL, 0x4C39E693A7837157ULL, 0x5FF867BD82AA6E5AULL, 0xFF55CB446A313370ULL, 
            0xCB69CC9565129AEBULL, 0xB236E750E0E4D9B5ULL, 0xC2644986D43E31E8ULL, 0x7ACFC6F256AB0AF7ULL, 
            0x489D3ABF78F78D7DULL, 0xCE4CDE35625B1BEFULL, 0xEB9C102F3A26C27BULL, 0xCBD9420FD706CA85ULL, 
            0xF7EE276DD194B3CEULL, 0xE8980879536BB6E3ULL, 0x276F4BDCFDB09176ULL, 0x0E70E691606CC711ULL, 
            0x15268558960C0340ULL, 0xB0EA723B5B134095ULL, 0xBC3C98A0632BBC94ULL, 0x8A76DCBE06AC716FULL
        },
        {
            0x237503571311D537ULL, 0x0B4EE76A7A888051ULL, 0x051A1E920396CACCULL, 0x41264CE620E9960FULL, 
            0xD4F499F65D14C5AEULL, 0x5DA95432D93C3895ULL, 0xA83A03E572073AB3ULL, 0xBDFF99DFA91F7810ULL, 
            0xAFFDB2464E1C0721ULL, 0x5B9D82D1F7D722DAULL, 0x914128D50803EDA6ULL, 0xB5608F4D7F43DDFEULL, 
            0xA936A45A03BB247DULL, 0x501F114E510CEBBFULL, 0x9B68EDE039F978E4ULL, 0x0E95677E4F5F3897ULL, 
            0x625AC637EA463276ULL, 0xD6E97A92173B70F4ULL, 0xAF0F8541E43BA9F0ULL, 0x468FB2117EFDF478ULL, 
            0xF832639ACB9DCB86ULL, 0x5B52A3B03E4C55F1ULL, 0xCDDB34175FD10B1DULL, 0xF16B7311376156A5ULL, 
            0x12E5767EA7F41A31ULL, 0xFBB0D1BF6A56B7FFULL, 0x09E90B3CFD371D3CULL, 0x840F6E4917DA2AD8ULL, 
            0x6DC94127AB44D5A5ULL, 0x73117591E22A2733ULL, 0x253414F76717A53BULL, 0x50C589D20DEF8D07ULL
        },
        {
            0xB9DE8E73B6C78158ULL, 0xBC745CA89A2F13DEULL, 0xEC9F8BCB1F79A915ULL, 0xE5BC9D3FBA2B7E4BULL, 
            0x98E231EA3EACBC73ULL, 0x85FCDFAAA897590AULL, 0x9E844441C2D26794ULL, 0x0E7366CE405F7BF6ULL, 
            0x865E46EA817DB719ULL, 0x3BEB88B2B1E08F39ULL, 0x2BD5FB5A3389C9E8ULL, 0x8ECD6FF6640443EFULL, 
            0x2FA433D1442EA828ULL, 0x2E256171EABF22E0ULL, 0x0024FAD8C43CED54ULL, 0x7B9B8548FEB5FB97ULL, 
            0xD219DD2AD6AC3D72ULL, 0xD6333EAEA22C0865ULL, 0xBEB8A89591211447ULL, 0x4184D92E2CC65969ULL, 
            0x496E13636E6551BBULL, 0x727402BA17540BB2ULL, 0x9A6D2B7AF1BED5F1ULL, 0xFCFC1CD8944CCB45ULL, 
            0x2FB5D1C86E57E6AEULL, 0x0200642CD232380DULL, 0xFD1B3B51717D08A1ULL, 0xE4D9AC21210C9E82ULL, 
            0x79C383B6D72C02EEULL, 0x32934BA81EB1F6A5ULL, 0x799B500AEAFB9203ULL, 0x4A23D539ABC91598ULL
        }
    },
    {
        {
            0x63E0E581955E33A6ULL, 0xB4758CC1F4216395ULL, 0xCAE2CD986D311232ULL, 0x28B6022638898E4CULL, 
            0x2F7E8C687536182FULL, 0x9FD4A0B15C434BACULL, 0x1A873236DF272E00ULL, 0x1025962F6EB6A066ULL, 
            0xCA744770B4A49FFEULL, 0x783B25B851D6E75AULL, 0x57E795967EBF3BD4ULL, 0x4D4D3D913D455909ULL, 
            0x1DFEA3B780408666ULL, 0x6B6896E4DB50F944ULL, 0x5B705CBFC9FA4F97ULL, 0x60D5767819404714ULL, 
            0x3691094FE4BA10C0ULL, 0x8D3BB7050F80DE8DULL, 0xCF69CEDEBBDE6B4DULL, 0xF715702C228416C2ULL, 
            0x0C9E123203C81CE5ULL, 0x00CC3117BE341FCDULL, 0x5BFEC926F7862D4DULL, 0x366C4D9E29E30212ULL, 
            0xB1C83656B6669C62ULL, 0x68E5A435556649A7ULL, 0x10687DAEAA80778BULL, 0x7ADDABAE6F8F355CULL, 
            0x8F889F504CB82371ULL, 0xCC7C0FF38C3138F8ULL, 0xC615DA38CA2DA5C9ULL, 0xEF3AF555ECEE28F5ULL
        },
        {
            0x95EC5BF24A78D4B1ULL, 0x3D3352FA33D66855ULL, 0x62A9F1980E4A410DULL, 0x6A392FF3BEE1570BULL, 
            0x1A3FC9CFD37C82F7ULL, 0x2B0C78537995814FULL, 0xFC44BB26B6CD128FULL, 0x9A4B19A2F8A0183DULL, 
            0x07987574D64110E1ULL, 0x258CC890439ACE51ULL, 0x400F5EEE957FE5BBULL, 0xF5A8E6C912701A47ULL, 
            0x6A04C103422321CAULL, 0xA344EB090BEF8931ULL, 0x8FCED095E22AEDE1ULL, 0xEE2CCDFBCF04C97CULL, 
            0xD260E3A94F3F703DULL, 0x3115E4E380DEF310ULL, 0x8E0E8D333B965053ULL, 0xE8DC6A98CAFA10A0ULL, 
            0x1DC6933D6307C9C6ULL, 0xCBDFAA6491AF7284ULL, 0x88CFAE6F5AD956B4ULL, 0x833AADB731916D5EULL, 
            0x89B10E8D6E4A89B2ULL, 0x88B7B47B5908EEEAULL, 0x9F455F6D0637997DULL, 0x8DDEF3FA312538F2ULL, 
            0x25793D7A26DFCBA8ULL, 0xA7248A50B7F17D23ULL, 0xE80F367FE92D7A16ULL, 0x7C3A3D718E92AEB8ULL
        },
        {
            0xA8F1F73243C6250FULL, 0x5D8AB123F67444E9ULL, 0x388BE5C253741AFFULL, 0x7A3A228EEDF3E22CULL, 
            0xB3871D48E9228A48ULL, 0xEE4115B68CA9AAC7ULL, 0x06583944EE69CFCCULL, 0xD91CBED64075107AULL, 
            0x263A7FA2DB245609ULL, 0x4EE018549E8C9AD4ULL, 0xEFFEF33D85EA3672ULL, 0x32656E6B901853A5ULL, 
            0x9EA4232BCC428706ULL, 0x386C0454D67B3E0DULL, 0x89B32CEE0E3C3BC7ULL, 0x0FDDE22B676FC4EAULL, 
            0x9C9D0625E1BDC050ULL, 0x03AC0AE1FE1A0C0EULL, 0x04CAE1B9E293735DULL, 0x4F4B64592C99CA6EULL, 
            0xC7045C435D7F4C8DULL, 0xF8548E7A213AAAD5ULL, 0x320B2D5E18A758A3ULL, 0x3EC38C08BF723EA1ULL, 
            0xAFDC28B8954FB356ULL, 0x622A929E491ADFA5ULL, 0xB40E3EDC1DDEB07DULL, 0xCF26323914F1FF15ULL, 
            0x89D8651DC4E7365AULL, 0xCDFD50841512103EULL, 0x5D7B5F391EA234E3ULL, 0xA1804EAFE99B7A4CULL
        },
        {
            0x3324845788796F9DULL, 0xE782F8FF6794DDCCULL, 0x1D3D4BF09B4DC922ULL, 0x46D9EC5FE5B825BAULL, 
            0x806E5EA85834EB84ULL, 0x68B2F8C4233BC010ULL, 0x098A6A91C13DE9FAULL, 0xFBD111B7EDFF3E9FULL, 
            0xDA5FF708CD4F7B70ULL, 0xFE7A93CD68EA3E1FULL, 0xA4C033C5EF3F2977ULL, 0xA7A96BFCE9722B67ULL, 
            0x5C5FE892E5831312ULL, 0xDFEB0D4F13B554DDULL, 0x7312E0E6D3715781ULL, 0x5D5BFC7626B17910ULL, 
            0x9C7A91BC2D52C3CCULL, 0x1E0A63DB6FBCACBBULL, 0xE27C7744E9E87D7BULL, 0x649D2355C5FF724EULL, 
            0x37DC010D56572436ULL, 0xD71936A6406C63FEULL, 0x488B43418B74517DULL, 0x735EC731C5AFDF51ULL, 
            0xF3D9F352B502961EULL, 0x825F2DAC0B4574A8ULL, 0x768433B68F6789CEULL, 0x24C3248635A698C7ULL, 
            0x06E723F59EFBF3BEULL, 0xCCC7BED5F9870F2DULL, 0xC060AA81D8D24BD0ULL, 0x615C75C48DE6EDA7ULL
        },
        {
            0x5C53CA7CBFC66B61ULL, 0x4D8A42E5BD1B2083ULL, 0xEF7BBD3A3AE1ECEEULL, 0xC2791CB3D6067999ULL, 
            0xBFDD254742BBA414ULL, 0xBB5E5A860DCD0E24ULL, 0xA1EF6A69ABFAF4BBULL, 0x1253479E41B7B7F3ULL, 
            0x635AB2B63E9B6310ULL, 0x51F621D64D042472ULL, 0xF213A85C514D217BULL, 0xDDDCFE2DAD199EE3ULL, 
            0x647AB7E608287383ULL, 0x12ED3E7772E5E163ULL, 0xD9147ED8066271C6ULL, 0xC0F9C96051BF2682ULL, 
            0xDD7E815D8823E61BULL, 0x6214992E0B39276FULL, 0x20615D7E6A3F43EFULL, 0x626A5101ED7AE96DULL, 
            0x2959F5FC2B8273E6ULL, 0xE06DE317A8070C0BULL, 0xC69214A81A06C58AULL, 0xFD6A3FA788BE86F1ULL, 
            0x2A5FD9A2DB56AE9DULL, 0xB44553011B897ABEULL, 0xB4B222249009CF3CULL, 0xC41F098BDEBF1F55ULL, 
            0x41207710948A01F4ULL, 0x6F3F4693CE4BC660ULL, 0x0E399077654F9CD5ULL, 0x47AD53C0C149F3E4ULL
        },
        {
            0xFD9DE792E53B2F0AULL, 0x29860A1F2C36C9EEULL, 0xDEA56B17FFDD83C7ULL, 0x2186343957B44FEEULL, 
            0xD3D56615CD3860BBULL, 0xE9F884ED116F5D9BULL, 0x9525A8A6325500F1ULL, 0xAF44533E519D7B2EULL, 
            0xA0C909CCCD66D33FULL, 0x41C884BDDB921BCEULL, 0xB6E97B97A6B5A89EULL, 0xA55F33007C940E0BULL, 
            0xD7DBDE9C7FCB7A8DULL, 0x7EE4D76CB8355E5EULL, 0xDBCA0949492DE9C0ULL, 0xAB4BB3927CA8EED3ULL, 
            0xB901571EACA8D985ULL, 0xBC5B397C3EEF022FULL, 0x2CD3DBE8BB16EB2CULL, 0x781E0120FA7E7CC7ULL, 
            0x018CA3988F69962EULL, 0x2AB8A2EC4B7FB021ULL, 0xB8767FCC504C1505ULL, 0x7BE29F26D46426ADULL, 
            0xACCC3A28B54BA86BULL, 0x331F9AA64596A5F6ULL, 0x9E4F137E1137133DULL, 0xBF96A87B8E305D91ULL, 
            0xD69CC9C9A640D36BULL, 0xB90177E2AC8A176CULL, 0x9C5D72E77BB94D1FULL, 0x8915C15D30BD19CAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Athebyne::kTwistConstants = {
    0xF8011CCBDDA375F6ULL,
    0x73C698A1C0FEAC2BULL,
    0x69EB0A220A7FC16BULL,
    0xF8011CCBDDA375F6ULL,
    0x73C698A1C0FEAC2BULL,
    0x69EB0A220A7FC16BULL,
    0x54DAB94EA6EDF708ULL,
    0x05620165BE6700F3ULL,
    0x34,
    0x44,
    0x4C,
    0x13,
    0x0E,
    0x9D,
    0x27,
    0x3E
};

