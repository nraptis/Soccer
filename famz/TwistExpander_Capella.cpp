#include "TwistExpander_Capella.hpp"
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

TwistExpander_Capella::TwistExpander_Capella()
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

void TwistExpander_Capella::KDF_A(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Capella_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Capella_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Capella_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Capella_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Capella::KDF_B(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Capella_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Capella_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Capella_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Capella_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Capella::KDF_C(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Capella_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Capella_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Capella_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Capella_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Capella::KDF_D(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Capella_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Capella_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Capella_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Capella_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Capella::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA48C5FE1A9550F8BULL;
    std::uint64_t aIngress = 0x9136E119FB8A62F7ULL;
    std::uint64_t aCarry = 0xF78273331125A347ULL;

    std::uint64_t aWandererA = 0xBC660CE956BEF0C1ULL;
    std::uint64_t aWandererB = 0xB68C86F03B2AED45ULL;
    std::uint64_t aWandererC = 0xAB4F8CAF9AC41016ULL;
    std::uint64_t aWandererD = 0xA86C59C44A6D1127ULL;
    std::uint64_t aWandererE = 0xCA2697CF5AACE2EBULL;
    std::uint64_t aWandererF = 0xCFD5AC90306809F3ULL;
    std::uint64_t aWandererG = 0xC1EFA634C2726A32ULL;
    std::uint64_t aWandererH = 0xDFC58D4A9577FB17ULL;
    std::uint64_t aWandererI = 0x89C3D0C781DE5160ULL;
    std::uint64_t aWandererJ = 0xD6F56CB8EA26BBC8ULL;
    std::uint64_t aWandererK = 0x912C2259DACDA6BBULL;

    //
    // KeyRotate A
    //
    aPrevious = 0x818BA20E7973A09DULL;
    aIngress = 0x9540AFC59146E4EDULL;
    aCarry = 0x980089622C7139A9ULL;
    aWandererA = 0xA705C99EDAC2528BULL;
    aWandererB = 0xD6B79A8AE764CC4DULL;
    aWandererC = 0xCAB829C67C9ED8DCULL;
    aWandererD = 0xD2C09497A23E33BBULL;
    aWandererE = 0x8D40BE941344F9EAULL;
    aWandererF = 0xFDB119DF8B9C381EULL;
    aWandererG = 0xAB50D4CA35C18410ULL;
    aWandererH = 0xB40DF64DCDB9CF54ULL;
    aWandererI = 0x861E060114B4B3C7ULL;
    aWandererJ = 0xC153146A8FFA1C76ULL;
    aWandererK = 0x877321C1029E134EULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateAConstants), &(pWorkSpace->mDomainBundle.mKeyRotateASalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeyRotateAConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xA9277FF879E92B71ULL;
    aIngress = 0x925014CDF64BDFDCULL;
    aCarry = 0x8DD5905614E63FA6ULL;
    aWandererA = 0xFD34F1C10D3F5562ULL;
    aWandererB = 0xF83F2F02030E5D65ULL;
    aWandererC = 0xA5A5E35DD2653A7AULL;
    aWandererD = 0xBC4639C4BF0E0B3AULL;
    aWandererE = 0xAB97C24B8F5FC3E8ULL;
    aWandererF = 0xF0044AC19AC70914ULL;
    aWandererG = 0x8EEBB420ADB8347BULL;
    aWandererH = 0x87DDA1DACA9664F1ULL;
    aWandererI = 0x892B22E8A154694DULL;
    aWandererJ = 0xF0227EC756F24544ULL;
    aWandererK = 0x9FE8D7EC16713C8CULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants), &(pWorkSpace->mDomainBundle.mKeyRotateBSalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneB, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xF8745F8B5D31F431ULL;
    aIngress = 0xF3BF87D96CDF0704ULL;
    aCarry = 0xFE35546E0412B95FULL;
    aWandererA = 0xE1BB5F7F0E63CD10ULL;
    aWandererB = 0xCB82F107052274A3ULL;
    aWandererC = 0xF873CC282B30CC8FULL;
    aWandererD = 0x8AA3480E24EE8753ULL;
    aWandererE = 0x834C6B780FD7D927ULL;
    aWandererF = 0xFE5DFCC1699C4591ULL;
    aWandererG = 0xC0C3529EB2EBC992ULL;
    aWandererH = 0x9D79BE33A5667B83ULL;
    aWandererI = 0x874DC62E3BBC01E6ULL;
    aWandererJ = 0x84966935347E1639ULL;
    aWandererK = 0x897F2C9FFAFC8441ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnAConstants), &(mDomainBundleInbuilt.mKeySpawnASalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants), &(pWorkSpace->mDomainBundle.mKeySpawnASalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xE647588ADBCC9163ULL;
    aIngress = 0xC296F3E3104FC852ULL;
    aCarry = 0xF57832B4FE0014B6ULL;
    aWandererA = 0xC1415133201ADD84ULL;
    aWandererB = 0xFB58EB17565C3912ULL;
    aWandererC = 0xB009F942ADABA82BULL;
    aWandererD = 0xD9B10C3012F71DCBULL;
    aWandererE = 0xA49D4BE954434919ULL;
    aWandererF = 0x99112A68F5BF7BF8ULL;
    aWandererG = 0xBB5AF7E632D94379ULL;
    aWandererH = 0xA569B84FBC2C0BEBULL;
    aWandererI = 0x8DF052CEB91F2C4CULL;
    aWandererJ = 0xB111ACC9515007A8ULL;
    aWandererK = 0x929D0882537F8EADULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnBConstants), &(mDomainBundleInbuilt.mKeySpawnBSalts), pSnowLaneB, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0x870B385EC430E05BULL;
    aIngress = 0xCF91066903441DC3ULL;
    aCarry = 0x9389793852E8A453ULL;
    aWandererA = 0xD8D9BF5AF6EDAC59ULL;
    aWandererB = 0xF659DC22A081EF9EULL;
    aWandererC = 0xB0716D676974DF0FULL;
    aWandererD = 0x881540E8559BAB2FULL;
    aWandererE = 0xC39D600FD6C14A69ULL;
    aWandererF = 0x8AD52883747A47C9ULL;
    aWandererG = 0xC46FCE02A014B13FULL;
    aWandererH = 0xE681D4480C3116BEULL;
    aWandererI = 0xCF35704DC5F51A4FULL;
    aWandererJ = 0xFCA3F2C7137611B4ULL;
    aWandererK = 0xB25E7F7C20640B00ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mTwistSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xD48AA667FC00ADA7ULL;
    aIngress = 0xE244B3D32FC35C6CULL;
    aCarry = 0xE26BB74B5B3CAFE2ULL;
    aWandererA = 0xD97C397D3979E359ULL;
    aWandererB = 0xE89933FA048F9E79ULL;
    aWandererC = 0xB71FBDE28CC464B7ULL;
    aWandererD = 0xD8C7FBEC47EAC77EULL;
    aWandererE = 0xCE26C2FF11588C92ULL;
    aWandererF = 0xBF53D0695502E9AEULL;
    aWandererG = 0x871C15F8613EFC38ULL;
    aWandererH = 0xFD59FD021174BF8FULL;
    aWandererI = 0xD871D0A2AFC6A793ULL;
    aWandererJ = 0xE962770EDFCF96EFULL;
    aWandererK = 0xB005FC191303C02AULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xD5EAA201A8E5E3E2ULL;
    aIngress = 0xC8AA694A2BC8A07AULL;
    aCarry = 0x908A2095AF68EA2DULL;
    aWandererA = 0xF1A33E8130194214ULL;
    aWandererB = 0xB77C86C8E3408457ULL;
    aWandererC = 0xBA4CB102C365C5B5ULL;
    aWandererD = 0xEF38DE92DC9BC813ULL;
    aWandererE = 0xAC76D9F15A1192DEULL;
    aWandererF = 0x94A5B5F1D5C7F9BCULL;
    aWandererG = 0xACDCE6625E628C2BULL;
    aWandererH = 0xA9B7F9616701ACD8ULL;
    aWandererI = 0xCA788D8DD04496EEULL;
    aWandererJ = 0x9461E0ADCC7F4E28ULL;
    aWandererK = 0x8D837CB37DACC02DULL;
    //
    TwistExpander_Capella_Arx::SEED_A(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::SEED_B(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::SEED_C(pWorkSpace,
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
    TwistExpander_Capella_Arx::SEED_D(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::SEED_E(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::SEED_F(pWorkSpace,
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
    TwistExpander_Capella_Arx::SEED_G(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::SEED_H(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::SEED_I(pWorkSpace,
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
    TwistExpander_Capella_Arx::SEED_J(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::SEED_K(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::SEED_L(pWorkSpace,
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
    TwistExpander_Capella_Arx::SEED_M(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::SEED_N(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Capella_Arx::KEY_A_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::KEY_A_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::KEY_A_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::KEY_A_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::KEY_A_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::KEY_A_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::KEY_A_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::KEY_A_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::KEY_B_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::KEY_B_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::KEY_B_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::KEY_B_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::KEY_B_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::KEY_B_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::KEY_B_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::KEY_B_H(pWorkSpace,
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

void TwistExpander_Capella::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB98D092DA1888C34ULL; std::uint64_t aIngress = 0xE7F5256BCE826611ULL; std::uint64_t aCarry = 0xFE02DE47BD9CF34EULL;

    std::uint64_t aWandererA = 0x84A39C5EC699B0A4ULL; std::uint64_t aWandererB = 0x8995271E017F49E9ULL; std::uint64_t aWandererC = 0xC705FB063FD75EDBULL; std::uint64_t aWandererD = 0xD28E657E45E82141ULL;
    std::uint64_t aWandererE = 0xC4BDCDD440A75893ULL; std::uint64_t aWandererF = 0x913B1828B650E8F3ULL; std::uint64_t aWandererG = 0x94C5AB747F3D3BAEULL; std::uint64_t aWandererH = 0xE1757F40E93CCD44ULL;
    std::uint64_t aWandererI = 0xAFAD7D24B90603DFULL; std::uint64_t aWandererJ = 0xAFC5D77DCD17EBB0ULL; std::uint64_t aWandererK = 0xC515E65AA5B2CFECULL;

    // [twist]
        aPrevious = 0xC7F2DA682C7E2EE3ULL;
        aCarry = 0xABC62CE64C140DE3ULL;
        aWandererA = 0xE27F66A350F5D78EULL;
        aWandererB = 0x900942AFF1885907ULL;
        aWandererC = 0xA531C236786B5F4AULL;
        aWandererD = 0xBDF0A3A6F53B1993ULL;
        aWandererE = 0xF8F8DD620E99F20BULL;
        aWandererF = 0x984E1C26E4DC71E5ULL;
        aWandererG = 0xEF3062FAFF6C83DCULL;
        aWandererH = 0x87CA49A2E8DCA90AULL;
        aWandererI = 0x9FEC31A85D3C57E1ULL;
        aWandererJ = 0xC703E98F6329C3DBULL;
        aWandererK = 0xD4C133318BC1EC8AULL;
    TwistExpander_Capella_Arx::TWIST_A(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::TWIST_B(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::TWIST_C(pWorkSpace,
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
    TwistExpander_Capella_Arx::TWIST_D(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::TWIST_E(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::TWIST_F(pWorkSpace,
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
    TwistExpander_Capella_Arx::TWIST_G(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::TWIST_H(pWorkSpace,
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

void TwistExpander_Capella::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Capella_Arx::GROW_A_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Capella_Arx::GROW_A_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Capella_Arx::GROW_A_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Capella_Arx::GROW_A_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Capella::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Capella_Arx::GROW_B_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Capella_Arx::GROW_B_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Capella_Arx::GROW_B_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Capella_Arx::GROW_B_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Capella::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 15 of 33
    // Exploration cases: 0
    // Structural maximin 525 / 674; family total 7536
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
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8059U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7699U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7879U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 47U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 92U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1330U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1735U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1645U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1825U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 47U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1375U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1960U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 15 of 33
    // Exploration cases: 0
    // Structural maximin 525 / 674; family total 7543
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
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7429U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3468U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2838U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7519U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1285U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1105U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 520U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 655U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 610U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 475U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1195U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 835U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Capella::kKeyRotateASalts = {
    {
        {
            0x46E9920950B7AE09ULL, 0xF6E2B5C2553A3DD7ULL, 0x640A65C1AC1FAB17ULL, 0x983FAE2A307039FAULL, 
            0x5D02D2EAF74FE876ULL, 0x4B0863C135EA2DEEULL, 0xB3E161A3651D2593ULL, 0x0CA056B6C82B883BULL, 
            0xBFBBB01F9AF786BAULL, 0x879C3F02ECB9F719ULL, 0x83E1DE4A4B37C4C4ULL, 0x7865F14A046ED399ULL, 
            0xA853673C37B29D10ULL, 0x5BFFD76053C444A4ULL, 0x80F24275E62B62B3ULL, 0x06A37655264CEE88ULL, 
            0xB565CFE422140BC0ULL, 0x27482168635E88ADULL, 0x0F3078BE0CD1DC41ULL, 0x0BB583EFCCC0E980ULL, 
            0x0264D3E1768F2D0CULL, 0x1C0015079425DDE8ULL, 0x88B3B083DCADCA93ULL, 0xB138E75DBB797EDDULL, 
            0x6397696B8FFBC788ULL, 0xB1FEB3801F1507B8ULL, 0xD91FEC7699C8D604ULL, 0x11531117EEDB6A7EULL, 
            0xF8837F9212EFB012ULL, 0xAE37CEC8614E035CULL, 0x9569F278173ED2CCULL, 0x7036416FD736CEFEULL
        },
        {
            0x1C8A2CAFD9970EA7ULL, 0x0131BB434EE6C594ULL, 0xC0B1C1E09B43ECE3ULL, 0x4895C3ACC1048D0FULL, 
            0x1A608C70CE74D218ULL, 0xF502511199480F7FULL, 0x18A44399EB366231ULL, 0x38D044C76279386BULL, 
            0x4E8445728F3054F3ULL, 0xF90224A562232B05ULL, 0x83FB1C030E97784FULL, 0xE41076FB17C5BBD9ULL, 
            0x6C76C21D95662ECDULL, 0x0645F0C2B10BCF60ULL, 0x9150C267B3FFD893ULL, 0xC1280E00EB206485ULL, 
            0x2278D1C424BD6563ULL, 0x900FB326C82B4399ULL, 0x19DB7C143F7E5637ULL, 0x4B41DA382469245EULL, 
            0x144837EA11DAEC16ULL, 0xD51FC8EB31EF7AF5ULL, 0xD9D6179279901812ULL, 0x0A645DAD3F25A2A1ULL, 
            0x76977C42C72F4687ULL, 0x8112CB13A503E88CULL, 0x0244627A1F331001ULL, 0x8BACF9A8316AC0ADULL, 
            0x3649EF6F7AF0086BULL, 0x84A31B20155A31D6ULL, 0x94C675D804EF6178ULL, 0x21B6D433551864D4ULL
        },
        {
            0x72EC804131B9EEB4ULL, 0x2A043AF7CF85403EULL, 0xC39D65E40F2493DFULL, 0xF89F3EF7D70204A3ULL, 
            0x3376D0CBDC36AB4EULL, 0x12BAA499CE968CA4ULL, 0x316A87743002AA3AULL, 0xA87B0795BA6FF536ULL, 
            0x8B4209B463939E99ULL, 0xF140951A7A8B5901ULL, 0xB175D8211A7A12D0ULL, 0x39FE90016B33A9DCULL, 
            0x8D185031C84F55D1ULL, 0x706059D14C82E76BULL, 0x8C93D3571FAF6262ULL, 0xBE82AC88914A73DEULL, 
            0xF126D8E9891AA0FBULL, 0x044C7ABA0B6F60F3ULL, 0x2F0F86E2E7218CE7ULL, 0xCCAB3297DF8DA116ULL, 
            0x93DBC0E5FA062E47ULL, 0xD71F719A3409E34FULL, 0x437C46780DB77349ULL, 0x0475E0E44A5C1DC8ULL, 
            0x9CFC48A8474BE6D6ULL, 0x5A844FA44D16FFA6ULL, 0xAA050BB3FB99C297ULL, 0x49FAF225621EFAD8ULL, 
            0xE41BE2455B810FC5ULL, 0x7E838BFB6BD0E9B4ULL, 0xFF276CE131A4B2C0ULL, 0x3E969A3046790ED5ULL
        },
        {
            0xEC65F7E365FAA226ULL, 0xA9083A518489985EULL, 0x7C2C784E885572F3ULL, 0xFC9F76EC3F65EB7DULL, 
            0x4E6B0C111C3D9C9AULL, 0x9FDC44317DFD2C51ULL, 0x102456D7DD365BBDULL, 0x361DC68A3BEDD0ACULL, 
            0xA87E03EA44887887ULL, 0x89F9EF5F8CA61EB5ULL, 0xBC2C2F188D6D9710ULL, 0x41938D455BD50BE3ULL, 
            0xBB1BD2F83374748AULL, 0xC1E552D4EA6A7DD8ULL, 0xB952990206C788CDULL, 0x3CB919C47DAB19DAULL, 
            0x6EF31CB219AFD608ULL, 0x8ADD0EA2DEFFAB1AULL, 0xE1B48E0939F63136ULL, 0xCE94B407235A3B5EULL, 
            0x2B257ED4719985F8ULL, 0xD6B1C9022502EB6AULL, 0x274B975FB66182EEULL, 0x52624CDD15ED8332ULL, 
            0xEE4227CFB6F8584CULL, 0xD8D18D10FE1FE801ULL, 0x0C7AC11BA9724715ULL, 0xEC3136DC73F41337ULL, 
            0x15532DF3C92C7F59ULL, 0x75390EE31B22F0EEULL, 0x018FB56034A53455ULL, 0xB7584FDD7FD26207ULL
        },
        {
            0x2705FDB44550FE54ULL, 0xDFEA8030A73E3B69ULL, 0x6A060517EDBF6ECBULL, 0x637546DD58EE16ABULL, 
            0x9D37FE78BF09B1ADULL, 0x2CF35A15FFE34141ULL, 0x60A72C3BEB58FE16ULL, 0x82319A843B768D8FULL, 
            0x32F3F8B70564EF0EULL, 0x0771473ED9F8B381ULL, 0x1E516446983F1F47ULL, 0x1E35A1B445B23AD2ULL, 
            0x8C3D92726E4DB34BULL, 0x412A6CD9A343F318ULL, 0x80C3EAF34E1AF83AULL, 0x3B0279D2A422A630ULL, 
            0x1A0F6256B0B44B78ULL, 0xB4AA320BB329D849ULL, 0x8FF883B2F036E034ULL, 0xAE22F3EEC075775FULL, 
            0x27BE0E11D8017737ULL, 0x4B2F3F0F40ED9A97ULL, 0x5DF4A46E60D11BDBULL, 0x8DE3CBE9B0DBF49FULL, 
            0xD55364FF50679FB6ULL, 0x84BCAEC6D7DC4E6CULL, 0x71A82C00C3DAD121ULL, 0x470EBC38B6FC380FULL, 
            0x968020B4768DC358ULL, 0xE6EA3C52AF9FA1A4ULL, 0x30306EAB7CA945A2ULL, 0x45B4A6E4F32DE88CULL
        },
        {
            0x4B26A5F068FA0F59ULL, 0xF7A6EEAD79458916ULL, 0x6DCF14A6688A4170ULL, 0x9650056301868B62ULL, 
            0x3A317B65245D1C57ULL, 0x6CA454CF7C791B5DULL, 0xA0BDA3CEA043DAF7ULL, 0x162101320D260B35ULL, 
            0x50E2DCA258C0C412ULL, 0x3A5ED68A771AE795ULL, 0xBAC84033D56ECF1DULL, 0xEEC4C04185814AFCULL, 
            0x9525E0D70624A12CULL, 0x131724A5D5D2877EULL, 0x5F8F88FE79211262ULL, 0x5C72A16FBF5A0E50ULL, 
            0x288D60FB222CF864ULL, 0x4CFD7B83936D3097ULL, 0x68262873D71C888BULL, 0xBF3C90171FA622E5ULL, 
            0xD1EB7E4B67112A8CULL, 0x96647851BC0EF41DULL, 0x77DAA9CDDDBC4866ULL, 0x03FE71C45E89F3C0ULL, 
            0x0E3451DA33BD3FD2ULL, 0xF5F85CC86D91D6EAULL, 0x18817AB4734BC10EULL, 0x0999330FDD6C9F35ULL, 
            0xA42CA1763AA7460AULL, 0xA2EC8A5EC2657C74ULL, 0xF361043559C75B52ULL, 0x677C04AC08D8555CULL
        }
    },
    {
        {
            0x5B421C34557316AEULL, 0x03F9D55147848224ULL, 0x7F0A8CB0520F16EEULL, 0x884F501DFA92BA8AULL, 
            0x9861F1C5CC4F7837ULL, 0xB8D6A9DBAC04B577ULL, 0x3405AE9B8C34FE32ULL, 0xE300F4DB718DE637ULL, 
            0x8561F0BF44861C35ULL, 0xAB50460140C54EA0ULL, 0x7B148D46D28AB91DULL, 0x5F56E75EC0DD0751ULL, 
            0x0019531BC2B31BA4ULL, 0x8A9B2D9623C6C526ULL, 0xAF73752CF07D73C7ULL, 0x1C19AF6620B84895ULL, 
            0xA3A3E23753BD9FFEULL, 0x054DFFFEEB922755ULL, 0x34B335CCFB17B237ULL, 0xD06385B4D36C9DAFULL, 
            0x3FA98F4B586520FFULL, 0x434519F280D9F1A2ULL, 0x074E1FB1B1726870ULL, 0xFFAA56BADFFC84FDULL, 
            0xBCF51316D23A4873ULL, 0xCC8D81C1FCC57BB0ULL, 0xC0D2EE0277058209ULL, 0x2E294E2CB69338A8ULL, 
            0x3433A99312429EAFULL, 0xF9DE717E94DC9EA2ULL, 0x11E29ADADFAE1CDBULL, 0xAB04D7CFB4CE097DULL
        },
        {
            0x1A12B1276CE883BCULL, 0x101538B96243DCD3ULL, 0xDDFE64EC3E48E458ULL, 0xAF55FAE97A8E4D9DULL, 
            0x89C6D02A58449F32ULL, 0xBA1F774224F780D0ULL, 0x36BCB56051C0C1A7ULL, 0xB129702F22E79560ULL, 
            0xC7C1A80E4BEB6CBCULL, 0xAA9EC1776BCC89BCULL, 0x4C0FF6B7676E6295ULL, 0xD398663FE300F1CFULL, 
            0x6F2A43A93FC574E4ULL, 0x14C6F40C14020326ULL, 0x7F34E3F99C61B6B6ULL, 0x173FF281E7A60601ULL, 
            0xC41902A094FEC408ULL, 0xC1AA4AF980CCB143ULL, 0xEF9F681316E2CCA2ULL, 0x71878EA452EEDD64ULL, 
            0xF8C2BE000337BA78ULL, 0x647F0D3E76D8638BULL, 0xDB8631E160F89687ULL, 0x2E1FDC7ED4C35B8AULL, 
            0x46455B95539F4DEFULL, 0x842D9849C67D7D5EULL, 0xC1E4F8DAB193C967ULL, 0x657E6D39B60424BBULL, 
            0x009EE2B405243057ULL, 0x4691CF3B85BEF03DULL, 0xB0850EC527B6E582ULL, 0xAEA81589DB1F66E0ULL
        },
        {
            0x63F097F952985A32ULL, 0xB5C204DBFDA73804ULL, 0xC0B3B66C397E5F7EULL, 0xF0594122C7434593ULL, 
            0xA3C0FAC4AA878D2FULL, 0xFC98D4E5003B6A1AULL, 0x4B1964FD291EFF23ULL, 0x6570B62D31CB4D2FULL, 
            0xD4AF0C1E1E4B0FB3ULL, 0x3922BB21FCDB9876ULL, 0x72520847D5A55CD2ULL, 0x26C154BCC193CA4FULL, 
            0xA708C7CBFF80ABB8ULL, 0xEF613ECC93192DC0ULL, 0xB52B0B6D1247A4F4ULL, 0x005D0B2A33A1AB22ULL, 
            0x3E0FBF40D7550DABULL, 0x860409FC8896724FULL, 0x0ADF717B7EA82AF0ULL, 0xDE08CF0D8EB9CD58ULL, 
            0xBE0F43E15FC4DE83ULL, 0xDD2DC0FB4FC9A0A8ULL, 0xE22886DE1763CF6AULL, 0xF7892783DCBFB7FEULL, 
            0x81C600E50601510FULL, 0x26BE12701E72BB6DULL, 0x54A83A24059DC360ULL, 0x67663C9569434C3BULL, 
            0x6CBF985189EAED58ULL, 0x2A91BC05F4E097B2ULL, 0x587CCC2A83995641ULL, 0x85D71D478D5A3E21ULL
        },
        {
            0xCCD9E2A650D34FA5ULL, 0xC899E99D168161FBULL, 0x4C25FDBA12BA72ECULL, 0xDE432F6821912C03ULL, 
            0x95EBAA7E0F79B198ULL, 0x004891E8C8B1BF2EULL, 0x8B54112E77AB589FULL, 0x87560BD175025D64ULL, 
            0x2038115F1018930EULL, 0x7E640BAB3B04C40EULL, 0x6F2ABD382D920E34ULL, 0xFA0B5E40A93C93B9ULL, 
            0xED1387251280BD0BULL, 0x3D645514E9EE0529ULL, 0x1F249F377B8DC68FULL, 0xDD245AAEF8B416C9ULL, 
            0xED032749FBF29941ULL, 0xE5A44E71BD0639E1ULL, 0x451FAFC2609ABBC9ULL, 0xCBD21A17FCAD7A61ULL, 
            0xE7F4696E31F70C7AULL, 0xC8CD948F58AF2F62ULL, 0xCA639BFEEBF89A56ULL, 0x3FC96A8F547065F5ULL, 
            0xDDA51B230907452DULL, 0x574A47A4DECC6285ULL, 0x5D08E5B119D6F5D7ULL, 0x8F582C0D3391DC10ULL, 
            0x915C14B03A39E8B9ULL, 0x3B7997935D739933ULL, 0x945775604DFBBC38ULL, 0x8883C16F1AFA4B87ULL
        },
        {
            0xC9EDC41C7C163B4FULL, 0xCA22F5D3C2116D86ULL, 0x24364899A0AC4FB4ULL, 0xC3D7454061B55E26ULL, 
            0xEEEECF37408729F3ULL, 0xD0ACDF17AD3CD438ULL, 0x060D3867C956D7CFULL, 0xB4AC423526F4E5E0ULL, 
            0x8C44BA245BA3EEA4ULL, 0xEBAA0AE2F86F3B55ULL, 0xA7E1916EF335A68FULL, 0x1BA4EEF76D32B0C2ULL, 
            0x40818A9326B0FCE7ULL, 0x7B550A47D283003BULL, 0xFB24A725374FA50FULL, 0xD5CBA998335889A4ULL, 
            0xFFAF43C15B076FEBULL, 0x4CC8FA523D6DF575ULL, 0xF8FBD8D1BE4975EAULL, 0x4CC8E60AA3A688B8ULL, 
            0x28B30CD761687CF8ULL, 0x20C91645270FA9A1ULL, 0x572B6CFBC1317D1BULL, 0xFCBFB6BC32607852ULL, 
            0xFC470D94B21BC984ULL, 0xD96FBCE4BE737E6FULL, 0x8469B8AA8A8BB51EULL, 0x3F618FD6E81E304FULL, 
            0xA7D8167A95F9143FULL, 0xD181765DD60D2082ULL, 0x04C7E86C3D9D5B0EULL, 0x7211B2C58267C1E8ULL
        },
        {
            0x59FA800846619C06ULL, 0x9FB4D8AB468CEB83ULL, 0x992D25CB01DE974EULL, 0x8DDE979D291DBE37ULL, 
            0xAF5A8BDD2D361EBBULL, 0xAD79921C2E5C7E6FULL, 0xEE563E1B2297499DULL, 0xB7257CAD1D3BC426ULL, 
            0x56DE55AA66B35137ULL, 0x7F828836318296F4ULL, 0x6839939AC42AD5D1ULL, 0xABFCCF17D8BAF9ACULL, 
            0x08E48834D85F227FULL, 0xA1E2B9144A26CE77ULL, 0x5FD903E40B60C861ULL, 0x6F6517D63DA71F11ULL, 
            0x686C182C39CAAB5EULL, 0x1A053979B8D7A49DULL, 0x9956D13A3EA71E9EULL, 0x4ABE8B2610D9BC67ULL, 
            0xCCF51DFCD516DD17ULL, 0x658CBD8F73B8EECBULL, 0x85238A75BBC0A334ULL, 0xE6203A401820DAA5ULL, 
            0x956AD9AAA08D510FULL, 0x73545ACD640BAB57ULL, 0x0AD2E0FCC8EAC076ULL, 0x514B8194EC561280ULL, 
            0x8FF6124C71328ABAULL, 0x6B6D6D00C0C84F4EULL, 0x914A31F0AC3D5E7FULL, 0xC9929B35AC697FF8ULL
        }
    },
    {
        {
            0x55786929775C271AULL, 0x18389C053C285824ULL, 0x63D91FE40E6F1F65ULL, 0xECD359C06C0D5D55ULL, 
            0xBC2AC006DAB41C8AULL, 0x10BFAB24C0526B84ULL, 0xD72BF0A3CE580BEFULL, 0x45842DBBC70F41B8ULL, 
            0x053032A031722407ULL, 0xFEED959439F3BF3CULL, 0x46CB29B8593C2C27ULL, 0x74BB175039FF527EULL, 
            0x864B44EBE19718B6ULL, 0x571CA3BCE591129EULL, 0x221A14C962F8F2E5ULL, 0x7927641C192E9AABULL, 
            0x55B03DAD563E2FD2ULL, 0x1B83D1F536218926ULL, 0x80501F6960B7BE93ULL, 0xFB256CB3A2A207C7ULL, 
            0x9B138E2C797A7B95ULL, 0x364F42FDD914030BULL, 0x46A87C553FDA5247ULL, 0x502FBEABE9FE4A4AULL, 
            0xC48F16FDF611A3CFULL, 0x75830E7949465248ULL, 0x6F6D99AFC66A4D5CULL, 0x93D733E0E8DF9F84ULL, 
            0x4503B66A7A3D5525ULL, 0x71E3AB7EBB54601DULL, 0xE64AF4652F0652CCULL, 0x3A7959456BCB86DFULL
        },
        {
            0xEEFED317BF60A54FULL, 0x4931FEA0F8DB6B9AULL, 0xF7F4D57FD3357F67ULL, 0xB28462D910F4007DULL, 
            0x31ECAC5D26AD2201ULL, 0xA8FC90ECB6FD91F8ULL, 0x74BFA6C2D60DCF6AULL, 0xE7C13A43AC72AF2AULL, 
            0xCCB896415290DDF6ULL, 0x7DC0C51CD1C27AD4ULL, 0x32BCA47CF36D651BULL, 0x826343C040C082CEULL, 
            0x134F780F7D9C87BBULL, 0x392CF636C7781903ULL, 0xDAF76300EAAA8DDEULL, 0x45434A31583A78C0ULL, 
            0xA8EF5DAA5C2EDDDCULL, 0x1ECB1F24F6995735ULL, 0x517B7813B351602CULL, 0x92C5514409AF78CCULL, 
            0xE60A1847EB7D0CA3ULL, 0x690F99C7A385C88BULL, 0x2BFA635258CCB308ULL, 0xB6540CEF2A789232ULL, 
            0xE8C35936D2EBC5EDULL, 0xC5A4F3B8801B4C9DULL, 0xFBE7A37679958B47ULL, 0xADF7D8F927342EFBULL, 
            0x4A210337BE58CF56ULL, 0x93680031B00F51F4ULL, 0xD08B018AABB682E3ULL, 0xA8A0F09963B1D25EULL
        },
        {
            0x87A7210CF45F0D1CULL, 0x282B03B1DC935946ULL, 0xBCBB9CD35D285E7EULL, 0xB81B9BE526025953ULL, 
            0x28AD252CA9798791ULL, 0xE4372229504FF008ULL, 0xE12EDC23C627F203ULL, 0x96A4ACC3E47B1F24ULL, 
            0x88F3ECD17568941DULL, 0xB6A44AB4CF51709CULL, 0x88E3316C220CAE5EULL, 0x780793B348A4CD4CULL, 
            0xAE68924DD7B7AF62ULL, 0xE3881CA24F0EB645ULL, 0x35E3B4A199CCD96DULL, 0x02559F3926FF7396ULL, 
            0x74ECF80F3A91EAABULL, 0xFE956417C7014375ULL, 0x545E4BEDC5B35702ULL, 0xEB3FA56F1E21A172ULL, 
            0xA715FA461932EBAEULL, 0xAFFF4B16C90A48F0ULL, 0xFF9C6FA3EA238A68ULL, 0x2145200F2E947A99ULL, 
            0x2B40032F51D8A4CBULL, 0xDC21613F67638A48ULL, 0x101ED453B2DDA3F6ULL, 0x33785F6FFB0C98FBULL, 
            0x8653D09D4F80DB5EULL, 0x22110D141EA05500ULL, 0x7FCA2B910720DB3DULL, 0x682EB1384D563F5AULL
        },
        {
            0x9CDB4EFFC825C00FULL, 0xB673F0BF43DB218AULL, 0xCA5DC00A1758D205ULL, 0xE7989F88C567E9DDULL, 
            0x0C7A436DFD357116ULL, 0xFBDC5CB01DD7CD80ULL, 0xE6EDA99F4DB23130ULL, 0xC376B22A48663C2DULL, 
            0xAFB967FFD26E8947ULL, 0xF838C12B7EE42358ULL, 0xD8869F4519699D06ULL, 0xF3078DA30328B5F8ULL, 
            0x682B4FA664D0FE29ULL, 0x5774AF2D52608804ULL, 0x0DFD56D07E17DA76ULL, 0x6AD1439D3328275CULL, 
            0x5A31CE97296348D7ULL, 0x3EF03C53312147E4ULL, 0x257C22BD55C85D7BULL, 0x4D4F666F8AC01869ULL, 
            0xBB90AE81572A31C4ULL, 0xEDAF72BC1139A080ULL, 0x40CAC9D6C73041C5ULL, 0x90CC5A880ADA4790ULL, 
            0x9D34FB3EA40B3233ULL, 0xDC61CEE912440930ULL, 0x4C8C73D9856A1527ULL, 0x3677A2EEFDF6ADF0ULL, 
            0x210119A811489DD8ULL, 0xF265E4561A4CE502ULL, 0x33F92FB7AD9755C3ULL, 0x5C424119ADF52497ULL
        },
        {
            0x26EC220A3D723ACFULL, 0x9D66918638FD1F38ULL, 0xC618F0D23A4AEFD8ULL, 0xFC3849B440CC79EAULL, 
            0xC5A389109DAB8213ULL, 0x9356109E58B19D02ULL, 0x29372D146DA9B805ULL, 0x7999C92F23D1408EULL, 
            0xC671A78B855EE07AULL, 0xB148923725016AEBULL, 0x955D1E79BA0B83D8ULL, 0xCD8FD674F8FA6269ULL, 
            0x8EA71356B7385D61ULL, 0xA9DFEF00684004A9ULL, 0xFB34A4E1417D03B7ULL, 0xA067AC657BF76FABULL, 
            0x4D04A71CB1F83766ULL, 0x94C2D1692A04C751ULL, 0x171EF115AB41FF76ULL, 0x23F8D3852CE79F0BULL, 
            0x3E4AAD1EA3DDEBDEULL, 0xC90917233E61B20CULL, 0x9672AA30D75CAA5AULL, 0x6325E4A1A8ECAF26ULL, 
            0x276E0CB8EC6149C6ULL, 0xC37D01D3454F8E47ULL, 0xD84236F0BF75D15BULL, 0xC4DCEB8B8F325870ULL, 
            0xF5EAD405180D6E19ULL, 0x46BACA0E59A14D46ULL, 0x201E0E0FA36BAD91ULL, 0x28BF8B98F3E49C65ULL
        },
        {
            0x257F44551F1ADD07ULL, 0xEF506C7E20BD4D51ULL, 0x1137295B2E2B6F6AULL, 0x423B0D5BFC42DD65ULL, 
            0xDB6FDA36B3D32658ULL, 0xFAF6EE58DF14E6F5ULL, 0x76427F6B36E44D8EULL, 0xE938EB6EBD11134EULL, 
            0xA31C3CBE0ABA9857ULL, 0x559FDB06F805B291ULL, 0x8789B11E5BB529CBULL, 0xEBF65BEB8BF7C1C2ULL, 
            0x18187F96810A366CULL, 0xBF9708CC6BFA3BD3ULL, 0x27924425468FAF5BULL, 0x443222657AB4A00EULL, 
            0x33E630561DC02AA7ULL, 0x85710F7E15475982ULL, 0x519081B62A0422BDULL, 0x0F1EFC7D9F1E02F5ULL, 
            0x9E262A2AAAD1E711ULL, 0xD711A78699E54DA3ULL, 0x22055477A1F8FDB2ULL, 0xB4F74A100F1D9184ULL, 
            0x4AAFB2EDA84FE018ULL, 0x81F68612E1B796EEULL, 0xEBC0319955126CCCULL, 0xDED0AF1395489C6DULL, 
            0x4930CA28C3863C80ULL, 0x530C86562ECD1B12ULL, 0x374653D63D72CA0DULL, 0x450D76C1AA8A7E96ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Capella::kKeyRotateAConstants = {
    0xA63752A3C8F78719ULL,
    0x6D3DFC503F08A1F8ULL,
    0xF13EF311BD3A3ECFULL,
    0xA63752A3C8F78719ULL,
    0x6D3DFC503F08A1F8ULL,
    0xF13EF311BD3A3ECFULL,
    0x7E699264BD8FDFBAULL,
    0xF0353020BF1D4F41ULL,
    0xA0,
    0x8F,
    0xF6,
    0xB4,
    0x3C,
    0x72,
    0x30,
    0x6E
};

const TwistDomainSaltSet TwistExpander_Capella::kKeyRotateBSalts = {
    {
        {
            0x2DEED62E7E8DA7CDULL, 0xBD922AEDCFBC44B4ULL, 0x726775CE30B56FBEULL, 0xC2E6B80CD72AA711ULL, 
            0x15E6402C9951D28CULL, 0x8A97E830E710D96DULL, 0xB8073822181792CEULL, 0x9257B664969B73FEULL, 
            0xB4DAE794681D966AULL, 0x26CEFFC2931286D3ULL, 0xFBF3F110B098CFBCULL, 0x12BB9F72632C7651ULL, 
            0x7BB80626E72E8E9EULL, 0x061CD7713155366AULL, 0x41FFC2E12459F819ULL, 0xAA1EC01DB50796AEULL, 
            0xE857EFAE74678ECFULL, 0x677626640BFAEDB2ULL, 0x635392C29FA98FF7ULL, 0xB58B3730AAEEEC03ULL, 
            0x55C4F4ADC28C9676ULL, 0x1435ABE3AF02DE94ULL, 0x5FB01CF2076F2DBAULL, 0xABE606873BCB3CACULL, 
            0x613D060DDF77F5F3ULL, 0x8BA8CBCA37E22E4CULL, 0x06430D323AB6E42CULL, 0x570173D56540B1FBULL, 
            0xE540C17B869159EFULL, 0x9AFD4DB7F0081DE7ULL, 0xD440017716BEC5B1ULL, 0xED5CDBFD4CBF2F1EULL
        },
        {
            0xD582CA1FE1C41843ULL, 0x5ED2BFA735EA5F2EULL, 0x51AD65670A6B606FULL, 0x80A3665A5EAA3504ULL, 
            0x1D1CEE52AE12EAF9ULL, 0xF1D3C6FD8E989FD6ULL, 0x4CE2D56DD56E53BBULL, 0xE47F26E0A7754085ULL, 
            0xCB7D15F5A0995E0AULL, 0xEA12500B4933FB4EULL, 0x19B473FDA27CEC85ULL, 0x37B4AAF4EB74F9CFULL, 
            0x35B4835540EAFBAFULL, 0xC157983F8DD0C63EULL, 0x9D402A3AFC8911CDULL, 0xB71C645A92B086DDULL, 
            0x2680DDA9ED533AD3ULL, 0xDE2A88FC386405B4ULL, 0xB32701E862FD299BULL, 0x2F4E45D7C740F196ULL, 
            0xC7DC70251348DDDAULL, 0x973334F2ECB32976ULL, 0xABBDF665203F019FULL, 0xD10D9DC49C8EAF63ULL, 
            0xCE7BDB45AEAD7747ULL, 0x1DB48C03EB21027CULL, 0xF2BA0F19D1792071ULL, 0x20C12936967F375FULL, 
            0xA9750DAA614C28A3ULL, 0xF7C2773A46CCC529ULL, 0x9545F5F82B3D52F7ULL, 0xCEF3D12CCA288536ULL
        },
        {
            0xEA653E08374E08DFULL, 0x3FEA0424637F8CC2ULL, 0x62F696DD4D0A16DDULL, 0xE10C98B5AD86C92BULL, 
            0x36E592792D13D2F7ULL, 0x0FBD1A075C0F49C3ULL, 0x042D9906DE079446ULL, 0xF048D2C516C58128ULL, 
            0xC03275C13F6C71E8ULL, 0x64D5934CE6A2652AULL, 0xD4A37175268DDC74ULL, 0x3F3EB4FF37CF1D23ULL, 
            0xEF8A7D81F45E7248ULL, 0x8CCEA98C14B00A31ULL, 0xE21ECE41D36D74B6ULL, 0xE774E24539B7E087ULL, 
            0xF23E29F64F1B544CULL, 0x4B7BDC11689B0694ULL, 0xA4DD84A04D5C6E2CULL, 0x383593909465C6B7ULL, 
            0xB75D2600C3000C73ULL, 0x5346338F9F232C01ULL, 0xDD28DA4A596BA36AULL, 0x2C25C60BA4B6C828ULL, 
            0xB4391014F41723A7ULL, 0x61E30C64F89F39B7ULL, 0x5EB7B72B1CD74068ULL, 0x41F58F5D8C083C63ULL, 
            0x66396B2E701021EEULL, 0x4F9B758A7BA802DBULL, 0x81E3DD1116EB5994ULL, 0x519910D0E8ED0147ULL
        },
        {
            0xEDCF753A4C235326ULL, 0xB50C13547278174DULL, 0x59181B23396B6343ULL, 0x46531C6EB032A1F4ULL, 
            0x3A8D816BB7B334A8ULL, 0x816910753DF4AD2DULL, 0xEA8EF5D45DDC6251ULL, 0x312F32DFF84BB248ULL, 
            0x3EAB117286720308ULL, 0xEB0A534C51B3EB2DULL, 0x65A0507C53750AF0ULL, 0xBAAB33C23953B55DULL, 
            0x15358F04AA31D7C7ULL, 0x28483D25B9E25673ULL, 0x0944DE366EFCD17FULL, 0x84C82F13A045C428ULL, 
            0x0F1A0B7509B14CA1ULL, 0x2477F7697B6EFA6CULL, 0xD45151142D66C234ULL, 0x838539311768EA7BULL, 
            0x83C73EBB1C30AA34ULL, 0x45F4D8EB09A98517ULL, 0x13EEF7454A88D5A8ULL, 0xD6C64CBFBB01EB5CULL, 
            0x1A27A66986A6E16FULL, 0x5A17BE382D5E3D10ULL, 0xAA672FEB164C4965ULL, 0x2605BF36618994D0ULL, 
            0x554D0F7C0E288BEAULL, 0x85FF5DE34E4A7D91ULL, 0xB356317C21BE8E68ULL, 0xD0392C7D664C2A18ULL
        },
        {
            0xCE0D88103F954A5BULL, 0x92759E031B672233ULL, 0xF666AF8D4EC5DDADULL, 0x1A6AD8170E403E80ULL, 
            0x00E8C4C691E5FD32ULL, 0xB99DDA5118A98BDFULL, 0xDAB38DEA1CA515E6ULL, 0x3A7FEE132CAF735EULL, 
            0x736ADF62B2452B6AULL, 0x72E4D86E9155982EULL, 0x5BC34F577EC6457EULL, 0xBCD30B466E49FE93ULL, 
            0xF771F6C28B896961ULL, 0x8E32BFAFD5E7E6B3ULL, 0x2E8B1EB06FC1A9ACULL, 0xF9FC960CA5AB3225ULL, 
            0x9D8C1325527192F4ULL, 0x46B346F2234C4226ULL, 0x1D1601B064B6AA8EULL, 0x76323242C3CE33FAULL, 
            0xEE09A712C082125AULL, 0xA8D4A63767131948ULL, 0x97ECB91B9AC9FEF0ULL, 0x7A7ED0F1326C6B7FULL, 
            0x965741F0924AFD05ULL, 0x9DD7186738D7652BULL, 0x11A8B9CEF09F3B80ULL, 0x6939DB593B44D5E0ULL, 
            0x7E778750CA80A4C9ULL, 0x8838763B28DA0622ULL, 0x53BBC7114268ADE7ULL, 0x78A8C6C770A7BF19ULL
        },
        {
            0xC94605DBBF7A5908ULL, 0x7E66AAF255181A5BULL, 0x222E9FE5598EBCF3ULL, 0x9BE2091CFD650381ULL, 
            0x802370109210ECE2ULL, 0x1C6C43231266A539ULL, 0x0B2E9B5A81341362ULL, 0x5D2F5DE4F80958E4ULL, 
            0x35E5AC8A480867FDULL, 0x54F3571D1062D30CULL, 0xE02D0122B177938BULL, 0x4175DA710B4331E0ULL, 
            0x19581BDB15693E86ULL, 0xC24BDE6A617BF276ULL, 0x7794A31736D8307AULL, 0xDB2DB6F61133F49AULL, 
            0xEF01DB60558A9726ULL, 0x122857A7F1496047ULL, 0x1D31D74AD31CB6B1ULL, 0x5E27D19FBE0E4EEAULL, 
            0xCF42900A2BC7AE14ULL, 0xF99FA4A23CA2FF25ULL, 0x93B92216740B0C12ULL, 0x15570960884E2726ULL, 
            0x4D929150E5509284ULL, 0x12AC1065B4410397ULL, 0xF778F01EC96FFB39ULL, 0x93E25210F08DC5B1ULL, 
            0x07E226A359B7DD7EULL, 0xFEC7D016ABB7A179ULL, 0x3EA272780894B674ULL, 0x0D9E094A5A0E6F56ULL
        }
    },
    {
        {
            0xB584C80FBDCE1B32ULL, 0x02DCE9A965150941ULL, 0x4755A4C172C85932ULL, 0x2BF08ACAA3F6A145ULL, 
            0x9D233DFC527401EEULL, 0xA6AA9153489ECD13ULL, 0x36063F9A84B59AFEULL, 0x6953B034F7D22506ULL, 
            0xA2BE17872A189A77ULL, 0xCCEAA1848A76D0A5ULL, 0x921A64889D5A898CULL, 0x60EE1CA1346DCA51ULL, 
            0x4B679EA4F24ABB3AULL, 0xA20499A95F9EF185ULL, 0xAEE98708B923DBF1ULL, 0xB09F27CF68322F42ULL, 
            0x7A19515C132685D8ULL, 0x34DD1499C3105CC9ULL, 0x9A587AB0DF1AC9A6ULL, 0x129283CF36F7342DULL, 
            0x3322975C894F8A2BULL, 0x9EEEBA1B3F159DF1ULL, 0xEA31DCEE97BABCC3ULL, 0x43E997BAF2BBEB4DULL, 
            0x460441CF99168611ULL, 0x8ACED56A8D5719EBULL, 0x2A9A71392CCAE4AFULL, 0xB532B0D5815C3F4BULL, 
            0x844E9E21F37D5270ULL, 0x736EC5D0E214BBFEULL, 0xE1942A637FDFB21DULL, 0x70666B310F1A220CULL
        },
        {
            0xDDF19235D43CDC77ULL, 0xAB961C7E83763C9BULL, 0x92EF0CC9131F0192ULL, 0x4439416A19102CA6ULL, 
            0x67A5DFF353495F36ULL, 0x1D8373772D9E9D71ULL, 0x922DB954581E7DD9ULL, 0x30136901E8CF0D10ULL, 
            0x3D88F649AB64E2B1ULL, 0x4F6B77F99134EF42ULL, 0xD75DE1BC06D099E6ULL, 0x185584DF157BD5EEULL, 
            0x3EA4E0BC77B4246AULL, 0x801513D30B348803ULL, 0x2D00DC97E1585861ULL, 0x4E5AA455E314E014ULL, 
            0x461FC03BD9A5C84CULL, 0xCE8B76902408C8AEULL, 0xE89C49DC9A96F4B1ULL, 0xD83959E33AC0F0C7ULL, 
            0x2EE9F73E5F934174ULL, 0x4D2AD7FC8E283D25ULL, 0x5DDD9365CED60772ULL, 0x04734915A053ADE2ULL, 
            0xF433E3B6E89DF060ULL, 0x7703EE748C581ECFULL, 0xE7014C93CEF57F27ULL, 0xE16E5E4F1FC1B704ULL, 
            0x0998BFE2906716E6ULL, 0x1697A04584844A40ULL, 0xFECB6C08F994C00CULL, 0x985788A4C80CC933ULL
        },
        {
            0xD285C672D8E3567CULL, 0xA9F2AAAA0C21DF8FULL, 0x22CAF51DFCC21798ULL, 0xAB83C73FA9591375ULL, 
            0x4CD09798D863B8D0ULL, 0x9B38ECD3E79ABF47ULL, 0xF80E4C22BC151434ULL, 0x2F06D0AF81E81978ULL, 
            0xDA90B789F4795AFFULL, 0x1908CC00D1AD38ABULL, 0xFD1A3DFE5B2CB3E0ULL, 0xC909EF88CA802610ULL, 
            0xB8F2AD12862BCFAEULL, 0xAC27CA3BA8702AA6ULL, 0x926295673CA65089ULL, 0xBD76670FD215ABDDULL, 
            0x22F15403F4A48576ULL, 0xE144D05015FDEEC6ULL, 0xEB1735D095682730ULL, 0x5E93B9619EC02491ULL, 
            0x508D6EC61E84094AULL, 0x02FB03D3CD96FF88ULL, 0x4441B0740488838EULL, 0xD980DB70D683041FULL, 
            0xC8121C98A7FDB5DCULL, 0x857B754EDEE0B5E8ULL, 0x7D8429381430F74FULL, 0xC428FC89CC4CF4B1ULL, 
            0xE1B757E573199CE8ULL, 0x3281A7377F5702C3ULL, 0xDB697C3D76FC7FF6ULL, 0xB37314953DA5C181ULL
        },
        {
            0x48B984CD4B22D0EDULL, 0x88020FFDC68E0E83ULL, 0x50EA6E9C8880CD70ULL, 0x06819C5369C1F177ULL, 
            0xE006579FE6A1CE73ULL, 0x4713697565E0E365ULL, 0xC978D12FD1FE35DAULL, 0xFC969AC0CF5CE24DULL, 
            0xB2BF38BC4C8C2E70ULL, 0xF7F95FB6375BA952ULL, 0x7547757715E1ECCDULL, 0x757D531D502C5B45ULL, 
            0x546530A9671C93FAULL, 0x305A543A790F5F24ULL, 0x49C554AA39F99AC6ULL, 0x343AEB87A7B47B1DULL, 
            0x60945ED0ACB2BAE7ULL, 0xDEC20E2A3D3AE705ULL, 0x17B27171CE2751AFULL, 0x8E3E35B544CB82CDULL, 
            0x12E153EF90A5A424ULL, 0xECA86503F4932F7EULL, 0xACE1CAE950746847ULL, 0xAC3D8672236704D3ULL, 
            0xECCA0697F001525CULL, 0xF9C33E7A601EC5FCULL, 0x826D579FE2C71A6AULL, 0x94DDFAF6E73A6F02ULL, 
            0xCB886B24B33D7BE0ULL, 0x3327FCC115D342E6ULL, 0x4EEF542557DCD131ULL, 0x569BF6A74C9DF36CULL
        },
        {
            0x3D26A25A5B8FDE25ULL, 0x62CDF4A08638ABA3ULL, 0xF65FACADE52AAC68ULL, 0xF16BE49204AF47BDULL, 
            0x35EA3A3D7FE6788EULL, 0xC25BEC165A5E2CD1ULL, 0x61DCE5405E3C269FULL, 0xCDA5A4DBC7F27B57ULL, 
            0x0E58D4A916C8E2DAULL, 0x38C96845B81798A0ULL, 0x0C367DCFB32363E8ULL, 0xF8C288CC018F85A7ULL, 
            0x1F676C49EB3AB19BULL, 0x82C6BF59C73A49B3ULL, 0x4D2A0E03B29EDC42ULL, 0xCE976FE8E353A37CULL, 
            0x20282BE64F3855D6ULL, 0x1A0EAF673B274AB1ULL, 0x8D30D23B7EB7AE65ULL, 0x860A82DFBF40D34DULL, 
            0xDB88B139F382D868ULL, 0xF5BF07CBAC9B3211ULL, 0xFE7829EF3E178C7EULL, 0xAA380844E2B86945ULL, 
            0x6DBFF0C76A9DDB72ULL, 0xC8DED879E36C7C1EULL, 0xFAC11A1ACD38E769ULL, 0xEE88AC895C42AC78ULL, 
            0x4DBBCE13B7A4C221ULL, 0x876BFFC217F5B573ULL, 0xE54ADD5E56173BE6ULL, 0x0F80BB275724C733ULL
        },
        {
            0x3D161583F43740AAULL, 0xE0B1CA489E83CC5AULL, 0xFE5E8C0638848FEAULL, 0x4E3B4C0DA2C01C83ULL, 
            0x5495301713A43069ULL, 0x96D90956174E7708ULL, 0x666F20C986110E23ULL, 0x498C26A6CF9731F2ULL, 
            0x6D0FC6D547D3BE30ULL, 0x772FE8EF8D7136C7ULL, 0x61C364EDB575CA87ULL, 0xEF125B5BE30BE4BCULL, 
            0x4CC439B17FCE2233ULL, 0xDA80A3CA537B8A52ULL, 0x01D00324FD4B43D6ULL, 0x5AE65450E416FB13ULL, 
            0x2CC8DAB3D9317E69ULL, 0xAB9BA224AEC81458ULL, 0x4A01A4C981DB4A63ULL, 0x9FCD1CF1D7980DF4ULL, 
            0xCC45F0253AACAD74ULL, 0x27E54EDEB16EB866ULL, 0x2BD05D2D11DE7148ULL, 0xB71072C097DF4235ULL, 
            0x355AF30AFA36E051ULL, 0x908FE747A3A6FF8AULL, 0x4361CCA0946E4F73ULL, 0xA2E771D13F044DA1ULL, 
            0xAB6041375F5790CBULL, 0xC5844A4F81296CDDULL, 0xBBEC6CF8D0FB36E9ULL, 0xF4661F58E0A49BA6ULL
        }
    },
    {
        {
            0xC5930FB6A32EA085ULL, 0xBDA18AB63D301E3FULL, 0x9D11D8B9D109F679ULL, 0x03D964B2C9F06121ULL, 
            0x599E9CCA08F070ADULL, 0x65003E05400CF3CBULL, 0xF5F56FF8CAF408E4ULL, 0x228ABBA07B3C279DULL, 
            0xFEB3101279601C16ULL, 0x8BFFD9A57FDBC8A0ULL, 0xD3B8C67CAE251223ULL, 0x39547BC5BFC619B9ULL, 
            0x0A4FC636C50A14F6ULL, 0x3E06AF0BEBD306C2ULL, 0x0F7E8C82F98B6A92ULL, 0x51B98007F76223E9ULL, 
            0xD89AABF60405176CULL, 0xC4E81B1B037B6E27ULL, 0x171A379FA14EFD11ULL, 0x506A334A8BCFF62AULL, 
            0xC1B71BDE4D4505B4ULL, 0x40657E74B797B185ULL, 0xBB642CDA584CAD32ULL, 0x4E5EC65EACC780C8ULL, 
            0x56EF670C4939BE96ULL, 0x5689DD850C9089D7ULL, 0x5B03842DAC49BD8CULL, 0x4D181E5E6949C104ULL, 
            0x9A6A155820926239ULL, 0xD1DBE3E6A1B55187ULL, 0x91EFB41AEBA26D26ULL, 0xB097D808573F6A85ULL
        },
        {
            0x78BBE399BB8E2F0FULL, 0xBFA493DA48414CADULL, 0x63295AA0A5F65448ULL, 0xC4B0CA8A83576F29ULL, 
            0xD147592B4FEE969EULL, 0x97E6E44DA8A82884ULL, 0xDB2D5C1FA509652DULL, 0xAA3FF9EC96DAF4FAULL, 
            0x369951CB8E609DAEULL, 0x283F7982EA2B3985ULL, 0xBADD16EE2F467AB9ULL, 0xAD7A8F29337EED54ULL, 
            0x3096A2ECAC9BB80DULL, 0xE8BD4718D982D69CULL, 0x15ECB8EB229117F0ULL, 0x1658105C6088593BULL, 
            0x1C1FDB587D7A1026ULL, 0x36CCE19C4AC75F6CULL, 0x98BE09C399333F29ULL, 0xC9B10255CDA38EE0ULL, 
            0x4A0E4F5ABD4610C3ULL, 0xC4B45D27E0ECBB2AULL, 0xF4DE322C057D7EBDULL, 0x625B08F6A8622330ULL, 
            0x47A6B65DA7F46847ULL, 0x79D29B3FDB1CD52DULL, 0x77993565A640A229ULL, 0x69497972B23BF691ULL, 
            0xD0DD00B4A6F5D701ULL, 0x7F79D8B60987FF39ULL, 0xA2E34D5526D76AE2ULL, 0xFE8AEE0FE3BFCBDDULL
        },
        {
            0xC3942F5E6158E981ULL, 0x6BF27DB0EF995100ULL, 0xA3367292C6CEACC5ULL, 0x2668D6533473E92FULL, 
            0x9B9841881FE28BADULL, 0x4F7CF376DABD64B9ULL, 0xC21924A1FC7B1C1FULL, 0xE1C219FF6F217FFEULL, 
            0x17154C645A2C4BB1ULL, 0x2BEEA18A8C01EE24ULL, 0x4CA06C600FA83854ULL, 0x735979781536DB75ULL, 
            0xE0045D18741389BAULL, 0xCA497649141E39DCULL, 0x096B078BAA0A2ED4ULL, 0x72A2A1854AF4C8C9ULL, 
            0x652180F6FFABD2D2ULL, 0x9490A68CC9775550ULL, 0xAD262E605BA20DD5ULL, 0xE91AE970BFFB2A8AULL, 
            0x2514B036D7509864ULL, 0x051561A1087004D7ULL, 0x641D0F9C555D10A4ULL, 0xE34883B05445A3B7ULL, 
            0xFADDD6D499B1F3B1ULL, 0x4296F59D3155CF3CULL, 0x8A5B16EDB359AA0FULL, 0x5FA4682470767369ULL, 
            0xDC6A27953F4324DEULL, 0x2BA73FC943C050FAULL, 0x2A9A95519A15DC56ULL, 0x5958C4932568356AULL
        },
        {
            0xB87E1AE98CC61D5DULL, 0x3C2539A970BB3615ULL, 0x153F8D6A3988B773ULL, 0x8B71377F4A1BE095ULL, 
            0x213048BFC833D162ULL, 0x5F6F36D2AF75E8CDULL, 0xFA76E074211B3818ULL, 0xDF0A0ACB8B6A0C59ULL, 
            0xF8E0559F63E304EBULL, 0x14CE69D1E19CC607ULL, 0xD6D30FADD597847EULL, 0xCB07A5AD204C42F4ULL, 
            0x274D49D787D8DFBEULL, 0xB2A6822E6FCFD288ULL, 0x5FBFB53BF29C682BULL, 0xC7F954884427B74BULL, 
            0xE37B00852B11630CULL, 0x95A31BCAE3AB8DDDULL, 0x09EABB8168485378ULL, 0x4944DAC9F5A890C7ULL, 
            0x4F1AA6B4885F7910ULL, 0xEEF0879398E6E1EDULL, 0xFEE6614440DBA8DCULL, 0xFABA582EC1B559C5ULL, 
            0xC01E03F0DF449FDAULL, 0x6941B3762B3B9A25ULL, 0x29182BD696874C8FULL, 0xAE9D05EB3B71552BULL, 
            0xF9202FF0FF8B77FDULL, 0x9557205F4F9D27D7ULL, 0xED2AF4F86D3894BAULL, 0x24100D0960D3F23EULL
        },
        {
            0xD4EE8935745B0C03ULL, 0x28A75A63615D5356ULL, 0x0F40B4F76B47FD04ULL, 0xD5268CA333C12E1CULL, 
            0xBB94295CE1ED305AULL, 0xF3B4A1F753E5ADF6ULL, 0xBEE02F841E914B09ULL, 0x9793D0E42B20366AULL, 
            0xA315EBA55EBA48F8ULL, 0xDD2920DB66D9EB18ULL, 0x6E060C8FA70AA27EULL, 0x10FA7FEB1ADBD788ULL, 
            0xA320C76DB9A7B51BULL, 0x97B581B4B1860C32ULL, 0xCFE3B46068A496A8ULL, 0xD2E017D5CBB2154EULL, 
            0xD9BE05FA0220EA4EULL, 0xB41728B84FD5F079ULL, 0x2D7E9E927A615AC1ULL, 0xC00758F1BF1FA3DEULL, 
            0x0298E7BC33DFEC4DULL, 0xAE8C8559191862E4ULL, 0xD80C4BB7B9339F84ULL, 0x1FEB5D2903FA2D7DULL, 
            0xB469969980B44770ULL, 0x90EC9D572D682BB5ULL, 0x3194C739D49EF3F1ULL, 0x42CC883ADC62A08AULL, 
            0xC9B02CA7DBAE741BULL, 0x630B600BA6AE8C52ULL, 0x616979BB6024294BULL, 0x5956D1C2E2FA0F1CULL
        },
        {
            0xF67A6F8E0D0532DCULL, 0x381786507D24A647ULL, 0x0D96B4FCDCBAA99BULL, 0xC51A47077701920DULL, 
            0xE168519850728DA0ULL, 0x916D20781F6B8DAAULL, 0x8C68E3540655C205ULL, 0xA8C32A2842A77AEDULL, 
            0x78830B4DEF84DF81ULL, 0xC1B0B2DEB0362DD6ULL, 0x28AE99F1DA9FC103ULL, 0x4FEFCB855B600631ULL, 
            0x03DDE4C685A75C3DULL, 0x50198CD0F110A176ULL, 0x4BAED3AAF42872B5ULL, 0x7903BC3D43D6BC52ULL, 
            0xBD3F6A1975E59AB0ULL, 0x9A07A9F10E1269D7ULL, 0x8481E2068D75B8BEULL, 0x7399F54A6CB06CE8ULL, 
            0x2C50553F7150EA92ULL, 0xD1151550826AAC87ULL, 0xBADD072EDBBA9E86ULL, 0xDACE81059BA1650CULL, 
            0x02ED2055EA288684ULL, 0x62B20FB6DB090564ULL, 0xBFE8D48F5AA14912ULL, 0xF10846104838A797ULL, 
            0x170B41013949711AULL, 0xD6E9890EA8C7D409ULL, 0x03B50C826F976576ULL, 0x4295667F2951FCB8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Capella::kKeyRotateBConstants = {
    0xC5F208AAAED69300ULL,
    0xC83E8632BDA9653AULL,
    0xA50FBCCA56808D55ULL,
    0xC5F208AAAED69300ULL,
    0xC83E8632BDA9653AULL,
    0xA50FBCCA56808D55ULL,
    0x14F246E1A02EF9D1ULL,
    0xB2AA78B67D23341AULL,
    0x8B,
    0xA2,
    0xF3,
    0xA2,
    0xA6,
    0xE7,
    0x9C,
    0x06
};

const TwistDomainSaltSet TwistExpander_Capella::kKeySpawnASalts = {
    {
        {
            0x814EB72A4823E644ULL, 0x1DDF19258CC24769ULL, 0xE62BB8507FAC5D98ULL, 0xC8F0FD3E1722FA4BULL, 
            0xD9E7A621BB20D4DFULL, 0xB9172BA01DE3FF03ULL, 0x0D3E4D38C3390F7CULL, 0x0A44D144F1DBE79DULL, 
            0xA06EFF269EAC4A88ULL, 0x868F45B176D890EAULL, 0x84AC1AA680BC9B7AULL, 0xAF5CBED4C44DBD7CULL, 
            0xC187139A4C7F1D78ULL, 0x1B44BF6D972DCBA2ULL, 0xD4F78D0B85442EE6ULL, 0xBC52C6093915D4FCULL, 
            0xBB17E680EF2F994EULL, 0x7F99AFDBBDD2A286ULL, 0x015A18224CF4B3ABULL, 0xFDF583C3A31147EFULL, 
            0xC4D7DEE9775A267FULL, 0xDADE3CC124E57DDAULL, 0x39D07AA6FA8AD44CULL, 0x4E40CC6AC82BC470ULL, 
            0xD5DE0FAA1881BDD0ULL, 0x2A29CC004F937472ULL, 0xB00C9411E49162A8ULL, 0x5ADB86B4B1885541ULL, 
            0xFA285739E23D9607ULL, 0x968D12BDE60E2865ULL, 0xF305C693973FAD7EULL, 0xE57A0EBF298661BCULL
        },
        {
            0xC36A8E2A0AD80B20ULL, 0xAEF4DFE8A9CDD209ULL, 0x9BD429C1A1089A71ULL, 0x7D578618AA14BFCFULL, 
            0x44653EE18B9DAAE5ULL, 0x016E02036D5F6B77ULL, 0x95871A5C70442BEEULL, 0x9F73FFE91E77ECEBULL, 
            0xE0095E1107C8D036ULL, 0xE32B3A9F8C333F64ULL, 0xBEF925E65211105BULL, 0x21DEEB3631AB252BULL, 
            0x3C9B116C5ABDF176ULL, 0x40BB84B45AEF7825ULL, 0xB526EB59DFB54FC7ULL, 0x595A8465CEEBE42DULL, 
            0x429986A4C66DD793ULL, 0xBBB06839F7ED2EEEULL, 0xFCA27C36689F460BULL, 0x7951929E4CC5AC84ULL, 
            0xA5A13170C97EBD01ULL, 0xF39CD6B5B31C9F5CULL, 0xD0F41F9699FE77D2ULL, 0x52BB2293A460B314ULL, 
            0x1E93E60A9EDC369DULL, 0xECE6BD2C7E3A6D59ULL, 0x2AEDFB35B7BCBC8EULL, 0x9D5B8F8991B9FE89ULL, 
            0x612DC530FD7FEC73ULL, 0xDCD0AC97DEFB9363ULL, 0x8D44903321D5F120ULL, 0x6F8005050184C76CULL
        },
        {
            0x28D099FEAD04D8A7ULL, 0xC5CDE796FA77A0C4ULL, 0x348CBCBC4280E687ULL, 0x6928722453055D68ULL, 
            0x0BD90D3FE3F578DAULL, 0x78AC39CEA4938CB8ULL, 0x26849201AC3ADF08ULL, 0x350FB744AA503781ULL, 
            0xADFD1AF5C66C09C1ULL, 0xCD4DB5F67C6D47CFULL, 0xAD3940DA57520A4DULL, 0xFCF8FAA78BF11D35ULL, 
            0x53F7B6794540F9EDULL, 0x5D1DA2E35B188298ULL, 0x5376E1D3757F247EULL, 0x7C8892FAEB9DC036ULL, 
            0x05B1B9CB97EA4E75ULL, 0x4E83ED8EAD75E006ULL, 0xB575C52C8B35EB8CULL, 0x9D639F5A2831BD34ULL, 
            0xC0958B064CBCEAD0ULL, 0xC48128DDBB55F07DULL, 0x099A1E926FEC522EULL, 0x80EB10073A0264E4ULL, 
            0x8BE0BD7C6C0B7751ULL, 0xCEAA171E2A16C059ULL, 0xE9B7E60DC2B1CCD1ULL, 0xCCA3DF06ACE89A91ULL, 
            0x4E4DE0EB7F76C14FULL, 0xBE0AE37C4F6A5000ULL, 0xE18C04A536528438ULL, 0xD8D725FA7BF8108DULL
        },
        {
            0x322736F097E758E0ULL, 0x2920A0AF3C47F04FULL, 0x5CBCF03F4354E638ULL, 0x4082E792FE16445AULL, 
            0x23569374D7CC7650ULL, 0xC4E2F07A93F99AD7ULL, 0x7552369A124CEEF8ULL, 0x7D7D608F9CB60D9EULL, 
            0x73BF03EA2725BAADULL, 0x89FCF5965AB88538ULL, 0x513115F98DD77C28ULL, 0x7458146647A56B62ULL, 
            0x8290A40AB70B81A5ULL, 0x1EBD852C98EBC8DCULL, 0x149AD61F524860E9ULL, 0x0411EC357B0CBA67ULL, 
            0xE7C3FB3F8572F5B2ULL, 0x4F9C6067FA2F6BC3ULL, 0x48A9134DAB0C62CEULL, 0xDF4520A7D0396161ULL, 
            0x4CE6D7515BFA325CULL, 0x4119F360A685ABC6ULL, 0x86D1BAC2F3209876ULL, 0xA470F41CB1627965ULL, 
            0x2A646DA02F5C57A1ULL, 0x622EB0EA938350A5ULL, 0xC82E31E6B23C7B64ULL, 0xDAC7817F3CE8BB63ULL, 
            0x051716E63E5BDEE0ULL, 0x6631A73FB2D97BD7ULL, 0x5B120A6703FB9144ULL, 0x31DB619A548DA77CULL
        },
        {
            0x572BDBA837EE537CULL, 0x9B13961808CE8283ULL, 0x37CBFFBEC3A4B2BAULL, 0x1A96FAA6AA5F7BC5ULL, 
            0xAACF219E88F956D6ULL, 0x53086C71CE6CE4A4ULL, 0xE82DBB196E739827ULL, 0x58DF8568F2401E41ULL, 
            0x9BC82DD52BF4B650ULL, 0xA187E9B13ACAD846ULL, 0xFE93534E80CA7224ULL, 0xF19CB3C135E613C1ULL, 
            0xC64FA305CC7D610DULL, 0x0F2266EA98B85206ULL, 0x1FB73EA95366A31FULL, 0xB8DD208B7A29A7B6ULL, 
            0x1C7B4A81C97A46AAULL, 0xC4E1C75C920979C3ULL, 0xC0728DD4360DE262ULL, 0x771FE4B4644679B7ULL, 
            0x0D97E7E18F5E7DB8ULL, 0x955654865EDA370FULL, 0x48AADE233CBC9A59ULL, 0x7A1BBA5B3496EB8DULL, 
            0xD0FA2159E3BD483CULL, 0x3D4384D149F5E26AULL, 0x9ADCBB03D51BEDCDULL, 0xA100702BB66F5637ULL, 
            0x90799288009577C5ULL, 0xDD755F6BCC1A684AULL, 0x163C50972BBB2D98ULL, 0x63F6B22D2A4B20B4ULL
        },
        {
            0x0E3CA4966DF908DDULL, 0x8E13EBC7F441A17CULL, 0x0C3A7D3216AE172AULL, 0xD36C9E15E15F6A3EULL, 
            0x7EEA7E2CD2469823ULL, 0x41DA764D29B926AAULL, 0x99FBDAA088B01CABULL, 0x0832D25CDD93DE8AULL, 
            0x2623BBBA12F00FA6ULL, 0xD643325A75AC8F90ULL, 0x1C2B6B2E19EF3DE7ULL, 0x0CD883A275DA868EULL, 
            0x4F0CB83EC26EFE87ULL, 0xDD1474EC22B3C44FULL, 0xF7D3273E970728E3ULL, 0x0FDDBC785DB7E3CDULL, 
            0xA2C6FD0DA4B2AD1EULL, 0x682EA06C46850AC6ULL, 0xFD3DD7D322CA50D1ULL, 0x774CA703B59FA8FFULL, 
            0x6E59B330BC8C14CAULL, 0x385F9B33A0F14A5DULL, 0x6FFA4B38A4A4C7B1ULL, 0x968C428777411A91ULL, 
            0x4F2886A2A16449B7ULL, 0x7D6F88FDC8B0D8FAULL, 0xE61F7982784E51C2ULL, 0xE0ACC4AD18C60D98ULL, 
            0x0BBC9F64791C083DULL, 0x84B3945CAEE02D60ULL, 0x5E1F1509832A394CULL, 0x99F08F83D2F2B1F1ULL
        }
    },
    {
        {
            0x607E1A14A1EFF36CULL, 0x89322EE82D4FECC1ULL, 0xC803990EDA922356ULL, 0x98D2F98268EA6EA1ULL, 
            0xEAD900A405900055ULL, 0x9F0C30604FACBA31ULL, 0xFEEC0BFC7F41831FULL, 0xE0CD2D86CC72734EULL, 
            0xA5B26BA45FEC1FCBULL, 0xA2F0FF069084E644ULL, 0xF63C5FA59FCBC0A6ULL, 0x3B77348296452B5CULL, 
            0xC2A62F4861861C0EULL, 0x1A4D10AB0B6A9AA9ULL, 0xBF527ACBE32FD734ULL, 0x2DC35462BB61F94DULL, 
            0xC4BF7AB0E1AD3C34ULL, 0x5EDBE3059D7870A5ULL, 0xA3149FED309988E8ULL, 0x261CB8F79BFDEEFBULL, 
            0xFCA53B7792613E55ULL, 0xF4EB1CFA5F3F04A1ULL, 0xF998721771BCCC3AULL, 0x2831D8598FF4CAB1ULL, 
            0xED4A49B6D7F83F8BULL, 0xC11514CC7168EA86ULL, 0x42CFD5A0F7B4DCC1ULL, 0x0FBB513AEF13D586ULL, 
            0xB4B055807706421CULL, 0xBE3D0A528004E5EEULL, 0xAF33CBA52491708DULL, 0x96BB8F2AC703234AULL
        },
        {
            0x01900A2EB0BCAA09ULL, 0x6409BB2BD42103C4ULL, 0xC0377522AA239F9BULL, 0x6DC76DC346522A52ULL, 
            0x7F62182ACB8BF8DBULL, 0x88A920E356509DE6ULL, 0xD1273FAEBA2E4704ULL, 0x55E0EACD8CEA38CCULL, 
            0x306CC4F6F114FB1FULL, 0xE5BB365298C43513ULL, 0x0563F0F1E719C04BULL, 0xFAB35788A61EEBB4ULL, 
            0x67A64E8897890C05ULL, 0xB88C25EF1D014A40ULL, 0xE18420B6D9A20359ULL, 0x2865929154C2CF12ULL, 
            0xD7FBC400F1108E78ULL, 0x44C5122E32494B2EULL, 0x549EC5DC76191ECEULL, 0xD1E30F43EB6BA56BULL, 
            0x4BEB71A373F509A2ULL, 0x929E8CE5277258B1ULL, 0xEC928E5C908F8A96ULL, 0x448A42EFE3B71A80ULL, 
            0xDD642CD1F8A7B8C6ULL, 0x63C0BE1D7E913DF5ULL, 0xBEC34137477C0686ULL, 0x487C31C357830203ULL, 
            0x6D323C5B6D273E82ULL, 0xF37D53BA82701BE3ULL, 0xD2A700938574C53AULL, 0x622DC011C6240F6CULL
        },
        {
            0x009DE2219D3A56A2ULL, 0xF26EE52F4F0D2DE9ULL, 0xB310C1F62A576526ULL, 0x4690C71BA22AF1CEULL, 
            0x9877AB511A363DBFULL, 0xA31653ED1C3EE069ULL, 0xC9FBF023C626E878ULL, 0xC30B5E4E60EDAC92ULL, 
            0x0C27BBEB923421C2ULL, 0xE0FEF05E16C1A0A1ULL, 0x44EC4E895F8A2F9AULL, 0xEBA5D9E7846758ACULL, 
            0x1654C618087895E8ULL, 0xF563CCD699C436ABULL, 0x2461DDE733B86782ULL, 0x7380EB09E4BC17E8ULL, 
            0xF66EDF8B3F84568AULL, 0x9F52B14D04EC7BE5ULL, 0x728BA7BE0B690363ULL, 0x9ECFEE03A3B59709ULL, 
            0xC8751BBD2F385146ULL, 0xBEBEEBEF696CEEEAULL, 0x43AA76814064BD46ULL, 0xDD4E431E60FF14B4ULL, 
            0x9E4FAFBFFE287EB2ULL, 0x29D6BF8711AF66B5ULL, 0x20A3A99942DA7C85ULL, 0x90E25A1289CB5577ULL, 
            0x9A3604502BA6382DULL, 0x60237D0C3BEC4189ULL, 0x6E34EBA8FEBBAA91ULL, 0x96C06E6BE29E21D8ULL
        },
        {
            0x454C0988E44DE94BULL, 0x94F973C0E4242314ULL, 0x03070CB1E9274B8AULL, 0x6C716AD5C3A431FCULL, 
            0xB8F5DE4303E5E297ULL, 0x31A20370D8DE36B7ULL, 0x72C7759540C14E72ULL, 0xD3838B0F86798EC4ULL, 
            0xF46E3EC7EDEB78CDULL, 0xB5042CCE182F118EULL, 0xC17FE2B5DE08F17BULL, 0x2A1AF1DA0FD93D89ULL, 
            0xC3D0EDFE620D448BULL, 0x89FF9CBBEAD661A6ULL, 0xD2EA78D7EA5456C4ULL, 0x3B4DD52286AC7BDAULL, 
            0x1DA953AD85B84844ULL, 0xD477894300618FA1ULL, 0x169C8E0E4203E125ULL, 0x979BD10055390E9CULL, 
            0xBE1B6D00D73CF5E9ULL, 0xD6C858C232F8A93AULL, 0xAFFC1E306FAB4B4AULL, 0x32F47A9121139F6FULL, 
            0x01058C7039E0942BULL, 0x2029EA692C53023BULL, 0x30C4985DADF9FFD3ULL, 0x9F75D718CE16EB1FULL, 
            0x83B01848954842E4ULL, 0x31E217FF5635F3FEULL, 0x9541A80017F4A4EBULL, 0x5D0E151EE05D2152ULL
        },
        {
            0xD5BAC65E92BD4169ULL, 0x7FFEF27210263A91ULL, 0xD87FF09C56C38B53ULL, 0x0D39631DC8EEF73CULL, 
            0x5960BE245DD4F1F9ULL, 0x1768E26EAC0E03B1ULL, 0x883744AE15341D7CULL, 0x985D7E4C85420549ULL, 
            0x0E8D0C8539E1856CULL, 0xFD147D35DA021409ULL, 0x758781644403C324ULL, 0x638CBA3F7CEB3244ULL, 
            0x2553C76E201EA599ULL, 0x287065D19A6FCB79ULL, 0xB6C85001DF512AD1ULL, 0x0B956130B47478C2ULL, 
            0x9AA721948F53B770ULL, 0xACB89057B6AC29A1ULL, 0xC1589EFCA2227EE5ULL, 0x5806AC54D8B30C8CULL, 
            0x8AE87DEABCCCA86AULL, 0x72C16E407CE7217EULL, 0x47034C51C7733F61ULL, 0x48EE644BFCA62917ULL, 
            0x193A817D045C54D8ULL, 0x7B3B2F9E83325AC3ULL, 0xA588A0C1E970D2ADULL, 0x79ECA42CCE1F4C14ULL, 
            0xCDEB3637C65BB15BULL, 0xC06CF6A68FF2FD63ULL, 0x395B937C2A5CD4AFULL, 0x3515B07EC652BAA6ULL
        },
        {
            0x27FB50E912AA7C83ULL, 0x543035BBAE9A76E7ULL, 0xBE00DEC5899BF96DULL, 0xB2909DF367AD6151ULL, 
            0x7640BEB3C1D1179AULL, 0x357A19F5CEEA2A35ULL, 0xF7F803CB3980A9E9ULL, 0x67C2515ED73B2B4CULL, 
            0x871E5CD653F5E2DCULL, 0xBAA09F0B996D57E6ULL, 0xA76573582A66BB9AULL, 0x26E2FAB76B5BA649ULL, 
            0x92BF0ABB0ABB5ACBULL, 0x29AED2FB8D2F3AE5ULL, 0xEE477663680B85D3ULL, 0x929F7CEB77FAA176ULL, 
            0x0265648417A31311ULL, 0xEA5F2FFB00F8B042ULL, 0x2F6B23F2F9A9C35AULL, 0x682DA0AEAFF2D9D0ULL, 
            0x810D9FEA60E6145BULL, 0xB06F090E980DBA57ULL, 0x006BE28F824539ADULL, 0x6E95DB1CA841FB69ULL, 
            0xC31679DCFEA5E47EULL, 0xF073B5E76AFBA7F7ULL, 0xEEFF6B51A1E4955EULL, 0xD27C93E0EC64ABB6ULL, 
            0x0854BA9204A35033ULL, 0x8BAE1BBA29B921D3ULL, 0x272B50904CD17EA8ULL, 0x2EE57889E6007012ULL
        }
    },
    {
        {
            0xE8866297DC7D3F3EULL, 0xAB603F56FE4EBF93ULL, 0xDC63EC6BF60F8EBAULL, 0xA9C0391B147EA5E0ULL, 
            0xDF6A9C415E6AAACFULL, 0x5560000BA7F392D8ULL, 0x147C3386AC6CE494ULL, 0xCBD2035A7D385B5AULL, 
            0x2B59A0F458EB93A0ULL, 0xEE4D60F7B46B20E4ULL, 0x49304E2A729D09A4ULL, 0xACCCCE840B87AE6AULL, 
            0x65F3B03ED5FA6F4CULL, 0xF8015ACD180DAF37ULL, 0xEF64B0577ADCC8CAULL, 0x1C90DABCF5911010ULL, 
            0xFC6453709985B55EULL, 0x880369ACF3110D29ULL, 0x2C6A42E988332C24ULL, 0xDA378EF761F70889ULL, 
            0x5427753942E383DCULL, 0x1B477D8EF3DBC53EULL, 0x791ACBAB42E4BD1DULL, 0xA9871A85A49EC45FULL, 
            0x5DF262BE01F51B75ULL, 0x99CC3967C6FE7037ULL, 0xFAFA9779392F8687ULL, 0x8407A78119FA367DULL, 
            0x0A96499F42472EF6ULL, 0x105A0A5CA51E7726ULL, 0x961ACBA8B8C42EE3ULL, 0x1C182331069C7A6BULL
        },
        {
            0x1BA31D3FE140D6E6ULL, 0x2A24DE435BA3C885ULL, 0x0C9F7545A7DF7154ULL, 0x037E54ADEC50C696ULL, 
            0xAFD80DF5D2F5900AULL, 0xE1FE374F5982C535ULL, 0x6533ACB32F2475EAULL, 0xE7C9874F82ACD8BFULL, 
            0x583C7882CF6D5103ULL, 0xA24BFE804B60ACFEULL, 0xBD0F274E81FFEDA6ULL, 0x41C74DD327FA987CULL, 
            0xC59CA58B1FC9EFD0ULL, 0x9EE6F4B387F44147ULL, 0x474B6E508653863BULL, 0x84818B8AB87FF5BCULL, 
            0xAFAB038ED916F097ULL, 0xBCEA7823CAD37BA9ULL, 0x160C55DF4AB396EEULL, 0xE36AFADDCB5E5F66ULL, 
            0xC141396B7652B86CULL, 0x773361FD68340946ULL, 0x5318ECC92CE90972ULL, 0x55D4F2B6FA8A4F0DULL, 
            0x91F97017CAD486F3ULL, 0xFEDA2E71F1174682ULL, 0xABBD1DC6FCD0D9EDULL, 0x3043CEE85D4ED7D4ULL, 
            0x1DA0FFC9B3B64816ULL, 0x94B1996B136F9149ULL, 0x31156256C4EBE299ULL, 0xD1BDDC56A7D7093CULL
        },
        {
            0x8B0F453C69EA9E70ULL, 0x68E6939AE12CAEAAULL, 0x1584A25500E8CE58ULL, 0x97689AEA60B20B00ULL, 
            0xBAC022521E40F323ULL, 0x94C89AAC32247EAAULL, 0x005DB6CFC4DFDF8EULL, 0xA15F55719B6ADB59ULL, 
            0x7D788B9EF4DC4685ULL, 0xDEFBF92CD74D3B66ULL, 0xF6E5A84890BA235BULL, 0xBE343E5205BFB58DULL, 
            0xCF738F265682607BULL, 0xCD67F41E8A95E3FEULL, 0xC21CB671D79DE5C6ULL, 0x1B45E6D17523DCC1ULL, 
            0x6A3E6A2ACD0D0E60ULL, 0x1007B9C8573A1210ULL, 0xA5D7529E26652CB8ULL, 0xBC355C6ED488C3CFULL, 
            0xF78F70CA6759808EULL, 0x0BBE440F05D0882EULL, 0x753891A28CDC1ED6ULL, 0xF54B55E283CEAC55ULL, 
            0x977D0FE9DF2D298EULL, 0xC076A3044C3DDDF1ULL, 0x0D363F54BA897971ULL, 0x3916C5B9A2A4B7EAULL, 
            0x482B9F2261695E3BULL, 0x6FCA41B02131E52DULL, 0x29C217F05F685301ULL, 0x782F1F54BFC91A1DULL
        },
        {
            0xFF0CB362E2588ACFULL, 0x3390A41753FF0449ULL, 0xD795FE0493599519ULL, 0x2648A152DDB0E498ULL, 
            0xA0AB84C67344F270ULL, 0xD6AE4C7182127427ULL, 0x3FAF9493334B1FCBULL, 0x286F8AE55E968DC2ULL, 
            0x96BF05E66F680327ULL, 0x11ECE075ABE0586FULL, 0x83AB0E9E7422EB70ULL, 0x6CF6456D06E32AA7ULL, 
            0x1916E5A9A332CAF7ULL, 0xE11E2EC5CE335A91ULL, 0xF7852D95F4B2709FULL, 0x8F26CBC2EF44FF01ULL, 
            0x22A2C749C91758FAULL, 0xDDBBBD90432097E4ULL, 0x2723731A413F5CE4ULL, 0xFE36023D4CE2A478ULL, 
            0xBFCF75A001074855ULL, 0x585FEA2B2163F539ULL, 0x6BC88C8209B56810ULL, 0xA33A5037D2F0E974ULL, 
            0x992FDEDC35258E4BULL, 0xC5A73B016B271DAEULL, 0x09217B38B0147F4CULL, 0xA416EFF364E0F908ULL, 
            0x6FE9AFCFCA656B7BULL, 0x4AD8449261827F92ULL, 0x6C0D347B389B1440ULL, 0x203FE8A198269DC4ULL
        },
        {
            0x4E8417BCA45475A2ULL, 0x20A1FA08689F2374ULL, 0x9A6F70D579579F7CULL, 0x7109DEDD3798361DULL, 
            0x87795051B5C4CF44ULL, 0x3783F8219029DFFBULL, 0xB5438B50FC5C24FEULL, 0x55FBA900432B774FULL, 
            0x0A9DDF61D6D4C329ULL, 0x72927FBF6D780AA7ULL, 0xB5CD22AE86C2B640ULL, 0x700DAD7E0FAEDCE8ULL, 
            0xC2093864F8986AB8ULL, 0x687214C6C3D68B02ULL, 0x66D62F8D14798076ULL, 0xE5661FD61EA6A653ULL, 
            0x11E55507D8B6700BULL, 0x0B8D32C6C3736392ULL, 0x4AEAAAC3E065954DULL, 0x9009E2C36EB9CAE8ULL, 
            0x9D492A971C329A70ULL, 0xE2FBE9B3FA2D7398ULL, 0x205A983F63A130ABULL, 0xBEBE972D93CCA2E5ULL, 
            0xD549073C92CA5923ULL, 0xA51C2AC477C8FA97ULL, 0x9E1B54D96239279FULL, 0xF6F9AF3A3710FE42ULL, 
            0xD0AD606D5C1D4DFBULL, 0xD9523C56F3933A77ULL, 0x5E27806766365113ULL, 0xA0CEC29B27CF0757ULL
        },
        {
            0x77A2A810C21C5A81ULL, 0xA77D2D8B84D72340ULL, 0x7D78EA6AE0459113ULL, 0xD085E4DE70FDA2F6ULL, 
            0x8A6417A9FFB92A82ULL, 0x65E4CEC554E7C25EULL, 0x07A217526D97C4D0ULL, 0x41D54AAC6DD1C598ULL, 
            0x6E6E70C8BC69A78DULL, 0x57F7875BE1940CACULL, 0x12DB6CA6E801BD5AULL, 0x6697FD9703F19916ULL, 
            0xF658CE809B17F3F5ULL, 0x826DA0C030825189ULL, 0x13B7AE6252B9CB77ULL, 0x4659CEABD88AE604ULL, 
            0xB7C431C498188066ULL, 0xBDA38E98641B8320ULL, 0x20CEAF2F05F141DEULL, 0x197CD654F1B98635ULL, 
            0xD6F32E215D6D2BBCULL, 0x08A6AAB0502B19BBULL, 0x8B20E0F8EEFBE968ULL, 0x9CD8FC585D0D8BB7ULL, 
            0xB98C1AB5B0480F7AULL, 0x377D768DD4876BAEULL, 0x808B70D9FB81C276ULL, 0x2593BA3F6E412D5CULL, 
            0xA2F209C4B330A68BULL, 0xD2F19CD351AF721DULL, 0x1286E65D85855F12ULL, 0x7367D0593A31FC3FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Capella::kKeySpawnAConstants = {
    0xFEEDA0E83F49858AULL,
    0x98BB780C9157CDA9ULL,
    0x1E6A396DA14C1AB2ULL,
    0xFEEDA0E83F49858AULL,
    0x98BB780C9157CDA9ULL,
    0x1E6A396DA14C1AB2ULL,
    0xDAC2358A03756064ULL,
    0xFEC5E18770BAF4A9ULL,
    0x05,
    0xF4,
    0x3D,
    0x7B,
    0xA7,
    0x42,
    0x08,
    0x64
};

const TwistDomainSaltSet TwistExpander_Capella::kKeySpawnBSalts = {
    {
        {
            0x21AFD056981D19F8ULL, 0xA5D03805387C3A22ULL, 0xE6D81B6BDD5023D0ULL, 0x604A81E195DC6875ULL, 
            0xB4D2A1CEF88C34C5ULL, 0x11B10275616232ECULL, 0xEEA2FB344190B55DULL, 0x6E9EA8185A2FB56EULL, 
            0xD99DEBAB3F24D832ULL, 0x3E2F6EC02701F25AULL, 0x6C0308DB309C8553ULL, 0x290D322EAA9A1FBEULL, 
            0x4658D84CE3410400ULL, 0x9649DA663609B2ECULL, 0xC40924D30C8D3A1DULL, 0x85A756BF71636730ULL, 
            0xFFE841C44494C403ULL, 0x872031FC93730003ULL, 0xFECD41DE40754FAFULL, 0x1048C7A5B97F733CULL, 
            0x1CA694AB156273BCULL, 0x3DF47C27F85139C4ULL, 0xD015CA56AA9A7FA8ULL, 0x9BF203B461B1B03CULL, 
            0x64D2A5FC7CFC578AULL, 0x81D041026B38EE16ULL, 0xBAC07053CF6893FEULL, 0xE3AED5F771CE33F5ULL, 
            0xDD3C4DB1D408C80DULL, 0xD847A11663C6719EULL, 0x78767ACBDAD0171FULL, 0x2067A3C0EFAD7772ULL
        },
        {
            0x87295A7EFAFB1E46ULL, 0x0D8EA9AB2BAF106AULL, 0x2481A37FD5132701ULL, 0x4BDD47FF00E43F7CULL, 
            0x1CD154D249C2FEFAULL, 0xBBC00E0FC953087DULL, 0x779710B43429CD41ULL, 0x2BFA90B48ADD28D4ULL, 
            0xC71DAF4FBBDD5C98ULL, 0x3DCE6AC10F316EA8ULL, 0x6083D410C8DF6309ULL, 0x891EFDE79B53F3B0ULL, 
            0x04D258CEAB7A0394ULL, 0x77666216EF914C41ULL, 0xB1E8D1770D02B64DULL, 0x7539EA2B2B75AE7EULL, 
            0xF19B1B07BB72DAA3ULL, 0x54C7558875C5D952ULL, 0xCCA4174E62FA5068ULL, 0x824F5BC866F427ADULL, 
            0x3E7921340593FC44ULL, 0x77A88DFD07E52B3CULL, 0xA5E16552B99D4C43ULL, 0x53FD338611961956ULL, 
            0xED38316371659D67ULL, 0x3BFBDEBEEE327266ULL, 0x27B3C4FA9CCF5095ULL, 0xE075F9CDFF150C66ULL, 
            0x57FAB314EEB3003EULL, 0xA04D931A217FBAC4ULL, 0x30FD973C38DA5B3EULL, 0xDAE8466EA8539C70ULL
        },
        {
            0x395014ED53252752ULL, 0xDAA34A97F80814B2ULL, 0x1995D0F0EC946B93ULL, 0xFAC4A6E9A311B1FBULL, 
            0x6E1EE92980EF0B91ULL, 0xDFDB446017A85544ULL, 0x6FE1B139A59F5781ULL, 0x5482676E39492687ULL, 
            0x684FBDACE8F8F35CULL, 0x401256CFEAE44627ULL, 0x82BB5CE7D26F0C7EULL, 0x6474B6999BB78230ULL, 
            0x8775EBD0A1A7E7C9ULL, 0x64A0EA1FC9383F47ULL, 0x304C9AEF1D5C7E52ULL, 0x246DC7A9B14F485FULL, 
            0x2AF1EBE114F1C127ULL, 0xFC7091E834C9BBCEULL, 0x504CDF7B20020B03ULL, 0x9F0682C79A2E0AA9ULL, 
            0x236F6273148460DFULL, 0xFA28EDEB1296FF4DULL, 0x797BA599043BFBFFULL, 0x7C924BC61F1C561DULL, 
            0x54EE6B0D87F2670DULL, 0xB626A971AA63FF4AULL, 0x211A1F949651C5E6ULL, 0x4D912794773D525DULL, 
            0x166AD37EC9E3C4C0ULL, 0x5214C1016A3CA039ULL, 0x61DAABCF2B592D55ULL, 0xCC17ED7BCB01FB7AULL
        },
        {
            0x98488AB21CF4764EULL, 0xACC594F3E353330FULL, 0x011EC2E9FAD9C719ULL, 0x4BFB5E9FE0DBF23FULL, 
            0x0851B630077C2F1DULL, 0x3EA49381728A8AEAULL, 0xE92C7E0CB5A96314ULL, 0x1958AA4179D74134ULL, 
            0x5991D72E0FA5C5F2ULL, 0x0D608FA4CDF1695CULL, 0x96DD324A3FBCD123ULL, 0x97F4642A1F25E458ULL, 
            0xA085026FBD39CF2CULL, 0xD7562C6F5ACDA419ULL, 0x42171D0AA406D800ULL, 0x78D017F2AA6643C5ULL, 
            0x35C66499731A765CULL, 0x5CDAB4FE943AC501ULL, 0x2BBD22115F236878ULL, 0x5A1B6AE366C4039DULL, 
            0x2A26B606986B8F79ULL, 0x28C72145288B95C5ULL, 0xE9149A6D16DA4A15ULL, 0x4903BB481F9C0A3AULL, 
            0x4A3F1D36111D342EULL, 0x17279CFAA9F8FB3EULL, 0xDC400448FCE94075ULL, 0x5D86B7F9C3986800ULL, 
            0x14DB949E7D044614ULL, 0x27E63A08C59CFCE3ULL, 0x56F6ABE1D5B72809ULL, 0x0BC7F1F5D32CB83DULL
        },
        {
            0x3C12B4B47EEDA252ULL, 0xD456ABDC13707738ULL, 0x4DFCD49D6F8DD4AFULL, 0x1FDC7E0C84B13A97ULL, 
            0x55C9DE8BA39ADBAEULL, 0x30D154FF2A1E10FCULL, 0x05461B5E093AE6F5ULL, 0x50C06E1695446D48ULL, 
            0x11BB863F34EE1A25ULL, 0xC2B1CCD34CC8503BULL, 0xDFA8A11304457660ULL, 0x4013BF6110CCCCAFULL, 
            0x2BA8B97D71E93174ULL, 0x82119125BBBCDDCEULL, 0x65A75724F5F5F704ULL, 0xC8759DD74E6E7A30ULL, 
            0xE9AD9B0CBCD59E22ULL, 0xACF3F157CF10189FULL, 0x55F7DD0E404C0E87ULL, 0xE58B37D27777A5EAULL, 
            0xB7B27470DD9D9401ULL, 0x5DD9AF6BA15B91C3ULL, 0xDBE0E194B1F25405ULL, 0xD8DE36B301272E97ULL, 
            0xF06FD3CC002A017CULL, 0x93990D3082EF6872ULL, 0x766B9F10EE33846CULL, 0xFE5BB7F32D35391BULL, 
            0x0136F4DF8B27B6F5ULL, 0x2292EB04310180FFULL, 0x8A31059DD7450111ULL, 0x28921B0D8B8B43F3ULL
        },
        {
            0xA29F784F4D618FA0ULL, 0xCA933E678BCDFA59ULL, 0xC7CCCCF9E3330A1FULL, 0xD607EF67756778DAULL, 
            0x767381ECA5CB6E72ULL, 0x03377B8D098A5687ULL, 0x68C0666BC5D086D0ULL, 0xA090DF64D62E6EF9ULL, 
            0x6E98E98613151909ULL, 0xAFD68F8752B537C9ULL, 0x6DFF76F226CBC9B3ULL, 0xF5370BC119E8D407ULL, 
            0x93D2F52CE7019121ULL, 0xDE8FBFFB5D54CB7AULL, 0xADB682D52D781693ULL, 0xAE1FC2D5C731B011ULL, 
            0x1220DA7D7A920D92ULL, 0xD71ED354237F5D6FULL, 0x06EA885CB6255626ULL, 0x37E4EA2892CF9845ULL, 
            0xBD9579986B1B930EULL, 0x58652061CDB0092BULL, 0xC68B06F11010E937ULL, 0x01C423DAB3B0362BULL, 
            0xCF35BCAA1C5466C2ULL, 0x9B83B235830C2FAAULL, 0xB0F5700B0CDAE337ULL, 0x0F0F96039117B1CAULL, 
            0x824DE4A681E54577ULL, 0x7068FC80074EA400ULL, 0x40C4786509941780ULL, 0xA169781B5C5B692FULL
        }
    },
    {
        {
            0x07B12DBDA7462C73ULL, 0x3170502F6AE04920ULL, 0x5665BA4450266D09ULL, 0x45BEB224BE696CABULL, 
            0x4A7408E96D833740ULL, 0xE44F377D66D7B0CCULL, 0xCC61E5B4A48679C1ULL, 0xDED10EF841052DBCULL, 
            0x74B978B27C2C8E38ULL, 0x98929EABE5B6C714ULL, 0xC5C2E896E6A1AB41ULL, 0x66E190266AAB6F82ULL, 
            0xA5AD0499B3249FE7ULL, 0x35384ABB94B3C75BULL, 0xFBD00E981AAB1E14ULL, 0x2B179BEC2EFAA1F8ULL, 
            0x1C1A74DD0615E431ULL, 0x1B7440041D2BEA1CULL, 0xD869B0059B40281EULL, 0x1408DEFFF5DFD4EDULL, 
            0xEB5C49DE42284951ULL, 0x610AD0A3D33D558EULL, 0x32A3CF9E7336ABFFULL, 0xA32613D923E35CC3ULL, 
            0x7CE5FFFC405EE479ULL, 0x39E9416D53F65C6DULL, 0x1FDB617D558B0756ULL, 0xCCC4344DB4595694ULL, 
            0x85DBCE2AEC31F8E8ULL, 0xB9F86AFA1563355AULL, 0xCB4A4F0A61E98313ULL, 0xFC2B66F896A9A493ULL
        },
        {
            0x97F444E37D705D4CULL, 0x77B5476C56500398ULL, 0xEA5724A6BA41EEBCULL, 0x33F2BE3E2E273818ULL, 
            0x055CA7924B6AE365ULL, 0x56283A750B23C01BULL, 0x8F9D83503547B35DULL, 0xEB2CA8D88CB6B375ULL, 
            0xE7A01C299BC62411ULL, 0x85348A2DB296E261ULL, 0x8B9617392EF086A3ULL, 0x205267915E344E02ULL, 
            0x0E668FE665ACD9F4ULL, 0x2E5EE6CABA382F98ULL, 0x72A2AF413C98F5A0ULL, 0x2151AAD1ED2E25B1ULL, 
            0xD7FB454F6103ACF1ULL, 0x7A3E29FC1A66A501ULL, 0xF8A5974E1AC2069DULL, 0x454D31D3E7697276ULL, 
            0x591DAA0CFC150388ULL, 0x65F407C4BF5A8684ULL, 0x32091567F92EB426ULL, 0x40BD12347B823CE3ULL, 
            0xDC74CB4D72498415ULL, 0xC349607E0D1136B7ULL, 0x97B74721192A4704ULL, 0x7A1DCB8B2199E3FBULL, 
            0xD571D4E37E704882ULL, 0x9683900A49F9A71FULL, 0x9597D899CEEE0807ULL, 0x6D73CFE3C3C3362BULL
        },
        {
            0xB4CE1644C279AE65ULL, 0x055012EC3519D806ULL, 0x4D64A99C096181ADULL, 0x1270EBD1C617D8A1ULL, 
            0x5308E6BC9C385D0BULL, 0x4A91D8B34B5CE0A4ULL, 0x440B8D1314501CF5ULL, 0x094317F592A07A43ULL, 
            0x3A9EB2BCB54C58C9ULL, 0x8D11F42F6DC1410EULL, 0x21FB8D598C533C50ULL, 0x1E14DE591CB08527ULL, 
            0xCD3925CCDEE7C812ULL, 0x5B7812135627513BULL, 0x5F97D0F11104AC07ULL, 0x95CCABFA0D297A51ULL, 
            0x859D6295210E601BULL, 0xB3F55ECB3B6F4C3FULL, 0xB83789179C066364ULL, 0xD2157497B1C34C33ULL, 
            0x84F40229E31B0457ULL, 0x728C6571A28B4970ULL, 0x7DE524DF74E54DD5ULL, 0xF3781F0FAAD1800FULL, 
            0xBA4E6642069EB987ULL, 0x1022D45FA3ACD7E2ULL, 0x8FBA5CDE7D290843ULL, 0x899A237C8D748AE8ULL, 
            0xB6C82EB6CC2EBEDFULL, 0x0E7519ECE7CDE292ULL, 0x86B072E84018B89FULL, 0x57E6D9FBA205FE01ULL
        },
        {
            0x0A51A574A3A26B46ULL, 0x8102C60099E28109ULL, 0x9A9B82B735709A59ULL, 0x3A854E94CFED2545ULL, 
            0x473B51D4D342417AULL, 0xBAAFA3DA92F52ED8ULL, 0xACE93036D66E929EULL, 0x461AC42CCC2A0A7EULL, 
            0xD18F905E4A7F9326ULL, 0xA68C1A6033AF20F8ULL, 0x72148B4F8FBD3E48ULL, 0x22ED14F18AD031D6ULL, 
            0xA3300D5C18433798ULL, 0x86394DB02754335AULL, 0x60D21F4BB28013A0ULL, 0x66E0617E745D7B2BULL, 
            0x02810370A78A6B2AULL, 0xC15DA39C844203C4ULL, 0x4943328E0057DC0AULL, 0x90D164818A95A432ULL, 
            0x3117BBAA6D90A778ULL, 0x4E688DA29496A03CULL, 0xB643FFF22D8BC3A8ULL, 0x292FE6CB2FE31B4BULL, 
            0x12BC06F1A6B26895ULL, 0x0C59C14C361CEBC8ULL, 0x30546BA338D94EB4ULL, 0x88EC76B0FB03B7AEULL, 
            0x1AA7963FCA02C10BULL, 0x5B23D744F5CF2648ULL, 0x9C891B0AD15BA909ULL, 0xE47BE92B45157546ULL
        },
        {
            0xEB2279FBB1A1BD7EULL, 0x0907CF306189C1F5ULL, 0xC44D896B85594365ULL, 0x0277447C5CD35297ULL, 
            0x3EF42B4DE03A5F4CULL, 0xE5D4B1BDA87DD755ULL, 0xF98DA9AF7D1F94B4ULL, 0xF9598F0A5E994822ULL, 
            0x90451E30A1AE255FULL, 0xF636E0F6E1134251ULL, 0xF03001D95671CE43ULL, 0xEC75541182ABA275ULL, 
            0xDDEB77E407C9E9B1ULL, 0x0BAAF6D79C2F59B9ULL, 0xF62CCA902FA2A083ULL, 0xAF278E60402F4115ULL, 
            0x50F8F47CD23E0D36ULL, 0x5E53435B2E453746ULL, 0x94D8404E16814618ULL, 0x1495FFA1DA66705DULL, 
            0x39F6F971ECAD6CB1ULL, 0x01A8EB1624C9953AULL, 0xB739E8B53C30FA0DULL, 0x485AE9778D53F04CULL, 
            0xD1361307089A7BEBULL, 0x598B30089309BE78ULL, 0xE5BD1360CE6ACE09ULL, 0xAE55F44F5CB79C99ULL, 
            0x3568F162701DA77FULL, 0xACC4071B67ED4C3AULL, 0xA7FC422F82ECC405ULL, 0x3D82701138B40FD1ULL
        },
        {
            0x121DEF4FA1332FE7ULL, 0x6FA4A8D105671D18ULL, 0x4075536395C667E8ULL, 0x059BF1B5734FDEF0ULL, 
            0x7E511EB5FED2F92AULL, 0x1ED9A04C8F11361BULL, 0x53F0923160B9D0A1ULL, 0x0A28AF18892BFFA9ULL, 
            0xAE49C599BC9248C6ULL, 0x69E3F1E5AA5551CAULL, 0x3B70F442AC2680F4ULL, 0x1D914989A3E97E9EULL, 
            0xF4F710BDBC719B13ULL, 0xCD40DBA15DBD13E8ULL, 0xAD94DAFCD0006880ULL, 0xE87907BB517E5CCCULL, 
            0x0F0C591D702143C0ULL, 0xBE64F5F4FCD4C1BAULL, 0x968BA9E2F2394C49ULL, 0x1DBE7494D4A73D7DULL, 
            0xFBDE566305211FBCULL, 0x39198994626E9DB9ULL, 0x87394071B77A1B2AULL, 0x379746095444202FULL, 
            0x899974314502C9F1ULL, 0x6BB9238407B9E0A5ULL, 0x1C53642A03271579ULL, 0x561B9F5542B04E97ULL, 
            0x7B4336053CAACB07ULL, 0x5AC87AE481DE248FULL, 0x61889485F296983FULL, 0xF339DE19AFD8A2DBULL
        }
    },
    {
        {
            0xD207BC23DC2681FFULL, 0xAE7FB3CF136414ABULL, 0x176FF33771C36CFDULL, 0xD3DD408A4C1DC5D7ULL, 
            0x685727B1B077693EULL, 0x3E85671EEDF92030ULL, 0x5E9E13B0B97D3AC8ULL, 0x7EE4D53CF1919D13ULL, 
            0x06E33C4799CBE9BCULL, 0xFF4D3B238D3DAA57ULL, 0x2E8EB020DC50231FULL, 0x382B277B9FA1A470ULL, 
            0x3C1BC115204657A0ULL, 0x886635514728D827ULL, 0x049B9E36C85D09C0ULL, 0x804AF3FC0976BE6BULL, 
            0x3860B3A5E7DD8D05ULL, 0x9D78988ED30115BAULL, 0xF22F639FDB87E817ULL, 0xB8F1AFE3B0691DCCULL, 
            0x2E58B4DB3AFA9949ULL, 0xB45757857BC680DAULL, 0x6777C5FB96897B9AULL, 0x20F419B628BD72A5ULL, 
            0x62F56C74028CF16EULL, 0x524D74E8E8F9C862ULL, 0x923CF4F6CD80D5BEULL, 0x8363ADACB9273258ULL, 
            0x49BBD7206DD14915ULL, 0xBCA624488E1BEE22ULL, 0x2EAA8855487382D1ULL, 0x933503755E09CF27ULL
        },
        {
            0xAC6EFA2F16FFA562ULL, 0xC281CF45E5ADD995ULL, 0x002CC6FB5CA4D1ACULL, 0x1C1BF09DCE572A3CULL, 
            0x59D9A4874AEA89D5ULL, 0xB5E7456497B74215ULL, 0xC3EB50EB81336863ULL, 0x31FB7AA1B1C2197CULL, 
            0xF64332BE2EF7B069ULL, 0x58259FEA88FBC253ULL, 0x6A72A3742D941D62ULL, 0xC44951727F83D152ULL, 
            0xDBA369A2DBFE4A8EULL, 0xE88C08DCE1AFE48BULL, 0xFDD11C83387B6DDCULL, 0x7C9D8D3653C36137ULL, 
            0x82ACEC1436D339CCULL, 0x6A2882A3F33936C6ULL, 0x7D8DA6E5A835A37DULL, 0x1EB9797E286CC4C0ULL, 
            0xF74CBDFF6E35EF6AULL, 0xBB39DE666E0C34E8ULL, 0x14B64B057D38A4E7ULL, 0x36ACA3E23EA47750ULL, 
            0x7E6AC3965F5A3759ULL, 0xE75F68A92FA75F3EULL, 0xC30F2D7C97F7E9ECULL, 0x5BA5514B0ED3A527ULL, 
            0x227FA3FEC0E5CA85ULL, 0xEE8C71B01637BC30ULL, 0x17D3452EC5A7EA60ULL, 0xE38F8761A5E50405ULL
        },
        {
            0x6C7A0AC2F7E0608EULL, 0xDB17FB0CECB3DA5DULL, 0xFBA07B1F053F2657ULL, 0xEC7F6CB60A9E7655ULL, 
            0xA2002E43A482CE5DULL, 0x72FF8DED3EA67492ULL, 0xDA2CAF1C5BEFCEE1ULL, 0xE9625633E429C20FULL, 
            0xF587C6ACF6ED77A8ULL, 0x84548B02B7437E06ULL, 0x30C88E77653CB413ULL, 0xFE49CB69749BFF1EULL, 
            0x1D86D7A322BF9BA5ULL, 0x7B1D72BD8E059687ULL, 0xDDA627AADC1FA0A4ULL, 0xF6F077F341F24696ULL, 
            0xCBCC75F4CB343850ULL, 0x941358E85E7034E8ULL, 0xA0485B3142A22899ULL, 0xCD8F76D0A568DFE4ULL, 
            0xE34D1FE64732E510ULL, 0xAE65CA75FEE0CD03ULL, 0x5DAF181DD7B068CBULL, 0x5B352B07CD818E02ULL, 
            0x570E0F6A08A63014ULL, 0x8BCCD37983B3CA5DULL, 0x8D881F73E0700A9AULL, 0xC8B68C0F2FF54949ULL, 
            0xE95A6B73C27FB639ULL, 0x06F3289F519590E4ULL, 0x0826E213A05D86CCULL, 0xA74068B0770DF104ULL
        },
        {
            0xB1F3CC54BDCC8C74ULL, 0x1AB0DD2F07BE0EA2ULL, 0x07B360D3F7C0F6C9ULL, 0x19E33B5CC2E78200ULL, 
            0x55775B3247C48387ULL, 0x16DA779A7175B693ULL, 0x92401DF7F3DE3322ULL, 0x7030DC48D5D9F0D9ULL, 
            0x5B3A244B0C796514ULL, 0xA55A42984FA74EABULL, 0xDFF0B6D76B5E587AULL, 0xD92283E7A986F46CULL, 
            0xEAF4B0DC3910897CULL, 0x17DC226C2736F316ULL, 0x0421FC9CBF7B80A1ULL, 0x2E038F03467E1BB3ULL, 
            0xDE57A8141C9F1545ULL, 0x92FC79647E1CDF95ULL, 0xE5F3762E390C0094ULL, 0xACABD97EB8569295ULL, 
            0x3770910E38ED5EDAULL, 0x1EF9D2ABB725A44FULL, 0xCED7F68F289F6496ULL, 0x8714532CD53AC555ULL, 
            0xB47A8F1F125F581EULL, 0xFBD8D16FA20E807EULL, 0xBCAC583BBA00818AULL, 0x7BF3F1C3EE561FAAULL, 
            0x54E9333354596FA7ULL, 0xC92977A20F2AA905ULL, 0x783419E0BF568CA4ULL, 0x9D715377547D3858ULL
        },
        {
            0x02AB66FE4B82A665ULL, 0xA8D6E3622F6A9CA1ULL, 0x08E786E6D1C4834AULL, 0xFFF4047BB4D3691DULL, 
            0xB2F86CBF411254C4ULL, 0xFDD6EB446E1BAA95ULL, 0x67F423B1DA04CD4FULL, 0x058DA0AD211C6069ULL, 
            0x55A421E12220AE94ULL, 0x05142A4BE1421BA8ULL, 0x831DDD05FFD9F625ULL, 0xF0A23E7952B21EA1ULL, 
            0x34BB014403B38FCCULL, 0xF7F9A77CE06E51DAULL, 0xF26695ABADD07AA8ULL, 0x73E6D2E9780B35A6ULL, 
            0xB06C7F931DF7E6B2ULL, 0x3504C4F887CD2724ULL, 0xC9697F50DB459383ULL, 0xD0CE1D8B2999B29AULL, 
            0x8020E91D1B3015F6ULL, 0x9D3DF50013B62A2EULL, 0x611B9FAA6866C66BULL, 0x59957E8582AFA4DEULL, 
            0xA5FB696686069550ULL, 0x7C477FDE0EC97C33ULL, 0xB84545B344B5C4EDULL, 0x3D1C55EAE15EE9E2ULL, 
            0x74FDC2E20A413B1CULL, 0xDB1362C5C24FF349ULL, 0x8BD502347557AC35ULL, 0xB9C9FBEBD823F227ULL
        },
        {
            0xFB48E35FDB02AE45ULL, 0x82CBA9C45FB679C2ULL, 0x5E8DC31F113CBD2AULL, 0x3F820352C7B0B263ULL, 
            0xD0B2F09E28809BDEULL, 0x2AC457C4C0ED776BULL, 0x7BE7E01098EF83C6ULL, 0x651FFE682B3E962EULL, 
            0xB8BAD6561587A2D2ULL, 0x89F646EF3A29074EULL, 0x60DC2657BE093294ULL, 0x3B75F97EC1B7D7ACULL, 
            0xF88083D07D8D6FF1ULL, 0xCFDA7334FCCB9708ULL, 0x4067E421136F5C9AULL, 0x757DBAF71B9FCA56ULL, 
            0xA343AB296E14D3C5ULL, 0x6ACE9371729DD852ULL, 0xA7BD5B8E9E48E7ACULL, 0xD39A252BB603601FULL, 
            0x1E087B4F91CA4522ULL, 0xC26D03B39DC1119CULL, 0xD007CDDC113627A1ULL, 0xCC98DD9504F0B385ULL, 
            0xEEADCFB94E2F9138ULL, 0xC695ADB0D894ACD0ULL, 0x040A11F35A8355DDULL, 0xD04CFA8FE2B053A3ULL, 
            0xBFE39CF9DE1F69A0ULL, 0xD7BA0DD06C26C29BULL, 0x7596ECE936720F48ULL, 0x665A23E8EA1F4610ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Capella::kKeySpawnBConstants = {
    0x5FA476CD90212A19ULL,
    0x75AD13ABC3A6CA84ULL,
    0xD83BB565E6F3B587ULL,
    0x5FA476CD90212A19ULL,
    0x75AD13ABC3A6CA84ULL,
    0xD83BB565E6F3B587ULL,
    0xC7CEB15CBB113C8CULL,
    0xB99F020ECA4451C6ULL,
    0x7B,
    0x8F,
    0x26,
    0x20,
    0xDF,
    0xBF,
    0x71,
    0x4D
};

const TwistDomainSaltSet TwistExpander_Capella::kSeedSalts = {
    {
        {
            0xDDE8ED63ABF89C59ULL, 0x2A5E11346AD6CDACULL, 0x06EE3E8E5D361BADULL, 0x8794D2F824E0C090ULL, 
            0xEB84AFBEEA6437ECULL, 0x9A27743ADBDE621AULL, 0xDF569F01536B036BULL, 0xA3B2D7FC751521E6ULL, 
            0x54B235F1542E41D3ULL, 0x150BF8C65C646B9AULL, 0x4DBBFF7940517FE5ULL, 0xF92519254B7E278BULL, 
            0x55265D78A26ACDB8ULL, 0x7974267B481B6DC8ULL, 0xA1E104B8D1292862ULL, 0xA6087774FAE5A543ULL, 
            0xE5443F8D5C9BBDE3ULL, 0x7D0F26563EE7B431ULL, 0x9011A8DF150B3489ULL, 0xF47B952CBC601546ULL, 
            0x074CC2F033A60CE9ULL, 0x53F9B0E249E0B579ULL, 0x5FAA6F9D077D4FA7ULL, 0x76832F7E57D64C5DULL, 
            0xBD6A516F53FF259FULL, 0xC8E39DF2F5ECFF4CULL, 0x1F010526D32885A3ULL, 0x645076A8E5C73157ULL, 
            0x3267F0F4614C68DEULL, 0xA7502F2570B224BCULL, 0xEC4657B2E7DCDF89ULL, 0xDA19982ADEE9708AULL
        },
        {
            0x783BA72A6D369302ULL, 0x202F1E94D1DB3AA0ULL, 0xC716F5BA0342BD9BULL, 0x80209D6BAEEBD1EFULL, 
            0x6BA15484B1241A2DULL, 0x6F1251B3CE5D0A36ULL, 0xCA32D50ED9DAA004ULL, 0x1F4D4748332EC3DFULL, 
            0x998E700713D27205ULL, 0x0BDDF516AFB380C1ULL, 0xCF3A20370C5AE96FULL, 0xCD11E9B847C0C808ULL, 
            0x7A0C117ACF976F8EULL, 0xAC91E58CDD33DDB0ULL, 0x56388EF9B045BDDAULL, 0x28091F394BD0BFA2ULL, 
            0xB07712810EADEF67ULL, 0x3DCC3992B768ABBCULL, 0x773F663A5B0A6A47ULL, 0x3121958CC8F4F8C3ULL, 
            0x5961F634AC447956ULL, 0x35D9CC9C63891CB9ULL, 0xE7E7C4E2D6039F70ULL, 0x85429E457D456BC7ULL, 
            0xD02F5E602DCA2E83ULL, 0xFB6CB371E4230ED2ULL, 0x42D574B92F4343A3ULL, 0xB046400E771712D0ULL, 
            0x32FC323F0B9AC6A9ULL, 0x8D226D38D45A3969ULL, 0x28A9CDCEABABA21FULL, 0x2752D858F71FBC15ULL
        },
        {
            0x60349424C71F3694ULL, 0x6E0269D51417DFD8ULL, 0xBA38309A50562A14ULL, 0x28843E00BDCC9567ULL, 
            0xA63EBE5A5A597D3EULL, 0x2C23F6789C5B3524ULL, 0x88E70A68B97F31CDULL, 0x8FE95E3FC05C4014ULL, 
            0x74E216DF704CF291ULL, 0x3A8826FC157672FFULL, 0xA5BD83C186968CFCULL, 0xBC83585BE7078C37ULL, 
            0xA350E43587E01974ULL, 0xFCEA156D9601CDF8ULL, 0xC538FDBE882B215FULL, 0x124C5790974B5C22ULL, 
            0xBE9FFE4B1DE440CDULL, 0x78C7A3AD044CCE18ULL, 0xC1FA69AE014A95F6ULL, 0xF4B9D950E64809CEULL, 
            0x27F2E3D133D630B0ULL, 0x5404AFB97672D0C6ULL, 0x4DE61B2002480B6FULL, 0x7DE01FFEBF7CCA31ULL, 
            0x23CF3B1409FC14A2ULL, 0x3586CF0415D0A1E9ULL, 0x40F31214642163B7ULL, 0xAEB2E8760FDDE018ULL, 
            0x203F377F5B85778DULL, 0x736C6E391201537EULL, 0x7272C260492FC708ULL, 0x14093DC1D3E542F1ULL
        },
        {
            0x0D72035A7B2B994AULL, 0xD3423DCE9DFEC812ULL, 0x211E1E9028D8952AULL, 0xCF4B6429D02A0008ULL, 
            0x94834CF12D977C7FULL, 0x5DAFB8221B96EF48ULL, 0x748AD2294AD92D6FULL, 0x760CCA5B046571FDULL, 
            0xCB711C9D2A2173F4ULL, 0x68A18F14E1B20E1EULL, 0xA94FC5E900BDBB04ULL, 0xBC868D6C6656152CULL, 
            0xFD3A1483F9DC260CULL, 0xB14B730A8A27668CULL, 0xDF5C2461250E4554ULL, 0x35A9A703F3778D18ULL, 
            0xCE2A146E362B5776ULL, 0x21E018D94DD4D352ULL, 0xAB8416B1E9EA49F7ULL, 0xCA5E65C38EE9DDE0ULL, 
            0xDE9DDF8B95CF99E1ULL, 0xD6FE47EF630A7115ULL, 0x8B8D5D3E9A1F19E0ULL, 0x8F6B45E1440B8AA4ULL, 
            0xF2D19E0100532501ULL, 0x01DB145565DD8AC6ULL, 0xC15861415A344EF9ULL, 0x156735120400384FULL, 
            0xB2D4F2FFE3EF3798ULL, 0x5FDDCBA06778413AULL, 0x1A6AC2C86635EAD3ULL, 0xB32CAC7617CB1038ULL
        },
        {
            0xAB6630AA03846ADDULL, 0x5158986C4FC8BADFULL, 0xCF990B9260E16AFDULL, 0x15DB938E78D0A45BULL, 
            0xCBC94A3F9F1E5CB2ULL, 0x5E907A81B9407811ULL, 0xD5453AA1BE18A558ULL, 0xF416D002CEB1356DULL, 
            0xD884A18907EDE209ULL, 0x03FE9A2316855920ULL, 0x024A7D2BC596E890ULL, 0xC44E61CFB84AB78EULL, 
            0x358C727E4D526C57ULL, 0x215C9368FC858275ULL, 0x6CBF0201B9BF801BULL, 0xAD6AB88C154C2E25ULL, 
            0xBE77304C79ED15FEULL, 0xF322FED276D892E8ULL, 0x40A85FF07EC87700ULL, 0xB2BDB0E8211E4A24ULL, 
            0xDCA555BADC86B52EULL, 0x3EBAAFC13595B862ULL, 0x2C3BC8A3E7A53E8BULL, 0xC6EECF8727BCA52EULL, 
            0x8A3898D2D8F2FA7EULL, 0x81463BBABA56934AULL, 0x21454F577EF2D34BULL, 0x892D7378A49B5A81ULL, 
            0x89E7EAFA823AEDD9ULL, 0x9C7D6342476641BDULL, 0xBD64699EAF2A2F32ULL, 0xA1FB2EDB70AE04C8ULL
        },
        {
            0x371FA2D5C7293A77ULL, 0x60CB5A78E87FBF02ULL, 0xEDF2D258D19F2077ULL, 0x47C4CCB87C01A945ULL, 
            0x58B5BCEBD17A711AULL, 0xA8C8E7DEC5DC2510ULL, 0x5592EC45DA9D438EULL, 0xD9BE07BB8266EC97ULL, 
            0xF7E130A21BC3093FULL, 0x72C3D789BE4A4F3CULL, 0xBACC0634B12EA6B8ULL, 0xF88DC44168BE0CBAULL, 
            0x9905EF502B3AA14FULL, 0xC47353301619CE39ULL, 0xC990813222F19F9EULL, 0x77D34D41E51262B8ULL, 
            0xC806D33CCC06A23BULL, 0xBCA7DAF520862627ULL, 0xC302D2F68BAD266EULL, 0xF344BEA139B7B228ULL, 
            0xAB1C9AC893F867FEULL, 0x0F7DB3F55ECA3CC3ULL, 0xC39F8751D40C6F96ULL, 0x437E2651F5BBA045ULL, 
            0xCBC2E701004F5192ULL, 0x2EB46C9DFF57F4CFULL, 0xABDF1DB697C44E3CULL, 0x6EDC66E0351349D5ULL, 
            0x0CD7ED8F362D8A28ULL, 0xE5A5E9B521E04DEAULL, 0xF0D697F28C6782C5ULL, 0x16C878942B1A9735ULL
        }
    },
    {
        {
            0x56D0157259274D6EULL, 0x8E80AF05D03DF716ULL, 0x9BDDDD83239E4299ULL, 0x496AC4F54861991AULL, 
            0x20783D9DA7FCDDFCULL, 0x779D6824C1D07BD3ULL, 0xBF2F55F5D7C353B9ULL, 0x15217DE3AD5CF8A1ULL, 
            0x6F9B3D95827EF5DBULL, 0xD0DD68359F565B9DULL, 0x32BFC593E047500CULL, 0x2091889515C18BDCULL, 
            0x91DE78881B290C13ULL, 0x79B80D8A2DA5258AULL, 0xB3E4690CF1BF239CULL, 0x78BB52F27488D1FCULL, 
            0xEFF976AC7D886E10ULL, 0xBC0EBF12EDBEAB8DULL, 0x4EB0F96F1B158983ULL, 0xB2AB72EC6B3130ECULL, 
            0xED93A9E7F002FE7BULL, 0xC5C965FBEEBB0919ULL, 0x44BD91E95CB57363ULL, 0x063FE7D3A469C8E7ULL, 
            0x0213DA56424DE9DAULL, 0x551380DCE1AEB208ULL, 0x9AD0EB1C9EF5C2B4ULL, 0x27FF5D789F38C824ULL, 
            0x0F24A7ADEC45FD9AULL, 0x0842175EFC637DBDULL, 0x7F1B4F46136B02A6ULL, 0x685F6C7CD81DE183ULL
        },
        {
            0x71186390273F2E83ULL, 0xBE609457A46F1D8DULL, 0x83D1A8F4668E9F25ULL, 0x5F84E0CB838C1B30ULL, 
            0xEB315525D6ED12AAULL, 0x7C8B58DC468AEAEFULL, 0x8A801FB1F53BA123ULL, 0xA58642B762B087EEULL, 
            0x4FC5005D9E3876CEULL, 0x41470EB95851E3D7ULL, 0x05FF22EF349C26BBULL, 0xCD6DC8DA32EE65E9ULL, 
            0x4AFEDF1617A7EB0EULL, 0xB2B247D34FA2B96CULL, 0xEDB97B64360D1878ULL, 0x1BD5D9F9DE329CF5ULL, 
            0x97E6D855360DC39EULL, 0x0702196BCF7434A4ULL, 0x5CDE996153E2F3D1ULL, 0xFFD9379E13A7DE0BULL, 
            0x33936F728C479689ULL, 0xC1646AE3C970CF6FULL, 0x6E5624ADAC19C4B4ULL, 0x18BE3FA1345A0F35ULL, 
            0x48D2F385CCBD5999ULL, 0x9CC24B37BAC30125ULL, 0x857C7ED0158F422DULL, 0x99D22543A1829F10ULL, 
            0xE37C2EA5986A6126ULL, 0xDE31C806CA727037ULL, 0xC437E0B4BAB69AE9ULL, 0xBB96FD274654122EULL
        },
        {
            0x64B3C1F804606FA3ULL, 0xB6E60D7C202CC6B2ULL, 0xEB0446D5A93235F3ULL, 0x5694EAA433C22719ULL, 
            0x91CAA5C64A8A17ECULL, 0x80720B5E3A1F9F12ULL, 0x674F7ED4138D3A47ULL, 0xAD07E04F4230B377ULL, 
            0x4F7E398296B74A56ULL, 0xD5083BF0E54E88F4ULL, 0x5E5B265126AA2628ULL, 0x39FF3EAEBFEC048DULL, 
            0x4780CA5F77221813ULL, 0x285A05C9C119BC76ULL, 0xA2446FA2053AF8E1ULL, 0x89D5464BD7828EA2ULL, 
            0x55B9AD937FCA1C95ULL, 0x0A2BF50CE7A55BE5ULL, 0x3EA1A944C77555C3ULL, 0x83C3D0058DB83147ULL, 
            0x1C9EA4FFA9FA9E2FULL, 0x1399800AE41B09C2ULL, 0x9DFC297D062E6C72ULL, 0x570D4100162EE687ULL, 
            0xED20F345DDCCA3F2ULL, 0x3D4DFCD1B2B1E5E0ULL, 0x4B5EB3B8161B8B12ULL, 0xF3AECE782203706DULL, 
            0x19EB7886C6A8ED4AULL, 0x68D5FA2B6177FF1BULL, 0xC86BB5D515E457EEULL, 0xD03BB8E828741BD7ULL
        },
        {
            0x344D1922A4FA614CULL, 0xCE994FD947CD77FAULL, 0xFAF742C1C63228B8ULL, 0x6BA9868FF5FEF635ULL, 
            0xFD31FD9E949976A2ULL, 0xB1A049F38849594AULL, 0xED013AEAF371A67EULL, 0x2CE4D75BC4D11729ULL, 
            0xC41C872BD1BB694EULL, 0xF048D0FB37319CC2ULL, 0x702A1352AD3ECDD8ULL, 0x9F217E52F0465544ULL, 
            0xF73042CC0F6DC152ULL, 0x16F3E830F8E27044ULL, 0x9F66D4772F195028ULL, 0xB8B0DE8EA15EA29FULL, 
            0x8F240E9B65A2EF94ULL, 0x20EC4C7D06F5EAF2ULL, 0xF4A5E1F7F070262AULL, 0x90AB15AE6452B416ULL, 
            0xC860D17633425283ULL, 0x9F57A494A2A98729ULL, 0x509425DB89B674BCULL, 0xF17C51BFF52118DDULL, 
            0xB405F46CA174D2EBULL, 0xAD39419910080511ULL, 0xDD94EA754E623C76ULL, 0x04E6377C4A2B1036ULL, 
            0x3B3F09201BD1E0EEULL, 0xE2DD454DEC5C9ABBULL, 0x4BC860A21AD357BFULL, 0xE8C30DC5ACC7C72FULL
        },
        {
            0x6DAF0C35AE3EE803ULL, 0x5C890E5C301A90A0ULL, 0xAFB71A5100C9AFE3ULL, 0x1ED1CCE497D7EA24ULL, 
            0x62FC737403F6DB72ULL, 0xB697EDF17A26C9EBULL, 0x1E99BA451186A8EEULL, 0xDA23B7708B5ABEBAULL, 
            0x81251B587DE539C1ULL, 0xC5E120270BB8D81DULL, 0xAE80BD2EBAA6B742ULL, 0x4A890F4160C684A7ULL, 
            0xB066DAC546D33096ULL, 0x7E4FBB6B4627224DULL, 0x3DBB61BBCD2D1B3AULL, 0x2FB646D50AC27E41ULL, 
            0x068D47F316CBB0C5ULL, 0xA562A6BD36F89E82ULL, 0xBE7F002F80807E0FULL, 0xB48DEAD7AE3C99EBULL, 
            0xA843595E84258528ULL, 0x079F32F7F36AFA6DULL, 0x533D5A92435E43C0ULL, 0xEE8856C39EEB28B7ULL, 
            0x3D476E9A2FE84976ULL, 0xF4E22B9866BB191AULL, 0x01ABEF9BFAB770ACULL, 0xE574C7D4E8745991ULL, 
            0xC5368BCE7C00C24BULL, 0x9E1F08E886E7F882ULL, 0xC6E2A5429D293184ULL, 0xEB184134AAE0245BULL
        },
        {
            0x185F4ED2666AFAFCULL, 0xF902FD86AB3187B8ULL, 0x1148E6EE39F565DBULL, 0x8925B44669FBB0B2ULL, 
            0xC0AAE95B090E6C88ULL, 0x795146DC48EE4A4CULL, 0x28E8831873813E5FULL, 0x16C9C9CACF1F066DULL, 
            0x9EC13D91EDAF5A88ULL, 0x94B35A77CD9166C6ULL, 0xDA13E97F6375351AULL, 0x97B24302B7EE4441ULL, 
            0x52F61021EF398DBDULL, 0x84D7B4BCA4499FF7ULL, 0xED6FC6AD8C55579EULL, 0x43DF09009CCFEE4FULL, 
            0xE2D8B78B26BE0757ULL, 0x3B61CF6531B24B1DULL, 0xACFB250DA63063DBULL, 0xAEC7D5FCE283F5DBULL, 
            0x8769529B497F3B1CULL, 0xB2007EB1C4853279ULL, 0xD2BB6C5A94F6AD57ULL, 0xC94398DF1E837372ULL, 
            0xA551F214E2510FDEULL, 0x65BC81A6AB26E006ULL, 0xBCBAB6F0C64897BDULL, 0x2E8ECEB03FF480C9ULL, 
            0xE2579607BDEC7A3BULL, 0x2D56B2A962AF15C4ULL, 0xDDDE81862D271047ULL, 0x43CD36AD61DD6695ULL
        }
    },
    {
        {
            0x476091D99C8457F7ULL, 0x65CB1BFD7CD712F8ULL, 0xFE676F7FED80C1A9ULL, 0x2E403A905CE12B34ULL, 
            0x8F01B700D19FC8DAULL, 0x8D73B2F831087538ULL, 0x9F20543F54807190ULL, 0x56843D06A6E5C21FULL, 
            0x14799D7EF55A311BULL, 0x6997132C013EB4E1ULL, 0x5ED1A2FE26EC3EB5ULL, 0xDBACFA27C5BF6704ULL, 
            0x6FE95BF151C646B8ULL, 0xADE65C57C35DE4B3ULL, 0x89134CFA3401D6E7ULL, 0x0191E757A644A8E0ULL, 
            0x510EE21BDDE0DDF2ULL, 0x45D3EE51A25E21C0ULL, 0xAF8F62B80C051581ULL, 0xB17E7DBA74A2BC06ULL, 
            0xBBC57CD999391A5CULL, 0xF5187D14ECE9CD0BULL, 0x07C7C2ECC5BDADF3ULL, 0xDCC8DACED6B56EB0ULL, 
            0xEE6DF6BD6448B420ULL, 0xAA4BBAA10B212ADBULL, 0xA25E809F59D02E10ULL, 0x3079358885FB1838ULL, 
            0xE61E310036703D1DULL, 0xEBE8B575D9B95310ULL, 0x47E2A104611C9FD0ULL, 0xE4839ACB1B244FB5ULL
        },
        {
            0x0EB8113147ED7AE1ULL, 0x8F94CAB1164EBC5AULL, 0x096D666019DD584DULL, 0xF14DBC8650FDAFBAULL, 
            0xE0F1334B970FE305ULL, 0x6F6149F5D1265DC9ULL, 0x3F6E62E91D5A4CB1ULL, 0x91BD0D42A5B40451ULL, 
            0x8FC0816939EE57F2ULL, 0xCC4A68C5E60A6360ULL, 0x1327FF3907F3A1B5ULL, 0xFCD3465386DBB496ULL, 
            0x9E3D5B3B7CB5429DULL, 0x0357AFBA8EF97530ULL, 0xF74A792F36160F9CULL, 0xA64BA33EA9A355E4ULL, 
            0xE00DE6AD5830D12AULL, 0x98CDA88553AD7E13ULL, 0x2071D4E682428747ULL, 0x761105D18D29B542ULL, 
            0x179541948AD774A4ULL, 0xCC93FEB42E18D804ULL, 0xDC67D90B07331B16ULL, 0x9D5AB37F0338F2B6ULL, 
            0x3E714CC432CDA792ULL, 0xBCB3C39B72044B37ULL, 0xADE428AB8FA76967ULL, 0xA6B7092EA324E884ULL, 
            0x8C7DFF891C7635F2ULL, 0x66B6116376D2CD8FULL, 0x3A861D22741C89B1ULL, 0x2BC906FEABA9B6DBULL
        },
        {
            0x8967AF4CAE4B9352ULL, 0x8E9B67A506BA8EF4ULL, 0xD29963AAA8C2250CULL, 0xBDB99783D5CE1240ULL, 
            0xC6C09D4BD0E73ED5ULL, 0x8DFF530E52BA6946ULL, 0x311F3521CF632F79ULL, 0x5D58F0244D197FDEULL, 
            0x40C1E7371A58982BULL, 0xEFB1A9ACFA4BB135ULL, 0x97BDF27483BB4497ULL, 0x99675E1E8E116513ULL, 
            0x0F32B52FCF5A0C48ULL, 0x85E5BF7805CC1F75ULL, 0x7369963059C3555DULL, 0x255F70890B714FA0ULL, 
            0x661822B531BCD24EULL, 0x175348A11E8A368CULL, 0x6088F94270BDB9E3ULL, 0x0595F29ED02A746FULL, 
            0x7F16FD6747E0B0CFULL, 0xC6475963B2AC45D0ULL, 0x00D162B4ECE9903BULL, 0x42530C9034E0F942ULL, 
            0x707CDCE4044A8D61ULL, 0x019D50D0E43DC2D6ULL, 0x22EC065C0BF961D9ULL, 0x96A736F58CD85BF3ULL, 
            0x8B5AC84D73ABF0BEULL, 0x75AC56580B83F839ULL, 0xA4394B1F9D26363FULL, 0xC9140E67B74802E4ULL
        },
        {
            0x7A0CCD6B96E2B4C1ULL, 0x8BF5C9E28529EE59ULL, 0x9B9E61C4E9B31E51ULL, 0x906B5B2566D19607ULL, 
            0x072DD09B6F0C9F17ULL, 0x4C9CF7287CE9E88EULL, 0xB1A34F32CABF70A4ULL, 0xBBD5D30FA24DB6A4ULL, 
            0x91F26E81D5DF8CD5ULL, 0xE4BDF3EB36BC5092ULL, 0x816CD73A5594136FULL, 0x326C05C735CA91B7ULL, 
            0xCFD8FBEFC06CE9F5ULL, 0x23998D9F1B5A100CULL, 0x986DDF216C0C6FD9ULL, 0x4553B26B1CD5CF92ULL, 
            0xF3A11400E77CD722ULL, 0xB8DEB54A8FDCC8D9ULL, 0x38ADF1837E013ED9ULL, 0x68598326BE961ADEULL, 
            0xAE853559F3B4B430ULL, 0x5847CB560FD5E270ULL, 0x23F79D0B5999B6BFULL, 0xAAD27261313D3258ULL, 
            0x0121387395F021C8ULL, 0xD93CE2A061D649CEULL, 0xCE4501DDDEFE0CF1ULL, 0xDB7D347633A47AB1ULL, 
            0x97972BBFD2009F90ULL, 0x3A0E93B693C5F927ULL, 0xBC62C99804192CBCULL, 0x29E066B672571B6AULL
        },
        {
            0x88637D5800EF0B6BULL, 0x15739EF42AFC492EULL, 0x71DD052258B13925ULL, 0x0017886B8F8565DBULL, 
            0xCF788D043EA84157ULL, 0x1838EEF24CF2D441ULL, 0xF51F1435994C647CULL, 0x0EB910F38F5DE9EFULL, 
            0xA7309C202803E1E5ULL, 0xEAFA74C95EB6ACC8ULL, 0xD78E8B309DDB6B90ULL, 0x3210EBEDCE501D07ULL, 
            0xA8D8506113B74CB8ULL, 0x5132F77E5DDAC006ULL, 0x6FF86BA0FF15B565ULL, 0x04A3640CB2CEF56AULL, 
            0xF98D7F89961499E7ULL, 0x6465D8FD05500F80ULL, 0x7DFA23535BAA8F99ULL, 0x6522670F0E6D40A7ULL, 
            0x6EAE2D89BE29936CULL, 0xD174E1CD16506275ULL, 0xB803BC16C4BA1026ULL, 0x5E860798DC2A2E12ULL, 
            0x18C44DDF50B67584ULL, 0x916B7E96CBCF546BULL, 0x1D97673F70F9FFE1ULL, 0xC95F2B1531CACA4CULL, 
            0xD0490261B014C40FULL, 0x3710CA443DDAA26BULL, 0x12CE4014D9247681ULL, 0x469F801672728155ULL
        },
        {
            0xFA50E6F508DF42D4ULL, 0xB5E6D6AA01BE1FE2ULL, 0x5216F6F39A44D48AULL, 0x1DC3A07C51624E5AULL, 
            0xC34BA0BD9184EB16ULL, 0x02FF5F71DACA89AEULL, 0xC13E636F20AB6C00ULL, 0x79BA1261E37B5EA4ULL, 
            0x58B1A2B6E533F94CULL, 0x12F36B85CBF9DEF1ULL, 0xB4C2DED93CE8DF91ULL, 0x1CCDBF3D8090CBBCULL, 
            0x226BDC4C1BB6FD4DULL, 0x18E649DB8A3AAE3BULL, 0x8023D8CB4C8785D8ULL, 0xCB43F60F00424AD8ULL, 
            0xCDAF296B885A07E2ULL, 0x102236A787554A2BULL, 0x903B691494D9693EULL, 0x7BA88419B98D6AE0ULL, 
            0x379F5809F09BB237ULL, 0x2BC70CF84AB2D86AULL, 0xD3BBE41A28AE7594ULL, 0x9E1FBB447278A83BULL, 
            0xEA7182A125360D2AULL, 0x2434087AD182E90CULL, 0x04CC125BD8559343ULL, 0x53E568210F3242A0ULL, 
            0x7834D8A7AE20DFF5ULL, 0x0A8FEF46FD65B6B2ULL, 0xC6BC070BDBD02077ULL, 0x26D766E9C1AA9DD2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Capella::kSeedConstants = {
    0xDA90BE781AC35BA9ULL,
    0xAFD79F1ABCD5FECAULL,
    0x93062E4AEE8FA35AULL,
    0xDA90BE781AC35BA9ULL,
    0xAFD79F1ABCD5FECAULL,
    0x93062E4AEE8FA35AULL,
    0x81F2835314C3103BULL,
    0xBA3326E29F3C6D7FULL,
    0xD8,
    0xBD,
    0x59,
    0x56,
    0x79,
    0x05,
    0x35,
    0x50
};

const TwistDomainSaltSet TwistExpander_Capella::kTwistSalts = {
    {
        {
            0x38CD78A405C4B93CULL, 0x87044975CA322F98ULL, 0xC2479EFD97D4AC39ULL, 0x9C34B1CC92626F89ULL, 
            0x07FBAB6C01D3A64AULL, 0xD6AE210022129710ULL, 0x19710F9C1F0FF483ULL, 0xA62071C343C90140ULL, 
            0xEB6177DA64476C24ULL, 0x55394E4CAF86874CULL, 0x886D45EB4543A974ULL, 0xB6A1F5F08F26AB9AULL, 
            0xE828AA9D0E00B87BULL, 0xFD66BFBE60C17506ULL, 0x11E8AFF7E6A7E278ULL, 0x6307E238F4E8D8CDULL, 
            0x4B8A0C1CA681448EULL, 0xF3AC9B042F070979ULL, 0xACB2548DA95F1938ULL, 0x3F1001EF22713A88ULL, 
            0x4AEBAAB7500C507BULL, 0xF19A1A168740E49DULL, 0xC23C60AFB5FB2505ULL, 0x57D0BC0B80F59C69ULL, 
            0xFD91B9ECD6446650ULL, 0x8D92EEB16B0427B0ULL, 0x89AA24FC264D1DE7ULL, 0x9F5E2B84381BD3BEULL, 
            0x9A12313409C8D385ULL, 0xB064F42AE56E4B5FULL, 0xF221B43163E08CA9ULL, 0xDC5B8656335B028EULL
        },
        {
            0x7D5C61F21D3AECE7ULL, 0x754A64C79F6B3C01ULL, 0xE4E5BD7C5FB0E402ULL, 0x30D6DFDCC7115F08ULL, 
            0x4022286AA0454380ULL, 0x8808186525FC3ABEULL, 0x444B086B4CFE3E8AULL, 0x6DBA185C3EEFBBBCULL, 
            0xAD04318947CC4CACULL, 0xC68A78C3C8E2D393ULL, 0x4519DE5CD62B7102ULL, 0xA307CA7CB72C6139ULL, 
            0x03800068B4F98FEAULL, 0x78A6209E59169F28ULL, 0xFC811EE1D7D6B345ULL, 0xE71CD50F2CB35058ULL, 
            0xEBE1DFB5B9901A39ULL, 0x24AB5BB8AEEB65B2ULL, 0xD54088667B064795ULL, 0xAE5039FB12668E03ULL, 
            0xBC4BD18B7EEAB591ULL, 0xC4DB828351A9E7F0ULL, 0xB1FF97269DD46EF9ULL, 0x661E526C774026BFULL, 
            0x28209A42CDAB3AE0ULL, 0x76A1E77FB35B15E9ULL, 0xA4C0752C1C98F562ULL, 0xEE0168684AAFE2FAULL, 
            0xBCD39AA4F2A5B603ULL, 0xA679A2A60A35E7AFULL, 0xDDFED0EB8D6898F8ULL, 0xC98207EC5E108545ULL
        },
        {
            0x7954D0B38E337386ULL, 0xA8B43E848EE85D62ULL, 0x046FD9B477446ACBULL, 0x9D922B602F1192C6ULL, 
            0x58D54452EB797B55ULL, 0x3A4A1789F15DBDA2ULL, 0xA94C959915D06DC7ULL, 0xFEBE4721744E6C07ULL, 
            0x8DBE09DC2FB30BC5ULL, 0x9B04BAE408997EFFULL, 0x87575252C77B9FDDULL, 0x807777F2CBA00E1EULL, 
            0xC20A55DA1B391DF3ULL, 0x4E21952596C525D0ULL, 0xEFFFFDD7B0B126AAULL, 0x24D33EE507897C75ULL, 
            0x0296625E6C5CA72BULL, 0x902A2C6272E44E62ULL, 0x433F675001D0FEB0ULL, 0xADEC4C5EBA0496B3ULL, 
            0x5F8F9DD81E3235FAULL, 0xF76DC4F503895481ULL, 0x3B366BB5A7814BCDULL, 0xB9A58D21D7F19C71ULL, 
            0x22C799412480DB85ULL, 0x103D79791426CEA3ULL, 0x53D2E6A0D04FF9C5ULL, 0xB8C3B3D10FC7E347ULL, 
            0xC45350646D7AC4D0ULL, 0x7F7D1BC5E7B3690FULL, 0xA7224DDEAE0D838FULL, 0xDECFFCFCF8D4C367ULL
        },
        {
            0x09282D931B2E7962ULL, 0xED3FE7538B047598ULL, 0xA9D3D96D9A1B131BULL, 0x4BBFAA2F969AD566ULL, 
            0xD400A7770219DB02ULL, 0xF602FA0683B5C60CULL, 0x008383014F3F4EDCULL, 0x48EB19A4E369DA10ULL, 
            0x2D68088E7BE76BD7ULL, 0x1D7421E7DA68F3EFULL, 0xCBE3448EAC9A2FB1ULL, 0x901B10AD752517C2ULL, 
            0x5053A5D64BE9161BULL, 0x74288A134B39B6B7ULL, 0x80E2CB6819C8B334ULL, 0x934821A07FDFD0BBULL, 
            0xBFB7134244C16E75ULL, 0xE07C0E1AE6CAE414ULL, 0x9F21AC73C38C37CEULL, 0x722EA1A55D640977ULL, 
            0xDB42F0A943AE33D0ULL, 0x36A79CE50AA72BBBULL, 0xE2A47D48776E1760ULL, 0x0DBB3931CB2CB4E6ULL, 
            0xC765775BF37A4EADULL, 0x8A27FCC1C5D57CDFULL, 0xABAD102F4B7F7AD3ULL, 0x79B31F10888C885CULL, 
            0x54A1E4EB2EBFBF87ULL, 0x57A3A81A98CF142BULL, 0x9722FF7947631A47ULL, 0xE985EED3C2340257ULL
        },
        {
            0x209C5002E0E098DEULL, 0x7D4D98C047C4983CULL, 0xAAAAE25D085AED21ULL, 0x107D125FE0AA472DULL, 
            0x3E3D8BF655BD9906ULL, 0x5B22C76E8513F58EULL, 0x148531A86DC9229CULL, 0x3257D2DEA3A9F9D7ULL, 
            0xCD53990679DD6934ULL, 0xF0566040FA4AFE2CULL, 0xF2B79EA454DCC1AFULL, 0x1113E2748FD50A33ULL, 
            0x1E8212BF6B9F5E9EULL, 0xDA9C667A155E0767ULL, 0xD3A21FCE722F9BF9ULL, 0xA287784E55217D06ULL, 
            0xD464A63998E1C938ULL, 0x6D3BE21FC5D334FDULL, 0x95672A6FB2377D26ULL, 0x3A77B3E13C33F5A4ULL, 
            0x7FF9454CBCE76CA2ULL, 0x42030707C14BBD04ULL, 0x2E01B7BD9CFD633BULL, 0xA2233B44214F4B15ULL, 
            0x6FDB81E9B6710BADULL, 0x16BE555D52FB5422ULL, 0x67DFB8E952327805ULL, 0x380E5F58001ACF48ULL, 
            0xF86D80E18D15EB29ULL, 0xFFD61FBA311A778CULL, 0x837C8EFF0C1442DFULL, 0x2F2368E72D3E81BAULL
        },
        {
            0x3C8E65FA074DE2CCULL, 0xCC6176A7D707DE77ULL, 0x44F624309ACF6467ULL, 0x790308831A995CCBULL, 
            0xD0AF2CCD80F9C8A0ULL, 0xBBFB58DB8CE7062EULL, 0x013F42B2A522DC8FULL, 0x8AA8DF267296234BULL, 
            0x28A24F40530A4A15ULL, 0xA2271358490D80C1ULL, 0xA452FFF3046602D0ULL, 0x17C8C3E6A7D13CABULL, 
            0x5CC769D7445A5115ULL, 0x49414B7BC95B8345ULL, 0x1296E65AB1E0F6C3ULL, 0x072940E496860D35ULL, 
            0x3A2BDC9701D611E4ULL, 0xE0491105B44F90D7ULL, 0x277FF7ECB85ACAFBULL, 0x79AE726618F9A618ULL, 
            0xBBE4DE1E46D61115ULL, 0x5CC18979FCB9B127ULL, 0x02F79E3FE0D1651FULL, 0x00B64537E2F90F83ULL, 
            0x598B96422AE578A5ULL, 0x53401624A1FFCD88ULL, 0xC1038165838B0850ULL, 0xA8701217EE308D54ULL, 
            0x9FDD2C66F9D7F2C7ULL, 0x233FBC0AAA347A61ULL, 0x626540BB02D631E5ULL, 0x9442673C983D775DULL
        }
    },
    {
        {
            0x118B366FA79DBFAFULL, 0xFC834D73294F95F7ULL, 0x6E82F4760BD0C8E7ULL, 0x0F0534F767FD74E3ULL, 
            0x598BB24254C361EEULL, 0xE6257C1DED1BE2CBULL, 0x0777C22CED0771F3ULL, 0xE5E5B51CBF2A2BC1ULL, 
            0x7E8A9FF31B5EEC96ULL, 0x25238E45551ECE1DULL, 0x9FE1C1923515A31BULL, 0xFF9B385ED114C1E9ULL, 
            0xFAA4F244CC15E608ULL, 0x85AD688F6B7BC560ULL, 0x589B723139E7CF93ULL, 0x00735220D1D457F8ULL, 
            0xEAF00BA9264AA416ULL, 0xDD80854688013497ULL, 0x48C9AE3581B3336AULL, 0xCA1BFC03F07BAE5CULL, 
            0x0FA21F9FE3E0A550ULL, 0xB024DF144EC9FD9CULL, 0x0FB7AACA7BA2F1B7ULL, 0xE7B568E7BD4CDD4AULL, 
            0xED331A0D95D7240FULL, 0x2B331D6D7B00DE36ULL, 0xFB050CD26057713DULL, 0x978211CB5FB6FE03ULL, 
            0x5385DC4BC14FF7D4ULL, 0x25B9406C52E0ECF9ULL, 0xC2C28985EC4A47D3ULL, 0x806B3EA8A7FA9EBFULL
        },
        {
            0xD9876DC985579950ULL, 0xD7C334BBA5811696ULL, 0x5AD06B0A5603FF48ULL, 0x30555CBA603CC953ULL, 
            0x791ED8A2757E7EC6ULL, 0xDDFDF0B138890415ULL, 0xF97829D0CF43D9D9ULL, 0xF5F6252A73A630D8ULL, 
            0x25F22046E3D34EFBULL, 0xD3473DB170C33477ULL, 0xF996CE861DF865A0ULL, 0x3BCA690D91B5CFE5ULL, 
            0x50A529B05617167CULL, 0x0AFA736A5447F083ULL, 0x619ED4907B87E528ULL, 0x8403414096AB8184ULL, 
            0xCE70DC221B4B7213ULL, 0x67DF68D3B02F2F48ULL, 0x05AEA11B55C1F3CBULL, 0xFFBE3B0AE3B49D97ULL, 
            0x959AAFF00F47A448ULL, 0x53AEBA31F97C5213ULL, 0x009F2DB794218C4AULL, 0xFDBDDEA0A850087DULL, 
            0xBB71FC65262889ACULL, 0x59652186308B5BF2ULL, 0xA7D9AF1B7F5075D4ULL, 0x45BE3DEF853C28E0ULL, 
            0x3502296BA52DDCC0ULL, 0x438A77F9E16728FAULL, 0xC833ADBA5D297A11ULL, 0xA7741165177DA5A9ULL
        },
        {
            0xF4C4E61C41A4BB08ULL, 0x3550F3576EB0D3B5ULL, 0xD8B6E5CAB2FC3419ULL, 0x341FD7B9833DC466ULL, 
            0x38027E37E4F99C06ULL, 0xA2825FFC09EF4701ULL, 0x3E201AF8208D7C54ULL, 0x53E045AE3BE3188FULL, 
            0x7132833B37143388ULL, 0x0BC36A67FAB7F4A2ULL, 0x1B6F4EAF0FD1248DULL, 0x69E42DE6A2C0D56FULL, 
            0x9C8BDBEB61DDE8FAULL, 0xEB51989930AEA4B1ULL, 0x16AC2982CACEC965ULL, 0x1FAA9050A172DA52ULL, 
            0x812454A4A6D20842ULL, 0x345BD7A6F8E68967ULL, 0x1816771419790F57ULL, 0x40307BA6BB7C977EULL, 
            0xF01747703A07D7FCULL, 0x3D296D220C3DC36BULL, 0x8E2103776A0FF394ULL, 0xC054D0D181519EC6ULL, 
            0xB3BB0C4A3B822F0AULL, 0xE9D4A19F5A24BAC9ULL, 0x822DD93FD5EE965CULL, 0x9703BAC92D4A9A66ULL, 
            0xAB65B2F016B6B2E3ULL, 0x8D141AD55451EFF5ULL, 0x0181F5FA491CF960ULL, 0xD95BE2F54E5116D1ULL
        },
        {
            0x51C59BC1CA5A502FULL, 0x1E57692B8C10AEBAULL, 0xE403A7510A42B6C7ULL, 0x0BB2DDC22040F6FEULL, 
            0xA1E642CDA52252E2ULL, 0x240A0FFC9B21D909ULL, 0xB0050B39E49DEBA1ULL, 0x77B2FDC0DBA3EC92ULL, 
            0xE2245876AF2C54F9ULL, 0x512E3395CA685BD0ULL, 0x0C8F8E9335131722ULL, 0xDB309FCFC4560337ULL, 
            0xC26228A2C14A68A1ULL, 0xA8AB4B8F0A2D9761ULL, 0x88B8E9FB58F9B0CCULL, 0x76D6A4C85EC19CA2ULL, 
            0x25C9A429B5141AB3ULL, 0xC604666AA64142BDULL, 0xA854784EF2FF35F8ULL, 0x345F06F4E0E20973ULL, 
            0x44412CC6AE46BCFEULL, 0xBA62B40AE852573EULL, 0x4871DC101F98BB42ULL, 0x3E913AD9B43AE67AULL, 
            0xB54D9F34F67B931AULL, 0x31E8761F74B8E82DULL, 0x269A8A6EDD7C4384ULL, 0x5D95666E3137B6D1ULL, 
            0xE6DF0840EC18DEC8ULL, 0x8417FBADCCBF9F84ULL, 0x8C711CDE1030207FULL, 0x6EE35B1A46447F50ULL
        },
        {
            0xE5F022CA299C34F6ULL, 0x403AF442718930C3ULL, 0x52E48250C3AE7292ULL, 0x494B41F0B673E6CAULL, 
            0x51AE31D7F66C6C7EULL, 0x8A0422A7531F7253ULL, 0x6E3A9A250FE8023AULL, 0x5588B2857205BEBBULL, 
            0xBDF498D541F4EDF5ULL, 0x85778A57CB0099FDULL, 0x6E75D498FD6A66DBULL, 0x8D5CFAF329930D59ULL, 
            0x29EBCD88380EE1C4ULL, 0x50CA797768D94A9DULL, 0xA185D0A91EC2C9D6ULL, 0x3B8243705A2D749EULL, 
            0xDD4AEC3C4A830F94ULL, 0xBC2A7135EB6320CBULL, 0xD20B923444BB7AE9ULL, 0xDE6E905557A9491BULL, 
            0xB47297B6411E00D4ULL, 0x7E2822D958AB010AULL, 0x7D77423551346A10ULL, 0xA7A2410F920C2C79ULL, 
            0x768A21D968477968ULL, 0x10E62065EC5C93ACULL, 0xEB5FDDF15DE877D3ULL, 0xB849F971CA01318CULL, 
            0x080C775B6930C35BULL, 0xB368F809CA2E8542ULL, 0xB48432E93A3861A5ULL, 0xE901DD3C2E3B17C5ULL
        },
        {
            0xF2EE7C86DBE3EE6EULL, 0x152C2514A2B11BFAULL, 0x7B7C4896D8E6AC12ULL, 0xFC105EDD9E4D3BDDULL, 
            0xEA6BFA15899BE4BAULL, 0x72DF4997E9CA00FFULL, 0x7F897C8FA9CE4101ULL, 0x4E7AA1B538254DEEULL, 
            0x568E12BBAF9C272FULL, 0x3A02BCAF41ACDBCEULL, 0x90A751EF8AA0C58AULL, 0xDD3BBCD338B77C96ULL, 
            0xDE970438B2FEE2CFULL, 0xA2718D4618823A93ULL, 0x007DA99CB29CBE86ULL, 0x05126323479DDABCULL, 
            0x187681E73248C211ULL, 0x1586E6354AB8B2B9ULL, 0xFF89BDDF6A756B05ULL, 0x4014EF44CACE4279ULL, 
            0x0A6A042AC7545D52ULL, 0x8C26C00EDD599638ULL, 0x17FF1B71DB3E2D96ULL, 0x061F4B33F5503D92ULL, 
            0x49983CD6BF68185AULL, 0x5161B0F573255B8DULL, 0x52FA88191E36083EULL, 0xAFE8099CC64C7FCCULL, 
            0x7131A4C78677F759ULL, 0x9AF85DF0FD382548ULL, 0x994D910683A27E9EULL, 0x30081D5D40C0D37DULL
        }
    },
    {
        {
            0x1135DC5D79B067D6ULL, 0x611D3F019E2B0A90ULL, 0xC9E061D75C8E4A69ULL, 0xBBC61CD696E7BBD8ULL, 
            0x07FB6D98B87BDFE2ULL, 0xBDF79232D5E1C26EULL, 0xF097D91421B20BD6ULL, 0x86FF358646547A57ULL, 
            0x5C682EC94F9975F3ULL, 0x9E3904B197142D97ULL, 0x2A3296F7082E7EB1ULL, 0x83BC1DB65CE37E19ULL, 
            0x243DE80294686BA7ULL, 0x46DF8C88101371FEULL, 0x98EF95D0E6498971ULL, 0xB8229EC3C3DD452AULL, 
            0xA17AC5C11E825CFCULL, 0x41755410107DD175ULL, 0xA3ADD791A21F878BULL, 0xF50F4BEFD544A4E7ULL, 
            0xAAA79EC72A0010DAULL, 0xC98F3484AD5FDCC0ULL, 0x3297B479542BCB62ULL, 0x0419056FDC1A9B0AULL, 
            0xE7E6D94B9BC5E943ULL, 0xA9F33C418ABF6BF2ULL, 0xC8244FC7E4DB7D9BULL, 0x377F5F89F4902C5CULL, 
            0x6A44373555EC49FBULL, 0x2AA7A56935718BECULL, 0x7DE0C94A8A953D36ULL, 0x4FC6026C1FF7AC88ULL
        },
        {
            0x9DB907C0FA3A15A0ULL, 0x2BFCD2D57B309ACDULL, 0x8E94F69574228CBBULL, 0x7933059E2245BF10ULL, 
            0x64AA9BC12E5E70D2ULL, 0x7F05EC509C6DDAEBULL, 0xEE301142D9315CA0ULL, 0x8BF455EBF85EA103ULL, 
            0x917C9E0D3298C165ULL, 0xE00FC27582F1AFF0ULL, 0x402D5899B8A54278ULL, 0xB5CE74250082C7CFULL, 
            0x01BFC9F9417531F9ULL, 0xE5E90D5A2D5E5430ULL, 0x56976DE60D656A34ULL, 0x768E8E9CFE77EE49ULL, 
            0xBC2A5770F6A300A3ULL, 0x5AB753F115029343ULL, 0x6BBFCB00CDC298F0ULL, 0xDC1BF4315CAD03AFULL, 
            0xD9C3AA4A228C9183ULL, 0xBDB1DBA3243D1F01ULL, 0x80D601F895843A0CULL, 0x81E5147BA6FA3250ULL, 
            0x7AADD35F43EC0DFAULL, 0xC46EB26FE2639672ULL, 0xCFFD90124E3D9420ULL, 0x0BEF0742841BF7F3ULL, 
            0x03445FCBBE5E057EULL, 0x7172EFFF8D03A22BULL, 0xA3895FC1C50A6292ULL, 0xFD59D200D93161BBULL
        },
        {
            0x6FD5A9B23709288EULL, 0xC4011494F358305FULL, 0x7C91491855B78AADULL, 0x5AFB9DBE4A26A964ULL, 
            0x1B84EF43D763A4ABULL, 0x52C93DC9506B9A8DULL, 0xA04C6A767A8E8BBCULL, 0x4FD8404A112CC54FULL, 
            0x948A058DCF7AB03BULL, 0xC3D1CBB6A594BA32ULL, 0x169C9DBB8F90988AULL, 0xB9C69B25D94489F7ULL, 
            0xEC0487106AC0C955ULL, 0x7D7A83222F4B6966ULL, 0x70A716F167D2D8D0ULL, 0xECD7D5145A54765AULL, 
            0x0871D4EB922533F8ULL, 0x795B316D769F6B20ULL, 0xECB7C1C4F6D2C5ABULL, 0x5BB785B6184FDBF4ULL, 
            0xFDA48201998AB269ULL, 0x92905514A0FF4AE8ULL, 0x7E786EB6ECCB19F2ULL, 0x6068CB27C96D2F20ULL, 
            0xB52FDA88C2F8ED12ULL, 0x7AE3966D39C4F203ULL, 0x1A7E414D18939615ULL, 0x03D16824954805BCULL, 
            0xE7E58406F397B599ULL, 0xA9E531F176FBFB0FULL, 0x4EB88504ED6BFB6CULL, 0x693909039FA88431ULL
        },
        {
            0xB7D827006088C2A6ULL, 0xC2792B4028A901E7ULL, 0xE0438C97D61DEB3FULL, 0x13E3943448D7D2DCULL, 
            0x682AF9AC50378EA4ULL, 0x60892E50A1C0094CULL, 0x1E05514CFA7C01B6ULL, 0x0F625321D6135598ULL, 
            0x9BCB1A1C18180FE8ULL, 0xC5BD583E42D043C3ULL, 0xBA87A4BE6D0616DBULL, 0xCFDA56EA8F5295CCULL, 
            0xCB1016DAC85BA5BBULL, 0x42968428DE19E651ULL, 0x0BCE6E0D8CD9ED7CULL, 0x95423242611D5C10ULL, 
            0xA6AD3D1737339FF6ULL, 0x93DF7F44AD598302ULL, 0xB8F8DE725FAA322DULL, 0x43B6CE63C962570CULL, 
            0x8760EBA95CB74250ULL, 0x27B59955FA93910AULL, 0xF057F5A054D93200ULL, 0xCE0DCF6687ADB284ULL, 
            0x49350D39D95F2C67ULL, 0xEE49A8BDECD6F30BULL, 0xB804A6627C1C29A6ULL, 0x10ABC3408E3BEEA2ULL, 
            0xD530C06720F2A927ULL, 0x607EF35835C27A33ULL, 0x9FEBF63756F4455EULL, 0xA172A8CFD9CC453FULL
        },
        {
            0x9CC4AA8DC5A5F61CULL, 0x9AD0C623B5F38E19ULL, 0x379BB60680DAC312ULL, 0xA19C5E2B3B42C3FCULL, 
            0x7CD312CB4D93DF8AULL, 0xCC86792D0F3CD256ULL, 0xC220ADD988067206ULL, 0x77DDE99E02DEE25FULL, 
            0xC091EE607D6766B9ULL, 0x7F6AF8ECDC573A07ULL, 0x7B8D50829823748EULL, 0x905503660557AED9ULL, 
            0x169E7FC2AFDF94E4ULL, 0xF5D8B1F809158CDCULL, 0xA6C60AF61FF86246ULL, 0xE03860FA26B086B0ULL, 
            0x6C150758C4EB14E3ULL, 0x28EF1B1F9753F531ULL, 0x8999AD905C1F7733ULL, 0x410265E384616B5FULL, 
            0x69797BD179CA2910ULL, 0x6643128A7F2280C7ULL, 0xEC511DED5230B6F2ULL, 0x6C8070F941ECB865ULL, 
            0xB2780539D7B6CDB4ULL, 0x1E0E752C34194A32ULL, 0xAC5E76C5EB501157ULL, 0xC82F9E6C259B881AULL, 
            0x5ABE865063C0669CULL, 0x4E695D65BA1CA3D8ULL, 0x01F43ED4524BEE2DULL, 0x3FE94B423DEA733FULL
        },
        {
            0xB4944D5BD3D521D2ULL, 0xA3E8032FAE8E399CULL, 0x4F794C5C09FB7C65ULL, 0x8D8F753DE99C430BULL, 
            0x6309EAF4EAD5B0DEULL, 0x78A82744116DBE2AULL, 0x5F53949A4A6BC125ULL, 0xACBEBD0CAEC6D861ULL, 
            0xA61922EB99AAA370ULL, 0x4CDD423591572D08ULL, 0x8C5795CD951420B7ULL, 0x00DC1D923252B8ADULL, 
            0xF82B430FF1DD9960ULL, 0x9EBB8B18BC1B4914ULL, 0x9AE7BA2A915BFBF8ULL, 0xB50806045A3576FEULL, 
            0xCDB703CD5D9EBFCBULL, 0xBE0AB3E451A01B8DULL, 0x5D20FF563A762A49ULL, 0x3859854766841831ULL, 
            0xCAFA70AE4327914FULL, 0x0A27611DCE259B73ULL, 0x47FEF27755870E25ULL, 0xE18036D44AA27BFAULL, 
            0x970EB2636239BA05ULL, 0xF486B44500397A7AULL, 0x9034F5A9B92045F0ULL, 0xFB09AC277D77A569ULL, 
            0x02C5459F5A673EDDULL, 0xCE0BA53AA99A0C2EULL, 0x5A6BF9FD41C55A76ULL, 0x61008FDABF976D41ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Capella::kTwistConstants = {
    0x968144FA6C8EB5D1ULL,
    0x16AB864B50B94CA3ULL,
    0xCB5EA6D9BCCF23CAULL,
    0x968144FA6C8EB5D1ULL,
    0x16AB864B50B94CA3ULL,
    0xCB5EA6D9BCCF23CAULL,
    0xEF7753964BA1EE2FULL,
    0x621EBF4C163D2E9EULL,
    0xE5,
    0x18,
    0x0D,
    0x44,
    0xC5,
    0x92,
    0x43,
    0x32
};

