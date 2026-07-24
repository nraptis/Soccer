#include "TwistExpander_Capella.hpp"
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

TwistExpander_Capella::TwistExpander_Capella()
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

void TwistExpander_Capella::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x97FC2605AF9A64B3ULL; std::uint64_t aIngress = 0x88C6E34F05392D77ULL; std::uint64_t aCarry = 0xBDEE939695703C37ULL;

    std::uint64_t aWandererA = 0xDCB0E9BA65E8387CULL; std::uint64_t aWandererB = 0x8A7ADB1C1BA4578CULL; std::uint64_t aWandererC = 0xDAD5C95AB6D07830ULL; std::uint64_t aWandererD = 0xF8FB36CF0E447BC5ULL;
    std::uint64_t aWandererE = 0xE0D3902768840C2EULL; std::uint64_t aWandererF = 0x8E38C4CAF0BF5361ULL; std::uint64_t aWandererG = 0xAD948C21AE99D700ULL; std::uint64_t aWandererH = 0xA0B1747C5D8FDF57ULL;
    std::uint64_t aWandererI = 0xD1FFBEB69339439AULL; std::uint64_t aWandererJ = 0xDD9F9DBCBCF67EEDULL; std::uint64_t aWandererK = 0xA6630F69FE67D6B9ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xA2A4F1F7DDF92714ULL;
        aCarry = 0x98E00C6C0FD9342BULL;
        aWandererA = 0xC2BBE14881DF4BC8ULL;
        aWandererB = 0xCDBDC908EBA4C84EULL;
        aWandererC = 0xE1CC312D6F54B0F4ULL;
        aWandererD = 0xF38B1E92B3698F5BULL;
        aWandererE = 0xFF202F7A3FDD1CCEULL;
        aWandererF = 0xC7C3CBA6DC98E5E7ULL;
        aWandererG = 0xA37B296D7F740278ULL;
        aWandererH = 0xB03085FEF77ABC5AULL;
        aWandererI = 0x8EC3844B6A8430D3ULL;
        aWandererJ = 0xB4CA6757DD811A79ULL;
        aWandererK = 0xA136AA07388904FBULL;
    TwistExpander_Capella_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Capella_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Capella_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Capella_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Capella::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD41FF3B90432D266ULL; std::uint64_t aIngress = 0xDC02D2BF50777FE4ULL; std::uint64_t aCarry = 0xA7425B463732BD4BULL;

    std::uint64_t aWandererA = 0xF93AD436472AE45DULL; std::uint64_t aWandererB = 0xD5616A77B3CFD984ULL; std::uint64_t aWandererC = 0xD09F14264E04B59EULL; std::uint64_t aWandererD = 0xD31FF3800F28C96BULL;
    std::uint64_t aWandererE = 0xE316F5FC8E35C4FEULL; std::uint64_t aWandererF = 0x968F1211E2798F2EULL; std::uint64_t aWandererG = 0xD5321CF770E7C4C5ULL; std::uint64_t aWandererH = 0x9FB37ECF814EF962ULL;
    std::uint64_t aWandererI = 0xC6F1BF31D2EF15ACULL; std::uint64_t aWandererJ = 0x86699EA91EAE6209ULL; std::uint64_t aWandererK = 0xBD3F4F350838168CULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xE9BF1B0A4EA09C01ULL;
        aCarry = 0xBC668CCA26CA80AFULL;
        aWandererA = 0xC748CFDA841B324DULL;
        aWandererB = 0xA519048A2C178542ULL;
        aWandererC = 0xE8E49AB8A402E394ULL;
        aWandererD = 0x8A51B261820F15C2ULL;
        aWandererE = 0xCC2515B7415D52ECULL;
        aWandererF = 0xB9ACD73E2B0D3F56ULL;
        aWandererG = 0xD41A81396D85EA4EULL;
        aWandererH = 0xDBF8F8B9DC8D6E41ULL;
        aWandererI = 0xE4B537354C0C9457ULL;
        aWandererJ = 0xB56D50B520376C6EULL;
        aWandererK = 0xD5703E55C35CEB1AULL;
    TwistExpander_Capella_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Capella_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Capella_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Capella_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Capella::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB64B1D8D92D1F07DULL;
    std::uint64_t aIngress = 0xAB8BF81E9B066006ULL;
    std::uint64_t aCarry = 0xD05D29B792ABEA90ULL;

    std::uint64_t aWandererA = 0x8C735355172DA58FULL;
    std::uint64_t aWandererB = 0xC921629D3EBBF49DULL;
    std::uint64_t aWandererC = 0x8B34B9500974CDA8ULL;
    std::uint64_t aWandererD = 0xAE58F538B752AC03ULL;
    std::uint64_t aWandererE = 0xBB485A9AFE6BAE2DULL;
    std::uint64_t aWandererF = 0xED8654A6A8DA7E51ULL;
    std::uint64_t aWandererG = 0xDBC948A4B5CF23A7ULL;
    std::uint64_t aWandererH = 0xBD25912F3068F6B2ULL;
    std::uint64_t aWandererI = 0xFB7A7171965E979BULL;
    std::uint64_t aWandererJ = 0x90DA046D994D4BEDULL;
    std::uint64_t aWandererK = 0xAD2B3D6BB61A8BC1ULL;

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
        TwistSquash::SquashB(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, aIceLaneA);
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
        TwistSquash::SquashC(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, aIceLaneB);
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
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), pSnowLaneB, 2);
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
        TwistSquash::SquashC(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, aIceLaneD);
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
    TwistExpander_Capella_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Capella_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Capella_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Capella_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Capella_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Capella_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Capella_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Capella_Arx::Seed_H(pWorkSpace,
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

        TwistSquash::SquashC(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, pDestination);
    //
    //
    TwistExpander_Capella_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Capella_Arx::GROW_B(pWorkSpace,
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

// SmartSquash candidate 15 of 33
// Exploration cases: 100000000
// Nearest-family diversity: 933 / 1088 (85.75%)
// Total distance from earlier candidates: 13289
void TwistExpander_Capella::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    static_assert((S_BLOCK / W_KEY) == 16, "SquashInvestToKeyBoxes expects 16 invest fragments.");
    static_assert(H_KEY == 8, "SquashInvestToKeyBoxes expects 8 key rows per box.");
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 11U), *aFragmentB = aIceLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 7U), *aFragmentD = aIceLaneD + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 422U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 672U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1143U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 405U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 10U), *aFragmentB = aIceLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 11U), *aFragmentD = aIceLaneD + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 489U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 920U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 891U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1549U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 14U), *aFragmentB = aIceLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 1U), *aFragmentD = aIceLaneD + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1211U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1651U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 773U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 5U), *aFragmentB = aIceLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 3U), *aFragmentD = aIceLaneD + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 2U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1450U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 528U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1011U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 6U), *aFragmentB = aIceLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 12U), *aFragmentD = aIceLaneD + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 718U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1700U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 371U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 258U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 8U), *aFragmentB = aIceLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 5U), *aFragmentD = aIceLaneD + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1925U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 486U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 749U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1557U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 0U), *aFragmentB = aIceLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 10U), *aFragmentD = aIceLaneD + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1000U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1154U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 937U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1055U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 1U), *aFragmentB = aIceLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 13U), *aFragmentD = aIceLaneD + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1507U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 539U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1195U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 924U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 4U), *aFragmentB = aIceLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 9U), *aFragmentD = aIceLaneD + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1646U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1113U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 509U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1151U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 15U), *aFragmentB = aIceLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 8U), *aFragmentD = aIceLaneD + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 984U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1403U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 167U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 514U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 12U), *aFragmentB = aIceLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 15U), *aFragmentD = aIceLaneD + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 602U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1945U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 337U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1524U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 2U), *aFragmentB = aIceLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 4U), *aFragmentD = aIceLaneD + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 266U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 460U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 35U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 102U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 3U), *aFragmentB = aIceLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 6U), *aFragmentD = aIceLaneD + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1635U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1963U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1016U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1541U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 7U), *aFragmentB = aIceLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 2U), *aFragmentD = aIceLaneD + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1747U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1193U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 658U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 381U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 9U), *aFragmentB = aIceLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 0U), *aFragmentD = aIceLaneD + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1908U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1772U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1160U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 648U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 13U), *aFragmentB = aIceLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 14U), *aFragmentD = aIceLaneD + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 481U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1437U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1711U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 70U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Capella::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xBE2C971B28C3A600ULL; std::uint64_t aIngress = 0xB9637073F6849023ULL; std::uint64_t aCarry = 0xA50BD11F80EF1783ULL;

    std::uint64_t aWandererA = 0xC6EB68EAE0C79904ULL; std::uint64_t aWandererB = 0xB8C3D608C62A5BFAULL; std::uint64_t aWandererC = 0xB724732D95EE0D8EULL; std::uint64_t aWandererD = 0xEAA25EF60D943A2BULL;
    std::uint64_t aWandererE = 0xF0A51BFCADF48B9DULL; std::uint64_t aWandererF = 0xBF6974153B686148ULL; std::uint64_t aWandererG = 0x87FF50026B97E8A5ULL; std::uint64_t aWandererH = 0xF0D0644F7EA5054EULL;
    std::uint64_t aWandererI = 0xBA363828D3DB1244ULL; std::uint64_t aWandererJ = 0xA7DA024BAFD17638ULL; std::uint64_t aWandererK = 0xAED1EAA8006E02F9ULL;

    // [seed]
        aPrevious = 0xE5B6BCB1CCB8AFE5ULL;
        aCarry = 0xEE629E743EC15ECDULL;
        aWandererA = 0x90556223984B69FCULL;
        aWandererB = 0xC92E170FB7808173ULL;
        aWandererC = 0xB20590F4DAB9BE42ULL;
        aWandererD = 0xF0DC035955C7E3FBULL;
        aWandererE = 0xB4F920FB4783B067ULL;
        aWandererF = 0x948CBABF747AD227ULL;
        aWandererG = 0xB5CA6FC86AF663DAULL;
        aWandererH = 0x93883D6841FAFC71ULL;
        aWandererI = 0xA3AE57C41DC69709ULL;
        aWandererJ = 0xB09BE7C7FCF52224ULL;
        aWandererK = 0xA5C82D04C0714A7EULL;
    TwistExpander_Capella_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Capella_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Capella_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Capella_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Capella_Arx::Twist_E(pWorkSpace,
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
    TwistExpander_Capella_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Capella_Arx::GROW_B(pWorkSpace,
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

// GrowA candidate 15 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 7669; nearest pair: 477 / 674
void TwistExpander_Capella::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5764U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8000U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1325U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5441U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3177U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5716U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4703U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5740U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7220U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7676U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4494U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 332U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4910U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4763U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6516U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5894U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1274U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 861U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 24U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 76U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1792U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1201U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1730U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1139U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 465U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 251U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 537U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 578U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 568U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 476U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 57U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 621U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 617U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 474U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1883U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
}

// GrowB candidate 15 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 7678; nearest pair: 507 / 674
void TwistExpander_Capella::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5772U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3214U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4811U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5020U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1839U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6106U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7894U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4230U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1191U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3041U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1094U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5969U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1509U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2481U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1138U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7939U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 43U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1885U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 340U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1377U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1939U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1404U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1165U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 173U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1371U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1518U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1919U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 727U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1727U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1295U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 42U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 224U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1396U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1771U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1680U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 556U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
}

