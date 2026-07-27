#include "TwistExpander_Menkent.hpp"
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

TwistExpander_Menkent::TwistExpander_Menkent()
: TwistExpander() {
    mDomainBundleInbuilt.mKeyRotateSalts = kKeyRotateSalts;
    mDomainBundleInbuilt.mKeyRotateConstants = kKeyRotateConstants;
    mDomainBundleInbuilt.mKeySpawnSalts = kKeySpawnSalts;
    mDomainBundleInbuilt.mKeySpawnConstants = kKeySpawnConstants;
    mDomainBundleInbuilt.mSeedSalts = kSeedSalts;
    mDomainBundleInbuilt.mSeedConstants = kSeedConstants;
    mDomainBundleInbuilt.mTwistSalts = kTwistSalts;
    mDomainBundleInbuilt.mTwistConstants = kTwistConstants;
    mDomainBundleEphemeral.Zero();
}

void TwistExpander_Menkent::KDF_A(TwistWorkSpace *pWorkSpace,
                                  std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet,
                                  std::uint8_t *pSnow) {
    TwistExpander::KDF_A(pWorkSpace, pNonce, pConstants, pDomainSaltSet, pSnow);
    if ((pWorkSpace == nullptr) || (pConstants == nullptr) ||
        (pDomainSaltSet == nullptr) || (pSnow == nullptr)) { return; }
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
    std::uint64_t aPrevious = 0xEC44B3910DA43D51ULL; std::uint64_t aIngress = 0xD7D066BEA33DE649ULL; std::uint64_t aCarry = 0x81AAB7F2B9FD0FCEULL;

    std::uint64_t aWandererA = 0xBD07348AA18C7371ULL; std::uint64_t aWandererB = 0xBAFDAB8FA1A6CE38ULL; std::uint64_t aWandererC = 0xC856A9D3B5EB4006ULL; std::uint64_t aWandererD = 0xE8D91543DABF7573ULL;
    std::uint64_t aWandererE = 0x8EC311885888E068ULL; std::uint64_t aWandererF = 0xF9999AFC452C0791ULL; std::uint64_t aWandererG = 0xA1523331B95E9161ULL; std::uint64_t aWandererH = 0x92F51986A8AA3218ULL;
    std::uint64_t aWandererI = 0xED59D003C000DB9AULL; std::uint64_t aWandererJ = 0x8BBE0B1392612BAFULL; std::uint64_t aWandererK = 0x8E66FC91F9783325ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xAA73201FDFEC97A5ULL;
        aCarry = 0x8E6B69DFE4D85C7DULL;
        aWandererA = 0xD46ED9841C1EBC11ULL;
        aWandererB = 0xFC138E9FAF643636ULL;
        aWandererC = 0xECF7E6FDC78F9036ULL;
        aWandererD = 0x9376708BEFF52EDFULL;
        aWandererE = 0xC4B13755DD315619ULL;
        aWandererF = 0x8D5805A260E859DDULL;
        aWandererG = 0xEF394EABB435138DULL;
        aWandererH = 0xFE5065B9CB6F0F40ULL;
        aWandererI = 0xC6CD8B329A5FAD19ULL;
        aWandererJ = 0x88664D1AB85F091DULL;
        aWandererK = 0xF49BD9BD854D7ECFULL;
    TwistExpander_Menkent_Arx::KDF_A_A(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 pSnow,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    TwistExpander_Menkent_Arx::KDF_A_B(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 pSnow,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    TwistExpander_Menkent_Arx::KDF_A_C(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 pSnow,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

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
    TwistExpander_Menkent_Arx::KDF_A_D(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 pSnow,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

}

void TwistExpander_Menkent::KDF_B(TwistWorkSpace *pWorkSpace,
                                  std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet,
                                  std::uint8_t *pSnow) {
    TwistExpander::KDF_B(pWorkSpace, pNonce, pConstants, pDomainSaltSet, pSnow);
    if ((pWorkSpace == nullptr) || (pConstants == nullptr) ||
        (pDomainSaltSet == nullptr) || (pSnow == nullptr)) { return; }
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
    std::uint64_t aPrevious = 0xB9DFACC70E0B6ABAULL; std::uint64_t aIngress = 0xFB97B2074F40B3F2ULL; std::uint64_t aCarry = 0x8A10D0EB3E93E3FCULL;

    std::uint64_t aWandererA = 0xCE62327F39B3F910ULL; std::uint64_t aWandererB = 0xD407045312CA7C80ULL; std::uint64_t aWandererC = 0x995F3A1E8CC907AAULL; std::uint64_t aWandererD = 0xD7CE7317C2A4311BULL;
    std::uint64_t aWandererE = 0xE1B7FD773B662936ULL; std::uint64_t aWandererF = 0x9D6757B86FDE6B6DULL; std::uint64_t aWandererG = 0x9C4D66BD85502898ULL; std::uint64_t aWandererH = 0xCA9F72F41135592CULL;
    std::uint64_t aWandererI = 0xBD67519F7AF2C753ULL; std::uint64_t aWandererJ = 0xC33E37B6D93BE0E4ULL; std::uint64_t aWandererK = 0xD01AECEE12AA2DD1ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xA520E8DB9AD4633DULL;
        aCarry = 0xCFCE8C499BBAC5E0ULL;
        aWandererA = 0xC40510ABACC52C8BULL;
        aWandererB = 0xF163C41C7985E64EULL;
        aWandererC = 0xE957F8747CDB46E8ULL;
        aWandererD = 0xE393FC160786B20DULL;
        aWandererE = 0x94D76F158E849ECAULL;
        aWandererF = 0x8E16663D969A4009ULL;
        aWandererG = 0x8FE40EE4F9223F79ULL;
        aWandererH = 0xF763BA87D7086B8CULL;
        aWandererI = 0xAC08248055BB369DULL;
        aWandererJ = 0xC044BAF6E5091378ULL;
        aWandererK = 0xA5129552648C72F9ULL;
    TwistExpander_Menkent_Arx::KDF_B_A(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 pSnow,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    TwistExpander_Menkent_Arx::KDF_B_B(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 pSnow,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    TwistExpander_Menkent_Arx::KDF_B_C(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 pSnow,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

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
    TwistExpander_Menkent_Arx::KDF_B_D(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 pSnow,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

}

void TwistExpander_Menkent::KDF_C(TwistWorkSpace *pWorkSpace,
                                  std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet,
                                  std::uint8_t *pSnow) {
    TwistExpander::KDF_C(pWorkSpace, pNonce, pConstants, pDomainSaltSet, pSnow);
    if ((pWorkSpace == nullptr) || (pConstants == nullptr) ||
        (pDomainSaltSet == nullptr) || (pSnow == nullptr)) { return; }
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
    std::uint64_t aPrevious = 0xD7022BC399EDFED6ULL; std::uint64_t aIngress = 0xFCBF0EC916E6999CULL; std::uint64_t aCarry = 0xC0DC2862BA68EC72ULL;

    std::uint64_t aWandererA = 0xD381DE49DC2993CDULL; std::uint64_t aWandererB = 0xDC051DE6FE0B1E5FULL; std::uint64_t aWandererC = 0xEE0B757A0C5C0CDDULL; std::uint64_t aWandererD = 0xBFA9E82229A13058ULL;
    std::uint64_t aWandererE = 0xB21C5236F8341BD5ULL; std::uint64_t aWandererF = 0xA63506C6FA279CB9ULL; std::uint64_t aWandererG = 0xE4E189B8B5348665ULL; std::uint64_t aWandererH = 0x84A25A896865E202ULL;
    std::uint64_t aWandererI = 0x8D1204192DECE506ULL; std::uint64_t aWandererJ = 0xA05EB66633E54148ULL; std::uint64_t aWandererK = 0xC01AFA34844D8E9BULL;

    // [kdf-c]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x908197E39F491049ULL;
        aCarry = 0x97F84C1DC2074920ULL;
        aWandererA = 0xCAC329D894D94F4AULL;
        aWandererB = 0xB73444F5203B2FF8ULL;
        aWandererC = 0x95A386A8FA850802ULL;
        aWandererD = 0x8391547AA058F156ULL;
        aWandererE = 0xADB3D0BDDBF971F6ULL;
        aWandererF = 0x9FD5087CCB69A708ULL;
        aWandererG = 0xDA8A75081366FC65ULL;
        aWandererH = 0x8C0A9D1C0277F1BFULL;
        aWandererI = 0x8D5316B738A19A1CULL;
        aWandererJ = 0xC47DE1B2CB55FE2EULL;
        aWandererK = 0xFA6215E751911EB2ULL;
    TwistExpander_Menkent_Arx::KDF_C_A(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 pSnow,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    TwistExpander_Menkent_Arx::KDF_C_B(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 pSnow,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    TwistExpander_Menkent_Arx::KDF_C_C(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 pSnow,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

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
    TwistExpander_Menkent_Arx::KDF_C_D(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 pSnow,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

}

void TwistExpander_Menkent::KDF_D(TwistWorkSpace *pWorkSpace,
                                  std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet,
                                  std::uint8_t *pSnow) {
    TwistExpander::KDF_D(pWorkSpace, pNonce, pConstants, pDomainSaltSet, pSnow);
    if ((pWorkSpace == nullptr) || (pConstants == nullptr) ||
        (pDomainSaltSet == nullptr) || (pSnow == nullptr)) { return; }
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
    std::uint64_t aPrevious = 0x99250959CF31FD73ULL; std::uint64_t aIngress = 0xDE348A52E0004A57ULL; std::uint64_t aCarry = 0xA1C013DC7B5AD583ULL;

    std::uint64_t aWandererA = 0xB2513E90F1A8F62FULL; std::uint64_t aWandererB = 0xA97C9568575B8075ULL; std::uint64_t aWandererC = 0xF86C726CC479C25BULL; std::uint64_t aWandererD = 0x9911F6E42286AF7EULL;
    std::uint64_t aWandererE = 0xCCFB7BD1813BA392ULL; std::uint64_t aWandererF = 0xA1AEB85A419AABB2ULL; std::uint64_t aWandererG = 0x85B21117F7E2A109ULL; std::uint64_t aWandererH = 0x8E736E3E281A3903ULL;
    std::uint64_t aWandererI = 0xCB409B13E90CD388ULL; std::uint64_t aWandererJ = 0x893487E60D12F582ULL; std::uint64_t aWandererK = 0xF141CD37695DDC43ULL;

    // [kdf-d]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xF7ACC3FDC60FE730ULL;
        aCarry = 0xC4BD09789F61FED6ULL;
        aWandererA = 0xA070F249B2C1A234ULL;
        aWandererB = 0xEB20894E65305D8BULL;
        aWandererC = 0x933AFFE06F62E46DULL;
        aWandererD = 0xCB5BD9C04A910E49ULL;
        aWandererE = 0xE7054D5D36492AB4ULL;
        aWandererF = 0xC02833BE06D6B89FULL;
        aWandererG = 0xCE35C0ADABCEB589ULL;
        aWandererH = 0xC2BED981C8B6B763ULL;
        aWandererI = 0xDFB9644908882B61ULL;
        aWandererJ = 0xA96EEC1A1E9DD622ULL;
        aWandererK = 0xD8E2F21470C9FEC2ULL;
    TwistExpander_Menkent_Arx::KDF_D_A(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 pSnow,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    TwistExpander_Menkent_Arx::KDF_D_B(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 pSnow,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    TwistExpander_Menkent_Arx::KDF_D_C(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 pSnow,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

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
    TwistExpander_Menkent_Arx::KDF_D_D(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
                 pSnow,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

}

void TwistExpander_Menkent::Seed(TwistWorkSpace *pWorkSpace,
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
    mDomainBundleInbuilt.mKeyRotateSalts = kKeyRotateSalts;
    mDomainBundleInbuilt.mKeyRotateConstants = kKeyRotateConstants;
    mDomainBundleInbuilt.mKeySpawnSalts = kKeySpawnSalts;
    mDomainBundleInbuilt.mKeySpawnConstants = kKeySpawnConstants;
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
    std::uint64_t aPrevious = 0xA510072C53E6ED03ULL;
    std::uint64_t aIngress = 0xE37C68889488ED8EULL;
    std::uint64_t aCarry = 0x9CD2413C7D95319FULL;

    std::uint64_t aWandererA = 0x840918DBE2770422ULL;
    std::uint64_t aWandererB = 0x9BF4A42D38907529ULL;
    std::uint64_t aWandererC = 0xAE4DFE9BF0CA89A9ULL;
    std::uint64_t aWandererD = 0xDA65DB9AD1370771ULL;
    std::uint64_t aWandererE = 0xE21F7698710A35CAULL;
    std::uint64_t aWandererF = 0x914946228A49816DULL;
    std::uint64_t aWandererG = 0x88F241A1EF6564B2ULL;
    std::uint64_t aWandererH = 0xC4FC4E360AE810AEULL;
    std::uint64_t aWandererI = 0x92AC890B8572F710ULL;
    std::uint64_t aWandererJ = 0xB83BE3772833D3BEULL;
    std::uint64_t aWandererK = 0x8CD2AADE1C6898DDULL;

    // [seed]
    ////////////////////////////////////////////////////////
    ////////        KeyRotate
    ////////
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateConstants), &(mDomainBundleInbuilt.mKeyRotateSalts), pSnowLaneA);
    ////////
    pFarmSalt->Derive(aHeartLaneA, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aHeartLaneB, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aHeartLaneC, mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltF);
    ////////
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateConstants));
    ////////
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateConstants), &(mDomainBundleEphemeral.mKeyRotateSalts), pSnowLaneA);
    ////////
    // wood lanes to pWorkSpace->mDomainBundle
    pFarmSalt->Derive(aWoodLaneA, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWoodLaneB, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWoodLaneC, pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeyRotateConstants));
    ////////
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateConstants), &(mDomainBundleEphemeral.mKeyRotateSalts), pSnowLaneA);
    ////////
    // crystal lanes to mDomainBundleEphemeral
    pFarmSalt->Derive(aCrystalLaneA, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aCrystalLaneB, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aCrystalLaneC, mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeyRotateConstants));
    ////////
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateConstants), &(mDomainBundleEphemeral.mKeyRotateSalts), pSnowLaneA);
    ////////
    // poison lanes to pWorkSpace->mDomainBundle
    pFarmSalt->Derive(aPoisonLaneA, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aPoisonLaneB, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aPoisonLaneC, pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aPoisonLaneD, &(pWorkSpace->mDomainBundle.mKeyRotateConstants));
    ////////
    TwistSquash::SquashC(aPoisonLaneA, aPoisonLaneB, aPoisonLaneC, aPoisonLaneD, pWorkSpace->mDomainLaneKeyRotate);
    ////////
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        KeySpawn
    ////////
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnConstants), &(mDomainBundleInbuilt.mKeySpawnSalts), pSnowLaneD);
    ////////
    pFarmSalt->Derive(aHeartLaneA, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aHeartLaneB, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aHeartLaneC, mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltF);
    ////////
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnConstants));
    ////////
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnConstants), &(mDomainBundleEphemeral.mKeySpawnSalts), pSnowLaneD);
    ////////
    // wood lanes to pWorkSpace->mDomainBundle
    pFarmSalt->Derive(aWoodLaneA, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWoodLaneB, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWoodLaneC, pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnConstants));
    ////////
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnConstants), &(mDomainBundleEphemeral.mKeySpawnSalts), pSnowLaneD);
    ////////
    // crystal lanes to mDomainBundleEphemeral
    pFarmSalt->Derive(aCrystalLaneA, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aCrystalLaneB, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aCrystalLaneC, mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeySpawnConstants));
    ////////
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnConstants), &(mDomainBundleEphemeral.mKeySpawnSalts), pSnowLaneD);
    ////////
    // poison lanes to pWorkSpace->mDomainBundle
    pFarmSalt->Derive(aPoisonLaneA, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aPoisonLaneB, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aPoisonLaneC, pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aPoisonLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnConstants));
    ////////
    TwistSquash::SquashB(aPoisonLaneA, aPoisonLaneB, aPoisonLaneC, aPoisonLaneD, pWorkSpace->mDomainLaneKeySpawn);
    ////////
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Seed
    ////////
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneB);
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
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneB);
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
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneB);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneB);
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
    TwistSquash::SquashC(aPoisonLaneA, aPoisonLaneB, aPoisonLaneC, aPoisonLaneD, pWorkSpace->mDomainLaneSeed);
    ////////
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Twist
    ////////
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneC);
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
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneC);
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
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneC);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneC);
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
    TwistSquash::SquashA(aPoisonLaneA, aPoisonLaneB, aPoisonLaneC, aPoisonLaneD, pWorkSpace->mDomainLaneTwist);
    ////////
    ////////
    ////////
    ////////////////////////////////////////////////////////
    TwistExpander_Menkent_Arx::Seed_A(pWorkSpace,
                 pNonce,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    TwistExpander_Menkent_Arx::Seed_B(pWorkSpace,
                 pNonce,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    TwistExpander_Menkent_Arx::Seed_C(pWorkSpace,
                 pNonce,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

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
    TwistExpander_Menkent_Arx::Seed_D(pWorkSpace,
                 pNonce,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    TwistExpander_Menkent_Arx::Seed_E(pWorkSpace,
                 pNonce,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    TwistExpander_Menkent_Arx::Seed_F(pWorkSpace,
                 pNonce,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

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
    TwistExpander_Menkent_Arx::Seed_G(pWorkSpace,
                 pNonce,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    TwistExpander_Menkent_Arx::Seed_H(pWorkSpace,
                 pNonce,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    TwistExpander_Menkent_Arx::Seed_I(pWorkSpace,
                 pNonce,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

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
    TwistExpander_Menkent_Arx::Seed_J(pWorkSpace,
                 pNonce,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    TwistExpander_Menkent_Arx::Seed_K(pWorkSpace,
                 pNonce,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    TwistExpander_Menkent_Arx::Seed_L(pWorkSpace,
                 pNonce,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

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
    TwistExpander_Menkent_Arx::Seed_M(pWorkSpace,
                 pNonce,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    TwistExpander_Menkent_Arx::Seed_N(pWorkSpace,
                 pNonce,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    //
    // [KEY — sixteen key rows, lane splits A-P]
    //
    TwistExpander_Menkent_Arx::KEY(pWorkSpace,
                 pNonce,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    FoldSeed(pWorkSpace, pDestination);
    GrowKeyA(pWorkSpace,
             &aPrevious,
             &aIngress,
             &aCarry,
             &aWandererA,
             &aWandererB,
             &aWandererC,
             &aWandererD,
             &aWandererE,
             &aWandererF,
             &aWandererG,
             &aWandererH,
             &aWandererI,
             &aWandererJ,
             &aWandererK);
    GrowKeyB(pWorkSpace,
             &aPrevious,
             &aIngress,
             &aCarry,
             &aWandererA,
             &aWandererB,
             &aWandererC,
             &aWandererD,
             &aWandererE,
             &aWandererF,
             &aWandererG,
             &aWandererH,
             &aWandererI,
             &aWandererJ,
             &aWandererK);
    FoldKeyRows(pWorkSpace);
    pWorkSpace->Zero_PostSeed();
    Zero_PostSeed();
}

void TwistExpander_Menkent::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF5476C69ED6D03CDULL; std::uint64_t aIngress = 0xFDE5F86D3DCBC214ULL; std::uint64_t aCarry = 0xBEE33E3079E4EDF3ULL;

    std::uint64_t aWandererA = 0xE97FAFB07084F778ULL; std::uint64_t aWandererB = 0xE7C491929755D71FULL; std::uint64_t aWandererC = 0xBA1DBC352E8E9F2DULL; std::uint64_t aWandererD = 0xFD55B40889410508ULL;
    std::uint64_t aWandererE = 0xD1822D724B96F2EFULL; std::uint64_t aWandererF = 0x925E7C49FE483CCDULL; std::uint64_t aWandererG = 0x89C19918721A8125ULL; std::uint64_t aWandererH = 0xB8C87A0966051CACULL;
    std::uint64_t aWandererI = 0xF6FC607BECBC7BF6ULL; std::uint64_t aWandererJ = 0xD7E3BB6205B70EBCULL; std::uint64_t aWandererK = 0xD7D6EEE91ABC0B5BULL;

    // [twist]
        aPrevious = 0x976F80D3EC1FF422ULL;
        aCarry = 0xF80B8C2053DACD69ULL;
        aWandererA = 0xEA483D295048B91FULL;
        aWandererB = 0xFE1F2006BFF1133EULL;
        aWandererC = 0xD50791B9BA421493ULL;
        aWandererD = 0xC36809C1E6D2C484ULL;
        aWandererE = 0x9C0A5AC08604435FULL;
        aWandererF = 0xE6FE379B3CCA24C7ULL;
        aWandererG = 0x990C0A7306E28774ULL;
        aWandererH = 0xFBB1FF23087ECC53ULL;
        aWandererI = 0xD6548CB2F5FDCE4BULL;
        aWandererJ = 0xD45567BA60FF2388ULL;
        aWandererK = 0x99571B18F7593AC2ULL;
    TwistExpander_Menkent_Arx::Twist_A(pWorkSpace,
                 pSource,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    TwistExpander_Menkent_Arx::Twist_B(pWorkSpace,
                 pSource,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    TwistExpander_Menkent_Arx::Twist_C(pWorkSpace,
                 pSource,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

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
    TwistExpander_Menkent_Arx::Twist_D(pWorkSpace,
                 pSource,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    TwistExpander_Menkent_Arx::Twist_E(pWorkSpace,
                 pSource,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    TwistExpander_Menkent_Arx::Twist_F(pWorkSpace,
                 pSource,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

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
    TwistExpander_Menkent_Arx::Twist_G(pWorkSpace,
                 pSource,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    TwistExpander_Menkent_Arx::Twist_H(pWorkSpace,
                 pSource,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
                 &aWandererC,
                 &aWandererD,
                 &aWandererE,
                 &aWandererF,
                 &aWandererG,
                 &aWandererH,
                 &aWandererI,
                 &aWandererJ,
                 &aWandererK);

    FoldTwist(pWorkSpace, pDestination);
    GrowKeyA(pWorkSpace,
             &aPrevious,
             &aIngress,
             &aCarry,
             &aWandererA,
             &aWandererB,
             &aWandererC,
             &aWandererD,
             &aWandererE,
             &aWandererF,
             &aWandererG,
             &aWandererH,
             &aWandererI,
             &aWandererJ,
             &aWandererK);
    GrowKeyB(pWorkSpace,
             &aPrevious,
             &aIngress,
             &aCarry,
             &aWandererA,
             &aWandererB,
             &aWandererC,
             &aWandererD,
             &aWandererE,
             &aWandererF,
             &aWandererG,
             &aWandererH,
             &aWandererI,
             &aWandererJ,
             &aWandererK);
    FoldKeyRows(pWorkSpace);
}

void TwistExpander_Menkent::GrowKeyA(TwistWorkSpace *pWorkSpace,
                  std::uint64_t *pPrevious,
                  std::uint64_t *pIngress,
                  std::uint64_t *pCarry,
                  std::uint64_t *pWandererA,
                  std::uint64_t *pWandererB,
                  std::uint64_t *pWandererC,
                  std::uint64_t *pWandererD,
                  std::uint64_t *pWandererE,
                  std::uint64_t *pWandererF,
                  std::uint64_t *pWandererG,
                  std::uint64_t *pWandererH,
                  std::uint64_t *pWandererI,
                  std::uint64_t *pWandererJ,
                  std::uint64_t *pWandererK) {
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
    TwistExpander_Menkent_Arx::GROW_A_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Menkent_Arx::GROW_A_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Menkent_Arx::GROW_A_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mKeyRotateConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mKeyRotateConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mKeyRotateConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mKeyRotateConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mKeyRotateConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mKeyRotateConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mKeyRotateConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mKeyRotateConstants.mMatrixArgD;
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
    TwistExpander_Menkent_Arx::GROW_A_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Menkent::GrowKeyB(TwistWorkSpace *pWorkSpace,
                  std::uint64_t *pPrevious,
                  std::uint64_t *pIngress,
                  std::uint64_t *pCarry,
                  std::uint64_t *pWandererA,
                  std::uint64_t *pWandererB,
                  std::uint64_t *pWandererC,
                  std::uint64_t *pWandererD,
                  std::uint64_t *pWandererE,
                  std::uint64_t *pWandererF,
                  std::uint64_t *pWandererG,
                  std::uint64_t *pWandererH,
                  std::uint64_t *pWandererI,
                  std::uint64_t *pWandererJ,
                  std::uint64_t *pWandererK) {
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
    TwistExpander_Menkent_Arx::GROW_B_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Menkent_Arx::GROW_B_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Menkent_Arx::GROW_B_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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
    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mKeySpawnConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mKeySpawnConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mKeySpawnConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mKeySpawnConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mKeySpawnConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mKeySpawnConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mKeySpawnConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mKeySpawnConstants.mMatrixArgD;
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
    TwistExpander_Menkent_Arx::GROW_B_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
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

void TwistExpander_Menkent::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 18 of 33
    // Exploration cases: 0
    // Structural maximin 512 / 674; family total 9150
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
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7969U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7789U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4188U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8149U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1735U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1375U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1960U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1690U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1645U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1555U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1780U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 47U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 18 of 33
    // Exploration cases: 0
    // Structural maximin 517 / 674; family total 9179
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
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7069U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3468U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7339U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2928U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1105U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 565U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1285U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 610U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1195U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 475U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1015U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 520U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 700U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldSeedControl candidate 18 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1057 / 1248; total 18384
void TwistExpander_Menkent::FoldSeed(TwistWorkSpace *pWorkSpace,
                                      std::uint8_t *pDestination) {
    if ((pWorkSpace == nullptr) || (pDestination == nullptr)) { return; }

    std::uint8_t *aPoisonLaneA = pWorkSpace->mPoisonLaneA;
    std::uint8_t *aPoisonLaneB = pWorkSpace->mPoisonLaneB;
    std::uint8_t *aPoisonLaneC = pWorkSpace->mPoisonLaneC;
    std::uint8_t *aPoisonLaneD = pWorkSpace->mPoisonLaneD;

    std::uint8_t *aDestinationLaneA = pDestination + (0U * W_KEY);
    std::uint8_t *aDestinationLaneB = pDestination + (1U * W_KEY);
    std::uint8_t *aDestinationLaneC = pDestination + (2U * W_KEY);
    std::uint8_t *aDestinationLaneD = pDestination + (3U * W_KEY);
    std::uint8_t *aDestinationLaneE = pDestination + (4U * W_KEY);
    std::uint8_t *aDestinationLaneF = pDestination + (5U * W_KEY);
    std::uint8_t *aDestinationLaneG = pDestination + (6U * W_KEY);
    std::uint8_t *aDestinationLaneH = pDestination + (7U * W_KEY);
    std::uint8_t *aDestinationLaneI = pDestination + (8U * W_KEY);
    std::uint8_t *aDestinationLaneJ = pDestination + (9U * W_KEY);
    std::uint8_t *aDestinationLaneK = pDestination + (10U * W_KEY);
    std::uint8_t *aDestinationLaneL = pDestination + (11U * W_KEY);
    std::uint8_t *aDestinationLaneM = pDestination + (12U * W_KEY);
    std::uint8_t *aDestinationLaneN = pDestination + (13U * W_KEY);
    std::uint8_t *aDestinationLaneO = pDestination + (14U * W_KEY);
    std::uint8_t *aDestinationLaneP = pDestination + (15U * W_KEY);

    static_assert((S_BLOCK / W_KEY) == 16,
                  "FoldSeed expects sixteen key-width chunks per lane.");

    //
    // FoldSeed — Chunk A
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1758U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 115U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2006U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 993U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1083U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1983U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 385U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 768U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 93U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1173U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 160U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1668U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1938U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1218U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 453U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2028U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1691U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 543U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 183U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1578U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 340U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1961U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1646U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1871U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1916U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1128U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 273U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1623U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneG[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 678U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 408U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 498U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1038U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneH[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1893U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 138U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1736U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1533U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 363U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 48U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1398U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1443U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneJ[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 588U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 70U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1781U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 228U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneK[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1308U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 948U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 858U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1488U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1353U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1826U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1848U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 250U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 25U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 318U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 903U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneN[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 813U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 295U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 633U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 723U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 205U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1803U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1713U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1263U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldTwistControl candidate 18 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1061 / 1248; total 18331
void TwistExpander_Menkent::FoldTwist(TwistWorkSpace *pWorkSpace,
                                      std::uint8_t *pDestination) {
    if ((pWorkSpace == nullptr) || (pDestination == nullptr)) { return; }

    std::uint8_t *aPoisonLaneA = pWorkSpace->mPoisonLaneA;
    std::uint8_t *aPoisonLaneB = pWorkSpace->mPoisonLaneB;
    std::uint8_t *aPoisonLaneC = pWorkSpace->mPoisonLaneC;
    std::uint8_t *aPoisonLaneD = pWorkSpace->mPoisonLaneD;

    std::uint8_t *aDestinationLaneA = pDestination + (0U * W_KEY);
    std::uint8_t *aDestinationLaneB = pDestination + (1U * W_KEY);
    std::uint8_t *aDestinationLaneC = pDestination + (2U * W_KEY);
    std::uint8_t *aDestinationLaneD = pDestination + (3U * W_KEY);
    std::uint8_t *aDestinationLaneE = pDestination + (4U * W_KEY);
    std::uint8_t *aDestinationLaneF = pDestination + (5U * W_KEY);
    std::uint8_t *aDestinationLaneG = pDestination + (6U * W_KEY);
    std::uint8_t *aDestinationLaneH = pDestination + (7U * W_KEY);
    std::uint8_t *aDestinationLaneI = pDestination + (8U * W_KEY);
    std::uint8_t *aDestinationLaneJ = pDestination + (9U * W_KEY);
    std::uint8_t *aDestinationLaneK = pDestination + (10U * W_KEY);
    std::uint8_t *aDestinationLaneL = pDestination + (11U * W_KEY);
    std::uint8_t *aDestinationLaneM = pDestination + (12U * W_KEY);
    std::uint8_t *aDestinationLaneN = pDestination + (13U * W_KEY);
    std::uint8_t *aDestinationLaneO = pDestination + (14U * W_KEY);
    std::uint8_t *aDestinationLaneP = pDestination + (15U * W_KEY);

    static_assert((S_BLOCK / W_KEY) == 16,
                  "FoldTwist expects sixteen key-width chunks per lane.");

    //
    // FoldTwist — Chunk A
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 904U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1174U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 656U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 859U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1624U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 949U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 476U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 296U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1331U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 836U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1354U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1714U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1804U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 701U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1309U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 994U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1489U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1511U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1016U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 251U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1399U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1264U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1196U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 971U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2029U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 71U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 206U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 341U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneG[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 926U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1061U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1286U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 746U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneH[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1444U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 611U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1894U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 566U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1151U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 791U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1376U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 814U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneJ[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1939U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1466U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1106U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1579U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneK[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 161U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1759U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1984U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1669U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1556U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1084U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 386U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1039U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1849U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1534U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1421U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 521U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneN[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 431U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 116U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1219U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1601U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 26U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 881U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1241U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1129U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Menkent::kKeyRotateSalts = {
    {
        {
            0x7E0974101A40F358ULL, 0x947DB29127310B82ULL, 0x132D972B18602DDEULL, 0xD3486CDDE2D58130ULL, 
            0x5255F33EC0D04FC9ULL, 0xADA995D70EE9A5A1ULL, 0x0595BEAA08CB6E0AULL, 0xBA6E0459D41CD5B7ULL, 
            0x9476DD95654A44AAULL, 0xC7987C7B7C5B9BF8ULL, 0x642360D9C38666B0ULL, 0x76E4CDB79290D3CCULL, 
            0x918FEC3422713A89ULL, 0xB1B0F18664CC4603ULL, 0xB6294312629DA1ECULL, 0x307594CC7FD447C3ULL, 
            0xA6A57E38DD957A97ULL, 0x1416BA95EE8818B0ULL, 0x249C124094D37232ULL, 0xBB1B650DFE0276B5ULL, 
            0xE761B260858F8143ULL, 0x276125624081AB16ULL, 0x3C8DF3937DC833A0ULL, 0x114812CB61944780ULL, 
            0xA8A965FCE81212CBULL, 0x8F7CFF770AF817D4ULL, 0xB56CF9D9F6F88FB7ULL, 0xF0896271A0CAF664ULL, 
            0xC0CD39A79A27C21FULL, 0xCDE98764D7FDBD3DULL, 0xB821D06F451E97FFULL, 0x9BF36B44C79E9DCBULL
        },
        {
            0xC68AE62294A53B0FULL, 0xEDA50DCA2CAC533CULL, 0x15C2B374A03DD7E3ULL, 0xA56752A880233F3FULL, 
            0x257AC18C264C298AULL, 0xAA437E8F90983AF8ULL, 0x6778BCED7D25E551ULL, 0x4AE7C929460BAE1BULL, 
            0x59761439B9B36F39ULL, 0x37301EB1DEE24F5FULL, 0x6F3691063F863AF9ULL, 0x6F01B3459D7AFD11ULL, 
            0x303732BD7F1B72D8ULL, 0x049F7B3BC41C144EULL, 0xBD1FA471DC318D2DULL, 0xC5842A87C0DAA60EULL, 
            0x436101D4EF11BF7AULL, 0x150EF2923AED4E7DULL, 0x50C2EDB48C8160DEULL, 0x0D473D05B7D42CA2ULL, 
            0x21CDF287CBAF3D2EULL, 0xB7945B88691D8613ULL, 0xFB62A4CFEC95F50FULL, 0xAE8C4DA5AA9BA95DULL, 
            0x847F3F2AB9663F1CULL, 0x0869D228DA563AF2ULL, 0x055DD9884498B334ULL, 0xA6BCDA300D377091ULL, 
            0xE285694D28CC771FULL, 0xC7539181D60B9CBFULL, 0x9CF68DFD91FB78A9ULL, 0x514F7442D09C161DULL
        },
        {
            0x36A9668DCACAF032ULL, 0xD2DF9A5E75108C5EULL, 0xC61B952C7DB5AE13ULL, 0x777EF1C1CD4B9A2FULL, 
            0x792129180FABE04DULL, 0xC08DB01C4530473CULL, 0x17E4BA31CF508CF7ULL, 0x59AE44B76B91E5EFULL, 
            0x615A80A0351BEF25ULL, 0x4CBDEB2B88643205ULL, 0xF226802E65CD6759ULL, 0x263FD58513069877ULL, 
            0x77D9A60E690D3F48ULL, 0xCBBA88F84CE8B91CULL, 0x76BC173EE5900B1EULL, 0x61B4B2261323748DULL, 
            0x20A52B30552C9FBDULL, 0x80A9F6614E29F40FULL, 0xEE7AB8E9CFE673A7ULL, 0x7C39F1AB5DEA74A3ULL, 
            0x2008A67D05D044B9ULL, 0x976267067D9C3E6FULL, 0x657D3CB7F162E762ULL, 0x362296DA65A76512ULL, 
            0x658B93A3107FF8C0ULL, 0x968D7CC13A304D94ULL, 0xC9B31161E1F82759ULL, 0x171D8E7AA019A429ULL, 
            0x4A9BF429AA6B1897ULL, 0x107F9A35C10255C3ULL, 0xC19B52CF5F5E2F50ULL, 0xBAC946B64792ACA8ULL
        },
        {
            0x9C5EA83B0DBBB93EULL, 0x742F8207CDB8830BULL, 0xEDED1FA6489AE370ULL, 0x81B618EF4BCAD227ULL, 
            0x7113F2BF42F40D22ULL, 0xB88A06169CDA32F8ULL, 0xC2E339660C70F8CBULL, 0xDB5C5CC2F306EE9CULL, 
            0xC00D4BD5AF1A3673ULL, 0x205C0ADB3E108682ULL, 0x9ECF0B7515AE307EULL, 0x4E9A51DDB96C6966ULL, 
            0xFBEA1D7F2517E3BEULL, 0x91F21D35818B3DBBULL, 0x188AFE5EDE3B75CEULL, 0x501A3A343F0B55A6ULL, 
            0x27BBFAB267885E07ULL, 0xC01479B5B72DC89AULL, 0xAE9FAA8EB7EF4327ULL, 0xC133C97CAC131825ULL, 
            0x754F6D410A0EE2F9ULL, 0x23E638B7CE399B72ULL, 0x7E08265BC34CB294ULL, 0x527C6460CF791D0BULL, 
            0x30C3D5F480260B48ULL, 0x4F31C07BF532A65AULL, 0x3432D211450D3A72ULL, 0x6883F9643BE0610AULL, 
            0x4B1900AE948F206FULL, 0xBF9415AD1162E80AULL, 0x1460397CB5402F39ULL, 0xC1A2BA1C9F9A3A2BULL
        },
        {
            0x09148F8DD5E13815ULL, 0x7839290936A221C6ULL, 0x6B2E5F53259179ACULL, 0x1BDDC63B32B83CE1ULL, 
            0x761BAC43AFA835BDULL, 0x6C5E23379E801D11ULL, 0xAD36F259CF04B6A2ULL, 0x0460A4E099FEAF50ULL, 
            0xC7FEAB90B183775FULL, 0x03A1B2635C36B52FULL, 0x17D0019E66942FBEULL, 0xF91EE7729DA4AAA2ULL, 
            0x12B3BB0ADEA3FE0AULL, 0x65B62CD7F4BBAA5CULL, 0x73935F53C9EC4CC9ULL, 0xEC92CB543689A14BULL, 
            0x4F7E8272B4832C77ULL, 0x74BA3826096B3E15ULL, 0xCC7C3B553442987DULL, 0xCC075A0B2B46694FULL, 
            0x4D692FAD044ED095ULL, 0x32C5F21A02EB346FULL, 0x970D71211DAF340DULL, 0xAF23D40401E2E736ULL, 
            0x1746E06C52A29F25ULL, 0x1E86C220AC4427F2ULL, 0xF29B98F0161E465FULL, 0xFFD9A7EF996807F0ULL, 
            0x835D7DB0FA8A441CULL, 0xF64D7A673EE9F999ULL, 0x2C287A180F919161ULL, 0xAEB757D807CF4B3EULL
        },
        {
            0x462E74687E0D6D0FULL, 0xDD433002BC11B9FDULL, 0x64D19BDFF6A78EFEULL, 0xEA212FFE6701CF04ULL, 
            0x0F1D0426257EFE36ULL, 0xC07A8D8BE8E5ECA1ULL, 0x600400592A4F20C5ULL, 0x908E925E6CE895F4ULL, 
            0x8D38D219A635878EULL, 0x2BF08E45F20103A0ULL, 0xA66FE44FA6ADAC84ULL, 0xD1DCE83DE6CEF14BULL, 
            0x4134256725604E0EULL, 0x0834585782F224F5ULL, 0x92E0B616C0C2FFDEULL, 0x59BE53F9BAA8D488ULL, 
            0xCB6A19755DFF5050ULL, 0x725D32EEA950DF1BULL, 0x854C495B183B51EEULL, 0x5472F318D60A0B3CULL, 
            0xB6A230AF70BF4920ULL, 0xFF55F7CE6DD7B9ECULL, 0xF0759D9D3420CDC5ULL, 0xB877673612D0669EULL, 
            0x6308F236DE2F1B1EULL, 0x210F97BE889B9306ULL, 0x5E317526EAD3AA50ULL, 0xE17F0DEABA7BD303ULL, 
            0x232C7999A745F23BULL, 0x49F69FC8CB8466A5ULL, 0x96502111896A329EULL, 0xAF45EE7A913672E2ULL
        }
    },
    {
        {
            0xAFD134712D98ED3BULL, 0x141802A582757DC2ULL, 0xFDC7EE17FAD9A86DULL, 0xC752A4677B44D5DFULL, 
            0xA231C1C7C2B628FCULL, 0x6593106403D96E7DULL, 0xFFFD4F8D4949C1B4ULL, 0x28EDF34424D97F8EULL, 
            0xFADC92A11EA5144AULL, 0x3F00E8A392ED3E18ULL, 0xAA5C7B08A2F35FFFULL, 0x7DE25E438481B5FFULL, 
            0xE3FD0CEF364504DFULL, 0x15549937235BAB3DULL, 0x2C826666FA649E17ULL, 0x2AEEEC77DFC58EA5ULL, 
            0x4BD3182A755D1C77ULL, 0x99D466C67BDE92D3ULL, 0x204E8AF8C5BFD6DDULL, 0x672CCD6FCE3709FAULL, 
            0x809EE683438FD804ULL, 0x4F5D1F93323664A1ULL, 0x15C2C924EC73F247ULL, 0x0D3E6F43C4242D0BULL, 
            0x9B421ADA6175FAD3ULL, 0x50F08E0B8178A576ULL, 0x4595E43417F5F500ULL, 0x6916A8E3B378A04BULL, 
            0x123AFA9CD8389BE3ULL, 0x8033298C86561366ULL, 0xA89CFE804C1B702CULL, 0x836BDC5C180F013DULL
        },
        {
            0x15EC588519171CF4ULL, 0x7BCEFA578F2C0C79ULL, 0x86C41088988CCE63ULL, 0x0AD61C659184F7F2ULL, 
            0xF2263DB56E22116DULL, 0xD322C147C7AD87F7ULL, 0x3842F5FA6102E320ULL, 0x16B14BE61E509901ULL, 
            0xEE7CE4E8C39D3077ULL, 0x9BEE2175AEA71640ULL, 0x0D8090D3556049D8ULL, 0x4A996CC3B5C08E3BULL, 
            0x2E8DCE40DA31E969ULL, 0x5BAF671C244C67F5ULL, 0xAFB1E6B42D73CDE8ULL, 0x538B304C2F9ED8BAULL, 
            0x63BDF7AC857A3403ULL, 0x032C5442CD112346ULL, 0xDD8C9E2F7B6525E4ULL, 0x99AB03BA8D523D75ULL, 
            0xC8894339A1DB0C57ULL, 0x26E0CBEBCC0617D6ULL, 0xDAB4AAFE0082C4ECULL, 0x4A9D88D3E2CD1A3DULL, 
            0x4380C307F1A1B683ULL, 0x69C6A25EC84C91DFULL, 0x61CAD01BC31B54F9ULL, 0x1E64BD00EF18989FULL, 
            0x3359A9B93C2A7956ULL, 0xD1955DD9EDCF2F83ULL, 0xD757E0104D5B11CFULL, 0x8B8F247819753577ULL
        },
        {
            0xF307297557B9CF5EULL, 0xED39B2B11C92C3F3ULL, 0xC31186166EC3AFFBULL, 0x96EC7F811A3F655CULL, 
            0x6D482516D77D63DCULL, 0x1F1ADA877C7EAD8BULL, 0x0D0541DACA036C22ULL, 0xF72FBB7693FE2E8DULL, 
            0x293EE15AEFF8EEF2ULL, 0xBE69F672BAAE2CB5ULL, 0xADC323E6349ADC2EULL, 0xA09136775FE589D5ULL, 
            0xA286F92F8AD3C293ULL, 0x9B23484F0F62A1A0ULL, 0x2962D73E67D049EBULL, 0x36E95D9743859B41ULL, 
            0x32D6907A439C6387ULL, 0x399C2C94705FECB6ULL, 0x54C14D83F9573170ULL, 0xFF9FA194BD95A195ULL, 
            0xA46A1DD5469597D2ULL, 0x30624B7F395C3035ULL, 0xA0625682101559FEULL, 0x10401944AD62EC1EULL, 
            0x953A363F8562310FULL, 0x3BC4A5504DBDA4F4ULL, 0xDD23547F035FE3B2ULL, 0xA51A7F1223E7C7DDULL, 
            0x850E6F1D865D9080ULL, 0xEEBB765A83772EB1ULL, 0x044993BE1AE247CCULL, 0xD83C7A3A4167D6B5ULL
        },
        {
            0x4C42F5002A74DFD0ULL, 0x9238CC6109B5D90FULL, 0xA54526B8F079247DULL, 0xCD8396527CB36E32ULL, 
            0x4CD004DFBEE76815ULL, 0x0359BD5FB0AB6AF9ULL, 0xF015EE1615002FEEULL, 0xEDAE286DB40BB193ULL, 
            0xA0676BDB92DFB190ULL, 0x95CD35ADE73F4B8FULL, 0x4356751C5537EB9BULL, 0x7880A7D14A2D3622ULL, 
            0x61424A4996673B89ULL, 0x9CAB86C8D6099437ULL, 0x305ECCFBE377857AULL, 0x2D9C10BD8A1CB2CDULL, 
            0x112020EE9A7FFAB4ULL, 0x58E6BF13A498DF51ULL, 0x02438ABC21B28226ULL, 0x0CB5593FC8EFE6CBULL, 
            0x2BBFBA4EA7E331C6ULL, 0xEE89A4DE099D9185ULL, 0x164081A6F2E087DAULL, 0xCAC6ADFA46906CD4ULL, 
            0x6AE9F3E178B48061ULL, 0x50C17FB210FAA00EULL, 0x7107BAB23569E1F9ULL, 0xAAA1FCD6F4D87B9CULL, 
            0x1FF5BA26E5723821ULL, 0x9370FAD01FA721D5ULL, 0x9A76F42A4C4A9297ULL, 0x9017623717E4A84FULL
        },
        {
            0x065C5407DDC9A86FULL, 0xE897762279F4B37CULL, 0x861B7EEE1C4562D9ULL, 0xE8461015CDB35542ULL, 
            0xE8335EF38BDD6A53ULL, 0x39266420780F6CBEULL, 0x30864188658CCAC2ULL, 0x4CF3FC82D52590C1ULL, 
            0xFFD05E69797C606DULL, 0xDE754FBB550E832FULL, 0x4D3DCA5DB7E3774CULL, 0x144609948D38B6DDULL, 
            0x38B5043A96085D14ULL, 0x61BDA936F3C370CAULL, 0xD99B43146A5D7C91ULL, 0xB2DF66E7B0A003B8ULL, 
            0xEAB9730B3AD1E4AFULL, 0x0FC5056242CA5DBEULL, 0x671733C3152EC1A4ULL, 0x7951580D02894B4DULL, 
            0xB205135383A9D74AULL, 0x1E0BF713BCFE7B7FULL, 0x3E1C6D566C3BC652ULL, 0xB2507644A9C907CCULL, 
            0x22C0E44505A2317FULL, 0x389FD03996014C01ULL, 0x2846FAF097C52175ULL, 0x962DB006D9D3B4EEULL, 
            0xF2EF5CAD8220A0EDULL, 0x286C7E94946A658EULL, 0xEDC65FD0A58CF899ULL, 0xD53F6F69A6D9902BULL
        },
        {
            0x7A4502F411758D21ULL, 0xC0DF269071702AD2ULL, 0x5E58DDEF15311AE7ULL, 0x92D11E90946437A9ULL, 
            0x6563558F6EFE8B48ULL, 0xCF22A236611B6F7EULL, 0x89BDF964BCEAF903ULL, 0x15CE77F8DBCFB750ULL, 
            0xE193A35C69219D9BULL, 0x4A5DB3BDD3D80725ULL, 0x551EB3EEE15EE119ULL, 0xBB947F5BA4FA471CULL, 
            0xF77104C793304419ULL, 0xE58C602E6BE0D5B4ULL, 0x34906CED7E550105ULL, 0xDF2CF809F31B966CULL, 
            0x3F3A3A37AE6CACDCULL, 0xB09DB682C5211DD7ULL, 0xE3727038845EBB79ULL, 0x7C7B9225D115AD33ULL, 
            0x77B34DE009A71548ULL, 0x752F155474F05FA2ULL, 0x6BA93AC21118A9C2ULL, 0xFA63A9735E8BD71BULL, 
            0x3D67ECBA3D0D389DULL, 0x466295D97C6C12C6ULL, 0x40D2CA5A355207C2ULL, 0xBE5A4913D4CA88F0ULL, 
            0x7309DBC0E0F18D15ULL, 0x23E066F739B125E1ULL, 0x1AB35D45A202FF83ULL, 0x0E3E3082C856D2ACULL
        }
    },
    {
        {
            0x8AB596BAA77A7ECEULL, 0x4445068ED53966AAULL, 0x4DF7A0EB0E0A1A50ULL, 0x56B4C50CBEF2FCADULL, 
            0xF080D427FD397F64ULL, 0x113596F6F7C1351FULL, 0xA4463CF3F655F6D2ULL, 0x237ECEF8536CE055ULL, 
            0x82758DEB5FA90E81ULL, 0x9F00BA8FAC6609D3ULL, 0x6162F58D535A78FEULL, 0xE1A3C3C524223323ULL, 
            0x1996B90DB4DF56B3ULL, 0x461748A8E15D8E63ULL, 0xFD9174CAB72F115EULL, 0x60913F9D5C9C52F6ULL, 
            0xBBC149D0FE13C47DULL, 0x482F4AB8623B73CEULL, 0x5B156C7665C90CBDULL, 0xDCBE5C3B8BFF10D0ULL, 
            0x66F088205C410DF2ULL, 0x6A10B49733586C74ULL, 0x9A0B94C659FE3AE6ULL, 0x2043973B6D87F06FULL, 
            0x0CD8206AE72EDC69ULL, 0x53876E4FF8FF079BULL, 0x008190628C710CEEULL, 0x3263D41070FCB425ULL, 
            0x22D3358429F3BF00ULL, 0xB568CE207EF51904ULL, 0x944ED5F64FD94A67ULL, 0x7CAD81FE2EAF3FA4ULL
        },
        {
            0xF98A30B98A65158BULL, 0xD606B7A0316357F6ULL, 0x25F9D895A4528864ULL, 0x6FF145844658D717ULL, 
            0x5C818F27EE9F7B7CULL, 0xF633E15124EA0B52ULL, 0x2AC6D5E75DAD7DADULL, 0x1529938F21DE594CULL, 
            0x0FC8674E30821C85ULL, 0xA7CD002A6378A4F7ULL, 0x7A14D9F86CC98F2EULL, 0xBE21778F486BC73DULL, 
            0x067155C190A80823ULL, 0xB43C4E65996DC839ULL, 0x129C69DF0FDBF0AFULL, 0xB88484AFDC767544ULL, 
            0xA16B7104DC15BA62ULL, 0x729FCC24CB71AA62ULL, 0x37B88EDB3C313063ULL, 0x32752DAD2F9166B1ULL, 
            0xCA619DDE4AD8C8DBULL, 0xFF6FF7FD49ABFA0EULL, 0x6F11E2AE13183C93ULL, 0xF50FEEED4317A3CDULL, 
            0x0E1A5BB94A54C56DULL, 0x816E2E3520FF5AC1ULL, 0x2C4CBD61591F6966ULL, 0x345FEDB7E0350F63ULL, 
            0x321F7C474CB870B9ULL, 0xBF0D1E9AE64BDC85ULL, 0x14662AAFB8D4A42DULL, 0xA06D032BB3DA19FFULL
        },
        {
            0x8AE10029D81B0D12ULL, 0x40E34776CA17D3F3ULL, 0x558741B5F61A504FULL, 0xA11A0C87B4BB8E4BULL, 
            0x911960C96F560545ULL, 0x4E28031378BFA219ULL, 0xA771252ED67E0219ULL, 0x717682D4E5074AFCULL, 
            0x6E993534491EF6FCULL, 0x1290A4B122F58ECAULL, 0x9B8AD50CA7026055ULL, 0x1169FA7FF5D6E692ULL, 
            0x4E1BDDA1C1B7937EULL, 0x8B59F00D20C0FF55ULL, 0xCC3635DC1B9891D2ULL, 0xC4BD4396131CDF0FULL, 
            0x9BE44A7D16684611ULL, 0x188FA46B4704E2E8ULL, 0xE1D17D46F8458870ULL, 0x5D4C6FEB0231B796ULL, 
            0xC229CA62C063A6F3ULL, 0xB5E95273F2787AF6ULL, 0xE68378D436E24E78ULL, 0xE24D3FA2F5CE200DULL, 
            0x0C5A6E1CF553B5B0ULL, 0x169E7BC9E758AA32ULL, 0x8DB08F8BAEFD9ECBULL, 0xE1476CCD3A3F8000ULL, 
            0xCC96D147D6A798FFULL, 0x6A2D5F44EF96A3E6ULL, 0x37E9D228AD30DF79ULL, 0xC1C5D584C7631548ULL
        },
        {
            0x0E0AD4378578334FULL, 0x98CA7511FAD17E99ULL, 0x03C9099AB8E1B0B2ULL, 0x346E96CE6C943D56ULL, 
            0x8C6A4EB59D533D40ULL, 0xA3C6AA56DA778A83ULL, 0xC47EAB07035908C7ULL, 0x76F52FA59FE99762ULL, 
            0x247EC67A8A293387ULL, 0x4A3983C90D648B24ULL, 0x9DA4C28F9FF140CBULL, 0xC242B0A221BF9FECULL, 
            0x3FB52209D6C0349BULL, 0xAC6815A76ECEEAD7ULL, 0x57728C5B62FB1F71ULL, 0xC3385E39B2F69DF5ULL, 
            0x6525DF4412BFBB5CULL, 0xF94030A0CB89CBE6ULL, 0xEA6E492B731B7C49ULL, 0x262FCF6F89897874ULL, 
            0xE604212EDB3F104CULL, 0x646AF645025EFCBCULL, 0x053159F80E696232ULL, 0xD739C0296A0D7686ULL, 
            0x8D7416F6841EDB37ULL, 0x787AFFC7F1D20441ULL, 0x801008848988AFE8ULL, 0xBA9FCB30A9027E75ULL, 
            0x46C46678DE65EEF0ULL, 0xFE3FFD332B7CA454ULL, 0x435FDF56F97910B4ULL, 0x119856375B656CAEULL
        },
        {
            0x524B339A73239759ULL, 0x832B148263CE46DBULL, 0x772B893EE63921AFULL, 0xC58EF0F7B67867A0ULL, 
            0x2C3226557F517CE5ULL, 0x6A5DD9CEC81747DDULL, 0x61C7B172914DA6C5ULL, 0x3FDFBEB4E01CBF16ULL, 
            0x186BDEC08B83DAA6ULL, 0x80B4F22FD0A6B6E7ULL, 0x7DEEBCDF2D1D1353ULL, 0xFDB13A06A355C986ULL, 
            0x25FBC15CD7420C80ULL, 0x72B9E1B8E4D05993ULL, 0x7FC496E8CFC8FF0AULL, 0xBEF24644C8A12B3FULL, 
            0x8C7AC81A2368C37FULL, 0xA9FB3495ED437E9AULL, 0xA32B1379D06BDAB1ULL, 0x077EABF2F8F3594CULL, 
            0x01B7F3AFAC258812ULL, 0x1133E36669A07540ULL, 0x25F20FCE939AFE2BULL, 0x75282680DBFF14FAULL, 
            0x240687CC0852D86DULL, 0x7AC4F5D334BBEC2BULL, 0xC02E307A5D1742BEULL, 0xB7526E047CAAB374ULL, 
            0x1B39596B57A1AFF0ULL, 0xD7D73782FE86AF39ULL, 0xEB0238CF6A77C7CEULL, 0x6EB1A8BEA9A2FDA2ULL
        },
        {
            0xA71824933A18B4E1ULL, 0x1A28CAB6A6BC63C4ULL, 0x78FF4A32C26CBE79ULL, 0x89F48D3BB9442075ULL, 
            0x3C35418BC4076265ULL, 0xDDDD57A56B7D6CF0ULL, 0xBC3EF8A13B4B1C92ULL, 0x34517690F6CA2D06ULL, 
            0x10BCB7A33CBA8383ULL, 0x8119F4F82176A7B5ULL, 0xFB354D783CCC4A05ULL, 0xDAF147E789B391C6ULL, 
            0x19B52600A4E7632FULL, 0xB877318FFDE80323ULL, 0xC85C1D2D87CC5058ULL, 0x6C8C3B1AF3425126ULL, 
            0x34FCDEDC178848C3ULL, 0xDB2AF4465E88F8C3ULL, 0xD297C9816A78A12DULL, 0x6DEC346B28B19F84ULL, 
            0x94FDF02C6A8B8BDAULL, 0xEAEC9AA145289851ULL, 0xD1E8EF942F0A3C26ULL, 0xF681C4759D26ABD6ULL, 
            0x45309119C43D3789ULL, 0x46F3D63703D59527ULL, 0x0D1A99DEAF3A7F80ULL, 0x7E38E7DB679EDABEULL, 
            0x9A54974338C384B9ULL, 0x44124A8B2BF4FB79ULL, 0xEECE2B41F28C05F2ULL, 0x39CE4D716C1195D3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Menkent::kKeyRotateConstants = {
    0xD8A1CE07F758AA38ULL,
    0xF27E50CF385AEAA7ULL,
    0x31499BA29E5347CFULL,
    0xD8A1CE07F758AA38ULL,
    0xF27E50CF385AEAA7ULL,
    0x31499BA29E5347CFULL,
    0x65229C95F5ABB705ULL,
    0xDE4834F084E59D4FULL,
    0x16,
    0xA6,
    0x4F,
    0x90,
    0x0B,
    0x21,
    0x2F,
    0x06
};

const TwistDomainSaltSet TwistExpander_Menkent::kKeySpawnSalts = {
    {
        {
            0xE87CCE928922B27AULL, 0x92DE4A13736481C3ULL, 0xCFC921175951A771ULL, 0xF3CC7E38D76BEFBCULL, 
            0xA9B93BC7355B7466ULL, 0xA8EBE2CB768BE0CDULL, 0xF52533CC7AACA743ULL, 0x8A98CF365E505FF2ULL, 
            0xDE48C406A1AEC1BAULL, 0xAB17DB9C6BC9C463ULL, 0x42D28C4CEECD5F1AULL, 0x6E614CC6027CD15CULL, 
            0x8E8593C9F0035A21ULL, 0x255D478DBF29668DULL, 0x360F1B6A4705DDD1ULL, 0x371B7998D85FC833ULL, 
            0x24415E566C49A6E8ULL, 0xB7BC6932E527DDF9ULL, 0xBAFBA1794C90AEA4ULL, 0xB4CE58F0E5CCE53AULL, 
            0x4E6B91B97D3228FFULL, 0xDD456951EEF0D323ULL, 0x3DB848D9CECDC493ULL, 0x2927B00001CB895CULL, 
            0xFEA0F7F587372238ULL, 0x84237CE744C3D0D5ULL, 0x449ACC7BCE738900ULL, 0xB94338E07889310DULL, 
            0x8CEC74850604F11AULL, 0xC3B717E13647114DULL, 0xEF47D4A088759897ULL, 0x557325C366E77355ULL
        },
        {
            0xB6EDA3D96B365B24ULL, 0xD22632F348D3403CULL, 0x0B2EB47990B3CBBAULL, 0x99057C470E5D590CULL, 
            0x4E381AB2107911DFULL, 0x5BDF39B54E3928EDULL, 0x19133C3ED89D27B7ULL, 0x3867F2B758D0A6FFULL, 
            0x7A9FDC5FFF386F4FULL, 0x0C3E0DC2C9B1BED6ULL, 0x12C2405AB95836DFULL, 0xDD62C452E3B0AA42ULL, 
            0x0D3B805C1E802943ULL, 0x332F0C33F0389260ULL, 0x2DED2498ABC1E3F3ULL, 0x10B9CCAD41E08C5CULL, 
            0x9E28A3E180BB2C3CULL, 0x90BBEFFA1C97849DULL, 0x7180C500A7CD64CEULL, 0xA25C7C73DC0A59BCULL, 
            0xD6721FA8B934B729ULL, 0x672F10521895F276ULL, 0x7FC1C76E13B9078AULL, 0x858A7F4E9D9AE989ULL, 
            0x352A615EF51DEEB5ULL, 0xA55BFE7937121C41ULL, 0xDA5FBCF0712F3E5BULL, 0xD5AE3D1014742419ULL, 
            0xB8096D02A2385927ULL, 0x535CA4399DE3D041ULL, 0xB2EF935D3A68C431ULL, 0xF1ADEE633CA7965BULL
        },
        {
            0xA42A839BDA698B18ULL, 0xF18D9889416D76E5ULL, 0xCF5FA8E2D58EFB19ULL, 0x24A61B6C88074A8DULL, 
            0x45D1530AC00C2E51ULL, 0x1EFA4FAF9436E5C9ULL, 0x64D2A589E55870F8ULL, 0x8DC2BE85E2D9CAE2ULL, 
            0xB19F84A02F2DFD7DULL, 0x497197D028C31222ULL, 0x3721E94947A2B951ULL, 0x79DD6899ECBD56B8ULL, 
            0x0DB090FE122F40F5ULL, 0x14D74BFBC1D26BEAULL, 0x1D524786E5E0BEBCULL, 0x926BADA17BA48255ULL, 
            0x83A70BD276805DACULL, 0xB0E023306F26EC02ULL, 0x7F87BB2581251CF2ULL, 0x2AC41416AFC9FD6CULL, 
            0x0FA43908EE963939ULL, 0xC78EA9D5E310E9BAULL, 0xCDC41B0AFE059868ULL, 0xCC13B6ECE90B3D2BULL, 
            0x7CCB26D9BA0E51BFULL, 0x6FC524F789CDE0C7ULL, 0x48039AD1B9100C32ULL, 0xF6F6A396ED4A8260ULL, 
            0xFFE43F2C881DD05BULL, 0x066F4BAB9A97E2B6ULL, 0xD191B4DDBF125B56ULL, 0x33EAF695EC3A4A7BULL
        },
        {
            0x7A4C95509F4EFF55ULL, 0x5450DCABC6D2C69AULL, 0x9657D218194BF504ULL, 0xD7877D72E4827D3FULL, 
            0x2095CB8338FE4C12ULL, 0xCD180663D21A241EULL, 0x14F24EDD41439D7FULL, 0xE1BF6162960D0E83ULL, 
            0x7D620C0D3238E0DCULL, 0x3DC4D51D9B431ABBULL, 0xD688235771C2DDC2ULL, 0x5D3F47B74C815780ULL, 
            0xB2A2A91E41A9668DULL, 0x69A1D451390CC378ULL, 0xCB699C606732F397ULL, 0x7FEAF9283BDA02C7ULL, 
            0x099CA607185E68B9ULL, 0x1D01193A5547B181ULL, 0x03B72DDFA32FF238ULL, 0xBFF114F04C002CCDULL, 
            0x6496056DD217ABB3ULL, 0xE2C808F6FED0044BULL, 0x6FB8F32DA2FB3C01ULL, 0xD946DD00A23A7E2BULL, 
            0x1E42076DCB1939DEULL, 0x08EBE4E0F7AA1272ULL, 0x2E684F4DA31CB257ULL, 0x1A1F963A7AC755CEULL, 
            0x8A47952AE9168AD2ULL, 0x5D20E2F2048C5B3FULL, 0xCC4F2D2EE5152E9EULL, 0x7A2976479B2D629BULL
        },
        {
            0x823AFD0A31682B03ULL, 0xC3966F3F1579E242ULL, 0x832A08CC7BDBB7E0ULL, 0x69F71B4C9B205359ULL, 
            0x63B01C31CF5ECCE7ULL, 0x5B61A28E80287246ULL, 0x156A6F20BC5E12D0ULL, 0x0A8A90F23D4C996FULL, 
            0x8D46C7C2082452D7ULL, 0xE6FD141EC7E1DC24ULL, 0x80C271715A44C50CULL, 0xABA82D5F93EB06B9ULL, 
            0x6C7B0E3DDAF268B7ULL, 0xBFB971965FFCB7A4ULL, 0xBE980368D0F30916ULL, 0xB47C6303D3F859F2ULL, 
            0x2292690A6C00CEADULL, 0x70E7B046149F1EBDULL, 0x19A37ACEA414C206ULL, 0x5658C060704D3226ULL, 
            0x41DF479976666A3EULL, 0x736DE05BB1420599ULL, 0xFD8741F1F0E5188BULL, 0x4EA2B3F1A77F45DAULL, 
            0x5803A0F3224A4BA9ULL, 0xB207A2DB6E985E02ULL, 0xFC241D769D1B24D9ULL, 0x647D88599C769AEEULL, 
            0x60E4981B6EB65824ULL, 0xBD7EC289C235309BULL, 0x8CD53A40B2CE8DA1ULL, 0x8FEBECD9B8B47EBAULL
        },
        {
            0xA0AF01BB859B0F53ULL, 0xF25231ACA43D0B12ULL, 0x3726684928BAB14CULL, 0x9C18308BD8BFCC91ULL, 
            0xF7015D6BAB930BD9ULL, 0x821B499F86F03AB5ULL, 0xBD617B11CB31D7F3ULL, 0x1F2070901BAF8629ULL, 
            0x0FA4782558814D72ULL, 0xDAB213ABBB5CDC5AULL, 0x0ED9CE1031925DC1ULL, 0x82D873A709EDF776ULL, 
            0xF7FE5F6DF182941FULL, 0x6DB246226BC3E767ULL, 0x95D1879E1E12FEA0ULL, 0x2241B46EB9B4BBE7ULL, 
            0x671090BF632123E5ULL, 0xF723D57B67163170ULL, 0xD460E79F143BA850ULL, 0x7D388DAB9DC999B6ULL, 
            0xE53F1178E08EF4CAULL, 0xFA0830F97384F51BULL, 0x8262583248D296C8ULL, 0xB836AF20434AF6ACULL, 
            0x787E83F209C5939EULL, 0x894B7AE1DB3BE6D3ULL, 0xC3C08D09393CDD8EULL, 0x65601CFE437CDC21ULL, 
            0x3ADDD19EB46B7D49ULL, 0xBF0D0797137BC014ULL, 0xBD510D5863ECE0B9ULL, 0x61FAC7FDBBD5D2D9ULL
        }
    },
    {
        {
            0x2F837D7A0C3114B2ULL, 0x7ABA7E086381D340ULL, 0x77179D98B7BF8678ULL, 0x4D8CB120B08FA3E3ULL, 
            0x655DBFAD0584D74DULL, 0xC77B0A8DEE2B810BULL, 0xD80DFED54DE129A4ULL, 0x8B1993DE6334CC30ULL, 
            0xD364BF282C4E2949ULL, 0x103AC2E1E18D549CULL, 0x20F0620EFB20DDE0ULL, 0x15E0ED9A8ADB92A8ULL, 
            0x6BD907D009920720ULL, 0xB2DAE1CAE89860E8ULL, 0xA433696E34CE65D6ULL, 0x535B6EBFDDCE6285ULL, 
            0xB6B78430DEAFF238ULL, 0xD913B70F751845E1ULL, 0x56EDB00AD31B6074ULL, 0xDE404E69359EB676ULL, 
            0x3E46F3640DC9DC21ULL, 0x10D28CA3FD5C9C03ULL, 0x7924FD2CCABAD4CCULL, 0x2EF48EAC9A854244ULL, 
            0x238329271ECCB2A2ULL, 0xF6FEC492EC9DD781ULL, 0xDE81D1022752B352ULL, 0xECEE043EB828B3CFULL, 
            0xE98A13CFAA3A49B0ULL, 0x5AD86F1615DF5AD7ULL, 0x1EB0F3239DA9AFA5ULL, 0x505FE47F440950DDULL
        },
        {
            0x45428F229685214AULL, 0x7B7F0AC7C0766B5DULL, 0x334DCB0D9F6448A6ULL, 0x10E0D81F70AB1EE5ULL, 
            0x4B5AD6C988C8EE39ULL, 0xFCE24748CE544161ULL, 0x550D7B4FC515E920ULL, 0xC6D7CCCE0014A481ULL, 
            0x53CC2C5CCEA2E4A4ULL, 0x85CE585799778DB8ULL, 0xA5B02576433E6C10ULL, 0x25EF365100C2B2ADULL, 
            0x2F695FFED34A5A9CULL, 0x40D8F9B35DA659E1ULL, 0xC5533C06CECED3F9ULL, 0xE4149886C8A36005ULL, 
            0xBA2D955FD8A3A1CEULL, 0xB2F992D232DE3BA9ULL, 0xB83C41B18A616411ULL, 0x2EBF5DA80DB47C71ULL, 
            0xF6AEFE87835AB266ULL, 0x4CB80FEE3134FAECULL, 0x5F4957B1834F319FULL, 0x7A7826806171C274ULL, 
            0x0287B69B63AF8403ULL, 0x0AF816459C2632A9ULL, 0xBB7C89DE5676AC9BULL, 0x12C4EC7B5A787198ULL, 
            0x470CF8099F45B50DULL, 0x066D12F12EA236C3ULL, 0x50F212F5CC353A1DULL, 0x74BE74CE6FB6574DULL
        },
        {
            0xB53CF6B27DA5DD4FULL, 0x9EB6BAAAF8586BBAULL, 0xF1C926EC3A80F8A3ULL, 0xEFB0E487B04275C7ULL, 
            0x2CC1734B57DF389AULL, 0x6FBDCEFF171C3B1EULL, 0x05716CCEB8E4A367ULL, 0x0B8FFCF6E9596DA1ULL, 
            0xD20843B2656EAA6CULL, 0xBEA05A145908E92FULL, 0x08F08FFE64C8EEBEULL, 0x472FFA4CEA5DC533ULL, 
            0x2E70BF5260E67C88ULL, 0xBA362C4133063CD5ULL, 0x57D1D7D747E80BDBULL, 0x15EB0813FC00DA1BULL, 
            0xE55850AC73CFBE56ULL, 0xE8FCF5B3E7209F18ULL, 0x079A0D2F742BE2CDULL, 0x920660C6F1EB1BEEULL, 
            0x21C7D5F9551FE77DULL, 0xDFE7AB3C16323F00ULL, 0xBA9C579AA809D287ULL, 0xE08A20960A706F1DULL, 
            0xFE94F9D173AC84ABULL, 0x94534B0999B29490ULL, 0xB4F261F0685B02EFULL, 0x13F9424E19009350ULL, 
            0xE68C4FCC7BEA4640ULL, 0x45B7C7ED3295990DULL, 0x75C2BD34E0EA2EA2ULL, 0x4A7AE6B897AE9F54ULL
        },
        {
            0xD7C1E3797AF00EC5ULL, 0xF2220BF0DF231DAAULL, 0x6A86B0472487ABC3ULL, 0xED054B60C76CC79BULL, 
            0xA3E97D611C6A9A76ULL, 0x1BC507386DE45C7CULL, 0xDEB0768AC6688B6FULL, 0x511BABDDADF3DE55ULL, 
            0x7F968834E350EF64ULL, 0x1057C7DE0AEB40A3ULL, 0xC54453D4A19A1E8EULL, 0xBF5A4FFF2FB46AA7ULL, 
            0x2ECC3D61A8866E39ULL, 0x6266956FCEFA7C40ULL, 0xC098499DEEF2E70DULL, 0x5A07843557139D8EULL, 
            0xBB5577C44EE1F5F3ULL, 0x8542BA74A2CBCFEEULL, 0x61B0A09676031B21ULL, 0x9373AAFDB2F1B367ULL, 
            0xADB3257C76E54E90ULL, 0x01FA16DF5E810322ULL, 0xCC9A87E380154C79ULL, 0x9CFF39398254D555ULL, 
            0xCA991894908B88F5ULL, 0x42BE87B4134D8BA9ULL, 0xE0916593130A9A31ULL, 0xF775C55278165135ULL, 
            0xF13B8E1CDD6BCF67ULL, 0x2913063FB676D929ULL, 0x46759B3413317030ULL, 0x5BF7CA41DB770147ULL
        },
        {
            0xC0761D0B363D1755ULL, 0x3D99EB3AAE2222E0ULL, 0x2A185A00807EEA09ULL, 0xDC2AF7EF3C021866ULL, 
            0xA2DD39BA634A4D8FULL, 0xA7649A9BC50A243EULL, 0x47B21BA9338602F5ULL, 0xD5963DE4E2327E45ULL, 
            0xF46B80CDED81FC6AULL, 0x96656D8AD5CDE7BBULL, 0x325460DD65002A4FULL, 0x7C4C084681159277ULL, 
            0x76C72FFF8DA40647ULL, 0x57941CE64177D315ULL, 0xAD0AFE0D1E4EED55ULL, 0x0078109BEB6BF377ULL, 
            0xF9CBA2662D819380ULL, 0x733F4CAD43C1438CULL, 0x3923BA0EEC90C7FEULL, 0x0CE82988A059D5F0ULL, 
            0x90FCFCA0AA4CB404ULL, 0x3B9CBFDE5F6FF676ULL, 0x553A507D2D49F223ULL, 0x3E52B51A0E881ABAULL, 
            0xC9249A643BA739CBULL, 0xA19D03A316256D2AULL, 0xB2A85D75D3ECCE4CULL, 0x59A70851A6B82E34ULL, 
            0xCC645AA25983828AULL, 0xE8E3E9F36DD08D06ULL, 0x44D008A3CE833D29ULL, 0xEABC07AEA96A6404ULL
        },
        {
            0x6824FDE7545253FDULL, 0x9E2A690B10E8FE4DULL, 0x714B60A461A2C36CULL, 0x425009923AF9C2D1ULL, 
            0x6520E9AF7B166452ULL, 0xC763CB0A15D4D51AULL, 0xA15AB42C16961BD4ULL, 0xFB715BCCB2CBE2AFULL, 
            0x997934C14B0B7E52ULL, 0x81B603EAD2F05613ULL, 0x6B92E919C2E6C5EBULL, 0xE0C68D07014EB82FULL, 
            0x075D807E1A36FD75ULL, 0xCA616574B6B9B704ULL, 0x05ECD774CAD1C901ULL, 0x6390F032303C388CULL, 
            0x253F71DC75056C63ULL, 0x2468E6779733BED3ULL, 0xBC2B923D6722A23EULL, 0x70FFC219518A16BFULL, 
            0xEBD210C300BEE8B2ULL, 0x1E7D2E2EE92EC761ULL, 0x27973AFA8C21F331ULL, 0x8265E7C2ADD15BA7ULL, 
            0xAF5E69F08A3D74D1ULL, 0x09664DA69FA85916ULL, 0x0FD7A99ADBCE6858ULL, 0xA28C6A82A4EA30E6ULL, 
            0x5554AE3140554E4EULL, 0x8208313ADFE314B2ULL, 0xEE9E0A3FDC23BD47ULL, 0x9194F1D2E97AC18DULL
        }
    },
    {
        {
            0x5002AA29FA0DB436ULL, 0x1B63B00EF512BE2EULL, 0x7B9A52F8073346A3ULL, 0x92B1D49A6D6B83C6ULL, 
            0x6CFC34F54A168832ULL, 0x0DD18313B086D15CULL, 0x947DA9AAD2A9D3DCULL, 0x527A754DC24CBFE0ULL, 
            0x57711A8F81BDDF7CULL, 0xF12280EC27F63AE6ULL, 0x76E0E4F34B2CCE14ULL, 0x22BF281A9CF69B6BULL, 
            0x9D6DD288E7AAA840ULL, 0x5E30AF54666B9500ULL, 0x377DD4ED0A2C7FCCULL, 0xBCC1C60D2BD77337ULL, 
            0xD6EFEB675FB72B00ULL, 0x7EABCB6912478391ULL, 0xE88BD0D903F6690CULL, 0xDA27E639EE050224ULL, 
            0x9BDEA9F7AAF8AFA4ULL, 0x50C354A0CDE32923ULL, 0xEE4DDAF6596CDE2CULL, 0x40942295A3395D90ULL, 
            0x837C208575BC50D1ULL, 0x3EE7E15872D619D3ULL, 0xD73ED025E6CF9AEAULL, 0xE4460A52B4AC1CA7ULL, 
            0xF1884F1B95DF597AULL, 0x2E726850479FC3EDULL, 0x51A33398B6DC4973ULL, 0x830ED863E53FB008ULL
        },
        {
            0xCE30B85BFD0325F6ULL, 0x4FB5BCC6528FD64FULL, 0xF74732C047EEB9D9ULL, 0xBAA18CEA6B4B1621ULL, 
            0x43FAC518B2EA2EF0ULL, 0x12FBD760243F409FULL, 0x1BC28D10A615E348ULL, 0xA0A427E99DC5F43EULL, 
            0xC973084F1E29CBD0ULL, 0xDD0C562128A59073ULL, 0x61B188BAF247F9A9ULL, 0x69B741549C7F9E78ULL, 
            0xACB657E4C142C131ULL, 0x548A6AE1A5EA956CULL, 0xDABF8958D2654E49ULL, 0x4DDD157D7155FFB1ULL, 
            0x29C86526E3D8A565ULL, 0xA03FA95876E6800AULL, 0x85411AAC594F8350ULL, 0x694D7F909811394EULL, 
            0x96CF414B6C8E66F0ULL, 0x8A5AF3D2CAF5DD71ULL, 0x382551F951B1900CULL, 0x1CBC486585D110CFULL, 
            0xB49B5470F1B0DE9AULL, 0x04179FDE2829D927ULL, 0x69257FEF23CC6FF6ULL, 0x479EB28ED8C080D7ULL, 
            0x5B15756F4FCE201AULL, 0x597D01739EBFDCE7ULL, 0x3984C9A336C406A3ULL, 0x61CBABC73965252AULL
        },
        {
            0x3C57E1513051ECA3ULL, 0x4CC07007DCCD2B06ULL, 0x5401FB9C0FBF93E4ULL, 0xA332B3EB5A957BDBULL, 
            0xF04DE718AC9880C8ULL, 0x5C372939F52910D3ULL, 0xC1992D52C49A989DULL, 0xDE3015AD23AC498EULL, 
            0x5BDE4E2D8426D5DAULL, 0xFA589848A144E264ULL, 0xA90C22A62D57C59FULL, 0xEDA3CD11DAB64B85ULL, 
            0xA279159E8EE19F08ULL, 0x853898A2C1942AD6ULL, 0x23BE25BEA96A4EEDULL, 0x23A06A18B0A6EE55ULL, 
            0xDAA4364169E3EE7EULL, 0x108D79E144B115A0ULL, 0x5D932D5B735E3AA1ULL, 0xADF215CE8CE71C0CULL, 
            0x46DEAB143F3D3846ULL, 0x3F620E54D7910F57ULL, 0x89228BF11FAFC19EULL, 0x8A4E9DBAAC6A2782ULL, 
            0xDEA68C94DB9F63B8ULL, 0x00EE72F112D704CBULL, 0x359BA0D17F6704E9ULL, 0xC0F6533C64A9CF60ULL, 
            0xC875DF6A96C9FB3DULL, 0x0D867D2D7A586ACFULL, 0x5174AF0187653F17ULL, 0x312C6C5C96EDF19AULL
        },
        {
            0x6E9ADDBC672A7021ULL, 0x44D84C893418E6C0ULL, 0xD57A5B2174A03879ULL, 0x8484097F1480D409ULL, 
            0xBB252401C574393DULL, 0x90DDDB7B990BA922ULL, 0xFC584445FD00F23CULL, 0xB14C5E31515DF352ULL, 
            0xDFBDDD0A93502CE6ULL, 0x97858BD946CADD9BULL, 0xE869FD9BF0E0C0D7ULL, 0x70467F0BFD4928DDULL, 
            0xA7F853B859DC9148ULL, 0xD92EF3DAD45C0C59ULL, 0x00CC881E4467472FULL, 0x402AF8690512BCB3ULL, 
            0xD57196B3F766743CULL, 0xC75F46DCC95ACA74ULL, 0xB5135771548B8558ULL, 0x1DE24C2DE7B681B9ULL, 
            0x8C4A3B9148F09D76ULL, 0x28D933B151BE0248ULL, 0x6D3BC266BB3085A2ULL, 0xD4A51E950599C498ULL, 
            0x6B4D2FAF7F681576ULL, 0x3C38D5DCBD715CC9ULL, 0x5570301579AB873EULL, 0x62767BAF856BB4F2ULL, 
            0x420F0A068979935CULL, 0xEAACC1224267483CULL, 0x4CCF9E7F437CADAFULL, 0x2A340A032C3BD904ULL
        },
        {
            0xD17BA96B3A2E9FCBULL, 0x4E58C74B376E36E3ULL, 0xBD44AB537CD6B8CBULL, 0x583D732A6E2F7E82ULL, 
            0xFD7E7EF90CDA3C2BULL, 0x0B8459800D419746ULL, 0xEF896B229171BF47ULL, 0x83A4B8E8514C5AFAULL, 
            0x9F252C4893DDD182ULL, 0x59AD8314CAC264B1ULL, 0x30C40E8E64ABCFE3ULL, 0x0B808B015DD99F85ULL, 
            0x10BBDE2F3E174551ULL, 0xED3F9AB02262FC7CULL, 0x2738B87E148ACB85ULL, 0xF3BFBA937016B98DULL, 
            0x3B385D06F202D6C6ULL, 0xA562F19B687DD6E2ULL, 0x1612F8602850B701ULL, 0xB2CE188550FC78ABULL, 
            0x4F33A9B93724EB15ULL, 0x2037C76231BA01C0ULL, 0xA84FFD9F7EA3E3C5ULL, 0xAE14AAF63862EF03ULL, 
            0x4CFDA221FF9FBCDBULL, 0xE7B8D61FAC6B45DFULL, 0x80B33182869EB9AAULL, 0x3FFDE60E895CCA9CULL, 
            0x18CB1E559F5B8007ULL, 0xE83ECC42B520D492ULL, 0xC29B653E0C2E5FB7ULL, 0xD720E0402DB6B9DBULL
        },
        {
            0x414B418505C74CE0ULL, 0x36AAC9364684F274ULL, 0x09B6C707C8B539DBULL, 0x3BA6892BDC8F3DDEULL, 
            0xDF60DB1734E72BEFULL, 0x58EAF8E1031C826DULL, 0xC4E048EDCA6B59B0ULL, 0x5EDA55FC60A07036ULL, 
            0xB7EE563A8455FC0BULL, 0x8913250ECEB35327ULL, 0xE19FCCC6167BDB99ULL, 0x4EC0188C2A19AC16ULL, 
            0x1C4AA2C269AD3951ULL, 0x2F31421F19906C70ULL, 0x74143D6BC7499C0BULL, 0x193AFC274DA91C81ULL, 
            0xCC6C8577216E943BULL, 0xC0D8D65E91C921D1ULL, 0x74C8625B892FF700ULL, 0xA43B1DCD7053B526ULL, 
            0x2FB4588A57D4F53FULL, 0x80C94E22D7582EFBULL, 0xE41B7EC66439C1C6ULL, 0xE761A3C392706B67ULL, 
            0x7E011263DB728B5BULL, 0xF461DD41EA186D7AULL, 0xD244DECC63EFCA01ULL, 0x990324B09832389EULL, 
            0x00F0DC3D53FE0D32ULL, 0xD958C490C5D7F06BULL, 0xF962BC64F7E9F82AULL, 0xB009989C643C7536ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Menkent::kKeySpawnConstants = {
    0xFD464B983A618CA7ULL,
    0x3D5C0457F6D3A285ULL,
    0x161AEAFC1637C31EULL,
    0xFD464B983A618CA7ULL,
    0x3D5C0457F6D3A285ULL,
    0x161AEAFC1637C31EULL,
    0x5C4B7FB3EB99065FULL,
    0xDACD638902E8D3BBULL,
    0x28,
    0x1A,
    0x88,
    0xF4,
    0xD2,
    0x30,
    0x9F,
    0xD6
};

const TwistDomainSaltSet TwistExpander_Menkent::kSeedSalts = {
    {
        {
            0x3BFDD8B0EE538626ULL, 0x1D9906585B7F7A64ULL, 0x419194F5F492743EULL, 0xEA2A81F0D4A822EAULL, 
            0xE6482D3984ADD5DDULL, 0x7CB89433554F1CFAULL, 0x3C7E2A041A046417ULL, 0xB07FBE6699A0FAB8ULL, 
            0x0A7362080B74023AULL, 0x38273F8ED432A806ULL, 0x7D2326ABD8152792ULL, 0xB9B8EE43C56925BEULL, 
            0x19BFB8004AB8E4EDULL, 0x3152D22F6C394844ULL, 0xC428B0D1AA4C8751ULL, 0x5F095F06A6BD36F8ULL, 
            0x1A845EE5493DF4FCULL, 0xCCA1B6EE19764C08ULL, 0x4C185FEEDFCFF885ULL, 0x5AAD978887BF5212ULL, 
            0x217893D599BAEB3EULL, 0xB72A87623C319390ULL, 0xEF44E41DC973E4FDULL, 0x2DE5825CBAF6B17FULL, 
            0x7E395E6D0F6BD48FULL, 0x66F8D6B40D732F39ULL, 0xC432EF52F4B7EA1BULL, 0xDD6B7F18D4F2A853ULL, 
            0x44482781133C41A2ULL, 0x4B874974B089AA62ULL, 0xA8035DD485C61389ULL, 0x271D16BB4BE793BAULL
        },
        {
            0x8D314EBC6D3BE322ULL, 0x2D887F4C506CA685ULL, 0x7D3ED3587B3FDE73ULL, 0x5681D6F7F11E18B2ULL, 
            0x508C3032249761A9ULL, 0x720793232FD49806ULL, 0xADBB01BF7BC1ACE9ULL, 0x377704D96B88B09BULL, 
            0xF0F8159415163183ULL, 0xD94242E99922E04BULL, 0x85013391DB7ED855ULL, 0xE9D2A36271BAF5B6ULL, 
            0x3541EF0FDE3EA240ULL, 0xC739EBD570A1A127ULL, 0x9B97A0BE2DF079F4ULL, 0xD5D4D25A670A6B39ULL, 
            0x1918036482B97402ULL, 0x451B74755E47A5DCULL, 0x99B2E567A0B25818ULL, 0x0B4ABFAAF3FEB689ULL, 
            0x83DBF285B38A6D77ULL, 0x4DBB914069279643ULL, 0x9D28055727965C4DULL, 0xAD3DDB569B18BFA9ULL, 
            0xD284E729256C77DDULL, 0xD8989EA2593FA1B4ULL, 0x117E5FC13F12F7D6ULL, 0xE1532555B5E5AAB9ULL, 
            0x2A404463367582BBULL, 0xC0BA39C9A45F5A52ULL, 0xFD72F8CD8974A9ACULL, 0x23A8BC48352332A4ULL
        },
        {
            0xE89F4FE8C650448DULL, 0xEC9B95738E7B8D5AULL, 0xE487D9FC83B34746ULL, 0x152E2A450983EB13ULL, 
            0x5FE467FB143D987FULL, 0x74C4A530C65EF4A6ULL, 0x6D0E725308AFBD7DULL, 0xF58AA2F4CFBF0918ULL, 
            0x7DF0F7C15EFD9862ULL, 0x6052E0AB42335F65ULL, 0x378351EE3582F44FULL, 0x644D6F0697789F7BULL, 
            0x527A7658A226FB91ULL, 0x9377330C6813145CULL, 0x43313A9F57B8B82FULL, 0xC0177C13B4FB4487ULL, 
            0x059C59BD7BE80DE1ULL, 0x8387E47AAFD2EF63ULL, 0x01BE484CBE1551BAULL, 0xD65E18650C69CF89ULL, 
            0xB10530FD16F7AAC7ULL, 0x2C1ABF519F5EA180ULL, 0x5FD14E78B1D2E2B8ULL, 0x4E77B9310C69098CULL, 
            0xCA57397126DD9033ULL, 0xFCFCDC79A7B48128ULL, 0x6A86D4D749AA6E78ULL, 0xBE02EDBE60AA4328ULL, 
            0x2187D10DF8C4E4BEULL, 0x8439677B17FD7A07ULL, 0xA7304B584D9F4A39ULL, 0xDA23E2FD668728E7ULL
        },
        {
            0x82376F9722BB0C97ULL, 0x6BA484DF2554A7FEULL, 0x7F0050960502C2C9ULL, 0x31B4896B15989AB0ULL, 
            0x52F73E9472E64607ULL, 0x93E691BC8DEF9682ULL, 0x17D59315F33FF3F5ULL, 0xFE4E40C97B5C232DULL, 
            0x7408242BB4F4979AULL, 0xD95691EF55BA50D9ULL, 0x264B85CAF7D2E401ULL, 0x2D7A065D54B4522DULL, 
            0x46CFF82968F66EB9ULL, 0x0C63866F9A23DB1FULL, 0x89B6C3223BCB8AB1ULL, 0xE1B232F5531B540FULL, 
            0xE29A3549C876C91DULL, 0x2B9824593055AE14ULL, 0xDB45D2C8118C93B8ULL, 0xF81662F1212747CDULL, 
            0x59CFE1971A0B0C24ULL, 0x64DF26679D1E8931ULL, 0x00A1C5F0F3F54965ULL, 0x34777FE07CED6994ULL, 
            0xF558E21D1CC77C58ULL, 0x6387C40A7EF1FF99ULL, 0x8EDF608A950E7598ULL, 0x23411E1430520805ULL, 
            0x54C15294E848EA9FULL, 0x13ED86D64FD56EFCULL, 0xBDD8FA82BC11BAB2ULL, 0xEF90701AF8CD6E0DULL
        },
        {
            0xAD19C69B1486A370ULL, 0x7D8CEAD350DAA2C4ULL, 0x68A6513E87A0C0BDULL, 0x93B3C45AEE9E324DULL, 
            0x43BFBBEE00A86D58ULL, 0xA615FFA754A2227CULL, 0x1A168CC2E77EA768ULL, 0x87204B03C147B298ULL, 
            0xBE124DB7ACC5B99BULL, 0x344148DB8475A2EDULL, 0x79993B7AA2DB718FULL, 0x8B162AB7D212264CULL, 
            0x714C4E0EE911FDD3ULL, 0x3D24AF23B822A473ULL, 0xAB8C1B8381B4B298ULL, 0xB234B6F65D1DFD51ULL, 
            0xA9CDE4BE2C5AA736ULL, 0xAFB1B31BA20E6F89ULL, 0x91F50CEFDCADDF2DULL, 0x5C04AD58E21C0618ULL, 
            0xFE8C3BEAC1C5A108ULL, 0x05C97A52D9CBFB34ULL, 0x422EE50EF9A626C2ULL, 0xC92C156E7D4139DFULL, 
            0x79C0D5A3E43A9CB6ULL, 0xAC64988C04652B3EULL, 0xBCA1E55B98D1CF1FULL, 0xF057F89CC0AEF67EULL, 
            0x068B1E1E6517A578ULL, 0x05EBF57326289FFAULL, 0x30042042942C5E06ULL, 0xC67BB1FCED09840DULL
        },
        {
            0x5C690C6549BBB6CDULL, 0x3A8C529A01912808ULL, 0x10A386342D3CAF80ULL, 0xBD5B494E9EB1FB2BULL, 
            0xD6EE00F03BAC011BULL, 0x108B855E22D9F9C8ULL, 0x5815E78ED5145847ULL, 0x6C45223D23CDFE35ULL, 
            0x9619A6A1D38C3150ULL, 0x7A6088534DEFEBF2ULL, 0x6AA6C476DE6BF8B8ULL, 0xF7CF39F18E6936A2ULL, 
            0x15CBF1A6D2A8BE7FULL, 0xEC8B81F8E4CD078EULL, 0xF2E842A163345264ULL, 0xDE207A3FA1450901ULL, 
            0x0653656765901B79ULL, 0x4D59176FDA293ED4ULL, 0x0270722BC9236695ULL, 0xABABF92D631F8382ULL, 
            0xEB1C4CE485C392D5ULL, 0x1A2665BCF9E9EA3AULL, 0xEB1325AF48671781ULL, 0xE832D95BE8F86B71ULL, 
            0x8BFC3FD05DA8C79BULL, 0xEA7DD5D2A991F806ULL, 0xF8AFD00DB53453ABULL, 0xF94EAA951F4C8DE6ULL, 
            0x2411F8166D56D761ULL, 0xDEC75001D59C083FULL, 0xBC3AFA63D8C6D3B6ULL, 0xC6CFF848B7C28AEBULL
        }
    },
    {
        {
            0xE28AF4571FAC8FDBULL, 0xC60CBAD7A5060869ULL, 0x1ED7C5E0E6EA5079ULL, 0xE21CD14CE7F8DF4DULL, 
            0x295A2AD26334E239ULL, 0x45EFCCA07AF5780CULL, 0x8283DB3191504914ULL, 0x7C3CDCF14B077053ULL, 
            0xDC339E9468964FE2ULL, 0x3497AAAB7738639CULL, 0x8BC968B81EC36020ULL, 0x640E395933E07EF3ULL, 
            0x6F79EB1B69FB1AABULL, 0x29D0B5439444C19CULL, 0x6A427C62E637FD1AULL, 0x2058727098E857B6ULL, 
            0xEEE577F51DE6EF0AULL, 0x51D2AA6E6F5DCCA3ULL, 0xB7C51EF1202056CBULL, 0xD743A4794149B0A8ULL, 
            0x85088E0364ACDA5AULL, 0x24225F3814141719ULL, 0xCBCADA414DAC25B8ULL, 0x26008737152FF7C4ULL, 
            0x02BC6E1A64165700ULL, 0x1E8C8E709058F60CULL, 0x11F715E1B508BC43ULL, 0xCB38209A3ECA6C70ULL, 
            0xCB9F029C007E3631ULL, 0x2ED787FB8846F1F3ULL, 0x2409B1A380424431ULL, 0xE4B4E0A4DAE56DBDULL
        },
        {
            0x99EA604F148E1B14ULL, 0x4468E9F5D75222C1ULL, 0x409666C27832758AULL, 0x91E3C635B68C4B1AULL, 
            0x8001D14339E7A9B4ULL, 0xE78022C9FD2AAE87ULL, 0xCB5655C0F324DF19ULL, 0x530A4D8AF220ADACULL, 
            0x82833799989B602FULL, 0xEE17BB7161C9903DULL, 0x2AB516023F5CEDEDULL, 0x2820DC9AE2909528ULL, 
            0x064F32139BD5E4C0ULL, 0x08E525C6018DEA35ULL, 0x10A9D8214AA3F287ULL, 0xD54B4206CB825D26ULL, 
            0xC1CF18E007A8C14FULL, 0xDBE6A1ED2B3BBDFFULL, 0x22162A2EA00F86A9ULL, 0x69C41E3D4036441FULL, 
            0xD71261E8FB71F029ULL, 0x5B2926BE1ED514BBULL, 0x4DFDD492C20F9F44ULL, 0x7415EBF699486216ULL, 
            0xC37FE0FE2A4192AEULL, 0xF529699EF1515C03ULL, 0x945301D55E7E08B7ULL, 0xEDAFDC484672AB02ULL, 
            0xBEC71D493EC2603BULL, 0xF219CEB0E92E2FC0ULL, 0x3BB93CDFAB207092ULL, 0x3B3BBA75237EAF3BULL
        },
        {
            0xA0D13B15CA20DE9FULL, 0xA2F170D1A15690BEULL, 0x7EAC6FAD4FEF70D0ULL, 0x827D6244AAFA4FEAULL, 
            0x8DEE724D7B333938ULL, 0x534ED1DB7D6922FFULL, 0xBDEC2CC2C5A897EEULL, 0x1574B8E89D541A56ULL, 
            0x517A1E7D2B3B1959ULL, 0xA0963A0E842A67B2ULL, 0x94634961ED10DE3DULL, 0x5198FF3965B34F0AULL, 
            0x902EA80127453F85ULL, 0x1A22E3925A37D101ULL, 0x92C8BC963651E821ULL, 0x68534EB1E8172367ULL, 
            0xB5462E8DC82B9F3FULL, 0xC8A4A6EBC9CC2947ULL, 0x623DD24AB98C069FULL, 0x67C5D4C30642FD32ULL, 
            0x42B30406978708F6ULL, 0x226CFBF4DFF27E6CULL, 0xB1BEB6B71433106CULL, 0x976A02820EB13B6DULL, 
            0xF2CA349FFF356D7EULL, 0x62C05300290898A4ULL, 0x211BD169F4A076A7ULL, 0x03013D7262BEF129ULL, 
            0x92086A43F4475F0BULL, 0x325AD2CD54F4F01DULL, 0x15A23669D3505F02ULL, 0x8A6A3C32EEA1F81CULL
        },
        {
            0x0A4AFEF10820A9F7ULL, 0x684CDCC20CF39DD7ULL, 0xB44A5A4DA5CCB7B9ULL, 0xF7771319689BE33BULL, 
            0xD875D6DDAB443842ULL, 0xE2985CE8CA1E2A60ULL, 0xE8939B3406C70079ULL, 0xA47A804297100F8CULL, 
            0xE6F6A91C1276B477ULL, 0xF64D85071A4C3A89ULL, 0x6FC288144718F039ULL, 0x053648DE791658B8ULL, 
            0x28761650EF5AAF1CULL, 0xA61C7A29DA86DFB8ULL, 0x6F81DAC91B638CE1ULL, 0x025EFA0F7AACEA66ULL, 
            0x8BCB055DD4340844ULL, 0xDC19B2FAAAE4DDA7ULL, 0xFDA0864D5D13C2ADULL, 0x3149AA70366A7E67ULL, 
            0xC7FE8B0D432C99B6ULL, 0x4DE5CA62AB99C1F4ULL, 0x9289B39D59EAF4ABULL, 0xD710D36E96F33627ULL, 
            0xB0A7074C5E3DF8CDULL, 0x6983013F6D85A79BULL, 0x4434B8A3BF7233C2ULL, 0x7BC8606747743B5AULL, 
            0x255D9E6086F06203ULL, 0x48689D537098A9D7ULL, 0xBC1775D05B8BC5E5ULL, 0x4121EEE6297F330DULL
        },
        {
            0xD301CAEF55072BECULL, 0xA0A8D5AD249E96A0ULL, 0x9982B5F8E7FB4290ULL, 0x52168F1E101D5C88ULL, 
            0x5C415557722B698CULL, 0xFCBF258700C2FBE6ULL, 0x383A307E7FB9D90EULL, 0xDE812B293BE8E0D4ULL, 
            0xD12C5FE3B0B36B4AULL, 0xC48DB0C08DE2308BULL, 0xE62280DEBAD9F44BULL, 0x39DF59E26DD99B92ULL, 
            0x131005BE36E7F214ULL, 0x7CF18619F4737E2FULL, 0x87FD333E3C4084BFULL, 0xD5B42C7E4BD3E02DULL, 
            0x980257649BF8A864ULL, 0x1D733D18F83D2EC8ULL, 0x83184A62F75D2946ULL, 0x8D83954624D1E85FULL, 
            0x58FD69E9D1CC6DF3ULL, 0x17A5C3FA91F10BE9ULL, 0x2279B2B3B7895216ULL, 0x3B54B251CE54384EULL, 
            0xF74C1442AAB2145BULL, 0xF3BD27219AA12EA7ULL, 0xB5C456C63B5F8C77ULL, 0x9FBBDFA4806E129EULL, 
            0x90DF66849FEDC754ULL, 0x304CA621005DAC08ULL, 0xC943F99EE7B750B1ULL, 0xA7CA7C24C8B749FEULL
        },
        {
            0x84F5CA7871C3C8ECULL, 0x344105D50BAB1E9CULL, 0xF1A4DEADFC436040ULL, 0x626234E0A9D04770ULL, 
            0x159DF148E3CEFE7AULL, 0x930C913C43FFDE9DULL, 0xF025AE0FFBBA8310ULL, 0x96CBF05C4620CA64ULL, 
            0xE691EED51E37E307ULL, 0xBC670AA6E72AF248ULL, 0xE83EE9E7F44E771CULL, 0x993D2DCD99C46F67ULL, 
            0xC4134E04E2D72B67ULL, 0xF3543F65E0B912FBULL, 0xE32BC4987BDE5109ULL, 0xDF41A2FC9196E928ULL, 
            0xA7F0F53B98A45A20ULL, 0x12EAD9110E41E0D3ULL, 0x70C4FEA9E18A738FULL, 0x361652B9A0B76A7AULL, 
            0x5108A4325BACD5A1ULL, 0x8E374A78E319DD69ULL, 0x28156A2AE5131BD4ULL, 0xBF86B379ADC67711ULL, 
            0x0DB93685EE835CC9ULL, 0xB73AED523FA64D82ULL, 0x00CEA83425D56A40ULL, 0x1CF012155EC69724ULL, 
            0xE387F201F0650B3AULL, 0x907963586293F7EDULL, 0xCD56481DE41F8A5EULL, 0xB1517061A8294BACULL
        }
    },
    {
        {
            0xEE81ED707E635691ULL, 0x29ABA5484EFAD82AULL, 0x0A84671E9847F2A3ULL, 0xEFF5498BA774224EULL, 
            0x10C62DCA254A2806ULL, 0x88B76C036FB43AA1ULL, 0x97A2BE225DE289DCULL, 0x6E68A2FEBA9BAF6AULL, 
            0xEF09A349E488752BULL, 0xD7D5EC9EE79C5AEDULL, 0xC0B531639F8AF53EULL, 0x3FA188DD898F5F9AULL, 
            0x1F623D97E27CE208ULL, 0xBA900CC1E576AA03ULL, 0xF6A0CDD45E10B268ULL, 0x4DE3226B8475AE3EULL, 
            0x492A160437FE01A6ULL, 0x3B611EE62F9E1C70ULL, 0x7010C6795FD8054EULL, 0x89EA387CDC28C06FULL, 
            0xE96770D4735D1DDDULL, 0x27F75C3A60CB5ADCULL, 0xA7BEF7A7CC474A10ULL, 0x8ACAAF708A9E670BULL, 
            0x32C64857D3D3768EULL, 0x4D41C7B3D03A6BC2ULL, 0xCC4232C8F01CAAA8ULL, 0x8902285FB08750DCULL, 
            0x385281EC46F36F3FULL, 0x0B8BA76063F6A6C1ULL, 0x5A552BE47F61EE06ULL, 0x901D869426123F34ULL
        },
        {
            0xD69CA5707764D205ULL, 0x237F750432343C8FULL, 0x1DE51836B86FEFD9ULL, 0x83E7786377E417A1ULL, 
            0x0FABCD0CAC272B19ULL, 0xB1A0DF31618D9151ULL, 0x53E67D51070DCDF2ULL, 0xF26A8A5EBBBAE58FULL, 
            0xD524CCC3E019FF4DULL, 0xE5C212F60948CE52ULL, 0xB9136476A1ED91BAULL, 0x2A43A3AD92D539A5ULL, 
            0x95EEEAC928B74CF8ULL, 0x035510BAB9F5E9DBULL, 0x442A978C2180E6BBULL, 0x06B9429D586C41F6ULL, 
            0x7B57CDCB9A9D3C53ULL, 0xBA233FCA4E9A4F86ULL, 0x830763DCD08D3195ULL, 0xE9A1352C70D4DA32ULL, 
            0xF21D47495FB5E380ULL, 0x48C8224B8D26EB24ULL, 0x7CE25B99CD3240D0ULL, 0x632E33BCFECA67B2ULL, 
            0x0258B648BF333CCAULL, 0xF7865940768296DAULL, 0x4AB1BE7D1C27ACE2ULL, 0x1D6ABC5CAB87B720ULL, 
            0x9A8E442E718811E1ULL, 0xDEFEACF7B740DD52ULL, 0x3767786D0C256DD2ULL, 0xE6AD2E8549728AD2ULL
        },
        {
            0x8D2472ACDAE918B1ULL, 0xA5AA38171CEE52BFULL, 0x188362EDDFCE95F7ULL, 0x3F3CDE2F1D55273FULL, 
            0xE684F546C44FA5C7ULL, 0x57A031BD57840636ULL, 0x4D5B6DB13AC6A281ULL, 0x34E783C165AD4815ULL, 
            0x1AA3F30D3E9BD22FULL, 0x40CAF254B7C2298AULL, 0x92D3729DF54D27B1ULL, 0xA407E5D35DC4C4EEULL, 
            0x01AB2B639B31D0A5ULL, 0x104CD21E3521DAD1ULL, 0x891C5836ECFFB399ULL, 0x6FC7B9D31E29D7CBULL, 
            0x475E21D196D553A7ULL, 0xE5B45F4D31590372ULL, 0xBD98556D3EEF8FFDULL, 0xF845386E061116EEULL, 
            0xD6F4DC011F2F877BULL, 0x77666CDE099EF2D9ULL, 0xD3CB182471B8845AULL, 0x3EDD933AB8B9FC32ULL, 
            0x18591BEAEBA915C0ULL, 0x81983CEE0660C952ULL, 0xF4D8357C2F525D86ULL, 0x85F7E4F2F66612CBULL, 
            0xBD7803C318FC0C22ULL, 0xB3887C10E3572D31ULL, 0x4F591405AF4B2C5EULL, 0x5706E164B68DB490ULL
        },
        {
            0x795238FA3058B101ULL, 0x1E8022E8F546E351ULL, 0x7332C3DE81893786ULL, 0x89FAE3665997D82CULL, 
            0xFA63C507B865C0AFULL, 0xFC41DDC86C098DF5ULL, 0x1C1FDCEE96BC99D2ULL, 0x6AE224CA24060C31ULL, 
            0x1696DCE62754C3ECULL, 0x07F5B45C1A85F148ULL, 0x3B0EDB2B41C33A78ULL, 0xC0040EC76A921702ULL, 
            0x6FAEB8FF73294BD7ULL, 0x51DA1A3EFE637684ULL, 0x84A2106CBC42752BULL, 0x0A2AE2CA28986661ULL, 
            0x893BE891DD9C312BULL, 0x45CDB7AABAE6D05BULL, 0xA4C8F721C2DAD7F4ULL, 0xDBA3016904326F1EULL, 
            0xB887A94B8977E523ULL, 0xA7DE718222BA44B6ULL, 0x33B3FFDAFABEE023ULL, 0x5A3D790E5E7C6F5AULL, 
            0xC07EDA432C3AE56BULL, 0xD5C2E34520892DD8ULL, 0x39C06E37C56A7897ULL, 0x0CFA8CCDF5FBD68CULL, 
            0xE37FB52972E8E86BULL, 0x67E0C8B262485B3CULL, 0x14FF47662541FACDULL, 0xAB8150F056E80BB5ULL
        },
        {
            0x09E285A2D291CB84ULL, 0x05997F9A7BE7C0D8ULL, 0x09023D7DF288CF83ULL, 0x1EEE36AA2CFC9EB9ULL, 
            0x31AD2001C6439A59ULL, 0x67924EA300001E27ULL, 0xCAE64E53657D9126ULL, 0x967FC6E7EAEBFAE8ULL, 
            0x3EC83D95AD818E3BULL, 0x21AB0D33EC00A640ULL, 0x163BFB105835555AULL, 0x5C6005755CC65116ULL, 
            0x65901A3F5A98936BULL, 0x833DFE8436A5CEEAULL, 0x482D44EFD5A48EA2ULL, 0x9414A3D443E12A61ULL, 
            0xD3282CC162B42700ULL, 0x643F804651AC4D15ULL, 0x16EDF01770731564ULL, 0x96686F75F0F0ADB0ULL, 
            0x7652EBBDAC1822F1ULL, 0x0E6AA72A7D31E8AAULL, 0x5D19DFCED09419C2ULL, 0xAFA30343D3B2666DULL, 
            0x0B968D83B4ABD7AFULL, 0x6F73D4D99BD1219AULL, 0xA3F6D53F0A647A0FULL, 0x5C18956CCC7AA43BULL, 
            0x1845674D2448639AULL, 0xA2C671608EFBD85EULL, 0xA52C82FD0253A3FDULL, 0xF4938626230E142AULL
        },
        {
            0xC14214E9A113E557ULL, 0x0BA7BAAF5D73F755ULL, 0xFDE2AAB0E746E8EEULL, 0xCC28AED9C6C807A1ULL, 
            0x4FC72B1AB62B9777ULL, 0x6ED54186AA34EC72ULL, 0x43689D295AE8562FULL, 0xE2EE62BC0B5E63C5ULL, 
            0x31779746B95713F6ULL, 0x6220A32979686EDBULL, 0xFFAA638EFBA00AE9ULL, 0x4E382A4B71FE0362ULL, 
            0x22B8AF47B8D31767ULL, 0x37807F0C6B1036F2ULL, 0xABD6658A7DB1DB74ULL, 0xD812E5D4D8BE7940ULL, 
            0x588E0BA2FA018A23ULL, 0x8E116966D4404925ULL, 0x72E97F34A7A2B1B7ULL, 0xD6A58C66A376C8D5ULL, 
            0xDDFA57621D5A04EFULL, 0xF0669B12A65EE4C9ULL, 0x04947218E4987AB9ULL, 0xE378726AF97D6B41ULL, 
            0xC9061DAC2A3B527DULL, 0x77280F0EF47D5892ULL, 0x3F2C6D964B91763EULL, 0x20593E62EB18B00CULL, 
            0xB0E3CC9417429C2DULL, 0xBFA8D02857EC4DFDULL, 0x0B156F10929D7405ULL, 0xB3EA9DBA26A9686AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Menkent::kSeedConstants = {
    0xF8FE322E6B43DEB4ULL,
    0x431C759D462D32CCULL,
    0x0B11F6A3B9BB50B0ULL,
    0xF8FE322E6B43DEB4ULL,
    0x431C759D462D32CCULL,
    0x0B11F6A3B9BB50B0ULL,
    0xD6C9DA746A1EBF41ULL,
    0x5536DF5BE9F23512ULL,
    0xD4,
    0xF8,
    0xD7,
    0xA4,
    0x34,
    0x32,
    0x42,
    0x68
};

const TwistDomainSaltSet TwistExpander_Menkent::kTwistSalts = {
    {
        {
            0xC70880B6CDEFCC52ULL, 0x70AEBA2678CBB15EULL, 0xD38011CAE6271D3CULL, 0xF8D36BBB7C7806F2ULL, 
            0xF4E43368CD95C465ULL, 0x93CAE3C67C36BA74ULL, 0x1B822E51CC7443BEULL, 0x50917AE6EDC0DC9FULL, 
            0xA1C2B4E871B7C3FBULL, 0xA48ADCDE08CD49D1ULL, 0xB51440F4D2116944ULL, 0x6C26E6AD4EEAA506ULL, 
            0xA70F81BE59800170ULL, 0xC2163E287818EDFEULL, 0xA72C6BACBE82584DULL, 0xF48E5EDB39049E3EULL, 
            0x0D4DE0227EF5C6C6ULL, 0x6B70B746E288271EULL, 0xD3F1FBA11CA13A65ULL, 0x842A08EDECECD654ULL, 
            0xEAF43EAEB6B29A22ULL, 0x9C7D8ACFE5585EB5ULL, 0x332556CA79DC30C5ULL, 0xC299982DF38E08EAULL, 
            0x85D0869C65D277B6ULL, 0x99B95F44252DF342ULL, 0x7C0C0DB252DF649AULL, 0x1BBCAD30776AE951ULL, 
            0x8B4226C2EC747907ULL, 0x84017D0C1933A188ULL, 0x45E65688C7CC9A46ULL, 0xF9B5269AD42EDFF2ULL
        },
        {
            0x6AD67A3CE1F9E282ULL, 0xD39CC6B3FE1AAC4DULL, 0xC55BB45283E5FEC8ULL, 0xFA0BF5478081CFC4ULL, 
            0xADE608047AC0A2C8ULL, 0x66B52BE96C1AAF4BULL, 0xA0479A10DF03C45FULL, 0x6E9B3707EF4597E0ULL, 
            0xD523C28CE10E3480ULL, 0x2C6903B8EC8278DCULL, 0xBDB43F795DB80BCFULL, 0x880626FFA155FA2FULL, 
            0x40599F7EA6F9918DULL, 0x03C82DAF9C65F702ULL, 0xD5EA85E3A7E829E8ULL, 0x7D4698080D2A501BULL, 
            0x22D3026513BD561BULL, 0x51A96221082F8EBFULL, 0x3D8D446A9BA6D920ULL, 0xC8AF7D1DFB09A099ULL, 
            0x3FAF2D0C82AB1DC5ULL, 0x6B89322E1ACDD81AULL, 0xF48D8FCE1C24679AULL, 0x4BE98D38FC8958E5ULL, 
            0x5107510E6F69EC2FULL, 0x68250ADC2F8A6316ULL, 0xDD64D885E6815E72ULL, 0x8A482F8E829E2478ULL, 
            0x8F5A729043E40DC8ULL, 0xE27EAAFAA5A2DAFCULL, 0x1C2170D9E41F901FULL, 0x4F51D4C25678977EULL
        },
        {
            0x27D6DEEFE8B2D46FULL, 0x493261147B81EBB7ULL, 0x56CA13562D6D692BULL, 0xF7A734C2A1634ABDULL, 
            0xE67979968FE85F21ULL, 0xFC94064EF9CD8003ULL, 0x883B0315EA818E74ULL, 0x32B07F30173AF158ULL, 
            0x45BBEAF6623AD0E8ULL, 0x62C26A69C6E8D004ULL, 0xC374D8A496EAC333ULL, 0x3EAAC7F936730BBFULL, 
            0xAFDB071E4B05741CULL, 0x026200C578C7876AULL, 0xA058A7B9B52F2F5DULL, 0x9F07A52B69951EE1ULL, 
            0x03336718085871BFULL, 0xAA9D9B0E67FF8544ULL, 0x2DF4BAADE89FC3C2ULL, 0xFDAAF5F966870E63ULL, 
            0x3683A403D63A3C24ULL, 0xFB8CAA4C95A60EABULL, 0x6E6BE1031162506FULL, 0x8BB235E2CC0554AFULL, 
            0x0F681E68B3A4FD84ULL, 0xAAB698673B120262ULL, 0x65F9B3EA3D11DE2EULL, 0x31DA30F63E44D182ULL, 
            0x56952AEDDAC690A6ULL, 0x147A90DFC8BA3FBDULL, 0xACEC849F230D23A0ULL, 0xAB6F30F2C7531AC2ULL
        },
        {
            0x58EF079D2C76BDDFULL, 0x1479CE4C24CA280BULL, 0xBC8E7B5114B3942FULL, 0xDD341BF957E1CF77ULL, 
            0x8579295F161C12A5ULL, 0x569C356BC34B1C5FULL, 0xEB60E7E8851438A0ULL, 0x36FA9B8E2DE5BE2CULL, 
            0x2A3353A7206DABA1ULL, 0x5E701F4DB97E4F1DULL, 0xE72F53ECD3BF39EDULL, 0x3278CF73BE36C1C4ULL, 
            0xB05F2A2D64D2FC32ULL, 0x6DE5C3EE6DA42740ULL, 0x7C25C2FEEA3B0C9DULL, 0x1CCEB0E5BF6F416FULL, 
            0x3D2AC0B421CB9D77ULL, 0xC62C2188688ECCFBULL, 0xF8206816D1F73064ULL, 0xFD849C23F0B690FAULL, 
            0x4D968679341CE95CULL, 0x72454C6B1EB12D6BULL, 0x3975030B3E8EB665ULL, 0xAACD2B2364E72F35ULL, 
            0x79860866CFFBBF3BULL, 0x90FEBB0BC1D01E2CULL, 0xA0B4710B300F6D87ULL, 0x1123828EEBBAC5EEULL, 
            0xC85A624B26422F4CULL, 0x29345BF7583A763EULL, 0x71B819FDB04093D5ULL, 0x0129DB15C13A98AAULL
        },
        {
            0x92756BB5BC2693F3ULL, 0xCFC486E6C7E3FC76ULL, 0xA190AA623684580FULL, 0xD086F480F778DD28ULL, 
            0xEE70C0CF00996AF6ULL, 0x7FE0D52F0BB68916ULL, 0x6F74F5939BB51402ULL, 0x050A75EEBA29150BULL, 
            0x69E5D74EEAA9FD97ULL, 0x6B1F132D30F6B7D1ULL, 0x7EB9305A1E167BDEULL, 0x4BD8DEFEBEE653B2ULL, 
            0xAA7BD488AE1B381CULL, 0x275D00FC72E6A7A9ULL, 0x838B19283309A9B4ULL, 0xE0E223734ECEBF64ULL, 
            0xA4750D020A34C6F6ULL, 0xA143CA1A9A8196D9ULL, 0x1230ECA5973265BAULL, 0xBD63ED0BF7E71365ULL, 
            0x648CA5DB6CBD76D6ULL, 0x1897CB51ECB8FD52ULL, 0xBE9D25AB3F658B84ULL, 0x170E0B9203FE22F2ULL, 
            0xEC8211E77ADB72C3ULL, 0x672EACF97CA084E1ULL, 0x9D016E8DA9640FB3ULL, 0xC4219D2AA216F356ULL, 
            0xE633953F83187D90ULL, 0xAD15CF6B3DFCA4DDULL, 0x9EDB4A9AD6599891ULL, 0x453A1E587FBAB179ULL
        },
        {
            0x3BE04C6DE30B7C4CULL, 0xB044344708A11CA5ULL, 0xC43A27C7D5BC2635ULL, 0x22456E8D7850652DULL, 
            0x8CE2DFDA67293A48ULL, 0xC1A3391360283FC2ULL, 0xF124BE8270D4D1CCULL, 0x89D6D8968847C7D7ULL, 
            0xC80725EBC3FFF065ULL, 0xB2503D90EBFA56CFULL, 0xFE9EE3E17460E327ULL, 0xAEF922BA9CED69BEULL, 
            0xE71D1A33AE4DB0B7ULL, 0xE70CE4732515544DULL, 0x5B918D6494E75F14ULL, 0x2D811B7130F07933ULL, 
            0xE535F518D81D1D8BULL, 0xB60F9C52ECDD94C9ULL, 0x33E9DD4069E1B0ADULL, 0x7604D2C22E2C227AULL, 
            0xD930BA4C6C0C6E87ULL, 0x5868FFF598F34EC7ULL, 0x0EC7380B43D2B9C9ULL, 0xC63014F5926F6DCAULL, 
            0xD1FB14893BB14D43ULL, 0x73604B64A291F433ULL, 0xFD6B7C88EA0EB80EULL, 0x480E8D2F44FB646CULL, 
            0x23DBCA95DFB3AE5FULL, 0x6A45968A3F61996DULL, 0xB8E3494BC23D74B4ULL, 0xD256C56A29B668FCULL
        }
    },
    {
        {
            0xEBEB23A244517E9FULL, 0x0FDA977A0CF0D424ULL, 0xB2A8E90E2505AC0DULL, 0x6A74953B4AF5B235ULL, 
            0x88CF36E6FCD57E47ULL, 0x3A0FB2F0B7F85B68ULL, 0x0F0C6986486011D4ULL, 0x5138E2C30977E08FULL, 
            0xE69EB6B91D73044CULL, 0xFDE36BAB0BDB3802ULL, 0x344C0FBC579604D8ULL, 0xD8FDD628DAA17F76ULL, 
            0x9DA05114E3B5562FULL, 0x4D87FEF0588F81E5ULL, 0x0B997E0EF2575626ULL, 0x034D86C1F2E7F037ULL, 
            0x3B34D1D9659CF3F7ULL, 0xFB8F0F028BC3A462ULL, 0x0FA4876C4F11A8E3ULL, 0x39808934B66CC48AULL, 
            0x9A3D4B1FA18D7C87ULL, 0x388B8D34E657E5B2ULL, 0x93D9A93EF6C6ADEAULL, 0x87C34C5F125495F1ULL, 
            0x23BB14AE52ADAE54ULL, 0xDF4A983C2677DA12ULL, 0x5A16734336FFA13DULL, 0x5D56E41F492BFD7EULL, 
            0x19ED200336BC58BAULL, 0x8621FCA865000C58ULL, 0xE31C8AF011083FC0ULL, 0x5D6FCEA6A84823A9ULL
        },
        {
            0x3529C94446AF84EFULL, 0x5A1DB6F37F591C4AULL, 0x580C8F35C7D9D2B7ULL, 0xA06F240586611DEEULL, 
            0x7C1DCEAE00E1A76CULL, 0x226437B4AC841C26ULL, 0xF8EC8FCE3D25085BULL, 0xE910D7E758165D5AULL, 
            0x9D7CB11C84BB5770ULL, 0x02CD4DFA5AE4912DULL, 0xAD2AB3E42B73A281ULL, 0xF15237DACD860991ULL, 
            0x2E04B5332881CA4EULL, 0x2BCF528C60A5008FULL, 0x1D1956F9881344F6ULL, 0x4820D90998A2E479ULL, 
            0xAF2F9847844859D0ULL, 0xBA5D64364E2FBC6AULL, 0xFF73779F6031EC79ULL, 0x2ED5FC81861CB244ULL, 
            0x391E07D5560752D7ULL, 0xF10B4E0AEDF95FA4ULL, 0xCA587E141EAE099AULL, 0x1A5A6FD7C37F3C70ULL, 
            0xE9A584A0E083FE2AULL, 0x05F40195D4963BBEULL, 0x08D0C11C3973A0EBULL, 0x21D0CD23C7B40365ULL, 
            0x0F0740ADDB445034ULL, 0x571ACB84FD24E24DULL, 0x177DBF5C73069305ULL, 0x7660C6BE38A645EDULL
        },
        {
            0x7D62BD1C14714CF8ULL, 0x23F54AC1D13EB1B0ULL, 0x2CB5C09339F24C08ULL, 0x669A1B00A2DA9DBCULL, 
            0xB9E5453A1D2FC0BAULL, 0x90210DFF20B70F29ULL, 0xE50CF98E21B5F6DFULL, 0x589DF13B66580E8DULL, 
            0xE92CFB464F5DD64FULL, 0x5EB4A698F24F77CFULL, 0x2168E45A9DA9C155ULL, 0xD62E45ABE461D0E2ULL, 
            0x68E1325D5482AA7DULL, 0xDB517A8665CB9109ULL, 0x40D1127C1400C522ULL, 0xE6FCD836FBF19DA4ULL, 
            0xAF2DC5AAEBF4CCF6ULL, 0x6FB56CC453E02CA5ULL, 0xE1F30DD21578E6FDULL, 0x656E851FE2A874E2ULL, 
            0xA9BD4F674AAB78E2ULL, 0x553B398EFC009C88ULL, 0x992AF8C73CB1A4F7ULL, 0x713BF868A6132A32ULL, 
            0x8BF0BB4FBBE027BDULL, 0xD103607733CAC31BULL, 0xD1980BCE75A3C392ULL, 0x8010B3DBEEA5D8BCULL, 
            0x15F0548A3EC578EDULL, 0xC7AF8CF4F8AEEB53ULL, 0xF1EF16427B439BEAULL, 0xDBC1722B2265EBC0ULL
        },
        {
            0x1CAEEDC379325D24ULL, 0x63D40EB107FAF717ULL, 0x9E723034CF12B80EULL, 0x9745198A87A10C91ULL, 
            0x9A21EFBE29BCCCF1ULL, 0x053DA9B4BB5BFCD2ULL, 0xF999048E5ED6A51AULL, 0xF9F2307566684ADFULL, 
            0xBA26A24AD8D0D93FULL, 0x600C2023EF8E14DDULL, 0x709DCDCFBEA2E66DULL, 0x3C460A2BED04E446ULL, 
            0x7D8C5AD342A9414DULL, 0xC98B52FF7EEE4B2CULL, 0x26A2495CF07BCA8BULL, 0x1C3A6E71AAAF85F1ULL, 
            0x73AD3027A6CB9756ULL, 0x4B4D37A30F07E9A3ULL, 0xF25B66351A18DF39ULL, 0xB59AA4F3130716C4ULL, 
            0x794AD8BD92C94684ULL, 0x5674FD0983FD641BULL, 0x21E7C453C12CE25EULL, 0x1B669206526BA3CAULL, 
            0xA93F2753FAE06786ULL, 0x309BD148A263A5DFULL, 0x56C147E25BBFF734ULL, 0xE03F18EEB29B68D6ULL, 
            0x5CD28187D32E2113ULL, 0x3F6F072CB639F9B2ULL, 0x5748EC0CA0E4E4F6ULL, 0x3D01FB46EC54D042ULL
        },
        {
            0x8B00D031E8B1B533ULL, 0xCB855A37B94B8FAFULL, 0x3FA1779AD9D12F3AULL, 0x1612876639642AF8ULL, 
            0xC7B2DD0D682514AEULL, 0x8545689FDFB24A71ULL, 0x022E8A2682C5BEF8ULL, 0x3DA53E2B84BC7896ULL, 
            0x393D007E6AA63F4CULL, 0xD98713AE81E51FF4ULL, 0x43F6B43439C6409EULL, 0x4CF86AA47A63C4FAULL, 
            0xFB2918D2C4F5C11DULL, 0x9BEB08E7C7DBC161ULL, 0xF09FEB6C23FC7FB8ULL, 0xF2B790F87966CB1BULL, 
            0x933E27C5DDE9632DULL, 0x5B8177AC07E3B16AULL, 0x4742BE054430F0C1ULL, 0xCE34D3C6BA4BB5B1ULL, 
            0x6BC9C1CE343363EFULL, 0x8C3A855502A7963FULL, 0xB6B8BF8AD52BC38EULL, 0x541F92135674C1C5ULL, 
            0x116A455C8E5F4EE8ULL, 0xDD8B4816DC222D20ULL, 0xA4D46F15627CC3C6ULL, 0x68E465D5BB672EF6ULL, 
            0x78D13BD9470C3A85ULL, 0x5CBC954D76246519ULL, 0x2481B3D5180A87B5ULL, 0xCC3C52A1158F23A1ULL
        },
        {
            0xE16FC2F944FEB5B2ULL, 0xEA06AEF2CBFD334EULL, 0x7C16ED6DBDD04CF9ULL, 0x9247AD0A03AFB14DULL, 
            0x51418D6EC171FF40ULL, 0xEAD3D23F2DD9D060ULL, 0xB8A581DB0ECD30B5ULL, 0x6D182368DE49E934ULL, 
            0x8EFB02E88FF5083DULL, 0xC092B9730AEA2D8AULL, 0xCB3E9FBC896367F1ULL, 0x886524472C995765ULL, 
            0xE579EC6C4A95B57AULL, 0xFF8AD66176114734ULL, 0xA80A8DFF0379A3A4ULL, 0xC08480B2A96BDF72ULL, 
            0xB4AA4E9052EC8A2FULL, 0xCF60DD696F02E8BCULL, 0xAF69108A00A86065ULL, 0x12DE9D3FDFEE4233ULL, 
            0x5CE342F2B6633518ULL, 0x2C43AE10EBF738F8ULL, 0xB9E2731A13685D60ULL, 0x77CB1DC6ED826996ULL, 
            0xC21526865E290348ULL, 0xDF9C9FA25038AD9EULL, 0xE00ED7C0D2C03C3FULL, 0x0D74F20DC142B9ABULL, 
            0x6A3B511E54A01770ULL, 0xE065B482027E63CDULL, 0x1079621EDC2517ACULL, 0x1FEBE32FEFE98964ULL
        }
    },
    {
        {
            0xA3835C107A0DB272ULL, 0x4EEA3577BC7501E1ULL, 0x418D829CDD457C93ULL, 0xC161823CBC065BECULL, 
            0x6CDB59A125BF2936ULL, 0x758D2F627498A00DULL, 0xE70D6F220FF3A397ULL, 0x91F273D0049D16DAULL, 
            0xA1A502B5F84A48C1ULL, 0xB3FD4B002819D2F5ULL, 0x779B37D6BC1E17EFULL, 0xD0657A18B20F584FULL, 
            0x60E98049AFBE6C73ULL, 0x17728899F0783D54ULL, 0x1091C9ABAE5B4D39ULL, 0xF60F866C2D8A7251ULL, 
            0x507F4B39B928EC09ULL, 0xF6B822B0732505E3ULL, 0x776B7E751CC2C5ACULL, 0x16E02DD1AAAC3264ULL, 
            0x013F182424B76DEDULL, 0x503EAD717EC543B8ULL, 0xA1119870DB33615BULL, 0xE65FF79B381D7617ULL, 
            0xDECA231ED6DA8439ULL, 0xB242D2011BCCF1D3ULL, 0x7AFDFA78A60D8099ULL, 0xDBAD7CDF151C986AULL, 
            0x52AA896340CE7E52ULL, 0xA7C4F9AA6DFA98EDULL, 0x6075A4026219B288ULL, 0xF5CA1D73AE6FAB46ULL
        },
        {
            0x04741243DE1D3E95ULL, 0xDE2E4738C5AC558AULL, 0xDA22D6EFDDC1DE23ULL, 0x6ACA60FE0746F165ULL, 
            0x911A723AD229A1EAULL, 0x0067C589863A613EULL, 0xBBB747148C08F1F7ULL, 0x7DDBC397765614DCULL, 
            0xDC9DCE16B855EA5EULL, 0xDF63C249BBA41FFEULL, 0xE6FFF9A6C969661BULL, 0x9CB6E5F62EA2320CULL, 
            0x4E1E0803E70E1354ULL, 0x843872402EE6A815ULL, 0x85609C223306171BULL, 0xA8CFB23FE4DAAB2AULL, 
            0x9CAB29CE2913D531ULL, 0x04183E374EF9F009ULL, 0xF89EECADCD96D53BULL, 0x3D2F6FCA0AC7AB17ULL, 
            0x5B6814C2180B9729ULL, 0xFC57900B9A9B6B76ULL, 0x90749B28B244E51BULL, 0xDC54CA33B76399A0ULL, 
            0x79D7ADDADF4750ECULL, 0x38E36A472302EDEAULL, 0x7E909680264E954AULL, 0x8BF004C826A46E59ULL, 
            0xE9EAC3647E49E472ULL, 0xE3FEAA73F5AB5DF9ULL, 0xEDEAF98212754A93ULL, 0xCE31F4E5D4CDA560ULL
        },
        {
            0x0704A2AE0073A29FULL, 0xF75E92BB31350E49ULL, 0x1DCEE0CB4C606397ULL, 0x1A3EDD3A3593E894ULL, 
            0x5C8B5528AE31BC7EULL, 0xD33F648FCBEE8E4CULL, 0x0C1425D8D250DCECULL, 0x68C166CF2C983067ULL, 
            0xE74D84E8ABE4C630ULL, 0xCB79F265D451DDF4ULL, 0x2B7DEE23CA70E112ULL, 0x05C65B346DB4827FULL, 
            0xF0905E25837A7AF5ULL, 0xB5E983A7A6327AA1ULL, 0xE94A9A08E279BFC6ULL, 0xDFFBBF454A6E1B34ULL, 
            0x58F7A357E5BD34BCULL, 0x5A2A911A9FC9FA7BULL, 0x464B788754FFB517ULL, 0xA86C325B9C923244ULL, 
            0xDD7557BFA02D3827ULL, 0x420F1D02DAA63E29ULL, 0x0051DB4B6076CCF5ULL, 0x71D8DC4CF0C2567DULL, 
            0xB05E4F14ECEFF614ULL, 0x3FE559BD1D758F21ULL, 0x75952BA7908F8471ULL, 0x33A615B848B20CE1ULL, 
            0x234AD7007007AE2DULL, 0xA9E4AB453BCE4BF9ULL, 0xC90D1BAA0C7BA18EULL, 0x91A0810B6AE1956AULL
        },
        {
            0x215CEDCC854A264DULL, 0x0F84421F67B042CBULL, 0x2CCBC6FB2138FAE1ULL, 0xB4CC12F58363FF14ULL, 
            0xF42AA491DA793022ULL, 0xB1143378D9897D3CULL, 0x626257E13E5A64EAULL, 0xEB3FE4C644C37005ULL, 
            0x837650649195FD66ULL, 0x9125BBDD9DF47C33ULL, 0x3014446B2CAFD36BULL, 0x35831ED7C25E563DULL, 
            0x27D7820C1120FFD6ULL, 0xA8F41AC52ECDEAF4ULL, 0x39A3DE7C45B14ABCULL, 0xB66AAF74733EED4FULL, 
            0x8CDB131F2BAFD4E6ULL, 0x3FEFD4755D784B5FULL, 0x9523AFD6A1C14724ULL, 0x5E064B6C405283D9ULL, 
            0x522E5B239F2ADD54ULL, 0x02618BB0DD153E66ULL, 0x09C77A7924BB02C2ULL, 0xC3D017604A9B58BAULL, 
            0xF7DC64680D1FE7EAULL, 0xD9FCCBDA5C1937FCULL, 0x23C72737CF9CD39FULL, 0x80C860AE0CB39D2EULL, 
            0x608BDD751264BF45ULL, 0x4CF1AB1B2843D302ULL, 0x348B42F0897FE4BDULL, 0x7B107CA122A26D0BULL
        },
        {
            0x78537FC4E09E3E4AULL, 0xE9FAAEB63638BF4DULL, 0x71CAC77077E4444FULL, 0x38DF16C78F0B0957ULL, 
            0xCA670D8C1929D6F6ULL, 0xAC31CF66A1668452ULL, 0x8EB5DAFC892BAE09ULL, 0x156FA5D284D53F36ULL, 
            0xC8F6349D1C96D0D2ULL, 0x11FDF746B7F68855ULL, 0x85062978251BD5E1ULL, 0xCC47561B647396D9ULL, 
            0x6668A929DE3A9237ULL, 0x7D3B6F3B7AA3DA1AULL, 0xF2486BA3012ED8B9ULL, 0xD927C74D2C098977ULL, 
            0x39A7D95E17D5B0EFULL, 0xE6666126404664BBULL, 0x7F0FB5BF95F7D6D7ULL, 0xB3504DAC17C93D49ULL, 
            0x3ED2170DCE0264FBULL, 0xAA9DC9A659F52572ULL, 0x4E3C79BA9EFD4D9BULL, 0xA919A003A1759EA4ULL, 
            0xEA5610CFC542363EULL, 0xE09785D6DA79D708ULL, 0xF3FC7408702C7B57ULL, 0xBD22567DEF9797EBULL, 
            0x686F93A7403EA8CDULL, 0x0E935BD841E533B5ULL, 0x6DC91090C553946DULL, 0xE2E916734B851E7EULL
        },
        {
            0x53F9AA29906FDF27ULL, 0x4761842B4DF0036EULL, 0xE1D165A7D3F6F3C3ULL, 0x051CF13FB220BDB3ULL, 
            0x16D3635CA965ABE1ULL, 0x30D2D185E4735A5EULL, 0xC97F061462E36BF5ULL, 0xCD96AA82F0417669ULL, 
            0x7C9EEC2D00632E01ULL, 0xCD171ED892B4C3EEULL, 0x98277A70EBB82C1BULL, 0x029977A1D8E5A019ULL, 
            0xB4D8C6907E786881ULL, 0x82D4DE55AF08FCC1ULL, 0x2A1CAEFCBE42AED0ULL, 0x16C36EC918E4D082ULL, 
            0x9F8DBB1E3CB41E22ULL, 0xCDBC3260215BD46FULL, 0x06FCC430AE6EFA73ULL, 0xA7D699E944B8A7D8ULL, 
            0x4CE93ADE830E5728ULL, 0xA494361B1759B51AULL, 0xDBC1E33D8E24FBB6ULL, 0x871ED84279C10CAEULL, 
            0xBC584887386101DBULL, 0x57E720DE9CF7339CULL, 0x307F245FA10704F6ULL, 0x4FE9172A87E5CF11ULL, 
            0xCC236D722705B5D1ULL, 0xC6851E7A068E5E76ULL, 0x13C50D851743EB48ULL, 0x27400D8712B80C9CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Menkent::kTwistConstants = {
    0x130AAC645060527CULL,
    0x88D6B2031C14A2B5ULL,
    0xD10929E550AA59C3ULL,
    0x130AAC645060527CULL,
    0x88D6B2031C14A2B5ULL,
    0xD10929E550AA59C3ULL,
    0xD56630F4D468DE9BULL,
    0x35A3F4FFA5A0257EULL,
    0xAC,
    0xDE,
    0xCC,
    0xEA,
    0x87,
    0xB1,
    0xD6,
    0xC4
};

