#include "TwistExpander_Alioth.hpp"
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

TwistExpander_Alioth::TwistExpander_Alioth()
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

void TwistExpander_Alioth::KDF_A(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Alioth_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Alioth_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Alioth_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Alioth_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Alioth::KDF_B(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Alioth_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Alioth_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Alioth_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Alioth_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Alioth::KDF_C(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Alioth_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Alioth_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Alioth_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Alioth_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Alioth::KDF_D(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Alioth_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Alioth_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Alioth_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Alioth_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Alioth::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xEADDF064FEA174D3ULL;
    std::uint64_t aIngress = 0xBD03312EA184A1CEULL;
    std::uint64_t aCarry = 0xC1B94DD6102E1374ULL;

    std::uint64_t aWandererA = 0x9C62AF30D42C1079ULL;
    std::uint64_t aWandererB = 0xA4F284D8FB6C95C3ULL;
    std::uint64_t aWandererC = 0x9A56E07478E9E79BULL;
    std::uint64_t aWandererD = 0xD5EF9CB15CEC32B0ULL;
    std::uint64_t aWandererE = 0xE1DCD4889BDFDF01ULL;
    std::uint64_t aWandererF = 0xFA3BD16955A00C74ULL;
    std::uint64_t aWandererG = 0xB00716997C0F5F4FULL;
    std::uint64_t aWandererH = 0xECDFE57676796310ULL;
    std::uint64_t aWandererI = 0x9A9C0413D37F6CCDULL;
    std::uint64_t aWandererJ = 0x858AF8D48143F688ULL;
    std::uint64_t aWandererK = 0xD3D9EEAC84EE519DULL;

    //
    // KeyRotate A
    //
    aPrevious = 0xD8960EB2A71EF28CULL;
    aIngress = 0x9B824E05E3E640C4ULL;
    aCarry = 0xD5CC9E29EF678BB6ULL;
    aWandererA = 0xAB865186F4995D94ULL;
    aWandererB = 0x9688FA61C0FEFF13ULL;
    aWandererC = 0xDF33C86F38B2224CULL;
    aWandererD = 0xBC4505D21ADC1F1CULL;
    aWandererE = 0xEE3A4C250EC44102ULL;
    aWandererF = 0xBF5C6076CAEED392ULL;
    aWandererG = 0xA000425CDBA62959ULL;
    aWandererH = 0xBD933AFBB35E9F83ULL;
    aWandererI = 0x84DC4BA879D898C4ULL;
    aWandererJ = 0xB3C63EF68584BEDDULL;
    aWandererK = 0xA0C16290914EC3EDULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateAConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeyRotateAConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateAConstants), &(pWorkSpace->mDomainBundle.mKeyRotateASalts), pSnowLaneB, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0x880AF93AE0879AF6ULL;
    aIngress = 0xE6E2B702EA2200BFULL;
    aCarry = 0x8E88078B45E5E8D9ULL;
    aWandererA = 0xCFFDD7B796FBB1C7ULL;
    aWandererB = 0xA84BD568B63F016EULL;
    aWandererC = 0xC64762F377C0177DULL;
    aWandererD = 0x97D160DB9A60CDBCULL;
    aWandererE = 0xC50E5806F5FAAC91ULL;
    aWandererF = 0xFC4A58C281A3AEE2ULL;
    aWandererG = 0x947C72E2CD8B7035ULL;
    aWandererH = 0x8803E01E025B4AA2ULL;
    aWandererI = 0xC36D9BEC429317AAULL;
    aWandererJ = 0xA33B23843FBEDA07ULL;
    aWandererK = 0xA06A47867996131DULL;
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants), &(pWorkSpace->mDomainBundle.mKeyRotateBSalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xC305CF3095FAFF9BULL;
    aIngress = 0xF32B5F09E474B670ULL;
    aCarry = 0x9B6EB8D445B566E4ULL;
    aWandererA = 0xDB2038D5F0FDC829ULL;
    aWandererB = 0xDFD0ECA23FC52C6CULL;
    aWandererC = 0xBCBB69717E51920DULL;
    aWandererD = 0xBFC45D0C24716565ULL;
    aWandererE = 0x81EAC9BB334FD6C2ULL;
    aWandererF = 0x91925B0026D8EE1FULL;
    aWandererG = 0xA8DEA45E5C95F53AULL;
    aWandererH = 0xE88BE411BB26EDAEULL;
    aWandererI = 0x8202CBC22DA208D6ULL;
    aWandererJ = 0xC515E8C27252E3A9ULL;
    aWandererK = 0x9992B1FDE4E05407ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnAConstants), &(mDomainBundleInbuilt.mKeySpawnASalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xD9E3484C84D204F0ULL;
    aIngress = 0xF1277390CDA69BA0ULL;
    aCarry = 0xE8CEF05BA97DC4EDULL;
    aWandererA = 0xA503CB9A46A94291ULL;
    aWandererB = 0xF8449630209B0556ULL;
    aWandererC = 0xE2DE578CDD774881ULL;
    aWandererD = 0x98EF8AE81C52B937ULL;
    aWandererE = 0xCDED21A36C7D3473ULL;
    aWandererF = 0xA72A7118BDDE1B89ULL;
    aWandererG = 0xA57532D8EE2841D3ULL;
    aWandererH = 0xAA04AEB955096D34ULL;
    aWandererI = 0xDDEDD932EF980D66ULL;
    aWandererJ = 0xD33F411BA1101B35ULL;
    aWandererK = 0x8B550DAC6C8E6150ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnBConstants), &(mDomainBundleInbuilt.mKeySpawnBSalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants), &(pWorkSpace->mDomainBundle.mKeySpawnBSalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xBAAE6D5D4AFA6F60ULL;
    aIngress = 0xC5FCBC19530B56A4ULL;
    aCarry = 0xC4CD2131C884E8A9ULL;
    aWandererA = 0xB765ABCEC92D0B18ULL;
    aWandererB = 0xD4538B6BACBFD298ULL;
    aWandererC = 0xD1306AF8FB17BAF6ULL;
    aWandererD = 0xCCD4FCE3F9B59264ULL;
    aWandererE = 0x965479708BAA5644ULL;
    aWandererF = 0xDB7C99227257EA0EULL;
    aWandererG = 0xC6138F85F6B436A5ULL;
    aWandererH = 0xD8D50514D501B6BCULL;
    aWandererI = 0xDBDA032ECC2D06F0ULL;
    aWandererJ = 0xF6D8D68DE5FE35D5ULL;
    aWandererK = 0xAF69BA25B891A2ACULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xA0039314017A73E6ULL;
    aIngress = 0x8DD0AF35458862D6ULL;
    aCarry = 0xF8D03DE8D3AA657DULL;
    aWandererA = 0xAA4DD0F71BD8491FULL;
    aWandererB = 0x80A6832A40958F7AULL;
    aWandererC = 0xE82688C31B6F7610ULL;
    aWandererD = 0xE75E98860249CC75ULL;
    aWandererE = 0x9327A2DE3280A8FFULL;
    aWandererF = 0xC427E92037EE52F4ULL;
    aWandererG = 0xD63E4C29D65C8A8AULL;
    aWandererH = 0xCB416847D02B6CE7ULL;
    aWandererI = 0xEE14C69D613BF595ULL;
    aWandererJ = 0x89A3A6604831C5D1ULL;
    aWandererK = 0xB42828D2699318FBULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mSeedConstants), &(pWorkSpace->mDomainBundle.mSeedSalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xE38B0BF1BFD38F01ULL;
    aIngress = 0xB6B87B0F0099A86CULL;
    aCarry = 0xCE771B7C34A79977ULL;
    aWandererA = 0x98094474E328D3EDULL;
    aWandererB = 0xA965B751C1F52EBCULL;
    aWandererC = 0x87E679B016AB26EEULL;
    aWandererD = 0xF3FC41770CE4B894ULL;
    aWandererE = 0x9263B7EA5EA94F60ULL;
    aWandererF = 0xF46BB4712871A637ULL;
    aWandererG = 0xAFA34248FFBFB4BBULL;
    aWandererH = 0xD14BA7625E0B3BF6ULL;
    aWandererI = 0x844844690E2EBCA4ULL;
    aWandererJ = 0xC9A22D0E30DB25D5ULL;
    aWandererK = 0xCCF44267BECD60A0ULL;
    //
    TwistExpander_Alioth_Arx::SEED_A(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alioth_Arx::SEED_B(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alioth_Arx::SEED_C(pWorkSpace,
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
    TwistExpander_Alioth_Arx::SEED_D(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alioth_Arx::SEED_E(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alioth_Arx::SEED_F(pWorkSpace,
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
    TwistExpander_Alioth_Arx::SEED_G(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alioth_Arx::SEED_H(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alioth_Arx::SEED_I(pWorkSpace,
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
    TwistExpander_Alioth_Arx::SEED_J(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alioth_Arx::SEED_K(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alioth_Arx::SEED_L(pWorkSpace,
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
    TwistExpander_Alioth_Arx::SEED_M(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alioth_Arx::SEED_N(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Alioth_Arx::KEY_A_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alioth_Arx::KEY_A_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alioth_Arx::KEY_A_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alioth_Arx::KEY_A_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alioth_Arx::KEY_A_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alioth_Arx::KEY_A_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alioth_Arx::KEY_A_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alioth_Arx::KEY_A_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alioth_Arx::KEY_B_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alioth_Arx::KEY_B_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alioth_Arx::KEY_B_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alioth_Arx::KEY_B_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alioth_Arx::KEY_B_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alioth_Arx::KEY_B_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alioth_Arx::KEY_B_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alioth_Arx::KEY_B_H(pWorkSpace,
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

void TwistExpander_Alioth::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x856D1DA025FD8377ULL; std::uint64_t aIngress = 0xDFB2DF344B661EC8ULL; std::uint64_t aCarry = 0xEEB727F5CCB98BCBULL;

    std::uint64_t aWandererA = 0x94E8E878FC06F10AULL; std::uint64_t aWandererB = 0xCAB80F5661202A12ULL; std::uint64_t aWandererC = 0xFFA3989EB167E7C9ULL; std::uint64_t aWandererD = 0xC4F252CED3FC4B2FULL;
    std::uint64_t aWandererE = 0xB46E4A224D0A386FULL; std::uint64_t aWandererF = 0xB7A966648377BA80ULL; std::uint64_t aWandererG = 0xC217D83B5924569EULL; std::uint64_t aWandererH = 0xCD2E379BA55BFF43ULL;
    std::uint64_t aWandererI = 0x85B7AE23C53E214AULL; std::uint64_t aWandererJ = 0xA982283474047844ULL; std::uint64_t aWandererK = 0xA06296A10B0475BFULL;

    // [twist]
        aPrevious = 0xDA81AD2765527CFCULL;
        aCarry = 0x8E25FD0107B3CED9ULL;
        aWandererA = 0xCA538F95BCA7D965ULL;
        aWandererB = 0xA4DA5971AA47E93EULL;
        aWandererC = 0xFCE7053E7465F123ULL;
        aWandererD = 0xEBC877B84D3738F1ULL;
        aWandererE = 0xC45C06A980F81988ULL;
        aWandererF = 0x9D841908F971EDEFULL;
        aWandererG = 0xB96B6C56FB2C1A92ULL;
        aWandererH = 0xA558063BFF06C6CBULL;
        aWandererI = 0x96F42BF703493940ULL;
        aWandererJ = 0x9CEACAA3B16B9AA9ULL;
        aWandererK = 0xAD97B1AAB2F60DDBULL;
    TwistExpander_Alioth_Arx::TWIST_A(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alioth_Arx::TWIST_B(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alioth_Arx::TWIST_C(pWorkSpace,
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
    TwistExpander_Alioth_Arx::TWIST_D(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alioth_Arx::TWIST_E(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alioth_Arx::TWIST_F(pWorkSpace,
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
    TwistExpander_Alioth_Arx::TWIST_G(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alioth_Arx::TWIST_H(pWorkSpace,
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

void TwistExpander_Alioth::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Alioth_Arx::GROW_A_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Alioth_Arx::GROW_A_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Alioth_Arx::GROW_A_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Alioth_Arx::GROW_A_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Alioth::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Alioth_Arx::GROW_B_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Alioth_Arx::GROW_B_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Alioth_Arx::GROW_B_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Alioth_Arx::GROW_B_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Alioth::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 4 of 33
    // Exploration cases: 0
    // Structural maximin 581 / 674; family total 1748
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
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8149U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7789U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3828U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3648U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1420U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1645U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1465U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1600U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1960U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1735U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1330U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1825U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 4 of 33
    // Exploration cases: 0
    // Structural maximin 586 / 674; family total 1789
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
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7429U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6979U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3468U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7249U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 880U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 970U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 520U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 610U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1060U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 475U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1015U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1240U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 925U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Alioth::kKeyRotateASalts = {
    {
        {
            0x98EBC019B6EF0972ULL, 0xE669C06E03CB1FE9ULL, 0x1B2859EC6004E205ULL, 0x4E5F213E869F694CULL, 
            0x0A66BB6A333E3568ULL, 0x7B6C5FEB6E13FC0CULL, 0x5EE2384F00459334ULL, 0xB07C650795C38DA4ULL, 
            0xF87BA42B88CFD9BAULL, 0xF2DD8AAB2BD1064AULL, 0xEAA05A81EF09CE3EULL, 0xB8C2801C4B787AB5ULL, 
            0xFD513C2841AF8AEAULL, 0xC78EC1467A77A4D6ULL, 0xAC3EADF9E9EAF389ULL, 0xA6C193AB11524B08ULL, 
            0xCA876720E72DC9A1ULL, 0x73EBD5E48F2A7299ULL, 0x37423ED52AF1364CULL, 0xF9824DA8838FE3D2ULL, 
            0xBED47284B1DB0A8AULL, 0x30578EA064F83EB5ULL, 0x8F1D60D9ACAFF178ULL, 0xD89F3EC4B4F6B007ULL, 
            0x45525E63E34D1CCFULL, 0xED0FA35758E5ED9EULL, 0x1E9DEEB4A3207D66ULL, 0xDC1756E28214E183ULL, 
            0xAF6A1C26D37625B8ULL, 0xAC152361B2330EEBULL, 0xBD364F79DF20BBB4ULL, 0xBFA5122CBB416EA1ULL
        },
        {
            0x5FA483E5DC09279EULL, 0x69DC07635F96DBA2ULL, 0x14D9792B0F45E8BBULL, 0xA262DDF98D7B0D34ULL, 
            0x37CE30BC15A34E5BULL, 0x55C2FC84B72491CCULL, 0x6DC589C23B66AB36ULL, 0xCF9F7F4AB2F2BA4CULL, 
            0xF69383948A26EC7AULL, 0xC40CD8FB5DD1C0F6ULL, 0x5B35C2FCC17AC04EULL, 0x8B9A2E47AA117B14ULL, 
            0x6F7561870D224373ULL, 0xAA46B4EB7C11AD0BULL, 0xE340C272AECC9345ULL, 0xFBBEA9C55FFD541AULL, 
            0x2B97CFCCCA0067CEULL, 0xE3791BC805347662ULL, 0x2B3CE3FAAADE9498ULL, 0x5715B9CAD14AACA8ULL, 
            0x603A28DBEF4AB624ULL, 0x5980D0A377EE5620ULL, 0xB3167BD3495BC99CULL, 0x0D16C67E728C2C35ULL, 
            0x3EF56AD10771DC79ULL, 0x25AFB78DA6FDDC65ULL, 0x137D9436DA5B2FBBULL, 0xF82EE2BC734FA9BDULL, 
            0x62A2A4928E949EBEULL, 0xD5ACFF8C84CA66DDULL, 0x6DA73A2153A8F454ULL, 0x0853EE58AD3067E0ULL
        },
        {
            0x8638E9BF00200E98ULL, 0xFDA767D011FEF32AULL, 0x242619FD3E323BA2ULL, 0x8DF40E610D5BB87BULL, 
            0x5EBE700258793641ULL, 0xD4D2623763C193CFULL, 0x1FFFA73CC34FC83EULL, 0xF89517578191FBFBULL, 
            0x3E22A02C96E2630AULL, 0x7B30C263632D2535ULL, 0x47CFB083262D9116ULL, 0xA68B4A6A2D98E433ULL, 
            0x2DA10AC97E8D3F51ULL, 0x9391D4E44ED2D75DULL, 0xA80DCC94A400A871ULL, 0x7A80BB2A03278942ULL, 
            0x649E9ED9C8F59E7AULL, 0xA161EB7EADE53D20ULL, 0x64E1ACCBE25250D1ULL, 0x5F322F4D03934D7DULL, 
            0xC6E7327D5728E847ULL, 0xF29DC06ECA443F56ULL, 0x2AF3055792E9BA72ULL, 0x5F85789DF79B04C4ULL, 
            0x1A2B2F5846D0D9B9ULL, 0x4766B8A0715C4B33ULL, 0xEA4FD74BE75CAECFULL, 0x8A6CAD16CA614E00ULL, 
            0x1B0BA41FB9872280ULL, 0xC09BA20E1577E478ULL, 0xF11A06DC6FF61E54ULL, 0x794D0A4726D21FC3ULL
        },
        {
            0xFB4FF374741B0AD9ULL, 0x361AB592A525106BULL, 0x11CF19FF1D5E9AC9ULL, 0x7FD3CF88B70500A9ULL, 
            0x964378A17A9F1B3AULL, 0x4E16B66685A3A37CULL, 0x18F09BBFCEBC8898ULL, 0x7D9FE29A6E49AA3FULL, 
            0xEE4AB233F1F5A419ULL, 0xCB28FFF13D906F38ULL, 0xD11787813DE1AA5FULL, 0x8002D4B8213FE64EULL, 
            0xC05AAEE937C45490ULL, 0xC9DCDC2F112FFF27ULL, 0xF0C74049AD074990ULL, 0xADDD2E26BC1E561FULL, 
            0xD9274DB3EBB01493ULL, 0xA114446DF6A508ACULL, 0x38CFEA655E33F992ULL, 0xDD2D115051B64D0DULL, 
            0x935B22ED63FE1D18ULL, 0x3ED373374CCBCA31ULL, 0x95FF577E5847C1B3ULL, 0xC4A888317DBD11A1ULL, 
            0x73680B8E27552A1BULL, 0xE3559F7C36BABCB8ULL, 0xC170589B48B34FEEULL, 0x9033F7DDC536312DULL, 
            0xEA907D869DB1A477ULL, 0x3CDC4CCDA0476A74ULL, 0x48AA16AB50764B70ULL, 0x51AA77DCB0016187ULL
        },
        {
            0x7E18A6B8CD9E6378ULL, 0x9DC9D7D05D7DA08FULL, 0x2B7336BB7D061511ULL, 0x3DD415AEBE0DC6E4ULL, 
            0xFF259CEEC73F6CFCULL, 0xCA45A761C44787D5ULL, 0xB928130E61532F25ULL, 0xCFF5A6A5F741D434ULL, 
            0x795338AC42AEB4F2ULL, 0xA745241243B7DA94ULL, 0x64F8540A1C919D00ULL, 0xD50B74051842CA8FULL, 
            0xB235990D45F2EA3BULL, 0xA371DA5E17214121ULL, 0x3AB1A587FD4819CDULL, 0xFAD02A433C581AEDULL, 
            0xBD20A59566ECE595ULL, 0x40055A340ACFECB2ULL, 0x21B4FD6D7BAB42B0ULL, 0x4BFDB4924A5809E1ULL, 
            0x4BFDD1CF45A2CDCBULL, 0x989F13BEA727CCD2ULL, 0x37E6FC04D5A2615DULL, 0x97AEFE9C7520C24BULL, 
            0x6CB84C6FE7D0F074ULL, 0x352D8F7BFAB07F06ULL, 0x13242610D42FC784ULL, 0x010394D4E3CEA2D6ULL, 
            0x52B1598659B0C7F1ULL, 0xE137D0A4F1C77EE8ULL, 0x66E91637A180A57BULL, 0x51A4D8609681EA49ULL
        },
        {
            0x2BC99428FE2DABDBULL, 0x2B76F05DCDEBEA88ULL, 0x776CB95F09BEB3D2ULL, 0x79F9C6D336ACFF6CULL, 
            0x17C6DE0012C47D62ULL, 0xBD4BF8F5BEC66ACAULL, 0x137B9EEB64A92F4CULL, 0x8CB0E256E18BC5C7ULL, 
            0x77F915BDC151D87CULL, 0xCE92282683216789ULL, 0xA1B30A0258A72AF7ULL, 0xA31A15A69DFCB457ULL, 
            0x7A4AF66B4CB39934ULL, 0xDD0D0D91634C5C7AULL, 0xCAD819BD46616DDEULL, 0x2B672B04D36C701BULL, 
            0x991C8FC8AEE81CD5ULL, 0xE5E7EAA4F446869CULL, 0xDAA8B98D5F86331FULL, 0xB2F7AE0F596B4BD5ULL, 
            0x459D37AA7F22DF8EULL, 0xD0C2CFCC71D9BB33ULL, 0x401002AB820E37FDULL, 0xE7F6E172507659E1ULL, 
            0x99AEA4E76D729528ULL, 0xA656A9B8C12AFDEBULL, 0xB681ACF324FC3C6BULL, 0x706E1AE978D3DE6DULL, 
            0x0E5E2A98E5BC2588ULL, 0x7693B080A26A2E29ULL, 0x96CEEFA74DAEEF0CULL, 0x357964AE5CCAC2F4ULL
        }
    },
    {
        {
            0x120C1E6534B1FFFAULL, 0xB94E5CB3843B0D45ULL, 0x9860BF009E2F981DULL, 0xAEEFAA6C06CE2B10ULL, 
            0x55A8A0C2790B910FULL, 0x3CC9B9E6D2F45948ULL, 0xEA5D274D8BD8A111ULL, 0x721B9CBD2254055FULL, 
            0x898E1A30405D9F3CULL, 0x9886E8AD3B86525EULL, 0x8D3BF13BC952AF14ULL, 0xD8D23D8A97FA2F6DULL, 
            0xCE6662D58C752349ULL, 0x659783A794EB094CULL, 0xDC36029E1134DCE4ULL, 0x8A255450F0BF2D50ULL, 
            0x661C9F815549C2EBULL, 0x21BD067DD4517F1DULL, 0x5ED49F24BB866FCFULL, 0x40C5F54D2E026B37ULL, 
            0x3AD95E95F73C91A9ULL, 0x3B6AD65A0615B0D5ULL, 0x844B86D8E5546D1AULL, 0xB26674D74C9C1F1CULL, 
            0x015BFC29219C6F58ULL, 0x2B2E82F3A9A69AF2ULL, 0x0B70DE06D418C67CULL, 0x2134CF9866E97B5DULL, 
            0x1F3FE79A324FBC1DULL, 0x76AE45D5301DFFB1ULL, 0x4315B054DDBB7142ULL, 0xF45AE8E81D5F94B9ULL
        },
        {
            0xE5861C07EF0780F1ULL, 0xFB29893BB66F2149ULL, 0x7AA9B904D1DD4CA4ULL, 0x05C45E4D3A5B0D63ULL, 
            0xDE590FCBED6F1303ULL, 0x10188570018492CFULL, 0x47AD43FB7BE9492FULL, 0x8252048670F563EBULL, 
            0x2ED61EB85B5914C6ULL, 0xED91BD35EB786A6DULL, 0xE253FFE8BECE848EULL, 0x699526820A8C9558ULL, 
            0xA1C62573B05C728DULL, 0x4777B3183F290429ULL, 0x3827DBD9F8C5C6AEULL, 0x4667CFFD0FBB370AULL, 
            0x7241F1821CB33332ULL, 0x79D97FB04CC6264EULL, 0x6470800EDC147A7FULL, 0xE9D6FD3281A22EBAULL, 
            0xEE5829CF66C899EEULL, 0xECCDEEC8FB20EC5BULL, 0xD2E75D1774FE448CULL, 0xAA0AA5808AF5AB13ULL, 
            0xC59229D79A2A0199ULL, 0x8A164FC179680CBCULL, 0xCD2B974F5E765C2AULL, 0x4042BE0806F32666ULL, 
            0xE319C8121483E3F2ULL, 0x965F1D83C363F53AULL, 0x28FF5D25A6124896ULL, 0x43200CC441EB851EULL
        },
        {
            0xC2AF2EF044B3DA02ULL, 0x3AFFECDFE7F66B20ULL, 0xB589FCA2CF8CC910ULL, 0xCAB128D1F6A8D6B9ULL, 
            0xB8F62FE30BE0CA88ULL, 0x1AB9AA64C3705C83ULL, 0xE35539D619852095ULL, 0xAB05994020A3A5A4ULL, 
            0xB020F34BBD4C9C3EULL, 0x62BF94A761D724AFULL, 0x5BA19D6B57614FC0ULL, 0x9A04882CC8E24DFAULL, 
            0xAE3C6708B8EEBE70ULL, 0xC23A3B26A2842E9CULL, 0xD8C0F843845125EAULL, 0x3BAB65DC02F74372ULL, 
            0x9AC3924674FED1AAULL, 0x60B28E38ED3EDBB6ULL, 0x6BB63D452AEF6071ULL, 0x2654239EF7638C89ULL, 
            0xBEAF6CC0BF6E6BB4ULL, 0xED2142326EC0A599ULL, 0x67623C858CC77436ULL, 0x900DA0AB2373E503ULL, 
            0xDC2886516ED959B4ULL, 0xD4C799DC1946F144ULL, 0x520F860273E6BC3CULL, 0xF8ECA273E8FBA0D4ULL, 
            0xA97DEA4781897FB6ULL, 0xF873C3C07A5E8D0DULL, 0x87437FAE938172C7ULL, 0x02AD560D43E548E3ULL
        },
        {
            0x0C7869C1E9C6FAFAULL, 0xAEEF8FAAFF95C1CEULL, 0x8683EEF32AB98007ULL, 0xC7C7824F5E930E72ULL, 
            0x48E48C9BC22A6135ULL, 0x18127383D0B1FFC7ULL, 0x29E92CEA4765D00CULL, 0x9C2A1F8F88E9975AULL, 
            0xB4366185B8E2CB02ULL, 0xBE0F51993CD9D98BULL, 0xC999BFBB961C6276ULL, 0x3D54842CC31F4D76ULL, 
            0x0D4ADBA5B97AE79BULL, 0x0A57636B5DD9FD21ULL, 0x04EC52ACB65E28FFULL, 0x9D7EECE3A53C2331ULL, 
            0xD3177EE860E630B1ULL, 0x114FE6FCC24454A1ULL, 0x2E7681D7D22128A9ULL, 0xF435112274459E53ULL, 
            0x1DFE3922ADD17A0FULL, 0x8E86DEDB396C88BDULL, 0xAE3330371B770630ULL, 0x32B032F3416D40C1ULL, 
            0x20F598B402EDD514ULL, 0x897F2EADF51DC65AULL, 0xE5438D3F7DD91B5DULL, 0x348C424D612A9EA6ULL, 
            0xFA76925F0C6BC288ULL, 0x90A9DAEC56DB654FULL, 0x00CFDEA877A843DCULL, 0x95904B7E8CD16AD3ULL
        },
        {
            0xE04EF48D00563B52ULL, 0x3E6FAA2BBE62E511ULL, 0xE90FC88D9617A21DULL, 0x24F66821F4A644BEULL, 
            0xAE9A29FEF43C9512ULL, 0x01A650E871388D71ULL, 0x9C7B75C8E3397458ULL, 0xD78E86EB7FD40472ULL, 
            0x9CFA0B63451FB15DULL, 0xA81C07961D5C3577ULL, 0xCB39EAB5F6452D1FULL, 0xFEAF06E91F69FC19ULL, 
            0x6CA651FDC2B7545BULL, 0x4B5E23969B4AF5B0ULL, 0x96A4A67EA98420C9ULL, 0x8DD130AA58F106F3ULL, 
            0xC2FAD041A8395B93ULL, 0x603CB9FA316D44D2ULL, 0x2378CCD693CC3DE3ULL, 0x44DADCF133F610C8ULL, 
            0x3B79EA5048FF9D59ULL, 0xACBC4DF0B7424F43ULL, 0x0A2577A04E1D6791ULL, 0x7320FF11B95219F4ULL, 
            0x5D3886D1A238F41EULL, 0x2B8E2D3498DA7029ULL, 0xA2E328678AE30009ULL, 0x0092943E9ED27F3FULL, 
            0x9D6FA9DC5B3955B4ULL, 0xA3A9D2672C393983ULL, 0x1163F1541C726435ULL, 0x2F977DACA8DDCBA6ULL
        },
        {
            0x486F9A3001EA1C0FULL, 0xD5D31DD0FF55F0EFULL, 0xD38ECC1DF71EE6F1ULL, 0x9622BC110D6F12D4ULL, 
            0xA468EF64F73A048EULL, 0xF94AC8CB6BD88D71ULL, 0xF8F234988EF90F07ULL, 0x403259CAFADE1D9DULL, 
            0x619383FC6BFF436AULL, 0xAB40F214CE83772FULL, 0x78D4D635C8618672ULL, 0xEDB0FF7D15A4EA3BULL, 
            0xFEE8169CC22D2A57ULL, 0xA62B47F33D35C2CAULL, 0xC22C52DA410CD403ULL, 0xBB685C1AC8A2420BULL, 
            0x59C27E0B3037F477ULL, 0x25CDA1E62F2BE6F2ULL, 0x0F31196AEB24BB6BULL, 0x123A938DD497AD5AULL, 
            0xC6788B2CCEDCAA94ULL, 0xB00D25FAAF472682ULL, 0x238271081F586FABULL, 0x74DC57E7724C6036ULL, 
            0xF761117DAEF176ABULL, 0x8D7549B4EDD4914AULL, 0x7719DF53E59BE78CULL, 0x193399874D8901D0ULL, 
            0x3A5864D7D1C77C06ULL, 0xFE3B593DA0AC9242ULL, 0x3B0317D78098E94AULL, 0x212E7FC2835A48D8ULL
        }
    },
    {
        {
            0xA6FBA845494E4EC1ULL, 0xCA6196D9D05ADD48ULL, 0xAD12F1880A14A1D8ULL, 0x621DE688E3D2F55EULL, 
            0x90801A41F9D3F23EULL, 0xAE7D745B5A6CB154ULL, 0x0BF56CB6D04C6CF9ULL, 0xFDDDAE65F8F48085ULL, 
            0x298BCA23408C0027ULL, 0xAECF070FFB393A61ULL, 0xCAC7E7A40605E9B6ULL, 0x14F3A5211BFAD8A3ULL, 
            0x8F5E70DB8FDFAD73ULL, 0x0AB3DA9C25D6FC68ULL, 0x631507B4B4C42C6FULL, 0x937B2D34FBDCCA0EULL, 
            0xADFA84013B874517ULL, 0x09BB25A377AA3170ULL, 0xF53AD2AA23002517ULL, 0x7DF5AB6A2D15D6D0ULL, 
            0x7F1400FF407783D2ULL, 0x90DA9DE0DA679948ULL, 0x498621DA187523C9ULL, 0x11B206B7832A1F80ULL, 
            0xA61461E03825BA1DULL, 0xEE2B4A5937F57938ULL, 0x39460B2FB640DBFFULL, 0x510E9C12D5393EFAULL, 
            0xEB170B555366A9DEULL, 0x4CA9A92D91D5E6AEULL, 0x928728F0EC20EB37ULL, 0xEEC61F8B8888247DULL
        },
        {
            0x53EB1BC04B5C45DDULL, 0xA3D550D292C8BB96ULL, 0x1C96DAFD37E12E6FULL, 0x08844D629DEDA8DCULL, 
            0x962CE8274B1E0BA3ULL, 0xC764E23F0EB00728ULL, 0xB87275D32CABFA85ULL, 0x1A9D4ECEC957DC66ULL, 
            0x6F8366AD0CD45B21ULL, 0x4E67452B87ABAD57ULL, 0xD82C4A7B6D4255A6ULL, 0x033F36FB6DFAAD04ULL, 
            0x61F77BD00C915BD0ULL, 0x7B26CD4D05682FD8ULL, 0xD71A5246ECB07993ULL, 0xD8A2221743C148FCULL, 
            0x1F09C77F1C29EE58ULL, 0xF5E7464C0C3D615BULL, 0x3676726AAEF79683ULL, 0x7637FF1E2F927C87ULL, 
            0x7525B62FB0A4D9D7ULL, 0xDF23FC3B7B9F3C64ULL, 0x3104DC334D85872EULL, 0x9EC825DD8BAA467EULL, 
            0xFF27BB57A969CD07ULL, 0xA2FB3421047DECDFULL, 0x831CDD21EBC89DC3ULL, 0xEAD1ACA132D40220ULL, 
            0x77BFE3812DFF893FULL, 0x2F2820973CE22A71ULL, 0x77A97F52077F1D1BULL, 0xECFC6A869CE72D41ULL
        },
        {
            0x03D44B097B6BBE4EULL, 0xF577163B830FCE16ULL, 0x111C3656AA934D8EULL, 0xA5C7B2A72B49CC1EULL, 
            0x56E9B38D9AF51923ULL, 0x473CF8B5ADB57B33ULL, 0x502AFABAE03C7DD0ULL, 0xCF6F9C33E0AC91EFULL, 
            0xD88AF64D8E2120E2ULL, 0xDBD86537CAF36CE8ULL, 0x457F85222B711808ULL, 0xB05D74049B6B2056ULL, 
            0xB5CDA74EA715FE81ULL, 0xFC703F7696F813F0ULL, 0x7135CE819788F176ULL, 0xE726B11279E5C98EULL, 
            0xA77A45460958C0FFULL, 0x42E6B4C1EDDA5F49ULL, 0x25207070206E4F7BULL, 0xB47038632D08EEB5ULL, 
            0x8BD1CF4EDF150CF2ULL, 0x9B896C0A181B0310ULL, 0xC8739DAD8B558956ULL, 0xCA4AE938ED3ECDA3ULL, 
            0x81974DCEBDC80C4FULL, 0xECDB03E2FBD54606ULL, 0x385027A63B7F825AULL, 0xA49501256AF3AF83ULL, 
            0x2ECCC01BCC096664ULL, 0x3662679FBA55EC75ULL, 0x647FA60AB54CF82EULL, 0x553F3E31926E5A05ULL
        },
        {
            0xC474469ECBBD13D7ULL, 0x8AAB5C0C02DA014CULL, 0x8F702DD3D4C6DA71ULL, 0x16B787143AE7F50BULL, 
            0xA23F48CAFE39E602ULL, 0xF79BEB265C091E25ULL, 0xB52BE096D5B3ACD5ULL, 0xC13C7E4F886A4A52ULL, 
            0xCA88F8810C6AA207ULL, 0x164494DC78D20D3EULL, 0xBD1C988D0C5AA091ULL, 0x6E0FF773AF042AF7ULL, 
            0xD4E4793F4EBA522CULL, 0x49FE11FAB566A7B6ULL, 0x8875D4B4A22D349DULL, 0x3644F67DE9C19BFDULL, 
            0x8CD1097F4A0B7129ULL, 0x7458D31A88E3357CULL, 0x3BC0314931520FA7ULL, 0x606854FAE2CB3667ULL, 
            0x233935A3816AEC66ULL, 0xF26E3CC967E6AC03ULL, 0xECDEE2A036A5298DULL, 0xC0A058A4BAA6D646ULL, 
            0x3AED09B2CF7D8869ULL, 0x2E552C1BA29B9716ULL, 0x5C8164EC65BA9AAAULL, 0x3A4303180885F2FAULL, 
            0x98BFD7FD55339F5CULL, 0xA002FCF2CE71645EULL, 0x42A0A2F54170A407ULL, 0x5E3B4A9BA9AF87ADULL
        },
        {
            0x43F3D93546E16C17ULL, 0x0E56807CDD512C89ULL, 0x932410D0998EA66CULL, 0xA8DD6F1183BC8AA7ULL, 
            0x63149A3397DA3B84ULL, 0xB991FB13092052BEULL, 0xA039709FF4B7AA5FULL, 0x7042DD4A143066FAULL, 
            0xA0D18C9FA8D287FDULL, 0xC7E9E2893F19B264ULL, 0x0B59062D33C7E6C3ULL, 0xF36E0EBE414212E0ULL, 
            0xA2A7C6434E61A1DDULL, 0xC6A9168C04A23467ULL, 0xE3B0FC1A4DCB7B3BULL, 0x8DC6BF6EDE9856DCULL, 
            0x6EEC85B1DCBF2010ULL, 0x61B1CCBE3C52A8C9ULL, 0x112954C98DFA5F77ULL, 0x778D346DC3246BC4ULL, 
            0xDFCB706001105FDFULL, 0x1BCEBBB807FC911EULL, 0x850D709E7C8235D9ULL, 0x78723073AC5E9777ULL, 
            0x209EB7F36D7BA398ULL, 0xCB0985CBEF5C0096ULL, 0x5B4D7D118A4AD675ULL, 0xA80EE631C845B52EULL, 
            0xE2F0B5664CE1AF72ULL, 0x76CE3849F1A640C9ULL, 0xB9358124B1CCF819ULL, 0x60FDC3DE1E43070BULL
        },
        {
            0xEEE3784FED94160CULL, 0x7CE41D5A89319724ULL, 0xEC6BD26FBBA7B5B6ULL, 0x4889317DC7049F3DULL, 
            0x0A0333E6AF8EC6E0ULL, 0xEC7823A3E991C653ULL, 0x78C80FA0EF9E5907ULL, 0x656B97328566F8DDULL, 
            0x4B0ED4376712920DULL, 0xDBD5A10189BD0EDCULL, 0x4FCC85A4471F3799ULL, 0xD9A9604E752237A9ULL, 
            0x1E4CCEB5FB2F0368ULL, 0x61EA7C79FAD20B71ULL, 0x6E61260B192EB399ULL, 0xBA72387979E84085ULL, 
            0x6E8F1FA960D298F3ULL, 0xC018F76E2CC5C687ULL, 0xC6D40BD59F68C3C2ULL, 0x04D582B4E4CB6C79ULL, 
            0x8B9A2F24EA7AB0B8ULL, 0xEC13CA93986E2AE6ULL, 0x33AB338B2C5619B3ULL, 0x88E31ADC349D0019ULL, 
            0x6DFB0B45188EF8B3ULL, 0x2A4281BEE6AE05CEULL, 0xB71F3808875FA81DULL, 0x1E6E8117586AE15BULL, 
            0x1B076BBEB74499ADULL, 0x6DF51176402B7D37ULL, 0x46944CF713EEFC4DULL, 0xEE66226DF14E2C82ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alioth::kKeyRotateAConstants = {
    0xC4826A790EF3EE51ULL,
    0x2EA48F4946FA4232ULL,
    0x5F81F362EACA873CULL,
    0xC4826A790EF3EE51ULL,
    0x2EA48F4946FA4232ULL,
    0x5F81F362EACA873CULL,
    0xFB38470AA478590BULL,
    0x3B8337EA5D51AF55ULL,
    0x4A,
    0x75,
    0xEE,
    0x0E,
    0xCB,
    0x76,
    0xAB,
    0xC8
};

const TwistDomainSaltSet TwistExpander_Alioth::kKeyRotateBSalts = {
    {
        {
            0x8AC2197FD7A45098ULL, 0x88D70F53CD514BDFULL, 0xC0E31EB3AEED5FDCULL, 0xFC470F54316B2F73ULL, 
            0x8B334FE199B139EDULL, 0x15978AE89BBF88F8ULL, 0xDD3055C25223A2FFULL, 0x30B3008F161A4DBBULL, 
            0x58B53800ACBF48B0ULL, 0x820CC4EA7EDFB289ULL, 0x28D295AC106B0020ULL, 0xD99080754F6FE236ULL, 
            0x1FE0B716B1396DA5ULL, 0xA150448883BA297FULL, 0x9C43E7A12ACBF9F8ULL, 0x27DB1D85E64E9A5AULL, 
            0x42B1C69858D3ED59ULL, 0x9881709733B18AD6ULL, 0x28CAD4F137DE5330ULL, 0x3CB7469093569D7FULL, 
            0x75990E6DBDC2DE79ULL, 0x53ECFDE791C87FA1ULL, 0xC232E0EA9268F88EULL, 0x8FCBD681D4F2DDB5ULL, 
            0x3266168943C0543CULL, 0xFCB2A5AF865F52B6ULL, 0xFE23146F2C713FFDULL, 0x6C72EF38771D0B3EULL, 
            0xEA292AAB0CDB5C7EULL, 0xFD1FF6BB2C7536CFULL, 0x4A196CADE1F8F2A5ULL, 0xE505BE379D7A89BDULL
        },
        {
            0x800E072B423BBB3EULL, 0x44CFC52024D2A87AULL, 0xDD4D951A5DE14F6BULL, 0x63568C34962CE154ULL, 
            0x2B92BC7DBF039381ULL, 0xA715FB3AECE6F75BULL, 0xA251522610728B03ULL, 0x60BDC518EFDE97DAULL, 
            0xA97EEAC8F155B845ULL, 0x2124CC5F1A02491DULL, 0x9099B394757C73B1ULL, 0xD1F16A6F03AEFBDAULL, 
            0x7833034F4FEE3CD5ULL, 0x69BEC71546E4289EULL, 0xA3CD297F0D6699C4ULL, 0x1B6DEE2CEC8F19DDULL, 
            0x77FA118756AD4085ULL, 0x8D6BECFE3D8B5A71ULL, 0xA017D8BD85A4BEC6ULL, 0x11E751CE0D27E692ULL, 
            0x172FF9D784C5A023ULL, 0xC67F21E1F7B1A066ULL, 0xFDAAEE79759A577FULL, 0x0D8A3A53C2B815B3ULL, 
            0x25407125C9537CDBULL, 0x4B17DA8DFF2C997DULL, 0xC4F824B92C8ECE3FULL, 0x7656CFC5A2ECACCCULL, 
            0x13A163E318191575ULL, 0x2BF2F68A54ED8816ULL, 0x2B699758C6CC8E62ULL, 0x4EED9E8188D9A994ULL
        },
        {
            0x7C4F7CD65BEECF2CULL, 0xD9139736608C0DB3ULL, 0x607391ACBD2ECCFCULL, 0x6F9BF49DAA5803A3ULL, 
            0xC5BA46FBB112A68DULL, 0x584824747E2BC1C8ULL, 0x13B219280CA7A87CULL, 0xF05C38C78DAA90FCULL, 
            0x815C9FD065E8D83BULL, 0x47CBBC9DB4FD766BULL, 0x4CB9FD71F27B15DDULL, 0x95044CF8D77E5B04ULL, 
            0xA61E657BB511EC31ULL, 0xA1C26A59740578B8ULL, 0x511D1301E852193AULL, 0x7E65B9E92CB63AA9ULL, 
            0x2EE427ECB026305FULL, 0x536C76CB963F4D1DULL, 0x32992DB3E6F5ECD3ULL, 0x07D1FE3B6ED5B687ULL, 
            0xF00AA455C45C6CC2ULL, 0x1866E90BCE1AFF60ULL, 0x3E6721D318C8020EULL, 0x8AED8901AF76B637ULL, 
            0xEC7D6465452CEA3EULL, 0xD80626AD2515C914ULL, 0xE3D4FA53BBFB5A03ULL, 0xB43935EA35FABF56ULL, 
            0xCA3F240D57525925ULL, 0x93800888E5BA327FULL, 0xC09D1AA646398B58ULL, 0xE6232A4B98E4285CULL
        },
        {
            0x459855A52B7CDEA2ULL, 0xABC25AA971111998ULL, 0x53F28A8317FD3DD2ULL, 0x8C7945D65C01DA88ULL, 
            0xD6178D321AC8CC4CULL, 0xE99AA7D3A059C79AULL, 0x885A3EB566A94A6EULL, 0x201FED63FAAD45DAULL, 
            0x16071CA1ED57E387ULL, 0x98839943A205EBE3ULL, 0x9F1898380F479C1EULL, 0x0B18714045C71ABEULL, 
            0x583115A61F716F7DULL, 0xC66119A486B71A38ULL, 0xFEE92DB6ABAC7C06ULL, 0x32C0CFAD7F7941ACULL, 
            0xF74135E6CF77EF04ULL, 0x5F7CACEF120F1F6CULL, 0x5768BB74492CAA9CULL, 0xCBC3C9E6F5382088ULL, 
            0x643CC6032FBD0B58ULL, 0x28BA61BDBE0FB7D0ULL, 0x9D3C4783C14DC9C3ULL, 0x158EC374F57625F7ULL, 
            0x55C246270D6DCFC7ULL, 0xF2ECBE98C4BD809DULL, 0x6ABCC60CE7A3A9A1ULL, 0xA153B5423DED3F61ULL, 
            0x5B75FB57F5AA0A9AULL, 0xA9221D61B79A1341ULL, 0x2F2AA3A4211F0C51ULL, 0x70EC44BACEC1650EULL
        },
        {
            0xC7BA1159A9810369ULL, 0xE9308DEED9B94B0BULL, 0xD608F59FA33F81B1ULL, 0x9164C87DE4DE2E95ULL, 
            0x17329AD26F442BA7ULL, 0x3810AEB81C3953D9ULL, 0x47B537295CE9FF23ULL, 0xE49A83FD17CDE7FFULL, 
            0x2FE464CC67DCC4C3ULL, 0x8E250F8173128653ULL, 0xD21FEA98F085162AULL, 0x58B491ADA87975EEULL, 
            0x4DF29EA0AAE474C3ULL, 0x606B67002A4BB24EULL, 0x7CCCA37446527C29ULL, 0xEC0718758B4EE780ULL, 
            0x8A94FFE754F0976FULL, 0x155B67021442313FULL, 0x20B00E20D335AEB2ULL, 0xE795E37B76898F5AULL, 
            0xB3929DBAD6FBCAD9ULL, 0xFEEA24C7EF508C93ULL, 0x3E0C5725CEFBB350ULL, 0x84CE5B0BCFE8D751ULL, 
            0x9C2AAA6FEB975FA5ULL, 0xC36073C369585E40ULL, 0x396D221737E1512DULL, 0xD50FD4EBB3C98423ULL, 
            0x21C8970BA23A200CULL, 0x5A9F4D680A89F66FULL, 0xB55BF195923F200DULL, 0x604A896F53848F45ULL
        },
        {
            0x99E3DEF06C9DA3BFULL, 0xFE9796D59FEB59F0ULL, 0xA737B4F2256A2F5BULL, 0x275F8D538004E755ULL, 
            0x1D4CC6A99D299C71ULL, 0x6A576762A9F116FCULL, 0x5A69B4E93A9C4EBAULL, 0x08A11A141B06DDC0ULL, 
            0x20873C5B02BAF115ULL, 0xF0D74DC1A7063809ULL, 0xE779F89E0F530C6CULL, 0x6AC18131CB2ADF16ULL, 
            0x95B4019D99586BF0ULL, 0x15B920D65DAC4467ULL, 0x0C81CCEBC8536F35ULL, 0xF426195768D311AEULL, 
            0xC357DFFB788FB6F8ULL, 0x0ED6DB0F0A0164EBULL, 0x18E4D00E5808ABF6ULL, 0xCD76D19F79F87CEFULL, 
            0x1B6CCD9B2169B89CULL, 0x6404AE523A55EF08ULL, 0x05129177ACDB3A6AULL, 0x61E197E052D4E09FULL, 
            0x1800BFA3332970A8ULL, 0xEFD6A9038D92B33BULL, 0xFC6DE0F249850BF3ULL, 0x5D6C2BBBA5203929ULL, 
            0xA8F2A4BE8742154DULL, 0x7BF1CD45E28E8951ULL, 0x16F31F388D72B5AEULL, 0x091053E0AF144A6FULL
        }
    },
    {
        {
            0x620EC6870626BD43ULL, 0x759D9B5634765B53ULL, 0xCBCBE2AF65A7E027ULL, 0x203956176490049DULL, 
            0xBEEC5310B4A111ADULL, 0xE30FC163618E400FULL, 0x41816381CC159105ULL, 0x5F9028490420BB6DULL, 
            0x93C6E25017EBAF44ULL, 0x8BA92D1639696FA8ULL, 0xF3532094C04979DAULL, 0xC43C008D9D786420ULL, 
            0x2F2E04269FA7DC04ULL, 0x090C833E1D35CDA1ULL, 0x3653AE462DB1AB51ULL, 0xE58D6F72DC2F65E4ULL, 
            0x3A3A0C7F75EB3B88ULL, 0x593633660E41D08EULL, 0xC1EEBEBA81D8ACB7ULL, 0x0A93FDB630EA5FA7ULL, 
            0xFCB9EA2851AB1845ULL, 0x7571558E867EA862ULL, 0x34321B89C1948C86ULL, 0x3D9EF5FB35D24F9AULL, 
            0x382A0ADA015F2CFDULL, 0x3FC2E0B7F91CFC43ULL, 0x8CC3A7261724248DULL, 0x0384F8EFC54D8B6BULL, 
            0x635B0E505EA2AA92ULL, 0x0B89AAA1F1792D3DULL, 0x32BAB06FCABDB9A2ULL, 0x8F671B7679466A75ULL
        },
        {
            0x2F4F9B5EB6862FBDULL, 0x6581F768BEA9441DULL, 0xD14C4946271F5C40ULL, 0x9AD9BF2DB801325FULL, 
            0xAEBE30494FA7F0C9ULL, 0x0146600FD100788CULL, 0x60653881C7AF34F2ULL, 0x6950EFAEE664028BULL, 
            0x40BE3F3A1146BDF1ULL, 0x6299386E55698F34ULL, 0xC95FBE1AE799136CULL, 0xF00F0CF8EAB6D376ULL, 
            0xA8BDCE49D23CDBABULL, 0x9158BFBC9631EDB2ULL, 0xCDB0BCF9CEDF592FULL, 0x68F7B5B0EF502BD4ULL, 
            0x813BBBE0E8408EACULL, 0x67D7F4400D42B14CULL, 0x6F3DDD413273D6D7ULL, 0xD9E59426F7F95318ULL, 
            0x627C2079AB4FEFC3ULL, 0xAEDB1E2C7121F641ULL, 0x275F5CBB5E5F8AF3ULL, 0x36509E5F6171C86BULL, 
            0xB1708DB97149D1CFULL, 0xAB0210F1E97F7D89ULL, 0x445A6E137CF28A09ULL, 0xB6AF0057A9B1B56BULL, 
            0xB411E3BBE0A06D38ULL, 0x370EB6B58F82B3FFULL, 0x49D0EB6AB254DEFCULL, 0x97A7F46D060E183FULL
        },
        {
            0x6252D5B9D5982D8DULL, 0x6B9345C0DD79A54BULL, 0x26ECBE068C26506CULL, 0x0A0A080FF285CC41ULL, 
            0x2C5ED7C95EE2D7A1ULL, 0x817FFCA787ECE434ULL, 0x4348A7E96E5112B5ULL, 0x237C33A9CCE36E56ULL, 
            0x75C5C294434D70B3ULL, 0xFC5B6733AD8E29C1ULL, 0x2165D07B34E6218CULL, 0xF066747B865B61A0ULL, 
            0xAE15B5D4C82F17F8ULL, 0x802D849C2754B94FULL, 0x55FD87E039349257ULL, 0xB5D0CD5D207E9A23ULL, 
            0x4178E233612A2E59ULL, 0x79B61F558AFDF8BCULL, 0xAD9672D899B08777ULL, 0xE40BC6E3C8B9A495ULL, 
            0x1B91B12B908024F2ULL, 0x93240EDADC33BB76ULL, 0x64ABE374D085E1D1ULL, 0xF2B232578E77ADFBULL, 
            0x94B030548EF6CA0AULL, 0xD874B3281222C49EULL, 0xEAF48A853D400094ULL, 0xCA60195F96FB336CULL, 
            0xDB9BE502F1E7BB41ULL, 0x491C6D80DFA34734ULL, 0x504914D4F341B728ULL, 0xD337B8E9F2351F97ULL
        },
        {
            0x436BCAF7515D073CULL, 0x43961567C49EDE5BULL, 0x73C397C43C8B89E4ULL, 0xD8ABBFDA7A33C4F6ULL, 
            0x09F1A4D7CEB26DEDULL, 0x57E26C636D30A789ULL, 0x3DE97617AF0CF1EFULL, 0x6AD2875DEB421600ULL, 
            0xA9F808CCCEE9595DULL, 0x9598C91DF428BC68ULL, 0x81763878F135B9F8ULL, 0xC0ECF171FB07131FULL, 
            0x578BF8C3473FB3B5ULL, 0x1C82838275B103B8ULL, 0x9E10D1126437A62CULL, 0xAD2CDA4376255B7AULL, 
            0x280C5163A0BECAFFULL, 0x69A2A68717DABB5BULL, 0x4F8DED5F1481230DULL, 0xA2443312582A0269ULL, 
            0x1958602F1E4C8C0CULL, 0xBC4856D14DC6D7A6ULL, 0x4786E4A9614D6FADULL, 0xAEEE17EF168B3781ULL, 
            0x78CCDCB113E86EC8ULL, 0x968B2877D0681C57ULL, 0x0618403D57538782ULL, 0xBFE6EECED4908B36ULL, 
            0xEFFDA6D9FD0AD3F8ULL, 0xD625E20E41E1D66BULL, 0x1BB178B69370C341ULL, 0xB94EEEC216EDF593ULL
        },
        {
            0x5FAB762663C007DBULL, 0xED77481250FD2C7AULL, 0xE9A928BEEE4A0607ULL, 0x194392886026B7DDULL, 
            0xB7F731BE980217B1ULL, 0x8205EAEE379F9EEEULL, 0xE8E57451A6CBD101ULL, 0xDC3410E11CAE2E60ULL, 
            0x07019CF4B0D05A34ULL, 0xD7441E4422F7508EULL, 0xFF977D3064D2100CULL, 0x8619A8C96BECAF0CULL, 
            0x381E18D7CFBE86B9ULL, 0x5DC2C105BF7842B5ULL, 0xDA33333EFF5E2C20ULL, 0xBB5A5EAD1E34A7E8ULL, 
            0x32C6F548BDA278BFULL, 0xAA1030D33C7F1DA3ULL, 0x02DD9F5C67862E50ULL, 0xA15EC968B22AC91CULL, 
            0x4DE23896B47470AAULL, 0x3F9E3D33E8A30282ULL, 0x6BEC4A05A6C6036CULL, 0x6CD1242A97B47459ULL, 
            0x2306A2A827C054BEULL, 0x37232054C1969446ULL, 0x55796CE45FCA62CDULL, 0xCE2174E44E7335F1ULL, 
            0xBB8A741FA19E91EBULL, 0xE4B89B482F40D8C2ULL, 0xB85EE5B2E9A92BBBULL, 0x0A245DAD73107534ULL
        },
        {
            0xF53DB1010F8F6E08ULL, 0x60A255217F94FB9FULL, 0x5A47905688114F8EULL, 0x98DE94BDB873FBF0ULL, 
            0x2ABD3A0986D6AC5DULL, 0x05E94B45FC88E537ULL, 0xC4C7911C409D101AULL, 0x96DE1E386A435F83ULL, 
            0xA0432DE2664A75DEULL, 0x2AD9D3F765147F86ULL, 0x0CCF82A79E1C2973ULL, 0xD0E0F70B239073E4ULL, 
            0x5413681E21E821C0ULL, 0xA1EF75421D769F37ULL, 0xFC17C14ACF5A697BULL, 0xDDB3DC209AE23F61ULL, 
            0x045E6806EE572582ULL, 0x3B76F7CDD2DA6809ULL, 0x519BC2AD8944B1BEULL, 0x3CC0D65AAC88FC9AULL, 
            0x67097D1C1ADD4B20ULL, 0x1B0D0483D42AEF74ULL, 0x16D1CE62EBD6C534ULL, 0xF50FEFEFB5DD78ECULL, 
            0xC0E46AC3BE8A9300ULL, 0x7C3D9ACC68A632F2ULL, 0x3176B0D7A818ECA2ULL, 0xD236F1F1A78395E4ULL, 
            0xB05EC9B394CCEBFDULL, 0x8E8DAA3934525B79ULL, 0x81967A8D6C7DF447ULL, 0x6780820FCAE7A909ULL
        }
    },
    {
        {
            0x285823F8E4EF5A72ULL, 0x840EBEC6776159CBULL, 0xB52383D50D0E11C1ULL, 0x496A1B514D897ACCULL, 
            0xAEA7B71DD5A04FA1ULL, 0xFB0B6A70872675D1ULL, 0xD374A0A09CD7957FULL, 0xF92E37DEF5D847B1ULL, 
            0x9EE6FBAE1B8C9C6DULL, 0x12678F0832FD6775ULL, 0xD0AAFC0DF919440BULL, 0x0830AA08DC4B7F51ULL, 
            0x91ACCA759B5E08A0ULL, 0xC99DB1748331A4E4ULL, 0x107CA721C34AA85CULL, 0x1E0B868A6062B855ULL, 
            0xD65F2E7052C2D57EULL, 0x324E3FD4B5CE2951ULL, 0xEF036F5B84B7098DULL, 0xAB688B273CE390E0ULL, 
            0x6F6EA753847D43AEULL, 0xDB51CD6A2DF466D0ULL, 0xEC10316BF0A3AD49ULL, 0x4B663C6607D4A95BULL, 
            0x1EFCBBB604460067ULL, 0xCAD4DCA65D116225ULL, 0x0F70314D7A9958E4ULL, 0x74BB8470D556EC1EULL, 
            0x031F4F2299691FEEULL, 0x75AEBCC67BDBD8FFULL, 0xCF47FF8CEC2F5388ULL, 0x6DE56CEECD0D03ECULL
        },
        {
            0xD4D2F940947E2F90ULL, 0x7AC48709462D6C3BULL, 0x293895B802376AFEULL, 0x85AD4A45B481E223ULL, 
            0xAA9B28E5CA44B53AULL, 0xB5968AF089325B52ULL, 0x9762BF85E0786C41ULL, 0x50B2F834C0A869DDULL, 
            0x343397E026AF3FE7ULL, 0x2DD7DD46F8357ED3ULL, 0x5257178EA4600AB7ULL, 0x509AF2EB586C7E36ULL, 
            0xEA21660394B28FFEULL, 0x761A1EB2C0082D4EULL, 0x2DC02D2FAD71B5F7ULL, 0xB0D2954ABF732644ULL, 
            0x4F0976CAA7CE9B99ULL, 0x239E6E91E464520FULL, 0x7DA1676C29B49BFCULL, 0x7344E9DFC6B852D8ULL, 
            0x5FCDA9F0C71D059BULL, 0x8C0FA02D4BC6BEC1ULL, 0x72B5746F1D366733ULL, 0x0726EC7AF0FF12DDULL, 
            0x465BAE4CCEF307FFULL, 0xB5FAF95DDB97355BULL, 0x720A89C2679433F8ULL, 0x65D936B3429A76A1ULL, 
            0x6BAC16DA86139130ULL, 0x8F307DE3C12B3DEFULL, 0x4886D2F18F9D9843ULL, 0x6F20BC2020A9DAD6ULL
        },
        {
            0x33CDE2791C55DC6FULL, 0x5CAA1C6DD1D1FAB7ULL, 0x39942DA38EC078A2ULL, 0xACEC7E081E30233EULL, 
            0xD29EC32CED007552ULL, 0xE117FC296F8F3CDFULL, 0xD6B3C36EE9EA02B4ULL, 0x9915202330496D27ULL, 
            0x19D0DD5628E608C9ULL, 0x914CD52DFD52B8E5ULL, 0x95678732C6BFF859ULL, 0x070E2E58A833CD95ULL, 
            0x65E2ADD8AB78D153ULL, 0x2EF554BF3B3888ABULL, 0x80337D713ADB563BULL, 0x7C6A3C96B174122CULL, 
            0x685A343D7DC9CAD0ULL, 0x2FCE52D5169CE8BDULL, 0x2A1C2C4346FF517AULL, 0x4FFB949F903FE520ULL, 
            0x1386BCED383B024EULL, 0x42EE38DB89DA9057ULL, 0xF4C120D75E26B4A3ULL, 0x9DDA85ED36B92E81ULL, 
            0x7F42CE4537BA2694ULL, 0x1EFA35EF01DC9E7FULL, 0xF9F4C7D6BDDD220AULL, 0x02D68A6335245CA2ULL, 
            0x669C826194AF3D46ULL, 0x1279B471E250D021ULL, 0x47933F2BEDE7E7F3ULL, 0xC2F667F3624A94B3ULL
        },
        {
            0xF2A759F3E1079508ULL, 0x5E3630F83D32EA1BULL, 0x4471E9776DBA0D87ULL, 0x455244E3D539C7BAULL, 
            0x364BA2BAE47A458DULL, 0x70A73BF5F122F472ULL, 0x163729E254413A63ULL, 0xA5F7B5EF803D6356ULL, 
            0x402DCEB8E26797A2ULL, 0x5CE4481B250CFD5CULL, 0x2BBC156653C2E029ULL, 0x95105604DB095B0BULL, 
            0x77452B5C4AE51A46ULL, 0x06C06F9EE87ED30CULL, 0x5E94223884F90F3DULL, 0x38DBD7B3A468F1BFULL, 
            0x369425EA9B1BF992ULL, 0xEC740F26DF40EED9ULL, 0x8382A3073F0AA258ULL, 0xE43C91072193C285ULL, 
            0x85D4663CBDECD15BULL, 0x06E3740362E0122DULL, 0x815B6398F074DB91ULL, 0xAF888B9AC4712136ULL, 
            0x27034D0DD7974B9EULL, 0x543B4BF886710950ULL, 0x2E851FE9FE1FCADCULL, 0x5A27F38E25C3E155ULL, 
            0xE077E29DBC5A86BEULL, 0x62BA54627743E5E9ULL, 0x4421068F02061640ULL, 0x1CCADAE5DEE8F32CULL
        },
        {
            0x7F62F908ABA2488FULL, 0xD30F8DA50E868CF5ULL, 0x31C41B2CF0F06EEBULL, 0xFBF0E754EF0D0B67ULL, 
            0x388F7F091E757241ULL, 0x0C95312FA02053DAULL, 0x6AA8932AEA3C62FEULL, 0x70AA8DEA48F2945EULL, 
            0x9448FC3D24B53D59ULL, 0xE65C62605F15558EULL, 0xEE361E0992278E2CULL, 0xC42B2CC1825131ACULL, 
            0x7F2FE40EFC0A4AAEULL, 0xC5867AC76C4F9D2FULL, 0x578B9055F82F9303ULL, 0x67C9266792E32A94ULL, 
            0x2FD7452BCFD21D48ULL, 0xD180A8DB51C3D647ULL, 0xE08C0162A1A425F6ULL, 0x295D1EDF23558D23ULL, 
            0x230C15910962966EULL, 0xF46278D06456AB56ULL, 0x1D4AFB8866CE9027ULL, 0x7C91E565B4338183ULL, 
            0x1098821D424E40F7ULL, 0x8D03A77796884351ULL, 0x52D333683E415682ULL, 0x0800A1DCBA42D1A1ULL, 
            0xEE002F8370A3E5E6ULL, 0x716F045FCABFC6D1ULL, 0xD7F29E036B2CA14AULL, 0xE64E027319435206ULL
        },
        {
            0xAAF3D28A997380DAULL, 0x18AAB9FEE95DEC63ULL, 0x12DD5D2F1071D5C0ULL, 0xEF3E7BD0299AB58AULL, 
            0x925B5AD6F8D355EAULL, 0x1470BB52D5F31613ULL, 0x9E655CF341CC48DCULL, 0xC5E289C57585AEA8ULL, 
            0x3EFD221ACEEE793CULL, 0xC6A917B14FA6598AULL, 0x2C054202CEF4DC59ULL, 0x80D2649AB41179B3ULL, 
            0x3F03808A0FF77E23ULL, 0x3BE5C07EFC67C33FULL, 0xB85442DA9AC77932ULL, 0x57666610B655EA46ULL, 
            0xA3108EE4848CEE27ULL, 0x5FFC5269C7ADF8C0ULL, 0x67CCE3FC82351A18ULL, 0x197ACDA2BD230A8CULL, 
            0xC9C88CC290B9DA06ULL, 0x649A8AC039E0247DULL, 0xFD513F303BC1A9A1ULL, 0xEB1956A8609A9ED2ULL, 
            0x5F76655453D2291EULL, 0x358B085B7AD8BEDCULL, 0x1FA822AFA44F3CD4ULL, 0x52FC259F9696A202ULL, 
            0xAC43A24370A713E5ULL, 0x5368DA542AE439A8ULL, 0x505C91940ABB6B2EULL, 0xBBA8D3D6E796A02FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alioth::kKeyRotateBConstants = {
    0x8ECC495F6BDFA236ULL,
    0x703FC8CC19777243ULL,
    0x25B4C3F5A503AFD6ULL,
    0x8ECC495F6BDFA236ULL,
    0x703FC8CC19777243ULL,
    0x25B4C3F5A503AFD6ULL,
    0x3C8A3470E76649FAULL,
    0xB736AB8E7B56E9EEULL,
    0xCE,
    0xB3,
    0xA6,
    0xBC,
    0x04,
    0xA1,
    0x8C,
    0x05
};

const TwistDomainSaltSet TwistExpander_Alioth::kKeySpawnASalts = {
    {
        {
            0x6606286EA49AA96AULL, 0x480952B9E8FE8C5BULL, 0xDA8F76F1EB301402ULL, 0xCE98CD4C2E699FF4ULL, 
            0x16AB8BE733136B52ULL, 0x20D488C46400146EULL, 0x8AF5E62C31C250F3ULL, 0x76614E8802881E38ULL, 
            0x6B15661AE29C1FF1ULL, 0xEE528AE3B9E92311ULL, 0x87E9191493DA4642ULL, 0x7722BA4ACBE8942BULL, 
            0xF8E80A1AD7D1C54FULL, 0x4A06E067D152B2C4ULL, 0x31DF110081D675D2ULL, 0xE37D2AB9717868E8ULL, 
            0x9BE8401044D8E858ULL, 0xAB9221DAA4B16352ULL, 0x49A326D74DECDB5BULL, 0x7D488795B4226448ULL, 
            0x448C8CEFF26CF914ULL, 0xFEA41825D0C4D0F1ULL, 0x001A02404B7943D6ULL, 0x58A9E8E97D39F9D0ULL, 
            0x71313FFCCBEADABCULL, 0x5269D7E0E408C1B6ULL, 0xD36D18ED844AC08BULL, 0x4C846286F937B7BCULL, 
            0x5FB9FDAACAFA1448ULL, 0x572D6516722EFD3CULL, 0x2542FC56798C4713ULL, 0xFED32EE1D3EB54AFULL
        },
        {
            0xA19375E64C03D7C8ULL, 0xD45BA6E44404E990ULL, 0xEEC8BA05328C3FBEULL, 0xFFE6F34592F4E50AULL, 
            0xDCAE16051AE8FC90ULL, 0x2744E5A0B0FF72A2ULL, 0x595407DD7133C03FULL, 0x6251CDA37D22D26FULL, 
            0x4EC731FE7F562ED9ULL, 0xE132CDD99821E387ULL, 0x6611A0E00C91A529ULL, 0xC05667345C73D484ULL, 
            0x7FEEC956C64EF6FCULL, 0x16BA8DB174658AF1ULL, 0xFD63011947314E27ULL, 0x02B5DB9FF29C2110ULL, 
            0x6FEA083760144249ULL, 0xDB5E954E0860D745ULL, 0x8068DA64D22D509BULL, 0x59271D3478D81A53ULL, 
            0xB875C67E5F28C107ULL, 0x0564E11614A45A4FULL, 0xF564F0A959BE2852ULL, 0xD549118E96F4E1B9ULL, 
            0xA76A7EA0804CBBCBULL, 0x74EED69321447AB0ULL, 0x01EBD8AFB5B8F886ULL, 0xC8AC1A4EB4F3384AULL, 
            0x3DBE313A44882C1DULL, 0x1545782745A27507ULL, 0x01C38356A2BCEC68ULL, 0x013E1765454FF07BULL
        },
        {
            0xED1186D267DCC8E9ULL, 0x5EFFECFDE3D63289ULL, 0x4F5F7478DB885DB3ULL, 0xF3E181C16A5229E3ULL, 
            0xA2221075D4284582ULL, 0xCE25A8EE60C4FD87ULL, 0xE6B28AB82A6895DAULL, 0xD4A9A3239FF63D6FULL, 
            0xC847DCE41CC746C7ULL, 0x44098BD4635CE0E3ULL, 0x48BFEB89A60BD3F4ULL, 0xA3B164C3842F2465ULL, 
            0xC5D07D65D0AE9856ULL, 0x0105ECEA5A2A1515ULL, 0x4A03870D640E4CE7ULL, 0x3550E1EC8C873F57ULL, 
            0xA9101B02C35DD058ULL, 0x19711513F0534A57ULL, 0xF651BAD166E095F8ULL, 0x309A071EF80EDACFULL, 
            0x4EAEB4EE7C6DB644ULL, 0x31F0D1FC9416033FULL, 0xD944511D94376C73ULL, 0x68FA21BCE69AAD8DULL, 
            0x64821E4939F727B0ULL, 0xC2719F2CF6D75745ULL, 0xC2A1481D3C889730ULL, 0xC707F617F70B4E9CULL, 
            0x611471E4BF2AFA7FULL, 0x7E905FFD418F737CULL, 0x5B6B646CA9B70EB3ULL, 0xAEFFB34BBE44A7B6ULL
        },
        {
            0x6ED10317A272E414ULL, 0x7E32F22A5F9CD8DCULL, 0x7699C4733044D2EDULL, 0x35FABB4EBB7515BCULL, 
            0xC0FBDDE0CD27CC74ULL, 0x7860F2094932C3ACULL, 0xCA1A7D9F4FEE30A0ULL, 0x8CD2FC678DA93E3DULL, 
            0x70841FEED8520308ULL, 0x24A99B0EE990852DULL, 0x26DE0E56804E2E73ULL, 0x08B1D1A93F970454ULL, 
            0xBC5CE5E2B89552A1ULL, 0xD1D9EA0005598287ULL, 0xA595076A87EB1437ULL, 0xDBB748FA6513AB7FULL, 
            0x07956405AE18B3A1ULL, 0xA442AD1A18A399C7ULL, 0xB191493D296AEE8EULL, 0x19BFACCCB353DF3AULL, 
            0x794655908BC30F78ULL, 0x0ACB22E95F37F591ULL, 0xDBCC890A2A59559DULL, 0x28F0CFFF3192D77BULL, 
            0x965B226DD55688F9ULL, 0x5C8D61F451CE4AD2ULL, 0x60FAF05CC25E3C05ULL, 0x0FB0A8CEC1EE9AD3ULL, 
            0x0E5B7B441EB3FAABULL, 0x5777B92E6D967A8DULL, 0xDE2BD6D7798DC2F2ULL, 0xAD36874D024BBCB9ULL
        },
        {
            0x92E531C84BBC0099ULL, 0x82EEB99138CA0C39ULL, 0xE6AAF49F70A2A493ULL, 0x616F4E60213979C1ULL, 
            0x41C34E5F7CD71D96ULL, 0xF6EAD55BB6DCF81EULL, 0x0AE850619363757CULL, 0xEAE4CD5BE5DDB998ULL, 
            0x96F8F9E817F22A53ULL, 0x78448F5C464FEEB8ULL, 0xEAA40D02F90787B4ULL, 0x5108F7797A664EDFULL, 
            0x847EA78730467102ULL, 0xC5F015E9CA08581CULL, 0xFDFD85B284D1D141ULL, 0x01C2D78D0FC4D449ULL, 
            0x0E6706B1D4D77DB9ULL, 0x1B712D53128E5EBEULL, 0x6F021E4DBF0CC153ULL, 0xDDB78851576941F3ULL, 
            0x8A01062A6E2CDC8FULL, 0x1C26B7F24D01F73BULL, 0xF02DADDD90A9C729ULL, 0xCF630AC93B1C15F5ULL, 
            0x926C65BCB10F9560ULL, 0xEF232847BC803545ULL, 0x53DFECD0F1A3F78DULL, 0x50FD78DD68F8D78EULL, 
            0xCEF54F03DAE0FB68ULL, 0x2B5A545905FB7B45ULL, 0x77653B5B9639FC52ULL, 0xDB2937C344B3DD45ULL
        },
        {
            0x357456DC76D3EB2EULL, 0xD6A4C08D84E80B3EULL, 0x51D982160584BFB9ULL, 0x99AC49CB80F61B5CULL, 
            0xB3CC4E5B7B84B957ULL, 0x0AC83BFE9C55251DULL, 0x9B6D3193BF3AFA70ULL, 0x5910169E3467AE38ULL, 
            0x23E210D4B1A7DF3DULL, 0x2D6B000825F7B117ULL, 0x3F9D14B01C687630ULL, 0x22CF7398F320DC60ULL, 
            0xCED32DDBBD376B4FULL, 0xFDAB8F8B9FC231D1ULL, 0xF0D8661E073304EFULL, 0x82A4BA2C3B3DF209ULL, 
            0x6810E8E8FCC44359ULL, 0xA720E1594A3FE65CULL, 0x5A3749F455CD6505ULL, 0x4239917A78C2C22EULL, 
            0xA0C464AB1E90629CULL, 0x2E016B3FA22DDFE1ULL, 0xBEC17288AAFD8137ULL, 0xFC28CB7962A4386DULL, 
            0x454F499446BDB213ULL, 0xAAC90CE30EC70966ULL, 0x808EC03C2E930B8CULL, 0x42C6048F0D29A6C6ULL, 
            0xDCD2C7B41CF5C10FULL, 0x9AA80CE95E52CCCCULL, 0xEFF90676C98493A8ULL, 0x58642A8ADCD7718AULL
        }
    },
    {
        {
            0x8346D4FD4D41C2C7ULL, 0x9EED074C154DEB3FULL, 0xC03FF39D5229BEA3ULL, 0xEB6558E962D4CE61ULL, 
            0x8488B1FB1163EED4ULL, 0xCA1477060CC30718ULL, 0x5C78C9FABB2A6390ULL, 0x3F5D59D8FE2CFF0EULL, 
            0xE047D77E24636FFBULL, 0xC237FC01A02D6B50ULL, 0x69408179A2FFB1ABULL, 0x3DEE98AD935C203EULL, 
            0xFFC98202DE2A3B5AULL, 0x04F807CA96BA286AULL, 0xA8BEDD240359D31FULL, 0x201FBA938B5A949EULL, 
            0x92F22D81E24576B0ULL, 0x81879AAB1EA12139ULL, 0x2263092E503F27C0ULL, 0xDA7EA9D58F00A717ULL, 
            0x0317D50AAED29884ULL, 0xF4E6438A2436D6AFULL, 0xC9244F6F8E261783ULL, 0x709EF50FA0149F2CULL, 
            0x65F2EB2E692ECCCFULL, 0x65E6EDE3844472F9ULL, 0x10AC18404CD0D29AULL, 0xB20720833AEBF9EAULL, 
            0xBFEC73C8CBCF006CULL, 0x7EA483CB81897724ULL, 0x2F595CAE000B669DULL, 0x5F7CF57D8FB224D1ULL
        },
        {
            0xE083ECC7483C2477ULL, 0x3F2BC40038EE5410ULL, 0x0CFF9E950BF21612ULL, 0x4F5CC5EA2C2E5360ULL, 
            0x2DF6AAFD644E8AB0ULL, 0x57ADABC641274079ULL, 0x5F8FA6E00AE96BFCULL, 0xFD46E629964DCF64ULL, 
            0x7E6AC0919032E951ULL, 0x3592BC3937C8BF9BULL, 0x49B91E8FFC826B15ULL, 0x08A4A3A652681A7BULL, 
            0x26C7B81B5BFE272EULL, 0x6DFCFD68544A08F4ULL, 0xA96A42C1B73D17ADULL, 0xC73C1AEDD2EA73E7ULL, 
            0x8686B62D68C0ABF6ULL, 0x8C009069BF693675ULL, 0xBB3CAFF26A994C98ULL, 0xAE585167AC9E56FAULL, 
            0x9946437BBDD36254ULL, 0x2D7BC61169DD7D4AULL, 0x7BA14D1D2A0DE84EULL, 0x054C7DD37A694CD4ULL, 
            0xEE6740543BE3DA44ULL, 0x811F8CCDC543FE36ULL, 0x1575E36A79738656ULL, 0x48B712DDE38D2E23ULL, 
            0x2B83A4C04320355BULL, 0x4F973157D9A4DF56ULL, 0xA0EFAB84C705F13DULL, 0x543F7B7A870B382FULL
        },
        {
            0x6EDC702C99C04A08ULL, 0x221FC80CEA403F20ULL, 0x53FC93A5F76882A7ULL, 0xD0C639067C0E80B0ULL, 
            0xEDBC04FE954E25F8ULL, 0x4FD5761C2CD4A8B8ULL, 0x8E064DC4F37A22D3ULL, 0xF0B3AF2B3AAB26CCULL, 
            0x3D4B877737C43F32ULL, 0xB1B6C22E812C58F0ULL, 0xAAB0A7898EC61AFEULL, 0x1ACF388A98A22B2BULL, 
            0xCC28AE156F996599ULL, 0x3B769BE29ED579B6ULL, 0x2C9FEE4B510EC464ULL, 0x3972DB61283F11AAULL, 
            0xEDB0753619271120ULL, 0x86D1A2C2C5EC273AULL, 0xA3891684E271E5C9ULL, 0x51EA7C72A097BA4EULL, 
            0x61C69A2E5EB23209ULL, 0x955E4C04E3653153ULL, 0x6D7900D176A7D7A4ULL, 0x5959BBE2DFD17280ULL, 
            0x46BA036B55AF590FULL, 0x3E88653B49E85E58ULL, 0x6F5422BA015DFBF5ULL, 0xE50B50FF5B5C4945ULL, 
            0x2AB17A843F134404ULL, 0xC77285257BC5391CULL, 0x2AF8E840A408664BULL, 0xB3F8600834C2BD81ULL
        },
        {
            0x04B2917A3B33D141ULL, 0x77D350DF93FB79F4ULL, 0xCD24664FFF215AA0ULL, 0x9FFE55CCE6AEFD5DULL, 
            0x16EFD67E1E795197ULL, 0xE0504EF944A760E0ULL, 0xBA7C9D7556B36746ULL, 0x5BAAC128A93DCECDULL, 
            0x869148D4C3B28942ULL, 0xB8ACB09AEEFF3B64ULL, 0xD0CD5E50BCC0714EULL, 0xB1A81B47E4562C1AULL, 
            0xB011BC8A5C35FAAFULL, 0x42F8DBE3BEBC8B89ULL, 0x048B46AFF1AB8409ULL, 0x5969824D3C75E441ULL, 
            0xD343EF72847EFA96ULL, 0x99CE3A1566AD2370ULL, 0xD9A08AB03FB47428ULL, 0x2D9EF491F937DD38ULL, 
            0x8544307BBBA2A1FFULL, 0xE60C7D623BF36860ULL, 0xA8B67008CF157937ULL, 0x461D746EFFBAEA22ULL, 
            0x4D9ABA5BCB516D38ULL, 0x04BC26C8B9708624ULL, 0x913649ACD47385E7ULL, 0xB707CA3726CD1AD0ULL, 
            0x20680136CC5BB053ULL, 0x9323DE62FB8CD344ULL, 0x33463A8E85B88B40ULL, 0x6AE59F1A591F2ED3ULL
        },
        {
            0x9755246FA657265CULL, 0x52832D469884E2D2ULL, 0x48EE958D63F9CCBEULL, 0xC2B59AAF12DC6326ULL, 
            0x0A4B5F301914020DULL, 0x2372D89AA7125E12ULL, 0x9B9B1574355D91BBULL, 0xD2CC4F82FEB8A0E1ULL, 
            0xBA5DB90CA6CA2762ULL, 0xB2DB7F56DF1C9A6DULL, 0xE17D460DAB967893ULL, 0xABE4C38EF155BE8AULL, 
            0x437D74BF77DDAC4EULL, 0x433CE38ED8390293ULL, 0x4F657C874FD2D597ULL, 0xD27CD7C785067869ULL, 
            0x28ED4F50E9DA4D27ULL, 0x4DA186F4A7AF298CULL, 0x0B9A569607A1232AULL, 0xAB34F0642DFF8EBBULL, 
            0x3263D3D6381A0B31ULL, 0xDC2E07D6E44A2017ULL, 0x276E9C3A1DA45FB0ULL, 0x454676EA5B134E01ULL, 
            0x9130ED1070CF600AULL, 0xD9850A4123A1DD1AULL, 0x393DB648B0EB8DF6ULL, 0x4C149243F8D74867ULL, 
            0xCFFB34697D56A1D6ULL, 0x63C1B3796FB864B1ULL, 0x45276E5662C5451CULL, 0x5D211A2C09D70C6BULL
        },
        {
            0x34CC11CB9D97DD52ULL, 0x32055668F50C9A43ULL, 0x8E6286C94414B5C5ULL, 0xFE997C0F8758255EULL, 
            0xF55452AF50299E08ULL, 0xA2FCEF4236718657ULL, 0xB06C76EE95382159ULL, 0xDCEE620165161A6DULL, 
            0x20D3AA8CB7375C1DULL, 0x523DCA36469DED78ULL, 0x283DA4D9C7265E4BULL, 0x56360E35BDB73DFEULL, 
            0x1C84C53FEFB0D990ULL, 0x8BE82871E0CB9FDEULL, 0x920D8F4482706C28ULL, 0xF965AFF6C52B24B3ULL, 
            0x018C34713F2B3432ULL, 0x829183EEF918686FULL, 0x1FF0B248D69A32B8ULL, 0xED08C76F83BB47C0ULL, 
            0x680980A2F3CF1394ULL, 0xCD6DD67B2F342906ULL, 0xCE9864830131DE9AULL, 0x6BE62AC4EFE78FCEULL, 
            0x397495F7D6EEF629ULL, 0x8D15417D863FA032ULL, 0x1517E8FF85383055ULL, 0xC0F6464843E8489BULL, 
            0x972B459269E2592BULL, 0x919D72030EE67C41ULL, 0x4BBA04642529E2AEULL, 0xE45CF225DA5EFB96ULL
        }
    },
    {
        {
            0xFF27BFDB94EF1714ULL, 0xB7AC5F126D685092ULL, 0x6DE8D373A26B7D67ULL, 0x0A6B8DEB8181E717ULL, 
            0x284A79442EE6FB17ULL, 0x788CDCF746AAFFFCULL, 0x2D0FE6CD3240F8EAULL, 0xE939D7E313D4498AULL, 
            0x70D64F46646916F8ULL, 0x3576C05DA521E0F5ULL, 0xFF2C6BBD7355B1EBULL, 0x91AA6E948ED05176ULL, 
            0x8EC99F3E467D5C73ULL, 0x1946AE69CBEF840AULL, 0x6778EB78DB08B125ULL, 0x99C78B5CFE2EAB57ULL, 
            0xB2943957621355A2ULL, 0x68BBFDB1CC42BC56ULL, 0x2EE99A1486373BF3ULL, 0xC6BAB6F2F9014FFBULL, 
            0xE2E18DFADEAC3D80ULL, 0xE65A1EF18E85F564ULL, 0x60A4209847CCD53AULL, 0x64FE142894925E85ULL, 
            0x61995479E53D2128ULL, 0x3000664B930D4CDCULL, 0x8A56E68189380417ULL, 0x37025D613E4F81EEULL, 
            0x6752389340A18F3CULL, 0x0E58E65CFFE97D87ULL, 0xD3EB06E71B4E8AD3ULL, 0xA02EF1680ED2D246ULL
        },
        {
            0x59A0BE0EA3AB3AA7ULL, 0x7B14527BF6F91474ULL, 0x0C2792D967C42577ULL, 0xAFF3C487F33AB3F7ULL, 
            0xF4E0C4E6CD21AC7CULL, 0x62E5FE15F5894E46ULL, 0x77E53D250257E7C1ULL, 0x6CB837A072E02D13ULL, 
            0xFDBAE1BCA48ED698ULL, 0x1CDEFEB58E489233ULL, 0xF0726826F92B1884ULL, 0x86909FE72C22BDC8ULL, 
            0xF2E4F5CDEDFAAF8AULL, 0x5C6B958123A455BAULL, 0x455EEB302CB38671ULL, 0xD3F489FAF9743997ULL, 
            0xB21059DEE47D323AULL, 0xCDB794DD57C94176ULL, 0x0038252CE0CE712DULL, 0xD0F252DF0D135D80ULL, 
            0x75BF5FEA27ADDCF7ULL, 0xA2BF9A64DDF9F575ULL, 0xC3AD2262E1E1E467ULL, 0x5A2B9F011D092A9BULL, 
            0x5EDA2577D17A65A6ULL, 0xADF3C695C8F45D88ULL, 0x76EBC45CB7FB1446ULL, 0xBBDFCE170CE8FC10ULL, 
            0xC1DE32D320C445F0ULL, 0x51668D690FF41E5CULL, 0xB0DC38FA39EAF3E4ULL, 0xBF0DF46260CAA69CULL
        },
        {
            0x2E53386FEF7D2A55ULL, 0xD40648E42725D2DEULL, 0xBA69BE27A6BC7BADULL, 0x7346E0125D702A91ULL, 
            0xFE5880B5FE74594FULL, 0x8C1EEF60236264C8ULL, 0x371C1246159A1CFFULL, 0x985A9361C33B5A35ULL, 
            0x4525CBF1867B9250ULL, 0xB99491B2282BE38BULL, 0xB5A0E3CF5AA95EB6ULL, 0xC4A3701BB1EFD9BFULL, 
            0xF5E83104DC8EADA5ULL, 0x0FA8CCC21F76D855ULL, 0x02C46EBDFB81D509ULL, 0x9F4C9F2BC70DA961ULL, 
            0xA5A682F5B57671E6ULL, 0xB69BC53EF67849E2ULL, 0x31E9486F5C6F1F1CULL, 0xF60237AC7A2A056CULL, 
            0x4F005CC9751679E7ULL, 0x6681DD508CC5A6FBULL, 0x8EF9122B004A48CAULL, 0xDC8E8CA61F494F4FULL, 
            0xCCCA5843A51BA94BULL, 0x0BB73123176BAB37ULL, 0x515AD7BF0CE3581CULL, 0x1EAA10D17EE96619ULL, 
            0x476521349B339C6BULL, 0x8494C291E2055EA8ULL, 0x664939EB915AD1E5ULL, 0xA7348C9E9F445BC7ULL
        },
        {
            0x4751D92C90361929ULL, 0x6BA228977432808EULL, 0x6B0CF74D8C66276DULL, 0xE86CF70FD6749D0AULL, 
            0xD8B5DA0CA01D35FDULL, 0xA64550E2115898C4ULL, 0x0614A488015312D2ULL, 0x011812561CE01773ULL, 
            0x22EE98606E9498D0ULL, 0xBFFBB4310EFF0ABFULL, 0x6E5B91F197F0152CULL, 0xFCE2E8E29C74D19CULL, 
            0x8DA18B3B67457234ULL, 0x16D4A4FE80D98D9FULL, 0xEC02E06F0B932973ULL, 0xF4A4D5D90A067885ULL, 
            0x613A1DFBD2915DE8ULL, 0x1E627C72D478337CULL, 0xC550D149801C9BDBULL, 0xE08DBF34B73512DAULL, 
            0x64036DFA374236E6ULL, 0xD1651EFF03AB0AF9ULL, 0x4DDCB0771391C8CDULL, 0x18065A940780AF0EULL, 
            0xAE432A0BBFD1EE02ULL, 0x681A45EF29928443ULL, 0xC37934575873D7CCULL, 0x67A256519E26AFAEULL, 
            0xCE9AC51536436FB8ULL, 0x840AE168B759875BULL, 0x36F9C35D1E820804ULL, 0xB2DAA042344BC5F0ULL
        },
        {
            0xCC9693CC59D12D0FULL, 0x42E6C2A92ECA7058ULL, 0xF13F084E5AF282A3ULL, 0x6765E2E08FF1D60EULL, 
            0xB4511195E452841BULL, 0x0C01C39FBA0DF800ULL, 0xE3AB72D32BD3ADB2ULL, 0xD6965B36B1839FF4ULL, 
            0xF78603DDB9C6972AULL, 0x575B00281F4976D5ULL, 0x831DFC8EA739954CULL, 0x8574ECA9A705F916ULL, 
            0x4CCA245BE0DC5052ULL, 0xFABAEC24452963E6ULL, 0x99A168005A24020DULL, 0x26985E9823F6DEB7ULL, 
            0x8675F8F223E3AAD7ULL, 0x84C3CC99B3A96C10ULL, 0xDE214BBE6A5274ADULL, 0x5E3E6D1F6BF28E11ULL, 
            0x3831DF57822B1280ULL, 0x1DFFDCDB25B574C5ULL, 0xE6DE66C771402DEEULL, 0xB53108C21C1A3072ULL, 
            0x51B4F424A9290F91ULL, 0x1D9FAD3B61925CF4ULL, 0x70AEE090374AA5FCULL, 0x0717F08D279CD923ULL, 
            0x5CAE85100C68C6E6ULL, 0xD4E210E5E85743A2ULL, 0xDCDB561AE09504E1ULL, 0xAA5815291A34A032ULL
        },
        {
            0xA42B43D5D22A1620ULL, 0x1C697D2C8DF6D908ULL, 0xE11DCCBA09DAF97FULL, 0xB912BA83800F0D6CULL, 
            0x35DD8A8C7F8B59D2ULL, 0x85F5F48B652F2CA4ULL, 0xFF8D9A8A4764512CULL, 0xD1CB5B847DBF09BDULL, 
            0xACB64BA6DEB3BA42ULL, 0xEB78C77233BDB16CULL, 0xF932675A2B431A93ULL, 0xB49707D33C6D0C35ULL, 
            0xD19DF3019B8A83CCULL, 0x875E7019EB9A7499ULL, 0x17ABD987311AD996ULL, 0x8B87075709238B41ULL, 
            0xB5B8A051A8007F13ULL, 0x68CD209864A00899ULL, 0x4F3FF30A9F028A23ULL, 0xFE90DF886F89E057ULL, 
            0xDD8955EF1EE20382ULL, 0x70EE41ACC54DEFB7ULL, 0x3C9E0D46B06831A9ULL, 0xA7A5C05521D3F142ULL, 
            0x690C8A2285529026ULL, 0x590B101AEAFBC4BAULL, 0x79F7AF74350172B7ULL, 0xF7A2065E0A76E2EDULL, 
            0x58A4EE99B50AE198ULL, 0xA3F7C98AD71065F5ULL, 0x3BA678FDBF6B105EULL, 0x29AAA085F1DF94FDULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alioth::kKeySpawnAConstants = {
    0xBF14860FA1C04DF2ULL,
    0x0223ADD16FCB2A4DULL,
    0xC2546C109EC8C860ULL,
    0xBF14860FA1C04DF2ULL,
    0x0223ADD16FCB2A4DULL,
    0xC2546C109EC8C860ULL,
    0x544DC6D867B6AE97ULL,
    0xE8A9B7304EC78EF9ULL,
    0xFF,
    0xD6,
    0x30,
    0x75,
    0xF7,
    0xB3,
    0xB3,
    0x7B
};

const TwistDomainSaltSet TwistExpander_Alioth::kKeySpawnBSalts = {
    {
        {
            0xE532D7FBB8DE14BFULL, 0xCC17AEC77B3CCB7DULL, 0xF0DB3DC2F7F3255EULL, 0x61A0BC268334E158ULL, 
            0x7A37EFF4B4324863ULL, 0xA61D6D5D592613D8ULL, 0xDF99C8B2A2DFFF65ULL, 0x119D5DE6E23FE0E0ULL, 
            0xEA25182572B1BC9EULL, 0xDB84B1AE31059FA7ULL, 0xF37D5FA2CAEFB157ULL, 0xE054EED218B65776ULL, 
            0x06E4C8E6C03D5A10ULL, 0x04A197C38C74C3B8ULL, 0x3BA67213A4204F6BULL, 0xEDC598D70D6968FBULL, 
            0x37DC4BE4563768B9ULL, 0x40212BD5AB844700ULL, 0xC1CF485FC3B080DAULL, 0xE4DB93603EDDF706ULL, 
            0xFA859A825A645626ULL, 0x99BB2E079FDD8E39ULL, 0xE8692E413E55AE87ULL, 0xB58C8A648D325671ULL, 
            0x079A28859DAEBC23ULL, 0xB2FD683BA80E9B00ULL, 0xE283625A69B07862ULL, 0x712F592E84CF4A47ULL, 
            0x9AA1F57B145BBE2DULL, 0xAF0A6B858BA8FFD9ULL, 0x793785ED8CF919B1ULL, 0xC710898D02AB30E4ULL
        },
        {
            0xD05DB4771DD1C5E1ULL, 0xFC31A7971AFAFDF9ULL, 0x0220F34FD79B8E8BULL, 0xFEFCE03E9AFE8980ULL, 
            0x66CCB7347F77592FULL, 0x6B3DD4E2970073ADULL, 0x4CBEBFECD97D39D5ULL, 0x59BCFCF318FBEA19ULL, 
            0x8EE929E61FDCCD7FULL, 0x4822929F045AA380ULL, 0xD6F6CB15D1C2D193ULL, 0x6A04FBE26B75E878ULL, 
            0x8932276CF0E9DB75ULL, 0xC648BDF5D9DAEE4FULL, 0xD3577785B7BDFFC2ULL, 0xF2DE8BF32E2BD204ULL, 
            0xD39A21A6D1AD2E20ULL, 0x41EBF1EE4E09BDF0ULL, 0x4A425A8E87362D1DULL, 0x62B098CC24E56188ULL, 
            0x88CB6325DAE7E404ULL, 0xDE8610173823634AULL, 0xEF4A57DD53330D99ULL, 0x51B20E4639F15E79ULL, 
            0x85CFC3E1428845C6ULL, 0x36F4FA3857582422ULL, 0xA64ED3667757FA9DULL, 0x4470B3BEC05E912EULL, 
            0x64858AECC202BACBULL, 0x4384356BE9DC7207ULL, 0xBA3D25BE9B861333ULL, 0xC38BB193577DAB85ULL
        },
        {
            0xEA60FB4368DC4C35ULL, 0x785529FB9B873A1DULL, 0xA3D660346FB4D2ACULL, 0x2437409EC842E0EDULL, 
            0xAD8817E11AA11217ULL, 0xE472282BAD686BD3ULL, 0xA8C90D606B9A12EAULL, 0x7B7CC29DB981EB85ULL, 
            0x11933AC25001C897ULL, 0xDCA479521BEBF69DULL, 0x83807A89517D877DULL, 0xAA6584F588B358DCULL, 
            0x464A810C62920FFEULL, 0x1A369D8BB45DF3E9ULL, 0x9F0F6F1FAA1604A7ULL, 0xDF9A9AA06143D625ULL, 
            0x283DDC32462B38FDULL, 0x5E11F4BAB0E424A8ULL, 0x505B9E8F91425F5AULL, 0xF6C4FCA70F5CADEAULL, 
            0xC81E641E335DDFF2ULL, 0x85B45F4EEAF2E4A6ULL, 0x46FC8564645EF58BULL, 0x380994C7A0CD36FCULL, 
            0x2A135E8C436A1F9AULL, 0xBC90A49A39AA014FULL, 0x4A0D722DA52EEFCEULL, 0xF2046F801F2391F4ULL, 
            0x0409630F9A06E625ULL, 0x82909DE46DE8205FULL, 0x34EE9C28CFE87167ULL, 0xD76DE5F175B8DD8EULL
        },
        {
            0x62D791C4ABDD3289ULL, 0xEDC221143282D91AULL, 0x48284705AB71DB08ULL, 0xE0E9D40126F6E4E0ULL, 
            0xE6DF326D8BBCF33DULL, 0x1DE084B6B6334C9DULL, 0x2832EE8015E50351ULL, 0xBEB8175CF0506E46ULL, 
            0xB845518FBBC056A2ULL, 0xADE11ED97ABF79BFULL, 0x32835C0474A1BF3BULL, 0xFD4D61F52AF0EE80ULL, 
            0x84AD5157513F0BD2ULL, 0x08E26CDB6E1421C1ULL, 0x0FFF68C049348DD0ULL, 0xEEA68AE9A5265940ULL, 
            0x8DB25D549163B3E5ULL, 0xFB3D64FBA490B35DULL, 0xFCA243ABA4C4E215ULL, 0xEF03133D3F7F7CDDULL, 
            0x9F3355D82CA8D99CULL, 0x976C6DD1F390650AULL, 0x1BE2B30867D8AA23ULL, 0x364278280BF2A03FULL, 
            0x62442DD953EA21A9ULL, 0x1CF0ED6AAD5E20C0ULL, 0xBBF626D875F2FEDEULL, 0x1A7C04BCAC3F4CF9ULL, 
            0x7A8D4C4A114300F0ULL, 0xF09C36B9708BABEEULL, 0x54A11984ADDFFC52ULL, 0x46E15931C3A79CD9ULL
        },
        {
            0xA5F603FA41D31F4AULL, 0xBC8CD00532BA2F27ULL, 0x30396DDDDBB4E6C3ULL, 0x2C7029CA0F69AD76ULL, 
            0x8118B192875B5E5BULL, 0x58AF95CA5202FB13ULL, 0x3BAB23DE051AF576ULL, 0x3EDA354C199A94DBULL, 
            0xEDC5CE2B8438A09CULL, 0xCAEA0516359912E7ULL, 0x93855AFED5C0157BULL, 0x0D2AC84B6FBEE8C9ULL, 
            0xCB26ABB5274CA953ULL, 0xE3F1462E764340D5ULL, 0x569C1EF48EDD626CULL, 0xCF4FFAEEC609A366ULL, 
            0x5AA411DC438B63D9ULL, 0xE8E38824D97F7574ULL, 0xEC3EA2BAF3914B5FULL, 0xAB16A21651C1DEF5ULL, 
            0x34FD7F585AD9583DULL, 0x6C70772D55E1B078ULL, 0xFBB415090F9A3417ULL, 0x5CD8FEF1BD9D9309ULL, 
            0xD9979E62A9B46CE1ULL, 0xE25AD8B3AEBF8E7CULL, 0xC455A334F07F01C6ULL, 0x362723D1702943E8ULL, 
            0xB49C4FB298B4C444ULL, 0x8735F5904A7386F6ULL, 0x8C4B37F205871CF2ULL, 0x3035FF53A2308B8EULL
        },
        {
            0xA077873E3C291C22ULL, 0x96ADB3D7E653244BULL, 0x9714FB37B8534791ULL, 0x5E5431F5AF727944ULL, 
            0xA0E8B7388624F1EBULL, 0x6208582C135163B3ULL, 0xD3F62417E6550164ULL, 0x5CB526784A552A25ULL, 
            0xD259EA73C801DBA2ULL, 0x6F8D8372DFBC235EULL, 0x8CA73325789B0562ULL, 0xC4A6CA46EF976AE5ULL, 
            0x2A8029AE69AB1671ULL, 0x3F86FEFAE69CE3D9ULL, 0xFB480841C35DB1ACULL, 0x11EFE0B47E5E01F5ULL, 
            0x49696FD220C6EE4CULL, 0x4E81D0BFB65A4858ULL, 0x4075D2A07F04EEE2ULL, 0x87614CA4D42C8328ULL, 
            0x00520CC8466CCFFAULL, 0xCE825EADEAC93CCBULL, 0x401548EBE6236B06ULL, 0x3D2F747A45F0E631ULL, 
            0x05C1E04F1CEB71FFULL, 0x1853C72FB8B17FEEULL, 0xB611084CCEA05652ULL, 0xC73B1FDBE61BB0E3ULL, 
            0x01B82469E7333928ULL, 0x161628429D769BC6ULL, 0xDA27D41FB6FBE475ULL, 0x10056E515D39CFA1ULL
        }
    },
    {
        {
            0x1E108C22196BCC6CULL, 0x2B656ABBD4EB37DDULL, 0xE6D4B077B73BB757ULL, 0x233C2722CBB5B42FULL, 
            0x5BD07C9A02727FDAULL, 0x6C6267F7BB4C484FULL, 0x483A11DAA6B9B41AULL, 0x823962B48162E820ULL, 
            0x3D27D93D3EEB38D4ULL, 0x5E9B4B71EB1EF133ULL, 0x7136A05A3850897FULL, 0xFB641875D87E0A2CULL, 
            0xFD42FD3E2F932D44ULL, 0x479CDAC15C9DBF2BULL, 0xBBA87AB417EC49D4ULL, 0x857357A9BC0249D4ULL, 
            0x04EEA2CDAF774132ULL, 0xA12A14D7DBC5E4D8ULL, 0x8CEEA2323A0D1174ULL, 0xF836582DD151AEF4ULL, 
            0x21AAFFF7C998CD18ULL, 0x31D24D0C229CDF31ULL, 0x21AF656038032ED5ULL, 0x05AF659A80B2977AULL, 
            0x12F83318832B90D5ULL, 0x2EC5FAC0AE35EA50ULL, 0x61C615E03EC0EC39ULL, 0xC9543496539DF77DULL, 
            0x0768BE73E0717D51ULL, 0x7489B32754C54863ULL, 0xE11513CD4C48DC84ULL, 0x657C47289609DB5CULL
        },
        {
            0x4C97B8B5BB2E7C7AULL, 0xC2423F6D2DE55AEAULL, 0x766CD36F94765583ULL, 0x5CA706EF94B89B94ULL, 
            0xDE9C265B1E6EEE24ULL, 0xB0C9A9398C890267ULL, 0xC9BA1F25E692C254ULL, 0x387AD15F2B02B0A8ULL, 
            0x68710C7BF675380BULL, 0x9989B2B3D6F78A28ULL, 0x666E1811E47B9FE3ULL, 0xE2AF2FCB9E845993ULL, 
            0x041CBAAAC63F5394ULL, 0xF3DDCCE135D3794BULL, 0x15AB38E47222044FULL, 0xA1C5154691FBE75CULL, 
            0xD7CF5572B8EE0614ULL, 0xA08ADE75814883EBULL, 0x5AF63C81DE918589ULL, 0x6F82BF277294D4C4ULL, 
            0x80730CEC8815B8F8ULL, 0xBBB7C71C83C68AE4ULL, 0x506B34AF9EA7887BULL, 0x59AB2383C0FDE6CCULL, 
            0x82C839C03C0011E1ULL, 0x4069D5666181DF59ULL, 0x3D482C616E02BEB3ULL, 0x39A810F38C3E3627ULL, 
            0x8760D0F94F3F5678ULL, 0x093114AB1A0D5A24ULL, 0x1F9F98481ED6B3CFULL, 0xC4F2977F5422CD63ULL
        },
        {
            0xD77F612FC14D7E0CULL, 0xF3BB3B53C64451D1ULL, 0x6187E7BBE7E140EEULL, 0x3B378F6C36E9AACEULL, 
            0x606A8DDFD045A4A1ULL, 0x01E26BA7D3D4CE45ULL, 0x0D2ADAD9287FB72FULL, 0xEAA2702960B87983ULL, 
            0xB37E41173198F6F0ULL, 0xB0DBC2C29BAE01C1ULL, 0xA29AC4EB97BF5DA5ULL, 0x43B4A9613F4B4597ULL, 
            0x428F0B63B623B791ULL, 0x0E89F66DEE656538ULL, 0x89645AD35FD4E81DULL, 0xEE954EABB4799972ULL, 
            0xBF1ADB70A1B9086DULL, 0xC4ED4F7C701B3CCCULL, 0x911814463437A3F8ULL, 0x7A8E327431D0C974ULL, 
            0x8E89113919CC6973ULL, 0x6B7BE6E9FEF60DFFULL, 0xD5F21CBB313620F4ULL, 0xB606D6B727553EAEULL, 
            0x083A91663BBF9628ULL, 0x452480D9536E4A79ULL, 0x590A02B8AB22B9D6ULL, 0x14B422952F21C954ULL, 
            0xCBB6102A98ED115DULL, 0xD784C48832F458C1ULL, 0xB574DF0A7D98439BULL, 0x9C350034DA13BCAAULL
        },
        {
            0x2E507EC3608808DAULL, 0x097BEB896079E161ULL, 0x8600B89D9A9966A9ULL, 0x238A2F5E6346FD3FULL, 
            0x78DA46B13926C795ULL, 0xC9057741D82F14BCULL, 0x0E7DEDC3B3107D5DULL, 0x31987287477EB53EULL, 
            0x196B6955CF257769ULL, 0x4F7190442E20D13FULL, 0xC90DC1570F3FEBFFULL, 0x86AEBCBEE9579A1BULL, 
            0x739F09A372893133ULL, 0x738E94C51A677005ULL, 0x704F027CCCAFC009ULL, 0x9F1A72CA8B0BAC5CULL, 
            0x7C4EC88D58A0E9B7ULL, 0xFD245CC6952CDCE8ULL, 0xC5175A5BF858F12AULL, 0xE3A487CAF183C23CULL, 
            0xB04E8540ACE9DFA4ULL, 0x911019167422F39DULL, 0xFFDC7C60D76AD0AEULL, 0x17515FFCE7577A76ULL, 
            0xCB90D84815058811ULL, 0xC37B4E7D40593CF0ULL, 0x90FC935DD936E9DAULL, 0xA12BF1559FC869F7ULL, 
            0x5FC2BB2F580E35F2ULL, 0x7DD9DE9B06ED284DULL, 0xD384E18CB7FFC2DBULL, 0xFCEBC005B3F95FBDULL
        },
        {
            0xF4577340E24D975FULL, 0x1B050315C934A1B8ULL, 0x58A50D57229E3EBAULL, 0x995B50B21EA51248ULL, 
            0x6DE2C491091E1225ULL, 0x419ABC7C643B4779ULL, 0xD188B52829FDD04EULL, 0x2F0CFF546B3CE066ULL, 
            0x7C2C883126C8D20AULL, 0xED2E14B9FB937B69ULL, 0x684ABB712226E1FDULL, 0x6804018868E20FECULL, 
            0x59AF78838ADCD465ULL, 0xBEB0FDD65FBDE97BULL, 0x5E2A2D27BC9D7531ULL, 0xB2FFF499F028A139ULL, 
            0x3DB83E6E4BE510FEULL, 0x4A3D37766E8969E8ULL, 0xDAA6B26E6DE5E236ULL, 0x359C842E0B4B296DULL, 
            0x8E04F3C1F0DC1DC9ULL, 0x1BFAC6BCA2A4BCC8ULL, 0xF57AB67B3EDF7092ULL, 0x5C1E350048642D2FULL, 
            0x0866F3D310256642ULL, 0x23699F7745CDF96FULL, 0xBA729F41BE6FAC31ULL, 0xA1F4555B223D732DULL, 
            0x8A9CAF0BFFAB1E72ULL, 0xE508E5F76B105389ULL, 0x4AA6EE4EEF2B7689ULL, 0xD799BDF09226CC05ULL
        },
        {
            0x0A88C258261B1713ULL, 0x1189C89CDB4598E7ULL, 0x703DC692EC2C3B1BULL, 0x8840DF8987B63CDCULL, 
            0x6019CC08C8EA325FULL, 0xD8575B1F793809C1ULL, 0x6A657AA5B06ED7E7ULL, 0xF5EF12B82D58AB23ULL, 
            0xFB98C3FAD7056DBDULL, 0xFD9CD01F4066E486ULL, 0xA03F34E9D72B74A3ULL, 0x8228B483AE4AE9C2ULL, 
            0xA8663EFAD32CA7FEULL, 0x6A6BF6C03751577AULL, 0xF85C36ECCE4EA4D0ULL, 0xF5C2D9F01E1754A4ULL, 
            0xCFBAE1C3F4E8A36CULL, 0x9AEB545345CBD7BAULL, 0x4C74A5F0AECDD0B7ULL, 0xBCBB4EFF392E2846ULL, 
            0xC91A5CF0F6F1EB1CULL, 0x28A5F8B5486ADDCCULL, 0x41CFCCB49195D14EULL, 0xE4D3906BB28D03B4ULL, 
            0xCBB68CF0C85EAF40ULL, 0x0F2A900C429A7A9EULL, 0xD9A1C31C7E7D11DDULL, 0x1ADA180AF7BB64AEULL, 
            0xB78A868714BE6D00ULL, 0x1F49B01D31CD4C51ULL, 0x6DE8AA04B6396DB0ULL, 0x387F4353319A6280ULL
        }
    },
    {
        {
            0xBED3180FC5DF1655ULL, 0x2D07FCFEA593AC88ULL, 0x1BD61C4CBF6D7054ULL, 0x073511A788574FF3ULL, 
            0xECFA6C4FC5CC2E84ULL, 0x6790D43391836FC5ULL, 0x6BAC3487DD3C56EEULL, 0xA49FF870EFFDC030ULL, 
            0x81B28804BBC9A6C9ULL, 0x55C6AEB878BD9177ULL, 0x7D36FAF899C50EDAULL, 0xB6DE9E0FA200BAEDULL, 
            0xA6DD345FAF417E07ULL, 0xED513A50B0FD8C96ULL, 0x2DD70BD54D2CDC90ULL, 0xD1EA725466930A24ULL, 
            0x908629A8048885EEULL, 0x81E6A89CB97F8179ULL, 0x557156F5711165EBULL, 0x2090BF2A9F6447CBULL, 
            0x7C8B05C2103FBBD4ULL, 0xC80ADE0BA850975FULL, 0xBC73BE60F00C5046ULL, 0x4DABD6F235FCF201ULL, 
            0x59F090A3EF105296ULL, 0x19A0B674F05DFF2BULL, 0x2FD19770CC582A98ULL, 0x2058291923F71BA4ULL, 
            0x9AF0D718B0D69AD1ULL, 0x802D677BEE529699ULL, 0x084A8AB0EA53EE5DULL, 0xB4F95840C514DE3BULL
        },
        {
            0x1ACE9100BFFBE1C3ULL, 0xFD255C1140EACF69ULL, 0xCCE681AA5A574168ULL, 0xDBB3E80232365509ULL, 
            0xC3EBA3CBB3443D27ULL, 0x6DE08D1B989E495BULL, 0xD933E091D686ED9FULL, 0xB2D3EAA6D4BB7E39ULL, 
            0x975181D418A11363ULL, 0x99F27D4D416F46B5ULL, 0xFC5594501531DF36ULL, 0xDE69EB2F7796D76DULL, 
            0x5056E924A9F5C1CDULL, 0x84D8F715E3B76906ULL, 0xCB004DE8E926133EULL, 0xD979CE7C24AB0DF4ULL, 
            0x29DAB388E827C996ULL, 0xF5075670646B9498ULL, 0xFBD50B45BBF5FAC8ULL, 0x5B301F27F0936132ULL, 
            0xADE1A4FE5BA8E4C1ULL, 0x7772893DB85144DAULL, 0xCAE9D05047C3E047ULL, 0x709C2A93D4967317ULL, 
            0x14FEAF21CFC00C93ULL, 0x539B0A2ADB781C95ULL, 0x3C501D7895BBA521ULL, 0x54F1C941DDDE9D44ULL, 
            0x1B7661B30CFB925EULL, 0x5E92C8E93B4DD0E9ULL, 0x15316AC1330B9A05ULL, 0x831B0A7A9F4493EEULL
        },
        {
            0x64E61240E55D8E24ULL, 0x164DE741DA2A474BULL, 0x39AE423CF6D35703ULL, 0x2ED48B838D91EB4BULL, 
            0x9B5527BBB48A028AULL, 0x53050CB5EB53D77FULL, 0x06269EC3A157C261ULL, 0x697BC17E151D1F74ULL, 
            0xA109B939ED51BB5CULL, 0x90F086351B65F0C7ULL, 0x21C3D320A56DEE8AULL, 0xB81DE1F1A21C2F4DULL, 
            0xF63605CB8DEB7C66ULL, 0xDB83887D4E13CD3EULL, 0x6ACBBFF5D154F9A9ULL, 0x807C949C02BF71E9ULL, 
            0x2A031E2CD53F758AULL, 0x234697A474307CB0ULL, 0xC7695FBF5AD70668ULL, 0x3D75DA28AF2C3590ULL, 
            0xD147EDDE61BCC001ULL, 0x84EC055DCA4E414EULL, 0x2250DC0B7E4563E5ULL, 0x21779673495C13F1ULL, 
            0x5BBB3ED97149E1E7ULL, 0x13807308BF04EA54ULL, 0x9F51A08865644630ULL, 0xCDE39DF5E066C70AULL, 
            0x1B364CC0EFD053FCULL, 0x8715F8616D4EC93EULL, 0xA85F8492AD0298FFULL, 0xD9C935438C458A8EULL
        },
        {
            0xA8B7EAD28D24F433ULL, 0x84E41BE2E2EAB54BULL, 0x9C4C83843733F4F0ULL, 0x9B606EFB01D4277BULL, 
            0x08BF2A827656A515ULL, 0x0832F1FC609C92DCULL, 0xAFFB00F4C180F297ULL, 0x88CF40170448B1C9ULL, 
            0x5F75462834433598ULL, 0xE25AA4F73C185221ULL, 0x58F95752DBF5B8ADULL, 0xDA376AECAD6F0CAFULL, 
            0xFDB93F4A9E381F53ULL, 0xFD454E89B771F980ULL, 0x3DB3B4FA24911230ULL, 0xCD3D82E608D546B9ULL, 
            0x1271C1183A1A4953ULL, 0x474E5BBD0D09B0EDULL, 0x3D3DA9A4709AE8C8ULL, 0xF5576B5246812ADFULL, 
            0x2E18B2A0A16F5109ULL, 0x15CDA011B8C54832ULL, 0x2DEFAC3335ECF88AULL, 0xA9A2B7C4432A4514ULL, 
            0x02518E6E1E25C6AAULL, 0x75B7FBA3E1250609ULL, 0x3A018AE5DEEFF808ULL, 0xD639F0AE4AADDF4CULL, 
            0x82AD26A7619A9042ULL, 0x949E3A4D4A4BAD21ULL, 0xEA2432B1083B1A4EULL, 0x3E866A8E33C1DA71ULL
        },
        {
            0x2E46AFA81CB87128ULL, 0x0B258D767D73B17AULL, 0x9F6B1D52B2D15940ULL, 0x71112CA90448E3D9ULL, 
            0xD951768A0EDC160EULL, 0x75E0D2488CFC162CULL, 0x593B40B6E4214590ULL, 0x31DC0A3774E26D49ULL, 
            0x31D408DD94C2A06EULL, 0xCDB09CF4F162A251ULL, 0xD314C2C6DD08210EULL, 0xEF1EE0B702C50418ULL, 
            0x177E6DF5FF5562D3ULL, 0x489DF2BFD86AC8F5ULL, 0x428082868369450FULL, 0x17E1C64196CCB1F6ULL, 
            0x2234704BFECDEF62ULL, 0x2D38ED09F3D89806ULL, 0x6E71E6F44A789101ULL, 0x8A8AE46167ED55E4ULL, 
            0x85657A7DB77121AFULL, 0x86BFDF644912CD25ULL, 0xEBFCCAD875CCFCC8ULL, 0x182E2A1F676A8006ULL, 
            0x56B8EB7A38779565ULL, 0x765586263248F311ULL, 0xE20B8BD2765DA752ULL, 0x4CD9162755DB9186ULL, 
            0x8E6E597EF5B0F583ULL, 0x931B3871B0E3CC6CULL, 0x4BFC3E37422DF560ULL, 0xA4E92D381B40A7B3ULL
        },
        {
            0x67E902FB63E54CAFULL, 0x8EF3CA6B0761DD75ULL, 0xC3200338AD84D383ULL, 0x03F9E53F966BFBA7ULL, 
            0xA5E2AEC5C7CC7CCFULL, 0x03CC5F853401D274ULL, 0xD9AF6495D27C8E34ULL, 0xE803FB026DA33A49ULL, 
            0xAF97B6C2A682E7DFULL, 0x2A3815E8262299BAULL, 0x1B74EEDAE0CD566BULL, 0x38D264796705404BULL, 
            0xD740E1CBEF4617A2ULL, 0xF89CFEBA040F61F0ULL, 0x62D4F4A39BB1C390ULL, 0x6BCCDE3949A7996AULL, 
            0xE1E90A36F6ABD9ECULL, 0x33FB93F40E61B53AULL, 0x12454B60C06E0DEEULL, 0x84F177316867BA17ULL, 
            0xFDA089BB682ADCBEULL, 0x721633354A9E5812ULL, 0x03DF5AEE01168A78ULL, 0x76EC0C9D01111097ULL, 
            0x53C5C50324FCBC02ULL, 0xCBB6E6E211400C38ULL, 0x24D996C1FC0A350DULL, 0x3E28283088DB58BDULL, 
            0x7C8AF3AA7F335033ULL, 0x97DBF571CB668CCBULL, 0x4DA632878C15E5D3ULL, 0xE196A7771041E5A5ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alioth::kKeySpawnBConstants = {
    0x5310F3EC93141633ULL,
    0x6287F7C2DB7A3212ULL,
    0x56742A64A245AC96ULL,
    0x5310F3EC93141633ULL,
    0x6287F7C2DB7A3212ULL,
    0x56742A64A245AC96ULL,
    0xA03624F620336A61ULL,
    0x5BF3592E97225923ULL,
    0xD2,
    0xE1,
    0x4A,
    0x2C,
    0x62,
    0x85,
    0x7F,
    0x5B
};

const TwistDomainSaltSet TwistExpander_Alioth::kSeedSalts = {
    {
        {
            0x74A524004E2A8677ULL, 0xB67BAABEBC978EC2ULL, 0xE6C8669E4FFC374BULL, 0x7AAE7277CE691BA8ULL, 
            0xBE5C881442CEACFEULL, 0xB6ADCB66B68BA213ULL, 0xDFBE6AE34FD7FE6FULL, 0xAE10E1CDB7C6A834ULL, 
            0x27E763ABDC698F60ULL, 0x5DF385945EF48A52ULL, 0xB433C4B6250A9FA5ULL, 0x53F2FCF5418D7D85ULL, 
            0xC59D136EBA255257ULL, 0x32C2A634B6058607ULL, 0xFF6CA70E6F0D3B4CULL, 0xE640E44989813CDCULL, 
            0x267AD9EEEDDA7A18ULL, 0xF11E75E11FFFDE2FULL, 0xD8C7D8429A1B448BULL, 0xE520C3B9002C27EFULL, 
            0x91418B50D8D20696ULL, 0x91C96F8CB6A87DA3ULL, 0x93B735EEDE27D372ULL, 0xDC6C2B20E170FC29ULL, 
            0xD1B4ADF03EBF3E22ULL, 0x22F907C73AE2BB6FULL, 0x98682C761ECF9206ULL, 0x22911A63DAAD2561ULL, 
            0x6B9B489AE3FCB254ULL, 0xA6CD86C7DA4648EDULL, 0x1749FE91A230E3D2ULL, 0x8F03915D210B370CULL
        },
        {
            0x5793A2A453D150CCULL, 0xC30E27C04E8BEA6EULL, 0x988E3495C434C414ULL, 0x1ECE28836DFC93E6ULL, 
            0x3091FFAC931E8E10ULL, 0xDCFA37798B11D7EEULL, 0x61F49D301F56BFD3ULL, 0x455F217602DEB5C5ULL, 
            0xD0925F29027E7274ULL, 0x0E612C2106EED498ULL, 0xCA17030643A49643ULL, 0x5B50528869DD21CCULL, 
            0xA13A2548333C73BCULL, 0xE5BC7DB2671A49ADULL, 0xFA87C6DFABBE45A8ULL, 0x66EEED9084060695ULL, 
            0xF67D37E570C7ADBCULL, 0x7C67A5FEA23E7584ULL, 0x0E4B7ED74CEE5FF5ULL, 0x55963E280B96EB13ULL, 
            0xA0660CD3AD8128BBULL, 0x1013E3C3B702BCB6ULL, 0x15727DDD09715A30ULL, 0x658ED7F205BDD70CULL, 
            0xD5D84286A055454CULL, 0xCAAAD6907C638191ULL, 0x1343B4C0BC6EDD8BULL, 0x604E7DDB1F7E7FDAULL, 
            0x5B50C6B5876955A5ULL, 0xD9AA85DBD94EE057ULL, 0xBC01E120281F1F56ULL, 0x713F193D2A9D7F7AULL
        },
        {
            0x56CF17682D2323A1ULL, 0x2AA3F174A908584FULL, 0x6020D8561A2872ADULL, 0x89DBE03904B79F73ULL, 
            0x8DDCC1CD8EE4513BULL, 0xB1CAA8301F31C363ULL, 0x64632FAFF79A650AULL, 0xBB40FC5304CE3DF4ULL, 
            0x56084AECDD42F518ULL, 0xC0394D945A634728ULL, 0x068DE4E57EC056F3ULL, 0x1B0BAC30422C7971ULL, 
            0x95B8E80AF972B8C7ULL, 0xCD2592F46C5C29F0ULL, 0xC92055868842B4AAULL, 0x5C9EF5CCAECC6BF2ULL, 
            0x34F12D6F8240E4C4ULL, 0x234FCB8564F49F57ULL, 0x43658B1C8C201076ULL, 0x62F1292C54AB90A2ULL, 
            0x8D402AE17212F396ULL, 0xF05FC977E2F3E8D1ULL, 0xB7523D8B9077F014ULL, 0x9F287AE822DF3042ULL, 
            0x3C8F52F81FD46BD7ULL, 0xB2679ACB4EE4B5FDULL, 0xD395F7433EAD6CB6ULL, 0xD2980F0952059865ULL, 
            0x9321F2914361C028ULL, 0x00C36B631C936C7FULL, 0x733537E4D0657962ULL, 0xCDD8E98FD49EE86AULL
        },
        {
            0xCAFA4006C3F7B0FEULL, 0xDE5433185F007C15ULL, 0x822A4EB8030FE43EULL, 0x71BF37E6D7537A61ULL, 
            0xF6E5A505AB697EF5ULL, 0xB68F55E138E71632ULL, 0x2697639F8AC8B4A8ULL, 0xC864F1FD22C78D0BULL, 
            0x5DAA0C316CD6DE89ULL, 0x4C538123EE1114F9ULL, 0x0629AD7A0BACBD77ULL, 0xC45010170B5177D2ULL, 
            0x27F6E71338EA7284ULL, 0xBB8A47DD556740F7ULL, 0x7AAE0D4BDAD83820ULL, 0x4001DF57BF3B04B4ULL, 
            0x56B50D60FB4EBFF1ULL, 0x9152536983865CA2ULL, 0x2C4345EB8BF32B36ULL, 0xBA539C474FF2AF81ULL, 
            0xA1FD9405DBBCD0B6ULL, 0x79A913A4C3E2E6A2ULL, 0x4BF94DB374EA5CE2ULL, 0x57FA4A34C0194817ULL, 
            0x5E38B2A9B11F4867ULL, 0xD42B92F8E9D62D6EULL, 0xA0D1F6AF9429AE25ULL, 0xB2141945048E4A4FULL, 
            0xCA3D32CA45F757BDULL, 0x282D6418854FAB8AULL, 0xA8526785FA540C3DULL, 0xC49254441C022790ULL
        },
        {
            0x50DCB937E4C54A8DULL, 0xC75912BB63300F7BULL, 0x370BC2B37625A538ULL, 0x19F16F00280AED01ULL, 
            0x8582FD21175F4E61ULL, 0x8830E4B8D8F39DEBULL, 0x8187C5B2A97CD94BULL, 0xB7E0127B5E8757CAULL, 
            0xE06159BA7FAAF867ULL, 0x6BF99736C64C482BULL, 0x4189A9D029C43072ULL, 0x077762B2466A3B7CULL, 
            0x6AECAA805EBB9650ULL, 0xC6D521A57E96B22AULL, 0x630A3EE4FDB7DA78ULL, 0x3F711694DD27C20EULL, 
            0x259BBFCC00094A34ULL, 0x0438DAC58E01C918ULL, 0x395CE199BCE5E476ULL, 0xA9035E22673F4C1BULL, 
            0x2CA9B3024212847AULL, 0xAAE942F3D0285E0AULL, 0x3015955F3B6CCB34ULL, 0xB3F9C4AAF96375F2ULL, 
            0xE6127AEAF8739A24ULL, 0x619FAAB0E17F7C69ULL, 0x2751BF6086776973ULL, 0xF7272918513596F3ULL, 
            0x4E6E2D41E0E09B9EULL, 0x52BC89286E2CA513ULL, 0x72865856EAFC3E42ULL, 0xF638159CBAE28FB3ULL
        },
        {
            0xA39B23F601D31B77ULL, 0xBF2194F282057583ULL, 0x28D3E95B4005A0A0ULL, 0x32331FA7269AC9EFULL, 
            0x5CC4272DB7A9FFD2ULL, 0xC8CA5C2502E4AEBAULL, 0x250789B10DAAFEFFULL, 0x41E49C654B31C9A8ULL, 
            0xEF6B9B5CB26B5033ULL, 0x16CD5767435B9C81ULL, 0xD57832DD2004786EULL, 0x972810B35E31D8ADULL, 
            0x8F998DF25CBFBD9EULL, 0xCE18933BE9A062F9ULL, 0x2661CA03D1B0E1A7ULL, 0x9ECC95460CDE9692ULL, 
            0x597613F9B532CE27ULL, 0x641BDFF96C9C142FULL, 0x307FFAC4D7E2A5A0ULL, 0x50655F471ED5CC93ULL, 
            0xFA8EC52BADFC98DCULL, 0xBFFA0847A9E98ED1ULL, 0xE9FE55E89A7CBEA4ULL, 0x61A641E83C3DFB09ULL, 
            0x59CB13DB7B44317FULL, 0x5AF75DCBADD6C4B9ULL, 0xD238A788131D572EULL, 0x90C893DB87410F90ULL, 
            0x56C06CEC6C965B9AULL, 0x717249B3A31246CEULL, 0xF6AEC3762DDD45F2ULL, 0x525F6DC04C5DD4ABULL
        }
    },
    {
        {
            0x05F9ACC770212F60ULL, 0x9B3122CC8290C131ULL, 0x2A47AE7B77FD9092ULL, 0xA0DFF9DDCBECF366ULL, 
            0x632BC754820C28F1ULL, 0x150111643926A4F7ULL, 0xC76CF3FCBD049D24ULL, 0xE3EC11246184540AULL, 
            0xCC5DF4D4BCE49179ULL, 0x00B86C8D4DC81BEFULL, 0xB5CA85E4159AD8A3ULL, 0x86DF4123E5A72A5EULL, 
            0xB9D55853513F3394ULL, 0x8F892085E8921A4EULL, 0xBB472A5F298C424DULL, 0xFE92FEFB414C483DULL, 
            0x7535C23695C62FE7ULL, 0xE89361A1CDC10E86ULL, 0xCEE7295931C1D601ULL, 0x57871707497F8B79ULL, 
            0x734EF6C31BF54E9BULL, 0x27CBDCE5E208BEE4ULL, 0x885E76A81B105AECULL, 0x207085D638B5040EULL, 
            0x827B0C013968063FULL, 0x1BCA8745DD075232ULL, 0xAB44615CB1CCD0E7ULL, 0x25FB1A6C2BEC00EBULL, 
            0xA274D3049C1E75A9ULL, 0x42814E62841E8415ULL, 0x9E616CDA6A617978ULL, 0x910CACB2E6D5DD00ULL
        },
        {
            0xF7689A8AE3A15B91ULL, 0x28B9A034E70A995FULL, 0x22D5970E9B3D87EBULL, 0x0C71B2A512FDADB7ULL, 
            0xFB7AD967AF1660E3ULL, 0xB94CF08335F0B40DULL, 0x563AA1FF1210E041ULL, 0x94AC002AC8AF920BULL, 
            0x9781541EA2B811C4ULL, 0x396018AE2D8F223CULL, 0xF693ADD44384392BULL, 0xDA9777087A44BA44ULL, 
            0x5DD87A86C743B21EULL, 0x3F5359A81B00C2E5ULL, 0x79F8A0E34AE73655ULL, 0x5822995C4A83E867ULL, 
            0x7E4DEFA38C8C15FDULL, 0x0D013D9108550C21ULL, 0xD5BC163BC7602806ULL, 0xB2C80467C6C59A31ULL, 
            0xE55770DBEFCC9053ULL, 0x95EBF66F45C63013ULL, 0x31DB63C0755960C2ULL, 0x31CA6BF69277CBEBULL, 
            0x79EE7EE465AA5F49ULL, 0x1C2002A05E994CF1ULL, 0x632112DE1B1A9E2BULL, 0xD3853AF53295768AULL, 
            0xBA90E4A0C40FCA83ULL, 0x1EE117E65E67B654ULL, 0x438062B3ACCAC1D9ULL, 0x1B5680F690C9605AULL
        },
        {
            0x7531E8AD2D1B8596ULL, 0xA53F1BA17985BF7BULL, 0x27110F8B4AAE7F41ULL, 0xDE8BB737CAC24788ULL, 
            0xA1D3ADCD78500A80ULL, 0x76CAB0C58ED21091ULL, 0xA83903901BA30C83ULL, 0xBDB66802773A2537ULL, 
            0xDCABBF113BAA3994ULL, 0xECFAB4B89A7A49C4ULL, 0x6EBA1326F283EDEFULL, 0x46E56CB6732C966AULL, 
            0x7E64C8DB0C86B1C1ULL, 0xD72082F131B64DC5ULL, 0x06376D9480767F0DULL, 0x7A3A47D0A33FD29AULL, 
            0x69C5B00341C69A62ULL, 0x2B93E983CD667671ULL, 0xE899FDC3B8DBA934ULL, 0xCAAC671F7DA78143ULL, 
            0x3D959761777283A6ULL, 0xE990A73AAAA3C907ULL, 0x17BDC0EAE3DBD2F9ULL, 0x1C8F0A786E87DCD5ULL, 
            0x65420F7FFB7731CFULL, 0xEBF279DB918047CEULL, 0xD83831309E426EADULL, 0x4E8CEF1EA072BB9CULL, 
            0x0BCCDC2F03192880ULL, 0x4BC2F59F2287DD8CULL, 0x03B6FF9E7F0CF7B8ULL, 0x56061BBB6ECD2AF8ULL
        },
        {
            0xA41B990BB1EC7DE4ULL, 0x5236C99BF567EF76ULL, 0x22794CBED225AF00ULL, 0x054648868DF088E4ULL, 
            0x3E6F564DE3D3EF5AULL, 0x12041D78BF54A7EDULL, 0x08677BA2759092F6ULL, 0x31E49F43DE33463EULL, 
            0x34B9B6299739A410ULL, 0x54748B50E3CCD96BULL, 0x2F88B88A83C40297ULL, 0xF1084B1CDA4A9DECULL, 
            0xA85B38906E855F14ULL, 0xC0C5131581EC1CD0ULL, 0x78582E918D59F20DULL, 0x006D2EA4CB26FA83ULL, 
            0xCA7F7E984DE45AC8ULL, 0xBD2C7A09F2717901ULL, 0xD5BCC44ABF24FB55ULL, 0xEAF8E34728838665ULL, 
            0xA5D3486CD10696FFULL, 0x984C44ACE5B32D64ULL, 0x7A1B4D95B1F16A72ULL, 0xCEF1FDC958885D1CULL, 
            0xE75DAB7636BF16CDULL, 0x0872F2B59E71D011ULL, 0xFFF9EA5E63319004ULL, 0x5C022FEDE8312934ULL, 
            0x43C16AC83B3AB3A3ULL, 0x4A53A655B603650AULL, 0x5B00F06A51B5644CULL, 0xC59B8517F7CCC5ABULL
        },
        {
            0xA8C113BCCF18F6E1ULL, 0x14E88571525D2064ULL, 0xAAB1AF4D74999545ULL, 0x1E272D36A7A433F4ULL, 
            0x3E50A93CD11AADC2ULL, 0x65B65624A71F0B07ULL, 0x5B2A824D16680B9EULL, 0x0794DEB706C6C2DDULL, 
            0xBAB08AFDE81FCCBBULL, 0xC2B0A4A22831A242ULL, 0x115FE1C10F2BB882ULL, 0xFA087ABE1E6C2DECULL, 
            0xFB1C27ADBD75184FULL, 0x94EC78BAB91E4C9DULL, 0x18EF8B4B23331951ULL, 0xF07C2651793B2A0EULL, 
            0x879DD300B799DFB6ULL, 0xDD29A5F96C8F7B6DULL, 0x1B87411874D6C7E8ULL, 0x352F8B9EC63CAE18ULL, 
            0xAFA20AACEF0532C9ULL, 0x3410EB80BFEDDB5BULL, 0xBA0C3A9655EE38E7ULL, 0x50AE36433DE68199ULL, 
            0xDD890E4AFB8C530AULL, 0x6D0E66D142885BC5ULL, 0x6167B5B3CF2ADC7BULL, 0x435902CD17A2F8BDULL, 
            0x6A73F8C033AF0876ULL, 0xFC435D20BF78C570ULL, 0x04D73DF1D831F85FULL, 0x995FFD715D73846AULL
        },
        {
            0xCB25CE144F5D0975ULL, 0x81AD05C4DDCFD5B5ULL, 0xBA667E668ABEA3E0ULL, 0x4B1D785D6A346045ULL, 
            0xF88702EC3E001AA2ULL, 0x79DFB00A0F564C8EULL, 0x6A03493751CE4FD9ULL, 0x12C39B1D762A9B3BULL, 
            0x370A32F5BF18C281ULL, 0x721C0C4A698B9605ULL, 0x4FEADBB39BF8F82BULL, 0x1267E4B1A76C368DULL, 
            0x0061D99E6DC4F695ULL, 0xA8B367F0D006C513ULL, 0xCA432D8A5AD63498ULL, 0x2ABE6DE53116D90DULL, 
            0xAD0EECB8D0E259E6ULL, 0xC3076FEFD3DBB82EULL, 0xBD8ED0FE4BE57CF6ULL, 0x1A7790698C715F37ULL, 
            0x7E131FD53C23FD69ULL, 0x437BC978CF6AD7BCULL, 0x2BDFDA01F18D2855ULL, 0x88D90C5AB066EF07ULL, 
            0x3089837F91988EB6ULL, 0xD8BD943EC0C3737CULL, 0x505C43AEE55AABAEULL, 0xC0A6E5295586C211ULL, 
            0x4C321B05B3132D6AULL, 0x3CAABCBACBA51DDAULL, 0x0CABAFAC42D20561ULL, 0x3668E491347F5F30ULL
        }
    },
    {
        {
            0x6A1AA2DBF047127AULL, 0xE0127EF471F3A84FULL, 0xF9D175FD2F62969EULL, 0x02A7D652F28D849FULL, 
            0x398964235186D871ULL, 0x874849C5679EAC75ULL, 0x868B5F1AEEF04DCEULL, 0x1F2F10EA4B95928EULL, 
            0xC3B6C82A3F1357B2ULL, 0x3F2EC9BC43AD7905ULL, 0x902BADCB62F55912ULL, 0xCD8DEB42512FE445ULL, 
            0xE8A568FAA898D441ULL, 0xE8F33E22009038A4ULL, 0xA0B5DC18CADB56AEULL, 0x76A6AFDC89677510ULL, 
            0x99BCEFE6B0887FFBULL, 0x08243B9515606F99ULL, 0x9ACB9FD51831378AULL, 0x0D31AB94A5AF4440ULL, 
            0xAF0C9D479F2D6B99ULL, 0xE6A0DB5548705C1AULL, 0x4618E4288AA6CC51ULL, 0x221AFE510D5CF19CULL, 
            0x94BE5828B7FCD26DULL, 0x116AD3BF6FCCBACCULL, 0x9B2E1D7FFFF65463ULL, 0x47AE8B545B42EAFEULL, 
            0x62DED7DC3F396C0DULL, 0x9D0232AD120F234CULL, 0xB5D92CCC777052F0ULL, 0x179DEEB63E25D0DAULL
        },
        {
            0xC7CBD26E950C7496ULL, 0xC27694C730A1CD96ULL, 0xBCB55E3E6AA17379ULL, 0xB5A2C73656EDB37AULL, 
            0xA32F423F80E2B144ULL, 0x1D6F8A6ADDAF54F6ULL, 0x379A1BD2B02015F9ULL, 0x900FA4DA0193321CULL, 
            0x097274FBD343CF28ULL, 0xC2379DC487D336D5ULL, 0x3EE1BE96187E36E1ULL, 0x7BF1934C7BF37DD7ULL, 
            0xD62AF46ED40F8644ULL, 0x5E059A37B2FCDC58ULL, 0x8E67BC00549F23F0ULL, 0x78E2D2B069FAD1B4ULL, 
            0x7C16E41933776A62ULL, 0x1B3CBAC600D1082DULL, 0x0E0F56C469940935ULL, 0xBC6706187783F1FDULL, 
            0xC2B8D67610B531D2ULL, 0xFC21B0BCEC4D3D40ULL, 0x254F2D04E1948A46ULL, 0x68BF287DD91DCADDULL, 
            0xD779B1C76B1D12B2ULL, 0xCBDFDCCCD6E13E9FULL, 0x9EEBE9F54A2BB6B1ULL, 0x72E51E23A6C3547CULL, 
            0x099873EC4498215BULL, 0xBD3120E7ABDD5834ULL, 0x75E3C251F9F22545ULL, 0x7495C88A55A95EBFULL
        },
        {
            0x8570EA304AB17B06ULL, 0xBCA9BB9832B2934BULL, 0xC5D2E78BCBDD926DULL, 0xACDF21FD00CBE916ULL, 
            0x55430DDC500418D7ULL, 0xBF613D7B45D9F6E6ULL, 0xA0B2F96045053F7FULL, 0x0DCF3044E9D5EB8EULL, 
            0x7048D88F939B1330ULL, 0xDF7D234E8EE65291ULL, 0x10C8CE86988AA8D7ULL, 0xEF56885AC297B982ULL, 
            0x6B98BE53A6CDBD8DULL, 0x96B926D4BDBF871CULL, 0x1E417E07388C1D0FULL, 0xDF5F71707DD7C57DULL, 
            0x92C174070EE5E58EULL, 0x423F0805BEE5AE10ULL, 0xFCEAE3416EFD339DULL, 0x6E69C68752E4D086ULL, 
            0x738FFCBDF3489B36ULL, 0x6A22C756E9E86C33ULL, 0x70A9CE3C46382E89ULL, 0x692F6B7D5AEF5061ULL, 
            0xBE26A1559BB4E5E7ULL, 0x630088DA1788F286ULL, 0xE804359E3471F4F9ULL, 0x4F352016DCB00538ULL, 
            0xBEACF257152B26C5ULL, 0x2B588091FEBE3C45ULL, 0x3AE660132BCEBBE2ULL, 0xE8DF5AAB36C146F3ULL
        },
        {
            0x19F70F38738E9143ULL, 0xC69D02414AC6559AULL, 0xD019563727007913ULL, 0xA5715536F5AEAF01ULL, 
            0xAE0010262CE98B56ULL, 0x70F980FFB42B4920ULL, 0x3191845FAC61694DULL, 0xB102F85742C04CFDULL, 
            0xDB9613373A2F4489ULL, 0x523D0ED59136C581ULL, 0xBE44FE4CB099E0C5ULL, 0x9A41F743FBFF2B93ULL, 
            0xCD4F54909D066E79ULL, 0x1749AD11F6239963ULL, 0xD8F66665365E297FULL, 0x2D3BD16FD82FDB01ULL, 
            0x781760A04D641419ULL, 0xFA8904EA985822B5ULL, 0x3A00E7A6C1C7CE00ULL, 0xE44B3CD38E5C868EULL, 
            0x77E7766988A5C1F2ULL, 0x27348815DC39273CULL, 0xD96D055AB86530D9ULL, 0xF266988CB3198B64ULL, 
            0xCAE54027FAC396BFULL, 0x9885A58E23516182ULL, 0x5E216B8C9A9C9FA1ULL, 0x9499827030E8D091ULL, 
            0xA4751F0F4689B4F0ULL, 0x2D9AE39E3A8EF9D0ULL, 0xE29C90A1845643BEULL, 0xDF3E993B6A655A87ULL
        },
        {
            0xCEC8DE940B3ACA0BULL, 0x85F1EBD4DC7973FCULL, 0x129B45BB2CB8ED65ULL, 0xBAE96862A93F6EA4ULL, 
            0xB161746EDFA8E777ULL, 0x2023D3FBFB5860B1ULL, 0xD176B2FCA7A53EFEULL, 0xC36BD3636835B0E7ULL, 
            0x22E31BE09265359BULL, 0xFD36BF8CAE01DC33ULL, 0xE02812C80B568C43ULL, 0xE19F031BD8A3FE83ULL, 
            0xC1DC85016B2E11B9ULL, 0x5BDBBE8E1CEFA721ULL, 0x4EB882F61F4FA76CULL, 0x35805591D77A0B1EULL, 
            0x284926789246BF1DULL, 0xE645551EC87C2DEEULL, 0x5BA60CD8DF64E56DULL, 0xEDEE255F3DE4980DULL, 
            0x798B76D3BDD42355ULL, 0x7FDC9129F82FE0CDULL, 0x47B1B2009E895B40ULL, 0x48A877C916073DD9ULL, 
            0x8E66F438060D52AFULL, 0xDD654A7A701E3A0DULL, 0xE7C445310BEFDD11ULL, 0x7C3B1C30EB04DC52ULL, 
            0xE70A091921B42DE4ULL, 0xA1ACF0B133EA57E8ULL, 0xE690F6AE93936109ULL, 0x2441BCFFCB9CEF84ULL
        },
        {
            0xFD4F8C301C6959EBULL, 0xDD51DD6779C310CBULL, 0x64D9DB1D5F81AA92ULL, 0x5CCEC0C8B535A0E3ULL, 
            0x868C4E4C79EE92D0ULL, 0x30D3F44C2DC1C731ULL, 0xE0BA29EB73285D4FULL, 0x6352BF8FF3D4B413ULL, 
            0x59E904311866D479ULL, 0x3AA4E71DD5612C3FULL, 0x1A91840185E0F534ULL, 0xC067DD463FC5EA6CULL, 
            0x4BF8D90B29A84BB1ULL, 0xD78DC7B57AB6F720ULL, 0xD9D6B03CC760C30FULL, 0x6CF9F88355A0F536ULL, 
            0xBC524214651D7EB6ULL, 0x86E9E54D331B1E56ULL, 0x2DB4B26AAEC9ED95ULL, 0x8BBA2A044B31E357ULL, 
            0x917F294D525D56C8ULL, 0xE203C5DA62C975BEULL, 0xCD8C50844C4614D1ULL, 0xA57A81A9833F6E77ULL, 
            0xCDDA344840A894A4ULL, 0x683DB7606F8B4225ULL, 0x1F2EDC4F468C31DDULL, 0xA25D77634C96BC47ULL, 
            0x56E9221262D0A56BULL, 0xBB6740AC4230D075ULL, 0x87210F655B687A7CULL, 0xB3CE48EB68F610B7ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alioth::kSeedConstants = {
    0x0255DA4A85D9B560ULL,
    0x6D0E9B60FE429E8EULL,
    0xBDEFF21B2A65FEFAULL,
    0x0255DA4A85D9B560ULL,
    0x6D0E9B60FE429E8EULL,
    0xBDEFF21B2A65FEFAULL,
    0x4BF205C3BDE63AEDULL,
    0x5EBBDE8445AF5A55ULL,
    0x72,
    0x02,
    0x84,
    0x8A,
    0x9F,
    0x90,
    0x4D,
    0x3A
};

const TwistDomainSaltSet TwistExpander_Alioth::kTwistSalts = {
    {
        {
            0xA1C5C285DFB463E7ULL, 0x4C32806263E9620BULL, 0x6623082BA0926EDCULL, 0xDCCEBFA3833A04E3ULL, 
            0x414F7D58D81A0BE2ULL, 0xB6B70129D01CB513ULL, 0xEF2A3814A7DE9330ULL, 0x84078759F73EBC36ULL, 
            0xCB324670FAA22A3CULL, 0x4F439BA1943682D1ULL, 0xE321B7CCBA422223ULL, 0x9EF02D036EEB8B75ULL, 
            0x015F0C922756816EULL, 0x1A407417800E83E5ULL, 0x9A404A7BB7D11AE6ULL, 0x57EAE6E4027FC3C3ULL, 
            0xFAA223AAF1C36C3AULL, 0x9DD909F307DF6ED2ULL, 0x26D113A4A50121E6ULL, 0x836C69C994FE2360ULL, 
            0x112BD9BF911140CDULL, 0x6070BF0CEDD543F0ULL, 0xBB153CCFC3E12FBBULL, 0x889692A425F52294ULL, 
            0xE57B3419B96C471FULL, 0x77C26D10489D6A44ULL, 0xFBF3BCE54F47D5CFULL, 0x2C1485464E8B8395ULL, 
            0xC7DC0862C6F359A1ULL, 0xD3FF94AE7BC451CFULL, 0xDB11380D28355D70ULL, 0xCCC3B966E29F8BB4ULL
        },
        {
            0x1998B85474CB96EDULL, 0x9661AE10B9D30A32ULL, 0xE65F8211F26EEAE1ULL, 0x700DDD8E12F535A9ULL, 
            0xAA28E588547DC526ULL, 0xE9DD758950C6F4F4ULL, 0x5EB1AF1157EA24E6ULL, 0x4FA21CC50251A1BAULL, 
            0x8CF3CF38B3C1C2BDULL, 0x44BFACD9423CE8F5ULL, 0xD1A49054D7C01D94ULL, 0x61A16B053268795EULL, 
            0x78E1F56523B92470ULL, 0xABB3A4486C6A858BULL, 0x15EAEBB47AC34B4BULL, 0xA87FE8D71611B4C3ULL, 
            0xDC86FB1F0E5A8663ULL, 0x1CC617E870FED8B6ULL, 0x48C3AB1E3D188698ULL, 0xC48232BBBBB306B2ULL, 
            0xBBFF30B9FC672AD5ULL, 0x6D6FBAA73BFCBE8FULL, 0x73B6337F2A78CAECULL, 0x30D1E529F4B10C89ULL, 
            0xA528CC036FA6CCD7ULL, 0x2C3DE1B6C7E287F4ULL, 0xFD3CA279126F1AEDULL, 0xF0CF748A469AAA2FULL, 
            0xF78DCD6B36B88F3DULL, 0x6053C0CA79FDEC1EULL, 0x45A0043826309CDCULL, 0xC0BC127003C990B9ULL
        },
        {
            0xFF239FC64F3EB0A6ULL, 0xED76DE3923CA82E2ULL, 0xA2962CDDEF7655DBULL, 0x729EE991C94C16EEULL, 
            0x2CE37BD57240BA6FULL, 0xB9645D2C4C9BAF8DULL, 0xADA7779564705ACAULL, 0xF7B5D39B4216C1C5ULL, 
            0x50E9B44B211530E5ULL, 0xDB942AB24467E30DULL, 0x4F21B737BCCE7572ULL, 0x9A76B941DA47E470ULL, 
            0x92F77DDA25E64828ULL, 0xC823B0DBE0204DEFULL, 0x79AAE394F1533E37ULL, 0x6A87ABE2F052E3D8ULL, 
            0x688275C67FF596B0ULL, 0xD8B6D30FAC92ADFDULL, 0x6E13BBB840DB2370ULL, 0xCFB9FB6DE77B7695ULL, 
            0xF58EDAB33C73D6E9ULL, 0x1FC3262AE6495785ULL, 0x48885905F4D04E35ULL, 0x9CFEDA7D8C484B17ULL, 
            0x4D5875CDED042938ULL, 0xB9CD57E9CABBFF07ULL, 0xE56588EC40D728F1ULL, 0x66C3C962663AD4BFULL, 
            0x155AF9918C5515ACULL, 0xBA8AA9E2E5B5BB5FULL, 0xEAF3F58856CBC752ULL, 0x6038690079C79860ULL
        },
        {
            0x7D32B1372F71C9A3ULL, 0xCC9F93807612ED2FULL, 0x6464D632400524F9ULL, 0x7305E5C3E6019604ULL, 
            0x6A12AB5D4FE2E82FULL, 0x02C497CBAF1D3125ULL, 0xF91200C4EDD8FFD9ULL, 0x0A618603A759EE5AULL, 
            0xE900B0620D46415FULL, 0xA82B019519303D87ULL, 0x874AD9A8EB5EAFC0ULL, 0x402844AB5886BE24ULL, 
            0x2994B845AA682A2DULL, 0x238D2DBE0FD49E48ULL, 0x8B414EE1FBA60989ULL, 0xA60CE54C04210017ULL, 
            0xB88726FF73A2D1C4ULL, 0x2C75128101355AA4ULL, 0xDA2679F8DEB75281ULL, 0x06A3C202AFA69A93ULL, 
            0xEE6ED4B2B858A070ULL, 0x4128F9595303F9C9ULL, 0x4958698EE69DD6B3ULL, 0x6B57BF17482E5B82ULL, 
            0x040494FE11CD943DULL, 0x60074F29C0294BF9ULL, 0xEB57621212448145ULL, 0x7E1743031E74F493ULL, 
            0x748F3D80A051DD7DULL, 0xF39E0B67770294D3ULL, 0xC1FCEE1613270DD2ULL, 0x4DD7832AA72D829BULL
        },
        {
            0xCFA554D5DCE4756EULL, 0xA42F6CE7AB07F8D5ULL, 0xDA420E608992E022ULL, 0x85F9FF9D904B6A1FULL, 
            0x489E28A1F5583826ULL, 0x39AC0EB761A56B36ULL, 0x91ADFB72286B2787ULL, 0x83EDE3DD2C6A3A82ULL, 
            0x62E03908857085C2ULL, 0x1A0CE3F4D23D57ABULL, 0x982B91B76E79590CULL, 0x9A251B620B2FD9AEULL, 
            0x065F032B6F86672CULL, 0x19FA1631B9B5BE51ULL, 0x50B139A82E057BACULL, 0x354A367833EB735DULL, 
            0x1D73D36CF49A6B52ULL, 0x308E90C484FB2B86ULL, 0x426ED4D6DAE8C77BULL, 0x2093A4CA882F2C04ULL, 
            0x30FF0A976A6CF3A5ULL, 0xED43BCDD189490D2ULL, 0x2B84244EE7B67516ULL, 0x194A1ECA6F169855ULL, 
            0xAE4EF0F69ED89760ULL, 0xDBBE222374D9730FULL, 0x7D629D4BEE08C44BULL, 0xCA2ADACE1BA55F3DULL, 
            0x490D191051726BB1ULL, 0x0BD7A28C15ED6B7BULL, 0xC36DCBDF66C4EE77ULL, 0x6995117AFF9F0EFAULL
        },
        {
            0xEF6ABC0B45302C4FULL, 0xFEF9ADD7E5B654F5ULL, 0x43509E9593697AC2ULL, 0x8DD24BA339680C6FULL, 
            0xFDDF61807652EE1AULL, 0xCA7A6747783285B3ULL, 0x050CE3C44E9DFCECULL, 0xADF189A5D5ED9125ULL, 
            0xAAE443CF0100B9BCULL, 0x74DDE3A6A734497FULL, 0xA7842CF01925E70EULL, 0x840363721F6AC01EULL, 
            0xC59558E086BB9587ULL, 0x82E06ADC8FE8EAA5ULL, 0x1E19D0C7BED29060ULL, 0x08A9C392BAE95815ULL, 
            0x424D2145DE14CDB6ULL, 0x54A74BF7021EF2A3ULL, 0xC1388B30D696C3D4ULL, 0xE9FFEF38CBC76ADDULL, 
            0x6ECA09B68345C6B9ULL, 0xA2F6731153FFF658ULL, 0x3B36914074475CDBULL, 0x986293F5BEF7A908ULL, 
            0x52D0B91541C7C522ULL, 0xCCE0F42CFA9EC9E7ULL, 0xA41AC391455D957CULL, 0x2567829465D4F1E8ULL, 
            0x6E5DA48B3E4F7603ULL, 0x92A31F3C0D4F0801ULL, 0x4DAFE8C0C55E4080ULL, 0xCE01D833CD107CAAULL
        }
    },
    {
        {
            0x6497E6C908454EBCULL, 0x68C6A911F172E608ULL, 0x6A29DF97F9CE6099ULL, 0xC466AD6D5C6B6A42ULL, 
            0xE50EFDE5C799D25CULL, 0x285D350295894F13ULL, 0x71CC7CC27A2F69C8ULL, 0x46B272C47C43331BULL, 
            0xAA2FE8918AC36759ULL, 0xBEEE4B01618AEA62ULL, 0x038B489240B97BF7ULL, 0xCA404DAC36004983ULL, 
            0xBF711F54388C9F2CULL, 0x302A65AA277239A8ULL, 0x746534B1F35B196DULL, 0xBD07655DFC542889ULL, 
            0xEDEE45C4F9D7B333ULL, 0x73C42B697962EE0AULL, 0x35EC52360054C07EULL, 0x6F470BA4A345EA5DULL, 
            0xA96EBDC7E4008B24ULL, 0x8E3EEDDD3106FFEBULL, 0x65885EC922AD992CULL, 0x93C395746B5A59E3ULL, 
            0xB485461DE2E3610AULL, 0x1AC13926C9DFEAD1ULL, 0x5EE708035A18B78FULL, 0x7DF46D98BB0D9FD9ULL, 
            0xC65C4E3719049AC8ULL, 0x1107C69EEB9861C2ULL, 0x3A76110297EC9552ULL, 0x5820C078BC04D00CULL
        },
        {
            0xEC78BE7A87A3E16AULL, 0x7CBF118D4A3EFBEEULL, 0xBDB6F38A401F4A8EULL, 0x615B944B858BEF2FULL, 
            0x954B59C34F285A30ULL, 0x68139639CAE5C0ADULL, 0x6D1F827D81B6E32AULL, 0xF88DBB08152455A4ULL, 
            0x373138DFFE3A5960ULL, 0xB12EFB6868E9802EULL, 0xC97038E8F286E6A3ULL, 0x538814EC510D57DAULL, 
            0x7790F65F09B58B2AULL, 0x8F3E8CE784E41211ULL, 0x365E5ECD41921BC9ULL, 0x387FF5E1C6F00562ULL, 
            0x3C2DB61168F2F7DDULL, 0x6ABBFF463DD83382ULL, 0x7CC2AC9DC053519AULL, 0x477320F6C2164FBEULL, 
            0xB5A29B1BA2C76CDCULL, 0xB41A5E19FFA93CD6ULL, 0xAF23D5523EDE0E2FULL, 0x73361F79FB061E11ULL, 
            0x2363D032555C11DDULL, 0x6C6420594F81F565ULL, 0x910609E07ABAE0F6ULL, 0x81A819546D2274B7ULL, 
            0x1BED6B2D1FB1FE40ULL, 0xD821424E8495A41FULL, 0x4DA477D2C16D4CD4ULL, 0xA6411F27ABB296D9ULL
        },
        {
            0x856B39FA646810C8ULL, 0x06A68BD1CA2DF958ULL, 0xE1EFC24D8E055E13ULL, 0x4D7E65906DD3EAA7ULL, 
            0x901DF49F8283456CULL, 0x37C9E845E1E2BBCCULL, 0xF07DC21F7459D2A1ULL, 0x4F170265604DC36BULL, 
            0x85021A705FA6DD73ULL, 0x7A9E6BAABF47D685ULL, 0x420CD100C719D272ULL, 0x232B3EF11C3AF1FBULL, 
            0x36CF9578C1960E3BULL, 0x086C298CC01FB4A5ULL, 0xB4CD440973294F10ULL, 0x06A93DB7A55D4AF9ULL, 
            0x7376C71BBD828CFEULL, 0x9D8B843BEA49818FULL, 0x3330F468FB431CECULL, 0x6A3C6A97842305AFULL, 
            0x1BD72766AC0B8B0AULL, 0xCFEF43876CF860CBULL, 0x9E06815F28C65CC7ULL, 0xB990D74F551ADFCFULL, 
            0x1D57AC820D3ECA5EULL, 0x72058FE28BF427B3ULL, 0x79DB57EE7681C2C2ULL, 0xFE909089B1022474ULL, 
            0xF06965E0DD0BDA33ULL, 0x0D4E461BD2E10E01ULL, 0x1F98F11241EF6017ULL, 0xD19F7A40CE03E86BULL
        },
        {
            0x0F60BC75F1153F25ULL, 0x0AB3256030D91222ULL, 0x508D21E96FB707A2ULL, 0xBCDBBB49055A3E54ULL, 
            0xED0D0B5A1728D35CULL, 0xF817306D728AF952ULL, 0x18C507013F629ACEULL, 0xA3FC0693F71C8EB2ULL, 
            0xEED16BE2660A0ED3ULL, 0x6DA9F878CD96AE55ULL, 0x64923827C1FAA4CCULL, 0x197314E2052092BFULL, 
            0x4CEE7F8703E936CEULL, 0x3C932EDDB3F1DE34ULL, 0x4506781C0BA290F7ULL, 0xF2008C2279904AC1ULL, 
            0x16CA815AD0851B0BULL, 0xF1AF6AFA8E4F5954ULL, 0x4A349F24EF48D0A2ULL, 0x7315D774E4D426A9ULL, 
            0x4BB379B84CABA173ULL, 0xBECFB6C501B67C72ULL, 0x38664811CEE8049DULL, 0x073A46A96650C1ACULL, 
            0x828188191E552630ULL, 0xEF3A679A6BDD9116ULL, 0x5CEFD16B7C136DA2ULL, 0xEBAE212B6EC11DFFULL, 
            0xBFC196F11DB74A47ULL, 0xE8D51D0A19784029ULL, 0xC0608703520F4FE9ULL, 0x4476C94BA56A3F8EULL
        },
        {
            0x0852C59D7CB8A339ULL, 0x04E4610C2C8E87D1ULL, 0xD14C0FABAAD00C44ULL, 0x26C3DED750CB7131ULL, 
            0x7526C189B04D804DULL, 0x3C9E3039A0A3B74CULL, 0x1ACA0CE45874D010ULL, 0x2C775687A4B562BBULL, 
            0x565F91CB4335A4CBULL, 0xF3D95947DF2DF4F1ULL, 0x1B45CB4E649BCA9DULL, 0xFE2E7CD42D979F92ULL, 
            0x8202A5BC1212C78FULL, 0x7245A277FDC8E7DCULL, 0xF89353856F1E01C6ULL, 0xCCD24F0FC8115841ULL, 
            0xB6D5C0099CB41C74ULL, 0xC5C0AE2A8BB08D91ULL, 0x7A0D0CD4C41835DBULL, 0xDAAFAB86CC94823BULL, 
            0xFB356401DB069894ULL, 0xCC1717F996CCF902ULL, 0xF6F1DC52635AD5C6ULL, 0xFA20EF4FC9FAAC3BULL, 
            0xE2BC4CB9CB02C8E8ULL, 0x0F38A8772C240147ULL, 0x6484700FA2CC4DB7ULL, 0x92F9768D052D2BE7ULL, 
            0xA47A9DDC946BA8B1ULL, 0xA9AAA94BB8BD85DAULL, 0x22C6ED166C68A68BULL, 0x616D0156C96AE0A5ULL
        },
        {
            0xFCCEA7B75C5AE1BAULL, 0x8C805447D240CBE3ULL, 0x58C7B3AAA1FD7CA1ULL, 0x11058F239037E0F9ULL, 
            0x56C178FF44D2D37AULL, 0x9885779C6FBCB6EFULL, 0x52B1ED18C5A373E1ULL, 0xFF67D24FCDD36914ULL, 
            0xE95D6FE7A7B00AFFULL, 0xD271207BE1FD9E4DULL, 0x6CDB34B0A45F86DDULL, 0xB4C7F45BC7F6F737ULL, 
            0x7D691769B9F688DDULL, 0xCAE9B4A6A73DE791ULL, 0x1DA905D61421C392ULL, 0x6CF5B6EB0AF3E905ULL, 
            0x464E69B65CDF07ECULL, 0x175FC27B22EDF540ULL, 0xC4C3D819A494C960ULL, 0xDC4FB1AC6492A156ULL, 
            0x4E9ECD5C8FAF3579ULL, 0x48C7470E9809A574ULL, 0xF41437B3B7FAC2E9ULL, 0xEDF12A2C25115E80ULL, 
            0x1CD19647E9CC87C8ULL, 0x2DE2A6A7177509BCULL, 0x7E497B1E33BDC0E4ULL, 0x3A24943838FECF30ULL, 
            0x9F1000F584811989ULL, 0x69147710B6EAEB71ULL, 0xFB87896C3B2D9326ULL, 0x88B05D28DADD6627ULL
        }
    },
    {
        {
            0x9EDDA6C78781B2BCULL, 0x5730305CCA8A890FULL, 0x90ACF000CFFD3715ULL, 0x948B56693AEB148CULL, 
            0xAFE58F524A4B890DULL, 0xBF769987602C79B1ULL, 0x849BD10AF33CF394ULL, 0xC268ED3E0639DAE9ULL, 
            0x7CC9D0995CF64CAFULL, 0x73BBC16A229BF01FULL, 0x7F2AC1616EE925A0ULL, 0x13E7190D955F17CAULL, 
            0x68843C8A2218ADF3ULL, 0xC3663AB0D39C0427ULL, 0xF0F6955E9DB2DB3FULL, 0xBF777CC8B1DC273DULL, 
            0x32E13E21323258EAULL, 0x7B997C2EC0AE04DFULL, 0xAE8ED73A5A76B5E8ULL, 0xB8D5F013A8899061ULL, 
            0x66A8E572BD577BABULL, 0x3FE9BD4236AFAAF7ULL, 0x693E1C105252FE0AULL, 0x490136C9AED39AD0ULL, 
            0x72EA3897174105B9ULL, 0x97C81FC64C12AC22ULL, 0x9559AF0546E4A283ULL, 0x4CFB1924A70CCF12ULL, 
            0x4D069BAC8BD8F4BFULL, 0xBBA2D8639346B53DULL, 0xCEE17C4E2E627E9EULL, 0x57D738048CE1B971ULL
        },
        {
            0x301BBB5E7D861BE1ULL, 0x58A6FF5C77F140E3ULL, 0xA69EAFE2938B35F7ULL, 0xF43CA7A748E4C02AULL, 
            0xA499E3AB304443E2ULL, 0xE1486BBC4D0228C3ULL, 0x848FE06588DD4F8DULL, 0x73D8A835F75828FCULL, 
            0x86943DEF808EF984ULL, 0xA9296B031EB76880ULL, 0x97D5AF50BD0BDF57ULL, 0x88BA91A1090801EEULL, 
            0x88D40FEEC8489A2CULL, 0x13705F5039A5C160ULL, 0xA86E485C6C20DD5FULL, 0xF02B54B397ABE7FEULL, 
            0x916D2283A622370DULL, 0x93E9E7A27976AEF3ULL, 0x9226393F7348F2A7ULL, 0x940A446CA795DDF5ULL, 
            0x3FC88505BD52EADFULL, 0x3F4D0E4440CF3887ULL, 0xD03FE832164929AEULL, 0x4731D9FF4BA1795EULL, 
            0x399B3ACC3557FA14ULL, 0x4049C200BB1324DFULL, 0x21D33F764E42D8E7ULL, 0xEF03B9F983F40005ULL, 
            0x0303D897C8167624ULL, 0x9F1897AB7574D832ULL, 0xC4657F99D973270DULL, 0xDE27A7641E4AF2ABULL
        },
        {
            0xB1DD61EC3D493EE3ULL, 0xB00893BF7A4541D0ULL, 0x22A7CE17BD2B80EBULL, 0x990ED77C0E31E9D0ULL, 
            0xE8483C808FBD5A00ULL, 0xC6786DC78A225AC5ULL, 0x818D81B57CDBB526ULL, 0x98B350A8C2AEAAF8ULL, 
            0xF7BC433668AD3482ULL, 0x58E6AA02D26C694EULL, 0x06F8F7CEB317647FULL, 0x13028901472C4847ULL, 
            0x83A5AECCD7E266CCULL, 0x0A4EAFA03733EF9BULL, 0x34BA45AFBD93FB47ULL, 0xF43E7347A4ED85E3ULL, 
            0xD7D336E0CB31748DULL, 0xBA4B440B88DAC2A9ULL, 0x232AA2454BEC9535ULL, 0x1EB9ABAE3656061FULL, 
            0xF03786086B9BF65CULL, 0x87BECFB21BC04F48ULL, 0x671696E65F7044A8ULL, 0xD40356EF5757337BULL, 
            0x7AE22E633C4E2751ULL, 0xA4DC590E0FB6C9DCULL, 0x508CBD4431CF3CB3ULL, 0x90E65169F264CBC9ULL, 
            0x7FCF6B7DFFC8D289ULL, 0x8BC21DCA5BAF21C6ULL, 0xE5B90C5DD392680DULL, 0x434FB87573A7BD9EULL
        },
        {
            0x1A912F7A39A42F33ULL, 0x1C8ADDFECEF6BDD1ULL, 0x59B750CDEB631D8DULL, 0xF5ADFF18F56F8DA0ULL, 
            0x21ADC747C51AA32FULL, 0x8EC9B9688271E470ULL, 0x36D9CB634F6EF6F6ULL, 0x732832025EEB79FBULL, 
            0x3E60C73C48DB08C0ULL, 0xB24EB7317CF9C293ULL, 0x7A8CE4B31AABA9C7ULL, 0x21C923A2E6C77853ULL, 
            0xF7E14A0859896ECFULL, 0x157478D34718EF36ULL, 0x4FB1C618DA551F88ULL, 0xC6355D381FB80C64ULL, 
            0x846E8704A06E2668ULL, 0x0B7A61BF6389D960ULL, 0xCEEBD325614B4556ULL, 0x18652AE93FBDC5E5ULL, 
            0x000A24D30C4F8E2DULL, 0xB8B0679236E86C2DULL, 0xA89C7F5392F688F3ULL, 0xC51F088714BDB57FULL, 
            0x5B9FDA548FF989E6ULL, 0x8776B3E9CA18E35DULL, 0xF9B79BED1B40079EULL, 0x5C5A47EFB054063FULL, 
            0x07B1BC52F0E8B67BULL, 0xBDE69149AEC9D5A1ULL, 0x6FCB9CBE258AE362ULL, 0x0B089B0A7E3D541DULL
        },
        {
            0x09B7DCD36DECB949ULL, 0xCD62FF05F8643893ULL, 0x4A52F186651B8187ULL, 0x3A5547EFAB99631BULL, 
            0x4958EF600A981FF2ULL, 0x3897A3E24AB5F6DCULL, 0x609DDDEA24254252ULL, 0xFE896C8075CE37A8ULL, 
            0x6A30B1F8D5D5EAB0ULL, 0x66B818553E017AA3ULL, 0xDF3D28EF2030FB46ULL, 0xDCA88ECA27F5CA73ULL, 
            0xBF1A4B40F04FD4B0ULL, 0x99F3D8D7E01264F6ULL, 0x7781EEB6A9F7EE32ULL, 0xBADF8325AF65FF30ULL, 
            0xF4A7B98D2F8C14F3ULL, 0x2DB80D818D25908BULL, 0x9C02FAD7908160F1ULL, 0x476B9DA2F63E0A5EULL, 
            0x8B5CDB8F9A1813F1ULL, 0xB222C06A643F5C1FULL, 0xDDDCE3612288BA89ULL, 0x860D0D48AC552961ULL, 
            0x9ED6BF43116575A7ULL, 0xC591957658D75CD6ULL, 0xDDB9C7629F73C5FDULL, 0x70DE69C7BA8A9F58ULL, 
            0x53738AD6B6E0E13FULL, 0xDC69EF8C1EE56CFCULL, 0xE107D77A1CE64F81ULL, 0x9FA0D359CB3F103FULL
        },
        {
            0x745A60AADE2694D8ULL, 0x8B00C18349C67B39ULL, 0xE34B250588D2E9CCULL, 0xE888D0DD60F86342ULL, 
            0x6B4D997A924706A7ULL, 0x089166FAF4A4EF43ULL, 0xE212E7732ABC16B2ULL, 0x3C58272A0B24AD7CULL, 
            0xDEFA25F2C720FD36ULL, 0x40070122D6BA0F74ULL, 0xCB0AA05372203A53ULL, 0x3168A59082394D03ULL, 
            0xE771CC503524BCA3ULL, 0xC2648E35EB70EC4FULL, 0x33A29BBA08ADAD3FULL, 0x0875BF53C6CA2B29ULL, 
            0x6B20DFB999DF742AULL, 0xCDB7559CC6590B54ULL, 0x897C9D48FCB70514ULL, 0xCB39314E1C24B45FULL, 
            0x9D16524C863953B3ULL, 0xA8D7058AC84855A9ULL, 0xB2F968D3F8384562ULL, 0xBB881D76B9B82684ULL, 
            0x6C21D60C14ACA467ULL, 0x1E1F1DB29D43DDEFULL, 0xCD07AFC6266BD02BULL, 0x9017CAEE362A762EULL, 
            0xF22C791556059564ULL, 0x879050C7FD23AC6DULL, 0xE7209395185F492EULL, 0x76C8AC22B570565BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alioth::kTwistConstants = {
    0xF907851C94E7F4DFULL,
    0xA54DD019893D84BEULL,
    0x8C09483EF84639E4ULL,
    0xF907851C94E7F4DFULL,
    0xA54DD019893D84BEULL,
    0x8C09483EF84639E4ULL,
    0x081699DE94CE6B47ULL,
    0x8514DB6173A827C6ULL,
    0x1C,
    0xD6,
    0x70,
    0x2B,
    0x3A,
    0xB1,
    0x41,
    0xDC
};

