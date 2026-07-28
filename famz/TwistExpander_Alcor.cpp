#include "TwistExpander_Alcor.hpp"
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

TwistExpander_Alcor::TwistExpander_Alcor()
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

void TwistExpander_Alcor::KDF_A(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Alcor_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Alcor_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Alcor_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Alcor_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Alcor::KDF_B(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Alcor_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Alcor_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Alcor_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Alcor_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Alcor::KDF_C(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Alcor_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Alcor_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Alcor_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Alcor_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Alcor::KDF_D(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Alcor_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Alcor_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Alcor_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Alcor_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Alcor::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xEEFD3BD257D19248ULL;
    std::uint64_t aIngress = 0xA965123C91643A42ULL;
    std::uint64_t aCarry = 0xAE9BE216DC1E5A75ULL;

    std::uint64_t aWandererA = 0xE434BD64647ABD86ULL;
    std::uint64_t aWandererB = 0xE15D70359D3C2AA8ULL;
    std::uint64_t aWandererC = 0x9CE2B7FED90B3FDFULL;
    std::uint64_t aWandererD = 0xE0B9403BF5A72FA5ULL;
    std::uint64_t aWandererE = 0xC79066BED78F6DD6ULL;
    std::uint64_t aWandererF = 0x8DC39A1A2685749AULL;
    std::uint64_t aWandererG = 0xC8DAA5EFB9337543ULL;
    std::uint64_t aWandererH = 0xB7A3A76327F7BDD1ULL;
    std::uint64_t aWandererI = 0x94C58C288662770AULL;
    std::uint64_t aWandererJ = 0xCFEC09D9CEA49A44ULL;
    std::uint64_t aWandererK = 0xBF1EA1AF41161763ULL;

    //
    // KeyRotate A
    //
    aPrevious = 0x8B0B2BE74C40F4BAULL;
    aIngress = 0x943CD2A24FDBE276ULL;
    aCarry = 0xA5ED4035B129BFD3ULL;
    aWandererA = 0xDF160EBC9F45FFA0ULL;
    aWandererB = 0xC2FF61459DC01C1EULL;
    aWandererC = 0xF1865329813FFDF4ULL;
    aWandererD = 0xF5AC27CC4D6E7AC4ULL;
    aWandererE = 0xEDB9BA1E4052C877ULL;
    aWandererF = 0xD4F56225CCB886B2ULL;
    aWandererG = 0xA03A66B356931A6CULL;
    aWandererH = 0xFACFBE969206C5D2ULL;
    aWandererI = 0x9E87A2DFEC93ABF5ULL;
    aWandererJ = 0x837C7B42B97D0C6BULL;
    aWandererK = 0x943B6720FA659113ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateAConstants), &(pWorkSpace->mDomainBundle.mKeyRotateASalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeyRotateAConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xC6DD4E29024CF9FAULL;
    aIngress = 0xC7A2244DF682691AULL;
    aCarry = 0xD89BF721895EEA7EULL;
    aWandererA = 0xD762B1005F4FD0EFULL;
    aWandererB = 0x88C2F2626D2921A8ULL;
    aWandererC = 0xEB947DEE5171999EULL;
    aWandererD = 0xD8196056C50629EDULL;
    aWandererE = 0xB3164B0B28767E41ULL;
    aWandererF = 0xB096633FAF0F5181ULL;
    aWandererG = 0xBEBE17C676C97C96ULL;
    aWandererH = 0xFD8CEFA2CC4EB7D4ULL;
    aWandererI = 0xAC678E43CBDFEE9AULL;
    aWandererJ = 0x990FE9266BD22603ULL;
    aWandererK = 0xE60650ACF1AE6576ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants), &(pWorkSpace->mDomainBundle.mKeyRotateBSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0x89BEF6FBFF115983ULL;
    aIngress = 0xE88D2EFB3DB9F33AULL;
    aCarry = 0xF0A6E422C2D779E1ULL;
    aWandererA = 0xF6D30106A0B43038ULL;
    aWandererB = 0xDEE80C3F50CEAA16ULL;
    aWandererC = 0xCF145F08E76CC1C8ULL;
    aWandererD = 0xB10CA802D7B3A7FDULL;
    aWandererE = 0xB1CD07778D295329ULL;
    aWandererF = 0xBB2477A46B89DD17ULL;
    aWandererG = 0x9C4EAE876202F69EULL;
    aWandererH = 0x8A56A5CF59BA9023ULL;
    aWandererI = 0xF7AFEAB310D17B13ULL;
    aWandererJ = 0x8A56887614671013ULL;
    aWandererK = 0xBCFE2627E26997BFULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnAConstants), &(mDomainBundleInbuilt.mKeySpawnASalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnAConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants), &(pWorkSpace->mDomainBundle.mKeySpawnASalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xD8A79BEE66A91DE2ULL;
    aIngress = 0xA5EF3BF886D3FB88ULL;
    aCarry = 0xC04B317ED790C30CULL;
    aWandererA = 0xDCCA6D30C1B9C117ULL;
    aWandererB = 0xE3F7A4BDDABF3C36ULL;
    aWandererC = 0xE901E78060070149ULL;
    aWandererD = 0xBD8C3F6D64691001ULL;
    aWandererE = 0xC3E948EDE3536087ULL;
    aWandererF = 0xDF9D49DABF2AA33AULL;
    aWandererG = 0x82DD4C9091DF0267ULL;
    aWandererH = 0xC00119577AA22227ULL;
    aWandererI = 0xA9571C428938D7F6ULL;
    aWandererJ = 0x851722D8DB62ACFAULL;
    aWandererK = 0x93C5FF46F72B2820ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnBConstants), &(mDomainBundleInbuilt.mKeySpawnBSalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xF7BA5C3A0916FA30ULL;
    aIngress = 0xE701EE556FCAD30AULL;
    aCarry = 0xA4304258310836DAULL;
    aWandererA = 0xF699ADC3E5DA9772ULL;
    aWandererB = 0xEBA1ED8C30F429AFULL;
    aWandererC = 0xB8B8C4F527D15E5CULL;
    aWandererD = 0xC5D8D8E52AF1EE6FULL;
    aWandererE = 0xE3D8F053F404E24AULL;
    aWandererF = 0xFD45D753CB07B33BULL;
    aWandererG = 0x86173C4088AC6265ULL;
    aWandererH = 0xFEB2C4B336920172ULL;
    aWandererI = 0x9A1F37110E177337ULL;
    aWandererJ = 0xD9ABDFFBA72CEA86ULL;
    aWandererK = 0xE5A68C5270C0CB35ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mTwistConstants), &(pWorkSpace->mDomainBundle.mTwistSalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xFD4CE70A82F315F8ULL;
    aIngress = 0x9154B7C1963BC55EULL;
    aCarry = 0xE6BE3C1C2C678908ULL;
    aWandererA = 0xB1C6BB6C2CEA3234ULL;
    aWandererB = 0xE5D94740FA196848ULL;
    aWandererC = 0x9F04406529550DA8ULL;
    aWandererD = 0xC22482CED3EFBAE3ULL;
    aWandererE = 0xD994025BC5305D7AULL;
    aWandererF = 0xF18B8CABA6527EC2ULL;
    aWandererG = 0x9064EE8FB666A3F4ULL;
    aWandererH = 0xBEF2403EDF1954F4ULL;
    aWandererI = 0xB0A2C3D5E4C6A05CULL;
    aWandererJ = 0xAA45434F723144ACULL;
    aWandererK = 0xB235A81A1BA512F9ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mSeedSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mSeedSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mSeedConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mSeedConstants), &(pWorkSpace->mDomainBundle.mSeedSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mSeedSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xFDD78497C8AD4BD6ULL;
    aIngress = 0xAB2B5B8ADE2BA601ULL;
    aCarry = 0xF84F76F2F00FBF46ULL;
    aWandererA = 0xD4A655B8B279CFA6ULL;
    aWandererB = 0xA51D0ED78155D5DAULL;
    aWandererC = 0xAC8DB035F5003A46ULL;
    aWandererD = 0xD391622CB98A091BULL;
    aWandererE = 0xCC96FDB3E5C872C6ULL;
    aWandererF = 0xFD6806A802D5E331ULL;
    aWandererG = 0xF17D313B6181C694ULL;
    aWandererH = 0x9D9B6E7E56320627ULL;
    aWandererI = 0xBBFB59D4CC7E5D50ULL;
    aWandererJ = 0x9C80CA863FB82DC2ULL;
    aWandererK = 0x8A3BAA7435E9D1A1ULL;
    //
    TwistExpander_Alcor_Arx::SEED_A(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alcor_Arx::SEED_B(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alcor_Arx::SEED_C(pWorkSpace,
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
    TwistExpander_Alcor_Arx::SEED_D(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alcor_Arx::SEED_E(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alcor_Arx::SEED_F(pWorkSpace,
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
    TwistExpander_Alcor_Arx::SEED_G(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alcor_Arx::SEED_H(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alcor_Arx::SEED_I(pWorkSpace,
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
    TwistExpander_Alcor_Arx::SEED_J(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alcor_Arx::SEED_K(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alcor_Arx::SEED_L(pWorkSpace,
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
    TwistExpander_Alcor_Arx::SEED_M(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alcor_Arx::SEED_N(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Alcor_Arx::KEY_A_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alcor_Arx::KEY_A_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alcor_Arx::KEY_A_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alcor_Arx::KEY_A_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alcor_Arx::KEY_A_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alcor_Arx::KEY_A_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alcor_Arx::KEY_A_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alcor_Arx::KEY_A_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alcor_Arx::KEY_B_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alcor_Arx::KEY_B_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alcor_Arx::KEY_B_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alcor_Arx::KEY_B_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alcor_Arx::KEY_B_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alcor_Arx::KEY_B_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alcor_Arx::KEY_B_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alcor_Arx::KEY_B_H(pWorkSpace,
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

void TwistExpander_Alcor::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xAD44252CDB3F65CCULL; std::uint64_t aIngress = 0x9BC83EE081CDC0F0ULL; std::uint64_t aCarry = 0xC6E2F0E074D8E8ADULL;

    std::uint64_t aWandererA = 0xF2D7ADD7BCE5D027ULL; std::uint64_t aWandererB = 0xD681685330F7216BULL; std::uint64_t aWandererC = 0xA245E5F9A27F3074ULL; std::uint64_t aWandererD = 0x96E845375EA18DFDULL;
    std::uint64_t aWandererE = 0x97C2130F93BF570AULL; std::uint64_t aWandererF = 0x9540A332F2A8CCD4ULL; std::uint64_t aWandererG = 0xC8345ACA8B345FBEULL; std::uint64_t aWandererH = 0x88337EBCA2B05515ULL;
    std::uint64_t aWandererI = 0xA9CD484C0A062004ULL; std::uint64_t aWandererJ = 0x82FB0E0DA4B1E676ULL; std::uint64_t aWandererK = 0xDF83828639D49AA8ULL;

    // [twist]
        aPrevious = 0xD2811B2F5BE18F7BULL;
        aCarry = 0xC1B5BA4BACBC37FBULL;
        aWandererA = 0xB86E9A36366B7171ULL;
        aWandererB = 0x9A701182BB0B0AB5ULL;
        aWandererC = 0x9BBF5CECFA30F8AAULL;
        aWandererD = 0xAE1696316C3922C6ULL;
        aWandererE = 0x86A262A7126EAE3DULL;
        aWandererF = 0xDE4B87C39F675B5AULL;
        aWandererG = 0xCE28B8BC3A85FE56ULL;
        aWandererH = 0xD4B82E6814C56BB0ULL;
        aWandererI = 0xC749AF315FA35501ULL;
        aWandererJ = 0xA5E11CF1FD54BE8CULL;
        aWandererK = 0xBBAED5DF4DEA6CBEULL;
    TwistExpander_Alcor_Arx::TWIST_A(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alcor_Arx::TWIST_B(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alcor_Arx::TWIST_C(pWorkSpace,
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
    TwistExpander_Alcor_Arx::TWIST_D(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alcor_Arx::TWIST_E(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alcor_Arx::TWIST_F(pWorkSpace,
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
    TwistExpander_Alcor_Arx::TWIST_G(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alcor_Arx::TWIST_H(pWorkSpace,
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

void TwistExpander_Alcor::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Alcor_Arx::GROW_A_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Alcor_Arx::GROW_A_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Alcor_Arx::GROW_A_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Alcor_Arx::GROW_A_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Alcor::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Alcor_Arx::GROW_B_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Alcor_Arx::GROW_B_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Alcor_Arx::GROW_B_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Alcor_Arx::GROW_B_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Alcor::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 2 of 33
    // Exploration cases: 0
    // Structural maximin 661 / 674; family total 661
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
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7789U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3648U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3558U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8149U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1690U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1555U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 47U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1780U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1960U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1330U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1510U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1645U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 2 of 33
    // Exploration cases: 0
    // Structural maximin 660 / 674; family total 660
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
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7609U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3288U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3468U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2838U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 610U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1060U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1195U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1285U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 835U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1105U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 925U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 880U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 520U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Alcor::kKeyRotateASalts = {
    {
        {
            0x4BB275EAEEB4F40AULL, 0x2AAC8BE7CBB1A90AULL, 0x50DD67F428C0EEB8ULL, 0x620AB0628477C885ULL, 
            0xD7EA83261807FD62ULL, 0x1E44E11ED5BF3C96ULL, 0x91FC15373EF2083AULL, 0x97869CB5FE69309AULL, 
            0x12E148D71CB620EAULL, 0x11121DD814187DDFULL, 0x2A88A2E57C5DACF0ULL, 0x364955363FF58D10ULL, 
            0x5C96A622489957E9ULL, 0xC2DEFA972D1D46C6ULL, 0x86175FBE7AB4CFDCULL, 0xA4C064031BC67033ULL, 
            0x2C671FEDF1F8B47BULL, 0xF201292774FC5010ULL, 0xFB65F8C8125487A2ULL, 0x0784699D6F846841ULL, 
            0xBC71048555A540CEULL, 0xF7D1FAB0E8B33D26ULL, 0x1F6CC1E89C8E5C1AULL, 0xB68E976441CCAB46ULL, 
            0xA28250319470F20EULL, 0x70C21FE6F57C91A4ULL, 0xB79CFA683D1C946CULL, 0x07EA5D05715B6E21ULL, 
            0xBADA8A20556A5952ULL, 0xC27BE93A50F3B729ULL, 0x20203BF6706C47BAULL, 0x18B5BC4B49C50704ULL
        },
        {
            0x5B8E4EFA359E9235ULL, 0x8137F3C377BFED0AULL, 0x8801D94F3050976EULL, 0x57DE2B4AF4DF648BULL, 
            0xA906ECD99EB1E9DDULL, 0xF71F622D15D24AD6ULL, 0x4B95B39DA251A727ULL, 0x00865921AEE8EC7AULL, 
            0xE205F9084B1B9D39ULL, 0x7E6CB07BC767ED0BULL, 0xD2E8AEF92822AB1CULL, 0xC70FFE2415341E9EULL, 
            0xE82FB4967D440FF0ULL, 0x6797ABB8F300B952ULL, 0x0AEB151BF65189D8ULL, 0xC5A9AA1A62FABB54ULL, 
            0x0B2D587CC646F976ULL, 0xF9FD97E2946F15DEULL, 0x16A94A02B1F0F2FCULL, 0x4A3301C8235F0BF1ULL, 
            0x726CEE2550B5714CULL, 0xCA409419DFAB364FULL, 0x44B14E86C304BD61ULL, 0x5F18318AF3CEACC6ULL, 
            0x53909D9331C3941EULL, 0xB0F97B7AD7C33F26ULL, 0x50C8BAE277142B09ULL, 0x83AADB9C0940715AULL, 
            0x2BFAA4E934D8149EULL, 0x29123FBE5427B4E1ULL, 0x3C10730673A8DC00ULL, 0xDFC7D787895273F9ULL
        },
        {
            0x5793D0754C93068DULL, 0x605D429217806180ULL, 0xA26CC67DE3AD53EAULL, 0xAD6390507CD03BA7ULL, 
            0x777A40EC0D20BDECULL, 0x3FF6F297B95BC227ULL, 0x324AFD32125D7B7AULL, 0xBF3BC0A33749B733ULL, 
            0xC506809051AE1594ULL, 0xC57E521B848CC834ULL, 0xFDABEB0845FBDA68ULL, 0x5B71B266EFEE3B76ULL, 
            0x12E9A680772087B8ULL, 0xD74EA770E439580FULL, 0x50E3E6EC4BC3EE43ULL, 0xCB612B0F7ED23492ULL, 
            0xEA312B0F5EDE2F53ULL, 0xE18811E7C21DFF0DULL, 0x83B21A5CBF5BA09AULL, 0xEF70ADD9C45CBA4EULL, 
            0x58537C2F4193C81EULL, 0x12ACF4277738D43BULL, 0xCF23F90AC6B530F0ULL, 0x1242363BA406DBA6ULL, 
            0x8AB495A324648BD3ULL, 0x2DC8820A74A5807BULL, 0x818E1E802B070CBDULL, 0x48FD369863ACE8F5ULL, 
            0x7B2163467A39E9FCULL, 0xA65E3713D9F9E033ULL, 0x3B3893A636FA1BD9ULL, 0xDF4CDB7B3EB7DA10ULL
        },
        {
            0xC8A1137764283903ULL, 0x92F2ED60B28F3CF2ULL, 0xCDAD8CE354B65F7BULL, 0xAFBDA048222D5034ULL, 
            0x6F8E657D3B564356ULL, 0xE96532CF57885724ULL, 0xFDE3AA510C627879ULL, 0x693C7ACE588069F5ULL, 
            0xFF080B4439FEFB97ULL, 0x998649E159E9CC7DULL, 0x41F220F11E71643FULL, 0x196AB0D1799A0E52ULL, 
            0x4B7BC6AB2DC066C0ULL, 0xDCD85BCE007BEC88ULL, 0xA53E8BCF8492868DULL, 0x2A6A78FDCDBD374DULL, 
            0x5871BA112E32E967ULL, 0xE85D7E73913DDF5DULL, 0xB753803F3A7B34C3ULL, 0xF143FA093733D823ULL, 
            0x6743F1BFCB51ED23ULL, 0x2510995D0B1DB274ULL, 0xCA3EFC5AA193E14FULL, 0xB662795D8A5ABD73ULL, 
            0x60E17AEEE185DB41ULL, 0xADE2FBACA754460DULL, 0x70DEBA54923FE69EULL, 0x54CA5FB64BA5CDBEULL, 
            0x0BCCBDB4D1C466FDULL, 0x400CC835FF80E253ULL, 0xF687347B93EB898CULL, 0xCE865DFD4485C096ULL
        },
        {
            0xA2FEABFA4A15A1C7ULL, 0xD1C9916A13E9A991ULL, 0xD93CAEEECA7EA87EULL, 0xC5222A12F1E220E4ULL, 
            0x7E27448E9C3F06B1ULL, 0x122A53EC9C438616ULL, 0x0BCAFC97E58A2CDFULL, 0xE9323264C0D9AB53ULL, 
            0x2801CD63399882DBULL, 0xC45C6CB44160F952ULL, 0x73D5D09A35756004ULL, 0xB93899A30E50CA92ULL, 
            0x3A45746DBEACCACDULL, 0xC2A517156F9C8444ULL, 0x9AD1B1BC272A8487ULL, 0x37CA52997F6B6BB8ULL, 
            0xB28717F5C3DC54E1ULL, 0xD1453BAD0382FAF5ULL, 0xA1E3B76DEFBA6B9CULL, 0x781A9205A8A01D5FULL, 
            0x0EEB6B5CD24CB208ULL, 0x7FD7D5CEFAE7C420ULL, 0x8FF572D415B1556BULL, 0x520DFB6FFE425857ULL, 
            0xF8A8205DF2FAD6E3ULL, 0xBE2981F9F0B248C2ULL, 0xAD83ECDBA9D18F4AULL, 0xCA8B57D1BAD79F4EULL, 
            0xF4C07B38F2EE5790ULL, 0x263E6CDCFD20252AULL, 0xC98C3B0942560C9EULL, 0xD7BCF5C56104E631ULL
        },
        {
            0x8603EEF8A36C6771ULL, 0xC947AEADE3BCEB30ULL, 0xE2A051561115A645ULL, 0xB5C738CB0F8F4818ULL, 
            0xDCBBB04F11AA5A60ULL, 0x9BE9482CDA510E66ULL, 0xA511485492792F18ULL, 0x99ECBECCDA857597ULL, 
            0x3875DE3FBE7A78AAULL, 0xC0D2A99C46716D3AULL, 0xAD1C297ADE87BE3DULL, 0x351603E2437EE5F9ULL, 
            0x49BAB9E9799ED432ULL, 0xE2E1FDD001AF7D3CULL, 0xDCFA5727CC9BD2F3ULL, 0xE75B5CF0EE0824D8ULL, 
            0x856E27BCD84A7DA2ULL, 0x43ABE958937902FAULL, 0x7D48F228F6FE51DCULL, 0xC1F3A6A868C01A05ULL, 
            0xAFED67CD4EFA07FFULL, 0xB4449E5DD23AE0C4ULL, 0xA9744A872AAE3BCAULL, 0xEDD5429F99511612ULL, 
            0xF010CF4CB96F250FULL, 0x7E0B5241A0AB7B98ULL, 0x78BA3753506499F8ULL, 0x611BD7DB4EBCDB5CULL, 
            0x3A2D8B4B977F21B5ULL, 0xEC2F7DD756FCA74FULL, 0x8FDD81D40EDE2D99ULL, 0x48412055086D3AE7ULL
        }
    },
    {
        {
            0xF58CFDFFA1D8825FULL, 0x195960E0C9CC4929ULL, 0x8C391472D40EA10EULL, 0xB6825ACC1F651B0CULL, 
            0x5281052EA87A5989ULL, 0xC86B6DA257ACB9CEULL, 0xDED6800A6A049396ULL, 0xA9F69428B8D70E67ULL, 
            0x7581F14D45B14F66ULL, 0xE6D4E61AB67ADFC8ULL, 0x914D546DEF6BA5E5ULL, 0xB1E7A2D6EFBFD910ULL, 
            0x06D3F8C2F43DD10FULL, 0x9A8D1ADC3BF4D882ULL, 0x8F59B4AF4A9E8BFAULL, 0xBE09522AFB143EA3ULL, 
            0xFB91064375698154ULL, 0x0DDD575DE4220658ULL, 0x32427CAD08FD2045ULL, 0xEE554D8A0284A5D4ULL, 
            0xF0C97FA092223801ULL, 0x77CF9CA1BA412481ULL, 0x067CD73E55103EEBULL, 0x80B8CD49C074B880ULL, 
            0xF5A289852D65B6ACULL, 0x2A1C89EA909A988FULL, 0xB1A23449FFFC268DULL, 0xC8D5843A41FD54DFULL, 
            0x5A0F0E69E8804251ULL, 0xF87BC938E15C82FEULL, 0xD98DE9AF9F1178FFULL, 0x38DDCD7731184A8CULL
        },
        {
            0x7D6FB7DB6EB863EFULL, 0xEB80DEF4C912E849ULL, 0x2A9124316719A727ULL, 0xACDC1A3CF7A82693ULL, 
            0x65D7068C6FF14203ULL, 0xC89030072DF15E1EULL, 0xB7422553E95E8111ULL, 0x5D48F7A98E908033ULL, 
            0x73E8BC9676314050ULL, 0x58884A9F32A86128ULL, 0x3D9C437187026BE9ULL, 0x8B26B8AFA4FFF397ULL, 
            0x694A97C80F22ED54ULL, 0x03A8E9619A0400B0ULL, 0xF7B2C875DE033B45ULL, 0x6478B7D98C5322E6ULL, 
            0xF15B49478A0137B5ULL, 0xDB61A3690AC4561DULL, 0x9DD9331A5B6CD5B5ULL, 0x839B3461DD27B940ULL, 
            0x7D8C89E3B00E533BULL, 0xE1D3894C5B6D97C9ULL, 0x97C3942BC1D75D8CULL, 0xFEA4C663A9943BC6ULL, 
            0x0724FBA949D114ECULL, 0x5EA6788A7FA56FE3ULL, 0x23894C53D5D17B73ULL, 0xA2C24062FE411177ULL, 
            0xDF40F4B87CF282F3ULL, 0x5A8CF3560DE64182ULL, 0x7FA2E62BD6F5EBD6ULL, 0xF703045203AA59D6ULL
        },
        {
            0xF189E9850B30A608ULL, 0x977E57FC993531B3ULL, 0x8CF2472F96F392B9ULL, 0xA71AA346A41CC8CFULL, 
            0x7E2C842DF8E941ACULL, 0xB5B13621AA4708E0ULL, 0x57102A6F4576EEBCULL, 0xA7AA78C35A1473C8ULL, 
            0xC1429DAB78579D5AULL, 0x7E6A8B3D5F93540CULL, 0xA3676C805B13C343ULL, 0x1A13ADB41A51D464ULL, 
            0x65A8E6E2C50ABFFDULL, 0x586A4985CB027014ULL, 0xA67926D1146B4C77ULL, 0xFB2D5C55AA1F4D31ULL, 
            0x425C0D0D10179A33ULL, 0xF8B90A15D6DE7D90ULL, 0xC73C10794566E122ULL, 0xD204E837195D11E1ULL, 
            0xBE22AF3C8C04B142ULL, 0xA2754330637589EEULL, 0x89B2F1DE9CF70EF8ULL, 0x7B617519C01307DCULL, 
            0x0F2C63A56ED155B9ULL, 0xA9B6E9B61917F454ULL, 0x41E2DF7A5F27468EULL, 0xC9AF6DC115597174ULL, 
            0x0654E85BFE3C26C2ULL, 0xE7BA6FA5754E164EULL, 0xB4EE2BE2A4BB0D35ULL, 0xB158225B4A39FA42ULL
        },
        {
            0x589842CC1B9DD3DDULL, 0x4A66C18603FDCD93ULL, 0x04763067E321C327ULL, 0x7C849056FD4E3C95ULL, 
            0x71968996440EA9E0ULL, 0xB35A0426094BB52AULL, 0xAD6F0E89B2B2F488ULL, 0xA98FC7BEE7B00174ULL, 
            0x8017722FC5C254A1ULL, 0xDB510BD2A121A873ULL, 0x5422F7F73C348689ULL, 0x13ED2A7F1BEE44E6ULL, 
            0xE19EC00ED9FEAD3DULL, 0x896E6C98AD77DEEFULL, 0xCF421805BA12C859ULL, 0x2F9383C4C3059244ULL, 
            0xE9082F2D63951DD7ULL, 0xDD4BBFE6971BD8B1ULL, 0x94A93B6CD475B40DULL, 0xF39305A8D08EA114ULL, 
            0x3A67C8677832746EULL, 0x9D2A7693DFEC59B9ULL, 0xB1B41EEDA2A01A84ULL, 0x7A1C2CE22C224A79ULL, 
            0xBA2EBAAB04E9FF73ULL, 0xCD40A65B9528CAA1ULL, 0x2D195333008A5D08ULL, 0x30EA79560428B2EAULL, 
            0x72A776F45A6A2FEFULL, 0x283F971EEF4B18C9ULL, 0xCFE59A0513C3C955ULL, 0x17FFF7CD43A66C92ULL
        },
        {
            0xBFBB0E3EAB4B01CAULL, 0xBA044F2DF801ACA7ULL, 0x78C5C2EECA42413AULL, 0x7913ECA5BF51019AULL, 
            0x565FDAA07273C001ULL, 0xF336937E9AD6C820ULL, 0xF5EFD18641ECD3B7ULL, 0x1C2E4F2AA9111BDEULL, 
            0x5A5204A57E5C2525ULL, 0x65C67068BAC0738FULL, 0x56ABD81CD0308B3AULL, 0x99A3638AA9AFCD03ULL, 
            0x612AF901E2AD92AFULL, 0x3ABE2536B235A0C5ULL, 0x404952D5132E8221ULL, 0xDD2981D1D8D6BD1AULL, 
            0x302082AC9C58DA97ULL, 0xA8F724FEFF91D3E1ULL, 0xCF929259FC1E0AECULL, 0x5C4BEF8BFD9B0F8AULL, 
            0x4E5C26DEF559784EULL, 0x10BC80748BED30D9ULL, 0x9771EA78FE419214ULL, 0x8AEA095B1EDDF8B8ULL, 
            0xF2434B31AFD00BF6ULL, 0x83C76A2CB02F566DULL, 0x5BD766F1EFEC68B7ULL, 0xED623656FA9790C0ULL, 
            0x059272E552CD6B83ULL, 0xD7EE7E8D1E882E72ULL, 0x0226FC425D1CFBE8ULL, 0xFB091D69886BF15BULL
        },
        {
            0xF021247D803CB871ULL, 0x1B0C0675D8FFB758ULL, 0x443D345C7DA52550ULL, 0xF56EBC53F7DB6A9DULL, 
            0x92C49FCFB8468B02ULL, 0x9A9655B3C35432FEULL, 0x2AF36ED0F7AAED2FULL, 0xCC10ADBFD794F3FBULL, 
            0xCAD0081D8214C6EDULL, 0x6E876148C21378F5ULL, 0x6276F24F45F1CFA1ULL, 0xB25441D75A802D8DULL, 
            0xE62C55CFF75D1563ULL, 0xB28E81E7F75E2A5CULL, 0x22F041DD7CCC439BULL, 0x789A6F196E840129ULL, 
            0xB76C951108C22CA1ULL, 0xF1BF76A7FD32AA63ULL, 0xDE4AC2A7AC8923B1ULL, 0xCBAC2C2C243E5417ULL, 
            0xE793C7CCC2654456ULL, 0x641422590E50A760ULL, 0xB5429E4C106D75B9ULL, 0x71096A3A21351A32ULL, 
            0x3FC449C2A2F11DE2ULL, 0xA31E05DFA95A0B26ULL, 0x2D219F5E89ACACDCULL, 0x908E88EDF58E12E9ULL, 
            0xF5FDBEA891B030B9ULL, 0x8086A2FAF883BA34ULL, 0xCB441047A6572EDEULL, 0x1FD3886F584373B4ULL
        }
    },
    {
        {
            0x8AD4115EB4CD8A11ULL, 0xB6998A2EE3E0FB50ULL, 0xB77350391008E33AULL, 0x18012B2A080ECE55ULL, 
            0xAEF0E88A67E8F179ULL, 0xAD7B3CC32B266D55ULL, 0xE6936F6639DA4E2EULL, 0xA075C9F7DE8E4E08ULL, 
            0x317A2FBC3F9B6457ULL, 0x170235BB2591A822ULL, 0x6017EF67B927F804ULL, 0xD5E600B14A4A6A4DULL, 
            0xC5BECED3366792B3ULL, 0x634729193260AA60ULL, 0x24304A02819E7666ULL, 0x5F7AFB0C98C7AB61ULL, 
            0xBBD8CC4E2796736DULL, 0x71F026B21D092135ULL, 0xDDC719E49512A8D7ULL, 0x0951E4364C62831AULL, 
            0x81B3EE094BD26A80ULL, 0x05D3CC794D1A45E3ULL, 0x2D58F81E940F1CA3ULL, 0xAD59D4C4775C954AULL, 
            0xD21926FF7C3479C7ULL, 0x1779CF89BB3B4698ULL, 0x9A0CE98609DD294BULL, 0x80336E265F336237ULL, 
            0x3BB5B7670C608D48ULL, 0x62552495701CE743ULL, 0x42966DD201C97D95ULL, 0x681CC3392BD8BD94ULL
        },
        {
            0x2E3BB291ECF84A89ULL, 0x3FFCF3A64276FB86ULL, 0x29FA62F56C20AA54ULL, 0xD98D4CF5D01EDFDAULL, 
            0x6AFE793DDEF7003FULL, 0xCEB8E4C5AA3543EFULL, 0x22E9367967120A1BULL, 0x6F5299497D958B37ULL, 
            0xB68714022D71024AULL, 0xFFB78CA44AB3E487ULL, 0x902FE9E7C76DD968ULL, 0x4A82E6A6CE555CFFULL, 
            0x10C2A6BDB2411C3EULL, 0x06707B38E6653BABULL, 0xED769F652AEBB95FULL, 0x8C59315AAD7D16E2ULL, 
            0xD745C6BEAE6093D8ULL, 0xE1E4A131F1648EE3ULL, 0x97C8AF290F880FB5ULL, 0xE7A430B41A62E4CAULL, 
            0x4A44E8F3BAF3E135ULL, 0xEBC8033E64931BACULL, 0x3813ABF188B5CAB6ULL, 0xFDCE021E1C8ABFF0ULL, 
            0x0C8BF03F7EED1E3BULL, 0x41FE755B6DD760B7ULL, 0x8730531E9CDB2342ULL, 0x426731952B63FE84ULL, 
            0xF187248E45ABA4A7ULL, 0x0FEAFCCCD264AF7BULL, 0x870293504F0FE0F9ULL, 0x59CC7E5669DD34BBULL
        },
        {
            0x50AC8F2FA2DA9344ULL, 0xE35C59453D8B6DA0ULL, 0x03634F2E5D079449ULL, 0x6460F99AB47EA1BFULL, 
            0xFB53FDE64CCD3C55ULL, 0xEE619DFACF04610AULL, 0x33811E3037A379A5ULL, 0xFA30E86DD0AF0288ULL, 
            0x95829D24531566B2ULL, 0xEAAFEC9CC64C81BDULL, 0xEA86C31F6AFD2B93ULL, 0x3DCB932D04BDDC90ULL, 
            0x886BD3B6FEEB3390ULL, 0x2B6878CB248D5349ULL, 0xC849A6D7FFFCF280ULL, 0x702984DE091AC829ULL, 
            0xC17879496AF449EDULL, 0xAE3BC836FAD437B0ULL, 0x4B67F73E27BA3719ULL, 0x56E536E39B12C906ULL, 
            0x886B44B2CA269D19ULL, 0x739FB096048323DEULL, 0x6C77A38C7A132DF2ULL, 0x6E88A2BA0A33A664ULL, 
            0xDF3A04BBC775390BULL, 0xC87532A330B8A4CAULL, 0xF3E629F45CE9D43BULL, 0x4A711AC431A0C670ULL, 
            0x341AC0CE623DA01FULL, 0x1EEAC5FF9A0BA93DULL, 0xB0BFF9D409AAF283ULL, 0x2F78AD9E62C0B914ULL
        },
        {
            0xE056ED119E6C9404ULL, 0x80CB6D617A473C1EULL, 0xA5AA4154DC042CE7ULL, 0xC1F76CB38C0E2DEDULL, 
            0xEBBE693A4EC17152ULL, 0x30D10A32A66D1F7DULL, 0x1E1D3DA263872777ULL, 0xBA7F427E0A1D6FE2ULL, 
            0x21B654A0A60A9CCDULL, 0x83A17A67306E5E8FULL, 0xFAD6A187E76FFEB3ULL, 0xBCBDB89862012398ULL, 
            0x5055F7B6C7F5C1A5ULL, 0x3186B21EB37E3B56ULL, 0xAA49493B8B06D7D1ULL, 0xBA489AF82D172C99ULL, 
            0xF86F0995CC1E7272ULL, 0x17F270754A050E45ULL, 0xE6BE97FE966A0EE4ULL, 0x2818D7C2E4C267F8ULL, 
            0x28653CCA2E9FC357ULL, 0xE8E7A76D54008F33ULL, 0xDD6C64FA2B58D1E6ULL, 0x2AF8CB7EEFF697C5ULL, 
            0x8CCD354E7BFE19C0ULL, 0x3120558A823C99A8ULL, 0xBFBB3A018571E20DULL, 0x7617E2AA19A05C96ULL, 
            0x44E7168E47FA255EULL, 0x5F0C9769DC271B4EULL, 0xF15B4C5AEBD85815ULL, 0xA4CAC628656CA9F7ULL
        },
        {
            0x7C1DAB32E106C659ULL, 0x7D59DC6742991FA4ULL, 0x27BEC07D14EC99B7ULL, 0x9775EA4074F6ECE4ULL, 
            0x7A073823C56038D6ULL, 0x867D68C452125061ULL, 0x94EACD36FC8EA756ULL, 0x7DB1B83EBC149528ULL, 
            0x69788E39EFEE11BBULL, 0xDCCC4BD2D545D16CULL, 0xC25AFBD4E4E4A4D3ULL, 0xD46C6A2C8557517EULL, 
            0xC4F9D4A288929E15ULL, 0xEEAF98AE4AA47A5DULL, 0xB4AD7BCE3C6771EBULL, 0x31D5A600E0D6CBEFULL, 
            0x94A36BB8A34BAAECULL, 0xC6F9EAC5C4299152ULL, 0x06B600F1EE3268BFULL, 0xEEFB3D334782B4ADULL, 
            0xF011AA50E42CEE47ULL, 0xEEE1D27F6000685CULL, 0x46C4067821955537ULL, 0xFF54E50EA8C427DEULL, 
            0xFE8BB06D280BFA21ULL, 0xD5E5219E2500B5ACULL, 0xC76DA2F6854B2D90ULL, 0xE72C60C08B990E7EULL, 
            0x680E3C997BA28FC3ULL, 0x40E8F318E1D660F2ULL, 0x41EDA7F794CB5441ULL, 0xF8969FD781C43A68ULL
        },
        {
            0xA0448CFF18D5A12EULL, 0x238645C7D6371E4DULL, 0x7C6085FCDAE2B24FULL, 0x54F9097C9F10E4B6ULL, 
            0x297D0A0033E77C40ULL, 0x8EF2A589E8953BF5ULL, 0x6D34BC55E6DF845DULL, 0x2A95AAA3AC12AD54ULL, 
            0xC3A579DAEC627725ULL, 0x8FB2FC482A2B0E3AULL, 0x1EF61833A8B9C6F8ULL, 0x9CAFAC8B66E1ADCDULL, 
            0xC9153DD65D747CC6ULL, 0x2C083157EBB8072BULL, 0x2F234D7CB11659CCULL, 0x04D2C76204B5465CULL, 
            0x6102C63D3B063982ULL, 0x79ACB0A5CEA32D33ULL, 0x0FD586F187458E87ULL, 0x40C999009FB260D9ULL, 
            0x64CD2EB06FABDF18ULL, 0x549CD89FEC706375ULL, 0x43142F2DAB786D92ULL, 0x5E17C59CEBB42304ULL, 
            0x6699927CEF802296ULL, 0x25A4A7827FEA7107ULL, 0x6A0EAE8A72A1508DULL, 0xBBDC1B021BE7D1E2ULL, 
            0xF93A0E023E3847BCULL, 0x53D79409EC6E4A8FULL, 0x890389FCA8282F6AULL, 0xBB886D7776C36AB3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alcor::kKeyRotateAConstants = {
    0x937171D17554EFFCULL,
    0x8A8C78B5C985C6D0ULL,
    0x478B748164A5FBCCULL,
    0x937171D17554EFFCULL,
    0x8A8C78B5C985C6D0ULL,
    0x478B748164A5FBCCULL,
    0x4CE7C4BA56BF4124ULL,
    0x4B570964F44A514BULL,
    0x49,
    0x50,
    0xAB,
    0x74,
    0xAD,
    0x6F,
    0xA9,
    0x53
};

const TwistDomainSaltSet TwistExpander_Alcor::kKeyRotateBSalts = {
    {
        {
            0x6C01C41E7E21A5A2ULL, 0x1BC8D9EECE2822CDULL, 0xBD46C8BCB5A98C59ULL, 0xA693CF69BB69C4C9ULL, 
            0x14E7B46AE43E47AAULL, 0xF6F242C2CF55CDDEULL, 0x41921594A4CCD214ULL, 0x77BEAD687CED522AULL, 
            0xEFFC10DF99B69287ULL, 0xD16C441F27A9EC86ULL, 0xDC7D64C000A5A9B1ULL, 0xED25F9F14F3B61D2ULL, 
            0x86703130F5B578DDULL, 0xEEE0C0C7D78935A3ULL, 0xB19D6C87F9CBFA29ULL, 0xF673E8B2A1C44CF1ULL, 
            0x76005B4A4FD6EF2CULL, 0x0A50F484F4384105ULL, 0xB0CB332DC76E79B3ULL, 0xCC0F5756E4DA52F3ULL, 
            0x4C87D6C00CA87FE7ULL, 0xBC6B035FD8035F20ULL, 0x6C2B1C84287C29DFULL, 0x96D584BAF0CC6C3EULL, 
            0x04E25738A635CDE8ULL, 0x526CCEDA93CC6F2DULL, 0xA622C5F7C9E2ED9AULL, 0x53F905FD1FDE3D45ULL, 
            0x91CFEA54E69B7E8EULL, 0xA86AADBF88419471ULL, 0xBAB77AC17C7CA620ULL, 0xAD226210BE4DC625ULL
        },
        {
            0x52DCA89FD0B56076ULL, 0x9DC30CA70096F962ULL, 0x8E19CF3BC949298AULL, 0x0BB8CF7EBE0F6B0DULL, 
            0xF883B29996A02BC9ULL, 0x2F6808D73BE26474ULL, 0x51030BB2327746F5ULL, 0x72550F12605DCB07ULL, 
            0xDF2E11E91F956EDDULL, 0x903A41DD37435D12ULL, 0xF54A7542D3B031E9ULL, 0xC1DEAD6393035891ULL, 
            0xC3F7D0348D8EB025ULL, 0x6B98BF1EE5580611ULL, 0x66A371BC6FE7EB93ULL, 0xDE1166115F2B7CB4ULL, 
            0xB95862270B133047ULL, 0xCBF88B4A3F49367DULL, 0x8BD4FFECEA641F09ULL, 0xB70381E1A982F579ULL, 
            0x64C681F2942E163DULL, 0x3290017E56CB8253ULL, 0x7931728FC22FBBE8ULL, 0x53B78F2D9C1C9E3CULL, 
            0xEAEAF6F42017E6BCULL, 0x4D2EAB507CB2DFA8ULL, 0xFE6DC39A84009C51ULL, 0xF871E02E9CD247D3ULL, 
            0x07BB3418A709A0BDULL, 0x9A17714FF390C9D7ULL, 0x7B845404FA87A614ULL, 0x352449726620180DULL
        },
        {
            0x5E13C98F561B1D33ULL, 0xCE2D5ED0A3068B13ULL, 0xCAB558211A4E823FULL, 0xEA4847B1F26A9F31ULL, 
            0xD9E4943DAF88D43DULL, 0x6C5CCED7F9A5EDB9ULL, 0x7BE2E28C88CAAF15ULL, 0x72F1ABDCC1ECB546ULL, 
            0x55A9F6CFE499164AULL, 0x82A8A70D52790BCEULL, 0x2CF9942481D9CD3FULL, 0xB205A19C2B129219ULL, 
            0x09925E1DD7A1D99DULL, 0xEC15D80A41B1EEF7ULL, 0xB4C6BB968EEDBCC8ULL, 0x9A2E877624E858CFULL, 
            0x61982FC02026918CULL, 0x64B54D0CD48F36ABULL, 0xADB4B69351F3761DULL, 0xC1200991CD35DCA2ULL, 
            0x944E3342F85B475AULL, 0xCAD3162FC775A297ULL, 0xEC48DB1DE819FD6EULL, 0x7B337DF72C43F8E0ULL, 
            0x83A33EF7EB377DB9ULL, 0x5A8F9CD256A71A41ULL, 0x04116EDE3F2C612FULL, 0x9E36F0E0FDFB7CCDULL, 
            0x827E2DEB7598E6EBULL, 0xF0CFD2DFE23B1F92ULL, 0x539C7066F714CE1FULL, 0xDF9F427DCD0CA50DULL
        },
        {
            0x6913BEB75ED7DB14ULL, 0xF5AD776350931718ULL, 0xC4AE0A424868FCBCULL, 0x3FA1F7067A7DC3E5ULL, 
            0x638070650886EC52ULL, 0xE7C00DBA0B1A2DA8ULL, 0xDADB4A0C8C94EB06ULL, 0x8C9F5C6B1583BF26ULL, 
            0x7CA10F14DC0601A9ULL, 0xE43687B167F7690DULL, 0x664024BC3F3D473FULL, 0xD40C0908A748E09CULL, 
            0x27BC43FD9624E1AFULL, 0xC7B3E4154DC71343ULL, 0x3F7931ECF420F38BULL, 0x801EFB006F8CB77FULL, 
            0x326353236066E592ULL, 0x81F171E9E1C0E271ULL, 0x1017949288AC3AECULL, 0x7CBE823B9E2A3D9FULL, 
            0x3B01D836668E532AULL, 0x6F449BF1F7BDF10AULL, 0x261B4E7D6A3BFF28ULL, 0xAA7110BCA4A161A0ULL, 
            0x9D094EFA731D5116ULL, 0xDDABCAC80050AADAULL, 0x30D6D8EC0B4F0150ULL, 0x06817D7E533CC271ULL, 
            0x75E6FB1330023E66ULL, 0xAA01CB67ED93C55CULL, 0xFCB0B3A29231CA8BULL, 0xF9EFBBA8AC551769ULL
        },
        {
            0x2E394ABCBE9099DAULL, 0x4D561354E138F37EULL, 0x5ABB319595F0D5ABULL, 0x38CDBA0AAE0727A1ULL, 
            0x43818E92CEA48097ULL, 0xE4A4ED751B61FA11ULL, 0xFF6037DD4CE30122ULL, 0xEAAC95132D8F5ACCULL, 
            0x868B1E8336FBD631ULL, 0x559A30E6EDECA0A1ULL, 0xB401289BA1C7B62BULL, 0xFB020A50EA9B4FBEULL, 
            0x2B55183CA6DF3D3DULL, 0x1B8C1CC4973F65E8ULL, 0x472461E99E743B33ULL, 0x689397B1EF11A13FULL, 
            0xB250A1F57D361EBAULL, 0xAEDE24EAE249113DULL, 0x36E86DE6188ADFD2ULL, 0x6EBCFD12D5D7C642ULL, 
            0xE8671AE14FCDB580ULL, 0x639CBC3FC389E52CULL, 0x8A66DDA8A2447563ULL, 0x1CBE11D101E95BF3ULL, 
            0x063CD07E1384EBB9ULL, 0x058743D2A96F41CFULL, 0xF559FE599F7CC56FULL, 0x2304D77493B8E0BDULL, 
            0x0766D8F1BCE05C30ULL, 0x5D532995A9E61E13ULL, 0xCD0BE0253DF2A915ULL, 0x7266B3F8F068520AULL
        },
        {
            0x0A179863B1F5B186ULL, 0x3DF7DA086210961FULL, 0xFB59F3F5604A512FULL, 0xA3B0FD5C4C9EDB58ULL, 
            0x296218A0848F352FULL, 0x61D49DA45EA559A7ULL, 0x4167A3DA02B07536ULL, 0xE230F9314E78D505ULL, 
            0x9A3B2DFA6F8BACE5ULL, 0xABEF56BDD5044130ULL, 0x3C513226DF632C44ULL, 0xAC2E1350F5B95C3AULL, 
            0xD657D71DB99B8BDBULL, 0xA89D8E2B190B6A53ULL, 0x42002B968EED2F0DULL, 0x8515B2A720D98B49ULL, 
            0x47BF618CB3E32440ULL, 0x2C8137CDDC4E8987ULL, 0xD942D2B1834EDAE6ULL, 0x7B74C093ACF863ADULL, 
            0xB361D5DC135E4729ULL, 0x36883BE43719C42DULL, 0x7EE23F8FB3061A65ULL, 0xA38024D31B1C63B4ULL, 
            0x34B0E30294ABE703ULL, 0x22B04D2575F7E383ULL, 0x63B98FFD26533920ULL, 0x9BD1DF0FC506D218ULL, 
            0xAE8826D5C4D99E02ULL, 0x66DC28C44BCA8B58ULL, 0x1418BACB40EC81E7ULL, 0x3DEADF0BCF4FCA7CULL
        }
    },
    {
        {
            0x8F04C45AF10AD036ULL, 0xC320963ED0B8FAB1ULL, 0xD7FAEA6DB021D333ULL, 0xFFC41ECAB112FA9BULL, 
            0x79302A3FA99FA446ULL, 0x5B2589560BC7140BULL, 0x194C74CA701D26FBULL, 0x1FA07D74097B4B89ULL, 
            0x2A6089E15E2B42BAULL, 0xC70CDB20E2DAD843ULL, 0xF3C39F5A66F33CC4ULL, 0x71262D8AA6E366C1ULL, 
            0x62BFB9442B7A97D2ULL, 0x776585EE59018DBFULL, 0xDE35B028DA9FB04DULL, 0x592D5D907722E11CULL, 
            0xBC09D3DC9D5E5EB4ULL, 0x7BDE0F4B09BDAEBEULL, 0x453E41E1969BBE2CULL, 0x39C240EA05199D24ULL, 
            0xF55B8724389C0839ULL, 0x4916429BFBCAC0C9ULL, 0xD7C39B8CDEA87B3BULL, 0x0EE568CC26C783D7ULL, 
            0xC3D68EDEE06B5664ULL, 0x0A41CEDB5A7DBB94ULL, 0x2898FA8817CDB4ABULL, 0x7EF7D9CB860C05E8ULL, 
            0xB9F9EB496BD9F8B7ULL, 0x7773B599A2BAB20BULL, 0xA4394F25E5B34CC3ULL, 0x3509D60F3FE4D642ULL
        },
        {
            0xF81C12B3017CD96AULL, 0xF5E3DD5E98213DD6ULL, 0x4A3EEF33CC4B3FFDULL, 0x7A91FBFEAEF86011ULL, 
            0x080ACA6FF77ABA24ULL, 0x5129CF878DB5A889ULL, 0xE8DD845373FE9098ULL, 0x9821D35C330E2AD6ULL, 
            0xE8EB6D4399934964ULL, 0xF4A9DE2F7006B9DAULL, 0xC88F0D970B5D2085ULL, 0x317F7C4621D3D07AULL, 
            0xF5DB7F8F6612C423ULL, 0xA1D4EC4DECBB2A70ULL, 0xBD5449C5B4C6E281ULL, 0x1223756C030D4C6BULL, 
            0x9516298C995CA7A0ULL, 0x6962F1EE0CA63556ULL, 0x04AF7EFBC77F28DFULL, 0xC08E66AED1251220ULL, 
            0x3D3BC5A4C8CF6430ULL, 0xD40818AE0D132619ULL, 0x11DE2750D4580856ULL, 0x161F79E80E74C9C4ULL, 
            0x728CAD8FF1AE545EULL, 0xE07026DBFE46658AULL, 0x329300CE23E55D89ULL, 0xC91C3766F24D460AULL, 
            0x98E2DDE2B97A129EULL, 0x107AF0C3F9EB8C36ULL, 0x9952A8DB32EE998FULL, 0xAB80285535608E92ULL
        },
        {
            0x4178CB550B85E32CULL, 0x2690C2866F4D40AFULL, 0x2DC114E7D7D66109ULL, 0xA646A8E3C25AEA01ULL, 
            0xFDA43545C2F9D07FULL, 0x4BDEEFD4CDE1ED6DULL, 0xB86BA6D8037E4630ULL, 0x5A8A893C775F6EFCULL, 
            0xED49A3F04843CD16ULL, 0xB51CE96C501D7D3EULL, 0xB7B6D70ECB8863E4ULL, 0x5E72EA50DB86F9B6ULL, 
            0x9877B87353E682B8ULL, 0x3513DF44F743DFC1ULL, 0xFE95BC0A63222847ULL, 0x98E05E2743ACF374ULL, 
            0x6F8D5A5AE5C43D77ULL, 0x187115578A626507ULL, 0x2DB2F70B8B46AD36ULL, 0xA864482E98D30420ULL, 
            0xADFF50B9EC563093ULL, 0xE5BC0E2AC67794ACULL, 0x8075295F83F42822ULL, 0x274D771B3AD31813ULL, 
            0x178F80D71186D892ULL, 0x2AE237F2E86DE277ULL, 0x6866117877DA3A3CULL, 0x6F61A99357DB9BC4ULL, 
            0x73177A0602F2E2EDULL, 0x0CACCEB366CB5D97ULL, 0xF513EE3A7A6DF51BULL, 0x4E3CB10E0AA720C3ULL
        },
        {
            0xFA133A32953F4869ULL, 0x6B403A358ABED245ULL, 0xAC18C7DC54E91692ULL, 0xB27B7AFAAF39F013ULL, 
            0xF6893B713F10C4A5ULL, 0x5815071A8811E694ULL, 0x2D4CB81CF14D78DAULL, 0x09B9B26E68506476ULL, 
            0xACF752C616ACACF7ULL, 0xCE5CBDEA102E4DD7ULL, 0x35C6380FDC3A8685ULL, 0x0E3A6E208D34E7F7ULL, 
            0x0584BF8637B90AD3ULL, 0x79E1CCD403F036ABULL, 0x3A0D0113D9FAC9DDULL, 0xA79B9F26BB48CAA4ULL, 
            0xBB7796037C349FF2ULL, 0xD8577F6DEEF686B1ULL, 0xEF14AA16765712EEULL, 0xE085B8CF7D4782F3ULL, 
            0xB1E3F7DF01FFC3EAULL, 0x5480E92D53493F66ULL, 0x476C5FF97F76D501ULL, 0xB0AFE30C4A5931CCULL, 
            0xC737D92ABF4B70A2ULL, 0x07EFB6BCF7217817ULL, 0x2A26F2EA7F861F77ULL, 0xDFFC398EA1AD7462ULL, 
            0x9DCAD9630795AA33ULL, 0x4D7AB5C64026BFF1ULL, 0x70A5DAA15CBFC746ULL, 0x66A8ADAD976F8B0EULL
        },
        {
            0x9BC0A323D810DAD9ULL, 0x805CB95966E2C4DAULL, 0xAA742DE0E2EBCF11ULL, 0x65A92247B87054F1ULL, 
            0xF36186BE0B4A6C8DULL, 0x3A1E15C8648CCE18ULL, 0xBB19AFBC3E77D882ULL, 0x0A6D1D5CC1827532ULL, 
            0xC9C899E65DFF7DAEULL, 0x2BE2354C86DF722EULL, 0x4B7E22BF03CB9B0CULL, 0x8756A4BB3EDB12F1ULL, 
            0x73219D11A619A049ULL, 0x95A3AE99960FB1AFULL, 0xCF6E595E4C01ACEBULL, 0xD3CE47F98F6BE526ULL, 
            0xAF096818B539A6E3ULL, 0xC4881496EC5FC9BDULL, 0x5625342074E4A4D1ULL, 0x3C492B901A6B1EC0ULL, 
            0xBE13B2B03057B435ULL, 0xC65862900A6181CDULL, 0x2B52217079C2F212ULL, 0x4AEBA9BFC5FD9386ULL, 
            0x8AE02C0456DB1A53ULL, 0x32533B854521B447ULL, 0xE1C06740FB668ECCULL, 0x9AFE6C46B3704771ULL, 
            0xCB3DCB78437C56A0ULL, 0x9274DFF035A9F369ULL, 0xA9B78935DFB2DBF1ULL, 0x064FF7DEC17603D6ULL
        },
        {
            0x3F03044B6B23B32CULL, 0x89142223E7227B77ULL, 0xEA3602BA30CD0A6AULL, 0x9AA513A0E5AFA5BEULL, 
            0xFDF7248F7A11541CULL, 0x2F576B594ADC3D70ULL, 0x7413957330933461ULL, 0x5963427844674F39ULL, 
            0x31467981952DDF90ULL, 0x0BBCA8AD9274C515ULL, 0x279015B19E6307B1ULL, 0x0DE93EBD37F94728ULL, 
            0xEFF3045089EB0C2DULL, 0x98FBC7A1F6D77C53ULL, 0x76B075C8CB38A5D4ULL, 0xB1C698EE5092E6D3ULL, 
            0x2529ACACC68E3986ULL, 0x59AE399640863BCCULL, 0x8E0719A8EF2ED4E1ULL, 0xD7240631A175FF0FULL, 
            0x0E77F5A646158629ULL, 0x90B4050DC8694C79ULL, 0xEBD9747F9A09DEA6ULL, 0xA7ABF7459ED9AE95ULL, 
            0xA7519A119F966169ULL, 0xE485453A50E4884FULL, 0xAE0B842EA846C616ULL, 0xA61F93CC1047D174ULL, 
            0x9AD66A77320515B6ULL, 0x8F5EB8D99737976BULL, 0xABD47634A6963E34ULL, 0x0C25A49F448E03B6ULL
        }
    },
    {
        {
            0xD5192E042CDBC907ULL, 0xE3B2EC79172D5BD2ULL, 0xDE8F01D40AC53591ULL, 0x5CE7B35ECAF74E48ULL, 
            0x674DA52B514393CBULL, 0xE5757CC34B121ABFULL, 0xDCB51CCFDAFEF99CULL, 0x0B20430612588AB1ULL, 
            0xB6D46B0D50D61C87ULL, 0x37CB4DA0BD817AE7ULL, 0xD403FC076D49A4A5ULL, 0x1ED6C3A37E9D319BULL, 
            0xD9D887C619A5ADA5ULL, 0x14D208167C21D61DULL, 0x8C455191AFC244B6ULL, 0x8B7FDD4C400DA95EULL, 
            0x339CFA3107BEAFC8ULL, 0x27C8D2BB5435653AULL, 0x39C032A37E409FB1ULL, 0x6D31A796E334A1CEULL, 
            0xA9BE550931B93201ULL, 0x27AD6C0ED7245968ULL, 0xBF9D19C555D7077EULL, 0x52462F01ABCF8846ULL, 
            0xB6CAF85AEA261797ULL, 0xAB6E62E76D995801ULL, 0x1F162B98753EF3C0ULL, 0x6E5D1F886BFA45A1ULL, 
            0xAFD5A738CC93E192ULL, 0xA37917F96745DB7AULL, 0xB88CCFAEB66AA074ULL, 0x5D16A3A066FF3DCDULL
        },
        {
            0xFD374D4A85430367ULL, 0x45C048A8C06AE7A1ULL, 0x50657B26785306ADULL, 0x654D3E82F6A5DB90ULL, 
            0xD8ACF5E69FBAB0BCULL, 0x83EFF5E3D6509182ULL, 0x308C988F33841278ULL, 0xB72D9E18709A67A8ULL, 
            0x59B89873F2507D9AULL, 0xB2D96051C1D971ACULL, 0xB43FC44225467949ULL, 0x6A5D1C07C0176223ULL, 
            0x36A38E11ECDFD427ULL, 0xC844C0C065FC7AABULL, 0x71DD7D7CAC22BF40ULL, 0xB28D37E892ECEE21ULL, 
            0x503BFFA0161E9033ULL, 0xACCDC93461B16099ULL, 0xDB86E70F83C9ECB8ULL, 0x4DBEA0E3487FFFDBULL, 
            0x34D5092B9BF2013AULL, 0x69F34ADA1EB4E7B0ULL, 0x88019EDF2B766E37ULL, 0xC02D3304FEB3E863ULL, 
            0x7318D0975C5B82C2ULL, 0x7ADB741D83E1795DULL, 0x9F35BD8831CD9FAFULL, 0x22D4A9DEF52C1596ULL, 
            0x6A464AF8F835D438ULL, 0x25D4CF886E6AF8F3ULL, 0xB1E6ABE518E792D0ULL, 0x5781301C33379354ULL
        },
        {
            0x12EAD61837FE1FE3ULL, 0xEC357F119B21DE3FULL, 0x7761F804C7B775A6ULL, 0xFCBCF0CDC96B6CF4ULL, 
            0x752BC1746A440B76ULL, 0xF8E31DF66AFF6C04ULL, 0xC9954F0053F487DDULL, 0x8F72C22CDFD28426ULL, 
            0x6FD9C8EB2697E69DULL, 0xAF2F0902CD372E44ULL, 0x760736C18A330E8DULL, 0x2688907D8ACD41A9ULL, 
            0xAA892E13D1766C12ULL, 0x86D828CC5884B7A8ULL, 0x41766035933A1031ULL, 0x828A0C3253BFFF0CULL, 
            0xE7C4CF6496C58D34ULL, 0x174EEF6CB4F06F3AULL, 0x53B28418E662229DULL, 0x13F0ECB9DC4AE347ULL, 
            0xD0C31599A0F4BE86ULL, 0xFDACB9D9CC84F9B9ULL, 0xCA8A5BD1F5A2A410ULL, 0xDA56B5B9DDCB26ECULL, 
            0x973B45D5D49D2E06ULL, 0x6A33792D09A77EC5ULL, 0x11BEFFCDF5618246ULL, 0x725406ED698C7810ULL, 
            0xC28841BF6AA6D16DULL, 0x0053D4D5B12C73B9ULL, 0x1240EB05EC4A563EULL, 0xB9C6AA582A4D9419ULL
        },
        {
            0xA3BBE06743853F80ULL, 0xBE09C6918063BD92ULL, 0xD3FD94221D23A1AAULL, 0xBEB018C8D9F3E5B4ULL, 
            0x33F9296B8F157968ULL, 0x8889FD76D5EFC804ULL, 0x43A765C79A600394ULL, 0x750559C51B34B605ULL, 
            0x4897EDFD1BC1F574ULL, 0x345C5AE3057156EEULL, 0x4AE29530EC5D6F2CULL, 0x5B0E80C52E24701BULL, 
            0x6752F3309FFDBAF9ULL, 0x01802CCF83498D87ULL, 0xCA20CA8BBD749C18ULL, 0xAE3AA7A0D1CE37BCULL, 
            0x8C0B86319FB4DE0CULL, 0x72F8887BC000C632ULL, 0x16F7F12903543702ULL, 0x516442D2346E2810ULL, 
            0x64FD966A64C9CD68ULL, 0x29C3B42324E51753ULL, 0xE7D954A4C63EDFE5ULL, 0xCA5752A49DAA9BA4ULL, 
            0x96EED1EF46106691ULL, 0xD8A1136B865BEAE7ULL, 0xC2BC979A82C0BFC5ULL, 0x97FEEE89929F6939ULL, 
            0xE46EFB7EA018B2E9ULL, 0x4D02AF67B50B73CEULL, 0xC00C5072D02EF8A7ULL, 0xB20AD2A32D126BF0ULL
        },
        {
            0x39E16BC39550B42EULL, 0x9D2602B204E17AFAULL, 0xC8682EA82F4BA966ULL, 0x3B005F3DD4C4C367ULL, 
            0xDBB195F4D00468DAULL, 0x4F6668E8A10D638DULL, 0xE796F353EE69DD79ULL, 0x7EF731A2E65BDE05ULL, 
            0x9FABB6E04D1AD2C8ULL, 0x0E990343418F098BULL, 0x7377FA56A1B9FFBAULL, 0xA38E0F932EF38B36ULL, 
            0xEECB9B8C53100F2DULL, 0x4D370BFE382DA1F4ULL, 0x2F44205B45F8DA95ULL, 0x97451A73A1BA1BE5ULL, 
            0xB05B9E3C95F0E63EULL, 0x2E07C4ED172C7D64ULL, 0x8FF3D0A960333329ULL, 0x6FAC56DA101AD3D2ULL, 
            0x29DD48E5FA939366ULL, 0x07CBBE62F84D0BA3ULL, 0xC4D6BBF0683AA0B5ULL, 0x8B6D999A49611A88ULL, 
            0x038A07133AD098E7ULL, 0x80376F4FD71AFCC1ULL, 0xB36DE617BBD8EFACULL, 0xA591C6827340F027ULL, 
            0x5E863092401B9D92ULL, 0x677A2270A3C09235ULL, 0x364C4AE4502FCDFBULL, 0xC042517E3EAE9B67ULL
        },
        {
            0x3CBB7B5BD6501144ULL, 0xC063D675BF37CBBAULL, 0x99A9EAEDBC2EA6F7ULL, 0xB86407E4F7366AEDULL, 
            0x6022CEF9CEC43B58ULL, 0x26F6415984BF6673ULL, 0xEB7D6BA643AF5C3EULL, 0x76D5EF249B4A7FE6ULL, 
            0x6ED68ABB41466DE7ULL, 0xA7545886BB945A41ULL, 0xB32BDD074E37FB38ULL, 0x9B882515AB4D6709ULL, 
            0xE2D4EC640036F736ULL, 0x82843A66688EABF3ULL, 0x645D474AF03B8A49ULL, 0x2515189238B120C8ULL, 
            0xC1EBD40287591EC4ULL, 0xCDDC4571E3909613ULL, 0x17124D9F9A9F4CD8ULL, 0x49FC0D618F8CD3F1ULL, 
            0x0BDD5805D924A2CFULL, 0xAAE07B59650364DEULL, 0xE9132B3C414C0DE0ULL, 0x5ED1F34E778AC30CULL, 
            0x73595AD55DE95FF5ULL, 0xA6B245801050026EULL, 0x57CC56701B5301B4ULL, 0x2D9057D3B7245C42ULL, 
            0xC395E69520231CCFULL, 0xD5A736BB98B508FCULL, 0x45B0A1C3C846A6C6ULL, 0x7F4BF4781A6BCC10ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alcor::kKeyRotateBConstants = {
    0xEF8B332B34345D2AULL,
    0x1B894758CA09B844ULL,
    0x0A42698FC85D4709ULL,
    0xEF8B332B34345D2AULL,
    0x1B894758CA09B844ULL,
    0x0A42698FC85D4709ULL,
    0x3CD59E5A3A8C268EULL,
    0x98C19305AED1A698ULL,
    0x32,
    0x83,
    0x45,
    0xB9,
    0x89,
    0xA9,
    0xBD,
    0xFE
};

const TwistDomainSaltSet TwistExpander_Alcor::kKeySpawnASalts = {
    {
        {
            0x0D40A82253B05051ULL, 0x26CE98C65D708A13ULL, 0xE6EB880B892FBF9CULL, 0x2C19EEE8AF8656D3ULL, 
            0xABA250C737602957ULL, 0xDCE784632B71FB0DULL, 0x2A13DB8EA955D4EDULL, 0x3D2F7845CA16B71BULL, 
            0x412D0D957A37856EULL, 0xAEC3E918911F81B8ULL, 0x89E6C9B06248235AULL, 0xA4B8CA3F39E4C087ULL, 
            0xDB410DA318D3FCBDULL, 0x92FF6BBA0D86BB59ULL, 0x6E54D1F9150B0A6AULL, 0x7DB39F11FEA628FEULL, 
            0xB26E31F2423D1CB4ULL, 0x0CFBE50D99308E29ULL, 0x7188F9404B0450F7ULL, 0xC5B75B6F0017F3BAULL, 
            0xEDB83C425860F81AULL, 0xB4ACD847D7444273ULL, 0xFD54E0C2D3E02F72ULL, 0x73E1025A88D03F22ULL, 
            0xB8FD4956FC8F0ABBULL, 0x13694012C8B923CCULL, 0x92B9070F6893F309ULL, 0xEE10E87E3BBCCD8CULL, 
            0xFF42DF2BB9670EFCULL, 0x7FCD1964A6B27C7FULL, 0x1DEE2F1EACAE0F04ULL, 0xF84788F9FBF7E047ULL
        },
        {
            0xC1FBA7F35948942FULL, 0x1D635ACAE7A1EEDAULL, 0xEC8B9BE9EE29B986ULL, 0x28C0BA3118847830ULL, 
            0xD84280BF698AE333ULL, 0x10DD804BD29EA973ULL, 0x43A74C72669F4ADBULL, 0x475B8FD46488BE24ULL, 
            0x1D50B9E17FDFC7E7ULL, 0x1BB054EDCC97ED5BULL, 0xD448C25ADDB1929BULL, 0xE888F7792A539B6CULL, 
            0x80EDE32D03EF2B8CULL, 0x3AD5188AA0269C2CULL, 0xC8D90953EAF7FCA5ULL, 0x11540AAEF2E71398ULL, 
            0x13BB55B8C9BD3200ULL, 0xE1A03DD1DCB2DB75ULL, 0xB436335AC6D51B06ULL, 0xE7F8C24AC86933E6ULL, 
            0x871346D38D5F284DULL, 0x13812CD84E87B90FULL, 0x8DFB1CF57827EF9EULL, 0xB517FC1CBCF0D640ULL, 
            0x530FDBF1B7AECAB7ULL, 0x2FE01E386D7A1B8FULL, 0xFFB790EC7F0C2BB9ULL, 0xEB76862DC3621D19ULL, 
            0xF4400F441E79C603ULL, 0x75F460A3A9EE19BBULL, 0x09B633022AF23C00ULL, 0x0E2A086504DE42CCULL
        },
        {
            0x2A7422D4855D8FFCULL, 0x5550A9B00DBEC704ULL, 0x18F0022B0D5B3829ULL, 0xD2FB1D946B821A0BULL, 
            0x4DD142F31FE1A079ULL, 0x22AC20EF747A96BBULL, 0x7E41812E509506ECULL, 0x9D3062EFDEA700E2ULL, 
            0x2EF4C0515336607CULL, 0x4B1E655DC7CDDFBAULL, 0x3C20F40C5A9A7C68ULL, 0x1234445BC52EC635ULL, 
            0x251F3CD1D91E2E00ULL, 0xF93FDAF08295027FULL, 0x9597239775D33CEDULL, 0xC7ED5344EFB73332ULL, 
            0x14789CC668ACA4D0ULL, 0x2ACBCB5DB5E59B01ULL, 0x6762F73FE3DAC829ULL, 0xB2407754700AAC26ULL, 
            0x7CC181B971FAC974ULL, 0xEB06811E349C3AA2ULL, 0x6041A624FA74CBF9ULL, 0x225908449E819B91ULL, 
            0xDE39069740AB12EDULL, 0x8766A1A28D3FC99FULL, 0x54DB73C34E90A830ULL, 0x7C1876806662EAF8ULL, 
            0x246F799738E8E276ULL, 0x6D5B1A661016A76DULL, 0x1CE1A6DC1FEF8556ULL, 0xB2F5C859D6AB1E09ULL
        },
        {
            0x1EC4A7CF680519B9ULL, 0x9FB6239F6689F92BULL, 0x79916B174B36BC9EULL, 0xDB6F54D49114A811ULL, 
            0x4B5D608774F35D6AULL, 0x3EEBE842C1FE8CBEULL, 0xCBC40A75B64ABE2BULL, 0xAA2ACE1055A03D54ULL, 
            0xF1860F03BDDB34D6ULL, 0x130762844A311597ULL, 0x0E6F3934D1B382B9ULL, 0xEA81A9EFE6ADFFB6ULL, 
            0x66AA474AE56636C6ULL, 0xBB805ACAAD1515F2ULL, 0x958697005627C09BULL, 0x51DCA7E7DA58C870ULL, 
            0x27589503EFCEBE3DULL, 0x8077690510E39356ULL, 0x7D707A0830650223ULL, 0xD3573971402E0847ULL, 
            0x5F9B4C2DFDDE7D1CULL, 0x6FB43804AD8D956AULL, 0xB0572AA7FF73F484ULL, 0x129F28171A26E5C4ULL, 
            0x0018068FAA18A32DULL, 0xFF717AE1EE90F610ULL, 0xCE77A5018F916097ULL, 0x66F5D182D562D85BULL, 
            0xBE0E685E8437D19BULL, 0xFA6E272BA13F83C0ULL, 0x5E45198DA944E417ULL, 0x5FDCB4DC7AD65213ULL
        },
        {
            0xA649C07CB0815CA7ULL, 0x07D7E27FD3A6F073ULL, 0xA857FCB98AC5CE83ULL, 0x3487F25685FD2E17ULL, 
            0xAFF62FCE5184B5BDULL, 0x7CC99352C70185FFULL, 0x1DB6D624F3D9F5A9ULL, 0x7879C8D5F9FF1C3DULL, 
            0xE471BEF76933E3F8ULL, 0x0BDC95008FF0D9B3ULL, 0x23EA56E4AD14B37EULL, 0x6717329DC25AB3AEULL, 
            0xE0083D1529AC6AD9ULL, 0x4F670CCD5AF76F1DULL, 0x64EF074B465765B7ULL, 0x06E9CDA51CEC2DC5ULL, 
            0xF4E785554F70B405ULL, 0x561F18B745D407A6ULL, 0x95E5ECA6880179A2ULL, 0x2F9C8918185E57A9ULL, 
            0xDEE35F303F4FA10CULL, 0x9D2ECA5DDAB5D1C5ULL, 0x9F36DE207F15A176ULL, 0x26706F3A58451490ULL, 
            0xA0B0157BE71C299CULL, 0xC255F327A1A5CD03ULL, 0x572CAE3E09C595E3ULL, 0x826DB83B3C94D530ULL, 
            0xAB28C1F9FF6E3E96ULL, 0x853FD25335EB6542ULL, 0x1423A4DA8F755A21ULL, 0x56200AE0133A66CCULL
        },
        {
            0xC67F1C2CB433299EULL, 0xEBB401FD2B94A9EBULL, 0xAC24681B272FF6ACULL, 0xFB0B76D3A46BC4FEULL, 
            0x4394B2981EAFAC59ULL, 0x7A8DF0562791ECF6ULL, 0xF09550C33A7F0EF8ULL, 0xCDF9AC550504E62EULL, 
            0x6C58301BC5EBCB15ULL, 0x4E40C2B5552FBCD0ULL, 0xE0B57954A302258EULL, 0x2F3FBC9776AD95E7ULL, 
            0xEBEA4B6CE30CAD4CULL, 0x28584B599B61B87FULL, 0xDEA9B759C1680E5AULL, 0x1BEA5B1F963CCEC5ULL, 
            0x9863BA7E460B7D46ULL, 0x459ADA54B9AEBFD6ULL, 0xD2E153077EF44482ULL, 0x9CF62478CA8E8694ULL, 
            0x2ECC0694E3774CC4ULL, 0xE7BC3291DE70F6E2ULL, 0xBD615BEE8370EA6BULL, 0xAD3632ECCC97DEF7ULL, 
            0xF117603A06880349ULL, 0x43687FC8570F7EECULL, 0x8A53E48F6FD56EC3ULL, 0x4382D45E3B5551C8ULL, 
            0x2EA3FD03F715CAF1ULL, 0x690F635D8BC6927FULL, 0x1F33A5214DB14510ULL, 0xFB12E5922CB02625ULL
        }
    },
    {
        {
            0x5C540CEC47540663ULL, 0xC73721264E1698E7ULL, 0x24DAD712A0E7FE55ULL, 0x083AEF0B8F8761D0ULL, 
            0xEC4BAD7929A737F1ULL, 0xB4893089B90745CDULL, 0x4A28F3BD7B3E72ABULL, 0x57D8652655727F91ULL, 
            0xBD14A5697C4B4296ULL, 0xD5009D99E0CC65A9ULL, 0x9969348698B33DC4ULL, 0x7F16141884184451ULL, 
            0x4C8B3DB630B5F7AAULL, 0x22CBA2369F03225DULL, 0x2BE581F54340FD9FULL, 0x69CA02D7FA511241ULL, 
            0xA9A2430FBD1B030FULL, 0x9F8B61FBD48EE79BULL, 0xFC27AF06E4AF9582ULL, 0x3CB507B7BFB15E58ULL, 
            0x4F29744815C5D32CULL, 0xEC7632154A515A0DULL, 0xE815AE686792B788ULL, 0xEFD63148807A164FULL, 
            0x12C76D0A0464E73CULL, 0xE21C954BBF79B39EULL, 0x7A5836647B44B589ULL, 0x8C613BC4DFEAA48CULL, 
            0x8DBF183514402AA5ULL, 0xD5BF62C7F2CCED83ULL, 0x875039170A691E15ULL, 0xD1A43E417A2070F5ULL
        },
        {
            0x75C8C624C328AD47ULL, 0x60186B778115C8F6ULL, 0xE3C933F17DAA636BULL, 0x04F10A9DC94168A3ULL, 
            0x86E2A18F9BEDEC3AULL, 0x61F59805ADE0EB62ULL, 0x3EBCFF67011FF188ULL, 0xD0E3E465BE49AA90ULL, 
            0x8A0842BB550569EBULL, 0x89B578809D07DC40ULL, 0xA0EA86455A807188ULL, 0x182F7FB4F2D1D22CULL, 
            0x10811319BE344238ULL, 0xB16FA4D5628BEE52ULL, 0x8D432A5216A92F65ULL, 0x1F07298922331E59ULL, 
            0x65B55C12707D546FULL, 0xE44254128B47CDEBULL, 0x9FCAFA02C178CB65ULL, 0x6D4947EF132A9C7EULL, 
            0x050621EE90C51DB4ULL, 0x17DF3862F6B4AF0EULL, 0xE64527FEA7AC10FDULL, 0xD435F6632AD5D7CFULL, 
            0xCB7E35BDCAEF76AEULL, 0xD596D003C346C476ULL, 0x83A8C4C64FBC30CAULL, 0xE9E23741D856B556ULL, 
            0x7B4E02B2DAFF22BDULL, 0xCB157CD4775AC1A2ULL, 0xC862004D32332494ULL, 0x068443A2FDA4B1E7ULL
        },
        {
            0xBB928B75ACC685EFULL, 0x764E1452F1120FF6ULL, 0x0ED1AC786980CCBEULL, 0x10FABB86AE0D4840ULL, 
            0x615FEFE8DC84C1A3ULL, 0xFB01960E62A05983ULL, 0x710C266E10617E9AULL, 0x68C5D6220469FFAFULL, 
            0x088D1FC903C14FA9ULL, 0x88B6352051A88623ULL, 0x681F524DABDAAD32ULL, 0x0650D6FDF72E3249ULL, 
            0x35A0AFD2EB98F026ULL, 0xEAB279C0FA1A6AE8ULL, 0x281A81881C344DB5ULL, 0x9B2C47B7EEA6C02CULL, 
            0xEB4C9912970694F3ULL, 0x63F63648ED1A1838ULL, 0xED40BDAFC4CA7BC9ULL, 0xA84EF32D57C16B9CULL, 
            0x5845872D051D6E55ULL, 0xD34E94E13B3F1F88ULL, 0x6EA188876C3E9E19ULL, 0x68F03799DB53EAFEULL, 
            0xD6D31F9D7A43261FULL, 0x85568D9CB24CCE56ULL, 0x84BC73F65C256250ULL, 0xD74C850DCAF74122ULL, 
            0x820647A225CE0ED9ULL, 0x40D3D25762A49AF1ULL, 0xD400F4691D002809ULL, 0x4EA150B83DF3FB8FULL
        },
        {
            0xB49742462E4AE84DULL, 0x9F9FD1B775928AA1ULL, 0xEAF33EBEA21B76FBULL, 0x787B08DDA0BBB6C3ULL, 
            0x8D4E9ECDF4FD0B15ULL, 0x633974ED969D6140ULL, 0x49BF06CC3CF3BD20ULL, 0x8568CC498A723627ULL, 
            0x876885933ACE4692ULL, 0x1BB6D5987FC15DDFULL, 0x9A0180B49E339104ULL, 0x95E4E53DD02A870EULL, 
            0xA160E3F8907AD68BULL, 0x26104ABE4F7596F0ULL, 0x85883E5A6C39C955ULL, 0x8B70E278F02BA62AULL, 
            0x2044BCC0734861C9ULL, 0x1F30AB6FD47CFF11ULL, 0x5DF488CBE3347CCCULL, 0x2EAB3B3F0A2B8C65ULL, 
            0x60E525B8B01E1DD2ULL, 0x4ABCB6D4D37CDBAFULL, 0xB27BC9DF8C58A6AEULL, 0x0DA8B48B2A723E70ULL, 
            0x447861E8D8351B82ULL, 0x29BD79818B8FF63BULL, 0xDAB904B7C1D45131ULL, 0xD98B6A2A3121C7BCULL, 
            0x734D63B91BCE699BULL, 0x37F2261BF3917110ULL, 0x4B1B7C34F42B8AFCULL, 0xD90C94964841AB72ULL
        },
        {
            0xAEEBAF6DF9BA0ED9ULL, 0x533F778466A376E1ULL, 0xFE6AA49E6DDA1CA7ULL, 0x0C645FE81EA5E09BULL, 
            0x9B2ED39AAE93E8CEULL, 0x68501C8AB0C531E7ULL, 0x651819683717B310ULL, 0x6EFF3FC5AC6E9693ULL, 
            0x61B54F02E5CF47FCULL, 0xF8E8F357CF509CCEULL, 0x447687D7E08BFDBFULL, 0xB5CDF9DFED38BE69ULL, 
            0xDBD9E2D2FED6DA81ULL, 0x1AEE397DA0B10446ULL, 0xD437CBC417E33624ULL, 0xE77E38D78D2E4BEBULL, 
            0x5C0E51F8FE943079ULL, 0x9051C7E4C41F624AULL, 0xEC869D6E1772D87BULL, 0x197B8DA028A49D52ULL, 
            0xE5110410CD087930ULL, 0x249F63FF3977FDC0ULL, 0xA232A30F4E3BA921ULL, 0xBCB2161FDA342FD7ULL, 
            0x2B367549B84BC5FAULL, 0x91AF530C6BEA6119ULL, 0x76CE3C8AD506A31EULL, 0xBC1ACB404E897898ULL, 
            0x4DE0F1CF96A03FB5ULL, 0xBA11E50566DBE1B4ULL, 0xD07816909FF773D6ULL, 0x6DF8A421F3B43C0BULL
        },
        {
            0x2B8693567A3C60CAULL, 0x6C96BB5D63E4333CULL, 0x6D69955E9BC46ED5ULL, 0xCC1070B385D65254ULL, 
            0xEE2815EF186BE1E6ULL, 0xD73A425E1ED03574ULL, 0xD4E8AB761EC95998ULL, 0x272EEB57EDA28682ULL, 
            0x2773FFED82528D64ULL, 0x8425259761051965ULL, 0x95F7F0C9D2D470DEULL, 0x607D13E3C624760EULL, 
            0xBF35965BD31D3BF2ULL, 0x651B9C60132A366FULL, 0x248BD9AFB8D2CAA7ULL, 0x4020E3D26CD3F78DULL, 
            0xD6E9A04EE4530E96ULL, 0x16EF43AD6AE5FAE3ULL, 0xC9D09AA3EC30D6B2ULL, 0x10D8677067B4F0F6ULL, 
            0x6D8815DAE260EF0AULL, 0x66B7AF8322DE6B3DULL, 0x12C8AED7EAB69193ULL, 0xB236D773A516F480ULL, 
            0x112545562CF6C15DULL, 0x973F44F966B5B871ULL, 0x862CC16315FF33A6ULL, 0x9A1A639C63F1E589ULL, 
            0x1860883C8185F85EULL, 0x409D430D2ACFF564ULL, 0x3841C5627A188D6EULL, 0x2B9C1B09ED316075ULL
        }
    },
    {
        {
            0xF20466A62F3C7467ULL, 0x486869EF84C46558ULL, 0x2C7E03BB17CE224BULL, 0x22471F067B9CBF84ULL, 
            0xEE6F771808EB19EBULL, 0x6BE0369DC0997982ULL, 0x57E310BE74C0F493ULL, 0x0F8B9F9BFE8B741FULL, 
            0xFFC2758387A19E26ULL, 0x7260762E1D4F5156ULL, 0x855DCDB0AEAE9958ULL, 0xE6EFAE2BBF29B23CULL, 
            0xE6A3CCB4045C5C00ULL, 0x7DF3F6D79FE5D6C4ULL, 0x8F46BF37291D5CF7ULL, 0x14067CD3DAF1012CULL, 
            0x1261F03710D96B3FULL, 0x127060B3F91B302DULL, 0xF25AED8615A1F0E6ULL, 0x5B81AF5AAD66ABEEULL, 
            0x0F96486955D5B45DULL, 0x6703A9BDE69A0122ULL, 0x2CD124368E7DEFF5ULL, 0x7EC1D8D00CDA52ADULL, 
            0xAC2C047923EEA6C5ULL, 0x585994EEC33A7B5AULL, 0x3488E27F3E55F43EULL, 0x2F616B2616ACED77ULL, 
            0x98D33E40A3AFB4F8ULL, 0xDABD5427175A8157ULL, 0xF07DE7E2E88B311CULL, 0x43984883E3BFD1C2ULL
        },
        {
            0xCB7F138E4C438F8CULL, 0x0ECD30D6EC0162C7ULL, 0x8C968361A9705240ULL, 0x0A1710D26710EB96ULL, 
            0xC596F8A2381CC708ULL, 0xAEB1DB64C0229793ULL, 0x4D44B64EC2B7AF57ULL, 0x89FB64F45C7DDE7EULL, 
            0xCE3C14E29E8EFA9AULL, 0x7F7DA0F79C18D692ULL, 0xE978C3207498F118ULL, 0x6016D33CA75A3315ULL, 
            0xEF73123E3BB6340CULL, 0x6DD77C8DF64E9A21ULL, 0x94B52CB39FE811F6ULL, 0x7090942E76EB286FULL, 
            0x53E6D47A9960653BULL, 0x04CE02874CDA4885ULL, 0x2E55E136DA773A32ULL, 0x1B0130FA912D3B46ULL, 
            0x960688806BF0E8C3ULL, 0x7E7CC790FE4476BFULL, 0xCB5B48D480CA31CFULL, 0x82AA399D00B5BBE7ULL, 
            0x97521458162F7223ULL, 0x3DB85F00A945C65FULL, 0xC2D5B3BA6B3806AEULL, 0xE58E39E98CBA0E44ULL, 
            0x68FF21ACC8E47CC1ULL, 0xC19D6A92054364E2ULL, 0x1704625E6CCF9806ULL, 0x2F38A99135E804BBULL
        },
        {
            0x39D73160A5EDEA28ULL, 0xF338B88F4D1B0E6BULL, 0xD8E138A90B0504D4ULL, 0x547BC23BDA4B626FULL, 
            0x2DA13F85BCFC343BULL, 0x8ECE3F3516860FEDULL, 0x812EADA54176F4D2ULL, 0x6B487826C7AD9F18ULL, 
            0x43508EAA235E85F6ULL, 0xC989E4A92885C530ULL, 0x4A394D3DDB7F4CE0ULL, 0xF6C6BD365743C979ULL, 
            0x726430483DC523BAULL, 0x1854F1C5F9FD4EFEULL, 0xF030C21C02540054ULL, 0x5FB0B440DD00E5D7ULL, 
            0x2DFC70CA0DFCCED5ULL, 0x5B7CA74185936842ULL, 0x652A0FD8E42C43E7ULL, 0x311A7501780697A9ULL, 
            0x72A42656ED85F2DDULL, 0x8E342541A5000E83ULL, 0x00E42FBFB8567612ULL, 0x11437A18CBCE9FEBULL, 
            0xDE83F5EDD6512C3CULL, 0xDA6ABDD88C355256ULL, 0xD27056C1F196399CULL, 0xA4A1F6BD8880166BULL, 
            0xC28C95BC43D39A14ULL, 0x8C78B637C44FA3A6ULL, 0x0E0B4547D4E016CEULL, 0x10747D5542C51440ULL
        },
        {
            0x8D2182AE80DE7579ULL, 0xFF84002C011F110AULL, 0xE2673A27A742329FULL, 0x0DF916E83C7724D6ULL, 
            0x6B01D1546897DB51ULL, 0x6DEAA3BE442BD252ULL, 0x5D360D72FB2957FEULL, 0x6E2BC32F6E70361DULL, 
            0x488E36097AD2D012ULL, 0xC6F1A2B369A5AB71ULL, 0x26B6F3B329FC41B2ULL, 0x2FA8983A1E554223ULL, 
            0xCE6063DD1EE54EA4ULL, 0x80D60F84FE1578CCULL, 0x573039CD6B62EFBFULL, 0x2D2D3805B4921761ULL, 
            0x355D2F5526AD75D5ULL, 0x7FB79266222B74E3ULL, 0xF241B492EE97A285ULL, 0x65D57AFB5A45B653ULL, 
            0x34E1A7F900D22C6DULL, 0x4963B3FFFC41E355ULL, 0x8FFE9BACBB74DC39ULL, 0x30ACBAC6CA66E246ULL, 
            0x3D592CAB5846AD26ULL, 0x78717492448D0AAAULL, 0x7FB934C12EAC8C15ULL, 0x0C8ACEC11454C256ULL, 
            0x2C8324CAE388B681ULL, 0x6A752CD54973AEDDULL, 0x262EA2680E31F830ULL, 0x3843C95C24DE1761ULL
        },
        {
            0x635E6A1FEBAFA456ULL, 0x4AC2CFFE71B58F40ULL, 0xC77F1DB631205309ULL, 0xD25984841628B03EULL, 
            0x949F236109253806ULL, 0xFE4B0D574A3AE0DCULL, 0x908F1E72ADB566E0ULL, 0x42188885179EA593ULL, 
            0xB5B3E6EF96B18BAFULL, 0x9A1BF092E7A3A2ACULL, 0x4A64D369FF515334ULL, 0x875F42BF10164019ULL, 
            0x34CF4040D505E489ULL, 0xA51FC06C3F827783ULL, 0x40206429C6C2ACF7ULL, 0x10CA175EFBB740A4ULL, 
            0x05CFFF8E8008086CULL, 0xD63AFD5D8577587BULL, 0x90629FFB8541EDE1ULL, 0x6E7AE429DAA646E8ULL, 
            0x9518F9D2DBE13A76ULL, 0x258D42C7DBFB70DCULL, 0xA8C90180A4CD9A62ULL, 0xEB901DFF84EF0BDBULL, 
            0xAC2CDF520BA72EB8ULL, 0x6F90E69E23BA981CULL, 0x152F8717A50D5170ULL, 0x7611155758F38D9EULL, 
            0x4DD014D5B9F89A97ULL, 0xF7BCB2E398FA5125ULL, 0xE25A02B77DA43606ULL, 0x296EEB3731F279A0ULL
        },
        {
            0xE4F12B37B1034017ULL, 0x4F0EA5CBD2CA909AULL, 0xADEEFDADD7BA1792ULL, 0xF7B241090AAA42A0ULL, 
            0x749E5F82CD08DAF3ULL, 0xB0F79F4D2D2CE829ULL, 0xE27BDDE114CB2CEEULL, 0xD8AF19FCF77F89B0ULL, 
            0x64EFA15ABF97117AULL, 0x0AEBD91391DB9CADULL, 0x77530CBCBBCB884CULL, 0xD01664D6769A0137ULL, 
            0xB096C980E510D196ULL, 0xD57D31B788F41076ULL, 0xAC6BDE652215EB33ULL, 0xA6A96C8F11A39B50ULL, 
            0x1FDB4A3B9AFD7E2CULL, 0xAE0630D858C82DE9ULL, 0x07C9DF4522895E37ULL, 0x55A11EBF05AEB0A8ULL, 
            0x2B27D29A0CC0151EULL, 0xBBCBBCD1E6BD4665ULL, 0xECC323B57E191062ULL, 0x988B187D66113BEBULL, 
            0xE3B868BE112D9B9BULL, 0x964EB3B9857A9086ULL, 0x6EF16BC563331413ULL, 0x6CD63A13E0656873ULL, 
            0x7764F586507057E8ULL, 0xA824927E6F128354ULL, 0xC2AF45F6524AC4B8ULL, 0x01A40336E9AB1DA6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alcor::kKeySpawnAConstants = {
    0xA2BE370906D09FE3ULL,
    0x99CE9152DFAF83BAULL,
    0x9F55E1E0446C2F26ULL,
    0xA2BE370906D09FE3ULL,
    0x99CE9152DFAF83BAULL,
    0x9F55E1E0446C2F26ULL,
    0x014898E8CAFCC3F1ULL,
    0x84C5579B863C719AULL,
    0xA8,
    0xE0,
    0x7E,
    0x3F,
    0xD8,
    0x60,
    0xA2,
    0xBE
};

const TwistDomainSaltSet TwistExpander_Alcor::kKeySpawnBSalts = {
    {
        {
            0xE7B7752DB1CAC582ULL, 0x6D26D5C7E6EB8F64ULL, 0xD260AA18B9445717ULL, 0xD11449C5ADAD9629ULL, 
            0x90EB9EAF6E3C873FULL, 0xCC48BA6B48A12AC6ULL, 0xB1E6649CE94207F9ULL, 0xA59015174F2E702BULL, 
            0x7B77768080463980ULL, 0xF500E81E9EA03FE4ULL, 0x048A24BA70CA1271ULL, 0x4380D624D1B00219ULL, 
            0x1B553A56A58A09ABULL, 0x3CE9A456B89D1721ULL, 0x17D610FAEC595E1DULL, 0xF2CA2FFBE395AF59ULL, 
            0xACFB80A2F2CF2A4EULL, 0xA9C8EB01CF8AA0A6ULL, 0x7AFF3B22B8E1DC15ULL, 0xB6A297024A273E38ULL, 
            0x699DA89FDEBFB14EULL, 0xE4EEF279946965FEULL, 0x9B68A728F653913FULL, 0x929F585A7A3ACA8EULL, 
            0x7817B12F9FA18922ULL, 0x45793A0CCEE116ABULL, 0x75FB1B4AB8084F7CULL, 0x4BD2E1FD85DB1122ULL, 
            0x0BECAC103EE6FDB5ULL, 0x049C7059511A0C69ULL, 0xD629AD925A487EBBULL, 0xAE07C578DAC8C730ULL
        },
        {
            0x2C595C9E58043CB0ULL, 0x62E60846C0406CC2ULL, 0xC65A8435A8EDCC41ULL, 0x2887C6855BD6C527ULL, 
            0x814E48FEF94DA712ULL, 0xB578E97CE7D15DAEULL, 0x6B5C63DAD1B4196EULL, 0xC76EC5DD67030EEAULL, 
            0xB666183323241082ULL, 0xCEDB7E22D560B5CAULL, 0x0A0AD17BE6E49416ULL, 0xFCF52A897F5A8921ULL, 
            0xFAF5ABD86F6E8465ULL, 0x7F8CD4F57F4AB5D7ULL, 0xD8A3C634E7F2FDBEULL, 0x80EFFCC86BAD0F25ULL, 
            0xD0807400C84886F2ULL, 0x90C5ED0171CD161BULL, 0xD823B5484E580D1DULL, 0xAF678CC7AEDB869AULL, 
            0xADE0221F7D30E7CBULL, 0x40C1215D95D3FC90ULL, 0x178EEDEC7B13FD39ULL, 0x6AFDE234557BD7B8ULL, 
            0x4BFBACE7340124CBULL, 0x172FC35A0AC1EAB8ULL, 0xEF29EEF3A757C390ULL, 0x3E4D421609925D23ULL, 
            0x043C375E125046AFULL, 0x5A4DCD5EBE95F029ULL, 0xA7D8D770DC7F3FEDULL, 0xDD0FE4F61D26BF8CULL
        },
        {
            0x042425496F3AEE96ULL, 0xEDEB02920CD095B3ULL, 0x3A2F5915ED79DF45ULL, 0x235F43421A9C1CCAULL, 
            0x40D8F9C76DF23CA7ULL, 0x108741A1D1290100ULL, 0x6BAD585C7D089AC3ULL, 0xD8A884FAC9E293FCULL, 
            0xCB965C94488E691EULL, 0x0518D1A520B8125BULL, 0x17FA6DC5A4D7AD2AULL, 0x9E52EE6441B1948FULL, 
            0xA4D0016F811935C6ULL, 0x811032F79953CEE9ULL, 0xEE3E5C37269F9C4DULL, 0x9D9F2F2B5102EFF4ULL, 
            0xEBB4FBCF8D489364ULL, 0xCDB970689AA3F9B8ULL, 0xCE63263ED2B584A5ULL, 0x6ADFEDC6EA668274ULL, 
            0x02E05D6DA736D084ULL, 0xFF1ADD5CCF2FCE37ULL, 0xF0E23CF3FE5865E7ULL, 0x9A7349E58518966DULL, 
            0xB939AEC8E2986B11ULL, 0x2986CBCC1CF90A4AULL, 0x00A28AAEF7B71742ULL, 0x8EA518898541123DULL, 
            0x2CC4D6D029028DA7ULL, 0x157AD85271A9F6D7ULL, 0x9B76C52694BB7B95ULL, 0x3FB5B77C39ACD058ULL
        },
        {
            0x772DA7B4103660B4ULL, 0xD09577877292FF74ULL, 0xA4312D6E7641C8A4ULL, 0x2820FF9DD280900BULL, 
            0x2EBE4ED112407511ULL, 0x12B9EB07625F2608ULL, 0x16B0F7D47DAF54B4ULL, 0xC83265281C9D0960ULL, 
            0x7F16E9777F7F3BA5ULL, 0x05AEFE5260583140ULL, 0xC3F0480EF5FAFE7CULL, 0xFF3B62AACE852A27ULL, 
            0x68E9349931E7B965ULL, 0x4BF9479151F974A0ULL, 0x2654DF054BF603ABULL, 0x246D32FAB7E4521EULL, 
            0x182E26672748880AULL, 0xA863EF88D8E96119ULL, 0xC6BE9846D6E5FEB5ULL, 0x8A23C2EB7195D25FULL, 
            0xA706E9F07F7DD54DULL, 0xFFBE950227D1D3E7ULL, 0xB9BB5709269587C2ULL, 0xD8AB5AFD66ACAEF6ULL, 
            0xD7FAAA508028A779ULL, 0x2ED83A8EC860578BULL, 0x72E67C8246F068AFULL, 0x87830E83339B72F6ULL, 
            0x2CB794386EEB56D2ULL, 0x0198470747D260B7ULL, 0x7B6518EBE84B6231ULL, 0x0933CDDFE02A0C98ULL
        },
        {
            0x2A7A37E6ECA48FA8ULL, 0xF0DDF0FE68A1DC74ULL, 0xF5E622E2BAFC4909ULL, 0x9C050AE806A23725ULL, 
            0x965C780E9EEAC3D2ULL, 0xCE023E6AF5F980D3ULL, 0x7DD089B8070C1F83ULL, 0x3B986BE6C0CC646CULL, 
            0x566D4B68B8284144ULL, 0xC28DA6C4652F3D85ULL, 0x33E0559C31B1832BULL, 0xA6788386D026BFF7ULL, 
            0x7FF5A6F9CEA0C452ULL, 0xE47F19AD3376DC57ULL, 0x867A275AF44CD936ULL, 0xA57CEBBF11B330C4ULL, 
            0x8C274E6026A693DFULL, 0xE746D181F9F35E5FULL, 0x3842365B138E8246ULL, 0x0F19E40C1349F05CULL, 
            0xF01B86ADA26ADCA1ULL, 0x4EF5D20398228F24ULL, 0x051EC2598C10E303ULL, 0x45AD9263B65E11F8ULL, 
            0x9C3AAF50D1681F93ULL, 0x6F0A450EF5F8DDFDULL, 0x29D43FD91011D1F7ULL, 0xA32CE5EFFC5FC22FULL, 
            0xB21F1147AC654C81ULL, 0x1EBDE1328FB903FFULL, 0xBF997724B9D30615ULL, 0xBDE91CCD8459A049ULL
        },
        {
            0x59EF085662E81456ULL, 0xF35C42AA9D450A9BULL, 0xE8CACBEE051012AEULL, 0x0FFC50F7F417DF0EULL, 
            0x31DFC6C13CE635CFULL, 0xA2DFEA6182ED1C66ULL, 0x303E6DDC56874C42ULL, 0x33D041B9B872935BULL, 
            0x7F8AB7034CA52278ULL, 0xD241E7CF4D764643ULL, 0x42BB75E08D8D13EEULL, 0xF92DF00998CA0345ULL, 
            0x8AF06341676F492FULL, 0xDA035FF9CA23EE17ULL, 0x7C5CDBADD780A1BEULL, 0x7A4B280EF1D995DCULL, 
            0x1BC44DDB901FDDF7ULL, 0x17A34B51AE1DBE26ULL, 0x3C5CBDA2D51B7A8FULL, 0x2638D83D341DD4B6ULL, 
            0x30047C0F426E4AA4ULL, 0x5629DF0FE4E2A245ULL, 0x26845CA04DB03B44ULL, 0xD0B1A9D452411088ULL, 
            0x30CA37D50B6F529CULL, 0xFB605938CF412E68ULL, 0xB61B6231109FA928ULL, 0x7412340C33699711ULL, 
            0x2382AC6E452FDD8AULL, 0xA4F7901E1D36D425ULL, 0xE24649F42ADB1445ULL, 0x1B93AC75CE239129ULL
        }
    },
    {
        {
            0xE22D85DA4041A9B4ULL, 0xE4AB1119546D0FE4ULL, 0x3DE9D6D73743482BULL, 0xEE928C2F733F5029ULL, 
            0xFFAE84DE6D2684E0ULL, 0x764831917FC2D8ECULL, 0xE9119FA5CE49CC5AULL, 0xDA036F1A7E4468D3ULL, 
            0x19E884CA0AAECF24ULL, 0x7B801DDD1EE8AF54ULL, 0xD3D8415D06C6186CULL, 0xA9E823ED2A96A14CULL, 
            0x84C097232732B4D5ULL, 0x4A4128E84DB76924ULL, 0x3ED95E231D7908C7ULL, 0x33D72D4A70338749ULL, 
            0xE72A50E6D7AB2879ULL, 0x755C1CE1C52F8BFFULL, 0xB45532933FE35F4CULL, 0xFACA4B751D46D93AULL, 
            0x28325681A2269DD7ULL, 0x39A1FA28103A4ED1ULL, 0x0D3E70D583B8E14EULL, 0xEADE905CDA243FD4ULL, 
            0x91F2448B170F5A8CULL, 0x360F1E7641BCDE9CULL, 0xEF918AD2B9F1F635ULL, 0x2D3E0AF832C9B3E6ULL, 
            0x2407788085CFED5FULL, 0xE8A9DC11CB55A298ULL, 0xD1BA51D01F6BC2D6ULL, 0xF061667BE57874B1ULL
        },
        {
            0x13B4CDD9E42C62EEULL, 0xF8796276B245F8C4ULL, 0x0E90D2374CFEB1D7ULL, 0x2F406BCEBAA57D92ULL, 
            0x3C09E8A4862A2AD4ULL, 0xB7FE08B70F7371B0ULL, 0x84E3D856D11549D5ULL, 0x36DFD7E3886E44B7ULL, 
            0x66D3995ABF6EE8D7ULL, 0xDD81E3647FB65721ULL, 0x72013DFF857C5DCAULL, 0x8A9AE7C06B3FD084ULL, 
            0xB2B433F67B027DA3ULL, 0x5D2A951B72478509ULL, 0xC80801CBDE1A35FAULL, 0x497035ED1CAA44D7ULL, 
            0x9001EE5C0E831001ULL, 0x6171B37945D698ACULL, 0x64946F03831BCDA0ULL, 0x970D3F37BD55E27DULL, 
            0xB19BCF6D0E4E6794ULL, 0xF9428FB11B2F4B93ULL, 0x1D9C50CF4856F615ULL, 0x6103460125B603D9ULL, 
            0x7450221EE5E8C0F3ULL, 0xFD675D4E73E8A686ULL, 0x15666327BD80F427ULL, 0x94C4C89E087E6995ULL, 
            0x927D6AB02E12924FULL, 0x94325C9428F28DB6ULL, 0xA136FF4B0D68350AULL, 0x04F96412B313E9B4ULL
        },
        {
            0x913DAFE459AAEC8AULL, 0xDDD88C272A4083F1ULL, 0xC2E67E43328F099EULL, 0x3A3BB58F71493FDFULL, 
            0x8E17F0467F93590CULL, 0xF0E0D02F5085A7B9ULL, 0x0C1568B98DF2C5D8ULL, 0x3B3E0EEF8FB9FC3DULL, 
            0x404C2C7D25EBBDA3ULL, 0xA486E32E99924131ULL, 0xB00820DD785560FEULL, 0xF96158E51DB5535CULL, 
            0x0308F738F8999C23ULL, 0x0BEEEA4CD12B89B8ULL, 0xF32F7465FBB75F45ULL, 0x9CD83618B795D64DULL, 
            0x0FB6F16E403421B3ULL, 0x7814EF40147735B2ULL, 0xB3D2635A9EB27D10ULL, 0xE146EB498AD40310ULL, 
            0x4EE9F3750F7DAE39ULL, 0xA3B01E0759AFE963ULL, 0x1F4F6F7FB1045090ULL, 0x6ED0E757878CB60BULL, 
            0x691384BF0DBA6DB5ULL, 0xC1B42D62942512DDULL, 0xFCD6394FE1D4E05CULL, 0x3C255A94963512C9ULL, 
            0xCCE66936EE6A9A06ULL, 0x8A1AA99AADE715DCULL, 0x59D14DDDB5CD03AEULL, 0x9682FD4CB3DADF39ULL
        },
        {
            0x0634617FBEDB8614ULL, 0x2C61F0FB8DCEBC02ULL, 0xA92D2D679BEE9E1AULL, 0x7BDD07F65CE18D84ULL, 
            0x856A229ADF9F6E0CULL, 0xFC3AAF0D0D449CBDULL, 0xD3A2A567F503D88FULL, 0x95DD9B94791117A1ULL, 
            0x46F8C1430E1AE018ULL, 0x08BD61111A8576F5ULL, 0x238C85187C138066ULL, 0x8619A2A22495C44DULL, 
            0x6DD4C98E60E056CFULL, 0x40B9A70F5E3A4F23ULL, 0x4D01A07BC29A63C3ULL, 0xCE23C09FA99E856EULL, 
            0x9199A470EF570F0EULL, 0x899D6C61B4E5DE28ULL, 0x54BE9E529A2BCACAULL, 0xABA5EF3207F68094ULL, 
            0x74B2071BC8EEF813ULL, 0x223D84579550E171ULL, 0x328EC78E221126E9ULL, 0x305D941CC963896EULL, 
            0xE867D14B40E11787ULL, 0x68D4F26B1B04FECDULL, 0x4C6B81AF0BDF097DULL, 0x969EF7E31C7F300FULL, 
            0xD3A4FF28AB473BF1ULL, 0x6B48AB4A10DF5C9BULL, 0xBBEF145F92188F60ULL, 0x27263A42CE20CD32ULL
        },
        {
            0x9118CCC5584D8089ULL, 0x1CDB388A1B138663ULL, 0x09F18272A795AD1BULL, 0xC01FA1816F54E3F4ULL, 
            0x9E891A00B2F52551ULL, 0x64E96A9753110D46ULL, 0xAA77D65CCC86EAF9ULL, 0xB4D39D05D0AA8D82ULL, 
            0x8E77FC6937F94B10ULL, 0x2B491298F94B6C19ULL, 0xD1CF6D4D185D0DD7ULL, 0xC67CA844A924387BULL, 
            0x0B5D2A6CFF990377ULL, 0xC285F58DE5C3E956ULL, 0x41005D4B144E566BULL, 0x72016333F242C5E5ULL, 
            0x23B0A66B22931C12ULL, 0x6F53A82C2C18AEB3ULL, 0x40CD1CAADDCC2F8BULL, 0xCED080A3F944EA11ULL, 
            0xB39B1F72E7689382ULL, 0x2C70D683834D3659ULL, 0x4B2273B9AFF97C56ULL, 0x805DAD6E5243146FULL, 
            0x9FC9172A4BB5B485ULL, 0x0B89F46F25B5B903ULL, 0x7FF10ACF4A201EEDULL, 0x3ABF4D6D69E3D3B0ULL, 
            0x698D8C3136031BBFULL, 0x265F98A85C1D2D4BULL, 0x231709083119764DULL, 0xDB7894215B07BF18ULL
        },
        {
            0xAEF0637711A7A27BULL, 0x798026C9B2602B37ULL, 0xA805ABC81583E6CDULL, 0x195620975BE0A03FULL, 
            0x79EA71AEE708422FULL, 0x1B40737A4289A764ULL, 0x59A04532768FDCF3ULL, 0xCD158B731047A953ULL, 
            0x6A8876BE98BBBDD5ULL, 0x1708CB475C83C7ADULL, 0x749BF0D4F370D489ULL, 0x2E0651E848CEE520ULL, 
            0xE47A99E142AD9157ULL, 0x832B85058DD489A2ULL, 0xCEB0763C055C5559ULL, 0x4E832F74775D1FBEULL, 
            0x20FE643DA35F4306ULL, 0xF29B6C75C78A9835ULL, 0x6F35824B72879378ULL, 0x7FDB5BAAF3127667ULL, 
            0x84AA30C2931510A8ULL, 0x00BEFC48EFE79B22ULL, 0xAA64FDE66B6CF589ULL, 0x90BDE313893E967DULL, 
            0xD9D3F551C2739701ULL, 0x8A5FF4CA4FCAD1BEULL, 0xF4C2B727DFF2C238ULL, 0xB29A3E832357B267ULL, 
            0xE43DE5ADDA4F9C0AULL, 0xB2B15A719218CE9AULL, 0x3B79DDD7556E037DULL, 0x3F56B7A030195BD9ULL
        }
    },
    {
        {
            0xECC5F48D1CCA5C4FULL, 0x9CAA2F858B6FAE71ULL, 0x18C09816DD20B1D9ULL, 0xBAE2C50CC0683447ULL, 
            0x8DAF909067D62974ULL, 0xBB431253F12D83E0ULL, 0x33A81C52286D5A27ULL, 0xE0FAA9A3F87EBF6DULL, 
            0x3C0A7E02DE59FD5CULL, 0xD6F9CEDAF7FAE422ULL, 0xDA8E75B54F947019ULL, 0x9AFEB8128FEDCA58ULL, 
            0xCB03A4697C1BA87DULL, 0xB3C2A113466FCD57ULL, 0xBA27B703F5916BA0ULL, 0x0BBD33B9B5644AF7ULL, 
            0x976928868333E497ULL, 0x9D8EA1F43CA23AB3ULL, 0xFDE85042A08EE252ULL, 0xE0AAD39D522D2106ULL, 
            0x4E5E056C3C077DBFULL, 0x81B515216199768EULL, 0x8EE1770F2C6034ECULL, 0xC527E536903C8415ULL, 
            0x97DEA809FBC4F833ULL, 0xCE530175A8DF88EEULL, 0xECFD4D620CD06204ULL, 0x20BD3EF7B3122E6AULL, 
            0x7A593E7F20F3EAA1ULL, 0xFDFF8E3080256441ULL, 0x5143C48D07794248ULL, 0x11C07A173D963723ULL
        },
        {
            0x9A599AE41E0C9E0BULL, 0xD568557823B18354ULL, 0x741D906C7E8705ACULL, 0x58DCF89F34929875ULL, 
            0x27BABE3DC7C5503CULL, 0x98C198D2867F6E96ULL, 0xF86CAD32F17AA28DULL, 0x019F79DD9E7CCD8EULL, 
            0x3D3CC8F3A1FC7E98ULL, 0xA879CE7DBC18804CULL, 0xF427907D3E694852ULL, 0x4DA5669CCDBE3A06ULL, 
            0xCB4D2F170601413DULL, 0xDE2C569D707F3B86ULL, 0x8A301B67CD626A7EULL, 0x842F120A15AAAE01ULL, 
            0xFC89DDDC4D650CA2ULL, 0x89074B8681B56EFAULL, 0x98970C6A23D12B0BULL, 0xF97D87424A738407ULL, 
            0xDF0FD4AC78183081ULL, 0x3DC04308ED0BAD0BULL, 0xEDFAF09D926B49F0ULL, 0xDAA3318D8EED9D62ULL, 
            0x7AB6C8A62FEA861CULL, 0x85A1610C014468C2ULL, 0x93EC96EA170E1C49ULL, 0x94B4782C01BE2857ULL, 
            0xD1358E71F4142595ULL, 0x741D5AA92CB02D8CULL, 0xD9BB592F03C55929ULL, 0x47DA7E9A224AC6FAULL
        },
        {
            0xCE9A2801487F7AD4ULL, 0x0173BED098142EF5ULL, 0xF3BA372B40CF0E7EULL, 0x46315368B0FB943DULL, 
            0x54BB7019697A5D26ULL, 0x32E5B2194EFD0B31ULL, 0x8680C5CE9FCCA790ULL, 0x39D3696927D9B778ULL, 
            0x7EF2A016E2009C23ULL, 0x266FE94BFFB58839ULL, 0xC18068BBCB337D99ULL, 0xB2C6538F2D396B6AULL, 
            0x92B12F964B296990ULL, 0x462A206455169045ULL, 0x36E4DCE5679BD6D0ULL, 0x8C88536E8689D571ULL, 
            0x724CCF3B73F31A21ULL, 0x5331DB46E346FD15ULL, 0x16A7870412016D06ULL, 0x2C084B51B35E8D51ULL, 
            0xE9D0800F93737CCBULL, 0x7CA0B4F872306016ULL, 0x6B9FF988E688C950ULL, 0x7CF9237CD186208CULL, 
            0xE921C47AB5719EB6ULL, 0xBFB953F6AC763AC4ULL, 0x8314725AA5594A1EULL, 0x81A72F09F6E8B43AULL, 
            0xA8F539CACB26E9FCULL, 0x05610D7B0B125BFAULL, 0x6BB0E862BE77E935ULL, 0x65DDD77A7CF0BC41ULL
        },
        {
            0xFE3D83739B47207DULL, 0x1EF7175EE873995EULL, 0xFBD795E8EA3DC8F1ULL, 0xEB4DB928DAE69C5EULL, 
            0xA314D7C88993F19FULL, 0x441368DCB74CD18EULL, 0x52EDC7AC786E05CCULL, 0x0DA0975141C8562FULL, 
            0x734F7398B90A8B42ULL, 0xDBCA8F0789E50284ULL, 0x848902AECB28F4E4ULL, 0x107B24717F6007DAULL, 
            0x72EB51944C831163ULL, 0x71C24C43039DD326ULL, 0xC387660180D87FB7ULL, 0x879D56305B263959ULL, 
            0x058B2DCE5E878733ULL, 0x2E28FC713480B101ULL, 0x638AE426D1451699ULL, 0xD63D11156DE00E6AULL, 
            0x0605D50B08EC4B41ULL, 0x9597BAD0F47FA78FULL, 0xFC3B9AA5861FC067ULL, 0x628BBD9935F3271CULL, 
            0xB07ADE91EB89DCCDULL, 0x1F595E1402A740DFULL, 0x488DE4F79E690A2CULL, 0x8E29952932AC1F85ULL, 
            0xAA21EF6C8837F7D3ULL, 0x7C51A104EBFCF2A4ULL, 0xC853DF641505C6F8ULL, 0x7F081BF25B09B84AULL
        },
        {
            0x4A8B1C29B553474CULL, 0x1D7FBC0137BF33CCULL, 0xA7FCE25C8B6658F9ULL, 0xB65CC97300790C05ULL, 
            0x3C8069A5E3ED5A18ULL, 0xCBCFB079B9BDC128ULL, 0xE38590B79407765BULL, 0x604B85C4A0F653B0ULL, 
            0xF7CE6F141B45F997ULL, 0xA2DEB8914E720E37ULL, 0x2AECA57F556ABAB1ULL, 0xB468D007F6CCC349ULL, 
            0x6FA3B74855A9135AULL, 0x7D312541030E5515ULL, 0x135540A54A5C126FULL, 0x25125798CC2F2480ULL, 
            0x888487E0EB7D4C69ULL, 0x11B2CEFA1D92C0EDULL, 0x04DA5C42C4102C0FULL, 0x981889D8F0A5FBFDULL, 
            0x39BF86F432BA8E97ULL, 0x7D3BDEA792112F46ULL, 0x649AB6A5BB0FAFB3ULL, 0x196690A7FD61AA5EULL, 
            0x24446AA769EDEAA8ULL, 0x076195DDA8B8ADC6ULL, 0xD376E99E3ED94D74ULL, 0xA9A42275C2D7538BULL, 
            0x86B38AA758246EA9ULL, 0x886BC71AF89F5123ULL, 0xDBDEDB2A2F430524ULL, 0xBA8C117435069F0AULL
        },
        {
            0x13BC4226CC49B8B1ULL, 0xD30883876D301300ULL, 0x451DF3D031ABA733ULL, 0xF0BD8D052A3FE92CULL, 
            0x6153A1615D96FC49ULL, 0x26A80F34A4D547A4ULL, 0x04A3C1CC43D42271ULL, 0x8EE1B14DD311C0F7ULL, 
            0x249C4EE398586627ULL, 0x62C7E3F06DC0D4A2ULL, 0xED0D0CB750A68E9CULL, 0x1E7A5C6C51B33AF6ULL, 
            0x9E40C3E50ED4AB7BULL, 0xFEFCCCC75E668DD4ULL, 0x3C51E4CF63F9FA59ULL, 0x7F7AABBCA6AF8609ULL, 
            0xD165424C55481D45ULL, 0xAAF11B1C798CD269ULL, 0xC31DA8C24956F253ULL, 0xDDB167F25809F70BULL, 
            0x83B94AAFE5BF5496ULL, 0x3076732FB74B7798ULL, 0xAB7046E673DE7F96ULL, 0x5DF1E172117476F3ULL, 
            0x3B206CD036DEE0CCULL, 0xBE759B4132C1E3E3ULL, 0xF84C2845D756C963ULL, 0xF2B43C40CE1027DAULL, 
            0x37EEB0B882D1D0A8ULL, 0xF70A7DF6C0E7177FULL, 0x3C001B64CC5BEBEEULL, 0x91E05FA6BA358E00ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alcor::kKeySpawnBConstants = {
    0xE62C1905E5782344ULL,
    0x50AA498BD5BE5AE7ULL,
    0xCAF7DB8DA40D9706ULL,
    0xE62C1905E5782344ULL,
    0x50AA498BD5BE5AE7ULL,
    0xCAF7DB8DA40D9706ULL,
    0xCC3C89965446A79DULL,
    0x764402FDE8DCCC34ULL,
    0x1D,
    0x25,
    0x88,
    0x36,
    0x41,
    0x21,
    0x15,
    0x40
};

const TwistDomainSaltSet TwistExpander_Alcor::kSeedSalts = {
    {
        {
            0x2DB9E6E5CAA4F336ULL, 0x9700F1D69CD4A76EULL, 0x4CB2DFB9001A4BCEULL, 0x57DDFF91AACFF3EEULL, 
            0xB4E8AC67CCF0E93EULL, 0xB771E7F3D64DCBF0ULL, 0x6D666419543EEBAEULL, 0x5F15B4A39C4637BCULL, 
            0x45CF940BF07ED212ULL, 0x0759593997D962E5ULL, 0xE76CDFE4671DB613ULL, 0x7D81D25B75466CE7ULL, 
            0xAF2F7E0DD418A3D3ULL, 0x018C1E5C287F8399ULL, 0xE07CD381AA449CD7ULL, 0x17AE458B86398FC3ULL, 
            0xF95DEA1110FD0BB8ULL, 0x98246C5F5D455413ULL, 0xDDA298793CABB925ULL, 0x2DF26D18688D6C55ULL, 
            0x82CB53EA88835917ULL, 0x8D8C482552C3EB20ULL, 0x8FF150A18C100FA2ULL, 0xD031D577FA8E2FA6ULL, 
            0x8A882990894A921CULL, 0x4CA65CF09A594207ULL, 0x1D1F84EDE789CA09ULL, 0x38B06FB5AF2D9143ULL, 
            0x87EBE98AF4677A73ULL, 0xC6BA56E9CBA1BB12ULL, 0x6D80AAB6DD1B7111ULL, 0x6B662E223EB89597ULL
        },
        {
            0x86FE82AC6F2E011AULL, 0xBF4DA0B9D66560BAULL, 0x24F243E3A00842F1ULL, 0xE71398E0DA9B7F29ULL, 
            0x9E68F95A7C657CF6ULL, 0xF5F2CC363C0B724BULL, 0xF94BF67A9B5BEFE7ULL, 0x0CF784924CDD758EULL, 
            0x1AF323A9974044B3ULL, 0x2B9A0938FE46BF35ULL, 0x9D3286174D7F1C50ULL, 0x092C624D7F8420A5ULL, 
            0x8C9F85D7A0B7345EULL, 0x354A93A8F4702DA5ULL, 0xCFB299D7BD54F48CULL, 0xDA4F5898D3E5971CULL, 
            0xC95238A6D0CCC880ULL, 0x44A0ED3CD6246A43ULL, 0x641AE4F41171B2CEULL, 0xFFF41525123A1CFFULL, 
            0xD655DFDE70BC45A5ULL, 0xDEF7733F3516D467ULL, 0x0CF2567F8580D481ULL, 0xE4EAAE8AA08D4714ULL, 
            0x9588547267008501ULL, 0x50F0715F6F7F03FEULL, 0x3C35C7B0E561594CULL, 0x08F949B6C7732499ULL, 
            0x215B846E1C02FCFEULL, 0x9F70040DC7EA3141ULL, 0x39C97FA4A09BB16FULL, 0x4D44DD207513223AULL
        },
        {
            0x58019730D4580E2DULL, 0x8314B90E42CBF495ULL, 0xFB1FC65717595BFDULL, 0xA787C9BF0CDC0776ULL, 
            0x979AC67EF0EBB22DULL, 0x6375C8201FE0CD85ULL, 0x4519EF4031122F31ULL, 0xCB136FAFEA4EC6B9ULL, 
            0x6749BDD77917EEE4ULL, 0x984E179F5D033005ULL, 0xCB8FF30AE0083AA4ULL, 0x4EA7A7B31A2FBC92ULL, 
            0x28AC313727587BAAULL, 0xB1B6A85470502632ULL, 0xB0852655F60AB43EULL, 0xCA63852B6184C2C6ULL, 
            0x873366D8B6A4A1A6ULL, 0xA78BE72586A148BFULL, 0xB49423F61C876288ULL, 0x778882A66289D060ULL, 
            0x140AEDB08F6EF797ULL, 0x52328A0FDA9C734AULL, 0x2F4F2F95F5BCEBA6ULL, 0x532D985C19853A41ULL, 
            0x5AD7735768810640ULL, 0x04969DC3EF9A746DULL, 0x619E51A6CA2A33F8ULL, 0x79547095DB23A101ULL, 
            0x099E5BB28E951E2FULL, 0x517DF4DA02839725ULL, 0xBC0ECFBF42EBF48FULL, 0x969BCDC2BE8A26BCULL
        },
        {
            0x513EFEA745EDBAAAULL, 0x4FF1A23994223AC6ULL, 0x6FDE8B2CE3DE3369ULL, 0x383BD109B6C5FEB2ULL, 
            0x5072EC1B5ACED587ULL, 0xFF6F2813B236C22DULL, 0x90EAAAB1C457002BULL, 0x47C5D184823F06C4ULL, 
            0xF866731F7E5B9F95ULL, 0x27B67BE9BABAD25CULL, 0x49B998F6020BEFA7ULL, 0xC809FFB9148BB9CEULL, 
            0xEFD48FE034BEB134ULL, 0x45D312A59DC86355ULL, 0xBDEECEF7AD98D38DULL, 0xCFE25D86A3F8763CULL, 
            0x8DBAC71FC1C6CA44ULL, 0xFD7A29D0F25A8A6CULL, 0x87D9AB4FAD770FE5ULL, 0x1F2C4BD714F7850CULL, 
            0xF0A3E172161B3964ULL, 0x4D865E834635E746ULL, 0x4E2758B3BE39DED4ULL, 0x39A5171E9FAC4B23ULL, 
            0x347B58D892B83895ULL, 0x6D8488762D55BBE8ULL, 0xF5CC12FEF3610D27ULL, 0x4E22F2129612F94BULL, 
            0x525B347DBAD5586AULL, 0x74F7B562F73AFB59ULL, 0xDE6DF5681DA7FE39ULL, 0x76A07224BAD602B8ULL
        },
        {
            0x8074120FF16D8DBDULL, 0xC880FA2AA06E089FULL, 0xC9AC806909B18863ULL, 0x05CCF64E6E89D2C6ULL, 
            0xD0243A79B50558ECULL, 0xEB65D477FC6CDA32ULL, 0x95E415C00DC02FCAULL, 0x4F9A4EEF93B66EEFULL, 
            0xD904BF75BE204C96ULL, 0x9EC39960D373D87AULL, 0x6660AEBD9F4080D1ULL, 0xF55C142D1F9A6572ULL, 
            0xA4FC96B5E61C5F1BULL, 0x2ED0B23E63B3C9C4ULL, 0xBF933B7266C612BEULL, 0xF23890D7DFB81129ULL, 
            0xD77DB95759CDF9AAULL, 0x1B4E91886E038B48ULL, 0x3F526B32D7076CB4ULL, 0xB8C2BFB338EA45F5ULL, 
            0xFB4D32739F50D3DEULL, 0x56D58AD67A891782ULL, 0xB0CC972383B9BA93ULL, 0xF4D25498665E9CF2ULL, 
            0x84A9511E237572D9ULL, 0x2D02036D5DE1F2ACULL, 0xABC8F6EC7C0B96ABULL, 0x9BD197D901D936E6ULL, 
            0x2F7AE28643765F85ULL, 0x57F582EAEB624480ULL, 0xC3457B0037BA7D8AULL, 0x9635DBA630B0867AULL
        },
        {
            0xCECAA5F1641904DEULL, 0x265EABC3F35B4D74ULL, 0x77137D90D1A2078CULL, 0x63872921A18085DBULL, 
            0x6E974E124144CA1EULL, 0x2CC1275BD69984E0ULL, 0x48B4B3DACE738F0AULL, 0x06681C355D5719F0ULL, 
            0x778B83C30AD85AC0ULL, 0x9516C2FE4877E1DEULL, 0xB22E2B3899D7F0B5ULL, 0x0396177565AB0B15ULL, 
            0xDDD95921DA9821BFULL, 0xFD110FC920EFC905ULL, 0x9824C9A7AEFE106EULL, 0xEB0547C92F6CC2E3ULL, 
            0x7E057D7A5106621DULL, 0x160AAAA2F6162AE0ULL, 0xC38619BDEC9B6805ULL, 0x730BA5618F7227C0ULL, 
            0x30ACE6F11CAE706BULL, 0xF73C688BF8961C21ULL, 0xD99F686456A14FCCULL, 0x70394E7346319F5AULL, 
            0xA5370E855BACB1D8ULL, 0xFDC78972414CCAD9ULL, 0x6FF864E4215F9BC6ULL, 0xD08DFAA600D2FF2DULL, 
            0x9015EF1CE05FE75DULL, 0x6886BCF5E4B1F7EAULL, 0xFFAA315A9EF3EAF9ULL, 0x8BA4717BF53DAC17ULL
        }
    },
    {
        {
            0x27288C53DDF1BC11ULL, 0xEDA084BCDCDF5C50ULL, 0xD21A98A1F7399116ULL, 0xDDCE8E4C6BDA4DA4ULL, 
            0xEC4D9C08E0F2A173ULL, 0xEA59BF06501E16D6ULL, 0x4E941B804DC882E0ULL, 0xA777CEFDFD1B008CULL, 
            0xAEE395EF1A7643FBULL, 0x810E812F25FFFDA5ULL, 0x007ECE94A2D5E207ULL, 0xE800DA5293876A14ULL, 
            0xCE6A7C8B945686BFULL, 0x5FBB404777EA4801ULL, 0x6827DC7B2382AAC5ULL, 0x0217A72A2DA06B3FULL, 
            0x6755AFAB0ED5DAE0ULL, 0x8C5602A08D9A2AC1ULL, 0x79F481450689E4B8ULL, 0x02DBBD60337A809FULL, 
            0x00DAE8E65AE3C33BULL, 0xB05102E453A21A64ULL, 0xF4E71151016C8268ULL, 0xA4B2D3E3C7AE7462ULL, 
            0x2FD2FC6DB57921F0ULL, 0x8AC4B72E173E8C85ULL, 0x264B2A396E2D734EULL, 0xF59FFBC9FD139DCCULL, 
            0x7FD258664E40A5C4ULL, 0xB50DF17BFEBD3910ULL, 0xBD332AF9F5A9CB1DULL, 0x38EA77A4BDD3AF22ULL
        },
        {
            0x314EF99091462AC4ULL, 0xE9669809485CA07AULL, 0xDBBBBE5C930EDAABULL, 0x7A1087AD63CF0FBEULL, 
            0x417221D4164C0FDDULL, 0x462B8F2DCCE6E3B4ULL, 0x26FB7EB79CC9BE40ULL, 0x659AFF078607088AULL, 
            0x8FF69837384FDBD6ULL, 0xB28870FC1E9FC0C4ULL, 0xF4C89581C9AC1DB7ULL, 0x6104DD0E0503D593ULL, 
            0xB62447088249063FULL, 0x3E468BAF83CD688AULL, 0x8A6C3690F14BADA6ULL, 0x7F4B95FB1BEFCECDULL, 
            0x019217E180481DC6ULL, 0xBE4438D23CCAE918ULL, 0xE475044B4D5B5135ULL, 0xE7C255B6CAB977E5ULL, 
            0x410BAF5524384617ULL, 0x1C1FB28AAEA8BE7AULL, 0x4B5E51D361E64BC8ULL, 0x318C566C9C1C39CCULL, 
            0xBBD2FE27D0C2F2ABULL, 0x5F1C0F69C31D6439ULL, 0x4B05BE1632F14EC4ULL, 0x8C996FF88825D466ULL, 
            0xBDC2F76C8F83737CULL, 0xC7595810ACE8DAEDULL, 0x5F796BD41DE7C978ULL, 0x01834800C4B23B07ULL
        },
        {
            0x0910B87A1FB9B020ULL, 0x812DD3AB2C708951ULL, 0x7211FF48CEE0534DULL, 0x62F8ED213678DCF3ULL, 
            0x114A6587F033145BULL, 0xE6E7817E51990161ULL, 0xCD7335E94D3157DDULL, 0xC580152610ECF988ULL, 
            0xECE57F1CD596D38DULL, 0xD8249BE5F0BD58EDULL, 0x8A806F1F304103D4ULL, 0x47F565CC30B6C743ULL, 
            0x3AB080EB4C3649CCULL, 0x5ADC4413496032FEULL, 0x804BD6D5558430A2ULL, 0x365EF49D15B6B6E0ULL, 
            0x810E22F39F790FBAULL, 0x4C66588D66507248ULL, 0x07B8F2E7F6D2CCF3ULL, 0x396ED35B83263755ULL, 
            0xA108AF3016C6DC32ULL, 0x76B9D10181347E76ULL, 0xDA23C23D6DDA3228ULL, 0xFD26AE26B495AA73ULL, 
            0x954D936D10401E5AULL, 0xA3542BF6541E7DDDULL, 0x1CE2EBCEA783F965ULL, 0x7AC4963436F8F99AULL, 
            0x1F8B15B6282E0EA2ULL, 0x64EC848CB29B24F2ULL, 0xC251BC476AF6F959ULL, 0x0E6289FB36E7917FULL
        },
        {
            0xC2E1E3746648A2F3ULL, 0xAF4434FBC4454B7AULL, 0x34B480567299B81DULL, 0x43C090A439873125ULL, 
            0x3833154DC7296BCBULL, 0x9112D525B23CD6C8ULL, 0x337B496A3EDAB590ULL, 0x01B4CF895E150BC2ULL, 
            0x41CB11FB71F3E6B6ULL, 0x921789C77CAD874BULL, 0xD09DA343C50A5857ULL, 0x27D96D2023456464ULL, 
            0xEAA4C9938F41B482ULL, 0xE3C32D6ED5E56B03ULL, 0x4754ACFCA18F87A4ULL, 0xAA9FA793F38AE0FBULL, 
            0xDAF11FA2CF3A9E1FULL, 0x954BBA112AF9A5D5ULL, 0xC281E66EED1E83B8ULL, 0xE85A79820B0A828DULL, 
            0x720389F1B303CD5FULL, 0x4A847BB5E2AB942EULL, 0x6613C4EA62182272ULL, 0x5F09F6C60D9A62E1ULL, 
            0x01F43B277561E5D6ULL, 0xA1B0D66683743F53ULL, 0xE38FF63CE488C468ULL, 0x9DBAFAB7DCC4D5D9ULL, 
            0x7360A956ACA25BAFULL, 0x81DFAE767319D0A2ULL, 0x69BEE2A2DCFF00C8ULL, 0x53CC1BC0A6DE9535ULL
        },
        {
            0x5F23C1564F114DD8ULL, 0x01BEBE143060662DULL, 0x55145801033F4E2CULL, 0x815F4DB4A40794C7ULL, 
            0xEE6514ECB2D1BB14ULL, 0x853933D8911431A3ULL, 0x8FA05334E3D0B0BAULL, 0x258270140B6F7773ULL, 
            0x74001D1734133284ULL, 0xE0E6635A8ABF4D67ULL, 0x97D6050AA7D2FA55ULL, 0x9911F8E1E171C02FULL, 
            0xAD63C8516DBF57AAULL, 0x0991EE74C5F5DB67ULL, 0xF5AF211B07C4D345ULL, 0xA2E608384E2A6710ULL, 
            0x826C3B7272189163ULL, 0xB182013E614FBCBFULL, 0xAB42AA15F74BA2D1ULL, 0xBE93DE1599CD7FD6ULL, 
            0x5BBDE6034321B2E2ULL, 0x2B2C2A62B517FCA5ULL, 0x00E921FC65E00A54ULL, 0xF09ED73EF21A6E6EULL, 
            0xD1B8EF9BBF6FD065ULL, 0xF9A04430C69F32EEULL, 0xC374699427442E5CULL, 0x38EB8D69652E80E8ULL, 
            0x199486F0B8B65497ULL, 0x16B05B06445A8A45ULL, 0x68D49F4AB6F1C965ULL, 0x44651F183E969598ULL
        },
        {
            0x091720AEF9C044F5ULL, 0xB9F34505D7BDF2A0ULL, 0x6364B9A4C155CE48ULL, 0x8900F9379BD12CF4ULL, 
            0x9437FC1081B8D235ULL, 0x5C74F51D28D029EDULL, 0x24DC106E10FD42E7ULL, 0x96918BB6A830C9B0ULL, 
            0x8AE20ADC05BF8078ULL, 0x58054487349F3FC7ULL, 0x0541767999CFDF3BULL, 0x1391C7E89BAB0F8FULL, 
            0x7F0097A02F7C97A5ULL, 0xFC52654B1E834983ULL, 0xDD5721206DC553A0ULL, 0xF512C936D8F975F9ULL, 
            0x97B2E0CB1AB92285ULL, 0x08CD3E25F8912F73ULL, 0xB6CE1133568897CFULL, 0x751B374C99CDC2B9ULL, 
            0x66FFBB00E184C7DBULL, 0xECBF46A885A06CF3ULL, 0x9A5A47FACD6A5117ULL, 0x6B4490F43E885A3CULL, 
            0x02079AC64BA12DEFULL, 0x5B24A624F31188A5ULL, 0x2E1F546D1051EC38ULL, 0x75CB7197C0C6606DULL, 
            0xFA56E6D72C691DD3ULL, 0x3D86B121783237F5ULL, 0x5AAA3B88088034A9ULL, 0xF0074CB84CFF9BDBULL
        }
    },
    {
        {
            0x7D3FDD48CC6E45A9ULL, 0xD66488D8F97D8DD5ULL, 0x4BCC3E3F72F1D140ULL, 0xC009496B8E93B693ULL, 
            0xCE9EE59F181096A4ULL, 0xCD53C54F9C69BB00ULL, 0xB58F7E69EA05E148ULL, 0xEC72A8FBDF83ED2CULL, 
            0xC5B0001D68BAFB00ULL, 0x76A1CF4938263451ULL, 0xBB6F46B1EE123058ULL, 0x064AA147F66DFD28ULL, 
            0xD13C84963D970A9EULL, 0xB73E12D747C06E33ULL, 0x5E808E7234D39E5BULL, 0x5268F57FEACD848AULL, 
            0xAF5F6CC8CBD3FFD7ULL, 0x42C9E5055C40D6B3ULL, 0x35BD9954398A62C1ULL, 0x4D5064865BCD6405ULL, 
            0xEB9AB877A5C3C797ULL, 0x5E313096084F82C3ULL, 0x878E10919A23FF68ULL, 0x1B14D045390926E2ULL, 
            0xD21AE910769B86B4ULL, 0x1239639681465E45ULL, 0x2432BAED0C9461C6ULL, 0xC36A1602924BB81AULL, 
            0x885CCB152F8D67ADULL, 0xB8C9FB59C700F3E0ULL, 0x4119F9EB7D63D4C2ULL, 0x21E4331E8707A60BULL
        },
        {
            0xB5C30EA594005169ULL, 0x344774174E5B0FD6ULL, 0x419E9FCE2929A0D6ULL, 0x54A19CCCDD9BE9CCULL, 
            0x19F3E0CC556D79DDULL, 0x95858EFF3092A905ULL, 0x11782ACA0927C44AULL, 0x97994E8B5C55DBBFULL, 
            0x579A8E8837A5BE23ULL, 0xFC632C1416D1EE0FULL, 0xC26093626E4AA76EULL, 0x41EBE96CFCB1ECD5ULL, 
            0x6263633C0B1CC817ULL, 0x9BD108D5126FE4C1ULL, 0x8E4E93FBA603FE0AULL, 0x29D7401EF0FD6DDCULL, 
            0x7093297498DE68F1ULL, 0x4E7C4877D0823EC5ULL, 0x40CE3A444B189E04ULL, 0x8792A0606911E88AULL, 
            0x1FA319234416A3C9ULL, 0xD085F159C74FA6E0ULL, 0xE3EB6BA722D76216ULL, 0x100BBE1E9C3EA22DULL, 
            0x6A4867C74A0F82E6ULL, 0x9E3D80B1D85A3BE4ULL, 0xF33F7FD91780B3FEULL, 0x4846097347B27B7AULL, 
            0x05319452A38B5202ULL, 0x486D3145885D3998ULL, 0x41CF80827323541CULL, 0xEDFDC493DE0AB57FULL
        },
        {
            0x87B377D6A4EBD35AULL, 0x4AD98997B4A275DEULL, 0x65F25BC1E08E334EULL, 0x330A2A6BD8FA17C1ULL, 
            0x04C6DE14080B430FULL, 0x48A074B4521135B1ULL, 0xB37D71057FDC540FULL, 0x9079846E92F68B3EULL, 
            0xD63D432A83C68307ULL, 0xACA45A7677734DA9ULL, 0xEF9E2CFA2500341CULL, 0x660CF8847C0EBC54ULL, 
            0xE9477DCB7B81D93EULL, 0x993C8C848ACE1C3CULL, 0x1FCE0525A10B0A02ULL, 0x36C94116FA3DE156ULL, 
            0xDA9D40B08685397FULL, 0x2D2B58723344BFFBULL, 0x3408A5C200983ECDULL, 0xC7407B36A6AD2314ULL, 
            0x98B4380850E6A64AULL, 0x0231385E824B6435ULL, 0xC8CD5196A4C4FA34ULL, 0x21B2E425DBA26907ULL, 
            0x35E7E7A61FCBEB86ULL, 0x07077A4B5EE249BFULL, 0x7BF9CFCBF7099FEAULL, 0x3954BADD54AEF4D5ULL, 
            0x40B6431698EB8A01ULL, 0x34C4EC1B40641090ULL, 0xBFE5CB864351291FULL, 0xDE339655EA81C3B4ULL
        },
        {
            0xE429A69C98F716E1ULL, 0x9A3F87BF4D8B89C0ULL, 0x14CFB1F0501B2563ULL, 0x7BF3D8C435C6C03FULL, 
            0x7CCC5921B8A82A23ULL, 0xC80C90183AE7D1B2ULL, 0x8B608D54749DD95FULL, 0xF3EAEE4D0E4A85B3ULL, 
            0x58EEBDFC9296E357ULL, 0xAF028ADF266FC6E6ULL, 0xD094F7F65D56A135ULL, 0x96DD3596E9BCFFF5ULL, 
            0x16441CC0F8EF6D9AULL, 0x0B4E65427C68CDD7ULL, 0x37D12720B04632ABULL, 0xC8266C4181BFCB67ULL, 
            0x08AE24AE1C7010AEULL, 0x756F1B19C112E7D0ULL, 0xDE02BCA948B84BDFULL, 0x03EA1E28F587A841ULL, 
            0x2B3F7FA5F930DBB7ULL, 0xBB8A8FBA4457D6DDULL, 0x1B68A74C4160D992ULL, 0xB06DD3610E3F39FFULL, 
            0xC034A614715DABFEULL, 0xEF5ADA2C45EFC623ULL, 0x73A499FA788FDA69ULL, 0x493FCD73EA0700EEULL, 
            0xDA30EE9632BDCF88ULL, 0xE06BECCE60276319ULL, 0x09CD361D8734F219ULL, 0xBFB413371705438CULL
        },
        {
            0x9744CA047AD23035ULL, 0x4AA77C639B89CE07ULL, 0xD1DFD2B7CE27B538ULL, 0x47968B5B435F345AULL, 
            0x3B05D395D5D832F9ULL, 0x31438BCF5AAE71A7ULL, 0x5947AE765BF3E3DEULL, 0xFC5624A68CA58031ULL, 
            0x7632793C8D714E61ULL, 0x11B198B534A46C53ULL, 0xE8F7FC1BB529ED36ULL, 0x0DA28C98AE17E3C3ULL, 
            0xFD11A64273D1C79DULL, 0x4A940F5CE7502A81ULL, 0xA4DA8C9B68E2E018ULL, 0x453C4DA2F2517B4DULL, 
            0xEB7A4F8BA0FBEB80ULL, 0x1B985F5D2E737797ULL, 0xE06949CE2AB7A162ULL, 0x93792445810990AAULL, 
            0x6D529414BACCB855ULL, 0xEBC3B35F5241B451ULL, 0xA7D6552E97E16703ULL, 0x379890A41AF381DBULL, 
            0xA6770679908F652EULL, 0xB61BEA7C216C4DBAULL, 0x193F181E985B9FF3ULL, 0x5FE613FC81F62AADULL, 
            0x178B777C7EFB9E1AULL, 0x3AB94A66B170FEF7ULL, 0xD967EC3161A40CB5ULL, 0xB3EEC361CA0E4AD0ULL
        },
        {
            0x5F7C71D0966203E4ULL, 0x43C5A3EC10B74707ULL, 0xE6C8CFA22A0C7D47ULL, 0xDF7D1E8209D0FD38ULL, 
            0xB14B955A3B56417FULL, 0x2656223E7D5B43BAULL, 0x3A50E1BBCB71C37DULL, 0xAB2246DC77AF7110ULL, 
            0xFD412CBCBEF1544AULL, 0x623774A273856A2DULL, 0xEA9D168FBDDC8B20ULL, 0x59630BED245069A2ULL, 
            0xAC4992E2361D9134ULL, 0x4AA91329BF38CBF5ULL, 0x3FF3C47853880034ULL, 0x990FFC97FBCDBFA5ULL, 
            0x4B57D0619730687EULL, 0x42C8E5E92C68771AULL, 0xD48044FED0CEC83DULL, 0xB4C4BCBF1155A0B9ULL, 
            0x63FA3B9FB7665A46ULL, 0x8B08BA359DAA1F82ULL, 0x0B989A8D21A34506ULL, 0x6523AAFBAFDD628AULL, 
            0xE90D4B19100BF258ULL, 0x6B0F3D3DB4820DADULL, 0x6CB70FAA0DD50E2EULL, 0xC9421D8ECD978A5BULL, 
            0x3A5BFB5A1FAF3C8DULL, 0xD83B2BDF4C6AD853ULL, 0x4E09A771AA0175A1ULL, 0x1720995FD3E601CFULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alcor::kSeedConstants = {
    0x0CF597DD07F45B27ULL,
    0xE67E501ECDA4C702ULL,
    0x546874DC8A2AAF46ULL,
    0x0CF597DD07F45B27ULL,
    0xE67E501ECDA4C702ULL,
    0x546874DC8A2AAF46ULL,
    0xE8844E77D1DC4494ULL,
    0x31B65DBBA084A138ULL,
    0x0A,
    0x66,
    0xEC,
    0x3B,
    0xC1,
    0xCB,
    0x84,
    0x25
};

const TwistDomainSaltSet TwistExpander_Alcor::kTwistSalts = {
    {
        {
            0xA918AE293B4DAD11ULL, 0xABAE8387EE9C0A7EULL, 0x6CF06573EEFC5838ULL, 0x6108E33DA9E54B3CULL, 
            0xA912042B174625D4ULL, 0xD40F601B8D4C36C5ULL, 0x27B68BDA3A580F3EULL, 0x1E777393C1FB71C9ULL, 
            0x6F3588C5C7190907ULL, 0x65F6974056E93287ULL, 0x33ED05B1B71AB2D1ULL, 0xBA79275E88D82C87ULL, 
            0xDDF048B7875CAD69ULL, 0x2E2D1D115505D88EULL, 0x2CEE6133F414FC1BULL, 0x401481F04678281FULL, 
            0x375D644DBA3800B0ULL, 0xCCC9071F707E63EBULL, 0x6925308A74BAE89DULL, 0x274F2599CAC0854FULL, 
            0x97C07DF4177FB3F5ULL, 0x3CD035BE1D7851FAULL, 0x6F72D67FE949E4B4ULL, 0x5F12CDBA270BA3C8ULL, 
            0xBA3A4B63C31C2111ULL, 0x32945313968464ADULL, 0x887DEBA72D0B41BBULL, 0xB419AD2EA4E0D9EDULL, 
            0x027AAC1C1CB57291ULL, 0x0E478B75B24D718FULL, 0x15986055FD926743ULL, 0x73E9B89C5FCCD91DULL
        },
        {
            0x19C663E1EB0A187CULL, 0xD66B1AE6C5DD9A97ULL, 0x58901F1FE798C864ULL, 0xE40D7A69F8EBD611ULL, 
            0xDF120626B84BAC41ULL, 0x825BD1AB3A65B3CCULL, 0x8A6DDF96C6E689C3ULL, 0x78D4CBEAF815B0F3ULL, 
            0x77020DF5A6CC5107ULL, 0x58D19853A078B51AULL, 0x9DD37478D274CA10ULL, 0xAA84D6FE3EAABA85ULL, 
            0x423104232F7F91EEULL, 0xAF05039D2963BE45ULL, 0x70F2EFCFEE4C584CULL, 0xAA7D8AF9B773E2FBULL, 
            0x6DB91DAC40897F48ULL, 0xBD9A9632251B53C5ULL, 0x733B2A87BF370668ULL, 0x4C9D5A53B7B44F9DULL, 
            0xECA37C48F113B5DBULL, 0x6C5D9D37A877A4C9ULL, 0x8698B4118E062116ULL, 0x048CD55B9E184A36ULL, 
            0x9E73FFE2049ED041ULL, 0x7C4C0B68276ACC23ULL, 0x692263C3710A9935ULL, 0xDCBA510484F213E3ULL, 
            0xDBDAFC392122640FULL, 0x9BC15132C8A38E3DULL, 0xC28B4AB7BF2B6F6BULL, 0xEA5BC2BBBCFD6EF3ULL
        },
        {
            0xD9CFF9A10E77CC2DULL, 0x9E4327241B1277A6ULL, 0x8885A4E442914174ULL, 0x4FC71D87FD63FCB3ULL, 
            0xF326A507A2552644ULL, 0xDA0E47D1D7D75327ULL, 0x8065B9E1E053BB5DULL, 0x57E16ABE75D1ED79ULL, 
            0x80F9069621BB64F2ULL, 0x08A2C4E3627155E6ULL, 0x75C7CCBF37B43BCCULL, 0x6BB6FAC402968083ULL, 
            0x1EB27CF7F25CFA6EULL, 0x7FE1022B295D683FULL, 0xB54E3C11B725C09FULL, 0x71BD032DD93EA542ULL, 
            0x0F3EEC54B1C35EE9ULL, 0xE4BF0A46D0882C70ULL, 0x4A1288CBB715D5E2ULL, 0x764747D3A2A4FCDFULL, 
            0x04656054BA43FCC0ULL, 0x020EC0C2B642AF51ULL, 0x5C46D0C52DEAEB2CULL, 0xAEFA3D4B78132B4EULL, 
            0x44B755B3137750BFULL, 0xF318804CFD4A514CULL, 0x5A2CEC8FAA6DD936ULL, 0xE99E1F4E85D5D0A0ULL, 
            0x83ACAA4E54C88DE0ULL, 0x75A5B8F0D6D99C8CULL, 0x90A6A2E1B2488E29ULL, 0xD5857FC5BC896D06ULL
        },
        {
            0xFAE2FEED804DCA0EULL, 0x2C0373CF69A9E3BFULL, 0x9AB72CAB5B92E549ULL, 0x6B6225EDE5AC6EACULL, 
            0xC93B0F23896DAE54ULL, 0x924BD3A454223B3BULL, 0xEC527A3436F18A18ULL, 0x970CE01DFD6F2AD6ULL, 
            0x44205279D1B20FF7ULL, 0xED61EDFEE2821040ULL, 0x3526F89901DE8965ULL, 0x0A0B04378CDF11F0ULL, 
            0x5C98B936090D3A86ULL, 0x95915B14960B76B7ULL, 0x97DAAD37CF34F931ULL, 0x8221E2FEF3C7DD2FULL, 
            0x6ABF21365E75113BULL, 0x20F2F15CBD6F499FULL, 0x8E56A4219A42822CULL, 0x38DA43EB35942A34ULL, 
            0xDB246799E30EB01DULL, 0x66D1C98EB6C8BE2CULL, 0x957D55507DD37146ULL, 0x393646A1D538BD2DULL, 
            0x6050B223930AE639ULL, 0x44B6A22F7CC2F260ULL, 0xE922591D9C7B4D5DULL, 0xC450F2A796DFF231ULL, 
            0xD4DF8AB5EFD6EE09ULL, 0xFE28578777E76135ULL, 0x9342F6A5130D294FULL, 0x3C1426B823B481FDULL
        },
        {
            0xA485BE07E962D3C8ULL, 0xCE4834F3DFEA056EULL, 0x2419CA51EC6684D2ULL, 0x204381B23DD51F48ULL, 
            0x1FDFA015AB009E00ULL, 0x8E19C1F26E05162EULL, 0xA3852C067F29893EULL, 0x418F4767A040B417ULL, 
            0x3A902DAB53DDC0E1ULL, 0x7A92A36C92BCC825ULL, 0xBF631FE66A15DA51ULL, 0x16DF22D8D8E1E5A4ULL, 
            0xB17CCB80E7798462ULL, 0x5A8B5868F5E08B48ULL, 0x01526430ADD0481EULL, 0x6BFBF7B6AE99B5A8ULL, 
            0xE94CDDF27CC95018ULL, 0x7D8894BF9055C28FULL, 0xD3EF319C85822C10ULL, 0xFD996DC1A8195D87ULL, 
            0x894021E088C48AE3ULL, 0xF5535E8293945163ULL, 0x2A367508EC8645B0ULL, 0x19FB335244C2FC04ULL, 
            0x563795072D789A5BULL, 0x0ABD9585A7B7727EULL, 0x4E90CB08BB786161ULL, 0xC3C3CBC9DEA19CADULL, 
            0x15F53F06C862FB54ULL, 0x97472FBD386B6F64ULL, 0xB17FB9B33FA88402ULL, 0xE57C974DBE12508EULL
        },
        {
            0x0AAE1616B2A9CC90ULL, 0x9709F21A99E4B5AFULL, 0x1F68ABE7D1F5CB06ULL, 0x92F2D5555C225640ULL, 
            0x0EAF8B2BB6EF31D1ULL, 0xDDB34050753FB8B8ULL, 0x4B3818BFF180455BULL, 0x51DC4E6A878F4AF1ULL, 
            0xD97B91F82BF705FCULL, 0x0B66D22D59C1C169ULL, 0x8BA72AEB9BB660DAULL, 0x331A33E729C572B7ULL, 
            0x6EF9BB218C8D3D9BULL, 0x8F018A4E5DBD2173ULL, 0xF420A299FEA23427ULL, 0xD31C42BBB46296AAULL, 
            0x129258E26C59CF39ULL, 0x2EFCB56F2346C847ULL, 0x724C95487315DA78ULL, 0x48CA98E3EC4C99CDULL, 
            0xA72FA5B0788F25C8ULL, 0xC43DEBCC4E64EC4EULL, 0x7C6DAD2087A40317ULL, 0xC435FDF9BE0804B1ULL, 
            0x206092BEC413FC0FULL, 0x61EFA8AB2D376FB6ULL, 0xF0CA9A9F048E666FULL, 0xD372038A6368A2EBULL, 
            0x4CADED85786932A3ULL, 0xD2096A70CFEAC10FULL, 0x2D5DEBC535688D7CULL, 0x99DDBA1BDAF17671ULL
        }
    },
    {
        {
            0x74682EE6239958D0ULL, 0x10F101CC1459D1DAULL, 0x96B0466C93432E3DULL, 0xD74DB78C7B9D8E81ULL, 
            0xDC6C31B3C4D83A5CULL, 0x98FB74E70E40D6E3ULL, 0x60EF1699D308B8D7ULL, 0x8AB81712DAA53078ULL, 
            0x394396C844036895ULL, 0xC555AB1D574C1853ULL, 0x5158752CD7A68B43ULL, 0x10F252E289FC38D0ULL, 
            0x2C98A59F95F41F2EULL, 0x3C8932C62275E95EULL, 0x4087920ED1477520ULL, 0xD40634AF6498B19AULL, 
            0x5ADDA7335B41C710ULL, 0x9ECC3349C077E2ACULL, 0x416DBD68C5FA50A8ULL, 0xB8C9EB4BE76814A2ULL, 
            0x15C47D2C814DAE85ULL, 0x6024975FEACA54B7ULL, 0x13443B35F5C3E496ULL, 0xBC1A0B25338D8328ULL, 
            0x22BAE6143DD32012ULL, 0x8A816CC5E257FA9CULL, 0xB973426FDAF6FE39ULL, 0x9F2467E1F6AD5D07ULL, 
            0x53910D7E76244575ULL, 0xBF182D54BC39AADFULL, 0xCE999C4D89820D5CULL, 0xC6B53E8C3FD755A6ULL
        },
        {
            0xD0DE7F318B57FE72ULL, 0x2BF03BA271C71AC0ULL, 0xE7B6410679AC582AULL, 0x520C22FDEA7DF9FCULL, 
            0x56E9C719B810BB4EULL, 0x3F8B92DB88C96A5EULL, 0xD9D2F1307C3F4144ULL, 0x117BB4EE45B50B46ULL, 
            0xC09CBC260865D384ULL, 0x1CA0184AA005A0F6ULL, 0x038D0FC94BD74A35ULL, 0x894CD1372FD4E84DULL, 
            0xDAAFC1922DFE02C5ULL, 0xE68538F076B1DE4DULL, 0x04F974CF97FA79C0ULL, 0xE41EB2C297834248ULL, 
            0x64D2E3FF37477CB5ULL, 0xD2A0836F3204507AULL, 0x753AA4BE57768960ULL, 0x375CA664CB994506ULL, 
            0x5EA9B68D27B2375EULL, 0x1B3FAE23FBA9504FULL, 0xD486216DDF409863ULL, 0x2E8F7DA6963D4404ULL, 
            0xBC24B51CAA09A3F3ULL, 0x0FBD4DEE0D645E95ULL, 0x2A8750F48220FD57ULL, 0x5317EF7CDE00C3CEULL, 
            0x0BA9C47D9B9B325CULL, 0x1B1506BE10FC5F6AULL, 0xF21676627F26F39FULL, 0x21F0EF3AF4596310ULL
        },
        {
            0xF8B820EAEBE5CA3EULL, 0xD7EE136C22A78025ULL, 0x53DD095B1919553AULL, 0xEEEF0C2C3B21200AULL, 
            0x28628B35E949216DULL, 0x66D30E3C2A6C735BULL, 0x1C3A39A0D10C7DBBULL, 0xDBD9F25173FB6AE1ULL, 
            0x313F6B0B5F7B5E11ULL, 0x60C5085071F7595BULL, 0xBA5C7E4D679E288AULL, 0x036EE6E3139CB804ULL, 
            0xFD4C80D43D78417EULL, 0xC5EFACE1DBEFB7D3ULL, 0x5CAD9502569B2DD6ULL, 0xB79B824A913689F4ULL, 
            0xA61AE111EEA16F78ULL, 0x9CA26D7E334D3B6FULL, 0xEAE041B75161563FULL, 0xFF97C79C95205AD2ULL, 
            0x35D617DB79796B25ULL, 0xC78EF49522B1404CULL, 0x42D4DB60A978B6C4ULL, 0x17CB7C8C4A94B55AULL, 
            0xE3345BEE4A45D77FULL, 0x1E8D9822C8E14B3EULL, 0x44E0E61A60B9A546ULL, 0x3B6C8E75A9557EAEULL, 
            0xC21BB68CCFA67E84ULL, 0xA873A7913067F16EULL, 0x4C87DC08D9C1933AULL, 0xE4364DDE5EBDF3EBULL
        },
        {
            0x8726B75E18565F41ULL, 0x3918227E018FEAF9ULL, 0x42D8DCB6894E08EFULL, 0x649A5FAE4AC90FDCULL, 
            0x85E455161A7D2729ULL, 0xA35F94D0F0863206ULL, 0x7F2F10A6037C5718ULL, 0xD9FDC9FEAC28AE21ULL, 
            0x44C69BFBD5DC72D3ULL, 0xBCD7ED5F38D1AE2FULL, 0x6E0C252A97FBC5EEULL, 0x451A8EF38B230C9EULL, 
            0xAD316CD595EA331FULL, 0x566808086B303708ULL, 0x0301818DC9612B8AULL, 0xB379E3F6EFB8CE0AULL, 
            0x02A36CF4A95B75E3ULL, 0x2C75FD195769D5BAULL, 0xD0B862C2C97AD1A9ULL, 0x5AB541E70895850DULL, 
            0x30FB37057D92CCECULL, 0xEC44E752E418086DULL, 0xC44BD5DE513B26F9ULL, 0x570AB4EE13A4D3D2ULL, 
            0x73F0F71987D44B84ULL, 0x573AD4F5E682EFDCULL, 0x0192577AAD37D1C1ULL, 0xD91D3FFB601D4113ULL, 
            0x7761068FD1C09FD7ULL, 0xA25C90043D3DE261ULL, 0x216513C6B82E9F2FULL, 0xAEA0B58729DFAF5DULL
        },
        {
            0x09DFB65DB4D81A50ULL, 0x861E8AABEFDA8813ULL, 0x14306A9B0EBE9C1BULL, 0x1B61316D4720226DULL, 
            0x5665DE8E3311A07CULL, 0x947019CCBA3820E5ULL, 0xE54AC62C7042AC7FULL, 0x1731CF1551BEAA6FULL, 
            0xAA37C5168844A82DULL, 0x153804E625EFF4CEULL, 0x805ACF7147300678ULL, 0x316B5AE26DC418C5ULL, 
            0x48B62756F50A2DCAULL, 0x59C615D249602B54ULL, 0xC79E97C14D642C51ULL, 0x243B068D6BDACF54ULL, 
            0xD6454E28DF651EE5ULL, 0x29ADA190E375ADBFULL, 0x910D4C2E33DF692AULL, 0xCA8F0D34E36CD860ULL, 
            0xD172EC43AE1D1ABCULL, 0xA1ACDE8840B5A2B3ULL, 0x08C55CBA4B57497EULL, 0xF4BC2649FE4712B8ULL, 
            0x59E721A9D41FD106ULL, 0x3EDCA1070E23A033ULL, 0xD6C413CCF900B91DULL, 0x861994B53AA6ACEBULL, 
            0xEBD6739B15959F39ULL, 0x26924FAA9884ECA2ULL, 0xDB9D4033146B7F0BULL, 0x86BB8A60F459F5AFULL
        },
        {
            0xD38097392EC61179ULL, 0x149A891B78DD7F45ULL, 0x22D92FF1A9078231ULL, 0xBB32A00D2F954FA6ULL, 
            0xCFF1F201B85E0817ULL, 0x29E7EDFD3754D034ULL, 0x0D5F0428DA27B6BEULL, 0x8E8C083170FD436FULL, 
            0x626710A008EFA2A9ULL, 0xCA36CB4730ECB5E9ULL, 0x4488737617A281AEULL, 0x6C11499389863B67ULL, 
            0x5D7C9DD147E48F24ULL, 0x435E64DA3590E600ULL, 0xE0E7D8678D01F586ULL, 0x21DA7C10D8D86F11ULL, 
            0xC6DC2D444111B535ULL, 0x812C29B5736A79B7ULL, 0xD436E62B22901BB4ULL, 0xD2F7A55C5DC908A9ULL, 
            0xF3E411E371C13199ULL, 0x8A3909FDEFD26280ULL, 0x5F807F4AE8025FBEULL, 0x3E0C43EED29A92F1ULL, 
            0xF08B359F790DD888ULL, 0x9EDD3FF25C2DF932ULL, 0x809C698A568CD823ULL, 0x391A0634A412093AULL, 
            0x1C850B6920946349ULL, 0x758CEB529914C44AULL, 0x510D81F938EA7479ULL, 0x99765DCCCFE64DB6ULL
        }
    },
    {
        {
            0x27101BAFE0C642E3ULL, 0x7F6F58E9DBB0475AULL, 0x4B841F56AF98A3D7ULL, 0x9B338B73C3CCAEEFULL, 
            0xBC8ECC634DFCDBEDULL, 0x9014C1151E839F62ULL, 0x1645B6172D6759F4ULL, 0x951082F799E3F870ULL, 
            0xE199110140A29B07ULL, 0x06D2CB24F90624FCULL, 0x50A344382B38A941ULL, 0x22385FC10D279CB5ULL, 
            0xD1176FCF4421B8AEULL, 0xB9DB25FC1D6E7347ULL, 0xA40B481682AFC43EULL, 0xF9BAFD42E5AB4CA1ULL, 
            0x2C32F2292175FD97ULL, 0x66DC82D2395C05AEULL, 0x773078433C60698CULL, 0x2BB1B6E3C3DA5998ULL, 
            0x4F976CB90F811B64ULL, 0x6A94972F9B0EAD3AULL, 0x974EDB4A18F792CDULL, 0xCB2A60E29FED31B9ULL, 
            0xE969D03F4A46FB31ULL, 0x2338E7974273876DULL, 0xEBB68ED269FAF67FULL, 0x57539F1C479E2842ULL, 
            0x47A30CDF43EF6346ULL, 0x8FAA06AB44BC2933ULL, 0x3D578A840D44FBC7ULL, 0xEF39051F34FBD1B5ULL
        },
        {
            0x5F52117D3E60FECEULL, 0x24F549E73435A1EFULL, 0x052706891C28012FULL, 0xF01FBD7EF03EC3EFULL, 
            0xD8C5C23D7CA38664ULL, 0xD70826BBD5C8E9A6ULL, 0x3BE4541ADA3299EDULL, 0x0952B7C4848C99EDULL, 
            0x250AF720D4F60CA9ULL, 0x7785A2C0A9A1C002ULL, 0x6B052AB0E019FF3EULL, 0xD70EA3C76749558BULL, 
            0x3E0CD2CDFDC72F61ULL, 0xBA93A09176C614C1ULL, 0x80953748A59A944BULL, 0x7277EF37EE801FE8ULL, 
            0x307D401C437A636FULL, 0x5AB012E397A6C1B6ULL, 0xCC49332377767BFAULL, 0x506DF15955A84477ULL, 
            0x09FD02DDBD6EDD1DULL, 0x2B5D8911E390A975ULL, 0x8FEA96B4C7431183ULL, 0xEE0B2C0107D8EA47ULL, 
            0xF6F95974A32D6E1FULL, 0xB1E30C45CEBAA72FULL, 0xFD5EBB9631A74C24ULL, 0xA36E15BAAF59B817ULL, 
            0xF0E9EC8E172B4EA7ULL, 0xBCFB2A00E649F1D4ULL, 0xE7A8A9A70D517827ULL, 0x9021BCFC243482C4ULL
        },
        {
            0x949960344B6869F1ULL, 0x000EB6167D5D3FC5ULL, 0x66E5ACE03FB49F62ULL, 0xD839F84382DA8E29ULL, 
            0xEA95BD47756088D0ULL, 0xDD1C529C8EC7E930ULL, 0x77118CC28D180E35ULL, 0xCFF8662B30AED10FULL, 
            0x09C1DD6267FA19CDULL, 0x7BFCEA1E67A8A8D9ULL, 0xA637584BCD12996DULL, 0x8BADEFF4A0172E3BULL, 
            0x3CBEDA0E055F81C7ULL, 0xBD2BB8BE7DAFF0E5ULL, 0x46DC0279F93B551BULL, 0x8946A0D41128E750ULL, 
            0x25F5D7005011BC33ULL, 0xB3E39E9236D457A9ULL, 0xF4FB05056BF81586ULL, 0x4259D5AF59D492F5ULL, 
            0x04A08343E970A24DULL, 0xD8825C66409364CBULL, 0x8024E1DD92C0E25CULL, 0xE8F4F4B5DF808290ULL, 
            0x15BCB89A6EF6C9D1ULL, 0x38FBED758DD38924ULL, 0x30BAAE28F976E85CULL, 0x8C3157179E411FB7ULL, 
            0x4BC921B202C2BD77ULL, 0xAFB370DC054A5840ULL, 0xB6E88C9029A27FEAULL, 0x0AA82ED366446303ULL
        },
        {
            0xD66FA492190C3B9DULL, 0x2B37C7B8FB1AEE5FULL, 0x691353C290BAB23DULL, 0x309B03A6C1C49393ULL, 
            0x03503EFA0D6C66E8ULL, 0x86A7E7CFECAF98B4ULL, 0x754910306A2E4A81ULL, 0xB37A0DBD3BC042DBULL, 
            0x6B755D653ECAE21EULL, 0x8FB7B542D3F6CAC8ULL, 0xF7E1AD75B47B5E2DULL, 0x898925890ACB63C4ULL, 
            0x5A374697BE011F87ULL, 0x5EDA5B0E567451F2ULL, 0x71276257837A0172ULL, 0xE5009E611F6639A4ULL, 
            0x660FD91B438AE919ULL, 0x0EB09B6A56538B82ULL, 0x4B2FD809E2730787ULL, 0x3241A9AA72CA1301ULL, 
            0xBA8AFF58BABE81DCULL, 0xFA3A7A28C0BF388CULL, 0x32BB30721945239BULL, 0x086C232FA0E9B5AFULL, 
            0xC558DCD93D2F86BFULL, 0xE18A01A79F992CC1ULL, 0x0225E8F272056E1FULL, 0x5B4574761778FFE3ULL, 
            0x479D91F3D5E39595ULL, 0xDB91477D0F006143ULL, 0x09DEE66D7A5FA745ULL, 0xB5FE376D06AD3399ULL
        },
        {
            0xA266C18A60A9F435ULL, 0xEC5A8DE19FD2B299ULL, 0xCFDB58191F8CC30DULL, 0xE30778759E1A8E44ULL, 
            0x6F32F46C966C809FULL, 0xDC39E3FFB50F0AB8ULL, 0x677AF78C005720C3ULL, 0x687F4762FBEBFAF9ULL, 
            0x47F768DFB74E32E0ULL, 0xB70DDCFA3B93F7B0ULL, 0xCD0B79ABAD6DF018ULL, 0xD3A7F31948D44272ULL, 
            0xECE1B2C3F3931B90ULL, 0x2837BC63AEC413CFULL, 0x1EF38F52E0BB0CA3ULL, 0x11C6D3C6520BE4EDULL, 
            0x0D4390B72B18BF6BULL, 0xD4557E9EE1B2208AULL, 0x39DE57D2D704E20CULL, 0xB0B964B89656F66CULL, 
            0xD08CFB129D23E270ULL, 0xC010F5E7E37EA7FDULL, 0x4FBBA3ABA34B88CDULL, 0x0C7283C9B3DEE6EEULL, 
            0x9F2CF7565F91262FULL, 0xDB03FE176EC39444ULL, 0x6CFFFA371C8B901BULL, 0xA2CA9F1392B134A1ULL, 
            0x35A5D24C0C71124EULL, 0x811D3E143458AAEEULL, 0x3E65B4E238C30CC8ULL, 0x198EC72470BD408FULL
        },
        {
            0x362CACD4D76FE05BULL, 0x378B3A2724F0A091ULL, 0x9F2BCA98B0B70BD8ULL, 0x2EC348D17670C3C7ULL, 
            0x0C46F2F5E16EF432ULL, 0x6F74E8D4F7B34C42ULL, 0x587B592812185D48ULL, 0xC846AFD5EF7D7277ULL, 
            0x1888B05821EACD8BULL, 0xF4FB1DEA5C72361AULL, 0x27953DAC1875E1AFULL, 0xEBC41504C213CB34ULL, 
            0xD15E1E0D35482289ULL, 0xEDB59F64797B4C64ULL, 0x100AB8131963BA10ULL, 0x40C8AA43E9E37978ULL, 
            0x9C8DE6B251D41F5FULL, 0x50E8A08A340EA10AULL, 0x3086443467336783ULL, 0xD6B520E11451E48DULL, 
            0x35C64FF80C727883ULL, 0xE6914A46D0E344B5ULL, 0xA403FAF4DEA22C69ULL, 0xBC9BC0EE290A6D75ULL, 
            0xCDBCB958C440E456ULL, 0xA9216AAC938CA0C7ULL, 0x67AAD797B2E0FAF0ULL, 0xAB5BFDD965853874ULL, 
            0x940EB5BE3B6A4135ULL, 0xAA3CE64737707FFAULL, 0xDD22B9FA7E1FAA30ULL, 0x41B915F1D9B9A247ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alcor::kTwistConstants = {
    0x853ED9CA2A54FEB0ULL,
    0x579273F810AAE7A6ULL,
    0xB0B644AE35EDE196ULL,
    0x853ED9CA2A54FEB0ULL,
    0x579273F810AAE7A6ULL,
    0xB0B644AE35EDE196ULL,
    0x223D651EAB5EE971ULL,
    0xCBA30560D9E7DF4CULL,
    0x83,
    0x21,
    0x7C,
    0x47,
    0x1A,
    0xE5,
    0xA5,
    0x0B
};

