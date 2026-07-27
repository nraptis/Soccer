#include "TwistExpander_Ankaa.hpp"
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

TwistExpander_Ankaa::TwistExpander_Ankaa()
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

void TwistExpander_Ankaa::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB0854F139A1BE91DULL; std::uint64_t aIngress = 0xB17068DE1CDC1017ULL; std::uint64_t aCarry = 0xAD05063D612F0301ULL;

    std::uint64_t aWandererA = 0xA9A279D6A862E8A7ULL; std::uint64_t aWandererB = 0xE269060E55B5FD8FULL; std::uint64_t aWandererC = 0xB6D4DBFFFBBF08BCULL; std::uint64_t aWandererD = 0xA3C5678B596BB282ULL;
    std::uint64_t aWandererE = 0xE440D7CEED8682E1ULL; std::uint64_t aWandererF = 0xD93B1112D5C6FA70ULL; std::uint64_t aWandererG = 0xF104CD0FBDDB66BBULL; std::uint64_t aWandererH = 0x8263D87283AE6A2DULL;
    std::uint64_t aWandererI = 0xA2B41ED8B0D95440ULL; std::uint64_t aWandererJ = 0xDE40106C7282D555ULL; std::uint64_t aWandererK = 0x83ECA0818C5BA5D7ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x8640BC4153AEE428ULL;
        aCarry = 0xE6359527C15A1F1EULL;
        aWandererA = 0x8EE601793D4A7DDBULL;
        aWandererB = 0xA2692C810F9E1B5EULL;
        aWandererC = 0xAC958C8472B6D778ULL;
        aWandererD = 0xFBC1B8F0BB924BBCULL;
        aWandererE = 0xFEB9DA4A5AB969F0ULL;
        aWandererF = 0xD9522E8313DA39DBULL;
        aWandererG = 0xBEFEA77506AB78EEULL;
        aWandererH = 0xC723C821AA0F5E4FULL;
        aWandererI = 0x9DD9AAA50FB41415ULL;
        aWandererJ = 0x9C05759BF89A5660ULL;
        aWandererK = 0x809822B0D3382FBEULL;
    TwistExpander_Ankaa_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Ankaa_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Ankaa::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF701FBA6E5DD2472ULL; std::uint64_t aIngress = 0xFEAC1BC7A9B9E311ULL; std::uint64_t aCarry = 0xB63DA64A9896B23CULL;

    std::uint64_t aWandererA = 0xFD8E3FF14B0B6E50ULL; std::uint64_t aWandererB = 0xB9B16FE26A962E7AULL; std::uint64_t aWandererC = 0xBB8BBEEB6829ED39ULL; std::uint64_t aWandererD = 0xDEA25619F0A92678ULL;
    std::uint64_t aWandererE = 0xD8092D431EF70948ULL; std::uint64_t aWandererF = 0xDDD20C88A1F31EAAULL; std::uint64_t aWandererG = 0xECD338816E5EC610ULL; std::uint64_t aWandererH = 0xF97106C37C465446ULL;
    std::uint64_t aWandererI = 0xF20C823E25194A34ULL; std::uint64_t aWandererJ = 0x898667D889B9076EULL; std::uint64_t aWandererK = 0xD24DBD4C6BC03232ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xF569DA00F62E36DFULL;
        aCarry = 0x97BB0EF667AFC137ULL;
        aWandererA = 0xF1243E1E107507E0ULL;
        aWandererB = 0xC3BA37E97EAE8B36ULL;
        aWandererC = 0xFBDF03C2152E6048ULL;
        aWandererD = 0xF6DCCFF3F5391D51ULL;
        aWandererE = 0xD1E459985874FEFAULL;
        aWandererF = 0xCEA4DEE129F19019ULL;
        aWandererG = 0xBD32D496BF975ED9ULL;
        aWandererH = 0xE4C9E7D284335069ULL;
        aWandererI = 0x986AF1BDC5D0D29FULL;
        aWandererJ = 0xFD04994ACFEF1A88ULL;
        aWandererK = 0xE48456A33F381DE7ULL;
    TwistExpander_Ankaa_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Ankaa_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Ankaa::KDF_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x91B30017B501088AULL; std::uint64_t aIngress = 0xCB0C4A5338CC629FULL; std::uint64_t aCarry = 0xD69DDD0F00C97B12ULL;

    std::uint64_t aWandererA = 0xC6069767A7C6A15BULL; std::uint64_t aWandererB = 0xB38DECCDBE7BDA21ULL; std::uint64_t aWandererC = 0xA763433051687916ULL; std::uint64_t aWandererD = 0xDCC394782801F8B8ULL;
    std::uint64_t aWandererE = 0xC5D2FD26E7880CDBULL; std::uint64_t aWandererF = 0xB533AFF7B0AC47D2ULL; std::uint64_t aWandererG = 0xE952EEA93CBAA536ULL; std::uint64_t aWandererH = 0x9BF8F4A34DA868D1ULL;
    std::uint64_t aWandererI = 0xA672FBC16D5E4593ULL; std::uint64_t aWandererJ = 0xEA7751A8D5BB04A2ULL; std::uint64_t aWandererK = 0xCDD3514F29B62064ULL;

    // [kdf-c]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xB180FC2446152536ULL;
        aCarry = 0x805DA26CFD9DA1DDULL;
        aWandererA = 0xE9B0A8E6497D1F97ULL;
        aWandererB = 0xBF4BBF3E2A1D00FFULL;
        aWandererC = 0xF485D07DAD588528ULL;
        aWandererD = 0xDE5F935A50972A24ULL;
        aWandererE = 0xC606032CD00F2478ULL;
        aWandererF = 0xFDF8330F1CD5AA43ULL;
        aWandererG = 0x92552861E4138A23ULL;
        aWandererH = 0xE4D893154A155C19ULL;
        aWandererI = 0xA502BA0EB032AB35ULL;
        aWandererJ = 0x9629BF65DCBC40D6ULL;
        aWandererK = 0xB2C4DCE767236CD4ULL;
    TwistExpander_Ankaa_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Ankaa_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Ankaa::KDF_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA8E6C822D48F36C2ULL; std::uint64_t aIngress = 0xAD4ADCCC23BF6BBEULL; std::uint64_t aCarry = 0xC852286489255B61ULL;

    std::uint64_t aWandererA = 0xF4064EDEFF6FA1DEULL; std::uint64_t aWandererB = 0xAB19962AFC329503ULL; std::uint64_t aWandererC = 0xBFE51636A5C86A1EULL; std::uint64_t aWandererD = 0xF6426851A60D802EULL;
    std::uint64_t aWandererE = 0xCF373E13E3BC1A49ULL; std::uint64_t aWandererF = 0xB3324F6725468FD0ULL; std::uint64_t aWandererG = 0xA168FAA0A9FC90C0ULL; std::uint64_t aWandererH = 0xDDECC3149A88FB06ULL;
    std::uint64_t aWandererI = 0xFE30CB46934785D7ULL; std::uint64_t aWandererJ = 0x8A24CC48170F360FULL; std::uint64_t aWandererK = 0xCDD3A5C6233EAF66ULL;

    // [kdf-d]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x8C8D1C0B78E15FA5ULL;
        aCarry = 0xE03BA1F97B9BFE7FULL;
        aWandererA = 0xB1AD70E1F09C207DULL;
        aWandererB = 0x85E80FE919DA3874ULL;
        aWandererC = 0xF05061ED99FB77EFULL;
        aWandererD = 0xC44D1966744B143DULL;
        aWandererE = 0x8BBCBF0FDCB997E3ULL;
        aWandererF = 0x97641CBF729A0225ULL;
        aWandererG = 0x89168F49520016A4ULL;
        aWandererH = 0x95828248FC2D3A12ULL;
        aWandererI = 0xF84754B81F2E6F53ULL;
        aWandererJ = 0xBC3F07D6976F4A9FULL;
        aWandererK = 0xA2D16DE1EE8F7385ULL;
    TwistExpander_Ankaa_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Ankaa_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Ankaa::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xEF69BD522A4901F0ULL;
    std::uint64_t aIngress = 0xEF3A35158D5DB936ULL;
    std::uint64_t aCarry = 0xDDBC25F3978371B5ULL;

    std::uint64_t aWandererA = 0xA1F376D690F9183BULL;
    std::uint64_t aWandererB = 0xCC28982B5F50EFFFULL;
    std::uint64_t aWandererC = 0xC01A644BA469F2F5ULL;
    std::uint64_t aWandererD = 0x950D7DF9D84E5872ULL;
    std::uint64_t aWandererE = 0x97967EFCF52BFE06ULL;
    std::uint64_t aWandererF = 0xA4642AF238C4841AULL;
    std::uint64_t aWandererG = 0xBE2A0565E68ECECBULL;
    std::uint64_t aWandererH = 0xDDB3DC605356AC38ULL;
    std::uint64_t aWandererI = 0x9959CAA0BB6A1728ULL;
    std::uint64_t aWandererJ = 0xCA5DDCF1362BCB37ULL;
    std::uint64_t aWandererK = 0xA7E5BB6BE7D17EEFULL;

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
    TwistExpander_Ankaa_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Ankaa_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Ankaa_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::Seed_H(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Ankaa_Arx::Seed_J(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::Seed_K(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::Seed_L(pWorkSpace,
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
    TwistExpander_Ankaa_Arx::Seed_M(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::Seed_N(pWorkSpace,
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
    TwistExpander_Ankaa_Arx::KEY(pWorkSpace,
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

void TwistExpander_Ankaa::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x912C11092A6957D5ULL; std::uint64_t aIngress = 0xEC73EAA503C9ABDAULL; std::uint64_t aCarry = 0xF945EB5DC8BFE4FDULL;

    std::uint64_t aWandererA = 0x995C8A77E707DDAAULL; std::uint64_t aWandererB = 0x851C9B37C36ABD91ULL; std::uint64_t aWandererC = 0xCE76C93ED728CFAEULL; std::uint64_t aWandererD = 0xA2E64B97B1E952BCULL;
    std::uint64_t aWandererE = 0x8EE725A88FA08ABAULL; std::uint64_t aWandererF = 0x9A9F192A0C2682E5ULL; std::uint64_t aWandererG = 0xDF4FFE74DB9F07A7ULL; std::uint64_t aWandererH = 0x94DEF997A6DF9BC6ULL;
    std::uint64_t aWandererI = 0xCB5F463F2B9ABB44ULL; std::uint64_t aWandererJ = 0x80E78A1AEF163B5FULL; std::uint64_t aWandererK = 0xA4D05D6B337E3BC7ULL;

    // [twist]
        aPrevious = 0xCF0F25FA05572A42ULL;
        aCarry = 0xA89E2BAD760DE08EULL;
        aWandererA = 0xED1089517102B9FFULL;
        aWandererB = 0xD242D3B697F301CEULL;
        aWandererC = 0xC5A61B09998627ADULL;
        aWandererD = 0xE562E362EA056A2BULL;
        aWandererE = 0x8A428FB96B3F6661ULL;
        aWandererF = 0x8C1564AE3F4ADFCCULL;
        aWandererG = 0xC888133DB16DD22CULL;
        aWandererH = 0xC4F916D89CF8979AULL;
        aWandererI = 0xC7E36BE06F8D81BEULL;
        aWandererJ = 0xE7503423E3062C2AULL;
        aWandererK = 0x983E77F9978D4E61ULL;
    TwistExpander_Ankaa_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Ankaa_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::Twist_E(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::Twist_F(pWorkSpace,
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
    TwistExpander_Ankaa_Arx::Twist_G(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::Twist_H(pWorkSpace,
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

void TwistExpander_Ankaa::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Ankaa_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Ankaa_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Ankaa::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Ankaa_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Ankaa_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Ankaa::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 8 of 33
    // Exploration cases: 0
    // Structural maximin 535 / 674; family total 3854
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
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4008U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7789U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3648U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 47U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1645U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1375U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 47U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1915U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1330U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1825U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1555U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1465U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 8 of 33
    // Exploration cases: 0
    // Structural maximin 541 / 674; family total 3874
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
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3018U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
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
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2928U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7519U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3198U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1150U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 835U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1105U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 610U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1015U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 880U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1285U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 655U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 745U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldSeedControl candidate 8 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1085 / 1248; total 7682
void TwistExpander_Ankaa::FoldSeed(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 858U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 543U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 228U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 48U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 273U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1083U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 25U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1893U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 93U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 250U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 115U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1938U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1826U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1871U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1038U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1961U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1398U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 340U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2028U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 363U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 948U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 205U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1218U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1353U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1758U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1173U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 385U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneG[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1308U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1668U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 678U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 993U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneH[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1488U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1263U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 768U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 318U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1848U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1781U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1443U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1623U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1916U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 498U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 723U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 70U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneK[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1646U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2006U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 295U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1983U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1691U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1803U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 183U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1736U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 588U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1128U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 633U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 160U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
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
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 453U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1533U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 138U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1578U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 813U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1713U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 903U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 408U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldTwistControl candidate 8 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1081 / 1248; total 7606
void TwistExpander_Ankaa::FoldTwist(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1016U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 296U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1174U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1354U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1804U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1106U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 521U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 611U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 814U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 949U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1939U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1241U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 859U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 791U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 71U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 476U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 26U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 926U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1151U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 566U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1129U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1219U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 431U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 881U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1376U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 904U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1669U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1286U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneG[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1556U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 251U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 116U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 206U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneH[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1534U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1466U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1579U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1624U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 836U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 994U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1984U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 341U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
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
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1849U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 386U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1061U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1444U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneK[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 971U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1511U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1714U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 656U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1084U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1264U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 161U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1489U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2029U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1399U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 701U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 746U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneN[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1039U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1421U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1196U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1309U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1894U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1601U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1331U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1759U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Ankaa::kKeyRotateSalts = {
    {
        {
            0x84CEF010DB4098A2ULL, 0x060D931F1CF2D562ULL, 0x0EE218E5F0AD1CA5ULL, 0x8F542E8EB0EC7211ULL, 
            0xFF669D3A7CC4018DULL, 0x753E839A60EA3869ULL, 0x1D93AAFC5D6E1145ULL, 0x4BA231D6DA62AB29ULL, 
            0x0DD1C6485540AE98ULL, 0x28E9D80EB71B8D4BULL, 0x78104241C1AC1A4DULL, 0xD0B968A82011C9B3ULL, 
            0x889144E101D36EE9ULL, 0xE699F47087EBA86DULL, 0xD30A39E8820C234DULL, 0xF770924D762731E2ULL, 
            0x4ACB3783149FD4DDULL, 0xC4DE877256E1D013ULL, 0xE9022FA556EF228DULL, 0x885BC0252EE5C88BULL, 
            0xA6B0D6DF63E6FDDAULL, 0x31E084A919066486ULL, 0xCD27485953B6B5B6ULL, 0x9CDE69FBF146E593ULL, 
            0x4B15CAD103F369FAULL, 0xF1043B02268B5EF7ULL, 0xC656A6F327097086ULL, 0xCFBEE7A4146895B8ULL, 
            0x6894EAEA72B5F29CULL, 0x7F47277E6726DEF6ULL, 0xE7F399371CC1F46BULL, 0x0B025CB3F898E589ULL
        },
        {
            0xF9CE783679DFD11EULL, 0x115D239A6873494FULL, 0xB6A2CBD6833FDDB1ULL, 0x9F7B0BC70AA8DCD6ULL, 
            0xDFF4B997F4B02DA1ULL, 0x2C0C782477C7DFE1ULL, 0xD3CE432326F35778ULL, 0xA82053300F9F2BF5ULL, 
            0x9CA59B2F16D82F11ULL, 0x345348FDB64374ECULL, 0x0E70D1C388C3643FULL, 0xA5F6E5FDDCD61D15ULL, 
            0xA89BB05F4AD47DFEULL, 0x14B4273F3D5365CAULL, 0xB5687F8AB43FC107ULL, 0x825D8DDAB9807F71ULL, 
            0x7B15B9DC25221184ULL, 0xB7EC5AA06DD973A6ULL, 0x271AE4A9FF63CBD1ULL, 0x1936E333FF4A2955ULL, 
            0xFE13A2DFFE1825DBULL, 0xA39AA5045F06FCAEULL, 0xAA9EBD8940D9654DULL, 0xC49E81D950440AF3ULL, 
            0xDDEF47D551FC0B54ULL, 0xBCE02D59D906F079ULL, 0xDAB5F3C1D0B4DFA8ULL, 0x92E9B79AF0EADDFCULL, 
            0x54B6180B0E8C636EULL, 0x23E62C84DAFEA6BCULL, 0xEACCBBC0AC416E70ULL, 0x3A35CEAAC6FC1350ULL
        },
        {
            0xA137947B5DE614B8ULL, 0x6165E8645EA1D0B4ULL, 0xAC5CBE19BA192BD6ULL, 0x925C8CD81E2040BDULL, 
            0x00D79C280B4FEF7FULL, 0x7384A53898CF871FULL, 0x97BBF6DF01E83F7FULL, 0xA6D4B5FE4C6CBF2BULL, 
            0x67287F036F92B3EFULL, 0xACBDDEB563315FB6ULL, 0xE924EAB4DCFCAD80ULL, 0x4CB5BA78A49E46F9ULL, 
            0x64DA431A60D4507CULL, 0x4DE91C75DF1DF0E5ULL, 0x8F6EBCFDECAE354CULL, 0x4F95BFF7B6CC88DEULL, 
            0xE5696FE95C3DAA90ULL, 0x60A9E6F26C05AFB1ULL, 0x97424C6EB2300C5AULL, 0xA82BCAB2D7F5E8F7ULL, 
            0x0053691F02D716FDULL, 0xA2AC10B873A669ACULL, 0x46C11CFE00CAF032ULL, 0xCCD02B8B04A040F7ULL, 
            0x17E6D5C9DE42A1FBULL, 0x13071A69142B04EFULL, 0x91CE963F2EEB9BF1ULL, 0xDE8C55AA334B914BULL, 
            0x82F6E1266B440ECFULL, 0x95FD452BA60015FDULL, 0xD2DA2438BAFAC610ULL, 0x2FAEDAFEBB9972DEULL
        },
        {
            0x828AAA1B3481EDF7ULL, 0xA7875B345EE944F7ULL, 0x1C7C49264111E53EULL, 0x85FADBAC9707F7B7ULL, 
            0x98EC1BCD7D16C4DAULL, 0x8BF7BB3AE7FCA4ECULL, 0x2B13528CB3942C1FULL, 0xBACF2F7018FFE5D4ULL, 
            0xAD1DD5F1A5ED1D46ULL, 0xAACD74D431DA48B2ULL, 0xF5517B379F33A4B8ULL, 0x45BB6010D0578152ULL, 
            0x4DC6051FCE186795ULL, 0x36D3E15F152657F3ULL, 0xBEE097EA6B9BDF76ULL, 0x5012A3A41214C511ULL, 
            0x49908696F935943DULL, 0x61E3E1A80AD22407ULL, 0xBF2DF493FE5DAC32ULL, 0x035326E03506854FULL, 
            0x196A74B96A244C1DULL, 0xEC544C047096A631ULL, 0x8B957F064FD7D0FDULL, 0xBFD1C7BBDBE60D58ULL, 
            0x2551810D86508280ULL, 0x506EEEAE08F8841AULL, 0xE11BFDA069A4478EULL, 0xBB32637C5C79EBE9ULL, 
            0xA900A249F7580E98ULL, 0x9E547C986B1DFFDEULL, 0x51F85AB712BCA7BAULL, 0xEDE820D4F3E2AE8DULL
        },
        {
            0xD71750E0A70F2A80ULL, 0x9F9A253AA4EECA03ULL, 0xA2A6560DF43E65B5ULL, 0x5B981A35FA407905ULL, 
            0x3E36447E926AB814ULL, 0x5CD575EBC219A2FEULL, 0xB310C04C2EE1BCB4ULL, 0x9F6140BD1CB7527AULL, 
            0x06B0187FE00B8C7CULL, 0x618FFFE374BCF931ULL, 0xCCF201254BD4F97DULL, 0x910338E9A917DA93ULL, 
            0x56EDB163EEBA3570ULL, 0x52D4F53336BB0E48ULL, 0x444790D8DEA01C93ULL, 0xC457045A15153FE3ULL, 
            0x3C4B30E35696163FULL, 0x4D24EF9E0BBE6B8FULL, 0xA0D0377F12562A68ULL, 0x2D9C12B2298B4771ULL, 
            0x2485FFD3907B1EA7ULL, 0x92DA2D2BC896FD01ULL, 0x51BC7F2824118ED8ULL, 0x3D70942BE3D69447ULL, 
            0x0140159BE17249AEULL, 0x1364C03EF28369BFULL, 0xBE60207759496EBDULL, 0xB14ED8362066B18FULL, 
            0x89BC3541B552086DULL, 0x8DB8CE8955D19424ULL, 0x8A06602BFCDF2FAFULL, 0xDC5A896D1B936A1CULL
        },
        {
            0x6E002880B792EEB2ULL, 0x33DB9660520B0EE8ULL, 0x164FE06A682006FCULL, 0xE484038091F71470ULL, 
            0xF461C523840B68CDULL, 0xA636ECE111C47A60ULL, 0xAB0AE712602272A5ULL, 0xD200ADF43EAA1D89ULL, 
            0xDF902469E462297AULL, 0x68DF06638A23B32EULL, 0xF322C7B80E70F24CULL, 0xE4EF00B0066237ABULL, 
            0xEBA634524071CEE9ULL, 0x83395CD80F796317ULL, 0x140AA7020E29578FULL, 0xF59672F10373805EULL, 
            0x2D93085DD3D9B91FULL, 0xBDA33BC7E063A330ULL, 0xDA60AD44B69B5FCAULL, 0x5CCC45DECDC6D2BCULL, 
            0xEDBF5BBE714C969BULL, 0x0B1A75B023F2A088ULL, 0xC481AC8344B19AD1ULL, 0xE2670FFB82120D91ULL, 
            0xDDE06139332F696BULL, 0xFCC82EB6E5ECC85FULL, 0xCC47C17D39D9D7B4ULL, 0x8792FA640EB8921FULL, 
            0x717DE7FCB958DF4BULL, 0xECDF352DA8A22599ULL, 0x93446021E4869C6EULL, 0xC981447F0E7D2E62ULL
        }
    },
    {
        {
            0xD6700652B81E662CULL, 0x3AF58877EF38B0B9ULL, 0xF97F111154E03A87ULL, 0x4FF7F6908584F373ULL, 
            0xF2EF7510385AD3D5ULL, 0x5AB50B1689B79BB2ULL, 0xA281C14FE93161B8ULL, 0x10C19C0F8A4CF14CULL, 
            0xF4032E3A823B195CULL, 0x5C90D27D3673A11FULL, 0x71628371B2B29DCFULL, 0x25903E8F61ED979FULL, 
            0xAFC5516AF29B80E5ULL, 0x0F666EEBFD526BC8ULL, 0x6B88F092BF5789F6ULL, 0xB0B238C5CDE5AF8BULL, 
            0x7F795780A050F219ULL, 0x43EC33152C828A55ULL, 0xD293666ABD490058ULL, 0x82791E0BAACC7B35ULL, 
            0xCA27F3873A24914CULL, 0x9B65E92565FE74AEULL, 0x5D356BBD35863575ULL, 0x61F961D032F37F31ULL, 
            0x131866853C3F8677ULL, 0x7F2BE3D70BE54C27ULL, 0x91A43D91F12464BCULL, 0xA85D7D9F63362511ULL, 
            0x2FF014A3157207E7ULL, 0xE9FAD736622A58D0ULL, 0xB5C4933924E437FAULL, 0xC69008CE21007210ULL
        },
        {
            0x6CEAFF1AE249C935ULL, 0x6C230D708023E794ULL, 0xE7C1D77915F46C72ULL, 0x2F0B798BD501B2B4ULL, 
            0x56B38213839AFD60ULL, 0x28587461AEE03FEFULL, 0x940F4686741CA828ULL, 0x7C70F51B4F2A0A01ULL, 
            0xB93457FA295D9530ULL, 0x97092198862D2F72ULL, 0x3FEB789D4DC0791AULL, 0x6C85700CD28F7F98ULL, 
            0x92C8224F81CC8867ULL, 0xF4DAFA6840F79C20ULL, 0xE60532A2DED1ED71ULL, 0xA6F846ECA95DC1A1ULL, 
            0x7BB34AFA66646C39ULL, 0x4492611FA234A307ULL, 0x49C1196308795E1AULL, 0xD54F8EBF6805F75DULL, 
            0xE28A8F28D9C2B174ULL, 0xC049A174A2D47C23ULL, 0x1D15B87AB9926EF9ULL, 0xE4375D746BFBC8AAULL, 
            0x1914B7EDE2A86124ULL, 0x4FFEFC03D38443DCULL, 0x0F76C03692FE3A32ULL, 0xC7CECBB7290F9835ULL, 
            0xAC78E2296C63A588ULL, 0xF16CCA4BDEC63BD9ULL, 0x28430B185D3AD899ULL, 0xFA26CE9F763A0127ULL
        },
        {
            0xD95C2979560950B8ULL, 0xEF3632746F6A335BULL, 0x6892A90C02EF7D52ULL, 0x304C23F145FE2C2AULL, 
            0xFDA993CC21868B5EULL, 0xD39D284A29E6B609ULL, 0xB5CAACC8E02EBF60ULL, 0x767A923DABCB515EULL, 
            0x0B2F8F8830A67924ULL, 0x6E6C1D81A93C8573ULL, 0x5739AE1992B0C907ULL, 0xD4B59C90DAC6C86CULL, 
            0x99C6A7C5C3569778ULL, 0x3EA1407A86AF676DULL, 0x727B1C4CC309DB01ULL, 0x754EF41E959C2A5DULL, 
            0x1E0F969EA7BB0AFCULL, 0x330F5A7F5FB86A1FULL, 0x450E380B9AC6BF35ULL, 0xC3BCAA5CB75563F4ULL, 
            0x1902BD002EC8B6FBULL, 0x4A3E9EE104976920ULL, 0x14B30DBB41DFF6E6ULL, 0xA6C1A895846B48C2ULL, 
            0x096B7727035A3AF7ULL, 0xC2936A1117D57D59ULL, 0x2B1F9AF1D6D8E6D1ULL, 0x4E82C6FEC86C30ACULL, 
            0x745C11D6E2102708ULL, 0xCB0D9BD4BE2367F4ULL, 0x63C084D9485CE917ULL, 0x57CFEB13CA357555ULL
        },
        {
            0xFBB3501DD599894DULL, 0xCF7421FAB4117491ULL, 0x432C91F4E77EC619ULL, 0x49CD3FCE24D49AE5ULL, 
            0xFE021913C4C58AE6ULL, 0x28E939C718A73CB7ULL, 0x7DEEA966663D7E30ULL, 0x8A02631C73A12053ULL, 
            0x5A11828F0CAC2BFAULL, 0x1F462F5ECB4833C5ULL, 0x1F6A511254487AEDULL, 0x5C850191280C3BC3ULL, 
            0xCD0890701FF387EDULL, 0x27B16C3EB0455FE0ULL, 0x97A8DAEB1071712CULL, 0x182BC24BA01472D4ULL, 
            0xD62D94F55FC2D04EULL, 0x006F1F64187A9BF7ULL, 0x12C8181E4D8FCD02ULL, 0xBAD1E1677CBC1B18ULL, 
            0xF3717A4119671549ULL, 0xA251B241D4D53967ULL, 0x81CB4AAD07064079ULL, 0x8748EF80EF7F21ADULL, 
            0x93A4338A1352A7B9ULL, 0x861C3F6868BBBD79ULL, 0xC12D8721F8D07084ULL, 0xC5CDB619DC9BECD5ULL, 
            0x071B3D67620AF3A4ULL, 0xB74BA012CD47E3BBULL, 0x03DDAFF31D09B0FEULL, 0xEF62FC2875B3C5E3ULL
        },
        {
            0x0860374831F01826ULL, 0x7D3F4B81EA4EFB3AULL, 0xFCA0A42E2845721AULL, 0x0FB05040AA481AADULL, 
            0x8B5B1F865EC16C6AULL, 0x2B48138A305250BBULL, 0xA6A6B01D05AAE3D5ULL, 0xD07F7265372417B8ULL, 
            0x74F89F3148C2374CULL, 0x4D3869B69A46E05AULL, 0x6AC5BD6EBBBD78CEULL, 0x664E4F6E569D8217ULL, 
            0x074FC0C0DF2B8068ULL, 0xD64D3FF2F09FB23AULL, 0x474A9F31E3DD9D53ULL, 0x0C96DBB59FC3BF4DULL, 
            0x55910BFADB2E884CULL, 0x4AC18596877C9904ULL, 0x854C58B0EB888BFFULL, 0x739161A80069F992ULL, 
            0x058B7838B3C81DD9ULL, 0xCA241D4A269289A4ULL, 0x4D7738FAA90179B0ULL, 0x6B662CC2FBE08792ULL, 
            0x0975E128BF89AC86ULL, 0x354C2FB801DD3940ULL, 0x38FFCEA78B98E1EFULL, 0x2D94297C9D89E10CULL, 
            0x438972AB113F9DC5ULL, 0xB805394A99A403C8ULL, 0x740FDA448400C6D3ULL, 0x20166B453E8D5EE7ULL
        },
        {
            0xF16268AE9AE9A66EULL, 0xCE813E3D2BB21087ULL, 0x9D379C9293D5259EULL, 0xBD4E9C8E6DE548D4ULL, 
            0x4FBA641ABAB9E4BDULL, 0xA83B48DA4C3B43A1ULL, 0x1BD23C44389A420CULL, 0x35E048560003A819ULL, 
            0x1B466A52CFFECCEAULL, 0x1007FA24CCA47439ULL, 0x2BE70DC386019748ULL, 0xBF954E8D51F1E248ULL, 
            0x5D1EAFA30E53C321ULL, 0xC4AD437D0E93AEE7ULL, 0x590FD5E911FD1030ULL, 0xB8D8DA605EFDA33CULL, 
            0xA700D0758803642EULL, 0xB66A8B085A53907FULL, 0xDA7D4279080149CBULL, 0x106912CCE85B9E35ULL, 
            0x54FE93197E462ABFULL, 0x7550E4FD78487F84ULL, 0xEBFAEA9F26E9B098ULL, 0x3063B25BF8762539ULL, 
            0x6978526520DA79D9ULL, 0x2C91B426ABF08C1FULL, 0x239D5C2E66FD48E8ULL, 0x5D7E97E28A450E6DULL, 
            0x02366A348CB8FB35ULL, 0x8BD2430B49645A69ULL, 0x5F007C5CDD7117AAULL, 0x2DF10B2F9C4F3E2AULL
        }
    },
    {
        {
            0x462CBCD1A5C2BF9AULL, 0xD8AA0B28AEB5A363ULL, 0x632A2FB65FA9BFC2ULL, 0xB99192F9FD9E98FAULL, 
            0x83189C66DF5264E4ULL, 0x5C16E935FE6A8C4CULL, 0xC6626CDD3350747FULL, 0xCA9C395BB5A598D1ULL, 
            0xABAEF4DF6B338DFBULL, 0x295F91837A5792A1ULL, 0x0431A6882D663CFDULL, 0x4021F88E2C0209ECULL, 
            0xAED988DDB99D44CEULL, 0x4AD22F92820DCAB0ULL, 0x4B2D25642AD2C072ULL, 0x880CF5536452F0BDULL, 
            0x5F50D6BD6B762CBAULL, 0x7C2F6C12B0F779B9ULL, 0xEAADCF028AFA2ED1ULL, 0x92C399116060E44BULL, 
            0xD827019B2A706F94ULL, 0x211A5D41587DD1DEULL, 0xCCFB278C73F6FA00ULL, 0xBF962134D2B4F39BULL, 
            0x8AC7E0108E7C2A3CULL, 0x666CC34C433A0E99ULL, 0x3207DF6F98977D1CULL, 0x1BD32AE0C031A663ULL, 
            0xF2C1776CFA87623FULL, 0x7CFDF2C3E384D228ULL, 0x38C233720EF3097DULL, 0x2BA6C64C1997F1BAULL
        },
        {
            0xBA76D8B788AA97F3ULL, 0x7E7BF9178E60D53DULL, 0xF2397D966E8F2601ULL, 0x118D0EFDBF3FB80DULL, 
            0xC4966FAC2D5D0B8BULL, 0x0D5717E2E9F032ECULL, 0xA6CD6D50D20CEFD8ULL, 0xDE18C85821AF4C32ULL, 
            0xC938EEFB487566F0ULL, 0x32FDA54588C3F18CULL, 0x3B13C8000C50D64BULL, 0x816F1CD8974049DCULL, 
            0x2733524C4032D6ECULL, 0xFBCCEB3C6A3EC646ULL, 0xC9DC1D95D0E95177ULL, 0x9D17B578EDB72FFBULL, 
            0x4A87EA2C81D5B410ULL, 0xB4CB9C430A35AA71ULL, 0x19B1E24FEEA557A1ULL, 0xDED48FC838142FC3ULL, 
            0x540C9C51AA3AD9ADULL, 0x07A67A59AA00EEA7ULL, 0x4ACB13841EDB5840ULL, 0xBD69D90DEAD5C6D6ULL, 
            0x1A8CAD4CD7A94200ULL, 0x59FF18114A476715ULL, 0x7BE8088B0C54C5B6ULL, 0xC3147C81FBCA5E39ULL, 
            0x43F626060A7B7EBAULL, 0x6AA31FD301FCB032ULL, 0x7BC92FFEB2C8D3F5ULL, 0x596E94F3D9FF484BULL
        },
        {
            0x8C4B7B0482E33C12ULL, 0x13CB510B80A403F2ULL, 0x648D33A60F16B32DULL, 0xCE3359B3C8C6815CULL, 
            0x50AEAF6EC9C9345CULL, 0xB9B6837C8D47D341ULL, 0x9D70A60D0BD451F6ULL, 0xC952BD1FA24BE86AULL, 
            0xFE8511297C00380BULL, 0x17DCE42D1E4E2F65ULL, 0xA634231C2CCA07ABULL, 0xE2B4451A5EFF869EULL, 
            0xF50B407658B7C48BULL, 0xA2BC53C30819F837ULL, 0xC3E8B0FF35BF58B5ULL, 0x79846904F3BFA80CULL, 
            0xD1C94436C36A747FULL, 0xFE86C5D686B402A2ULL, 0xCB345FE5646CC6EDULL, 0x0C08428B181E99F1ULL, 
            0x3F440B03D1438184ULL, 0x9387653C9EA4C05AULL, 0x0CD5BEF6B882F9C5ULL, 0x85BBBCDCDE6E750EULL, 
            0xE98D2DF663C55D0CULL, 0xB0D060512197B981ULL, 0x503B21D4CC4FCB03ULL, 0x276899D48698FE95ULL, 
            0x1C49DD79D70FE6ACULL, 0x2E91C1AAB3DF686DULL, 0xA68F151373A30310ULL, 0x60F42DBC8FEE3A0AULL
        },
        {
            0x51A5569DD4BBC1E0ULL, 0xCDC7CB8E38284C6EULL, 0xBFE54BF8E6BB0A57ULL, 0x158DCC6E1CABA356ULL, 
            0xCA389A02A5C27193ULL, 0x7524E637B7A3E0ACULL, 0xD5EC42F041796BB1ULL, 0x5F22EFA59F729B51ULL, 
            0x510870563A470913ULL, 0x9BC9A29D11035151ULL, 0x1599A2998ED254A8ULL, 0x6B0891E1BFBBED49ULL, 
            0xB5152EAAF24BBF12ULL, 0x71E124EEBEB716ABULL, 0x8721D181BAEC087EULL, 0x94F2E4A891E55C13ULL, 
            0x4EC85E2E7FDDF0C1ULL, 0x0B71C09C805C1155ULL, 0xF5BBC4BE7EF1BF5EULL, 0x47C60C44D314078DULL, 
            0x7376B6EB790DEB82ULL, 0x02FF59DC530BBE0AULL, 0x49C71DB0FBA5E085ULL, 0x7DA85636B6D19753ULL, 
            0xDC632E28117AF215ULL, 0xD0B764BC56F93CBAULL, 0x89309803F2C66EFDULL, 0xDA39EF5B8E06EC13ULL, 
            0x80EBB963734C5CFFULL, 0x24258C71450C501BULL, 0x32B88F70D80B1E69ULL, 0x533A4D87BCA42728ULL
        },
        {
            0xBF89FDF8731C26F4ULL, 0x811AB8F3703EDD91ULL, 0x6737130B232B26A6ULL, 0xC68BD84B83CD610EULL, 
            0xB2D698AA12799F13ULL, 0xAAE3F06BA569436DULL, 0x9267EC2BCB4BB9A4ULL, 0xA068ECCDD275A9A2ULL, 
            0x18F025186A4E507DULL, 0xF9DE44F156BB1D29ULL, 0xF399F9CFEC19BF59ULL, 0x767088B75A905096ULL, 
            0xBC4CD584540628E3ULL, 0xC1F57C1F0251A747ULL, 0xB02770C60D4092DDULL, 0x704B3D02563FE958ULL, 
            0xBACE54609DB0FDA6ULL, 0x0FE967D9A5264484ULL, 0xC734138E8AE3B53FULL, 0xFA921DA74E6AF511ULL, 
            0xBC41CE0E1C905B69ULL, 0x19AC74B35D8A19F8ULL, 0x3C98D578427228C6ULL, 0x8810947FB3BA4F73ULL, 
            0x47EA3D9212C15863ULL, 0x67CCE5C3FBCB7B70ULL, 0x133D3973C427E0F3ULL, 0xA1D1E25DB5DAEC5AULL, 
            0xC7FC9576ED85ADDCULL, 0x800523770F70476DULL, 0x20DFFC055E909F93ULL, 0x650E0232579336FBULL
        },
        {
            0x66C6C5602591568AULL, 0x6227567B3936C1DEULL, 0x04FFE6F2A49EF9FDULL, 0x23FF19A06D008087ULL, 
            0x1FA83613C7413F67ULL, 0x5A4F4F7007E0EAC6ULL, 0xCA4FF7BA8DD6BA12ULL, 0xD1ADC99D2F174694ULL, 
            0x0B3D3063D4A7EAB4ULL, 0xD5688AEB59186682ULL, 0xE13ED4ECEBFA8738ULL, 0xF3C4AA0915D4C745ULL, 
            0xB761B4099D505884ULL, 0x936A74A1076A62C3ULL, 0x37B6CFB040147011ULL, 0x9C625FDA497A5F00ULL, 
            0xC839FE453291CFACULL, 0xB6198A27963B551BULL, 0xB0ECBD00D142E024ULL, 0x058AFE0EA15A3930ULL, 
            0x352E68DBA55D9820ULL, 0x1EA286D49A689043ULL, 0x5327853C43D144B2ULL, 0xBE2759FB55EF27D1ULL, 
            0x07C82E003C72947CULL, 0x6675DD334CE682F0ULL, 0x7714BBAC69D8C9C1ULL, 0xA31287810C339CB5ULL, 
            0x91063767E24F45D8ULL, 0x1E0FF077D1C8C139ULL, 0xDB0A07724B096EF2ULL, 0x2D2A2B917517634AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Ankaa::kKeyRotateConstants = {
    0xDCB9DD35C40039F0ULL,
    0x1C51865354258418ULL,
    0x7BB870B27EF0365CULL,
    0xDCB9DD35C40039F0ULL,
    0x1C51865354258418ULL,
    0x7BB870B27EF0365CULL,
    0x620694846C308B3AULL,
    0xA9CFC88B67A6C58CULL,
    0x84,
    0xB7,
    0x9B,
    0x59,
    0x40,
    0xEA,
    0x46,
    0xF9
};

const TwistDomainSaltSet TwistExpander_Ankaa::kKeySpawnSalts = {
    {
        {
            0x25C6DF8A4836788DULL, 0xDB6C33E1691641ADULL, 0xADFB6C9C68185955ULL, 0x5FFCADB569AADAC5ULL, 
            0xC36D0DC4B24633FBULL, 0x2AD231869B3058B9ULL, 0x6FBD6455280BBFF7ULL, 0x1BA4203643076E26ULL, 
            0x874338B561EBC291ULL, 0x1D03616F17B6C196ULL, 0xF5D6154C564867F6ULL, 0x71E1F49F2F37A8DDULL, 
            0x504D2C3C0CAB4577ULL, 0x9C04AA8D463F8B52ULL, 0x761A0ACAC01F72D2ULL, 0xD5A6E3897ECF8E54ULL, 
            0x634C5B639187993AULL, 0x9B2CA72DE7B743B7ULL, 0x762FF64DBC55250DULL, 0xA33BC42026555CDBULL, 
            0x0514C1E40D7AB920ULL, 0xD50C9999A525FE44ULL, 0x414F3092EDC3434CULL, 0x3EB8F87166762557ULL, 
            0xBEF33D3C0FEB6BBDULL, 0x3966058212E0AB99ULL, 0x5E9BC3B60030E86EULL, 0x5F74EB6AE1598895ULL, 
            0xA85D8C44DB40C2A0ULL, 0x09B3C8E3046CE905ULL, 0x91A028FD15128465ULL, 0xFC8398FE416480BAULL
        },
        {
            0x5234AC29BFD4CFE6ULL, 0x4B52E0E4B5084E6BULL, 0x0BC831F1A3F59510ULL, 0xF440322AC77B75BEULL, 
            0xB7E7ECA2729A4340ULL, 0x1B177A16337FEED2ULL, 0x50F0580890DFFAD0ULL, 0x2157C13D594AE3BCULL, 
            0x7B4EF97D52D2C5E6ULL, 0x2F83616415302B14ULL, 0xFE41DE8AD0E16C51ULL, 0x0C6369FD03B7EC05ULL, 
            0x50F4CB907C19172EULL, 0x7D8FDF443E422052ULL, 0xE88AE33A71AE5882ULL, 0xACDF4C5D1D28AE25ULL, 
            0x69D955ADB3AC5530ULL, 0xACF3003FB3465A9EULL, 0xDDA16E09F5E5859BULL, 0x4E7E1549A005958BULL, 
            0x6531863671D235B2ULL, 0xDF9F2A563CF485BCULL, 0x8EA5E158A54F5CB8ULL, 0xEA87DF2D3E91E748ULL, 
            0x25D6CFE68142E98AULL, 0x980CBA3FD4978A8AULL, 0x4A72D106534F10EEULL, 0x5F10F3DB7C724D68ULL, 
            0x48F22E39FB8DBE54ULL, 0x5B91E3251121BE66ULL, 0xE994ACFFBBD2C1BBULL, 0xAE460173CE2EF4C0ULL
        },
        {
            0x6DE1254A3E4F5A9CULL, 0xA8C2EA97ED9EE947ULL, 0x965F68A93C505142ULL, 0x36D27C797A5FDBD2ULL, 
            0xCB78455D1D5FA94BULL, 0x397439302B888BBAULL, 0x01DE8E8D37F20A9EULL, 0x3D809A348106CAD7ULL, 
            0x553D6B70C2614B3DULL, 0x668EDBEBCE2B6BDAULL, 0xFF3DB5FC289DC10AULL, 0x9465652CCC1C3966ULL, 
            0x2FBB94BFE82E965DULL, 0x889C1278B1606BF0ULL, 0x98A5C8D453E82D9DULL, 0x8E7686CF391F88EBULL, 
            0xD24B5932EF4858FCULL, 0x5264A2B05059AC89ULL, 0x7A59BB672FB88824ULL, 0x9C1F3AEA436B1BAFULL, 
            0xB3A138DDE39255A8ULL, 0x172A3326AFE6A0CAULL, 0x8C2F46026006FBF2ULL, 0x7EAEEDBBC65E3C5AULL, 
            0x14A9817B7FB56F83ULL, 0x21D0EBB934F08168ULL, 0xB53F3C64FCF9BD35ULL, 0xF7008633D93AD58FULL, 
            0x04FEFB030D0FC09EULL, 0x6585FB251408ED7DULL, 0xBDC797BB0BB68A25ULL, 0x7F42E1B673B81806ULL
        },
        {
            0x2772DC2D3905A46FULL, 0x7EBA24E7982A4429ULL, 0x5105F8D2430AACEDULL, 0x31D98FF4189CB58FULL, 
            0xD9F16BA718751AFCULL, 0xA481A2BD033EC7CCULL, 0xBCE0D7C408F987E1ULL, 0x175243AEADE19AF3ULL, 
            0x0A6EBB5A1C6D3B11ULL, 0x7FB2749FAA504AE3ULL, 0x4B895462CE4EEFC0ULL, 0xDDFB53B511737FD9ULL, 
            0xF5C896D94E2C3DEFULL, 0x74F18D3743B3CE93ULL, 0x14ACB6E161391F6EULL, 0x7AB280B019F48BB3ULL, 
            0xC65687A3993AB196ULL, 0x808DA4D85EEA7AD7ULL, 0x104A7B1858B903E8ULL, 0xCE14157FCEE5776FULL, 
            0x8242762739BC014AULL, 0xDE2D4607144BA1F7ULL, 0x74EBC770CF8596C2ULL, 0x145000010E1C606BULL, 
            0x562D1DA7F8063A45ULL, 0xD2A6E8CCC6FB5710ULL, 0x5FE2E31620FDEC4FULL, 0x8253085B97E9E9FAULL, 
            0xC7536DBE9FDB7015ULL, 0x555F194D53E8301FULL, 0xB873E7A308F7F7A3ULL, 0xE423D28EE4D7601AULL
        },
        {
            0xFEAB2FD21CBD84CAULL, 0x030A077E22A0E375ULL, 0xEE5AC5F8AF4E6721ULL, 0x9F231EEA7E06517EULL, 
            0x834A6FC409652C89ULL, 0x298C0A51A42BEB48ULL, 0x6617657FB5BD5CBAULL, 0xF013DF4C5D26ED4EULL, 
            0x84B04B2F5B16D81AULL, 0x9F7F0BA27C87ABCBULL, 0x96EA3CBDB5404133ULL, 0x99821C060053D030ULL, 
            0x6C4A8E4A591A0865ULL, 0x687B6C0F374A8802ULL, 0xDF13D41113C81158ULL, 0x34DBAFBD3C6194DBULL, 
            0x50CCE478EC01E0E5ULL, 0x7F2A949B754550BFULL, 0x682C011270D8FAEBULL, 0x6E991A190A1B8B6EULL, 
            0x08E6A0F4A487B5CCULL, 0xA68A061921877B17ULL, 0x42832D704935B8B4ULL, 0xB583F6CA4EDE3A2EULL, 
            0xF4C61E848FE6B635ULL, 0x20BA7AA26A32BC46ULL, 0xA13982CB1B1E85CCULL, 0xF875B1BB2A168806ULL, 
            0xABC81EC96EDCA5BBULL, 0x6B6534E6B8E8C0EBULL, 0xD0436BC574CE61EBULL, 0x37A92FE619EC9CA7ULL
        },
        {
            0xAA6339AD09F91FBCULL, 0xE3963D8FE03BACEDULL, 0x99AA814DA5FDCAD9ULL, 0x28E2D54DFDF4E133ULL, 
            0xCAA3533E0A3EDB5FULL, 0x01F7AB013DE265DDULL, 0x45124CFCD98AE183ULL, 0xB9667C18999E7348ULL, 
            0x81771DC9F2FE2693ULL, 0xE9D6FE2A4498E9D9ULL, 0x55B876B61FC6FC5EULL, 0xB8D00F403D2334B6ULL, 
            0xFA6AEB6C1F89601DULL, 0x09D90259D783F196ULL, 0x373F9631CE346F2CULL, 0x3A02237C80AD7D2CULL, 
            0x109D42FBE8320D05ULL, 0x0F7B7B18568B6762ULL, 0x946697DA795E8831ULL, 0x48EB0EA6C5302107ULL, 
            0xBEB810233C0A0F2EULL, 0x3F85E69272AF6CAAULL, 0x64C45B42179DAC98ULL, 0xD8967E87B2790EACULL, 
            0x343006162378C4EAULL, 0xFCA99CF027B3E694ULL, 0x195DD4078B05A4E4ULL, 0x8E91BD74132C4B4EULL, 
            0x8ED4DE493D8C8E4FULL, 0x38DEDA6728241D59ULL, 0x6BFADD48F321D887ULL, 0x322E49486CA0D7C3ULL
        }
    },
    {
        {
            0xA3B1DFCB5480B2FBULL, 0x106FD20B5E0750BDULL, 0x84E3C567A621A9BDULL, 0x370EFEDC6EEE4650ULL, 
            0x6CC540A459C26162ULL, 0xBC1EFED7BA254FA8ULL, 0xC374BE069A3ECEC7ULL, 0xCA3BE41DCA7E2248ULL, 
            0x918B1C6CD0A5F5D5ULL, 0x24250D39373549E3ULL, 0x113A7DD763230CE6ULL, 0x15918A834DB1F1DDULL, 
            0xA220341B39A70732ULL, 0xB7D6E01DAF289359ULL, 0x8AB2549C0C13AF98ULL, 0xF9A668CE23B74614ULL, 
            0x1A8114EC9AD79F53ULL, 0xD10ABAE0BCF58B7FULL, 0x356D14BC2A6572CAULL, 0xE01BA45676C82390ULL, 
            0xD757C27FB2054438ULL, 0x7935A195072DE929ULL, 0x7654E94F7F82384AULL, 0x1ACBF3A151631775ULL, 
            0xE3E652D41C7F078CULL, 0x1678D642EDF05DC3ULL, 0x9F4145C38689358DULL, 0x88B46819F3F7F319ULL, 
            0xBD24B81BABA94561ULL, 0xC052B45AD2D439A2ULL, 0x549DD1A5261D273BULL, 0xCA6391F44FBA38DFULL
        },
        {
            0x9C659E8EACCC1921ULL, 0x38F2AB2D6997A535ULL, 0x36C81B35B0BC3362ULL, 0x587F5BCE3F880D13ULL, 
            0x80682F60CE999D3AULL, 0x8B3081AD8C9D128CULL, 0x7CAE2FCED0961EC8ULL, 0xE142E1ED427B9A64ULL, 
            0xD202F42AF3EE4AACULL, 0x164BE7E50941AC69ULL, 0x94A96A9B678E3688ULL, 0xFAB4E26BACEFBFE5ULL, 
            0x1432798ADCF5D96BULL, 0xFBC633050C3C8641ULL, 0x56788AB2D130C22BULL, 0xAD79D4B6A5AC4644ULL, 
            0x5D0B331538EB661AULL, 0x24B846992B3D204DULL, 0x33E1798E4929C67BULL, 0x15724767F17506D3ULL, 
            0x67D3BC923A2D8BA7ULL, 0xE32D65F053254841ULL, 0xF8BE7916AFECD0C5ULL, 0x1C5486681898EEAEULL, 
            0xAC324590843AF2C2ULL, 0x16455C7233E68170ULL, 0x49D6ACBD7134E464ULL, 0x4BC3AF27D5C611A0ULL, 
            0x304544F325993578ULL, 0x469AAB08EE98F26EULL, 0xC239A4BD02A74324ULL, 0x3C58F0A96440BF5EULL
        },
        {
            0x35F6330770ECBA01ULL, 0x7117E9AEE8C4EEE4ULL, 0x660F45D0B0915296ULL, 0x03768C687F5AD8E6ULL, 
            0xBCF87CBFAA733327ULL, 0x9566BBA329DA2B51ULL, 0x566F2EE793A88E6EULL, 0x8C21A00B26F57136ULL, 
            0xECB529361914D3C5ULL, 0x1D1FCE0591657BDFULL, 0x1DD56BA02ACB755CULL, 0x2BE69D174DDCD2E5ULL, 
            0xAF970DEE11B463E9ULL, 0xD75EEE75FFF33D89ULL, 0x63459B701FFD2CDAULL, 0xDE1CA2E2013BE34DULL, 
            0xF10B4AC9C097644AULL, 0x1C4563E946EBAC04ULL, 0xBAB631FA90B8D8EBULL, 0xF8F3F920E58DFFC9ULL, 
            0x37DE99AF79D776ECULL, 0xA5DE7861ECEC129FULL, 0x60A984C0E0608D85ULL, 0xF840DD42ADCBC5A3ULL, 
            0x95FCDF68224550B0ULL, 0x46CE612DA86D5625ULL, 0x996795DC2BD39562ULL, 0x00AC29D06621BA99ULL, 
            0xFB5300BEF73C6D21ULL, 0x9FA9484A1225C033ULL, 0x3FD152F816F78D7FULL, 0xE3269978238F36E6ULL
        },
        {
            0x38EB42FBD11F9F00ULL, 0x5167EF14812E2C1DULL, 0x38578209BBC6D700ULL, 0xC1841E3C1C69947CULL, 
            0x8C67BD4DA314446FULL, 0x363B57B1C6726885ULL, 0x10921725EB707306ULL, 0xE28F037B01CB65CBULL, 
            0x3A95B8272113D17DULL, 0xF30FE0AC75877A50ULL, 0xF39F9B97050AB90EULL, 0x037B7FA582DA4449ULL, 
            0xC5F9850CA44B8F57ULL, 0xC00B56494BFCA1B3ULL, 0xF59758FFD67CC737ULL, 0x1AAC2634275B68E6ULL, 
            0x15B8149D8FD5938DULL, 0xEA81FB8DCABCB8A1ULL, 0x83E9C36C8404CCC4ULL, 0xE5F7E35493DBEDB1ULL, 
            0xC538F8AF9A5CDCB3ULL, 0xE68E066535FA6AA0ULL, 0xAA508C7398CB4B35ULL, 0xBB696D2A4E6EE173ULL, 
            0x34118F36F227C16AULL, 0xFC0E206F836D5D73ULL, 0x8CADF771E9619CC9ULL, 0xF23707AA1C511DB5ULL, 
            0x1C2717B643D5D891ULL, 0xDD624DAF0612D77CULL, 0x65FBD27D66E631D2ULL, 0x3AD1599FAADA883AULL
        },
        {
            0xDBDCE4930CA4D774ULL, 0x21EC180802444801ULL, 0x9BD951142DB30778ULL, 0x3EE7C693C5086829ULL, 
            0x97AE7A21B4D886B1ULL, 0x158B2B3783D6DDB0ULL, 0x0647630424E71901ULL, 0x298595ACE47D0549ULL, 
            0x762373C8D3EDB947ULL, 0x4487A40FC9814F3DULL, 0xAF5E2796C33EFF71ULL, 0x88FD628CA6D67AB4ULL, 
            0xAA1ADF686E9B485EULL, 0x95016125953E6DF0ULL, 0x401096039D2A4F99ULL, 0xA7736414E154CEE3ULL, 
            0x8317C0FE31C25FDDULL, 0x7B52F946BB1CE5FEULL, 0x0EB19306F8BB7F3EULL, 0x59FF09F012325F25ULL, 
            0x81B11709BC3E2612ULL, 0x6FD348C06C9D2C80ULL, 0x18C398D071E91D76ULL, 0x6A48E1D2C4B3932BULL, 
            0xECD83D067D10F240ULL, 0x87A1063C657E6873ULL, 0x818CF98368E14262ULL, 0x91DE23579D903A04ULL, 
            0xE9E2868DF24779BCULL, 0x2B2D39F2365059A0ULL, 0x60EE8789E41625BCULL, 0xBBDB1BF02DCBFB44ULL
        },
        {
            0xEE8EDE90C377EACEULL, 0x7DA4DD6D00417859ULL, 0xD6E5B225B987276DULL, 0x55CA78ABD9D22B49ULL, 
            0x1806EEC7EF795FF1ULL, 0x060DB341B1B87914ULL, 0xE082C922B55A5ADEULL, 0xE86E7B88ABD76BDCULL, 
            0xFC4971BFC66BE3ABULL, 0x74B78EE6FA925DF1ULL, 0x9533B02736A8E114ULL, 0x4D24CE69C2D7201BULL, 
            0x057C38D84F4B6FC9ULL, 0x02476D0C6C8D7AFCULL, 0xBA2970D2A62C3AF2ULL, 0xB8C0439CD1AB77C6ULL, 
            0xBD27AB90E987A292ULL, 0xA68EA63716C1C066ULL, 0x70E4EBFDA49D5AD1ULL, 0xE6FCA9E2FE57C529ULL, 
            0x43391C6CD0F103BEULL, 0x878B20AB93EB0099ULL, 0x57B33775FEE56ADCULL, 0x70006599F970258FULL, 
            0x01EE8FBD29C363F1ULL, 0x6490774207E2B7ABULL, 0x42A33C57E65E1376ULL, 0x881554403B1A2FE0ULL, 
            0x2593133F88AE3F1CULL, 0xAFF928738E90910AULL, 0x41755933463FADCAULL, 0x5136EED104D1FA68ULL
        }
    },
    {
        {
            0x7316C21C14BBD80AULL, 0x072802984B611AF1ULL, 0x3F62AFCEC7C1971CULL, 0x37DED9D3142F8F4AULL, 
            0x0EBB953F6BC43A64ULL, 0x7130232CFB41A897ULL, 0xF01343BE664DF040ULL, 0xE381DB07C9F535E5ULL, 
            0xA6409CB06300E272ULL, 0xE06F15179489D7DFULL, 0x95E429D9333C2AABULL, 0x6E0D67A64C96EECCULL, 
            0x079039ECB3900368ULL, 0x87DFFD6CC540F87AULL, 0x86E989EB592AB7AEULL, 0xC98316F55257B165ULL, 
            0x9E6B9529AFD01987ULL, 0x00EE14A7C7E9E2C5ULL, 0xBB696816FB66D344ULL, 0x37793D51A21FC15AULL, 
            0x12ECF6776730EE0EULL, 0x7B6A6762B0620BB3ULL, 0x1A673AE7782A4699ULL, 0x4B384D3ECF1E9965ULL, 
            0x0172BCAB974344B8ULL, 0xA461F4AB1ED3D4E9ULL, 0xB0C0400C3FE709DFULL, 0xCEFB8C56996FB3C2ULL, 
            0xE02676AB7198DFFAULL, 0x3C46B3388DB8F98DULL, 0xC25FFD11EF5C096DULL, 0x59A5F6A76CFDC8D2ULL
        },
        {
            0xA69C59755B6A07A2ULL, 0x43749CA221092890ULL, 0xA3651946337DCD38ULL, 0x26D84218AB2FAFF5ULL, 
            0xD3E9FDF455B72548ULL, 0xABF68B5F1361F04CULL, 0x35B45EDFD08DE054ULL, 0xD78FF17429EFFB45ULL, 
            0xE11CA3754BA60370ULL, 0x9B195733C97DC851ULL, 0xB00110258BC1472EULL, 0xDC0B359894A3E858ULL, 
            0x66AAB9E222FB37F1ULL, 0xEB2CBD386E3946E3ULL, 0x7FF37B845B15446CULL, 0x16583024DA49C369ULL, 
            0xC640540160EBBDB7ULL, 0xE755F0CA8380C5FEULL, 0x8C95CF3D6ACCFC82ULL, 0xB81041A224FC46B8ULL, 
            0xC58EF4C7F042AFCAULL, 0x4615417973D377D3ULL, 0xEFA381460129553EULL, 0x6D2EDFAD990BCFC9ULL, 
            0x715916600F2937ABULL, 0xE4F66692C979B663ULL, 0x5EA68A7562EFBEC3ULL, 0x05C27831E3BA084AULL, 
            0x99A20E57D52BF7C0ULL, 0x606C873EEDC2FFADULL, 0xBDE9F55AD103FB76ULL, 0x0ADFBEF802FB7643ULL
        },
        {
            0x8B515698C64DF096ULL, 0x7BEC75077133C6C5ULL, 0x977E9475A84EFACEULL, 0xC0D966F4C981CE66ULL, 
            0xF04A4390852C667CULL, 0xDF80DE2C49B854C8ULL, 0x45F1B8075E8A4EABULL, 0xAB04FFAD63D38BD2ULL, 
            0xAC14159ED218C9CCULL, 0x7B3758975792B8DEULL, 0x993A5842764EC9F0ULL, 0x911F6570B7852DAAULL, 
            0xAA9C144A2E19D124ULL, 0x357B69E657B90C6DULL, 0x3C14917EC8DD6B60ULL, 0xAC696AF7A3B6D23BULL, 
            0x8CB47C867D65511EULL, 0xBC4A8284BCB6435BULL, 0x6EB9BB5C738CD5DFULL, 0xBBAF0C6F85AE2F57ULL, 
            0xEFA2CA8D1F571E91ULL, 0x2147F40E875401E0ULL, 0x5975F0568491A609ULL, 0xCBFCA789780C65F0ULL, 
            0xECB3930CAE7392F6ULL, 0x17F96F8BCB4A238FULL, 0xBB6CBDAD9C0A3AC3ULL, 0xF12EE2694E813223ULL, 
            0x6D861E6ACDF26BBAULL, 0x6C4C18A50BF78CABULL, 0xB62714939E7CB715ULL, 0x07452A147BA797C0ULL
        },
        {
            0xC9246EBB77191A0CULL, 0x942CC601194102B9ULL, 0x1827922059BF43A8ULL, 0xDBC977A24D7D3400ULL, 
            0x5F4A014915E2527CULL, 0x614F1C29125857DFULL, 0x929E6129C608DD8EULL, 0x570E4B5E8C69B7ABULL, 
            0x6760A71AF74AF720ULL, 0xC186F6D013CD2722ULL, 0xF8DF349DEC39FB1BULL, 0xDF53B2962B49EE77ULL, 
            0x19479C209F634963ULL, 0x94E1EA7923FC7691ULL, 0xD99CEE8B1506C2F1ULL, 0x58010EAFC0C6E542ULL, 
            0x6AB21953EBF52274ULL, 0x1A2DB87C49091028ULL, 0xFA8AD1D1ECCF500DULL, 0x60591DAC037F2609ULL, 
            0xD96068EE8D32E2BDULL, 0x9C81FBC32425AA88ULL, 0x47AF90495ADB3FFAULL, 0xBA62C5F1EE8C080CULL, 
            0x2F09ADC2D40C3B9DULL, 0x96F52C58EF3DF13FULL, 0xF5178CE2337A3B47ULL, 0x38BE6B4C11C89881ULL, 
            0xC99E2FA20258E657ULL, 0xF4C8A541C84FB2ECULL, 0x63F8D95964D2219CULL, 0x0AE4C3B005D701FAULL
        },
        {
            0x460BF1BB10C44541ULL, 0xF6D7F591AAE00D7AULL, 0x78764A60091CE74EULL, 0x62C72B313EB1888EULL, 
            0x206FFAF891CB4A42ULL, 0xDF9D5FDF87865517ULL, 0x34459777C5220F00ULL, 0xEB6CAC77C97EA356ULL, 
            0x23C7459F49470C16ULL, 0xC119200F4E1CC884ULL, 0x2CAC7F871FFCE86AULL, 0x977A87FF4533E93CULL, 
            0xFAC4A1E78A57971FULL, 0x6C96917FAB36CF7DULL, 0xCEB761F78099B043ULL, 0x5A7D7CD28A5E207EULL, 
            0xE8C0F3DFED423F5EULL, 0x10B45E8F638D8F4DULL, 0x6C7F90BAC4A089CAULL, 0x19F60E6659179DFBULL, 
            0x2A4565F50526EDB4ULL, 0x08F4EDC586CD8E11ULL, 0xBDA764FE07A56605ULL, 0xB4CA011B731901BCULL, 
            0xE1785507D6B3278EULL, 0xEB905A09604F70D5ULL, 0x622087E17A9E49C2ULL, 0x2FD4F9E6BA9DDD2AULL, 
            0xBFEC94BB1F480D9EULL, 0x4E69196D4B7FA11DULL, 0x8995ECBE4A2336E7ULL, 0x53785CF2255F0580ULL
        },
        {
            0x52B6B41031D2326EULL, 0xA380E7E7EEF41FFBULL, 0x602B109E26516202ULL, 0x9A6766CBB2E5C8CBULL, 
            0xDE7B0EFB069CDEC9ULL, 0xAA1127A3565936A5ULL, 0x5F23B00378C1967AULL, 0x551D8342D195ABBEULL, 
            0xE45CFC6123230026ULL, 0x9DBE33BE2AC28A38ULL, 0xE7EF8E3C925B08A0ULL, 0x10E1762E894EBB1BULL, 
            0xF31E04EB1684A856ULL, 0xBC13F5E6E47CE63CULL, 0x03556DEE2C11FB17ULL, 0x085A094099E3FC64ULL, 
            0x27110C2352A104B6ULL, 0x181415114401995BULL, 0x153317E2926B2EB3ULL, 0x61988B9125228EB4ULL, 
            0x805B7A897F8D0CCEULL, 0x12DF619FDCA29D5FULL, 0xFDABC58C7A73C288ULL, 0xBC71D780CCC56BCEULL, 
            0xFA62574E8A4A2C3EULL, 0x6EF662E408240F25ULL, 0xAF268BB58C28E53CULL, 0x13FAAD60C5999459ULL, 
            0x31A82253E0604707ULL, 0xCA4597E08456DEF7ULL, 0x8B2A9FB8D1A8B8AFULL, 0x7A6D6D6AE08F63B0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Ankaa::kKeySpawnConstants = {
    0x8D624916B138BD0CULL,
    0xED176970F967F11AULL,
    0x7E6BAFA2A5465BE6ULL,
    0x8D624916B138BD0CULL,
    0xED176970F967F11AULL,
    0x7E6BAFA2A5465BE6ULL,
    0xBD3125F91966414AULL,
    0x6D23D93306FE96E6ULL,
    0x75,
    0x0F,
    0x75,
    0x35,
    0xA5,
    0x3F,
    0xDD,
    0x58
};

const TwistDomainSaltSet TwistExpander_Ankaa::kSeedSalts = {
    {
        {
            0xF7BC4F49564F8D0AULL, 0x4BF69776C03389F9ULL, 0x6E460DEC70EE7E0FULL, 0xAC318C86F365B638ULL, 
            0x048E4A666CB1057EULL, 0x762E2A116F5F5763ULL, 0x7364C8A6AB5C1D3CULL, 0x77F7038891550FF6ULL, 
            0x71E2F9D7B2E2AD9DULL, 0x7B2A876E19ABAAAFULL, 0x0831C0396D347944ULL, 0x75C2607CC2AFE47CULL, 
            0x4001F5876F099F07ULL, 0xA192F40F300942ECULL, 0x2E0124EB3501F3A6ULL, 0x2092AA28F00EE985ULL, 
            0x8D4B7DD3AB5BE07BULL, 0x69E87D7972E766A9ULL, 0x0984BD78FAF98BE3ULL, 0x18A254524B098AE9ULL, 
            0x09925E83772A95C7ULL, 0xB4CF053F37EF00ADULL, 0x4CD168ABB31F394DULL, 0x351D728069046E89ULL, 
            0x0F12FE85B16CAA5BULL, 0x5E82C00B9C243E89ULL, 0xAD1B8FEEC795CE54ULL, 0xD9EFF5D9F48D761BULL, 
            0xFC7C42BA2FCF923BULL, 0x7E3902639D71CA8FULL, 0xC43042397E25AC3BULL, 0x5DAFDF049525CDA3ULL
        },
        {
            0xE49F00C0339101CDULL, 0x0E4871BD2261EB46ULL, 0xDBCBC06CEBB2C4DBULL, 0x46547F3E0C5F0905ULL, 
            0xBA2642C035FB536EULL, 0x4D633C29A6BD63D8ULL, 0xE90D5AE7515F0B88ULL, 0x9832F239C55A3C1AULL, 
            0x972454318B4E3FEFULL, 0xD272F1751C369827ULL, 0x3783A20D9715B224ULL, 0x3A3B4F54096CADC8ULL, 
            0x5D47CC708B89E845ULL, 0x7BE58047294F457CULL, 0x005B15486CD3BC9DULL, 0xFC20B8ABDB5B20E1ULL, 
            0xCF2951F432C0357AULL, 0x33C931AFB8505987ULL, 0x63AB1040AC80AEF1ULL, 0x42F98DBE2C3C9E32ULL, 
            0x1A70014C78B533CDULL, 0xC19A202B3ED8F7E3ULL, 0x56B9687EBFB6B7E7ULL, 0xFE61B589125B6DE3ULL, 
            0x0C4B91B7172B7E6FULL, 0x2911E4737E69E712ULL, 0x06866084E71BC2EDULL, 0x49839BEF7D6E3F75ULL, 
            0xA9AA5D30F6FC90D7ULL, 0x26DEDCD76D00656BULL, 0x346A392965764DBEULL, 0x680D34F219B6B72BULL
        },
        {
            0x9FAD33EC73EE38F7ULL, 0x8CC78173A2149465ULL, 0x8FE230EF2E4C9627ULL, 0x3EF2601F8201BDC9ULL, 
            0x0C28756B1C23DBE9ULL, 0x1107E865F5EEBDFAULL, 0x4FE2DF70CF57ABAAULL, 0xEDDD5E77A7496F7DULL, 
            0x64AD6B40D39DC457ULL, 0xB54097036CE56633ULL, 0x8613480B3329137DULL, 0x6B3B364216F5EB87ULL, 
            0x4A0CF7B6086F3415ULL, 0xA2B4788D7791908DULL, 0x9E3510CAD6F126C4ULL, 0x264007B179193106ULL, 
            0x355AE685C8CEF165ULL, 0xFF6EC8BEE088EC89ULL, 0x8B22481CD3578C4EULL, 0x2F82949349EBDC29ULL, 
            0x0743135B62161CD5ULL, 0x1230893C0911FC68ULL, 0xC57E2F8FCF8F8E7AULL, 0x47B46560014CEA42ULL, 
            0xDD84ED6A8B090ADFULL, 0xA02BF707CD7109E4ULL, 0xD3609CAA6854CAA9ULL, 0x253457FB979CB2FEULL, 
            0x02F9008C86E6A6D0ULL, 0xC1099C0005D456D4ULL, 0xC3D306A29C6F71B2ULL, 0x0EB4713C19D71B31ULL
        },
        {
            0x833740DED3806F27ULL, 0x109BE8629231F4F4ULL, 0x7DF2F1A4810B4662ULL, 0xF9A1CED747F2B5FEULL, 
            0xB425A1FFB645C6ECULL, 0x70FA85DB87E23324ULL, 0x40011CDE646FB48EULL, 0x690C725EB8455D6EULL, 
            0x4CDF03CF39582AC9ULL, 0x29D177E9A6C87E63ULL, 0x70A582B85023C8F1ULL, 0x98F0CA003DE10E73ULL, 
            0x67643B6B305579DEULL, 0x703A86DE67FAA9C6ULL, 0x6EA2865A71020F1AULL, 0x5175A518792D1BBAULL, 
            0x875C6F6B2E27783AULL, 0x19FA781449E4C395ULL, 0x5D637BF6FFEB3B76ULL, 0x34FBFBF52CB51855ULL, 
            0xE5A1D49734E35752ULL, 0xE526D1795A5A70EDULL, 0xA226689517A55A13ULL, 0xD17CBEA30BDA5A85ULL, 
            0x419B44E9C6348D56ULL, 0xE4D67DAAEBA45888ULL, 0x1785D1124646CE53ULL, 0x0D0DE661B80465A6ULL, 
            0x07BAFD21B6BCE448ULL, 0x15D9B342EE378856ULL, 0x7490C4163DCFB761ULL, 0xAE1B5E00FE7AE296ULL
        },
        {
            0x75A97A48BE5B333AULL, 0x2D759FC61D474D59ULL, 0xD63A3F2B4A8E6F5BULL, 0xAA55FA8FBF9A39FCULL, 
            0xAFD1C932ED3B5838ULL, 0x6E95D946B85BE266ULL, 0x9233BD276FF91C8FULL, 0x7EAE8B1FFAFD3F4AULL, 
            0x86D30BD3C1C849E3ULL, 0x593154EE152096B1ULL, 0xF24A5B15859FAA82ULL, 0xD5D873E0E7E0CBFBULL, 
            0x47FDA1DCE714D947ULL, 0xF9D2057C746F8639ULL, 0xF4B241967069230FULL, 0xD0ACD830A3005C4DULL, 
            0xA9E239E414757FB7ULL, 0xCBA53BD9FDDA37A0ULL, 0x9F2DDF6ABEC5D3DCULL, 0xBAA7FEFA9023C644ULL, 
            0xA6C6F7E797ACD571ULL, 0x543A6F5AFB61EAF2ULL, 0x5341DEAB89B44B28ULL, 0x19013E1E2EE60DFCULL, 
            0xB2963543639AE198ULL, 0xC808301C26AE1327ULL, 0x6D3D53417BC7E99BULL, 0x1916205FB4AA5878ULL, 
            0xFDC4A7DFD5B5DDC1ULL, 0xA100BB5BAEF8CFCBULL, 0x398E4E6600DB887DULL, 0xD09B0C07A560F28CULL
        },
        {
            0xADE963AA11BF6F3FULL, 0xA8ADD1D7CEE819A9ULL, 0xC09129834377D1D5ULL, 0xAB52FD2012D3A627ULL, 
            0xDDC5A143DF4F9DF8ULL, 0xA16124A30DE5C788ULL, 0x50CF1AF317D67A37ULL, 0x8818388EB1117842ULL, 
            0x5882B33149B52B79ULL, 0x94D9D21CB3E4B142ULL, 0x7BA2D711F7A2ECD5ULL, 0x2B22141A16F5DBE6ULL, 
            0xBF38BDEF1EDF8CA9ULL, 0x943B2D085A15CD62ULL, 0x198BD0F360AA246DULL, 0x5DBC123FDCECFBCBULL, 
            0xFA0961B714F79903ULL, 0xE2B0949090039FE9ULL, 0x1415E43205096F7EULL, 0xCFCF1979FA3CE58CULL, 
            0x3F8550C090DDA0F4ULL, 0xC4A95BA4091CCBB6ULL, 0xAFF0C180B1A60DA4ULL, 0x69D2C4CEBCB3DC87ULL, 
            0x969F5F7613194201ULL, 0xA537288D993DD91AULL, 0xEE198F75085CA415ULL, 0x7ABCBA287ED4A778ULL, 
            0xC6A3851ABCC6B235ULL, 0x52E4C264F07F7353ULL, 0x1948C80D94D8C35BULL, 0x792E6A49695DF4F5ULL
        }
    },
    {
        {
            0x35031BF5E66130BEULL, 0x52D7F43C0ECF6A2FULL, 0x613CBE87747FF9EAULL, 0xFB69D3B6FF72977DULL, 
            0xBBBC3F1BA6235F15ULL, 0x0FF15E932973E868ULL, 0x2954CB6950F5B5C3ULL, 0xC0D2CCC1E25EADF2ULL, 
            0x45A2247F94A1BB61ULL, 0x5BA6A3C3967066CCULL, 0x564DCBEB3526BB80ULL, 0xC6069D8798B3825EULL, 
            0xBD90550B3239A8A9ULL, 0x0A818578E6BD96F5ULL, 0xB8B97AB4A7A583B9ULL, 0xEC403E8048974021ULL, 
            0x034A29627CDDAF29ULL, 0x7D660CCFD998FBF9ULL, 0xC10257D6DB924E93ULL, 0x31F011236757DA69ULL, 
            0xF0BC377E0928C4D0ULL, 0xB76FEEB1623E3DFBULL, 0xAD75868024251BABULL, 0xC1880E7B5F1528FBULL, 
            0x8109302B35B4BB07ULL, 0x389DD7251EA31C79ULL, 0xD40B31BC9787E0F3ULL, 0x97F6E5D0507DEDCDULL, 
            0x6A3F3CB3A02C6A35ULL, 0xAD8D0EBB32D74A92ULL, 0x17FED5748DEE2161ULL, 0xB55C054F98A99DBDULL
        },
        {
            0xCD6C8DD203577E6FULL, 0xBADF5396BE799133ULL, 0x3500F1B74BC9A56BULL, 0x7FCF53CCA262657DULL, 
            0x237D0086698CF2D1ULL, 0xE8BDFD80AB14949FULL, 0xBFC17F34B39A4BAAULL, 0x926C8619C7F55505ULL, 
            0xCC34A021E179C281ULL, 0x59F3A3FE9999B1D5ULL, 0x6B1BD8809BF0E7E5ULL, 0xBEF9A1783B2DEDB0ULL, 
            0x8797D4CA48E0A556ULL, 0xA02F3351995E81AEULL, 0xA9C3DD28AF28D2C5ULL, 0x713B8CB6E80E0A50ULL, 
            0x4A6EA2CC83E24960ULL, 0x3D6A6EAF49C9BE93ULL, 0x43358C6A1A6154A5ULL, 0xF443065779B20835ULL, 
            0x89C9AA69C5932235ULL, 0xF16B87FAA5417CFAULL, 0xB5114475E637584CULL, 0xA401611C773FE0F3ULL, 
            0xBD43E396C6F310A1ULL, 0xAF2B65C8FCE3C8F6ULL, 0x140D7682D770B890ULL, 0xAC96885B315BCAF4ULL, 
            0x296C44F03AFBE204ULL, 0xE1B6C469FF2D8E35ULL, 0x2EB6EE7AFADA349DULL, 0x0BE2A9F35F98AD5AULL
        },
        {
            0x77B2AA76B5B51ECCULL, 0x033566D39D6DD8D7ULL, 0x4189839F25B0F859ULL, 0x77B451E97F73A358ULL, 
            0x08DEC87DF24490C4ULL, 0x4128AF46A3B61002ULL, 0x86C5DBA129F1A8BDULL, 0xBC8FD82956F34F31ULL, 
            0xFC5157F44AC2ED61ULL, 0x4798521C24EA8EA1ULL, 0xEDEDAD7C0307C620ULL, 0x3B2AF8F13158BEC1ULL, 
            0xACF0EB6B9BBD2C79ULL, 0x88D346F6145A8F01ULL, 0x2A2A53A93DF8D27EULL, 0x33F39AE1CCEDA0DBULL, 
            0x71C46A95B7DBFFF8ULL, 0x98EC8EB52A79F4DDULL, 0xE9841552D6B38E34ULL, 0xC3D7DAF0F7589423ULL, 
            0x02FB6B9A2CDA660FULL, 0xE4674C0E072A6F7DULL, 0xFC582715C3687FB3ULL, 0x64E5BC3DF6D2AF57ULL, 
            0xDF09F19349535109ULL, 0x069D15016FEFB011ULL, 0x927DD35F1B49B31CULL, 0xAFB265CEF871F9E6ULL, 
            0xCF3B156FE946104DULL, 0xEDE94242FA27B3BDULL, 0x4399830496550134ULL, 0x039CA82741F580DDULL
        },
        {
            0x8ADF140B8223FEEEULL, 0xCB9B87CD89560D65ULL, 0x4F5FAA9570C9D305ULL, 0xC998CEDAFEED219CULL, 
            0xEF5F0340CCC1E34FULL, 0xC9C87003F0E9CA04ULL, 0xB59CD7F065C5DB91ULL, 0x445948293B1EE8ECULL, 
            0xEDAD282D5A246CDBULL, 0x50455A8D8BEF6A28ULL, 0xDF3407700BE3A563ULL, 0x2240511AE6D81A62ULL, 
            0x703BF12DFFFC59F4ULL, 0x9A343DA4867668B0ULL, 0x97B39F2778F5DE93ULL, 0xE549527442EB1F6EULL, 
            0x9C2422400AEDAB3FULL, 0xC5A7F9715C89B364ULL, 0x14384747248405FAULL, 0x202B08B0C38CD569ULL, 
            0x8BCC4EC2EDA3E0D5ULL, 0xF4CAE301DB612F66ULL, 0x468D41ACDC890D59ULL, 0x197E2C884866B9A2ULL, 
            0xC3BE4DE97C6076F7ULL, 0xEF9FE6A2C138303EULL, 0x143E0DC8071EA126ULL, 0x2FDD6793F7C4E2F0ULL, 
            0xF533630E07BEE6CBULL, 0xEBF3006D88D424B9ULL, 0xFBD1C7EC498FC0F9ULL, 0x4BDA02F50617D012ULL
        },
        {
            0x88A704C22C2A652DULL, 0x6C5B7BB8F1DB0FE8ULL, 0x7D909F83A90BA0D4ULL, 0xDC8246107472B8D0ULL, 
            0xAEC662DB5AA6881EULL, 0x84BACBA9A07F7E66ULL, 0xCD7A5836102239D2ULL, 0x4A3325642CE46D49ULL, 
            0x548BDE72D1E063F3ULL, 0xB55F6989B2E9E76AULL, 0x6CEA2E9AA6708AF1ULL, 0xADE78EB9A0C677E6ULL, 
            0x310C5810C037A6CCULL, 0x02BFFEC488F9B16AULL, 0x428492D34257B96AULL, 0x5F6B190003CA1A13ULL, 
            0x5EFEE6298BCBF856ULL, 0x6EC4CF74C116C8A6ULL, 0x5DD4BFCE64172A21ULL, 0x66F5D54B200DBBF6ULL, 
            0xB574F919EEACF182ULL, 0x9C2714295C8D7D24ULL, 0xB8AB517CFB0CCFECULL, 0x96182C741541725CULL, 
            0xA3EE17A957EE0C0AULL, 0xFC5AC4A55F6242CEULL, 0x6F65C7FAD3ECF3BAULL, 0x109135E235EDB2F4ULL, 
            0x1456E98FFA3FDDB5ULL, 0x19F6827BE0EEA119ULL, 0x9B15E1C3996FF1E0ULL, 0xC77FEFCA6770A1D7ULL
        },
        {
            0x140F45E407EDE19FULL, 0x35D2BE02299ECBBEULL, 0x7C8C8FD7CCB84AECULL, 0xFA85C901B565F0ADULL, 
            0x6BCACA6E8C35AA5FULL, 0x354B7AED2F32D36DULL, 0x9F65B86F5A715C36ULL, 0x152514EE4536E788ULL, 
            0x81316A363E3CD8C6ULL, 0x32D7354AFE2928BDULL, 0xCC79EE5DA4B23A1BULL, 0xCE36D1122CEC3167ULL, 
            0x234CDC9F050F5369ULL, 0xA0AC6103194EF9A4ULL, 0x52FD6CA39FEDEF93ULL, 0xD3F2439AFC609CBBULL, 
            0x8D6AF8AEF16D3D41ULL, 0x7EC622CC09885541ULL, 0x09350EE9B09E50D1ULL, 0x7C9ED7D1E164534EULL, 
            0x70B439610E81FDBCULL, 0x8AC7C01F36EC703AULL, 0x635D56973B7E1484ULL, 0x640FA03ACEEDEE06ULL, 
            0x852E4AEA9C451795ULL, 0x85D7DA47DB898D9EULL, 0x3AB84F994DEDFE4FULL, 0x43C63CFD90C104B8ULL, 
            0x7B6E84513A917F29ULL, 0x895F7B4ABABFCBBDULL, 0x26B6B68903A221A5ULL, 0x12D774BAFAEEABE2ULL
        }
    },
    {
        {
            0xA65E9F57107A75BBULL, 0xCA77A83E023876B5ULL, 0xCF4ACBA262BF55A2ULL, 0x459E89F073015976ULL, 
            0x4C0E38CCAFB0E52AULL, 0x98AF37CFA0D6023CULL, 0x218F61E43242B2DBULL, 0x548F6D63FAD6A647ULL, 
            0x2C1898C5A784D139ULL, 0x2E6E4EA8AFF3A793ULL, 0xFC994050127D3071ULL, 0x83EF6FD7083FC5A7ULL, 
            0x915D5749C43576B2ULL, 0x48F2688560AA7477ULL, 0xB47CA6E9D0B4FC2AULL, 0x2DFDCB0D7A512312ULL, 
            0x8C310C01FC182224ULL, 0x0F31F3E3E069CDA6ULL, 0xDA5B4F4AC848ABA3ULL, 0xDCEBF0D4FF19D659ULL, 
            0x5450FCA37DE5F3BCULL, 0x98F536660903A27AULL, 0xA2D27B42EEFED96BULL, 0x94531420C4B91303ULL, 
            0xCC5573059A59D03DULL, 0x46D3AAF3E764BF96ULL, 0xDCFCA20EB7E07547ULL, 0x1A6C690CC18BB35AULL, 
            0xE7A95A0036E43F74ULL, 0xC22324406A680C4FULL, 0x1F2D214BD16190F5ULL, 0x6C3C9530EB9F5BC8ULL
        },
        {
            0x74B001E463E6AC6AULL, 0x86F7F68D17CAC309ULL, 0x3478B3C9D49648EBULL, 0xB677F2A123591F74ULL, 
            0x87BC624699F9303EULL, 0x4CCC5CBEAE03C6CFULL, 0x3E6FC4CD3EC8CC40ULL, 0x41FB9CE4C6DE6134ULL, 
            0xAFD3B637EE4E09FFULL, 0xFB053B59994F0F0AULL, 0xA63BCF9CAB079254ULL, 0x691447B44D3BA026ULL, 
            0x60634D0EA924A57DULL, 0x5F2EA077D349DD85ULL, 0xDCB78D770E5C813DULL, 0xC26B7657F0F49C7FULL, 
            0xAA82419F32C09C6CULL, 0x870E6EFC60D991F3ULL, 0xDBD3697FF052A97FULL, 0x233A6EA12C4E1AABULL, 
            0x6CD0EAD22EF8DF4CULL, 0xA41C58316EAD2357ULL, 0x064371F7457E5299ULL, 0xD0FD6E77679003CEULL, 
            0xAF3E4C90E80F1FEFULL, 0x8FC4F9E4DFFD154DULL, 0x2BC750F7B999C7CFULL, 0x6C007708AFB33D4BULL, 
            0xA6F6A12D60BFB963ULL, 0xF831E6969B331D69ULL, 0xB80D38E55521AD05ULL, 0xF5C536EE0621698FULL
        },
        {
            0x4A5AA67A028B18CAULL, 0x268263235B0B1F37ULL, 0x81C2742CCAF60005ULL, 0xC260433A61988FF0ULL, 
            0xAAA6A699085A1108ULL, 0xEEEF63DC99883439ULL, 0xDFAB5F38291E095CULL, 0xA52D795A09421258ULL, 
            0x39899CDAF5F99537ULL, 0xD86A017C5DD540A7ULL, 0x3B9A93A0FC5E8BF3ULL, 0x91E4C48247711256ULL, 
            0xF7813AFCD2334755ULL, 0x1827063A312CFB3FULL, 0xC6CF3C3312D6EB62ULL, 0x39BE3F2CD667914BULL, 
            0x431E050B3F9A6CC9ULL, 0x208D255935AAF8BFULL, 0xD62815D4FA78952AULL, 0xEED7514D74A8685EULL, 
            0x61497E2FB59B29AFULL, 0x9A568E1521CAA80CULL, 0x4ADFDE314EF73851ULL, 0x2623A926865657C2ULL, 
            0x95866DE7A9ADE39BULL, 0xE86ED803E626C9EBULL, 0x076ECBC8B3467F60ULL, 0xD638D665301F6BF6ULL, 
            0xD32220BC3078BCF6ULL, 0x00F2560257FC8D38ULL, 0xC2D828F5551344E5ULL, 0x32D69196770526D6ULL
        },
        {
            0x8C71FCFA10E99309ULL, 0x1ABB5104DC7AEAE8ULL, 0x4ED243E1832C55CAULL, 0xF1BFFCD38E877BE9ULL, 
            0x5D6FBD147C0F5817ULL, 0x25E443D51FBA0760ULL, 0xFB4E23BA9DA0FEF5ULL, 0x1173918065C455E3ULL, 
            0xFE05F5A658BF4E8CULL, 0xCEC448A36CF6B960ULL, 0x98F612B2A32527FAULL, 0x61A7A3F285E05FD7ULL, 
            0x05E1AA98CA75E496ULL, 0x5DDB2680B78AF2A6ULL, 0xA687EDD79FE38D8AULL, 0xF0078A0D7BA6E2D5ULL, 
            0x50096E589885356AULL, 0xCD480F8E106E8DE0ULL, 0x2CE6C84B2A9BCFE7ULL, 0xC53E4B8B4406FEACULL, 
            0x877F1043255D9C0FULL, 0x4CA630FA9FFCB450ULL, 0xAB5F14239EAF6FA9ULL, 0xB0E7E6A87B318757ULL, 
            0x09F82F597443DC24ULL, 0x647E147AA758F2E7ULL, 0x2AFDB41CCD3C03EAULL, 0x31075C115F3538CBULL, 
            0xB3DF9ADE33F4BF27ULL, 0x1FAD234DE3FC8F4BULL, 0x5D27D954AF87B2D2ULL, 0x128FEE3B2545F184ULL
        },
        {
            0x41D5E874B083A641ULL, 0xAD124FD2C48F7D57ULL, 0x378B28E70AD1E835ULL, 0x78A6599895453EECULL, 
            0xB5ABCDC0A4DF49C3ULL, 0x60DDAFE935E9E8F0ULL, 0x359250A1A9EE48C7ULL, 0xC058F3CEE390040BULL, 
            0x4BDC3949C45D80E8ULL, 0x98366086CDA87526ULL, 0xB0AC53D036E7D50AULL, 0xC07A69A2A52C29F3ULL, 
            0xD375522A0D86593FULL, 0x40ED124446F5CF27ULL, 0xDFEF26DA1BC5696BULL, 0x8E8876F606EA4E83ULL, 
            0xAF870D6B73E092E1ULL, 0x6D7EE5F813421BF9ULL, 0xD5498309979E0917ULL, 0xA1A2A4B0F2416639ULL, 
            0x3A5C73C942773305ULL, 0x46FEB0B602A90D61ULL, 0x602C21B951688DBFULL, 0xF755A25003C2F9C1ULL, 
            0xBF855E95BC9A2FA1ULL, 0xE199A115D072933CULL, 0xE261478818773288ULL, 0x753678B4AE117B6FULL, 
            0xA723FA61DD84EF57ULL, 0xADF6B38A1E35C00DULL, 0xBF6198E708646E42ULL, 0x7B3F21B01B32DD85ULL
        },
        {
            0x6F5D5F4BFA66D8E7ULL, 0xB55D4DBF1D28051AULL, 0x807A87C2640D4EFFULL, 0x694B81C4D3D4CC79ULL, 
            0x895D8C63FEA6E8F0ULL, 0x3F276CD8C8F1C3ADULL, 0x3A82DB75712DA441ULL, 0x5A79206389A2AD3EULL, 
            0x48FB6C037F2F92BCULL, 0x28432A397837A22DULL, 0x720EA7ABA66CA46BULL, 0xB54B55C5A82E64C3ULL, 
            0xB84DD6889CF4CA92ULL, 0x2DB71DB975C9A679ULL, 0xDE69EA9B77E50553ULL, 0xF3D72F8147130A94ULL, 
            0x8CEF823D7F951AACULL, 0x801646170D3D49BCULL, 0x5D5B6CE47DCCB085ULL, 0xE9FC59E33AD9DC53ULL, 
            0x4593D219E33741A4ULL, 0x83DD3AF735FB8B3BULL, 0x4CBE0585173694FFULL, 0x1A986E94DF0A693CULL, 
            0x8E89476B011D4BDEULL, 0x9672422CB0313129ULL, 0x7B0F6A538B8393E5ULL, 0x21BFD84F73990EB8ULL, 
            0x5421E2BEA1B0D963ULL, 0xF52872D5E7F07B81ULL, 0xA2F4A6D55842D307ULL, 0x7D94B6C423A19E4DULL
        }
    }
};

const TwistDomainConstants TwistExpander_Ankaa::kSeedConstants = {
    0x53A428B7B331DAB7ULL,
    0x6ECC5D1267861743ULL,
    0x7BA22F44B479A9FFULL,
    0x53A428B7B331DAB7ULL,
    0x6ECC5D1267861743ULL,
    0x7BA22F44B479A9FFULL,
    0x1B8CF20A93612172ULL,
    0xEDA9EB7EC4825557ULL,
    0x10,
    0xD5,
    0x54,
    0x77,
    0x99,
    0xE8,
    0x14,
    0xAA
};

const TwistDomainSaltSet TwistExpander_Ankaa::kTwistSalts = {
    {
        {
            0x0F8464AF765DFD21ULL, 0xAF31FFA425EF0C00ULL, 0xB810F19A533344B7ULL, 0xE0C1995FD4198144ULL, 
            0x3A483A611DD95F7AULL, 0x48403131F2642D03ULL, 0xA45499385D27F3B3ULL, 0x93664EC5AB114177ULL, 
            0x056C8EE87BA48092ULL, 0xB61CAE1A9E31ED7CULL, 0xC4727BB520F59F09ULL, 0xE0DA100938FAF14DULL, 
            0x5BD2A02CE19C1DA2ULL, 0x6F343BA71227977AULL, 0xE9A326D5AAE76E31ULL, 0x679CECDA90FD2DECULL, 
            0xF0F14E8EB2FCE2F1ULL, 0x6DC19B6C04ACFD3BULL, 0x119B579168F71C0EULL, 0x3FED0A08FC1B34C4ULL, 
            0xEEFAD6246C6B8580ULL, 0xF0980DC43C67DCF7ULL, 0xFC383B2E05E0CEE7ULL, 0x70DE8E12462FDB12ULL, 
            0x766DAD3EF76B75DBULL, 0xDDC6C059A005D1F1ULL, 0xFCD361130B692774ULL, 0x3ADC4F1B7536F26BULL, 
            0xAF2A0508AFBE3CD2ULL, 0x07C96C61AA489112ULL, 0xCFD9D2BFC61ECC8BULL, 0x85A08DB4B8EBBB36ULL
        },
        {
            0xB004409BEC54EAF7ULL, 0xFCC6E9DE6348BB8EULL, 0xD992E180DA9600ADULL, 0xBB3EB90627A17F29ULL, 
            0xAB32C79B5E47093FULL, 0xD920467C18356C4FULL, 0x0360B119A8F5B1B6ULL, 0x675B744E3818B58FULL, 
            0x6D0877E8C3379F26ULL, 0xBA4FA9276F6673E7ULL, 0x67DE3E71D8CE87CDULL, 0x5853C26C2EADDA08ULL, 
            0xDA992C933BED06D9ULL, 0xC883C4E8512C4ADBULL, 0x19CCC493A580886EULL, 0xA3B1E721CFD54F78ULL, 
            0x0B59845D0D102BABULL, 0x263EB78C577324C4ULL, 0xCD8C06EB9D23785DULL, 0xB3A9EDF3847E4064ULL, 
            0x036A68B03632D79FULL, 0x682A38D0C98F9DE8ULL, 0x016FD59A0D8DFC0BULL, 0xFFB0B01BB351D467ULL, 
            0x4B271FA92A6C0F9DULL, 0x93EC5A1FCC234561ULL, 0xE9667F191F70A5B3ULL, 0x95123B1E594A06FFULL, 
            0x75F5CD6F13ACC414ULL, 0xC9B1C822779D9183ULL, 0xFC397758CE6CA42EULL, 0x5B79F2507517F204ULL
        },
        {
            0x98652E33280D18EDULL, 0x4BDB48502BAD59A3ULL, 0x819D7230A6EF0EF4ULL, 0x2400BE85B1EF3D81ULL, 
            0x48CDB64515E2BCB9ULL, 0xA5FE749E43C2CBF1ULL, 0x701F404C011ED355ULL, 0xD5C589AD5B650365ULL, 
            0x39759EABCB5120CFULL, 0x5009F8D8A39A7833ULL, 0x80173E7917BCA3E9ULL, 0x93A0ABE563F8D422ULL, 
            0xE8ADF983D7305BD1ULL, 0x72F1DF4DC4E61178ULL, 0x1861A88800BEF608ULL, 0xAB3DC3EBA4FE7877ULL, 
            0x2366233A1A6EE128ULL, 0x820F139762D2FFABULL, 0x7932CA46BEFE3E3CULL, 0xA4E2755A5B6480EAULL, 
            0x8FD2A8D2D763B013ULL, 0x90A86AE54E813D89ULL, 0x96FE3E3F4C7EF2E4ULL, 0x577DA46E92AD1C8BULL, 
            0x8925F9C47785AB74ULL, 0xF160C858B0F081C1ULL, 0x4FDDE69A54061389ULL, 0xAE050D92E2C23BC6ULL, 
            0x4C99F784C567D11EULL, 0x538838FBCC50A8E8ULL, 0x965833676DF60794ULL, 0x7D9C5659F7FB0415ULL
        },
        {
            0x65CEFE79E48DBDA0ULL, 0x9B4FEB22AE20FE48ULL, 0x3606E435383417C3ULL, 0xC2E5654B25580594ULL, 
            0xAF8E5B4869B96936ULL, 0xECECFE783ABBB4A8ULL, 0x536F7F543A4AD677ULL, 0xE9DFBCFBF8CF7365ULL, 
            0xAEB43B4414EF3F42ULL, 0x8ECBAA0F5278BF20ULL, 0xE7A60916DB745F48ULL, 0xD4A275C7117EFA12ULL, 
            0x04C477C4AB1498D2ULL, 0xFDDFB457B643BF02ULL, 0x8DC49CCEA3587B8AULL, 0x06F6166E66D812E1ULL, 
            0x6E2FD09C31A943F1ULL, 0x7869689B0BC43A49ULL, 0x7E40C93A78D51CB5ULL, 0xF60034A55DEC0B5CULL, 
            0xBE7225D98880F71FULL, 0x8E4DF87E4FDD646AULL, 0x49DC180A8385FE49ULL, 0x1256C44E44703E2AULL, 
            0x1E1DD331DAC5225BULL, 0x98568FDB0549FDCFULL, 0x71D30354CF5E405FULL, 0x37805ADDD5D55FCCULL, 
            0x422169662549ACEBULL, 0x3FEE24FB175E0067ULL, 0xCFBAC220BA818EF6ULL, 0xB50F2EBDEA773B9AULL
        },
        {
            0xFFB885D975CAAE39ULL, 0xC7CF8ADABCF91464ULL, 0x1688C90FD29515CCULL, 0xCEE498B6746336ACULL, 
            0xB312ED3D4ABAE2BAULL, 0x2F081467C78E4FF4ULL, 0x58F655A46E3EF525ULL, 0xF144CB7981ACA45DULL, 
            0xCD1957FFBCE1B167ULL, 0x496A83973C662273ULL, 0xA312DA4F94674364ULL, 0x3D3BF4D938DB0472ULL, 
            0xD1C2BECA77E98DFBULL, 0x08D2CAEECE5012D7ULL, 0x6012497A5B351AC9ULL, 0x4066A0408F16916BULL, 
            0x4861238BBA8EA8DCULL, 0xC29BCF7A3D773D38ULL, 0xBE53098B6B9AB26CULL, 0x71F41E44EE83F40BULL, 
            0xA0A1570566A6D6B7ULL, 0x2C85CD7A76B9FA6DULL, 0xD1A94E8C504E2788ULL, 0x6D364A91B01C7651ULL, 
            0xAB8A920107F39CC5ULL, 0x72E798206C979439ULL, 0xA453D33BAE0B11E4ULL, 0x456DF9958F1A1CCBULL, 
            0xD9F42C6FBD64FCDFULL, 0x8C42A2E5C114C8C0ULL, 0xA9E618CC28FFBE8CULL, 0xBAF69F343AD96089ULL
        },
        {
            0x4F8486986649B5B9ULL, 0x31E778C3ABAED63BULL, 0x099A351A23FDCFAEULL, 0xD4C10E6EE05C70ECULL, 
            0xC6DF4B97AE3FD05AULL, 0x90EB1FE493EAA136ULL, 0xA2D30A3A0310FA84ULL, 0x515A1CCFF1022774ULL, 
            0x3076418548E005BCULL, 0x0C7196BCD1135B39ULL, 0x8D644D030C8324B9ULL, 0x809F5A9F85602C56ULL, 
            0x5F4DCEC89983BCBEULL, 0x957CD7F1264167F9ULL, 0xB18D678727ABBBEAULL, 0x02A2C8FF6B5BA0E0ULL, 
            0x10BE5063E4BA9EBFULL, 0xF91E3545C6ECC952ULL, 0xC20377E582F77C49ULL, 0x2DF9C4E78ABDC0D7ULL, 
            0xB7919FC909216836ULL, 0x20CE43C06321BF6CULL, 0x3E941E633DD40E79ULL, 0x55E990EF3E4967C8ULL, 
            0xD5F22E8571F49C6FULL, 0x518642D028857D44ULL, 0x0B4D3CE2F1468E40ULL, 0x3D12C3B77BF9D02CULL, 
            0xDB433321CC3D5DA5ULL, 0xF98107329F87394AULL, 0x28DFF1A8E86E8D85ULL, 0x4A1F1C446423E9FFULL
        }
    },
    {
        {
            0xEA84A1F59505F7BBULL, 0xEF240D8C751424E7ULL, 0x8374B8738F20C305ULL, 0x40C9F8A9E2F88ECAULL, 
            0x519DDDE410C91AABULL, 0xA501E278F6111BF9ULL, 0x71737979507F34F3ULL, 0x245C6482A24C442DULL, 
            0x4192AF805A8F07FFULL, 0x5BE1DA326801A473ULL, 0xD4AC6E06031B1A15ULL, 0xFC416739DDF06334ULL, 
            0x0D0261B64CB7245DULL, 0x6F31D96318255AF5ULL, 0x1D5CFC27E3D65D0AULL, 0x5A0748DAA2FC2D50ULL, 
            0xE6C6FFC811F5C95EULL, 0x9B48A3AF4F315C18ULL, 0x02A5B520947CB5F2ULL, 0xDA0E86D5D78C740BULL, 
            0x526B93ED75A878E1ULL, 0xE344BC5AD6E63864ULL, 0xF3CC6499AB71438EULL, 0x0236CADF1BA67608ULL, 
            0x9D74BDBCC3A13D6BULL, 0x08AA3230563D4409ULL, 0x55F96BAFB756C4E5ULL, 0xB474AACE32742ECBULL, 
            0xC1556A00BBBEE6B8ULL, 0xF56BD8DFC0A621D4ULL, 0x15855B3BB5B41D26ULL, 0x863F9D9008F7A9ECULL
        },
        {
            0x4DD35A6D1E090F49ULL, 0x1A8507A8B96838B8ULL, 0x7DB19B7DB1D30B17ULL, 0xEBAB1F5865CF1C8EULL, 
            0x13841FBA55E2A0E3ULL, 0x821F6B1E21DDBD2BULL, 0xFFB28C43A6851DFFULL, 0xC402EAD92E236DD6ULL, 
            0xEC96CCEB73D562B0ULL, 0xE21F6C4FBBBFC8EAULL, 0xAC43BD9887FE4436ULL, 0x0C1D7831873491DEULL, 
            0xDCEA11FFF6ABFBA5ULL, 0x7FFA8A2620EC2926ULL, 0x9DB1C1E372F1F6E8ULL, 0xEA4EE7D512865FA8ULL, 
            0x1FAA7E8C9822BDC4ULL, 0x12B3949277B1728AULL, 0x2CF5DD7D337A0B2BULL, 0x2A4CA9F2E360AF38ULL, 
            0x79220C8292FEEA68ULL, 0x321B198F77B0CCC6ULL, 0x3EC10C88ADACB5A9ULL, 0x012FCD892EB90717ULL, 
            0x87B65389C8D3C62BULL, 0x6A8884DD28A3B1A8ULL, 0xC93D9FF86F997BE0ULL, 0x51A025365274286AULL, 
            0xFE6BD6E7C06E1AA2ULL, 0x344E928B8CA45E93ULL, 0x38E4118341202FE5ULL, 0x68BAF16E4DCB595CULL
        },
        {
            0x14FC8396D0A30841ULL, 0xCF068E893BA4F805ULL, 0x644FD292E4F5B7D2ULL, 0x1AAF631085BACAD3ULL, 
            0xB5574E4FDE2448ABULL, 0xF9856EF83C6D4B65ULL, 0xAAC895F57394F3F6ULL, 0x67CFB2C0A026C3A4ULL, 
            0x044B78E3D48CB0EDULL, 0x7B3581B5B46007C6ULL, 0xFC56D0A34CC5F97EULL, 0x4EF40F2BA3885A7EULL, 
            0xFE4CA2DAE8047373ULL, 0x66F2A8048C0C790AULL, 0xA4C91880415010CAULL, 0xD3ADFF3DC9ED6D6EULL, 
            0xA0316334250199E9ULL, 0x35320B6759F599F9ULL, 0xF9B38DC9DE2E754AULL, 0x960B74B622E9F8D2ULL, 
            0xDC9F517ADEF30885ULL, 0x846C6B1E3D6CA569ULL, 0x422FE663866E3692ULL, 0x59C6623D7FDE6904ULL, 
            0x27552565FD4E5805ULL, 0xD79D1DE30B97B134ULL, 0xA278CD87C5BEAE1BULL, 0x55A548826474B111ULL, 
            0x42856DFCFE8767E5ULL, 0x5DE1D0A0787A6D9EULL, 0x92AD62C63DCD7E7AULL, 0x5CA5EDBCA1C04144ULL
        },
        {
            0xBA8BE438F0226596ULL, 0x3E0A7C570ABB4926ULL, 0x23B875A5A6D7A41FULL, 0xBB09F957EB35C314ULL, 
            0xED70FC66F26AC0BFULL, 0xA08E22501F1A49EFULL, 0x674EDE1359B4F6E5ULL, 0x0E66690932A253E6ULL, 
            0x0E0955C72D1A1418ULL, 0x30552D1C0AAD64EBULL, 0xDD55C3A3CBDDFA15ULL, 0x215192C6EFD1955FULL, 
            0x582D05F4BF91B402ULL, 0x2926854FE2C72E94ULL, 0x1D7EC1687B64C882ULL, 0xFE334725560EA813ULL, 
            0x10F536B090B5DF97ULL, 0xCDDAB9192CC91119ULL, 0x0F27231A64F8CEF3ULL, 0x8584E226902A35A8ULL, 
            0x40D3C6BD0ABE6E25ULL, 0xC416464A63ED8B76ULL, 0xFE73D8A397A51C50ULL, 0x772EAC6D27F89C87ULL, 
            0x63763B37490D156BULL, 0x8C10017724947CF5ULL, 0xBA3418FEC46937E4ULL, 0x7379C83155A2F53BULL, 
            0x196B2C6FA935D993ULL, 0x70F792275F3B0829ULL, 0xAADD1E62584CB3C2ULL, 0xD4CED9D4A1ED05AAULL
        },
        {
            0xBB4CC62CC2D5C301ULL, 0x7684048AE216F274ULL, 0xCC1B3389AE9CA004ULL, 0xF01910D95E81F8E0ULL, 
            0xC939DD27B291ADE3ULL, 0x52E6842C203C5032ULL, 0xB84E6423F9411522ULL, 0x352D9BFBCC0ABBF3ULL, 
            0x733FB9C976DDAE0BULL, 0x93B6A637833B4170ULL, 0x81EFF683C11628BEULL, 0xFE6D2E80D385AC0AULL, 
            0xF30A4B4B39321B19ULL, 0x5019814BD8BD5EA7ULL, 0xC3740341C3267C9BULL, 0x1B2EF677F804A6F6ULL, 
            0x0ADF63F76F3337B7ULL, 0xFB951F176597DA2DULL, 0x67D45E411ABFE789ULL, 0x3092083F493CE2A8ULL, 
            0xDBE23441EF0C7BDEULL, 0xA69121C77A816F4DULL, 0x8992B539361B5627ULL, 0x95686003E74AE497ULL, 
            0x362D46EBB349A146ULL, 0xDB37183C61628F00ULL, 0xB5A2780A4A12588DULL, 0x1482CCA802DD9246ULL, 
            0xE70279DDC29C5814ULL, 0x1A741F417235CD6DULL, 0x3116BA7A523C3FB2ULL, 0x4C968B4856469533ULL
        },
        {
            0x906ACE1C230BDF11ULL, 0x93089FDB7C88A991ULL, 0xF78CDF9389AF4F45ULL, 0x98977EEE11437327ULL, 
            0x921DB30D378ED847ULL, 0x1EF6C793D780B41EULL, 0x0132FF4F4ED618FDULL, 0x6718CCDE44458A48ULL, 
            0x0319CF1AEB10CD95ULL, 0x09284E3D570238A8ULL, 0xD014BA97764A8C26ULL, 0x1E4C4B4902E22207ULL, 
            0x6B45FEAB1B576CB5ULL, 0xF2CA8DFCFB889467ULL, 0x7588C78CC706BF9DULL, 0xEF490DC18A6FE748ULL, 
            0xC1A854C01F503A76ULL, 0x0EFD7F0C197002D9ULL, 0x1AE33D236933EC31ULL, 0x5CFD823084CA1C7EULL, 
            0x92C85B16BF1324FDULL, 0x29D609A3B16FE874ULL, 0xFDA07E8F95433591ULL, 0x1EE4B6CB8ECA256EULL, 
            0xDB87467824493646ULL, 0xA5242F612ED535EAULL, 0xBE991932C4BCF6D5ULL, 0x9E92D9827AEA9611ULL, 
            0xF4E2CF20E397293FULL, 0x4EF210F9031181A1ULL, 0x988E86174B8611E2ULL, 0xD99E46DDEE0EF930ULL
        }
    },
    {
        {
            0x6573B112AB349763ULL, 0x859DBC146DF9496AULL, 0x49D5E414D68BCB23ULL, 0xFDFBE4C958C25CC1ULL, 
            0x2A8D19BFFC5FAF9BULL, 0x051736F2FCF44526ULL, 0xD9F22006CADB7881ULL, 0xEA9F9B8D5C57844AULL, 
            0x1053619E2A62E260ULL, 0xAE4DFCB270999F99ULL, 0xB7D880063B4FF55BULL, 0x54B3828962209ED0ULL, 
            0x3F752AF8FDC6C9A8ULL, 0x8F1BCD9CB9CCEE41ULL, 0x725755F3480C652DULL, 0x7512FF9095796018ULL, 
            0x0123F6242A6A85B1ULL, 0x023CA2C7F62F6ACBULL, 0x5527388EA651B660ULL, 0xA1C44EB61D3C387AULL, 
            0xC718903078B7FDF7ULL, 0x18F641A0A8BFEE1AULL, 0x30049DD5DC045750ULL, 0x46347FFFB06E29FFULL, 
            0xAF5BFF2270E0C6A7ULL, 0x3D77BCDBA0FF70C6ULL, 0x3BD36D5F396B73CFULL, 0xB317228C0547C266ULL, 
            0x347E44F0EA7D310DULL, 0x84BFD4079C501138ULL, 0x27628935264E1D9BULL, 0x78DE81A077AB366AULL
        },
        {
            0x4F52C347B609CDDCULL, 0x404E3BB2EBB6B2FFULL, 0x967AE24C722286C2ULL, 0x7DE0C7235A367B5FULL, 
            0x40DADBC88935A10CULL, 0x39366F148B4915E8ULL, 0x1D62F64C5AB99073ULL, 0x602211EC73D07A87ULL, 
            0x009653D9E0ABDC43ULL, 0x9C1D67118958C2A7ULL, 0x4112F5667C73CB6CULL, 0x160DCC3D8D82C6FDULL, 
            0x8DE6E2EC44E64114ULL, 0xDDC80B4154B71925ULL, 0x2C06B3594CAAB48EULL, 0x386349D14B742842ULL, 
            0x6AF6E69CFD0E5960ULL, 0x6F28A89E37C39939ULL, 0xCA34FE3B6C38F1CCULL, 0xCEFF2BBD4ECF934FULL, 
            0x1AFB72675FF47E27ULL, 0xC61DE4D8D77FB93CULL, 0x16BCEAFBA87FC36FULL, 0x7494825E856FBAB6ULL, 
            0xA87544A3337F2EA9ULL, 0x16F5DC39F9D0D90CULL, 0xBF1A1065B183D104ULL, 0xE003FAB31F67D4CDULL, 
            0x6AA0204A50527B79ULL, 0x0A1871274C4305F6ULL, 0xE2DAC545575E23A4ULL, 0xE433F84DF3BE5B96ULL
        },
        {
            0x160F26DD7B003C47ULL, 0x499D3650D49E3069ULL, 0xF294E630C8657D18ULL, 0xC842A6BF58337F38ULL, 
            0xD92C5DCD2AF6FF66ULL, 0x4791AED69D11E33FULL, 0x2066DBB2D72ABBA7ULL, 0x46C84383A523AA60ULL, 
            0x96E2C686C21C6817ULL, 0x057CA6D976FBA6E7ULL, 0x635FEB05733BCE6CULL, 0xE056D99A358400C2ULL, 
            0x0DB5570CD3DF376AULL, 0x225D53785B62BB04ULL, 0x0E18D79383917141ULL, 0x344B5F002C8138E3ULL, 
            0xD945F9BC1E3739BBULL, 0x8A63BC88DBD1D50EULL, 0xAEA15D6CE7C92FA3ULL, 0xE489024FAC24EEE4ULL, 
            0xD0D3EB94442492F2ULL, 0x6CA784E5839D6B68ULL, 0xEEA21855F55CFE25ULL, 0x704A0D365979F901ULL, 
            0x8932F7314053DDB1ULL, 0xDCD78ECCCC20892FULL, 0x7F7D4436533DADECULL, 0x2B2A1DB585211AB5ULL, 
            0x7557D1C972545265ULL, 0xC6ED4F69FF5A7AF6ULL, 0xD9AB64F5AE89E309ULL, 0x6E0C5AE7D1125525ULL
        },
        {
            0x62483F94929C0554ULL, 0xBBE48D453CC4666AULL, 0xA5B82AED46199583ULL, 0x00C069D43998D9DFULL, 
            0xE2AA1793BA23B944ULL, 0xEF90AE065BE08D3EULL, 0x2C065E6510D8E48BULL, 0x95F0F0BD9639CD97ULL, 
            0x650020AE25D1F4F4ULL, 0x989C5ECD5A77BFD5ULL, 0x807513E4E420F0BEULL, 0x8198E22B685BA8A1ULL, 
            0x1D5BF1A0227895B9ULL, 0x767F062BA66A2398ULL, 0x8D361CC855AA0E34ULL, 0x0D2BE68EB91B5BD1ULL, 
            0x3F0C927C4B623692ULL, 0x3ADB1FD0E0FCECF3ULL, 0x26E1DAE3EE94BED8ULL, 0xDAE4094CD518E267ULL, 
            0x51AE2A3F3908513FULL, 0xBDE6C1A1CB3C69ADULL, 0x401C77FBECA1B559ULL, 0xCBFA098DA5B7D83CULL, 
            0x79A19FF51DCB85E7ULL, 0x22A3F2BB5EEE9030ULL, 0x2A7326DE4AF29A87ULL, 0xAF813CA3DD781317ULL, 
            0x68302BD7B633EC11ULL, 0x72EC284DF4B07D66ULL, 0x039B9BA4FCD209B1ULL, 0xBFE04B2752A29B18ULL
        },
        {
            0xD1DC3D2ADFD21BA7ULL, 0xD59C0525D4B3DD33ULL, 0x75AE9E4AE21500E7ULL, 0xE9C893342FBDC014ULL, 
            0xB4C0EBD23D20223BULL, 0x6657301E0C02019FULL, 0xCD8D81AEB24DD262ULL, 0x8769CD96011ACB48ULL, 
            0xD3A5652AD7147815ULL, 0x11770E99866E3AFBULL, 0xA5770CB4E0C0CA48ULL, 0x0F087D45CAAB8DFEULL, 
            0x04490B1B156694F5ULL, 0x086DF5F1DB2ED991ULL, 0x73019DA7501713B0ULL, 0xF1FC68D3E8BDE10EULL, 
            0xC918B4C72FBA5487ULL, 0xA8184165608D025CULL, 0x3086527CB25056DBULL, 0xE010C76C6AA8A60BULL, 
            0x32AB169BC98030A0ULL, 0x51095BAA48315103ULL, 0xB617E190929D83F7ULL, 0x2804996C629E60D2ULL, 
            0x0589CED2D4929DF5ULL, 0x339EFC4F250BF8B1ULL, 0x6EAA182D67D57140ULL, 0x04B2B8D35B947150ULL, 
            0x9E6D394335F326FAULL, 0xFDB1319FBE5ECBE3ULL, 0x4DFC56FA396D3166ULL, 0x1E7E9243D484FB4BULL
        },
        {
            0x7B9AABD5135646A1ULL, 0xB34CD64744D6134DULL, 0xC46B9378E1C499FEULL, 0xD007D975F8737461ULL, 
            0xB662558F276FCABFULL, 0xE280D70B49793A50ULL, 0x246282AABFD83504ULL, 0x7C6EF2E9595301CEULL, 
            0xACBC30E404205A12ULL, 0x5A1F544769BBCCCDULL, 0x0AC59B0677C8767EULL, 0x673153B2887AE1B9ULL, 
            0xCCC19E51D0B4C6FBULL, 0xA96785DCEF4F5C2AULL, 0xF3BE53B8CCE26274ULL, 0xB0E8CE91CE30A9F3ULL, 
            0xB85BAE374A613E88ULL, 0xC676C1576372F6ABULL, 0xDC9CA51648C4D5ACULL, 0x38E0D332C5E91A4BULL, 
            0x1C0FC9E9F5D4698FULL, 0xF0F3CC03E2253C72ULL, 0xB18FF2C98A902772ULL, 0x375D999FF125FD5BULL, 
            0xBD766550B12738F5ULL, 0xF5307A697D1212D5ULL, 0xB9EA43B649BBCB10ULL, 0x0D7581F6C286FADCULL, 
            0xB5AD77E6F406B869ULL, 0x1AB7CD67102DB04AULL, 0xDB1CC35AE506249FULL, 0xF666228B3D30C174ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Ankaa::kTwistConstants = {
    0x45A64B229D8225C1ULL,
    0x5FDBB78C8EFAFBB8ULL,
    0xE27FDC6A587BFFE9ULL,
    0x45A64B229D8225C1ULL,
    0x5FDBB78C8EFAFBB8ULL,
    0xE27FDC6A587BFFE9ULL,
    0x2B01145DBB227381ULL,
    0xF6DC8AD2B31B0B03ULL,
    0x41,
    0x05,
    0x64,
    0xDE,
    0xE6,
    0x0E,
    0x41,
    0x34
};

