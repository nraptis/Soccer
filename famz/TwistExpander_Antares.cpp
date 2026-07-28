#include "TwistExpander_Antares.hpp"
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

TwistExpander_Antares::TwistExpander_Antares()
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

void TwistExpander_Antares::KDF_A(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Antares_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Antares_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Antares_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Antares_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Antares::KDF_B(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Antares_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Antares_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Antares_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Antares_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Antares::KDF_C(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Antares_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Antares_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Antares_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Antares_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Antares::KDF_D(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Antares_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Antares_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Antares_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Antares_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Antares::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB67D91F3B4385A59ULL;
    std::uint64_t aIngress = 0xEA58B447FB91E402ULL;
    std::uint64_t aCarry = 0x948906319A92FC53ULL;

    std::uint64_t aWandererA = 0xC603DEB92A582DABULL;
    std::uint64_t aWandererB = 0xCC6B31EB01D2DA0BULL;
    std::uint64_t aWandererC = 0xAA311D0D3C0FE3BBULL;
    std::uint64_t aWandererD = 0xDA59BE6FD5F5CF82ULL;
    std::uint64_t aWandererE = 0xF4275C4F3596F325ULL;
    std::uint64_t aWandererF = 0xC4B1E828D4C490ACULL;
    std::uint64_t aWandererG = 0x89F1EEDD893C4699ULL;
    std::uint64_t aWandererH = 0xE5333764575F2E69ULL;
    std::uint64_t aWandererI = 0xCF6A3F3AD818C2BEULL;
    std::uint64_t aWandererJ = 0xFE3F7DD77EA576C1ULL;
    std::uint64_t aWandererK = 0xFB1FBAC498A080DEULL;

    //
    // KeyRotate A
    //
    aPrevious = 0xC51E25AFB3C05EDBULL;
    aIngress = 0x8D865CBCD09B3E2FULL;
    aCarry = 0x952EE598DE6780E3ULL;
    aWandererA = 0x80E6106BFC40A0C2ULL;
    aWandererB = 0xD1F6E05F377C43F3ULL;
    aWandererC = 0x8EA3B9B35FE4517CULL;
    aWandererD = 0xB14CFBDBF524AF6DULL;
    aWandererE = 0xD85B479A526BFE3AULL;
    aWandererF = 0xC95092C4AA3EBA22ULL;
    aWandererG = 0x9EB2B01643BFF1B1ULL;
    aWandererH = 0xA90A2C8DE8639FB7ULL;
    aWandererI = 0xD7D232EDBC1042EDULL;
    aWandererJ = 0xA7B78917ED8B076AULL;
    aWandererK = 0xD04A616358FC47C2ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), pSnowLaneB, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateAConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xC4F84ECAF97B9B6DULL;
    aIngress = 0xB962F3C780ED5F42ULL;
    aCarry = 0xEDE296F33469B661ULL;
    aWandererA = 0xFF06E7E829BAEA47ULL;
    aWandererB = 0x9D1C521858ED80CBULL;
    aWandererC = 0xDE7CA58C27E18588ULL;
    aWandererD = 0xC9B168620B02000CULL;
    aWandererE = 0xC8F3F435E942338BULL;
    aWandererF = 0xE7AE598A0D4CBC48ULL;
    aWandererG = 0xE59464646CEAB7BEULL;
    aWandererH = 0xE3E28B4BC959673EULL;
    aWandererI = 0xDDE4260643F73F7DULL;
    aWandererJ = 0x86E805D9C98186D7ULL;
    aWandererK = 0xD335ACAD498601F6ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xD11AF0EE6DC1255CULL;
    aIngress = 0xC90833CE9E59C28CULL;
    aCarry = 0xEF11F49206F3883EULL;
    aWandererA = 0xB03B780076514CADULL;
    aWandererB = 0xBEBDA9C66DC7112AULL;
    aWandererC = 0xC49E5C0C6D969BACULL;
    aWandererD = 0xAF5E1541318BFD5BULL;
    aWandererE = 0xAF80D5F8A111E350ULL;
    aWandererF = 0xBF91B68E1FBE5696ULL;
    aWandererG = 0x945628C502A4ECB2ULL;
    aWandererH = 0xE8A5C342EFC1094DULL;
    aWandererI = 0x93271727ABE8A60BULL;
    aWandererJ = 0xAE102167AC90D84BULL;
    aWandererK = 0x906BE578EC04F7A3ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnAConstants), &(mDomainBundleInbuilt.mKeySpawnASalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants), &(pWorkSpace->mDomainBundle.mKeySpawnASalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xA3A55DFD923C05DEULL;
    aIngress = 0xB0639B75FA083AFEULL;
    aCarry = 0x8805C1BB33B57F14ULL;
    aWandererA = 0xDF6F25A6891E1F5DULL;
    aWandererB = 0xB4A869FAADF9934EULL;
    aWandererC = 0xDECF44FC6E5B375DULL;
    aWandererD = 0x92CAB915F97BA3A4ULL;
    aWandererE = 0xEEE9BFBA0035A491ULL;
    aWandererF = 0xC967F29283A940B5ULL;
    aWandererG = 0xED251C9E9E4061DBULL;
    aWandererH = 0xC8AC4FD4FE0BBC71ULL;
    aWandererI = 0xEBADF5FE8740D641ULL;
    aWandererJ = 0xEB0BAA91FD67310AULL;
    aWandererK = 0xF5D9AA83BC8C953DULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnBConstants), &(mDomainBundleInbuilt.mKeySpawnBSalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants), &(pWorkSpace->mDomainBundle.mKeySpawnBSalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xF445121A86B88DCAULL;
    aIngress = 0xEB55BAF0A81A640CULL;
    aCarry = 0xCC068C82F1E7D076ULL;
    aWandererA = 0xF62060E93568C4B2ULL;
    aWandererB = 0x9680199811F5BDD3ULL;
    aWandererC = 0xB269750B6D27D2A0ULL;
    aWandererD = 0x85CEDFA4B7093EE5ULL;
    aWandererE = 0xFB9C91A1EDB4236DULL;
    aWandererF = 0x843013AA79C666A2ULL;
    aWandererG = 0xC3B77D89073C2878ULL;
    aWandererH = 0xAEB94E8590B16899ULL;
    aWandererI = 0xC7BB4EAE1941F744ULL;
    aWandererJ = 0x97696C44D146CC06ULL;
    aWandererK = 0xD5B4B20D3EEFA4C3ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xE997EEB080DCF70AULL;
    aIngress = 0xC465C2172B4DD3A4ULL;
    aCarry = 0xB52ABC0C62C8DD46ULL;
    aWandererA = 0xB5837FAB1AD6316FULL;
    aWandererB = 0xD219D2CD7E978B14ULL;
    aWandererC = 0xC9B91FB399C30B4EULL;
    aWandererD = 0xD86BE98A8E912390ULL;
    aWandererE = 0xE51D5D4853237AD8ULL;
    aWandererF = 0x90CABB5B1DD9F231ULL;
    aWandererG = 0x8A557CA6754F05D7ULL;
    aWandererH = 0x836ED3872C16A842ULL;
    aWandererI = 0xB534AF4C0EE5330DULL;
    aWandererJ = 0xA5E474B2A72210EBULL;
    aWandererK = 0x9ABD177B53148EB7ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mSeedSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mSeedSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mSeedConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mSeedConstants), &(pWorkSpace->mDomainBundle.mSeedSalts), pSnowLaneB, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mSeedSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xE012BA10935D12F3ULL;
    aIngress = 0xB3A497FA1A4A7885ULL;
    aCarry = 0xCC3AEB3E11C90C1CULL;
    aWandererA = 0x91068F7588A43AF2ULL;
    aWandererB = 0xF7560B9163A81C29ULL;
    aWandererC = 0x957C80BFD44C0B5BULL;
    aWandererD = 0x9D1D34E6F864904FULL;
    aWandererE = 0x87A2DCAAC9E31596ULL;
    aWandererF = 0x8BCA7A4A9CC744F0ULL;
    aWandererG = 0xAE846979B1DECCFDULL;
    aWandererH = 0xAEC60663DE4E190BULL;
    aWandererI = 0xD8A7041F3310BC46ULL;
    aWandererJ = 0xE0EF6EDCB8D1343BULL;
    aWandererK = 0xD8E611F662FB14FCULL;
    //
    TwistExpander_Antares_Arx::SEED_A(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Antares_Arx::SEED_B(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Antares_Arx::SEED_C(pWorkSpace,
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
    TwistExpander_Antares_Arx::SEED_D(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Antares_Arx::SEED_E(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Antares_Arx::SEED_F(pWorkSpace,
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
    TwistExpander_Antares_Arx::SEED_G(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Antares_Arx::SEED_H(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Antares_Arx::SEED_I(pWorkSpace,
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
    TwistExpander_Antares_Arx::SEED_J(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Antares_Arx::SEED_K(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Antares_Arx::SEED_L(pWorkSpace,
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
    TwistExpander_Antares_Arx::SEED_M(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Antares_Arx::SEED_N(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Antares_Arx::KEY_A_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Antares_Arx::KEY_A_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Antares_Arx::KEY_A_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Antares_Arx::KEY_A_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Antares_Arx::KEY_A_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Antares_Arx::KEY_A_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Antares_Arx::KEY_A_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Antares_Arx::KEY_A_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Antares_Arx::KEY_B_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Antares_Arx::KEY_B_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Antares_Arx::KEY_B_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Antares_Arx::KEY_B_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Antares_Arx::KEY_B_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Antares_Arx::KEY_B_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Antares_Arx::KEY_B_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Antares_Arx::KEY_B_H(pWorkSpace,
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

void TwistExpander_Antares::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xDBC59D45A2454758ULL; std::uint64_t aIngress = 0xD27405105E2B321DULL; std::uint64_t aCarry = 0xB98F5BCACB4F103CULL;

    std::uint64_t aWandererA = 0x83B21BDC5BA9A767ULL; std::uint64_t aWandererB = 0xF3AB738C83AEF058ULL; std::uint64_t aWandererC = 0x8CA87F51258162DEULL; std::uint64_t aWandererD = 0xBE1F0447C61E9FADULL;
    std::uint64_t aWandererE = 0xB60EBBFA4D79B66CULL; std::uint64_t aWandererF = 0xC1013FD9EF2A1AD5ULL; std::uint64_t aWandererG = 0xDBCE41DC934B3F19ULL; std::uint64_t aWandererH = 0x9B67C884079A91A9ULL;
    std::uint64_t aWandererI = 0xBE92F3D1FD45BBAFULL; std::uint64_t aWandererJ = 0x8BFE767F3CBC472DULL; std::uint64_t aWandererK = 0xBF65FEFC42673120ULL;

    // [twist]
        aPrevious = 0xBCDDC7CF58F790A5ULL;
        aCarry = 0xAE49EAA09D33FE93ULL;
        aWandererA = 0x9B33F6AE7001E6F5ULL;
        aWandererB = 0x9E99FF7C2081B2FBULL;
        aWandererC = 0xC43DE23450A8F0A4ULL;
        aWandererD = 0xBE92FD208405AE23ULL;
        aWandererE = 0xF216A4CFAD166E08ULL;
        aWandererF = 0xDD2F91A2CCEDDE31ULL;
        aWandererG = 0xA39B419153961F72ULL;
        aWandererH = 0xB587FB31CF48B437ULL;
        aWandererI = 0xF69D3DDC9177B432ULL;
        aWandererJ = 0x8F490F0E977EFF65ULL;
        aWandererK = 0xB4158E2574F3E2B6ULL;
    TwistExpander_Antares_Arx::TWIST_A(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Antares_Arx::TWIST_B(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Antares_Arx::TWIST_C(pWorkSpace,
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
    TwistExpander_Antares_Arx::TWIST_D(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Antares_Arx::TWIST_E(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Antares_Arx::TWIST_F(pWorkSpace,
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
    TwistExpander_Antares_Arx::TWIST_G(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Antares_Arx::TWIST_H(pWorkSpace,
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

void TwistExpander_Antares::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Antares_Arx::GROW_A_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Antares_Arx::GROW_A_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Antares_Arx::GROW_A_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Antares_Arx::GROW_A_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Antares::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Antares_Arx::GROW_B_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Antares_Arx::GROW_B_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Antares_Arx::GROW_B_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Antares_Arx::GROW_B_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Antares::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 9 of 33
    // Exploration cases: 0
    // Structural maximin 541 / 674; family total 4405
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
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8059U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4008U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3648U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3828U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1420U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1960U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1915U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 92U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1510U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1555U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 2005U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1600U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 9 of 33
    // Exploration cases: 0
    // Structural maximin 537 / 674; family total 4398
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
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3378U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7519U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3198U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6979U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 745U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1240U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 565U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 520U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 610U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 475U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 925U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 790U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Antares::kKeyRotateASalts = {
    {
        {
            0xD0EE51F830609EF4ULL, 0x0C312D4BB324A7FEULL, 0x36A0A9E4F7B67E0EULL, 0x757AC12A1D5E825CULL, 
            0x8640E4C00BA8B04DULL, 0x3E105A1A90FD22DDULL, 0x6556B523F24A9569ULL, 0x605FD9B7B88F48BEULL, 
            0x17CE4DDFDDF0B9E1ULL, 0x2F4BB6B27D6D1D69ULL, 0x5386A19EB071B0AAULL, 0x5A02986473CC39BCULL, 
            0x67699451793FB8BFULL, 0x096387DC39D219D5ULL, 0x5824F0BECA3BB363ULL, 0x6C9142CAA1D5DFAFULL, 
            0xD39340760D527EC1ULL, 0x5DC58BB77BD793D8ULL, 0xCA6EEAD14B432E2EULL, 0x3EBF24A899566518ULL, 
            0xDD6474E5A6FC8425ULL, 0x5CDBF2E4FD5499BEULL, 0xFD8DB47BA919841CULL, 0xD27935401E7F6E5CULL, 
            0x14572A0FDBB28400ULL, 0x63C6B0BE92005EABULL, 0x4C7C60624D864C2BULL, 0x1E0A5A849668B3D9ULL, 
            0x5417C3EFEF5B8664ULL, 0x7D21E7DE0546121CULL, 0xDEEFCF8AE9CB0AF1ULL, 0x6F7BBA6726BA771CULL
        },
        {
            0xE1AD4C43A053F792ULL, 0xB18B978B0462370DULL, 0x91525F967B67BE09ULL, 0xE15BC391977BF181ULL, 
            0x8DC2948110E3CCE5ULL, 0x412C3497D8E37B18ULL, 0x105B2D07606BC192ULL, 0xF6A0E464A0DCDE4DULL, 
            0xEA17D7D75C065707ULL, 0xAC5670A5CF3C6D97ULL, 0x418A85C4C14A8D21ULL, 0x60862C0FE7633E52ULL, 
            0x1622F6C77389004CULL, 0xD8DFEA478794994BULL, 0xD9A12897A39803F2ULL, 0x102CE659D063E840ULL, 
            0xA3D5EB8390C22468ULL, 0xF2CF0640EE51623CULL, 0xC55F271AD4DF95E7ULL, 0xA0C37FAC16890EB8ULL, 
            0x98B5E83395B67D28ULL, 0x8F2FD4A200F19DD2ULL, 0x471B612B1CF5A8F0ULL, 0xA2CE05B16E7807D0ULL, 
            0xBB64C98E69D2921AULL, 0x2799D95F54CFECA0ULL, 0xABA00DEFBD3CC6A9ULL, 0x06CE61A402661AF3ULL, 
            0x04E587B30F9A3139ULL, 0x5E60A0B1587A1AECULL, 0x5E79CAF909F1CB16ULL, 0xD69AE2E09C6C6676ULL
        },
        {
            0x73C8E32271273320ULL, 0x907BB3D1BCFC4BCDULL, 0xB805AC6DC1F05821ULL, 0xBB2ABB7EA9FA8BACULL, 
            0x9AD7D8ABC7D4F236ULL, 0xEEE141260E3B581CULL, 0x3BB01C15ADE2A2E5ULL, 0x64FF2A895518000AULL, 
            0x95875DC41681371FULL, 0x990A14B07AEA5C5FULL, 0x8CD2AB7C5EEBB172ULL, 0x4A0264B551DD2E9DULL, 
            0x3371901BAE9EC6F3ULL, 0x9A626E03778D0646ULL, 0x7FF466F756D8F145ULL, 0x35778564EA0140A9ULL, 
            0xD6F804E839BBBE25ULL, 0x5D4E3906217989F7ULL, 0x023519DE892217B6ULL, 0x3FD851528851B92FULL, 
            0x636BD2EA018545D2ULL, 0x3CB4C47791B3872FULL, 0x891A6AB248B850ABULL, 0xE530B13E2513F1D5ULL, 
            0x8532F83B3C5572E8ULL, 0x10E39FF781419352ULL, 0x266637DD32A5684AULL, 0x0B983BD4FD44BA33ULL, 
            0x1D86A9A0D70DEE87ULL, 0xE9FD0DE05F256CF5ULL, 0xC0C40A60316612A0ULL, 0x432DEFA50240ED88ULL
        },
        {
            0xA8CB06054E0908FDULL, 0xB76979C9165B3FA7ULL, 0xE3BEC94B1B332B1AULL, 0xC4FFCC458E7637ABULL, 
            0x8C1044C609F147CDULL, 0xB55C8DD95E24233BULL, 0xA8CCADAE37DFDE41ULL, 0x072E7B2154188EC2ULL, 
            0xC4ECE357CDD2A623ULL, 0x8849F01B20E81108ULL, 0x543BD8864A168227ULL, 0x521B680AB5408C13ULL, 
            0x541C2D4254AE7D61ULL, 0xAE19ADEBA0FB6502ULL, 0xCA42BB0552A55A4EULL, 0x799B623CF31EE493ULL, 
            0xAD0A64298F6F8359ULL, 0xAEBA029BA29CE926ULL, 0x0CD27DDF7FF4CFE1ULL, 0x78803AF0253CD551ULL, 
            0x2679525D788A3976ULL, 0xD6A47BE61BCFF16EULL, 0xC37274F9795F1A9CULL, 0xF820DB8A10D76241ULL, 
            0x489DDD15C1E08DA9ULL, 0x971B88CF73A8A81AULL, 0x749393267C3B4942ULL, 0x5FFAA76A274300D1ULL, 
            0xCC5F112251357D29ULL, 0x1A41A67C878F915AULL, 0x75C2EFCB0BDB430DULL, 0x15420ED4FD61FC00ULL
        },
        {
            0x330A0FD0CEB0857FULL, 0x81C3E685233C4AC9ULL, 0xEA90BF3C839EDF76ULL, 0x42BBB5A3DB279D7BULL, 
            0x4D42C9CABC0CEB53ULL, 0xB79A575E575F8B9BULL, 0xD0A425CCDC3579C1ULL, 0xF76B6AAFB41D5A31ULL, 
            0x3D09EE86B71EAD65ULL, 0xEDF010BB97B474A7ULL, 0x8EB8F4A7CC50D8C2ULL, 0xADF2AAE2873F4C72ULL, 
            0xBC0D6893F1EEDF5DULL, 0xDCA0D459B9C4EF15ULL, 0x9B1E5C8E58536305ULL, 0x40015CC0E8CE3434ULL, 
            0x40DC866FDC1E9115ULL, 0x6E743FC7956D0499ULL, 0xAEE7B1F9860FE34FULL, 0xB6278261AD34FA76ULL, 
            0xADBA99F24325E661ULL, 0x6505A4D241DAB376ULL, 0xFCB2A446A3C66A1AULL, 0x7B19F0775F0620C7ULL, 
            0x634CFA365B2458C2ULL, 0x16061D9154179CCCULL, 0x551909CE249C2C53ULL, 0xD9304E6F7E116467ULL, 
            0x2CC0E20890E35DEBULL, 0x8540E39A56CF54C1ULL, 0x8A97E5C344368AF5ULL, 0x69FB9F7907CFC14AULL
        },
        {
            0xC701759D9AFF3301ULL, 0x9041C9FC30394DA7ULL, 0xC539CDB1F1B1BB78ULL, 0x58138F84E3BB1A70ULL, 
            0xCA698D09BAC85E47ULL, 0x07F66A5FAFDA7A28ULL, 0xE1599A75634BFD23ULL, 0x9E6200EF4D0BE321ULL, 
            0xB04F4F2ED05FF1A9ULL, 0x611426C67423D552ULL, 0x1CAB23E5E2293E8CULL, 0xFEC110A48FEDA591ULL, 
            0xFEEA1E23CE89C672ULL, 0x5135F958CD5C1FF8ULL, 0xDCF91CFBDBED9E07ULL, 0xE9E3A71802B6CFC5ULL, 
            0xFC5B74D396626B1DULL, 0x5AE6FF462A0B1A92ULL, 0xD609936031C0FBE3ULL, 0x3B093CB28DE802D2ULL, 
            0x288762DE23F202A6ULL, 0x1BA497821EA6BFE5ULL, 0x4DD3B54442F048C5ULL, 0x0C3250824CD80E4EULL, 
            0xD5670175F18C18DFULL, 0xC5B8B9215F74A529ULL, 0x276A9CC82B690817ULL, 0xB09124D9D1F605EBULL, 
            0x5F8B40CEB4D39E35ULL, 0x5241DA142B5766B3ULL, 0xBE002FF6E02834ADULL, 0x236017D4B3FE0B84ULL
        }
    },
    {
        {
            0x1C3B77D14214C816ULL, 0x97577E2AB3EBEA87ULL, 0x187AD9C54712021DULL, 0x2CE95DFFCA570B57ULL, 
            0x46FC6E4C91ED8683ULL, 0x8116BCDE6BE2FFAFULL, 0x50D506FC2A754060ULL, 0x6EE2436D12D6467BULL, 
            0xC883DCD37F897B44ULL, 0x0056D52DA164CD45ULL, 0x0E5D88D67469C2A3ULL, 0xE2167300E2540430ULL, 
            0x4A23DB2CE3A80540ULL, 0xA3FE573F238930FBULL, 0x7F7D93AA0333B6BEULL, 0xFC7058728D62C6D8ULL, 
            0x6C53E163C6C9547CULL, 0x0684D67860EB04CDULL, 0x641FCD288F2EC3B6ULL, 0xEA32990C7A202BD8ULL, 
            0xE732EB21DED2E87DULL, 0x6CAD6061374169CFULL, 0x44435F29AA62A246ULL, 0x6835F00865907644ULL, 
            0x2B19A6EA29B91A6DULL, 0x6C6E99799CD33D80ULL, 0x19EA3EFC6A913902ULL, 0xCB473B6B04BC630CULL, 
            0x8A68898465E12919ULL, 0xB4A3DFD47DC7E2B2ULL, 0xABF19E8ED780F329ULL, 0x8200CABE349783E5ULL
        },
        {
            0x4A9FCBA7AE6A8F91ULL, 0x2F20B6581B1957D4ULL, 0x3082BAEAC2144AC6ULL, 0xCB291EF06FF9F872ULL, 
            0x17CA2224B0E20A2BULL, 0x207982A7E3ACBA1EULL, 0xB9369267E52E68BBULL, 0xC187CC44CBBA34BDULL, 
            0xEA752D3437010DE7ULL, 0x382507EE0A552A27ULL, 0xD88A2BC1E4178CF8ULL, 0xCE9BBA1E56BB23CEULL, 
            0x5B78FD217E03E99BULL, 0x6C6D05776E643ABDULL, 0x3EB32310FFFF55CBULL, 0xE5BD58858B9BF7D0ULL, 
            0xAC45B235BDC22EE1ULL, 0xDA7B000D9501149AULL, 0xCE88A947789EC348ULL, 0xB02D5C5DEA6B225DULL, 
            0x22356D82A6B3705CULL, 0x6B3558DF5E635FB7ULL, 0x191CD36FABF63CCEULL, 0x4DBE0CBF321D6C4EULL, 
            0x89B15994B63A2568ULL, 0x2A0D74F0004525ECULL, 0x25205ECA659BAFAEULL, 0x82E4ECA2799C3CB8ULL, 
            0xF0157F7AFB2AD11FULL, 0xAC91288B3EB5C554ULL, 0xAC603C692442CF05ULL, 0xB711EBDED0B0D10DULL
        },
        {
            0xAC135B0114D1E2D7ULL, 0xF356CEEAA52F33B8ULL, 0x4BC2FF71401EBCA9ULL, 0x276B89515856EF7FULL, 
            0xFF084D70E5CE4857ULL, 0x09EC92ED77568766ULL, 0xE7B541CBA073C8F1ULL, 0x6C3581B357EC34C6ULL, 
            0x1FBBB9BE9BEB7801ULL, 0x84B7B8BAB900B00BULL, 0x72DD7B04E2D92241ULL, 0xB320D7CD36C7942EULL, 
            0xB5B50C9C973E482BULL, 0x75D6F805D16E9372ULL, 0x6A0686E7C3F5B25BULL, 0x4AAEF1387E630BEBULL, 
            0x7A5247CEA24C6B5FULL, 0x30D92690C632D2A0ULL, 0xA38E5F714977B698ULL, 0x2F90451EDE076B45ULL, 
            0x11C3CAF8840A2888ULL, 0xF756913480475C16ULL, 0x1DC35832D649BD33ULL, 0x74662B2E1613BB9AULL, 
            0x7721E7C93D6549C0ULL, 0x61D0156004B1D962ULL, 0xB3DA90649CBA80E9ULL, 0x14D261C3ABA2DCA1ULL, 
            0x306ADC3563D18C74ULL, 0x2098C716647F41B8ULL, 0x5C1242D46413CA92ULL, 0x614941A95065B31FULL
        },
        {
            0x0951A7E5DCD653F4ULL, 0xC39FBF50F5DDFAC0ULL, 0xD0356D9322E2D598ULL, 0xC5B98D1CC45E5275ULL, 
            0xD081C492B17FE948ULL, 0xD750CC41882DE059ULL, 0x38A29480639195E9ULL, 0x11C494BA4650AC31ULL, 
            0xA17C3ED8F36FA5FEULL, 0x6CDC11780EBE5E37ULL, 0xAEDF37562EDF6B53ULL, 0xFCE4AEC35742CE15ULL, 
            0x6974D30D8F8EC81DULL, 0xD6CFC6C94C60E0D0ULL, 0xF71E0F336AFFE5C2ULL, 0x9609DCA0DAB43281ULL, 
            0x8DF72E27C4F3E66AULL, 0xD005519F0FB46571ULL, 0x3D23F5F527620674ULL, 0x8CBF3C147F8694DCULL, 
            0x5229CC50803A4300ULL, 0xA87545F483B6A012ULL, 0xA7A9C7110E470A33ULL, 0xB430874271FC0444ULL, 
            0xFBE1BB96A0C5964CULL, 0xF0916823AD8ADA98ULL, 0xDE7C080A11B90FF2ULL, 0x92BAB3E492526120ULL, 
            0xDD9773F4F83B6E2FULL, 0xA0CCE06290DF775AULL, 0x907F2FFE1B4988B2ULL, 0xB81AC9808FBE2536ULL
        },
        {
            0x61ED276E962019E0ULL, 0x92B990FD20E7184EULL, 0x31A8501F23C45C4FULL, 0x46C3322F1D0C7E42ULL, 
            0xFA1392F94741D627ULL, 0x5240670A17626980ULL, 0xA4BEC125DFA00A9AULL, 0x52446EBCEC6DDD77ULL, 
            0x23D71DFD4AAD3446ULL, 0x32DAE59BBE64AC88ULL, 0x97768549B5C12B84ULL, 0x1D8677A1E8B3351FULL, 
            0x77F6A28E419192D2ULL, 0x2DF51F75CCDF11B6ULL, 0x826C765131F885E2ULL, 0xE3A756847F185A90ULL, 
            0xCA15135E1C530E57ULL, 0x5AAE52EF6628C7EFULL, 0x1343D515CC855656ULL, 0xCBF0F515B2CB9F25ULL, 
            0x50B493E6B169B347ULL, 0x0A1BE83547E5DB83ULL, 0x770106AE5EDDA9A6ULL, 0x76CA7EFDCD4AD77DULL, 
            0x076770662F052C01ULL, 0x927EC1E698089298ULL, 0xA0A83256022A7F4CULL, 0xD8110E16AFAFA500ULL, 
            0x90A8DC4EC4AB49A0ULL, 0x63DA28F51AE5405EULL, 0x31E4F16D6BC89D8AULL, 0xE3AE2C6D7DA6B11CULL
        },
        {
            0x7A0C0BEAF9CB7051ULL, 0x46B43F0B341117B4ULL, 0x5B3982BE9BAC716BULL, 0xFB478416B924633BULL, 
            0xD237672B919F661FULL, 0x2E0CA699EED823ADULL, 0x661C69598C7D1B1DULL, 0x7F1FDF7500B8956FULL, 
            0x54F9C85344CC9931ULL, 0xC0C8BBCF10215A21ULL, 0x90754DFBCB23B67AULL, 0x1089BD20115410ECULL, 
            0xC222349DA26C6395ULL, 0x75C2EE267824775BULL, 0x46EF562433824128ULL, 0xE247652E25DCF863ULL, 
            0x82EBFBC0FB322B8FULL, 0xC59773A2F2B34C70ULL, 0xAF102F0150192770ULL, 0x23A1111F5B93E368ULL, 
            0x87F981C76415132AULL, 0x0D6BDD06D7C55FD8ULL, 0xA72F795063CC9185ULL, 0x22ACA1B205704A37ULL, 
            0x03B180C6D4609AA8ULL, 0x6A60FEE65907DE59ULL, 0x84BC536D4DE97E5EULL, 0xFA59DEF34DE27153ULL, 
            0x55DC748D258ED82AULL, 0x53A736071270D0CDULL, 0x6EE86326B4BF0E19ULL, 0x0CE6A2F2F4051F58ULL
        }
    },
    {
        {
            0x72DF5118F4EC42D7ULL, 0xFEFF69936145C458ULL, 0xF6A0BECD10457F3AULL, 0x82089B0F2ECD08EDULL, 
            0xCF72216863BE9903ULL, 0x3481BBDC8BD0661BULL, 0x4345A84786F5C0C3ULL, 0xF62F0ABC3DDE1E6BULL, 
            0x4B239390C452E477ULL, 0xBF4171F3A3CBEFD7ULL, 0x21697D26B9505136ULL, 0x26A7F21D75B3F646ULL, 
            0xE570AADBEBC2B776ULL, 0xEC4CD717D371C8D8ULL, 0x1952729FD9AC2A6AULL, 0x9959E294B2B2EF5CULL, 
            0x263533333B695B19ULL, 0xF23D69D4E0462531ULL, 0x5CB80BBD461EE39EULL, 0x1D8B678E78AB5B5AULL, 
            0x6B5865E6A43E4183ULL, 0x920CED7A173395EEULL, 0xC48018BF570FA6C7ULL, 0x84C9139C62A26DEBULL, 
            0xE69D0420F979B566ULL, 0x4EA589614027AF12ULL, 0xFFFC5E06A9B6525BULL, 0xAC3A658683B8C854ULL, 
            0x5D9C4D1AB926E383ULL, 0x37B85EFCD738A94DULL, 0x48F9E85FB1531ECEULL, 0x111D9546DA809946ULL
        },
        {
            0x5131B7DF9A9AE9A1ULL, 0xF205F5F5229EF74AULL, 0x876C1A580D8896CDULL, 0xBA46E02BA90BF297ULL, 
            0xE85504BD459733F3ULL, 0x505998EB11FE76F8ULL, 0x4F7FB749A6F12181ULL, 0x5D365D5CC50D125BULL, 
            0x60652824B14E531EULL, 0x865BDFB94DC1EDB9ULL, 0x7CA11E91DD3EB3C2ULL, 0x2DA7B4094703B0B5ULL, 
            0x20FEA3D38064316BULL, 0x37134858EBC0EC0DULL, 0x64A1DC1B59E46262ULL, 0x27DEFEAA5F1996FDULL, 
            0x30E70E3B861F2D34ULL, 0x16CB516B3FC9FEB8ULL, 0x00A23A9EF52F653BULL, 0x5432C1C8729C2F0FULL, 
            0xF6B28FF9BA322FEFULL, 0x919686AD166C97E5ULL, 0xB886B6AF793C7BA5ULL, 0x56DC5C582D0E06C0ULL, 
            0x64BD1E9046FB8BC8ULL, 0xB77D9FD214D0F9B3ULL, 0x6AD408EE377B8BF5ULL, 0x86AEA08241ED5BADULL, 
            0x576C7F62B79A75E6ULL, 0xC7F4CA4B43CD5826ULL, 0x6B927682A1E3F494ULL, 0xBB0FF0E9CECF114AULL
        },
        {
            0x595BCB6D4F1260BFULL, 0x362713031D02C4ECULL, 0xD36E7D8D73A8202CULL, 0x5E67F35DEF286AE8ULL, 
            0x7C41DB3A135A0E55ULL, 0xD98EA4CFBAC4029FULL, 0xD8F4443D0ADF2A0BULL, 0x521D875A4D2C2BD2ULL, 
            0xAB2D10EBE245A7E2ULL, 0xD3C988DA30DCB154ULL, 0x0937D6B0E6282887ULL, 0xC8FBCEB29C5F4CC9ULL, 
            0xA792FB40CEFAE16AULL, 0x555C73D9CE9EC311ULL, 0x20EEACADEB741D05ULL, 0xC4875659A80EFA0CULL, 
            0x32EF601F95C46198ULL, 0x439F8FB32E85BDFAULL, 0x760013BF00526064ULL, 0x16F29264C47F6487ULL, 
            0x4F2C4C6E26F9F335ULL, 0x9914ABA2CC1274F4ULL, 0x4785BC9BF5052E00ULL, 0xA03F5E859E5AE9F1ULL, 
            0x0B7E571F0FC524A7ULL, 0x4C45DC68CE2E251DULL, 0x86984EE154D35D41ULL, 0x9B249521DDA00BC6ULL, 
            0x575FB75E1E28817AULL, 0xDC7DFE91B18890BFULL, 0xD5C4B355DE345FC4ULL, 0xEC189949A7F7C379ULL
        },
        {
            0x5D98610782F95791ULL, 0xF3D936A6ABBB48F9ULL, 0xC8F15A3B4A0B3608ULL, 0xFBB9B0FBEAC01969ULL, 
            0xD1DF9CDE633B29AAULL, 0x58DFFA51DC871666ULL, 0xA762ACB05F1B9D02ULL, 0xC5203B8D5FF6B098ULL, 
            0xDEE122C4084CCAF6ULL, 0xD3474C4CD94A362EULL, 0xAD3FA944B78CDF5BULL, 0x3784FA7311BF1DC5ULL, 
            0x3CA789C39A57BDB4ULL, 0x83002DE87F48AEB7ULL, 0xC97E2A86717A6D0DULL, 0x417BC1BF2AF3312BULL, 
            0x5061239907B36D67ULL, 0x3CA9E07467DD2B9BULL, 0x450FF4016DD79781ULL, 0x151F134D1D408A07ULL, 
            0x99E020C3079E6B4DULL, 0x72AD532439690E1BULL, 0x91791B6B11751F7AULL, 0x0668A9449A6B27B2ULL, 
            0x783F08884AB39958ULL, 0x5B7A49A212859FD6ULL, 0xF6EA387B317FF221ULL, 0x95BE63A1BB4EF62BULL, 
            0x99589B9BA4493F31ULL, 0x32C9821943299BECULL, 0xBA93627A24CC7773ULL, 0x7A2F96E7708A7F52ULL
        },
        {
            0x579CDE1C9F35ACB7ULL, 0x46A8F6DC9CEFC3FEULL, 0x26D431C95DFA642EULL, 0x67FF6034485BEB76ULL, 
            0x9DE913C2252A148FULL, 0xF4F8B874C3B91F32ULL, 0x40EB73940CC19395ULL, 0x3AC881F3C1F48B86ULL, 
            0xA8619A7290784175ULL, 0x56C7D719EB592759ULL, 0x448755569BA472A5ULL, 0xFA6D93F5F14FD68BULL, 
            0x1F7CF3A0074483E8ULL, 0xF70F357DE4BF4B75ULL, 0xE9109933FC538C16ULL, 0xDE975F9CB8815C1BULL, 
            0x16AE7FDB0F634F7FULL, 0x1A6A5EC2B8E752A4ULL, 0xAFA8C062F370AD2CULL, 0xB58267A5A70A7235ULL, 
            0x89B3ED6988A60E5AULL, 0x42E09E7DD0E2F990ULL, 0x66C3CF892BCCD04BULL, 0x8034EF4F673BD331ULL, 
            0xC2F9FCA87DC2451DULL, 0xB0CB58F7C2886FB3ULL, 0x53996683DB8D308DULL, 0xAC9DC93A9E10FD05ULL, 
            0x9689ADF6054C3CCBULL, 0xC367919E865F24B2ULL, 0x0CF528A7DE48A242ULL, 0xA370D88006B5E0C0ULL
        },
        {
            0xB2944FDC0E7D116BULL, 0xF7EA1D7C2EE4614EULL, 0x9D2D0ACDF56BD6CDULL, 0x3A134DDC323CF0DCULL, 
            0x8D15CEC792555F20ULL, 0x0F34B1454BB0FBBBULL, 0xF73780AB709F9817ULL, 0x8D517B77CB93ABF5ULL, 
            0xE7BAE9DA7C04D996ULL, 0x3456D9B130FBCCFDULL, 0x795EB6A54891219AULL, 0xAEF6D4E3AB26349FULL, 
            0x674AB10D5B25103EULL, 0xCDD5AB76B4737804ULL, 0x1FBFE80AD08672D9ULL, 0xB4E6FBE210A177AFULL, 
            0x1AB9025DDF92AFC6ULL, 0xDB320C40D29F92DFULL, 0x9860DE4408BF5379ULL, 0x10D85DF82BBCC2B1ULL, 
            0xC88071E6B6DC54F9ULL, 0x923225DE377ACEFCULL, 0x1154E4F9F5E3F072ULL, 0xDE2BFC28720D13CDULL, 
            0xD40B3A5A09681F63ULL, 0xF04A1AB57F8C7D66ULL, 0x81C0B68B103F8552ULL, 0x0A3B7D8F67EE0F4DULL, 
            0x832E7A0A3DBBE35AULL, 0x4987EDC05AB69A8EULL, 0x663720DC50E1E7D3ULL, 0x69634F0C3096FF1AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Antares::kKeyRotateAConstants = {
    0x4CD18D31F8BF6280ULL,
    0x826A025F4632855CULL,
    0x3AD3D8F80A5E2937ULL,
    0x4CD18D31F8BF6280ULL,
    0x826A025F4632855CULL,
    0x3AD3D8F80A5E2937ULL,
    0x685AA6FA25344A7AULL,
    0x31876D818059DCC9ULL,
    0x2A,
    0xCC,
    0x50,
    0x8E,
    0xD4,
    0x1C,
    0x20,
    0xD8
};

const TwistDomainSaltSet TwistExpander_Antares::kKeyRotateBSalts = {
    {
        {
            0xD3632201D19E34D7ULL, 0x81DD50CB16983809ULL, 0x6A6589D41EC02891ULL, 0xB40E3D76CE53C4F6ULL, 
            0x87E4C78B3B8E48DCULL, 0xCDF6C3D9D9A56461ULL, 0xEDE5D3388A50CA2FULL, 0xDC008397940A25F1ULL, 
            0x6831A191341256E4ULL, 0x64AACF68725CFC79ULL, 0xC19AD959EB89064CULL, 0x07CDB6292125972BULL, 
            0x9506C435555CDEBEULL, 0xFFC03476E88DC9CBULL, 0xD72CA2E86CD3F1A8ULL, 0x3CA85D377649D3ABULL, 
            0x1C000BFB369F32E6ULL, 0x9336938B30BF2368ULL, 0x1B76913EF36CAF11ULL, 0x6D6DEFCD7678ECE1ULL, 
            0xC5AD8D6FFA34CCBFULL, 0xB22FFBAE3F6D851AULL, 0x70636FAA2911661FULL, 0x72EEEC9C96D900ADULL, 
            0x710F23421BB34272ULL, 0x586FAA625729AE4BULL, 0x68DD1EA526041BE3ULL, 0xD00DD2E131D0F9CBULL, 
            0xA918AE56FB6AF736ULL, 0x24B42D69E193BB6FULL, 0x9C9C6478287B7F2AULL, 0x6B410790012F7939ULL
        },
        {
            0xACB23EFC8F1BCF2AULL, 0xC741FFB86C8DB2E1ULL, 0x16F4D3B5CAF48316ULL, 0x87F8A52F6B93C4FFULL, 
            0x84C3009A2590742DULL, 0x4B0B871BBDBEF911ULL, 0x517717F6353F56EAULL, 0x5AEE369A4972E705ULL, 
            0x6D3D8F126246B32EULL, 0xC9C84BA4212644DEULL, 0xE7C6D8FA1A5170A2ULL, 0xD36E77DD67095201ULL, 
            0xE8E87CAED8271B27ULL, 0x382329E41764C778ULL, 0x7A58D38B57B40CDCULL, 0x7E1D922B23470B5FULL, 
            0x3F59D11DFF534D7CULL, 0x6283A424BC603539ULL, 0x7E538A0F947CB95FULL, 0xD31919B02CDD61FEULL, 
            0xC8134782D9FD43C7ULL, 0xAE783583797C0168ULL, 0xD3EF3F316700CDC9ULL, 0x6409936B18F791B3ULL, 
            0xF71820BF7910EA26ULL, 0x3B0A126A8226881AULL, 0x016C2D574149A27AULL, 0xBAFA114EAF38E875ULL, 
            0x7461E934B51A4E54ULL, 0xA096BFB92DBB9EF2ULL, 0x31AD05F3E650F158ULL, 0x8CBE893CA3F9D2BCULL
        },
        {
            0x9B522094FF82C7FAULL, 0xB62D157F13858CA3ULL, 0xDD4FAA84B5054456ULL, 0x8FDE641818986EC9ULL, 
            0xD80DAA559ED66EF2ULL, 0xA21695D51E50A11DULL, 0xDBFC3E56558EB2C5ULL, 0x0B2F5A450145B7B1ULL, 
            0x939AF8513DD7A5CDULL, 0x31DA3B6396E686DAULL, 0x99D1A5F20E7CC55DULL, 0xE0EC52E518AFCF52ULL, 
            0x658168ADF35FFEBDULL, 0x203B93DBC4438CC0ULL, 0x9A4E82A53C1A17A1ULL, 0x3E1244917DF7D210ULL, 
            0xCD768579659F14E5ULL, 0xAB09DD8AD93FF047ULL, 0x6D2C466F2772F0CDULL, 0x2AA65E9BC8B4200DULL, 
            0x16CE3748D47A6287ULL, 0xFB747FD03ECF780CULL, 0x0AD66A543D14916CULL, 0xEE31C0C9F1FC2262ULL, 
            0x706166006E7FC8C2ULL, 0x95D6C3F199ADC028ULL, 0x3A40DC65E2843D45ULL, 0xADC0DAC9133E6760ULL, 
            0xB3A97D5D891F7197ULL, 0x58DE2B7BEB31FFB3ULL, 0x020AF34CA628B67FULL, 0x2A3250669C7464D8ULL
        },
        {
            0x6D570F76A9C6B85BULL, 0xA98DF630743A2874ULL, 0x7EA4B722E516825DULL, 0xD412BB926237880EULL, 
            0xA68B3B80125CFC05ULL, 0x204E75EA7CDA5CD2ULL, 0xF2111D5FF26A1801ULL, 0xA14D6326756B86F4ULL, 
            0x458EDE54A3F40AE0ULL, 0xCB552C988E6C2641ULL, 0xB0862C0C88738E5AULL, 0x49624DD396A3BEBBULL, 
            0x201603A29E5F9EAEULL, 0x74E127D190FFD91BULL, 0xB475C7D5A6781B8AULL, 0xFCF59E26EC2EB713ULL, 
            0xCD41BEEBE0C74DA4ULL, 0x616FE6FF662E7451ULL, 0x0D0714D27C664DF8ULL, 0x867D0F0FC609A04AULL, 
            0x23765F23FDF21F2AULL, 0x440FEADE24FCBA4AULL, 0xE30F63D2475017D3ULL, 0x1043E00C8A941FEEULL, 
            0x5D1887496A3210FEULL, 0xF2A144BAC6D1218EULL, 0x51001C7F44249B9FULL, 0x5C8AD1204798E3DAULL, 
            0x8DA01700CAF9A4C0ULL, 0x7B4CE11C7DB144D3ULL, 0xF1CFF7A9533B7F3DULL, 0xB54871081DC7338AULL
        },
        {
            0x918D637A0179DD9AULL, 0xD40AA0E7EF8DA797ULL, 0xA303D1F4EC31965CULL, 0xB6640B79D2F9FE3DULL, 
            0x01B44D3CDD722E4BULL, 0x35FA1AC9EC31493FULL, 0x21FDB07BEFB872CAULL, 0x6D1076DB082F9298ULL, 
            0x84CF3DDB7E4E4A6BULL, 0xE3A3FC7EF443FBA8ULL, 0x06F08E63926D0A9FULL, 0x12EA2EA7F5FF2C07ULL, 
            0x312493E38B02E23DULL, 0xB82D7C63B8FE82E4ULL, 0x629EFD655D581A86ULL, 0x68572B1D3E9ADF8AULL, 
            0x6958989842A6BC67ULL, 0xB2BD31B09DAE2710ULL, 0x79B9C07AB2F4209AULL, 0xC0E5FEDEFBB09F0EULL, 
            0x81F927015321E40EULL, 0x64D8F7D4B87DC25FULL, 0x2AB1DAE71BABB588ULL, 0xEE80459F485E920DULL, 
            0x03BE2D51B0CF630CULL, 0xEBDE66891944BE72ULL, 0x2CD4DEC747F790C6ULL, 0xC50384273A365EABULL, 
            0x8A01CAD03CB3DDCAULL, 0x9D7AB711CBC260CDULL, 0x6B9BBA9F4E1F7BD5ULL, 0x35C3432FD234FAA9ULL
        },
        {
            0x1B7C1DF2E8F9DA25ULL, 0xD3B21C73CDD12A30ULL, 0x8FADB5EE64DF773BULL, 0xA3A352E7913808CEULL, 
            0xEA7A68ACCCEC3D59ULL, 0x45F0664958A59D72ULL, 0x044EE1134E59CAC1ULL, 0x99A43CC9FEEAF7E7ULL, 
            0x652030C37A7651F2ULL, 0x617361C8213DAC39ULL, 0x88DC14243AEDBE7AULL, 0x048B0B14181FE5F5ULL, 
            0x63C41A3E63F71DCDULL, 0x4E902187CDB073E1ULL, 0xEE78EC06B89439C9ULL, 0x169B28543C5EBD59ULL, 
            0xBDF5D4DF10929069ULL, 0x00F6B30922DFEC2BULL, 0xFA312518336D471EULL, 0xBED8C59FB68A5FBAULL, 
            0xBADE0A810564B6B0ULL, 0xA7AF04C57C3A9505ULL, 0x01506FF15317D2F9ULL, 0x93F5C24FEB7ECB0AULL, 
            0x6C3E1ADF6AD1FD72ULL, 0x87F93D914DC2FC25ULL, 0xDC4DB5427DC7ED51ULL, 0xFC40B2EC16D43802ULL, 
            0x93550FA0D2EA5E15ULL, 0xF8555C1855CCD8FCULL, 0x2DC466E37B1EB211ULL, 0xE55EA984226E36FBULL
        }
    },
    {
        {
            0x3A92E01235382371ULL, 0x5DB24E037E95C24CULL, 0x0FF34C91A1A78821ULL, 0xD45E55DAB0778861ULL, 
            0x8ADACF9FFEE4C7ECULL, 0x82B5E2E4B8C68221ULL, 0x3E8B2C069EC3625FULL, 0x292F7710C159A631ULL, 
            0x6B05308FE5370023ULL, 0x53FADD0A3CD11FA5ULL, 0x33BFFD725E20665FULL, 0xAE7E258ED2367471ULL, 
            0x305287CBFA45D50CULL, 0x1645EE550E165C69ULL, 0x8E856CDA6B523B28ULL, 0x4AD5CDB0F00A3A16ULL, 
            0xF24AB35666567B27ULL, 0x9CDED8FE627947C7ULL, 0xB9372829C7BD6F8DULL, 0x4B315636DCB6F3C8ULL, 
            0xB4F0FDE2647B9046ULL, 0x230A7491B7BB2C27ULL, 0x83F88CD85390DF87ULL, 0x2C763272C6F41949ULL, 
            0x0FB20FC8F88DE701ULL, 0x9FCCAF6144E5AC8EULL, 0xD2DC2C6D655935BDULL, 0xE4B9FD708497CC6CULL, 
            0x244A16FD34E22938ULL, 0xCD2C4837E311E46CULL, 0x1FD014E14678DE41ULL, 0x5A8FCE861BF5DB3CULL
        },
        {
            0x84520790F850CF0DULL, 0x286876ED078BB418ULL, 0x985D21C724F658D0ULL, 0x4776C6256B17F38BULL, 
            0x8F3BDC0EC32288F7ULL, 0x324B0043F25D91F1ULL, 0xAEBC7F1370A7022AULL, 0xCF9028D8ECDA01CBULL, 
            0xDA2C43D2188C330AULL, 0xC1FC55E47A77D017ULL, 0x5D7BA3E64F593D7CULL, 0x144BF69269864A4FULL, 
            0xD7EDC33FEE36EFB9ULL, 0xDCDF2179EB0D768FULL, 0x6F07865C9C85272AULL, 0xA1BDB9E45456F14EULL, 
            0xD0B038B23255F019ULL, 0x9F845D7A73580443ULL, 0xAC1EFC29976913E9ULL, 0xFC74D57179C531EBULL, 
            0x32E7757F10BE6D97ULL, 0x074CB86CE6B4F3B0ULL, 0x3EFB5855E06663B1ULL, 0x8036AD0EBBD25E7DULL, 
            0x3E46B9ED7FA9DBF5ULL, 0xF0849F271A3E562AULL, 0x4AF76F82001D7A2CULL, 0x11B6915809896D76ULL, 
            0xD2F552CF8FB013E6ULL, 0x9AEDB52AD69A5D07ULL, 0x9A11B5A465B7AF74ULL, 0xC951DBBF0B57CA2BULL
        },
        {
            0x61E9E995F912E4C1ULL, 0x7C2195671FD8C774ULL, 0xF139E1DAE9CCD35FULL, 0xDCDEBBE0FFFBE104ULL, 
            0x88CB1083647E2D9FULL, 0xDE221A9AB10F8127ULL, 0x0949E4A8DFFFD3BFULL, 0xDA927DB39A3AE319ULL, 
            0x4F03635D5E34744FULL, 0xE029A682D4C6466BULL, 0x926C44F4088A05A2ULL, 0x0C2E27CB2BE1D9C3ULL, 
            0x3775B4B6548918D7ULL, 0xAE48878A14254CD4ULL, 0x1E4A25BEB94E65A9ULL, 0xB037B72B9D04DA78ULL, 
            0x989087617B576D74ULL, 0x1015814A929DEFE2ULL, 0x056A342E293E6906ULL, 0x772022D8D069B84CULL, 
            0x6C40BE47720D2276ULL, 0x5B915692621A1620ULL, 0xAC8B70041AFA4FB7ULL, 0x91772E4582126BB9ULL, 
            0x912F6CF184756EB6ULL, 0xC65D7755A225945EULL, 0x22BF544969525C00ULL, 0x67FCAA58A8F56D1BULL, 
            0x8FCD54645EE0DC7EULL, 0x19BAA1DB9B780DF2ULL, 0x6364F23C890AE591ULL, 0x5463F553457DA65EULL
        },
        {
            0x9FE47227B8FE15FFULL, 0x2A5D2C03E0AF4012ULL, 0x69241BE67273AE60ULL, 0x9B961BB2502ED915ULL, 
            0x8308B876A40B595CULL, 0xF4F3AB20E345D956ULL, 0x2217ABAE75901F83ULL, 0x369586E5504F3597ULL, 
            0x10B79D5ACCDEDB39ULL, 0xF02899CB69AB2463ULL, 0x400D770DD760C241ULL, 0x67801F6A867C0C4CULL, 
            0xB692ACA2B3DF927FULL, 0x2DE8DE7B7BE717D8ULL, 0x41D874B52D551213ULL, 0xFB4C1AE27C6591E4ULL, 
            0x17D3F824FA7159A8ULL, 0xD270A38A9F4E8A9FULL, 0x54B6900F4D050066ULL, 0x55CF267FCED9ACFFULL, 
            0xAB9E465EAF64A8ADULL, 0x3400561B4E6AA2C1ULL, 0xE9B9E9ABB0EDEDE2ULL, 0xB87B9ED5D73DB4B5ULL, 
            0x03B7D5CE91806567ULL, 0x20EA648A501BFF4DULL, 0xC740C017D8A47D9BULL, 0xCD6D698E6FF4BDC7ULL, 
            0xCD282AC9D33FC518ULL, 0x05E35FBB478A61DDULL, 0x07A110CF7DB3B2A9ULL, 0xEBEFE8D05EC9DEE3ULL
        },
        {
            0xD22E613FB51BAFCDULL, 0x9E4ABAD6144F64FAULL, 0x300C7A148AF4B755ULL, 0xB8F48415A6FF05F7ULL, 
            0x0BEC33E0E2AB6AE7ULL, 0x208D9D91F897E937ULL, 0xB751844A28C4A28DULL, 0x32B146A7A0A23D2CULL, 
            0xC2B923F79A2A01EDULL, 0xE808E9516B62A4B9ULL, 0x1105869841179F6AULL, 0xC35B7FB7A1EEE5ACULL, 
            0x93243E6C19B3F6C9ULL, 0x108C021E376AEA6BULL, 0x67F310FE4895A99FULL, 0xB5189201D3F1850FULL, 
            0x0DBB16FE8B92827DULL, 0x4FCDA5DD38B9F2BDULL, 0x06EE30AFEC7FAB12ULL, 0x7363230835F72A83ULL, 
            0x4DFB1EA5E66A5397ULL, 0x7106E7AE06E8A08DULL, 0x0C7E2CC25FBDD180ULL, 0x897FA60F7ABC57CAULL, 
            0x65DA9B8574F106C3ULL, 0x7A313FC363E7ED9DULL, 0x56BC73317E4B6EFBULL, 0xA8631244D1FE3CFBULL, 
            0xD58CEAE31BFAF15DULL, 0xAAF5B55251FF4019ULL, 0x08E8EE556267467BULL, 0x59914A218188C35AULL
        },
        {
            0x0D48AB5CE4C11F24ULL, 0xC144D64EDB0FF045ULL, 0xE880A422E14E2E6FULL, 0x79BF7BF7A9E8DD38ULL, 
            0x8B67C8352893A86DULL, 0xB23746D051508E41ULL, 0x41B9429362F822C8ULL, 0xFD153553D62E54F6ULL, 
            0x0925DC9CCAD348E6ULL, 0x8EB6B51DB1F03747ULL, 0x9C322EA934997501ULL, 0xB47C3E5F07B80F8AULL, 
            0x980C3E1610348C64ULL, 0x9BC4BB5EAA98453FULL, 0x2D80B4B95EF065F9ULL, 0x20D886BBCD6153ACULL, 
            0xE51B680F3CBF364EULL, 0x515AF7F96AEA3D1CULL, 0x895C831BC5C0BBBCULL, 0xF4388FBE5E2EBEF5ULL, 
            0xBE3F8A7084E3D991ULL, 0x772C5D3AC139AB91ULL, 0x183C0298DC21A4ABULL, 0x0124B5F6141784F5ULL, 
            0x3F465FF02D763B91ULL, 0x6555988C7B3681F5ULL, 0xF1119CB1BFFEAF6EULL, 0x7452FC7E19CD3041ULL, 
            0x149F9A3FF8780BBBULL, 0x7C9FEE308C36633EULL, 0xDB8EC11507E6D362ULL, 0xA6A7E695A4748D6DULL
        }
    },
    {
        {
            0x67AD35E3FE5B7AAAULL, 0xBB310E6D236E9CDEULL, 0x86CB65A8E837042CULL, 0xCBF3DEC6B686A4B7ULL, 
            0x1FAF76883CFDC9CAULL, 0x66B5558283333476ULL, 0xF3BF9BB619B8381BULL, 0x97EE404EC6D1E40CULL, 
            0x137F9D0A0566A99FULL, 0xFC5BAD227240236BULL, 0x52B746A403BCE510ULL, 0x601B8798EE5FC280ULL, 
            0xFEB9E5B1FD86A796ULL, 0xE919712CA699CDA1ULL, 0x92768C417F508FE5ULL, 0xB55808644BB934A8ULL, 
            0x1691005095077E49ULL, 0x927588708032A53CULL, 0x74C0EF5A4029AAF5ULL, 0xEA12B7971BB7C8E7ULL, 
            0x173D0A069E54D524ULL, 0x3B9D928EF595B300ULL, 0x946632C7892EBD8EULL, 0x676D13F8FE7DBBAFULL, 
            0x6BA9DDB44A35C799ULL, 0x7516005E859CF943ULL, 0xB126A68540E1A8BCULL, 0x66AE6AF3C98EE376ULL, 
            0x2D1D0CB7C3192A5BULL, 0xDC880D4ED961770DULL, 0x3C4A9B35A71D5D98ULL, 0x1E0190A4DA08CB36ULL
        },
        {
            0x2CE87032B05D130CULL, 0x3D4211E7E2C87DCAULL, 0x41E8AB15E84123D7ULL, 0x1C39920DAD5E77E8ULL, 
            0x56C2993F6D1689CDULL, 0x98FC464966B49D1EULL, 0xEB7B3B92934E9C5EULL, 0xDC5F29BDF9652404ULL, 
            0x69FB2A731946BEDFULL, 0xCE5016C86DBE6795ULL, 0x4DD03CAD75681F8FULL, 0x15E54130C722F006ULL, 
            0x6231F0B11B267B13ULL, 0xF73B0CAEEB4BA2A6ULL, 0x5DA30EB9DF3418BAULL, 0x684A93F7F4CAA384ULL, 
            0xD76308E5A1FA4656ULL, 0xC3ED7E1F801C9E69ULL, 0x20D6C3B03BF0A7E7ULL, 0xA649E3C76B23490FULL, 
            0xE8141AD5DEE1E66FULL, 0xD126A563D5E7EF18ULL, 0x273A66413CBE46D7ULL, 0x01B0FE3CD7FAFB2BULL, 
            0xE0EDEAD5198D172CULL, 0x27C5CE5382C5C3FCULL, 0xF1C597B32102C245ULL, 0x36B137B5351118DDULL, 
            0xF09029ED7447AA05ULL, 0x64217DB47352232EULL, 0xB61401EDC80C7CAEULL, 0xDA9934AE3AF55DDAULL
        },
        {
            0xEE16229D7CCD53F0ULL, 0x13C20969C78E01AEULL, 0xE052EC75BD9FA588ULL, 0x444CA26F43C5BAC3ULL, 
            0x2F88B96900AF066CULL, 0x55FD17CF75C6D4EEULL, 0x9B88B0A40AFCEE90ULL, 0xBEEA716FFD2D2F45ULL, 
            0xEEE56C564DE250B9ULL, 0x4DAA4356BF3086CDULL, 0xE731AC39017CDC05ULL, 0x43EE083C0BD96969ULL, 
            0xD449FFB8D1E31356ULL, 0xCE03DD1CA3F22CBAULL, 0xA9FE5540F4D1F37CULL, 0xF3442CC0106168C8ULL, 
            0x55FFB8AB65EAAA65ULL, 0x313FF71D9F092980ULL, 0x19D892B8E2B29139ULL, 0x7A3405B80140A27EULL, 
            0xC6F796EE128539DAULL, 0x88AABAA412B9AF32ULL, 0x04BB4243445A6600ULL, 0x17BC6C0F73D575C4ULL, 
            0xE5604E47338A602BULL, 0xCA79F8D941DA2FF1ULL, 0xE68B1F1B4A30B547ULL, 0x73EFE2C0A2486ABBULL, 
            0x547DC19FA109E8ECULL, 0xBAA89F23978A8DBAULL, 0x32F7C9D683203E69ULL, 0x70BF1F7BA511AE75ULL
        },
        {
            0x7159AB9DA996EC6BULL, 0x75C31669D6D7BB31ULL, 0xB0F92CBB5435CD0FULL, 0x874658A197C9D964ULL, 
            0xDBDBCEDFB9FA8712ULL, 0x2E1F38032E6A0B4DULL, 0x2E279DA7727FAFE1ULL, 0x77107DD54E0F5C97ULL, 
            0xDE6F97AD2FDAE2BDULL, 0x46FE91FF93F429B9ULL, 0x96E688709EC8B743ULL, 0x2408E611AD7753B6ULL, 
            0xCC12647939EEF3D5ULL, 0x5C6A04861A811C94ULL, 0x192F1E27040412CAULL, 0x3980F7154597B3C0ULL, 
            0xAC4A4C5673CB4E76ULL, 0xD2C19D368925133EULL, 0x027A0A55AD6E523EULL, 0x71EB9B98487D34DFULL, 
            0x5BCE3243B84FCFB9ULL, 0xABFB98C23A26D1CEULL, 0x3D2B82DFF7B4461CULL, 0x384553E426F4F300ULL, 
            0xED0C884F9C8731F0ULL, 0x228D2EE00B68433BULL, 0x87DE8E6AD62619FEULL, 0x08B4E58641F5C758ULL, 
            0x7DBA175FCDC017D7ULL, 0x1AB0E87E36ECB126ULL, 0xDC33F2B9EBDA9A49ULL, 0x7609E6E569BBF599ULL
        },
        {
            0xEF06893ED9AD5BBCULL, 0x81B70AEDB1E4BBFEULL, 0x3957F524042FBE97ULL, 0x5D7B312809EA75CDULL, 
            0x093FAFA37B0AA791ULL, 0x325FF469A53AA46EULL, 0x19EAF6886DC72934ULL, 0x7CA97456436783B2ULL, 
            0xB853CE43E013709DULL, 0xE70C4F8B10F13B7EULL, 0x4CB7CDF9ABA08000ULL, 0xE60AC8DD875F4363ULL, 
            0xEF59B9B3E008D554ULL, 0x387A9987EF92E810ULL, 0x29590CB3CBF3141AULL, 0x5309FD7D37131ECCULL, 
            0x786A0B790D4C85A5ULL, 0xE1E7D971C635DBD2ULL, 0x8532F53CAC3B8794ULL, 0xF0C21EB4E5AEB8E8ULL, 
            0x42E8934596035576ULL, 0xF4F83A7CE97E9659ULL, 0x8BF3F4BCC2800AF5ULL, 0xD5D2C430F890DC4AULL, 
            0xF25A7F9B57BD3B2BULL, 0xA59FE7F8EF68F40AULL, 0x2E565B9C6885B69CULL, 0x58AD74BBE05147E2ULL, 
            0x884AE4D912EF1D7AULL, 0x801D098F2D054A40ULL, 0x65C61A1BFA95B18BULL, 0x6921FFAB9BD3DA75ULL
        },
        {
            0xAB1293749899D8E7ULL, 0x8EA22E8B85427D03ULL, 0x98A1AD6D1B24DB1CULL, 0xD28E8EF80A764A99ULL, 
            0x8B7C34F3C48670DEULL, 0x0C51D9A9115D5434ULL, 0x6DE7A2DA52B7F5DDULL, 0xCE5200E5EEDD2298ULL, 
            0xF2AA35D1C1DCDC32ULL, 0xB4505D80A4B18FC5ULL, 0x6B30162BA45AF606ULL, 0xD6D14441C345F520ULL, 
            0xA66413DD18F6CC81ULL, 0xCA8956FC4C300E4CULL, 0xFCAA7D4C3BD874D9ULL, 0xD45E00EFCE2E4471ULL, 
            0xEA7A7496AC35CADFULL, 0x440CF5C3F5E13C31ULL, 0x9BD781D0CD36EC78ULL, 0xBE61050621A6E796ULL, 
            0xAC78945D58511941ULL, 0x0F34962B3EF6A99EULL, 0x87D0B0B123A01DCEULL, 0x8CD7C3409D3B6262ULL, 
            0xA5CC9B20DC4F4B5BULL, 0x1AD838E361F51F66ULL, 0xE7F3ED87AB9A972BULL, 0xB52A25B3251E7614ULL, 
            0x30D2579EB2282207ULL, 0x57911964B56547D7ULL, 0xCF6269FBCDFE2F84ULL, 0x2E19843920FDD04BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Antares::kKeyRotateBConstants = {
    0x8B09AD2529CA7D81ULL,
    0x5FA5C6D613222F22ULL,
    0x066CFA13D7837684ULL,
    0x8B09AD2529CA7D81ULL,
    0x5FA5C6D613222F22ULL,
    0x066CFA13D7837684ULL,
    0x2DE7B4612669B430ULL,
    0x7E47A6D971D5890FULL,
    0x74,
    0x3E,
    0x80,
    0xEA,
    0x4F,
    0x34,
    0x5A,
    0x1E
};

const TwistDomainSaltSet TwistExpander_Antares::kKeySpawnASalts = {
    {
        {
            0x61BB1FADF78C00F7ULL, 0x6C675BF1402DECEEULL, 0x658BF1B79F643F79ULL, 0x58216EBEF2060BE6ULL, 
            0xB0CA34A16F57DC9BULL, 0x57E68FBC81D2DF1BULL, 0x670515CDE7AA89F0ULL, 0x8FD72B8B8E78C845ULL, 
            0xC680AD36A8BA085FULL, 0x5D418274FFF12673ULL, 0xB7FBBE40A9B084CBULL, 0x6ABCC34B07AECE77ULL, 
            0xB3629EC5F7FE21F5ULL, 0x7F92B55FA13C2089ULL, 0xB3460B4F9F45B9A8ULL, 0xED531E9C563C38C7ULL, 
            0x1CAE9B1D0A7E4318ULL, 0xB52C0D302CC198FCULL, 0x6C75EBBB3B9F25C2ULL, 0x2B51CFB3CDEC3196ULL, 
            0xDE9375980A6A3C15ULL, 0x6129D9FEE3B5365EULL, 0x9961948FF9EBC979ULL, 0xD4A515CF12E79E73ULL, 
            0x44ADE94FF7D2B4D7ULL, 0xE471E344F7AE8331ULL, 0xCE89F10128B17C06ULL, 0x7CEF6D55E93289E3ULL, 
            0xD523C50A8624DC06ULL, 0x3DCEE8A8AF488E9EULL, 0x0F0CF5740F1FB4A5ULL, 0x42B451186306F791ULL
        },
        {
            0x5B926FC0C8CB9BCFULL, 0x9F75A9E634A08566ULL, 0x3FA52F22D322B4DEULL, 0x9BCAEDB15746F505ULL, 
            0xA86F62011578E39EULL, 0x934D195A56C2E19CULL, 0xB3B755144A6BA49FULL, 0x1A1DA255ABD1DBB7ULL, 
            0xBDE9A3777FFBC853ULL, 0x8ED901B35481A973ULL, 0x608E35FDC7AA1002ULL, 0xE0A89A69521211D2ULL, 
            0xD995DB727E7286B0ULL, 0x56E9A789EFFDF10DULL, 0x387120FB66720632ULL, 0x31B10358D92E8A00ULL, 
            0x9ECC73D8855EE235ULL, 0xC8F4ABF6A063D886ULL, 0x0B996BE49B54ADE0ULL, 0xD342FBD9998EBDCBULL, 
            0xE6C2B366AD4EDC72ULL, 0x7E5F671161BDFAD5ULL, 0x8071C70CCD22EE60ULL, 0x5FAEC1C777A9EDA1ULL, 
            0x4CFD41818658E0C1ULL, 0x6F7E68CC1C21B034ULL, 0x0655937C736FCBEDULL, 0xB6923489CAEED907ULL, 
            0xDD679D568645935BULL, 0x20AA0DEB833D4DE3ULL, 0x8BA4A9192C49EE7CULL, 0xD54A86928F1DC409ULL
        },
        {
            0xADA723C2C970A2D9ULL, 0x7DC36D3185F6CFD5ULL, 0xBA4015E55E40E491ULL, 0x2562FA808B450AF0ULL, 
            0xE084A1139D774C16ULL, 0x04C5FC6BC5AE51BAULL, 0x7DC7CCE089031092ULL, 0x14CE08933785250FULL, 
            0x68420947D7ED54BFULL, 0x8B67650ACA06C3E4ULL, 0x9205CA95C03113C3ULL, 0x597ECB5A31F108ABULL, 
            0xB179E4B50FEBB6A8ULL, 0x927456994C232789ULL, 0x436DBAE1D3D8962CULL, 0xD1094E19171DFDC9ULL, 
            0xB400D7A1A48B4123ULL, 0xAED265E399EEF1A3ULL, 0x413CDA35FDB2F60FULL, 0xC585ED4C6E07AFE2ULL, 
            0xB32A2AEF87A5CDFDULL, 0x37597E05FE8C3D7BULL, 0xB8202F46EC36B437ULL, 0x6CA0E9F065652B8EULL, 
            0x7865FC8DA20B58D3ULL, 0xE01EEED2C8827176ULL, 0x9D8BBA430BCE6E28ULL, 0xD8F94248627F4D55ULL, 
            0xFEC028BE2B361E2EULL, 0xC69CD2DF87EEEB1FULL, 0xD2E9D768BCA84E8AULL, 0xD082A7DD9A6E61E6ULL
        },
        {
            0xFF9E8EC90AE39F85ULL, 0xEA4690940DACDA39ULL, 0x6F555C4426A118ABULL, 0xD35900FD58C20F6AULL, 
            0x27628432E2B1A8B0ULL, 0xC2098E6E3D483717ULL, 0x5B854BB24B668913ULL, 0xAAE374B6D78A8944ULL, 
            0x6DAD5E1B7C2593C5ULL, 0xE6455228FC65F2D2ULL, 0xA051B3A952291A30ULL, 0xC69961E6F7BA025DULL, 
            0x535DABCCD3C5FCF7ULL, 0x629065AAE848D577ULL, 0xD9A834EA28B3D215ULL, 0x0CC750A747F8258FULL, 
            0xE5D7AD6C83073538ULL, 0x40FA0858D49DD745ULL, 0x2915A4E310B7478DULL, 0x62C8FC8354B3F87CULL, 
            0x115E7469B1AC2CA6ULL, 0xD9E3CC41D5754010ULL, 0x0C832F489E31B068ULL, 0xE1C9633AFB7E1D81ULL, 
            0xB346600562DB42FEULL, 0xBCD7A6EB628648C4ULL, 0x2A4BE6D49BD0AA6DULL, 0xB0B81DCFAC44C656ULL, 
            0x1D47BD95ED730975ULL, 0xBC936E0327C44B8DULL, 0x5754B42441057BDCULL, 0x23A0381C8E481221ULL
        },
        {
            0x075A1C3099FFB220ULL, 0x20D2C714AB30147BULL, 0x671537B5A3EFBAD8ULL, 0xBA78B3E8A075A80FULL, 
            0xBE79798BBEA62228ULL, 0x7CED1BBD6F6D3B79ULL, 0xD72DCE7701CA6299ULL, 0x11B3BD671762C283ULL, 
            0x0116F73111C3BDABULL, 0x3C7BF8AF4DAF99D4ULL, 0x7D990136113A456CULL, 0xF45DFCADEDB33875ULL, 
            0x61A4B24A85A38FB9ULL, 0x175AB0732B6B6ED4ULL, 0x6681B00E33E65663ULL, 0x7C04050BF82AE688ULL, 
            0x36421BB66610C6D0ULL, 0x59F24ABDBCD2D564ULL, 0xDF09E8DE9D9FA062ULL, 0xADD9F364B7502705ULL, 
            0x16683883A097B90EULL, 0xAB2E908DD43A2094ULL, 0x6B4F49AFB504B461ULL, 0x6018633DB9BBD953ULL, 
            0x92A0B8F33AB7ED53ULL, 0x17600DC92A60083FULL, 0xC37E539C10BAFEB0ULL, 0xFEB03A51DBD20200ULL, 
            0x50136D11C03C0A9AULL, 0xCC4EB7E1CF35322FULL, 0xAEB34FA0602BD976ULL, 0x2138585D489AB265ULL
        },
        {
            0xA658595FACD34766ULL, 0x4EFE0E73ABE8B3F8ULL, 0x360B4F3831A0C955ULL, 0x8AF3ABCD4728E037ULL, 
            0xF9032FA59516AAD1ULL, 0x14058B4E03F3176BULL, 0x73AE99CDA3BEBCE5ULL, 0x38D64C843AACCABDULL, 
            0x99AC4973E3AA6A04ULL, 0xB058F29C1F7264AEULL, 0xB20123FCD9166AA6ULL, 0xF9E90DC009D84607ULL, 
            0x8F7FEC9A916BF130ULL, 0x390BA9060212288BULL, 0xC30A195E203F27ECULL, 0x6C3DD11DBEDA44BBULL, 
            0xABB12DB2E42440FDULL, 0x0EC171DB729608F8ULL, 0x2D440CA6820BDF43ULL, 0x71F338A2C0CB504DULL, 
            0x9D938CEEF889BB0BULL, 0x8DA400BA37C2B85FULL, 0xDE05FA47EBF187B9ULL, 0xD1FEDFD94AC7EC4CULL, 
            0x9E721E29786A8365ULL, 0xDC6B3001F79ACEE1ULL, 0x129DAC48A2BB5040ULL, 0x2634090CE01C7759ULL, 
            0x63066774DB1BAE54ULL, 0xAA5E5E07340FE931ULL, 0x3290883F69C184A6ULL, 0x7FE62E9FA74D7AD7ULL
        }
    },
    {
        {
            0x66D306D41B1EE71CULL, 0x07748D8F6AE17253ULL, 0xD373AD78717DACB4ULL, 0x441CE339DF97B5B6ULL, 
            0x1231DCF14E1F2CC3ULL, 0x2C349471F538F11AULL, 0x83CA50E58231BB5BULL, 0x90C37F8B40AFEB89ULL, 
            0xEBC91940A57A6793ULL, 0x23A7BE398C58CFB3ULL, 0x15110B20DBF1A6B5ULL, 0xF26D50BDB6DEA864ULL, 
            0xB3A471712BF7A549ULL, 0x12769FE9BA7083FDULL, 0xEC8202E89EBE66E1ULL, 0xDF751F4A9535C3BAULL, 
            0xC6D7F33BDF3F08D1ULL, 0x23BFE8F6A8D72A5DULL, 0x119469148498EF91ULL, 0x1E47886E834BEB46ULL, 
            0x65E803F1498CC797ULL, 0x543F36B3E193A58BULL, 0x4E2C92D22B507D79ULL, 0x298A87409CED8867ULL, 
            0x34F15DDB35D51282ULL, 0xAB6AC06FAF90C146ULL, 0xFE2DC04E97A21287ULL, 0xF42F85862489DAE2ULL, 
            0x4C23207BEE996BBBULL, 0x43F54B0AEB373CA6ULL, 0xEC97DE09B092DA4BULL, 0x91F666DC2B790DD8ULL
        },
        {
            0xEF3C62A0A6CD46EEULL, 0x82503E7954B59746ULL, 0xA31E8B524D053DEEULL, 0x333134A7AF612DD0ULL, 
            0x21AA6ABCD347158CULL, 0xAB3402AB1A893E70ULL, 0xB1915FA1A17851F7ULL, 0xF156C3992223E9FCULL, 
            0x8962ED72DFEF8B1DULL, 0x16766F7439F9F4F3ULL, 0x0302D9FB2733A7BAULL, 0x8FBC307E71A577A8ULL, 
            0xFDABDDA1C35D7EB1ULL, 0x4E232BD9FE903485ULL, 0xB967B512F7DD9BCBULL, 0x8BEC7E20F524FE4EULL, 
            0xA54A997962D4DE56ULL, 0x85E55064E73543CEULL, 0xB715028A14C86CD2ULL, 0x65778F0489C6EAAEULL, 
            0x00205AEDAAE1D7E2ULL, 0x1B71BB0450F63670ULL, 0xBAFE08F13CF5FAF9ULL, 0x0CDDC07EBB02657EULL, 
            0xC2936152F17EB81BULL, 0x43929E897A9F20ADULL, 0x189DE04CDC79FBFAULL, 0x0234E196D8E1FC5AULL, 
            0xFB148448D0B708A0ULL, 0x3D5A8812B2BEF570ULL, 0x6AF94151DF21259AULL, 0x1C06089A33F4D1C4ULL
        },
        {
            0x5A4E8ACD7D6D27C3ULL, 0x56BC78CE1DDDB522ULL, 0xBD999F3B215D6749ULL, 0x47D587AEE5760DBEULL, 
            0x9BF9DB0726941A52ULL, 0x3E0DDD37DF664DD8ULL, 0xE37DCA5D0B514736ULL, 0x901DB0A2B88B7D19ULL, 
            0x4877A3EEBC3C2ED8ULL, 0x4E562CD28AFA5A42ULL, 0xADCFD768623B59DCULL, 0x65DBB4EFBA97B001ULL, 
            0xE0F6817F1393F443ULL, 0x51515AF5C5FA44B9ULL, 0x128E256931FEAB7DULL, 0xD8191CE3A26F93D7ULL, 
            0x0B2C51D62A03ADAEULL, 0x8E89994511AF60F1ULL, 0x4A1C982944504F17ULL, 0x0DDA0D481827EE05ULL, 
            0x3C23C81F3DB814F9ULL, 0xD75811701209D107ULL, 0x5396CD58CBC29273ULL, 0x65C85D0610BEC23BULL, 
            0x2428D88549ADA07AULL, 0xE3392D322996F5C8ULL, 0xCC356C8E4B0A68A9ULL, 0xC2FA3D1722964880ULL, 
            0x9830ECD1EFE9913CULL, 0xCD9F9F3D100C8A5AULL, 0xB6AA1D94ACDA8C2BULL, 0xB3619280F746029CULL
        },
        {
            0xA889A47BCFBF9E24ULL, 0x9C7B0A5D9F13A5CEULL, 0x97A34625459155EFULL, 0xF2237EFFA0B14B0DULL, 
            0xAA07B71D86002DD4ULL, 0xDC459E0E6E05497CULL, 0xE9A0364EABBBC8FAULL, 0x71805587586DECACULL, 
            0x85CE411981961BC8ULL, 0x5CBC8CD859397187ULL, 0x081D4C98B8848A8AULL, 0xD74E5FF6D365C350ULL, 
            0xE7BEFAAA43A41E9AULL, 0x295B4D78B6872913ULL, 0xC0CFEF835A22E0E2ULL, 0x7E44078780031312ULL, 
            0xAFB47D31328E5DECULL, 0x8A79DD5B0B4551EFULL, 0xBCA0E964F2B0622EULL, 0x1E0523885FB99A78ULL, 
            0x34EE458625962DECULL, 0x30266EC8C641350CULL, 0xDFF192E71738779DULL, 0x1D3131EE5E978528ULL, 
            0x90843F8C7179ADECULL, 0xEBB381628A5207B1ULL, 0x20D5AC707C4F8C31ULL, 0x74E247AD4B2BF3B5ULL, 
            0xA7BD2AF10CF61774ULL, 0xEC1CC2335456EA60ULL, 0xA06B607DC7B8C120ULL, 0xAC9FB4D6C0E2A154ULL
        },
        {
            0x5AE5F7A4030B8F20ULL, 0xD678D57BDD3848C8ULL, 0x186EBE879E4F2D05ULL, 0x18597EDE15CC636FULL, 
            0xCD28D7DB24EEECCBULL, 0xD3CC911FB7970FE9ULL, 0x43291729129935BCULL, 0x2D67CAEBCA830776ULL, 
            0xB3D4E4B02D59549EULL, 0x1D2B29D9D3E12924ULL, 0x9BF24460EFC25793ULL, 0xBC172A1FDDB6CA8BULL, 
            0xF00D4153CE6B6DF7ULL, 0xD02B07D54A28F63DULL, 0x7A31F908B968D726ULL, 0x039B888AC1E8B63DULL, 
            0x05DFCBDA042519B6ULL, 0xA6CED1D84B775DEFULL, 0xC3C3BC2E5F4A79A9ULL, 0x83BE400193CB24A2ULL, 
            0x4102FD14700EE778ULL, 0x4062344787D584B8ULL, 0x2464E07725C3CB2CULL, 0x9F348663A332DCEFULL, 
            0xEABB56F947A0BC3EULL, 0x288A6A29D55C9FACULL, 0x000ADFDCF3C73633ULL, 0xE668FDECE28602C4ULL, 
            0x77DF82B83507D9A5ULL, 0x18D847B409A40CB7ULL, 0xBE9F3C08C8DE5E0DULL, 0x9B4F6FE7C168640EULL
        },
        {
            0xE0423950483F12DAULL, 0x49BE1CB8CFB77B25ULL, 0xCE5CFE1DB844CD1EULL, 0x9D9E39FAA957B037ULL, 
            0x1A9D14580333FF5CULL, 0x7710A93E2E7269B1ULL, 0xD1A24701DBD79158ULL, 0x908CB29D25174CFBULL, 
            0x64DDDEC4E9717CCEULL, 0x722178FD8F716DABULL, 0x729ACD8FAE23F876ULL, 0x782148505F25CBCEULL, 
            0xCC20A10530A82D6AULL, 0x40BD75BF49B12651ULL, 0x904A17F8C0228C29ULL, 0x14E92EA4E9434C89ULL, 
            0x418EE8E2E63272F2ULL, 0x39E9A45B45B527BFULL, 0x31A63D8DD69D8971ULL, 0x3BB29582856BC68AULL, 
            0x68EEC918E2ECFB05ULL, 0x6F84A9EF29365429ULL, 0x79CDEAF8CE432841ULL, 0xCFAA860CB1F9FEACULL, 
            0x93FD25BB9B02FA46ULL, 0x10EC9B7DBB2DFDADULL, 0x2418823F39E5B007ULL, 0xA9EB60D733359E4AULL, 
            0x1EF38DC0F9FF6B04ULL, 0x1B263370B0ED4D4AULL, 0xA69F39B58636D004ULL, 0xF9FF9C74BD7C88E1ULL
        }
    },
    {
        {
            0xAD88CC5DE8BDA126ULL, 0x3B7D71E1FB13C4B6ULL, 0xEDD3CAAD8435B73DULL, 0x318AC54A24D0A041ULL, 
            0x8843B76AD83988CBULL, 0xE52D61FA00839A42ULL, 0x9C6FE6634051EAD3ULL, 0x80735D311ECABE4AULL, 
            0x8960F385C742040CULL, 0x988095CB788ED255ULL, 0x2C69AB515DAD2DFEULL, 0x6980A3EAC851C408ULL, 
            0x15FBF5A72164ADDBULL, 0xCAEBA169F124263BULL, 0xC38C6B4D90AC20E4ULL, 0xC3219F62A7B97903ULL, 
            0x47CF4383F31F565EULL, 0x41C284917C79B032ULL, 0x4D1358463D17F680ULL, 0x0FBDB6050BEC1441ULL, 
            0x85AB36088F1B705CULL, 0x674321E1639BC6DBULL, 0xA0EAF8C9C92903AAULL, 0xDEA6581ECA72028DULL, 
            0x39693A1C1B85ABDBULL, 0x92646FF59AABD1B3ULL, 0x5BB3F02CC520219DULL, 0x1FEAF39586BC05E2ULL, 
            0x012B76625050B3C1ULL, 0x0660B4AD8E9A3CADULL, 0x073373AA1B2154ADULL, 0xB5F0CEDDDABF35CBULL
        },
        {
            0x36554F8F8FD2391BULL, 0xAECAC2BDCFA7E026ULL, 0xB8A263D0199BF09FULL, 0xFBA07A45EE6D8615ULL, 
            0xDBD1ABA3882392CEULL, 0x4B20C7C627B7C716ULL, 0x85001485E69EC77CULL, 0xB817D9076EDC4A2CULL, 
            0x045888CC3BDC4D2EULL, 0xE56C1F9143432374ULL, 0xBCBB2BE8F55652EDULL, 0x588932E724A2491DULL, 
            0xA20330AA00510CBFULL, 0x9249C0DFDFA25121ULL, 0xFC72F5EBDB29CE24ULL, 0x1CB45DDFB265EA34ULL, 
            0x55E05FA1B97F78D1ULL, 0x8F5B508E4D171C7EULL, 0x150A1E6EA566FD42ULL, 0x00905793DBBD2165ULL, 
            0x7290B327A6D5303AULL, 0x507A57D5DB2F7E28ULL, 0x2C3B290CB2E489E4ULL, 0x7450E6D8E24B216AULL, 
            0x5FAF477967E71F74ULL, 0xEDA0AA97454C3569ULL, 0xC381458D225FF455ULL, 0x82C5E3FEFDBC4D64ULL, 
            0x3EB99042F5646C34ULL, 0x38C9C746121E9459ULL, 0x9DC98394F56F992BULL, 0x5BEEAE63F2E63B1CULL
        },
        {
            0x92D0266215150BB6ULL, 0x4933D71905CA1370ULL, 0x6146D316BB9A254BULL, 0xC9A3F4B8F23153DBULL, 
            0x1F5A2D9512629C6FULL, 0x215F60AE9701B828ULL, 0x7558940FE4D7439CULL, 0xB6959D922F567CE4ULL, 
            0x44D7C380C3F3172FULL, 0x20F911E402425852ULL, 0x9BAEF35A042E3E25ULL, 0x5BB35152C8DA0E24ULL, 
            0x77980F73AE053FD6ULL, 0xAD4658BB778F10BAULL, 0xA4BD0EAAF1095895ULL, 0x2EFAE59B1D1A0457ULL, 
            0xC681A0658C1D8D60ULL, 0x4F8A7A56A9259154ULL, 0x51267F34C8B1FD2AULL, 0xC65427A689D1483FULL, 
            0xFBF5F0EC21CAD6BFULL, 0xABABB7B6F438D15AULL, 0x47174B7DAD8158B1ULL, 0x452814F27F8E3D1AULL, 
            0x0C5819EBA62836F6ULL, 0x2A44923071A40C43ULL, 0x2F5B3FA5D688EBE5ULL, 0x39A2D48EF28BF0C8ULL, 
            0xCF167A51FB2F2898ULL, 0xCC3E1C43B398DCDDULL, 0x2B75809185831AC7ULL, 0x418353DEFF392FCDULL
        },
        {
            0x99DD7678BB0E9BF2ULL, 0xE2E4AAC87DFC8D7AULL, 0x51C37812B6B9B167ULL, 0xD59C0769639EDAC1ULL, 
            0x391BF12A56B1214FULL, 0x000BCF8A5D4C5BF3ULL, 0x69EF86262DCB9DFDULL, 0x5992EE2BA5D8E7DBULL, 
            0xA8C9B71CB4829024ULL, 0xEE2BB176CF6F359CULL, 0x8188628B758B2904ULL, 0x3BC148F144074205ULL, 
            0x7CEC529CACC26147ULL, 0xC8723B050B7582E3ULL, 0xB95A560D9DBB7264ULL, 0xB4C811CF1A501F02ULL, 
            0x5D12571E20863DB6ULL, 0x86B020F528D42B77ULL, 0xFF8B2B3C23D6465AULL, 0x944DFC5413CA6D87ULL, 
            0x8C383FAD69B4752DULL, 0xD63C577894864168ULL, 0xA57C8F520B3DF363ULL, 0xF0F914EB2CA03953ULL, 
            0x1790591DB3349920ULL, 0x1339DF1814540131ULL, 0x0B446AC4D60ACA4BULL, 0x2948B5F679631812ULL, 
            0xB99E40F9ADD839E1ULL, 0x131D049B5B7BBBC2ULL, 0xF4B2A5299BDBA16FULL, 0xCDE0B942EE9AE6CCULL
        },
        {
            0xCCFE70896360B6F1ULL, 0xE6C73374A1819C15ULL, 0xB70C6D61DE8B2779ULL, 0xCAD948072FF2C104ULL, 
            0xBB32E2827E1B6DFCULL, 0xF6C1134CA61248B1ULL, 0xB4BBE74C892981DBULL, 0x1251612C235E8411ULL, 
            0x6F6131463014EF45ULL, 0x779E8D9190FC2046ULL, 0xDBA0BFCF721C1464ULL, 0xC29BAE5B48197B04ULL, 
            0xE77D830C15D40174ULL, 0x79487AA10514D80AULL, 0x4728013A9F88479CULL, 0x3ACB62A46DA3F2D5ULL, 
            0x9F717F1334292D13ULL, 0x1BFA17EDCF5D3C92ULL, 0xD8B195F03B0DA113ULL, 0xE06E8B5A62EF577AULL, 
            0x5161DF39526D4436ULL, 0x8FAA074CBC7A35A5ULL, 0x4519AA46D6B67F0EULL, 0xC7F58552776B65DDULL, 
            0x5F431A6627601BF5ULL, 0x89B82A6B51707DD0ULL, 0xB64822B7FA07C24FULL, 0x1449FBCDCCD5EABBULL, 
            0xF0EDCD3F603C7B9AULL, 0x5DF23620A4EC1AAAULL, 0xED38BF319DB75F6CULL, 0xE792D890CB8D74D1ULL
        },
        {
            0x128A04ECDEBCA5DAULL, 0x8174A763C9CB89BBULL, 0xBB3DC87FA5B9F8FDULL, 0x6901BF1EB2A3F271ULL, 
            0xDCE9224BAE66FBCCULL, 0x7AC789323902AEEFULL, 0x9863ABDE72E91DC2ULL, 0x38B97764E1D15A4CULL, 
            0x7A4776A75DB2E8E2ULL, 0xAD68593F6016EDC2ULL, 0xC9273B39D19CD40CULL, 0xC8CED89A0BE6E1F3ULL, 
            0x780E252C1A9EEDE7ULL, 0x814017A8BDF2D062ULL, 0x0177FC7455C2A879ULL, 0xFD7F21D31B0C4C90ULL, 
            0xE550FBB832E71E72ULL, 0x8D42CBCF0F1A2A1EULL, 0x910166A4949E6479ULL, 0x09C6637882E3A2A5ULL, 
            0x797A0AC25644F50AULL, 0x2AA8DF146B9CB54DULL, 0x4265CB579B31F988ULL, 0xC1E0DE616F0B61F0ULL, 
            0x4307325D03F54561ULL, 0x58897CE59E533F8DULL, 0xE02E514E60B60C08ULL, 0x2EAFB738AB9DD9E6ULL, 
            0x6C006799425C6CE6ULL, 0x041D9D6C4A4E0301ULL, 0xC4ADE5915E9B623EULL, 0xD893839138943FD3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Antares::kKeySpawnAConstants = {
    0xDC0F4E58B0735472ULL,
    0x18DD8FAF7515CF5EULL,
    0xC7C03B524D4A6933ULL,
    0xDC0F4E58B0735472ULL,
    0x18DD8FAF7515CF5EULL,
    0xC7C03B524D4A6933ULL,
    0xC4D7DBC7E64806B5ULL,
    0x9F753BC49AFB368BULL,
    0xE1,
    0x0E,
    0xFF,
    0xF0,
    0xDF,
    0x45,
    0x2B,
    0x26
};

const TwistDomainSaltSet TwistExpander_Antares::kKeySpawnBSalts = {
    {
        {
            0x9EE202AB70778F91ULL, 0x8AE4E943E554BDDDULL, 0x520FEC3350AA6CF5ULL, 0x712222E49CA0371CULL, 
            0x237DF2CFF9595208ULL, 0xFED3A098B1871AE8ULL, 0x7E7F0EDF163A9C48ULL, 0x44DE6F0C431E1C56ULL, 
            0x24440BDABB865BCBULL, 0x4F10C13AFAA5BE09ULL, 0xD94DA2A4D516D65FULL, 0x020E53C76FEE4EA4ULL, 
            0xA3F8A2219B773C52ULL, 0x0E56B8BFD42EDDEEULL, 0x25FC824C66B76474ULL, 0x4C49FCCDDAFE01D0ULL, 
            0xA1612270C95DA6BDULL, 0x0E825DA1D537010BULL, 0xA9CD2CC6A8CFA3F8ULL, 0x30EAD46D72DFDF1BULL, 
            0xFF6104748AFD8542ULL, 0x4D9719A51034E1DDULL, 0x47CA428FFB85C530ULL, 0x4BFC0180832465E1ULL, 
            0x99BB6ECFAB9C2B52ULL, 0xC3844361C3CC43E6ULL, 0xCD23CC69E660EFD8ULL, 0xF01C6B947468A39EULL, 
            0x4468045D44E5A028ULL, 0xF4CF1E0401DF623DULL, 0x33BCBD3E35041621ULL, 0xAEC0CE794C3BBCCCULL
        },
        {
            0x079455211429C994ULL, 0x85B08379FAB49611ULL, 0x6DC707FA80C65D77ULL, 0xCCC3B33553E5DDF2ULL, 
            0x94F162066C923FE1ULL, 0xD0B655EE4479F417ULL, 0x2F7FAC06E9116732ULL, 0x18ACDCD7D7D01093ULL, 
            0x76CBADF1BBE16926ULL, 0x45151ACD9AA7D360ULL, 0x39F971D8CA40BCADULL, 0x72926B73B2A95003ULL, 
            0x495AF40C70141BB4ULL, 0x56C3E6A56EB79DDFULL, 0xF7EA5CC68DBA9FF2ULL, 0x76228FECB7CE12D5ULL, 
            0x347ADA6767147832ULL, 0x484890A7812D05A1ULL, 0x0C6FD0BF4E8FA1D8ULL, 0x7E5A874FAF1879C6ULL, 
            0xF1920505BF18FDA5ULL, 0x2FE363A4EE821DBAULL, 0x8596381455231553ULL, 0x600883E444B44BC2ULL, 
            0x34C0C0E24DF4801CULL, 0x4AEC4990DDBA91FFULL, 0x794AE78A7067865AULL, 0x24A1DBB64AC5F572ULL, 
            0x1A5E891B2C18340DULL, 0xB0ADAAB2E874371FULL, 0x0C7B50460F690DE2ULL, 0x77321A58CFF75C03ULL
        },
        {
            0xF35469731B124C81ULL, 0x6F084CE66F8BED30ULL, 0x0DF3547F61992B38ULL, 0xA57FE8B19D6CE5E5ULL, 
            0x56EC9C053401E060ULL, 0xA2678EBFA7C24F99ULL, 0x5A0B1C6284853DF2ULL, 0x5BCD4FC1D1AF7451ULL, 
            0xB54C382817011BCEULL, 0x8B27D848C7C617F1ULL, 0x048E7B1DCA38EE59ULL, 0x2A982DDE8EBA01FDULL, 
            0xA6DA54263927C422ULL, 0xB2E34CA7A1EB396CULL, 0x3D2D9A4B647BB42DULL, 0x3955ABB5F77E4EA2ULL, 
            0x178383E27ACDF01BULL, 0x9E4B26F29346DB0BULL, 0x53637862C628C315ULL, 0xD27A2855874E7B8CULL, 
            0x490B9B08A545FBBDULL, 0x546A733D749D4565ULL, 0x6E76662B0DE0FFB3ULL, 0xC1BEB832BBDBD57AULL, 
            0x432F1AD902802465ULL, 0xC8D5465DC93AAEC7ULL, 0x3F93C8B0889D628AULL, 0xA8F945F62D1D5665ULL, 
            0xAA79DE8C138EEA4EULL, 0xD087DF20C72EC154ULL, 0xE2CFC233D5DA0AE6ULL, 0x53B4F95A27F202DEULL
        },
        {
            0x804146A89759E9E4ULL, 0x189EA26C448EA053ULL, 0x815D356C17F93F45ULL, 0xB98E5EB954A3D8C9ULL, 
            0xCE60AD02898B0D3AULL, 0xDE87DD92924809E0ULL, 0x9E47915B4A529716ULL, 0xDA657E9F63BC2F0EULL, 
            0xBA3F27C826740989ULL, 0xD60634F80FDE86AAULL, 0xFB5B912D99ECAD64ULL, 0x8D4195959DDB7CFFULL, 
            0x9D6854DFF1622126ULL, 0x637E0F05F69B0417ULL, 0x3E58FEE289858A6AULL, 0xB5DA668803955184ULL, 
            0x1E97E4B91BDF3CA3ULL, 0xCA6EEF3538A0F2A4ULL, 0x9949F3A54FDE7A46ULL, 0xAA62A882A3B5F02CULL, 
            0x6C90C24AC26E306BULL, 0xC6A8CF4687360FE5ULL, 0x0066F2B38FCF25ACULL, 0x32B95A871A292C00ULL, 
            0xD0E0BDCC34A54823ULL, 0xF79DE6FA9E875B97ULL, 0x49B553C9F6F9F43BULL, 0x2736CF889CEA09D2ULL, 
            0xAAAA09C3F3F3D67FULL, 0x102CDA691625225AULL, 0xE13A4EF1D0B04BFFULL, 0xBF8431EF4C6B0F40ULL
        },
        {
            0xE3EDD7D33246E5BAULL, 0x57F1A2C1C258BE17ULL, 0x1CB19EE534CBA84EULL, 0x01F9992A7C8A18A6ULL, 
            0x573A4C36E557A36CULL, 0x0416D6F530079427ULL, 0xFD0E3A0217CFEE5AULL, 0xD682436C56D3609FULL, 
            0xFBECBF437DD4618FULL, 0x1CDF854DAE57C82DULL, 0xD52CD255DB9A9BAAULL, 0xA4724F797BB5AA79ULL, 
            0x59978DA15BC3BCA5ULL, 0xA9E69B16A4BC729CULL, 0x254A207F59021904ULL, 0x13EE5FD46BF22F7EULL, 
            0xB2ABF441C1B23EE7ULL, 0x3DEC3E6237AA7502ULL, 0x49C529218F6760B2ULL, 0x187E4444FED04FB3ULL, 
            0xC1C728EEF232E16FULL, 0x4F031D6CCA369111ULL, 0x17961C6E7F6549BCULL, 0x38721CB65384EB72ULL, 
            0x7E2C8B5DBBCF6FBDULL, 0x4533C5AAD59F1F1AULL, 0x7F7A6FE4C1BE00ACULL, 0x1D1DFFCAE385ABD2ULL, 
            0xE4A7C94D0436F077ULL, 0xD260C35761A3944FULL, 0xE5160B6AA5E00314ULL, 0x7ABA08EAE346A1C2ULL
        },
        {
            0x1596691DDE733357ULL, 0xB471AF91D1AF626DULL, 0x7F731CEB33CB5271ULL, 0x9A060BCA100E92DFULL, 
            0xE5B09D5D33F727C9ULL, 0xFC1E19AAF10DE59EULL, 0x96D6EE9F596D61D2ULL, 0xD7353D120D436E71ULL, 
            0xFE9711D0DDA11807ULL, 0xEBC05FC5D16E069CULL, 0xABEFF42402FCD6B5ULL, 0xC7474CB2965E69ADULL, 
            0xB4432CF4FAB66EC5ULL, 0xC15780EED3517182ULL, 0x7D53492002F76D44ULL, 0xD41FEEB37BA25115ULL, 
            0x98CE880278ACBA55ULL, 0xC6E142109F7F1557ULL, 0x4B1C9A5011434510ULL, 0x961F7FB1E97C9432ULL, 
            0xEE518C371B07A970ULL, 0x226F807CA30EE178ULL, 0xADB3DCE4B2D94C57ULL, 0xCA505E4051DDAC17ULL, 
            0x63D2EE76A58262C8ULL, 0x2EB788AEAAADE606ULL, 0xF03FC74AA63F4792ULL, 0x857D2A4D61E3CD36ULL, 
            0x5E1CB4C412051B54ULL, 0xA706A60A900294F4ULL, 0x5EAE8AE0378876E2ULL, 0x2CC1BFA437A43298ULL
        }
    },
    {
        {
            0xC349D6CAC83A4AE3ULL, 0x89C6281FF6565A04ULL, 0x0C4F1A4AC1C2ED4CULL, 0x6BC015CA7EEFEEA1ULL, 
            0xCAEFA64C1B25A344ULL, 0x736F1A54032BEF4AULL, 0x0CCD461F9A75F826ULL, 0x072ED6129DF52849ULL, 
            0x2F5612F87D2523A6ULL, 0x962FB57C83FA27F0ULL, 0x5306C13FA54E1849ULL, 0xA806EE46D7948DD8ULL, 
            0xD74AF827A5FD788AULL, 0xED9AB2E3FF56B52CULL, 0x40A162498993F7ABULL, 0x191309D00D6D9014ULL, 
            0x0E42AAD932144450ULL, 0x85B420F414DC2AB3ULL, 0xEFDF983CEE5B39ABULL, 0x4179F7A0E2B79E46ULL, 
            0xB5E87EF9056FB774ULL, 0xC79D0A9FE46D2F5EULL, 0xEFE9F20264AAB83AULL, 0xB47948B157C6EDE0ULL, 
            0x5671DFCF558369B6ULL, 0x2E4981400422F813ULL, 0xF5751B66F057FA38ULL, 0x7979FC8105E7C974ULL, 
            0xF0428E71D7F84408ULL, 0x790EBDA5CF71989DULL, 0x36398578A4492FB2ULL, 0x58C8CE9F19524977ULL
        },
        {
            0x21DF3C0DB8B0E166ULL, 0xDC0F26324F9FE0D7ULL, 0x09325FA9CB3BC852ULL, 0x1DA30B91080E0D3DULL, 
            0x4CF145B3B34CFBD7ULL, 0x2A2B7FF455209350ULL, 0x2827602B7FAA7966ULL, 0x4AC50BFC5BAB90E5ULL, 
            0x500C1BD5C9C78FD5ULL, 0xB6E2EDAF581F0E0AULL, 0x29BA6BE5F31A73B0ULL, 0x4FAA5B9758F0AC12ULL, 
            0xA62BDCBD3C961DFAULL, 0x84F2A07E5C838A6EULL, 0x97F98588A0A8EF88ULL, 0xBC992E46827B33E2ULL, 
            0xE512D2ABC01CFE6AULL, 0x92CAB5CED85FD02DULL, 0x8569164E13F1C8FAULL, 0x37746DFAA4E4CF1FULL, 
            0x079E2ED6A2866A7CULL, 0xBBB8697E5453975DULL, 0x2073DDB16AD8F20FULL, 0xA65F54031AD6FFBBULL, 
            0x60A6A31C0D395775ULL, 0x8DDD795FB4248D5FULL, 0xAD9FA02C97FA5AFFULL, 0x414E6269939294F0ULL, 
            0xFDCE02BEEEDB3E5DULL, 0xC4878E07FD0E40FDULL, 0x5C417458612FE4D4ULL, 0x0C7F5143848E6EADULL
        },
        {
            0x373D29C3EE45CD56ULL, 0x78A74A49F900CAB8ULL, 0xE6BAEC1F8A413037ULL, 0x2F8299E82D36CDB7ULL, 
            0x6AB765AF01AE57EBULL, 0x106DF56D181D136CULL, 0xC7D8BD26B0AB690BULL, 0xF6E1FEC0A1C0E518ULL, 
            0x8AC62D03BC5760CAULL, 0x73174E05320659DCULL, 0xC6200B5F464E5CC3ULL, 0xF977FED676880135ULL, 
            0x5020080E85E07C74ULL, 0x8789123D833F0002ULL, 0x184B5058085323BDULL, 0x1BFE6920A7A25587ULL, 
            0x9A316D63F50AB214ULL, 0xC3D3E1D007481FCBULL, 0x46CA65DE733F38A0ULL, 0xBBEA02D9071C6581ULL, 
            0xD7CDEA78EE0BB194ULL, 0x570D775CD666CE8DULL, 0x3D7DFCE8F91E44ACULL, 0xDAD61828DBED7DC6ULL, 
            0xB167C034DCA94F3CULL, 0x80A90A2578D07C39ULL, 0x61B1554897F7265BULL, 0x5BA12EFA7D8F3A59ULL, 
            0xEE97833DB5D1A820ULL, 0x13558EE6750BC0BCULL, 0x26592AABFACC5190ULL, 0xE591D14967354359ULL
        },
        {
            0x4B319A50DBB274BCULL, 0x9BB5EE0081D84C45ULL, 0x331329EB0AC97A3DULL, 0x96AEFFE2DFC616ACULL, 
            0x65596101DA633D68ULL, 0x7C5C391BE3235709ULL, 0xF81F79FC96CFDA85ULL, 0xB7700B78261384F6ULL, 
            0x0F21B815F1082E50ULL, 0x4F152B142A96FC60ULL, 0xB02E5665A8DF55F6ULL, 0x38385ED7F2BA8BFFULL, 
            0xD3E7CC3342B28DD3ULL, 0xB961F95FDE11AC2BULL, 0xF52D1EF121231C61ULL, 0xCB07E53DE7122166ULL, 
            0xAD255C886F2B7A9AULL, 0xA8431BFB0BED4B9EULL, 0x35093AADC4CA6ED5ULL, 0x740273AAD8B8F8E6ULL, 
            0x69E6980E517CAEA3ULL, 0x305E23F25AD2AE62ULL, 0x839BDAA307BA3228ULL, 0x844588184C52DADBULL, 
            0x92043C706EE9E146ULL, 0xB52EE029C940A4EEULL, 0x25A47361CF93C4D8ULL, 0x7BC7C893A2FCE9BFULL, 
            0xC92F5C7AA17A1260ULL, 0x38372F89618044F3ULL, 0xCDD193272D14193BULL, 0xA06E48BBBF6D66E3ULL
        },
        {
            0x8F7FF228CE46F927ULL, 0x634341FBAF5D3B4FULL, 0x34F19AE1F190E346ULL, 0x840DC4447769B02AULL, 
            0x45476963411DA883ULL, 0x5DCCC9527988B6E1ULL, 0xA5D278F28AE03CC3ULL, 0x19EB6CFF206FF501ULL, 
            0xA8FA2F48B7E89BDAULL, 0x6DAE2F0BE66F9B3EULL, 0xB1CA0FF192F8F345ULL, 0xF69425F5CABC87CDULL, 
            0x91185B662E97F0C5ULL, 0xB13C5CF9FF34F839ULL, 0x93BF78C8F2454623ULL, 0xC0032E7195779A88ULL, 
            0x8EBD885FAB438588ULL, 0x0A1168FF202B9D18ULL, 0x3DDA6350206A92E3ULL, 0xC29DCE59A78B2B6FULL, 
            0x6E155A85C9962E14ULL, 0x622BCB67CCB874D3ULL, 0x3D09295933384E66ULL, 0x3E9392B9C6E9331FULL, 
            0x41B47533F77A5DEEULL, 0x0F1F4F3A54DABDCDULL, 0x9B01E8A9002D32FCULL, 0x484EFB288D793B19ULL, 
            0xBB6930998E03C010ULL, 0x5B9D896C53B63CABULL, 0xD5A407F712666ABAULL, 0x098DFC6368CCF324ULL
        },
        {
            0x272234BD20F0B3A9ULL, 0xD30182D17766DB7CULL, 0x59FA192FA946441FULL, 0xF20220B4246748E9ULL, 
            0x5A1CEA67C9F33C5AULL, 0xF42CCDBE8860E1D6ULL, 0x3DAC82263B08E901ULL, 0xF3111726DDB06BC7ULL, 
            0xB3A18E234749E9FAULL, 0xDB207376D12D2340ULL, 0xC8F72B51CD88F547ULL, 0xC56E5448916FEF16ULL, 
            0x2429C3DD52036035ULL, 0x67C41D349D8A8333ULL, 0x3E0A43CB479AAFA6ULL, 0x9EB7315EAA876B93ULL, 
            0xAD17DAE2A045C6FBULL, 0xC63BADC36C2943A0ULL, 0xC1904671DDF61AD7ULL, 0x61D985FB7846ECFDULL, 
            0x94A20DBC88E35712ULL, 0x968382FD978002F1ULL, 0x2BDD2B2675586B61ULL, 0x7F2032B1C57796E7ULL, 
            0x8299D564E4B9635AULL, 0x19830503B2EF92D5ULL, 0x27ADE7001D9DDA18ULL, 0xA3F65C5EE06CDC7EULL, 
            0xBE80DDF1D1151BD9ULL, 0x5F707692AAE8010BULL, 0x009E9885515A6B8CULL, 0x3225AD27644DA900ULL
        }
    },
    {
        {
            0x399D6A6085856145ULL, 0xF02BCE1FF3809ABEULL, 0x646985767BBA311CULL, 0xC00A982A1275F1FDULL, 
            0x84CE55CA745E8641ULL, 0x0F2572F698056EB8ULL, 0x73656B949A8735A3ULL, 0x59C5E3023096FD8BULL, 
            0x273066F5A98C5236ULL, 0xEF7A42C7D86B913DULL, 0x3BA129677A272D5FULL, 0xE4762D0056DF16C1ULL, 
            0xF1FBB86326DCF068ULL, 0x44F5DF7208619432ULL, 0xE200DE1C43A694E1ULL, 0x7AE3AEF2FB3E235AULL, 
            0x5B37A6209C3768BAULL, 0x921CB5D3E10A49C8ULL, 0xB74FA6EF1FC8808AULL, 0xE5F1F89E7A3A95E0ULL, 
            0xE6A615AE517C4927ULL, 0x7D15E703260D01F3ULL, 0x410AD7D73320E534ULL, 0x3B9C29024FCD70EDULL, 
            0xBE290B1E97B719ECULL, 0x06582D63D34B87C8ULL, 0x3302CE8840E04E29ULL, 0x4A3065562A5DE0F0ULL, 
            0x6750F8C312C58674ULL, 0x0E64481416853C73ULL, 0xEE7324543862921EULL, 0x09F176C1AF4E3B00ULL
        },
        {
            0x5014B49846F95EB2ULL, 0x7CD7BE12D4D41389ULL, 0x840675DBA8ED9894ULL, 0x4C1E011443ACF87AULL, 
            0x81DF2455B2CA5168ULL, 0x60BA58177B574072ULL, 0x00A6493F32BE60AAULL, 0x786A664619525F67ULL, 
            0x3828F1FD85ED16DEULL, 0x68E913A46D35B181ULL, 0x039E1956C93F3096ULL, 0x1A1E51929218E6CEULL, 
            0x5F735641EFA9C731ULL, 0x08346B494157A5FCULL, 0x9BF0B792FAA295D5ULL, 0x14D90F13D7EE266DULL, 
            0x98DAD1F2BD9F0F47ULL, 0x11CFFEF1252344D3ULL, 0x3EF59A4B1D0BCF31ULL, 0x8121897C0C901B5AULL, 
            0x578D97A06FB0C524ULL, 0x4CDA4E1F501648C4ULL, 0x41E4B8A30DFD9188ULL, 0xAAB27C6AA1999288ULL, 
            0xEE14119AE272EED9ULL, 0x261D833D4E9B6BAFULL, 0x00E98E30BB9190E4ULL, 0xCCA7088D15DD10DFULL, 
            0xCD52F594E4EABC9AULL, 0x0F4FE0F1904FBF74ULL, 0xA7D0D84C9E1F5F70ULL, 0x82EC2254BAE44C0CULL
        },
        {
            0x97BBECF0D8D8FF3FULL, 0xE2606B6E0E38F8CBULL, 0xBCF27777BE3E51EFULL, 0x09A0D13127535502ULL, 
            0xBD62DAFFD6114AE4ULL, 0x4EA4990DA798350DULL, 0x0859B8E4610AC7ACULL, 0xA839644B5A9A9841ULL, 
            0xDAA7BBA32D56AC88ULL, 0xA72AADCA3D9900ECULL, 0x6202A79641FC357CULL, 0x106EECF956786F63ULL, 
            0x0D74DD88A33563D2ULL, 0xFCC2A1A79C6A9102ULL, 0x6B88A7C4E26744E0ULL, 0x769D887CC691F013ULL, 
            0x59EBD7CFC4E297C8ULL, 0x013B15E51F41BB62ULL, 0xBD88AEBA96BBB3F8ULL, 0xEE01E978B121C453ULL, 
            0x6CE197F455E39300ULL, 0xCF433579CA0109F1ULL, 0x8786C8653A195F90ULL, 0x5D647AD5311322E3ULL, 
            0x0F32FF0E16CFAEF8ULL, 0xDDCEE7EC0C2B6627ULL, 0x483D101A6FC0BBFBULL, 0x173F3F225E7CE5C4ULL, 
            0xCE4960FFAB8CA011ULL, 0xD429E8B640C1EEA5ULL, 0xB8B8FEEAD6334D60ULL, 0x70A7B1D7F6CC67A3ULL
        },
        {
            0x88B2CB01B28919BAULL, 0xE6BECF1B1FBEA4BFULL, 0xD4F8E60F3CB07306ULL, 0x31C929E6E37034A4ULL, 
            0x25C0DFBFDADEE7C9ULL, 0x5F7038F7AAE91E9CULL, 0x547599313F4EEE18ULL, 0x2BC3E07C18E2A854ULL, 
            0xC12AA3CAF4D10618ULL, 0xD38DCB5F0540696AULL, 0x8B155C62072896DCULL, 0xB61CBF5226F2BFD2ULL, 
            0x814BD4354819856FULL, 0x5BB4436EE503D042ULL, 0x5969D020900A6CDAULL, 0x0B42790A7CDCDB3CULL, 
            0x2F01EA548555C5FDULL, 0xDDDC45044713D4CFULL, 0xDDC4982EB7CBBC95ULL, 0x1266BF5F56EFF0A8ULL, 
            0xA5BE42BBEFBFD45DULL, 0x8D4176BBD2C0F166ULL, 0x34BDF962C4B995D9ULL, 0xD9B5F0455CCD1C21ULL, 
            0xA756C7AD97A4F552ULL, 0x74626A74D7DE4429ULL, 0xACFB43E66065FEC1ULL, 0xCAB1D6C3A321E578ULL, 
            0xAF22A499911F95F3ULL, 0xCD77E484ECC70FA0ULL, 0xA62298D61BB9AA15ULL, 0x1015BFA90E8B2EB7ULL
        },
        {
            0x123D1EC2F3DCAA21ULL, 0x7A36E6A5CCA1E321ULL, 0xBFAFE2680D87A19BULL, 0x1A28CC0F7551E910ULL, 
            0x35796100DFBF301BULL, 0x21B65CFF3EBD3146ULL, 0xB947DFCD2ABBBF6AULL, 0xDE0AC97C1C0A100EULL, 
            0xD9541D0227DD1542ULL, 0xF6DCE2683E7A649EULL, 0x354487D0DCF3C878ULL, 0x3405CFE8792AEF32ULL, 
            0x7958449031C868C7ULL, 0x4C5B3E9366E3C0B8ULL, 0x8165337E457F1EECULL, 0xA20120B4CE92879DULL, 
            0x006E18E46F71A4BFULL, 0x6029D744433C7885ULL, 0x57F2FDF7F7F4F90BULL, 0x2802CBF856D6F663ULL, 
            0xA3053200D36B5E0AULL, 0x7E53894B0D311D70ULL, 0x1801F3657B4577C3ULL, 0xC1DAA6480F32E6A6ULL, 
            0xA3F368C9083EE35FULL, 0xB57E8BD671474C6BULL, 0x2602D1BEF438C7BFULL, 0x9A7F370D4171B7DAULL, 
            0x562E7A48EF9AA03BULL, 0x2179AE728C00EEB2ULL, 0x9BDE46FA0E9682C7ULL, 0x62166C630C24F2C5ULL
        },
        {
            0xFDAE47CA6ED63B19ULL, 0xA4436C2BAAED7355ULL, 0xD17F6F60FA3AAC14ULL, 0x80A32E67A870980BULL, 
            0xA133043F446169B5ULL, 0xB9BFEDDEC9C75DD8ULL, 0xB67D34E0D337C260ULL, 0x51BD1C6E5DFF0081ULL, 
            0xD7FEBB5929B29EE5ULL, 0xE1281A7D30D05AE5ULL, 0x605D2BEB749D6D5FULL, 0x3D3FFE3FE78C562BULL, 
            0xC107ADA4F824577DULL, 0xC86D8DAA323E3B76ULL, 0x01367586127536FBULL, 0x57D10FBD657B7AEFULL, 
            0x37759144B2094EF5ULL, 0x6F18C7CD2AE3F0E0ULL, 0x5CB0E4BC89D5C5FEULL, 0xA91E0FB71F60A74CULL, 
            0xBE8E8EB2928C132AULL, 0x3F3EBD494E40CA13ULL, 0xA3932BB663EC52A5ULL, 0x26876433F6F00505ULL, 
            0x42C282F470502973ULL, 0x1741D3380D6EB769ULL, 0xC0C126FA58A034AAULL, 0xB5C7EDED9B2E759CULL, 
            0x29C228F22E43EFC7ULL, 0x370E5C73AC1DF3E7ULL, 0xA457498B02918D2CULL, 0x62FA31B52EC2661DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Antares::kKeySpawnBConstants = {
    0x3305F68840257660ULL,
    0xD0BFD6C125703E01ULL,
    0x4755EBF3E8ADEE83ULL,
    0x3305F68840257660ULL,
    0xD0BFD6C125703E01ULL,
    0x4755EBF3E8ADEE83ULL,
    0xD06375676E453745ULL,
    0xCF5A76E74BEEDCD6ULL,
    0x98,
    0x5E,
    0xEA,
    0x3B,
    0xC0,
    0x33,
    0x4C,
    0xBB
};

const TwistDomainSaltSet TwistExpander_Antares::kSeedSalts = {
    {
        {
            0xCECA6DC535E0FB1BULL, 0xF2473EE345A83DCCULL, 0xE8F3BF7D33C28FB1ULL, 0xB8957DB94778311DULL, 
            0x8C05F237AEE543FEULL, 0xEFADFF75C0677338ULL, 0xC707849E85035110ULL, 0x590296BCE5588F0EULL, 
            0xCE7DCA1051BC52DCULL, 0x0E8B702307C7FF47ULL, 0x9802BEA51EB699DAULL, 0x71211D4049066078ULL, 
            0x4655055960827854ULL, 0x28812C9215BED28CULL, 0xF2DFBA0912F99816ULL, 0xA531D1075D83543CULL, 
            0xDC35C0949C90D1FFULL, 0xBF29C3D37BDAAE7FULL, 0x88C42C67AAFE6311ULL, 0x96C63CBB5F7E8278ULL, 
            0x0971B699DC8DB6E6ULL, 0x523EE9FB4ABBE3DFULL, 0xA26671892D3AD6BCULL, 0xDB22FE7064084BA7ULL, 
            0xE9CCF034D3C80918ULL, 0x8E1D33D00C982EC5ULL, 0xB5E36D26A0130A69ULL, 0x32F6C3F63CE4A66AULL, 
            0x48CC47131CC49692ULL, 0x5BA587888112186FULL, 0xDE09F4A90E5DE665ULL, 0xF891E2554FDE83E4ULL
        },
        {
            0xFEE0AD92BDD23480ULL, 0xED34CFD738C697CBULL, 0x1B238FCB46F1B2B6ULL, 0xE4F25260C0F1F002ULL, 
            0x7A121451271FCC75ULL, 0x813E4B05631CD725ULL, 0xCFF233911BE760ACULL, 0x02EEAB13096CE5AFULL, 
            0x9A442A93B841DD30ULL, 0xBBB23715E7834150ULL, 0xB395454652BA8D6CULL, 0x62EFEC48FB3DC2DCULL, 
            0x416389D92A739128ULL, 0x56F56805EE0CEDE7ULL, 0x00134E462CFA9591ULL, 0xD1B4A8097A391B7EULL, 
            0x1EBA75DFFCFED8D0ULL, 0x0D83164A8A8F1AC6ULL, 0x07F17CA0F52A37C8ULL, 0x74F7B7A5334537BBULL, 
            0x42CAFE6D5670BDE9ULL, 0x188200D29B13EF14ULL, 0xB54753A59764B4F3ULL, 0x4428E37CB2AC143BULL, 
            0xE1CA07FAA8B8BBFAULL, 0x252A204C0A262AFBULL, 0xCC773FA74006D59EULL, 0xBEFF5DE05DEE43C8ULL, 
            0x8B4D6E2ECCC16C4CULL, 0x3FCB7A2D5843AEFDULL, 0x6C0C9260606ADB4CULL, 0x8BA83F1E099E04D7ULL
        },
        {
            0x272ED5DAAC1FFC35ULL, 0xD9E533C212EC3ECDULL, 0x02BF598A7435BB3EULL, 0xCDEF0850BE259103ULL, 
            0x1E5892C1D037E519ULL, 0x147001A3BC2E10D0ULL, 0xBB663D3DB0C9BB52ULL, 0x1008452A3AD5697EULL, 
            0x10507A8B0B000D4BULL, 0x2E62356FA1646E59ULL, 0xF070FE9821E8527BULL, 0x845A4152393B86B7ULL, 
            0x818AD14372C24010ULL, 0xF52BE4998D2959F4ULL, 0x3E8EC6BBFF25316DULL, 0x1899C16659D5A482ULL, 
            0x84C349EB266A9EA0ULL, 0x74D6CCEBCAA821A2ULL, 0xD38DAAC6C1C70476ULL, 0x27F5CBC663FAD1E6ULL, 
            0x1597676725A1BF83ULL, 0x47569743039EE81AULL, 0xF81D10ACE3ADC297ULL, 0x9D8596CCF0CB6DF4ULL, 
            0xEB92E411D44BAA5FULL, 0xC0A3A3BABB17E110ULL, 0x3B4AE88855198FB9ULL, 0xD2CF1121980C5E74ULL, 
            0x97F2F1C474D1E5CBULL, 0xCFA0C5A245C693B2ULL, 0xF49A59D238EAC251ULL, 0xBEEBC33893E163DFULL
        },
        {
            0x0C3C0EA351E6F7DFULL, 0x8D5245497EF1ED2DULL, 0x449923BCE25C313BULL, 0x50B96391503C6215ULL, 
            0x5B1D265A15D54231ULL, 0x2A038F3A054518EAULL, 0x2243C4AEBCA2C9BFULL, 0x4AFA982C7EDD9E14ULL, 
            0x6E8C24DFE5852C80ULL, 0xADD6EA4B8D6285C4ULL, 0x669C63D73B9D2502ULL, 0x9CD495C1982353FEULL, 
            0x3008C12253ECCF38ULL, 0xDFFC0115F5AC5240ULL, 0x7A774575F0836AD4ULL, 0x669CB114FFEC8B74ULL, 
            0x689069E0CC7BC1A2ULL, 0x1B160E328682CC10ULL, 0x2E1E92B1245E02DEULL, 0xD0F40AE135D84CE1ULL, 
            0x33CCCEC4F361215BULL, 0xA1E522F8D2C0ACC2ULL, 0x76E14284748D7C93ULL, 0xA03AB852E424A461ULL, 
            0x7F381AA60EC2B6E5ULL, 0x1C349C1CC106AEDFULL, 0xF044061EFA7ADE8AULL, 0xCADC89A6C15352A6ULL, 
            0xC9791AC5D832206BULL, 0x79459819DE985149ULL, 0x58D53BD889DC6D6EULL, 0x60D58CC11D0BE8E4ULL
        },
        {
            0x5C95C8641ECA0B15ULL, 0xFEB00A24ED3A4C47ULL, 0xC85D6AB18B150CC8ULL, 0xE6EDBD57E9BA0DF5ULL, 
            0xA1DE540007C56071ULL, 0x29B30C8FD70ADF77ULL, 0xF8D2444BDDCEAC7FULL, 0x0F496A8714E85A67ULL, 
            0x9B67D24EDC0BA986ULL, 0xAEC154417C7E0153ULL, 0x4AD4914DA132F2B5ULL, 0x22385D5DBBFA6D59ULL, 
            0x7DA28421F4BFE0DFULL, 0x0FE737DBBDA903FDULL, 0xA7BB0967AFE8AC78ULL, 0xEAC39A02B05CD71FULL, 
            0x726EC6BA14BF7168ULL, 0x56C205A8D6BF21E4ULL, 0x1B81750196A351CCULL, 0xC07CD0219231E072ULL, 
            0x8DAFCA0B228EFCD8ULL, 0xE327A5A7B309B6DBULL, 0x19FFCD4F6CD0C5DDULL, 0xF3D8B8022C5B6202ULL, 
            0x12491BE09C5D913EULL, 0x02C97E9B88E65F1CULL, 0x3FF60EFC01FAEC69ULL, 0x9EC73F2322358F44ULL, 
            0x407D038613E0DACAULL, 0x7547BF8B4998B734ULL, 0x54D4329BA4842084ULL, 0xB6C11E50D8EB59E8ULL
        },
        {
            0xF57B4159E7CD2BACULL, 0xCC7214EF4AAACFD1ULL, 0x71FBC210A57DCD9FULL, 0xBD3ED35A041E6B7BULL, 
            0xD4FEA09D2533CC9EULL, 0xB206C4E76BFEE5DDULL, 0x5ADE459CD643C632ULL, 0x91071315426B5638ULL, 
            0x712E3BAE38E5AE85ULL, 0x223023CECD784378ULL, 0x9B61B477CC607F1BULL, 0xCB27BAF4EFA250FEULL, 
            0xD8C760770EB45866ULL, 0xDEA1C445F8AFCFE3ULL, 0xF56C302B7B8DDB3FULL, 0xE04239D2F7DC2FEAULL, 
            0x439CA62F2EF0F71AULL, 0xD67B357B64F3BEB9ULL, 0x393A43BA0D41DEB3ULL, 0xB907E35C22D5FE47ULL, 
            0x30A4C57D291E97BCULL, 0xD526616FA19F7556ULL, 0x76D2396D99605E43ULL, 0x56CA00CC9E7F3B05ULL, 
            0x484B31C8F4318DE2ULL, 0x5C0508EC9B78FBE0ULL, 0x0600C20A80805100ULL, 0x97A7E2A85258A8B9ULL, 
            0x9C49A4886A329CB3ULL, 0x7025B4362AAD8A39ULL, 0x7230D286F848172EULL, 0xE792C7CBFABA4C0BULL
        }
    },
    {
        {
            0x1E2C044847F9FCFFULL, 0x74AE55D302B01F6FULL, 0x764D199B16A7CDD6ULL, 0x504009B7240A0C4AULL, 
            0x712D8BF4C45683E3ULL, 0x4D81D1648DFF61FBULL, 0xE6723821C9234EADULL, 0xCC53375E29B59611ULL, 
            0xE8272147AECBA7A5ULL, 0x0F86BD34FFB5AE3DULL, 0x85D16C5F7804F31BULL, 0x149C74E484AD37BFULL, 
            0x5EE657F33B6B2515ULL, 0x95855E9040DE20CCULL, 0x4A66E34E3486408FULL, 0x04580462220B3CFFULL, 
            0x30FBD41BDF2FFC70ULL, 0x3D7840EB34EEAEC5ULL, 0xD5395350803A4C1BULL, 0xFA3DF794AC97444EULL, 
            0x51DD424A31FD175DULL, 0x70B881D8BB41FCABULL, 0xE6200F6BCA1BB3C6ULL, 0xB6B389328ECBD686ULL, 
            0x69A0B52A7F59E99CULL, 0x6767F343878D6C48ULL, 0x3209AD991A5CB5CCULL, 0x5057908ED197DE25ULL, 
            0x892AD1B0173BE206ULL, 0x1CBEA98EE950EE05ULL, 0x8890196F9B4A1DBCULL, 0x26B152CC06B0EA41ULL
        },
        {
            0xC979A59F4BF7CE0BULL, 0x8A17CBFDDBC33370ULL, 0xC23BFE3367A1B512ULL, 0x81E7F5ADE04914E0ULL, 
            0xC0A19E230B10AFACULL, 0x657F752F6C8DE503ULL, 0x583837845792FEECULL, 0x808977DCA5794705ULL, 
            0xDF14F877DC45D21BULL, 0x990613B9258EB111ULL, 0x5D96BA7C0A0880B4ULL, 0xC4F9E2124F5DB953ULL, 
            0x01C765DC3DB837EAULL, 0x2B63BC6E648EC9D8ULL, 0xB1C41EC24790EE01ULL, 0xA7F617F5691EB794ULL, 
            0xB73160614A15EBB9ULL, 0xA4F21541B18A165DULL, 0xAC5B4AA160EF1DDBULL, 0xAFB380C56261853EULL, 
            0xA859091AFA5D9F28ULL, 0xFE6354A2E2092C31ULL, 0x5C4EE638798A2C25ULL, 0x01BA3A211DFF5119ULL, 
            0x5B870C8974EDCD42ULL, 0x9C313DB5C8B5576DULL, 0x2BAF47EF3BD0CAD2ULL, 0x7DCCA8303FC214BCULL, 
            0x16515CEF9938BEA5ULL, 0xF572F29C2D634B2AULL, 0x45ACA1F394067A86ULL, 0xA658D9D38143445BULL
        },
        {
            0x3E338F1ECF9268EAULL, 0xEBFF898B56C7141FULL, 0xA3E51BFB18F39F59ULL, 0x1635D3C1990F6CA6ULL, 
            0x42A03EF5DBE43385ULL, 0x137B89A55D7DDE39ULL, 0x63FC2A5A6583A595ULL, 0xF590AE8D5455129BULL, 
            0x6AEB1A00689D9CC9ULL, 0x40BCCD2A33410776ULL, 0xB61A03622CB85B86ULL, 0x6FE27D0A94DF5974ULL, 
            0xCDF83A84D4C23ECBULL, 0x265C4792721CACD8ULL, 0x00BE4E10F31F83AEULL, 0x13B4D12D4FFC3A57ULL, 
            0x57FE1688B39FEFF6ULL, 0x60D15BCB9178F6D3ULL, 0x10AD0F08735DA978ULL, 0xC30211B047E9330BULL, 
            0xDB95D60AB61FA4C3ULL, 0x112295C544BCFF88ULL, 0xF671B7C2EBC8284BULL, 0x3C79E9F34880BBA4ULL, 
            0xA10B8C8CC3BD8439ULL, 0x531EAE57F6478DF5ULL, 0x9F47A425432DDF0BULL, 0xB850A027D4C78993ULL, 
            0x1F90C5E4F99F712CULL, 0x54E137C5EB52C8F7ULL, 0x96EF946571BC2114ULL, 0xCE7DAE72F3A93676ULL
        },
        {
            0xA2CA77EDD7D65E0FULL, 0xE121B3E101E0162BULL, 0xC4CC1FE2056208C3ULL, 0xDE8E0B28B1A473E9ULL, 
            0x9C29214C2B27B91FULL, 0x2D2723C98F70EB5CULL, 0x296A74E4164D0A96ULL, 0xBA1178EF48151491ULL, 
            0xC10E65FEC1F7758CULL, 0x615FCDC69C3CF0EDULL, 0xF901F8AA7A68677DULL, 0x47321DD83B0C3BEEULL, 
            0xD02733BB89A0CE48ULL, 0xF611A26ACD2AD854ULL, 0x16EDDF25128268F3ULL, 0x08898E2D6ECDF279ULL, 
            0x142C3A3676A71CDDULL, 0x83EBA001D2EEA9D5ULL, 0xFADF48FE44AC8CBAULL, 0x86B5FA726CB7F5CCULL, 
            0x4E01C0D6BAD54B3EULL, 0x35A389BBD2DF85E9ULL, 0x0B3845701B82B39DULL, 0x9EFB9D233F170E01ULL, 
            0x09A63E58FDBA40C3ULL, 0x4FF254A58076BB44ULL, 0x7989D4794AD2447EULL, 0xFBCE857A12EAA60CULL, 
            0x5A8B74D51141FE87ULL, 0x0B3C0CDD17CF2429ULL, 0x223912BD85FF369EULL, 0x1734ADDB50717ED8ULL
        },
        {
            0x5054686AE859CFEFULL, 0x794B339F057E3E28ULL, 0xD1BAF3D3F90A7D89ULL, 0xB79DA956E3D272ADULL, 
            0x64CC418924A01642ULL, 0x0F31F3EBA6F277D1ULL, 0x27BB63B91404067DULL, 0xAEAFEFAE59AE5A10ULL, 
            0x7FE3F9A721162504ULL, 0x9568BE5B02365510ULL, 0x70571BCBC18182BEULL, 0x58E919B653A6E158ULL, 
            0xBF2F19E97D9D2507ULL, 0xF1FDCA5A27BB30D4ULL, 0x2E500090AED59F9EULL, 0x3A6D31213F92B165ULL, 
            0x8C3139188D1AAEAAULL, 0xE7F283814009E41DULL, 0x319DBA5DC2295C73ULL, 0xF8419E0585842BD6ULL, 
            0x839F2BCF962EF9CFULL, 0xFADF61A1ED6B29EFULL, 0x66F2832F6FE54A71ULL, 0x697BF32F485A3C8FULL, 
            0xD40767334BB3A8EEULL, 0x09E8D76162E0AD12ULL, 0x85D259E3DAB5ED7DULL, 0x3693F65A4AACFC12ULL, 
            0xA0CBAE5F2CC91F9FULL, 0xC9F8B5069AE98EFDULL, 0x296D5A6219EBB94BULL, 0x3DFCABA0B927784AULL
        },
        {
            0x9D90FA07CB2F26DAULL, 0xBF5050D5F1D4F674ULL, 0xE1EEA63240B1D034ULL, 0x1E1041A531AAB0E7ULL, 
            0x95A453D14DDC2BD7ULL, 0x4FF70AE58E6F8E61ULL, 0x523CF9C965C492F6ULL, 0xAEEA61F4BAFF6BA2ULL, 
            0x68822592F430F3DDULL, 0x36E638310A0687EFULL, 0x20446232B64114C0ULL, 0x69F95C58B9DEF0DDULL, 
            0x8D6F816D11BA3C50ULL, 0x0C6F116C69EF7475ULL, 0xF4ECCC6ED9A12D46ULL, 0x09DDAFB0AE1AC692ULL, 
            0xC2E38266DBAE5072ULL, 0x9AF0E89EF790D792ULL, 0xD703DCE321274079ULL, 0x05E268C7A964E6B7ULL, 
            0x7E5659B98B127951ULL, 0x32D523D473105498ULL, 0x797CA7BA81FEDC09ULL, 0x3175D75B93BAE9E6ULL, 
            0x848E06717433578EULL, 0x7DB8B13E1B4D7D4BULL, 0xF6AE4CB8E2DC0E93ULL, 0x8C67D236B8C22F63ULL, 
            0xE057D741852AA57DULL, 0x3D264E01ABBBF177ULL, 0x9E29D0AE4EA7A90FULL, 0xAAC825FD2FC40857ULL
        }
    },
    {
        {
            0xE44F5B2E0DD0B52EULL, 0xEF31FFEC17AD6002ULL, 0x5AAB942AE205CE91ULL, 0xE09B7EC2D4E9D30DULL, 
            0xA9ED060E864F19E7ULL, 0x4209FE58FBBF15FEULL, 0x71EAD119569191DBULL, 0xB402CE3A8332C685ULL, 
            0xFE499A976F9474DCULL, 0xE055D456B56868DDULL, 0x57CBDAF08069C4D6ULL, 0x025AAF030183ED40ULL, 
            0xFD3E7AA17E0B0DCFULL, 0x85E2970CCB2EEED2ULL, 0x1394351FF4EBCCD9ULL, 0xEC38312E1F7826E8ULL, 
            0x3E729E122F834961ULL, 0x9505296175A34A30ULL, 0x637430910B6228AEULL, 0x279BD2587A6E516BULL, 
            0x3693FBBA5EEC73C3ULL, 0x1A70A75854CB7C39ULL, 0xA2B716C0F0554284ULL, 0xA0D87AF60863E7CEULL, 
            0xCDF0140C5DC68978ULL, 0xEBF8E15BEB2E8EC5ULL, 0x8A2B1CA13CF55921ULL, 0x73C06DAF631758B6ULL, 
            0x7368CBE181CE8C50ULL, 0x92BBCB74E8CA78C2ULL, 0xEDF6C097E957FF28ULL, 0xC865D616C5DC2D1FULL
        },
        {
            0x19C7D48D0AE91F73ULL, 0x6C15F8F8E970D918ULL, 0x761533F8E6027508ULL, 0xC1914A267E0816B6ULL, 
            0x8B3F021592461A0EULL, 0x15E1A57B0D2A117DULL, 0x2B1502F461B761B1ULL, 0xD89313BD8AB405C6ULL, 
            0xDA2E8BCA15A9F070ULL, 0x4F32D69C3BEC4DE2ULL, 0x1FF1F7FF73A2B4F9ULL, 0xEA0F247F9F26D6C3ULL, 
            0x00799A485F2B2AA0ULL, 0xE506504FF1C462B2ULL, 0x5C5A727C4701AECDULL, 0xF3A1522A0439A9EBULL, 
            0x65F5985A92110FECULL, 0xCA98D29896D55DCBULL, 0x82F731624136A3CFULL, 0xA0FF940E711B068BULL, 
            0x885B8CDA4AE10ED4ULL, 0xDE2AFE6573AA7610ULL, 0xD0FB0BBED9C5BB94ULL, 0xCB973E4B135463CEULL, 
            0x35DFE8A81AB12B85ULL, 0x3A6F95F1C3C3BD56ULL, 0x255A38F79B9FF483ULL, 0x1C6395C11B5B1EBDULL, 
            0xD6202E1A5D0E5FBDULL, 0x75CC32E0E9E2A444ULL, 0xF0A2D0A8BCB31D30ULL, 0x071968D6161955FBULL
        },
        {
            0x01BCD374B5F5CA43ULL, 0x91628273BCCC041BULL, 0x4985B60ED00DBCF6ULL, 0x82F2CA061E4D4A89ULL, 
            0x44DE4B96A692170EULL, 0xC91A944A4014E607ULL, 0x20D44719F806334EULL, 0xA1B162321A3902BEULL, 
            0x249484625510DD42ULL, 0x7DDAE0741E219D2AULL, 0xD58F005D34E6BC52ULL, 0x401039C6C149FC31ULL, 
            0xB475DFFC3A316339ULL, 0x96CE227F383E272EULL, 0x79EBE19C92ED9B3DULL, 0xFEA9804ECF4EDA2CULL, 
            0xB8230EB80BB26CB5ULL, 0x6DDD680FDE3ABD2FULL, 0x4D1C562A5C2BD28EULL, 0xD7D7552370F69185ULL, 
            0xAC684D78C1F09CD3ULL, 0x3C819C3F58A82165ULL, 0x0DB3930200C5B7ECULL, 0xF12710A4024697B3ULL, 
            0xE3A78AA95DEAA7D2ULL, 0x85F60FBB2E778BE1ULL, 0x1FB2B660F2C72C7DULL, 0x1696C58C643DABD3ULL, 
            0xC134F8B2C55F947CULL, 0xF11EB97A2483D4A4ULL, 0x30A58F9E0BAE78EEULL, 0x866353173A11479EULL
        },
        {
            0x6E5286894F2E0D88ULL, 0xCD05FCC54BFEC11BULL, 0xAE4C5CF8D73B488EULL, 0x4EC06E2EA237F37AULL, 
            0x36A15923A705D86DULL, 0x91F113615D5CA44EULL, 0xEE6604D721373B20ULL, 0x38625FEC98478A2BULL, 
            0xD7FDF78DEF4F2025ULL, 0x47EE879D93252F04ULL, 0x7211032699E36BFAULL, 0x4FD4BB4D36DB2506ULL, 
            0x6343857E89D35B01ULL, 0x9B7CA17FB88B0FA9ULL, 0x908E916904ACCDD4ULL, 0x1E19340C337FEC56ULL, 
            0x432E6EDFAA722538ULL, 0x32891AF06B03F415ULL, 0xA639D5B756D37490ULL, 0xC53A7334803D22ECULL, 
            0xA4EBF288E3157768ULL, 0x6967C74FE73A90B3ULL, 0xF46E652F58B3D338ULL, 0xFA598C6D21A5093AULL, 
            0xF3B1ABC7E1FDB6AAULL, 0x852F61AA22A539B9ULL, 0x7513C9E8D65F7F24ULL, 0xE2016021BE512A7FULL, 
            0xE7ECCE9398872F4DULL, 0x6D374C3B2C34F237ULL, 0x6FBAA235BD0CD939ULL, 0xE402641436E93B82ULL
        },
        {
            0xD30D80D8459AFE4EULL, 0xFF908B5877A43783ULL, 0x97A5886A9F1FAD18ULL, 0xC8B6F56486E7CCC7ULL, 
            0x969961BD44FA90BBULL, 0xF58AAEA0F01A2339ULL, 0xBCBC5CD068795CDAULL, 0x2F2074CE3035CF03ULL, 
            0x38E6C5D66E0B72A5ULL, 0xECCFCE94A312869BULL, 0x0E366EB4A78849D6ULL, 0x5861BE86C67AF9D8ULL, 
            0x2EB2EFFDE612800AULL, 0xF80C80047468D28DULL, 0x06887B88FBC75C69ULL, 0x507C6AFB67131E38ULL, 
            0xD3A177DCC0107558ULL, 0xF509DCDB8EE8A4DAULL, 0xE9C4B43A5F973B9CULL, 0x23DFD905637738E6ULL, 
            0xC48B807B48A4E194ULL, 0xCDE1C0A7D60F977DULL, 0x119D4EFB2ECB4148ULL, 0x27567B5F1D82E7EEULL, 
            0x33A8E302D8FC33E3ULL, 0x549C6B8EC81F2B17ULL, 0xC7457DD4ED097D16ULL, 0x62CA750927688744ULL, 
            0x05396DF2B46F2649ULL, 0x13953A6A4BD44724ULL, 0xCFA248E76BACD467ULL, 0x755C8413E004E2C8ULL
        },
        {
            0xB461CB55FCB26D9AULL, 0x1F994F52B2B3416AULL, 0xBC428ED376C9C893ULL, 0xBCDDE77E54D212D2ULL, 
            0x63BCA61086AF9C1EULL, 0xA40F28B6851282A6ULL, 0x24219135A2A41540ULL, 0x977735E67576968BULL, 
            0x09DC0E75683667DCULL, 0x08D7FB448BF381DEULL, 0x6A8D2742737E3814ULL, 0x941BBA5ADDB9A076ULL, 
            0xFBAED87185D34F58ULL, 0x8AC987E90DB86123ULL, 0x04A4316EBEE08F64ULL, 0xF20BBA7F410FF17BULL, 
            0xD0FB162117FFB630ULL, 0x3979C2B02A426F2EULL, 0xDE1DC77C53FA0C68ULL, 0x7AE102437616A1B7ULL, 
            0x044B13E71C5D3014ULL, 0xF4EED9237EA24AA8ULL, 0x8C713A32BABF7B69ULL, 0xACB3C4FC57A27F74ULL, 
            0xADD4828C7CB5DC6DULL, 0x432651DF23C193A3ULL, 0xA8E36F0F30F6778AULL, 0xF739A0386F059858ULL, 
            0xD8FD91A81669EA40ULL, 0x80FEB1B8CC3E3B80ULL, 0x6584A7C50C4687ECULL, 0x4D6CFE6CBF13854BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Antares::kSeedConstants = {
    0x72C888EA025066A9ULL,
    0x0C76EB566E6535D7ULL,
    0x8423CC80C81B3F2FULL,
    0x72C888EA025066A9ULL,
    0x0C76EB566E6535D7ULL,
    0x8423CC80C81B3F2FULL,
    0xDC290814140F5687ULL,
    0x3C17F4DDECA0097BULL,
    0xF6,
    0x95,
    0xA1,
    0xCD,
    0x67,
    0xCC,
    0x69,
    0x3B
};

const TwistDomainSaltSet TwistExpander_Antares::kTwistSalts = {
    {
        {
            0xAF1FAA270F0B5318ULL, 0x5442BBF932CFEA40ULL, 0xAAEC0B36A9CA2994ULL, 0x2E975DA0148ED6B0ULL, 
            0xAE4C83B7DC8D3466ULL, 0x589C4A0BFFA0CAC7ULL, 0x952EEA42760879ACULL, 0x28B0BC0EB8BF6360ULL, 
            0x3A63089D58666263ULL, 0x22245F07040E8854ULL, 0x97787476D19BC112ULL, 0x813E3E74C0581610ULL, 
            0x628CF10CADA75812ULL, 0x0E88DB9CFA5579A9ULL, 0x4CD9D574C520760FULL, 0xB5DB70992C9052B2ULL, 
            0x4C78E5816DD966C4ULL, 0x80830BB54F8D4C0AULL, 0x97A10108A9966F42ULL, 0x3172F40B204ED29BULL, 
            0x7AFF513B2AF73B11ULL, 0x3FBC896C4815F714ULL, 0x1BE356FB65689D37ULL, 0x08DC3670D0EAD009ULL, 
            0x14B483FAE91B4915ULL, 0xE7F6B8F03D1F3C7AULL, 0x1A694B8BE0115ED5ULL, 0x84500993F8B3A23BULL, 
            0xA9062939851CBECAULL, 0xEB13CF427D779983ULL, 0x44E6613250E5CC1CULL, 0xD0085606A6665342ULL
        },
        {
            0x181FB5685AFE2479ULL, 0xAC12ADC76DE8D222ULL, 0x197651778CD8558CULL, 0x8BF42AAAB67C476DULL, 
            0x48B1A9CB075D3E69ULL, 0x0B561FA9F96E85E0ULL, 0x24DD2C9EC5D72E46ULL, 0x0903473D3FDC1135ULL, 
            0x2D5C6DE20A7C28FDULL, 0xA52AB8E1B93088CFULL, 0x7BE94827FC17630CULL, 0xFB7AC0CB6385B8D5ULL, 
            0x96F769572A882AA8ULL, 0x9C60E7FE6BDCB436ULL, 0xE13050F08368E1BFULL, 0x724211E75E04C01BULL, 
            0xA5918660BD468AFEULL, 0x3F5F7AB9DD7AFE34ULL, 0xEA6FFD8E067D3E5FULL, 0xBF892AB7423090BAULL, 
            0x4E308EA9D2DE4875ULL, 0xD636702BCA29B7D8ULL, 0xE9D6919D7E44376FULL, 0x5BEAAD9A695A93B8ULL, 
            0xE744C532CF014A69ULL, 0x95E11605FE18CE38ULL, 0xC6A18298ED404085ULL, 0x0CADEF92FC189EC2ULL, 
            0xF996DEE1F2237832ULL, 0x167BDC6259BD8C38ULL, 0x6BE9BCA1F7740589ULL, 0x64F2B2C0C1F226B9ULL
        },
        {
            0x5252586D874F0044ULL, 0xF4AAE3E99674564CULL, 0x1FFC76CC8BB38756ULL, 0x73C656D2BF94085AULL, 
            0x8D38ADCBE2E1634CULL, 0x92DDF0AA894B0C18ULL, 0x74B1037F419FEEE5ULL, 0x99FB6DD43F5B96EFULL, 
            0xB95EC280668A8D18ULL, 0x2669C37344A07F9DULL, 0xED56F6AB7455416DULL, 0xE52A60902DA4A67EULL, 
            0x99F8F1BC604DCBD1ULL, 0x231CDC6C1E972E25ULL, 0xC618C2FAE52AD790ULL, 0x90024F6DE7816E31ULL, 
            0x5EDC41EFD508D32CULL, 0x840F4E9228AE91F6ULL, 0x4E732CB25DACF72AULL, 0x322B3EC6DFAEA22FULL, 
            0x40846D95858F40EAULL, 0x5EE1A37993321356ULL, 0x8BE341BB09A0C7CFULL, 0xC4BD6D1D6DB80A41ULL, 
            0xEFDBD3379E72CE9FULL, 0xBF1E832195FA427CULL, 0x4D34CC4C79D9777FULL, 0xD0C5D4A9C2B6260BULL, 
            0xF94151A067816E18ULL, 0x304F364C74B8FB9DULL, 0xF7A31A66973419CAULL, 0xA2847FCAF1059553ULL
        },
        {
            0x606A9E3E6A949545ULL, 0x91385378FD6B3CFBULL, 0x18B647FE6F2B3AEDULL, 0xB327CE015C5DDC94ULL, 
            0xE10E9DE0A6758493ULL, 0xEA1606E5EB0904B5ULL, 0xD3D751C85AC70BB1ULL, 0xB21F271353EE6D00ULL, 
            0xA96FF3577ACB4FEAULL, 0x808C628EB8C96517ULL, 0x788AEE736D4B31F3ULL, 0x6621DF423FC107AAULL, 
            0x35DE7F4D8EE5E13EULL, 0xC6D9D9507EE13F7CULL, 0xEE4F9F8F1C7FA71DULL, 0x75100CC90F3756DBULL, 
            0xDE25C3296D9D0202ULL, 0x1ACA48A3E97E3D11ULL, 0x09BFB9AC12FBD392ULL, 0x53B701930CFB5681ULL, 
            0xECFD3D1E63E68EC1ULL, 0xBE36FC160EC839F4ULL, 0x97721F217B7B083CULL, 0x3C76651B683A5102ULL, 
            0x0742503612BEADB6ULL, 0xE01BD81840140995ULL, 0xAEA04A73A0DB1E51ULL, 0xBDFAC4EF55FC5929ULL, 
            0xCC26AD3C88AF7FA8ULL, 0xE3F2CFBD976FBC9EULL, 0x23C71097F6E5618AULL, 0x3CD3F3599B339074ULL
        },
        {
            0xAF6B6A1F6FDB47FCULL, 0xF7B477AA1CDC6A8DULL, 0x64FAF8C777C72EB4ULL, 0x5AF8F558224AD949ULL, 
            0xD273789C93502C84ULL, 0x32132124747D2F60ULL, 0x6DE4B63C389EA6C4ULL, 0x9A1F553C6ECC99B7ULL, 
            0x3EC55AA0D2469BD5ULL, 0x3643E8EE395FE7C4ULL, 0x1F123A2681374725ULL, 0xA953AC92119C4C55ULL, 
            0xCE1FD490C44A3C46ULL, 0xA637CAEAA8C7AE38ULL, 0xEC74979423EDBCADULL, 0x1E1094BC08A06C02ULL, 
            0xFD764CC868ADD7C7ULL, 0x5CCD799ADB7C2085ULL, 0x7C5FBE538A0B3B5DULL, 0x30CC4D1155F6145CULL, 
            0xB933BC11C30815E1ULL, 0xD462E05A8BBA4478ULL, 0x2E27657F12FB1031ULL, 0xE4243034D9182F9EULL, 
            0x0352379DB7D4A7C3ULL, 0x310B6342012D3900ULL, 0xB7CD37E15FEF7C40ULL, 0x6641D955CC7A7957ULL, 
            0x7237BB19C1C111CDULL, 0x19CD0B67124334E4ULL, 0xEB451228153D8978ULL, 0x32934961362ED277ULL
        },
        {
            0xC14AF8C3A7DA28B9ULL, 0xFEB063BE7E19A3A0ULL, 0xE4CD329B21CA8903ULL, 0x204A995C24A48ED1ULL, 
            0x39EED1E16E2A94A9ULL, 0x959E0EC281EFE2BDULL, 0xEA5E01A25212FFD3ULL, 0x91DB91394C408295ULL, 
            0xA168CD7177CE2324ULL, 0xFA7498EFED4AB475ULL, 0xF98F05206759956CULL, 0x432640C88DF3ED9BULL, 
            0x071F00087E10831DULL, 0x535ED68710AD7EF5ULL, 0x24A103BA4C8A07B3ULL, 0x7FA2D99990A44B34ULL, 
            0x9545069A508C6F5FULL, 0xFD148F2E4F0CB6E6ULL, 0xAF560D7FB6AF6EC6ULL, 0xA35FDA95E2651F96ULL, 
            0x8E7B789EBF45917AULL, 0x3A37CEB225141B76ULL, 0x2668B44DA90FCD4EULL, 0x84EF326C2F2D3C42ULL, 
            0xD4434F7CCB9F34D5ULL, 0x71F275FE5325F52CULL, 0xE35312A2A163B049ULL, 0xD80DEE84A7F24591ULL, 
            0x15B56EDB41267EEAULL, 0x834D92F75A32C3CCULL, 0x6A6416A9AB870DB5ULL, 0xEAAD3FAEF02AD59CULL
        }
    },
    {
        {
            0x984545D1BA635E74ULL, 0xBF1644469C67BF64ULL, 0xA2F23C11964ACB95ULL, 0x6B32C4FF8E13E801ULL, 
            0x19139286FB4A3541ULL, 0x2A54AA31F5B780CAULL, 0x67135252BB1D2F5FULL, 0x79233009A09D50D9ULL, 
            0x4066CC6F5843B9E0ULL, 0xCF26A5DD737C4416ULL, 0x9CA72909390D8341ULL, 0xFFF8AE8609097613ULL, 
            0x504221157D4EAFDEULL, 0xF0B3A9EE2992F0DBULL, 0xE9FDFDBAB877B14DULL, 0x54220A0445A6773AULL, 
            0xC7757E76D98125FCULL, 0x4FF0992628768ABBULL, 0x9ECACA137BA5B4F7ULL, 0x1DDBB37C81C2DA31ULL, 
            0xF9B1D1D500D0E3D9ULL, 0xED0ACE0A3E99F70FULL, 0x7ED1A954BCEBD86CULL, 0x8E897B33FF4BA4E1ULL, 
            0x6F68C5E44298A647ULL, 0xE1B5765F05CD6968ULL, 0x11BAF41435FDAD64ULL, 0xAA8672CA48FA1C93ULL, 
            0x80EE071F4904B028ULL, 0x06929756A96A3352ULL, 0x6BA051EFFBD73AC6ULL, 0x23AD123B786618ACULL
        },
        {
            0x44BDDD060FC2F80FULL, 0x4904A955F77727C1ULL, 0x95E219BF4F4F4432ULL, 0xA29EFD93E2FC591CULL, 
            0x9C50D3294C865FF3ULL, 0x8B03F7ED2D1BD45FULL, 0xF61AF7C2B6E78025ULL, 0xFE2CA4481CF80330ULL, 
            0x5BD1A62DCCCC399BULL, 0xE70023C0DA470724ULL, 0xF4FC4BBCF47D2FB5ULL, 0x949D26027F689472ULL, 
            0xF117609E6D748086ULL, 0x3044DFBA4616C519ULL, 0x111C455332549008ULL, 0x609750029AD01F71ULL, 
            0x5D961295B6D564B3ULL, 0x4980DEF6A6381A89ULL, 0x67726EF1482A813DULL, 0x946B77878B81FEAAULL, 
            0x7A4553E050D8A714ULL, 0xFFDA5650019F956AULL, 0x180E753A3380495FULL, 0xDD21689B1E80A662ULL, 
            0x5A9F3FF374DAC950ULL, 0x01B9FD83A69FB0FAULL, 0x8CA81FBB46B64134ULL, 0x6161E65E417024EBULL, 
            0x399A5B44C87986B1ULL, 0x5FB996FF1E66A881ULL, 0xD037211B87E982E7ULL, 0x619F238333B028AEULL
        },
        {
            0xD22C0DC54FE00170ULL, 0xC01B9B69059A19F9ULL, 0x2ECEFD88FB6C76CCULL, 0xCF7BA77B7C3E80D1ULL, 
            0x14C82AB7F0157355ULL, 0x66E749BEE2E85E18ULL, 0x236A28EEFE5309C5ULL, 0xC1729D241B3F3AD7ULL, 
            0x7A7B86C9B999B849ULL, 0xCDE2EF8FADA13CEDULL, 0x34380237FE28F29AULL, 0xF4FC23501182C13DULL, 
            0x750A550FC7D15479ULL, 0x5CE7DC54E2D39D73ULL, 0x842C7A4E3D7056D7ULL, 0xF5662E95B7F83998ULL, 
            0x1072B2933A13CD7BULL, 0x322A4B717F3F5499ULL, 0xA26DAAB7F46B435FULL, 0xED950339A7FD2835ULL, 
            0x9AAB9AE6041E224EULL, 0x192765DC6F1360FFULL, 0xDE187B923E4C4C1EULL, 0x0EAA451722BD8BE0ULL, 
            0xDC2E306E6270C859ULL, 0x232C2877CCD6E474ULL, 0x69B2EF2B9702BD6CULL, 0xE8577AA56D8CDD3AULL, 
            0x565679901239D38FULL, 0x3E2EF4917E9E344FULL, 0x4C775D4182B43065ULL, 0x3EA3DAD26B188D94ULL
        },
        {
            0xB3C28EE26AA9F28FULL, 0xD3489BB3F5A5F283ULL, 0x8BCCFCD7EC264348ULL, 0x352549AE565121A7ULL, 
            0xAF7898632917BD0EULL, 0x9773E429A8C51CE2ULL, 0x555DC1316AAEC569ULL, 0xC716B44D31FF6DF6ULL, 
            0x726D1BD5ACDE1AA7ULL, 0x1AD59762C87FDDC5ULL, 0xE0BD020EB7AA4D73ULL, 0xA55140801A367D8EULL, 
            0xDE769E173CA8AB8BULL, 0x99D6AA38A035E1A5ULL, 0x2851B078D0FABBC3ULL, 0x99E543BF130C97EDULL, 
            0x7ADCE445C27070D3ULL, 0x2F3D8F138459B3C7ULL, 0x02B8D0C75ED01D71ULL, 0x29C69AAFC9CA4931ULL, 
            0x5811A76DA3AEFA72ULL, 0xC0A34DFCEF92003FULL, 0xBC510EA4CF320D2CULL, 0xFACBEC00514D4AA0ULL, 
            0x73C138032DF49E77ULL, 0xB03D44AB8BACB10CULL, 0xE2F1390AB466054CULL, 0x5C3A7675763EDB1CULL, 
            0xF35B618EC46FC506ULL, 0x8C161C1C1907EF19ULL, 0xEB366F1D91AEA2CFULL, 0x3DC7F0C77A04CE4DULL
        },
        {
            0xDAE80082CBB0821AULL, 0x06DEC274924F5439ULL, 0x00F76CEB957205A6ULL, 0x076BC444B83CB63EULL, 
            0x7E1BA7C9E36CF4B2ULL, 0x255435D96734787FULL, 0xA5960974AD3DAD7CULL, 0x28673F503AE06DA5ULL, 
            0x21DAFF96FC1C63C4ULL, 0x98D4DA8F9C6B944AULL, 0x5AC4885A49473BD7ULL, 0xE883DA48493C314BULL, 
            0xADF11DE99CA03566ULL, 0xF4A735B0D5249BB2ULL, 0xFDBC608178C5E636ULL, 0x1C3ABCD2BD56BBCFULL, 
            0xC9160DE2183C3BF3ULL, 0x4C7E951B04209956ULL, 0xCB7BE1297F91CBB2ULL, 0x73FF39173DF83CB9ULL, 
            0x13698489523B3A01ULL, 0x17647B69D584AE66ULL, 0x3BE7032FFF0F540EULL, 0x5E1FC2CA838A043DULL, 
            0x0DA394519CC2183DULL, 0x8D6690EB05CD75D6ULL, 0x0E84A7CD26C881EBULL, 0x00AFF5EFE5F15C6AULL, 
            0x64FCB0B0362C74FBULL, 0x919D0F64E9BC7397ULL, 0xD53EC98D98C87384ULL, 0x89B89DF815926EE2ULL
        },
        {
            0x8DA977B65424E5F9ULL, 0x22DD3682DFC4CCB5ULL, 0x5196263ADD7A019FULL, 0x85F3953BCE15F03AULL, 
            0x961266E091E103F5ULL, 0x0058C23DF107FBDEULL, 0xA7BBFA89EB120260ULL, 0x2834F556E3E19E9CULL, 
            0x075DB2C8346192FFULL, 0x537E5DCF0E7EDFE9ULL, 0xB1991BF13ECED095ULL, 0x70C4EF872A86F24BULL, 
            0x6318EDA8AC01EC38ULL, 0x0E9943F163B4C209ULL, 0xB06CA1D7186C7373ULL, 0xBB4A27D4E27CB412ULL, 
            0x40656F6A6D4BBF39ULL, 0xD4533DEDD59F7E00ULL, 0xCE6C36D33B6B4B6AULL, 0x43671B53095E2150ULL, 
            0xEA551F4D572587C8ULL, 0x5E052F5D31B8F8CEULL, 0xB22BB1FC5A4D5520ULL, 0xEE5F32DE4A01D354ULL, 
            0x7B07AA0DB4FA1B93ULL, 0xE615EABAB4BF5B7EULL, 0x588F68772BA9FA70ULL, 0xC9278FD9EF2CD8B2ULL, 
            0x4082B6BE9F51C917ULL, 0x5A53A7B5C95808FCULL, 0x2C8C3D7AB95488F7ULL, 0xDBE9144F0849EF7DULL
        }
    },
    {
        {
            0x0CE8A06CCC95A6EEULL, 0x667C34BEE9B710DFULL, 0x69EBD9192A7E51E5ULL, 0xB495039979D97A94ULL, 
            0x24610D2894A44B05ULL, 0x13DD740B309EF9ABULL, 0x74878BA15423EB4DULL, 0xE0632C6981B76099ULL, 
            0xD4304E357A70C5ADULL, 0xD5A68271CAE46155ULL, 0x63710398FF7D2188ULL, 0x2DA69D723C6EB9ADULL, 
            0xCA5B9D5AB0A0E9BEULL, 0x13C9137BB87AC2C1ULL, 0x53D23DC869B82D5EULL, 0x5F1EA5F0A414305AULL, 
            0x5F3A2C2D72F2B7A4ULL, 0x6D46793AB6F7C7EBULL, 0x6F6419FB5B6C3C6CULL, 0xFC15DC69DD03D491ULL, 
            0x9F1EAB82FA126D0DULL, 0x5E9F4C7B3C04BFC5ULL, 0x3904F010AE9B657DULL, 0xAB05EE811E88491BULL, 
            0xC45F3DBE146CBDBFULL, 0xE1F6D5CE844C3596ULL, 0x56451246D133ED81ULL, 0xC8840ACCB7D6AF58ULL, 
            0xA42F5CCE2983BBC4ULL, 0x9DA47FE0F5CF9CDBULL, 0x392A2EB788E01F61ULL, 0x4EDA3CB9DEF33163ULL
        },
        {
            0x376D402A2D576DC7ULL, 0x11719492563ECC9CULL, 0x50102DA924F6A48DULL, 0x1B7AF42D8C4D911EULL, 
            0xDD8753E761A7925EULL, 0xD7B087152C88148CULL, 0x05F52DA9E033EB31ULL, 0x9BF72214571E9C7DULL, 
            0x235CBCB8D5D730A3ULL, 0x7278F4D45C94C72EULL, 0x852CFDF2A78FA57FULL, 0xA1E156D523784C00ULL, 
            0x4E16128EF2D037E7ULL, 0x98C6F0812019B164ULL, 0x6FDE9D52CB055D17ULL, 0x68B107440BFF94BBULL, 
            0x507339C2E58C2210ULL, 0x2769D0D14F1BF4ECULL, 0xA87C38188824BF85ULL, 0x2F6ED65490C6E7D1ULL, 
            0xC3A85C732994F1A3ULL, 0x544EB6DD68448CF7ULL, 0xDB821EA708B5D800ULL, 0xF9701CBC2D5B9A10ULL, 
            0x406B423958752F60ULL, 0x5D62FED1B3F48FCFULL, 0x08D21C47A9EB911AULL, 0x59FB6560F138F3F3ULL, 
            0x3AE1BD56135B220AULL, 0xB5FD390BCDA5FDDBULL, 0x10FEF33C655F4D9EULL, 0x1FE22C4E46C5BC39ULL
        },
        {
            0x656CB01F2787B006ULL, 0x107FA9D4E95C56F4ULL, 0x6841701EE71019A5ULL, 0xF0DC989FC03E97ECULL, 
            0x63864E553E128B59ULL, 0x39A07AB5ED0089C8ULL, 0x7E37C3F390D8B1B1ULL, 0x231CF91F5A07C940ULL, 
            0x00C707521AF8ACE1ULL, 0xD3AA3B6448EF26F1ULL, 0xD5C22599A1908B22ULL, 0x4C9A65E39D39FF47ULL, 
            0x4396D8DC74FD1545ULL, 0xA94DD7FFC365B991ULL, 0xD97F79BE71FA4DC5ULL, 0x1854A22031CB9F99ULL, 
            0xBF168AD30255F021ULL, 0x2E528696F392F2E6ULL, 0xA54ED6D79243F7EBULL, 0xD69CB93326D1EA43ULL, 
            0xD9EB59F383924E74ULL, 0x1309A4D7C4105DD0ULL, 0xE553720A1C60E8F9ULL, 0x6DA5E7E71A4E7FADULL, 
            0x3FF2A7D835152A6DULL, 0x0A257300EABC64F9ULL, 0x461A630829175C21ULL, 0x7A8F3CAA0BB61281ULL, 
            0xB54A9A66D24E933DULL, 0x8B505AFB0DD9F7B2ULL, 0xCBC7D494FB01E988ULL, 0xDA9988DAFD5D32FFULL
        },
        {
            0xC105B2042BD63624ULL, 0x9E9C7E528F9DC2F8ULL, 0x21D0F0E3AAA22A2AULL, 0xAB03D93BF3C37E13ULL, 
            0x42986046490CB978ULL, 0xA841360DC67F1325ULL, 0x8160AA0AE83C7189ULL, 0xB5FBC7E3F414A25AULL, 
            0x96ED07C5E4E64903ULL, 0x61F49D1D9FA53191ULL, 0x0AD1711B9DD5305EULL, 0xC223EA7D6E8A951DULL, 
            0x4F5A2C6391EB99BAULL, 0x815613297DE38106ULL, 0xB774E9BE1A6FD30BULL, 0x2219D1F3AC19AC74ULL, 
            0x49DD63E54D9B83ACULL, 0xE4FCFBB0A6FDB6E1ULL, 0x1D1C91D1D8901D79ULL, 0x7923A18646126053ULL, 
            0x33C3795D8C67185EULL, 0xD405AB4204297FBFULL, 0x87BC34E39441782FULL, 0xCD1837C146AED901ULL, 
            0x9B626592FCF85468ULL, 0x2A6CB83F532EA8B2ULL, 0x3E5F0B22A7F9E241ULL, 0x05033181ABDCCFFDULL, 
            0xCADC294C6CB35001ULL, 0xEF0456FB92843A9FULL, 0x5C3A1F092EFE89F2ULL, 0x3473150CF7C15001ULL
        },
        {
            0xA91675FC566D00BEULL, 0x81CE5772D7E28BC6ULL, 0x43B506FEE0009521ULL, 0x7DD8E74CAD498329ULL, 
            0x0AB1BBD73D932CEDULL, 0x9E7FE898A40DDBE3ULL, 0xA825B1211898FE88ULL, 0x2BEAA0F42A7500B5ULL, 
            0xF4EFB8CBFB655391ULL, 0x1D01CA99F0BEEC13ULL, 0x1736FD5C95F0D8A1ULL, 0x31E470A9C861AFA8ULL, 
            0x018BF78CBA13E281ULL, 0xF92547210AD74A68ULL, 0x18E19804075B296CULL, 0x399A28A4CB1FACE5ULL, 
            0x51B6C046A3848BF7ULL, 0x296E587608F221B9ULL, 0x22E5E50B135E12F4ULL, 0x5EE772ECAAA47C33ULL, 
            0xDB83E77CFE94CFEEULL, 0x7C7B4A1423462F79ULL, 0xE92C32C3D682E83FULL, 0x98F9A9E672B7A6BAULL, 
            0x669051EC26564B02ULL, 0x091D5CE732DC79A5ULL, 0x7AE7C0A5DC7160C3ULL, 0x54A1FCD082DBF91CULL, 
            0xF8C05B3CA2A9459FULL, 0xCD16DEEC821F84B7ULL, 0x4C4CBE7B82146147ULL, 0x98469FC99F653824ULL
        },
        {
            0xCAB9AA38B39E25C6ULL, 0x1F5391D5349D2952ULL, 0xD867B3B0C9258A56ULL, 0xEA081976F87A75FEULL, 
            0x51D6FF98FD7D510DULL, 0xCB8B986B09624FC0ULL, 0x111793212A14C5F7ULL, 0x4D016ABC3A9DF51BULL, 
            0xA13971B5020FB49BULL, 0xE49022AA8C1D515DULL, 0x648D5EDEF1A3E9ADULL, 0xE2A8269A75919918ULL, 
            0x2B34707CE9E512E8ULL, 0xAAC4E834DDE063BCULL, 0x1ABE11E536A74869ULL, 0xC93764F630FB71EBULL, 
            0x5507CF63D4D3714DULL, 0x7FE53F6D9A83066EULL, 0xEE4308B18F4293FFULL, 0x6C729791D63B84B2ULL, 
            0x28DD5F5353237A75ULL, 0xA012A20C13141D28ULL, 0xA6F7B4CBEC9B066BULL, 0x7FAB05A9B10752ABULL, 
            0x06377534293108A9ULL, 0x201CF492F93A00C2ULL, 0xE91D03B1A30F05A3ULL, 0xF81D102AD32B680CULL, 
            0x846A7CA6CCF2129CULL, 0x31772AD0ACF7B382ULL, 0xE1874AFD751248ECULL, 0xC979A56AB60DABB8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Antares::kTwistConstants = {
    0x182767E013F050F5ULL,
    0x12E7821BFE1CB141ULL,
    0x3FB7BEEA59CD436EULL,
    0x182767E013F050F5ULL,
    0x12E7821BFE1CB141ULL,
    0x3FB7BEEA59CD436EULL,
    0x9F3877F2452F9B47ULL,
    0x0C26DEF7FA910346ULL,
    0x57,
    0xEB,
    0xA3,
    0x28,
    0x53,
    0x56,
    0xC5,
    0xA2
};