const TwistDomainSaltSet TwistExpander_Capella::kPhaseASalts = {
    {
        {
            0xF7346B7338F00D0FULL, 0xE565A5A46BEB51AFULL, 0xB1CBCB3103AA9433ULL, 0xE82F4B8E3E55BC3CULL, 
            0x5EDC397FF86885FDULL, 0xB633AD05379A1ABDULL, 0x519C234E4AECEE04ULL, 0x90DF9073E489F2E4ULL, 
            0x835F969E296455D6ULL, 0xADE3EEB59860274EULL, 0x67C128A40AD58005ULL, 0x42FB5BBB45587445ULL, 
            0x2AB54A5D8559E9F7ULL, 0xE73CA536C01AFCBDULL, 0x530B6FC9A273E5CBULL, 0xFC921D9AC2BF3B64ULL, 
            0x78326287F9283EAEULL, 0x6BA394CADA8CB4FEULL, 0xAB38F763BE2E294CULL, 0xB675D234F7D2A014ULL, 
            0xB15F9FAF87E93B61ULL, 0xA031896C5D310BE2ULL, 0x2131316BD1D7D5FDULL, 0xE2AF3647AB3CC141ULL, 
            0x66293C6DB203CF89ULL, 0xDE23DAF599C9201FULL, 0x9504C748A43A11E2ULL, 0xF6E4D0ECDB3E1A3AULL, 
            0x938A91ABCBD8139AULL, 0xF2DBBB42D63544B1ULL, 0xB30A41FD177C5887ULL, 0x3F2A037F2F6268CBULL
        },
        {
            0xF62511613F303D56ULL, 0xB06A5804D41D245EULL, 0xD9B188C328ED9A88ULL, 0x46CA3E7DF94EC871ULL, 
            0xC28DF25AB8695C30ULL, 0x6BE8942CDBD028C2ULL, 0x9BE4ADB9D3CFF57CULL, 0xC075B83C2EB37C7DULL, 
            0xEDB12D74CE99B8EBULL, 0x15D47CB3D9A0D063ULL, 0x8EEDEB5E0B299224ULL, 0x7037AB8DA7E30944ULL, 
            0xC98E9171765B6DBFULL, 0x9E39DFB853B6018FULL, 0xD76E9C2C2760A4BEULL, 0x9DB49E0D4FEF6799ULL, 
            0x93BC1610A3FBB627ULL, 0x0B75BBD674C169FEULL, 0xF47A13D2DFCE6A47ULL, 0x82B31DBA6F04750CULL, 
            0xB3B70C20A6D06D73ULL, 0xF70E7DBDCE7DD244ULL, 0xC45D3F9330643544ULL, 0x95195FAA10723340ULL, 
            0xBDB842EB66A96AF3ULL, 0x26D7776B6127F019ULL, 0x545529387645B9ADULL, 0x9B23EA2D75519DFBULL, 
            0xF49E9D026CD46EF6ULL, 0x2C7C2B2C7F70CE39ULL, 0x8141312E8720E42CULL, 0x16EEC6A1486DF803ULL
        },
        {
            0xDE6485DE1131822EULL, 0x4F56AED8E4FB06A6ULL, 0x75CAEC6136DA5E01ULL, 0x0DE3ED7365FB8FD9ULL, 
            0x68B6E66D89F54F69ULL, 0xAD69C9CB59C091DFULL, 0x08E6E976FB8ADC69ULL, 0x1BB4B77316B7499CULL, 
            0x57833685E6B0600CULL, 0x13BC1C4E96F94755ULL, 0x5556E1FC997BDB09ULL, 0x251DD44E228A1A59ULL, 
            0x573757D240F6F980ULL, 0xF5BBA7453E476DE8ULL, 0x5AFB31D442E66B5BULL, 0xE63B3188602FCD5AULL, 
            0x4EAF2D5A013CCD78ULL, 0x82675EB83341A54AULL, 0x1EF397BDAEE25DC9ULL, 0xEA3812B9000E2C4BULL, 
            0x6DC3213907240DDDULL, 0xA4654BD541A166FDULL, 0xEF48682379B7BF3FULL, 0x98EFF6A7F3B96519ULL, 
            0x84564B8C0C919F9EULL, 0x3A119C4FFEFB5548ULL, 0x2EFD2F466ADA1755ULL, 0xE63C0D3B8865F204ULL, 
            0xF5369463026464F3ULL, 0xB289FA0EC4458509ULL, 0x184E18DDAD2BBEE6ULL, 0x86B937D9177CB391ULL
        },
        {
            0x5ED24A815A2A1FD5ULL, 0x1A077D3D5C76EF7FULL, 0xFD48EA2CD9EDCE6BULL, 0x3783FB0F82DDA205ULL, 
            0xD6A660F06406B759ULL, 0x872A7446594FB203ULL, 0x75AFF5AD89964722ULL, 0x5ED1C38535C3F524ULL, 
            0x0B0E0A870DDDFFF8ULL, 0x072AB2C4A22363F8ULL, 0x5ED3BA6099B47938ULL, 0x93C2DEF629E10AD4ULL, 
            0x2C36E3E5042F4427ULL, 0x2B8E112C335DAEE2ULL, 0x1190254FA4302B8DULL, 0x5786D234D5018AE9ULL, 
            0x71486EA245420E52ULL, 0xD13073AEB24A4367ULL, 0x826BB4B933D65322ULL, 0x5B7E41FC3D9D8150ULL, 
            0x774F7A350D6DFD94ULL, 0xEC40B8D3CD791EE0ULL, 0x41F6ABB5BA49014BULL, 0xCFEBD9E1A51BB6CAULL, 
            0xE540826DC59AD5D1ULL, 0x87B7FF2C75ADF433ULL, 0x701E4E5A66B88C61ULL, 0x18E9B0A632E16F3CULL, 
            0x33CD17E4923B19ACULL, 0x474FEEE78EC6A18AULL, 0x8655473739C9C21DULL, 0x326FAC7EB34032CAULL
        },
        {
            0x1B4AE4B960558205ULL, 0x5EB1EF5E6A11A09BULL, 0x68721F13B8834406ULL, 0x14BEEFD46137BD6CULL, 
            0xEA34746A0E0D54CFULL, 0x018B86EB8BB4A2B8ULL, 0x917C0851BB409E2AULL, 0x374A89863E86EC5FULL, 
            0x0145F6A3A62A227BULL, 0x4D5FF32A5754ABD8ULL, 0xB9A1771D0ACFEFE0ULL, 0x46607A814ABFC4B4ULL, 
            0xFBD6F7F72173BA4DULL, 0xBF88655A7353D989ULL, 0xF09B675B1AAEF29AULL, 0x640312F973CB6762ULL, 
            0xFE1040CA24204FC6ULL, 0x4DA7A8772186B7E2ULL, 0xB2976899CF6096FBULL, 0xA997352FF2201A71ULL, 
            0x6FF63A0F464A41ADULL, 0xFEB0B6C8AEBC60BFULL, 0xBF03C398737861FAULL, 0x3661BF34C5019FE7ULL, 
            0xE94EA558AA0E71AEULL, 0x8858FDC3B8BCCBDFULL, 0xD74BAF1B89E603A5ULL, 0x223D409595737E2EULL, 
            0xC8437A62F2483A44ULL, 0xA6D50F740140FCDBULL, 0x2AF388DF9739717EULL, 0xC65A85358EAD7D63ULL
        },
        {
            0xACAF461D960B9C00ULL, 0xF0B31187CE4DBC21ULL, 0xCB44D4CFC03EA912ULL, 0xEFD2594B7B242DC2ULL, 
            0x988C48FADE141E12ULL, 0xB7FD9059FFD0B21AULL, 0xCBDD08E559E1C837ULL, 0x9621E6A647F025B4ULL, 
            0x9BFABBE98D04735EULL, 0xF5359A9FDBC524A0ULL, 0xD473C2B7172D329DULL, 0xCA6401ED546C2586ULL, 
            0xEEAB2D60A85DEDCFULL, 0xF99EF7D12271B5F6ULL, 0x7F7D57CDC77C3854ULL, 0xE80F54306CD186EFULL, 
            0xFBE47D3192C27DBBULL, 0xEE497AB9CB6ECCA0ULL, 0x61678C6938D9776BULL, 0x25B206DA856957CAULL, 
            0xFDC29B60495B4CF0ULL, 0x1400D9E2AB7D8CD3ULL, 0x362013A074104FE7ULL, 0x9ABDCCAE9CCAED94ULL, 
            0x3FDBC62EA33E1FAAULL, 0x41C2463757E281A4ULL, 0xF1A737A9BCD82D7BULL, 0xBF198B9C2A72D473ULL, 
            0xA2C2996E7ECA1651ULL, 0xABF66EA32EFD88E3ULL, 0x0437C13527E67DCCULL, 0x4AD288F5032E1C46ULL
        }
    },
    {
        {
            0x3D99741E7799140EULL, 0xD7E3B5B34400B333ULL, 0x1FEFDA21621FC044ULL, 0x7FEE8A968E9416D9ULL, 
            0x88CA88AC20D6BEF8ULL, 0x968CA6F197CF17BAULL, 0x2ACD5DBEF2E378FFULL, 0xD7BF8699C17FE718ULL, 
            0xAC4A6A4037AA95B5ULL, 0x5A7A569BD2C533A3ULL, 0xD965A55E52B1FA24ULL, 0xDCE51246B9095789ULL, 
            0x5D5D644E344E47B9ULL, 0x087E13C393E80FC4ULL, 0x45AF46EF110DEAB7ULL, 0x084A9CF1DCEB7DD3ULL, 
            0xF92245BEB1D8AC4FULL, 0xE8DE2E9FB565FEC4ULL, 0x457FEFBB33E22197ULL, 0x43D02C5501B4F258ULL, 
            0xC81CF7A4DFEC12DDULL, 0x68412838C301B61EULL, 0x5C1B988E0AD9FE42ULL, 0x9CF6CCCD57213467ULL, 
            0x35E74ADB3713941FULL, 0x99DF0047A3A90702ULL, 0x500924A244C03642ULL, 0xCB59D3C2567E76F0ULL, 
            0x84932F97B097F4E3ULL, 0x4CBCAE7C88E91221ULL, 0x15E8132C740BE945ULL, 0x64AA08ED1A229A93ULL
        },
        {
            0x0A19C65C346F85EEULL, 0xD56C49B899C4F072ULL, 0x4E7A36DFBCC4595BULL, 0xC3C2E1DF558EE0E2ULL, 
            0x1A97A26BD99243BCULL, 0x7123C20E09A79459ULL, 0xC93B5EB473C5EBFAULL, 0xD6C4784FF34A96D6ULL, 
            0x76F013929E4BF6C7ULL, 0xE5838F717DDE8635ULL, 0xA1AC231C6EC21953ULL, 0x811C2525F6ABFCA7ULL, 
            0x914A7E6026A055FCULL, 0xBE640E804A851EA2ULL, 0x98A001EB1FB68ECFULL, 0x911610CEC8145AB4ULL, 
            0xE9BB580DD710F0A3ULL, 0x4E6BE023940F3EFDULL, 0x216E176B5CE1A124ULL, 0x40EABCD1972C3203ULL, 
            0xDDF34FDBAB05FCC8ULL, 0x1DD50436AB6793D2ULL, 0xB885821AA5562CBFULL, 0x28A24084D1ABA625ULL, 
            0xEF7CCB667BA5219CULL, 0x29A0FA786E0DE764ULL, 0xA50B984F8AF97BAFULL, 0xDF7EE24D71D1958FULL, 
            0xE907C48243E7EEDBULL, 0xEC2FEE255B6B50D7ULL, 0x1D51B8A624180BC6ULL, 0xE298FD125FD73591ULL
        },
        {
            0x3CD4E40E40EFD6FEULL, 0x0B452CB5B3787596ULL, 0xBEFDEA21F0E07078ULL, 0x010FE7C67A2489A3ULL, 
            0x2B38DC3D53E87E18ULL, 0x23A601AB46A7CE41ULL, 0xA646F843C7DBB495ULL, 0x7DCB256E5855C85FULL, 
            0xFA6486DDE04AF5A3ULL, 0x00AD72324BCE98C9ULL, 0x0218E6ECEBB823B6ULL, 0x20B814FDFBDF449CULL, 
            0x9DF5A8BE7F813574ULL, 0x6DF39B79FC16E8C7ULL, 0xC58DAC762EDDF230ULL, 0x25128DDD61D68DBCULL, 
            0x23B0170854371E28ULL, 0x14B4A0F91AA4767FULL, 0x3FE4FCCC36D6837DULL, 0x8E55C9236B9DE82BULL, 
            0x2096A5D1738324F7ULL, 0x0A3F4E0D4A4D8B69ULL, 0xAE66179C405F7467ULL, 0xBA7DAFE808018852ULL, 
            0x661A9435F9BD6A9CULL, 0x4DCF6724670C6047ULL, 0x508A6D840DDE9DBCULL, 0xC236517C5017E8F5ULL, 
            0xBEF0E9259F868206ULL, 0xAE9ECE2DA2D8336BULL, 0x007B8249E40E776DULL, 0x016B4C508F85776FULL
        },
        {
            0xAF078652889FD672ULL, 0xE04ED4AE5C8DD075ULL, 0x466652BAE5636E64ULL, 0xCC72508AE7F4F183ULL, 
            0x1835E5299AA8D253ULL, 0x14EE5830D964831BULL, 0x4B4B631D889DDF8AULL, 0x6220030AB25FA5D5ULL, 
            0xA55B7F9B0BAAB62BULL, 0xC2287F88BE908DF6ULL, 0x78D25198D799B35FULL, 0xB5D9E8F1E436A530ULL, 
            0xCF31B325E44F379CULL, 0xE6617AE544933A4AULL, 0xFE925FFC6E98FC18ULL, 0x55F6D6B9C90BAF19ULL, 
            0x1DC546143A7DC625ULL, 0x3D5363CECEE41073ULL, 0x37EEAA95DFC5FF6FULL, 0x86A008D498C30E23ULL, 
            0x49C835260194255AULL, 0x3EE4135A22F9AAA6ULL, 0x7ED01A2E8BFCE252ULL, 0x257B487EF2C2EA4DULL, 
            0x911F44A52870A1F2ULL, 0x6FE983D9C1A12685ULL, 0xE5361B8702A6A24AULL, 0x76AB89F335388C2EULL, 
            0x771A77A0BEBB7551ULL, 0x63405828FF83ADC3ULL, 0xA520D5631983F7E4ULL, 0x15B326B6A6C54BCCULL
        },
        {
            0x22A58589E5A76357ULL, 0x7A5DE1B3716BA9AFULL, 0x055CA362A054FE36ULL, 0x12F746F1B0FFB7E5ULL, 
            0xC7B127A8FB6CF3E7ULL, 0xD4DB6D8DB79AB9D2ULL, 0xD8F1A0865F56A356ULL, 0x1137AE3212720451ULL, 
            0xCA06FEF291BAF674ULL, 0x1D41D45503F2D85DULL, 0xFB7EE1937E2910F9ULL, 0xB2D34391A836D284ULL, 
            0x32C4B4189F11B250ULL, 0x9A69CD184CCA84C6ULL, 0xD464CCB5EDD040E2ULL, 0x69F0CA4251A714A7ULL, 
            0xA4B5ECBD28319D7EULL, 0x80FAC82B1C5BB58DULL, 0x7719920586537ED8ULL, 0x392AF8A86FDB441CULL, 
            0x716E38CC5CA2435EULL, 0x9F5A21F6F7110A18ULL, 0x2E5C7454E526F774ULL, 0xF8315B40C9C25B93ULL, 
            0xD9C26E8611855250ULL, 0xA0FFE64B84355B6AULL, 0xF944B10D9A02D141ULL, 0x4293D14BE5BE6228ULL, 
            0xD3E01D68A49175D6ULL, 0xEBF2107237A74529ULL, 0x7E9BA361D6BE2297ULL, 0xFE8A14B43D46BA19ULL
        },
        {
            0xA08452AC9B4FC2FAULL, 0x182128E152EB9081ULL, 0xE19F60BE4881565EULL, 0x9C4C7C5C085FF931ULL, 
            0x74853215AB55FFF9ULL, 0x236C2D57C877C51BULL, 0xD1E2FA98661ABB4AULL, 0x5FDA6ED2D997C41AULL, 
            0x7D2A79B85306E58CULL, 0xF03B3C05462AFBEAULL, 0x1172ACBD8654EDA1ULL, 0x26EBBBA49DC7F571ULL, 
            0x752C6A46B145FBEDULL, 0x96E897034F24EC57ULL, 0xC4C58F0262200F4CULL, 0x3FECD77B080EE2CAULL, 
            0x1231E0E019139872ULL, 0x20571F0D8BFB1924ULL, 0x9F312649B228D518ULL, 0x142220A510A22338ULL, 
            0x1BFA7D591DC42CABULL, 0xD935049B42DBABD2ULL, 0x4D7BE552B9CBD7CFULL, 0x868EF568243CE82EULL, 
            0x4605918A229D5F64ULL, 0xDD5C9AC67412BB3DULL, 0x318656778A1337D9ULL, 0x56BCD94844B425F3ULL, 
            0x90CD2063F0C5FB13ULL, 0x8D8B2CA6F6292366ULL, 0xEEB0AEB29C47A989ULL, 0xF099BF8538BCB128ULL
        }
    },
    {
        {
            0x8D7045B8B6EF86E2ULL, 0xE3A249A2C3CFBB69ULL, 0x99C5430F346A324FULL, 0xDE0DA7D23FA6F723ULL, 
            0x465504441139A3CFULL, 0x2B83B6FC31854D70ULL, 0x5F268776B529941CULL, 0xF8A5E07F2CEA3562ULL, 
            0x0C420049BDEBA70CULL, 0xCE06036CBE95BEC3ULL, 0xC68CFA0AA3AF2C1FULL, 0x371B28D161FDE2BEULL, 
            0x9A016393025363BFULL, 0xF26CE90EB56F031CULL, 0x5A4EFA816A96EE01ULL, 0x25BF84FF8FAA6C73ULL, 
            0x36BC640124B9411FULL, 0x02E026DFA409983CULL, 0xC48A473306C8C348ULL, 0x167AC505671BB0F7ULL, 
            0x25693B2EC989A990ULL, 0x14DAFB2C6B7D6D5CULL, 0xD5B3B4C220B3355BULL, 0x11673CF7056BF824ULL, 
            0xECE01745B56E2B1DULL, 0x93D2FBF14FBE01DAULL, 0x45CD217FC12CDA92ULL, 0xB5CA9ABF5FF963FEULL, 
            0x160C573CC348CB6FULL, 0xB83DFEECD56058CCULL, 0xDE32267D0823DEACULL, 0x737F35E9A652A76AULL
        },
        {
            0x60E7DDCBA593E99AULL, 0x042672C66B9360D5ULL, 0x00E128078A483C14ULL, 0x61482AF69CACCE8DULL, 
            0x3F58F86DEA28B014ULL, 0x699D88EA07C9B6D0ULL, 0xA1EB47A797CDBC10ULL, 0x8D4B303A38740F6BULL, 
            0x911E78CDA3C451CDULL, 0x62A7503490ECA4E5ULL, 0x1CFDEB95DA832722ULL, 0xE72013670FF3434AULL, 
            0x75D49F4375C49F40ULL, 0x5DD6E0D1D109BB22ULL, 0xA0F311361FAA797EULL, 0x0440CFD001C5660AULL, 
            0xD8D4DB639116C7A9ULL, 0x794CB9BF1A268116ULL, 0x44F19355947405F4ULL, 0xBA53048DC39E62D1ULL, 
            0x804658CC1AF71549ULL, 0xC40AAFA888C58777ULL, 0xE186C0B8F0FB3926ULL, 0x44502D10A9CEEC24ULL, 
            0x32CC8E7E518811B0ULL, 0x9026142383EA090CULL, 0x717AC905FB2997A1ULL, 0x358BCE5E9D8244B9ULL, 
            0xADCBA5AB95A11628ULL, 0xDEB812DD5703B4D9ULL, 0x295AE07383923D78ULL, 0x95642503D64E19A1ULL
        },
        {
            0xA9D7B1B1AB69B73CULL, 0xBC0EAE479D13F0F0ULL, 0x13A3BE7F1C6541DBULL, 0xF9FEA5DC0EDAB46CULL, 
            0x3758D9362F2FA61AULL, 0x16E54847AB1C4E5BULL, 0x7C240A17C2D1EBBDULL, 0xF36AD64BE7770BE1ULL, 
            0xDC91A49CF6ED04E9ULL, 0x39743E6AE8D9F3C4ULL, 0x8906145970761547ULL, 0xBB6DA476B3E9B701ULL, 
            0xB4E3D8FD88D851D1ULL, 0x3951244B54F5F0B7ULL, 0xBF6C0EF1ED42DA63ULL, 0xB0DA2F06BDCA495EULL, 
            0x9FC6111FF6CB1DC0ULL, 0xD22A1088FDFF18BBULL, 0x5128678BE142C7E6ULL, 0xFD9BB47236D8778DULL, 
            0x7D43AC09335910F2ULL, 0x10BEE47F5DEB9FFAULL, 0xC465052E20E0A519ULL, 0x4C6857A3F72B551DULL, 
            0xF282F829790E71B2ULL, 0x363AB7957324D070ULL, 0xDE0509769A137AC0ULL, 0x2FE8E7FA0AA35EC8ULL, 
            0x5E3ED26413E1C00EULL, 0x2E330E764593A39DULL, 0xDF17327321531F8BULL, 0xE801AE6854153651ULL
        },
        {
            0x8B02F0A2BF6DAF24ULL, 0xBF5AB5F31F0F5FCBULL, 0x2202B3071CE581EEULL, 0x3C9F570082C8B7B7ULL, 
            0xCEE4F91EF61A0FBDULL, 0xB72D31B4AE79C06CULL, 0xE53C053BE7CB3F02ULL, 0x3DF1BD76EF268699ULL, 
            0x1F4CFEC5ED8442FAULL, 0x61FD7D78BC608956ULL, 0x0CBF3A4C86AD740BULL, 0x3B89E610112C1F01ULL, 
            0xDFB44AFE1DD9D6DEULL, 0x563D9F62C8604363ULL, 0xBC5908A068F3A783ULL, 0xADD32ADB5570D2CFULL, 
            0x3315D97E4C99F285ULL, 0xFF135B273CEA4200ULL, 0x2F90C52527F979C2ULL, 0x0E4162D0E91EAFCCULL, 
            0x6BC2B72F56356612ULL, 0xBBC87EF7A09CC432ULL, 0x09B35F088B819D0EULL, 0xED228E37E23F1B5DULL, 
            0x8CD0F66F6B740C2BULL, 0xEEF5016E69572770ULL, 0xA2BD37C6A6E0032FULL, 0x97D5E33AC2C37802ULL, 
            0xC1BCA123F9680BDDULL, 0x34FE3AB3AF342DD1ULL, 0x4FAF90E0F7EABF43ULL, 0xACFE1C7CE649DD88ULL
        },
        {
            0x0DE58DF488E6AA3AULL, 0x9C38648F76C659C7ULL, 0xFB07BDA7F05B0BDEULL, 0xA2FEE2F10B02F305ULL, 
            0x5FCB4A8FB40BB6CCULL, 0x17500A806E939B3EULL, 0xC0CC9A305F72BD7EULL, 0x16C32531FE021C56ULL, 
            0x0FBD3E207AA30C9DULL, 0xAC53A126B9E0B10FULL, 0xE1D5E9E40F1E5CB6ULL, 0x143D018D46A2510AULL, 
            0x523126E8D9D5AC74ULL, 0xB5DF2CBF76F66ABAULL, 0xFD627ECAFDC01D64ULL, 0xE06C6D84A69C015BULL, 
            0x1098FA75F28EA0F2ULL, 0xF0E7E3BE10398425ULL, 0x616B5239832C41A8ULL, 0x385322BAC2CAF01DULL, 
            0x5E9AA7EB342E9044ULL, 0x874B181326FEDCBCULL, 0x089A52A2A503BAA9ULL, 0xBD80B491F5918E6EULL, 
            0xE7752C651085180BULL, 0x334E0281D114379BULL, 0x584F70C85F9749DAULL, 0x3F601A640AC8D707ULL, 
            0x047812D97DA61944ULL, 0x9BE8412ED538E3F6ULL, 0xDC785D77628EE944ULL, 0x356CDD7A544570AEULL
        },
        {
            0xE5C8517BC4A78E25ULL, 0x712906FE542EB959ULL, 0x77DD87A82880BF2AULL, 0xDF712FFF6BAFC458ULL, 
            0x218E497897AC3D30ULL, 0xA56ABD832D61E83FULL, 0x34396A928B3CCFCBULL, 0x251FCBCBC7CEA044ULL, 
            0x0D94542776937238ULL, 0x5604C71FB41F0F2EULL, 0xD9E9A8DBFFE908E2ULL, 0xEE35A6C6849926A3ULL, 
            0x7E96D32F7F5FA62EULL, 0xA8E62B55073B787FULL, 0xEBDDCBFA12D0C3C0ULL, 0x22AD2E6B0362DC15ULL, 
            0x0F6F69B759F426DCULL, 0xE656BB3A0B68F3CDULL, 0x4ECFC78A7C61EFFFULL, 0xC15F6B5EB066D473ULL, 
            0xC9E8911576133E3EULL, 0x7473C5FD648C7CD2ULL, 0xAF8FBFB93EC5EB44ULL, 0xAF27DD14BFCC8758ULL, 
            0xDC8496E3AB9262B5ULL, 0x2C3F4E31400E6A27ULL, 0x0A2589FDF7FF943BULL, 0x71E3582BF1B5A144ULL, 
            0x643171338B9964F5ULL, 0x625C3C243F676F96ULL, 0x1AB1247421817BE5ULL, 0x4A4A02D14BFAFFCCULL
        }
    }
};

