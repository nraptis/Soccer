#include "TwistExpander_Mothallah.hpp"
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

TwistExpander_Mothallah::TwistExpander_Mothallah()
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

void TwistExpander_Mothallah::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xBA2F26ECDCFF6511ULL; std::uint64_t aIngress = 0x8100FB45AA5876EFULL; std::uint64_t aCarry = 0xDD16DD6E90C411B5ULL;

    std::uint64_t aWandererA = 0x9B937CE6E4DB4EF4ULL; std::uint64_t aWandererB = 0xA37C27D41B1ABB74ULL; std::uint64_t aWandererC = 0xAA0D9984F4161AA8ULL; std::uint64_t aWandererD = 0xED2DD490849C95B6ULL;
    std::uint64_t aWandererE = 0x9FD6B9985C6174E0ULL; std::uint64_t aWandererF = 0xE91163DD9D8B284CULL; std::uint64_t aWandererG = 0xBE4837FA3CB3E783ULL; std::uint64_t aWandererH = 0x914B6DD09DD90825ULL;
    std::uint64_t aWandererI = 0x86D17A17731AA52DULL; std::uint64_t aWandererJ = 0xCD2B287624F504FAULL; std::uint64_t aWandererK = 0xF3D513B969A619AEULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x854FAF7F21FCAE19ULL;
        aCarry = 0xE240407D9795C069ULL;
        aWandererA = 0xE8F032A52B4CDF25ULL;
        aWandererB = 0xA9EAC1965F8A6B60ULL;
        aWandererC = 0xC135A90C42611EBFULL;
        aWandererD = 0xE96A616E7D856B40ULL;
        aWandererE = 0xBE89C4142146E642ULL;
        aWandererF = 0x8756CF3CE267988DULL;
        aWandererG = 0xB91E7B9FA3D9580AULL;
        aWandererH = 0xBA2CE15F112AD3D5ULL;
        aWandererI = 0x89918B72C9D50722ULL;
        aWandererJ = 0xA9B821B6AEB927F3ULL;
        aWandererK = 0xD6567C58263D4499ULL;
    TwistExpander_Mothallah_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Mothallah_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Mothallah::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xCDA98D231776EB9BULL; std::uint64_t aIngress = 0x93D8BCF0D5E0C813ULL; std::uint64_t aCarry = 0x82E7887473B0B84FULL;

    std::uint64_t aWandererA = 0x8E1A0B23AC6B7048ULL; std::uint64_t aWandererB = 0xCAA9C65E28598FE6ULL; std::uint64_t aWandererC = 0xE71A7D64894F05C8ULL; std::uint64_t aWandererD = 0xD0FA68C39383EECCULL;
    std::uint64_t aWandererE = 0xA76FFF1A8A47FA87ULL; std::uint64_t aWandererF = 0x98EA38CE2059354CULL; std::uint64_t aWandererG = 0xDB6500F8020CB17BULL; std::uint64_t aWandererH = 0x837D2BB9183F1281ULL;
    std::uint64_t aWandererI = 0x96680E6C2CCEAC53ULL; std::uint64_t aWandererJ = 0xBC25AEE0969030B1ULL; std::uint64_t aWandererK = 0xD8D1C677D88CCB96ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xA2DAB49F08028058ULL;
        aCarry = 0xCF20EAC27A27E5B2ULL;
        aWandererA = 0xCA89FAA91A5CCDD2ULL;
        aWandererB = 0xE193FA2C0C1E84E8ULL;
        aWandererC = 0xDA1499E467AD8DAFULL;
        aWandererD = 0x85814688DC361CD2ULL;
        aWandererE = 0xB89F5F14A1C5B5D7ULL;
        aWandererF = 0xEA318390B3961680ULL;
        aWandererG = 0xA0328971B38C7905ULL;
        aWandererH = 0xC25A8DF56A336D71ULL;
        aWandererI = 0xBE8C7089A4732918ULL;
        aWandererJ = 0xA61A6625B81F1D96ULL;
        aWandererK = 0x981CCCDAB81FFFBEULL;
    TwistExpander_Mothallah_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Mothallah_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Mothallah::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA5F03F9FDABD0D23ULL;
    std::uint64_t aIngress = 0xC3D962EB259BF6DDULL;
    std::uint64_t aCarry = 0xC48ABC01486C04EDULL;

    std::uint64_t aWandererA = 0x8A8AC53B6D487DD3ULL;
    std::uint64_t aWandererB = 0x9307192BB052C093ULL;
    std::uint64_t aWandererC = 0xDC744476DFA9E024ULL;
    std::uint64_t aWandererD = 0x9644312A25C7BD4FULL;
    std::uint64_t aWandererE = 0xB32AB72488EF1150ULL;
    std::uint64_t aWandererF = 0xEA4FF9986E5CEFF7ULL;
    std::uint64_t aWandererG = 0x93C28DBA1F829253ULL;
    std::uint64_t aWandererH = 0xBA0153F31522478DULL;
    std::uint64_t aWandererI = 0xBAD401289BB360C8ULL;
    std::uint64_t aWandererJ = 0xD1AFB83723E5AD2FULL;
    std::uint64_t aWandererK = 0x809F275673A19CB7ULL;

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
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), pSnowLaneC, 1);
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
    TwistExpander_Mothallah_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::Seed_C(pWorkSpace,
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
    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgD;
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
    TwistExpander_Mothallah_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::Seed_F(pWorkSpace,
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
    aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixSelectA;
    aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixSelectB;
    aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixUnrollA;
    aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixUnrollB;
    aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixArgA;
    aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixArgB;
    aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixArgC;
    aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixArgD;
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
    TwistExpander_Mothallah_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Mothallah_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Mothallah_Arx::GROW_B(pWorkSpace,
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

// SmartSquash candidate 22 of 33
// Exploration cases: 100000000
// Nearest-family diversity: 917 / 1088 (84.28%)
// Total distance from earlier candidates: 19593
void TwistExpander_Mothallah::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    static_assert((S_BLOCK / W_KEY) == 16, "SquashInvestToKeyBoxes expects 16 invest fragments.");
    static_assert(H_KEY == 8, "SquashInvestToKeyBoxes expects 8 key rows per box.");
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 11U), *aFragmentB = aIceLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 4U), *aFragmentD = aIceLaneD + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 812U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 296U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1362U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1346U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 1U), *aFragmentB = aIceLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 2U), *aFragmentD = aIceLaneD + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 268U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 190U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 664U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 509U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 8U), *aFragmentB = aIceLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 11U), *aFragmentD = aIceLaneD + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1733U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1609U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1326U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 767U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 13U), *aFragmentB = aIceLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 3U), *aFragmentD = aIceLaneD + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 272U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1561U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 2038U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 978U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 3U), *aFragmentB = aIceLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 1U), *aFragmentD = aIceLaneD + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 649U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 643U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1739U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1354U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 7U), *aFragmentB = aIceLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 12U), *aFragmentD = aIceLaneD + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1533U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1610U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1494U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1946U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 10U), *aFragmentB = aIceLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 9U), *aFragmentD = aIceLaneD + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 890U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 2046U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1490U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 920U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 9U), *aFragmentB = aIceLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 15U), *aFragmentD = aIceLaneD + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1380U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1947U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1357U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1472U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 6U), *aFragmentB = aIceLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 7U), *aFragmentD = aIceLaneD + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 929U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1538U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 139U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 640U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 5U), *aFragmentB = aIceLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 8U), *aFragmentD = aIceLaneD + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1708U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 823U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 592U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 609U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 14U), *aFragmentB = aIceLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 6U), *aFragmentD = aIceLaneD + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 887U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 425U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 176U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1700U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 0U), *aFragmentB = aIceLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 5U), *aFragmentD = aIceLaneD + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1242U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1344U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1748U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 636U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 12U), *aFragmentB = aIceLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 10U), *aFragmentD = aIceLaneD + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1303U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1862U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 674U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1411U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 4U), *aFragmentB = aIceLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 13U), *aFragmentD = aIceLaneD + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 48U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1957U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 590U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1840U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 2U), *aFragmentB = aIceLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 0U), *aFragmentD = aIceLaneD + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1824U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 284U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 902U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 24U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 15U), *aFragmentB = aIceLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 14U), *aFragmentD = aIceLaneD + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1270U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1612U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 645U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1034U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Mothallah::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xBA31725E95808B82ULL; std::uint64_t aIngress = 0xDF6FE7BB8E940041ULL; std::uint64_t aCarry = 0xE5952AA70D455DDDULL;

    std::uint64_t aWandererA = 0xB17D3D912F8A0539ULL; std::uint64_t aWandererB = 0xE1D09F0BDEB3C12DULL; std::uint64_t aWandererC = 0xD9293E34921F1EE1ULL; std::uint64_t aWandererD = 0x8BF717BFEDC6798FULL;
    std::uint64_t aWandererE = 0xD2C77588EA03E7ACULL; std::uint64_t aWandererF = 0xB15C20415023C4D7ULL; std::uint64_t aWandererG = 0xA29BA4861CAD9F30ULL; std::uint64_t aWandererH = 0x8072B67FD7916F04ULL;
    std::uint64_t aWandererI = 0xA3CD477981F0E5CAULL; std::uint64_t aWandererJ = 0x900E025B2B85B703ULL; std::uint64_t aWandererK = 0xEE97A317A05D99F9ULL;

    // [seed]
        aPrevious = 0x89B2C1933578D640ULL;
        aCarry = 0xAA4797610D52264DULL;
        aWandererA = 0xFEBB6E30B188ACFEULL;
        aWandererB = 0xA5AF83FE7835F9C2ULL;
        aWandererC = 0xCBF072C1F0C21BFAULL;
        aWandererD = 0xF2EBD3E31FF5A123ULL;
        aWandererE = 0xEA02D026B77B1F2FULL;
        aWandererF = 0x8005E7EFE4963718ULL;
        aWandererG = 0xEDCFC68FF664990EULL;
        aWandererH = 0xAF8A38BD37026734ULL;
        aWandererI = 0xC5A702E860060EB3ULL;
        aWandererJ = 0x8BC653DBCF8C46DDULL;
        aWandererK = 0xA9A97E3891AA422CULL;
    TwistExpander_Mothallah_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Mothallah_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Mothallah_Arx::Twist_E(pWorkSpace,
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
    TwistExpander_Mothallah_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Mothallah_Arx::GROW_B(pWorkSpace,
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

// GrowA candidate 22 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 11402; nearest pair: 459 / 674
void TwistExpander_Mothallah::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3131U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6726U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2378U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7093U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4476U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6366U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1840U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1026U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 813U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6668U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2109U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7880U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 166U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5189U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4415U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2282U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 144U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1372U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1678U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1798U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 158U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1753U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 678U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1754U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1844U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 54U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1976U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 176U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 368U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 365U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1581U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1033U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1632U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1777U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1838U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
}

// GrowB candidate 22 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 11385; nearest pair: 473 / 674
void TwistExpander_Mothallah::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 392U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3570U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1970U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4062U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2230U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2970U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6807U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5062U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1768U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5043U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6719U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6632U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6016U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8100U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5760U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6156U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1901U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1017U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 143U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1836U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1894U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 234U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1753U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 647U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 678U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 293U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 603U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 275U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 440U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 447U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 458U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 825U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1491U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 324U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 842U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1988U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
}

