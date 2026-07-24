#include "TwistExpander_Alkaid.hpp"
#include "TwistDiffuse.hpp"
#include "TwistFunctional.hpp"
#include "TwistIndexShuffle.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"
#include "TwistFarmSalt.hpp"
#include "TwistFarmConstants.hpp"
#include "TwistMemory.hpp"
#include "TwistShiftBox.hpp"
#include "TwistSquash.hpp"

#include <cstdint>
#include <cstring>

TwistExpander_Alkaid::TwistExpander_Alkaid()
: TwistExpander() {
    mDomainBundleInbuilt.mPhaseASalts = kPhaseASalts;
    mDomainBundleInbuilt.mPhaseAConstants = kPhaseAConstants;
    mDomainBundleInbuilt.mPhaseBSalts = kPhaseBSalts;
    mDomainBundleInbuilt.mPhaseBConstants = kPhaseBConstants;
    mDomainBundleInbuilt.mPhaseCSalts = kPhaseCSalts;
    mDomainBundleInbuilt.mPhaseCConstants = kPhaseCConstants;
    mDomainBundleInbuilt.mPhaseDSalts = kPhaseDSalts;
    mDomainBundleInbuilt.mPhaseDConstants = kPhaseDConstants;
    mDomainBundleEphemeral.Zero();
}