const TwistDomainConstants TwistExpander_Capella::kPhaseAConstants = {
    0xDA6455557C3CA23BULL,
    0x9CB022ACA84CE44BULL,
    0x5D4F0A87FEBB5A46ULL,
    0xDA6455557C3CA23BULL,
    0x9CB022ACA84CE44BULL,
    0x5D4F0A87FEBB5A46ULL,
    0x53348CEA9BF8A2CEULL,
    0x77090017208E0FCAULL,
    0xA5,
    0x97,
    0xEF,
    0xE2,
    0x30,
    0xCE,
    0x25,
    0x7B
};

const TwistDomainSaltSet TwistExpander_Capella::kPhaseBSalts = {
    {
        {
            0x45BB9399CBE5B818ULL, 0xEDF8927FD2AC66D6ULL, 0xE428DFCE912C2BF6ULL, 0xC9C4035C717378AEULL, 
            0xAF5D4B82EF7B6F1BULL, 0xA3386C5E451A60ECULL, 0x4A47D814906DBA2CULL, 0x7C5616EE2E6BC553ULL, 
            0x01D1414E1A207BC3ULL, 0x45A363442FF233C6ULL, 0x688F0C18DF0E388EULL, 0xF933190D87733C3BULL, 
            0x433FEAE4BE017455ULL, 0xF9B4ED006B8C77F6ULL, 0x6F2F036837A4757EULL, 0xCDA839BC9CD949F0ULL, 
            0xFC6642006B430DADULL, 0x9968F25F1586E3B4ULL, 0x21377CC2917E7241ULL, 0x62D293A475A75412ULL, 
            0xB5DCCB1B5438245FULL, 0xD96E75B5A0ABA36FULL, 0x69A12751CA0BBEB5ULL, 0x47226632A197A5BEULL, 
            0x1495CF970A7EDBB5ULL, 0xA100A6ECF1ACF10FULL, 0xBE24BF4201671EF2ULL, 0x28184752D9418A54ULL, 
            0x75895C5600400C1DULL, 0x9A824A9EE20331F1ULL, 0xD704131DCE0F28A0ULL, 0xC54AAFFCDCB871B1ULL
        },
        {
            0x7CC54BCCA462D6B8ULL, 0xB2F85E1EA949D305ULL, 0x0A07184B533D4BE9ULL, 0x18824E80630D13C0ULL, 
            0x9B829D08CFDF7884ULL, 0x71A33B6198E211BBULL, 0x9E412ADF27046CEEULL, 0x2766A8A0ED38922EULL, 
            0x811A2560B3B6E8E3ULL, 0x8E2369B8A0882703ULL, 0x30F43D70A65CCE0FULL, 0x4F0A9FD09C36ED85ULL, 
            0xF3D7C656889CCC4FULL, 0x0C24188D8FCD4A54ULL, 0x0AB1EFE8E4777962ULL, 0xF4E8B9B7AF318D34ULL, 
            0xD71E4E840A2276DFULL, 0x038199AF6BCD93A4ULL, 0xA8FE2183F3CF7DAEULL, 0x7D3B14DD10939BAEULL, 
            0xEC5DB0467E1555C0ULL, 0x11BF4A7125F5D714ULL, 0xBB936CFDEC0E3669ULL, 0x2DC90A909147663CULL, 
            0x91D68145F665643FULL, 0x41D1C80D5F03B6AAULL, 0x274142BDBDF8A3B8ULL, 0x9EEC4AF23DCCBABEULL, 
            0x2F0AA81DADAB2B27ULL, 0x2D602F33C714D274ULL, 0xE05F5B48809A9B06ULL, 0xCB6C9923A9DE11BDULL
        },
        {
            0x82AEA946C428F714ULL, 0x31C6883D25CCD458ULL, 0x09F8BB86648BCDBEULL, 0x00784DBD85385316ULL, 
            0xE8FA12CBF88F4860ULL, 0x5F6388B404143C1BULL, 0xD5EF7DE34A4B2186ULL, 0xCD0452AA84C1F52FULL, 
            0x74D407531615E756ULL, 0x74A47DA1E87A790DULL, 0x0D51E6826A477466ULL, 0x9529D3888F9BCE40ULL, 
            0xCDB417E14081B394ULL, 0xB9EE6FCEEA5E6E35ULL, 0xC1A56EB635404F7EULL, 0xBD0823F018CFC189ULL, 
            0x8E27E4E3AA15EC1BULL, 0x47214853663D2655ULL, 0x3C55D119BB904D88ULL, 0x4D1F6DBD761EDC58ULL, 
            0x0CA59CBCD6DF1AC8ULL, 0xE8778B5240225C43ULL, 0x4FF1043ECE570BBCULL, 0x800D2307F2B29BFFULL, 
            0x86E440D0C047D41EULL, 0x755C945450EF5C09ULL, 0xE4F4415B0B40741CULL, 0xE41264C9D608D7BCULL, 
            0xCEF35CEA4CBC588CULL, 0xF09505C3E193CF50ULL, 0x637E77E9A7E6DAA7ULL, 0x5A57B7366220D6D7ULL
        },
        {
            0x81CD1F3B3DC1D2BCULL, 0xE4D1120E065317E9ULL, 0xD143D51BCDCD1CABULL, 0x01DE517C999E5C57ULL, 
            0xCC3D064F6C0831EFULL, 0x120D55D9DE300640ULL, 0x73BDCB94ABD2C367ULL, 0xE6FFC5F7358BD860ULL, 
            0xFA9C9BD72CEBA988ULL, 0x4884C4D41EA0FF44ULL, 0x22B4984E83F759BEULL, 0x05553A553B1C7A6AULL, 
            0xBB5BB460BE1CFAB1ULL, 0x9EFE60264DB59790ULL, 0xE34029B71BEC15ADULL, 0x47CBF974D9211DEEULL, 
            0x5C2FCCC82C6D6F01ULL, 0x8222AA0987C43B68ULL, 0x8A0EBDE6FB5B9698ULL, 0xE3B6C6457DE922AFULL, 
            0x4835424696B8D271ULL, 0x79CAA5ADBA054957ULL, 0x0E435D50103BB134ULL, 0xB9B59E8AFE1968CEULL, 
            0xF34DB14B212DCD00ULL, 0x8759A139D0EB4AB1ULL, 0xD1BA16D875A6C944ULL, 0x92461D9E6F2538F1ULL, 
            0x16A90EF0A6A70B51ULL, 0x7D4A9D6D5ECEC5C2ULL, 0x1639B2A9629C5A9BULL, 0xA0C22FB04F4C6B01ULL
        },
        {
            0xE3F6D93A9C0F3393ULL, 0x3F76FA53449D79F2ULL, 0x4A7B19FBD27AFFCEULL, 0x5DE297AEC0E777FDULL, 
            0x715316F3D5D77B1DULL, 0x7F7A6BCACC974494ULL, 0x62927136E2CFB38EULL, 0x3A9BFD1CCB0C71B0ULL, 
            0xED505384E93A3A46ULL, 0xAFBB7A6DFF946B4AULL, 0xC0DAAA7432E07D6FULL, 0x1BF466ED1E4F1F1EULL, 
            0x75B098B8FB1B8120ULL, 0xA0033CEAEDEB3EC4ULL, 0xAA4DB53E8597FDD2ULL, 0x13F3FD5885302E18ULL, 
            0xEA66602E98E0E28DULL, 0xC472639709EBB459ULL, 0xFC5FD2A609637E7EULL, 0xC2F3D58230A0BD89ULL, 
            0xFB30EE90DD2BBC43ULL, 0x543E88B5629E7211ULL, 0xA2B3E6E0E9DCE6B4ULL, 0x7E332E2AE06D83C4ULL, 
            0x91124781D8E728B5ULL, 0x1CBCD3616C53F1AAULL, 0xC5B1EB785F1DA18EULL, 0xB5851C16E29EEB0EULL, 
            0xDEB4880D25742AA2ULL, 0x5481E7B931740C59ULL, 0x99083A1210BABE8AULL, 0x96E554106B73B088ULL
        },
        {
            0x6DEF1D9BED6D9717ULL, 0x31A4F7569195A474ULL, 0x6B46B995CC467C8EULL, 0x683B5CB6E1EAA32AULL, 
            0x0A0CDE79D7E4F97FULL, 0xEE25E1143EC9EE3FULL, 0xD0AC3C3C1A9127CAULL, 0x98C9A01A98BB7687ULL, 
            0x194F7AF239A22E05ULL, 0xCE5E55B7EEF3E3AAULL, 0x21DC76BF55880F49ULL, 0x95ADE2EB0B551551ULL, 
            0xEC69E87747545033ULL, 0x895EB2E8C366B4AFULL, 0xC16610D35102D808ULL, 0x6251D3F779E9B28CULL, 
            0x29D2D8FA4402A799ULL, 0xBAF0DBEDE2A5117AULL, 0x1C22685B6546BBACULL, 0x55C0D6F537663DCCULL, 
            0x2D5C98235F267A30ULL, 0xD045774B345EE260ULL, 0x40D6583F7101C203ULL, 0xB242B7CB5C014B0BULL, 
            0x6BFA0F059DCB95F8ULL, 0x0C17881A591D0EE1ULL, 0x90B4338A42E59CB7ULL, 0x3A99F813255652B6ULL, 
            0xAABB8A741AC44C3DULL, 0x592E2002C3139D69ULL, 0xC7127C43C335B78EULL, 0x66792035BEF15161ULL
        }
    },
    {
        {
            0x1A76919058EEAC54ULL, 0x4C100A13499D89CDULL, 0x5172B8271E266509ULL, 0x551B07131A0BCEF5ULL, 
            0x553C67C883B3F964ULL, 0x5FC4275ED2AA9BE1ULL, 0xF136F002AABEBFC6ULL, 0xCDEC9321842C3232ULL, 
            0x0144A64323B29FD4ULL, 0xB0406919CC7E522FULL, 0x964F1E391CB3EEC4ULL, 0x0B5206D91429B6F7ULL, 
            0xE21FCB458500F622ULL, 0xA0FC8DA856F92C6FULL, 0xD944A3C9B1B92A7BULL, 0x3C47B9A2435E2BA5ULL, 
            0xC9924A4DC466F930ULL, 0xCDD227CE67626064ULL, 0x232540413362527AULL, 0x449BBD8AF5BB59BEULL, 
            0xBBB51492DB0CFDD0ULL, 0x9C6B1BDB6A2065A3ULL, 0x5F20F36E2D8BF2A2ULL, 0x88839840CEB158A1ULL, 
            0x93DF3A5D09459158ULL, 0xD0B210F062FC0D4BULL, 0x6EF45A51334CE205ULL, 0x615E631798D8B55CULL, 
            0x3D2164F7DA41DAFCULL, 0xF4CE21C995246DD2ULL, 0x266709C8BCBE9190ULL, 0x4D93F7A5A4053DE5ULL
        },
        {
            0xABB212A9810AFB89ULL, 0xDD0E0363927E0361ULL, 0x69EC940CE7E53E4FULL, 0xA9D9BEB7C4132CA5ULL, 
            0xB1C4DA620D9FEDDDULL, 0xF8CE79CF1DC036FAULL, 0x507F4A61C6B322FBULL, 0xE6E1BCCD2352C303ULL, 
            0xE6B47C4BA17C7C21ULL, 0xD61BC7EE2D743833ULL, 0xFBBF692888C55EA6ULL, 0x8E944230F299FE47ULL, 
            0xEDD835F7DD7249C5ULL, 0x4CBC89446524A23AULL, 0x7C75435C21963F72ULL, 0x6E21CC9641152EE6ULL, 
            0x9FA8D5F9F3F50880ULL, 0x9F08839DA35BF6A2ULL, 0xB6E9AD0F96B12460ULL, 0xF84D9D1B616924FFULL, 
            0x5A3FAEECBE84E84DULL, 0xE610E2DEB0044193ULL, 0x6DBEE2F830DD0884ULL, 0xEE4665116A0A2F74ULL, 
            0xA6A906424AB1C405ULL, 0x6AE066C4CCE38EE1ULL, 0x9A8C27F1577952CFULL, 0x649C65131EDDDFE9ULL, 
            0x327339433945B8F0ULL, 0x0759C327B258C920ULL, 0xF15837E7884C433DULL, 0x51BFC6A3C556AF76ULL
        },
        {
            0x21A0A754EB0A8CD0ULL, 0x17D0244B37191144ULL, 0x059C6CEB0DFDF8F0ULL, 0x1FAFD7433A11B740ULL, 
            0xFC4F562B9011BBBBULL, 0x54E72A296DB96C70ULL, 0xE27A89C3566F9676ULL, 0xB475D1333FC81718ULL, 
            0x08D941D409AC3626ULL, 0x5C2D3796424E8665ULL, 0x7FAC8A3BD063AFA0ULL, 0xE20D6DDDC20B0313ULL, 
            0x6F87793AB51B62BEULL, 0x009894AE8D2127FEULL, 0xBF34C9896450C2E8ULL, 0x9D2BACAE6C2978CCULL, 
            0x89D908897C31DB88ULL, 0x925594D7BF1B71D4ULL, 0xF789F0B59FA9C24EULL, 0xCA3557959B27F5F1ULL, 
            0xD30A87867FC43857ULL, 0xC195FE594FECCB3CULL, 0x90C0327EA397C0B8ULL, 0xBE7500DBDDC2E91CULL, 
            0x30A91976B9485BE2ULL, 0xD76131388EE92D0EULL, 0x3064C4F63ACA5E3FULL, 0x1CD5A331F6564E4CULL, 
            0xD5919CE4D55DDF75ULL, 0xFF6356C3095BC5F5ULL, 0xDE47A07C58768CB4ULL, 0x03F528F0FB350DE9ULL
        },
        {
            0x4B899E672BB31AF6ULL, 0x1AF149165058E22FULL, 0x423514167BAC109DULL, 0x8A65C19A15757979ULL, 
            0x912AFCAD7C210980ULL, 0x248E828825A501BFULL, 0xFC9E44959B156A5FULL, 0x7D2D08D7809AF7BCULL, 
            0x32684EF2EBE12CB7ULL, 0x3D6BF80FDC70A1CBULL, 0xBDDB0796ADCF9B08ULL, 0xB245C3C075C29948ULL, 
            0x44618601F2374DA8ULL, 0x34972521CDC0F707ULL, 0xC9CEF9158948262AULL, 0xC908076538BC3263ULL, 
            0xA04814C3FF8DE828ULL, 0x026EAB009DFFF388ULL, 0x68DE748D182FFE4AULL, 0x9F2D75847C5D18CFULL, 
            0xDD63E9807213EEBFULL, 0x4AABAEC027037A53ULL, 0x5C825492698EF52CULL, 0xCEB0EE13B5CA8E56ULL, 
            0x9723A64D11A8FD9CULL, 0xA374A0BB76BB4DCFULL, 0x46FF312FB1FA9890ULL, 0x90F6B6270405BAD4ULL, 
            0xEDDEED743CC9A66CULL, 0xDB072D1A5555FB7DULL, 0x0D06314A28F07789ULL, 0xBDF870080BE49F4BULL
        },
        {
            0x3186856E848E3BA2ULL, 0x6A552B77BA37E93FULL, 0x33F952AE6C35725FULL, 0x84DE4CF4B2716036ULL, 
            0x0789D5607811AF46ULL, 0x422D005C3429CA1FULL, 0xCF53C1BD6E4EDFC6ULL, 0xCB55445583D84D4CULL, 
            0xE16B2F91899D62E6ULL, 0xC5DD44FF5F0E02EAULL, 0xE5DE4E32DB79F8FEULL, 0xD40BC1617185CC8BULL, 
            0x21D3719A859957FCULL, 0x9421B8678690089DULL, 0xCA0B47384A2235C2ULL, 0x461FB1FDFC3E9507ULL, 
            0xCA7C88FFFD032F88ULL, 0x2A82C917263F95A5ULL, 0xF5D2D45850791CF9ULL, 0x5F9104A2262B2DCFULL, 
            0x926CEFC04C264BD4ULL, 0x8C90F6F9D5281304ULL, 0xC1D1157912DF2A02ULL, 0x798DB348A57DC902ULL, 
            0xA69AE6F8FBBB3D18ULL, 0x27B5E606D6D3C70CULL, 0xEB9C66083FC2F2EFULL, 0x75907BD581ABD7C2ULL, 
            0xEE804E5B93DE9BCEULL, 0x4F0C2FC61E09A42FULL, 0xA0ABA9D6629A0F2AULL, 0x918B9281DA769F5EULL
        },
        {
            0xB5B88F5BCD73FF90ULL, 0xD13529D07F110072ULL, 0xE6C6B1E55FB32D78ULL, 0x67A0D11F42F23D79ULL, 
            0x6DBF076B6701752EULL, 0xE137CBE879BFECC0ULL, 0x240679DB723B41E7ULL, 0x73F24168409F54F4ULL, 
            0x08D7667F36B3FB1FULL, 0xD93223B9F71BA811ULL, 0x220CA2BF61661549ULL, 0x1947D9A21C8DDF3AULL, 
            0x1E858973D579136DULL, 0xA106E40DD1A25716ULL, 0x2D72F0E58417F078ULL, 0xC9709871F1D79B9BULL, 
            0x0EE9091EC33B934FULL, 0x454A905F83C1EBABULL, 0x973A2D5376CEEA34ULL, 0x8030BFA3102E3FD7ULL, 
            0xDDED477255CCC83AULL, 0x37B2C871A20B9C2EULL, 0x6048CB135F08C79DULL, 0xB8BC94C2C59ED7BEULL, 
            0xE9CB2AA44A365D50ULL, 0x2CACC865326A7DD1ULL, 0x92770BFBCC03A71FULL, 0x28F6A7FF71140BA9ULL, 
            0xECE4D24ACDFCF859ULL, 0x5A91867D65244B3BULL, 0x458D1C950D73ADABULL, 0xAB0A89EC55E629CDULL
        }
    },
    {
        {
            0x683D5CC574AC208EULL, 0xD9E21179A1D5BD8BULL, 0x53A57D4DAA840609ULL, 0x38614F39B5DB103DULL, 
            0x7A650268A62172EEULL, 0xB4C45786B0AD1729ULL, 0xDCB72C0EB9C36ABAULL, 0x677497DBF8E12F3EULL, 
            0x2A9394B3485C1C5CULL, 0xE58AF40211E5CFF7ULL, 0x17E3E59A7583B960ULL, 0xAE6E93389BDB40CAULL, 
            0x3B3BDEF2BF56512BULL, 0xE94A59BB04664BDBULL, 0x23DF093E53EE70F3ULL, 0x00EEE0AB35648383ULL, 
            0x3F28CCED27A6AC64ULL, 0x0D0CB961EC2FCD3AULL, 0xADB7EEACCD6A57D6ULL, 0xE081F2BE812294A5ULL, 
            0x0999AF6DAD2A2ABAULL, 0x3B57848D658C562CULL, 0x181A849D5B3271DAULL, 0xA2C58EA5C7BD8462ULL, 
            0x011AC6119FEC93A1ULL, 0x0D36FAB12B2A6577ULL, 0x9077407225A80DD5ULL, 0x7456DD30714BE93CULL, 
            0x989737EE7A0E193DULL, 0xFEC3BEEA3785DB70ULL, 0xF57F463B7A008AFDULL, 0x4B726E366AAC7802ULL
        },
        {
            0x116FF225E8F60BF1ULL, 0x6224832044AADBE6ULL, 0x3EBACE221CF95B87ULL, 0x287A1F6A6FF74E14ULL, 
            0xFDD18EA67ADE9513ULL, 0x91E68EF8A96DFAC4ULL, 0xC539EA651BB78D4BULL, 0x584E0085AA545186ULL, 
            0xB4A1D2B6E6022484ULL, 0xD447E4A2C964605EULL, 0x7E0B76A16A93BD97ULL, 0xBBD8DC1C34A569A5ULL, 
            0xDBEB473617C1AB99ULL, 0xC8F4329F5A34BB8EULL, 0x3EFCDCFE8F94E712ULL, 0xB4EE375921BB19E7ULL, 
            0x3CFB5CFA1875A79CULL, 0xEBD63FA6514AA673ULL, 0x0E89F4BF36CE2955ULL, 0x891BFECB6DBF3428ULL, 
            0x701ACA7B20B32095ULL, 0xF2DBD82FA00CAE04ULL, 0xD2E4CBF5209CB86CULL, 0xC4D42D2077627D9CULL, 
            0x215178BA29BEBD54ULL, 0xC52E68C5F253A532ULL, 0xB716E563F623E263ULL, 0x0F450E5D0AC77CC6ULL, 
            0xA7F57C40DF994A4DULL, 0x2835C41D98DF8C9FULL, 0xD83C284ED2C2FBCAULL, 0x071F816FBC0616D0ULL
        },
        {
            0x699E5ADC9AB3C677ULL, 0xFC6E936D2071EF21ULL, 0x117FAD5CFB598975ULL, 0xFF0938B103CCFFDCULL, 
            0x1D518972EE57F48FULL, 0x2B1CCBEF927AF7A8ULL, 0x2CA6169A91B4939DULL, 0x335945AAB401B8E9ULL, 
            0x5B710CF987CB57B7ULL, 0x4A4E37A0EE4F3500ULL, 0xC5B1D41B96AA9769ULL, 0xEF38645A243A128FULL, 
            0xF12B1572B97C09A5ULL, 0x4735E7F8462E6757ULL, 0xC7E56292C4A1C84CULL, 0x5B478E529D2196DDULL, 
            0xAA804966B362DB52ULL, 0x3A0327D3B9853993ULL, 0x11FA96813833BCC5ULL, 0x7AFE7D553DF9D34BULL, 
            0x6DDACCB703C5DD87ULL, 0x67D64FFB7DB8210CULL, 0xD77D7E3537797C59ULL, 0x8694C43F50641EF5ULL, 
            0xAA9CF27D40CD29DAULL, 0xF77DD44E1298F3FBULL, 0x79FE07CE71EA4CABULL, 0xC08E08F34888106DULL, 
            0x86B8396D0C845DC1ULL, 0x5E6F411224C8D82CULL, 0xA8BB158C13B1F41CULL, 0xDF1CA0389D7B17A8ULL
        },
        {
            0x496794671E6AE4AFULL, 0x88425CDA4EFB89EDULL, 0x75897D4466CA00DCULL, 0xC0C0B03E92077E04ULL, 
            0xF987BBEB7AACD7B5ULL, 0xE4E60625A3C97050ULL, 0x75393C7CDDBE50DFULL, 0xA25301802449466BULL, 
            0x8F408A4775670BA8ULL, 0x160CFCA4BAD84156ULL, 0xEDFE73C83B5B98DFULL, 0xA816D42371FB2A75ULL, 
            0xC79B68A761898DD4ULL, 0xD7430BDF21E5C4D9ULL, 0x0E76826CCCB4A672ULL, 0xC6D5BCC239183CC2ULL, 
            0x5953925461339EBAULL, 0xDC7B9E2DB9994B9DULL, 0x9384D85412F734CCULL, 0x24888A731C16CCDEULL, 
            0x8674CCE291B1A379ULL, 0xF28A47FCCFB95556ULL, 0x1E0B5D82EF3E66E0ULL, 0xB09057268C657A36ULL, 
            0xBBA3755FEC52D2EAULL, 0x62491F10475E6C71ULL, 0x652814E3E4EC4A78ULL, 0xBDF0D74478C345EDULL, 
            0x65A5D51427764F9CULL, 0x3A5F8E117D9A772DULL, 0x5CF185B798894D7DULL, 0x1648463FE37A8EBFULL
        },
        {
            0x4ABDA7676ABD030FULL, 0x3727C858D7C10524ULL, 0x9D51109B49CD4324ULL, 0x8B23726952E4169CULL, 
            0x162EB1405D4177D9ULL, 0x72179D4D991FBC1CULL, 0x4295F63351E5DB2FULL, 0x36F8486A2591874DULL, 
            0x85BF4C17B1FD12A2ULL, 0x39A5926348F468CBULL, 0xEED16E2F15142B18ULL, 0x8433ABB9B3AA034DULL, 
            0x23C9119867F6B0B7ULL, 0x812EE12CD5AB4704ULL, 0xE66EA20AF069025CULL, 0x929E3DFBE20BBAD5ULL, 
            0x37486B53DE17E5D9ULL, 0x1887C7F6F0B7C114ULL, 0x15B2BAD85FD8F965ULL, 0xE62484AAD114E2D8ULL, 
            0xDA79B3416B649418ULL, 0x36F25986B1FE95C1ULL, 0x4D32DF97F987E09FULL, 0xE99B40F2EA1CBAA7ULL, 
            0xAC3AA5772BDF5A10ULL, 0x75D5C11042FC82A7ULL, 0x34FA3FAB760FF08FULL, 0xD1D394793A81AD43ULL, 
            0x083F4BFE0B28C16BULL, 0xB84A8D571DA2CD89ULL, 0xE6F6C794F099ADFDULL, 0xF1513BB4E7E243B7ULL
        },
        {
            0xC10628858B8E7DEFULL, 0x214357D4C6C73523ULL, 0x862BD6F895CB20BBULL, 0x52CE22B3D14C96CEULL, 
            0x014660B087986C59ULL, 0x4E4C530C0B819A3EULL, 0x24383540EAEEC62EULL, 0x8F034A2408940B73ULL, 
            0x7170205657747714ULL, 0x0FEBFD33AC449EB8ULL, 0x8C252C1570687991ULL, 0xE6027DE2B317E996ULL, 
            0xFD343C773CA384C6ULL, 0x1D5E59AF32C40605ULL, 0x6C3EA2715C2D190DULL, 0xFD52CCBF4FCED8D3ULL, 
            0x24EBF445CED0500BULL, 0xEE184D6F384D85E7ULL, 0xAA25E8E23158C165ULL, 0x8D491214B3286207ULL, 
            0x5CAF4A39D93D2BBAULL, 0x77B7916CB5E6E02CULL, 0x40A4F0610690C980ULL, 0x266B86CF6F95C748ULL, 
            0xCD15A07ABA1D9193ULL, 0x59196B9C655BBA2DULL, 0x61238DDF6C435879ULL, 0x5ECA03657E6D3F9FULL, 
            0xC8C5B9F46BFF1627ULL, 0xBAC5B2733D87A48AULL, 0x7FB03E606F574892ULL, 0xE8ADAC54EBC9ACCFULL
        }
    }
};

