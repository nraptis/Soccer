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
               std::uint8_t *pSnowLaneC,
               MUTABLE_PARAMS) {
    TwistExpander::KDF_A(pWorkSpace, pNonce, pConstants, pDomainSaltSet,
                        pSnowLaneA, pSnowLaneB, pSnowLaneC,
                        pPrevious, pIngress, pCarry,
                        pWandererA, pWandererB, pWandererC, pWandererD,
                        pWandererE, pWandererF, pWandererG, pWandererH,
                        pWandererI, pWandererJ, pWandererK);
    if ((pWorkSpace == nullptr) || (pConstants == nullptr) ||
        (pDomainSaltSet == nullptr) ||
        (pSnowLaneA == nullptr) || (pSnowLaneB == nullptr) ||
        (pSnowLaneC == nullptr) || (pPrevious == nullptr) ||
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
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
               std::uint8_t *pSnowLaneC,
               MUTABLE_PARAMS) {
    TwistExpander::KDF_B(pWorkSpace, pNonce, pConstants, pDomainSaltSet,
                        pSnowLaneA, pSnowLaneB, pSnowLaneC,
                        pPrevious, pIngress, pCarry,
                        pWandererA, pWandererB, pWandererC, pWandererD,
                        pWandererE, pWandererF, pWandererG, pWandererH,
                        pWandererI, pWandererJ, pWandererK);
    if ((pWorkSpace == nullptr) || (pConstants == nullptr) ||
        (pDomainSaltSet == nullptr) ||
        (pSnowLaneA == nullptr) || (pSnowLaneB == nullptr) ||
        (pSnowLaneC == nullptr) || (pPrevious == nullptr) ||
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
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
               std::uint8_t *pSnowLaneC,
               MUTABLE_PARAMS) {
    TwistExpander::KDF_C(pWorkSpace, pNonce, pConstants, pDomainSaltSet,
                        pSnowLaneA, pSnowLaneB, pSnowLaneC,
                        pPrevious, pIngress, pCarry,
                        pWandererA, pWandererB, pWandererC, pWandererD,
                        pWandererE, pWandererF, pWandererG, pWandererH,
                        pWandererI, pWandererJ, pWandererK);
    if ((pWorkSpace == nullptr) || (pConstants == nullptr) ||
        (pDomainSaltSet == nullptr) ||
        (pSnowLaneA == nullptr) || (pSnowLaneB == nullptr) ||
        (pSnowLaneC == nullptr) || (pPrevious == nullptr) ||
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
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
               std::uint8_t *pSnowLaneC,
               MUTABLE_PARAMS) {
    TwistExpander::KDF_D(pWorkSpace, pNonce, pConstants, pDomainSaltSet,
                        pSnowLaneA, pSnowLaneB, pSnowLaneC,
                        pPrevious, pIngress, pCarry,
                        pWandererA, pWandererB, pWandererC, pWandererD,
                        pWandererE, pWandererF, pWandererG, pWandererH,
                        pWandererI, pWandererJ, pWandererK);
    if ((pWorkSpace == nullptr) || (pConstants == nullptr) ||
        (pDomainSaltSet == nullptr) ||
        (pSnowLaneA == nullptr) || (pSnowLaneB == nullptr) ||
        (pSnowLaneC == nullptr) || (pPrevious == nullptr) ||
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
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    std::uint64_t aPrevious = 0xFCF41FD0B6D0403BULL;
    std::uint64_t aIngress = 0xF40F55241EFF50B9ULL;
    std::uint64_t aCarry = 0x96F07BC95A62DD46ULL;

    std::uint64_t aWandererA = 0xF2EBD09F6227069FULL;
    std::uint64_t aWandererB = 0xC952DB5C484323A3ULL;
    std::uint64_t aWandererC = 0xFD964179C94FF955ULL;
    std::uint64_t aWandererD = 0xCE654C4F29C126E7ULL;
    std::uint64_t aWandererE = 0x987C621AB1CAA2E6ULL;
    std::uint64_t aWandererF = 0x9EE87DF28562BC16ULL;
    std::uint64_t aWandererG = 0xC8F250B4109F7BADULL;
    std::uint64_t aWandererH = 0xE416FE8B69E25587ULL;
    std::uint64_t aWandererI = 0x865036A28253CA5AULL;
    std::uint64_t aWandererJ = 0xA61D543ED6B75739ULL;
    std::uint64_t aWandererK = 0xC3661F0DA0AA0663ULL;

    // [seed]
    ////////////////////////////////////////////////////////
    ////////        KeyRotate A
    ////////
    // Reset ARX state for KeyRotate A.
    aPrevious = 0x81649CEA9DD492D5ULL;
    aIngress = 0xD7A60D9DE15B3656ULL;
    aCarry = 0xA385EF160E6A23ACULL;
    aWandererA = 0xBB5B27E99D732F74ULL;
    aWandererB = 0x9ABCE9D5DC38FEEAULL;
    aWandererC = 0xBCC377E7372AD9CDULL;
    aWandererD = 0xA194BD1DC86CEA15ULL;
    aWandererE = 0xBDA04B8F51092CD3ULL;
    aWandererF = 0xBF0E7215BEE1D60AULL;
    aWandererG = 0x97DC23142BCD1A07ULL;
    aWandererH = 0xA726AAFD163EBF3FULL;
    aWandererI = 0x8C6890AF177A9E19ULL;
    aWandererJ = 0xCC0669BB9B899450ULL;
    aWandererK = 0xE6CA5C57650F2664ULL;
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), pSnowLaneA, pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    ////////
    pFarmSalt->Derive(aHeartLaneA, mDomainBundleEphemeral.mKeyRotateASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mKeyRotateASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mKeyRotateASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mKeyRotateASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mKeyRotateASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mKeyRotateASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aHeartLaneB, mDomainBundleEphemeral.mKeyRotateASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeyRotateASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mKeyRotateASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeyRotateASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mKeyRotateASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeyRotateASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aHeartLaneC, mDomainBundleEphemeral.mKeyRotateASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeyRotateASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mKeyRotateASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeyRotateASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mKeyRotateASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeyRotateASalts.mWandererUpdate.mSaltF);
    ////////
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateAConstants));
    ////////
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneA, pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    ////////
    // wood lanes to pWorkSpace->mDomainBundle
    pFarmSalt->Derive(aWoodLaneA, pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWoodLaneB, pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWoodLaneC, pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeyRotateAConstants));
    ////////
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneA, pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    ////////
    // crystal lanes to mDomainBundleEphemeral
    pFarmSalt->Derive(aCrystalLaneA, mDomainBundleEphemeral.mKeyRotateASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mKeyRotateASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mKeyRotateASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mKeyRotateASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mKeyRotateASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mKeyRotateASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aCrystalLaneB, mDomainBundleEphemeral.mKeyRotateASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeyRotateASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mKeyRotateASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeyRotateASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mKeyRotateASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeyRotateASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aCrystalLaneC, mDomainBundleEphemeral.mKeyRotateASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeyRotateASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mKeyRotateASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeyRotateASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mKeyRotateASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeyRotateASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeyRotateAConstants));
    ////////
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneA, pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    ////////
    // poison lanes to pWorkSpace->mDomainBundle
    pFarmSalt->Derive(aPoisonLaneA, pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aPoisonLaneB, pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aPoisonLaneC, pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aPoisonLaneD, &(pWorkSpace->mDomainBundle.mKeyRotateAConstants));
    ////////
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        KeyRotate B
    ////////
    // Reset ARX state for KeyRotate B.
    aPrevious = 0xF4E9BF484F71BB79ULL;
    aIngress = 0xC1233490DBCE97D4ULL;
    aCarry = 0xB511AD1FD4C3F29CULL;
    aWandererA = 0x97C8162507983E80ULL;
    aWandererB = 0xE9483C1B66DB0D86ULL;
    aWandererC = 0xA205B0035F68460DULL;
    aWandererD = 0xC096711B8FE83897ULL;
    aWandererE = 0xBFD624C0C55CA15CULL;
    aWandererF = 0xE77C2F0E34810BFAULL;
    aWandererG = 0xCB59B26676357699ULL;
    aWandererH = 0xF97818B1945F4EC1ULL;
    aWandererI = 0xBE03F8A53B02667AULL;
    aWandererJ = 0x83EEB42F22725C42ULL;
    aWandererK = 0xA03DAE7454ED65D7ULL;
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), pSnowLaneA, pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    ////////
    pFarmSalt->Derive(aHeartLaneA, mDomainBundleEphemeral.mKeyRotateBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mKeyRotateBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mKeyRotateBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mKeyRotateBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mKeyRotateBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mKeyRotateBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aHeartLaneB, mDomainBundleEphemeral.mKeyRotateBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeyRotateBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mKeyRotateBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeyRotateBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mKeyRotateBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeyRotateBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aHeartLaneC, mDomainBundleEphemeral.mKeyRotateBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeyRotateBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mKeyRotateBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeyRotateBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mKeyRotateBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeyRotateBSalts.mWandererUpdate.mSaltF);
    ////////
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    ////////
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneA, pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    ////////
    // wood lanes to pWorkSpace->mDomainBundle
    pFarmSalt->Derive(aWoodLaneA, pWorkSpace->mDomainBundle.mKeyRotateBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mKeyRotateBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mKeyRotateBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mKeyRotateBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mKeyRotateBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mKeyRotateBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWoodLaneB, pWorkSpace->mDomainBundle.mKeyRotateBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeyRotateBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeyRotateBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeyRotateBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeyRotateBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeyRotateBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWoodLaneC, pWorkSpace->mDomainBundle.mKeyRotateBSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeyRotateBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeyRotateBSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeyRotateBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeyRotateBSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeyRotateBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants));
    ////////
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneA, pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    ////////
    // crystal lanes to mDomainBundleEphemeral
    pFarmSalt->Derive(aCrystalLaneA, mDomainBundleEphemeral.mKeyRotateBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mKeyRotateBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mKeyRotateBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mKeyRotateBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mKeyRotateBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mKeyRotateBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aCrystalLaneB, mDomainBundleEphemeral.mKeyRotateBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeyRotateBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mKeyRotateBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeyRotateBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mKeyRotateBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeyRotateBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aCrystalLaneC, mDomainBundleEphemeral.mKeyRotateBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeyRotateBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mKeyRotateBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeyRotateBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mKeyRotateBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeyRotateBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    ////////
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneA, pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    ////////
    // poison lanes to pWorkSpace->mDomainBundle
    pFarmSalt->Derive(aPoisonLaneA, pWorkSpace->mDomainBundle.mKeyRotateBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mKeyRotateBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mKeyRotateBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mKeyRotateBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mKeyRotateBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mKeyRotateBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aPoisonLaneB, pWorkSpace->mDomainBundle.mKeyRotateBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeyRotateBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeyRotateBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeyRotateBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeyRotateBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeyRotateBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aPoisonLaneC, pWorkSpace->mDomainBundle.mKeyRotateBSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeyRotateBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeyRotateBSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeyRotateBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeyRotateBSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeyRotateBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aPoisonLaneD, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants));
    ////////
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        KeySpawn A
    ////////
    // Reset ARX state for KeySpawn A.
    aPrevious = 0x989169E260B79728ULL;
    aIngress = 0xCB963069CC1DAF02ULL;
    aCarry = 0xDBD39003ED336185ULL;
    aWandererA = 0x994DADA82F878713ULL;
    aWandererB = 0xC2CAC48E8CB8DADCULL;
    aWandererC = 0xE64AC0E0F0B9155BULL;
    aWandererD = 0xFFA3F22EE58080A8ULL;
    aWandererE = 0xF47AEEC7112ADC71ULL;
    aWandererF = 0xAD4547EC7A70CFC9ULL;
    aWandererG = 0xF0C8690ACC04CB26ULL;
    aWandererH = 0xC17F57DB1FC90658ULL;
    aWandererI = 0xB38F384492E93D03ULL;
    aWandererJ = 0xC1026D9B319D89C2ULL;
    aWandererK = 0xE5E831470420E19CULL;
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnAConstants), &(mDomainBundleInbuilt.mKeySpawnASalts), pSnowLaneA, pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    ////////
    pFarmSalt->Derive(aHeartLaneA, mDomainBundleEphemeral.mKeySpawnASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mKeySpawnASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mKeySpawnASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mKeySpawnASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mKeySpawnASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mKeySpawnASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aHeartLaneB, mDomainBundleEphemeral.mKeySpawnASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeySpawnASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mKeySpawnASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeySpawnASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mKeySpawnASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeySpawnASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aHeartLaneC, mDomainBundleEphemeral.mKeySpawnASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeySpawnASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mKeySpawnASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeySpawnASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mKeySpawnASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeySpawnASalts.mWandererUpdate.mSaltF);
    ////////
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnAConstants));
    ////////
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneA, pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    ////////
    // wood lanes to pWorkSpace->mDomainBundle
    pFarmSalt->Derive(aWoodLaneA, pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWoodLaneB, pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWoodLaneC, pWorkSpace->mDomainBundle.mKeySpawnASalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeySpawnASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeySpawnASalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeySpawnASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeySpawnASalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeySpawnASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants));
    ////////
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneA, pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    ////////
    // crystal lanes to mDomainBundleEphemeral
    pFarmSalt->Derive(aCrystalLaneA, mDomainBundleEphemeral.mKeySpawnASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mKeySpawnASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mKeySpawnASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mKeySpawnASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mKeySpawnASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mKeySpawnASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aCrystalLaneB, mDomainBundleEphemeral.mKeySpawnASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeySpawnASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mKeySpawnASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeySpawnASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mKeySpawnASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeySpawnASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aCrystalLaneC, mDomainBundleEphemeral.mKeySpawnASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeySpawnASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mKeySpawnASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeySpawnASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mKeySpawnASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeySpawnASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeySpawnAConstants));
    ////////
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneA, pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    ////////
    // poison lanes to pWorkSpace->mDomainBundle
    pFarmSalt->Derive(aPoisonLaneA, pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aPoisonLaneB, pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aPoisonLaneC, pWorkSpace->mDomainBundle.mKeySpawnASalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeySpawnASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeySpawnASalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeySpawnASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeySpawnASalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeySpawnASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aPoisonLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants));
    ////////
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        KeySpawn B
    ////////
    // Reset ARX state for KeySpawn B.
    aPrevious = 0x9E749C66372E97E8ULL;
    aIngress = 0xF45FD20930C5CF67ULL;
    aCarry = 0xB9264D696A7F0E9FULL;
    aWandererA = 0x98D656541DCCB81DULL;
    aWandererB = 0xBA89EA8135EC660EULL;
    aWandererC = 0x996E8FD63B9842F4ULL;
    aWandererD = 0xFFCFDDD310EA0A25ULL;
    aWandererE = 0x8E7499A60DDAC303ULL;
    aWandererF = 0xA76A6487F16D6AFDULL;
    aWandererG = 0xE10289C04FB5B39CULL;
    aWandererH = 0x870465D641B2A054ULL;
    aWandererI = 0xE258704052F95F34ULL;
    aWandererJ = 0xD33F6BBB15F9F5BAULL;
    aWandererK = 0xF0BA16C5F8E2E948ULL;
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnBConstants), &(mDomainBundleInbuilt.mKeySpawnBSalts), pSnowLaneA, pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    ////////
    pFarmSalt->Derive(aHeartLaneA, mDomainBundleEphemeral.mKeySpawnBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mKeySpawnBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mKeySpawnBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mKeySpawnBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mKeySpawnBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mKeySpawnBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aHeartLaneB, mDomainBundleEphemeral.mKeySpawnBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeySpawnBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mKeySpawnBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeySpawnBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mKeySpawnBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeySpawnBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aHeartLaneC, mDomainBundleEphemeral.mKeySpawnBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeySpawnBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mKeySpawnBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeySpawnBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mKeySpawnBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeySpawnBSalts.mWandererUpdate.mSaltF);
    ////////
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    ////////
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneA, pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    ////////
    // wood lanes to pWorkSpace->mDomainBundle
    pFarmSalt->Derive(aWoodLaneA, pWorkSpace->mDomainBundle.mKeySpawnBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mKeySpawnBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mKeySpawnBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mKeySpawnBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mKeySpawnBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mKeySpawnBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWoodLaneB, pWorkSpace->mDomainBundle.mKeySpawnBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeySpawnBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeySpawnBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeySpawnBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeySpawnBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeySpawnBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWoodLaneC, pWorkSpace->mDomainBundle.mKeySpawnBSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeySpawnBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeySpawnBSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeySpawnBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeySpawnBSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeySpawnBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants));
    ////////
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneA, pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    ////////
    // crystal lanes to mDomainBundleEphemeral
    pFarmSalt->Derive(aCrystalLaneA, mDomainBundleEphemeral.mKeySpawnBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mKeySpawnBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mKeySpawnBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mKeySpawnBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mKeySpawnBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mKeySpawnBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aCrystalLaneB, mDomainBundleEphemeral.mKeySpawnBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeySpawnBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mKeySpawnBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeySpawnBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mKeySpawnBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeySpawnBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aCrystalLaneC, mDomainBundleEphemeral.mKeySpawnBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeySpawnBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mKeySpawnBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeySpawnBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mKeySpawnBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeySpawnBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    ////////
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneA, pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    ////////
    // poison lanes to pWorkSpace->mDomainBundle
    pFarmSalt->Derive(aPoisonLaneA, pWorkSpace->mDomainBundle.mKeySpawnBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mKeySpawnBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mKeySpawnBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mKeySpawnBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mKeySpawnBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mKeySpawnBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aPoisonLaneB, pWorkSpace->mDomainBundle.mKeySpawnBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeySpawnBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeySpawnBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeySpawnBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeySpawnBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeySpawnBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aPoisonLaneC, pWorkSpace->mDomainBundle.mKeySpawnBSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeySpawnBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeySpawnBSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeySpawnBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeySpawnBSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeySpawnBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aPoisonLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants));
    ////////
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Twist
    ////////
    // Reset ARX state for Twist.
    aPrevious = 0xEB1EA23669461136ULL;
    aIngress = 0xCF026E179037220AULL;
    aCarry = 0xE25114D93150C9D9ULL;
    aWandererA = 0xE702ED9B41669D19ULL;
    aWandererB = 0xCF15D8CB6261F5C3ULL;
    aWandererC = 0xBB79F8D2262CDB77ULL;
    aWandererD = 0xB21669CCC3FBB395ULL;
    aWandererE = 0xB85B4747EDB7A7C3ULL;
    aWandererF = 0x9B00EF11268F0D8EULL;
    aWandererG = 0xC13854EA32620B26ULL;
    aWandererH = 0x9F4E6C03D77AFD28ULL;
    aWandererI = 0xE32FAB3CF78D78DFULL;
    aWandererJ = 0x9E9E40D41557AD86ULL;
    aWandererK = 0xD16B43C25495951FULL;
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneA, pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    ////////
    pFarmSalt->Derive(aHeartLaneA, mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aHeartLaneB, mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aHeartLaneC, mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltF);
    ////////
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    ////////
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneA, pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    ////////
    // wood lanes to pWorkSpace->mDomainBundle
    pFarmSalt->Derive(aWoodLaneA, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWoodLaneB, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWoodLaneC, pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mTwistConstants));
    ////////
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneA, pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    ////////
    // crystal lanes to mDomainBundleEphemeral
    pFarmSalt->Derive(aCrystalLaneA, mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aCrystalLaneB, mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aCrystalLaneC, mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    ////////
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneA, pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    ////////
    // poison lanes to pWorkSpace->mDomainBundle
    pFarmSalt->Derive(aPoisonLaneA, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aPoisonLaneB, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aPoisonLaneC, pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aPoisonLaneD, &(pWorkSpace->mDomainBundle.mTwistConstants));
    ////////
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Seed
    ////////
    // Reset ARX state for Seed.
    aPrevious = 0x8951EFDF02A2B527ULL;
    aIngress = 0xCF7E71741CE05FA8ULL;
    aCarry = 0xCC8933354C0281B8ULL;
    aWandererA = 0xE16F34B542A09574ULL;
    aWandererB = 0xB7669A31D9D72E7CULL;
    aWandererC = 0xE1D73C45EAC63705ULL;
    aWandererD = 0xD2ABCEACFF7B0E96ULL;
    aWandererE = 0x816CBB6A0EB0625AULL;
    aWandererF = 0xFFD9987E5623787DULL;
    aWandererG = 0x98CBF85078C823AEULL;
    aWandererH = 0xE1F230EB9E0B9124ULL;
    aWandererI = 0xC8BCE6D07BBA1FB1ULL;
    aWandererJ = 0x99680DBE7D594618ULL;
    aWandererK = 0xE6D0F5E7F4DC5AB2ULL;
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneA, pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    ////////
    pFarmSalt->Derive(aHeartLaneA, mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aHeartLaneB, mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aHeartLaneC, mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltF);
    ////////
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    ////////
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneA, pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    ////////
    // wood lanes to pWorkSpace->mDomainBundle
    pFarmSalt->Derive(aWoodLaneA, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWoodLaneB, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWoodLaneC, pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mSeedConstants));
    ////////
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneA, pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    ////////
    // crystal lanes to mDomainBundleEphemeral
    pFarmSalt->Derive(aCrystalLaneA, mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aCrystalLaneB, mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aCrystalLaneC, mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    ////////
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneA, pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    ////////
    // poison lanes to pWorkSpace->mDomainBundle
    pFarmSalt->Derive(aPoisonLaneA, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aPoisonLaneB, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aPoisonLaneC, pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aPoisonLaneD, &(pWorkSpace->mDomainBundle.mSeedConstants));
    ////////
    ////////
    ////////
    ////////////////////////////////////////////////////////
    // Reset ARX state for Seed stages.
    aPrevious = 0x9B5DC9A8B6E92F18ULL;
    aIngress = 0xA7E66787DF02A4EEULL;
    aCarry = 0xCC72E0E606402EC0ULL;
    aWandererA = 0xC93052F15F7CF6E1ULL;
    aWandererB = 0xB892982AD9D832E6ULL;
    aWandererC = 0xCED0119BFDB9DEBDULL;
    aWandererD = 0xE11AD01A7FD5D782ULL;
    aWandererE = 0xCA64C046C3E6A265ULL;
    aWandererF = 0xDA7C9D7DA7A440A2ULL;
    aWandererG = 0xFEC4ADAB0EAC1AD3ULL;
    aWandererH = 0xC5A353859D7095DEULL;
    aWandererI = 0x8CAC528378604248ULL;
    aWandererJ = 0xD3FB2A448553F5B5ULL;
    aWandererK = 0x85210B7977D06C19ULL;
    TwistExpander_Capella_Arx::SEED_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::SEED_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::SEED_C(pWorkSpace,
                 pNonce,
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
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::SEED_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::SEED_F(pWorkSpace,
                 pNonce,
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
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::SEED_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::SEED_I(pWorkSpace,
                 pNonce,
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
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::SEED_K(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::SEED_L(pWorkSpace,
                 pNonce,
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
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::SEED_N(pWorkSpace,
                 pNonce,
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

    TwistSquash::SquashA(pWorkSpace->mPoisonLaneA, pWorkSpace->mPoisonLaneB, pWorkSpace->mPoisonLaneC, pWorkSpace->mPoisonLaneD, pDestination);
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
                                       std::uint8_t *pSnowLaneA,
                                       std::uint8_t *pSnowLaneB,
                                       std::uint8_t *pSnowLaneC,
                                       std::uint8_t *pSnowLaneD,
                                       std::uint8_t *pDestination) {
    TwistExpander::TwistBlock(pWorkSpace,
                              pSource,
                              pSnowLaneA,
                              pSnowLaneB,
                              pSnowLaneC,
                              pSnowLaneD,
                              pDestination);
    if ((pWorkSpace == nullptr) || (pSource == nullptr) ||
        (pSnowLaneA == nullptr) || (pSnowLaneB == nullptr) ||
        (pSnowLaneC == nullptr) || (pSnowLaneD == nullptr) ||
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
    std::uint64_t aPrevious = 0xFE2A62940D19A672ULL; std::uint64_t aIngress = 0xD447995FE4BFC2E4ULL; std::uint64_t aCarry = 0xB258F041023AFFB1ULL;

    std::uint64_t aWandererA = 0xA47A35FFB8FB20A5ULL; std::uint64_t aWandererB = 0xBAAFE75E3307246DULL; std::uint64_t aWandererC = 0xB82D4EE75FEF0DC3ULL; std::uint64_t aWandererD = 0xF2973AE5CD52B5E1ULL;
    std::uint64_t aWandererE = 0xA561650780515DDFULL; std::uint64_t aWandererF = 0x8DD8D901848DFA34ULL; std::uint64_t aWandererG = 0x937A85114C81F7E0ULL; std::uint64_t aWandererH = 0xD0EFCD0B87A73A66ULL;
    std::uint64_t aWandererI = 0xD09184A06DE6A07FULL; std::uint64_t aWandererJ = 0x930E06E8F9EC9B1FULL; std::uint64_t aWandererK = 0xC9EC09E7AE2F900DULL;

    // [twist]
        aPrevious = 0x95B09193D82BDB30ULL;
        aCarry = 0xADA5349EE5BAA7F2ULL;
        aWandererA = 0x802F976ED7ACAC5EULL;
        aWandererB = 0xC9D912214CBB9BC0ULL;
        aWandererC = 0xAFCFF981EBA4A5F2ULL;
        aWandererD = 0xD5D56A66F60AD011ULL;
        aWandererE = 0xA2DA96C347F49EC9ULL;
        aWandererF = 0xFB926E82F2504E13ULL;
        aWandererG = 0xE57EB6AC80B3DDCDULL;
        aWandererH = 0xFB4096C7D0B4D6D5ULL;
        aWandererI = 0xAA0BF31BC9ACAF2BULL;
        aWandererJ = 0x96288066481E73FAULL;
        aWandererK = 0xFC66EEF936C2E285ULL;
    TwistExpander_Capella_Arx::TWIST_A(pWorkSpace,
                 pSource,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::TWIST_B(pWorkSpace,
                 pSource,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::TWIST_C(pWorkSpace,
                 pSource,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
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
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::TWIST_E(pWorkSpace,
                 pSource,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::TWIST_F(pWorkSpace,
                 pSource,
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
    //
    TwistExpander_Capella_Arx::TWIST_G(pWorkSpace,
                 pSource,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Capella_Arx::TWIST_H(pWorkSpace,
                 pSource,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
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
            0x43B9711D98D38101ULL, 0x533AF854AFF9A060ULL, 0x1F28BF6BA619FBC0ULL, 0x679D26FC42DA3C6BULL, 
            0xA110B0BC38F756BDULL, 0xC72A116A0167910DULL, 0x0912170A55463899ULL, 0xA283555B59AB96FDULL, 
            0x17859A8B39A4BBB9ULL, 0x8AFE34E0F04459DFULL, 0xC7EF381C73865062ULL, 0xBFED3D297B33B7C0ULL, 
            0xA6E2EF599A38C67DULL, 0x3E8E50122C093DD7ULL, 0x6CFC0EEEBB50F3CFULL, 0xAC2624E77B282077ULL, 
            0x8651DC4E15E7EAB8ULL, 0xB1C3F3E7887F193FULL, 0x555B16FD279B1140ULL, 0x2088DD6C9AFE23CAULL, 
            0xF3D77FD9D0FF2D64ULL, 0x08CCD5F29D9A0B8DULL, 0x81FA0C7A64669C7BULL, 0x71721D431E10AE16ULL, 
            0xB5FFAC39F3B7AC98ULL, 0x6C7EBFAB495F0776ULL, 0x9A01ABD4551689B0ULL, 0xD35C457CBB4FCE4BULL, 
            0x6F8A099A29F22F9FULL, 0xA364F5692E7353CEULL, 0xCE497FDBC6FE4847ULL, 0x0DB7132CADC97B23ULL
        },
        {
            0x8C523E64C260E063ULL, 0x12C58BFF3CE60F73ULL, 0x2747E805AA1753C6ULL, 0x469F2B06AEEC2772ULL, 
            0x79D9B93C78E6EA2BULL, 0x09D72D183711D4EFULL, 0x9A00303F08C578F3ULL, 0x749E667C1312DF7AULL, 
            0x09B498318D736332ULL, 0x7C795EF3CBE284EAULL, 0x8CDD458BADF63FDDULL, 0x4B2EE84B7710CF35ULL, 
            0x3369D8E8A80D1E54ULL, 0x9CE4AB47393A3AD7ULL, 0x920A4507D9A1F73FULL, 0x006E107F6D42CEA9ULL, 
            0x95BFD42CD802C45BULL, 0x6114E477C8405BC3ULL, 0x077AB810AB1763BCULL, 0x292580E284F3962BULL, 
            0xE1553CD9A0CC3E5EULL, 0xBC8DE4C17E9903DCULL, 0xC582BF75CE1D3D2EULL, 0x5BD01778B0B90F28ULL, 
            0x2CF21940E5A94DA2ULL, 0x52E304C6A0F15A90ULL, 0xD3A983531544B6EEULL, 0x76CA1ABB6C952708ULL, 
            0x103F7E372A27775CULL, 0x4A0B5B07B2150E58ULL, 0x6A7EA6E5D4EE2ED2ULL, 0x23129558475ED857ULL
        },
        {
            0x2BE76155F41ADFCCULL, 0xC0444D13A33DF395ULL, 0x4B0AEAF75F3FA133ULL, 0xC5C151F8AEF2C8D2ULL, 
            0x08402D2C51E23A31ULL, 0x2F9D0F9D3196F3E7ULL, 0x160F67C4F39E78B9ULL, 0x9C2137F38F68EAB0ULL, 
            0x119330179CADD874ULL, 0x9697394C502F7A0EULL, 0x5D7BB2ADBFFC9B10ULL, 0x14A983B6AAFCB66DULL, 
            0x81AD80776E03838DULL, 0x0243B4005E0BC1ACULL, 0xC7F1DC2B0FEBB9F3ULL, 0x959B4C47358686D3ULL, 
            0x27EA4DCA8D34463DULL, 0x55D2B81D8C0CE27DULL, 0x063455959C192C22ULL, 0x2A66DEE97425E651ULL, 
            0xAC6CBAEA9605D527ULL, 0x9D15E4C7DC55C56DULL, 0x1D4774721DBC8619ULL, 0x0D6B84458B6463D1ULL, 
            0x8EE28D4F32EA3B4BULL, 0x19DC9B5755920D42ULL, 0x9D66DD2D50F9A3F4ULL, 0xB6684A6AA0E5F434ULL, 
            0x7EDC8F1B0A30A4D3ULL, 0xC6FC3A15F6A18D2FULL, 0x0B08B3E6565E7FEFULL, 0xF9AF042B47E9DB77ULL
        },
        {
            0x9593B84C53BF60FDULL, 0x26B29AD5186E9D9FULL, 0x93D6A65C99DDAAA8ULL, 0x141EAB3EB8C1BA25ULL, 
            0x90330AD6608ED5D7ULL, 0x1F54ADCCBEB06453ULL, 0x4F40E20E39D92DB7ULL, 0xA6604536DE70AFA8ULL, 
            0xA12D4BD805CD7103ULL, 0x2C57099116437361ULL, 0x1E63B1CC587C5635ULL, 0xC0C8F4CC1F9AC6ECULL, 
            0x3668464771C72612ULL, 0x364CBB0C0E581F00ULL, 0xEABC7C4C4F0B4878ULL, 0xBE5EFEEECF86BAF7ULL, 
            0x3C40BD133EB180E0ULL, 0xB746677D472A35D9ULL, 0xB9419578E8955DA9ULL, 0xEC6E3D2BFF912623ULL, 
            0x1359BA130C6CB8A5ULL, 0x133C74BD3635375EULL, 0xB38197B58A12B53DULL, 0x064CE96F7F980953ULL, 
            0xD09F56021E376D7BULL, 0xD675E63769405B1EULL, 0xED4348B44E961038ULL, 0x8F79F0F4C19489E4ULL, 
            0xC8F78B0FF9C39E49ULL, 0xFFFAFCF93F558928ULL, 0xBBCA5069F2D2DCEBULL, 0xAB321291F8A5B62FULL
        },
        {
            0x4D077159FACF1A10ULL, 0xB55A22D9AF6E1EF5ULL, 0xAE3BB1A9A564AE30ULL, 0x7FBFC7D87B9868EFULL, 
            0xC99C55733D413A3AULL, 0x468746133A27AD56ULL, 0x3DB92CCFF4640CE7ULL, 0xE9F25817954837CDULL, 
            0x9083A4612F442828ULL, 0x3F5C0B6DC3DA0497ULL, 0x17B7411042A4FED1ULL, 0xC4BF9109CF73D491ULL, 
            0x73A67DCB40A4FF8BULL, 0x87FE79FB2C143A04ULL, 0xC7EEDD857EFC2189ULL, 0x995356EBC5A57170ULL, 
            0xEF087E83C6B71895ULL, 0x3F8811C1417141C9ULL, 0x4B7949620BD923CAULL, 0x3F2B8144FC13C559ULL, 
            0xB525790C2B52EF42ULL, 0x6A7020FFC87A3B9AULL, 0x078E9DF88B867EF3ULL, 0x20F08DEE176CDE04ULL, 
            0x64B16C9625F8BD19ULL, 0x20F8FE3F6DC545ABULL, 0x78A23632E3171E20ULL, 0x4538A497C54FF56BULL, 
            0x70D176F9719707AEULL, 0xBCA1EC76F0710A2CULL, 0x44158E106949BBABULL, 0x7820EF8AD97CE39DULL
        },
        {
            0xF5818BBDE37BFA88ULL, 0x9955F8D3018BC05CULL, 0x460726329657AF91ULL, 0x1751B2EB5B489E85ULL, 
            0x79E40B7545BCEAC3ULL, 0x25EC0EB945205EACULL, 0x8D129B2AF832780CULL, 0x6E09A72592BBE194ULL, 
            0x294A2C842864BCFDULL, 0xD1EF29B7BCD5D754ULL, 0x57BA293EF32B41BAULL, 0xC4AA05B24824AD19ULL, 
            0x89E4E265E9D71E0EULL, 0x3BD8557F6F18CDB4ULL, 0x54ECE72DF0600EDDULL, 0x2F4F1B232FF6F6A7ULL, 
            0xEAA978CE2342388AULL, 0x2A626672C455953FULL, 0x671E12B4E727D024ULL, 0x50675B91D73012A0ULL, 
            0xC3FD87DF504BCC39ULL, 0x201CF0B990CE2E2CULL, 0x552873B5DE8954DAULL, 0xBBFFA5D85073C90DULL, 
            0x438A4CA4657A77BBULL, 0x419630D4345F1693ULL, 0x93F5295643C4A0A0ULL, 0x73B9EEA03665118BULL, 
            0xC5666484DD77C613ULL, 0x797EF5D6A3A35DB9ULL, 0x58EF64C9BBA5D157ULL, 0x204D8DB73663C5FFULL
        }
    },
    {
        {
            0x7DB9F56295AA4F5DULL, 0x5912B3F967346D5CULL, 0x8061DA22E1135BEDULL, 0xCF6605B0AA0C25FCULL, 
            0x7B6899A110DD1167ULL, 0x4191A6367800C79AULL, 0xEFDDF0ADA9B0B7EEULL, 0x7C1FD69B8AFE75A3ULL, 
            0xF5D33F8C14C6BD42ULL, 0xC278110C2FF79775ULL, 0x88353E31A38B915EULL, 0x185DB96B0927A05EULL, 
            0x3309BDD4D44F9C72ULL, 0x42780EEB51885243ULL, 0x03ED267C011C0F5EULL, 0xE00E02003F399584ULL, 
            0xF88D8E6E7C76DCC2ULL, 0x42E33C3947679005ULL, 0x2AD4A4452C3A0167ULL, 0xF30C2D7AC410255CULL, 
            0x575D5556E21F607BULL, 0xAAD780574608AAC6ULL, 0xD8F53FAB202F9AC3ULL, 0x5366BBC97E59D6D3ULL, 
            0x84EE1AB595557E2CULL, 0xD3A3DEE1A5F26E5EULL, 0x82BA7E25F8EA33ADULL, 0xB675F8A92F04884EULL, 
            0x5F16C7DE2837FB3DULL, 0x50305105E03948B6ULL, 0xF87362C6B8DFC255ULL, 0xC3F252724EB3A89DULL
        },
        {
            0x468460E31310007EULL, 0xF1723A5541CD687CULL, 0xDFD6C2A06A5F9D65ULL, 0x78C663BD8E7CB1F8ULL, 
            0x4D9314B1F44CDF4AULL, 0x641EDDC60B7FF2ADULL, 0xFC3879A72F5F60BAULL, 0x493A31ED3688C9C2ULL, 
            0x5DC46C786E1C866FULL, 0xEEBAD28DD5E558D2ULL, 0x921EFC6EC83A4D15ULL, 0x121A806A2D243252ULL, 
            0x9BE55C6D66173532ULL, 0xA049824861D23510ULL, 0x3384F2638D21E99CULL, 0x8E8DA558F6A1F825ULL, 
            0x475C9EAD32895945ULL, 0x967DEE3F3A115D8DULL, 0x362682C0E8C4AAFCULL, 0x1F33D992EA179FFAULL, 
            0x0F300B0E4014B9D2ULL, 0x8690A7742C5D1FD1ULL, 0xB985273AE5372D5FULL, 0xF22A6152195649BAULL, 
            0x61A47704001E7683ULL, 0x54D1F6AEB78E5035ULL, 0x3E245565868481A5ULL, 0x1B2F0596C8FE1002ULL, 
            0x2C96FC89399BE28EULL, 0x68FDFC6F9275A9A8ULL, 0x1493DD0DA54C7657ULL, 0xCF02719F068A3533ULL
        },
        {
            0x8F6A891E24BBF7DCULL, 0xCDC09636FAA89945ULL, 0xD1978C75865C0EEFULL, 0xE4E09BEE8BAA42D9ULL, 
            0x990FC80C2000D6A4ULL, 0xCA2630CE0C7B7BBFULL, 0x650AE728886462B7ULL, 0x3C091C030B0E79D5ULL, 
            0x239A40A00FA0FDE6ULL, 0x29A2199F1D6F0E87ULL, 0xAC22622D6F9E2FDFULL, 0xA17295ACA5EA1BFCULL, 
            0x4E0680C5D46CD031ULL, 0x1A88DD80D660E1D4ULL, 0x00F10B58110DD377ULL, 0x3BA3817387B1B355ULL, 
            0x17C2119506C3926BULL, 0x9A22E8C9BE3B5988ULL, 0xD43E338F321ABDA8ULL, 0x1D93E9B9F2623F29ULL, 
            0x1C9AF20B0D87B5A9ULL, 0x1109D7E3B8AC9046ULL, 0x6E8D303233657675ULL, 0xF767C3A5C8259B34ULL, 
            0x2D50C8FAE1A83B70ULL, 0x658D83000BA88412ULL, 0x32E5F88D32D3BB77ULL, 0x5F0CB841395AE2ADULL, 
            0x92299F23A5CF6A0AULL, 0x960CA237F76A3EA3ULL, 0x89949BEAA2D12C96ULL, 0xC8A0B1EC85B26011ULL
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
        },
        {
            0x3DB7EC296589A947ULL, 0xB768648E4C83362AULL, 0xA1B9B920D326E925ULL, 0x267F936C7D0E8811ULL, 
            0xC7DE6EAA46543291ULL, 0x3ADE69E8590CF949ULL, 0x9D0A62AE4BC2DAA9ULL, 0x13276F6211723DEBULL, 
            0x3A094569E76D159BULL, 0x7B10EB21F3234003ULL, 0xF57D2205C3CC6849ULL, 0x692778552B824DA5ULL, 
            0x2A48B5DC30F584CBULL, 0x429A8AE12B279A68ULL, 0x4ABEAE95512B4C23ULL, 0xCED651611CE2B43DULL, 
            0x590C910604D8E14EULL, 0x586CE1294855869EULL, 0x9C79A0C9248EC385ULL, 0x8157D47129356595ULL, 
            0x7669284FD96CA148ULL, 0x09A2B265F9DDC701ULL, 0xF3F177DE83D96BA4ULL, 0x95B38EDD988DD901ULL, 
            0xD3CB6E924D6F92D9ULL, 0x5B11DBD170D386EAULL, 0xD4EF0BB87563DEA1ULL, 0x572D755F636E5C12ULL, 
            0x420CF52CCE94ED07ULL, 0x2D527708226C5F52ULL, 0x1C3DED36DCEDA84CULL, 0x3F04C4D90A50A1B9ULL
        },
        {
            0x89E5A57995D60C68ULL, 0x82291711B258C118ULL, 0x0A9E4A1C6FEACA2CULL, 0xE59CC0477DDFEE9BULL, 
            0xAA1CD70AD97BA02AULL, 0xA453C2F815065990ULL, 0x99C9F0D25ED320BFULL, 0x9B83A922373488D9ULL, 
            0x71B6AC5EA2B41ABFULL, 0xF4468C415DE7CF79ULL, 0xD55B007212BA1CB6ULL, 0xA1C96753913C5003ULL, 
            0x38763477D63BA6DEULL, 0xE44A659407A3799DULL, 0x27AC6176D13D5908ULL, 0x02EBDA922768E662ULL, 
            0x5E732FDDA4129604ULL, 0xBEB638B0B5D19E9EULL, 0x9F700217C043D7A4ULL, 0x8A13C5683C06570BULL, 
            0x26FADF1647F816DAULL, 0x550327FB137EA498ULL, 0x01E3F3997FC2B23EULL, 0x6DAB61C329EBA7D8ULL, 
            0x9CEC035FCC48682FULL, 0x78D839D9292C1A9DULL, 0x38DB39A3FE7C5A37ULL, 0x6A832F0F9E3D758AULL, 
            0xBDE70B3A6CEFFE22ULL, 0xB5F0ED5C5160B1B4ULL, 0xDF89C5326DC38886ULL, 0x9F9833C15EBC48F7ULL
        }
    },
    {
        {
            0xCC439407ACD316C7ULL, 0xE3B484D8BEE1C954ULL, 0xC9A6AA0CB0627A15ULL, 0xA77ACC41A92335D4ULL, 
            0xBE43B177C28644DBULL, 0xCA7FFFE12228B492ULL, 0x1CC217B5567B5FFAULL, 0x1B7FDA533CF84809ULL, 
            0x207043436482D93EULL, 0xFC72EDB97DF6B45CULL, 0xAF3584E91156F191ULL, 0x310A8BDC30B3CC7CULL, 
            0xD46689B5AD5395ADULL, 0xF470C60729D500FFULL, 0xE4BFF48E2F720128ULL, 0x5F905101EDFF6EE7ULL, 
            0x425166D0EC7B2691ULL, 0x0026E1124CEBCE43ULL, 0x5CDB1E107B18D20DULL, 0x92EF04EA0BF57E15ULL, 
            0x821B364BF627F5BFULL, 0x1E8CA7639306A022ULL, 0x0A0D2B6AC244B180ULL, 0x9508EE01A15F5231ULL, 
            0x21335607BF377A13ULL, 0xB6E8CE0684689E3BULL, 0x73B6740101CB51EDULL, 0x790B796FB63BE14AULL, 
            0x2AD544C2F2EE65A3ULL, 0x4A752737CAFB8025ULL, 0x6C60FE38EE716C42ULL, 0xCEC32BF6AA0CA4B1ULL
        },
        {
            0xD3D1731854018C3CULL, 0xB69EE44E6291835AULL, 0x503E7C8D8C25CF5FULL, 0x7EE981AAED454632ULL, 
            0x4BFFF55A8C5CE38EULL, 0x54B8836A127B7ECAULL, 0xC3D8C7FB15F5C219ULL, 0x2B38696E8531E34EULL, 
            0x34CAF064901D6BFBULL, 0x117598BDD47E6D19ULL, 0x7DE4C52F74CA8EB7ULL, 0xCCA58BB497C464A5ULL, 
            0x7B5C6306CD8A1888ULL, 0x7D7D89BC61E2FDAEULL, 0xF9F2B5139CB71A2FULL, 0xEFA2C6091ED6333FULL, 
            0x621CB775FAFA74E8ULL, 0xEE4ACAF660153E97ULL, 0x1E002F0B4D21E8F0ULL, 0x5282AB40988A9A7CULL, 
            0x7F97A501EE58D922ULL, 0x7CB39245DAC5E0BCULL, 0x1290EF5785265630ULL, 0xDAE34C3234913FECULL, 
            0xD525A1A5DE2BD673ULL, 0x680FF86D8E9967E4ULL, 0x5D0A2D25010F46E9ULL, 0x7665CEF0AAB3B59AULL, 
            0xCD424F5D90953E95ULL, 0xCC3A5B25CA54F84BULL, 0x5FDC3496EA4C9D21ULL, 0x906AC3D6245CAA06ULL
        },
        {
            0x560A81401C909A0DULL, 0xFB29C4E041878E92ULL, 0x3A799D08860032F4ULL, 0x066A63E26C4599D2ULL, 
            0x566A40CC10D1B2B1ULL, 0x91298EE3D34252AEULL, 0x96F5491AE4F80E64ULL, 0x0C62BD4FF42260EFULL, 
            0xA4C17317BBB282BEULL, 0x093EB18C0FC9D449ULL, 0xF2CFD49F50B5C9F4ULL, 0x895D4C7CEA8212F2ULL, 
            0xD510D35009E5D24BULL, 0x886EFABD9B999041ULL, 0x57177F7C20E00C78ULL, 0x3B2B12C0134A1D19ULL, 
            0x0D666B761A06535AULL, 0x166B2D544788EBCEULL, 0xDCB8F896D2D83E2DULL, 0x7854D870E00B0AC3ULL, 
            0x5A284228F25DA024ULL, 0x749C7874C3119CD6ULL, 0x455C2CE83992C7A5ULL, 0x872A30041AAD1737ULL, 
            0x03B02B1755C9722BULL, 0xEBDADDA0CDB74010ULL, 0x8F508BA3D1029C8DULL, 0x42D6A5A7F1337AA7ULL, 
            0xD5FFA4724C5BA0F9ULL, 0x35542CF10AB608EAULL, 0x280EDF21F98D4B6DULL, 0xEC8FCC7F039E8624ULL
        },
        {
            0x633A9E4E1CC7A5CCULL, 0xE34D708C8F659D77ULL, 0xE58123FD7E80D1D4ULL, 0xA7B37757CBDAB57BULL, 
            0x1B29596CCDAB8E8BULL, 0x7A491FE8769645B4ULL, 0x66707CC31C0958FAULL, 0xE45B9D5A4F79EC5DULL, 
            0x8C583EA202A4C082ULL, 0xEC6CB5B4FC0DC02BULL, 0x3DBE00C1D2949A3BULL, 0xCEBD5A996FED28CCULL, 
            0xF0BD7B2B7A4D835FULL, 0x757D11E3A1D00501ULL, 0x6CAA743946009601ULL, 0x04814AD07C145F34ULL, 
            0x3227F13A451A2336ULL, 0x8D9EFCBB476F4333ULL, 0xC9687312097F817EULL, 0xB9AD175DF3213204ULL, 
            0x379AF8933A27534AULL, 0x0513DA02CB8941DDULL, 0x96F4D73623270619ULL, 0x4986358629E8B93EULL, 
            0x5D3F02CE4DCEC5BAULL, 0xCD7ADE5E3DA6902FULL, 0xA697C87F45CF0514ULL, 0x44EAA2AFF3C63D7EULL, 
            0x55C1EBAC190A0727ULL, 0x9323E204CE9B72C9ULL, 0x78B73A767EF5D0EAULL, 0xEF87357BCBFF3A63ULL
        },
        {
            0x67FFF957977DBC0FULL, 0x9C1F2BDD81214A60ULL, 0x0CA08156375C23F4ULL, 0x0AC778C984656FA0ULL, 
            0x913F06DCA6527D9DULL, 0x6D0E1B2DA0B587B7ULL, 0x570939BEE4F4430DULL, 0x72A5EAC034625A38ULL, 
            0xDB762FC91EEE2E45ULL, 0x1834BF6A230C97F5ULL, 0x0F6B74554BD051BBULL, 0xDC1226BF7CF8170EULL, 
            0xFC20A47FF233F820ULL, 0x1C8F6E8D866E94DCULL, 0xC566746EBA1E7959ULL, 0x727CB2BAD63B8D1EULL, 
            0x10D2E73C4B09368FULL, 0x82481BCEA03E837BULL, 0x1E302ADCB4CD0599ULL, 0x2D6C5540A21A433AULL, 
            0xB939E5DDA6B16DF7ULL, 0xD01D3E0824ACCDC8ULL, 0x19C301DCD3143A0FULL, 0xA37C543B30DF1F95ULL, 
            0x1F315160FF81A073ULL, 0x653F7A53BB7D72A0ULL, 0xB96045B519B53144ULL, 0xBC89159FC72E8C56ULL, 
            0x5D6EA9E1FDEA9392ULL, 0x607FEDCB9EA4EBBDULL, 0xAD648DBE1D811365ULL, 0xE3F46F80481CCA89ULL
        },
        {
            0x540D0641480D4845ULL, 0x271D0859C8215703ULL, 0x4356F65A03C4F302ULL, 0x1A6668817FEEE204ULL, 
            0xE7A69B6559B27484ULL, 0xAF22D07E01D66A64ULL, 0xCBDC3F6C738A66EBULL, 0x94B1A8BB2F2E0846ULL, 
            0xA8592D62636119C4ULL, 0xC24D78E82ABD14BEULL, 0xEC9F6F6E3C91A711ULL, 0x7CFFFB26D0CA7602ULL, 
            0x8F10E4A01E21E037ULL, 0xBAE839290F2149A4ULL, 0x2EC669DD38A510A3ULL, 0x119F942EF6D41D1AULL, 
            0x85EB12D9A96706F8ULL, 0x7D8818EF33778C87ULL, 0x0457FE77840E48E1ULL, 0xA12D94C25873A179ULL, 
            0x694D054875145ECCULL, 0x978038EC23559E39ULL, 0x33336767974D8BF7ULL, 0x145A79F393C962FCULL, 
            0xAE5A3FC0C615D844ULL, 0x203890B88C2CE1E8ULL, 0x9612F4036A600FEEULL, 0x5B9ED8A803F7E2C8ULL, 
            0x1A8AA3DD2EC38A47ULL, 0xB5B791436DFB8A60ULL, 0xAB471B031FDBBAFAULL, 0x1FD911CE0C2ACC03ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Capella::kKeyRotateAConstants = {
    0xFE4767493A245CAEULL,
    0x484D27DE57ED33D6ULL,
    0xA1FE7756C099BC5CULL,
    0xFE4767493A245CAEULL,
    0x484D27DE57ED33D6ULL,
    0xA1FE7756C099BC5CULL,
    0xE9C53EB6C0DC0D2BULL,
    0xC6D46B0BD04EDFE6ULL,
    0x63,
    0x1C,
    0x26,
    0x96,
    0xFF,
    0x85,
    0x45,
    0x55
};

const TwistDomainSaltSet TwistExpander_Capella::kKeyRotateBSalts = {
    {
        {
            0x42A451B5142ADA4EULL, 0x693D2BCDB73175B6ULL, 0x2CB6518FBBFBC7C9ULL, 0x15AF14CFFE6FE1EAULL, 
            0x8B7294B1398E19EFULL, 0x7D8DF7B4BA473281ULL, 0xEBAF9974DB5FEBF9ULL, 0xE400C64110CE92A1ULL, 
            0x413206A8A1C05E89ULL, 0x240E5613B22A4B45ULL, 0x166ECC9727F7F040ULL, 0x0D54E54FF8A93E0EULL, 
            0x647995C036401B1BULL, 0xDDE10A19388345E2ULL, 0x8F6EF2E7DBFA9AD3ULL, 0x0DD388D9AAE72792ULL, 
            0x426DAEC1BA5A8C95ULL, 0x74EC78BFC57EEDB0ULL, 0x7EC51D640DDCC507ULL, 0xCD4129C02FCF462BULL, 
            0xC45E48AEA960D981ULL, 0x2AFD837B220D0E24ULL, 0xCE4FE706F31C5556ULL, 0xB0B265B9A070FD07ULL, 
            0x047204FA09E4E424ULL, 0x0068E5FD19030C66ULL, 0x295B3DE0E9648013ULL, 0x093A76531EDA3198ULL, 
            0xE006CB879FFEE2B4ULL, 0x1AE99D447967FA34ULL, 0x7A29AAC82A2317C3ULL, 0x2978DDEF07BA2B7EULL
        },
        {
            0xB548E584553083C0ULL, 0xBE36C5E3D95ADF9FULL, 0x950B99A9E4B32B98ULL, 0xF4DF7EA75A848168ULL, 
            0x14113A7C590B761CULL, 0xD41EC0445A39A77CULL, 0x156C295490D3E4EBULL, 0xD4DBC4BA9DD2183EULL, 
            0x3F07CA4E46FFE48BULL, 0x509EC6AF863574F4ULL, 0xF190DB6D3136D2CEULL, 0xBA65D64FAD66ACC1ULL, 
            0x3F6193344699936DULL, 0xB54EF3EEF1F10833ULL, 0x6D6387D6E5E5E514ULL, 0xA60E800D99B5DD61ULL, 
            0x865906C34E496340ULL, 0x1FDC3054C9AC4A22ULL, 0xCE7D608800108FC6ULL, 0x6EA69107229D9639ULL, 
            0xBE059A45FCF4D1D5ULL, 0x2435F2EBE87C5489ULL, 0xE6846189C7059468ULL, 0xC584B0EABA896E41ULL, 
            0x2AD153F9203D2118ULL, 0x01E6BD7B1B1AB496ULL, 0x16011BB16C58FE43ULL, 0x3435F8E1D7FA8B4CULL, 
            0x59DE5ABD3E4A3FEBULL, 0x0F29C2BEF4F1BCBBULL, 0x358A9CAF653B3C77ULL, 0x0EF5C322C3185D95ULL
        },
        {
            0x9676F97160FD55E7ULL, 0x1D17EB89E9ECBC62ULL, 0xA824D7B8F98D96A7ULL, 0xADB179FEF64193C8ULL, 
            0xC6ACDAB468873F3BULL, 0x72753CDE5271E6CEULL, 0x9F788E15ADE79E85ULL, 0x303157AACE1B93F1ULL, 
            0x41C10FBAE58014ACULL, 0x526CA10584BA1F55ULL, 0xC0BF1362019DC8A7ULL, 0xDC8E4A3F18AD671EULL, 
            0x167C0EFD183D5C19ULL, 0xCFAD91C957DD2D20ULL, 0x8E5CE57438B893F2ULL, 0xE98437D7C0A9E9E2ULL, 
            0x6FFB73266D80772FULL, 0x4D6C8AD372405198ULL, 0xD20528256673898BULL, 0x197E6950EDEBF732ULL, 
            0x859B61F537921345ULL, 0x7580ACE47E8B0ABDULL, 0x9CF5B4788D06861FULL, 0xF090098ED32B16FCULL, 
            0xC7C61BA4EB84FF00ULL, 0xD27827495564BDF4ULL, 0xE44D021714C88F78ULL, 0x1E9269985E755157ULL, 
            0x29F06832161FFF15ULL, 0x72DF259A8BDE8B95ULL, 0xC10B907407F6FCB4ULL, 0x10D5A6FA45868F99ULL
        },
        {
            0xE943B515E809C50AULL, 0x04958EB4F6280A40ULL, 0x481401836FB62529ULL, 0x98690E8E9D02E9A5ULL, 
            0x57194A3DBF5153F8ULL, 0x1DEEDF33CD19EF6CULL, 0xBBC8EF5BFCF624B9ULL, 0x510B560713CF2048ULL, 
            0x7ACAA49DF4AEE98CULL, 0x80061B829EDDB6A4ULL, 0xA4CFA262633FA30CULL, 0xF05130CE9BFEC00DULL, 
            0x9C982863797908F6ULL, 0x381E635D880ADC2FULL, 0x0713A2848DC3738AULL, 0x4DAF116ABA8EC6EAULL, 
            0xDE917E06ABF00E11ULL, 0xD2C56A7FD81E6800ULL, 0x8AD434CAEF9A5460ULL, 0x41783D348609634CULL, 
            0xEA7234FBCA05EA06ULL, 0x2BC93020C20C2588ULL, 0xC179464F8FB5C945ULL, 0xDD6D1683DE549349ULL, 
            0x9AFF015CECEA8BCAULL, 0x006FF7ED42D2355CULL, 0xD73CE5C00AFC793BULL, 0x46DBE3DBD0494FF9ULL, 
            0x5E779E1278EBE43FULL, 0xFEC874E935EA42BCULL, 0x33092D4FB5F25C1AULL, 0x0A148ECC6CB508C9ULL
        },
        {
            0x4E981EA813EC61B0ULL, 0x1E5F66DA462CBDDEULL, 0x05D52A230735A5CCULL, 0x800B43AC660A1BE9ULL, 
            0x4490ACD31E8A6ACBULL, 0x4D936A9CDC53D658ULL, 0x1B764F356F1BBECBULL, 0xBD030BDD865A266EULL, 
            0x2F1C90D213A2F5D6ULL, 0xA33F8334CF470D01ULL, 0x7718AE4ACCBB2E19ULL, 0x2A240D86DC2551F1ULL, 
            0x8D922A6B16489BC3ULL, 0x66344C1341EB0339ULL, 0xA44584BCC29FB9E7ULL, 0x7D881F6E849F2E5AULL, 
            0xBFCB23B37ACB12E6ULL, 0x6E7026D2751796F8ULL, 0xF3A148002118034CULL, 0xCF14B09E8E65E492ULL, 
            0xF04CE9579F6952D6ULL, 0x6CD368947ECA927DULL, 0x07CB2D3AB618B911ULL, 0x7BE8538203AA3CACULL, 
            0x04ADB0F28D2C86D3ULL, 0x70A68C054A1E74B1ULL, 0x769B10AA78A3857DULL, 0x36F56EED3E2F6CD8ULL, 
            0x23354AD41B1AAACCULL, 0x7EA6A53C0799F681ULL, 0xEA981AD07498CB76ULL, 0xF8CF1A8C1E774B31ULL
        },
        {
            0xC9E2FE45DA4C3886ULL, 0x4D4F545F2EF1E12AULL, 0x67B84D00001519BDULL, 0xA0A8C6021725BC2AULL, 
            0xFC9E9E55A981E64AULL, 0x0A35E7C8D8210C3EULL, 0x64544C8259240703ULL, 0x97C93684C96884B6ULL, 
            0x892B3C56C1D15008ULL, 0xE1DD614B038CAD88ULL, 0x428F128AEB834AB1ULL, 0x2E4D8249ADBE4972ULL, 
            0x641BD8CF70999B20ULL, 0x7C0C6D6DA71924C6ULL, 0x9CB585DE08FD9CA9ULL, 0x3E72586D5EF027F4ULL, 
            0x9C0DB65F5A0BE1F1ULL, 0x0868B2FE13AD3235ULL, 0x95B46CC94A2DBA7AULL, 0x1F86EFDB73E944A5ULL, 
            0x6F7A629C5FCC5F4AULL, 0xD98AB72385790BD6ULL, 0x482AD84CEC556D67ULL, 0x7F8447B12FAA07D3ULL, 
            0x316B988F0297E993ULL, 0x37D4E520C5022D9EULL, 0x114A52066A73C11FULL, 0x92E0EE3CED8382E6ULL, 
            0x6970548C8ED8A707ULL, 0xE2BC3DE5E06A0BF3ULL, 0xE4296E1446B46ED3ULL, 0xA45DF21CA4CEA1EAULL
        }
    },
    {
        {
            0xCEE0C9271EB4DD2BULL, 0x67FEC1E75A03F284ULL, 0x88D4091506401801ULL, 0xD89C92804891032EULL, 
            0x8094E268014F6A48ULL, 0x82CC122C841FC56DULL, 0x888D39ACF96B611BULL, 0x3181316C2D879BFAULL, 
            0xEFB35B8333D41012ULL, 0x96470541A4C85C58ULL, 0x13729287AA96FEEEULL, 0x867BFB68DEC4325FULL, 
            0x8E3B5FD9394F8B23ULL, 0x52EA9C4920434BD1ULL, 0xF917F00BEFE5D831ULL, 0x20880F9C6AB00A20ULL, 
            0x5344D645E8726A99ULL, 0x83B11C4AF11678ADULL, 0x110BB7803EED4FA8ULL, 0xEB6E3A5CFB39B27BULL, 
            0x6EEDE792E4B1B2B3ULL, 0x1199B9E827FEE1C1ULL, 0xA0580F1168ADFD78ULL, 0xB3BCDB98EBF6D22EULL, 
            0xEDA868815CE3844CULL, 0x177DB9EBA5E164EAULL, 0x815E53198FE5FCDFULL, 0x88542F83BE9D97D9ULL, 
            0x80AC0B8BEFA5CCBCULL, 0x2517D8E26B7F1348ULL, 0x51A84BAA8E0DE117ULL, 0x682968DC7722D562ULL
        },
        {
            0x679B0010813DB6F1ULL, 0xB242208CA8DC6CF3ULL, 0x58EA8ADD2BA3E9C7ULL, 0x2AB1175C7A222F1DULL, 
            0x98615213303E099CULL, 0x61A59B14839B823CULL, 0x4027A1CC421C280BULL, 0xB11FAC907D5D29AAULL, 
            0x6C638711E25ABD84ULL, 0x9D5F0E872B645AB4ULL, 0x09FCD81336C9A7B7ULL, 0x92ADE7D93A5D7EAFULL, 
            0x50BF5771E43B115EULL, 0x5567F462C41F8137ULL, 0x570CA9BEDBC8B6D5ULL, 0xC686DD903E608B8BULL, 
            0x576E869A9822C753ULL, 0x478E3172851CAD33ULL, 0xA8398B689A8F6AA3ULL, 0x1F87C4FEA2D56983ULL, 
            0xA3F76D32A2DEFB3CULL, 0x8CF6394281EE5162ULL, 0x918050B7BAC46395ULL, 0x5D2528CE23B681D8ULL, 
            0xE873EC9720819901ULL, 0x024DEBA833EE47EAULL, 0x5C993D4601094B2CULL, 0x8BED92342F17FFB3ULL, 
            0x77A4FA274B3037B3ULL, 0xBE5822325F3393F5ULL, 0x3C483F25B98B1740ULL, 0xB6136AF2A848BC23ULL
        },
        {
            0xEB64881DAEFFDAA1ULL, 0xFC3ECAF54785BEEDULL, 0x3F9CCD529769255EULL, 0x8F4BE812DDACCB0AULL, 
            0x405B439AE5A90720ULL, 0x8E1246BE6F7917B7ULL, 0xA655F6FD20370BB7ULL, 0xBE31D423886298ADULL, 
            0xB7E6E6134A38C17CULL, 0x416C5DF7C11B64C9ULL, 0x5B0D75AB73CC3064ULL, 0x84224D9F9EBE932DULL, 
            0xC5BED093D96FAC58ULL, 0x40AE64215928F818ULL, 0x823A29FE3B380C5CULL, 0xE525AFFC39E556BBULL, 
            0xD867C443A21FC4C2ULL, 0x406D5A54E6907F5AULL, 0xBD798C8D6DBDFD64ULL, 0x1B025C3769AF11D3ULL, 
            0xA02501AE613AEC59ULL, 0x336CFBC127289FE0ULL, 0x8F17E66C2F8AD30CULL, 0x84A5B023A0A702DDULL, 
            0x948FF4D07DE1FE9EULL, 0x58A6CFBE00710DDDULL, 0x3EA2E1BF8EFA72A9ULL, 0x31A3F22A2F6E1FCCULL, 
            0xBB6A9D81F00EC53CULL, 0xBF53734AB363568CULL, 0x5FA84D0E70AAE229ULL, 0x0B852BE996439AD8ULL
        },
        {
            0x2BF4D42A7D0A739EULL, 0xE3F1F30A50149175ULL, 0x48F3FFE6F2951DD0ULL, 0x41CFC301D9EA4736ULL, 
            0x51D5557741F5B90EULL, 0x60AC1452A9F9C82EULL, 0x0DB1364E79F8A5E3ULL, 0x3776D2677CDD482CULL, 
            0x75C962BB855994ABULL, 0x940011357632911CULL, 0x11A6DC4C5C8B1FA9ULL, 0xAB7AA376F56B2AC8ULL, 
            0x903C5098B53A7181ULL, 0x436BCF78206181D7ULL, 0x5B6B97B032E4F0BBULL, 0xEDABB6EA3262AA77ULL, 
            0x7DAE5CADAE807FB1ULL, 0x80BAE2EF97B9FA8DULL, 0x1AE7A9EC395FE4D7ULL, 0x60B6F2C498CFD601ULL, 
            0x88452FB8B5DA40E0ULL, 0x680A5395388ED600ULL, 0x69BA0BC3413766A8ULL, 0x5ABE0C84D12CAC49ULL, 
            0x8F0874BAB0DCE316ULL, 0x02C0ECC7F89CA17CULL, 0xE23CBF23EB318412ULL, 0xFEC968B8F328BBC2ULL, 
            0xA01535D102FC0686ULL, 0x16C3F0E081DF361BULL, 0x4093B6968989ED70ULL, 0x496AA2C3DC492708ULL
        },
        {
            0xA01F718FC6C19BF5ULL, 0x9BE7C6FECB11F51DULL, 0x5AC95B5DE214FF37ULL, 0x7C58EC140D7F2CC2ULL, 
            0x48A566FFF5AAC6A3ULL, 0x8B71ED82A66BAA66ULL, 0xD6B63A42B73951DBULL, 0x58E9894F8A29FD2CULL, 
            0xECFB7F90E1AAD817ULL, 0x3B11EBB89787E86BULL, 0xF985AD2444CD5DD1ULL, 0x44C0D610DA06F27FULL, 
            0xFCE64650DF239481ULL, 0x8357AFA5034D0238ULL, 0x79C70A02F44D3BD9ULL, 0xBECBD805A351E94FULL, 
            0x5F3A154B1F38F3F3ULL, 0x99322F184AE543FDULL, 0xC4D57A00378FA6CCULL, 0x22B9E0989C05E815ULL, 
            0x94D2DAB55FD053AAULL, 0x1A073543B98A3B32ULL, 0x3B8E652F9AEF0CC0ULL, 0xAD2728E254F40FE3ULL, 
            0xE798DEF22BB2C8F8ULL, 0x22FB46C1C7D3187DULL, 0xBB02137B12383F65ULL, 0x09411A98D2037FCDULL, 
            0x2CCCA917E5068650ULL, 0xE9CA4ED9BDF482A3ULL, 0x2F8EAA01497CEF6AULL, 0x9C823A4C373FB4A5ULL
        },
        {
            0x1922D5DD245F373EULL, 0xC3A4AC29DA2FEF34ULL, 0x0A6E4C7315466707ULL, 0xBCA7F272FBEEF074ULL, 
            0x312FB77E86E5EEADULL, 0xEF75188024EBB4C6ULL, 0x2304704F8ABBF2AAULL, 0xB3E9C778CD8507EBULL, 
            0x9B3B4F7D66C1521DULL, 0x8F8B05BB41EA99A4ULL, 0x47553AF2B30DEEF3ULL, 0xD4324950E574FEEDULL, 
            0x80BC6F7DDCE49C8AULL, 0x5616615B38B92950ULL, 0x41BF4A17F3D20B97ULL, 0x0E8156BB485F4A57ULL, 
            0x34DA10D1DF4B52B1ULL, 0x52AA4E44A560BEEEULL, 0x7C775B069388E5DBULL, 0xC0EAFEB7495D0DEBULL, 
            0x6346C17DB5821B22ULL, 0xCA67A958C8A2F45FULL, 0x7A3851E2EC20670DULL, 0x6B78D2AE3CEEE1C6ULL, 
            0xB9B9BDA5736600FFULL, 0x428536E9F80F76ABULL, 0xAED3EF666D5C59ACULL, 0x53812BF81C49CD5AULL, 
            0xDCDFC70ED0874FABULL, 0xAD1F88DEA21ABFEFULL, 0xAFC5418F4A2CFCBAULL, 0xCA1407420733C5EEULL
        }
    },
    {
        {
            0x13D990721BC125F3ULL, 0xFB631D75AEA5F9C8ULL, 0x97E1EDDE8B78CB40ULL, 0xDBA50E4F80ED6BCDULL, 
            0xAC9E57D2F56B85C8ULL, 0x6F2762D3F35E5479ULL, 0x637483A47065644DULL, 0xE1330704FF213569ULL, 
            0xA22A7813B5167E7FULL, 0x281AE23B312E8F96ULL, 0x7A8D2D96E9D81349ULL, 0x74F1645C255EB2D2ULL, 
            0xD2E6E3492B4D186DULL, 0x4E7E49D838894607ULL, 0x4D5379F4D584D893ULL, 0xDE73C62C39E06414ULL, 
            0x14AED98432E9468BULL, 0xD1DB8DCE7D081AEAULL, 0x0A336A47E8E88056ULL, 0x5E34FC298EA582B8ULL, 
            0x178541DE4E227204ULL, 0x44B4CE7110168125ULL, 0xB57F00ABBC8BAF24ULL, 0x2F85ED2F837E6AAAULL, 
            0xE38D888209BEED2AULL, 0x2FAA9D8D8D1EE796ULL, 0xA7BA0B226FA774B6ULL, 0x06B70BBEB368D8F5ULL, 
            0x0B563E8C6116EA73ULL, 0x67E128853783135FULL, 0x854B69B51EC27498ULL, 0xC2961B78B511FED2ULL
        },
        {
            0xDDDDADDC75A866F6ULL, 0x788A694482E14BD4ULL, 0xE2D345F095671B11ULL, 0xD3C5C36C93F0C9E0ULL, 
            0x094980E82A60E9D2ULL, 0x40DACAF95D71C031ULL, 0x41F65B9DB019BC04ULL, 0x1C6D8C4D2FE79FCFULL, 
            0xE5511AE8BFFC0749ULL, 0x7E6F81AF14B07A5FULL, 0x0939AAFCECF1D3C4ULL, 0xA4685D8C772F450AULL, 
            0x418A91E711C552FCULL, 0x5F2DC79CF55D95A0ULL, 0x837C875C99F152C8ULL, 0xE61D4E2675BA5FCBULL, 
            0xB3316F7B6EB575A8ULL, 0xB0B385D05504EA7CULL, 0x18BB11B1847A3D30ULL, 0xA3D8365A7248AD75ULL, 
            0x4194C0529E145EEEULL, 0x30940D052B221AADULL, 0x780D3F862C802968ULL, 0x8DBEEDDE323AD1F0ULL, 
            0x805B423021B9AE75ULL, 0xCD983AAFA8D56E43ULL, 0x6B968DD0E5D8B692ULL, 0x14CC9C985B84A136ULL, 
            0xD11BDCFBB8F23D49ULL, 0xEEF21AFA2DCEAFD4ULL, 0x74F3F0D5EA850B34ULL, 0x2466A8E5BE024EA0ULL
        },
        {
            0x323D44FAA5CB7A12ULL, 0x888FE4074302F044ULL, 0x2C033E8F16CE132FULL, 0x131436172DF23E93ULL, 
            0xFE13B0B788EC1085ULL, 0x1484569AFE4A4270ULL, 0xD0F0D3D6C51436F0ULL, 0xD7D1D49911479CBFULL, 
            0x9B280C0EB69CAE17ULL, 0x057C9D652D79050CULL, 0x576D0131B91B50E8ULL, 0x9A21079462AD71E8ULL, 
            0xD9FE07B7FD5F4960ULL, 0xBD3C94B8E38ACE7DULL, 0xC1523ECC2F4EC556ULL, 0xE77A24C0B9288603ULL, 
            0x77901CEF2C6DF832ULL, 0xAF99B614FAA4A156ULL, 0x1E35B24FA93C12FDULL, 0x5C984EAF707C25DDULL, 
            0xCBC39C684AA672C2ULL, 0x0CFCD386D09E69F1ULL, 0xE686D9F41039F6B4ULL, 0xEAF66855AEC736C9ULL, 
            0xAE4A2F03401A17FCULL, 0x6917E2D59CB841ADULL, 0x51DC83DA52BDD9CBULL, 0x0CE38A43D7664AE5ULL, 
            0x5FBB04F741368A91ULL, 0x1981F5D0F2F0B041ULL, 0x23E544BE1297CB76ULL, 0xABE7485E15756430ULL
        },
        {
            0x5563A52253487006ULL, 0x09C025C1367E01C1ULL, 0x5ACED8E91F56ED87ULL, 0x78A779FEE46A7AC0ULL, 
            0x21CADF3187DE218DULL, 0x981093E54898E619ULL, 0x51E05FD5BC08AC9AULL, 0x4A66D91CD10239C8ULL, 
            0xCB3FBF4D159472D5ULL, 0xF9A039B75D471136ULL, 0x70CCCC799DFD6BF2ULL, 0x0EB7D5C74413A848ULL, 
            0xA5C34DADBEE72CB8ULL, 0x004E533A8CC08600ULL, 0x931F49D03B28D943ULL, 0x358B7B17DDE47806ULL, 
            0x52F155E199782E89ULL, 0x6D834B3C0203317BULL, 0xE97AFA04D38E9C51ULL, 0x6C54B2ECE0B8D29FULL, 
            0xAEF5E6952E8B3F5CULL, 0x1507F54D24AD528EULL, 0xC556482FDCCE1719ULL, 0x4D0E6309B069C5FFULL, 
            0x766661576AB72E6AULL, 0x692B14A2E51D1220ULL, 0xEBAC695785912835ULL, 0xC3E065EA73B43F8BULL, 
            0xBDFCE3BA89653E3FULL, 0x71E72F8DAC51AF74ULL, 0x9A6006C731D936C8ULL, 0x8019A0054D705675ULL
        },
        {
            0x3BCD4960A44A962DULL, 0x157BA6963B8A4757ULL, 0x7F0D2FE3F928311BULL, 0xF3AC23FE0AA35DD8ULL, 
            0x17525E86FBDC903EULL, 0x661355B53D8314BAULL, 0x7E95784D6083B121ULL, 0xBA4CD893877D74B5ULL, 
            0xF7B2C1E332D5D1B0ULL, 0xBAC206AE722FF836ULL, 0xFE48DB03F30BBBDAULL, 0xCB499EF13D6C6644ULL, 
            0x045697965551CB28ULL, 0x047E104FF264F6F0ULL, 0xD28542EEBB4D3286ULL, 0x38A2E5B26C829FE1ULL, 
            0xAAD881425CD4A52FULL, 0x93B4A472DF28930EULL, 0x22A30C07774D1DDEULL, 0xD5064209BF357095ULL, 
            0x70E44246E7DADDF2ULL, 0x08C35CB7E65124ADULL, 0xF193773B60673EC0ULL, 0x11EE651AF3F7B3F2ULL, 
            0x6E9C5AFA9694CB2BULL, 0x641EA6D9DD6C1166ULL, 0x19217DCC35CCD2CBULL, 0xEB85BD32A1AAB6E6ULL, 
            0xD493E31E85E94236ULL, 0x8C9D6C1EEAA51B46ULL, 0xFF5C71008BCFED25ULL, 0x09A8B408E3F342ECULL
        },
        {
            0xE4AFC4B9386A2314ULL, 0xF3B4CFF800BE1F59ULL, 0xEA8C3E4F83A903BEULL, 0xAF3D7A291C3CD4FEULL, 
            0x7D9AF906D80C048FULL, 0xC881F2E382920424ULL, 0x1EA2C31EC8954B6BULL, 0xE9A2EBF7951768B7ULL, 
            0x21DF5A09243C711DULL, 0x8C8FA9A1C8BEAAE8ULL, 0x0C9B85E7BF15C48BULL, 0x0A1083896BAA9CA2ULL, 
            0x70F93EAE56F05C44ULL, 0xBDA2219920F5CF88ULL, 0xD3C158C1E019C824ULL, 0x1DF9355E034C6557ULL, 
            0x500E9CD9884C3C28ULL, 0x5D1168CD0FE60E5DULL, 0x0F056B2FE7EC3801ULL, 0xD5CA8EB036A42A5DULL, 
            0xB8B9D8C38A559206ULL, 0x16D27F9A23905225ULL, 0x3330AA04CFB577A4ULL, 0x2082CA5704008137ULL, 
            0xD759238E7A210E28ULL, 0xE6252FD72BB34DEDULL, 0x2AD7511B4A433702ULL, 0xCF331297B90DAF5DULL, 
            0x64ED86C31A771039ULL, 0xDE40539580C84551ULL, 0xA38F696B115624DFULL, 0xCC3BDE35A2F2B152ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Capella::kKeyRotateBConstants = {
    0xE01E15CCC8B82FDAULL,
    0x925DAC079DCF02D9ULL,
    0xE9F8E4AF6EF1E98BULL,
    0xE01E15CCC8B82FDAULL,
    0x925DAC079DCF02D9ULL,
    0xE9F8E4AF6EF1E98BULL,
    0xEFD2EFDB77166BEFULL,
    0x4F8980241EA645DBULL,
    0xA1,
    0xC0,
    0x19,
    0xEC,
    0xCA,
    0xA1,
    0x3E,
    0xE6
};

const TwistDomainSaltSet TwistExpander_Capella::kKeySpawnASalts = {
    {
        {
            0x549F064837DA7596ULL, 0x8B5EE9AADF0DC769ULL, 0xCA40A3B8173097F8ULL, 0x770670B885836858ULL, 
            0x99B13B32C4EB9504ULL, 0x6338B27ADC6C0DB5ULL, 0x51673F93B3791777ULL, 0x549EB5C57225DD2EULL, 
            0xE0CA77EA9B150615ULL, 0xE9D8D9987A51E991ULL, 0x0E2676949F06C75BULL, 0xE2FEC635308E6417ULL, 
            0xA81455FB04F8793EULL, 0x90C44FCFFAEC4618ULL, 0x46C5BDDE7198C2F0ULL, 0xC7880A931BFF03CFULL, 
            0x4256B3CA6C719990ULL, 0xCD937B9F148D2C81ULL, 0xE109175221039354ULL, 0xC5239D35133624DAULL, 
            0x0CB1904871F26140ULL, 0xC467CFF94B35F29EULL, 0x45B33795D71DDCFCULL, 0xCCC36F334A2FE211ULL, 
            0xF56C63DF94AFFD2CULL, 0xCF9EA3389938DDFAULL, 0x25E6A5B7285CA5DDULL, 0x6FD2D8DEFF3D6DC6ULL, 
            0x84F2BEE83B650CAEULL, 0xDF0F40D52A75C1BAULL, 0x6C82CB8784CE8123ULL, 0x214B0C46DD1039C1ULL
        },
        {
            0x46E3B9DEB16F1889ULL, 0x50B6CDEF47284D55ULL, 0x9BEAEA785A3202DFULL, 0x9A7578D5F5B09F7FULL, 
            0x0BBC48A9318A88C9ULL, 0x84475B07C875FB6FULL, 0x696244B96B3B49DAULL, 0xA0AE2934E374664CULL, 
            0x9F5613D368787AB5ULL, 0xFD060332BD92FAD5ULL, 0xE55826BA7D2E7C5EULL, 0xB2934A9512F90F11ULL, 
            0x1456A95C62465F10ULL, 0xEFBF18F4988BC592ULL, 0x65DD928D240E96B0ULL, 0x1CC7471792465DF3ULL, 
            0x81268996A36ADCA4ULL, 0x7D1AFD8D17D6AC25ULL, 0x7DDC58003711D51CULL, 0xDA22A5EF69625F34ULL, 
            0x122A1126AAF0CB81ULL, 0xA2AD15D73BEB6A1BULL, 0x76EE1557FD3017C1ULL, 0xBE9A981095B46A38ULL, 
            0xBA5934C12814BBE0ULL, 0xF470265DBBDFD706ULL, 0xE9BEBDD434C956F0ULL, 0x1E49D1D9BCED9621ULL, 
            0x8657CEFE7E86677CULL, 0x5C6A4F8938E15853ULL, 0x91ACD87A348155D3ULL, 0x0F1846A0429E80B9ULL
        },
        {
            0xB03C748A3600F2B3ULL, 0xB5FE451576A34353ULL, 0x98446213A77C4BACULL, 0x93E4430D41AB454CULL, 
            0xCAEC496943FD54B3ULL, 0x8A3934AAE3A91625ULL, 0xBF56CF0F3A775C59ULL, 0x3C22844EBF83699EULL, 
            0x7DF5AD9887AA783BULL, 0x0B2E9E5D3CD45AE8ULL, 0xD9684CE3179F290EULL, 0xE9495E2EF6F6C830ULL, 
            0x54F7F916EC1388AAULL, 0x785F3086E37D0805ULL, 0x5235AE2E6B339DBAULL, 0xC9ED9951C84122F7ULL, 
            0x2F21070C98B3E55AULL, 0x51D6C2BBEA6678F2ULL, 0x392219EBCD3BDB93ULL, 0xCECBD4A75A005700ULL, 
            0xB48E899887E6D2D1ULL, 0xF1E5C6349B29E3A5ULL, 0x4306079997376712ULL, 0x40C924E082D3F8F7ULL, 
            0x232FD2BE5B29E5F7ULL, 0x08069799D7337C8EULL, 0x6D5D6F15867C5D96ULL, 0xFCBD824DC8D41B4AULL, 
            0xE7609C0B89C711E3ULL, 0xA444F498CBE7BC34ULL, 0x24BE79E31DC6B09CULL, 0xC136CB85B04CBDD3ULL
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
            0x74E38768B659F675ULL, 0x3032C6C070C844F0ULL, 0x64650DB76DCF89A6ULL, 0x6478C3FC2C33A535ULL, 
            0xE1928D7863B2EE58ULL, 0x24CB9BC80DECFF1DULL, 0x6A3DD53D6E28853FULL, 0x8D9F10220808DA1DULL, 
            0x192FB3CB96A8602AULL, 0x2810B67FE65EEBDBULL, 0x937F1B5146DC6B18ULL, 0x9FA2E5F89109F470ULL, 
            0x87DF465F122B3758ULL, 0xA177C40E6D6710F5ULL, 0xA2B8F36E84EA72C6ULL, 0xC0CEAAB5850CA20FULL, 
            0x816EBB4578025233ULL, 0x3F218572A1B9354AULL, 0xDC63EF3FA22601F7ULL, 0x707B4C7464B86C88ULL, 
            0x44DB8CF2DB9F85B2ULL, 0xAEC08CB86BC7BCC9ULL, 0xA05C5E050977CFA9ULL, 0xFC64ACF150E57812ULL, 
            0x6C289AF103A9C643ULL, 0xD44B76A9A9BDE8F2ULL, 0xADB36A73162E14F2ULL, 0xF0019A565D2B551AULL, 
            0x6EA8668A81117507ULL, 0x83F6F20711A78268ULL, 0xB4663CF8E7921C78ULL, 0x654987B83848F5B7ULL
        },
        {
            0xA88394B379D9A0F1ULL, 0x770A5F484AD582E2ULL, 0x580ABE3EC977BA76ULL, 0x3E0A6EE883532532ULL, 
            0xF51C783935B6B184ULL, 0x7994D1AD1D29400BULL, 0xE6D22F52F411346BULL, 0xBE32F731B86E2633ULL, 
            0xD15B4AA87788DE86ULL, 0xED763221732E381FULL, 0xDA1D2A7D9F020A5CULL, 0x65ED325E7088DF3FULL, 
            0x1B662BDF48D31918ULL, 0x475A7AEAB3331673ULL, 0x60A7FF5F47BAD375ULL, 0xA4768F93A43CDC7CULL, 
            0x16FF0229267FDAF7ULL, 0x7CACFAB740F41F5DULL, 0x7E968179674F7266ULL, 0xBC8027D8F61D943EULL, 
            0xBE7FB4FF3E2A692FULL, 0x287E6737D9A29EE1ULL, 0x77DC241871F5EE66ULL, 0x6018CBD4F24B63C8ULL, 
            0x6F13966D8CF028AAULL, 0x12376ECFC6396256ULL, 0xBD74AA789735A152ULL, 0x5CAF29A735AE5B23ULL, 
            0x7D6CE90E3084153DULL, 0x188B739D602442F0ULL, 0x7AFD18AB40210FC0ULL, 0xD49AA02A54B10CCFULL
        }
    },
    {
        {
            0x9ABB64E41D4F78B9ULL, 0xBADEEC4BE616B9E3ULL, 0x1AAB79FE2D0605BCULL, 0x6244ADE56676D2B7ULL, 
            0x03D00C4B948F6976ULL, 0xDB0794BACAC7B7BDULL, 0xABD8B3CCFD428893ULL, 0x11A02CEEFD506070ULL, 
            0xE8E47C9D94E02905ULL, 0xA5AA60EBAB046D1FULL, 0x580E88029A586CACULL, 0x73D7D0997B22DB65ULL, 
            0x881E497F58EECDBEULL, 0x6115828D861497C3ULL, 0x626663AFB630F0B6ULL, 0x5E0353B964C4E3C7ULL, 
            0xA9784F7E41E7F7B6ULL, 0xA8C4FDAD5CF85B24ULL, 0x516C3B00A102EF0EULL, 0xE69CA8CDCC2C1CDAULL, 
            0x8811EEC7ACF7606DULL, 0xF85D3F07AB6AB07AULL, 0x059B6B6B141F58C8ULL, 0x19D1EB0DC89736BEULL, 
            0x7EA37EDF66604D1CULL, 0x5A1A99385446C7E3ULL, 0x45DACA10871690C4ULL, 0x977D6FD64BF5D806ULL, 
            0x7716665649588449ULL, 0x573E460F4D0F48D4ULL, 0x8144C0529BD76A8FULL, 0x87CC9895E25300FAULL
        },
        {
            0x369FB67E15568611ULL, 0xCCE03E17186D3BE3ULL, 0x1B557C15D1BB6242ULL, 0x898BF701E7772475ULL, 
            0xB09A096EC0647AA2ULL, 0x7DEA4AA1A7BAB643ULL, 0x0D347DDD23B623E2ULL, 0x9D224A5EB7236F5DULL, 
            0x797CC6E46D14BBFAULL, 0x3D5F894D0A0B08EDULL, 0xFEABCEBD87C96C8AULL, 0xCB206396B9E5830EULL, 
            0xEAFF6E15C60969F4ULL, 0x2DEE2B25B0403920ULL, 0xC9B25EB6BAB147F7ULL, 0xF3CC399A6DA38A29ULL, 
            0xC3CE91CB2CFD6BB0ULL, 0x6E5E653FF9733141ULL, 0x92D613198ABDA901ULL, 0x601CF1087F6C586FULL, 
            0xB19364320C56CE29ULL, 0x7E5467F973C0BAF9ULL, 0xF8D8A82B4209A6EFULL, 0x7D81347BE35B6CFAULL, 
            0x9119E638407AA601ULL, 0xC1B06BC2F2495A50ULL, 0x3B08CCEF2C72B2C9ULL, 0xF4255984529D334CULL, 
            0x1BA4F887924BE141ULL, 0x117B9E1BA5F52E4CULL, 0xACB17823CC91C687ULL, 0x46881F3F96EE5124ULL
        },
        {
            0x4CC7F4A1D175B552ULL, 0xE38F3D4F2EFB4B1AULL, 0x17A5996B81720F39ULL, 0xA11ED8CEA29646BEULL, 
            0x996AD53311F63063ULL, 0x63C999335884D8CEULL, 0x3CFF2F8322D3F587ULL, 0xBD06C5F0BC6F6495ULL, 
            0xFE4181F819F244C0ULL, 0xB2C88E4B7ADB60D7ULL, 0x1B69C3BD2C235F43ULL, 0x52BF5BC73E017FB5ULL, 
            0x5C84BB0AF3108965ULL, 0x0E04A8074B53485CULL, 0xC099B97FE7D38253ULL, 0x2390AA1A21281B10ULL, 
            0x2F842C776363CEE8ULL, 0x2C7BA47ACE786A5FULL, 0x22688C9353D07B09ULL, 0x6E82D111662A81A2ULL, 
            0x9752608CDE453833ULL, 0xC5967E670EF420E8ULL, 0x2EB6BB196C911E49ULL, 0xE0A9CA4C1D64D5BAULL, 
            0xEE1AFDBE829032EFULL, 0xBFBDF121859572FDULL, 0x863AD531DB3EF6FAULL, 0x474F702122C87CC3ULL, 
            0xA07C0C495CE8EE53ULL, 0x295BA21C31F2B924ULL, 0xF9EF265454F4C053ULL, 0x1CEFCDE83FC103BFULL
        },
        {
            0x71B6EA7A3DE07970ULL, 0x9D96B3EE73B772BBULL, 0x43183210C5DC27D4ULL, 0x8C7F4F5B68A99555ULL, 
            0x49A583329FB7A159ULL, 0x4B54347528872C7DULL, 0xA21F5BF09CDC21D8ULL, 0x7206594A75F38BC8ULL, 
            0xCADA18861C171FDAULL, 0x63E56FC003D14BC1ULL, 0x61AA53D9232752B6ULL, 0xD2FC3B508E649124ULL, 
            0x0B9EC26BD72BA19EULL, 0x59C877E0079EA98BULL, 0x92EB8FC4BDB490D9ULL, 0x6A71FDBC871D8352ULL, 
            0xCB534F4345316F40ULL, 0x0C709121F4D88C58ULL, 0x49F10AABF22E6A40ULL, 0x8B89701950566AE6ULL, 
            0x0DF5F2E18B67F413ULL, 0xB276ADD8859D56F5ULL, 0xBD4C0C5FB1E785FCULL, 0x14D115D65D45BFF7ULL, 
            0x66E312F79F0884CFULL, 0x78F903196A771359ULL, 0xC898F165BFB53696ULL, 0x82FC7270D2EED701ULL, 
            0xC4DFAAF6AD52FA6DULL, 0x7B4A68B182A2A976ULL, 0x32F4326D8EF5F7E2ULL, 0x7CAAF2C47511CEAAULL
        },
        {
            0x1DF39F298DD64FE2ULL, 0x91FFA05CE8C3ADA8ULL, 0x58E5D50431EEDBD5ULL, 0x79B9C31EC744AEB0ULL, 
            0x7C25CFB4ABEB8B40ULL, 0x8EBD7FBCA4849613ULL, 0xA4B46F3E5765180EULL, 0x7DEA4B0080C5A561ULL, 
            0x516F4507C1BF8DE4ULL, 0x0C0E139C3AAA9D74ULL, 0xE01BB75D72A7A44EULL, 0x3245298CB384E1ADULL, 
            0x3A8D144C07B564D4ULL, 0x8D02972D07BE38B7ULL, 0x101CDEEC11FA4956ULL, 0x5693D9D7304A14B4ULL, 
            0xFCD4D65D797F0678ULL, 0xFF3C4EF6C7C94A92ULL, 0xF282D8F56A56B22BULL, 0x83F218D357E6E5D5ULL, 
            0x54D4BF18399EB3E6ULL, 0xB97FD4A4E45F74CCULL, 0x9DA1FB7A40FB573BULL, 0xBCEAAB37639A312FULL, 
            0x8D6DCC00609F2E7EULL, 0x9D8A0086ABAB4C2CULL, 0x9BF17510CA6C5D7DULL, 0x4351B37220472A62ULL, 
            0x12746269B6EAA98AULL, 0x2DA89140DB58EFD2ULL, 0x394723EC8A403EB1ULL, 0x5DA8B6321E6F61A2ULL
        },
        {
            0x63B7AC42A5EEE1E7ULL, 0x3025EE78572BBEDFULL, 0x1F21265601051D9BULL, 0x6678A9FD1859A136ULL, 
            0x9B96CB05FA2905CFULL, 0xD2510030F8507A0EULL, 0xE36F33981E080BE3ULL, 0x89D22A2A114F9B9FULL, 
            0x4B389B992ABD053DULL, 0x0A840F62612DBA23ULL, 0xDA472F24C9734B18ULL, 0x869FB36E65E1C610ULL, 
            0x9921460BFD2EDB12ULL, 0xA399E5F9AA3BAEC6ULL, 0x26844969B28518C5ULL, 0x92B3B5E4D1557188ULL, 
            0x0156BCBF7350F39AULL, 0x243A246CCDF1A8DCULL, 0x757E9AEF0682B8CEULL, 0xE99EA9395E10E2C1ULL, 
            0xF18B34FCAF626492ULL, 0x803C5EB2E77A7229ULL, 0x4C4F53EAA2F120ABULL, 0xF8C6674E877A39F6ULL, 
            0xD90A7D78FB55554EULL, 0xD18CA81BEE3762D7ULL, 0x90E9BEDFA10A1066ULL, 0x6AEF821585FC7699ULL, 
            0x5753B71D783FDA34ULL, 0xB105C840EF3A8439ULL, 0x0C3E83E8FF430C67ULL, 0x38C1F269B3800339ULL
        }
    },
    {
        {
            0x5C226FD0915C0490ULL, 0xA18BCBFFFAAA7A64ULL, 0x0FD0BC7448C2FA8FULL, 0xEDF8B2B7E57B110CULL, 
            0x5B573B2634808766ULL, 0x90CB65419D442F4CULL, 0xC223DE44028F139BULL, 0xFB2385D838B17E27ULL, 
            0x99789547672DDCCAULL, 0xA7A870C665D43294ULL, 0xC72CDA6FFFEB1F79ULL, 0x86D70A4FCDB38113ULL, 
            0x1E7B7096617457F7ULL, 0xE9D5914F40F52D5CULL, 0x0E627B52CA41C74FULL, 0xD9354E991BCE9EF7ULL, 
            0x67BC3A75F0E29C0BULL, 0x9C4579B42AF6EA4AULL, 0x1890427E5E00E1A8ULL, 0x61C04439DD4BA517ULL, 
            0xCC257836E0018E6BULL, 0x8AB1058B8DC99F01ULL, 0x6AA5F6DA84000979ULL, 0xCAB90BAFB64188F8ULL, 
            0xB776251CF7D8030FULL, 0x67B16E05B1659A8DULL, 0x19976F19C7FB96FEULL, 0xB57D63CACA49F6BEULL, 
            0x9B87AE99E699DFA0ULL, 0x67F9261A53D02C4CULL, 0x57AE345DF16DFA1BULL, 0xC02EC863F4E068E0ULL
        },
        {
            0x59F41D920AC84C9DULL, 0x9C46F101B74972BFULL, 0x2EBAC79792C1D931ULL, 0x39A0F76A564FB0DFULL, 
            0x43061588FD36A776ULL, 0xE8CF01878942EFDDULL, 0xA2A19C198758B426ULL, 0xA7B0BCCAE43991DBULL, 
            0xBFD359038FA028DDULL, 0x4F9F9DD9E1CEB6E1ULL, 0x6174021D5FD29FE6ULL, 0xACE6793097DC32FAULL, 
            0xE576DC8F5F829E95ULL, 0x01F935AADDD41EAEULL, 0xDD4F035A008592EEULL, 0xAC106231027B78BDULL, 
            0x4D0C94F88EC35A71ULL, 0xB1E85CDDBEE6302DULL, 0x46098367BE6BF159ULL, 0xF0AD8B7A318435B4ULL, 
            0x29C356966C074D04ULL, 0xB28B6C6B6AEE02AEULL, 0x4BC98A6BBE7D3A0BULL, 0x81E5874F23F493B1ULL, 
            0xE58B9FF66C080A4CULL, 0xD70CAB6ADB07089BULL, 0x1B9196A63C4E4001ULL, 0xB6D84083F68E06A6ULL, 
            0xC04637305E2B2162ULL, 0x6BCA538549F9CA6EULL, 0x818610CDB6872D4FULL, 0x101B5D48B7C657A0ULL
        },
        {
            0xA71567DF2238486EULL, 0x5C3EEEB7BF434859ULL, 0x6C1890F2D2742A4BULL, 0xC0AEEC5AA83CEE01ULL, 
            0xAE1EB9FFCAD87D18ULL, 0x77471DD9D192E5DEULL, 0x09B09B32AF220EB2ULL, 0x8A55EB16889FC3E0ULL, 
            0xCE2A88BCCB6BE665ULL, 0x417C569165A9FCB8ULL, 0x673C478D14CD2029ULL, 0xB0D1809CD2642BE2ULL, 
            0x6717C7B5D5B8C542ULL, 0x9108D0BD616E14DCULL, 0x7EFE32E23301CAA9ULL, 0xB6DE2E44E49109B2ULL, 
            0xB590516A52A3C146ULL, 0x65FF73D48B1A8C11ULL, 0x2845CFC4401B54EAULL, 0xAA1BDB1671BA1C8BULL, 
            0xD3E438274A330636ULL, 0x0109522381758201ULL, 0x4DC380134433DEC4ULL, 0x7F90B5DF2FD3401BULL, 
            0x311B06E4C56FB6BBULL, 0x72C5D17374A24137ULL, 0x5FEF1F49ED78628BULL, 0xB280BBC1F715A718ULL, 
            0xCA74EADAEB9E1A63ULL, 0x5642E3819AF7BC1EULL, 0xE0AC27FEC1B87940ULL, 0xFA4DFF128CDE7537ULL
        },
        {
            0xA9DF25D620B22B37ULL, 0xC1A0E50CA2ABE67AULL, 0x263B3D55DBB6CB9CULL, 0x79617A41AA6FD0F0ULL, 
            0x98C1BA32D5125126ULL, 0x38A1843CB848F5AFULL, 0x9AC1034A9D4D769EULL, 0x01880A9067587A30ULL, 
            0x88EB698E35ADD411ULL, 0xF4EF14D7CE8C334FULL, 0x47A145B2968A9187ULL, 0x115F8FF6565F91D4ULL, 
            0xA6CC1C9049D8622EULL, 0x19D7815E4565EE0CULL, 0xE987DDEA31BF47FFULL, 0x3EBB25C02BE4FE2FULL, 
            0xFECF36FA719ECBF9ULL, 0xBDB76AEBC418B388ULL, 0xE28BA603D0C1573AULL, 0xCAA7D02CCFE6D3F2ULL, 
            0x6CCE91FB257FA8B6ULL, 0xA8462D667FB66A9FULL, 0x9673FF75042019E6ULL, 0xB6FD11816ABEB3A0ULL, 
            0xC89865549CD15C15ULL, 0x67AF408281C8BF7FULL, 0xB06FAB651DE5F97AULL, 0xE3A5A3BDCAF1C0BCULL, 
            0x769C69386ADC0DC4ULL, 0xE4A0341C4652EFE6ULL, 0x92B763A03B1BAD96ULL, 0x27AB0E741100D206ULL
        },
        {
            0x7E92780DDC41F5F7ULL, 0xE26AC0AF238ECCDDULL, 0x53349AACC9F14B29ULL, 0xB9391457B3615A75ULL, 
            0xB085744BA8893E68ULL, 0x6717A2996327F95FULL, 0x5D0FB353F4E1DA30ULL, 0xDFAAA76CC7BE133FULL, 
            0x0D63FD69B875018BULL, 0x38CF682A50D6CA4DULL, 0xB2C4F15E01463DD2ULL, 0x12D510B7C9BE9C3EULL, 
            0x116DF4F4B092E119ULL, 0x365D1D6DE9AF912DULL, 0x5366CD0C84BFF29EULL, 0x66337D1C85AD7045ULL, 
            0x8FFDE9BC1B5CC1DCULL, 0xA347F32B9FAF2A79ULL, 0x4F490BE4C20C3BFBULL, 0xBFEF7FB062F455B7ULL, 
            0x411AC760301FFDBAULL, 0x8F581A02B0079CF6ULL, 0xB53D9844754DD1F1ULL, 0xD94A6D0F858BCDE5ULL, 
            0xA6E8FCCEF47F4237ULL, 0x59323C956BB04566ULL, 0xFA53DA3C2081585CULL, 0xA2FF12F6F8ED8970ULL, 
            0x1471E0EDF4720293ULL, 0xD34DE3264E2DAF57ULL, 0xA66E666DD2DB000FULL, 0x8C837F5FCA184C12ULL
        },
        {
            0x7287C64ABEDAED4FULL, 0x2BEF3192AAC6B8B0ULL, 0x1475FCD6C40128EAULL, 0x8E6B562415BA8CA5ULL, 
            0xA01705948C609687ULL, 0xD8342221EF20D469ULL, 0x2EF5AFC88DCD432AULL, 0xAEF9168BD98F8F90ULL, 
            0x942D968C03362389ULL, 0x86E19F504FBA04CCULL, 0xBDFF638327496CCFULL, 0xBC350F347987C3D9ULL, 
            0xD39D45A41C61BA7EULL, 0xD7DBE1684380CC33ULL, 0xDFC3F23A5DDAA7C8ULL, 0x8F97F9FDDE731C38ULL, 
            0xB2B19E7BDFFDB736ULL, 0xE9BDA0B2068DE095ULL, 0x4C8442E1E1B2E153ULL, 0x74470E5AB325E77FULL, 
            0x70D5E7225AAFA735ULL, 0x75569463B58F5377ULL, 0xBAE67575B43F83A0ULL, 0x0E4893BBE216AD35ULL, 
            0x0E57695179502978ULL, 0x2780954589A65782ULL, 0x83FBED3D5C02D087ULL, 0xBB0701A29106D4E4ULL, 
            0xC7498DA02DB57E20ULL, 0x0B1710912C13B42AULL, 0xAE4BD1AC9CFF139BULL, 0xA31C5DD992CF0CB6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Capella::kKeySpawnAConstants = {
    0x5216FB31DF96E0E6ULL,
    0x6CBF985189EAED58ULL,
    0x808A02F0EB3D374CULL,
    0x5216FB31DF96E0E6ULL,
    0x6CBF985189EAED58ULL,
    0x808A02F0EB3D374CULL,
    0x870FB030ACC6B44BULL,
    0xE219EDE7218A1828ULL,
    0x07,
    0x9B,
    0xFC,
    0xA0,
    0x83,
    0xB5,
    0xB8,
    0x6F
};

const TwistDomainSaltSet TwistExpander_Capella::kKeySpawnBSalts = {
    {
        {
            0xA46DB0D830920C9EULL, 0xB738391AD24ADD4CULL, 0x1CB67E2147A5FDEFULL, 0xD2BC08F82F07B67AULL, 
            0xFD99308F9FFB0067ULL, 0xBBF3424D97522325ULL, 0x77ADD939477F7317ULL, 0xE73E314EE8E91C38ULL, 
            0x4071AE4B5DC70E90ULL, 0x66C19A920C36F640ULL, 0xF74FEBB48894A220ULL, 0x12EDB187D9816EE0ULL, 
            0xF4F0D29A82BC40FDULL, 0x19F05E689B732300ULL, 0x70462FEFF9EE19CCULL, 0xC684295309A99A47ULL, 
            0x9285E9051274A2D6ULL, 0x71BEE7468DBE19FEULL, 0x4DA51B33AC3846FCULL, 0x04ABBDDAA5BE0C7EULL, 
            0x654B29C08F2CFA20ULL, 0x7FD559C2140EBCFBULL, 0x2302B6498E4897C8ULL, 0x65F4DC3FF1841888ULL, 
            0x46D296D9C0201625ULL, 0x47A3D8B889992995ULL, 0x8A16CB8623361891ULL, 0x44876DD8410F24B2ULL, 
            0x2E4C2629DB7052E2ULL, 0xED24D521834164F5ULL, 0x683D0E5DDA2EA052ULL, 0x9F8DE3A091407F6FULL
        },
        {
            0x8C01BFBFC281E925ULL, 0x8EA84C86ED3A1220ULL, 0x074E4AF99D751208ULL, 0xB2CF0FB2E8BB8906ULL, 
            0x0AA8FE3D4E41C18CULL, 0xB88DB8833D330B21ULL, 0xD95D815F6C10C6BAULL, 0xBE721A2FC4225572ULL, 
            0x0A8DF4D63DA36456ULL, 0xD3FF2D53487975ACULL, 0x72337D8FEAB313ADULL, 0x9A5B6630609C3F8FULL, 
            0xAC6EEAF26497DA26ULL, 0xA54AFD3EFD36A065ULL, 0xCBE27D0EB2896B86ULL, 0x431BF6479C008AFFULL, 
            0xD524C18388091BAFULL, 0xA27ACCB2B4AA9FA7ULL, 0x31738279087687A9ULL, 0xB51572E7777DFC3FULL, 
            0xB2584975AD33F6DAULL, 0x48E7771AA24679EAULL, 0xBCEBAC9A9BC14448ULL, 0x3651C4A3CEEDCE6FULL, 
            0x3043F1ED274C3D7AULL, 0x87CF67B987ACE31CULL, 0xC3D82FD5E1F8798BULL, 0x1E81D1F31D2D4CE4ULL, 
            0x6275F24AFCC57C6EULL, 0x6335DCEB907F6995ULL, 0x620C08D97F3C2B26ULL, 0xF3B5F00DBD8B1E36ULL
        },
        {
            0xB901A1452B601BD9ULL, 0x2C27A5B1C8F5C184ULL, 0x79535D23553E5C59ULL, 0x407179A0B66C732DULL, 
            0x111D3CE76903D57EULL, 0xE5934785A804D679ULL, 0x377AC0AC26B64D50ULL, 0x9D39F1D7BF2872C3ULL, 
            0xA5E363A64E5E60E4ULL, 0x7F3D9DE590E27E7FULL, 0x844E46CED6C17B72ULL, 0xBDE227BDEE24F866ULL, 
            0xCE631F658B25CAA1ULL, 0x1FDFDDED7F228550ULL, 0xEB20F4A75CEEF635ULL, 0x66C14274BC9D66ABULL, 
            0xB9116BE2D768CE33ULL, 0x156001E7971EEA9FULL, 0x9283D82B6B491BA2ULL, 0x06DC84C5EFACB3DEULL, 
            0x21A7B61861758449ULL, 0x2DBFF3F2A601E488ULL, 0xE9969226353360F6ULL, 0x422A6DE98FA57F35ULL, 
            0x27E36F8933880FA4ULL, 0x6E4C3729B05CFCCBULL, 0x5F3A46E7CF7EAD09ULL, 0x8F348E1CAF4639DBULL, 
            0x7016E7E9E39C38BBULL, 0x45BD80C81D8681BFULL, 0x3FF61ADCC7B5EE59ULL, 0x0F9DE1EBCAC19223ULL
        },
        {
            0xD85AF60D35848712ULL, 0x2759F8808458FCFDULL, 0x59EE65C0E597689AULL, 0x5339B56614F50A5AULL, 
            0xA88E6C8F52BC7D27ULL, 0xAE8AD6B505EE0071ULL, 0x502FC2F698CF55DCULL, 0xBA6A872D3D616816ULL, 
            0x4C7199FAD040464EULL, 0x43D9B491EE7F1D09ULL, 0xC57664040D528645ULL, 0x50F9BDA3705A7BB4ULL, 
            0x92F85871CC2BF46AULL, 0x40DAA11ADFE05B45ULL, 0x3058D1F497FA14ADULL, 0x8FAA0FAE33288704ULL, 
            0x59768A7215CB10B7ULL, 0x61C03B2AFAA955DAULL, 0x0FB6D2A69BCBF902ULL, 0x432EFF7FEFCBC023ULL, 
            0xDA3F222A5128B3FCULL, 0xA3C17C0532B79FA5ULL, 0xCCC00BA94F45EC37ULL, 0x1A9C3A51B04A9931ULL, 
            0x3E963C1F0A575A6DULL, 0x3616F424626F3B32ULL, 0x5B98558CDE89E48CULL, 0xC90031148D9189CCULL, 
            0x6A9F00C5BBF722EEULL, 0x8CE515BBDA0ED090ULL, 0x0F06A544E971EB29ULL, 0xDDFDD94931AC834CULL
        },
        {
            0x7095755CCDD8F728ULL, 0x726AAE8D02F7D8E8ULL, 0xCC528E65C33D51CAULL, 0x4AA0F25BCB185D5BULL, 
            0xF0240B3C30B7015FULL, 0x0D112B17ECCADEC5ULL, 0x05BA3E53D887A45EULL, 0xA01542C2520B324CULL, 
            0x945136D1EB59B7CBULL, 0xEA36DF9AA0CED468ULL, 0x7F4AA2A247B7FB9EULL, 0x63668B80DC8CA636ULL, 
            0xDBAD91F090C0D6F6ULL, 0x03FA67C5E8ECCD5CULL, 0xC2D2F2D0FC64F833ULL, 0x975F4E26946CE768ULL, 
            0x7C146CD01204F2C6ULL, 0xE528966451D5BF2BULL, 0x45FF2D1ACE581489ULL, 0x655EA583CFC91851ULL, 
            0x47D5CB7268590D49ULL, 0xA94F54FDDB29E123ULL, 0x1C4F661BA8271E87ULL, 0x3B44D3132505B822ULL, 
            0xB0640C90978D4C6CULL, 0xCE6C1DCD7A9348B1ULL, 0xBA452902E6A00BE6ULL, 0x6B94D52F4BAFC077ULL, 
            0x51B2FA5E37A0AB40ULL, 0x0291FF395E619AA0ULL, 0x6B2DA8B385FB2D48ULL, 0x16DC93CCBD2AF264ULL
        },
        {
            0x5F41BDB989D4011AULL, 0x82A6C0118872CF5EULL, 0x1E20E42E80CE7517ULL, 0x3D30A4B6D1558E28ULL, 
            0xE5A73B5BB099283DULL, 0xE81FB8CA4A4E4127ULL, 0xC75818C8C916AC8BULL, 0x0A04391063B4B4F0ULL, 
            0xB1BB661F2EBA7E4BULL, 0xA1193D98B7A19D80ULL, 0x27BC696622AE192BULL, 0x2BFB3ADD3046E650ULL, 
            0x253A6B7CBF1A4B82ULL, 0xA721D1EF51235B63ULL, 0x7AA04B8DA5D5AA54ULL, 0x82EE5CFFDB82D6AFULL, 
            0x14E4A2649CA6BBF7ULL, 0xC573C5A8C04E5CE7ULL, 0x2B61B12CDBDBF169ULL, 0x81E97C70A12739C7ULL, 
            0xDB601987F1C9DFE2ULL, 0x37846267B3C6F55FULL, 0x1A76A928A287B9FBULL, 0x989884975D0BC9EFULL, 
            0x431D26031C169292ULL, 0xDFBE1DE5DBF0DEBCULL, 0xC05D4D1D8CC5A9D5ULL, 0x75749B0123F87AB8ULL, 
            0xFB3FDC0995F59925ULL, 0x5A6B97CF539E448FULL, 0xFA19602BEB69E98AULL, 0x5CBDAE71D30FE87BULL
        }
    },
    {
        {
            0xE508CD306F405116ULL, 0xA389352F7A985792ULL, 0xF8C6E2FC38844A46ULL, 0xB1BB7ABA5C9062E9ULL, 
            0xFF230EF58D1C3ABEULL, 0x78CEFC9808543084ULL, 0x1755D6D9D71E2BD0ULL, 0x8A70317CC2DE2EE9ULL, 
            0xDF0FE72DCB3EE452ULL, 0xE8DB0773BDF4F661ULL, 0xFDF23D2300019D96ULL, 0x272E624AE456BAB9ULL, 
            0x3C45079D5D7777DDULL, 0xA9EB1455AB2BE8CCULL, 0x7F8142EA0F574E84ULL, 0x0EDF16D8174B77ADULL, 
            0x89AF305B8D233B08ULL, 0xB4AE17CAF8B4B893ULL, 0x46C92C0EA64BB2B0ULL, 0xE3A2EE3C4211E0BFULL, 
            0x5C94CDA200AB394EULL, 0xF501451DE9B583ADULL, 0xE056E8C826B09C5CULL, 0x5BF88A7F8546F669ULL, 
            0xA4BBC3BAD9C5CAFCULL, 0x8654801554B684EFULL, 0xC797E0096E76EEDFULL, 0x25E3DE3ADE07AF2DULL, 
            0x40E09F3836C1266BULL, 0x4449E01DA70A8C72ULL, 0x8142270730C9947FULL, 0x44757E9CCD24B5C8ULL
        },
        {
            0x98CD834E189DC72BULL, 0x03062550347B49F1ULL, 0x243F2DFE240C8BF9ULL, 0xE6C01570FB989B50ULL, 
            0x5B059AD39ED9AD97ULL, 0xF6F2ECD90AE7FD1EULL, 0x6F4B9771681D6365ULL, 0xCC2144F5D1716527ULL, 
            0x0C7788001A10B8C7ULL, 0xC7CF5F1102DD1610ULL, 0x4B349C57CA75C32AULL, 0xCB8A70A66F5DEF32ULL, 
            0xEAF2AE972ED69F4EULL, 0x0987E90BC95DB002ULL, 0x98B871EC761AC680ULL, 0xF99F87E1F91972ADULL, 
            0xC4D94F98B124E807ULL, 0xF3DEECB0CCDE5BDAULL, 0x1E924A119CA2F46CULL, 0xE52F41B4185E05C7ULL, 
            0xF724F676B4C0DAA2ULL, 0x37B539F851AD997EULL, 0x6D618857DBC3B996ULL, 0xEB4F4A81DB083AF5ULL, 
            0x1083FDFE8A1C43B5ULL, 0x4334CBE9173D6932ULL, 0xB3565C6241FA6927ULL, 0xBEDF5B400218E106ULL, 
            0xE0C14CF1C8DA478BULL, 0x2F5AF4080CFD5625ULL, 0xE4FBCF1642342F3FULL, 0xF9821FAA2A2CB698ULL
        },
        {
            0xFF2ACE621124F9E6ULL, 0xA377B9B589542AD0ULL, 0xC26D095C85A62F8EULL, 0xD2BAC345C09B2B2CULL, 
            0x5D41DCBAD52F2111ULL, 0x668541D5BA10E457ULL, 0x35CEE5CF954EA3BEULL, 0xD4F86F7FD97F9B8EULL, 
            0xEA660EA71C5283D2ULL, 0x5BFCECB4569CFC80ULL, 0x31CDEBE2499C8D5AULL, 0x33C6BFBE36B9AFE8ULL, 
            0x51966144A867B4DAULL, 0x60F81D0E8BEBFDB6ULL, 0xE6F4D66558537AADULL, 0x761FF9ED0D75F60BULL, 
            0xB55EFEA1CABDCC31ULL, 0xCDDEA9F284837C73ULL, 0x610039DC4E1E0DC2ULL, 0xACEC025CFEAE6BA9ULL, 
            0x660AEBFF6DBF3077ULL, 0x4B015C72E0302101ULL, 0x8D6F7061E0F442DCULL, 0x2DDDE448A3FCC98CULL, 
            0x7F4D119808D18030ULL, 0xE385BB699BA017BEULL, 0x9A2E80DF487A0269ULL, 0xA5799902C5577DA3ULL, 
            0xA2766CD31A6782D8ULL, 0xC54A2CB91890648BULL, 0xC0BA9FF43BF1C6B8ULL, 0x07DCDED80E10657DULL
        },
        {
            0xD69A25B510D34E02ULL, 0xF8B0A2E762B764CAULL, 0xBE8195961666500EULL, 0xCC8B570FAB38AA42ULL, 
            0x6778A3A390E63E4EULL, 0x71B7E8BBA8E9EAE5ULL, 0x881FCA50FF3234FAULL, 0x19737F9FF4390F90ULL, 
            0x75E19C0B23BD0F8CULL, 0x1389D1A9B9F419D9ULL, 0x4456FB017D32DD11ULL, 0xDE7ED284A286FE19ULL, 
            0xE18C326FF34C06FAULL, 0xD13F74CFE201BACDULL, 0x3CFD51548053E2DAULL, 0x0A3AC9B22C63687FULL, 
            0x30FAB198DA8FF9C8ULL, 0x28B8E28D064D7509ULL, 0xAB7228A59A5E7C01ULL, 0x8BC0F7F41E3DB1F5ULL, 
            0xA73A09645F1F4D3EULL, 0x51704496FFB74060ULL, 0x2848F7086F9CA4B6ULL, 0x989CB8C69D97B946ULL, 
            0x2997A4786B5DD735ULL, 0x26B61B229E8ED34DULL, 0x6ADE66B1AEAA5DB9ULL, 0x074BDC3BCE7D7BCFULL, 
            0x9723D232CD1AC19CULL, 0x0E5CE28E16E6271FULL, 0x45CD28B8C34B4A81ULL, 0xD7FED124F7308682ULL
        },
        {
            0x9ADB2241A79D06C5ULL, 0x754546EDDC804949ULL, 0x16E493E6CE0BF83AULL, 0x42C62C969E72206FULL, 
            0x159073C5D8E29538ULL, 0x9955DCF673712EE3ULL, 0xEC7C611B1E587599ULL, 0xF97E90A1D4354A6BULL, 
            0xD7DE13A80AD6AFC5ULL, 0xDDB308B09F9CBB66ULL, 0x09B8A47C14FB511BULL, 0xAC9066B1BED55DAFULL, 
            0xA6B10990244BD302ULL, 0x1C6FD1AD3FD0720DULL, 0x17937B925467DC3CULL, 0x15CDFECA1136A56FULL, 
            0x06B8FF2D4074EFE2ULL, 0x30046130907CF764ULL, 0x1215E274CC692730ULL, 0xCAB11ACCFE03BCD7ULL, 
            0x9CAA9A72CB5CC641ULL, 0x43BD8746BE7B3D10ULL, 0x9406A81AF95DE6A9ULL, 0x1F1824B0C369F0D7ULL, 
            0x8115A925F4B41556ULL, 0x3F6223465E2B3536ULL, 0x1595B0D1DE8CBC2DULL, 0x2D60C8CBAF0F64B3ULL, 
            0x80020DEB66C14868ULL, 0x558FC022D4238F60ULL, 0x5C2C845101B861BFULL, 0x2587ADA3AC1E3AE1ULL
        },
        {
            0x3797242B4CA29542ULL, 0x2D08EDD4AB92A7CAULL, 0xE9123225943571C1ULL, 0xC19B271BEE5E15AFULL, 
            0x092124119D409BC8ULL, 0x4E12C31B76AAED6FULL, 0xB3717B511B8181EAULL, 0x231E88566FE6D1DEULL, 
            0x4D7AD32673E12ACAULL, 0x3918A6540DB6A8E7ULL, 0xBFF7883B38A6509FULL, 0xBB7A517D155833FDULL, 
            0x8F194244C84CF6AFULL, 0xDB159904C110ED35ULL, 0x5DE91707F6512C15ULL, 0xF8162548F92C1456ULL, 
            0xAF0A43E53B87B9DAULL, 0xEFC29A9435005EEBULL, 0xCCA60CE1F387D0A4ULL, 0xEC8C276D3C3CE577ULL, 
            0x6E811747F9AFC713ULL, 0x9A1F462418D3A075ULL, 0x0CB5D8E199C9F63FULL, 0xE7689507DE72BF98ULL, 
            0xECB5AD772C2C35FCULL, 0xD1FC0CCB2A4E5F26ULL, 0xA1D5539260356639ULL, 0x11F533DEB612D8B0ULL, 
            0x595876A920DD7090ULL, 0xED8D33CA324437C0ULL, 0x83230D5528A53113ULL, 0x6EE2F9772BB002FBULL
        }
    },
    {
        {
            0xA1397F398BDECF3EULL, 0xC42B07D696CE2DD9ULL, 0xB463090D1BD76992ULL, 0x3668E8631CA15D5DULL, 
            0xFA39E1CAA67BCC42ULL, 0x352A9B611A66EA64ULL, 0x528796492C80FE1FULL, 0xC1B1F042EE22E6DBULL, 
            0xD3B3DE4E9CDA7113ULL, 0x396F7178EAFDED34ULL, 0xD07936244C9859B5ULL, 0xBE0539C2714FCD88ULL, 
            0xFE0F7FB00116BA7DULL, 0xFEC2B188F8E941D9ULL, 0x5BD6744F55860E58ULL, 0x3AAF803559C69849ULL, 
            0xAD596C837E118497ULL, 0xD9FE655D75AFC404ULL, 0x29F2A6DF6C4AA0ABULL, 0x95A3AB3CD58C5811ULL, 
            0xAF8C0D1F36AA5479ULL, 0x8AB9C2FC0DEBFF42ULL, 0x3D5FD581B3D08BE5ULL, 0x06802A029A2E39BFULL, 
            0xF44122393222BF03ULL, 0xC12997AF468322A2ULL, 0x6F721F30600A0787ULL, 0x1D544D9E90AFE652ULL, 
            0x85F498AB799A3B36ULL, 0x787009CEB50CE47DULL, 0xA1104563F44A55A2ULL, 0xB9064C5FFD78CFF6ULL
        },
        {
            0x741C2903B8CD08D4ULL, 0x07F5D3439E7B86C8ULL, 0x7504E6D6AF3F1E8FULL, 0x0EE6E99AC6772312ULL, 
            0xCB820F255F18F8D7ULL, 0xC2FA02D7A41F7395ULL, 0x0168ED5DCB1F8ACEULL, 0x2E52B0C8C7282EE1ULL, 
            0xFDADF2852166B5B2ULL, 0x42E67B26A555C5F3ULL, 0x49847F87EE4E87EAULL, 0xB2D6067BF45C113FULL, 
            0x8B4A49021C4DF2C0ULL, 0x9DFC26FEBA7B68FFULL, 0xD7605588A571123CULL, 0x14EA1B15E6F66565ULL, 
            0xB10A157E8A07D0B4ULL, 0xCAFB274FA49287A9ULL, 0x22C68C7B99F8C372ULL, 0x8114D1B58855D671ULL, 
            0x24DF861A7C2F4D0CULL, 0xEE5500C68BE758B3ULL, 0x9390B68D8FD97AB4ULL, 0x9320EFD471B56BABULL, 
            0x8386EEAF0BB07C02ULL, 0x3775297CC86F1430ULL, 0x5CF8FB92F31097FFULL, 0x700DD24DF231DA65ULL, 
            0xB967B220921D558FULL, 0x7EF36F61C10E13D0ULL, 0x0DD032E0FFC17FDBULL, 0x33F6FDBB1DD35094ULL
        },
        {
            0x3B34651C1085653FULL, 0x445283F43C9E865CULL, 0xE280D3ABEDAAD918ULL, 0x8DD748964A487199ULL, 
            0x08FD20875AFC2586ULL, 0x9AB05FB1024B7274ULL, 0x2282A6418499FB89ULL, 0xCB33D79EBDF04AD1ULL, 
            0xD70BF443C533AEC1ULL, 0x028AE875B47476DAULL, 0x3482B846B03BED3DULL, 0x69CEF472006EE600ULL, 
            0xD0D7C4AD1388AEAFULL, 0x7ED731E71E56BDFEULL, 0xE7654C9677F21882ULL, 0x53DBCF78436EBB85ULL, 
            0x3A8C225E7509E8A8ULL, 0x4EBA3A9CFED7258EULL, 0x3DBE026AC051C528ULL, 0x41E48041AD2F5BF4ULL, 
            0xE3F37DBDE7F6379FULL, 0x333C2C7BF20BB115ULL, 0x24E3A01105E620AEULL, 0xFF7F37DFEBD6F48AULL, 
            0xBF1AB26F315ED813ULL, 0x9ABF5A959F5DA857ULL, 0x5A55828D6D4AFAADULL, 0x129A3A22A8A325B9ULL, 
            0x591FC9B592CBEC7EULL, 0x8EDBE36275E4B9AEULL, 0xC05E6139DF73B325ULL, 0xD5BAC5816EE41BEAULL
        },
        {
            0xC06FB4DA60F278B8ULL, 0xD164FD2548AD6C10ULL, 0x8FC9D3AC93490652ULL, 0x2D5548978322260CULL, 
            0x7665FC988C4467AEULL, 0xF2166CE6ABDC1E77ULL, 0xF67425E8406DCF89ULL, 0x3BBD1D0B5A1F3309ULL, 
            0x4CD7F1FBFFBEC2CBULL, 0xC2D790AEB05CB406ULL, 0x195B01B98A04A786ULL, 0x665B5FBFCF91352BULL, 
            0x58E79312F910CCE3ULL, 0x5CA920FEC2C424C8ULL, 0x8A1A3C62204C5A7AULL, 0x79A7DC7BD8CB513FULL, 
            0x535583B6DC0DED99ULL, 0xA3E83B5413697D45ULL, 0xAC4C96A47DE87AC6ULL, 0xAB919DD0E5FE19D9ULL, 
            0x97797EE0B22B4C00ULL, 0x87CBC934CE7E977EULL, 0x2C5C210598D786F5ULL, 0x01260A324D8FE63BULL, 
            0x5EA9FF9D6A91A542ULL, 0x6485061A491AD35FULL, 0x49A01CB544DA1AA0ULL, 0x7A6F0168A087671DULL, 
            0x84E62CF6AA82AF9AULL, 0x6C035C238D1A3DA2ULL, 0x979C2DA4AE6AAAA1ULL, 0x857C7B484674422BULL
        },
        {
            0x604A02CBE8F841E3ULL, 0x69A164116C94F804ULL, 0xFA6C021E184B5328ULL, 0xD2D8C6FF937D61D5ULL, 
            0xAE767B8400222175ULL, 0x01100C25B644B9A7ULL, 0xFD1AE07DF3D26AA4ULL, 0x88089E66E9BE23F0ULL, 
            0xFBA43F23A0E87531ULL, 0xE3B45762F0C825ABULL, 0xBF9577E21F1AAAC3ULL, 0xDEAD678275F7007DULL, 
            0xA9FDB2A1E599BEBDULL, 0x326EA1CDD1520BF7ULL, 0x027E4AC20E9526A3ULL, 0x54CE24996154617CULL, 
            0xC7B8DC1547B04A78ULL, 0x3B9A8EC228388CE2ULL, 0x8C979DA955EDD55BULL, 0x3522BB148C527DD7ULL, 
            0x6C589FF657F1A997ULL, 0x3260B1432BB98753ULL, 0x06A7DE4DE104DE0DULL, 0x7911377C71848E23ULL, 
            0x537220542C3AE5C4ULL, 0x4342BF4C10D421DCULL, 0xA4F02A7AC94E2FD2ULL, 0x3515C65B4AEA0876ULL, 
            0x2BDB254827B346CCULL, 0x9951C7A02F665518ULL, 0x5CD589B47DBCF800ULL, 0xFCCA9296F041803EULL
        },
        {
            0x2B6EBD02D7D9B067ULL, 0xA75EBF6318754E86ULL, 0xD1B4FE9F523BED9EULL, 0x62F4BA63CA81853CULL, 
            0xC935B74F1704FF2AULL, 0x154C180B0665FC50ULL, 0x12A06772A0219192ULL, 0x5B7E1F4F3AF49FA3ULL, 
            0x2EC57E51AB7D2B85ULL, 0xEEEC97D6E0F11F47ULL, 0x71D7340DF1BBB230ULL, 0xBDAEEED2FE314B57ULL, 
            0x7455630BB5BC2D19ULL, 0x09CF7AF34FA30593ULL, 0x1906227AE9E4E60DULL, 0x927087C6A9E5EC5FULL, 
            0x3F8AEB16348DE2DFULL, 0xF3F7F2B8EB85E295ULL, 0xF3C28FD6A4AB343AULL, 0xBFDE02C4393FB650ULL, 
            0x5AC2A3EC96654240ULL, 0x557A84B61A578114ULL, 0x456C3E6182D2ED5DULL, 0x1B5F00E97CF98102ULL, 
            0xC53CAE63803D9AE0ULL, 0xFCE9BB713D8187CEULL, 0x924D5D2D8BFF26D7ULL, 0x68FB2A3247801D50ULL, 
            0xD9BEECBBA74F3F9CULL, 0x5CF236165415592FULL, 0x59883A82D342208DULL, 0x151E98330E96FC0BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Capella::kKeySpawnBConstants = {
    0xE1D6E44BBBFB698AULL,
    0xBE69FE59F8F6DBEDULL,
    0x3264C34076513C4CULL,
    0xE1D6E44BBBFB698AULL,
    0xBE69FE59F8F6DBEDULL,
    0x3264C34076513C4CULL,
    0xF8F3699B29C2C0EDULL,
    0x164E3EE4F63DCB5CULL,
    0x65,
    0x65,
    0xB8,
    0xC5,
    0x13,
    0xDB,
    0x97,
    0x20
};

const TwistDomainSaltSet TwistExpander_Capella::kSeedSalts = {
    {
        {
            0x5FA9FE9230260D1EULL, 0x505CC89D9E90A30FULL, 0x21A8AD4BA4E7B73DULL, 0x4F6D1F90F1875935ULL, 
            0x8205429199BBD93FULL, 0xEBFD07FBFDBC65FAULL, 0x9E0C617A96ADFF9AULL, 0x10945D6B244C5074ULL, 
            0x358F7209F815B92EULL, 0x10E9FA4B087644D9ULL, 0x82BA20357B559DE7ULL, 0xA4330F6E08133C61ULL, 
            0xDBEEE152715077F5ULL, 0x736C95C4FDDAFAA5ULL, 0xA79461AA5565C24EULL, 0x4E57D2B39CB4E756ULL, 
            0xE7F1F821718B088FULL, 0x565C24C4D28ACDE5ULL, 0x737C50D8E526B177ULL, 0x4250316F0796FA29ULL, 
            0x879B7BAAAE1D6462ULL, 0xCEAAF5B55AB4A49FULL, 0x6297549CD32EECD3ULL, 0x5F0BB3DC71BD148AULL, 
            0xBB294BD6469E36DAULL, 0x477B542003A63967ULL, 0x174BCF2C720DBCDCULL, 0xB7AE79F4BD635B88ULL, 
            0xB36F7BAAB787C4F6ULL, 0x9CFD786F71452045ULL, 0x7903DE55F1FC528EULL, 0x7C34ECDDE29942A7ULL
        },
        {
            0x043B82BAA5CE7D8BULL, 0x07888F4F5E6CE020ULL, 0x19F925B62EDA0F5AULL, 0xA48918B885DDDBE8ULL, 
            0x5EDF69DDCF22A133ULL, 0x5690B2C101EB69C1ULL, 0x2A3B76880EE99887ULL, 0x3F833ADD0F56B451ULL, 
            0x6CD02AACB502528FULL, 0x9E3E3F7CDE09DAB6ULL, 0x83F1CF178D47F9F7ULL, 0x2A431083B0AE1B4CULL, 
            0xF5D54BC84777AF3FULL, 0x14F119677A07E127ULL, 0xF001B8B8C4687A34ULL, 0x5D5DE937A116DB1CULL, 
            0x21184C55A3C7201FULL, 0xC8CEF1D63A2C8513ULL, 0x891E20055C849EC6ULL, 0x0CA26C253D8D7806ULL, 
            0x199D482E7DF74203ULL, 0x71D977BDB36C27B3ULL, 0xC2C33926F8763C7DULL, 0x0D21B3401E4BC0A6ULL, 
            0x1CBA4145500510DFULL, 0xFA78EBC3CF2C661AULL, 0x1175B1B8704CA529ULL, 0xD48671B855D71D66ULL, 
            0xF7441524F540AE4DULL, 0x04CFE8485061BB2DULL, 0xEB29B65B0D070E38ULL, 0xD739D5A5A329FE90ULL
        },
        {
            0xFE5F228773F3BB97ULL, 0xE1D7899015B1A0A3ULL, 0x25099DD3468528C4ULL, 0x0FF9A752BD680256ULL, 
            0xAAFFDE5342F2D7F2ULL, 0x7F0FD2A661A9436EULL, 0x189031EDAACA4D69ULL, 0x8D9199C5C84E79AFULL, 
            0xE4ADFE7ADD1958EEULL, 0x38E6622A47AC0F64ULL, 0xA0DE532D4A6920C5ULL, 0x94A19EA76245D8D7ULL, 
            0x7C83A5A08193E3A1ULL, 0x22BF1B241FB3DE12ULL, 0xD3B7478CA5F47352ULL, 0x0C9FA8931E814D97ULL, 
            0xD2167AA5578F49A5ULL, 0xFA71DB1842FBAC73ULL, 0xF8DF634AD3B7F9F3ULL, 0x9A21FE3A908C477DULL, 
            0x75E66DFA7024F47EULL, 0xD1F556CBF921AC85ULL, 0xC46042E6C469A462ULL, 0x55A7959B1D72125BULL, 
            0xB66FD058AC335B17ULL, 0x3E14111ACE1ECAF6ULL, 0x311F93FEEC650D4EULL, 0x38BBF0BABC89E5EDULL, 
            0xE3428C7083DE27C7ULL, 0xDCB3043AC0E6D48FULL, 0xAD79424BF3B798D2ULL, 0xF2BE3F48B606B8F7ULL
        },
        {
            0x2C3FD53923AEC14EULL, 0xD338AF4FB9DE3AF4ULL, 0xC4C7AFDA8AE45610ULL, 0x2DE1BD4A578B2860ULL, 
            0xA35F0FB386ED90F7ULL, 0xD57D6C990CD805EFULL, 0xE8FD77C10E492964ULL, 0xA62E7AE5F9DB7A89ULL, 
            0xAB594C5F42005792ULL, 0xED654B38F001C8AEULL, 0xA27697B26EECC033ULL, 0xB99479DE754E16ADULL, 
            0xA1568E6282914F79ULL, 0x259363410C5C58B2ULL, 0xF68ECD0C9108C0DDULL, 0x33EA6ED0452E7ECBULL, 
            0x4578F6648A797482ULL, 0xB0CF010F5ED64B7CULL, 0x97813D7F729D377BULL, 0x4063AC59A2D7D74EULL, 
            0xCFF4BE31FAA6902CULL, 0xE4CF01FE0F6E0A11ULL, 0x85DABD63DFAA60ABULL, 0xD26E9ACD7361464CULL, 
            0x3CE22F3B0811B161ULL, 0x17462721A103299EULL, 0x36127F72E4BFA2C0ULL, 0x1A1413883019FA75ULL, 
            0x3F5D23DFF6F13481ULL, 0xEAE818BABCAE2C68ULL, 0x5D41FCDEE71608CEULL, 0xA0528A61B76ED2FAULL
        },
        {
            0xAB377E2D18A8DF51ULL, 0xBB78C1575BB77068ULL, 0x5FE9B87B7F3CD242ULL, 0x32A1D97304177E84ULL, 
            0xDE924D94BA9CCFDFULL, 0xEFC9B04DA1F7A6D1ULL, 0xF03B25293BF48E9DULL, 0x867497A0F1424212ULL, 
            0x61A2124CFF514A0CULL, 0x19F00368C30715DFULL, 0x67976209C666C97AULL, 0xADF5A5AFBDC1C36DULL, 
            0x028B90EAD03EBEA2ULL, 0xD528B1ACB30BA167ULL, 0x746FE968472084BDULL, 0x3503DC316C8F07FEULL, 
            0x8CD8B17786DF4930ULL, 0x5A2BAF4688E59587ULL, 0xF8E8327F35F6C149ULL, 0xB2E84B74F94727ECULL, 
            0x62DF1B3F16B35BABULL, 0xC5141497B82010E2ULL, 0xC47CDAFED8764DFDULL, 0xE63524D07067A99AULL, 
            0x61E616A1CCF6AD38ULL, 0x61E2033DC880D03DULL, 0x8DA2877D947FC532ULL, 0x8618C96F980692A5ULL, 
            0x5AC01469615F54C2ULL, 0x520D236329A5A290ULL, 0xC43008BB7B02E572ULL, 0x8624C9E9A7D09C52ULL
        },
        {
            0x6128448B61449812ULL, 0xF022AFA6B3205F8EULL, 0xA7041A54FD15EA68ULL, 0x2F777E8C8FE3C6DDULL, 
            0x219EFC3BCA79659CULL, 0xFC76B60655FC8E23ULL, 0x8335745291B00DDBULL, 0x30EE07D6715C05A5ULL, 
            0x1E658A116F745978ULL, 0x133A973CCE2267B9ULL, 0x2743B195DCD5AD05ULL, 0xC838FDEC25FD7A4DULL, 
            0x370BF2529C58D98FULL, 0x7B67BA0281718020ULL, 0x21A589BA1D7B4435ULL, 0x730B93E6123017F8ULL, 
            0xBC0401384C37B2D9ULL, 0x6C2E39B0F037FB81ULL, 0x261F65B34D9FDE5BULL, 0xCE15F45000A6FAE4ULL, 
            0x54C8646957146EC3ULL, 0x6386FB9BE9E5B05AULL, 0x2184788209E5464AULL, 0x8CF50DE00DCD6ECFULL, 
            0x148144072DE209C6ULL, 0xE58F00958C8E0046ULL, 0x78FDC45F919CF458ULL, 0x9CAB1C45587D5FC3ULL, 
            0x7940567809FCAFC8ULL, 0xCE8BD6BB6ABCA998ULL, 0xA464CD386CFCD84AULL, 0xCE4AD26E701CEA0CULL
        }
    },
    {
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
            0xEAE4C030B2C4D692ULL, 0x0DDD34C43C01B986ULL, 0xA1613C28327ADBC0ULL, 0xF25000BB68736131ULL, 
            0xC831412087AFE82DULL, 0x28EB219D9877EF85ULL, 0xDBAFF0BCE95C7447ULL, 0x01B450302E31AE9FULL, 
            0xFF7D70A17A81206DULL, 0xDBD09E169F81CBB6ULL, 0x66E8113C792DE078ULL, 0xDF84BC54F0E75839ULL, 
            0x9AB3C189424564CFULL, 0x460492EC70BA0919ULL, 0x18CA2787BBC4ED16ULL, 0xB317C75EB9657AD8ULL, 
            0x46A7CDDAD1E91CCDULL, 0x90AC96B8C39E66E4ULL, 0x0C683743D20B696DULL, 0x8F7CDCED6EE63059ULL, 
            0x3B371BB353B8F0BCULL, 0x96BD8776C7E7B201ULL, 0x673AB8D112C352D2ULL, 0x1CA592191310A21AULL, 
            0xB14B8C7C7935A145ULL, 0xAAF720C920EDF6A8ULL, 0xCD00B32F029573C8ULL, 0x5B509668276D2429ULL, 
            0x667904F866AB68CBULL, 0xE5A420DF1E09C089ULL, 0xA43942CEFF5BB7F6ULL, 0x17A233972C814C3AULL
        },
        {
            0xEF2DB001A3EAC75FULL, 0xA913DDAB33281CE2ULL, 0x7E565FB57C010AD5ULL, 0xB56AE01F906DCC3FULL, 
            0x5F1B7D2DF9C83120ULL, 0x177E8DB051BCF333ULL, 0xF51627DF54EDD5EDULL, 0x264A28D95BB47537ULL, 
            0x45AEE925F98FD052ULL, 0xE70F06347FB3BB5FULL, 0x179084AAADF15C00ULL, 0x0EA0C31FEA658501ULL, 
            0x6726CA08321F254CULL, 0x765CDF281AC84C1AULL, 0x70E5937651BB97F0ULL, 0x28528599D734CE05ULL, 
            0x7EE562914B8660BDULL, 0x79DF8F9E52160F6BULL, 0xA7A0D2F44C6AC1C6ULL, 0x7F488C3DF9B1BDFBULL, 
            0xA73AD4D66EEF9568ULL, 0x2B5F7507FA0DC01FULL, 0x13B213C5DB1C1709ULL, 0x687C5CBCF447F8F1ULL, 
            0xDAB4FE7C43BE4E88ULL, 0x370E6AB6A74B7448ULL, 0x30B97A3568F74927ULL, 0x3DF18A0030D0D1ACULL, 
            0xF03113F4DC6BEF8AULL, 0x3C71FD21CBBE874BULL, 0x123C664473B3DD53ULL, 0xF73356428FECC300ULL
        },
        {
            0xB3BBA87AAB5D4497ULL, 0xB193F0546F4A5675ULL, 0x9B2C43D3F9DBB8F3ULL, 0x67BE66D3855905D2ULL, 
            0x58A0F564C3E01B3CULL, 0x3B88038F9E72465AULL, 0x344B110ECA1D0072ULL, 0x37873DC53276E1D3ULL, 
            0x521D542FA4E47B8FULL, 0x35A786D77521D65AULL, 0x82F283A43429639CULL, 0x6039039CD75F3C74ULL, 
            0x2FE32AC3E5705E69ULL, 0x6B119162BC9AC32EULL, 0x53356BE40BFD2217ULL, 0xFCAD613F8E915784ULL, 
            0xA8216DA0E3EC1C6DULL, 0x253BEA6A6B3E13CBULL, 0xBCA659B4361F5498ULL, 0x92082C285E8CD273ULL, 
            0xC5C711906E875E47ULL, 0x4097ED679E7797C4ULL, 0x2E042262CFCA5CF4ULL, 0x2DF8A79373A06A6DULL, 
            0xBDA2D0E8FE8A0F47ULL, 0xE7A7C51240753B2BULL, 0xF039D9244A65F32FULL, 0xBB7988960E0AF8F3ULL, 
            0x06BC777657B03C01ULL, 0x12137E62CCE10547ULL, 0xD8CC72A2F34D0679ULL, 0x0222F6C199B9C8C1ULL
        },
        {
            0x3CDA115F98612D0CULL, 0x357AD1C0B9BD672CULL, 0x7D838EA7FBC03CEBULL, 0xD7A3F02F0363B186ULL, 
            0xC62DFA68395C3DE0ULL, 0xE754517AB12D813FULL, 0x7D051204287F8D44ULL, 0x272816E3E16750A7ULL, 
            0xB0DA36823C7040B0ULL, 0xEED0CBE2C8A04E65ULL, 0x5E2A0AAD90B2A22AULL, 0x95166016DBBBEED5ULL, 
            0x6C66FD7BCCC02702ULL, 0x225571E42AB45DA1ULL, 0x1A1626DF27B21DF6ULL, 0xE86425389D9EA514ULL, 
            0xDDF25B3F6C3A0FB6ULL, 0xC2AAFC660EE672B8ULL, 0x85D322691F73B2D0ULL, 0xE2FE452DCF124197ULL, 
            0x70BD0D660B7823C5ULL, 0x33E87FD51647CE7AULL, 0x373BEDC2493A0841ULL, 0x149B2A23074B3471ULL, 
            0x9382D1F87A402362ULL, 0xBE862ECFF110E5BBULL, 0xEDE87BAE6DD23CA4ULL, 0x522FF9F4C2F4CBAAULL, 
            0x784F8D3BC21972B9ULL, 0xB29A54824D405CE1ULL, 0x431B8E4DE6381E65ULL, 0x36CCEF47E5BD6E09ULL
        },
        {
            0xAD71A47E7B90B08DULL, 0x447FE6693FCFFA06ULL, 0xEF5DD935588F649BULL, 0x16AAC9F773A3E256ULL, 
            0xCF7FEB6AD7BC3830ULL, 0xF31585FAFCCEF8D7ULL, 0xF447C507FE02F8EDULL, 0x33640383DBC4C4C7ULL, 
            0xDDD3E06BE06FE81FULL, 0x0F634417CCB7932BULL, 0x90460267BDBDC27AULL, 0xBF886DB736CAA453ULL, 
            0xE69DFB739B60EF81ULL, 0x5A4F67EB4CC5A5F6ULL, 0x6CDACC869C8F8C2BULL, 0x03B26F68E20FC5F8ULL, 
            0xAB735EC15E8FB1A6ULL, 0xFF0C10FBBBB523F0ULL, 0x57CA938AD9F8D91CULL, 0xA35781593AF07534ULL, 
            0xCFA182974C02A81BULL, 0xD8112159885A6C3DULL, 0x7CA9CC5C065C2BBEULL, 0x1A8A3DC29D8EACB7ULL, 
            0x3D4FEBF17F6F145FULL, 0xE09449B54FD05409ULL, 0xF4EE3BC6D6BDB87FULL, 0x5585EEEC3AE2312FULL, 
            0xFBA9D9D8E97B15A5ULL, 0xB7ABF73A21DA8406ULL, 0xDC7E8FDC3952CBF8ULL, 0xAA1C4D2037422D13ULL
        }
    },
    {
        {
            0x8F56B0BF4206095BULL, 0x94DBC4D34CE25CE9ULL, 0x186AAA15E79AD334ULL, 0xF2F0A3FBA9C1E6B3ULL, 
            0x13D8E34499D3E139ULL, 0xC9C61BC22A75CFAFULL, 0x555378FA2C5280D4ULL, 0xFEE41265EBEE5A11ULL, 
            0xC31E4DC578E0D672ULL, 0xF9FDF8E55FA04BFDULL, 0xEED5038D6EE03E0FULL, 0x86BA6CE8837A428AULL, 
            0xF3814BFA418EAE81ULL, 0x857C36D41565E995ULL, 0x8403642FFA527EF6ULL, 0x934FC65F8D38649AULL, 
            0x27F172693DD86DFEULL, 0xEDEB5C34001A50D2ULL, 0x20739980EE86BEE5ULL, 0x2C6E1E8C47347914ULL, 
            0x47C7ECFB8A8A939CULL, 0x97A64E5272200F20ULL, 0xCF3BE581895D7C9CULL, 0x1A843FE5E4AD301BULL, 
            0x8C44727BA5DACF91ULL, 0x50661428E36D2308ULL, 0xA42374F7D9EE38EBULL, 0xF16E33B17A3F6A27ULL, 
            0x7C06FA38F52B8E11ULL, 0x2F7DE8AD35098AA9ULL, 0xB553C7B53D073755ULL, 0x106752E8FFC5FD40ULL
        },
        {
            0x5A82E9C52BF0125CULL, 0xEFC6C71735141B45ULL, 0x6BE0D397C78B35D9ULL, 0x12255ABEF0996C67ULL, 
            0x582C6E3E424DFFEFULL, 0xCDC5B05814D2A941ULL, 0xE21F9E36D8270EFAULL, 0xD8B604D1A89926A6ULL, 
            0xCDA843BC5C4656A0ULL, 0x6DFF2A6217DB2C2EULL, 0xF47AD97FAB367273ULL, 0x6F16C42E0E14CF66ULL, 
            0xD761921B0D9ADF50ULL, 0x5B90558A8FABECE2ULL, 0xE2F54AA52421A542ULL, 0x5F6941E087F9E55BULL, 
            0x1AB2EFE436B1FDF2ULL, 0x91919AD97470E9D5ULL, 0xAADB25682E7540F8ULL, 0xF14E29C423C2B7D7ULL, 
            0xFCD1AB3C7AD9D032ULL, 0x8D5560133580289EULL, 0xC00689F6C1D0588CULL, 0xC9C00A247A5C7A66ULL, 
            0x6164C684803F158BULL, 0x8CE74155318892ECULL, 0xF3E1683A944E4AAEULL, 0xBBE46E7FBA6A827FULL, 
            0x8E1531FF34CF8DB3ULL, 0x33387ACB98E721C3ULL, 0x5E577C9976BEDB43ULL, 0x801DDC00503D29BCULL
        },
        {
            0x5A469DB6107ECB48ULL, 0x0B8316BD1257260AULL, 0x05C7D53928005F6EULL, 0xD799E240C3117E2EULL, 
            0xDF6AE411574A85E2ULL, 0x978F2AA9A76FC025ULL, 0xE9BA8B41591C1024ULL, 0x45EECD1E08A213E8ULL, 
            0x768341CE3F53F4F5ULL, 0x861CF230E169077BULL, 0xFA815A1B7FCB789AULL, 0x4012B773BE69B40EULL, 
            0x77E59923D6C93EF1ULL, 0x0DCB3935EAB3BA1AULL, 0x10D035C2DBB9135BULL, 0xF6487A3C9ACD1C04ULL, 
            0x1A35D2E826DD7BEFULL, 0x1B347C01BF69D321ULL, 0xAF12C8EAAC2A0711ULL, 0x1AE70E48285CBB0FULL, 
            0xE4400D5C7955EC07ULL, 0x9BDA4B93EBF4B9C7ULL, 0x9C0EC957FBA388E7ULL, 0x8E097C2B953E12ACULL, 
            0xD000FBC330373D26ULL, 0x09BCF56DD52DA104ULL, 0x544133A52B35A306ULL, 0x6582C5C780674FD3ULL, 
            0x89C01B484E0C3E81ULL, 0x807F2F96F4A0CF3EULL, 0x56DD2C1727ECB802ULL, 0x8E367E0BDC14E79EULL
        },
        {
            0x223873D63FBB047BULL, 0x347A3DE452EA28A1ULL, 0x52BD2E4F53F9DC60ULL, 0xD998C8EE386ADED4ULL, 
            0x27A4CEB2312B65FCULL, 0x187A9A8E6CAD11B3ULL, 0x4D8888BBE25528EBULL, 0x5DBC9A09AED9660BULL, 
            0x6B5B5052FDF18166ULL, 0x8048A7B0C90F3171ULL, 0x9C10ADEE083118BEULL, 0x87A368276868A045ULL, 
            0x60C71987EAD698A7ULL, 0x8BB0AE81C1FE8C8EULL, 0x66994ED47D835831ULL, 0x463BFFD76FFA40B3ULL, 
            0x4F6519241EAFFFD0ULL, 0xEF7DD59BE115C2A8ULL, 0x3CB77DE6316FC0A8ULL, 0x2C85F7F1D6D36901ULL, 
            0xFD19A6D924AAD674ULL, 0x5A975D28AD61D79BULL, 0xC89E8FF76045309FULL, 0x751050545F1C3E14ULL, 
            0xE14841FCA0F96962ULL, 0xCA64A6EC9DC73A58ULL, 0x2F60726B8877CE75ULL, 0x4232677B72E0A669ULL, 
            0x444442322B760C87ULL, 0xB4F89178D466CDCCULL, 0x6B7A22048F7A98D7ULL, 0x47BD2D53661DF713ULL
        },
        {
            0xF632781258F88E5FULL, 0xB6E53B458AA86318ULL, 0xE8E8B5E9A51D3429ULL, 0x18949E94DBA78547ULL, 
            0xE5C2746F8162F1F2ULL, 0x19ADF3CB392EA000ULL, 0xBCC0324858F94B2CULL, 0xD719735C8501C93CULL, 
            0xAF60860102ECFC39ULL, 0xAEC3AD5F18F2F6E6ULL, 0x4CAED93CBE1605BEULL, 0x5C99D79356184D78ULL, 
            0xB5B061A60E7C72DAULL, 0x1955B5881BB0F010ULL, 0x7D162D695E6BD0AFULL, 0xE19A2591108902FCULL, 
            0xCBB92369A79A2D7BULL, 0xFD712C8CC60F4C13ULL, 0x636F4BE43B592F73ULL, 0xD9F7EBF312CAEE53ULL, 
            0xAF972263CA945BF7ULL, 0x9E7F1E53D00CB8D3ULL, 0x49A044AD933169CAULL, 0x0583478EA0A36FE3ULL, 
            0xD613E6EC8FD98E7DULL, 0xAF8C8D550CF0F7E0ULL, 0xEFAF284E4EBF92EDULL, 0x51956468151F5EF2ULL, 
            0x08504944534AB287ULL, 0x7CF92BBE602E4BB7ULL, 0x9EF80D3B760455C2ULL, 0x90FB263146C1DC89ULL
        },
        {
            0x6E3252C69E01EAC0ULL, 0x3409A842920F9303ULL, 0x6A6E1632CD9405CAULL, 0x96C07AFD18FA42A6ULL, 
            0x04EC2569C9CD4DCBULL, 0xFD454AA3EFCA9D35ULL, 0x0DB6B5939E5316ABULL, 0xB2011D352EA53C03ULL, 
            0xF9F2046039849D10ULL, 0xB5A3390568FC469EULL, 0x3D39225D54C9AEA4ULL, 0xDEB976F4B8E707ACULL, 
            0x49B83C030611A1A3ULL, 0xA952BF760D36257AULL, 0x76EA3099DD860CA9ULL, 0x893D042B17AE98B4ULL, 
            0x98EF00CE0D0E4C68ULL, 0x35BACA61D4FCE0FCULL, 0x18FB1E6E0D4C85BBULL, 0x79BF09CD1F1F0A85ULL, 
            0xCD9495640CE7CA6CULL, 0xB014DEBC9DF6ADD6ULL, 0xD4855E3316DEE1CBULL, 0x7B46FD24687FC119ULL, 
            0x3693D549603DF706ULL, 0xFCAB329BD138A258ULL, 0x396C84AAA054D5F8ULL, 0x403186490AFBE8BAULL, 
            0x21A99004DB60F81DULL, 0xF5468DFCDC55B657ULL, 0x84BFF1A13E1B6062ULL, 0x5E2AB1704F269652ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Capella::kSeedConstants = {
    0x19019F6C1329FC97ULL,
    0xB93539EF2CE4C317ULL,
    0xD02412F4F847D792ULL,
    0x19019F6C1329FC97ULL,
    0xB93539EF2CE4C317ULL,
    0xD02412F4F847D792ULL,
    0xB3E50FB543630981ULL,
    0xFAB9740EF39525A1ULL,
    0x3D,
    0xB9,
    0x5B,
    0x51,
    0xF2,
    0xBC,
    0xA4,
    0x70
};

const TwistDomainSaltSet TwistExpander_Capella::kTwistSalts = {
    {
        {
            0xE647E01D650EA557ULL, 0xCF63B0ACC7475F67ULL, 0xABCD6D630C9CA36FULL, 0xA5437540957AFA23ULL, 
            0x1CC0D743037E6E71ULL, 0xF097971B3FA5A75EULL, 0xD45EA6DCEFE3B9F2ULL, 0x342B4CB25BE59CE9ULL, 
            0x633DCE5211FA106CULL, 0x334307E8AC3BEB78ULL, 0x0ADD494E29F58534ULL, 0xC83F8171E7384A58ULL, 
            0x87DD7CE351C3D7B7ULL, 0x668D8D92704AD2E6ULL, 0x188425AD2C997425ULL, 0xA17EC50772AF6C8CULL, 
            0xE59A7072C6F371DFULL, 0x20719CDA2876FF37ULL, 0x8BD1BE8323CC5EB6ULL, 0x1379C5FAB1233EBEULL, 
            0x43320B01BE1C7486ULL, 0xD70CF12CFD48006BULL, 0x5639B3F8DCC9DE54ULL, 0xE3EE8B8C6AF37170ULL, 
            0x41EC8BFFE22C5506ULL, 0x4D8FD824BEC6D1E7ULL, 0x5EB91B9E7B22EAA8ULL, 0x9C8B18506A3D8B73ULL, 
            0x67366DF39FF19518ULL, 0x8E94B49BDD22F2B3ULL, 0x9A41BE8101D24BABULL, 0x321A3754A2CBF65AULL
        },
        {
            0x0421853A3E9C7A24ULL, 0x77CACF77F142A1DAULL, 0xFFBF389AB80C8869ULL, 0xCB07A8B3FCD0EF45ULL, 
            0xC312F7BCDF33A3BFULL, 0x19FBE9987B3ABF24ULL, 0xDA3E8B1F9CD4AE17ULL, 0x8A9336AE5FFD1CA8ULL, 
            0xF975DD5A3DAB617FULL, 0xB6F116E044E1339BULL, 0x8333E1150E1DA4BAULL, 0x153FF48CBB174307ULL, 
            0x7D58F85204D7DAF8ULL, 0xB702281F44B4683EULL, 0x2F5C05C505B9E0D3ULL, 0xC9514F092C4C2B35ULL, 
            0x02BB7F46C4129FB8ULL, 0xD2FD12F7A42B5D8FULL, 0xB77CC79CAA08B42DULL, 0xC6BA1842B7F0B9D2ULL, 
            0x0F05FA19EC7ECF1CULL, 0x2DBF811E08563043ULL, 0xF686F87F3F6ECA3AULL, 0x812E132B52E99E2FULL, 
            0xF2E2E8A6448D3EE3ULL, 0x5C134893612CFF77ULL, 0x6C889C8C28F410B0ULL, 0x30518BDB012244FDULL, 
            0xB9D39A881F078CDEULL, 0x3F712B927A48308AULL, 0x99D97EC9D5977C41ULL, 0x99B36861F87197D2ULL
        },
        {
            0x6D12AFF7C8B3A03FULL, 0xAE6A58463A27513BULL, 0xD7FD78C1A86E7E23ULL, 0xD1FC9328C505C8C1ULL, 
            0x0A27BCEFB0FC198DULL, 0x16C0CE19460EFB60ULL, 0xCDD9C7374F6FD781ULL, 0x6DADED630B8026B1ULL, 
            0x8A1D46329B9C1451ULL, 0x735750430B0525F4ULL, 0x14E601E09FA0113FULL, 0x3024E2B9AAFD88B5ULL, 
            0x0B0F6A1E6F6A38C8ULL, 0x088157C4607143ADULL, 0x9EC704025B6DCC4CULL, 0x0B4D11934895F7ACULL, 
            0x51765C282BB9B14BULL, 0x337BE1293C26439CULL, 0x9C82EC9791D0370BULL, 0x616087F3C8270AE3ULL, 
            0x3EF92AA4DAF88C83ULL, 0xF6DA9B6A16F6662CULL, 0x825CD7F24C82736FULL, 0x918806A32F7A56F1ULL, 
            0x1D07376F1CA07F59ULL, 0x2AA7929E7C0FA1C3ULL, 0xCE090211E27357CCULL, 0x55AD273C121399D8ULL, 
            0x443C2040B3D42A70ULL, 0xBE5EE8A584912ECCULL, 0x89F36993FF3AACDDULL, 0xB93836E5ACA8DF87ULL
        },
        {
            0x300BA31AF1F3AA00ULL, 0x0D311C96496BA14EULL, 0xF1E761D767AD965BULL, 0x47495B9312B4864FULL, 
            0x967CF4F16D43E78AULL, 0x8008B4595952F5A5ULL, 0xEB7FBCF90B7C5F52ULL, 0x8572819E86514502ULL, 
            0x5D136F32225F0069ULL, 0xFB63F1E63AD07F48ULL, 0xF52F389F1DD6EC08ULL, 0xEFA7C7A4F711E407ULL, 
            0x38AD7C13F9AA5E8EULL, 0x6C7A52229B39C251ULL, 0x4C499FD4E62BB2CBULL, 0x87F2B35AFF0A8224ULL, 
            0x9E2FA85BC0B763C1ULL, 0xBF2ACD5176EAC010ULL, 0x7AE873FD309655E5ULL, 0x2E9E1AE245085F26ULL, 
            0x8611252E82472E83ULL, 0xA440DABA207FFC45ULL, 0x6FBE2495065CF1E5ULL, 0x3D0E0FCDCBE4B768ULL, 
            0xECD50B2290D8E998ULL, 0xB5910CD1AB32BD31ULL, 0xCD8B20DEBAC3F09FULL, 0x64162DC17C2C7E64ULL, 
            0x4B81B35A791FE55CULL, 0xCEF0339FCFB20C85ULL, 0xF01482E190850EC4ULL, 0x963E370C47B07A8DULL
        },
        {
            0x3505837BF629D96FULL, 0x0731A59AC76EC542ULL, 0x4BDC53516DE1C70DULL, 0x3589CF3E525D2F2CULL, 
            0x971DBF9CC380EF77ULL, 0xFFB07BB770292C0BULL, 0x1C37EE480A6C47DDULL, 0x8C411504B1060A68ULL, 
            0x4A7090D78BAA7B5AULL, 0x260E0C99A29A0BD6ULL, 0xA48BD99FEFCE2888ULL, 0x23774574A005AD7AULL, 
            0x474C5F92989B56DAULL, 0x3636237D262565BBULL, 0x08A5EDB026198596ULL, 0xAE15B61A21DADA3AULL, 
            0xB0AF527C7F751D7AULL, 0x3277B2D79D2B5E73ULL, 0x89CB8B6803B33E91ULL, 0x9FE003709FAB5D04ULL, 
            0x4FCF585FD5C699FBULL, 0xBBCF9EE99668B604ULL, 0x6E677F2B40A791A2ULL, 0x5292C4AEDBD6815AULL, 
            0x66650E4488D68BE0ULL, 0xD5200446BFC12CBEULL, 0x9620102F8F7F7FE3ULL, 0xAE93CD150B0B7354ULL, 
            0xA4CAFA0942C8EF7CULL, 0x33F8C797D50231F3ULL, 0x05962764342C81B5ULL, 0x1291CF850F275E78ULL
        },
        {
            0x3CB3847CFDA3E18CULL, 0x1EF6A40F4C456F02ULL, 0x59666ACB1FA1F8ACULL, 0x8A107860E4B8E744ULL, 
            0xF461E3BBB5963B78ULL, 0x25B8A3ABAE4D0D96ULL, 0xE66558C7C4A7F941ULL, 0xEBF216CF864FBAAFULL, 
            0xD6BB39B6D19D7224ULL, 0x65B98F872CF10477ULL, 0xB592CB4903CE3BB0ULL, 0x700D0FD45C773337ULL, 
            0x8A81C9FBC66117F3ULL, 0x62A30961B0B0CEB5ULL, 0x35DE6C435088A2B3ULL, 0x49E1827896A554A4ULL, 
            0x75EEC7ACE90A6063ULL, 0x05690D56BAB37FD4ULL, 0xCC612AA36FF606C2ULL, 0x851DAB2C87FCF1EAULL, 
            0x8F8C81FB95F3D6EBULL, 0x1AFE2E764B371CE6ULL, 0xD583FBC7BB6CCF99ULL, 0x33A2C0BAB88A72CFULL, 
            0x17BB16AB0368B8D0ULL, 0xE3B9ADD438EA09B9ULL, 0x03605D86C2F4B382ULL, 0x0002C7E8E0A5E804ULL, 
            0x430F336E1A720457ULL, 0xBAC1F047CD386CD1ULL, 0xB42E6D87B821D01EULL, 0x4234B95C289F2038ULL
        }
    },
    {
        {
            0x5AE54CD207B3A84EULL, 0x88C2C1EC113EAD96ULL, 0x7C1299F7265A0669ULL, 0xD27CC509636EEEA2ULL, 
            0x6034B4E9C2D8933BULL, 0x2455BE75B9C739CBULL, 0x0CDE840B4E0B31B7ULL, 0xB0523B2E673D8E78ULL, 
            0x4FA9D7D6E16F09C7ULL, 0x0B4F91E89357A332ULL, 0x098F9C5850B4789BULL, 0x561A8DBE83197881ULL, 
            0x987B26746B545090ULL, 0xD39D0CF8058AFC59ULL, 0xCA97B9EE275B81F2ULL, 0x1F9B2E75014A6C9DULL, 
            0x4832C8C87084F2AEULL, 0xB1D3EDBC7056EB83ULL, 0x9EF6438B78DE0C24ULL, 0x64FB1BA71502EF08ULL, 
            0x82013303B292E810ULL, 0x8ED583989A0ED1EDULL, 0x8DDFAC582DB85767ULL, 0xD35A5587CC916492ULL, 
            0x4E35873C6F031046ULL, 0x3736F4FA9F1E927DULL, 0x426F3AF564CFDA5FULL, 0x6EDE080CEB237E2FULL, 
            0x4B475C4F0E92991FULL, 0x652F2078209296A5ULL, 0xD36C982092A6E10CULL, 0xA74ADE2EE53C746BULL
        },
        {
            0x8B23F8228B9FCA1CULL, 0xED87FA0213AD5455ULL, 0xCB295F37F5C12D78ULL, 0x003635412693D213ULL, 
            0x189959DBEB6A6068ULL, 0xE64F856D98BD5B9AULL, 0x5F7A9C5D70D7F320ULL, 0xA1E7B311CCF49B4BULL, 
            0x3D4BB8DBD0908E9BULL, 0x68965EBC0132CDA4ULL, 0x867938509F0004DEULL, 0x23BBEEBB34A60D09ULL, 
            0x00AFDDCA3DC055BFULL, 0x5FBFF82552889886ULL, 0xDB79AA1B4DE999F3ULL, 0xF80F58512355DFA9ULL, 
            0x5C4075164F23818CULL, 0x3051AB965D14959AULL, 0xB1A00116180AC3BFULL, 0xEBAC8F70597DC24DULL, 
            0xA805A3B68374BE9BULL, 0x7CC7F99EF4878B77ULL, 0xCDF948FC52206548ULL, 0x9082191EAE57D5E4ULL, 
            0x579C9C55D59C29F6ULL, 0x85DCC201E8477F41ULL, 0x45742C60BEDB7D5EULL, 0x1CF9BC5291D01026ULL, 
            0xB89320BE5FD39EFBULL, 0x1F531A565AA28577ULL, 0xDCBBD6631B17E919ULL, 0x337C6F0FD7C5CEB1ULL
        },
        {
            0x3C2912AB369E9CD5ULL, 0x3EBCFDF0F9013771ULL, 0xA502FB43A15BB705ULL, 0x50708A377D87C5B6ULL, 
            0x44D2720C71CE6E0AULL, 0x37EB16BA756BCCFAULL, 0x76C59B4C20C716E0ULL, 0x3953B76EF51DBEBDULL, 
            0x7F5E778AE8516683ULL, 0xFBDE3FF5E2724266ULL, 0x7EEFD7275D7B2C0BULL, 0x41F134CE375A5AA0ULL, 
            0xA5F55522D45FB668ULL, 0xBDA27CD711D30655ULL, 0xC6DE24B9C3B97887ULL, 0x28B093C94016B267ULL, 
            0x615024F4B39AC4D4ULL, 0x04A9DBDD6CC80D79ULL, 0xA72E92C0E73A1370ULL, 0xD5E8BDEC3D3040B3ULL, 
            0x621DD6CCFE1E8502ULL, 0xE490CD67C874925EULL, 0x7F84C086D1548AB8ULL, 0x37E409ED8924B455ULL, 
            0x10B98F72F2ED804EULL, 0xF229CF70EE8E7F0EULL, 0x4A59C55EDA4181A5ULL, 0x484EFDF382230534ULL, 
            0x13A8A7729CA7ABC6ULL, 0x3C5B6F6E7ABDD730ULL, 0x4CEB77E44420A732ULL, 0x0F7AAF5D6002CFDEULL
        },
        {
            0x75E48CDD479D1656ULL, 0x4C9A06847270521DULL, 0xB133C70965E7B3D6ULL, 0xCC82F46F83DA283AULL, 
            0xF0F744DA84FF966AULL, 0x47E795C9D99C8754ULL, 0x06C792067C383A0BULL, 0x0F772F26EC344FE5ULL, 
            0x132E88B50BA85EA4ULL, 0x54693B9C81548BD9ULL, 0x6F9B61F289248646ULL, 0xAFAC86B62E0522BDULL, 
            0xAA307F3F64BD43A4ULL, 0x9490662FC6A1C895ULL, 0xA2779B4FB20A829FULL, 0x68E0448CFC7371C7ULL, 
            0x2D0C69B0CE3BAAEAULL, 0x33BC5499285B31A2ULL, 0x47ED4863E55E8A71ULL, 0xBA8D5C88F1401E92ULL, 
            0x7B70B219563DB2C6ULL, 0x0C329D52C1C0F64DULL, 0x421303DDEE0A9285ULL, 0x1921CF5CCC957590ULL, 
            0x3D067C6B8DC1D0D5ULL, 0x0938E6E94A2EDE8AULL, 0xE435B9D0F71497CEULL, 0x547760F8ECBC36D7ULL, 
            0x9B128A0C8BDEF58AULL, 0xD4153C7974859C18ULL, 0xA7C1742D18B52BE8ULL, 0x686E465C913C2FC3ULL
        },
        {
            0x14582587BD28726EULL, 0xF20302B4D5E9804FULL, 0xC1626054C6A32C49ULL, 0xAF0AA50B427A22D6ULL, 
            0xFB6AE0E446102D02ULL, 0x42209BA2DA653B52ULL, 0xC0BD381164F95C9FULL, 0xE0C051165A5CCEB3ULL, 
            0xFCB74F73525E2951ULL, 0x60AC9D1B128B6BA7ULL, 0xDE2D1440F58347E3ULL, 0x62DE85A2B53E841CULL, 
            0xA45F532AA50E96B0ULL, 0x828984252D57A774ULL, 0x3A44727D60ACD5ADULL, 0x8240490B7B259761ULL, 
            0x12AB85329808C89EULL, 0x6D38AD8D7742CEF9ULL, 0x7EC657D5A78A9AC0ULL, 0xB676394B664D2D77ULL, 
            0x6873881743680777ULL, 0x25F5C72EE984B716ULL, 0x036E648C5A76F92DULL, 0x751E296C78CC7D5DULL, 
            0x6DE75AE56854CCEDULL, 0x1F75FF0D5BBFB094ULL, 0x87BF69521D426205ULL, 0x312817C94DC4C0EBULL, 
            0x8D0A33B77C972DB2ULL, 0x51AB2B429B465217ULL, 0x54A014A6FA8E2E94ULL, 0x3A1A6E4C2770E0F3ULL
        },
        {
            0x16FDDBD6EC455E51ULL, 0x2DC1209EE6C46EE1ULL, 0xDFB5AD4C47245346ULL, 0x73A900F4BF12A75DULL, 
            0x645F3408E7FA8415ULL, 0xB00B48CC9C1AF24EULL, 0x5BC95F50A690D54EULL, 0xA7C7F2AC1BEA8C0FULL, 
            0x70DC5B51795204E4ULL, 0x83E5363AF6B27867ULL, 0xF0284FB43973A95EULL, 0x05D29598CC87ABE2ULL, 
            0x6A26454157668411ULL, 0x30212ECDC12695FEULL, 0x011CA44462902BC5ULL, 0x21530CA68B0530E8ULL, 
            0xE8EC263926670D45ULL, 0x4F9426526FD2C46AULL, 0x3D2967B7228440C0ULL, 0xC77A9F6F58A017EFULL, 
            0xCFE19C42196BE578ULL, 0x8157FDEB317E2BD6ULL, 0xAFE2BC7BC0EEFBE6ULL, 0x39E7429B84F33799ULL, 
            0x90F145CA3207D427ULL, 0xD4A0419E731F5AD0ULL, 0x08B3D7A28F3EA3E7ULL, 0x514AF12BC29C30FEULL, 
            0x7029C4FC0F69C0E2ULL, 0x4ACDC362A1A1423AULL, 0xBFC78582E4723948ULL, 0xB876A9C3D1223DD2ULL
        }
    },
    {
        {
            0x32800E3493C62E26ULL, 0x086137FD44289B43ULL, 0x2EB48024871806D2ULL, 0xD9E9185B7F2EB096ULL, 
            0x7113A0EB2AE274D8ULL, 0xA6662D90368949D5ULL, 0xCCCFC23B65724539ULL, 0x9E8A4E80E92DF45FULL, 
            0xD940EC3BC9E15145ULL, 0x511E46C8EC5C4A19ULL, 0x173109205D68F119ULL, 0xEBA52F8DF5256E89ULL, 
            0x3D331C05089DC42CULL, 0xC02645DE011789BDULL, 0xC13EEA932464560CULL, 0xFFDF85C2F2F6C80EULL, 
            0x61B1E757225EC09DULL, 0xDCBE1029D3C37B5CULL, 0x5C36AB84F8CF4C44ULL, 0x956C853821D1B3F6ULL, 
            0xF437A52AA5D4238AULL, 0xC4B239DA98DCF6B6ULL, 0x91C7BCE9120D6FB9ULL, 0xFD59FE1DB2CDD2CEULL, 
            0xE8BBFF57A7ED26AAULL, 0x739D520FA241D20AULL, 0x35A7E76B3C9D7E3AULL, 0x67804DC37A8472ECULL, 
            0x21950A130B6F9897ULL, 0xC333EAE876989201ULL, 0xBEA49F78B2D5F902ULL, 0xF8A4E470EE772E23ULL
        },
        {
            0xA134261873FD88B4ULL, 0xBE2AAECC74ABF052ULL, 0x49D284A309CFD0D1ULL, 0xE4DBAE9EAFC57212ULL, 
            0xFDA065F537C3AD3EULL, 0x0744801880AFFBB6ULL, 0xF2789468B3AB4FABULL, 0x381523646137FE3AULL, 
            0x2678D1CF5304158BULL, 0xC46FBC2150D7A89DULL, 0x01C4B30CB61C9693ULL, 0x7EBF5F880D93DAE0ULL, 
            0x3C48ACDF237FB90FULL, 0xD77EC5787AB50269ULL, 0x52BE3A66ABF6F67CULL, 0xF91B14EBA3F38D5EULL, 
            0xE0FB108E0194FE7EULL, 0x5449DA60467D5281ULL, 0xA6F5A1131580F57EULL, 0x7E162006D18798BFULL, 
            0xE91A95194F557A7FULL, 0xF510184CD662B0DCULL, 0x0AAEB003D02C6DA7ULL, 0x4985E5794BC8A0FFULL, 
            0xD8EA45D343DCAF7FULL, 0xD3B92D738EEAC2FAULL, 0x280162561BCEC17CULL, 0xAAEBE200844F05BDULL, 
            0x6CA67723C8C82A39ULL, 0x5957E4B2DE9A962FULL, 0x8909A040B847643DULL, 0x2C31996E5B64540CULL
        },
        {
            0xFE9A3DE93A103A9DULL, 0x9B2E4A65D99989DDULL, 0xD0ADE5E50D0C2CBEULL, 0x7C27A20832B0A1FDULL, 
            0xC4F963F8C6592229ULL, 0x9533A72324C00BB2ULL, 0xABF5460164FB9BDAULL, 0x8C476F843713171FULL, 
            0x5FC8593B7AF0CECBULL, 0xF0993A1261B41487ULL, 0x2A9C0B11B9D816E6ULL, 0xCC18C64F16488761ULL, 
            0x303EE11327240636ULL, 0x9C08E364878183A5ULL, 0x06C891D4C61F5DB3ULL, 0x86820F68792A04EBULL, 
            0x5B7F89961989C195ULL, 0x0886DF6A7E7D29C7ULL, 0x58E82F6992EB3803ULL, 0x9B976FBAE6ECE0CDULL, 
            0x468B00214ECB3F97ULL, 0xEAE4845A7B1BA5ADULL, 0x33F11B4C07573F91ULL, 0x688A222C9EE24E1AULL, 
            0xE8B337CED7053B8FULL, 0x7D3E3FAFD4C9AFACULL, 0x9C7E9DE818427CADULL, 0x5215B3E692F0BC96ULL, 
            0x916F89B5376A7B84ULL, 0x7F2DF7D47779C121ULL, 0x15052DD48D797A17ULL, 0xAEF36943CEBCA117ULL
        },
        {
            0x37C04FD36B52CF82ULL, 0x3D9B45AC32F04501ULL, 0x6DE503EAF03DAF69ULL, 0x7C5EC22460B38156ULL, 
            0x3AF445AEED354497ULL, 0xBC2918C8B883E969ULL, 0xD4B8BD10A9ED912DULL, 0x1E51789E68E52F37ULL, 
            0xF74C9BD0F7E46BB4ULL, 0xB7ABCE30537E80C3ULL, 0x66836059BA038447ULL, 0x9AE36087956498C9ULL, 
            0x64A7DE06489FC9CAULL, 0x97AB8695998D5B46ULL, 0x50DC95D0CEEE3E0EULL, 0x3A23530E7A428F36ULL, 
            0x4EA863EE44F10E35ULL, 0xE3D8FA5D6C504233ULL, 0x6246E9ABF6BEFE85ULL, 0x811C936252DFC297ULL, 
            0x44526170E6CBFC28ULL, 0xE340381FACC2F140ULL, 0x16AA399D0D49005EULL, 0x96E4FA01F2E2BCCBULL, 
            0x9D8F36559F86C065ULL, 0x101F5DEB46B325D5ULL, 0xBC7B92411D0316FAULL, 0x4E32C2DFE15F2D97ULL, 
            0x0B6C996EFB3DB63DULL, 0x538FA78A389D816EULL, 0x4036DACB53EDAB43ULL, 0x022021EB55E0F5D4ULL
        },
        {
            0x99EC488772A63678ULL, 0xCFC5EC608F39B5AEULL, 0x105FA9405E77F6E0ULL, 0x1284622CDE92078FULL, 
            0x3D0AF01B81646087ULL, 0xDB106D388678B0D8ULL, 0x2F2B04D5FCF18B4CULL, 0x46E7EE3763172EAFULL, 
            0x430A663E850A1AB4ULL, 0x779B9F3E81DCCFECULL, 0xB62F522ECE73F4B0ULL, 0xDEF65BF02D684778ULL, 
            0x580E07045104E5F2ULL, 0x5E6866482477E097ULL, 0x3AE28FA6867050C7ULL, 0x6968AEF2DA8D5EE0ULL, 
            0x5A558088B1FE641AULL, 0xD314665A04CB9889ULL, 0x76307F5335528C38ULL, 0x4CD0DAD91202A2F0ULL, 
            0x611282BB9DC6B880ULL, 0x69DBD5873479BCE5ULL, 0xC6822F25FAAC58BDULL, 0x880E3E671C402E42ULL, 
            0x6F17EC32414A5A09ULL, 0x3A072DA876638F7AULL, 0x694F3B8FF9C0D9EEULL, 0x31D126832479131AULL, 
            0x89083904822959A1ULL, 0x7935108CAE8C2E16ULL, 0x204CD0DEC2E31E20ULL, 0x0CAEEE34F20A33E7ULL
        },
        {
            0x7CB4ECF44797302DULL, 0x5BAE94DFEFBE4FC9ULL, 0xF9E6CB31DDA64FE1ULL, 0x1B8DDD544FAD00D5ULL, 
            0xE85C64F0F3F79E9FULL, 0x7B6280DBBCDFE0E8ULL, 0x4777E2303C0DB9B0ULL, 0x34920464FF3B38DEULL, 
            0x721FA60CCB1E8C75ULL, 0x153506B93AF85A25ULL, 0x750BC279DCE5BE2FULL, 0x90238A0CD3F609BCULL, 
            0x43C582896C00BCA7ULL, 0xF596F064A614888BULL, 0x40A64B109D273084ULL, 0xE7B4FDACA5B56BB6ULL, 
            0x9BEE606B1AC465DEULL, 0x3E2C108C6A292B6FULL, 0xB3492D2F4787D129ULL, 0x2718C08A3F7CD0D7ULL, 
            0xC5E5A19C808C4A96ULL, 0x8BB1A86D39BF4EC5ULL, 0x138F0C8733527897ULL, 0x89BDDAA6AEBE909FULL, 
            0x1DC4B11E295075F6ULL, 0xB188F8A5B2000AF7ULL, 0xF1054BFC9F7E871DULL, 0xAEB4E8B1A2D8792CULL, 
            0xDA68FECC5ED05B2BULL, 0xC6EB192DBBFCEF07ULL, 0x914D40B564195C54ULL, 0x7E875B53C1279809ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Capella::kTwistConstants = {
    0x0C0C6B9748B83760ULL,
    0xB6C5F15FCED71963ULL,
    0x420CDB023D73D8D9ULL,
    0x0C0C6B9748B83760ULL,
    0xB6C5F15FCED71963ULL,
    0x420CDB023D73D8D9ULL,
    0xC3D50D966A8E5483ULL,
    0x35055E232D079FDCULL,
    0xA7,
    0xBD,
    0x49,
    0x2F,
    0x23,
    0x5D,
    0xC3,
    0xA7
};

