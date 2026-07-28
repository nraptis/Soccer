#include "TwistExpander_Mirfak.hpp"
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

TwistExpander_Mirfak::TwistExpander_Mirfak()
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

void TwistExpander_Mirfak::KDF_A(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Mirfak_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Mirfak_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Mirfak::KDF_B(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Mirfak_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Mirfak_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Mirfak::KDF_C(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Mirfak_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Mirfak_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Mirfak::KDF_D(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Mirfak_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Mirfak_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Mirfak::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x96BEBA7F715F89EBULL;
    std::uint64_t aIngress = 0xB609D5A4C9628CE3ULL;
    std::uint64_t aCarry = 0xB5600A0038866E4FULL;

    std::uint64_t aWandererA = 0xFE10AB0A4A3D1256ULL;
    std::uint64_t aWandererB = 0x94E47518A8035B83ULL;
    std::uint64_t aWandererC = 0xE14D3FBEBFBFD7C6ULL;
    std::uint64_t aWandererD = 0x864B9CCE59A4225FULL;
    std::uint64_t aWandererE = 0xB6803D6DE4516513ULL;
    std::uint64_t aWandererF = 0x9F3AED5F5C8C420AULL;
    std::uint64_t aWandererG = 0xC19274BEF7845AC7ULL;
    std::uint64_t aWandererH = 0xFB746AEB62BFBACEULL;
    std::uint64_t aWandererI = 0xE24785E630AC5FB3ULL;
    std::uint64_t aWandererJ = 0x890600D82E8828F5ULL;
    std::uint64_t aWandererK = 0x8DAC3C9221AD9CC7ULL;

    //
    // KeyRotate A
    //
    aPrevious = 0x977E4B8D2EF79EDFULL;
    aIngress = 0xC0F2995A24FDC393ULL;
    aCarry = 0x976EB5956B6CEF6AULL;
    aWandererA = 0xC6E4C7EFD29EE71EULL;
    aWandererB = 0xE25594EABB21CAABULL;
    aWandererC = 0xB0AF711CE68771DEULL;
    aWandererD = 0x96AFC3017348CEF4ULL;
    aWandererE = 0x9FFFCF6FF74508FDULL;
    aWandererF = 0xBE7E414801D2B789ULL;
    aWandererG = 0xFD50BBFCC84D1C40ULL;
    aWandererH = 0xE857EF3002A23083ULL;
    aWandererI = 0xC6B0A1A8C2707781ULL;
    aWandererJ = 0xB3E62EAACF07CCCEULL;
    aWandererK = 0xB88DC3BBBB34FD02ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateAConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xEBF59B313D9D6D61ULL;
    aIngress = 0xC0C400E2759105A9ULL;
    aCarry = 0xAC9D468EAA54849FULL;
    aWandererA = 0xB595E723175112CFULL;
    aWandererB = 0xDB5A6CD84669C99AULL;
    aWandererC = 0xDAE5E2B4F802CA7CULL;
    aWandererD = 0x82AF216619C3B96BULL;
    aWandererE = 0xF2B1DE511211A02BULL;
    aWandererF = 0xC0BDDC7FE9F6CC83ULL;
    aWandererG = 0xF284B7142D4FC5E7ULL;
    aWandererH = 0xAE577275D7009262ULL;
    aWandererI = 0xEEE4F700433E004FULL;
    aWandererJ = 0xC2FFF0F205B6B4ECULL;
    aWandererK = 0xB09A62ED8258443BULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0x8C6A1332D1574D56ULL;
    aIngress = 0xBA296BB1065308F1ULL;
    aCarry = 0x81EA4BF070652F5AULL;
    aWandererA = 0xB4E1052CA2F955C3ULL;
    aWandererB = 0xE1AB4C75A3AA0D58ULL;
    aWandererC = 0xA6AFD6C0C1C7E00CULL;
    aWandererD = 0xCB265B2FC889D8EEULL;
    aWandererE = 0xE319BA4EF8638EA6ULL;
    aWandererF = 0xB0263A1F3200D667ULL;
    aWandererG = 0xEA18343B5E958C99ULL;
    aWandererH = 0x9B199AF43DA97724ULL;
    aWandererI = 0x80E55C5F43FFE9DAULL;
    aWandererJ = 0xC008533799D7B625ULL;
    aWandererK = 0xCD3F96E5BD082032ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnAConstants), &(mDomainBundleInbuilt.mKeySpawnASalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnAConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants), &(pWorkSpace->mDomainBundle.mKeySpawnASalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xBF1C5B2F0F736D5EULL;
    aIngress = 0xC4E556C7217D70CBULL;
    aCarry = 0xABB36C76FC2DD9A4ULL;
    aWandererA = 0xC6989C2560659691ULL;
    aWandererB = 0xAEDA615D1D4CCE59ULL;
    aWandererC = 0xA3A30BAD2C630389ULL;
    aWandererD = 0xDD6A211F07759729ULL;
    aWandererE = 0x9F32A25EEEE2AFC8ULL;
    aWandererF = 0xE7F189FDF998C000ULL;
    aWandererG = 0x87D90589D8DF1C9FULL;
    aWandererH = 0x84CD9E6C00F0864CULL;
    aWandererI = 0xEDC0160BF3E27E1BULL;
    aWandererJ = 0xA1AD592421D3BA43ULL;
    aWandererK = 0xBCE9224A5648FFC7ULL;
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants), &(pWorkSpace->mDomainBundle.mKeySpawnBSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xB2B9B3BF3FC6275BULL;
    aIngress = 0xD4F5FD5B0A9FE0E9ULL;
    aCarry = 0xB0F46970E25335B1ULL;
    aWandererA = 0x91E39C93E11D6BCEULL;
    aWandererB = 0xB028503D1B8A177EULL;
    aWandererC = 0xB0359A14C53D2E0BULL;
    aWandererD = 0x8D90DBBDCB0B3CC3ULL;
    aWandererE = 0xE9A356FC1827ADC6ULL;
    aWandererF = 0xE1A7581B1A039BB9ULL;
    aWandererG = 0x8E862C6867C6B9D7ULL;
    aWandererH = 0xEACA490802EA3F22ULL;
    aWandererI = 0xAD7056E8552E4669ULL;
    aWandererJ = 0xF0C8D980BDD5C1A0ULL;
    aWandererK = 0x81D6897158A8E0D1ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mTwistConstants), &(pWorkSpace->mDomainBundle.mTwistSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mTwistSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xAE563A8F540B2AB7ULL;
    aIngress = 0x8C485839A4B2A393ULL;
    aCarry = 0xABD3542514B565FBULL;
    aWandererA = 0xFE9F025B16895F8BULL;
    aWandererB = 0xCF028C00A1296985ULL;
    aWandererC = 0xC92BE174277917B1ULL;
    aWandererD = 0xFF5BAEDCEE5C9494ULL;
    aWandererE = 0xCBAA9780E1DF869EULL;
    aWandererF = 0xBCC7786B1417AF08ULL;
    aWandererG = 0xFE1010BE16E73A89ULL;
    aWandererH = 0xA33960A8A1BEF08DULL;
    aWandererI = 0x91D66F4DC45288E3ULL;
    aWandererJ = 0x809045C4A3117EEDULL;
    aWandererK = 0x87D470E837C2BAB6ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mSeedSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mSeedSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mSeedConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mSeedConstants), &(pWorkSpace->mDomainBundle.mSeedSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xBF921FB2BCC89E4DULL;
    aIngress = 0xEF2D45FD586C4AEBULL;
    aCarry = 0x934EEF22E3D110A0ULL;
    aWandererA = 0xFB5A8BE527DD1B67ULL;
    aWandererB = 0xF332C3B05B2FBCD5ULL;
    aWandererC = 0xBFDB0329FC565D9AULL;
    aWandererD = 0xD6C3FE600710D865ULL;
    aWandererE = 0xF2B1CCB9863338A2ULL;
    aWandererF = 0xEEBC6FE8974813EBULL;
    aWandererG = 0xC3889F06F7F2CEEDULL;
    aWandererH = 0xEACA78B1B68188E1ULL;
    aWandererI = 0xC2427E4267B0FE71ULL;
    aWandererJ = 0xFED8D9964FFB3ABDULL;
    aWandererK = 0x93F7B0943BF53A0EULL;
    //
    TwistExpander_Mirfak_Arx::SEED_A(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mirfak_Arx::SEED_B(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mirfak_Arx::SEED_C(pWorkSpace,
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
    TwistExpander_Mirfak_Arx::SEED_D(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mirfak_Arx::SEED_E(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mirfak_Arx::SEED_F(pWorkSpace,
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
    TwistExpander_Mirfak_Arx::SEED_G(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mirfak_Arx::SEED_H(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mirfak_Arx::SEED_I(pWorkSpace,
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
    TwistExpander_Mirfak_Arx::SEED_J(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mirfak_Arx::SEED_K(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mirfak_Arx::SEED_L(pWorkSpace,
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
    TwistExpander_Mirfak_Arx::SEED_M(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mirfak_Arx::SEED_N(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Mirfak_Arx::KEY_A_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mirfak_Arx::KEY_A_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mirfak_Arx::KEY_A_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mirfak_Arx::KEY_A_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mirfak_Arx::KEY_A_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mirfak_Arx::KEY_A_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mirfak_Arx::KEY_A_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mirfak_Arx::KEY_A_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mirfak_Arx::KEY_B_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mirfak_Arx::KEY_B_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mirfak_Arx::KEY_B_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mirfak_Arx::KEY_B_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mirfak_Arx::KEY_B_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mirfak_Arx::KEY_B_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mirfak_Arx::KEY_B_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Mirfak_Arx::KEY_B_H(pWorkSpace,
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

void TwistExpander_Mirfak::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA84D0D94469C9FDEULL; std::uint64_t aIngress = 0xB4EDF4E4E81FF366ULL; std::uint64_t aCarry = 0xFE987F6923893DC8ULL;

    std::uint64_t aWandererA = 0xB0012CC05E150BA9ULL; std::uint64_t aWandererB = 0xA12C6EB56143DDF1ULL; std::uint64_t aWandererC = 0xFD2B3CEE15B56487ULL; std::uint64_t aWandererD = 0xB3786A42AEEEE804ULL;
    std::uint64_t aWandererE = 0x82A52AAA0517B87BULL; std::uint64_t aWandererF = 0x90A4C1CD2BAAEC78ULL; std::uint64_t aWandererG = 0xC0267FBD03CB9134ULL; std::uint64_t aWandererH = 0x91AD231FDF4E74F8ULL;
    std::uint64_t aWandererI = 0xEC6430A1F887BDFEULL; std::uint64_t aWandererJ = 0xF18C675BC910DD94ULL; std::uint64_t aWandererK = 0xB2AB0A3AA296D15FULL;

    // [twist]
        aPrevious = 0x99BA9DF437C46A7EULL;
        aCarry = 0xB9B3A3955F924E59ULL;
        aWandererA = 0xA1492A3710BC1162ULL;
        aWandererB = 0xF4814DFA79075510ULL;
        aWandererC = 0xB6A1E6B32045A1B2ULL;
        aWandererD = 0xFA142E835C537176ULL;
        aWandererE = 0xB5D732B3EE662577ULL;
        aWandererF = 0xA8608ACB6F4C7828ULL;
        aWandererG = 0x8ABBF94CA209DD00ULL;
        aWandererH = 0xA28EDFEC0C9C7865ULL;
        aWandererI = 0x8B3DD05D5AC3DAC0ULL;
        aWandererJ = 0xACDE11BF4120C371ULL;
        aWandererK = 0xCB97042D72F0883DULL;
    TwistExpander_Mirfak_Arx::TWIST_A(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mirfak_Arx::TWIST_B(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mirfak_Arx::TWIST_C(pWorkSpace,
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
    TwistExpander_Mirfak_Arx::TWIST_D(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mirfak_Arx::TWIST_E(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mirfak_Arx::TWIST_F(pWorkSpace,
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
    TwistExpander_Mirfak_Arx::TWIST_G(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Mirfak_Arx::TWIST_H(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistSquash::SquashA(pWorkSpace->mPoisonLaneA, pWorkSpace->mPoisonLaneB, pWorkSpace->mPoisonLaneC, pWorkSpace->mPoisonLaneD, pDestination);
    GrowKeyA(pWorkSpace,
             ARX_STATE_VARS);
    GrowKeyB(pWorkSpace,
             ARX_STATE_VARS);
    FoldKeyRows(pWorkSpace);
}

void TwistExpander_Mirfak::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Mirfak_Arx::GROW_A_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Mirfak_Arx::GROW_A_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Mirfak_Arx::GROW_A_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Mirfak_Arx::GROW_A_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Mirfak::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Mirfak_Arx::GROW_B_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Mirfak_Arx::GROW_B_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Mirfak_Arx::GROW_B_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Mirfak_Arx::GROW_B_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Mirfak::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 21 of 33
    // Exploration cases: 0
    // Structural maximin 520 / 674; family total 10741
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
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7969U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3828U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 47U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 137U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 92U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1735U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1600U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 47U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1690U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1555U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 2005U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1870U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 21 of 33
    // Exploration cases: 0
    // Structural maximin 516 / 674; family total 10720
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
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6979U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7519U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7429U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7339U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 655U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 430U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1015U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 610U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 835U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1060U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1150U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1240U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 700U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Mirfak::kKeyRotateASalts = {
    {
        {
            0xFB949E71D909C58FULL, 0xA1E9D6689F65FB96ULL, 0x70B167EE00D4CC7CULL, 0x9D888CF1A2E8BAB5ULL, 
            0x0D971B1F73073BC3ULL, 0xD37B8B13C9478D39ULL, 0x6E037D038D2EDD56ULL, 0x5EDF2C72921C02B7ULL, 
            0x40829B03762E5E2EULL, 0x5CF8A84D69F1E814ULL, 0x899978868DA10547ULL, 0x48C69DA8A725441FULL, 
            0x98F249B1C5E27E3BULL, 0x34D07E34A83F33AAULL, 0xA5DEC505B2089F8DULL, 0x2206B801B7D85958ULL, 
            0x9293D9A085DB5FEBULL, 0x9C135CA236BBB86BULL, 0x951227CCB3786C33ULL, 0x31D227FCE74CD47FULL, 
            0x85EB680F807B237CULL, 0xB036A887DDE15235ULL, 0xC15F654C60EAE6A6ULL, 0x16187DD0B5B429DBULL, 
            0x35E843CD96F2117AULL, 0xFDB95E8E93A32C40ULL, 0x4F3FDB17D407F70EULL, 0x10C1C5F86E491B22ULL, 
            0x72DF8C085957A4F4ULL, 0x517BE984930DC2FEULL, 0x04CC8A56176DB3C2ULL, 0x69D93E8C5AC3A5A4ULL
        },
        {
            0x9B2D30CB32E8BAB6ULL, 0x1714B4CA7C290D37ULL, 0x6B6914740A3A1379ULL, 0x57B0C827E2CE0645ULL, 
            0xD2B23FB6DD5E0D20ULL, 0xF2B2D8F6726AFE70ULL, 0xCC84A1CA6D9904E5ULL, 0x30D1B7DC5CB5B819ULL, 
            0x6DF240C8125FD286ULL, 0xC9D3220185176EEAULL, 0x774EA7A1C874D6FAULL, 0xAA6CAB97CA265073ULL, 
            0x87252286AEF0FE3DULL, 0x1F21824215D439F5ULL, 0x68FBE8ADAFB14D28ULL, 0x65B2C1679476734FULL, 
            0x7465CAE26F992B77ULL, 0xE47B2338B24B28F3ULL, 0xEE495C12C1024B30ULL, 0x7E839B8AEE2C2C4DULL, 
            0x5029EC6B5D32C45EULL, 0xA5BE335FAE94E63BULL, 0x9BA0D7E5D84A14D6ULL, 0x09DAB9B1578D89C9ULL, 
            0xDC7391FE9E350FA0ULL, 0x1C6E39E236B42564ULL, 0x71BCB9602A9FEBA7ULL, 0xD5065AD92B370B67ULL, 
            0xE57A73272142B525ULL, 0x4552FA84160DEB71ULL, 0xBF714F56E23B5EA6ULL, 0x5B13969F8C3DA9ACULL
        },
        {
            0xCCA35D167EC61027ULL, 0x3D08C382527CFB5BULL, 0x8F82854A8F5212A3ULL, 0x258E92BE6E2F0AD4ULL, 
            0x9BB50596A51641E4ULL, 0xF9FD6C8CD9E1E191ULL, 0xC9C7AF89762250ADULL, 0x13BC823B380465EAULL, 
            0xDBB6D609D11C7C1CULL, 0x2776BC08D2C1E814ULL, 0x7C0C083E8C2A0BD1ULL, 0xEC37CB2517EA1ECFULL, 
            0x466C316CFDE2BAD1ULL, 0x7C0454238CA104A7ULL, 0x9A586B2618FE799DULL, 0x4FE0EDAE0C027FBAULL, 
            0xBA0FFC4788192088ULL, 0x666D45F254106A6BULL, 0x2C8EE436F181FF24ULL, 0xE7FAA4C7E428E679ULL, 
            0x21AC0B8B45C05F9CULL, 0x6D38AC45B2E2ED28ULL, 0xED4F7364019DBD1FULL, 0xF27B4AC924BBF3ECULL, 
            0x4B36BD4949D11073ULL, 0xF99D6095F72DBDFAULL, 0x7D7B36931D0037CEULL, 0x679557E9707E107EULL, 
            0x25C3C26330F41F53ULL, 0xC70814F0AA1300E0ULL, 0xB95C5010BA86B2C1ULL, 0x5594E070A8C83B4CULL
        },
        {
            0x422AA27291FEB377ULL, 0x68A6A71D46554028ULL, 0x4841CA47E27D2146ULL, 0x5C102CAEEE3763EAULL, 
            0x9C449C1159BD9EC3ULL, 0x510F960939A33746ULL, 0xF372392AAB0E8673ULL, 0x2486229198978FADULL, 
            0xFB3E422B5DC9EF30ULL, 0xBFDBC08FA157A54FULL, 0x22443ACAF98B6064ULL, 0x0B909A6DCDE63166ULL, 
            0x47BE45D4C8950BE2ULL, 0x0242110C5C373400ULL, 0xDBAD17DF446989CAULL, 0x3CDDDF435BFCBE74ULL, 
            0x15A8DEBEC07514C6ULL, 0xEA32EF1A4D5C3C7EULL, 0x534CD2F39FF4AF52ULL, 0x9D709021DE08FAF1ULL, 
            0x81BB59E3D4A97E7EULL, 0x1E6738296CC725B8ULL, 0x6FEF06C391D162F2ULL, 0x88AE36ADAB55CC99ULL, 
            0x21496D06E4386BCAULL, 0x4F8A151E178A4FA7ULL, 0x3C50D85371DEDF3BULL, 0x833D8F9A99D42713ULL, 
            0x882E1F0B10AEE183ULL, 0x6236F4007C6BF88BULL, 0x4DCBCF1B653BC2B3ULL, 0x657204F082D56D30ULL
        },
        {
            0x08FFF405C33387A4ULL, 0x574019E97E151406ULL, 0xD4C87827457C9FB0ULL, 0x96D901CCEBA7A509ULL, 
            0x45C873B4116C8C26ULL, 0xF885AB77DB763695ULL, 0x7511A118173CA7FBULL, 0x9CA60E543CD16B3CULL, 
            0x3162AC33CF90B497ULL, 0xEFBECE76EAD4F741ULL, 0x5A61B4E270A53175ULL, 0x3C66BA8C18AA5292ULL, 
            0xD3878FBBF99C18C8ULL, 0xE6F01A6BFE70D11AULL, 0x8843D7DF12309498ULL, 0x77078573F8E9FA57ULL, 
            0x72A8E49D934A7B3FULL, 0xC28BF1780FD7A919ULL, 0x8C626C164228D604ULL, 0x097A3F4DA782F900ULL, 
            0x789235110EEA9005ULL, 0xA5BB17C023FF40F7ULL, 0x00C7656EEDB6FCD5ULL, 0x4854534213E0A48AULL, 
            0xCA3996D162C053ECULL, 0xDACE0255852510EEULL, 0x7A96F429ACDFC81EULL, 0x9B66BA433E043C77ULL, 
            0xB142533A425C82B0ULL, 0x3868DFD6CC678233ULL, 0x50EB6987F64334B4ULL, 0xA0E5328D698583FEULL
        },
        {
            0xD25B8EF122694393ULL, 0x7C2A83C8F8B73044ULL, 0xE0A8D81E2CD07485ULL, 0x7F4271E38472597EULL, 
            0x670A9A23F23B8348ULL, 0x9F304632AEB31BC2ULL, 0x36B1F31B772E70ECULL, 0x4D7E6A30BAFE3931ULL, 
            0x83645F35821D1620ULL, 0x7E641FFC572C389CULL, 0xB1B628C553E2AEABULL, 0xAC958169A67619CCULL, 
            0x0E3E1774A269D064ULL, 0xB8E4E6C4FA7BCB1DULL, 0xE44D46265B92FA50ULL, 0x120CEED40587F8FCULL, 
            0xBBB6E4D3D0823745ULL, 0x7B93FAE377ABD08BULL, 0x73578989EE2A1EC4ULL, 0x22119D51D9DAFE36ULL, 
            0x2D4E451CE91634ECULL, 0x918C1A014B4DCDB3ULL, 0x44E5741819379B0AULL, 0x12345EA8F0819139ULL, 
            0x3B9582E828427DDCULL, 0xB01C87C694CF17AEULL, 0xB8A15049B156CB3FULL, 0x23115FDDD8BF8853ULL, 
            0x8A02AA32BF5C0247ULL, 0x49F55D00FB9438A3ULL, 0xFA71F017BC07C29BULL, 0xC9343391B8B4ADE8ULL
        }
    },
    {
        {
            0xD8D35B878CC6D3BDULL, 0x4C3236EF48812807ULL, 0xB9A8B019A4426499ULL, 0x97EBEA14561F11C9ULL, 
            0x450EE9D2403529FDULL, 0x8576245E4C46E58EULL, 0xF81668ED33367C1DULL, 0x81A0B1366CE99F5EULL, 
            0x544EF828B8AF0342ULL, 0xA2C56BB4152B9FB4ULL, 0x4DDF6CCD67CC72E4ULL, 0x2D22D339B76CA340ULL, 
            0x668B6C747FD3EAAAULL, 0x81DDDD60ED6CBC6FULL, 0x08CF8AD066881253ULL, 0xB2DE72BFAF113A63ULL, 
            0xDBF66D82040BBECBULL, 0x8421CD83FBC27637ULL, 0x842E20A0E0C86C84ULL, 0xE9C28262254C19D3ULL, 
            0xDDB3D2CC2DEE28C1ULL, 0x1795BEE03D466F1CULL, 0x3FED0738045F5D4CULL, 0xD270A1D084BAC64EULL, 
            0x4D637041F132A24EULL, 0xA88D75F026D3E427ULL, 0xB78A056D67C26456ULL, 0x88CD287960BEAE68ULL, 
            0xC2CDC04F5A1E0E19ULL, 0xE6AF70D32D907022ULL, 0x59741A65382D33D3ULL, 0xA072E39B278DED73ULL
        },
        {
            0x3E2D05EFE37A3935ULL, 0xE0438AF83BA258EDULL, 0xF30C57004F22F27FULL, 0xC4FCE93D4F51A1AAULL, 
            0xA60461ECBC6F14BFULL, 0xC0979E3713127191ULL, 0x77451A9E13C08730ULL, 0x54FA5D3FF27C5427ULL, 
            0xF73ECCD0DCD65705ULL, 0xAE141CCF06F097BAULL, 0x9BB1872810917A34ULL, 0x542C1EE0F1C596F5ULL, 
            0xD37D2FB4300ED81FULL, 0xC49FD5C01B570479ULL, 0x71FFD2F02839D7FAULL, 0x75901E39C55D3B40ULL, 
            0xF80FB54FEDBB7FF0ULL, 0x74063EE73AB1575EULL, 0xA5C1814890CB6B50ULL, 0x1DCEA5075806D219ULL, 
            0xABABF513D849E8DDULL, 0x5B375E48E2B661A6ULL, 0x90CEA9B1EE4C27A1ULL, 0x82317463DEFE759BULL, 
            0x73DE7501E056A0A0ULL, 0x98E36EFEB6AE0A53ULL, 0xE6DF2DC38508A0F8ULL, 0xFC9191DAED7235BFULL, 
            0xB1D5715072B16384ULL, 0x09606C482A010DDBULL, 0x5592ACC2E7AA20E7ULL, 0xD7600473C97F5D9CULL
        },
        {
            0x7B820140CF4F5339ULL, 0xF51DD7B1462A1897ULL, 0xA08E4DBBD6A86E4BULL, 0x676ECBDCA0647486ULL, 
            0x34D9B6386BCED4AEULL, 0x2A423BCD55847C65ULL, 0x58F1A67258D56738ULL, 0x11E15BD0B198EBABULL, 
            0x052CF388F5C17FC7ULL, 0xCB3B120E7A980BAEULL, 0x273406A537BBFE12ULL, 0xAB244E0B162B6209ULL, 
            0x84C4154782D4FE55ULL, 0x3FA981C740FA1178ULL, 0x9BA54698CB903C20ULL, 0x6D7A7296E2889AF0ULL, 
            0x4A2E0947BC2BC688ULL, 0x24FEB71C9E537C2BULL, 0x0FB0EA74F02EE40BULL, 0xCC3337B81395851EULL, 
            0x7305058B5D67356BULL, 0x23FC7D5584189735ULL, 0x6D3F72079140FA01ULL, 0x484EA5C3C0280A70ULL, 
            0x9B9D1B3CBB24E649ULL, 0x3129AC62CBBD6735ULL, 0xA136421271F30D6DULL, 0x6329083EE2C9E22FULL, 
            0xB69B5E2B9B9A689EULL, 0xA6C0B568BC8D19C8ULL, 0xB2AC43CE2A52CFA2ULL, 0x1285208D70632B84ULL
        },
        {
            0xB1283C79F6527121ULL, 0xE264C6394E322F7BULL, 0xD2B1257C9F4244EAULL, 0x273CEF2ABA28317AULL, 
            0x78A9E92E4924F15EULL, 0x1669FDCED345D7BBULL, 0x5D4B357C5349391FULL, 0xF4F89013B21B2E18ULL, 
            0x29F6F3060FD92A00ULL, 0x7C4631950989030EULL, 0xE42919A6BBD1AC78ULL, 0x5AA6E08F9EC10CA6ULL, 
            0xE20254370DA6FB1FULL, 0xDC00C8342FBAA538ULL, 0x2DA022B4BDD54EFEULL, 0x197104BE5F69061FULL, 
            0xEEABF3407D40A952ULL, 0x1F87F387D305DBD7ULL, 0xC48D147E7F08A8E3ULL, 0xBC9F472B10E89279ULL, 
            0xFE1AD4A1607D40F4ULL, 0x334267BDB15A5A11ULL, 0xD6DC2E84A4506BE6ULL, 0x1CADD82DBFC2B882ULL, 
            0x03D792C2EA13C19BULL, 0x9333A33C1BE4AEC0ULL, 0x2B624C8748178E5CULL, 0xD24DC0C85782B624ULL, 
            0x6276A3ADE5AAC153ULL, 0x0B0ED54F2DF7DD25ULL, 0xFBF1CB36F5C85B97ULL, 0xBDAFF580EBC8B28AULL
        },
        {
            0x7017C46374D3D6EEULL, 0x176D83FC304CDE69ULL, 0xC44F452B89320F0FULL, 0xCCAD3BC767F8D065ULL, 
            0x1CCDEF8492EAECE4ULL, 0x3D153D60E4EFBB13ULL, 0x44CF21C9AD441F1AULL, 0x1E1AA1C92A08EC87ULL, 
            0x87AF2D99DD632531ULL, 0xDF67B291C5057B13ULL, 0xFC0DCF78E1B2C9DDULL, 0x3926F0483CBEA623ULL, 
            0x65A2BF8C9AF5C93FULL, 0x8C5D77E10D0E9F1EULL, 0xBEF6266D9758B720ULL, 0x3560052348DE079BULL, 
            0x4A8425AC56A3040DULL, 0xA5BF4727D22DFB86ULL, 0x12EF489BC0E20C6AULL, 0xD859EC63A5CA7E31ULL, 
            0x5978275200D1AF0AULL, 0x414990FA02568D6AULL, 0xC2171A087D3FF1EDULL, 0x30CF78BCB013B8D8ULL, 
            0x0D304576AFC20344ULL, 0x3E4197FADB47E661ULL, 0xA17E07D94D96DFF1ULL, 0xC9EEF0E1D43E8544ULL, 
            0xE8E2E070CE6DAB40ULL, 0x44557873F9AD7AC6ULL, 0x632CBE490D0E78ECULL, 0xA2A85C70211F3C99ULL
        },
        {
            0x3AFF9EC0EB30E1B3ULL, 0x6F537F2C82017C0CULL, 0x97617647C4848093ULL, 0x85850C98546BFCFDULL, 
            0xB37001037727FF84ULL, 0x6DF307ACF09120B3ULL, 0x3DC1FB47ED64BC98ULL, 0xC93A1606A02B2BF2ULL, 
            0x8589C2A56160F27FULL, 0x7F7B1BB4D2FE4E64ULL, 0x9628AB12E6585672ULL, 0x6857005C567A45AEULL, 
            0x5B0E8E168F7E4887ULL, 0x69EBCE607E5ED3F9ULL, 0xBD8D42A24263FBDFULL, 0xEB78C690DFDEE00FULL, 
            0xDAEBAFD748C8E70EULL, 0x5465B1E8BCE30B50ULL, 0x15C39BF5976880A3ULL, 0x7E4BEEF372F6C557ULL, 
            0x732BBECA999043A3ULL, 0x4D4AB8123D179461ULL, 0x514FB9B914977E00ULL, 0xADFEE399C9B4221DULL, 
            0xF8ACB0006890EC4DULL, 0x0D751A1DE2273F8DULL, 0xAE160B13D4BCFCD6ULL, 0x6CB1AC0FAD955B17ULL, 
            0x0296D76A618AA45CULL, 0xE5C66656248C7221ULL, 0x1BBB08F823DEBDCFULL, 0x7DE9C9D4E52E9378ULL
        }
    },
    {
        {
            0xF0F5FF63D6A8433DULL, 0xFC55912090DC240EULL, 0x6D443A578AE7E7BEULL, 0x126001D7460B5359ULL, 
            0xF6C32C2F4031706DULL, 0x8DFA31BB71701556ULL, 0x8109D0BE3914148EULL, 0x17FAAFBA32AEFA68ULL, 
            0x77D1972E0F6BDE23ULL, 0xFFAD7F508F740057ULL, 0xB531E0D6DAC8A086ULL, 0x25A1B559D6971466ULL, 
            0xF8F50EB300CF20B1ULL, 0xC8A996E3A2D8B9FDULL, 0xF6C2A3A61503D0BCULL, 0xC1D47FD7F58849EBULL, 
            0x5E9556B7611B369BULL, 0x619F9AD7C7473FBBULL, 0x29F4EB0B17D9A13BULL, 0x787A742EB31D2EEAULL, 
            0x006E03F1403A23E2ULL, 0x079207091105F1E5ULL, 0x36B6225C56D9431DULL, 0xA7AC81EDE2A8B1A9ULL, 
            0x3F19B7F4C4134114ULL, 0xAE932E1088183966ULL, 0xCCCCE667BE8861FDULL, 0x3B459F13E8C6C330ULL, 
            0xBFB1C9547A2DF415ULL, 0x6470405E2C7DD37AULL, 0x5399B79766D14952ULL, 0x8EF0D2438D2C38DDULL
        },
        {
            0x0CDF38085D390DDEULL, 0x607C6B646A917FC9ULL, 0xAE94F7C7B3B14B7DULL, 0xE1EFDAD6A497D2AAULL, 
            0xD63C3C1B60316DD3ULL, 0x999E32DF6FCCC7A7ULL, 0x47E7E72FFC2F1694ULL, 0x63C84BFE878DF706ULL, 
            0x345D0C38D02732B6ULL, 0x4947C0C0458CFC6CULL, 0x2F2F5220595E77F0ULL, 0x00B36C2520B43D2BULL, 
            0xA12CF76D00444B6DULL, 0x99F067756D002CB5ULL, 0x8D42C8802C7F3950ULL, 0xFDE3F80860373311ULL, 
            0x72D8500B34F3A2E4ULL, 0x6B2E567AAE975E51ULL, 0xF95AB3F67514D68CULL, 0xB87BF5B3BC32CAC3ULL, 
            0x6822A8015385F99CULL, 0x65EC365E97AA1530ULL, 0x25655C960BF28831ULL, 0x38CFB1C777520885ULL, 
            0xC4369E247A8DF733ULL, 0x99EAB5DBCC82AF8DULL, 0x1961C2A6AE442B2DULL, 0xF8C395A00278C6F6ULL, 
            0xBB60A5207E7F1B76ULL, 0xCC6C1C87A2C79A37ULL, 0xB4F70647F5CB9C85ULL, 0xB59A2F235A64F3C4ULL
        },
        {
            0x33EA100B33186FA0ULL, 0xF5CBB8C3A2ACD640ULL, 0x3ECD4BB3E7BFCE26ULL, 0x3C948C6E0F8FBE2FULL, 
            0x75A7B84F766512C4ULL, 0x1BB58216FFEB790CULL, 0x6B4295676FD7E2D0ULL, 0x790799869CACF02CULL, 
            0x5AC93C1EF74A23FEULL, 0x386A1F5463A2ACEBULL, 0x7EAAD5C4D7079369ULL, 0x335960E0676B13A5ULL, 
            0x7FDC3CB3510C7B43ULL, 0xE199D96DBBE76209ULL, 0xB25E7E0A41C09DCAULL, 0xD5D0D29135D751BAULL, 
            0x37C0696FE94E6D63ULL, 0x2494DDFFF35DFAC0ULL, 0x871D6DABD4BD9E09ULL, 0x2694F6A9E0D51C52ULL, 
            0x442A0B708FCC0035ULL, 0xF8237CE8C5F2E49FULL, 0x37A2A309F7500B25ULL, 0x9E53CB68009DE9ADULL, 
            0x51081B6C4F74B35DULL, 0x60D33623E65963FDULL, 0x54D7EF2CA1B393C4ULL, 0xAE34ABBC2A9E1C95ULL, 
            0xFCB4764168500781ULL, 0x70927999DDFD1273ULL, 0x9C6F9122DEE1C91FULL, 0xC398AAE8E0FE3D80ULL
        },
        {
            0x4D7287355CD5FBD2ULL, 0x7241DAE39EAF0BD9ULL, 0x570B0B98448E24A2ULL, 0xB757D8EA84322A94ULL, 
            0xEF6CABDB0FF87027ULL, 0x4CDA195A0719EC4DULL, 0xA24DF987EA035287ULL, 0x680DE696A7F82830ULL, 
            0xFA28AB87D56D915FULL, 0x9C8E9A49600A944AULL, 0x04A58740FBFDD122ULL, 0x6022A2D74342CB00ULL, 
            0xACBCEF8A2B9CD272ULL, 0x9885210BBDAD0824ULL, 0xFCBAD226CD50A19CULL, 0x8DBB09F22A225D6CULL, 
            0x4A0B9B332556D2B5ULL, 0x2407CFE5C1D54A9BULL, 0xB558407CD9C3DCEAULL, 0x82B299600D3AE583ULL, 
            0xDA62104250822286ULL, 0x46EC75611102A35CULL, 0x6E734951F9366123ULL, 0xC533D829EF897C08ULL, 
            0x102B8A42846AD868ULL, 0x8266BB6D294B7A94ULL, 0x965A13E5BF3FEA51ULL, 0x084AB8A0E5952E8DULL, 
            0xA8F5448151D1FECCULL, 0xD42624A6B37102DCULL, 0x11A41F657A2FA6AAULL, 0x64ADBD3E618A0895ULL
        },
        {
            0x1578D1613F806879ULL, 0x43D6B57F703D0935ULL, 0x6F32A0A8FE8FBA01ULL, 0x4D335633E3EE4542ULL, 
            0xF1C7ECC6D9B57E9DULL, 0xBC2C5AC85B673109ULL, 0x17B078CD64D240E8ULL, 0xF41C25B9E1DF91A7ULL, 
            0x52F5933F8C179104ULL, 0x9EC60282809D2605ULL, 0x84C7A204D3FA5E8BULL, 0x0C2F9492A6A622D2ULL, 
            0x118A455F646B25DFULL, 0xB9ED754889FA8711ULL, 0x4809EEC5AB6237B2ULL, 0xDE62F566FA5DB95EULL, 
            0xB5D4E88860B1B3EAULL, 0x5C184547737AD1E3ULL, 0x546DF4312E22223BULL, 0x07C668B933DBF72FULL, 
            0x3516EB4A74B6EA72ULL, 0xAA1CD31CF0A1B3FDULL, 0xBBAEAF41AAA698CFULL, 0x767EF1019B5A97A9ULL, 
            0x40F4F75869B13D75ULL, 0xD0B7CE96301D77C1ULL, 0xF12597DD08EDB2D8ULL, 0xC78188B843C97F6FULL, 
            0x2D65B9104B2FFE66ULL, 0x266BDA708CA2CD65ULL, 0x7D01F73C86E3BE41ULL, 0xDDB46FB700165713ULL
        },
        {
            0x46BF71595DBE10B2ULL, 0x5954A5501DE87684ULL, 0xE323396231AEE5D7ULL, 0x2E804A18D881BB3BULL, 
            0x375C5267F6AC33D6ULL, 0x120CDD94FAF12C43ULL, 0x7EEBAAE486364897ULL, 0x6DF0B38D0BDB058FULL, 
            0x942F4D92F27468FDULL, 0x156A31E08A80BFAFULL, 0xFD7CA01706AC0988ULL, 0x813A5E6BBB52867CULL, 
            0x039E62F138FDEAA1ULL, 0x9A7683606C3F2279ULL, 0x9882B2114DAAE6C5ULL, 0xAA24390D54582A9FULL, 
            0xCEF6A62998397D9DULL, 0x5E837F56370E0636ULL, 0xC1CDD572073A749FULL, 0x661C14129BCF79D3ULL, 
            0x5285A240DDA318E2ULL, 0x7F7288EFCD844992ULL, 0xC12AF7B4C8E7938DULL, 0x2DBB7D3AFF7F9CE2ULL, 
            0xE8230C386A08BA63ULL, 0x298276498279F206ULL, 0x995F698758FCC09DULL, 0xCB57C8C88AD37876ULL, 
            0x60B891FFFDC11669ULL, 0x1C2EE86B52A658F5ULL, 0xA98572DB11FBF849ULL, 0x580AF6C1B85DF1EEULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mirfak::kKeyRotateAConstants = {
    0x23B4966FB2EDDBBEULL,
    0x9E155BA1699BE33DULL,
    0x9801F6B50FAC85FBULL,
    0x23B4966FB2EDDBBEULL,
    0x9E155BA1699BE33DULL,
    0x9801F6B50FAC85FBULL,
    0x94E65A51490DBAF0ULL,
    0x964EEA3D967F4082ULL,
    0x0C,
    0xD2,
    0xB5,
    0x04,
    0xAB,
    0x8F,
    0xC0,
    0x6A
};

const TwistDomainSaltSet TwistExpander_Mirfak::kKeyRotateBSalts = {
    {
        {
            0x6E37FA6DA0D95C00ULL, 0x779EC1DD05B69CFFULL, 0xE88B1060E935872BULL, 0x98F9D970361D7834ULL, 
            0x83B5C46CDE519A74ULL, 0x28EA23343B658E32ULL, 0x2B312C22D2CA5C89ULL, 0x42BC6515507B2B80ULL, 
            0x2A03D580C21F19ABULL, 0xB7DA8FAD13D1907EULL, 0x8819347AC1E1D744ULL, 0xD208447BD032E850ULL, 
            0x7EC5EABD87116591ULL, 0x9BCA90838A1DF3A0ULL, 0x256153B03C01CB27ULL, 0x7C40CF7DA606C232ULL, 
            0xEFBD1431334DA0BAULL, 0x98B2589F9B0FC5B3ULL, 0x900294B3FF36CD53ULL, 0xF933F859C2358BEEULL, 
            0x112B3AD1A164E4D2ULL, 0x88D3F9AABECB809CULL, 0x542E9D2C53CF41C3ULL, 0x111D77FD30F1392CULL, 
            0xC1DCE0F722EA714FULL, 0xD8053ADAA69BF17CULL, 0x4828FE7DD82C221FULL, 0x5F6885A1A069EFF8ULL, 
            0x9C274353E08DF849ULL, 0x4478915DA5478F5AULL, 0x2B20F86DF036328BULL, 0x0A23DA0FD9BB0DECULL
        },
        {
            0xD726568856318B55ULL, 0x8775DCBF425CA1D5ULL, 0x238CF2890AA16D40ULL, 0x66631C6EC6243A40ULL, 
            0x77EA596EA7FD163FULL, 0x78DD48F0A39764E1ULL, 0x0170481E9990A972ULL, 0xD3B8165BF0A415E6ULL, 
            0x944B984102570ED0ULL, 0xF17F830492F67238ULL, 0xAC40FB853148E1C9ULL, 0xFFA0D7D520D312D0ULL, 
            0x8F360EF7C4AE54E3ULL, 0x8F97C461D4D963F0ULL, 0x6F74ABA378A773A5ULL, 0xE423128D37863FA9ULL, 
            0x267B6629A93B5301ULL, 0x0AC15200C8A8C17FULL, 0xA70E1D9AADA87DF7ULL, 0x3CCB88AD6DF7706FULL, 
            0xE34B3E3C8CF401F1ULL, 0xF18F7FEE0CDE8D71ULL, 0xE8D806CC988C62EEULL, 0x791B59773E8F40F7ULL, 
            0x02A90CD2D8764FDEULL, 0x93956492436DE9E5ULL, 0xDEF01F37B902E0C1ULL, 0x297DE57E5D3648FBULL, 
            0xABFD5DFBF0450773ULL, 0x80EE7B6B777D507BULL, 0xA977F20279D04E3AULL, 0x566C1BC3341F2085ULL
        },
        {
            0xF0D528F410F9850AULL, 0xADF5706ECEB2EA08ULL, 0xCA709DF58EC90FC5ULL, 0x1627FAAE0766990AULL, 
            0xA0A89E96C4AAD329ULL, 0x2E4DCFB50D7C8EB3ULL, 0xE9564404595FED01ULL, 0xD936CB7386933B12ULL, 
            0x868E74EBA63BF6B5ULL, 0x03E46E9306166449ULL, 0xDA384EA00EED3D05ULL, 0xDB6581F937F2ED84ULL, 
            0x03037BB68BEF6F41ULL, 0x181C47C2A3106941ULL, 0xE00EFE66B548EA35ULL, 0xC1D90B35B4F39E65ULL, 
            0x2A0917BC03580FA0ULL, 0xA1AA917252B0165DULL, 0xCC5702D77D064AEAULL, 0x44E036F95BC388AFULL, 
            0x308818CE26804FB1ULL, 0x834182687BBBEB5BULL, 0x0644FDED96AF7681ULL, 0xC316E884E9F04357ULL, 
            0x1109CD19088BB956ULL, 0xA96DA7935C3C1794ULL, 0x482777BB937D78DBULL, 0xA4DA1DC1532755BFULL, 
            0x6B819E09D115786DULL, 0xEBE327534A1BAF9FULL, 0xDA6F12518E053137ULL, 0xFD020F06379E1D64ULL
        },
        {
            0x941A10491CA0CCF8ULL, 0x0736BD113FD66B0AULL, 0x9D012ADC3C07D0BDULL, 0xD000C3251A64D2E1ULL, 
            0x9DCE44082E5897EEULL, 0xE017EE7BE3407A5EULL, 0xB45360BD8D1D2022ULL, 0x58A77E8201E5A8B5ULL, 
            0xBAF90D1575C2237AULL, 0xD4763A5C66E6AFCAULL, 0xB3CB6D9B3F4D404FULL, 0xB6CBEABADA6321DEULL, 
            0x0EEDD26A6197CD0CULL, 0xC25805C3DA47CEB2ULL, 0xFB7E388369B5F6AFULL, 0xDEF0B5F8EDC35142ULL, 
            0x5A1325149F9211DCULL, 0xC581E99D2619F688ULL, 0xC28D8073D3BD971BULL, 0x2FD1E37C260363B1ULL, 
            0x692164AF9B67820BULL, 0xB9A2EA8268CC24D6ULL, 0x8CBCA4A2CF8764C1ULL, 0x2CF2E32CC43A5C4FULL, 
            0x0FE984BEFF442404ULL, 0xEDC22E12A2BAAFF0ULL, 0x0EBD97E7DDA23203ULL, 0xD5E4CCD7D91F00F0ULL, 
            0x204D8B10849D19BBULL, 0xD493E8B4D17600C4ULL, 0x5A49E9D5B3BA8C42ULL, 0xA01C9B8DE17DED6BULL
        },
        {
            0xC8CA1718B24839A2ULL, 0x8282A91BDA5E8A54ULL, 0x89E55D9095C7793CULL, 0x73E408D5F4582EFCULL, 
            0xCDC3BE00F7B2AD17ULL, 0x7A3D6F053787B83FULL, 0x1B649365F3C50CD0ULL, 0xB9D4C68B7E05484CULL, 
            0x45FC6597CFF4B27FULL, 0xA8D58D41ECAEF8AAULL, 0xE3363EF5DEC20578ULL, 0x67493CBAC56E6070ULL, 
            0xE1959432C3FDE2C0ULL, 0xD757667891D0C80EULL, 0xC12B8C20043B3B3EULL, 0xC202BC734184FBF8ULL, 
            0x4DE38BCEBAC9636FULL, 0xBA888CB399E37115ULL, 0x3C36FAF85A93EF29ULL, 0x76CECA84196BEAADULL, 
            0x9C32FFADFBB64197ULL, 0x2E7302291F786340ULL, 0xA72845C9A4E76CE3ULL, 0x174A50D5ECECC982ULL, 
            0x269CFB94C2A6BCE1ULL, 0xC436A4BC3D50D505ULL, 0xAF91EEA394A8B6D2ULL, 0x43CE5F2B77D80349ULL, 
            0xC2B9FF01C7499FE8ULL, 0xEF87707123327771ULL, 0x1B1C4FDA28C9D374ULL, 0xBE5F3602F601D21FULL
        },
        {
            0xEA8E188F97B07A97ULL, 0xBFC91A74A22CCACCULL, 0xD2C5CD9FA75263B6ULL, 0xBEFE90715C84EE1CULL, 
            0x0B4AFC58ADE5BC8DULL, 0x256ECC748817BAA4ULL, 0x7807A06035E520FEULL, 0xDB48ABCAC7062D04ULL, 
            0xE5FD8491FEB35122ULL, 0x32B2A6CC38AB6463ULL, 0x131EFFAA0AEF60F7ULL, 0x6682FE4E177A31A4ULL, 
            0xF24C809B020E45CBULL, 0xCC8674C7CBF417F6ULL, 0xC0030FD966569D8AULL, 0xAB591BA198D3B2B3ULL, 
            0xF9CE98FE5D8B3132ULL, 0x7B61501AF01E1F59ULL, 0x6A0A6B649F583073ULL, 0xBC6D814953D032FDULL, 
            0x275E0776B0B5BD9CULL, 0x31133700FE095E1DULL, 0x03B73ED05A233C9EULL, 0x9F8763E860BB2E9FULL, 
            0x58C7DDFEC95BC5FDULL, 0xF3E6B48A7391CAECULL, 0x2646DCCB94EB07F4ULL, 0x38A7402321C397C1ULL, 
            0x564F1E2F7B0B73BFULL, 0xDAA0178BD0EC99B0ULL, 0x707C0C52094D4A52ULL, 0x221D8EEE4228BC61ULL
        }
    },
    {
        {
            0xEA522769A51AF33CULL, 0xE7D1982EB7DCEAEEULL, 0xCC6A3294CA89CE88ULL, 0xCB9676148DF710B8ULL, 
            0x7C0EDFA779D6EAAEULL, 0x2059D2A8EBF86AA5ULL, 0x113F49592C760D16ULL, 0xA75606EE464896A9ULL, 
            0xD9307F2466DC8D0EULL, 0x2CAF93607F2889ECULL, 0xC7670600F3387EF9ULL, 0x31AC0DAABBA70D8BULL, 
            0x8725FFC9E497A021ULL, 0x789F264466DCC95BULL, 0x2B77A71A6C5092ECULL, 0xA93BB3CDA7B5F896ULL, 
            0x5C2EEF469563BFC3ULL, 0x6198D1B2B6E4BA20ULL, 0xB02858F06E390C89ULL, 0x74FC7ACC9C43FD5CULL, 
            0x184260D161221A24ULL, 0x1CE8489F87AEC52BULL, 0xCAF6A6DDD4892F8EULL, 0xCD59016FFC7D369DULL, 
            0x7777EBA0E2951DCCULL, 0x74E03A9EF63E8E35ULL, 0x3F08C4E2487C583DULL, 0xFDDD8C0C394D1B2DULL, 
            0xFFED29B7973C80F3ULL, 0x8927061DFF1DE359ULL, 0xDEA6536EC252FB80ULL, 0x15404796B264470AULL
        },
        {
            0x6F2BD46178744E32ULL, 0x413A867E49B48DF4ULL, 0xBCF2F634321E0090ULL, 0x5410FB63FA15EE60ULL, 
            0xB1E47BA4BAC81A56ULL, 0x2B3F598A5311CD0BULL, 0x365EC48594DB5821ULL, 0x78D00BDE9754E3E9ULL, 
            0xDACD27B171E98E82ULL, 0x6569E460E20E65B4ULL, 0x970AC2FB56E8E42CULL, 0x51FD998AA8E1D047ULL, 
            0xE07CD66823ACAB92ULL, 0x063B57728D501EEDULL, 0xDFE494AE71B93ECAULL, 0xFAE453AAA321B537ULL, 
            0xE290E595EBE9DE28ULL, 0xFCF3699AA37330A0ULL, 0x7DFE5141250F64A9ULL, 0xE2E0E59F05E2840BULL, 
            0x070B52D529F00880ULL, 0x022FB15D51B650E7ULL, 0xB1B8E53EFA84059AULL, 0x1A29C1C78AAA92BCULL, 
            0x19B3D841182DD611ULL, 0x0D978EEC54A7CE48ULL, 0x5CA5888392811034ULL, 0x2CD75B6C27A61DCFULL, 
            0x75CBEF73A063B9FAULL, 0x402F4CAFD12D259BULL, 0x9F211C3F10F88141ULL, 0x130FBC665500E7DBULL
        },
        {
            0x65C0B8389E63B319ULL, 0x14E6B0A1062FF3C1ULL, 0xCE5E82FD60C75756ULL, 0x07588DE48835C7C6ULL, 
            0xD71D7CF7BF507221ULL, 0x9AC075DF463DDE42ULL, 0xEBB8990BF9B97ADCULL, 0xB7353648E96C7E39ULL, 
            0xF587EF052C5E2F2DULL, 0x436FB8E4EB99BFC7ULL, 0x586B997979AF2209ULL, 0x810ABF243A1CA531ULL, 
            0x0A13603A3DDC53E9ULL, 0x5521F4E34CE55DA4ULL, 0x2AFE57FB20489EEEULL, 0x88CC99C5D10A4E06ULL, 
            0xB4E5B3706C2E3AD5ULL, 0x26D78762C7AF92D6ULL, 0x7BF7C0E28141E490ULL, 0xE26CE2B3545B6D4EULL, 
            0xA0E3C77E3B6BA853ULL, 0x4EB583E3467BA2B8ULL, 0x1408DEE6880A0D28ULL, 0x457F61E6041C989AULL, 
            0xCF5E4298D582B222ULL, 0x7EC9BEA5A956DD50ULL, 0x28AB11736AF5C65EULL, 0x699DB01640759461ULL, 
            0x17D7C1C9166DD0F4ULL, 0x02AF38C861DC2DB3ULL, 0xDD33A12718102D27ULL, 0xD0BF43F1A9359847ULL
        },
        {
            0xA3C6488079C28B21ULL, 0x3FB81E5D0C7C4683ULL, 0x9CA2760C4D1E7E95ULL, 0xDDEF9AA52B2EF305ULL, 
            0x8A0D59B78A1441DAULL, 0x43A939E417983316ULL, 0x049D3DF0D204452CULL, 0x7CF3F243E742207FULL, 
            0xFBDF5DED425C0542ULL, 0x539E233E424AB1E6ULL, 0x9F33B9BCC144DB22ULL, 0xFBDA47943CA600E4ULL, 
            0x93FDC6705EBC0315ULL, 0xED158EB7A6ACCE42ULL, 0x74465189709F8300ULL, 0x8DCC435DAA66DBECULL, 
            0xE2537B15B8428B38ULL, 0x8FCD70D16275CD01ULL, 0x8F457C1002E7224EULL, 0xAF8002F7BD484E83ULL, 
            0x89025705DD9D2C8CULL, 0x8DF6196F15B44E59ULL, 0xCA1C6DA1FE4FB20BULL, 0x65A97FD57F4E5AC5ULL, 
            0xFCF26F2F5EC4F007ULL, 0x994BFB7F3F7AD5F9ULL, 0x71811129E6C7DF85ULL, 0x97B268F82C01ED9CULL, 
            0x348D45CA51EEEFC9ULL, 0x1110392A5F95069EULL, 0xC399B6228F2EC813ULL, 0xF356E592E7A93D42ULL
        },
        {
            0xAC83A565D2B19930ULL, 0x8C32BB2C6C07E700ULL, 0x316B33D6DEC64A22ULL, 0x80598EE867EE7899ULL, 
            0xA95782CE970D1374ULL, 0x0605B3E05074834EULL, 0xF60AD7841AAFD6BFULL, 0x10210536C1A9C858ULL, 
            0x56DE146AF6102A7CULL, 0xACE5B07552E1E16EULL, 0xECEF7FDB4D676F8AULL, 0x99890C65DA4B8F20ULL, 
            0xC05B993759D062D7ULL, 0x9FD62EA244F4F00CULL, 0x1D2CCBC748D8050EULL, 0xA9297BD9390B487DULL, 
            0x989AD51D0153501EULL, 0x805834C74D3D19E4ULL, 0x81726BF4B5600E59ULL, 0xA157BED052997079ULL, 
            0x88DB97E4ED7A74C2ULL, 0x2B954F834C4B3F0CULL, 0x90239B7A66CEC40AULL, 0x90DD452C23591A1DULL, 
            0xA7D1C5500FB30E14ULL, 0xA30F05C422555FC4ULL, 0x31DEAB4E04B891D0ULL, 0x73F7B2E6536230F8ULL, 
            0xF57D0609B1CFA8ACULL, 0xEF25483FF82681D4ULL, 0x8B9CD2B1DC96A925ULL, 0xF31EB46826B51937ULL
        },
        {
            0x7DCC1CFCFB0F2127ULL, 0xC043D8C48DFEF2CAULL, 0x8EC2F6C2C67D1EA7ULL, 0xEB2E1B49609B38F2ULL, 
            0xB603D78E636B9D7EULL, 0x515CD20AE53BE30EULL, 0x193A5D45A7546B66ULL, 0x07454FD08BE4C88EULL, 
            0xAC5AEA87633A8887ULL, 0x902287880AF5610CULL, 0x77444C8878DAA86CULL, 0x73E0C74B742D3BA7ULL, 
            0xA09EBFE01C5F6188ULL, 0x1C88DA61931FC04BULL, 0xB220FED772DE65DDULL, 0x2AFEDA42DEF28476ULL, 
            0x4C85FE14844819E3ULL, 0x70E17DB3CEFB5F95ULL, 0x9728CD15BF383D52ULL, 0xB5F2CD4301D6C46AULL, 
            0x46FAE50BC6EC2179ULL, 0xD253A4358BD9BA4EULL, 0x21F6724534163467ULL, 0xCC929DE37C36BC3DULL, 
            0xC360BD2E894F1012ULL, 0x5F4D3F4DE490034CULL, 0x7E3A96AD30B3F30AULL, 0x52A936D26AFBA2D5ULL, 
            0xF6323A4244BAF257ULL, 0x312BCC58875C7FA1ULL, 0x88CA1E996E7ED52AULL, 0xA749AB060B186146ULL
        }
    },
    {
        {
            0x95A3F58ECF16D6AEULL, 0x87C80C34A1B69C39ULL, 0xA26E8F0E1BCC3BC1ULL, 0x7AF9EA7950456B1EULL, 
            0xB296ED35EBC5C566ULL, 0x4214EFA62EF61A39ULL, 0xB66232294B23C891ULL, 0x32F444B115414A36ULL, 
            0x7F6BD70FC39675F7ULL, 0xC398163BD3A66D40ULL, 0x1BB7574131696F29ULL, 0xC41CF96D184FC423ULL, 
            0xB328068221236ABDULL, 0x3E7EF3E472884FFDULL, 0x62D66FEFAF54C511ULL, 0xC205E61F006986D7ULL, 
            0xADDBC24BEB96211EULL, 0x1754C207DD7D811CULL, 0x456458AF501AD4BDULL, 0xE46F082AC672AEF3ULL, 
            0x44F000CB46CF449EULL, 0x99C87DC7398B610CULL, 0x6DC3DDBF8E972EEAULL, 0x8728A9A4655788E1ULL, 
            0x02DBFFCB88DE51BFULL, 0x8FEC8F78C375FAA9ULL, 0x56F51461CBE19DE9ULL, 0xA3E9CFE423774FDDULL, 
            0xC1E55B0F755B791FULL, 0x470D841C3FB02B72ULL, 0x9D9948615D2E4783ULL, 0x2FAAD48D6EE7DD7BULL
        },
        {
            0xF2C641EEED63D178ULL, 0x24CF148ABBC9BF22ULL, 0xF78605F5D91CC115ULL, 0xA24B0AAD2609020EULL, 
            0xCD4199775BA6702AULL, 0x9D9FB2A745A8CA2DULL, 0x965E44159E8FB913ULL, 0xC4C31D67E310A817ULL, 
            0x44012524795AD810ULL, 0x0D0643089F543102ULL, 0x750BF7CC42DAE593ULL, 0xD9E05E2AEA70A51FULL, 
            0xEC97DA955DF517F1ULL, 0xDF428EE9B2593135ULL, 0x6FA4A00BCB9B0A34ULL, 0xC437E8BF35D4E354ULL, 
            0xA85634917C2FB6B2ULL, 0x7F9205A7BF11D9D1ULL, 0xFDCE63A75919FC46ULL, 0xE7DEAE43A8558E4FULL, 
            0x7BBE9E1323869C9BULL, 0xC63658CF75B8DCD6ULL, 0x576FA1AAA169032DULL, 0x63B94A8839171217ULL, 
            0x381237CE8815E981ULL, 0x986F0AAE0D5CAE35ULL, 0x8D315CA09E2F91A2ULL, 0xC29C665CFF1A5FC2ULL, 
            0xB577C758662DCA6AULL, 0xBA76AF2338224E60ULL, 0xB5A9DD3AEF9B320CULL, 0x47113891E8056650ULL
        },
        {
            0xB8EAC9570DB126FAULL, 0x2D18592A4D9528EFULL, 0x8BF11FAF2F63D454ULL, 0xC3407964987EABABULL, 
            0xF6CC40053CD169B3ULL, 0xA52714E7D1560D79ULL, 0xBBC8F0F896A8244FULL, 0x6E3DAF7ADC78AA0DULL, 
            0xBC6E210D1EC16B6AULL, 0xB91D430415F36C54ULL, 0x784259502BF5F2E0ULL, 0xB3F44E094DA470D5ULL, 
            0x8D7539EEB68AF8FCULL, 0x1B22363020327BB6ULL, 0xC415B35D44381380ULL, 0xAF4478F5B24E0BDCULL, 
            0xA808F3BAF2049FCBULL, 0x30843B712385A27AULL, 0x25386496DD5E375BULL, 0xDDDDB357AFF6E14AULL, 
            0x59BD2806EFE3F471ULL, 0x6132570B996A3573ULL, 0x5DB64A2D684DCE4AULL, 0xA4DB6C0CA83D2010ULL, 
            0x9AD9FDCED429B5C0ULL, 0x3F8FA2642ADBBF83ULL, 0x06DCFA1FE966DF09ULL, 0xB8AAF1359193BD7EULL, 
            0xD78A5C380BD1A457ULL, 0x24E1131A18376783ULL, 0x07749675043C9D23ULL, 0x0425F3C1B7FCBC4FULL
        },
        {
            0x463DF75C45D3EEDCULL, 0x16427D13E056971EULL, 0xD293255E089B8BF4ULL, 0x166C9AD230ADA230ULL, 
            0x9508FF5E5AEE66D5ULL, 0x5AACAA9E485B5B2BULL, 0x1498F3CC8F26A11EULL, 0x04B83FDB6C97FC4EULL, 
            0x239460484DD37211ULL, 0x7D77C548D70E34B0ULL, 0x3766B520FA69A01EULL, 0xBDC98D81835D9B68ULL, 
            0x6141669EE9E5C848ULL, 0x335E638929FF812BULL, 0x9ADB788A818C7F5FULL, 0xDF9C2EAADD5C2DA0ULL, 
            0xCC18634444B30FCDULL, 0x7748806B2DA7FB3EULL, 0x657A59EF99AB9A9EULL, 0xC37FCB28FA888795ULL, 
            0xF7D2D6F3D886AFA2ULL, 0x7A4C5DB93BCA26EEULL, 0x6778BF1CE7550EFEULL, 0xD04B1704161C29CDULL, 
            0x096D1424A7709E94ULL, 0x2274E04221A8246DULL, 0x74309BFC7900D020ULL, 0xA5A25C5BCC4033CCULL, 
            0xE1A68794A5005DF0ULL, 0x2E1F055436FFFB61ULL, 0xEBB2EF78129D8F2FULL, 0x353F7AE9FA058FBBULL
        },
        {
            0x05C0C76CEC3E62BBULL, 0x0136F278349A0B06ULL, 0x5A594DB0E58EAF56ULL, 0x9C3513FD621C06A1ULL, 
            0xA181D2F2E4F80399ULL, 0x58880CBC252B9318ULL, 0x85ABEB47D4321FC3ULL, 0x5BBDA039E45EF618ULL, 
            0x5C0D03DBF527463CULL, 0x565915DC2DC3F6B5ULL, 0xE7D9B1ED7DE7F175ULL, 0xF97A7A0692D3732FULL, 
            0x6CB47DF06135D9FFULL, 0x754B1D29C13AC2ECULL, 0x7E8F79C9A640CB6DULL, 0xB7C32A37D7454C6AULL, 
            0xCDC77DF745ECE840ULL, 0xF9976BE979247049ULL, 0x452888F6F67AA83AULL, 0x4EADF8A874767E35ULL, 
            0x3986B9C59022AF7FULL, 0xBD9930AEB6E1CE92ULL, 0xAB332AFF1BDFA11CULL, 0x9E30C62E23ADBCA2ULL, 
            0xD94CDD3AF8FF8126ULL, 0x6DF112CB7020FB41ULL, 0xBC15A4D6E4DFA395ULL, 0x18386CB59CFE8E93ULL, 
            0x10794B632CB978FEULL, 0xBE16276F9516CF8AULL, 0x79A7E03E1FA08322ULL, 0xEB1FEB338275E6C8ULL
        },
        {
            0xA769AA5AA70AD544ULL, 0x2F5DC51FBC339D8EULL, 0x7740A179370493E2ULL, 0xC18612E5B43604ACULL, 
            0x149E548A39C3B7DFULL, 0x9CCC0F055AF4ACD0ULL, 0x509928F9C0F5F0D2ULL, 0xD8679DA4AA47FC87ULL, 
            0x78796D752F825700ULL, 0x9A6D3438CB98FA5DULL, 0x1CDE63F3577333E8ULL, 0x15522CB952829E75ULL, 
            0xC7D4C6477E7B4229ULL, 0x73849FC29311B934ULL, 0xA6879C3DA47464CEULL, 0xD197EAF0C82F85D4ULL, 
            0xCDE8242DE6B7AE92ULL, 0x3BA3DE9ABEFEF17DULL, 0x53A8D5824CA7F549ULL, 0x84E60DA58B4BF9C0ULL, 
            0x01D3CD52D5262B98ULL, 0xDB7D0A5FC3D7C4FEULL, 0xB60175DB346B4F42ULL, 0xCD7F3B4153C729C1ULL, 
            0x2D59D41509ADEC55ULL, 0xDA47F876BB67CED4ULL, 0x3EE3F8C158B77E20ULL, 0x512F48FBEDA387A1ULL, 
            0xCA28264AE3DE92E3ULL, 0xF6B5529E75302859ULL, 0x8510708D1E38B2E0ULL, 0x2BE3C2F9D89DA8A3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mirfak::kKeyRotateBConstants = {
    0xC206B6E55F71D327ULL,
    0x94699624CA6C5774ULL,
    0xEA44B489EA933F2AULL,
    0xC206B6E55F71D327ULL,
    0x94699624CA6C5774ULL,
    0xEA44B489EA933F2AULL,
    0x5F95A4926272381DULL,
    0xC7244F9550F3CF7CULL,
    0x60,
    0xF6,
    0x71,
    0xC6,
    0xC0,
    0x27,
    0x72,
    0x46
};

const TwistDomainSaltSet TwistExpander_Mirfak::kKeySpawnASalts = {
    {
        {
            0xE4FEDDBAF30A4E51ULL, 0x5735B02681C612C5ULL, 0x58914553FFB11359ULL, 0x2B37A51465BFF401ULL, 
            0x62E11F837BC95AC7ULL, 0x3FC6312D390FE1B9ULL, 0xCA8DBF095A3FE35BULL, 0xF79786993B1A05D7ULL, 
            0xAAA1DEE9CD86C297ULL, 0x3EFC6B8487D4C9E4ULL, 0xADAABFC5071D8C9AULL, 0x8AE5820DA72BF375ULL, 
            0x91A1B7BD24BBB253ULL, 0xD3092358C038A9E9ULL, 0x26BE007E198A1115ULL, 0xDE7C53520E958453ULL, 
            0x91E25C92BAF8C249ULL, 0xE29D3A2DC4754B49ULL, 0x78B195560B275942ULL, 0xF5D9626AA5E1FC52ULL, 
            0x3CF717333EC4B69FULL, 0xE9B24365D3CE2CB4ULL, 0x0506D6DB67E02D57ULL, 0x7B90D4F6C5FA3DFDULL, 
            0x05639EDBC5BE0F2CULL, 0x4E425251D43AD10AULL, 0x9ABF387CFB0C6E42ULL, 0x5B27538EBF924C83ULL, 
            0x106ECC15CAB8CB6AULL, 0xFADEA5F9CEBD3E38ULL, 0x18AC8AE08B6B060BULL, 0xB7380ABB456357C5ULL
        },
        {
            0x298A0933C28D7ED9ULL, 0x0A9F3BBD52EB2C1AULL, 0x554D054CA9C9C7FDULL, 0x3D9597FEB15C25BBULL, 
            0x58D8C4F84E1D4B25ULL, 0x9D0F820D4A57BF8BULL, 0x9EDB68DBC190AFA3ULL, 0x5D10F4325717FCAEULL, 
            0x9FF412D687291E12ULL, 0xF797F77474F79AF7ULL, 0x48CA9178FCE2A26AULL, 0x22E31DFD9D4C9753ULL, 
            0x200FE99EAAB5F5FCULL, 0x5E04E6006E35329CULL, 0x036668FB21EC860FULL, 0x78ADEA61A2973E81ULL, 
            0xC8A12BCE3D8164A4ULL, 0xBD124FD15E0EBB93ULL, 0xE56B456167DF993FULL, 0x80384EDA928C36F7ULL, 
            0x4BC1B614538AE24DULL, 0x0728E940766C60CCULL, 0x0A35A69C19F05900ULL, 0x7CAAEC62863669EDULL, 
            0xF6DA3717F9EFBFC7ULL, 0xF40511836E5C08EAULL, 0xBFC03368BF638921ULL, 0x925D957D4980C4A9ULL, 
            0xE8FE6DEB2A040B3AULL, 0xEB87431CAF3CEFEBULL, 0x7C2EDC61A778BC47ULL, 0x039DA9D62160A1DCULL
        },
        {
            0x746D69B3B19186B7ULL, 0xB2FE66940BB9B930ULL, 0xE9201E473F1A042CULL, 0xF537219871A45A98ULL, 
            0xCF21DF068E412F9DULL, 0xBF8739174F606609ULL, 0x40AFC8C64269B781ULL, 0xF4AF60AE3C2D94BAULL, 
            0x384429CBFF9CFACCULL, 0xB9A31935147B068DULL, 0x1088A65C0C947D8CULL, 0xFA68E3F9EFD44265ULL, 
            0xD3ECAF9C13790E73ULL, 0x53F8BD53ED31DBD6ULL, 0x12654004BB9C6B07ULL, 0xED2ABB77216B07EDULL, 
            0x0556482E110849B2ULL, 0x4A152AF2D0A3CCB0ULL, 0xE189B65949724C01ULL, 0x5276534C5BDA6585ULL, 
            0xA0D04A65403CBAABULL, 0xA7B07D155A134674ULL, 0xFD762045F22B7998ULL, 0x8BFB2A1B9A27F166ULL, 
            0x1D287411931DB3C4ULL, 0x5876677A3B194983ULL, 0xF747B5086A69F30AULL, 0xA81F9AF6B3F62D60ULL, 
            0x5CF542A44462D84EULL, 0xF18F5C1F0A4B2FF0ULL, 0x61E5810B927E7F2AULL, 0xAF1D23B790935484ULL
        },
        {
            0xAA819D6CBC634CA4ULL, 0x537A3AA142C736E2ULL, 0x4FF0C8108A0A454AULL, 0xA278B915F7947831ULL, 
            0x8FBB15B47BCBD9A8ULL, 0xF45906BE92329780ULL, 0x5C904D460C87FA29ULL, 0x0B3202FEAC4D9442ULL, 
            0x9230E1C2FCDF7FABULL, 0xA3B2A240F32E4495ULL, 0x393C47BBDFC8B473ULL, 0x03DA73E0F9F2251AULL, 
            0x073AF8EAF9E41A0FULL, 0x47AEB1E184CD4745ULL, 0x5BD6811CC5A98582ULL, 0x078BCF909552F497ULL, 
            0xB0F2DEB7E48C2C45ULL, 0x25F04CE9E890AD08ULL, 0x0EA15C14BCE2D118ULL, 0x394B12D4B9C47312ULL, 
            0x35C4138D90BAEF9EULL, 0xB1FADCE2513DDEC3ULL, 0x7EA34E3C8F971511ULL, 0x9DCA996AD2ED1B5FULL, 
            0x7264CB84435B398AULL, 0x115E9D4ECEE09B68ULL, 0x630D0DDE66DDCF7AULL, 0xCFAD8A2F47FF8282ULL, 
            0x7A89A4DF279E78EBULL, 0x96E673B97FAE2429ULL, 0xCC53CF456B8868E5ULL, 0xDF083BA6A679C811ULL
        },
        {
            0x8B304416C2188455ULL, 0xB3A176C7A63A8929ULL, 0xE7F5C54B86505760ULL, 0x8400F498F426599EULL, 
            0x9826A073E25BEBECULL, 0x9DC662CC8FC3C354ULL, 0x05638EA0E4E9D365ULL, 0x1267245460F9EEE6ULL, 
            0x737367B5F7896315ULL, 0x8F9859E5D7616834ULL, 0xD84011E563EF4365ULL, 0x2D6BE37447DF1118ULL, 
            0xCF5F424AEC03DE1AULL, 0xE98D906E00EE7019ULL, 0xB9D4C9BD7ACC667EULL, 0x10368E16DD61AFEDULL, 
            0xA4A6437EE35953FFULL, 0x483F4E207287216AULL, 0x1849626FAC413851ULL, 0x47760FB1D2E534DDULL, 
            0x39E994CD25EBB9EAULL, 0x4A9BD833DDCFFCD5ULL, 0x3B158CE5EB8FA079ULL, 0x131BC96A308979F6ULL, 
            0xCEAA3824FB4B4821ULL, 0x1BEA5E3DD8DAB980ULL, 0xBA96C90BF93D638FULL, 0x01B4B276313F39D5ULL, 
            0x5F60E2E447A4A80EULL, 0x5643FC83A0FB61EFULL, 0x435F77C6B839281AULL, 0x2EF0BDA0A197AB00ULL
        },
        {
            0x3C499F59B5F036C1ULL, 0x00AF9F5AEBE86289ULL, 0x9236B475D054503BULL, 0x130428C25FD8D492ULL, 
            0x427E69810212AA1BULL, 0x522DAFB8E618DD53ULL, 0xB8CA2E25A444C1CAULL, 0x9D18E22151D0370BULL, 
            0x9E2ECAA2A31496B3ULL, 0x5A2BFAEB0B8DD392ULL, 0x64B773204CC67930ULL, 0xE377E7F84CAE0C85ULL, 
            0x04CA7BA95BB8672CULL, 0x4E0AEC31CABA51E5ULL, 0x1BA17CA629D58043ULL, 0xAA47C0E0BAE2C7F3ULL, 
            0x9A8B2488327479A7ULL, 0xE2FCCD8851970430ULL, 0x338E014BE27EDC42ULL, 0x832B313B03396E34ULL, 
            0x96ECE2F4069EB506ULL, 0x5DB3AA53CDACEAA0ULL, 0x00544AFB480248AFULL, 0x86FA7E7BB14F00BAULL, 
            0xD21570051F598507ULL, 0x6AEEAAA98D5B0799ULL, 0x9AC6ADADFC044D99ULL, 0x94EA6FEE50194315ULL, 
            0xF9ABDFBEEE39A7D2ULL, 0x3B37ABF6A3330CB1ULL, 0x0DF183E74A686DE9ULL, 0x8A74BB45AE20BCAEULL
        }
    },
    {
        {
            0x8B9C19C315A875EBULL, 0x30D80AF801DB01D5ULL, 0x6437F07AD7DFC30EULL, 0x0E612B817285D178ULL, 
            0x6E0A96917EE2BDF9ULL, 0x495CC246F27FC954ULL, 0x5EF34D15E24839E3ULL, 0xBBD16C1B3E1A8AE7ULL, 
            0x1FD83F45053E16DEULL, 0x037F2D244285D78AULL, 0x2B642324B452B6DDULL, 0x7F93C47144B188C4ULL, 
            0x463C0D22EB1DC1F9ULL, 0xE4D54528BD5943B3ULL, 0xD0AFB1AC85E1F349ULL, 0x4B138CC13EC7FBA3ULL, 
            0x088610E0A4207FD4ULL, 0xBDCC8D8810610FCFULL, 0xB9EA3A526A351999ULL, 0xB7297C68F782FE95ULL, 
            0x2088350DC8204E82ULL, 0x07C2CBE1FACE1136ULL, 0x74C8C815E4B2083FULL, 0xB1F63FFCB2C0D655ULL, 
            0x246263C6CB9BB912ULL, 0xFD7B0FC96FC0368CULL, 0x04796E00903AD18AULL, 0x48FE3F3DCCE0B130ULL, 
            0xBE82E9ABD21AA8D5ULL, 0x29C7B3D8396E9CB5ULL, 0x24DFBD43B9268813ULL, 0xF1FCFB43E0BF0D14ULL
        },
        {
            0xDF7C4F0C2E2A63D9ULL, 0x2EAA55073F00F407ULL, 0x9411AE844A9D907EULL, 0xCFCCDA0654C9F7BBULL, 
            0x17751600E85C1239ULL, 0x05138368AED54DC7ULL, 0xBA9158813AABF094ULL, 0xDB621361D96C66BDULL, 
            0x64C96A1894D32DB3ULL, 0x3C865E9A6512AC94ULL, 0xEA47302EBFB5333CULL, 0xBE7D0DDC0FAC0D69ULL, 
            0x2C69AD3FF1DC7087ULL, 0xE4F85251966917DDULL, 0x4171613C189C3794ULL, 0x4381EF02A960FDACULL, 
            0x4183AD38DEDECE99ULL, 0x8EE5F8D57FD40316ULL, 0x55313CED23017281ULL, 0xF8048A6206323049ULL, 
            0x0B3751121D43871DULL, 0xF652326E0CCAC5DDULL, 0x1C8FC05DA7D8FE14ULL, 0x382DA6D9DE33EAC3ULL, 
            0xAE7F5336C3191D5FULL, 0xEDE3EFD85FD72019ULL, 0x4682B10C34F64570ULL, 0x1BE924FA0511F7E0ULL, 
            0x759E6E853AB37B65ULL, 0xE5BA2DF298407B85ULL, 0x77A979B98C3F85D1ULL, 0x49A2E500CEB4EDB6ULL
        },
        {
            0x0549BC6747EAC61BULL, 0xA73298FA3B268D2DULL, 0x711B3EC061065B07ULL, 0x3A9AA173FF34B7E8ULL, 
            0x49E8A84CD38D28EDULL, 0xE9C2F1BB1CE8894EULL, 0xD41989DDFE7661A5ULL, 0x35277EB06CCF6D55ULL, 
            0xF52D66FCECBA2453ULL, 0xB1485B2B092997AAULL, 0x2DB019C02597F12EULL, 0xA246725549B074A8ULL, 
            0x4A406B455F75B6FCULL, 0x6DC5BFCB432F281FULL, 0x9CE33C209FC1BDE1ULL, 0x5D236AF06A573764ULL, 
            0xD18912AED8D849DFULL, 0x91A8D2D3A29CCE31ULL, 0x499F4D0C0668E89CULL, 0x444BBF1A5F453089ULL, 
            0x2269218770D69440ULL, 0x16EA3B8E9971C4F3ULL, 0x8E9CD844B5F742C1ULL, 0x6F9178AB6522537FULL, 
            0x9A8E6835E3F46EA1ULL, 0x61D1AE98241CE190ULL, 0xC2B08FB4958C9FE0ULL, 0xC3E863673DB684FDULL, 
            0x63CD36E09808940AULL, 0x87F3C44221268E07ULL, 0xA3B289A0F4806D8BULL, 0x4F47B20340C7BF86ULL
        },
        {
            0xA8C7A50D4F003434ULL, 0x86D61FC3C81CC20BULL, 0xA228DFFE4FA3B440ULL, 0x10BF218E58F1AB41ULL, 
            0x1431EF3457AA9A05ULL, 0x5F044BDD3D15F28AULL, 0x9CBEAD66EC67BD5CULL, 0x1D50FB76FAFFA827ULL, 
            0x822D9169CA09760CULL, 0x58F06619FA3BEBC3ULL, 0xA1B35F0AC9C98735ULL, 0xE4C469D0133022D3ULL, 
            0x602AD6CADCF45F9CULL, 0x118E0E817E06DEEEULL, 0x5D7C81F0C3E403B4ULL, 0x6B0245A1C5C1AF63ULL, 
            0xF9F9C19A09AEAF2FULL, 0x8BFCBAEB053C1D5DULL, 0x986A25DD2FCD949FULL, 0x52ADC81224E4A570ULL, 
            0x3CAF4C3E81C90F34ULL, 0x522DD973CF191097ULL, 0xC79F543FBC6F6463ULL, 0xD9C291E97291F3DBULL, 
            0xD5623812F2BED271ULL, 0x8E61915908F9BCD1ULL, 0x1305E3D53C515C41ULL, 0xD3DD415792FE0E55ULL, 
            0x9E49A28043A7A6D9ULL, 0xEED06F710282C1D2ULL, 0xEEF8AD6E13BE5A6EULL, 0x700F28194F5FD154ULL
        },
        {
            0xDA9047EAE0951397ULL, 0xE4FF367C616D3BA3ULL, 0x5D30291B70BBA453ULL, 0x2B16DFD66AEC892EULL, 
            0xB884551EB429197FULL, 0xAD6404C1BB801014ULL, 0x2E940A01207F161CULL, 0x7C4326A086EAE9F5ULL, 
            0x9D9A1015DB956C99ULL, 0xE277559C599733BBULL, 0x5D5144E8C73B9A2BULL, 0xA0585AE35E5E4064ULL, 
            0x1CD9EE25EA5FFFAAULL, 0xC62FADF193AD55A1ULL, 0x78179BB21E4747E2ULL, 0x91DA6E23584EC93AULL, 
            0x8BCF40A9769E99F5ULL, 0xD8FFADA1E5B93A45ULL, 0xA9DFE3C4F1E2A557ULL, 0x53A07E38D6F242DAULL, 
            0x584A5B3D9EFE1457ULL, 0x8DAF50FB8479A8D6ULL, 0x4DEC192948433681ULL, 0x590ACF473CBC123AULL, 
            0x3F78018DA1F32DF2ULL, 0xC4B604B922345EA6ULL, 0x18AEF18702327ECFULL, 0xAF43096EF4782A0FULL, 
            0x0B2ED61651ACB4FFULL, 0x89D4A09B919E4994ULL, 0x17A1B5C9DFD8DFACULL, 0xBA4C06C58C1605A2ULL
        },
        {
            0x341768099587B78CULL, 0x3461DBAB9A041249ULL, 0x07FD29A1E6E61F8FULL, 0x080C9A229ECB791BULL, 
            0x8FCA609791CE49DEULL, 0x659BC7180D1B9A67ULL, 0x396919C91D300530ULL, 0xA24E46337AAC25C8ULL, 
            0x0DED53749D8DB9AEULL, 0x9E07914E9DF0B834ULL, 0xF1E78F7F00E7D12AULL, 0x32B5417CBB2B6E9EULL, 
            0x8A150B9B1C54DA3AULL, 0x90453551C4745EFBULL, 0x36620814FEB4037EULL, 0x85B04101B979DDFDULL, 
            0x9A5CFD06639F32EDULL, 0x2AFBCA6221E1CA0AULL, 0x7B6C6EB7F67E059FULL, 0xDA2FED00A225B37DULL, 
            0xEE27C158E8FC9C9CULL, 0x269CD41FB231C13BULL, 0xE04FF392213031F5ULL, 0x7035B047070AD377ULL, 
            0x85CDE886F0C8BA8CULL, 0xF0F81541C4389DBAULL, 0xE35E66E4DFAACC32ULL, 0x772ACE6B9CB2FE81ULL, 
            0xD0EB33114C0990CFULL, 0xF8D588C6CF283EBBULL, 0x54AF5506C7E0C5E8ULL, 0x58F9C8C136C97254ULL
        }
    },
    {
        {
            0xE1AF45C33577A854ULL, 0xA6C94AB993BC25ACULL, 0xE4D84DF29F69CE69ULL, 0x9AAD1152AF261FAFULL, 
            0x05BC59D27D4406A0ULL, 0xFD2DDB0E0C7E400BULL, 0x500FFC5BFB740887ULL, 0xC596018A4447E252ULL, 
            0x66AA90F5E27B13EAULL, 0xE36C5682ABEC2588ULL, 0x83BBE528815236F9ULL, 0x6B3541824EBCB51BULL, 
            0x553261DB30AD15B4ULL, 0x4EA4212AFAD350DCULL, 0x4A5DB826B0449CC8ULL, 0xB5D034A1656FE234ULL, 
            0xEB3988F178103D57ULL, 0xB358FB31FEB846A1ULL, 0x9E76774FC6F00C97ULL, 0xCB9E249A00FA34FAULL, 
            0x4793F75CAA680AA1ULL, 0x21C8B0808ACCFDC0ULL, 0x79E07B2D08F1147AULL, 0x49942FB9E3EF4464ULL, 
            0xECB544F9F81DB160ULL, 0x551535FB7B00D909ULL, 0x135215315EB7EC86ULL, 0x2F4D6C85067D5447ULL, 
            0x6EC940A5A95A4E0CULL, 0x31ADFB8230B18E93ULL, 0x9983EEE02844CA9AULL, 0x3032FCF58CFCC91CULL
        },
        {
            0xDA42468A28880854ULL, 0x00B44646AAE4DFC2ULL, 0x8B01474420E7D57DULL, 0x48FC54660C7B91D7ULL, 
            0x699DEF580127BA9FULL, 0x9856E6FACF6071D2ULL, 0xF34C5163C4BFC480ULL, 0xC71AD116A218E8D8ULL, 
            0x45C4FF1EC0C60C13ULL, 0x739839B1DF7C7ADFULL, 0x1FAC419635F8BFE9ULL, 0x458E31FC3C01EA89ULL, 
            0x8FFEC2DDBA141ABDULL, 0x1309FFE4C8CE3EA3ULL, 0x2F35F3416F4963FEULL, 0xB676DAB4C8D17387ULL, 
            0x830A345E911792FAULL, 0x3B5513212B2ED662ULL, 0xD6DC8719B46F6128ULL, 0xAB8A9927B72F45BBULL, 
            0xA0C4B95247448DBCULL, 0x23BC2699C6557EADULL, 0x4B5FD6A871A335C5ULL, 0xF36EA4799A4C755FULL, 
            0x7267E3A8C3F75183ULL, 0x0D77416597D1FDA2ULL, 0x9772814807D797C6ULL, 0x5BBCC389D915A72AULL, 
            0x7D21E05BEFC938F8ULL, 0xC041DAE7DDBB56BAULL, 0xF2E38B4FAE4BA282ULL, 0x8716DF87E23288C6ULL
        },
        {
            0x857AC8D859473A38ULL, 0x88B1628687ABC795ULL, 0x96D21A54B4D8A1D3ULL, 0x6B5261415A028036ULL, 
            0x10A5438F8E81F168ULL, 0xB972A21DEEE72E48ULL, 0x067D0F4C46B45A78ULL, 0xBC24A44F83E7761FULL, 
            0xADD7B1F340039D55ULL, 0x12EEC971BC809B61ULL, 0x3859911CB9056B52ULL, 0x2DC1FF9C983947F9ULL, 
            0x3534AB13D879C252ULL, 0xC11B6E450F2E8366ULL, 0x1CB70CCC16F3600BULL, 0xF13B838607C7814EULL, 
            0x5E5C87BF2CC1B964ULL, 0x41FEA475BD799C16ULL, 0x710F5D03F9F7D458ULL, 0x1284D94803C9FC36ULL, 
            0x183EBF626FD5A0CDULL, 0x10A5F15A8DBB7BB1ULL, 0x3E82B3384D66707BULL, 0xE318CB27E1A8F6F4ULL, 
            0x6E1B3C843D5C3CBCULL, 0xC18B3617FAB3683BULL, 0x4A78353E896DFA5CULL, 0x944FF006C1A4F8E1ULL, 
            0x6FE1073DD9E22F86ULL, 0xE2CCE591841F2979ULL, 0x62784FAFEA01F593ULL, 0x3DDFC304F0772198ULL
        },
        {
            0x57B0D4814647EBADULL, 0x1CA3B445C8CAB63DULL, 0x5B35AD65AB9AF455ULL, 0xCC576DA7F39CC1A3ULL, 
            0xA1D559D6B13FAE3BULL, 0xE3DB9ADEA51C3977ULL, 0x5988287CB9A09642ULL, 0x200C2BCDDEDBD49DULL, 
            0xED89E7FB012C91FEULL, 0xB6E7E2D452518833ULL, 0xCBF8FF7823DF31B9ULL, 0x51B065ABC737B5B4ULL, 
            0x245EE90D07C5BEB9ULL, 0x08BF8786F1ECDD34ULL, 0xECC871F4888F7815ULL, 0xAF23E80FA6319618ULL, 
            0xDF68C030560EAF77ULL, 0xBA3D7182859B0C58ULL, 0xE06CF80B4BE82867ULL, 0x3BB8EE8660807589ULL, 
            0x9CBB67BD827BF001ULL, 0x1AA699A49068E926ULL, 0xFAB51301674523D1ULL, 0x7D66283ED6D6166EULL, 
            0x5189915FE78631D1ULL, 0x89F79EDB36376D78ULL, 0x31EBFE689689BA9CULL, 0x0D4FC804D92AEBA9ULL, 
            0xDF479822BC6EACB1ULL, 0x048A37EA614AADA2ULL, 0x436C05EBE8312AF1ULL, 0x43FF82D0431D6725ULL
        },
        {
            0xD2EEE1B204831B25ULL, 0xA67600DA3AE30F6CULL, 0x80553F3730918BD4ULL, 0x44E9ECD5B2B578A0ULL, 
            0x0BBC6FED129D4FF1ULL, 0x2077DBAEDAA7A53EULL, 0x05C069C92573514BULL, 0x285BCC6A0A7D4B16ULL, 
            0xEC1861C5F718046FULL, 0xD16BF50259A0B6E7ULL, 0x1D48508CA01C7223ULL, 0x77F79B4D4CE661DCULL, 
            0xDF47F6CF41502867ULL, 0x4170DBDDFC64898CULL, 0xA92C8D20EE515EAAULL, 0x59157130177D40E7ULL, 
            0x2507EEA598AD9A5CULL, 0x9ADD62C8E4EF3DF5ULL, 0xFDA24C092067239FULL, 0xE28440C3B15CD443ULL, 
            0xF8917B7722DDE178ULL, 0x1525AD623BBC60A5ULL, 0x965B93BF3845076FULL, 0xB327CA5A6BCF81B2ULL, 
            0x530A6E8134910CAFULL, 0xF72488622C7A6933ULL, 0x3380D5C4BFD4E2D6ULL, 0x1C966A4F5AB829B8ULL, 
            0x66DA08AF39040264ULL, 0x3A5E56D3550D6805ULL, 0x84972AEBCA6C1019ULL, 0x0A489A66EBB428E3ULL
        },
        {
            0x4C198403A8E6BA17ULL, 0xA5273F2AD5F6DF4BULL, 0x823A74FC89DE617BULL, 0xD5DA93E17D5B0BC5ULL, 
            0x79057568E4024B0FULL, 0x1D9CEED0A2222FC3ULL, 0x41C1BCC91A071611ULL, 0xA730C33E2C2A0557ULL, 
            0x2CA50C80DE6ACE03ULL, 0x666D4F18FBF6D9EDULL, 0xED85C1ED94853412ULL, 0x96B8D52BD8F532ACULL, 
            0x96D954420B26D812ULL, 0xFA67660DC7A4AD89ULL, 0xA04830A03CC027B1ULL, 0x147FC237F2EE023BULL, 
            0x3F28922E218A4AA7ULL, 0x33DCB026493C438AULL, 0x9516EEF4408293FCULL, 0x31D981590AEAF23EULL, 
            0x03FEB63784EE6F41ULL, 0xBE0E0F5A15865A41ULL, 0x7D4A46E3BCF25E80ULL, 0x4529E50423820868ULL, 
            0x5C479EBDCDBD271EULL, 0x17ECBC1C22AB9C9AULL, 0xE78DE50F1824CF8EULL, 0x6A25A7F3E6B61233ULL, 
            0x4D285AC64854CE44ULL, 0x58B210C4E5B16DBFULL, 0xBF30CF70EF62F61CULL, 0x7F77BFD4EA4DA884ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mirfak::kKeySpawnAConstants = {
    0xFE7F2D48C3A9D4A0ULL,
    0x51E293AC4FF3169DULL,
    0x361622CD416B72B6ULL,
    0xFE7F2D48C3A9D4A0ULL,
    0x51E293AC4FF3169DULL,
    0x361622CD416B72B6ULL,
    0x5CB2D023558D92FEULL,
    0x7F7BABBB09AEABE8ULL,
    0xEA,
    0x5A,
    0x5E,
    0x31,
    0x3C,
    0xD5,
    0xA6,
    0x39
};

const TwistDomainSaltSet TwistExpander_Mirfak::kKeySpawnBSalts = {
    {
        {
            0x177ED46C581EFA2DULL, 0xAE0B48F84794118BULL, 0xAFAFC1988CDD4886ULL, 0x7A8BFE43CFA6D439ULL, 
            0xC26505247E402C30ULL, 0x9D88963605EC2DE1ULL, 0x722B285A733B07E9ULL, 0x4D263DECFC06AD1EULL, 
            0x1B3C603AF6C8787FULL, 0x7D95692CEC20B3A0ULL, 0x17BBE9D61FD81775ULL, 0xF1C69B1444651E79ULL, 
            0x4FAD9697D5092BCEULL, 0x64A190FD1586FA67ULL, 0xD80E97486BF63F31ULL, 0xA09AA6A1DB9F0E63ULL, 
            0x390C058D835C28C2ULL, 0x1D5DB850831BB949ULL, 0x8BB4D2A6DC27DE79ULL, 0xC77746C8D11D7B1BULL, 
            0x15E21747B6E2A450ULL, 0xEB8B7193DD825C02ULL, 0xEED61231E8C503E1ULL, 0x9480B7A27A4535CCULL, 
            0x82C50B75A7EA28BAULL, 0x118421C0764417F3ULL, 0x47CA1770AEACAACEULL, 0xCC4F6D98D3300719ULL, 
            0x896F4E2DF7CB6B02ULL, 0xDDAEC6C19885BCD0ULL, 0xDE48B6B850C54766ULL, 0x78B5D940FF090B07ULL
        },
        {
            0xA9FF63F53DA2BD5BULL, 0xA548DB70C4762146ULL, 0x7968615DE1084B55ULL, 0x9B23DC1046184DE5ULL, 
            0x0531139256213765ULL, 0xC2C864D1FA5960C5ULL, 0xFF71382C307F9060ULL, 0xD50D2FE71859086BULL, 
            0xBD3A1FDA8459C4B2ULL, 0x72DDF8D8577BF9ECULL, 0x5365A3B1EF309757ULL, 0x283AFFACCF9D10E8ULL, 
            0x26B002DA34F5418BULL, 0xAC232CA8E07FA338ULL, 0xF1C6EB82AD43F629ULL, 0xEBC524B35BB6EF55ULL, 
            0x7785CF5E954E0BA2ULL, 0x6A450AA2E0C2F885ULL, 0x9A0B8EEF3E17A538ULL, 0x566E0C0E969D61F7ULL, 
            0x40D660CBD4EC7BDEULL, 0x699ACDFE49E74BA8ULL, 0x54BD5534615BB031ULL, 0xB1ED1417EE0CE42AULL, 
            0x2DFF4781317E5898ULL, 0x05F5EE46AEC6A73CULL, 0xE89BF7B4ADDAE687ULL, 0x8923CAD40B65AEE3ULL, 
            0x206D80E6788BDB7CULL, 0xEAE2397C6D2E8EAEULL, 0x1139D082D3E8A681ULL, 0xF827F8A014609E4CULL
        },
        {
            0x272DE59449CD7F9BULL, 0x28E3056B02C3A3CAULL, 0x1DE621FE3BC8F070ULL, 0x24FF87AFF03A5005ULL, 
            0xBD86AE112A2F79ECULL, 0xC5E7E61EF70BB02FULL, 0xA638F14A567C9829ULL, 0x1A16021236374D03ULL, 
            0xF7855EAAB7DB1754ULL, 0x7174138B71B0EA53ULL, 0x724DA834A7BF2CBDULL, 0x017E9CB8E4852BD8ULL, 
            0xA2C44501DD91B31DULL, 0x13AC47B0F75C1138ULL, 0x1A54888F57A939B1ULL, 0x30E201ABC756875CULL, 
            0xAE0370C818DB3CBCULL, 0xD1DEDBFBB39F575BULL, 0xD53FFA6CADED6E51ULL, 0x07AC559069FAB689ULL, 
            0xB4158E258CE07642ULL, 0x4243DB219E3B5B61ULL, 0x61BC2BEFE1768B7FULL, 0x4D66B5F128C46327ULL, 
            0x9A73CFA712E49994ULL, 0xF90E169CCCFD7973ULL, 0x4282FD9A15CE745DULL, 0x6CE69EAC5C89DDF5ULL, 
            0x092C5674324EF721ULL, 0xBFB36308D7E0044BULL, 0xD422CA7A62C36EC9ULL, 0xDAB542A0FA058B5FULL
        },
        {
            0x57617AB5802F51BCULL, 0x93F28EBB8379E3F3ULL, 0xD5072DEA13549784ULL, 0x05423B4E26763E8EULL, 
            0xE6810CF271DA3B29ULL, 0xD437D876C820544BULL, 0x7D0F8E2789D1C80BULL, 0x554BB575ACF41BE4ULL, 
            0xE8AD9E9513C14ECDULL, 0x160BDCB863A8B712ULL, 0xC19E050BD3C9C8E6ULL, 0x753D0C2FC6DA7FDDULL, 
            0x71142833FD25D056ULL, 0xB84EF14070E65D50ULL, 0xF1E699D0872312E7ULL, 0x0B496947A74F6E25ULL, 
            0x97EF94DD85FA60FBULL, 0x3499DD17EF86CFC4ULL, 0xAA553E245F8153E2ULL, 0x6CFC201B46E123FFULL, 
            0x217C7D4BFB6F9B6DULL, 0x14A72413CFDA93ADULL, 0x448E800415A2D397ULL, 0x405A6001CB085C37ULL, 
            0xBF1F1EBD604A9C29ULL, 0x8E3DCDC3839C5519ULL, 0xC5E1BE8BB4CD99F6ULL, 0x1D72947A08FF45AAULL, 
            0x025609FA757D3552ULL, 0xC71888D023C39101ULL, 0x00671E7F0841E978ULL, 0x783CCF64011DF8A9ULL
        },
        {
            0xF02E74D09C853E7FULL, 0x35030C2B0D985A36ULL, 0xB10FDC8CE99FB45FULL, 0x73F8D6E85C01F6EAULL, 
            0x8D362C27D2BF5036ULL, 0x83FBC02B6824ADCFULL, 0x5F17E755FEFFE435ULL, 0x06FDE9C724830D51ULL, 
            0xF3784C09415256B4ULL, 0x7776320E71989DE0ULL, 0x45F7D029B89D026DULL, 0xAA2DA54ED7743715ULL, 
            0xE1BF47BBF4DD93C7ULL, 0xE4B454F624453E07ULL, 0x0CBC1C0EAF21842EULL, 0x6185864FC2B66285ULL, 
            0x2FDDE8ADD734F96DULL, 0x7D34698A3A59454FULL, 0x31D9192430793957ULL, 0xB41201E83BBBA078ULL, 
            0xBAE7276AEDF2516DULL, 0x66F75F167CBFFC53ULL, 0xB277DAFE2D94EFCAULL, 0x4BA2711237EDC20FULL, 
            0x6B0405EFB58B1599ULL, 0x8C33499B989A4B03ULL, 0xBB137C802AFD0383ULL, 0x9746F018DBC30FADULL, 
            0x8A68141138C8BF1AULL, 0x0FB84A90358AECA2ULL, 0x90745C7633C337EEULL, 0x2B95359B28B9CF71ULL
        },
        {
            0x9A8BBCBDBB3B378BULL, 0xA92784F19DF159D3ULL, 0xF44D6237B3BB7535ULL, 0xEE6F6BD9E0837035ULL, 
            0x27B91CCA40F2D1D9ULL, 0x4E3E69C8639CEC7AULL, 0xAB82919D07106BD5ULL, 0xF03C6BA39C73FAADULL, 
            0x19AA3C829DBD9192ULL, 0xBD5944E77D4B4056ULL, 0xA5D48145988E47A2ULL, 0x21558DC664822DBBULL, 
            0x7700898899E66314ULL, 0x8455E2FE0E689B2DULL, 0xA41500951AE6F0A0ULL, 0x1CAF648300032599ULL, 
            0x6FB4E155DE650F9AULL, 0xDCFD2E9208062CDAULL, 0x8EAEEF841BAF1A93ULL, 0xB506C17538D9FF00ULL, 
            0xBE193858B0D893C1ULL, 0xA9810F8CC2EEA82BULL, 0xED3B9AF92ADD36C2ULL, 0x2A22DC9AF91183FBULL, 
            0x57B6EE1C4F621C8BULL, 0xEAFCD82062FFB261ULL, 0x7F60671A8184E0AAULL, 0xDFED0ED3A5BDE69AULL, 
            0xBAA1AD90FF6757C7ULL, 0x74F8F7662B3762A6ULL, 0x2DAFEB7C81C5B16CULL, 0x4D16F986A633450CULL
        }
    },
    {
        {
            0xD62A9CED980BA699ULL, 0x6AB66931A1E1EDE2ULL, 0x6C7BE1C4B65169BFULL, 0x93CE7641A2FA8ED2ULL, 
            0x604D7A0D219E8CA9ULL, 0xE32D7499C840F296ULL, 0x46AC89E9A0B19CCBULL, 0x33254F1CD7E1D74FULL, 
            0x41B7ABEB34EE9E2BULL, 0xEFB559D1AAA6EDE1ULL, 0x93E262AF0080C52FULL, 0xF1E10F1833E30249ULL, 
            0xC8607C8F67B0E0CFULL, 0xFFC8EA45A1C2AD44ULL, 0xCF591C123C919EC3ULL, 0xF7ADB3E3E13F5290ULL, 
            0xD4CF5972CA2BDF17ULL, 0x8C6B4580EC5C616EULL, 0x5F11CFA8538E1204ULL, 0x258A0C40630B83C1ULL, 
            0x2C3C0AC3E12FB814ULL, 0x666DE29769D9D1A4ULL, 0x71D6937F6892EAB7ULL, 0x4ECFAD2E8074679AULL, 
            0xE7BFBC0D3FC888BBULL, 0xF702127DE677AA01ULL, 0x43124EFDB5295659ULL, 0x07F61B75039DEFDAULL, 
            0x5A4D673775AECC65ULL, 0x8278208353A8C2CAULL, 0x391D8BD77BFA78D6ULL, 0x37AB6A657A322635ULL
        },
        {
            0x5EA958BD32622738ULL, 0x8A37F4E30DB447D8ULL, 0x24C44E3D230F2F56ULL, 0x45CD7EF019894F12ULL, 
            0x71DBD5C7B5F76D07ULL, 0xCAC7640E421AE5E9ULL, 0xC5483C1FAC9C85E3ULL, 0xD5BF805EAD6D7716ULL, 
            0x86D53FCCD5B1D57FULL, 0x4756492E76CA5382ULL, 0xCDD9B68955BF0279ULL, 0xB625E5EAE3567A00ULL, 
            0xF73BC02A72CEA6B1ULL, 0xB9977484243B8A66ULL, 0xD3691BFE066EFC23ULL, 0xFFCECD063253A2D7ULL, 
            0x2E4C54D6A16096ADULL, 0xB0F95BCDC6229F6EULL, 0xCEDE8C3CB29825FEULL, 0x93BCB04A85E6DFCEULL, 
            0x0E35BEA4227B686DULL, 0xF71569013A0B444AULL, 0xE4C03D84E9C4F9F5ULL, 0x6BDABA0DCA83DD9EULL, 
            0xED161D03BE4A6E60ULL, 0x4FD51B55C93CAE8FULL, 0x4A5ABBBA0EF6F270ULL, 0x41032A056CEB7B32ULL, 
            0x9C2E50199F05B0EBULL, 0xD5755F501E1B4749ULL, 0x2D39218037C97BBEULL, 0x20D4E46C726558C3ULL
        },
        {
            0x2D516576434F9D2CULL, 0x68CCBC7A2F2F51CFULL, 0xD64EDA01C9794612ULL, 0xEC72443B5B61EBF2ULL, 
            0x75E3E71C5BDC68C5ULL, 0x52A7004AC41C2F33ULL, 0x037C3C45EB889900ULL, 0x905E3052DBF1FBA7ULL, 
            0x40179E3AD0EF13E2ULL, 0xFF3E3891A70F5FBBULL, 0xA148E871FAB47122ULL, 0x3C4184C95DF3BD43ULL, 
            0x1543305C13E196C4ULL, 0x5790681E99414AD0ULL, 0x6FBE2A3A015EFED6ULL, 0xDA20A358EA155B38ULL, 
            0x2A3003D8CA246A07ULL, 0x94C8F471B2BB4F6EULL, 0xB78E025038D1E1DDULL, 0xEB23512636018B9AULL, 
            0xB7029D7E57C5414EULL, 0x3BBC220A46610B1DULL, 0xB09883BEBB22673AULL, 0x2D769E84F08A6641ULL, 
            0x3F1AD390844E9EFAULL, 0x0276BB0F3688B478ULL, 0x3997D4BC9F8C8ACCULL, 0x7BC21DAF674B688EULL, 
            0x9C577056C117E6CBULL, 0x5DA91DCF90270DF8ULL, 0xFF43256C7A76F07CULL, 0x7B266FD760936B69ULL
        },
        {
            0x56C2B6BBD0C48432ULL, 0x800F661D363E375CULL, 0x00EC10D642A8E89CULL, 0x2A00F9C9621DC7C7ULL, 
            0x347CA7EF81FA2BECULL, 0x55D218B07A1EE3FDULL, 0x8E831FBF0643053DULL, 0xC0DF4D5E82D6B7E0ULL, 
            0x3F50ADCCBE64CB1EULL, 0x898E5652DAE479B3ULL, 0x1D7409369CE504AFULL, 0x7AFB85FB6CAB8742ULL, 
            0x0F5D1486296222C8ULL, 0x5790B5C523E08FC6ULL, 0xA1A51E95FF3C46AEULL, 0x11225E65B1BF1CD4ULL, 
            0xE4B922A4B1CA43F6ULL, 0xAB57D05A6C3BE713ULL, 0x0D619BE3B3EA77F2ULL, 0x644B95FA2E25FF92ULL, 
            0x5E4D7C15045B141BULL, 0x8342B07C8B8DAA37ULL, 0x4D21AD0EBB2271C7ULL, 0x7643AE58E17B0FD3ULL, 
            0x77919CA91DE4759AULL, 0x64886636E5E69875ULL, 0xC8B92EBDF8376E9BULL, 0x7C94AC1391D16F5DULL, 
            0x503B31BF8E7BD430ULL, 0x5ED329182C56D5FCULL, 0xBC86C18E8F18AA38ULL, 0x6E6864B14361F1C1ULL
        },
        {
            0x28DD72C7691FD5CFULL, 0x763B20E4DA7E461EULL, 0xE4D6CA0EBD567D91ULL, 0xCBC1FF2F80672451ULL, 
            0x759B6955E2E7EBFEULL, 0x53ACE6319CFFEBC8ULL, 0x05F2B1EA95389E25ULL, 0x06D85A7D07CD30A8ULL, 
            0x82FFEEB2B4FAB767ULL, 0xE1A272668A710D1CULL, 0xE9B6C07097245BD9ULL, 0x3F53D3B45859F292ULL, 
            0x7310F0D4437E0EE5ULL, 0xFA3F1E43F45C0127ULL, 0xF8CF9937B5B5A3B6ULL, 0x2E220BD4EF8150DCULL, 
            0x5AEAC0E3DF7F53ECULL, 0x5E90FE58F5678768ULL, 0x68525F3BE3DD5124ULL, 0x20EF2D67EF8C2009ULL, 
            0x3EB4BE7713D169C0ULL, 0xFC5536BC321E469EULL, 0x865441CF4DF2BD5BULL, 0x75040E437DDEDCFEULL, 
            0x5CA4677D487E7E44ULL, 0x96449464B6330885ULL, 0x2749639EAD18B2E7ULL, 0x70D760F7D9ABAE33ULL, 
            0xC393EEA1DAF50A09ULL, 0xB01A6C16E96C6F9EULL, 0x67C7D879914CB6FAULL, 0xEF99357DF77DE65FULL
        },
        {
            0x5E9092E95A4B8413ULL, 0x9BD34B88FBF2A0F7ULL, 0xA2A168AEC2E10C74ULL, 0xF3447A7112A3A84EULL, 
            0xE8050E73FAFACF35ULL, 0x0C86D8219B6AD6CEULL, 0xD1F0D1C736BFF722ULL, 0x6D199348D5CED102ULL, 
            0x9EAF28DA3B079123ULL, 0x16C8EF92183A8E90ULL, 0x375959E30F7B12B1ULL, 0xFB14E052BABC0BFDULL, 
            0xB6775F9BD0EE46F6ULL, 0xFD5234F08C865E21ULL, 0x708D211492BDB5EBULL, 0x16B5863BAFA444D8ULL, 
            0x9EA2DB897D6C09E9ULL, 0xE160CDE2A0914C51ULL, 0xD9CBF66E1A4D3A83ULL, 0x271C2C30C8792C25ULL, 
            0x2143A75F3F344EE9ULL, 0x74B2A75787ADFC8CULL, 0x92685D457849466AULL, 0x7A9D470003C9C35CULL, 
            0x23A8256A81EEF51DULL, 0xC6879123C288A1AEULL, 0xD499F610BBFFB997ULL, 0x5F9BA64B481E7799ULL, 
            0x2799EFDEB609D7C2ULL, 0x3EC139984CD5906DULL, 0x45CFE7A5EB550794ULL, 0x9F4709B9F9DA7882ULL
        }
    },
    {
        {
            0x7310A64B1ACFDF30ULL, 0x6D39736E7735BE8CULL, 0xD585554E3EDB94EAULL, 0xCBAEDEFF367465D8ULL, 
            0x7863425115FE0A7BULL, 0x533A1DCFC3B75632ULL, 0x56A56F33BCF69A72ULL, 0x4276D00CF3117743ULL, 
            0xB65F9897E274274EULL, 0x56AFCBED836C2C86ULL, 0xF49D9820A352558EULL, 0xE2FCBAB11CFE3686ULL, 
            0x8B67BE652B704250ULL, 0x3F532730FA60CDC2ULL, 0x418E5793CAAEFE56ULL, 0xA451FA2A459848EFULL, 
            0x568E379A98862AB6ULL, 0x92633F8BB6011497ULL, 0xDE232FBDEA73FC36ULL, 0x8EFA9603D97F622BULL, 
            0x6535AFDED5403E54ULL, 0x695EA21093F70602ULL, 0xFA43FCC8BF792ABCULL, 0x162D9B81FBF2D410ULL, 
            0x111F1D69C32AA822ULL, 0x7E90EDBE59344E81ULL, 0x9AFB2621885F66B6ULL, 0x45141FABB0206401ULL, 
            0x0D598F41ED716C4DULL, 0x9C358DD815217FF6ULL, 0x56259C5E16676A69ULL, 0x11A98F7B180C0A26ULL
        },
        {
            0xA1964F59B4F7938CULL, 0xED60E90B0D8C8D39ULL, 0x0291AA64470921CBULL, 0xC031746EDC095C52ULL, 
            0x16957B8A0704A72EULL, 0x4443D923F2F191DAULL, 0x8A99B3159A5DBF01ULL, 0x4D80CABB064540B3ULL, 
            0xBEBA0C246F2155CFULL, 0x973DDF990A88A49BULL, 0xAD64A9D9A7F84C01ULL, 0x82435AEC1055A027ULL, 
            0x01368A55B1087B47ULL, 0xC3A3A7E594C171D6ULL, 0x6C51C3D5BDABD918ULL, 0x424E276C4EC3BF48ULL, 
            0x3C09677350DE97FAULL, 0x19ACD4DF22CEFB19ULL, 0x9C261E069C82A89FULL, 0x429FA5B7E8F24312ULL, 
            0x323DFF489F65E272ULL, 0x95CF7C601F859462ULL, 0x3CA5442B9861B5E5ULL, 0xC5107E11B60746E4ULL, 
            0x945AB2BBB096FAC8ULL, 0xD65B77F777670058ULL, 0xC4408674AC838650ULL, 0xB81E8761F00DC994ULL, 
            0x727AE4133A0C89C5ULL, 0x49BA142E6F10DED2ULL, 0x3952E6FEF97489ECULL, 0xBB281293A9B64CD7ULL
        },
        {
            0x4B368728FF47E48EULL, 0xF564ADF92C201ED8ULL, 0xFE1C157D3A65B209ULL, 0xCA3C30F094DB03DFULL, 
            0x3E99DC4DFA1704E6ULL, 0x68C9AC67A2BF7C79ULL, 0x6AF0EDEE8BA41CFCULL, 0x99DDDBAD191A3DC0ULL, 
            0x13E9A8E96009A1B2ULL, 0x2F35D6C27479CA6FULL, 0x50398388A1E6087EULL, 0x392D6E6E60D6E175ULL, 
            0x453B3CC94800572EULL, 0x13DD79B9BC839323ULL, 0xB3D44D0EAB0DE123ULL, 0xB5DA4E8746ABF7E5ULL, 
            0x2A1345CBD689F99BULL, 0xAB75C4C3B37B17DEULL, 0xCEFB9D9CA1075B13ULL, 0x6C2D667E55BB6CD2ULL, 
            0x09BD2C8303FA8FE8ULL, 0x81ABFE349AE9AA07ULL, 0x61E08D5E10E8C0FCULL, 0x59A124C5F6DA1D8FULL, 
            0xEA2AF4A9DFB62519ULL, 0xC0F889FFB85FB4C3ULL, 0x9F46ACB7EA6EE6AAULL, 0x8DCA79AE1158CC99ULL, 
            0x1527A3542CB86095ULL, 0x67DB3E4678F5DED3ULL, 0x6CA3358926F3DBBFULL, 0x608E15248F3F48D1ULL
        },
        {
            0x501245532C38DF2CULL, 0xC1AE556AB22017F1ULL, 0x08D3CCF125F68223ULL, 0x90BA09CFD7F54E82ULL, 
            0xA733296422046FB3ULL, 0x35A6389400AA3B38ULL, 0xF7362F075C6B9D70ULL, 0x753CBB3B2401616AULL, 
            0x3C538B3BA71F6181ULL, 0x1B3166BF6D7E2534ULL, 0xDFAC03C0B42DBCB4ULL, 0x18F564C396892C9BULL, 
            0xF586C27F29E794A7ULL, 0x666279BBCD2BC247ULL, 0xA051711C463990F2ULL, 0x6D95116CD539A262ULL, 
            0x600140C869BB6511ULL, 0xB37875148A6A40EFULL, 0x2D09958D65B0F375ULL, 0xAC802DAD89F71D44ULL, 
            0xC3136C06AAA83C77ULL, 0x519CF71235D1565FULL, 0x432AD9EC72EFC995ULL, 0x1DF6177EC322D988ULL, 
            0x4CA2883E37D62F2BULL, 0x83CF95EB53036B0CULL, 0x3BF165F760132BA2ULL, 0x1E42CDD035E6BBCEULL, 
            0x7708DC535E859EB6ULL, 0x9D8263AB969FF2D7ULL, 0xCF374E0CB121E7BAULL, 0x419769F0FB373401ULL
        },
        {
            0xCA6A96F93B9B5C57ULL, 0x78E8A5A3991E7571ULL, 0x7D22FD3153D37D4BULL, 0x53D3E08ADF3F9BD4ULL, 
            0xC82BAA88A741E649ULL, 0x923FA40ECCE4C28DULL, 0x128DCC030F34008BULL, 0x37171D9993BB281DULL, 
            0xBDA66CF7A02C4570ULL, 0x8CF83AE570EF23BBULL, 0xC4865ACD64F1EC0CULL, 0xC98106242A58FA44ULL, 
            0x8E549FA5E729C9BAULL, 0x2B52683DC330E38CULL, 0xBC346958DB3808E4ULL, 0x30594314F3262E62ULL, 
            0xE101E4F8C9933147ULL, 0x29499DC2F0F3BF19ULL, 0xCBB2638557F24663ULL, 0x1CE09435014E44EEULL, 
            0x0A010CF3AB2DB11FULL, 0xC45B968085DF33DDULL, 0x076DD6034548E46FULL, 0x33DC8BCBE79FEEC1ULL, 
            0xC7BD90EE4E73EC19ULL, 0x2A2F675A59E98B16ULL, 0xA91AD2A0034E7BB1ULL, 0x5ED06F25508E4889ULL, 
            0xFA206E9FB4B2B8EFULL, 0x2DAD10456F66358CULL, 0x42AB408FF0437592ULL, 0x01BD1C18291FF7F5ULL
        },
        {
            0x25A5F303586968ACULL, 0x2023F9DB22A2FD8AULL, 0xBF33D76809C492B9ULL, 0xEE0662E737BC3416ULL, 
            0x232C0D79A301FB86ULL, 0x49F0EF57210156FAULL, 0xC55A8D6EBA3F1C91ULL, 0x32E2AAB3B51D3B4AULL, 
            0xC5C3BBA50B7CAA0CULL, 0x19C3FEE06E8757B2ULL, 0x9D8EE49775BD5C2FULL, 0x4A87CBAEE4DB4B2DULL, 
            0x9A1BABD07AD8CE18ULL, 0x1A26B5C10DF6722CULL, 0x3ABF000A2820C005ULL, 0xE053902601201626ULL, 
            0xDAA79DC123AFB940ULL, 0xCED510E150529BDDULL, 0x7E1C2598DECEFB58ULL, 0xD6126A054ED9D311ULL, 
            0xFD07A71F00C531E4ULL, 0xF4A32EB014D21239ULL, 0x68ED4C396933EF81ULL, 0x431C631FA015F79CULL, 
            0x555F53EA2F95EB92ULL, 0x9236F1D9F696B444ULL, 0x79C52470608D3861ULL, 0x017A3C3E072E1F12ULL, 
            0x39583E4DFA431A3BULL, 0x13791F66FBAC4874ULL, 0x0FBA5446D83A32ECULL, 0x1400D2AB72E44B07ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mirfak::kKeySpawnBConstants = {
    0xCA5EA62E5EAADB75ULL,
    0x2E91BAC74A750820ULL,
    0x9956C806221CF2EDULL,
    0xCA5EA62E5EAADB75ULL,
    0x2E91BAC74A750820ULL,
    0x9956C806221CF2EDULL,
    0x34F6843CD4E0785EULL,
    0xA95F121ED5258C57ULL,
    0x75,
    0xAF,
    0x5D,
    0x4B,
    0x4D,
    0x99,
    0x0D,
    0x51
};

const TwistDomainSaltSet TwistExpander_Mirfak::kSeedSalts = {
    {
        {
            0x412A82B86AA9F2B4ULL, 0xF19A35B0BEA5DEA8ULL, 0x2805189E6D27C672ULL, 0x93450283CA38DFF3ULL, 
            0x4E182A7EC194CD08ULL, 0x1564C902753C1E0BULL, 0xE7B44AF8C2174619ULL, 0xE4269691E845A31BULL, 
            0x153C20026426BF9EULL, 0xB90FFF175DEBF98DULL, 0xF86F475E5BD3B267ULL, 0x5E219A579BAA1A20ULL, 
            0x21E14E1682E1B330ULL, 0x7C0BDC11F2C4473EULL, 0xE75A9173652ACDF3ULL, 0x81D4DD2C4511B790ULL, 
            0xF286C47456E8703BULL, 0xB19CD7EABB4971E6ULL, 0x2EF470526D207767ULL, 0x090DB4914948CBF7ULL, 
            0x1DD433AB0C59CA63ULL, 0x9156A003914EBAE6ULL, 0x6259AAD667093CBDULL, 0xBDF3904EF538E47EULL, 
            0x007E15297962EABFULL, 0x6D409289A3F76245ULL, 0xE849C33E9AEE1646ULL, 0x289A45D4367C2229ULL, 
            0x289EAFA8766FCC5AULL, 0x77585AF1A3BFB678ULL, 0x39319325E13E97F7ULL, 0x653037FF4045EC76ULL
        },
        {
            0x80F136D1462C76E1ULL, 0x6AAC6860C4DF77C8ULL, 0xDBA9EBB91EFC8B41ULL, 0xCBB384806A88FDE7ULL, 
            0xB2BE812084B01532ULL, 0xE575B468BC2ABEEEULL, 0xBC1BD843CAD32B26ULL, 0x2C56D54DC58DEEAAULL, 
            0xB0E7532DCF9950D0ULL, 0xECBD5E666280C21FULL, 0xB1BDB78F8611C0D7ULL, 0x1CBD49D836FA099CULL, 
            0xF68629CCDB8A6C00ULL, 0x4C70F05A5282A601ULL, 0x8176452D0C5E7EBBULL, 0x99DCFC3D90B85BD4ULL, 
            0x9FEF3E1F1707626BULL, 0xE6A2D8F6DF189703ULL, 0xB7C188CF7EAC6746ULL, 0x9007B006567CD3A4ULL, 
            0x05A8A5D1CF930850ULL, 0x3A72ADDEF0E2CC04ULL, 0x35DB66FA02D5CCD5ULL, 0xFB7B32033E84A168ULL, 
            0xE09884FF348205AFULL, 0xAD90ABD431CBDA55ULL, 0xD27B2CEF9BBEA72BULL, 0xE38A6162CB552F6DULL, 
            0x43BB92F1AEBEF5BCULL, 0x432A02875DCF672FULL, 0xE38B55610F3FEDD5ULL, 0xA552399C13EE50CEULL
        },
        {
            0xCBF948EBA96A7B27ULL, 0x7A96E2546E3DED8FULL, 0x6828393E496673CCULL, 0x369D0206766884ABULL, 
            0xE9E39540C2CDC5E4ULL, 0x749112CCB4D58AE6ULL, 0x886C64368268A6F5ULL, 0xECE191407A07A801ULL, 
            0xACA5FA93DC56CDE9ULL, 0xEEF29037AF716322ULL, 0x5661DD94D1273603ULL, 0xF5C69F0F121F8CC3ULL, 
            0xC12C17FFD33649C0ULL, 0xE231EC8A4E57B385ULL, 0xE1F340A47B36AB03ULL, 0x87F53D5E0055DDF2ULL, 
            0xB8BB5C6C9A0E2BDDULL, 0x02D560AD8A25A3B2ULL, 0x51452C0ECD48FE8BULL, 0x5CF9FA77DC74BB31ULL, 
            0x3DAECBECA11EF875ULL, 0x4F8B4822D675F006ULL, 0x47E1C655DEEDD624ULL, 0x3A66416F28245809ULL, 
            0x51136BC118E37DFAULL, 0x09EDC4AC22BF91A7ULL, 0x496AE33C6D94453DULL, 0x85D590325C18CDBAULL, 
            0x63698E7E59330DC2ULL, 0xA311F729D5A41F6AULL, 0xCA11EAEDD22B24BCULL, 0x477A7BB56A80C468ULL
        },
        {
            0x6A39C5235BE9A57EULL, 0xDF191DEEA0ECB9DAULL, 0x6197136FB62F9397ULL, 0x9028B06D81C3E0FBULL, 
            0x370D029CACDD3DFBULL, 0x9896535613CC692EULL, 0xA9C69F5D3F7E3321ULL, 0xE02D527E836801C0ULL, 
            0x54F9D0E07C9BECE6ULL, 0x4B24350C843CB621ULL, 0xDD4BB34F7364F708ULL, 0x6A58D4326C68941BULL, 
            0x01F1ECB8F24899B3ULL, 0x04FD123CC416F479ULL, 0x0E6F11CE3EFD2A15ULL, 0x81001FEBAEFBE6DAULL, 
            0xB8BE751B4CF3842FULL, 0xB505968C59D2262AULL, 0xF6F0E80786CBE83DULL, 0xD9E16E63A8E1A9D9ULL, 
            0xEE08A065F50559BFULL, 0xDABCBA0AE03AA95DULL, 0x9A7B567AAC8B393AULL, 0x03AA2C9DFFE95442ULL, 
            0xC49C76C0C438E092ULL, 0x27D45B1FC18E8C3BULL, 0xF765534421DC2696ULL, 0x296C252B52FD44E5ULL, 
            0xD042979CA3E7E9E0ULL, 0x0DA65D73149F2CFFULL, 0x394D3E352B469AF8ULL, 0x9DD2C7449FCFD100ULL
        },
        {
            0x3F4C60B4C406A2ABULL, 0x2DF61DAE8E6C736EULL, 0x4082E8CAF74B0C2FULL, 0xB4C43106CDF82E58ULL, 
            0x2EF494456159B737ULL, 0x8EA688FBAD0A38E4ULL, 0x2F51A324A48EEF60ULL, 0x0ACA7D59EFCFD0B0ULL, 
            0x45312774A498E42CULL, 0xEDB56926F7797041ULL, 0x1BBEED12D9D6DE65ULL, 0xE24B66BA0A21B12EULL, 
            0xF4E3BBCE95EE25ADULL, 0x5F6FA830201A5CEAULL, 0x6211EAF6F0D36E2EULL, 0xE63707F645C76FF0ULL, 
            0x02C7B5F7D60773F0ULL, 0x4214687F30D386C0ULL, 0x20D73076200AB5B6ULL, 0xD045B958DD35CFC8ULL, 
            0x06C4CA83E7FDFA21ULL, 0x87A2AAA094FF7C00ULL, 0x0DB8CADB774808B5ULL, 0x7F38FA45454166FFULL, 
            0x397842B207608B50ULL, 0xF231B915AEAF2390ULL, 0x91CA58D389029622ULL, 0xEEACD4D0E41FDB88ULL, 
            0x26AFAF2A61775FA7ULL, 0x7B4B626F9E1616D2ULL, 0x3ADD9A45CD0518E9ULL, 0x108A4D465D53F779ULL
        },
        {
            0xE5EC52BDAC930DC0ULL, 0x7D14123A091D827CULL, 0x1C56284530E4C47AULL, 0x1864115FF05623D1ULL, 
            0xA5A79C1F980135DAULL, 0x4BB9BFB793EA0D8BULL, 0xE60E41766C7A21EAULL, 0xC6FB40CA2666F9F8ULL, 
            0xE3383E4337EA14C5ULL, 0x9B410ED09FC0A4F4ULL, 0xBB1DE2FF232A94A8ULL, 0x80A480F35475C0EEULL, 
            0x08D466145130A331ULL, 0x614E1C88BC4A7701ULL, 0x3A33668EFB7C303DULL, 0xBE689B6C573D2C48ULL, 
            0x7A879E2D35BB7B04ULL, 0x1128DAE3853AEA56ULL, 0x39228F42DB8AF421ULL, 0xD7E1F8CFE0054F1FULL, 
            0xACFEC70505507CD6ULL, 0xD333B9F95D355F97ULL, 0xD07996BB222B6C09ULL, 0xD5CA69FB77F1E83DULL, 
            0x9A8BF5D1926FC818ULL, 0xCA7BBEE0154D80E5ULL, 0xC0F4E638F3BFFDA7ULL, 0xC64137D16F50F365ULL, 
            0xD1F1A116ADBB6539ULL, 0x53CD993C7A1AD85CULL, 0xA50466B32EC3C5E8ULL, 0x7EAFC2E6815126ADULL
        }
    },
    {
        {
            0xFF01335D55D89ED9ULL, 0xB0A13B4BE4E5FC31ULL, 0xF2D1335ADA7E96ABULL, 0x870BDF100341968DULL, 
            0xFD6BEF9E53745170ULL, 0xBBF335102B0BBF71ULL, 0x4780806432E276C3ULL, 0x2F0D5F6E33E3CA41ULL, 
            0x1F7F7CCBEAD50B9DULL, 0x7EBCD9A5CA42E0C0ULL, 0xFC893CBAF1A15EE0ULL, 0x8DE41B8A0C1E0359ULL, 
            0xA04D6EFE747BF1B6ULL, 0xCB3B425DC33DF8ACULL, 0x77C79DEA813E6299ULL, 0x400727E4CDE0C482ULL, 
            0xAB49DA78E135F5B3ULL, 0x8E9B2741FCE44D4FULL, 0x7BDB4F794FCA3560ULL, 0xCBEB5129D7EB66A5ULL, 
            0x7DA6D5F762B27194ULL, 0x7CE5EDB33343D53BULL, 0x39E7C27439FABE76ULL, 0x85D63F302FED272DULL, 
            0x039199E4BB0F06BDULL, 0x562533051B7B11E0ULL, 0xA5FDB73AA689E75EULL, 0xD953E73EDF3322B5ULL, 
            0x59028F00EE866DE8ULL, 0x8E8BB421C9C2C2CDULL, 0x98F1594AACF57451ULL, 0x615C5B0F29DE973DULL
        },
        {
            0xE8404948FE14DDE6ULL, 0x0C01BAAD2B0C0C1BULL, 0x003ABA063D24C19EULL, 0xCA46799FA42F0A59ULL, 
            0x495839F575757302ULL, 0x95C0655D0F65C3D0ULL, 0x7F95B8E5BCAA3A2CULL, 0x2812170BAF5AAFD2ULL, 
            0xC72BCFF889FFA56FULL, 0x2E4F6D101307924BULL, 0x2EB02D1620A4D245ULL, 0x3E5B008EEFF41EF4ULL, 
            0xE595D550516885F9ULL, 0xC9EC319F8CF15E64ULL, 0x3E77F4B512D4781AULL, 0x66E88F2F761AD83CULL, 
            0xACEA75CEF2F07596ULL, 0xDFD3D782B6CF047FULL, 0x487D84DBECEEFDADULL, 0xE283E2A1AACEC3BAULL, 
            0xEB905D2CB49EBC25ULL, 0xA58C1F51AFD0EED2ULL, 0xF360818434C81BE2ULL, 0x88A2526D483FE9A3ULL, 
            0x1AE7B912C57A2429ULL, 0x4EE3294452894350ULL, 0x36D33AA5F50BDD13ULL, 0xE6CD328CFECED069ULL, 
            0x2AB1A116728EAE91ULL, 0xEEB2EF04C0DEBF33ULL, 0x63CADD41B009B01DULL, 0x69E7A994346325C7ULL
        },
        {
            0xA895D77D7428CFDFULL, 0x4FE3A04768066CE9ULL, 0x386BE5F9AE5AFD13ULL, 0xAD799DC37180BFFDULL, 
            0x568CA7068ADF5225ULL, 0xCB9808B7D6B2CF26ULL, 0x4B4FB41FD00B515DULL, 0xF40DD28069FDC7E2ULL, 
            0x67FC0BB522BEBCB6ULL, 0xC2FE238E884B4150ULL, 0x302D9178CDAD441AULL, 0xE4FCB7A47F76F82DULL, 
            0x9B8138031B2626DFULL, 0xE312A2B5294CFB9DULL, 0xA7EA56898B11705CULL, 0x0D2346BF818EDED8ULL, 
            0x78E1431B7D7240B1ULL, 0xA761B7C78BC329B5ULL, 0x534F9F8B83A839A5ULL, 0x00A4C299F281F573ULL, 
            0xDA19B9836D1F5A12ULL, 0xA69D267CA933D27EULL, 0x404645AA435EDC50ULL, 0xC605FC28AEC25B09ULL, 
            0x0C893B110FDB29C0ULL, 0x120D0C31E0EB1797ULL, 0x9DBC13E2795AE113ULL, 0x9239425294158E3DULL, 
            0x58F1F746E7FD34C8ULL, 0xBD8A39277A84FA2DULL, 0x26CDBBAE888F291DULL, 0x6666E75EE9858406ULL
        },
        {
            0xB17AC893AA26197DULL, 0xDFA3192A9BDD84CBULL, 0x9C2A90CDC3943A9DULL, 0x8CDA8C66DCA71AE8ULL, 
            0xA9A2879C76ED89F8ULL, 0x93137AAF83D012A7ULL, 0xC570A92DD0655BE8ULL, 0xED8A6F7CECA4BECBULL, 
            0x132BEC77EFB82D2DULL, 0x39136FC5B7756A7EULL, 0x9AD8843093492F69ULL, 0x9DAB0A030A32E200ULL, 
            0x4EDD4289B3535826ULL, 0xE5A51A4982464566ULL, 0xFA6F54195C3133A2ULL, 0x559A959E3297F97AULL, 
            0x5B32DAFE016950B4ULL, 0x2767C53F57D4AD03ULL, 0xB8BB372D67C07205ULL, 0x4AE91C51570041B7ULL, 
            0x66055A5BD54FE7D1ULL, 0xF9FFE250B3A877CEULL, 0x642E1A58F3083F82ULL, 0x36D3A1CAD7C3FAFEULL, 
            0xA6836EAB17B91A98ULL, 0x12DB48F666C4D261ULL, 0x3202F7E7D1D51970ULL, 0xEAB0BB71FBDE439FULL, 
            0xE89CF7AB16149E2CULL, 0x489E860EBF6D1E7FULL, 0x8859124000BBFC50ULL, 0xA83ED16D8E5A1E2BULL
        },
        {
            0x9825FFE30A6DD312ULL, 0x37CA2F12D16CE12CULL, 0xAFC87AED09DDD4BDULL, 0x018BB19EBDC97183ULL, 
            0x97158B8B613A02A6ULL, 0x3BB9E928D622AAB0ULL, 0x41E0B5E0E6E75F8AULL, 0x37D6E76326CD9B4AULL, 
            0xE357A01AAE50B134ULL, 0x8F3B9F8AAD864E04ULL, 0x81196849135DA2AEULL, 0x3D8670307524D789ULL, 
            0x201D4C05D82C8679ULL, 0x9507E5305E56B280ULL, 0x609A6B6AA5AE6751ULL, 0x7D9981E9520FF44FULL, 
            0x4398689D1D372D60ULL, 0x4439E1E54864A958ULL, 0xB3429C5B286F5625ULL, 0xF7A1ED1F4A9CA88AULL, 
            0x3CDBCE27E57436DBULL, 0xDC2C2063DA62AABAULL, 0x28C51D192B0AA5D1ULL, 0xF3F2E9BDA6A5382EULL, 
            0x1FCEC2935309CD70ULL, 0x14B7264CA3DAAD20ULL, 0x9CB902F1A392C16BULL, 0x7FC88C6DAB63467FULL, 
            0x9664782CD40E320CULL, 0x830AB6A69EAB1678ULL, 0xE3EECAE992663E86ULL, 0x15CA239FD04BFD3CULL
        },
        {
            0x706D2A7AF2A991ADULL, 0x7DA2FD43BCC394C8ULL, 0xFB8117C1F3C3C10EULL, 0xB8A1D48C68A92363ULL, 
            0x449AA5A6C37628B2ULL, 0x794B15AFF835B365ULL, 0x12B0AFB644AD5496ULL, 0x91A0E62B932EECD1ULL, 
            0x9049D8D670638845ULL, 0x1983C901E609E10BULL, 0x4794F3884CC38A06ULL, 0xA57F83ABF8E45F68ULL, 
            0x94E68F0E68282DABULL, 0xE4C07C05BA291628ULL, 0xC5954E7F0A43D6BCULL, 0x8D95D57810BEC972ULL, 
            0x37A2DAC46171F151ULL, 0x6C3A72873C6D9E60ULL, 0xF7D2BEF762CEC3D2ULL, 0x7D034A93ECC51745ULL, 
            0xAAFE2EF8A5BF346AULL, 0xD174C6E12EB8D6E0ULL, 0x83C83EF76B694725ULL, 0x0B4031EBA6EA8EDDULL, 
            0xDEBFBAA71894A360ULL, 0xAFFE71D364EE49BDULL, 0x306DD25295AF6E4FULL, 0xA101338A78961A8CULL, 
            0x7FC20BDE89AA6DBFULL, 0x10CB5BA1059EBFD7ULL, 0x5839C6629B3E843EULL, 0xCD49B95637F0E93BULL
        }
    },
    {
        {
            0x9491F4034EB3C5ACULL, 0x47846ECE14F3A9E9ULL, 0xDA43C2310E28CBB8ULL, 0xDDBD5F38755E56B9ULL, 
            0xB26D6797C3E5003AULL, 0xEC647FE3DACA67ACULL, 0x0B69FCE0DBA72A9EULL, 0x325090ECB0173AD6ULL, 
            0x17F8710CBE93310DULL, 0xBE607E7736F9ACC9ULL, 0xFB0A15878B77C8F7ULL, 0x4A3ED7DEC2E80CB0ULL, 
            0x5F72CB0114E2ACE1ULL, 0xB7BAF2EB61AC6BE3ULL, 0x539C234B2A385656ULL, 0x2EDC6ABA6027410CULL, 
            0xB33FD615BB44776AULL, 0x2CA5701C222571F3ULL, 0x218FAD0BA3B36B06ULL, 0xE1A3BE8BC5C76867ULL, 
            0xF197393A536C3C80ULL, 0x74FF56A50DFA531CULL, 0x307AA040C5EC773DULL, 0x9A2312373F6D2E33ULL, 
            0xFC4FCCD6AB87ED79ULL, 0xF7DBA66CDBAEF45FULL, 0x08C16843FEE9FB4EULL, 0x2C19F15E2C77842EULL, 
            0xC2D6463C2C3D18B4ULL, 0x1B57DCA070EF41A8ULL, 0x722F33BCC2466763ULL, 0xBEA6D3A022B8EACAULL
        },
        {
            0x0C2BB76C21925276ULL, 0x3CB20C28493AB83AULL, 0x6CD50F63D582655FULL, 0xA00066633B9E6A11ULL, 
            0x58E349384F457E1DULL, 0x6EA2F16D3948782AULL, 0x8796E016AC86E681ULL, 0x4E18BC7E08131F67ULL, 
            0xB77AED2C9C2C194FULL, 0x40E7A680C8DB0BA0ULL, 0xBACC4FD25B6E8935ULL, 0x7588CA05D6375E01ULL, 
            0x7C2A65F764A2B15EULL, 0x447929A73E5449C0ULL, 0xDFAA118CEA8A2694ULL, 0x14C30A93AD63E0B3ULL, 
            0x362E6AC34A80A67DULL, 0x08CA8F81CBB06C45ULL, 0x9A1D168ACFBEEA73ULL, 0x9099E0052A025423ULL, 
            0xFB7B937BD860C8EAULL, 0x847781605BBAF756ULL, 0xFD2D2B408806C017ULL, 0xC21DC04D7E243377ULL, 
            0x17CCDAD539517955ULL, 0x93998A124BE1A4F2ULL, 0xE5B6418BD1231C4DULL, 0x4B999822A5DC1704ULL, 
            0xA7E671A3A8970480ULL, 0x9864D7EB44D5EB41ULL, 0x2AA96487ED55DF1BULL, 0xAE2E22EAC640505AULL
        },
        {
            0x54D8ABC74BCCC665ULL, 0xC44E71F5935728A5ULL, 0xA5367A2C9B45A38DULL, 0x191397D36205D5BCULL, 
            0x17FCBE328B7D73ABULL, 0x68559EE0BBC7FD89ULL, 0x3F7FA572822E5307ULL, 0xCAB9865974310352ULL, 
            0x4CEA088ADB02EA45ULL, 0xD790E45B42156B7AULL, 0x131C2DCCD674AB2CULL, 0x0F0C79AFE8908FE8ULL, 
            0xF2141EECD00DA146ULL, 0x7FCFC1EDEAA24CBDULL, 0xA3B5A0E588BD494FULL, 0xE673E65B170F357DULL, 
            0xEBF945065A4746B5ULL, 0xB1301006169E74D4ULL, 0x83BE36C420797B58ULL, 0x33068BF4E27CF155ULL, 
            0xCDAEECE975D2C679ULL, 0xD6C8129BB71DFAB2ULL, 0x5E06338ADAED3696ULL, 0x2EE451642AFB8C55ULL, 
            0x88E68FB0D074D1CDULL, 0x3445C26A01F015B7ULL, 0x1EF45F67394136AEULL, 0xEAE581E9EC819750ULL, 
            0x716696E326A103D9ULL, 0x11A07E1FD2C5FA2FULL, 0x5735940B3F8AF13FULL, 0x8E414531576FCE10ULL
        },
        {
            0x54F1C6373CC021B7ULL, 0xCD1E3E17C94DA125ULL, 0x4765116D29FAA24FULL, 0x9F59195BF17FBC9DULL, 
            0x8814D0426E371FDEULL, 0x25DC0444F1D9B85CULL, 0xA3F9ECE16FE032A3ULL, 0xB5B9D764AC30B426ULL, 
            0x76F28E13E755F2C1ULL, 0x28BB5AD09010A594ULL, 0x39C832C564E12328ULL, 0xA5AC33DCD53F1073ULL, 
            0x16ECEEB7FA4B0878ULL, 0xBECCD13512923176ULL, 0x3269895778204457ULL, 0x75F9A764E5E7B624ULL, 
            0xCF5E14007EC4D5FFULL, 0xED62E187204C1124ULL, 0x4E569C9020DDDE4AULL, 0xA77FBB31A80F0514ULL, 
            0x43F5C567F183C80CULL, 0xCCADF0CF3FF13360ULL, 0x119952E7844D0E35ULL, 0x11F4F12B8F8C6500ULL, 
            0xBCB6DCA430061517ULL, 0xFDB96C54D811FFB2ULL, 0xA3A73555AC7B26DEULL, 0xBD363A4B672B2D8BULL, 
            0x9B2C3B08F2E8C451ULL, 0x2C5EF3619B1BDC51ULL, 0xA9835B7A0C91AC11ULL, 0x72E9E1B8522C1038ULL
        },
        {
            0x11F564619ADC7AB0ULL, 0xD2C5B73CF84E8036ULL, 0x3E827DBDD11E2D24ULL, 0x6296B6CD2E6ED536ULL, 
            0x7E7CD9F75483E0E9ULL, 0xD8BBA2A0B77FDC57ULL, 0xD709545987E0B8FFULL, 0x7B59E25E5A4DAB6BULL, 
            0xC510F6CD27F68197ULL, 0x78CA441AAF045E89ULL, 0x92C5CEF38743BE68ULL, 0xF5FAB12362AEC752ULL, 
            0x41B42A0677FD94F3ULL, 0x4A77135CB70C5566ULL, 0xED37424127D2D313ULL, 0x036AA12915D48FE0ULL, 
            0x32D1B22A08673370ULL, 0xEB120916AB829BABULL, 0xE206B1B7DD81628FULL, 0x256776E862FBCF1AULL, 
            0x431E92EC5E456FB1ULL, 0x83634D0C537ECEDAULL, 0x384E985E57918394ULL, 0x1926A5AC77CC39E7ULL, 
            0x995415EFDD718A9AULL, 0x626135B1CEF6F51DULL, 0x8575C2435F38572DULL, 0xFB7B8ED1A9297F39ULL, 
            0x694822EAD17CFA8FULL, 0x68430E7CBD1F5CC6ULL, 0xC0E183A08A71EAFDULL, 0x4C1D21484136F2F5ULL
        },
        {
            0xA5403FCE137310BEULL, 0xAD9C6457462C507EULL, 0x6FC695F4ACE7DB47ULL, 0x2A1760A700955934ULL, 
            0xDF832519C8B66725ULL, 0xEB961A295A42B9B8ULL, 0x726A6CC14C0A5EA1ULL, 0xA7BDEE344AB50297ULL, 
            0xFA635BBD552FEF9AULL, 0xCB94EBF63178AC3DULL, 0x44E345447E9A2F2DULL, 0x8ECA45CA6636302DULL, 
            0x9FB501F33D4EBAFEULL, 0x55607B6F3A40C939ULL, 0x05327753A7CB184AULL, 0x293CB4A39A96571BULL, 
            0x921BA8619EFF9010ULL, 0xE09567C0AB50DDB2ULL, 0xF52CB331C899A466ULL, 0xFEAB65ED5E237484ULL, 
            0xE32229D7A198DCC6ULL, 0xC55B0108ADB0A620ULL, 0x8655F6BCE1B51ABDULL, 0x1F24A6A4468F274CULL, 
            0xE4A4C88FF5614446ULL, 0x7D1FC74A5B1B0829ULL, 0x6EAE37A9604B32E7ULL, 0x4FA5C7F3ABA146D2ULL, 
            0x03FCBA9F4806DFD7ULL, 0xFF1D3D552577A6D7ULL, 0xA5EDF93C48C68B01ULL, 0xE5F4E6121FE674ECULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mirfak::kSeedConstants = {
    0xFC0B1150EC0EEFFDULL,
    0x1E7F11E26D21BA16ULL,
    0xDFF17EFCBBF33AE2ULL,
    0xFC0B1150EC0EEFFDULL,
    0x1E7F11E26D21BA16ULL,
    0xDFF17EFCBBF33AE2ULL,
    0x5C7D095555978D8FULL,
    0x55B3BE7229AFD975ULL,
    0xAB,
    0x3E,
    0x97,
    0x31,
    0x3E,
    0x5A,
    0x68,
    0xB8
};

const TwistDomainSaltSet TwistExpander_Mirfak::kTwistSalts = {
    {
        {
            0xD1057AD249ABE02DULL, 0xF7C7E278A265533CULL, 0x8BE59E822C4E1671ULL, 0x9D07243FB5CE874FULL, 
            0x29B166D07F5149AAULL, 0xA3F9E1D924D14A46ULL, 0xC5C81C7895EB8349ULL, 0x3E71FFE958323F40ULL, 
            0x83D766A95F6BFDC5ULL, 0xABC928963444C172ULL, 0x418D8D6297CA6A8CULL, 0xE8D1EF981B1167D5ULL, 
            0xC9F6D5FFF0ED0DCAULL, 0xDFDB3292AA36D68BULL, 0x8B38F9C67A35C9A9ULL, 0x01A65910AEA77363ULL, 
            0x90EFA01E51F475D8ULL, 0xF2F24564AC3F8641ULL, 0x50B99E596DA935F0ULL, 0x3559C24568A98C54ULL, 
            0x7B5884D4549A64A6ULL, 0x1CB5E2BB20E66EEEULL, 0xC5711C2C3DD207AEULL, 0x6A8CF1EFEC68E009ULL, 
            0x55140024FDBB558CULL, 0x4AC4AEE53B13D330ULL, 0xC7EB8BFC27A8152AULL, 0x6E8082787B3DF972ULL, 
            0x98571443642BA06EULL, 0xDDCDF654091FC1F9ULL, 0x434E3EF2151D15CBULL, 0x855CCD6CBE0E1D71ULL
        },
        {
            0x5037E41B9C4F56F0ULL, 0xEA7B1E44A58C8ADFULL, 0xB9004D964CA4C0BBULL, 0x710B25C328649596ULL, 
            0xDBB9192C813FA3C4ULL, 0xAF8B6FDB40C3CEE9ULL, 0x89279D4EBF06FECAULL, 0xAC52C10F4A83FA1EULL, 
            0x1A9666638C54F87DULL, 0x31E09B468288C893ULL, 0x91B07252EC788CD3ULL, 0xC2A87401A26EFAECULL, 
            0x1249BDB9C38CA60AULL, 0xCF42818A7403CBA9ULL, 0x1EBBEEFBC95F958BULL, 0x15B1A9158D14752CULL, 
            0xF24195063F739848ULL, 0xF642C0BC536CFF58ULL, 0x8170744021858381ULL, 0x33522736B9D0CDBFULL, 
            0x921A62C10D3F3311ULL, 0x7A48417E2075CDE1ULL, 0xCEE57980305D0C64ULL, 0x07915044D430F0ACULL, 
            0xAB2833D9BEA1DFD9ULL, 0xA52C6F0E8EC22932ULL, 0x2E857F9BF625D167ULL, 0x40B6DD6A28437B61ULL, 
            0x887BEF18EEA44681ULL, 0xF799CCF0F303DE97ULL, 0x8806C9CAAD3E6A02ULL, 0xEE703F43D39C59AEULL
        },
        {
            0xB66953C3559720A6ULL, 0x27A3AA63255ADAA6ULL, 0x3C66203050B176F9ULL, 0x27EF1E4BA6FC9C5FULL, 
            0x9E904090686246B3ULL, 0x20E86173D7E75CF9ULL, 0xC437788BFF9361ACULL, 0x602FBE4340187CEEULL, 
            0x5031C4A7C1D24A5EULL, 0x26B620395FDFB0C2ULL, 0xA63DA75EE96EE7C7ULL, 0x09D65D9E6FB8B972ULL, 
            0x073BF85FE6DEEF1DULL, 0x0CCD76FDB4A70349ULL, 0xCC6CF30605F3D640ULL, 0xE44E6CDFD3EB32B1ULL, 
            0x5EF9B880278F8C83ULL, 0x39A787C9B97B567BULL, 0x42638D5938AD33C4ULL, 0x30CDECA53058F7CBULL, 
            0x6B44882A20189C83ULL, 0x785883F9517FF521ULL, 0x288FB8503BE215AEULL, 0x218C0B316978C4DEULL, 
            0xDEDDAF6B7CD34857ULL, 0x318D8FA58D308C3DULL, 0xA8888F02E3213111ULL, 0x005DD8D2872AFF05ULL, 
            0x7395C6514E4148BBULL, 0xA61E28436B15EE46ULL, 0x5F65BA0E6570476FULL, 0xD783EB00FF96C45CULL
        },
        {
            0x90DAC937AFBAFEB3ULL, 0xC2380309C51B8B70ULL, 0xECC1DD96133F929FULL, 0xC447FBB6CE0DB90CULL, 
            0xEFF314BD116FEB5BULL, 0x9D12F3D7F953C446ULL, 0x35FD12240A1F5C11ULL, 0x57C9FC797B8A4667ULL, 
            0x3EC582116523457CULL, 0x4EA7D0FB71E688CFULL, 0x947EE3BB82E61187ULL, 0xD895E9AE8C465BE3ULL, 
            0xD84082DEE487D542ULL, 0xC69936D9C17CE1D9ULL, 0xEDE809B91F113F20ULL, 0xA60E746216CB459CULL, 
            0x6ED2F04BDE72874FULL, 0x3A889BDDB2C5A0F4ULL, 0xE4CA6AAFD7F7B06EULL, 0x962DCE4382D734AEULL, 
            0xA04E1E0A329115F8ULL, 0xD5274757AD29D55EULL, 0x86B85D345B24A432ULL, 0xF9D31ED3FEA9546CULL, 
            0xCFED9893C30BBB07ULL, 0xEEE5BD1A6795DFB0ULL, 0xDB79BCA2BD0FB2BEULL, 0xF63A65BEE7641B07ULL, 
            0x6F1C07DFF9E4DD1FULL, 0xAFD3E3242C7949B4ULL, 0x64C45A5377B96200ULL, 0xD25065B6C2D8A274ULL
        },
        {
            0x4A5DADBC696E4999ULL, 0x182A417431C25FCAULL, 0xB1E3814D6222D9C0ULL, 0xBD55BF35EE803C70ULL, 
            0x207239C803002D0CULL, 0x641829D7B1392763ULL, 0xB98A809920DF7E58ULL, 0x1B580F0E61A74F55ULL, 
            0x1E48F3502B8FB9E0ULL, 0x0202C02E90413A5BULL, 0xFE9165E5C55C629FULL, 0x4CA9D8555F8FD44EULL, 
            0xFD8E61D032AC4BC7ULL, 0x4A44574330F54DC7ULL, 0x9843EBAA423D252EULL, 0x6FB71768F401A3CCULL, 
            0xA1ED984863DCCBD1ULL, 0xA0668D93780F021AULL, 0x186E0FC8EB199D12ULL, 0xED6030E5058E2F4DULL, 
            0x604A19D322904AC3ULL, 0xEC306BE2CDA27012ULL, 0xDC069D87DF313037ULL, 0x25CAF2B095AF56ACULL, 
            0x54954846D08F3D4BULL, 0xBD2CE67F65DC99A4ULL, 0x61C9E2D0226E09F5ULL, 0x8A02B7CE86CC7D2EULL, 
            0x53DE12930E337301ULL, 0x93C5A89406286173ULL, 0x6DA1BBFE84E8072AULL, 0xD5C883A37BF07E44ULL
        },
        {
            0x4DD0EC1551C98D00ULL, 0x80496CEDBD6D82CCULL, 0xB2750C7221F89F6CULL, 0xE1024D4A6CDE4419ULL, 
            0xAB32804052FB9DB0ULL, 0x26453B4797E4F142ULL, 0x550B4BB8A6124B58ULL, 0x540FCDCA948B08A2ULL, 
            0x6049B0649CD3B6F2ULL, 0x40D0D8F5D50F1B1BULL, 0x6EEEB5C51547E952ULL, 0xFBAD39D3C7639F10ULL, 
            0xC2B82DD24066A687ULL, 0x56A09E6D25E9C5D8ULL, 0xAB6EE66DFBC00B4BULL, 0xB76BCF27AE7CA47CULL, 
            0x399369AB8290BE3EULL, 0xFA9E4F5E672CFA6FULL, 0x523DBDB82641AE27ULL, 0xF84A9705B77D6C7AULL, 
            0x362384962E1A95DFULL, 0x6648F531BF57CE23ULL, 0x0D66E61143A61532ULL, 0x9E26A285A6E51D30ULL, 
            0x822C2EADD6DA6049ULL, 0xE2C98FF111FAE28CULL, 0x9B3D952BEE33ED30ULL, 0xC064B31181D5B69AULL, 
            0x0D7B5CB4C6C31928ULL, 0x7A81CEE7C5B09523ULL, 0x521F6DA4B8D15FCCULL, 0x1EB2822DFFCF5887ULL
        }
    },
    {
        {
            0x352229CAFFE95E48ULL, 0xF63FA577AFB8BE6EULL, 0xAA95B17A631FFE7EULL, 0x5DB3D4EAF3D1ED63ULL, 
            0xCA3BB9D7F5F7CA3EULL, 0x3500752CAE305985ULL, 0xC503CC2B914CB514ULL, 0xF4901EC77878F4FBULL, 
            0x070364F99F2809DAULL, 0xDADC6E5F16947EFFULL, 0x7A3C54108E466838ULL, 0x9DACCE28ED07A5B1ULL, 
            0xFA389AE18676B766ULL, 0x0C636CCFD414F576ULL, 0x3BB076E660A0C36FULL, 0xACA7599943F9B89CULL, 
            0xAE903D3D80FCA4B4ULL, 0x1DF5414C96F08A33ULL, 0xFB1F905838E06B3DULL, 0x2D577292BE59E3FEULL, 
            0x3F4C3B6BFA4C970BULL, 0x8CEF0379938EEF94ULL, 0xEC3CFED5FEE77534ULL, 0xDF7CAA2FC636B3AEULL, 
            0x805EE79EBE7EB978ULL, 0x677FCB03A0AB3971ULL, 0xDE07BF9EB5198AECULL, 0x92FC98961ED818D5ULL, 
            0x44DB8916BE69EEFEULL, 0x844474DD0665F1B3ULL, 0x21E4FC955CC53AC9ULL, 0x7721BB2AE4DE1D9BULL
        },
        {
            0x6197632204C2E98AULL, 0x0FDAE7645101C8F4ULL, 0x6256362D4B9A0950ULL, 0xDDB5175E77576835ULL, 
            0x16B3062D1C0B39EBULL, 0xBAC89C6719E63AD2ULL, 0x906D5806460B82CBULL, 0x3F7146071CAE7D92ULL, 
            0x50A2AC78D6C5A4D2ULL, 0x7D13EC6F2614F888ULL, 0x9501894FC06FECCDULL, 0x2709F012E3559DF6ULL, 
            0xF5539353A0722628ULL, 0x5CCCB48B2090391DULL, 0xCC1C47034902DBADULL, 0x6BCC2B354150E11BULL, 
            0x98AC66D31B5A34C0ULL, 0xCC8465ABDC0D2B42ULL, 0x7580FCAC2B9CFDD5ULL, 0x7593434BE6806FEEULL, 
            0xF6B951B764B2EF30ULL, 0xECAB0F2D9F89EAC1ULL, 0xF25561F1A5A3F319ULL, 0x65B509055E217E65ULL, 
            0xABCECF484FFB74B6ULL, 0xBE587D46971BE864ULL, 0x27913C8E5AF4EA6CULL, 0x537A68885CAEFF44ULL, 
            0x46634EF5201DBBFFULL, 0x07D740D0FE26BC50ULL, 0xE6C89ADBF0B9D7FBULL, 0xE85B4C41E71E862EULL
        },
        {
            0x6623D50D232ED914ULL, 0x0ECA9A2A3157928DULL, 0x94D97435B29CA323ULL, 0x6EFC99301E88C954ULL, 
            0x423A8DDBADED843DULL, 0xAC02EAF2E0BF525EULL, 0x9FB67D504C235C64ULL, 0x608D1134379F111EULL, 
            0x7ADCF1705D37EAD6ULL, 0x8A7B6193AF729E9BULL, 0x12E1A8CFF1D91C8BULL, 0x357C17D8E8B73DF5ULL, 
            0x7A0BE8F23BBCD2A6ULL, 0x6002969D573C9A68ULL, 0x6436A22F4994C000ULL, 0xF3B3374EAF8D96FDULL, 
            0x98C01A73690B81CEULL, 0x6A3636DF6B45FF23ULL, 0xC605658CDCE4C8E6ULL, 0x17801598A22DE7E7ULL, 
            0xBA67FA1F002E194BULL, 0x52B56C007A133DAAULL, 0xFBFDA1B9A4E7812FULL, 0xDE1FEF92F38B9949ULL, 
            0xECDEA596E6D32E4CULL, 0x50225E9CF42D5388ULL, 0x14568A2C6F3C817DULL, 0x62E5D7A8479D2C4CULL, 
            0xF4B12F923EE39674ULL, 0xDF5B25F93AC21309ULL, 0x299C62226862406AULL, 0x508A70E7654347FDULL
        },
        {
            0x6D94CC348B19B4B6ULL, 0x532DAEAE3E9D47F9ULL, 0x7BDE13869B09C74BULL, 0x20B0B053286A74B6ULL, 
            0xC05C455B342E9C3EULL, 0x719E4F1D250DB217ULL, 0xE9198D738F034C22ULL, 0x48C027ABC1FB3475ULL, 
            0x7954603305967D3DULL, 0x595C1A15A61ABE80ULL, 0x40D12F2D0CF1AA2FULL, 0xBDBB0EA5086458B6ULL, 
            0x5A5C4FA9BFA5CB4FULL, 0xFBD251E13D14A658ULL, 0x41DF7F4424E73025ULL, 0x5B77AE4EA41ACB6EULL, 
            0x590BB88B9C70D13AULL, 0xCB46C374985D7266ULL, 0xC0DAAFF7C7964FBCULL, 0x06EA619A5AE1566CULL, 
            0x42490CBC094ABD0EULL, 0x41C5062466909EBDULL, 0x0A141A5D0FA1B5F3ULL, 0x16F7261267497A5CULL, 
            0x2138A16BA67D9C6EULL, 0x8EC3D43590FDEA44ULL, 0xAC86DD0C84E507F0ULL, 0xB7CE764B3887F167ULL, 
            0x54A14A876E06CEAEULL, 0x04B491F906A8C028ULL, 0x5DF0E2CEA984B7AEULL, 0x19DE6DB201CE82DFULL
        },
        {
            0xCD40A140670E3B96ULL, 0xC74A98E9CDF2B9B2ULL, 0x19493DDAFF83225EULL, 0x0AF20028AF5ABA50ULL, 
            0xB42A2E4748417D9AULL, 0x0DF78FC4E877AFE1ULL, 0x48ED2E16CFA3AD3FULL, 0x2126C13A02428894ULL, 
            0xBBF49846E582A08FULL, 0xEFA2522119804EE0ULL, 0x640E1442916872DEULL, 0x538E4E7F71C863B3ULL, 
            0xFDBBC40C81F251E2ULL, 0x3816DA968A151978ULL, 0x055FFF4D0580F08CULL, 0x98183E5BE30450E0ULL, 
            0x7C38DDC3789F6FDBULL, 0x19036EE94E2F8E1EULL, 0x24BD4B0126883471ULL, 0x48F2C54B3023A15AULL, 
            0x3B4FFD467451B1ABULL, 0x379D8F3AB2DC0AFBULL, 0x13EF6FF773C1307FULL, 0x160B96693ACC8197ULL, 
            0x38360FA233E73566ULL, 0xA662496018827CCFULL, 0xB9E255EAA40B73E3ULL, 0xC3D7F5A2E69E131FULL, 
            0x12DD6592268607E4ULL, 0xF39E4FFE03662AFAULL, 0x5A868281B391DC84ULL, 0x2668AA5E5692CA02ULL
        },
        {
            0x529D37AD25618E16ULL, 0x1CBA2ABE0C9FA7D3ULL, 0x3897BA48B6EB2B75ULL, 0xFD91C8202A8EB5E7ULL, 
            0xE311D7A0F82D0426ULL, 0xBD25C8F93E8F6FDEULL, 0x12E8C5785EDEC49CULL, 0xD55296F49FB164C4ULL, 
            0x5FCAFB870F689A2CULL, 0x78688EA184B9F083ULL, 0xB98B917AD120748CULL, 0x5D7627767695101EULL, 
            0x233FEBBF10D2DEE9ULL, 0x73646C4FD41E5F13ULL, 0x7B6727050F31FC3BULL, 0xA3BF45A51766F45CULL, 
            0x99B310C9413BD5BBULL, 0x2502BFEFA4EE7BF8ULL, 0x2CE7FBD2F00AC50DULL, 0xE1FABBB66A068F26ULL, 
            0x2332F5C835D10553ULL, 0x1FAB9380BA6E8BA2ULL, 0x5477A20A6C20D699ULL, 0x4A7183CACA1D4924ULL, 
            0x2F902D7E67B921D6ULL, 0xF43F6BE989453503ULL, 0x3EBBD844B81A098CULL, 0x30F21A6DEE7DF9D9ULL, 
            0x2684FAEDFE4CA626ULL, 0x2FFCAE491173E0BEULL, 0xF03C10DF57D7C223ULL, 0x6FC1EEA63A19BFD2ULL
        }
    },
    {
        {
            0x70516D137A3C858EULL, 0xDF2F54E69E8F9E4DULL, 0xC708CA6BA8B76AEAULL, 0x847CD6AB77E2A6C4ULL, 
            0x3885961D8AC73FE5ULL, 0x822DFBCAE46F84B6ULL, 0xF6E8474206573EBAULL, 0xCD99B71F454B8DD5ULL, 
            0x47AB2A0C2F971A3CULL, 0x46632F1FD242CB26ULL, 0x5F8AF1E36A726B62ULL, 0xD4EB8DE512E39086ULL, 
            0xC46016F695D66D28ULL, 0xD21B6E6E1E821503ULL, 0x3C68034B728E6108ULL, 0x3627E0244E3CA2D2ULL, 
            0xE9902E13EE433AC1ULL, 0xC42FEA37D3087F55ULL, 0x8B8F50FCFB4FFC44ULL, 0x8431C0714765EF21ULL, 
            0xB818E78839A11A34ULL, 0x172635E082E5BB2CULL, 0x659C395A1AEBBA0EULL, 0x1DC65C0E9E6337F1ULL, 
            0xA10DA308FB12775BULL, 0xC4529C24E80785A2ULL, 0x093FBDF4993EFC95ULL, 0x3EE646ACBC1D3F5DULL, 
            0xA814F9A53232B0C6ULL, 0x95E8B6C2B76554EEULL, 0x87C94ED567DFC7F5ULL, 0x6B7FB97A18A791BDULL
        },
        {
            0x789295A6B018FD91ULL, 0x6C744EBD51E0C6CFULL, 0xF51ED05777AE0A69ULL, 0x54D1959D3918D9C1ULL, 
            0x9F2C9B448BC1D3D2ULL, 0xC7684A098F071EFBULL, 0x1495083E86139529ULL, 0xC1F796B485FBCDF4ULL, 
            0xEA09B6DDC152D9C1ULL, 0x3C52302554A40D4EULL, 0x085B2A6C78619C42ULL, 0x4E3C452C6EE943BBULL, 
            0xF2F8A3B8FF91A7ECULL, 0xC25600F53A5A47EFULL, 0xDA545A085731D0B6ULL, 0xF06E985D528FBBBAULL, 
            0xFB59B119694111BDULL, 0x074092F14773B657ULL, 0x9E72EBB75A451BA5ULL, 0x200BFC6849A3D8A7ULL, 
            0x9F994C9A721E1F8AULL, 0xD8C6B4709199332BULL, 0x326C2108C347C611ULL, 0x486602EA4D9DD305ULL, 
            0x551B50ED226D92A1ULL, 0xC60F9152B7AB3AEAULL, 0x93FC78D050BD7F9FULL, 0x1F01EA60230C2A68ULL, 
            0x2BAF1EC7869DEEE6ULL, 0xAEA8BBC17E489202ULL, 0x21628111EAFCAE26ULL, 0xD7702C4DCBA66A41ULL
        },
        {
            0xA944F33B5FB7EF87ULL, 0x4E8CF6B86202C56EULL, 0xBD2F462F51C5B197ULL, 0xF820F8AD6EC6ED74ULL, 
            0xF3EF5E72AC4EF9DDULL, 0x725252D0E53025EFULL, 0xB65976FEF20135C5ULL, 0x40D1965F2781CF1EULL, 
            0xD44D9D52B6B0D1B1ULL, 0x424DC4AAF7D21019ULL, 0x25035F5269CFF215ULL, 0xD5758BFE12E778E2ULL, 
            0x22FAB215BED8700AULL, 0x6A853D2253EF88F0ULL, 0xDC3702D2FDE54442ULL, 0x6C235B5C7E446F95ULL, 
            0xE5DF506884947C6AULL, 0xF0F299C580FD5684ULL, 0xE2D12D9DB73B1423ULL, 0x3FC78BE04CACAF85ULL, 
            0xE8627E3FDB71B79AULL, 0xFB5EF7EEC23DC67FULL, 0xC32FFFA7A6264920ULL, 0xF60262D7AE2793F0ULL, 
            0x84B74A352CD09BC0ULL, 0x449CFB54B4D55D5EULL, 0x6319B1B7F2B9FC9DULL, 0xFD58DE9BFC6C5B8EULL, 
            0x71615A10F9C803FBULL, 0xBA7555A2EC796521ULL, 0x00CE185AC0080246ULL, 0xD33C93D5395114E5ULL
        },
        {
            0xA07D64DAF0E6DC09ULL, 0x6AF11D83A183EC6EULL, 0x925F2E7A1FE68949ULL, 0x2E951A1C82DCFC19ULL, 
            0xD4B795DE81B3F708ULL, 0xA4D1D62D2B5E7190ULL, 0x2796C8AF316D4B19ULL, 0xC37FC03404132E87ULL, 
            0xD6DAE5587825E69BULL, 0xAAD281CB304DABD9ULL, 0x16F19ED8F29EDC2FULL, 0x5868F77B65348ED5ULL, 
            0x9A30D9D7894FA341ULL, 0x9653F082693AF357ULL, 0xBE2A17FA1881DB00ULL, 0x7FB1D8A72EAA9FEDULL, 
            0xF918E59EAE5464E6ULL, 0xD431651300294F80ULL, 0xBC7BA2AD70A27A95ULL, 0xF961BF181842B27AULL, 
            0xC002B6851A470C67ULL, 0xC09A3138A3F90BCAULL, 0xE1022E4554BDC758ULL, 0xC77D94624979767DULL, 
            0x99D8AEC87FD9C6ACULL, 0xA0E785ED98719FD5ULL, 0x12C6E4C34BC4D5A6ULL, 0xA671DACD6095F197ULL, 
            0xBE78BF20749086B2ULL, 0x1BBB6035065A63FAULL, 0xD833CFF59B97B99CULL, 0x77989E6094796AAEULL
        },
        {
            0x5F378AD14A5D47BFULL, 0x5992C4F2061CD90EULL, 0x7D3CA02CD6D42262ULL, 0x917E8E5CB8140265ULL, 
            0xC1CF891EA89F5B80ULL, 0x862487D42A8D8DADULL, 0x7707BA060B30D565ULL, 0x4C9616A2F09C1FDAULL, 
            0xDA533479C5246C06ULL, 0xC8E99BC597B400F5ULL, 0x99618C4CA7E66FE0ULL, 0xDC418BD2483AB543ULL, 
            0xA635E1921EF54387ULL, 0x2AF0A3781EB20057ULL, 0x7F11AA979B1A6535ULL, 0xF80E8099559479DFULL, 
            0xA4AA0668A7E4DF92ULL, 0xF9827FD6B1F59862ULL, 0x0037F7C758E8135EULL, 0x89B66E42E01158E0ULL, 
            0xE60B4534487C6F90ULL, 0xC1F5417237F4780DULL, 0xFBF07EC5A2428E2EULL, 0x561E83C186B55D09ULL, 
            0xF952BD7D76B43B08ULL, 0x47D59A742D57FDFCULL, 0x7F8980EEF785BA99ULL, 0xED0A461A297A8CF2ULL, 
            0x42EB2CB47607798BULL, 0xABFF3649092039C8ULL, 0x8A04B4E3D0A24509ULL, 0x763C027DC15349A0ULL
        },
        {
            0x2EE7E97A2F93014EULL, 0x2E981AD722B0167CULL, 0xAC09F6BCAD0B7ECEULL, 0xA9F1CC80F9405373ULL, 
            0x98506688F7723628ULL, 0x35E58B1C5A9136B8ULL, 0x3D0785B89A198775ULL, 0x4CCD10FAD9411C99ULL, 
            0x907A58966C17A624ULL, 0x723C385E1938B365ULL, 0x960D3728F7A75554ULL, 0x7C863CA6A3BC7D18ULL, 
            0x1D59BE88C5FDD9EBULL, 0xC1144BF06E2F7FDEULL, 0xB5A8082FBA2DF9C0ULL, 0x31C10B10964043CCULL, 
            0x3164FD4BE67DD6B9ULL, 0x9BB862DC8014F99DULL, 0x734DE6CACCC52637ULL, 0xAE91A032A2CB21BCULL, 
            0x241566EB233045BDULL, 0x6F38F759EAF5253BULL, 0x7D19A80592CEBF78ULL, 0x1E5EA155C2677378ULL, 
            0x18AF8B809DB32658ULL, 0x23583F72E1F70F29ULL, 0x5D6A57903318A49FULL, 0x8E5A37157FAA75EAULL, 
            0x74AF3730AAC0679CULL, 0x6502A5BFA06A65C6ULL, 0x6FD75523FF86936EULL, 0x13A5A6A80F9DC526ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mirfak::kTwistConstants = {
    0xA703142A1B1567BEULL,
    0x7C45A694A5A79164ULL,
    0x31B62D8DB012CD07ULL,
    0xA703142A1B1567BEULL,
    0x7C45A694A5A79164ULL,
    0x31B62D8DB012CD07ULL,
    0xD9C93CD5E90D0593ULL,
    0x31F89EAEC391950DULL,
    0xBF,
    0x6F,
    0x6B,
    0x8E,
    0x2C,
    0x3A,
    0x4F,
    0x85
};