const TwistDomainConstants TwistExpander_Capella::kPhaseBConstants = {
    0xD126C7CCF6B77259ULL,
    0x4FDD8E95BE834C29ULL,
    0x0F46C6A3195CE7FBULL,
    0xD126C7CCF6B77259ULL,
    0x4FDD8E95BE834C29ULL,
    0x0F46C6A3195CE7FBULL,
    0x94718B89D3322B46ULL,
    0x61DE8C3831FADC29ULL,
    0xF0,
    0xB9,
    0x73,
    0x07,
    0x12,
    0x32,
    0x78,
    0xA8
};

const TwistDomainSaltSet TwistExpander_Capella::kPhaseCSalts = {
    {
        {
            0xEBCFEE85E2D2EBCEULL, 0x55C291C9A1441D40ULL, 0x0C455B332E9B8371ULL, 0x12DA0E5408131C4BULL, 
            0x011BA5ABC7425869ULL, 0xF10F26AB8F7A1A76ULL, 0x24FCB45DD222187BULL, 0xFA8122D7AE20091FULL, 
            0x537E96974F7CE159ULL, 0x19AD221970692080ULL, 0xAE0D7B95074E5CDAULL, 0x4597A8920225F188ULL, 
            0x9D21678C302F2598ULL, 0x4E7E0ED472B7FA76ULL, 0x1CBB204B4E26EDA2ULL, 0x771A569C22F5B44EULL, 
            0x2880DBCC0D0F0CBEULL, 0x7D0D22D1EC90A549ULL, 0x9B4C6FF896FD7951ULL, 0xBEFF7640F87D4632ULL, 
            0xDCF1BBE211198662ULL, 0x4CB65321FD05423CULL, 0x4764B94AE625FBA1ULL, 0xD53D98E278558711ULL, 
            0x703FAC2802352DA6ULL, 0x19AE5E5531205F1CULL, 0x66F9D2882D427B91ULL, 0x820371EAB75B0547ULL, 
            0x8A01ACB867BFDA44ULL, 0xAE0F31795918F0D5ULL, 0x8081F678B784A552ULL, 0xA7A4FE06D8D85D6CULL
        },
        {
            0xBCED19AE9DE0F68FULL, 0x4E84EAB367C2A534ULL, 0xB91F71917D9A898CULL, 0x8C51B83777EFD094ULL, 
            0x0839902DFF0D05ECULL, 0x7DAA0A093542D3BBULL, 0xD6A2994B84510579ULL, 0x9E76DBAB86571214ULL, 
            0xBAA29DF5E215149FULL, 0x4160399E2297FBFEULL, 0xE32A9B8355E60628ULL, 0x5D933604C1EE2B72ULL, 
            0x1613217F41D98210ULL, 0xD86052C0F75CDAABULL, 0xD59532D2B81DC4A4ULL, 0x4F841A35B9920F7AULL, 
            0x68FB059F8D56F1AFULL, 0xC4DFAA28631BB944ULL, 0x5E6C062642C89E42ULL, 0xD46E144737F122BCULL, 
            0x06192E9AE1B6175BULL, 0xB2A180FE630D5DFFULL, 0x933FEC3F3CFE6EE2ULL, 0x0A92DA5284747649ULL, 
            0xD36B6143DCEBA8EEULL, 0xF70665528D095360ULL, 0xF29652DF1812A311ULL, 0x09B27F9275F0AAE1ULL, 
            0x144B635213299B68ULL, 0x847BCE99FE85836AULL, 0x0B3E2F89D9C99A97ULL, 0x74F8785E4547FA77ULL
        },
        {
            0x4EB3D605A7E70B0AULL, 0xBAD776463FF6195BULL, 0x14309E7C77BD21F4ULL, 0xA0887FED333819F1ULL, 
            0x09CCBDB967790D2BULL, 0x40ED0DDB56D96989ULL, 0x93A1A8AB98CA1CD4ULL, 0x8F2C48AACC8E5122ULL, 
            0x14604B89CE9EA3E0ULL, 0x019B7D94407AAD65ULL, 0x72A3C652C8D734B0ULL, 0x3CE2F42C33CED3F3ULL, 
            0xC6A7D6C22B5C061AULL, 0xDCB42A26A1C59537ULL, 0x0F75801C11179076ULL, 0xFA7E12D5530F2D87ULL, 
            0x248363448D0772CCULL, 0x8D2743D7A73D8974ULL, 0x893EBD30271C0FC5ULL, 0xB21B52A6A509F56AULL, 
            0x7849CD277394B317ULL, 0x09077B0AEFE0FE00ULL, 0x59A6E405B605F1F5ULL, 0x3273A746770C506EULL, 
            0xBB03AD53BE6F78B9ULL, 0x6BBB8187B7E6435FULL, 0x5B6E82506480DD3AULL, 0x3E951FCFE31290F9ULL, 
            0x3997DFA9C629B292ULL, 0x14BB5294DD983495ULL, 0xE149A05920CF14AAULL, 0x79594BDF6B78C513ULL
        },
        {
            0xA80ECC0BB4D50FD8ULL, 0x33724E2FF30C9E81ULL, 0xD4EB27566E2B4A8CULL, 0xCF9155EB85D67105ULL, 
            0xD9EE6719F67E1810ULL, 0x732ED298CF1B8C96ULL, 0xC515722FE0B26EC4ULL, 0xB39311224EE2B1A0ULL, 
            0xF879B691FFA4E25AULL, 0x00096D1BA5896869ULL, 0xE1095322B78BB23FULL, 0xA688DA7197D30014ULL, 
            0x5456E0D95DC85691ULL, 0x2DB102643F1DD7B3ULL, 0x5E14237D2D9393BBULL, 0x7ADDF65C9095DEA1ULL, 
            0x1937D0AACA08B823ULL, 0x2B235E7CD62524A7ULL, 0x84278A2A17AD93F0ULL, 0x1D5AE403665CEC74ULL, 
            0xBAE1FC70A47814BAULL, 0x07E1EF18825EB52CULL, 0xE624DE8332BFE6ADULL, 0xC4EFCBAEADB1ADD6ULL, 
            0xCCD9E50A5D4F173AULL, 0x212B068A5E914DCDULL, 0x72ECC6C933DE63B1ULL, 0x68D68738C0D214E9ULL, 
            0x835B400D1457887BULL, 0xEC6E92316C07B703ULL, 0xC917FD20B3A6646FULL, 0x87B27B2052CC6252ULL
        },
        {
            0x529932BFC91CF95FULL, 0x4089EAA9E054C943ULL, 0xD64967AF8042C688ULL, 0x869B766DA88943CDULL, 
            0x0838169375695624ULL, 0xCF4B4A8E004CB6E1ULL, 0xB53A27E6695C3BB2ULL, 0x3B7E8615593D7E13ULL, 
            0xC4C02506A3640C2CULL, 0x8F64E1B263FE7965ULL, 0x5A583B04B3AB3EF8ULL, 0xD9BFB89AC597C107ULL, 
            0x56A9CB559BF3DCF9ULL, 0x20555B85809870ECULL, 0x4665B23893E58409ULL, 0xB3A2130BC695472FULL, 
            0xC95C96F78AE1127AULL, 0x19061A860A016496ULL, 0xD611E92BED1CFA5BULL, 0x8075098BBD0C2822ULL, 
            0xFB7C4AFA00271E11ULL, 0xBB94B02123CA7DF4ULL, 0xAA5E794F1761BF7FULL, 0x39C321386A675539ULL, 
            0x42089374303D3C82ULL, 0x5DCEA11F25DF1C64ULL, 0xD492432CAE6DB95CULL, 0xA24DF72112B44C6DULL, 
            0xA9F2D00174C84DA4ULL, 0x2422284834102FBFULL, 0xA167720E48C76535ULL, 0x27E98AB7835D30E8ULL
        },
        {
            0x6570AD9E59DF6A4BULL, 0xEF1CDDBFF97D5C30ULL, 0x21111CFAAF1B4D30ULL, 0x853F6AC2E8FB153AULL, 
            0x304A56DAED22FD77ULL, 0x580A3491AA011999ULL, 0x0170C3A0A3CE8DACULL, 0x9224D078CC2F6A0AULL, 
            0xBCBA602387BC0764ULL, 0x9D51AB66FE1BC29FULL, 0x4FEC1FBC32232C4AULL, 0xDE56B69A78E18C0DULL, 
            0x53D5707CDFED5E58ULL, 0x80D341358B1DFDEBULL, 0x238074BE3EC6559FULL, 0xE46537495BADF895ULL, 
            0x15ED42FCFBA6F6D0ULL, 0x50BE6D3D437AB4ABULL, 0xB29558F0E447E078ULL, 0x1EF03955C95B1DF4ULL, 
            0xFB95E4DD6376ADBAULL, 0xFC52BD52E947E364ULL, 0x0BAC8547BA2A621AULL, 0xBB825D6E7D7EE72CULL, 
            0x7A4A2CC0A691A517ULL, 0xB5418AC27C426F94ULL, 0x443551E2BA34FD53ULL, 0x4B71D5FC588D981AULL, 
            0x836FD94043EF25FAULL, 0x03B8789FAE1DD3A5ULL, 0x4D1424A2958E6768ULL, 0x3838E0FA71733201ULL
        }
    },
    {
        {
            0xB045A752DC8CE98CULL, 0x4501331BC5D3436EULL, 0x9F54BC7B520211BFULL, 0x70CB645D0B212672ULL, 
            0x55466940074470E9ULL, 0xCD3E070A91E1CC57ULL, 0x7A2B359F09F9527CULL, 0x377483B926C057C6ULL, 
            0xDFC121E3CFA70730ULL, 0x9675DAF695DCE38BULL, 0x9E6B40825881455FULL, 0xD4380DDE67EE74ECULL, 
            0x9C52BABDFA234BFCULL, 0xADD4EFBE444367F8ULL, 0xA26F29713FDC627DULL, 0xFF8A112DE813F5C6ULL, 
            0x46FF92915E606893ULL, 0x8C4135125902BB1DULL, 0xB522DC9EB6011DBAULL, 0xD093508553927E0DULL, 
            0xC471AA80F31CF482ULL, 0x4AAE98631F77E718ULL, 0x3910B8DF9CC202E6ULL, 0xA0EFD28C76D231B7ULL, 
            0x1E39131CCD2D9D2EULL, 0x842BB29CC5C10B1AULL, 0x4130FFC334D3721FULL, 0x47DD0E99344073B9ULL, 
            0xBE85CE63AEFC0B35ULL, 0x35A8CA37B78C715CULL, 0x897AEDA94D10D996ULL, 0x41B356244F304A79ULL
        },
        {
            0xE9D9CA4E546F1EE8ULL, 0x437C6B16A4A78EEDULL, 0xA47413287F47E382ULL, 0xB0BBC84048AE8C07ULL, 
            0x3969FFA79DE5FE3AULL, 0x26044E8472311B48ULL, 0xFDF9F608D446E53DULL, 0x4E97576572A134AAULL, 
            0x7454381DD2EA589BULL, 0x9645327D05FC7530ULL, 0x423AC475979CF9C2ULL, 0xCF5685BCEEF5BDE0ULL, 
            0xF297CAFA6BC25AF2ULL, 0xD5EA2C67532E3820ULL, 0x838CAFA1668DDD5BULL, 0x747472ABAC89F197ULL, 
            0xC8BD93129933A838ULL, 0x70E80F582094BEDFULL, 0xEC1CFE7012477842ULL, 0x7A0157E66A56D5D5ULL, 
            0x92DA26439900261EULL, 0x70F32D9809F39018ULL, 0x83E44D38B37B7583ULL, 0x2123DA98CE582052ULL, 
            0x028195C41344F358ULL, 0xA93CB80AF8694473ULL, 0xA57AAA94FF4D1A39ULL, 0xE573DD6EB338E736ULL, 
            0x31DF00AA0A9A11C8ULL, 0x68F925FB3A224F3CULL, 0x659D0C2BA35CA2D9ULL, 0xCF06FD887D582176ULL
        },
        {
            0x20871D6D2A53E368ULL, 0xDAEB499B89C7F7DCULL, 0xB192F9C1CE84FC53ULL, 0x174E7425BAD49AB7ULL, 
            0xB2EDC40D0A416EE5ULL, 0x4ED5E36B88C72030ULL, 0xF5174F88ED58F954ULL, 0xD4505FDFBAE6711EULL, 
            0x4C0A4407C814AC30ULL, 0x860AC37D2E8CDFDDULL, 0x8C5FC22B2B001882ULL, 0x4F46AC483D1F623FULL, 
            0x10838F293E15BD0BULL, 0x2F125229D82626C3ULL, 0xCBD15EA64D521166ULL, 0xF55414CC7B69C46CULL, 
            0x92AC7673A4DD512DULL, 0x8254D36F459D284AULL, 0x0FB2DE1250BF6DF3ULL, 0x30DE61B41561D0F2ULL, 
            0x4CE03304C4991988ULL, 0xB79421145EF17E41ULL, 0x77120BE3D8159D8EULL, 0x48D872C03FD61E91ULL, 
            0xD95C546A0D509EA8ULL, 0xEF6F6CD4B5F5EE36ULL, 0x82EC65FCEADB8DEBULL, 0x0C501C13DB7E0FDDULL, 
            0x45F72163ED87BE25ULL, 0x10CEDE43669C69D9ULL, 0x0E1057AD81C03FB0ULL, 0x3DC7F89BCC983A5DULL
        },
        {
            0xC404A3B47CB3C1C2ULL, 0xBEAAD53A0366308FULL, 0xA65D463472C84BF4ULL, 0x465E416CAB2474F6ULL, 
            0x53013AE1EACA46B9ULL, 0xE6B027F1E6FB97D1ULL, 0xF195C9E659C3AE12ULL, 0xAB6D3EA6BA4C974AULL, 
            0xE0F5C5B57673EA3DULL, 0xCE8C0993BBD851B1ULL, 0xE5BDB18BB5AA2104ULL, 0x8CAFF9B246CF0C96ULL, 
            0x1657AFBB8E95BBF5ULL, 0x03957A7E8093DF3AULL, 0x17CF804AABDF876CULL, 0xC72915C7B3173498ULL, 
            0x60E135C2E94F4684ULL, 0x1DE66DECF636EA98ULL, 0x17ED20BDE787E693ULL, 0x7420BB827346F77CULL, 
            0x448EEC8BB4651F54ULL, 0x3CBCE668DECB1900ULL, 0x7A03AF947BB5A74DULL, 0xEFA2ACC0E257DE24ULL, 
            0x4CDE62CE7D64D3EDULL, 0x9F3647A1500CD832ULL, 0xF4A986D1168AECEFULL, 0xE171BC05202155EAULL, 
            0x8CA0B4CD55E8A098ULL, 0xEA2021D81C72DC84ULL, 0x33563E5BB270712CULL, 0x1F25B747D5B72563ULL
        },
        {
            0x0DD5718E6DF502E4ULL, 0x03A9A28CF10F8C7AULL, 0xFE213D26D2984B6DULL, 0xBCB586AE19F84384ULL, 
            0x403B3D7AE0152B96ULL, 0x4BA1E4FB82FB910DULL, 0xC7B083347A8E31A1ULL, 0x6B6D94E32C49E67FULL, 
            0x107E335D435C1851ULL, 0x118202FBD5D28C00ULL, 0x00D58044D13493D0ULL, 0x3777BB13A7B2828FULL, 
            0xC2313537506D47A3ULL, 0xF1D043CCB9E2343FULL, 0xBE3720E0DFCCEAC5ULL, 0x33CFF900570EF2DFULL, 
            0x1190CB350D48ED17ULL, 0x767A006FB647CE2FULL, 0xE2F718A723DACED3ULL, 0x25A13D52F4B336FBULL, 
            0x3A45727723B2DA01ULL, 0x2F99707A7315AC9BULL, 0x5F28750F343C4C01ULL, 0xFD50BF37044715D1ULL, 
            0x74C27D9B2E7FB880ULL, 0xC39ED27F86F8E65AULL, 0x723917A46B3074A4ULL, 0x5B7EDB1189547CC6ULL, 
            0x57C78E7C0A1E4263ULL, 0xE36B562675215DACULL, 0xAD3499B01F7C2603ULL, 0xED1F21DBDCC83B1DULL
        },
        {
            0x7A49568AD0C36277ULL, 0xFCAE5082A9FEDE8EULL, 0x60EF16F3C8C9F47BULL, 0xD3E2A7142D9EAEDDULL, 
            0x0B88C0D7DC381299ULL, 0x76CB310C22566618ULL, 0xE4F3EE95F4D8E405ULL, 0x0AE06F13E59A94B4ULL, 
            0x5F587DAC87985833ULL, 0x3D3ACE6983336197ULL, 0x501AB0C937F75FADULL, 0x0AEDAE17FC3457D9ULL, 
            0xE8606BF1DF559E74ULL, 0x543A8F7DD5165ED9ULL, 0x60C1D8BC5DB3AC6BULL, 0x4C8114CF05A1E795ULL, 
            0xB7F921DB19BD920DULL, 0xEE08751328A4DA11ULL, 0x21D426AEF2330507ULL, 0xC47104AE3CD33548ULL, 
            0x4CBE73E604A8DB6EULL, 0xA3392F815BC02617ULL, 0x981F6DEAAB88E5DBULL, 0x7F595A8094B3667EULL, 
            0x80652F4489B04100ULL, 0xADF914EC8AE9FF17ULL, 0xDDEA7FA7F7878110ULL, 0xB65AF7AEC885C843ULL, 
            0x35BC1671EF9B56CBULL, 0x4B35E79C13A801CCULL, 0xC516C82F3604F065ULL, 0x00CA47884E13E298ULL
        }
    },
    {
        {
            0x99A6BE5BC0AB5AE5ULL, 0xE1D07D5C2D6D1421ULL, 0xE6D06BA989F2EC6AULL, 0xA89BF8E22BDC3A63ULL, 
            0xEBA53B145C002C8EULL, 0x4E49626090ED390AULL, 0x6E2DE99A72CF01E9ULL, 0xC2D3DEBF41D6B869ULL, 
            0xD4209C9488AB103AULL, 0x433AE9B3F6C14F7CULL, 0xD53CFD95D7F76F81ULL, 0xCFFC817850B3EF27ULL, 
            0xE77CB439A0020EF0ULL, 0x20DA80C6EFF39460ULL, 0x921C65A2DD513A76ULL, 0x9B9E8B307D74A034ULL, 
            0x15CF8C8C8D7C1946ULL, 0x54FC6CFF3AA9F996ULL, 0x9991F8719157B134ULL, 0xBE7E8FC4224F213DULL, 
            0x0742B051FB0DDE6CULL, 0x744ED554E344FB01ULL, 0x41E46E5AEC24B034ULL, 0x2AFA75E099C239FAULL, 
            0x8DCB8832360CE256ULL, 0xE70519F7254F3A5BULL, 0xFE00FA9CE25B2C81ULL, 0x29BF9263C549A179ULL, 
            0xB6D009F375A9D7E7ULL, 0x63198B8BCCD00816ULL, 0xA25928E7823C70F8ULL, 0x0602CB86F21B9C90ULL
        },
        {
            0xF6DF7C479D0358ABULL, 0x8361DF29B4C836ACULL, 0xF125D20F671540B5ULL, 0xFB12EC7899CEDB5AULL, 
            0x8DB41D80C35504E2ULL, 0x6F6FB2E248AEDEF9ULL, 0xF47DD98EEC11206FULL, 0xF2D27834BC5A95DBULL, 
            0x65641D946791C86FULL, 0x1AABED9EBAB0E2A9ULL, 0x3FF4421D98D8F3A8ULL, 0xD72402CF617EF7E5ULL, 
            0x19203CE9D9059338ULL, 0xCDA56648A66ABBEFULL, 0x527A7E1101D5678BULL, 0x6C449B7C93973F5CULL, 
            0xBFB9D1F39155AADAULL, 0xA2AC63ED34D207A4ULL, 0x98CEF0184133DACCULL, 0xBF48BA7CAD630E69ULL, 
            0x00D8EE7FF3697136ULL, 0xE8FAA0AB78215BAFULL, 0xC72F864F93E537FFULL, 0xE07036BE3F5C1FEFULL, 
            0xE9915A328C9D1980ULL, 0x1326D5EA42D8A215ULL, 0x7F126E3C38F397AAULL, 0x599269F696BCC56AULL, 
            0x688254522EAD58C4ULL, 0xAB36FB10588EFE67ULL, 0x0C7402F40F56DFBCULL, 0xDB427BF670D124B3ULL
        },
        {
            0xA8853ED77AF96609ULL, 0xF96D8C24D8C3D3A1ULL, 0x4F3B7307EEF9838AULL, 0x123D424D589404D2ULL, 
            0x768F0FB9209B4CEFULL, 0x078D9B08E84AA586ULL, 0x2AE1EF11CCE017D4ULL, 0xD8BAFA08CF22083CULL, 
            0xF2FE94E790233898ULL, 0x44EC72E34E75E7FFULL, 0xABAE6C38A4DB0495ULL, 0x3105856B6A0EDC56ULL, 
            0xD3CD811180FB638BULL, 0x38B78098ACE4D80FULL, 0xE0569DA3E99FC665ULL, 0x6792B713CB638409ULL, 
            0xC87E3A916E567F10ULL, 0x2B581254E6FAAAC6ULL, 0x77C5D6FA6DB1C058ULL, 0x0D5057097D4ADEB7ULL, 
            0x3AC95054BAD06054ULL, 0x0EDB7E574F80509CULL, 0x2CDFDAD5A40D69C6ULL, 0xB936B5FB18CE1103ULL, 
            0x2133F1DB0E7395B5ULL, 0x0BFC3E35A069D6B0ULL, 0xDFB1D723A1576B29ULL, 0x6646A7DE05F49075ULL, 
            0x7765730527BB52BCULL, 0x1F92182CF52F9515ULL, 0xE390B9EFDD617703ULL, 0x37AD427EAAB06B42ULL
        },
        {
            0x1ABC6F50CD0CA090ULL, 0x54B9777596442762ULL, 0xDE62135F0E635000ULL, 0xAE55101085C101E8ULL, 
            0x650947D477E400CFULL, 0x81B945A866F1E20CULL, 0x161BD9F5E6D7B0F8ULL, 0xAF7307FAB975EF10ULL, 
            0xAEFD910B32A6A520ULL, 0x06F214BC56AEC000ULL, 0xD3B41BBF8F6DC434ULL, 0xEC069F6F286B0609ULL, 
            0x1EFB88DE18FE89DEULL, 0xF3AFF51DE9F671AEULL, 0x7F386DC2EAB61BE8ULL, 0x62AEA6C2CED7DA59ULL, 
            0xBECF808F74064160ULL, 0x9A53B106E770BEEFULL, 0x250C9FB03CBFD4F8ULL, 0xC0AAC2975EEB381DULL, 
            0x4801564F0EBCFB26ULL, 0xE978B6C159177D88ULL, 0xFC9C9303E7A335B5ULL, 0xFEE2FA09708B3CD1ULL, 
            0x0263BE1C1C7F140CULL, 0x4E84CA2C3EF9073AULL, 0x3BCBD29C598E42D2ULL, 0x6E2D05CADAD69B27ULL, 
            0x447F0AFBD4D65FF8ULL, 0xEEB1EA8F4345C467ULL, 0x69DC41F70898EE7FULL, 0x8A5D273F66DC076CULL
        },
        {
            0xC5BBE3563D9D771CULL, 0xA40A85D5EABEE595ULL, 0x0658E7347B65BBB0ULL, 0xDD6049C06FF55210ULL, 
            0x93BAB5295C32E198ULL, 0x339A278E97FAFF3CULL, 0xA89986AB62498A71ULL, 0x3EA368A809C2F714ULL, 
            0xA3D5BCDA172F7696ULL, 0xF44D23D4C1C3C9AFULL, 0x7052E787330F382CULL, 0xD41F58054656BC9BULL, 
            0x12ABFBC0B336F21EULL, 0x9BBA632D4109D4D3ULL, 0xCA229DD943175F7CULL, 0xD194DD4C4AF279C8ULL, 
            0x2D4A17010133C113ULL, 0xD8F4A0E8D0F50DCEULL, 0x4F02D74B1B51CDA2ULL, 0xD3EB8D5D9442A3A6ULL, 
            0x118CA82B3D0FF786ULL, 0x9A6C237C2B4B6B56ULL, 0xB50EA47FBB83A1BBULL, 0x47467AEF4AD4D697ULL, 
            0x1F7EFE0DF3768481ULL, 0x30412E83F27729EFULL, 0xFC9679AF16EE73DCULL, 0xC0C437F6BEA0C1D7ULL, 
            0x284F125EC17CC3FEULL, 0xAE8AAABBA96170E3ULL, 0xB96F2F04FFB045B8ULL, 0x6921E7A38591A3BEULL
        },
        {
            0xD8EE955321C3757BULL, 0x71BC4720BD558EF3ULL, 0x4AC54722ED1191ADULL, 0xB783B9C0C09C51C4ULL, 
            0x9B409F5A6717DE72ULL, 0x16FFDDDB8AFD404EULL, 0x8A27C2B72A132600ULL, 0xFF8D89BF66B64AE7ULL, 
            0x8F50CA7908DD5A71ULL, 0xC4A5373A6D122F46ULL, 0x9D34DD23A45013EEULL, 0xCD840BFCC5258E8FULL, 
            0x6FBDEC862FD1EF1DULL, 0x5AA21BCF977DA884ULL, 0x474FCDEA3A67AA2CULL, 0x4BAEFC55D85785FBULL, 
            0xC89E492581D7ECDFULL, 0xB633883057EB7D50ULL, 0xC26573B4F96EC424ULL, 0xB270D3491572802DULL, 
            0x0555AD118D335BB6ULL, 0xB2E7685391022DBFULL, 0x90DC9DEC7D6BE07DULL, 0x2694DD6A660D212BULL, 
            0xDA02D407DBD755C0ULL, 0x29EE43C0A2FA07D7ULL, 0xD28EAD40B815EDA1ULL, 0x6FFEA53C4EC45701ULL, 
            0x526A34AF562E38BBULL, 0x45EAB7C0EA14869DULL, 0xD7DB1D72A4BFB858ULL, 0xC67EDC357DAC6C4EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Capella::kPhaseCConstants = {
    0x5C0494C1B237478DULL,
    0x132FD1A4A8384032ULL,
    0x561D690D7ACE1641ULL,
    0x5C0494C1B237478DULL,
    0x132FD1A4A8384032ULL,
    0x561D690D7ACE1641ULL,
    0xFF9F920458BF1E24ULL,
    0x0C66575FCB2F93EFULL,
    0xD8,
    0x66,
    0x83,
    0xA5,
    0x5A,
    0x4A,
    0x39,
    0x33
};

const TwistDomainSaltSet TwistExpander_Capella::kPhaseDSalts = {
    {
        {
            0x8EBF590DF59EBC0FULL, 0x41CB850CED00BC76ULL, 0xF76857A2122CE73BULL, 0xDB3E79FE472E29D9ULL, 
            0x58825571435ECE5DULL, 0x1242E72DC1660AFCULL, 0xB4B5ACD4F5E0B6C9ULL, 0xC8DC7B22E97C2498ULL, 
            0x9193C139F2B69B53ULL, 0xF272723690138DC6ULL, 0x56B6E2A65852F06EULL, 0x87930D81202ED7D4ULL, 
            0xDA29E0C4D36B910AULL, 0x7E149CBF177EC210ULL, 0x5B37736D26DCC490ULL, 0xB7128649DDA491E5ULL, 
            0xFA1DD77B0AED2824ULL, 0xB61C459F01493227ULL, 0x27C1C94D561A75F1ULL, 0x833C0E4111CF633BULL, 
            0xBB95C7EEB36AC203ULL, 0xBC60D8DD726C5921ULL, 0x88CD2CBF55BF8CFDULL, 0xEA14CA35C37AD7E3ULL, 
            0x07A51A88B2FADD45ULL, 0xD1669D4C0855E46DULL, 0x0536024027B9C4E3ULL, 0x7FE2A0B127274FD0ULL, 
            0x8A4B94B1AE53571AULL, 0x690A849CF961ABC0ULL, 0xCDFC61F9066EAED7ULL, 0x96D75503035A4B2CULL
        },
        {
            0xB888839AF851D62EULL, 0xD46198A25C3F1321ULL, 0x693F8BC26BC61D72ULL, 0x71BB74540BA39868ULL, 
            0x079944BDECAB0DD9ULL, 0xA80DDC0C0E61E1B2ULL, 0x6500E93F11648BD8ULL, 0x037302FEF84BA57BULL, 
            0xC9F8DB56A627727EULL, 0x6A8C4BDFA9E4B483ULL, 0xEE34367337464B19ULL, 0x6501D75236BA4306ULL, 
            0xE66AC7CED1602544ULL, 0x0914414E3655D252ULL, 0x1F7BCB27C6EF0082ULL, 0xCA29155910C48685ULL, 
            0x3F21E5F4428B52EFULL, 0x7417BA591374DD0DULL, 0xF9786E4408BA36A9ULL, 0xD7E4FAB34683AB20ULL, 
            0xA2A9E5CC6AA13C6FULL, 0x9B9D34A64A3C19C3ULL, 0xF0E27D36FABF1E46ULL, 0x660E928A5CB226C2ULL, 
            0xD96C9F1F5E7886F7ULL, 0xA6AE17FCC4EEB412ULL, 0x95FCC61849CC3722ULL, 0xC97A2862300B9CD3ULL, 
            0x27D00E91D0B53C93ULL, 0x1A473E535CECECA2ULL, 0x0CFDFD7B7A09EED5ULL, 0x4BA74B6A6CEC1A3EULL
        },
        {
            0xDA2DDDD84705E212ULL, 0x08E72B56B709D34AULL, 0xCD1DF5E0C3B6C582ULL, 0x8E4352517DC186C2ULL, 
            0x708CACE503801C62ULL, 0x66F8551F06F9AF80ULL, 0x51EFBC9333DB1FA7ULL, 0xA2A1EBD499E64889ULL, 
            0xCE5669BBCC89ECB1ULL, 0xE2466127D0314721ULL, 0x94E1B951369BF849ULL, 0x3893CC60B8A6EA0DULL, 
            0x1F4E10A4B1484F86ULL, 0xED9644D322B2AFE7ULL, 0xD77FB35686FE9C95ULL, 0xF1F2E7DEAEF77893ULL, 
            0x9CA724829B1013CEULL, 0xBE4C4505ED421464ULL, 0x50BFF1DD1A8671A5ULL, 0xCC78319DE207F3CAULL, 
            0x6F9D7D3747D88D4DULL, 0x878EAE723AA124EDULL, 0xC54FC364000581B7ULL, 0x513C5ED76ABC8B3AULL, 
            0xB6208E15726BAB0EULL, 0xC47F61DDF03E5913ULL, 0xB92CB339ADA14A2CULL, 0x6ED756C3F29ABB10ULL, 
            0xB7F51D7B7875004BULL, 0x7E553744962AD7A2ULL, 0xB1FE8A9C0B96C21DULL, 0xFB3A9E6FFE6505D6ULL
        },
        {
            0xCD549C61063E4E5FULL, 0x4A84D20497DC8BC0ULL, 0x07DA4FE730306278ULL, 0x7BD44E96F9FFCCF0ULL, 
            0x521CFEB23BDFC52FULL, 0xEFCC7A57370423DAULL, 0x2A326D4459BF1980ULL, 0xD99F1C6DA0F60C0FULL, 
            0x24C1F65B4488A2ACULL, 0x53D8E5FBA28C6988ULL, 0xF5948E9D6C985924ULL, 0xF2C4626D8CF8F26CULL, 
            0x8050DB1C27FD93AFULL, 0xDC21AB2B1AB23503ULL, 0x42705E57F6AFCFFEULL, 0xF1B1F08BE6884B53ULL, 
            0x25FDE0B6B77AC730ULL, 0xBCB7DC03F53841BDULL, 0x20658BBC99586AD9ULL, 0x51F71FB0334B23F0ULL, 
            0x0DEC7211F17276A0ULL, 0x9F192A42D115DB6DULL, 0x8ECA920CFDFFECA1ULL, 0x10B5A806F0764D20ULL, 
            0x52BF9197F36178D3ULL, 0x407FF06ECDF50035ULL, 0xC2E8F836858D7291ULL, 0x2A5EF66DD2B86BD6ULL, 
            0x431C759D462D32CCULL, 0xAA45FDA82392947AULL, 0x3849DF293FC71084ULL, 0xC2BC9C406B26D681ULL
        },
        {
            0x87DA2207100120A1ULL, 0x132E496DF5EC70D1ULL, 0xE7A7BAFE94FFD769ULL, 0xE823E566F1EA62FFULL, 
            0xA3B925F0E64D885CULL, 0xF12E21630A56E9A0ULL, 0x61EA9762E7E96525ULL, 0xE72F6F0A7E29C367ULL, 
            0x6338C13519C0B138ULL, 0xFD2CA58C443BB220ULL, 0x12E071D01AC2B950ULL, 0x63E3AEB31EB194C1ULL, 
            0xF787C6EDB6746A63ULL, 0xAEBEAA49013E5976ULL, 0x358D71C58DD8C827ULL, 0xB9B7E607AFEBF749ULL, 
            0xC1CF58FE8B634141ULL, 0xAD2C3F0284FB1BF7ULL, 0x5C6C461D266AD4B7ULL, 0x69E7DF9E261201AEULL, 
            0x45F004224ABDD967ULL, 0x764ABFA8CA55468FULL, 0x29CE8615C138DEA5ULL, 0xFA991AD80436DD33ULL, 
            0x6413443B93AB0CFDULL, 0x002B1463C87A15B7ULL, 0xC52940F313C939BCULL, 0x7933943B945ACF32ULL, 
            0x6A2509E691F8580BULL, 0xF81838820888E4CEULL, 0x1E31A89A86200EE6ULL, 0x15D78F46F545E934ULL
        },
        {
            0x71926E9DC3386ACCULL, 0xE1E8573F9F38F9D1ULL, 0x791CE56999F469FDULL, 0x5C158C0525C95C35ULL, 
            0x1D04CBF87B1E29C0ULL, 0x49C275123EE7BF4EULL, 0x7BBC92F1BE942B44ULL, 0x12C921DD7A065C8FULL, 
            0xD66E3E47B5A81919ULL, 0xE46452B7F7774B44ULL, 0x11CD7A128EF0DA9EULL, 0xFE5522D6B360E82FULL, 
            0x53C9657573E8FBB6ULL, 0x29EE488FF0EDBE86ULL, 0x82EFD73FFE58982DULL, 0x42C6B70AB23373EFULL, 
            0x501CA72A314EE775ULL, 0x3252CA45EE6FBB2BULL, 0xB752B5B995061A96ULL, 0xE41BB28B3E8960D5ULL, 
            0xD5CB2FAC80B30781ULL, 0xB6C6D3D0121A27E5ULL, 0x8DC0258499383641ULL, 0x9DF693767AB4D422ULL, 
            0xF6966E742043FCE9ULL, 0xEC357A3C0434B7E0ULL, 0x7571268852FAD361ULL, 0xE41A6507D03F0547ULL, 
            0xAAF450473503D0CCULL, 0x962C4113D11FA809ULL, 0xC52FCB86AFC56936ULL, 0x4A7B152364BD0D75ULL
        }
    },
    {
        {
            0xDA3FA8F40DC6587EULL, 0x0EFAD97796D0AD64ULL, 0x33AEE26262B74FD2ULL, 0x253D34FB60C2BF4EULL, 
            0x751A49042CA719E7ULL, 0x6DC29C0AB07E4125ULL, 0x155EF6FFE1305A1FULL, 0xEEF89FFFE5D09E88ULL, 
            0x3D414F6978620FE6ULL, 0x6046116B349D321AULL, 0x98D99486E80D5084ULL, 0x33305791AF900624ULL, 
            0x94F849C90D1943FEULL, 0xD4B077D4C1053854ULL, 0x4577CB103CA3183DULL, 0x3E02FFC3618994B8ULL, 
            0x880140B29385D7CEULL, 0x05E6A89A27A71017ULL, 0x5F22A07539077DA3ULL, 0xE90E7338BBA4B5B1ULL, 
            0x1AFC58ED02A87F2DULL, 0x920AFD23247B1F39ULL, 0x148AC76DDE5A30C0ULL, 0x884DBB922FE78288ULL, 
            0x2A47EE4F2AFB3620ULL, 0x7D92A59934E26FEBULL, 0x809986AF6B2A8AAFULL, 0xA0032FF9CF33E5A8ULL, 
            0x9D97DED0388D3037ULL, 0x9D26B474DFF81DB4ULL, 0x8865F3A4760D0E77ULL, 0x94D2E68328478D14ULL
        },
        {
            0x6602FDB927EEEB97ULL, 0x16A52C584D3ABB25ULL, 0xE7E955E20FAE0540ULL, 0x55333E43080B8573ULL, 
            0x9226FE005B74DE04ULL, 0xEB322D2358D5FDC1ULL, 0x3828D3B573D4E122ULL, 0x7532F9C37D31CE4BULL, 
            0x491E99B21A0AF59FULL, 0x32994BB310926893ULL, 0xBED7F3BBFC41CC84ULL, 0x66C72BF434D314C4ULL, 
            0x9911162F54D01977ULL, 0xBC916D023A6762FAULL, 0xE5528834917430FFULL, 0xD10440F7F1308253ULL, 
            0x0090CE10B06E7A8CULL, 0xD84910D4087E5632ULL, 0x9D30D237041CBF9FULL, 0x45363103CEA8BF5FULL, 
            0xB9CFFC91AE6A6EDFULL, 0xBCE6EFFBB223F57BULL, 0x4279C3B8B78899D3ULL, 0x43D3215B1F8B7146ULL, 
            0x0CB88A4446F38B7FULL, 0x3442C3BADE884610ULL, 0x18D1D6F10B1E56D9ULL, 0x486A4F805AB74B30ULL, 
            0x7A580A8F9B93C79AULL, 0x65B35847B06950B2ULL, 0xC3D12F7B8713E478ULL, 0x4E2A2BD4B9AAA12FULL
        },
        {
            0xBE117323D68DA37BULL, 0x3C045B690F47807EULL, 0x2C54BB24B1A79CABULL, 0xBAAF849B5DC0EF33ULL, 
            0x5D808EC37DCFA587ULL, 0x570AA6698F2FFA90ULL, 0x71320CDD8BD0538DULL, 0xDFA4B324C17A2347ULL, 
            0x0410CEFDC0355073ULL, 0xE070C8F7860AB0A0ULL, 0xB42B55CCC5D5F7B3ULL, 0x056A19F8D2D9994DULL, 
            0x4EC9F007B31318ADULL, 0x01678B1E88461A1DULL, 0x8673B8A2288A06E3ULL, 0x96B79FC5576DCA5FULL, 
            0xD41CF64006B2CF60ULL, 0x1FE42B8BE25000C5ULL, 0x3CAB2B236FC52C7CULL, 0x1876C83031A6C73CULL, 
            0x6A25DCCF7A6BDCB4ULL, 0xF76105A138DAEC6AULL, 0xF5AE2B0191566029ULL, 0xBD20FC859E26BC13ULL, 
            0x9EE5C462B9E2625FULL, 0x956DEDF4B0B4AD1BULL, 0xFB17D9D0EE4523EAULL, 0xED8BFADED6D1BC66ULL, 
            0xCC947DFC69015C94ULL, 0x0CEFE6FCFA05A355ULL, 0xB784C86FA816858BULL, 0x6174F1D8ADA7E8E6ULL
        },
        {
            0x34D0697F3AFAB14DULL, 0x828076C50DA37E5AULL, 0xD2031861B5B5FE87ULL, 0x045DC828827E3CFDULL, 
            0xE0DF7FEC65D04649ULL, 0xD0339B70FE7ED258ULL, 0x3F5CEEF8B5721224ULL, 0xC6E732E940BBE07DULL, 
            0x01B63CBD64F7230EULL, 0x209A6704C1276555ULL, 0x6DA1344648D1C410ULL, 0x38EDF1F0E5759FD1ULL, 
            0x6FDA267A09BEF571ULL, 0x19B9FE2D4137AF05ULL, 0xAA36FFBCF51321BCULL, 0xC1FFA7E6EE19D3D7ULL, 
            0x8FFF7414826026EFULL, 0xBD24572C28BAD46DULL, 0x9D258D4E02D9AABCULL, 0xEE16BB4EC68076ACULL, 
            0x9C96699857F32AD9ULL, 0x089F18DDA523350FULL, 0x4398A3E9618A01DBULL, 0x78BC52ED242F8997ULL, 
            0xD2E2DE1383A76CE2ULL, 0xF38663BE2903581FULL, 0xBAA81F44D37D7CFEULL, 0x29D2F1CD2DD6605FULL, 
            0x400949CE091F65CFULL, 0x97430411EF202101ULL, 0x24F2F3CF6E3BCC20ULL, 0x8C3F250F60C0FFADULL
        },
        {
            0x88A80584B3FB8882ULL, 0x44D5C17C3234C955ULL, 0x98EC5D3B76D79B0BULL, 0xE2BBAE2360DF1E1BULL, 
            0x55A78D24E837F2FEULL, 0x547328A4F57ECAACULL, 0x3A6E5A5E72AE90BFULL, 0x756FECAC93F4CAA4ULL, 
            0xD25CE6341A68546EULL, 0x1A6105F892676A35ULL, 0x403B41D77159AB31ULL, 0x759454692CB43072ULL, 
            0x178A218C7532236FULL, 0x4797B164D806E8EEULL, 0x59CA0BEB02DE0AB1ULL, 0x47B2C97417486CC5ULL, 
            0x085DF714D7028BBFULL, 0x11D7F87127628393ULL, 0x20A3EDF5F10B9565ULL, 0x5D748526A22BB40EULL, 
            0xA4A99AF894F96671ULL, 0xB84AE5CD0AC680FCULL, 0xC798AFF3CDA7E83FULL, 0xB67D679E8D854C8AULL, 
            0x68FF2576FA0CC6D1ULL, 0xBB108E379B834E98ULL, 0x4F4C3E38ABF183FBULL, 0x4705754A6457FBB3ULL, 
            0x8178FB4BFBAB54D4ULL, 0xF11D41DDA2AB9A9BULL, 0x432B9D028E01B18BULL, 0x28B08E61E1437758ULL
        },
        {
            0x930942D35755775CULL, 0xD68EC801DFBD4D08ULL, 0xFF9F699BF0AC9623ULL, 0xADCDE79E39539418ULL, 
            0x1B69770CC44FA943ULL, 0x5D7D0A86D5E3FA7BULL, 0xE619DB6BB11A6D2FULL, 0x96DD7CBA3E10809DULL, 
            0xFC12D61B4BE78752ULL, 0x0550EC45C510830DULL, 0xA5F65640D1FB7CDFULL, 0xE686BB7C38F26FD6ULL, 
            0xC2568376BDCA6A81ULL, 0xC085BA3FDAE296ADULL, 0x838CFD566AD74B18ULL, 0x157E8E376549A239ULL, 
            0x8A72F1381ACA1F41ULL, 0xED7B689C43A50F71ULL, 0xFF6A8163C13CDCACULL, 0x47420F0B1D0DDBF4ULL, 
            0x1404A813E28CED3DULL, 0x9DC68784E083E389ULL, 0xF090016A7D224CDAULL, 0x91104AD198FFFF60ULL, 
            0x602D16BA26B31DA6ULL, 0x1353E6128D66C6E0ULL, 0x9EEECF8C16C3B474ULL, 0x360910B6454C8112ULL, 
            0x6FEBCA45456A0F69ULL, 0xA1357AFFA4206342ULL, 0x78618A89212740B3ULL, 0x26F04257729A3303ULL
        }
    },
    {
        {
            0x6A9BF26C86C9BF22ULL, 0xD0DF3D4ABC799D3CULL, 0x4A7ED2C3C6AE30DBULL, 0xF02FA840F2B9A47AULL, 
            0xDD6A05531E40D420ULL, 0xE744C5250409CE89ULL, 0x07FF890AE36F5D6AULL, 0xAA435605450B4572ULL, 
            0x2676C4638348CC5DULL, 0x73CDEDB4D09AF214ULL, 0xD5B673C1C9690C6EULL, 0xDFA0B8BE51DC6FBFULL, 
            0x4BB4BA9D0C3C1E5AULL, 0xD0C74F6C5F001337ULL, 0x19FECFFAD9F9EA3EULL, 0x84713AD589D01FCEULL, 
            0x41FB8A8E4375FC4DULL, 0xF9733BFFFF33122AULL, 0xA13E748CF1B58B69ULL, 0xB26C5B2485777793ULL, 
            0x36688EF9B129E41EULL, 0x07AE68C876C60B58ULL, 0x5E1CBCC5EC2C3A9EULL, 0x54263628E585CD50ULL, 
            0xEEDCADD6926C563AULL, 0x27A71A0D2B71DF28ULL, 0x1878DBBDC64A9BF4ULL, 0x228F040DAD85C95FULL, 
            0xA4AC6AF45B12282FULL, 0x5C8FB153842C66DFULL, 0x8D6BAC5DEDC67E42ULL, 0xCE7C04E8B8DABD55ULL
        },
        {
            0x190ADEB787664BC4ULL, 0x2E6E73AB2104B27AULL, 0xC0E883DC922E2B12ULL, 0x319F4527D02D0E72ULL, 
            0xB40A96B5ACC112FEULL, 0xC38579E582A9F3FCULL, 0xBC9FB9272A86D28CULL, 0x8E546066453C3346ULL, 
            0x5B314DEC43957CE4ULL, 0xB66AA21AFB21FA09ULL, 0xA17A0CA38BE8E3C9ULL, 0xE36B477C20A21FF9ULL, 
            0x2060F041290AEBB8ULL, 0x40198F1E46F37F76ULL, 0xB84DEA2FA9B57CB4ULL, 0x76458D6EB6B1B798ULL, 
            0x50D0B1EEF2970E2EULL, 0x7101FC2075811D14ULL, 0x80A0B7317174F0D2ULL, 0x6071970C37FD59F6ULL, 
            0xC61069B57F97F8F0ULL, 0x8FAB99528CEA53BAULL, 0xF545DFE7EC699E7DULL, 0xF26EDF16828E1481ULL, 
            0x5C13B20D7101CF16ULL, 0xD44E43071762EA85ULL, 0x03B5D35A4E17655CULL, 0x4B471020069D664BULL, 
            0x8F022EF0801B3CCFULL, 0x894C81C52651F614ULL, 0xF7F1DFDAA14419A1ULL, 0xDF53BCC0D9388753ULL
        },
        {
            0x188EC4E969B1709EULL, 0xEA812C200418ABD0ULL, 0xC774A7C758FBB36DULL, 0x08B3B9446F585045ULL, 
            0x3BCFCE56CCE1B5D3ULL, 0x4E8F26389E1A6DE3ULL, 0xDA0600540EE1320AULL, 0xDC5E6DC3142F9ED5ULL, 
            0x3C9B92401D8E29B3ULL, 0xF41C64E612B3064AULL, 0xABDE4B92B80C6871ULL, 0xF95E6D83B154DF6AULL, 
            0x3D1B989F2470A0C6ULL, 0x53D35AFD05222468ULL, 0x52B8E245665FEC4AULL, 0xF4B6E1D3F94D518DULL, 
            0x46FD52255A66C62BULL, 0xE6326C271A64B4E2ULL, 0xD3E1BC2193BBC8D9ULL, 0xAC21427AFD454A68ULL, 
            0xEFD60A9DCBED0068ULL, 0x5DB8F2CB744B82FEULL, 0x07A260A59F206ABDULL, 0x371E22B353515514ULL, 
            0x9D58B99F898A57D9ULL, 0xD2AAE04AC368FC03ULL, 0x30C97EFD39672BA5ULL, 0xFC7F3F2ECF96AED8ULL, 
            0x64E83EECF0D69642ULL, 0xBFBD1F7D01653C19ULL, 0x989FCFBC6F700775ULL, 0x7F0BF98DBBFE37C4ULL
        },
        {
            0xE24E1EDF73EA25B6ULL, 0x797769A5CE565C94ULL, 0x89AB0CD7A56B5CA4ULL, 0x07F3AF3CDA20E7F5ULL, 
            0x343AB527EBE6CFE5ULL, 0x91AB361E041148FCULL, 0xE47426A4955039D9ULL, 0x6C5B4A2F51E5594CULL, 
            0x756B177BA75A11C9ULL, 0xA9C424B2D261C239ULL, 0x3B24A9FCA2D6B7B0ULL, 0xDB73737233861781ULL, 
            0x5F307D997F7F8512ULL, 0xE44D5C56A8997795ULL, 0x0855D29CD3F514FDULL, 0x7FECBAA3F85C420CULL, 
            0x06BA8280AC4AAD34ULL, 0x9ACAB601360ECDDFULL, 0x89777FBD6A9071C0ULL, 0xFF323CD679B6D4B2ULL, 
            0xC449CB09EBE54BD4ULL, 0x2C97014821D95461ULL, 0x4C6136ABD1719F6FULL, 0x31585B0539C93C98ULL, 
            0x9675F9BC34E20229ULL, 0x21848DA84E051207ULL, 0x59D2C9067E56B14EULL, 0x0472148F3423CE38ULL, 
            0x4A4DF9F66A48045AULL, 0x70C8B366A934F45DULL, 0x16917E659F49C6C5ULL, 0x0455D3955C0FF505ULL
        },
        {
            0x924CAB4566920CDEULL, 0xE581D42D5EF09329ULL, 0xC0A054F0E189B706ULL, 0x15451212CB21A9E7ULL, 
            0x2B1F6A33D15B1A5FULL, 0xD8A53A051DB26103ULL, 0xAA4FF88E6AEED04BULL, 0x3C6CC8BF5DEC1F15ULL, 
            0xB7E714FEA02DBA6BULL, 0xFFFF041EA043A3ADULL, 0xFFC0CBEE89D10F78ULL, 0xD03BB23C1514FAF3ULL, 
            0x8A585F249749B2E0ULL, 0xB20753DA1F6AD496ULL, 0xC30D10BA4E2D80AAULL, 0xD1743CBA319ED9F3ULL, 
            0x6C4EFBFB0344E5D6ULL, 0x3807E808F73B1206ULL, 0x9EAC8468A5B1558FULL, 0xA7B0C629B711DCF4ULL, 
            0x83414E9D051EA785ULL, 0xC4467561A32791A3ULL, 0x5B9D1A071F24491CULL, 0x1E0F57A783D85548ULL, 
            0x1654FE79BEC5D3B9ULL, 0x8D5FFEAE8A9CDE37ULL, 0xBFE1F4A6D71CEDBEULL, 0x43FC2B8B7798D7EAULL, 
            0x5F6A19695B2283C2ULL, 0xED4DD85261B2118DULL, 0xCF6BCDC28D984F18ULL, 0x159DBF13B7CA5C86ULL
        },
        {
            0xBF0F1DBCE61AA33DULL, 0xC144B759CA220EF2ULL, 0xB45EFB5ED81A4C71ULL, 0xA2841EF27BB840A7ULL, 
            0xE63DE42224D3F500ULL, 0x78EF27DA0A7DB904ULL, 0xF33833DB8E75ED91ULL, 0xEF790A6DBA6EDC9AULL, 
            0xF1B2A32A6D2B8A05ULL, 0xD6457C19DD53B1B4ULL, 0xA284742F4EE6F16FULL, 0x6E26B01B48E1988BULL, 
            0xEFA75AFDE30FB41BULL, 0x16196D70105CA73DULL, 0xAE18F3ADC8F45278ULL, 0x08F5F955420CEA39ULL, 
            0xA96ADA1553D4714AULL, 0x11ED2D4BDA4D4B24ULL, 0x7B9CBA435C1C4D4CULL, 0xB3D8092BF445A773ULL, 
            0xB5361BEAA54D4D96ULL, 0x43C17BCA5523D61DULL, 0xF3FAACE95B0DF9ECULL, 0xCECDD397A20C7C5EULL, 
            0xE24AE3E0F73C618FULL, 0xD477A68C944A45C3ULL, 0xCBA9C13D707EEA99ULL, 0x0DD6FB73F20934C4ULL, 
            0xA0E541218CDBE2CBULL, 0x681F03EF9CB068CBULL, 0x85636DB32D2853B0ULL, 0x38C1887CA14E83EEULL
        }
    }
};

const TwistDomainConstants TwistExpander_Capella::kPhaseDConstants = {
    0x355AF86A3D8763D6ULL,
    0x410126D336CFB478ULL,
    0x90EA012B6296DCC7ULL,
    0x355AF86A3D8763D6ULL,
    0x410126D336CFB478ULL,
    0x90EA012B6296DCC7ULL,
    0xD418DB56A0096992ULL,
    0xC6ADB757BC0F205EULL,
    0xC9,
    0x43,
    0xCF,
    0x2C,
    0xB5,
    0x6D,
    0xD9,
    0xCA
};