const TwistDomainSaltSet TwistExpander_Mothallah::kPhaseASalts = {
    {
        {
            0x9CC7CABDBA9B1E3DULL, 0x30F3B4BC397F3E5EULL, 0xD81B3A40A1FE8272ULL, 0x40D0CBC0351E11A0ULL, 
            0x20112C70E2AEF333ULL, 0x556E717D4AAE8941ULL, 0xBC9C3468ACBCB331ULL, 0x1E34A931B345F8CAULL, 
            0x3F1947EC1A2E45C5ULL, 0xA1C2B22CEE692D08ULL, 0x8AE33CA4C8620E90ULL, 0x215A81E1DBC7FD41ULL, 
            0x3B3CD22BA2341EEDULL, 0xD04A8F5E7883520FULL, 0x635F84035BE04C21ULL, 0x7E41F0CE68EA3F0DULL, 
            0x32E24D8383EAD55DULL, 0x7F3431315EA388B4ULL, 0xDA7659A0D10E068AULL, 0x4FB00E73CE84F69CULL, 
            0x5DC0F6DCC6C2F534ULL, 0x21E7466768337F16ULL, 0x05AC2CD4805D8888ULL, 0x69FFA594A1A9BF6AULL, 
            0x73368047CC986461ULL, 0x2C6A05512B5ECFA2ULL, 0xBC832A155EF47036ULL, 0x0348D700BA2C97A1ULL, 
            0xC3B76B262729EEFFULL, 0x2FB6763AB5A3C62FULL, 0x54E639DB0074166DULL, 0xA08A9C09928A53E4ULL
        },
        {
            0x871FDBD397A3E750ULL, 0xD11CFBB3974CB85BULL, 0x607D22D5E0BD8703ULL, 0x2D73AB1C08D5DF40ULL, 
            0x7A2967B45A6FA0E7ULL, 0x1E2705F193E74357ULL, 0xC163041F81E1DFE5ULL, 0x94BA683D6F7F048FULL, 
            0xE8A914784F700091ULL, 0xEF39AD79E422FD5CULL, 0x6793AF0865373A54ULL, 0x1B42B2FF027CF929ULL, 
            0x53B753A74A3B5D4EULL, 0x9F12614425DDC389ULL, 0x986007A6F27F76A7ULL, 0xF4A10C1A48629C2DULL, 
            0xC328BA7460653794ULL, 0x467092B6166F5278ULL, 0xFCDB52A1BD9CE2A4ULL, 0x2685008302A9BE93ULL, 
            0xB5246BFF45A5A957ULL, 0xF945E7E7AE3BEE9AULL, 0xB30ECE054C68442DULL, 0x8271507EF49EDA19ULL, 
            0x9BC1BCBEC66E7818ULL, 0x2EB77E13A350D537ULL, 0xCC42FB070A504700ULL, 0xEFBEB66E8A6CE13FULL, 
            0xE3263EAF5D0D338DULL, 0x59822FDD9823F3E6ULL, 0xE174DAF33F0058E6ULL, 0x7DE82BD2A75B8A26ULL
        },
        {
            0xDE520FA050AAE2C5ULL, 0xC9EC00948E4D3F57ULL, 0x6019806D7F11BB28ULL, 0x4BACBAC8D09FEA4BULL, 
            0x01CE378CC04BA312ULL, 0xCD8B4C7D7BDEFC5DULL, 0x2A19DF8DF4DB1FD7ULL, 0x77DCDFF430BEE635ULL, 
            0xD19F8A216507F6C3ULL, 0x690BA6690464B003ULL, 0x54C35ED0D87D921DULL, 0xFFFFFB131D8750F1ULL, 
            0x9DFE1EAA1C2E56D3ULL, 0x1BF23E0A94B7605DULL, 0xA6F92C9E3E7B8AAEULL, 0xD1A843D3F4C15A86ULL, 
            0xAE4F7C3BA9B0049DULL, 0x9500923606970889ULL, 0xE733DC88B12B5C45ULL, 0xBAAF1357C58494D6ULL, 
            0x08E890B82A7DD8A1ULL, 0x50098F1E89BDF4E0ULL, 0xE21BB10D6EC14C75ULL, 0xFB9DDEBC6A45D564ULL, 
            0xB421DD2CE4EF42DEULL, 0x095D1214F41564EEULL, 0xF316DB032623077FULL, 0xBA61D1D94DF34CFAULL, 
            0xF50FBDD9099AFACBULL, 0x026B68C6877E6423ULL, 0x098433D795EB1FF9ULL, 0x9F8FD56E7E4B53AAULL
        },
        {
            0x33CDE06D5534DD58ULL, 0x28935897C7930C86ULL, 0x1D626EA52BB84A82ULL, 0x0C4B42779288D94AULL, 
            0xDAC88A09E7809491ULL, 0xCDC0F7CE7B1A6770ULL, 0x9C50322B71CEB79DULL, 0xF77160C41B24D734ULL, 
            0xD39BC81F25DA64E7ULL, 0xA75AFE77D6E96A17ULL, 0xAA1BC7B286F010F1ULL, 0x77EFA4D81CD548E4ULL, 
            0xB862856CDA13A1ECULL, 0x9162DE990DC5A5B5ULL, 0xD9D0AAC58C44A776ULL, 0xE5B2600596FA77DBULL, 
            0xFC2766F8F871B5CFULL, 0x3B90077DCBFDAD7CULL, 0xEF0F995991980B0EULL, 0x790271028323EE79ULL, 
            0x15E16141A56C6206ULL, 0xECB2467506BBF473ULL, 0xA4318C0A40052377ULL, 0x57891AEA44F53E6FULL, 
            0x2A3D68B56D073A19ULL, 0xD8E1AA0BA1E97E60ULL, 0x5D3DB7D0DB8310F2ULL, 0x0208D68992A2EB43ULL, 
            0x1812D839752ADB54ULL, 0x2C676764C6C55117ULL, 0x58008D0E34F05F8AULL, 0xE82A4510A37D1DB6ULL
        },
        {
            0x3B70823A98907094ULL, 0xE3634EE1A3B7C3D8ULL, 0x78F05DB75DE25AB2ULL, 0xE0949862EEAE9E5DULL, 
            0x1BDA1C1C29E31796ULL, 0x08C245A448B24439ULL, 0x3978C90B68C7A343ULL, 0x544858098998CAC2ULL, 
            0xCC453FE946B0B452ULL, 0x4573162DE7993490ULL, 0x9F327600E6694E20ULL, 0xC6373823D154E371ULL, 
            0xD98D330AFD5514F4ULL, 0x622404E3B075A897ULL, 0x922A0F3942BBF6BCULL, 0x8AE4E551361FC4D9ULL, 
            0x913039FBF63B19D0ULL, 0xDEB3757F8332BD5BULL, 0x02780306548AFF9AULL, 0x1AFB585A974F3EE5ULL, 
            0xDF9D555D12D8A7AFULL, 0xD3EB57376E6C7103ULL, 0x8DA25A7197BE08F6ULL, 0x67E4ECB1E2A583EFULL, 
            0xEC9D084F80FB2200ULL, 0x40983DAAA98B604AULL, 0x8528F507FD6FD8E3ULL, 0xD4CDE449584E242AULL, 
            0x4E1107B30B7A62C1ULL, 0x82D6BEB539EDB176ULL, 0xDF83BCED294278D0ULL, 0xBAB9B3A6208E5517ULL
        },
        {
            0x99B0B0F8505F298CULL, 0x7B5515EB5A819A6EULL, 0xB26804ADC8D63646ULL, 0xD51C1FFFB2599F7AULL, 
            0x970E16E83C6C3D9CULL, 0xF368B1746E2E7299ULL, 0x40AE30AD9AEBD92FULL, 0x92E94A9924B079D9ULL, 
            0x3C6C00CD5A496CD7ULL, 0xE451BD01AA019828ULL, 0xD8B7F4B5814911B8ULL, 0x19B17D80BF2FD842ULL, 
            0xCAEA2213299B22CFULL, 0x89520274264086F5ULL, 0x0C6565DE84FDB3C5ULL, 0xA23C552D6887334DULL, 
            0x047312EEA509FCD4ULL, 0x7612C4AAE4A34B8CULL, 0x4D4507EEB78256E4ULL, 0x9A572ECE170E2576ULL, 
            0x44BC17929AB2170AULL, 0x0670493ABEDB84AEULL, 0x54CA03B54C8ED6E5ULL, 0xB5E29134D074904DULL, 
            0xF649D8B02095462DULL, 0xBE9AD2EAE4F99980ULL, 0xD0AFD78F57E48EEFULL, 0xB9F9BFD264AB832BULL, 
            0x5D2D905AA79B305AULL, 0x8AE5E7B44BFDFC5BULL, 0x2AA824D3B0C9E928ULL, 0xC5E8D6C51A2FDE7DULL
        }
    },
    {
        {
            0xEB8C23F6279CC839ULL, 0xDD2F7F101697EA40ULL, 0x8BA0960B8115F507ULL, 0x39D6320BF22C7157ULL, 
            0x7E79392F575445CBULL, 0x6E178396D66D81AAULL, 0xC2F63180682D2799ULL, 0x765263CB837512BCULL, 
            0x146BB44335B6F5A9ULL, 0x8534E61574872154ULL, 0x45EFD903F8D9DDA1ULL, 0xC11335C9BA97FED2ULL, 
            0x09FBBCA3C357190AULL, 0x294E5CDB635AB982ULL, 0x5E04C6055904A3BBULL, 0xE8FC6A9304B87F6AULL, 
            0xF3BBDA1CB92B2304ULL, 0xA35EF0413DF7B07AULL, 0x9964654CFD907A5AULL, 0x9536E1CA7C546E28ULL, 
            0xE97B4FF1DAE7BADEULL, 0xEC5A9F06FBC7AF70ULL, 0x06B1F6D81BA21150ULL, 0x74FEDDD2D004F20EULL, 
            0xACD4E4DD8E872363ULL, 0xB901490C1C8106E7ULL, 0x8A791F9C74F29E47ULL, 0x98AC5B5A00C93871ULL, 
            0x00E39B7C82A8C914ULL, 0xCD2778ECB2FB91DDULL, 0xB2661AC513717591ULL, 0x408B0C423A9F82B6ULL
        },
        {
            0xAA857C5961A82271ULL, 0xDE3E02A5602EBC05ULL, 0x53ED8B73E296DF1EULL, 0x7CD5B5AD15A4219CULL, 
            0x180E7F586942E2E3ULL, 0x8C6D7E302D45F6C4ULL, 0xA227F3EEC0CA657BULL, 0x8364F07A0F5AD938ULL, 
            0x12FAE305CD2DFE7AULL, 0x3BB986A836D60334ULL, 0x0A261209ED74B25FULL, 0x2777B60B8FAFEA36ULL, 
            0x3C80A3757FD5E60BULL, 0xB8EB74FF3123B4EEULL, 0xC6008285F8FD5CECULL, 0xCD85B1616BA77E9CULL, 
            0xDCC9227DD2049068ULL, 0x79668A251BF3E421ULL, 0x3B78BDE2298F9195ULL, 0xAFB883ADEE4A525DULL, 
            0xF6FAFDED044AE546ULL, 0x1DDD7A101446F2E1ULL, 0x83F797F898BE617CULL, 0xA1CFD675606424E6ULL, 
            0x42EABAF41275C1EFULL, 0x00FFB42AC9F6A6CFULL, 0xB22843E709E7B1D4ULL, 0x3E62426A5B11E4C6ULL, 
            0xF3B136CE9A6E8F06ULL, 0x948AC9FD211BBAB1ULL, 0x8E4BBEC62F795AEFULL, 0x523A899EFCD314CEULL
        },
        {
            0x16026E8182C80E5EULL, 0xF1850E4A73FD837AULL, 0x288BD35C58732359ULL, 0xDF27C3FB8C4896FEULL, 
            0x5FF15CD82B153B9CULL, 0x4CF46BF293A6AF4DULL, 0x7DB3EA160E3D3A12ULL, 0xA4967854B1B2F008ULL, 
            0xF873AF4652AA19ABULL, 0xA4D1CDBED3F47532ULL, 0x81B03437B4C01AC5ULL, 0xF665D9FC073ACA96ULL, 
            0xB6D24C247190F1F7ULL, 0x93A9D32CDE60D521ULL, 0x669D3E402A8B1CEDULL, 0xCE3524E396ACA623ULL, 
            0xA4C9B9BC0B336BEAULL, 0x7F286DDF6778B4CEULL, 0x6A75A9997E5DA164ULL, 0xC201A84BD2FDAF69ULL, 
            0xA40F9ADAE8E07931ULL, 0x24DB775243068C0FULL, 0x495A14AD3A21AACBULL, 0xF264FD109DE63DF8ULL, 
            0x92E4F16FEDB58C73ULL, 0xD56F34CBF1501575ULL, 0x4ED7388189F4C94CULL, 0x0F2676F131C1E71BULL, 
            0xC85F1655A33AD864ULL, 0x1373DB46C81FEE3DULL, 0x2496DAF3E33EA9E5ULL, 0x9A628C6745B94B2AULL
        },
        {
            0x2120527C29CFAE23ULL, 0x302BD30A25CB2BF8ULL, 0x7CDE6EBEE2CBF37EULL, 0x0B2E05965D2E8033ULL, 
            0x292C2F090BC61DEAULL, 0x170D3AE18DFC0E60ULL, 0xD99BADD83B3B00C0ULL, 0x70A58C3C0D9A5AF0ULL, 
            0xE7D53EC7B43AA0CBULL, 0xF01E95A7D82B9060ULL, 0x80F55F0F9431CDD9ULL, 0x198F37E0126E4364ULL, 
            0x39FA165EE684D93AULL, 0x9225D447A05FB326ULL, 0xDAB4295539D1956AULL, 0x40F9CF56BAEEEDB0ULL, 
            0x7865D03B71963470ULL, 0xBB63B009C231506CULL, 0x5614EB9B1F05378FULL, 0x9A62EC35482CD74DULL, 
            0x7FEBFF3DC964AFD1ULL, 0xAABB51B63111E5D4ULL, 0xF86E7A75D6B1E876ULL, 0x777F3258D22BC17AULL, 
            0xD9139B2618EAB277ULL, 0xC6D5DD5CDFD04E64ULL, 0x50BC4569F0CBDFE2ULL, 0xD693A8CC07CD02CCULL, 
            0xD454B4BEC6061450ULL, 0xB2E8228E6C1A1CC4ULL, 0x41FEB3EE61E45584ULL, 0x0D23C9EFE231BF4EULL
        },
        {
            0xFF7E6B2AAB57B4AAULL, 0xA093FBD92B6D7688ULL, 0xD17E26D223F4DB40ULL, 0xC1934B05EB077BC2ULL, 
            0xA6481C7381DE2456ULL, 0xC317157018F346B5ULL, 0x11AD43EA2F3CAFC1ULL, 0x6F8F1159FE329DDDULL, 
            0x9178C82CBABB67BAULL, 0x64217BBB9867C294ULL, 0xB978553B2C2D66C3ULL, 0xA8190602B5697485ULL, 
            0x4538D9D21C53B9CBULL, 0xD6B4A16EDBCC5B72ULL, 0x066C61AD0B0CEFF5ULL, 0xD154EE6F044AA3E8ULL, 
            0xE6EB3022FF3D5D3CULL, 0x2B1808D0EAD46C21ULL, 0x68806E4930AA3F48ULL, 0xF2B0064A7A5914D3ULL, 
            0xEA2A0D62A65A5A74ULL, 0x73F312077BC85733ULL, 0x09EEBCF98253390EULL, 0xB17A525F88F20A46ULL, 
            0x0B2FA31DF04A8518ULL, 0x47E57A1789F73C83ULL, 0xD63FCE9AEAFE21EAULL, 0x6B4DEFFB57D8F407ULL, 
            0xEEF21599083BB522ULL, 0xC7EF3955E51A5337ULL, 0xFEBFC3DA2A6A687AULL, 0xB121F99FDE76B232ULL
        },
        {
            0x5F7B26F58DF6BE08ULL, 0xBDCD74277935CEFFULL, 0xD421819D80C93C02ULL, 0x08BD9525717EAA37ULL, 
            0x82C590F88EF6CB9DULL, 0x1BFCA8E2D9999C7DULL, 0x6850C8C500B5E4EDULL, 0xE106D3CD08089910ULL, 
            0x201AD3841FBAAB95ULL, 0xDF3CF9C7826211BDULL, 0xEE7637E997CDB332ULL, 0xA020FA093CE68F66ULL, 
            0xF0F567938F5D85BEULL, 0x1F61603D86E67D72ULL, 0x1CE4C4A4C8E5869EULL, 0x818A81E34A9DFD06ULL, 
            0xE6E1DD365CC9FD31ULL, 0x02CE958D30E56627ULL, 0x26016214DF0C109DULL, 0x47E5973410223DDDULL, 
            0xA2CA0678ACA52B6DULL, 0xAF6D2CF03CCDEA8FULL, 0x574B79C7ABB2D9BFULL, 0x89A7A2994674E55EULL, 
            0x3606B4A6E84A5770ULL, 0x8A4626AEC652627DULL, 0xD08FD549EA35FF0CULL, 0x215C5E520F9D6EE9ULL, 
            0x32B098E2D0FB7A24ULL, 0x4CD6CDB857183AA8ULL, 0x5215E13C02403168ULL, 0x03F237DC6492439DULL
        }
    },
    {
        {
            0x2156E0EAF721266DULL, 0x9A6FB6CBCBA126BBULL, 0x7D8475B970C40FCFULL, 0x00C2D97E06843363ULL, 
            0x3349D9144BD8BE75ULL, 0x481E4953FD7E51ECULL, 0xCE265C64E857BE46ULL, 0x2D61341889CC3388ULL, 
            0x34C9919C3875EE7AULL, 0x2245F85DC2FC3ADCULL, 0x6043989BF8689C16ULL, 0xBD16A9825027C8F6ULL, 
            0xFF5781B4F699E633ULL, 0x558015D2F517AFC7ULL, 0xF046DE87E5538F41ULL, 0x28E9E9B742FCCB86ULL, 
            0xDE77B5C09B274B03ULL, 0x5A0E1C28FC74BB53ULL, 0x765023DD50CB4308ULL, 0x39C60153A18A7EA0ULL, 
            0x17400D580E45AEA9ULL, 0x96698FA633B83BAAULL, 0x0B2A46AE3F1E1E90ULL, 0x6482385E7EE2E0B4ULL, 
            0x94D56ABE377ACC4EULL, 0xB0EF4943E64A4DC6ULL, 0xEBB2883AEF67E58CULL, 0xB51EA1FB5C9DCD9FULL, 
            0xBA78D0E9F8449AE3ULL, 0x7337287D87D02A21ULL, 0x264A70451720F51AULL, 0x898C1D6E88DE930AULL
        },
        {
            0xA10D4D8D7AED60E2ULL, 0xFF66B6F7FC5FC7C2ULL, 0x9C0954365FAF3999ULL, 0xFFD03334484FADDCULL, 
            0xDF3FCED8486C0E49ULL, 0x79F9E63ACA9FBB99ULL, 0x09BE77CD617A8127ULL, 0xF61D65D004F8C5DEULL, 
            0x10DBBB184CC9D726ULL, 0x6251B39D35C9C44FULL, 0x1337A3CE9A35EEEAULL, 0x6ED9C7B6F23B5371ULL, 
            0xA5238C8CF76D6EB4ULL, 0x7F8843CC7A32193CULL, 0x49EAE84A864462B5ULL, 0x7443A1FEC101AE8FULL, 
            0x5FAC9D404E56A448ULL, 0x9AEADABF1FB21E14ULL, 0x27E98A31CF0FB48DULL, 0xC24601A9624622BDULL, 
            0xA454DBB0870FD28BULL, 0x104D420CB2A4082BULL, 0x6FFB969261FAB781ULL, 0x7FC0BD8CC4E2D479ULL, 
            0x85FFB219E38FB270ULL, 0x0E1471C0883AFBBBULL, 0x45F5730EA5C85F97ULL, 0xBDE0021E0B10AFC6ULL, 
            0x98A9824300DFB8DEULL, 0x36896A523E16DE97ULL, 0x7B96AA461496889FULL, 0x0AEBB6F09E63F67CULL
        },
        {
            0x30B244FEF45ED292ULL, 0x8A8D4D492D5FE8E9ULL, 0x3BD30498F6061FAEULL, 0x157D71E21ABAFB13ULL, 
            0x6DCB1CFED29F6A8EULL, 0x87C45562544F67F9ULL, 0x5D74B3775211A16CULL, 0xB85D7E49A3F9CEC4ULL, 
            0xB01D5A32C47B7EDFULL, 0x6F218ABC83E0B3F2ULL, 0x6D9316A5FF4A36BCULL, 0xEA52116B6BCBB4D5ULL, 
            0xDA6787368C75ABAAULL, 0x7FF0980F7163D0FFULL, 0xF12C333F9D998826ULL, 0x319D8F84B7525425ULL, 
            0xE2951B8512FB3E75ULL, 0xB508A49318E0DC0DULL, 0x96043C011BA5164CULL, 0x87C4D3679A0836B1ULL, 
            0x94BC0556E319AFC0ULL, 0xBD2A0F1EE769777AULL, 0x9EBD33DD3E733754ULL, 0x1C93F7724B15D057ULL, 
            0x79AC0C507E11749CULL, 0x4DC56A0F48EDBB54ULL, 0x3C97A4855CFCDD9AULL, 0xCFCC957376392896ULL, 
            0xC3A2EFD7A1CF5EECULL, 0x5BC45D4CC8951F48ULL, 0x8E2224CF3140DA98ULL, 0x7DF796561648CA6CULL
        },
        {
            0xD6505CBDB8F6DDB2ULL, 0xC097B9613ACCF910ULL, 0x4033219D6E06CE0FULL, 0xE180CD1AABBB6A8BULL, 
            0x8E8A60262AE871DCULL, 0xC7F8F372B9403EF7ULL, 0xE1C97A2E2EDF233DULL, 0xB912BCCD5819332CULL, 
            0x0852908AC9A8B65EULL, 0x3320D88446FC63DDULL, 0x82F397CB01252621ULL, 0xB0E2A4A2E53BB0ACULL, 
            0x68C5BE1802ECCE22ULL, 0x2E07242B22B3A908ULL, 0x9CCB1316F8956F30ULL, 0xA7E02D2A23EB41C1ULL, 
            0x027EB28172D49852ULL, 0x6056AEA7C34CBC91ULL, 0x3D624BE1EA18259EULL, 0xF58A153D3ACD80FDULL, 
            0x00C5B5C68AD268CFULL, 0x1CD531D7BD944450ULL, 0x11C32B5241C2BE54ULL, 0xCB4C20DF5C691847ULL, 
            0x523F542D2250E0ADULL, 0xA204A609F262BB1EULL, 0x86549FB5E4B38C1FULL, 0xA6ED72E0D5747880ULL, 
            0x58746F64B50818F1ULL, 0x6B89BB995866265FULL, 0xB4740B95379C06E3ULL, 0x94AEAAD8381E932CULL
        },
        {
            0x5F801B3B7A9443CBULL, 0x17B79044E2B178D2ULL, 0x2F483C2C783D92D1ULL, 0x94A57312807C5E1EULL, 
            0x4FA192C774CE9E1CULL, 0xB327D3966CDEBEA6ULL, 0xC65CAA19CEC1711FULL, 0x3DDC40B86D2489F4ULL, 
            0x84D261E4CC63A7D7ULL, 0xD485025D17FC0675ULL, 0xD64CC574A1A8C3C6ULL, 0xE447BE9C41061C0BULL, 
            0xDCB02EE644AC7A0CULL, 0xD953DB879F9D47D6ULL, 0x23120518FF2A5EB3ULL, 0x4A50B33D20FEB551ULL, 
            0x160DE2B44B7733DBULL, 0x765F0CDE14721027ULL, 0xFA899F3EFD4AFDEBULL, 0x17F8452073B5BCC9ULL, 
            0xEC63657A0A6CFCE0ULL, 0x38EF189F488AF289ULL, 0x973DEDE9D1CEE0BAULL, 0x12F27B9A6E2090DEULL, 
            0xDCA854156A1A8A5AULL, 0x0B0326589DB8B263ULL, 0x3C52BB5D4C1F9C50ULL, 0x3B6862D629A3F8A0ULL, 
            0x000AE7A0FAF49E19ULL, 0x05763E601AAF7A42ULL, 0x80455B0E7756BD7BULL, 0x63812E73F38752C3ULL
        },
        {
            0xB69FF83066769696ULL, 0x2AB1185856E99793ULL, 0xE8E0C392626563B5ULL, 0xDDF122141ABE9A92ULL, 
            0xDC9DC8F0DF315063ULL, 0x5DB1ACD678423711ULL, 0xF12122FFD87AADE3ULL, 0xD79D135142ACA928ULL, 
            0x48E3A3655FB942F6ULL, 0x557492602C865226ULL, 0xDD4F5CF7A6C2ECE5ULL, 0x631906C0F91E5A99ULL, 
            0x432E93DC001C0616ULL, 0x797538B45FAA7D1EULL, 0xE14B4B9F91D8E312ULL, 0xDC318D2F9AF4BA4EULL, 
            0x0C1B4C99EF0719BCULL, 0xA9242164DD6083DBULL, 0x3A31DE6CE7497F27ULL, 0x885B5524922CD716ULL, 
            0xDC15F8B8F01DEA06ULL, 0x67D1AE12A81DA4A7ULL, 0x98E4580C3C014681ULL, 0x6F6D1050B1453732ULL, 
            0xC893CD7B4F5F66A5ULL, 0xA10721CA301F70BBULL, 0xF0BA1BA4E2A98C7EULL, 0xF0D9CA572E42C9EEULL, 
            0x5DBB7DA70F1F4E4FULL, 0x24984D923A080C71ULL, 0xF4A51B454A32456AULL, 0x49CB6FDEDBA11429ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mothallah::kPhaseAConstants = {
    0xC94833472E29A0D5ULL,
    0x3838E1AFC2755104ULL,
    0x6D95F19AB96BDB34ULL,
    0xC94833472E29A0D5ULL,
    0x3838E1AFC2755104ULL,
    0x6D95F19AB96BDB34ULL,
    0xA74972CB8C716F4EULL,
    0x99898FDF249EF568ULL,
    0xB8,
    0x29,
    0x1F,
    0x0B,
    0x06,
    0x8B,
    0x09,
    0x44
};

const TwistDomainSaltSet TwistExpander_Mothallah::kPhaseBSalts = {
    {
        {
            0x7CD0D4D7BE3781D9ULL, 0x3E0FA873070B53FBULL, 0x85269BFA81080089ULL, 0x8AA1442481BB6308ULL, 
            0x2F7B7C04E39A8241ULL, 0x7907FA9CC883E40EULL, 0xF9C9B4623A6F2224ULL, 0x05CB46158CF7F158ULL, 
            0x795777060CC765D7ULL, 0xDC563203AEE8840DULL, 0xDF9F6C0C5E7D4C69ULL, 0x157D3097CC49D602ULL, 
            0x70770B49E2D12064ULL, 0x729CC5079118BDD1ULL, 0xAAC527FE6B79EB44ULL, 0x746EA859A91A15DFULL, 
            0xD2C28B77E5148F86ULL, 0xCCC4C5327F9693ACULL, 0xA375417559E1B880ULL, 0xEC8D66821F2E23FDULL, 
            0x572C4E8590C818CCULL, 0x040CD157F2913043ULL, 0x8218512A6642319AULL, 0xB697F58E521660D9ULL, 
            0xF602CC80254FEC6BULL, 0xD31832F776BAF170ULL, 0xB8B919986C7A38CBULL, 0x0F25007E239D4DCFULL, 
            0xD10E6870DBEDC0CDULL, 0x8AC4975ECC25B423ULL, 0x96CDAE46D030F49DULL, 0x57195087713A9359ULL
        },
        {
            0xBBBBB23CA5669A04ULL, 0x71C494668438436CULL, 0x1392A40A152A04F2ULL, 0x53E7F64B06FE4FE5ULL, 
            0xBF2B319BE47172BFULL, 0xB0910BEF80351478ULL, 0xA3AF769161128949ULL, 0x31B24A94DA5611A1ULL, 
            0x76237A4A0FAB81D8ULL, 0x13CFFFA2B12DCD64ULL, 0x432C8B7868AF9EEEULL, 0xB3549B2934EA713FULL, 
            0x48A1A9DBAE0CCD5CULL, 0x6CA817BC07E6212CULL, 0x52D4CF121E1066FCULL, 0xB06130A43C747361ULL, 
            0xB90E985F682DF1F6ULL, 0xE447215BAC9E5D80ULL, 0x94448FDAA5CF6415ULL, 0x186AB02B48C03ECFULL, 
            0x475732E92298B852ULL, 0x1439F96A665B192DULL, 0x29167CCCC531E355ULL, 0x326DB3612CB6D876ULL, 
            0x05D8522720D09306ULL, 0x73C6C1A7A545C87CULL, 0x3C4B27F006D35ADFULL, 0x35CA648166783230ULL, 
            0x7F591E7142AFD1B3ULL, 0xF809F9FE15178284ULL, 0x41C8E0F8715AE094ULL, 0xB6FB8FECEE749DF3ULL
        },
        {
            0xB2B22D069EE84399ULL, 0xC4EEE3F8FC5355B9ULL, 0xC1F14561B57FBD22ULL, 0x4B2348EB8916F531ULL, 
            0x5046BD657AA3FA38ULL, 0xBDB531F2917A118FULL, 0x790DDC4EDB2F4C0CULL, 0xC2F7ADF46C7EE96EULL, 
            0xC66CDCA8B86F17F8ULL, 0xE77FEB1BBF2B0C61ULL, 0x84F608207E566B05ULL, 0x97C6F0464FDB8485ULL, 
            0x962A2C6E706F884AULL, 0x3461A4D969300834ULL, 0x60BE315C69AB765EULL, 0x3E6B55140839C6BAULL, 
            0x85DEA2279C5BEF7AULL, 0xD6518B9252505FFDULL, 0xEE361503181B5113ULL, 0xD13C5104DC916A90ULL, 
            0x7DE50856CBBCBB71ULL, 0x490A0A90EBB0670DULL, 0x665783B921E15F40ULL, 0x0C932189B8212184ULL, 
            0x59AF10EB81271ADCULL, 0x940AE9BD6039F50DULL, 0xCDB63CFA0C5FDDC0ULL, 0x363334CD01703B7FULL, 
            0x8EAD11E2481EA670ULL, 0x623D821DA8EE2D8CULL, 0xB9035AB93E1E2AC2ULL, 0xADD3E2EB8D3170DEULL
        },
        {
            0x69BA34E9ACEE505DULL, 0x4ECBACA7A0DDEE39ULL, 0x51271E11B8C2270FULL, 0xE9EFAF694F2C49B2ULL, 
            0xB044D913910DDCBFULL, 0x1C48D0F55B99C45DULL, 0xBD6D61A92C8C8993ULL, 0x72E6D30770D1AF28ULL, 
            0x79E88D55AEAEC696ULL, 0x0592D7DF62F7E9C0ULL, 0xD4CF2C6A36CCDDC4ULL, 0x81561B939BA581BBULL, 
            0x2AA6E74454532B4DULL, 0x083E9AF8AAEB16D1ULL, 0x4121D94844ED74C1ULL, 0x5FC7D30211D358EEULL, 
            0x0FC198A25C8B9D87ULL, 0x382694AD1DEC75B0ULL, 0xFD0B73799E6629B4ULL, 0x1405970FE96F4AFCULL, 
            0xBC71A14CA8DCB60EULL, 0x87EADE3C2B8FB288ULL, 0x50E08A0667F268DAULL, 0x28E5CA5B909323EFULL, 
            0x3A6C78CBBD315DB0ULL, 0xDD95EB6D71622024ULL, 0x81F44FED09871398ULL, 0xFC8652FDCD6D8003ULL, 
            0xF3E6C16771B0FBCFULL, 0x56738B22A547E213ULL, 0x247E88A7A9B3586FULL, 0x81F7078AA58AE11BULL
        },
        {
            0x85FBF94EDE4D1B89ULL, 0xD75C32BAEEF23ED8ULL, 0x6898A76914B10378ULL, 0x3FC39F98BA47C4B8ULL, 
            0x192F94C868F1C119ULL, 0x6B8A1A97428A2CE9ULL, 0xB38C32FD94449E66ULL, 0xB95960F1CFE3F10FULL, 
            0x15E6C9742F60C901ULL, 0xE847A3B484BF3327ULL, 0x1240A9A8F89782D0ULL, 0x78162BE370918CA5ULL, 
            0xD25D1DC7FA466C03ULL, 0xE7F32C2C9800AB52ULL, 0x1748B9E1666D4896ULL, 0x9326F93EAC8AB94FULL, 
            0xC58BD2E60ED32364ULL, 0x1CDF4B00BB81963FULL, 0xC236410761005E97ULL, 0xB3DBE2C60A71D8F4ULL, 
            0x469FD2282A1F64F0ULL, 0x112E26BEA23AFAC1ULL, 0x27D068CEC975C88BULL, 0x48DD46DC1D30BDA8ULL, 
            0x19A28B223BA7FB77ULL, 0x24C8FBD138ABCA89ULL, 0x50B5289F26F35463ULL, 0x480891015F2571E7ULL, 
            0xD7201D0D4CE2969EULL, 0xF872AA713C75EF70ULL, 0xF80F8E61FF1D15C6ULL, 0x74D6B3B8D5CDB487ULL
        },
        {
            0x4B4E08D0C3D9E932ULL, 0xAE373C9E43D4309BULL, 0x7B1992641987D46EULL, 0xB81038FD9EC13773ULL, 
            0x0FAADC51E4D27D57ULL, 0x7F81D3DFBD4C2603ULL, 0x773C6F66939287A9ULL, 0x4B29E8E2463DB30BULL, 
            0xFC286ED29C334ADEULL, 0x7E3CCFE0AF972AE3ULL, 0xB2DF284EC4238E03ULL, 0xD56E78B44C3C6108ULL, 
            0x2183BC62833BDD84ULL, 0xF32FC1C741DDD3E3ULL, 0x17CF2E43E84DEE43ULL, 0xA5732A4E6158D3DBULL, 
            0xF7AC048C4AC0EF16ULL, 0x98C7221FEED4167BULL, 0x012578A4781E35F2ULL, 0x0C3AC4CF6111CA0AULL, 
            0x6FD93CE20FE4A8D4ULL, 0xD0A3922317073A08ULL, 0x8A2D1DDE328351B7ULL, 0x12114368E1F46DB8ULL, 
            0x2041EE5B8B2BD24EULL, 0x4D1C6D462B0D37DBULL, 0xC1C78ABC0C959D78ULL, 0xB7A99B38E6A46BE9ULL, 
            0x8162BA746DC9A68EULL, 0x98EDF14340D95A12ULL, 0xBC27AC3A74365495ULL, 0x00192017CB3264DFULL
        }
    },
    {
        {
            0x610108FBEE76C2CAULL, 0xC1D393576845B77FULL, 0xE40299B7763D0283ULL, 0x41F0E5A13715C918ULL, 
            0xC3785C6C021E0361ULL, 0x6BF828EFF721A9C1ULL, 0x276DE03759677019ULL, 0xF0304EF6A4639D9EULL, 
            0xD60B0AE0C4215F13ULL, 0x245BB7886858F2E1ULL, 0x5AAB7356F20A5102ULL, 0x5FDDA432E6A8D84AULL, 
            0xF4AC7E723D68ED54ULL, 0x2441CE99B81C3E6EULL, 0xE2C8B802D3D2D121ULL, 0xF299D3B22598B4BDULL, 
            0xA0E38A9CADE0EE6CULL, 0xD788B320E0A78AFFULL, 0xBEF9D3D5961A668AULL, 0x38256A8AEA00CBB0ULL, 
            0x343BC8BCA118B890ULL, 0x6316316C77DC5D78ULL, 0x310F84C91DAF2355ULL, 0x2235497337E4898DULL, 
            0x410078232076E151ULL, 0x10FFA0F73516EC10ULL, 0x42E51A221D91440CULL, 0x6EEAB2BA464D3530ULL, 
            0x45244DD0E77B718EULL, 0x1FB90E2DA795101FULL, 0x3B3BE81E3D85ED16ULL, 0x6BEFC81A0E005F78ULL
        },
        {
            0xABE8EFA5DEE46C1EULL, 0x2201E962D427CC36ULL, 0xC551E591136D04BCULL, 0x02105DF798A3D64DULL, 
            0x2D9A9F7C09D96CB5ULL, 0x6B969D4563B9C7DEULL, 0x636BBCEC130941B9ULL, 0x2C2B4CFFE5103A1DULL, 
            0xA78AD6F916DB89F0ULL, 0x1DA4E1E1359159BBULL, 0x0FE87DE430770926ULL, 0xD7F07D06BB78B762ULL, 
            0x0388A0A2ADCA58DCULL, 0x27B3C8B468985E67ULL, 0xD2CFE34C2B92D0EDULL, 0x4CC6AE26E500A700ULL, 
            0x30D3E1F79382BEA8ULL, 0x10F7576E90E99EA7ULL, 0x9DC8165FE9A1C687ULL, 0x4D88B65A5DA6A2A0ULL, 
            0xB3AD384DF183DFBCULL, 0xBDD959335BFC13C5ULL, 0xF127A7493FAACAB4ULL, 0x6FF9B3819B9410B1ULL, 
            0x50CB1786743F1C00ULL, 0xF3E19586BF8F96C2ULL, 0xB3852EB7B9EDA330ULL, 0xBF455C6F4463D187ULL, 
            0x6FE143A107554597ULL, 0xE6973AC30486F61FULL, 0xAF03324DE3B5453AULL, 0x573D7C9B5F4C634DULL
        },
        {
            0x2F0C41E3454AA6CDULL, 0x14E2EE2AE658A9F5ULL, 0x785F09AE59466F19ULL, 0x892045D65E3117CEULL, 
            0xA32B9AB33EFAFC0AULL, 0x311AB9515B89AAC1ULL, 0xC8243F69E7EFC17AULL, 0xB2B87CDFFBA89558ULL, 
            0xD320EBDC7BE3B775ULL, 0xACA8EC11EBAC0B59ULL, 0xE5E5741955FA6F6FULL, 0x378CD5EE4056870DULL, 
            0x8AFD941EC9AEC533ULL, 0x9109D61F9F96F7A7ULL, 0xA0709E767167F6D7ULL, 0x9D8DCA85A8A2D9C4ULL, 
            0x55A578CCFC17F588ULL, 0x74F8DADB61A3CDDFULL, 0xD5969E1AECE0163DULL, 0x06A5B0ADA422EA90ULL, 
            0x62F02A28EF2157EBULL, 0x49FDB1A5EEE8C817ULL, 0xB1BD0BC236DB7489ULL, 0xA399C76118E54A53ULL, 
            0x767DB6BF7E951569ULL, 0x8C1C9C27CBFFAF94ULL, 0x8FEC75894982E28EULL, 0xC7C5EC9FE2404DACULL, 
            0x8F2C3A7384553483ULL, 0xFAE97E0BB8C062B2ULL, 0x550E6D799D02F478ULL, 0x92B9758402E759ECULL
        },
        {
            0x561B8B1695DEAE1BULL, 0x169B9013F3497E64ULL, 0x50AECA9ADB0DD571ULL, 0xAEDC9676C13D49E8ULL, 
            0xDC9DC230CA853202ULL, 0x5AB4D7A7E919019BULL, 0x5FB18282F9AF6C3EULL, 0x02C98F63B53F7F3DULL, 
            0x310FFFFCBCA1364CULL, 0xBB2379348AE2FCE4ULL, 0x6D5A2E6C82D0C72CULL, 0xA19EB4EF6FFF7633ULL, 
            0x12037C6F9B8974FCULL, 0x2B8304B572F43051ULL, 0x82A90DDDC88BF985ULL, 0xA17B1F3291F3A38BULL, 
            0x8F685E21B7961150ULL, 0xDD0E170E454F29A9ULL, 0x0E841E937D205038ULL, 0xCFCA6E2B07383E28ULL, 
            0xF34E96985FA8468EULL, 0x52A65DECCAC88847ULL, 0x95A3A03434AFC9D5ULL, 0xF874DA57CA34A437ULL, 
            0x799D27FE495FD15BULL, 0x0F330E48D0F05EF2ULL, 0xF292F277ABA8F868ULL, 0x3093374AB959F4A2ULL, 
            0x15814A5894762702ULL, 0x8BDAF46C59FA89EAULL, 0x1D049AE5568500A9ULL, 0xB7454BEBEEC948F0ULL
        },
        {
            0xF24BE5C050F0E9D0ULL, 0x7E020FC55F209E5BULL, 0x21367317D0D014A1ULL, 0x7458883289F131EEULL, 
            0x88563F1800A47BE8ULL, 0x929AEEEC8DBDA214ULL, 0xEB0AE7991C5667EFULL, 0x86608D4201C8BDF8ULL, 
            0x5D589DC06C7FB2F2ULL, 0xEC129A65C4A0CD48ULL, 0x83038C4D5EB618AEULL, 0x96A3B43CD42275C8ULL, 
            0x1599FFBF179E3B05ULL, 0xBBE234AEE052F8A0ULL, 0x313E1B4D74D8EFB1ULL, 0xF444069578AE8A90ULL, 
            0x32757129EFE5B748ULL, 0xA78080B91A8F4BA0ULL, 0xD7562CB72DD3208FULL, 0xFCB2B0936F0AFED0ULL, 
            0x1FB9308034D4A456ULL, 0xE5216A0E2902DF9FULL, 0x7F66ABAA293B2AB4ULL, 0xE9528A63CD21A2B2ULL, 
            0x2527DA737A42B9A7ULL, 0xE8FFD1D9278F7E7FULL, 0x00204E3830B39CADULL, 0x686578819F0C51C9ULL, 
            0x5B75020337086184ULL, 0xE24FF94839E6ED83ULL, 0xEDFA8A3404C75D80ULL, 0xE79646F045337456ULL
        },
        {
            0xBAD6371AA4EA9EF6ULL, 0x75571B60F6DFF911ULL, 0xF788C43221536648ULL, 0x68B83CDD8BB0DDFBULL, 
            0x893B66B7BF3DEB4AULL, 0x3C51998A7F111214ULL, 0x122F2A909BEC3B4AULL, 0x71913736EA6DC41DULL, 
            0x33D1CAEE51482E7FULL, 0xF9E20F75A360A8A8ULL, 0x07B6B737D9A38F4AULL, 0x18CE793953C06111ULL, 
            0x28F8667046D2CC04ULL, 0x33FD248A93C83630ULL, 0x9D1FC0F039656194ULL, 0x4095F5911F00810BULL, 
            0xFE20E07BB3F62BE9ULL, 0xB3BD03B1082A3A82ULL, 0xD463B7BE731DB411ULL, 0x4562A46B78B2D2EEULL, 
            0x6372394D35F66F2BULL, 0x8D92A072AB04FA65ULL, 0x47A9AE1F2A477D30ULL, 0x859EC6B7B8C22BA5ULL, 
            0x8A2C8C679A5E94F1ULL, 0xDBC022C3213E4A6AULL, 0xBF8F307588E28344ULL, 0x33BC9AF8F0490D49ULL, 
            0xBA572169B8BB6B4DULL, 0x7BB1D187498C61D0ULL, 0xA36765BC3D11063CULL, 0xCB38A6E58A529F89ULL
        }
    },
    {
        {
            0x7D7D6671B6DC20C4ULL, 0xB8E63959C9F2378BULL, 0x7699B699C048ACB6ULL, 0x5A297E6E6F50AC43ULL, 
            0xF28AE83C0B5D9DCDULL, 0x398CA2AABFA4FD9EULL, 0x8976FED5CAFE957AULL, 0x6FBBC07B4C6A224EULL, 
            0xEE316F377BF4CBD2ULL, 0x670BA9C628263C41ULL, 0xED3D618C3DA4A996ULL, 0x7C410EC7F2EBEC14ULL, 
            0x0FD63FFD3FE3412AULL, 0x12790A0A6FEBC75FULL, 0xB759F43EE98E320DULL, 0xD36CB23E59D210C5ULL, 
            0xD12F9A42ECBD74EBULL, 0x160513429205F398ULL, 0x0660DCFA9EF6C4F7ULL, 0xA69A0211E649D17BULL, 
            0x41A45767D8D8A2F4ULL, 0x2FE39A36C7E00ABCULL, 0xCEE63C6B303407F1ULL, 0xF10E505FB8192A51ULL, 
            0x86193D21BA2F150AULL, 0xBA6E551C90483D45ULL, 0x4A21A4B6A60F5B6BULL, 0x3332BD89764C485BULL, 
            0x8FA7B6DF58DF8BBCULL, 0x9C7E2B4362512D36ULL, 0x89FC4790CCE4910EULL, 0xFF08F1D08FA67A24ULL
        },
        {
            0x5BCA63BDE5B7EECEULL, 0xAB7F86825755B971ULL, 0x6C81711F1A10CFB2ULL, 0x9EB0536B881081FBULL, 
            0x5449982F203D5A23ULL, 0xC0B578B056FA2308ULL, 0xC32FEC725684F537ULL, 0xD07784A025CAC958ULL, 
            0x96EA6BBB435223D7ULL, 0x046F55A76A74BE74ULL, 0x8635CE540A141AFDULL, 0x5C97F8D905674BD0ULL, 
            0x163D11747418B798ULL, 0xE0F6E499EF4C3F89ULL, 0x6CD4CC15F6A4555EULL, 0x55D09D905B58D528ULL, 
            0x678B3E769AE56B5AULL, 0x30784F037D8C4F6DULL, 0x5F83C5B1B704695CULL, 0x629E38A867BC797CULL, 
            0xDD6742781FD66206ULL, 0x84959853FD891DB5ULL, 0x078CB4C2536B4DE3ULL, 0x2F6C696BE00DC123ULL, 
            0xC2EFD14623C2C752ULL, 0x666C7CE641BB165CULL, 0x8CB8D3DA8B8D45E0ULL, 0xBA8A0F56874AA08DULL, 
            0x04D51655DEDC7F3EULL, 0x82ADD7F21D02ED2FULL, 0x21291662D7034A37ULL, 0xBFB0577AD978A48EULL
        },
        {
            0x73ABEED74A0B78F8ULL, 0xDF7796AAE8DE3CBEULL, 0x50A1290F006136B8ULL, 0x9CB02F06699E3718ULL, 
            0x23CEABE6E8F8E961ULL, 0x4F4550465A0A1D92ULL, 0x0008141C78260B22ULL, 0x0689C1429A02A79AULL, 
            0x126C5C02595B5C9AULL, 0xE67256F2C91BAB61ULL, 0xCBEAE8052B4EC927ULL, 0x217D080CFBEB40C4ULL, 
            0xB58E3370CCAFBE8CULL, 0x4BD489B491221AA7ULL, 0xD482113CFE2B97DDULL, 0x86FC1F12B1E607E9ULL, 
            0xB7FD47152A9F85FBULL, 0x42314DAFC1FF3492ULL, 0x5347EEF0FD34FB1EULL, 0xAC430FBF12D2FFBFULL, 
            0x50CE3A5222BDA1FAULL, 0x3CC14DA453DF2EE5ULL, 0xECDA345B1EC7F6D3ULL, 0x2B400456D25030F5ULL, 
            0x52838ED4CD05CDEEULL, 0xCDFE4EA3E523D994ULL, 0x5EBF01A39DE19C04ULL, 0x52E0804CA36F2BE1ULL, 
            0x995280571B55ADFCULL, 0x1C69AB1A040445ADULL, 0xA302925701C6018EULL, 0x498CB90C9AB02CDBULL
        },
        {
            0x9EEA29A9514152ACULL, 0x2F093EF373EABB0BULL, 0x5F2FF3C5FB46805EULL, 0xBFCB84D0E77DC453ULL, 
            0x3D3354027F6086CAULL, 0x96F3D0482F783E95ULL, 0x9A86B38A9F67097EULL, 0x1BB926A3D62997CFULL, 
            0xE45387C2EE918D13ULL, 0x2115C9373E3D5F5EULL, 0x9343CEEFA189651FULL, 0xFFD9B68121AD99D8ULL, 
            0xEFC5ACF93300AE45ULL, 0xE2B5871E0C1F963BULL, 0x1607B5B576F3A7E7ULL, 0x2D63D794FBBA7C79ULL, 
            0x50CD5D3BEEC2AB6FULL, 0x9AC5CE141FFBF463ULL, 0xC7BC70421AD17429ULL, 0xD2E88AC74C351B42ULL, 
            0xC96AA860EC5C6B62ULL, 0x0A0C1F123F0BEB87ULL, 0x470D51EB4C8AA9C3ULL, 0xB53055BD5533FC51ULL, 
            0xF5A5F3BA8D4F8173ULL, 0x710DF80D77420D7EULL, 0xD2FA13393523B6C0ULL, 0xB0ADE7AF622143E1ULL, 
            0x7A657D78D8DC516CULL, 0x4CC791E9E69A8F61ULL, 0x31EB9E739DE4A9E4ULL, 0xCCD377879EBA1CA1ULL
        },
        {
            0xA1147845696F0972ULL, 0x7F78E032A297C1BFULL, 0x29C2E155765B4980ULL, 0x8AB8D2A49E3F88E9ULL, 
            0xE61A0C71545B2DE4ULL, 0xE0665354C3D0AAA2ULL, 0x7DF91EC817F9F5A0ULL, 0x2AB67781542C9A0CULL, 
            0xAC932D5850B6CD5DULL, 0x4A64AF4BA62C9B94ULL, 0x62B7894EF2F13B07ULL, 0xA93682BF42B7425DULL, 
            0x71E7959A79370EC8ULL, 0x1344B02BE38AF9B9ULL, 0xDAF07CE18FAEE0F7ULL, 0x8E5948A13A28F17BULL, 
            0xF8D53DF205EFEC47ULL, 0xA6B362832A7233ECULL, 0xC0C0DA67F646BD6BULL, 0xEAD87BCBD9BDD2DAULL, 
            0xE2C7C8AE2308C522ULL, 0x3DEC841EB0FCF87AULL, 0xA669A388591D04FEULL, 0x930ABE2AA9F3E8F5ULL, 
            0xB13D81C0D449D501ULL, 0xB609D060E7260B3DULL, 0x8FC1E34FB2F522B2ULL, 0xD248FF57BD25B327ULL, 
            0x223E534A8714BFF6ULL, 0xC151D0B225351F51ULL, 0x550D8F8376997A45ULL, 0x4B0009D0F6323CA4ULL
        },
        {
            0x78D849CF7B363507ULL, 0xDA1E7E239219C455ULL, 0xEC18C30AE451AC8BULL, 0x0AFB7AF01A9C98B8ULL, 
            0x87F82B3100BEE997ULL, 0x7A7AB81808E35EE8ULL, 0xCE06A29589E54252ULL, 0x14DC45E655DF1E43ULL, 
            0xB76EFBFED9B6C400ULL, 0x9427ECBD72E8C7B3ULL, 0xB2ED041D9101FAC4ULL, 0xFFEFFAE7278741F8ULL, 
            0xCC27ABCA36D5D1C1ULL, 0xEB0B991F7AE1C32BULL, 0x237CC0EB15F4C8FFULL, 0xC7A37A854F0C8F3DULL, 
            0xA4D1AF97DE318BAEULL, 0x8AEF65BE67CD29AFULL, 0x1634E4872EC14A22ULL, 0xA34B805A596798AEULL, 
            0x1AFC2EFE2F0A7B5FULL, 0x07A2603F8D0C9813ULL, 0xD75010C8C3F7EB0BULL, 0x77A3125DBEEA60F1ULL, 
            0x11AEF04DDF1457C0ULL, 0x2AD754C651916B68ULL, 0x79C45910366634A7ULL, 0xCF9C51A86484B997ULL, 
            0x6B4EDD6F415C55BEULL, 0x35FEF6E104F34895ULL, 0x83BDAC704AD5EC8EULL, 0x2E2900FFAA817A60ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mothallah::kPhaseBConstants = {
    0xF8646A7F7EC24143ULL,
    0xD9AC321D0C84E635ULL,
    0xE4399735DFE57D94ULL,
    0xF8646A7F7EC24143ULL,
    0xD9AC321D0C84E635ULL,
    0xE4399735DFE57D94ULL,
    0x09C8BEB07491AA6CULL,
    0x00F3B50F25375CF9ULL,
    0xCE,
    0x70,
    0x18,
    0x50,
    0x41,
    0x5F,
    0xA4,
    0xAB
};

const TwistDomainSaltSet TwistExpander_Mothallah::kPhaseCSalts = {
    {
        {
            0xD1AFC527C9B8FE28ULL, 0xDD61769840945641ULL, 0xFC88293CB1B860C3ULL, 0xA0ABF0A424B8F713ULL, 
            0x177A1674B3748B28ULL, 0x7DFFAA3740DEF7B4ULL, 0x49B6D20F25C053A2ULL, 0x9BE8EBAB9C6A4526ULL, 
            0x75DCB7A364D13156ULL, 0x93A2E094943D17CCULL, 0x38E8755B8381EF0EULL, 0xDC7F60D7E513133DULL, 
            0xAA877CA44F33A892ULL, 0xCEBDD9200CEEDC93ULL, 0x48AD260E28163721ULL, 0xF0E859D522A1DD70ULL, 
            0x4937F740A2C9C2A0ULL, 0x39FB9572168CA9C8ULL, 0xC5E775483F3D6AA4ULL, 0xE3EBCDA692E4C9F0ULL, 
            0x0B437FB5D7D27A5FULL, 0x2AD7C9CB358A242BULL, 0x403F7F1C0F4F46B8ULL, 0x7224C8413C792A67ULL, 
            0x4291672745397373ULL, 0xF9E546C747637BCBULL, 0x24718F9423218420ULL, 0xC253564016DB5847ULL, 
            0xC102EF6CEE6B4B63ULL, 0x135410D7481454A1ULL, 0x15C1C37426ED1EF2ULL, 0x20A547EC4046640FULL
        },
        {
            0xA856DC9D6BE7A763ULL, 0x922B208066186B12ULL, 0x20986FDC1783E43CULL, 0x299564DA2FE0A967ULL, 
            0x3B3CC609E3E2BF12ULL, 0x96BCF3CD95FDE8C7ULL, 0x50AA9EE8428C3A78ULL, 0xBC12DD02944681B1ULL, 
            0x77473C3FDDABB4CFULL, 0x7796B12494FAF4D6ULL, 0x9E4B956ADF6DF11EULL, 0xDC528B5AFD6CB8F4ULL, 
            0xFA276214A2F5990AULL, 0xDD50091CCBF23005ULL, 0x15BFEA0001B346C6ULL, 0xBA80B6B12D17327EULL, 
            0x7031AF5793C56C8AULL, 0x9F14E22126535F6AULL, 0x347FB08F7537A883ULL, 0xDE7984AFD42C670BULL, 
            0x8904DCB1A50BBE51ULL, 0xB881FCE7C5F3697CULL, 0xD96106EAD41897A6ULL, 0xEC132603671A6750ULL, 
            0x1AAD76FE848E8FFEULL, 0x5A6F11EE36B74BFCULL, 0xB8A24BF9133D0DCCULL, 0x2ABE4A9D70BDAEEDULL, 
            0x12606993E47AC667ULL, 0x38754A3EA6348CB2ULL, 0xCE0AAAC3EA5E598CULL, 0x5765C649812C1623ULL
        },
        {
            0x994FD9C721A29942ULL, 0x7902A51F7C6485CFULL, 0x8F931E9BD9A4E7BEULL, 0x7D41A826658F6733ULL, 
            0xE565CF71631EEB78ULL, 0xC6A8C02F473221F7ULL, 0xC7A069806098BB43ULL, 0x01E4BF71FFDE617DULL, 
            0x55DC9FA51FAC9F44ULL, 0x37577851627EC26CULL, 0xFDFA2B050F7FDB47ULL, 0xF000B9E6E47AD0BAULL, 
            0x2BF648BA9F236DFDULL, 0x4F6676B7108E6B08ULL, 0x8998717BEBE9797FULL, 0x285EA527D2BE5B85ULL, 
            0xEA810C6DEC09811BULL, 0x78D640229EE94C4DULL, 0x8C82D297849CC742ULL, 0xA49B9D8223814EF5ULL, 
            0x1D184F3E374182BBULL, 0x3EF5F107D59B02F7ULL, 0xC8160679EAAC34B3ULL, 0x99B2A631B64A625EULL, 
            0x1A83F1C728B47E0DULL, 0x82F830B4D73E861EULL, 0x4D596559482A1A61ULL, 0x33C6182F21CA2D76ULL, 
            0x488085F24C18F29DULL, 0x921A4ACF44341334ULL, 0x5DB4644FE23BF61DULL, 0x9143B1EB356F22C4ULL
        },
        {
            0xF8156A2997FEB8F6ULL, 0x19FB659BE83565A2ULL, 0xECB576626E0A84B2ULL, 0xD56D5C19B102164EULL, 
            0x0C335F49ADFB0608ULL, 0xA0BA4B991D956DD0ULL, 0x552AF6D50DAD0853ULL, 0x8C10152EFEF64BFAULL, 
            0x0BFD912A0CCF302CULL, 0xDA5E4FAAC5BD57A9ULL, 0x4C3B2079F7E57D68ULL, 0x8752BC536888EC36ULL, 
            0xE848F2D0AF100158ULL, 0x425D0081568D5DFEULL, 0xC3FE9658D2E62820ULL, 0x577161F9FF18C17AULL, 
            0xD917618E193996AEULL, 0x5DA7369504EBB2C6ULL, 0xA3430CDF47D70994ULL, 0x24E0DD3E579A298CULL, 
            0x0C435A0D9D6075ACULL, 0x40A357F201752BB2ULL, 0x4F7A53749267313EULL, 0x0EC1B0B264993E1DULL, 
            0x056A9C41FE905297ULL, 0x9C5A5A08027688D9ULL, 0x564BC66F31DEDAFAULL, 0x5D4CD145930601DBULL, 
            0xB1838C60ACFED3A7ULL, 0x612BDF4540E0B32EULL, 0x8C8DBB5E194F8748ULL, 0x7E8A2499EE1FF064ULL
        },
        {
            0x03D017D2ECE15A29ULL, 0x8FE6477E5B7D3459ULL, 0xED844B47B2691FD0ULL, 0x26C1087E1FAD14D0ULL, 
            0x94477B2DDD4303C3ULL, 0xBC0583D427FCAEBBULL, 0x20D80C6C419F0C7CULL, 0x04B6FB3106C71F38ULL, 
            0x631E98820200578FULL, 0x5926E12308621CFFULL, 0xBD2DB40AA7AA1CA8ULL, 0xDB98ABC986D25B60ULL, 
            0x05D64C1149962158ULL, 0x263827A8358FAF05ULL, 0xE4CD7B1AE6AECF83ULL, 0xAB3E2B70860A6F58ULL, 
            0xF24ECFE1A1CBF5EBULL, 0x8820FAEA4D793C2CULL, 0x95365EB7AE029743ULL, 0xA3557F8F49F768C4ULL, 
            0xC588B7A4A22795F6ULL, 0x7C7424795C8DCE94ULL, 0x346ECE310E9DC58EULL, 0xA1EDFE9B2A44B2BDULL, 
            0xA2E3121253FB377EULL, 0xBBFF5EE9428B811FULL, 0x9EED413895FBFFFFULL, 0x8F4B2E3D6D091448ULL, 
            0x92C4990B19826A77ULL, 0xD53A96528D17743CULL, 0xFE434DDEB0937F2CULL, 0x608C8E779DC7CC30ULL
        },
        {
            0xA174DE9C2B41E83CULL, 0x5CB4BBCEE14AF48AULL, 0x99A5597FA8DF983DULL, 0xB81A32FA525C2684ULL, 
            0xDFA15222E8681CAFULL, 0xD628D0A4AA94B6DBULL, 0x4827439C6BC2D18EULL, 0x7C05D87F43DC389EULL, 
            0x9AED0E8FE93BD409ULL, 0xF3A07F2B6B4874FFULL, 0xF16FE49F61809253ULL, 0xF86A4343DD1FE107ULL, 
            0x2F185C3F6C683FF9ULL, 0x8DD1BBD1139FF6AEULL, 0xB58099E94EAFE03EULL, 0xE387ECE1D0C9FC4BULL, 
            0x3E5CF714B18BC3EAULL, 0xC117E0FDC6B9E414ULL, 0x37EF96525CF18232ULL, 0x3A367FFD2CBBA0CBULL, 
            0xE34ECF08C4FD5D06ULL, 0x8546855E4BC3A1FEULL, 0x834E4B5B6D1FF428ULL, 0xB96423118ADB6C86ULL, 
            0xB33018B0CC617DC9ULL, 0xBA2EFC39FDDC52B3ULL, 0xAB120164910737C1ULL, 0x82216E210686C1CAULL, 
            0x995DDE4F3E947386ULL, 0x5AB54A945A41EF93ULL, 0xDAB2D52F7C4BB2FDULL, 0x6AA2E8DD0F329CABULL
        }
    },
    {
        {
            0xE89393B145DCEEC7ULL, 0x45C5AFF167393C09ULL, 0x4CAEE2600D5A4D16ULL, 0xB56982A6CB9966A7ULL, 
            0x4A602657110FF8A8ULL, 0x25748FAA67291A20ULL, 0x209E0E12A54A980CULL, 0x535472134F19F80BULL, 
            0x045AF45D9B42C933ULL, 0x84C39EB7E7CF03FFULL, 0x5FE478AA03808313ULL, 0x3A586847D0394DE1ULL, 
            0x8435FA10FB176CD1ULL, 0x68DF3FE1266B6CE7ULL, 0x704F1BEF54E3B575ULL, 0x16BED71F00A25B1CULL, 
            0x3384DE49C615935BULL, 0x0111EDAAB651261FULL, 0x782F07A762B5ABAEULL, 0x1A31A676CFC9237AULL, 
            0xC434F049E6EF47E7ULL, 0x599D89BCD398F05CULL, 0xB1D2699400C28CFAULL, 0x58B8EA57888AC57EULL, 
            0x7271E3C7A12DAAFAULL, 0x0ADBD23E194B52ADULL, 0xE471A02F93873134ULL, 0x93078AC1E939C90DULL, 
            0x8C5BB837C715ECE9ULL, 0x48A1F38AA64D0BEFULL, 0x8973B2EA08DF7911ULL, 0xA110CA165947BC4CULL
        },
        {
            0x7F4FB0BAA0AA7EB3ULL, 0xCB82D66EA4A93D72ULL, 0xBC6AC079AC02620DULL, 0x26EB7436E8EAD61AULL, 
            0x47E28EAFF178E56DULL, 0x3BB956B5375F6ED7ULL, 0x53C0E8203B0421A3ULL, 0xFD703734BB9F0AC7ULL, 
            0x01F087B53672EF21ULL, 0xA6CB836CE7E9D3C9ULL, 0x39473FCD57171359ULL, 0x047719C6F8152103ULL, 
            0xA60E8598D001D0ABULL, 0xBE1702B2CE508C4FULL, 0x2160EE1FEE40AF8AULL, 0x1619205FB020E3BBULL, 
            0xC29D1B936A1D466CULL, 0x7C60A494E99EB8B1ULL, 0x48175A84A6C75F99ULL, 0x70694B54D4BF3A1CULL, 
            0x8E860F9D65B5397DULL, 0xEA96C9951ACE27EAULL, 0x441ECB5594F17AB8ULL, 0xC7EA32FCFB6EF6D8ULL, 
            0xA7FA61FCDA6AD803ULL, 0x7BFF72E10D3E8627ULL, 0x159F4BD03214059FULL, 0x2B09F2B97ADCAF67ULL, 
            0xC6EA12D4B6C40288ULL, 0xB33A589C3218B880ULL, 0x31237B4F870FDF9DULL, 0xB8A1299F5E7E58E3ULL
        },
        {
            0x00A41DC8C1683C12ULL, 0x9858372EFC05002DULL, 0x1956A488576B04F1ULL, 0x9655E13FAC0D90E4ULL, 
            0x63649FA4E478D2E0ULL, 0x4CC5447E40EAF1BDULL, 0xB0A2880764A14390ULL, 0xA603A2D2EA0B40DCULL, 
            0x2C870DACA39D5A2FULL, 0x1968C5FF1A6A860BULL, 0x64E8B4AAA163C57CULL, 0xDCFA7D7E72D4E6A9ULL, 
            0x2E28BC2940D8526CULL, 0x8D8092EDEEF12D1CULL, 0xD08E8F3D51B46FACULL, 0x1E0C3B096F87C44BULL, 
            0x31C8FC78018B74C4ULL, 0xFCD89236A59B684EULL, 0xF4C6E670DFEA3C94ULL, 0xC3A995654F129A65ULL, 
            0x3A3D007F069A4C9FULL, 0x4F0E2D191E7B3E19ULL, 0x8D317E405F50F596ULL, 0xBFA12359D4E1DDBEULL, 
            0x05DED728F4324553ULL, 0x0BE79BA6DCCDB8C2ULL, 0x2E82D32B57455574ULL, 0xDA4A3AF429624D47ULL, 
            0x847E1BC0EF088F79ULL, 0x303C517BA7BA1F72ULL, 0xCB02140EC941DA53ULL, 0xD5AB89D8975E4CA5ULL
        },
        {
            0x1575EB9A83CAE6B6ULL, 0x9BAF929BBEC4D96FULL, 0x623CA2C84DF63AD8ULL, 0x5B6E91696F7521AAULL, 
            0x6C7D6B1E2C3B0EC5ULL, 0xDDF88E4D643AF1CCULL, 0x5A598C1BA98EE7FBULL, 0x1320E3398A7F227FULL, 
            0x1FDDB3EFB35A4030ULL, 0x6C3970CD1B003FB0ULL, 0x29CB29A18DF9009CULL, 0xFB1DF3C626FA79FFULL, 
            0x900EBE4E72ACC636ULL, 0x4059209728669089ULL, 0xE3E278439C8B5361ULL, 0x779B70B27AFE1980ULL, 
            0x730336BF7075B407ULL, 0x481993005F9EFB0FULL, 0x75A1EE97587FDAA4ULL, 0x56A1BEF8D63D199DULL, 
            0xF341FA83BA210F29ULL, 0x3BFD8F12F2F63A94ULL, 0x4A8AB4DC77120538ULL, 0xF6B739538A2EB549ULL, 
            0x80B02C1A9514BB91ULL, 0x5B68199B98BB3176ULL, 0x0F68B6B3DB7A307EULL, 0xF5FC2D5D80BA0165ULL, 
            0xFA85F2C215DF696CULL, 0xB5BE58A5C38B107AULL, 0xE8079CCBA1680A3DULL, 0xCB6C6298493214D6ULL
        },
        {
            0xA6B1C3FF7EEFB887ULL, 0x965A76EF919538FFULL, 0x0C9F42BA75C87D69ULL, 0xF427F1A4E5D33CCEULL, 
            0x79545F84D3E181A1ULL, 0xFE6EB1581B51D013ULL, 0xD7D998400B2F33E3ULL, 0x94B11F59586B8316ULL, 
            0x0711C8780F38E045ULL, 0x253255B9D96B630AULL, 0x3C174C16BEBEB86FULL, 0x1BCDFCBD02A04B1EULL, 
            0xFD498FCA36AEBACFULL, 0xEB76DD488DD308F0ULL, 0xC2FA0DAE3FFA3767ULL, 0x8F3AA0CB98243654ULL, 
            0x27223D19AB87A198ULL, 0x0926C8E39527E5F9ULL, 0x7068A9939CA5BBD9ULL, 0x69F8ABD42CAB5227ULL, 
            0x64736B0F108CD88BULL, 0xE57F144AAFDC0ADEULL, 0x92A1BC7F105872C5ULL, 0xE783778BEED7EAB4ULL, 
            0x33468A9B3A02D2DDULL, 0x6D906E1735F478A5ULL, 0x109887AE857E1411ULL, 0x49D7FD84981BCEE9ULL, 
            0xF2E9FCBCBAAA5024ULL, 0x853CB8EF00285D17ULL, 0xD94039BA881136F5ULL, 0x507DCB9952222517ULL
        },
        {
            0xB0AD44FCB888AE3CULL, 0xDFB30CF9332E0EA3ULL, 0xC52682A3F9E6D064ULL, 0x8AA75DE972E2D5DEULL, 
            0xB684A5BEB9393DCAULL, 0x98FBB803784E4F8BULL, 0x22472C49E592B659ULL, 0x7706D96C093A4C45ULL, 
            0x482E2E39FF97CA15ULL, 0x0E21CF7A47E26AB6ULL, 0xF82E1807C324565AULL, 0xEA085CC712A2D48EULL, 
            0xA6286EED9F489124ULL, 0x6114DEAD9322FD70ULL, 0x1E0D6105540E89BCULL, 0x40CBA73298BD3742ULL, 
            0xCB786B14F928C68FULL, 0x92362234BF7867BEULL, 0x8AEA83F39CC10417ULL, 0x919DE637A16B1600ULL, 
            0xF029242B5953AF84ULL, 0x2B73E4E52CFB6129ULL, 0x129C51CB1EB4C5D7ULL, 0x41A815313C2633D8ULL, 
            0xAEE0866BA778F10DULL, 0xE78E11DFEC7BE8B2ULL, 0xE63A7C45FCF8A521ULL, 0x3B73AB93377D497CULL, 
            0x41593D3197151BF2ULL, 0xA2BD583529E937C2ULL, 0xEA06E557ECF0CBE2ULL, 0xCDC821AA8E7E37ABULL
        }
    },
    {
        {
            0x6C97C7FEB71131A0ULL, 0x6F03ECE8B30AFBECULL, 0xE0086EB430524856ULL, 0x5441E6B9DE9471CEULL, 
            0x3E42E16ACF91B315ULL, 0x2D64E5C3C2B0B48CULL, 0x7C5020FE12533BF1ULL, 0x39A3ADA5F255E5C9ULL, 
            0x7270AD078621CAB8ULL, 0xF96B808656B43DD4ULL, 0xA6CB3893DCC01888ULL, 0xDB4A64B7CEA65216ULL, 
            0x361A11786F256DA9ULL, 0x1808D5B06EA1A686ULL, 0xCB3BD47748957DDCULL, 0x779B95771C7FBEA1ULL, 
            0xBDD09395811E1094ULL, 0xEDEFBB4A328C61ECULL, 0x7BA887782F5E86E5ULL, 0xED260C880D2A30FCULL, 
            0xC437CB45201CC09BULL, 0x58C1664006188863ULL, 0x5F2595C926A5FDFDULL, 0x6968175FE50BD588ULL, 
            0x5F5D460C0C6A5794ULL, 0xC5138DB6657873DBULL, 0xE25FD1783EEBA8D7ULL, 0x9F0E6B4CA815646AULL, 
            0xC147571B2658A9E9ULL, 0x28090F3EA9BCDE81ULL, 0x1B4CC5E001CBE26CULL, 0x75543E22E8FB88B4ULL
        },
        {
            0x60487CC3040BF024ULL, 0x91A4401A374AF309ULL, 0x9E24D9DFD28A4B38ULL, 0x31C43072E98429BFULL, 
            0xAC363C9C9BF286C2ULL, 0x4F7390B087BCAECAULL, 0x3E597FC5EFE4E8D6ULL, 0xFFBC4E855E592F7BULL, 
            0x595A1525AAE34F80ULL, 0x7E272ED2558BC66FULL, 0x55A4C1269CE4646AULL, 0xB7494CBB1836EC15ULL, 
            0xCA874F60AEEFA996ULL, 0xEB826F9784687706ULL, 0x1406B72624EAA740ULL, 0xB54A545B8B62A290ULL, 
            0x8C76811DF383296FULL, 0x80BEAD4E7BD80B72ULL, 0x7F291161814EFBE6ULL, 0xC83B96D63D919B8BULL, 
            0xEFEB926DEFF8B008ULL, 0xBBA23FAD2A1F6DECULL, 0x3739E878AA71DBB6ULL, 0x761C9F800437398FULL, 
            0x6380A2E11C58B066ULL, 0xBD7736CCCB0192FDULL, 0x79DA823631670175ULL, 0xE6554F1A1A7B35D8ULL, 
            0x1A8952FDFE611912ULL, 0xA3002B7AB8ABD358ULL, 0x97EB816DF92F35B5ULL, 0x2700AE24560A5EB2ULL
        },
        {
            0xCE024CB72B4DAA6BULL, 0x979D9709D96F4A85ULL, 0xD096D261DB3D3C02ULL, 0x0C44B60A8370DFBFULL, 
            0x9EBA72ECF9ADA9D3ULL, 0x8F0302C42F98E95BULL, 0x58970B9E6CF51DEBULL, 0x846EEB72EBEF9FC4ULL, 
            0x6AEF67E01AF119B5ULL, 0xCA16A2B1F35FE0ADULL, 0xDC2C17A7FCE991D6ULL, 0xC1A21CE4D5DA4F7AULL, 
            0x25A0B51003366919ULL, 0xA361C669DEF9F166ULL, 0x7CF858784971C73FULL, 0x85AA878F95207173ULL, 
            0xBF27AC36F83F415BULL, 0x33F10C295F66D7DEULL, 0xF09D91921179DD4BULL, 0x449461479EADD77DULL, 
            0x78EF80F5EE218401ULL, 0x8C5ACBFFEFCEBFD8ULL, 0x8257A0ACF2580362ULL, 0xBF6BB468A9161DC2ULL, 
            0x52209FB1B48BDB8FULL, 0x87DC130747300D3AULL, 0x9153526C88526AD6ULL, 0x1C89CAFBD7FF76CAULL, 
            0xB17AFBC1D1D9093CULL, 0xF42CA8EFF84EE92BULL, 0xEE4CDF7CA163D938ULL, 0xE1E00548FE4E6C0DULL
        },
        {
            0x5ED7B50256073DB0ULL, 0x7A24FBED687FBA72ULL, 0x7319E87FAEC9129AULL, 0xF32162DBE36DAD86ULL, 
            0xAEE4144F9ABBF710ULL, 0xF8FFF51CF19108D4ULL, 0x5B65006B95F05696ULL, 0x37B73B620A4C5E2DULL, 
            0x7B5302CE76C62DDBULL, 0x41BB26E6E581C9CBULL, 0x4C11296FEF0A1CDAULL, 0x6EB47862B9D85B12ULL, 
            0x97D83119B4B258BEULL, 0xA53E9D6D29B649F4ULL, 0x399306CCE7F8115AULL, 0xF617A8A11C1F7892ULL, 
            0xAEAED570D917E455ULL, 0xD0620195C20256CBULL, 0x5EA663C96E52E595ULL, 0x10C27DF4769BBADAULL, 
            0x0908734C102F6DD3ULL, 0xF1D302BD9B5B3341ULL, 0x48A7670F64BF6CE3ULL, 0xF00C24809E1606CFULL, 
            0xFA172B0690E6E605ULL, 0x210DFECAD5011D83ULL, 0xA2AA3079534250FCULL, 0xBACE93B8166ADFCAULL, 
            0x7DC25B85F985D980ULL, 0x79D4432B60FF3A77ULL, 0x9918819D698DD581ULL, 0x49F2C30BE618B9B7ULL
        },
        {
            0xE3702D78DACC9878ULL, 0xB66B5C6BD4AEC30DULL, 0xC501E2ED30563F5DULL, 0xFCE21E25573BAAD5ULL, 
            0x93536FB5BAE6A627ULL, 0xCE7E46DFC8222D70ULL, 0x840EB1E1C47DCD09ULL, 0x920CFC08DFEA79E1ULL, 
            0xA08CC1EBE6F4CE5FULL, 0xBD408C5C8090DB9DULL, 0xB4C1F8E3101E7014ULL, 0x67B98F1ACF852AA9ULL, 
            0xD4ECA8C266FE06D9ULL, 0x6C9B5F421DFBF7B3ULL, 0x8E0FCE4E882CF579ULL, 0x605A6A066412AE66ULL, 
            0x6E6EAF800FF7D3D6ULL, 0x16420164885ACA08ULL, 0xA1D4838E8940AC9EULL, 0x55D7CEFE7AB6C7CFULL, 
            0xE652038955603FA7ULL, 0x1686FA409A937542ULL, 0x8BB90F2B637896B0ULL, 0xCD58C3E321F3E503ULL, 
            0x09208CA9D5156832ULL, 0xEB61AB88FEAF6893ULL, 0xABA0F8E19B421D5FULL, 0x65D05A72A1BD3C80ULL, 
            0xE43C3FA4B8321DA8ULL, 0x8DFC15A99CC69DB7ULL, 0xAD688212DDC413DCULL, 0x05EAF1DDEFDF2BC2ULL
        },
        {
            0x853C494DC5EC3D6DULL, 0x317AF714CDFAD5E3ULL, 0x443DB989F2A8A1ABULL, 0xEF7E70CE12D5CE4DULL, 
            0x0A9F1BCDDC895C56ULL, 0xD51E624EAEAC4743ULL, 0x5DEE8833C0831173ULL, 0xD1B9301324C1F6FFULL, 
            0xF5BA294E289ADA6FULL, 0xA1D69FE5D1277C83ULL, 0xCA82CC7ABA8C5B5AULL, 0x5DB7A2DC00B89766ULL, 
            0xF0AE26D5D495DFA9ULL, 0x456E42C196D0D666ULL, 0x09EC39610A99993BULL, 0xC8706DEB66445B99ULL, 
            0xB814E96C1551DB5FULL, 0xE175E7F9B4F8230BULL, 0x17A25A7070231250ULL, 0x2679D4CA8DD9BE18ULL, 
            0x418BD332B0858C1FULL, 0xB5734427813103AFULL, 0xBB851333748E31D1ULL, 0x57D8B596E9438F95ULL, 
            0x502E6E0BC8DAFF71ULL, 0x0D7E395CBA2B564BULL, 0xDBCFA4DE72FA3509ULL, 0xD0670A54767D4491ULL, 
            0x35B1DBE56147600FULL, 0x601E53961110A650ULL, 0xAE6260A0FCDF4CF8ULL, 0xFC8B89A9D930DA10ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mothallah::kPhaseCConstants = {
    0x77C24D8C41F1232DULL,
    0x70C9D1EE035DD1EAULL,
    0xC41B31257CCF163BULL,
    0x77C24D8C41F1232DULL,
    0x70C9D1EE035DD1EAULL,
    0xC41B31257CCF163BULL,
    0xBBBEA1D8F0CB4306ULL,
    0x23646443D99981DDULL,
    0x83,
    0x76,
    0x2C,
    0xAF,
    0x57,
    0x3E,
    0xA9,
    0x5E
};

const TwistDomainSaltSet TwistExpander_Mothallah::kPhaseDSalts = {
    {
        {
            0x61CC68A3687234F5ULL, 0x2C4588959D121AF3ULL, 0x35CCBC909624D799ULL, 0x069F8D8638EBD40CULL, 
            0xA4C596C626AE2F3AULL, 0xA8B6DA38B6E8EBC3ULL, 0x483905A70AFCF53CULL, 0x66571B6F56C18381ULL, 
            0x38A3B571A21D14D4ULL, 0xAED7454645F62CBBULL, 0x0FD64CB98D17204AULL, 0xA6F083D60DE5373AULL, 
            0xEBACE9C777AE1DD2ULL, 0x98103E3F38E81345ULL, 0x62B852E7117648B9ULL, 0xEC660E37290C206FULL, 
            0xC908BC61D2C4F02DULL, 0x0260E6B4BAD2B119ULL, 0xD56AA5C627DF0785ULL, 0x5521111B2DD16A4BULL, 
            0x8252F147FB1102C1ULL, 0x60EB1838AB5E4A64ULL, 0x04CF6360DA20F946ULL, 0x5D70F0D78C43A5BAULL, 
            0x6F9FA07B6548A2DEULL, 0x2C8ACB9DDDD0D8AFULL, 0x739B955A0ABB3900ULL, 0xDBBEE5AAE71E492AULL, 
            0x5112B6C490AF046EULL, 0xF11014C0E6B39162ULL, 0x3A9F4FFCF5B2B096ULL, 0x3D6ABE1322796212ULL
        },
        {
            0x731C044E932809B4ULL, 0x42D1519D8A3067F0ULL, 0xA335329D6646B8B0ULL, 0x5C57238966FA9A88ULL, 
            0x2AF0CFFF4CA17707ULL, 0x020E2BE8875F9F2EULL, 0xCD11FBC59080C14DULL, 0xA20537CC06E8DDD2ULL, 
            0x4F66CF2563F5507FULL, 0x62CC3B142586F811ULL, 0xF0F456E6063B7801ULL, 0x387AC735F83E562FULL, 
            0x3922AA9E512B2D96ULL, 0x2DA2E4A1019C599AULL, 0xFDD8B4C44BF46EE9ULL, 0x54558C158D17CF62ULL, 
            0x0C25F3C914FE0058ULL, 0xE0E6604F95C81AB7ULL, 0x647B2B78B339CEBDULL, 0x27028E4074589A3DULL, 
            0xD6A3E9506FC061CEULL, 0x1AC394B7A97780FDULL, 0xC02DDDF831BCBAB8ULL, 0x856E6FE5641A427BULL, 
            0x5D75ADF80EB81F19ULL, 0xA41291596A5B54D2ULL, 0xDDE01A2ADAF3C8EDULL, 0xB28D72FE1EC02791ULL, 
            0xB20C6D9A11224689ULL, 0xEDE0C7EA646C4AD7ULL, 0x8D68B1F228B7A9B7ULL, 0xB79B1DACADFFBBB7ULL
        },
        {
            0xF74D40F97C966EF8ULL, 0x4807FC3FE79D436EULL, 0xD55972E15DAB32AEULL, 0xF88DE49144121249ULL, 
            0x717C2E92A259A627ULL, 0x38FF1727E31F91D5ULL, 0x524D641D0A582B84ULL, 0x3818E0F807CFA48CULL, 
            0x487ABD0797394E7CULL, 0x8EF7286759F8D8E0ULL, 0x5575682A1C592B92ULL, 0x9AA3183966C49ABEULL, 
            0xAD1A216E7F19C4FAULL, 0x5DCBCA71DE54108DULL, 0x9DBE8265B0841367ULL, 0xE8C9AF97BE5E8B05ULL, 
            0xBDCD7DC3B48BD49FULL, 0x9DCD3A2158C234C9ULL, 0x37AED855B0B3450CULL, 0x385C810B6CE73B71ULL, 
            0x3E48AF8C2F7C011AULL, 0xF127EDA9223A9560ULL, 0x3F7F2579E3F8DEEFULL, 0xB10984C099836779ULL, 
            0x324AC94D015907F9ULL, 0xCDAC0D64DD42D7A3ULL, 0xC23BA7F734B1B9B1ULL, 0x1CA4FA629AC72DF0ULL, 
            0x37824F9CCAB1E9FFULL, 0xE010167CD33B25D9ULL, 0x2DF079A93776386CULL, 0x67285504903A0D37ULL
        },
        {
            0x20F4209F8C43055FULL, 0xB759CEDED405FF13ULL, 0x02C811B2ED43AD9AULL, 0xFC8B7E8A10F7EF5CULL, 
            0x5198E39B2E719283ULL, 0x6EDED1DE16D9AE0FULL, 0x12C25082960B14DBULL, 0x1236E9C11C2F04D7ULL, 
            0xAA20C2622A03D394ULL, 0xCDF1560F295ADEF7ULL, 0x79D08E8660743FF8ULL, 0xC71E99B10FC0CA80ULL, 
            0x2F634C9276EECC66ULL, 0x4F2EDFF4A4D2E480ULL, 0x10CB35B3E069043EULL, 0x13B5A252B1F6F054ULL, 
            0xC92B636B271972A7ULL, 0xD96A5F94F297513CULL, 0xF44BAE6689B5C6DEULL, 0x681F7D0ED9410605ULL, 
            0x6757B35DB708CA03ULL, 0x50F85B854AFC3338ULL, 0xD6B7539BFB491976ULL, 0xA817A3F7B1A1FA47ULL, 
            0x945E760CCE041416ULL, 0x65B788DB1410399EULL, 0xF4091E46AB39924EULL, 0x435B8ED8E276DA74ULL, 
            0x5E075D30732AABE5ULL, 0xAC672B61B87CCC32ULL, 0x25433194AE460C24ULL, 0x10D13A7E2D55C0D3ULL
        },
        {
            0x1D3D110371362CE1ULL, 0xC65C22BF18611871ULL, 0x774F7EA96F512F1FULL, 0x8AEC3D5AE35C6447ULL, 
            0x8155CE95C30742A3ULL, 0xF3311C619ED529A4ULL, 0x4361C73613A977C5ULL, 0x06FDC00E0E90970AULL, 
            0xE16516BCF96E1331ULL, 0x64CB40C597E3DF90ULL, 0xE69102F06D7FAABBULL, 0x9D7631D3F45281AFULL, 
            0x2AD92E930C1FC5C0ULL, 0xF48BA96B3325911BULL, 0x7657D650AC98DF1DULL, 0x54F1B3A4601B855CULL, 
            0xBDEB709DCC101275ULL, 0x058A4C4FCA5BFA30ULL, 0xF3DBDA107AC5DD58ULL, 0x87B1BCD63EAE5D4AULL, 
            0x28BD4771A444741EULL, 0x6B4D335E8F280743ULL, 0x3E24A6F0F03C37CFULL, 0x4DEEDD02699F538CULL, 
            0x71D27E5EDE9D2577ULL, 0x0E9A5C4C52416E73ULL, 0x5DEE1E8DCE43698DULL, 0x26E34A2575942217ULL, 
            0xBDDF42E302B8C016ULL, 0x24DD596521890460ULL, 0xC0D9E786CB9B2C19ULL, 0x2AE3EC8EF921A61DULL
        },
        {
            0x36B810EA4399FEB5ULL, 0xA5F708CEB6476CCFULL, 0xD4FDC3FDDB6DB5A5ULL, 0xCF4E54600F293C23ULL, 
            0x3F78173041816D78ULL, 0x47237E7B90B811C9ULL, 0x68204A61E10FCDEDULL, 0xE1B2265A611CE4FFULL, 
            0x453DD85FF08D8290ULL, 0xAEA62FC7B4C32F9EULL, 0xE23639E215178C45ULL, 0x58C769A8A1922640ULL, 
            0x8B652E8CF7215C1BULL, 0x2C0F76C69316C094ULL, 0x76D7FFF89B038187ULL, 0x2F3F8997F8D5FFBBULL, 
            0x409698A014E39E3CULL, 0x53D9048504D99509ULL, 0x05F3441AD99226C8ULL, 0x67B5B65258795AB3ULL, 
            0xB6AC71842D6A03EAULL, 0x44D7E25EB7D71A57ULL, 0x4F4F9A4F568B313EULL, 0xDA35E8DB7BBB15B4ULL, 
            0xB658B42338DC1666ULL, 0x28447351A29AA2E5ULL, 0xEFB3D1CB1D3E7033ULL, 0x5784C57A866ACAA0ULL, 
            0xD382A3D88C0C8470ULL, 0x1B79952F42144798ULL, 0xE630794E15AD56ECULL, 0xBB04C7FEBD0CFA23ULL
        }
    },
    {
        {
            0xEF5929CB422FB900ULL, 0xDCB69BEE090B8357ULL, 0x58A92AB54CC06F58ULL, 0x196408463FF5D904ULL, 
            0x02828265E891E348ULL, 0x1B1671FD38EA6EF0ULL, 0x8D5BB12B68F9D1B9ULL, 0x5F58C510948B120CULL, 
            0x996AA32FE3B0D27DULL, 0x445DFDE772765CA1ULL, 0xAF8A156D4327B3A3ULL, 0x540058C191A831C9ULL, 
            0x185A6E79D1E00EABULL, 0x45E91D1432E67D8DULL, 0xBF121CD00B863F2EULL, 0x8764BE8178CE8394ULL, 
            0x8D7779E33E8F9DFBULL, 0x8A2188BB87F46929ULL, 0xD3AF8FB0F80918D6ULL, 0x3AC23A7A71B39D4BULL, 
            0xB5815F2BC4877D3DULL, 0xF508732F9E49E1E4ULL, 0x4E234647DA42780AULL, 0x13A05118FF1CFAF4ULL, 
            0x35B1D4F23A4C6C3FULL, 0x614622FAAAFA4775ULL, 0x6191920FBDBB02BBULL, 0xE7E7D415AE375ACDULL, 
            0xD9F274BC23CC0A14ULL, 0xD988D90E33BE30D0ULL, 0x258485F9C1C892ACULL, 0x6D4593E6B417F45CULL
        },
        {
            0x6978B37F778A22BCULL, 0xB1C0C7B7EEA40EC4ULL, 0x54EE58A5EFF759C0ULL, 0xCE6659DED7AAEA0FULL, 
            0x8D43D5929EAB5CFFULL, 0x1D34C4B2DD92DA36ULL, 0xE6AB5484EBAD64EAULL, 0x0484D0A3DBC6DC91ULL, 
            0x64C36BDE605F6220ULL, 0x91A838974690C06BULL, 0xF07FC310941ADBBAULL, 0xE00544175F2A1B75ULL, 
            0xE68B73BA35F4A83EULL, 0x9A0C5D8444DB52E8ULL, 0x84B726AF7C3A2D71ULL, 0x1E966D3CF22AFC8BULL, 
            0xDCEBEB2FE7972B73ULL, 0x706B7688A6DCCF5DULL, 0x0C226295FF3026FDULL, 0x1526FE558E195D2BULL, 
            0x206F914D03DA5E79ULL, 0x04616E3682516F40ULL, 0x6E1F12E282162EF7ULL, 0x6277031234D124DDULL, 
            0x341156F7BDD5A986ULL, 0x9DACB2A08AA6CBDBULL, 0x9DA2DD3C7D0DA202ULL, 0x71B409C3D9A9FD67ULL, 
            0xBE38C25D2385F427ULL, 0x226369FAD7C21AC0ULL, 0xE230E800C3EC148CULL, 0x5FFFF09EB1418241ULL
        },
        {
            0x18625BB1BEB1F15FULL, 0xE511EBC7BD97D381ULL, 0x5D59CC3994B387F6ULL, 0xCD818E604013AB2EULL, 
            0x97E9072876FAB28EULL, 0x2A307CAF2F9C9336ULL, 0x54B1636816A6844EULL, 0x68EEAE62A7833822ULL, 
            0x4769D3D23158D690ULL, 0x2D52DD3700AAA74CULL, 0x4334C490C30BEFCCULL, 0x5D6813BE767D3670ULL, 
            0x9C01C62EC98E727DULL, 0xD30D5A8259F2570AULL, 0x734622ADC1E58295ULL, 0xA464268C0AECFB4AULL, 
            0x1D91F8ABA8D85FB5ULL, 0xF4DDF2853EB81B9DULL, 0xF8CA9893C4453AC1ULL, 0x0DBD1727B65E03D0ULL, 
            0x3EE00A2A2B3088E7ULL, 0xF604C471C29B3B6DULL, 0xC09AFE34CF9D2D76ULL, 0x99864E8E7AC6DE39ULL, 
            0xB3BCA1E5D013A5CBULL, 0x368BEBB269008AACULL, 0x670113014471F086ULL, 0x57FA8F5AA5C0FB32ULL, 
            0x38B882D990149F5EULL, 0x5B66D50E5A8243F4ULL, 0xFE6C7901FFDB4A5DULL, 0xAB5BDDBF61936D8CULL
        },
        {
            0xECDFE4A8BF6F9354ULL, 0x44AFE478D85467E8ULL, 0x5BF76BF212A1DA4AULL, 0x39DC1F412FD1F19AULL, 
            0x7C2B806E97BD10D6ULL, 0xEFF48F01FCC7935DULL, 0x7C6D2C2B94301C21ULL, 0xE02A223412AFD248ULL, 
            0xE5D6CE5D7292EB59ULL, 0xCC79B25525B47969ULL, 0x32F3D7DDF19156F0ULL, 0xE0F925740C81F908ULL, 
            0x02F9EB3F4FB62C0FULL, 0x9710338F4FB0FDD7ULL, 0x7CBA6530AB53631CULL, 0xC19480BF1CD20059ULL, 
            0x5CF9EF1EA3387546ULL, 0xC2070D9D32527E89ULL, 0x1ECC72C26ADBB7B0ULL, 0x68720876D269981DULL, 
            0x363B38942A135CB7ULL, 0xE44411E0CF984FA4ULL, 0xAA790BBB76280E48ULL, 0xF4759945B2096947ULL, 
            0x93C56913DF0465BEULL, 0x0577619FB7F29D96ULL, 0xEB32502350B587A8ULL, 0x965D4660F7D46F48ULL, 
            0xB0411B2B5E490D92ULL, 0xFB3E73DE8BBB0E14ULL, 0xA7B69DFC407B3301ULL, 0x75D36FE5AA9DBCEEULL
        },
        {
            0xB4520C9BBB553464ULL, 0x4D6DA01C4DB4AB95ULL, 0x5DE2DC3C83A73B16ULL, 0x9BDA067AD633A80BULL, 
            0x42BC2675948D9013ULL, 0x221741BA950C8854ULL, 0x48EE96E1217107B3ULL, 0x1CDB46B7152AE66BULL, 
            0x92BF4430EE4D09E3ULL, 0x58349B6392E6EEB4ULL, 0x230CC43AB8CBAC49ULL, 0x0F030E88BDEC7440ULL, 
            0xA9ED97A4016464C0ULL, 0x3B3FEEFD77C308A7ULL, 0x773714818FD81578ULL, 0x53C1A327BA504FD2ULL, 
            0xF352061B5A36DD4BULL, 0x6D30A72D61F1718AULL, 0x4B4D9172103166DEULL, 0xBC81CAD85E819DEBULL, 
            0x47B7F5DE9186BB89ULL, 0x9884B6D477EC443DULL, 0x3F070B9BA856EB93ULL, 0x9FCBB286492E8564ULL, 
            0xF22F105B6546C154ULL, 0x5AEA555E9C59E7FFULL, 0xD50A952CE91A251FULL, 0xE6C2FC49FF6F40EEULL, 
            0x4AE874606117A805ULL, 0x8985F110F0DD1D36ULL, 0x5486791A23C5579BULL, 0xD8EEED4786CE9462ULL
        },
        {
            0xD3662C79835C2FB6ULL, 0xB9BD393C999AC263ULL, 0xB3EBA2EC923498DAULL, 0xD8C43914EDBC32C9ULL, 
            0xF4CE5C775FED72F1ULL, 0x72E657D064EB12A3ULL, 0x3D36F286A222FB71ULL, 0x69F8249687243D14ULL, 
            0xCA14EE8FF2D4A838ULL, 0x0D2D109D8CAF0059ULL, 0xCF8C81B75A776366ULL, 0x8C1B189812E199D5ULL, 
            0x4F16230FE71439DBULL, 0x51778082F45F67E2ULL, 0xDF9710546AC5F2D1ULL, 0x57672C8A226A26DEULL, 
            0xA9E8628C0E672A1BULL, 0x15303A2C4200E2F4ULL, 0xFA76610B70C2089DULL, 0x44DAB42F41069660ULL, 
            0x07396A9EFC0E631BULL, 0xA916D70C791293C4ULL, 0x5D89A053093A7140ULL, 0xABDAA498716C7342ULL, 
            0xDD678226AA37BFC7ULL, 0x41C7F53E1A727995ULL, 0xA2BE37756F364E6DULL, 0x2D7B2B3F05ECFDD0ULL, 
            0xB8EFC49618C9DBB6ULL, 0x1AFD4DDB25D17E0BULL, 0xE6383DFEE098769EULL, 0x6343469963F10257ULL
        }
    },
    {
        {
            0x943182A087207E66ULL, 0x765C75279FCD28A6ULL, 0xE05F2F4531456557ULL, 0xBCB2F0F3ABF913ADULL, 
            0xA622E62A2CC4E263ULL, 0x225F7A792EE4BF98ULL, 0x67D955A280267BA8ULL, 0x9AA09FF15B8982A2ULL, 
            0x3546AD77EBA62F3DULL, 0x97A407B80A9CD26FULL, 0xA955EB987B9EA644ULL, 0xB7214ED7B4B4450DULL, 
            0xE79E3CFB84E5B4DBULL, 0xBE64F4A90AC797E2ULL, 0x8E9B38B9620156BFULL, 0xA5E5B295E0C164F7ULL, 
            0x270A3B3BC6D23E2BULL, 0x1F73AE83C6565844ULL, 0x3719C8D9669F70F6ULL, 0x0E7F6F760F418B4EULL, 
            0xCF3DC1F530F48A49ULL, 0x046611012F87ED77ULL, 0xB14213C93061AA6AULL, 0x51F6BF232AC8FBAEULL, 
            0x7510256B8FA0B2AAULL, 0xD45B3F0627FBCAF1ULL, 0xAC1B1579157B5F33ULL, 0xB21A07EEC721EDC4ULL, 
            0x80E6D312CE6D7BF3ULL, 0x3A0FFD7C45F9AE55ULL, 0xC74468912809E2C9ULL, 0xEBC8543DEA40DB21ULL
        },
        {
            0x3A82451319D9CEC9ULL, 0x9F92945F879E1583ULL, 0x44B08D3E7DF1194DULL, 0xB546F4C051C6DAE8ULL, 
            0x2E2D760A77BB6AB4ULL, 0x410DA34A6D243B2DULL, 0x22742138ECB2E7B3ULL, 0xC9CD15AA28E53615ULL, 
            0x12B61E92B4F35B80ULL, 0xAA3F715CE92590FEULL, 0x0E6F8F5B185E6BA5ULL, 0x6867DEC3AF5E99E4ULL, 
            0x7D9D2A3910042B59ULL, 0xC8EAF210F0A1DAACULL, 0x90BBE20E23541441ULL, 0xC4C25C44184BB9E3ULL, 
            0xB8920903CB30375AULL, 0xC2284ED287FD5DDEULL, 0x59FB8B7ACE6B42F3ULL, 0x5D51048DFF6428C4ULL, 
            0xFC68B56368BBE270ULL, 0xD61627668CA643C0ULL, 0x71CC7C87C65D72E1ULL, 0xD0BE5AE1B4EC3BC6ULL, 
            0x3C832C53DBD74246ULL, 0xEAFA897B3B7CB3E4ULL, 0x6F070E2459262955ULL, 0x2AB2D633638EFCC5ULL, 
            0x79CEF9579632F66BULL, 0x1A6972241C81147EULL, 0x61425C46364DC91BULL, 0xDCF8FB6C22F83DE7ULL
        },
        {
            0xF52611BBAAF492C8ULL, 0x72E992894A6D4459ULL, 0x35C1FADC806B375EULL, 0x87103B70C1A878BBULL, 
            0x26C4A949A3A2AA2EULL, 0xB2005CFFD503385DULL, 0x1D32C5168953685EULL, 0x4ECCA57B4B748B56ULL, 
            0xFCE3335A100FEDC0ULL, 0x268DAF746796ED3BULL, 0xD5CB8C8159ACB854ULL, 0x5D26CCAB3B744DB1ULL, 
            0x073D9AC6147F56C8ULL, 0x61B4EF82BAC875F1ULL, 0xA17A6281FEBAC015ULL, 0x031F5E8D5DB73F8FULL, 
            0xF6181BBC6B954C0EULL, 0xC34C291E29D9A46CULL, 0xDAB7A3FB9DAE000FULL, 0xA8DF59E723BF1A16ULL, 
            0x134FD901E84A7594ULL, 0x614E3433C15C700AULL, 0x2EEDBC9AB262EBB0ULL, 0xCDDD71D94C47FEBEULL, 
            0xB7B037DBA059CE33ULL, 0x1327BF72CFDD2340ULL, 0x569FCB9E744B6CD0ULL, 0x6B5D435E5C2C11FCULL, 
            0x1CA46EF3B9FCE165ULL, 0x2BC2E56D67C2E2DDULL, 0xCA4E3179D7FF3B36ULL, 0xD3071FD6063F21B1ULL
        },
        {
            0xDF8BA816AEBBB9DFULL, 0x79AC94922E4BA107ULL, 0xBE6636C2E63272C8ULL, 0x26807832FDFFCCD8ULL, 
            0xEAAB8F8F7C631D38ULL, 0xFA9DB4B69279CA85ULL, 0xA3440BA0AD31913CULL, 0xCAAE40047CC0309DULL, 
            0xCA7D0FFADB209CAAULL, 0x53C1B63532FE5BAEULL, 0xCDFA7341EBED1CB5ULL, 0x6C1FE744BDA02805ULL, 
            0xD1640CB786996678ULL, 0xD46ED22C2E32CAEBULL, 0x2E8CBD9F889A0F35ULL, 0x0F3CEDC686C6C804ULL, 
            0x14EE2CFEF80A4474ULL, 0x7CDA481BB820B1D5ULL, 0x65CC4AE741D48500ULL, 0x990AEF87BDA8B548ULL, 
            0xF6349F03E7D4B7A0ULL, 0x4B38512B571E439CULL, 0xB62A3EBEAB206690ULL, 0x6439C96B80FD5820ULL, 
            0x0371718D2BB25D1DULL, 0xC614A2790FF2ED94ULL, 0x3758B0D442A00ED9ULL, 0xE7A4C6526921CA08ULL, 
            0xC72930BE8ABEB669ULL, 0xAB42BD2E5D0C4914ULL, 0x22BEEA53517561B1ULL, 0xD036FB04E7DDF134ULL
        },
        {
            0x1A49BC74DDFC7526ULL, 0x9ADAA0CBF40C7F84ULL, 0x8FA9F2F030A990FFULL, 0x45F60FE97432AEFDULL, 
            0xB5EB862D84ACDE2EULL, 0x47475814AC618C3DULL, 0x5258C07BF0496C8AULL, 0x1599482B56845E48ULL, 
            0x2E37DE08891492F0ULL, 0x7719C79FFF9C0365ULL, 0xB027670F1A10030AULL, 0xF74ED57364D6CC66ULL, 
            0x3B77DE3149404CA3ULL, 0x64C4943B1AE6E12AULL, 0x8B6BAB39A486649AULL, 0x20B36220285EF864ULL, 
            0x972278A433377320ULL, 0x7392C6125E8CE30EULL, 0x8D078A69B9AE51F2ULL, 0x11F8B99E638F2159ULL, 
            0x76DF6245D3096A92ULL, 0x1B3C621BA4D75032ULL, 0xFDB40E723BF7C7B9ULL, 0x97FF3B97BB64108CULL, 
            0xB2CAA1B15EC512C6ULL, 0xD401E098A74A7586ULL, 0x0243BCF4C53F1125ULL, 0x6821D3D48A85466CULL, 
            0x0E7D22863E0E3BF4ULL, 0x71E8DD5DADED2214ULL, 0x9985A702E3DC6E92ULL, 0x8B99A9E7891F3C2EULL
        },
        {
            0xA596D0DDFDA7365EULL, 0x2E998910458396CBULL, 0x952F40C663C38162ULL, 0x666C54C45203C46BULL, 
            0x76F87D2090341727ULL, 0xF651A670C2737892ULL, 0x8216EDB993CA5EFBULL, 0x79D0FD4083D118A5ULL, 
            0x77A62AA1C5030068ULL, 0x63BEDC4724A721A1ULL, 0xD4343DFC46D63A77ULL, 0x6A360F2604AE7430ULL, 
            0xA6C65D2E74F2ACFEULL, 0x19B9BD16CED6EA2AULL, 0x371DD6F97E66DC12ULL, 0xC1EFDDFA94296108ULL, 
            0x62D824761AFDD761ULL, 0x25115877CC8B36B2ULL, 0x76AF548FC3B3E892ULL, 0xCC7E90FDAD27A97FULL, 
            0xE54E64D27FD05705ULL, 0x2EEA73B9FDB621F5ULL, 0xDF5A3F160C620EADULL, 0x618D5F7BE3E36434ULL, 
            0xC7920A2B2DA87EDDULL, 0x8A398FB6E0DE83A0ULL, 0xD1DD3137C40C028DULL, 0xFB3CFF3F474A9429ULL, 
            0x2CB670113480FA89ULL, 0x56D9547387330BCFULL, 0x77C56B2C897E60D4ULL, 0xEC814AF0BB670BEAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mothallah::kPhaseDConstants = {
    0x33E346A2BB6805CFULL,
    0x08B2D91F62975FAFULL,
    0xDC037E908FEECCA0ULL,
    0x33E346A2BB6805CFULL,
    0x08B2D91F62975FAFULL,
    0xDC037E908FEECCA0ULL,
    0x5566B63BE3843C05ULL,
    0xAA17112999E904FDULL,
    0x49,
    0x41,
    0x95,
    0x6F,
    0x22,
    0xC9,
    0xAE,
    0x43
};

