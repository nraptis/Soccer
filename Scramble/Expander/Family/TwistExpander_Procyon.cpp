#include "TwistExpander_Procyon.hpp"
#include "TwistDiffuse.hpp"
#include "TwistFunctional.hpp"
#include "TwistIndexShuffle.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"
#include "TwistFarmSalt.hpp"
#include "TwistFarmConstants.hpp"
//
#include "TwistShiftBox.hpp"
#include "TwistSquash.hpp"

#include <cstdint>
#include <cstring>

TwistExpander_Procyon::TwistExpander_Procyon()
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

void TwistExpander_Procyon::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB154EFFAAE229BA5ULL; std::uint64_t aIngress = 0x9E53359D5B6F5C41ULL; std::uint64_t aCarry = 0xD605BC33B84095B9ULL;

    std::uint64_t aWandererA = 0xB4BB128073B20117ULL; std::uint64_t aWandererB = 0xC40BCC12CE8895C0ULL; std::uint64_t aWandererC = 0xB28B7591598BC0F4ULL; std::uint64_t aWandererD = 0xB7B4CC262B8A2095ULL;
    std::uint64_t aWandererE = 0xAAE9009E10ACD495ULL; std::uint64_t aWandererF = 0xB14908E223229D2DULL; std::uint64_t aWandererG = 0xA60525C86E0A71A9ULL; std::uint64_t aWandererH = 0xD768B1E774D6AE0AULL;
    std::uint64_t aWandererI = 0xB8B8A07A27CF93E6ULL; std::uint64_t aWandererJ = 0x9AD0683698E987D2ULL; std::uint64_t aWandererK = 0xCBDD8AE85C373680ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x91DCF3C059C124F0ULL;
        aCarry = 0xB142AAF365EDF110ULL;
        aWandererA = 0xB95F7715F8F53368ULL;
        aWandererB = 0xFC28695FA4D63414ULL;
        aWandererC = 0xE6FA4AC9DB60FAFAULL;
        aWandererD = 0xB82FF915DC9148F2ULL;
        aWandererE = 0xE1A5B8EE36C295F8ULL;
        aWandererF = 0xF82E344DD2DF6D8AULL;
        aWandererG = 0x87A7940EA80A647BULL;
        aWandererH = 0xE7D29EDCE12BF270ULL;
        aWandererI = 0xB7C7889805FC40D9ULL;
        aWandererJ = 0xD85909A731CA8392ULL;
        aWandererK = 0xF589B3C8F93034C9ULL;
    TwistExpander_Procyon_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Procyon_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Procyon_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Procyon_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Procyon::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA029CEB0786A015DULL; std::uint64_t aIngress = 0xA2131310AED886B7ULL; std::uint64_t aCarry = 0x978510A20AE36A73ULL;

    std::uint64_t aWandererA = 0xE30A59A59A642B9FULL; std::uint64_t aWandererB = 0xA1846E9B50391A8CULL; std::uint64_t aWandererC = 0xBCEBC4B2791C2C48ULL; std::uint64_t aWandererD = 0xBEDC3DEC0B2404C1ULL;
    std::uint64_t aWandererE = 0x8B844B6BE51CA325ULL; std::uint64_t aWandererF = 0xD1E18E81EF85D789ULL; std::uint64_t aWandererG = 0xDE00FBAE6D4F9F3AULL; std::uint64_t aWandererH = 0x942121CD51E77B4DULL;
    std::uint64_t aWandererI = 0xAB4FEEC89E9ED77EULL; std::uint64_t aWandererJ = 0x96D00A31DE2CD13AULL; std::uint64_t aWandererK = 0xEDF15FDB03FDA96EULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x9EA7B2887D9CEB46ULL;
        aCarry = 0xCBD305F1D79201A7ULL;
        aWandererA = 0xF5193F343AC655D7ULL;
        aWandererB = 0xEAD0C395BC9A15E1ULL;
        aWandererC = 0xFD3B3DD07045DB2AULL;
        aWandererD = 0x9C5C6BA18ABB466BULL;
        aWandererE = 0xF8963D07C7096164ULL;
        aWandererF = 0xD54662585C880991ULL;
        aWandererG = 0xA816D837A2212471ULL;
        aWandererH = 0x8139DC10A50E6D4CULL;
        aWandererI = 0xA08F4F1B27A0B5FFULL;
        aWandererJ = 0xF1BBF0454BF68975ULL;
        aWandererK = 0xEF75DCAD688A1ABEULL;
    TwistExpander_Procyon_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Procyon_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Procyon_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Procyon_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Procyon::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB4823ECE64BF9745ULL;
    std::uint64_t aIngress = 0xF5E203119337230BULL;
    std::uint64_t aCarry = 0xC23285177058405DULL;

    std::uint64_t aWandererA = 0x827B008277ACA93FULL;
    std::uint64_t aWandererB = 0xAD2C0BCAF1CC21E7ULL;
    std::uint64_t aWandererC = 0xD8B8E9F5AEFBF65EULL;
    std::uint64_t aWandererD = 0xC099314E8074E6FBULL;
    std::uint64_t aWandererE = 0xBD82269A2A35F086ULL;
    std::uint64_t aWandererF = 0xADCDA9CD649CA023ULL;
    std::uint64_t aWandererG = 0x929B961CA771F555ULL;
    std::uint64_t aWandererH = 0x9D78C8F4646E19FBULL;
    std::uint64_t aWandererI = 0xA87EB468B3163649ULL;
    std::uint64_t aWandererJ = 0x8BC727A338E11C45ULL;
    std::uint64_t aWandererK = 0x85C39C8E62065664ULL;

    // [seed]
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), pSnowLaneA, 0);
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
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), pSnowLaneB, 1);
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
        TwistSquash::SquashA(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, aIceLaneB);
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
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), pSnowLaneD, 2);
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
        TwistSquash::SquashA(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, aIceLaneC);
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
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), pSnowLaneC, 3);
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
        TwistSquash::SquashA(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, aIceLaneD);
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
    TwistExpander_Procyon_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Procyon_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Procyon_Arx::Seed_C(pWorkSpace,
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
    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgD;
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
    TwistExpander_Procyon_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Procyon_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Procyon_Arx::Seed_F(pWorkSpace,
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
    aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixSelectA;
    aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixSelectB;
    aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixUnrollA;
    aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixUnrollB;
    aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixArgA;
    aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixArgB;
    aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixArgC;
    aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixArgD;
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
    TwistExpander_Procyon_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Procyon_Arx::Seed_H(pWorkSpace,
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

        TwistSquash::SquashA(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, pDestination);
    //
    //
    TwistExpander_Procyon_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Procyon_Arx::GROW_B(pWorkSpace,
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

// SmartSquash candidate 26 of 33
// Exploration cases: 100000000
// Nearest-family diversity: 917 / 1088 (84.28%)
// Total distance from earlier candidates: 23269
void TwistExpander_Procyon::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    static_assert((S_BLOCK / W_KEY) == 16, "SquashInvestToKeyBoxes expects 16 invest fragments.");
    static_assert(H_KEY == 8, "SquashInvestToKeyBoxes expects 8 key rows per box.");
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 10U), *aFragmentB = aIceLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 11U), *aFragmentD = aIceLaneD + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 596U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 668U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1195U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 2011U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 4U), *aFragmentB = aIceLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 4U), *aFragmentD = aIceLaneD + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 703U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 759U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1754U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1112U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 6U), *aFragmentB = aIceLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 13U), *aFragmentD = aIceLaneD + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1328U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 2025U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 671U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1477U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 7U), *aFragmentB = aIceLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 1U), *aFragmentD = aIceLaneD + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1457U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1983U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 639U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1787U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 12U), *aFragmentB = aIceLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 10U), *aFragmentD = aIceLaneD + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 384U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1973U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1556U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1185U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 3U), *aFragmentB = aIceLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 0U), *aFragmentD = aIceLaneD + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 710U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1907U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 327U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 440U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 14U), *aFragmentB = aIceLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 6U), *aFragmentD = aIceLaneD + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 210U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 752U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1455U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1210U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 0U), *aFragmentB = aIceLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 9U), *aFragmentD = aIceLaneD + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 212U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 714U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1424U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 899U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 11U), *aFragmentB = aIceLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 8U), *aFragmentD = aIceLaneD + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 323U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1377U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1209U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 326U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 8U), *aFragmentB = aIceLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 12U), *aFragmentD = aIceLaneD + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 642U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 917U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1774U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1401U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 1U), *aFragmentB = aIceLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 3U), *aFragmentD = aIceLaneD + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1305U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1581U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 344U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 527U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 2U), *aFragmentB = aIceLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 14U), *aFragmentD = aIceLaneD + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 2030U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1673U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1675U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 2003U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 15U), *aFragmentB = aIceLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 7U), *aFragmentD = aIceLaneD + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 127U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 388U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 785U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 404U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 9U), *aFragmentB = aIceLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 5U), *aFragmentD = aIceLaneD + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1175U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1258U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1272U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 955U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 5U), *aFragmentB = aIceLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 15U), *aFragmentD = aIceLaneD + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 376U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1674U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 152U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1505U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 13U), *aFragmentB = aIceLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 2U), *aFragmentD = aIceLaneD + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1750U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 631U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1387U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1212U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Procyon::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA331B23A1FF400E6ULL; std::uint64_t aIngress = 0x87D9A26445F9335EULL; std::uint64_t aCarry = 0xE077F2AF8337965BULL;

    std::uint64_t aWandererA = 0xF00DB6FC1A25C0A0ULL; std::uint64_t aWandererB = 0x8A24085E153D32BBULL; std::uint64_t aWandererC = 0xAEF1C050CFE91615ULL; std::uint64_t aWandererD = 0xB90D8419934DCA0AULL;
    std::uint64_t aWandererE = 0x8519C9164053E047ULL; std::uint64_t aWandererF = 0xD7E4419038D65A0EULL; std::uint64_t aWandererG = 0x84F3DE32B4416886ULL; std::uint64_t aWandererH = 0xD2004B157ED06D28ULL;
    std::uint64_t aWandererI = 0xBF1EB3C176E62DCDULL; std::uint64_t aWandererJ = 0xB9E35871E2116083ULL; std::uint64_t aWandererK = 0xD70D064D2F9CB9B6ULL;

    // [seed]
        aPrevious = 0xF42CA781683073F9ULL;
        aCarry = 0x9AEF9BCF5091264DULL;
        aWandererA = 0x8CE0210349BFA602ULL;
        aWandererB = 0xD831D84DB30F16B6ULL;
        aWandererC = 0x82506F6A958BBDC0ULL;
        aWandererD = 0x93ADC27E5E6B6C4CULL;
        aWandererE = 0xA52961106EBF602EULL;
        aWandererF = 0xFF0F072953355637ULL;
        aWandererG = 0xA8F8AB8EB7E1CB6CULL;
        aWandererH = 0xE9E2448287CCF302ULL;
        aWandererI = 0x8024FF8CB97C7353ULL;
        aWandererJ = 0xCF805891048B239BULL;
        aWandererK = 0xDE9B935167020C2DULL;
    TwistExpander_Procyon_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Procyon_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Procyon_Arx::Twist_C(pWorkSpace,
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

    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgD;
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
    TwistExpander_Procyon_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Procyon_Arx::Twist_E(pWorkSpace,
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
    TwistExpander_Procyon_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Procyon_Arx::GROW_B(pWorkSpace,
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

// GrowA candidate 26 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 13524; nearest pair: 479 / 674
void TwistExpander_Procyon::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2063U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2419U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3527U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7435U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3597U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 444U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6091U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2158U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8085U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8131U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1967U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 743U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3800U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 237U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 653U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4633U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 730U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 953U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1059U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 165U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1337U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1069U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 16U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 787U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1282U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 318U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 48U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 530U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 848U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 17U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 147U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1147U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1256U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1725U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 108U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 2029U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
}

// GrowB candidate 26 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 13538; nearest pair: 445 / 674
void TwistExpander_Procyon::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1295U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2952U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3359U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 603U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 919U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6714U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 112U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4959U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 294U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6550U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5686U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6944U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 221U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2922U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 960U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1885U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1172U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1698U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 868U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 974U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1896U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1744U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 261U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1998U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 332U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1075U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1604U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1402U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 85U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1019U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1689U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1558U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 931U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 49U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 509U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
}

const TwistDomainSaltSet TwistExpander_Procyon::kPhaseASalts = {
    {
        {
            0x71BC355D133ECCD1ULL, 0x2335BC9E32CB7130ULL, 0x36693A684CD01040ULL, 0x74AD46B4A5401B80ULL, 
            0x03DE35C306E1117EULL, 0xC0E773987EEC1470ULL, 0x8BBC40B0E296A2C4ULL, 0x78738605DFAE5038ULL, 
            0xA7904777151050AEULL, 0x6A62FFAF33A77F96ULL, 0x6D445248D3AB91C8ULL, 0x5E4043CEECD6C738ULL, 
            0xC655E609A0DD10A4ULL, 0x29FA23C18A7145BAULL, 0xF88C28C28158DC3EULL, 0x6A72EE41F4BB60E0ULL, 
            0x81E409B1058442A5ULL, 0x0B0E1CD13E6A9021ULL, 0xEC453C29D770F5DBULL, 0x481C16D311C10A27ULL, 
            0xF2A6621A53604792ULL, 0x2D8DC59D4452D734ULL, 0x5969A13DC7AFD22DULL, 0x6A6FCED99C24A315ULL, 
            0xFC14B0408D9C3FACULL, 0xEFE536A617D8CFCAULL, 0x4636720BB19A03E1ULL, 0x73A184BE84EDFB9BULL, 
            0x18D1C40766D04ACAULL, 0x900132C6DF5CC798ULL, 0x4D1F73E84A898822ULL, 0x6216F1E653C26A33ULL
        },
        {
            0x683C69C63FD80DC0ULL, 0xE5059F5F4E9DD44AULL, 0x27BA2B4845C02100ULL, 0xF47BDCC647080634ULL, 
            0x50FCD661516E6A0AULL, 0x943F6B2DC8475FEFULL, 0x599C45A49A8845BAULL, 0xCD70A4A8CD0307ECULL, 
            0x450C58117D0175AFULL, 0x3BAF2B6CCEE12490ULL, 0x9D80C3750E7D1DBDULL, 0x179DEE170EAF4195ULL, 
            0x03865E43C1A3105BULL, 0x8CEEB2BF7C7F3D14ULL, 0xD69DFF7444FA09FAULL, 0xA1146F9474F45ADCULL, 
            0xBBC4799F6EFBD7E9ULL, 0xB5C6B811D6EEC27CULL, 0x38EFDBA85C02CF63ULL, 0x462F656D0E598035ULL, 
            0x22B89B881F1F469DULL, 0xDB96A83CAE2410F0ULL, 0xD965C2B98EE571CCULL, 0xA0796EC79FC89B32ULL, 
            0x70F8BEC87B96E73FULL, 0x27427226015FD699ULL, 0x7DED045268B9F0C3ULL, 0x54056191B3AAC406ULL, 
            0x7FAAFE3D1720ED50ULL, 0xDD0219F6CC266DF5ULL, 0x650D0243DFF4F5B9ULL, 0xD0FE284858221441ULL
        },
        {
            0x3711376FC72DEC97ULL, 0x9147F33BFA3C0F19ULL, 0x014DB7BF04F19859ULL, 0x46D0919AE71F31ECULL, 
            0xC227C5CB2E93F565ULL, 0xE55CFFBF6DE46586ULL, 0x566A0A44A4D78BCDULL, 0x8AE24217B5867AFCULL, 
            0x9E6F5B3F1BE7B296ULL, 0xC408D84E99D5014AULL, 0xCC758F7B7BBF6A61ULL, 0x992A47A1B9BD7C2AULL, 
            0x966FBB56093B0B2BULL, 0xBC848FC500630A9FULL, 0x3FC0A3C56C847DFCULL, 0xEAB4415CFDD63A96ULL, 
            0xF7E7B9669C8E7FA1ULL, 0x71D445DF26A5E0A3ULL, 0x5C81F8287FD221B1ULL, 0xBD3B735051075961ULL, 
            0xC0284D6DC0D301E7ULL, 0x369B8802CCC43EB7ULL, 0xB82B8C00BA9B5C4DULL, 0xB174076C2DC7AFF2ULL, 
            0xDB320DC6EF608730ULL, 0x3618EFB1AD750861ULL, 0x8FE6665D96114B4FULL, 0xDCB9B4A5A5B9915CULL, 
            0xF2B3E587F280589BULL, 0x9DD78F18E06ECDD3ULL, 0x0FBAD5A01A0ED02EULL, 0x71CEAC61C78215CCULL
        },
        {
            0x69327C13E364C7F2ULL, 0x76324AA40F468D9DULL, 0x1C94DB8BC974D160ULL, 0xAE1821743C1E7F9CULL, 
            0x584BA54EF72E2E6AULL, 0x5550E030476F3C47ULL, 0x91E5E2467AE72D40ULL, 0x9CBCB1DC0C394F09ULL, 
            0x530273EEC06D3649ULL, 0x52D1220F10902326ULL, 0x7D325CE6DF0CDD81ULL, 0x35AEDBA9A77AABE5ULL, 
            0x6120CBBC38133F21ULL, 0xBA0564CAD2E5EDD2ULL, 0xA7257B12A2E9C525ULL, 0xCBDB0F58EB142BADULL, 
            0xBC280CC972CD2735ULL, 0x55B59C101130BC1DULL, 0x42368AE74DCB916EULL, 0xC6A9D3F255FB6C08ULL, 
            0xF346E294F4BEBAD0ULL, 0x2A8E786C3598CEE8ULL, 0xC8E58FB8126521C2ULL, 0xE8FEF507E2FAE497ULL, 
            0xF61B0C535FDB38ADULL, 0xA27ADF6A621D1C6EULL, 0x62B3204A918EBB05ULL, 0x8C42C1E5540B074CULL, 
            0xDB85F776A4C43504ULL, 0x01B0308C97F223B3ULL, 0x8F1986A81982A76FULL, 0x2E19AF3845E48A42ULL
        },
        {
            0xD33BB51A00334919ULL, 0xEC8AFD30A3B89947ULL, 0x232139AB04902ABFULL, 0xD6974CE3E2B26F89ULL, 
            0x90CC7707A313AD9AULL, 0xF15C155AE76430B9ULL, 0xC31E5446FE92B818ULL, 0x30EC2E6E40D1A039ULL, 
            0xDEB803DAB2C70ADEULL, 0xC84C79772C58058AULL, 0x85FDDC26A7E0B29DULL, 0x79865F1DAFDD48C4ULL, 
            0xC328122539BD7EC4ULL, 0xE322A8937F61D1BAULL, 0x273A1E03B4487E21ULL, 0x9A02042631E8EA8BULL, 
            0x8BD0C3B2083F85E5ULL, 0x75B8A823EC125FE1ULL, 0x124F1AFF3E034725ULL, 0x87054E758DAD8DAFULL, 
            0x54F1CC2C846CB40EULL, 0x15C000ED8D958BE5ULL, 0x2265AD9F717F1AD5ULL, 0x6FACF278CA72C298ULL, 
            0xD46803867B72692AULL, 0x8E169F792E073A95ULL, 0x2D748AF0A682C18DULL, 0xCC69ECA772204CF7ULL, 
            0x376EFC734C710592ULL, 0xA7E16306B0771A35ULL, 0x98639826A5D48DDEULL, 0xAD787A3F31EEB3B2ULL
        },
        {
            0x9DF1CCAEDE50D0AAULL, 0xE17E29A92079BDD0ULL, 0x39A1671D1B669E61ULL, 0x8F8A3DDF666AA7F0ULL, 
            0x31A89F24F3127F31ULL, 0x2A468FEA0BF82002ULL, 0xBD55E2DDBD49EDDDULL, 0x1A38E996F0954A26ULL, 
            0xBA7DABA2BDA7C92BULL, 0x091EA66FEA689453ULL, 0x8F41A03BB9DA4729ULL, 0xB48F63452F25DE54ULL, 
            0xF541D8D2EEAAC699ULL, 0xEEF02D4B2D6F4FCAULL, 0xBE8F6357B556C8F1ULL, 0x3951A45FA2778252ULL, 
            0x06F9ADD97A66339DULL, 0x92D5CD03E39D5E4CULL, 0x83873E6E9B45121FULL, 0x3B200A28C1BF59C7ULL, 
            0x2488E17489920D84ULL, 0xD6E24770A95176E1ULL, 0xCBB21DF982D874A8ULL, 0x4B84AC9B06F3F997ULL, 
            0x5D4041630C28021FULL, 0xFE37210663150D58ULL, 0x5C1B793EF6B72559ULL, 0xE44617B780A9D006ULL, 
            0x9C7A7F79963AE9C3ULL, 0xA29C9088A65BB342ULL, 0xB66C2EB5A6D6D4E3ULL, 0xE4D54FC5619B3BCAULL
        }
    },
    {
        {
            0x4F6EDF278414E109ULL, 0x2EB9F9359DCFFF94ULL, 0xC20E57DA8DE77223ULL, 0xA62916CDDF368C69ULL, 
            0xF1A03FDA9A6CD7ABULL, 0xC606D21C9553C923ULL, 0xA43AFA0EC02F9A07ULL, 0x07FA79E4AB56A1BFULL, 
            0xF738CD5828AB359BULL, 0xF5EC4F92294BFE74ULL, 0x375F4A52D721DCAEULL, 0xE7FD0D0FC03AD05FULL, 
            0xDAFD214E88405D43ULL, 0x55611F2A3021B7D7ULL, 0x9145346179A64B3FULL, 0x0C0B51EB733E35AAULL, 
            0x6EEDF1F700E726F2ULL, 0x929C602A7EF8E20AULL, 0xBE697A5751422424ULL, 0x08E4593DB445ECA5ULL, 
            0xA65987CBDC24D37AULL, 0x1A0A60154166E1C2ULL, 0xCF83E31885E76DCBULL, 0x2849DF0961A55E16ULL, 
            0xEE1415E08486AF8DULL, 0x24546E2028878316ULL, 0xDCBE2F126E4BDC47ULL, 0x271B62186897981EULL, 
            0x87C222226386DF2AULL, 0xD3C14CDC0C6D9E3AULL, 0xB3266698CA4ACC76ULL, 0x8CAEE443DAAAE524ULL
        },
        {
            0xF823835B2DF90EFFULL, 0xB12DC4DF40C130C4ULL, 0x899E8D2B315E0D3AULL, 0x1FE9F57B16A67D46ULL, 
            0xCE515118CAD2C227ULL, 0xAF5C326F91EF278CULL, 0x6499EF6C78A35532ULL, 0x34BD6E4F1BD7CE82ULL, 
            0x55A95745014FC634ULL, 0x9ADD6094F3051BA5ULL, 0x7DC32821F80029C8ULL, 0x373AA53756093C48ULL, 
            0x20C5C30F9B73F2B5ULL, 0x58225A527708EA59ULL, 0x6C126F10F77E29F0ULL, 0x81EAEFB48221C4B1ULL, 
            0x21740F6B094A6C54ULL, 0xB7029D3F90833D0BULL, 0xD2C1EA9467063609ULL, 0xEF54A2A026A93622ULL, 
            0xF251BC325700C832ULL, 0xD361A3ED13D00B2EULL, 0x6116A27417DFCD7AULL, 0x23758E1EF621D775ULL, 
            0x072FC2DAB06EF732ULL, 0x604CD61C5E1092CFULL, 0xD9C60D76D65AC4C6ULL, 0x57A6B968917BD547ULL, 
            0xC61A32AB5AC7FFAEULL, 0xEFB8EEB2CB7DE71DULL, 0x99A982F91CFA639FULL, 0x633F30F36F81385AULL
        },
        {
            0xCFDF652CB83B7D23ULL, 0xC39523BD0C403EB7ULL, 0x5161E62FB5A58C96ULL, 0xA3A7C69875832F2CULL, 
            0x44B8F57ABCAB8C01ULL, 0x8F6A673A0A5CB71CULL, 0xBAD0678BAC0B25ABULL, 0xC5CA0AB28C38E712ULL, 
            0xFB17DBA9B440155CULL, 0x06CEF72B600F7214ULL, 0xD3A2C46A94012150ULL, 0xAEA22D57F87B2B5FULL, 
            0xB45B00BCA660F195ULL, 0xABFA334D2AD46B30ULL, 0x5B6E16CD87B2E5F0ULL, 0x65BFFF6229A0120FULL, 
            0x2C6C85BB28D9AC0CULL, 0x76B587688376A9CFULL, 0x6BFE8A99FD1407E0ULL, 0x66800001FF17A3B9ULL, 
            0x54AD6D476E32D7E0ULL, 0x2121E205A902CCC8ULL, 0xEDFE9A0F5FE41D24ULL, 0x819AF3720F27C585ULL, 
            0x07162E4AB3C8D32DULL, 0xE4040ED5D7558289ULL, 0x76C43E178035CAC1ULL, 0x126286C8AB31C157ULL, 
            0x7BE72D58089F442BULL, 0xA95CF39E29804E0CULL, 0xC38CE542D43D1605ULL, 0x86C65D5497BB6878ULL
        },
        {
            0x7FE2FFB8B6EF2FFFULL, 0x78615E3E7F02C4E8ULL, 0x096437F4A0F9ECEAULL, 0x06D55137F565C263ULL, 
            0x5B0C7EAD7F8E2BFCULL, 0x60C506D05595ECE6ULL, 0x0E38C32B4C7D66C3ULL, 0xE3A3407A1C49CFAEULL, 
            0xF7EC1CC5B82F95C5ULL, 0x55FFF48E3E9C7160ULL, 0x46FB2A475B777DF2ULL, 0xBC4BD71ED54F06E1ULL, 
            0x3CB86EC0E7EF4D8BULL, 0xF294397FD936E0C1ULL, 0x391CC0106CE5C29DULL, 0x37567FC29DC7124BULL, 
            0xF90EB95757262440ULL, 0x1DA077A3802CDDD1ULL, 0x0065502BF2862D0BULL, 0x5A29087533E3DCBEULL, 
            0x72F853B41FA82988ULL, 0xC8AD807FCA54669EULL, 0x352A2093800A4900ULL, 0xBA2AC9ECE7F89CE5ULL, 
            0x1D7A9F880FAD7D1CULL, 0x4DB0C8FF9BD5EC8AULL, 0x78921ADBF95D0FB7ULL, 0xCD0C8CE06FBDC3FFULL, 
            0x48B864F574834070ULL, 0xD99E5B7A99DC4818ULL, 0xD747F7013C4E3069ULL, 0x32047397DBC238CFULL
        },
        {
            0x361546AC7207C6F1ULL, 0xCF59537D739C2422ULL, 0xF4F596780FC04C5FULL, 0x81A9D881550FB486ULL, 
            0xDA3171752DF87975ULL, 0x413B875EA0C25434ULL, 0xCE87FAECFCBA2680ULL, 0x9C34C2695D76D6C2ULL, 
            0xB8BC75C5167F8B74ULL, 0xADA3463F1B5DF8E6ULL, 0x4FC57DDFF2ADBDE2ULL, 0x2A8275302842FF54ULL, 
            0x22D0D2C6B2C5E83DULL, 0x160C183EDDBBC612ULL, 0xE02821FA98924406ULL, 0x0118188C439CB2D2ULL, 
            0xD084168FF4F5A973ULL, 0x9A94A1C1F580A201ULL, 0x943DD6A0EBBBDDDCULL, 0x80BE54F7814C63CEULL, 
            0xCC9E23B3EFF2D458ULL, 0x5006CA448BCC7655ULL, 0x7EDB7D409F22F1D9ULL, 0xAFCF72FB6E6BADEAULL, 
            0x17C4F00B2AC3AE50ULL, 0xD37E37566224AB58ULL, 0xC6A414FDE2A4DF6AULL, 0x1E32A305F6586B4FULL, 
            0x8D4541F41FB0DD61ULL, 0x65E3802D15BA01A2ULL, 0x1ABF13DAE48C7312ULL, 0x784EF8BF951FF61AULL
        },
        {
            0x3ED11F527387FF13ULL, 0x5DCAA5C0489DB30DULL, 0xEA4B2B750ED580C3ULL, 0x1E8040F109464091ULL, 
            0x4E496570A0940864ULL, 0xD858E784D11B2101ULL, 0xF049EF381AEB88D9ULL, 0x8BB90EBE2FAAE448ULL, 
            0x0E2DCB5BA708709CULL, 0xC6AAA5EEF55B3A03ULL, 0x493375F5592EA558ULL, 0x13CFCFE048F0F4B1ULL, 
            0x59E0A316D4B3ED22ULL, 0x3B6ACA2C8D02AA0FULL, 0xA49EC46AABE9FB68ULL, 0x796E41F10DE1911DULL, 
            0x3B5CFD519388DD2DULL, 0x5F5BDF3830E6F5CCULL, 0x6CBEBFDDA3E0E5BCULL, 0x1C6AD1C7D7E5E777ULL, 
            0x6D6F05C988D72F47ULL, 0x0BEA8008C9D2F1A9ULL, 0x3C9FCC6B9319B623ULL, 0x469098B7CD259DF3ULL, 
            0x2582E97077C52795ULL, 0x711CCAD24E2CF327ULL, 0x08F1F14E93096B7BULL, 0xC18ECC0370605D87ULL, 
            0xB58466AE11E8FA90ULL, 0xF9591D3A96D8500AULL, 0x8A188C45EB46B128ULL, 0xCDA7ADC03CF32E39ULL
        }
    },
    {
        {
            0x7DD3E3B85D9772DDULL, 0xFE68AA3AAB4F6972ULL, 0x3E97ED0F772DB589ULL, 0x8834FC08FE06641BULL, 
            0x4A7BFB552DD1EF62ULL, 0x59CB0262138FFCC5ULL, 0x5A102BE34A9F525AULL, 0xC422D9CD98255129ULL, 
            0xAEE4CE269F36CF89ULL, 0xCB2102253E3B1373ULL, 0x4839F8A023A4C189ULL, 0xCD48BA2D07E32AA3ULL, 
            0x7D0ADECE5648C0BBULL, 0x47154E15419933E2ULL, 0x86D248E03CFB3FC8ULL, 0x5F4E8EA9640E654BULL, 
            0xBC17652E2699FA8BULL, 0xD3695DA27EAB7FFFULL, 0xD5D1D21F14DA480DULL, 0xB63D960273F9C0E0ULL, 
            0x94817EEB520A29EAULL, 0x3FD85BDFB6D39C13ULL, 0x5160A6E7CA907881ULL, 0xF3E9C1F178FD008CULL, 
            0x2780C46318F2C6EBULL, 0x9102DB6E50D78956ULL, 0xC8A789EB5A76D203ULL, 0xF0F9F1D788F17EB4ULL, 
            0x61F8F0A601E632E1ULL, 0xC1FFFFB362D7602FULL, 0x9B4C0D61E4C39A5FULL, 0xAFF1591E9ACB73FDULL
        },
        {
            0xA476C5CBC0A38B14ULL, 0x4191861943FDB0EEULL, 0x1162867F12CBD91CULL, 0xD03CEC83277F9D6CULL, 
            0xA873D0CD7BB45DFEULL, 0x7F703C157CF4C701ULL, 0x45CA25547E7ED777ULL, 0x559298B2AC44D399ULL, 
            0x2CB22922C4A9E48EULL, 0xBD418D5A65050696ULL, 0x73F96831D338C4CEULL, 0xCB0DC3344DDF7E9AULL, 
            0x1DC429EA04111384ULL, 0x193705B2A3993FC2ULL, 0x96C57DD129919500ULL, 0x3B1AAB6CDA4B1622ULL, 
            0x545B3ACDEA9471C1ULL, 0x1179034528C04A34ULL, 0x5052F3F854E1EDFBULL, 0xBEF35B30AFEF4D46ULL, 
            0x4FB5AFCF1D77BC90ULL, 0xB838B8EB7B838FB6ULL, 0x098977455644BE03ULL, 0xBF5475884D762986ULL, 
            0x23933A571EFFDC67ULL, 0x608EEEE6ECBD42AAULL, 0xA633DEB72045B61CULL, 0xFC93021192544292ULL, 
            0x0C7521FA6EEC70E7ULL, 0x1DFAFEBA5112428DULL, 0x87465F88356A0FB4ULL, 0x720235DC02BA9350ULL
        },
        {
            0xD9F37140FDB754B2ULL, 0x0AF63BAF8490BC94ULL, 0x3510F5680679555EULL, 0xC2DAC70DD938C975ULL, 
            0x7A8FD78E66FD6600ULL, 0xC877D10EBFD5DFC9ULL, 0x68AE9A49B437B089ULL, 0x7DDAA7DF1EF188A2ULL, 
            0x46224E448FEA4C44ULL, 0xF32214A96C9E4EECULL, 0xD634BF2206DF2015ULL, 0x7E60D671B64C4E52ULL, 
            0x532749FFB95FDEDFULL, 0xC622B37B829EFCAFULL, 0x6C60686BB43F67ABULL, 0xB12BF45872AC0B3CULL, 
            0x84EC9AD069CA961EULL, 0x8D3D113120E99D6DULL, 0x97D7D73766E43256ULL, 0x7BE6994BDFB25415ULL, 
            0x3D8DD7C21F6B27F6ULL, 0xC2C87203E4F73977ULL, 0x37329207C3BF9A2EULL, 0x624027C66C7DF269ULL, 
            0x6CA72BCA6A2CAF62ULL, 0xB9F8C7762C85927DULL, 0x9FCFB960D0E36779ULL, 0x944CE43F1311AD31ULL, 
            0x5A68C2976FC1FFEDULL, 0x19C7055B2A9C0884ULL, 0xD767DE282E02C4FAULL, 0x8A456317C7D02EB9ULL
        },
        {
            0x75E333801885D4AEULL, 0x6C6EF5D6915E25AFULL, 0x145FEADA31B63752ULL, 0x7387EED619DD1B09ULL, 
            0x64847C9FB90BE3C6ULL, 0x1D8027B3941E64A0ULL, 0xCED444E6B376C722ULL, 0x971B6DB9CD9BF746ULL, 
            0xF115CC66C2EEBE76ULL, 0xF54445EC1A2BAC8FULL, 0x27863D63CE7052F1ULL, 0xCED0EEEA384E92DFULL, 
            0x7BAAF59B2693163DULL, 0xACD3B89072417773ULL, 0xC739BFC829969683ULL, 0x030686790083C938ULL, 
            0x1F7F9C0C9260A4E3ULL, 0x35BEC077A6C5FB7FULL, 0xE848DE0D8FAF760BULL, 0xC88C1E427F94AB17ULL, 
            0x76BB202B3CEAC8B7ULL, 0xFF0EC0BCD866A45FULL, 0x13929B0128D2410AULL, 0xB6C96535B50460DAULL, 
            0xDA77DA423D78D505ULL, 0x53E3FEDEF9217591ULL, 0x25CE069457FE5E39ULL, 0x7003979C0E0D5CF2ULL, 
            0x6084E1E38BC3B27EULL, 0x0BF7D3C7528D53B3ULL, 0x8BB9CC4FC80A460CULL, 0x0CD44B70D7F88F39ULL
        },
        {
            0x5CB5CAF2F806F6D7ULL, 0x4F4BF686585E8DB4ULL, 0xE22C1E3DD7E059DFULL, 0xFAE6598B45C5F0A3ULL, 
            0x057A4D8C374DC59EULL, 0x6A4CD33FFFCA7A35ULL, 0xF5CBA773DB527A50ULL, 0x20F75FD2ACF33354ULL, 
            0x0FF3E3C20FB52A37ULL, 0xAD8983F077FACA4AULL, 0x61D3232D484C294BULL, 0x4004CAD9A09F9909ULL, 
            0xBC0B25361955405FULL, 0xF8758EF74D7893AFULL, 0x492F53AB0F4E2DC7ULL, 0x0356473F3FA72F7AULL, 
            0xFE3716EAD3BCDF95ULL, 0xC3DDF17946849593ULL, 0x1A0EEA4DEB4E092BULL, 0x11B80A721EF8780DULL, 
            0x4079B6C80AA40ECDULL, 0xDF38CF03DEA15B53ULL, 0xEE0402561D6F40D3ULL, 0xBB40F0A2FD571C58ULL, 
            0x53F7B9D776BABAEDULL, 0xACE9AA9556375AEBULL, 0xDC63B1D8BF39641BULL, 0xEFD5BF753E2186EDULL, 
            0xD239934C1D955E5BULL, 0xC9AC1BCD74F51630ULL, 0x76534B0885606130ULL, 0x9491E03CBBA810ADULL
        },
        {
            0x79EAAD49CF9C1AB3ULL, 0xB0CE77B96D953089ULL, 0xBA0ECB14B429A134ULL, 0x4EC9516E6E00AD73ULL, 
            0xFF728743AB613742ULL, 0x52E3AFC840D78E72ULL, 0x1A32EE804AE47245ULL, 0x4988C5EA70D04CB6ULL, 
            0x79B9202BECBF0447ULL, 0xCC5CBB043381F57FULL, 0x1FF39F58FD163483ULL, 0xFC7AD2783A02A9B2ULL, 
            0x3DF13CB656DACA20ULL, 0x4AA7B4B94E14CDADULL, 0xDBB0C3D112711679ULL, 0xE0014CCB851EF085ULL, 
            0xDCE8F8DFC2305925ULL, 0x9C08541010B6AEBEULL, 0x913E8A14536ACC7AULL, 0x490084196803761DULL, 
            0x30979F1692DF2377ULL, 0xE99BC46D2E47A7A0ULL, 0x569169F8A73F3B79ULL, 0x010392144B4FE892ULL, 
            0x2C738C999E31554EULL, 0xAD6F7BEE0279FE9BULL, 0x752A2A6D4159A776ULL, 0xB3790B3F1B68D7EBULL, 
            0x84F73026CA5E2B73ULL, 0xE099ECA5FEB0B310ULL, 0x7FE46F93C9680449ULL, 0xA9FEF7AE712AD4F6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Procyon::kPhaseAConstants = {
    0x3E3927C53A0EF434ULL,
    0x48B85248A824B3A9ULL,
    0x24598DE503503111ULL,
    0x3E3927C53A0EF434ULL,
    0x48B85248A824B3A9ULL,
    0x24598DE503503111ULL,
    0xF514B0616AAA9FB0ULL,
    0xCF1677F4C1775C02ULL,
    0x27,
    0x4F,
    0x30,
    0x0E,
    0x9E,
    0x62,
    0x84,
    0x47
};

const TwistDomainSaltSet TwistExpander_Procyon::kPhaseBSalts = {
    {
        {
            0xEE128AF5F7298FA0ULL, 0x9965B2865E9BADF7ULL, 0xE59BFE00E5690326ULL, 0x73F2BB18E75DE883ULL, 
            0x8F9DC21D14141961ULL, 0x621E11C9AC396872ULL, 0x966A84DE52EB572BULL, 0xE708C894EDB9BC4EULL, 
            0xCDE94638EE49DCF3ULL, 0x3FF2D4A88EBDD03AULL, 0x63D95D069DCDD7A1ULL, 0x0B1E74D1C52CF7F0ULL, 
            0x1D52221E6A2E487FULL, 0x9A50538CB14EA1BBULL, 0xCFE5C412675FBEEBULL, 0x6BEE181F548082D5ULL, 
            0x147BF70D3E9C8DCCULL, 0xE657FBCC01EBD70AULL, 0x0DD9F5F8F8CCB6A4ULL, 0x542CE084EC0A4EE9ULL, 
            0x21D2E6CDF777D7A9ULL, 0xF23AC48353E1B0B0ULL, 0xBCE6A622F1168C33ULL, 0x8ADAF279107A71D3ULL, 
            0x25ACA6B30AFDF89CULL, 0xFCDAA15090D85C77ULL, 0xD9A84AEF339F39FEULL, 0x30C8A7E846E240EBULL, 
            0x5F36177EB7CE663AULL, 0xF5F7AB6BCF33B6FAULL, 0x30E8DE94EADECCD1ULL, 0x7B0DE654F1D58B63ULL
        },
        {
            0x43ACDD8B2028C412ULL, 0x413AFB3833C09546ULL, 0xCCAF0598EF5796A7ULL, 0x3B3B6B8D2AD134C6ULL, 
            0x640FBB424FDE2C5BULL, 0x1BFBD382A7D06382ULL, 0x194F6C2675F23ADEULL, 0x3EBF09A893E6E13EULL, 
            0x93137D9A19706FE2ULL, 0xC7BA88C068E95C98ULL, 0xFFE0E581D369EB7CULL, 0x643F0A0FCB1AC452ULL, 
            0x68BB0E6602E4F90AULL, 0xB7ACA118A6728F9EULL, 0x9C7C4EE90559F2ADULL, 0xB9D25BF44A3F95B3ULL, 
            0xC25BC409FBA3327CULL, 0x8CB48E303410C125ULL, 0x21B93AD6B38D3B9DULL, 0x1D98881AC480D5D9ULL, 
            0xBB0D5EE3BD5A615CULL, 0xBCA57F2A15C2AFE0ULL, 0x653F0DA0AB22EF36ULL, 0x9092AEE3BB5C32D5ULL, 
            0xA5FA46A226C19F97ULL, 0x4C9C50F1167AE74AULL, 0x93674A61A6236A32ULL, 0x28D84353FB3F36C8ULL, 
            0xC15D54C5CC6F78F5ULL, 0x034557B68F48AACAULL, 0x71D7B532EF3336DAULL, 0x24EDFD24AAC12910ULL
        },
        {
            0xCC91A4E5DAA9BF23ULL, 0x9A0EE8A163714CF1ULL, 0x1D54EBC244A6DD9DULL, 0x5E9E5BF21A5EBC46ULL, 
            0xD0F94205A9550B3EULL, 0x0851BC86D28BE68BULL, 0x2ACB83C9A4BB14A3ULL, 0x3A4B0D23A5C899C9ULL, 
            0x6812F3FD9D749A25ULL, 0x85DFD704C26900D5ULL, 0xE613A42C6C1CC45AULL, 0x373FE2FA837C482FULL, 
            0x433DAD58B9C233FEULL, 0x7405E8E62ADB03CAULL, 0x4D2169A9FED29555ULL, 0x3356E487D9FA1BEBULL, 
            0xD5D3AB7DA4401439ULL, 0x86A34BB5A24AF6A5ULL, 0x4DD81F969879D61BULL, 0x835F0C333939D6FBULL, 
            0x6EA61C0C950A7197ULL, 0x1A4BE018BC8816BAULL, 0xDA15B6C8B6EF8DC8ULL, 0xA453886D164EDFC3ULL, 
            0xA84D5BD57CA38510ULL, 0x08B1F0F8E179C408ULL, 0xADB59E9D45B908BCULL, 0xE4457BAD068290F1ULL, 
            0xED9FEACCE086FC4DULL, 0xD94E64A561BB3B9DULL, 0x9B8F01043C4EE344ULL, 0xFD837E7C2F07B85FULL
        },
        {
            0xEB8C3836404D3F4EULL, 0x7C0E06D8341D82A0ULL, 0x76AFF52B8FF3ADC3ULL, 0x7A48DC7DAA96A580ULL, 
            0x3A59E1AF84256C05ULL, 0x5D709D2AE7834552ULL, 0x1F54C00B5B74B5C7ULL, 0x56DD963AC47F5E31ULL, 
            0x1A7FE5064701377BULL, 0xA75E4D0882AD0E55ULL, 0xBD1A153322C5F0A4ULL, 0xEA822C2BD6283B27ULL, 
            0x155FE42BC6B185B1ULL, 0xE3776DFEFA183ABCULL, 0xDBA16F36B767B1C6ULL, 0xF374855D89D92375ULL, 
            0x4600A043A9B6A208ULL, 0x0024F3136E5D1DDBULL, 0xB691F783B4E4FB34ULL, 0xB8BDA82A20277B8BULL, 
            0xF90730D6A2DC893FULL, 0xEDE4AB41DC4A9D54ULL, 0x099A0C5ECCF40932ULL, 0x1A42A7016429A850ULL, 
            0xB8BFE32834692312ULL, 0x975E1CA75FC159B6ULL, 0xB4DC6E3A3838DFBFULL, 0x05488DE584AFD120ULL, 
            0xD057E3405BCB7558ULL, 0xB96BB93626D55FE4ULL, 0x11B2C6AB41971085ULL, 0xBB67158BB6A02E5EULL
        },
        {
            0xF7A993EC037F02BEULL, 0xD35D3CDD2D714EA7ULL, 0xFD46E13D64BC7C87ULL, 0x7CC5C2F9E455C835ULL, 
            0x5847A2340448AFF4ULL, 0xFB9740C436CACC0FULL, 0x31D7DC52EA31C8ADULL, 0xA3EFAF76D673B812ULL, 
            0x572757C7C7503D9EULL, 0xAE16E29EF2DB47F6ULL, 0xF1D1A639A8AF2D2AULL, 0xC4A857784A0A5CA9ULL, 
            0xF2694F095E1437F3ULL, 0x2E96C0EF3BC826EEULL, 0x93A8519AA20D491EULL, 0x0530015910655B5DULL, 
            0x7990031014A92BF1ULL, 0x5174D4AF0D8ECAD4ULL, 0x8876983560ECB58FULL, 0x35E44AA618F4BB91ULL, 
            0xA91115453E4D41CEULL, 0x9D46360FDA9421E3ULL, 0x41D7419147F9E014ULL, 0xBDAF102A383E584EULL, 
            0xECD55F3B83DE57B2ULL, 0xE24D4DB59B41D732ULL, 0x984760CDE47A8288ULL, 0x15D40FC13B47A23FULL, 
            0xF5683809AC846466ULL, 0x5CD8AA260EBB869CULL, 0x411BAFC0115C5746ULL, 0x74B7AD739ADEF2EBULL
        },
        {
            0xBBD15FF054FB2DC6ULL, 0x8F09B439515F972AULL, 0x4D905A8682DA085AULL, 0xBAE13FF6A5EE273EULL, 
            0x9168AC381BFE7C6FULL, 0x0BE9E56A18E8A7BDULL, 0xCA1EA8D546B94A46ULL, 0x92EF1F3C81C7E030ULL, 
            0x72504D279C5DE2E2ULL, 0xCC189D42171486FDULL, 0xFE371188659D4B79ULL, 0x8B01D62B8A5FC226ULL, 
            0x1F8743D0AA20FB51ULL, 0x622FF885FE68700FULL, 0x3A3D41F39F3798BCULL, 0x5C00B12EDC13799DULL, 
            0xE4BFC4EB7BEF4863ULL, 0xCC70F35794E7F6B3ULL, 0x7F924485F2DBC1E4ULL, 0xBFACEDF66CBEF173ULL, 
            0xFF969C70C7108E42ULL, 0xAEF15682EFE2C76AULL, 0x7D3738296A003B19ULL, 0x97433855620721C3ULL, 
            0xAA6D274CD71F4F6DULL, 0x4950A3A7FAE54003ULL, 0x507830D92C3A1C47ULL, 0x8BDEDFFBADF9C405ULL, 
            0x362A9FD6D2C4BE54ULL, 0x2A0C2A804E2D7482ULL, 0xEFAEB45A00326FDCULL, 0x228A7B4708F65FB1ULL
        }
    },
    {
        {
            0xAF463B8F76C119F5ULL, 0x57306D9E619D6FD7ULL, 0x7647B078D6789D7BULL, 0xBC460313AE11F647ULL, 
            0xB711DAB90A51C108ULL, 0xB63058C18F205E8FULL, 0xDF3A03B813ABACCCULL, 0x4DB373172BE5F5E2ULL, 
            0xB3242E86B07AA281ULL, 0x1C770B6E42D0EC1DULL, 0x0FD4065A0CDF1678ULL, 0xACC51A855E20CEEAULL, 
            0xB56EC73C838C6684ULL, 0x3026DF5C74B5C4AAULL, 0x4F09DE0E297D8AEDULL, 0x7AB70F24EC5C9F63ULL, 
            0x7B45ACF3000C4B4DULL, 0xAB281140EFF055A8ULL, 0x09B978931201C742ULL, 0x54029F05E93485E3ULL, 
            0xAE1F9DAEE7DD6513ULL, 0x31F066BC2CCEA40BULL, 0xFCD3242C2BF98C24ULL, 0x87C42ED6206551E7ULL, 
            0x5ECA4F074C118359ULL, 0xA5E35064F11C09B1ULL, 0x04F14310634D27A7ULL, 0x99424928576A033CULL, 
            0x297E58FC08227F6EULL, 0xE5841CC9B7ED2677ULL, 0x788E168F20603DB0ULL, 0x3627A84AEC52A2F5ULL
        },
        {
            0x78544212D1894C27ULL, 0xEDCA0BBD665D5217ULL, 0xC8F66D01319555A0ULL, 0x958A7FC490BC0F2EULL, 
            0x4D5CDFEC8B0EFFE9ULL, 0x303A1BA503DE1C57ULL, 0x16EE004349F4C2F5ULL, 0xC3767FE13D9DB0CAULL, 
            0x39BA2B92DD8F67CAULL, 0x4D4906CCEF4B3838ULL, 0x6E0A96CB96100882ULL, 0x60F174E0AD7EA9C5ULL, 
            0xBF869D65B92A3813ULL, 0x6190479A6A3C039BULL, 0x7B1B2A5CED59E58DULL, 0xE028078086725CA7ULL, 
            0x452D8AAAEA8C7A03ULL, 0x9092B0AB55FE3377ULL, 0x0A8D2132C1B42A1CULL, 0x19EE03CED83708F2ULL, 
            0x3DFA583510FAFE2CULL, 0xF9DEC4714931DE83ULL, 0x7B5CFBD71E2371E5ULL, 0xDD1A37AA526DB313ULL, 
            0xB295C831EBC9E18FULL, 0x47E847F05DAEBC66ULL, 0xFBCB540736057006ULL, 0xA9562C6B4F8B86BEULL, 
            0xDA58BFFC184CFAE1ULL, 0x35FA15C32391C9CEULL, 0xBFA7D9B26BA7AD44ULL, 0x70843506A6277F2AULL
        },
        {
            0x9F4FE4A516AC8FEBULL, 0xE2B0D1D44F22C2C7ULL, 0xA68B0E6171E9C39DULL, 0xA2186E9B357B3E56ULL, 
            0xF525FC6B06FC6A53ULL, 0xCE95FDAF4575A714ULL, 0xF0CD68B0FFC5AC17ULL, 0xDCCD63519F74DEB6ULL, 
            0xA6DD987834E5C9C8ULL, 0x4D2B86DDECAE7D30ULL, 0xD4328B7B69F2595BULL, 0x81A24042E135271CULL, 
            0x06B04375EC661A1BULL, 0x8550501369AC4E27ULL, 0x4C5F3E86E25FA718ULL, 0x60F51F9FA78D070BULL, 
            0x77900B1286453C8FULL, 0x8E371AEB2BFBA05FULL, 0xC6618561D7FE85FFULL, 0xAFCCA60D2A427B27ULL, 
            0x08E758C4015E10F6ULL, 0x20334D0EB8229102ULL, 0xB50FB007C56844E4ULL, 0x4FE269F4536A96D1ULL, 
            0xC4CB8D2A4A990B58ULL, 0xE02B02D56E09D830ULL, 0x57EABFB00DB6DCB9ULL, 0x0EF33F7A91220E02ULL, 
            0x3989D85D3D30BB8FULL, 0xE0C93E438EB967EFULL, 0x7B41DC03B64075A4ULL, 0xD5FF23E375278231ULL
        },
        {
            0x73B0024146B3E4C7ULL, 0x2E8E7AA6816F8C89ULL, 0x05E9E8975D0F5DCCULL, 0x980F001CEC86E618ULL, 
            0xBF8A26292E8F2805ULL, 0x9BF4FE476D8D12F7ULL, 0xCE8EC88E899BE13BULL, 0xB4044E4FE8D9F424ULL, 
            0x8FF1C5851866284FULL, 0x24C3180FBB154C3FULL, 0x90680F004C2CCDD3ULL, 0xF2D450330DEDAF9DULL, 
            0x936FC4AC44873BF4ULL, 0xBD411B96C72BBE8BULL, 0x1AB682789A46FAB6ULL, 0x5440D93BFCB37489ULL, 
            0x5756A44926187789ULL, 0x0471C241CBE5AFB7ULL, 0xAAC5BFF5B88C6951ULL, 0x93DC6AB91DF9B9BBULL, 
            0x6146AAB3E0EB2C09ULL, 0xF109CCFC9809F112ULL, 0x0CC6B7194EB51D63ULL, 0xC382F4C6384D978DULL, 
            0x32E7F23E0F70E151ULL, 0x08AED1927ACC495BULL, 0x7C21B8B6367464FEULL, 0x33A53150F112706FULL, 
            0x8655B9084A70488EULL, 0xD2D25824A5FB829BULL, 0xB7FEB0DFD980103CULL, 0xF25C6D7AA2CB8D1BULL
        },
        {
            0x615E95134A0E9EBCULL, 0x3526D27C3E3BAA89ULL, 0x6E650317443D549AULL, 0xBF50FA1956584FC5ULL, 
            0xCE942F16B5D19A6EULL, 0xDF1FBFC96A4B601DULL, 0x8BC96D9B0B5BA0ADULL, 0x15E8D8C40FD9559AULL, 
            0x5F5E4EC3236AB971ULL, 0xECF2BB423208A5F8ULL, 0xB9868A913D158052ULL, 0x18667FFE5CD44932ULL, 
            0x6585E04BFB20E279ULL, 0x2C99596D2FC6B661ULL, 0x74F41705C6C03746ULL, 0x6555C129F2E532EAULL, 
            0x6C1E9AC605B8CDB2ULL, 0xAEC71AB4B2E43266ULL, 0x90A6EFB6A6D9A5C9ULL, 0x80AE7D8897D131D9ULL, 
            0x33A18CE57DC13E20ULL, 0x0AB3979FDE6EA072ULL, 0x37D3DEB4640397B8ULL, 0x17125CDDC16697C7ULL, 
            0xFEEA7978F9AA9FA4ULL, 0x6D0A8D40DEB60686ULL, 0x5CD6A46AD2183676ULL, 0x03B2F50F97EB306BULL, 
            0xAEEB6FE649E882E3ULL, 0xED936E5C47835C81ULL, 0xACEEFF672F33BACBULL, 0x380BB5F55D6E7F00ULL
        },
        {
            0x9154732504997B49ULL, 0x6FBA8C0E0D422368ULL, 0x7D9DC850EAFA8276ULL, 0x6CBBFBC97B7AD26FULL, 
            0xD972093200DAF3A4ULL, 0x913D338CD68F179AULL, 0x441D4B81A9265503ULL, 0xA36BCB429DDFCD16ULL, 
            0xC02F7EF23711E8B5ULL, 0x4275968E235DFD21ULL, 0xDB397630B9A29BD9ULL, 0x3CA1D2BF14744C23ULL, 
            0x6A59824FD116D0E0ULL, 0xC6B1626F2DB4B1C1ULL, 0x86B357196E82CF9EULL, 0x3A76A8B8BE2063D3ULL, 
            0x89B4426AA3B80EBEULL, 0xD8E85A32ACEBFD8CULL, 0x89F8D83C3790A1A9ULL, 0x62070C2FB69056E8ULL, 
            0xDA1724F33ABE23F1ULL, 0x8760C83E2C7DD169ULL, 0x2D8EDBEB80926ED1ULL, 0xD48D1551A683C468ULL, 
            0x95A48508FC05612DULL, 0x9EBB1471AC5225E2ULL, 0xCF22947633D8FD68ULL, 0x758D1FEC9F5364ABULL, 
            0x9B2A66443AA434E5ULL, 0xDF869CF6D7BF5CE4ULL, 0x9DF23FFDB1DE3AA8ULL, 0x8409CD09D95CA535ULL
        }
    },
    {
        {
            0x80D73A89DA1E17DFULL, 0x0FE3687D824B0A93ULL, 0xF64D3BD04865444EULL, 0x2D2EE3D135AA1DD3ULL, 
            0x0A7C8713E8836467ULL, 0xAFADC36A1611C956ULL, 0xCDDE9221D3FDBD9DULL, 0x4CEE20A001BDD1F7ULL, 
            0xF7A7B203411D306DULL, 0xB145F2E552E66E2DULL, 0x67F2A81A123F151EULL, 0x5F803829280C2E49ULL, 
            0x474F65111B0B5476ULL, 0xD42A7ED070405E21ULL, 0x1E7B54AA7AD8C78EULL, 0x050CF1611F0CD54BULL, 
            0x6F324BB310FAAC14ULL, 0x1634C3454834F233ULL, 0xBB978F0A7324FB4CULL, 0x1881174EC7279A70ULL, 
            0xB84C69211BA1F1BFULL, 0xAAB3934D4B469798ULL, 0xA2A8785B25266EB5ULL, 0x80E3D0B87636E236ULL, 
            0xB0E63020E53AA189ULL, 0xAA66BF6DB6FC904EULL, 0xFB53BD9F7541EC45ULL, 0x9B4CB82A72C663B5ULL, 
            0x05A4FA20EBB853A6ULL, 0x414A289CEB8DDB91ULL, 0x0A141E775F62BE0CULL, 0x5A6CC8846F078A45ULL
        },
        {
            0x0C8BB575707266C5ULL, 0x2CBAA023A78ADEDFULL, 0x04D17E55F10AB2A1ULL, 0x3B16B90924D0FCEDULL, 
            0x3A32C36556A5175EULL, 0x6EE9943235799C2FULL, 0xCCB4A93D8DA39505ULL, 0x0696E93D44F78224ULL, 
            0x280FBDEAA58197CDULL, 0xBAA23A15FFFE5594ULL, 0x2DBD7FDE07F1C02CULL, 0x5CA9003CF6542AD5ULL, 
            0xE8E37001903B0EA9ULL, 0x5FB4710A9D9529BEULL, 0x1A16EE137909FD2EULL, 0x3A66D348A67DAD6DULL, 
            0x3CB870C978F2A277ULL, 0xFFA3544A52BB22A5ULL, 0xD53BA7F8A4DD5CF8ULL, 0x0756522043D6871BULL, 
            0x7E4F00E8510EA2D3ULL, 0x2B090D1A66C16CB0ULL, 0x3A9E67B05966221CULL, 0x340C8352F7082595ULL, 
            0x6917A07F42B7AA46ULL, 0x89F4C423F52EE020ULL, 0x88992AD591E42B3FULL, 0x379D6944AFFB13A8ULL, 
            0xAF1CA722068BBEC5ULL, 0x71C9C189359192D2ULL, 0x3CBC122E4FFA1BB1ULL, 0xFCD930A826F2D3A9ULL
        },
        {
            0xE6FDEB526589708BULL, 0x88906AC70CB97F93ULL, 0xB7BA91E659FF8F87ULL, 0xA97F891889FCC33DULL, 
            0x58061CF89A825743ULL, 0x44572361F5B5B7DAULL, 0x8FCCD3383A6B4EEEULL, 0xCB782FCB3A63BEEBULL, 
            0xB75E20E8196D24A9ULL, 0x740FC6CC9107BE11ULL, 0x541553FFFBE898F2ULL, 0x0C7902BF503DEEF6ULL, 
            0x75414B2D70B3B11DULL, 0xEC48A8F2D06777B0ULL, 0x7002F1BDFC13CE1BULL, 0xC9D7574128BC170BULL, 
            0xB2062A4059E06492ULL, 0xC09AF0C0BBB556B2ULL, 0x64268727473470E4ULL, 0x11C5B0459A9B3D14ULL, 
            0xC6637647F06CEA81ULL, 0xEEC9D4501395E65BULL, 0xE0DF929217DFBF41ULL, 0x4E595C58C6B43B33ULL, 
            0x479209C3CDE404EEULL, 0xD3934897E81B19BEULL, 0x77DF1232931FB738ULL, 0x5EF5957C7E65357FULL, 
            0x7B7942AF221C1095ULL, 0xFFE6CCE68FF98396ULL, 0x3D4B261A9C7D5146ULL, 0x7255E600199F9965ULL
        },
        {
            0x9C86899535866D05ULL, 0xC2E2B0A533C74E23ULL, 0xB5B3EAC8FA06F169ULL, 0x29831353F96046F2ULL, 
            0x580B500280FB16A9ULL, 0xC3E83B3158377CCEULL, 0x489450CB3304863BULL, 0x6B8FD6D7AD344FF4ULL, 
            0x39C65BE0650F6E8BULL, 0xFEFEF7BB9720CE11ULL, 0xDB7632B20CDDD62FULL, 0xCCA33111310EFE59ULL, 
            0x80C0396A5FF1FD8CULL, 0x5EC0988CE6D30FD6ULL, 0xDBA1DAC7C98A6737ULL, 0xCF13877807049D2EULL, 
            0x1D3AC22C58CCFB9AULL, 0x2B28D3DA2D164E45ULL, 0xEDDB79338BD0CFE9ULL, 0x311DC6C155B93C56ULL, 
            0x462B517F63161646ULL, 0x3D4E2080E704256CULL, 0xF545A083DBD8BDDCULL, 0xDB335B9FA43CFAADULL, 
            0xDE916EC12C7205B8ULL, 0xA45160858CC6D450ULL, 0x9D2C9BBB71279601ULL, 0x6C05092F2AC62C80ULL, 
            0x4B3D6BDD2C8B5899ULL, 0x8B72559363F9979DULL, 0x75FFEB8BEA24BB0FULL, 0x08D5CC2DD4F91269ULL
        },
        {
            0x8BB2D31228FDA1E2ULL, 0x03B3F9534F78253BULL, 0x252E10E80714E5DEULL, 0xB406392ECFCE7E3CULL, 
            0xCA5864BE34753521ULL, 0x34554C2E88FFCC76ULL, 0xC0CDE086089C6F3FULL, 0x8C66426FBD2D055DULL, 
            0x993E32A35A9169CBULL, 0x5579065ED15B7A88ULL, 0x6B743FC26E1DBF0AULL, 0x962CC81966ADD292ULL, 
            0x03D5B76420F17A82ULL, 0xD0B958F3184F50A7ULL, 0x554D9BFCEF7A3046ULL, 0x8F3B2305EB989B8BULL, 
            0x06BA59F02E7983F3ULL, 0x493371488E6D2A09ULL, 0x698F51D5637119B3ULL, 0x6A13C432BD1A3DE3ULL, 
            0xBECE33D8624B3329ULL, 0xF3CF7030D3AB2511ULL, 0xBAAFFED63CA37D67ULL, 0x8C65AF95A40483DBULL, 
            0x530DC29193003E46ULL, 0xBBD2AD60109BB1DBULL, 0xC281B0E62F0F408AULL, 0x9A8E9CA2586C89B7ULL, 
            0x0DAFCB13854F1341ULL, 0x899F567FC954EAC4ULL, 0xC60F455583AE117EULL, 0xB8386A5F95792346ULL
        },
        {
            0x4D61D890F257194CULL, 0x47BF1D8D7F88CCBCULL, 0xF3F18E98860CEF70ULL, 0x4F70FB546350DAE0ULL, 
            0x67332C49B2101A92ULL, 0x985B864A3D4A9E9FULL, 0xB4D7C639519059BEULL, 0x911A2D3A956FA4C9ULL, 
            0x1187238563961DCEULL, 0xB4D15698769778FBULL, 0x58DD8FEF951131ACULL, 0x8CF5F4FA0A10CB2AULL, 
            0xCEC5E7FA38BB0057ULL, 0x64E3954694A0A7FBULL, 0x435E3E5CA78BCC42ULL, 0x75896B082975076CULL, 
            0x56BB28794927B8FAULL, 0x396FA3B1EA881DBEULL, 0x4106C0397991D4D1ULL, 0xDCCE114AD23DCF25ULL, 
            0xE18FADB8628DD951ULL, 0x58C4B18FB4F99CB7ULL, 0x977002079ACB9167ULL, 0x278A80E3F0B7BDC0ULL, 
            0x6DA475215F4B6C06ULL, 0xD13C08D82A9A3EAEULL, 0x55B754468B52C80CULL, 0x9F0717BECB1CD063ULL, 
            0x9998AA80AF6953D8ULL, 0x40F909DD1973A346ULL, 0xB6D1EE25293FEEF8ULL, 0xC02BE5BA8D4D70E0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Procyon::kPhaseBConstants = {
    0x6DE73A5AC24CCF3EULL,
    0x7D6FAC9A7A7A820FULL,
    0x74461451F85C1CE8ULL,
    0x6DE73A5AC24CCF3EULL,
    0x7D6FAC9A7A7A820FULL,
    0x74461451F85C1CE8ULL,
    0x4073411C7FF6EB1BULL,
    0xF30E4F4BEC629810ULL,
    0xA7,
    0xA3,
    0xBE,
    0x73,
    0x02,
    0x66,
    0xBD,
    0xAB
};

const TwistDomainSaltSet TwistExpander_Procyon::kPhaseCSalts = {
    {
        {
            0xBC7FDBBD12A2E189ULL, 0xB077FB4D72B53CD8ULL, 0xCD1995FBEA50B7CAULL, 0x2F9C5EE47CF0E527ULL, 
            0xE62F0F144145BBCAULL, 0x6F2AC3F0FAC1FD9BULL, 0x3CC5BC3D820FC937ULL, 0xABEEB7BEF661C724ULL, 
            0xDCB90F58044C658BULL, 0x8E4038F435A6931BULL, 0x038E3147D3D69D06ULL, 0xD66167366293CCFCULL, 
            0x07FE36F9DCC0185FULL, 0xBDDB0B18D6B83893ULL, 0x8FE47111BFAF57F2ULL, 0x1059DA495444F2B4ULL, 
            0xC1B89F87A44F3181ULL, 0xD5FEB8BD2D6747F0ULL, 0x11FFD1729656A37CULL, 0x7B1EE356DE160D7BULL, 
            0x32BB72CA4E9493A9ULL, 0x364279FDB5CD642AULL, 0x7352EBA05EBBFE71ULL, 0x91DEE3DFA715A6BAULL, 
            0x593DE3B1755AAFCFULL, 0x5E63E01D5AC1F888ULL, 0xBC0D021F8C6077C6ULL, 0xA700649C0AE4917AULL, 
            0x5054E4A462D96687ULL, 0xC1F89890E7FE7D2BULL, 0x84DBDFD0391EB11BULL, 0xA588D13872EC0951ULL
        },
        {
            0x86A1BF2C671FA1D3ULL, 0x4E842979523DAF3CULL, 0x8114EBC6540E74D8ULL, 0xEA3FF4429E246099ULL, 
            0xE854DFD00FEC5503ULL, 0xA66F6BC9811A20CDULL, 0x116CCE99648EF93FULL, 0xAEF0406A476FA6A7ULL, 
            0xC051C58C230161CEULL, 0xCABF0AC0B699BD43ULL, 0x3EB56803E848A6E1ULL, 0x9D9138B9D81A8B98ULL, 
            0xFAB690BE5C82436FULL, 0x2422F7BF81439025ULL, 0x7FC799C8BFE82D89ULL, 0x096EB7297E6AE9FFULL, 
            0x1F60E39DA23D46C1ULL, 0x0B3591B4869CAC68ULL, 0x7A3CD5D3A4D40521ULL, 0xDB0C1FBF217B4AC3ULL, 
            0x89E4F1CB954C1A9EULL, 0x9CDE47D85F26388CULL, 0xDB42B9BF5B7F1865ULL, 0xB3F57D7A43A58B76ULL, 
            0xF68F73CBDAB49671ULL, 0x080EDA2131F32E43ULL, 0x34D56310B63C6865ULL, 0xF2077DA0F046EBDCULL, 
            0x5946DABD0B85DDF5ULL, 0xAAE384CA983132A2ULL, 0x918A47702599A420ULL, 0x86242CCAE669E3D2ULL
        },
        {
            0x8CF886FA59F30F80ULL, 0x7875002DF73B649BULL, 0xD58137F4486A4577ULL, 0x177A7E63624EC5F0ULL, 
            0x2088E3D365244A77ULL, 0x856DE04A65C891B9ULL, 0x78E7C5805BF0E157ULL, 0x38D88BFA2AB77EB5ULL, 
            0xF21E6627C620076AULL, 0x1B4058B57BA1DEB1ULL, 0xB59D293D3044FA1DULL, 0x03A2AF9BB6FA9DD3ULL, 
            0x874F5BEF105EC70CULL, 0xD76B746862728AEEULL, 0xC9AB9408D8BD1569ULL, 0x0F862541B291C729ULL, 
            0x8BD9F232B27CAD9DULL, 0xBA780EBDBFCB616BULL, 0x27B5E92868073804ULL, 0xCC336A3726308E3DULL, 
            0x1A1ED495C011B50DULL, 0x8F8ED5CB0E5F6816ULL, 0x21AD3B33593E4768ULL, 0x1CD998DCF3C27285ULL, 
            0xC4A4FCE02149194DULL, 0x5B7EDCCB551936DDULL, 0xC995A8FD74BB1676ULL, 0x7E0344ED574BAEFDULL, 
            0xA3C37247DFB4F123ULL, 0x43348BEDABFEB672ULL, 0x43F0F8F7EDB5295DULL, 0x9FFDB05029FB72B3ULL
        },
        {
            0xA8478A2AC76A3444ULL, 0x6800CE86DA0AAF17ULL, 0x29BC7B278E276D34ULL, 0x65B1438F65932A4EULL, 
            0xB15D747D0CC0FBC8ULL, 0x8996807DE101F5F4ULL, 0x7034D836E82F21A7ULL, 0xC855882077DC1660ULL, 
            0x049E7460B28ED1A7ULL, 0x2ABDBD1CCB476A42ULL, 0x9597F643165C1746ULL, 0x6C3B5A4BEAFEC31DULL, 
            0x643663198A48C8A7ULL, 0x6B5BB0300D41155AULL, 0xD462EB0F2208DCD0ULL, 0x9FEAF1FBF9AB5C6DULL, 
            0x1462CD8140908DE4ULL, 0x6A713A3565188B5DULL, 0xECE2CF5DC09A0503ULL, 0x69D78AA7164BAC0CULL, 
            0xECD01E52C90643EAULL, 0x130810E27C938E01ULL, 0x2171CCF55912BE63ULL, 0x979A4DA090650A33ULL, 
            0xF8D032E728AB612FULL, 0x68FF279E32B9A7A0ULL, 0xFD12B6E58C56BA24ULL, 0x9EEE295EA8E8AFBAULL, 
            0xB61078CDA1EE9B67ULL, 0x45B22A1A2A4415C3ULL, 0x26B8628AE1E6F232ULL, 0x677A7045224C777EULL
        },
        {
            0x76E05F9151581A43ULL, 0xACCDE7969B73D3B1ULL, 0xC7275957F0DD5A8FULL, 0xC3755B5E77CBA1A3ULL, 
            0x66A6CFABA03EF6CCULL, 0xD2DF9E8C2707E618ULL, 0x02D44E63194E9533ULL, 0x457D280357F3E669ULL, 
            0xE53A1A6CD4D1DA1BULL, 0x1DD28C970F0C9F7EULL, 0xDD01F4C0BD28D1B7ULL, 0x6BAAC12E51EAA415ULL, 
            0x3D52996F35A0B312ULL, 0xF1BC7AAAC1249F54ULL, 0x276E990D0F67220EULL, 0xF4193CBEE0088632ULL, 
            0xC7BF9E79089CDA49ULL, 0xFA1FB977B9B82262ULL, 0x6FF4CC51DC77302DULL, 0xFA063A32D9F014F6ULL, 
            0x4DC594CDA6D4A62FULL, 0x5886BB58348A5CF4ULL, 0x3AA43EFEFB1EEE22ULL, 0x4ADC07C5C49EDDBEULL, 
            0x6B1897F3C521CA31ULL, 0x955D2DED451403D6ULL, 0x5591B5CA75F251EDULL, 0xF8AD9812257B1EAAULL, 
            0x7F356AD2F0B8A53FULL, 0x24823CEB67EE7D02ULL, 0x563271388C14E12FULL, 0x5E94C7C56CDE00F9ULL
        },
        {
            0xE4FACD6D3697568AULL, 0xDC53A34D16D7BC11ULL, 0x3F3645D7233F9C9CULL, 0xADFEEEC0B694C4D8ULL, 
            0x92DB55DABC5C4F6EULL, 0xB7079DE8683C0CDBULL, 0x42C13682E06EB779ULL, 0x78BF3C6E1F05BE53ULL, 
            0xD400B648671836F3ULL, 0xDFCAE09187254B8EULL, 0x4200C14BC4E4BAFBULL, 0xA18B7DD07D11F3A5ULL, 
            0x59F48F23A36985A6ULL, 0xAE4F90E8665ADD0CULL, 0x2734E01364E5E210ULL, 0x0F82A669DB9DDE06ULL, 
            0xFCC5E73C0BF3A917ULL, 0xE6C0E4C0FC3013C3ULL, 0x417C401137B66C38ULL, 0x16591A13BF01E10EULL, 
            0x0125DAD1F4C5971AULL, 0xF6AB135D3EA3D9FAULL, 0x0C603D4539073ED2ULL, 0x8BA518E54E3A285DULL, 
            0x7BB4B4696F61F473ULL, 0xB6FAE871745A6099ULL, 0xE193DD2B82C5AD47ULL, 0xF4DFC0911F5851ECULL, 
            0xFEE30BC6D9A79843ULL, 0xDE389A18C0FD88C0ULL, 0x9EC7A22D6DC8F5FCULL, 0x3295997FE7385A0EULL
        }
    },
    {
        {
            0x2A77BBA1DA970989ULL, 0x2C37A9572B08D07EULL, 0xEFA7BF526A7C84ACULL, 0x6655C7CA02EF0EC1ULL, 
            0x9E8BA6374C184D71ULL, 0x8FE0CF98302EB62BULL, 0x1965B5A2064F788EULL, 0x6F7B5DE121DCD615ULL, 
            0x8354D38B832DFC0AULL, 0xD0BBD18AE1CCBC7EULL, 0x91A70FFB0B6549CFULL, 0x66A027AC625BF139ULL, 
            0x8A404A0D3B61E187ULL, 0x9C38D519388ED767ULL, 0x2CF3C66D6BA4A3DBULL, 0xC97C3E7E002EF2EBULL, 
            0xE62426421559C5CBULL, 0x33E74CDCB04CC6D1ULL, 0x5A2995B30C704375ULL, 0x7119E04EA3ADBD1EULL, 
            0xB72E054AA34E5A42ULL, 0x36E492D999295325ULL, 0xC389914760934C3EULL, 0x5B9F61C040276E00ULL, 
            0xF4C0B6E15415ABBBULL, 0x90A80B8DF33E318AULL, 0xC0DCC54BBBC43361ULL, 0x65384C6E433F4C9BULL, 
            0x819982A7122A6E73ULL, 0x1A236FE26A0C01E7ULL, 0x8870E8349F9E59ACULL, 0x37C56977383F9C24ULL
        },
        {
            0x6ACAFC3D4893D2D3ULL, 0xD949BEB7CB97E642ULL, 0x8595C5E5C0138A34ULL, 0x2E1758831887752FULL, 
            0xB0CA727043C3BFDBULL, 0xAD9CA4CBE6185A26ULL, 0x8668457C79D76638ULL, 0x08B9AD7DF2C9FAEEULL, 
            0xD7F2CD538D3B85EDULL, 0x740CD7D2FF3C6C05ULL, 0x378610C5B7E76C1FULL, 0x9E74734D6811E3C9ULL, 
            0xBC177D846D8ADC34ULL, 0x12330E4F2E1B8414ULL, 0x134A61DDB124E883ULL, 0x46C389E842ACBF55ULL, 
            0xA96E7982D64A189FULL, 0x1B24894792D19630ULL, 0xD2EEE4E1DC30474AULL, 0xDDD10F8393EDDE11ULL, 
            0x8C0DD512699773F8ULL, 0x65966673E4873605ULL, 0xE66B4241A2C4ACCBULL, 0x943B69EE07B6FF9FULL, 
            0x165DC3C4071436F3ULL, 0xC756A39E5FC400E1ULL, 0xC8789E81E7BC7C2AULL, 0x5CF390D5A0B5E50BULL, 
            0x7118D1D318B4E2FAULL, 0xD38A1D9C966CE9EDULL, 0xB81CDB84DD8EC0D0ULL, 0x6F1C42BB0764F69BULL
        },
        {
            0x5DDF7915D0E07912ULL, 0x41B956533302CCA1ULL, 0xA33796AE04DAE72DULL, 0xED8933A790C56146ULL, 
            0x9ED8BDF6C9CE6EEFULL, 0x514D40115B38D9D0ULL, 0xBC7E933E9C22F7BCULL, 0x0DFAC40A60869456ULL, 
            0x6B9A0667C2951C29ULL, 0x335BA760F994791FULL, 0x7D9E983281A70747ULL, 0x9B3811DC7DE2397FULL, 
            0x4CFE3E0CB408B326ULL, 0x19D3199B89FC49A7ULL, 0xBEDBEB98EE6AF9BAULL, 0x4705B5699BC856EEULL, 
            0xF8DD6957275FDEC0ULL, 0x711BF603873E3119ULL, 0x778FD016D04559B1ULL, 0x406C52CEBEC1D15EULL, 
            0xCE0A4B53832ED444ULL, 0xD0BE297FD1AE7749ULL, 0xF96F3241BE1B7410ULL, 0x0FC907685B79B152ULL, 
            0xACD98FCEEBACE217ULL, 0x198FFE140EFE801EULL, 0xB1404338022BAE90ULL, 0xDC171F6F9C573B04ULL, 
            0xE4A7F6B420A00561ULL, 0xF926781899963612ULL, 0x25BAC0D02B5F0F4AULL, 0x862787CD34E70B49ULL
        },
        {
            0x9FDAB595CE464BF0ULL, 0x54232B7A3360E78BULL, 0x66FFBB415425566CULL, 0xDE35110DFEA7346DULL, 
            0x5EC2C4E42BB17EFBULL, 0xAB0D781C2259D49CULL, 0xC36BB02257D23E67ULL, 0x67224BFA706A8C13ULL, 
            0xE892EDF708A6333DULL, 0x2FED2DF7CAAE277EULL, 0x91B260D6D823AFB1ULL, 0x8E23405E325945FCULL, 
            0x01A6502E7596574EULL, 0x7C68DA7BB11C4250ULL, 0x2C7553AFE196FE37ULL, 0x7260F6814AF244FFULL, 
            0x7A7A3F2D6D5AB416ULL, 0xB7D61D56BD88F6B9ULL, 0x109976C59DE2D14EULL, 0x927211374EBD1930ULL, 
            0x57E32DEBA9FE51BBULL, 0x3B00340CC921A86CULL, 0x4E51CC263CAA72F0ULL, 0x2C5F271CA7662FA7ULL, 
            0xC59F601CDF2DEFDFULL, 0x84FE9B87A8B4361FULL, 0xB5942E6186A1042FULL, 0x63D9733D9277D709ULL, 
            0x62649152B28D5838ULL, 0x9C9099048C1A6FF4ULL, 0x65C27BD4EE828A2EULL, 0x17FF515AA55232C2ULL
        },
        {
            0x7DAE7257A912A8A2ULL, 0xF4EFA1A8DC9B2F2BULL, 0x07607E8FEBFB4DADULL, 0x117122ABA86D436AULL, 
            0x3C1CF80D10075D17ULL, 0x6261B7D9634F0237ULL, 0xAC920D5779395064ULL, 0xE456ACC2AFE3F753ULL, 
            0x5EDF57561A15FF81ULL, 0xC27BAD99754F0D36ULL, 0x30FC25D294CC0C9BULL, 0x3CA008C10FFA53D2ULL, 
            0xD4B96C97C8DA59C4ULL, 0xC6C37BE9C645E544ULL, 0x38332CA41E4436F1ULL, 0x03D869DD4A51E112ULL, 
            0x19113ED47F26DFE1ULL, 0x098AC8831E54F6EBULL, 0x5D5C63CC8A3A4AC6ULL, 0x8976D5A32DF4C037ULL, 
            0xA985D780DEE504F2ULL, 0x14B4C1F704D36D7FULL, 0x52E772AA6D055813ULL, 0x7B2695C88CFA9F43ULL, 
            0x1B551C8A39DDF68CULL, 0xEA9A23D04568A735ULL, 0x0701AFAE9F2E7810ULL, 0xAB0FD2C4E08799B7ULL, 
            0x9F8D0FD3F321A7A7ULL, 0xD18465CBFD16CC6EULL, 0x867D7349686311CDULL, 0xDD65D57CF1BCA9A6ULL
        },
        {
            0x55B5D8C687C88CA1ULL, 0x0373F7678209BD96ULL, 0x4A14072A99B8955DULL, 0x71E69BCB923290B4ULL, 
            0x85F51B546261472DULL, 0x7437412EE62216B1ULL, 0xEDA70E6AF5001268ULL, 0x139A5C37E59080C0ULL, 
            0xD933E9F52E7F1230ULL, 0x806A409BA17B47A9ULL, 0x5EB2367BA0E47D04ULL, 0xE7EEDD59498E3CFAULL, 
            0x318AAC07279FD040ULL, 0x9E665E2243A897A2ULL, 0x33BA426DBB338039ULL, 0x6B62926A216BB31DULL, 
            0x98E6BE279E9B93C1ULL, 0x1AF658BDBC67D9EDULL, 0x34AC909B54E133E9ULL, 0x81DF5C26BF48186EULL, 
            0x8156CDCA4D7B89E2ULL, 0xF3D312B302A4895BULL, 0xAD0C1798C1E200B6ULL, 0xAF196A4E426F0266ULL, 
            0x76CE287AD3F36C84ULL, 0x9A1678F666BC3374ULL, 0x32EF672D0845F07DULL, 0x5740A16D0C488530ULL, 
            0x84F394DF7ED67A3AULL, 0xDBBCDE9144D3FCAAULL, 0x489A9F039D8B411FULL, 0x01717BC77B39DB55ULL
        }
    },
    {
        {
            0xC87D723274149707ULL, 0xD5CB72F094254DC4ULL, 0x41F907F9E66E00F2ULL, 0x8D1EE39F9A23F363ULL, 
            0x66D2452C6E93A9CAULL, 0x673685BEE31B0E4EULL, 0xF68C19203D20EAC3ULL, 0x65E4FA0F33A028C6ULL, 
            0xF52CFE741F8C60F5ULL, 0x60F7714BD2026309ULL, 0x3FFCE304F9F1172DULL, 0x9D3D2D5E67BE2B08ULL, 
            0x8314507A1C658779ULL, 0x6B68F69A18FF8ABAULL, 0x747BBE99239FA388ULL, 0xC220B49C490F9927ULL, 
            0x081B4EAE4090A7EBULL, 0x6317729C8D328549ULL, 0x047C5EC83870098AULL, 0x993FFE81559D70DAULL, 
            0xA5F7E5370EAD8DF4ULL, 0x86A049C1D5E75F04ULL, 0x01B17D8DC142C988ULL, 0x6980DE063B64C98FULL, 
            0xDDD0E21DCA38EAE9ULL, 0xC4960856AE3A18B6ULL, 0x77F7C0F3F6ADE83CULL, 0x07489AFB360FE996ULL, 
            0xB4FAB7152B5E09E5ULL, 0x71E328C6D70FF338ULL, 0x8B42BACC16BB2BE7ULL, 0x9D3DBE93F87A3BE1ULL
        },
        {
            0xB8ACAF3EC291FBD1ULL, 0x20BAA862B40B409AULL, 0xECC1A8C71FCD2B21ULL, 0xB93F4FAE3EDD0405ULL, 
            0x8A997C3E4DE33884ULL, 0x3CCB55CBBA6062BFULL, 0x455E3C9579FF5A74ULL, 0x90A137768650562AULL, 
            0x5074871A321D2358ULL, 0xB87ADD3DC578C36AULL, 0x65AC122A59546706ULL, 0xB9D4CC982568F729ULL, 
            0x758C557991B7D400ULL, 0x91817B7505E4DA87ULL, 0xE5C9A53DFA552E2CULL, 0x6A105CFBCC8980B1ULL, 
            0xE3571CD6D943CFF0ULL, 0x28AA63CF8730DCA9ULL, 0x649D5FB15B5834E8ULL, 0x687A410CF735DD40ULL, 
            0xBF2BAED712B5980EULL, 0x51A319024F4A62E2ULL, 0x7EC9D1623C7D40E6ULL, 0x53C61ABB94CB87F3ULL, 
            0x54988B0F5CF9F0C1ULL, 0x5324FE34D57D4D44ULL, 0x6BAD0B212C6B7E64ULL, 0x7CF097DF77ED8878ULL, 
            0xE9C21F506D5C298BULL, 0x4525E681A11F12D5ULL, 0x09A55F702D9ABA3DULL, 0x774E371FDAEEFBBDULL
        },
        {
            0xB42842B4E145C929ULL, 0x9A52C1AC81882A41ULL, 0x0E312985B3E60A7CULL, 0xF3DB2EEF3B216E3FULL, 
            0xF5FE9A1F7764621AULL, 0x9ADA0E8981839AD2ULL, 0x1A4A1981AFDEB8FDULL, 0x631DAD6BA514FF9EULL, 
            0x366675E9E9AC8DFAULL, 0xA15AF4EB29F6737FULL, 0x2B32BA2837118479ULL, 0xABD64401BA6D206AULL, 
            0x19CBD8AF725EE21FULL, 0x3AFD98D507C1528FULL, 0xBCAA6189E883133FULL, 0x49D0684813C6435DULL, 
            0xE555C3BE0E7AC499ULL, 0xDF1454C1E97813A5ULL, 0x89E8B64528E719AFULL, 0xC6C0D0E1E897B8EDULL, 
            0x732DB7A45377D07CULL, 0x6A1E50A93F23E497ULL, 0x95D71D25FD725DCBULL, 0x47AECF94BADFEBC2ULL, 
            0x1DE80FDAB0DB2E87ULL, 0xE4F0479E863CEF5AULL, 0x55E782AF8C9F6818ULL, 0x2CD9B372B6DDE926ULL, 
            0x378BE7D6A7F254BBULL, 0xEE258B45377DFF6FULL, 0xB4E03780EF30B0BCULL, 0x8348CB83CA77B7A5ULL
        },
        {
            0xF5ED192186E6A12EULL, 0xB3A2BC8E9A73D118ULL, 0x554513CF6E4C9534ULL, 0x2910841098AF6936ULL, 
            0x827EFD92F0DF527AULL, 0x322037498F0BE0D2ULL, 0x315000ED64E8197AULL, 0x47833B5F8E341913ULL, 
            0x8DBCF29B52B7D775ULL, 0xE6877F883777765DULL, 0xBF8796D72CBB341AULL, 0xCF1D5D3CEF8BE209ULL, 
            0x62D604642E7723C4ULL, 0x4A2EEBBE43A906D9ULL, 0xFD26F4B230031692ULL, 0x0C04AC354485683DULL, 
            0x17387C71FD2766B4ULL, 0x6CA89806E787829CULL, 0x51286E4B09E8BEFDULL, 0x931A444C869ACEADULL, 
            0x46D60626B0DF4A0CULL, 0x0CF4778CA81C241CULL, 0xF250ED0E4870018FULL, 0x87EB770580FAEFD8ULL, 
            0xDFF52D20631B30BBULL, 0xB94C8332224502DBULL, 0xD73A47AB7B17EE0DULL, 0x87DDC05EDD0ECCF3ULL, 
            0xB1D151E8A5013961ULL, 0xC00EBFBADF5E93A6ULL, 0x9E71C060A9AD43DDULL, 0x009743ECE0434267ULL
        },
        {
            0x6A9A60534D5D9780ULL, 0x7C4345B3A8363B2CULL, 0x7FCA94E78EAD668CULL, 0x87F467AE30DE0F46ULL, 
            0xCAA4AD0444AEB5E2ULL, 0x8F4D565AF37E1198ULL, 0x8E59373B59AD09ABULL, 0x3835E9AD79E16339ULL, 
            0x17DFC9B04F7E74E7ULL, 0x762633CBF52BE6B5ULL, 0x478D48E9F43385EBULL, 0x27D36AC5CB5F5B27ULL, 
            0x839F2A043F36B10DULL, 0x4055326693188B6FULL, 0x3C404EFB3552A432ULL, 0x20C1F4D7CD43FDD0ULL, 
            0x60F521A438C33463ULL, 0x9C1F17B27CCE7A5CULL, 0x1FF1CF85BA73E9DBULL, 0xE8836B28D2A4DF4BULL, 
            0x2A7D0F62E2CF01BAULL, 0xCD2D686B1E0F57DBULL, 0xA3D4AFE5B9C1E1A5ULL, 0x6179F7421B93052EULL, 
            0x26FBE3D306DB91F7ULL, 0x9063A376964CF1B3ULL, 0x8C04E312FA2E0D04ULL, 0xF9D2529EC1A0ECC9ULL, 
            0x16FC2AB2E85EF1E8ULL, 0xE325AEA623ABA014ULL, 0xDAEC2B0A431BFE76ULL, 0x8BEB7DA1B5AF6E97ULL
        },
        {
            0x833324F652F1110BULL, 0xF1E1888BCD2CAD32ULL, 0x44EBFD288977F2BBULL, 0x4F0DBBC3106298A8ULL, 
            0x168B6B2DB54E9A26ULL, 0x6FF8AFBA80D87774ULL, 0xEACD7B833844E3FDULL, 0xA1C0D252B6868913ULL, 
            0x6FF701152A87FC10ULL, 0xE2BE24CADBFF0D72ULL, 0xE08037C928474F8BULL, 0x46F0E93A52696647ULL, 
            0x1FE62ED3C2BFE39BULL, 0xAB6C4C4ADC21F7B4ULL, 0x04FE7049E997AAA1ULL, 0xA9CEFC6FCBD66950ULL, 
            0x34B1CF5D95862719ULL, 0xBB2096CE6BDE828DULL, 0xDE66C3DEFC0681DBULL, 0x58B574E38120C94DULL, 
            0xCD852B234C5B57B0ULL, 0x8A9C4CEDF0AD73F2ULL, 0x0D0B40F8398AFBC2ULL, 0x76A954A4CB07CB59ULL, 
            0x6C50046F35491115ULL, 0xE5B263649AE270D7ULL, 0xDCC3F896EE7F7756ULL, 0x779D4F2CA6B625AFULL, 
            0xABC42FC6D07B27C3ULL, 0x596904DDD8FEEA79ULL, 0xEE32846C00ABF8D3ULL, 0xDBA3295BB0A52B57ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Procyon::kPhaseCConstants = {
    0x7B57CFCC35695DE1ULL,
    0x5F137E9529EE9685ULL,
    0x9BF3727A9E41F1EFULL,
    0x7B57CFCC35695DE1ULL,
    0x5F137E9529EE9685ULL,
    0x9BF3727A9E41F1EFULL,
    0xD55FFEAE0F378780ULL,
    0xE9997332A2548AE6ULL,
    0x89,
    0x0B,
    0x08,
    0x02,
    0x96,
    0xD3,
    0xB4,
    0xCD
};

const TwistDomainSaltSet TwistExpander_Procyon::kPhaseDSalts = {
    {
        {
            0x62D0AB3B2B1D7893ULL, 0xF7120D17B26EBC21ULL, 0x956B331F3D4C5A23ULL, 0x019522A07EEB86ACULL, 
            0x21717B6438E248B7ULL, 0x99C015E578E70767ULL, 0x2493338C7060AEE9ULL, 0xF45B7785DE0B7C3FULL, 
            0x9BDC53CB53012FF9ULL, 0xBE4468F6A82A2EF9ULL, 0xDAF0B52E1F22AE21ULL, 0xD4FAA3A15EE70509ULL, 
            0xA2514DDD44617C60ULL, 0xE5D1ABD780359B37ULL, 0x9777FE7019BC5F66ULL, 0xD5291C21E34F680FULL, 
            0x11EA6069A425F371ULL, 0x68741B3833C5777AULL, 0x1152F60D2125C4A5ULL, 0x03633340E651D5DFULL, 
            0xAE30FC2B0B0CA70CULL, 0xA1A90195F92F4925ULL, 0x1833C5211B29E28FULL, 0xDD8E45C889A73FCAULL, 
            0x525FF2A0CF8B0E62ULL, 0x6AF36D0041AF358BULL, 0x155106E13F145DF8ULL, 0x405787EF952D74F2ULL, 
            0x8B8357A5A6AB6430ULL, 0x7FDC6CACA6B1B6CCULL, 0x590AB667F67CCEA8ULL, 0x06225F4BE29D39ACULL
        },
        {
            0xA604593EFB67697CULL, 0xB61BB05292D9AA6FULL, 0x4BBDCDC6819374CFULL, 0x9C35A14C22DEEEACULL, 
            0x259AB792E4932692ULL, 0xAB1CB9C74F16768FULL, 0xB686EADCD8039A37ULL, 0xBB7159F9C413CD60ULL, 
            0x4335EA5E3401213EULL, 0x47018CBCCAC4DD2FULL, 0x750C9E06AAE0AB7DULL, 0x779E68B5AA7C06ABULL, 
            0xD9D1742193528A12ULL, 0x57A8DC1884FA8E91ULL, 0xE363DBF47BBD0A65ULL, 0x27F3D3CB132F7062ULL, 
            0x1CF807E0EF41F35FULL, 0x8F82FA68CFB76975ULL, 0x230DB34A23AC2FC6ULL, 0x32960C320E838DC3ULL, 
            0x683529EF15CDF355ULL, 0x1DAC3FD38C31C5C7ULL, 0x7D1F8B874767E13BULL, 0xA906719EC2E696EAULL, 
            0x51394573D88724C1ULL, 0x97FF7317C3FAF123ULL, 0x9D52129B027962C1ULL, 0x6BC67C65C01CD253ULL, 
            0x5127ED9A2E45DF3AULL, 0xECF3DBC05D625C51ULL, 0x6DCFC014C52FFB1FULL, 0xCA48D39665E15176ULL
        },
        {
            0x9B32C389DB4B0041ULL, 0x766364513AD705B2ULL, 0xC9466C0E4F73B187ULL, 0xD513EC4FCA170F36ULL, 
            0xD4CA10B63E71EF93ULL, 0x4C1580C527182E7AULL, 0x028BA0FCD5E06146ULL, 0xB38481A82763738CULL, 
            0x7613E702FB609C12ULL, 0x8CA15EBF9C03AAAEULL, 0x42E25F34F99CAB55ULL, 0x4F616E23B338D750ULL, 
            0x6D801FA0AE1A40AFULL, 0x136F8739E5A89B7BULL, 0x716E6EFEB2102402ULL, 0x89F86DAB104EA124ULL, 
            0x159D6DB8493E2833ULL, 0x4A81129827D76AB5ULL, 0x7A8DCA6F9932998FULL, 0x7CB9F05E7C6FE9C5ULL, 
            0xC99753085D18B19AULL, 0xEE7666F297A3E8FCULL, 0x1BD3F2770F6672F8ULL, 0x856A610A60D368C7ULL, 
            0xA1B35EC5B222157BULL, 0x44578D317671629DULL, 0xCC8C54A8D4E90F79ULL, 0x9EABC2CD81A60A44ULL, 
            0x8A5C2BB7C0DB611EULL, 0x99C2C33357AADC17ULL, 0xEB47067063D40562ULL, 0x4B6CF64DD7F008CAULL
        },
        {
            0x1B9746655633DE9EULL, 0xCC09FB29537B2FD3ULL, 0x503D3FBD1242F9F2ULL, 0x47814934B9E70630ULL, 
            0x555AD9054283F830ULL, 0x22A8BDBFBF35E23FULL, 0xCD43315B1BC970AEULL, 0x9704157E88D2FD56ULL, 
            0x6E2E1D357FE00691ULL, 0x8B3CDB6488FD9C86ULL, 0x4D212EA6966CDA3BULL, 0x60F85362F635328DULL, 
            0xBF92D3D649B9D848ULL, 0xD1AABF6F615005F1ULL, 0xF73AB514EF8DC2EEULL, 0x0FA1A50487F6CD15ULL, 
            0xED7D3578EF895936ULL, 0x98A63A57A18FE0A8ULL, 0xB2D96C8D9283CD12ULL, 0x2795C7B0376346D6ULL, 
            0x1CF9BBBF5E7629B3ULL, 0xAFE2976C8EB18AE5ULL, 0x5A188E17A07738B8ULL, 0x476F3A1E418A43DDULL, 
            0x69A5C6B58908D5E6ULL, 0x3A0662480DECE019ULL, 0xC2B1FB69C996BF6AULL, 0x3755408C531312D4ULL, 
            0xF022D02B1FEEAFF6ULL, 0xBCC2DD09E4AE4FF5ULL, 0xDFF4B366A4CCF803ULL, 0x3C334EAC9AB339C6ULL
        },
        {
            0xF27187ABF14FAEFFULL, 0xD88604E2B337646AULL, 0xDC9904F9C4A260CBULL, 0x95B4CDA5AFF8A7CBULL, 
            0xABF6DEA933C4F448ULL, 0x8778CCA0FAFD7444ULL, 0x91CAE628603004C8ULL, 0xD384B563D127A291ULL, 
            0x4AEEB29AB82A1E84ULL, 0x737639949A8F7D05ULL, 0xC4B20D58A3B0902AULL, 0x79A9B67CBB4869ADULL, 
            0xAD63717AF8C43563ULL, 0x4F41B09A5D8EFA46ULL, 0x424F0FCA0B4ECE31ULL, 0xFA835EBF3064E1DEULL, 
            0xD27D7927DA286B0AULL, 0xF0C918A97D096447ULL, 0x3AAB21294EB02F24ULL, 0x5EA545F98478C886ULL, 
            0xE596AA8C93B1FD2DULL, 0x624BB6B850741D85ULL, 0x0C9166020FA2FAE6ULL, 0x3D461D501EC16C5CULL, 
            0x4861255BAB965AE3ULL, 0xD9D0990438E2E8E2ULL, 0x97E46EF7D454E6A7ULL, 0x6B1DA78241DDB260ULL, 
            0x1FE43341C54D9E3DULL, 0xC8878A15561ED5BBULL, 0x624975228EB287E0ULL, 0x6320826CBE4E72BFULL
        },
        {
            0xB731A5C2413672EBULL, 0x16597B62DC22869AULL, 0xCE5A8A818AC1D207ULL, 0x8152B5A20DA8175CULL, 
            0xBCC9944E1123D0F8ULL, 0x5A165B431E00647AULL, 0xE9499A734993FA04ULL, 0x68C15B3FBB94FFACULL, 
            0x7C6C0AB449D5D09DULL, 0x145313803A9EB66BULL, 0x4802A359BDABEDACULL, 0x98A40F215B2546CDULL, 
            0xE8988315AC4AFAE6ULL, 0x3509E3FCDA39B672ULL, 0xED79F5F13AC83A36ULL, 0x9A79F7A6FDFF6701ULL, 
            0xB67D155AFE2DDADAULL, 0x686A52FC7FA5B29EULL, 0xE4AE2D9F9602A543ULL, 0x24DEA1614C01EDFEULL, 
            0x904681A16FF04AC3ULL, 0x51D2F2EEE3C9B755ULL, 0x6BD13689ED8C4D25ULL, 0x52254789ADF5137AULL, 
            0x60AD2627E7AFEB6CULL, 0x9E7F4639AC32B169ULL, 0x71E6D8A5848E872EULL, 0xFDE2106DE2DE408FULL, 
            0x831DFD015834518DULL, 0x6DF43C61EACA3D52ULL, 0x2E89F12977BC26E0ULL, 0x668BDAC59F426533ULL
        }
    },
    {
        {
            0x8E6F05D720349B33ULL, 0x40B5CF7FF5685A1EULL, 0x8D9A6124069BAA16ULL, 0xBA7553254ED1AB5DULL, 
            0x07FFD44CBC20CEA3ULL, 0x38845C4C8E4B722CULL, 0xCAF532313733EA8FULL, 0x9368666BF07517E9ULL, 
            0x7371CC056DD540CDULL, 0xB843FD135288A2CCULL, 0x54D1C58C4277B88EULL, 0x0BEE3DE786DA252DULL, 
            0xFE10D7F412FA9CAAULL, 0x1AF46DBCB5BBEC25ULL, 0x8C9B249DE4E8CBA6ULL, 0xD53B719BF362B429ULL, 
            0x72163003ECE4A317ULL, 0x8EBB0F9D096DEB78ULL, 0x6878ECFE91BAA7E8ULL, 0x0047A9A9B10F3B6EULL, 
            0xDE1A942A00DEE724ULL, 0xF95AA8DAB8C1EC12ULL, 0x9C9E80AC091DBE13ULL, 0xD72EFA0B28CBA038ULL, 
            0x9AB92590BE742CE6ULL, 0xDEB09F67A85EE655ULL, 0x0C0E237542364160ULL, 0x19A2548DFE65119BULL, 
            0x9F5DD00E50A6A4F3ULL, 0xBA8013447E8997F1ULL, 0xFCACF489D479BDEFULL, 0x3104B004AA2AC15FULL
        },
        {
            0x7CBBCFF38C700F87ULL, 0x6FE9C2BFB1F82549ULL, 0xC9590E582B9FF36EULL, 0x0EF48E9A5B90FE43ULL, 
            0x808CA112C6E1E759ULL, 0xCD47CE92C601FCE1ULL, 0xD158189C10DE41A0ULL, 0xA80EC06925F1BC80ULL, 
            0x05F5647978D54B21ULL, 0xF53789CC49C9515DULL, 0x83A2EAE009EE8692ULL, 0xA9D7604D3E2D10CFULL, 
            0x0F0F44FF3F966795ULL, 0x4F1E858DF9C9980AULL, 0xC1D0CA524331DE10ULL, 0x050EF916314997C3ULL, 
            0x725CAA300C5CC5DBULL, 0x45600F7CFD475033ULL, 0xF5A2C989E08CE60EULL, 0xA054B66D8897AE8AULL, 
            0xC71B00CF7830AF16ULL, 0x4B233453A977BBF1ULL, 0x7F5F7734C9233545ULL, 0x0F4DDF850E9EDE7DULL, 
            0xC3F3F882112EC87AULL, 0x313CEA5BA1207389ULL, 0xCC155B0E6121086EULL, 0xAE3464C722B73D1DULL, 
            0xF715B0764397FCCCULL, 0x30B37A1D9EBB9E71ULL, 0xBCB32433EE17BEBDULL, 0xDBFEC1B23BE7BA2AULL
        },
        {
            0xC802468AF57BC411ULL, 0x8D05E20E168735F2ULL, 0xC0B532F78379F784ULL, 0x6745406C625DD076ULL, 
            0x7AFC9B18C0D773BFULL, 0xD37C8C1C45B1263EULL, 0xD6446CE71C4A9BA7ULL, 0xFF4AE13B304C93A5ULL, 
            0x590B6EE13C5F1B9AULL, 0x514FC6A5CBE4585BULL, 0x4AA7249C7558285DULL, 0x7E286801C0639322ULL, 
            0x0A54903BE7EA6377ULL, 0x04889CEA78391635ULL, 0x7BA923F03D98A82EULL, 0xB9E63AE16E8ADC98ULL, 
            0x84E52546B5E8991BULL, 0x72E1DE618189A9F1ULL, 0x0CB2870989909844ULL, 0xCA7B50E3AFFEFA0CULL, 
            0x487B885EECC0156DULL, 0xB1F9059056240D4CULL, 0x4DB6EEBFFCDD752AULL, 0x944744C8A8B13204ULL, 
            0xED6135BE276F55E5ULL, 0x1ECD3A901E75BB39ULL, 0x7F448044FFC6271EULL, 0xF01459F2DD6E0978ULL, 
            0x1C7980F129F622D8ULL, 0xAF3E43322F71482AULL, 0x6C416A9407119AB8ULL, 0xC1B144C9C1454197ULL
        },
        {
            0xDF3890AFF3E6C549ULL, 0x5A508CE9FC925193ULL, 0x0D15FAB9732D559CULL, 0x82C76558A08F7186ULL, 
            0x206C3A93FF5D7100ULL, 0xE104AF35E4D69F78ULL, 0x42B4E2A56EE337C4ULL, 0x7BC2D18A5E4EAC89ULL, 
            0x6216CDD4CD3635B0ULL, 0xE1397A8683E3B340ULL, 0xA0016AC494227FCEULL, 0x6C1A79CFF0AA7262ULL, 
            0xB5739C7E9F1187DAULL, 0x8A110947689C4A63ULL, 0x31274404EBCB34D5ULL, 0xBCA44E2E2BBAF75CULL, 
            0x49BA70F4198EB3B0ULL, 0xFE644E96CC87B40EULL, 0x81C8A8D97456329DULL, 0xB9A8F2A203543B2EULL, 
            0xBC55DDAE4D6C0AE3ULL, 0x64F329771C780F1FULL, 0x2060D8783A2A2A93ULL, 0x20FCCDBB73DCFDF4ULL, 
            0x78DBC0DB5D99FAEEULL, 0x0101CDED30830B99ULL, 0xE476CB6910FE9B28ULL, 0x7AABC4E1EE5C14C0ULL, 
            0xB8E975132D59486CULL, 0xF70D9194BD015BE6ULL, 0x3CE7E61BC1297272ULL, 0x8951ED6E76472C18ULL
        },
        {
            0xC846C1E49C77DF37ULL, 0xE97F359DFEDB2C1DULL, 0xC69553F0DF10DB88ULL, 0xBEDDD7D970BBAC39ULL, 
            0xEF47094258DE8E6AULL, 0x3D4DE4B87488E040ULL, 0xDD1497A34E009789ULL, 0xE8941223F70EE4C5ULL, 
            0xB101520A762D004FULL, 0xE46A226C7C0538E2ULL, 0xE6B35C177DDDA210ULL, 0x4D208E26F870379AULL, 
            0x1FA709016F29BF6FULL, 0x3796FD77AD1C8EE9ULL, 0xAA66679EB12C44D0ULL, 0x6BC5FD8F6949F0CDULL, 
            0x671D951001E49463ULL, 0xFE8B7855A1425BE3ULL, 0x29F07D07CB9CE6EFULL, 0x05F9DC1076550CAAULL, 
            0xACA0FFC1BCB184E1ULL, 0x4C6A3A02E9D0E48FULL, 0x30A618917E1E497AULL, 0x1AF777D89FE2C792ULL, 
            0x80E5E5720EE03924ULL, 0xB326BF554CA6A8C3ULL, 0xFD4C131FB03A18E4ULL, 0x0EE6AB9047CD73E7ULL, 
            0xB85CFDB8949D60F7ULL, 0x74D6E23D1160ED38ULL, 0xE66CA08F1CF3EC5EULL, 0xEC0EFCA18158D958ULL
        },
        {
            0x5B045518ED815917ULL, 0xEFC6D525AC701410ULL, 0x8CEBFFAE43FD6D9EULL, 0xACE7D7F35D1AB364ULL, 
            0xA93FB986ACDE54A4ULL, 0x25404796FB0BE5D8ULL, 0x667C46A937FF8FD2ULL, 0x88006C3B190DB718ULL, 
            0xC05437C99E8999A9ULL, 0xE3AB8E683EEDBE56ULL, 0x0C519878C5BF57FEULL, 0x30EA0CCFA03CEB65ULL, 
            0x5B8B1BE77EB35D17ULL, 0x46137EC079C6AD15ULL, 0x886738DCB480BF3EULL, 0xE6AEC82DE1FD16C7ULL, 
            0xEBD8FD0FE2852063ULL, 0x661F934171699CAEULL, 0xCB39680DC5468CD3ULL, 0xC343D713C74BED72ULL, 
            0x22259780C48F4115ULL, 0x35F7CB955FFA08C9ULL, 0x1902C45359F1E080ULL, 0xD7DD3C258A478567ULL, 
            0xABC4B302F290E949ULL, 0xBE78CD2CE7B9BEF8ULL, 0x86F66422EE3D643DULL, 0xC0CC191EB62ECFD5ULL, 
            0x4E6EBC9D48A47A4FULL, 0x28A2024E007C8E1AULL, 0xDE5A321184E340CAULL, 0xDDA9F0D6A143A859ULL
        }
    },
    {
        {
            0x4221EF61EB624BB8ULL, 0xA9E04B2C558124ECULL, 0x764ABA31E7BAF9A4ULL, 0xE20AA1972974D120ULL, 
            0x48463B200D28548DULL, 0x540C8E71D21BD4C1ULL, 0x0957A6C14C6E9CAAULL, 0xA0A6D378EA3D20E4ULL, 
            0xEBABAE071B3CBADBULL, 0xF234DDE09EF00D2AULL, 0x5567EE8A53445A3FULL, 0xBDDD4DD1DA1C598FULL, 
            0xF1B825A69685643BULL, 0xBD023D478F0DF482ULL, 0x657A6FAFD5012A1DULL, 0xF64BF3935BFF4BD2ULL, 
            0x20F8CFA1C0AEDE7CULL, 0x67147A68F787A5ADULL, 0xAD61748073E14E89ULL, 0x697AD18EC6AF9B7DULL, 
            0xAD327DAAB37B8AE9ULL, 0x98085CB557DD0C6DULL, 0xFC54A21D252588F5ULL, 0xB850353180C96532ULL, 
            0x5CB89FBC823CB220ULL, 0xE59D2C847C63CB85ULL, 0xCD03033D83035061ULL, 0x97817ABF239969D8ULL, 
            0xA65EA6A5F868A887ULL, 0x0520DFED4924F58DULL, 0x9651DDACF2A2D9AEULL, 0xC7D90E4A9E9758DEULL
        },
        {
            0xB46EF319EB14A4B1ULL, 0xE683227DCA8A73DAULL, 0x3CA9AC54CDD443AAULL, 0xEE59F05E90823FEEULL, 
            0x88188586C1C9DDDAULL, 0xCF1BFC4B9D0F116BULL, 0xAAA50393F1071181ULL, 0xCE4B95684264D19FULL, 
            0x3152A992C83A1548ULL, 0xC704C6327EB4BCB0ULL, 0xAAD99C933C0F7822ULL, 0x4BD94EF73785F539ULL, 
            0x74DDA8FC956EE896ULL, 0xB4FCE2C8A4E90FBBULL, 0x908DAC8EE7EC068BULL, 0x289890A134FA998FULL, 
            0x5FC52201E03832ACULL, 0x0FFE8FEA02740BE5ULL, 0xC355FDE3A2350CADULL, 0x10C008B63BDB6D10ULL, 
            0x5138569A56F77BB8ULL, 0xA64AAD0585624C83ULL, 0xEB405AC682BC654EULL, 0x9FCB6AC1318C6CC4ULL, 
            0xBE78E92E5B7E994BULL, 0x5A113A8B4C9C052CULL, 0x4625266394DB3FB1ULL, 0x371F089AF34E642DULL, 
            0x5505A2AAAF1FE2D6ULL, 0xD87FD6B2CF6CCBCAULL, 0x65B8238CACCCE448ULL, 0xAA3169A95C1CB550ULL
        },
        {
            0xD2EB7B4C52A9843AULL, 0x703082CBF3C59772ULL, 0x050A4CB86ABB549DULL, 0x046E9066F605010BULL, 
            0xCD1651C881A55E43ULL, 0x7D5C709B0F2F6930ULL, 0x01903A7D1EEA072DULL, 0x6CD202A02F07055FULL, 
            0x4F8492A92E551B88ULL, 0xD9BC93BA3428388DULL, 0x3034ECA86682C60CULL, 0x4DA997D76B879217ULL, 
            0x18E529BAE0ABD2B0ULL, 0xC62D48860C355B6FULL, 0x3270DD6B3ACFF3E8ULL, 0x40899D00204BE495ULL, 
            0x5781B0B2F6EEED28ULL, 0xD7A21028B327C250ULL, 0x4A8DE258E128E38EULL, 0xEA9A6F6D80FDC481ULL, 
            0xE7B21B836D7A99E5ULL, 0xE7C303E75697FB77ULL, 0xBACE597A3E62C04AULL, 0xC3ACFEC6F7542DE9ULL, 
            0xCA27A845C0E078FEULL, 0x9DFA044C2B1E4987ULL, 0xD1AB60A85857C810ULL, 0xEA4097D89B8A730AULL, 
            0x4BC471AF8D4736FEULL, 0x7D9E70E4633B41BDULL, 0x4CEAD474B039A46BULL, 0x89DAC26CD413D69BULL
        },
        {
            0x296B7640F60F8B2BULL, 0xBA6D0EDC90DB5086ULL, 0x17E1397D62B780B7ULL, 0x27457FD66E6162CEULL, 
            0xD8FDA247145E55E9ULL, 0x3AE3ABEC176347C4ULL, 0x2B9D8B23E778AE2CULL, 0x0EDA0921F8F3773BULL, 
            0x564F9F8992DF680AULL, 0x19258D6078B4EF2CULL, 0xA5CAC729F38AD831ULL, 0x4A023689C83BA4A0ULL, 
            0xF8B66A81312808DFULL, 0xD3443054DC319FA2ULL, 0xCF80F581109EF5C8ULL, 0x95D9039EC1E4DAEAULL, 
            0xA90A124B96520AD2ULL, 0x5E93AC7BA751E1ECULL, 0x4CC2619AC90B613EULL, 0x2280A70CFC6A7DC9ULL, 
            0x91622C1DAFA6AC7AULL, 0x4B8105EEBF2790F3ULL, 0x3C2979B60542B5E4ULL, 0xD5D008C5D781D743ULL, 
            0x077E7D29E8C5F474ULL, 0xD95AD13DC9731AF1ULL, 0xC8A20AB2AE472CBAULL, 0x61F58BDC710E506AULL, 
            0xF41DA847AE19556FULL, 0xAB8FD7E0EA0441A5ULL, 0x1A272A7EE6F13649ULL, 0x48DC88AE5F8E4D62ULL
        },
        {
            0x75F4CD3829FBA6C3ULL, 0x0A0F0D08972242B6ULL, 0x6E70FEBB8D62132CULL, 0xAF01389F3DC84AE6ULL, 
            0xEE2CEDFA5B9FD03FULL, 0xC36159DDC2919566ULL, 0x713B785B6CD72BEDULL, 0x3A8CBB79A9AAB098ULL, 
            0x46652F114BB04758ULL, 0x53B7629FB7B1C1AFULL, 0x017DEA8CE6742A47ULL, 0x661D4F73B8BFEDD1ULL, 
            0x769393082EF1B4D7ULL, 0x080EF35AB24F930AULL, 0x75FC5026CF1B767BULL, 0x9EE66FDC23C170C4ULL, 
            0x63A86A74113D7054ULL, 0x360057101DECF4EAULL, 0x36DCEA3C810AB397ULL, 0x5226CECBDBF7E7ACULL, 
            0x5C1FB296A44110CCULL, 0xDCBEFF166F01DFE0ULL, 0x2C9C7FF30BD1336EULL, 0x3E808338CE484C33ULL, 
            0xDAE790D13D548BA6ULL, 0x30AEECA7DEA416A8ULL, 0x1F42190CB77788CBULL, 0xC4F876077FEEB0E3ULL, 
            0xA4219D8AADAE8791ULL, 0x86F68A79D7A88AA5ULL, 0x7F1E967FD9500D75ULL, 0x723277BFEBB93F0EULL
        },
        {
            0xFB3A35F67BCD3F77ULL, 0x2EC2FB466AA0E2F1ULL, 0x10AC0F722D39A595ULL, 0x8EDF941322BCB6CFULL, 
            0xA50D4B9CB18B5466ULL, 0x792BFF7B027F5143ULL, 0x89F4D9DD0A9B19DFULL, 0x33772DF37E32EF69ULL, 
            0x0F78C119F3A64E71ULL, 0x9457F470837A9BB7ULL, 0x9C9777B3D19CF887ULL, 0x4F95694886F92BB1ULL, 
            0x37A430BCD02CA85DULL, 0x282454203437BB92ULL, 0x7B2737F0CDFA2C0BULL, 0xDF45DEADCEDD0BE2ULL, 
            0xFE8F2A26B5ED30B7ULL, 0x7E31E2819508DC00ULL, 0x65497D7596D51F60ULL, 0x180935B5E8B7FE4AULL, 
            0xA1C8878FA922FB01ULL, 0xE85A0AFDF5C36551ULL, 0x8DCE07C34BF595A6ULL, 0x37176AC34AFC674BULL, 
            0xFE334217060C67AFULL, 0xD444E509ED43F5F0ULL, 0x1C082FEDAE05E2BDULL, 0xC6231880F6CA811FULL, 
            0x38D9E772FB74348AULL, 0xAFAB68DAD9EB9146ULL, 0x28A17746F6CD15DDULL, 0xCDFFC9F07A64E38BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Procyon::kPhaseDConstants = {
    0xDFF6F205219D85A6ULL,
    0x0D215793148694D2ULL,
    0x3010A6B60817E6B3ULL,
    0xDFF6F205219D85A6ULL,
    0x0D215793148694D2ULL,
    0x3010A6B60817E6B3ULL,
    0x42AD5EF8DF7A89B0ULL,
    0x9C731BD90B365D50ULL,
    0x34,
    0x84,
    0x62,
    0x07,
    0xF4,
    0xAE,
    0xE3,
    0x29
};

