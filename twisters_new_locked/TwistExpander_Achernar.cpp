#include "TwistExpander_Achernar.hpp"
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

TwistExpander_Achernar::TwistExpander_Achernar()
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

void TwistExpander_Achernar::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF6EE18F992902EABULL; std::uint64_t aIngress = 0x98B19122BF0F4335ULL; std::uint64_t aCarry = 0xA864C51C44E164D6ULL;

    std::uint64_t aWandererA = 0xD50484C611B184E1ULL; std::uint64_t aWandererB = 0xF74C67F9C36D02A9ULL; std::uint64_t aWandererC = 0xE5D90C5A0CD3BE27ULL; std::uint64_t aWandererD = 0xFBD84A3DE83CC0E7ULL;
    std::uint64_t aWandererE = 0xF31F15711CFA5D99ULL; std::uint64_t aWandererF = 0xA115C16524880F99ULL; std::uint64_t aWandererG = 0xAA9B75E27FC6E12FULL; std::uint64_t aWandererH = 0xED806E57BECFAB01ULL;
    std::uint64_t aWandererI = 0x808568FC1B56D917ULL; std::uint64_t aWandererJ = 0x8BECBC3ACC9A6DA2ULL; std::uint64_t aWandererK = 0x97BF8ED026AC2B37ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xEC9552A2DCB39F5FULL;
        aCarry = 0xD63DC99CD1FA5AE5ULL;
        aWandererA = 0xBD105266263884DFULL;
        aWandererB = 0xD487FCB0B13F2A60ULL;
        aWandererC = 0x80D2AAA004B238E9ULL;
        aWandererD = 0xB168FDD248B14C68ULL;
        aWandererE = 0xB7CA93BB4A849E7AULL;
        aWandererF = 0x8C4A899CD3086C21ULL;
        aWandererG = 0x89685661B137C9F3ULL;
        aWandererH = 0x966642F065AB752FULL;
        aWandererI = 0xB6C0D6A0ECE86A01ULL;
        aWandererJ = 0x83CD30DBA7F02A88ULL;
        aWandererK = 0xB38DB12E581398B8ULL;
    TwistExpander_Achernar_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Achernar_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Achernar_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Achernar_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Achernar::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE1582C3465EA7C71ULL; std::uint64_t aIngress = 0x98F72EAF447694F2ULL; std::uint64_t aCarry = 0xAC4A5C7E511BAEBFULL;

    std::uint64_t aWandererA = 0xE9C50E993E98ABCFULL; std::uint64_t aWandererB = 0x86F3180868F4576FULL; std::uint64_t aWandererC = 0xB3BAF9943AAECEE3ULL; std::uint64_t aWandererD = 0xF60E377EA54762E7ULL;
    std::uint64_t aWandererE = 0xC1F11625B90E128CULL; std::uint64_t aWandererF = 0xA02A91F52FCC5CD4ULL; std::uint64_t aWandererG = 0xBAFFFA03FA12A286ULL; std::uint64_t aWandererH = 0xDF70ACF41B0E2C89ULL;
    std::uint64_t aWandererI = 0xEDD30CA50250CC65ULL; std::uint64_t aWandererJ = 0xDC2CEC9B210ED7E0ULL; std::uint64_t aWandererK = 0xF1915A68B3942F7BULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xC541217444152B6FULL;
        aCarry = 0xD064ECA9B28F7CB2ULL;
        aWandererA = 0x802D36165AA096A3ULL;
        aWandererB = 0xF4041AB952925334ULL;
        aWandererC = 0x8965F75479E02967ULL;
        aWandererD = 0xE22658299360237AULL;
        aWandererE = 0xE864FAF8C8A15712ULL;
        aWandererF = 0xE50C9E3DFC2F41EDULL;
        aWandererG = 0x8898969B8BF718A3ULL;
        aWandererH = 0x9FF315D22E24F566ULL;
        aWandererI = 0xAD3F4F4DF6115565ULL;
        aWandererJ = 0xBC28682AF92D6B89ULL;
        aWandererK = 0xE3D20EDA8F2D7DE7ULL;
    TwistExpander_Achernar_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Achernar_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Achernar_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Achernar_Arx::KDF_B_D(pWorkSpace,
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
    std::uint64_t aPrevious = 0xDA375A5AC52F8704ULL;
    std::uint64_t aIngress = 0xDC9473F76C638D95ULL;
    std::uint64_t aCarry = 0xCE0B0E1F8908E310ULL;

    std::uint64_t aWandererA = 0xF297B21DB094DF93ULL;
    std::uint64_t aWandererB = 0xFBA60266BAFB4359ULL;
    std::uint64_t aWandererC = 0xEF4C2DB2ECBC311FULL;
    std::uint64_t aWandererD = 0xD3B36A407A4C5793ULL;
    std::uint64_t aWandererE = 0xF4B6A8F495F26EF4ULL;
    std::uint64_t aWandererF = 0xB898CD55B1769D23ULL;
    std::uint64_t aWandererG = 0xCD1132A6BF8FE201ULL;
    std::uint64_t aWandererH = 0xC44A8080D40B193EULL;
    std::uint64_t aWandererI = 0xD282F7EB465105D9ULL;
    std::uint64_t aWandererJ = 0xC0190D619FEF99C3ULL;
    std::uint64_t aWandererK = 0x915E0C13E1D6598FULL;

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
    TwistExpander_Achernar_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Achernar_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Achernar_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Achernar_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Achernar_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Achernar_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Achernar_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Achernar_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Achernar_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Achernar_Arx::GROW_B(pWorkSpace,
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

// SmartSquash candidate 1 of 33
// Exploration cases: 100000000
// Diversity score: baseline candidate (no earlier family member)
void TwistExpander_Achernar::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    static_assert((S_BLOCK / W_KEY) == 16, "SquashInvestToKeyBoxes expects 16 invest fragments.");
    static_assert(H_KEY == 8, "SquashInvestToKeyBoxes expects 8 key rows per box.");
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 14U), *aFragmentB = aIceLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 6U), *aFragmentD = aIceLaneD + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1639U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 313U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 698U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1781U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 6U), *aFragmentB = aIceLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 12U), *aFragmentD = aIceLaneD + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 706U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1603U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 525U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1769U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 2U), *aFragmentB = aIceLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 0U), *aFragmentD = aIceLaneD + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1581U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 989U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 516U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 633U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 7U), *aFragmentB = aIceLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 11U), *aFragmentD = aIceLaneD + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1145U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 990U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 126U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1430U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 5U), *aFragmentB = aIceLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 9U), *aFragmentD = aIceLaneD + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1793U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1531U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1778U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1801U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 1U), *aFragmentB = aIceLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 8U), *aFragmentD = aIceLaneD + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1080U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 165U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 40U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 48U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 11U), *aFragmentB = aIceLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 14U), *aFragmentD = aIceLaneD + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1779U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 360U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 27U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 777U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 0U), *aFragmentB = aIceLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 3U), *aFragmentD = aIceLaneD + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1162U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 834U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1214U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 930U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 15U), *aFragmentB = aIceLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 15U), *aFragmentD = aIceLaneD + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 183U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1454U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1734U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1787U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 13U), *aFragmentB = aIceLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 13U), *aFragmentD = aIceLaneD + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 194U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1348U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 864U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 278U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 3U), *aFragmentB = aIceLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 4U), *aFragmentD = aIceLaneD + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1387U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1092U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1668U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1817U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 10U), *aFragmentB = aIceLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 1U), *aFragmentD = aIceLaneD + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1890U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1043U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1600U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1718U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 9U), *aFragmentB = aIceLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 5U), *aFragmentD = aIceLaneD + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 474U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1228U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 527U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 675U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 8U), *aFragmentB = aIceLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 10U), *aFragmentD = aIceLaneD + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 177U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1622U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 85U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 483U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 4U), *aFragmentB = aIceLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 7U), *aFragmentD = aIceLaneD + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 861U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 34U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 169U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 790U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 12U), *aFragmentB = aIceLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 2U), *aFragmentD = aIceLaneD + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1188U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1464U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 854U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1854U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Achernar::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD06EEF1398A5211CULL; std::uint64_t aIngress = 0xB1C46E94D34C9AB3ULL; std::uint64_t aCarry = 0xCBE7D800C1F741C1ULL;

    std::uint64_t aWandererA = 0xFA52EAAD691A3F14ULL; std::uint64_t aWandererB = 0x8A71C4DD177D081EULL; std::uint64_t aWandererC = 0xC49CDFE4F672CEFDULL; std::uint64_t aWandererD = 0xBA23EA94DDDA1F54ULL;
    std::uint64_t aWandererE = 0xACF642F47E59F477ULL; std::uint64_t aWandererF = 0xDFB3D4D102AE79BCULL; std::uint64_t aWandererG = 0x9BA82A733A875390ULL; std::uint64_t aWandererH = 0xBAC33EDFA18D1863ULL;
    std::uint64_t aWandererI = 0x856C60EDB3E6598DULL; std::uint64_t aWandererJ = 0xEBBD2F61FB56D0CAULL; std::uint64_t aWandererK = 0xA6D2C1C26E260EB9ULL;

    // [seed]
        aPrevious = 0xA03726EE015BC28CULL;
        aCarry = 0xEC025C0AB8A4421EULL;
        aWandererA = 0xB7B14A8300815536ULL;
        aWandererB = 0xDE3F23091C38F44FULL;
        aWandererC = 0x804C3BF031F34790ULL;
        aWandererD = 0xCD02564DAEBF38D4ULL;
        aWandererE = 0xB21A738F7F5EB260ULL;
        aWandererF = 0xCFDC5B93AE9BA1E4ULL;
        aWandererG = 0xD72D1C74EA27306BULL;
        aWandererH = 0xF936EDE6AFB4BF5CULL;
        aWandererI = 0xD2395C7CD99DC216ULL;
        aWandererJ = 0x92C4E069620A4E1FULL;
        aWandererK = 0xA0932894E1BB934FULL;
    TwistExpander_Achernar_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Achernar_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Achernar_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Achernar_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Achernar_Arx::Twist_E(pWorkSpace,
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
        TwistSquash::SquashB(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, pDestination);
    TwistExpander_Achernar_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Achernar_Arx::GROW_B(pWorkSpace,
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

// GrowA candidate 1 of 33
// Exploration cases: 100000000
// Total structural distance: baseline candidate
void TwistExpander_Achernar::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1255U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6354U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1878U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2148U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6739U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1069U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3370U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1422U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5071U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 560U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3627U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5330U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 753U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5731U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6626U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3580U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 387U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 286U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1985U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1114U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 401U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1071U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 316U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 526U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 767U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 517U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 659U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1807U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 507U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1109U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 96U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1030U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 485U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1346U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 966U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
}

// GrowB candidate 1 of 33
// Exploration cases: 100000000
// Total structural distance: baseline candidate
void TwistExpander_Achernar::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1199U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 704U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5970U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3590U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 63U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6818U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7190U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7332U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7148U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3049U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2557U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1609U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4023U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6964U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7875U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1082U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 757U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1378U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1274U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 383U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1568U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 884U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1857U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 429U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 300U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1763U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1137U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 504U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1868U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1046U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 448U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 480U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 667U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 947U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 250U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 345U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
}

