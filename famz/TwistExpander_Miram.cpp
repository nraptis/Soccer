#include "TwistExpander_Miram.hpp"
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

TwistExpander_Miram::TwistExpander_Miram()
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

void TwistExpander_Miram::KDF_A(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Miram_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Miram_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Miram_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Miram_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Miram::KDF_B(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Miram_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Miram_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Miram_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Miram_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Miram::KDF_C(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Miram_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Miram_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Miram_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Miram_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Miram::KDF_D(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Miram_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Miram_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Miram_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Miram_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Miram::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA267959EFEC38496ULL;
    std::uint64_t aIngress = 0x81DE97CFAA08717FULL;
    std::uint64_t aCarry = 0xF02238C2A72F53FAULL;

    std::uint64_t aWandererA = 0x9688E2447E2D05BBULL;
    std::uint64_t aWandererB = 0xCBC07CB6AE0CB13AULL;
    std::uint64_t aWandererC = 0xD4C014641D9A1BCAULL;
    std::uint64_t aWandererD = 0xA0F083AED82D5805ULL;
    std::uint64_t aWandererE = 0x83CCF4E6CAB64BDBULL;
    std::uint64_t aWandererF = 0xDD6055FDF1E8B961ULL;
    std::uint64_t aWandererG = 0xE00D4F3B5193122EULL;
    std::uint64_t aWandererH = 0xBAEB3043AF629664ULL;
    std::uint64_t aWandererI = 0x803E05DDB33AA591ULL;
    std::uint64_t aWandererJ = 0xADF6CFFAEF9CF0CDULL;
    std::uint64_t aWandererK = 0xEB13EADD07BBD497ULL;

    //
    // KeyRotate A
    //
    aPrevious = 0x99FB0BD70A6E1713ULL;
    aIngress = 0xD784DD9E9DB3BD26ULL;
    aCarry = 0x829FD45B53CE0124ULL;
    aWandererA = 0xD4AFAB05BF567FB1ULL;
    aWandererB = 0xAC9DF6423FF2FA93ULL;
    aWandererC = 0xF8464F070F537689ULL;
    aWandererD = 0xF01C7040E9865191ULL;
    aWandererE = 0xFFDDD64C4B929320ULL;
    aWandererF = 0x853E6241A895FD2BULL;
    aWandererG = 0xBADB90F7C398DFF5ULL;
    aWandererH = 0x9045B0EA496C3C08ULL;
    aWandererI = 0xF70DC392FAA8F42AULL;
    aWandererJ = 0xA54D9E1F04F049D3ULL;
    aWandererK = 0x94FF90F025F9D305ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateAConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xC86CEFB8C0EBC093ULL;
    aIngress = 0xC322CF80B1D5E99FULL;
    aCarry = 0xFCA7B50ADA1F0AA5ULL;
    aWandererA = 0xFABB8A694F906FEBULL;
    aWandererB = 0x8909ADF6F537D40AULL;
    aWandererC = 0xF444DD6847E02C65ULL;
    aWandererD = 0x84308C61498C7325ULL;
    aWandererE = 0x9F10F5BC2019F0B2ULL;
    aWandererF = 0x8D7D781DB2F86E76ULL;
    aWandererG = 0xC7FE49BE10B85353ULL;
    aWandererH = 0xE2EE38A18630E129ULL;
    aWandererI = 0x8BB718DC000576A4ULL;
    aWandererJ = 0xC7BCE796E6A7223CULL;
    aWandererK = 0x851617F1A0C6A887ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0x885A3EE8A2781CE3ULL;
    aIngress = 0x8CFB00D25CA94136ULL;
    aCarry = 0x86E8F28EF94AA7E0ULL;
    aWandererA = 0x8AA0F88E255787CDULL;
    aWandererB = 0xAF94F99A15D3BAD0ULL;
    aWandererC = 0xBDCDEC6D58D5C1F2ULL;
    aWandererD = 0xB729BB071DC62829ULL;
    aWandererE = 0xCAD8C97E4CA8B71BULL;
    aWandererF = 0x9866843AA05D4D19ULL;
    aWandererG = 0x8FE1BBA30A42FF84ULL;
    aWandererH = 0x849704A1BFE00F95ULL;
    aWandererI = 0xE34121609C939446ULL;
    aWandererJ = 0xFF01AD931B105868ULL;
    aWandererK = 0x85BAE4FAE59C5A8CULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnAConstants), &(mDomainBundleInbuilt.mKeySpawnASalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnAConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants), &(pWorkSpace->mDomainBundle.mKeySpawnASalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeySpawnAConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0x888772EB702148EDULL;
    aIngress = 0x8681247FEEB05004ULL;
    aCarry = 0x95C9DFF25FE3F84BULL;
    aWandererA = 0xC8C95E122E84AD8CULL;
    aWandererB = 0xFC87901249DA602AULL;
    aWandererC = 0xDEBEA7889592CEE9ULL;
    aWandererD = 0xC0AD852A2551299AULL;
    aWandererE = 0xBEA261E915F3CA40ULL;
    aWandererF = 0x81075DA9C7808829ULL;
    aWandererG = 0x90E09AE4DBAC27C3ULL;
    aWandererH = 0xDD9DA29F8336E128ULL;
    aWandererI = 0xDA1407D6A8344EA3ULL;
    aWandererJ = 0xAC4B95AB2D0EEDE7ULL;
    aWandererK = 0x9A7C8928DE2FB8A5ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnBConstants), &(mDomainBundleInbuilt.mKeySpawnBSalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants), &(pWorkSpace->mDomainBundle.mKeySpawnBSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xFE03655EFF6E7B01ULL;
    aIngress = 0xBD8883E10CFB7F82ULL;
    aCarry = 0xAAC0B60D932CC931ULL;
    aWandererA = 0xCB887084A4A2CFA8ULL;
    aWandererB = 0xB183437DD1DCBE59ULL;
    aWandererC = 0xCE2E39A46CAEF815ULL;
    aWandererD = 0x82C6E39A684C8F42ULL;
    aWandererE = 0xE65EDAD0CEAF1CE2ULL;
    aWandererF = 0xC7F6FFE0AFA4C9F0ULL;
    aWandererG = 0x83370C012B8ED0E0ULL;
    aWandererH = 0x857F4C854618BE0AULL;
    aWandererI = 0xE81C8479FEF42D81ULL;
    aWandererJ = 0xFC0DEE902234FF1EULL;
    aWandererK = 0xC1F348FB55FD7BC7ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mTwistConstants), &(pWorkSpace->mDomainBundle.mTwistSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mTwistSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xA18E85C4AEACC9B1ULL;
    aIngress = 0x87BFEE2A931253E7ULL;
    aCarry = 0xA150A5BA289AB122ULL;
    aWandererA = 0x96948AD7DC016906ULL;
    aWandererB = 0xC7AA03331F60C64AULL;
    aWandererC = 0xD01E848EC376F4F7ULL;
    aWandererD = 0xD63BE1457DE81967ULL;
    aWandererE = 0xED5744DBBAB3A284ULL;
    aWandererF = 0xD271268A27F05CDAULL;
    aWandererG = 0x8E0EB587FE7A5BCDULL;
    aWandererH = 0xB5720141E8EE1A21ULL;
    aWandererI = 0xC3214B35CA4AC225ULL;
    aWandererJ = 0xB81CEB2B9815835EULL;
    aWandererK = 0xE741C4ACB86FF0DDULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mSeedSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xA11A0D0E02414138ULL;
    aIngress = 0xCDA1BA8E7D453DE7ULL;
    aCarry = 0xB7CC8C989DBEED98ULL;
    aWandererA = 0xEFAF244F34CC55E8ULL;
    aWandererB = 0x8E070EF9C3AB7C85ULL;
    aWandererC = 0xECDDE5752749C441ULL;
    aWandererD = 0xBD0187B43190F886ULL;
    aWandererE = 0xF435BECCC2C5E49DULL;
    aWandererF = 0x8DA6E8F01E2B87D8ULL;
    aWandererG = 0xB3D873A704253E93ULL;
    aWandererH = 0xC2D277B50CB141A8ULL;
    aWandererI = 0xD3A5667F00C1FB49ULL;
    aWandererJ = 0xE2E71B22A1C1039BULL;
    aWandererK = 0xA3A341EBF9106D1AULL;
    //
    TwistExpander_Miram_Arx::SEED_A(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Miram_Arx::SEED_B(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Miram_Arx::SEED_C(pWorkSpace,
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
    TwistExpander_Miram_Arx::SEED_D(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Miram_Arx::SEED_E(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Miram_Arx::SEED_F(pWorkSpace,
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
    TwistExpander_Miram_Arx::SEED_G(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Miram_Arx::SEED_H(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Miram_Arx::SEED_I(pWorkSpace,
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
    TwistExpander_Miram_Arx::SEED_J(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Miram_Arx::SEED_K(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Miram_Arx::SEED_L(pWorkSpace,
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
    TwistExpander_Miram_Arx::SEED_M(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Miram_Arx::SEED_N(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Miram_Arx::KEY_A_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Miram_Arx::KEY_A_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Miram_Arx::KEY_A_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Miram_Arx::KEY_A_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Miram_Arx::KEY_A_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Miram_Arx::KEY_A_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Miram_Arx::KEY_A_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Miram_Arx::KEY_A_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Miram_Arx::KEY_B_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Miram_Arx::KEY_B_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Miram_Arx::KEY_B_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Miram_Arx::KEY_B_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Miram_Arx::KEY_B_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Miram_Arx::KEY_B_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Miram_Arx::KEY_B_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Miram_Arx::KEY_B_H(pWorkSpace,
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

void TwistExpander_Miram::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x9B100FF27FD5274EULL; std::uint64_t aIngress = 0xE7635864CC33C481ULL; std::uint64_t aCarry = 0x81545C20ABA65CDBULL;

    std::uint64_t aWandererA = 0x9AE89A45C4D5AE6AULL; std::uint64_t aWandererB = 0xCD2377FF2BC7E8B2ULL; std::uint64_t aWandererC = 0xF62ECD8FF43E81F2ULL; std::uint64_t aWandererD = 0xF03CE5059AEFB7B0ULL;
    std::uint64_t aWandererE = 0xCEE4836654E0A023ULL; std::uint64_t aWandererF = 0xFD289C38C2CEE037ULL; std::uint64_t aWandererG = 0xCFF235A14A9CB09FULL; std::uint64_t aWandererH = 0xEDDA88E332F3076EULL;
    std::uint64_t aWandererI = 0xB14F90CA10997F81ULL; std::uint64_t aWandererJ = 0xB6A52E5901CA199DULL; std::uint64_t aWandererK = 0xE73AB0B613666D2FULL;

    // [twist]
        aPrevious = 0xBF954492D9A19542ULL;
        aCarry = 0xC0411B05D2D7DE40ULL;
        aWandererA = 0xDB224FF069A36CF0ULL;
        aWandererB = 0xCE9FD0AE03581248ULL;
        aWandererC = 0xD413DA8A0557978DULL;
        aWandererD = 0xC6B9E6D8E4353D3BULL;
        aWandererE = 0x8A8E43D94EDFC45FULL;
        aWandererF = 0xB1D64E7D491C3CA8ULL;
        aWandererG = 0xE6CF24713C1D5356ULL;
        aWandererH = 0xDFBB33B75F2760F0ULL;
        aWandererI = 0x8E00D3B89D4B4FCEULL;
        aWandererJ = 0xE41CD49DC3C56816ULL;
        aWandererK = 0xD2E814452C30287CULL;
    TwistExpander_Miram_Arx::TWIST_A(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Miram_Arx::TWIST_B(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Miram_Arx::TWIST_C(pWorkSpace,
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
    TwistExpander_Miram_Arx::TWIST_D(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Miram_Arx::TWIST_E(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Miram_Arx::TWIST_F(pWorkSpace,
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
    TwistExpander_Miram_Arx::TWIST_G(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Miram_Arx::TWIST_H(pWorkSpace,
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

void TwistExpander_Miram::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Miram_Arx::GROW_A_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Miram_Arx::GROW_A_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Miram_Arx::GROW_A_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Miram_Arx::GROW_A_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Miram::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Miram_Arx::GROW_B_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Miram_Arx::GROW_B_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Miram_Arx::GROW_B_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Miram_Arx::GROW_B_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Miram::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 20 of 33
    // Exploration cases: 0
    // Structural maximin 522 / 674; family total 10238
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
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7699U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4098U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7969U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7879U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1915U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1960U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1645U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2005U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1465U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1870U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1330U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1420U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 20 of 33
    // Exploration cases: 0
    // Structural maximin 520 / 674; family total 10234
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
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6979U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3018U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7249U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2928U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 790U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 475U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 610U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1150U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 745U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 565U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1195U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1285U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 520U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Miram::kKeyRotateASalts = {
    {
        {
            0xF769A09E17787664ULL, 0xA8C0C5C688620F6DULL, 0x4A36B82B80C12E34ULL, 0x22D95F5BA936DA55ULL, 
            0x70C9C58F4D299505ULL, 0xCF3D4DDA450B8A8FULL, 0x82F59BFF7F9B6CB1ULL, 0x873280FB9F1CCADAULL, 
            0x500489764826DB75ULL, 0xA18A8403125AD794ULL, 0xFD5309E4C2A3C9FEULL, 0x3171C8B88BECF85CULL, 
            0x9F08AC272D063B4EULL, 0x1CC578C120E1F55FULL, 0xC6B8002C2E5058DEULL, 0x2838FD1DA93EFA7CULL, 
            0xE89F464C3D45B90DULL, 0x2B33BF72C8628235ULL, 0xD6580240CACC9A17ULL, 0xC88455D0CB08AF22ULL, 
            0xF147229908915B83ULL, 0x2F9EF367D99CCA3CULL, 0xFE21BD3BAFE38BB9ULL, 0xBBC3C7FFAF00F6C8ULL, 
            0x0A2396847E8EF80EULL, 0x3684A8CDC8798D77ULL, 0x66584BBF13B615B5ULL, 0x8A32FC5C0F899F45ULL, 
            0x9BDAECC21E24D486ULL, 0xD4FEE7787D127BE4ULL, 0x1E35085A721A9952ULL, 0x8738DBC396B10E22ULL
        },
        {
            0xB4FEEE8FC8C06338ULL, 0x84835B95C5796471ULL, 0x650852DBDF3FB208ULL, 0xC29DA33016F0C066ULL, 
            0x20A40E82238B87BEULL, 0x7CE9088B979E6EECULL, 0x6BF049D5C875AC8AULL, 0xAD683994E45BEB18ULL, 
            0xC5A9F83DEA5997A5ULL, 0x1AC074CAA7482EE0ULL, 0x94560165E1C972D8ULL, 0xC180005DBAFA297CULL, 
            0xBCC0997D860D46E2ULL, 0xF05826B4BFF82EB7ULL, 0x275086BA5BDE8DF3ULL, 0x526F11990E337A55ULL, 
            0x2C5ED49B4D26FB27ULL, 0xCB18316B7429F710ULL, 0xC51C5DA069547C47ULL, 0x62697F41F489A856ULL, 
            0x35A3DD5A7E1EE988ULL, 0x60CF3E28B80D9470ULL, 0x5569EE41FCDC982CULL, 0x2F511323B08F5C40ULL, 
            0x710A2C7D0421C659ULL, 0x9D8CC4BB7BE4B374ULL, 0x933D7C7789437BE3ULL, 0xBD9DF9324F6CC5C8ULL, 
            0xF98F89CD27E9847CULL, 0xDD0EDE0B8B40DCDFULL, 0x8249AC7EB7B9D388ULL, 0xD337294B3D8636AEULL
        },
        {
            0x91A9B85AE51FAB33ULL, 0x667A2D1311DB41D2ULL, 0xC2655B8C0A8BBA7CULL, 0xF887CDA5D9FD49E3ULL, 
            0xEF666A0B444615B0ULL, 0x370214B3816A3616ULL, 0xA62634F1E985D09FULL, 0xEF6BB49E9CB65AEDULL, 
            0xF4129777581B4405ULL, 0x3E4B4C68799454ADULL, 0xD2A7FE229CA1ABE5ULL, 0xCB0CC86B71DA5DB1ULL, 
            0x04E00855002AFAC7ULL, 0xFCC32D3316FAD544ULL, 0x2E799E8FE564E84CULL, 0x955757A1659EBD75ULL, 
            0xCBD22CBDCB4B0E83ULL, 0x0E7D96164C25A013ULL, 0x15971CC79268A515ULL, 0xEF6794A4BAEB39C1ULL, 
            0x2CAA5E708DD312FDULL, 0x4735C609AB0FD923ULL, 0xE90E479DB65FC33DULL, 0x5A860414921417AEULL, 
            0xECE20FC9CB455C71ULL, 0xCAA84158B589D1CCULL, 0xACEBAE344FAC8118ULL, 0x91DE4D4F7FBB1C39ULL, 
            0x0C09F14CC0EF07D7ULL, 0x1634E9442A7CA046ULL, 0x061B421065AD66A8ULL, 0xE745B8F5E38E6D96ULL
        },
        {
            0x523F70AC5839A813ULL, 0x1F931469F26D36BCULL, 0x5E2524AEED2BF552ULL, 0xABAA82638F152C0CULL, 
            0x58DE4516B07CA6D7ULL, 0x02CB82D3B07D4BD4ULL, 0x29CA0F7446962D04ULL, 0x570B47E0A147DEAFULL, 
            0x47965303EC690046ULL, 0x71F411E94E6058D1ULL, 0xD4C904ED773D601BULL, 0x7F2133D2F8C9DB5EULL, 
            0x5AF3091900AE17B6ULL, 0x8DDAAA007BC75A7FULL, 0xFF8BF576223BA9CFULL, 0xDB686E65952DE479ULL, 
            0x6AF17E2E04709D57ULL, 0x3556796228178D96ULL, 0x20194EB48195BA64ULL, 0x02A92D181DD14087ULL, 
            0x5C182F6176787F93ULL, 0xD4B449E088626C90ULL, 0x16D733AA7EFAEB46ULL, 0x9AECBBBE6E3EE151ULL, 
            0x1EF390270C2D7997ULL, 0x57DE91BDC724099AULL, 0xA146821733EAAB5EULL, 0xF3822D7345F2EB1AULL, 
            0x3E39226EE168E439ULL, 0xF7DE8F2315B3F715ULL, 0x17373FAA09263ACBULL, 0xE5D0714DD3FE6448ULL
        },
        {
            0x0B631EFA6F1F56F1ULL, 0x2E1CBD7423F52F33ULL, 0x8458CE36ACD54AE3ULL, 0x855E827557852480ULL, 
            0x3AC9F40094D79773ULL, 0xC8D01A5B42223860ULL, 0xEE17FD3BA6B34E71ULL, 0x97005B9357E47130ULL, 
            0x1671C7618BB486D0ULL, 0x666D3E07A4025000ULL, 0x20469583A21E4DC1ULL, 0xAA516BA7D5565C93ULL, 
            0xE1CA536B13174A16ULL, 0x0B13220D8E1A0089ULL, 0xF1A7674F6EC8C635ULL, 0x879E2AAF29E1715FULL, 
            0xF8E34E2F3137C7CCULL, 0x2BB1DCD8D5E2DF4BULL, 0x4E8DC2D0B8B1EFECULL, 0x59591C05F648668EULL, 
            0x4A25E70B375D23ABULL, 0xEBF00719EAF44781ULL, 0xAD678AD941485DADULL, 0x307347CA505A04E2ULL, 
            0xD810BB0C7239AD2AULL, 0x026BE1FC4A0FFD7AULL, 0x6FFB4200C876786DULL, 0x6C79B1BFF8A07CE6ULL, 
            0x6D7AAD9FD9BAC440ULL, 0xD3BDDDEB71596345ULL, 0xDF45BC9281B243E4ULL, 0xB8AE402A975285CAULL
        },
        {
            0x67EDF30C7ACE5482ULL, 0x7199A9326308902AULL, 0x4D6D6D156ECD238EULL, 0xCF3093ED561D3E14ULL, 
            0xF3E047FA0CF0827BULL, 0x3506EC0134A04CCAULL, 0xB37A3071D9B57CB1ULL, 0x3CC174115C137FADULL, 
            0x098A0E603CC687E0ULL, 0x74C9DB886E0E23C8ULL, 0x5C57C8396D3FC44DULL, 0x2E2497CF8BB14574ULL, 
            0x9A4E0BFE2C777328ULL, 0x5BCB434594186BD3ULL, 0xAE01CEC3B2E40363ULL, 0xDF0E8CC4CAFDC5CCULL, 
            0xB93189575B8B9653ULL, 0x6DF500D145E35773ULL, 0x8E3E12E858D59406ULL, 0xE094D2C020BBA7AFULL, 
            0xB786BD02CCC56F85ULL, 0x8F9DBCCCC1113D7AULL, 0x755B8767D5182895ULL, 0xF4AA8CFC45E22B4AULL, 
            0x649032BCCB42E465ULL, 0x2F8272BCFA2C96A9ULL, 0x89B702D427D9791AULL, 0x3A99C7E782F214D6ULL, 
            0xBB19055900118D62ULL, 0xBFB62C28B721012EULL, 0xBD598BB84EA99958ULL, 0x06E2CC7394A661D1ULL
        }
    },
    {
        {
            0x1F5B66A73047553AULL, 0x382E93D8C9B5FF32ULL, 0x9F7BA71F53B2EC53ULL, 0xDE7405846C717131ULL, 
            0xD3266131F7C6FBE7ULL, 0x9025D498A327ACA2ULL, 0xF8ECC8F0D72548C1ULL, 0xF31AFB05F70F8127ULL, 
            0xBBAAB02F13A0C391ULL, 0xCB3BD3215E530E09ULL, 0xFD7169F14BF3D53AULL, 0x9EED5C956702D2C0ULL, 
            0x6CEF7401FA1F1914ULL, 0x79BA1B74A954611BULL, 0xF25B78A05F42DC51ULL, 0xE0EB5240499C085BULL, 
            0x760E0245FBF843D5ULL, 0xA95802E933FBBFEEULL, 0xAFBC7AA7679F3A30ULL, 0x83D952AE8F8B6691ULL, 
            0x32525D5FB8F722E7ULL, 0xB37075E13D9A525DULL, 0x01EF51F999B81142ULL, 0x57538F4409A69129ULL, 
            0xE6AA947E3FA12D24ULL, 0x6A6A4DD7AC37DDF4ULL, 0xEA3702FB7DFEF581ULL, 0x7699A1666C71577DULL, 
            0xF5640A7BFA921140ULL, 0x2F984D4B84776C55ULL, 0x7AA0B446E5DCCAB7ULL, 0xB798968EC9C4A764ULL
        },
        {
            0x549B5CF3DFE1672CULL, 0xE285F1FD183E1CB8ULL, 0x376DC804BA5C9E1CULL, 0xB227DBFAF63C66BAULL, 
            0xC13F7F1B91885680ULL, 0x42F54523464FB3D0ULL, 0x676BECBD114CAA76ULL, 0xC1CAD88791421E0CULL, 
            0x68CA19B2E7E20933ULL, 0xFEE6BFBA8DB4171FULL, 0x417A1EA725CF85D8ULL, 0xFE3915B63465CE33ULL, 
            0xF99578812C958D7EULL, 0x87C779B2EE687ECAULL, 0x8C27729EA85CB674ULL, 0xD419B67204E0546EULL, 
            0x41E032FBF140C04BULL, 0x1CA6EC6787A2DEC8ULL, 0x28099FB3734B08DEULL, 0xE22B5B2817C86F2FULL, 
            0xB612504086BF7DFBULL, 0xCC7D5D96685D1DACULL, 0xDE8339059C9C2817ULL, 0x7A8B27D7E2A2EF18ULL, 
            0x0AE5A885DE9C7751ULL, 0xBF0553AD74798BC1ULL, 0xFD697C694381A2BCULL, 0xC984C8F2181CC1DAULL, 
            0x66B28B44F8F9751EULL, 0x2734B5524470F3C9ULL, 0xA06011685E437179ULL, 0xCD206D9E9BAF792EULL
        },
        {
            0x18CF0EE76F25983DULL, 0xC2EAA126E8B18A90ULL, 0xAA3F403F9699DA7CULL, 0x49992EDD89025895ULL, 
            0xE49C3D6F5706C9E5ULL, 0x9FB4841B7C093189ULL, 0xCF560F6E60C78602ULL, 0x75986D4C4F8E62FCULL, 
            0x09250DECD5C6CE7EULL, 0x6A27195DD1692DA7ULL, 0xB5F04F651F3E7F3DULL, 0xA00AE655CFF5652BULL, 
            0xEF3071ABC486CEA7ULL, 0xC0FB570EF8449751ULL, 0x293410EA05ADC95CULL, 0x1C4227FD1ECDE035ULL, 
            0xC1B9351F940DC003ULL, 0xE3FFC46295E55E6FULL, 0x0F2118A09C518253ULL, 0x97C1B0F96A2738A9ULL, 
            0xA30CA0263F17182BULL, 0xB7F1C3FDEAF1A151ULL, 0x1F0C771C88F2EDCCULL, 0x18A7F29D5401288EULL, 
            0x57C1A4638F68C0B7ULL, 0x9E39F7896E10F323ULL, 0x4B9C5994971CF5C1ULL, 0x2859EA4A1818AA56ULL, 
            0x7A63DB4BBCF82FCDULL, 0xB37F92FEAEBBD3A8ULL, 0x4D0604E5FD0F8FD0ULL, 0x60D7A1486977237FULL
        },
        {
            0x5B0C37129E90158AULL, 0x6F253C8AEC5D9564ULL, 0xF2CCA28A544EDF3CULL, 0xBDED12C6ADBEDC60ULL, 
            0x17438D1AE66A7F45ULL, 0xCA8217038572EE51ULL, 0xE60FC7D8C014F408ULL, 0x2B841004FB1EBE18ULL, 
            0xD11530D2981EC6CEULL, 0x6925D860A65FD92FULL, 0x24609277A726D421ULL, 0x1A869EA7FC957691ULL, 
            0x99582A57B8E3049FULL, 0xB850B02FF98F464CULL, 0x6C9E454B1605F514ULL, 0x9177AA346A56D448ULL, 
            0x0436B754D8179442ULL, 0x4E09AF968E050344ULL, 0xBC6202F9F8EDEFBCULL, 0x0B04E09AA65B5322ULL, 
            0xEB81AB3CBC5563D7ULL, 0xFABF1685BC24CF4EULL, 0x46FEC4414CCFBD41ULL, 0x0EBAB82144F5441FULL, 
            0x2F7DD608EF188E83ULL, 0x9CEC0F3C603EB22EULL, 0x8B6698AAEE780B2AULL, 0x4E150805F5E6F1E0ULL, 
            0x53DF905F3D7F601BULL, 0x28584C0BCC72C230ULL, 0x44436769F6687F95ULL, 0xCFFE99A1B715E672ULL
        },
        {
            0xAE001B67512FA2B8ULL, 0x4B9E419B641C632CULL, 0x91A1D81E2FE09D85ULL, 0x0E57577416E25624ULL, 
            0x93D151E0CD2211F6ULL, 0x132EC810155355CEULL, 0x3FE49C4D00798983ULL, 0xE8502538ADB01D3EULL, 
            0x3D50EE0BD4A9D3F5ULL, 0x99DD34538F441D5AULL, 0x87D2356B744BB488ULL, 0xF9F423C46EB3892AULL, 
            0x7E9D1F104F1C55D0ULL, 0xCB958BA82DE180D7ULL, 0xAD8ED05CC4AC946CULL, 0xE67FFB3A95CE6851ULL, 
            0x009E9CE6D93C663CULL, 0x7C7B02F6C5F3B6A6ULL, 0x12FE0D372C035FB4ULL, 0xCD9852B65E4AA082ULL, 
            0x46BED508C1E4B7D6ULL, 0xB82369613341457EULL, 0x731B078954BE815AULL, 0x6C21D3E80DF5CD2FULL, 
            0x51DB7A753FE3912AULL, 0xD007E0EE75B24B58ULL, 0x857504CA5274D9AFULL, 0xB9392DC415564888ULL, 
            0x69F8878EAFF6B2B9ULL, 0x28283C63DF8FFCD9ULL, 0x4B990D2E7EF03729ULL, 0xCDDE78336357F82FULL
        },
        {
            0xA8B2CE71ED1413B2ULL, 0x7C4DFB7F5986596FULL, 0xD394D3321FFE0AE9ULL, 0xE51DFD9D934E69BBULL, 
            0x2CABEAF3C9FF8306ULL, 0x8ABB9CE6D2DB59F6ULL, 0xFCA2C82885CFBA94ULL, 0xE41FE70B6306C94EULL, 
            0x79A8ACB145D74727ULL, 0x6F1C05D235952C39ULL, 0x9E3FB6E6C5C08254ULL, 0x859EB79EB4BD8272ULL, 
            0xCD0830E1D7A2C3ADULL, 0x4C886FA53D91950AULL, 0x4AE9F15EA329C9F1ULL, 0xCFD59DA05E4D189BULL, 
            0xBE314BDC736724EEULL, 0x47029F80B67006A3ULL, 0x2ACFF5B36757B152ULL, 0x56F60C3377D05D46ULL, 
            0xF93267B954650B0EULL, 0x9B23CE594FC40EFDULL, 0x7E67F6F5E6292005ULL, 0xA0B4D92E259164C5ULL, 
            0xEB1142CEC43BD519ULL, 0xB0E51BEA7768FE4DULL, 0x3B5D7BA2CF79A351ULL, 0xCDDBD1D1EF0B7663ULL, 
            0x0DB88FDB78139182ULL, 0x928D4245666DC7E6ULL, 0x22EB7E70DD3DA1D1ULL, 0x91E5C4F7ADCA9219ULL
        }
    },
    {
        {
            0x607A94E2B9381440ULL, 0xF716E595F3B11030ULL, 0xDC76FCDCC8A2F91EULL, 0x8D1321DF0513A344ULL, 
            0x16AE8EB53B1C2EDAULL, 0x237F983EBE6992CCULL, 0x392DEEFB19AAF0DEULL, 0x038560A87BB864BEULL, 
            0xC60C0C7946C72F0BULL, 0x3B3962A147D2A357ULL, 0x37FF440F2AC981EAULL, 0xC5A159218404B91FULL, 
            0x364A7967D6396B54ULL, 0x1F28475CC8688D67ULL, 0xCAF6618C8E0547BEULL, 0x73610285D78E46DCULL, 
            0xF8785EA6C25C8D73ULL, 0xC25D3BB1872C4F4BULL, 0x4FE05DA8A79149F9ULL, 0x6FE46ED255D17759ULL, 
            0x4EDD410E4A215C4CULL, 0x80EEACB9D5962E85ULL, 0x84705C1C0BF6D92EULL, 0xFCB028AD2BCF6450ULL, 
            0xD9DF017C56D2102CULL, 0xBE4EF598A6A79839ULL, 0x36EA77F9D51511E9ULL, 0xAFC84F426E947E04ULL, 
            0x68955CB79D89D5B3ULL, 0xDECA35CDD2709813ULL, 0xD8AC249E29EC2D69ULL, 0x3D13D21EDB17E803ULL
        },
        {
            0x8FD7F617D11B4CDFULL, 0xEFA87D3DCA9948ABULL, 0xC9D07B9BD4CBD197ULL, 0xBE92B4AE713F148AULL, 
            0xA8FDD6E9762BEEC3ULL, 0x24EC86FEE09C8E06ULL, 0x8F8B65DF68D4FDAFULL, 0x48B55C99FB2A7B19ULL, 
            0xBBC9752C43AD3B4CULL, 0x10251AA8806C02E5ULL, 0x977B74CC0CA6C6B8ULL, 0x095E8BE70927EB00ULL, 
            0xCC54806141A827E9ULL, 0x75B6F4BF0A485418ULL, 0x4A640C11291A6CC3ULL, 0x26D1FEB73937E331ULL, 
            0x23DEFDBC15715048ULL, 0xFF3C1673485F120CULL, 0xEB18BE3DE1413810ULL, 0xFBC25EB0B1CEFE0EULL, 
            0x65FF08F5DC30501CULL, 0x06EC00CACA64E159ULL, 0x9A09E96AD9669400ULL, 0xB872FF8FE54BF349ULL, 
            0x7053FB74DCF97D02ULL, 0xA7E40F13404DD462ULL, 0x2421552D8C49F1A5ULL, 0x603867B4BF6AB12DULL, 
            0xEC13BA4292B618F8ULL, 0xE465C06530607E96ULL, 0x75A06B9359968765ULL, 0xD28ECC63EC4B7ED6ULL
        },
        {
            0x60969679947C315EULL, 0x1780ED70F5F15043ULL, 0x07D085B6D94CD9DFULL, 0x852E578F90352775ULL, 
            0xCD1CE4633C624583ULL, 0x7521DD5A06B1EB39ULL, 0xAAA78FBA38832C42ULL, 0xF5AA743B787DFC06ULL, 
            0x50AA5C24A06225BDULL, 0x234E6314B6BE8D05ULL, 0x1E37FB40476F941AULL, 0x1EE62CB2591D6A3FULL, 
            0xDD897E6DCCB02549ULL, 0x77D6F2CFE2809D5DULL, 0x0B03C8FB599C3DCFULL, 0x1BCC48AD2E9FE965ULL, 
            0xC6BBC690A36FB380ULL, 0x121D9FCCDACEB82AULL, 0x5DBCEB74632902A4ULL, 0x9D903908FDC9296BULL, 
            0x3A94B57A003D6F47ULL, 0xE88FC9AA40740948ULL, 0x7C9E64E27B7A20B7ULL, 0x84BCDD35A662B2C3ULL, 
            0x54BC03F5EB16CE07ULL, 0x52E623827E4BE39EULL, 0x5475B52FCF011B93ULL, 0x82AF3661A75FD3A0ULL, 
            0x094E3DE453E065E8ULL, 0x0DB8D71014419857ULL, 0xB23223EF51C4D0F4ULL, 0x9A20DB453258D3A2ULL
        },
        {
            0xF5C16023B800C42EULL, 0x1044F5A230C35847ULL, 0xB147FBF7E787D087ULL, 0xE9AC231DD3F3198FULL, 
            0xF65F5BE81EB9999DULL, 0x26933FA20E219586ULL, 0x677305788C882096ULL, 0xEFEBF40C901CB5E8ULL, 
            0xCEFD82A64B554DC1ULL, 0xA87AEC0CD3992DB2ULL, 0xB355A05797E3AF7AULL, 0x4265DBF194A8DBFEULL, 
            0x38561F6D473816DEULL, 0x84361E898DE0CB29ULL, 0x35E06F621251B83BULL, 0x36C8D665C31AAABEULL, 
            0xB7FE8C00612F1A14ULL, 0xCA5C6679E396167BULL, 0x0932F67C47F68DD3ULL, 0x853C83A5D486D3E3ULL, 
            0x3F3D6203498BF04CULL, 0x7A4E632AB7D91E53ULL, 0x52F1352336B7D0B9ULL, 0xBA129E847805F5AEULL, 
            0xADCEFA99952620A9ULL, 0x857C30DA5C6978B7ULL, 0xF2F050C2596153D4ULL, 0x3969BB1D320F18C5ULL, 
            0x5332CE1169193C39ULL, 0x247A52B39B4292B6ULL, 0xE3FEFEF0AAE3B681ULL, 0x2925FBD482D477B9ULL
        },
        {
            0x9B9675B0C5E482A2ULL, 0x8BC859909F59D366ULL, 0x62D6E6A8534B13D0ULL, 0x2FAD45C80F948A66ULL, 
            0xD55D2F3B54E84554ULL, 0x027BF30424C85E27ULL, 0x05C6A455520D8134ULL, 0x58874776AAE3B56FULL, 
            0xAE37FC1A9801E736ULL, 0x05B7F0615E2ACE42ULL, 0xC7C47DA92EA0D5AEULL, 0xBE5EA131AB9C5979ULL, 
            0xB9523D7D5067DA6BULL, 0x9D4ACAD763D24F70ULL, 0x53030D7200496C45ULL, 0x84E0DE0D04575E06ULL, 
            0xF2ED961EA1DC9C78ULL, 0x2F01C3CB0F6FB1C7ULL, 0x83E8E68BB323EC64ULL, 0x45174F8D063A8652ULL, 
            0x9766909315E8343AULL, 0x1996E9BBEB8A4A52ULL, 0xB3FFC9A88EB70322ULL, 0x0D8D20359EDC1A34ULL, 
            0x54A57446FF27CAA4ULL, 0xCB8D0A022A85A260ULL, 0x5073802F6F85E46BULL, 0x4A9FAC57C8198CA2ULL, 
            0x53293F160D8427D3ULL, 0x94A93290DA90BAF8ULL, 0x5D906D6E6C4879C8ULL, 0x32932119B1D62628ULL
        },
        {
            0x4ADD6D74D42FE85EULL, 0xEF82C16AC2A64C90ULL, 0x70199860DF9B21DFULL, 0xD071A3C7AF1B324CULL, 
            0x844FE38CC4E19094ULL, 0x2C1FD207BF66D6DCULL, 0x2E1252A8FC03A2D0ULL, 0x84C6EB7A92CD130EULL, 
            0x9B3F1B8B677BF576ULL, 0x4986D12EFCEF7613ULL, 0x6F13A311C3A57181ULL, 0x047F4A0AB567A089ULL, 
            0x096673B2B3CFD004ULL, 0xEC7A5C417C7F9BD8ULL, 0xF0CD185CC5A34058ULL, 0x9AA69AA5018A609FULL, 
            0x0DE42347B4B38AF4ULL, 0x037499B79E390443ULL, 0x6E0D90DC14D375EBULL, 0x1E4CA9375072A0DFULL, 
            0xF9D5F4B550CB7FE0ULL, 0x8E162330013C5A90ULL, 0xD443F3D12CD8664AULL, 0xD872F0AC7F454A2DULL, 
            0xB38E58DE6835F439ULL, 0xBCB8CF7B0A7809BFULL, 0x12A9FE5662ED8C10ULL, 0x4D15B447208AB09AULL, 
            0x0CBCEFD6365816ABULL, 0x24F3D16665D9DD3AULL, 0x96544503EC69750FULL, 0x59A2718008E17760ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Miram::kKeyRotateAConstants = {
    0xF04A9190E978D70DULL,
    0x9E196DB3676D27BDULL,
    0x68999CA1BA83603DULL,
    0xF04A9190E978D70DULL,
    0x9E196DB3676D27BDULL,
    0x68999CA1BA83603DULL,
    0x1560E74FA9C5AB8BULL,
    0xE7F7D5BAF218DD88ULL,
    0x97,
    0x04,
    0x8A,
    0x73,
    0x67,
    0x8E,
    0x44,
    0x09
};

const TwistDomainSaltSet TwistExpander_Miram::kKeyRotateBSalts = {
    {
        {
            0x34B94D5C633CAB68ULL, 0xD4CE3228E56FCEF9ULL, 0x8A1801279386A13EULL, 0x1B89FC03BC7A2527ULL, 
            0x276E2C86AB5EFD6FULL, 0x7DDB54E48AA8F7B0ULL, 0x73E7FAFF9C80800DULL, 0x4E1A9BD33D5423E9ULL, 
            0x3C4C6C5C22F7C7C1ULL, 0x8C718433D81A7D16ULL, 0xEB28AC66543C567FULL, 0xC3C3BAB0D2B2614FULL, 
            0x834F6FB54668574BULL, 0x0A149500619625C6ULL, 0x21D8B8CB00FCDF8AULL, 0xD845F51CA2380D00ULL, 
            0x0A9180A4DCC267E4ULL, 0xADF75B6905333756ULL, 0x70B07B2385CAEBC9ULL, 0x7414F9E1407E62DCULL, 
            0xCD84857F795BAB4FULL, 0x3A974F5D50CD15D6ULL, 0xF2B045FD50EEF60BULL, 0xAA96D58C06E773E0ULL, 
            0x4292CDDE6FB4C1E6ULL, 0x406C046645F1D750ULL, 0xA70248768524292DULL, 0xA23C8983E95DE95FULL, 
            0xC31A06BBB7EA01C0ULL, 0xACCAFC7FF985F582ULL, 0x749DAB6711695C7EULL, 0xB84035933FF205A6ULL
        },
        {
            0x5EF1BD67EB09E86CULL, 0x5496E479C37F9BB7ULL, 0x8B09EEEE69FBE179ULL, 0x67854003B4229A5CULL, 
            0xEC867BAE60593918ULL, 0x057825FD8C5868D4ULL, 0x5C60F938FE631DE6ULL, 0xFABE9E3E883E21FCULL, 
            0x55C3F4DA108365C1ULL, 0x12EB353B5D57C244ULL, 0x8F043D374B05BB75ULL, 0xD9BFEF274A5513A7ULL, 
            0x1A826840023589EAULL, 0x8F0A6369DB759E64ULL, 0xCD5E029EFAA34C67ULL, 0x82337D767BD9BBEEULL, 
            0x18D706B37CF7C118ULL, 0x01DF5F2621A9EE38ULL, 0x3EFBF1496F8FF195ULL, 0xC8C25DBE7667B18BULL, 
            0x417634E11A93A431ULL, 0xBF914F4C6332D357ULL, 0x13A85F848145CCA5ULL, 0xEED09B8B0E9EF510ULL, 
            0xF6E9F6C9015EEB9EULL, 0x99A35EB86E05AB9EULL, 0x7C44CA85B2C5E207ULL, 0xBD04D72E059A4963ULL, 
            0xD6D50C788DB0D32BULL, 0x3A475412E33DBF0AULL, 0xC31EAF82F91A6E13ULL, 0x2CA7CF920DB145BBULL
        },
        {
            0x02E13DBAFA3C5B03ULL, 0x5A8A691AFB36B301ULL, 0x52482DC215FD6639ULL, 0x92A4DC02456E7FA2ULL, 
            0x5BD3D379E2FA1DFBULL, 0xA7D9A7B21A000439ULL, 0x4BB6879D0B49EF05ULL, 0x28A5FD7A921F2218ULL, 
            0x0612310D4371897FULL, 0x88DB58F2E4CA68A2ULL, 0x7CEF80D804B1A059ULL, 0x28E1D3707586FE0BULL, 
            0xAE249470E9DE01F5ULL, 0x82E44888C3FE76FBULL, 0x38A29358C50DEC91ULL, 0x5720652E8EF67018ULL, 
            0x1585CCC6C03F2906ULL, 0xB867C93F6F585C34ULL, 0xE812095D57E7B785ULL, 0xFCCD42219E290E47ULL, 
            0xE62FA4D998489EC4ULL, 0x2709AA685FDE6EF7ULL, 0xA6493FCC44240A76ULL, 0x64E8740874058317ULL, 
            0xF52A14DA7629497FULL, 0x0370C81EBFCE54B7ULL, 0xAEFCAEC9C4860232ULL, 0x04A6D147F9D00A2FULL, 
            0xB9E43195601E99E4ULL, 0x1F35D345A688D7E7ULL, 0x3D6A8A435C0739C7ULL, 0x41D10A8A164F06F9ULL
        },
        {
            0xB3258EB1A540E0DAULL, 0x142C31B9AB248537ULL, 0xE03A03E0A1E9EA2CULL, 0x91488985D5113F9EULL, 
            0x26D8CF7EC3532FD4ULL, 0xA52AD473263ABEDDULL, 0x881CAA7B9C4A7AB7ULL, 0xAE9001ECBAC94947ULL, 
            0xB467F88AB01C1C77ULL, 0x6A2FA70FBB0CEF23ULL, 0x275D7504758BAF0DULL, 0x02220476C082E1BDULL, 
            0xC57E9D68E4FCE25DULL, 0xD46B3F769C296A56ULL, 0x1D3CE855709275C6ULL, 0x937A1C0815344965ULL, 
            0x13C09FD92F1CCCA1ULL, 0x3341C2B253D96811ULL, 0xF2B4D44293834FBDULL, 0xF2D3C9A206F515ABULL, 
            0x6CAF6621D129CA1FULL, 0x02348DDC902CA923ULL, 0x0E5F038C1A8A8EC5ULL, 0x8E00FB36DBA957EEULL, 
            0x30CE3329BAAE50F6ULL, 0x87E567C9D21C4CC6ULL, 0xFE98BA9C5F32A21DULL, 0xE0A1C9D2261760A7ULL, 
            0x9A8FD0523028B4ACULL, 0x81759827AAA3EE30ULL, 0x9A32FD7C68E51981ULL, 0xA4E87B5155BDF0B9ULL
        },
        {
            0xEBFDCBFA036AB0A3ULL, 0xE5578101225AAB8EULL, 0x99336BEB1153F002ULL, 0x0ED3F3A0046A90B1ULL, 
            0x88CF1B07CF3C75A3ULL, 0x0E7749579BB8806EULL, 0x0B68B80A2E6E9322ULL, 0xFBAC8D9432109966ULL, 
            0x14FB7662DFD94234ULL, 0x37570BA62B56F8A1ULL, 0x9279AF95B130024BULL, 0xEB1E92F45222A41FULL, 
            0x1587618CDF45EA95ULL, 0x6C0235ACEAD3D1ABULL, 0x7D2CF30CD66EC4C6ULL, 0x4DBB1A2B7C45231EULL, 
            0x37E98901924322D6ULL, 0x1C3D922BD4B1BB40ULL, 0xFBADC6178939CF42ULL, 0xE930EA56383A2B1AULL, 
            0x57269EB9F050521CULL, 0x4CFEFE4AABD79990ULL, 0x54B002A202BEB949ULL, 0x7177A6E8FB7E32C7ULL, 
            0x0F4C762BD4FCF255ULL, 0xAF683ED705D3D6BBULL, 0x818590B3F272EE8CULL, 0x08D20AAC52075D83ULL, 
            0xB63E32D355498D31ULL, 0xF6AE1F1D3E2AF23AULL, 0x45398F5C0FAF961AULL, 0xE605E4EA2656E3A1ULL
        },
        {
            0xB139F60A8AD81744ULL, 0x4EAD1BBE1D468002ULL, 0xEF8F9D9F889D52B2ULL, 0x574E5D9AC8EFA374ULL, 
            0xF6C324CF73864942ULL, 0x13FE57F723FF1695ULL, 0x384E2A1F08F8F4F3ULL, 0x05899EA06601220DULL, 
            0x66A9F258823BB817ULL, 0x5BC80360C0EF8F5FULL, 0x4D63FD56F0D98274ULL, 0xA03390C4606C1000ULL, 
            0xD8D141EF4D37DA1FULL, 0x2166680FDB06A4B2ULL, 0x0C670C983719CCD8ULL, 0x5C41AE96EF628ABCULL, 
            0xAF2A577ED50B5CA6ULL, 0x613571F06FCED870ULL, 0x5A9FDA86F38A75E5ULL, 0x79188D3047330E31ULL, 
            0x263D228B5388081EULL, 0xA4E59EFC90FF24C8ULL, 0x17857BDDB93DB0F6ULL, 0x0575F1320DE32748ULL, 
            0x3D1C4F728178B8DAULL, 0xB27C1486755688D7ULL, 0x0A54E11A812B40F2ULL, 0x392A6E4A93F8D352ULL, 
            0x1A6DD5E922478A29ULL, 0x507B236D614FF9AFULL, 0x24A0303EE35BFC12ULL, 0x81B09BF36AD93E83ULL
        }
    },
    {
        {
            0xAED251E2887E84BAULL, 0x64B0849E9D59D4A3ULL, 0x5D6FD5FC33EA56F2ULL, 0xF17181F3C441CA0DULL, 
            0xDA3A5E642597DCE7ULL, 0xC9A4A9EFC745138CULL, 0x5446E2226EB95B24ULL, 0x62B78C577601C188ULL, 
            0xE94EBDC8214136E3ULL, 0x3152CFCB00B1DBDBULL, 0x289B971D9FD58F78ULL, 0x18083FF82CCDE644ULL, 
            0x170655B28B9092EBULL, 0xA4837A5053E21926ULL, 0xC92C94AEE1BF23F0ULL, 0x3C03AD3A607A75CBULL, 
            0x186064358CCA36EBULL, 0x60481C068B920D89ULL, 0x40BD0BE24E1982A5ULL, 0xCF97F0B971B70392ULL, 
            0x8A4F9DF00BD234B8ULL, 0xF9045DF33CC065C3ULL, 0x81E9B36F3918110BULL, 0xA7AF09A98A4FCF3EULL, 
            0x6C0231AA13290B28ULL, 0xD8DC84D5AAAE6609ULL, 0x41E2EAD46A5036F8ULL, 0x545A5F90CFD71C0FULL, 
            0x5C9176F521EEE860ULL, 0x2D4B8B4D9D4334CDULL, 0x569E1C5C80CC1426ULL, 0xF3B52E38BAA3C5BAULL
        },
        {
            0x244BFF93CBCCF5E7ULL, 0xEFCFE8CC9C817777ULL, 0x1708BC782E4638A6ULL, 0xCE263048C4CFEF89ULL, 
            0x6ADF0FDC78F33994ULL, 0x406692966C9EFA39ULL, 0xA574C7B73F883FD8ULL, 0x5DBF970F8B3971EBULL, 
            0xEFEFC7DBAFCBDC3EULL, 0x917071EB9FE6B3A4ULL, 0x854CC78BE4F0E928ULL, 0xA829849727FA4EE3ULL, 
            0x4B9087994126B058ULL, 0x84086E7DA5BE2A8BULL, 0x2CCCCCBA0335F965ULL, 0x7C6D5D42B074575FULL, 
            0xBB76A7361F46959EULL, 0x23AFB96E5943B76BULL, 0xB83EFB594BC44B7AULL, 0x436A2EB8C0D5795EULL, 
            0x48D0F3D17F6A9B6AULL, 0x80291752DC5B7D92ULL, 0xF7DF25DD9095A5EFULL, 0x918DC5012B53B9C4ULL, 
            0xFAC71D0660A53CAAULL, 0xC080927892EFDDD1ULL, 0xBF9A69BC67D82054ULL, 0xF03137613AB480F2ULL, 
            0x4C54CD24C46A1C1CULL, 0x2AC8533B154A23F6ULL, 0x81C7ED9DC78B5312ULL, 0xBAFBA2391C5C11B1ULL
        },
        {
            0x6753749BC027A880ULL, 0xE1B64D63B14E6781ULL, 0xF63B2E12EEFEAD87ULL, 0xCFAA17AE52B5886AULL, 
            0x3FB77402AB309702ULL, 0xA91101D9B972DEB4ULL, 0x0706B659C7AA1EB3ULL, 0xDE2BAD47E9405F62ULL, 
            0x1DC3265CBB1B80C4ULL, 0xFBA8425C0F4A91FAULL, 0x8F73821C8046BDEDULL, 0xA9E69A217F94ABD0ULL, 
            0x0CF9A9C93823BE48ULL, 0x80E471B11507A1ACULL, 0x41AE66C128E43F55ULL, 0xB50FB4D295AA30DAULL, 
            0xA89B722A6D483E84ULL, 0x12177933901207E3ULL, 0xE785846F90DE8E62ULL, 0xE12A3E5DC93CACDAULL, 
            0x266113BEA9F02064ULL, 0x5B7C0BF54ED278F7ULL, 0x11E171EB0D823D9BULL, 0xCA4779D51F15CB14ULL, 
            0x67AA8C2E4EC3F6F9ULL, 0x7A5E5D5160A28A13ULL, 0xE8E1C8B79F29F256ULL, 0x6C51009BEA31A357ULL, 
            0x3B614B86C17C670AULL, 0x3BE47F3DBFCA0955ULL, 0x9D100419881CA628ULL, 0xCB504A42A83BBC97ULL
        },
        {
            0x5E09DD7C7F726F02ULL, 0xA99C87BB659462C0ULL, 0x5EAEC223E4E67B38ULL, 0x6B290B90F1F1320AULL, 
            0x6A89D347B568CE74ULL, 0x0DFF8662771B29F6ULL, 0x3B40F47BD68C7C57ULL, 0x8A335BC2F495F787ULL, 
            0x16A8D87A692144C5ULL, 0x10A1F7D10A4F57ACULL, 0x99AADCE36AAE3706ULL, 0x0914BD61B058940CULL, 
            0x1F0F40E828FC6A62ULL, 0x102D76A80E9CE4EDULL, 0xD0080BB1D09DBAD2ULL, 0x85A0EA0026CB539BULL, 
            0x0D5A025BBB3D5163ULL, 0x8A462E7485165D70ULL, 0x0BBC045C9704CBD4ULL, 0x35AEBF9F2FABBBFFULL, 
            0x317862B217464EB9ULL, 0x219E30328A54268FULL, 0xF3D0E2F66285462DULL, 0x56DA38C88EF1B518ULL, 
            0xB1E82004A848CA72ULL, 0x94188B82AA42F0FCULL, 0xA6F2DD6389B6120DULL, 0x51FE99D6CD6D04F4ULL, 
            0xF009849F54CCB5B1ULL, 0x1B27B2A65CD9AA99ULL, 0x567515097CAB37FAULL, 0xABF53C4D064B8BC5ULL
        },
        {
            0xBD05CF6A7757B698ULL, 0x24A123A2CBEE87D1ULL, 0xB6825930BEF88AE8ULL, 0x893DD0A5854ABE57ULL, 
            0x4458EE154CD480F8ULL, 0xDB00EA0C535AEDB0ULL, 0xF3DDF35E3535BE71ULL, 0x0060D192213F2136ULL, 
            0xB3B36480F3E8E172ULL, 0xDFE530DEF91B66CAULL, 0xE6F380F2DB6142A6ULL, 0xA2F16313303EAE52ULL, 
            0x22B1A5C3836C1BFCULL, 0x7BCC723984EFE510ULL, 0x108DCB40036D140EULL, 0x3AC3139991FDC0E5ULL, 
            0x314C4CA2EA288B44ULL, 0x18E396750B775D45ULL, 0x67A397B44F5C026AULL, 0x29FBA64EB00E6900ULL, 
            0x5EB5A00616E6D3E5ULL, 0xECF87E7284C62E8CULL, 0x578DF65FF7E725E0ULL, 0x49B55A844B3EB322ULL, 
            0x6196BB907F3DCF59ULL, 0xE4F90699336DAC41ULL, 0x873CF5515E96784BULL, 0x9272254703077E08ULL, 
            0xA970A1BECF1045BBULL, 0x75FFE531A1561167ULL, 0x13824E473D9AF6D7ULL, 0xD418BB5F3C356740ULL
        },
        {
            0xC748443F3C5E08D1ULL, 0xD1E2A25CF0FE86D2ULL, 0xE5A63FBA70EF720DULL, 0xB389DB8DDDC94537ULL, 
            0xD3F563466F422D60ULL, 0xAE10C2A508CD0781ULL, 0x68ABCC8FBB7A196AULL, 0x42161C05E1D648ACULL, 
            0x3D3187296AC8B182ULL, 0x131075AF9A901A99ULL, 0xBE5E102FAD384127ULL, 0x0C98BFF3A5704FE0ULL, 
            0x47C1C40B6C0C9AC9ULL, 0xD18F19CB4C8DDBEBULL, 0x4DD223F094F43B74ULL, 0x53A9DD8C655199A1ULL, 
            0x568FBB86E8F04963ULL, 0xA46115075195C062ULL, 0x6A4419B29AFEE4E5ULL, 0x7C21BB871DD6818CULL, 
            0x99BE3EE31250B42DULL, 0x0D68CF95D2BBC049ULL, 0x5DDA8B0EE1B95166ULL, 0xE5C3BC003E9BBD9DULL, 
            0x2E4ADFE2C72FB31EULL, 0x9662099AFFEF43B6ULL, 0xC59FFF82010F2C58ULL, 0x06E1BC1E83B4B924ULL, 
            0x45B30F30CC745093ULL, 0xA4B24CDC247D04BFULL, 0xF6CA21412524BE31ULL, 0x05335016947FEF87ULL
        }
    },
    {
        {
            0x332A6F9A03C7489DULL, 0x79B860213088DBB5ULL, 0xED4A5CF942372808ULL, 0xEE1239AF068AD258ULL, 
            0xC65CBE1BBA4C4A74ULL, 0x780DCBE4970D61E3ULL, 0x452F2DB89CAB6750ULL, 0xC3CDFC8457470D47ULL, 
            0x12F9FC7BB6B14772ULL, 0xAE93703B26545436ULL, 0x0C425E7212617E3CULL, 0x57E1D03E3C27333CULL, 
            0x24D0C6F2437FF9B2ULL, 0xEB5C40BB24D895A1ULL, 0x9D6C1175EC7DC84EULL, 0x95D9ED406EB6BF66ULL, 
            0x3A7731C0A4C4EDCEULL, 0xF23C8CC348B3055BULL, 0xBE0403B8249407BEULL, 0x2864956CD7648892ULL, 
            0x91B2A18CE10DB926ULL, 0xFB3047EF583331A3ULL, 0x925A18BA7CF38B97ULL, 0x1892F433FFC695E8ULL, 
            0x978B67619EC61FCAULL, 0x8E745F8BCA70398DULL, 0xCD4A0038AB783E9BULL, 0x5866849171F6F27FULL, 
            0xD406B623DD91DBE9ULL, 0xDCDDC98C60A5EF87ULL, 0x4C3AEAD640634E7DULL, 0x265C7F8E5ADF37E1ULL
        },
        {
            0x6481D5159CFE9321ULL, 0xE2416706FFF1F8C6ULL, 0x7C8F567A61C17D48ULL, 0x070B37B6C091639FULL, 
            0x4B282039F103BF93ULL, 0xCFDE4F2F808D5287ULL, 0xADCFE17AF82139F2ULL, 0xEA4F822C182ACA1CULL, 
            0x3A3765A322C05B21ULL, 0xC4FD5E78B2584CF6ULL, 0xD550279A3F2EF69FULL, 0x7E6F2D1A021588F9ULL, 
            0x1A3491EE4690F167ULL, 0xD49FC00A3A31DDA9ULL, 0x5C07F516EB33DF5CULL, 0x018E5F30395BB5A3ULL, 
            0xC50AC59B6409946DULL, 0xEF048CA0E1E8F3CDULL, 0x2B2B421E006C7430ULL, 0x1964C619987A217DULL, 
            0x17C9E79C6F7D6049ULL, 0xA4D0C57008ED2B16ULL, 0xFEC022AE4C403C2DULL, 0x1F1FEF18DF46811BULL, 
            0xB2CDA60D810236DDULL, 0x4F1E5EDE6BA7DF9EULL, 0x59A42C845B8D041CULL, 0x94D8B9781F465243ULL, 
            0x9A95494360B9CB3AULL, 0xE2C24C896E25757AULL, 0xBDAB0498477416E4ULL, 0xE5F971E4D3F2C40FULL
        },
        {
            0x45CDEB13473D166DULL, 0x13B0DFED425F7340ULL, 0x0E4E1C5F24196315ULL, 0xFB23A39A91D683A3ULL, 
            0x6A57D122165B364BULL, 0xD5ADD991F3E45976ULL, 0x12D022A784918D5FULL, 0x666F4FFA7CD69637ULL, 
            0x3D4F6D6F8BD0F09EULL, 0x6ADFBF1C27B4F6E9ULL, 0x14F5E6D576A3A53DULL, 0x5E54DCE84681DCCDULL, 
            0xCF81A236B7A4C12CULL, 0xF29163DE7820CAA2ULL, 0x6B1A0A6E074B239CULL, 0x5222372F07EB72F0ULL, 
            0x80542B7D69CE61BAULL, 0x3E9C332F2B4636F8ULL, 0x37BD102F157EEF1BULL, 0x3FC95321B7629051ULL, 
            0x3E3A21F6F8384719ULL, 0xBF52D4FC8EB2D872ULL, 0x2E4C03221B0EF3ABULL, 0xAAC7C01A8AAC6584ULL, 
            0x1D8B4CC860237A90ULL, 0xE104A391A1381BD9ULL, 0xF2AAA717CF52C3B9ULL, 0xE8F514C89BA9689CULL, 
            0x419DB91A08A07C08ULL, 0x60C7F605D77A4A02ULL, 0x66CC4DED546BE373ULL, 0x38701F7C5D12692BULL
        },
        {
            0xFAB661FEF75E2A80ULL, 0x038EBF42BDF9828FULL, 0xBB22660F3350E4E0ULL, 0x684AD766CB4F72D4ULL, 
            0xA6FB64D74AE43787ULL, 0x27BDAA3A7114D96AULL, 0x08C399B16F950470ULL, 0x19EB60957299C68AULL, 
            0x2B2DB243E72CAFF7ULL, 0xB26DA66028036D02ULL, 0xCCA7ACFA806A2A31ULL, 0xA42A8D38AEB691FBULL, 
            0xE1B73D0EAE3DA733ULL, 0xC8F11B596BB38FB1ULL, 0xE25F698823227108ULL, 0x975E4792D09E04C0ULL, 
            0x8945809F439CADCBULL, 0xCC0FB39817A82EDEULL, 0xE66BCA7731155114ULL, 0x0A6E8018EDC4ECB0ULL, 
            0x4818464FCDC3257EULL, 0xA1694644E8759B1BULL, 0xB67C72BA05BC0827ULL, 0x42850A3C6FF8B200ULL, 
            0xA763D99F78D46C7DULL, 0xDD0DBE2BC5C4F536ULL, 0xF0B4365B5B164278ULL, 0x439A875B6496B044ULL, 
            0xF56FA279651871E1ULL, 0x4FCF5DF1A930117BULL, 0x83483A4BCF209D08ULL, 0xFF69C6A1477ADC91ULL
        },
        {
            0x6445F6B070FA7775ULL, 0xA210AF6AA93D541AULL, 0xC2703A0964B499D2ULL, 0x327A691EEA1028D0ULL, 
            0xF914B92800BEF367ULL, 0x88AC27A5943BF871ULL, 0x235048B128206574ULL, 0x22F98F4A38132EB6ULL, 
            0x37757204A4525BC9ULL, 0xDCB4AB036E9BF65BULL, 0x22FF6C5952D3DCBDULL, 0x0445E5BCE1C4882EULL, 
            0x62C376CE8F4EFCACULL, 0xE304593C936BA28DULL, 0x38D660FCEAB1029DULL, 0xFA4E42078E8DF4B8ULL, 
            0xDE33B0AD147D5060ULL, 0x16CF597E55E4D209ULL, 0xF25CF376BE3DA38CULL, 0xFAC487942D507651ULL, 
            0x2A39768AB2699EF8ULL, 0xE2A783884C81462BULL, 0x45A9CE3C7F9E5480ULL, 0x49ABB662F8A8F0FFULL, 
            0x9A32D4DDA02C4CC3ULL, 0x7713AA48D7954128ULL, 0x30F6B52473DC636FULL, 0xC33A4454D298983AULL, 
            0x6976CFC5048AE4BCULL, 0xE6B5C347E5F69AA9ULL, 0xFD9796F8C50046D3ULL, 0x8B9E8381C34C892FULL
        },
        {
            0x1A15BDD2CC66C6FAULL, 0x7B45A03A98F0A33DULL, 0x996CE3FD8A1D6B6AULL, 0xBA074C00F2C14CF3ULL, 
            0xAC416D4C8C16051EULL, 0x356EE5F79F7B3EAFULL, 0x4762267487A9FAABULL, 0xC2B913EDFA1369CAULL, 
            0xCA73AEB2D2A4575CULL, 0xD01CFAB15518760AULL, 0x94B0DFCD698F733BULL, 0xA495EE5970F59733ULL, 
            0x0545F7E4818DB7ECULL, 0x41BD25F4BDF65FEAULL, 0x5EEAD95616149AE8ULL, 0xE30C23285D24EFD3ULL, 
            0x748DA19B623282A5ULL, 0x39812987D8BEA588ULL, 0xB68C21981206138DULL, 0x5358BA85641D7D83ULL, 
            0xC4AE6B56339F226BULL, 0x32280B95B5D6755DULL, 0xD388922BE0EA87FEULL, 0x2080733FE90975A9ULL, 
            0xF11B5E3862C3E797ULL, 0xB63B6709AC2E56ECULL, 0xF1A9C93AB2B726E7ULL, 0x350E747DA6035524ULL, 
            0x46C0A308C1254453ULL, 0x4FF8AF17BF8871BCULL, 0x28DC82BBD138EDA4ULL, 0xC345C6A0647C1EDEULL
        }
    }
};

const TwistDomainConstants TwistExpander_Miram::kKeyRotateBConstants = {
    0xB970A5C608293F93ULL,
    0x571EF310E3964F7DULL,
    0xACC8AADC50290401ULL,
    0xB970A5C608293F93ULL,
    0x571EF310E3964F7DULL,
    0xACC8AADC50290401ULL,
    0x382C556E5E415374ULL,
    0x9807BE52D4962DA5ULL,
    0xC0,
    0xE3,
    0x9C,
    0xA1,
    0xF8,
    0x12,
    0x7C,
    0x23
};

const TwistDomainSaltSet TwistExpander_Miram::kKeySpawnASalts = {
    {
        {
            0x0F0FED00E4756CBDULL, 0x1DCC323A3516B133ULL, 0x134234B7A592709DULL, 0xB249F1ADB9159461ULL, 
            0xC6E4F8D63A1F0F96ULL, 0x7FF190FCA949B10BULL, 0x0254AC56D18332DEULL, 0x254BE139F76095C8ULL, 
            0xD9F8E74C57EE6375ULL, 0xA0EBB7A1572255EDULL, 0xB405573735A2876FULL, 0x250D98F5DBA2B7FEULL, 
            0x0FE46E43789CCCEDULL, 0x6AD6BEB9D67A723CULL, 0x22A9C15833D9AA99ULL, 0x31171833C6311284ULL, 
            0xA02917E278809986ULL, 0x615B50164D5CE365ULL, 0xD52644130B0B9D31ULL, 0xB2AEA552ACDA9A0AULL, 
            0x0D9C3953361F598EULL, 0xE2C0F9D764F66686ULL, 0xB4A524C7D0D8D381ULL, 0x97E9346094228A17ULL, 
            0xA9297D7DC5C8726FULL, 0x8BA59EEE3E8E65C2ULL, 0xB5141038515112A5ULL, 0x5C2F78C09DF2F540ULL, 
            0x12BEC8A124D6633EULL, 0xEF7EAE5856F1647EULL, 0x8341E6175B83D783ULL, 0xE9F244D0B6D77084ULL
        },
        {
            0x065A772821F39B67ULL, 0x64889015D588569CULL, 0x331C7742D1197E49ULL, 0xEB1F9FCA93F036B1ULL, 
            0xDD9908757F3787B2ULL, 0x071143C887A22468ULL, 0x73A28F19B0FBB228ULL, 0x2EB64BD7D825E594ULL, 
            0x484D51A534B98ABCULL, 0x28DE38879AB3B130ULL, 0xE5E02C9B9AF49533ULL, 0x6D2AA932033591A7ULL, 
            0xBCE140C84B404C75ULL, 0xD6C32D425C8B6A44ULL, 0x99DB9E9AD851FDEBULL, 0xD489C800A2BF419BULL, 
            0x4B34074B6F356342ULL, 0x77BB53770D5745DCULL, 0xA0AA96B819808C14ULL, 0x24F364DF2A6B8B28ULL, 
            0xB23A060CE6BBEC77ULL, 0x8E57A8A2AFA1D2E4ULL, 0x4CBAEB5D2AB99EC8ULL, 0x5C1DF6394F0A0DABULL, 
            0x2BB8FDDB30B97CAFULL, 0x1B23DE30DE5195D8ULL, 0x304AD145F79DF340ULL, 0x2B7C29D504181CDBULL, 
            0x904BB477E960A3E8ULL, 0x5214BD35C244D5BEULL, 0x2B34A96CC274559BULL, 0x740088ACDE71A169ULL
        },
        {
            0xB95132DC56C1311DULL, 0x3BCC06496621037CULL, 0x33DB60060FAE6CD5ULL, 0x491573DA7F8694CBULL, 
            0xECBBDC73EA61969CULL, 0x23CC6FE112FC1C68ULL, 0x723162E84A97BAF4ULL, 0x8D321B7A5A2DAE52ULL, 
            0x42EBB19E36B1CAA9ULL, 0x398C2A843566BCB1ULL, 0x32A1E51BCEDD83D4ULL, 0x0B44BB913AE98F14ULL, 
            0x8C65243BC199105FULL, 0xF927290D22F97445ULL, 0x2DDE1FBB267E912BULL, 0xA94DAF5524C49F7FULL, 
            0xB176D1ECABDB8FB0ULL, 0x9F89B0FE3DF2CB88ULL, 0xE00239DA0E94E8C3ULL, 0x001CD36C7E23C01FULL, 
            0x379EDC3032A77EF1ULL, 0x2B3402340B8EE0D3ULL, 0xB984FAF2A03F1FBFULL, 0x486D2CC4A88D54A7ULL, 
            0x6639EEBE2CA1003AULL, 0xE6FD9F60F5417DCAULL, 0x4D42EF633140FFD5ULL, 0x8C2676E209836807ULL, 
            0xC898DEC7F71C5FC1ULL, 0x5D67BABE46904825ULL, 0x65C0711A4B15662FULL, 0xA6F3AC55210DE34CULL
        },
        {
            0x7775E164E4BA9AFAULL, 0xF0BC0F1A59FE0906ULL, 0xC43CBE770FF89A6BULL, 0x0041B6E08164CC86ULL, 
            0x64CFA53432A14069ULL, 0x953EBDFC3CBCBE7FULL, 0x7E4F508D44DD785DULL, 0xFD5AFA922D4600D4ULL, 
            0x293A0C39242195A9ULL, 0xD4E68DB5362BD276ULL, 0x214A01E27954550DULL, 0xADC02E01128D829BULL, 
            0x41FEEDAB26311C77ULL, 0xE451D464E47DF96BULL, 0x98B9592639C59CAAULL, 0x33E0B3DD4CB10496ULL, 
            0x29EDFE7E84C69270ULL, 0x93BE89C49851B1D8ULL, 0xA7091E8AF949F743ULL, 0x7B2DBD6E6EDB38A9ULL, 
            0xE3F1485EB4AF8C25ULL, 0x1CBE95E2EBF77456ULL, 0x6933C4865F60541FULL, 0xE3A11810689FF057ULL, 
            0xD468E445C9ABCDF8ULL, 0xB7CC86EC3934F2A0ULL, 0x7C9DE9E556D165A1ULL, 0xE27004067961D11EULL, 
            0x29944F9E7A876945ULL, 0xC38DF898AA41B62FULL, 0x8D8F454CA076805CULL, 0xE9F3A069E643B086ULL
        },
        {
            0x13D9467D117B3326ULL, 0x0BF22E55DB2C0DC1ULL, 0xC7F49B78A8D60FDDULL, 0x4F3425B623E742CCULL, 
            0x4AA5D80855E527AEULL, 0x318ACC8B62442DF2ULL, 0x5065738C848D9866ULL, 0x06ED61034A153075ULL, 
            0xD33FBAD3931D2FDCULL, 0xCB7224FBB311E653ULL, 0x0EE1919DDDFA8B7BULL, 0xE94D56B2CBDB8115ULL, 
            0xADD05E44CBF2934AULL, 0x77C0D3FA4C7D436DULL, 0xA295E657C5368429ULL, 0x5E677C08BB50FE07ULL, 
            0x77ACAD9CAEA961F3ULL, 0x0DE5972210D7F78CULL, 0x492899211398E084ULL, 0xE78136DBA9A856FFULL, 
            0xE16C834EC5B078FAULL, 0xCE83BCB82689E055ULL, 0x4863FCA816DD35D5ULL, 0xD4D20ABF246F0F36ULL, 
            0x37FEBDADA806A52DULL, 0x09910289A591558DULL, 0xADA31AC7A996B4E1ULL, 0x53A00C21759EE2DAULL, 
            0xA417051DE3BC1B72ULL, 0xEE73BCE9D7C930EBULL, 0x91FC5BE0B36B6424ULL, 0xA70D556C947D514CULL
        },
        {
            0xA8E510BA6168CF6AULL, 0x67B008EB36D50E62ULL, 0x6C6716C4DFDBB443ULL, 0x84C59EE74223A3D8ULL, 
            0x6E6B8FE547DF8A59ULL, 0xDB36C2689CFC0D45ULL, 0x8643BABE56FB6CE4ULL, 0x666085430035A121ULL, 
            0x277CD5FD0AECD05BULL, 0x21E762A954721DE0ULL, 0xCE10A1EF0EE94B27ULL, 0x6315FA83309135A2ULL, 
            0x4D80C66DC835A296ULL, 0x602534AA48F174DCULL, 0x7F0F6EF4EE086632ULL, 0x09F07A922D5EC54EULL, 
            0x136EFB9056208433ULL, 0x76AB8BD0B4AC87CFULL, 0x500C2B6035BE909DULL, 0x0946D1259A25F55AULL, 
            0x9702C9454BB4A6C8ULL, 0x9245879ABE8ED197ULL, 0xC4926F01E04D1082ULL, 0xE6015C36AD64F341ULL, 
            0xFF098BF85FF9470AULL, 0xFFE2225E158F7FDEULL, 0xEE1162FBD5C74333ULL, 0x4117F3C4C10F1098ULL, 
            0x0D160509AF998066ULL, 0x1CF2A2F74D1E5D15ULL, 0x5758FB093147F9F4ULL, 0x574C67DC21B98527ULL
        }
    },
    {
        {
            0x20142375B8F7D611ULL, 0xE930DC6F68B00DF7ULL, 0xB1898DE605FA9130ULL, 0x0DF9FAFE9230A29DULL, 
            0x91E00D327DD4F58FULL, 0xFF6E7F3E237C0A73ULL, 0x0CCE47B6B5F65A26ULL, 0xF859F8F105AAB410ULL, 
            0x86374B5660B93CC1ULL, 0x0D04DA0378256547ULL, 0xE018A4E591945B1DULL, 0x1BB39CACCE3443B0ULL, 
            0x73E033302CC335A5ULL, 0xA678520B288A19E7ULL, 0x0FAEF58159007B29ULL, 0xE1388D854814B8CAULL, 
            0x4D779E3DC461CA0CULL, 0x1996AE9217622BE4ULL, 0x249F2E0B6B7C62E2ULL, 0xF26D53EDB2B6FC88ULL, 
            0x6D8E220F418B6318ULL, 0xDC23C60F371A44F5ULL, 0x096442B7117F0203ULL, 0xF859150D233639A6ULL, 
            0x200FAF3B08B1C92CULL, 0x3693F81438709C72ULL, 0xC1C62899AC78E7F8ULL, 0x55673963B47A5640ULL, 
            0x7D0DD3517C6E5902ULL, 0x543767BD66243221ULL, 0x5E7C0CF88F672E39ULL, 0xAD681E011B165C96ULL
        },
        {
            0x58AB5A6D0A8DB9C3ULL, 0x95F7B47114E72B7FULL, 0xA5DE9062319CC7BFULL, 0xC31E500501F09273ULL, 
            0xA9E058EEDA737474ULL, 0xE83874994D9F1CC5ULL, 0xE5A1ECCA2E5297FAULL, 0x12B9FCEA30F7465AULL, 
            0xCEF78EA750492D17ULL, 0xA61DDC7FB282A90AULL, 0x82095F4786FF4620ULL, 0x55B4CBC328629A42ULL, 
            0x17A88924E19668ADULL, 0xD507ED6CF699A736ULL, 0x01B37BF36613BDF6ULL, 0x21A9FDFCE8CD7C30ULL, 
            0x671858A7C8DC8930ULL, 0xA8509ED4A0AB1D94ULL, 0x0C4A946EF8202AE1ULL, 0xDE0E9C0A4B714165ULL, 
            0xB94E056D4122CA66ULL, 0xE9D357EA5291309CULL, 0x8E07C32E276D8845ULL, 0xF543623A00821E88ULL, 
            0x5925EC0943D04729ULL, 0x2384214A2444A9EAULL, 0xA6C783C01AA9A16EULL, 0xDAEC7A056F31A10BULL, 
            0xF439BC838DB0D998ULL, 0x0263D9316684967AULL, 0x2369F94C820265D3ULL, 0x7D804A829A0B9B40ULL
        },
        {
            0xFE006E23EC6737F0ULL, 0xC8A2DF7F74FF0B00ULL, 0xEF191F1F3C0B3F7EULL, 0xA6E10ABE5C0BA399ULL, 
            0x372F79330382DA85ULL, 0x30D47353C7A0F568ULL, 0x31604A11F5F0BEF1ULL, 0xD8B3A0E03C40F505ULL, 
            0x2672DD9FDAC5712DULL, 0x46F847A4C54CAFA2ULL, 0x6D3B31092929B85BULL, 0xD7E0D79BC875A14BULL, 
            0xA00D553F5F0FAD93ULL, 0xBC5E6CC041C2E2A6ULL, 0x947FBD31BE318234ULL, 0xAB57FAE0C432EB77ULL, 
            0x7BDDF5A882A3E350ULL, 0x2ED5D81081CBAECEULL, 0xC3988075C5F9DB70ULL, 0x567E7E47518F04E6ULL, 
            0x0CC4C4C6517961F6ULL, 0x55B947BFE4C80FA8ULL, 0x25AEF13B54036D00ULL, 0x9B82DC2C8AB367D5ULL, 
            0x368B5480F8D9806EULL, 0x8BE8FFBE616D456EULL, 0x044BAD40D967CCD7ULL, 0x056420E891A77809ULL, 
            0x54E913D7FD6DBFF8ULL, 0x3B8EC24CF01DF197ULL, 0xE93E73390485C809ULL, 0xD265782F63F109FDULL
        },
        {
            0x29BDC81B3AE0FC64ULL, 0x8744DCB7F0C94A35ULL, 0x76A8760596D6D5F1ULL, 0xA202BDD214314D03ULL, 
            0x4C5516E1B324D75FULL, 0x0E9EDE95EDABA39BULL, 0x06048627E9C66796ULL, 0x16208F708427AC6DULL, 
            0x80BD99396FAE8313ULL, 0x700AEFDAF9F6AC16ULL, 0x5472678D2609A931ULL, 0x036EA142F039CC1AULL, 
            0x784B8038777F736FULL, 0x7E27A345679565E1ULL, 0xB9CBB77275F48A34ULL, 0xC1CD95001E934AF1ULL, 
            0xB03F378FAC41B50DULL, 0x2940C7F2A923CFDDULL, 0x1493B8A94627785CULL, 0x6F73A4DF929F2ED0ULL, 
            0x5B93D21975513B8BULL, 0x4DCAE7F8AFEF8FE6ULL, 0x0D548B204C6B8C0AULL, 0xE0D6F9D1BC82813AULL, 
            0x7672ADD925A6FA73ULL, 0x2B15F478E56213F0ULL, 0xEDEE3102685234DEULL, 0x15F02921CF76AE12ULL, 
            0x3D74E36F2FB2F7F2ULL, 0xCE5AF766EBC9162CULL, 0x072CF47C3DE82B49ULL, 0x81B07BBBC42A7203ULL
        },
        {
            0x2956E756936DCCD5ULL, 0xFF38849E8DF2CD52ULL, 0x455BE5D71326B775ULL, 0x6EBD43D41E03C31BULL, 
            0x90F0BB815B4F82CAULL, 0x7094A8EB81A1687CULL, 0x5C0874F3524870ABULL, 0xFA0A5CAF50260E3DULL, 
            0xBE6B3EDB5B568A61ULL, 0x54238E286F30365DULL, 0x562156C1E499C16AULL, 0xAF65D1845C52D1DEULL, 
            0xC26329714E02874FULL, 0x07416E09E3F76745ULL, 0xE6DF60B7A742A1FEULL, 0x6E484A5FF1EB9295ULL, 
            0xFEA3860FCEFECF2EULL, 0xBD01425A03201479ULL, 0x5E8970A365817B3CULL, 0xACE13CD33DB7F23DULL, 
            0xD00918F4A703F918ULL, 0x8584A5B25AECE348ULL, 0xDA5B4E5CFFBAA64AULL, 0xFF2FCF5EF46EB1CDULL, 
            0x5961A0F721734125ULL, 0x51C112967745BD42ULL, 0x1CE750E737E586FCULL, 0x87A82572E6B13DBBULL, 
            0xB94AC29F5D9579D5ULL, 0x1E7A882BAA66BB57ULL, 0xDAB1157E278D76A2ULL, 0x4404A37FD29CA4A7ULL
        },
        {
            0xB97618BF927A260CULL, 0x94B166975434F6A3ULL, 0xAC53EC936A0AA06AULL, 0x64453E95AD9EE466ULL, 
            0x4AB0B4AEDBB28F87ULL, 0xFFA58ECB283DC2B0ULL, 0xC88162519176F5F6ULL, 0x7C981D5313E6B44CULL, 
            0x3DD64B7A2931EB18ULL, 0x4A6ECD04AA7BEEC4ULL, 0x8CF5339475061684ULL, 0x5A2180A83155DABBULL, 
            0xF290EA22D5E93946ULL, 0x4DA96848C26C8FD2ULL, 0x3F980C5F75BEF340ULL, 0x1802E82772CE2E28ULL, 
            0x76A762DC3634C78BULL, 0x54FDD8EC8D09E514ULL, 0xAE0C41C7B3A959A5ULL, 0x49FFCD2A5D0EEBDFULL, 
            0x423ABFBA0CBA0DC6ULL, 0x5E00EEF0AE5383F3ULL, 0x117B6DA4676FF1EDULL, 0x025C3CD4E4F0B107ULL, 
            0x6A64E60A0768D641ULL, 0xE2F5B77AD1BC3654ULL, 0x47E45BAA20ACFEB8ULL, 0x8704646E2147FF23ULL, 
            0x961C3EDBA4874343ULL, 0xB3702C7323ABBE55ULL, 0x2CAF331EC9FF6C80ULL, 0xC8F9CF622CD9C80AULL
        }
    },
    {
        {
            0xC7F6A75EBC6E2BADULL, 0x4FC302951C9948CDULL, 0x2BEDC108A4E3445DULL, 0x9BB784A7CCEB401CULL, 
            0xF2C03438BACD8F2CULL, 0x6A44F6DDA9472EA7ULL, 0x33C189629FFC80FDULL, 0x2D9AC4588A62A5E7ULL, 
            0xDBCFCEAC11F2F9F4ULL, 0xFD4A511F7629B0A4ULL, 0xD5B433DEA32F350DULL, 0x4621E509AC815DAFULL, 
            0x41CFBE015CE99701ULL, 0xC6425FE93133FE50ULL, 0x5FD3DFF3C5D69AC1ULL, 0x4757A71AB51F1231ULL, 
            0x6489F355975DFE98ULL, 0xFC9DE40268617334ULL, 0xEF6303737189CA61ULL, 0x1AF19EF0748650BBULL, 
            0x6B79892C750DD3EEULL, 0x7A71342F891694E4ULL, 0x3929AB151A976019ULL, 0xC7DACC4B4D68D77FULL, 
            0x518A72A8F3692C4CULL, 0x8D9173070C8EFA17ULL, 0x73B0D0E5E2E6CB44ULL, 0x838B67D00522BD43ULL, 
            0xEB7C96CF8317B8FFULL, 0x240B64A42CF9CFC3ULL, 0xE359F3DC13BF38F3ULL, 0x8DC61776C9FD1D74ULL
        },
        {
            0xA5AF4D7C483C1B52ULL, 0x7A28CD47B7CCA158ULL, 0x2F18CAF8D9FE10C7ULL, 0x8DA4DCCB891BEFF1ULL, 
            0xD60B4CF85F0BD2F2ULL, 0xFA2EDCDBE926583AULL, 0x93DE4D5F591B4C67ULL, 0x8F69B9B94780EA1CULL, 
            0x130EF1BFCD382D4AULL, 0x88C5AB2CE911ECBCULL, 0xF315B10314C9FF73ULL, 0x523F0BA29451F02EULL, 
            0xFE6DD5E3EFBF5A92ULL, 0xDE260ECE70B26D03ULL, 0x5E2C29049086364BULL, 0x539EC11A88AA8840ULL, 
            0x274F54720EA152D3ULL, 0x45D5410AD41CA651ULL, 0xC7AE7058EC26FBE9ULL, 0x059719E68EAD0A07ULL, 
            0xB3CE8F805224F39DULL, 0x4B7201AF3E5DE1AAULL, 0xC4F938320B587AC2ULL, 0xD0041C76BF205E05ULL, 
            0x21BBE674898F8672ULL, 0xA7163B79A5BE70FEULL, 0x136188BF31162013ULL, 0xB8F880F731129B24ULL, 
            0x877D92B5B94C727AULL, 0xF1314DA329375C73ULL, 0x81F59875D8427FCEULL, 0x73239A9647C16C3CULL
        },
        {
            0xDE8EF190A5247F82ULL, 0x9BB1869A09D7D473ULL, 0xB3FEF49ADDABED08ULL, 0xB8A1CB25B6306FBFULL, 
            0xA18B215355A85114ULL, 0x802248E2D2C7D297ULL, 0x45564BAD22057F38ULL, 0x990248E060A9330BULL, 
            0x832878C467617C5CULL, 0x5E80065D56F6AFA6ULL, 0xAF30153B59594F67ULL, 0x3835EF1F8178B5C7ULL, 
            0xF3251CAD953C77DCULL, 0xB0C8F844C4278074ULL, 0x194441DDE1E80558ULL, 0xA062275299FFD2B0ULL, 
            0xFC894D34D783DB28ULL, 0x49DA20F28749F4E9ULL, 0x9DFF60821D6DB82DULL, 0x2CC9D2271A02B7ACULL, 
            0xD5D79E04DF191D99ULL, 0x8F320715C59A19B1ULL, 0x93999A83B7C9F00EULL, 0x7F3E77F23A463686ULL, 
            0x2E2DE962B115CCABULL, 0x1477E9502C585653ULL, 0xEA60E3838BA4665DULL, 0x23220B10E33F28CDULL, 
            0xBFBC4F2EDEB746EEULL, 0x7F8C1A48E27968F1ULL, 0x32607B59A6461A14ULL, 0xD7B412D5530E356CULL
        },
        {
            0x4A67CBDF7735053FULL, 0xD395E7986543463FULL, 0x94B16A817A6CBCABULL, 0x232B0251F9120815ULL, 
            0xF94BDECBB65E5391ULL, 0x573636CE0F244E65ULL, 0x38AB0A0EA3A86145ULL, 0xEF25F21A7AE3FC64ULL, 
            0x6FAD669F1D0F189FULL, 0x430062E8A33992E0ULL, 0x7252F8E3A635201EULL, 0xFEC3F65ACC8B8CA6ULL, 
            0x400DF1E3E9903246ULL, 0xBA49199D7C49805FULL, 0x4AA4D0B440C7ABEEULL, 0x8483089C95C10307ULL, 
            0x79FDAABAEC7E157BULL, 0x4804ADF19D9EB211ULL, 0xB6A7AA5CE88CA528ULL, 0x2BEF1D0F5B6B5F35ULL, 
            0x46EA323DA0D6FDB8ULL, 0x24482F1E6C58DA4DULL, 0x6947CB478F359713ULL, 0x6D6D1397FA43801AULL, 
            0x2BF20B9EF1400743ULL, 0x3BE0BA8FAEC0C13AULL, 0x5F4050F8CCB3D164ULL, 0x98810A0DFB5A23ADULL, 
            0xCFF307F0AB011BC1ULL, 0x780D024A53EE6920ULL, 0xC2DCB746040B18BDULL, 0xA2B70276567B43D1ULL
        },
        {
            0x63D099AB550F870DULL, 0x3DE6FC8437FDCAAEULL, 0x5754726D8CA49437ULL, 0xD961D476325B50F4ULL, 
            0x699C5AF36CF4715AULL, 0x455455914AD692CCULL, 0x211035E238E51809ULL, 0x8482A4ED1B724B80ULL, 
            0x2D6D36DB1FA45080ULL, 0x4EB7EADEFDDE3A8DULL, 0x48C1C3D8D5713F82ULL, 0x9EF8B3D8C8526075ULL, 
            0x049981057ABEDC09ULL, 0xEE55C3BE474BC6D3ULL, 0x4C49DD6688A7553FULL, 0x95A3446B399D8F1BULL, 
            0x68F0FC9E90461B96ULL, 0xF93CE92C19DE6DDCULL, 0xD313802E639CD9E6ULL, 0x16540D0FF9575001ULL, 
            0x5A6B39C4FF04BD4CULL, 0xF25F6925B9089FB9ULL, 0xEDA6A9772D4720ADULL, 0xF5AD0EDCCACE70B1ULL, 
            0xEE73BBD1C0A06DB7ULL, 0x3A10C8205C6E3DE9ULL, 0x0CBDB925CD16C3EAULL, 0x7477E3C44E67006EULL, 
            0x7078A915F4F021BBULL, 0x0C3236E2126869DEULL, 0x39164E135162E6B7ULL, 0xF517463B7B53F0BDULL
        },
        {
            0xE57CB1FEBDA5E5FEULL, 0x459040E2595AF9BBULL, 0x03731C4F7B0E500EULL, 0xBF3F6F27AF9DB1BCULL, 
            0xF09A0B1BD477767FULL, 0xCFB85E7163729226ULL, 0x6471BFC301B5C84BULL, 0x7DC469A9457ECFC8ULL, 
            0xC0DBFA9BCE22C95CULL, 0xA7AC20229C36C516ULL, 0x03217517DE803FE5ULL, 0x1A0E43CC1894A448ULL, 
            0x00AA20EF0D5810EAULL, 0x1AF13399BD402764ULL, 0x6C70457AB502C4A1ULL, 0xEF253C0A3097DDFEULL, 
            0x0E567624DA2B39D8ULL, 0x254B3FBDED4B7802ULL, 0x19D251061C2526CBULL, 0x0EBEC4AADB7B8D15ULL, 
            0xFBDE1D9CBF42D480ULL, 0x26CD8D7C572C99A6ULL, 0xAB5D98D59EB70C01ULL, 0xCAE9F574C06920BEULL, 
            0xB7D8E100FDBDF482ULL, 0xFED62AF4AFDA4C02ULL, 0xC71144A8FDEB3C6CULL, 0x4DEF714E33476CCFULL, 
            0x12C7633E879613FDULL, 0xCBB51FAA33E9B4E2ULL, 0x391A0E5E19AE7D7DULL, 0x827FA8C9CD848B07ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Miram::kKeySpawnAConstants = {
    0x973C369C38E2F82BULL,
    0x9F9A49B3D8F23DB0ULL,
    0x1C2279C90C82584FULL,
    0x973C369C38E2F82BULL,
    0x9F9A49B3D8F23DB0ULL,
    0x1C2279C90C82584FULL,
    0x9162DF80B82C2462ULL,
    0x3CAB2D06395D7F14ULL,
    0x38,
    0x58,
    0x24,
    0xB6,
    0xCA,
    0x3D,
    0x2F,
    0x1A
};

const TwistDomainSaltSet TwistExpander_Miram::kKeySpawnBSalts = {
    {
        {
            0x5BB988893664B30BULL, 0xA21A2714752F8562ULL, 0xA1188E07E628D530ULL, 0xB1DD1262D18E4211ULL, 
            0x7E8C7D061B703B02ULL, 0x35C1082FC7C6DB91ULL, 0xB87068BBDDF01C54ULL, 0xAC764CB41446055DULL, 
            0xB123BA9FF48CB397ULL, 0x68FB904CC5DEB9C1ULL, 0x478777B334E365E4ULL, 0xCC77EABFD05B6ADAULL, 
            0x2157D1E98A7EF9AEULL, 0x6C572E8EFE16A883ULL, 0x7EEC6EE596051F32ULL, 0x333ADAD6F9BAA7B9ULL, 
            0xDDF3CE11395CB9F0ULL, 0xF99447C37C7BB038ULL, 0xD498DC0B031D6459ULL, 0xBEEE1E11E2B7F4B6ULL, 
            0x9E5D2FF6A3A43DC3ULL, 0x5B02B2C9925EFF02ULL, 0x24476DFE6D7E4599ULL, 0x0311F7D66C1FE659ULL, 
            0x34C97B942463618AULL, 0x5FB101BAA244B737ULL, 0xE1CD670FC916EDF9ULL, 0x5E323B599DC202EBULL, 
            0x5022697AC0A8E99CULL, 0x8843BE2B9F821168ULL, 0xEC64B3CC41CD7465ULL, 0x35986E3DAEC4F197ULL
        },
        {
            0x2710E3C26D4B58E1ULL, 0xB1CFD85189A475C1ULL, 0x2D910037CB409EECULL, 0x25087893704F29B5ULL, 
            0xADED46A68C25541FULL, 0x248085A54FC0E4F7ULL, 0x1647F613E26A4A5EULL, 0xA9C4041ECD613E84ULL, 
            0x14682868071C0FA7ULL, 0x5BA29F064999C485ULL, 0xDCACD0155121CD1DULL, 0xEA5D034407161FEEULL, 
            0x5CF5A8BBCB5BCA30ULL, 0xCA301E87B8D5F754ULL, 0xF5E388A8209F970BULL, 0x89FF6215A0B1DAC8ULL, 
            0xB55D5826FE615986ULL, 0xAC65BBB0C88D74A7ULL, 0x70BE74615B7B5FE9ULL, 0xAF0AE18421F6296BULL, 
            0x18F798FA07911527ULL, 0xF14593FD85C48CCDULL, 0x51655079F17F6113ULL, 0x2D0D1B2A5EB1BD71ULL, 
            0x20F34668F1E2F496ULL, 0xA71635094E60DFC1ULL, 0xF190B2268091D27CULL, 0xD0EC0E5D5F444ACEULL, 
            0x57B8C8CEE3DCED67ULL, 0x6FE1AD2F282C4BCFULL, 0x54D3DAF8A3DCA083ULL, 0x36F01348502771EAULL
        },
        {
            0x7A22388B06885DADULL, 0xBA1ADA1BFE947747ULL, 0x4AA02DBD978498E2ULL, 0xAEBE572B8AAC835BULL, 
            0xAAB19C6BDBA698A2ULL, 0xD72E8A1C9B9A3FDBULL, 0xD37E1CC7A3B340A1ULL, 0xA1CC1E9DA8814B24ULL, 
            0xA94E9AEB31DAA277ULL, 0xF4F7C4DD71E57DE8ULL, 0x94304F539558B522ULL, 0x62B16C2D708E9D83ULL, 
            0x847EE287901E7B12ULL, 0x482D65D2731514BCULL, 0x4DD3C9D6DDC2B5C6ULL, 0x43876E5AD37FF1FEULL, 
            0x8F658D345290E536ULL, 0x94153C839E74C65DULL, 0x9466605C601DB23BULL, 0x6DB572B670D560A2ULL, 
            0xBB5B4363A92E723EULL, 0xB5D6376782949425ULL, 0x23457491704FE480ULL, 0x2E12EEC73BD5B66AULL, 
            0x7CF7A8278F782CBCULL, 0x4848D4D6C584475DULL, 0x2843E8B00420AC1DULL, 0x8A0BF59F5CB050BBULL, 
            0x4D95E7363B828014ULL, 0x3D2C4EB31295034DULL, 0x2B47FAD261DBE96BULL, 0x291124ADCD09D9ADULL
        },
        {
            0x5FC36033064A1547ULL, 0x10FE4015960992F3ULL, 0x6B4152BF51C02BDDULL, 0xC1E3BD65C48F3D2AULL, 
            0xCB8BEF001A82F3FBULL, 0xAD04B501F0CEDA88ULL, 0xB5DE1F79506344E4ULL, 0xDB7662FFBA42C8E9ULL, 
            0x1254EE65B4DF6C98ULL, 0xB2C970D8F1A255B1ULL, 0x25BAC75B91FFB6ECULL, 0x14ED91B584D2AC30ULL, 
            0xEA514F478A3E9F01ULL, 0xA76F0C87C63F89FDULL, 0xF15B178C97678BC4ULL, 0xA8146E409FEA1DE4ULL, 
            0x5FD22D218F199E96ULL, 0x2FA9B9AFB06F1DE3ULL, 0x446F9134E7FFDCD4ULL, 0xEC59939DB8DE3543ULL, 
            0x405C560558EA0A23ULL, 0xEB869633517FB25DULL, 0x1B2EC3DD1A3F2DA9ULL, 0xF91EBC1CC4F9F4ADULL, 
            0xF3ABFAC72A66269DULL, 0xAF9D0F443CB731DBULL, 0xE27BCC40EC62B554ULL, 0x669869751F49D4C8ULL, 
            0x53AFECF3BD06050AULL, 0x0A41F1D4904524D7ULL, 0x01A194B996E233C5ULL, 0x5F9AA435D1DF5A6AULL
        },
        {
            0x934CEE939B1EAFF8ULL, 0x50E8C00190CA2F69ULL, 0xDA3FE288D925F1C3ULL, 0xCE3FA4EAB99A10E0ULL, 
            0xFF24B5FD3A5E9A53ULL, 0x922466886CC0C6C7ULL, 0x99DBDB0BC1D12FB3ULL, 0x403D9882F7DA0799ULL, 
            0x2628E0DA0488AD39ULL, 0x43605AA04C56D8DFULL, 0x121CBD08CFC13513ULL, 0x1055D7FBEA462E09ULL, 
            0x4E8EDF9977B6CCC9ULL, 0x6A34DB1BFD47EF53ULL, 0x369A646B89F9A30BULL, 0xECCF5303589B5E0DULL, 
            0xFAD404AD7C52D3F5ULL, 0x06B0E8A6462D61FAULL, 0x43F79175583A3D92ULL, 0x9A6F8911C7C6DAA2ULL, 
            0x95D4F766BE2F0FACULL, 0x7CB142A7553B4BB4ULL, 0xACFB03C32F33489CULL, 0x512198F7222F59C9ULL, 
            0x6A1D7BC3EA9CBC09ULL, 0x7996CBD472DC7E5DULL, 0x140D50CE51C22104ULL, 0xE82FAC7218F5053DULL, 
            0xD54D259D1F7FBA1FULL, 0x1F7227757004B106ULL, 0xFBC70023513DF453ULL, 0xF7C2570C5A0C747AULL
        },
        {
            0xCB1DB1A0D12DB5BEULL, 0x5DDD650A1BA75073ULL, 0x931497E2BD9CC57BULL, 0x7804F913408C3945ULL, 
            0x1C83B7C86C23A77BULL, 0x9CE686D8D043AC39ULL, 0xCD945955A12EC047ULL, 0x43B139FE0206D94BULL, 
            0xA3F8AEC726A88650ULL, 0x47B3BE4E253E9AD3ULL, 0x2C8889639ED46816ULL, 0x89CB69B1805C6694ULL, 
            0x9D7EE032D5D753B9ULL, 0xF8F486D9ABBA4181ULL, 0x4D9E2E050C04D464ULL, 0x81384B6EC2C9BAB6ULL, 
            0xD19086817EBDF7ABULL, 0x4E2FBBEA15281069ULL, 0x768C4DB82BFB6CB4ULL, 0x0A942BB18F1C5A7EULL, 
            0x411576F8C317DDBDULL, 0x3EB7415A14139A0EULL, 0xD4852340F244E10DULL, 0x2D02EE324E093B7DULL, 
            0xD39029679CDF72B6ULL, 0xCC4A3278800E4B95ULL, 0xB06D9AAE9408A98CULL, 0x872E666EDFC75D41ULL, 
            0xC5B4CA30774ACF3AULL, 0x36DEC214CF42981FULL, 0xE509C3870A0CA2C4ULL, 0xEC0429EFE2864320ULL
        }
    },
    {
        {
            0xC46D82C1EC35EC0EULL, 0x45DB7C8622A9743BULL, 0x03F630D48D2251FFULL, 0x71FBC7A2F285262DULL, 
            0xF3331A6C805D843EULL, 0xA7ACC6CAEED6D61AULL, 0xD14D9CD82303B9C5ULL, 0x3130D0F2D6254195ULL, 
            0x2D576AD2F91797C6ULL, 0x621AE8A592646FC8ULL, 0xC75D8183C9000E17ULL, 0x27FFF8FD1FA18339ULL, 
            0x453ECE5EAA5B0853ULL, 0xBE8B6F2D15F86C8CULL, 0xDE7764861A6B6E0CULL, 0xE73AB80CB3B62C3AULL, 
            0x878402ACD74C682BULL, 0xCDE294369F624DB7ULL, 0x95A5F17F3B12A002ULL, 0xE87EC6723D82BBFAULL, 
            0x42D0375F70E56351ULL, 0x8C7D1E88904944F2ULL, 0xF987209B9BED2159ULL, 0x713D8CE30FA05AB9ULL, 
            0xF3ED121274C568CBULL, 0x1B82810771179776ULL, 0x1E94ED9D42F6F7FBULL, 0xDB4807EC9432618FULL, 
            0xAAFCA0FC09E3863AULL, 0x9C52EB3B6CB05634ULL, 0x858343501E3B2B0AULL, 0x8EE4740A62240D83ULL
        },
        {
            0xDE1EF0F4B0BA4E0FULL, 0x7D8279838DBAC971ULL, 0x73961610ECBC834AULL, 0x7BFC229B8D91B0F0ULL, 
            0x225A95D00F2E1485ULL, 0x0609FBB6EC880044ULL, 0x11D0247059605D0EULL, 0x3676450E6D06E0B9ULL, 
            0x504D4AD08854335BULL, 0x3F87F82A09165CD5ULL, 0xD30C1F006F698382ULL, 0x00F4D30D912A58A9ULL, 
            0x68BC27AFE0D2A841ULL, 0xC664D922E14C08F7ULL, 0x8246E38078389DA3ULL, 0xC6D42C04B90A8A2AULL, 
            0xE119C260E7E961DAULL, 0x9C47F47671EB65EBULL, 0xABAF44C71734CDDCULL, 0x7975045A19D98F35ULL, 
            0x633FA28C44C61D03ULL, 0x06438942F99BC3F7ULL, 0x25EE60060B5A56FAULL, 0x24949A8D20A242E9ULL, 
            0xCD0AECE9457F8FAAULL, 0xC5D9D6CDF6280657ULL, 0xCC93E855EDA23C49ULL, 0xF8864BDEABB1E35CULL, 
            0x71433F54F0470944ULL, 0xCA5ED9740F5893D1ULL, 0x6A0620C859642453ULL, 0x6451558E1AE0258EULL
        },
        {
            0x995D102FFB2181E4ULL, 0x42291D9B7F4EB795ULL, 0x675695295CD6C676ULL, 0x6D271E758684D475ULL, 
            0x1A86DE0ADE0B5752ULL, 0x4659C7DD7631F0D6ULL, 0x8AC8906A32C71479ULL, 0x737E83616B740B5DULL, 
            0x0730586DCECBDCFAULL, 0xED4547DB7EA7B559ULL, 0x01D1530E6C118542ULL, 0x2591447A53E012EEULL, 
            0x2F5D240E9D19041CULL, 0xC72B28826C0D32D7ULL, 0x33F72FFFC46AC966ULL, 0x693C6C0E4419E4D7ULL, 
            0x7B3D86FB64C8C6FDULL, 0xF768C6BE1702B304ULL, 0x9673F5FFC8974C43ULL, 0x44ADCC7DEF294B0AULL, 
            0x3D4010E90E6C8C99ULL, 0x75061DE928147494ULL, 0x6A74CC00ECF87517ULL, 0xF3C54A6920A5149AULL, 
            0xD00356F86E2085D9ULL, 0x53E27F191065E84CULL, 0x774E07A651F74202ULL, 0xDB320C1EA5C9AF1EULL, 
            0x5121E9AF91585EEBULL, 0x6C894553C3F7147EULL, 0x449A0D8FF6C54AC3ULL, 0xBEB77E9E7F65F203ULL
        },
        {
            0xDA3BF6D121CB700CULL, 0x2545C718CA6EDC12ULL, 0x75BB34D9818C5708ULL, 0xAC45097308BC1D80ULL, 
            0x69F46C233F130435ULL, 0x8B9A714428626688ULL, 0x7BF1282D58A82E53ULL, 0x1DB7D703FEC86120ULL, 
            0x7D2BF3A6ACC613D1ULL, 0x9419BFAA575C19E9ULL, 0x48FE7649EC75879FULL, 0x272BC9FA3296A475ULL, 
            0xF64730FF7A2C3FD7ULL, 0x10D5E552FE6DCB22ULL, 0x0C96A78C5652DFF8ULL, 0xE73457431233E67CULL, 
            0x9BBE21BBB5E71809ULL, 0x1915B5AB392EBFE0ULL, 0x3068CD35D562B9BFULL, 0x658DF22BD4F41A75ULL, 
            0x90AD30706F4C0850ULL, 0x7A59719D47931E85ULL, 0x702851F0B278AEB9ULL, 0x315D1DA1CB9B4E1CULL, 
            0x9328CF3AF70002CDULL, 0xCDDF55DF52327338ULL, 0x8D9EFC7A91E91FCFULL, 0x0E41564D474C6485ULL, 
            0x1D0AA29713179B8DULL, 0x64EAC37FB4E3824AULL, 0x2F25DA122FF563D7ULL, 0xE76C524BEA1B3284ULL
        },
        {
            0xBD3F1DD2F5E299D6ULL, 0x674843B2D97F63ADULL, 0xB4C06BAF0B4F42C1ULL, 0x85F9024E4341C10CULL, 
            0x87D469EC04DD26FDULL, 0xF3171B40A519396BULL, 0x5B8B6352605AF4A5ULL, 0x6F13A2ACA6D1DD5CULL, 
            0x6123DCAEB7C2C2D8ULL, 0xC241033FD6D5A367ULL, 0xECFB3FCC521C4C38ULL, 0xFB8C815A9907E48EULL, 
            0x31550C52619C2A23ULL, 0xC9294BD53B7AA86CULL, 0xE4899ED90D1930E4ULL, 0x68A2F4A1F6957971ULL, 
            0x10DF4E90359B49E9ULL, 0x2209074D37118049ULL, 0x8BF31D6773DA4978ULL, 0xC2F124BB0C1F6F2BULL, 
            0x75DA2599F793A9D6ULL, 0xAFCB8C01EEF0C4C9ULL, 0x34C29203738E1B33ULL, 0x82823C8D2AF7B95EULL, 
            0x3985ADAE2F9B9406ULL, 0xC414F5180836B628ULL, 0xA08BC5D0822CE765ULL, 0xE78D3B8A1F8942A3ULL, 
            0xA65B691AD423E995ULL, 0x2C8C30D62EC1E8A2ULL, 0xA44338AE09DC16F6ULL, 0x1DBF1F12EB5BCE98ULL
        },
        {
            0xBF4760796C1A0285ULL, 0x717C98308E2725CDULL, 0x96D78BB6F4189CBEULL, 0x9202BC05E108B948ULL, 
            0x189163F117F5EFBBULL, 0x4EB34EA1CFEEC514ULL, 0xE42857D32C9D4B4CULL, 0xE6870D6FB6058DF9ULL, 
            0x5C8099D035900932ULL, 0xEABBE3243669C911ULL, 0x7BF5397F6119532AULL, 0x4B500EFE98843FC3ULL, 
            0x784335F5F3360A3BULL, 0xB69BA976DB39D59BULL, 0xEFCAFAB201FBF706ULL, 0xE8ED0FCB66CDA0E6ULL, 
            0xC5C0590021641658ULL, 0x088AD4040126ED83ULL, 0x2F19434639CAF155ULL, 0x6EFC0F4B3935BE95ULL, 
            0x8A3FB95C68587748ULL, 0xA3E184A811113090ULL, 0x1BE7D9B94A890483ULL, 0xED8D521D4256BDFDULL, 
            0xA42336AC7C7C8A5BULL, 0x8C6EC46FA2B54C76ULL, 0xD13BF86DCC63FEDFULL, 0xFAADD444B97ADFDDULL, 
            0x97E216D4AFE32E34ULL, 0x86A723646727CBEBULL, 0x533DC09BE15291A0ULL, 0xA646A9D25E642EB9ULL
        }
    },
    {
        {
            0x8FF94FE55009D571ULL, 0x3FCAECD310C8D888ULL, 0x487DD7931AA2FF2DULL, 0x826810D5B9542379ULL, 
            0x7FE66C100418AEFEULL, 0xB76C387F4A46D5D8ULL, 0x0375ABED89039092ULL, 0xC798BF25BCA627E4ULL, 
            0xE920DEE0C0204DA1ULL, 0xC263F8FFEFC4ADF3ULL, 0x1E51270061D1476EULL, 0xDA2269F9BD714C1DULL, 
            0x32633012F6414C63ULL, 0x0EEA2286F5E1BD41ULL, 0x9ED0E6A47205939AULL, 0x2C6D86BF91A4FDD7ULL, 
            0x8BFC80A490D12D69ULL, 0x402DB06976D33404ULL, 0x2546A0066DC1A61DULL, 0x9F7D532470C73A4EULL, 
            0xE7A1D8781B925A9EULL, 0xFE10B01209EAEF6CULL, 0x9624C5B8EB863053ULL, 0xEE6D851D2AA3EB4BULL, 
            0x519B46DCD436EC5EULL, 0x0F6BBBDFBEFA0449ULL, 0x74FEEC35CD70FB97ULL, 0xAD944CD85554F48BULL, 
            0x613EBE032A641D6AULL, 0x393D99FB11AEC139ULL, 0x0FC35E89A03EB64EULL, 0x483440CF3E144D54ULL
        },
        {
            0x167B6D3CF8CCE3E9ULL, 0xB34D2556886982B9ULL, 0xE3F31558BFA7D3D3ULL, 0x969034B460102320ULL, 
            0xA087B7BDE8560EFFULL, 0xD352D6E8FA4FE778ULL, 0x1467C3C388CBFA4DULL, 0xD93D5F0F9238D86DULL, 
            0x7EFACF7D42650ED3ULL, 0xE1888BCE3CE00D71ULL, 0x46D3F422EDF69ADBULL, 0x8AF3B5EC4F3D245EULL, 
            0x609ADF3DBBA4014AULL, 0x87730C8469572BAAULL, 0x48CE20BCBEB488D4ULL, 0x9C2D4AF1E60CF783ULL, 
            0xBDCCC99E4B71A518ULL, 0xBB7305D144172D35ULL, 0x66717AB0F2C83BFAULL, 0x1AE8A55EC16709F4ULL, 
            0x72E2ED3F3A043390ULL, 0x1FD60EE1F1994899ULL, 0xCFDD36E8CCB8B839ULL, 0xE88FFC05298AB6E5ULL, 
            0x7B0D33B4FDF70BBCULL, 0x7C8DBC30694B9941ULL, 0x0A3117673146CF4AULL, 0x87878EB93F16A093ULL, 
            0x40C37EC3AF7C1FD6ULL, 0x93CFC45366F51459ULL, 0x8ACCD8A211F6D6BDULL, 0xD4C7D27663FA3E79ULL
        },
        {
            0x74BB1D38980E123DULL, 0x31047B2A3CFEBB83ULL, 0x597B851F02FF086CULL, 0x4ECFDEEC1928FF4AULL, 
            0x30ADEFBE69CA5CFEULL, 0xCC3F0A9176B2C90CULL, 0x64564CCC4F233D39ULL, 0x038EB5EF33ADFC8AULL, 
            0x18FDAF070715823EULL, 0x0665C0A2B7ED69E5ULL, 0x3E5B9D0EC666CE9CULL, 0x6857805A43900B64ULL, 
            0x3BB62260270A5D05ULL, 0x3E7CA6C303C0DA84ULL, 0xA6B0F818D21F4488ULL, 0x6890D0E3C07E10A2ULL, 
            0x6DD3ADB393A53BF0ULL, 0xB0D9A77B34EBF541ULL, 0xEB483C97C1C2821DULL, 0x9337AF93B278BB79ULL, 
            0xFBF95D5378B3B8E9ULL, 0x2FB66985D8E7CC8AULL, 0x7B9AF683F9DDA376ULL, 0xC69D31B43285DD96ULL, 
            0xE0B3354DFBBB692FULL, 0x8BE3C6B2A64AEA76ULL, 0x67414687CC61E1EFULL, 0xD696A4C96E4B6441ULL, 
            0x4AD4361528CE79A5ULL, 0x1F3EF43C4DA811DAULL, 0xB350CA118BBCC4A9ULL, 0xF3C28F2AF54D6773ULL
        },
        {
            0xA73B77D51D90B3D6ULL, 0x7D2DA865A853133DULL, 0xA5104E19F24CE234ULL, 0xD77D10AD6E4F8840ULL, 
            0x11D76DB5AAF94835ULL, 0xBE15FC134E75784DULL, 0xF11AE62DA5EE2F04ULL, 0xF6790023E5EE9F86ULL, 
            0x84EB9A642CD8F901ULL, 0x295B878C89843105ULL, 0x422CD0DD2FE83D65ULL, 0xE1E38880DAAC08C7ULL, 
            0xFA0C8FB878AB8BE7ULL, 0x00916DC76CA3774AULL, 0xF05C71083413DBCDULL, 0x2C0D7BCBCCFD08A0ULL, 
            0xB2728A48203E57D1ULL, 0x516ACB1E9D9FF32AULL, 0x1799C4FA441002AFULL, 0x304CBC43CBA3B32CULL, 
            0xF9C5B0F3E5C69390ULL, 0x2AF8E796278C72CCULL, 0xD4AF9A0760CF130EULL, 0x177A801FF85C95A3ULL, 
            0x8D4C082110582454ULL, 0xB479F59B6D5D40A3ULL, 0xD947F51E9030FCB3ULL, 0x46F09EF692512C3DULL, 
            0x4138FCF429866353ULL, 0xD9A792C211D73C6AULL, 0x9D0E6F13EB15C553ULL, 0xE1A13FFF11FB50B8ULL
        },
        {
            0x44C8E955C8A569A5ULL, 0xF23C7EF445F79039ULL, 0xAEE4788D55F1E02EULL, 0xF5704D7C01A3A05EULL, 
            0xA65271573C5E5493ULL, 0x86C31003C1D043DFULL, 0x116A67EAACEF23CEULL, 0x3BAF02A467484C8BULL, 
            0xFB758ACC3F26D6D8ULL, 0xE93D2AB3DBDD41E8ULL, 0xB2B4E866F60554DEULL, 0x4F127A442444EE6AULL, 
            0xCFDDC461440A332EULL, 0x83347C0F40D61DFEULL, 0x6EF99EABC25A0164ULL, 0xACD22CCB2BB02141ULL, 
            0x8D4D149F073E465FULL, 0x307F1CBF29821BAAULL, 0x9F7733041E8E6587ULL, 0xF22668A12E2D51AFULL, 
            0xE58A35E21BD57A64ULL, 0x2370AADEEBBDE32DULL, 0xD98630F79CA6D287ULL, 0xD94958B4CD17026DULL, 
            0x19CEEAB1510918A2ULL, 0xC4DB66344D09E12EULL, 0x26C9470D95E14521ULL, 0x1B3722964E41E484ULL, 
            0x26905ECF22099C67ULL, 0x89EF8E2ADE6F55D6ULL, 0x4297FA5A9EA75B44ULL, 0x7EBDAF8B4E336EC7ULL
        },
        {
            0xE7B1BDA46D41099FULL, 0xF04C7D6EE7A67880ULL, 0xB0ADEA160D856009ULL, 0xBCC3149A36AE8CA9ULL, 
            0xA72319B8C0B229FBULL, 0xB675A82538588C8FULL, 0xF17360C3664957DEULL, 0x516D0670E2C1EEFAULL, 
            0x7D8F7E845DB7DC44ULL, 0x30E3DB807CB9D12EULL, 0xCDD6BFB46249CD98ULL, 0xADCF37E7AD7FFCD0ULL, 
            0xBF67345532DF7CF9ULL, 0x075E08A7A5CE1F62ULL, 0x01FCD58DE2315D3EULL, 0xA3D5089C9932E360ULL, 
            0xC251D4A67BB61C31ULL, 0xA09D16A33F3C214DULL, 0x7CC4979E183F184AULL, 0x65EDCD05F1275527ULL, 
            0x5BF651D77AB5A3E1ULL, 0xA84C63AF1F6010CFULL, 0x6A1449504BB905F2ULL, 0xB7A062CA0099FBEAULL, 
            0x30B8ADF8E300B831ULL, 0xCE45EFC8BFFC56A0ULL, 0x78C306A99E1A780EULL, 0x5111291FE4627B13ULL, 
            0xCB105D33926D32E8ULL, 0xC0EC45B07153A7D8ULL, 0x09E85F03A6F5C637ULL, 0x6E4B0772C50C4EAEULL
        }
    }
};

const TwistDomainConstants TwistExpander_Miram::kKeySpawnBConstants = {
    0x7DF4A1B96269D1F9ULL,
    0x15D773DA9A988A56ULL,
    0x1CD749A89D453804ULL,
    0x7DF4A1B96269D1F9ULL,
    0x15D773DA9A988A56ULL,
    0x1CD749A89D453804ULL,
    0x45BFC97566509D3CULL,
    0x0D369F4BCCEC4D56ULL,
    0x89,
    0xA4,
    0x23,
    0x69,
    0xBD,
    0xAE,
    0x11,
    0xE7
};

const TwistDomainSaltSet TwistExpander_Miram::kSeedSalts = {
    {
        {
            0x84CE64C02F4FB342ULL, 0x41480DCB27E8ADC0ULL, 0x96BAC7FF92AAA25BULL, 0x60F063731F20C3B3ULL, 
            0xD577A7BED41418C7ULL, 0xBC4CEF788C9419C7ULL, 0x93FA5F5C5A2B0213ULL, 0xAFE1838A87EC0696ULL, 
            0x3832D5EF504EE779ULL, 0x50821B8CB7EC1F3AULL, 0x95B37CA186B14A6FULL, 0xF70DA16F13FF76BAULL, 
            0x3925686304845573ULL, 0x6D8010BDF133C2B0ULL, 0xD175D066F392CD73ULL, 0x2F3961DCEC41A68AULL, 
            0x0B2C8A393D53363AULL, 0x3DD2CCFA03867606ULL, 0xA223355343736FA9ULL, 0x98E131D8E54E43A6ULL, 
            0xB129BB33516163F4ULL, 0xED561C78E1E07D20ULL, 0x2C44DE495DE06491ULL, 0x83C0ED1090D92437ULL, 
            0xDC172B8640AA20DBULL, 0x50FEDA59839857A8ULL, 0x704263588A40D9E6ULL, 0x1E785128EE53F0EFULL, 
            0x095122ADC9CBC6FDULL, 0x7D1A513C27CA3C25ULL, 0xDEF0C22998A22EB8ULL, 0xDF38AA7C1151EF63ULL
        },
        {
            0x6D18E952A1DF5050ULL, 0xC7C3343BA6643E01ULL, 0x60A53538AD2E6AD5ULL, 0xBF2A93967AC02FDCULL, 
            0x04E86A6CF5FF9B64ULL, 0x2D235BE10700B261ULL, 0xE283864138AB179CULL, 0x1DB307A47198903FULL, 
            0x69E2A10384CA01BAULL, 0x574CA77C985A2769ULL, 0xF0F0A51D3EDDF428ULL, 0xA26CB910A4B6ADFCULL, 
            0x6CA50D9D98E10DF0ULL, 0x122D21189A9712B7ULL, 0xFB9A1056373D0812ULL, 0x7D5EC072D8F123A6ULL, 
            0x7C6044E074ABBB85ULL, 0xC13818B1509366D8ULL, 0x9F0AF5202B547814ULL, 0x1220D42CF3AB2AF3ULL, 
            0x408EF5515E5A5861ULL, 0xF2F235DC76C1C62AULL, 0x0FA5A89478D2461CULL, 0x4DB2B85282D5E66FULL, 
            0x4E4E64C9ED9E9756ULL, 0xFFA4E6E2CD15E683ULL, 0x8EB1B2949EEDDEE9ULL, 0x8ED059095C5E6B1AULL, 
            0x744641D2AF7CE617ULL, 0x818327F0B7FE27F1ULL, 0x78697A08A6DFD1C7ULL, 0x3F5E05454F5D7222ULL
        },
        {
            0x6025B2F5D06DBCA3ULL, 0x4885FAD31C643F1BULL, 0xCE9DDE5A0228B04BULL, 0xB5BB09BBF7FDCDF8ULL, 
            0xA62CFEC721FBE608ULL, 0xC8CB3AD4523C8C63ULL, 0x993CF0BF0A885534ULL, 0xC8209918D49C6AA8ULL, 
            0x0281428EC12192D0ULL, 0x1699156DA3E69A00ULL, 0x81DDCA3842DD8D59ULL, 0x51CB135A87866401ULL, 
            0xCA44698A1946B86EULL, 0xC882834CE625BBC5ULL, 0x82CD3F92C2947691ULL, 0xADC000E7BDF795EFULL, 
            0xFDB80396DC6F19C1ULL, 0x53CC8009BEC63E37ULL, 0xC4E81CAC1F150F68ULL, 0x92027E83FAA361BFULL, 
            0x9F4D4340738BD5CAULL, 0x9AD5309697E3E645ULL, 0xCB8221483CCE44BDULL, 0x878D9E9B1833B04EULL, 
            0x9F46592D4DE3BCF4ULL, 0xE8B40AFF5197378EULL, 0x807CB39BC4093BA7ULL, 0xC7F7290CE5F5F244ULL, 
            0xF75EBEE58E58EC48ULL, 0xFB59EEB74B15B5DEULL, 0x9F3C9F17C76065A7ULL, 0xAF8F381A05ADCC4CULL
        },
        {
            0xF098B5D40EA4B8EBULL, 0x2B1D4442D974136AULL, 0xFD179D2A46BC8562ULL, 0x645D3BFA59C1A7C1ULL, 
            0xD98B6908AF84B185ULL, 0x9819550AF77505EFULL, 0xC4378DA4615C7D7BULL, 0x70E81DB0691CA1CBULL, 
            0xA53545133336AA34ULL, 0x8CB154900B567750ULL, 0x1CA4E7EA0781576EULL, 0xF141D0D481E17605ULL, 
            0x77C2B101202B2F72ULL, 0xD42C481CF869C13AULL, 0xC53CD4C77E43F932ULL, 0xE48D853F15A0B2F1ULL, 
            0x1AE29486B6F77AA8ULL, 0xFA00B6DA39CB2715ULL, 0x7E3541564343ACFDULL, 0x243A388644CE7C9EULL, 
            0x285B5A7CE62CA530ULL, 0xDEC4CB39F54AD813ULL, 0x7496EB9B5B5C31D2ULL, 0xAE108A12F61C546BULL, 
            0x48A42DE3D24926E8ULL, 0xE3B944838D126FD6ULL, 0x24F341263E223036ULL, 0x2D21E9C6D310EB25ULL, 
            0xDF4724BC0D3AFC53ULL, 0xE066359652E7BD75ULL, 0x9EFC01F81858835EULL, 0x302225601D6E5FF4ULL
        },
        {
            0xA4E2187D0A49B4FEULL, 0x5180E443F957A67DULL, 0xD56310E10ADFEFAFULL, 0xF2E5E9AF37AF36C0ULL, 
            0x4C398BFF072AC149ULL, 0x732091E832A5E81FULL, 0x2064BBDD8AB6F9E4ULL, 0x2E4B71F0BDBE9AF5ULL, 
            0x7A4F9203D637B5FFULL, 0x16BCDEEE06745857ULL, 0xDD09E1143FAD6A16ULL, 0x4BDE4F0A7A284992ULL, 
            0x3E30F62002E0DF27ULL, 0x1B04C56B63CBF861ULL, 0xCD312F8EF7EC92AAULL, 0x145C1D4E900F81CEULL, 
            0xE2891837E730C5EBULL, 0x31E6A7F53FEDF962ULL, 0x4D9DA65495D1E875ULL, 0x71B5BF94535D3427ULL, 
            0xF2D15312B8CA218BULL, 0xAC70F47C2CC108C5ULL, 0xBE640E45F6A6EA26ULL, 0xB909B49284F79036ULL, 
            0x8D10BA80096B7C0FULL, 0x555B4B2723B34088ULL, 0x7F5294A89DED9CFEULL, 0x2A8A11541404ACC1ULL, 
            0x18977C310B135580ULL, 0x309C8ED78289D814ULL, 0xAC011303A41F8FC6ULL, 0x26FA8E03CDE526F9ULL
        },
        {
            0xD0EB0B379E7E9AC8ULL, 0xFED8880890203B26ULL, 0x64C2002C829C43A7ULL, 0x51F24520836B44AAULL, 
            0x8FC5B71BD89CCDACULL, 0xBF87ECEEAC1B558BULL, 0xB0836C089E2440BFULL, 0x31A3953401C11021ULL, 
            0x736CA01290ED2F70ULL, 0xEBBAC33E8056265EULL, 0x51E259DDE452FC6CULL, 0x1B554A37A03300F5ULL, 
            0x82C82C0FD86F2834ULL, 0x3F117B34ABAB0C78ULL, 0x7E487FA6C0EA1AD2ULL, 0x9B1AAFD59BC13753ULL, 
            0x9EFAC24FAB406FF2ULL, 0xC98430F65C8F2DF9ULL, 0x1E009D24B19237B5ULL, 0xA8B3E4E9A3462F39ULL, 
            0x08113991FD4BDF7BULL, 0xAD8D7E4642886E8EULL, 0x9E846EA5F337BD44ULL, 0xAEB8A6411770CC79ULL, 
            0x9D05343E640AF8A5ULL, 0xB94DD6138FB3D4F5ULL, 0x1DD18E8AB9D2318BULL, 0xF0AF5648F0BB1F31ULL, 
            0xF378AFC58A72EF1FULL, 0x727FE0701826C02CULL, 0x5CCB736A2F9DAFD4ULL, 0xC021A3DD422B3F99ULL
        }
    },
    {
        {
            0x0CE39BAE3379B6D7ULL, 0x80C21EAB1EDA9762ULL, 0xF70B9A216F9E9E78ULL, 0xCFA7E27514E801E0ULL, 
            0x92370B3071D5CC0CULL, 0xD5FB98B6D6D6880EULL, 0xCE702EA617682FD9ULL, 0x77556CE620252B0EULL, 
            0x40A37C328EDA1B72ULL, 0xC8BA33C6900CEC66ULL, 0x8DD45BFA32796531ULL, 0x5FA676BD2519B23BULL, 
            0xBD27BB2D32F7E2E4ULL, 0x059C6D0616B0F5ABULL, 0xC547332500D291CEULL, 0x7567DA5E007CB172ULL, 
            0x5496AD177F5F4A43ULL, 0xD9824E822D8071CCULL, 0x093BB32158D3A3E7ULL, 0x1EDB63EE749276D7ULL, 
            0xD2D8B128F74B6529ULL, 0x5556FD9C8498C4FFULL, 0x14536E3A2091F7C4ULL, 0x6278C821D979DBCFULL, 
            0x5AB8DEEC1B1FA976ULL, 0xBFC96F2FFB70B9D1ULL, 0xE63C43A5B6DD50A3ULL, 0x05212B5C2D09C60FULL, 
            0x8D4C3D07C5873B41ULL, 0x4EDCDD0741AB4C99ULL, 0x11E7F95A782CD57BULL, 0x1F0A9C7E81E2DC60ULL
        },
        {
            0x256161D7C28B2A7CULL, 0x1EC2A0D66AFE65E9ULL, 0xFE38B76765317590ULL, 0x40B2728E09EB8403ULL, 
            0x4FF2786016EB6681ULL, 0xAAE62B20D6998EA3ULL, 0xBC4DF77B0E7F6EB1ULL, 0xC2B615F1199BCBC9ULL, 
            0xA317369148032B0EULL, 0xF5F8004ADDCE218AULL, 0xBFB7757DA9F5E4F3ULL, 0xD95006352FFEA9A1ULL, 
            0x7305A829903BFDEEULL, 0xAC606325CF37A828ULL, 0x3C430A310D4CE4EDULL, 0xDE175511D59CFB64ULL, 
            0x2BCD9A6F30BD0579ULL, 0xF379C2D98B03D16AULL, 0x966408D87A2797CDULL, 0x928269F15156BF36ULL, 
            0x11A81DE0F1F15603ULL, 0x7DAF344252E36549ULL, 0x4B64DC84DF41D5CCULL, 0x79483E13DCD1BB63ULL, 
            0x1D845CE329F8FA3BULL, 0x48C93DD6907F2F5CULL, 0xC4B0B39ADA67BE84ULL, 0x62B93D902FD1EB97ULL, 
            0xB05DEC8EC0FCF484ULL, 0xC125450437436EA1ULL, 0x2F8B17597139BF95ULL, 0x33B9C881CABE643EULL
        },
        {
            0x7BA814DB820A4245ULL, 0x5754A80E51041DF6ULL, 0xE2CEB3BD07116847ULL, 0xEFE0FAB42975F5CBULL, 
            0x0779C8628FFDFC60ULL, 0x8D86FE70F4D2E844ULL, 0xC91B7FD8D562DBF1ULL, 0x78C17DA76EFC727CULL, 
            0xBCE3CA66D7808A62ULL, 0x1E93594A86A01424ULL, 0xBE7AECA06B6BAC1DULL, 0xCB605C13285C7201ULL, 
            0xF8F4251681877404ULL, 0x9DC6130C198AB25BULL, 0x6C277A6640BC1703ULL, 0x69F0B5316D58F488ULL, 
            0x2C2A5662CA8C9F74ULL, 0xD4B66E14816C3050ULL, 0x39F5E9FDF6190E31ULL, 0x9D7DB65BC504E42AULL, 
            0xC29FBDCA31593156ULL, 0x96253D58AFF8D289ULL, 0x6D8198E7ED3041F2ULL, 0x7EAB230F389A7675ULL, 
            0x34B50B16DEE94267ULL, 0x4630BA966B786706ULL, 0x864FE4BAF58890B7ULL, 0xB0B97035D2B81CC3ULL, 
            0x98AF419F4D4C3E90ULL, 0x68B90682C6D98BC6ULL, 0x8EC1855D0061C340ULL, 0x122B099BC8A46072ULL
        },
        {
            0x34BEBD2218544105ULL, 0xF4E5915FD0C0A40AULL, 0x5449C8C834F8590BULL, 0x30C9EF3FBFFD7C78ULL, 
            0xE6177AC1BF68CD08ULL, 0x1603CFD44690E61EULL, 0xEE1A52D50147C648ULL, 0x4D589EF742FDD3DBULL, 
            0x624F8BADE641395AULL, 0x909F3D18B7EE2B15ULL, 0xE9703FBD213E4DEDULL, 0x58DF38BD7429C28AULL, 
            0x2E9E976AA32512F2ULL, 0x03ED54808AEA7207ULL, 0x368F6189EC520B42ULL, 0x87448386B8EEA962ULL, 
            0x6E2DA90B085903C5ULL, 0xA3CA8BE4EDF6AEB7ULL, 0x03F53B7315CA261AULL, 0x596ADFE3C305FFEAULL, 
            0x763768A7B865EEF7ULL, 0x76B51E672F1182BBULL, 0x68BBBFA1B7ECFBDBULL, 0xC4C691C144CD65F4ULL, 
            0x6C48D5AB36C5A910ULL, 0x6E028153FC8BEB8FULL, 0x6D8D7A926261537DULL, 0x8E82BA56EB11EB42ULL, 
            0x5B2187E752459BF9ULL, 0xFF6D24E4C72F0BA5ULL, 0x6B5B671E413A5DD3ULL, 0xE40B814C93CA196CULL
        },
        {
            0x8A119C3C8603CDD6ULL, 0x3BFE5BC3800FFC7DULL, 0x8E8E52DF74D6DAEAULL, 0x5E8E2E705BBCC010ULL, 
            0xFB81F0E638CBE97DULL, 0xFA4958ECA8A0F121ULL, 0xB61B049BAF0CF38BULL, 0x07274734451CA8DFULL, 
            0xE0B31B1EF82CA7D5ULL, 0x26A54B30B7E9894BULL, 0x9B29C4EAFFD4C68FULL, 0xEA248AAB63558790ULL, 
            0x71D17460BF8ACB02ULL, 0x3F9275B2F4A8C311ULL, 0xF07C0B00919F38C9ULL, 0x0A9B358D77A971BBULL, 
            0x533636FF62F07A75ULL, 0xF9E10D5DC06D5041ULL, 0x4B6E4D5CF702A5A9ULL, 0xD12D56CF0A9B841BULL, 
            0xCADF05011214B303ULL, 0xE3BEDB407E0C00B1ULL, 0x8B56C175FFA66202ULL, 0x0776E6B641DFA7D9ULL, 
            0xE2288F44CDED3540ULL, 0xF51E91658BEB4F49ULL, 0x9537A8406D115947ULL, 0x3522D1D9B1DB225FULL, 
            0xCCA674B67817F752ULL, 0xDF2BCEC15DF478D4ULL, 0xC93E6C111A4FC0DBULL, 0x846D8EBD52D0E7F4ULL
        },
        {
            0x9256E3358D0B1201ULL, 0xBBF75F4519F7196AULL, 0x9E881B4A029F6396ULL, 0x310EA7E145847246ULL, 
            0x4281B1DFB70A1896ULL, 0x70E9EF30319B1E15ULL, 0x82E9D6A228ABE289ULL, 0x3B95E204510FC5D2ULL, 
            0xA4E69745FBFBF660ULL, 0x87418745EF1086FCULL, 0xA8E279D0CAC1FBC4ULL, 0xD8D7644B78728191ULL, 
            0xB352F9320AB72D64ULL, 0x5B4F0DB2EFA98650ULL, 0xEB5985ADFD11A175ULL, 0xD0F5E734C5A54E0AULL, 
            0xC0E108EF47C2ABD5ULL, 0x825D53901576CA57ULL, 0xF0B4148D94655462ULL, 0x0AE68B586400C7B5ULL, 
            0x0167196FA0B489C4ULL, 0x1A811D8BC8B0CEFFULL, 0xD59C4981A92D0D7EULL, 0x01294AC2DA7F4B7AULL, 
            0xCFCB35D74211193AULL, 0x8C62113CCBA120C2ULL, 0x59B77FCD17629829ULL, 0x72A3B0DEB2F68BC8ULL, 
            0x582D2C415349F740ULL, 0xF72730A20C2F7382ULL, 0xCB9C92ECBEBA5643ULL, 0x50B64F972055C29DULL
        }
    },
    {
        {
            0xF56C4CAC31627394ULL, 0xAAF9EA450B838D7CULL, 0x082B2672A896073EULL, 0x01B142E0464E37C0ULL, 
            0xFCBD3EB33794EC59ULL, 0x9AAE6331D9F03FE2ULL, 0xC3749AE5FA9596CFULL, 0xE26E0F9E70ED8123ULL, 
            0xBA911AE9BEA10F53ULL, 0xE4AF0B84F894695AULL, 0x347D468097676BD6ULL, 0xE84A0B9037BFF437ULL, 
            0xF775F17C42A8F21FULL, 0x159CFA8209E4078BULL, 0x49E08DBA38FC90A7ULL, 0x608CD5715DBC2D1AULL, 
            0x58DFFCC381C752A1ULL, 0x469A38DF2BC8BFF6ULL, 0xD4BEE077B8EF15C6ULL, 0xF9EBE8EDA73CF0ADULL, 
            0x47786344059497B6ULL, 0x62204F928D58B85DULL, 0x9B01911E175BED28ULL, 0x7A7263298A5038DEULL, 
            0x8A50DDB3926E168BULL, 0x3343718F38A5634DULL, 0x2AB8EEB5C406AF0FULL, 0x6A0F78A6376F8A2EULL, 
            0x1DC68BC5ABEF7893ULL, 0xB14DC3800E9383AEULL, 0x839B9656ABDF680BULL, 0x9AC5C9BA00A5B436ULL
        },
        {
            0xF7ACC1E248F5E6C3ULL, 0x3A0E5B84E4523735ULL, 0x86071876CD82D012ULL, 0x3241DF75ED05F3DBULL, 
            0x7F48307A8A3478F9ULL, 0xF6E434658E28E96FULL, 0x5F2B63CD0F855CFEULL, 0xC454548DB92C8F95ULL, 
            0x9B3825A6250D30D9ULL, 0xFC54504D3CD64952ULL, 0xED033B8C04EAA284ULL, 0x4D614A15AAF27A10ULL, 
            0xBF366EE286833ADDULL, 0x29A1EF933971E773ULL, 0xE88D6C19F4C1797EULL, 0x73BD24C9A953FF3CULL, 
            0x506BCB4F2C44D640ULL, 0x399CA0B794BFCF24ULL, 0xEE2EC0EE85877AE6ULL, 0x8506A459767A730AULL, 
            0xAC97223861BF83E9ULL, 0x142C6365DA40A893ULL, 0x6E75BEF99F7E398FULL, 0xAD51A11216F4FD14ULL, 
            0xC165825056253730ULL, 0x1F8B71F21B8376BAULL, 0x11B0181AA64116CDULL, 0x5E42FDE85D32FB0DULL, 
            0x6BDD79B421613BA2ULL, 0x0C78C11343038E65ULL, 0xD651C0D2FC6BE51FULL, 0x2992A82810C7CA2EULL
        },
        {
            0xADC2824911A53A1DULL, 0x8A1D0852D8DA9D3FULL, 0x921C83A4BC95ECC8ULL, 0x7DE32A9E3F86058EULL, 
            0x27BAFC853F17B9B5ULL, 0xF4F7BEF1D5FFD5ECULL, 0x3D04068B47530B2AULL, 0x1AE48F9514CBF731ULL, 
            0xF517351B72E823BDULL, 0xA6B6E4129C0CC60EULL, 0x4E4E9335C1748C2BULL, 0x9A5CD8FC20A845D7ULL, 
            0x5DCE1968A55A2AE6ULL, 0x23D90108AC99F266ULL, 0xC3ECAE4683AB1D01ULL, 0xEF2EE0A4CFE6B3D2ULL, 
            0x2F74E08635D24BDCULL, 0x11E418461F295EB4ULL, 0x0337C25A5A7966F5ULL, 0x52682240567AB3E6ULL, 
            0xD9AFB9FE1C092198ULL, 0x71287218EBD62E8EULL, 0xF4A8479426F49B39ULL, 0xE4566858AAA4E86AULL, 
            0xE101541EB8A05419ULL, 0xD489583B89ABB057ULL, 0xEA785E0CF1068314ULL, 0x00C55F4CD0965D08ULL, 
            0xFDA30E2727C93E0FULL, 0x6D33B3C9CA01CA95ULL, 0x9EF5F38B567BE945ULL, 0xF93C19166A590419ULL
        },
        {
            0xBBECC2DB3E8C5631ULL, 0x830EF1C0EDA8F40DULL, 0x325F7A6869DBFA92ULL, 0xA0BC421A74D4A2B3ULL, 
            0x0751054EEB3BB1A7ULL, 0xFFD5040A29FA1101ULL, 0x5499C430B3DBAD68ULL, 0x1CC636F6E5A3BA96ULL, 
            0x6D8B14D0961F7B9DULL, 0x367D4EEEC28AAE0BULL, 0x3C25B18B3B7D9193ULL, 0xDC83C52DDA03FAA7ULL, 
            0xEFC70C190ABFC4BFULL, 0x9EB0063E92552FB4ULL, 0x0E8830F9CDE14AC5ULL, 0xB1084A6FDC2B31B2ULL, 
            0x50AE1CCF224EBDB4ULL, 0xA3F58754420CA6FDULL, 0x2133CA77A910807EULL, 0xE114E8010A200A80ULL, 
            0x5419237A84F758CCULL, 0xB0E7D14B0FD6F8E0ULL, 0xE990B0088184A85AULL, 0x0A75F128BB318CB1ULL, 
            0x5DE1CEB63578B1F7ULL, 0x76FB62E016D0022AULL, 0xB1A82B9C91813D43ULL, 0x055775A4E2019A9AULL, 
            0x8148B612E9AC44C5ULL, 0x7464E3D73CA66B2AULL, 0xAABEAC2B5D696933ULL, 0x9190A6CCF68A318AULL
        },
        {
            0xE9E3567F70015560ULL, 0x057EDD28B1F073C0ULL, 0x568AC5CE1AEDB053ULL, 0xDDDE55052090DD25ULL, 
            0xB252ACE7AFA4F03DULL, 0x340E5B67EFC7DA6CULL, 0x660FC8657BF0579DULL, 0x4DBB2C5631707F48ULL, 
            0xBFD201E60C8C17C2ULL, 0xF150AD2C11D1D272ULL, 0x4E0786A71B179DCAULL, 0x040BE740C6432D3EULL, 
            0x6A62A07E14539B94ULL, 0x6F57C35744C61089ULL, 0xF5DD409DFDF9632AULL, 0x3D1E1B43BC436115ULL, 
            0x230CE88A307FF8EBULL, 0x0CA96F51FB4E469EULL, 0x77D21A575185E370ULL, 0xB67EC073C6854CB0ULL, 
            0x3B4D67608830FE29ULL, 0x52DD384E55E2CB6CULL, 0x5D5D79CE69FABE9AULL, 0xD69180AFB4E2AD44ULL, 
            0x40D6FF338D267ABAULL, 0x64D8A4ED92443AEBULL, 0xB2826AD750576188ULL, 0x60A99A594DC4B838ULL, 
            0x3F5895D18398A7AFULL, 0x419DBA5CD59D48ABULL, 0x8CF52CD778730F50ULL, 0xA6BEAE7F3439C4F6ULL
        },
        {
            0x1846DD9AABEB560AULL, 0xAA21108FA8E837E7ULL, 0xFB2E0C7CD43A7B6CULL, 0x33E20F2E92413933ULL, 
            0x8130CA8B6130AA4DULL, 0xF4AA8D782D5D7991ULL, 0xAAF67A9645BE67FAULL, 0x840D7732022D2FCBULL, 
            0x69C576A5663262A2ULL, 0x54E6F925BB05CF98ULL, 0x76C2C086299A089AULL, 0xF538ED32A49DF5CAULL, 
            0x60CAAE1EDF9BCBC1ULL, 0x0E1227D4E275D9E9ULL, 0xF61BC6CF67D9D5F0ULL, 0xA935B381A4BF3D4EULL, 
            0xEE445D9DC30D35CCULL, 0x6AA9E650F931A537ULL, 0xBAD388B2185DEC91ULL, 0x420795F3A0A4D7E0ULL, 
            0x33B5EA210720DBCDULL, 0xF12F5F8627E7E232ULL, 0x62ED5F5FCE84B6D9ULL, 0x8738F0AD0DB2C2C1ULL, 
            0x6C88002A8DAC2EE9ULL, 0x4D7E7C0D58AC74FBULL, 0x381E35A6AC421C6AULL, 0x360FBBF0DDA5B170ULL, 
            0xA3D54137AED43004ULL, 0x3DDD5B3F8588D5E6ULL, 0x7065D55C270DCF28ULL, 0x6CC94C15381C166AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Miram::kSeedConstants = {
    0xA7C98FD5C79349E5ULL,
    0x5F0600F4B3A728BFULL,
    0x09B1398123B5C70EULL,
    0xA7C98FD5C79349E5ULL,
    0x5F0600F4B3A728BFULL,
    0x09B1398123B5C70EULL,
    0xF4C228A80B62D267ULL,
    0xC9F7A3FB22EE208AULL,
    0x46,
    0xE0,
    0x9E,
    0x2A,
    0x4D,
    0xE1,
    0xB7,
    0xF8
};

const TwistDomainSaltSet TwistExpander_Miram::kTwistSalts = {
    {
        {
            0x8143BEBDFED2E740ULL, 0x118F1F4148DE64DDULL, 0x7970EF59AB64DCD8ULL, 0x4E5E173B9B4FF5EFULL, 
            0xEF5545CFD44339AAULL, 0x17C9661C132112F8ULL, 0x1889D06C3DD827ABULL, 0x96C936944AA43B64ULL, 
            0xC6C26FE8C870A8B0ULL, 0x0A9B0F67D220D683ULL, 0xAAD7F4A2E10E0B86ULL, 0x527D61A668288B53ULL, 
            0xA4348C089238E896ULL, 0x699EDC7BC4866974ULL, 0xA7F02304519C6262ULL, 0xF75B271683649DD2ULL, 
            0x332CBD5FD79D4C23ULL, 0x78A142CDE997408FULL, 0x62E8F4FBB3B27003ULL, 0xDE3D09F8EF909BBDULL, 
            0x7226A72A5FFE8A38ULL, 0x4C58E135618A52FAULL, 0xADF6F755EB31FD2EULL, 0x6F68DB99A981484BULL, 
            0xC4C9C83FE4EEF0E9ULL, 0xE93C2925322130CAULL, 0x23579D27AAE65471ULL, 0x60484C8E7ED46AE2ULL, 
            0x510E67BF142DF556ULL, 0x2DC4439A43C90C6BULL, 0x46CD43A497944EF6ULL, 0x80A3D0DCF5F22456ULL
        },
        {
            0x5E8022C516CC1CCEULL, 0x08911FC17F5F1278ULL, 0x0F0663092FC5FE83ULL, 0xB2102C0386197312ULL, 
            0x9ED72268E784F583ULL, 0xD4A43B6DA1FF635BULL, 0x09C1F54B5C42C72BULL, 0xE3FFF0C6AA95A955ULL, 
            0x7F766F8DCB98E2F3ULL, 0x9A13415572FA2971ULL, 0xAA524EF435F7D183ULL, 0xD728500B1D5F597DULL, 
            0xF49582E336633263ULL, 0x8CC9E331343E7E53ULL, 0x8063266252B3C2C5ULL, 0x5AEA8B899396AA44ULL, 
            0x1C8994F78A75F257ULL, 0xB451E79E1A193418ULL, 0xDD7A0C382B10156CULL, 0xEAEEF2BDE9B19ED1ULL, 
            0x712F91FD1A6A9DAFULL, 0xB7FB517EDDFCC4E9ULL, 0xDB1A2A826EE71223ULL, 0x49514AE239D80D59ULL, 
            0x6438AC4FC6200D06ULL, 0x57B6F59A1DEEB47FULL, 0xC70F34777ADABE4FULL, 0xE3BEE5E8E06A1761ULL, 
            0x0894CFFA1CA79011ULL, 0x6D52A37705A4F352ULL, 0xEE5B186C58EF3405ULL, 0xF974D4B7ED9CB7BFULL
        },
        {
            0xBCB3CD95E31CF4E1ULL, 0xC019A9FFD9BB046AULL, 0x263F38F91BD90E14ULL, 0x2F7E62C50FC0B1C7ULL, 
            0x0E1130E316C81E41ULL, 0x26075A895478BCF2ULL, 0x9F1F86C8FA40EF2BULL, 0x3B03E4437F1FAE14ULL, 
            0x1C266061D45528B8ULL, 0x88E0D8DDD55F7B24ULL, 0x73DBDFE8FF6A1E21ULL, 0x0E21140E5B8C23D9ULL, 
            0x42A330CEBD6E7F92ULL, 0x5264FC9ADB7D8CD9ULL, 0x68B2C853EC77742EULL, 0x3794C8768E97DE4DULL, 
            0x1EA38286FAA0D7AFULL, 0x9E49AB503A242A18ULL, 0xDB819E5C04FE69D0ULL, 0x5C133D38D370594DULL, 
            0x72221DC5F63E273DULL, 0x8084AED348F02AE8ULL, 0x9DCD2750F1B7BC04ULL, 0x4062261E04833166ULL, 
            0x0D6B0433800DF436ULL, 0x6F4C7F309D97FE38ULL, 0xDF4B57D8FCF96D19ULL, 0x69A0C86F6B6A6EB2ULL, 
            0x3BF69A344F84F82CULL, 0x21FC5F276D1187C4ULL, 0x85F8B896669D2972ULL, 0x3BA39F399CF5E407ULL
        },
        {
            0x0FC5C35DC438147AULL, 0x64A16BF0CE296FE6ULL, 0xE0F941454181FC98ULL, 0x2D2BE39E773507E4ULL, 
            0xF1BC7643EF9DFC47ULL, 0x9238870878F95C57ULL, 0x8DBC5817E151A3D8ULL, 0xCDAC9364CE284637ULL, 
            0x64AAF4E0746F4B52ULL, 0x18B4EE5A7FD72938ULL, 0xFC48F48E09209E29ULL, 0x444F7B4D3C52165AULL, 
            0x17A8BA1B8B72A070ULL, 0xC1EF420B1FB28FB9ULL, 0x67921A1BC8A3D72FULL, 0x671B58B979DBAB93ULL, 
            0xF3FE19BDEF6C5558ULL, 0x9B13B113344CBCECULL, 0x6A16989D29CA8982ULL, 0x206B05A393A2C4ADULL, 
            0xB11B8AE920C0C349ULL, 0x797288D3B971DE50ULL, 0x6B63E516FD557947ULL, 0x36FC8518BF5D696EULL, 
            0x672B5BD901D50131ULL, 0x1849ED441EE43CFDULL, 0x99EF1CBB9F932339ULL, 0xAA2C0BCDFBBEDE8AULL, 
            0x9FB7A02E12C2DECDULL, 0x139292200DBD14EFULL, 0xE3DD7F8AB860A74BULL, 0x1CC7A2D4D6B6F286ULL
        },
        {
            0x1C7BA5B4F44AF006ULL, 0x98532694599E364FULL, 0x42BF967FE7530B29ULL, 0x1E1A3A86DB9911C3ULL, 
            0x89F7A91DC25ECDBAULL, 0x1421544811923D8BULL, 0x5FF77E48B44B6997ULL, 0xD3A090E04B7BAE17ULL, 
            0x79722369A4679D9EULL, 0x693A3A2C968A3490ULL, 0xCC7EE3A491BE439FULL, 0xE782BBE16BC22D60ULL, 
            0x415E96285BD7CAA8ULL, 0xB9423B808630E9D0ULL, 0x3F16AE12B72CC6FBULL, 0xF66A6248F202DAFBULL, 
            0x46F20B3D5FE0F8A0ULL, 0xB55B72ED477849D1ULL, 0x9DF2158312D80CA3ULL, 0x9496BA8B8F0B177FULL, 
            0xBFC81B198AB3F192ULL, 0x80F5E40DA010776FULL, 0xF5B204012CCB1719ULL, 0x165F3C957216A8E0ULL, 
            0xD890C7DC3134A83FULL, 0x851F8EB790B5078FULL, 0x67CEEC02BF0F2564ULL, 0x0672484D6E864D6EULL, 
            0x10C50FB984A7134AULL, 0xE2961A59E47734DAULL, 0x91EA8104E1E6EA0EULL, 0x63F6B240A1F67113ULL
        },
        {
            0x03DEA39BC39A4A56ULL, 0xB5416A1C4DA31760ULL, 0x921D0D5B42679910ULL, 0x263431825DDDD740ULL, 
            0xD7002CD29AC48E5EULL, 0xFC04D57972817247ULL, 0xD64D9544A7FF1AD3ULL, 0x840EAE82964BD04CULL, 
            0x47CB8003312ADFA0ULL, 0xBF4DD633107EB2B9ULL, 0xE0556E9CE7DD46CEULL, 0x3EC3D6609067F349ULL, 
            0x4D2C0CF1B70ADEC4ULL, 0x4D6FD0924204D2DBULL, 0x27F566404451E96BULL, 0x602B3E655F662796ULL, 
            0xE93C12BC88745029ULL, 0x4945C6E246015F47ULL, 0x7DE4391BB35961EFULL, 0xFCA7A9CFB3C7CFA4ULL, 
            0x2FAD7326498F7D3AULL, 0x2E14D0C16255FB8FULL, 0x36993CF896B19E1EULL, 0x278B825C3356EE48ULL, 
            0xB486F974742247F2ULL, 0xA1B6D3F0EE3CADDEULL, 0x3F1FB5FA7FB2EF5BULL, 0x625B2935ED56D0C1ULL, 
            0x27F053F1A0099061ULL, 0xC053B76958EFC0BFULL, 0x7450624BBD30FE0DULL, 0x6B623D0BBF6EE73EULL
        }
    },
    {
        {
            0xE88DD1101DB57CE4ULL, 0x025A2B9C5D81C794ULL, 0x5AD03D2259B5E4E4ULL, 0x25FAACCC4D7D9B92ULL, 
            0x043DFFB69D5818F8ULL, 0x537D12CC8DA07735ULL, 0x612425EB60153CB4ULL, 0xBB8A38CC4C0BCEBBULL, 
            0xA401F4494E03D4DAULL, 0x2DDB7BED001E6063ULL, 0xCC598ACE85639C0CULL, 0x0A0284E57CD522B5ULL, 
            0xFE90DD0114BA6ECAULL, 0x32F0D8D5E08C0DCAULL, 0x1434694724A9E249ULL, 0x898BE4A7D47924BBULL, 
            0x079C0B5C903543DCULL, 0x3A64230BA01FDDE9ULL, 0xEDAC07400B4CEB75ULL, 0xDAFBE7E9D134BBD2ULL, 
            0x82B08B0C57BFA521ULL, 0x9AE65E5AB2C05732ULL, 0x4ECD9ECA93D4B3D2ULL, 0x864C46EBA69F0EF8ULL, 
            0x9E9E2BDDC7EDA3EDULL, 0xD7897AE052FF75EFULL, 0x71AFE847F0E89150ULL, 0x28A03D4A83E121D4ULL, 
            0x6FF2DAE82B1F5472ULL, 0xA28923E5E0CCDEE9ULL, 0xEB64BBBCBFC22602ULL, 0x60EAA7D8BE1DE431ULL
        },
        {
            0xD34A147E6EB76C13ULL, 0xFBF1A3AE9228F5E1ULL, 0x02641F210FEF0651ULL, 0xCE8BC22D0B62E134ULL, 
            0xF991C10817D8678CULL, 0xB169DAA856C16193ULL, 0xBEEAF16763E25026ULL, 0x5630C1C9AE91947AULL, 
            0xCEA5709DFC8FC1DEULL, 0x7042937EBAEB31EFULL, 0x152223C673BFDC1EULL, 0x821B6B1EA765A857ULL, 
            0xE67E481C7C4660A1ULL, 0xD7C68B4F51A30C9FULL, 0x01F3D0160C80C875ULL, 0x8B31415DB9962C9BULL, 
            0xCF708984CFD78830ULL, 0x1093D02F169E854DULL, 0xDF8C84E6212B681DULL, 0xB771090077114632ULL, 
            0xF77228D335380A97ULL, 0xA18CCF14D2AA9D94ULL, 0xD9148113C457E9AEULL, 0x806924D04EC53C1DULL, 
            0xD52EEE8010C276ADULL, 0xC8AAF059A50309F2ULL, 0xD99CC5D5F6B45334ULL, 0x2BD56046494D627AULL, 
            0x095D66246152BE18ULL, 0x94B4B89D2F5A68BAULL, 0xBF30C0C23BF9C64AULL, 0xCD97264C705B4EBBULL
        },
        {
            0x4D6DAEABA9C9D2A3ULL, 0xEC5DB5809070761CULL, 0x5786966A4DA3F0D7ULL, 0xAA8D53C1C8AECECFULL, 
            0xC3B8F030330A453FULL, 0x46293D2A8ACE35F7ULL, 0xF3F7F0FB89A216ECULL, 0x5E6E66C01469A25AULL, 
            0xF580B13A0ECBDF48ULL, 0x488F61C42F3AF237ULL, 0x22E34359C7F90072ULL, 0x8C8A9D8F9CFD1B74ULL, 
            0x8C16952E6E4BD876ULL, 0x27B980EF9CD5C3BDULL, 0x8854D974D82DBF86ULL, 0xD36B35F83B3420E2ULL, 
            0xDC5E219975011451ULL, 0x705F574F6FE78E11ULL, 0x505072BA317AC90FULL, 0x5B2997E2FA738101ULL, 
            0xE69929187F4AB591ULL, 0xEA8B87CFD0DBD816ULL, 0xBE908477FB26CB5BULL, 0xCA7953CC5AB44593ULL, 
            0x6B9EED6ABD6A6B7EULL, 0x50591CF4762C497AULL, 0x464D308B8DBE2C77ULL, 0x73ABF3632B91EE19ULL, 
            0xB30F32649DE48824ULL, 0x586047AEF7C5E823ULL, 0x4CE4EA7C3C13AB17ULL, 0x32139106BEF67537ULL
        },
        {
            0xA64A363CF3FA9A50ULL, 0xF212AADFE0E96275ULL, 0x5B7F1E52DCF7A962ULL, 0x177FEC7F821435BDULL, 
            0xE3277332D44FCA59ULL, 0xB4D875140E53F3D4ULL, 0xB5DCA6B2FC7ACE96ULL, 0xBD91FEEA9712F13FULL, 
            0x83F4384C67DA0B52ULL, 0x808507B99FA2DFA7ULL, 0x4D857C79455853B6ULL, 0x0AE150CE443B045AULL, 
            0xB4F943D2F8A9B388ULL, 0x2468AD759A1AE61AULL, 0xF1E104379A52A845ULL, 0x26D201626EE17474ULL, 
            0x635F58E93AF87457ULL, 0xD37B3D852E1C720FULL, 0xAC40CD487ED24B88ULL, 0x52DF36C894A56987ULL, 
            0xED598E3B8EB47C6AULL, 0xD8D812EAF361F711ULL, 0x552F940D261A619FULL, 0xFA92AEBC54A650A5ULL, 
            0x691880B6FB6F8B9FULL, 0x537F32B6066A5474ULL, 0x8C68835B0EE06FF9ULL, 0x8A8AC4D046205D49ULL, 
            0x5BBC5D05F3218BACULL, 0x922A86F3130CA2E5ULL, 0x53BB089F5CF42DCBULL, 0x058702D1C51D47BDULL
        },
        {
            0xC7211C66057A2CB9ULL, 0x54EC447DD3E503D8ULL, 0xFE9D511847ECB35BULL, 0x4CD3A74F951B5448ULL, 
            0x1CB9576E1C112F3EULL, 0xD87870397ECB14DAULL, 0x7904DF9944AF1FADULL, 0xBE4384B22B2A7992ULL, 
            0x895B381B30446BC1ULL, 0x8653DD4B0383057CULL, 0xD3E01864398E82CDULL, 0x3D6C862674637F48ULL, 
            0xFF960D8696B67BD1ULL, 0x82375F28498DD169ULL, 0xF8C8DF56340CB089ULL, 0x838F9E48B32ACCD2ULL, 
            0x1320869FA919CC24ULL, 0x284C9C8BF3C04651ULL, 0xF9664A4B021B6718ULL, 0x626E5CE99DB57505ULL, 
            0xBBF74DEA832FC820ULL, 0xA647FA52387638A9ULL, 0x347460A2284D225EULL, 0xA39FE184E9B218E3ULL, 
            0x0495732E8327CECAULL, 0x5E53FAEB92A0B1F8ULL, 0x4F6703ECB0CA20FFULL, 0xDAC393EEC5A95941ULL, 
            0xA655A0B1B72B21B6ULL, 0xA36FD48D34B197D5ULL, 0x7264783C1FBE107EULL, 0x74AE23B8F44BC8D6ULL
        },
        {
            0xF0F68A9A9CBC4102ULL, 0x8034269188036A47ULL, 0x6E192F106546E6B2ULL, 0x053B7788BFFF1604ULL, 
            0x8506E7F65B0241ECULL, 0x1B36FC70BB25DD70ULL, 0xDAFE2ADC4816D610ULL, 0x90E2C0095969AC6EULL, 
            0x3291804F321639A2ULL, 0x4201CC46097FCF7BULL, 0x70B30929655075E7ULL, 0x7A594B77A8E344A2ULL, 
            0x20357E53146CDAE1ULL, 0x99E177E458F8995BULL, 0x25BBE2696AC0F73EULL, 0x0EB2F7FF8BF272F1ULL, 
            0x7781A45A15B87F55ULL, 0x53492067CEAAA7E0ULL, 0xC36B39B5FEE46623ULL, 0xCC21249DF6F0650BULL, 
            0x6CAF5CDE68BD40B1ULL, 0x3743F1ED22BD5B4FULL, 0x9FE878529AAC9D1AULL, 0xD986A0D03E7D7526ULL, 
            0xC9B419303BC613E4ULL, 0x20ABEDCA28664DD7ULL, 0x03937BAD4CBA8CC6ULL, 0x4DD7AF2A5DFD44E8ULL, 
            0x9C368CA56A601442ULL, 0x05346853AB6547ACULL, 0xC3ED15F0AF363387ULL, 0xA36C1D6591813F9BULL
        }
    },
    {
        {
            0xB02C8D0430E158EBULL, 0x1D0C55F7092F451CULL, 0xEA9101D7B810949AULL, 0x3539015005368D2BULL, 
            0x35B5ED2BD4146A9BULL, 0xD5B8833A2BBF1C71ULL, 0x2FF51C8996D7883CULL, 0x09BC1458039711C8ULL, 
            0x431402CF96EBBE1FULL, 0xE90A363883966766ULL, 0x29A3655DBBE4AC3BULL, 0xC08062B9077A4F5DULL, 
            0x5BA9DD635FA0CE4CULL, 0xFD313347D4169C46ULL, 0x85595F70C3B6E22CULL, 0xF77C03EA32718622ULL, 
            0xBB495E5B80A600C1ULL, 0xD9FB93E39538F16BULL, 0x65B06BFC3C0C1FAAULL, 0x2B07BECB11CDDC03ULL, 
            0x1E17FA2811B87A52ULL, 0xDF22C7222313E687ULL, 0x2BDCBE656AA5D714ULL, 0xF9AE76B646C30799ULL, 
            0x59057ADBA348535DULL, 0xB0CE524B4604E239ULL, 0xC01CBE50235BC467ULL, 0x5337281F71C6EEAFULL, 
            0xB917E9F9D92F4D6EULL, 0x9CF543EC8C3368ABULL, 0x36057BD36BF109F6ULL, 0x3E992D7810346083ULL
        },
        {
            0x432B6C52CC732E75ULL, 0x111AAF9916FFD4FAULL, 0x4D3526A938A4C3A5ULL, 0xD5DF0FDC71EDC276ULL, 
            0x177380527ED234B3ULL, 0xB7CEA5A9AE77C402ULL, 0x407D71A1E994128AULL, 0xB05F38F75A46BD24ULL, 
            0x3781F0EE878A3CA2ULL, 0xEDC1209B73C0C5CCULL, 0x1A788F5E3E8E9C54ULL, 0x1FEE52E4AF5BE056ULL, 
            0x44A6BD044E38B32DULL, 0x41636A4808B6BA12ULL, 0x7A0F716626E52C03ULL, 0xFB8A9B798602AA3CULL, 
            0x70E7566089E2076FULL, 0xA47ED73E30E196DFULL, 0x0626AA95296DD87CULL, 0xF73D3BBF2790A438ULL, 
            0x5B26B64690163CFDULL, 0xFD565E5E35F530BBULL, 0x4BE088770353EA94ULL, 0xA1B59A9EE80A93A1ULL, 
            0x7B4A0331671330E4ULL, 0xBBE4B73479682975ULL, 0x7623776173417976ULL, 0xD3DB20A4161AA073ULL, 
            0x8509DEFC01B12263ULL, 0x8ACB042E0B128482ULL, 0x1FFA078487A6BB58ULL, 0x66EF0485AF110F1CULL
        },
        {
            0x13C25F89BF3DA2A7ULL, 0xEB4FBDD012B38BF1ULL, 0x8AF4E2F1BBF3311EULL, 0xC83CC42458821C3FULL, 
            0xA9E8673AB23BAEABULL, 0x7845F8039DFF9614ULL, 0x8FF3729BD45A326BULL, 0xFCD15F00A80B1056ULL, 
            0x23B1CCCBE89F0C3EULL, 0x4ADC97D8C9B850F7ULL, 0x21CD1153231FDFA1ULL, 0x1D0AA55A09E97DEDULL, 
            0x9E040755474A2E6EULL, 0x7B0FF36A47047E51ULL, 0x703F82C8E4C8DDAAULL, 0xEB3FEEFB023799BBULL, 
            0x68C3E97D9A7EF3FBULL, 0x9866720BC2C5F48AULL, 0x64F11BEF1E3E17C4ULL, 0x2451ACB9C0D16E94ULL, 
            0x5BBBB0C7812A5D36ULL, 0x1A3A4BC33ECC9FAAULL, 0x903B5150F5AADEACULL, 0x5D6080C9DCC10FA6ULL, 
            0x918723F1B2F8A485ULL, 0x02E502FC6285AB12ULL, 0x763C4C5CA99A0A9CULL, 0xBA328D3F7347EA3CULL, 
            0xED74259F139A9158ULL, 0x37861CC455318909ULL, 0xA58980852A771A39ULL, 0xFE1B8BBEDD39FC54ULL
        },
        {
            0xCD9A46302DBBEB19ULL, 0x9F215035BB2BC666ULL, 0xFE3AA259A21690C6ULL, 0xB1C7CA351583E0D7ULL, 
            0xA85D96B365DBC472ULL, 0xB5F6C1EEEE7729FAULL, 0x94D73B5F6877FE4FULL, 0xF9C61A13295746F3ULL, 
            0xEFF507C4795C566DULL, 0x1A548896403F161DULL, 0x6D4D666A3201B48AULL, 0x66FFDF366C834137ULL, 
            0xF5DF85D2944267DAULL, 0x0E077C6B84B2B877ULL, 0x723DE7531AAFC95FULL, 0xDA7A6BCFC5D02964ULL, 
            0xBD64146247D195DAULL, 0x2680693C4816EDD1ULL, 0xD4CD93254DEDDC9AULL, 0xD3E256225110F7C3ULL, 
            0x7920C21F99769ADAULL, 0x987C6E92D64AD3A0ULL, 0xB7A2D063AD9C1794ULL, 0x393521D2AA5EF9CEULL, 
            0xF52BFCD0B71C2CA5ULL, 0x61134CB9A70EAAADULL, 0x42636866F70593D9ULL, 0xC22AE891702753C1ULL, 
            0x79B33E46C936195CULL, 0x9E4C0D499A0E470BULL, 0x4835F86093FA7602ULL, 0x0610D8A2C909002DULL
        },
        {
            0xAFB13321A16BF340ULL, 0xD32A2CDF315CA490ULL, 0xBD41FE5F8A06E0E0ULL, 0xE588FA0A4FDDD628ULL, 
            0xF2AE5B2F72D7CED4ULL, 0xFF16F890F269CAB1ULL, 0x4C8D4638C695710BULL, 0xB94A99BCF9855A9FULL, 
            0x63B9A4E566C39AA0ULL, 0x93F31DA348A49A98ULL, 0xDF6EDA9DB31DCA35ULL, 0x54D0BE554DC0119FULL, 
            0xEABBF095FBF63F4DULL, 0x61B6DDE9E2E24F88ULL, 0xA7D4B9CCEA66379AULL, 0x117898CADC42132EULL, 
            0x14C935D9E1FFED3FULL, 0xA47FDE6C7CE12E46ULL, 0x94F765AA6A5B6BD4ULL, 0xC1FDC6FE6975E9CFULL, 
            0xBD6B1F97C66FC2D4ULL, 0x01B57C573F6DE55AULL, 0x8115E8205C46438BULL, 0x1DC6AC861349EFFFULL, 
            0xAEEF6A446D6953CAULL, 0x3FA4C30F14E448E8ULL, 0x55D4C1DE30AA7864ULL, 0xE3064226C227751AULL, 
            0x48EB4EA897725760ULL, 0x65DBD95BE6564F46ULL, 0x38C59D7BB0E3910AULL, 0x0E2AFA7A47E79181ULL
        },
        {
            0x162B2C7E2BA303CEULL, 0x0FBCDA936F340689ULL, 0xD6BB64CAFDEE2922ULL, 0x353762C4DD615069ULL, 
            0xB3DFEA9AB718AE23ULL, 0x9CAD33A08B8A17FCULL, 0xEFA7F1088ACC7688ULL, 0x065EA89007A0620EULL, 
            0x9768739FEEC0A7EEULL, 0x4B39239380816FC7ULL, 0x1DA90711A8375B44ULL, 0x40BF1F92333ED139ULL, 
            0x3F28A738B167F633ULL, 0x9AF375883BC84405ULL, 0x0D1CC646D98ECA0DULL, 0x3FA39A5703CDAE19ULL, 
            0x4273EAEB69E5BAFEULL, 0x8613DD499365746AULL, 0x1E0B9BE54577B26FULL, 0xE36D1772A0684AC7ULL, 
            0x39598DB786270544ULL, 0x3D84C79B48185E9DULL, 0x00590B82B6484E6CULL, 0x8B462802876B2125ULL, 
            0xCE59FC999A6F1A8FULL, 0x58D52352104737F5ULL, 0xA2BC518FC4E6562AULL, 0xD11724C9AB5755A2ULL, 
            0x4C513252A0884011ULL, 0xE898280BFC11CDEFULL, 0x378650046CA61DB4ULL, 0xA88D03C44625B8F2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Miram::kTwistConstants = {
    0xDE79A6417A76158FULL,
    0x52993C06856C48A1ULL,
    0x90D34DBBA2771A17ULL,
    0xDE79A6417A76158FULL,
    0x52993C06856C48A1ULL,
    0x90D34DBBA2771A17ULL,
    0xC568C6E2F0ACE879ULL,
    0x293CF94B6211C49EULL,
    0xBA,
    0x47,
    0x4D,
    0xF8,
    0xEC,
    0x26,
    0x48,
    0x24
};