void TwistExpander_Alkaid::KDF_A(TwistWorkSpace *pWorkSpace,
                                  std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet,
                                  std::uint8_t *pSnow,
                                  int pIndexKDF) {
    TwistExpander::KDF_A(pWorkSpace, pNonce, pConstants, pDomainSaltSet, pSnow, pIndexKDF);
    if ((pWorkSpace == nullptr) || (pConstants == nullptr) ||
        (pDomainSaltSet == nullptr) || (pSnow == nullptr)) { return; }
    std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
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
    std::uint64_t aPrevious = 0xDE9EE1DD34BABFCCULL; std::uint64_t aIngress = 0xDB9F52A783AF3CB1ULL; std::uint64_t aCarry = 0xC116263C589C0235ULL;

    std::uint64_t aWandererA = 0xB53C832017457A35ULL; std::uint64_t aWandererB = 0x8720DB9233CD2CE9ULL; std::uint64_t aWandererC = 0xC64BF12E8B1AE12AULL; std::uint64_t aWandererD = 0xC513B37770097496ULL;
    std::uint64_t aWandererE = 0xE3F196184F6BE559ULL; std::uint64_t aWandererF = 0x99A53615F1CD5AABULL; std::uint64_t aWandererG = 0xD6E242C4C57920AEULL; std::uint64_t aWandererH = 0xDD1556C63849534CULL;
    std::uint64_t aWandererI = 0xD863A812BC530CA0ULL; std::uint64_t aWandererJ = 0xFB793EFB8CD164F5ULL; std::uint64_t aWandererK = 0xF878AC0493954742ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xFE0B5E4F529855D2ULL;
        aCarry = 0xB48C148A03F33A3BULL;
        aWandererA = 0xB16D26D0F74F9427ULL;
        aWandererB = 0xA81D9FAF4E83ED2DULL;
        aWandererC = 0xD576E66E5C1264A6ULL;
        aWandererD = 0x87294F17C8B3A6E2ULL;
        aWandererE = 0xA352D3A173C5ABE1ULL;
        aWandererF = 0xAB69EF07404328EAULL;
        aWandererG = 0x84EDD8741CC2CE7BULL;
        aWandererH = 0x90FAFA18C9A371A4ULL;
        aWandererI = 0xBFA3B3E0C9D05CF0ULL;
        aWandererJ = 0xA691B8080C2AF4CCULL;
        aWandererK = 0x9E9501F0C335D731ULL;
    TwistExpander_Alkaid_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::KDF_A_C(pWorkSpace,
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

        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,  // input lanes
                         aWindLaneA, aWindLaneB, // output lanes
                         aFireLaneA, aFireLaneB, // index shuffle seeds
                         aFireLaneC, aFireLaneD, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneC, aFuseLaneD,  // input lanes
                         aWindLaneC, aWindLaneD, // output lanes
                         aFireLaneC, aFireLaneD, // index shuffle seeds
                         aFireLaneA, aFireLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    TwistExpander_Alkaid_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Alkaid::KDF_B(TwistWorkSpace *pWorkSpace,
                                  std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet,
                                  int pIndexKDF) {
    TwistExpander::KDF_B(pWorkSpace, pNonce, pConstants, pDomainSaltSet, pIndexKDF);
    if ((pWorkSpace == nullptr) || (pConstants == nullptr) ||
        (pDomainSaltSet == nullptr)) { return; }
    std::uint8_t *aPoisonLaneA = pWorkSpace->mPoisonLaneA;
    std::uint8_t *aPoisonLaneB = pWorkSpace->mPoisonLaneB;
    std::uint8_t *aPoisonLaneC = pWorkSpace->mPoisonLaneC;
    std::uint8_t *aPoisonLaneD = pWorkSpace->mPoisonLaneD;
    std::uint8_t *aSpiritLaneA = pWorkSpace->mSpiritLaneA;
    std::uint8_t *aSpiritLaneB = pWorkSpace->mSpiritLaneB;
    std::uint8_t *aSpiritLaneC = pWorkSpace->mSpiritLaneC;
    std::uint8_t *aSpiritLaneD = pWorkSpace->mSpiritLaneD;
    std::uint8_t *aFuseLaneA = pWorkSpace->mFuseLaneA;
    std::uint8_t *aFuseLaneB = pWorkSpace->mFuseLaneB;
    std::uint8_t *aFuseLaneC = pWorkSpace->mFuseLaneC;
    std::uint8_t *aFuseLaneD = pWorkSpace->mFuseLaneD;
    std::size_t *aIndexList256A = mIndexList256A;
    std::size_t *aIndexList256B = mIndexList256B;
    std::size_t *aIndexList256C = mIndexList256C;
    std::size_t *aIndexList256D = mIndexList256D;
    std::uint64_t aPrevious = 0xAED240E1EDC6726FULL; std::uint64_t aIngress = 0x98D62AC2181CEA57ULL; std::uint64_t aCarry = 0xC35301B6208A9BF7ULL;

    std::uint64_t aWandererA = 0x8E16383DC1FE48F0ULL; std::uint64_t aWandererB = 0x934FA04D93CF8F9FULL; std::uint64_t aWandererC = 0xE20FACD0C3EF0A59ULL; std::uint64_t aWandererD = 0xCC02AEB17B645746ULL;
    std::uint64_t aWandererE = 0xB281082B4C00C013ULL; std::uint64_t aWandererF = 0xFB559E8BC8EEFABEULL; std::uint64_t aWandererG = 0x838B645881E327F2ULL; std::uint64_t aWandererH = 0x80C724B2D7BFAD2CULL;
    std::uint64_t aWandererI = 0xA2F826E92D9B0AC2ULL; std::uint64_t aWandererJ = 0xA67AC194D10B88F5ULL; std::uint64_t aWandererK = 0xD23F66679A53D508ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xA46C2A2A0A5F9B45ULL;
        aCarry = 0x8F74A289277177B8ULL;
        aWandererA = 0x8BCE22998D87028DULL;
        aWandererB = 0xFE184F5C090588AFULL;
        aWandererC = 0xF9E24CE0443FF3A3ULL;
        aWandererD = 0xF48D02C109310399ULL;
        aWandererE = 0xB75B32CAA44B539DULL;
        aWandererF = 0xA52187734682ED0DULL;
        aWandererG = 0x8C30B66041763047ULL;
        aWandererH = 0xC45A1661D45B22E1ULL;
        aWandererI = 0xA7484800B95E28D8ULL;
        aWandererJ = 0xF8D6581202E6D667ULL;
        aWandererK = 0xA41A3B8E7C2120C8ULL;
    TwistExpander_Alkaid_Arx::KDF_B_A(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
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

    TwistExpander_Alkaid_Arx::KDF_B_B(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
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

    TwistExpander_Alkaid_Arx::KDF_B_C(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
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

        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,  // input lanes
                         aPoisonLaneA, aPoisonLaneB, // output lanes
                         aSpiritLaneA, aSpiritLaneB, // index shuffle seeds
                         aSpiritLaneC, aSpiritLaneD, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneC, aFuseLaneD,  // input lanes
                         aPoisonLaneC, aPoisonLaneD, // output lanes
                         aSpiritLaneC, aSpiritLaneD, // index shuffle seeds
                         aSpiritLaneA, aSpiritLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    TwistExpander_Alkaid_Arx::KDF_B_D(pWorkSpace,
                 pNonce,
                 pConstants,
                 pDomainSaltSet,
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
    mDomainBundleInbuilt.mPhaseASalts = kPhaseASalts;
    mDomainBundleInbuilt.mPhaseAConstants = kPhaseAConstants;
    mDomainBundleInbuilt.mPhaseBSalts = kPhaseBSalts;
    mDomainBundleInbuilt.mPhaseBConstants = kPhaseBConstants;
    mDomainBundleInbuilt.mPhaseCSalts = kPhaseCSalts;
    mDomainBundleInbuilt.mPhaseCConstants = kPhaseCConstants;
    mDomainBundleInbuilt.mPhaseDSalts = kPhaseDSalts;
    mDomainBundleInbuilt.mPhaseDConstants = kPhaseDConstants;
    mDomainBundleEphemeral.Zero();
    pWorkSpace->mDomainBundle.Zero();
    std::uint8_t *aSource = pWorkSpace->mSource;
    std::uint8_t *aHeartLaneA = pWorkSpace->mHeartLaneA;
    std::uint8_t *aHeartLaneB = pWorkSpace->mHeartLaneB;
    std::uint8_t *aHeartLaneC = pWorkSpace->mHeartLaneC;
    std::uint8_t *aHeartLaneD = pWorkSpace->mHeartLaneD;
    std::uint8_t *aSpiritLaneA = pWorkSpace->mSpiritLaneA;
    std::uint8_t *aSpiritLaneB = pWorkSpace->mSpiritLaneB;
    std::uint8_t *aSpiritLaneC = pWorkSpace->mSpiritLaneC;
    std::uint8_t *aSpiritLaneD = pWorkSpace->mSpiritLaneD;
    std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
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
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;
    std::size_t *aIndexList256A = mIndexList256A;
    std::size_t *aIndexList256B = mIndexList256B;
    std::size_t *aIndexList256C = mIndexList256C;
    std::size_t *aIndexList256D = mIndexList256D;
    std::uint64_t aPrevious = 0xD67AA22DEA6B779EULL;
    std::uint64_t aIngress = 0xDC0539FA8C931327ULL;
    std::uint64_t aCarry = 0xA5D6E57589A86AFCULL;

    std::uint64_t aWandererA = 0xD0AEB359AB549E46ULL;
    std::uint64_t aWandererB = 0xCB659B147E18C201ULL;
    std::uint64_t aWandererC = 0xEF4D3C943DC0FF88ULL;
    std::uint64_t aWandererD = 0xA0CEB6DC8568E913ULL;
    std::uint64_t aWandererE = 0xEF6DFE488F91724BULL;
    std::uint64_t aWandererF = 0xE432A6D21E286F0EULL;
    std::uint64_t aWandererG = 0x8D3D4D0821B4FC66ULL;
    std::uint64_t aWandererH = 0xCB561C02C7AA92C0ULL;
    std::uint64_t aWandererI = 0xAD07E87B066B57B7ULL;
    std::uint64_t aWandererJ = 0xA1835769BE020713ULL;
    std::uint64_t aWandererK = 0xEFEC1C7B78D0B530ULL;

    // [seed]
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), pSnowLaneC, 0);
    ////////
    pFarmSalt->Derive(aWaterLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWaterLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWaterLaneC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    ////////
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseAConstants));
    ////////
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
    ////////
        TwistSquash::SquashC(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, aIceLaneA);
    ////////
    pFarmSalt->Derive(aHeartLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aHeartLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aHeartLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    ////////
    TwistFarmConstants::Derive(aHeartLaneD, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase B
    ////////
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), pSnowLaneD, 1);
    ////////
    pFarmSalt->Derive(aWaterLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWaterLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWaterLaneC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    ////////
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseBConstants));
    ////////
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
    ////////
        TwistSquash::SquashB(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, aIceLaneB);
    ////////
    pFarmSalt->Derive(aHeartLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aHeartLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aHeartLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    ////////
    TwistFarmConstants::Derive(aHeartLaneD, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase C
    ////////
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), pSnowLaneA, 2);
    ////////
    pFarmSalt->Derive(aWaterLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWaterLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWaterLaneC, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    ////////
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    ////////
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
    ////////
        TwistSquash::SquashC(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, aIceLaneC);
    ////////
    pFarmSalt->Derive(aHeartLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aHeartLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aHeartLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    ////////
    TwistFarmConstants::Derive(aHeartLaneD, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase D
    ////////
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), pSnowLaneB, 3);
    ////////
    pFarmSalt->Derive(aWaterLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWaterLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWaterLaneC, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    ////////
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseDConstants));
    ////////
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
    ////////
        TwistSquash::SquashB(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, aIceLaneD);
    ////////
    pFarmSalt->Derive(aHeartLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aHeartLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aHeartLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    ////////
    TwistFarmConstants::Derive(aHeartLaneD, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    // GSquashInvestToKeyBoxes (start)
    SquashInvestToKeyBoxes(pWorkSpace);
    // GSquashInvestToKeyBoxes (end)
    //
    TwistExpander_Alkaid_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::Seed_C(pWorkSpace,
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
    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixArgD;
    //
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,  // input lanes
                         aWindLaneA, aWindLaneB, // output lanes
                         aFireLaneC, aFireLaneD, // index shuffle seeds
                         aFireLaneA, aFireLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneC, aFuseLaneD,  // input lanes
                         aWindLaneC, aWindLaneD, // output lanes
                         aFireLaneA, aFireLaneB, // index shuffle seeds
                         aFireLaneC, aFireLaneD, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    TwistExpander_Alkaid_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::Seed_F(pWorkSpace,
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
    aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixSelectA;
    aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixSelectB;
    aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixUnrollA;
    aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixUnrollB;
    aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgA;
    aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgB;
    aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgC;
    aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgD;
    //
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,  // input lanes
                         aSpiritLaneA, aSpiritLaneB, // output lanes
                         aHeartLaneC, aHeartLaneD, // index shuffle seeds
                         aHeartLaneA, aHeartLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneC, aFuseLaneD,  // input lanes
                         aSpiritLaneC, aSpiritLaneD, // output lanes
                         aHeartLaneA, aHeartLaneB, // index shuffle seeds
                         aHeartLaneC, aHeartLaneD, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    TwistExpander_Alkaid_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Alkaid_Arx::Seed_H(pWorkSpace,
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

        TwistSquash::SquashB(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, pDestination);
    //
    //
    TwistExpander_Alkaid_Arx::GROW_A(pWorkSpace,
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

    GrowKeyA(pWorkSpace);
    TwistExpander_Alkaid_Arx::GROW_B(pWorkSpace,
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

    GrowKeyB(pWorkSpace);
    pWorkSpace->Zero_PostSeed();
    Zero_PostSeed();
}

// SmartSquash candidate 5 of 33
// Exploration cases: 100000000
// Nearest-family diversity: 950 / 1088 (87.32%)
// Total distance from earlier candidates: 3816
void TwistExpander_Alkaid::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    static_assert((S_BLOCK / W_KEY) == 16, "SquashInvestToKeyBoxes expects 16 invest fragments.");
    static_assert(H_KEY == 8, "SquashInvestToKeyBoxes expects 8 key rows per box.");
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 3U), *aFragmentB = aIceLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 4U), *aFragmentD = aIceLaneD + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 163U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 155U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 885U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 400U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 8U), *aFragmentB = aIceLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 6U), *aFragmentD = aIceLaneD + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1824U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 368U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 926U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 798U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 10U), *aFragmentB = aIceLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 5U), *aFragmentD = aIceLaneD + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1626U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 157U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1731U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 500U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 14U), *aFragmentB = aIceLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 2U), *aFragmentD = aIceLaneD + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1674U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 674U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1015U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1364U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 9U), *aFragmentB = aIceLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 14U), *aFragmentD = aIceLaneD + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1932U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1954U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 129U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 197U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 0U), *aFragmentB = aIceLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 15U), *aFragmentD = aIceLaneD + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1407U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1231U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 173U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1990U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 12U), *aFragmentB = aIceLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 3U), *aFragmentD = aIceLaneD + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1749U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1343U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1383U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 478U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 15U), *aFragmentB = aIceLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 10U), *aFragmentD = aIceLaneD + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1659U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 828U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1149U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1280U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 5U), *aFragmentB = aIceLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 8U), *aFragmentD = aIceLaneD + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 480U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1560U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 934U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1942U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 2U), *aFragmentB = aIceLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 12U), *aFragmentD = aIceLaneD + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1702U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 694U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 124U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 376U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 7U), *aFragmentB = aIceLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 13U), *aFragmentD = aIceLaneD + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 374U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1453U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 454U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 988U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 1U), *aFragmentB = aIceLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 7U), *aFragmentD = aIceLaneD + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 629U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1436U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1488U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1345U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 11U), *aFragmentB = aIceLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 1U), *aFragmentD = aIceLaneD + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 246U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 953U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 839U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 207U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 4U), *aFragmentB = aIceLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 0U), *aFragmentD = aIceLaneD + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 681U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1461U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1574U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1075U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 13U), *aFragmentB = aIceLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 9U), *aFragmentD = aIceLaneD + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1157U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 878U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 2045U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 803U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 6U), *aFragmentB = aIceLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 11U), *aFragmentD = aIceLaneD + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1434U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 46U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1915U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1771U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Alkaid::TwistBlock(TwistWorkSpace *pWorkSpace,
                                       std::uint8_t *pSource,
                                       std::uint8_t *pDestination) {
    TwistExpander::TwistBlock(pWorkSpace, pSource, pDestination);
    if ((pWorkSpace == nullptr) || (pDestination == nullptr)) { return; }
    std::uint8_t *aHeartLaneA = pWorkSpace->mHeartLaneA;
    std::uint8_t *aHeartLaneB = pWorkSpace->mHeartLaneB;
    std::uint8_t *aHeartLaneC = pWorkSpace->mHeartLaneC;
    std::uint8_t *aHeartLaneD = pWorkSpace->mHeartLaneD;
    std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
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
    std::uint64_t aPrevious = 0xF4C786AD2E6AFF4CULL; std::uint64_t aIngress = 0x9ADBC7BF1BCE1E91ULL; std::uint64_t aCarry = 0xCFBC67AC3C5C5C12ULL;

    std::uint64_t aWandererA = 0x852D4430EC922277ULL; std::uint64_t aWandererB = 0xE306C794C63940FEULL; std::uint64_t aWandererC = 0xC1DD8C0C9153D760ULL; std::uint64_t aWandererD = 0xC735B4B68410C151ULL;
    std::uint64_t aWandererE = 0xAB6FD91C2D02A49BULL; std::uint64_t aWandererF = 0xD10A20599EB7F7C9ULL; std::uint64_t aWandererG = 0xCA4E11860B95FA38ULL; std::uint64_t aWandererH = 0x8543683EF35D99E0ULL;
    std::uint64_t aWandererI = 0xEFA49F4FE962E93DULL; std::uint64_t aWandererJ = 0xE116B7E69EF21142ULL; std::uint64_t aWandererK = 0xD7D1B4F3F965513DULL;

    // [seed]
        aPrevious = 0xD693DD6F89442908ULL;
        aCarry = 0x8E3787E4CF5C8EC9ULL;
        aWandererA = 0xEE78EF4BCDD9A3AAULL;
        aWandererB = 0x9A27613D5B6552B4ULL;
        aWandererC = 0xADDF9A12227C550BULL;
        aWandererD = 0xD88D5D0181E52DC3ULL;
        aWandererE = 0xBD9771D4AEA79280ULL;
        aWandererF = 0xB43DFE0C20EA260DULL;
        aWandererG = 0xCAA3BCED053E7352ULL;
        aWandererH = 0x93CCA782FB6F5D56ULL;
        aWandererI = 0xF74BBE264C84CE5CULL;
        aWandererJ = 0xCCB04BCE359940F2ULL;
        aWandererK = 0xD8CF295566937BC4ULL;
    TwistExpander_Alkaid_Arx::Twist_A(pWorkSpace,
                 pSource,
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

    TwistExpander_Alkaid_Arx::Twist_B(pWorkSpace,
                 pSource,
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

    TwistExpander_Alkaid_Arx::Twist_C(pWorkSpace,
                 pSource,
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

    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgD;
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,  // input lanes
                         aWindLaneA, aWindLaneB, // output lanes
                         aFireLaneC, aFireLaneD, // index shuffle seeds
                         aFireLaneA, aFireLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneC, aFuseLaneD,  // input lanes
                         aWindLaneC, aWindLaneD, // output lanes
                         aFireLaneA, aFireLaneB, // index shuffle seeds
                         aFireLaneC, aFireLaneD, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    TwistExpander_Alkaid_Arx::Twist_D(pWorkSpace,
                 pSource,
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

    TwistExpander_Alkaid_Arx::Twist_E(pWorkSpace,
                 pSource,
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
        TwistSquash::SquashC(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, pDestination);
    TwistExpander_Alkaid_Arx::GROW_A(pWorkSpace,
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

    GrowKeyA(pWorkSpace);
    TwistExpander_Alkaid_Arx::GROW_B(pWorkSpace,
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

    GrowKeyB(pWorkSpace);
}

// GrowA candidate 5 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 2324; nearest pair: 534 / 674
void TwistExpander_Alkaid::GrowKeyA(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;
    std::uint8_t *aWaterLaneA = pWorkSpace->mWaterLaneA;
    std::uint8_t *aWaterLaneB = pWorkSpace->mWaterLaneB;
    std::uint8_t *aWaterLaneC = pWorkSpace->mWaterLaneC;
    std::uint8_t *aWaterLaneD = pWorkSpace->mWaterLaneD;
    std::uint8_t *aPoisonLaneA = pWorkSpace->mPoisonLaneA;
    std::uint8_t *aPoisonLaneB = pWorkSpace->mPoisonLaneB;
    std::uint8_t *aPoisonLaneC = pWorkSpace->mPoisonLaneC;
    std::uint8_t *aPoisonLaneD = pWorkSpace->mPoisonLaneD;
    std::uint8_t *aKeyRowWriteA = &(pWorkSpace->mKeyBoxA[0][0]);
    static_assert((S_BLOCK / S_QUARTER) == 4, "GrowKeyA expects four expansion-lane quarters.");
    static_assert((S_QUARTER / W_KEY) == 4, "GrowKeyA expects four key chunks per quarter.");
    TwistShiftBox::ShiftKeyBoxA(pWorkSpace);
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3109U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2112U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1147U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7112U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7368U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5950U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7065U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5979U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6473U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5965U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2846U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5276U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7625U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3144U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4574U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3178U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1845U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 287U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1116U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1247U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 302U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1925U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1475U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 164U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1336U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 13U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 760U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 84U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1512U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 214U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1624U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 937U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 293U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 642U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 6U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1666U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
}

// GrowB candidate 5 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 2313; nearest pair: 568 / 674
void TwistExpander_Alkaid::GrowKeyB(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aSpiritLaneA = pWorkSpace->mSpiritLaneA;
    std::uint8_t *aSpiritLaneB = pWorkSpace->mSpiritLaneB;
    std::uint8_t *aSpiritLaneC = pWorkSpace->mSpiritLaneC;
    std::uint8_t *aSpiritLaneD = pWorkSpace->mSpiritLaneD;
    std::uint8_t *aWaterLaneA = pWorkSpace->mWaterLaneA;
    std::uint8_t *aWaterLaneB = pWorkSpace->mWaterLaneB;
    std::uint8_t *aWaterLaneC = pWorkSpace->mWaterLaneC;
    std::uint8_t *aWaterLaneD = pWorkSpace->mWaterLaneD;
    std::uint8_t *aPoisonLaneA = pWorkSpace->mPoisonLaneA;
    std::uint8_t *aPoisonLaneB = pWorkSpace->mPoisonLaneB;
    std::uint8_t *aPoisonLaneC = pWorkSpace->mPoisonLaneC;
    std::uint8_t *aPoisonLaneD = pWorkSpace->mPoisonLaneD;
    std::uint8_t *aKeyRowWriteB = &(pWorkSpace->mKeyBoxB[0][0]);
    static_assert((S_BLOCK / S_QUARTER) == 4, "GrowKeyB expects four operation-lane quarters.");
    static_assert((S_QUARTER / W_KEY) == 4, "GrowKeyB expects four key chunks per quarter.");
    TwistShiftBox::ShiftKeyBoxB(pWorkSpace);
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3501U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1099U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4931U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 570U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5734U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2520U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7265U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2832U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5297U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7126U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 274U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5924U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4160U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6659U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5550U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1645U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 94U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1734U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 514U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 863U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 147U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1470U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1624U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 101U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1305U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1077U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1571U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 331U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1371U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1320U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 236U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 2032U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 104U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 189U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 731U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
}

const TwistDomainSaltSet TwistExpander_Alkaid::kPhaseASalts = {
    {
        {
            0xBC93BC81C98C5DD1ULL, 0x44685C246A77F831ULL, 0xD65056B4663A3C7EULL, 0x329B574F8051F6C1ULL, 
            0x3848C86AD9E28FA6ULL, 0xD99E0C1EB831C03FULL, 0x9346CFD0655C6617ULL, 0xA3CD659AA259E64BULL, 
            0x961468DE0120D2B6ULL, 0x2BCEA39AA00981DAULL, 0xB65DD4A5FF1B8ECAULL, 0xF6FD6D7531784552ULL, 
            0x36E06C683561C688ULL, 0x876F460509875CEFULL, 0x4289404C3BBD012EULL, 0x482833316D120D5FULL, 
            0x4DF01372D7505FB7ULL, 0xE8934CFEF9DEB314ULL, 0xF673D0094EE112ABULL, 0xA746C1DAF49F2AA8ULL, 
            0xBDBE1A18886E63C3ULL, 0x4698AC4082FE7CF4ULL, 0x0510A1B88F3D7F3AULL, 0xC8F94C50793CF247ULL, 
            0xA811848D345EBD48ULL, 0xA9329A2406191361ULL, 0x3F45EA3C1580598DULL, 0x18B2F2CBE811CA98ULL, 
            0x67DAF8E3DD6150B8ULL, 0xC3C28EEC4934952FULL, 0xE1A0056D5E269711ULL, 0x635C16010BB9BDD1ULL
        },
        {
            0xD49DC27CCF3C78C1ULL, 0x597E26ADC355D14FULL, 0xD82EEA8BFAEA6D03ULL, 0x2C19A4986DC922B1ULL, 
            0xD7E9AFD8D2483420ULL, 0xADFD7791ABD2B89EULL, 0xE9EFE7A8620D58CFULL, 0xAFEB9E1700EF09CFULL, 
            0xA6F80839A07F004FULL, 0xAEA0C81B24CCBAB3ULL, 0x9F0DB7AC4B13EF62ULL, 0x2994688A5F33F082ULL, 
            0xDB83AD2A2552BB44ULL, 0xF540A74FF09A49E8ULL, 0x471B897A09275E3BULL, 0xDD90029AF7E84A8EULL, 
            0xA459BE1AD6747F0CULL, 0x1A932D140DAAE34CULL, 0x257D421FC7A447C6ULL, 0x7D355EA7E4B70B7FULL, 
            0x6D982EAA66974943ULL, 0x9AC434CA29C65BE9ULL, 0x49D40196C1B6FC2CULL, 0x370B88B51A3CE074ULL, 
            0x7304A9F2300B4AACULL, 0xCE1BD828E979D251ULL, 0x7089482403540C43ULL, 0xC26F45D1691ABE13ULL, 
            0xB6D0AB0EAB90E052ULL, 0x494CA732790DB645ULL, 0xB1BB39A05D157CAEULL, 0xBCCA136595398B8DULL
        },
        {
            0x6592ADE34F59AC2DULL, 0x5F9175E037301073ULL, 0x256358E0A6F9A3B2ULL, 0x25EA8114B3BA9200ULL, 
            0x6F7CCD53F72EC1DDULL, 0xEA58A7CEF84CC7D3ULL, 0xDDB007208F155956ULL, 0xF2BBE4B41A8A18C5ULL, 
            0x887DA72C957D720DULL, 0x392FC14C9D698AD6ULL, 0x3024AF9F1BC53FB0ULL, 0x593F58B802788C02ULL, 
            0x15D18E43D866AE78ULL, 0x69D05C23FC17327BULL, 0x02FD0CDF6AF0A097ULL, 0x104A3753478DDE0FULL, 
            0xDE2E58BB8A048B5CULL, 0x04EC0233906AC12AULL, 0x305310E6544E38C6ULL, 0x117EE20E058E2C07ULL, 
            0xC727272C97DC1360ULL, 0x7770223C05D9854CULL, 0xB432252699A5BFCBULL, 0x993C96B242EC97F8ULL, 
            0x14DEC36CFF0DDB96ULL, 0xB888FEB6B81E52C0ULL, 0x7917B508B5B56948ULL, 0xBE618BD5A0DB29D9ULL, 
            0x9671F3C25ED5568CULL, 0x800F328425CB1134ULL, 0x9941E7F8F0697655ULL, 0x7FB52975461994ABULL
        },
        {
            0x12BCB37379305B96ULL, 0xAC32F5B5FE4E012CULL, 0x8BEF2049D0E524B1ULL, 0x9831C6D7D06F14ADULL, 
            0x2059798A665AEC34ULL, 0x7D6208D1BA749EB5ULL, 0x9C847A95789B597CULL, 0xD0328242CAF977DCULL, 
            0xA8425408029317FAULL, 0x75050965D3577247ULL, 0x48883A3771788ADAULL, 0xA617E2F31A795F7EULL, 
            0x5EE8C2DEE23BCF11ULL, 0x059EBFE59D04E474ULL, 0x77B25542C8305389ULL, 0x285C4BE16549DCB0ULL, 
            0x96FC87BEDC809415ULL, 0x3124290B47C140DEULL, 0xE137DB0E05184B21ULL, 0xFD17E4C8D5F570CEULL, 
            0x54233E32A2F563ADULL, 0x7393CBC3DD0C93D4ULL, 0x7966EA602B7104C0ULL, 0xE0AC72ADC5466762ULL, 
            0x2AF0600C71BEC8ABULL, 0xCBE898B69783FAFEULL, 0x0DD5207A4E89175EULL, 0x27459A305A0A4A17ULL, 
            0xB7F7D6D8B4DAFD4EULL, 0xD13ECD5F50B6D149ULL, 0x6D9F29A65238DF9CULL, 0x63B4E63FB806B206ULL
        },
        {
            0x061B5D21129B088AULL, 0x1263D9F5EBFCF5AEULL, 0x3B5379BCD709A077ULL, 0x10EA5C16AD0FC400ULL, 
            0x75BAD1C826E6911CULL, 0xA1D10305B778D1E2ULL, 0x44CA6179188CE691ULL, 0xE55FBF28473FC0B9ULL, 
            0xBE43C7E1728BA92BULL, 0x2CB9D753C25C340DULL, 0x695ED7D362D1C388ULL, 0xAD87C3EF489EEBDFULL, 
            0x94E49D55DA956802ULL, 0x8A0CD89FAD8FDA9FULL, 0x9D8B5E30C01149F5ULL, 0x9D8BF10FE6DE3465ULL, 
            0x7613EA690AE1AF62ULL, 0xEB53B7860F97B907ULL, 0xDB32D91251B6ACA6ULL, 0xF1D10CD7E75D9C73ULL, 
            0x57C8C12B4A3FCA2BULL, 0x5455B5E2FB0C678AULL, 0xE1AFAF6C68205177ULL, 0x21F590F9E85CA6BBULL, 
            0xF5A592CFBB9CE42BULL, 0xAB033FF76C63CB09ULL, 0x4E88B7936AD6DE52ULL, 0xF08515DDACECA7F2ULL, 
            0xB62EA26C14093DCBULL, 0x5AE2DD6B01DEDA9CULL, 0xD47BD4C75E6613DAULL, 0x0DBEFF4531F1CF5FULL
        },
        {
            0x2D0954C436B26414ULL, 0xE3CB2DB5F85E53FAULL, 0x70CA62190F59AFB3ULL, 0x900F6C4B88332B56ULL, 
            0x1AEC35241B950592ULL, 0x92DEECF4F5D5B5CCULL, 0x9CD8C76CA4900157ULL, 0x861905577B7FF060ULL, 
            0x18F8B120F0E16D38ULL, 0x20CC8954A5070664ULL, 0x1644A77D04843A8CULL, 0xECAE1FAAAB596828ULL, 
            0x0AB2E80E6771005FULL, 0xD304DEF90B015412ULL, 0x5E606795355BDAAEULL, 0x7C32A7196E48355AULL, 
            0x389B4FF8D5D39399ULL, 0x5C0AAAF0A5A5CD97ULL, 0xC1037BDEB4589468ULL, 0xE4FD45473CCD7526ULL, 
            0x4711E10D90C2FDEBULL, 0xE99CE1C9CCEF91E1ULL, 0x13F2259586ED788BULL, 0xCEE265AE7BAB7079ULL, 
            0x7292B0A48ABE3F8AULL, 0x1E1DFD9F175A0E00ULL, 0xE4006B0FA72B7327ULL, 0x5BE07BF36A0452DDULL, 
            0x82BB1976C239198CULL, 0x8B358C7FF096743FULL, 0xDCD3E28776102AE5ULL, 0x3D73D2903FD05B9DULL
        }
    },
    {
        {
            0xC46FACCB2FF64195ULL, 0xFD7EDDCE6EC9DF89ULL, 0xB85027AB915FB090ULL, 0xE131598F1C4FC480ULL, 
            0xD41953369B77B687ULL, 0x054B8365A2E25278ULL, 0x648A9BD9D2E79673ULL, 0x8E8F0293861B14BBULL, 
            0x3FCF43AF01A2706FULL, 0xB8C4AABA4D417555ULL, 0xF7F3499100A6597DULL, 0xE12F97E5F6142E7BULL, 
            0x74D6D4DF7880096FULL, 0x4F306CF67A90C0ADULL, 0x7C0ECE8051F8CF9DULL, 0x59DC7661BC4A998FULL, 
            0x24FB9445B73CE9EDULL, 0xEA383C932FF5F523ULL, 0x736261706F927B39ULL, 0xEE1E41FE97F40C3BULL, 
            0xA429A08697E3A1E9ULL, 0x4E990274CF896562ULL, 0x957AFED29112A85FULL, 0x33F93BEEBC403CA4ULL, 
            0x1CD8812B623D3EEEULL, 0x357DFDD5A0071148ULL, 0x643D99280B992193ULL, 0x9A9CBBBCA5B478E2ULL, 
            0xF3BA3B6A011BF8B0ULL, 0xCE5B0071E99C254FULL, 0x786891B7771EAF36ULL, 0x56F8B610F94A7F5CULL
        },
        {
            0xA2058ED4615EB699ULL, 0xB649F2A84E70EFC4ULL, 0x34A95828336B8DEEULL, 0x83364BDC2CA0A767ULL, 
            0xBFD5E11E87771DB9ULL, 0xAA09766D52008B08ULL, 0x18DB3B6F479F0B0BULL, 0x46EEFB41E4A1262BULL, 
            0x0EA99F41134D6182ULL, 0x07FC5DEC68F446BFULL, 0x91B12EB40C7599E1ULL, 0x6CB18166ACE0BCA2ULL, 
            0x9403DE8B87B19C66ULL, 0x7A737C9C1CFE5367ULL, 0x9F5DF01FAC5BD21EULL, 0x46333C54C3F43310ULL, 
            0xDFDE76F2BAFA52FEULL, 0xE3AE648CB8E72E3AULL, 0x178881EE4ACFD5A0ULL, 0x0595679801C799B0ULL, 
            0x5BB8B047C36EFA57ULL, 0x0F5003C9A5B5ECA0ULL, 0xBCF4E113597F2F4CULL, 0xD84495E2FFBF831CULL, 
            0x543944B4E07B4846ULL, 0x52418C85F641298EULL, 0x3B060029A79D078BULL, 0x766D70278A619193ULL, 
            0x084069E98141451DULL, 0xB730E0D61FEF9C0EULL, 0x231F975F198B9C2BULL, 0x2CA0E4C5602D94F2ULL
        },
        {
            0x3C9A4F34E2BD4404ULL, 0x1DEEC3E35DE24226ULL, 0xA8FC67A27651F989ULL, 0x95E2537739909BCDULL, 
            0xC85B466F90B3986AULL, 0xBEEC6824333F98FFULL, 0x2B4DAC93208BDEB3ULL, 0x9C4B5B8CAF980BBBULL, 
            0xF9227BDA4E668DD7ULL, 0x62E7B7778213FA58ULL, 0xF6E245554CA6E00AULL, 0x159B2C21F253AC41ULL, 
            0xBDE5D3FCBB45FA3CULL, 0x06514E54EBC0EA5EULL, 0xEDA951BC355B6D39ULL, 0x272588B0348C2EBDULL, 
            0x3C97305E3FDBCF66ULL, 0x0BA5EB864F0A5E33ULL, 0x0197F292E25343E3ULL, 0x7B487E5D95A16036ULL, 
            0x06CD871EC466F896ULL, 0xA58AFEF094B444F3ULL, 0xDD484D8B2BBAEAA8ULL, 0x0B53E4CE9E07B7B2ULL, 
            0x271E34B892388C28ULL, 0xA0BA2BAEEE82AB0CULL, 0xE6833E77C45CEF05ULL, 0x545FA88EB4E9466EULL, 
            0xE9F008C7E4138859ULL, 0x56DCDCEBD8C57503ULL, 0x7C8CB0237F337894ULL, 0xAF190559343AA090ULL
        },
        {
            0x53A01C852729B7BCULL, 0xAC17B33778E88914ULL, 0x5BE2D6B5CF6562C9ULL, 0x438C90E934E8E6F0ULL, 
            0x04AEDF3CF05607BAULL, 0x34DCE2E12ABD5616ULL, 0xD87B589D10C8F47EULL, 0x15FB4EE298CD1AD0ULL, 
            0x24D6532808E45A99ULL, 0xBC5C5FC9773F30EEULL, 0xD9E1B9AEB425F625ULL, 0x27B4738494BD9DEBULL, 
            0xF0B820D683D3C569ULL, 0x086DC04AABCE80E8ULL, 0xCDB2CA19A7D1CD45ULL, 0xD638964B6D12FB36ULL, 
            0x40971E846C0E8F64ULL, 0xEB0537581FBACD55ULL, 0x7DFEC06E1AFAFFBEULL, 0x4490A328E959BBD2ULL, 
            0x6F160C55EC2B3B78ULL, 0x65A606F1EC1CBCACULL, 0x08046179FA42C1EDULL, 0xF2D0043D59441102ULL, 
            0x5D55FC1D70C0CEFAULL, 0xC059D1330589B025ULL, 0x81F0C35A330D7C03ULL, 0xB5631BD54F7A612EULL, 
            0x1DC94B71FBF86526ULL, 0x24AC45347EDCF8FDULL, 0x1DE4DE2A28028B66ULL, 0x3111F164F9B67E05ULL
        },
        {
            0xFDB4F5517B2D7EAFULL, 0x58A984A64D644521ULL, 0xC44BA6E894E5CB74ULL, 0xED0BDA88A92B98F7ULL, 
            0x0248C918B5B70668ULL, 0xD632FB97E8807C21ULL, 0x0A887CA52DA0099FULL, 0x0FD88C9973CDDEBCULL, 
            0xCD37C2CC06D2FF34ULL, 0xDECCA07F0723FB93ULL, 0xD8C3050271D06742ULL, 0xCC0D084D070FFCBEULL, 
            0x51C4E646D8B89810ULL, 0xCE9EA902C9A034E4ULL, 0xAE21F4F06F1E8766ULL, 0xAA74201C85AAC171ULL, 
            0xB306473C629F1861ULL, 0x7DB84622F0C46DD0ULL, 0xE9B5004203CABEE8ULL, 0xB456312240E1CA71ULL, 
            0x776FD6CE5977DB15ULL, 0x97B261BB4CA90E78ULL, 0xC9E3A79D6CF8F05BULL, 0xD5D9E74827EFF3BCULL, 
            0xA5929052A588551EULL, 0xD61BF569F6F0F1F3ULL, 0x794BE78724ED0C2DULL, 0xDA4ED4F0AAA639D7ULL, 
            0x42C86AB5D571424DULL, 0xFCE8A452C9448914ULL, 0x1AB4C60728EDF06DULL, 0x34E34BBB100A0F9EULL
        },
        {
            0x24D2D54E8E97B969ULL, 0x22C5C0BF34B7157DULL, 0x58DE35A94F5CC147ULL, 0xF9E4FE3838DF1FDEULL, 
            0x531A1731A69EA549ULL, 0xF09E36171B0F83F0ULL, 0x2F89B761004100E9ULL, 0xB3B88D71B0F24D9EULL, 
            0xA927F760028A62FAULL, 0xF5028C2399E04D6DULL, 0xDBA3F44165187695ULL, 0x6F96394A82DB356FULL, 
            0x82E42C24CDF46B14ULL, 0xCF28DC2B2F5C9055ULL, 0x6CFE8323FC97A815ULL, 0x60FF7BF81C1FEDBFULL, 
            0x8E069093B26F82ABULL, 0x234F0015E31E8158ULL, 0x8B6E82EC4DBFD6D5ULL, 0xFABA26008FE486E2ULL, 
            0x5961B4459D3D9BFCULL, 0x6D26C73B0D935EC7ULL, 0x6E74651F89D5CE70ULL, 0x1948EBCE3EF22139ULL, 
            0x63B2F62C0A388419ULL, 0xE8CCFBEE68151F7EULL, 0x961D2E47180A4812ULL, 0xCB6DC3548830E185ULL, 
            0x2E37F77B4809D180ULL, 0x743D5C38E64BDFC3ULL, 0xB42FA1104ADE81F1ULL, 0x0040A86D9EEE4215ULL
        }
    },
    {
        {
            0x20C03FAB50FE555CULL, 0xB22826C3E769A736ULL, 0xE9109E435836A889ULL, 0x965A6C2B3D2042A3ULL, 
            0x69510BC73D2497DEULL, 0x1C02B3E6B9347D01ULL, 0x1B9C61F749B55DC4ULL, 0xE8FF5C39FFA79673ULL, 
            0xAD6E47FC36BA860EULL, 0xF21F0844AF01E5A9ULL, 0xBF3E842E3FEE5C4EULL, 0xDA5988C73974DF71ULL, 
            0xA8686FA3F6694A82ULL, 0x95750A430F75F2D8ULL, 0x35A507CA31760924ULL, 0x8CB3FE232B0DAE5FULL, 
            0x90E5CF431243ACC4ULL, 0x4A684C6026D29DB2ULL, 0xF0558D4CC25B7B4DULL, 0x295158A89E5755E5ULL, 
            0x86AAF0CD80030592ULL, 0xAE37D343294216DFULL, 0x08A349C39BE81C83ULL, 0xE93B9862C5CDBA3BULL, 
            0xFD8C58A2A6F5B64FULL, 0x6C0C374C8303F44DULL, 0x6C15F5608C305FDBULL, 0x4AA2EAF4684C58B4ULL, 
            0x3480E7A4B54A9917ULL, 0x408A72981A4C001CULL, 0x24C8CD6AF89241D1ULL, 0x9D47385441670D0FULL
        },
        {
            0x2CE4D33AE04E93EBULL, 0x860066A686FB874AULL, 0x288D09BD4ACA6375ULL, 0xAA2F21EE3349EB5BULL, 
            0x35C69D5B35EA788BULL, 0x38F365E3A18AFF80ULL, 0x4663046E888725E1ULL, 0xA4130277234C4075ULL, 
            0x7926C27698A12E82ULL, 0x38CF060667E2B28FULL, 0xBEC05C35B0AF276EULL, 0x8EC0B4F7344A2762ULL, 
            0x4015E49D6CD02FF8ULL, 0xFABDCB0BAC19BA33ULL, 0x42D91ADBF6D49663ULL, 0xBECB0B1220F89BB6ULL, 
            0x9EFC466D15B894F9ULL, 0x700D4C1161900707ULL, 0xC5BF98FB197D7A7FULL, 0x8AD7303FCA0E15FDULL, 
            0xAD1D650BE7E898DAULL, 0x7678AC2C36627F4DULL, 0x7232A795F8351EABULL, 0x46A14BFB2AFBCD44ULL, 
            0x7D90BAE5ABA34DEAULL, 0x60B1D4AB639F8843ULL, 0x4216104EC5EB28F4ULL, 0xDE99C53F25CAB9BEULL, 
            0x37DB9FB874DA59AFULL, 0x7E214D0EA4220122ULL, 0x6A472B06D525E37BULL, 0xE7F315A620E0B474ULL
        },
        {
            0xF9AA64D385A17FCEULL, 0xF0C332DD2318D954ULL, 0x6915BD6BEFE61C65ULL, 0x3EB80C15C27FD656ULL, 
            0xC3FD54EB20341565ULL, 0x4B5187AB2DD1F8C9ULL, 0x9BD97E458455AFECULL, 0x322DFCE36258DD4BULL, 
            0x5C7B5469B49865D8ULL, 0xB07F026CABD932F9ULL, 0x914624C9A2BC030DULL, 0xB454E5F3C17C6AF4ULL, 
            0x87441F1099E02F60ULL, 0xFDD064A03117981BULL, 0xA9253BCBE4DE1917ULL, 0x8F0E983B6420B54FULL, 
            0xDCDBECDC386DD2A6ULL, 0x4606042E26DA72CFULL, 0x3CC7D51EE2D28895ULL, 0x70CCC919093E42B1ULL, 
            0x390DDE18C1473D50ULL, 0x4B891DA3041C5914ULL, 0x8647F84673390786ULL, 0xEB9B27C490311212ULL, 
            0x5FFAEB381A301C15ULL, 0xF63E3E813A8AD844ULL, 0xD2551124016851CDULL, 0x928E7A4DE23082DDULL, 
            0x9D586454CBBF16F0ULL, 0xCA7FBD11B18A9031ULL, 0xF2731294885A7E94ULL, 0xD97409447CCDB07CULL
        },
        {
            0xF315CB5F2F30DD05ULL, 0xAD45F567F29A227EULL, 0xB217A04527CCE1AEULL, 0xB2DFEDF16FD16555ULL, 
            0x97AA5FBCD7B58F76ULL, 0xA9CFC88B67A6C58CULL, 0x00B2E592CA181A29ULL, 0xC0D36FD84EF3AE4FULL, 
            0x75052FE75C54CB10ULL, 0x684D6520D7253B19ULL, 0xB36F578A1BB908D5ULL, 0xAFFBEAAAC4FC73F2ULL, 
            0x425EA9D79161B3A5ULL, 0x12DFCC04B620A9B5ULL, 0x3269E45FE9951A40ULL, 0xBABC5C8B24ED34FAULL, 
            0x0FF12F6F1E2EF696ULL, 0x159463B41D9C9A60ULL, 0x44B7DBB95AAF4040ULL, 0x03CD5F583ABF7E54ULL, 
            0x0137E778A98A7EA4ULL, 0xB27FE564B492FD42ULL, 0x90F6C8E49ADA09A8ULL, 0x4F2D924C1D585911ULL, 
            0x9DA0027C764DE8C2ULL, 0xA121F2CFB512E1A5ULL, 0xFD30C2F035F33DEFULL, 0xF5B8B231EF18224BULL, 
            0xDE5A608ED94A0D01ULL, 0x1362655F4EF59BF2ULL, 0x6109584D414F6F77ULL, 0x73CBB04D6B34D4C8ULL
        },
        {
            0x7C90B8FA3B6716B5ULL, 0x2BF77828E34B0EBBULL, 0xA331C4FB0AF8D8CEULL, 0x7128E7A185F1ACE1ULL, 
            0x2B64E9132A1675C6ULL, 0x7A5AA4DE79A1F51AULL, 0x2AE197380AD5F194ULL, 0xFB095C388091BA05ULL, 
            0x9EE1FCA4A422DE4FULL, 0xC89E470D7CA4CEF1ULL, 0x699A35182E049D0DULL, 0x5EC0CF590CD476B5ULL, 
            0xB2A72494CD93AF7DULL, 0xA235CBED2E69D5E4ULL, 0x63593F1198E7E71FULL, 0xD313782BA68D01D3ULL, 
            0xE50CA5DDA20B053FULL, 0xDD562746CF72E7BCULL, 0xE7CE79CC07AEF81BULL, 0x2DE067D9DF840F20ULL, 
            0x0A28088FF21FA909ULL, 0xABD42D602469E037ULL, 0x03CDDC7F59887BF2ULL, 0x028851F1044FD981ULL, 
            0xE87DB7ECA2AFC4FCULL, 0x2E5E928EFE2638E4ULL, 0x50861A6D6C958FB8ULL, 0xFA372222843E1CFBULL, 
            0xFB0E01A4D3B142E0ULL, 0xCE937F58DA3E25F5ULL, 0x78BA84D9A7761F20ULL, 0xFAEF4803476A113EULL
        },
        {
            0xEF7C2FBB3AC7536AULL, 0xD7EB6834BEE25230ULL, 0x31B65A31268B8F0DULL, 0x091C8C76057A162AULL, 
            0x846D8C310976FF17ULL, 0x9CFC708C57F0F86CULL, 0x215A786794E4546EULL, 0x76A0F6C4E8C33D4AULL, 
            0xEBEE029E1660A61CULL, 0x8B090C2A884D1332ULL, 0x6AF2BCC56C57A4CEULL, 0x3C3F4B04A753B458ULL, 
            0x6FACD27124AAB37FULL, 0x6584B171855A1D92ULL, 0x93E4F3FDF56CE276ULL, 0x4D63675368D1D720ULL, 
            0x594DB8CA23079311ULL, 0xADE33C7C64DB3E55ULL, 0x456A814F46858004ULL, 0x9F11A29FA80BB3ABULL, 
            0x5779CEB393436C30ULL, 0x7637394DD603C9A6ULL, 0xEEB457262D2DC457ULL, 0x352CACAAD5033B69ULL, 
            0xBA0ABA6FF42E6356ULL, 0x13F737CC2B3666B9ULL, 0x84668DDCEFF413D0ULL, 0x793F0F4E5F032873ULL, 
            0xE9836CEB5DABD7ADULL, 0x498ACC057C76235EULL, 0x5EFE2C0015A34E65ULL, 0x13499FA9B10ABC63ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alkaid::kPhaseAConstants = {
    0x8013A2922058DF5EULL,
    0x725131BE01D8108DULL,
    0xAFAE8778094D87B1ULL,
    0x8013A2922058DF5EULL,
    0x725131BE01D8108DULL,
    0xAFAE8778094D87B1ULL,
    0xF48167C26C2F34CAULL,
    0x3739F84431B04889ULL,
    0x51,
    0x4C,
    0x68,
    0xCF,
    0xC9,
    0xB6,
    0x67,
    0x9F
};

const TwistDomainSaltSet TwistExpander_Alkaid::kPhaseBSalts = {
    {
        {
            0xCE3F5AF34155A447ULL, 0x618659FE38D50448ULL, 0x8EE3924B51B78AB4ULL, 0x6BA5AF47875999EFULL, 
            0x10CE152D43562684ULL, 0x9DAA761F95AC40E0ULL, 0xEB05547362AB3768ULL, 0x1CB404E1D2101A1DULL, 
            0x2EEDB7858126FBE7ULL, 0x579B958AFCE0D719ULL, 0x92C01FE77AB00B08ULL, 0x4CB6C98B6943EAC8ULL, 
            0xF6BFCFCACBDBE0E2ULL, 0xE850D20A094906D1ULL, 0xA180FA67DBB7CCB2ULL, 0x95423A12D2E3AC45ULL, 
            0x24B25050BD9328FAULL, 0x80762912BFF62990ULL, 0xC8316F0B6EBC5218ULL, 0xF9E3ADFFD082E985ULL, 
            0xD768AE11277C791BULL, 0x1D3F5515D9E4C2C9ULL, 0x3E524F88A4EF7842ULL, 0x16875818AB92FC32ULL, 
            0x1764D6726B32EFBCULL, 0xCDD2F1ABAE23B59CULL, 0xC22F603156F70CCAULL, 0x4876A5F48F1F8B30ULL, 
            0x56AB1201B1D4150EULL, 0x4C7E7CF9A0E10FCAULL, 0x37BEBC211CEAFD23ULL, 0x123CB11A1251B855ULL
        },
        {
            0xEA2F14710C609868ULL, 0x566FFD9FD2F2EB05ULL, 0x42212A12C8A2887FULL, 0xA19FEE6E0313F81EULL, 
            0x87DC9A8C08764A3CULL, 0x8CD027C454D990A8ULL, 0x4DE77A6998CC871BULL, 0xC6B2D1BEE4E78266ULL, 
            0x1F912E849868C8E1ULL, 0xC919BF67E626C642ULL, 0x4411F174561ADCD0ULL, 0x04EDDC1EDA9AF2B1ULL, 
            0x71954594F4927F73ULL, 0x850D75398F4541F1ULL, 0x88BE9022B1FFCD34ULL, 0x51DAF42E182FCF09ULL, 
            0x40A73A7A44BB55B4ULL, 0x5677BA32BA1DBE6EULL, 0xDDFCA9EB39277B32ULL, 0x19394B3DF97F8BD5ULL, 
            0xBB8BAE4AE35B3F72ULL, 0x389DF16B577C03B2ULL, 0x71B42DF1D8ADC990ULL, 0x85667B67ADEC197EULL, 
            0xC65F7E6002621071ULL, 0x79EDDE6E4293E56EULL, 0x3631F8EBC6262CD9ULL, 0x4413A05C75C57A0CULL, 
            0x5FF6BD137A6E9F99ULL, 0x450F778825F889CCULL, 0x213093232D42A8E6ULL, 0x4F22098A709E2DAFULL
        },
        {
            0x152351437BC64088ULL, 0x54111387E476BC5DULL, 0x0A01574CDB0487AFULL, 0x871F90ABE9F59FA5ULL, 
            0x3F5E5E3BDC815AD4ULL, 0x19A8D9B266A19130ULL, 0x5F86DB4F55F3A972ULL, 0x369D1C70359CCD93ULL, 
            0x5F72DB3D3CE05143ULL, 0x3F1BCE73B9C69807ULL, 0x8DF0B86909CBA798ULL, 0x0DC2E518CF84C9F7ULL, 
            0xF9A4CB51FE5FDB7FULL, 0xF03BB1CDC9548C10ULL, 0x6DB3B091ED13DC9AULL, 0x3F42C877C1413716ULL, 
            0x5D70F83EB4D2DE6CULL, 0xF74F64550EB12A7EULL, 0x2A7870ECDFAFB9CFULL, 0xC333B4DF366BB26CULL, 
            0x8A16EF9D0546DB4BULL, 0x55586C8074C0755DULL, 0xD0F2E08A5199917DULL, 0xA7503EA949A070A9ULL, 
            0xB145131BFDF6EF1CULL, 0x9929C63E89C346B0ULL, 0x40972E532E6CBF7AULL, 0xD05FC0ABD19D4B65ULL, 
            0x46CE8D76C60BFCBAULL, 0x6808522AD585E2CAULL, 0x374053860B8629B3ULL, 0x0784CD7FD3946F27ULL
        },
        {
            0x856E60853323298CULL, 0xBFFE4EB605B65370ULL, 0xF19A9471147C24EAULL, 0xA44090E02D4C4A93ULL, 
            0xE3010AF434A48F5AULL, 0xF41A6BE22A023FABULL, 0xF17CD4AF63ACF52BULL, 0x2328208708386BD8ULL, 
            0x4D7EDB70FE1FAADCULL, 0xFF72F1FFAD4F32D3ULL, 0x8A22B7B331EA82AFULL, 0x1CFD63D1E7A60B86ULL, 
            0x2C62629E6FA7F021ULL, 0x16815E22AAA32EFDULL, 0xB790E05A881AA507ULL, 0xFCCCCA818F2875A2ULL, 
            0x0132271A87F597C0ULL, 0xEE23866A42BA56A1ULL, 0xFF5420B8A1ABDEDCULL, 0xF0DECAAFA3203FA5ULL, 
            0xBEFAD7926B0F17DBULL, 0xE1E0152B0D87D279ULL, 0xDDEC1F0437E50BF4ULL, 0x4FA816334C64ED63ULL, 
            0x11CC15FD73CE059DULL, 0x9FED94887965DFD9ULL, 0xBA4445604FF596AAULL, 0x5A2B5671C1F751FBULL, 
            0x714F4C89EA83271CULL, 0xFD2B0E16B539FB59ULL, 0xECEE14D245C40FABULL, 0x66E9B1F1F3333F10ULL
        },
        {
            0x720B08EC59FC60C2ULL, 0x7D0F315A884BD596ULL, 0x57B4214564CD0FDEULL, 0x99B1BF6E49233935ULL, 
            0x8ECE2DE9E8EAD78BULL, 0xA7C70BC36FEB8BC9ULL, 0x8D41C92BCFDD9B94ULL, 0xE094790AE3EFF007ULL, 
            0xF982F3C9D7D7F61CULL, 0x88CE45E4B2876CEBULL, 0x4E02573A0B1C7D72ULL, 0xE8F5B059FC628803ULL, 
            0x840E137456DADB9FULL, 0xEF1CF3AF3B5970C6ULL, 0x008BC2BA39A2D32EULL, 0xF2D80BD0E3B59470ULL, 
            0xC54C72CA0753EB24ULL, 0x1B0BAA269591BDF3ULL, 0x44E5BC42533A3171ULL, 0x8E5022DCF22EA047ULL, 
            0x4812C5B41DE5CFA8ULL, 0xD6BED613D0B96FB5ULL, 0x346C7E57FDF58E2CULL, 0x040AB81CF913EC33ULL, 
            0x6DC5ACEE1ACEC363ULL, 0x14A77A101A898F06ULL, 0xD013DCFD7CEA422AULL, 0xC99D81C4AFD4EDAEULL, 
            0x98F39CB72E16895DULL, 0x97745BD6B806A380ULL, 0x2EA14D613CBFC088ULL, 0x8B4A55119FB9CA11ULL
        },
        {
            0x2B8E008E4808C7D0ULL, 0x50FCB287DAC0CB44ULL, 0xCC2C7DE857C16C63ULL, 0x86D7F970EFCA8723ULL, 
            0xABE4A01BAA1B180EULL, 0x7C807C8150FD1817ULL, 0xBE61886BB6D64EB9ULL, 0x42D75133B6A79AACULL, 
            0x22C89DB6D8468E20ULL, 0x1D3A80E776E2569CULL, 0x09D0FF7EDC2B1A4FULL, 0x9CF1FE7D876C6C43ULL, 
            0x14D2417C19073DC2ULL, 0xD52AB84EE5FCF187ULL, 0x0CD275BEE578CFC0ULL, 0xEE1A984640F84274ULL, 
            0x6DEC74759C5A641FULL, 0xE4657E4838CD7B40ULL, 0xA14BFB46B3C4DC54ULL, 0x0F899D380C034BDEULL, 
            0x6F150A3A502CFB5FULL, 0xD9966E4DAB3346B0ULL, 0x0497C636EF12C0F1ULL, 0x4E337B29BB319FABULL, 
            0x352F49C4D2A4B0FEULL, 0x3E51434C07E40B65ULL, 0x80FFF4BEE718EC08ULL, 0x2D8811995D7E3474ULL, 
            0x705A23C8A9FC4A81ULL, 0x8F68AE4574152081ULL, 0x0D10E6DC037ABDA1ULL, 0x1CC1DDD4C039C805ULL
        }
    },
    {
        {
            0x2C00E3B5FEE55C7EULL, 0x412665CF6EDE2077ULL, 0xE2C46107A09C6794ULL, 0xA323D73682DC2CD4ULL, 
            0xF2D195431D094C24ULL, 0xA3FE99511683AD1FULL, 0x84F22457DE225657ULL, 0x46409B3B75BE2E28ULL, 
            0xBF5F051C2F1E39BEULL, 0x7421BECECF3762EDULL, 0xFEA72A979ED5B0CBULL, 0x7BD9B854A2A30EFBULL, 
            0x479F81FBAD7B17B7ULL, 0x5ADC136895688050ULL, 0xC39A82317D959A81ULL, 0x6DC5D4367A3DE695ULL, 
            0xB05DA6BBD38A8419ULL, 0x73C53447A3F84F9DULL, 0x361F8184AEDD32A0ULL, 0x7C84DB095DBFB753ULL, 
            0x6025DC34283C8CD9ULL, 0xB710E6CA2D82BB4EULL, 0x575FB997012D26CBULL, 0x9006791ABFF1944EULL, 
            0x48156C9E29E94070ULL, 0xFCECDC6107C55B56ULL, 0xEC1A6B4726BBF857ULL, 0x2D8F6433A73912F5ULL, 
            0x14F979DE956BEE37ULL, 0xB4CE06D1B32745ECULL, 0x93B6F69EA7058B36ULL, 0x263AF823A2D10ED2ULL
        },
        {
            0x5E30AAECC77E7953ULL, 0x209E1F19F0713FCDULL, 0x4843CE08FC90F790ULL, 0xB4CB2175C528C8A8ULL, 
            0xD7D7A77CF3DAD325ULL, 0xEAB02AB954A66369ULL, 0x04E7854E2865DD62ULL, 0xD22400D4E1847321ULL, 
            0x96731BA8F1D587C1ULL, 0x4171F4B5CA220E54ULL, 0xF5BC28D42C6FB743ULL, 0x01D7212C0013EF48ULL, 
            0x5AB0B7D9EC258ECBULL, 0xEF5B65CADB33A8FDULL, 0x51D874AC91AE0CF9ULL, 0xFE8A9B21BED2779FULL, 
            0x365268DA87EE8D8DULL, 0xE8D396F9286FB341ULL, 0x5C22BB48166C31B6ULL, 0x0B9F5AF4E9010CE6ULL, 
            0x00CBBD330EE4800BULL, 0x5E485C7D904ACA9CULL, 0x6C75567020C8B35EULL, 0xD779D7EC0BDEDF88ULL, 
            0xA686E45A9C863CD5ULL, 0x5BE1596B19431F72ULL, 0xF85A18408170F08BULL, 0x3E199DF316B4FD38ULL, 
            0xB819E636D61DEF85ULL, 0x77F1FF7B6B2303DFULL, 0xAC6A851A18A3A270ULL, 0xC4F519156D7FFCEFULL
        },
        {
            0xE489C4CC0FF7549BULL, 0x8DD8C17AF51F0AA9ULL, 0xCAD7BFC7D281EA52ULL, 0xB9B0E04A02F4B659ULL, 
            0xA08934CCD3DE98F9ULL, 0x713333F388B55A0DULL, 0x449AE349949B67C6ULL, 0x5049B3597757EEBAULL, 
            0x3DBCC53D5FA5B5B0ULL, 0x4D0ABCB74CC5E86FULL, 0xB9ED25489EC6E6A8ULL, 0x6B11ABB6076481E0ULL, 
            0xE80F7D27B52B84C8ULL, 0x95A20160F6BF504FULL, 0xC14C9956DA1C0F9BULL, 0x3CF741FE8ED41714ULL, 
            0x78B60C4093026F8EULL, 0xF7777A24D7027231ULL, 0x2C6466415DB953B3ULL, 0x5C519E6FAA291973ULL, 
            0x2DF5D0D8423DB178ULL, 0x2CB2ED08297CD099ULL, 0xAD15C281E313CA69ULL, 0x7B1FBC16B5E16651ULL, 
            0x322D48281FD53D58ULL, 0x94BA4BB30ADF1402ULL, 0xAC5BC62988C44D9FULL, 0x4B13CB644EDAD52DULL, 
            0x8C5B3FA0AEA47C35ULL, 0xAC4FDD985F9F95B2ULL, 0x5F833CC807EDD476ULL, 0x11FD05F3C076D121ULL
        },
        {
            0x6E3E409FAA627E34ULL, 0x5A16B98BC5C0AE03ULL, 0xB0C37D9F8E6A147EULL, 0x3E79B45CD7DADD35ULL, 
            0x0A3504C9EB1A3A9AULL, 0xE7B02834182E313AULL, 0x390F0E554E12149AULL, 0xFD52BC66E4AC7459ULL, 
            0x08583813653A73CDULL, 0xE86AEE3E3FF87169ULL, 0x87FA955DF83CDCADULL, 0x89B836C5EF32C4FFULL, 
            0xD0179D059C0F8CF7ULL, 0x56BCFD3B743C3813ULL, 0xEB851804E99F0D95ULL, 0xCE490CD1C2C14A24ULL, 
            0x3C3CC4CFC54A3785ULL, 0x088C1FA59519284EULL, 0xD844121BA3171944ULL, 0xC6D2E49B0AF23738ULL, 
            0x11169577B1B1676CULL, 0x512E584FED93734CULL, 0x460533F58E72D3F7ULL, 0xB960B51D0B47289FULL, 
            0x01E84D144B70631AULL, 0x54230BCFFEB1C1BBULL, 0xD9E557DD0C67DCCEULL, 0xE4B9614B5028CB38ULL, 
            0xC0D2A4B8F098B12AULL, 0xEFA8FFC5AA403ED3ULL, 0xEA69D3467993DA9DULL, 0xA377BEECA38F319BULL
        },
        {
            0x1DE7B7113D7A44B0ULL, 0xCFAB004B0EFCAF97ULL, 0xA93B1AE9AAC529D7ULL, 0xD61B320094DF319FULL, 
            0xAEF9E9EA8CFEE5A9ULL, 0x2B6E1297485C54D6ULL, 0xFC52E5C04AD0FFE6ULL, 0xC7464E3A9ECA9941ULL, 
            0x70F8689DFC11FC05ULL, 0x2F8AE8C709013837ULL, 0xE57656B7F44BCE2EULL, 0xA49F1956D85732E0ULL, 
            0x1DAA8845877C185AULL, 0xF1D16D0FCB27BD3FULL, 0x2ADF1155902F077DULL, 0x62CAADF288DABCD8ULL, 
            0xF788CBAF12A9B16CULL, 0xC287720DA47A8700ULL, 0x76E6A6A149FA3D21ULL, 0x48F15B70E2F7E811ULL, 
            0xC743FB1C7F5B3914ULL, 0x0C5D274D5B082084ULL, 0x9F0E201CAB9DA0BBULL, 0xBF2BDF6118D43DD0ULL, 
            0x799225932DF94712ULL, 0xD3E37A0A115E5729ULL, 0x331CC116D3EED0A4ULL, 0x8B4D621C1DC3597FULL, 
            0xDBBDBF1D9B6E371FULL, 0xAA3765701DAC0D4BULL, 0x86934C228D1BA548ULL, 0x151B261450D65C43ULL
        },
        {
            0x1C64719EC4F2DE5FULL, 0xD5F4725DA9EB6D93ULL, 0x1191FA661E479B8BULL, 0x634E5DE7FF3DAE6BULL, 
            0x164A77A8B00AE97AULL, 0x45A3E65F80CF930EULL, 0x826E0FD969830671ULL, 0x862CFEDFC3579DF4ULL, 
            0x85D0F085EB761193ULL, 0x85ABC9C50615C9C6ULL, 0xD0D929F16CC4F98EULL, 0x74323373FCAD20BCULL, 
            0xB38810F72879EEAFULL, 0x1409C5F6A36F03B1ULL, 0xF914987FC658E4BEULL, 0x3196D71E74AEDDA2ULL, 
            0x8DC127461EE5E79BULL, 0xE529131EAFB67795ULL, 0x42F2F24C447A5C07ULL, 0x2ACE70450AB8E4FFULL, 
            0xF340F1EC8DC27A0AULL, 0x1F5760D1F7108A61ULL, 0xC1503C28B64884C7ULL, 0x3D0A275147913109ULL, 
            0x4A2E0D409BA8CA21ULL, 0x0962A32A1B703BB2ULL, 0x485336CE6312DF78ULL, 0xD29827A7EEA32840ULL, 
            0x2EAB9388F83903DDULL, 0xA603CF30D1E04C65ULL, 0xA3F891216AE86EB8ULL, 0x7C58374D5AD22DC4ULL
        }
    },
    {
        {
            0x62023C6A6AAF01B8ULL, 0x3F3ED1A0A20CEDAEULL, 0xE7B953625C0CB0D8ULL, 0x1727843A024B9866ULL, 
            0xB69B9C8A02160E55ULL, 0x2A907898F5422A4CULL, 0x92C7B9BD8ACECA39ULL, 0x237050DCE5E7016AULL, 
            0x3BCE22B370904E15ULL, 0x0243FC2211636D1EULL, 0xC9FAE3ACA39CB7EFULL, 0x239A818502A1138CULL, 
            0xC4F3CC1F0F2F5761ULL, 0xFF92F6E841084656ULL, 0xB4CDD89E2C7ACD9EULL, 0x8268817587D5EDE6ULL, 
            0x88CC9917503C2EA9ULL, 0xF11AE0E49B7370BEULL, 0xB34BFC35D4F8F63EULL, 0x0E368BAFDE6A0A54ULL, 
            0x312BC2EEE7E0AC27ULL, 0xB439BDDDB681DED6ULL, 0xF631E0613C6AD9EFULL, 0x85C2B6E86A09A0BAULL, 
            0x4303D6513CA845A9ULL, 0x08E0FD407DA638E5ULL, 0x4DCF990C09740B01ULL, 0xC59F227F11842EDDULL, 
            0x385041F656B98A54ULL, 0xE123DEB32EA38D13ULL, 0x8C53C318A9654F73ULL, 0x2AF0B8EBF6ABEF77ULL
        },
        {
            0x2A6762E3C0F93DFBULL, 0xE45ACF30DA585875ULL, 0x533169253A9B423AULL, 0x9E2C76018B5DC539ULL, 
            0xFBB14A0C0A9ABFB6ULL, 0x45254EEE7F70A53CULL, 0x0717BDC3D45DCF4DULL, 0xD719A5228D46FEBFULL, 
            0xD15045600DBDB367ULL, 0x2EE76BA29E554D00ULL, 0x909F783262141ED4ULL, 0xE0CD2F8FEF7DDF9CULL, 
            0x3C79BB05CFDD7F0CULL, 0x7C6638066FF3B34EULL, 0xE4DA84EBF358871DULL, 0x691F661D49C203B8ULL, 
            0x74A8A5BE1ECCE6E3ULL, 0x9B017641356BAEE1ULL, 0xB46DA648D3559D83ULL, 0xE669B08D7821D470ULL, 
            0xE88DF8FB4C01A917ULL, 0x5A2ED593995499A4ULL, 0x5A8B6B4050BFA460ULL, 0x6B7AAE898B3095C5ULL, 
            0xB7857EA373E08919ULL, 0x09EDFBE30E26805BULL, 0x6697A5772F7D9027ULL, 0x3E7FBDF1A64FCF05ULL, 
            0x75485003A52653F4ULL, 0xD97DE63285D81D12ULL, 0xCA4FA2FD97ECB4F1ULL, 0x6BD1B6151FAD4991ULL
        },
        {
            0x01C53A970BA56E26ULL, 0x3803D7A7F567DF0DULL, 0x4016BCD4D04B8A93ULL, 0xB78D2D0201EBECF6ULL, 
            0x9D20D96FE064A6E7ULL, 0xA0D3A6A251CB1697ULL, 0x539E63160DC38109ULL, 0x60A5C436D1C06302ULL, 
            0x0967FF50B75094EAULL, 0x8F82A4E81C44EA88ULL, 0xE101222737FB24ABULL, 0x72FAFEDE8D30E987ULL, 
            0x7060A4C23A2BDA92ULL, 0x4FCBECD28CA60224ULL, 0xB24708322624EE98ULL, 0x920E8395F03F5BEDULL, 
            0xB831AFA5CFDDA9BFULL, 0xFB44631CDC671AB0ULL, 0x8987BC463656CC16ULL, 0xBFECF08CC8A39877ULL, 
            0x7D2795602C2009D6ULL, 0xFA5B78EA820B464FULL, 0x7C973A051944F13DULL, 0x5A3A056B5F054C16ULL, 
            0x2A5BA86E51D0FB05ULL, 0x9ECF703E90431965ULL, 0x8B9861948FC5BF53ULL, 0xFA0CEBD6848D6637ULL, 
            0x2874318022DA2B99ULL, 0x23FD16DEF4F03B91ULL, 0x502AD65FBD5BEE19ULL, 0xF380CEEC25B3643DULL
        },
        {
            0xC77F5D796F17AC00ULL, 0xBF1E44FF123F6316ULL, 0x6955139C273B6EECULL, 0xAB906FC310ADDB7CULL, 
            0x6F0E382F1EE7C002ULL, 0x7C402126E7DBAE62ULL, 0x937C0BB4265E4713ULL, 0x2DDF79CC94379B24ULL, 
            0xA10AFD4443D3FF7BULL, 0x2611EC497636B5DCULL, 0x344AABEEA5550AF1ULL, 0x435EA12A19EC6F01ULL, 
            0x3C5ABD8962A3F455ULL, 0x0EE6E43D52D59AD9ULL, 0x18C2D813311CE8B6ULL, 0xE841F35705CEEFF9ULL, 
            0x10D19543ECE62723ULL, 0xF0AB1F1E5EB21DB5ULL, 0xECAC590168D82221ULL, 0x0ED3575073D25EC6ULL, 
            0xE831690AF8BE15F1ULL, 0x4CA8B1CF7D88ED4DULL, 0x39477DBEFC7821CBULL, 0x8811CCB16B6D2083ULL, 
            0xF99CD33A88387464ULL, 0xEB8159D70E2BCEA2ULL, 0x0E4D82202B74690FULL, 0x4C8E25D7855F518DULL, 
            0x7538D5000353B458ULL, 0x7E458C80624F9779ULL, 0x301CDC3F65C5A5F1ULL, 0x0A676B5E793AA53DULL
        },
        {
            0xBFE1C3796B7814B6ULL, 0x1C4A0BB8312819B3ULL, 0x806A805C9AFB8CC5ULL, 0xC89B79CD63CC2776ULL, 
            0x9C77FE6CFB6E0DB0ULL, 0x15EEB9A1A01BA6EAULL, 0xF715C05478620B77ULL, 0x10883CBBBEDA62F0ULL, 
            0x312ED4E847455C77ULL, 0x51F9A1426288A3E8ULL, 0x73FF308BB8764EF0ULL, 0xD841B164354B6859ULL, 
            0x49C62CB58189FAAEULL, 0xCB006B53EE1A0F0DULL, 0x02AC75E12C9BC126ULL, 0x7EA2F7E504F25CD1ULL, 
            0x8DFCD226F57B77BBULL, 0x93278859089CCC6BULL, 0xBFAB1A0437C3E287ULL, 0xE42BC992777A9EFFULL, 
            0xA00BAF4B3934E3E4ULL, 0x6269F8D9F9FBABECULL, 0x3963E22CCABDFB44ULL, 0x5AA79EEF1C25F70FULL, 
            0xD58C205132FC6405ULL, 0x1A13B3ABA8CA25B1ULL, 0x39113C3E210438D4ULL, 0x4A48E116DE71C284ULL, 
            0x48F0ED50A27083C3ULL, 0xADF6E810E5242F73ULL, 0xF93F963A09B68FE1ULL, 0xB3C0757168416471ULL
        },
        {
            0xA705815905ADF85FULL, 0xB98B76D058E14611ULL, 0x4194B3B8D2C7AC18ULL, 0x1541DEB36612AC2DULL, 
            0xBBDA3DE30B914B66ULL, 0x195D8B1C74CE6217ULL, 0x95E300112733D773ULL, 0xB05FC93B1E82AF05ULL, 
            0x82A87BF0C21E11E8ULL, 0xBD4E2C07E48F4BD2ULL, 0x514225E6BE6E36F7ULL, 0xA03492EA5DE1301CULL, 
            0xEE1EE51CBBEE460AULL, 0x2B07F6030796090BULL, 0xD2FE82E9F98650BDULL, 0xBE58B6F76F70AF96ULL, 
            0x00E140937764813FULL, 0xA7ED1CC80479ADDEULL, 0x96187CA302C1A8C6ULL, 0x184C7B79BD87927FULL, 
            0x3C5C34BB1CA6063EULL, 0x8DA209E29A12B4F4ULL, 0xCE037AEF2176465CULL, 0x6B817B7302D94AABULL, 
            0xE6AD58B13BCA1635ULL, 0xA6851F4E775EF9DEULL, 0xA7B3B27062F08B4AULL, 0x5D7A1999C0207DA4ULL, 
            0x1235EAA20981154CULL, 0x9533C0BE4CA3B5FEULL, 0x546797F7F9991226ULL, 0xCD1A8EFC82823472ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alkaid::kPhaseBConstants = {
    0xBC8786B25354B6DEULL,
    0x63747DE550D59692ULL,
    0xF17C037BD0A6FA80ULL,
    0xBC8786B25354B6DEULL,
    0x63747DE550D59692ULL,
    0xF17C037BD0A6FA80ULL,
    0x64368D481BFC1A00ULL,
    0xEC8E1BCC17533908ULL,
    0x7C,
    0xC8,
    0xCE,
    0x38,
    0xF2,
    0x0E,
    0x63,
    0xD2
};

const TwistDomainSaltSet TwistExpander_Alkaid::kPhaseCSalts = {
    {
        {
            0x4877BDE5966DE278ULL, 0xF40C3663D7EE63DBULL, 0xA21629D7FB9150CEULL, 0x9EAF64F1AFD274DEULL, 
            0xFBFF457DAA2AE56CULL, 0x3DFDFF3EB2952B96ULL, 0xECB7A3DE06202B95ULL, 0x1C6C41B2EBE9F0C5ULL, 
            0xD57A6C5DE92C88FCULL, 0x1D0DB909E29D46DFULL, 0xB71B641318DCB911ULL, 0x33D7D1BF7875D85BULL, 
            0x29F2178DC66E65F8ULL, 0xB105F14D5CEC3E32ULL, 0xCD3DCB9CD53941B7ULL, 0x52F2E563AC7D5338ULL, 
            0x4BC5D206C874E1A8ULL, 0xFA0305998129655FULL, 0x1CAD88E561E047DBULL, 0x80C0D54DEED17FD2ULL, 
            0x0F9BDC06F502F212ULL, 0x9C21F2DB4B94FEBEULL, 0x4664E7EF7051D6CBULL, 0x876315AC19165A8DULL, 
            0x03FEC17914C1A52FULL, 0xE916CEB34E059289ULL, 0xBE3CAC984E3428E3ULL, 0x0407676C92E3ADE0ULL, 
            0x7AA1026337F7BA6DULL, 0x5ED813D6E97E6600ULL, 0xF2037B941CB0CDD1ULL, 0x6D8341BFFAB0AC17ULL
        },
        {
            0x3D4EC8466352180BULL, 0x8383E3460253E3A9ULL, 0x31C4DFA93CDAC718ULL, 0xC99FD4853705AECCULL, 
            0xECD8E0B652D61DE2ULL, 0xBBE3DA4C46335273ULL, 0x502600DDA6D59E60ULL, 0x5B034DE53DC3AA83ULL, 
            0x25C8E57CF794FD0AULL, 0x1BAEB0AE45F333D3ULL, 0x18AEED25CB32B91FULL, 0xCC16D34D1A8A8193ULL, 
            0x352CC0C629B5BDC1ULL, 0x8033B08250052B46ULL, 0xC445ECC6A3455F6CULL, 0x5EA364C6410D2770ULL, 
            0xDFB5A607C30F5447ULL, 0xEAA90D2215CAD829ULL, 0x73BD4C9CA8DEC9F5ULL, 0xBDE3F577487200F6ULL, 
            0x2FD9CC884C295B32ULL, 0xB661E9FC33816057ULL, 0x55EDA1F1893AE624ULL, 0x2135177722184FD0ULL, 
            0xB90BD49B2D5655F2ULL, 0x7498576DE2CADAA9ULL, 0x0C451C0945742265ULL, 0xAA0567FE38C500DEULL, 
            0x22BC2C60D4766113ULL, 0x4FBD9430DEA1AAA9ULL, 0xBFE07F7579B5AA91ULL, 0x8C4B79A95F5136A7ULL
        },
        {
            0xC8BD0AB30E5E319BULL, 0xE99E532650B70BF2ULL, 0xA4E1024A19D12C43ULL, 0x4C71EA7BD3FF379FULL, 
            0x1414BF03BA18DB25ULL, 0x1B01A299475793DFULL, 0x2AC3608BF8B8EB2AULL, 0xC87C44B356CE488CULL, 
            0xCF6C1CA1C568DA30ULL, 0xB0C69B6C10EEB41CULL, 0x42FBA871CA442213ULL, 0xCE79E408402025FEULL, 
            0x48DFF8A63F11F38FULL, 0x74F44956758E216EULL, 0x7623A9EE34D3D68CULL, 0x3C5BB0D8B8AE43A2ULL, 
            0x1789911156A8D03DULL, 0xD790E59E52442EDFULL, 0x234F0E38BE489994ULL, 0xF1239E9586658CE7ULL, 
            0x6E347FDAC42E74A2ULL, 0x4ABF7651812AFD33ULL, 0x10B081A46234C831ULL, 0x1DBEE65281CD01A7ULL, 
            0x53BF7C3714F99D5CULL, 0xAF854FD27D58C988ULL, 0x0E84CF90A3B45857ULL, 0xCDB0C7097641D293ULL, 
            0xD09FDFEA7530A920ULL, 0x1053E60F81302C35ULL, 0x7B11D11C1FCE892EULL, 0x0BF6312F31ACC30AULL
        },
        {
            0x4A4A283CA4432E52ULL, 0xA53B86A569AF55A5ULL, 0x90CCDA0328BE84D0ULL, 0x724BA7FFCE7850E0ULL, 
            0x073C9B25D1D41809ULL, 0x7FE7FA6E7821492AULL, 0xF5965BA8696D99B2ULL, 0x750D6045CFEF31F1ULL, 
            0x79C398388C0D1783ULL, 0xABC1C82830E16628ULL, 0xB4AAF73493AED27CULL, 0x8AA8D2476AF615D2ULL, 
            0x2F15FD9C652C49A4ULL, 0x6AA7468784A41F85ULL, 0x83618B29AD5669ABULL, 0x984F4A6855AFE6BBULL, 
            0xB33EE05534C167E7ULL, 0x4E8FE7C813E8FC18ULL, 0xACA8C5ACB071422BULL, 0x8AE3C0EC9706BD8DULL, 
            0x44B88B4BB3876CBEULL, 0x3090B5DC02BA2C14ULL, 0x5C7B9EB09DA881C4ULL, 0x7F166F4CDB98FB35ULL, 
            0xBF403235E10A2719ULL, 0xF14D62C4EFA4B30BULL, 0x3B3F66FF2E912737ULL, 0x6536B5362B27BEFEULL, 
            0xBE719EF6BB5E7D59ULL, 0x9EE67430D8E0C4F7ULL, 0x1A2BA5E47A7D759FULL, 0x0F9295C5235AA094ULL
        },
        {
            0x7E743ACB455DD05CULL, 0xE929DF08C946E023ULL, 0x68CED018E138C176ULL, 0xCEA934F4A6923E1EULL, 
            0xF246CAA2E888A33FULL, 0x4EEE2E45C6539257ULL, 0x8C8A6D9137C3E1DCULL, 0xFF9E41E507A975A6ULL, 
            0xFBD67D52E888BCADULL, 0xF1DD3C1E299C91C9ULL, 0xD7318A26062A36ECULL, 0x3D77E80B7189BC84ULL, 
            0x618CA18986FE840BULL, 0x0BBC61835D722F8DULL, 0xB1C8B52DBB88D9A3ULL, 0xB6AAE45E21933E3DULL, 
            0x80F698B24994FA2CULL, 0x331157E29A43D27FULL, 0xA4BFAF6C9952CA38ULL, 0xA45AD8529A378284ULL, 
            0x03978DE83D4DF0A4ULL, 0xE02C5126E96FFA78ULL, 0xFDE5E1E4A9E1B107ULL, 0x564A28B4CA435CCAULL, 
            0x9C8F2C7D8F956941ULL, 0xF513BF4FF9210CCAULL, 0xCD7DE8A2E5BB4CC2ULL, 0x653E10D1702037EBULL, 
            0xA6A85FF5791074BFULL, 0x18E037EE4929C15DULL, 0x7AF938B15AA6ACE3ULL, 0x5DE9777E3C8ED3E9ULL
        },
        {
            0xBF0F2E21D87AA3BDULL, 0x756608B8FAA8EAF4ULL, 0x3FF09F2499C4B0D5ULL, 0x48753A2691756908ULL, 
            0x0B924B4829D256C9ULL, 0x35F0494363DB017FULL, 0x30FE8848776A0229ULL, 0x489F9EE91F0CEF70ULL, 
            0x6F209F6E2C3191E1ULL, 0xAA1A01B80969B5AEULL, 0x4604E42BDF67AAA3ULL, 0x87B03C37879C123DULL, 
            0x4F67422386240912ULL, 0x01CC3A4C57B15F2FULL, 0x7C64C5254B4729F6ULL, 0x3522BD8EA0CDABDBULL, 
            0x00FF2AA81824BA5DULL, 0x42861326308DD1F3ULL, 0x25358B23E8CC797BULL, 0xEC3E397E1E801A7AULL, 
            0x7ED45A467A6EFE90ULL, 0x2A35AC16C1DD7EE9ULL, 0x217A6CAD28B39247ULL, 0xC0933499538263B6ULL, 
            0x2149C4190806423FULL, 0x03068629B87D7465ULL, 0x4D215CCF89C8E3FBULL, 0x0ABC402827C2FFB5ULL, 
            0xDECCDAF19297A1C6ULL, 0x316B8F552C93C486ULL, 0xB43FA76F3E6FC8F3ULL, 0x62FB4C3DDA137B80ULL
        }
    },
    {
        {
            0xA26BF0F660A571FCULL, 0xE3353CAB98713596ULL, 0x5B864FEDA939CA3FULL, 0x964AB2C1F032E120ULL, 
            0x0B1C8DCD5290F532ULL, 0xF7CA759875C8B747ULL, 0x2C0C3F9B5789393CULL, 0x4A4A6F03A2242B3FULL, 
            0xCF3174E68521DD5DULL, 0x8E54C641B6B25B2CULL, 0xAA2DDC4146250593ULL, 0x646C83F954175E0EULL, 
            0x20872545EC98126CULL, 0x88B2454A30D2D301ULL, 0x67E1EC56B4D8DD6AULL, 0x0591F0E04F0C69D6ULL, 
            0xEA518073EFBE0E06ULL, 0x07491A8878EEBBDDULL, 0x08B166A1CF14A8FCULL, 0x4243E85DDD465EF3ULL, 
            0xB0B24A8B013C1093ULL, 0x63CFA455404AE04FULL, 0xEBE3FE538C9A0487ULL, 0x9135EE3B52700C86ULL, 
            0xCF556A9CBCE3CE75ULL, 0xD05795AE3E44A30AULL, 0xADBA07D36A1B2483ULL, 0xDFED64BCB8C9152DULL, 
            0x0D4BFB4F1354E69BULL, 0xB039862FED7B8730ULL, 0x19F91BB0A07720A0ULL, 0x3391A71C8115DC8AULL
        },
        {
            0x7BB78A47EB141AC4ULL, 0x26E72D73C091AE65ULL, 0x0C2C0D92BE41BF37ULL, 0x3BB56FBA5A267727ULL, 
            0x6CCB29FBF13C7CEFULL, 0x1320003EC24E8DA8ULL, 0x1397A9D3CE5F82D9ULL, 0xE57D4C4B495915B3ULL, 
            0x8B873FDB175A9D01ULL, 0x93FEADB9CE20A263ULL, 0x642490FD8EBF8240ULL, 0x2AB36046427E7396ULL, 
            0xD6CB48063A74F910ULL, 0x0F29DD74C323DEF7ULL, 0xD80667C28839D8A9ULL, 0x910F5427251093D6ULL, 
            0x8A1D3A88772E0E28ULL, 0xDBCD1EADD31123F9ULL, 0xFD4EF26590772D75ULL, 0x42FD069FDBBE2EB0ULL, 
            0x6709C2102D55616FULL, 0x67176C77E77DFF54ULL, 0xEF56A48B43BBCDC2ULL, 0x9F85FBCA07315FF0ULL, 
            0xD840D7F40D903684ULL, 0x63C49B6A104457DCULL, 0xE3E94BE35FE4D70EULL, 0xC054DCB605A37E48ULL, 
            0x37B3CDDF62321FB1ULL, 0x9B09400E99D75708ULL, 0x918696FCAD7481ACULL, 0xFC43C6319FD2988FULL
        },
        {
            0xEDB86E336CEB4B8EULL, 0xC3C2B66205FF01F2ULL, 0xFACE11D876EB70EDULL, 0x10030267AB21F897ULL, 
            0xB651B90718559895ULL, 0xE46B7413FD2A2F63ULL, 0x77FB7E5ABAF675AAULL, 0x0D9DECF5C6567B90ULL, 
            0xB44C3A90E221827CULL, 0xC764D60DCA1DE53CULL, 0xC438D07CE01FA315ULL, 0x306106916695EE79ULL, 
            0xC71F2C6CD0397C9CULL, 0x498D83BA7A4CE0D0ULL, 0xAC494FB6128A7CEAULL, 0x2C0394722C9EFBD3ULL, 
            0x1EE0F1D5FDC6C270ULL, 0x79C4722559E7F1EBULL, 0x85063B50E5C3BD57ULL, 0x6C9BC8BB31DD1D32ULL, 
            0xD7ABE33C0637A024ULL, 0xA11B36158EA665B6ULL, 0x16D1FD40032D300CULL, 0x56023D91616BEB65ULL, 
            0xAF425A46A8F80F75ULL, 0x1EDC38F66DAB9C83ULL, 0xBAA04854160DD90CULL, 0x00254F7D9BB6B0F6ULL, 
            0x26D094A3379E4C09ULL, 0x4383DBDEEAC05515ULL, 0x1BFE53368798D28BULL, 0x9A1AFB3735742F06ULL
        },
        {
            0xE6D254299B27ADC7ULL, 0xC8A4590CA5F3D4B7ULL, 0x1EE756BD0441F004ULL, 0x7DCD774238DED50DULL, 
            0xE9037F23F224E368ULL, 0xD08EBFB3EEEC764DULL, 0x332CAB82DCE52898ULL, 0x5EB7C45E0CC23B49ULL, 
            0x467DA899164ED612ULL, 0xDAA5B440BD75D87AULL, 0x382C0E1EA1FACB4EULL, 0xDBA99A8935B320FEULL, 
            0x3755A26EBCE9EBE7ULL, 0xD2196D071E663F60ULL, 0xDA610E68B0C29D22ULL, 0xF43C7F3528AD705FULL, 
            0xF009657ADF98B5ABULL, 0x9F39ACBDE0950D7EULL, 0xAF55F82ADFCF3F4BULL, 0x333F9A5CBD59FC3CULL, 
            0x029E4771F5116DBCULL, 0x8193FB730AC8356EULL, 0xDA71762210383DB9ULL, 0x1C15C1BED6E7CFF9ULL, 
            0x2CAE0C99F9796938ULL, 0x76231AB0535DE87EULL, 0x47DE7ABA5035A77EULL, 0xC7E2AEC87FCAE7ACULL, 
            0x345037CBE7B9D524ULL, 0xD5D778942FA7D409ULL, 0x8B839F09BAED1517ULL, 0x7F6EF031488C320AULL
        },
        {
            0xC7E78C2003DB0101ULL, 0x17CA0CD0051B8ED1ULL, 0xBB883BD793DCEC7EULL, 0xBC84D83094378141ULL, 
            0x634F9BA219025DBFULL, 0x900FC5299DE09DCEULL, 0xD0EB22072B368255ULL, 0xE07C4ABAD5B526A3ULL, 
            0x8FFEA09BECCB6545ULL, 0x0C5938A62D596FDBULL, 0x0BBB98F0EBACD3B4ULL, 0x9545C45D5EE41BFDULL, 
            0x50A93CD2D5512858ULL, 0x4E9170BC04722388ULL, 0x6336A405CA63D928ULL, 0x8AAA303F511217C8ULL, 
            0x14648C611B86CEE7ULL, 0xB96DC4AEF9CD1128ULL, 0x7A939642537CAD6CULL, 0xDABE5CD637BEA4A4ULL, 
            0xCB6C5088C89484C6ULL, 0x80D3DF808F0FFD39ULL, 0xE7862B1326B6A1E4ULL, 0xD0C12AAABAF364BCULL, 
            0xDB38E9D0DB629019ULL, 0xFB3A893A541ADF88ULL, 0x36B33495F390C24DULL, 0x0122306A7D08AF4FULL, 
            0xECA9389F7FAA5692ULL, 0xC36E776FAA4344C2ULL, 0x3A95A1EE34F80D4DULL, 0x55C5863343B87DE3ULL
        },
        {
            0x55A94A334C5C412FULL, 0x40B1DF52C0D916AEULL, 0x14694AE5AECEDDFEULL, 0x8DD8E1121B5CA8DDULL, 
            0x714325AABE2558BFULL, 0x7057E95A6681F4F3ULL, 0x1ACA55D8678DD405ULL, 0x0470D7C1444E49C6ULL, 
            0x65B32183E5F45DC8ULL, 0x40FBA4F0639DF360ULL, 0x902257EDDC079F1FULL, 0xF27BADD7E89F474BULL, 
            0xBD5D595E0ABF02D7ULL, 0xBB3E6A2DAB393EE6ULL, 0xEADFD14C30EC26ADULL, 0x7A5B1B68B51959D6ULL, 
            0xDD6BEF280F126B56ULL, 0x3FB9163FD4A85243ULL, 0x50075455A3148E1FULL, 0xEB9796DA237ECE47ULL, 
            0x8971919BD4E6B125ULL, 0xA01E93CA5D98EE93ULL, 0x2B68E241BB8BE2CFULL, 0x383CF9060B6FB81FULL, 
            0xBA30796ACA623070ULL, 0xA18A90B30F884F09ULL, 0x7297CADD521A3476ULL, 0x378BA4295EF118AFULL, 
            0x3740CDD15CDBABD5ULL, 0xE98D19307C8C81E1ULL, 0xCE6FE448DA5CC4C8ULL, 0x3099C541A860809DULL
        }
    },
    {
        {
            0x5C37D412E8EBE94CULL, 0xC5E98A722B890E61ULL, 0x9E99C1B77BAAB092ULL, 0x5364BDBC9A1943F3ULL, 
            0x653B24C2ED53367EULL, 0x24F0CE0CDCBCB66FULL, 0xFAE9A73550A903B3ULL, 0xB3C36E721C1A509CULL, 
            0xFF3F5C5D9F77CA29ULL, 0x3BB55FCA17D39A8BULL, 0xB9BA5C91E5F51209ULL, 0xD1BC7D6548DB35AAULL, 
            0x8ED398CA919247E8ULL, 0x2EB50FF11C70E7F6ULL, 0x96454D3ACF663A03ULL, 0xCD8CFCEA88631124ULL, 
            0x97E265D76676E294ULL, 0x3AC0BE90C6F3C4AAULL, 0xB06572C7A0328C56ULL, 0xFE35B5C07129273CULL, 
            0x91D8A38B3231228AULL, 0xB9D55F39415DE5BCULL, 0x4844E7EDF426BF39ULL, 0x5319D4F0D67DA24AULL, 
            0x767A9E9FD56EDFF2ULL, 0x7213CD73D414A9C0ULL, 0x942AAA1520815F5EULL, 0x752CCEFEEA37632EULL, 
            0xD99F9223920A2993ULL, 0x9422C6509155E75EULL, 0x581F708E27A5357FULL, 0xC416DF4F61A2D5FBULL
        },
        {
            0xB33D993D8694D523ULL, 0xE07294DA93BB929CULL, 0x3F965005AAEA7233ULL, 0x5FC1AA24CDF94716ULL, 
            0x0E0C87ED20EDDA24ULL, 0x0AE56D39269619D2ULL, 0xB497A4E444AC8AD1ULL, 0x62674684534C6086ULL, 
            0x6543DFC7A92EF43EULL, 0x10C800409A97005DULL, 0x16ADC38DD2003594ULL, 0xAAA8496D88685FB6ULL, 
            0x4E621C54636E5FD3ULL, 0x519F1C1A1F5FC04EULL, 0x0E2B051999F8F2D1ULL, 0x4D6CCE117952C28FULL, 
            0x7246DAEC25E3F00BULL, 0x838639515CD29DA3ULL, 0x862204B99FBD5220ULL, 0x626820108688D64BULL, 
            0x86F9C014535D3805ULL, 0xA3F64966D360E00BULL, 0x49FCE94E50E631D8ULL, 0xC6ED9895FFB473F2ULL, 
            0x7E8F9E4216877B81ULL, 0x070497F5C7133364ULL, 0x04D678C49CD07DF0ULL, 0x2265B8957545E03DULL, 
            0xD31104982DEB140DULL, 0x813BC4AB28D02C79ULL, 0x8C9B6B35103F7CB1ULL, 0x2D017074A1CF3EFAULL
        },
        {
            0xC5A3B4F5E82C59D1ULL, 0xFFBC395742A9807FULL, 0xA269CDAB82115152ULL, 0x581D51E6B966F525ULL, 
            0x53D254E43E23978AULL, 0x032BF317643049B1ULL, 0xCFE5631FA18D2032ULL, 0x7D652842D5CA85F1ULL, 
            0xAC97FB67242130E7ULL, 0x5E44871AA4C58DF9ULL, 0xBAB250E5CAEE588FULL, 0xDED84CA8DE83F0ECULL, 
            0x29071C321D126C67ULL, 0x325E4AF4444EAD64ULL, 0x16B0DACF51873F0CULL, 0x83DC71507245FC58ULL, 
            0xF5CEECBB6AE0DE41ULL, 0x5E7278EF9DB6B79EULL, 0xD7D596B202E05A8DULL, 0xDF72774F93AEC731ULL, 
            0xE44EAD1E0D481098ULL, 0xA279DB441D68C336ULL, 0xB6069789A2BC16F7ULL, 0x3B261E3E27E1F0B6ULL, 
            0x4B696E09061517BCULL, 0x3C398620738B32E3ULL, 0xE339BD3EAE9EBA7CULL, 0xD7ADD6D29D88337DULL, 
            0x848815BA87B699F3ULL, 0x7CC97D0AD36C1A94ULL, 0x97B42F7A8505A8EDULL, 0x9F3D5B0D82BE8D6CULL
        },
        {
            0x4D3D8A7FDC3E7C59ULL, 0x04ACDC920B3B7C94ULL, 0x290CB9AF196DB699ULL, 0x7DDDDE54DB37EF5BULL, 
            0x4AE9525C97962993ULL, 0xF300E81B50B5629FULL, 0xD3D0176E3F2B4D00ULL, 0x6974B40C50BA5898ULL, 
            0x2B3BEFA71B001B84ULL, 0xA3F7788F099877DCULL, 0x4CC9DF95958E12DAULL, 0xAADF4980FFF5376CULL, 
            0x98B15B6FA99EB7FDULL, 0xFD40D94DD2B7991CULL, 0x764E1A0258B5645BULL, 0xD162FAF0098A672DULL, 
            0x064E74D022B04DDCULL, 0x7B003D95B9B8C7E2ULL, 0x8534892852942554ULL, 0x40046B0E7EED4857ULL, 
            0x74472AF294821A92ULL, 0x334432281C44849CULL, 0xE05791697C92ACB6ULL, 0x69CB779AA6614987ULL, 
            0xEC7C7E4511B49D0AULL, 0xD14927CD45D3B3C7ULL, 0x48BA0B9DA2DC3F28ULL, 0x3B9F5A88166C7983ULL, 
            0x51680A7457DFBFC2ULL, 0xED9605649A34C20DULL, 0xD4771B2741E7BB6DULL, 0x3183D859450164BBULL
        },
        {
            0xEECFC8DCCACA08EDULL, 0xA9B0A58A21A9F148ULL, 0x3B25C968DA43407AULL, 0x9392C93F32F94792ULL, 
            0x1B5A543FF62BCAB0ULL, 0x13C37F9416388329ULL, 0x7E051E257CFF3D90ULL, 0xC77CC53AA8CE3D9DULL, 
            0xEDF7BA47DE9F632DULL, 0x4D18BEE203A594E5ULL, 0x9BADEF9225EEEADDULL, 0x5598F4976D51327CULL, 
            0xF0F75B08528B5A1AULL, 0x99DDAD5A1094B653ULL, 0x4BFB025A43F7888EULL, 0x1B416964D9E9E2ACULL, 
            0xB4610705362946CFULL, 0xC41ED965C84D7570ULL, 0xF8FD4F5C46696EB4ULL, 0xD72C665E48D03D7DULL, 
            0xD6009EEE3A44F010ULL, 0xE65952C7FB083530ULL, 0x22EC9815376582EDULL, 0xB144DB785FF932C9ULL, 
            0xD1A464A40CB0092DULL, 0x4E6A2FD45E18ED0EULL, 0xB51AF1D16EE2BCDAULL, 0x67286FC40B3C6D72ULL, 
            0x2384752B3B361C49ULL, 0x97EC6DAA20632FC1ULL, 0xDF7592F2191A4850ULL, 0x4E8EE862DE72F134ULL
        },
        {
            0xD90C6BA1CF5BFF6BULL, 0x5E7DDC73218DC6CCULL, 0x3BE359E125738F10ULL, 0xB1968233027D439BULL, 
            0xCD8A664BEC102253ULL, 0x15893C6100EF07BAULL, 0x17C6B196DA7C9756ULL, 0x88BEF04E36DE7D3EULL, 
            0x8A145CD79A2F82ABULL, 0x112A5FCE3ABC3945ULL, 0x26D6671E8AC53C91ULL, 0xD0F4A06DA060703EULL, 
            0x95418FE7B2EAEFC3ULL, 0x6196E20A0F1694A8ULL, 0xEB3CD0D2245057E0ULL, 0x6AC32834580057C7ULL, 
            0x60ADF48FAC05B1D4ULL, 0x6783026FB2445220ULL, 0x4EA4A41F822959E1ULL, 0x17976F32C57CED12ULL, 
            0x916D974E55AB1D0BULL, 0x4D10A67C825A0DC3ULL, 0x145BA076B444BE03ULL, 0x575E1CD802D3055BULL, 
            0x64A4644764FC4DF0ULL, 0x1E453AC16ACC797CULL, 0xA2D8741EE22ABCE3ULL, 0xA4A5B14055811AA5ULL, 
            0x580641E5A60E2031ULL, 0x75EECC708002E7E3ULL, 0x2F839A5216280FCBULL, 0xECB2A28EB1C1B306ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alkaid::kPhaseCConstants = {
    0xEC29C79672AE9BAAULL,
    0xA04CB5AF8F0C6EB4ULL,
    0x640ECFBAB3D2994AULL,
    0xEC29C79672AE9BAAULL,
    0xA04CB5AF8F0C6EB4ULL,
    0x640ECFBAB3D2994AULL,
    0xEBD53B74E0CA2BF5ULL,
    0x1B8060D950A02938ULL,
    0xC3,
    0x5C,
    0x55,
    0xB5,
    0x87,
    0x25,
    0x0E,
    0x42
};

const TwistDomainSaltSet TwistExpander_Alkaid::kPhaseDSalts = {
    {
        {
            0xBAB651C75B630B82ULL, 0xF587F568FCE61C6AULL, 0x79BF6DC6E39D73D9ULL, 0xC512D28E2ABEBB3DULL, 
            0x3C7B7D62CF2E4BF7ULL, 0xAB8A2A1EC79EA789ULL, 0x9734E8B6616C7AF9ULL, 0x5346D188D168D5C5ULL, 
            0xBF4EC73D7797081EULL, 0x7C7BAC8DE8860739ULL, 0x308C923D70BE97F1ULL, 0xAC32211DCFE0B776ULL, 
            0x79336FD53DF9F118ULL, 0x77E7CACAE2663FACULL, 0xC961F6D4B1A2BFA5ULL, 0x713F80A6328BBE15ULL, 
            0x804F4489B1A29E74ULL, 0x05651BD2CCEF56B0ULL, 0xAD26E67ED261B9CCULL, 0xA3D24E18144AFC22ULL, 
            0x5D86DC30E9EC4A79ULL, 0x092D0C3E2260FC99ULL, 0x5F358D08EC768999ULL, 0x0D91A61173383995ULL, 
            0x945B221BE561F373ULL, 0x0417A748AE7B0976ULL, 0xB78ABDED493EFC14ULL, 0xF4D3BF0E37F11A8EULL, 
            0x285B686822332CECULL, 0xE4B562E14F6FBE39ULL, 0xC0AA0A98DB4BB7A1ULL, 0x9386A146097D4699ULL
        },
        {
            0x95A0A86A95AC84C1ULL, 0xEFB00F7833AD54B4ULL, 0x0A5C15E88919E9D4ULL, 0xB0587CA5172E2C7CULL, 
            0xD26019453099094EULL, 0x5A0CAA1F6257B4B0ULL, 0xABE21256C26BD515ULL, 0xF80309F963E5F5A2ULL, 
            0xB3B5A7C63F1805B2ULL, 0xE179FAD550AD1CDFULL, 0xF50E16075AC2FB2AULL, 0x9E40D800FA9849BFULL, 
            0xEF2229E2104DC42BULL, 0x31C9BE7207B57C77ULL, 0x69B1118ACDB5EAEEULL, 0xFBB30A8D58071145ULL, 
            0x1E33582008C2246EULL, 0xE459BE50378C9069ULL, 0x0C2C36013D9B9F43ULL, 0x3F99FA93C2E97D1BULL, 
            0x9512DF3F2A6A605BULL, 0xB3E9F4299231471AULL, 0xE21DC35A823642ACULL, 0x60BAFF13EFA80B00ULL, 
            0xAEC9D146559FE6FDULL, 0x28264304D5C3CC82ULL, 0xDB356E9850AF7394ULL, 0x6982A7FA8609B085ULL, 
            0xB423F2A82F6AF50BULL, 0xD9BB99832FF2AAF8ULL, 0xF99B5856614AD483ULL, 0x50559A1126199A8BULL
        },
        {
            0xBDE6D27493308DDAULL, 0xB0072DD9468060D8ULL, 0x262991697DBF7BD3ULL, 0xA8FC06B9666396A5ULL, 
            0x0A999B89C1B51992ULL, 0x1EEC985FF25DF8F9ULL, 0x50E9793A4B89670FULL, 0x40CEEF339115037DULL, 
            0xC306C4264C54EF19ULL, 0xC0315C67B8161AFAULL, 0x5F07EED5E335CC10ULL, 0x72D8AFBB09F54728ULL, 
            0x65B29941EF81BE54ULL, 0x3F5A24B25F427614ULL, 0x83718EEC0BD5C157ULL, 0x79646DF4F8816629ULL, 
            0xFACAAB59F89BC52AULL, 0x535E6E9490F212D4ULL, 0xFA49F85540A1BEC7ULL, 0x054986D1055994DCULL, 
            0x1C9714CCE5E79CB1ULL, 0xAA6C3C1A200BC362ULL, 0xF15581BC16956B0FULL, 0x0741DA8710A85260ULL, 
            0xC9FD7C6FFE099927ULL, 0xC6DB6136894C9257ULL, 0x3B8FDE7C3A0BA715ULL, 0x4B2D1325D740905AULL, 
            0x52BF9C85AF0A7531ULL, 0xB207C8EAE4472612ULL, 0xE54F6CD29096B2BDULL, 0x05F6D840D3779463ULL
        },
        {
            0xD3B392BF509EE170ULL, 0x49EF4794BBB48F39ULL, 0x6A7DF63646278B41ULL, 0xE3D1385B79E72CD4ULL, 
            0xD89B821BE5C30749ULL, 0xE2942C6A4AF2325FULL, 0xBCC061A22DBDC95BULL, 0xA816DFB674341EBDULL, 
            0x6AB7B79B227FEC69ULL, 0x4AEB93FED6A7B961ULL, 0x97E691ABD20800D4ULL, 0xA9E72E741BCB5972ULL, 
            0xA223AFDE0C3D2E3FULL, 0x507C7D3DD14D697FULL, 0x39572E49BE02958FULL, 0x7267624A13D036B4ULL, 
            0xFE98B154A3A4DF4CULL, 0xEF2CE8C4B261195BULL, 0x0B61F59ABC10A390ULL, 0xA8993C2C2AFD84B1ULL, 
            0x25673B22B9A3EB53ULL, 0xF3F5F9BD349CE806ULL, 0x4C38A3AE26B97186ULL, 0x38F30D8EB5FE79B6ULL, 
            0x5605B21DB9DDEB94ULL, 0x651D8787629FBDD1ULL, 0x9B0EFD2F7049B8ABULL, 0xC2DC87AC1196BB39ULL, 
            0xCE01C0A6EE5FE603ULL, 0xC67EB60336D35AB5ULL, 0xCE8A84DDBF38B33DULL, 0xAF75BDD4566E2C6FULL
        },
        {
            0x5D0844F6768F335AULL, 0xAE926F8569C8388DULL, 0x9B9D7FDD3B022690ULL, 0x793FAEE9777EB43FULL, 
            0xFD5DE99CBAA10724ULL, 0x43D5BBA741441A73ULL, 0x20150CA9A29EFAA2ULL, 0x6B2F687F6488A8DEULL, 
            0x9A2FE230869701ABULL, 0x9D9B11C3F97BD207ULL, 0x8F3FBDE54287D64FULL, 0x7C8DBA87D018E27DULL, 
            0x853034B36ED95A1AULL, 0xA7127D0D0C3E2FE1ULL, 0xADBFEFD0127C2C40ULL, 0x35B669C40D42E3A5ULL, 
            0xF89307ADB5396384ULL, 0x23A32A2307FC2DF8ULL, 0xE5E0EFB1FC3B890EULL, 0x24D8BC37A2518129ULL, 
            0xCFE8FCAEC3400851ULL, 0xBFC229C2A2780FCDULL, 0x1018802B46AA2B70ULL, 0x718691BD3ED55EB9ULL, 
            0x3E0F8F25E8CB73EAULL, 0x58EE0B3685BAE745ULL, 0xDD51A0DDF3625969ULL, 0x26B60006C2BB78E4ULL, 
            0xD7512DCFED5980A3ULL, 0xA598212AD967C22FULL, 0xAFA840AD3F155E93ULL, 0xDE452C8D4A7722BFULL
        },
        {
            0xDBF9A894CA446B44ULL, 0x36D32357923538CBULL, 0x2C41B2E6D00AB7C6ULL, 0xE3F9544E89FDDEC3ULL, 
            0x29DE29ABDC0E5A68ULL, 0x8CDA71B36B064EA5ULL, 0x60101F61766DE01CULL, 0x299B656D4D1F742FULL, 
            0x8CD74D67C20B93B3ULL, 0x2FAE7A07311CB5CFULL, 0xE9DDFB4F9237780BULL, 0x6500D0D2D6CD2650ULL, 
            0xF3C3CC4FC021383AULL, 0x0594A46A5B7BFFF9ULL, 0x66465FA593CBFA89ULL, 0xF28A4304488F55FDULL, 
            0x67304DB4BA874BBFULL, 0x9819915FAD1C3441ULL, 0x91DE270DB9F12CACULL, 0x04EC153ABEB414FAULL, 
            0x86FA58FC31B1D249ULL, 0x47DA86646F940E7FULL, 0x68D4538393127633ULL, 0xE874BD06DE1BA8C6ULL, 
            0x0BA99BD0324FE197ULL, 0x43974D2F9817512AULL, 0xB12260B147094F14ULL, 0x86C8445D6DFCE38FULL, 
            0x39DEE2D2CB9F57A0ULL, 0x5DBB813FDFBB5D9EULL, 0xB2CA446B12CF46C2ULL, 0x7F91038C2ED63E13ULL
        }
    },
    {
        {
            0x0E1A5BF37AF03A60ULL, 0x82587558AF56B9FBULL, 0xEA718E669F557722ULL, 0x7A0163228B161C39ULL, 
            0xCD0855F46A066D65ULL, 0xCB2619458A503A18ULL, 0x39A156CCF9BE87EAULL, 0xC1640A2F863CDEEFULL, 
            0xFA79DA6BFC0DA714ULL, 0x785ECDE35A22A600ULL, 0x3DDA3E59FF13DD66ULL, 0x043DAC7BF12388AEULL, 
            0x8B2E014B58AE58F7ULL, 0x732E3B718F574259ULL, 0x2E02DD05879B6DBEULL, 0xFA3142DFE74F66FDULL, 
            0x95F441B93FD901F0ULL, 0x57CF839F85838420ULL, 0xD3CA507964AD35F0ULL, 0x54647197A7B9BAFBULL, 
            0x4703222A9A2C69B5ULL, 0x1D51AABE7C9986A4ULL, 0x5625AA2C75046F16ULL, 0x13B59EA976A515ADULL, 
            0x9B383F1F91ECC1FFULL, 0xB743F6E4D8877240ULL, 0x2DD02B063EEED5E4ULL, 0xC9E7622692D8790BULL, 
            0x37F468107B76B871ULL, 0xC9DCABB57C64B3CBULL, 0x6279740999E8F1CDULL, 0xB81B224A8AD6158FULL
        },
        {
            0x41099BD6A93EFB90ULL, 0x3B673CB32094BE71ULL, 0x346C7E5B6E9F3522ULL, 0x8C74881C2BAF5924ULL, 
            0x3955D0939D56A263ULL, 0xB67D57F248010D30ULL, 0xB299C4C338C3C83CULL, 0x636E552A253A490AULL, 
            0x91167FB6893E9154ULL, 0x1FCC2E6BC51F5CE9ULL, 0xA0D98E08B69E2691ULL, 0xFBA03A3AC73E95ABULL, 
            0x420073176AF616A0ULL, 0x46A93986A85D3D7EULL, 0xDEEE3718956B6551ULL, 0x1B5531EA0F1D1C82ULL, 
            0x4E66D77000513ADFULL, 0x7932478B6040228AULL, 0x16887E3E0B00C176ULL, 0xE197C81B10FB15A1ULL, 
            0x55A4B9B76D0B2126ULL, 0x8B29C57D17D92E2CULL, 0x7951FD5AE4C31ECCULL, 0xFBFD2FEACC37C652ULL, 
            0x61342B1E57655EE2ULL, 0x39C2D7596D5B1748ULL, 0x6577344AF2D80D62ULL, 0x0E4D0AEE156354B9ULL, 
            0x95CA850B11B25AA8ULL, 0x75358984F46E7E32ULL, 0x01E9705F54D3394DULL, 0x46F920E53A7039A4ULL
        },
        {
            0x757A7EE69BE41CEEULL, 0x5F0D942F9865DCB7ULL, 0x7431592C8DFA074DULL, 0xBF1123CA60DFFF61ULL, 
            0x402B85C652B95D84ULL, 0x3C0893A3B32E7B05ULL, 0x7C0BEE93033624BAULL, 0xE20ABDAA9AD772D4ULL, 
            0x556420DE46ABEF32ULL, 0xC3FE02866B2ED704ULL, 0x5175012F2B8ED68AULL, 0x38AE9838F1D7FCF1ULL, 
            0x7144826C5645B147ULL, 0x72B159A9461CB713ULL, 0x9EECDEE22FF9722FULL, 0x0EC29B6B9A5405DDULL, 
            0xA046296D10486F47ULL, 0x388E18A919287766ULL, 0x24BAF724E77A2E37ULL, 0xF38C89E34F5181DEULL, 
            0xD159A533D8005E9AULL, 0x7A28C055CFB4AD55ULL, 0x27699C6B9F9226A8ULL, 0x9E7C4FF5CBF34DB3ULL, 
            0x41D00EBE391B0995ULL, 0x5379D87D975090C6ULL, 0x97FC09CA6893DC37ULL, 0x6980E97ACB8BC372ULL, 
            0xD2934B5C9A7373ECULL, 0x4CE2F202CDC3A6B8ULL, 0xEBCC55CD9A08034EULL, 0xCC5E73E1E18BDEF3ULL
        },
        {
            0xDF42B2771100F246ULL, 0x3DFF4DD5E3255292ULL, 0x2D00FE909ABC0C9CULL, 0x8AF6B39DF4103503ULL, 
            0x09DEA080344FA7BEULL, 0xD0F1285E773D9A9CULL, 0x816F3F6F2C855D7CULL, 0x4DFD1B3D8DD57D56ULL, 
            0x728551158E485EF8ULL, 0xC6D2AF501AC3DD1AULL, 0xB219CF840A9B2EA7ULL, 0x0F74938102648902ULL, 
            0xF00D980523596045ULL, 0x321963DC1DB7968FULL, 0xAF12C9A97AE3DC9DULL, 0x921F6CE5F0225CBAULL, 
            0xFBB7478C262F38CAULL, 0xE7E47AEEEFDA0DFAULL, 0x90A8C44FF11CE568ULL, 0x47D9AA23470191F0ULL, 
            0x28CA6706D4F5A778ULL, 0xA01D28048140D14BULL, 0x8D345E63A10D8A95ULL, 0x818932FDA61D01F4ULL, 
            0xBC99152956738AC8ULL, 0xCDE4A6BFF23537C5ULL, 0x59079F6F9098568DULL, 0x7141CB4E113F0D8DULL, 
            0x126B1272106236D2ULL, 0xC5F2954A9B64E44BULL, 0xCCEBF372B0093E23ULL, 0x631602F849C0757FULL
        },
        {
            0xC9EC0D1BFF9CE4F7ULL, 0x4620051FD7292057ULL, 0x542191156A2FC58AULL, 0x017C066AE6778E6DULL, 
            0xA135C47C923A2969ULL, 0xF56C43603538A3EBULL, 0x5AFCFF14A4FFE4B8ULL, 0xD5271E2C29C381D5ULL, 
            0x874446569C666615ULL, 0xDED956416525E7EAULL, 0x89212B49FF2F8D43ULL, 0xAAF191F1719CDEE0ULL, 
            0x4A4E412357B93D89ULL, 0x5CBFD29950B0E8DCULL, 0x07B75C79C3A08BA6ULL, 0xE5B0553AFBFBCD7AULL, 
            0x92148B69111B2220ULL, 0x09E3D36F1560772BULL, 0xF8FD1171129514FBULL, 0xE6E8008FEAE0E5ACULL, 
            0xD31E345A1378D083ULL, 0xFD03DE1D48ED8939ULL, 0x021142FABA5D778AULL, 0x7BFCC02B641C050CULL, 
            0x6138BC819B08C684ULL, 0x17A4483AD3954180ULL, 0x0E590FF09C7F5504ULL, 0xE284752D0F5640ACULL, 
            0xA7C8E5F27A6DB5FFULL, 0xF75C0A94D05B9D74ULL, 0xFA10CA138918EB26ULL, 0x964C6E1079301443ULL
        },
        {
            0x69ECE4FD4DC2A2FCULL, 0xC8D0921F2E03566BULL, 0xB107EE13359DDDBAULL, 0x789B7AC1DC574990ULL, 
            0xF0F25B53AF698F98ULL, 0x4995048CAB3C4092ULL, 0xAA4D4D40DFAEA7BEULL, 0xF3EAE6C10F3ED3EAULL, 
            0xADCC5CE7C891C853ULL, 0x9A93CD94BEE626C5ULL, 0x87DA80B25F042876ULL, 0x77FA30401BD35419ULL, 
            0xDD12F2FBFDEC9F02ULL, 0x6959A731141717E3ULL, 0x554F95B92FCFAFF1ULL, 0x04EAC915AB9CD425ULL, 
            0x9991B06D1A488B7DULL, 0x4A2EAFAAFED7C98FULL, 0x52E028E56BFDD846ULL, 0xCBCA8E465407E040ULL, 
            0x852536F51C3200CCULL, 0x23AED4DAB88A9897ULL, 0x2D309FEA11BDA3FEULL, 0x8E03EB17C6A9CB6DULL, 
            0xD9906FE9106ECBCEULL, 0x6C7F3C6F9C7221CCULL, 0xAB281CAB89897008ULL, 0xB60DEE3C2EA789A5ULL, 
            0x858E896FB1D48794ULL, 0x522376926D69AFA1ULL, 0xCFBA13DE87E78DB6ULL, 0xE38F6708597F516CULL
        }
    },
    {
        {
            0x44C99D2407F30860ULL, 0x92EDB43A764FA8F7ULL, 0xAB9904042DBD0E0FULL, 0xB38FDB8C7AB26138ULL, 
            0xC904CF31BA4DE29AULL, 0x5A5041E7BC339B01ULL, 0xA76B14CFB1344B88ULL, 0x21F8144B908A3039ULL, 
            0x058A95FC8462F3A1ULL, 0x1FCFC18B94E2C25EULL, 0xE845D8F2DA73C8A4ULL, 0x62C8551E905C39BFULL, 
            0x7D587F8C8F86D546ULL, 0xFC587E5E1522CE9FULL, 0x7FFF5D00E0082C48ULL, 0xD9E6C54B3D2E65DEULL, 
            0xD2BE4C6B56F77D5EULL, 0x51822202128CDA80ULL, 0x36D31DD0EAF12122ULL, 0x85A3C66B94EAADA8ULL, 
            0x7AA2680934E773FCULL, 0x7A8B029D4131F9B0ULL, 0x60C73AE65217A690ULL, 0x4F92994EF41DF8D2ULL, 
            0xF8EC392575CB4F4DULL, 0x739F6EABC5B151A4ULL, 0x50A79B5111033FF3ULL, 0x2F510FC29309C825ULL, 
            0x77AFEC71B329BFE5ULL, 0xA0051057CD9B6D4AULL, 0x1BD7C4DF15AEAAF9ULL, 0x34B9B06E10CBC7F2ULL
        },
        {
            0x7B2ADFAFA1D9D685ULL, 0xD75243B72FECC0D5ULL, 0x1DF125A97BAEB533ULL, 0x673D8FA37848C7B6ULL, 
            0x36C048EEE130F9EAULL, 0x223490E9EF271550ULL, 0xD1933BAF106011B0ULL, 0x5F616313F4DE27DAULL, 
            0x5FBBBF209AD0D023ULL, 0x0DCBB3AC1CC6167BULL, 0x8F5B5F56734F1ECAULL, 0x5CCF566D2712CA0FULL, 
            0x5DA74403F58C94E3ULL, 0x7D9DB01E361EF577ULL, 0xAD00B08E80C04A66ULL, 0x5BF86B3E81546698ULL, 
            0x53D26D6076352CE5ULL, 0x68534CC3B3EC0C9AULL, 0x952808621BA79CB3ULL, 0x841D7082506D43D3ULL, 
            0x01AB328AA9389EDEULL, 0x28E7EE1D2760C9E5ULL, 0x645DC0893D68F56FULL, 0xA7C8D504A1754716ULL, 
            0x6D41BCC9413F4C30ULL, 0xA51DEA4786AB8942ULL, 0x2BF57B4C327C15F2ULL, 0x0894B2816D333409ULL, 
            0x7FE7C407DD0BBCFBULL, 0x10048729090310A6ULL, 0x2A84E0355B950FF8ULL, 0x8B88C2328B0B8306ULL
        },
        {
            0x838EC48337AA5703ULL, 0xFFAC556BA07D87D8ULL, 0x88DDEEC9B02991DBULL, 0x8AC0B7EFAC1B2940ULL, 
            0x0EB9832328AC4A23ULL, 0x07638B8AC98FA469ULL, 0x7EC4DA2D68F8B99FULL, 0xEBECB0ED036B3240ULL, 
            0x0CC5867E8FE35804ULL, 0xD55503CE72BCFCF0ULL, 0x8392DF2391DD3A20ULL, 0x212E278B2AA679CBULL, 
            0x3DFAB1A1A5719D63ULL, 0x278B58288BBB49C4ULL, 0x8BD0BCC756F52282ULL, 0xA21783E7474053E5ULL, 
            0xDAA1F6F9DAAB0C1EULL, 0xC6AFA0EE3503602BULL, 0xC83062C5F8450E40ULL, 0x21E8F1BEB0784A17ULL, 
            0x6F82213BC88E0010ULL, 0x433FFFFA76F53139ULL, 0xBEFCC7F159B688EDULL, 0x97A1AE65FF0FAF78ULL, 
            0xBDD00726C76009ECULL, 0x2D3ACC99AEBEA393ULL, 0xEB5BCE10B9733A9CULL, 0x8B89876D358403AAULL, 
            0xD2C44EB9D368038CULL, 0xA9A07C63E5CBBF27ULL, 0xD49263C581EC7734ULL, 0xD8D4904A7DF17FA9ULL
        },
        {
            0x6DFC4E0BE587FD04ULL, 0x92462E7009EFD910ULL, 0xC60497050CEF12A5ULL, 0x5A7743DD3AA0B22AULL, 
            0x929F579F5F068326ULL, 0xC457A3D2885E1FADULL, 0x9B3E89322936196FULL, 0x4C726FCCA4FC5B75ULL, 
            0x6245BAF45CCA8627ULL, 0x3CEBD2D54AF467B8ULL, 0x43C9F37147DF8FAAULL, 0xF2CB4238F4128121ULL, 
            0xBA7BA53A75AE955FULL, 0xF2A896AD2F101F9FULL, 0xE52E742F428DE289ULL, 0xE6C4268A5127B049ULL, 
            0x47A1407CA4889F65ULL, 0x296CC3D2D0A0554BULL, 0x18E37F86B8755D19ULL, 0x91DF5F30BF232A17ULL, 
            0x4B31BBB87BBD39C2ULL, 0x8528CF31B384074DULL, 0xB348B1B7D28BCBC8ULL, 0xDCC6A4FE0A987AE5ULL, 
            0x29042C3B4CA55992ULL, 0x82BA9EF0595D9277ULL, 0x12BA03ABDE31D58FULL, 0x4207A00C85D907BFULL, 
            0xEE26CFBF2E951BDBULL, 0x768697673A46DC54ULL, 0x6574BFE7B132A1A0ULL, 0xA4E20FFF9E61A83EULL
        },
        {
            0x796F94423A03C792ULL, 0x21AD9E72EA3D723CULL, 0xF433E25D1A6768BFULL, 0x96994D32C33CD2B9ULL, 
            0xA167EA1C1A4BC482ULL, 0x0F32F7AABD765832ULL, 0x9A4EF11D7FDBE58DULL, 0x6A31E8372B4BC595ULL, 
            0x8F9636DD408E1AB8ULL, 0xCF3B4801ACB15D5EULL, 0x9B4DC50BE931427BULL, 0xD7353A55625C5F1DULL, 
            0x4EC90CB7AC1D57C2ULL, 0x6B6996F44148BB45ULL, 0xC073EFCE882A1A38ULL, 0xAA95CE3FD4409480ULL, 
            0xCEDCB0C271C87047ULL, 0xABEFC1CC266539D3ULL, 0x533A551EA488B3E7ULL, 0x1121F3F22EB0DB0AULL, 
            0x793C4FB701AD5812ULL, 0x744AA2E142A74F6CULL, 0x2FFC391D79E32470ULL, 0xED5EB4881CCD00D2ULL, 
            0x1B895E362C704366ULL, 0x55076A6127ED4423ULL, 0xA916D2E7633BD3ADULL, 0xB33EE65C2D5F7F69ULL, 
            0x3A483233E82AFC52ULL, 0x74446BFCEEABFE32ULL, 0x52C286C27CEDDF0BULL, 0x8D20E9640BA44E58ULL
        },
        {
            0x9B8C1A3018B562A4ULL, 0xF924824BE72CB2B9ULL, 0xDB165CB14B548FC7ULL, 0xAC97C5AB05DE70FDULL, 
            0xA2B07D98A28EA955ULL, 0x724FB3108161829FULL, 0x4D6C38B179B97001ULL, 0x9145387DF3E1A223ULL, 
            0xE805B56B43768D91ULL, 0x3034E4580A7B45D7ULL, 0x153EA2991A5A1472ULL, 0x0E79FC5DCBFDF8E4ULL, 
            0x439CEA01C811883CULL, 0xCDD732925F31B9BCULL, 0xB239A2D30AEC0C2DULL, 0x687F17E9E71BCB88ULL, 
            0xC622B1DE3BAFE89CULL, 0x88DEB930F3680C4CULL, 0x463BAE78530CEFD6ULL, 0x3DCBDEB834DA31EDULL, 
            0x76CBC4B64238B818ULL, 0x72BE0BA652F71B35ULL, 0x6F465E3E8F0B68D9ULL, 0x30593B0CE118A326ULL, 
            0x42AD8BF4BCC69B2FULL, 0x2DE0E3CFFDD6A6E6ULL, 0x0CA693CC991A193DULL, 0x1BCE59C8A54C0CFBULL, 
            0xCCE17C90940A59C4ULL, 0xC165D21FFDD89F22ULL, 0x0853CD7D15C2E52DULL, 0x6E5CEE2E38631B6CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alkaid::kPhaseDConstants = {
    0xB86072707633C6F7ULL,
    0xE3001513F21EFB92ULL,
    0x8927EDAA8C492CE0ULL,
    0xB86072707633C6F7ULL,
    0xE3001513F21EFB92ULL,
    0x8927EDAA8C492CE0ULL,
    0x993951C4B9E2EDE0ULL,
    0x8DE6E2EC44E64114ULL,
    0x0D,
    0x1C,
    0x88,
    0xC5,
    0xD6,
    0x59,
    0x35,
    0x51
};

