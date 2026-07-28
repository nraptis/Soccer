#include "TwistExpander_Achernar.hpp"
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

TwistExpander_Achernar::TwistExpander_Achernar()
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

void TwistExpander_Achernar::KDF_A(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Achernar_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Achernar_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Achernar_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Achernar_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Achernar::KDF_B(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Achernar_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Achernar_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Achernar_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Achernar_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Achernar::KDF_C(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Achernar_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Achernar_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Achernar_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Achernar_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Achernar::KDF_D(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Achernar_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Achernar_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Achernar_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Achernar_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Achernar::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x9F5A6E8FC9E608B0ULL;
    std::uint64_t aIngress = 0xAB7ED957C8FA3F77ULL;
    std::uint64_t aCarry = 0x8B6B76ECC30D4E44ULL;

    std::uint64_t aWandererA = 0xF8BE8F79BE4F4FBCULL;
    std::uint64_t aWandererB = 0xC0772C5BBE4FE77CULL;
    std::uint64_t aWandererC = 0xB0E5CD129035B20FULL;
    std::uint64_t aWandererD = 0xC8B5E5CD125320E6ULL;
    std::uint64_t aWandererE = 0xE8F4621018FDA089ULL;
    std::uint64_t aWandererF = 0xD3E17E7FB944CF0CULL;
    std::uint64_t aWandererG = 0xA7FE7F2987F158D9ULL;
    std::uint64_t aWandererH = 0xBB90D8EDA6984CE6ULL;
    std::uint64_t aWandererI = 0x9B194832973B59E3ULL;
    std::uint64_t aWandererJ = 0x8FB3C7C32E4BB6D2ULL;
    std::uint64_t aWandererK = 0xB8840B0F346977C9ULL;

    //
    // KeyRotate A
    //
    aPrevious = 0x9ED7091BE4A27CA0ULL;
    aIngress = 0xC9FC42CF9BBA1ED9ULL;
    aCarry = 0xA40EACDD0CB6EF2EULL;
    aWandererA = 0x972CAAFAE3646F75ULL;
    aWandererB = 0xB373287ABF953B14ULL;
    aWandererC = 0xF34204645AEB11C0ULL;
    aWandererD = 0xE4922BC41FBE83D4ULL;
    aWandererE = 0xB71980A7C8AF7E8FULL;
    aWandererF = 0x95709FE9E9531C5CULL;
    aWandererG = 0xAEA4D14C5F30D6BFULL;
    aWandererH = 0x9A7CCA49398E717EULL;
    aWandererI = 0xFCE5C2AF6F384BB6ULL;
    aWandererJ = 0xF9EB062B6CD3B7AFULL;
    aWandererK = 0xAE5AB51E939D01CCULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateAConstants), &(pWorkSpace->mDomainBundle.mKeyRotateASalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xF6BE45E60634BFAFULL;
    aIngress = 0xA4FE5BC48FAC687EULL;
    aCarry = 0xEE736EA14C0BE6A1ULL;
    aWandererA = 0xB6126A1EC276FE67ULL;
    aWandererB = 0xFD82E74021335A1EULL;
    aWandererC = 0xAF52C6425732CB78ULL;
    aWandererD = 0xC889976A8ADD5011ULL;
    aWandererE = 0x8442C31131D52E0FULL;
    aWandererF = 0x8ED4120EA88E19DEULL;
    aWandererG = 0xCC5D0A15F888AF5AULL;
    aWandererH = 0xC6917D11A5EF8EB6ULL;
    aWandererI = 0xA3C6192BBAB9CB39ULL;
    aWandererJ = 0xE781F3B5AD5DFBE9ULL;
    aWandererK = 0xEF620B154045E7EBULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), pSnowLaneC, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants), &(pWorkSpace->mDomainBundle.mKeyRotateBSalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xB06B00BF1139B8DAULL;
    aIngress = 0xD3FFF6DC97F164C3ULL;
    aCarry = 0xADB26FD823D65EA8ULL;
    aWandererA = 0x8DCCCE06FD043851ULL;
    aWandererB = 0xA78F958283FBEEBDULL;
    aWandererC = 0xBD4C21AC869FEF38ULL;
    aWandererD = 0x8EBEB56F6A194DE8ULL;
    aWandererE = 0xC978365BA4934BD6ULL;
    aWandererF = 0xE3897DF0FCFEF358ULL;
    aWandererG = 0xFD6AF4157C38CFCDULL;
    aWandererH = 0xC38397B3735E9FF6ULL;
    aWandererI = 0x8CE0402383A47BD6ULL;
    aWandererJ = 0xCA084F9FD80E7EF7ULL;
    aWandererK = 0xBF42FA9115490995ULL;
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
    aPrevious = 0xC5CB3E5D049718D6ULL;
    aIngress = 0x92C94FEEC8072071ULL;
    aCarry = 0xCE407E111FE13101ULL;
    aWandererA = 0xFA423E3D86E91E2DULL;
    aWandererB = 0xA09626316ABD31DBULL;
    aWandererC = 0xBD264AF8CAE17B16ULL;
    aWandererD = 0xA1C852B841EE0A87ULL;
    aWandererE = 0xB607AA3E2D123C1DULL;
    aWandererF = 0x9850D0342425F110ULL;
    aWandererG = 0xD40DBBD760C6DE95ULL;
    aWandererH = 0xDC78887029C55A1AULL;
    aWandererI = 0xF7395A6AB898EF04ULL;
    aWandererJ = 0xA3C47D517BF46977ULL;
    aWandererK = 0xE507634B6EA68EDDULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnBConstants), &(mDomainBundleInbuilt.mKeySpawnBSalts), pSnowLaneD, pSnowLaneB, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeySpawnBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnBConstants), &(mDomainBundleEphemeral.mKeySpawnBSalts), pSnowLaneD, pSnowLaneA, ARX_STATE_VARS);
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
    aPrevious = 0xB20FCA011CCD5C48ULL;
    aIngress = 0xC73D7231340E3F6EULL;
    aCarry = 0xA37905E6F24765E7ULL;
    aWandererA = 0xB2F10F9F414BEBAEULL;
    aWandererB = 0xD4C5A119546F8CA3ULL;
    aWandererC = 0xDDDE3340B03D2F2EULL;
    aWandererD = 0xE0A2E70BA92BA3FEULL;
    aWandererE = 0xF27D89178D1A17F2ULL;
    aWandererF = 0xE205E16D12C34C30ULL;
    aWandererG = 0xD43DAE34BFDF85B8ULL;
    aWandererH = 0x802C507459B8B401ULL;
    aWandererI = 0x9829B4E5A8A5DB7AULL;
    aWandererJ = 0x8638A1A43AADCE88ULL;
    aWandererK = 0xA30A1FEC936438F7ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneA, pSnowLaneD, ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mTwistSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneC, pSnowLaneD, ARX_STATE_VARS);
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
    aPrevious = 0xA49BDB4290E87FD9ULL;
    aIngress = 0xA0EB88794784C167ULL;
    aCarry = 0x89AF9FE2915779C9ULL;
    aWandererA = 0xED59E78BDC50E37BULL;
    aWandererB = 0x9E2CECCC032704BCULL;
    aWandererC = 0xC103B4B0940C96CEULL;
    aWandererD = 0xA59A817973E828BAULL;
    aWandererE = 0xCE0FC9B19B59DD5DULL;
    aWandererF = 0xFE320B3526308462ULL;
    aWandererG = 0xF26FE7F0245B4E7EULL;
    aWandererH = 0xBB26F13B8BEF4905ULL;
    aWandererI = 0xE00AC676F20C401AULL;
    aWandererJ = 0xF1150CFD7D1CE485ULL;
    aWandererK = 0xAC24D1A5D034CEAFULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneB, pSnowLaneD, ARX_STATE_VARS);
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
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mSeedConstants), &(pWorkSpace->mDomainBundle.mSeedSalts), pSnowLaneA, pSnowLaneC, ARX_STATE_VARS);
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
    aPrevious = 0xC151997820C60B56ULL;
    aIngress = 0xB8F5076AC986C485ULL;
    aCarry = 0x94EF1A2B51854336ULL;
    aWandererA = 0xC4EBD00EAE59FB14ULL;
    aWandererB = 0xD5AE493E646CB7F1ULL;
    aWandererC = 0xA41442977325ECE0ULL;
    aWandererD = 0x99E943DBBD551C4FULL;
    aWandererE = 0xEE902795B2833AB4ULL;
    aWandererF = 0x91A4CCCD6B95B093ULL;
    aWandererG = 0xFC9A3E9D8C918234ULL;
    aWandererH = 0xF30835DD5D7BED71ULL;
    aWandererI = 0x8366747616535467ULL;
    aWandererJ = 0xD9FCDCA20D63FB19ULL;
    aWandererK = 0xD7ADDE7060C1A9A0ULL;
    //
    TwistExpander_Achernar_Arx::SEED_A(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Achernar_Arx::SEED_B(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Achernar_Arx::SEED_C(pWorkSpace,
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
    TwistExpander_Achernar_Arx::SEED_D(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Achernar_Arx::SEED_E(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Achernar_Arx::SEED_F(pWorkSpace,
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
    TwistExpander_Achernar_Arx::SEED_G(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Achernar_Arx::SEED_H(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Achernar_Arx::SEED_I(pWorkSpace,
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
    TwistExpander_Achernar_Arx::SEED_J(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Achernar_Arx::SEED_K(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Achernar_Arx::SEED_L(pWorkSpace,
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
    TwistExpander_Achernar_Arx::SEED_M(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Achernar_Arx::SEED_N(pWorkSpace,
                 pNonce,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 ARX_STATE_VARS);

    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Achernar_Arx::KEY_A_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Achernar_Arx::KEY_A_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Achernar_Arx::KEY_A_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Achernar_Arx::KEY_A_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Achernar_Arx::KEY_A_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Achernar_Arx::KEY_A_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Achernar_Arx::KEY_A_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Achernar_Arx::KEY_A_H(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Achernar_Arx::KEY_B_A(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Achernar_Arx::KEY_B_B(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Achernar_Arx::KEY_B_C(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Achernar_Arx::KEY_B_D(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Achernar_Arx::KEY_B_E(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Achernar_Arx::KEY_B_F(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Achernar_Arx::KEY_B_G(pWorkSpace,
                 pNonce,
                 ARX_STATE_VARS);

    TwistExpander_Achernar_Arx::KEY_B_H(pWorkSpace,
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

void TwistExpander_Achernar::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF8ACAEC547BD7923ULL; std::uint64_t aIngress = 0xA56A8AE7D1D71450ULL; std::uint64_t aCarry = 0xCDFEFF70F1A8F639ULL;

    std::uint64_t aWandererA = 0xE7086596070D4C7DULL; std::uint64_t aWandererB = 0xCE21049D2BC3EA1FULL; std::uint64_t aWandererC = 0xEA1B9C1E4B70E3C3ULL; std::uint64_t aWandererD = 0xFB5505EAECD0976FULL;
    std::uint64_t aWandererE = 0x8FB9757DE2D690ABULL; std::uint64_t aWandererF = 0xCE5C76B1AD1F650CULL; std::uint64_t aWandererG = 0xFE66895D486B7C67ULL; std::uint64_t aWandererH = 0xD0FA64A1370DB539ULL;
    std::uint64_t aWandererI = 0x81ED700924508A35ULL; std::uint64_t aWandererJ = 0xCB3264009467407CULL; std::uint64_t aWandererK = 0xA1CD31AA47F3D09CULL;

    // [twist]
        aPrevious = 0xBB9A5E835FCE571FULL;
        aCarry = 0xEB10AEF9F8C4E30EULL;
        aWandererA = 0xB5FDA60FD3124E2AULL;
        aWandererB = 0xA06A3B72CA9982D7ULL;
        aWandererC = 0xE9322D6FB18D5555ULL;
        aWandererD = 0x8D217FA85FA42E6EULL;
        aWandererE = 0xC6439BBE15070671ULL;
        aWandererF = 0xB6CF3916292FEAE7ULL;
        aWandererG = 0xCB0BB304F289CB99ULL;
        aWandererH = 0xA41D294A94DA4697ULL;
        aWandererI = 0xC259CAD953681D45ULL;
        aWandererJ = 0xF713EDB008CB7A35ULL;
        aWandererK = 0xE0010D8304861EE9ULL;
    TwistExpander_Achernar_Arx::TWIST_A(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Achernar_Arx::TWIST_B(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Achernar_Arx::TWIST_C(pWorkSpace,
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
    TwistExpander_Achernar_Arx::TWIST_D(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Achernar_Arx::TWIST_E(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Achernar_Arx::TWIST_F(pWorkSpace,
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
    TwistExpander_Achernar_Arx::TWIST_G(pWorkSpace,
                 pSource,
                 pCrossLaneA,
                 pCrossLaneB,
                 pCrossLaneC,
                 pCrossLaneD,
                 ARX_STATE_VARS);

    TwistExpander_Achernar_Arx::TWIST_H(pWorkSpace,
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

void TwistExpander_Achernar::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Achernar_Arx::GROW_A_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Achernar_Arx::GROW_A_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Achernar_Arx::GROW_A_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Achernar_Arx::GROW_A_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Achernar::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Achernar_Arx::GROW_B_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Achernar_Arx::GROW_B_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Achernar_Arx::GROW_B_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    TwistExpander_Achernar_Arx::GROW_B_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Achernar::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 1 of 33
    // Exploration cases: 0
    // Structural distance: baseline candidate
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
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4008U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3558U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4098U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3918U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1915U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1780U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
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
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1330U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1735U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1690U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1645U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 47U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 137U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 1 of 33
    // Exploration cases: 0
    // Structural distance: baseline candidate
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
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3018U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7429U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7069U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2838U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1060U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 655U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1240U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 430U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1150U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1105U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 610U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 475U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Achernar::kKeyRotateASalts = {
    {
        {
            0x9470135F2EA5E7C9ULL, 0x0C9713B7BBCFF0D3ULL, 0x1154BCFB133BDFD6ULL, 0xE5F030405635C763ULL, 
            0x984264B499BCC7B8ULL, 0x5F9EDCD087DF51ABULL, 0xCE49D0B36AED00B0ULL, 0x4D673E3437319E00ULL, 
            0xBEC5E07FC22FDFBFULL, 0xA8D49D16D0F94431ULL, 0xFEDABBF77694BE33ULL, 0x6D18B4937F415F8BULL, 
            0x21557DC5D0BC062AULL, 0x474F60F093A1C7ECULL, 0x25E25D7031AA6472ULL, 0x5A578E0B5D9B7EFAULL, 
            0x81FA62DB2D66E6BAULL, 0x1F1FF5C9DF7382F1ULL, 0xE77461741F5A003DULL, 0x05E5EA5A48546E34ULL, 
            0xC640961EB02C0D39ULL, 0x850BB9B57FDDCB37ULL, 0x4F169177A013F0A0ULL, 0xA5105E97A3252BD2ULL, 
            0xFC41E59821B4BE62ULL, 0x918759952E05251AULL, 0xB9423FFA0B1069E3ULL, 0x42B236A999781238ULL, 
            0x2B7C3A2D7B919C41ULL, 0xE64CACB3349CE5A9ULL, 0xB09F953BE6A9734CULL, 0x476D2748B43D5F52ULL
        },
        {
            0x04B1F7EB92D83FB1ULL, 0xE7FDB4B930F1A79BULL, 0x4133DE78E2807D35ULL, 0x7354E1E64E1C2B8AULL, 
            0xF327266374D5DC4FULL, 0xCB9D9CC5B992A871ULL, 0xD65A16885C363FBAULL, 0x58238DAD3E53B509ULL, 
            0x990987570CD08301ULL, 0x751CC7402F68798BULL, 0xBB66202A17EFC5FAULL, 0x28DEDD958DC2C8E8ULL, 
            0x361C6F541E7A8050ULL, 0xD9237F58159B8990ULL, 0xE60BB7F39EBC7A4AULL, 0x4FC56693708A7435ULL, 
            0x76074820B42AA4DDULL, 0x09C906D69C5DC0E4ULL, 0x9870597DD7E08F9FULL, 0x9A46D373CEB90DEDULL, 
            0x96E385EA12755149ULL, 0x3956B02A90D4BB5CULL, 0x758AE7D183772406ULL, 0x8372ECDBC12B23BDULL, 
            0x7080A9D885D47D7BULL, 0xA1B4380ABCC25D8BULL, 0xCC659AC62D98BCA6ULL, 0x4B3AFC9A035FB17DULL, 
            0x177F5706C18CC35DULL, 0x04495398FA69C58EULL, 0xCD26DBC74A33DD27ULL, 0xE6E6316D8FD427BCULL
        },
        {
            0x227B701B5E6C2726ULL, 0x4E2138270644302CULL, 0xE1C2009C00B40F0BULL, 0x34847B2CD208E081ULL, 
            0xA777DF036A282497ULL, 0x577CB1600E7B94ECULL, 0x5827786C04D66A7DULL, 0x549C67D87E70C96BULL, 
            0x846ACA3BFEE7A5AEULL, 0x3987F251E9D08D8AULL, 0x64EC899FE90462D7ULL, 0xAD8398AC3A19FE4BULL, 
            0xB6880B5FDC3486CFULL, 0x4AF8933DBE63FDD5ULL, 0xCAC292970DF0BFF6ULL, 0x12E86692A53BA454ULL, 
            0xF2446E3A3BAE17F0ULL, 0x91B6B4EDD996A4FCULL, 0xA811FC248314AB2AULL, 0xFECF457165BF8B85ULL, 
            0x6092F919E38E33E0ULL, 0x13C62BC89944438CULL, 0x84189989971F772AULL, 0xD10C23D674063F07ULL, 
            0xFD6D68B813538A08ULL, 0xE78FEF309F7C9F63ULL, 0x12B6AC4366E84C9FULL, 0x5BC7EBEA54A0287AULL, 
            0x46A0FCB666B1CC03ULL, 0x9C9B9D6FDD70B877ULL, 0x4CF8B5BA50BE5F9AULL, 0x462FD20E1DF58243ULL
        },
        {
            0x383AE77BDA0EB5AEULL, 0xB5AA30D5EA4B7D88ULL, 0xE563C70B079E72C4ULL, 0x1BAC4E5CA15A87ECULL, 
            0xF552B2D631A84CA9ULL, 0x498049F2F1773F08ULL, 0x67F8F335C17DAA0BULL, 0x3E3A259772E89879ULL, 
            0xBCA096CDEB0F3358ULL, 0xF93AC8E6B0DD823EULL, 0xCB697E4B178F6C8AULL, 0xE41A66D37679DFE1ULL, 
            0x4E2CEDDF27A72A6DULL, 0x3C8D28227059C2F0ULL, 0x4134F604E0321941ULL, 0x9E522496C6765019ULL, 
            0x80D11598BE066B2FULL, 0x2BBB7995BC7CC0ECULL, 0x32F7395C19FE20BCULL, 0x1B4BF8386BF583DAULL, 
            0xC39734F9CE85BCC7ULL, 0xFA25EBDBE203A3BEULL, 0x424DD5F571E5AE96ULL, 0x371A25AF79928DBEULL, 
            0xAF05F4F80BF8E6A2ULL, 0xFC4CD72236E6D2F7ULL, 0x1B25367BF77BB145ULL, 0xF23B535866713DAAULL, 
            0xEE1D41A38B0A7BABULL, 0x25915574D23987DEULL, 0x7AFAF8E0DEE7834FULL, 0x1496E510F4C1510FULL
        },
        {
            0xD70AA66FE8E50513ULL, 0x87E574390EB252F4ULL, 0x20B8FB31568E9178ULL, 0x6ED9ACBD5542F659ULL, 
            0x49E439FE6E47755AULL, 0x2C99B2C70E52806CULL, 0x8A6E10B09EFFF761ULL, 0x3B2CFBAAD4CB2AF6ULL, 
            0x7B15DBDD69E7E2E8ULL, 0x3573073A291C13E8ULL, 0x664FAFA0F840EE15ULL, 0x0353A8357DC43DCEULL, 
            0x7529AE4856D41C80ULL, 0x88462D39DADDF833ULL, 0xF81EDBD5E7ACF051ULL, 0xFB446BEE9A3E7366ULL, 
            0xD94AC5FDB63C4D69ULL, 0x45A3C2EB9A475B1AULL, 0xA83DA8F8423063A1ULL, 0x52FCE17E3FBF41C8ULL, 
            0x099431050DE165CFULL, 0x134FB6EDF50346A6ULL, 0x92B6306A27D8FFF0ULL, 0x87583995FAC3670BULL, 
            0xFD8966C9135BABF1ULL, 0xF6261FD2910B61AAULL, 0x1233E66C7F95EF2CULL, 0x62C1A73F0F5E6CB3ULL, 
            0xEAC32E379043032FULL, 0x19472FC4610444E4ULL, 0x858010F6A6874134ULL, 0xC560AEC40F4A8BABULL
        },
        {
            0x533349CCE9A1A908ULL, 0x6B20CF467B595643ULL, 0x616D866640A8848EULL, 0x3643B9F26D190D1EULL, 
            0x16701A1DF9C1E7D0ULL, 0x72EE604014588060ULL, 0x7E7AD3F739748128ULL, 0x1206632F19DEE61DULL, 
            0x1A3E7DB4AAE3B188ULL, 0x03D59EFFCCCB228AULL, 0x8D021E0A58F6D45DULL, 0xEDC44F78DCEADEF6ULL, 
            0x5A6A291F6F35905EULL, 0xF47D62D6EEC65DEDULL, 0x9274B2A203B37546ULL, 0x0C0CB9DFD85427C9ULL, 
            0x576B1EB234D76746ULL, 0xFDE22F0DC294ADAFULL, 0xB17EBADD5DD4AA6CULL, 0xA4869AE82B466824ULL, 
            0x31A4231B88B272D1ULL, 0xE948FA9C1456ABE9ULL, 0xBA0DD0885E332F7EULL, 0xC34FC38724E590DBULL, 
            0x1C2B0B7BA5F533BFULL, 0x96088C32253C0BB9ULL, 0x78C884B972EBD212ULL, 0xE26C5615AA117E9FULL, 
            0x0604144448E9894BULL, 0x993C26E3665A0FE8ULL, 0x732F80B9BC7F7101ULL, 0x4FE72F4DAB62541BULL
        }
    },
    {
        {
            0x741C906A0EE3F44FULL, 0x9A8F1FACD829154CULL, 0x4516CB66B417A72DULL, 0xDFF15A14A897BA28ULL, 
            0x7EA84B3E99B17CE8ULL, 0x19ED09AF61461463ULL, 0x0FE72EE246EFEF7FULL, 0x729E1B0513F3A5BAULL, 
            0x0C58A073423F6212ULL, 0x8587F14E902AE408ULL, 0x96C327229EC86044ULL, 0xEEB89E8039AA4342ULL, 
            0x46CFA75693996E37ULL, 0xB0D2286350050FE1ULL, 0xED2CEE90EE9CD7D9ULL, 0x7F089E5471896021ULL, 
            0x162EE03DDC82BCE6ULL, 0xFD2D1075E1D0B656ULL, 0xB0786DE237A35128ULL, 0x47F6588BBC46DB26ULL, 
            0xC38B714A7EE0A865ULL, 0xF4BE8F641F74A1E2ULL, 0x7CD4440087DE1180ULL, 0x4FB59DDB52512973ULL, 
            0xD7F3A87F9E3656EFULL, 0x424479BBE19CA309ULL, 0xD99F351B13897F03ULL, 0xFF6FB31E191D76CCULL, 
            0xDB90551B5E64F7E8ULL, 0x106C5FB6A1352981ULL, 0xACA215E8A542D8FDULL, 0x6FD8CC7BCEE89CB0ULL
        },
        {
            0x82C67E60ACAD8566ULL, 0xAEFD488740C1964AULL, 0xE10591081753CD66ULL, 0xD406ADE72E04C69CULL, 
            0xF4632AAE2DC538E5ULL, 0xA70E564765748F9AULL, 0x813D6CB9DDE50667ULL, 0xF34B3ECBED34D030ULL, 
            0x696903FC5172D372ULL, 0xAA74FD25453EAB96ULL, 0xDC0FB86A34EBBD1BULL, 0x2B1D8BEF0AC34CB5ULL, 
            0x423468A7A34B7DF3ULL, 0xF7FF716029C84E4AULL, 0x16C1758540E9B617ULL, 0xF4A5BA847C9C0D9BULL, 
            0x3B1B0C96ECEC88A0ULL, 0xA57D6A5D230038CEULL, 0x4F27B1DEA535DD6CULL, 0x71C67A5E3441CC8DULL, 
            0xE32F48DAEC91BB01ULL, 0xE569903634DC7D1AULL, 0x389BDE8DB1335305ULL, 0xBFCDCD15A3C7C8A2ULL, 
            0x02E6ABBE7BC8694BULL, 0x69CABE1236860C25ULL, 0x88ED9323CBC2E644ULL, 0x6DD4CBC8F52BC265ULL, 
            0xB5495454FB32E9ADULL, 0x2E05868BD73EF7ABULL, 0x3EBF84BC088D0708ULL, 0xBEB6BA55B7790D0FULL
        },
        {
            0x790C768EEF249470ULL, 0x8BC428F6A2690E8DULL, 0xD9493DF03F97DF22ULL, 0xBFBFD9302ECD060CULL, 
            0xA30EFAA401CDCD39ULL, 0x2BA5C9B094C52342ULL, 0x3E867BBD1E8F0EB0ULL, 0xC7FC5E7F916F01F3ULL, 
            0xACFC1063766D40CBULL, 0x0B2974206B8903A9ULL, 0x983BE6C2A9C8A244ULL, 0xCA5D725C31456A87ULL, 
            0x8A2D79D296BB6091ULL, 0x12A0A2B513C8D708ULL, 0x8DCC05CA5B22FD01ULL, 0x1B3CAC2F7750218CULL, 
            0x83E7FD89108F476DULL, 0x8EF4E2A6CC99CE6EULL, 0x7CD22D6EA2708E32ULL, 0xF82F706BD9FABBD0ULL, 
            0x8B44AB51C132C591ULL, 0x28A9D42D1F6DA11FULL, 0x83E137642F0B5667ULL, 0x17B70ABB6D5CFF61ULL, 
            0x9C9B7F65DD1F08A1ULL, 0xB9898FBE6DAABA4CULL, 0x1BD184A9849462A9ULL, 0x828372F24AA91384ULL, 
            0xD0E073ED7AC630ECULL, 0x9D9415C08EB7EE62ULL, 0xD32574AEFC6832ECULL, 0xA3518BC7DC80E712ULL
        },
        {
            0x9CC7CB615B0559A8ULL, 0x3FAF95504CF14ABDULL, 0xEE8D0E22908C66E5ULL, 0x73DBF2D933C033EFULL, 
            0x05DFDE26238F4E70ULL, 0xB439DEF2177B2C42ULL, 0xEAF2D188F94E3CD2ULL, 0x32BE1C2DE443F22AULL, 
            0xB5F95603B5D5F558ULL, 0x5EBF54869E01F78DULL, 0x44115BA0E700D1BAULL, 0xAAA604C0E0644035ULL, 
            0x6A69479E2533F087ULL, 0x9A1F81B5893B9D99ULL, 0xEB95B94B9B98C426ULL, 0x0DA42FD27F120820ULL, 
            0xE7D3FC5128D683B9ULL, 0x8F4CD25F89DE2543ULL, 0x7CC343EB5FE41453ULL, 0xEB0CFE75263BD855ULL, 
            0x34E32FAC378F8914ULL, 0x5F64BFE97B03D48BULL, 0x02B1BBDB36E7E63CULL, 0x09A006CEC72E81C2ULL, 
            0xEFD2975BCBEA6D2DULL, 0x9AC7530B3B014072ULL, 0x1CA6EFC3EFCC3CC9ULL, 0x7F961F3A46239D27ULL, 
            0xE7A006C6FAB96D46ULL, 0x45B28FD8FB1E6C05ULL, 0x7C54354FA9A50D4BULL, 0x28EFFB5B7C9DFDCDULL
        },
        {
            0x34F06DDEA061E9CCULL, 0x2DCEFB42AC46592CULL, 0x0098C0C94EEF80DCULL, 0x4AF8C6F4D6341FDAULL, 
            0x5ABC475B9CCA550EULL, 0x4B257AE70B3A728AULL, 0x2294EE085606955BULL, 0xDA5B4F1736F2993FULL, 
            0xC6028F6F9851B83DULL, 0x3448CCA93D3B4D85ULL, 0x001CDA6CF5560E71ULL, 0x8643783B22C01428ULL, 
            0x65DF938EE6FCEA77ULL, 0xD6C2A7CB68A0D340ULL, 0x6C469804EEEA27DEULL, 0x8A90A4CDF4565D4FULL, 
            0xFB13E6721662A533ULL, 0xAC6DEB11746C2972ULL, 0x6D0EEB4B2CB3994EULL, 0xADC287813E49C557ULL, 
            0xC78DDA1FFAF62352ULL, 0x0E780A5DBB9C6245ULL, 0x0300CCB32579DA5CULL, 0x219017C3782D7775ULL, 
            0x1EFA0A2A7E8390B1ULL, 0xE0D154CD1A861B1EULL, 0xEE47CA71E1EB34B8ULL, 0xBB7D5FD33CBA5240ULL, 
            0x0CA6597ABBC315BFULL, 0xCBFE52C16BD8D1F5ULL, 0x0A51F1EAE81A7BCDULL, 0x3B77B333235DEAE2ULL
        },
        {
            0x85729397EFF7BCA4ULL, 0x36AD11EFC85A31E2ULL, 0x842D42C344D79BC8ULL, 0x8637CC1DF519380FULL, 
            0x0EAB96EF74A21DC0ULL, 0x412C25DD9330E52DULL, 0x7B3C6784B6253453ULL, 0x1D04C750C542229BULL, 
            0x22D444F513FA418AULL, 0xD5EB6D195AFACE56ULL, 0xCBB40B870B19ABFEULL, 0x5B812430CAEFAC7FULL, 
            0x45424FAF5EA7916CULL, 0x759BDDA66DFFE4B4ULL, 0xAB5ABC8928DFB371ULL, 0x7D4A769C51848696ULL, 
            0x874FAA93AC430389ULL, 0x3B0A501E28F87142ULL, 0x0EC3F8C82CF2FB86ULL, 0x8CE08EAFBFA816B3ULL, 
            0xA69D8697436BFBFFULL, 0x79D2C2761D3F9C70ULL, 0x6AFD26AA27EB4E09ULL, 0xAC5F5462F69B368CULL, 
            0x0DA635CB698303FFULL, 0xF0CADEA4E65E8949ULL, 0x693DD5A48A054732ULL, 0xB437730CE9704D3AULL, 
            0x28BA4DDDDFBCC459ULL, 0x2B23E80379A5E2A5ULL, 0xFF2C74DFCB5D5DFFULL, 0x2E7E92E65A208B52ULL
        }
    },
    {
        {
            0x49DA9C6BB73AFE9AULL, 0xB8AABCA1BF04E6A9ULL, 0x298838DD1DF3E588ULL, 0xC86B24F76223D5B5ULL, 
            0xF4AC3769815431C6ULL, 0x6DFD42393B750CD2ULL, 0x89D2BC212C52182DULL, 0xC5E48383D238A25CULL, 
            0xB80F68CC68158D1CULL, 0xA31837F43FFA56D3ULL, 0xC3C1F3EDDFD782E8ULL, 0x3D1275E62D046B1BULL, 
            0x6918F57FD054D866ULL, 0x40F0AEA4BE958525ULL, 0x55AF43A317E1D393ULL, 0xF8EB967D52EB15CDULL, 
            0xD27D07676E1B7E53ULL, 0x44648BC6466DA85AULL, 0x8240C43CEEF7B555ULL, 0xECBD1DE3C11FE56AULL, 
            0x73B9F6A70D1B87F2ULL, 0xC14D7538B301F6F9ULL, 0x1BA2B81897762FEAULL, 0x87AE56901B9525E3ULL, 
            0x5D3C6AA67B1B2F58ULL, 0x2A10E5142859F8A1ULL, 0x845026181D5A588CULL, 0xFFE690954F81230EULL, 
            0xA8E993EC3BEE41E1ULL, 0xCE0A3C0F2DD4E854ULL, 0x543CDB07FA4E867FULL, 0x4090E3E729362E66ULL
        },
        {
            0x99BA7081B8AB7B41ULL, 0xABDBC16DAB2D83A1ULL, 0x7950248CCA854C63ULL, 0x9FA0190D37D8263AULL, 
            0x47894190BCA8C355ULL, 0xE1080F629E97A249ULL, 0x1B0C15EDAAC47D41ULL, 0x0A1C72E470750430ULL, 
            0x2FE1621EAD186885ULL, 0xB829DA7C7E7C5076ULL, 0x865EA198F03874AFULL, 0x7802FFFDDFDA9565ULL, 
            0x70D2B3A5422BC8DDULL, 0x4BA17124E1104DCAULL, 0x4B1B8E89012A04F8ULL, 0x39451C7AF10048F2ULL, 
            0x2F30D17ABB531513ULL, 0x5EDF02A65985078DULL, 0x421A05766AD8C745ULL, 0xB3934AE27AECA058ULL, 
            0xDA264BB5842242B6ULL, 0x864918689CCE9116ULL, 0x41AB308BB52F8B05ULL, 0x6C2A5BF0719FD119ULL, 
            0xCE2072BFA2BEEB85ULL, 0x5294B8AB760F83F1ULL, 0x8D86456BE9776ABBULL, 0xE36D9B29A45F148BULL, 
            0x34379CBE154344FAULL, 0x770A8F19C01DE7F7ULL, 0xAFA6A023C06C1B90ULL, 0xB595157EEE0227F6ULL
        },
        {
            0x1EF4B3002803AE17ULL, 0xC872E1E7703DBAB1ULL, 0x9AA8CE743F04764EULL, 0x19C35862BE2BDD22ULL, 
            0xA85AB0CACAFE8231ULL, 0x636A0E2B2AEB9275ULL, 0x0CDD96441FF61757ULL, 0x373529D8CCEC8FA1ULL, 
            0x8009D59E1F8ABC4DULL, 0xD4827D601585B33DULL, 0xA2906AFB5A46CC6FULL, 0xB116C2C91D9D2FD0ULL, 
            0x9A210B95DBBBA674ULL, 0xD3E6A301BD578996ULL, 0xAF3D84FE5A782598ULL, 0x92A4A729612A0397ULL, 
            0x2682D51823D6B944ULL, 0xF8BCB69BC8AF3AF7ULL, 0x67A3D41FB50FDCB4ULL, 0x9DCD90569F418036ULL, 
            0x8216CDE0F38B5B46ULL, 0x1DB6415014959CA5ULL, 0xCF39D35B5C7F8601ULL, 0xC58A7E062C326431ULL, 
            0xA57D2E88E71B73CFULL, 0x75008B780E8FBEA4ULL, 0xA49D50FEDCD92DF2ULL, 0xC78B107FBD544080ULL, 
            0x38A474362DC1CF77ULL, 0x2B8606193E81FABAULL, 0x9A2CF5BA6A4F3AC4ULL, 0x45FE5AFA082E242FULL
        },
        {
            0xB1466CB859BFA9D0ULL, 0x26975AB74A4C9EF9ULL, 0x1BCA303CC3B82DC5ULL, 0xDD096F9FA97E23BBULL, 
            0x024DD66F648BDA02ULL, 0xA3CB5E19FC8A0878ULL, 0x19FF1434C1360A2DULL, 0x1E0D3C6E587E9A3EULL, 
            0x9C2EE88183D13BC3ULL, 0xB8FEB9E7DA53EB37ULL, 0x2E687C2453BB752BULL, 0xD9EB9BAC3705971AULL, 
            0x73C28795F62429EEULL, 0xE1D5571A03083029ULL, 0x48CD9CA2FC536AAEULL, 0xFD00B5FFAC676B55ULL, 
            0xA9760A9048CADFB6ULL, 0x89A78805AF4A6148ULL, 0x64AA759B2EA93735ULL, 0x97B8EFD350298500ULL, 
            0x861BAAE3F3C04FE4ULL, 0xD00BC8CF705F512CULL, 0x9A17FDE6EAC1D20FULL, 0xAA9073C37E29BDF7ULL, 
            0xDBF35AD718B9AE9AULL, 0x7C84382E6588566AULL, 0xF25F8DF1CEAF3177ULL, 0xDC330210332B8025ULL, 
            0xB63B32FC574BD876ULL, 0xC7366BBBD6D86897ULL, 0x605BC9F7AC72B758ULL, 0x318D2145255826F1ULL
        },
        {
            0x3E84ECC1957877A2ULL, 0xFF467B5C22E41330ULL, 0x6925348E7C6E8A9FULL, 0x5F6FF7E20C32108EULL, 
            0x8126EE8631252AABULL, 0xBA7244B0D02104F3ULL, 0x7400178FA33EA0E5ULL, 0xA992384BC4B4E8DCULL, 
            0x255199AA8254F5E4ULL, 0x855F1E55690AC947ULL, 0x11327EF0EB679F0BULL, 0xC7E0A886F1138D4DULL, 
            0x058928AD83BC20C3ULL, 0x3BCB60658B401BD5ULL, 0xDFC97F6C300EF8E7ULL, 0x91EA69699A5B16F4ULL, 
            0x6B32FB488C7BA34FULL, 0xBA53B44E545812D7ULL, 0x2DD6D31201A8D465ULL, 0x04B7F68A338F1BF6ULL, 
            0x9CDFD575DD0E2200ULL, 0x2577C2B491E5ABDFULL, 0x1E5EEE5C075F8F16ULL, 0xD858779AAB8B4AF2ULL, 
            0x31ACE3B9737D0BEEULL, 0xB04388E30A824FC1ULL, 0xB1E284E540A9C496ULL, 0x486162EC5BD29ECFULL, 
            0x39BFA682EDCA2346ULL, 0x5FFEECA10328B142ULL, 0xBBE729F55BE3100FULL, 0xA45A6B748F79987BULL
        },
        {
            0x9C6D23D5D3F2CB5FULL, 0x102E6A6F9D0BBF5DULL, 0x8B0112B312EBE6B0ULL, 0xB17427A137990EBAULL, 
            0xC31FC431C3E05839ULL, 0x15B6891F0CE92064ULL, 0x6BEA77CEAEFA1A67ULL, 0x7607B248EF9DCF0FULL, 
            0x354D383F4CED6B7CULL, 0x1D163EFCD164434EULL, 0x3B158E9021A8EB4EULL, 0xB3056F0A4D82BD8BULL, 
            0x659C9C3027E3E629ULL, 0x0430375507315387ULL, 0xB6FE44EF1179AE28ULL, 0x2A5B193C7C21617FULL, 
            0x0A714BDEF469FD1DULL, 0x663C036361826FD4ULL, 0xC9AC383B471F24C8ULL, 0xDFBE08DA77C8736BULL, 
            0xB4FC0CF9682162D8ULL, 0x90279A61C4D52A7EULL, 0x7671F5980510A75AULL, 0x15688C22AB3BEB2AULL, 
            0xB273FAC030957023ULL, 0xFA3B5998B98261D9ULL, 0xEC26A6415DE05524ULL, 0x67971FBB2E7BF174ULL, 
            0x75F0030020FF1515ULL, 0x3074C70F588E6BC6ULL, 0x85AB8641DD8B2EDAULL, 0x70C54C0B74638C24ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Achernar::kKeyRotateAConstants = {
    0x1B43FBFC9AB9DD21ULL,
    0x1CDE9BD933EC97A8ULL,
    0xA8B543EADF5E3065ULL,
    0x1B43FBFC9AB9DD21ULL,
    0x1CDE9BD933EC97A8ULL,
    0xA8B543EADF5E3065ULL,
    0x33667B3E9ED7BD74ULL,
    0xD0B946BB9AEA7C96ULL,
    0x5E,
    0x8C,
    0x97,
    0x57,
    0x19,
    0xCD,
    0x54,
    0x2A
};

const TwistDomainSaltSet TwistExpander_Achernar::kKeyRotateBSalts = {
    {
        {
            0xC566011A8F22044BULL, 0xDE89E8DE6D791081ULL, 0x90C7C1A912BECEA3ULL, 0x5B5E62E7180D6F6DULL, 
            0x059A5F7A747056AFULL, 0xFD7ECE2EB37DB110ULL, 0x76BBF434B943912CULL, 0x7065BB3FA822642FULL, 
            0x9800EED245C9A500ULL, 0xB812EFC19F6DE17EULL, 0x1D8C51D6278BFF5CULL, 0x1FAB94BAF58EA75AULL, 
            0x7A1B762D25514785ULL, 0x17ED594479036C23ULL, 0x36B48E3AFEFAE7BFULL, 0x3AA7C0122672AD11ULL, 
            0x5E065B38BDD21240ULL, 0x7405589569E92453ULL, 0x81C844979AE23292ULL, 0x1D07B8D9C4E3CDDBULL, 
            0x26661D3AEE4DB71EULL, 0xE6CD3F9D5FA55D8AULL, 0xD5ED537213FDB0CBULL, 0x96847BB9190729A5ULL, 
            0x52E8C7690F05BADCULL, 0x658CB58D54F512EFULL, 0x889D1F80629E906BULL, 0xC45F49765A966958ULL, 
            0x07DFABCF0ADDF5CFULL, 0x019DF31D11A3156DULL, 0xE93BADD48F0573F6ULL, 0x9C1E431C69B9CDD2ULL
        },
        {
            0x28086E7FCC9D504FULL, 0xF0B4E51C29DA9410ULL, 0x9DE6025730FEB69BULL, 0xB76A693F394DFB22ULL, 
            0x83F42246C91CD5B2ULL, 0x732FDD2AD61A4668ULL, 0x380FB29C6FE46DDBULL, 0x28BEAF162FC279D4ULL, 
            0x519384BD5A7FD8BFULL, 0xE0689E2FA71913CBULL, 0xCD136040E9EE9CC6ULL, 0x3FFFB4B48B3552DCULL, 
            0xAE09D70A949FB703ULL, 0xC02ACE64524CB9A3ULL, 0xBBCA3142A1B2753EULL, 0x57AFA1CD28C42225ULL, 
            0xD5CE8D739E537458ULL, 0xA208A02F4BFA532FULL, 0x4A3B566AEC2B67A7ULL, 0x6226E46512D8EEF7ULL, 
            0x718ED6A78532E567ULL, 0xACA212A3F4271C1FULL, 0x85ED04B8F0A29090ULL, 0x964DEAC610357D44ULL, 
            0x3BD02A4452277544ULL, 0x9A19BF1A7D455D86ULL, 0x835BACBFC33A8A70ULL, 0x8E1F7F61923DA256ULL, 
            0xB741722C18102D1EULL, 0x16BD5DDEE307A531ULL, 0x0B652BE55CD0DE60ULL, 0x92DC25C7133F7312ULL
        },
        {
            0x5D4B81928DCCB401ULL, 0xCB5096D051318251ULL, 0x2E80E8F8A37E7F2FULL, 0xF8210E8E4448579CULL, 
            0x6E530F08048000D4ULL, 0xFF37B146B17BE990ULL, 0xBF1A842BDE07473DULL, 0xA6AA2AEBDC359236ULL, 
            0x4D5CD0E9DDDF8898ULL, 0x6210F387232C1157ULL, 0x631CEAE19C74ECA2ULL, 0x83E9DCDDFADA3814ULL, 
            0xC1DBC921305A35F8ULL, 0xB0D220256AD6E1D2ULL, 0xA0004E36216F53D1ULL, 0xF6A98675145E1F5BULL, 
            0x0B17186DDBD725B5ULL, 0xD6B8FF400755B58FULL, 0x64E13024E7FDA829ULL, 0x810A208C792721C3ULL, 
            0xC3373DCC4370F4D2ULL, 0xD8B754D70FBC7A8DULL, 0xDBE6CCE5D7F27FEDULL, 0xB844334518D16ECCULL, 
            0x591B035011E99B78ULL, 0x253100689CCEA1DFULL, 0x2DF8B7627D873F9DULL, 0x18689D7AFA8D6B0DULL, 
            0x9FD9E672B6B496DDULL, 0xD716BADDEB00D922ULL, 0x45B8302DC11199A0ULL, 0x89C817347AADAE56ULL
        },
        {
            0xD72F2A11E36F0061ULL, 0xCA8546A675D6DB33ULL, 0x45268246F493E249ULL, 0x62102EFF0ED745B8ULL, 
            0x290FB821B38F5D00ULL, 0x3DC40A7295776E88ULL, 0xA4AAAA245C933284ULL, 0xFD4DA0251FB4F957ULL, 
            0x5D9D8032B1779C9AULL, 0x9A59C5459B867D4FULL, 0x5A7C59512BE4968CULL, 0x61FFEAEC737AF2C6ULL, 
            0x995DE42D53DAD9D8ULL, 0x89C08E4E53A747F9ULL, 0xA25547CA8B05449CULL, 0xC4A7EF14F130E8C7ULL, 
            0x099D27EBD91D472EULL, 0x3179445F22499C2FULL, 0x73602A95042E9D63ULL, 0x2E6D615BC18FEC3DULL, 
            0x67AAC6638B4C3392ULL, 0xCF26268D6927EA64ULL, 0x558B8BFB52B66AFFULL, 0xCDD545CAA036CD8DULL, 
            0xE07742E06AEC9BE7ULL, 0x3960670F53D9C96EULL, 0x1A885C9DBFFED97CULL, 0x693D92F1DD63C5FFULL, 
            0x5137D23EF2BA6CE6ULL, 0x6B12CF1D3939DFD0ULL, 0x2986B698DFB277AEULL, 0x996DFB758ABD3822ULL
        },
        {
            0x94E207453B431625ULL, 0x26E687408CFC62CFULL, 0x897D163D914475D5ULL, 0x7FEF597047E4291AULL, 
            0xD88A5D2AC2C7FD6CULL, 0x045D4893825DF1D8ULL, 0x5DEF6D64D1B401CBULL, 0xA63FBF8ED10DFA71ULL, 
            0x40788E6D006BF2D0ULL, 0x1B67AD42BA5E87CBULL, 0x1E90136AC41DD5A2ULL, 0x713BD23CFFA52739ULL, 
            0x91F1008583DEC53EULL, 0xFDA6D63585EF4ACBULL, 0xB924B3B8ADE2D06CULL, 0x63971D8FEACD6157ULL, 
            0x1187FB3D0EB12C43ULL, 0x6F6C0C068FFC38EBULL, 0xD58474DE5DC65778ULL, 0x8AF93F7C379027FCULL, 
            0x7A9B4DC3E666738AULL, 0x55AD8A06092F8F53ULL, 0x635905C303DF6E29ULL, 0x01A63E8CBBD46B4CULL, 
            0x9D498C74B0AA3F43ULL, 0xED097C911525E8D5ULL, 0xF0612EC74C23C99AULL, 0x1474511B6B4F6415ULL, 
            0x305FD1826353ADFCULL, 0x56FB5B451FA1E48AULL, 0xD400CE18B18948AAULL, 0x71BB4E2022D4A0A5ULL
        },
        {
            0x5FCD13595ADC8959ULL, 0xBBF18CA485C66867ULL, 0x502BB9FFE24E472BULL, 0xB1CB5A9EDBF6C5BDULL, 
            0xCDE66D3A67A410AAULL, 0xF3ECE79688C41B5AULL, 0xCDEEB1F873F7F7D8ULL, 0xED0B5D4E96F55133ULL, 
            0xE9F1912152899F36ULL, 0xB35E4FE015B65B09ULL, 0xF53C364DE75FBB60ULL, 0x4C8876EB8E633D07ULL, 
            0xDABDA374DA9C5B78ULL, 0x0F2473D645AE3C7DULL, 0x0C04F435B1CB181FULL, 0xC73B73374601EFD0ULL, 
            0x7B3C16132159B5E3ULL, 0xAC213FD35E253C29ULL, 0x2AAB12DD76DD6052ULL, 0x8F4B7F232FB92030ULL, 
            0x0383D3E3ED890C4FULL, 0x6A80550BED280F0EULL, 0xFB046AD5FE4EE457ULL, 0x255C6FEF203D9086ULL, 
            0x20CA205A51E0F86AULL, 0xFE4F3812963CBA2DULL, 0xD32FDDBEDD1B11FEULL, 0x1683634872DDEF99ULL, 
            0x7627201E89282F9CULL, 0xEDED4BA83546AB82ULL, 0xD66DC6F9652B1A44ULL, 0x85A4DB91D375A10FULL
        }
    },
    {
        {
            0x9E8495E49125F697ULL, 0xB6425BD38D8C7ABFULL, 0x4977DD44EF70FB02ULL, 0x18972126C35FA1FAULL, 
            0xE2A4E97B6AD3520FULL, 0x614546AACF5736BFULL, 0xA27DBA55C65B5DB5ULL, 0x6BEB1F41864811E8ULL, 
            0x654D26C492B840F4ULL, 0x4E256EE8FEEEAF4AULL, 0xAB8F827BB2E174BFULL, 0xA81D67A6759A8B3EULL, 
            0xA7D6B94F4652947AULL, 0x983BBB9810B597DDULL, 0x03651BDB6E46FA69ULL, 0xA3FDEBC7B8C8CB73ULL, 
            0x05E3380CE0BE385BULL, 0xD3CACBF575933604ULL, 0x5BEE0ED061EA7EEBULL, 0xFC61ECDB53916845ULL, 
            0xF86BF8F3099FF141ULL, 0x0D3AB44278D61876ULL, 0x301BDCE4FBDB1D80ULL, 0x20CB37646E94F57DULL, 
            0xBAE60FB0E0D90DD6ULL, 0x8588BE8283ECED1FULL, 0xED4100692E7B2F87ULL, 0x45C5EB81A81A2BB0ULL, 
            0x539254772695AADFULL, 0xC23E26C8309F111BULL, 0x28E8CA4FB31C7377ULL, 0x2C88226BAFEF2D98ULL
        },
        {
            0xD3737B53D1C6FED9ULL, 0x2699A5CFF9F36FDAULL, 0xD8FEA1A07E001526ULL, 0x186784950B639210ULL, 
            0xE787FD8CF694B1CDULL, 0x0086C1E846367C0AULL, 0xC92CE52C33A37105ULL, 0xA2E9AED99B6AA657ULL, 
            0xBE119D4726ABDA53ULL, 0x4AF765DFABCDF4AEULL, 0xA8A927D887A44CA4ULL, 0x3FD67E1E661A205AULL, 
            0x26508A731E60B966ULL, 0x55DBD4B3B375E861ULL, 0xA464EDE567BA23BAULL, 0x639470D46652397EULL, 
            0x57B5C466428E5710ULL, 0xF0106DB1C764C9F4ULL, 0xFBB812509CC1390BULL, 0x9AEA05F40A8F725DULL, 
            0x2002B56C4B846B75ULL, 0x06C04BF099364948ULL, 0x954C2D1919C13AB8ULL, 0x1756B036182AB3EEULL, 
            0x9262D65E139A7AA1ULL, 0x4E517A50C0543A25ULL, 0xFD1F64C0B7853A88ULL, 0x12D1A08D3E26B45EULL, 
            0x5B00A1E323E05381ULL, 0x21730EFB4071A6C3ULL, 0x7D88C60352FE9DE3ULL, 0xAF8F6EB7398CA447ULL
        },
        {
            0x6854FD59B85CD3C3ULL, 0x25F76E01BB3D04E9ULL, 0x58EA313B15DC366AULL, 0xA1DF081CE7EB06ABULL, 
            0x8CC01C4E595FD92DULL, 0x4D9C0BEC0FE4E1AAULL, 0xABA3D6D63C767450ULL, 0xAFDB2AE107677132ULL, 
            0x1FBA888D4AADC1EFULL, 0xC547DBF96ADB3656ULL, 0x35F15A2D24FDDFB9ULL, 0xD2ABEC742A5664ADULL, 
            0x4485CCC8CEC9153AULL, 0x6F0BD69F196A0DD4ULL, 0xC138960D0FA77A9BULL, 0xBFF10B7E6AB66D52ULL, 
            0x25759E6A7A4BA232ULL, 0x6E20D354779B4C4AULL, 0x705AEFD7C515B5EBULL, 0x54D9D8CF24331C28ULL, 
            0xB10B9AE2CDB755C1ULL, 0x3A063623B10588C3ULL, 0xD2AE89CDE9741DC8ULL, 0x45D31CC89E0085C6ULL, 
            0xE89B137AD6188F32ULL, 0x3E5F4828C27ECE50ULL, 0x56B4DBD5B06967F8ULL, 0x8C9875359283E4DEULL, 
            0x8E611587647DCA10ULL, 0xFA10A9A219CBD484ULL, 0x0251593B37A33C55ULL, 0x9838C2722E9E1E48ULL
        },
        {
            0xF90440B8885F7D31ULL, 0x8D7F76D8DBC809C9ULL, 0x07B76F9360C33340ULL, 0x503143F0B7A53C07ULL, 
            0x28C862A43B6BDF6EULL, 0xC3D74B6A1F0F81B4ULL, 0x09688012B7B6F048ULL, 0xF6EDE47BB44E0F83ULL, 
            0xEF2051348052F180ULL, 0x3F0F3A16CC06D3DBULL, 0xFB8C7E3F01F35BFAULL, 0xC7CAD61D25E3B922ULL, 
            0xC237B742A3DC4456ULL, 0x26D13F3426108099ULL, 0xB3DBD3BFC8DD255DULL, 0x91EC1820FC1157C9ULL, 
            0x91DB3D5DE64AFCF0ULL, 0xB3E0352844CFBD0FULL, 0xBE717D64F08BE13AULL, 0x82374A443ED41307ULL, 
            0xB9E42153C9425BE7ULL, 0xA65A31A7391D9764ULL, 0x0D4CA85CB0EA8B8DULL, 0xCE28DA1FDBCF519CULL, 
            0xCE40D94EF5B3BABFULL, 0x89AF5FB154903478ULL, 0x9C35F2EDD0321E66ULL, 0x1614A4E12FE76F22ULL, 
            0x45ECD94BA7AF714EULL, 0x227062C304DE9478ULL, 0x7C3AD564B16ABA60ULL, 0xFC5D4BE901E3F9BEULL
        },
        {
            0x5BB605C575BEBA96ULL, 0x131B1BF69BA18F39ULL, 0xC1FD57A8A0EC1BDFULL, 0xD8B403D64EAB1577ULL, 
            0xFB1380FC368175F3ULL, 0x2EB7D4BEA2F30F14ULL, 0x4016035FA287D9E6ULL, 0x5AA56FF4E88084ADULL, 
            0x29F61FF82F607FF6ULL, 0x1E64E4B90DCDB628ULL, 0x16601FBF54DCCA62ULL, 0xC9360C93FBB4B256ULL, 
            0xEEBA7966DA7BBE30ULL, 0x683AE13C09F2C102ULL, 0xD7A5778D75CFB485ULL, 0xDD4BE6F18A3F68C4ULL, 
            0xA18797D87CAA9C07ULL, 0x146A7E49C9C69801ULL, 0x0B328F8D1061F659ULL, 0xCF8DE9D9D417F434ULL, 
            0xE1F4146186AE1ECCULL, 0x1E455009FEF59503ULL, 0x93B9CA72DD80B23AULL, 0xD26E4AAFA8ECB73AULL, 
            0x69F8A976E7CD1B4EULL, 0x48FF66B02394A411ULL, 0x4A695FD2FD10AB38ULL, 0x662F6316811FD0ACULL, 
            0x86699C02DF923CFEULL, 0xECB783AE22B7EA32ULL, 0x96E64E35246FD66CULL, 0x3486417E5F0244E9ULL
        },
        {
            0x44510E6C5082F939ULL, 0xCD71DE385BABA1B2ULL, 0xEA1D12EDB65AB860ULL, 0xD5BDF61127535CF1ULL, 
            0x649D4F1CA20CD537ULL, 0x576C6ABA33293217ULL, 0x9B14CE3F66E0DC28ULL, 0x5D16EE643E76D513ULL, 
            0x58F8AA8655545BAEULL, 0x3936A3605C27EC37ULL, 0xC726F798C7E611B1ULL, 0x98EB982EBCBA61CCULL, 
            0xCF56DD49166A3690ULL, 0x8747B3572555EBF4ULL, 0x4B89DDB3696971F7ULL, 0x5DF658F9717F14A3ULL, 
            0xBCB1F353B29FB9B4ULL, 0x753FB46D4CCEF861ULL, 0x28552274D913EE28ULL, 0x2D88C26A66A7CF85ULL, 
            0xA8860AD23EDCFED4ULL, 0x24F51AFAA5E7B80BULL, 0xFB38D9933B2385EDULL, 0x46E0C6B1A87145ACULL, 
            0xBB0FF8CF4ACA1206ULL, 0x7A3DA112A390008DULL, 0x063FC4235811CAB3ULL, 0xF203D98682C85057ULL, 
            0xA2621678F79D92ADULL, 0xD7EB144C3FA0AD10ULL, 0x28EC459AA708317BULL, 0xEBBF26A679FDCED6ULL
        }
    },
    {
        {
            0x7ADB971001888C32ULL, 0x13967D205EE4B0F7ULL, 0xB8159BB53E9A3853ULL, 0x38D1E7021BF93657ULL, 
            0x758ADBC22DC23D0CULL, 0x229970A42B4F9AFBULL, 0x27D8D9AFC31E3A9BULL, 0xD66DCC934743C282ULL, 
            0xD5EF4E5B2FB8B7F5ULL, 0xB5AE43372B368E72ULL, 0x815C59D6A8B10B5AULL, 0xCB475FBF04697ECFULL, 
            0x7AA82C0AF72C8996ULL, 0x0CA5C58D385C230CULL, 0xC35ABB551A64B108ULL, 0xA48706474DF7BCA8ULL, 
            0x39A7C2FF87D2CC29ULL, 0xEF1ADA9866D93C8CULL, 0x23A9E0F88AC11012ULL, 0x788797A7E694AB91ULL, 
            0x2879E963206C7429ULL, 0xFCA0E8B84B7DAD32ULL, 0x94835A62A946B34AULL, 0xB66FA193EBEE36EEULL, 
            0x4A408765EBD76EFFULL, 0x0DEA8380CCC78A50ULL, 0x73093E84FAA9E5B0ULL, 0xB916CF421AE77538ULL, 
            0xBEB40E2D65A350F3ULL, 0xA52B8629B4AEB9B0ULL, 0x635FF968C0944B6FULL, 0x2859BDD0E7476D30ULL
        },
        {
            0x32194CE32BC2DF05ULL, 0x10B85403B6742FC5ULL, 0xD758B812BB97802FULL, 0x9164E03565EEC2B8ULL, 
            0xEDD9DE783D4FA448ULL, 0x2D17A66026AFE13BULL, 0x1F6C502E162265C8ULL, 0x56EFEE9304F6411DULL, 
            0x5A1795DBBB392B00ULL, 0x784CF6773284BE71ULL, 0x65E5AB08CDBB6D12ULL, 0xEE97B04D1EEEFA01ULL, 
            0x830C9AE1E23FC643ULL, 0x69DC356809600E65ULL, 0xEFBB665FD34DE088ULL, 0x857A4810CE6EB9FCULL, 
            0x328E5E7C4A56A9C9ULL, 0x6E3F95FEC70F7EEEULL, 0x9EAB4AA072860A3AULL, 0x8635B8EA42178743ULL, 
            0xF1BBC8FE8ABA37DEULL, 0xDBCA4113144A1508ULL, 0x531A6DCB252A6695ULL, 0x26F4DB6F6E310849ULL, 
            0x10A427AF2C0EE712ULL, 0xAE713B242DAFB247ULL, 0x01E7ABF8FC90581CULL, 0x1683B28EF7CC179BULL, 
            0xCCA03F65298AC7AAULL, 0xC05EB18E5457607EULL, 0xFBF9D05EC80CF3F2ULL, 0xE6E280500810FB7BULL
        },
        {
            0x3FA9B91A6935E0B6ULL, 0xBB4AFD7B01620545ULL, 0xCE9EE290E29FDA97ULL, 0xD3DF67F5B777777BULL, 
            0xCFC71DA364F2F466ULL, 0xFA379B787773CE55ULL, 0x1FD623C7D26DA68DULL, 0xFFA4D3946FD3A87DULL, 
            0x15008EEE808777C1ULL, 0xFE7922A0A57B7B58ULL, 0xE355223CC068B101ULL, 0x36B353B0229C2B80ULL, 
            0x437D1AB4EA817251ULL, 0x2B5A607D7A53FCA7ULL, 0x5DA6D7BEEB4337C2ULL, 0xD8367E13DAE393D1ULL, 
            0x051CB643FBFFEB84ULL, 0x495A15B97555A8BDULL, 0xDD2087D04B08E54BULL, 0x7989682CDDC26138ULL, 
            0x063A0A1A7E413407ULL, 0x0166D523F634A774ULL, 0x6CE04B1567F176AAULL, 0x5E4E095A79464858ULL, 
            0x41084EEF19ABCCEEULL, 0xCE9A437C83CD9FF9ULL, 0x16CE26947AB32945ULL, 0x0CF8503159B24C3BULL, 
            0xFBA8F584E3FC348AULL, 0xF0478D3D6C7EDD6BULL, 0xDD0041A122ADC700ULL, 0x90A57FDC2386199EULL
        },
        {
            0x8CA45B47113DEC8BULL, 0xD712CC048E2C15BAULL, 0xAF700A0AC55B35AAULL, 0x4A2782F8A11C71CBULL, 
            0xB2B21DFE52319C77ULL, 0x08D04D9A4B02ED9DULL, 0x88B00772E168BFBDULL, 0x3CAAE427D3D2DAEFULL, 
            0xD4CB910F88FC8E32ULL, 0x0A6396C5E99308E1ULL, 0x7A5F0A9CC17AF82FULL, 0x33DF25B9439BDBC4ULL, 
            0x7BCC3687E9F8F74AULL, 0x28ADC38604F25F9FULL, 0x0FFCAB491D2E2F3CULL, 0x1D98DF7FCD67CF44ULL, 
            0x2068C1DD811618B7ULL, 0x7F2F9EB9A2117BEEULL, 0x56AFB3137BD060E4ULL, 0x0A47335295D6D1EAULL, 
            0xF9706F75592645E3ULL, 0x04EBB76A294DB583ULL, 0x47E02EFD1B41933CULL, 0xA2B7468C60F9766EULL, 
            0x589F3E4295DD04FFULL, 0x9B5779CB8BDE3271ULL, 0x99234B447AD2821CULL, 0x5722FC9FD9547AC3ULL, 
            0x8922556E8FCEC406ULL, 0xB08BBA951C20D521ULL, 0xD03A1347A4E08F9FULL, 0xB74374FFC12FD53CULL
        },
        {
            0x64D5B4CF54CDEEB0ULL, 0x3F48B91B07C6CF94ULL, 0x3E055918E865293CULL, 0x7304CC95EB615BBAULL, 
            0x688F97C4F639B70DULL, 0xFE8D26A797AAADA4ULL, 0xC13C4FDB6CB060C6ULL, 0x849515EACF730757ULL, 
            0x87E36F36B95E89DFULL, 0x3B0BDF2D779EF939ULL, 0x7F3987D6CB5801BFULL, 0x1B310AD2B674C6ABULL, 
            0xF1A233DC1A5164F8ULL, 0xD91AB0EC1994F891ULL, 0x258BE0D88A18F2FFULL, 0x0F1873C37A40B506ULL, 
            0x0B5590C7DE0507E5ULL, 0xD7A28959F279141FULL, 0x949553EE163D56EBULL, 0xCAB5EEAF73865289ULL, 
            0x56689E3E7FC7F847ULL, 0x69C35841E056F381ULL, 0xB418496196E5F3A2ULL, 0x76146E1AA3351765ULL, 
            0x51C46760B1A2517BULL, 0x99571B0E2CE1B6DDULL, 0x02F484BF237C080CULL, 0x9D27D92B4B30ACE6ULL, 
            0x9061533CAAED0AF3ULL, 0x5165F90906254D5CULL, 0xD2143856D91CEF37ULL, 0x2C7E677BCAEEC615ULL
        },
        {
            0x731F5078949F3F08ULL, 0xFD262B6DA032B76BULL, 0x2095E38F0C9E04A4ULL, 0x13BE8FF9CAAB1BB7ULL, 
            0x0D88E1C06E75A483ULL, 0xEF702A9246E321C9ULL, 0x90692CC7BF3E7286ULL, 0x8183211A43D83CC1ULL, 
            0xFA590C1D68564ABAULL, 0x62A43FEBE6D8D58BULL, 0xDAB4737EE83575C5ULL, 0x2B76BFA6A3D91897ULL, 
            0x74ABC83605D850B0ULL, 0x1EDCC8615315B1F3ULL, 0xA269290439C0F1F0ULL, 0xF5B52BFA01D4B053ULL, 
            0x5DA918DA1E5BC733ULL, 0xF81B1D67777F58CDULL, 0x8D5B7D889A0B2F93ULL, 0x359D0469025ABE51ULL, 
            0xB7000E66B94462F3ULL, 0xF9BD8970F7B54997ULL, 0x56F6F5B1DB60176CULL, 0xF63AC1FF79F9E552ULL, 
            0xFBC09BB90091C618ULL, 0x1A91F542513BA348ULL, 0x6DD3D4497D687C5CULL, 0x6DD4CA2ED4CC8BB4ULL, 
            0xEA25399C242F2A29ULL, 0x9958CBBFE0F6B378ULL, 0x2700A178CDA2AA60ULL, 0x4DE910E5580DADFFULL
        }
    }
};

const TwistDomainConstants TwistExpander_Achernar::kKeyRotateBConstants = {
    0x6399904028540CDEULL,
    0xABB43449D76F81C5ULL,
    0x427F14DD82755D58ULL,
    0x6399904028540CDEULL,
    0xABB43449D76F81C5ULL,
    0x427F14DD82755D58ULL,
    0xDC07F41B4FDB18A9ULL,
    0xF072C6E30113BE12ULL,
    0xBE,
    0x45,
    0x16,
    0x65,
    0x63,
    0xDA,
    0x38,
    0x27
};

const TwistDomainSaltSet TwistExpander_Achernar::kKeySpawnASalts = {
    {
        {
            0x3EB58BD286E9D84EULL, 0xC73EEC10DB76B884ULL, 0x9383F5902E0905EBULL, 0xC7C710D98351F812ULL, 
            0x1FB7F4287326B393ULL, 0xF32F7BCDB236E9BEULL, 0x03AA3DCBBAF0F676ULL, 0xABE715FF565314ACULL, 
            0xC492A708D56A2277ULL, 0x8BF6B2266F29CE7AULL, 0xECF1E33722143742ULL, 0xF45EE2EC21DF70BFULL, 
            0xACC4BD5CD446CA24ULL, 0xCE18FA2ED494993DULL, 0x4D00E6D3D03316FCULL, 0xE5805823491F6D73ULL, 
            0xADF41C5514BD1254ULL, 0xD0487B503E67409AULL, 0xF59A3BA2AFEEDF83ULL, 0x4E607ECD73720D93ULL, 
            0x7B4645233BD89195ULL, 0x61696429D615561EULL, 0x853E390BE88E8353ULL, 0x76BD6E17EF5A1461ULL, 
            0x1A13C2136E8A61AFULL, 0xAADD2A3A22AB9DDEULL, 0x885A74C583A39579ULL, 0x6F1396CFE5BDAA62ULL, 
            0xFFE3B96F4206D936ULL, 0x1FD6C3029075DEE8ULL, 0x777304406AB4F0CBULL, 0x44BD9AF804A5C715ULL
        },
        {
            0x4B0FBE5A8F773EB2ULL, 0x55045F28DB71A97CULL, 0x985CDA4A1A20C741ULL, 0xEF465F2504B9A220ULL, 
            0x6D98232926DDC2D9ULL, 0xE88493AE9BB5E1D9ULL, 0x5DD1629D9FB70350ULL, 0xFFE3054A4D80AEE2ULL, 
            0x84B6B9E41AEC1F9FULL, 0x4676DD316A3152DEULL, 0x081CDD050E263296ULL, 0xCC923AC8CEE7487AULL, 
            0x6E11AB6D09DDAEB7ULL, 0x2E065FD4D4BFFE08ULL, 0x24B48BE2FFBD4FAEULL, 0xEC56C7909F203406ULL, 
            0x2722767DBE52CDEFULL, 0xA6EC77594FF556ACULL, 0x1F13E3378817E962ULL, 0xD1842A75128AB4BCULL, 
            0xA2757919200DDD73ULL, 0x02D7D35851452222ULL, 0xAD6CB80F4FB41BBAULL, 0xDD7FE8C75108DA93ULL, 
            0xFCE4D0DD41624A5DULL, 0x6022B58858E62999ULL, 0xEE54DE38B8B7E787ULL, 0x28BC908B89CDBCB1ULL, 
            0x1F5FF06B1B21C063ULL, 0x03860E2F156C78C5ULL, 0x6CE71F3309A95301ULL, 0x21321515BD01B0B4ULL
        },
        {
            0xD832FE74D6E54550ULL, 0xBF4CD7F00BDFD419ULL, 0xEBC77F196794BF52ULL, 0x715929279AC8713BULL, 
            0x2747DBF03D3FC6F7ULL, 0x778AD065A6022DCFULL, 0xF04076D4A69C800EULL, 0xABD23F9BCA797EF0ULL, 
            0x73EF3BF1CCC98F75ULL, 0x3002A33B147BE502ULL, 0x18390A9A23CA0E36ULL, 0xF324BAB3D87661D1ULL, 
            0xF22010739F22A2C4ULL, 0xCEF0358AF081CCBBULL, 0x537A52A5DB633168ULL, 0x9100A0CBE06A2596ULL, 
            0x446AF38E0FFFC645ULL, 0x275FB90A53F06E9BULL, 0xE7E654C38011B594ULL, 0x29D47B6B687F5CE1ULL, 
            0x84F2C5FC29D46F5CULL, 0xFA93EDBF4D5F5E93ULL, 0xEF8C9E39F20C378EULL, 0xD64A1EC6376C8C2DULL, 
            0xDADA99D012649F9CULL, 0xAF562A376C4B2FA0ULL, 0xF88D284F207B1ABFULL, 0x581DD802FE1B03DDULL, 
            0xDE1E9781AA593224ULL, 0x75412BAE02FAE9B0ULL, 0xBE0E025D5BF940F4ULL, 0x222FFAA0B8D41636ULL
        },
        {
            0x1425F1206BBFF05BULL, 0x9ABF3AA33DB001C0ULL, 0x00EF82C6040BD5DAULL, 0xC3990BA92AA474A0ULL, 
            0x440EAF26D6A81EC7ULL, 0x307A5A80489AE6BDULL, 0x839D2F5F9C2A32AEULL, 0x06562CF2354D53CDULL, 
            0xD8827551C2542C60ULL, 0xF2286557F861A6D5ULL, 0x5368F24F9F483F42ULL, 0xC06AF7521B2B25A2ULL, 
            0x10737D343CB6494FULL, 0x2A64160C96E86297ULL, 0xA38D37CF525D828FULL, 0xEA6DADC2C6C84EFBULL, 
            0xD738DFEC288C4B30ULL, 0xFAF385189B89273BULL, 0xA397E8C8CF7FC14FULL, 0x58A74F7F7D6A736DULL, 
            0x816E8F83A00775B8ULL, 0x968176942FF1A314ULL, 0xF9EEDDF498B1D78DULL, 0xD641117B9FB86D15ULL, 
            0x0828F78A36EA7B1CULL, 0x51DFC1FC36CB7C07ULL, 0x41C7FBD0D3A0D1DEULL, 0xA4E42C49E742DF6FULL, 
            0x0340BB5B7158384EULL, 0x9DC30796FE4FEE00ULL, 0x6C195AF0A2CC0ED5ULL, 0x905BDE7DF18DBE70ULL
        },
        {
            0x311674003EBD4E32ULL, 0x6ABCD0511E5721F9ULL, 0xC9B6AA23F0D8CD2BULL, 0xB45F85B7F3121124ULL, 
            0xC02B8E79985DD00CULL, 0x4781FA0D6F501FF2ULL, 0xB79E05D71D10BD97ULL, 0xE47DC98235EE7424ULL, 
            0xF6FEE16F93AE26EEULL, 0x832A75C5214AD81DULL, 0xB941D36B3DA3B85FULL, 0x8630E078A9C0A076ULL, 
            0xE1B8D2362EA80E25ULL, 0xE30492ADC006664DULL, 0x2301B8B7B721E8FBULL, 0xA2638C801E5A408FULL, 
            0x092B8911A4C0E073ULL, 0x02EF5516448ECE4BULL, 0x4D01A0AC9E38FBD7ULL, 0x202685D88ADF3959ULL, 
            0x50145469994477FAULL, 0xD88D672853A8C60FULL, 0x4063D4A812B71E0BULL, 0x4CBC3B5E7085DDBBULL, 
            0x5359072872426A41ULL, 0x39CD1B2C84090FBBULL, 0x30EF3106CE36B4C5ULL, 0x5B0DA7769B7D13B2ULL, 
            0x62CC3CA0B2D68B78ULL, 0xB3FF1BF70766F4DFULL, 0x2D33860EC99ABD60ULL, 0x9DD9DBBAB18218D1ULL
        },
        {
            0x71676CDF836B4932ULL, 0xB70881D44E36DA0EULL, 0xAD85D00711272719ULL, 0x5F80FDD5E16F0E10ULL, 
            0x28D9B087A233CB26ULL, 0x9140FDC1E941BF3CULL, 0x16E0A18DA6683510ULL, 0x602431A137AE3540ULL, 
            0x261997D075ABB227ULL, 0xDC4E93726B3911F4ULL, 0xEF29FF73F0CB6705ULL, 0xEAD42599AD698418ULL, 
            0x990DD5CA2B102F2AULL, 0x6842F3771EF20A8FULL, 0xCD7B8022F8A7245BULL, 0x708EAF585AB91235ULL, 
            0x8DF9A0D3910129C4ULL, 0xF08E03C2AEB1C035ULL, 0x53C2A45216E5DF28ULL, 0x39E551C6EE9C2B39ULL, 
            0xC7B557FB5B6D96AAULL, 0x401FA1558B436EB9ULL, 0x205653046867C994ULL, 0x2B83E8210EF42242ULL, 
            0x6FA0F859294B3D75ULL, 0x1D382494E878041EULL, 0x66FA19DAC097D906ULL, 0x8CBB17BE38F004F4ULL, 
            0x69E38DA2B6E8CCDEULL, 0x93CC96FA4281B083ULL, 0x71E966AC048336D5ULL, 0xB2950468B9E9F725ULL
        }
    },
    {
        {
            0xF545B612294E8287ULL, 0x382DCDCFCF773650ULL, 0xD61854A5D990F1DDULL, 0x14A5E47DC50CBCF4ULL, 
            0xD469C816295693C5ULL, 0xDD7FD27165ABCA5FULL, 0x5D03693E5C596633ULL, 0x59695EDE631173D5ULL, 
            0x9C882BC6F96186E4ULL, 0x596CE2792AFAD3C2ULL, 0xE68D73C1E05B1894ULL, 0x9F3CC6CC5B19AB90ULL, 
            0xB0F3CE112E09DA9EULL, 0x17110D9BA57D8636ULL, 0x36C185A282CB9EC2ULL, 0x10B616BE22339539ULL, 
            0x65CA351A0F9B42E1ULL, 0x7B61A5BB2160B3AFULL, 0xFCFFD605E8F2AFF3ULL, 0x70797DFF35583F28ULL, 
            0xC8D9EABE5EA1EA2FULL, 0x3445DC6B945DAF37ULL, 0xAE81135675E34421ULL, 0xEE283BBA371AC61FULL, 
            0x5491CCC67A7EE75BULL, 0x6CECE8BA1D293CD2ULL, 0x1EFFA9ECA623A9A9ULL, 0x7BF634600A39EAC4ULL, 
            0x0AB3EBEDC2957FD1ULL, 0x967B503009C4CE55ULL, 0x884F108BF0F5B088ULL, 0x66DA65F0C5CA7D3BULL
        },
        {
            0x09ED9480FCA33E1EULL, 0xD061F7466F6BAB9FULL, 0x3E7B9B60113B8F0AULL, 0x2155B6A256618E62ULL, 
            0x7638F15CC1B99796ULL, 0x9825370B668B6EC3ULL, 0xCE2B7946D983662CULL, 0xCB200441DB66BF83ULL, 
            0xDE5E5283B2CC5C6FULL, 0xA9889761D6955362ULL, 0xC512A6EF603DDA6DULL, 0xB32A9BFB9359818EULL, 
            0x1E6CD645679ADAB3ULL, 0x7D921F061CE956A8ULL, 0x913A120A595697B3ULL, 0x3C67D30DE6D83EECULL, 
            0x7B3BA22648323D3BULL, 0xB4432173D84E651AULL, 0xD6716DF599A4BC38ULL, 0xE6585083417597A8ULL, 
            0x026CBDD76BD8E1DFULL, 0x01BA315C6753B768ULL, 0xE2282D4DC9EC6CEBULL, 0x1D25B8B3C081B6FFULL, 
            0xC3B5DEE652572FB2ULL, 0x20085278BB367F44ULL, 0x37CDEA7DEC3D8A39ULL, 0xB0FEC06BB8512177ULL, 
            0x5193445D43C367D7ULL, 0x2683FD134811BF85ULL, 0xBE35A6DE541DBBEDULL, 0xED7F68FABB9ED525ULL
        },
        {
            0x40F669B4BBFA83E8ULL, 0xCD3D777A832812CFULL, 0x95665CF3698FF4F7ULL, 0xEACB7BF5AE26810FULL, 
            0x0277A3E58C319490ULL, 0xECC00E3489B1890FULL, 0xD831991E67D5F407ULL, 0xA213DF62037D2AA4ULL, 
            0xBB97A6F37D9D8909ULL, 0xD2B71F63D08D170CULL, 0xF7736B2118D87F77ULL, 0x1EF4E87132A271DAULL, 
            0x80B2C3F2471C8132ULL, 0xF9C1AF3D879B70F6ULL, 0xE1D91AB4F1BFC803ULL, 0xCB384C1CDF8C214EULL, 
            0xABA9971DBEF94E5AULL, 0xF0E4316CEED13E6AULL, 0xB343F66192A45030ULL, 0xF933C7D109AA4CE1ULL, 
            0x76AB0150B9DD86B6ULL, 0xAC61766833C78058ULL, 0x39AA9775AF0D2482ULL, 0xFE44A46395AB49DDULL, 
            0xB031A46FF87D27EEULL, 0xB4FE87968206168CULL, 0xB5327D6EF6CFCED6ULL, 0x7E528AED3753FEA1ULL, 
            0x22570BA3880324FEULL, 0x4A4BECA1B6865EDCULL, 0xDA9036AFFB8396FAULL, 0xE0BDEBA614062ED3ULL
        },
        {
            0xE23AFF6730839334ULL, 0xD46D712FF993B79AULL, 0x2AD7B64220F37B73ULL, 0xA7B1D7FBC3EC78FFULL, 
            0x5A4F797D6BE90CC0ULL, 0x93C500EF2CA2115CULL, 0xBF71B60D03B326F0ULL, 0x210571D22C2FB727ULL, 
            0x4C541F0EBA463A8CULL, 0xE8C035DEF0C36BC5ULL, 0x753861FC81C17962ULL, 0xE40E06FC54F3C19AULL, 
            0x4588C92C53B0453DULL, 0xED6A31E9A37E039AULL, 0x3E73B58124F9A97DULL, 0xBDD61A2D57ADA912ULL, 
            0xCD838E51F2922077ULL, 0xCA9DB9E6E1174B69ULL, 0xD118015B1FFDC018ULL, 0x92B1D64F4E23EEB9ULL, 
            0xFC2F7B56B60279F7ULL, 0x171E02377AAF21CDULL, 0x15AAFF5F53845FBBULL, 0x39AA47B36676105BULL, 
            0x413B1086CBE3FC85ULL, 0xB768547A126B0321ULL, 0xD23B44C2A2347EE0ULL, 0x141F31D7046707C4ULL, 
            0x77EE1C9BE2457D83ULL, 0xA25D40B064E0C2F7ULL, 0x46152AF8C173E39FULL, 0xDE32D8F50EFD77E1ULL
        },
        {
            0x650772BFAC0C3ED2ULL, 0xE6C21CA8F621776BULL, 0x459D3B3DF31BB7A3ULL, 0x1E9B3AA2A4A33D94ULL, 
            0x4EA8E77A81BDC4D9ULL, 0x4765538F21B732B2ULL, 0xB43CA74CE7B98C0EULL, 0xB48D73D7C66E79A3ULL, 
            0x48B92DBA47DF71F6ULL, 0x3EAA7292EEC87974ULL, 0x56366591A7485650ULL, 0x30AFE203FEC817D9ULL, 
            0x072E7443D7720EAEULL, 0xBE4CF46E095C20BEULL, 0x8872CCE99F629035ULL, 0xBD28A546CFD54C1CULL, 
            0x37B4EA4A353901D3ULL, 0x1A9B0B382619A363ULL, 0xEA5258903C3CDC57ULL, 0x8D8CB2216B6123FAULL, 
            0x06C657888AEDEDE5ULL, 0x957AE6A4E6FC2BA7ULL, 0x3685C5397AF6B27DULL, 0x970B745A1E27D6F8ULL, 
            0x7E020086761B9859ULL, 0x9DC71CB5BB6B0C33ULL, 0xB2C750E15DE3C3F6ULL, 0x61B0108BB014F4AEULL, 
            0x76DF42772E2F6AAAULL, 0xF2327A69B6AB17EBULL, 0x29A9BD4A597A3897ULL, 0x8DD87D2F1FFAB1E8ULL
        },
        {
            0x3ED2C2482290060CULL, 0x7A702BFAE755E3A3ULL, 0x860A13067F26401CULL, 0x41DA1E447CAAA81AULL, 
            0xF48201AC665D968FULL, 0x751943BA065688C9ULL, 0x0609596E7F91B9A2ULL, 0xC5B78219997D3FE9ULL, 
            0xF4A9B776141BC0D6ULL, 0xEE8F8624AA2FBCCEULL, 0xB758D5A0B5F7A70BULL, 0x45F7A653CF4ED6D2ULL, 
            0xB1BA720F933A49BBULL, 0x0F45A32D07D17DD5ULL, 0xB2611E49FE75AC73ULL, 0x20B4A1DD8DF2A744ULL, 
            0xA8665A89A37F2FECULL, 0x2E9FD5A55D1A1178ULL, 0x989D6F76A04044EAULL, 0x70E5D33B415C0F7AULL, 
            0x9D334AAE98BCC96AULL, 0xC81777D5D8B4F4F5ULL, 0xD0DC39B608DCE13DULL, 0xFE76D4666BA8234BULL, 
            0xE0F303A7732620F0ULL, 0x122D56F8AD139B61ULL, 0xF054E33445E16E00ULL, 0x4E71204CE7903045ULL, 
            0x8B38B35D759FD719ULL, 0xCE1F5C1A1FB6C34BULL, 0x2C301371AC47CCC2ULL, 0xCAB42B55EB9A442EULL
        }
    },
    {
        {
            0xFA3D292AAA6983B0ULL, 0xCADEE4C15C02E66CULL, 0x125A16BC3FC5006AULL, 0xCFC32860B371BD46ULL, 
            0x21C453063AB5FF15ULL, 0x7DAC77CAE44DF13EULL, 0x6CC2134FEA75F8B3ULL, 0x494EDF3E57EC4C43ULL, 
            0x858776BB4BFA87E5ULL, 0x2354F6209976A965ULL, 0x7D00DBA104DEECF4ULL, 0x58F67B49819490A4ULL, 
            0xAEDF1A9B32C74D01ULL, 0x7E0C60CD91C99132ULL, 0x665A22FC2F631D66ULL, 0x68265CA126756B19ULL, 
            0x6C7BE16587890816ULL, 0x33519D8C82B6D24AULL, 0xB9BAC96E1C57749CULL, 0x57AA7074B0CF2DE1ULL, 
            0xD995FFB46C38D035ULL, 0x194099ED64C89753ULL, 0x2DDA762BB6876203ULL, 0x99333001894408E6ULL, 
            0x5AE088088A00A88AULL, 0xC5FA2FA8D0F10698ULL, 0x3717DD12CD2A3CEBULL, 0xFB7F341CFDC1BE3CULL, 
            0x6A8CD3CD31A87182ULL, 0x6E077310B62F0A13ULL, 0xDC889C9646568AFAULL, 0xB2394FC8BF96F290ULL
        },
        {
            0x05F1CA6CB96B9435ULL, 0xC13891D99BABB9B4ULL, 0xC1A082E08AF71B96ULL, 0x8FFF21D8066601C3ULL, 
            0x2E08A679F5D76F64ULL, 0x2FA44D7EC7E14379ULL, 0x7DF7C0B4237D1FB1ULL, 0xAFAD08385F751242ULL, 
            0x9D193469FF22A7BEULL, 0x203AB3C8840F1E55ULL, 0x8F3676D0859E49C2ULL, 0x552547B51153B979ULL, 
            0xFC3A3B2B8DF32B58ULL, 0xD46DD0CE82F6A68EULL, 0x74E0804942B68181ULL, 0xFBFA15CB10A96FD9ULL, 
            0x0E1EF6F87E57928BULL, 0xE1D01013FFBE5925ULL, 0x2801A84924F9CE2FULL, 0x439E033D1CCFB3ABULL, 
            0x4E50EBB19C39EBFFULL, 0xA82B8302DF07357DULL, 0xDD627A665269B721ULL, 0xD6542DF992053C7EULL, 
            0x2BD506F75FD53D43ULL, 0xA1E0B3F3D045DAF5ULL, 0x82DE017FCCF4674EULL, 0x83486D5DF9ACC1F4ULL, 
            0x6D957715E4DBA78AULL, 0x3F8DAE8A1ACA384FULL, 0x500BBDCF21F2E250ULL, 0x22B423EA631BF8ABULL
        },
        {
            0x8BF3D86C0BC6F18EULL, 0xFE137F2682A4A927ULL, 0xB6D10E7BB588D5EBULL, 0x2480C25B397ED01CULL, 
            0xD31B300FC54F345AULL, 0xC0FE8A867FDB823CULL, 0x1842ED8BB6F09498ULL, 0xEFF2696E3F59692BULL, 
            0xF9004F96812892B6ULL, 0x96596745F56F3258ULL, 0x49C92A8D2A245C2BULL, 0xD64C7DCE08EA9D1CULL, 
            0xC250F4367ABE20EAULL, 0x25072AA990B26042ULL, 0x6C313401B990011FULL, 0x92236EA7F8DBCF37ULL, 
            0xD8DB31AF1DAFB3B9ULL, 0x95795F8A2078DE31ULL, 0xBD0ADE9F4AB03811ULL, 0xDE1094B087902353ULL, 
            0x6F395A8E00D1701DULL, 0xB5E02332E2A0313FULL, 0x0EFEBB4D12023003ULL, 0xF922AE042D8766A0ULL, 
            0x99581E4D772E3A85ULL, 0xE38FAFB58F0C076FULL, 0x681D0D50BDD8F284ULL, 0x0599AA5E6D548FBBULL, 
            0x07A68EADB38ECBBEULL, 0xF2BE9E882DE475FDULL, 0xFB4E28281DEF9DE0ULL, 0x56D7BD14F957C6C7ULL
        },
        {
            0x12D7B924926F4652ULL, 0x49EB22B8C77E09BAULL, 0x6D858AA2B81535C5ULL, 0xF7E478FD0A97DF5BULL, 
            0xD4A3EEB1D28D8E00ULL, 0x938EF1A7430B7773ULL, 0xC9B09A6AC3F322F2ULL, 0xA329384DA30B0915ULL, 
            0x45256E5EB8CEEFE3ULL, 0x31A4270322507491ULL, 0x81898E449E847A4BULL, 0x7138ED5869F8B73EULL, 
            0x154367EFF87E9F1EULL, 0x9DAC751F97685EC0ULL, 0xA43842A3A08B0C24ULL, 0xB37F8F2008939F94ULL, 
            0x10D0DF5FABC20704ULL, 0x2D8A8F2F405868C1ULL, 0x0A6809F805002FC6ULL, 0xD983C4AD9AC42767ULL, 
            0xE45EFE1668011624ULL, 0xC129E7CF3063C75BULL, 0x2D9F20B0575AC499ULL, 0xBA41082E5DF0698FULL, 
            0xAF553DB5F01FA191ULL, 0x8BF7AD07265BBB44ULL, 0x2BD2569194F63E55ULL, 0x2BE9829C43DE9DDFULL, 
            0x5AAEEC3CA70B8246ULL, 0x19FF91E343D39965ULL, 0x8CC569E3BC3F40AAULL, 0xC41ED9DF0F417835ULL
        },
        {
            0x0297AEA36700B651ULL, 0xAC787E88950BD812ULL, 0xC4CFB26970FEF3D8ULL, 0x3BA1F36708BFA932ULL, 
            0xB3A9F96B4ADD023BULL, 0x3A229FEA07FB8D33ULL, 0x4D3AFC1617C46B8BULL, 0x8EF8412796EE4D33ULL, 
            0xE7002AFC3ECE5DA7ULL, 0xE63CF9E74884A517ULL, 0x897B881198E8ACF7ULL, 0xAE213A1631223D91ULL, 
            0x78081087AE37C998ULL, 0xCE659B37BD76E576ULL, 0x5417B061614E3F1DULL, 0xDEE9A1C75C731D2EULL, 
            0xB6E3928BF80E3060ULL, 0xCFFACC0D3D445FD5ULL, 0x6E536A16A4353F91ULL, 0x0F860ECB9F04CB0FULL, 
            0x3C2E490826A2AE23ULL, 0x74E8CB1F64576C5DULL, 0xED781F3153C8B7EAULL, 0xBE4DAF07B78D9948ULL, 
            0xBF7FFBF85A05BDD6ULL, 0x157A342E879C040FULL, 0x70FC3B01C08E2DCFULL, 0x0F13DE2EF8B45CBAULL, 
            0x0E3579EA0FE5F2BFULL, 0xEF417F005C27A7E6ULL, 0xEA2AE99357C79E86ULL, 0xECA16E9509630099ULL
        },
        {
            0xDD8662EA38BCDD53ULL, 0x8455BA4DAE976A65ULL, 0xDC2800463D0968D8ULL, 0x274CE9E7D3C0E1B6ULL, 
            0x8D97FB2478337CDCULL, 0x166C149E54352AFBULL, 0x2844F9F1D4CAADADULL, 0x58FB7AB0CC05C341ULL, 
            0xCDC8AAEC6941BA7EULL, 0x55566549E300DCD7ULL, 0xDD6797BBC115B092ULL, 0xE90937017D3400D9ULL, 
            0xF292FB06D87AD2E7ULL, 0xBCA37E2F4107B2F2ULL, 0x707827CE239B8A76ULL, 0x7F31A3B4F7729FACULL, 
            0xC348C8752FEC20B3ULL, 0xAC588B0C8F15F997ULL, 0x893A90C9585F94E5ULL, 0xCA643C9F1E2E38D0ULL, 
            0xE3F3DE2779F00C29ULL, 0x30B4CE6AECDEEBE0ULL, 0xD4EA1EC1D6E7A44EULL, 0x2BBCBEB7D06DCF1AULL, 
            0x1F1E99E929497B95ULL, 0x32C2367195419CB2ULL, 0xA29C2390ACF467A2ULL, 0x185C1E537317EE4CULL, 
            0xB76824659661915EULL, 0x6204D61B50B3D7EBULL, 0x3F6D191C11C2291AULL, 0x63EE467600C9B6ABULL
        }
    }
};

const TwistDomainConstants TwistExpander_Achernar::kKeySpawnAConstants = {
    0x43253C3B64281EB0ULL,
    0xEC8722FB6F2229FBULL,
    0x364B8F645726DDE9ULL,
    0x43253C3B64281EB0ULL,
    0xEC8722FB6F2229FBULL,
    0x364B8F645726DDE9ULL,
    0x1BA5B3E5911E7908ULL,
    0x5F86BD343D8CEF95ULL,
    0x03,
    0x77,
    0x37,
    0x6D,
    0x72,
    0x08,
    0x8A,
    0x49
};

const TwistDomainSaltSet TwistExpander_Achernar::kKeySpawnBSalts = {
    {
        {
            0x04B26C48452D59D3ULL, 0x220A909C642A7CE6ULL, 0x1B69D1556A92CE7DULL, 0x191E56447C8FDFC5ULL, 
            0x44FEBA5E15EDE373ULL, 0xEAA9A72C827638A1ULL, 0xC57E29DA3E1BFA12ULL, 0x6E291C440558F689ULL, 
            0x59A08D914E1DBCB0ULL, 0x4DE8D6D765A01CFFULL, 0xC3ED4D02826B8702ULL, 0x7A7CA17BEC97E396ULL, 
            0x94202DCEBC9676F6ULL, 0xE3E5462ECCEC05EEULL, 0x6CB5889C0035D2D0ULL, 0x8EF35C99AA6DA4AAULL, 
            0x39F3284C1D0623D6ULL, 0x6F839825DDB0A50DULL, 0xA46F692E632D0712ULL, 0x8989267828436051ULL, 
            0x8A3A46E43A224E79ULL, 0xFEBD9DDD68AB530FULL, 0x8C88F1A3E8F3252CULL, 0x8F405E7D257E7B16ULL, 
            0xCCCD6298599A49C2ULL, 0xFEBC9DDC5F038318ULL, 0x7144E1AD093A35D9ULL, 0x840256DE8BC52F43ULL, 
            0xB0D7500A39E3845DULL, 0xDFCAF42B4045CBD8ULL, 0x15083E2732B5245EULL, 0x7CE75A6D7CC98412ULL
        },
        {
            0x53DF0DDDA0C4E9C3ULL, 0x9E2DAEE9F79E656EULL, 0x283C06A7DD3BD45DULL, 0xB7BCA083D4FFF59EULL, 
            0xA9FEE333F834D197ULL, 0x900F7E8EA079C22DULL, 0xD8E3949D2D2FABAEULL, 0xC8C3552FD365EE6EULL, 
            0x1154859984F916D0ULL, 0x83B167C8C69788F9ULL, 0x4C8B3562EE3E3941ULL, 0x3F5AC03ECD9CC1BDULL, 
            0xB62790CF2163F8A2ULL, 0x4D3EDFE1E176A82DULL, 0x312A7EEB1AA88BA1ULL, 0xCE99880D813A929BULL, 
            0x4FF2F34C7F76E660ULL, 0x44728C711D6C4C49ULL, 0x8F05A2C299341E21ULL, 0xA05FA955D433C2A8ULL, 
            0x48B1398FE2EC339DULL, 0x69B6CC1276CED49DULL, 0x37F3BDDB323E3425ULL, 0xAFC0BF64FB9554E3ULL, 
            0x855F11A000E529D2ULL, 0xC4F347B039FB53D6ULL, 0xEC7DC9C0EBE3BDEBULL, 0x6CBD735E876371DBULL, 
            0xBBB9A8C1F6BB886AULL, 0xF1EA5143B22B802FULL, 0x784F08C759B0ABD0ULL, 0x687672F4E5FE949DULL
        },
        {
            0x7961C0886CF9BF41ULL, 0xA211CB6ED04C2AA2ULL, 0x0D938FE51B8CFAF7ULL, 0x4DA7945DB2A0F270ULL, 
            0xD0E7A93F444CA60CULL, 0x2275211AE84B5C58ULL, 0x833413E62E5F9EABULL, 0xD78D97D2FCCE43DAULL, 
            0xAD2CE248121B481EULL, 0x900B0A293D295B3DULL, 0xED4822B63C602ED9ULL, 0xA2D5B41B7988AFAAULL, 
            0x08FA705D6C43459EULL, 0x4B7AE2A0209C3440ULL, 0x903D3DFE010565C2ULL, 0x2BC37B4C5947FBD7ULL, 
            0x3710E922C385D1DCULL, 0x48FCB6B2FB178637ULL, 0x52C8FF953A525125ULL, 0xFDEE3DC9AC46B638ULL, 
            0x1589218369ABF639ULL, 0xAAC564934F75D8DBULL, 0xEE9ED50B889CF920ULL, 0x7F93B6928555C0D9ULL, 
            0xA5FC84A167AC5504ULL, 0xFA516DDDECB3B20EULL, 0x718698B0EA9B0F41ULL, 0x4466165F79A402EFULL, 
            0xF8B764BCA18625DBULL, 0xC6B08DCFEA01136FULL, 0x0C5BFF82451CD612ULL, 0xC1DFCFD01F67AF86ULL
        },
        {
            0x426F4FCE39EB403EULL, 0x774B925BD6990362ULL, 0x4E8382C39F271DA8ULL, 0xE8D0571C71DBB057ULL, 
            0xE386A37F2AF25399ULL, 0xFB1F678CD3000048ULL, 0x88C417192419061FULL, 0x7C7BEA454D03959DULL, 
            0x6DD8705DA65EA3D8ULL, 0x20E22321467130E1ULL, 0x59C53D54CACBB7B6ULL, 0x9ACD4C7430728203ULL, 
            0xFDD22410646F944DULL, 0x6918AFDF21B55AA5ULL, 0x0AE1CB9E116CC21BULL, 0xBC72A714C29ACBAAULL, 
            0xF2AC5EADF8E8BC4CULL, 0x215C6687BF08424AULL, 0x67B1DAA8E7420357ULL, 0x1C7C4ABF88556B78ULL, 
            0x84BD2998B721F3BFULL, 0x0F0530825F8DFCC3ULL, 0x8125472A06F09B22ULL, 0x2223FD1EAF75E075ULL, 
            0xEFB6F5B02B2F34EDULL, 0x77FC7D5ABEBD879AULL, 0xE36F5ED2E8B12086ULL, 0xD8F5520A92A8312EULL, 
            0x4002917A58287ECDULL, 0x339871291FEC3DA4ULL, 0xA37D6F79C8C09A5AULL, 0xA5A358C02C1280D0ULL
        },
        {
            0x27647225B492DB7FULL, 0x220946904CA03061ULL, 0x87A93786C8FAFCFDULL, 0x2846B2A9562AA898ULL, 
            0x8FC8D228B8B89954ULL, 0x1F9C7F89458F8C8DULL, 0xD452E335C27EFB4EULL, 0x97EC9D607B38BEA6ULL, 
            0xEA1DF7CB47526139ULL, 0x0F11FD27DD145D38ULL, 0xECD19C688204E07CULL, 0xA57B567D08404907ULL, 
            0xB3D76D2D2990DC02ULL, 0x9639321923297676ULL, 0xC4B2620B78860ABDULL, 0xE81BCE74992E53E2ULL, 
            0x5F66366CF7926E23ULL, 0xBD843D54D4448762ULL, 0x15683C9BB01A799BULL, 0xC53C05E6C22C396AULL, 
            0x6F77F9D1ED7945D3ULL, 0xC11B0ED5F78C2D08ULL, 0x3D83C6BEA56161B9ULL, 0x69B102820480CD80ULL, 
            0x2C23C96684051C21ULL, 0x3031B54B70C9B05AULL, 0x29581BE18A234CBCULL, 0x6789B43BD6CE2EFFULL, 
            0x438349194BCF085CULL, 0x6C3655D05DF480A9ULL, 0x82A1E7B4D8267C8EULL, 0x34E2F83D0A1FA274ULL
        },
        {
            0x881921602E54E1D9ULL, 0xA8AF4FA17AA6379FULL, 0xCAABDBABAE891940ULL, 0x5923B8A2528281C3ULL, 
            0x54019E8DBED3A146ULL, 0x89D4862002EA2095ULL, 0x39BFBFE6D4E4A234ULL, 0xB2849DB92168E3DEULL, 
            0x83C45CFB73189775ULL, 0xD1C6D9498FC740FDULL, 0x8E76257E8D46885CULL, 0x2F80227ED9A72A5BULL, 
            0x89EC09810F3D3173ULL, 0xA3F3F81CAD30A708ULL, 0x9484EA36328C2F4AULL, 0x1FA4B6C1123EDC28ULL, 
            0x8A2A918D0277C1D9ULL, 0xFDE26AEC272E22FCULL, 0x939433B86C533271ULL, 0x5344BEF222E2CFE3ULL, 
            0x9F442556E0D2468FULL, 0x824A8E690D39298AULL, 0xDF04CF491D97AF65ULL, 0x628A26654FD28BB8ULL, 
            0x84228D178D61AA34ULL, 0xE2183D6F77DC93D1ULL, 0x730EB8A717889B83ULL, 0x765B95856F4ABDF5ULL, 
            0x7B9EDAB9482AAB1CULL, 0x915B75B5F538CCB4ULL, 0xDEBE441C4D148E17ULL, 0x48DD95413776A1F3ULL
        }
    },
    {
        {
            0xA63848055075E67FULL, 0x45141B16AD3B87E6ULL, 0x8A8D02F6E015E41BULL, 0x3CBAAB1834D75970ULL, 
            0x141303743E30A1DDULL, 0x0D7229462E836202ULL, 0x48FF2A7D8DF25918ULL, 0x4D7048A3E7455170ULL, 
            0x266019AE53FC2CB5ULL, 0x452ECE3EF03B01EFULL, 0x97C30297A6B9A09EULL, 0x8665AC613DBEB6DCULL, 
            0x5743EB05DA1C40CFULL, 0x5F03C67EC7C2E1E3ULL, 0x9E19F4C98A44498AULL, 0x0032E975F0E5B66EULL, 
            0x22E22E2B7E90B840ULL, 0x8A087142D39B2138ULL, 0x8C8958A48A05C8FAULL, 0x99B1B8529701F703ULL, 
            0xFD34E54D68EC3C54ULL, 0x848F944A4B5F18A3ULL, 0x7A5FB5F11536526AULL, 0x21237C3A99836560ULL, 
            0x14171AFAAF54A3D9ULL, 0x30ACE1C18222DF56ULL, 0xFC3E09A13CFECE2EULL, 0x1A0DDEC578598C3FULL, 
            0xC72BE6CC45B43765ULL, 0x3E0566B269C247EEULL, 0xF81A3F6EFFC86FDCULL, 0x927A9650A81685F1ULL
        },
        {
            0x842804EDE2BCC369ULL, 0x334B234358DBC36CULL, 0x1DDDE375F028367AULL, 0x72EC76293468C5A9ULL, 
            0xD44F4F75494B0106ULL, 0x33DB338E0904B477ULL, 0x6CE7A3923A49BCE8ULL, 0xE952B321E0D0A274ULL, 
            0x5385C1B017B4E689ULL, 0x02251D50B19993CBULL, 0x4ACB6B54EEB97675ULL, 0xEFB127B6C41C6BD7ULL, 
            0x40BEAE7174885B08ULL, 0x60013E05244B1B96ULL, 0xB978EDC08543F81DULL, 0xF85A614866D51265ULL, 
            0x1A8D40E0BD328B3DULL, 0x7E618746D2380890ULL, 0x981C3F30C8F70607ULL, 0xE2395C8C199471E5ULL, 
            0xFDD6D6DAD1BFE7AFULL, 0x4B182CBC20F7E1F0ULL, 0x3ABAE9C3595C38E2ULL, 0xBBF3F38E1C561A5EULL, 
            0xF835ACF7DDD666C4ULL, 0xDCEC4AC5FC0ACDECULL, 0xC3D85B185A49DB0AULL, 0x75AEAD72F5429C62ULL, 
            0x5741FC36C8956FB4ULL, 0xBF84B0D8A4CB3379ULL, 0xF7B3FEB4AEFDEDD9ULL, 0x6A2851C14118662CULL
        },
        {
            0x8D95EC1ECA22E644ULL, 0x4535559569655C8AULL, 0x9BA4D4ED71E768C5ULL, 0x7ACF2044E5C76D10ULL, 
            0x086FA3E6992F32B0ULL, 0xF9369041892F17F0ULL, 0x56C2C800820D6851ULL, 0xF2422D58427910EFULL, 
            0x2CBC40309BBD3EE4ULL, 0x135993F064C8E2B3ULL, 0xB98DD0A936B87BDAULL, 0x1A21EA13C6BE5B1AULL, 
            0x8B725922932C3DA0ULL, 0xFD102B8D02075303ULL, 0x6689B788E240EB33ULL, 0xBFBB7523076139EDULL, 
            0x63D946EE12C3ADC4ULL, 0x179DAEA1BFA3910CULL, 0x554B57E5DCFBED1EULL, 0xC7FCDFCCDC7B85DBULL, 
            0x31277FDABA7AD20CULL, 0x5965431D295FC3BFULL, 0x55DBBEFCAB2A3788ULL, 0xDE758B7FD6E58E52ULL, 
            0xDB8D3D3E1AE9CCB2ULL, 0xA8D3A6BD868682A6ULL, 0x40A19F29B38C92ECULL, 0x0CC66B768C58F5C7ULL, 
            0xE63A036846751483ULL, 0xD696B869393E3B83ULL, 0x5BC57211385D08E2ULL, 0x4525DD0B9E6ABB94ULL
        },
        {
            0x7A167E01F5A24084ULL, 0xDC62A72113E51648ULL, 0xD434252E6DE28B4BULL, 0x4C9C6B51B0E4DA56ULL, 
            0x7B56AA5328D07EECULL, 0x48DC143B8B131933ULL, 0xD8F8FC14ED7D93CFULL, 0x697211CA079EFDB0ULL, 
            0x62E758BD40179289ULL, 0x45AE4D0971EED570ULL, 0xB38FD679D493D6FDULL, 0x00C5E3B69CE86393ULL, 
            0x1696D0AFFBADF6C2ULL, 0x91354F5A30A3996DULL, 0xE99524B69EB53695ULL, 0xA30067ECD23D4A75ULL, 
            0xE301674DEC2CE79DULL, 0x246DA4BB5578D970ULL, 0xAB49EFB717B0FA77ULL, 0xCC6D885C5741BC84ULL, 
            0xC09CFEA528FB7D77ULL, 0xBB7991DEE622CDA2ULL, 0x405C884ED882216BULL, 0xA1560D5CCE9E23EDULL, 
            0xF433836D071DF6F1ULL, 0x7787DB1AAA977EE4ULL, 0x1A835BDFFAF81C02ULL, 0x1EA40B06D79CAC2CULL, 
            0xFAC40FD10D5FDD4EULL, 0xEA58202887C9D823ULL, 0x575246DC72B67288ULL, 0xF129161842EB601DULL
        },
        {
            0xCCEC441850AF8A65ULL, 0x8450507CF94B0A4DULL, 0xCEAAF683AB0ED225ULL, 0x1F6B879449106A77ULL, 
            0x9ACBDAF20F6695C2ULL, 0xF941BEAD9C1134D3ULL, 0xB68E9C4E30C32727ULL, 0xCA45FBD34787C65CULL, 
            0x03592C0B0BABDC6FULL, 0x7BC40ED0C32E296BULL, 0xABE78C41EE8A8951ULL, 0x19E0DB29AF109D54ULL, 
            0x250C67485B831A59ULL, 0xB0DDFF9CDD062209ULL, 0x48675DC1B6A4B709ULL, 0xCA02ED0A9A306F4BULL, 
            0xD4BA33E72E4C1383ULL, 0xF384AE7DE1A00C47ULL, 0x5F7A201A6BC0282CULL, 0xFEAED5395266A5C7ULL, 
            0xC2B4E8590C710B26ULL, 0x506309A82C06E362ULL, 0x87C36C966649B17EULL, 0x0CD45040532FA150ULL, 
            0x894E7F55A21CEE04ULL, 0x37421C1A113AAD6EULL, 0x828749EF3C784F11ULL, 0x8C23A26688ACF9D3ULL, 
            0x9722E71E89D64A2BULL, 0x1A45D71F595A0FEAULL, 0x51387BD43AC579D5ULL, 0xF634BCD91FD6E1B0ULL
        },
        {
            0x127607988542023AULL, 0xF99B1648DF43C9A2ULL, 0xC797A2F2A40F7533ULL, 0x1E6A63E41663F0CCULL, 
            0x1958992482EA851AULL, 0x670FE3371A5B6CD2ULL, 0x1AE1165A7F7A9CBBULL, 0x20B9DB35AE8C7CCEULL, 
            0x2CD915A9D53CFD14ULL, 0x7C5EEED6F0D56CB0ULL, 0xFFC4A33A25A0D150ULL, 0xE2A5BFB7F44EFCA9ULL, 
            0xDBF0F71C8106A475ULL, 0x2EE30008FF343DB7ULL, 0xE3A5A281C50C5586ULL, 0xCBA9F552BFA66234ULL, 
            0x97587D562457E450ULL, 0x636AD863D53243EFULL, 0x24F8777D2DA37FD6ULL, 0x4320CB885E353F73ULL, 
            0x3F22D50743933DCAULL, 0x8CDF3E6BD58CD7B3ULL, 0x9C45BAB6A098FB6FULL, 0x7B5D0AAC5094037DULL, 
            0x5BD202BD058830D5ULL, 0x5897EC63E424C4B6ULL, 0xC5F381DB2C351715ULL, 0x35B932827A2EA108ULL, 
            0x1978B10D90CA76A0ULL, 0x761B2624FC12641CULL, 0x8FBC68E3F0076888ULL, 0xE1E5EF1F926F4F7AULL
        }
    },
    {
        {
            0xDF2B6F4A2B380BD1ULL, 0x6A4157E092BC5DD6ULL, 0xA7BEC05A4D32DBB0ULL, 0xB0A7254D7F86F7DCULL, 
            0xC090EA52571CEA44ULL, 0x8E848177F89B3545ULL, 0xE37F5918F848D273ULL, 0xEAD1AD9BA4E2368BULL, 
            0x6887D4EE75945E3CULL, 0xAD646F1E65F0C2F0ULL, 0xF8BFA1F19B4475A0ULL, 0x4A0666C52AF67B32ULL, 
            0x0EBCA11BB968ADC3ULL, 0x0E1D455B79B427CDULL, 0xA4510AA1CB3C839CULL, 0x4A51EEAD28693370ULL, 
            0x47DC72B121A01741ULL, 0x4025DFF602825F0AULL, 0x76C27A052185AC26ULL, 0x60BF7BAC59E7FA0EULL, 
            0x0C0E7C466C0DD943ULL, 0x7C3AC6FEC01931D5ULL, 0x0131A51A823C39ACULL, 0x7002DD9E7AF33E06ULL, 
            0xD28C3B20B13D1409ULL, 0xBD9F554C3981DED3ULL, 0xC68A2291FF7D765BULL, 0x1468CB5AE60996ABULL, 
            0xAE726AEBF46C474FULL, 0x83FDE82809D55D17ULL, 0x8588D376B30DBDCAULL, 0x31BE444FD54D50D4ULL
        },
        {
            0x05CA7BE30736EFEAULL, 0xFD16B6BF37C53A7DULL, 0x39DAABAD36E24ECAULL, 0x481CCA8C082F9CDFULL, 
            0x1EACAC5962081B1FULL, 0x40B6917B106DA29CULL, 0x5B535758D5D7EF58ULL, 0x2BD045F59EE12E59ULL, 
            0x4D72B00D40E037FBULL, 0xFD3FA52B024D9266ULL, 0xAB35B896D7AC1D12ULL, 0x4667136BEF66022BULL, 
            0x3502BC203713A5ECULL, 0x05AC4BE2470DE4B0ULL, 0x1DCBC31C7D6CA060ULL, 0x5C8A72B1054BB0D2ULL, 
            0x0809281331F4F9ADULL, 0xBB7AAFABF9847A09ULL, 0x7B720F6265A16127ULL, 0x6385976763EA5396ULL, 
            0x49151CFE9BDF8859ULL, 0x04D089DDE7F75887ULL, 0xD4F8A49D7147BA72ULL, 0xE9F033D41AF18EC9ULL, 
            0x2FB02F553B009DAFULL, 0x7DA4EB2249FFCA8FULL, 0x7C97FAA827FAAA2AULL, 0x7B5171281E8957A0ULL, 
            0x5E27564C47CAE2FCULL, 0xB347F051593978FDULL, 0xF8EA1946EBE5C6B1ULL, 0x1D93E9792B6B5BACULL
        },
        {
            0xC9A53117C0C9E2EDULL, 0x629B099AC9D14C13ULL, 0xA85555EF10E67DFAULL, 0x2028574F8E0CE341ULL, 
            0x61646F9D8135C8A2ULL, 0x88A20F808B13293EULL, 0x16D515AF93F35FF5ULL, 0xB3F2C1BCE924E487ULL, 
            0x7903C0832A9F1C53ULL, 0x96ED8DDF8C47F5AAULL, 0xDDCD99999C5C905AULL, 0x957DAE8C7C5FA3E8ULL, 
            0x72632834ACF2E437ULL, 0xA90F2D65269809E4ULL, 0x8D73533356FE3868ULL, 0x496DF57F258EB27EULL, 
            0xDF9DC4D241226654ULL, 0x0DC43ED308E7F14BULL, 0x7543E03A2B3B8FBBULL, 0xEE9E5AA4D5317E69ULL, 
            0x2DA49B9B442B4905ULL, 0x9BECC8BB4C2FD5EDULL, 0x10E290F07564777EULL, 0x03CEC5EB1D8D5B5BULL, 
            0x94F4075344B6FF80ULL, 0xE4EBE879D01AE9E1ULL, 0x5FFD89A6E0E6CB5FULL, 0x14D8243E6F6B9A5BULL, 
            0xDAADA278C7997FE1ULL, 0x7896C1984C072C99ULL, 0xE409D2BC601FB5DAULL, 0x768B7DFB6F9F0692ULL
        },
        {
            0x341B2907112EFE69ULL, 0x002C6F3BDE6E1AA2ULL, 0xAA245FF646C859BEULL, 0x00875E029C365B5AULL, 
            0x54F84AC08476BF18ULL, 0x28BF503B1847DF21ULL, 0xA4A58C4D01DB8C16ULL, 0xE4027F0986B35B58ULL, 
            0xCAA2DEBC934B0C12ULL, 0x0B63A09110855708ULL, 0xE12B64D286BC7D7DULL, 0x62D14780F92E266BULL, 
            0xC7CDBDEADFCB4DADULL, 0x2032878811C7D48FULL, 0xD65EE023A89DD96FULL, 0xDB8B28083CF8DA80ULL, 
            0xE808B38A187289D5ULL, 0x266C59EAF9F783F8ULL, 0x5DF9D956F7800E09ULL, 0x321ADBE975B094DFULL, 
            0x63F575A7A1CCDEB3ULL, 0x868477C1000DE751ULL, 0x07060623F14970D9ULL, 0x8B05D9DA14598DA6ULL, 
            0x3B94E8F822670678ULL, 0x3D818F33F91D04A5ULL, 0xEE6A4E8051961669ULL, 0x96057CF0A15AB2EBULL, 
            0x3C1A000DFE39581DULL, 0x7A5B280691388405ULL, 0x6AE5FDE772BB0691ULL, 0x699811D0AC794549ULL
        },
        {
            0x1B9607C8F0D49080ULL, 0x309738C5CAF5EAE5ULL, 0x67D1A76C6F4EED65ULL, 0xF6F53D7795C8F579ULL, 
            0x54DBF53F44553779ULL, 0xF1DBB100DB72BDBEULL, 0xB09FBB7F4BDAB46CULL, 0xC01C359A11242E9AULL, 
            0x04A5EFE4E7603FF4ULL, 0x92E4CD46C69E57B7ULL, 0xC644C4D5EF16FA9BULL, 0x3ED6A0BF43DE9ACFULL, 
            0x50823F92D11F6EF0ULL, 0xFCD89F0E9F5EE374ULL, 0x6658D1B35597F13BULL, 0xAE166E207DB216E0ULL, 
            0x70DCDA38AD9B60AFULL, 0xA54BEF7AEA814592ULL, 0xBC44A341EAE6957FULL, 0x710BAAF765CC1590ULL, 
            0x558F8CA629297D4EULL, 0x1AA8DA982947B1D9ULL, 0x4233F9DF1F6ED1E8ULL, 0x5F59DA26A1D5ACAFULL, 
            0xC985DEA4F1FD8CD1ULL, 0x943CF4A092EC1AE7ULL, 0x88545613DCB7FCB5ULL, 0x096EDDD7924A9279ULL, 
            0xE5BF96BBEA6704E0ULL, 0x0AB75B1EDBCC4ABBULL, 0xF2D5264C867118B6ULL, 0x63D7D0BCBE0473C9ULL
        },
        {
            0x11F089CDC7F29016ULL, 0xA9237E22F37EE936ULL, 0x3C8E2419E2A5EF33ULL, 0x5931B4DF4851A79BULL, 
            0x3B48907955145FCEULL, 0x206ED2D1721F9E77ULL, 0x6E403CB88D3EBDBDULL, 0x31DAF096AE9647B9ULL, 
            0xACE6EC16DF9AFBA4ULL, 0xF80CF5A49E1A1C99ULL, 0x629E82E5AF3F7DADULL, 0xDA51127721897E4BULL, 
            0xFB2E01B518431009ULL, 0xC973DB0001905D88ULL, 0xE62EFD166DA46FF5ULL, 0x3B516D074383B9DBULL, 
            0x523688B90ECDEA05ULL, 0x7105602B3BB773A7ULL, 0x352A0B07C25E2695ULL, 0x3E29C16E943A86AEULL, 
            0x3E8B546B71ABD324ULL, 0x60A5AD1B382033ACULL, 0xA3730C6FA7B3FC18ULL, 0x824A0C5914CDD700ULL, 
            0x403989346089F903ULL, 0xAF2DD906DE4B1E6FULL, 0xE2CF805AC530FF36ULL, 0x425044866189BE79ULL, 
            0x862F2180FC3B0F7BULL, 0xAC24FBB2C0688BDCULL, 0x509BFBC0EE2E7AD1ULL, 0x207BDFAEFE18D8DAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Achernar::kKeySpawnBConstants = {
    0x9D4FD5D570967CABULL,
    0x555117CE4E81ABEBULL,
    0x1458299B013A0D88ULL,
    0x9D4FD5D570967CABULL,
    0x555117CE4E81ABEBULL,
    0x1458299B013A0D88ULL,
    0x1CA2F25D6DECF780ULL,
    0xC3F00E7115248D95ULL,
    0xE4,
    0xAC,
    0xD4,
    0x2E,
    0x9C,
    0x4C,
    0x39,
    0x3B
};

const TwistDomainSaltSet TwistExpander_Achernar::kSeedSalts = {
    {
        {
            0xEB302789D304C65EULL, 0xABCEE0E35C52F068ULL, 0x45EDF6CF22907464ULL, 0x138853C24F50AA7CULL, 
            0xFE4507D8E06773D4ULL, 0x9B8EC06023C3E914ULL, 0x776D7C16885D4200ULL, 0xF2EE07504906DC2BULL, 
            0x687CD29E168DCED6ULL, 0x02478975C0460EB2ULL, 0xD2DBB7F8477C3B35ULL, 0x5B7B82EE1C2799ABULL, 
            0x9B21A16B8AA5F11DULL, 0xF4DF7FA36F2278D7ULL, 0x592A8EF164284285ULL, 0xA788138129A1872CULL, 
            0xC4A36C7992137E4EULL, 0x9DE3866A6B7A2B7FULL, 0xCD23EF9823BA106CULL, 0x248CE8E2E0499A21ULL, 
            0x4B07CCE474A1EF5DULL, 0x32FBDA9B22040C8EULL, 0xF735C5419A9ABFD3ULL, 0x0A8A448F06A66B5AULL, 
            0x506BE6C7ECBE5B26ULL, 0xBF1263A33B6F028AULL, 0xAD7B138EF4802525ULL, 0x9F4D319DD4DC7100ULL, 
            0xDDC1A4AD808868E5ULL, 0xD2829BF8D34EC31EULL, 0xDF626FBA80900E7EULL, 0x245B382E99F7F1C8ULL
        },
        {
            0xDCF242DC27F3A170ULL, 0xEAB277041C900787ULL, 0x094FAFC869C06585ULL, 0x539968254F6FDDFAULL, 
            0x1608B29721ECC801ULL, 0x3F7511E502A342AAULL, 0x19D5C868021D7CA8ULL, 0xC92A4FF5BAFDFBC2ULL, 
            0x77008340464F68D9ULL, 0x310F06EF90A37837ULL, 0x11E382DEA20E5A98ULL, 0x3995B7E1589E1C08ULL, 
            0x94968135199A96D9ULL, 0x88140AA11A4E5D89ULL, 0x7D907CD2F118AED1ULL, 0x4ABCC1F6F8BEA7C0ULL, 
            0xA8FF3D38B64C6E1CULL, 0x10E6E9B81CE83E8BULL, 0x46439F5F52D2133FULL, 0xF6E49B277B2C921EULL, 
            0x8F8E8FCAE9589D67ULL, 0x8CBED391410B2DFDULL, 0x20B4BB288F0E336FULL, 0x5850336E78AA3E07ULL, 
            0x6E089920F2F5ED1DULL, 0x3000DA0D5D3789D1ULL, 0xDE227928CC44DF7FULL, 0xD6FC54C516B8FFECULL, 
            0x4894DC98E47FCEC2ULL, 0x26AAAEF5DF3D40B1ULL, 0xB32C59DC9EBB7A12ULL, 0x8C3FAD8BE9885407ULL
        },
        {
            0x943C30BB7306B5A9ULL, 0x390DF3D387187674ULL, 0x7087AAB6FF73D330ULL, 0x6BA8B8062BD799B0ULL, 
            0x22829E3169E7C8E6ULL, 0x80135EF6D68FDBBDULL, 0x3D6B74B14A565CE1ULL, 0x06BAF1E078689A2CULL, 
            0x73DC08CE7A57E2EBULL, 0x6AFAA80EDCE4B472ULL, 0xE16E78996E357E62ULL, 0x75C913E080D942A4ULL, 
            0x834769E7C574D146ULL, 0x7DA53D1F4F999772ULL, 0x2C595E4C8C3AD9CEULL, 0x087EC2880910419AULL, 
            0xAA3DAD4C3A14737CULL, 0x2D8990FD23AAD673ULL, 0xEE9C8296039EB2BEULL, 0x9F2696ED8A14FA23ULL, 
            0xE256E95DC0ACA66CULL, 0x2B9B54F346BCE4C1ULL, 0xCE4742CBF9E5ABE2ULL, 0xB2489317F6F15B3EULL, 
            0x04E3EE442C035FEDULL, 0x95C2E118FCDEF0BEULL, 0x88D1244A3BB26577ULL, 0xE9902569394F9429ULL, 
            0x2DF788CE59AAC4D3ULL, 0xBE83F0B2FB2F7162ULL, 0xCC571E8F306D886DULL, 0x7E4BE860327ED7A2ULL
        },
        {
            0x3D49CC1E0833AE07ULL, 0x5AB40E69B928960FULL, 0x6F80A307124DA930ULL, 0xE95AE070ADC624D3ULL, 
            0x606C4C1A2FE1FC34ULL, 0x116DAEEC16178B9FULL, 0xB3020F1B2612B6A8ULL, 0xBDFB08D918DB72D3ULL, 
            0xD4F5447F1589F76EULL, 0x4013B164AFE95DECULL, 0xF1743EAA4462A6D3ULL, 0xDBDB9C7354CBFF7EULL, 
            0xCBE54B62302C873AULL, 0x9434E90811C4036FULL, 0xEFD250D810FCEFEAULL, 0x49EC33288E096BF5ULL, 
            0xBF713F1C3023141DULL, 0xA29336A3E33C6517ULL, 0xDBBC348579C9B75DULL, 0x9221219AA5B60744ULL, 
            0xFF01B761DC4A6F4DULL, 0x7F998CC1B5D8A0E2ULL, 0x81D744272C7BB971ULL, 0xF6B77F7C72AA2CCCULL, 
            0xB95B8DEA9EDF02FEULL, 0x4823F469B9941E20ULL, 0xABE823C7BF2EA239ULL, 0x1AAEE1050EA1959EULL, 
            0x45792F173F8F0E20ULL, 0x2003307F89075E74ULL, 0x6FFC7F96BE9CC557ULL, 0xD07C4F466A82A5B0ULL
        },
        {
            0x5C69DAC5BFE31958ULL, 0x67794CBCB99188F3ULL, 0xF573857295C65824ULL, 0x0D41BF647B05AD1BULL, 
            0xCE2994553BA051DBULL, 0x90D62457592EC200ULL, 0x972ED21E5796034EULL, 0x260BA41BE1955615ULL, 
            0x3C3EF195EEF7292DULL, 0xF256569FC3C04A67ULL, 0x48F1107C3BEAFC0EULL, 0x0FD8571D992A1FE3ULL, 
            0xDE08224E24345D8AULL, 0xDC33191C0147C4D6ULL, 0x5D6673B52A648A97ULL, 0xA47A41EAF9FE2CDFULL, 
            0xEBAA93152C42F017ULL, 0x6CCB291625D59F24ULL, 0xBD86189765E9666AULL, 0xA0034F038F450433ULL, 
            0x51C6516F17B62EC2ULL, 0xEE63E87FC32A600DULL, 0x1F2ECF034FE46497ULL, 0x545A80863BA8D1C6ULL, 
            0x00247AA51EDA16E0ULL, 0x68D0FBC32EFA4CD6ULL, 0xDAF5CF2BF3DE0EACULL, 0x77CDBE632B57DF18ULL, 
            0x84D61B9E1D6F4E6FULL, 0x5524AD92F052610EULL, 0x8543FB1E5543829CULL, 0xC3DDAF1EE53760C2ULL
        },
        {
            0x46BA7414534003DFULL, 0x14BB8B1EF84EF900ULL, 0x6D4FC28355C294C4ULL, 0xAEC735AC7BA86B11ULL, 
            0xF7FE25B5C695256AULL, 0x5F8A98969038088EULL, 0x8B8214CD23991837ULL, 0x6129B5244EE2D89CULL, 
            0x22C1BA2BCDF3D8E9ULL, 0x0C28057631122409ULL, 0x5C50225D5F355574ULL, 0x11CF150924BC1692ULL, 
            0xB840A4DD4184D253ULL, 0xE3ECAE9B1A4176B3ULL, 0x5359310940B6276EULL, 0x0184E55B13A7F141ULL, 
            0x0CA80425D9532BC6ULL, 0x0EE4B7AE4F81EB64ULL, 0xC27CB8F65D35D9B2ULL, 0xFC0F78ED282744F9ULL, 
            0x64568D2D3B637FF3ULL, 0x6A5B163700FFCF10ULL, 0x416865B671F04D94ULL, 0x74879183F329CEB8ULL, 
            0xB2E0F0D0B36AD392ULL, 0x6B592CE059262E21ULL, 0x86F1D14BD15FEB9FULL, 0x819147F25C91792BULL, 
            0x4B4E98055D66608FULL, 0xBFDB63DB180CF0D7ULL, 0x05988797F1A35AD5ULL, 0x396509BD8A86A0D3ULL
        }
    },
    {
        {
            0xD4C7F1AF71D5D2F4ULL, 0xFE5C9028D581CEA9ULL, 0x40AE2240A1A22270ULL, 0x52F2401C986BE599ULL, 
            0x02E845D906BDFFC7ULL, 0x371DBD02850B0058ULL, 0x3FAD91C2766E383CULL, 0xB1781CBBC13B7284ULL, 
            0x9386450DB1A4274DULL, 0xA0B79D72E7608DE4ULL, 0x3A0E7AE835E5132CULL, 0xE123352429ADC04EULL, 
            0xE32017154B26E58AULL, 0xD22C018D50809293ULL, 0x6561DD67E4EB7A4EULL, 0xFC2F8CBA877B9022ULL, 
            0xEC0DFBD838C07335ULL, 0x1F56EA93CDC49813ULL, 0xFC2256B0FA2DFD6BULL, 0x0BBD865327FE7E93ULL, 
            0xA5D7A63B29299478ULL, 0x5C57791BFCC081B3ULL, 0xA959C8A5F458D28CULL, 0xBD1A9F1470A62564ULL, 
            0x5637030DB0BE259FULL, 0xE29157B2C14D1DC1ULL, 0x14523DD4B1F5F0C1ULL, 0x6D2CDA1315CC7421ULL, 
            0xF80DFA37FC7B79D8ULL, 0xECB6FEA1930CBE84ULL, 0x9084EB8607132CB1ULL, 0xB473B091F0F21390ULL
        },
        {
            0x2E8DE9216B61DFDFULL, 0x83C1B411FA1753C4ULL, 0x66957B21850788D7ULL, 0x47F0F358CDBBAF08ULL, 
            0x4654A5137CF3FF26ULL, 0x91970D30F205DB6EULL, 0xF8555E8DED563D30ULL, 0xFB0D9F0C582E2864ULL, 
            0x089A40B76BC0B6ABULL, 0xCF5150427EC35258ULL, 0xEE6B2DC9427E2414ULL, 0x1C117A0953734E50ULL, 
            0x2DDD8C87D5AEBC4EULL, 0xB8B5738E33FD0864ULL, 0x2966EA9E4E088089ULL, 0x5F382748D0C632E5ULL, 
            0xF35F5F81D6ABB20BULL, 0x854764B4222BFB9BULL, 0xBD9E6E667B5B5E0AULL, 0xB045423BAC7F25D3ULL, 
            0x3958EC12C6E2A8C1ULL, 0x618BB1E054C8FDF7ULL, 0xC73E74979A81E15AULL, 0xF9D66AF23D89894CULL, 
            0xA475DF7C3A4E6FC1ULL, 0x555BF564134E05A1ULL, 0xCD31B6AE743726EBULL, 0x4ACAA04012198050ULL, 
            0xAC5E582899117964ULL, 0x2C21AECADD248482ULL, 0xAA6C6A47F9DC1A0BULL, 0x35D9DACD3E0CD35FULL
        },
        {
            0x4222D715C17B13DEULL, 0xE52D931330F0D945ULL, 0x2165F5DC88EC8D5CULL, 0x574B82D89D783FC1ULL, 
            0x04EF0054127AF910ULL, 0xA40A23C175482BE0ULL, 0x558C896D96D2FABAULL, 0x85AD1F7494BB2D53ULL, 
            0x7EA6132300079922ULL, 0xB89EFF03D64BAFC9ULL, 0x0D1E2CCB081AC4A4ULL, 0x3F395CB35AC4B5C6ULL, 
            0x1F9C25B0CE81CC6CULL, 0x6B902BE0C8296021ULL, 0x714B11A158722B4BULL, 0x1F86F0AF6B283463ULL, 
            0xCBED4B749550D39EULL, 0x1DB68673FE7710E4ULL, 0x6B8C3B1952CFCAC4ULL, 0xAB20FE54C662C55CULL, 
            0x50A624127E8FA3CDULL, 0x0AC145FDC8A0AB8AULL, 0xDA8AAE411BCF7CC4ULL, 0x4290C06968E5647FULL, 
            0x72C424BFEDF42947ULL, 0x04CEAC8537A8F95EULL, 0xA7E8012A198BD014ULL, 0x0D0D16E6847C0C5DULL, 
            0x33DDC936D33D90FBULL, 0x2ABCFFEE276A6944ULL, 0xEB04EAADA391E0CBULL, 0x654470CE0DDCFEDAULL
        },
        {
            0x68F888AA34DDF6DBULL, 0x0DACB3E76C87AA4AULL, 0x2903EE606A1A3C26ULL, 0x1C603A67502C302CULL, 
            0x7A7728B774014540ULL, 0xA0FB24D60F579B3AULL, 0x9E448339D3E32842ULL, 0xD1D78AC3F260C039ULL, 
            0xAD8AFC09B79B7C10ULL, 0x4537E2D949E2A176ULL, 0xC4F5D58D30764B0EULL, 0x303AD5241A99254DULL, 
            0xA0F37209F32DC18BULL, 0x0AB6E8B3A028FD71ULL, 0x9378B057BEB8B39DULL, 0x2FA9EF0A42FA7C87ULL, 
            0xFB569FD8B29404CEULL, 0x59D622C7D64F71A8ULL, 0x1327BA896362494AULL, 0x36B591E9E1BD2937ULL, 
            0x8E2129020A985DCFULL, 0xBFE41AD71CA617C6ULL, 0x7B868FE6447CB676ULL, 0x680D0B4C865E31B7ULL, 
            0xD0EB24759EA75860ULL, 0xE5DBA346D5689F68ULL, 0xB7E75B53CD086085ULL, 0x595D56ACDF487563ULL, 
            0xEC8EC4D21380EB76ULL, 0xD83B94D26F287390ULL, 0x844132EF1AE1DC5FULL, 0xE6DB52CDDB8DA852ULL
        },
        {
            0x35351ECC50E164BFULL, 0x67EFE260108D0864ULL, 0xF0F283BE8C29209BULL, 0x67C3DF85A9FC1E0AULL, 
            0x00DAF781B6FE033FULL, 0xE8BD84DFA03D24ABULL, 0x28569ED7BFB3D68BULL, 0x4D5630A17D7B1286ULL, 
            0x1E8456584745BB1DULL, 0x4C888E3BEDEFD793ULL, 0xCB6F54B0CDECDE83ULL, 0xEE8861E164D46530ULL, 
            0xBAD126EC3C64C972ULL, 0x8FD36F97C1AAE84AULL, 0xDC0A07060132EA65ULL, 0x84606645B96A7B30ULL, 
            0x7671CB4A6FCA780DULL, 0xE529612CA48C478DULL, 0x521C72EF7E2940D3ULL, 0xBBCAEB001DB6B1F9ULL, 
            0xDE6EAEA685131F1EULL, 0x943C473B55379CB9ULL, 0x5A89C1930BB1C95DULL, 0xF748250FF6A478ABULL, 
            0x74284942066A8A9FULL, 0x1DD74C329023323FULL, 0x4307455C6AAD8368ULL, 0x794E0389E54337F6ULL, 
            0x8CC466750D8241C0ULL, 0x8CF4085324847C0AULL, 0xDEEA9654727DDDC9ULL, 0xE9F976D5F80F86C8ULL
        },
        {
            0x4C867775741031F1ULL, 0x1940120AB8B3D638ULL, 0x94657DDE34E4317AULL, 0xEA03F23FCF8A05D8ULL, 
            0x616C323B16DE2ACAULL, 0x8B0F6E06BEFB1D55ULL, 0x5DF6AC5C94E0EF6EULL, 0xB5541FFFA54A8DD2ULL, 
            0xC14B8C125709D270ULL, 0x4C751BD5306A7E03ULL, 0xFEFD45EE8D523D01ULL, 0xD0E0D64B3BCF9375ULL, 
            0xAA5981C50DFC0C42ULL, 0xC6D2152B86F8B0DCULL, 0x3651627DF5961324ULL, 0xBC8936D32FBBFCBEULL, 
            0x4F1C4185ED7A9CC2ULL, 0x91C4343D46DBCB76ULL, 0x0F9DA8179A33E9F8ULL, 0x896CB1C1F1580E3FULL, 
            0xC7D191732F1BB00EULL, 0x7628D4458185624EULL, 0x7726EF2322EB23E0ULL, 0x2BAC025F54FA3DB0ULL, 
            0x3958532C611B75A6ULL, 0x57E3D1E86D9B3EA3ULL, 0x2897F8E4C0A4155CULL, 0xBA72D887FEDDD9C3ULL, 
            0xE9154D1E47B5D5BAULL, 0x51A658AA0F14EC63ULL, 0x35082FD36B049BD7ULL, 0x8FE4FE09B223AC2BULL
        }
    },
    {
        {
            0xBA1DF394FF154E61ULL, 0xB2FB1B7D1F69CD0CULL, 0x75987EB444C65F14ULL, 0xE36E8E0FF5436CBEULL, 
            0x8C2304AA2783657CULL, 0xA3E8F275A70FD695ULL, 0x73B7EB63D35B9687ULL, 0xB4B235EE657C2906ULL, 
            0xEBF1CC06E34354D6ULL, 0x66FFBB209273035CULL, 0x19A28948985F346FULL, 0x4FE6DB1E8D1620B4ULL, 
            0xF81F85FA8F1FB2DFULL, 0x13D071A8BB72E4F8ULL, 0xA2B1A2C2B0444012ULL, 0x2B29705F4CB67394ULL, 
            0xF820A0341D58045AULL, 0x11884CDE32A56D3EULL, 0xE6CD1D771FC83E11ULL, 0x0465F9487CDBA38CULL, 
            0xD9BD633FF132CCE6ULL, 0x0E9FAE71A58ACD48ULL, 0x462BDD4FF3C8A8BFULL, 0x4FF19C848C3FDD73ULL, 
            0xE442C62D7C108AA0ULL, 0x3D4C5195D419D19FULL, 0x08E7A7DF4ADB2381ULL, 0xC60A5A066DC207E2ULL, 
            0x04B0B3D83C297E30ULL, 0xE1F43C9D088223F8ULL, 0x1EAF64222A85C5F0ULL, 0x3D85AB64309C8696ULL
        },
        {
            0xF462CB5DD44CE27FULL, 0x57DE881C407D8EDEULL, 0x70977BAEEF231C1EULL, 0xE8901003FDBD74DCULL, 
            0x5C52CE958EA59C10ULL, 0x5DC1EB7B6251EA2DULL, 0xC639C670DE189D33ULL, 0x9E2C0AF755BF6FB7ULL, 
            0x7725117F85E75575ULL, 0x6DCD1E8B14A521F9ULL, 0x2D441ABD848CAA9DULL, 0x14B67027BD91333FULL, 
            0xA36D262C01DECC27ULL, 0xD30A01161CC93AA0ULL, 0x7857A3C12FA68B91ULL, 0x864C76B36E1F2904ULL, 
            0xF05EEEF16AB580B0ULL, 0x2B64558DB0F8993FULL, 0x8CDFF257B1D5992FULL, 0x4DB67D52E164B74CULL, 
            0x52403FE0B8A59D14ULL, 0x55A333F9218B1ED8ULL, 0x3E7A5714A5599B7EULL, 0xD9547298F89F106FULL, 
            0x931F53D2E732B682ULL, 0xFC8EB2D5BDD00ECEULL, 0xCDB4E101284741DDULL, 0x9635D5CA2476F61DULL, 
            0x282DC928F39D0AB1ULL, 0x34E465351F85BC01ULL, 0xB0A3F36C8D620D0DULL, 0x9EB4A1467ABDA28EULL
        },
        {
            0x5ED6E2425CAC26ADULL, 0x94991AC640E1CF44ULL, 0x2B317EB8898F3499ULL, 0xF1A12D46532B33A8ULL, 
            0x8602130A0B142AB8ULL, 0x28424ABB2FDC5EFDULL, 0x3D71A1685D33CC18ULL, 0x795510158FFDE8C5ULL, 
            0xD0F7A7E856226A34ULL, 0x09BC4874B1689CA6ULL, 0x1842C16A405A0C53ULL, 0x659AAE8548AA343DULL, 
            0xA661932C464E3730ULL, 0x0A8E3E798490AC39ULL, 0x570F37B8B98B141DULL, 0x0BEC1CA8FC089819ULL, 
            0xF05A8240D6F7EF5EULL, 0x8435995B52278FAFULL, 0xDAF1467E7901CDD6ULL, 0xB6ACF022279DE395ULL, 
            0x82A59CD560FF5861ULL, 0xE7892DA08AFDD3ACULL, 0x4D2A2B8F269F20E7ULL, 0x6D3508DF5C20347EULL, 
            0xFC9D241A4AC6E02CULL, 0x06B9AB8BCD35F891ULL, 0x380E055D702FE92BULL, 0x1A717B3CBC1F54ADULL, 
            0x62DCA8EAE5AA3B64ULL, 0xFABE3F3F0F13102CULL, 0xC593E2090BA1E83CULL, 0xADBEE2D26585DAA7ULL
        },
        {
            0x2888C7232973E43BULL, 0x3FFAC5747F339008ULL, 0x8187A06FEB4900F9ULL, 0xAD1834907D7DC9DEULL, 
            0x4442BFB9848EBBAEULL, 0x1C895ADB6BA670BCULL, 0x83F7A934290A5EA0ULL, 0x5DC3139293B8A7D5ULL, 
            0x6FC5AF40A615FACEULL, 0xCC86BA19B10D3045ULL, 0x8F2FD22825A311CFULL, 0x0DFE00EE7DE54E76ULL, 
            0xEA7778B13389510AULL, 0xE361F268E6924012ULL, 0x2A642294FFF721E0ULL, 0x8F5DA16824300495ULL, 
            0x28325CF0FB9B4787ULL, 0x968DECEABAC2436FULL, 0x3FD94F911DE93AB3ULL, 0xB2EB833FD4C6C8D1ULL, 
            0x82BA4079F372E285ULL, 0x03D23923789CDA2AULL, 0xB263D70C03E8A261ULL, 0xBA8332FD707946C4ULL, 
            0xDBBB2873BC654992ULL, 0x3188D49500A22A8EULL, 0x56F79504B5DCA86CULL, 0x907C2092D79696E7ULL, 
            0xDE44070ABF095846ULL, 0x7DC7413EC8DEACC6ULL, 0x96772A42D248294DULL, 0xDEEE622F39E648AEULL
        },
        {
            0x7DBE1B5340FEEC1EULL, 0x594982FFEFF05379ULL, 0x367D06EBDA3AD642ULL, 0x0760FF32FF173753ULL, 
            0xD02B234C08CB9769ULL, 0xAF7A34E14CC5BFA5ULL, 0x1EC255015CA741BCULL, 0x0D54A13CE276422FULL, 
            0xD723E525F97C4BBBULL, 0xAA132022690E37C0ULL, 0x2E35F1C0EC9659BEULL, 0xE3C60C68A0BD0924ULL, 
            0xF3082A434D67D23DULL, 0x6AA975AFC4275C3AULL, 0x98C8498EF222C34DULL, 0x1CE98885C74413EAULL, 
            0x2177817B0922549CULL, 0x684DFBF033032727ULL, 0xCBAE68ED455AA740ULL, 0xEF5B91F19653B651ULL, 
            0x735F43A6119D68BEULL, 0xC469FB008C0BBF79ULL, 0x2F0FDED66351C250ULL, 0x092CBEE6F2C5D9E6ULL, 
            0x3B1157CCD28F8CFDULL, 0x236F7FB0BED2DE35ULL, 0x2E4CE7CF64677692ULL, 0xC3B4F0098C166773ULL, 
            0xB29EDB361C97FA7BULL, 0xE720118AE11CD4FFULL, 0xA93CBBFDDD560168ULL, 0x9B70EAAB15C301BCULL
        },
        {
            0x8589D905A0E62DC2ULL, 0x29395AB9587FB2D6ULL, 0xCB8C43843205405BULL, 0xEBA0BCA006B458C0ULL, 
            0x23C77781D3B58A40ULL, 0x6070733E0FA87DECULL, 0x1F8F37A63C1FB3A4ULL, 0x9523CEDB8D3C4D26ULL, 
            0xB0C9C0E8D82F222AULL, 0x363692FD623F7E79ULL, 0x38D11EC35DA1EC6FULL, 0xBFE438C6E1CDDCD3ULL, 
            0xF72E7566BEA1543AULL, 0x5E09A03E5CD347FEULL, 0x419C3C6B2B14E5ACULL, 0xED6FCC5B29306BE0ULL, 
            0x1A23224894583A8DULL, 0x1A22A3256EDE880DULL, 0x34ECD72C2CC82999ULL, 0xD35EEFCF991CCB15ULL, 
            0xC94148BF1FDC1DBFULL, 0x8ED2DD24F9636CB9ULL, 0xF030E49ED6B1A9B3ULL, 0x4B8DB93A3E94E5A0ULL, 
            0x2817520D7E7C2748ULL, 0x6E413AC75FE7118BULL, 0x66B88ADA7CB53B27ULL, 0x6E00EB60ECE6294BULL, 
            0x59D64A04FE8980FFULL, 0x60D73BF98257D9F4ULL, 0xF23C02F69CC6F595ULL, 0xC9C154D84CF3E50FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Achernar::kSeedConstants = {
    0x01B2822D5A7A5FB9ULL,
    0xDB4981248A087C7BULL,
    0x53398533A023F536ULL,
    0x01B2822D5A7A5FB9ULL,
    0xDB4981248A087C7BULL,
    0x53398533A023F536ULL,
    0x1CBE4283A46E13ECULL,
    0x44F8CB125DFE44D3ULL,
    0xF3,
    0x49,
    0xB9,
    0xDB,
    0x46,
    0x3D,
    0x8E,
    0x87
};

const TwistDomainSaltSet TwistExpander_Achernar::kTwistSalts = {
    {
        {
            0xD60324A65A903B25ULL, 0x8960A5F9CB478CBEULL, 0xF9DA2F7DB3751BD9ULL, 0xB1DCFF5066B77EF8ULL, 
            0x066467AC51CE457FULL, 0x7A984F5B7B4FC0F9ULL, 0x89BBD0ADD37D8E63ULL, 0x7A3163C0363E69AFULL, 
            0x3D4D4D7BE97CC93AULL, 0xB2DD7D2AE08C5E4BULL, 0xF7FF4CC9946A0C44ULL, 0x9A03FF6D36AB0A34ULL, 
            0x79AD8103B3DF19A4ULL, 0x0D07218FD2F4C044ULL, 0xF7E43CBD7CE59428ULL, 0x7715B8A62F89C0BEULL, 
            0xEEE2F820842DE332ULL, 0x3931A804CD4F7A95ULL, 0x90B0AF8ACF32008DULL, 0xAE49C793D31203F9ULL, 
            0x988B6B94D1363012ULL, 0x255813C6987023BDULL, 0x3DAB119571275329ULL, 0xC3D31C23EBCBA3DCULL, 
            0x671B2CFC56BD3BC2ULL, 0x69335CA725D49C49ULL, 0xFE8DCB6ABDF74A23ULL, 0x978AE7B2367CCCAEULL, 
            0x3BDED5F28675AC94ULL, 0xF16923B658C2E361ULL, 0xFBCB7FB5C7A345E1ULL, 0x2B27D22F5ECFAEF5ULL
        },
        {
            0x3989A776AE5ACBBDULL, 0xD1772904203F443CULL, 0x4EFFFFE8AF079B90ULL, 0xD518A7097296E7F0ULL, 
            0x4ED00473BEA6CD03ULL, 0x2ED3BE8A4499E2C5ULL, 0xC2A77634D9FD66A7ULL, 0x4237B61A850F76E1ULL, 
            0x5D65C42DAD677BB7ULL, 0xB25EF05D8DB9D58DULL, 0x35E9E55ACD95D5C0ULL, 0x5AD54492B1476220ULL, 
            0x526E41940DB5DED4ULL, 0x9DE2263EF746AF17ULL, 0x744A1213C4DBF2B5ULL, 0x379787A24B3AB05FULL, 
            0x422CEBAEDEC35441ULL, 0xEDFBC287945FE627ULL, 0x011909A9ABCD944BULL, 0x0F53039E38C3C7A4ULL, 
            0x618D48569241A180ULL, 0x9DAD5537CFF3C517ULL, 0x33BDE5C934BB2B39ULL, 0x46F370D5F47097D4ULL, 
            0x99C99342D18A91A7ULL, 0xE6DF12A5589E1C04ULL, 0xCAB23B96B53E727FULL, 0x05E433228A4E7724ULL, 
            0x9C964A2BD062556BULL, 0x564C5AB93217C6BFULL, 0x2D7E5AD085DE8F46ULL, 0x57B8E0839A91FDE9ULL
        },
        {
            0x4C7920266D6C6541ULL, 0x959C46F3505EB622ULL, 0x54695859958A4380ULL, 0x28C446F4F222EEC3ULL, 
            0x1B24EE7F50C1D721ULL, 0x6B531E27139CAF4EULL, 0x85D21389E023B1A8ULL, 0x7C8E8F946AA32682ULL, 
            0xF834018A53C2896AULL, 0x7CFB43B85009B263ULL, 0x14417A78A9380912ULL, 0x06D33617B5566D98ULL, 
            0xDD02B8226CD8B328ULL, 0x59ED19FBE44F37CBULL, 0x7D78751FD98F105EULL, 0x90C9DBE2CDD89446ULL, 
            0x8A28043B93C90A6AULL, 0x92B502E8BCD58675ULL, 0x6D276267B3EBE044ULL, 0xBCA71395047202FEULL, 
            0x7215BB6C5EB41086ULL, 0x784213E6517E1631ULL, 0xFC938BE46BA7B22AULL, 0x72B1C2F93BC42109ULL, 
            0xE35C6DE08584B8EFULL, 0x796B7188B17AEBA0ULL, 0xBF2CD308E5334E7BULL, 0x4015A034A6E465CCULL, 
            0xA9B7CA71111A3464ULL, 0x8D4B41B7A8BA67ACULL, 0x72AD1B6DA89C776EULL, 0xF06328498725E742ULL
        },
        {
            0x723CB8D1188A5DDEULL, 0x52DBB101E47BFE77ULL, 0xABC50D194D566366ULL, 0xEDD9676C6FE39A3CULL, 
            0x95628D3A1270F057ULL, 0x1E8430EFD99FC857ULL, 0xC8575988C9532C67ULL, 0x21913371B0D284D6ULL, 
            0x69A5678AA4C52CD7ULL, 0x7A4FDF0DE9085416ULL, 0x43888F939985C603ULL, 0xD29755A5D91EE15AULL, 
            0xAA14C7DE6E2D339DULL, 0x4E8EEB1A531C97F1ULL, 0xC6A9654515FFDF93ULL, 0xEB31B892CA480227ULL, 
            0x2AD7A33E458CE164ULL, 0x64A1EA47ABFE276DULL, 0xAA3D6D4AF81F8E59ULL, 0xA10F79B7D93554B3ULL, 
            0xEE7971C355D5CD92ULL, 0xE39A347C912500C2ULL, 0xDB061FA4190A3D69ULL, 0x79E110F960FA4AD0ULL, 
            0xFCA77C6E49478CA9ULL, 0x38A2FF1596A42FCAULL, 0x5E481B171E664F18ULL, 0x53DF182F1D502540ULL, 
            0xB0F2DEAF25175C3DULL, 0x76F3317A1BD67302ULL, 0x746C17C2B3738BFDULL, 0xC64F5B717C148FD7ULL
        },
        {
            0x1E9D669B410C12A9ULL, 0x0A0C7BDCD83D11BFULL, 0xE0ECCAB90DDDA3E9ULL, 0xB128601D5915F89FULL, 
            0x0D81913AE0C34F6EULL, 0x74FB53FF65DC9110ULL, 0x4800ACB2D564C382ULL, 0x73485B28BE721807ULL, 
            0xD9FFA9E0A962B8B3ULL, 0xC9264B878813C636ULL, 0x0643B29536315FD8ULL, 0xEA1A2C6DA8F2CEC8ULL, 
            0xF44ED0CF9826F852ULL, 0xA0066EF332DBC34CULL, 0xFB0458FA40E939EDULL, 0x75768BF35FB159F2ULL, 
            0xA22D3AEC412C1E17ULL, 0xF80C88C335E935C0ULL, 0x11EA292CBFC1729FULL, 0xF3E69ED78BBAA853ULL, 
            0xD4479CDC9EEA2D0CULL, 0xBB645669B9203994ULL, 0xB53EA619D03B311BULL, 0x348D51AFFB3D1A16ULL, 
            0x5E543888A179D99BULL, 0x8A6CF4244BFC7A51ULL, 0x5CFD8CDE158AA1C4ULL, 0x47B9D0D20D3B5CA2ULL, 
            0x33F8776EACCF7D24ULL, 0xC005764A356B52BFULL, 0x1956DD5F989CA108ULL, 0x6F1172676B7CFFC9ULL
        },
        {
            0x3D4A04F6DDC46A84ULL, 0x1639ED2EEA826E75ULL, 0xF44808A3A5259F2BULL, 0x99A9863E38BDAA65ULL, 
            0xAA6331E20C73442BULL, 0x3F5D722D9F468A71ULL, 0x5924AB184B1AACB2ULL, 0x15D15F9FBC46EAE0ULL, 
            0x60F6D6204DCC33D0ULL, 0xACFF43421C765B92ULL, 0xFC8DCB10ACA978BAULL, 0x394AEB9FC8226948ULL, 
            0x30CC4425211D1031ULL, 0x97D008CE4E1D8821ULL, 0xD85798271A230219ULL, 0x33E6323250487C3DULL, 
            0x2868302DB8A26B8DULL, 0x857ADDC84C296240ULL, 0x94695E5D0F26BDF6ULL, 0x90B7129073D1F73CULL, 
            0xAA21D7532521D523ULL, 0xEF9B1C0C878182E8ULL, 0x41D7D187A850D980ULL, 0xC0AE9B69E1BF03EFULL, 
            0xA6E7A1842EE2FA5FULL, 0xE95BB93F0DECF6B7ULL, 0x8C89C5B9801CA931ULL, 0x4E574F30B1A4E0C6ULL, 
            0x0157866EF9BCD3BFULL, 0x1D870DCDA9E676D6ULL, 0x6DD7A64638F3D412ULL, 0xD2E7281E21E655DCULL
        }
    },
    {
        {
            0x43FF60DE3A780E44ULL, 0x078C7B5A322E8F9EULL, 0x5F8627AC6E536D36ULL, 0x5EF93F7516B0136BULL, 
            0x929A7169B4082833ULL, 0xA0DB16BBDED2D3C1ULL, 0xC3B592560F9E858EULL, 0xB492FAAAE965F307ULL, 
            0x476C127504574E9CULL, 0x2017740BFF9EEE22ULL, 0x2E6F7E325296A6A9ULL, 0x1460967D8F7303C2ULL, 
            0x9170E974F9685E06ULL, 0xC498366B943C6544ULL, 0x0BFFC824BC1D893DULL, 0xC543921460D5CCBCULL, 
            0xC285F58DE3D9A8B5ULL, 0x8A1D8409C34739B9ULL, 0x1466A75AFED81657ULL, 0x90D189CAD44AB096ULL, 
            0x471CDD5B13A17146ULL, 0x29ED16BDD4744D18ULL, 0x5927D97E07C3ABBAULL, 0x3F6D89BF2D9EF2ABULL, 
            0x5CEA997FBA0676AEULL, 0x34384480852B6D7FULL, 0x6DAD740543986DAFULL, 0x3E4DF276A79C3D19ULL, 
            0x4123D8E90ED1D821ULL, 0xAB2DB67F6749DED5ULL, 0x16E8608759668405ULL, 0xAC37F667A77B76E1ULL
        },
        {
            0x147590B1D6D1D79DULL, 0xD78E5766F29407B5ULL, 0xDF227BB041891F4FULL, 0x3BCA819D9E8848A5ULL, 
            0xB6D79569CAA358C6ULL, 0xF1E2FEDF57325C62ULL, 0xAE255F135A2809CEULL, 0x42204A0A868DC9FBULL, 
            0x495F9152BC8D968AULL, 0xB839401FFCE37F32ULL, 0x9EC3174D120DE087ULL, 0x531CD089A54AAF57ULL, 
            0x636D8685848A665FULL, 0x921EA9C0925A854AULL, 0xF7ED3C7709FAE9E4ULL, 0xFF35BDB26A05560DULL, 
            0x3172A9CFDDE85AB9ULL, 0xDA758ED495CA17ECULL, 0x4F903531456B5D81ULL, 0xD453C71E51752E17ULL, 
            0x72C75D83F37C68E4ULL, 0x12CA51F8326BF7D0ULL, 0x3E6CB8D5083DE0A6ULL, 0x09CD590F2086BFBAULL, 
            0x296001CD12285B10ULL, 0x7515C267D374E8C7ULL, 0x19C931C0B55169D8ULL, 0xFD8D9F6501AA027FULL, 
            0xB90836B42FC4F995ULL, 0x765F37020304BD47ULL, 0x226A4D08F2C8D873ULL, 0x17611624AC5EA718ULL
        },
        {
            0xF4CEA4064F70A050ULL, 0x30538DE08B74D02AULL, 0x02132B634DAD188BULL, 0x47549AE394EDBE10ULL, 
            0x6677AFB0C9B2E37BULL, 0x40CD5105DF706F15ULL, 0x97AF796D18DC2708ULL, 0x0002ABEC91E88CCFULL, 
            0x565B669A794C2C56ULL, 0x9FA83B1823678CD9ULL, 0x49BC895B0404491DULL, 0xEB3409438CB330E4ULL, 
            0xC2849F93A4B011C9ULL, 0x2EAB04F548BAAC8FULL, 0x55B958CA5615ED01ULL, 0x75E75C423F21DA8FULL, 
            0xD61DCDA9C9531D19ULL, 0x787582764D079EE5ULL, 0xD912BE0DA630B834ULL, 0x0A55DD7A18C4CB66ULL, 
            0x5274CC77268363F0ULL, 0x69B99F202DB29BC2ULL, 0xDBF106C7885BECA3ULL, 0xE22C78861ACD5E40ULL, 
            0x787D85BB4EDD71AFULL, 0xFC4CE60D58EBFA71ULL, 0x3A15259929036362ULL, 0xCFEFE96DF7D60885ULL, 
            0x67AA09A40F52F83BULL, 0xF54D22B4C5B5F9F0ULL, 0x977F6D67272F344EULL, 0x9A0E3DC068D47316ULL
        },
        {
            0x8234290698EC5FB9ULL, 0x93CD3B1BDC224E80ULL, 0x5B6208EF6BE78300ULL, 0x46563BD1E0E78F2EULL, 
            0xF89D9BC415AEE6B1ULL, 0x51E60CF14A02F116ULL, 0xA93312F6DE9B7FB6ULL, 0xA38FA49FE3256710ULL, 
            0x30900ADFD5977267ULL, 0xC79E8BC84B3D884AULL, 0x4770CBBF7D9117ABULL, 0x895B2282D8D2E2A8ULL, 
            0x3556A62E0606CF95ULL, 0x2A9297F0AAFE3498ULL, 0x754CF37240ED89B7ULL, 0xBA542E34A0908135ULL, 
            0x256CD482A8E0232DULL, 0xEDA3BD5C39D8F594ULL, 0x02991AA72803ADC1ULL, 0x8C55B8B229E58F75ULL, 
            0x5C894A267A4F65A3ULL, 0xE28B4AACB4D11D27ULL, 0x2E1173E77BEA754BULL, 0x1A977439CEDD775CULL, 
            0xA4FE014C7B9D9D26ULL, 0xD3BC1CE8DDA79D61ULL, 0xD588AF8078FF6D72ULL, 0x277C18C083F545EFULL, 
            0xFA8EBA0907E35321ULL, 0xDAE88EC64014A459ULL, 0x711A7BEE2BE5232BULL, 0x94512F7FEE375430ULL
        },
        {
            0x1A28D20BD0ED9039ULL, 0x369977619367087DULL, 0x7CDA13685C5E5926ULL, 0x07681EF539E618CBULL, 
            0x839767978535A960ULL, 0xEADF96A781232F2DULL, 0xE7BE4C439A9A42BFULL, 0x2784038015B8F8EFULL, 
            0x1724620808133D4CULL, 0x06887255C97B9752ULL, 0xF1A9920FD06509B8ULL, 0xA5DF66CB58A2B150ULL, 
            0x71FCDA1F0270D10AULL, 0x2CC8715B9241D539ULL, 0x75FBB4B7F80954CEULL, 0xCAF1F762A2C66825ULL, 
            0x8C81BF9CF06FEB1CULL, 0xD0C7F64B7CC9DC5BULL, 0xE060038B8AD3BB45ULL, 0xA55281F854EBACF0ULL, 
            0x6A85744743847C68ULL, 0x34EAC1F4E522A52DULL, 0x60B0F85DE3CD86A4ULL, 0x433A1230DBFBF922ULL, 
            0x7C24221F5F9A991DULL, 0xD2207832885FA0C4ULL, 0x39C3EF1DE8CCC444ULL, 0x498A8EB54E31CDACULL, 
            0x9EAB3C7B1788FF33ULL, 0x94DA13CD50CE7F7DULL, 0xA07733F9A159F51FULL, 0x94AA86B80B3D0416ULL
        },
        {
            0xF7200AF6AB56CF67ULL, 0x7377CF4EFFCC8FC3ULL, 0x5B22C7E9AA91AAC2ULL, 0xA734648A9CD61269ULL, 
            0x6A61AE17E0378DE0ULL, 0x3DD6501C93F8DE45ULL, 0xC7D743241E4176FEULL, 0x99361F3DC3E016EAULL, 
            0xED1972B65619BAC5ULL, 0x51963B514BCA8300ULL, 0xC032130DD1DD5FE5ULL, 0x63873F4C4F5F4D92ULL, 
            0x54B4CB7D9BA7AA49ULL, 0x8FECCA26444A316BULL, 0xBDE6AEB012E2F386ULL, 0xC0CFCD85C7566639ULL, 
            0x53656F4CA067DD13ULL, 0xFD459699E2D732B3ULL, 0xB0DF3FE2051628B9ULL, 0x40C7FE3FE6B0C3C7ULL, 
            0x95530ED00F98514DULL, 0x97B356BA251187BEULL, 0x720816E51628DA1DULL, 0xB679059F50ECD321ULL, 
            0x06B1057FC4E0861BULL, 0x9DEA289912631070ULL, 0xD8AE9819B454E3F7ULL, 0x21D55BECE9C344CAULL, 
            0x1684F3F84562D367ULL, 0x0431666A9E0D1EF2ULL, 0xC74B44C35C9F5A76ULL, 0xBDC11766C6CF7C43ULL
        }
    },
    {
        {
            0xED70E735E1BE1DADULL, 0x71E8C9D1BE3879E1ULL, 0x045C47089B0783E5ULL, 0x9BC0060DF6928FD8ULL, 
            0x14F5449EC6C13DFFULL, 0x4486C330E2B807C2ULL, 0xE3B8FE16E1136154ULL, 0xB4A5F205D08A3174ULL, 
            0xD1214E1FDF72E3A2ULL, 0x45DFD4779C331BCBULL, 0x1202CF515CDDDC93ULL, 0x15E95BBCB72026F6ULL, 
            0x31DC9D89FB8DFC5CULL, 0x441876454E82660BULL, 0x6D18F87F61510C58ULL, 0x1DFC26803B427996ULL, 
            0x6A6447669ABFEA56ULL, 0x3B9EC37910557ADDULL, 0x7421EE824F18E021ULL, 0xD8F66597D6D541A8ULL, 
            0x591C4DC6AB1C411EULL, 0xBBB40F0AF8108EA7ULL, 0x05EC0BBCB219B974ULL, 0xECFA516F1FD53859ULL, 
            0x8CDBA5C179262B3AULL, 0x4303C21D363ECE64ULL, 0x884C191F4CC33FCCULL, 0xCF7BB3D210D1CDE2ULL, 
            0x8964AFB760DF6DB5ULL, 0x8CF9E40FB109401CULL, 0x1DB5A1313A6CEA65ULL, 0x6C6167A782287FE5ULL
        },
        {
            0x20FCE2F206C271A4ULL, 0x0C52364396087A61ULL, 0x86092AC0F870CC63ULL, 0x69DD93430461D049ULL, 
            0x2CF1ACD00DE61380ULL, 0xD4A167DC8C6460EFULL, 0x7460D6D646ACB373ULL, 0x1E2F6EC3BEC70C22ULL, 
            0x7137C4DD74465A3FULL, 0x9C3B11211CD57DF4ULL, 0x45E69B020D789BDDULL, 0x28CEC2FC32436006ULL, 
            0x21B5E294A7D2DE79ULL, 0x49999AEF3D54C080ULL, 0x0A4DCB86957539E0ULL, 0xBA2B4D089EA64608ULL, 
            0x68F3A1ADA82DA197ULL, 0x696EA6B9DD57AF58ULL, 0xC7AD9E02D7606CC2ULL, 0xBBFD33E108667943ULL, 
            0x0CA0E42CC6E08829ULL, 0x75A6144A55D24D33ULL, 0x11178FA2B7570193ULL, 0xBF5AF2B3DA339AB3ULL, 
            0x7CAFA8699223D87FULL, 0xC0D8E3B5777EA369ULL, 0x689B0A71B50C614DULL, 0xE8C60516F901F9EEULL, 
            0xB9EC9C9C58FB4338ULL, 0x7D6CD9A1D8C9A382ULL, 0x6615D48E29379710ULL, 0x9DCB9A53562DF027ULL
        },
        {
            0x6DE18C8D879E79BFULL, 0xA53D3C87F945BA97ULL, 0x9083E425FF85A6D9ULL, 0x2074C57DD62E1531ULL, 
            0x9AA0A4A14F311B39ULL, 0xF0697A3B67DB74E5ULL, 0x26A8FFD1E1F5371FULL, 0x2E92F8E7DB6F3190ULL, 
            0x22EA307F9CB8385BULL, 0xD88FF3D47BD0D9B7ULL, 0xF39A2B71D3835D31ULL, 0x99BFEEE2074CED49ULL, 
            0x1849191215D0DF4FULL, 0x9339CB0C69E15F40ULL, 0x994EA271F7AA1207ULL, 0x0041AFEE077CE698ULL, 
            0x60DD411B7E076393ULL, 0x5FBC88683BF0D25DULL, 0x63BF69571CCC3AEFULL, 0x6271CC91FA8763AEULL, 
            0xE6DB2AFDD41A1D4FULL, 0xD45643E2626C9535ULL, 0x38DDA2B1ABA11DDDULL, 0x8A1293B72933DA3BULL, 
            0x66F72B39DA51A036ULL, 0xD232196EB63CDA86ULL, 0xB0B510D7F69BCC42ULL, 0x90F202B22891B5B0ULL, 
            0x6D0D403EE423DE02ULL, 0x6D272380E26710F1ULL, 0xF43DB9AB10803FF9ULL, 0xBB6AFEE263A17195ULL
        },
        {
            0x9FBAA8AF233DF59FULL, 0xC434F1AFDEC49FD8ULL, 0x1649185B9D4DD113ULL, 0x5A6C2EDEDD5B2A7DULL, 
            0x39891BBA299832B3ULL, 0x74D30AFEC8127A6DULL, 0xE36AC677CC21E3DEULL, 0x98D28AD68B8CB1D2ULL, 
            0x29E3B4E2B282CB43ULL, 0x7C19264216C8D2B8ULL, 0xF8245C72F5D19CF9ULL, 0x829EF6D2D777D1E4ULL, 
            0x4EEF52425B417D10ULL, 0x7894127CE084299DULL, 0x40697576108C2E35ULL, 0x02FCDC045DD0EB34ULL, 
            0xDEF2F149C6927BCCULL, 0x23E34A2A76E8599FULL, 0x2F0A223326C1FBDFULL, 0xD299EC9110617370ULL, 
            0x67A0813A0DDCF2F4ULL, 0x334DDA60DDA2A0B9ULL, 0x14FDECAAF4CE88F4ULL, 0x374B08FFF198EF0CULL, 
            0x7FC5AE5DAD85C517ULL, 0xEC084E6490A1EC01ULL, 0x8EF428BA9A118A72ULL, 0x5B64D45FAE947925ULL, 
            0xF667ABFB852B9BA6ULL, 0xB43A70E8C59D1B30ULL, 0x577592B6B74C6A26ULL, 0xDA383B8B4B6637BCULL
        },
        {
            0x219F722F71EE4B28ULL, 0xD13F8B2B742A21E3ULL, 0xCC43A643517CA048ULL, 0x9F30A63F6ED2C6FDULL, 
            0x9F483D570C543E20ULL, 0x588EDB9106505571ULL, 0x534065C2C43CC6DAULL, 0xA846EBB3377EB786ULL, 
            0x3BAA9947A87E97E2ULL, 0x9A2285628F0E3325ULL, 0x3873667AEF9A6939ULL, 0x8E5C816EF1356CF2ULL, 
            0x56825631B9837C78ULL, 0xAD1C76ED805BD1C7ULL, 0xA17025613C2C2FD9ULL, 0x4D1F0B0A13D1ED57ULL, 
            0x21D1FDBA9C76AAEDULL, 0x109317BE0E85F8BCULL, 0x877F29D4FE36E011ULL, 0xF8FE730C9C3DDAFEULL, 
            0xABFB296A02010878ULL, 0x7D7448BACA756F55ULL, 0x5FE0899D17543A70ULL, 0xE867E3CC0DE34FA5ULL, 
            0xE9F34FA273E0F119ULL, 0x31156D830E1087B5ULL, 0x038229124C602D66ULL, 0x3FFE8144C40F7E41ULL, 
            0x70BD3A44358E8E2DULL, 0xBF6F390B3531FF59ULL, 0xF563BD1C78D0F49FULL, 0x70CD6821BE919523ULL
        },
        {
            0xD255B84255FC9CE0ULL, 0xF7A0A7B382387A1CULL, 0x5BECA56C8920287FULL, 0xCB30966FA209C359ULL, 
            0x45BA4B016CE41C95ULL, 0xAC9FBFCC4093E15DULL, 0xABDEBB8D218930A2ULL, 0xF86DC809FF7828A2ULL, 
            0x4C474C345D7D386BULL, 0x36D2A4E85D6E7C04ULL, 0x7D2EC7C53B5BCF8BULL, 0x45F31038BBEC2D5FULL, 
            0x6A38875B2E8E5F42ULL, 0x4AA43E804221AC82ULL, 0xC7AA67B69BDE63EEULL, 0x4AC86A20504C5C16ULL, 
            0xF7F64ACEE5D1A7E5ULL, 0xDB24B8C28AFD647FULL, 0x0FDB65FCB1323D76ULL, 0x326B588D1E37F869ULL, 
            0xBA5C1BB0958B7E63ULL, 0xE538E0A4E346B9F8ULL, 0xD606552C66A85850ULL, 0xAEE85C0AF587887BULL, 
            0x3583014F71785148ULL, 0x906A5206ED363C9FULL, 0x5C5CA348F2F1AC39ULL, 0x39886119D56887A2ULL, 
            0x99BB5D0DE8742F2DULL, 0x4898B60389C7F17DULL, 0xDEA9F0AC6E4A04FEULL, 0x929595480BB00AE9ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Achernar::kTwistConstants = {
    0x5C0FE1369BDFE47AULL,
    0x7B2510386C5B5CF8ULL,
    0xCA8B6E7BC8BBDDBFULL,
    0x5C0FE1369BDFE47AULL,
    0x7B2510386C5B5CF8ULL,
    0xCA8B6E7BC8BBDDBFULL,
    0xB85DEC65830290D2ULL,
    0x2CFDD1642348555FULL,
    0xD2,
    0x19,
    0x3F,
    0xDB,
    0xEB,
    0x73,
    0x43,
    0xA8
};