const TwistDomainSaltSet TwistExpander_Achernar::kPhaseASalts = {
    {
        {
            0x63F57D05F4BA97E4ULL, 0x262AEAB7D872AFF9ULL, 0x9117E90683C150CBULL, 0xB5E5473D44BB07DBULL, 
            0xB9FD0509D319B777ULL, 0x39C222F175CCFD4EULL, 0x8DB1EF113869AE21ULL, 0xA7735A8B158C36DEULL, 
            0x0AC1A895F1A6591AULL, 0xDC6B6F48B6E1E0CAULL, 0x44EC9BF6FCABC7D1ULL, 0xEC93835F3322371DULL, 
            0x83690CC63EC833F0ULL, 0xCC92F16B57476FDFULL, 0x73C8F4BD17B5A951ULL, 0x266AA3730C66119AULL, 
            0xE708B3E67B720B2EULL, 0x1E4AC66C1E01246CULL, 0x8F36BB572E2391EAULL, 0xC6F427277ABF89E8ULL, 
            0x3ACF1C006D79B953ULL, 0x68E474807C4F7A80ULL, 0xFEC7BB3C4359726AULL, 0xD388F25A4A252B98ULL, 
            0xDFD76B91C6898181ULL, 0x1D9BED8B85415842ULL, 0xFE19F45EF67B0D8CULL, 0x21D5022EB9F65CDBULL, 
            0x6EE237390DBE3124ULL, 0x7184E53BC30CD250ULL, 0x0C03CDA9CFA72E19ULL, 0x01B85D83BF1018D7ULL
        },
        {
            0xCD03BB83FC461543ULL, 0x938E876124CC7469ULL, 0x600066343B3FE735ULL, 0xCFB66A5F7949BE62ULL, 
            0xD7BE1307644C9926ULL, 0x17083DABA4C89CCDULL, 0xFB54D830CCFFCC74ULL, 0x6E14FE638CFDCA13ULL, 
            0xF7FDC5E0379BE57FULL, 0x2BC7D166C99F9267ULL, 0x8763635080FC8757ULL, 0xD3F9F8BFA6D7D873ULL, 
            0x68026EAC316E13CBULL, 0x6679123E6628C922ULL, 0xBC071C6D97A38078ULL, 0x53E81CA09A4555B3ULL, 
            0xDD9641DA18C1E5FBULL, 0x2A89A385E444DEE7ULL, 0x26200481162887A1ULL, 0x480363825476EFD8ULL, 
            0x59B054E22FC9454AULL, 0xCB3806764C6DCA3CULL, 0x4D6A7C788EEE485BULL, 0x9563D2C3E37A2935ULL, 
            0x4755A50C778A23AEULL, 0x91F33002C87866A5ULL, 0x9215F8DF0E185A6CULL, 0x06B55B372AEE256EULL, 
            0xACFA13CF5D6433E7ULL, 0x12D54E5045980CABULL, 0xEEFAD1EE5C90997AULL, 0xC5AC201B33449EB6ULL
        },
        {
            0xC088AFC4ED5ED499ULL, 0x797AC9620BE7A53BULL, 0xA3AB49CCD97679BBULL, 0xCEF2A2B0704D90AEULL, 
            0xCC45B0ABAE60B309ULL, 0x51B7BB3BF932E3FFULL, 0xA6249AA17122C644ULL, 0x10B352BADF421EEEULL, 
            0x3E0C10F631892E0EULL, 0x79ADCC665B11B348ULL, 0x52C8B6FC47BF19CCULL, 0xB2DC6A7BD2D7D320ULL, 
            0xF28721B32D7C0080ULL, 0xAEDB32E8672E95A0ULL, 0xF6271EE5D075017BULL, 0x6195B947FE5879D4ULL, 
            0xB5C185AF16B150B0ULL, 0xFADE8D3B844F6E9EULL, 0x7B510D886F29FB69ULL, 0xD5005D393A847E62ULL, 
            0x438B41A4B197DDDCULL, 0x7D0B458E761F010DULL, 0xCC5E2BB346FA9DA3ULL, 0x5F31C5BFEAF4FAA7ULL, 
            0x5292F3A520066C5DULL, 0xDFAF9001FF6542A6ULL, 0xA1EFD4330D8896A9ULL, 0xE64B333CC0197AB6ULL, 
            0xB866DF3FEFF643A4ULL, 0x5F2794B192759CB7ULL, 0xED8CC44AC4D95D44ULL, 0x2436207B6F8937BBULL
        },
        {
            0x155E7659C90FEA22ULL, 0x5CDD4F01DBCAC74BULL, 0x50307E4033E8EE4CULL, 0x4C09C3B0A19C1709ULL, 
            0x2EAE3963AE98CED6ULL, 0xE3BF24CD3265B24CULL, 0xCAB2F4C69B2C8212ULL, 0x2D1D63AEA6864C56ULL, 
            0x33A9AEE79A76E95BULL, 0x81B57FE31BE3D52AULL, 0x48950AA6CBB7C9ABULL, 0x98EFC967860AE6DDULL, 
            0x74073928EA1C1A7DULL, 0x1D24C8120477555FULL, 0x176F483C1C003951ULL, 0xFB9D668D1B202F6CULL, 
            0xD004A06E534FC4DFULL, 0x5DF6B8A272625257ULL, 0x4B161D7E56D13E94ULL, 0x972F4EB6B733BA96ULL, 
            0x05E52EA92954E45AULL, 0x5435803BA8D0050BULL, 0xBB79B43019E7F02AULL, 0x1F94EB9D82B5CFEDULL, 
            0xA275AD25032DAB50ULL, 0x56AB15265437C2EFULL, 0xD4173F7AAD69CB28ULL, 0x27ADDD91FB61FF52ULL, 
            0x30AE2EE77A219942ULL, 0x19E9F41E4BA961CEULL, 0x4EA885F929F8C935ULL, 0x284228CA23CCB7BEULL
        },
        {
            0xC777C2BD1B6340DAULL, 0x973012678EB96CBCULL, 0xB7CA3E4C60EB9FB9ULL, 0x9E8E5BE32F07838CULL, 
            0xA8AEC62870827C45ULL, 0xD095BA0FE01C27E9ULL, 0x2FC5596DE5B945C3ULL, 0x5FC0D5BD0605B04AULL, 
            0x547A2CE8023A88ECULL, 0x6C97890CFFDE8D47ULL, 0x07432E0C5911880BULL, 0xFF3F2D641A8BC526ULL, 
            0x8B3AD2BD535A3460ULL, 0x6FEE06FDF1D28FE7ULL, 0x98DF2CA85BA443ECULL, 0xD5B194154EB05A09ULL, 
            0xA5DC9000E7D5CF26ULL, 0xAAC7A5550C82697BULL, 0xCA26A8A24FAFCAAFULL, 0x6D1E4A81001DA3C0ULL, 
            0xFB11A5067ABA62ECULL, 0x4060AEB7A5323720ULL, 0x96FEDE874B666B94ULL, 0xAF4A33784A39D8F3ULL, 
            0xBC7C8B22997CDE9AULL, 0xE0A9356B6E8BFC1FULL, 0x829029476326D6C4ULL, 0x2E294A5B06D3ACC1ULL, 
            0x98C2535736676AF4ULL, 0xF8754C4126E30E9AULL, 0x4A5867DEF1416FCCULL, 0x3CFBA30CB9B1423EULL
        },
        {
            0x3194627D3B196372ULL, 0x4F41E9452FAD5C51ULL, 0xFC934AF614021E24ULL, 0xF64B214825FED117ULL, 
            0x2389D9D668AB59C4ULL, 0x15976640EA6B7160ULL, 0x9C5CBB11118FAF89ULL, 0x0FE98EE47000EE4CULL, 
            0xB2EB74094D20F62CULL, 0x31798E1C91ADFD59ULL, 0xC02BBE4EC29E7EADULL, 0xCFDF5543F37B4749ULL, 
            0xB9285ADF960B55E0ULL, 0x346FD9E7FD40EB07ULL, 0x4C6CE8E7EDE8C661ULL, 0xEC7984EACD5606BDULL, 
            0x262AD027A34C7193ULL, 0xA95AD363D87B57BFULL, 0x1FE7E1A280164184ULL, 0x97A53BAB37D50667ULL, 
            0x74586BD50470E15CULL, 0x9DED74BC53BFDC21ULL, 0x221686855AD0736BULL, 0x0B8D743AA55E0E72ULL, 
            0x8247EC135C20A74BULL, 0x0F986A7268453ADEULL, 0xADC2F291DEA16085ULL, 0xAF42EC71B472B97AULL, 
            0x1768007513EE7FCEULL, 0x28D0BFB46CFDEE37ULL, 0xD3AFDA3DBCC5CB24ULL, 0xBA09AB226D3DFA85ULL
        }
    },
    {
        {
            0x8434E7A76CB1B6D1ULL, 0x3775AA6663821ABAULL, 0x6651EB071130871BULL, 0x9F4DFFDE7594A734ULL, 
            0x5446F71753E6B1CBULL, 0x2B36970871988051ULL, 0xEF604E79684EC369ULL, 0xBBA2134C6438D940ULL, 
            0x724B2214FC36EC98ULL, 0xD0AD10EAE3D02E12ULL, 0x883636A879AD489AULL, 0xA6F6B83B2494E4ABULL, 
            0xC498E5F9263BDCFBULL, 0x12C8E26822F1A9CEULL, 0x3A657AFD586DEA8DULL, 0xB62897CE675EAF98ULL, 
            0xC43782D2C5E2CCB8ULL, 0xF1CF28CCDB578EB3ULL, 0xE3511878B593F250ULL, 0xF2B123E36D58B381ULL, 
            0x6853BCA741A55E49ULL, 0xC654EC6E8CF46FADULL, 0x94DA71345A9443A6ULL, 0xAC2F21D1563D82F6ULL, 
            0x7D187A032728BCDBULL, 0xD19D098DE453325BULL, 0x5263E20E9BBB8992ULL, 0x43C7349AE3520E46ULL, 
            0x67D3B87FB57AE2BAULL, 0xDC0195D012E20717ULL, 0x06202D84A737F5B6ULL, 0x8D451F038BDF0608ULL
        },
        {
            0xFA4E5AE15F21882FULL, 0x7C92F621ADDF5143ULL, 0x9550A420125B39BEULL, 0x19C969F0644E42C9ULL, 
            0x13655A6B30D58333ULL, 0x29D52F7BC3748885ULL, 0x0E3FF5BE8D73B385ULL, 0xE23EAC049A137A43ULL, 
            0xAE26341C874CF760ULL, 0x196CB4090579122FULL, 0x311D09844299A2E6ULL, 0x5B9C32AFCE0D736EULL, 
            0xCA80B4613045F4DCULL, 0x4DAD3A4E2EA8E25BULL, 0x0CA6B40078C85BDAULL, 0xFB82F3B9A2BAD6B1ULL, 
            0xFDB1D311AD76A418ULL, 0x68C1EB2916591474ULL, 0xA0B4267011768FD2ULL, 0x9023267F3FBADD2DULL, 
            0xBD956E6B18C1C3D5ULL, 0xFA55FB1999CDFBCCULL, 0xC0BC39AA93D360BDULL, 0x16BC5BD2AD47FB4DULL, 
            0x32118DFC0081948DULL, 0xC70B4DABBEF093DCULL, 0x3651448F7D6DF8DAULL, 0x84E803CDA8C5128AULL, 
            0x0ADC84F11D9EFA1BULL, 0xE390E6DB2C94D93DULL, 0x0F4DD45B21F105BFULL, 0xC4E65792C59F74A7ULL
        },
        {
            0x694DDE34A34F89B0ULL, 0xF6753BFC29A6BB6FULL, 0x73379B32D0FA75D5ULL, 0x7116960FE4C46AC5ULL, 
            0xB2EFC4FFA0850E12ULL, 0xE6089519A2272BFCULL, 0xDDC5BCF8B99F2B5EULL, 0xB23597B6D4190C2DULL, 
            0x80B7A2EEAB4B2783ULL, 0xD55C3F09AC5778D1ULL, 0x81A7668B9395B272ULL, 0x29EF8D81CA8E0D36ULL, 
            0x70C3B53C12662FE8ULL, 0xB8991D50814A895DULL, 0x20C14B242C697E2DULL, 0xA4FD9D79931B4B2BULL, 
            0xE3F5020CFC9B0DA4ULL, 0x71078C2010E1F0A0ULL, 0xA549969182A9E1C4ULL, 0x0038B76D04A81BE6ULL, 
            0xC940EE85878C4396ULL, 0x57999F67E71C3BA9ULL, 0xC337EFCE69B9A4B6ULL, 0x15E05AE4084B49B6ULL, 
            0xCFAF636759F34D14ULL, 0xDA2137426887A2D8ULL, 0x0C65A164821D0BFFULL, 0xCDB5D1542F4153F1ULL, 
            0x8D56EAA10DC1FE6FULL, 0xAF572373CAC30EC1ULL, 0xB97939F3E1CA91F4ULL, 0x78B061CBE853AC9CULL
        },
        {
            0x7A704D66E835E9CBULL, 0xB01567714B88E6A6ULL, 0xDC1FE43CF2A33DEEULL, 0x98A50A6B5A4E79B7ULL, 
            0xCDFD02EDB6AD10B3ULL, 0x7AE3BD9DD033758EULL, 0x8C898B60B09C2210ULL, 0x7BDD8178E8FDC195ULL, 
            0xABB810C274E14044ULL, 0xD762E6EEBF2589D5ULL, 0xE6E1A213530C954CULL, 0xCF8E48A86CE835EDULL, 
            0x956AFB20A25E71BAULL, 0x644B5D4BAFCBFA06ULL, 0x0C45BE0A06B7AB8AULL, 0xC524D37F82B04370ULL, 
            0x764B58C0FA4A902CULL, 0xB4C4F04EA46C08ADULL, 0x4EEE17771D13B09FULL, 0x72B941B85206A0E1ULL, 
            0xEB008A513F8EB92FULL, 0xA203028480F5B60BULL, 0x1A5336E3766EB9B3ULL, 0x304F6BAABAA944AEULL, 
            0x92088C4465D28490ULL, 0xDEA111BCC9173072ULL, 0x592FEF016B47466BULL, 0x310E6DF552AF9E7BULL, 
            0x760CC647CDC4AF8DULL, 0xD961841AEB59B153ULL, 0xFE79046D436632ABULL, 0xC072B10A26A96FE5ULL
        },
        {
            0xCFACEE6EFF6252BBULL, 0x5B64F70E469EB0BBULL, 0x5D62707B7656B7E8ULL, 0x177B0930CB3C6F39ULL, 
            0xDAE7D1B3D1CBADA3ULL, 0x1A5F67C7805D7150ULL, 0x9F19E8358FC19A6CULL, 0xE2F1B9B1D5CB6B17ULL, 
            0xC83B07C37FE9EE4BULL, 0x93AC887218A74FFAULL, 0x560840AEE305F5EDULL, 0x3B10638C155C2F4DULL, 
            0x064FC9B40DC8F18AULL, 0xA4C2E2222D7142EAULL, 0xCBA24EF2A6888079ULL, 0x92110F8A9ECBF98FULL, 
            0x0EC71C9125600300ULL, 0x7330915B6BF53750ULL, 0x28B5971C8D31225DULL, 0x286161212249DE46ULL, 
            0xC4E9B911126F24CFULL, 0xEDC93A40D7F649CFULL, 0xB79BD4706F416550ULL, 0x4D3760EACCB24BC8ULL, 
            0x9C7C664E22D53E20ULL, 0xD620C7C884BF53C2ULL, 0x40BA0B5A3C239727ULL, 0xE6B327B00C01466FULL, 
            0xBECA34DFB15D5B9FULL, 0x4A43F2E68E5DC6ECULL, 0x0A97C5ED9AED9D67ULL, 0x1EFBAD34D8BFDFF8ULL
        },
        {
            0x14392D2EC52ACF17ULL, 0x842969CD1E2AEFA7ULL, 0x1E9A92FB34C3234FULL, 0x4EF33FFF7E55EA16ULL, 
            0x8174E2E51BB506EFULL, 0xC9138D13FCD38F57ULL, 0x30549DE6F3A734B2ULL, 0xE2A20A06008C2505ULL, 
            0xAD621F911BBAB977ULL, 0x9C3C0278FEC3A560ULL, 0x0994092D2EDB9655ULL, 0x5F8C959B9AA25CC3ULL, 
            0x039618863BCDF6E6ULL, 0x3077B220D174E22DULL, 0xE86D525F88026CE2ULL, 0x524963E4E14805F0ULL, 
            0xD06D4ED70EBACE43ULL, 0xB8F1FD4D38D71529ULL, 0xC4F54666D5397F7DULL, 0x5A9200EB807F763EULL, 
            0xAAE142FDFB22F4B3ULL, 0x473FB1885F5093A5ULL, 0x2393C2EB2C6B34EAULL, 0x89976A90C075BC43ULL, 
            0xC6B0DB58F7198588ULL, 0xD15AB9527C85DEE7ULL, 0x1A219828F455EF35ULL, 0x2660790455CFEA54ULL, 
            0xEE4C1D62120C9219ULL, 0xA15ECC76F4F6E950ULL, 0xAB37D534CBB8152AULL, 0x5ECC82986462E4A7ULL
        }
    },
    {
        {
            0x2F928C65487AC353ULL, 0x4BA5257D556AC948ULL, 0x3BC2629A744FE360ULL, 0xECCBE56BA2327254ULL, 
            0x9094068F26AC3A2FULL, 0x0179DBEB9C87A2B5ULL, 0x88492F63CEC3B382ULL, 0x844D3961A941C2CDULL, 
            0xFA87FE71D5032D25ULL, 0x23DE09E804CAC13AULL, 0xAB611BCA565E94F2ULL, 0x43CCD68CF63C33DFULL, 
            0x2E5899579056CABBULL, 0xA083029A2073CDEDULL, 0x797D283E79856D18ULL, 0x60D47CCA5D1319E2ULL, 
            0xBFCCF91D011DE73DULL, 0x11E8167874CF9EECULL, 0x814D8B99684F7576ULL, 0x418F14AEA14C7482ULL, 
            0x3019036FED3F9A3AULL, 0x96A110CE9EEFFFA7ULL, 0xFE3587E8C729D259ULL, 0xA5AD63CCB7E00626ULL, 
            0xFF8D1C00F8FDF4D5ULL, 0xC0747FF13466A7DFULL, 0xA4619252A6856B00ULL, 0xE1F5454FDAA3EA61ULL, 
            0x39F141CC956D0E2EULL, 0xE9C455109438D8ACULL, 0xBA135144D8389FF4ULL, 0x430E5B855E36AB84ULL
        },
        {
            0x03987A03C81AE7A8ULL, 0x64B6A2B80C01471CULL, 0x8D5CB221DBF11B1DULL, 0x45E4D4B0DCE20129ULL, 
            0x2BD6377DECD862F9ULL, 0x4BFD4DD08788163CULL, 0x78C37DC602711BC0ULL, 0xB0657A17ABF752D7ULL, 
            0x7E04B5096006318AULL, 0x61284F70C4D5F2D7ULL, 0xFBFFBB3D0669C2EEULL, 0x692CCC028AA50B23ULL, 
            0x498BC2B3B85AC311ULL, 0xDB7652A2692FFDDDULL, 0x18B4C929792CE9A1ULL, 0xC47117DFDE439974ULL, 
            0xA38E49699AADF3DAULL, 0x84A26EC055BFADA8ULL, 0x8179026EDEF2E977ULL, 0xC4DFE1A7102BEE31ULL, 
            0x9BA7F88FB8FEA03DULL, 0x6622C4F7D2389C03ULL, 0xB816F54F3ED3BF9FULL, 0x1F89517A48932642ULL, 
            0x62004C7784AB9E51ULL, 0x3FAF90D16CF7B79CULL, 0xEBC9F6464586EB46ULL, 0x87A38485B01C39B0ULL, 
            0xC47277FBA09030A5ULL, 0xB707D15BBE7903ABULL, 0xC07BD687684AC2C8ULL, 0x229CEB03DBD5E80EULL
        },
        {
            0xA841AB3D249CA99EULL, 0x278136B43ABC389EULL, 0x20A068701F0D59A7ULL, 0x4B58DD42A9487DD9ULL, 
            0x774ED56033BF4B79ULL, 0x8052AEDE415DD8FAULL, 0x0FF0E5C86126E9FCULL, 0x0149710BCCF44538ULL, 
            0xAFF48D4CB91A4B3BULL, 0x6F54436E841E91F0ULL, 0xB312D8157EEBBECDULL, 0x23B6E9121F51A958ULL, 
            0x5B4F791BC6179705ULL, 0xEA804CBCE2F7018AULL, 0x9AC18F1AFF621E7FULL, 0xAE04B8DC0039E669ULL, 
            0x4DEBB1FEC809AD6AULL, 0x5C38B18901D3FF03ULL, 0x9500B458CA9F9F24ULL, 0xB33AC360B7AA0B14ULL, 
            0x8E396A97410BB3B7ULL, 0xDB629BDF5540A2CEULL, 0x12DA949D695109B6ULL, 0x83399C5F21A7132EULL, 
            0x29130ACEF7C12264ULL, 0x1E33A272071CDBD0ULL, 0x5301FFB617BE4D4CULL, 0x2FB640B8E190A715ULL, 
            0x86902AD291CDFA8AULL, 0x80DE1E33E5A2755FULL, 0x9C8728D61311F308ULL, 0x88C633E6B682402EULL
        },
        {
            0xE1249AC1F5C84F5CULL, 0xF6E0008DE57B9A1EULL, 0xFE66F16ABC9F56DFULL, 0xD853853BFB479DA1ULL, 
            0xFB87C901742BBB7DULL, 0xDD240012F790601EULL, 0xE5F74738173EC14CULL, 0xBB0C899EC41990CFULL, 
            0x14FBDAD58CA3952AULL, 0x1CCD540FB1B69BC7ULL, 0x689E6387C0C17094ULL, 0x2CA34CA9DB442279ULL, 
            0x72F9891374D2E9C7ULL, 0xB41FA759D66997A5ULL, 0x1E9CB7815DF36BD8ULL, 0x097B8E2D1BC84505ULL, 
            0x1D96BDF14B6D7BCAULL, 0xEF0E6941234FC5E6ULL, 0x2A5A43F3F120B41DULL, 0xED32BAEFDA0226D7ULL, 
            0xCADCB33DE998FEC6ULL, 0xE1ADC7A974C47161ULL, 0xD93D8A22D88858B3ULL, 0xCDEA5B94A1A3FB12ULL, 
            0xE9613B16E097E440ULL, 0x665945FEF977DF49ULL, 0x10FD31ABE288792CULL, 0xB6A8E2EF6C58BBBDULL, 
            0xAF27F6989A4CFFBAULL, 0xEB2C134DD8315FCCULL, 0x2CD77721D8E109BFULL, 0x5EF81A0380B2D5DEULL
        },
        {
            0xEA636595B1053541ULL, 0x7E06EDC2FDA11465ULL, 0x4FF7A2BA11BF609AULL, 0xC92C92DB00BEA2CAULL, 
            0x8151EB7A7C5ED49AULL, 0x720CE9D4F2EA0F57ULL, 0xB5FF4B6FE26E9AB8ULL, 0x9A2FBE960B430325ULL, 
            0x2FD9F857087EBC44ULL, 0x826E873142556713ULL, 0x094943A60826A6EEULL, 0xCBB76F141EA1B0B7ULL, 
            0x6CD7BF30F1799DFDULL, 0x2537E3938CEF850EULL, 0xD22053648F9D85E4ULL, 0x1949A74F3C8A4BF2ULL, 
            0x7B290A9DAF0FA13FULL, 0x5FC55BDD83C0B6F9ULL, 0x7BFAF4F225063675ULL, 0xC6B53FD13B0C5699ULL, 
            0x4250C349FD06DD35ULL, 0x648536240CDBFCEFULL, 0x2EB53BF9BCD7D99DULL, 0xF67C9C3966416415ULL, 
            0x9631575F4C33D5AFULL, 0x4A0F559022BA5C60ULL, 0x6F7467FB02FE3983ULL, 0x878660919CE63A91ULL, 
            0x2A17044AEB9697BCULL, 0x8A934B55E1B22D60ULL, 0x75AF5667813EE8AAULL, 0x47D1C63051E7D654ULL
        },
        {
            0x757E27465D06F3CEULL, 0x8C2236070CE6BDF3ULL, 0xE35B1655EDEEBCB0ULL, 0x3912DA8D6CC32AFDULL, 
            0xD6F0A7DF5DEB7A73ULL, 0x5AABE19862BCD2F3ULL, 0x411664D341447669ULL, 0x41883259430EDF3AULL, 
            0x922964236E74D566ULL, 0xC82F0F703EEB53DEULL, 0x7D1BACCBCD4D43D4ULL, 0xB0C744F5466A6A05ULL, 
            0x3CE4C79CCCB64BBEULL, 0x5E5C67A629B7F3D4ULL, 0xFF8F3CC727ECB4A5ULL, 0xCFF7C24E01804E93ULL, 
            0xA9DBEE12180D9101ULL, 0x023128B70CA88C9AULL, 0xCF6C594D95A0642FULL, 0xB849EA74A44D5299ULL, 
            0x563F799F51E97A7BULL, 0x1FCF53CFD966D4EFULL, 0x303B03B8EC8E2660ULL, 0xE5C266C7E58F94BEULL, 
            0x5CDA5C17828D3787ULL, 0x0D98AFFFC092AA56ULL, 0xBA0FB7BD5B96BC35ULL, 0x532383F0938AD115ULL, 
            0x4F36C80349DE1C81ULL, 0x43B773729157F27DULL, 0xD2522ACEADBB220FULL, 0x079838DC166CD7A3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Achernar::kPhaseAConstants = {
    0x4520ED56A98070B7ULL,
    0x1BE7417CF7B4202DULL,
    0xC9F167D5D4DA521AULL,
    0x4520ED56A98070B7ULL,
    0x1BE7417CF7B4202DULL,
    0xC9F167D5D4DA521AULL,
    0xCB112156B3BA8720ULL,
    0xC2FB06DF40FD22B1ULL,
    0x13,
    0x44,
    0x97,
    0xD2,
    0xE0,
    0x25,
    0x98,
    0x03
};

const TwistDomainSaltSet TwistExpander_Achernar::kPhaseBSalts = {
    {
        {
            0x6E181044567A17C7ULL, 0xC58389A6E3F4D6E2ULL, 0xDBD66102A282E00AULL, 0x8877E2B108B21E9BULL, 
            0xC3B65FEEA1104B9FULL, 0xA11673E9500A795DULL, 0x78C59263DC0A48F9ULL, 0xA64A7043E5C40BE1ULL, 
            0x0D1FCB7A3B760C42ULL, 0xFD3574DEF47AAC4EULL, 0xAD9375FEDF4EABA4ULL, 0x34E32AB53BC9EF71ULL, 
            0xD282407E94E3C8F6ULL, 0xD71F91BE091AECE8ULL, 0x203C1B24E9505DB4ULL, 0xC514374E4A47794BULL, 
            0xC3DB12B125FFAA4CULL, 0xE9A1EF8A8D6B69EDULL, 0x20E3E8F16DB0E505ULL, 0x840DF3EF7E1BC591ULL, 
            0xC0B0F44609389C30ULL, 0xF26BC312A9AB3792ULL, 0x535E3D1C98A79686ULL, 0x3EB65761CF1932F6ULL, 
            0xADD1137CD56F21BEULL, 0x9514577D20409BEFULL, 0xE117E288DE93542EULL, 0x1577EC5E78686418ULL, 
            0x44FA4B3771BF1799ULL, 0x864BDD8EAE7D2790ULL, 0x45B0200F4B47406BULL, 0x77B8E440BB6852F8ULL
        },
        {
            0x9917AE8FA9CA3BB6ULL, 0xD9F6865276A25C91ULL, 0xF4F218901D9DCCB0ULL, 0x75AEAC791827278DULL, 
            0x6A0DE0A0C63F190BULL, 0xA419B870A292EF5CULL, 0x72498560BB296750ULL, 0x0C15D0705E19EF4EULL, 
            0xF6FB85D85C49A5DDULL, 0xEBE6CF6D8AAA248FULL, 0x24F3ACE23883A875ULL, 0x6D348CEDEB15D95AULL, 
            0x398D339B65EE8103ULL, 0xC0AC22B7D02B26CEULL, 0x6170EBCFE04AFAACULL, 0x1F12902919ADB572ULL, 
            0xC1A6681FF8EDCA7FULL, 0x2DC5818C0C7D4C19ULL, 0xD454AC6D005B20D8ULL, 0xA0C193CDF6CF3A90ULL, 
            0xFA31FFB2A60CC725ULL, 0x90314863F394170EULL, 0x342A24E76DEEF5D8ULL, 0xED5ACD3E2D3AB7DFULL, 
            0xCE2831D010C4C508ULL, 0x6F69A9AC2E70C939ULL, 0x62AFB33575C5B0CDULL, 0xD3A7825EBC8209FAULL, 
            0x535D97383340FD2FULL, 0xC193DCE8D8952465ULL, 0xA602720D24F7F210ULL, 0xDC6AECD39EAC7C9AULL
        },
        {
            0xECB5B26A3251E0AFULL, 0x65335291BCA6CF53ULL, 0x1694CD9DD18F87F3ULL, 0x8168347B51F6F3A8ULL, 
            0x8E9B1414D46F5917ULL, 0xC6308AD740DC5FACULL, 0x83DA39A40AB6AB99ULL, 0x5214F5E2EF621363ULL, 
            0xFB066414AD6C839AULL, 0x17EE4101965A862FULL, 0xAD09E50B8FA7B217ULL, 0x80125382FF75D7C5ULL, 
            0xECB7043BA441FD01ULL, 0xA4D23508A1ABF89EULL, 0x022D75B80E8168FAULL, 0x6CB0E2F66DE2F4C3ULL, 
            0x306E695C4DA7B971ULL, 0xA68A0A52245377D6ULL, 0x7D9F54E8AAA82AC5ULL, 0xC805559C36E97360ULL, 
            0x40BAD9D2354A0BE1ULL, 0xD60D2D38CE28185DULL, 0xE572914F82939F49ULL, 0xD178BE32409CC6B0ULL, 
            0x2B90A8FE46C5F4E3ULL, 0xC6BF878F0A9CF163ULL, 0x88A97C98C2EC2FCBULL, 0x915A0A24DDBF7C1AULL, 
            0x28E969AEACA28310ULL, 0xFEBE1AB0800532E6ULL, 0x77A8D03D41A6E46CULL, 0xF0A0F24861677D98ULL
        },
        {
            0x9174A3C7BDE2E53CULL, 0xA09650C29FECFA59ULL, 0x7E07100FBEBEF305ULL, 0xCD66860DFC345978ULL, 
            0x9DA40486724693D9ULL, 0x16A4B10B5FE5FF27ULL, 0x9E874722FEC2A947ULL, 0xC78FCE2125DAB42DULL, 
            0xA91893E5E164EF18ULL, 0x43552313B4E639BAULL, 0x58506499AAFCC418ULL, 0x722D5BB9BC5597B9ULL, 
            0x711903A28E95B29BULL, 0x3E13419662B0ABD5ULL, 0x36849797D6C0AABDULL, 0xAF4DABD6ABF93A61ULL, 
            0x177B756AC21BFE5FULL, 0xAFC958E5B5D37273ULL, 0x447B6EA06B5CC50BULL, 0xBB6DE8705726B4DBULL, 
            0x33C7BA21ED4A98D8ULL, 0x1B5B0971A5555D06ULL, 0x5ABA5D2AD909E20EULL, 0x86E8FBA389A3A0EEULL, 
            0x7BCA6BEFD33A2BD5ULL, 0x21139F2C93CDD589ULL, 0x1C15510243E3758AULL, 0x2297A36B987C48AFULL, 
            0x23046E711A1F28E8ULL, 0x5433010B4D0137B1ULL, 0x7E4B3B18C723DF76ULL, 0xCF0CC75DAF1CE74DULL
        },
        {
            0x895F2B0289591BEBULL, 0xD75C5F5D857A3B7EULL, 0x6C3C6DB3F8E74234ULL, 0x2A5058D02EF2F707ULL, 
            0x7896E79459FC0944ULL, 0xA730110D2D3A5471ULL, 0x31173D3E1A6C3283ULL, 0xDB3CC8C15A296BBAULL, 
            0x5A2E0EE5A6B22B16ULL, 0x49BB2B08BABCC38CULL, 0xB4587CD2B36DDBA0ULL, 0xA3E5EE7DFD516638ULL, 
            0x1682F7EC528649B4ULL, 0xD9589F978844EAE1ULL, 0x42569936285082BDULL, 0xB83704A7CDE93DC6ULL, 
            0x89296627B8F39E0DULL, 0x907F774160F9A69FULL, 0xBD10216491042205ULL, 0x2EA242FF0A1E9161ULL, 
            0xDE7A5F3C91B4F85EULL, 0x00C1A26583F064E7ULL, 0x3AE33C96769ACB27ULL, 0xD44C86C1F9B15D98ULL, 
            0xB860DA7BF5BD6946ULL, 0xBD8D3A30381C7C97ULL, 0x12901CE977175E8BULL, 0xD3F9BB1AABD4D913ULL, 
            0x1FBB3BCDE6F9C757ULL, 0xAB3DE50B6CA89655ULL, 0x74F072BACEA3C8CAULL, 0x035649EDDCB32925ULL
        },
        {
            0xE96735E21961A44BULL, 0xFD2289377BBF736DULL, 0x6942FCC42ADD7866ULL, 0xE447B7759B332ABEULL, 
            0xD9826BF1F50BD2D9ULL, 0x1FF8A5F9C5B56255ULL, 0x89448214BE2D54EAULL, 0x7224D0FE7DDEB30BULL, 
            0x4E1C1DCBC7F13AD7ULL, 0x3645ADB5CFC9347AULL, 0x46758168757E0A2AULL, 0xEA72CF679A39DD31ULL, 
            0x79AD35B34561E335ULL, 0x9D2FBF7F7A339BBCULL, 0xEF467846B6C7507FULL, 0xCB0D6F94B4FB5C3BULL, 
            0xCAC336C7EA45A282ULL, 0x2A139731F2566EA6ULL, 0x6EA0DF8E8533063BULL, 0x16DD2AD944E76B21ULL, 
            0x3442929EF7808BDBULL, 0xBF8C5D37A8FDFC83ULL, 0xEA67A6D613D29441ULL, 0x8A521ADE228AC879ULL, 
            0x72A45944ECA773B0ULL, 0x5CFA94528C933B6CULL, 0x7169FA7450DC1387ULL, 0x73E023AA3B622DDBULL, 
            0x0306501F5B19B298ULL, 0x3F34C06FF94D1FE4ULL, 0xB934BE5EBC305155ULL, 0xC7214E5B4D154976ULL
        }
    },
    {
        {
            0xEEBABC332D0E3706ULL, 0xC01FE9891E4FB933ULL, 0x1D568CE0118CF71EULL, 0xCA4214EB407500C9ULL, 
            0x0D1C479945C609B3ULL, 0x7D4C58063E405FD7ULL, 0xCF6463E645BC82D4ULL, 0x714C8C8DACD8CC39ULL, 
            0x0A1764E32BEDFAF4ULL, 0x916F7A6B719BB1A1ULL, 0x54D8BAFA04AE5565ULL, 0xD9C8FF4460F5F6C0ULL, 
            0xDA452EC10DE4111BULL, 0x18FD1CF5FDE3E825ULL, 0x91FD12B8CD3119ACULL, 0xAC5242664BC66BB5ULL, 
            0xF5759AA780622A1CULL, 0x797F56203E572905ULL, 0xDFE48BBDC2A9225EULL, 0x308B2D3689DD9A2AULL, 
            0xB3A2067FE7E6ED8AULL, 0x122EA317BA08A652ULL, 0xC070D1DD827AB16AULL, 0x502A18A725D3412FULL, 
            0xF5D2DB94CA12C0ADULL, 0x6C29559629DFCCE9ULL, 0x2548ACAFA23EFA37ULL, 0xAB8BE4778A05E6C5ULL, 
            0x8D9038E2D867D5D1ULL, 0x484B42D225991C0DULL, 0xDF49B51BEE80161FULL, 0x56433C5A7DF527E1ULL
        },
        {
            0x40470DA5DDF60ADDULL, 0xC90A0F317E303667ULL, 0xC0DEA17D003D6F6AULL, 0xFEF7EC6D844BB7CAULL, 
            0xC65580D1EC4CCE9DULL, 0x3BAFD0EF8F028237ULL, 0x30FC3537EFF9C4A5ULL, 0x24EB0A1530E836EFULL, 
            0x81817B7DA4CF7F14ULL, 0x4422C2E5744AB6CDULL, 0x5AC4EA6C97F2824FULL, 0x7AC7F187CA7414BBULL, 
            0xE3832389B2368638ULL, 0x877C2DCB29213D63ULL, 0xD2857ED32B0CCCE1ULL, 0x8150BD7D51A44889ULL, 
            0x7553A10555A4FAD9ULL, 0x7603DB50C231B100ULL, 0x79C3D67981A69988ULL, 0x536E257EF06EAA43ULL, 
            0x7D6203238AFDBF89ULL, 0x49A39570F6455973ULL, 0xE5AF2D07D302D62DULL, 0xA14423CF0F07AD26ULL, 
            0xF1CD1F8507FDADA6ULL, 0xCFDAA87748102809ULL, 0x6EE457BF393D3B4EULL, 0x9C5008AFE2D23EABULL, 
            0x8A97FA81DCA289A5ULL, 0x0F2BF65C97081C97ULL, 0x2E78A328A0FEF117ULL, 0xC8403A5CD8C5A7D7ULL
        },
        {
            0x8F0F0827D1A16A6CULL, 0x9569C721083EFA88ULL, 0x0F404F42976CC062ULL, 0xA12C1B193E4782E6ULL, 
            0x8B98DEC0E8A3FD1AULL, 0xAD4391A9C2427C51ULL, 0x8A83D43482E8B04DULL, 0x3B9A8B7A73DF1987ULL, 
            0x9326499C1DC27E6FULL, 0xF5D0777EB6858ECAULL, 0x907795513A446470ULL, 0x9184904E4C953BD4ULL, 
            0x6BB27E8E8B3F173AULL, 0x147940509ADEDF8CULL, 0x5DA01AC01BC20C81ULL, 0xBB53ED6D14A138EFULL, 
            0xF4DB38E50C590159ULL, 0xCD72D432D055BC9AULL, 0xA09E4F8906DF27E9ULL, 0xD1C43C4B5AF42970ULL, 
            0xC9425E25002B6240ULL, 0x53F43B8EA323035CULL, 0xCC46E4B5F10FC35DULL, 0xA370728189208C4FULL, 
            0x63CF904F94246DD7ULL, 0x692928EFE49009E7ULL, 0x60CD18C2CA7F7989ULL, 0xDF10BA7FA15E45CEULL, 
            0x4FC5D1E3967D7AAAULL, 0xDE0F291244F20FC0ULL, 0x94E3F7E7DDB3567FULL, 0x977F8F9B0E07765BULL
        },
        {
            0xC1E4DFD78B5CE20DULL, 0x32A2837326A250B4ULL, 0xCD779F73EDED0849ULL, 0xC05F5AC20EBFEDB7ULL, 
            0xCA5926A12CC4F3FFULL, 0x5AFE52FBA9EABC6AULL, 0xB0C9046672485AC9ULL, 0xBC7A07F2491F0363ULL, 
            0x9D5FE73E7FB9EDB4ULL, 0x8281DAA35B9BD882ULL, 0x6AC082332F865363ULL, 0x1D278C6E7449D8D3ULL, 
            0x5FE77AC39FCF75B1ULL, 0x3C4F91C2A3A94822ULL, 0x979B0E05F4F6AA16ULL, 0xF8537CC10085E17CULL, 
            0x8B568A8649A32091ULL, 0x3ED41DBD19EEFE4AULL, 0xAB2ABA7381EC65E8ULL, 0xB43474DA6295A1ECULL, 
            0xB41EB172604BE580ULL, 0x21EB02DCFED0F2A6ULL, 0x04CAEC9B8D64552AULL, 0x7DE2BF2B3E96E770ULL, 
            0xF92B85DF8CD46445ULL, 0x752F0E6AAA59B126ULL, 0xD7164B4DF548114EULL, 0xDD1AB65C334EDC0BULL, 
            0x109250019AC22C6CULL, 0xC95AE2E59FF0C60AULL, 0x94655559BE2A5061ULL, 0x06E335F879A5FCB5ULL
        },
        {
            0xAE51313101F0CBE7ULL, 0x3714162B230749D2ULL, 0x998DEC2EB46485FBULL, 0x8D96EE54DB7E744FULL, 
            0xF4BA1F439545DC36ULL, 0x50DC3A3ADEAA6C04ULL, 0x1DB9A55271EEC312ULL, 0x530FA554FE68C6B5ULL, 
            0xC18BD45FAA50F847ULL, 0xAE05653C82400DFAULL, 0xADDB41F198FD10B1ULL, 0x359917AEF5A34541ULL, 
            0xE7FEA8975571E36DULL, 0x4CF54FEA14149A80ULL, 0x8BB9CE391F6EDF3DULL, 0x5607AF38DDA84611ULL, 
            0x844369921B11CAF7ULL, 0x2386ED30AA39E654ULL, 0x2EE95936B9BD9614ULL, 0x73137A5B0902DB18ULL, 
            0x2D18A249D5E31A4DULL, 0x8F5B6C500B9B7945ULL, 0x5B74DE2A382D643FULL, 0x809C84B4DF85A9B0ULL, 
            0xE5B2D56AF5BC1E65ULL, 0x3B42A9BE42C87105ULL, 0x886B8CD6549461DAULL, 0x23BCFD8F59DEFBAEULL, 
            0xD474B3AC4C1E1348ULL, 0xD3690A509182DD36ULL, 0x9CCF23A28B17C126ULL, 0x8EA8E814D50C5084ULL
        },
        {
            0xCEDCFED517701434ULL, 0x5C7795597BBB9E17ULL, 0xF87EDBA3D6C91C72ULL, 0xEB7133DEE5BE712AULL, 
            0x602BA5DE155DCABEULL, 0xEE331C7F6AF2C866ULL, 0x1B4C73FC4D1C610CULL, 0x6F36A9EAD6D8DAA0ULL, 
            0x5BDC8DDFFDE39B4BULL, 0x54F8F92BDC2AD61DULL, 0x95B887D2BA1F0A19ULL, 0x330A671EAD42E2A2ULL, 
            0x34636ADB1C0932C6ULL, 0x6352078087C33881ULL, 0x53E0CD6402CBCAC8ULL, 0x33647F494D26D96EULL, 
            0x9AF3CCF9F7ADAF62ULL, 0x872ADEA612981F1AULL, 0x15D6E68B0B997935ULL, 0x6E38312E86577DD0ULL, 
            0x83159964808FEE19ULL, 0x61B9862B4FE0CE10ULL, 0x5EA796774F5534F7ULL, 0x640579CCB91C4190ULL, 
            0x4C4B9177261ABEECULL, 0xCC9C41DE64FB91AEULL, 0xBBDC7D54A6899680ULL, 0xB02FF1617BF0D11EULL, 
            0x374A6AE57B385B6AULL, 0x696FFEB2FC8A5373ULL, 0x02B9A180B657F8AFULL, 0xD8931D6D8DE50C3DULL
        }
    },
    {
        {
            0x28279BDDDAAC6EDAULL, 0x09082A053375B131ULL, 0xEB6DFB6750499D15ULL, 0x58838AA757CDF860ULL, 
            0x3DD9B7D0C1D2DFD7ULL, 0x0444EAA3C516BDDEULL, 0x487C3C22D594242BULL, 0x45DA905122C177C2ULL, 
            0x86FB59BFFABDF75DULL, 0x65282D70E94E5AE2ULL, 0x9672F0BE61760600ULL, 0x52F44EE6E8ADAB19ULL, 
            0xFC8CDBA247A9BAE9ULL, 0x26B225704192F09AULL, 0x68B4419BFC9DA7A9ULL, 0xE58B68DD3A6184B4ULL, 
            0x5CDC8FB7561FA0EDULL, 0x4AEB5A51BC429F09ULL, 0xF7EDCA13158F4369ULL, 0xDF19282434B002D8ULL, 
            0x538AE10555F12B48ULL, 0x43A2E00336B6535DULL, 0xB40640370B261A00ULL, 0x216CECD736892458ULL, 
            0x71A0B90FBAB1F399ULL, 0xE82315181FEE2C79ULL, 0x707D361EE18B4DD3ULL, 0x21388CCAC79C4B98ULL, 
            0x7C31907E924F820BULL, 0xAF36B027773443E9ULL, 0xA277D9569C003475ULL, 0x3D9BD0A076D48439ULL
        },
        {
            0x4B05EAE6933119B1ULL, 0x693BD94BDEFC463AULL, 0xE764F2D8AE00C0E9ULL, 0xB354FB36FED34C9FULL, 
            0x8B9325D7A19A01FBULL, 0xE84EC14D02B1A3CBULL, 0x640D57CD4067E52AULL, 0xA637BA5752D7256AULL, 
            0x2B32213D69C5B2B2ULL, 0x8178A61909A7072AULL, 0x92934EC91B327EBDULL, 0xCB7EB38E75FF74D5ULL, 
            0x47B2A9A032CB1060ULL, 0xFC3B83D47226C143ULL, 0x01E9FDD2549CCE93ULL, 0x76EF33BCE8B1FA95ULL, 
            0x3F3E209D53877EF9ULL, 0x457465833BFBAA79ULL, 0xD2C6BBF93C63AC91ULL, 0xF124AC0EA118C6D6ULL, 
            0xB8A31F2014CD1497ULL, 0x222077D90D476A37ULL, 0xD028AC39B6D6C717ULL, 0x446895B609FD9179ULL, 
            0x861B5928A39764FBULL, 0x2A7FCDA97EE7BDCCULL, 0x9E4DCB492D44C203ULL, 0xD0B2B8EE3C35AF6EULL, 
            0xDD227265E8BF7C6BULL, 0xC44756351D86C1A9ULL, 0xC054F8EDBF857074ULL, 0x20B35B830E265298ULL
        },
        {
            0xD945992A17CD6119ULL, 0x9EAFA6F77DB6B001ULL, 0xFA6E79FD56C3AEA3ULL, 0x5D0A8B0B9998AE20ULL, 
            0x3BC22C89EED1B34FULL, 0x1BAC26A22E9FD050ULL, 0x68DE5FBC9B50EA12ULL, 0x85B160B7798D8C1AULL, 
            0xF4E2D2501E23EC59ULL, 0x3FC794A5DBFA4FF6ULL, 0x648A936482148EAAULL, 0x2EAE860483796C72ULL, 
            0x9EBB3B4199473B92ULL, 0x151B00CC8FC03662ULL, 0xC286ACC3E9BA0B15ULL, 0x7E0AE82C967B49EDULL, 
            0x532AC4D773B025FBULL, 0x21270F9505FE7149ULL, 0x7499F32278A019AAULL, 0x5E5A4835E092933DULL, 
            0x0E82E75319B27ECCULL, 0x555BA8953F850655ULL, 0x37004C2BAB4CB8B8ULL, 0xFAE28B667625BCD4ULL, 
            0xBA5FCF12EF86E968ULL, 0x7BFC8468B5D9E805ULL, 0xC8673418AF94C861ULL, 0x9FD546F404091210ULL, 
            0xE45DF8A99DC1DB2CULL, 0x6C3EB10E93D74594ULL, 0xD7246ACF5C05CDBEULL, 0xDB5A478F910B032BULL
        },
        {
            0x21F9EC4111A4081CULL, 0xE5A39739C8CBE707ULL, 0x70C7425C2BE3816EULL, 0xA71BAED0640275F6ULL, 
            0x24BE2C9F3D73451FULL, 0x6A1144031F76E85DULL, 0xCEE024E4C1D0438FULL, 0x64D877C8316A98E2ULL, 
            0xA3B96A8CC31BED69ULL, 0x49C83BC977B3D2B0ULL, 0x3523C2CB4764F6A2ULL, 0xC3CA51DBF37779FDULL, 
            0xF9A6D7A65643E01DULL, 0x6E8D7826B276F81EULL, 0xD9B8CE0381E4ADE2ULL, 0x5F70A41BFBBAA3EDULL, 
            0x08EF76CC865CFAB9ULL, 0x2863D6B5F5F13586ULL, 0x85132FBE319FB717ULL, 0xDEF6B64259090904ULL, 
            0x4008C97E19CB85EAULL, 0x2D2A270E18D6B13EULL, 0xD8ABB79D153D4561ULL, 0xB5405515E94CC712ULL, 
            0xCAF28892F48C70A9ULL, 0xB8161BFF5F941951ULL, 0xEEB73C141E64D23AULL, 0x20F680CE38533BC6ULL, 
            0x5B9B9C17EAB59AB0ULL, 0x0BAC6BE681EC7E15ULL, 0x46A24C48A21CDE0FULL, 0x2ECF0FF2603FB337ULL
        },
        {
            0x11438DFD958F5F5BULL, 0x8623CE2766C0BC55ULL, 0xFA325B60CF9861F5ULL, 0xD5A345A672978550ULL, 
            0x2892295DE04E9BFDULL, 0x80F60202A6DCFA35ULL, 0xD77078D74C746EB1ULL, 0xACCB2CF651C08B01ULL, 
            0x530F3E4659BFF26FULL, 0xF6C4A337DB768C36ULL, 0xCBC924A8926B9BC5ULL, 0x5E304BC134F5166BULL, 
            0x7733F31A833BAAFEULL, 0x8347A0F0020C9D05ULL, 0x18439E8933BBC35DULL, 0x51830FF34FBA6DDBULL, 
            0x9101D4DB5FA9407BULL, 0x81F585E7E395433FULL, 0xBA3ADF5AD88E81F8ULL, 0x1D5C48268B1687C7ULL, 
            0x2AB572FEC361BE8CULL, 0x121BD379D9269084ULL, 0xB3ABA4712E077FDCULL, 0x639D73216DC7569DULL, 
            0x166D50BF3B7DA933ULL, 0x3A13AEE99B42C1C1ULL, 0x995C9181B5400C9EULL, 0x120CF9ECA082117BULL, 
            0x347EDEDAE6EBE134ULL, 0x5310B4D50B30DB90ULL, 0x3E50A2C9E72883B6ULL, 0x70194E411DE90340ULL
        },
        {
            0xDBD21AD85989C776ULL, 0x9EF9B9B9ED1AB0BEULL, 0x67126450694A650BULL, 0xD50769E305703F77ULL, 
            0xDF8B9DC42E7A585DULL, 0xB39356D4DF32CF05ULL, 0x896FBC3AE6FC0C68ULL, 0x78557239C5F73C49ULL, 
            0x5BD036ABF6220EB8ULL, 0xEE8C0FAC712AA9D4ULL, 0xEDC0ABFE59464F16ULL, 0x8EDEF65F9E70B2EFULL, 
            0x3B3FAF533A443E66ULL, 0xE793271EB35B4BBAULL, 0x9D15FC75D17AEACCULL, 0x586C0EB17CEF873AULL, 
            0x3D9D2454E55A7C00ULL, 0x8CDF600440444DD2ULL, 0x3957496A4B6D7424ULL, 0x27659BCAC7767C71ULL, 
            0x325A19CF162F6A17ULL, 0x90334AF4DBA0A1ACULL, 0xE3D698186065EBDCULL, 0xBFE961E45C678E26ULL, 
            0x96CB43A4F09A64C2ULL, 0x50E52CE844630C07ULL, 0x706F1D634F992D3AULL, 0x05A14FF929C2026EULL, 
            0x91A13D44135DD1E6ULL, 0x0B5B0ACFC562C279ULL, 0x76DC4AA9E8321300ULL, 0xBED8A61BE686C32CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Achernar::kPhaseBConstants = {
    0x9154FE8292BFAEC4ULL,
    0xE510143814258553ULL,
    0x94EE9E1A4163C59BULL,
    0x9154FE8292BFAEC4ULL,
    0xE510143814258553ULL,
    0x94EE9E1A4163C59BULL,
    0x74070474953966D5ULL,
    0xB7C32591F80228A1ULL,
    0x36,
    0x39,
    0x26,
    0xA4,
    0x42,
    0x1A,
    0x73,
    0x32
};

const TwistDomainSaltSet TwistExpander_Achernar::kPhaseCSalts = {
    {
        {
            0x399CCAEEC96F639EULL, 0x1B0301F08556EA1CULL, 0x158E3BAA771443FEULL, 0x7AB253216B3ABF46ULL, 
            0x7EE4D3C3CE81EC6AULL, 0x5335BD867EE11E6AULL, 0xE653F0BF9A24A5E3ULL, 0x7FB56F33D2A354B0ULL, 
            0xFF58379831658B1CULL, 0x98F1DCAC00B0E35DULL, 0x125CA497A2AD71F2ULL, 0x3AE253BF4B7F1E5EULL, 
            0x170C5AB80B702347ULL, 0xB9F092D432B55CB3ULL, 0x8684E02F1C9FFFA8ULL, 0xC0CCE6B2A85C49F1ULL, 
            0x841D256AC7AA321EULL, 0xF8C55AD87AC5E505ULL, 0xEADED2BE5DEF53FCULL, 0xBB3DC0552C442118ULL, 
            0xE78B54C5C46B9E44ULL, 0x59EEBBC7543CB706ULL, 0xA68C5F95BB39E428ULL, 0x019F570836EC32D1ULL, 
            0xC92A6E460DE43C91ULL, 0x75E8DB694361CA3BULL, 0xBA27C0419280371CULL, 0xAEAE4481C314B3F4ULL, 
            0x48AA7ADFD416A696ULL, 0xAD397410379CF4B0ULL, 0xE5544F37E76C4F66ULL, 0x4E2157F355EAB5F4ULL
        },
        {
            0x0300977A70C13647ULL, 0x2B99C67D6FF504F3ULL, 0x3E2A2EBF1FD27575ULL, 0xEFF42A1641049952ULL, 
            0x6E8BEAD87974729FULL, 0xDF853068DE447768ULL, 0x86544C924EFBC0A6ULL, 0xC05AF33B8B30A20DULL, 
            0x04DBC16482D5F362ULL, 0x767818EBC8FC3779ULL, 0x139647367479710FULL, 0xF0782643976B4000ULL, 
            0x79738E93C472983DULL, 0xAC5F1B9A3D4DFA6BULL, 0x79294EB5B87F2E37ULL, 0xD96FF980BB9AEF3CULL, 
            0x08AE2FBD065B791CULL, 0xBEF0384DF5E2CDA5ULL, 0xD49BEA2C30649AF8ULL, 0xA3A92D5ECA39423FULL, 
            0xB066A3F0487C409CULL, 0xA9B5DA03C4E4F7C5ULL, 0x2D994518419FF839ULL, 0xE875324EC53B4DA5ULL, 
            0x24FE98F9FCEA99C1ULL, 0x6A747625610BE6F9ULL, 0x02EF821078F3540EULL, 0xF35ECC1ABA37C48CULL, 
            0xC3E49CFBD615C647ULL, 0xB21B2F3DE4AC64AFULL, 0xAB3228CAF85EA2DFULL, 0x9152DBE89B6D34CFULL
        },
        {
            0x53C7944CD5198C67ULL, 0xE65F05676B0DE862ULL, 0xCB8BABBDF9B6B606ULL, 0x2C60C60AA2E67799ULL, 
            0xE1674FE0CCD4B73BULL, 0x4AB971C50CBF94AFULL, 0x4789CC97B4B7FCB1ULL, 0x211C4626C27F5086ULL, 
            0x490406D11D49931FULL, 0x4F63678CA1C5CAC9ULL, 0x759E6E5106EC8859ULL, 0x7F21457FBC26CE10ULL, 
            0xAE24349124245938ULL, 0x6C92B90A90DBEAE8ULL, 0x6F92FCDE5A886F15ULL, 0x49016D0A65132F26ULL, 
            0x7543A4C23FF104CAULL, 0x6596E2954967EEC4ULL, 0x717743AFDFF3F0CDULL, 0x860F27A78A79B260ULL, 
            0x0A261C14CC8B2C1FULL, 0x8FB58EFB41F28196ULL, 0xDB883CD416EC039DULL, 0x482D1E35C273EDACULL, 
            0xE0F1E85617DA6984ULL, 0x299F5E8353E8B37FULL, 0x5F20AC48D7FA51B0ULL, 0xFD5BF5B8A75B5E92ULL, 
            0xA8FAB5E916F461A5ULL, 0xED8E275871F80EF7ULL, 0x9E132606869390CDULL, 0x976F78443F1980D6ULL
        },
        {
            0xDE5A93A2068EAD01ULL, 0x5C19AE40356220F6ULL, 0x396413F080BAB8F8ULL, 0x248630392B91293FULL, 
            0x9C874AAD8BAE9814ULL, 0xE3103716D55E2419ULL, 0x725AE533B5316058ULL, 0x21AC118979342D4DULL, 
            0x0F75E182043BBED1ULL, 0x4FDBB3ECB70DE8B7ULL, 0xEDB22D50C463A324ULL, 0xFD42D59AE97855F5ULL, 
            0xE03CD36DBC0F8618ULL, 0x6B16E3E7EDDA9AF5ULL, 0x715DBCD3F4475F57ULL, 0xFD635B548B1E64AEULL, 
            0xB29217926995CBABULL, 0x0204A1D439705C7FULL, 0x558068574FE8AC20ULL, 0x7FF95EA5486EC002ULL, 
            0x129D70EBEAF7EDBBULL, 0x5EBCB76FCDD35F78ULL, 0x9108135EB302AC24ULL, 0xFD4E767CD1034785ULL, 
            0xC55B72689C7F4B25ULL, 0xB5755CC2683CF6EBULL, 0x2588CAFFCDA307C2ULL, 0x956FE25186C2CE3DULL, 
            0x9C7F18A5330932CCULL, 0xDBD0CF5572F1BC73ULL, 0xFCAAEC3845A625CDULL, 0x1AA49BB5F0F4EF22ULL
        },
        {
            0xE8DFDD6228C83F9AULL, 0x11B19999C2E8E229ULL, 0x457952E935970EC2ULL, 0xB4B004D6FF9B88C8ULL, 
            0xF68C17A636A126E3ULL, 0xCF7D45B432C5633AULL, 0x158584E231A589F7ULL, 0x84C248CCF2638BE5ULL, 
            0xC805C7A9AF7D896DULL, 0xDE5ED5AE42A20413ULL, 0x0DDA8A1A8E7EF5C5ULL, 0x1CFE51249CE5FE94ULL, 
            0xB2F7506EE21C0C84ULL, 0x13CA7A868B48922CULL, 0x2E6D6287F68E35BBULL, 0x5841A09452062E55ULL, 
            0x40F6B0F9C36C04CFULL, 0x5101F55168EEA8D8ULL, 0x0D4B36ED8E605949ULL, 0x405C43F706DD188AULL, 
            0x66442E7C4895722DULL, 0xF180FA812ACC6A82ULL, 0x47ACCC452D3C98BBULL, 0x5766B09404965A4DULL, 
            0x2861B83751BA8611ULL, 0x796412B3C72C0F97ULL, 0x01423E6518653E07ULL, 0xC04C5A2087859419ULL, 
            0x8933F272EDA9729BULL, 0x211D0C73D6EB4A83ULL, 0xF6CAF3C4C7363674ULL, 0x463BFB72362B20BEULL
        },
        {
            0xE9AABD81DC140D0FULL, 0xEC5DD444033E3C6FULL, 0x8A4B330B9C728446ULL, 0x94CC2642A2BD291FULL, 
            0x85B2FED65A8B28CFULL, 0xAD33DF6485034894ULL, 0x3C79D2ED11045E66ULL, 0x5B6D5D682433C13CULL, 
            0x5797E03A059F3A6FULL, 0xA6101CA3A7616A48ULL, 0x97CDCEB679249F7AULL, 0xD5FDCD38757A8A59ULL, 
            0xC2435C4AEDD06FAEULL, 0x95B3122011A0FED6ULL, 0x49BC2DBEA15F95E6ULL, 0xE33A3F7969E73B17ULL, 
            0x95A3D5F1F65F1166ULL, 0xF979D46A57195254ULL, 0xA3C298401B9C1935ULL, 0x36388106FC017C6EULL, 
            0x526E144CCC124A33ULL, 0xF1AA4ED6D28674B2ULL, 0x284BFAED80F61237ULL, 0x16D8DC6CA557D86AULL, 
            0xE29B72A4E85CFCC6ULL, 0x11702DCFF7D7B6FBULL, 0x2EBDAAA58157461DULL, 0x7BBBF3533384E50BULL, 
            0xD91C7F291B95E71DULL, 0x1C77E51B63D65A5EULL, 0x6BD817AD3D936FBBULL, 0xCFADCC987E563558ULL
        }
    },
    {
        {
            0x6DCF73AA3BB48B98ULL, 0x27E04C9EB408EFBDULL, 0xF5EFD573B811C88EULL, 0x9B100D5A4DD987DFULL, 
            0x2C047C17E470220BULL, 0x482D9655F7D9CE89ULL, 0xBD6061EC2386086CULL, 0x90ED7233FF331029ULL, 
            0x44156CCC9BB1DC83ULL, 0x1ACCA071797ABB8DULL, 0x6E50F5B3018CBB1DULL, 0x71A4C0540585F2C7ULL, 
            0x7884D79835A2F228ULL, 0x25E54021727A1E03ULL, 0x2EF6034C70609891ULL, 0xE4718FB8BDC21C7DULL, 
            0x24B3DA5EC9851999ULL, 0x673D0944E9634807ULL, 0x92FBBEE116B1AD7EULL, 0x1928F38CDBB0166CULL, 
            0x543B574C8F0ADA3EULL, 0x82326FEF93118166ULL, 0xAF845A5FB6CAFAD7ULL, 0x50450D2AC9E6FF9AULL, 
            0x06A6E19F068DE611ULL, 0x69786AE0E004B11AULL, 0x05046A14C30DCEA3ULL, 0x298397F65ED5C1DDULL, 
            0x55303B6B1F6D9224ULL, 0x2AA6A950EEA2F2FEULL, 0x67CFE3E0E89C960FULL, 0xB20981D5E4BAB71CULL
        },
        {
            0x9910E8B5D8A3BD6DULL, 0xAD827E598291355AULL, 0x8710B5C03831CF18ULL, 0x33D789CB853445A0ULL, 
            0xCB9F56E591FD6A10ULL, 0xD2D6C70331088DCAULL, 0x9E0ACACBFD924C36ULL, 0xC8869B0390FB534EULL, 
            0xC682A1C395DD4400ULL, 0x2ADBC3790911BF93ULL, 0x35523823858C74CCULL, 0xE13DD3DB7C96DEA4ULL, 
            0x7F0AA5201D880DA8ULL, 0xCB10642323FF6010ULL, 0xF9B431BC5BE351FCULL, 0x8DD36D9AD8129889ULL, 
            0x72299ADF11AF3E6FULL, 0xC7008E5422A2790BULL, 0x1779C623B7E10DBCULL, 0x6E4090F9FECCC605ULL, 
            0xAE5B01BA959DC021ULL, 0x815ED085D42FE5C8ULL, 0x6DB2672F370DF12BULL, 0x605FE068C7A02D2CULL, 
            0xF998576E1BC975FCULL, 0x49895045F436148AULL, 0x4F4A1CAD62519B8BULL, 0xA3D64CA5E983A1C7ULL, 
            0x59BE2C655FA68A5FULL, 0xBB1173B8094DB0A3ULL, 0x7F34C669A143A29DULL, 0x0DB99285BB5E55EBULL
        },
        {
            0x1F8966FD4F6C9335ULL, 0x77119AFE217F367DULL, 0xCA3F71B7EE72A691ULL, 0xFF354E0CC43642B8ULL, 
            0x409CA0AC48EB12D9ULL, 0x57B37A8A5F1AB4B3ULL, 0xF424F8E5191588A6ULL, 0xC320999DBD612B14ULL, 
            0x86192CDB82CA2B17ULL, 0x153B43AD762C4223ULL, 0x9FB5B4031BEF5280ULL, 0xABB9BCB2D0A140B5ULL, 
            0x9D02C9065A93814BULL, 0xF5F5FC7F15A4A272ULL, 0x5FB28F0E44362FDEULL, 0xEC631355F431CC58ULL, 
            0xD93A3AA907A4B92DULL, 0x13A4545B62DD92ECULL, 0x047812891A3EE29FULL, 0x35DB8CEEE792A551ULL, 
            0xDA7D678868BD698AULL, 0xFB3F15E27AE42ADAULL, 0xB2699D151CBD39D7ULL, 0x30CC3F259DC74BD8ULL, 
            0xCE54069E460C517EULL, 0x5DF08C310F1CAACCULL, 0x5D33C7DADD5F861DULL, 0x2641FCD52B407344ULL, 
            0xA44B7B4009305EFBULL, 0xFF311A0728F68424ULL, 0x6E5B3F5D9D21317FULL, 0xA584F2ADF39BD9BBULL
        },
        {
            0x76091F7FA239C500ULL, 0x0E77F3A0A0E3FD73ULL, 0x0A45C7591E73C71AULL, 0x9DD7D2F618B7D2ABULL, 
            0x7E3FC90999BD1F11ULL, 0xE81E6A8C70FC8532ULL, 0x17638C589A675E90ULL, 0x8D330B26161F3BF7ULL, 
            0x0F6FA08C998A734CULL, 0xFC3EE9B3E0D96E60ULL, 0x614BC2DF4CC69154ULL, 0x1572036B4153B138ULL, 
            0x6E6AEDC9C31E7AFAULL, 0x06957E4ECFFA6354ULL, 0x4021EABCF6A565EBULL, 0x13F12F5D4695E701ULL, 
            0x4B32D8862B07401EULL, 0x5EF1024BF7E15B6DULL, 0xD82D57CB3A330CB3ULL, 0x14A795436F3EAB69ULL, 
            0x902B14590CC430CCULL, 0x09C3BE238B2AF46FULL, 0x16C2D60DAF0740C2ULL, 0xEAA95C2912BCF948ULL, 
            0x057A3FA17F8A0486ULL, 0xDB6BC13D952E83BEULL, 0x7377AEDCFCBA4BC6ULL, 0xD0838AC9A1B970C3ULL, 
            0x3B8C3B5757B3FCC6ULL, 0x3C475996ACA6B265ULL, 0xCBA8CDAFE6D8997CULL, 0xE614010973C70386ULL
        },
        {
            0x50074A10AC9AF0FEULL, 0x42320FD548B99026ULL, 0xD1C9FBECA0DEF62FULL, 0x255C715CB399B57BULL, 
            0x7732741B60C1C34AULL, 0xDD5FAE542F3E996CULL, 0x4DD26BF1A14D91AAULL, 0xBB47AD7AC5C09303ULL, 
            0xDD648C34C395AD10ULL, 0xED66B1B73E20C79CULL, 0xE4575C635C8A1924ULL, 0xA927E55A08772ACAULL, 
            0xB9BDE27F4A9F2C73ULL, 0x12969A36896BD848ULL, 0x8D7DEDED656708FEULL, 0xAEA5B599029A0389ULL, 
            0xBF971D1080E8FE32ULL, 0x7E0BC87A393F3377ULL, 0x0310A234B30CE26CULL, 0xCA69A50F80B2A1E2ULL, 
            0xEBEF42F38C2907E1ULL, 0x1C479D821E1152E8ULL, 0xF20B19FC6720CC64ULL, 0x2BF557C98909FB96ULL, 
            0x2356E0CAF93FAA50ULL, 0x3B0BF3A03C0715D9ULL, 0x12C71D9F1665010CULL, 0x20FE78C7462C95DBULL, 
            0x5DB02B873C3354C2ULL, 0xC3039B2158B266B6ULL, 0x00601ACAA3BE5FA1ULL, 0xF1096C2BE6271D8EULL
        },
        {
            0x7B13EB232FE119DFULL, 0x6FE1F5A73715AADFULL, 0x8E00BD114635DADDULL, 0xD32A52F9CDAA036BULL, 
            0x6BA4E49A0C8AC979ULL, 0x44C7BC3D1D9A73B5ULL, 0x2F7776DE02DA7D6AULL, 0x0E122D76E5575A86ULL, 
            0xBD8EB9BAE9868A23ULL, 0x82ECD62D67962F51ULL, 0xB289B59C3FA491AAULL, 0x852D84AF06E6F510ULL, 
            0x32B7E2E0F572CB63ULL, 0xF6B565F834503A1BULL, 0x982CA4A988A98A15ULL, 0x8259057EDD6729BBULL, 
            0xCB93EF338A65158CULL, 0x19FAA62BF331EA02ULL, 0x9B9B7AC13EC11645ULL, 0x7C266DAF92EFECADULL, 
            0xF057F80EF56DAE76ULL, 0x9203C92ADAC3E088ULL, 0xA77EB72C74704939ULL, 0x560723CB0F579267ULL, 
            0xFA28FF9D77467735ULL, 0x6B1CB1B57B672F98ULL, 0x248744DA712DF491ULL, 0x44432F59864456B2ULL, 
            0x97C79F4C1EDD0F0DULL, 0x3A5E527BFE2FFCFFULL, 0xBE51862793F9587FULL, 0x8405385FB5B3E1FDULL
        }
    },
    {
        {
            0x02B677F7C3AF6E6DULL, 0x077CEC74A2A9BE31ULL, 0xE467797F06E26363ULL, 0x4C8D3A88358FEAD4ULL, 
            0x8C50C4EC4F0C97B2ULL, 0xAF2A4166487C0AFFULL, 0xB9BB9A692EEAC7E2ULL, 0x63DF2139271AA184ULL, 
            0x76080247B60A3F6DULL, 0x8738505EE8DBF40FULL, 0xA94EB77C77E45215ULL, 0x8A942056F2E82FBFULL, 
            0x849186F1C9C2369DULL, 0x02B907C40FA2FC7DULL, 0x64ACFD9735947059ULL, 0x4BAA18A485E983EBULL, 
            0x92086B61CB102D04ULL, 0x1777FEBA08680BC6ULL, 0x90B6A2ACE7DF414BULL, 0xB3CB498E90FF3EEDULL, 
            0x406B2889A19494E2ULL, 0x99EB68D1783E65F8ULL, 0x152EC4156467333EULL, 0xA803CEFE7C3CC79BULL, 
            0xE8F7EDF9D3539D8EULL, 0x517A853A7129FAD2ULL, 0x6B4A74F10AC6F128ULL, 0x2536E58FCF6BB394ULL, 
            0x9AA4D3095BB8CF5AULL, 0xFC128244378286CEULL, 0xABF11B24FE04A325ULL, 0xFA84218C742F3B95ULL
        },
        {
            0x10A1C2A4256A0369ULL, 0xCDBB1AD154406422ULL, 0x98FAC44E45CADF6FULL, 0x1E20F7A2424CC4D6ULL, 
            0xC704E12A7A3883DBULL, 0x7F2DF4FCA7AE3547ULL, 0xB40CA5C049EABD5EULL, 0x9A2526C639C881A8ULL, 
            0xB642FA41F0D237E3ULL, 0x9B72867CC2838074ULL, 0xFB4BA44083DB6121ULL, 0x4229313D730F2650ULL, 
            0x60068FFF53CFB56EULL, 0x70A12C600907A06CULL, 0xD8495986184F69CEULL, 0x55864A1E0445479FULL, 
            0x45902C1200A02A27ULL, 0x82E9748F68DC9AADULL, 0x8728F6D88E74262FULL, 0xB52FE4D49187A580ULL, 
            0x37E96B5E596D2FD1ULL, 0xCB3292B8C8153AAEULL, 0xCD77E21F78CADB07ULL, 0xD0B425DD13A0C6A3ULL, 
            0xCB4AE4E717042F6BULL, 0xCD05C914A05927E3ULL, 0x15636D90DC330548ULL, 0xD231DFE6E4E0F543ULL, 
            0x4B7C3364F825C79EULL, 0x024AF46B1794EDD8ULL, 0x93B6BD9D390E59B2ULL, 0x9A72509E8840F3F5ULL
        },
        {
            0xFAD7B416FB1FC222ULL, 0x666DD8CFCE3CF4D2ULL, 0x92AC5FB149D35649ULL, 0xAFD1D94C48DD2D02ULL, 
            0x8153B8C69F807C94ULL, 0xDA0D4B1CCF6DB1F3ULL, 0x798F6DDCE3909FBDULL, 0x51B4FFFB4E80CC35ULL, 
            0x0711515A11C18882ULL, 0xD4407D6235E9F768ULL, 0x7055D88C081F7312ULL, 0x5075AA80AE8B0167ULL, 
            0x40D291D11B1CD4A9ULL, 0x768F383194C6BD63ULL, 0xE73175B64AD4A17BULL, 0xB93767A14F1F6301ULL, 
            0x9B57A7D66C0AFBA7ULL, 0x2D3CAA9BE1F53F32ULL, 0xEF7F8F71EB9816F0ULL, 0x62ABFBCE7B7A6C22ULL, 
            0x9CE744565CAE07DFULL, 0xC1CE45A975306B24ULL, 0xFF6E003394DED63FULL, 0x2871BA8574867792ULL, 
            0xC99C161D67C354CCULL, 0x8AAEEEFEB771A608ULL, 0xE09FF0EDBB55BAE1ULL, 0xAF584B894D164169ULL, 
            0x847FF687DEEBFC02ULL, 0x23CC53819B981F41ULL, 0x3208C93649B2766EULL, 0xFCFB50D88E8E06E5ULL
        },
        {
            0xB6D5496D84E37D76ULL, 0xE42E1F0C577D2162ULL, 0xBA1043577E91C1C2ULL, 0xE12261CD05C6F092ULL, 
            0x2E008CDA4E52D3F1ULL, 0x44F2988D1DF0DB46ULL, 0xB06241B14D6A00D7ULL, 0x2587B6750B4CD709ULL, 
            0x11E845354D829EC7ULL, 0x363C7FE324D46F5EULL, 0xC3D216D2E11D2BD2ULL, 0xC8933FDD20099C97ULL, 
            0xDC9A12172941AD6AULL, 0xE84021D78D74D708ULL, 0x13279EEC468A1205ULL, 0xBDF6C6FC27BB0E35ULL, 
            0x9F52B124BD8D72A3ULL, 0x4F1C50BA0AA2977BULL, 0xE73BF9426B316A07ULL, 0xF1DE5B1613F29B0CULL, 
            0x54FC1B21BB3D5CE9ULL, 0x175DA77695DC8184ULL, 0x40061BAACD25AC14ULL, 0x194C738DBF0C1F96ULL, 
            0x67491F9ADF7A04D7ULL, 0x6D7E4058D2FFC2DFULL, 0xD7B6200C09F0D305ULL, 0x4D0F154E3F99C469ULL, 
            0xF947601B6EA9E7CAULL, 0x3A3BD96CF12F1E99ULL, 0x1A74A79A6A70CD1AULL, 0xD38B9C5B57DABF75ULL
        },
        {
            0xA7D396FFD6D9822BULL, 0x90C946C94CDAA980ULL, 0x255E830455F61618ULL, 0x02883BD828ABDEB4ULL, 
            0x21768AA95FD89418ULL, 0x2A926DDD16388529ULL, 0xA8FA766964C5EEBDULL, 0x4AD62732B91A1C05ULL, 
            0x2DF4067D9DFD3F98ULL, 0xE228A53D565B2CFCULL, 0x197946126823C43EULL, 0x567CE705BFD0E13BULL, 
            0x1EBDCE6C9B612A53ULL, 0x97AF93E79AE25685ULL, 0x8F983C5FCE223F47ULL, 0xC2EB08BB1CB8715AULL, 
            0xB62A50DE728A8DC9ULL, 0xE3EE7E2AB791CCCCULL, 0x8E900839315FE08DULL, 0x6AC2315D1DCB943BULL, 
            0x248BDFE2065D3573ULL, 0x0C8A24FFE2B4C359ULL, 0xD1291DC8D02D26B6ULL, 0xB1EF904A2B701C44ULL, 
            0x7A404DC8BFB408DDULL, 0xB5C88FA74D6BA8C5ULL, 0x4457A6FFB21F5657ULL, 0xC18B2B86A50629BBULL, 
            0x921C503A4CE950B6ULL, 0xECD5DCAA3D2F0406ULL, 0x93E7C8316ABBA9B1ULL, 0x8AE1498CC05F5185ULL
        },
        {
            0xD7D18EC3FA50893DULL, 0x6A01899A2423A7F2ULL, 0x2625360FA816E4A6ULL, 0x5F42ABFC8609EBFEULL, 
            0x5C7B0CD8906D5113ULL, 0xE31692B6034FF5D9ULL, 0x081C7BE7BC73BA49ULL, 0xD53C14DC0921D4C4ULL, 
            0x0C8B7A65FD955BF2ULL, 0xA52CE03DE440D8F8ULL, 0xDE86479427364C23ULL, 0x3D7DB64465C6ED46ULL, 
            0x3A4E88A385F402E7ULL, 0x6CEB77AE7F91A60DULL, 0x3DA297ED6C1B37CBULL, 0x7A47F0AB6FFDDB5EULL, 
            0x4DA44EBE20A5937CULL, 0x7E8ADC0A8023E8BAULL, 0xFF1F7589BB841FFCULL, 0xDDBA08D6900BFDE4ULL, 
            0x44FAB907A9257D95ULL, 0x819AD7D4971A143DULL, 0xD9B60D4D59AED7CDULL, 0x809FCF2A94F62273ULL, 
            0xC12C0E57E16ABA05ULL, 0xDEB5628418784789ULL, 0xEB3D5358B4248D3BULL, 0xA805B5268F70E081ULL, 
            0x2E2E08517DB39049ULL, 0xAA2AA42268D6F0C9ULL, 0x671C7E15ECF45598ULL, 0x6B89BFF9F579CE66ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Achernar::kPhaseCConstants = {
    0x829C6F7162029442ULL,
    0xE22C0D36F6F33889ULL,
    0x1B8DF41361DF3285ULL,
    0x829C6F7162029442ULL,
    0xE22C0D36F6F33889ULL,
    0x1B8DF41361DF3285ULL,
    0x69F7EB0718668D3FULL,
    0x049D99634944C7FEULL,
    0x35,
    0x6D,
    0x69,
    0x0F,
    0x8F,
    0xB9,
    0xA6,
    0x34
};

const TwistDomainSaltSet TwistExpander_Achernar::kPhaseDSalts = {
    {
        {
            0x790BA94BE0305E13ULL, 0xF686BC0225BDC9B3ULL, 0xCA96C1A1D3C02C40ULL, 0x7ACA2C334C911694ULL, 
            0x79ADB53FA905A0EDULL, 0x7032A57CE512D125ULL, 0x12472F8E47AA8DF4ULL, 0xA94F22F2AA5F655FULL, 
            0xAE715092A7B1D5BFULL, 0x86972C86C1E22259ULL, 0xEFECE9133DE91D57ULL, 0xF9028FCE3B453CA2ULL, 
            0xF8F797CDFB52BD1EULL, 0xB644FD4E7B76D6DEULL, 0xE42B50FED360EF60ULL, 0xED2AC8B47B6C7214ULL, 
            0xD33F812D432C3025ULL, 0x0F64F86376F9368FULL, 0x472FAF77167D93B8ULL, 0xD66F63C452116647ULL, 
            0x41BE0A18360D2BABULL, 0x0AAB0D98F2AAA21EULL, 0x54A7611C84E7079DULL, 0xC23ED202F7217FDCULL, 
            0xCC5CEF729AA04166ULL, 0x8618E05A3D1E74DEULL, 0xC64131CC93F3CD97ULL, 0x62D30C8B5C2A4F89ULL, 
            0x9C7937D04E8C1318ULL, 0xF2A2794A691565FEULL, 0x8419F3C790B86178ULL, 0x6B2C81470AE15FFFULL
        },
        {
            0x104A3EC250F4C83CULL, 0x900F18E468775DD4ULL, 0xF7DA04D9F914FD11ULL, 0x13D7AF0124FF53D3ULL, 
            0xA3AEB0DFE2F683F6ULL, 0x05F8F57EF12CB6FFULL, 0x25D3BCE5E6B92D2EULL, 0xC2C703A258D09ECCULL, 
            0x98646DB6D023942EULL, 0xD2A78205362B6394ULL, 0xD4EBBFE7726D3178ULL, 0x9DB6D514E3C49421ULL, 
            0xC7370F4ECA6195EFULL, 0x980643ED70D7105BULL, 0x2EFF2A684219B211ULL, 0x6B3CAE3722B712C6ULL, 
            0x32C2A2B5F3341945ULL, 0xC071A6D6EB03A44DULL, 0xC815416FC9E1DC26ULL, 0xC8B0DB8D4AFF1CF7ULL, 
            0x9202196F639433B7ULL, 0x9379360E58D768ECULL, 0xE7DD67188AD7F352ULL, 0x3D1A07A5BE625B5CULL, 
            0xE4276ED89C41D029ULL, 0x19BAF5EC66D3508DULL, 0x6B20538A4CB64EEAULL, 0x331751D6F7C2AE65ULL, 
            0x9B369FEEE23429DDULL, 0xF8C7E3C57ACA00BEULL, 0x262AB0DD0698741AULL, 0x6837844E49F5EC9BULL
        },
        {
            0x385D384F4C35AF08ULL, 0xC12D8DC4A835B817ULL, 0xE40677124F86F095ULL, 0xCB09AA7CAECE2D3FULL, 
            0x76F6FFC00FD0AD3AULL, 0xA36CEF5E2542CD2FULL, 0xFBCBC2E06F6A0E44ULL, 0x10637476FC2AFCD5ULL, 
            0xD1A203592E6B546BULL, 0x34D053AD111700D1ULL, 0xC6A32F4B75E2C01AULL, 0xD5968D0472D5EFAAULL, 
            0x54231698EB338E46ULL, 0xD03ED05B66D9782CULL, 0xC38B8CE330E971CFULL, 0x4B737A0862552E2BULL, 
            0x180D29E27DF016B6ULL, 0x33FB69BA08032DD8ULL, 0x3BE820EB9B3532B6ULL, 0xD9DD5FDF8118DF72ULL, 
            0xEC8C9A839D64E346ULL, 0xA4D04AEBD6EED75FULL, 0xA160685FD0F1A391ULL, 0x5FA3D132160A4DFFULL, 
            0x3090FF0E7945575EULL, 0xE836030F411FD882ULL, 0x32D218A7120847DEULL, 0x063C02D6F42BC246ULL, 
            0x03B899C9AA9E02D1ULL, 0x5E33B40116C9547BULL, 0x5E280CC06640B931ULL, 0x2AB650964A330FA2ULL
        },
        {
            0xDC183D1DA8503F6DULL, 0xEC776CD12CABDDB0ULL, 0x487E205366A5E75AULL, 0x064EBFF33A6C774DULL, 
            0xC1927FA10011BD5AULL, 0x879C8EAF96D9C278ULL, 0xC07C70B1B1CC1C8FULL, 0xE054E7F66E13183AULL, 
            0xC55FF130D70AF156ULL, 0x26F06D656ED593A6ULL, 0x592F5A59C76A81CAULL, 0x29E50F6D0EA767F2ULL, 
            0x97BF9D6609B9AB4AULL, 0x5B107FDD7F86FC60ULL, 0xB2A7B63EC44A781AULL, 0xDDA26052F3E4F3AEULL, 
            0x131D03722FADC4D4ULL, 0x8EF5A7FF2715F02EULL, 0x96841376D4264D78ULL, 0xD3223FFDDF90CB39ULL, 
            0xB24BCC69D766EFACULL, 0x6BF4B8C8B2D2DF15ULL, 0xD4AB9E8C300FE248ULL, 0xDB7DC1208597EB63ULL, 
            0x0CE804D2C029BADEULL, 0xD74F1A067C76E1BEULL, 0x1E468F344CF42F17ULL, 0xC668E60932B0B761ULL, 
            0xE8F96FFDC6B13263ULL, 0x65F8C8E629DC83F3ULL, 0x85747AF7D1CC582BULL, 0x568F1593ED8E4947ULL
        },
        {
            0x56341E7F8114340CULL, 0x8979CADBAB000F52ULL, 0x749BCDA530D9F9D1ULL, 0xBFA79454FE747343ULL, 
            0x38AA793D394EAC8DULL, 0x727E9E23913238CFULL, 0x734EE42BEC1401FBULL, 0x3FBDF42CAF447DECULL, 
            0xFEF683C0F642CFCFULL, 0x04996C6815E12142ULL, 0x075D3F580E0832D6ULL, 0xAE8C8166CE0AD938ULL, 
            0x865E04462DCDB90DULL, 0x23EF9458ADBDE86EULL, 0xFCD38E09AAE202E4ULL, 0x80A64463F13711B2ULL, 
            0x6DBA9588087F1ADFULL, 0x5F6D0150808FB688ULL, 0x567921D8F800C7CEULL, 0xFBBBDA3B0258210AULL, 
            0xC0E98F59D666DB5FULL, 0xD4B637A448B6BEC6ULL, 0xCA3ABCF1D4655138ULL, 0xAE9AF9737F8707E1ULL, 
            0x60038A3CD4BCEFD7ULL, 0xF43048808191AC11ULL, 0x5615CBB71C2EE751ULL, 0xCA8BB937C1EB0D6AULL, 
            0xCF3EC53FBDEC6869ULL, 0x6C639B4292580158ULL, 0x4519A3E52314CE47ULL, 0xA13EFFF60DD2712FULL
        },
        {
            0x7D50E09C4DF8D7CAULL, 0xC9DC226D139D1FF3ULL, 0xAE231273BE160574ULL, 0x77158E78A21C173EULL, 
            0xA7E08CEC2C9D02A5ULL, 0x48BAC524DB20C86AULL, 0x86049CF047F3B652ULL, 0x942BBDE2A3A0BBFEULL, 
            0xF85E797403F6C943ULL, 0x69EEAFEE5E300A80ULL, 0xA580074353963CF5ULL, 0xE3C187477C9114E1ULL, 
            0x6E2C102EA23041AEULL, 0x453F67C249C526B2ULL, 0xF8001195298945C7ULL, 0x5CA6E600FB87A128ULL, 
            0x357016E8C013174BULL, 0xEA564CA676C6CCBEULL, 0x78F34F410536F9E7ULL, 0xF069B61A4ADE1629ULL, 
            0xA1D91643684A1402ULL, 0x8EC9F8112273A908ULL, 0x471BADC24070EF47ULL, 0x28956F30C49ED4C8ULL, 
            0x79E3FFA0AA35B87EULL, 0x1EE0A9FA80658AA9ULL, 0x558AFACD315142F0ULL, 0xA97BF00831D552EAULL, 
            0x09ABD489E5D70458ULL, 0xF362A0E80260C6ABULL, 0x08ED8C6D44B2EC6AULL, 0x6C8E45423767581FULL
        }
    },
    {
        {
            0x71507FA0ADC70328ULL, 0x4E9D62D2BB8221B6ULL, 0x7F8C45C297622B84ULL, 0x93871421AABFE38FULL, 
            0x84F68A49D0B842B5ULL, 0x73BCE091380636A3ULL, 0x892F532747113797ULL, 0xF20EECDC955C5781ULL, 
            0x174B7DF598EC7C6EULL, 0xA72ACFF4A1B23405ULL, 0x200CF51A5E7D2504ULL, 0x36590FD514A4F342ULL, 
            0xB8BD218F993619C9ULL, 0xA378EF085327F743ULL, 0xE85BDE589AC14EBAULL, 0x762B700944CA2E36ULL, 
            0x3294DE316BD69D7AULL, 0x06A4F0D9E4C36660ULL, 0xF435D316BCD8EACFULL, 0x8798D59F07349FF4ULL, 
            0x6254B6F6AF1033A7ULL, 0xD24FF0DD94B41430ULL, 0x08E495A0ABE0CE18ULL, 0x48799138A26FF22AULL, 
            0xC9BD1A0F3A2160FAULL, 0x16D98A63C983147DULL, 0x534601911DE873ABULL, 0x13EB18ED59CE259AULL, 
            0x6C1A21FB9DE19769ULL, 0x0C13C3525FD2FEB9ULL, 0x315A67D39934497BULL, 0x15BF9CCC57535569ULL
        },
        {
            0x40FE4442309208E0ULL, 0xD7DD3DB9BA38063BULL, 0x099B811EDA71319DULL, 0x392C01AE6B5F18EDULL, 
            0x4411C80B70C45257ULL, 0x41E4F3B04DF62007ULL, 0x59C542D390F8FE52ULL, 0x1BBA9FF8552E24D6ULL, 
            0xC8E943CB79F8D7A8ULL, 0x0C85C2DD92194AA8ULL, 0x3289591FEB8A87B5ULL, 0xCF5D2CEDFB73EBEDULL, 
            0xF7F3ABF56760480BULL, 0xE29A24089771D72AULL, 0x4D3D7148670E63A9ULL, 0x4B7F132D35B98AB3ULL, 
            0xA12232A34737621FULL, 0x1A941B298F315AE6ULL, 0x5647AAFF151158A9ULL, 0x85C2C04F0E653329ULL, 
            0xFC569EA010EEE2C3ULL, 0x755576AD20F4E1F3ULL, 0x9DB2161A5D99CE53ULL, 0x03AB6FB03FAF00B5ULL, 
            0x7127FB90B41E7D0DULL, 0xE3776BB843CDC210ULL, 0x5B8572F0C8F0EEF5ULL, 0xEA59A14140BA0A96ULL, 
            0x484E97CCEB8722BFULL, 0x7C9E22C8354565F1ULL, 0xB1BCCC63F44765BBULL, 0xE1EB27372D53D333ULL
        },
        {
            0x10B0E0B414D19E3AULL, 0xD0190262A8172EFAULL, 0x529C141E400DFC99ULL, 0x14FAC93ADBF012A2ULL, 
            0xD00479D7680EA270ULL, 0xB5088475D8C94003ULL, 0x43B9A8A8BA51C9E0ULL, 0x808AA21851C0B9C2ULL, 
            0x259C56CDBCFBB756ULL, 0x086A4B37BDFFCA54ULL, 0x3758F89B34E41F54ULL, 0xEF58E1F0651D88A7ULL, 
            0xEDC1831EE160E70DULL, 0x8624D93B45AAFCFFULL, 0x0DF0C52B1F6F007EULL, 0x5D7D1C3D38C1BA69ULL, 
            0x188E4D7F5F9ECDACULL, 0x6F6AA9C0CF3DC700ULL, 0x95C039250A972331ULL, 0x84BFB061866726F1ULL, 
            0xA0C3FD0900342828ULL, 0x3961D3970A2DB613ULL, 0x4ABA5BE467D5580CULL, 0xEF598C20079AA4E5ULL, 
            0x2A3E770479D9D1ABULL, 0xBCD50253F9648DDFULL, 0x5FA1CAF2E989816BULL, 0x880522DE9E855AF2ULL, 
            0xE1D16FAF8773EE76ULL, 0x79999A808B9A11FDULL, 0xFCDCD8DC20AAAABEULL, 0xFE4E409B8DF6AC92ULL
        },
        {
            0xA4DDF588F07F861AULL, 0x03F121A9C1E730C5ULL, 0xB744F9237731B37FULL, 0x15AA5E56C1543D23ULL, 
            0xA02839CB419F4017ULL, 0xA38966C1334DA237ULL, 0xA8EF308357AA143EULL, 0x23B5BA6589DF47BBULL, 
            0x9CBF0DE9A6382845ULL, 0xCDC47466656729B8ULL, 0xC97752875FD79DA8ULL, 0xB25D88F704DE85EFULL, 
            0x926DBDA1A8DC9869ULL, 0x1258297CA29CA645ULL, 0xB536B6DD41FCF5E3ULL, 0x4A4D766F7734C0DFULL, 
            0x57DEE16B721E751DULL, 0xD3737A3E456C7037ULL, 0xE89F4C392420A9A6ULL, 0x88C588B8CAFC9E9AULL, 
            0x02DB98A1FB6A0FCDULL, 0x7998681A425DF9F3ULL, 0xCA1A126EFAEEECFAULL, 0x5A1B9F0E15909D70ULL, 
            0x08F937852F155274ULL, 0xC874E9E9568837C6ULL, 0x4DBB9ECEB77465DDULL, 0x4F84EB2B41D6BA06ULL, 
            0x1A1DD119934C22C9ULL, 0x2B0AD73BA69962BBULL, 0x4D4ADFAB15F1B230ULL, 0xA71C054556705F2BULL
        },
        {
            0x20FF5E01CD2D57E8ULL, 0xB27BCA35C83DFF0EULL, 0xBFAD53D1FFA2077FULL, 0x9D7EE00388902D67ULL, 
            0x0DD4E59791870119ULL, 0xC10F58AF629F08DCULL, 0x3070E57C8769FE45ULL, 0xD17B4A84C8AC2054ULL, 
            0x1EFB1C96F459FE1CULL, 0xF229D529472DE07CULL, 0x211560FFB3095DAEULL, 0xD0C6D64E088E05F6ULL, 
            0xF7617EE77F27EEACULL, 0x07E8041FDF9B03F9ULL, 0x5BB099126525A452ULL, 0xE4650C2A881D98F7ULL, 
            0x4A355653A4379F71ULL, 0xAB244A1F079B97A8ULL, 0xF33E24FDF30EC015ULL, 0x2DAE9B78EA7803E0ULL, 
            0x7F33F86053C6664BULL, 0x83D1E37774A3B0CAULL, 0xCFB7EE5B938E3E5CULL, 0xF71AA8780C140D99ULL, 
            0x7F60AAF49ACD129EULL, 0x1A1D76F4BC227419ULL, 0x916CF7DF94E311F9ULL, 0x7F5B1D8257A44D74ULL, 
            0x115D4114F117FDB7ULL, 0x5FC064A45FF13FB9ULL, 0x908651B22B9806F8ULL, 0x29F586971172E0B0ULL
        },
        {
            0xAAD2039F76D47491ULL, 0x7E4B72EBCD730797ULL, 0xE3F5C508FF118DEEULL, 0xEBA497DA9726917EULL, 
            0x76CD93DC630166EEULL, 0x78D019DB9DC794D8ULL, 0xFC6BB28CE0A4153FULL, 0xF4DC2C4FC3884076ULL, 
            0x47DE947F808119D3ULL, 0xDD26249B950850EEULL, 0x6F34D826D6499A0EULL, 0x034DA93D3FE9289AULL, 
            0x576AB7F9C6C0073CULL, 0x18A784AEB9EEAA62ULL, 0x1590E4BC68243157ULL, 0x79B58007C771F450ULL, 
            0xBC7D5FC8FD9EEE16ULL, 0x2624E44D9CC74379ULL, 0xB15AC577B0CDE2DAULL, 0xDD5CA2EAB9E13DD4ULL, 
            0xAF80F74C93D54AC8ULL, 0x07B239DE08F85695ULL, 0x7DBA1D72A40E5D5EULL, 0x4713F82E26842EFEULL, 
            0x11B8CBFDEBDA273CULL, 0x12E76BE633F5BB4FULL, 0x9234FD6C0797DDAAULL, 0x49461C93E12F91F4ULL, 
            0x40168DE95E138810ULL, 0x210982EC68C8C9C1ULL, 0xDDD352F40CB929C0ULL, 0xB12C85D5CA04593AULL
        }
    },
    {
        {
            0xFFEE3EE0C14F3572ULL, 0x95E6840A5FBEB98AULL, 0x941EB19612785033ULL, 0xAC270F8A68555760ULL, 
            0xFD219FE7244F859CULL, 0xDC3981AAA0D47D41ULL, 0xF6A94C2276B0B7F0ULL, 0x779F6F2980E1A0BDULL, 
            0x3840AE3C437957EFULL, 0x91B8BDC54C78C9C6ULL, 0x69DF62D2CB5DD67FULL, 0x5AEFC1C51ECB1BB9ULL, 
            0x32C452DC05E0A0D3ULL, 0x5AC7A6AA360470E8ULL, 0xDCD06A2C8699EA83ULL, 0x348CA7C5EE2B24D1ULL, 
            0x1FB23D673DBD93F2ULL, 0x978D299FB1281D77ULL, 0xD6EA41FD4FA347ABULL, 0x367151088B06B0C6ULL, 
            0xDE86979E3D7A3DF2ULL, 0xB933862EE461EE57ULL, 0x0914BFC001884779ULL, 0x549D19579A982AF0ULL, 
            0x642F6B4494361C4BULL, 0xA1227F0A8C5F55FCULL, 0x7235C90515054498ULL, 0xE12638D59CCABB85ULL, 
            0xE74A766438F42D47ULL, 0x4E7765B7A7935B63ULL, 0x82C56B95F1C379CBULL, 0x99E152A77A3D1E4AULL
        },
        {
            0x716514C597A0A5CDULL, 0x154FB5F55BD08125ULL, 0xE1284B211C4882D5ULL, 0x8A257EE026EE7167ULL, 
            0xB727F923A460ACBEULL, 0x5A3204E1146F06E5ULL, 0x1623098A5B37DEEDULL, 0x52D0AF4C0E56D5D3ULL, 
            0x2D95BD202600CD11ULL, 0x5E3B4CFADC2B497AULL, 0xC43F3C42B6381B93ULL, 0x3C1E2DA9FD2D1C74ULL, 
            0xAA9C70540B2A41B4ULL, 0x1388E9281E39021DULL, 0xB5E64316EE12CECDULL, 0xD718EB9314114A9DULL, 
            0x0A3083165E8DC87AULL, 0x6226C640D472356EULL, 0xFA6F481EC932F58AULL, 0x3E274E8F252C6736ULL, 
            0xD2B1837DC744C6A0ULL, 0x553A0BCC31BDF55AULL, 0x815F93BCCE1A52E4ULL, 0x7ADECF92E9F872B3ULL, 
            0xDE05C94A37C77BCDULL, 0xB89D3B30B5E4B1CCULL, 0x0D21DF06AF85A132ULL, 0x8ABE08AC9B22E9A0ULL, 
            0xAD59079633739AC8ULL, 0x2B0ADD2D4542C1D3ULL, 0x78BF5BC5436F899BULL, 0x11D6ECDB3D19A931ULL
        },
        {
            0x7F954EBF27A2B279ULL, 0x48358D4AD87A8668ULL, 0x6D9358396269DC46ULL, 0xF0A6FAF1954A48AAULL, 
            0x3A5EAF5823645451ULL, 0xE14F6DAFC6848868ULL, 0x5F64DEAC6DC68936ULL, 0xC5F9D239FD5960A1ULL, 
            0x87B78DF3CCFD7E5DULL, 0xC83F898F9282C588ULL, 0x1E2A724B409DB7FFULL, 0x5D38B1AD2EEC5EEFULL, 
            0xAD6A7EFD0281D857ULL, 0x9795696A60534850ULL, 0x4B7E8F78AAA4C4F3ULL, 0x48EF234882643516ULL, 
            0x3A26312CDDA0EE4EULL, 0x602BF4BF4855C057ULL, 0x6106BA6B62BF60C8ULL, 0x219BC9C5AFED8B05ULL, 
            0x044927C90BF4FB8AULL, 0xD6C6259C9739D4E9ULL, 0x5F3124BBCFF39C8DULL, 0xDDA8D22292280768ULL, 
            0xEEB4ABDD13DD9D87ULL, 0x17621F01F89672A0ULL, 0xA8C7AEFF7CC843F7ULL, 0x380D0D78ADD97B06ULL, 
            0x907E00000A95BAFCULL, 0xA7C6E7352CAEBBD4ULL, 0x8BF615E3B6107B18ULL, 0x7A18F8D260F63A46ULL
        },
        {
            0x83B822C8D24D4A73ULL, 0x5A89D4604FCEBDE3ULL, 0x35D50E2D0B8769E1ULL, 0xFBBCBA278F87267BULL, 
            0x427360CDFD702648ULL, 0x5C7660D31B0521F9ULL, 0x8DA2626740773BC7ULL, 0xDA867DBB7A232EF5ULL, 
            0xEA0907E4D24A216BULL, 0x9175D9037FCAB521ULL, 0x2E439D268C20CE9AULL, 0xB47C7B5CEBD37FC2ULL, 
            0x1CE3B251B1B45513ULL, 0xBD24C5A228DFC569ULL, 0xDDCC20C7AB79069AULL, 0x51474A8D7286CDC5ULL, 
            0x8557D4E837F8DC2DULL, 0xE1C0AB13BD7F8DE8ULL, 0x2E98FBA91D78FB11ULL, 0x7A3777CEB3D852A6ULL, 
            0xC7FA5BD636A7A14DULL, 0x57BAF046C2F02AF3ULL, 0x49C0A89FEA0ACA2DULL, 0xA01CA46A092AAA1EULL, 
            0x1C08E37BEF7D166FULL, 0x65B4422D4DDB2C72ULL, 0x0DBC38C7678F6431ULL, 0x5C843DFA4CD96849ULL, 
            0xD41BC629A7646182ULL, 0x2E0D85E421FB2D19ULL, 0xF0657B224C9E1535ULL, 0xB52F9C27E4184FEFULL
        },
        {
            0x874D21C0C2CFB5A1ULL, 0x51F46F494E4091B5ULL, 0xAAD78353C06A5FF0ULL, 0xCD1C7B85D185D004ULL, 
            0x9FDFB0CD46598DB9ULL, 0x38583E5DCC9C077BULL, 0xA23AC6A4A1C8FA11ULL, 0x832A652763505E2BULL, 
            0xB88DEFEA283B1B96ULL, 0x9FF3F90D3963B00DULL, 0xB690931F43A29DFEULL, 0xE38D5CE855FA8840ULL, 
            0x01F86C6824A2FBBFULL, 0x090698A3BE0DA7DBULL, 0x23FE48A183B58B28ULL, 0xD9AF3DB13FDCB6EDULL, 
            0xED599CF15FF5ECE3ULL, 0x79D8C3FAAC96F013ULL, 0xD8FFB4645633FF72ULL, 0x4CBC78A177393108ULL, 
            0x3F15FEB8168A024EULL, 0x16074022CA85B0A8ULL, 0x4D11223BFA78164DULL, 0xDCD1E9D5E697FF43ULL, 
            0x7DEB5C62BE343DAFULL, 0xC27A076F4A6538BAULL, 0x868CF5ABCE594670ULL, 0x31CE14665C67B8C5ULL, 
            0xEF951428736476D9ULL, 0x835826D7452DECA0ULL, 0x0BD6A4B9C3F8AC51ULL, 0x92ABFAA963DF92D0ULL
        },
        {
            0x8341DCD71BF31508ULL, 0x2996E4890A6C1741ULL, 0x27C145B91F1C8A53ULL, 0xA520FE08075D2E11ULL, 
            0x4239A160D8E1CC40ULL, 0xAF3C41A131BC5FC5ULL, 0x0C45B8264BE2166AULL, 0xBACC7EB277EE95CEULL, 
            0xB4A471B5493BAA0FULL, 0xFFA2C23E2FF2C0CBULL, 0x668A888BB1C53CEFULL, 0xC92C781D3080EDBAULL, 
            0x6A5B9ED7853BE63CULL, 0xBE3058757F44D7A8ULL, 0x69C10B78DE92FD77ULL, 0xD59C18CD4F7A3BC2ULL, 
            0x81156D4375C8D085ULL, 0x4BC8EB405E97FC22ULL, 0x8917653C906632E1ULL, 0x963635186689B3E8ULL, 
            0x257C0134E70B1464ULL, 0xF1474C58D12D8777ULL, 0xE11534366B384A3BULL, 0x145ECF46A43EBC27ULL, 
            0x8FB6DE6C8133C5C4ULL, 0x1E6F3F5384BC3F90ULL, 0xD91B46CF1870EF78ULL, 0x131C10C97800708FULL, 
            0x2CCB8BE011E15EA0ULL, 0x76A8721D78A500C7ULL, 0x784B9B5FFF4CFDE2ULL, 0x998333C9926DE2C8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Achernar::kPhaseDConstants = {
    0x6AB20494725C826CULL,
    0x7460EB29E8885E42ULL,
    0xF0DE19F07318A8D9ULL,
    0x6AB20494725C826CULL,
    0x7460EB29E8885E42ULL,
    0xF0DE19F07318A8D9ULL,
    0xDCE88C5469832FB1ULL,
    0x08E393F3906AE715ULL,
    0xE1,
    0x54,
    0x8D,
    0x8F,
    0x01,
    0x13,
    0x62,
    0x13
};

