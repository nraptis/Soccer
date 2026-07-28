#include "TwistExpander_Alkaid.hpp"
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

TwistExpander_Alkaid::TwistExpander_Alkaid()
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

void TwistExpander_Alkaid::KDF_A(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Alkaid_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Alkaid_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Alkaid::KDF_B(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Alkaid_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Alkaid_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Alkaid::KDF_C(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Alkaid_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Alkaid_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Alkaid::KDF_D(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Alkaid_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Alkaid_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Alkaid::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA11372984ADF580FULL;
    std::uint64_t aIngress = 0xA6F928323170709DULL;
    std::uint64_t aCarry = 0xD10122E3BD40561EULL;

    std::uint64_t aWandererA = 0xC9A689724E3551E5ULL;
    std::uint64_t aWandererB = 0xAD7DAAD56857141FULL;
    std::uint64_t aWandererC = 0xEE3DBA741367B755ULL;
    std::uint64_t aWandererD = 0xF54C4CE8EA4257C8ULL;
    std::uint64_t aWandererE = 0x8782C4AE57EB7E3FULL;
    std::uint64_t aWandererF = 0xD00E049146C426CBULL;
    std::uint64_t aWandererG = 0x96CCFBF681BEEE5AULL;
    std::uint64_t aWandererH = 0xFA44704C86E4E65EULL;
    std::uint64_t aWandererI = 0x9A0D46BE47D75D26ULL;
    std::uint64_t aWandererJ = 0xD3C1901CC31C9717ULL;
    std::uint64_t aWandererK = 0x9712CA9013ABE70BULL;

    //
    // KeyRotate A
    //
    aPrevious = 0xC621DEC43976103AULL;
    aIngress = 0x988D01C70DEBF21EULL;
    aCarry = 0x9A4008803FDB6BA3ULL;
    aWandererA = 0xD07FA7B05EA46A69ULL;
    aWandererB = 0xA4FFAB2ACC7BEAB0ULL;
    aWandererC = 0x89709410F5D04B96ULL;
    aWandererD = 0xED9E53B56692FC71ULL;
    aWandererE = 0x9ABD1475261731F0ULL;
    aWandererF = 0xB2EE9038C6032C81ULL;
    aWandererG = 0xDC0833C9FEE5BE5BULL;
    aWandererH = 0xEC5A1AA318E82F18ULL;
    aWandererI = 0xB3AC1FD6DCB15E49ULL;
    aWandererJ = 0xDC61AE3BE1FC5CC9ULL;
    aWandererK = 0xD1D86ED2829F5177ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateAConstants), &(pWorkSpace->mDomainBundle.mKeyRotateASalts), pSnowLaneA, pSnowLaneB, ARX_STATE_VARS);
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
    aPrevious = 0xC8A3F430D198F28EULL;
    aIngress = 0xF0664D7A9A4F2B72ULL;
    aCarry = 0xB43BD2EDA5A55CADULL;
    aWandererA = 0xD79A71C93D8851A1ULL;
    aWandererB = 0xA54FDC705EE0578CULL;
    aWandererC = 0xE2C7DB765265772FULL;
    aWandererD = 0xC76B43808EA4DB36ULL;
    aWandererE = 0x96B4BA59BC9D42DFULL;
    aWandererF = 0xD06538EE46D8DFA5ULL;
    aWandererG = 0xE36CEA8F6EEC0C0AULL;
    aWandererH = 0x90A91FB5653D42E7ULL;
    aWandererI = 0xD813FA415DA9EE03ULL;
    aWandererJ = 0xE12975948E7A5AFFULL;
    aWandererK = 0x88DFD627D5973F9DULL;
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants), &(pWorkSpace->mDomainBundle.mKeyRotateBSalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0x997695B6914EF30FULL;
    aIngress = 0x8AB3DD8F61AD9652ULL;
    aCarry = 0xCD93528B9480EA06ULL;
    aWandererA = 0x80C1FDFD355EBF4FULL;
    aWandererB = 0xB66AB553346E7CBCULL;
    aWandererC = 0xB56B6C4E52FC256AULL;
    aWandererD = 0xB86BACFFFD79554AULL;
    aWandererE = 0xC06291F5D0BF6CE6ULL;
    aWandererF = 0xF2C2095E8A262752ULL;
    aWandererG = 0xAB9E269047C598ACULL;
    aWandererH = 0xDAC5FD653315CDEDULL;
    aWandererI = 0x948A0C289198EE8EULL;
    aWandererJ = 0x823C5099551A6F84ULL;
    aWandererK = 0xD2ED0CCB227BC207ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnAConstants), &(mDomainBundleInbuilt.mKeySpawnASalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnAConstants), &(pWorkSpace->mDomainBundle.mKeySpawnASalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeySpawnASalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeySpawnAConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnAConstants), &(mDomainBundleEphemeral.mKeySpawnASalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0x82D2BE3AA9DC1F06ULL;
    aIngress = 0xF96C44614054D892ULL;
    aCarry = 0xFCBBBBD5C25E8970ULL;
    aWandererA = 0xF2834C6C8D26A1BDULL;
    aWandererB = 0xA9C1D8134E0166F7ULL;
    aWandererC = 0xA606B32A7BDBFFB2ULL;
    aWandererD = 0xAE2AED987BFB7DB2ULL;
    aWandererE = 0xEEA77A67CDC6A61CULL;
    aWandererF = 0xB33993D335BB4104ULL;
    aWandererG = 0x837486FB3930E318ULL;
    aWandererH = 0x874183667CE6E98CULL;
    aWandererI = 0xBF10631470669281ULL;
    aWandererJ = 0xF7B41F5B5605502EULL;
    aWandererK = 0xF16F569ABA7AA3A0ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnBConstants), &(mDomainBundleInbuilt.mKeySpawnBSalts), pSnowLaneC, pSnowLaneA, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeySpawnBConstants), &(pWorkSpace->mDomainBundle.mKeySpawnBSalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xFE41688E4E415960ULL;
    aIngress = 0x98EDA85966BB5A64ULL;
    aCarry = 0x9E8237807FB04A14ULL;
    aWandererA = 0xC92F78342B614437ULL;
    aWandererB = 0xCD0CF598FDF5B7CAULL;
    aWandererC = 0xEE84190BE28F59E7ULL;
    aWandererD = 0xE6F13B739E012413ULL;
    aWandererE = 0x92F08A8F08591489ULL;
    aWandererF = 0xC981BBF31F77E092ULL;
    aWandererG = 0xED7585134417B0C8ULL;
    aWandererH = 0xE912423383BDBA62ULL;
    aWandererI = 0x95EACC0FA37B0C7AULL;
    aWandererJ = 0xB1D68687B543C711ULL;
    aWandererK = 0x999A46D1E525A45AULL;
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mTwistConstants), &(pWorkSpace->mDomainBundle.mTwistSalts), pSnowLaneD, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0x80FAD40A7E985C65ULL;
    aIngress = 0xDA1C81E5415CA4A8ULL;
    aCarry = 0xAB1F9FDD89CB2CFEULL;
    aWandererA = 0xDDA38985493744A7ULL;
    aWandererB = 0xDD30E9749AD36723ULL;
    aWandererC = 0x9C0703C585579645ULL;
    aWandererD = 0x91C9BEC6A5BF93B3ULL;
    aWandererE = 0xE2488E2715B26B19ULL;
    aWandererF = 0xDA7F65F481674A1CULL;
    aWandererG = 0xD94EFF98F9336352ULL;
    aWandererH = 0xA8B00DB1FAB0035EULL;
    aWandererI = 0x9573AB415CC00F96ULL;
    aWandererJ = 0xF2260339AE44A905ULL;
    aWandererK = 0xAC3F845DE084B5D2ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mSeedSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0x8B5DCC702F9AE9A7ULL;
    aIngress = 0xB69312E63E744B4EULL;
    aCarry = 0xA8F27279BBBCDE8FULL;
    aWandererA = 0xA9C0D3C82AD60E04ULL;
    aWandererB = 0xFB5159C4E78650A1ULL;
    aWandererC = 0xFA5475A2AA54E809ULL;
    aWandererD = 0x80DA3032606E49F8ULL;
    aWandererE = 0x92B66FEE67883B20ULL;
    aWandererF = 0xB4E3685DCCA5F498ULL;
    aWandererG = 0xE587D9980C8E73DEULL;
    aWandererH = 0xB991BE8AD6F558BBULL;
    aWandererI = 0xE4C0D60D63C1CF6DULL;
    aWandererJ = 0xE3E1A3556738210CULL;
    aWandererK = 0xD14B0DE2052655D9ULL;
    //
    TwistExpander_Alkaid_Arx::SEED_A(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alkaid_Arx::SEED_B(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alkaid_Arx::SEED_C(pWorkSpace,
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
    TwistExpander_Alkaid_Arx::SEED_D(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alkaid_Arx::SEED_E(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alkaid_Arx::SEED_F(pWorkSpace,
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
    TwistExpander_Alkaid_Arx::SEED_G(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alkaid_Arx::SEED_H(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alkaid_Arx::SEED_I(pWorkSpace,
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
    TwistExpander_Alkaid_Arx::SEED_J(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alkaid_Arx::SEED_K(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alkaid_Arx::SEED_L(pWorkSpace,
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
    TwistExpander_Alkaid_Arx::SEED_M(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alkaid_Arx::SEED_N(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Alkaid_Arx::KEY_A_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alkaid_Arx::KEY_A_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alkaid_Arx::KEY_A_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alkaid_Arx::KEY_A_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alkaid_Arx::KEY_A_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alkaid_Arx::KEY_A_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alkaid_Arx::KEY_A_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alkaid_Arx::KEY_A_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alkaid_Arx::KEY_B_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alkaid_Arx::KEY_B_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alkaid_Arx::KEY_B_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alkaid_Arx::KEY_B_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alkaid_Arx::KEY_B_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alkaid_Arx::KEY_B_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alkaid_Arx::KEY_B_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Alkaid_Arx::KEY_B_H(pWorkSpace,
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

void TwistExpander_Alkaid::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xC7F51E1CC8945356ULL; std::uint64_t aIngress = 0xD09D1ACE573041C0ULL; std::uint64_t aCarry = 0x8B161D3A420CE2DDULL;

    std::uint64_t aWandererA = 0xF2FE0FB89EE2A258ULL; std::uint64_t aWandererB = 0x9567F8FE2981E63CULL; std::uint64_t aWandererC = 0xFED3DAF371F2AF5FULL; std::uint64_t aWandererD = 0xD64C16E39A149585ULL;
    std::uint64_t aWandererE = 0x8BAECBE3EA33E28FULL; std::uint64_t aWandererF = 0x9EE39AF6DF5084F4ULL; std::uint64_t aWandererG = 0xC48AC2FE143ED543ULL; std::uint64_t aWandererH = 0xEB7348FA469E75CBULL;
    std::uint64_t aWandererI = 0xFEECD73E0E8D3A54ULL; std::uint64_t aWandererJ = 0xA5836DAC9C61BFE2ULL; std::uint64_t aWandererK = 0xA1249996A4DA3307ULL;

    // [twist]
        aPrevious = 0xFA016544A76E854AULL;
        aCarry = 0xC0D9CEE0EA333675ULL;
        aWandererA = 0xC427EBEEC08BEA5FULL;
        aWandererB = 0xEA363B61F1D1D0B1ULL;
        aWandererC = 0xB656D5706D6C9C42ULL;
        aWandererD = 0x8CCC448AB9AE9136ULL;
        aWandererE = 0xE94ED96F51CB8F88ULL;
        aWandererF = 0x90D80E07E9A90E4CULL;
        aWandererG = 0xAE9AEDFE95BE1AACULL;
        aWandererH = 0xC6F4A4BB53A01D28ULL;
        aWandererI = 0xB5B7916FFA1F2B68ULL;
        aWandererJ = 0xA1417990839C5757ULL;
        aWandererK = 0xC7768F75087C43A8ULL;
    TwistExpander_Alkaid_Arx::TWIST_A(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alkaid_Arx::TWIST_B(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alkaid_Arx::TWIST_C(pWorkSpace,
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
    TwistExpander_Alkaid_Arx::TWIST_D(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alkaid_Arx::TWIST_E(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alkaid_Arx::TWIST_F(pWorkSpace,
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
    TwistExpander_Alkaid_Arx::TWIST_G(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Alkaid_Arx::TWIST_H(pWorkSpace,
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

void TwistExpander_Alkaid::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Alkaid_Arx::GROW_A_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Alkaid_Arx::GROW_A_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Alkaid_Arx::GROW_A_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Alkaid_Arx::GROW_A_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Alkaid::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Alkaid_Arx::GROW_B_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Alkaid_Arx::GROW_B_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Alkaid_Arx::GROW_B_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Alkaid_Arx::GROW_B_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Alkaid::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 5 of 33
    // Exploration cases: 0
    // Structural maximin 566 / 674; family total 2273
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
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3918U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4008U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3828U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 137U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1960U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2005U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1780U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1645U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1375U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1870U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1915U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1465U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 5 of 33
    // Exploration cases: 0
    // Structural maximin 563 / 674; family total 2270
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
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7429U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3468U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3108U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7159U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 475U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 700U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 610U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 925U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 745U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 970U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1285U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 655U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Alkaid::kKeyRotateASalts = {
    {
        {
            0x0CDD1FAFBDB034E9ULL, 0xD88C216FE700F514ULL, 0xCF4979D95274FA61ULL, 0x7ADEC77D48D3CEEEULL, 
            0xAB5C48A4105804AEULL, 0x34A5B2BF994E90EAULL, 0x5FECF99052254FBDULL, 0x7698D904CD0E4436ULL, 
            0x99AA4DF3E31A14A2ULL, 0x2B98F250FD5817E4ULL, 0x7C1DD7E8720A98F3ULL, 0x1E64B649A1823DF4ULL, 
            0xF3EC8D789138E131ULL, 0xB064F6D1E0D6B282ULL, 0xC7A44A357E813DC0ULL, 0xD7760324BC506D0BULL, 
            0x219931102CC5DE5CULL, 0x920FCC4389449714ULL, 0xEC4B388383B4D047ULL, 0x95BFA08BB91F2B2DULL, 
            0x909721DB2BBF6A03ULL, 0x78EED01C99790876ULL, 0x2EAD10086F2BF1E1ULL, 0x98F46DB9D8214831ULL, 
            0x7E0A45E14D93F0DFULL, 0xB768E1EA1F7B5B04ULL, 0x22C25311BBC82013ULL, 0xE5180E32111E3DF7ULL, 
            0xD138C94A5B06DB57ULL, 0x76CBA87A1E914935ULL, 0x9E6B72B8D0C2CAF2ULL, 0x1E07374D1DABB884ULL
        },
        {
            0xCB66EE2B67979662ULL, 0x77CD8FCA3E27C6EFULL, 0x3BB4377489F5C74EULL, 0xA94C208287300CA3ULL, 
            0x249F693F36A6279EULL, 0xDFC58719EFF49556ULL, 0x3DF0FDA9B8AA4CBFULL, 0xC4CEE479FD8D1310ULL, 
            0x84EBD50A3F2D92A5ULL, 0xC0AA4BA05DD60F99ULL, 0xB06639666983A676ULL, 0x2BF2B472301B2019ULL, 
            0xD3D3C8AE3555A761ULL, 0xCF8ACBBA181CFE88ULL, 0xE46C2009D91ACDA5ULL, 0x84FEA82244B799BDULL, 
            0xBC02A93631743271ULL, 0x6B88E70A23DAE055ULL, 0xC8A912869F306CD7ULL, 0xBE908AC41669E7C6ULL, 
            0x9F274824AA6B7B71ULL, 0xDCE0288DBCC19AD8ULL, 0x675506048B1836A2ULL, 0x3F3E0E2BD2443836ULL, 
            0x4C88EE725F917E84ULL, 0x4B6C281BEAB73EE9ULL, 0xADF59ECCDA9B36E3ULL, 0x1D07700C669AA129ULL, 
            0x83FC1CB53329E815ULL, 0x5684EFD4D6D51D63ULL, 0x2B75B01A5DDB140AULL, 0x15C36472084E55EAULL
        },
        {
            0x79FF656A59C7D664ULL, 0x219CCE137F9E6522ULL, 0x3BAC536A80B79CF2ULL, 0xDFAB06344D700F4DULL, 
            0xA16801C346C3EF45ULL, 0x3281F9C268C8D312ULL, 0xA5C003B544019E05ULL, 0x432FC736FC653B7FULL, 
            0x29E07D4E80E21958ULL, 0x8633A79710B57B26ULL, 0xD9A7556DEBFB44ADULL, 0x01897B7A5902AC3DULL, 
            0xDFDA26360E6DD47DULL, 0x5094541FD3E6E0EFULL, 0x078F6F56AE8CC9A4ULL, 0x0675F38060E9D3EEULL, 
            0x30D7B984BE82C180ULL, 0x266A03DB88723C19ULL, 0x7A45AE7F2C1EB461ULL, 0x00D5E09EF62D6758ULL, 
            0x2B43DA828337997EULL, 0x98C5FD768348B0D8ULL, 0xB1089E1A06AE07A4ULL, 0x68BDA47E67F9BC4AULL, 
            0x74C4E45DCF975F7CULL, 0x94D555F5C1348CC3ULL, 0xED30E47B4EAB697AULL, 0x4230A92966D1A3C3ULL, 
            0x2DC2A8DA51B5E968ULL, 0xEB274056F64DB8AFULL, 0x0C52C3F92ACA7CD8ULL, 0x138D6DA388FC7758ULL
        },
        {
            0x7D0530BBB5A35D1DULL, 0x1E63E729815A8D65ULL, 0xD8B62AAD220036D5ULL, 0x53F7895470CFC959ULL, 
            0x1539B717A7350CF7ULL, 0x5D2597716C68986BULL, 0x21FBB4EE00B7D23DULL, 0xDCEF7B37C6EF2466ULL, 
            0x20CBD7EC20925DD9ULL, 0x105E4241D38EACEEULL, 0xCF4EE879764F64A9ULL, 0xB5C3E0CD4B3888A4ULL, 
            0x150BBF9F3C04D171ULL, 0x7A28C2D2F6515625ULL, 0x728C50E4DBEC2D2AULL, 0xBB8F49735BA2453DULL, 
            0xDDF8EAEFADB5C1E3ULL, 0xB5D0F71497864C73ULL, 0x0C0E60497530BA28ULL, 0x691115BE7B4A2CE0ULL, 
            0x32EDD14F0469D809ULL, 0xDDE4BBAF6CDA5D3DULL, 0x61A6FFD9C9676FBAULL, 0xA132286BFD693B5AULL, 
            0xE599E6DAA660F86DULL, 0xA98F5EA2D47DE285ULL, 0xC5D85D34130901D7ULL, 0x753BC3080AEABFA9ULL, 
            0x52AB8E245A63B678ULL, 0x2365E6EFCBC57468ULL, 0x614FF592632C463BULL, 0xD969032AC9B6599AULL
        },
        {
            0x077E6576A237360CULL, 0x57BDDFFBCD32639AULL, 0x464263188DF0EF54ULL, 0x73107E1ECC82312AULL, 
            0xB08554D13E0B5E9DULL, 0x767AFC8E9E0458FFULL, 0x1BE40F73D99A3489ULL, 0x24E64FD6A92CC3BBULL, 
            0x577221C367EBE99DULL, 0xFD84D24D797394F0ULL, 0x93D6BAAFE3E5931BULL, 0x76A9551BACDE7C85ULL, 
            0x4BBD3060D557C644ULL, 0x6DC435EB635B628BULL, 0xFF876B3E66F1F51AULL, 0xCC372A283CBF8D4DULL, 
            0x944668E23EABDB59ULL, 0xC6A77E6FE5B82C9FULL, 0x36EA8FB3CB954A57ULL, 0x93ED2842AB8B2E3AULL, 
            0x6631004FBD680F9CULL, 0xF3EB44C115C5C7CDULL, 0x9B521B0879D2544AULL, 0x1EC60532ACAAD893ULL, 
            0xA24418438A0A35D3ULL, 0x12FB52FFC4BB867AULL, 0xF7D24E30F7A89E0BULL, 0xBFD9130F31705EF3ULL, 
            0xDE0C36451A844C07ULL, 0xC828AEF6B2227C04ULL, 0xF394B2637EB3DB94ULL, 0xF970E7A35F59F31AULL
        },
        {
            0x713D6F15649BE20FULL, 0x86D8193857DDF407ULL, 0xEB5EAFBE37F58DECULL, 0x35198B066B0F4733ULL, 
            0xF4D39B835D4EB279ULL, 0x4F3E4E63B42A8C08ULL, 0x6857B11412775644ULL, 0x61EC43FFA6E14AFAULL, 
            0x93B5554EA244A2E0ULL, 0x1D994AC3D87F3DF8ULL, 0xD900812E4486A754ULL, 0x34702493B6775CBBULL, 
            0x1696365D6776AAECULL, 0xF8D0A08A9942F88FULL, 0x8E9EE7417C42F624ULL, 0xD372F3E7C9D9E496ULL, 
            0x0F5D3E3FD82E8FDBULL, 0xE09F09B5A2693BF9ULL, 0xA84CEAB6B1CB03B4ULL, 0xE32D90AF900D0A20ULL, 
            0xCA6D0A783D4B33ABULL, 0x2CD4812F3E12AD30ULL, 0xDC3648EF98FCF80BULL, 0xB5916CBAE761D8BDULL, 
            0xEFDFB4DE4BDACB9FULL, 0x6802981FD5E6D376ULL, 0x8A74F4B3401F1E3FULL, 0x4BD6E2F20F592655ULL, 
            0x9AC48E25593F9281ULL, 0x6926979D85CEAF1BULL, 0x39BC7CBAE64A4199ULL, 0x18C2629B50D27892ULL
        }
    },
    {
        {
            0xDA856BF6677DC889ULL, 0x39FC0B3D78A91A8FULL, 0x3F500A6DF6110707ULL, 0x57D26A13659B2BA9ULL, 
            0x9F1A40C3EF24F361ULL, 0x383CD85B693F6964ULL, 0x5B065D77FE419E6FULL, 0x48029607373E888BULL, 
            0xCD2EFC7B57BA3F36ULL, 0xD2A1946DE3E057C1ULL, 0xF1822293B93DB1FBULL, 0xAE4EF5E50F43E792ULL, 
            0x33EAF9793CEC55F5ULL, 0xBD8959257B7F2463ULL, 0xA5A4CEEF044B555FULL, 0x5FB2BEDD9F6AEB24ULL, 
            0x8DC677DBA493A197ULL, 0xE9AEA13DDC6ADCB4ULL, 0x6E549C2EC2965795ULL, 0x6C46637EDD49BBE5ULL, 
            0xACD3324D07766566ULL, 0x683179E2A2015930ULL, 0xC30274B5F978EF71ULL, 0xFA3E1E2F776CBF81ULL, 
            0xAF7A6E80DA87B2E3ULL, 0x18DCCCFB02DC49FEULL, 0x58BD09AF9B1BC3FFULL, 0x5AAC99037F665A9CULL, 
            0x07E7711DD62CFD87ULL, 0x6926D80A4BEA9DABULL, 0xEF3E5D5BC725DFFDULL, 0x6E933810E64DBE12ULL
        },
        {
            0x935AF8098449A86BULL, 0x1A149A647D8FAADBULL, 0x8D3247FEB4D426CEULL, 0x65E5AF5549696A6CULL, 
            0x65367066BF00AF2BULL, 0x98D9B69BB8CE7613ULL, 0x1B72EDCCDC43ED99ULL, 0x65152DEAF7850F2AULL, 
            0x2DF150BB649CB7EBULL, 0xE6826D2AD3D8B332ULL, 0x1070013FD1F376B4ULL, 0x1699A7D30E903B3DULL, 
            0x46FFBFE3E2486090ULL, 0xF1A30337E5793999ULL, 0xF12839336F5F39D4ULL, 0x14CBD6877E1D4CBFULL, 
            0xF123E8EE6FF3E2EEULL, 0xF52031D181E769B1ULL, 0x5049B4DB47DF6790ULL, 0xE20501E25408BE89ULL, 
            0x41C980B8F6EF6676ULL, 0xA18650E6817C631BULL, 0xBEC898B35F494F67ULL, 0x8C9154E88E02CDDBULL, 
            0x5E5F1CF25F2960DCULL, 0xD408B39EFF9BCA49ULL, 0x6825A733F055B9FBULL, 0x3C8ABADC64D1E39CULL, 
            0x7EE3722DEC5EB84EULL, 0x50109DA9DAAB1B8EULL, 0x6AD2E71A9A5E65BDULL, 0xDFB309E3CC516583ULL
        },
        {
            0x74583F51ED1310E2ULL, 0xAFFB9BB66463BBA9ULL, 0xCFC787ADE4796890ULL, 0xB5E5D4089A6668FEULL, 
            0xFCC7C5BC649D7D1AULL, 0x79E42E7BB4BFBD22ULL, 0xA955AF33971AE1BCULL, 0x7E80D566E55A66AEULL, 
            0x7C9052DC19EBF19EULL, 0x8F018F3CB91CBEA5ULL, 0x3DFF29750D86DC94ULL, 0xFA0ADD1144485721ULL, 
            0xE43E3E473F35867AULL, 0xC66835104FC657C3ULL, 0x6E8F8927C7A9C6E4ULL, 0x34FEF8924015AB3FULL, 
            0xA66BBD02014EC79AULL, 0xCDE2BA42E8DE7954ULL, 0xF337692514E92C93ULL, 0xDE21FF0B23276488ULL, 
            0x18C0F767D21F49CFULL, 0x05ED15AA077CAAA8ULL, 0x74A62F986AF4B3B8ULL, 0x039035B28D368EFDULL, 
            0x76C68057C16D1D08ULL, 0x5A81EAAB4FFA39BCULL, 0xDB73C83ECA229977ULL, 0xCC21918B3CB69992ULL, 
            0xA50B9295000D3BE6ULL, 0xA05E7D3AE373D6CBULL, 0xD699CD9CAF1E043DULL, 0xEC8E2D7EFECF3897ULL
        },
        {
            0xC7FC27C9F63DB079ULL, 0xE2981C34D2202B7EULL, 0x26EC1C81352462BCULL, 0x94988DB781BE9505ULL, 
            0x8D2CCD3B5E856FC3ULL, 0x17CD5020CBF4E8B8ULL, 0x29C1E563F35E2D71ULL, 0x837FC7D1EFABCDDEULL, 
            0xF60585AF37402508ULL, 0xB43C1C3E4E7F55B9ULL, 0xFE6F05185003DD10ULL, 0x9D1C31FEE447F986ULL, 
            0x30F272D51F0EF372ULL, 0x2747937526F660C4ULL, 0xFA2F64A5A08E9715ULL, 0x28E6774E3F7F3ED8ULL, 
            0xC64C2DE97A6674A6ULL, 0x66001D3C055C18B2ULL, 0xC38D170AE7BFBED1ULL, 0x68404506D53D1B68ULL, 
            0x886D57D68B079CD5ULL, 0x5C857000C1F07D9DULL, 0x7FF06587A2515B9DULL, 0x0FC57834ABF6C134ULL, 
            0xE0949876D3D3AFA7ULL, 0xE325237D0683D2A1ULL, 0x31C2F7BE625AA2C5ULL, 0x33D3392E31331972ULL, 
            0x10D67909184645C9ULL, 0xE382F5254F19B20CULL, 0x54E3191BE5228EEFULL, 0xA698EB6BF2EBC11FULL
        },
        {
            0x90DBA6C68BA4646EULL, 0x8003B8A43DC93CD4ULL, 0x55D04338727E9E69ULL, 0x1D5A208B8CF4D49FULL, 
            0x5D9BD55391EE28B9ULL, 0x17A2B2A43FF7860FULL, 0xD43A56AAE5D19D14ULL, 0x898C2B5751FFCA8EULL, 
            0xDFB5A981F2B1BF3BULL, 0xCDBF514CB8BABEE9ULL, 0x8DB8B0528187F8F8ULL, 0x311A5A7FB569BF92ULL, 
            0xC475716A916644E1ULL, 0x094B9F204C947252ULL, 0x7120063E62BA10E3ULL, 0x5C9D6F90D6721250ULL, 
            0x4521077F001EA93FULL, 0x34A1514F80D1EC26ULL, 0xF408D9488854B425ULL, 0x905E9E8B87344BA5ULL, 
            0xFD6580197C757E36ULL, 0xAEDDE6BF0DAFB8D3ULL, 0x1D5FC88DB544FA07ULL, 0x4B8CE89A988A92BFULL, 
            0x8F00A5F52D87810EULL, 0x29FB0D30B2878F07ULL, 0xCFCA7DF940F05DECULL, 0xBBD6C2DE0C3C511DULL, 
            0xE420198BE1237BDCULL, 0xD63C3747AEBEF06DULL, 0xDDD9F0BBA113932FULL, 0xD7029958B743CD9FULL
        },
        {
            0xBA7E67A12C2E9827ULL, 0x66C41C7F7580C074ULL, 0x08C65D88395AC90AULL, 0xB6C407E495EA5800ULL, 
            0xDBE8DD27464C2C95ULL, 0xB73C543A36E0FA47ULL, 0xECF277F1B17F86AFULL, 0xAADF32891E2A25C8ULL, 
            0x7EEB91C8AFDB1B41ULL, 0x2BBD57B6F0BE2A37ULL, 0x937BF5C4D3451DEBULL, 0xB09D2021B57AB7C7ULL, 
            0x58E4593909883C36ULL, 0x5AF1F41C7C873EEBULL, 0x347E61CBBE605311ULL, 0xD9B58B3E4ABDF373ULL, 
            0x53EC0E1A1E86A0DAULL, 0x68E8AF33ECE92E4BULL, 0xFBC9473DE85D8B46ULL, 0xC1B131365911F045ULL, 
            0x11075976A9736B0BULL, 0x4544660C9CE9F7D7ULL, 0xFBEB186BD5F54B40ULL, 0x17ACEAD270FEC306ULL, 
            0x5885E70946AE0654ULL, 0x8EDE417C48080B07ULL, 0xD40E7005C4A58BC7ULL, 0xF50BF8493E0F0F9DULL, 
            0xEEF7863B9E65B469ULL, 0x6DFCEBF1A853D0AFULL, 0x4C816336A9A0774AULL, 0xE3052EC890FBC0D2ULL
        }
    },
    {
        {
            0xF08FFF04742C1F94ULL, 0x43E73021F12C0D08ULL, 0xADE68CCF512A47E9ULL, 0x525A4E6FA08B8037ULL, 
            0x59583E15E75A836BULL, 0xE116A2D6207D83E8ULL, 0xB91BAF402DA0473BULL, 0x29F97F8DD389BE74ULL, 
            0x9FCDBBDED85940F7ULL, 0x89AF5C31B6D59236ULL, 0xDEDED5299C0D1AB8ULL, 0x0DEA534EE6AF53DFULL, 
            0x0DD29065A107E6BDULL, 0x365FFCCC366859B2ULL, 0xABEC735CF6C55F66ULL, 0x33652CA4CCADBF7FULL, 
            0xA90F7D3FA512F7DFULL, 0xB17CDAE2F663E22BULL, 0x0095AA084CFE6CE9ULL, 0x901E32487FA1C070ULL, 
            0xEE635669C76AF2C1ULL, 0x5BBC8700CC725B6AULL, 0x1D57F34142C722E4ULL, 0x581C5D5E5BF22D2CULL, 
            0x2CED7E23492F7896ULL, 0x9D7DCC2EA1057E5DULL, 0xF65A60EEB0124A43ULL, 0x7635F24E1BC635B3ULL, 
            0x3372A35B03D5AA10ULL, 0x8482F9AB125D594EULL, 0x1A582D882A23F68EULL, 0x3BB0835A4F6FFA2EULL
        },
        {
            0x5031270685907EC7ULL, 0xB33D303424BA4893ULL, 0x0D400C6ADE3C0AD2ULL, 0x89D8E48E95CA33D5ULL, 
            0xE99032CAB3044AB0ULL, 0xB75588A6544B44ADULL, 0x6307B0C8C9E48D9AULL, 0xEE860B7088C36060ULL, 
            0x76FC877B980A4C3AULL, 0x83C2760E68717118ULL, 0x3876A18C859B0FDFULL, 0xC280027E5833E4D4ULL, 
            0x17329926F45FBE52ULL, 0xB9989109598BFFA9ULL, 0x5E7F86B682EA2A5EULL, 0x40F803BE56686336ULL, 
            0xA352252D91A2B5CAULL, 0x829CE69B772DE244ULL, 0x9703957B63A4167CULL, 0x376DFAEB17D0BA12ULL, 
            0xE3BCBEC694E3B03CULL, 0xD234A1884D2F33EBULL, 0x87BC71485C77FA61ULL, 0xD0F9B015912C43BFULL, 
            0xCF556899C6027BA9ULL, 0x77E074A588F0FD60ULL, 0xD66EF12616C8D44CULL, 0x5C5740EB6CB25E10ULL, 
            0x13D39102B6E23C7CULL, 0x078FE05E24EC30C1ULL, 0xEAA6D936AB4CE063ULL, 0x56B99E4B9CF992F4ULL
        },
        {
            0x43484C01B07A9F72ULL, 0xD35A6108DB2FFEB0ULL, 0xDB83C46346EA3C6AULL, 0xF1B715C4D9EA92F7ULL, 
            0x196FEA6F979CA34BULL, 0x6D0B0C306C602439ULL, 0x7B2353C493D4FA9BULL, 0x878C6ECEBF97D9FFULL, 
            0xC9EF44520D16D271ULL, 0xA884649A0CEA316FULL, 0xA905573481D19DA1ULL, 0xE6E19CA5292CC329ULL, 
            0x8F4121B273BB4FEFULL, 0x9D9A8D29290C55CBULL, 0x27DC106F00CA5A04ULL, 0xAB5248F45F62841BULL, 
            0x792A9BC6766EE081ULL, 0x2B595BF8C6053BA7ULL, 0xC4A1BD7CDFDE6E91ULL, 0x4D3BEB2A3DCF9207ULL, 
            0xE686A5556FF46F36ULL, 0xB840404EB58CF405ULL, 0x1A403E6DCED5484DULL, 0xB7364B06F4DAE9DBULL, 
            0x1B1C14BAFBD09B16ULL, 0xA3DA0AD864A189E9ULL, 0x3FC067AE6E2AE1AAULL, 0xB0FE02642C3EFD02ULL, 
            0x0AEA7458816C290CULL, 0xEABFA9ED2D062621ULL, 0xD8FA71AE18AA2625ULL, 0x5A4BBCB7BC17B033ULL
        },
        {
            0x64C47F1877387D2BULL, 0xC38E7612B052E283ULL, 0x204D9F28A758732DULL, 0xA52D6A33B3DF92A7ULL, 
            0xACFE6FEF4489618CULL, 0x4008E596EA8B43B5ULL, 0x25B58C13F8A3305FULL, 0x70C2CE6319C558B1ULL, 
            0x9F05BF3778D51A1EULL, 0xA95C2AF5B5AF4475ULL, 0xFC8A33C5301476D9ULL, 0x9CC43040E1F24420ULL, 
            0x761DB92799185277ULL, 0x83CA789B35623E1AULL, 0x12D2E0A127339367ULL, 0x130151E1F1027A38ULL, 
            0x2F5FC88E0EE90ADFULL, 0x4947AC91F434B36FULL, 0x9D64BB3ADE0EF172ULL, 0x89F14EF3C89B1725ULL, 
            0xE64FA98F871970F3ULL, 0xF050CB229541D6EFULL, 0x2694DB2B7DDEA8D2ULL, 0xC38A7FE91C602D4DULL, 
            0x482FA554DF3B1A5FULL, 0x455689565524A51BULL, 0xEED9DDCAE5557CE7ULL, 0xFCE78D94CC8B5ABCULL, 
            0x44DCBB732C5C8330ULL, 0x155A38838E657021ULL, 0x9B584C8DB670086BULL, 0x94E91EF7A5E10A6EULL
        },
        {
            0xB1534923D8E2D54EULL, 0xD3718BCCCCDCEC40ULL, 0x0DA12CCF021A09F4ULL, 0xA4BAA2DAE95A391DULL, 
            0x8601E57D4CDFCE59ULL, 0xC337BA7F409A36FDULL, 0x93527E3E0AD7E621ULL, 0xA758B5CC91B8BF5CULL, 
            0xB2F97C8B05793859ULL, 0x8DEF814EBF0686B3ULL, 0x7664CA8DABAB261FULL, 0xE4EBF923FC26FE3BULL, 
            0xD7694B9E1CF68BB0ULL, 0xFB1063B265BC9DB6ULL, 0x661CD52AFE2D181CULL, 0xF4CDC9BA06B4A1C2ULL, 
            0xD7FFA4E29B241A82ULL, 0xDD4F00D3A91E8518ULL, 0x938CA6AF3FB21AC8ULL, 0x453F8A40940F548EULL, 
            0x083A1309AE0C656EULL, 0x6B055BF0FD62D5A8ULL, 0xFAF1A44425832282ULL, 0x3330E7DD2FDC65CCULL, 
            0x48FE3E528E7C2A6AULL, 0x58D7814930B59E0CULL, 0x3F28C749DE8BA470ULL, 0x2C8842F61378BF26ULL, 
            0x4C1A105B0A74E17EULL, 0x0735F321D0664FE1ULL, 0x475C1FAAA0DE5160ULL, 0x565CB24089DDB34AULL
        },
        {
            0x586B46607697D0E9ULL, 0x9B780809C5ACE95DULL, 0x6652E756F31962C1ULL, 0xA1867EC1EAAEAC10ULL, 
            0x0B3CC174BEA6BAFBULL, 0x99CDF34F5B808FC2ULL, 0x9C81BF9A46FF1129ULL, 0x009CF2FCDDA1244FULL, 
            0xB8E72BF0F2064117ULL, 0xA371C807C51A1A71ULL, 0x6F0FD4681354163DULL, 0x6A932CB1927F9257ULL, 
            0x7A24AC1168EAD027ULL, 0x2F1DE6D528B0EFA4ULL, 0xD1925C6B443CC561ULL, 0x2BD44C5D739C623AULL, 
            0xC62A89BA4B501471ULL, 0x64F72BB0C466973BULL, 0x1C81B7AA3A51AC18ULL, 0x40150EC22EB70B29ULL, 
            0x559B752E40BD069FULL, 0x8ABE5CC23F405245ULL, 0x9AB81F17D20D8166ULL, 0x814C396BC5DC70D5ULL, 
            0xF4591D47490FAC34ULL, 0xAD000B75F57ADADAULL, 0xC6949998CEE99E17ULL, 0x057E8D038DCAD4D3ULL, 
            0x90161CB1CFB3E3D7ULL, 0x91FF4AE768B78533ULL, 0x7DA8DC505F791D3EULL, 0x2DFFA5AE29DCF9C4ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alkaid::kKeyRotateAConstants = {
    0x34975DDDCDD82062ULL,
    0x9FD662B414296A36ULL,
    0x375CE7935A3CF7E6ULL,
    0x34975DDDCDD82062ULL,
    0x9FD662B414296A36ULL,
    0x375CE7935A3CF7E6ULL,
    0x7E4AC2F82916ED20ULL,
    0xB55196EA61D5279AULL,
    0x99,
    0xD6,
    0xA9,
    0x4E,
    0x38,
    0xBB,
    0x78,
    0x25
};

const TwistDomainSaltSet TwistExpander_Alkaid::kKeyRotateBSalts = {
    {
        {
            0xEEEAAC046E964CE8ULL, 0xE779E5951BF6CCB4ULL, 0x83B0148D43DFDB16ULL, 0x3CAF443311DB7A49ULL, 
            0x476B02A80B952FE9ULL, 0x9B511A594D0C4E6FULL, 0xD68524A56E5666C9ULL, 0xFD8FD2006263F3A1ULL, 
            0x9E6CD4D1FE7923BBULL, 0x0C775A129FF0AB0AULL, 0x3D868F8641F6D208ULL, 0x0D68E252EC229097ULL, 
            0x1197AA7607BB8B7EULL, 0xE5C286E278FE1392ULL, 0xC4BA916129497452ULL, 0x75156CEEBE106608ULL, 
            0x7FE38034C1C512EDULL, 0x817EF5F3E82292C7ULL, 0x0742B014475FB819ULL, 0x141B8194C1C83325ULL, 
            0xFBAA4A71E4CD2A66ULL, 0x94F7207B7DA35F60ULL, 0x480C730F2AA5A52EULL, 0xCDB85CC537497AB9ULL, 
            0xFCEDA698EBEE93E0ULL, 0xD62C42B4B2C59737ULL, 0xF15FA5F8BFD5390AULL, 0x4777769E5BE89F01ULL, 
            0xD73D70C8F57B3E90ULL, 0xB8C70F0E94AB3E0BULL, 0x5BA405D1CE39605AULL, 0x9F218123B11C37B5ULL
        },
        {
            0x4017804B4B7DF3FFULL, 0xE8C5362E8160F6D3ULL, 0x4F46FFB114FED485ULL, 0x208EFB0083E459C0ULL, 
            0x4CC60789DA120A6DULL, 0x246537E480724B85ULL, 0x78388566F7EE37FBULL, 0xA84B19144E45247AULL, 
            0xA101992032C4468AULL, 0x915D8EA87F00DA46ULL, 0x08FEFA1D935270C2ULL, 0x833216EDD790B1DFULL, 
            0xEACDC727D0E7C9ABULL, 0x4AFC6276E9FED878ULL, 0x9543E95DA9F321D4ULL, 0xA786D84FBF7D1598ULL, 
            0x1AFA19551AB7E6E0ULL, 0x9D6079BCD05F71DBULL, 0x36BF93FE950D25DBULL, 0xCD8687688EF43B45ULL, 
            0x7EC0DC5BD7038FF0ULL, 0xF226E0900E1774A4ULL, 0x3C033FD47F9205B9ULL, 0x199D334623EC94F3ULL, 
            0xD06C0ED056C3D34CULL, 0x6C2755A0284165A2ULL, 0xBB3194D8A8893D09ULL, 0x0BF2C4B1582281ADULL, 
            0xCF7ECA654FC053B7ULL, 0xA724ABEE05755AAAULL, 0x53B8E438365C8F08ULL, 0x5278CBCBFC1323D5ULL
        },
        {
            0x04BCBBB27E549FFCULL, 0x94024BF946E32F33ULL, 0xB4D7228B920BC461ULL, 0xD17FD58A0B4E17D7ULL, 
            0xF78EB24EE986D9C7ULL, 0x1B9CA22F20A7DE04ULL, 0x8659328B9F5D42E7ULL, 0x876AE817C5A3479DULL, 
            0xD6CCEAA6B2621882ULL, 0xA750F6A1C391D027ULL, 0xF45A673FEC5964BBULL, 0x35C8BAFADFA78163ULL, 
            0x2E2404FE8925579FULL, 0x155E87287F58632EULL, 0xA0BD11E960B739C8ULL, 0x60D731AEBF8E1298ULL, 
            0x2E8CF62A48E9CCB9ULL, 0x9F9893DC7B8E26F8ULL, 0xAB68D748B46FA74DULL, 0xF3C47681D1C67F65ULL, 
            0xDD1AB73BF2A28C57ULL, 0x4514A1395B0942F4ULL, 0x27A1B5755BC29877ULL, 0x6D11991A0DB2A1DBULL, 
            0x0E893857C2479B3DULL, 0xBF3EC2860E060F81ULL, 0x5DC994A251B5B94DULL, 0x341BBFB4A1E9727FULL, 
            0x8CD71F1BC743C178ULL, 0x5A04DDC89698E44AULL, 0xDE45912812FF32A2ULL, 0x7574E41BEC6AC18BULL
        },
        {
            0x9E855B47CB9D18E3ULL, 0xBDC63AB4C7A8C1BFULL, 0xF4C0572250015585ULL, 0x4F1D4E80AB6DFD4EULL, 
            0xCB2ACDDEAF059254ULL, 0xCDFF068F561A3156ULL, 0xC7F48430335F9A66ULL, 0xFED4847E327A8013ULL, 
            0xBA1CC37075F927CCULL, 0xA1C6061CF5BE74C3ULL, 0x7A4014320F1620DBULL, 0x3ABE6DCEB16C2FE4ULL, 
            0x0CCAB39667F4958DULL, 0x5491D634E914E853ULL, 0xE6E60AEFDAEF6623ULL, 0x1ECE58E38B53C735ULL, 
            0xD798BDBE8D1473D4ULL, 0x2A946D3EF9D31542ULL, 0x809364BD6003D890ULL, 0x9EB8A31A9C05185BULL, 
            0xC687DBDC710F6843ULL, 0xB37746114F1928FDULL, 0x73A2980317EF6945ULL, 0x081BD8C3E5060A72ULL, 
            0xE86CE9AA3FFF2B86ULL, 0x1BC4729359F50E65ULL, 0x19DD7F97F5F7BC98ULL, 0xFCF45BF991E8A351ULL, 
            0x68E9750F26FD561FULL, 0xE32C9242353E333EULL, 0x646F1D8CCB58F389ULL, 0x9F36F1ADCD467266ULL
        },
        {
            0xC11546C1DF7A3B43ULL, 0xBE642381AE5567A8ULL, 0x3F2A73AABC04EDA4ULL, 0xA5E7ABCE71965D6BULL, 
            0xBFBFABB83732BC26ULL, 0x57731C703AEEFDD8ULL, 0x4B52EDC3D00ECD86ULL, 0x9EC0A669EC77544EULL, 
            0x9F56F2B9706EAE47ULL, 0x399EE9EFF755BC2BULL, 0x2ED3DDA11D15F73FULL, 0x26CFE4D75E6E735EULL, 
            0x11F8F3EE252C01EBULL, 0x2B5B8CD1C8F7EBBBULL, 0x82EE012C21F7F343ULL, 0xE73C081FDF76C1F2ULL, 
            0x53A595EC3033144EULL, 0x8BA6B81C57C17A62ULL, 0x6A9E9931FC91BD6DULL, 0x84CC64CD75039837ULL, 
            0x3EA44620803E0773ULL, 0x6AC0412C2BECF9F4ULL, 0xF6ADD2540F61494AULL, 0xF0BACC2440D8338CULL, 
            0x978CEF41754D74E3ULL, 0x9AA2E1A743AE7595ULL, 0x0039DD6F2C3DC3A5ULL, 0xCE66D1FB717C6225ULL, 
            0xF6511BD988C87A93ULL, 0xEDB5AC58FEEAF191ULL, 0xFEBEB2CB6B4E11F9ULL, 0xE6E41B2A9C6CE8E5ULL
        },
        {
            0x779D92E4971D187AULL, 0xBD50C384D970B0D2ULL, 0x8B779D5426045649ULL, 0x68A402DDF97F803BULL, 
            0x9ACFF5567EDC52F6ULL, 0x27D0D51E8C6427DAULL, 0xADB36FAC91CCC6B8ULL, 0x20A74272160EC881ULL, 
            0xF383FEFC652E6B8AULL, 0xF710DB08D6AC4931ULL, 0x82AF219CE48BE8D5ULL, 0x3E77F89FBC202925ULL, 
            0xDC8C9D249546E0D3ULL, 0xE146482F540E78B2ULL, 0x5680F3EDBFC686D5ULL, 0x045649D8485B4AE2ULL, 
            0x9F267D5A3954BA63ULL, 0x751799A8E7090618ULL, 0xB491F3C822825830ULL, 0x3290D2A2D3796C66ULL, 
            0xC00489DBEDEB23CFULL, 0xFDB2AE0DE7E952B2ULL, 0x0DB85D373E09194BULL, 0x3AE3FED37EF0B481ULL, 
            0xCFAE913F5168C49DULL, 0x7772738454B25496ULL, 0x8C8395772DF8C737ULL, 0xA17C41F5E8AF16BCULL, 
            0x08F42C4B94B3626AULL, 0x51944722B7E4BA7BULL, 0x4BB5893B3E77841DULL, 0x4BFF0F178E39D5CAULL
        }
    },
    {
        {
            0xD3F75D45C2ED05B4ULL, 0xC5D69D5FF7936078ULL, 0xED7D02C8E1FD5972ULL, 0x098E03CA2E39255BULL, 
            0xF18CB8B066479809ULL, 0xE45869D1FFFDBA03ULL, 0xF791834F2628F47EULL, 0xE48E14F6DFB8B8C5ULL, 
            0xA868A91E60892B65ULL, 0xED4D4BE3F4C5213FULL, 0x4C509ED43BF7638CULL, 0x23D616AACD276A8EULL, 
            0xCFC08AD40862374FULL, 0x7D648842D9510657ULL, 0x7326665E667FDD14ULL, 0xDBA92D1F1C6EE745ULL, 
            0x6251B3B585CC4C07ULL, 0x21272C7ED17506A3ULL, 0xF901497568E5CEC5ULL, 0xA5A0B35C03557C5EULL, 
            0x3611DF186304954CULL, 0xBB780D22733AA678ULL, 0x70CB96549785E61CULL, 0xFF06DE960F1C8088ULL, 
            0xDDD6E19B0DA5D543ULL, 0x8FFB8F63C9644501ULL, 0x6995A8F0EF99541CULL, 0xC03110B7FE9BB04EULL, 
            0xF6216F654D80898EULL, 0x8083A03E95ECD79DULL, 0xBA5C017978ADF9E1ULL, 0xE87BF0E4758B259DULL
        },
        {
            0xB8B33172AE8751A3ULL, 0x9FF22C82AE0B3185ULL, 0x96EAFC96CBACD989ULL, 0x96DC47A348A7FB00ULL, 
            0x9B8C1B2EDACFB3C4ULL, 0xA50A5B224F8D6122ULL, 0xF09A404C5004CFA9ULL, 0x33946CF15BD20F1BULL, 
            0xA4AFBC4995777F90ULL, 0x483FA3DF60D3E253ULL, 0x5C5D7B932DB1DA21ULL, 0xBAA96CBDAFD47DAAULL, 
            0xAE5938B261C37917ULL, 0x8F3CF9F0D91809EDULL, 0x848B726B156124F3ULL, 0xCF7938010F1353FFULL, 
            0x1B8A225B964BB766ULL, 0x80B1C69F72C607BDULL, 0x2657D8E77DE5E01BULL, 0x7416FBE9F2BB9AB8ULL, 
            0xE17CBDAF32A87E9EULL, 0x5B81C474A46297C7ULL, 0xE01C52E9BC8228ACULL, 0xDEFB6C83641F745CULL, 
            0x26C174B83D91D6DBULL, 0x5ED9140664263344ULL, 0x57900716646E0A24ULL, 0xC367BA1C7F442C44ULL, 
            0x6D823349FA6C67D1ULL, 0x83D2B27CA72A13BEULL, 0x78112F978BC0A140ULL, 0x78593DF38D8E080FULL
        },
        {
            0xAE7F855CECF49016ULL, 0x61CD07A325DE6420ULL, 0xB9C00CA6040ACBD3ULL, 0x87C169C34A8764F6ULL, 
            0x36BB3330CEB3D57FULL, 0x12335B0B26864851ULL, 0x58799E9545FB8405ULL, 0x0D4E62102A353B7CULL, 
            0xCD5077C407D5C7D2ULL, 0xE7755EC5D0DCD3F0ULL, 0xBA9AE41DCF6CB81CULL, 0xA81A6ADE013547AAULL, 
            0x58A53A80FC910ADCULL, 0xC474DEF2509CABB3ULL, 0xB4C296A20E0813D1ULL, 0x7FE4106AAC78EEDDULL, 
            0x3B04A552E0F5F804ULL, 0x517F9E4480F82649ULL, 0xABBB41F74D752862ULL, 0x1901A7B3F0E0CAB2ULL, 
            0x85A0B9C8A9630897ULL, 0x23D004394F20F96DULL, 0x4CBC5C64929103C8ULL, 0x907AAE111D5232A0ULL, 
            0x7B4B741198E9C937ULL, 0x4079657CF01C1F14ULL, 0x47F2330868959070ULL, 0x389F3655B8010E04ULL, 
            0xF6B342B94E5368BFULL, 0xFDE5B70D9A7AA4C6ULL, 0xD650C9C243A2ABF6ULL, 0x6CF5FE56DE0EF09AULL
        },
        {
            0x3F765C78452B7CA5ULL, 0x819021AE4641F403ULL, 0x6BB05D96EB8BC3EDULL, 0x7FAECDEDA81CE846ULL, 
            0x44DEC67CDE70020EULL, 0x5BE4DA3D09434B48ULL, 0x61F6D69B7E363DBBULL, 0x23F538BB59403875ULL, 
            0xD6E11E8592CE845AULL, 0x85EC1734A2B74BC1ULL, 0x1B24A7278E249710ULL, 0xFF43DE5927C920CFULL, 
            0xA59D49EE7B2B9A8AULL, 0xBC559B78E2AC9105ULL, 0x74D611B8DC2B0C0BULL, 0x542E81CA3B6FE755ULL, 
            0x23C1307FAB352CD9ULL, 0xBBC8D7011790F65DULL, 0x21EB67C6D5A91774ULL, 0x2537B35268E3D1F1ULL, 
            0xAA1B1ABC411CA605ULL, 0x2FDA27167FB7549EULL, 0xD87B62AC473914CFULL, 0x6AD0A381777D9441ULL, 
            0x6FA6B3B390149A02ULL, 0x8417EA5C297426F1ULL, 0x9E03FEE911E419A4ULL, 0x8C44520090CDDECFULL, 
            0x58FACD120E075575ULL, 0xD49BFE6B3BA8B972ULL, 0xF666517D8305BD2CULL, 0x88F0725751192028ULL
        },
        {
            0xF0635C6C5FD3ACEEULL, 0x2CEA3580FE7409E2ULL, 0xAB974D5930B36300ULL, 0x5B5CEE5E725130A6ULL, 
            0x934A369454E72C51ULL, 0x1D7863EE247F7BD2ULL, 0x507E41818EAA29F4ULL, 0x3A9ED45A548DADC8ULL, 
            0xE6067ED4B684F404ULL, 0x93CE9B20A91C3E31ULL, 0xB54154908B927DE5ULL, 0x05D71761FB93D81BULL, 
            0x3FB3B01DF3922346ULL, 0xB40BD61F9F54DBA6ULL, 0xA2B88E5628A3279BULL, 0x4ADD11BB293E68ACULL, 
            0x926C30748EEB5E65ULL, 0xD6155AB7E11FD78AULL, 0x44877986B6C826E5ULL, 0xB24F2519A6A151B6ULL, 
            0x72E3251E81814AB9ULL, 0xF4F20751B151BB51ULL, 0x4EF200E423354249ULL, 0x81327973909CFDE4ULL, 
            0xA52837B2736D0313ULL, 0x6E765C42EC0CD1E7ULL, 0x273A2B218FB3A7CAULL, 0x79AC16717B1C125CULL, 
            0x05E86956A90AEFDBULL, 0x57BDEA5D9E2617AEULL, 0xC057EC26B54298E4ULL, 0x3A203A7F4415C3B5ULL
        },
        {
            0xC6C2253E6B2C4881ULL, 0x757B2E604BB54C71ULL, 0xBEB26C048F2A92F6ULL, 0x502340E675355E9BULL, 
            0xE1ADFB16BD05F219ULL, 0x76DC74BE9546B755ULL, 0x33160841B9ED5E14ULL, 0xA80EFC60642501C9ULL, 
            0xE8C57D43E1F3CEE0ULL, 0x53E25FC8C98B139FULL, 0x38112D99BC79BA73ULL, 0xC4B703FEF6D1EC8AULL, 
            0x8F2D21A4DC6E38FCULL, 0x58BC8B055A1F68D2ULL, 0x3BC476AC9835305CULL, 0xA60F9BA3BBE2E3F7ULL, 
            0x07262D42166D99D2ULL, 0xCDA2B9A9C05B7622ULL, 0xD3CD3195CFDE5DDBULL, 0x70EF62886C757C42ULL, 
            0x59DE6D457BE17062ULL, 0x81F39CAB1E20494CULL, 0x6FF3751C804F7BC5ULL, 0xA49134A31074C415ULL, 
            0x4F640D0317CB8D9EULL, 0x54737AA9144EEC83ULL, 0x73BF574A3E643609ULL, 0x3763395AE27173EAULL, 
            0x78B505033EE39BAEULL, 0x401F8B33D0641661ULL, 0x8A391D91F3EFF560ULL, 0xBD358A170C8C1081ULL
        }
    },
    {
        {
            0x597A6425A0FC373AULL, 0xF371151A58A8C648ULL, 0x9AA80A8166D523B4ULL, 0x47A8985307760200ULL, 
            0xFE96FCFE42F84571ULL, 0x38490EE15F40347BULL, 0xB430A2EFD65F96CEULL, 0x5A8679C96611E07EULL, 
            0x530E35036233A0EEULL, 0x4A8EBA73CB79B064ULL, 0xC1A0375493F34233ULL, 0x4667438572DC388AULL, 
            0xCFDA7E623FB264B6ULL, 0xF143BABC22A81157ULL, 0xDBB4079F3128FC93ULL, 0x165411C59182587CULL, 
            0xDE4727735A918209ULL, 0x1720C9D41BF13955ULL, 0x93B96AF87FB3D3E4ULL, 0x32ACD792C228B441ULL, 
            0xE691644B32B9CE4AULL, 0x94FE722BE0429EBDULL, 0x4FE50AB11BE8F36CULL, 0x4DC8CA3AE16BCF90ULL, 
            0x7BEE3073E44B36D8ULL, 0xE9CC5F43A3330C20ULL, 0x777011C9FBB77A4BULL, 0x125D8A6877CB6D5AULL, 
            0xDD6A3C18684B3227ULL, 0x215318C8F2361FF9ULL, 0x55DA59D578A8BF03ULL, 0x27B2B70AC15003C2ULL
        },
        {
            0xC9270FF8F829557FULL, 0x05E1BCC63E39137FULL, 0x9EE7BD208929B5B2ULL, 0x01875AF21BBA13C7ULL, 
            0x16A66E133181C96CULL, 0x91EE43BC6EBB578FULL, 0xF922D1ED5FD4919BULL, 0xA4F633A40C7E247EULL, 
            0x1E6E486F8B8253F2ULL, 0x36439BCA43118A9DULL, 0x16D5BDC64C72DE4BULL, 0xF8A4CA727BAD94E3ULL, 
            0xBD5110720653055DULL, 0xFDC6B6AA1D09DD4CULL, 0xFF98E5681FB3C95DULL, 0xBD2A582EC0A6028DULL, 
            0x38FAF066E0FBDB16ULL, 0xEE509D96EB5AA763ULL, 0x17C944685A4875B3ULL, 0x2E80A6774CD4DE47ULL, 
            0xA0E11102197CBEBAULL, 0x957F401C8B6C0E0AULL, 0xA1D76E9101699E42ULL, 0xD4FB5E30273C35E7ULL, 
            0xC4E9E08CC89881F7ULL, 0x62DC91FDC62B2263ULL, 0xA8145101CB870E3DULL, 0x1D062C4A4227C2E7ULL, 
            0xC00DB4D825DBCD0AULL, 0x9D2125D8A51E84ABULL, 0xAF60AA7D2B4E4F8BULL, 0x1C99728195F67ABAULL
        },
        {
            0x423D4CF4A88E4D50ULL, 0xEF25CE1BAF81F3D8ULL, 0xE121C053B5369975ULL, 0x8DED87A47F5A0F4DULL, 
            0x5FF17FB95AC054ADULL, 0x6E7313693EB166DDULL, 0xEAD906FF471144F8ULL, 0x35B5873E3F947B1EULL, 
            0x2EAE54AEB3EF5807ULL, 0x0327808DB7778F79ULL, 0x587BAA208C27FA36ULL, 0x0B1E4A73C5FFFABEULL, 
            0x956D41DC6ECC6715ULL, 0xED8AD669941FE538ULL, 0xCF81B8F7925AF812ULL, 0x5CBBA09F61000E5FULL, 
            0x65A89993455842D3ULL, 0x281F8815E09D73ACULL, 0x906546970B6CF966ULL, 0x65AF10151CB2CB36ULL, 
            0x7AEE6919013D767AULL, 0xA37DB44D788F7884ULL, 0xF37CBC28FB5F2E6DULL, 0xE99C7C468215FF55ULL, 
            0xB90A8C2A2844DE1DULL, 0x52BC3CDF2FE52AEDULL, 0x245AF85E409C0C6BULL, 0xFED21987A7B01DF4ULL, 
            0xE5F625F311C8ECAEULL, 0xA9D10C1396E112F4ULL, 0x59338CD975A93C4BULL, 0x94B1463CC7EB5087ULL
        },
        {
            0xE54291A1E10F316FULL, 0x0C67F1BE33F2164CULL, 0x804DE2E9CCFC33D1ULL, 0x82DF70BF29766621ULL, 
            0xF753C2AC330E536FULL, 0x909AF13C86DCC69AULL, 0x3607606B08AAD9FEULL, 0xE2CAA5FED05A6E52ULL, 
            0x02478ADB43A50D91ULL, 0xB975D2E2BE65318FULL, 0x9F3A61A5CE568DEBULL, 0x8108770E37BE0BC8ULL, 
            0xF34CE519DB844F96ULL, 0xB1EA4E0F6FF9910AULL, 0xC4934D11E6F1500FULL, 0x36AD008D85A385B7ULL, 
            0x847D976760DE4846ULL, 0xCE0A36105A7461F4ULL, 0xBD3BFCDBC89AFDC0ULL, 0x8CB9C4FD8DF95277ULL, 
            0x84BDE35BA320AD25ULL, 0xF31B094BC6C977B4ULL, 0xAE57F4EA2413D75AULL, 0xDC5DE2170F2EE966ULL, 
            0x46D8F33C988AC8B7ULL, 0xAF9068A2D5C71748ULL, 0xAF53C7C44647D647ULL, 0xA91790F0E7FAFEB7ULL, 
            0xD87F385B20295C75ULL, 0x023E401534E94B45ULL, 0x02A34C180C0C957FULL, 0x23A5AF1FCE5C0C53ULL
        },
        {
            0xAA762F9DF5B53819ULL, 0x1BCC70C4EFA0CDA1ULL, 0x02347C6E2F89F7ADULL, 0xB4C67E69B95B4739ULL, 
            0xE58969B100BFB757ULL, 0xE512C72025F1DAF1ULL, 0xEF1C60D4A72A4143ULL, 0xA0231534E0364DA7ULL, 
            0x6A757220C27002F8ULL, 0x1790FE54B74BFB37ULL, 0xC26655DC07CAF175ULL, 0x8D9B227DBAC482A5ULL, 
            0xD8DC3E3BC6CC12A6ULL, 0x662605837C872DF5ULL, 0x61B6A7E608B2C67AULL, 0xD52A3731385A83D0ULL, 
            0xEA109C9EB8E02A2DULL, 0xD1B204366BDB5176ULL, 0xA6C76EBCC93D3811ULL, 0x8EF209EE00CEC1A5ULL, 
            0x3B583EFE499F5860ULL, 0x89EFEE15734CF57CULL, 0x7786E0EF3EB52984ULL, 0x3FCE8B7AD54D56FAULL, 
            0xCD4BF2574E0DB7C0ULL, 0xC0AE37F951502DBAULL, 0xD0AF805812EC91C0ULL, 0xDD912B630B70366DULL, 
            0x61F2775CC98E49E2ULL, 0xDEB2BF758B6075B1ULL, 0x5B8DAA7DE47B937BULL, 0x46F84BAC30499CA6ULL
        },
        {
            0xDE04C58EB559DBDDULL, 0xCB9F921324DC0C6FULL, 0x7364D8017A90624CULL, 0x9395B8E6E33D849CULL, 
            0x279A1470A511EAE2ULL, 0x43C8FA4F82DCF8ACULL, 0xC347AAFA2508F7A8ULL, 0x6F39F6AC5B7BB480ULL, 
            0x674AE5919B5258F4ULL, 0xB598934F99BC2BD9ULL, 0x2431D2D0B6C760C4ULL, 0x6D704042D47581DAULL, 
            0xE813D121827AB7E1ULL, 0x74B640416B8D425BULL, 0x511E5096309E8228ULL, 0x76E40D33F441C361ULL, 
            0x62353219A5E025BEULL, 0xD348D328ABA55D6EULL, 0x3C9FD28320147E38ULL, 0x24D6FB26872E33D2ULL, 
            0xD965F1C3247AFF3AULL, 0x48D13CF33B998E88ULL, 0x27708AEAC5C9062BULL, 0xE9A6FF6CC7F57046ULL, 
            0x5FC3C368F203CA32ULL, 0x8C9D1145E5576E3FULL, 0x25FA3036BCE1D83CULL, 0xCF0B9B147A3BED4AULL, 
            0xCA13CAC0BBC9C5C4ULL, 0x9316AE20AB895BFCULL, 0x4A55593B1E4BE7F2ULL, 0xB1C87F8057D2DFDBULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alkaid::kKeyRotateBConstants = {
    0x33765FA512589BBEULL,
    0x350CB7241BDAD2FAULL,
    0x4DBD0F9903B2407EULL,
    0x33765FA512589BBEULL,
    0x350CB7241BDAD2FAULL,
    0x4DBD0F9903B2407EULL,
    0x58F2CAD98242E948ULL,
    0x53F077C2C1235CBCULL,
    0x80,
    0xB0,
    0x58,
    0x96,
    0x62,
    0x86,
    0x26,
    0x48
};

const TwistDomainSaltSet TwistExpander_Alkaid::kKeySpawnASalts = {
    {
        {
            0xCBE32737399E2D32ULL, 0xB17B5CADD75FDAADULL, 0xDC99D8CD24F4D8AAULL, 0x930FA7DC02546BA6ULL, 
            0x1FE99EFEE551D8A3ULL, 0xB01C22997AA68529ULL, 0xD6DA587D7B2554EBULL, 0x0FCF4C9CC681B48AULL, 
            0xAD14467D94D13147ULL, 0xEDA4C6B41AAE6898ULL, 0x0C665B4C77F511DFULL, 0xE9AA470B81AF61E9ULL, 
            0xE6831C9A6FB1D8C4ULL, 0x641007478FFC5E75ULL, 0xE22CCC9C23259A6CULL, 0x19D2929BB2841C47ULL, 
            0x069583CC34CAD502ULL, 0x75187D203496C258ULL, 0x27FD3C44B398F4F8ULL, 0x631792D2B294E759ULL, 
            0x0132CBCB50AAC7E0ULL, 0x0B475A9269A29CB9ULL, 0x348AA9670E0C5BE3ULL, 0xCD3A315ED1BE9DB7ULL, 
            0x7DEA53A5F86ECCF3ULL, 0x97663329EF441B41ULL, 0xEFEBFFA27233AD78ULL, 0x8C2F1C91F8CF9BC1ULL, 
            0xB9A8170E830B23D5ULL, 0xA79F1F8BD5D4D5B2ULL, 0xDB76D5C7185A45F1ULL, 0x2637DA5670E2EC07ULL
        },
        {
            0xA77D95D31D117EC2ULL, 0xDF1A39915712AA03ULL, 0x83E0368B2E85C8C5ULL, 0xD5028D06171508A0ULL, 
            0x0A3A08AA1F119F16ULL, 0x831C80BAEEA6F782ULL, 0xBAC3C9A0BBEA3675ULL, 0x98F12B302EA40F40ULL, 
            0x6C70C87F5B5D4FF9ULL, 0xE9A850B51625E860ULL, 0xC3DEE95C0044ACA9ULL, 0xB7BD922EE75CD67FULL, 
            0x729EC1550BF47A2DULL, 0x178612B00C9F3328ULL, 0x0CEE97DD3CB13645ULL, 0x1A0CD82DF5C16D10ULL, 
            0xE99FE17627A5B8AEULL, 0xF2DBB24D32E12B6DULL, 0x156B2958D5061B30ULL, 0x045E2598FE51964DULL, 
            0x36531AE887AB074CULL, 0xF95824629AEB0813ULL, 0x03E12B393C3081C1ULL, 0x30E990EC69081713ULL, 
            0x7E2788E4AC834F57ULL, 0xE15F786C3856871DULL, 0xB32050393BB09DF5ULL, 0x85E7002E571CBBFDULL, 
            0xA26A42D222CB999DULL, 0x9655DF4524B5CFF5ULL, 0x1A44B4B4E56A28F4ULL, 0x3C08D61734BFD352ULL
        },
        {
            0x456E72726D8BFB64ULL, 0xFE2ED66F3F4F2F77ULL, 0x189FFDBBDF326BF5ULL, 0x68B6CDF5FF5E6A07ULL, 
            0x902A95C2A12C847FULL, 0x790B07760ED58B37ULL, 0xD3C3159D29D57B9CULL, 0x70DF3A2B00E8D254ULL, 
            0x2B73B16EBACC99FDULL, 0xEF553D33F7EDC659ULL, 0xDEBB55A3791B3903ULL, 0x07F4328AE4812027ULL, 
            0xDD3AEAB0A494DD55ULL, 0x93812D763CE8B7F7ULL, 0x488374AC4D9AA0C1ULL, 0xBB05D60F73E0BCE1ULL, 
            0x143E3A3313EC3112ULL, 0x0D1EBAB76C86413DULL, 0x451013E472D9EF28ULL, 0xCE6D768F58B062B1ULL, 
            0xE26208C80C1E49B1ULL, 0x5E5CB4D58B6E0393ULL, 0x06DEBD3389C9520FULL, 0x51A0E14DDE85CC33ULL, 
            0xD4929A74A19EAC95ULL, 0xFD60AADC77C39E88ULL, 0xFD9190CA9AC76882ULL, 0x40EB458390DB3F81ULL, 
            0x8C2A37733FAE8900ULL, 0x7550208DF817DDCFULL, 0xAE3C3FB439431B2CULL, 0x99BB1817B426261FULL
        },
        {
            0x6306FF51D46E6615ULL, 0x79E77C4E85058650ULL, 0x1D367ACF46E08ECDULL, 0x91555A1A124752E6ULL, 
            0xB333C8ECE690101AULL, 0xA3BA6CD182AD2EE6ULL, 0xD458C04B23B8BC4BULL, 0x96B9384332F64C0BULL, 
            0xDB75D7C8B79FF380ULL, 0x35C8838114A59359ULL, 0x4CDE28809551351CULL, 0x850AFD7AE76A5AF7ULL, 
            0x13C732C1104F146FULL, 0x199377AC21CD82C4ULL, 0x7057C5E2CECE88BBULL, 0x8A58221A6184C0C6ULL, 
            0xE4B839B80CA46247ULL, 0x052B2C0BB265B053ULL, 0x6081115F03531E45ULL, 0xED32A489EE7B7A31ULL, 
            0xC11C270A00D068EAULL, 0x9887444DBA547F5DULL, 0x8D95BAB44B5C9CB2ULL, 0x3CE4D127D17713C1ULL, 
            0x1B58C429161D3DE3ULL, 0x5D65F71AD17BFC33ULL, 0xCBE3C4074A50F100ULL, 0x2D2D15F8B9BA5076ULL, 
            0x0FECF00C05D5E651ULL, 0xB36033455B6F68CAULL, 0x2E6B891263EB83C1ULL, 0x69FB5F91892FE752ULL
        },
        {
            0x07F6F57B3FA9D3F1ULL, 0xC0278BFE5FF8BB59ULL, 0x869DA16F3692BDC2ULL, 0xCB42B1482259F063ULL, 
            0x9F6669C3853AAC7AULL, 0xB4F7FC87F604B60CULL, 0x344AB504DA666C06ULL, 0x4384E072C7AA7726ULL, 
            0xE9A177B17F5F7230ULL, 0x5C130BA63179735BULL, 0xA840642B523B2E85ULL, 0xDB3F8E1B67CC5241ULL, 
            0x14EF4EA379F65FAFULL, 0x80E3B3B98E303A80ULL, 0x8FA295F4C12C7EF4ULL, 0x9B67A215952DC00DULL, 
            0xB7AE845A8B7AA870ULL, 0x169419DD9C7377BCULL, 0x0658B6D0D700E4A2ULL, 0xCC94A83E7AED6EE6ULL, 
            0x1A9500E0885817A8ULL, 0xA2124E0A540AAD7BULL, 0xC805AA28A71496CCULL, 0xA6AD3033858CF8E1ULL, 
            0xE91CD853C7CD26B1ULL, 0xBD46A96B4264C42FULL, 0xAECC08A45E1B0563ULL, 0xAB8333230C0FF0C6ULL, 
            0x0315DA9DFD78A6B4ULL, 0xFA739BFDC31E6983ULL, 0x56C72F9BAD1BC4D8ULL, 0x9EDA454768A26079ULL
        },
        {
            0x341DD373823D833BULL, 0xD45FCD0C39C28389ULL, 0x0B7BFD2A89004A17ULL, 0x39B4F34B697E629DULL, 
            0xA647F2F032749EB7ULL, 0x4B45783585C931F3ULL, 0x47EEDFE1AE17D530ULL, 0x230C820639BB1CF0ULL, 
            0xDD25FD15169890F1ULL, 0x31AD7B33BF7FD824ULL, 0xD42000B663137A22ULL, 0x0EE46E113A42E1B1ULL, 
            0xD868D51150BA4891ULL, 0x5107F0A1BB62B50DULL, 0x6C4697D02F4015A0ULL, 0xB9A58F40EE144A4BULL, 
            0x01F3CFB2EFCD2381ULL, 0xC083EB802962104AULL, 0x2AC8BBA97146D5C0ULL, 0x783F1CC5D5129087ULL, 
            0x9F0A4E286D24012BULL, 0x6B3045C065D7AC17ULL, 0x52139A0CDF0C01C8ULL, 0x826FA7E464E902F5ULL, 
            0xEC30E679E2B892C7ULL, 0xE96A04B58E4E268BULL, 0xC8C50A9E2CEF90A2ULL, 0x3B8C5B88C5E5D878ULL, 
            0x1F7D429B92994D41ULL, 0x43E7CF6C303B3855ULL, 0xFEDF4D551B3011E5ULL, 0xE3EEE2D455518B14ULL
        }
    },
    {
        {
            0x5F6A8158A1E4ED0EULL, 0x1CBF20C7357B6573ULL, 0x7D497180286BF4F8ULL, 0x34A64413376AB0CEULL, 
            0x5E030A25FE425085ULL, 0x0DAF46D51C3587C6ULL, 0x195D7E28492471A8ULL, 0xBE9C239545996F9DULL, 
            0x1815CB650560A6B0ULL, 0x41AA372A743A34DBULL, 0x1D747D2E6EE3D92FULL, 0x7D18A67946DB9AB6ULL, 
            0x57D5C0E75B0BE0ECULL, 0xC89A3209CB19D407ULL, 0xE68C0D1F553F7F9FULL, 0x2D83189882CEE682ULL, 
            0xEFB2DC19411A1694ULL, 0x1A57C2226A82A80DULL, 0x61725A4F70CEBD68ULL, 0x69D660675E1E360CULL, 
            0xB1B65EFEAA40263BULL, 0x2141D5E0BB515F5BULL, 0x41623453E6FDFA88ULL, 0x9EC326F69DE66179ULL, 
            0xBB58BAAE7F2AB8D2ULL, 0x51F6DEB0A86BBEF7ULL, 0xED2631C9CD00BCF6ULL, 0xAF326D5E4D954D41ULL, 
            0x236C3F9EB9DE8E19ULL, 0xB7C4C9339C20C1CEULL, 0x2E3BAFBF74DFF533ULL, 0xD03613B687F42AD8ULL
        },
        {
            0x0E97D71B066E9BE9ULL, 0xFCCD7D88CE2A1C68ULL, 0xF00D91159D749B2AULL, 0x69C4C2F6295B0193ULL, 
            0x9DC5243BF0FE7A8DULL, 0xB1CA7F61279F8CB5ULL, 0x043D0E06089DD8DBULL, 0x6567932F75B064B3ULL, 
            0xA0E4CCAB80E4BE20ULL, 0x23F1532C6D5759D6ULL, 0x7D470D559B9724EDULL, 0xD2D330E6323E4FF4ULL, 
            0x886105333833904CULL, 0x3397624F48B4F441ULL, 0xFF7E4CFE3236A4C6ULL, 0xBE8C681AD52D259CULL, 
            0x24889E98EB2E198AULL, 0x84D98402ADDF7B92ULL, 0xA2E209DD66AFB1DFULL, 0xF9C52A405A45D334ULL, 
            0xA6A67D8E04987871ULL, 0x501CCCABE4026539ULL, 0xDD9C893F8A7B3830ULL, 0x90B9290076B1773CULL, 
            0x2E54DCFF9A46D97EULL, 0x82F0AF1D21BB24D0ULL, 0xE05DF631053449A6ULL, 0xAFC853172719F349ULL, 
            0x0CFCE59AEAED6CACULL, 0x8903AFA7DC8F3F38ULL, 0xBEB4B6577CC159DAULL, 0x9A2078B70289109BULL
        },
        {
            0xE190EC5507AB7AEEULL, 0xAFCF896361230421ULL, 0xC8085EBE047C6DE1ULL, 0xD898E4F609FE0540ULL, 
            0xCCDFCC2F1CFFE7F9ULL, 0xD0BD0C9290329D1AULL, 0x9967AFAAD08D9463ULL, 0x7DF3333751AAE700ULL, 
            0x062FD83712CC509AULL, 0x14AF742BC294ED44ULL, 0x9B820164A68E5C61ULL, 0x6507B9059034718CULL, 
            0xE2EBE9D77C4AF495ULL, 0x2780157908D29E63ULL, 0xA97F389076FC615BULL, 0x148DBB2390040663ULL, 
            0xE88B31E5F42B482CULL, 0x94AEFFAE514F64CBULL, 0xB55A2E9556665D53ULL, 0x88A41BE2AEE017CAULL, 
            0x6F00939603C6DA8FULL, 0x0E5CA2666120D774ULL, 0x6425D53FA66D67E9ULL, 0x505DC113C5B7F68CULL, 
            0x437F728F880EA672ULL, 0xAE56C4977B9C042EULL, 0x9E81483C04FE8F39ULL, 0xED8AE8B9AA32DE23ULL, 
            0x41A97E5058097E51ULL, 0x59876D9D9CC2C623ULL, 0xC4B8EC77A47A41DBULL, 0xF945189B7C9F40B8ULL
        },
        {
            0x23538DE274E4AA1DULL, 0x3888FD3070957317ULL, 0x1B1F1DB1DCB03419ULL, 0xDF2BE56ED39E0CFDULL, 
            0x842BA0530D1BA053ULL, 0x829E1DF76378FED0ULL, 0x838BE21778B8C01CULL, 0x4E50264C280701CBULL, 
            0xE9F4C2AA24370316ULL, 0x26C7498D346F94F2ULL, 0x8EC0EF871F38DF7DULL, 0xEC7167B92BB27F5EULL, 
            0xF962109F0F225B32ULL, 0xD7F6B803D2B1A628ULL, 0x7C466E96ACA9C5C7ULL, 0x19864A8A3C4D7591ULL, 
            0x8A29FEA17431D81AULL, 0x455A1C8AC08D6DC8ULL, 0x468CEAEFB1880575ULL, 0x8978E689FA49F0B6ULL, 
            0xFB955A9FCEEBE4B1ULL, 0x870958D42C8267E8ULL, 0x85AAB76CEC7B12D6ULL, 0xE2D0A1B5B06BAD46ULL, 
            0x5EB43AF2EC04C365ULL, 0xA1920DB7A8674E67ULL, 0x0E6880FF26E96C99ULL, 0x82C4877907E37770ULL, 
            0xCE0D8C4388C41E09ULL, 0xFA7CA54A49E84A41ULL, 0xC44B79827DF02AEEULL, 0xC23CF00DD4CA5A84ULL
        },
        {
            0xC736A8A3D984EFEFULL, 0x4A446701027B655DULL, 0x151109B94450797EULL, 0xDBA27A5217FB24E8ULL, 
            0x88C87127BCBEC408ULL, 0x139FB60C07409979ULL, 0x80C7BB46F5F876ACULL, 0xC5D126B84AEBD876ULL, 
            0xA4A13E5E482E550DULL, 0xDB1A74A73D9FED27ULL, 0xFCC937D3154B5572ULL, 0xAA65E4385BA1279AULL, 
            0x1A657C7DFBEBE8F7ULL, 0x57E95F2AD16D3A4DULL, 0x2127076C0FD3FD9EULL, 0xE827C7957655CBF0ULL, 
            0x817577E3DC015F35ULL, 0x2494B1DC0674C77AULL, 0x52C3A52A7E58E37AULL, 0xB88C30C289ED6A28ULL, 
            0x1F43963E75FAA456ULL, 0xC08FC170E41F54D9ULL, 0xE6F60D1244C51489ULL, 0x93F84A7E02510566ULL, 
            0xA87E3FB76D517EF7ULL, 0x6A7CAF2C8640384EULL, 0x4FEDBFA553090EFBULL, 0xB50A72A8550AC2DAULL, 
            0x02CB9C00FAAA092BULL, 0x9080279C62357939ULL, 0x8E89C7C6D37413ADULL, 0x337C2DA60B05D2F5ULL
        },
        {
            0x9A778120DB8068A6ULL, 0xB886C7E3022DCA43ULL, 0x719DF32C00A8BF46ULL, 0x750588AF894E91BFULL, 
            0x371FF38B28536DE3ULL, 0x463A85481896BE80ULL, 0x1AF10CBF64739D85ULL, 0xEF756D39D283625EULL, 
            0x7A36119390850D34ULL, 0x1E0CDAA25F622C9CULL, 0x7873C56FDAFAB265ULL, 0x334447B4D9E65F3BULL, 
            0x83CC616EBF66F2B6ULL, 0x6725C9C5CB063354ULL, 0xECD7C3E78B8588A5ULL, 0x61A756BCD5210630ULL, 
            0xEDB6E9719349AAA5ULL, 0x4C87A0B644E4BC1FULL, 0x95412EF22C66D279ULL, 0xF8C8A5BC003D005BULL, 
            0xC74B6B5F0D7DE85BULL, 0x86514F0A1BADD227ULL, 0xC33D31B2ED01183FULL, 0x05069F7CFDD2842CULL, 
            0x94EC565709C052CCULL, 0x51FE1851417E01B8ULL, 0xF408A3AD4CDCD2A1ULL, 0x477115D16D96B8CAULL, 
            0x5BA92A2742CCE365ULL, 0x9DE48B0BF691ED0EULL, 0x3E452BB50CEAE10CULL, 0x99E1D8D95DAFBBC4ULL
        }
    },
    {
        {
            0x81E2F9CC2F6B047AULL, 0x12292AE268781CBDULL, 0x4609E80B547B3672ULL, 0xA3DB45C6DD4BBAC7ULL, 
            0x49F52655745593B3ULL, 0x62741C01C63B7544ULL, 0xBF751426BE137823ULL, 0x7572BA7DB29397A6ULL, 
            0xC336A14C0B16653AULL, 0xFEF967DF4BA01F34ULL, 0xB914317E8F2C113BULL, 0x0DF7E3CDF42D484CULL, 
            0xC3492E5A918F5805ULL, 0xE14A844229BF94D3ULL, 0xE9C8F29ACF6AA153ULL, 0xF3CE6F25576E87F2ULL, 
            0x5987B570209F4F46ULL, 0xB85D4213F9BCB748ULL, 0x21021D27EB79CC55ULL, 0xAA5ED39A27523AFBULL, 
            0x2AD7339BE592F1B6ULL, 0xA70A61EAA400EC33ULL, 0xDF4E4FFB70F8CA67ULL, 0x8AA22DB104543053ULL, 
            0x665B3080C5B414DCULL, 0x8B9CCF79A5819C94ULL, 0x4A433945758694CFULL, 0xE6CE3ADBB3551E8BULL, 
            0xD12C32A488B557FAULL, 0x435EB6E8B4114FD9ULL, 0xE0E5A0678F6946DAULL, 0xAB09EC801B589D67ULL
        },
        {
            0x10F16E604A56731DULL, 0xE48DBA3054803B2BULL, 0xC764867E759C95FEULL, 0x0B093AD84731C292ULL, 
            0x5EEF7B75C97E0CCDULL, 0x30752D9EA1977F78ULL, 0x5D8FCC0E45C0C396ULL, 0x07584ED43B149301ULL, 
            0x30CF9CE5BA1F92ACULL, 0x637677393FC08C0FULL, 0xF94AEB5AEEFDCB61ULL, 0xD3BE644D654A9434ULL, 
            0x5476DCD98E6A76C3ULL, 0xE2FAB28CF4C2A40CULL, 0xEC370FF23F2CE2CBULL, 0x33D1E3F5515EC16DULL, 
            0x396F972C3CE28400ULL, 0x8242BFB46AFEC86CULL, 0xBAF0553153291933ULL, 0xFC258BF2FD097674ULL, 
            0x12DF2E6EE8C7F893ULL, 0x58C4B446105014B3ULL, 0x99956B6FBAC54993ULL, 0x45A71097ED5A5C63ULL, 
            0xE715AFD0ACE35481ULL, 0xF90DE1931B5FAC7EULL, 0x9ECAFFCAF4C33670ULL, 0x74D353AC7EC80804ULL, 
            0xC9C150C23BB2D7A1ULL, 0x3997DCD0091EF1CDULL, 0x20A25BF59FE2793CULL, 0x63C16B836A262469ULL
        },
        {
            0xE3FFE441BDA53350ULL, 0x783646388230AEB9ULL, 0x4E23E34B7B6DDAE9ULL, 0x12E8D15854F26CFDULL, 
            0xD2683C02966D8D02ULL, 0x27C00C6F011C2DD0ULL, 0xAE947A48E4123484ULL, 0x7328F7DC7DFEE885ULL, 
            0xAF9FB83F1E6C6007ULL, 0x6DE86E383312D726ULL, 0xA17CA36253CFC4FDULL, 0x81B583EBD82DECA5ULL, 
            0xA381329024F31142ULL, 0xD14510B8258DBFDCULL, 0x7B9687579AEC13D6ULL, 0xD65AC1712203F064ULL, 
            0xA8BB02208C35350AULL, 0xA9647424B3243A94ULL, 0xF249645FEDDE06D1ULL, 0x75C66D723F31B32FULL, 
            0x3DD71595955D0554ULL, 0x5F620B00E15A2724ULL, 0x948B893B2D8960AEULL, 0x67E507855A09607CULL, 
            0xFCF3FF3127EC45DCULL, 0x209BD4522F2DFBD1ULL, 0xC1E491EF4617AF7AULL, 0x5D748C6E3AFA63BAULL, 
            0xF40E686A254B7258ULL, 0x5526E83DB908016EULL, 0xBE63A1C402F84737ULL, 0x5FE49E36B9C604D4ULL
        },
        {
            0x31D42B3E3A228E50ULL, 0x482AB9EFCB2B7B64ULL, 0xD93A2406B83B9121ULL, 0xA70DAFF4A8A330F2ULL, 
            0x650D845CB98DF4FAULL, 0xD8B1461392956534ULL, 0x11A2775899CB818BULL, 0xF33B7FFD6C78815CULL, 
            0x9B114CC98311B2CFULL, 0x87E2E4A4241AC09AULL, 0x83105D1AB66BEABEULL, 0x96535E86A34B4235ULL, 
            0xA512D29B473EADD1ULL, 0xC8E4897DA16490A5ULL, 0x6FBF617A376CAEFAULL, 0x399401179197D9A2ULL, 
            0x75CDCC4DB5243DE3ULL, 0x22C1748C759F5F30ULL, 0x0DEECDAF0C0CFDE8ULL, 0xDF601F33D3645E65ULL, 
            0x8B9206D199003006ULL, 0xA7D1D008E2192AECULL, 0x655A056995269AA0ULL, 0x6EDA6661FB752189ULL, 
            0xAB39503B0E2A22E7ULL, 0x9A0BAC72ABD4250BULL, 0x23703AD4161FBE74ULL, 0x2D669702D6B75164ULL, 
            0xC7F693355C83E49BULL, 0xB61AF780A5079E63ULL, 0xAA3B86B1C9797DA4ULL, 0x9FF24704CFB885D1ULL
        },
        {
            0x0F70A3D491A21F63ULL, 0x38388A6811909573ULL, 0xB3A37283CA4706A9ULL, 0xFB11006A75592ACBULL, 
            0xFDF8EED522F6EB05ULL, 0xCC46EA4ADC7B6EB8ULL, 0xAA19BEF34544DA49ULL, 0x880DAAB0B51D59A1ULL, 
            0x671D5E3C84EBBAFFULL, 0xE99C73B6C1A77397ULL, 0x75289628F7D1F843ULL, 0x008684CE1D66F9EEULL, 
            0x1FBEC66A45AC6566ULL, 0xE7845500C953DCCCULL, 0xE0BCB7968BFB399AULL, 0xDC0CC30F04623D2EULL, 
            0xC911CB367C545C6AULL, 0xAD545F9E5AC2ABE5ULL, 0xA1E7E3224118D82EULL, 0x7F39B0D0576DC71CULL, 
            0xC163355734B6CD48ULL, 0x2D654C63E9D581E2ULL, 0x7CE82F557F3CAE3BULL, 0x21DDD4D17F31A075ULL, 
            0x8D3D74564DFAF154ULL, 0xDFD903B28FAFBE03ULL, 0xC822ED8D8F2B7D5CULL, 0xE0498E4B4420ECB7ULL, 
            0xCC2FAF47A7D5580CULL, 0x2E15EA964DF9E29EULL, 0xCF08136E63825ADDULL, 0xDEE502CE76BCA595ULL
        },
        {
            0x8259E52903CC87A4ULL, 0x5EDB13EDAB11A090ULL, 0xAC2BFC04EB213AD3ULL, 0x559CBC86340822CDULL, 
            0xD0115BC3E05CEE7AULL, 0x13B90CB693BF7026ULL, 0x75D6F3668D824111ULL, 0x91E6D4F04D29C867ULL, 
            0x8C8E4BF157BE509FULL, 0xE7690617C930A2CAULL, 0x5BDAAA01A4A63AF6ULL, 0xC73092CEB850F2A7ULL, 
            0xDB1CEA7776FABBD6ULL, 0xD5F6B516877EAD83ULL, 0x9E1A5A184D197FE5ULL, 0xF8EF517EF8D98FE8ULL, 
            0x081D85A8D492B1FDULL, 0x2BF58303717FAFC5ULL, 0x40D07F6637A948BBULL, 0xE0C632B1E01BA4C7ULL, 
            0x190B5D0D584AB320ULL, 0x7CEF6B521A2B3602ULL, 0x148A191AB847FEAFULL, 0x6E879EDF51BFCC51ULL, 
            0x32E9992766710C78ULL, 0xFC908FF27997F09EULL, 0x73C68C7BFCC81202ULL, 0x3807FD7F00400987ULL, 
            0xD35F2BBC22556551ULL, 0x883DE9227A94CC15ULL, 0xD058A4A79440F2B4ULL, 0x3D7BAA4FBB671F91ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alkaid::kKeySpawnAConstants = {
    0xA41D8A5174215144ULL,
    0x4939F7D0D3F16C56ULL,
    0x1E438E6344E8D834ULL,
    0xA41D8A5174215144ULL,
    0x4939F7D0D3F16C56ULL,
    0x1E438E6344E8D834ULL,
    0x477BC8CA5C697761ULL,
    0x9DA4CB367884CF4CULL,
    0xC1,
    0xD6,
    0xB6,
    0xC9,
    0x76,
    0xD2,
    0xA6,
    0x37
};

const TwistDomainSaltSet TwistExpander_Alkaid::kKeySpawnBSalts = {
    {
        {
            0xC6769BEF7D8ACFB3ULL, 0x5DAE415488736F05ULL, 0x50394DC13C6C3C51ULL, 0xA2A1E15BAC485ECDULL, 
            0x8AAE6B1633710E03ULL, 0x4946ACB279DF2BF7ULL, 0x8D4316157610AF83ULL, 0x8A1E2FD28F21158AULL, 
            0xA4ADFCB144A8A601ULL, 0x600AB867D54F92CFULL, 0x73DC38594CD930B5ULL, 0xACA8EEC34F1A246BULL, 
            0x568FC1C76FD399EAULL, 0x6BBD71B7210C83A3ULL, 0xD1CCB6C73CE04EC5ULL, 0x768838A80168BEBBULL, 
            0x82F47E8E52E25199ULL, 0x2BA9AF443B880ACEULL, 0xB0B0B0E7E61F9D8BULL, 0x69CA03B08BB204BEULL, 
            0x96A4DE8EC32ADABDULL, 0x3F9B119468A1D1F9ULL, 0xA96B09696B6E3BCBULL, 0xCBDE0EF406A80D12ULL, 
            0x27F75F209833E01AULL, 0xA5D709AC6DFF6851ULL, 0x6AEC35578F48E667ULL, 0x947F4B965F6F1811ULL, 
            0x0307B9EF303673D9ULL, 0x99D1626A87BA88D0ULL, 0xFC99886B6FF143DBULL, 0xE59D7125C464A2E0ULL
        },
        {
            0xC52562547B09781AULL, 0xFC29C9E7482939B5ULL, 0xED6359418CCF6334ULL, 0xFB91BED3AC95159DULL, 
            0xCA3E62475F60BB42ULL, 0x349223B1037F6DE8ULL, 0xC57B5D0CF6802FEAULL, 0xE4E79FD168B5CE35ULL, 
            0x07FE03C8FFF325BEULL, 0xC3A89F00FF03DCFAULL, 0x7DCE94376995FEDBULL, 0x138FBBF7B2D182C1ULL, 
            0x6036A2380C335177ULL, 0xA764A1E40E075B11ULL, 0x2B558580D44461E7ULL, 0xAA2ADB43005A980FULL, 
            0x319D852F67D9A7E0ULL, 0x7321AACDE2484EBAULL, 0x5043DAB68353DDADULL, 0x81E8F30EAA9387E4ULL, 
            0xAAF2ABB8BCFBAA73ULL, 0xE9E70AB7D0E1E799ULL, 0x39B833BA3F069327ULL, 0x958D2504B4C7CE34ULL, 
            0x02EBF179D2999F19ULL, 0xDA940A8DC5BCCAD9ULL, 0xFACFE2159C27EB4CULL, 0x785B1E0FE20F6357ULL, 
            0x2B85D81415D1DE77ULL, 0xEA9E48BDE5313702ULL, 0xCD05128B6CEFD32BULL, 0x09A93FD3216A2FA0ULL
        },
        {
            0xCE30B98AA017A0B4ULL, 0x9A67DDDD3A0A8EF4ULL, 0x63A74A4D3E132CF3ULL, 0x7C8A160FA0556DCFULL, 
            0x3D4298CF63B0429CULL, 0x9459D37EC8A94433ULL, 0xFBB407D7352E28E8ULL, 0xCCDED8C79C03F44FULL, 
            0x7D6B0A5570CDBD5CULL, 0x0C5105DC5CA3727FULL, 0xD3935F4B17FBE0A2ULL, 0xEC69A8841F43AEBAULL, 
            0x623C64F7E6765183ULL, 0xF573057AA83F662AULL, 0x150FC27A8AF9ABFBULL, 0x0FE6CA1A26E69AD8ULL, 
            0xCD8BF411A3FA02A6ULL, 0x5C3F05E1B110CAEAULL, 0x13D1F216F5284F98ULL, 0x3568B2F4291FE698ULL, 
            0x23FA8790D8786C66ULL, 0xB086C0C7C1D56772ULL, 0x0091ADF51A4A9823ULL, 0x23A584B1F50D08F1ULL, 
            0x96508F373A2A6DECULL, 0xBEE0D751164D4FD2ULL, 0xDB9A5BB9463210C8ULL, 0xE2569F97AEC15DD4ULL, 
            0x988E1CBD008FBBF3ULL, 0x312D1576B1199F41ULL, 0xF6E104B577BB6FE1ULL, 0xD5EB7FC9D6995DC0ULL
        },
        {
            0x4D585ED63C390A32ULL, 0x1B3A8431641E0BE4ULL, 0xA1AF143099C96022ULL, 0x99BE1103A5B1B571ULL, 
            0x1BE2652BAA62CCE9ULL, 0x1860456CA48BBCE8ULL, 0x73DDE378F7B6BBB2ULL, 0x03EC0E5EDA5F0566ULL, 
            0x0BEA4CBEB3A67C80ULL, 0x80848DB34BA5EC2DULL, 0xB256709732FECC29ULL, 0x45183E3F51E22DE5ULL, 
            0x539D650BE9809189ULL, 0xA4BEDBDB52793100ULL, 0x2DE79685415216DEULL, 0x179E24BABCA5AB2AULL, 
            0x0587AE6AC87DD1CCULL, 0x181B44126BFEBE8EULL, 0xE809FB4B94F50BA4ULL, 0x1806D77A4913B72AULL, 
            0x27F20D25FBDCE7DAULL, 0x1F9C7832C66131BBULL, 0x65A97BD52C3CED61ULL, 0x98CF293C5EE83083ULL, 
            0xBE70529ACF3A4ADEULL, 0x4888BB75C0682B74ULL, 0x2581349B5F65E656ULL, 0x37DB1AE9925E9D82ULL, 
            0xEFCA86B11A6F50C2ULL, 0x1E22DFFFE5221FE4ULL, 0xF8EF112C6B1A5C48ULL, 0x9D50E0E363C717E7ULL
        },
        {
            0xCC338BCB2C686A6DULL, 0x6AAB36174E338422ULL, 0xF8EF965718DD7FFAULL, 0xD28B8D7625CB8BA2ULL, 
            0x274F2D51653B3687ULL, 0x2CB86037635EBC2EULL, 0x36B28AF967A937FFULL, 0xC181443514D08986ULL, 
            0x09FCA9F85C336407ULL, 0xD9E4C09149DBBCDDULL, 0xD0E6E4C906B98F41ULL, 0x8453573FF8056B57ULL, 
            0x2B490B6106E5D6D8ULL, 0xF0FDA204FBDBDB64ULL, 0xF38374EDDA14FE0BULL, 0xA14F67F243184058ULL, 
            0x7736BCC3AD469F55ULL, 0x863CCA59197DBFC9ULL, 0xD8AA1E6DA21C62EDULL, 0x3252A56B992D18D0ULL, 
            0xE05D64C71F07B072ULL, 0x68D0805B462DB9EEULL, 0xF0FCCB3BE3B907C2ULL, 0xE005E9D20205C669ULL, 
            0x7F94CCCFD7BB8940ULL, 0x35052E25FB2A53BBULL, 0xEE02972D07550103ULL, 0x6408AFA5C65B490DULL, 
            0x14A9FE9E6C99C21EULL, 0x41AC7C894B0CB8F9ULL, 0x38EE2F71A10CACDEULL, 0x11975A713D7F8274ULL
        },
        {
            0x8B1BB2C8BC2B045BULL, 0x2863305654277DCEULL, 0x153102AB8ECD2E17ULL, 0x1A9B186869042EF3ULL, 
            0x97F41F9BCA0B0CDAULL, 0x2831893B3FB504D7ULL, 0xAAFCD27EEE06AFA6ULL, 0x7DA0FF53120C4CADULL, 
            0x30F39095AE67A91EULL, 0x9B30E2C48145BDB4ULL, 0x283D3B0406DB801BULL, 0x1CDBD13EE83060F8ULL, 
            0x65B6CB78E160E91AULL, 0x3983542A88B02AEBULL, 0x03FFA4D472C77C0AULL, 0xACD58D40F4C79D8CULL, 
            0x6CA50B05A3E764BEULL, 0xCB22960DB02109B7ULL, 0x51AD7FD49A0EE3CDULL, 0x0386949DFC2A14FEULL, 
            0xB8B871A2C8BBE448ULL, 0xC1EC9095C4992A95ULL, 0x12F63AC093417948ULL, 0x960D13C48E6C1C4EULL, 
            0xF93E73199104C16AULL, 0xE49FD2130F80A20BULL, 0xC857BA77DDF357EFULL, 0xDDDC6953B871998EULL, 
            0xEBE3F6AFFFBD09FCULL, 0x52EC51AFEBA05352ULL, 0xB304D75B61CF50CAULL, 0x7886645D323CBB49ULL
        }
    },
    {
        {
            0xC8415BF476360E0DULL, 0x1879446CAA02D2BFULL, 0x9F9BCE88DE784129ULL, 0x21DE817A3DD64CF2ULL, 
            0x35D8687102ACE52DULL, 0x89ECF4A148DE1BA1ULL, 0xC1142A29D5F61D9FULL, 0x3E23D0AFB45BA8C2ULL, 
            0xD830B8225AC93563ULL, 0x7FDA61C22E609998ULL, 0x008A09ED16D20140ULL, 0x1CE656D0C62F63B7ULL, 
            0x09E0B4A435DC6E0EULL, 0xAEF25AB71CF5AAF2ULL, 0x29BDCA7E1B15D765ULL, 0xEF8FCA4DB78C7D66ULL, 
            0x4849E4A85EEA8DCDULL, 0x70BB9A8030827D59ULL, 0x23C4FE91FF1DC17DULL, 0x0E884BDDAF74FE45ULL, 
            0xFAA0626989A1FCE5ULL, 0x360F08EA09FFCEFEULL, 0xFF4C17D542C65274ULL, 0xDFCE0A70826BEBC6ULL, 
            0x53BFC4DEC098A773ULL, 0xDEB2237CE9581F3AULL, 0x138D8FDFFB58BDC7ULL, 0xEC4C42F2CC3817DFULL, 
            0x3EDD8E8829C34EA4ULL, 0x304FCE9E44430AB2ULL, 0xC3310F4CAE18C229ULL, 0x1BBE598E66C2951EULL
        },
        {
            0x235C715CE9B013E9ULL, 0x3BA74AD2E46558E5ULL, 0xC1224C5CC5161565ULL, 0xEA286D6BE4754B72ULL, 
            0x1FCD3188DB40EE5DULL, 0x7D1314993F6FD209ULL, 0xA7BB77F0718CEA01ULL, 0xE3CD73D388CA7578ULL, 
            0xFF48FD1A15E9014EULL, 0xC9E1DE83417D9371ULL, 0x97E209693A815E75ULL, 0x266948D97AC59FFDULL, 
            0xF2993942BCB4858DULL, 0x2556E83C075B531AULL, 0xC010C1B53CA98ADDULL, 0xDFD10A1D7734D0D8ULL, 
            0x244BAF3114E8AA9FULL, 0x318BD1C0B4A140A6ULL, 0x447755CE88F81409ULL, 0x40A448345C33746FULL, 
            0x5741D0E656713B34ULL, 0x114663AA7603A992ULL, 0xDB267224FDEC2065ULL, 0x4620177B3F64BBD8ULL, 
            0xFAE6CF3093899329ULL, 0x63E95E40D3FCA593ULL, 0xFBC98877A15C62A4ULL, 0x821B277F592B4C4EULL, 
            0x247A8623BFCB1376ULL, 0x5D1DB847D1AFAC78ULL, 0x104AA7F1ACF5B892ULL, 0x6D5A852E38751341ULL
        },
        {
            0xF8E6B98710C3B04EULL, 0xFEBECCA93853F7C7ULL, 0x2DBED56D5E5BD220ULL, 0x7F74BFCDCF441C2CULL, 
            0x8E36BFC2F5265C32ULL, 0x9F3869A88FD53856ULL, 0xA8A020FCAA45E6DBULL, 0xCAEE78C32B8319E7ULL, 
            0xE3FBD55E8725A4F2ULL, 0x4B20CC7002FC3BD1ULL, 0xDBB0EF9D440BF264ULL, 0xA08FA0FBFFBB1F25ULL, 
            0xCA4915250CFF3B76ULL, 0xD3C8DE59DD17C3F1ULL, 0xE1D6276484E60C90ULL, 0xD27C04A08715FADEULL, 
            0xA0D6FE6E0D26CAEDULL, 0x0FDB63A569ADF066ULL, 0xF97A4AA6C5891FD6ULL, 0xCDCCE54CEFD2A1FFULL, 
            0x05DB0F8BB68457E3ULL, 0x02CA60DC772A57CEULL, 0x9FF56B366A5FC070ULL, 0x2184AA3F70055A6FULL, 
            0x052EB569A590D191ULL, 0x15FF061C66A2011FULL, 0x6D1C84B6BC174651ULL, 0x0E8F07BF1DCAADFBULL, 
            0xE441D0B853006B41ULL, 0xB098CC5C9A3744EDULL, 0xA8505A7B0B5BDB0DULL, 0x4D96122289CA1FA8ULL
        },
        {
            0x221C3338E363DD02ULL, 0xB0BFF77F86F384BCULL, 0x651670A20225ACA5ULL, 0xB4188E1B823F28F6ULL, 
            0x1DBF717B4D261391ULL, 0x1BBCA6F440C66DAFULL, 0x6640A74FF6912395ULL, 0x632370C95DC84578ULL, 
            0xDF523E76996AC208ULL, 0x8E9CDB4CBCAD1E73ULL, 0xC6954A5997ABCC78ULL, 0x9370FBBCEF75AE78ULL, 
            0x15915AAEEBE6C243ULL, 0x4A2C93B539BDCEDBULL, 0x25FCD6B032B454FCULL, 0x9512F53FE215F936ULL, 
            0xACCCE79D5F63DE06ULL, 0xEE8EF270A6ECCB84ULL, 0x8E19B96DC44F26D4ULL, 0xDDCD61DCBED6D016ULL, 
            0x14276924352F5ADEULL, 0x5DCEBDA16D504B38ULL, 0xCF70474E04BEFD27ULL, 0x963C23F8D2C1AADDULL, 
            0x27794BE70B0BBD78ULL, 0x03D7BB9EDB92DE17ULL, 0xB7DB29DF298ABF23ULL, 0x8F078FE032E5520CULL, 
            0xB3E538ECAAC8EE8FULL, 0x8CF7FA8FAC29E499ULL, 0xDDE64457D114F9E3ULL, 0x48766707C394AD27ULL
        },
        {
            0xBD1EA92E6E15243EULL, 0x6DA29D5DA61AC4A6ULL, 0xD1A8CDE29F3CD0AFULL, 0x3876E0BF6178E13EULL, 
            0x7CA2512D7038D1DCULL, 0x492E6C4F97684E61ULL, 0x1E3FF977918C198AULL, 0x89DC12830FE942F8ULL, 
            0x4930893EB684AF7AULL, 0x37EB580C5C900349ULL, 0x170EC2D5BB021DC4ULL, 0x026D8E815139068FULL, 
            0x655A2D5F24372295ULL, 0x1AB5B4787484DB0DULL, 0x5ED1191CA8C880DEULL, 0x03DE98DB0A69743DULL, 
            0x01F45D9249DF89F6ULL, 0xC9E3377CD17CD7AAULL, 0x98A5F86F4890B97EULL, 0x4174DB51FA38CECAULL, 
            0xA580EDFF67C35FD1ULL, 0x3C11C420856769E9ULL, 0x405926081A62C996ULL, 0x74D88376600359FCULL, 
            0x753399EF65648AE6ULL, 0x95121D5778518CB3ULL, 0x47972BDBD0A89A8DULL, 0xC8873AE9C8C2B35DULL, 
            0x9E71AEC259FC30E7ULL, 0x0F26BF9D4108090DULL, 0xFEA0E15E744F49B2ULL, 0xCAF0ED442DDE964AULL
        },
        {
            0x02C6EAF47038091DULL, 0x5DEFF5C48CA35E6CULL, 0xA552E0DF5D1693B6ULL, 0x9A6755F96BE150E7ULL, 
            0xAC3A0592182ABD48ULL, 0x7765D116E51F03D4ULL, 0xA806FE6B6FC94B8FULL, 0xCB8A8221E1620365ULL, 
            0x988C4F526FA9F331ULL, 0xC0CA2AA7462D435EULL, 0x4A1307D0EBFE5F1FULL, 0x4D78BC6ABBF7076BULL, 
            0x5E27ABD0C4EDDE24ULL, 0x2A055A305E2D3FEEULL, 0xFBF11E8098360EAFULL, 0x95D00F165803AB43ULL, 
            0xBC054234F594E42EULL, 0xE45A78674A55F18BULL, 0xB82ED4B5337854EAULL, 0xB4F18184AA783030ULL, 
            0x198EC9E60CABA4BCULL, 0x7A0A7DF4186FD2CDULL, 0x3114C5236B717D9AULL, 0xD8B84F81C9E74D78ULL, 
            0x628CDB9550DCDA7AULL, 0x615B5E46F4B97496ULL, 0x3C3DD79D42161D0DULL, 0xA1D3262F6D3F10A4ULL, 
            0x670424F1F09434DAULL, 0x967A195C08086B1DULL, 0x07040C86D04730BCULL, 0x40F450C17B696D55ULL
        }
    },
    {
        {
            0x267A79B3B45C8C16ULL, 0xF2FD1BC085EC9F88ULL, 0xE943325A3CC837C0ULL, 0xBA1F396124BDA3FAULL, 
            0x1EFBBD667DC9F7D8ULL, 0xE27EC2C94B8D750DULL, 0x530F9D5D73E89C92ULL, 0xB76504B6D7C19078ULL, 
            0xC9A8B728990BF811ULL, 0xDAEEBB7432CCF250ULL, 0xC377ACAE57AD223AULL, 0x3A48EDDC4D6802D9ULL, 
            0x3AED33F319180A2BULL, 0xA092A0AFDF41A232ULL, 0xEE9234200AA9D979ULL, 0xC5E08389E19756ACULL, 
            0x2C433594823C8AFBULL, 0xB228F28DC3759104ULL, 0xEE8B743D19FF5F71ULL, 0xF898B77128D0F0BEULL, 
            0xE776941696802623ULL, 0x0578BCD3C31DD3B4ULL, 0x25A64C2D146BF5E0ULL, 0xA82BFE0A313F0404ULL, 
            0xE49B8945EAA89AD7ULL, 0xFF0E2B629F25B8D8ULL, 0x46B48EB56017F4CFULL, 0xF97760F325F88669ULL, 
            0x24A45315D42ED2D9ULL, 0xA00FFE22203A8EFFULL, 0xF463AB0A95351464ULL, 0x9292C4D928DA9657ULL
        },
        {
            0x392BB0E62E6E8305ULL, 0xF046D2DFF91AD754ULL, 0xB99E9BDB3D3A819AULL, 0x447BE41CF1CC2EA3ULL, 
            0xF6F88FDE8D53224AULL, 0xF508EB223612C7C3ULL, 0xA293D717422D3EB6ULL, 0xF532D40D00B5B8C1ULL, 
            0xCE41AB5B30888495ULL, 0x37112E04659E66FBULL, 0xF68ADD5FA71BA3A0ULL, 0x2ADB9AE740A72F1EULL, 
            0xEBCB978B6A1F8F11ULL, 0xD2AA480C5604B567ULL, 0xB2999163F405EFD7ULL, 0x08D346BEFFA392CAULL, 
            0x1C899EA7D2CFA3FAULL, 0x7429A17BCFE40D94ULL, 0xC841C60C1AFA780FULL, 0xE0462BBABC85E929ULL, 
            0xF731D755DC3D1087ULL, 0xAE9AE5BB17AFA2EDULL, 0x1443449D7B23A8C7ULL, 0xA88B9BAE2B5B6D10ULL, 
            0xE71D9CAF9898F41BULL, 0x955A9E88A8200FA9ULL, 0x8EB6AF705D483398ULL, 0x23A459D49CD44219ULL, 
            0x245E215F44AFDAD9ULL, 0x6C58675AE588F984ULL, 0x5CA33ABA3FF55A0AULL, 0xAE2A3542521A9556ULL
        },
        {
            0x13F73900A264B987ULL, 0x16F01C31C376A747ULL, 0x24288D58D7488F10ULL, 0xC4E2E4F56A573B36ULL, 
            0x5E8B9B36290D9E41ULL, 0xC027AFE63DC74001ULL, 0x3E2F03A9B98C2BE4ULL, 0xFE8DC3006F343967ULL, 
            0xF49D26BAD0D8908FULL, 0x60C0149C6D0024FFULL, 0xCC203230FB6418B5ULL, 0x4CB6A2E33FCD5CE5ULL, 
            0xA734FA96188DC3F3ULL, 0x20DD7D0CF5787B13ULL, 0x24607BCBA3DABBC5ULL, 0x637BC0CA2A0F2D42ULL, 
            0x04F830424AD0887EULL, 0x5862F4D67A8852ADULL, 0xEE41E2C16C0F6142ULL, 0x515931F0E7F622F8ULL, 
            0x7907B8DC40E0C7B0ULL, 0x2B2431714E84C70CULL, 0x5B0F7433C0DAE853ULL, 0x05F4958421350124ULL, 
            0xE0B5B3B9703628BCULL, 0xA9C928D476282CCBULL, 0x329B65A20096A692ULL, 0x509865F852D704B4ULL, 
            0x5DCDA0A4E4C1C381ULL, 0x0D471451075636ACULL, 0x0EC1F53BB6EB3D9AULL, 0x48A36CE1DAD8B6A2ULL
        },
        {
            0x6FBAC3E1F569E22AULL, 0xC0633DE4AC5DE3FDULL, 0xD18652F66AB63126ULL, 0xF3EAA25E305506D9ULL, 
            0x72676F00074D7D27ULL, 0x1CC9AFDC13A6F9E6ULL, 0x29795E4A8BB65B33ULL, 0x5B9FECFC7DDB2DC7ULL, 
            0x618A5C9AE211CD65ULL, 0xB7839CF2FFE620A7ULL, 0xC0CCAE57A308ABD1ULL, 0x47FD151521E2F746ULL, 
            0xC6BA1FEA9E0EE56FULL, 0x848CC62AD0B9DB7CULL, 0x4946FC7B7B0963A0ULL, 0x1498404F9C41094AULL, 
            0xCFAEC600EE8ECD7DULL, 0xBE88F0305AEB5455ULL, 0x62A5FF9D98D8A9FAULL, 0xB1F814E9FA69FE24ULL, 
            0xE897ABF8D188A53DULL, 0x9705D262B8A3DBD1ULL, 0x4F353004A424B89BULL, 0x789D46D1D17D6A70ULL, 
            0xF823E815B2491AACULL, 0xCFC84514E3D88B98ULL, 0x854329FFDF2DF49DULL, 0xB1782F7BA0CB4338ULL, 
            0x44070CF6A4784A92ULL, 0xBF89603F93923EA6ULL, 0x8CB5CA7C1EBFB44DULL, 0x252277EDE64B363EULL
        },
        {
            0x5E3CB4DD841CE456ULL, 0x1CC74DDCE5F399C4ULL, 0x446F441456E566B4ULL, 0x28E30DF8B10D7EF3ULL, 
            0x0E07BC5AA98FC3F9ULL, 0x7F82D51A84602C4CULL, 0x2EE4C383A2FF67CDULL, 0xFB9EF8DB54BB8A77ULL, 
            0x0263EADC87F66DEAULL, 0x611B2FA4C7A06239ULL, 0x2B4CF83ADBEC4D23ULL, 0x6C7678A1DB976078ULL, 
            0xB1DF0A154DCB9718ULL, 0x3F8A3730E284D51CULL, 0x61B3F25ACA44F705ULL, 0x259465CB90B3CFF8ULL, 
            0x326941D3E15935CBULL, 0x4DF9BD387DCE0875ULL, 0x7BC2DD35825BCA4AULL, 0x891AF29E6F03B2D7ULL, 
            0xA7C2C0339F8C0DF5ULL, 0x0124CA7A70DC20AEULL, 0xB8EC6904FB2D8EC2ULL, 0x7C75932824A772A9ULL, 
            0xD2CC8A8A6C74F03EULL, 0x7628CDD96FC7B29AULL, 0x6D669FA57CAEE144ULL, 0x013481F3DBDFCF3CULL, 
            0xCE7A29D40AE6009CULL, 0xE1DAF57342C872B3ULL, 0x7CC694EF39B7140CULL, 0x83A544F3FC6445BEULL
        },
        {
            0xB9A288E4E05F90B9ULL, 0x486BF562D9AA3B30ULL, 0x580F851E94238A6BULL, 0xD0C9E8EE8DD03458ULL, 
            0xD44AB21AE9F564D8ULL, 0x900B9390E54F1801ULL, 0xB49AB040A076F53AULL, 0x9509A3B5044FFB88ULL, 
            0x5D9B4A6F9E00EE7EULL, 0xB260B65E5D8250ABULL, 0x2C3C52C313A9E194ULL, 0x4B6FF29C60404CC8ULL, 
            0x6BB9DF7FB9CF034FULL, 0x786E2793E52A1FDBULL, 0x8C5FA8CA7C8D8462ULL, 0x1845E8F00A3396C7ULL, 
            0x4DDE0E4198D35532ULL, 0xD349F29E6D0AF504ULL, 0x78BE7679413E0A5AULL, 0x2DEECEC48DED80C2ULL, 
            0xC6FBB248BE33E76CULL, 0x8458E92CD09FE655ULL, 0x49853E66A3BA4CF5ULL, 0xBEF9895675221C7DULL, 
            0x17F7835DCE585231ULL, 0xDE400240892DB5C9ULL, 0x68C7A0E3766BA076ULL, 0x4F1F20FFC11E29ADULL, 
            0xBEE8716F3C82215FULL, 0x5CB64B76E20261D3ULL, 0x613476AD0C371507ULL, 0x451DA194A24D035FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alkaid::kKeySpawnBConstants = {
    0x9AB155ADC372569FULL,
    0xB5E6ED9E9B5CBE35ULL,
    0xF8185747E0A6B620ULL,
    0x9AB155ADC372569FULL,
    0xB5E6ED9E9B5CBE35ULL,
    0xF8185747E0A6B620ULL,
    0xACDE0E6B10883018ULL,
    0x1B5FF821F13A2EC9ULL,
    0xA6,
    0x22,
    0x05,
    0xD4,
    0x35,
    0xF4,
    0xAA,
    0x62
};

const TwistDomainSaltSet TwistExpander_Alkaid::kSeedSalts = {
    {
        {
            0xC212E5D5FF1E9A67ULL, 0x4A337FDE2359D1C5ULL, 0xAF7CDB49CF974B8AULL, 0xE5E193CC203F4532ULL, 
            0x45D1219C3900CE9BULL, 0x917B17B0E1F642FBULL, 0xB552FB124EEDEC79ULL, 0x8EA3FC34120CCB42ULL, 
            0x6EEF6D120EC55BA4ULL, 0xC744992AE47BFAB5ULL, 0x2901DB3383FE508AULL, 0xF38F1B0173441CD9ULL, 
            0xFBBEC090714D0F73ULL, 0x7962C2F4221C8C68ULL, 0x495229BCEFEA5A85ULL, 0x2EF414155E37A3F5ULL, 
            0xDB3CD67FE77854D2ULL, 0x582E71519997CE07ULL, 0xBBE65D6641742AD8ULL, 0x29D3488FCA05D780ULL, 
            0xADDA9DA8104FBEB1ULL, 0x40006C58B7B573E0ULL, 0x03AEADF234CE408CULL, 0x32DA37C14B11CAC6ULL, 
            0xD59B2DE668609A2EULL, 0xC8D4E008F4AF1711ULL, 0x988758356D37B21FULL, 0x3A26B6A51E0B65D9ULL, 
            0x65980E5181C0A9F7ULL, 0x4D7E87098215862FULL, 0xA9738B7A3F1495F0ULL, 0x74AD6457A7CD5EBFULL
        },
        {
            0x6C85DFCC4972EEC7ULL, 0x6D27FD1D22717AC5ULL, 0xD778C85923BA2CAAULL, 0xAAA4EEE3A185F3A3ULL, 
            0x2158EE4A3D29E701ULL, 0xD32C43AFC8893EBDULL, 0x62FC195FA9C56C87ULL, 0x6E9C862A1E45DE2AULL, 
            0x5454927AABC43930ULL, 0xFF5C3B132620D155ULL, 0x4133DB5897FB2DB1ULL, 0x512CEEA4C25D83D4ULL, 
            0x1A5BA7931AA47F9DULL, 0x25913D72AD7354F0ULL, 0x74CB86A47E153E3CULL, 0xB7521D0CAEDC5F23ULL, 
            0xF3363DAF27E049B3ULL, 0x54AD7AC7F547A3C7ULL, 0xA8DE70C8B23BE3D1ULL, 0x1614042D40FDFF48ULL, 
            0x046A69F4A501941BULL, 0x446722C8DA3A4AB9ULL, 0xFCCA713A3119A794ULL, 0xC866389094863393ULL, 
            0xEDB6E04FEB15AAA8ULL, 0x6529B98C9BF1624EULL, 0x0DFAE9F585EA9517ULL, 0x137C334EFB1EBD02ULL, 
            0x857668268B50FE42ULL, 0x644AC4521EF49117ULL, 0x8F62A458B9FD2D28ULL, 0xE4161038E495AF98ULL
        },
        {
            0xD7DF5BBE2AC0F0FEULL, 0xEB64FDE3EE762A6CULL, 0x3493C881981C8B7EULL, 0x2B5FE97F5D1D0EFCULL, 
            0x3C91646D31B23E51ULL, 0x6B7E8710AD95EA16ULL, 0xE0862DE557BA44B8ULL, 0x0AE88F1A9BACC2E1ULL, 
            0x71A3744DBC24ED1DULL, 0x886204DE66298B17ULL, 0x26F467846F669AF3ULL, 0x4B71AA2142120375ULL, 
            0x756CF8101635A4D5ULL, 0x06E0C4E7DACBE5D6ULL, 0xE5C4CC9786655A70ULL, 0xB18490BFA9E93137ULL, 
            0xFB3E26A687CBAE8CULL, 0x58DB09F2F778AFB0ULL, 0xC28C33B18AE87425ULL, 0xDF3ABBBD33D31A01ULL, 
            0xDD3A129EA3E1B930ULL, 0xAB17612F52AC1DA3ULL, 0x09A8C8A7CFDE8086ULL, 0x8E65A846A390EBE2ULL, 
            0xD4BA2CCD6E760232ULL, 0x52387F751B57949CULL, 0x7A46CE0C2FDA2E86ULL, 0xB6141B606F29E5E5ULL, 
            0x22399207766D05CCULL, 0x8ADEE147862F0470ULL, 0x1799CE59F5E1ACE8ULL, 0x8F32BCCDA05D86E5ULL
        },
        {
            0x937C3361E300EDBAULL, 0x9420031FAB423026ULL, 0x6E582796D7947B29ULL, 0xAE31A769995CAA1DULL, 
            0x24DD7E18D725561CULL, 0x1EEF62BF1B1AF7F8ULL, 0xB84F55507A2C9043ULL, 0xBD414C67D5017878ULL, 
            0x2B24F3E0C9DF6E6DULL, 0x139A6BF17A082AF0ULL, 0xEB4FCA7A79BA59C0ULL, 0xB2743CB9FF8A19BDULL, 
            0x1F04293FE8D1451FULL, 0x43078D564B441B37ULL, 0x8796D1D49DF00B64ULL, 0x7F8E02C20CDB7FACULL, 
            0xBB73AC45486ACAB2ULL, 0xC34ACBB8D4350CA8ULL, 0xC3671D3D5C7ABC1DULL, 0xFEF6515277677896ULL, 
            0x922FCE1055E32D4EULL, 0xA0E7A1AD49515711ULL, 0x6BDCA59045807E6DULL, 0xDE835E4E0A5D9DBEULL, 
            0x1B92DF4FC46590A1ULL, 0xA5123E4EEB6F2A3BULL, 0x1A4EE1B2B62F089DULL, 0xEDCA91CEBD311E91ULL, 
            0xEB405FCF28C3B7CBULL, 0xB6A1BA438729133DULL, 0x940174102575D61AULL, 0xE035DB4D510F5A18ULL
        },
        {
            0x7F344F49BE8E9D91ULL, 0xC767E84F5FCD6C4FULL, 0x13D356A1B7C7F762ULL, 0x19313C968339BE0DULL, 
            0x742E8053B6041BB1ULL, 0xE8A3F829867B2808ULL, 0x16DA24650E2EF3F7ULL, 0x906C85F4CCF8AA5DULL, 
            0xE07019C84AB1339BULL, 0x2EB2EEB992ED9F49ULL, 0x8E1E725C23D7213AULL, 0x7D0BEDF3DC7C2151ULL, 
            0xDF6202E64EADAA2CULL, 0xF98A29727F78EED5ULL, 0xD80EBC2A45342138ULL, 0x7DC297C51F71ADA0ULL, 
            0xB7DC689D0387D208ULL, 0x6A472517A1C729B9ULL, 0x838AECB1777E4CA9ULL, 0x7B71B11A43ACE664ULL, 
            0x1B94233DE7DA877AULL, 0x382CB2E1DC0C5E9DULL, 0xF0152C50CA8A5051ULL, 0x38B956A634B832AAULL, 
            0x6CE39CD0D39BBF9FULL, 0x403DCF86679C81F9ULL, 0x28727D0CCDEAA31EULL, 0xDE68410E491C68F5ULL, 
            0xBEA1C0D706D5B790ULL, 0x8BDE78B8598CF231ULL, 0x9A0522BA9B4E5EE5ULL, 0xF83DC22AE02B8CC2ULL
        },
        {
            0xB40F4C33FA9E6427ULL, 0x0E2600950168FA15ULL, 0xE7719E69483B4790ULL, 0x6B93C1D7E630CD4CULL, 
            0x64C691B238334D29ULL, 0x82C16F81528B6A64ULL, 0xBF1F8C9FC7923C88ULL, 0x2DF79D35F7548E19ULL, 
            0xEEEAF5B169C01586ULL, 0xB206059DF7BEC545ULL, 0xCD772F5D6F44B97AULL, 0x0EFE881BBEDD7DDDULL, 
            0xE953C43CB2402FA6ULL, 0x2062826449883DC6ULL, 0x65C69E2883801385ULL, 0x52C747FA0A2D5F5EULL, 
            0x4C109431D7DD8187ULL, 0x0D5E7C06DF70D0A3ULL, 0x3082D98F7FB1C6ECULL, 0x545CEC862D894BCFULL, 
            0x494109AFA92DB1D8ULL, 0x90AE49C6D9CAF73FULL, 0x7EA850B3634EB45FULL, 0x6578FA1E6ABC3773ULL, 
            0xBEBADDB2AD5E067DULL, 0x323D0D5A4E945578ULL, 0x699CD698261F4990ULL, 0x8B7B71FF47488447ULL, 
            0xFCD927EFDF2EEC12ULL, 0x87860260423009A6ULL, 0xEE8C2B545976D8FEULL, 0x74736FC533A6218BULL
        }
    },
    {
        {
            0x0868AB780957730BULL, 0x9EB747BFD5012C8EULL, 0x71C54DCA838AF855ULL, 0xDABEF1D2B88C22A6ULL, 
            0xA69453FE00F8354FULL, 0x3FFBDE9FCDFE9B34ULL, 0x46A0EB5B01C3CC4FULL, 0xC804A6CB51C06D1EULL, 
            0x7B35330BCED36BB3ULL, 0x50EEB970ADB7873CULL, 0xD2A5F5020C576101ULL, 0xC0615AA4A575D935ULL, 
            0x4CA9855A752F185CULL, 0x3334B0F87C46AB55ULL, 0x5407389702027002ULL, 0x71B6D796381ED6FFULL, 
            0x9E0B55B404351F77ULL, 0x623F0BB7C761EF3BULL, 0x285D9DA7F20053D2ULL, 0x719F8238C93CA2D3ULL, 
            0x9D3AE92BC2E663B1ULL, 0x75018DD1534824E1ULL, 0x53A3CFAD21E56C93ULL, 0xBC711B8F679DE045ULL, 
            0x77131760C918BEF5ULL, 0x39E4DDE8DDBAAB4FULL, 0xD3847DE9FE6C1F3FULL, 0xC2910B99562E0690ULL, 
            0xF90807C1039F056BULL, 0x63230550241067C4ULL, 0xE0D2D209390C9045ULL, 0x214EE7E11A416AB9ULL
        },
        {
            0xC684C9B86932DD41ULL, 0x00D9E6DFDA31B518ULL, 0x10B014925210DAF2ULL, 0xCC6EC62E7C87B71FULL, 
            0x6AEE160DC08C0641ULL, 0x81ECE86397BBDAD0ULL, 0x7E6E9FB141FCB351ULL, 0x15A7A646BC8D2DBEULL, 
            0x395E178408BC38BCULL, 0xDAE93E66FC065D16ULL, 0xB4FF5FB5C0F3EC7CULL, 0x7BE5259A2C8E503FULL, 
            0x74A7F6C882C18A50ULL, 0xA0B478B855144C13ULL, 0xAEE7E05203D630AFULL, 0x48564E01272C2F2CULL, 
            0x5240D46BFACCD4FCULL, 0xEE10C68B19071173ULL, 0x2B5ACBB7D36764F1ULL, 0xF35DC83BFAC05860ULL, 
            0xBC6CC1364333C0A6ULL, 0x102E75867C7D075BULL, 0x4C5CF1A85ABA5A7BULL, 0x332447140D734BFDULL, 
            0xB21026230C19E48EULL, 0xADA10F9AFE9C1F0CULL, 0x5D94BE5D40A250D8ULL, 0x43009B0958D77D31ULL, 
            0x8784A25E859D68B1ULL, 0x65D3FCBF0EF1BE64ULL, 0x32B2333E090A73EAULL, 0x28ADF4790C2EA55CULL
        },
        {
            0x714A6A5D2578EEAFULL, 0xCB3F7F8950FE8FA8ULL, 0x8A087D08377C5785ULL, 0x5648C7C359998C1CULL, 
            0xABC36CDF0722CCADULL, 0x797ED819B8C305C5ULL, 0x65E7C656541E846EULL, 0x71E45534E5B686AEULL, 
            0x103B521A9BC051BCULL, 0x8B15CC21F1C0BC39ULL, 0x9637E0142788FAF0ULL, 0x4E1609C134057099ULL, 
            0x91BA075B75A55599ULL, 0x4471DED734CB1EA6ULL, 0xC98A5B1898767F94ULL, 0x779CEB24169CFBA7ULL, 
            0x057DC162F3E75A67ULL, 0xFCB47F5359BADD78ULL, 0x481FE02AEF796A85ULL, 0x1DBD4024AE898143ULL, 
            0x7EF2A5044348D2D0ULL, 0xC6AA818C4C9B4BEBULL, 0xC079A85B434D4F9CULL, 0x0AFF9065C3746685ULL, 
            0x6BF6A4A662344CA8ULL, 0xA942F6565F8608F0ULL, 0x2B51F4B0790C0214ULL, 0xDD32C8996745E3ECULL, 
            0x7549B7E887B5D761ULL, 0x96A4997200230923ULL, 0xB5B427F1B660D531ULL, 0x2385AEC84ED0482BULL
        },
        {
            0x7E2F5F7A45197824ULL, 0xB87EC5EAD6084DF4ULL, 0xD459188E0E9A2B26ULL, 0x1ED758315E903242ULL, 
            0x952D9D1E5ECD6474ULL, 0x1C4232DCD021800FULL, 0xD86E2EF82E92233DULL, 0x2410AF4C74DD9D83ULL, 
            0x8AC5D63C537EE720ULL, 0xE585B918E200D4DEULL, 0x912130611D4CA789ULL, 0x2B18423A7F1F3145ULL, 
            0x4D9BC6EA916C64A2ULL, 0x2CBAB3AA3F55E074ULL, 0x5AC79F81A57F1C41ULL, 0x17CF65D8EF7FBF76ULL, 
            0xC5CEA7DC8CF0D42CULL, 0x4122C72073B9ADEAULL, 0x89BE0CE503464133ULL, 0x286512A8135DB5D3ULL, 
            0xAE96C89797629314ULL, 0x27199690F515780AULL, 0x681B3CCB720303E3ULL, 0xBC3DEFD117F7D12EULL, 
            0x2295BF9079AE1B9DULL, 0x099FFFEAFD1B9716ULL, 0x534B74304AC39E3CULL, 0x9ED9B35982CD4F31ULL, 
            0xD4A4A802F434073CULL, 0x94D73B056529C573ULL, 0x3B9FE416BDF90223ULL, 0xF52B1C10FE97A78FULL
        },
        {
            0x1E2A7787D1A7538EULL, 0x69282C9114111AAAULL, 0x311CB1AD20C81DB4ULL, 0x8A9F69675D437879ULL, 
            0xB2A9CAD7727830F9ULL, 0x6F5409DC24B6CA31ULL, 0xFE005ECE9B28AD3AULL, 0xADCB05A65BB13D92ULL, 
            0x7C1AFFDCE2D0A565ULL, 0x15F0485ECBAFA3F9ULL, 0x2A60702BAC812A56ULL, 0x02B4A2CAA4D326D5ULL, 
            0x681D5F943F2FCE47ULL, 0x2521FA906CF68459ULL, 0xA8024A12123F5AFFULL, 0xAAFC32908512C1C1ULL, 
            0xD8177FBB4EB4FB58ULL, 0xE21937886E6484CBULL, 0x05CE5A905BCD8E8BULL, 0x47DD1F9D9B731CA0ULL, 
            0xDE009326E9EF6961ULL, 0x4AF92EBFC422DE27ULL, 0x70365AA49F9A7C8AULL, 0xE5694807B1F8B898ULL, 
            0xA3D0B6F00F402971ULL, 0x8BAC4D9D65A290CFULL, 0x5D24CE36D55B1B9DULL, 0xDA347D04031B58EAULL, 
            0x72CC57E6456FEE62ULL, 0xB48CDE64EEE482A6ULL, 0xF653F177A8531D10ULL, 0x8C6E60615021BAB3ULL
        },
        {
            0x8DC243256A35F554ULL, 0xC3891EE65BEBA77BULL, 0x79EBC76B40321DB6ULL, 0x961827BA1E21F135ULL, 
            0x72F28EEB7829C4ADULL, 0x56496C25B67D0C7AULL, 0x3FB43A0533BAB804ULL, 0x1EE5F459A620128AULL, 
            0x13D253ECC8845F8FULL, 0x4AACC6D2A826B618ULL, 0x5E3690191CCA47B1ULL, 0x50B18F3EE4FAACEFULL, 
            0x722FD64455C7AA6BULL, 0xABEFF61E3EB3C36DULL, 0xF74EDF24564AAC26ULL, 0xA7BE45F35768D9C4ULL, 
            0x86D230D88F35236BULL, 0x230F25DC51B3E1AAULL, 0xE1A69361129739E2ULL, 0x8F72A0466F753679ULL, 
            0x905361D6558BD568ULL, 0xBB02835E53512497ULL, 0x85A012FBD357AA18ULL, 0x2A42BF89FF4AE80AULL, 
            0xA5D88F6BA462D40CULL, 0x9FA04068067AA9BAULL, 0x621EBC319F9F0B41ULL, 0x436414AA06A499F2ULL, 
            0xCBBE01A87947D478ULL, 0xB705D88617852A40ULL, 0x221C68B124379A65ULL, 0xE309A0A3EB6DB3CCULL
        }
    },
    {
        {
            0x75A313D755C59E2BULL, 0x0B514F2D71586A24ULL, 0x854DBEA3FCAE9FE8ULL, 0xE52DAAD812AAF6CCULL, 
            0x384D8C19CCCFCC92ULL, 0x116A84DC34B1BA2BULL, 0x738680113F442E3FULL, 0xD285AB0E244C10A7ULL, 
            0xA7636548A8DB8692ULL, 0x3FC17CEF57EB31A1ULL, 0x66B7419213C80608ULL, 0xEA4CE05159C6821AULL, 
            0xBF2214DCDECD9536ULL, 0x055C5F1193FDBD58ULL, 0x52C80B70D9F2C551ULL, 0x52AF1852A112C0A0ULL, 
            0x33466D1FE30C3941ULL, 0xC3984EE376D40733ULL, 0x153A715B23CC573EULL, 0x734B1A6F2119DCDCULL, 
            0x01283E34AF9B2869ULL, 0x032C64BCA1EEACD7ULL, 0x5F0C9AE65C77278EULL, 0x365DEEB90D04DCF5ULL, 
            0x0DCBD00762B9CB2DULL, 0xF46CC0EC649CB927ULL, 0x1FF72252650B8C94ULL, 0xAB7296FF6522AC30ULL, 
            0x4B36225AD50A2A0DULL, 0xADFBC70044837DA7ULL, 0x7F2AD6494BEB2386ULL, 0x4631DCE6D1D4D175ULL
        },
        {
            0xC48F2F4F276A1142ULL, 0xA3D1C13FDA43D5ACULL, 0xA89DAE32491B03D7ULL, 0x7DBD5A39244383AAULL, 
            0xB9D1B96471469DD4ULL, 0xC66283E4DCCC257EULL, 0x141C42733E9C05CBULL, 0x6F8FD80947E50CA1ULL, 
            0xA0EA009DA1EDD748ULL, 0xF2410EEA699BC1BFULL, 0x0BB9C2B397772B47ULL, 0x46F8A1CCB57977C3ULL, 
            0x08F2B9226FC3E3DCULL, 0x3A63C8A50608473CULL, 0x897090C9201F7EA8ULL, 0x1CF532FD7A9BE0A9ULL, 
            0xD16D65F8F09089D3ULL, 0x3AC7276DB655F71FULL, 0x77F63B83D133D9D3ULL, 0xC84A122745BD6DB6ULL, 
            0x525E6510A8C32676ULL, 0x4B3048B06C4D47A3ULL, 0x5DF61DC19845AC57ULL, 0x6ECFF0E5E32AA949ULL, 
            0x2EA01CFD8EAC3A22ULL, 0x34C1DB8A93B88BC5ULL, 0x9AFDC8D1385CDB76ULL, 0x9D298F6B6998B833ULL, 
            0xBD59EE8A4406ADC5ULL, 0xDF83EC2D21660873ULL, 0x5146CD54DDEA8371ULL, 0xAFF3D22A58AED8D5ULL
        },
        {
            0x57465442D68FB521ULL, 0x5A758D5D4540A4CEULL, 0x10DF24381253B1D0ULL, 0xDDB6489CA4214C97ULL, 
            0x760AA9DC0E61203AULL, 0xD8469358BF713F03ULL, 0x4B56BA6D296DED29ULL, 0x736C1F4309763604ULL, 
            0xB93266BDF41A0DCCULL, 0x1BA0E1E3DC636C93ULL, 0xD767DE71C97441C2ULL, 0xACD2F61032548FB3ULL, 
            0x0DD3117D67CABCBEULL, 0x44A65C25CDC0F291ULL, 0x834EDC5BA1CB957CULL, 0x6E9EC6DBB82D7C66ULL, 
            0x9E648E2E57470DAFULL, 0x30AF25311F788855ULL, 0xB45B595EC98D9DC0ULL, 0x8224533553728C66ULL, 
            0x86BCC19E12D349F7ULL, 0x0601B7516AFDBAECULL, 0x33D97984A4E017DBULL, 0xB8BFC239C9FC0939ULL, 
            0x8B19ADFB0EB0CA02ULL, 0x78A583DC590A4E45ULL, 0x71D3084BEFD9320AULL, 0x157E010B4085361DULL, 
            0xD88C543E4EA40162ULL, 0xEBDE250EF3CE3BF0ULL, 0xF1F020CF95F5FEC2ULL, 0xE36A3AAF2594800EULL
        },
        {
            0x9542D8EC307CF114ULL, 0x7AD87C0945FF979CULL, 0xAE09FA4BF609879BULL, 0x94A460AB9F6A0006ULL, 
            0x9734B651E8C237B1ULL, 0x31638C79B7A41FDDULL, 0x19BFE82553D0F963ULL, 0xD5BF2F56F1E0C750ULL, 
            0x88F91E40FD98E3C8ULL, 0x624CF85298D5C6D9ULL, 0x92B432FFBC1779E8ULL, 0x54B9BD1E99C96E36ULL, 
            0x0CF75EADBE66BC65ULL, 0x6A6ACEA7E27D58D3ULL, 0xCA3DFEAE4222EE18ULL, 0x26A02C4A4AFD136EULL, 
            0xFDC4F13A6A36C938ULL, 0xEF678DA12A791CBBULL, 0x015AAA063F47F490ULL, 0x03AF038542E69F88ULL, 
            0x21CEF47C8A535CC3ULL, 0x6DF431B206A4287EULL, 0xA7AD18E07D742FBDULL, 0xF088D752CEA4A0D6ULL, 
            0x313FBDC30CD36292ULL, 0x6DCB88A618F7593BULL, 0xE0882C804342609CULL, 0x2EEB300A0D450D5EULL, 
            0xDD4DC0553BB4A88AULL, 0x72F80F9BC007E4FFULL, 0x652B385B67C13DB7ULL, 0x5FF9C777A993021FULL
        },
        {
            0xD9D383D27D206846ULL, 0x6539792580115687ULL, 0xE6935DEE46F7CFBDULL, 0x3193138E11E50F08ULL, 
            0x0D398C4A7C1DDA73ULL, 0x84ADF815D0CEFF05ULL, 0xE55CED9219563CDAULL, 0x22CD1093D86B26D4ULL, 
            0xD7A3ADEADFD115D8ULL, 0x9FF937106854DD5BULL, 0x692B2C8DCCFD87F8ULL, 0x401711A0749E95C5ULL, 
            0x87BE74E774FEA3D6ULL, 0xB5B174DB3BD72662ULL, 0xC0AB7BF83E6327ECULL, 0x4727A2126A7C51F0ULL, 
            0xD73510CDDD823DCEULL, 0xD45D38817E76633AULL, 0x9FDEC91D81F26A86ULL, 0x3E67C29F8B1F477BULL, 
            0x6055D9560CCE88C0ULL, 0x6084192FA04F1502ULL, 0xB791782F069328FEULL, 0xD4F9FAEC31A4787CULL, 
            0x66C3F442027234FDULL, 0x8887880A17878192ULL, 0xABE3B53CC9E7F8F6ULL, 0x5FB011D55C08E0EAULL, 
            0xD2B2EEA946A8DB13ULL, 0x5FD9CD5B7A37CFD2ULL, 0xC81AC865DD3270B6ULL, 0x93277F5FA5D5C1CBULL
        },
        {
            0xEB38F4ADFDE73B3DULL, 0x6BBA055B643618A5ULL, 0x619CFD6D0061B8AFULL, 0xE41950816E208C94ULL, 
            0xF46F604B0AE9BBE0ULL, 0x4FE1354A7D3494E1ULL, 0x8E83B034E582608EULL, 0x59C265F3087182F0ULL, 
            0x7D250D6E4BB15A25ULL, 0xC7462DEA2B78CAD4ULL, 0x4F081A70C6056E39ULL, 0x4A04C8991628002AULL, 
            0xD4342A5A31B31E06ULL, 0x58BA475103212D24ULL, 0xA52E9D279639ED68ULL, 0x1D5746C23D60A383ULL, 
            0xA6F94D22FD52A943ULL, 0xC0D2F346BE1841FEULL, 0xD4C822ECF67DC1D3ULL, 0x01DAF6EC77402D90ULL, 
            0x24A916ABEDC89437ULL, 0x8447CEC94AFC535BULL, 0x368FB56620511F8CULL, 0x2955C472BED267DCULL, 
            0x6886F9A8FED6824FULL, 0x2A97EA708DAD538DULL, 0x1F47F31032112C02ULL, 0x5CF45B2DA0DE23A1ULL, 
            0x270F2DCB91FBAFF8ULL, 0x59CE52AA2EF915C7ULL, 0xD8D339C57B2BE7FEULL, 0x22CEB9B20FD9BD65ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alkaid::kSeedConstants = {
    0x883D75DF8DAA4D2BULL,
    0x97FDDAB1E7AAF9A1ULL,
    0x5E65704FF85A40C8ULL,
    0x883D75DF8DAA4D2BULL,
    0x97FDDAB1E7AAF9A1ULL,
    0x5E65704FF85A40C8ULL,
    0xFBC342A5EA0C5E08ULL,
    0xCE3382C90E99E17EULL,
    0xE6,
    0x22,
    0xA9,
    0x6D,
    0x0B,
    0xF9,
    0x22,
    0x41
};

const TwistDomainSaltSet TwistExpander_Alkaid::kTwistSalts = {
    {
        {
            0xFF3B8AF0E8CDE743ULL, 0x00598F6968981B95ULL, 0xA29D94C21527FB55ULL, 0x8FDE1D3155EE2B3CULL, 
            0x5B3BF8F3F6BC9B55ULL, 0x3DB683F021DF34B9ULL, 0x0A03E6220F11DA3EULL, 0x1FBB3FD4C86AC48FULL, 
            0x7296EDDA5D8E446EULL, 0x8719DDCF76F884BFULL, 0x4DF14B26EA513475ULL, 0x9587CE4006929CCEULL, 
            0x08ABC02718118CAEULL, 0xC33EECCFA6508FB6ULL, 0xE0D54FC925C106E3ULL, 0x386D9A4DAFF082EEULL, 
            0xCBC9AA131CAF539DULL, 0x5611E59CC8F4C7A7ULL, 0xB85D8E96C0A6BB3EULL, 0xCCB2AA2ACDA8817FULL, 
            0x263DA233420A93D5ULL, 0x7F8450EF56FF44B9ULL, 0x2F60D32FC2409738ULL, 0x39A706F96469C224ULL, 
            0x16037E2254E40012ULL, 0xD438B6C8F41090FEULL, 0x0275C8504C282D53ULL, 0x5A58769A68C2B434ULL, 
            0x0CB52389C311B928ULL, 0xFDCA1288F624CC71ULL, 0xE1EDF4CEACF225ABULL, 0x48C0FAC71855FDE5ULL
        },
        {
            0x6B5946264B90C674ULL, 0xB8113708C43283DCULL, 0x8454FB911F53819CULL, 0xE5267145E6EF16A2ULL, 
            0x3CA353495EA8864EULL, 0xE4983E7CC7D422BCULL, 0xF3650B4075D284B3ULL, 0xDB9602C0914DC563ULL, 
            0xCBB2794876E39603ULL, 0x93A896E78FDA4F0CULL, 0x903314DB844397EDULL, 0xD45953E40133B80CULL, 
            0xB9F4D3691D3D8691ULL, 0x52CC3F8CF5C633BDULL, 0x94C0BD6C4A218165ULL, 0x43A42DF741E2DEE1ULL, 
            0xA2BC9B1FC36AF162ULL, 0x7BE89094F1881D53ULL, 0x4D7CD5557316C1E2ULL, 0x3DC7EB4DD14CEE4FULL, 
            0x3A0F41FC3957BC8AULL, 0xB9BFE98BC2F0845AULL, 0xEB8ED67DE2320ECDULL, 0xBA8F04496B63AA54ULL, 
            0x4FA6B9156A7BE903ULL, 0x9F14F161EE69EFFAULL, 0x8CB55026499B3A2AULL, 0xE19B2E1B58B878C7ULL, 
            0x2047739814759235ULL, 0x123FC30953122F8CULL, 0x5B778F302DB5E37DULL, 0x47EF8EB9599D6608ULL
        },
        {
            0xBA7CF3473BC3356BULL, 0x423250CD5ABC970CULL, 0xB3E5EECCBE2022FDULL, 0x18F4AB2AB7E9FFB4ULL, 
            0x2518A343F0942887ULL, 0x695DAD16E07D3CC2ULL, 0x3EF7A5B2FBC5018EULL, 0x5E21457F499F1071ULL, 
            0xF2834619F643BCB6ULL, 0x46E105107BB3ECF6ULL, 0xEE0E5744988A4152ULL, 0xCC984909C3ECC076ULL, 
            0x9F5E1A66191CCBF9ULL, 0xD7E2D129F605E7D0ULL, 0x649A4962E2CFBD44ULL, 0x85EA83AE281D765FULL, 
            0x68F19DFBB52D5FF4ULL, 0x401C1113DD06996FULL, 0x3D3F6D4C94074CD4ULL, 0x1DA150FC6998DE3BULL, 
            0xED6050783FFB64DBULL, 0x60E45D016E6E8B2FULL, 0xC2EA8EAC827184E3ULL, 0x5543466D2C26A36DULL, 
            0x72ED82ADE80AD534ULL, 0x0D9EDAD1CAFAE035ULL, 0xB0593CC16B59D848ULL, 0xAB9F04A4FDE31E60ULL, 
            0x499D0C8D7BF63340ULL, 0xE80014EC56B0A42AULL, 0x189FFB41F8B3C828ULL, 0x8DD653B08C9DF1FEULL
        },
        {
            0xA8B36D92B9950453ULL, 0xA25A2F6B0E915625ULL, 0xC15A3A1841FADF58ULL, 0xBACFFE461BD7E4CAULL, 
            0xAD341B241ADE23C1ULL, 0x49D4E72E2A74C529ULL, 0x32572656D79B98E0ULL, 0x66833961E6234318ULL, 
            0xB0ED9C60D5EABDC3ULL, 0x46C282B27842721BULL, 0x386420862FE19D95ULL, 0xA0630C0F2393D653ULL, 
            0x8343888B554E4BADULL, 0xF29CB4556AD32B59ULL, 0x49945DDFE13202DEULL, 0x72DB87D1A9392632ULL, 
            0x5E6CFB29C7AA6262ULL, 0x48F5C98302370A6EULL, 0xE091839A8FA31CC6ULL, 0x2700BD6984123838ULL, 
            0xAFC3A160BBD164F3ULL, 0x43BDC538FB8A12F4ULL, 0x14E4329F59273515ULL, 0x445CB738EA60EC20ULL, 
            0x1FCAA8F10F8B38E0ULL, 0x7061145604C102DBULL, 0xB710B1AE56080DB4ULL, 0xA535EC1929C2D580ULL, 
            0x8D193DE9E33C63D1ULL, 0xDC58325E3CDCE78CULL, 0xAB4F692E545FB9FBULL, 0x04146FA0CD562053ULL
        },
        {
            0x0FA161685C7D8B81ULL, 0x78E1D99C3E4ACA11ULL, 0xD569C987D059733EULL, 0xB774C774B1AC68B5ULL, 
            0x6BFD06A7248F9E68ULL, 0x16107C541AB4630AULL, 0x0464F5259D0CB1C6ULL, 0xF4EF81F7F0161ED9ULL, 
            0x1887379EEA0DB2B7ULL, 0x0C7C034B89A43044ULL, 0x2E3BDB3281563E48ULL, 0x44F4DA3897D4679CULL, 
            0xA33E18CDCFBDEA52ULL, 0x57DAEE527952F8F1ULL, 0xE36623A990AB6F9FULL, 0xE94E363DD05E508DULL, 
            0x06B028E6EF0633B5ULL, 0x3924797E614A89F5ULL, 0x1FD0223AE7A50AADULL, 0x1BD3639B7732933EULL, 
            0x3212862002D4513BULL, 0x8ACCEC4D2EABCED3ULL, 0x216AD808D272658DULL, 0x9E2AAF34ACEC8D53ULL, 
            0x3BBAC8B0F9487FD6ULL, 0x21B6191DD35CC808ULL, 0xDA33D0FFDC392394ULL, 0xC597530E372F65D2ULL, 
            0x2CD8430CBD322B70ULL, 0xBFA578C4F9D591A9ULL, 0x912136A6E8D8CA25ULL, 0xE878EE7CA6009463ULL
        },
        {
            0x8CF9D483131DB96AULL, 0x8C2404E6581C9C5CULL, 0xF2F7AB904DEC2FD6ULL, 0x70984DCA3280FAFFULL, 
            0xF8F0123FE899415BULL, 0x18A8753E2C85C696ULL, 0x9E91165008019AF4ULL, 0x3F9C25E48A130CB3ULL, 
            0x01F791983887F716ULL, 0x3997EE88213C479AULL, 0xF41E15C2BE93E6F5ULL, 0x88BC52B22F6FCA01ULL, 
            0xADE02F2C2145FF9AULL, 0x8C977A65D0F4AAB8ULL, 0x9693DD0925EBCB42ULL, 0x4B2E0BC7036DEEAAULL, 
            0x3C25A9FE69A1D252ULL, 0x771F708ADCB48445ULL, 0x96C0F84E65B0C8A3ULL, 0xCCD2C2C6D7996C3AULL, 
            0x5CB5B51C200CF5E7ULL, 0xF8B9DD18C8D7BB79ULL, 0x00F973D4BDF1C97EULL, 0x64066C21499E5C66ULL, 
            0x2037BC21E044D93CULL, 0xD278A58095A66491ULL, 0x2D86364A04D05CAEULL, 0x50EB5109231E3F57ULL, 
            0x6B5799F79A4EBADEULL, 0x9B37430362EAC07FULL, 0x36F03539308B1316ULL, 0x7D032239D3BEB895ULL
        }
    },
    {
        {
            0x15BEF3A317CDA76EULL, 0xFBB9D69F1949F860ULL, 0xA6F760F83294D466ULL, 0x56CED91DBEC92FC9ULL, 
            0x3C9F62FCA36D13D7ULL, 0x51151A13F9B6F893ULL, 0x3A091A08A8A04100ULL, 0x03EE7FBFC9A2C0A7ULL, 
            0x9B0A9D314C316A73ULL, 0x8E3D0FA1676C7AE6ULL, 0xA0565D190E58E90BULL, 0x24A2E0E47B19E880ULL, 
            0x05A69604AB02E7D0ULL, 0xA4A458A5B99E35CFULL, 0x841ABDB54700549CULL, 0x0FDE299FE9155122ULL, 
            0xB614DC6C58DDEB05ULL, 0x046B6CFB6BA9AE01ULL, 0x8CB5944F91C6CE6EULL, 0x087AF1352F92A1DCULL, 
            0xE32ABB5723EE0F3BULL, 0x42B1F6BF73A2B5B9ULL, 0x2AE0AE58C03A9577ULL, 0xFD60E0993A5476E3ULL, 
            0x7C6367998C538AAFULL, 0x727CEA4C6BC37165ULL, 0x24A82A59DF149FC9ULL, 0xEF020AED69F2C20BULL, 
            0x91EE699919FD85FAULL, 0xCD478D849C9FEEDAULL, 0x0374B637646D08EDULL, 0xD2EDDC9DDEAE30D5ULL
        },
        {
            0x680968AB95099E64ULL, 0xCBF7A5D0884EEA8CULL, 0xDB02A4388FA9ADAFULL, 0xF8D9E3D7BB59F25EULL, 
            0x5F142516C62EE266ULL, 0x288B4563F2D02DB8ULL, 0x0591DAA68E0FA15CULL, 0xCA7993F9196B2F46ULL, 
            0x8C57B627DDFC421BULL, 0xF2954229832A4B7CULL, 0xA246807CB8DC291DULL, 0x3F37B119F3193CFDULL, 
            0x3E7FE3A062852447ULL, 0xA77B7C9740602BC7ULL, 0x0DA8FB6E657FD3ADULL, 0x149091F3BAEDD670ULL, 
            0x1A81E804EE87184DULL, 0x2F9403E25266BDACULL, 0xFC477792569F9210ULL, 0x1057A67A71785FD5ULL, 
            0xE9BA1847DC5EA687ULL, 0x10A62E55F476CC89ULL, 0xB49B0C053466FE59ULL, 0x5F66B6257BD1CBE8ULL, 
            0x3F80833BD8030DEBULL, 0xF003C6D069A3D481ULL, 0xF44681BB9E5DDF69ULL, 0x0B410D723DB54ED4ULL, 
            0xFDB57DE952FD240AULL, 0xE8AE930133986287ULL, 0x8F18F4EC8551F6C7ULL, 0x61855B0468324CF3ULL
        },
        {
            0xCB5D473C408ACE13ULL, 0xF06D5D6026734085ULL, 0xE8838A83A033506BULL, 0x8FB1FB65942A94EEULL, 
            0x875741341B7A2807ULL, 0x5E793D0E58ADE51CULL, 0xB18F06577D92FAECULL, 0xE9C2B38697277CF3ULL, 
            0xE2239D1D933482FEULL, 0x0B7C16927323C8ADULL, 0xCEACFE2E95806AE8ULL, 0xB312CE8686B88C3FULL, 
            0x99C5236AA7EE2B57ULL, 0x11F120120996360BULL, 0xA5E1A4D374E5A47AULL, 0x51980A64DA2D386BULL, 
            0x44A99C785BBC26E9ULL, 0x597D04BAF8A9946EULL, 0x73FDB4ADBEC5B24EULL, 0x08E973C11999E910ULL, 
            0x3ECEA8CA53AFEDA6ULL, 0x9BFDFFD1421DDE07ULL, 0xA309D57F4284B470ULL, 0x0846854B7B8004A4ULL, 
            0xDD65522195E7E711ULL, 0x309EB22897FC63D5ULL, 0x6A179F681784F829ULL, 0x03A92B15EE642695ULL, 
            0x049F81DA70CC358EULL, 0xF2CC8400BBDF273DULL, 0x54AC62EED0267202ULL, 0x028BDEC17D983465ULL
        },
        {
            0x7F3E651936EFCD1BULL, 0xC9553AF5B7510218ULL, 0xC54251789AF2B6CFULL, 0x8E980A2D50A05393ULL, 
            0x040E276732E35268ULL, 0x72099A3FE7D0A8CAULL, 0x11161ECD660D9F9CULL, 0xF4219226C1B5F2F8ULL, 
            0x59F7A9A62D964034ULL, 0x0A6FFD6C8D76205FULL, 0x984754638C12C723ULL, 0x934B0C2F0073BCDFULL, 
            0xB4CCD787A9537C36ULL, 0xF5F02CB18BFFB809ULL, 0x7993C09BDD49DE68ULL, 0xCAE41F1055B533B0ULL, 
            0x140E516EC1B04FA9ULL, 0x2A142E7BE7F5E37CULL, 0x47A9FA07167BBEB1ULL, 0xEF3448894B5AE323ULL, 
            0x1632CE842735B4C9ULL, 0x97689CD48F742B98ULL, 0x82D290179AC5A3A4ULL, 0x792DF1B897550C1AULL, 
            0x5B6DCD9A2222A793ULL, 0x070375180006BFD9ULL, 0x1EAD78F51E221982ULL, 0x902989939289D713ULL, 
            0xA46E3D25E17397AFULL, 0x4A0EA3C4551000FCULL, 0xAD37D2E30052AE63ULL, 0x6A30CEE93BD0E2BCULL
        },
        {
            0x88E01B14DF6925A9ULL, 0x07AB5C7CC48468DAULL, 0xF7B413C371889EB1ULL, 0xC624A43618569089ULL, 
            0xBAFFF9C170D9A80DULL, 0x4B173FA3A042BAFAULL, 0x705F58364647BBEDULL, 0xC9C988E87F0D5D52ULL, 
            0x6361B9C4DAF156FFULL, 0xE5F0CB7D446BC6ABULL, 0xEAE234CE6BFEF49BULL, 0x24A93DCF92D86D97ULL, 
            0x25AD5668F7E8336DULL, 0x577EFB9E9459619AULL, 0xC75E39E503DD259AULL, 0x791FAB1ED7255BECULL, 
            0x2DFB3BA0E29073DDULL, 0x93D4CD19629F12BDULL, 0x21A05C1B9FC6D5D3ULL, 0xF6F47C360DD7F281ULL, 
            0x55CA160CEAE8D27FULL, 0x4B83BFDA6F0F825DULL, 0x2144C4D368CA6E89ULL, 0x5989F9A34878329EULL, 
            0xE26793D6ADA00913ULL, 0xAD114D054F2470CEULL, 0x8A6469869379AF1EULL, 0xD1ACD8BEFCE96458ULL, 
            0xEEE31CC48BF78D13ULL, 0x83A15D6F396EA2B7ULL, 0x51D6B98A58422EF9ULL, 0x0F39D8C7451CB209ULL
        },
        {
            0x665AED26DB1149BBULL, 0xDB7F22FB4EDC8CF4ULL, 0x08C3FFD556D413D8ULL, 0xC12BA84A5A02AEB0ULL, 
            0xB896E654071622ADULL, 0xDD7F51CA523CB04EULL, 0xD504FEEE59435CBCULL, 0x124988F42E905CCDULL, 
            0xE96722DD289B8F39ULL, 0x24E745C7C48EAB35ULL, 0x48AD6A6439B3D929ULL, 0xDB7507A093B117F1ULL, 
            0xB3D8562E11826392ULL, 0x7A7792CE9B103E6EULL, 0xEF0C5B7C6BC8AFECULL, 0xD719429EB141FB43ULL, 
            0x9297E5DD6FF69398ULL, 0x2A60729D1EB43880ULL, 0xE27FA17C4C2737B6ULL, 0xB3D438597ECBA2ACULL, 
            0x77EDE9D4A0172F82ULL, 0xC5F1CD7AAD5D6618ULL, 0x48A504805121DDBCULL, 0x02120681576B077CULL, 
            0xE66C8515E022263CULL, 0x83B4BC91D1C2DAC4ULL, 0x60DB5A8BB40877BCULL, 0x568E76122DBE1DD5ULL, 
            0xF56C62E70AA23EB1ULL, 0x2A26CC423332233AULL, 0xEC15D04E49C5BCE5ULL, 0xD243A8FAB61BB737ULL
        }
    },
    {
        {
            0x62AA20B3A0C6DE22ULL, 0x5535C054DC2840D0ULL, 0x163F42831038DC68ULL, 0x57779EC2F78D74E6ULL, 
            0xFC3E1B0AF5CB4607ULL, 0x147ACF3E50C6BD91ULL, 0x32D989192C402F0DULL, 0x81F40404291CF634ULL, 
            0x17D9BCFC84611409ULL, 0xD89B01CF1D053E5CULL, 0x2FB4959368FF39EDULL, 0x540FE22E9643CA0AULL, 
            0x49CD11CBD389B955ULL, 0xD1CD6FC02A1FF385ULL, 0x356D5696BEE9BD9DULL, 0x0EC4F61739A19E0AULL, 
            0x6976742AAF6F78BCULL, 0x2247BA1A719CE6F4ULL, 0x0C41CA7EDB94691EULL, 0x7B1925A83A03E124ULL, 
            0x40113CF34778DC89ULL, 0xA7C5B2C43C788F8DULL, 0x323BAEDCA495A46FULL, 0xA30CDF61EF6C6B59ULL, 
            0x2771DABAFDFC7BD3ULL, 0x121F3211A1C6C995ULL, 0x31FE5A8045CAB636ULL, 0xD2DAD8874557E8EAULL, 
            0x83DF8628445C1E61ULL, 0x4AF69D86CDFE5C02ULL, 0x0A10DBA352D8EE8AULL, 0x0C2D485E0B70B244ULL
        },
        {
            0xBA73F21721E6A5D3ULL, 0x729353F1C8CEFB7FULL, 0x72AC9598CDAD96D3ULL, 0xFB437818CB13ECF0ULL, 
            0xD03B6E2E69E161D5ULL, 0x42CFE8078C22AB05ULL, 0xD47C4FA9244AF2CDULL, 0x56C940858B97DABEULL, 
            0xCD772249AA1D8B72ULL, 0x53BEEE03DAA26BC0ULL, 0x8A49E8969317A8EDULL, 0x8F88F2C1275E6198ULL, 
            0x24180242362AE2D0ULL, 0x3BA43BC9D351C9D7ULL, 0x967F30D48FA5301FULL, 0x1D08CED1F73B825CULL, 
            0x23FC6849113067B1ULL, 0x93E88D80EBFDB615ULL, 0x8313EAADA3313C61ULL, 0x2E774CC8EF3B1C8BULL, 
            0x08F6FE3D214AC92EULL, 0x98B108C8B0DA3FABULL, 0xBE16536C09A821B8ULL, 0xD035C485C0E12A96ULL, 
            0xDBE3CBB674FB71C5ULL, 0x65986700D38D4F21ULL, 0x2824F78AF4308979ULL, 0x7B9005D6CF1F20FAULL, 
            0x9ACDD56BBF3388AAULL, 0x074B0FDD31E82246ULL, 0x1E004114EFE9877DULL, 0x328D66D8F94C2058ULL
        },
        {
            0xB3C95894110E4FD4ULL, 0x0D9D9335AC52DFBDULL, 0x600DC0AAFBC26337ULL, 0xDB06F577C6011D67ULL, 
            0xA016AD57F40B73C8ULL, 0xBE1896C3502DD471ULL, 0xFF448D2D2F29CBFEULL, 0x31D0EC6EB7F612B4ULL, 
            0xE9A927A61CE71485ULL, 0x773D1604F0B2F062ULL, 0x83ABB84E97830EAEULL, 0x83B2CD04984330DDULL, 
            0xBB63B4761329D7DAULL, 0x9FFF013DF2307532ULL, 0xF96FE3A059808185ULL, 0x68DAED91917A8812ULL, 
            0x6C6DE8505B68D78FULL, 0x9D871C26424C9670ULL, 0x336CAB822995EA14ULL, 0x99688CD3ECB5288FULL, 
            0x5D56833A97E989ACULL, 0x04901764B23FDE90ULL, 0xA21E58E05E6848A9ULL, 0x3538089A68E92CE7ULL, 
            0x23BBFAD6E5207C7AULL, 0xA27CD81096FAA2ADULL, 0x74F3D1D89556A3AAULL, 0x18F95FB39DAC1009ULL, 
            0x8764795E9B9623E0ULL, 0xEBDD4F5290C83A57ULL, 0xF0ABA66313D2F9FCULL, 0xB190180A0977DB04ULL
        },
        {
            0x0AC3A26B5E981A2AULL, 0xFEF58922B9996E46ULL, 0xC340BB6CF2C12D34ULL, 0xE7F2AA5E74B34C89ULL, 
            0x6B457536B39EB2C1ULL, 0xD672F57EFF622F58ULL, 0x1985C99FA7E202F1ULL, 0xE62CD206C21A8258ULL, 
            0xBE09A99635DE9D42ULL, 0x39CB44FB7F2D1B0BULL, 0x0E1C506F2A300138ULL, 0x119B5A148F61C641ULL, 
            0xE616C5A0439D6566ULL, 0x4C6D8201C03FFC80ULL, 0xBA3AC60E684E7DF3ULL, 0xDA07F8C44E273EB6ULL, 
            0xF71C910E455FD3D7ULL, 0x62C11EDFC6975DF8ULL, 0xA461030E37750321ULL, 0x2696E1B6F5626353ULL, 
            0x856465C36ED71941ULL, 0xB35E99BFB223B8E2ULL, 0xFD96D984A42D88D8ULL, 0xE8AD45CDD0508D1AULL, 
            0x3695A989768749F4ULL, 0xD126B46AF88F541BULL, 0x5249F0F42F9F4555ULL, 0x490F467150541FE5ULL, 
            0xA6568049C9F06BA2ULL, 0xE1ED6408C4AFB5ACULL, 0x1BC51D8EB3E66111ULL, 0x861943CB44C2BA99ULL
        },
        {
            0xF6E472F86F5D647AULL, 0x1143B3F391681012ULL, 0xFCFAFE0C02EB24D5ULL, 0x63FDD87CA8F6F1ECULL, 
            0x6C95216C69D6510AULL, 0xB7814B99F6F43834ULL, 0x8C0F91A8D22AA44AULL, 0xFF76AF36A346B7D6ULL, 
            0xA7BD9F195002B591ULL, 0x67E3AAEF4911656DULL, 0x50A4BA91F544A7CEULL, 0xD45F7223C76AF581ULL, 
            0xAE00546F0B6EC8A9ULL, 0x776C772AC0A20915ULL, 0xC3B6FFE077402786ULL, 0x78E89ED2902A3645ULL, 
            0x295B990F573B2A83ULL, 0x16B24AC1C94286F1ULL, 0x9ECA16062431DF14ULL, 0x7B2405B74BDC01B5ULL, 
            0x28F28321AA5A3218ULL, 0x81D1230B81F3C489ULL, 0x69BFBEE4A257110FULL, 0xD3660C1DC4EF77F9ULL, 
            0x754CBCAE24F3028BULL, 0xE1D784EF96D71498ULL, 0x7529B67CD76D8FCDULL, 0x1D0FF3681D111F0AULL, 
            0xB7FB5BC7E6E89E3EULL, 0x1B771CF88E2ED934ULL, 0xF364A2599C06F145ULL, 0xCEA2E6115F5628D9ULL
        },
        {
            0xCCEB4DD8AF8639A0ULL, 0x92432443B6742579ULL, 0x1A4906BEFB1A5A81ULL, 0x378D771C8BCDE770ULL, 
            0x2750A8E1A1153A50ULL, 0xFBDD1C33674C676EULL, 0x267DE98498ED7DB0ULL, 0x5FAC385DEEB4C4DFULL, 
            0x0915E35B23F25819ULL, 0xEC31290AA3039CC8ULL, 0x72EA3081885C4121ULL, 0xB7BD19AB0FE28E9DULL, 
            0x5DFA9E6E79845113ULL, 0x8F1EFD84B5C16207ULL, 0x99B0D6DCC7390834ULL, 0x3983C3CBD43DD888ULL, 
            0xAFFF174C183898C9ULL, 0xD4F64133AC64EE5CULL, 0x49EBFF34079535CBULL, 0x9723A61A7046AA27ULL, 
            0x09284F1F3DC91AA9ULL, 0x87B060582683692AULL, 0xB0BE4B54636485B5ULL, 0xF3935E8E8C6FBA17ULL, 
            0x4985C9A02B8C31BFULL, 0xE9B39C1809B3902FULL, 0xB00424DD38B753CAULL, 0xF75F847678775F1CULL, 
            0x29CEDF7AC928E344ULL, 0x4E4459C62E46A5AAULL, 0x032B2078EC0B5A22ULL, 0x71D87A37E06E8391ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alkaid::kTwistConstants = {
    0x133568C3B43CF7F7ULL,
    0xD4B0F492AF6A36C6ULL,
    0x708D4730C5A21E48ULL,
    0x133568C3B43CF7F7ULL,
    0xD4B0F492AF6A36C6ULL,
    0x708D4730C5A21E48ULL,
    0xBACEE30FBD9DEBDAULL,
    0xB3E24111CE7D3802ULL,
    0x6D,
    0xEA,
    0x34,
    0x9B,
    0xAE,
    0x70,
    0x14,
    0x11
};

