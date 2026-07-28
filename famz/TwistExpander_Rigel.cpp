#include "TwistExpander_Rigel.hpp"
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

TwistExpander_Rigel::TwistExpander_Rigel()
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

void TwistExpander_Rigel::KDF_A(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Rigel_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Rigel_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Rigel_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Rigel_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Rigel::KDF_B(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Rigel_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Rigel_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Rigel_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Rigel_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Rigel::KDF_C(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Rigel_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Rigel_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Rigel_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Rigel_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Rigel::KDF_D(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Rigel_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Rigel_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Rigel_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Rigel_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Rigel::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF922E5F157CB1008ULL;
    std::uint64_t aIngress = 0x8A771D0F8A56DC15ULL;
    std::uint64_t aCarry = 0xDD9F77B5B00DEC32ULL;

    std::uint64_t aWandererA = 0x95BF86C1E1DAA079ULL;
    std::uint64_t aWandererB = 0x9765592A0CE8222EULL;
    std::uint64_t aWandererC = 0xCC545732F5D76847ULL;
    std::uint64_t aWandererD = 0x9B333F9C3D5DA6ACULL;
    std::uint64_t aWandererE = 0xBD1338BA46DEDD43ULL;
    std::uint64_t aWandererF = 0xAC2AAF8C607B8CE3ULL;
    std::uint64_t aWandererG = 0xC528D502667D8FFFULL;
    std::uint64_t aWandererH = 0xC3DFE93C487C7777ULL;
    std::uint64_t aWandererI = 0xEECE274E3023C603ULL;
    std::uint64_t aWandererJ = 0xC87089965A5F8E5CULL;
    std::uint64_t aWandererK = 0xBAD57951ABDAF85CULL;

    //
    // KeyRotate A
    //
    aPrevious = 0xCDA6C8205A132426ULL;
    aIngress = 0xC3CACCB643A36A84ULL;
    aCarry = 0x879A3B2D9EAB9C76ULL;
    aWandererA = 0xAEC30D516B47605BULL;
    aWandererB = 0xE1128A813F8B6342ULL;
    aWandererC = 0xDDE03338D30759C9ULL;
    aWandererD = 0xB4C3AEDBC66C85B5ULL;
    aWandererE = 0xFF7398C1122AB07FULL;
    aWandererF = 0xEB633DF2BA4F63ABULL;
    aWandererG = 0x8546C0FEAC00513EULL;
    aWandererH = 0xD082F6BEFE908519ULL;
    aWandererI = 0xCEA68D67197C31B8ULL;
    aWandererJ = 0xEC7F7C69FDACB075ULL;
    aWandererK = 0xDC3A1EAF96EC6B05ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateAConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0x805D9E355E853CB2ULL;
    aIngress = 0xBE1C8E144E0988B9ULL;
    aCarry = 0xD199001A83A5EBFBULL;
    aWandererA = 0x97EEF66A7BFABC30ULL;
    aWandererB = 0x9BF249E1CC3D4584ULL;
    aWandererC = 0xBFEC69A2DF82E387ULL;
    aWandererD = 0xDEC311E3B6B10CB4ULL;
    aWandererE = 0x8EB43A8417BD15E4ULL;
    aWandererF = 0xAC9E14DBA2D8087BULL;
    aWandererG = 0xC6B4EB0417BD896EULL;
    aWandererH = 0xE60E39354ADCEFF2ULL;
    aWandererI = 0x8EF2BE7B0FBA842EULL;
    aWandererJ = 0xC04A1026988EFA3DULL;
    aWandererK = 0xFBE32733D306E92FULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants), &(pWorkSpace->mDomainBundle.mKeyRotateBSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xF3FA50F63FBA00BAULL;
    aIngress = 0xF120D5832E9D204FULL;
    aCarry = 0xA75DEDF0C7D71434ULL;
    aWandererA = 0xEBC6822279E8A709ULL;
    aWandererB = 0xFA6DFDA1FA125A43ULL;
    aWandererC = 0xFEB62692877A88C0ULL;
    aWandererD = 0xBA2B9F5289B39B34ULL;
    aWandererE = 0xE20CF752A24AFE04ULL;
    aWandererF = 0xB7805B324B857E88ULL;
    aWandererG = 0xD5E886DE14239FB7ULL;
    aWandererH = 0xB02BB40FC031F1F9ULL;
    aWandererI = 0xD188F801355E8F77ULL;
    aWandererJ = 0xA6A502767C12AECFULL;
    aWandererK = 0xFD6A2CE62A5E006DULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnAConstants), &(mDomainBundleInbuilt.mKeySpawnASalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnAConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xEC7EB67CD0485F34ULL;
    aIngress = 0x8D7867D1291B6899ULL;
    aCarry = 0xF4FDEE544F1A6B25ULL;
    aWandererA = 0xF8E1D7D12995067EULL;
    aWandererB = 0xAAB8388A231A304DULL;
    aWandererC = 0x8E244080C5050E6CULL;
    aWandererD = 0x8E9921F7ED1F92C3ULL;
    aWandererE = 0xCBC5F517588F3D49ULL;
    aWandererF = 0xA61B40050F7327CDULL;
    aWandererG = 0xF847F7EC16E31865ULL;
    aWandererH = 0xAE081A7B76CDDE98ULL;
    aWandererI = 0xCBFE5E6BEB015F78ULL;
    aWandererJ = 0xDA9E5D89AC4D1240ULL;
    aWandererK = 0xFCDAA5ECADA33BB7ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnBConstants), &(mDomainBundleInbuilt.mKeySpawnBSalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants), &(pWorkSpace->mDomainBundle.mKeySpawnBSalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xA1E0F9119D102112ULL;
    aIngress = 0xE4437FA99F2D6D63ULL;
    aCarry = 0xF6D907B818F1213EULL;
    aWandererA = 0x87410FAEB86E5BB2ULL;
    aWandererB = 0xA40D7214D6A7A879ULL;
    aWandererC = 0xAE773783155A45C7ULL;
    aWandererD = 0xFBE10EB6D30B9757ULL;
    aWandererE = 0xC0327FF2D89247D0ULL;
    aWandererF = 0x97C63AD51FAD5EE9ULL;
    aWandererG = 0x9FED0834190B8C7FULL;
    aWandererH = 0xA386AAC9D1C79B06ULL;
    aWandererI = 0xE954565A32379511ULL;
    aWandererJ = 0xEDADEDD9450EAB46ULL;
    aWandererK = 0xBDF07FC9ECE95FE3ULL;
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mTwistConstants), &(pWorkSpace->mDomainBundle.mTwistSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mTwistSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0x84853750B73873E8ULL;
    aIngress = 0xD194F73AE13BA027ULL;
    aCarry = 0xEEC254C1E52E9969ULL;
    aWandererA = 0x9E74DB92FBDF5A1BULL;
    aWandererB = 0xBDB89E3046396F3AULL;
    aWandererC = 0xE406C166636377C2ULL;
    aWandererD = 0x93D116A5751C64ABULL;
    aWandererE = 0xC9903E7DD5F783D9ULL;
    aWandererF = 0xF38D79CD28F3F133ULL;
    aWandererG = 0xDF5038ACB6F1EA52ULL;
    aWandererH = 0xB25067FB4891E5D4ULL;
    aWandererI = 0x9EAAB0EAE420ED15ULL;
    aWandererJ = 0x930B4BA91FF6C5CAULL;
    aWandererK = 0xD0ABA8FB24A39866ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xC0C16C6107F5D453ULL;
    aIngress = 0xB647BB3C4D49BF71ULL;
    aCarry = 0x87ED458D177BED43ULL;
    aWandererA = 0xF5C1BC110EADECB8ULL;
    aWandererB = 0xC7A4353CE87BA7AEULL;
    aWandererC = 0xB8FBADA4D732D64FULL;
    aWandererD = 0xBF11D6BAC2663A51ULL;
    aWandererE = 0x9A78A7B6CA4107D9ULL;
    aWandererF = 0x8EC56F2B12229AE8ULL;
    aWandererG = 0x8350A26DC9FCA56FULL;
    aWandererH = 0xD6F40C379B0CB9D4ULL;
    aWandererI = 0xB448B77B0CB803C7ULL;
    aWandererJ = 0xDECE640F0D53C98AULL;
    aWandererK = 0xACBF8E148C7516A9ULL;
    //
    TwistExpander_Rigel_Arx::SEED_A(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Rigel_Arx::SEED_B(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Rigel_Arx::SEED_C(pWorkSpace,
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
    TwistExpander_Rigel_Arx::SEED_D(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Rigel_Arx::SEED_E(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Rigel_Arx::SEED_F(pWorkSpace,
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
    TwistExpander_Rigel_Arx::SEED_G(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Rigel_Arx::SEED_H(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Rigel_Arx::SEED_I(pWorkSpace,
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
    TwistExpander_Rigel_Arx::SEED_J(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Rigel_Arx::SEED_K(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Rigel_Arx::SEED_L(pWorkSpace,
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
    TwistExpander_Rigel_Arx::SEED_M(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Rigel_Arx::SEED_N(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Rigel_Arx::KEY_A_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Rigel_Arx::KEY_A_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Rigel_Arx::KEY_A_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Rigel_Arx::KEY_A_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Rigel_Arx::KEY_A_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Rigel_Arx::KEY_A_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Rigel_Arx::KEY_A_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Rigel_Arx::KEY_A_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Rigel_Arx::KEY_B_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Rigel_Arx::KEY_B_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Rigel_Arx::KEY_B_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Rigel_Arx::KEY_B_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Rigel_Arx::KEY_B_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Rigel_Arx::KEY_B_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Rigel_Arx::KEY_B_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Rigel_Arx::KEY_B_H(pWorkSpace,
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

void TwistExpander_Rigel::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA0F79897C287D3F5ULL; std::uint64_t aIngress = 0xDE7B6929AD6F6BE6ULL; std::uint64_t aCarry = 0xED5DFF757AC68AD9ULL;

    std::uint64_t aWandererA = 0xB03920731214D0F6ULL; std::uint64_t aWandererB = 0xF74FB290C70AE3D9ULL; std::uint64_t aWandererC = 0xA79722C969478AA3ULL; std::uint64_t aWandererD = 0xC5EAFF9D6B21FF67ULL;
    std::uint64_t aWandererE = 0x8B50426747A61E56ULL; std::uint64_t aWandererF = 0xCB4299D7A9003779ULL; std::uint64_t aWandererG = 0xA9838C1956A19F12ULL; std::uint64_t aWandererH = 0xEB218C75FE5166B5ULL;
    std::uint64_t aWandererI = 0x8C1ADE1C9EDDE2C7ULL; std::uint64_t aWandererJ = 0xBA2A0EBF2028057CULL; std::uint64_t aWandererK = 0xDC8E0F9533376F57ULL;

    // [twist]
        aPrevious = 0x8A3BDF861D4B7E8FULL;
        aCarry = 0xAEEDC0F0537B3D4FULL;
        aWandererA = 0xA76FD3C87CF22F62ULL;
        aWandererB = 0xC6AB6B80FCFFC49DULL;
        aWandererC = 0xB0969207DC381E8DULL;
        aWandererD = 0xC8242447A4E8042FULL;
        aWandererE = 0xB7321530C8C6CB9DULL;
        aWandererF = 0xAD50CE034A3D32B4ULL;
        aWandererG = 0xAAB43F25C3931EB4ULL;
        aWandererH = 0xFF804C25AF7F888DULL;
        aWandererI = 0x91979F6E06BD879FULL;
        aWandererJ = 0xE22ABC092A79F657ULL;
        aWandererK = 0xB94082A17D0A694CULL;
    TwistExpander_Rigel_Arx::TWIST_A(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Rigel_Arx::TWIST_B(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Rigel_Arx::TWIST_C(pWorkSpace,
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
    TwistExpander_Rigel_Arx::TWIST_D(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Rigel_Arx::TWIST_E(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Rigel_Arx::TWIST_F(pWorkSpace,
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
    TwistExpander_Rigel_Arx::TWIST_G(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Rigel_Arx::TWIST_H(pWorkSpace,
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

void TwistExpander_Rigel::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Rigel_Arx::GROW_A_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Rigel_Arx::GROW_A_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Rigel_Arx::GROW_A_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Rigel_Arx::GROW_A_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Rigel::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Rigel_Arx::GROW_B_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Rigel_Arx::GROW_B_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Rigel_Arx::GROW_B_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Rigel_Arx::GROW_B_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Rigel::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 29 of 33
    // Exploration cases: 0
    // Structural maximin 511 / 674; family total 14911
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
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4188U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 137U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3648U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4098U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1330U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1510U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 137U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1645U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 92U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1465U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1915U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 29 of 33
    // Exploration cases: 0
    // Structural maximin 514 / 674; family total 14877
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
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3108U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2838U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3018U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2928U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1240U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1060U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 430U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 790U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1015U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 610U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 880U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 745U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Rigel::kKeyRotateASalts = {
    {
        {
            0x5BBB17F3900CE8BFULL, 0x331FB65E2FAE1645ULL, 0x360F548AE64FA33DULL, 0x7A1A641D11D4AA09ULL, 
            0x0A1FFB754AB092ACULL, 0x93C3D955BE3A60BAULL, 0x42D430ACEF811282ULL, 0xD7695D616442AC11ULL, 
            0x2199136ABE86C3E3ULL, 0x82D5DAE8F1D2D058ULL, 0x7710B3E1B94E9684ULL, 0xBA97E0CDAB34D9C7ULL, 
            0xF4227E469E7DB8E0ULL, 0x6548332A0E45C920ULL, 0x4AC4FA6BCE05606DULL, 0x59E2A2E21A55B367ULL, 
            0x75369C14132E870DULL, 0x16C723C2D21EA0ABULL, 0x8B46D929204BD6DAULL, 0x97F5F617E8AA1293ULL, 
            0x6B4DBB00675CFCF3ULL, 0x3EE2E3138EE71701ULL, 0xC1072B9C0D7B8247ULL, 0x2EA46B2DB2A271F6ULL, 
            0xF8805317DF9EABABULL, 0x372001518EACC071ULL, 0xD102A3CCF04EBEDFULL, 0x61DFBD1785F1C24AULL, 
            0x201E2F3DF8CE9E28ULL, 0x04BEA472A1A21501ULL, 0xCB402CED060259BEULL, 0xA47689B23016F884ULL
        },
        {
            0x53A09D1E21F0B872ULL, 0x73E34A6DE982DF30ULL, 0x3DB60DB8AF33C949ULL, 0x8D46B0BCB33D5173ULL, 
            0x033C5027A8AF83E3ULL, 0x9C6AD2B735086E17ULL, 0xA5942436210FD351ULL, 0x4C7EFC0EFD9D8DE8ULL, 
            0x475035B6408EC2ACULL, 0x204A956211AE8A93ULL, 0xF03447457D463861ULL, 0xC02D2D68865FB762ULL, 
            0xA4428FCEACCDA42EULL, 0x639EFC724ABC59DBULL, 0x8D0536C8879A9097ULL, 0xC6BE4D5ACFD55A80ULL, 
            0x92DB9414BC55BF74ULL, 0xD10768684C78636FULL, 0x75CCFAB66D9BC5F7ULL, 0x221AE1B16F6840D4ULL, 
            0x26CF555A8E6635B5ULL, 0xB6B73DCDC14C8545ULL, 0xB3379909CF17AE52ULL, 0xD5C658D48101CA65ULL, 
            0x6114BE1F01340C7EULL, 0x7DD90938BC748128ULL, 0x6D24E15EA76C78ECULL, 0x12D6E91C94CD9FE2ULL, 
            0x7CCE2A96438426C8ULL, 0x0B6D001792FEA62BULL, 0xB61F11520DE778B7ULL, 0xB528CEA398D5A602ULL
        },
        {
            0x86049C6EBCD15A77ULL, 0x73CF6216DF3A9AB5ULL, 0x8009E37EC0772C3CULL, 0x8276D7E4ACDFB6C6ULL, 
            0xEEFFCB340154DA2CULL, 0x385B3513E85A63ACULL, 0x243BD502295DA043ULL, 0xFBB33CB209D4035EULL, 
            0x87635EB6C5C517C9ULL, 0xBCFC37540B8B6406ULL, 0x383A01E102134694ULL, 0x726060E5B0C2B797ULL, 
            0x6659C4C3C73105BAULL, 0x9629EC8240304210ULL, 0xA34ED2D96B3F864DULL, 0x05FBE77D4E6CB941ULL, 
            0x99641D3F640D46B4ULL, 0xD6B079FED31F728DULL, 0x13CD1F1DCD8DA791ULL, 0x10B691BCB4251612ULL, 
            0xCCCF59F0E52B7233ULL, 0x5908C17C0E33A0AAULL, 0x9CE1D99BE3555E4FULL, 0xEF304D2DA7B974C6ULL, 
            0x7F3DEA99A592285BULL, 0x06792C964BB9F6DDULL, 0x796804379E13F83FULL, 0x44F843B8EC281AC5ULL, 
            0xCD3CC47417F14DD8ULL, 0x084112AAB5DF9497ULL, 0x9E62EE669F70C89CULL, 0x2A49A1F408F95CFEULL
        },
        {
            0x1C0E58A2FBCEA5F3ULL, 0xA62A0A554552BB03ULL, 0xEBC41FE5B78DF908ULL, 0x9D50704D0525E5CEULL, 
            0x187A55245EBBA51BULL, 0x02A0C97CCBEAE20BULL, 0x6F3F2D7C43F0E588ULL, 0x88B05895994F9BFBULL, 
            0x79EE14073D36420EULL, 0x15BE2CD8DA128F3FULL, 0x90D13154637F5C8DULL, 0x7A238AFBEB23C686ULL, 
            0xD793EBFAD751BBDAULL, 0x43BF534C9623476FULL, 0xBBC92A4A08736D08ULL, 0x7FEE21C43127D62BULL, 
            0xA26709335CD37E18ULL, 0x767AB54B14152570ULL, 0xB249154881CE7F98ULL, 0x718BC826441AD67BULL, 
            0xADB650FF9A643257ULL, 0xABD31C707FFDF2B2ULL, 0xDCE4C0D0B68E27EAULL, 0xEB1A5D0D65A8B7AFULL, 
            0x9D6AB7D3A81DE3B6ULL, 0xC7611653E402D147ULL, 0x485D592A1D46EBACULL, 0x82F4C19F8493D251ULL, 
            0x24AF8A25B5AF546DULL, 0x79F07FD0BB49B027ULL, 0x3F4DB786423F4872ULL, 0x708FB23FEB61E679ULL
        },
        {
            0x1A8246DC3B6A2C2AULL, 0x544CCCAC97D77620ULL, 0xE5C334549C29A421ULL, 0x65DBDDA9BC00EB4EULL, 
            0x93655CEEC67786E1ULL, 0x2EB893B3009DABE7ULL, 0x541B39268333040CULL, 0xD9F3DF87CFBC02ACULL, 
            0x423851D9496E4D91ULL, 0x94BD04391CD71E0DULL, 0x5FFAE162EBA84A35ULL, 0xDF4DD2CDBCC85CCFULL, 
            0x575F9BB8016A456DULL, 0xD951995830C661DCULL, 0x4C30FDCBAC075C70ULL, 0x949B510D0C282FADULL, 
            0xCB97947789FF789DULL, 0x676AFF803DD3B96EULL, 0x403DE47368814BC3ULL, 0xDA8E724D9830380FULL, 
            0x7D95BA2DBF0C0090ULL, 0x6EA87A588D097B0CULL, 0xCBFBEB074FAC683FULL, 0xC1F2ADC6F361DE18ULL, 
            0xAF9F5BFEF6D712B3ULL, 0xBE2848CB28850842ULL, 0x8BAD8241FD73907AULL, 0x75A9EFC1B472FC50ULL, 
            0xC1E4C0C28C7568F9ULL, 0x9B95BD4749BDBDC2ULL, 0x0A1BBDD48EA284DFULL, 0xDB5DB100EA469A18ULL
        },
        {
            0x0F4AE2515895AC7AULL, 0x76F5ECEE61A18AB9ULL, 0x77A8B81A9033E2E2ULL, 0x03E8D1FC3405E12DULL, 
            0x90700E811772B4E5ULL, 0x0D8B32A814E48729ULL, 0xBAE34EBBB21FAA91ULL, 0x452C18AFF3046CF1ULL, 
            0xE43B3C40ECFC8488ULL, 0xF19BE1A0F97E5FEEULL, 0x4A952100BCCC9642ULL, 0xD062536D17AC0DA3ULL, 
            0x54A2FB9297D09D10ULL, 0xEF2A4D02E41C4FE1ULL, 0x263C7779BCE41422ULL, 0xB4631AAD01D792BCULL, 
            0x22072414CAC20B90ULL, 0x3A7B5400C1EC92D3ULL, 0x9FD71ADE878E1576ULL, 0xF224AAB1CE1943F7ULL, 
            0xFE760403A8018510ULL, 0x89DDDD18CC8D8D8EULL, 0x512E03C94E71E419ULL, 0xA30F1744D6AB5144ULL, 
            0xB01570EAC673DF6AULL, 0xA6B7FEFC09FCFAD4ULL, 0xD771812B9EB95218ULL, 0xB686F7C2C27275F4ULL, 
            0xD83FBA51EC7C90E9ULL, 0x62A1C5C7030CF18CULL, 0xEACA92522CBCBD58ULL, 0xA8D81C51D34EFD97ULL
        }
    },
    {
        {
            0x3BB15F98351605F7ULL, 0xA47EBC2B9EC0C343ULL, 0xDB20802AB518B1B0ULL, 0xB3EA8655F8D17C37ULL, 
            0x98774AE0056F10C0ULL, 0xA85492D40CD6EF00ULL, 0x74011F1E2DFDD0E5ULL, 0xB93AF6F4D1D0118FULL, 
            0xE1A71BD1DFC12233ULL, 0x6810BB33BAC2D1B3ULL, 0xA1039E9DD4EA3103ULL, 0x7383E7776548A26DULL, 
            0x3C0BDAF58B323082ULL, 0x23540799C0E1A634ULL, 0xD41AEA2E6FF8B4EDULL, 0xB302DCBADC7910E7ULL, 
            0xB58B45B3E0A7164CULL, 0xCCDB617DE545011DULL, 0x0C9272AAE2E71E36ULL, 0xD486E34D604086D1ULL, 
            0x8826AC11F7D2D66BULL, 0xAFF73157CB962925ULL, 0xB04E7D1CD89417A0ULL, 0x1291536126E3319CULL, 
            0xADF5260DB95F158EULL, 0x77C4001F50B1BF5CULL, 0x56A8177A38508830ULL, 0xEE440BDEC5A283B0ULL, 
            0xF42CD53EECBD0D40ULL, 0xEC661AC391D41CFAULL, 0x6ED01DFA84ED5419ULL, 0xAE07B7141EDB0441ULL
        },
        {
            0x80CD2DE3940A36C4ULL, 0x1FD94F059169B493ULL, 0x84DEA942260E5C33ULL, 0xCB7EB0831151ABE9ULL, 
            0x045544E981E354DCULL, 0x37E9B6E536ED6BC5ULL, 0x04669015C0E088C5ULL, 0x755D842595F8B00EULL, 
            0x130EDF89C4705108ULL, 0xD23A015423B5989EULL, 0x44E60219189A7861ULL, 0x842EBC0A110456F4ULL, 
            0x2FA315F6FCCDCCA8ULL, 0x6F4F3357D7EE3325ULL, 0x659D77714EA5C50FULL, 0x3F5941FD372912DCULL, 
            0xA7E8E918DE555E45ULL, 0x41B343780CB3507EULL, 0xD87B47C3A2DA0262ULL, 0x8D4E9FB4B06B6271ULL, 
            0x3B5405E3F22F6F39ULL, 0x0D42EB5F0ED6C669ULL, 0xA04A4B4A59C48846ULL, 0x222C9D875ED68103ULL, 
            0x88D7C7FA2A34D2BDULL, 0x192C5D2E97348E9AULL, 0xD83DD66C05C07B02ULL, 0xE7ABD66CCFFDEF08ULL, 
            0x141FEC4CFE4E4450ULL, 0xDA70A682574A7365ULL, 0x2016AC59C15AD5CCULL, 0x638187CFBA5C55AAULL
        },
        {
            0xE9D4D36B8295ABA5ULL, 0xB041E087D59AF07BULL, 0xF5B8C89342BE49F1ULL, 0xC8CA821302194283ULL, 
            0x2481F9CE80A06384ULL, 0xFD90A5193C8EFE09ULL, 0x9CBD3097A4A293F2ULL, 0x8BDA4F0250B8B961ULL, 
            0x8D934B1C525D10F9ULL, 0xB751D9720C07CD01ULL, 0xC2D9F11DD7537A0CULL, 0x6D49CCAB20FFB653ULL, 
            0x84F64E32405B8A81ULL, 0x032AE3A98E748BF9ULL, 0x5E03DFB868C4B31EULL, 0x6B738664A812AF18ULL, 
            0x4E338DEB48097B96ULL, 0x97F56D499EE832EDULL, 0x98A1BE1BD2337FA8ULL, 0x3FD0F1EF396462B7ULL, 
            0xA4875FFA4FBBE5C1ULL, 0xDF0B53A4595565AFULL, 0xA13316EF0D925440ULL, 0x91B6E8D1C6A1B552ULL, 
            0x9B1DD270EB4CC42CULL, 0x17428CAE97450A9DULL, 0x4C5E3B82BE78BE82ULL, 0xAFE518A02974CAA7ULL, 
            0xDF0845BA5A76B8BFULL, 0x40B4DBF4E2F917BCULL, 0xAD50755633F12C6BULL, 0x141865D936C4EE3FULL
        },
        {
            0x194B8363A6EDAE89ULL, 0xB1D32EC181B09276ULL, 0xC41F3C9F3B057945ULL, 0x2D1971FABCD9FDC9ULL, 
            0xF42F1D1EBC6F91F0ULL, 0xFBE7D0C108493BC9ULL, 0xA752B358648403F8ULL, 0x5F63E9611A791ED2ULL, 
            0x81DECE2800CC906EULL, 0x65E292D2D225D678ULL, 0x59313AA48B1BE86AULL, 0x0134D7C2442C4E37ULL, 
            0x23932CE06FC56026ULL, 0x959660941219C3C6ULL, 0x0D5BA5759B274322ULL, 0x60915413CADD8776ULL, 
            0xAADE3AE8573F8C7CULL, 0xB17389F1E909999DULL, 0x1125BBACB0194230ULL, 0x933928E98F51B0C7ULL, 
            0x714DB64BFA178814ULL, 0xAD3588F27A7F8FFCULL, 0x29E259BA0737D9CBULL, 0x739EDECD5D17146EULL, 
            0x921711A41EFEBE48ULL, 0x4493C482CCE8F224ULL, 0x230E58C3C48C6E16ULL, 0xA09A60FC5FB17299ULL, 
            0x6E13DB524A67C02AULL, 0x1280D880D286F3CAULL, 0x3FDE205BC3AD50A6ULL, 0xEC77595F88877599ULL
        },
        {
            0x946BF3B5FD11AF29ULL, 0x2B6B8D23D5F87514ULL, 0xD8122A14AF255E7BULL, 0x13DE1467DB2DA8A0ULL, 
            0xC71E69E2E8AF1300ULL, 0x4B78E75A38D787B0ULL, 0xE4F8AD945C3E7CF9ULL, 0xA4870A76E79E2852ULL, 
            0xE92D97A89E344C3AULL, 0xB9EF069A27390A90ULL, 0x53453A2945CE10A1ULL, 0x85069EA351CB6E9CULL, 
            0x33FBF60638A63385ULL, 0x49EF113A285909ADULL, 0x1D1C03B7E2332FC9ULL, 0xE32CE447919DBF39ULL, 
            0xFBAC811B990B347BULL, 0x291B269F95D11277ULL, 0x7A9D45D9F9ED0610ULL, 0x0799DC82499269E6ULL, 
            0x8395EF8048A13FC0ULL, 0x3469E39D20D2B49AULL, 0xE45E36AF34EB7645ULL, 0xFA960C4125589E29ULL, 
            0x3FB6C90191C1EA13ULL, 0x7716219EF49E79E0ULL, 0xB83A66EE232ADB26ULL, 0xA87B455051EF3769ULL, 
            0xF4A3C6EE7D40E71CULL, 0x645797D3D75292DBULL, 0x8A3FF1318079B1CFULL, 0x1DF2A4EC582CC8A1ULL
        },
        {
            0x5AEC7D2BB3088F7BULL, 0x9E80C8BCD514C865ULL, 0x1EF0D5ABEA5484E9ULL, 0x4C51CE0127BA86BFULL, 
            0xE1E1695048A7A4C9ULL, 0x4B83262BBB50FFD8ULL, 0x6B490466ADF69104ULL, 0xDC5ED67406DF2769ULL, 
            0xAB419D2C26478188ULL, 0x4171E42BB46E45FAULL, 0x5623CCA2C0EC574DULL, 0x15FA052D9D4E2461ULL, 
            0xA318C0CD0F59B034ULL, 0x3B1C553CD92B178DULL, 0x97D2D5E1E6C669D8ULL, 0x91534168F63DB123ULL, 
            0xEE055D55C84A0279ULL, 0xFBA0AD0E316B220AULL, 0xCB25522C332C28F3ULL, 0x7181282B1C835572ULL, 
            0xCB01A76CEB081A51ULL, 0x163595870983C905ULL, 0x2487DD6ED21E4E12ULL, 0xA21CAFA103DC7E51ULL, 
            0x67054468D899AC49ULL, 0x7A4BDEA54A98F89FULL, 0xABB58D652488AF5BULL, 0x593B6F2F17568167ULL, 
            0x3B241D62B5B1E399ULL, 0x21B24CA86045CD0DULL, 0x473CC0E6C6721709ULL, 0x2164F091F185C6C1ULL
        }
    },
    {
        {
            0xB029524FA4D96C2CULL, 0x547048F8983F857AULL, 0x72A8229D846AF23FULL, 0x789A2784BA390A20ULL, 
            0x8284073302439B15ULL, 0xC51588B6643857BEULL, 0x58D9AF7773DEC1C6ULL, 0x93AE8C569C5CF66CULL, 
            0x27BB7331EC0E670DULL, 0x4A7BBD9FFDFF8593ULL, 0xD1834D4126F00B6CULL, 0x02622DDB6480BCB6ULL, 
            0x0DC32E2BDE0962A7ULL, 0x5C6C80029913C450ULL, 0x94FBC157484C0792ULL, 0x2880D50F9502849CULL, 
            0x1C854ABE3B480A52ULL, 0x1E4AD5FC79EADE63ULL, 0x9A41C21108E52BCEULL, 0x87552E4625064899ULL, 
            0x9F33BB78513FD370ULL, 0x017725DA3858C84FULL, 0xE1508079D3F90CB7ULL, 0xDAC82C9C815D18A6ULL, 
            0x1937AF7AACDBC7FBULL, 0x47D914D315C74C62ULL, 0x158FC71E0D11F984ULL, 0x0E9DC47FB7233EC0ULL, 
            0x37B7AEF8BA7C9043ULL, 0x8B05CCB112CDCA40ULL, 0xA6DC625DB367A856ULL, 0xFFD6E8B0627BD564ULL
        },
        {
            0x41D7B35F5E8755EFULL, 0x14931B6F55E84789ULL, 0xF951084964030997ULL, 0x2D9357E9D952F9FCULL, 
            0x7E255D2357CE3834ULL, 0x83F12B1534A1A907ULL, 0xA18338B424A7C976ULL, 0xEFD674A9E2366E31ULL, 
            0xEB267C85473804E9ULL, 0x1CA9D7E56175E442ULL, 0xA37DCAE9C0391C14ULL, 0xFF9C24CA2795919FULL, 
            0x6939A5732293B242ULL, 0x9EB78241B21C3F73ULL, 0x9FDBF54206C4C72DULL, 0xDCDCE45AAD17BC26ULL, 
            0xEC8A760FE2AB57D9ULL, 0x27511F785D6C7E17ULL, 0x5FE1D4ECF6D9EDEBULL, 0x2FDAF233731A3122ULL, 
            0xEC8E56731875B1A9ULL, 0x951BD03A37FD5149ULL, 0x5D471738324F912AULL, 0x58FC033B1BBC38B3ULL, 
            0xE612BCEE409A1728ULL, 0x31000E141A9B28E7ULL, 0xC9F59A8D66225E5AULL, 0x5B61B74B2C77B075ULL, 
            0xC3F1DFAB46AA0352ULL, 0xA0C8C879FAB17587ULL, 0xB6402332351C3B12ULL, 0x9C840FB24CC039C5ULL
        },
        {
            0xAB4B5A1FB7FEB297ULL, 0x4312BF4DF322D400ULL, 0x09FC106E673DB191ULL, 0xEF197806A2AC864DULL, 
            0x08F3781443BA72BBULL, 0x34FA69F3806F4155ULL, 0x80B1E308152ADA1EULL, 0x5764D6ACD5C680A6ULL, 
            0xB5C12A9F251D9586ULL, 0x6EA58802A459D6AEULL, 0xEFBD0A9309F9D9AEULL, 0xD36E1939D2371E29ULL, 
            0x6C8D7B9DA79A2E74ULL, 0xDEA74A97468F5F21ULL, 0xDC6B73E1AFDCF807ULL, 0xA6133BE38CA5882AULL, 
            0x1859C37FD3C843C7ULL, 0x48D25FB31E99FED0ULL, 0xA07035F13E81D624ULL, 0x98630FB30B3EE9C2ULL, 
            0xC10BD8A0DBACB97FULL, 0x0C91A6B0C53A9AC8ULL, 0x0C7518758B34EF1DULL, 0x3E0332AC3D7B63A8ULL, 
            0x45514A37C83D603EULL, 0x4F4F8EE730F21DE2ULL, 0xC2E65C6810C00DD8ULL, 0xF9FF1FF091EBAE7CULL, 
            0xAF1A5D908A674FA0ULL, 0xF0A87E2E54A99CB1ULL, 0xB7B44F175911EDFFULL, 0x3D82CD0DD9F80222ULL
        },
        {
            0x704F19067579B5B3ULL, 0xF9F00B405E131D06ULL, 0x0813FAE76E364656ULL, 0xF3564CE9478A7F05ULL, 
            0x45A264F18B82FBF7ULL, 0x0A50C2476055CFDFULL, 0x4DB3B4B5897C08D1ULL, 0x4ED0F3398C5D35FBULL, 
            0x59D0297348EB5BB8ULL, 0xF0F92D159F7739FFULL, 0x7048F1343BCC2736ULL, 0x498CFA2EABC4F3DFULL, 
            0xEE35CFF7FBBEA031ULL, 0xCD7C597B5F943BCFULL, 0x37C2463666E3C87DULL, 0x25F7991EE34FC55FULL, 
            0x4F35233DB0B25031ULL, 0x064E8B4C2AB1E1FFULL, 0xE4FAC09A0B9CF531ULL, 0x762C071934BED10AULL, 
            0xF1D6B1450F49811AULL, 0x03A0846393C9681CULL, 0xBAC50BC99CB2C6DEULL, 0x5A8F716173E13D1AULL, 
            0x41208F3EA44818A0ULL, 0x5A9FF12E99938F68ULL, 0xA5F48EDA13A1D2B7ULL, 0x4C3E8808AE8ECDE2ULL, 
            0xC26C9E8A4AB6760DULL, 0x69ACAEC150599735ULL, 0xC583C298BA8DBBD8ULL, 0x67ABF0F9273C7954ULL
        },
        {
            0xB6E34F113DC1FE86ULL, 0x75EA1A83FCEB8F2FULL, 0xAC811CCDC158CE81ULL, 0x6802CE9CC34E00EBULL, 
            0x2A893404EC667CF1ULL, 0x0088F736059D5037ULL, 0xD1D3F161AAA3A8C4ULL, 0x316C4A2554287DBCULL, 
            0xE18B544C64AD7D0CULL, 0xCA962ACE38BA929DULL, 0x2D7A20CB31DD3E85ULL, 0x1C15B8C7728A5EF4ULL, 
            0x8BA01D2962D491AFULL, 0xB626839047E4DD58ULL, 0x4429ACFFAAE4AA2EULL, 0x8A92C50A49F2F9D5ULL, 
            0x9FFE7E5B938E4875ULL, 0xD947155CA8C20C11ULL, 0x64AA10E5D3C30C3FULL, 0x52616B910BE9A7C3ULL, 
            0xC4BA3ABF4FA990EBULL, 0xB59C9EBB78F939AAULL, 0x44C8328A70D72675ULL, 0xBD40D79CABECE3CFULL, 
            0x3930E886A5A7CD73ULL, 0x0623A0AE37E3C9CDULL, 0x683AF03E7D246DA3ULL, 0x218AEF64C121EB29ULL, 
            0xBC42D872477B4483ULL, 0x916AEAF658FBD278ULL, 0x138E53ADA2A1F9CAULL, 0x1EE5F60559011D5AULL
        },
        {
            0xBC9198B11ABA4D2EULL, 0x1375559093B2A269ULL, 0x7CB5DA3B094E6216ULL, 0x13EE546F20AF7824ULL, 
            0xC468E1B85289ECD2ULL, 0xA013F7248FE998CFULL, 0xC7566730CB54443EULL, 0x2182BE95FDEBAD78ULL, 
            0xF0E46987138B0F9AULL, 0xCF370BF2764E2FA4ULL, 0x884A935964C07D9CULL, 0xDAFE71CA2415498EULL, 
            0xD0D5BE58E37C33DBULL, 0x2E3746E78BEA4086ULL, 0x6CDFFF4C77040319ULL, 0x96A9BAD706C944DEULL, 
            0xAC5BE7C794CAF3CAULL, 0x6D0C946ACDFA91B3ULL, 0xAC01986A759E1BE7ULL, 0x8302363BF6F490A2ULL, 
            0xD13FEE1B162E7D72ULL, 0x828F099978B529B5ULL, 0x6DFAC9289719025CULL, 0x141049113DF39B6CULL, 
            0xC81045C02531CC85ULL, 0x652B2FA7FB3F3637ULL, 0x1885940EEB6067E0ULL, 0x7D228E7D2A2AC897ULL, 
            0x5FCA09114FBC451BULL, 0x5BB874926654438AULL, 0xDFA66382E5FDC694ULL, 0x564AA5B50AC3DCF2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rigel::kKeyRotateAConstants = {
    0xAE1439FD24F52749ULL,
    0x7CA2E66E839654BEULL,
    0xA0853A0A21FDDD4BULL,
    0xAE1439FD24F52749ULL,
    0x7CA2E66E839654BEULL,
    0xA0853A0A21FDDD4BULL,
    0x4CE7CB4260904339ULL,
    0x6041E6C158BB2408ULL,
    0x83,
    0x45,
    0x34,
    0x1A,
    0x98,
    0x01,
    0xEE,
    0xC6
};

const TwistDomainSaltSet TwistExpander_Rigel::kKeyRotateBSalts = {
    {
        {
            0xFCF35C96D7610106ULL, 0x380B47A706801D32ULL, 0xA7FC4E11ED44AEE7ULL, 0x73D2659F5D324A8EULL, 
            0x9411CE667DE98B07ULL, 0xB4EDC94610F90177ULL, 0xA770827C52ECF2A8ULL, 0x2EA2450EF26CB946ULL, 
            0xB4C71F9AFE83B9E5ULL, 0xC4A8DD2F34E312CBULL, 0x7F26C197CC0DD0E8ULL, 0x97FE306BBA402350ULL, 
            0x481CCF2C0CA7571EULL, 0x1986F088C596D95CULL, 0x8267FD4089BDF1F1ULL, 0xC4A9F0872C9137A9ULL, 
            0xAD6CE4877F8ECF7EULL, 0xA751F2CBA98B11A6ULL, 0xA26C9B4337DAE08AULL, 0x7D70ACF61980971CULL, 
            0xF0C0E5A34C604A97ULL, 0x2E4F3E06BD1A085AULL, 0x0920FEC2F9B2B1B1ULL, 0x1AB0B49BD8D405D0ULL, 
            0x3BDA7A8DE7CDDBE1ULL, 0xBCA0B08890CBDC6AULL, 0x2B278AB8F63EE90AULL, 0xA276FEE771214248ULL, 
            0x5CCD95F8F7B18865ULL, 0x3459E37061038E6AULL, 0xE8D1D636839B73FEULL, 0x2A3316A18A9FCE0FULL
        },
        {
            0x91A9181C0AA538D9ULL, 0x8DABBC2EBC16BC77ULL, 0xD1A9B8A295126BFEULL, 0x88BFA8D7609A5F3DULL, 
            0x3AFD357D59AE39DAULL, 0x593998CB71A6C4BDULL, 0x57C861EB60C8B6D7ULL, 0x49BAD796EAE1276FULL, 
            0xB588E3AA9315A865ULL, 0xD77152EF42CD3C8EULL, 0x9C2C7738B3481BB6ULL, 0x4EBC6491289B5BF5ULL, 
            0x328B79381D4C7D42ULL, 0x407A6945423EA7ABULL, 0x1EBA751C2A4098D3ULL, 0x803899FA9324779EULL, 
            0x0029ED62A9B3476AULL, 0x50FB8B8E6EEFF7DFULL, 0x2E24388CC6D87743ULL, 0x3DB74F72C6DED502ULL, 
            0x93FFA0126D7D9868ULL, 0x22AE39CC8565400DULL, 0x73D3C174716D1D10ULL, 0xA9E6183605A11ACAULL, 
            0x0323A9683BEBDA3EULL, 0xFBEA4FD3DA66CB4EULL, 0x7334000CF4DFB8EEULL, 0x98F28A11CEC11A27ULL, 
            0xB2C4501E259017F6ULL, 0xBF09B0ADC6D76A2DULL, 0x1148C8A9CE363F26ULL, 0x38B107721D74D3F8ULL
        },
        {
            0x4507579C09AE1BC5ULL, 0x2D17ED6237A91AFBULL, 0x987FEF1DCCA5FB32ULL, 0x65DCC4C0826D7AA8ULL, 
            0x2958E9A24B013416ULL, 0x1625D9903509B157ULL, 0x9E21FD845468F848ULL, 0x1AEC8DCC1E550E2DULL, 
            0xC9C498810212D285ULL, 0xDD204CF4111FEA55ULL, 0xE11E610D76FC7459ULL, 0x619136AC11FC88C9ULL, 
            0x8DA29FBC9C9CABB6ULL, 0x1499109A771A4386ULL, 0xA7A23779F4F621B3ULL, 0x9A614973CE669C5DULL, 
            0xB1B805C9127F284FULL, 0x5F76AECF322710F4ULL, 0x1E6048E0AE1E1C79ULL, 0x0AFF4C983BFC2BE3ULL, 
            0x4A1658EA4F74E1ACULL, 0x68E395EB20CC1F31ULL, 0x4B66B94C79D8C428ULL, 0xFC0B650372AE3010ULL, 
            0xB4D400D1DEBBE174ULL, 0xE8714E1E8D8737BCULL, 0xB74F8BF0E08543E9ULL, 0xA578E1DF8922BCE5ULL, 
            0x42F50998E2308737ULL, 0x7D376E6B40FE2DDCULL, 0xF53725DF19339CE5ULL, 0x596AE545840841B8ULL
        },
        {
            0xDAF146C2C09120A9ULL, 0x07E274F5068CDD1BULL, 0x626557EAB681E4F7ULL, 0xC38F0EA31AB27E58ULL, 
            0x9D71C2A34E48AAB1ULL, 0x70A225B9A470B8ACULL, 0x9FC99C61B1EE922AULL, 0x60270584207CCA5EULL, 
            0xE06E613C41539DFDULL, 0xA407342A12A99E76ULL, 0x141C1700B62803BEULL, 0x2C006CC6E92A616BULL, 
            0x38358117158E9AD0ULL, 0xBE3738C32E231D45ULL, 0x010C26CED4AC061BULL, 0xBE4E599FD217F3E2ULL, 
            0x8B0C230731CACF9AULL, 0x6938EEB3E6A23A20ULL, 0x86A532818B15286AULL, 0x8897E36E5E892328ULL, 
            0xB1D61BC264152D15ULL, 0xBD744729D208316DULL, 0x4CDD6D7487712975ULL, 0x24B452BD394AA3FDULL, 
            0xAE7EC7C234CFE7F1ULL, 0x996AEE64D684CBEAULL, 0xCA6F30D7058D2004ULL, 0xD3F6AC8C6576E5FFULL, 
            0xD23E5C78D0626F85ULL, 0x65FA143B9EB52854ULL, 0x595007FA3DF37538ULL, 0xF241C1CCF3A982E5ULL
        },
        {
            0x653F2E601E767901ULL, 0x5346FCBC558BF4FAULL, 0x830CCC1858FBBA40ULL, 0x721751161E311F7BULL, 
            0xC1E167122581AD31ULL, 0x1F274771DA56F112ULL, 0x9CDF3EEC84973F18ULL, 0x064666F3E405B41EULL, 
            0x79DDB610D68256FFULL, 0x5F33DB179D5EAB8FULL, 0x2F34CDCEB9C9E4BEULL, 0xB9494DAAEB5185DDULL, 
            0x8426FF69F0D530C6ULL, 0x47DF49780F021AF1ULL, 0x0F402972F9664007ULL, 0x6C49625FA2A2BBC5ULL, 
            0xD3864FABC1260E6FULL, 0xCA09889039AA115BULL, 0x7038F44D73A8316EULL, 0x3A4CECEE0AC7FF9AULL, 
            0x5FE5166CDE045789ULL, 0xE0B84AB1C545F302ULL, 0x89A229DF5BFAC6BCULL, 0x21822D3DC00F6281ULL, 
            0xC1B4FBF65B082138ULL, 0xE700C810289E1594ULL, 0x8C70E6450E235068ULL, 0x29210609CC17A0ABULL, 
            0xE02DE02DD8DC935FULL, 0x3F86AC7D1026F036ULL, 0x230CFF3B45736B0AULL, 0x02848F2610053C29ULL
        },
        {
            0x637FFC04118B0650ULL, 0x21682C540C8D1EF3ULL, 0x34BF2B7CEAFE15E3ULL, 0x32762477FA24675EULL, 
            0x471A84325F63CDBAULL, 0xEC5156967644E056ULL, 0xA0B6C8E6EE847C51ULL, 0xB987DB7D0E958207ULL, 
            0x9A7280E2DD5B6601ULL, 0xAC35E8F7F8B68BF3ULL, 0x2A1E0BA3A37E202FULL, 0x91A5C3AB5ED585E9ULL, 
            0x4F0F29F6661533BFULL, 0x1D5DD74861430344ULL, 0xDE17153202FBBD81ULL, 0x28F140CEDA037EBDULL, 
            0x6C1C5A059F267F7CULL, 0x27012418C264210BULL, 0x57E23EFDE8737DBEULL, 0x4D162ABBEEA92205ULL, 
            0xD3041D5A8B70BFE8ULL, 0x95E15A11E1E2137DULL, 0x928D4FD279E09335ULL, 0x7BA0B930FFDC2D5BULL, 
            0x552C7B696229BB0FULL, 0xBD7803EC9B1ACA7EULL, 0x7635748AA23F7A59ULL, 0xE253B32385A7009DULL, 
            0x988C2CF6047AB4A3ULL, 0x780896E2FB91DF4FULL, 0x3697900BFE51613DULL, 0xC68BF80477B21215ULL
        }
    },
    {
        {
            0x904B537944BDE1A8ULL, 0xE3DD630ECF9EA065ULL, 0x5BF78A90CAC72EEBULL, 0x1CE261BF76A358B7ULL, 
            0x4EAD1ED22DB793E6ULL, 0xBD4F786F708F9146ULL, 0xF002BA8FEC41FDC6ULL, 0x6039E1C3DED92506ULL, 
            0x346DCFD1653E82C8ULL, 0x25EB14BDEAD7BB04ULL, 0x73334CDA10BC0EDFULL, 0x6CE6664513CF2BA4ULL, 
            0xB2B59E6B8A067AE3ULL, 0x2608FF6EADE0AD40ULL, 0x1D37533CCB6A4505ULL, 0x1787F091A135121FULL, 
            0x8F3EA6B6B7251F86ULL, 0x33A7845AC6961C9EULL, 0xE003B391CE288960ULL, 0x00DD5BA6E51B0143ULL, 
            0x3D554C2D728C9748ULL, 0x451FF0F9238FFBECULL, 0x9831727F1D54078BULL, 0x153553A675F37C68ULL, 
            0x3B919777E5237D1CULL, 0xE124305323A12310ULL, 0xCE0E16EB89E79FC3ULL, 0x613D7C5811C1D384ULL, 
            0xA53B89ACFD634488ULL, 0x25CB01D3C6B87CCFULL, 0x88F7085FD8AC5BD8ULL, 0x1D7DDB25294819F4ULL
        },
        {
            0x47AB75CFD4F890ADULL, 0x2DEF5E5579ADDA27ULL, 0x25E1152F1E7E044CULL, 0x6DA4D7BED87C7010ULL, 
            0x16B896A617FD40D4ULL, 0x71CDC75918B06A25ULL, 0x11C6877F0A243F8DULL, 0xFC4DCE69DC7DCBA9ULL, 
            0xB63EA797D1853EA4ULL, 0x485CDEBE1D92CCCBULL, 0x7C7F2AD6AC204BF2ULL, 0xCCCC7D6FF88AAE9DULL, 
            0x45EF50DF289D7F55ULL, 0x1755502D584E145EULL, 0x017EA3898DB1E4C1ULL, 0x9D0B5DDC3B6F7375ULL, 
            0x2CD5221C9B544071ULL, 0x46D2FAB3A9E82116ULL, 0x8D3EB1C6F6737DFDULL, 0x04F5DEEF155E1DACULL, 
            0x2492E29EBA459EE1ULL, 0xC41DABD365C7E134ULL, 0xCF0F2C4E274B1F6CULL, 0x8D16BCF6E32E2AE6ULL, 
            0x25935A408A372970ULL, 0xBF85BBC43851B975ULL, 0x9E262F434C9D9C46ULL, 0xEBD98C1A05A5F556ULL, 
            0x82F4250810B48821ULL, 0x4EABF0B1DC34166BULL, 0x9F62550D791C49FCULL, 0xB0F8D7B25A5C62ACULL
        },
        {
            0x914085E2E2719FDBULL, 0xB389CD2139EE3908ULL, 0xFBB2FD19D40844F0ULL, 0x033369B758F67A97ULL, 
            0x9B8704D78F944253ULL, 0xD8B1BE8DC33FD85FULL, 0x7AC030CF604234C2ULL, 0x424F891CB9B1D8B3ULL, 
            0x0DCF2B3B3076C9EBULL, 0x68D5CB520C1D6215ULL, 0xAFF389EE7216B6BDULL, 0xDD2270DC9D4C0F02ULL, 
            0xBE2D1CCE09F1D37BULL, 0x9E3DBF7865C35B73ULL, 0xC0E40FAFADA44985ULL, 0xFAA1445CE9C2A5D7ULL, 
            0xB6A11EF23E7DA4D6ULL, 0x054F1EF5C3068E94ULL, 0x1C9E1CA24CC99533ULL, 0xC088B528268865ACULL, 
            0x9D239D2DDE2D4A5AULL, 0xCABC5A7CD797FB86ULL, 0x245A3DB3402D07A0ULL, 0x583DB4518121BDDBULL, 
            0x7E13D4A9E5C5DB3EULL, 0x2FE470FFB3857082ULL, 0xC0893DF5C3CDCFD8ULL, 0xD5BFF34AF18D6555ULL, 
            0x9C3206CA6C1A1904ULL, 0x3A3F83CD1AEBAD5EULL, 0x9E8FD30BF9BFA70CULL, 0x7AAE36B085D913D3ULL
        },
        {
            0x0EDED29CE2E4563BULL, 0xF7EBA51CDCA5FF67ULL, 0xACE601AC34C255CAULL, 0x6DC6984F13DC5771ULL, 
            0xE1EE41A19CE2E669ULL, 0xC5D204C923337D44ULL, 0x8F830BE3932025ADULL, 0x9AC5E7D78F601999ULL, 
            0xEF01232A0644E8D6ULL, 0xA5AA07A6F0B780FAULL, 0x8CCF6DE11528C008ULL, 0x9D5D525CCBDF2D21ULL, 
            0x3EEFD67B98D8EA94ULL, 0xEACA4F273DE77674ULL, 0xCD49779AF3D25AFEULL, 0x958D39C156F86FC7ULL, 
            0x1B1F1C82066B9C4FULL, 0xD3F09BDDA8515F32ULL, 0x63918A8313E331D7ULL, 0x26C25081CB1E0CF7ULL, 
            0x1EEF851D052964E5ULL, 0xFA7EF96B579F26E0ULL, 0x58F4117FD0078B17ULL, 0x9271BD33F2511AA8ULL, 
            0xF7891C565363E701ULL, 0x09821476EEB64C3AULL, 0x54343509C8D5AF57ULL, 0xCA86148CCA8C0D66ULL, 
            0x3674241294690200ULL, 0x1280A3328EC2383EULL, 0x668FBD4074468211ULL, 0x1186E72E45DF6E50ULL
        },
        {
            0xA800050685A40E58ULL, 0x19BAA82C7B5D16BBULL, 0xDE7C6750066CE64EULL, 0x5E0133A825E2080DULL, 
            0xE2FFBF6AB029BC68ULL, 0xB8AC458E4346EF26ULL, 0x7692F1F42D86714AULL, 0x8F5A7CB8650AFD7EULL, 
            0x931F75A76A71F6CFULL, 0xC2A56AE218F6F55CULL, 0x3BE36183BED6CCDBULL, 0xFFEB421148A86F5DULL, 
            0x2772A5421A0CE38CULL, 0xD00BF68A59AEAE63ULL, 0xBF302FEA5486525CULL, 0x2EB4C5A68085F8FAULL, 
            0x8A9E89608D3A276AULL, 0x501677DEE9B00D19ULL, 0x961B7A5FED96EBC9ULL, 0x36FC7F3A56A4B0F9ULL, 
            0x8492D499C478D09CULL, 0x286C681AF9A7D34DULL, 0x7E66584F19707058ULL, 0xAE223FD999F71CCEULL, 
            0xBA80B42DD824A7DDULL, 0x0A8C363948AA34CDULL, 0x43452EC1B56CA9E0ULL, 0x2D72BB6567037CD6ULL, 
            0x24731BD6D6D89369ULL, 0x1E8E3C0DBAED1872ULL, 0x7244B686B009D595ULL, 0x08BF12515FCFD7F8ULL
        },
        {
            0x05AF008C80FA1EC0ULL, 0x61324657C5C77489ULL, 0xC406604453F52C71ULL, 0xA3F327C0D88BBEEBULL, 
            0x19F333785D70665EULL, 0xCCCC3F1C223040B0ULL, 0xC98A90F5A30A4FA4ULL, 0x48585E72C17DFD90ULL, 
            0xEBB6215F737C5B1BULL, 0x88BB9B952CEBC496ULL, 0x466EE506D9F07EDCULL, 0x54E9E1154F277A7DULL, 
            0x5268D4CF15A69841ULL, 0x4B9C0B5B1C39FEADULL, 0x3B40259998954FAAULL, 0x275AC09BCB42B307ULL, 
            0x9F6346DC76FEDC15ULL, 0xCBF59FA62965D337ULL, 0xF27AFF382C89DEFEULL, 0x678546729DD5900CULL, 
            0xA35301009B01872EULL, 0x433D8C02F892E20DULL, 0x283DC229B77B2422ULL, 0xF0D8D246781D5CF3ULL, 
            0x5814D49617373D66ULL, 0x9B199F1571BE6BC9ULL, 0x462943E1B7E130E9ULL, 0xBC5D676FEBF47F4BULL, 
            0x9121A615E9DB19A1ULL, 0x544A31ADBAD0456BULL, 0xC5ABC4D98FE0AF38ULL, 0xEA1DB9EA6FD35DFFULL
        }
    },
    {
        {
            0x6969CD506B21EF5EULL, 0x9B2F5391FE28D572ULL, 0xBB8B59EDEDDA193FULL, 0xEF8E1A91EF035F3FULL, 
            0x4C635A34875A493EULL, 0xFC6AF87665FE3E1BULL, 0x1B96E3E5DE5EC73EULL, 0xC286DC8BBCB78FCCULL, 
            0xC0BC0D1DD81BB11BULL, 0x8CC50F74BA502BA5ULL, 0x69D3E9FA22C6599CULL, 0x4D9A2C75A1888AB0ULL, 
            0x9BFF1F126024AE8EULL, 0x82787E13D0DF7C56ULL, 0xF27977C85B36A71DULL, 0xA9AD8293EE67437AULL, 
            0xD6AF7DC5044BA245ULL, 0xE41A2CC386C7AF11ULL, 0x050ED03081845CBCULL, 0x5EB9BD7626EB091DULL, 
            0x130EA55730C07EBDULL, 0xB91914E859ABA347ULL, 0x134FEB0E601DA649ULL, 0x7C212A49BDDC0FA5ULL, 
            0xB367B2FDC4FFB622ULL, 0x538C8061DC8B5FF1ULL, 0xD394FE494C707E19ULL, 0xF7CF2B529797B5EFULL, 
            0x9FF214AF7432A585ULL, 0xE52164D51CF7D4A2ULL, 0x65B3459E925957A4ULL, 0xD9712338FFB676EBULL
        },
        {
            0xEE3B368ADCAF53C1ULL, 0xFC7744F837095D04ULL, 0xE29AB235E2AD1F4AULL, 0x1DF09D1F9C9001A9ULL, 
            0x319F00D39D9267E7ULL, 0xA8678A85886CF83EULL, 0x13AA737C8FFC22E1ULL, 0xBE8C2CE0BCA54FA8ULL, 
            0xFD0EA0C05AACE48EULL, 0xC42261D0C57DD268ULL, 0xFC8876335BA33D49ULL, 0x697F051CB8BA460AULL, 
            0x587E5D3D3B40DFA0ULL, 0x870AEC4850980C46ULL, 0xB2F18927236A0D37ULL, 0xC317A45193DA8D66ULL, 
            0xFFC18C3BBD6581DBULL, 0x47B5AD9D0E4D4517ULL, 0x10006257A4782EBDULL, 0xE81C3B43F4BCE232ULL, 
            0x701A203A220B75C6ULL, 0x00A696A0C8FEA055ULL, 0x6235D8690D3ABCB4ULL, 0x88A2D3209209E182ULL, 
            0x63B31704BCB73A36ULL, 0x8DFA64BC966CC1FCULL, 0x8805FC06E9FD2D40ULL, 0x84D13C6A278A36AEULL, 
            0xEF4F23E4C7FCA210ULL, 0x3B8D2EC9CB7ABF57ULL, 0x1DF817AE4B63301AULL, 0x63106199EDFF6954ULL
        },
        {
            0xC055F126345510E1ULL, 0xB2522FFE402FD292ULL, 0x54FDEA4F54CE0E2EULL, 0x766A24C5B6FCF797ULL, 
            0xF698E32070C3B925ULL, 0x1BB9F44A79FACC95ULL, 0x6238A8C6F3F47CF5ULL, 0xC8D009E93E26155EULL, 
            0xAF856ACBEEFEC787ULL, 0xAD95768C9B685A2AULL, 0xCD275214AD4BCF14ULL, 0xD4ECFF92A9F7124FULL, 
            0x0E087E3A3BC0D584ULL, 0x335CCFECCE9281E7ULL, 0x30561290EC4FEF55ULL, 0x2D6EA30F61A8AEC9ULL, 
            0x781C6F225CEAF7FEULL, 0xEEA652D4429A1DD3ULL, 0xE04DB14CA2CA1412ULL, 0x46E0D36B3529D0F4ULL, 
            0xC383000438555C0EULL, 0x82BC0D609D5BD61EULL, 0xE27341DF1EA32EB2ULL, 0x3777FC865A59CCF3ULL, 
            0x825F8380D558FA8AULL, 0xFE26A304267A5DB7ULL, 0xFC4F5B57F8F43BB9ULL, 0x9A0DD5C9252F9AA8ULL, 
            0x9F75916BB0D17912ULL, 0x41D176F0182FC503ULL, 0xA996A4D0EF29DF47ULL, 0x261A6F36FB362D22ULL
        },
        {
            0xAE544DB9ACE4EDE3ULL, 0xCDAF9ED8B7AFB41CULL, 0x094CFC503C843DD1ULL, 0x96BDC5A10BA9B923ULL, 
            0xD3EAF3D2A2A858A5ULL, 0xB558C592FCEAD85FULL, 0x519BEC1F91D9A3EAULL, 0x0BCF770059D3B6B5ULL, 
            0xFC89AE620025711BULL, 0x87884DE5FE1DE749ULL, 0x5DE2A642F5B78D71ULL, 0x956AA789A76467D1ULL, 
            0x9E80D829DDE9435BULL, 0x8BABD00B8584CCDCULL, 0xD7CBB25FB47452E6ULL, 0xC5BA5E87E6681D6CULL, 
            0x5BF55AFCC2AF6095ULL, 0xA90A08A2FD00684DULL, 0x775F08A77E2E326BULL, 0x66AD95DA34FAFBC9ULL, 
            0x9412B5F9BD1A0C89ULL, 0x07597A09E5FAD78CULL, 0x682EE413641B7294ULL, 0x532050084C7614F8ULL, 
            0x4722278C516759B6ULL, 0x99E2641C070BC25DULL, 0x85AA7291041F4596ULL, 0xA6DB8AC852440800ULL, 
            0x448357168573A5ADULL, 0x54396A8E727C8453ULL, 0xA71FB85054605C30ULL, 0x409B7CB8247BBF60ULL
        },
        {
            0xAD76E8DACBF995E6ULL, 0x1BDC185CD1957C48ULL, 0x48225E24C47FC7C4ULL, 0x250785A265C48095ULL, 
            0x68A7E61A1915724CULL, 0xDF823A95956518B9ULL, 0xCF944622C0A15F36ULL, 0xB0B38CAD08831426ULL, 
            0x8D4052B842A93425ULL, 0xEA58772686B71EEAULL, 0x2DF43D413D35AE41ULL, 0x3B104A3E580EC324ULL, 
            0xFBC04393692B7669ULL, 0xACE22A7F8D628FCEULL, 0x2DBF7A639CB7F3F4ULL, 0xB0B9140F5485EB7DULL, 
            0xCC700DE2D33538BAULL, 0x25E5D0D3E71B02EBULL, 0x7FA3F44D6A5A4F4FULL, 0xF8F48268AE8C9503ULL, 
            0x192AE38853883C56ULL, 0x09C63DA90946AC85ULL, 0x971E103B63158439ULL, 0xCA7F77F40313351AULL, 
            0x63968B0A08276D6DULL, 0xE85A6AF87CBC3ECFULL, 0x709BE669A5CC15A9ULL, 0xC07165114519E93EULL, 
            0xCA578B2EC09FEC21ULL, 0x6EFE106BDBA50D8EULL, 0x42BC2348AB34FC4CULL, 0x58C905655417BC1EULL
        },
        {
            0x9AE69BC4BF1AD890ULL, 0x4A84766EAED878BBULL, 0xC7B0D89E7D049C39ULL, 0xEF50E6F13E5363E1ULL, 
            0xD6874BDF8785A6C0ULL, 0xA2BAA1EDF76BD419ULL, 0xFD19316055688DCAULL, 0xAEED18AD7AB40837ULL, 
            0x8D59EE315888A353ULL, 0x17BEC7E51C33DA60ULL, 0x9DDE258DAF80F269ULL, 0x42EF73F5FDE8F74EULL, 
            0xBECE62C5ACF4284EULL, 0x8C6F94BACC33FBBDULL, 0x6F8CC227F02836EFULL, 0x8352C1896EBCEFFFULL, 
            0xD3FF636BD6D02C5DULL, 0xDE761B4340C32B45ULL, 0x81F9064424F837CEULL, 0xDDF1438497DE3FA9ULL, 
            0xB7E2479D6FEE76A2ULL, 0x14E793E02657ADAAULL, 0x9DA63F26EED1899BULL, 0xF09346C9BD0D47F5ULL, 
            0x87AC6C2F4BED9A41ULL, 0x95FE9FEECC1D353AULL, 0xDBD1F57792B6D8ADULL, 0x404E26BE44292549ULL, 
            0xEB86D6FBF3CCB6C7ULL, 0x77D480023A9242E2ULL, 0xC3987DCB7626340CULL, 0xF40488709CBD6436ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rigel::kKeyRotateBConstants = {
    0x6C9DEE40520D1C29ULL,
    0xD6018F4508C4C008ULL,
    0x489E6FDE060E4D98ULL,
    0x6C9DEE40520D1C29ULL,
    0xD6018F4508C4C008ULL,
    0x489E6FDE060E4D98ULL,
    0x7B20FEFCF1FCFE84ULL,
    0x30C0509689EB69D0ULL,
    0x2A,
    0x40,
    0x25,
    0xE3,
    0xFE,
    0x8C,
    0x04,
    0xCF
};

const TwistDomainSaltSet TwistExpander_Rigel::kKeySpawnASalts = {
    {
        {
            0x56396E4E635F680AULL, 0xA87FDCCF2CE42640ULL, 0xADEA31F18BAE7D2EULL, 0x89D5861D72B9E9F1ULL, 
            0x22AFD80DF4243D15ULL, 0x8CB4545FBF100AFBULL, 0x715E0662C9E8C227ULL, 0x69FF46498AC1AE7AULL, 
            0xC189727F0B47A4F3ULL, 0xE5A3D32E7BBEA57FULL, 0x382666BC8D343175ULL, 0xF678611F9463AEFCULL, 
            0x771C0434D709751BULL, 0x2F754749C9E53237ULL, 0x8EA62B1FCCE9DBB7ULL, 0x1E14C54ADFB3A948ULL, 
            0x19AA4708C26D6CF2ULL, 0x5DDF4958CE8DE095ULL, 0xAD711293650034A4ULL, 0xADCBBF795172043AULL, 
            0xAA199129840A35EAULL, 0x60B953F684A66A44ULL, 0xE141FF1E324236D0ULL, 0xAA661047CD9D992FULL, 
            0xA37F052BBA36C5E7ULL, 0xB32EE3E0D79876E4ULL, 0xAC054C6D66358B22ULL, 0x5A5288880056D5FAULL, 
            0x8275C0B1A48BC056ULL, 0x1CAD9B4BBF39F390ULL, 0xABC5FE748AAA0238ULL, 0x2F578C5B6CF23707ULL
        },
        {
            0x9C40EC53C9A93235ULL, 0xED0D0C17A6553F98ULL, 0x35C84EFAA6F44F37ULL, 0xD6AEA8396DE67738ULL, 
            0x1B8A697E227C207BULL, 0x4CFE3DBA8A0812FAULL, 0xE212C2B944807933ULL, 0x9E2DA0A0AC2AA8F0ULL, 
            0x987A12054A042833ULL, 0x7AF873234D89714AULL, 0x195B47D3BDF39B4DULL, 0xF3CC0D7F1AAD81EAULL, 
            0x0517C03CBA9737CFULL, 0xCCFE908DABE28359ULL, 0x99350A6E6B91D151ULL, 0x28D052FDE805132AULL, 
            0x0409D9368842E0D8ULL, 0x3C615581E210F408ULL, 0xAC9A9F5A3520B066ULL, 0xB7C9D0B2A742DCDCULL, 
            0xAB4A3C3F3AD08417ULL, 0xF09DF2AE1477B417ULL, 0xBFE6309B74CC6CDCULL, 0xF6D15E6E2FDC5CE4ULL, 
            0x55FD6AA67BCEDD14ULL, 0xF9FB9A7E4D2078E5ULL, 0xE5C3A6C7437C0F29ULL, 0x875D816340B3C510ULL, 
            0x185527D306C7079DULL, 0x7D4812ABACEDB60CULL, 0xA41B9F45F0FF6F2BULL, 0x1E769150E0C086F4ULL
        },
        {
            0xF06B3E224FF3D578ULL, 0x1F1AED39EFAF2813ULL, 0x9E15F55C146C0077ULL, 0xA56500A302FEA87BULL, 
            0x778A6CEDE018C4E4ULL, 0x5E09D74CC6D26272ULL, 0xB9201EAD274D5D29ULL, 0x2485FB4200CFE3D6ULL, 
            0xC0FBCE1CB0BD76ABULL, 0xAC37B3A601499E78ULL, 0xD05A8E44E13D2D9FULL, 0x764CD46EC935C7EEULL, 
            0xFE8CCB7FF0F9E30FULL, 0x766247A7DC32BF27ULL, 0x8D0C6F2B0A58B85FULL, 0x54210E7F16ADABD1ULL, 
            0xB957FADAB81BB51EULL, 0xC7DE6ADEA79741F2ULL, 0x5F80E465A54A6919ULL, 0x3B8332F7B412BE1EULL, 
            0x8C343A055C55E404ULL, 0x1271175DA7BF5596ULL, 0x87677531A2701B04ULL, 0x2A7122F27A95D187ULL, 
            0xB7069C41FAC9A985ULL, 0x0BFDB05FF1CC9B1DULL, 0xA5D28D67C47025A3ULL, 0x8E1E9A5DA248DFD8ULL, 
            0x10F5815AC2032FEFULL, 0x511F6638C0E7A02CULL, 0x40FD38D0D7726646ULL, 0xF70CD5B819F19E01ULL
        },
        {
            0xA889682FFCE1C976ULL, 0x7E0485229AE2302AULL, 0xE16A8C8527E76BAFULL, 0x8B7FAE50905192D8ULL, 
            0xE713DEB64ED3D43DULL, 0xE4D89F51158D52C9ULL, 0x40ACC8F06EAD1FB4ULL, 0x0BAF3437A28DEFD3ULL, 
            0x06FAB91F6BCAFA83ULL, 0x306C1CB6011583B9ULL, 0xC632B072DB1A3EEBULL, 0x1880408E16B04BD3ULL, 
            0x66FF5ED3B3A29C56ULL, 0x8704B0EB243DB49FULL, 0xFE42050FC89C8315ULL, 0xC436BE648A7226A4ULL, 
            0x1F8200ED37DF70F7ULL, 0xB945D25C5FDB90E7ULL, 0xD07395ABA3902759ULL, 0xBFD1FAE23E772183ULL, 
            0xA0638304D3FE4546ULL, 0x31FBE0AF953E90B5ULL, 0xEBF44AC99AB7D8F3ULL, 0x414A280BD1352398ULL, 
            0x8F94F9415368281FULL, 0xFFA9937DE58D1870ULL, 0x8CE2F9DF9C97E1B0ULL, 0xAC8AFF53404D5F81ULL, 
            0x81ED4EEBF4EA71A9ULL, 0x4AACBA029C8DFC7DULL, 0xA08E0E4925FD99EBULL, 0xFFA4F7BEB1C65A87ULL
        },
        {
            0x21799AFF0D5BFAC1ULL, 0xC883DC0ADB2C3365ULL, 0x3BA0FDD317873957ULL, 0xE9861883FF252C7EULL, 
            0x8BFC0DA184C681FEULL, 0x4C6367F73D9DE73FULL, 0x1CF105C9977E4329ULL, 0xB7B257641379853AULL, 
            0x6D907F20DACC67CFULL, 0x839277FA0A009FABULL, 0x15FD0EB9DFBBD456ULL, 0x93A78F49ACDB553DULL, 
            0x49574C44C5913897ULL, 0xC6F5F3A82D28E0ADULL, 0xF8F82590A91A673DULL, 0x08F338343BBCE730ULL, 
            0x6C84CE171548FF7FULL, 0xB3557447AABCE26AULL, 0x6821B3209C266B5CULL, 0xF69D907DFB36DFB3ULL, 
            0x283961583966F1E8ULL, 0xB9A8D4AEA473BC53ULL, 0x8CB0D0A882F341ECULL, 0x43FACAFD5A3D727DULL, 
            0x4460612BBC607A5CULL, 0x303B3400571B12EBULL, 0x65811C1D8453BD64ULL, 0x57B6E4BEBAD4953BULL, 
            0x3B10CAA63A54D70DULL, 0x178D84959366C637ULL, 0x8B34DC738A2966B3ULL, 0x69C511E9969B3C8CULL
        },
        {
            0x6628B87C0ABB7583ULL, 0x1F0090805703828CULL, 0xE43B1B5A11872928ULL, 0xC55BE481A727AE34ULL, 
            0x77B583C0DC996509ULL, 0x4861A9185FC1043AULL, 0x1B7E4F5B828DC17DULL, 0x979BF594B3859EF5ULL, 
            0x1B715C41DBDA0B4DULL, 0xF5433BFEFB76711CULL, 0xFAB7C441E77DD25AULL, 0x6EE00A5C6E851267ULL, 
            0xF59F974A07678F71ULL, 0x87C8B4C14E0D2E59ULL, 0x1B7C47CDD2B497F8ULL, 0xE1ECFF136958F7B8ULL, 
            0xB3F5E67D60A8847FULL, 0x1B22A17491C125A3ULL, 0xB4E5500B5977A5E6ULL, 0x72B617A6B5C524FDULL, 
            0xFD424995C43A0514ULL, 0x2A715E6F6E176B70ULL, 0xF165AD935C8309BDULL, 0x0CADEBFA99E28AA9ULL, 
            0x947A283B71246F7CULL, 0x2ED10B3D74621726ULL, 0x9881D0A908667594ULL, 0x1F2E031C43C241E9ULL, 
            0xAF22276E71E3541FULL, 0x1363D1A6DF178414ULL, 0xB4E5411863D87375ULL, 0xDCA00009C86E2230ULL
        }
    },
    {
        {
            0x56ECA944DA796D42ULL, 0xFE558864E1AD60B5ULL, 0x37DB8E918666F4BCULL, 0x62EDECA847D76453ULL, 
            0x608E2ED8E615BF3FULL, 0x64D0F5286EE228EEULL, 0xAE104BEB347B5AE3ULL, 0x3813E4283565C597ULL, 
            0x5EC4CA08509D406EULL, 0xFE753E440B2C1BE3ULL, 0x5F591BF0CB5943D4ULL, 0x3584E7A49F6B7BCCULL, 
            0xD58B63DF5477DB06ULL, 0xB0FF62D957A3D3D6ULL, 0xAB285E0267A75A65ULL, 0x45F4252945C3E755ULL, 
            0xD81DC75F9A29588FULL, 0xD5D535E70E0441BFULL, 0xF77922D38027F706ULL, 0x21DC0B094388FD08ULL, 
            0x25B12BFE82C9E007ULL, 0x6FFEBE30282279CEULL, 0x943B8992BCD40F38ULL, 0x919AB39EC3201157ULL, 
            0xD731619728DDDE79ULL, 0xC0397BAB8B22F15CULL, 0xEEA219CA4F35AC0EULL, 0xF9018111E9C377CAULL, 
            0x282D4737D232A9ECULL, 0x38C9A0E641F8C8AEULL, 0x4A1ACB5D6502FC35ULL, 0x3D66CB7E2D6A1583ULL
        },
        {
            0xE2237A14545AF266ULL, 0xECB1AE938874023FULL, 0x2DFEB89BE6A3B039ULL, 0xC894F90BD22903AEULL, 
            0x432CB855F61E9107ULL, 0xC7535E9AA9ACAD07ULL, 0x5B57023E863DBE2AULL, 0xE50218470EA26C8AULL, 
            0x941B8F3127417167ULL, 0x237405BFFB4889BAULL, 0x4CF459CA403CE225ULL, 0x7E5BC84DB3B64822ULL, 
            0x84F6F69F73899DC0ULL, 0x8F2AF3766F28578DULL, 0x87E01A9972A82157ULL, 0x212A7018A0E14F95ULL, 
            0xA50EE00D194F3DF8ULL, 0x2E4020628C192062ULL, 0x7C25ACBDE120C0C7ULL, 0x1C2CE317F835CC7FULL, 
            0x3534A294D780A609ULL, 0x10B0B5ADEA3B5CB9ULL, 0xDD3B789B80FB5EAAULL, 0xD30A512180ED5735ULL, 
            0x2D369315C73FFE14ULL, 0xF747FA56504E17BFULL, 0x8AC0D529C24FB9E6ULL, 0x759E0BF154F35960ULL, 
            0x15D0BCD7467CCA8EULL, 0xC642F964FE2998BCULL, 0x5731CC8D4DA98292ULL, 0x0841579C12B92837ULL
        },
        {
            0x06DF27D08981AC50ULL, 0x04BA5A53B4F7F158ULL, 0x7D15559643AB9A2FULL, 0xFAF9BA4E7512AF19ULL, 
            0x66341F931086C29CULL, 0x0FF11C37D95003A0ULL, 0x72F46D3EE7288613ULL, 0x306ACA56CD59810AULL, 
            0x23679F1D5C3B18EAULL, 0x94C6F642883D69C3ULL, 0x781943D11AA25F65ULL, 0x8F19D1B23105519FULL, 
            0x35BC7CE4F4C8EB4EULL, 0xEBDC8CA0AD3CA5E6ULL, 0x91E7461B6FCC60A2ULL, 0x0087BC9F070FC010ULL, 
            0xB802DBCD62525328ULL, 0xC582D1E9C3D0972DULL, 0x4968B63DED20C571ULL, 0x8C599BFA0E5D4C33ULL, 
            0x6019C5C72F908E89ULL, 0x7BB5F16BE896B8D1ULL, 0x4179ADCB2EB551C0ULL, 0x979EC1567FA5CD36ULL, 
            0x33569119C206A48CULL, 0x9323CD9D6D63AA0AULL, 0x30A90DF677A3A477ULL, 0xEF08D6D3F8FBF0CBULL, 
            0xFF8C4131811469D6ULL, 0x7B9E5E11663960A5ULL, 0x686A51DBD3D4937CULL, 0x2A8F5B4FC8A9595FULL
        },
        {
            0x1DA0AA705FF69B70ULL, 0x9E7FBE0B00FC477DULL, 0x968189F0694C8790ULL, 0x556D92DD3B6DC2ECULL, 
            0x8E4F6EDF5EDF8D7EULL, 0xBCC8C05DF65BAD1EULL, 0x5523AB6D682379C4ULL, 0x4D5BDD53F8C7F6F4ULL, 
            0xEC6D7688F6060EA8ULL, 0xEFA868AE12D562BEULL, 0x87FBEC7C6C2D9824ULL, 0x77C3E08CF82A7E87ULL, 
            0x085929DBEC4595FDULL, 0x4E54B59FC92E75CFULL, 0x7197D7E49FAE3243ULL, 0x1DC5D50F7ADBD57AULL, 
            0x28195010DFB8D3FDULL, 0x9757999466597507ULL, 0x95AC9901B58D3C15ULL, 0xE678E6FB903355FEULL, 
            0xD65BA62F6324F60BULL, 0x3CC308B76E8DF1E5ULL, 0xEF9CEB81CA1E8CBBULL, 0xBE1102963C129143ULL, 
            0x40B7E9F7D049F7BCULL, 0x15CA60F821859C63ULL, 0x305A0F2602FFF090ULL, 0x36F8CF385C9AD615ULL, 
            0x536B2D4F8409DAB3ULL, 0x67BA4E202AE9EA35ULL, 0xBD85A5C3751E697FULL, 0x811C6D43F01A12B1ULL
        },
        {
            0x6268F45E3A706067ULL, 0x40FA8428B037AE13ULL, 0x6679DC72BFFA64BAULL, 0xAB8A4D4FEB6B88FEULL, 
            0x5EC7B931D7BABDDAULL, 0x92FDDD1338EDB79DULL, 0x86B38DCF9297B273ULL, 0x6CED065C8AD286AAULL, 
            0xEE39D4F300A9C595ULL, 0xE19AB2E7B4F2A044ULL, 0x23C37F5D4BCFAE99ULL, 0x8E45AF0C711987CBULL, 
            0xAAEC9112D355FF65ULL, 0xEA3FA3B473E4578FULL, 0x3CD6EA2BA1303E63ULL, 0x3A392BEC49F06F21ULL, 
            0xFEC4CC146C197220ULL, 0xBA22E96930F96D3AULL, 0xA93A453D6FF26873ULL, 0x175875381F1DEBA5ULL, 
            0x18D92F5A6DCEDD88ULL, 0xF82C2CCCB99AF898ULL, 0x5C981714D5AB8B2AULL, 0x6D88A05868F43F24ULL, 
            0x14480022A97876BDULL, 0x055ED4CC36B298D3ULL, 0xC1B829BC46048208ULL, 0x9FD52458C686F411ULL, 
            0xCB6EF7BC2359AF7DULL, 0xDF40680DE5403762ULL, 0xEF7A7781F4A71515ULL, 0x6888423439E61BB4ULL
        },
        {
            0xA3B36402D60ECAC9ULL, 0x59612B74E4E4BD3BULL, 0xB9349937848C2609ULL, 0x4FC62E6D878B2B44ULL, 
            0xCB214FE79B0A3A29ULL, 0x101D68A2A26A9E0BULL, 0x0C7105F4CD00F958ULL, 0x947BE82F2A7367A3ULL, 
            0x9CF0AB4A9F1661CFULL, 0x38F4D926701E0BC0ULL, 0x533D6F3147B2ABD8ULL, 0x2BB9FFB1F3FED638ULL, 
            0xA2ABB775FB94B678ULL, 0x6BB8146FFCB07831ULL, 0x78BEA24391638A95ULL, 0x39B61C4F17C8DACCULL, 
            0xCA73F5DF7B1CD164ULL, 0x29B725DD9FA9C112ULL, 0x8C4F64E241668E26ULL, 0xD352C4B47CF07BB5ULL, 
            0x43871EAE98A32CE3ULL, 0x380DF87FFA8C11F8ULL, 0x319F5A40E157AEB1ULL, 0x615632264ABC34F6ULL, 
            0x07D5371DE2052BFBULL, 0x5EB1FA8D8562564AULL, 0x82288AF10ACB56FFULL, 0x273B4B53563D38BBULL, 
            0x67C838C7CE3F3B3DULL, 0xCD03FE5FD431F0B3ULL, 0x13177FF07FC79481ULL, 0x4F4B851D51F3B63BULL
        }
    },
    {
        {
            0x8B1B4E7FCE028A57ULL, 0x217755B796CE97CBULL, 0x29973061E0C2A415ULL, 0xFA00E960785C1DB4ULL, 
            0x8FE4D7DB6E4195FAULL, 0x787A13DFC49C51FFULL, 0x097E6C52B0EB8898ULL, 0xF7C3418F1B9D5252ULL, 
            0x2374C7FA773C1FEEULL, 0xA9F74F116FB09A1AULL, 0x7190CF256CA166C5ULL, 0x2903FE63E0B54CE2ULL, 
            0x1415CB81A9D2199BULL, 0x9840556B7451C647ULL, 0x0B0A2F7E04E37877ULL, 0xEDC69F2121EC48A6ULL, 
            0x4266F82D750B0146ULL, 0x133862211150CD9CULL, 0x8BC50DD7F2054DD4ULL, 0x911F0E26CD9B3CA4ULL, 
            0xA71B933F2C191AA2ULL, 0xA75094725F7E3462ULL, 0xCD56F3DCCBEAB535ULL, 0x73EF9FC3B9F37F8BULL, 
            0x7CE1CE56356EBBF7ULL, 0xF28AD83113B3FA50ULL, 0x5706C3A442A04554ULL, 0xADD6D4A44D536496ULL, 
            0x2DA26D14E41E173EULL, 0xE90C168AF66131F7ULL, 0x83601AF4FCBF4041ULL, 0xC4C299009317D473ULL
        },
        {
            0xDFC0C4F744FA6A24ULL, 0xF486F75363733901ULL, 0xB4F07112D9CC42DBULL, 0x8DAD948AD7DF0B9CULL, 
            0xF4C56558BEA7AAF3ULL, 0x9EBFDFC6EEE0CA9AULL, 0xD46B06B5E9F2CE49ULL, 0x2D6B2B732F797398ULL, 
            0xC65F448150C22D7BULL, 0xD9B8ADEFA8AD311DULL, 0x91AE239F2800CB94ULL, 0x35CFCD80111AF6D4ULL, 
            0x7CAB9468D1553A63ULL, 0xE5DEDD57C67BCAA0ULL, 0x2D076B5A88855A02ULL, 0x7E4C561B189D3BB5ULL, 
            0xE867CCBA8EA18397ULL, 0x46C0513791BF40DFULL, 0xBB7AA050A1232568ULL, 0x07FED14573A0FF43ULL, 
            0x58812F9136C0E227ULL, 0x862A09AA35FD9731ULL, 0x7A291DBF4629283BULL, 0x66E898A3EABC8A17ULL, 
            0xF806049A50C9819DULL, 0xF38DAC02AE71A190ULL, 0x9FA5F50290786D26ULL, 0xD3111A482DFA0C87ULL, 
            0xDD2F7672F48B8E40ULL, 0x78643741B2201FE0ULL, 0x5238C29A1B54E26AULL, 0x089B54B9B70BF4B6ULL
        },
        {
            0x8AC1B0D6ABC0AEEBULL, 0x28C0E6F9AF46C67BULL, 0xE7A10C762D8515FEULL, 0x5BF564F4614F6AF8ULL, 
            0x7E190C77E51E9043ULL, 0x3F18B1B2F1E1A9E0ULL, 0x4F422422BB102012ULL, 0x7B5793EF2F137D0AULL, 
            0x6DB860C9D8C387A9ULL, 0x0E3F5546B122C101ULL, 0x15B01FA270A20D6BULL, 0xDB51B76FC701550EULL, 
            0xD7AF9646E8E33EF5ULL, 0x1D1D7BCE559D39CFULL, 0xE900D71221DF48E4ULL, 0xBAE7AE7A5ACB12B3ULL, 
            0xDC5028213A9E0257ULL, 0x400B1F17031226D6ULL, 0xAE0E015484F79C18ULL, 0xFCCBA14A3AFAC596ULL, 
            0x9E55F1282C0F960CULL, 0xEA1D032269368359ULL, 0x831FBD700A9A4AF6ULL, 0x23999DC2BDEDC9ACULL, 
            0xCE71D6EEA0717EFCULL, 0xB4F3287623E83A6EULL, 0x10EBDB8A40C07220ULL, 0xA572F29317EAF048ULL, 
            0x38E817A8C844A31BULL, 0xC885288937E87558ULL, 0x6892CC442A859048ULL, 0x3C7E99B8B7ED03A9ULL
        },
        {
            0x3B42635027E08298ULL, 0xBE30C036693557C3ULL, 0x678818C98A5ED5FAULL, 0xD1E729F42467077EULL, 
            0x0BB0D67FC9C8F5D6ULL, 0xDE784BC4A1BA409FULL, 0x56B59ACD11B67F1BULL, 0x54831B542B54F9D2ULL, 
            0xD221A1D742D7A465ULL, 0x2E526FA52AF5172DULL, 0xD952BB585460A55EULL, 0xFAD3CF88ED08C154ULL, 
            0xF9FA952A00A1D313ULL, 0x27FE0BAFAC180883ULL, 0x65EA7A2685EC0E0DULL, 0xA271B4AE15285C2CULL, 
            0x69B6E5B595B432C9ULL, 0x5131B13CB9D2AD8DULL, 0xC08FF41F1B8524FAULL, 0x37758E4E4A9D9D9EULL, 
            0xE43DDCD37C41BA1EULL, 0x36E445393BDDF0CCULL, 0x972CAD7C8236A9D7ULL, 0xEDDE29B12939CD65ULL, 
            0xB2418263A4914D17ULL, 0xDF5D345CA78C9890ULL, 0xC4D8227DCC5F6517ULL, 0xF86DBCA0832EE3A8ULL, 
            0x3EB210A8B2C21096ULL, 0xFA4C945C753E5427ULL, 0x4F91182887D5270AULL, 0x2583198DA5680CD8ULL
        },
        {
            0xDADBEF54AE33794EULL, 0xB5EFA0E0F4FDA3A4ULL, 0xF4730F7669D53858ULL, 0x157BEDBF59638CDDULL, 
            0x959FE2552FEB806CULL, 0xCD8846620577B6D0ULL, 0x0C9BEF9FE481AEF9ULL, 0x2C1CC643AEF0FE3AULL, 
            0x3B780A11B1E2444CULL, 0x48496E433640901DULL, 0x053BBD7E43335925ULL, 0x9D37C8F7CDFCD2D4ULL, 
            0xCC76DBF723F21D4EULL, 0x405C3AFB5C170C20ULL, 0x51958E7DA0E38A3CULL, 0xAED1DD1BFEFE576AULL, 
            0xB262F1981B256978ULL, 0xD6F292BF2B9C9DCBULL, 0xA3A8C537443DD372ULL, 0x8B05B2227905B5E6ULL, 
            0x37B009C3C4C54404ULL, 0x6FD12CB6B3577B7DULL, 0x297705873B6F490DULL, 0xA93FC32D7A90C68AULL, 
            0x8381908C9E1A639FULL, 0x3599C406F189B041ULL, 0xD25F3F4218F1FF6DULL, 0x504B0082F2BCE75CULL, 
            0xFB9D6AB08C53EEF1ULL, 0x27A0C6EC2097C875ULL, 0xF91AD7BA903724D6ULL, 0x170A0EE4FBFD6922ULL
        },
        {
            0x4E8AFC53B4080602ULL, 0xDE56ABC8DE8E68D8ULL, 0x0FF6D994DB9765B0ULL, 0xD3851BF2BE4E5A78ULL, 
            0xA28D8E0CB05B5A82ULL, 0xAC0315D4039E50A6ULL, 0x0222302FDAE96D22ULL, 0xCD33CE5B06B96CCEULL, 
            0x36D58ABD2550D07CULL, 0x701FF7037BC7BE90ULL, 0x75E61A0E19D3B5C7ULL, 0xCAED38E455AF828AULL, 
            0xBDE75DC7EEBEC0C7ULL, 0xC22456F4E004DF49ULL, 0xD98C586635109973ULL, 0x38319E3BD763AEBCULL, 
            0xD82D992E6FC17088ULL, 0x68A947BF7A1AD1F0ULL, 0x56312AD9F8658C91ULL, 0x2AE88028CCE859C8ULL, 
            0xB3435747DB9053ADULL, 0x8700076160B53D0FULL, 0x0061DC7C4F22594AULL, 0x50F94B2598DCFA9DULL, 
            0xC4854AC02AD8B3F2ULL, 0xBE4F77106B6FDB9FULL, 0x5D44851A4DB38D7FULL, 0x0C8757A6F87958C7ULL, 
            0x295C91E2CE846757ULL, 0xDBA949FC1404C762ULL, 0x78727E00ECE9EEDAULL, 0xF2936AD47880D2C6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rigel::kKeySpawnAConstants = {
    0x896BD21B81BA4E3DULL,
    0x8368CF12E7938E87ULL,
    0x183F44737A77CB21ULL,
    0x896BD21B81BA4E3DULL,
    0x8368CF12E7938E87ULL,
    0x183F44737A77CB21ULL,
    0x08AC7C1B5C833B73ULL,
    0x433727B77DAE938EULL,
    0x4F,
    0xE3,
    0x06,
    0x0B,
    0xB7,
    0xAC,
    0x39,
    0xAD
};

const TwistDomainSaltSet TwistExpander_Rigel::kKeySpawnBSalts = {
    {
        {
            0x712B8D5A56665FA9ULL, 0xEA7D0CB6D082F329ULL, 0x0509E1C92192DE0AULL, 0x41BC684A6E3454D1ULL, 
            0x585FC088BDAEDBBBULL, 0xE6B5E9BAD894F9EDULL, 0xB9FDDB96EEF40C53ULL, 0x7D276651EB3E3AB5ULL, 
            0x18D8FFF70312CEE7ULL, 0x85F08B40FD293C59ULL, 0xA062F360433D6573ULL, 0x76F4CD8E33649CF7ULL, 
            0x7C92D21FA7A04638ULL, 0x4032F40F4FAED99BULL, 0xE87DF5E8A126B01FULL, 0xA415EAE2F9E43DC7ULL, 
            0xF00888D9DB1C94ECULL, 0xA60FD0C5E6956F2DULL, 0xB627D47D63B52A41ULL, 0x2AE2F52F9DD24C26ULL, 
            0x3E131BA91444B476ULL, 0x5772781E2BB03573ULL, 0x7C23BEB6B6031FE7ULL, 0x854767570AFA4C88ULL, 
            0xE8E9E2958256C39DULL, 0x1EA3EBA0539BB932ULL, 0x8CE992D85EF9E0DEULL, 0x22D748DE5371A514ULL, 
            0x34FEDB2403F11FB9ULL, 0x17992C6C4814B42AULL, 0x7D55F0E06B292510ULL, 0x62DA53EFD2074484ULL
        },
        {
            0x280C710B47BB2F25ULL, 0x3BCA6BDBF803B821ULL, 0xC862E3C2CDEC5CEEULL, 0x861482C2469BF009ULL, 
            0xFA9FC0B4F351CE9EULL, 0xF3DC7C366B096B6BULL, 0x83F6FD40D21FCAA5ULL, 0xCC6C0FE85C8B29B5ULL, 
            0x29D6E9C785EECA12ULL, 0x53CF3F64E724A793ULL, 0x353BD18FE37EB525ULL, 0x50450EF33D4088C7ULL, 
            0x06616D0A738F19CBULL, 0xFA8BA2A7809B4CDAULL, 0x7CAAAF9D42C1B01FULL, 0xECCAF2C6ED5E50E5ULL, 
            0xD7DB440001D27709ULL, 0x548EF47C211998D0ULL, 0x153069CC03CE0009ULL, 0x74CB695FCF46BDD6ULL, 
            0xE56DF21F365498A3ULL, 0x0DFB1BF914E28589ULL, 0x0E2A83FD74C603DAULL, 0x503833CD02D7E31DULL, 
            0x1C8E39ABB750A9ACULL, 0xD29259C767ADF17EULL, 0x1C36D291FA65039DULL, 0x6E52DF5FFB3A3007ULL, 
            0x0FBF7F2C2E69B054ULL, 0xFBB27793177FC602ULL, 0x87E756E939A377F1ULL, 0xC28605D33B43FB0DULL
        },
        {
            0x54C7840BCD037A93ULL, 0x8F9BF4680969C1B2ULL, 0xE7C20D951A179B1FULL, 0x76908F846549D6A4ULL, 
            0xE665EC9033F39F3DULL, 0xBF0CF93E94019A3EULL, 0x34B58AC19C381AFAULL, 0x286CF94D91739D37ULL, 
            0xF11FB2D2E1F7F4D5ULL, 0x1BE739212FCC4315ULL, 0xDDAAD7F14D7B48DFULL, 0xE187BD924609BF9DULL, 
            0x33413EA803E651E5ULL, 0xC094C38E0BB36A10ULL, 0xCBCD7D4D19B5DF68ULL, 0x6F190AAD88212304ULL, 
            0x65508F156CEEF2D5ULL, 0x8AE8BC6E22D29B23ULL, 0xE462F445471054B6ULL, 0x253D231E88E7EEA8ULL, 
            0x2E8609CAD93121C5ULL, 0xEBC801C9283B1729ULL, 0x5A462649A52D6761ULL, 0xE42304B12B11DC32ULL, 
            0x1ED97DEBBCB64082ULL, 0x1B47A49F55C35146ULL, 0xC8ABA1392646E88AULL, 0xADD3BFA24888DD8EULL, 
            0xFA49EF7718C0DFA1ULL, 0x2963CAC9ADFB1BB6ULL, 0xACBE9B8B9AC284EBULL, 0x5B5273296020312EULL
        },
        {
            0x7988A4CCD84BC5B1ULL, 0x78AE0D366DB371A0ULL, 0xBF92466B89821AB5ULL, 0x721642D4BB637726ULL, 
            0x99FF03A3A1BFA209ULL, 0x6B528B1C9057CB3AULL, 0xE5704AFC8BD0642DULL, 0x6BFA707E6C59E85DULL, 
            0xAA51A41318A5D934ULL, 0x5A1DEFD162B7945FULL, 0x01458715D885AB53ULL, 0xA8CAAF77E2CF7E4FULL, 
            0xEB33BFE13931DDE1ULL, 0x111D4B823B37E586ULL, 0xBD124CA0AA424DFFULL, 0x34DE15EEF483E4ADULL, 
            0x3C1825BBABFA417AULL, 0xF716D71DC0C26BB6ULL, 0xB6A2C502019FD82EULL, 0xD71B2F173036D3D2ULL, 
            0x9CF7B7281A288D10ULL, 0xD2D185D7DB7FDF38ULL, 0x95201EA19628F909ULL, 0x23B53A3B2BD4A8FBULL, 
            0xB5B90B10A5830C1AULL, 0x8892D3DB292C1E47ULL, 0x303F19E094782FF2ULL, 0x53A0F161B6E9F8FCULL, 
            0x59AA6C937469F19FULL, 0x0BCEF12517DC51C5ULL, 0x2C75E0C6D6B56696ULL, 0x607EDF4BD3D216ECULL
        },
        {
            0xB9B13FD7246919E6ULL, 0xFC0E1FD9366108E2ULL, 0xA7BC506910E9A1ECULL, 0x6617D55D5766DF30ULL, 
            0x9DCF5149C3F3D488ULL, 0x340918273E140A63ULL, 0x1FD4CF4F8C9C05FDULL, 0x7D2120E65BD88E7EULL, 
            0x4FCA6EE4BE6C24F6ULL, 0x78F97C98BD3FE374ULL, 0xC26485392CED120EULL, 0x47C78AAE1276CE8AULL, 
            0x79F137DFC6D2AD9AULL, 0x2B387A99B6335EFDULL, 0x7BB688821AEFF8A9ULL, 0x736955170A1FEB5FULL, 
            0x448CC1278759422DULL, 0x1BCB20D5BF1E0E23ULL, 0xE9AB85A8FD43A60AULL, 0x904861E43450E268ULL, 
            0x8322BF2ED3C248E1ULL, 0xE9C7EA8359CC030CULL, 0x0C5D10947CE044CFULL, 0xD7F5BACE13A57362ULL, 
            0x04E3B6613E0DACA6ULL, 0x397676D63684954AULL, 0xCD51CBAE42DBD90AULL, 0xFF8C57E7A96F2098ULL, 
            0x316A9EE2479867B7ULL, 0xE5BF19ACC78993C8ULL, 0xDDDBE01D766AF548ULL, 0x130BFE77402ED4E8ULL
        },
        {
            0xF1B78D606A41DA1FULL, 0x111A740CBE82CAC6ULL, 0xDA429E085F42FB07ULL, 0x503D909F0FFAE75FULL, 
            0xEE254D24DCD5EB25ULL, 0x2C9C1F22E2871027ULL, 0xA33DC5841D2456A8ULL, 0xD8231ED4261CC47AULL, 
            0x866CE854FEF3CEEBULL, 0x261A03BBB97460A3ULL, 0x5153B521FC338082ULL, 0xDA0B31875284A10CULL, 
            0xC9DA266DD2F08DC1ULL, 0x66B31F7B0A16E6F4ULL, 0xF285C43B093266DEULL, 0xB2BE090A5ABAE415ULL, 
            0x810DFE022A50B001ULL, 0xCAC5192492888F9BULL, 0x33DF600F810E7603ULL, 0xB1EBB5A973ED07DCULL, 
            0x0E89B4C00F61D81DULL, 0x2357A1240564A768ULL, 0x9A07D22306E7C78BULL, 0xF972FD142B50CB7CULL, 
            0x9CACD2BF885722A4ULL, 0xC4DB034D987DC939ULL, 0x20F68BA064942E08ULL, 0x2DC8AE1AB446F495ULL, 
            0xD78EF1DD1EE7B539ULL, 0xB3216DE4EDA59424ULL, 0xDCBAB41C33226DEAULL, 0xBF12C1B29551029AULL
        }
    },
    {
        {
            0xB3336121ABDB33C0ULL, 0x778098FB495D698DULL, 0x66EB886BA895BC80ULL, 0xFE58FFE4665E9828ULL, 
            0xEBEFF4DFF5AD580BULL, 0x2A385D8734608514ULL, 0xFDCEF6B0BAC9EB55ULL, 0x8EB9A3BADAFE03CDULL, 
            0xA746C41BAEECF80AULL, 0x516A30CA6632E9A5ULL, 0xF5B23363E4814741ULL, 0x1AC6AFBAA8A9BDBDULL, 
            0x45322AB8741095B3ULL, 0xF91002B6C760402BULL, 0x4838E1B1DA0AF31CULL, 0xD075BEE7DB0FBF0AULL, 
            0xADB9C4D1C36CE403ULL, 0xB151AFEB160B0E0CULL, 0x097318C944BFF3DCULL, 0x01114A175F5602E0ULL, 
            0x8E949E68DFF83F54ULL, 0x0236AEE30DFE9A3DULL, 0x996E33BE4D47008DULL, 0xCD6D74385D8A84C7ULL, 
            0x323C13F7B553B03BULL, 0x717D78E71655780DULL, 0x2F203FB05E1E2920ULL, 0xE2D64526BED39CB5ULL, 
            0x037DBA37F9E2E127ULL, 0xB41DDB0A034B66BCULL, 0xE9F3A71375EB0C5CULL, 0xBE8BF780227AD55BULL
        },
        {
            0x309ABD8CA570E9BDULL, 0x93B0E02B55191FB7ULL, 0x21E4FC482FD0B527ULL, 0x835B76FFE3076843ULL, 
            0x3EB83069FA3A432EULL, 0xF6BEAE04B3C489C2ULL, 0x3EF304CA00BF1DE2ULL, 0x13F5D36F2D2812BEULL, 
            0x431817E87E0D4F8CULL, 0xB522164E6ED269D5ULL, 0xC0563C08CB3D9A4BULL, 0xFB26FF802747D859ULL, 
            0xB5209EFF65FB8DDDULL, 0x07CA82D6F55F10A2ULL, 0x9581D140799D2E2EULL, 0x849DBCDF020A4430ULL, 
            0x82894C5306E5E38BULL, 0xE56A9B929888B25CULL, 0x172EF083B8312FB8ULL, 0x55DFBBDEA70DD1CCULL, 
            0x9936E34FDF5FCB04ULL, 0x81A6B98FFDA67AA2ULL, 0x6DCCEE99E983BA66ULL, 0x59E0018C9F1CBA26ULL, 
            0xD82AAEE32A3466CBULL, 0x277A49E47F348C93ULL, 0x542BB7109F55598BULL, 0xA4C4C5C8ABD3277EULL, 
            0x566D93B84F99F770ULL, 0x51D9D202D563C9C6ULL, 0x5FCFAF31D499C848ULL, 0x3B33261B9AF2743BULL
        },
        {
            0xCDA91E808E8D6351ULL, 0x41A1D26751CE47AAULL, 0x1855155FB35373C3ULL, 0xDDFDF06BFAD02954ULL, 
            0x85822DB3D84CDF13ULL, 0x361C33C3BC80FB56ULL, 0xE984473B80DA0044ULL, 0xCB05182D71111E8FULL, 
            0xC2945609A2345703ULL, 0x2B8C88F071A18828ULL, 0x73F1116D21BC05B7ULL, 0xAC5CCCC568403435ULL, 
            0x8E6FB86B633E3274ULL, 0x0E6E877414E41622ULL, 0xE5BBA83BD7332653ULL, 0x41CD62B87377E31DULL, 
            0x281B5DD8C7019BD4ULL, 0x19806C6A28502692ULL, 0x44FF8E7B9BCF315EULL, 0x23353F0E55D8EB03ULL, 
            0x7F57973929F598D6ULL, 0x676F842F45B89D8DULL, 0x8754A43F4E48B760ULL, 0xD2164DB88AEB6033ULL, 
            0xDB1D1D9A3CEF46CDULL, 0x68EF6B604F0D0C90ULL, 0x4B187466FF8285D5ULL, 0x9AAA0F0F11A077C5ULL, 
            0xFF25F49B8254455FULL, 0xCA338848033C2E83ULL, 0x598B98078826C3E0ULL, 0x29B8904586EE75CFULL
        },
        {
            0xB855AB8F8B026D58ULL, 0x4B6C5D1CC925A5D6ULL, 0x21C23E7EBE51547AULL, 0xE75C0338EF97DAEDULL, 
            0xDB158D6C56A6F070ULL, 0x5FF9BE2DBA7C0F27ULL, 0x346B95FE0D37F8BEULL, 0xBFB94DD4A8C58BDBULL, 
            0x5ECD373DC6E54B8BULL, 0xC6FC522855B64C7FULL, 0x491960A7C78B5A70ULL, 0x26FEDA01AC81ADBCULL, 
            0xA7D87D11BF2557B6ULL, 0x2D52291A9007C634ULL, 0x5347428C17DC68C7ULL, 0x3BA9A98545929816ULL, 
            0x7F4DEF4AD864DB64ULL, 0x3ADDC467B221A1C5ULL, 0x246A5151A9FE8D83ULL, 0x889896F77BBB6A02ULL, 
            0x4B07EE256033C9EBULL, 0xDC799215CAFF6466ULL, 0x6D12165AF6E10E10ULL, 0xD1C68560E2EDFFC8ULL, 
            0x2EB6319C044C859EULL, 0x249FC627B4FDB5BFULL, 0xA198F99DAB0440CBULL, 0x18ED0FFF05372647ULL, 
            0xA0F5B1EF8F75857FULL, 0x3186FB5C88D00EBAULL, 0xE0A2C9519A012C7BULL, 0xA902E17A668D98ABULL
        },
        {
            0x7207FB3A1DDB0D4DULL, 0x8F9E678D4370D8A0ULL, 0x3635D193A290D767ULL, 0xE2A743BD7372E8A2ULL, 
            0x66E7D7C023428AD6ULL, 0xFAE5080800ADF436ULL, 0x07A0646317824C07ULL, 0x23BEEB051BFE1A17ULL, 
            0x9A9400C84AD2C134ULL, 0x147CAC8126FB4A45ULL, 0x2267D54D941A98B0ULL, 0x944089F7E29E4D53ULL, 
            0x44392F6BA9150CF8ULL, 0x3387B27A44847ACBULL, 0x11ACBF8916F84FE0ULL, 0xFDEC8904FB5D450FULL, 
            0x7389B099700CEB76ULL, 0xF922AC6E2F3E14A7ULL, 0x74CFDD8DC9258077ULL, 0x898AAB3FFB10A5A1ULL, 
            0xC3B51474A1CEC37FULL, 0xE2390C72FA18426DULL, 0x323DC3B430D8FE0FULL, 0xC58A995608CC737CULL, 
            0x62B8B74348CDE894ULL, 0xA280B5597F89A8EBULL, 0x0B50AEAF928AE62DULL, 0x53C14B27E6AD6D14ULL, 
            0xBEAC9F74DCB83911ULL, 0xF061F9AA5DF00FDDULL, 0x80E4F96A7E6BBBC2ULL, 0x9DEE18F2E5CD0C6EULL
        },
        {
            0xBD88DACE4647B8B9ULL, 0x8C2DEE7ECEFA245DULL, 0x5BF61BEB9B4459BDULL, 0x2D1D49118DA39E57ULL, 
            0xDFE64A2A3D6E8511ULL, 0xFF8B00821630BBE2ULL, 0x290842D933DF4054ULL, 0xACE5A0DDA571849BULL, 
            0x9EB0201802D480FCULL, 0x36D15045589544FAULL, 0xDF496F39717D777AULL, 0x9B9453C0E6BA841AULL, 
            0xE9E85C62500AAFE9ULL, 0xB91E13330C266F35ULL, 0x4C2199483E0EF0B0ULL, 0x81A058AD9CB6CB8BULL, 
            0x7D374016E8BD03C2ULL, 0xF24916C2C2F441A5ULL, 0x14360C4324FD3CC4ULL, 0x43F6C0BD73C36FBDULL, 
            0x05926DC5410DEFABULL, 0x4EE8E21E675A65B4ULL, 0xE38E6DDEB6896087ULL, 0x07B1E5EA96AC7CD9ULL, 
            0x847512A017C5F17DULL, 0x838B94E065A61B7EULL, 0x9BD02FEF3D698A0FULL, 0x7BDCBDF26641C6C1ULL, 
            0x866C066A1BD4CF93ULL, 0x639272174C64B960ULL, 0xE0F802FCBF326E3DULL, 0x3627DF6768797E41ULL
        }
    },
    {
        {
            0x962456AF53F785D7ULL, 0x2F8DC34A66650789ULL, 0x589665E85012E86BULL, 0xB38ED807E3034239ULL, 
            0x9BE4699133B487E4ULL, 0xB52E94AA8DBEB481ULL, 0xA2127C58723A5F84ULL, 0x824585E434B2CD3DULL, 
            0x44AF851B48ED1CF5ULL, 0x070A3BA49145BEBBULL, 0xF48A6D02D864F0E7ULL, 0xCABA57D8B4AEBF52ULL, 
            0x1062CFFAA0D026C3ULL, 0x649A2CBD15A73D65ULL, 0x1604A9E08914FFB2ULL, 0x9B8132BB1DFF1FEAULL, 
            0x876FDF5D7F57B418ULL, 0xA8C7A1FA83BF990BULL, 0x74C16E63FC865269ULL, 0x905F34F8653A84B5ULL, 
            0xE79F14A17515C6F0ULL, 0x4C5140173E468133ULL, 0x23B40E1F1B7E0673ULL, 0x3FCBAC7F6C40C1AFULL, 
            0x9532B71A6B8EDD24ULL, 0xA8878645779B1559ULL, 0x5962911B4B8F2389ULL, 0xF8F0CACF83BFD928ULL, 
            0x0B28660DBFC64AC1ULL, 0x5EF9C15F2E2ABF3BULL, 0xE42FFCE4FEBDE515ULL, 0x9DD4599E4BA0B8FEULL
        },
        {
            0x2F33CB8C01B46C15ULL, 0x1E5F6AE9BA6080FBULL, 0x9B3F7CB0B7FD3F4CULL, 0xF10279C1A75B6D42ULL, 
            0xF0FFE71E77244133ULL, 0x0811C77107ED6D70ULL, 0x49F373BD2CF80025ULL, 0xA9957EB309D718DBULL, 
            0x3589EC04B4936490ULL, 0xED31472C24803219ULL, 0xB71C3559752C76E4ULL, 0xCE950DFA06398CF1ULL, 
            0xB27FE85605BEE6E1ULL, 0x79598A058784C74DULL, 0xEA0032E9950EAC9FULL, 0x58A138043F7652E3ULL, 
            0x43F7B3ADC699B532ULL, 0x98BB7BBEA9E6E541ULL, 0x46864B1AD57D82F1ULL, 0x6E13C444205EF171ULL, 
            0x585938C71A2BC43FULL, 0xC5A45ADFD713183CULL, 0x63E8904D2D2021E9ULL, 0x97C9DE5CEE9F7A43ULL, 
            0xE323E8ECAF1E5618ULL, 0xDE9E042C30AC8F46ULL, 0xC44661A3CAD7A92FULL, 0x8B91272D51903BCCULL, 
            0xE1EC728354E0C58CULL, 0x3F95561CF389E39BULL, 0xA50107368A89D980ULL, 0x35E4EFD0077C3D6CULL
        },
        {
            0x323494CA43F11532ULL, 0x1ABF4BEA6973EBA4ULL, 0x532E3F73B132E27AULL, 0x258CE41C23EE8E6FULL, 
            0x25BA9F44CBAAD1A9ULL, 0x19BBA48736F243F0ULL, 0x2C82B0F4B7550CD1ULL, 0x27EC9C3AFE69F0ADULL, 
            0x76330F7585C25357ULL, 0xC04458EAFD8CEF17ULL, 0x51CA493DE242A8F3ULL, 0x975746887C18A9F8ULL, 
            0xE12819055E89A9F3ULL, 0xFD3541987E9B91ADULL, 0xF54433E135ED3CEDULL, 0x7DAAACD1B324BD8FULL, 
            0xEC288692670DB724ULL, 0x46FBA30DC1E11EE5ULL, 0x1972E27CD70F537BULL, 0xFD7F47CD2C2DE385ULL, 
            0xB673E1F2E624AE61ULL, 0x7BABA0EB0793EE5DULL, 0x291D13DDF18925E2ULL, 0x45A73877A89CE692ULL, 
            0xB3E20996370AD509ULL, 0x0B70A7EC14E4A57DULL, 0x37DD423A54F6F434ULL, 0xB9943FFE334EDA29ULL, 
            0xF1E2E30D60BFAEACULL, 0x5E35871C7F08413CULL, 0x5D8E460848C2491EULL, 0x13BE02702A84F02DULL
        },
        {
            0xDAE28BD666346216ULL, 0x97A1D5942B268CB1ULL, 0x540D77BF5EB32FDFULL, 0xDA5900BE381336D2ULL, 
            0x0FA30F6AA6399860ULL, 0xD68040C9E2B572A8ULL, 0x7179DA5DAED9724BULL, 0x1AA618066B35ACC8ULL, 
            0xE19FF57959E3F4D2ULL, 0x87A07C7EB003270DULL, 0xA37710BB17768706ULL, 0x7C46587936882708ULL, 
            0xC695147A4E305048ULL, 0x9EF4571435EDA40AULL, 0xEBC97481AD674EC2ULL, 0xEDA993E7FA418B17ULL, 
            0x69A1931F5004E35BULL, 0x235657C148E65E47ULL, 0x0DED12EEC7C64F50ULL, 0x91EE4E3D98CB9E0FULL, 
            0xC8DF5B93A2BD84BBULL, 0x02D4C7E139438A97ULL, 0x200986D7B5975BBDULL, 0xDE6E1553B60040B8ULL, 
            0xC4F4E2E3C38786DAULL, 0x084E0102AB330E39ULL, 0x48A0A862CFCC1A7EULL, 0x5BC1CAB89693EABFULL, 
            0xD53D66407964A486ULL, 0x000CEBE6B80A9443ULL, 0xFE8C6132F0163FF2ULL, 0x9DCF41087A12F46CULL
        },
        {
            0x728076C15C5716EDULL, 0xF4C260BC716E4351ULL, 0x7BFA9010B614DD1AULL, 0x2FD1DF66ACED22D3ULL, 
            0x08EA5DED53DF9091ULL, 0xFBAC22156381242EULL, 0x65309EBE8BBBF04DULL, 0xA3C9A724CEC52944ULL, 
            0xF618DD56C5764F9AULL, 0x6D9237F261A8AF44ULL, 0x63B70529D348E5D0ULL, 0x558A3DA74D503EC0ULL, 
            0x72422FEFF121C507ULL, 0xA0A3E87684CF8987ULL, 0xEA9ED2950DB03B3EULL, 0x12CD9B91082B63ADULL, 
            0xCD9993E317864200ULL, 0x822D39A6DC5D377CULL, 0x4C4CECD00B213DA3ULL, 0xAD7EFE880A0D1DFCULL, 
            0x2EF6F2A8784CCA50ULL, 0xB2A1D76CE9917B46ULL, 0xD4ED22EE8DF8A30EULL, 0x376203BE3E609B6EULL, 
            0x9C5516DFCC93F222ULL, 0xFD33F0F0E4FE2BDDULL, 0x12E662C50A99EF38ULL, 0x7FA75B5409E98059ULL, 
            0x99CDD14A931062A8ULL, 0x42B4296CBCD1D5F9ULL, 0xED917B43E93FCD1FULL, 0xD731DD1AF3ED4FF1ULL
        },
        {
            0xF782C62CE555C39AULL, 0x906AC405E385A7CCULL, 0xAB9572F0A8C60750ULL, 0x34BAC8AB2CB0B6F8ULL, 
            0x177F78BFF88D4EF1ULL, 0xFA0E97B2BC933256ULL, 0xCBE4C80BD1207428ULL, 0x6A28BD4B81784097ULL, 
            0x0DF10A296B1B4B9BULL, 0xC9856EFCC28E6C37ULL, 0x93FBB19888611E23ULL, 0xEE61645474E52C22ULL, 
            0x09AB5CEE5926D6D2ULL, 0x175AC5DC03023756ULL, 0x1DD9A1B2A3095151ULL, 0x534ABF219DC03726ULL, 
            0x932C6CA196AFDD12ULL, 0x242CA6646DAE71EBULL, 0x8930F49FBE667858ULL, 0xDFC721681B41D520ULL, 
            0x2C4DDA04703B7B0AULL, 0xF4FDDF22B740B56CULL, 0x83A5FE54F25302B7ULL, 0x1BFBA16BC6068D33ULL, 
            0x88139DB9D0594B80ULL, 0x6C166C1F77F945D7ULL, 0xE48AA4429958CD70ULL, 0x5C7CE92E45DA115DULL, 
            0x219A81B77227FE6FULL, 0xDD85FE639A1F3731ULL, 0x47583A15A0551157ULL, 0x9B83EA2F7DDE5AF8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rigel::kKeySpawnBConstants = {
    0x9431FC73CA083054ULL,
    0x6FD10BD04FF8459AULL,
    0x9355D2044D16FBCAULL,
    0x9431FC73CA083054ULL,
    0x6FD10BD04FF8459AULL,
    0x9355D2044D16FBCAULL,
    0x9E09102742E7F433ULL,
    0x3F0038F2CB74A3BDULL,
    0xC9,
    0xDF,
    0xAD,
    0x99,
    0xB7,
    0x58,
    0xD7,
    0xD6
};

const TwistDomainSaltSet TwistExpander_Rigel::kSeedSalts = {
    {
        {
            0x1886126BFCEA40EDULL, 0xEF695E9773F79367ULL, 0x1164324E183746D1ULL, 0xAABEEF6B5003E067ULL, 
            0x278091A11794E866ULL, 0x85D36BF42C9C9FC7ULL, 0x1137781866E1D9AFULL, 0x9C4782C9AAD15BC8ULL, 
            0xD211C810663E44E1ULL, 0x62666BBA4E51F511ULL, 0x7E0EF0120187FC02ULL, 0xF51669793EBDD1AAULL, 
            0xF2E74BED89262CDCULL, 0xEBEAE716CBFAAA44ULL, 0xECA62E91CC03E9F8ULL, 0x67D23AD1F4C8E26CULL, 
            0xC49968157EB9BAD9ULL, 0x0F830179C749EC99ULL, 0x11DE7247BB56A650ULL, 0xB28A53302671009AULL, 
            0x50550D2177A71297ULL, 0x8880E731D289F311ULL, 0xA1F10101E6B2294BULL, 0x948C3DCBE33CAAD7ULL, 
            0xB168ADB1D9E7CFB9ULL, 0x284C292F719D8FAFULL, 0x8DC2EE714C0016E5ULL, 0x47DBBE0434281E61ULL, 
            0x2EA53904BAF42155ULL, 0x6CF73241FA36FF0FULL, 0xC3E38B65399BEDF1ULL, 0xB9ECCFD05679D4DDULL
        },
        {
            0xF633F6051AB20085ULL, 0xAE45D7BB3F406100ULL, 0x081707991BDFEB23ULL, 0x2A8FD98229C35778ULL, 
            0xA105ED1A110B8097ULL, 0xF960E595CAA6D6F5ULL, 0x885C6575900815DCULL, 0x0DA332E2DFBC0382ULL, 
            0x9BC8850BCC28E84BULL, 0x405D55156CE6032EULL, 0x19FF2CD147E4407AULL, 0x248533D839E7317FULL, 
            0xA0CCFE2DF26BA976ULL, 0x8C71A6FE182D537BULL, 0x39F54BB9816BD482ULL, 0x43848D2C15981812ULL, 
            0x69BD35FE57B291CDULL, 0x053E3F7528C04D3AULL, 0x70808632FBBB45EDULL, 0xEBF09488AA9E9AFCULL, 
            0xAF91A56CA68D1FD3ULL, 0xAF9DD3CE5469CBD0ULL, 0xE06CF6E7801C753EULL, 0xCC85001BF9C7736DULL, 
            0xB7C36AF2D76C0176ULL, 0x9D9CE21F4456D7F6ULL, 0x285A79D257D45E15ULL, 0xC1492FDA0F2ACAF7ULL, 
            0x4AA2983D040CC69BULL, 0xC766AF0DB1AC3DD6ULL, 0x2874EBAAA126E64EULL, 0x45AC74EA067949D6ULL
        },
        {
            0xC44A5709D7CCCEDAULL, 0x813024E0BD7AFDD8ULL, 0x9A4BE6578641C21AULL, 0xEFB43E32115F0C73ULL, 
            0x8210AB9683C22A4CULL, 0xA480A13C8ABD6E38ULL, 0xD6E74864F9A085B9ULL, 0xDBE768DDE3A4F187ULL, 
            0xF34AF7466484C4A5ULL, 0xAE275B8413CACDD4ULL, 0x50FF5DC076C6116EULL, 0x65C0790834A437E5ULL, 
            0x369529F41FC9BD09ULL, 0x7D54B005F101030DULL, 0x700039F96410B1C8ULL, 0x0CC5FC0C15C5D027ULL, 
            0x4A0C4DDFE2B9D6CDULL, 0x4984D9E9D974B29EULL, 0x4513520FF710141EULL, 0xF4EBA69481711416ULL, 
            0x561134C723EF1F62ULL, 0xD3432048D980D847ULL, 0x0D9612290A59C657ULL, 0x7106FE47C527BF14ULL, 
            0x13782EC04FCF54B7ULL, 0xBE5575247F2F1E4DULL, 0x125E1292F124C512ULL, 0x8D51879464800BC6ULL, 
            0x40C931A17C573D7EULL, 0x95FCA26DC8F71866ULL, 0x3CE8B303E78ABB00ULL, 0x504CDBE7F64F6672ULL
        },
        {
            0x6F60F4BAFA466917ULL, 0x391F24C010D179CBULL, 0x82719CABB3DB4772ULL, 0x32709F75CCB0E680ULL, 
            0x6176D133902F0E40ULL, 0x0DEBBA9752A1A157ULL, 0x6E46C2810CCAA127ULL, 0x5C9BB05D0C39212BULL, 
            0xEA55D2C7CC915956ULL, 0x88CBF8D178467F94ULL, 0x4107DDD37109F30CULL, 0xDABFA5F24B34AA6DULL, 
            0x6CE13E192221C209ULL, 0xE36268D6973C7B0CULL, 0xA50FB82A758FAD48ULL, 0x4C361E44B3BADB21ULL, 
            0x85835D415AF3CD08ULL, 0xD648CA05924E0ACFULL, 0x6706FBF160A6EF6BULL, 0xF6461F0DBFF70BCAULL, 
            0x4C2D2A040A701359ULL, 0x95E3D7799ABB5B2DULL, 0x8ED88326520FDE5AULL, 0x1C1C13678A03F7EBULL, 
            0x498388861073971AULL, 0x7AD598319A4C9E10ULL, 0x5729EA35617BDF28ULL, 0xA9DE00D7393EFA24ULL, 
            0x85123AFF065626A1ULL, 0xBEEF5587F18106A7ULL, 0xD734917A008846F4ULL, 0x931474F871135990ULL
        },
        {
            0xCE94F815B4716F99ULL, 0x888661A30A25937AULL, 0xD8399E8B1081C334ULL, 0xA295406F16B16B37ULL, 
            0x47ED347F91C4398DULL, 0x3942A36004E96ECEULL, 0x9782B053BF2DE18FULL, 0xCBCC5F53182AC851ULL, 
            0x2E40B1258356661AULL, 0x100BDFF0FB7C6768ULL, 0x6BF4B755C7001146ULL, 0x7586DF6D1B985321ULL, 
            0x064815D166D8AFF6ULL, 0x80B00F4515D05F66ULL, 0x65F2BAEBDDBB7DEBULL, 0x9846FDD9D6380857ULL, 
            0x0E1A87F0DEC9B4D8ULL, 0xC155C2226A37CDBAULL, 0xC9CD9C7059A608F9ULL, 0xD0099FC17304FD8AULL, 
            0x42055C02EC334DB5ULL, 0x6F07866D45E504FBULL, 0x17BE7A42044AC0D8ULL, 0xA8A0A94E6C85B770ULL, 
            0x034FA63423F0BF8FULL, 0x4C7209AA70135C87ULL, 0xAE7CD36CDA44998DULL, 0x3C07E6B4E0E5130BULL, 
            0xE0E50D8968ADFDC8ULL, 0x8A7C380A6F3B4C9BULL, 0xC76612F7472A787FULL, 0xAE804B6D90C150E6ULL
        },
        {
            0x534DE28214C28BBFULL, 0x07FDE8F373FAE683ULL, 0x8EEDC3066C4729F8ULL, 0x4F731F907BFD2198ULL, 
            0xA48FDED570836573ULL, 0xFD6476FFDC1435D1ULL, 0x47655EBAC960A73AULL, 0x4D8ED7891C752398ULL, 
            0x55CEDDD226EE4E23ULL, 0x2E26E45467D00D8CULL, 0x594321697A3E0A55ULL, 0xFE7DE15043C35B52ULL, 
            0xE2DE4F269A4628FAULL, 0x6111056A909035D6ULL, 0x9319E5206CE6C1CBULL, 0x963E5380E4B7F082ULL, 
            0x3E258E43022B5F41ULL, 0x442E8080BE363A66ULL, 0x5032461B86037403ULL, 0xED13F36FBC0D04CDULL, 
            0x19E77E60CFC0B97CULL, 0x53A43D0C9815F845ULL, 0x472945968524870FULL, 0x0460B2BA55DC5CF5ULL, 
            0x40545EBBC80A3707ULL, 0x9E3D6A42EE129787ULL, 0x20536BA35DB954C5ULL, 0x101732D2D31292D9ULL, 
            0xA4B177F969C6A995ULL, 0x4F6DDCBEDDB25899ULL, 0x7637B623A7BD6859ULL, 0xA4DFC85D8F2C5135ULL
        }
    },
    {
        {
            0x7A5E6C9A2A5DE829ULL, 0x65F9765F693B7926ULL, 0x572DFE7F2C1E6313ULL, 0x6B3EC3B37B2C2885ULL, 
            0xEAF6AA2E9185BC15ULL, 0xCECCEE9618EC8E0EULL, 0xB5E580A906498C1DULL, 0xB70F9CF6DEB8FC7DULL, 
            0x05DD7A784B661A06ULL, 0xCE27A2357CA35EC4ULL, 0x28DBD07BC8430BA9ULL, 0x12AA8365FE38A432ULL, 
            0xF9EA34960C6AA97FULL, 0x522E5A351876E13FULL, 0x98538ED173969640ULL, 0x8EBB56331344E9ECULL, 
            0x107CE4C7DF7B1857ULL, 0x7774E57838E24067ULL, 0xC0C75B6856A091CDULL, 0x1DA5C4C54A476B0CULL, 
            0xCD0E9FD1F5F92DBBULL, 0x0CDA176AF01438D5ULL, 0x78AFBB75734384D6ULL, 0x595A20A197ADF494ULL, 
            0x2FED42F770238E17ULL, 0x15772171D97EFE33ULL, 0x488414EE11C285E2ULL, 0xE2288283D61251CEULL, 
            0xC6976C6B635B4B80ULL, 0x8F2206F77A7FAD6EULL, 0x3CC75DBA5490F8E6ULL, 0x4BA079F8917D25BAULL
        },
        {
            0x6CB699F7C903B1BCULL, 0x51668D1DCB2AEEF8ULL, 0xEA818A66FFF0AEC6ULL, 0x652DE0D1E662F9A4ULL, 
            0x7BB51B21F1807932ULL, 0x7CCF7071BDA4F629ULL, 0xB803C66EA0CD9521ULL, 0xB89600C9F28FF86CULL, 
            0x69C460AB6054666AULL, 0x57FA929FF233ED99ULL, 0xEAC90C5D0253E973ULL, 0xFD9D58DB9185BDC9ULL, 
            0x504DA87C9789DB11ULL, 0xD1850794393F5AE0ULL, 0x17AE53707A493C61ULL, 0x0D17672522082721ULL, 
            0x2185D0FAC693A31DULL, 0xFCBFB78B8E51FD32ULL, 0x16487AA0DDBEB74AULL, 0xE5F53570B71CD397ULL, 
            0xCB614A1E956F6F02ULL, 0xB75368F50892F0EBULL, 0x98E9DD6152436814ULL, 0x90D33E687E2F8E20ULL, 
            0x33B93D5D5F69B3D2ULL, 0xCD0655330A2946BAULL, 0x7F81B1A03AA4404BULL, 0xA07B3FD2B9D4F329ULL, 
            0xC60AE4BC01FEE188ULL, 0xA61B53E3B6A8A58AULL, 0x41638E8C24FA8997ULL, 0x809C0E15F917D0DFULL
        },
        {
            0xB8D5995B8282CDD9ULL, 0x11EE45E866123790ULL, 0x6FF6559187819851ULL, 0x9848B9C662555507ULL, 
            0x948E65E75EDB3A06ULL, 0xB9E54B3313290248ULL, 0xAD06951ABF801274ULL, 0x2D9B8B17704FE046ULL, 
            0x6560556C818327D6ULL, 0xF458203557153066ULL, 0x37D99D8C88A3A036ULL, 0x43F45EDC997C27E4ULL, 
            0x7784E4891320E687ULL, 0xCF356B912C16DF4BULL, 0xD075557F0A2E330EULL, 0xB2016843964D55C0ULL, 
            0x9E4A2DC6494C9D55ULL, 0xC6BD6E0DE01FECA7ULL, 0x5A6675911DC238EEULL, 0xA5D63178EF1ADA16ULL, 
            0xE3368715A91F2594ULL, 0xF66476C6C4F9AF3FULL, 0xF90D62D8EC1E16C0ULL, 0x83FA67B674276136ULL, 
            0xDD3CC2F3880280EEULL, 0x1DBFCD508F4EFF09ULL, 0xC9D5E042F9FAFDBBULL, 0x9E621CBE8BAEA13AULL, 
            0xCF81009DDE314D08ULL, 0x0E54C09ED2ED74CEULL, 0xB35A7B31A1B76C16ULL, 0x702CDE90EDAF876DULL
        },
        {
            0x92B498A3F8A5EA69ULL, 0x188D78BDD5BB0F87ULL, 0x852ECC9996596B12ULL, 0x0C8B4A1AFEE497CCULL, 
            0xA40AA1612F4D6238ULL, 0xDC531BDB72A9299BULL, 0xD430CC297CB1A28EULL, 0x044E8BEF6FE6427EULL, 
            0x6A7D1BCE48B7446EULL, 0x31E2D7F91591286CULL, 0x5C5B1BA829694E92ULL, 0x4A18C3FC20CD4130ULL, 
            0xB01464E0B2F1C3D6ULL, 0x44BF62B80E087BFDULL, 0x8E6045F7BF23566CULL, 0x8BD11F0ABC41D094ULL, 
            0xE3809329398DC685ULL, 0xE5C1496B454C63ACULL, 0x36E76C2D106DEC34ULL, 0xB5EA7C4E6BB0D6DCULL, 
            0xE14A56113634F3AAULL, 0x9AFBE112DC0DCA05ULL, 0x0E92AA2F31F1D20DULL, 0x4540F5642E314B81ULL, 
            0x46CD51A9D32883B7ULL, 0x25F4F6F17F7620ACULL, 0x574BECE4EDDB04F2ULL, 0xE068C741E49292FBULL, 
            0x7435011722CE5C6CULL, 0xD3C17CCD0DD17B55ULL, 0xDCC8599952B9E6F0ULL, 0x24EB88B7271AC742ULL
        },
        {
            0x00AB1E7498AE32BEULL, 0x56AD7901100BD93BULL, 0x9C6EAB6ACB046B06ULL, 0x83193D412D90B76EULL, 
            0x1A0078931EDE9EE3ULL, 0xF3B457652C1B9B00ULL, 0xDD73BBD81C94711BULL, 0x1CC3539C10DA523CULL, 
            0x063B5B179F0B60D8ULL, 0x73863A07D1B917AFULL, 0x29BCB54AA45888FDULL, 0x9D792CADDB5D89A9ULL, 
            0x5F82DFB8D81B69EFULL, 0x1AFC9FB6D8BA1C38ULL, 0x3F94E8BC5345BA68ULL, 0x391CA4D23700FC3CULL, 
            0xC4E665EAF80D7F92ULL, 0xEAB4CFA49E969977ULL, 0x28A7EAC0B68BBD8CULL, 0xF9DB863881D47231ULL, 
            0x7EA0EF5A44EF3DDFULL, 0x0295828E84E27DFBULL, 0x22D8F70273A81D4CULL, 0x5B760DE3BF6AEA0DULL, 
            0x268C609C3F8B4789ULL, 0x6FED28788252FE84ULL, 0xEA9049AB02336319ULL, 0x17479D0FB2385900ULL, 
            0xFF64968A96DB8DAFULL, 0x330AA1737A2E0085ULL, 0xB2C11CFDE2B1318CULL, 0x7357E8828127A552ULL
        },
        {
            0x8E8903CA5290A8EDULL, 0x966C8E3E35A2C82EULL, 0xEBD9099C151C978CULL, 0x268D28F54E29ECD2ULL, 
            0xE2E0C43FACCF7288ULL, 0xCA882C87F3DBC84BULL, 0x2CE4FCF7AB50A824ULL, 0x8D8D12A93BAE5281ULL, 
            0xA650B6CD627711EBULL, 0xE6581520682BFFE8ULL, 0xAD12B3D0A449B52FULL, 0x2A21DB88C11F7934ULL, 
            0xB2038811E0B5AE90ULL, 0xEC5591D826428C2AULL, 0xFFC4EB68CBBE2FFFULL, 0xEBC19C90C1B7E87EULL, 
            0x70874E19280CA588ULL, 0xD6DB7D486AF37110ULL, 0xB6217BA90B90DEDAULL, 0x05C44BF9FB89DFEEULL, 
            0x525875FA84AB5E46ULL, 0x9945A3AF268F5F31ULL, 0xEF7B18990B4C5F9FULL, 0x07BE46F37E176E43ULL, 
            0xB24F52800D076058ULL, 0x0A84C327ABC5EF55ULL, 0x2E76836ACD380BD9ULL, 0x6F8B22CD4D5DCE60ULL, 
            0xB88DA8F8EA952F7BULL, 0x3534A2D3361C29AAULL, 0xF22FD345254102C6ULL, 0x225F352BA96D8644ULL
        }
    },
    {
        {
            0x92625A3298B28F16ULL, 0x9EE819C6C86538D1ULL, 0x4246B07A784B3B87ULL, 0x8DA5E8484E78391BULL, 
            0xA74D20551E890C04ULL, 0xBDD2B223C9C273BAULL, 0x90206A1F84911385ULL, 0x4E43F8F723F6FA54ULL, 
            0x6C7A61C36BD8B419ULL, 0xB8C559ADFA3F86C8ULL, 0xBB41A309D9837420ULL, 0xB157FFE92FEBD006ULL, 
            0x59495B2BAED996DDULL, 0x0346B082D3F79E57ULL, 0x381AE08E218AF09BULL, 0x57914425C5C35659ULL, 
            0x6715365BFD6D311DULL, 0xD099DBEBA534EC45ULL, 0xCBCF8A5A437E316EULL, 0x2F96983528A675A0ULL, 
            0x43F69471E30F3246ULL, 0x44C409DF97722F37ULL, 0x5631CACA2F141C81ULL, 0xB15553A85EA88447ULL, 
            0x6005E57E9AEEE858ULL, 0xD447DC52198D93D1ULL, 0xA3362BEA6D63F1EFULL, 0x6CA50E03A52DCAAEULL, 
            0xA9D98E37D65FAF74ULL, 0x238F9E47128DEEA3ULL, 0x65B3307042B03291ULL, 0xC33045F79748E99BULL
        },
        {
            0x708EE05E841E4EF8ULL, 0x0633D797FECE2F16ULL, 0x6CCCA0CC29B3C56EULL, 0x05D09770EAAD6551ULL, 
            0xE8BDD9F5981E22DEULL, 0x72DB46B7C4B73C66ULL, 0x41CA922B454EF67EULL, 0xF5B6A59CBBC4BE95ULL, 
            0xB5DB0FD4B2D3257DULL, 0x619D43FD85D1CD1EULL, 0x53A590F1F855F524ULL, 0x4192B5D111181692ULL, 
            0x2DE6D0D87589D3C6ULL, 0x68FFAB760032838AULL, 0x76FFF6F154E7B3ECULL, 0x6EDBB6547E21187BULL, 
            0xDC33F59AFAC2E026ULL, 0xC00F7FC985346F0FULL, 0x204E3D08DE4D437DULL, 0xC537E1957F5DAD5DULL, 
            0xE58F179EE863498DULL, 0x0460E62D81742BC9ULL, 0x53DCEF257961489DULL, 0xFEF6102C25A836FEULL, 
            0x4106B55717F6DB90ULL, 0xF502D55005B535C9ULL, 0x73BA6AB35F002950ULL, 0x77B60E659BC88E36ULL, 
            0xB53A9A7844082B4EULL, 0x912E529407B01BF9ULL, 0x0119C239FF377E69ULL, 0x1221C2B07A6FDDA6ULL
        },
        {
            0xEE6D6806CD437E56ULL, 0x744D53569488645EULL, 0xEDD39D4FFC6E5B10ULL, 0x706C99541F5E654DULL, 
            0xD4DE587D7F38B0F3ULL, 0xDD8EE477574E6509ULL, 0x34835F10BD6FF250ULL, 0x96A940F8FACB3CCEULL, 
            0xF783E7FDF6EF43A9ULL, 0x5B70CF124D64865FULL, 0x2CA0C6BA86A16191ULL, 0x6484A6F99379B673ULL, 
            0xC7C95A27021304F3ULL, 0xA050BC3CF6FC39DCULL, 0x9830CD975F508BFDULL, 0x5E94276BE3C52DE9ULL, 
            0xFEC19A1965BE1941ULL, 0x9B64BA9A91B1A041ULL, 0xBAD2D99999B4F2A4ULL, 0x917DFB797E2F1C6BULL, 
            0xACFF16B205EEE7B1ULL, 0x083E7249D2EA2250ULL, 0xB0D188A436ED7D5FULL, 0x796C2CB17918995CULL, 
            0x0190D26E09CBF1F1ULL, 0x06093841774DF208ULL, 0xBC5B014FAB0CE4C5ULL, 0xD0DD6FABDCC4AB62ULL, 
            0x5CAA868704D53032ULL, 0x4A4F7E9768832424ULL, 0xA3165BB8EE120813ULL, 0x9D21A9801015798CULL
        },
        {
            0x93342BC49E5DC6ACULL, 0x8F73CC717EFC7A1DULL, 0xCAA290B27B9FCE38ULL, 0xE960E1D7BC7B06CDULL, 
            0xB8A6BFA6F01571BFULL, 0x6FF9456579FA682AULL, 0xB36856EE002613A1ULL, 0x6AAE81B908CB124CULL, 
            0xF16A1F0B194E262AULL, 0x2956E0C0D974518CULL, 0x1A44B58BA7C196A8ULL, 0x5B9A44C8AB98A574ULL, 
            0x14A498C975C659A5ULL, 0x4AA800FDED1C4EC6ULL, 0x1BE62067EAB5AD44ULL, 0x8797A78980415E77ULL, 
            0x786B2EFC07274583ULL, 0xA9681C0E669C10EEULL, 0xC9557660BF695A3CULL, 0xF012D1585EBDAEA0ULL, 
            0x7CFF29489CF98E93ULL, 0x6F4E70C6DACD4650ULL, 0x4D241C58D8B93C3BULL, 0xF11A9ABCEC58AE81ULL, 
            0x66F2D4CBC4FC8EEAULL, 0x8C2D6EE283A75A5FULL, 0x797C9D6D96453D08ULL, 0x2BCA821B5C458B2BULL, 
            0x650A0E9529301C3BULL, 0x08EE498D470EFA29ULL, 0xC3FAA0B5CA3BBECFULL, 0x34171FD37831EBB3ULL
        },
        {
            0x28A620FEB829B34CULL, 0xB0347F46BB37595DULL, 0x49350A1DA83DF95BULL, 0x04420AB1973D6E21ULL, 
            0xB3AC2EAB176A2631ULL, 0x742B1AAF8A50F50AULL, 0x31CC27D49A23A401ULL, 0x136C50D0C72B29E0ULL, 
            0xB41C879E25B1F371ULL, 0x299D759E0398A20BULL, 0x6726325F0A601BFDULL, 0x556154301231BE9CULL, 
            0xEE3AFC2473ABA339ULL, 0x783FF0B8CA713C98ULL, 0x022A8A766FB61849ULL, 0xB4C25A4080461B66ULL, 
            0x5396BE927425AC79ULL, 0xF0F7BDFF238A8A1CULL, 0x26662423F62FDE0CULL, 0x9EAB71C977B6D71EULL, 
            0xAF339ED3C765D8C6ULL, 0x0874C5314BE4F718ULL, 0x63522766D06E29DDULL, 0x1B0BEB111E9EBA95ULL, 
            0x24832FC526C0698FULL, 0x92F13E591B62FE3CULL, 0x3909693E93301917ULL, 0x632512DDFB8D4350ULL, 
            0xC5D2560A727FC62EULL, 0xD5B94A0AB97A3556ULL, 0x3EB3B7CAD2C404D2ULL, 0xD0E25227B0EE50C2ULL
        },
        {
            0x87ECA678E5A87FD6ULL, 0x6B603893080504D4ULL, 0x91BE02713D7C1504ULL, 0xA7770EDEDA2C0479ULL, 
            0x075B5FCFD08035DCULL, 0x159E6FBF09BE4A32ULL, 0x351843A0C1F6E1CAULL, 0xB944A5BCA6D2B7F7ULL, 
            0x29CC7BA6E38180C4ULL, 0xD0F4EFD15CB06986ULL, 0xDFE5D328B1BBDD7AULL, 0xB88F8E721F16CA35ULL, 
            0x03BA8D0D77FE7017ULL, 0xBB35F66964365C8BULL, 0x3C5A8604C525E656ULL, 0xB61EBE9B6CEB90A3ULL, 
            0xE917D123B2EFDA5EULL, 0xEF39C02EC23D25B4ULL, 0x07369E66B6242991ULL, 0x7B30CC8FF6046DB5ULL, 
            0x7FBAB7E26106BBFEULL, 0xF8DD60881666D6DCULL, 0x6063A152DB051967ULL, 0x91AB46B5A842F4AEULL, 
            0x874B619D5127E4ECULL, 0xC60B90454735CFDBULL, 0x2ADB83991433355BULL, 0xD7D6587BB19994A8ULL, 
            0x92ED192512D2A814ULL, 0x6199B7A347F52EF8ULL, 0x942851036336EF2CULL, 0xD7A6AE32168EE36DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rigel::kSeedConstants = {
    0x0874D35CE96FB39AULL,
    0x46E0C6C9000CED64ULL,
    0x3F1BE791461A262CULL,
    0x0874D35CE96FB39AULL,
    0x46E0C6C9000CED64ULL,
    0x3F1BE791461A262CULL,
    0x7F8B295EEDC07595ULL,
    0xD526C7F6659F945BULL,
    0xDE,
    0xD5,
    0xF0,
    0xDF,
    0x42,
    0x3C,
    0xC1,
    0x6D
};

const TwistDomainSaltSet TwistExpander_Rigel::kTwistSalts = {
    {
        {
            0x4D86A11A9320CC58ULL, 0xAA08CC447E4FE546ULL, 0xA968684ECB8C0406ULL, 0x87F41D5C7F48E19BULL, 
            0x78CCAF8232D7A817ULL, 0x5339581F243C5E82ULL, 0x84196B42751A159EULL, 0x779DFC9D7601AD40ULL, 
            0xFACDECC58CC854ACULL, 0x0F3FABA22B43CAD3ULL, 0xE375DD788D5BC7A9ULL, 0xB7C9E3A5157F8335ULL, 
            0xDFA4A9BAB342743BULL, 0x56B8F8FE1AB0F67EULL, 0xCA86E097CECA356CULL, 0x15DF5C6E372CC35BULL, 
            0xF79A5C044616D089ULL, 0x2120F38B6D6735ACULL, 0xC124CAB2851AEB87ULL, 0xB4915073A849A9C9ULL, 
            0x8E951574605F72C9ULL, 0x1FF1810103741276ULL, 0x51217570D611FF13ULL, 0xCAE7551FB9B6AED6ULL, 
            0x84649F1943DD701DULL, 0x7C4A843FB03D00C9ULL, 0xA965889246D1E6B6ULL, 0xDEE9D91DA3EE3648ULL, 
            0x9E33C780323FCD53ULL, 0xE94D8E21EDCB91DBULL, 0x56562D61BB4D2E7FULL, 0x07AD49FB1DFFE51AULL
        },
        {
            0x3D1C4A363A1AC383ULL, 0x7E10E63B7013FB35ULL, 0xAF47B7E6775D2444ULL, 0xF4092409A9A2466CULL, 
            0xAF8792CBCE1DC802ULL, 0xDA92A61B617EB63AULL, 0x1DAB4CB6BE4FB212ULL, 0x3BC01D71BDF6BD65ULL, 
            0x4096BC1DEFF971C4ULL, 0x8DF1CCC2F023ECF7ULL, 0x30383A02EF955DBFULL, 0x0A23D89E8D363B79ULL, 
            0x1FE3F68BBB1CFB03ULL, 0xF7CD1D6563EDB144ULL, 0x84715B4F53F1A139ULL, 0xC49BAEDB5FB79081ULL, 
            0x37912E48AF232C47ULL, 0x1653F54495811ED0ULL, 0xCB1953E4EDE306DEULL, 0xCCF0593B0E9A33E6ULL, 
            0x9938155D9238D2B3ULL, 0xCAAFBC06AFB6E418ULL, 0x768C80A21252B79DULL, 0x41A9CEB7D220F64EULL, 
            0x5F4FA7165F2580B8ULL, 0x1B4B4A3CB60F9AFFULL, 0xCD95E1E4C5B5A9ECULL, 0x53E70F34C0D93F91ULL, 
            0x0DC7CE404D8C7F3DULL, 0xDEB4C39E1E145332ULL, 0x452075BFF98A38C5ULL, 0x0E60550469614B70ULL
        },
        {
            0xC6D6502D4B27C7E0ULL, 0x3EC2BE80B13EAB0EULL, 0x2A862AB42CED7D84ULL, 0x7230443AF27BC172ULL, 
            0xB080194C3828145EULL, 0x0570148CA2BEB2DCULL, 0xDE30296688CB493BULL, 0x42A500E5A5872173ULL, 
            0x8236EFF1499B6FCCULL, 0x3B35E3BAC1D31E07ULL, 0xDECC139E7E0B8B70ULL, 0xE5356F9292B68318ULL, 
            0x20609FE851B6C0C6ULL, 0x4907B05A563CD58AULL, 0xF64A12D98000D4B2ULL, 0xF08AD61B6335841EULL, 
            0xB14F78F61FC30A27ULL, 0xA555BB7AD6F5A74BULL, 0x89E2058841261218ULL, 0x984251695B9131ADULL, 
            0xDDBFFF769EF0909BULL, 0xFDEDC20387D19092ULL, 0xBE7E5F46F5BCF9EDULL, 0x9C632538483A4F14ULL, 
            0x8A5FF12074B7468EULL, 0x597F0FD65B4DF944ULL, 0x4F1CDA1B965DBE6EULL, 0x858C3D23B32C507CULL, 
            0xA66B8D23344B4A4AULL, 0x2D44DA9F28BDF088ULL, 0xED010405311FD153ULL, 0x5EA5FA764DDD7EFDULL
        },
        {
            0x10255EA00F816BC8ULL, 0x50F327A222982773ULL, 0xBFC3E25A5B9B81A4ULL, 0xEE6129E7A75E4896ULL, 
            0xD0561B5E3BC5A9BCULL, 0x296951D6199A6826ULL, 0x173C975D2403B6C8ULL, 0x68EEFAD51D41840DULL, 
            0xE332AA1FCEFC6DE1ULL, 0x380A05C3D740ECA1ULL, 0xFB79669F7C1025D7ULL, 0x66DFB593D03B1819ULL, 
            0x21B8BDB0ACC23AD9ULL, 0x6EFDE3731682D29CULL, 0x449728189C539425ULL, 0x354794027F7634C1ULL, 
            0xDB56557122A5B5A0ULL, 0x054FFC167A345C69ULL, 0xC1498ECB0403764CULL, 0x241C146ECA461A83ULL, 
            0xFC08F34E7D93D3B4ULL, 0x913035973A1A2201ULL, 0x6869F9115B2CC1AEULL, 0xB425EC2AE36DBB37ULL, 
            0x004E445E6FD969A6ULL, 0xF3DF8A69447BDC00ULL, 0x598CDACCA38E727EULL, 0x606876DB1D49489BULL, 
            0xB830D52923BA4D92ULL, 0x5D7685A8311F786DULL, 0xA2967CA9749F5B61ULL, 0xE1B439C248099625ULL
        },
        {
            0xBAE9B444189DA286ULL, 0xBA9CB561963DD563ULL, 0x1A99A2A7B8D0F191ULL, 0xF714EDAE0BD4C692ULL, 
            0x310907762A514660ULL, 0xAD9A916E31FB571EULL, 0xC915038ACE489745ULL, 0xD1612B0FB4893767ULL, 
            0x07AEB3EE48AEE7C7ULL, 0x2C2FA6ECE85CF999ULL, 0xA81C836D4F5C5A11ULL, 0x8E0B4559A3D9B9A7ULL, 
            0xF88345310A50546EULL, 0xBB1AD6F8B2A59F2AULL, 0x025847BD73A10A16ULL, 0xB3AE5658A0D6887EULL, 
            0xFB52A89547C7C3EAULL, 0x351DF1A25F1E1D1AULL, 0x9065F0CAE4A48914ULL, 0x3CF5916C1492B066ULL, 
            0x6198320AFF3B0B46ULL, 0x29EB1FF3D507E341ULL, 0xF2F28AFBD6D03103ULL, 0xF2EA859E3E85A137ULL, 
            0xE8415C6888DEC4A7ULL, 0xA8AB4A95EE03BA1FULL, 0xBE9F51CF009DBE4AULL, 0x67CA1FC43ECC100DULL, 
            0x8A00E8E0C9B31B4BULL, 0x3C99E9132888FD1CULL, 0xF8A8F1E3C79988BEULL, 0x12CE48246E794E17ULL
        },
        {
            0xD2BA8A02D79E5282ULL, 0x52F4790D254770F7ULL, 0x4587BAF8F7589C06ULL, 0x15B0202E8DFF5219ULL, 
            0xA19C24E8515CEAD5ULL, 0x418E425CF2471A6FULL, 0x04CD4BC125164F64ULL, 0xC0D8C03061358DF4ULL, 
            0x98910456ABDAE70FULL, 0x1B7F4765AA9ACCA2ULL, 0x2D40DD1A2AFF2BA7ULL, 0xEE928FCE13CE0E92ULL, 
            0xBE0DF58F57890593ULL, 0x49D91FFA9762363AULL, 0x09A84C9E17F4314DULL, 0xD6927D71130EDD09ULL, 
            0xF58FDDD7B97375D4ULL, 0x32CCD0054FD06CABULL, 0xCBCD5F47F5A7ED43ULL, 0x8D579EB4E0F86CAEULL, 
            0x5EC890C09C31E8CFULL, 0x50C1ADF8FA5294B3ULL, 0xB9BF852FA369ED32ULL, 0xE333BE9F4D02E890ULL, 
            0xDD3E309B22776D83ULL, 0x4EEA554B99363E3BULL, 0x5FC2DBCBEB9963D8ULL, 0x04B31AF244913B25ULL, 
            0x288CB4DC177A7858ULL, 0x2725E696F6DDACE8ULL, 0x19B16A03FA7E8E81ULL, 0xDF3DF35A989BD73FULL
        }
    },
    {
        {
            0x0F71CC99113309D2ULL, 0xCDA843B4CE01DA81ULL, 0x8DBCCF214F4875E7ULL, 0xD113E4A79CEEF6A9ULL, 
            0x045A9B94F97ADA05ULL, 0xF7963132BF35EC9FULL, 0x2CAA3AB21F665B0AULL, 0x704D65123EBACD36ULL, 
            0x78DD4570B2C35EA0ULL, 0x3609F35263D71715ULL, 0x63577D99E96511A5ULL, 0x9E9921A2FBDFAEBCULL, 
            0xACAE9C011B35A430ULL, 0x2398D5C996B8CA8CULL, 0xC06B7FDFF820AFBBULL, 0xF9FB3FBAD4BA5977ULL, 
            0xC0EDFAF846E4E17BULL, 0xEE6DFC3453573AF8ULL, 0xE14850F172A42D23ULL, 0x1282853B71665A53ULL, 
            0x94E28E133FF811DAULL, 0x875BA279F12BF077ULL, 0xDE2A42DD3222F7AFULL, 0x043E8C6008E3EDD3ULL, 
            0x8FA4BEFA6F7B197AULL, 0x27F6A9EFBE2C984EULL, 0x005BFFAA94B8A09DULL, 0xC48466BCDD348A8CULL, 
            0x3E650A7327D2D563ULL, 0x382239DCEA1B33D8ULL, 0x2E05CC82E4C26094ULL, 0x09A8D66040856A52ULL
        },
        {
            0xF153FAA2E73CE5A2ULL, 0xE9D49D9B804F98BBULL, 0x30FEB51FDFE7907BULL, 0xFD08E8FAC6ECA63DULL, 
            0xEE4A8FA711ACE811ULL, 0xD52A5F55BCFD3941ULL, 0x57878DB00E021285ULL, 0x8C9F9892C6A90658ULL, 
            0xEEF588F97C8200A8ULL, 0xA52F4ACDEA0423C7ULL, 0x8A568BF58F4CCC69ULL, 0xD335D7FE48950160ULL, 
            0x91EFE67EF2A6BBB5ULL, 0xE48D3AE289482282ULL, 0xE8BFAF0E890AEFADULL, 0x75C562FA5B9FA788ULL, 
            0x923AEF2936FD2953ULL, 0x725E8CAC7B55CFBDULL, 0xA5F6D10584CA0B08ULL, 0x0B03C24346AF7486ULL, 
            0x6F29A5F9FFB72DF0ULL, 0x25538E9315331EA2ULL, 0x2D08F1DAD8F88200ULL, 0x1F1134E0ECC3313FULL, 
            0x331AA26E26F9E7ABULL, 0x756751BDF6517000ULL, 0x50FAFA57F5467C19ULL, 0x251BF8F83BEFAA2CULL, 
            0x0404F27AE01C8DE8ULL, 0xBA63484B702591DBULL, 0x78CE68D3B55740AAULL, 0xDD4C59643F5A0FDCULL
        },
        {
            0xE292635085723CE4ULL, 0x2F178A1A7493951EULL, 0x791ABFAF89C5B7C0ULL, 0x158CBEF01437981AULL, 
            0x896D9261685BFFD9ULL, 0x70740B25AD5AF48FULL, 0x91708B79674E527EULL, 0x89E144F9D05E321DULL, 
            0xA8A03F4E9E873254ULL, 0xD067FF38732302D7ULL, 0x0F01EB5DB579E599ULL, 0x2059B670D6F96A20ULL, 
            0x45B83713890724C3ULL, 0xDFFDD33798535652ULL, 0xEC40137DD117DDBAULL, 0x698118E66B151384ULL, 
            0x471D6120DC166405ULL, 0x0D9C5A7F0F3F1B4BULL, 0x4B707FBAA14870E7ULL, 0xCFE6381DADD71E75ULL, 
            0x8CCCD84081B817A7ULL, 0xAE613015E0145CB1ULL, 0x332A89389F8755FBULL, 0xFBF2A4DE2E34BDCFULL, 
            0x3B9B98A6B07CB55FULL, 0x935B7E6560A6E531ULL, 0xB6F6A74E23D3242BULL, 0x6F51F42457EC41EBULL, 
            0xB310FB1E47892325ULL, 0xC13AAEC44E4296E5ULL, 0xF4C648E6AAF0DE51ULL, 0x56640FB680CF9B8CULL
        },
        {
            0x8C3AB7BFB6C61B48ULL, 0x1F778A764A5364D5ULL, 0x3A1A36F75B8753ACULL, 0x448EAB5F2EF492FBULL, 
            0x829DFD9805B267D4ULL, 0x43CFA01D40FFFF36ULL, 0x15169844E7CCED5FULL, 0xFE06F2D4230B999BULL, 
            0xB107CE7AF3B8F6DAULL, 0x42DA36D1D4A6EAE9ULL, 0x123DE988647FA370ULL, 0xD6A2B5DB39C546ECULL, 
            0x50A98C03F4ABC97DULL, 0xEAAC7832951E4E7FULL, 0x5F20BA3C44A1D402ULL, 0xF6EBE688B2011094ULL, 
            0x9930C1E95DEE6469ULL, 0x8C2F27ECFE11C013ULL, 0xA74EE3D095545980ULL, 0xEE9B7FEBF14DE709ULL, 
            0x93681A4F67DBCA73ULL, 0x7FB9D4593F344481ULL, 0x864DDA71CF039CB9ULL, 0x97C1F84B25022D8AULL, 
            0xD224CE1721E99699ULL, 0xA3CEE9180011DAC0ULL, 0xCEFA5F11011A7C83ULL, 0x519579573FCA16C1ULL, 
            0xC12E2B60D42D10D3ULL, 0xD8933AA68E7BE36EULL, 0xA576A32878E94958ULL, 0xCAAE787CC5CE3DB8ULL
        },
        {
            0x9A9B99EA43E39596ULL, 0xF18C8B8198537419ULL, 0x175E83656ABC4AE5ULL, 0xCB2A8CE8543DC8BFULL, 
            0x5528E4FCD59BD112ULL, 0x3BCAB12C412A1C65ULL, 0x4F8C9E4AF4964784ULL, 0x6A76143B9CFE0E26ULL, 
            0xD2E7C44D4DE87B62ULL, 0xE880EF3AE79D0C7BULL, 0x90ADB635BA25B5A2ULL, 0x8D1C357DF288838CULL, 
            0x5B5F2DD2E9C70E47ULL, 0xB8A0BEEDF1A7173EULL, 0x4ACFA229E99571B2ULL, 0xF8D1B6CEAF7F2A00ULL, 
            0x37CA8E9371B84946ULL, 0xBB4794F0B9899F18ULL, 0x7F9AE373C711AD80ULL, 0x6EBFCE19C68083C0ULL, 
            0xA6B26C3CE29F5C33ULL, 0x75F1B858171154CFULL, 0xDEDF4F4A10B380C0ULL, 0x935596F098C62D2FULL, 
            0xD5708DE3CADBDD22ULL, 0x65963B426E4FBF45ULL, 0x438B7728BC6F09F5ULL, 0x4737180F3F70743AULL, 
            0x9C9D18EC1FC724EEULL, 0x9C4394F547A7B8F1ULL, 0x284175451F6FC543ULL, 0x366E9F094DA72D3CULL
        },
        {
            0x01577DD149451DE6ULL, 0x3679CB2699F380E8ULL, 0xB22A5AC41B97AD94ULL, 0x7FC8252EB6680EFCULL, 
            0x307172747C85C49FULL, 0x03407E949E502E00ULL, 0x91B6CC02179F60BDULL, 0x2625113495D8A7ACULL, 
            0x00E8CF549C51156AULL, 0x92C8DFDBF1A89223ULL, 0xD50FD24365D7DC42ULL, 0x41562D06DFE9C1FEULL, 
            0xDF830BF7B5F8A978ULL, 0x1CD61D338B1282D3ULL, 0x4C65888DD2D06DFCULL, 0x57E927AB410A556EULL, 
            0xC4EE787B853D0720ULL, 0x58A910ED41712C83ULL, 0xDE3016ECE19CF5C2ULL, 0x1CE263AEBD670DA6ULL, 
            0x154FDD1142041FADULL, 0x17CD211057EB23E1ULL, 0xDEFFA88E7CD1CAF1ULL, 0x40B54542F220F524ULL, 
            0x6E557F705FEEAC8AULL, 0x03ED6B31B548D3BDULL, 0x6F7D2D5EE3A0D66DULL, 0x1F75219A9734CA73ULL, 
            0xAAE407D6B444578EULL, 0x4E987DE2A1FE63B6ULL, 0xE4621CA2A42184E9ULL, 0x4845900A2A4088A1ULL
        }
    },
    {
        {
            0x19D1ACBC38DE65A8ULL, 0x841639492339C494ULL, 0x82D37BCF1E9A271CULL, 0x820CF5C08747C766ULL, 
            0xD025ED3B3C3C28D9ULL, 0x0A97A02CD2F05A2DULL, 0xDCD2FFE3E1629415ULL, 0xB21268B8EA7F978AULL, 
            0x7CCD091713E61B13ULL, 0x50269BEF2452A27BULL, 0xF673E3F79B6969AAULL, 0xF1CC7CF7D3E788A1ULL, 
            0xA214C622DD53C0B2ULL, 0x1A9984A88C88CC4CULL, 0xCC47DDC8433720DFULL, 0xB39CC1E564B584EBULL, 
            0xAF158B22CF1065B8ULL, 0xA25746961C35883BULL, 0x218EC12F2912CF8CULL, 0xFB47BE92035341EFULL, 
            0xECD4EB006343EFBCULL, 0xE30500487AE127C8ULL, 0x381E39274C9049F5ULL, 0x49857A99BFD45172ULL, 
            0xC435B64D021A02E7ULL, 0x553323D7EA20C44DULL, 0x61742CB6BF1082E6ULL, 0x699E0AA8F5193D48ULL, 
            0xFE5EEAB6A0213A9BULL, 0x374F702316AAD637ULL, 0x5981B6F0CD8EEF26ULL, 0x7180BA55E56E753DULL
        },
        {
            0x10B415E4FC5632FCULL, 0xC1AB43E86E3BD41AULL, 0x320A347A2638505DULL, 0x73F1BC64F997F9AFULL, 
            0xB7EC4AE4DA0F5BB2ULL, 0x5390F58D89C5B4AFULL, 0xF57F2F1A0FAB0E37ULL, 0xA003D0E333EE04D6ULL, 
            0x272B40CCDC45BE4AULL, 0xA1AECDCC45C332ADULL, 0x2DFB2F88FE99E54EULL, 0x0E1C0FC551C080E9ULL, 
            0x5F9E79AF6767FCCDULL, 0xC5C095173EBC0371ULL, 0x4880FD70052C0262ULL, 0xA4E65BE9F8CCF6A8ULL, 
            0xB70CAA4A13D75F45ULL, 0x3FB39E9CC3E3094BULL, 0x6E1C4E583AE613FAULL, 0x669228DF8BF06F21ULL, 
            0xA4FA62CD47D7497EULL, 0xA1D4FE3F647A1267ULL, 0x5365D875CB576D41ULL, 0xB1035791F31C8093ULL, 
            0xFF376EF3A81FC5DAULL, 0x2346FD2783D62005ULL, 0xD0F8816D64967B87ULL, 0x510BDE6F065223F5ULL, 
            0x3DC5772AEF04709AULL, 0xFEBAFD4B246A9C09ULL, 0xE5896C23D8DE9CF1ULL, 0x51666B5E51E9BA05ULL
        },
        {
            0x2CC3410B7058275EULL, 0xFA0E3AFD76FDB506ULL, 0x79F0C596E0CE5AF9ULL, 0xEF9AB455F45854DDULL, 
            0x7A48E7C339CD1BB5ULL, 0x23700EDEB83F9F9BULL, 0x3A14830D8916317EULL, 0x76F78DB3BBE16473ULL, 
            0xE28E0B55BB8EEF2FULL, 0xB17A27D9FA985B35ULL, 0x468665A48E1C5905ULL, 0xCB8188E4A1C4D60DULL, 
            0x7C13E0718EADE108ULL, 0x5180725BB2207D5BULL, 0x816D8C9CEC2B07A9ULL, 0xC901E1FDFCA9AF9AULL, 
            0xFFFA26CC5F115C19ULL, 0x3621E5CCC88F3325ULL, 0x17F8543C28E96167ULL, 0xD8883B3AB7512CB3ULL, 
            0x7E45412FE93E5439ULL, 0xE27FEBFE83DEFA27ULL, 0xB191225F1A49941FULL, 0xC30A2B51283AB99DULL, 
            0x43DE51BDC7C3EC7CULL, 0x75C79EE94D67F4ABULL, 0xD67F32CB16652161ULL, 0xD94AB9F7A47546EDULL, 
            0x56E44DA24579ACB1ULL, 0x307BE733E546660CULL, 0x09C3BFC2DE57D96DULL, 0x22C81EAB4AC92A64ULL
        },
        {
            0x27D3E296F01404CCULL, 0xEEF6EB7ECEC12297ULL, 0x3B9CDABD97F26A75ULL, 0x2F07A09F2D95220FULL, 
            0xA268CB642D2901FFULL, 0xA7D63BB87A61F0FEULL, 0x8D182CCB12E92C97ULL, 0xD0828AE90AA09D19ULL, 
            0x8B31B55C06E8C555ULL, 0x0AE8AEC550BF0483ULL, 0x20361F12DF168D9AULL, 0x1966E763393BC834ULL, 
            0x59BF92C63E673CA2ULL, 0x6D2882D0AC18BC1BULL, 0x648976394C127FD7ULL, 0x0486716B2369C6B7ULL, 
            0x6FA888EDBABB988FULL, 0xF2EFB1B4EB4D4F04ULL, 0x4AAA020F5AC2A60CULL, 0x0F22779B3ECD9CF8ULL, 
            0xCB0B8AD2135DBB46ULL, 0x3CAB4EB3165567B2ULL, 0x7B36B2CB3724DCEFULL, 0x1948505FC6AAC446ULL, 
            0xD136D63B7712D694ULL, 0x6EABBEC867CE9D97ULL, 0x512C48BCE12AF990ULL, 0x6BAA5CDFB0A540A5ULL, 
            0xAC37AA34A931B912ULL, 0xD9163CB6A402118AULL, 0x3F125DC6ED89E74FULL, 0x4D926B06FDF59D3BULL
        },
        {
            0x976EA2C18A8E8DDBULL, 0x74D1227567289ADBULL, 0xA198AB6EBAA85088ULL, 0xF5E317D5E23C3F26ULL, 
            0xB3151D3E87B764A3ULL, 0xC405FCC485DDA242ULL, 0x133609CA9AA4FFE0ULL, 0x6FD645E1C190A29BULL, 
            0xDD1802D88F99C1B1ULL, 0x8436C43D80B3BD90ULL, 0x0848676C7FF95F69ULL, 0xA1E428ACBC7BB2B3ULL, 
            0x6A3BBF9050DBDE3BULL, 0x79A3883EE976FF85ULL, 0x443BD88C335085ADULL, 0x791FA373C522AD47ULL, 
            0x3A01C7D6172B9B86ULL, 0xBCC02378D47DC9EBULL, 0x44AAFACD241BD87AULL, 0x8C24CF22936A914EULL, 
            0x19121E04424818DAULL, 0xBFFD06AF40BDB4D7ULL, 0x2BDFDB8C00D0D999ULL, 0xF154D7666631C769ULL, 
            0x37B1F35262464A2BULL, 0x9F2E5E12614852F0ULL, 0xE704F3C797D1BAB4ULL, 0x73CEA40421C75075ULL, 
            0x98085FB96A954365ULL, 0xAC9D947E4FD3411BULL, 0x764F7058DF51ABCBULL, 0xD1E4DCFD30C912B6ULL
        },
        {
            0x7B13E102B48C3BDBULL, 0x6BD07B8FFE9100CCULL, 0xC3A5547794B7858DULL, 0x28FD73F4CC145A25ULL, 
            0x025E1D4C4D96EFC3ULL, 0xEF49CAFE0EB85E15ULL, 0xED259F29194DA875ULL, 0xDBFCDA85AEA2BF24ULL, 
            0xAEA9E661C21A7971ULL, 0xDCA787586643F400ULL, 0x7FB0E3308CE1EF29ULL, 0x75AFCDB98CF4DFFCULL, 
            0xAAA8E76431257B83ULL, 0xAE283418D4C47E54ULL, 0x094520762017F9A4ULL, 0xDF2CE6929C2F89B0ULL, 
            0xDFD6CABCD76E1651ULL, 0x0291F9BC2C5AA184ULL, 0x75EEC19CB91D6C6CULL, 0x1D12A2303EFEB6C0ULL, 
            0x58664C75DE577929ULL, 0x10BBA6E27AD98488ULL, 0x89A9C971C86A68C0ULL, 0x69069E44FC27C9A8ULL, 
            0x7FEE8197B361176DULL, 0x2C57C9C599C3D541ULL, 0x34E2F17BE6CAFC4FULL, 0x73BBEAFC3447ECCEULL, 
            0x11F77E79333A1E60ULL, 0x0E8250B097087C9CULL, 0x807A20413AC62158ULL, 0x0DCEB2073C844C00ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rigel::kTwistConstants = {
    0xF8DBE764D80B3A7DULL,
    0x2DE066A999FE9273ULL,
    0xA052ED023363DC84ULL,
    0xF8DBE764D80B3A7DULL,
    0x2DE066A999FE9273ULL,
    0xA052ED023363DC84ULL,
    0xE22B894597A0D09CULL,
    0x8CC248E0BE20B286ULL,
    0xE4,
    0x29,
    0xD9,
    0xAF,
    0xF3,
    0x7E,
    0x22,
    0x63
};

