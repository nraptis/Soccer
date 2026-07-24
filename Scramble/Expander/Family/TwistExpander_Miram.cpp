#include "TwistExpander_Miram.hpp"
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

TwistExpander_Miram::TwistExpander_Miram()
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

void TwistExpander_Miram::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x94764C4FB70027C2ULL; std::uint64_t aIngress = 0xC7F2C3D74D3348D9ULL; std::uint64_t aCarry = 0xC65C7F05F0E0FDB7ULL;

    std::uint64_t aWandererA = 0x83B014CADC0316EDULL; std::uint64_t aWandererB = 0xF0BCE4698B372EF8ULL; std::uint64_t aWandererC = 0xF651E59818BB64FCULL; std::uint64_t aWandererD = 0xB75AD2871773688FULL;
    std::uint64_t aWandererE = 0x87689737942B8F00ULL; std::uint64_t aWandererF = 0xA16E7062035183E8ULL; std::uint64_t aWandererG = 0xDD610A2F317D44F7ULL; std::uint64_t aWandererH = 0xE6F4EF389E8CF23FULL;
    std::uint64_t aWandererI = 0xAF2E2D1EBB247FCFULL; std::uint64_t aWandererJ = 0xE33A3C08B068C6B7ULL; std::uint64_t aWandererK = 0xC0D0717FE9EC25B5ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xA2A869DD33A9B690ULL;
        aCarry = 0xE78D4BECC4B67CDEULL;
        aWandererA = 0xB46535CADCD574F7ULL;
        aWandererB = 0x9951DFEF12C568FEULL;
        aWandererC = 0xDCE60B13D5672E2FULL;
        aWandererD = 0xFDF72A603C6B19ADULL;
        aWandererE = 0x9B56667A85E621C6ULL;
        aWandererF = 0x931C1AC17109D9A4ULL;
        aWandererG = 0xE0232C7EBA31BC4BULL;
        aWandererH = 0xEABC56E9A9EAF9A9ULL;
        aWandererI = 0xE01CFD02AF0C1E14ULL;
        aWandererJ = 0xF32FBD26F70BFC6AULL;
        aWandererK = 0xE8B885AE23F89487ULL;
    TwistExpander_Miram_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Miram_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Miram_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Miram_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Miram::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x8B468FB6C68D681BULL; std::uint64_t aIngress = 0xF557DC251C3E77BEULL; std::uint64_t aCarry = 0xCB12C1C79B9B8298ULL;

    std::uint64_t aWandererA = 0xEA4FCAAF72A3A886ULL; std::uint64_t aWandererB = 0xC0310CD792BE6B74ULL; std::uint64_t aWandererC = 0x9E32C632F073BD5EULL; std::uint64_t aWandererD = 0xCE77DF5F1535AC57ULL;
    std::uint64_t aWandererE = 0xCB1C68E6346FB20CULL; std::uint64_t aWandererF = 0xB0A379E461765805ULL; std::uint64_t aWandererG = 0xD4FC785155638D24ULL; std::uint64_t aWandererH = 0x8504E0497DBAF4B9ULL;
    std::uint64_t aWandererI = 0xA3B14379AC693687ULL; std::uint64_t aWandererJ = 0xD1EFC167F64480D4ULL; std::uint64_t aWandererK = 0xC1D49E040B334C77ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xE2E238A9C968BF30ULL;
        aCarry = 0xDE48FA1846EF5983ULL;
        aWandererA = 0xCADF860539E2AE55ULL;
        aWandererB = 0xDB57D707A171B1B5ULL;
        aWandererC = 0xF4DB0A636748E3CAULL;
        aWandererD = 0xB7D0A7234B5F17CEULL;
        aWandererE = 0xB245B2ED33BFC89EULL;
        aWandererF = 0xB244B9280A423746ULL;
        aWandererG = 0x84C52B0A044B042FULL;
        aWandererH = 0x90C95B1CB7A6E36BULL;
        aWandererI = 0x8FE157C4DAFD9931ULL;
        aWandererJ = 0xF26A879BB5E54A6EULL;
        aWandererK = 0xB64A33F455012025ULL;
    TwistExpander_Miram_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Miram_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Miram_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Miram_Arx::KDF_B_D(pWorkSpace,
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
    std::uint64_t aPrevious = 0x909FA6C841935160ULL;
    std::uint64_t aIngress = 0x80FBE8AF2151E88DULL;
    std::uint64_t aCarry = 0xF1A90EEB19A22C61ULL;

    std::uint64_t aWandererA = 0xB748F4F970EB5730ULL;
    std::uint64_t aWandererB = 0x8FEFA01B3D263817ULL;
    std::uint64_t aWandererC = 0x801D7FE95A38F766ULL;
    std::uint64_t aWandererD = 0xB13C70A68A13CDC6ULL;
    std::uint64_t aWandererE = 0xD3752E344A9224ECULL;
    std::uint64_t aWandererF = 0x9AA7A55679402439ULL;
    std::uint64_t aWandererG = 0x8B25FD7C85CEBD5DULL;
    std::uint64_t aWandererH = 0xA794831EB2A16EB1ULL;
    std::uint64_t aWandererI = 0x8990478A9365BCDCULL;
    std::uint64_t aWandererJ = 0xF7F01F306A807883ULL;
    std::uint64_t aWandererK = 0xF1887967EB7ED8A7ULL;

    // [seed]
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), pSnowLaneB, 0);
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
        TwistSquash::SquashA(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, aIceLaneA);
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
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), pSnowLaneA, 1);
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
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), pSnowLaneC, 2);
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
        TwistSquash::SquashB(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, aIceLaneC);
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
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), pSnowLaneD, 3);
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
    TwistExpander_Miram_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Miram_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Miram_Arx::Seed_C(pWorkSpace,
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
    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixArgD;
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
    TwistExpander_Miram_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Miram_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Miram_Arx::Seed_F(pWorkSpace,
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
    aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixSelectA;
    aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixSelectB;
    aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixUnrollA;
    aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixUnrollB;
    aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgA;
    aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgB;
    aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgC;
    aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgD;
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
    TwistExpander_Miram_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Miram_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Miram_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Miram_Arx::GROW_B(pWorkSpace,
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

// SmartSquash candidate 20 of 33
// Exploration cases: 100000000
// Nearest-family diversity: 920 / 1088 (84.56%)
// Total distance from earlier candidates: 17676
void TwistExpander_Miram::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    static_assert((S_BLOCK / W_KEY) == 16, "SquashInvestToKeyBoxes expects 16 invest fragments.");
    static_assert(H_KEY == 8, "SquashInvestToKeyBoxes expects 8 key rows per box.");
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 8U), *aFragmentB = aIceLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 0U), *aFragmentD = aIceLaneD + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1902U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 398U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1881U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 319U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 15U), *aFragmentB = aIceLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 11U), *aFragmentD = aIceLaneD + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1623U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 379U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 405U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1880U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 9U), *aFragmentB = aIceLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 15U), *aFragmentD = aIceLaneD + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1937U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1868U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 577U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1097U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 0U), *aFragmentB = aIceLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 10U), *aFragmentD = aIceLaneD + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 984U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1283U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 498U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 643U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 14U), *aFragmentB = aIceLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 6U), *aFragmentD = aIceLaneD + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 635U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 712U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1810U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1830U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 2U), *aFragmentB = aIceLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 3U), *aFragmentD = aIceLaneD + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1506U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 801U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 362U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 56U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 4U), *aFragmentB = aIceLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 2U), *aFragmentD = aIceLaneD + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 355U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 2010U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 197U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1069U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 10U), *aFragmentB = aIceLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 8U), *aFragmentD = aIceLaneD + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 907U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1152U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 634U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 437U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 5U), *aFragmentB = aIceLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 14U), *aFragmentD = aIceLaneD + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 544U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1945U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1569U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 668U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 3U), *aFragmentB = aIceLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 7U), *aFragmentD = aIceLaneD + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 231U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 805U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1647U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 866U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 6U), *aFragmentB = aIceLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 1U), *aFragmentD = aIceLaneD + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 638U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1578U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1225U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 959U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 7U), *aFragmentB = aIceLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 12U), *aFragmentD = aIceLaneD + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 699U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1923U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1965U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 887U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 11U), *aFragmentB = aIceLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 13U), *aFragmentD = aIceLaneD + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 740U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 595U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 345U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1959U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 12U), *aFragmentB = aIceLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 9U), *aFragmentD = aIceLaneD + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1078U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 54U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 122U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 579U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 13U), *aFragmentB = aIceLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 5U), *aFragmentD = aIceLaneD + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1849U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 508U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1713U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 2026U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 1U), *aFragmentB = aIceLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 4U), *aFragmentD = aIceLaneD + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 212U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1962U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 815U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 380U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Miram::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xCFF541988FF446ABULL; std::uint64_t aIngress = 0x8FF66C2812E44978ULL; std::uint64_t aCarry = 0xDD6C83FE13C05105ULL;

    std::uint64_t aWandererA = 0xF42D96DF7AEC2C08ULL; std::uint64_t aWandererB = 0x9074E5F68DDA0EEBULL; std::uint64_t aWandererC = 0xD26D21028659A9C3ULL; std::uint64_t aWandererD = 0xD7F22F999B26BAB5ULL;
    std::uint64_t aWandererE = 0xE62F73860561FB54ULL; std::uint64_t aWandererF = 0x90CD68CB0280C2A9ULL; std::uint64_t aWandererG = 0xC4FF10BD87F096A8ULL; std::uint64_t aWandererH = 0xE209C86D618763A7ULL;
    std::uint64_t aWandererI = 0xAB62D3A70CB30C49ULL; std::uint64_t aWandererJ = 0xD081A2B697EA7A1CULL; std::uint64_t aWandererK = 0x936330DDD4A21F1DULL;

    // [seed]
        aPrevious = 0xDB5EA05EAE728A44ULL;
        aCarry = 0xF61A5C58A6F0F0F2ULL;
        aWandererA = 0xB7927BA1F74A4E5BULL;
        aWandererB = 0xEF87DD4C81837036ULL;
        aWandererC = 0xE9B59167EC27ED9EULL;
        aWandererD = 0xD9D445420C5CCC6CULL;
        aWandererE = 0x92565F84058BF85CULL;
        aWandererF = 0xDDD8AE92103A78EFULL;
        aWandererG = 0xC39EC8CF6445055AULL;
        aWandererH = 0x8D1C490738E863ABULL;
        aWandererI = 0x876BBECF7399340BULL;
        aWandererJ = 0xF8B2BDCD1AB9D176ULL;
        aWandererK = 0xDA997BD981BE79BBULL;
    TwistExpander_Miram_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Miram_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Miram_Arx::Twist_C(pWorkSpace,
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

    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixArgD;
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
    TwistExpander_Miram_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Miram_Arx::Twist_E(pWorkSpace,
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
        TwistSquash::SquashA(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, pDestination);
    TwistExpander_Miram_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Miram_Arx::GROW_B(pWorkSpace,
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

// GrowA candidate 20 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 10341; nearest pair: 461 / 674
void TwistExpander_Miram::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3985U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 942U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3369U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6103U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7735U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3215U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 259U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7239U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1572U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1707U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3085U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4462U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7107U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 59U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4999U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6976U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 324U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2016U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 409U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 839U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 650U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1577U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 832U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 888U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 501U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 794U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 926U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 602U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1346U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1532U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1057U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 348U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 649U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 686U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 639U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
}

// GrowB candidate 20 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 10350; nearest pair: 478 / 674
void TwistExpander_Miram::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 330U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 377U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6271U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1724U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6477U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5775U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5599U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6248U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1809U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7533U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2443U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7184U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5098U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8114U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5534U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7829U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1128U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1210U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1746U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 419U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1846U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1990U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1396U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 960U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1096U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 491U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1263U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1988U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1683U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1927U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 881U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1646U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1238U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 151U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1338U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1326U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
}

const TwistDomainSaltSet TwistExpander_Miram::kPhaseASalts = {
    {
        {
            0x92079869FC998992ULL, 0xE6C1754276019B86ULL, 0xA39511C7B1777C52ULL, 0x4B55BCE7EB3E4A6CULL, 
            0x0631D45568E9307DULL, 0x51960F2249408A7FULL, 0xBBFC4145708B8821ULL, 0xD44A4850563ACB1CULL, 
            0x91F392B95DEA7DDAULL, 0xEC7F0F257EC5A5FBULL, 0x23FC49CBF7AA3F97ULL, 0xE4BB2875E5105D15ULL, 
            0xAB18D7F2EF6B47B2ULL, 0x11704BE2D9A6CF3BULL, 0x9A07B40748D372ECULL, 0x02E143DA32ECC6A2ULL, 
            0x8B609B07ABC0C302ULL, 0x006430002C07C2E5ULL, 0xC2B39D7200057BA4ULL, 0xB1DBD40309001225ULL, 
            0x8557FFBB9FFD8C43ULL, 0x8D8CADE795FED8F8ULL, 0x9F45A2380764C6E7ULL, 0xB47CCE47396D6E68ULL, 
            0x2AC7E0AF7BF1FB5FULL, 0x6EB76DC14BDB1B92ULL, 0xA51D30CA5F5792EFULL, 0x9D56C52F2EC2D984ULL, 
            0xDBCAE3AA03BAA73EULL, 0x8D6E5F06E3E190F9ULL, 0xC3072284E5C8CCB8ULL, 0xE45F3E2ECF552292ULL
        },
        {
            0x60227C5CA5EFEB53ULL, 0xBF041211B8B53900ULL, 0xEC00654588F7D114ULL, 0x6F5AFD39F0CF2640ULL, 
            0xD841D9AA03ABB895ULL, 0x1D56C7E7B138FB3AULL, 0x93B62909DDD4A4AAULL, 0x13B3AA2FEDFFB2DAULL, 
            0x7E0BFCBEB879BBD4ULL, 0xDCC4E4E6F5F325C8ULL, 0xF1828876CD85ABCEULL, 0x0EE6B2DF1F1CE667ULL, 
            0xE6D989B882EBE6E5ULL, 0x740379C9F4455441ULL, 0xCB6421F1D199FB03ULL, 0xE4ECCFC06B0BCA8CULL, 
            0x6D99F6344CE01259ULL, 0x5BB9D4B60201160FULL, 0x3EF991EDA10A9F17ULL, 0x8DC60E95280A7CE3ULL, 
            0x4D08EF41C7E92271ULL, 0x9E4830FF44052591ULL, 0xF8D2C7BD7ECC9D6DULL, 0x5D9913398903A51EULL, 
            0xE7B04AED03ECB436ULL, 0xAE776E92FFAD2734ULL, 0x37A39189131C2441ULL, 0x3F9D571870C9E3DFULL, 
            0xB7CA3EF4A8B3BD15ULL, 0x650D8CD3C1017740ULL, 0xFEC7574FEEC93A39ULL, 0x74E6BDD5A6606489ULL
        },
        {
            0x8EA82F92C3AB89A4ULL, 0x581B62A0129FFBA4ULL, 0x9665D00DCDAFBA35ULL, 0xE227DCDD58C743B0ULL, 
            0x1446891A33C8D93CULL, 0xD2C1FCD64529398CULL, 0x417CD0C3F6DA4749ULL, 0xA6279AB8378AED87ULL, 
            0x4871477F0DD5EF55ULL, 0x4C7E60D4509C8AA7ULL, 0x6B39D87FEA5B3C56ULL, 0xA6B3C1571AEFD34AULL, 
            0x9DE6A1996FAF2B4DULL, 0x00AD4B7D355913A7ULL, 0xB1150618907AA951ULL, 0xDB97F813B0E6E4AFULL, 
            0xE1B4E7D960244C7AULL, 0x96A0C88A649DCE6BULL, 0x36241C93405BDCDDULL, 0x19F51E71F0809037ULL, 
            0x33446683DEC90F78ULL, 0x1DA6C86653E59B7EULL, 0x2C41BCD61F203D2CULL, 0xC4CC51FEBFA4C930ULL, 
            0x6B2373046BDBE109ULL, 0x133C709C128DF93FULL, 0x59EB66DF15C3BFB1ULL, 0xA137C13EE0337A77ULL, 
            0xEB2A3F4C25DAA5A0ULL, 0x88B7A6CC072D67B1ULL, 0x384B90DB319E867BULL, 0xBD8EEC24B0203ECBULL
        },
        {
            0x996595D677D8D693ULL, 0x7AE9AC9AD08ED452ULL, 0xCDBC1D94251BDAE8ULL, 0xBCC72041E41D15A8ULL, 
            0x1AFEA5697CC5D475ULL, 0x39C06C28A07B9F76ULL, 0x71B6F262537E03CDULL, 0x592C9D0CBFC7AECFULL, 
            0xF54490B571F9A361ULL, 0xDC26E4419306912DULL, 0x7F482B3B4016B919ULL, 0xB682544FD6B13264ULL, 
            0x7D06E281D972E800ULL, 0x8C570576C841DEACULL, 0x7254EBF504569D54ULL, 0x6CA4D1763CCAD9B7ULL, 
            0xC12DCE1B93723396ULL, 0x4A607CC524406495ULL, 0x014E5C1D88D56C97ULL, 0x2D816F56C7E52F23ULL, 
            0xF5E7527FCAF53B99ULL, 0x45BCEC0F594C9305ULL, 0x6611C91EABE92DBEULL, 0xA3A03EF41791C4F6ULL, 
            0x8F864EEB061C8DF8ULL, 0x5605B2134CDE391AULL, 0x5BB3FAC2787C9B7DULL, 0x6CB32EB7E652FBEEULL, 
            0xE74F9D12AFF52A30ULL, 0xC203BF93BD3EDC2FULL, 0x301F6A0BFB368D37ULL, 0xF14AE0C80FF0775EULL
        },
        {
            0x543BA4E2C980FC6BULL, 0xE28E697AF0D6158FULL, 0xD27E066A90008212ULL, 0x80887B3F774A26CBULL, 
            0x509DDA9E9E17E45AULL, 0x5193EBE0057991CFULL, 0xD51A083CB1FF096CULL, 0x91396499C1B5746BULL, 
            0x4373D745344C9008ULL, 0xD521CFDD2F373B47ULL, 0xCA2C9D62BA613579ULL, 0x19F5DC70E7F852A4ULL, 
            0x2E5E9E14B8159C53ULL, 0xC02E6AB85FD6B93EULL, 0x9CA80194E0861FDFULL, 0x689417C0D6934AC3ULL, 
            0x636B02E2EA3B5AA7ULL, 0xDEAA0D782F3F0042ULL, 0x1BBEB6A7B16C2A44ULL, 0x9F03C31979265B42ULL, 
            0x655FADFB0E988560ULL, 0x3D6A538DE7EAA218ULL, 0xCF44D31D94B69802ULL, 0xBE92637BCB74286AULL, 
            0xC60E8DADB0C4A3EFULL, 0xB719CA871B325D12ULL, 0x9B16F9FF363C4B8FULL, 0x2BEFC6A8A83A7A32ULL, 
            0x50DEE0CAD4825B9DULL, 0xD3176187ECF5CE4AULL, 0xBACC69257FA1F4BFULL, 0x50FBCF632F35C7A9ULL
        },
        {
            0x8809751C2021E7BFULL, 0xE493221B25412512ULL, 0x51A21D4FAE5CC646ULL, 0x6E45538119B2E1A2ULL, 
            0xE1E58003FF494001ULL, 0x621747C391435249ULL, 0x381725AF7B24779FULL, 0x9CC336399FA310F4ULL, 
            0x773ADF5942C35BB5ULL, 0x1BBB8E2819617DC0ULL, 0xFE8C6826952B597CULL, 0x0685CFF75F43150AULL, 
            0x3C4ACF83B7A77BA9ULL, 0xFB15D254620A2B6AULL, 0xAFC990804B5B52CFULL, 0xF4AAA6BB55AC13D3ULL, 
            0x863C3CFAA7EBBCBCULL, 0x487AD02086EE30ADULL, 0x4A3793D7DC9A441EULL, 0x6EC4A66E252F3A63ULL, 
            0xB85293EE53A689EFULL, 0x790C3C9CEF48B9AAULL, 0xBCD45A567B41E395ULL, 0x3FF9CF1FD14F568BULL, 
            0x7415392D3F8E5583ULL, 0xBC8326329BFABAE3ULL, 0x4B2E15D3E1F410CAULL, 0xD318DBB3D1B17473ULL, 
            0xE1227AC8CA07AE9AULL, 0x113162242B211D39ULL, 0xB300F2927A504C6DULL, 0xC1EA3DF149AEFCAEULL
        }
    },
    {
        {
            0x7E432594A19EDD4BULL, 0xDE81FCDD5B1D85BCULL, 0x86EBA8A97DB1260EULL, 0x68E3CBB5C6F83A99ULL, 
            0x2AFA5C28169AD0AFULL, 0xB0C5CAC78AE5D9E6ULL, 0x5B1BBE65BE7DA265ULL, 0x055516D2BD92460AULL, 
            0xA7C5A866C87427E2ULL, 0x56D2E89FAE0212D3ULL, 0x5C6655D8EC294492ULL, 0x9AA9FD0C15200A3DULL, 
            0x5D7847567CF6F37DULL, 0xE8BD38E3AFF8C460ULL, 0xDE866D0DE6999391ULL, 0xCF80E0ABCFF7EB32ULL, 
            0x9DCDF948EAB248EAULL, 0x2799F588F84A7FF5ULL, 0x79B42FD751D90104ULL, 0x90C656313FE7A4F3ULL, 
            0x8852ADC4D1C78BC5ULL, 0xF022572A66875984ULL, 0x6474918504747777ULL, 0xD1F626316D5D09E5ULL, 
            0x4CFE328B4043965DULL, 0xCBD9BCD6A818D489ULL, 0x05F0AD2A14C5AC50ULL, 0x23B9E390A326A05FULL, 
            0x80208782A22CEA2DULL, 0x1C250B7EAADFAFD0ULL, 0x591511B5BEE8B52DULL, 0xE2FF289174FD2412ULL
        },
        {
            0x9C1CA31CB43704D1ULL, 0xC643D6320FADA2F8ULL, 0x1A1D2A1053FFE727ULL, 0x91A03A5DB79E84EBULL, 
            0x1DA7433C5CAA85C5ULL, 0x688099A8B6227400ULL, 0xA09DDEAEE95645BFULL, 0x8DEFCA76E6F12DAEULL, 
            0xF0398A11A7DC996CULL, 0x89F31CC013264195ULL, 0xB77BF8B7F4B88D6CULL, 0xAA91526AF675FBFEULL, 
            0x35F2BECAB003A7CEULL, 0xF0E5028755BA12C1ULL, 0xD91CCDB1A8613858ULL, 0x27C6933FBC46235AULL, 
            0x78DBB6B87B3CE2FBULL, 0x04A16D9AB2D481B6ULL, 0x8C64E09BD9634B32ULL, 0x4CAB8F5D138F2E7FULL, 
            0xA26D1E5BEC530CEFULL, 0x4D725562703EC133ULL, 0x1FD669E4C0BEC4CCULL, 0x5FA81D3E181CC247ULL, 
            0xF96236A4056D8D47ULL, 0xD4D19D7F987D30B3ULL, 0xDB3D0995C7A98141ULL, 0x560EF5E854DE9821ULL, 
            0x624473F22430C5FDULL, 0x3768BFA1CB29A585ULL, 0x7A93056152EA4798ULL, 0xEF896C87643C17E5ULL
        },
        {
            0x75E714935628B48AULL, 0x42A8583951196597ULL, 0x6C0A21ACD536C00CULL, 0x5B0A47C5EDB8C8E5ULL, 
            0xDB70D22FFBC773A8ULL, 0xBA50A202BA1CCB94ULL, 0xB637CFED97B3F6AEULL, 0x6347F4E73EF590CFULL, 
            0x4FCDD5C9A26DC8ABULL, 0x036A7C3471F7FA93ULL, 0x4DC36BE61D231B4BULL, 0xD8B872D433895FBBULL, 
            0x213557AF8E05132EULL, 0x19FD5DC4E3F1A1F4ULL, 0x8F4C30D0B0E69762ULL, 0x7F18F61AB334085FULL, 
            0xE98BF5AD6901BE8AULL, 0xB9A422AECCBA25F5ULL, 0xEC1DB782939BD447ULL, 0x261B3298D5A5601DULL, 
            0xE7E08E15947A39D5ULL, 0x1A7BD6CCA34173C4ULL, 0x1EF8F3304918140AULL, 0xD48E2938688337C9ULL, 
            0xE39789CCA0819A78ULL, 0x894DDC58DDA982C0ULL, 0x9B7FF11955DFD7ECULL, 0x7D77C8F2E311462BULL, 
            0x88E3921690B5452EULL, 0xBDAE70BB0BB24A61ULL, 0xD7FCF95E500D8F30ULL, 0xB8AD1269F816D7EDULL
        },
        {
            0x331EBC9949CBC9D6ULL, 0x6C567C9786FE048EULL, 0xF6A250C18F4AD1DFULL, 0x525F3C388427A071ULL, 
            0x41746EE36F5E7AC9ULL, 0x3885FAE14C94DC3CULL, 0x0611A22045275D30ULL, 0x682393449C4A5EA6ULL, 
            0xB7E5DF2B18A142C7ULL, 0xA1B45552B6793495ULL, 0xD7091C5C8E2ADBE9ULL, 0x030C475915B0F06AULL, 
            0x9F2A8EF17D2484BFULL, 0x9DBB7D3AAE97F020ULL, 0x5C8BD19AE00FD1C6ULL, 0xC2058EA3E69E272DULL, 
            0xFFEE49BCA2A466D3ULL, 0x365E6361FA4D18DFULL, 0xDE6A091C47F3AE15ULL, 0xEFF9249F3D1E124FULL, 
            0x1F2CA07679BFBC91ULL, 0x3FEDB9D9AD3267F5ULL, 0x7029CADA63B781F4ULL, 0xD8DA43B8B3DB9C0BULL, 
            0x1B177EA4739B00F1ULL, 0xCC66EFA88550D511ULL, 0x9E86F7F567F8BE18ULL, 0xDC9E851FA7634D40ULL, 
            0xE30689BE1010F588ULL, 0x3B1BC62534CDF271ULL, 0x594F365F27EFED93ULL, 0xCB0ACDCAA261B273ULL
        },
        {
            0x18F4807FA57ECA04ULL, 0x72BCDCCE2E3AFBF7ULL, 0x1959B3B7E6218967ULL, 0x89D75ACCD89458D4ULL, 
            0xC632391EC0C6B159ULL, 0x0043D0795CD0A479ULL, 0x22AB15F11BDB83CDULL, 0x5922F8CE9C3FBFFAULL, 
            0xE7666F4EF21F0E7EULL, 0x676A10F863A26AE2ULL, 0x64E9FA4C668E47F5ULL, 0x2823513DE0240469ULL, 
            0xECA9EFA085FBF0BAULL, 0x6100F346A3995A93ULL, 0xDBD8E1BD4683368FULL, 0xDD1A831BF4CE416EULL, 
            0x0FCA9A70DC15D988ULL, 0x20684DA8638B8855ULL, 0xC478E3B8E6CD54ABULL, 0x8B9A4A7B508C3849ULL, 
            0x79F0E56763651927ULL, 0x6F1386722A7D89D3ULL, 0x673F53F54C6F87D4ULL, 0xF0429D55E630F587ULL, 
            0xF358B0D50828A3AFULL, 0xFDCBB050D9CF0751ULL, 0x2077E75A07C86EBBULL, 0x8319AEED144C1520ULL, 
            0x5107C5C3650A84CEULL, 0x9CC2DD82DE67F6FDULL, 0x8BCAA71491608D84ULL, 0x8D849C028E806553ULL
        },
        {
            0x94290D84AEE68515ULL, 0x3A8A3744DC371103ULL, 0xF9544A001A5CD7B7ULL, 0xECA52B20C6C00AF8ULL, 
            0x8568ACABA0E462ACULL, 0x7EB3E47904EABC84ULL, 0x51F2BA0DDF761E12ULL, 0x45F5F276BC455131ULL, 
            0x2E3054FAC41453C8ULL, 0xAA40CECC5DC56012ULL, 0x3406FD9E2C705107ULL, 0x4B968D17DCD9917BULL, 
            0x383FDDACEB486C27ULL, 0x4F6B492F9545F6A8ULL, 0x030C72E2652BB9F4ULL, 0xF41F3049848BF8EBULL, 
            0xCC121C0D688D1BD5ULL, 0xD371DADDFE7DD1B7ULL, 0xF6D078F1B030CE30ULL, 0x42EB0C93D4DDA527ULL, 
            0x3F227A11E501F8F9ULL, 0x16B3534437D21D35ULL, 0x1608E43997537DECULL, 0xDE2700050E39A735ULL, 
            0x29739AF346C2B146ULL, 0xF269622E7B568E45ULL, 0x202B26E1118E503CULL, 0x2D412EDBD012EFA4ULL, 
            0x639CC7EFEC76D9C3ULL, 0xFAAA28581BA9E3B6ULL, 0xB53BC51403E1D844ULL, 0xD53F1FCD46E44C64ULL
        }
    },
    {
        {
            0xD893A9BBD2FB54F0ULL, 0x71FC4A635A35B32FULL, 0xF9E2F2B82B8123A5ULL, 0x45CA72671D98F92BULL, 
            0x1C7F4C2FF0F3346BULL, 0x339F635BB6EB8EC1ULL, 0x939F0B9E893508E0ULL, 0x107814F7996868B2ULL, 
            0x476C5791D7E54FECULL, 0xBF6338E6AB564938ULL, 0x1E194B2E8D9A830CULL, 0xBF780D1B40E4C0A9ULL, 
            0x28B66ECEA6DE092AULL, 0xA74B0F4457771446ULL, 0x9CAEFF98E87E0CDFULL, 0x7CD40FA0C4D2FCB3ULL, 
            0x90C1414FABB8AC47ULL, 0x9D4AB2D7AB087AB7ULL, 0x8B6940FA59C9642AULL, 0xC3E8D84E7576A92EULL, 
            0x89DE8549EA456319ULL, 0x4F6532BE43A6C9DCULL, 0x532CA31DA071DCABULL, 0x047F8A155CEDD7E3ULL, 
            0x983C1C010622EC8EULL, 0x5D8B9440922D6545ULL, 0x8737646D9189B1C9ULL, 0x827D1DBE0CD8D9ACULL, 
            0x9E3E0594ADB4DC75ULL, 0x5430F0C3EDEC640EULL, 0x0AF9D04906EF72B0ULL, 0x60923F84D6CE90BFULL
        },
        {
            0xD0D17F86B32AEFE0ULL, 0x85835FBE38DCDD41ULL, 0x3918E77B9A0B8602ULL, 0x58752C60F86AF749ULL, 
            0x1C499648D39936B7ULL, 0xE961FF39A319FDB3ULL, 0x1585654782483BDFULL, 0x7D6CFD99D8F55754ULL, 
            0xAA1F22856C689EB3ULL, 0x705D1F9122F182B1ULL, 0x2008DB69A6FD76A9ULL, 0x09AF7B7A87462658ULL, 
            0x5943C4CB65FAB6D3ULL, 0x68EF5D6091EAC9ABULL, 0xF0D7A341325DD2D6ULL, 0x11E7BD068344E388ULL, 
            0x5998501B37B5797FULL, 0xD91EBF8DA0EF8C55ULL, 0x95F35C76FD10E6FCULL, 0xF1E74C85CEFC8F7FULL, 
            0xCCB1BBA05881AA7EULL, 0x69A662AA6151F236ULL, 0x6ABC4EBA3FCA06C4ULL, 0x69F0C79F467B6E1EULL, 
            0xF36262F81E6D0B3CULL, 0x3A35E199383C5F5BULL, 0x10D7B979C6E5AEC2ULL, 0xF81AF4DD68233572ULL, 
            0xCB5FFBC7DC21BE5CULL, 0xC1BF8F4528A501A6ULL, 0x2904D1B79C55DFB0ULL, 0xAEB4C786AA72CDABULL
        },
        {
            0x001587863D146223ULL, 0xF3E2E097B4F6C874ULL, 0x8521941682E230DBULL, 0xB3AD835EFC8E9F35ULL, 
            0x58518C53F792FD26ULL, 0xCC980AE36500811BULL, 0xAF52EC88F2652008ULL, 0x045623CE15093637ULL, 
            0x207911FD102B5507ULL, 0xA52EAC373DADBE06ULL, 0x0F07C259FD03BE72ULL, 0x4DEED5ED74290A16ULL, 
            0x9A3D9900400DA3E7ULL, 0x5B5EB95762692ABDULL, 0x4E2478412107AB96ULL, 0xC233D34166A4821AULL, 
            0x73AA52F61DA6C4A7ULL, 0x71A642C9400BC0C7ULL, 0xE80F779140B49A1CULL, 0xD0A430E852CD003BULL, 
            0x7B31FC5CA46212E5ULL, 0xE4633461346C61B0ULL, 0xDE075B4809A47308ULL, 0xDB086ADEB6FBB63AULL, 
            0x4B94159C189FAE76ULL, 0x8793D22772D2FFC6ULL, 0xDF6DB9E030364BF4ULL, 0xAA1E9458D4EFC206ULL, 
            0x08D914AFE046BB61ULL, 0x1D4EA4FFDB8E8352ULL, 0x8739A6DCEA364284ULL, 0x9F7F03C7BC52597EULL
        },
        {
            0x6461986DC4EB9B48ULL, 0xE19F2A5B6B78254AULL, 0xD2926DCE202BA1B7ULL, 0xD34359C0CC4D8F5BULL, 
            0xC331DA3487A8190EULL, 0x2A4EC9211C304117ULL, 0xE5DE295D2D97D702ULL, 0xCBB58D51CCCA9A95ULL, 
            0x2B238555F0471179ULL, 0x7312E0982CD7BBB3ULL, 0x7CC59EC486AE6CF1ULL, 0xC843D4C59CAE562CULL, 
            0xB7F09DA856E5B00CULL, 0x078B2B3115197AB1ULL, 0xD479BE53726BA2E1ULL, 0x8F56446FFE936A96ULL, 
            0x6A7F2B241B9866C2ULL, 0x2CB5F637E20F8468ULL, 0xF575A43C5537B6F0ULL, 0x752BAE11AD573B01ULL, 
            0x06F73CE9349A69F6ULL, 0xFCB24AE84D87B2E8ULL, 0x4610B6D2224F1F65ULL, 0xB63B4E2D6393D07EULL, 
            0xB7A55CF9DFC0C497ULL, 0xDDCC8406B46EDA26ULL, 0xD1EEF7EDF817416EULL, 0x781D55233396BCF9ULL, 
            0xBFA023C5C5962145ULL, 0x007DA44D6B44B349ULL, 0xA2BF06F84EEB4110ULL, 0x294941192D6A6CD0ULL
        },
        {
            0xF77E82586E7B1816ULL, 0x7B17F35BA0CFD3A6ULL, 0x16031C2CE47B49AEULL, 0x1E449615834BBF9EULL, 
            0x00F40AEDF208FAFDULL, 0xC649FE58C1613C48ULL, 0xADF75C10A0065DD2ULL, 0x9C1B09117252FD4FULL, 
            0xE6B0DAC2C4B820F7ULL, 0xE868D8218BD4B8D8ULL, 0x80EAFB3EE8EF4524ULL, 0xCC801822421F2AC0ULL, 
            0xBF8B960641A3B54DULL, 0x7E744ECAA747B985ULL, 0x0004FA80A3D04AB1ULL, 0x489B1EA357BD4AA2ULL, 
            0xC487C923CFA8C080ULL, 0xF80015710E5839D7ULL, 0x8A9E8B73232E5858ULL, 0x22CA08955E88BFC9ULL, 
            0x1D2EE0AA470072DCULL, 0xD67511B16D52C7F8ULL, 0x1310A70B93D6E538ULL, 0xFB035E417795B89DULL, 
            0xDB6D6E24FE5E97ECULL, 0x0D9401AF0431D011ULL, 0x3298F76CDF297FE0ULL, 0xE93E0DBFB7120CC5ULL, 
            0x928D8B390679426BULL, 0x179E2EBA8A8416F1ULL, 0xAAA65CF2E2E7E617ULL, 0xEB3BA8DB6BCBF9CAULL
        },
        {
            0x2378458AD5D87685ULL, 0xED7BA36DD87D8263ULL, 0x4C41A213EF94E421ULL, 0xB2F5EC37E9EAB7D4ULL, 
            0x46E1DFF7D47208C4ULL, 0x44DCE8A7267E806DULL, 0xC7F8DD76690231A9ULL, 0x65A0F942B4972395ULL, 
            0x0C6CA06B424457F4ULL, 0x833C759EFF0FBED1ULL, 0xA85175F7B4EFEA83ULL, 0x45B61CB6989CF9A1ULL, 
            0x4C537D40B1CCBBE2ULL, 0x310CD05B12EB763EULL, 0x5CE5716C53C5D721ULL, 0x70A6074DA8118B74ULL, 
            0x849A347A3ADBB532ULL, 0xE9D6A3B13788E6A6ULL, 0x0CCD07C4C40BD5CFULL, 0xF49CBD8B75FA1341ULL, 
            0x482E5BF9F1DDE0B6ULL, 0x139AA3067C7FE8E8ULL, 0x48900233D8E83C48ULL, 0x32E8D3DAF0271574ULL, 
            0x7B9F3AA472D427CCULL, 0xBEA3285B455AFA5CULL, 0x5AAF330BBCEA98A6ULL, 0xF98392C3261289E5ULL, 
            0xB9EC436935539082ULL, 0xEE2386138763589BULL, 0x075BC62EBA203F22ULL, 0xE8A6320D0802F2DDULL
        }
    }
};

const TwistDomainConstants TwistExpander_Miram::kPhaseAConstants = {
    0x2710E661AE51BCA7ULL,
    0xBB75D7541ADD86A2ULL,
    0xCD98834D46A81555ULL,
    0x2710E661AE51BCA7ULL,
    0xBB75D7541ADD86A2ULL,
    0xCD98834D46A81555ULL,
    0xEDC8E12FD17EEE17ULL,
    0x98C1186E20B1D03DULL,
    0xA2,
    0x58,
    0x1A,
    0xF9,
    0x9E,
    0x37,
    0xBA,
    0x16
};

const TwistDomainSaltSet TwistExpander_Miram::kPhaseBSalts = {
    {
        {
            0x8726A4A7CB0120F7ULL, 0x8DDAE042CCA3EAEFULL, 0xDB5F66F47D06F9F9ULL, 0x410CB3E353ED64BDULL, 
            0x03243F2A300CACB1ULL, 0x3EC2F6E572B9039CULL, 0x7D534964843FBF41ULL, 0x624655C11186AC2FULL, 
            0x4DB5802363636BF3ULL, 0xA77E2EDDFF5CFB17ULL, 0xC837D54862CE999FULL, 0x0B40C9006B9E9585ULL, 
            0xCA82695FF026776FULL, 0x614EC8F0917C6D33ULL, 0x744BC6BC203949E0ULL, 0x5A01FD8D7C2E8C5DULL, 
            0xE42A3929124A1011ULL, 0xD2EDAF7C24120AA9ULL, 0x84504490A51C1199ULL, 0x1283885E31942D13ULL, 
            0x424F9E83C2161559ULL, 0xFFD599D86B2A0A02ULL, 0x8DB56D05C23CD9D3ULL, 0xEA36F5F9BBD3C3DCULL, 
            0x7E46A3C3FD578B12ULL, 0xE7F9979A59E36931ULL, 0x5934F41D2E8B5481ULL, 0xE54DF2EB84D6D2C3ULL, 
            0xD9288B3F483BFFEDULL, 0xA26AADAB134EDD30ULL, 0xC6B127A95322C75AULL, 0xE2A9E36FB092736EULL
        },
        {
            0x11529A617A19B041ULL, 0x8788F3CD277D50DDULL, 0xA6F89395315A3D08ULL, 0xAA21F4787BF5F270ULL, 
            0xF924048D8B6A9DB0ULL, 0xB33B235CCDAF451AULL, 0xB65B7165EF8CB039ULL, 0x030412C16AC93C13ULL, 
            0x688B6BD91B18B7DBULL, 0xC13A0096578489C6ULL, 0x6074CF9C0E0A3B3EULL, 0x5613F31C429A5BBDULL, 
            0xA05E4303C02EE547ULL, 0x0F776B3693175BFBULL, 0x0F322A217A0EA795ULL, 0xB811EA66735BF64BULL, 
            0xE9F5A898D3785371ULL, 0x86D5CA1117100252ULL, 0xB13D1F4C09426B0DULL, 0x0D3017B34B418EB0ULL, 
            0x26ECD116CDD9B773ULL, 0xFD3BB86AEA3D44E7ULL, 0xF17D73C0ACEB975BULL, 0xE75D95CDF66FF3C6ULL, 
            0x38D280B7B56E1BDEULL, 0xAE0B824671B34672ULL, 0x3C60BF651C5A3AA0ULL, 0xE28040532C51381CULL, 
            0xCA957571B3528D75ULL, 0xB09642EF9B0F819AULL, 0x57994BC0FC83E5D1ULL, 0xDDAAC048D1B08C03ULL
        },
        {
            0x358443929C41E0FEULL, 0x70C09FECC4EB0DB6ULL, 0x2E41D91A4BAF88C8ULL, 0x4871E3FA494144D8ULL, 
            0x63EC1CE8E6FC396CULL, 0x972BE6A1A93986C5ULL, 0x6EC72B53B68AAE52ULL, 0x6DFAFD0E63083639ULL, 
            0x22910524A44467BDULL, 0x1CBA499A87A7CE48ULL, 0x0DB25BB4380D00BDULL, 0x1A5FB3C0DD42742AULL, 
            0x1A02ABEF6E51B065ULL, 0xA1974462DC3902BAULL, 0xB0BA3589991A9BDEULL, 0xEF93465622D6E8FFULL, 
            0x6E6EEACFBB0F165EULL, 0xD41726B7A2E7ADCCULL, 0xF57A557445A034FBULL, 0x46CA60482328E6CDULL, 
            0xB887B664737430AAULL, 0xC045BE666ABCDDB3ULL, 0x6A9C0A5DC18B5F59ULL, 0xE480D56FC51E1F05ULL, 
            0xE5DBB0A3C9229201ULL, 0x761991A70270F995ULL, 0x8FF344FFB5FB4BF6ULL, 0xD2C6B3348E91A2FEULL, 
            0x08E425891EB5B94EULL, 0xE931423503FCEA86ULL, 0x5781D85E04ACB0A0ULL, 0xA975B404C86C3D2FULL
        },
        {
            0xA1587FCB8BFC72C7ULL, 0xEA3D782F9A2CD428ULL, 0xB145E45031359A04ULL, 0x8420444AA1303291ULL, 
            0xB17411C512011718ULL, 0x6D0CA498ACC9F725ULL, 0x82CE2F8B3F4473C9ULL, 0x314225E114925C6EULL, 
            0xDCAD191812E1221FULL, 0x8F1F28B34889D58FULL, 0x3BDBAB2C5B0A1CB0ULL, 0x6A4C02FE8A73296FULL, 
            0x7CCB1301A30F9BCEULL, 0xF5375F74A0EFBC26ULL, 0xB3A8FE9935DD638EULL, 0x9EBC11FA7677CE33ULL, 
            0x98BDC38D5274D8A0ULL, 0x6551A7DBDE20DE35ULL, 0x1A57DCB54F37C15FULL, 0x95C8FD41C9CE3E25ULL, 
            0xF19DEDEEC1366C4DULL, 0x763BABAE5E559927ULL, 0xD8759FE4FCB2F5FEULL, 0xE1F83AF0A01C6BBEULL, 
            0x10B93679821D1FC2ULL, 0x34C10740146DC7ABULL, 0xDFE2EB7A3C83D3A0ULL, 0xB3133AFEC79FF367ULL, 
            0x22DB697729B9FC6EULL, 0x3FE66D3F356763E8ULL, 0x70903EFBF231CA44ULL, 0xEC2E02D32E3BC210ULL
        },
        {
            0xA0516FD53A0EA00BULL, 0x289157575469679CULL, 0xF319400EFCBF6CC7ULL, 0x8254DD5CB8E338D2ULL, 
            0xF73DD3B7B30AAC39ULL, 0x4315DC69026E2BACULL, 0xCBABACEE9F119980ULL, 0x0EF636B2D258F889ULL, 
            0x4EECAD81F12C3EF6ULL, 0xD66089991184E0A5ULL, 0x71C5BE5D00C68CC7ULL, 0x30CB6545BF2F09E4ULL, 
            0xA9C15CDB7E5F9CD2ULL, 0x9BF1E9DDB55EB440ULL, 0x7B293E9071572AF6ULL, 0x3567DFF953D4FDD6ULL, 
            0x361BB95FBCAA339DULL, 0xA556F79ECD9A86E3ULL, 0x78DE8439705ED9D1ULL, 0xEAB68FC8F18ADEBEULL, 
            0x0ED5F61CDEB64106ULL, 0x1CABC1673B82F597ULL, 0x3795B7095BD16746ULL, 0x1271334AAF108E2FULL, 
            0xA89DC2DFA44EBDA9ULL, 0xB7BC62136B264408ULL, 0xBCBB989E997A241CULL, 0x4D7B37A515CDB060ULL, 
            0xB087D40C61C768B2ULL, 0x6A2A5A99888128F6ULL, 0xFFB6FFBD2195D9B8ULL, 0x439F9A377E5069EFULL
        },
        {
            0x9D21E9E58CFB7F95ULL, 0xCC5CC32EB8F9450FULL, 0x71157956E0F525C4ULL, 0x4A20CF9FA4AC70A3ULL, 
            0xE66225A48B794C57ULL, 0x51C21A798758A815ULL, 0x748C9C1783CF2012ULL, 0x1DDF9BCDD90FF950ULL, 
            0x439C3ADA9D28D17BULL, 0x156149DE7625176FULL, 0x04B7646FB75874B3ULL, 0x705AE16A4277835FULL, 
            0x2D4379FA5ABBA615ULL, 0x0A886D070F4023C5ULL, 0x2934BD151B2E7F11ULL, 0x06443A7C2BA3AC5AULL, 
            0x7B21A9E55B55EE29ULL, 0x98F3425797F0D013ULL, 0xE10449E5E1772625ULL, 0x2A5751D8A00BF7EFULL, 
            0xDE8A08E8992B036CULL, 0x86BBE01A96041FABULL, 0x7C8B3AC68D4B44DDULL, 0xC7C5A89F8754AE87ULL, 
            0x3BBDF2ACB5655FE3ULL, 0x2DC78D6EE469621CULL, 0x47142B858F202C83ULL, 0xEB455E7A07DDF6E8ULL, 
            0xCD4F9FDBFDB17EDCULL, 0xADE254BCF83EA729ULL, 0x1965BFC74716ECEDULL, 0x77C85304B96788ADULL
        }
    },
    {
        {
            0x4DCAD176654A775DULL, 0x9148C1BADD474408ULL, 0x8D1D3A3C2E57714AULL, 0x1B53B250368A6C36ULL, 
            0x988B87A03D2B6C79ULL, 0x733ED24563204510ULL, 0x81F879B8CA505ADCULL, 0x51D0B3C32FF43A32ULL, 
            0x56454E752203D0AFULL, 0xD0E3BB3A4AEF73F6ULL, 0x562FFA77EFC76C73ULL, 0xAEEF41690B51BEEDULL, 
            0x1E122497285D7D13ULL, 0x902C5CBD7E7ABF61ULL, 0xD50232B115E58AB9ULL, 0xF25E71462C37F1F1ULL, 
            0xBEBA38224B1043A6ULL, 0xA8AF2E7383BAAE87ULL, 0x28AFDA640F4E3D04ULL, 0x67BBF13A6C532BB6ULL, 
            0xD48A75886F950F63ULL, 0x3F33D9D2E295AD28ULL, 0x87E69B61E2B9730AULL, 0xEEB00773DDCE25AEULL, 
            0xE191BFCCF1002137ULL, 0xDC57CEAB9C82E857ULL, 0x1E41144544521CE7ULL, 0xED37BD583449F86DULL, 
            0xF64C49988F8DFAA6ULL, 0xB55DA6477C393822ULL, 0xF5C8B33A38587B5BULL, 0x2A8BC83D1515FD13ULL
        },
        {
            0x5DAC13930E6213C0ULL, 0xC111C53BB938AED5ULL, 0xA0A386510D7A0D73ULL, 0x33FFF51B0A6A8FBDULL, 
            0xACBFC495C20C2A32ULL, 0x08942FA83C8D3EA5ULL, 0x91F0ACA0C25187A6ULL, 0x29B518051AFB6E4CULL, 
            0x59729F06BF730AD1ULL, 0x5AFA4C02A14B4B13ULL, 0xA44AE79CDEA635D8ULL, 0x3620486C93D1F707ULL, 
            0x1C3F335BA7AF5EE9ULL, 0xC644E0BEEC7045F7ULL, 0xF770CA608B724458ULL, 0x9AEA3587641C8705ULL, 
            0xCD553D0C2141BBE2ULL, 0x7AC3675097BDB15CULL, 0xC5D60611CC8E501EULL, 0x2519A033589EE691ULL, 
            0xE7DC4E764D9F143FULL, 0xA036347F6CD97F5EULL, 0xDC89FA72F5805F7DULL, 0x3C70EBC21F97FDB7ULL, 
            0xAFC0B296E9C72E59ULL, 0xD81EB9C7605AEA9CULL, 0x1A75084156FD9ACAULL, 0x95C22785836A0A62ULL, 
            0xAF4D718D15271809ULL, 0x7F56E34C647BD4C1ULL, 0x7726187E6BC0FBDEULL, 0x2CF0BDDA4AA0C32FULL
        },
        {
            0xDC6BC12915085139ULL, 0xE2A41783BB48663EULL, 0x0013BB83CBD97C4DULL, 0x7D0A9265250A809CULL, 
            0x36F378AF8E864021ULL, 0xC6E0ECF4E416D9DFULL, 0x988D5062AC3F6F3EULL, 0x71329DFC9A01E821ULL, 
            0xDAE5B070511A674AULL, 0x6B49614FD55A3BF7ULL, 0xC721523787A93C5BULL, 0xF31FAF9B62EF2FE8ULL, 
            0x56F632F7A09FEE2CULL, 0xF00270AA3E315C2EULL, 0xA10396F590A5A0FDULL, 0xC89FB692B81A1A92ULL, 
            0xA0A4900D3C156795ULL, 0xDEE8F748BCE7CF84ULL, 0x92EC19494322753EULL, 0xEB8CD6489B939E2DULL, 
            0x03A5244878348D64ULL, 0x54B4A2114872FC42ULL, 0x748C3FB26BED52B3ULL, 0x3CB096AE11F8ADB2ULL, 
            0x6BB2BC20A7BEB723ULL, 0x61829B238E140EFDULL, 0x8B02CAA0EB39DAF7ULL, 0x37D72DFE0B8484CFULL, 
            0x51BA967BF6FF22CBULL, 0xB95FDDE527AE152AULL, 0x97D643BC60B89A9EULL, 0x5AE43EA26BC982C1ULL
        },
        {
            0x3126F606BEE1874FULL, 0x9ECFAEA9D8C9183EULL, 0xD319052CC72BF6D7ULL, 0x4012F9EE7031C483ULL, 
            0xDC64F2BB4FA1D7ECULL, 0x7F8E74BF95C75049ULL, 0x23BEB15CE7BF2735ULL, 0x27EB770700958FD7ULL, 
            0xF228B84D9C3FEB35ULL, 0x12DB6D1579BB65D1ULL, 0xF93B9EE1FCD8C6B1ULL, 0xB5FF9A08648FBC82ULL, 
            0x625E3258C4D0E2F2ULL, 0xF305FB65451E64DCULL, 0x8C4DA2D2F26CDFA4ULL, 0x1584E7511FC173E8ULL, 
            0x4EB54FD9615651A5ULL, 0xCF642E5D2F6E91D0ULL, 0xC64F7E526370C13EULL, 0xE17665F936CB6DFEULL, 
            0xC7FE318DBD538CE2ULL, 0x1774245AE60CE1D3ULL, 0x30C889148D1A25C4ULL, 0x65082B1229CF7104ULL, 
            0x42912CA60433B610ULL, 0x9F612058815B6154ULL, 0x24D19D04B484FD05ULL, 0x5312998685726CA0ULL, 
            0xFA7D83AD3FF19717ULL, 0x7C1DAAED724BB456ULL, 0x890D29473787E86FULL, 0xDFD3C05D7B6A660DULL
        },
        {
            0xB8C0977970603E69ULL, 0x023074D5739C7553ULL, 0x40AF5EAC50EC8221ULL, 0x675740DC75A117C9ULL, 
            0x1B7AD6A2455126CEULL, 0xE47A1BFFF9B09DE3ULL, 0x840CDE045E18F400ULL, 0x04FEA111F56C66FDULL, 
            0x7B3A8409BAC00513ULL, 0x3E62EFDEF30F9E76ULL, 0xFD7F8B972A459FDAULL, 0x6C0B60AEB2B4EDB0ULL, 
            0xA9AAC918F2E83E06ULL, 0xE8A8F0825EDEEAB6ULL, 0xC19E3537EAFA831FULL, 0x1168FB76EE4E6A70ULL, 
            0x0642EA4EBB432746ULL, 0xAF0B4CE197F0C007ULL, 0x2413E37A24F50FA5ULL, 0x007597B0CF72552FULL, 
            0xA4FD6B3BF500FE93ULL, 0xFCD6B105844317B4ULL, 0x993C64A8B42C2985ULL, 0xBEC977E8E6F52471ULL, 
            0xC208EFBEFAFE364EULL, 0xED08489AD76166E9ULL, 0x63290A392FECC368ULL, 0x23F9A58E0B8DB7B9ULL, 
            0xB8E43E6E2E4045DCULL, 0x7BE7394437FAE02BULL, 0x0391879F8B337ED3ULL, 0x7E4A6AED253AE778ULL
        },
        {
            0xFE26D0364F3945E9ULL, 0x2704720D4FAA89C5ULL, 0xBCA9036A4F58CB80ULL, 0x5CDA8645F9F983F6ULL, 
            0xD84CB70BDE14F21EULL, 0x91FE75BF61023CD9ULL, 0x5EDD99066E5AE60BULL, 0xB31C8B5406D9805BULL, 
            0x7860DBE62C5EEBFFULL, 0x2EC3BB46E5D33774ULL, 0xD8BA1A1CCE3FF04BULL, 0xEBA5FE1720AC545FULL, 
            0x723E400D70CAF0DCULL, 0x2574FBBC8C53F3B6ULL, 0x71C1A6B432D61D3FULL, 0x903D313069A60C01ULL, 
            0x4943ED1000E1DF96ULL, 0xC87E316CFF9423F0ULL, 0xF5CFBEE8725E2EE6ULL, 0xEB11B39F315D357FULL, 
            0xB00EFC5AE96AC0BDULL, 0xEFA3DEF474591662ULL, 0x7A31CDCF97DB4038ULL, 0xDFC8C028C4AF4BCAULL, 
            0x9270ED778D43FFD9ULL, 0x00CBDECCEAF070B5ULL, 0xE45854EC83E2DFFFULL, 0x3B6EF2C164F5F1F9ULL, 
            0x4BF6EB462C713518ULL, 0xED15C0CCCD4DA32EULL, 0xF050C44456F9E4CAULL, 0x2D3670E6A97647BFULL
        }
    },
    {
        {
            0x74D3546D8B4CF9DDULL, 0xABE994C25FA44501ULL, 0xA540446D93B3E537ULL, 0x2EBF075B38468421ULL, 
            0x0EA1DF0E416D55A9ULL, 0xB6F2791515C48FB0ULL, 0x349E64E5800537C1ULL, 0xBDA7BA6CADF5A3A4ULL, 
            0x30BDCEDB2C2BF2F1ULL, 0x0E358D90C2AAC208ULL, 0xFD6DA1F7CA5B9158ULL, 0x0637EA553F87B738ULL, 
            0x0E7876403541BC18ULL, 0xCB7915606815261CULL, 0x5D742104A3DE982BULL, 0x19293AC9A7A8131FULL, 
            0x5CF9348F37BBE430ULL, 0x136CB8EA3D62724CULL, 0x3AEB95F0DDA767BCULL, 0xE0FD9FCBC2C2C842ULL, 
            0x01AEDB1AABA8E14DULL, 0xE53C52BCB5276E02ULL, 0xB21E904E0281DBC6ULL, 0xB0EF84289EF2CF81ULL, 
            0x54F7C4CB1793840DULL, 0x055BD43337457EEBULL, 0xA5E40888B6243FA0ULL, 0x2041084CE455D82CULL, 
            0xCB38E1F596A74C48ULL, 0xCACB976D3ACDC6B8ULL, 0x14A53FE0869D3986ULL, 0xBEC81052C3E4401EULL
        },
        {
            0x9DF2ED98C10644D0ULL, 0x22DD3952B5744FCCULL, 0xC96C0B457B942A59ULL, 0x3622C6D3D4E4E448ULL, 
            0x5B796C74D8E75410ULL, 0xFD376913982C7A33ULL, 0x94E33351A2744007ULL, 0xC4423A7B07D6CF6EULL, 
            0x2F8375BD5D0E213AULL, 0xD6E1612A78B4BA9CULL, 0x590533BB7BE6F336ULL, 0x79DE838A631ADAADULL, 
            0xBB9B410D0F8145F9ULL, 0x87B10E4CF519E5E9ULL, 0x3AA397989EB9B6B3ULL, 0x243B22ABECA0EB1BULL, 
            0xE00D6C8D52C15664ULL, 0x2A9AB1F27415DD69ULL, 0x27F700DD1DB54297ULL, 0xC981CB40A83C1458ULL, 
            0x581D7180452B0E01ULL, 0x1B9CA0310E6DAF14ULL, 0x0217CF7110030ADAULL, 0xEBC434C91E8A50E6ULL, 
            0xAFE17C2BE93B3DC4ULL, 0x8F35F2D67FFC6C5EULL, 0xF7A88D067A248E99ULL, 0xAF57990C62401C70ULL, 
            0xC135FDD3FC539315ULL, 0xEAC33E4B2041E1F8ULL, 0xF624D210F1060ADEULL, 0x5703FCF2B5FC75E9ULL
        },
        {
            0xE086BC8A9ABB3E1AULL, 0xB0C1EA3171872B90ULL, 0x4A29A5D5AB5854E5ULL, 0xFB0DE951CCF80446ULL, 
            0x85FBE5F0A7640240ULL, 0xF64C4B3443BD7A6DULL, 0xFF678970C6259AA7ULL, 0x08BBDBE3BD313918ULL, 
            0xED6D2FAE67EF53B6ULL, 0x5350AE931ED6D281ULL, 0x07DEC4C9085E14A4ULL, 0x2785DD9BFFCE0D85ULL, 
            0xE67D6C6D9AFF43E4ULL, 0x50955BAB17163FFDULL, 0x63B9DBB05E9C1A49ULL, 0x105E9BA41B66518EULL, 
            0x6530393E02934935ULL, 0x4E45BA8D9BA3E017ULL, 0xD94AC846E878B4D5ULL, 0x3379F84E4499CC8AULL, 
            0xF97A01CE67761962ULL, 0x377DFD1E01176E83ULL, 0xD25A17424BB95552ULL, 0x0FCBD713FAC57740ULL, 
            0x94F2CA5254C9F5FAULL, 0x455A5E4BE533290AULL, 0x58927F5FC034D4ABULL, 0x4EB3767A3398F2FFULL, 
            0x4B9A0C6F65450855ULL, 0x324A7D312E222083ULL, 0x42283C35EDE145E7ULL, 0x0E4B24FD65BC883AULL
        },
        {
            0xE7CD6FB0800CE37BULL, 0xF84EF9F6FC2606B5ULL, 0x27D0AAE7DC7A860CULL, 0x3412EFC5CD201415ULL, 
            0x292584900B0AA7DCULL, 0xF26DC1BF1095AB9DULL, 0x50A44FF8D111729BULL, 0xF8037B77FBEE2693ULL, 
            0xB83C3281890B11C5ULL, 0x63C17BD6E52E63AFULL, 0xE623BEF5D80ACA9EULL, 0xDCA13AC377D7F811ULL, 
            0x2539979CE0528E5EULL, 0xBA75D9AB87F80549ULL, 0xAA843B770C6AC607ULL, 0x699FE2518FFC764EULL, 
            0xCAA283223CD191A9ULL, 0xED8386DA56B6433CULL, 0xA2D5C530D43ED625ULL, 0x0471AD1735559CC7ULL, 
            0x154BC3CED63A9E84ULL, 0x42BDB064006F3372ULL, 0x2F2D09BE96D1AC93ULL, 0xC87A1ABAFC8F512CULL, 
            0x76F82A7A793BC30BULL, 0x5163196556572803ULL, 0xA9C01AAF7C0FEFEFULL, 0x10E2043C20070B55ULL, 
            0x66DF1CEF3A11D7F4ULL, 0xA4BBB00BD1BE660FULL, 0x4659A8595D0DD9E3ULL, 0xA484B8159803091FULL
        },
        {
            0x879E1F9F139EB8D2ULL, 0xD695ACD9F79C9D7EULL, 0x13344041F9067AC7ULL, 0x3819914D2B036840ULL, 
            0x51C117A7B8992ACEULL, 0xFB7F92F024973F72ULL, 0xA7C91F5556175287ULL, 0x330F5879E295CD7DULL, 
            0xBC63D07C403F5E82ULL, 0x0B0628D2B895C8FBULL, 0xF4C3CA389EE78A7EULL, 0x46E5F3BB39FE6CBCULL, 
            0x3DD9CFB30C1919CFULL, 0xA0EBED4AB1CE10FFULL, 0x32C516C256076E97ULL, 0x244FABC1B80C7111ULL, 
            0x4D37AA5180F9863EULL, 0x7F62C7BF80409F45ULL, 0xBE5FBB5532C96D5AULL, 0x133D60E80F5C33B4ULL, 
            0xA0A8B19E24D66A42ULL, 0xEA549440369B8E24ULL, 0x351661260F3E274DULL, 0xD98B9A3870D4EFD6ULL, 
            0x51EEA8A616133FAEULL, 0xD07FF202DD1088FDULL, 0x09C443E66216C5C0ULL, 0x23944D4E5DF37E37ULL, 
            0xE4AE7CAC4B15E335ULL, 0x37C895D951ECB79FULL, 0x7793F6702569BB2BULL, 0xE029518CBD1DA3BDULL
        },
        {
            0x88DE4F72813C5795ULL, 0xD076E2D87E3805F7ULL, 0x19113A96395C9D47ULL, 0x9CC6C6982D153A66ULL, 
            0x14D7567FCE79F1F8ULL, 0x519C23B5077C152BULL, 0xCA5209271DF3CBB0ULL, 0x3FFE6937A35178A4ULL, 
            0xA9166734711078A5ULL, 0x53A2C17D75B3C301ULL, 0x255C7F01C026EFD8ULL, 0x61F61E71AA8E2CAAULL, 
            0x59583E2CA405DC5BULL, 0xC4E6D27BBA879981ULL, 0xEFFBF00344E753DCULL, 0x5BD6655B886425C6ULL, 
            0xCDFB9EF529DC7634ULL, 0x13117AA70200D472ULL, 0x61B0B0CCBA01173FULL, 0x956EC518AF09D108ULL, 
            0x8B49D03AEDB3DB58ULL, 0x3F43A0375BEAE5BDULL, 0x3878021AF94ABC2DULL, 0x990239FFA3C97585ULL, 
            0x6A8F985156F40936ULL, 0x5BE4145D254CF92AULL, 0x64097DF38663115AULL, 0xC2CF03BC24AC8189ULL, 
            0xE6B7A1F7C01C5A0BULL, 0x54B823FD84A2F492ULL, 0xED118F7A090E567BULL, 0x5842EEA0543A784EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Miram::kPhaseBConstants = {
    0xA98BD045D3980FBEULL,
    0xF0D2C6BA4BEF863DULL,
    0x7EC3CCD746A198D6ULL,
    0xA98BD045D3980FBEULL,
    0xF0D2C6BA4BEF863DULL,
    0x7EC3CCD746A198D6ULL,
    0x294A834B3B64C148ULL,
    0x5ED3D973B38C9E7BULL,
    0x14,
    0x1D,
    0x57,
    0xEB,
    0xDD,
    0x58,
    0x64,
    0x71
};

const TwistDomainSaltSet TwistExpander_Miram::kPhaseCSalts = {
    {
        {
            0xE6AF739F25EADD42ULL, 0x6C97DC791E8DBD5FULL, 0x8D92FAB5DF55D534ULL, 0xEAE6A9988B217FB5ULL, 
            0x30DAF34773304F77ULL, 0x4BCBEB1383E65DB3ULL, 0x82F497DC1C15596AULL, 0x524A1CFE52796043ULL, 
            0x0B8A14D6EF487AB6ULL, 0xA2085DBFC7A05D41ULL, 0xB1DA38CFEFD5753FULL, 0x1C21F08E634AB93DULL, 
            0xF806648223E4A69AULL, 0xACFB43C33D5B09CFULL, 0x34FB548C009FA48EULL, 0x8EAACF46ED181690ULL, 
            0xF7EC3B200FC8DEABULL, 0x08463140D3D53D2CULL, 0x008F0E6CD201FE00ULL, 0x00B09706EA52DB32ULL, 
            0x811FBFE1F2CB0166ULL, 0x5052B68C9AB03D89ULL, 0x8648147858545CB5ULL, 0x1F8393B650341F59ULL, 
            0x43F59C24E106859CULL, 0x9556DB230FD80094ULL, 0x58BAD5C4ADF0CDA1ULL, 0xBC0B5F115A37477FULL, 
            0x34D0A58F59148897ULL, 0x06DB2D1F77B78E6DULL, 0xFF72814529DA693DULL, 0xAB77EDD0EFC9DEC9ULL
        },
        {
            0x1B742506FEEA4808ULL, 0x53EAB1E1E2CCD526ULL, 0x70C5FD56E30D4300ULL, 0x7E96D6D7CDB9DBFDULL, 
            0xBB6665A251B4BA37ULL, 0x0B0BA8BE4FA76057ULL, 0x5248397E2E9CBDFEULL, 0x06699B007A65802CULL, 
            0x18F44AF5E23ED62BULL, 0x961D00594A0406F4ULL, 0x06DE54F9430C525BULL, 0x4671FF15E6BD669AULL, 
            0x7F3080CF8F5F39E8ULL, 0x15F1C7EB771E1B41ULL, 0x57B4F619D38D4417ULL, 0x1CB9D2D275DC2EA3ULL, 
            0x88D887CFF3C36659ULL, 0x56FEA77BD1F460B7ULL, 0xB052C4937E8F9A0DULL, 0xD4C85F00F244BD1CULL, 
            0x13449282658DB5CCULL, 0x479B546B79E3C391ULL, 0xF946697F54546AB4ULL, 0x0C3514533FC8CA42ULL, 
            0x140A03BE4E224F5FULL, 0xAE325005B32952FFULL, 0x63042D10654EF7A3ULL, 0x7CDAAE624D9BB8F3ULL, 
            0x9519D15732B8C5CAULL, 0x4DD4D4B3C8487CB7ULL, 0xE8EC6D89EC4E06D4ULL, 0xDA39F78128347527ULL
        },
        {
            0xEFFA609013DE00C3ULL, 0x09A071B4C0150774ULL, 0x78BD4F8D68D279C2ULL, 0xE8AA3884BA9FEEDEULL, 
            0x34261994855DC2C0ULL, 0xC40A7657A5785310ULL, 0x845209368415208FULL, 0x3B44165260F9EAFEULL, 
            0x883DD15F8C489AE1ULL, 0x90CF2FDF7624EF72ULL, 0x0ED2A572A7A44253ULL, 0xAAED7111E75445CFULL, 
            0xD7C74A64FEA019F9ULL, 0x1D1D44892C078E7EULL, 0xA7D2D691490A8008ULL, 0xF6E4CBFC8789E9CFULL, 
            0x3F00C5D24577F56CULL, 0x79F90F13333CDA2EULL, 0x829DAA7B1381771AULL, 0xB7F54A3797B7F30DULL, 
            0xDB43FB8CDB1E7AB6ULL, 0x6AC4610630A36AE0ULL, 0x93ADBA016A3AA5C9ULL, 0x74E354781F6C903AULL, 
            0x7A12D9D8F5774AF6ULL, 0xA1C7C270D286A3F3ULL, 0x4076CC9C0B88B0C3ULL, 0x2F2AD5EA7A3507A6ULL, 
            0xF192583B208E0A5AULL, 0x803EA01BFF09A6C6ULL, 0x25764CBC2FC970B3ULL, 0xBCA4EB048C410483ULL
        },
        {
            0xC5BDF4305D27F998ULL, 0xDE80996952397D69ULL, 0xFDD4387B823DA052ULL, 0x5B5A3173CE3AD763ULL, 
            0xD448E5269D0B0CDFULL, 0x40783D847D3CE061ULL, 0x082201942E6AA758ULL, 0xC63593A3A2C09B93ULL, 
            0x513C27C1DA4690CCULL, 0xF840E8D995260CA3ULL, 0x22F69151B3585060ULL, 0x43AFBA0CA2C881D5ULL, 
            0xBCA6A547358A20E5ULL, 0x7E4093D4D9ADDA7FULL, 0x4CC91BBCC67F2914ULL, 0x7F7D85BA73C60039ULL, 
            0x3DC8D6A39A68E87EULL, 0xBDA5A00E09107B97ULL, 0x031DD8ACBF53E800ULL, 0x3754D3AC2EEF2863ULL, 
            0xD1ADCB245A7BF828ULL, 0x1ECD809BFDF17308ULL, 0xE9F1E26E46C99D06ULL, 0x461D3179E469C63EULL, 
            0x35AC17336D6AA02CULL, 0xFF05192C872DF9AEULL, 0xED82582683800CDDULL, 0x8EC6985450C28DAEULL, 
            0x37285B88F4E3C853ULL, 0x6C0B08E5A51963CCULL, 0x18E06A7D0A93EFBCULL, 0x9B0A53A91DC67576ULL
        },
        {
            0x1D91B09C3B4A4989ULL, 0x59B8843CA0F86D5EULL, 0xC91DBF5C84EBEAA1ULL, 0xDB51E28433E50CF0ULL, 
            0xAE50B232632D88DAULL, 0xB9576807B44F8EE6ULL, 0x0DFE7723DA8908C0ULL, 0xDE9CB130BD105E45ULL, 
            0xFA3C6FB21E6F452BULL, 0x122BC46314E82E17ULL, 0x76D87816FE812E27ULL, 0xEF432A27262D5366ULL, 
            0x04D7F4E9BD07CDDAULL, 0xF4B39EA7BCE225D1ULL, 0x11EC7D3B883E7308ULL, 0x0C3E62D290F5D95FULL, 
            0x5AB15E3379224A31ULL, 0x344EFD56B7A4458FULL, 0x3054E6AAFCF5A778ULL, 0x28030704DEFF3D22ULL, 
            0xBEDC4C4CF0FE3047ULL, 0xEFAF19A8FD06A8ECULL, 0x00C5A6453D87E918ULL, 0x2271BC8F81A10431ULL, 
            0xD710440B5DEC86F9ULL, 0x585850FAB71DBC97ULL, 0xD6EBE9E3533E33E6ULL, 0x1CB18222D00D3E58ULL, 
            0x6A6C0D3AFA5C0047ULL, 0xEE08047BA9B11429ULL, 0xA327B6EDDBE742CAULL, 0xE41E273F155A0F1FULL
        },
        {
            0xE9D41C17B0B98D37ULL, 0xD6BB8CA9617E7205ULL, 0x804B4E6FB627696DULL, 0x9CD67DE254775BEBULL, 
            0xF18A3977BA38468BULL, 0x7F6422390E5C6F4CULL, 0xA6022FDEBE20BE08ULL, 0xF319034C79A97C91ULL, 
            0x3DD920C45A7B085EULL, 0x52B3FD5BE2FCD859ULL, 0x06F389E51A8CE5D6ULL, 0x966E4AE8CCCD7D8EULL, 
            0x482FEBE9C46732FAULL, 0x254B0E3D18D65176ULL, 0xA553415ADA11CB06ULL, 0x2F7C56EF21EBAD9BULL, 
            0xC74B2BFBE671D887ULL, 0x7B8CFDD107E4B6BCULL, 0xFAAACE018BDA9A9BULL, 0x0EFB6B49B10F4DD0ULL, 
            0x809271C6D2F7F210ULL, 0x1A982D3422DF8152ULL, 0xED6293D72BEFFCFEULL, 0x2D6948C472FA2EA9ULL, 
            0xF2A97A789E79061FULL, 0x38CE9277AE6B87FAULL, 0x45327DF9801B662DULL, 0xAFADD493EC48EDFBULL, 
            0x0E08C0C4188EB39FULL, 0xAF4548A081A53D54ULL, 0xAAD2ED2C76CAA498ULL, 0x5513B127386CEB93ULL
        }
    },
    {
        {
            0x2569E1C9325870BBULL, 0x61FA7D09D85DA793ULL, 0x0EAD25B13D808FA1ULL, 0x9A5E33F8CB0C51B5ULL, 
            0x1D81E1EEC40552E4ULL, 0xB508C5928C2AAEBBULL, 0x2BB7EEDBC392756AULL, 0xE9EC10C979680639ULL, 
            0x20428736E264F116ULL, 0xAA43487A937DE0F5ULL, 0x9BF1129C92B20397ULL, 0x04B248AACF785317ULL, 
            0x3291AFFB862C58AEULL, 0xA47F67807EEEEAD4ULL, 0x02297656F03D8D09ULL, 0xFA6F160519662AABULL, 
            0xA29A387A56C31610ULL, 0x48D7704B05E42C69ULL, 0xFC18494A35464E19ULL, 0x8AA54647BFB9FD57ULL, 
            0xAE17C97CE208C0FAULL, 0x86535130EBE36255ULL, 0x03CBF2DC546DDB4DULL, 0xE811C9DA9CDDBF4CULL, 
            0x7914F219374DF1D3ULL, 0xE1C281A00AFA7070ULL, 0x354CFF90B1B4CAD5ULL, 0xB3F4B4754ADD5C48ULL, 
            0x75D784D0C2D5AB5CULL, 0x2B5E2DA58999076CULL, 0xFD9A46A0C7F17370ULL, 0x42243FE9CC9988C0ULL
        },
        {
            0x62C0726F6F5DCEBBULL, 0xBCA9A7E890696D51ULL, 0x8F83C530B8199D3EULL, 0xD1AE756DE09745EFULL, 
            0x4FF271F83131F28EULL, 0xB04713F5F85A77B3ULL, 0xCB4C7201C2527AADULL, 0x2262645ACA8AFAE4ULL, 
            0x7E4B56E073C54282ULL, 0x02557BEE7F0E1191ULL, 0x5D55264C96E3BC7DULL, 0x1771FC5B70F4EE1AULL, 
            0xFC1E0D57202D231DULL, 0x0B59386711F764D8ULL, 0xB7A9C49532315CF9ULL, 0x7159E84AB5C65EB4ULL, 
            0x15B91BEA1DC54952ULL, 0xF633D9669472CD77ULL, 0x0F8F798FFC275507ULL, 0x8FF7B8DE0423B797ULL, 
            0x8B1664D64039C8C5ULL, 0x29293E992D83AEB9ULL, 0x5F17A1BBFC2A6227ULL, 0xA74C578883357269ULL, 
            0x978FF69EC511989DULL, 0x2056B85DD639B0C2ULL, 0xB533916272A8880AULL, 0xCE13616F08295F5DULL, 
            0x87478C73B7222DB4ULL, 0xC84F53D3CEE3B1BDULL, 0x11A66065CA0E9B35ULL, 0x1F399D4FBA7045DAULL
        },
        {
            0x80B45C03F4FFD0E7ULL, 0x1C37E89360A1E279ULL, 0x2A3FFE9886588BD6ULL, 0x30AFE16698A9DA39ULL, 
            0xD85482D67F4DEB72ULL, 0xEADD9CFD4017918EULL, 0x2A0A50140B8385B9ULL, 0xA6C85EE8B4B44BEBULL, 
            0x5C590C1A04780B13ULL, 0xF78A86C005795F80ULL, 0x068A155259D34788ULL, 0x0848FB5C58666035ULL, 
            0xC6C4D1FF8AA09F8CULL, 0x2CDABA2ECAB8A402ULL, 0x7CF5C15140F20694ULL, 0x960E1C7077D3469BULL, 
            0x90A9D9714F8C51A7ULL, 0x138B9A4C65B85252ULL, 0xB34C08648B6F75D2ULL, 0xB05AA7BAC2904571ULL, 
            0xB1690BDF70E3F243ULL, 0x5995F601643D1DF3ULL, 0x0D36B84B31C1018FULL, 0xFB3E45EACA633CFDULL, 
            0x649BD13221B7A822ULL, 0xFE4C74E3559283AFULL, 0x2EC05D7E81105F19ULL, 0x941D81840ADBAE88ULL, 
            0x1BFA2D42CA624CBAULL, 0x78F8B56F4B411FDBULL, 0xFEDC6CFBD5760045ULL, 0x3034C82BAF081290ULL
        },
        {
            0x6CF76F9F9DAB2B72ULL, 0x7E10D50118DD6FFCULL, 0xAC3AFDFFA2F59A17ULL, 0xE6C54385EBA7572CULL, 
            0x29BB39F15E001EB1ULL, 0xE8B43133E8A4E1D1ULL, 0xA12B12BA9650AFD7ULL, 0x4D7403105724FCD2ULL, 
            0xB1123C5B35F48B10ULL, 0x6CE32A380C1FFA8BULL, 0x52EE5B6B3D924DCCULL, 0x3756331E41040486ULL, 
            0x8ACBAF91A4FE60F3ULL, 0x1392257682C583CEULL, 0x46224D77176E0A2CULL, 0xA57013B0625CD5E8ULL, 
            0xA8496C5BA9EB5BA0ULL, 0xB96E08B6D7CE950FULL, 0xCE740E340C913759ULL, 0xCE49EE5E256C13D8ULL, 
            0x81807948FD4013ACULL, 0xCE5EF75217D5FBE6ULL, 0x1BF70E457CCFC337ULL, 0x9A950466658A7D60ULL, 
            0xD265EBEBAA756D3BULL, 0xCC263C6F047EB3BEULL, 0x06B4795858223040ULL, 0x60D63D2CAE6D7E49ULL, 
            0xA957A25418E027E1ULL, 0xF55F6A886B854F72ULL, 0x582F100D4E8EFEA5ULL, 0x9F8A0C688563E42AULL
        },
        {
            0x6315411A060DE3CAULL, 0xBCC40E648BF2BFA2ULL, 0x7484BE9BFB9DF231ULL, 0x7ABCBCDEFE132831ULL, 
            0xADDD35C974216A11ULL, 0xE45D54AF5ECD5812ULL, 0xF8445B730FAED159ULL, 0x26C8794AC53A4C49ULL, 
            0x5BE18955A40CCE4EULL, 0xC79FC2943344B9E5ULL, 0xDC3815D2FAFFEB19ULL, 0x60AD7AC2442EBDD9ULL, 
            0x66FF64BC0841C065ULL, 0x8A5D5A67D945B670ULL, 0x3F446EB9E78718CCULL, 0xB55480CAA44C1B86ULL, 
            0x6229BD15079BCD2CULL, 0xB8BB97C0FCB993F6ULL, 0xA44AD0C459D3629FULL, 0x1C3445B1315BA2CBULL, 
            0xFE8FB26F7C66B200ULL, 0x1F859372887B5467ULL, 0xA5DB86814CAFB628ULL, 0x7DD246F1B9D36B52ULL, 
            0x574B876AEE27FD2CULL, 0xE80C797ACA68DD61ULL, 0x6C6F6DC918E9A501ULL, 0xC044666FA6D05193ULL, 
            0xFE3D302A153C6162ULL, 0xB87C48F8CA7C43BFULL, 0x2CD3331453B2C903ULL, 0xB2777501530B144DULL
        },
        {
            0x8B79C1517894AA01ULL, 0x6A798B89A5660ACAULL, 0x10474611AD9BA406ULL, 0xC0E359700710DD12ULL, 
            0xBB6C0759C2EF5F76ULL, 0x221C4FC0459F826DULL, 0x4C598CBFDA068028ULL, 0xBEB719EAFBD1A752ULL, 
            0xA0C3DA37C19AC391ULL, 0xDC9A13FF8EF6CD7CULL, 0x17D22ACAE45A9AC8ULL, 0x5B889296B416CBACULL, 
            0x9D10DB50B1B70DB8ULL, 0x9997828428A9E3F2ULL, 0xB7813B9758E29C54ULL, 0x6A8FED003B28A7E7ULL, 
            0x1FFECB6E1DC8DE72ULL, 0x68DA544E685C7114ULL, 0x7F912A9ECEEF9F96ULL, 0xAB91B78C9D5F70DCULL, 
            0x7381A832223DE784ULL, 0x3284CB6B75250EC4ULL, 0x9B02BFA362D4A85CULL, 0x8B4CC7ECD43FC7A1ULL, 
            0xE15DC29F807AF6E6ULL, 0xD7E074DE4B096984ULL, 0x09E6046F05ACB896ULL, 0x7DD4514AF827D6A4ULL, 
            0x9864F81CE7520733ULL, 0xAC303CC2F8BEC359ULL, 0xD0B980315B004274ULL, 0x50FE8C1001F7D9E9ULL
        }
    },
    {
        {
            0xA7690E06A2000514ULL, 0x19E9D3A30B49E901ULL, 0xFBC86A21071A131EULL, 0xD632C3BE7FB06FCAULL, 
            0xA2B942DE24815F88ULL, 0xA37BE41DD43B878AULL, 0xD5FC73613A51E2E7ULL, 0x7898F337BF423306ULL, 
            0x277EA871F2D9DF4EULL, 0x4DECDC57FC4A2E5BULL, 0x8BA43A9F2EA4428FULL, 0x46EB1FE961377ADEULL, 
            0x0306E749A30BE46BULL, 0x7DE41B81E08F9BD4ULL, 0xA95350FC527FF340ULL, 0x5E0B96D76BDB581CULL, 
            0x038E98105E4175CCULL, 0xCC224C1C22EF85A2ULL, 0x321D715A9A014BDFULL, 0x03E8957256FCE244ULL, 
            0x8D52026FE15A5B39ULL, 0x78B9DC3704C578B9ULL, 0x56E5547D65127BEBULL, 0x4E2F277D8733A20CULL, 
            0x6DAD6139B4EDA83EULL, 0x241724931EFE2D7DULL, 0x1DE05749B31E00E1ULL, 0xFAC439CFC53EC218ULL, 
            0xCDF8043FAEC8F669ULL, 0x7417A8F2492797CDULL, 0x80510925805889D6ULL, 0x3FB12235BCE50D04ULL
        },
        {
            0xDA7601BDEAEAFBEAULL, 0x2E16683A97E513FBULL, 0xDCBDBAEC97859277ULL, 0x358F0DAEDF2922C9ULL, 
            0x0E68C8FFBA6CAE8DULL, 0xFD87D57DB78B4C13ULL, 0xA35BCD66EA330514ULL, 0xFDE49D1F6C0AACBBULL, 
            0x155D6288012BFA16ULL, 0x26F7C27127690D29ULL, 0x16C660E47A991162ULL, 0x134B263B58FE43D2ULL, 
            0x38B73D01731B0954ULL, 0xB8CC1DD2CDC4F49CULL, 0x5A945347F6F62D6CULL, 0x38A3443C74217994ULL, 
            0xBD80338560FA6DBEULL, 0x0427AD32E56F2253ULL, 0x8ADBFB388E3F6803ULL, 0xC22AE7346FB0E0F3ULL, 
            0x8F0DF7BEA2168B82ULL, 0xBA559AA066D4A098ULL, 0xD997326F9AE6F86CULL, 0x77C0C78084CFE8EAULL, 
            0xB97C8CAB80C2E037ULL, 0xED36C848A6CB2E1AULL, 0xC941B1112182F683ULL, 0xC8C474AE9B36EF95ULL, 
            0x97212DFF89881A47ULL, 0xD018987F471588DFULL, 0x8CD0F7FC03236991ULL, 0x779EEE98DB730C89ULL
        },
        {
            0xF5236DCBB0762844ULL, 0x02E5DE168002605DULL, 0x52CC43CCA188AF78ULL, 0x870309BBF40C6528ULL, 
            0x69886661D6BDA8B9ULL, 0x0CA0D0972334CCA1ULL, 0x143FBCAD48C1FCB0ULL, 0x83C796CE2A11D55FULL, 
            0xDF802DAEAF692FB9ULL, 0x4EF44861D3958C1AULL, 0x432730AD9FD6AFF5ULL, 0x0D8B72B701B566C4ULL, 
            0xCFECD6DCBF867E68ULL, 0xC9421325324ACAA3ULL, 0x63703D53CE183063ULL, 0x17BC3D02D6D722E4ULL, 
            0xA5A2E9FA86112A22ULL, 0xA2E224D9B0A5DD79ULL, 0x61C055FBC9C73083ULL, 0xEB3914ACF60B934CULL, 
            0x6E0E54D16FA818BEULL, 0x15652AD99D39C931ULL, 0x8BC6FD6F70C2E05FULL, 0x475AB1D2035CE5B1ULL, 
            0x306E9CB21554C713ULL, 0xD2FE139B9D77991EULL, 0xC2B70F87D619939EULL, 0x2C76017A3590656AULL, 
            0x1082867300DE6D55ULL, 0x79E9E0331ADB17FEULL, 0x68CC944D14083EDEULL, 0xDC38CBC105F86DFDULL
        },
        {
            0x3DE6E54446AB3CFEULL, 0x47CB9DE12D094809ULL, 0x3D9F91D3B2FCC3B6ULL, 0xFD5DFD2B08DA1E58ULL, 
            0x076FE8A954623F34ULL, 0x554D92896EAF9E27ULL, 0x149419EB9D72D10DULL, 0x63D66E1733C9F3ACULL, 
            0x39E80BCA93CDCDC1ULL, 0xA62FABAF5A7DA51DULL, 0x4F895A6C667775F6ULL, 0x299F1BFE77FDB939ULL, 
            0x3DB611AD06383701ULL, 0x3CC587E4BFD1EA3AULL, 0x310951FA251A5975ULL, 0x4FACF791DFBA2E76ULL, 
            0x53D0CAAF3260280BULL, 0x8185FF0BAA097A50ULL, 0x39A642D6A3CD980AULL, 0xC93736A52B573AF0ULL, 
            0xD4DC315130939DDEULL, 0x608D44B6DC213072ULL, 0xA4469A0943081404ULL, 0x7114E0AB6178022EULL, 
            0x16FDE0410A1C7B26ULL, 0x8E802E1FE7D330E0ULL, 0xFB180263CD6FC295ULL, 0xBF4A360B45131D57ULL, 
            0x679045503C0FBC81ULL, 0x11C8D051571B5F5BULL, 0x4B432493FFB1B18CULL, 0x4F532A8B813E28DEULL
        },
        {
            0x248997051B938CBAULL, 0x6E7A5EF807BEF635ULL, 0xE5696900FC03D398ULL, 0x8D75DA141CD23A1CULL, 
            0x8E703AB427F526C9ULL, 0x2CF04616B7F64680ULL, 0x55459282F447F194ULL, 0xF1489638E709DA9EULL, 
            0x679492271C712285ULL, 0x7028A841EE4FA8B8ULL, 0xE15F269EC952B2B4ULL, 0x94C77A92F2AFDB40ULL, 
            0x764FA2B2827640EBULL, 0x100AE6F9B39301FBULL, 0x39B1AD8A8ED078D0ULL, 0x33575CAA1F51CE0DULL, 
            0xE1FABF606F82AFFEULL, 0x486CAB4B581451E5ULL, 0xA0CEA20F3EEB828FULL, 0xE14EF21775EAF85EULL, 
            0x40944B55FEE09BB0ULL, 0x2296728EE82E5E72ULL, 0xACCFEC435C34C344ULL, 0xDB4E5BF659321F38ULL, 
            0x0DD39E9D77E97635ULL, 0xBCB342B350D1DE46ULL, 0x03D01090555BBEFBULL, 0xCEF8A731491113C0ULL, 
            0xD33A3700D35FE2CDULL, 0x5CDFCBE8804AD096ULL, 0x888C8191877D679BULL, 0x38911E99CAE52750ULL
        },
        {
            0x9C8358F7EF4AE25EULL, 0x41D53637ADDE7516ULL, 0x277CFF887A2E209EULL, 0x14AB561B8E24564EULL, 
            0x906D5A21359B6133ULL, 0xD149E14AA04D0FFBULL, 0xA39B6CA69FF70D5AULL, 0xAFD4586D81B99064ULL, 
            0xFE19E25FD049C9C4ULL, 0x35655526D3346CECULL, 0x5DC4726422B81DAAULL, 0x4C9A997004CC666CULL, 
            0x58175FF75B33181CULL, 0xABAB4A137C5291C3ULL, 0x0036633A05A1DFCCULL, 0x3D4E5CD4E391F30BULL, 
            0x401D40403A143C02ULL, 0x34253766803AB6C9ULL, 0xB4752DD9F9C098A7ULL, 0x84E367DE380B39D6ULL, 
            0x960A60B649932CA1ULL, 0x922AAD254B43A40FULL, 0xC68FAED660138F74ULL, 0x108557ACA0DB1693ULL, 
            0xC4D5B6737100456BULL, 0x529436B6002BAD02ULL, 0xE0697BB5476EAB22ULL, 0x0F50C2342736D532ULL, 
            0x73574F01C1120C30ULL, 0x74CECBEE0CFFB085ULL, 0x95E282A7AE002D2CULL, 0xF7076527135276ECULL
        }
    }
};

const TwistDomainConstants TwistExpander_Miram::kPhaseCConstants = {
    0xF0961DFE69C71974ULL,
    0xF32AC4555DD13E53ULL,
    0x81E25C82EBC89254ULL,
    0xF0961DFE69C71974ULL,
    0xF32AC4555DD13E53ULL,
    0x81E25C82EBC89254ULL,
    0x55F29E50DE95B4F7ULL,
    0x176A1C3F9EDACAF0ULL,
    0xB0,
    0x4B,
    0x24,
    0x4C,
    0x46,
    0xED,
    0xAC,
    0x48
};

const TwistDomainSaltSet TwistExpander_Miram::kPhaseDSalts = {
    {
        {
            0x185EF1CB9DB8D995ULL, 0xA7C264F47D85FC18ULL, 0x0C91AB9246C39014ULL, 0x688346ACE71869C3ULL, 
            0x6C279F15314F7457ULL, 0x5256914E77F3440CULL, 0x096966B914088D46ULL, 0xB94EA111490824A4ULL, 
            0xAA4B10DDB78634CBULL, 0x2570C982B0EBA829ULL, 0xED88E727BD462B40ULL, 0x98FF61E65AA75A7BULL, 
            0xDF6FCD48F61F5765ULL, 0x98E6380705AACFAFULL, 0x123ECEA3832B918BULL, 0xB3060D957689B956ULL, 
            0xC49A3E7D26FD1390ULL, 0x86A0FF286822EC22ULL, 0xBC3E5B2380415E4EULL, 0xBEC43B744E7F769AULL, 
            0x2B9DB6E460E9454DULL, 0xE9E3FD05F2839271ULL, 0xD2AE4F908C291084ULL, 0x0464E79A45972BCBULL, 
            0xB566645C574613FAULL, 0x80CA918A231F0372ULL, 0x2CE2DB388BB91C54ULL, 0xA65A47751A72BD80ULL, 
            0x4BC9A7247AEF4B18ULL, 0x1A050B57FA5942F1ULL, 0x3F07DB945113F3F0ULL, 0x5EC902DD2E73A494ULL
        },
        {
            0xE043C5F7745A9C2DULL, 0x08B4D5B57054A7B0ULL, 0xB88DD8C018AF545AULL, 0x528C696034975902ULL, 
            0x79A506048554F16FULL, 0x134A585299B46A10ULL, 0x11961BB01A88E5DAULL, 0xCE9ADC61B0AA9D1DULL, 
            0x87E0AFE26B8D8767ULL, 0x99BC503B3DF5E547ULL, 0x810B47EC454B4856ULL, 0x09FF5B92655C2E20ULL, 
            0x5F9E8B3F33DDA0C2ULL, 0x4AE6DBE7DC0B81BDULL, 0xB53EF45C10750C28ULL, 0xD1259FE3649E1FE0ULL, 
            0x48A37EB3A9F42B33ULL, 0xD9626A19CCD40482ULL, 0xED00367030FC898AULL, 0x887800D23E6B22A1ULL, 
            0x820E72B7E3315914ULL, 0x9E6466DAA0226E34ULL, 0x2F17148A9DB2FCCFULL, 0x8E76A9C65EE52FFDULL, 
            0x20EA9CC80703F594ULL, 0x02E5046EAE597456ULL, 0x2594EC24A10837F3ULL, 0xE0AAAD98411C7ACBULL, 
            0xF3B176E66A6D75DBULL, 0xE7979E176E3BBB1EULL, 0x97312A61CFC3CD64ULL, 0x45EBA7805B8F4821ULL
        },
        {
            0x1B22631180B14947ULL, 0x21BC32BEA9C759C1ULL, 0xCDA6E755C79FFF7BULL, 0x2274C230B1658EACULL, 
            0x0C4D7735BC7F8993ULL, 0xB64739E07333B030ULL, 0x55B4452CB50E4DCBULL, 0x88C55B2051CB3DFAULL, 
            0x6F1D0CF0FD17148EULL, 0xC8EBFEE0E2F4A38EULL, 0x1433E7B04B04F7D4ULL, 0xA8AC3563C86F0BD9ULL, 
            0xA96F651E00A2D22EULL, 0x406ABB6F72557E74ULL, 0xF4AC693C2C5C333BULL, 0x214DE8FA7EFE6EF2ULL, 
            0x3C29824D9F9B56DEULL, 0x6E8AF8A35741B29CULL, 0x3F3E57A0CE2EAD5EULL, 0x6BAC3B29C60F81CBULL, 
            0x1FACC6EA0C04383DULL, 0x3D22EB9636F5262EULL, 0x88B3FC56834D8BEBULL, 0xA93AE6378F66C8E0ULL, 
            0x227B46460AF72758ULL, 0x3F61C576BB07745CULL, 0x245CF1235202B4A7ULL, 0x1199CE6DC5604450ULL, 
            0x406C1FF9E47BA212ULL, 0x675AE0BF96E4E964ULL, 0x84012E34614FF2B4ULL, 0x2F8E7F6CFAAD257BULL
        },
        {
            0xD295919CA54EC2A4ULL, 0x3DA4A1F3F8CE95A7ULL, 0x2DA86BBA4E5E663CULL, 0x1A3400FB358907D6ULL, 
            0x3AA67ED37E06ED89ULL, 0x9A9939402900895CULL, 0x594821F62133B2A6ULL, 0x60B54A89AD524D9CULL, 
            0x38958B7D37A2DF5CULL, 0x77DC3095A80B30B2ULL, 0xE6FA56481E3C55F2ULL, 0xA245DB861A723B2EULL, 
            0x7F14CAE4346355FCULL, 0x44A5F645EA9128D7ULL, 0xE99CAAC7CEB15A68ULL, 0x8E4E8ADB15840807ULL, 
            0x7FE996058CF8FEFEULL, 0x0DA0E8672B22E329ULL, 0x1D25621C6B52B7CEULL, 0x3CA7BA0C6A66D746ULL, 
            0x225CABD15A0AC9D8ULL, 0x0EA1CC9965DC4AA5ULL, 0x48BF33D94C7DA3EAULL, 0xBF5C68614B3A5541ULL, 
            0xD46813048A5BC14AULL, 0xD825F6C305644DDEULL, 0x5055AD953C3A64DBULL, 0x507EF2A521749FB8ULL, 
            0xB87A96CF467D18E5ULL, 0xD27812E2B283A7E6ULL, 0x22BF69518A45E1CAULL, 0x565C14810ADCF6DEULL
        },
        {
            0x79046AAAE1B6B4A4ULL, 0xA64F2F514ECF5AA0ULL, 0x0571F484699C2FFDULL, 0xBDAC2455B9ADB977ULL, 
            0x7899DA9A2E4C0230ULL, 0x7A98A23CF46C55F0ULL, 0x17744CAB65F78A61ULL, 0xBF77F0128CF4551CULL, 
            0x2CC9FC043004EB8DULL, 0x078228D7A78376B1ULL, 0x022ABC6AE1605C95ULL, 0x2E92313C22F7159AULL, 
            0x0AB5532096433D0DULL, 0xE7833FA133FBD1E0ULL, 0xA2A9AE10946F3224ULL, 0x4A573450DCD9A052ULL, 
            0x9C62B4C2F29E5754ULL, 0xA8BC7C75A54B1B54ULL, 0x43720B81CC86F94FULL, 0xA0322BB6BAFD62D4ULL, 
            0x2A2CB0094A752615ULL, 0x2375F5F6A41BB5C2ULL, 0x434759D3891BA4BCULL, 0x67ECE5DC782CEA10ULL, 
            0x16A3C75C6E542A67ULL, 0x31368582C7093599ULL, 0xCBCE83F4853D6108ULL, 0x194660F8B06C655FULL, 
            0x04ED9AAC038D1A4EULL, 0x7E8B433DE3D127F1ULL, 0x01DE38A51667A9FFULL, 0x902B6F889BAC8093ULL
        },
        {
            0xD1FC3370F62580BBULL, 0x0A59CF8199096BE9ULL, 0x7F8133FD5231126CULL, 0x9715D620BB80F7E1ULL, 
            0x59EF58BA34C9B79DULL, 0x578F298BBDA0E244ULL, 0xCD33A9641859575CULL, 0x7ADA5C0668FA4E51ULL, 
            0x34489CC525D47B49ULL, 0x4ACEC37D0F7560FDULL, 0xC0647FCCCBC6B156ULL, 0xDB5E5D19D513D3A9ULL, 
            0x41BA204DF54350A9ULL, 0xA4081B23DAFB068AULL, 0xD28082C0A0360C00ULL, 0xB70D29C1BFEA5CDFULL, 
            0x412C34D73849B14FULL, 0x0AEDB8930B0127BFULL, 0x5A8A8A2B24DE5FC8ULL, 0x2F6E905645E6CD6BULL, 
            0x625071837BBA818EULL, 0x6339066D54A97EDDULL, 0x6B4257EA442D0F5FULL, 0xB67A4E1E684C9FBBULL, 
            0xC851B8C36667CE3DULL, 0x4AF9FBE4E1D2EBF8ULL, 0x5F69455B377589B0ULL, 0x3F7760B4B36B4CE5ULL, 
            0x0D0F1ECBF5CC7494ULL, 0x53E028B99F2C4098ULL, 0x1578903041E96DF1ULL, 0xA40BD61C06640945ULL
        }
    },
    {
        {
            0xF09A6DA3A9F29F26ULL, 0xE4F6A5BA399268DAULL, 0xCD04D2EC6DF881D9ULL, 0xE5AD2FC5E10F7EB0ULL, 
            0x65C48FA352B6DB85ULL, 0x1BB317528AEAD272ULL, 0x37596AEAC8EB5619ULL, 0xAC3B5D2D11BA2555ULL, 
            0xC0F524BAE5B23297ULL, 0xD409A604F8633406ULL, 0xF8F8EB2D39939921ULL, 0xF4C1B088277987CDULL, 
            0xF4260B0FB4C36777ULL, 0xA928936CA9BDCA83ULL, 0x64E9D75951FC8479ULL, 0x1126D79B3DE64B2DULL, 
            0xD03470F8FC566BA3ULL, 0x56CE46782EF19EE2ULL, 0xAB5567F33DD5C464ULL, 0x46F9C769EBEDEAD7ULL, 
            0x02052F3B4C62EF31ULL, 0x452F502CDC538B89ULL, 0x77B64A57F145BE73ULL, 0x0FF775C603EEF60DULL, 
            0xEE77AFAEC7643C77ULL, 0xF5E76569073A4E74ULL, 0xFD55E74D042157C9ULL, 0x9B2C795539C5DAA7ULL, 
            0x47EE161FCB959D89ULL, 0x37F013D2D950DE4AULL, 0xA05A99ADD7017015ULL, 0x069E2D1CF9D1C5ABULL
        },
        {
            0x2D3ADC64D69DB839ULL, 0x3A94D32055DC881AULL, 0x89D479D8347C8B5BULL, 0x80D00FFDCDB8A563ULL, 
            0xF9F6DEBF3D7F9B53ULL, 0xF114C085B7639C2EULL, 0xEF719195C43B6BD1ULL, 0xF8844A6C46058F23ULL, 
            0x9347D25A55656BA2ULL, 0x6C8D4DC2F4268883ULL, 0x10BB25EC39ED154CULL, 0x4D96C5DD4E90FE4DULL, 
            0xC518E693F7B8A032ULL, 0xDB5E42AEF1BB7E90ULL, 0xCB995511A9772FA2ULL, 0x086CD7B215EFC095ULL, 
            0x836A6DE8E939A56BULL, 0xF936DBC468BF5324ULL, 0xC4CE043B347F9DD1ULL, 0xEC642AB7D0AF2E78ULL, 
            0x3F8A9307D8774BF3ULL, 0xA8C1A3C1BCBE3C23ULL, 0xD6167E6B9534C01FULL, 0xF3C50769E0DDA99BULL, 
            0xA411E446E4A07551ULL, 0xFFCDB7077F839436ULL, 0x9093DDFE9BBE57ECULL, 0xC7E1046F114FD257ULL, 
            0x5D9CEEACE1B44DA9ULL, 0xBFD96C81564C0972ULL, 0xF8912BC46D07BEFEULL, 0xCFEFDF13D2D3322BULL
        },
        {
            0x9AAFED7D2E6C7271ULL, 0xF83F628B200CB563ULL, 0x2C676801F03F808EULL, 0x849ED478C007A309ULL, 
            0xB8A27C4AED1A17D4ULL, 0x143120A594E9EC8CULL, 0x326AF616EF27C918ULL, 0x617BF6F5C9295D92ULL, 
            0x810C1106A7E9D4D3ULL, 0xECD1CA9D1397C300ULL, 0xC753A2512E84F9AEULL, 0x2237D179893F9A00ULL, 
            0x5E61065E7537920DULL, 0x9F7BD799CCAE50A5ULL, 0x39E078CB34EF4D0BULL, 0x2AD8830F258ACB52ULL, 
            0x4DB2745384EAC0F2ULL, 0x49152D1DB1882FE3ULL, 0x099307959818BEF3ULL, 0x46CB5303C69351D3ULL, 
            0x236696630EDEF4F2ULL, 0x02CF45535A1FF8B1ULL, 0xA8D03E9CAC8FDCA2ULL, 0xB26C971B3B5B4112ULL, 
            0x342B0F453C69E5D6ULL, 0x2D1D111B0E07311FULL, 0xEB8E81D9357E20F3ULL, 0xE97B148BF1D0CE81ULL, 
            0x200307BA5E87D93CULL, 0x2D2D4DB62F07D32EULL, 0xF2D38F88E28562E0ULL, 0x1E1B74528D689027ULL
        },
        {
            0x746FD30356236100ULL, 0x360BA6201B8AD13BULL, 0xA06ECD2FB4A7B4F1ULL, 0x489DF626B7611C1AULL, 
            0x652640FFA680413FULL, 0x5BD6199C96794BC3ULL, 0x5EF96BC29B3ACC92ULL, 0xCC218EE3B4049802ULL, 
            0xEF341272CDC9AA27ULL, 0x12CC7282AFD3482FULL, 0x080C8C7B04CEC450ULL, 0x19F0E4380118E922ULL, 
            0x11F06FBD07AC5F89ULL, 0xFF1B41CE162AF679ULL, 0x7556FBF400A971BCULL, 0x99D27B5DEC41E48AULL, 
            0x0CE91B02535D55D4ULL, 0x97937CB562E539B6ULL, 0xE1ADAD3D137B48DBULL, 0x2C9D58E05098509AULL, 
            0xDAB3559E800B6B50ULL, 0x78154DC77D8F40EBULL, 0xBF6FBB93DAA46C87ULL, 0xBA55D67A819BAC72ULL, 
            0xDD706DDB3DE34F3EULL, 0x230CFC21D4D54C72ULL, 0x82A13DE6DA3C027DULL, 0x6A0DD9D0B658F972ULL, 
            0x1C9A36CD93EFABCFULL, 0x694899078110DD9CULL, 0xA14B6BD2EAB67A87ULL, 0xBA44D40ACC375021ULL
        },
        {
            0xCF85B1C9BE027353ULL, 0xAEBB9A4F6246750EULL, 0x186209A93D4CF02CULL, 0x993A5A7CE5089765ULL, 
            0xB573556C8803B233ULL, 0xE2CAB92F692C1BC8ULL, 0x90597F943AF535F0ULL, 0x4D9D98C4F6DB507DULL, 
            0xC0D687B7A73BEAF6ULL, 0x86590655C068F6D2ULL, 0x7551D10AFC0A3265ULL, 0x61CB5C830421CE07ULL, 
            0x4E268D36C842E2BBULL, 0x8B9E991C09A6171EULL, 0xEFDA8C69CF18EF4AULL, 0xF0B11D2E6F13C4AEULL, 
            0xDA5A7C33CAB103C1ULL, 0xF9BAA2C596B7C476ULL, 0x17821D27D980D46DULL, 0xC9EFC47223C1C4B5ULL, 
            0xF5C85DC05E11B6C4ULL, 0x270F9740095BD8CCULL, 0x51C87255B8312B7CULL, 0x10A3E93788A89F5DULL, 
            0x1D505060C6126406ULL, 0x7D82F6EE04FF9C7EULL, 0x0235CA66BEEB90BAULL, 0x093A5B2BCB1CB4D8ULL, 
            0x57815A47B540475EULL, 0x31F290B7CD4DD9FBULL, 0x1A41C8B35BA42075ULL, 0x7A9925E95709246DULL
        },
        {
            0x7079F017C809DFBBULL, 0xD18E1B2156A6814AULL, 0xF5ACE5342069201AULL, 0x3BCF0AE70F1808E1ULL, 
            0xE39A27889DA1D660ULL, 0xCC674CD2EADCF909ULL, 0xE5820E846F0D4ED8ULL, 0x88209218476521DAULL, 
            0x6F293237637F5BB4ULL, 0x10769CB6FBAD21ADULL, 0x22B0312C34BD31C3ULL, 0x7C69B247EE21736AULL, 
            0xE92EE7D5C0B9CFDFULL, 0xBD51FCE1FBBA2C5BULL, 0xDEFF2BC46B4270E5ULL, 0xF94A3C5CCB55EAB9ULL, 
            0x50C0FE46024CD154ULL, 0xA50F79113C24F29AULL, 0x0B18CF151651D406ULL, 0x26D4681AF85CB3ADULL, 
            0x1EFCE0807F08DE63ULL, 0x8ACF28523A6CFCE3ULL, 0xD9C924E225D8F542ULL, 0x79CE54180DC815ADULL, 
            0x2BB66457AF8DDCA9ULL, 0x3B7A1D7E602B9AB0ULL, 0x230EF7C468CFD6DFULL, 0x69C47BFA0E9FB90AULL, 
            0x73C769644AB434D0ULL, 0x74968A4201E375F9ULL, 0x98A413180CB2843BULL, 0xDC5F700665189F8DULL
        }
    },
    {
        {
            0x5ED2EF941F93D203ULL, 0x4D64729C6CFFA6D1ULL, 0x2A85F8687FC7A25EULL, 0x03B14CCF1DBD6534ULL, 
            0x66372A204F293356ULL, 0xF327BA954D5B3545ULL, 0x73B4ED42492BD26FULL, 0xBE580B60CE41C7AEULL, 
            0xAF30289E9138BCD9ULL, 0x3970A2C0636F02C4ULL, 0x3ECF4CDC3D59BF6EULL, 0xC206792C61592B57ULL, 
            0x6D423986925F8718ULL, 0x839DF3E9BC8359ACULL, 0x8ACF365362D64EAAULL, 0x6B9D95D4C7E27C7FULL, 
            0x403947940241C798ULL, 0x7930BBC9D321F0A3ULL, 0xC1D12D3B86975515ULL, 0x428323A5A12BCF0FULL, 
            0xB6D8FAA4F075A1C4ULL, 0x1ED00C8374F7A1C8ULL, 0x89C433C45222F648ULL, 0x84282BED1FA8BA1FULL, 
            0x552668196A817BF5ULL, 0xE9B13787FCF0E5F0ULL, 0x625405720DB46FABULL, 0xCC327CBC90B8AD45ULL, 
            0x90727FF93D012148ULL, 0xF1B2BA850249162CULL, 0x8439B6AD72CC5F89ULL, 0x55E74398470DE415ULL
        },
        {
            0x7E1981D1DB3CAE22ULL, 0xA459652EF5CFFC3EULL, 0x2F70D54F7166A5B2ULL, 0x5530067063232514ULL, 
            0x412FF1B9E1F18433ULL, 0xC3CD2EF37E553611ULL, 0xA5F1BA7D17421537ULL, 0xDA6330217945C0C1ULL, 
            0x0369EBC1FCCDA00AULL, 0x94C1C828F909A9C7ULL, 0xA34CDD50F8F7F52EULL, 0x4E725458C673FFA6ULL, 
            0x5E515AF9A5FE4F37ULL, 0xF6438F2053C46052ULL, 0x7D1FD6BDF0C08F3EULL, 0x39BA1A902B9E4852ULL, 
            0x7338C9A2ED6EE313ULL, 0x0117DFA368F6860DULL, 0x032DA0A46BA6CE11ULL, 0x00E37951968101A8ULL, 
            0xBE2F484BFDCFAB7EULL, 0x49651D6AF90FEC12ULL, 0x83CACA4EE048F47EULL, 0x6077E1F03C0C6576ULL, 
            0x8A2034928BA8C7D9ULL, 0x0DB4F0ACF63DDA39ULL, 0xEB753040ECB0F11FULL, 0x1C0F1550E6280493ULL, 
            0xC3484E14E52E970CULL, 0x82956D5E584A337FULL, 0x2E9F46A14C1D4265ULL, 0xE6C880F2B52056F3ULL
        },
        {
            0xEF13F2ABC5AE7AD3ULL, 0x74316126BD655C08ULL, 0x18E56D19F8418862ULL, 0x324B95D6D23E2C2BULL, 
            0x4356621E042E72E8ULL, 0x391106CE29068EFBULL, 0x600EC1EB1F15BD0EULL, 0x02AC92B57EA2351FULL, 
            0x5C1E1881FE3DB33AULL, 0xD8FBE433D2B5368BULL, 0x41820255DC5715D6ULL, 0xF08C63BCB2DC3EEEULL, 
            0x7FB579631F6962B5ULL, 0xD2B8B2F253DBBF98ULL, 0xD9F1E1E73E74DB70ULL, 0x584F093F45E5B95FULL, 
            0x9FCD07625F963B0FULL, 0x8F7B87FEC7A65C73ULL, 0x063364C3860E4503ULL, 0xBC8DAB3DE9FC87A2ULL, 
            0xCBC717169FDF0B16ULL, 0x80B365AF1CBE1872ULL, 0xBCE8E0959C55904BULL, 0x6A435DF6B0D2CC4EULL, 
            0x8748F6E5FBE91475ULL, 0xBA4DE672578CAE07ULL, 0x939FA081561AE1ACULL, 0x1EE8B8B57378439CULL, 
            0x13C34F5C56124704ULL, 0x0C64BBA390E64458ULL, 0x465FCE232E190ECDULL, 0x4FCEE435697F8597ULL
        },
        {
            0xC1503D916A2D76BBULL, 0x4D8D973D68E24A27ULL, 0xC308560A70D7EEC6ULL, 0xB033E47E13B0E5C5ULL, 
            0xC3C5DC733AE109CBULL, 0x238AE69692ADE346ULL, 0x7E081C0E48847E91ULL, 0xA4576384DF766D72ULL, 
            0x28567A12853D9B75ULL, 0xF2A3D33702A6CC9CULL, 0x15299123A62DEF16ULL, 0x681490B93A13FE83ULL, 
            0xC8A3254EE5F2AB81ULL, 0xB3A566BE0BC68194ULL, 0x409C8B49C3979BADULL, 0x19EA508E1F3C5779ULL, 
            0xA1D0F0E3C6398FBBULL, 0x0B90F1521A3CD23DULL, 0x949CED8CD5225A26ULL, 0x3EA2A6B1581A304BULL, 
            0xEC15ED1A1BC68C89ULL, 0xDA5CAE22F98BA168ULL, 0x767822FFB5C78234ULL, 0xE2306F9422E9D113ULL, 
            0x9F293A63783C0E05ULL, 0x9E6AE0A71A700B58ULL, 0xCF8099639B8DEA5AULL, 0x6E8A6E58674147E7ULL, 
            0x670126CD35A92F99ULL, 0xB2CADF2B495C1D0AULL, 0x4F903C80EC5BCC1AULL, 0xB8138A302E45BABDULL
        },
        {
            0x359082C1A2713E9DULL, 0x7C633D2020F7A948ULL, 0xB5AE7249F3D54AF1ULL, 0x45C0A24EF7BC65B2ULL, 
            0x6515E05CA85A442CULL, 0x96B22CC8F806A84DULL, 0x78017854AC3883C7ULL, 0x07715C8DE3E917D8ULL, 
            0xC334761FBFA1E238ULL, 0x60FF49BAB6B9BDA8ULL, 0x9B057CC0891CA1ADULL, 0x94753ED3F5037CE5ULL, 
            0xD2B079B084F7826CULL, 0x280FE8E8CF9BC1E8ULL, 0x0D8367DED63998ACULL, 0x6E4FC224036047AFULL, 
            0x4531C5ACB1F4EBB4ULL, 0x1BE7EE3BB8BD8F52ULL, 0xCBF44B0EB3FE23AFULL, 0xC12EE27851A6A579ULL, 
            0x09D52FE367EE9179ULL, 0xF7D01F892B846B8EULL, 0x4236B90BDE6F96ADULL, 0xCBE2FBD47AF7823BULL, 
            0x28F023AE93D15CF4ULL, 0xF77A529D02255135ULL, 0xC22B2BB59F99C7C6ULL, 0xF2118B1A23A8CC8FULL, 
            0x02283E20457BF065ULL, 0x3962CF5229183852ULL, 0x62783548DB8220EDULL, 0x5CF4B49FC215104CULL
        },
        {
            0xB6FFB1D02D66C04AULL, 0x3E2878033849710CULL, 0x3D31B44EC39219C0ULL, 0x10A4F2453F11C156ULL, 
            0x5FA7BF27E0DFCAB8ULL, 0xC8153D05DA7954F2ULL, 0x783165A4DD5B03CAULL, 0x0394795D5042C653ULL, 
            0x986229F485806760ULL, 0xA040CB8BD820E8D5ULL, 0x3CEF791BFF6286EBULL, 0x6D1AD0FDA4DAE942ULL, 
            0x1C7E7AD2844BA223ULL, 0x5DA48D563DFAC7D5ULL, 0x98BA49D87BBF512CULL, 0xAD733B06815B2D50ULL, 
            0x5CC547BB61C7F0FFULL, 0xEF4BD565C8707F69ULL, 0x159A7EEF8B68882AULL, 0xA90CE44EF734AE4DULL, 
            0x976DCC01FCC23A01ULL, 0x83BE2DE7A23F25CCULL, 0x49D39B1DDD90C6E4ULL, 0x9AB2025492F23EC1ULL, 
            0xB0D4A0E87B4C554FULL, 0xED519FA44EEAC803ULL, 0xC70AB3C3333BF2E7ULL, 0xF44484A01D714180ULL, 
            0x5CE7F6E4553E6A01ULL, 0x7DC293F45A82D648ULL, 0xA04E04BB70E263C6ULL, 0xF14D44221095B4ADULL
        }
    }
};

const TwistDomainConstants TwistExpander_Miram::kPhaseDConstants = {
    0xFF072AA0EECAF44DULL,
    0xFF82D670FAE905F5ULL,
    0x5867818A0BB38B39ULL,
    0xFF072AA0EECAF44DULL,
    0xFF82D670FAE905F5ULL,
    0x5867818A0BB38B39ULL,
    0x44B670E5975414D4ULL,
    0x91411CFA947F11A9ULL,
    0x6B,
    0xC8,
    0xBE,
    0x21,
    0x94,
    0x57,
    0x14,
    0x5D
};

