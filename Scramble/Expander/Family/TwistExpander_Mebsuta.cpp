#include "TwistExpander_Mebsuta.hpp"
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

TwistExpander_Mebsuta::TwistExpander_Mebsuta()
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

void TwistExpander_Mebsuta::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xDC623E8529265F6FULL; std::uint64_t aIngress = 0x9C972918D579B7B6ULL; std::uint64_t aCarry = 0xDFFB92F641DACAD6ULL;

    std::uint64_t aWandererA = 0x9D452348348254CCULL; std::uint64_t aWandererB = 0x8C84A50CD44081EBULL; std::uint64_t aWandererC = 0xE87A228542C53E97ULL; std::uint64_t aWandererD = 0xB7EDCD60E096ECFFULL;
    std::uint64_t aWandererE = 0xEB03C063774D7799ULL; std::uint64_t aWandererF = 0xCB441A779B506EE5ULL; std::uint64_t aWandererG = 0xA35AA07A5FC03814ULL; std::uint64_t aWandererH = 0xB4EFE8B60F86E8A2ULL;
    std::uint64_t aWandererI = 0xE916D511D047A8AEULL; std::uint64_t aWandererJ = 0xAE1E5DDAE758D62FULL; std::uint64_t aWandererK = 0xBCD9DBDB297B4657ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x8B7FD74ABCFE5B8DULL;
        aCarry = 0xE93227187C22B2E3ULL;
        aWandererA = 0xA79B6647C27BC8BDULL;
        aWandererB = 0x9722D9D82A918977ULL;
        aWandererC = 0xF0E538BAB5395A60ULL;
        aWandererD = 0xB3C83780418C1FB4ULL;
        aWandererE = 0x9E6701CF7F24B043ULL;
        aWandererF = 0x85305B66A45CA327ULL;
        aWandererG = 0xCD0D3AEC4D09367EULL;
        aWandererH = 0x810FB605D6383F8CULL;
        aWandererI = 0xF32E0EE1ED7AECC3ULL;
        aWandererJ = 0xD615885543A0A9D0ULL;
        aWandererK = 0xC1116113E1ABC10BULL;
    TwistExpander_Mebsuta_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Mebsuta::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xFE7CE4FF511E16ABULL; std::uint64_t aIngress = 0xF0F0F14D2576A32CULL; std::uint64_t aCarry = 0x8384774A21EC15CBULL;

    std::uint64_t aWandererA = 0x8EEC7054A096AE08ULL; std::uint64_t aWandererB = 0xDBA6CF98EE966479ULL; std::uint64_t aWandererC = 0xDC8EBF02CBADA7F6ULL; std::uint64_t aWandererD = 0xF8CA34C323E9FAE4ULL;
    std::uint64_t aWandererE = 0xB6EC80D0599A2753ULL; std::uint64_t aWandererF = 0x928C9E6BD3994CCEULL; std::uint64_t aWandererG = 0x9A823B8C956C5B41ULL; std::uint64_t aWandererH = 0xDE00D79EB403FFA2ULL;
    std::uint64_t aWandererI = 0x9130633F353FE5A2ULL; std::uint64_t aWandererJ = 0xDBEEDDD66610F479ULL; std::uint64_t aWandererK = 0xBD53EDB27AFE9BA5ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x88E5DF235D7144C9ULL;
        aCarry = 0xBE1035BD6AACCDD6ULL;
        aWandererA = 0x92CE277DC5B2D021ULL;
        aWandererB = 0x9CC1298ECEC50841ULL;
        aWandererC = 0xD79C082337676152ULL;
        aWandererD = 0x8F08107AD7D2AC0EULL;
        aWandererE = 0x9E85CADA179D9CF2ULL;
        aWandererF = 0xA264D724C57DAD2AULL;
        aWandererG = 0xE3F9B168F0CB0B12ULL;
        aWandererH = 0xBE98521AAC258E4FULL;
        aWandererI = 0x95989B9DAC329445ULL;
        aWandererJ = 0xAFAC2BA8153777C1ULL;
        aWandererK = 0xB374BB4708AFC401ULL;
    TwistExpander_Mebsuta_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Mebsuta::KDF_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x8738854061A314A6ULL; std::uint64_t aIngress = 0xBAFFE9D41CC94054ULL; std::uint64_t aCarry = 0xA801234F29878919ULL;

    std::uint64_t aWandererA = 0x8A9AAF7F5AB2EB7AULL; std::uint64_t aWandererB = 0x9304A6DF050FB758ULL; std::uint64_t aWandererC = 0xC161B118458A5A6EULL; std::uint64_t aWandererD = 0xD6A95FCF3A77AC3EULL;
    std::uint64_t aWandererE = 0xC7B29549868DC609ULL; std::uint64_t aWandererF = 0xD923ED765DEB94D6ULL; std::uint64_t aWandererG = 0x87D5177DBBB44303ULL; std::uint64_t aWandererH = 0xE838F6F315EA9213ULL;
    std::uint64_t aWandererI = 0xC36F2C3A1980D243ULL; std::uint64_t aWandererJ = 0xD3749280B3F10791ULL; std::uint64_t aWandererK = 0xADE7EAAB3D89CDB3ULL;

    // [kdf-c]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x896BADA61F157501ULL;
        aCarry = 0xCB1F61370E715427ULL;
        aWandererA = 0xA639A6C7F7DBC20AULL;
        aWandererB = 0xE08A6B2CB2E30D84ULL;
        aWandererC = 0xBF7B300F89E093EEULL;
        aWandererD = 0x9758D693B1C604C4ULL;
        aWandererE = 0x9327E3B3EF0CDF73ULL;
        aWandererF = 0xBD92EAF1A7117085ULL;
        aWandererG = 0xF10406BB4E276CCDULL;
        aWandererH = 0xE7386D305AE9C21EULL;
        aWandererI = 0xB02FDA68051319BFULL;
        aWandererJ = 0xC08657947B77B8D6ULL;
        aWandererK = 0xC369373BF574F41BULL;
    TwistExpander_Mebsuta_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Mebsuta::KDF_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD0C2001AA8829CCAULL; std::uint64_t aIngress = 0xE2484351CF08B6D4ULL; std::uint64_t aCarry = 0xDAC4E9729E94B85EULL;

    std::uint64_t aWandererA = 0xAA2BCF533B367658ULL; std::uint64_t aWandererB = 0x82A54FF754AB5337ULL; std::uint64_t aWandererC = 0xF49EFB04D6AA27FBULL; std::uint64_t aWandererD = 0xEEF99B732FB7E789ULL;
    std::uint64_t aWandererE = 0x8DDA6940696CA096ULL; std::uint64_t aWandererF = 0x966BC2F7B0906727ULL; std::uint64_t aWandererG = 0xF65FD0CB6F525FCBULL; std::uint64_t aWandererH = 0xBD059181CA200795ULL;
    std::uint64_t aWandererI = 0x969A61FA417E763BULL; std::uint64_t aWandererJ = 0xBCB07B6A79CE208EULL; std::uint64_t aWandererK = 0xE0BEFE6760AC850EULL;

    // [kdf-d]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x8CE1BEC864CDBAB0ULL;
        aCarry = 0xA5FF24CAD649B050ULL;
        aWandererA = 0xE35AF72C85074769ULL;
        aWandererB = 0xFCBAF89424EBE3AEULL;
        aWandererC = 0xFE4E6118B6231323ULL;
        aWandererD = 0x985A315BC2525AC0ULL;
        aWandererE = 0xA83453DF6CB0844BULL;
        aWandererF = 0x926062308FAC58CEULL;
        aWandererG = 0x810088BF11C18705ULL;
        aWandererH = 0xC20C6209C2E7B80BULL;
        aWandererI = 0x82E04B0F93A89894ULL;
        aWandererJ = 0x8F2084247FC4EC6FULL;
        aWandererK = 0xD7ED759E0B492E29ULL;
    TwistExpander_Mebsuta_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Mebsuta::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB0E326A7462EB4F8ULL;
    std::uint64_t aIngress = 0x8C5D4C5D76960B58ULL;
    std::uint64_t aCarry = 0xAE07CAE4201EDF57ULL;

    std::uint64_t aWandererA = 0xD8FCE9656AAB6173ULL;
    std::uint64_t aWandererB = 0xEA24AB99AB66B910ULL;
    std::uint64_t aWandererC = 0xB0020A5E7DBF9826ULL;
    std::uint64_t aWandererD = 0xB7B63505E7D59D9FULL;
    std::uint64_t aWandererE = 0xC8E6ADF1937B6992ULL;
    std::uint64_t aWandererF = 0x97514C503217EC3FULL;
    std::uint64_t aWandererG = 0x93DF2C041611F033ULL;
    std::uint64_t aWandererH = 0x83FEDED1888C77E0ULL;
    std::uint64_t aWandererI = 0x8D385A38E3212067ULL;
    std::uint64_t aWandererJ = 0xC30FBB851E5C80ABULL;
    std::uint64_t aWandererK = 0x86AEED14529D78F7ULL;

    // [seed]
    ////////////////////////////////////////////////////////
    ////////        KeyRotate
    ////////
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateConstants), &(mDomainBundleInbuilt.mKeyRotateSalts), pSnowLaneB);
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
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateConstants), &(mDomainBundleEphemeral.mKeyRotateSalts), pSnowLaneB);
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
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateConstants), &(mDomainBundleEphemeral.mKeyRotateSalts), pSnowLaneB);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateConstants), &(mDomainBundleEphemeral.mKeyRotateSalts), pSnowLaneB);
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
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnConstants), &(mDomainBundleInbuilt.mKeySpawnSalts), pSnowLaneC);
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
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnConstants), &(mDomainBundleEphemeral.mKeySpawnSalts), pSnowLaneC);
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
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnConstants), &(mDomainBundleEphemeral.mKeySpawnSalts), pSnowLaneC);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnConstants), &(mDomainBundleEphemeral.mKeySpawnSalts), pSnowLaneC);
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
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneA);
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
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneA);
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
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneA);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneA);
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
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneD);
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
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneD);
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
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneD);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneD);
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
    TwistExpander_Mebsuta_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::Seed_H(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::Seed_J(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::Seed_K(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::Seed_L(pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::Seed_M(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::Seed_N(pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::KEY(pWorkSpace,
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

void TwistExpander_Mebsuta::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA7495A48C6CFA95DULL; std::uint64_t aIngress = 0xD4B1CA278B424BD8ULL; std::uint64_t aCarry = 0xEC389C41C0C248C4ULL;

    std::uint64_t aWandererA = 0xFA427F6A3AE32DDAULL; std::uint64_t aWandererB = 0xB69E0AA8D67EE94DULL; std::uint64_t aWandererC = 0xC28976AD3FEDA2A7ULL; std::uint64_t aWandererD = 0xF15C9832504B1505ULL;
    std::uint64_t aWandererE = 0xC1FA4443033D52FDULL; std::uint64_t aWandererF = 0xF587C851EB6E4B9EULL; std::uint64_t aWandererG = 0xB89E5C8EA16A3087ULL; std::uint64_t aWandererH = 0xE8769467F735203DULL;
    std::uint64_t aWandererI = 0xFC8D4A96F2684C31ULL; std::uint64_t aWandererJ = 0xAD7E660BC7277DAFULL; std::uint64_t aWandererK = 0x98459C24E5207B77ULL;

    // [twist]
        aPrevious = 0xDE0158A98DD2D93EULL;
        aCarry = 0xA5A6848386D36834ULL;
        aWandererA = 0xD520BB94B5E29874ULL;
        aWandererB = 0xB64722CDE95C919AULL;
        aWandererC = 0x9D39C77619BF0D00ULL;
        aWandererD = 0xEA7DDB2873443DAFULL;
        aWandererE = 0xFD7FC40FBCB8A27DULL;
        aWandererF = 0xD5D89E827504B8FDULL;
        aWandererG = 0x9CBC9F0D1F8F049BULL;
        aWandererH = 0xEC6A6B4E77FD9EB0ULL;
        aWandererI = 0x9F268B1F6343DEACULL;
        aWandererJ = 0xEC246985FAF740B9ULL;
        aWandererK = 0xF332B6A73C15DF45ULL;
    TwistExpander_Mebsuta_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::Twist_E(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::Twist_F(pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::Twist_G(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::Twist_H(pWorkSpace,
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

void TwistExpander_Mebsuta::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Mebsuta::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Mebsuta::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 17 of 33
    // Exploration cases: 0
    // Structural maximin 517 / 674; family total 8557
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
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7879U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3828U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4188U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7699U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1825U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1780U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1465U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1510U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1420U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1645U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 2005U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 17 of 33
    // Exploration cases: 0
    // Structural maximin 514 / 674; family total 8624
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
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3288U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3468U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3018U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7339U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 745U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 835U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 520U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1105U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 565U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 790U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 925U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 610U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldSeedControl candidate 17 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1059 / 1248; total 17339
void TwistExpander_Mebsuta::FoldSeed(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 588U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 633U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1893U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2006U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
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
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 363U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1353U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1443U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 138U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1038U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1781U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 340U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 723U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 183U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 228U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 543U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1803U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 768U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1668U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1398U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 48U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1173U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1488U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 498U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1961U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 993U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1938U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 115U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneG[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1646U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1736U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 70U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 318U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneH[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 273U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1083U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 903U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1691U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 160U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1871U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 948U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2028U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneJ[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1916U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 678U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1533U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1983U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 205U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1623U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1826U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1578U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 25U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1848U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1128U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1713U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 813U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 453U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1218U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 250U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneN[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1308U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1758U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 93U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1263U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 295U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 408U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 385U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 858U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldTwistControl candidate 17 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1057 / 1248; total 17252
void TwistExpander_Mebsuta::FoldTwist(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1084U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2029U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1219U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1106U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 296U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 431U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 746U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1601U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 994U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1174U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1061U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1894U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 566U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1534U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 949U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1331U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1804U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1309U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 476U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1421U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 26U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1511U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1196U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1669U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1399U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1466U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 656U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1039U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneG[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 161U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 386U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1759U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 791U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneH[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 701U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1556U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 859U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 971U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 881U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1129U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1939U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1579U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneJ[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 71U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 814U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 611U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1286U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneK[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 926U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1444U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 206U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 904U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1354U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 116U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1714U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1241U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 251U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1151U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1849U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1489U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneN[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 341U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 836U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1376U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 521U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1624U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1984U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1016U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1264U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Mebsuta::kKeyRotateSalts = {
    {
        {
            0x0BAB789F1DF3010EULL, 0xCC6906D49CD79686ULL, 0xB5595913807AC89AULL, 0x95F68261796010A1ULL, 
            0x40501B3AD706A1DDULL, 0xC3D46219F098F5A9ULL, 0x7E721FE439B25CB7ULL, 0x9EB572EF2DBA8F1BULL, 
            0xEB15DB859ABA351AULL, 0x7F919B9CF980323CULL, 0x0FF4E599F3CB54A4ULL, 0x870CC23D1EF8E9ECULL, 
            0xA6FBDB674B142C12ULL, 0x6E0BCC531EBACF34ULL, 0xFDE255DBB7A84B90ULL, 0xB8CC898AB306E24BULL, 
            0x075A0FC5F5F3EE41ULL, 0x64E4D36CBC0ED44DULL, 0x3EA5F0F8B1FB046FULL, 0x473F5B52226826EEULL, 
            0xD8AAA878CDFA1F77ULL, 0xD5FD311E249A5AE0ULL, 0x4DB5DC77C69AC8FEULL, 0x7B3BA1F20156B3F9ULL, 
            0xC904A8597526B9F5ULL, 0xA346B0D0E986A990ULL, 0x11349B0A8C8A115EULL, 0x7FF68BAEE1821A5FULL, 
            0xD5F608C2E166FE49ULL, 0x2C4F8D043F0E5DD6ULL, 0xD047A1204B2EF950ULL, 0x72C6BA5235DA84C9ULL
        },
        {
            0x2968E9E498181A76ULL, 0x25D0FEE53CA0CD6FULL, 0x5922F633812C7EAEULL, 0x59F378DDDD8BD5EFULL, 
            0x00E7DD5315DF8F5DULL, 0xE927B8367340A766ULL, 0xDEAD1643235E066AULL, 0x60ED3A5FEBFEE3A7ULL, 
            0xAF9E75568564E660ULL, 0x07B0CBBA6F2309BBULL, 0x0DFACB6E195E63B2ULL, 0x977169CAEF29EC37ULL, 
            0x9E5557C6AF0DFEDAULL, 0xFB2782FEF4ECF819ULL, 0x894F134970588E70ULL, 0xF0D87BA2BC4F2F3EULL, 
            0xE432BFB06BAB49FDULL, 0x00C956F1A8033E39ULL, 0x740C30F7B5A82927ULL, 0xF1D9A98390C46517ULL, 
            0x54B4EB1AAE53E26EULL, 0xA05C71EFA56F5A7EULL, 0xA1613DE409D99F9AULL, 0x9DBFA4C8E5022838ULL, 
            0x727927FE54F557B4ULL, 0x5532C7107F78F6C3ULL, 0x2724B08587FC25DAULL, 0xC9097A6F2F38FD06ULL, 
            0x18DD7C481E51F3FFULL, 0x1C06FA17AA2CB312ULL, 0x1F35215A8A14F555ULL, 0xFA48D7CBC199B972ULL
        },
        {
            0xB92428E14AAB73BBULL, 0xDF7818F9CF77ABF6ULL, 0x741D08845BCA7B26ULL, 0x08DEDEA53F1EACA4ULL, 
            0x323295A8CA345D62ULL, 0x1127F6ED375971CAULL, 0xCBC6115C3590CE93ULL, 0x8712519494E78294ULL, 
            0x18E04962F51B017DULL, 0x4C66889D99589B70ULL, 0x874B0FC1E0B0CB6CULL, 0xEC2F3BE402D4271AULL, 
            0x66C13960551923E3ULL, 0x49F591D6CAEC99ABULL, 0xB668C5959D643545ULL, 0xE4CEC0E77E66D03FULL, 
            0xEED9985B48571064ULL, 0x465D3E26E776D54AULL, 0x2078C2FC10C64988ULL, 0xA2CD756B32E57A04ULL, 
            0xD06E5A712359D436ULL, 0xCBAF0C452FE8D579ULL, 0xEF7A098778F40F39ULL, 0x8E8992E4C50F1081ULL, 
            0x54092FDFAB4CD42FULL, 0x8B729081DE84E72FULL, 0x4C72D33626C7900CULL, 0x486E2FF108035AF2ULL, 
            0x83DA61539AB4A22DULL, 0x49FD4E79A6D9F4CAULL, 0x2ECBCC37F40F15E3ULL, 0x243225D748A8D381ULL
        },
        {
            0xA3205253B0969C11ULL, 0x48378577B74FFE1CULL, 0x7250873A867FDFBEULL, 0x2A2B955788059EA5ULL, 
            0xB157599DED2E6120ULL, 0xA5395A71E63382B9ULL, 0x858DF88E1038EAB4ULL, 0xC6D8752F49BE6D07ULL, 
            0x09BF569E97F793A2ULL, 0x2433FC302059ED0AULL, 0x8BA70F343170BC98ULL, 0xD2F06A509F0CD533ULL, 
            0x9FDD1F572454CE03ULL, 0x4002CD2D6F3843E3ULL, 0x53527227712023A2ULL, 0x8DBAF97668EAEC85ULL, 
            0x599E061B699271D5ULL, 0x8D4E2F818CCCBA05ULL, 0x1A947382B38FD8E2ULL, 0xBD56EF8FA6229649ULL, 
            0xD1D6DBB17E42CF40ULL, 0xAF5D33B486DC67FEULL, 0xDF1A3263818F3E12ULL, 0xD85714A196475E36ULL, 
            0xBF2EE8A94D375E14ULL, 0x850AF9F2B4F13A2DULL, 0x473E45F2F02BBC01ULL, 0xA799C3697B709B24ULL, 
            0x80D2B37ADCC9AA97ULL, 0xAE86C9F30983F5B1ULL, 0x30DFF763DE177CE6ULL, 0xC7D4D10F0F56A0A9ULL
        },
        {
            0xD401671D8969E276ULL, 0x84F700403443E20BULL, 0xC5D991DCD5E861C4ULL, 0x58102321253B714DULL, 
            0x15C0AB95F0190A29ULL, 0x3B73FBB8AD8F043BULL, 0xDE346520BADC205FULL, 0x39E2721689EF1857ULL, 
            0xB8E11BCD1EFE2034ULL, 0x6E308ACC803E8182ULL, 0xEAEBB8197EFDEAA1ULL, 0x6C624B6E2532486AULL, 
            0x830D0846A41742C8ULL, 0xC4508D9D391F3D69ULL, 0xEB0C79981B0407CFULL, 0xDD2131F4D9D6E11FULL, 
            0x2A86DF5AB5E2C047ULL, 0x7B955EE480843BF5ULL, 0x9CD1042EBC91C5CAULL, 0x479CB844C47EE458ULL, 
            0x00D393D65D94C0D5ULL, 0xDF3CF66079DACF10ULL, 0xC56ECBA91915B856ULL, 0xCBA0EBD6EEBE0ECDULL, 
            0xB6C9B916398706B6ULL, 0x8C51C35957744952ULL, 0x3DB159692FBC8EF1ULL, 0x10C3A1C8A8F33C99ULL, 
            0x9DC8E0BD44DC5FC2ULL, 0x2F613A02FED6A67AULL, 0x8856F3BE643BAC93ULL, 0x5360054AC1DAB18CULL
        },
        {
            0xEC171F752F0F1B09ULL, 0xE3F1ED799E724C46ULL, 0xE5CF6B43A33CEAEAULL, 0x3366349A26C38A9BULL, 
            0x80D6C0AE1F7F9D2DULL, 0x18B9469C26680FB1ULL, 0x050890B42D4BE3C3ULL, 0x8F50AAD5E4DEB4F3ULL, 
            0x051F3F1A8CEE11D8ULL, 0x059E3CCEE5241CCCULL, 0x0C16A6306B017A68ULL, 0x5A447BB3F25616FCULL, 
            0xE89692DFA5325962ULL, 0xE2BE5531DF127FF3ULL, 0x47730C419A2AA418ULL, 0xEC885E3761E16F2FULL, 
            0x13DCE3099C514EF3ULL, 0xC272B6938EEA2B92ULL, 0x5B19D896A61A024DULL, 0xE57D70E8521BE08DULL, 
            0xBEB05076ACF7B691ULL, 0x5DB084C7BBE382C6ULL, 0x27F92C7A90EB8346ULL, 0x3CD7ECF57C02CA9AULL, 
            0x61E13A88555FC912ULL, 0xBCB670D64ED8524BULL, 0x02AD71615161DA63ULL, 0x22FF72138006CA35ULL, 
            0x80BF1AD522E258CAULL, 0x50C4CB18C9107DB2ULL, 0xD0CE766E5064B6C5ULL, 0x9AD88C5563DA2267ULL
        }
    },
    {
        {
            0x70AE45FD4F3FB5D8ULL, 0x10B9AC4043252000ULL, 0x3CBC77F182A242A7ULL, 0x78F805C4683FCC11ULL, 
            0x3360468DCD756AE3ULL, 0x02833A66D275719BULL, 0xB6798628BA35D26AULL, 0x84753489437EE31BULL, 
            0x84B063F2BE193039ULL, 0x2592601FB9CCBB5DULL, 0x4EA714CA11CF4571ULL, 0xAA6BAAE027B17033ULL, 
            0x7DDEB65A8F7CD173ULL, 0x5DAA02F62720457AULL, 0x6BFE0B8BE0CC776CULL, 0xACDA563D4EECC38BULL, 
            0x76874A888DAAC9D2ULL, 0x1535F2A862927BE2ULL, 0x1FDE9FB83827C789ULL, 0x10BB40F54E1CF398ULL, 
            0xF02C7616098B3DDDULL, 0xF6A41D7F50A2D6DBULL, 0x2450E6515C7B1CE0ULL, 0x4DDCD39E1426CA0CULL, 
            0xF439D4D336994240ULL, 0x4EE02FD516CA76A8ULL, 0xAB4AF017C42BB22FULL, 0xACEE9B95BD5F9A40ULL, 
            0xEAFE5C65F981CD01ULL, 0x38F58E011414B56BULL, 0x82ED7B886023C3DBULL, 0xF6C716CCD7F25A27ULL
        },
        {
            0x412F737A3110C426ULL, 0x1BF2F7255D1AEB97ULL, 0x623E6F2E9A4EBCF0ULL, 0xB6AC15C6EDA5CAAFULL, 
            0xCE7BA60F36C31D90ULL, 0x3D8835D3AD55AA93ULL, 0x26FDD1149B6D8287ULL, 0x94F48949CB1483AFULL, 
            0x8539FDAA9E279BF2ULL, 0xF8CE045FECEF2E23ULL, 0x5F906793605E78EAULL, 0x71F3F9CF529AEB13ULL, 
            0x8C4B09CEC78C342BULL, 0x42EC0B839005D738ULL, 0xD6DD9EFB7CCB70ECULL, 0x544D217127898263ULL, 
            0xCEF3C6CDA513DBC9ULL, 0x697EA61CBF1421DEULL, 0x72D65441C91BD0ECULL, 0x4CD52D58433FCB4EULL, 
            0xA27EBB9E88415B13ULL, 0xDA02963EAD47E3FEULL, 0x166F8687BBCAAD7CULL, 0x30633A8796B0116CULL, 
            0xAC10D9D977690C71ULL, 0x225B91466596D6FFULL, 0x05DE848A534BF62BULL, 0xF3B671B078AA4EF2ULL, 
            0x5B9256AF06B2DAFEULL, 0x4236BC655BD5EA10ULL, 0xE35ED0A61FC87626ULL, 0x925048FCD5A4D1CBULL
        },
        {
            0x3E212E6302D1390EULL, 0x13B3C161D1899D82ULL, 0xF5D9BCCAB5B9985BULL, 0x2644581791421864ULL, 
            0xB1F139B0839610C0ULL, 0x6B81BF1F88795F43ULL, 0xE1010360B739EC78ULL, 0xC185F06D52B8A6CAULL, 
            0x7A80B58C57DB7173ULL, 0x44F4DE373A2517C8ULL, 0x0196761CE5D6D8D1ULL, 0x1510EAB2644F7C8BULL, 
            0x1E471CF4D4AD3D52ULL, 0x6C13509A446BE313ULL, 0x939C47038DE0EF0CULL, 0x5900D82B113CF572ULL, 
            0xBBE63F01519CB583ULL, 0xD6F86F2A4242EB52ULL, 0xFD76564951472CFAULL, 0x1647691BD8AAA444ULL, 
            0x27F042268B130ADCULL, 0x9C66E421F386A71DULL, 0x00964194276051F1ULL, 0xA0C14F2F221AAC84ULL, 
            0x5D67BAA2034B7685ULL, 0x8C17420D5E97C8A1ULL, 0xD16E4F291380EE80ULL, 0xA9C3889D3FB7BA26ULL, 
            0xDD3F4ED45282E9A2ULL, 0x35421F770329AF67ULL, 0x2874DC522874A882ULL, 0xCB3042A06E38F93CULL
        },
        {
            0xD97CC8C425694FB3ULL, 0xD8CA5F7D9AC56190ULL, 0x7804422E020386F9ULL, 0x632AF72AF1C7AB62ULL, 
            0x76A0567D6AB07B4FULL, 0x021C458EB7D1779EULL, 0x56C40566229DE803ULL, 0x74C27660836E41BFULL, 
            0x36705FE7795A9216ULL, 0xD60F48CFC81F89D0ULL, 0xD5048D41822069FEULL, 0x918992B0731E49D0ULL, 
            0x3FFEBEA002AA0650ULL, 0xBBF779C6C2FA0556ULL, 0x18F31895B515793FULL, 0xB4ADF40987B7F4AAULL, 
            0x0807CA723DABC534ULL, 0x3CA15572B256ADEDULL, 0xC82727F9CE9A7C4AULL, 0x293EAD9A55FCEDA2ULL, 
            0x3D7EB87F4DD7536DULL, 0xF97BF228170E295AULL, 0xDAEC0ABE87230CE4ULL, 0x87DDF7817A7764F2ULL, 
            0x053CC0B353B441C5ULL, 0xA6A12A47BDD34D43ULL, 0xF536F6693E6CC52CULL, 0xF57450582ADD122CULL, 
            0x4F48D46029057C49ULL, 0x37AB4CA0BD80F9A6ULL, 0x1023B51B60777607ULL, 0xACBF62C12490F144ULL
        },
        {
            0xCD8B436E5228A2E1ULL, 0x4C10C998E470094EULL, 0x8F7340624AE6031EULL, 0x594080BE0D5516D8ULL, 
            0x819C088F6F27DA83ULL, 0xC5B201409187371CULL, 0xE474483EC900EA07ULL, 0x95448F04A4E12A21ULL, 
            0x2734B57CD2B80C30ULL, 0xE5F96EF2D66480D5ULL, 0xD07E3A0FFF2F89F6ULL, 0x087824F968E0EA0AULL, 
            0x82E092A007A91FF0ULL, 0xEDC6D7630472426BULL, 0x05D1FB68EE10E092ULL, 0x6031C66138E61F53ULL, 
            0x9E32E6193AFE4D56ULL, 0xE7A9C64C8624C37FULL, 0x82101FA8BC14E1F4ULL, 0x1C40803ABB6BB2F3ULL, 
            0xE2D122DED1662A91ULL, 0x4E8E0675E60F4667ULL, 0x3AB94770359D886BULL, 0x7AD5EA4FC2A28C18ULL, 
            0xBB79D8E447FF5B07ULL, 0xD65C8ADCDBEB7BAAULL, 0xAD7E3437DF7146C6ULL, 0x7481F2BA2F862ED5ULL, 
            0xE07C6CB34DB49761ULL, 0x57340AF4C2ED76D1ULL, 0x09C4EEA5BE33E308ULL, 0x9EA75C7E928B26A3ULL
        },
        {
            0x953C684AB7C48771ULL, 0x22AD95716573953DULL, 0x2C1008E2BAD8726DULL, 0xCF71EA6EEE3B5EB4ULL, 
            0xB071937DE8852C1EULL, 0x39933AF7B13D5A64ULL, 0x7B46B5C0B90C7E99ULL, 0x4BDB3FD510DFA9F3ULL, 
            0x65F51AA669682F53ULL, 0xC3CCD1DE15CFDC8AULL, 0x420E40A8D6FE27E2ULL, 0xD8DE17C442E7D418ULL, 
            0x6A54D465FE603094ULL, 0xAC7157688866015BULL, 0x99F19E3B0A10E820ULL, 0x759349ADBD123A46ULL, 
            0xD1CDC6B406AEFA75ULL, 0x427D3F191DD93B0AULL, 0xA5A4578ED61AF083ULL, 0x5101D638250785B2ULL, 
            0x331EC422C2A709EBULL, 0x6753851BC000FD3FULL, 0xB4CF221B82F1F4A7ULL, 0x0C795336A391C5B6ULL, 
            0x99066E302143EB3BULL, 0xDC1CC4B07216A2BAULL, 0xB7FF678205B0E456ULL, 0x98E0A024326688F5ULL, 
            0xBFB117A43740FB89ULL, 0xCDD57D4BEEF5BA48ULL, 0xDBAEFECB15C20B86ULL, 0x13836F7AD74FF3B5ULL
        }
    },
    {
        {
            0x21F3B5E1651CE4C7ULL, 0x8C57EFC669B62962ULL, 0x2ABECEBC4A76A316ULL, 0x2F6437679D35D09AULL, 
            0x438ED962D699406AULL, 0xCE3BE174A7617121ULL, 0x852C1E07BE196EDBULL, 0xA6776689A76A0098ULL, 
            0xD86AE9DA414F4696ULL, 0xA902E23304E4ACC3ULL, 0x0F23233A79DA67FAULL, 0x3EA6E78730A126D8ULL, 
            0x1A7E536DA4408FB8ULL, 0xFA7D82A5A72618B4ULL, 0xA53243F23FB59923ULL, 0x410FDC4410248DC0ULL, 
            0x7D55FBC3EF16568DULL, 0x35C571277E6B8414ULL, 0x509C296BC25BB46BULL, 0xC6C31685CB4EC642ULL, 
            0x041DDFB6100CD7D3ULL, 0xB36CC33BC28B03C4ULL, 0x3F970B6880C989E5ULL, 0x8B6A90407D5F7137ULL, 
            0x2897F74AD43E31A9ULL, 0xBEFA13DBE9CDAC44ULL, 0x6DF2A1EF906FD092ULL, 0x9628EA65D18C7471ULL, 
            0x31CD2246C9DBA92FULL, 0x740CC70A084FB08AULL, 0xE674957A5967A3BEULL, 0xF4704FCEB240B050ULL
        },
        {
            0x9BAC92F333ED1BB1ULL, 0x860462F66AB91051ULL, 0x327191A4B9BF9999ULL, 0xCA45BBB1F1704DB2ULL, 
            0xF4A5911BAD20E2D2ULL, 0x9E80F3DD212B1060ULL, 0xCE8DEA5AE815A2DEULL, 0x69C4870F5D1AE2B8ULL, 
            0x25064BDD5239F97EULL, 0xB81B152FAA105A55ULL, 0xA4F257309E76CD80ULL, 0xDFECFD2F0EAB95CFULL, 
            0xBAF64D17A4A820A2ULL, 0x812EBF0EBDCE483EULL, 0xBC2FE0E904F314DBULL, 0xEDE8C0960E7D9E12ULL, 
            0xC802AEE0ED273B6BULL, 0x3E990A84008F67F7ULL, 0x973E61376B273E80ULL, 0x1969804DBC7E0302ULL, 
            0x65E0EB5C42512A4DULL, 0xBA5942E69B87F139ULL, 0x759FDB2AF706CA53ULL, 0x25D17FECD1D93164ULL, 
            0x246C018ADE5DF349ULL, 0xB4307E212E0B47BEULL, 0x79A2C66FC969BEA3ULL, 0x13F71E7F9E64E2F7ULL, 
            0x446A0F5FC2F8B300ULL, 0xDD14E3E574474C2CULL, 0x31C892D775C3AEBBULL, 0xDD9400D93BDA9F2EULL
        },
        {
            0x677D4EF943462D50ULL, 0xF0E2C28DBF0C255BULL, 0x3F49F1741070AE8DULL, 0x0C8EEE2C2B96821FULL, 
            0x898E1E91505C22A0ULL, 0x85752092546CD89EULL, 0xA8DFA4720A558A39ULL, 0xB644F8D58486CD42ULL, 
            0x526DE7BD92077342ULL, 0x745DBBCCDE813B6DULL, 0x10C993B3ACA2E2CBULL, 0xEB82E54C8D86DA85ULL, 
            0x479EFB53446568EBULL, 0xDDB173FCB4BE7522ULL, 0x7DD57167D47C1473ULL, 0x69ADEF55863B1634ULL, 
            0x45269BB2D626FFF5ULL, 0x2996D7812F9A9FF0ULL, 0xF59C1701958FA989ULL, 0x21E5BEFAF449DEBEULL, 
            0x5F9EA65B66A28E81ULL, 0xE5ABD3DAFEFD6B0DULL, 0x2D5A34920AD37BDAULL, 0x879E869105C292BCULL, 
            0x4C56C5D6A48EEED5ULL, 0xCE1F0C955EDFC8FDULL, 0x330E90C8FA309D90ULL, 0xA1A6BEA8555F6056ULL, 
            0x6F62022FED553029ULL, 0xE41D58FC2BC62B81ULL, 0xEE2C97D3667DE8A0ULL, 0x9F29F8DB564D66B1ULL
        },
        {
            0x87916046F764977CULL, 0xACFF3567CBE65CF6ULL, 0x2C9206D2991B8E64ULL, 0xDF56A6AB46312C15ULL, 
            0x517EDFEB8AE92362ULL, 0x4D5AD483BAAEFDB5ULL, 0x07591862D43C8E65ULL, 0x2453642889C37BFBULL, 
            0x4F3508537FBF7C9DULL, 0xAE9FDD7670CEC87FULL, 0xC6ED38F26F208F57ULL, 0xD0FABD43BED1189CULL, 
            0x345E88CD919A3A21ULL, 0xE4433CC54D15F6C9ULL, 0xF3DFFDA382931DBDULL, 0x8E3044585172D7C8ULL, 
            0x58A8CC5CA8739AADULL, 0xE3E2DFB69425FCE2ULL, 0x80E3ED69541ABB0BULL, 0xDCFE3EE7ED55B0E1ULL, 
            0x5DAE81BCD0A6267EULL, 0x4292ED9BBFD9B04DULL, 0xAA64565B31A2AC96ULL, 0x105EFF532D6D3BEDULL, 
            0xAC6A9ACF9A29E8F0ULL, 0xF1351421C4F700CFULL, 0x19657035B60CE0E1ULL, 0x64CB57B88F14EA0DULL, 
            0x55496C488A09A52CULL, 0x385EE77D93133DA6ULL, 0x962218E951CC042FULL, 0x4B7117BCB0B10F74ULL
        },
        {
            0x0B8032EEBE0FE0D1ULL, 0x95ABCE5E654C5E58ULL, 0x9D901DF3A412832EULL, 0x11DC25FCF9CC4242ULL, 
            0x932F0C5E3A73DF4EULL, 0x5D6836FD43A03BCBULL, 0x60FB753DBA0154B8ULL, 0x468958695AC31655ULL, 
            0x4721FAA01EF7B4A4ULL, 0xA36D80C4090DB0ECULL, 0x49316878FDE0F2D4ULL, 0x451AB03A96259765ULL, 
            0x5D445AF4EAC6E4C7ULL, 0x0EB176C05A5D5E6FULL, 0xDB8DA5C256BE0512ULL, 0x4330D4EA5F535626ULL, 
            0xE5DFBD508467914BULL, 0x679DFB45DBA86C1FULL, 0xB49FD9F16AFDAF45ULL, 0xCE698C4E0FF80728ULL, 
            0x0B7FD8B073F9AFE7ULL, 0x91B906BB44C635D6ULL, 0xB43A44D3B0143A92ULL, 0x4D29AE971C64338BULL, 
            0xE2722179DE88EE13ULL, 0xF79039818221C107ULL, 0x0DA965716DBD68A1ULL, 0x8D71CC653B2D8F1CULL, 
            0xBA35537E3D796DB7ULL, 0x1CD793C5A94FE1CFULL, 0x6DEA76B9A83A4EF2ULL, 0x0F287092BED83C47ULL
        },
        {
            0x18D59D47B8D762E0ULL, 0xC57D4C237C99A6D7ULL, 0xE9B84C3D46100373ULL, 0xF2A3BC88BC522C38ULL, 
            0x305E403C9F663F5DULL, 0x0626E616CA2E484FULL, 0xC3F89DF9C08C81DAULL, 0xA2E370A17BB921B4ULL, 
            0x8CFA3BB1310556A9ULL, 0xA75122C9E9F875BEULL, 0x4A2BF6F60A460FC5ULL, 0x1B9806BC7700882DULL, 
            0xF1AF5B0DED595667ULL, 0xF09D7E9C9ACD1E95ULL, 0xFF4294A13C3FA8A1ULL, 0x14274FDEFEA204F8ULL, 
            0xFC78C29626262B48ULL, 0x9EBA3256A97121B1ULL, 0x28F9CF5A0F2AD745ULL, 0xFE0AE3E952A0E80CULL, 
            0x43827400C8EB827FULL, 0x4C92FD574806EC7DULL, 0x14FB3D75E1087018ULL, 0x2C5E736CA1354DCBULL, 
            0xB2CF0ABD23E1FFCEULL, 0x2EE539F8CA945CA9ULL, 0x3DFD9289DA2F712EULL, 0x9A8AF353E3607F02ULL, 
            0x82EB7E2E08284FCDULL, 0x6DF2AB0F8B18D08BULL, 0x6103A1739CF44CC9ULL, 0x0B65BB3BB49C8F4DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mebsuta::kKeyRotateConstants = {
    0x01FDE074998FB785ULL,
    0x0652A166A53EC9DDULL,
    0xF8DE11DBCBC5AB84ULL,
    0x01FDE074998FB785ULL,
    0x0652A166A53EC9DDULL,
    0xF8DE11DBCBC5AB84ULL,
    0x34DFDE2BA0166A6CULL,
    0xF4EB4EFF2908D9E3ULL,
    0xDD,
    0xEC,
    0xDF,
    0x20,
    0xA4,
    0xAC,
    0x30,
    0x30
};

const TwistDomainSaltSet TwistExpander_Mebsuta::kKeySpawnSalts = {
    {
        {
            0xDA6B096E7E809777ULL, 0x426034CE99DF3294ULL, 0x914445FD8D4860D8ULL, 0x362AB294AE7CDA82ULL, 
            0x0D4FDCA2D598F9D7ULL, 0x3F2427FE80CD03B2ULL, 0x26F3F9A67FB2C382ULL, 0xC2DB2A1993A208F4ULL, 
            0x210E2A83A4DAEA81ULL, 0xE51FC871F2B74A43ULL, 0x843D69E1D3BFDAF7ULL, 0x43ED46CC9C157CDEULL, 
            0x2F74DADB1001D81DULL, 0xBF06E59BA511D133ULL, 0x0F35AA37C68BE1D4ULL, 0x85965437D81C9757ULL, 
            0x79B7F51176830E8BULL, 0xB9287F5FD576323DULL, 0x8B832BB88073953DULL, 0x0402F94998FAA2E9ULL, 
            0x29C155E430D4CDAAULL, 0x84A43F66AF6A7E17ULL, 0xDDBA0325A996A9DFULL, 0x6362FF0CB5EF8051ULL, 
            0xECF4533DE7D2967BULL, 0xD7E92B61C1ED82F9ULL, 0x409F77976F7D5507ULL, 0x53DD3773D8A78587ULL, 
            0xF43E35634DF5AA56ULL, 0xDFD7D35EAD3D8A0AULL, 0x1A33D08C542A696FULL, 0x05B2C432981AE903ULL
        },
        {
            0x15B475A45CD60B3DULL, 0xC2594F7D975F337FULL, 0x14DBC7DB02BEF0C6ULL, 0x36E3596B77A83075ULL, 
            0xF2195425EB8442F4ULL, 0x7E57B5B0CFAE2003ULL, 0x1EC5D537970EC8ACULL, 0x7867BF284DC4C590ULL, 
            0x6A7E97D1A78D38AAULL, 0x5C45A7910BF89B19ULL, 0x0B50516C50E05A75ULL, 0xB500B0089AEFFB0DULL, 
            0xC253E0844C49C20BULL, 0xF95B9AF24DFA0579ULL, 0x100C626A69DCA737ULL, 0xB6562A293EDB32ACULL, 
            0x5801A65F9074B4D9ULL, 0x4527078527934B39ULL, 0x2E70E4A1487A5E02ULL, 0x098D65CCC275271AULL, 
            0xF0ACDDC2ADCB40C5ULL, 0x986F15287C8EB0BAULL, 0x055F416431BB35AEULL, 0xF1A2B0550BB025F0ULL, 
            0x28C12190DE4022A0ULL, 0x34D9E12B4E48B142ULL, 0xA48FF59407ADFF31ULL, 0xA5F9116C86E19F29ULL, 
            0x6DC1C64C724275EBULL, 0x781EC6B0C2A4270EULL, 0x3ADD2950156DE4F3ULL, 0x9B1C4800C16D3765ULL
        },
        {
            0x0B3EC75FCEE3069BULL, 0x2DA7DD8A82FF5989ULL, 0x12C9A5EE975FA8E9ULL, 0xBC94932FDA56D7FFULL, 
            0x951B8F7E615E2F2FULL, 0x0E92805A6D44FC4EULL, 0x0763AF7BE9A5CAE2ULL, 0xCC4A33573C586F62ULL, 
            0x9E09D94CB9BC6A8EULL, 0x2ABCD4072810AF13ULL, 0xC4EB785151C9E2F2ULL, 0xD9C0ECD5DC7CDDD6ULL, 
            0xE30C843E7782E40BULL, 0x1F8E8A606868DD39ULL, 0xA47F939C4E27A97CULL, 0xAA76ABA673113B8DULL, 
            0x1502D094C30E3184ULL, 0xE9DFB3EC63A3B246ULL, 0x82E406BA8EB88A0FULL, 0x34B81BB4C1CF6F4FULL, 
            0xC30B227DDD4103D5ULL, 0x3C7D36ED1898E00EULL, 0x25280C0C5D9510B0ULL, 0x78600273EC0CAB48ULL, 
            0x4BB41EB98D46665CULL, 0x64E116E89EBE0BA2ULL, 0x4FE17307E842273AULL, 0x829B786F7D38B792ULL, 
            0xCEF1C47A337A88E0ULL, 0x59EC3AE9AB64A53DULL, 0x0D1ED8F2A11D03B0ULL, 0x7255B6329D8ED6E0ULL
        },
        {
            0x6D9F4B855B40AD3EULL, 0x7C499A58F69F7F40ULL, 0xB5E080DB0BE99FDAULL, 0x05966375DF9D7D4DULL, 
            0xEC13424C33A514CEULL, 0xBAEC1C0AAE0A0036ULL, 0xC33B2EE2AC09EBBDULL, 0xD9814EAE52D12CEAULL, 
            0x0534C5EEAE2FE758ULL, 0x0F1AB69209FF64A9ULL, 0x659B00830B297F29ULL, 0xE4AFA7B1044FD1E0ULL, 
            0xDF44D35B6A5896FCULL, 0x0B23BCB5AF7D739BULL, 0x78164A5EF90619C8ULL, 0x8FB4706E025F086FULL, 
            0xF131EFB44A653E79ULL, 0xE608719A82FF00B9ULL, 0xB774857E8D9A5C7DULL, 0xE224D70F685A8CE9ULL, 
            0x653185E258EE516BULL, 0xB3E769118F5429A8ULL, 0xCF45D1268E67D2E1ULL, 0xDDA3063C7A6D8FFEULL, 
            0xCE8473AF2B7F41B4ULL, 0xB5B85870AF52AC26ULL, 0xD04D117E892657D7ULL, 0x4256B661220080DEULL, 
            0x7F227DC5809DA651ULL, 0xA4DA895423BA55ECULL, 0x40956229EDFE74FDULL, 0xF404DBD3618E6C52ULL
        },
        {
            0xBBE76863726C521BULL, 0x9F2FF94F30B39D2FULL, 0x9B5400123F3F0E41ULL, 0xA31D11FF0E5DDE58ULL, 
            0xC46E53F1459BD338ULL, 0xD72B068545F9E392ULL, 0x30767DFAB8F331C1ULL, 0x714F8FA52F1CBC87ULL, 
            0x0AD84E52C32647A8ULL, 0x48558433BDAAA77BULL, 0x038E82D53F5F5888ULL, 0x7981B584DACA6ACBULL, 
            0x409B67393B94E32AULL, 0x00935FD7E8DF59C5ULL, 0xB6B75DE2679D070EULL, 0x6246BACB5A8E8AFCULL, 
            0xE99B125EFF98A3F5ULL, 0x22B2359218D8301EULL, 0xF3FFC9B829ABC3D6ULL, 0x3E9F759BAECEE95AULL, 
            0xFA03FD04CCF093F8ULL, 0xFDB86A7B26ECC1FAULL, 0xEEA8971301296951ULL, 0x81CDF535B342517EULL, 
            0xBC432A91DDCDBBBEULL, 0x647EFA5EADA8BADAULL, 0x3342F2B42565B0D9ULL, 0x9A1807E1B7643049ULL, 
            0x797EBFC8F31189B3ULL, 0xE2FE532B6A3B1CAFULL, 0xDE31C0920B1C08C1ULL, 0x95AA2D348160C680ULL
        },
        {
            0x34F90D5217B33AD7ULL, 0xF93B4F888DDDAE09ULL, 0xA314F1B459138EF1ULL, 0x28D50B903BBC3E0FULL, 
            0x5F22921FF3F31297ULL, 0x12018DBDE5E4345CULL, 0x7DD40AB0E4C9A0B5ULL, 0x72C1301C792E0CD5ULL, 
            0x15644A871B186BBFULL, 0x63A6829467193044ULL, 0x76F8E5E0034AFB6DULL, 0xE9B8669CB7A70BE3ULL, 
            0x86ABD2BC79DE9AA5ULL, 0x5E064D86A10B3346ULL, 0x9D4860A632B2DDF8ULL, 0x8B842DE68282B4FCULL, 
            0xFE871C0CFC112B39ULL, 0xF2904D28A7C68565ULL, 0x558F6903446ABF3CULL, 0x1CC7AC206E2C3E78ULL, 
            0x4382190BB3CFCB17ULL, 0x2D2FC68EA87C93EEULL, 0x331BDBC1B74D2E8AULL, 0x2293C11A0904108FULL, 
            0x8B75FCF3B70ACAF9ULL, 0x37321606C99BC884ULL, 0x5B9520CE4DCDF57DULL, 0xE9165916599410BAULL, 
            0xDC4E1066E6B9DEE4ULL, 0xA37067D630A9F7F8ULL, 0x8C20C74BCC84AA11ULL, 0xC71B5F86CD7C7123ULL
        }
    },
    {
        {
            0x2AC43804904915EFULL, 0x908B6A18A3D282A5ULL, 0xD75E820B86C8344CULL, 0x0D9228D817D7B3ECULL, 
            0xCA1D43CFC714A8E2ULL, 0x8A1690A528BFC340ULL, 0xEAE602C5EDB0E77AULL, 0x1B9BAB9D1C79193FULL, 
            0xC396CD739DD335FEULL, 0xB445DBCDA1AFED33ULL, 0x3D6FDAF63E0C30FDULL, 0x125334B28BE88AAAULL, 
            0x78483C4F9AC619A6ULL, 0x5D5D5B920BF8D225ULL, 0x85A1D2B72A4C5322ULL, 0xF1632C182C4FB91DULL, 
            0xB95FC97EAF9DBF37ULL, 0xD92D6B1C8F2AC504ULL, 0x06F2B60FA1EA8C7FULL, 0xD4BD831E194332F8ULL, 
            0x989B8A2EC7954CA3ULL, 0x36F8295126362A9CULL, 0x597B8CBE0F73B77DULL, 0xA426911EB490891DULL, 
            0xA6A14079295C5CBBULL, 0x2C3F1EFB6414526CULL, 0x07821FF382A3AA12ULL, 0xFCAE505A51C0EAEEULL, 
            0x8A04767D41745C7AULL, 0xBBD80BEB471D6B14ULL, 0x0F06E770A1538241ULL, 0x787AA09DCA402D35ULL
        },
        {
            0xDF3941162FC86265ULL, 0x9FD128E5DA8AAE5FULL, 0xCBE6E697ECEC90EEULL, 0x2A3B011B901C4857ULL, 
            0x5A2A00ED614FC10CULL, 0xB7C8E2194ED4DC93ULL, 0x8F77614C7CD6BA86ULL, 0xAED72103D08C705EULL, 
            0x203D5407778DE1A5ULL, 0x702D2D0F4BC4081AULL, 0xAAA635181D1BE1E8ULL, 0xE526F0625AADAB55ULL, 
            0x50EBABCFD7BA8ABCULL, 0xFCE5C312AB72D16AULL, 0xA4FF13C428A7FC73ULL, 0xC2DA23051A6140C3ULL, 
            0x052DA7A175CECADAULL, 0xD1558DE5456215ABULL, 0xEFB230A7A84227C2ULL, 0xFCDA623D9867F577ULL, 
            0x2CED2503E120D22DULL, 0x868B086634C23200ULL, 0x88BB41BC60311A17ULL, 0x0B651DCEBCA83027ULL, 
            0x37EF5C42CE4F8D7BULL, 0x63623C0AC386C78AULL, 0xD437F1641759E015ULL, 0xCA895B5D2B24C0DCULL, 
            0xBDAFDE7C17A1C97FULL, 0x1E9178BE8783EDC0ULL, 0x87F195A9FDE343E8ULL, 0x534E9B0D93DA6DFCULL
        },
        {
            0x359744D13D4AC7CFULL, 0x65C01CD2D726811CULL, 0x76C8A1FEEC1E89B5ULL, 0x325AFE753A8CC70BULL, 
            0xB995D275983899C0ULL, 0xB2EE25ADB9052333ULL, 0xE99CC4BA9DAA5CAFULL, 0x75638D7CDA7443C9ULL, 
            0x08CEEB623F589281ULL, 0x79E34CC55237412AULL, 0x995CA62EBF0C1355ULL, 0x2091A7DF07F22B18ULL, 
            0xDB915C1ED1FB9AA5ULL, 0x12D8F420D1785986ULL, 0x4E2FBAAB1C64848CULL, 0xCA875D88CA317216ULL, 
            0xC76C736E106A9BBCULL, 0xCAD9DAC2CEA61C19ULL, 0xABD4304DB6C99E5BULL, 0xC47AC2BD1B271929ULL, 
            0xBB9F07755172EC44ULL, 0xB5FA50CC2065FA73ULL, 0x054C4478787E6998ULL, 0x4464BC4DCA0012ACULL, 
            0xCBCACCB26B9B8976ULL, 0x0FE160DC393D4BACULL, 0x87D55DDD07A7EDC7ULL, 0x4991F422C95551F9ULL, 
            0x1998611F158E20DCULL, 0xE4AECE9059C7E436ULL, 0xB7CCCC795A556994ULL, 0x308CB8F715FA0747ULL
        },
        {
            0x6C20F1E2F20F9522ULL, 0xD1F3EA8273CFEAA1ULL, 0x64E5226C5894CF6AULL, 0x31815EB357740C35ULL, 
            0x14373918E673BB47ULL, 0x520064C8543130DEULL, 0xE2B20959583DE02AULL, 0x85720B1133F826EFULL, 
            0x599F308E01776D88ULL, 0x33E622FF5F1C044CULL, 0xE1E7DB35C4032610ULL, 0xAAB95F5BEB76855DULL, 
            0x9EB931271CA69566ULL, 0xD6481C520FCED31FULL, 0xB3FE58C93EA9E2C4ULL, 0x3A892257FA4C52CAULL, 
            0x7909F404716E74F6ULL, 0x8A531741E2FC043EULL, 0xDB1968173646CB14ULL, 0x3F7245C4C3C0A71DULL, 
            0xA35F15F2B966E145ULL, 0x065B5F0C1C05A7F9ULL, 0x186D60007CE8C04AULL, 0x09018E11FF6602DDULL, 
            0x33A550E857B4B471ULL, 0x2E127425710F39B3ULL, 0xC101CE9C6DBE6084ULL, 0x294BD790EEA6F87FULL, 
            0xC8BE03C338B996B9ULL, 0x5A52CD1AD14E8099ULL, 0xCD1D704307134E99ULL, 0x522073D61B0B39A0ULL
        },
        {
            0xA11C979C175E30F3ULL, 0x88D0B91AB229B594ULL, 0x747D5DFABDF903DCULL, 0x117FFE81FF34CC62ULL, 
            0x639156E7AACB8707ULL, 0x60042EC126F8960EULL, 0xE1BC5482D3400319ULL, 0x8669C6E958B9A4B4ULL, 
            0x1D2BB04C7924EFF1ULL, 0x33CC7F1C13AE0B05ULL, 0xD853359C497005A6ULL, 0x579567F3020C9F81ULL, 
            0x81E265E8EEA2E76FULL, 0x6F10D6ABC7BE83F0ULL, 0x8E06B8E833C42E7FULL, 0x16D41ECC90E7CA8EULL, 
            0x63999E17A0A6EBC7ULL, 0xE70A1185F1D4579AULL, 0x8F1117A7A94FA892ULL, 0xB01CACB9B8FE14B0ULL, 
            0x57F60A78047A6734ULL, 0x1FD8210A76964264ULL, 0x0BCABEBCC1FC7C8FULL, 0xF36157547A80552BULL, 
            0x955181D8E794668EULL, 0xA9AB129398BFA018ULL, 0xFBC767C3805B666CULL, 0x017775E1812597CCULL, 
            0xBAB637806B3D23DEULL, 0x08DA6150898A41C1ULL, 0x5B24BB8A185CD11BULL, 0x857A2CE5397CC24BULL
        },
        {
            0x858A2EB9824E4946ULL, 0x52E4ED48A7FE0BCBULL, 0xAC38EDB4BFE3D0BFULL, 0x8340809C96391619ULL, 
            0x51EA68AA19CB6DB5ULL, 0xCE04F6A5BBB065F5ULL, 0x51871FDB4865CB30ULL, 0x633163F30BBEC597ULL, 
            0x1B096C6275CDD3D3ULL, 0xEA6A0DF8E30CF1E4ULL, 0xFA7268303FE49957ULL, 0x5E7566572D76EC22ULL, 
            0xC91024F9AD05D98CULL, 0xADC86C5BF055D293ULL, 0x5A0797B39F1CDF33ULL, 0xB6ECC12FA047DAD8ULL, 
            0x23C827420AC8B9A6ULL, 0x5653F58EDDC8E900ULL, 0xDBB495E68E81DC77ULL, 0xDA411241ACB97271ULL, 
            0xB320BACDEE4894E5ULL, 0x03472ADBDD9BDF2DULL, 0xC1F01BE2566E2D97ULL, 0x3D065C5B7B0000CDULL, 
            0x840860F34532608AULL, 0xE353FA48DC61F0BAULL, 0xD963CC72DDE809E3ULL, 0x8B24D6A634228E38ULL, 
            0x039C48DB06B4E118ULL, 0x30B1DB4F425325C0ULL, 0x8637FC50BF5CAC5EULL, 0xB05732BE9655DA46ULL
        }
    },
    {
        {
            0x1F97AE0577AFEF46ULL, 0xC7C7850221B9245AULL, 0xBF5FCD57EDC68B9DULL, 0x030FA3CD445C8375ULL, 
            0x1961EC8C9C657919ULL, 0xF704AFAAC0B4B102ULL, 0x2EEF6E15D261A4B2ULL, 0xC25A24AA91282F81ULL, 
            0xD19DB6246ED50B5CULL, 0x12F8A3ACDBC49CBCULL, 0x35F8A771921853EEULL, 0x6DBCEC46D487C7AFULL, 
            0x0809E59AB8B836A2ULL, 0x71661610F7F6399CULL, 0xE3ABED17B9A2CEAEULL, 0x90F642EA4632A6C8ULL, 
            0xABDC3EE66AB62E5CULL, 0xBBD97E1DA13B781EULL, 0xC869ADFB8FDF496CULL, 0x2D60A20EA9493A63ULL, 
            0xBA4CFFD22D3FF29CULL, 0xF8E935124214F4B4ULL, 0x2F6671F798926ABEULL, 0x29EBB044E44C075EULL, 
            0xE97D2839E64D3E6AULL, 0xA118A27C28C639ACULL, 0x188C742C51D8531AULL, 0x4624F389031E838AULL, 
            0xE7DB1965CF433A86ULL, 0x7246E2AB9CD030CAULL, 0x43E91E758A0E87B1ULL, 0xD68E39DA57766449ULL
        },
        {
            0x7C4BA6DD2265E7C7ULL, 0xE8D9F2DA65039676ULL, 0x29FFEBACD9334DC1ULL, 0x0275838F87D93C19ULL, 
            0x6BBC9714B9598A6FULL, 0xE319D9AF608E209AULL, 0xF4634CF102FED58EULL, 0x0DADBE84D3184381ULL, 
            0x36D764AA27721B10ULL, 0xC200E630BD84F5F9ULL, 0x0620CACF2FACFF62ULL, 0x9F3C901C075330A9ULL, 
            0xB196FE947970B903ULL, 0xD73CC5AC79A588DFULL, 0x811162EB5D72A844ULL, 0xEB7BE68A9606F10BULL, 
            0xC156D41DD1A9D29EULL, 0x3228253AB2C75F56ULL, 0x8B7A0FB01AFE0720ULL, 0x74B296D5A2FE53C7ULL, 
            0x134983698733249EULL, 0x5FDA0A6E377F50C4ULL, 0x9D984E2DD810F4F2ULL, 0x2026A15AA3EC5E39ULL, 
            0x1F07C0314026A094ULL, 0x1BA0BF40A138DAFAULL, 0x14B49611A054C93FULL, 0x44FB6EF05EF0100AULL, 
            0xA64764C7174B8961ULL, 0x1FB431DE3B9A10FDULL, 0xBC8D3C736C7DE8EEULL, 0x408A6E83858D626BULL
        },
        {
            0xB6CCC795F1A67600ULL, 0x4E768A3E9D7723D1ULL, 0x3B6780B1807F7F1AULL, 0x226DA9F398944CACULL, 
            0x9CBBE0768CDB6278ULL, 0x1F498BB84FF604C7ULL, 0xF3FB0EF5499C992BULL, 0x1AC029BA3C290D35ULL, 
            0xAA75C532B22B4CE3ULL, 0x33C419FA00589637ULL, 0xB8BC0D37D25261E3ULL, 0x8B53E6B5997043DAULL, 
            0x6088A3F274732945ULL, 0x06A069AEAF125619ULL, 0xAD976AFCB8E4D41FULL, 0xCA7A1C102FC95E5EULL, 
            0xF3950672D8112D4FULL, 0xEE375585F34553F1ULL, 0xA38D764767321927ULL, 0xC94825165BA9312EULL, 
            0x5D9E4A72EB9152CAULL, 0x5D8505D2B419D01DULL, 0xAF50D165CB443522ULL, 0x5457102D105E2DECULL, 
            0x32057E35402934BEULL, 0x76434D2F24CA1BC5ULL, 0x962F95BC1DF84A11ULL, 0x3C5E70FA95FF27B3ULL, 
            0x0FF4A54DD346DC63ULL, 0x20A1A060884DAF38ULL, 0xA3674D45892E32A7ULL, 0x827A0724C21D2CD5ULL
        },
        {
            0x51464210C0F8731DULL, 0xD0C33EBD531E2BDEULL, 0x1B2087F2675E5E49ULL, 0x73623F607941C0C8ULL, 
            0x03B367B8F1789623ULL, 0xFA5C7D2F08CC34FFULL, 0x28D74569A1C4D1DEULL, 0xAF8DADC8CCA8AB27ULL, 
            0x2D792589747695C3ULL, 0x0542FE3B683D1397ULL, 0xBA7026C13D60EC3FULL, 0xA6B1112C666A0307ULL, 
            0xFB27B4867F417220ULL, 0xDDC5B756A1C9FB50ULL, 0x8E87A10A084A52DDULL, 0xCCCCD7C12DA30ED7ULL, 
            0x31C71EF3C8F69906ULL, 0xB912F72E17F7B648ULL, 0x225EC18A59B072E2ULL, 0xAFD370B39216747CULL, 
            0x9D05F56CCD92483AULL, 0xE4B440DC36FE7F9DULL, 0xD759F5524D5AE139ULL, 0xCFBB3AB18ACE7BF2ULL, 
            0x0A97281E90584069ULL, 0x65FF254B64049392ULL, 0x69F6B3CC2B8B0DD1ULL, 0x0FDD0DA1853E763CULL, 
            0x022074E9B322EF74ULL, 0xE231E79CAC872C7EULL, 0xB1027E78F9E44D3FULL, 0xE4572EA5DD2E5B89ULL
        },
        {
            0x6B03E8CAF6478993ULL, 0xEFB75EC2345B251BULL, 0xA4B674440BE4D7DAULL, 0x209A97682A7EA6B3ULL, 
            0x4B154E2FF8104FACULL, 0x1E8697B661717816ULL, 0x37BAACC089B92A38ULL, 0xFC1515900AC9CBA7ULL, 
            0x5A858D015AEB05BDULL, 0x88A879D665F3BCEFULL, 0x4A341D6C605BE735ULL, 0x9BE342D4D2BBA7C4ULL, 
            0xEED26138090F994DULL, 0x5712AD80B493795BULL, 0x7D7905777482AFCAULL, 0x0FA9ED0118734987ULL, 
            0x7814B6F7B0258BC3ULL, 0xB3F7688E01A91321ULL, 0x741BA0FE8935485BULL, 0xD982C798DA5022EBULL, 
            0xD2B21BF5C26EE699ULL, 0xF8B226D8D5DC62F8ULL, 0xFB940B5669E4B15FULL, 0x4E264BAB20E6B467ULL, 
            0x217C521A5C25FB5CULL, 0x4FFED0CAEF464AA4ULL, 0x3FC97A4D1223F7E3ULL, 0x1A62144B1649751DULL, 
            0xF4904388D85F3274ULL, 0x61A1C406682632B7ULL, 0x8BA4FAE364307EBFULL, 0xF632F51E3A13A5E7ULL
        },
        {
            0x310F7CB276E9A7C5ULL, 0x121491D9CDB48251ULL, 0xD3EB13ECB8C9442FULL, 0x6485A990CC7C4CD0ULL, 
            0xC35FA8D588E2FD58ULL, 0xD62326584E080F87ULL, 0x0E59551FE09C7E6AULL, 0xA2446B103F12B5A1ULL, 
            0xA538F7807FFCD982ULL, 0x8CDD796C395D2608ULL, 0x55DF25B99A1CFE2EULL, 0x02B30BF2E29553E1ULL, 
            0x070F0BF1A4BDC939ULL, 0xFB8743DCAD44DA62ULL, 0xC4C6AA108DC4A92BULL, 0x8A7D20D461DD6163ULL, 
            0xF30DFFF531B1F4E1ULL, 0xA3E7D9296CABF537ULL, 0x11B9163E4A43F575ULL, 0xE9B3C48DC220D22AULL, 
            0xD4BF9B1F8396F150ULL, 0x05C7162E3AAD76BEULL, 0x78599C1869D0DC82ULL, 0xCFE48B988020E4C1ULL, 
            0x178E362882224410ULL, 0x5A2A921AE63FAC4FULL, 0x0AA13DD4475826E5ULL, 0x316820FA144A57F2ULL, 
            0xB3B12B30CD2FE3AAULL, 0x6FE6EC886B6AF4F1ULL, 0x1B7D916AAA0B726CULL, 0x0C787BC493D159FBULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mebsuta::kKeySpawnConstants = {
    0x91D661AA05D89D55ULL,
    0xD2A1ED4E9D501C16ULL,
    0x58A4D7F573BC3E17ULL,
    0x91D661AA05D89D55ULL,
    0xD2A1ED4E9D501C16ULL,
    0x58A4D7F573BC3E17ULL,
    0xF8E4009C0E5BCF3CULL,
    0xF98D2AF27BD39E21ULL,
    0xAA,
    0x40,
    0xE0,
    0xEB,
    0xD9,
    0x2C,
    0x0D,
    0x6B
};

const TwistDomainSaltSet TwistExpander_Mebsuta::kSeedSalts = {
    {
        {
            0x1AE086A4FE59F9E6ULL, 0x41FDDBB3F77B5C98ULL, 0x457A329C7C35B912ULL, 0xE753585FF9E2A743ULL, 
            0xDFCD06359DDB17A2ULL, 0x74B0DB1714984F7CULL, 0xE9E42C74564650F2ULL, 0xE51BE9320B0FFA31ULL, 
            0x5EAC856D6FE8D454ULL, 0x4BC09BD4BE279FEEULL, 0x817123AEEEE9F07EULL, 0x9EE2910567F581CCULL, 
            0x9F43AFFD68AB93FCULL, 0x627C6DB8767A38FFULL, 0x1EF0599F1BF53A81ULL, 0xFEA01A5CC125DDFFULL, 
            0x946F19D31D6AFA5EULL, 0x130CE00483358634ULL, 0x8420D9DDF9867240ULL, 0xCD46C94A0DB4BDE2ULL, 
            0x5CEDC4A3F931A017ULL, 0xEC04BD5B151F2AA7ULL, 0x3D664074BF2FEC71ULL, 0x28AF5868516CDDC2ULL, 
            0xDF2247C2185BBA39ULL, 0x46546E1D7DB5E3CFULL, 0xFFB0BB23E791EAA0ULL, 0xF7ED14077F44E650ULL, 
            0x0A7A2A53D54E9E64ULL, 0x710FDC9D0B3494EFULL, 0x930939A5DC60D2B8ULL, 0xF81021F249D64A41ULL
        },
        {
            0x600F9D330EAF721FULL, 0x15A17ED9A6482A1CULL, 0x16335638FF118D9CULL, 0xEE714A179AE45721ULL, 
            0xCEBC38B11F176551ULL, 0x86C9917D479D661CULL, 0xE7D20CA6FF2A4518ULL, 0x545B8ED941E7D664ULL, 
            0xB6B8DADF2399E9C5ULL, 0x3C3563263BAA9924ULL, 0x6F6688C6FF520483ULL, 0x0BA38292CD0492A5ULL, 
            0xA12EA90D693C2A1FULL, 0x78D56BADF20E1F0EULL, 0xF96DA976DA6CCC78ULL, 0x280BC7DBB9C7C16BULL, 
            0xF68D1A79B1E13067ULL, 0x26087441A9BB5A5DULL, 0x9CE876A7A4531DECULL, 0x5A7648697139C9FFULL, 
            0xC25CA9C9FEFA6117ULL, 0x68122D838A00F331ULL, 0xACE9F06861A68907ULL, 0x98143347EFF7B70CULL, 
            0x1D14EBBF1D174E89ULL, 0x65C114F99C65EBCAULL, 0x1C76B208432C92D9ULL, 0x191BB36DDB7FD0B1ULL, 
            0x93D3E96303522819ULL, 0xB9A355C06AC14A39ULL, 0xA22C0BE6333AFA0AULL, 0x8D2FE4F3C1BFE2F7ULL
        },
        {
            0x623A49AAA76C6F78ULL, 0x93BCD953A32D1844ULL, 0x3742143B803E90E4ULL, 0x40D83F9C78C98839ULL, 
            0x1B1A65B63E93CCF1ULL, 0x2B8239E6B30AB046ULL, 0xF1792D51F674618AULL, 0x6EB9D08AD135A3F3ULL, 
            0xA0563998D27F9F18ULL, 0x8E411F80AA7E74D0ULL, 0x5AF6F42FEBC1A5F4ULL, 0x3985472E5B2260FFULL, 
            0xDA750EBACF114EFDULL, 0x0AB1E0999A028FB1ULL, 0x897B969BD9633299ULL, 0xAEE2DA3536EA8A91ULL, 
            0x52C0F16CF9F0C062ULL, 0x0556AD0DCFEC2AC8ULL, 0x796932651691F8B2ULL, 0x216FFA539D70E7B2ULL, 
            0x4233E5EBF9EE4576ULL, 0xA330FB5EFF0F1BD6ULL, 0xAEC611B740F645D7ULL, 0xD1633DED6862747AULL, 
            0x573BCD866E4F0C7AULL, 0x0F9E8460CDC745DCULL, 0x801997C14FE69D8CULL, 0x8165097A9D74A260ULL, 
            0xCC8E2FA881037F05ULL, 0x01200C77DE7850AEULL, 0x300884F089F21E8EULL, 0x16DC0A235D87D042ULL
        },
        {
            0x7573211904865E93ULL, 0x64510867DDAF9BA3ULL, 0x9E36BC96C53C1E1CULL, 0xBC0593B26334865DULL, 
            0xF8B0BF413D94BC62ULL, 0xA93D3917AD05049CULL, 0x3793846DB8C842A3ULL, 0xF61299F165E60175ULL, 
            0xB1294286CDE409C4ULL, 0xE253D55159117EECULL, 0x32DCD7DB2422A10EULL, 0xFD4993BABFBFD5ABULL, 
            0x350878F418ACEE38ULL, 0x129B178C330E9E27ULL, 0xD54575FC518BC810ULL, 0x05E8F0BF898905CDULL, 
            0x0754F3719BF4AAB8ULL, 0x31EBBB9586E2FDE7ULL, 0xFA096C9AE1207772ULL, 0x5FDE40020B7AB2FDULL, 
            0xF5DF61024D4DAE5CULL, 0xA6267695FDFCA34BULL, 0x2A37EFC0F65EBFCEULL, 0x4F83D78D9EE7288BULL, 
            0x90D4A9B94F552F48ULL, 0x62D71C7DE63146CDULL, 0xF44402668567EFB1ULL, 0x97E48305ADD426E1ULL, 
            0xFDF081CCD6A64D45ULL, 0xDF71E0D96E6E2BE0ULL, 0xD88215A51503A16BULL, 0x2D0DC11D6C06FBF9ULL
        },
        {
            0xBE03045237A029C7ULL, 0xC13FF043CC500A16ULL, 0xE0017E2BD67E75E9ULL, 0x6CDD23A25BFABF23ULL, 
            0x4F40F09F4CC653AAULL, 0xD485D8B5FEE10ED5ULL, 0xC630616F60AD0377ULL, 0x76FF84210D7AFD82ULL, 
            0xA1455890201B2E3FULL, 0xCE75151B2922A591ULL, 0x241501A3563ACAB1ULL, 0x8D322352605FF428ULL, 
            0xD9A4EE817D29E959ULL, 0x0195D0698FD5E5D4ULL, 0x9CF39AF8D897EDBDULL, 0x0BFF80C07BAB3B62ULL, 
            0xDFBED342FAEB3337ULL, 0x81194B9544524624ULL, 0x250170733EDD14E5ULL, 0x9C11CD065D70AC37ULL, 
            0x3AFBB52E4F118B70ULL, 0x70DB29F074D140A3ULL, 0x3933D19303EFEC46ULL, 0xB9FECB3C30DB1FD2ULL, 
            0xE225171A88AEF58AULL, 0x253D1D75E4301B80ULL, 0xCA7C2BA1910AA8A4ULL, 0x306D6B58136910CAULL, 
            0x76DBEF842E9089F7ULL, 0x84F67F582BEEB418ULL, 0x3E1F3402AECEECAFULL, 0x2E39BA69A60E908CULL
        },
        {
            0x068D20AA1FE8091CULL, 0x5F4E15107F17168FULL, 0x1D5C440777092D96ULL, 0x22641A43BF2845DEULL, 
            0x04AB4B629ED93B59ULL, 0xBB3E551A5E43C926ULL, 0x189A6337EAD6B1E7ULL, 0x99BBFB27C0DA52AEULL, 
            0x17C82E2B71E2D666ULL, 0x144E06806B6AF1F8ULL, 0xD49BDD476E0A6914ULL, 0xCFD0BF0EF210E1FCULL, 
            0xEF8E341C3DB572DFULL, 0xB63B72F432CFD536ULL, 0x57B3B74B86A747E3ULL, 0x681E5CA7C229EFFAULL, 
            0xA1BF7DEF193EC29AULL, 0x8A0C653169ED6EA2ULL, 0xEFF0DD1B47F0626CULL, 0xDA2D14E1FBEC306CULL, 
            0x4FA53DBBE7029144ULL, 0x5D301F4FC55E4E47ULL, 0x7801574957F1A406ULL, 0xBC23ED6076995748ULL, 
            0xF99F85390553ABDDULL, 0xF977EBA7D80AEBEAULL, 0xBD30FCC5E3951BC1ULL, 0x5105D565CB9BEA83ULL, 
            0xF12144EA1A0E202AULL, 0xE6DB413A4150DE52ULL, 0x545FB108C7B76F57ULL, 0x03E34D0D40AFC1DFULL
        }
    },
    {
        {
            0x6827BF648ACE06B3ULL, 0x3DBB81AD398D62F3ULL, 0x0BB92896C864F07EULL, 0x1C2BF8DA668F6FDAULL, 
            0xA49CBB07D0B5E3E4ULL, 0xEB53B0219B30C101ULL, 0xECAE8C2F9A6B0C4AULL, 0x9D39D4E525582684ULL, 
            0x74F83B2CDAB35DDCULL, 0x91E1E5266FB17FCFULL, 0x7C221DFE65F2B3EDULL, 0xCC5B013646359A23ULL, 
            0x7E93DA01D5A02636ULL, 0x75EB14F490DF698BULL, 0x9B6AD99374DB4297ULL, 0xDF3C964104D744EAULL, 
            0x69941FE5478D3367ULL, 0x691114204C180CB7ULL, 0x9388872ADF5EA982ULL, 0x992F6710DC1264A3ULL, 
            0xAB053F735E5598ACULL, 0x832C0983019D209FULL, 0xD4BE8E4D748D2ED4ULL, 0x3DDD131F839093C1ULL, 
            0x16287867823356CAULL, 0x00D80A1D09F33EDCULL, 0x7772D80765258248ULL, 0x8371AE5BF57DBF58ULL, 
            0xCEFAB18F9E46FC53ULL, 0x6BBD9E3937E44AA3ULL, 0xC9EE566B85F36DDBULL, 0x2283C8444A8A9649ULL
        },
        {
            0xBC8F16F4AA352E3FULL, 0x6960AF0415BF3423ULL, 0x440A6419C2138AA2ULL, 0xD6DB35418070B5F2ULL, 
            0x4F67B1EB60CFAFC2ULL, 0x28EA7C6E651BD5EDULL, 0x529DE18499D7DA1CULL, 0x2043F6B1A8D306F1ULL, 
            0xC1A0ABED219424AAULL, 0x5072BF8F57061860ULL, 0xB58E304D588DDF78ULL, 0xDDF93AC2FBBE1EAFULL, 
            0x39CE69AFC219352DULL, 0xC9551A122A49CFFCULL, 0x4DB09F2580210FB0ULL, 0x93C40824147AC325ULL, 
            0xA92B8E83AB272B97ULL, 0x1EE415F187C06FE6ULL, 0x78F25FADA3B976B7ULL, 0x2655CF87CB338510ULL, 
            0xAF16E0BF9B3CD09DULL, 0xDE5570BFA4D0DA4AULL, 0xEBB2486F52DEE074ULL, 0xE61CBD090974EA1FULL, 
            0xBD41CA5DB0A33CBDULL, 0x70EA9D0EEF84BD38ULL, 0x9B3FD2BD1E611A68ULL, 0x52D61AAE3E17BE24ULL, 
            0x9C47864662E8AF06ULL, 0x00461A79E573AFE1ULL, 0xEA56129F8FD47057ULL, 0x6B059552B32DD143ULL
        },
        {
            0x5C03254D69B651FCULL, 0xB32ADBB6BB9A3A60ULL, 0x04BDBB58BE0D6B7BULL, 0xDBBED8CE94311B44ULL, 
            0x703F83E879749FAEULL, 0x42ECDEE589F43D29ULL, 0xAC789E87DB43F7E8ULL, 0x15250D0C1AF0D53EULL, 
            0xAE3FB01731E5643BULL, 0xE8E72C7A8E6D8588ULL, 0xA40399908CA7E0C0ULL, 0x9B2FAA101F22610AULL, 
            0x4A7033895F1B2822ULL, 0x405984428F251308ULL, 0x8219381405B5AB9EULL, 0x2DC253BA049105E1ULL, 
            0x4F879F6C94F08D52ULL, 0xCED496CCAB5313DCULL, 0xA0A2544FD15440C5ULL, 0xCA27855D06106920ULL, 
            0xDBB07B3EEA04FDA8ULL, 0x6741A7225D64057AULL, 0xFA5C6599CF681E84ULL, 0x86A77129A75BE546ULL, 
            0x0E0D28163EA680A8ULL, 0x84E4BAD71CFCA10BULL, 0x1C820107AC818770ULL, 0x28D2EE6C6DECCD73ULL, 
            0xD904615B9E9EFB99ULL, 0x3604F5E0E959A006ULL, 0x66B8DB1F890F5EDEULL, 0xD8DAD1E1131D5A02ULL
        },
        {
            0xBB2DEEAE5C725056ULL, 0xB23857B991730B31ULL, 0x5EA73CDEDBA62B3DULL, 0xD54D4F64E506F657ULL, 
            0x48BF95A66F0643FDULL, 0x16666F7FB755ECCFULL, 0xA0B087837DE15485ULL, 0x2310DDCBE766ECE8ULL, 
            0x3CE063A2C04E4032ULL, 0xA642148AFE9F3FB6ULL, 0x7FC0C226008A2089ULL, 0xF5C08DB66AF546F4ULL, 
            0x1F76C8DFBF3D9891ULL, 0xF97FFB48E08355C1ULL, 0xC2456D91B9B5BC0DULL, 0x98F3B49602486B19ULL, 
            0x1B3D597DE1E51038ULL, 0x56EE2B10500AFA88ULL, 0xC535AC0FE737A86FULL, 0xA70FE56C2EA80F2EULL, 
            0xE2D0086649C27EE7ULL, 0xEF0CFFB8ABBDBD7EULL, 0x2D659B29F04E65EFULL, 0x7875AB4AF265087DULL, 
            0xEF20B21765868711ULL, 0x60CC635A9D6AFEB5ULL, 0xE6F8ABD162ED318CULL, 0xC80050C206076082ULL, 
            0xDDDD12A6EB3D8527ULL, 0xD4766D14591A39C0ULL, 0x8242D472C94CBAC6ULL, 0x57824CBFE484577AULL
        },
        {
            0x32F7B6ECDFD9E2D5ULL, 0xF2B4948E11FD6AC4ULL, 0xB5DDD6F4E3E97DBDULL, 0xADF9B6FE7FB79E50ULL, 
            0x81D2907A0EA8519BULL, 0x36C6EB3E17A94509ULL, 0x70E3703634283F7AULL, 0x043AE8A9CA007997ULL, 
            0x77594161CA36A11EULL, 0x2E51D4168F199E05ULL, 0x884A475C653EF00AULL, 0xE7D97FA7645B4283ULL, 
            0xDE5D8BB3F3020629ULL, 0xC3FEC7FB31F3D5AEULL, 0x38B059AF785D1F4BULL, 0xA44A5B94A193CE3FULL, 
            0x6A52B8231255767CULL, 0xD6A1B4A7812D928AULL, 0x989088EB4BA2A5C5ULL, 0x424F14243685F5D0ULL, 
            0x1D5932218C5F38EEULL, 0x0334209124017DE8ULL, 0xBAA9613903E0DC00ULL, 0xB5B178AED737D2CCULL, 
            0x5DFC101764D14BECULL, 0x300AB411F0439EBAULL, 0x13F178A15C7677A7ULL, 0x1B015331604F0354ULL, 
            0xCA67493BA43BF0A9ULL, 0x8F9265F6D64561F8ULL, 0x7F95681FBC744621ULL, 0xCCD52DB4D7D1EA70ULL
        },
        {
            0x9AFAE970C013A162ULL, 0xA8AD9228BB87E48BULL, 0x6C5E129525D5D211ULL, 0xCD2C30AB4A3C36BFULL, 
            0xE55FEB33750BD0D5ULL, 0x0C421C5FA2554A57ULL, 0xD9A88F1F25B5942BULL, 0x43B9FEC34877B15BULL, 
            0xE0D2B84527C2F515ULL, 0xC74A33725935A0C9ULL, 0xD4C7A8E21D2DFC8CULL, 0x303F33B6AE4257A7ULL, 
            0x77137F54B2311063ULL, 0x304C10FCE332D811ULL, 0x343C02FE73505036ULL, 0x5C78CADAEE2EE7CBULL, 
            0xF64E1CF9B22FAE26ULL, 0xE578B2316E18FE88ULL, 0x87C725CAA0A6987AULL, 0xB774A83450FCF952ULL, 
            0xA4277857F1AB1BBFULL, 0xFF8A84739F82C56AULL, 0x16A966225EBF58C5ULL, 0x1A8BE43E8C1F9716ULL, 
            0xD0267A079192F736ULL, 0x038215DB804692ACULL, 0x72FEEF8DC32E9256ULL, 0xC6CA7AF80CA6A5EBULL, 
            0x0A2429437A5197B7ULL, 0x079D8A8A05EE1FBAULL, 0x195C2884A56E1262ULL, 0x6BC0D4CF9B9C18CEULL
        }
    },
    {
        {
            0x39043954A4CEE712ULL, 0x927A9AA706A8B54BULL, 0x7AD06A126A353E63ULL, 0xB35A5EB52CDEC0F1ULL, 
            0x99CCCCE2C6982F9EULL, 0x3DBE43EC7F8EC7CEULL, 0xCD6FF0B74584FE92ULL, 0x28C7918F5B983157ULL, 
            0x5D2AD362EE38C428ULL, 0x36B9B795163B4417ULL, 0x275F23BE9105F113ULL, 0xF54DEDA194153811ULL, 
            0x72F176031E8FB35AULL, 0x50B205E9115736EDULL, 0xC8F745ED3FDD9C64ULL, 0x08558CA0091329A7ULL, 
            0xC23F0DF92C69A036ULL, 0xD570CA14E2DCEB2FULL, 0x42053B9846B3E247ULL, 0xB91E2AC1A1884F20ULL, 
            0x973A129D410D0AD6ULL, 0x1EFD2FCCFC14258BULL, 0x69D60342575E6383ULL, 0x6C4BB8450681F8FFULL, 
            0xAA70C8EB69C3C796ULL, 0xB597190745A581D9ULL, 0x7107A3CF6C52C067ULL, 0x275BDF919123780FULL, 
            0x914FD1656337F2BBULL, 0x382626197E8CA395ULL, 0xFCCE54270F2AECD0ULL, 0xA7D917E06B17D3AAULL
        },
        {
            0xEB86F8AC17AE7B71ULL, 0xBEE4139938CF0D1EULL, 0x9815D5DC9DF428CBULL, 0x4B611A374319357EULL, 
            0xC6B336763677F8C8ULL, 0x08F06DBF4402919EULL, 0xEABB527BFB1FFEBEULL, 0xD6E3C5CF1378B8FCULL, 
            0x43F60B8911E6989FULL, 0x8C191F80C4E6A7E6ULL, 0xFC2AB75B88B755B5ULL, 0xA9DBD13AC26B6C48ULL, 
            0x00ED245C5FF90DE2ULL, 0xDF169F52336016C5ULL, 0x50D0DD38CDDB5C44ULL, 0xD3D56673F4CDFBE6ULL, 
            0x0385B9752C80B92CULL, 0x7FCDC2B7D5F552EDULL, 0x37A219FECD7990A8ULL, 0x0E0B0E1E6A71C1A4ULL, 
            0x66854E607E07C2EDULL, 0x7299AD212D039D9BULL, 0xE1E5B5E6B6A74982ULL, 0xC4FED9DFA052C55BULL, 
            0x0366F9CD889693A9ULL, 0x4FE0AC17B1F7D9D8ULL, 0xA4B3BBE68393FE0AULL, 0x7A5CC58776D16F59ULL, 
            0xA2DCBEA090956B48ULL, 0x8210FBBD7357483BULL, 0x271DD5831042B658ULL, 0x2BEA4B15A21F9222ULL
        },
        {
            0x2CC34EC1C6D2C436ULL, 0x13A98C6F7739A85DULL, 0xF32C8D03783B09D5ULL, 0x9705CC9713795140ULL, 
            0xAF8AE2EA905C2C8AULL, 0x93E02178D58B35B6ULL, 0x3B3DD54F74A8ACA8ULL, 0x12E343132EE89AF5ULL, 
            0x6DC68C82AC794CCDULL, 0x8859A3963AB755D7ULL, 0xF531274DC5348129ULL, 0x997FA4BEF4D26D79ULL, 
            0x56BD95771E2E1384ULL, 0x9889A8C9D2DDFC93ULL, 0x02A3456F13FB7305ULL, 0xF1E11F8F385C2A5CULL, 
            0xE762AEE5531BEEBCULL, 0xC3E6BCC286343640ULL, 0xD6430DFAC49CAD5EULL, 0x94B7BE9C40D1BBC2ULL, 
            0x2204272AF60BAEDCULL, 0x753F84D36FC50230ULL, 0xCF829C046B55204AULL, 0x7012BA1D964D9B83ULL, 
            0xD0E35D80DBE1DA9BULL, 0x9FA09ECE4355F2F1ULL, 0x05C1C8938C600455ULL, 0x858E44920C385859ULL, 
            0xE738E66D4C9DD1D4ULL, 0x74893792CEBCD54CULL, 0x86F18BC84CAE0126ULL, 0x6A804226A3A97FC3ULL
        },
        {
            0x8DE997DB80B12E10ULL, 0xEF9AD8ACEF9CB3C9ULL, 0x223BE441A7E88D97ULL, 0xEF5708E38A8D0A41ULL, 
            0x95A0A173B56A1B0BULL, 0xE3E92AD87E13DC54ULL, 0x15FB697739A436C3ULL, 0x7012E037D1A04AF6ULL, 
            0xB0266F9C8465BC90ULL, 0xA43E1B52F7E30EBFULL, 0x0493469A332CF6F2ULL, 0xB4D232A82C598493ULL, 
            0xA43C910F195B49C5ULL, 0x21BD665338CDAB31ULL, 0x4C4DDEFAC51F2422ULL, 0x19BC219DAFD1E612ULL, 
            0x906EEE96E8466275ULL, 0x8B5211DD2CA61815ULL, 0x2D2D2243C655068AULL, 0x929764F05C3D97ECULL, 
            0x2A23308D8410CEC4ULL, 0xDE4FDFCA1336F106ULL, 0x34EB9B3CDBB596C7ULL, 0x440618285A5B0FE2ULL, 
            0x93A288E2DCFEAADCULL, 0x2ABDAA57DB2ABBF9ULL, 0x15D6247A8D77A362ULL, 0x2ED168F444CFACB8ULL, 
            0x3BD1F39FDC65C1D6ULL, 0x1553C523DC7525B1ULL, 0x81081B0EBF33CB33ULL, 0x1F6DE89B137299BFULL
        },
        {
            0xD9D85D40458CD0FBULL, 0xC831BDE83314482FULL, 0xAE335D7396ED58F4ULL, 0x2CFC3C572079553DULL, 
            0x49B3822AF1D7DA6EULL, 0x7C6DCC8D6F7739C7ULL, 0xB7319697F14CF56FULL, 0x15EE4A24DFE3DEACULL, 
            0x682315B7E867C2E7ULL, 0x91D3DBB5A32D1A47ULL, 0x3434E837ED1B93AAULL, 0x68C5FA28FA51C0E2ULL, 
            0x8371C7822DF94F1EULL, 0x0B659AD3D5F133BAULL, 0xC528620721C3F585ULL, 0xF8EF34FEA2C84D32ULL, 
            0x84850E4B7F790F69ULL, 0x5365DC3D6DB9BBCBULL, 0x7A5BE2CFBC2529FCULL, 0x56BBFB57AAA9FF2DULL, 
            0x1441E37989A4600AULL, 0x2E3C750724011E7BULL, 0x217674AC43133533ULL, 0xF751D288A3A6F8C8ULL, 
            0x1450B5D7FC0B34BFULL, 0x7F456146E9D42DD6ULL, 0xB92D9CAA6012A3E7ULL, 0xA4AC0D5D38D09519ULL, 
            0x2516CEB873F80A3EULL, 0x54006FCF2AB07DAAULL, 0xDDA86FF8875C96B2ULL, 0xB042E29A469B153EULL
        },
        {
            0x5F20F63BD7C387ADULL, 0xC54D3B23682F3156ULL, 0xB184612CF835BBF3ULL, 0x289592CB258EBBA0ULL, 
            0xF117C7AA225D5A08ULL, 0x706976184C641985ULL, 0x53FEB925C16AD2BBULL, 0x52ED045C0A59702EULL, 
            0xC8B08CFD051EFF27ULL, 0x279A638345FA7468ULL, 0x29537FFDB4B877F0ULL, 0xB9729A4FC8F0FD58ULL, 
            0xCE2168808B7A500FULL, 0xC1AA28E66E019994ULL, 0x0DEB5F796878E516ULL, 0x23B8F3F92E6E7BE0ULL, 
            0xA2065BEE8AF34F76ULL, 0xB25CCA9B11040686ULL, 0x874E1A9DF07D4AD0ULL, 0xF5A6953FE6DBAECBULL, 
            0xEE00FCC90681D937ULL, 0x8E4792E2F32E8F30ULL, 0x04FECD458EC98DA9ULL, 0xF8E91B43AEA32FDBULL, 
            0x6E9995291CC01080ULL, 0x0A81BCA01967DB0AULL, 0x95BC89CDEA8375F2ULL, 0x8A8D50454501447DULL, 
            0x61825C6A1B48F207ULL, 0x8646A6A4BA92EFBDULL, 0x3D46EBFE0F55004BULL, 0xD747D6F8A9965445ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mebsuta::kSeedConstants = {
    0xAC442646F0B201B0ULL,
    0xAB4CE84AD7A27064ULL,
    0x06C9DB02BF638928ULL,
    0xAC442646F0B201B0ULL,
    0xAB4CE84AD7A27064ULL,
    0x06C9DB02BF638928ULL,
    0x091B6214E72F4575ULL,
    0x8942D6FD60241C5DULL,
    0xA5,
    0x26,
    0xE3,
    0xE8,
    0x4A,
    0x20,
    0x18,
    0x05
};

const TwistDomainSaltSet TwistExpander_Mebsuta::kTwistSalts = {
    {
        {
            0x0B09A0C02AA7BF4EULL, 0xBAAB8EEE1C1339A9ULL, 0x48D96B9E167EA023ULL, 0xB09CBFBC844D0E69ULL, 
            0xF9F6774935964FABULL, 0x3E606AAE6C7F98B7ULL, 0xC51C2D31D725DAADULL, 0xB79FECE8A492CEBAULL, 
            0xC4EF35079A487BF6ULL, 0xEE5DFCCCD2C874C4ULL, 0x589B84724C603458ULL, 0x1B50015B3AAAF30DULL, 
            0x3A2A218860F64FA9ULL, 0x96E7B16F53E8EC6AULL, 0xA8294F2DC222864FULL, 0xA11478D1EE3FAB6EULL, 
            0x4B424BBF13F58957ULL, 0xD600092A16F26429ULL, 0x64937870E568D466ULL, 0xE71D7AB9325CC881ULL, 
            0x636A5048FD3BCE81ULL, 0x84B7595CCF02D855ULL, 0x69E8E95A3AF1F891ULL, 0xD6027D16F6D23EA3ULL, 
            0x7BDA8460D11C5EB3ULL, 0x68EA8DF31EBD1696ULL, 0xBE42064D791783C9ULL, 0xD76026949ED94CE8ULL, 
            0x748BA40BACD8A0C0ULL, 0x6868F1F449BCDF6EULL, 0x533670ADA295274DULL, 0x60C7BB5ED1C3FEFCULL
        },
        {
            0xEB75730CBD824C25ULL, 0xA24CABAB80840D2EULL, 0x98CA5C31023276C7ULL, 0x8769B019D618BDE6ULL, 
            0x5223012AD4D99355ULL, 0xFC39AB28096582D4ULL, 0x8C51A1853E45EF48ULL, 0x5971DBD12EEAEB70ULL, 
            0x5BB6E9C5126C65C2ULL, 0x62E7E6F6C9D5C61AULL, 0xA91EE3715B7FB15FULL, 0xAB8A31007E020F40ULL, 
            0x3EFC6666F6D7136AULL, 0x8EE23048D286D2F4ULL, 0x3EB7EBD84ECCA3F1ULL, 0x9D3A60762921AD21ULL, 
            0x1FCBBCFA82386AEBULL, 0xBFE473D5E9343627ULL, 0x16347DCAB7D36407ULL, 0x45694B28E884AEEDULL, 
            0x0A1B319C609CA554ULL, 0x3C8DEC684B63C08FULL, 0x92FDE6A432E16498ULL, 0x1C42A773EAD70D9DULL, 
            0x79628587EAE9BB20ULL, 0x495BC57609C88009ULL, 0xF94E6DC2102B5923ULL, 0x1AC9CBE650F76CA0ULL, 
            0x5C13EE41575BC2C0ULL, 0x526D1E918EB48D25ULL, 0x47A6A29EC747247CULL, 0x6FF638043DB94EA4ULL
        },
        {
            0x7C23B78C5A4A63FCULL, 0x9B99A8785F9D2790ULL, 0xA0151111480ED3BBULL, 0xE6CC7F20AF4A4A28ULL, 
            0xECF99724BD43B9B9ULL, 0xFB7B0B64AC263524ULL, 0x5975BC24DD23A651ULL, 0xB2CF3DD43AEA3DFCULL, 
            0x0FBDABD584463192ULL, 0xEF41EBA426502C88ULL, 0x215703D2D8EBAB23ULL, 0x3DDD19556F508FB7ULL, 
            0x8A978C59DE41B23AULL, 0x5FB03602D96B4105ULL, 0x2E8341F8BE43449AULL, 0x67349C89C52BD550ULL, 
            0x51D0C4741BDB6824ULL, 0x7760EF04CBE9F7BCULL, 0xF5620E2C073E4645ULL, 0x4D3C772AA163CADDULL, 
            0x1E009C63A6E1CE7CULL, 0xD9E7724FF5D5DE9BULL, 0x244404DC41509353ULL, 0x7B132A0764CA4301ULL, 
            0xC085108D044B0C62ULL, 0xA05C59AB2CF5BE19ULL, 0x7F0566B92A3844BBULL, 0x8DBB19B230F876CAULL, 
            0x329707CA94ED8D2BULL, 0x46EF03F7DBD7CA08ULL, 0x3D1E0E5B0F31C85EULL, 0xF314310612B6557CULL
        },
        {
            0x1AF0F3E9E3D10DF8ULL, 0x0B1791A7119A83CCULL, 0xCEA4BE15AD0026D7ULL, 0x3473C63198125AABULL, 
            0xCC8D7BA191B41696ULL, 0x2DA984EE5165FFE9ULL, 0xDC985F09B0DBA31AULL, 0xE2AD15B86F2D978DULL, 
            0x865FE41ABE54381FULL, 0x5163F0DC5B691B99ULL, 0xBB7D924233C95FB5ULL, 0x6DE1A950FA4E5BF8ULL, 
            0x21346967A4403B23ULL, 0xC261B8FD918FDC7FULL, 0xFDB701C4A291915AULL, 0x52F86B56BE4034E3ULL, 
            0xA266E37456C751C8ULL, 0xBDEB50FB97801D29ULL, 0x5E4F02C3674EDFF1ULL, 0xBB03EDD630DCD200ULL, 
            0x60114E1FFB8C3D72ULL, 0xBF50B7EA9ED8F4AEULL, 0x13772D08A07303DBULL, 0xDB73266F9EE40B72ULL, 
            0x4F627D4719C037B6ULL, 0x1C1420324471F481ULL, 0x3E8F63579C558859ULL, 0x039E292B1E81F270ULL, 
            0x4C85BCAB3E528309ULL, 0x66975BE4435D2AAEULL, 0x109D39CA31A314F1ULL, 0x9831F68E31730E36ULL
        },
        {
            0xF6721937FB45686FULL, 0xCB9C82B7E6C3528DULL, 0x19C7A620F1B5E2CDULL, 0xBE3696C574A5DB60ULL, 
            0x28951C8271C445EDULL, 0x066408515E007FACULL, 0xA8FECE22B2B1908DULL, 0xE5F51B23368431ECULL, 
            0xEF8A4FCEC2FBEEB6ULL, 0xB0B366D67FD472B6ULL, 0x85F63C6A14718A05ULL, 0xEEDEF506363A7647ULL, 
            0x4E09D4297AC07209ULL, 0xFEC0296DD66A1E6DULL, 0xE0533DD8E9D73D96ULL, 0xB5C38B5EE519E419ULL, 
            0x3D2789712FDA8664ULL, 0x2BC372B73458DFC7ULL, 0x16ADCFFB7105CA0EULL, 0x92DB69AC446D4E25ULL, 
            0xA41961CCC018466FULL, 0x23ABCCE1A55EFAEBULL, 0xD3AA7C30ACB3B0CBULL, 0x369175A52EC272D8ULL, 
            0x94208F38D01DD682ULL, 0xF3F14E1589FF40D9ULL, 0xDFBC9EC4567A934BULL, 0x3BB82A7134CB681CULL, 
            0x4E25BF21143A1824ULL, 0x852F25ED74ADC8DFULL, 0x37720CCF7B339E11ULL, 0x51E4AE46F61BBE48ULL
        },
        {
            0xC4EDD74BC9CE1D24ULL, 0x59BE112C08B2EC96ULL, 0x9B8D785FBEE863E7ULL, 0x0C7FBACC60B83998ULL, 
            0x2F5B8B4A74FAA9D0ULL, 0x20B768FBB396BB48ULL, 0x20745088456FCD63ULL, 0x2AA0E73AF54C1D94ULL, 
            0x70B5D88CE5172CE3ULL, 0x00A09559377F72DBULL, 0x62FF02793BF88305ULL, 0xD6FBEE9D3FC39B6BULL, 
            0x7709734DE0E785B6ULL, 0x1F480F5D3C0A6BFCULL, 0xE6BE84C15D2961AAULL, 0x3EF03BEA8BFC33E5ULL, 
            0x5F9362165BE0682DULL, 0x34C3ACAA51035109ULL, 0xD5E169C33C1E5274ULL, 0x4D59A5923766E437ULL, 
            0x73882EC8C97C16A2ULL, 0xEA25B6D96687B3B2ULL, 0x2B062525E1A7E032ULL, 0xB809E7D8F6DE8529ULL, 
            0x9CBCE94B6DCBCA76ULL, 0x81A4F2734328CA4CULL, 0x0FF29C7361502375ULL, 0x5061CAB99501E004ULL, 
            0x1E24F5F86D641D7CULL, 0xA381AA30A501C329ULL, 0x0BEE9F7B59DBB989ULL, 0x8765417F2367FDA6ULL
        }
    },
    {
        {
            0x0242D22F330F47FEULL, 0x82CE2AC270862C57ULL, 0xC552BC98370AE7B4ULL, 0x99D7216DF0EE5249ULL, 
            0xA6AF7711C1526F53ULL, 0x8656DC947E892445ULL, 0x4D032C2B2FF18942ULL, 0x6AD4EFB448DE6CA1ULL, 
            0x2DEE42CA8A84219CULL, 0x89F475EF551DF7B4ULL, 0x1BE055A5FBFA2CBDULL, 0xE39E57550FC6CEF0ULL, 
            0xE6D405C4E6F2EE70ULL, 0xB7180032B669F695ULL, 0x1D381AFBDD0F2F03ULL, 0x828A9FB7373C328CULL, 
            0xAB025411DF426516ULL, 0xED7A39C3C7DD7A69ULL, 0x732AD6F60FE92CC3ULL, 0x4907E76DC8641FEBULL, 
            0x52E3C1C640847FC4ULL, 0xA40613CD4E25A4DFULL, 0xBEF0B526CFB300AEULL, 0x8E272DD893E10C04ULL, 
            0x428B900FFDF79D59ULL, 0x2D6E1B91A5C3DA70ULL, 0xC73CAAF53FAC7790ULL, 0x56B7B0A87EEDB99BULL, 
            0xE13114D40A83E031ULL, 0x7E019321FC46DF55ULL, 0xBC5CB3E142AFC3EDULL, 0x785BE04C2246BAC7ULL
        },
        {
            0xDB5DF16BFC6463C0ULL, 0x502C9C41E81B22B0ULL, 0x325A2A7A15DB0790ULL, 0x0E0DE873178E0310ULL, 
            0xA54C6CA40BC248B3ULL, 0x3A705A24002D52D0ULL, 0xE09511B657EF373EULL, 0x57286048196D5936ULL, 
            0xA2AEB43F5797EA8CULL, 0xB8E63CDD242D251DULL, 0x25BF46EEB60A8559ULL, 0xAB531163480E915AULL, 
            0xCA66AFEC510EE03BULL, 0x32782994F8348C62ULL, 0xBE8E0721A5594186ULL, 0x6DFAC2B612D6A7C6ULL, 
            0x28459C34A63AF254ULL, 0x9F920292DE9CB99AULL, 0x75303512C11607FAULL, 0x50DD22DAF7CEA2CAULL, 
            0xD6ED146941781483ULL, 0x8E88CB526B922E66ULL, 0xB347C0B0A3953453ULL, 0xC02B83995F9E44BEULL, 
            0xB21AF5AAB13A9DE0ULL, 0x14FF74FC55429D2DULL, 0xBA5A30A853805889ULL, 0xB0A1C8918B872153ULL, 
            0x320C0A930BD600E7ULL, 0x6764ABBDDE2DB848ULL, 0xDE815316E8EEDCDAULL, 0x9239E26B67E90ABEULL
        },
        {
            0x4B8CE3D3EEB5AB0BULL, 0x25FE284F7FF8DF64ULL, 0x7420FDE376F4BC44ULL, 0xB2A961908D7A585AULL, 
            0x30ADE185B2A329ABULL, 0xA98CBC11AD2F3AE0ULL, 0x4B88536DC72C0329ULL, 0x6BE636E8D084FF34ULL, 
            0xB268FABFEFCAB376ULL, 0xDFF0C26C7982BEA2ULL, 0x68911867120EDE13ULL, 0x8A3B78E9CA6FF7F9ULL, 
            0x6E55D9140A9523B0ULL, 0x1DF66856656B5D55ULL, 0x0C949E1D0BE433BCULL, 0x5E349FD49F012F06ULL, 
            0x3BBF43164E70281FULL, 0xBBFC4FCF0286EABDULL, 0xC830BBCB34FA4D09ULL, 0xE514729F4D85A564ULL, 
            0x5EB4E071394ED5AAULL, 0x4CF50A5326B10060ULL, 0x2254265C329C2801ULL, 0xCD69C62691A5EC8AULL, 
            0x9C7C25548B6BCDD5ULL, 0xB8821E7A2EBB5724ULL, 0x5A6EA856870D06BEULL, 0x9D417B1FAE048B78ULL, 
            0xB127E0DA9126B669ULL, 0x34CBDABA9F45D103ULL, 0x95ED585D05A6FE9DULL, 0x891608112E262700ULL
        },
        {
            0x56B8C894FC9F237BULL, 0xCA4D44D25FF323D4ULL, 0x9415510F5425F07FULL, 0x0253AA33BEC1C59AULL, 
            0x47302BB54F2F4706ULL, 0x94FA069538F9729AULL, 0x3CB1EFAE450812BCULL, 0x3A0F4A5F3E8640FAULL, 
            0x2D9AE265B575DA7EULL, 0x32C1E45A48828239ULL, 0x3BF4066CD1A1E79CULL, 0xF7D238486CD5B7DDULL, 
            0xBFBDCABF26838771ULL, 0xFACBC313589AC07AULL, 0xC53211C8A53BACF9ULL, 0x99BA32964221E30CULL, 
            0x89D59F8393F3229FULL, 0x908D99B12EC977B6ULL, 0x14EC0769353E3B9FULL, 0xACAAA613ADBE9265ULL, 
            0x7AFFEFC10631C2A8ULL, 0x306C62A609A756FCULL, 0x42A47F922CABA63DULL, 0xCF69A24DA00CFB76ULL, 
            0xCCF6F34C19492C87ULL, 0xD068AE32FCDE80E9ULL, 0x35A089A9025F21BEULL, 0x2DEF1743A4D34486ULL, 
            0x5AE2688524C4C599ULL, 0x22413285A5FEAADFULL, 0x18133A4B49FD2761ULL, 0xB09DCDE882C40D5BULL
        },
        {
            0x9213588246584B28ULL, 0xD675F11A3ADFDB3FULL, 0xC8C81831DC6CED85ULL, 0xDCA96B8A1F4C44E3ULL, 
            0xA06D632323ED4D1CULL, 0x980C50E3AEE3CF26ULL, 0xB86FB3DCD979E6BFULL, 0xB232220B0DEC354CULL, 
            0x9CCE2D83CF7FC800ULL, 0xE91AA7EA79B5D2A8ULL, 0xF5FB8693726B8952ULL, 0x905EC5DA389979C7ULL, 
            0x30667FFFB21E43F6ULL, 0x9F7A394FA3337B51ULL, 0x5DB8E1B4EE63C1A1ULL, 0xDC5D827ECCCDC464ULL, 
            0xB1B909024CAF6A30ULL, 0x91D8DDCF5489792FULL, 0x683780DE516F7173ULL, 0x48A097B1A60FC5A6ULL, 
            0xA033698D39FF7258ULL, 0x583A86F944C7702BULL, 0xEDF3337B10ACB9ADULL, 0x5475F73B3B856DCBULL, 
            0xA28808AF48E49C08ULL, 0xF521C54FF3FC5E9FULL, 0x1A566D804A3BAF5AULL, 0x66B9E410460E6678ULL, 
            0x28EA02915DAED185ULL, 0xA2621810F7C53B02ULL, 0x06B3232ACD1A366EULL, 0x2DE6BFE442C1DF23ULL
        },
        {
            0x83F4BFBD85BABFEBULL, 0x8A793B88A7533EAFULL, 0x794DC5AD55766733ULL, 0x2D97210B6250BBDFULL, 
            0x1781CD039D1C8F6EULL, 0x331749CA63814F04ULL, 0x107D4BFDB0A5C1DCULL, 0xB29CABB54491C6FBULL, 
            0xED64D0DA90371442ULL, 0x56EB74D9B5335524ULL, 0x8E9D4F6E2875EAFCULL, 0xF0A3F7EAC5D6B74AULL, 
            0x8096845B9B4072DFULL, 0x39DF5EFFB3E10CB6ULL, 0xD7CD216C99487E9FULL, 0x3C2820B828FFC1AEULL, 
            0x87B328BB1D65D2CCULL, 0x13530B41545C0A23ULL, 0x4652B7A3A9D42762ULL, 0xEC7250A82C435C14ULL, 
            0x2A9C4EB9F26D992CULL, 0x195E3A027CEF39F7ULL, 0x07136068E2889B4FULL, 0xDB3CC68627B3AC57ULL, 
            0x2C84C5865DE0D24DULL, 0xCBE23C83338C1D26ULL, 0x6292CBB86B7A901DULL, 0x7EA97FE028B5033CULL, 
            0x336696C0D8DD1E90ULL, 0x9C12806B59999FBFULL, 0x99AF2593C6A84CF9ULL, 0xF6AE14AA098E144AULL
        }
    },
    {
        {
            0x2F180912BFE72A81ULL, 0xF186DC00BB65B107ULL, 0x2ADE1B9CA5F9A405ULL, 0x91F26C7D91FA4622ULL, 
            0xC9C6E9857CBBA01EULL, 0x9A52D6AD820A5056ULL, 0x23B7B47F04A5B798ULL, 0xA97A31BA4814AB4EULL, 
            0xDE110F30A76363CBULL, 0xF203006FAAA753B6ULL, 0xE0873C6FF5EEABDDULL, 0x6D5FD17FDE0B2A25ULL, 
            0x6DC6E79C337E0153ULL, 0xACA7D4142A7C4272ULL, 0xB58F462809E93E52ULL, 0x77E68C96E075032CULL, 
            0x328249F366419475ULL, 0xBB7A5D2AFB8B1159ULL, 0x035C0E9130D3F40BULL, 0x1AAD7C82BB55E835ULL, 
            0xC9853DC2F343B6B4ULL, 0x676F076B16FDCF3BULL, 0x967E14B62D6BCFC0ULL, 0xB95293637099A489ULL, 
            0xB9B5137A9AF63EDBULL, 0xD12ED01C2E5EF917ULL, 0x449A92C5A18DFC02ULL, 0x78997A0791D3BD47ULL, 
            0x11285A73BCD91BA0ULL, 0xBFF7D2A6F793773CULL, 0xCBB2219B707903BAULL, 0xA6AEB1169A9440C7ULL
        },
        {
            0x163FD9EEA174EC1CULL, 0xF434B451A2942F3FULL, 0x56EEDB9EF4C45290ULL, 0x641349ABFCB0512CULL, 
            0xCC39E92EB37E4DD5ULL, 0x5FB82837E7162B6BULL, 0x3AF98A0064E53A27ULL, 0x0E08D3FBDA9D4E6AULL, 
            0xB23A094BDEBAA30DULL, 0x28D54A39265A4031ULL, 0x226C165984DF8381ULL, 0x7ECBDC2DDC1CF2B5ULL, 
            0x70BBE0BDE8542D9CULL, 0xB643258258E842F8ULL, 0x8CC44658C1DDC554ULL, 0xD65F47435DFF5021ULL, 
            0x6E3E0B1EE59346A7ULL, 0xFEDBF0C1E2C38549ULL, 0x2772EC4236704B37ULL, 0x62B17BC1388074F8ULL, 
            0x853C805CF24BC51CULL, 0xA3951B2DB48F1A41ULL, 0xDC9E5CCB430D0C43ULL, 0x28B4BCFBD480CE86ULL, 
            0x6EF97835F4666F6AULL, 0xCE360677AAF6CA08ULL, 0xB4A1B6D34D7284FAULL, 0x1F781B114BE6952EULL, 
            0xE8317F4EFDCC801DULL, 0xCF8E368A9D9DF407ULL, 0xFAA545A91EE1CDC4ULL, 0xC8F05292C7AA4131ULL
        },
        {
            0x25808270E9A9E024ULL, 0x535759CE477877FDULL, 0x87D5EEC2DE0F2B92ULL, 0xFDF307502A39C5A4ULL, 
            0x5F081B7C2167C995ULL, 0x15EAA47FC1539A54ULL, 0x296B1E0236DF3847ULL, 0xD54987D22E525BACULL, 
            0xE5A81EFD946F1799ULL, 0x3BEBC9CFC1FCE377ULL, 0xBC4D99AC6DB8FE03ULL, 0x532C4EE9DB34CD5AULL, 
            0xF88B670B3BD11D8EULL, 0x070C3AA6F27096E3ULL, 0xA495A27C38EC60E0ULL, 0x4289066F67423BC4ULL, 
            0xD3504A4911E46BD1ULL, 0x0484E5578D1FDE75ULL, 0x04083F67A5F6A456ULL, 0x126633A9C8445464ULL, 
            0xAB5D38414906465BULL, 0x814CD22115B3B7A2ULL, 0xB48DB244BD51C3DBULL, 0xCE1E2692D8CBDF04ULL, 
            0x87FD73455FEB4993ULL, 0x5109188B0F04F20CULL, 0x4E8779745557BDFFULL, 0x4A9EDC8A39136FDAULL, 
            0xD9C8F04EB7DF4BEAULL, 0xE3494211EC06301EULL, 0xAAE010C3E1596977ULL, 0xEFD4A1541CF7A36DULL
        },
        {
            0x21817C261E9976DAULL, 0xEF96658DA2D3166CULL, 0x5AFCA45560E9E0E8ULL, 0x3699BBD1F5B39E97ULL, 
            0x4AA379A8CB160830ULL, 0x00FC1B3F49A8FB9CULL, 0x43999E2416D90551ULL, 0xE29E35161CCB3C92ULL, 
            0xD3030D119E07F8ADULL, 0x92AF09FC6D113226ULL, 0xC0EB4A90632EE0CAULL, 0xBA8631E5518E23B0ULL, 
            0xC94C7C919802E7ACULL, 0x22DEFDE4F90EA756ULL, 0x75DC527445EEADB6ULL, 0x5DA93C87723627A7ULL, 
            0x0688A4E633469FBDULL, 0x26C92D411B11A56BULL, 0x375CBB3DD28A9992ULL, 0xE995A65F8EA1A628ULL, 
            0xAC929CB02D22E8B7ULL, 0xB30C12C5076E844CULL, 0xA5F0AA42C4901EACULL, 0x291BA00205F22FA3ULL, 
            0xEBC5F20FC51BB9FEULL, 0x85D7FCD6D4F034DDULL, 0xE31048C079F6BD47ULL, 0x021FEDECB86F8870ULL, 
            0xB27770AA02A93E4CULL, 0x7C5B56630FACADE6ULL, 0x6FC2CBA88F618687ULL, 0x52AF84E161C6972DULL
        },
        {
            0x7E368AC562D2515FULL, 0x4B2551282E417514ULL, 0xFAEC42FC34B8A634ULL, 0xD53B10024C6685C3ULL, 
            0x190691A31D5A16BAULL, 0xB5FD29EFBD8495D3ULL, 0x8CC348A986BDC441ULL, 0x7446214019AC2FFAULL, 
            0xB02D68A678ACA132ULL, 0xF637784FD3F88C4DULL, 0xC6C49008272630DCULL, 0x279486AEE4B8974CULL, 
            0x5E37F52784055DC5ULL, 0x18D49BED41F4F934ULL, 0xFA0F51F0BEC95D33ULL, 0xA6FB34790B317173ULL, 
            0x4920135F29232F27ULL, 0x596ECA6C8C373F4EULL, 0xD8F132A65F6563F0ULL, 0x363AE00BD2234CBDULL, 
            0xA4B0BFD1CD899C9FULL, 0x209ACD3A609E0C03ULL, 0x4AFD0092D4C614B7ULL, 0x70DBB313676B4F84ULL, 
            0x7722A6A752ADFBA8ULL, 0x1440F55D174D8811ULL, 0xF190BB8DE5B63BCEULL, 0xD5E01DC90DB5236FULL, 
            0x0A9D9D0B01EE148DULL, 0x191237B79323739AULL, 0x7D81D018188828C4ULL, 0x8F8F76994BFA0A3BULL
        },
        {
            0xFC64082590C2E713ULL, 0x398F25AA1788D27AULL, 0x80B442768FB957CCULL, 0x204A075BECC3B7A7ULL, 
            0x40D332502424515AULL, 0xF35F84AB54A482F5ULL, 0xB3BF22483A270955ULL, 0xF88803FBE48A7DA4ULL, 
            0x3DDFD033AAD147EBULL, 0x6666CA13EB6C4FFFULL, 0x1C86E10B9EB32F88ULL, 0x277C41DEB4F968F7ULL, 
            0xA0483A0011BA7D2AULL, 0x04CC5977CC4A9279ULL, 0xD137A6F32E048C5BULL, 0x06519D9477DC7186ULL, 
            0x1712D28D147EBA27ULL, 0xE6BF2D54161E26E0ULL, 0x97A4A1B67AC98C0CULL, 0x2C2A8D60B82D6F0AULL, 
            0x607917E2EC937CAEULL, 0x9736673E32780099ULL, 0x57AC2BF6B82C4505ULL, 0x492F25A5E76B6AD7ULL, 
            0xABC859871A23255AULL, 0xA5DC9882605BF952ULL, 0x385AFD214A284C2DULL, 0xFFF1E3D6AF1936CBULL, 
            0x97029A92504E8BF0ULL, 0x5274AB5DE38B538BULL, 0xE162C519490615D2ULL, 0x062E9BE3E7396FC6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mebsuta::kTwistConstants = {
    0x2A39DC6F60CAEE48ULL,
    0xDD4F45C5CB0FD7EEULL,
    0x91BDFEFB4DEBB0A5ULL,
    0x2A39DC6F60CAEE48ULL,
    0xDD4F45C5CB0FD7EEULL,
    0x91BDFEFB4DEBB0A5ULL,
    0xC4D6A80E7BDA3D24ULL,
    0x2D067C63EB772AA8ULL,
    0x0C,
    0x04,
    0x60,
    0x0B,
    0x56,
    0xCE,
    0x6C,
    0xCD
};

