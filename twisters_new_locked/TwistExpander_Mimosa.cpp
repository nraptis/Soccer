#include "TwistExpander_Mimosa.hpp"
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

TwistExpander_Mimosa::TwistExpander_Mimosa()
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

void TwistExpander_Mimosa::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xAE8AB894B97AF041ULL; std::uint64_t aIngress = 0xDD27E652BCD76039ULL; std::uint64_t aCarry = 0x89FF96D86ECEE6C4ULL;

    std::uint64_t aWandererA = 0x86136602D25509FDULL; std::uint64_t aWandererB = 0xE83258B5AE8A9851ULL; std::uint64_t aWandererC = 0x97874A7A8F5512ECULL; std::uint64_t aWandererD = 0xF8EEA1218F4012A1ULL;
    std::uint64_t aWandererE = 0xE6649B1C95C1BD10ULL; std::uint64_t aWandererF = 0xC58B35964F9E04A9ULL; std::uint64_t aWandererG = 0xB1D001AF9824C0E8ULL; std::uint64_t aWandererH = 0x90D1DCFB0D5830DEULL;
    std::uint64_t aWandererI = 0x9EABAC843749B573ULL; std::uint64_t aWandererJ = 0x9DE4C83AA2552F75ULL; std::uint64_t aWandererK = 0xA09229F715323DA6ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xF426E57F591589D2ULL;
        aCarry = 0xF3574933F565A8FDULL;
        aWandererA = 0xD259D3A021FD3D35ULL;
        aWandererB = 0xE0176C38625D748FULL;
        aWandererC = 0xDABF43F4D0B6E469ULL;
        aWandererD = 0x843794C7C1A4A30EULL;
        aWandererE = 0x82F20CA31C85C432ULL;
        aWandererF = 0xAF5B10C5500B38FFULL;
        aWandererG = 0xAB8CB548BA920B41ULL;
        aWandererH = 0x9703351BBFDB1F52ULL;
        aWandererI = 0xE31FEFE7930FAF11ULL;
        aWandererJ = 0x9F255433F68FC242ULL;
        aWandererK = 0x93B953445A0D100BULL;
    TwistExpander_Mimosa_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Mimosa_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Mimosa::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB5F495A7942B78A4ULL; std::uint64_t aIngress = 0xCA2934401FE056B1ULL; std::uint64_t aCarry = 0xC9D3572461D6A683ULL;

    std::uint64_t aWandererA = 0xB6FAAA6B61E51035ULL; std::uint64_t aWandererB = 0x9F172B4A46B7478DULL; std::uint64_t aWandererC = 0x8EE471C1634F53D3ULL; std::uint64_t aWandererD = 0xE7B0D86652235382ULL;
    std::uint64_t aWandererE = 0xAB9C7145CE96CCE5ULL; std::uint64_t aWandererF = 0xC9E94231C3292561ULL; std::uint64_t aWandererG = 0xD23463F9F2C5CCF5ULL; std::uint64_t aWandererH = 0xA04457D6F9AC06B3ULL;
    std::uint64_t aWandererI = 0xC00D9FECB1ECA7A5ULL; std::uint64_t aWandererJ = 0xEADF5A90D1AFA86AULL; std::uint64_t aWandererK = 0xC607D7D5F312980FULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xDD5D539806519ACAULL;
        aCarry = 0xA0F9B5E3ED45C8F0ULL;
        aWandererA = 0xFC84C013925867C6ULL;
        aWandererB = 0xFCE4AA4CB26F271EULL;
        aWandererC = 0xB924E9930E90EC44ULL;
        aWandererD = 0xE708C51A297AAD4EULL;
        aWandererE = 0xE811E026ECAE4E48ULL;
        aWandererF = 0xF80B1F10431ADE9CULL;
        aWandererG = 0xBBE499FCA29EA635ULL;
        aWandererH = 0xD5080D98AB86E141ULL;
        aWandererI = 0xE09E3105EE2A1A21ULL;
        aWandererJ = 0xA18E7327BB03D972ULL;
        aWandererK = 0xD1010FC9C02BE3E3ULL;
    TwistExpander_Mimosa_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Mimosa_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Mimosa::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x99984C5B97DEA757ULL;
    std::uint64_t aIngress = 0xFD8BD543DBC7B48EULL;
    std::uint64_t aCarry = 0x96D2D2632904C9FBULL;

    std::uint64_t aWandererA = 0x85DAC345FDCCF5C9ULL;
    std::uint64_t aWandererB = 0xCA6BAB3110371749ULL;
    std::uint64_t aWandererC = 0xC8B67B87E82B51AEULL;
    std::uint64_t aWandererD = 0xBE2D0E6AFF5A7384ULL;
    std::uint64_t aWandererE = 0xD7770884782011D0ULL;
    std::uint64_t aWandererF = 0xFAE2559B651001E2ULL;
    std::uint64_t aWandererG = 0xE3B4D668163AA8EAULL;
    std::uint64_t aWandererH = 0x819627DB43C77728ULL;
    std::uint64_t aWandererI = 0xAEE2F27C6F520BFDULL;
    std::uint64_t aWandererJ = 0xB52BF6C634DB4BE5ULL;
    std::uint64_t aWandererK = 0xD761C098C286684BULL;

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
    TwistExpander_Mimosa_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Mimosa_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Mimosa_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Mimosa_Arx::GROW_A(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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
    TwistExpander_Mimosa_Arx::GROW_B(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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

// SmartSquash candidate 19 of 33
// Exploration cases: 100000000
// Nearest-family diversity: 923 / 1088 (84.83%)
// Total distance from earlier candidates: 16742
void TwistExpander_Mimosa::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    static_assert((S_BLOCK / W_KEY) == 16, "SquashInvestToKeyBoxes expects 16 invest fragments.");
    static_assert(H_KEY == 8, "SquashInvestToKeyBoxes expects 8 key rows per box.");
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 5U), *aFragmentB = aIceLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 12U), *aFragmentD = aIceLaneD + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 919U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 466U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1156U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1921U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 13U), *aFragmentB = aIceLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 15U), *aFragmentD = aIceLaneD + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1096U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 192U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 325U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 178U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 3U), *aFragmentB = aIceLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 8U), *aFragmentD = aIceLaneD + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1123U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1093U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1483U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 21U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 15U), *aFragmentB = aIceLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 5U), *aFragmentD = aIceLaneD + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 997U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1577U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1587U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 277U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 1U), *aFragmentB = aIceLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 11U), *aFragmentD = aIceLaneD + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1297U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 610U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1915U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1368U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 0U), *aFragmentB = aIceLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 2U), *aFragmentD = aIceLaneD + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 999U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1662U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1720U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 498U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 12U), *aFragmentB = aIceLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 14U), *aFragmentD = aIceLaneD + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 920U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1049U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 34U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 811U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 11U), *aFragmentB = aIceLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 1U), *aFragmentD = aIceLaneD + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 7U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1858U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1359U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 161U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 8U), *aFragmentB = aIceLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 9U), *aFragmentD = aIceLaneD + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 136U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 330U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 681U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1932U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 14U), *aFragmentB = aIceLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 13U), *aFragmentD = aIceLaneD + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 216U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1424U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1886U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1213U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 9U), *aFragmentB = aIceLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 0U), *aFragmentD = aIceLaneD + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 877U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1229U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1142U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 820U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 10U), *aFragmentB = aIceLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 10U), *aFragmentD = aIceLaneD + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 711U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 257U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 472U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 380U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 7U), *aFragmentB = aIceLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 3U), *aFragmentD = aIceLaneD + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1926U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1737U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 2033U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1776U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 2U), *aFragmentB = aIceLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 7U), *aFragmentD = aIceLaneD + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 517U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1533U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1967U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 590U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 4U), *aFragmentB = aIceLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 4U), *aFragmentD = aIceLaneD + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1916U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1713U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 649U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 236U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 6U), *aFragmentB = aIceLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 6U), *aFragmentD = aIceLaneD + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1151U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 2024U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 2042U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 933U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Mimosa::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xAFCCA75AA05AB88CULL; std::uint64_t aIngress = 0xD18BA1FF9FF202D6ULL; std::uint64_t aCarry = 0xEC076E8F6E1D4089ULL;

    std::uint64_t aWandererA = 0xB5C9F88F35ECB188ULL; std::uint64_t aWandererB = 0xF20318BCF4D690FEULL; std::uint64_t aWandererC = 0x95DD9A4BB7901576ULL; std::uint64_t aWandererD = 0x802C933EB32F51BFULL;
    std::uint64_t aWandererE = 0xF3AF8D9779124D65ULL; std::uint64_t aWandererF = 0xE4AA558CC13591BAULL; std::uint64_t aWandererG = 0xA50D7164F6C9D709ULL; std::uint64_t aWandererH = 0xAF1B3F67411F37D4ULL;
    std::uint64_t aWandererI = 0x856D37155DDED867ULL; std::uint64_t aWandererJ = 0xA5B57142C96DC5F1ULL; std::uint64_t aWandererK = 0xDF7D557D6EF78528ULL;

    // [seed]
        aPrevious = 0xEFDAB2523CCC113AULL;
        aCarry = 0xF44167B43A88A32EULL;
        aWandererA = 0xF9A6895C75292F8AULL;
        aWandererB = 0x8D3582AF8DE20A47ULL;
        aWandererC = 0x853A4919F11040EBULL;
        aWandererD = 0x8AC374E22494593AULL;
        aWandererE = 0xE20FB12342F3A1B5ULL;
        aWandererF = 0xD521ACACE47583C7ULL;
        aWandererG = 0xAF42887C8B5F6D22ULL;
        aWandererH = 0xDD95615C4B266980ULL;
        aWandererI = 0x825CF04D6ECDBEC8ULL;
        aWandererJ = 0xCC55E1AAFCF9A99BULL;
        aWandererK = 0x8AB025B1050EB336ULL;
    TwistExpander_Mimosa_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Mimosa_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Mimosa_Arx::Twist_E(pWorkSpace,
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
    TwistExpander_Mimosa_Arx::GROW_A(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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
    TwistExpander_Mimosa_Arx::GROW_B(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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

// GrowA candidate 19 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 9796; nearest pair: 486 / 674
void TwistExpander_Mimosa::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 369U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7422U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6806U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1315U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7583U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7860U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5126U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4734U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3855U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1817U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1607U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7199U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2003U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4041U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3947U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1840U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 793U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 147U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1312U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1278U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1637U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 910U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1199U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1857U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 605U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1624U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1769U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1572U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2037U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 979U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 390U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1514U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 748U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1799U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1451U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
}

// GrowB candidate 19 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 9807; nearest pair: 435 / 674
void TwistExpander_Mimosa::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4973U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 509U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8173U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5152U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 909U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2027U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 579U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5062U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4235U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1027U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7108U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 685U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2490U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 133U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 805U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8096U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1081U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 542U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1942U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 586U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1369U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 156U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 555U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1923U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 987U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1794U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1408U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1804U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1351U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1478U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 238U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1353U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1628U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 420U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1623U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 354U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
}

const TwistDomainSaltSet TwistExpander_Mimosa::kPhaseASalts = {
    {
        {
            0xE1E9D1631CD8FE68ULL, 0x88BF9896F5313DA6ULL, 0xF31A8DDBF72CEF96ULL, 0x2C0CDC6214714D49ULL, 
            0x7192497EA229FB4CULL, 0xDC5B4D7613FD535FULL, 0x877FF1B227F33B64ULL, 0x954ED48EE7127759ULL, 
            0x3BE7ACDEDA827B86ULL, 0x0173EBA5C8DB3FA9ULL, 0x63A789E66BB90E77ULL, 0x995FD94A9BBC3874ULL, 
            0x5F04376B41FE514DULL, 0xA58DBA5F47BB2BAFULL, 0x2AE8D50B295CF1E8ULL, 0x89ECFA2FC1396193ULL, 
            0x9EF55DD347347411ULL, 0xD5CCBA8752BBFE09ULL, 0x155964EDF6B9C11AULL, 0x95FECE6ABEBDDBB6ULL, 
            0x03EF5311A5C1C5BAULL, 0x206E7110C100CC1EULL, 0x52CC83EF59ADA7C9ULL, 0x7540FD94A89DE40DULL, 
            0x248127FF8D08CD33ULL, 0x434A89F3834871BAULL, 0x3A23C29EA7C89BB4ULL, 0xE79D4A3BCFA31322ULL, 
            0xA1DCCA6069F7EBFAULL, 0x62D18CA7A4CC3191ULL, 0x6AAD28B0ADD63445ULL, 0x8F699C9381F3DB92ULL
        },
        {
            0xC1DEF7CE8B0457EFULL, 0xBFD0CCB72F6ABE9AULL, 0xE20493029108596AULL, 0x3DA9C0E4BB3E0839ULL, 
            0xD7F1B062B0ED467BULL, 0xAB7E0BAD7127D962ULL, 0x35806210A9EB105AULL, 0x875DDD9DD5D7DDAAULL, 
            0xDB12C465663166E6ULL, 0xDBA24447AF713C0BULL, 0x09A5275BB21B637DULL, 0x8E3364D052C8462DULL, 
            0x819ED9694685E1B2ULL, 0x5FA5FB5104C8F538ULL, 0x536542B96E0DE976ULL, 0xBE0025FBCD13B488ULL, 
            0x489A17D8C7D8BAD4ULL, 0xC7DB0C03C4164D72ULL, 0x33A75C81F66A82FEULL, 0xF63782407A44E771ULL, 
            0x3D581F11C1E90F5FULL, 0x105620472334B25EULL, 0x19DCD7061743C205ULL, 0xB6F3FB4C4189559CULL, 
            0x863E669D5EB187F4ULL, 0xDFFB2B1F932BC140ULL, 0x4C78051425C5FFBAULL, 0x49D2B89FC5DDAECFULL, 
            0x7A8C6DD40167E221ULL, 0xAAE343AF5656D404ULL, 0x066DF075DE96F675ULL, 0xF418D6A8858B58D5ULL
        },
        {
            0xAEA2C0DB48599079ULL, 0x3F841CF4ACA7CDD1ULL, 0x61B54CFED11D2916ULL, 0x9889234C2E9E8698ULL, 
            0x90E2D08EE17E0FF8ULL, 0xE6706A2F981CB7B7ULL, 0x8F424DE512747B70ULL, 0x3693190D8629D0E2ULL, 
            0xCE9B60250C551E0AULL, 0x2C5D2AB4A85AFBC7ULL, 0xD1E72E166913A8D1ULL, 0x9D0F7A0054592B86ULL, 
            0x10C25A462D1E3571ULL, 0x32B90BCC9387A211ULL, 0xC782D02F407085B4ULL, 0xF5A8AD3AB9E575D4ULL, 
            0x63E0A857A4C48376ULL, 0x48D6378DED3CC0C4ULL, 0x9C47F006D7B2D59AULL, 0x0C49443F32B2EDE3ULL, 
            0xBF05CAB948521934ULL, 0x90E935B84549F5B9ULL, 0x22D73F932F35E48CULL, 0x21DD4992C5BE8C68ULL, 
            0xAF170DD6B35C7082ULL, 0x7FA1EF38103AA571ULL, 0x9C0429F79F360776ULL, 0x4050D6BFD7FF1300ULL, 
            0x9927B576DB20D905ULL, 0x1F119B845128B3DEULL, 0x8353BB1DBF976014ULL, 0xEBE4C1CE06CC5D52ULL
        },
        {
            0x7F9301EEBA2F4EEFULL, 0x511E30B2B0899C21ULL, 0x76AD1580AEE7AEE5ULL, 0xBAB8DB7156749723ULL, 
            0x51FC80F24B0D84BAULL, 0xFE4CDD40321D3A7BULL, 0x1024D11772CC4CBBULL, 0x87DF0ABCC9CCA29AULL, 
            0xDF59693FB6D18010ULL, 0xA387145A16E40EF3ULL, 0xEFF19BA4A94CA807ULL, 0xFBB8C684F64B398FULL, 
            0x69B0241E1C00C47CULL, 0x605C9351B17CB63CULL, 0x1C39E9F97C180C61ULL, 0x9B1815598BABE1B7ULL, 
            0x9485C1F586378049ULL, 0x1DEA2C826AACCE3FULL, 0xAAC85617DCCA2707ULL, 0xC80D1D8973EF1CAFULL, 
            0xAC5B9FD60374389CULL, 0xDC09F85A96DA6E98ULL, 0xCD866AA6FA341BD8ULL, 0x378D73165ED55675ULL, 
            0xED51E08618056C97ULL, 0xCDEF341E5D7DF620ULL, 0x67136B02D9ED5F55ULL, 0xE02C508418F8D269ULL, 
            0x58BFAB83CC20A5D2ULL, 0xB6651AB531371E50ULL, 0x83111A07EAB194AAULL, 0xA5B3308E6ABBAB63ULL
        },
        {
            0x6325B4418E9EBEEBULL, 0xDE66B22A3B1842B5ULL, 0x27FD74667992B8C4ULL, 0x1B53F3EE825F0CC7ULL, 
            0x0EB0AB9D452EBAEAULL, 0xCB79EA80E5DB4007ULL, 0xBF1644D57588B686ULL, 0x3E04ACEE5C9D441DULL, 
            0xC3B415F2C6E7BA11ULL, 0xE3C11C90F76EE7B6ULL, 0xBC4F73C800AEB210ULL, 0xD8C2534945F44345ULL, 
            0xB3D868CDA7590152ULL, 0x5047804F37FBFEF7ULL, 0x17682ED95FEBD9A6ULL, 0xB4FAFCD9355E803CULL, 
            0xFF39241CD88162FFULL, 0xAC47E6736EBE8B74ULL, 0x903BD23C59B01BEEULL, 0x2FF9C54EF5AB7B6FULL, 
            0xBF6BCF903E11C5AEULL, 0x41E2E8F6894891F9ULL, 0x4D700371C9213627ULL, 0x720E2C2C1E6407C7ULL, 
            0x478449EDC2F927EBULL, 0x6935A538CD638F71ULL, 0x9FB52836EF11EB13ULL, 0x60A95C3AC609E198ULL, 
            0x401ACE5A285E1D45ULL, 0x3C1DC394D6954F5DULL, 0xA04FEC8995D4B7F9ULL, 0xAEB83E9B2557DF21ULL
        },
        {
            0x795D9B5BDCBE1693ULL, 0x974AD334FF9B3A0BULL, 0xDF330D3B0C9BB700ULL, 0xDE7CA98590D36810ULL, 
            0xE87A8B1EA8FDE26DULL, 0xA457A3F0EA2B505DULL, 0x9FF94F77627644B2ULL, 0x5589A1A92D5E1EB4ULL, 
            0x46EDF0A14679E2FBULL, 0x8F82077557E0824FULL, 0x0F126D575F220489ULL, 0xFCFA8A577BAED91FULL, 
            0x0B79A4F836337BFDULL, 0x318631E9FEF3BC8BULL, 0xF9133A822184D986ULL, 0xE5F979D51A584501ULL, 
            0x7B8CCCD95C06CC7DULL, 0xCA43DB4EE63ECAFBULL, 0x5D21B43087685219ULL, 0x36ADD704A40BF833ULL, 
            0x7A4A2627A83269C7ULL, 0x450384C5624AF324ULL, 0x45E316F752E46D18ULL, 0xA74FF6DECED863C1ULL, 
            0xFBF29D6E533B13B4ULL, 0x4A8AE4CC4AA6C422ULL, 0x14FFF44601B70AF5ULL, 0xFC78258D6BF764F1ULL, 
            0x4D597FB55B2A5463ULL, 0x7C631170B68E9C66ULL, 0x445287E4BC48ED32ULL, 0xB45D6925821B8746ULL
        }
    },
    {
        {
            0x1C278DF9633C6F46ULL, 0x95EE7276B318A9EAULL, 0x9B99451911A9AEE4ULL, 0xE727F6A93099CCA8ULL, 
            0x1AF6B8529A729FE9ULL, 0xD52B534825C70FB7ULL, 0x0F1FFFB157146D98ULL, 0xA4F607B24C6CABDEULL, 
            0xA6B1858FAA1DB5C5ULL, 0x8A71CD801D10125FULL, 0x6569157F9C672AA6ULL, 0xE938D053CCEC13FEULL, 
            0xD73DBD19B1F0D9E7ULL, 0x6115EE42C05F803BULL, 0x920B2E94B986209EULL, 0xCD156D197C46D853ULL, 
            0x0A04F9CAC02208A4ULL, 0xDDC39B4911776481ULL, 0xD626D062A9DA650FULL, 0x52E5F421D3F76947ULL, 
            0xDAE3A435242EB645ULL, 0x69FEAA616EF2EC11ULL, 0x8DB6F4ADD5474A0AULL, 0x02EBFB82B7A07915ULL, 
            0xA2BE3FA984DB4D2BULL, 0x8E4C2474D07199D7ULL, 0xE94386AC8CBBB0D6ULL, 0x5411BD423D834026ULL, 
            0xB963727477AC1D58ULL, 0xBB80191D116ACBF8ULL, 0x7320AACBD0059C40ULL, 0x460A1C3C645B9E72ULL
        },
        {
            0xF1551387E6D7F60CULL, 0x4E29E13EF20BC88EULL, 0x395625FAA1129B2BULL, 0x4A2F7A5224737B46ULL, 
            0x39C60B2EC75AABFBULL, 0xD16ED6A1DE70FEF5ULL, 0x041AE0F2116162ECULL, 0xE22C457C8F858AA6ULL, 
            0x5B28E75C94A80B52ULL, 0x01C1F5F714B28D28ULL, 0x79FE435E3AE5592BULL, 0xA51CA6DBCD177963ULL, 
            0xC69E06ADF0ADE725ULL, 0x1AAA7B19C55F4B7DULL, 0x5A68F498785E6B99ULL, 0x04F07B1744EE941EULL, 
            0x2C7E89638027AAA3ULL, 0xF2DFBB0B42F18CB1ULL, 0x1E49C0BF92EB1C24ULL, 0xE5883B79777B800FULL, 
            0x94D3C794A5F6C1BFULL, 0x09DE11FA889F6FECULL, 0x3C3E05815D2EE6D9ULL, 0xBCB862908B184373ULL, 
            0x99A71A6B5DDB5C6EULL, 0x0019EF2C06B2916DULL, 0x25C2221A5D8C1D8DULL, 0xB11394B4E98DA47FULL, 
            0xA8FCC32218ED2428ULL, 0x858EC3DA5C4D3ADBULL, 0x4A8C80A58E9F596FULL, 0xB7A20B55B7440349ULL
        },
        {
            0x0CB55DB448FFE14DULL, 0xD5C18BFC17E17606ULL, 0xF952BA021E1A05E3ULL, 0x809AD9188A880273ULL, 
            0x2EA39F986A70DEF8ULL, 0x856CCFC348AF4F8DULL, 0xA91CC8B8F5B22D00ULL, 0x43C86A9BF0779833ULL, 
            0x234F66E2A5C9871EULL, 0x9FC460D52BC636BDULL, 0x1ABFB82032299194ULL, 0x8443D63F3F3D56DFULL, 
            0xC411A08115F1EA7CULL, 0x1A5C806DE97E2FC0ULL, 0x05F45C4FD0A46B8BULL, 0x8323E7C577206A52ULL, 
            0xA6FD86F1CDAA8F00ULL, 0x8AD97AF8821B5F83ULL, 0xED6549C4C8A0FE2EULL, 0xCBBC2FBAB5C428EDULL, 
            0x1C751E6E429537ADULL, 0x80083927100AB3A9ULL, 0x50755702FB2F42DEULL, 0x38BCF866B9D46F99ULL, 
            0xB0FEAC03B22E9A51ULL, 0x17B635C6277F18D3ULL, 0x1BC1F340E2915AAFULL, 0xB6550199F5115F17ULL, 
            0x7395FED625FC2C4FULL, 0xBAA0170869A887D5ULL, 0x487DA9958A551301ULL, 0x565CCEB53DB468DCULL
        },
        {
            0x7FF7563A397F96CEULL, 0xAF0DF4689894E25BULL, 0xA037C4722FCFBDE8ULL, 0x43C96CCBD20E5106ULL, 
            0x35D9C4DB2CCC98DFULL, 0x7D0C6C741EE2B8E9ULL, 0xA2502454982A209BULL, 0xF70E4C2319C3099AULL, 
            0xCA470E4DE972F6C4ULL, 0xAEC486F5F713E23CULL, 0x7F0F8112C7ECB836ULL, 0x944BCD36A87A1846ULL, 
            0xAA82C524AD5AC5A5ULL, 0x84DEF71BCA190967ULL, 0x2B19BEB01EE1F39BULL, 0xD4F1A99E0575AA31ULL, 
            0x20755CFBA7FE7AD3ULL, 0xC208473A761AE1F0ULL, 0x6B5153C0443BEF5BULL, 0xF162DA888D065857ULL, 
            0xD3FC0B33539A4DF2ULL, 0x6537FE5B3669CFD2ULL, 0x9299E7CB6EE6B616ULL, 0x34B451EDE2457A8FULL, 
            0xBB608523E2BD62E8ULL, 0x7A46248C249AD819ULL, 0x20F56D4E1C634E28ULL, 0x9761E4AAAA96D7F8ULL, 
            0x4B78636D6FD79C69ULL, 0x423E3E3F2DFD1725ULL, 0xA7EDC7627F9E67F7ULL, 0x82BECA0F84CCAB43ULL
        },
        {
            0xC411F3DAF5C56E78ULL, 0xB5CC0544C73168E5ULL, 0x9453FD561FC2D893ULL, 0xC28EDC9C129F9EFAULL, 
            0x58FBF3F24D39F8A2ULL, 0xBAA7ECA9EDB86630ULL, 0xD8DB51E255EFA2E2ULL, 0xA1BB05BE1845181DULL, 
            0x4A0EA4B07B1CEFA4ULL, 0x62D427F70668A567ULL, 0x4BCBE0E3E9A80F2AULL, 0x7B237C7E198B266AULL, 
            0xCC451AFAD6F46087ULL, 0xDEA6FD3C48821806ULL, 0xF60BE7094D48EF69ULL, 0x3583C030658472CDULL, 
            0xE15B1F70B427A3B0ULL, 0x366B990B9E38D01BULL, 0x13DA62D5C09C92CFULL, 0x67A06CC36DB0856EULL, 
            0x974D4237238C8D72ULL, 0x7CA45FAC6570DC69ULL, 0x56DC99BBA29CDCB2ULL, 0x1875956776016AA0ULL, 
            0x1AE6EDF4FF30E7BBULL, 0x5FCAED76A81456C7ULL, 0x62F4710F537D35C4ULL, 0xA3CA3EF3C2DB4349ULL, 
            0x28E60BDFDEEAEEFEULL, 0xF1C6A2C2F55B0B6EULL, 0xFF5EC8331F4E4E99ULL, 0xE7EAFA9E387D748DULL
        },
        {
            0xBBA5C60025FF0162ULL, 0x815BE52B5083BC68ULL, 0x55B3B6B8F345D692ULL, 0xF9ACD73165196A0BULL, 
            0x9AD8B4000C2FDB22ULL, 0x8A93EFCD35DA0413ULL, 0x3FC19EC427EFB4A0ULL, 0x965E1309D6203B70ULL, 
            0xF057E50126B994F4ULL, 0x0056720C5F03A333ULL, 0x697940BE0496D041ULL, 0xA3B916F47A96C52DULL, 
            0x3028A96CCD571298ULL, 0x145B1610D09305B8ULL, 0x90EEB0E6CBA3319FULL, 0xA8D656BE8C1E14FCULL, 
            0x5CF6342FB650DB7EULL, 0xE40B9E1F3D6BB579ULL, 0xFAD75F2F92CE0E4BULL, 0xBB1CDBF6C6377068ULL, 
            0x6DD94B1AABA913E4ULL, 0xFD45F3CD834BAEC2ULL, 0x5DF5C327CA5A7512ULL, 0xBC78D22BB3D50E52ULL, 
            0x4FB309DFAE167F0DULL, 0xC52800FEE22D4FA6ULL, 0x6F37152BFC2204FAULL, 0x239B43204F9B4119ULL, 
            0xC914E58CE81C58CBULL, 0x1E87ED50CE8516A8ULL, 0x74A73EE56B0F3DE9ULL, 0xDBFD7509B3C040ECULL
        }
    },
    {
        {
            0x2F0B61F4B4000472ULL, 0x6CEFA7AB02194925ULL, 0x779B4756D4B1EF41ULL, 0xC5B48EBD9A51B38CULL, 
            0x36FF9702663868BEULL, 0x8A79D792997A32BBULL, 0x1A253398CAD62E30ULL, 0x11656D83EB1D2BC4ULL, 
            0x6242D32E22A3D740ULL, 0x027D1D970D738528ULL, 0xED57B1393512F638ULL, 0xFDB9A4F50D7412A9ULL, 
            0x5FCC6EACDEB89FDCULL, 0x69AD18C558C72408ULL, 0xE045A722B180BBF2ULL, 0x787614F90E73B6C6ULL, 
            0x96470334E126FEE7ULL, 0x44714B96664F9564ULL, 0x87AF5C7A4437BF8AULL, 0x2362D54633EB51D0ULL, 
            0x0FABF91AA892D8B1ULL, 0xB98EB82E66577A95ULL, 0x45B34B77513DFAF2ULL, 0x93405C544F1F0016ULL, 
            0x21866BB3912A9FF5ULL, 0xA8D0AA378D9E9576ULL, 0x7162C9DD2D8BC428ULL, 0x62818DA1F3FFCB75ULL, 
            0xEBE7A74CA804DEE6ULL, 0x05A0BC9D169DC842ULL, 0xF8242C77A1B45A51ULL, 0xE412A4A9585C31AAULL
        },
        {
            0xD0C7CF9DB67F22A1ULL, 0x473FE84845D72823ULL, 0xB4C9D70B2D5FC90FULL, 0xBA8E3B1FFE1A198FULL, 
            0x69C00C14709EAE31ULL, 0x1043074517D615C6ULL, 0xFE38B0F1F703D83AULL, 0x73EBAC7FA44EA8DAULL, 
            0x9DDF0637A0ADC6B4ULL, 0x2697B8639352F32DULL, 0xADFCA2D43A315747ULL, 0xE7B5EF8FA7FC2169ULL, 
            0xF08E66CDD232EB0EULL, 0xE3717047656528ADULL, 0x1421E39050AD615BULL, 0x24AE4CE49ACAFC2EULL, 
            0x51C75CE97695D37EULL, 0xEDDC487AEB48C573ULL, 0x803E4E7F26B16EECULL, 0xEFEF4806B9D07214ULL, 
            0xF2E75C9CF321EE59ULL, 0x10283F1C01D9614CULL, 0x4D7859EA40AF618BULL, 0xB7AA294473757E40ULL, 
            0x0A3B7ECAEBE27496ULL, 0x3A34466D4854203DULL, 0x8A652637174B4B44ULL, 0x420C92CA4B52F2C7ULL, 
            0x8A9B63366634F1E6ULL, 0x47B9466DDADAB8C4ULL, 0x0F05B894DE3CE672ULL, 0xEC2A25B4C5934A90ULL
        },
        {
            0xAEF8752DEF06965BULL, 0x1A3FE6C510CEC9B8ULL, 0x554EECAE9E906107ULL, 0x6CD1B38DBAAEEBD5ULL, 
            0x7B203888200D981FULL, 0x9FE8FEF935815606ULL, 0x85EE467D392B2C00ULL, 0xE2DC82631F8BD8C9ULL, 
            0xA716105890CEBBA7ULL, 0xD4AA0D274B54A0C9ULL, 0x83844CD115595ED0ULL, 0xF21DBFEDC97BBEAEULL, 
            0xB45143D09FEA5D24ULL, 0x8F3DB0992D85F238ULL, 0x74840D37BEFB1560ULL, 0x70815194412DF1F4ULL, 
            0xAC5736DB8D0A199EULL, 0xE375D274ED39593AULL, 0xA37E056A22D10D1AULL, 0xFE6266011AF06902ULL, 
            0xF6A51633C65DE0CCULL, 0x399A29BF6BBDF03CULL, 0x52042A694D3358E2ULL, 0xA604E7F7059488DDULL, 
            0x6992545B932A9A52ULL, 0xDBEACAA569CE4D69ULL, 0x249153E0B5806091ULL, 0xD135BF9E0A8C6965ULL, 
            0xDA9A29AC1848ED8DULL, 0xFC408BAECC6F71CAULL, 0x8781CB556213AF18ULL, 0xF417C33C174FE7C9ULL
        },
        {
            0x12FB32B6A2F6EB83ULL, 0x78723162A9C14FBDULL, 0xA001D4B0BBF4878AULL, 0x6F5C6764EA6DC7B3ULL, 
            0x02716A7A5C963347ULL, 0x92853D3D1E22EF7EULL, 0xD3A06E7894CB7655ULL, 0x951A53C47D0CFA2AULL, 
            0x519D795900D5099EULL, 0x66707B488B90A607ULL, 0xBF6D478DF26354F2ULL, 0x9D7D2746D28F2D1EULL, 
            0xC1122E7444F8961BULL, 0x6750165417EF879BULL, 0x4FC9F58EAF1C16B7ULL, 0x52338099FDD1302EULL, 
            0x63F4DC841A15FA79ULL, 0x43D3B715F3FF834FULL, 0xD4C78565BFAF879FULL, 0xFA53D51FAFD54733ULL, 
            0x273E705EF848C0B0ULL, 0xC66040DE11CB23ACULL, 0x2BDB33B4D45E8759ULL, 0xE220470AC2151743ULL, 
            0x402DB1270273DD11ULL, 0xA43EC25E4DDA39AEULL, 0x1A74D759699EA5E4ULL, 0xF93A7B7286E921CEULL, 
            0x26D500F8A379045BULL, 0x7C5497CCC658AE2CULL, 0x851304ABC486E5D0ULL, 0x1C18A083866C4E22ULL
        },
        {
            0xD203248EC9B0EF4EULL, 0x00A0439EE60C9547ULL, 0x7ED95314AF1EC998ULL, 0x1723B09829D8EDD1ULL, 
            0xE1764623DEF90C4FULL, 0x58A6B840141ACEF6ULL, 0x6CA78438E1017CD1ULL, 0x37F34534A3D65F70ULL, 
            0x66DC5957EF4108D0ULL, 0xAAFAB2CAE7670310ULL, 0x8B538176C597DAE4ULL, 0x5A45BF30D6F3D720ULL, 
            0xFC645CAF0B50035BULL, 0xAF94D785449E9ADDULL, 0xD2B446D0A4C1E16EULL, 0xD163FC52D91B71FDULL, 
            0x91C3AB94C2B4C2ABULL, 0x6E880C4EA74B9597ULL, 0x9921E0C300F6FC6CULL, 0xE779B712B763DC1CULL, 
            0xFDD04B5B726427EBULL, 0x804B475FD0390E0FULL, 0xAD9572B84731734AULL, 0x4B54C2784B5A4682ULL, 
            0x5DFF2960EEE05965ULL, 0xF3A6A6EC2AA0FD01ULL, 0x8B9D882E6E8C2FD8ULL, 0x4C09D3CBD19A9640ULL, 
            0xDEDFC5A8A4E1C649ULL, 0xDAB2D1BF17886115ULL, 0x51A722147B3D5CF3ULL, 0x65AE2BE12802972FULL
        },
        {
            0xF429043A5F6D7634ULL, 0xF75924E6DC2184B5ULL, 0x6922F75CFD64AB6CULL, 0xD5E375E263DFDD0FULL, 
            0x39EC097CD5A6CDB4ULL, 0x410B42E4E8FAF846ULL, 0x1AA72552C2B8AB05ULL, 0x7E9C4E199C53F301ULL, 
            0x550E071E2BF023BAULL, 0x3674797BC464E7BAULL, 0x1CEC29546D636B63ULL, 0x45606C35C85E302CULL, 
            0x9AB38BC712637459ULL, 0x01936E790BECFFD3ULL, 0x0C51EB9B4C7986ADULL, 0x2CD253CDC82397C0ULL, 
            0x419939738991D3DBULL, 0x1745E5F6F0944F84ULL, 0xDD8B6949F153E230ULL, 0x1D6EDD1EED3B0261ULL, 
            0xEBE99890AD9A0F6DULL, 0x14F238A8106C2424ULL, 0x2B0D634F77BBFDEEULL, 0x585A2A45318738AAULL, 
            0xF2CA989F3DECE44BULL, 0x2EA331ECF9FC2CBAULL, 0x9E928B1EEE0A487AULL, 0x5E047E16985F3848ULL, 
            0xE2769F6CF91624DAULL, 0xE2651712B1BC0240ULL, 0xBE65C91D1036DDF0ULL, 0xAA54502B9E69A8ACULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mimosa::kPhaseAConstants = {
    0xD52AA99E5C98C3B9ULL,
    0x355FB8F2E93C0FCFULL,
    0x52D85B1C17584979ULL,
    0xD52AA99E5C98C3B9ULL,
    0x355FB8F2E93C0FCFULL,
    0x52D85B1C17584979ULL,
    0x3A1D8CF9F48F5184ULL,
    0xA74D052FE02F68E0ULL,
    0x6F,
    0x18,
    0x74,
    0x9F,
    0x42,
    0xF7,
    0xFB,
    0xB2
};

const TwistDomainSaltSet TwistExpander_Mimosa::kPhaseBSalts = {
    {
        {
            0x20BBE13369E8100EULL, 0x8341225452E44D3CULL, 0x1B061DEA637D0BD7ULL, 0xBA6B272AD249927FULL, 
            0x96F08A606832FF20ULL, 0x11931183B9072EB5ULL, 0x491E154097C062E5ULL, 0x97581CD0F29A8E95ULL, 
            0x2C0560D02FEA424EULL, 0xA00CA1A652AD6294ULL, 0x2864CFB3499AC68BULL, 0xA9EABF77FA25B92DULL, 
            0x3BFD93FEA74A4C5AULL, 0x172FEB8E151CED58ULL, 0xDD6CBA8BBD9613C6ULL, 0x58936AD8875D563CULL, 
            0x15E8CAB6BD3E676FULL, 0xD50E507D1416F374ULL, 0x757CC17E74C8559FULL, 0xB04FF410EB25B64DULL, 
            0x7CC6B3028D8070D8ULL, 0x21996C0986ECCBC3ULL, 0xD7CFA7C0AEB8F27AULL, 0x54B0C1A2AE0F7134ULL, 
            0x800984C3C1E41CBCULL, 0x78124B96EA232B94ULL, 0x47D60B1DFB57AC56ULL, 0x1EAFE4B7BDB2E90CULL, 
            0xAF7FFF302F18A710ULL, 0xE58B8A42722FF0E2ULL, 0x47707613678101C1ULL, 0x2B96E4A90A15423DULL
        },
        {
            0x794E8568B4D57D73ULL, 0xA32B13CD231E49BEULL, 0xB8AA51DB22B2EEE3ULL, 0x5F7E116B5E650E54ULL, 
            0xFD4E71DAF810426EULL, 0x99D2FA5E929B1DD5ULL, 0xE00A7B795178A8B7ULL, 0x2A8B3AD9E3AE76DFULL, 
            0xE3EC5F189D5AD9EAULL, 0xB96D6A1C34E2406EULL, 0x5273E3EA84EE1AFBULL, 0x26404E0FE3522C8CULL, 
            0x93A5BA3852BC74A0ULL, 0x5C6B3E4B090E6B16ULL, 0x6A2400B45119C06BULL, 0x2668CAF71001C1D0ULL, 
            0xE944548261937EFAULL, 0xA57EB37CD76AA9A3ULL, 0x5DD6D4D18221BBF9ULL, 0x10AE5D849CE4EA92ULL, 
            0xDF6DD748DDA070C0ULL, 0x3C128F8760F74FCEULL, 0x2D1CDFD84E3D70FCULL, 0xBF5438153071DA54ULL, 
            0x4199F0B12051B44AULL, 0xE228254E9C597C93ULL, 0x1B723C815AF0B1E8ULL, 0x66026C62F17BCBB0ULL, 
            0x215359B3A8A588B5ULL, 0x02EAB336773910ECULL, 0xE0D0202B553D5570ULL, 0x14684A16B0A00A48ULL
        },
        {
            0x1E876E337F13860BULL, 0x385BA58A30DADB7FULL, 0x72BEC97F8F20D651ULL, 0x6FCD89D4DAEFB88EULL, 
            0xDA45F7DC53310C4FULL, 0x01ADEB8A6C2F3291ULL, 0x842B7F8A4F1A2A39ULL, 0xACD5FEA5237CBDE3ULL, 
            0x0778F4F9A1966EC9ULL, 0xFD591D31AE583985ULL, 0xF6F6936ECF32792BULL, 0x5C2EC49C35487F2FULL, 
            0xFE73B70D589CD8F1ULL, 0x7616DA1C018A31C2ULL, 0x6034BEE1FCBBFC38ULL, 0xBF6DD92D49FB6F82ULL, 
            0xDFFD3E3BBD0D052BULL, 0xE9308F5CDA246170ULL, 0x15A36911A22B47DCULL, 0xA9792EE89F1F29E1ULL, 
            0x5819F7E99599F427ULL, 0x62E9C16552FB5C22ULL, 0x8B1614149BC44712ULL, 0x0CE1DE5A5F35FF7EULL, 
            0x5BD6A78EB22DDC3FULL, 0x2C396BCAA0E6ACDEULL, 0x3900FCF8CB25E38FULL, 0x97ABBAD2CC12A5F3ULL, 
            0xD5650855DC585CBEULL, 0x6D0F4F41B7698BA9ULL, 0x7857621C16DFB05DULL, 0xFBB25E2870263630ULL
        },
        {
            0x55864F5B74F23110ULL, 0x5C8FD69F073BA5A9ULL, 0xD000394B9E0FC6BAULL, 0xB5FB013314298007ULL, 
            0xFC68FB2477C94396ULL, 0x852415980E6C06E1ULL, 0xB675F92B06CE19E6ULL, 0xC3D0A4BAF567935BULL, 
            0x1CF6BA61FC8F10D0ULL, 0x99A0182ECBCF7E02ULL, 0xA05786CE3A0795E2ULL, 0xC20AEA2F72F267BFULL, 
            0x690C4520BA15B8EEULL, 0x9F238D69FB445496ULL, 0xB431C5ADE55BAAE0ULL, 0xAB0FB8D0410E6134ULL, 
            0x77C9B380ACE4019EULL, 0x11F1CBE1BA951B8EULL, 0x61C406DBEF6602D3ULL, 0xE0B8DF2139692539ULL, 
            0xEDFD21BDA472E9FCULL, 0xD5634140E0471183ULL, 0x050A47A77B9766A9ULL, 0x8A33D866930164B8ULL, 
            0xF7406544F803DE09ULL, 0x6769EF85A9899539ULL, 0xD03EB910A5D4B271ULL, 0xA1884AAD14E0433BULL, 
            0xA2D05124C5509A02ULL, 0xE6DA4DDD5FD6F9E5ULL, 0x043777B1AB081128ULL, 0xBF623A65164EF6CFULL
        },
        {
            0xDA3901996EB80C80ULL, 0xEDC60593041C9C47ULL, 0x35FC69F283EAA01DULL, 0x9E1560C2DF5FD854ULL, 
            0xDB927B1A9D09DD87ULL, 0xAAD6AD053EDB1F71ULL, 0xB12598C68DC51167ULL, 0x29FAA9D0BF3B1D45ULL, 
            0xB1C88BA0D1B83C57ULL, 0x282B5BFBF5209FD3ULL, 0xE6AF040DB889B94AULL, 0xB75A21FFD6302EDEULL, 
            0xE9AC0BC981D739BCULL, 0x52BBE70BAD91BDC4ULL, 0x8E71E097451328C5ULL, 0xE1DC40073ACCFF57ULL, 
            0x0F9FB2628590D1DAULL, 0x2BAD6913EF9C48C8ULL, 0xF15917172AE6A2C9ULL, 0xC5B5F0DB891E44BFULL, 
            0x4FC0F188C2D6617EULL, 0x4F861AAFA14A8368ULL, 0xCECB932EDE9D776FULL, 0xB84E4148583D474FULL, 
            0xB2EA2A525E8EF721ULL, 0x6169E507A5813CC2ULL, 0xE60BF65B0F1984DBULL, 0x028D267FC97A9B11ULL, 
            0x2EE928B50D079333ULL, 0x4F40B2B572EA1215ULL, 0xA80D25B26C11B698ULL, 0xF55894695BD158D4ULL
        },
        {
            0x00307FF541A2372AULL, 0x337B690D587316DEULL, 0x63A80D7E375E5BC9ULL, 0x55826EB73202BE16ULL, 
            0xCCDD82646C78B7F8ULL, 0x329107417D6FB1F8ULL, 0xF952941014F73561ULL, 0x5D4930A9B3E36487ULL, 
            0x8B6FA79986541D89ULL, 0x498D59BB6F702E24ULL, 0x33D0E6BEAE43E406ULL, 0xB5DA1323D9DACBC8ULL, 
            0xE1F736A47982949DULL, 0x6F3BE0EF1628DE55ULL, 0xCC6CD3BF223C7B90ULL, 0x165809887A3BC71EULL, 
            0xE94AC396587B0FDBULL, 0x33C4F43E61FEDA47ULL, 0xE95F36FA6FE6647CULL, 0x784B2034A04E2C38ULL, 
            0xD2DA0BABB03DB6F3ULL, 0xBD84FB3C0419F323ULL, 0xF1E18FB7B968D01CULL, 0xEC4E2D8B0D199E2EULL, 
            0x8186E1339BDB9C4BULL, 0x364C9EF83B9155D7ULL, 0x64E6DC6874F19503ULL, 0x996A5A129BB0C61AULL, 
            0xB1DA03B52BB70E1BULL, 0x84D6440F9057F6AFULL, 0x717533B21151873AULL, 0x049EB8091D53101FULL
        }
    },
    {
        {
            0x4607806DBFC95628ULL, 0x638140B70CF065B6ULL, 0xC94F2EEBB193519CULL, 0xE2F9E13122CA7829ULL, 
            0x4EFD66C59FE8F254ULL, 0xC76F1FB2B0FA88DCULL, 0x07C00677EB649345ULL, 0x11E24973AC9980F9ULL, 
            0x72595804A6C8918EULL, 0xA17563975625D051ULL, 0x555D1CF508385631ULL, 0x0E5873A5089BC4E5ULL, 
            0x371F7530D9AC1078ULL, 0xFB06D16AF8B53E18ULL, 0xF556E386A91EBD56ULL, 0xFAD308A15C1F92A8ULL, 
            0xC552B07D5A3A9B62ULL, 0xD5231052A3F56E6DULL, 0x940ECD83872F3AB3ULL, 0x9FF9B26FDA4CE3B7ULL, 
            0x54523D526E501AF5ULL, 0x590710FC3438FCB5ULL, 0x4E45777B24A1F9F0ULL, 0xA31C719D825FCF79ULL, 
            0x8F6045A725795EBFULL, 0x58DCD438D5C4BC85ULL, 0xCDE5823BFB129B63ULL, 0xDA9D0DA30DD10F66ULL, 
            0x3F876871622880D7ULL, 0x0518CB262733961BULL, 0x41C67BAF2D5AB304ULL, 0x5906A0A6993CD427ULL
        },
        {
            0x62308F0483C0AEC0ULL, 0x2A470A91D4FC01CAULL, 0x49F222177664B190ULL, 0x7D09972662B246D0ULL, 
            0xD9D375E7C3A10C5AULL, 0xFA7BCCDB9D9CC3B4ULL, 0xE68BCA272919B5ABULL, 0x3BF596FEC315B964ULL, 
            0x17905072789C48EEULL, 0xCA18DDEFB836489EULL, 0x20C115FFBBA0A930ULL, 0x352C74F7857740F9ULL, 
            0x8C3A0231D393E6C5ULL, 0x80E21D22D57D026FULL, 0xE428B45C0A44B2FCULL, 0x243CDAAB9EC84050ULL, 
            0xA59E14ABC4A54141ULL, 0x79B0103032E3B0ABULL, 0x4B2AF5E1AA25EA70ULL, 0xAB5E9BA1BF4C02B0ULL, 
            0x8F51722F984C5CCFULL, 0xC5F072D4ACB529AEULL, 0x1B4FC817AD352BD8ULL, 0xAA52D96E19CF2355ULL, 
            0x05D6E9312371EE3FULL, 0xEEBD28D9139EC9EFULL, 0x4C5304E538346F2EULL, 0x8974315D0DE24533ULL, 
            0x85FE4E01FE04952EULL, 0xA632E3E6C247C2F0ULL, 0xC321D3C0E41C432DULL, 0x4DB191EE56E4A750ULL
        },
        {
            0x5DFAF09B4EE63C4EULL, 0xF3B9DCB439DFFE7BULL, 0x45E0B522EC041D65ULL, 0x4FC33A0248B42F92ULL, 
            0xCFB786C49C6E1A40ULL, 0xE53EEF7D8FC37F35ULL, 0xF526DF897770845CULL, 0xF12318F6DBC32254ULL, 
            0x75ABED4827DBC430ULL, 0x7303865B82243BDFULL, 0x9D2D800B756E7C0CULL, 0xC54F484F75BBDB96ULL, 
            0xEF1445C94B04F0EFULL, 0x1D3D3E76635F58D4ULL, 0xE6D6BF46D5804864ULL, 0x38A5DFC08FBBD711ULL, 
            0xAB184D0EA3D89BB9ULL, 0x877167EBB3DB20A6ULL, 0x54E25FED21F8FD6FULL, 0xB98DB27F41D91391ULL, 
            0x9EF330403A7D61C8ULL, 0x6A05B4EA0F153F02ULL, 0x45B06AF3724A50C0ULL, 0xE74AD626EC7D818FULL, 
            0xEB0E167B8FFC07FBULL, 0xBF1231E994F9B2F9ULL, 0xC8E0591CAF599B6DULL, 0x138F12018EB4A5F0ULL, 
            0x0045CBEDE075C280ULL, 0xA232FB7A50575581ULL, 0xFD1F06EF981844E0ULL, 0xC5550EBD830A7A20ULL
        },
        {
            0x9C3FB75255FB2E4EULL, 0x12152ADD18C07519ULL, 0x664C3527109D8C7FULL, 0xE3C215A807E749C4ULL, 
            0x547E98C8F054732DULL, 0xD86C0754A7A46A75ULL, 0xAA80F6F017D9EC3AULL, 0x9BFF332411C4F9D7ULL, 
            0xA3022E22170368B5ULL, 0xD1CBD99229099D23ULL, 0xC588D8F3D9F585E5ULL, 0x725DD9C74FCA201EULL, 
            0x0EE14A1DDAC14BD5ULL, 0x3782708DD6970476ULL, 0x80AF5C91F388EB5EULL, 0x3007E257A828EC5AULL, 
            0x4E793C0D0811F9E3ULL, 0xEAE908A347B5A002ULL, 0xFC03D83FD6D330D9ULL, 0x80BB6C930ED5F50BULL, 
            0x84F47D0C0678C93DULL, 0x9E2AAE963EA5C842ULL, 0xEBF5AF43FA323C34ULL, 0x9016D5415E9F7C77ULL, 
            0x6B50E9276E63CF9EULL, 0x0D02CE1C79887507ULL, 0x5FF4DC65C4191116ULL, 0x27BF0886B1B9E9BCULL, 
            0x655810A74947E9A1ULL, 0x8DFFC1F5F8773EAFULL, 0xF14BCEEF9F40BB62ULL, 0x4F6D7623D10A372CULL
        },
        {
            0x14AC074C130138DFULL, 0x77A0E8EFF72BC2CEULL, 0xDC75B8AA8A15B36EULL, 0x04E4162C74437E74ULL, 
            0x682E3A17529217C1ULL, 0xF1DEE00766F8DE21ULL, 0x91ACAFEEC0965BBEULL, 0xB54F752ED60AB9B8ULL, 
            0x3B12A37D49BAC169ULL, 0x37D775B4380C1D1FULL, 0x8EED8783D21CB6A8ULL, 0xF2CD70B03AAC8F2DULL, 
            0xD44F46B1BB43F4BEULL, 0xF396E3D5D8C4953BULL, 0xCC679064C38F61F5ULL, 0x3FC43ACDE8756374ULL, 
            0xDB3AD3B2FB950094ULL, 0x58A8439DC69CB8AFULL, 0xD4F5C1B7F263CB7DULL, 0x72A0363ABB04EC85ULL, 
            0x53011A08F5DB7E3DULL, 0x4F61749A5013AB77ULL, 0x0FE53E541AFA8547ULL, 0x565445CF64F3F464ULL, 
            0xFA66D6A567D480FCULL, 0xDD5EBB4AEB1CF61BULL, 0x2B0FE6963AD7E605ULL, 0x05B30B5A365159D2ULL, 
            0xAE6AC8AA2CF5117EULL, 0x05B261D87D354392ULL, 0xA92E9B1A7A49CA34ULL, 0xBC9BB533957C679EULL
        },
        {
            0xA808D5126A81A14AULL, 0x912B5925884836E0ULL, 0x815F5F6E2D0B6EEBULL, 0x1DC380C542932F64ULL, 
            0x403DB9117120EE89ULL, 0x8D330D70AF97835EULL, 0xDED152EC681D9356ULL, 0x47C0C6540E7EAC2CULL, 
            0x717763A474D5F474ULL, 0xF45C11B5E0C42C6CULL, 0x895276DE652ABCE4ULL, 0xF912A6E238401584ULL, 
            0x5FCDC081A57DDA03ULL, 0x1D96D48995582003ULL, 0xC46192323B37920FULL, 0x3DA0A6B83A174A64ULL, 
            0xCDCF9280C5594F51ULL, 0xFBED3AE1C8A46235ULL, 0x3C417F414EF2BFD1ULL, 0x0897D99BAE8105B6ULL, 
            0xF00596D1A6858722ULL, 0x38A595AD81A556C3ULL, 0xACBDB892BB725278ULL, 0x68DDC41F1C79DB77ULL, 
            0xBD977C987ABD5EA2ULL, 0xC4EAA0285E02FDD4ULL, 0xAFC37D52137E0252ULL, 0x6C01114B62D91219ULL, 
            0x47832C274EBEA673ULL, 0x5B17A2771072CCAEULL, 0xCEF57944CBA3C3D1ULL, 0xC2617158B76105B9ULL
        }
    },
    {
        {
            0xF87650C4B7B79854ULL, 0x4D566BA3235DD4A8ULL, 0x104A52BE39C02247ULL, 0x89A4C18B36F09B1FULL, 
            0x23FC850FCD30BF7FULL, 0x50260182EA496EE7ULL, 0x516E270340CF6843ULL, 0xE340B30F1038FDCCULL, 
            0xEBF68BD7C19773F6ULL, 0x4DB948E90FC35215ULL, 0xED090CD094C92B3DULL, 0x3874E7F922C9F8D4ULL, 
            0xE03A76CF21425115ULL, 0x56F959F44965AF10ULL, 0x275226A4511C73BFULL, 0x20735DD4E2F1038FULL, 
            0xA0FE1F44C4C7C8D1ULL, 0x4264484904B08626ULL, 0xC90C8671A2E5ACFFULL, 0xDDA4F609CAAFE235ULL, 
            0xD74B1213A50F9742ULL, 0x180ACD7C2750D0C8ULL, 0x2ADC23F8A1D388F6ULL, 0xEAB440D89F2D2B0BULL, 
            0x7E7276810469FF4AULL, 0x1E5EC12C5E331D62ULL, 0x1E3A7123B2345B40ULL, 0xAADD549870E8B0EDULL, 
            0x4772D7736D5985A2ULL, 0x1E3ED6EB53338783ULL, 0xA2BCC775087A37E2ULL, 0xC2D51367E30567F1ULL
        },
        {
            0xB0EC6984ECBE9F50ULL, 0xB5DA6AFF9CEF14E1ULL, 0xA6434C67BA59D3EBULL, 0xB3C2E126A0BE5ED9ULL, 
            0x77ABD2F5DE1EF7DBULL, 0x0900D35B9D0F2FA0ULL, 0xD0765B934EA36E19ULL, 0x076947127E281F3BULL, 
            0x4468ADA0BA0253A3ULL, 0x827B94FC1D7B590BULL, 0xEC9553CE0E02847DULL, 0xA2BF937B268EE8B9ULL, 
            0x03C32C2176C6425FULL, 0xFCF986AE86CA53F0ULL, 0x1B8C12EA0E5503FCULL, 0x7B0582C55C27556EULL, 
            0x0F584EB4F9112808ULL, 0x398C6617EFAA44A0ULL, 0x791ADFA10D2929E7ULL, 0x06C85BA6E327B340ULL, 
            0x4C5A599B25B644D1ULL, 0xE94B3296F596512EULL, 0x159CEA14494B2628ULL, 0xED9E49A00A5A0F18ULL, 
            0x919837AF36E9D3E1ULL, 0x35F14EB7452EA4C6ULL, 0x9033C4776A0A35E8ULL, 0x86BC82AD7D33A05DULL, 
            0x5F8D604B5BD46673ULL, 0x22A253350D0DEC0CULL, 0xFC1BD031092350C4ULL, 0x2BEE1305D2CC56F1ULL
        },
        {
            0x966E5173922F8BBBULL, 0x8A8A3630E5FA5432ULL, 0xAE647E09D02DE71FULL, 0xF2B8A228CDD27795ULL, 
            0x099B16D5071B51F0ULL, 0xF5B701259A785C84ULL, 0xBAB95EF27ED5E337ULL, 0x09B3E6E8213C3F7CULL, 
            0x632AACECF7060810ULL, 0x4082E41C1235F4F4ULL, 0x6E9A8F78FE9A8E96ULL, 0x7A79ACFB56F1D37DULL, 
            0x22E40A2AC2464DB5ULL, 0xB68BEFEF11535E81ULL, 0x55F04D229FB238A6ULL, 0x279EEA21E164A5F2ULL, 
            0x3DA6A6A0F6B2302CULL, 0x6FF654591E250DD2ULL, 0x06A5D81C6181B6ECULL, 0x74E5820A9986DD19ULL, 
            0x65836B06D5C1F5F4ULL, 0xF66F05489A131CEAULL, 0x6AAC6B19A311002AULL, 0x2F7882427E9CB071ULL, 
            0x708E0D05EF42F15FULL, 0x8D0644474C18061FULL, 0x5939520695612319ULL, 0xC4F5F2DE1B6A7EA8ULL, 
            0x0D3581AA0D85DFA4ULL, 0xABC64BE3BCD51F04ULL, 0x87D84139F872A07EULL, 0x0EB2B12476F25FD2ULL
        },
        {
            0x58E08BABA06E1DEBULL, 0xB0D46BA6BD14E9D2ULL, 0x0D7805B35B05C6C4ULL, 0xCE7AD90920209323ULL, 
            0xAD67CCA5052D1A92ULL, 0x0F129DDFAA4C0EEEULL, 0x9418803B19905A14ULL, 0xFB934A9315DC24EEULL, 
            0xCD35E1F3955FEACCULL, 0xEDD81AADA5A26E0BULL, 0x26CD7B3534E88772ULL, 0x561BBB3E34C6A57AULL, 
            0xD69364F84FD02FACULL, 0x0247138795CAF5B1ULL, 0xA0C88DACA0053E28ULL, 0x2FEA6CE0E7E6DA46ULL, 
            0x87E831B675BD47C9ULL, 0xC941A40F2618F1B5ULL, 0x36AF7C55EA6ABB12ULL, 0x6EEA43145E7B9137ULL, 
            0x0A7254D7BA53E8D9ULL, 0x913E29F8027A3984ULL, 0xDCDB287A0DA6108FULL, 0xBBBBA18318DCFD5DULL, 
            0x0EC8D74FF7FB19A1ULL, 0x522F113795FC8D7BULL, 0xCE50A11386534A80ULL, 0xCCA458B4E0BDEDA9ULL, 
            0xED85C0493BEF1F36ULL, 0x54E00B7A25B0D8ADULL, 0x7518F089F2A38F7BULL, 0x741E0E5AE4D1BD45ULL
        },
        {
            0xDC176ECD734A06FCULL, 0x9C88631308FCFFC5ULL, 0x323549259B66B28FULL, 0xF91138EA1AAA02AAULL, 
            0x1945C2701216D227ULL, 0xDE7DF06B1DB2711FULL, 0x5947D410E3D79B5DULL, 0x2071620B04F6BF99ULL, 
            0x16C390B07BDE461FULL, 0xAE912B2891F9FD23ULL, 0xEC0D88C9CFA6A61FULL, 0x2AC5358A54F8F430ULL, 
            0xE152F87C9CCE8FF2ULL, 0x493F290252C148BDULL, 0x73E0C3647D506420ULL, 0xDB1EED74D231DB17ULL, 
            0xD42691340BAAECA8ULL, 0x86F146D11178B06EULL, 0x41C66C09989A7DF0ULL, 0xEDE7837D9A4F173EULL, 
            0xA68AEB83DB5D172EULL, 0x386EEF296B9CAB30ULL, 0x2789B5A5AA007E91ULL, 0x3934827DECB16B6EULL, 
            0x0C2F075B7F96C4CAULL, 0x983A73EF943489C3ULL, 0x10C2BAC508B4402DULL, 0x899D4BE6B6AD71A9ULL, 
            0xDACB5F55C7751EFAULL, 0x992E45D0950F7512ULL, 0x7E0E5F38B989BA3EULL, 0x72BD60ADB079EE3AULL
        },
        {
            0xA881B3DF9F7F498FULL, 0x35D3FBAB6B01ADDBULL, 0x64725885EC2D374EULL, 0xC49851F0E9E23AC7ULL, 
            0x34ED4F3CAAB6A6F4ULL, 0x7CC05CFC22E20EEBULL, 0xA2C0BF40E1ACDB27ULL, 0x5F57BFBEF31B6CDAULL, 
            0x36408091DDD0CC9EULL, 0xA4684C2B5F520B66ULL, 0xFAE5E19FF5CC49AAULL, 0x49C013CD2F63DC5EULL, 
            0xE3297344DE15A7A4ULL, 0xFB24BC034DC9B3BBULL, 0x22C4D97A73E3E49FULL, 0x2591162081556750ULL, 
            0x0F538DEAC2CD9A91ULL, 0xE4562F29A09F605CULL, 0x76EB41427D234B66ULL, 0xF277E8EC974DE032ULL, 
            0x07F6685E41044531ULL, 0x66629837685045B6ULL, 0x3EE60B294BF775FEULL, 0x459E6909D6D288F5ULL, 
            0x608C1C712A06DC52ULL, 0x3145DF1BB5F2D376ULL, 0xD6501DD666BCF35DULL, 0xA4A50269BA2AD65EULL, 
            0x69EF847BFE85950DULL, 0x56E3947BF2C69B65ULL, 0xE3395472FFBE02BDULL, 0x9D9E7397CBB6BFCAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mimosa::kPhaseBConstants = {
    0x373F0EC1FE15F5ECULL,
    0x04DFD6798F1BA4C7ULL,
    0xF8C86A4918B36CB8ULL,
    0x373F0EC1FE15F5ECULL,
    0x04DFD6798F1BA4C7ULL,
    0xF8C86A4918B36CB8ULL,
    0xBB629243D8EC386CULL,
    0x8D901FD142256991ULL,
    0x1F,
    0x82,
    0x65,
    0x33,
    0x5A,
    0xF3,
    0xC8,
    0xB4
};

const TwistDomainSaltSet TwistExpander_Mimosa::kPhaseCSalts = {
    {
        {
            0x75E3C9D53408721FULL, 0xC262ABD19C9ED7B8ULL, 0xFFEB2511983C8D8BULL, 0x917D5DE8BBDEF5FAULL, 
            0x88800AF0F079CEFDULL, 0x57CDF918755F38D3ULL, 0xE93A3BC2320D3703ULL, 0x826AE62E6A654364ULL, 
            0xF50693F480004EAFULL, 0xEC254997A7623733ULL, 0x669526D8A14C2AEAULL, 0x51DF8C3F46C167B7ULL, 
            0xBC345AB42C4CB0B2ULL, 0x1C14B7F55A8C2486ULL, 0xB9C0A487FC55B0D5ULL, 0x7799395776A47984ULL, 
            0xD438C7FA3A7FD39EULL, 0xD4042588A85CC5A0ULL, 0xB4CED0BA312E2D9AULL, 0x3CC58B86959E0470ULL, 
            0x339B98DC2D48FBF7ULL, 0x82ED50629C74D38BULL, 0x547AD7A4A6676B0EULL, 0x37C31D436B66E6E5ULL, 
            0xB0413ABB7AD4BBD9ULL, 0xA886D13E2AECC427ULL, 0xBE1DDA56149E330CULL, 0xE4577439A583BAF3ULL, 
            0x135CF3F5B543F17BULL, 0x2B5F88187AF43AA2ULL, 0x1AB17D10DE787285ULL, 0x61F0362833B84023ULL
        },
        {
            0xB2F2A7CA14636B53ULL, 0x3800685F3F74BBF1ULL, 0x329FAFEA33E3B18EULL, 0x8B1ED98B32A807DAULL, 
            0x20FA2123EBCFBBF7ULL, 0x7909B60310B008C3ULL, 0x33C455B854D729C8ULL, 0x5A591F20C05EF062ULL, 
            0x8239E35227B04EAFULL, 0xC7C1A86B8DA4B0BFULL, 0x320222CD7E6993CEULL, 0x866FAC2954E90288ULL, 
            0xFFE833E0AD13119DULL, 0xDAEDE73BC40A2E6EULL, 0x324BE9658EF8A84DULL, 0x44DFC0B83259F09AULL, 
            0x03A65BBA7388DFC0ULL, 0xC1C07161E647ED90ULL, 0xF49B63D9079C94DEULL, 0xC87A44F8052D26CBULL, 
            0xE75C3FA5DDCF097DULL, 0xF145B59D1B72B117ULL, 0xCA6B69A8F30B367AULL, 0x3F3B5B96D2C45C25ULL, 
            0x82C38B0131AF9DB4ULL, 0xD8818461568419C4ULL, 0xA99D937AFE96BE29ULL, 0xD9A16383C277ABC4ULL, 
            0x8C443434A3B22B12ULL, 0xAF0DC8730831476BULL, 0xAB652F2227064A4AULL, 0xAE49CE0E6AEA752EULL
        },
        {
            0x5396EEB4BEC9BDB4ULL, 0xD3CE80BB0895888CULL, 0x57632F4CEEF22F98ULL, 0x0D65A899084EE89BULL, 
            0x37D57926E867178AULL, 0x6034A829B658CA4DULL, 0xF515C01312BBEF24ULL, 0x2BF22EDFB2930582ULL, 
            0xA056708CA09871F2ULL, 0xD55F7BDC0B232456ULL, 0x229FD769F4E341A2ULL, 0x59F165444E453AF1ULL, 
            0x1AD64DC4454E0E72ULL, 0x67E2E0B24132C3B6ULL, 0x57980D9B8D897C3FULL, 0xBB5D2C2D9FD75DBBULL, 
            0xEBE15C963E500344ULL, 0xFA1617BBD3132414ULL, 0xE2DFC41886C433D7ULL, 0x64F3451C4B6C9A8CULL, 
            0xC387362970C5642EULL, 0x46DDAC3E086A85F0ULL, 0xE5C19658A66501FEULL, 0x2B179E2F7DAD5EF9ULL, 
            0xC46F2E9A97DAE21FULL, 0xDD227445AF39B108ULL, 0x5CF8194C4B23C503ULL, 0xB848FF35B74085DDULL, 
            0xCBF21835EA8662A1ULL, 0x331772D68236FEF3ULL, 0x02AD8C05A599EC78ULL, 0x984EF1521C5A5C28ULL
        },
        {
            0xEB5560F1DB0880E7ULL, 0xED5F40BF7232AF45ULL, 0xE32C325D20B8E530ULL, 0x2807A8484ECCBEBEULL, 
            0x4F4B14A643B9C18CULL, 0xDF911966A19D1D8CULL, 0x78473710A7DA150FULL, 0x9F25A0AC82D43E70ULL, 
            0x24AC4632879C4BBFULL, 0x220AC97254A08894ULL, 0xCB014E5762020E64ULL, 0x8B485F27A4E31A13ULL, 
            0xED774A82BCE9DFEBULL, 0x296F2A93C9783BE6ULL, 0xB589A165F3B7871AULL, 0x8FF1D3B2C4CA227BULL, 
            0x979E9200F8780D8EULL, 0x6112A56D78BC9C7BULL, 0x79B5F1969A9DE843ULL, 0xF0A88B90DB566DD6ULL, 
            0x4132BD69B2E70E4BULL, 0xAE8339E4F196E5D5ULL, 0x69C8460B05F1A1B7ULL, 0x4B300CE526F7A376ULL, 
            0x614E7232EBC4179AULL, 0xC3D29FDF6929DCEFULL, 0x4604218693194C24ULL, 0xFC483B9E3EC821D6ULL, 
            0x2F404604FA6F8913ULL, 0x7F2ADCE2BBCE4FB4ULL, 0x291D500FE7CD48A3ULL, 0xDB7064F1F6A20FD7ULL
        },
        {
            0xB1D0E9480F021D18ULL, 0xADCE9ED3233FDEFEULL, 0x511E48783B957857ULL, 0x63CBB7A5B768A45FULL, 
            0x1F95CE0D9029D870ULL, 0x048956EE55808AAAULL, 0xE15B63C033B66CE2ULL, 0x7A4064AB22FBCE20ULL, 
            0x9ED4CF1E5D6E0488ULL, 0x38C05A51A466F365ULL, 0x1F1870E35E047918ULL, 0xEE74C9BF0B2BB946ULL, 
            0xFAFA0D02586940C4ULL, 0x579AAF31BF019EC1ULL, 0x808BAC4BC5BCADD5ULL, 0xB30B24B652FA52A3ULL, 
            0xF1947935DECB9D1FULL, 0xC27F3E764442000BULL, 0x3499B417F98CA67FULL, 0x2A4BD58ECAC86E54ULL, 
            0x65B1E4DA3EA26217ULL, 0xFEC829821E1E7971ULL, 0xB8D91E64178F7213ULL, 0xCE64EA71BB81E3A1ULL, 
            0x54068F619851AA80ULL, 0xD78CA3AECFA9D977ULL, 0x648FC22513A6FA64ULL, 0xB6022056CB105612ULL, 
            0x929E442EF2656657ULL, 0x1F661ECA8BFB41BCULL, 0x7DC3077B058AD0F5ULL, 0x37520223BD174427ULL
        },
        {
            0x4F307D5E4F8257C0ULL, 0xEDAD9286914BF12AULL, 0x2836A332C2BD20C8ULL, 0xE6206F559E32F5ECULL, 
            0xD64F1DB6A4818398ULL, 0xF1B72D7610EBF796ULL, 0x5ABD5CC55FDFB62FULL, 0x42C42D61345ADA90ULL, 
            0xA4885ACA61AB280DULL, 0xE0C5D2BB0BD3894AULL, 0x1C8E6B33A768DAF5ULL, 0x85CA565B5715D7BAULL, 
            0xC0A9DAE76922090DULL, 0x689528EE1F62313EULL, 0xE3A4EED53A1BA495ULL, 0x3634EA64E25E3CC2ULL, 
            0xCB8BDC5BA2EF82C1ULL, 0x67AC8D87446F41CBULL, 0x79B0DC3DDE199507ULL, 0x6B5B6631FC8C6AE8ULL, 
            0x378AFB043DC6C3EDULL, 0x81093DF8F0E1F523ULL, 0x5D541130EEF98BB6ULL, 0x0F4959E9F4AE17ABULL, 
            0x930E7518B3D3E144ULL, 0xF82692D4294C6D7AULL, 0x7268C24E85AD5C48ULL, 0x7EA344DDBAB247B4ULL, 
            0x3597A8AC794918ADULL, 0x4C112762C40789AAULL, 0x161E921F42C25230ULL, 0xC9D224923E149BDDULL
        }
    },
    {
        {
            0x7D3B79E56FDA3EEBULL, 0x9EC2482FDBD78E34ULL, 0xA22D4C5BD0B83EDBULL, 0x8646B2691203F91BULL, 
            0xA96456D0D6E7D243ULL, 0x8A8839D39D0C2B6EULL, 0xA58B0A05224C864AULL, 0x8B70F43151949FEBULL, 
            0x39CF39DBD6161E8FULL, 0xF86A45D9048F38DAULL, 0x88BD7FC8A9285C4CULL, 0x0283C455E62A8E09ULL, 
            0xBC14557237C620B8ULL, 0x92EB5B36E5DC4AD8ULL, 0xF8B118EE3382A5C4ULL, 0x58E0AFD0A5FED8E7ULL, 
            0x89DFDA359998E4E1ULL, 0x677AB94D0082F36FULL, 0x36CDE8411729AA2CULL, 0x5E17CF89C827A1D5ULL, 
            0x821447E7F9CAC870ULL, 0xAD84999DC0A62891ULL, 0xD86996A773DF14F1ULL, 0xD809F9691D0BD0FEULL, 
            0xB4AC048151EAF756ULL, 0xDE783F4F6A7C9AD7ULL, 0x64CC390A7D17E1BDULL, 0xF308C4C52E264E60ULL, 
            0xB05EC207DA4A8E3FULL, 0x46CE2FFF9CFD4D77ULL, 0xCD09EAA594DD1E8DULL, 0x7CF7B2750B802AD3ULL
        },
        {
            0x3BCA53CB76772485ULL, 0x82F0248A13BB4786ULL, 0xE2A00F2AFC6BF5A7ULL, 0x69BF2EBB0141F2F7ULL, 
            0xB032DB3F09E4B50EULL, 0x09486F985867A720ULL, 0xF33389ED47E62603ULL, 0xB14C0E4EF03F4147ULL, 
            0x2F0E72F74B1792BAULL, 0x10795E5907C29A0EULL, 0x799608D7FFE35575ULL, 0xDCDB0B0803156DDCULL, 
            0x3A1D2E19ABDDBCA7ULL, 0x4AD37FD48D0E65C7ULL, 0xCEA3DEB3CC4597CDULL, 0xEA28F751479F25C4ULL, 
            0xE255F82AA7B01438ULL, 0x8E8448D2A41294D6ULL, 0xF15BBD0BAC2C19FDULL, 0x8D908744B61AB7BEULL, 
            0x5C21DFE9086DE15CULL, 0xF1BCF4F0A3711AE4ULL, 0xA0CA1818EE5146BFULL, 0x5809A7E9531E748FULL, 
            0xC70F7BEE000072E4ULL, 0xA6496E7D1E33EDBCULL, 0xE7A14AB14EDFA7AAULL, 0xD5669BBC0FADCA88ULL, 
            0x20D1A2A77E270D68ULL, 0x4AC30AC115E53DC2ULL, 0x96996CB9EC09D328ULL, 0x9AEC1088D3BEE2BEULL
        },
        {
            0x38A3BDF510A6EF23ULL, 0x4E335DFA1FFE32FAULL, 0x8BFCE84E8BD02136ULL, 0x03247C42423075CBULL, 
            0x8E3CF7A8D35B2E62ULL, 0xE32E431FBC103155ULL, 0x48D28D6D67356215ULL, 0x6F5D98C03AE30401ULL, 
            0x615028BB26CB3B61ULL, 0xE236507922FB217DULL, 0xAFD61E438B4258D5ULL, 0x40C66275E8491DACULL, 
            0xEED6DC54A8596A5BULL, 0xFFC1410503C40F2BULL, 0x11CB0F5830F19B7DULL, 0xE1FD97C73695385EULL, 
            0xBB1AE8D90621E1B4ULL, 0xBE92F7ADDA352F3EULL, 0x851D6B9CB51B2A60ULL, 0xE63B4FF6DEC1D3BDULL, 
            0x95331B428E7724D2ULL, 0xF160852F78A4E639ULL, 0x1AE87EBF0486F0C3ULL, 0xAE3BA3CD2A5476DAULL, 
            0xF19B2A1FF01ADBABULL, 0x5F684FA47ECEE11AULL, 0xC941D7C0B226365BULL, 0x77324BFDC76A5F30ULL, 
            0x13EB81E371475CDEULL, 0x79AAE1415309FC9AULL, 0x6D190B203E8FA52BULL, 0x51E7CD8D301B6D7EULL
        },
        {
            0x6A76A323D0D2447FULL, 0x09A05E843E93D058ULL, 0x3D18E2B83EEFDB68ULL, 0xBF12A247472855B1ULL, 
            0xEE829274217EFD9EULL, 0x1D1E72AB35974F3FULL, 0x6C2EE31030088979ULL, 0x1E74A4D51D07101BULL, 
            0xE812D8B346CC96CDULL, 0x152EEB014358B03DULL, 0x2FB7F9C8A7C47E4BULL, 0xDCE5D70114D721D6ULL, 
            0x052DD219CA4944D9ULL, 0x79E75664238D3082ULL, 0x2EDA507E4AC2B9E2ULL, 0x81DB7B2DE2E8E6C7ULL, 
            0xE8A47EACF0A0ED39ULL, 0x6CE4ED22A1B7679AULL, 0x4C52087F6796B4DBULL, 0x621AA285AB477A12ULL, 
            0x9AEF192DF5DF08E1ULL, 0xDEB3BF4036054243ULL, 0xB91A7CE588951D9FULL, 0x4BD16337F3EE3C25ULL, 
            0xA885392171FF7F86ULL, 0x3D118616DDB6A36EULL, 0x7E096F1ACF091FC9ULL, 0xECB9EB0E30A20DA2ULL, 
            0x1804956A69359940ULL, 0x3D60D29ABC9D8B31ULL, 0x91A810981D572E51ULL, 0x968913BD05882F7EULL
        },
        {
            0xC1F984BBFF1B9A16ULL, 0xC1FAE067BF661AAEULL, 0xFF70547A1513C57AULL, 0x9F2B2B8B3D1848E4ULL, 
            0xFAFB25D2EC805906ULL, 0x5C2BFB18387C375FULL, 0xEC7692038A18FAD4ULL, 0x08448E3B39D7C922ULL, 
            0x4FFE14C15289FD4AULL, 0xE5704728A3926B0DULL, 0xF3EE0BB15D6A18FFULL, 0x888B8545C0EA2B58ULL, 
            0x9D5C08F4CDD30309ULL, 0x78E875270958DE29ULL, 0xE6B3D45D0F44912AULL, 0x3CCC67945D72D0A4ULL, 
            0x64AD652A79510D51ULL, 0x63D1414535ECCE4FULL, 0xF73879D28FF8EEF0ULL, 0xB18E24D8C6D0FB70ULL, 
            0xDF7D15B2451ADCC6ULL, 0x1D2424EA63D8AEA0ULL, 0xAB87DDB030047058ULL, 0xF0AA8402F493887AULL, 
            0xB1572E3FF8A7461AULL, 0x3063A8DB62566422ULL, 0x61C61639AC1E9B5AULL, 0xF70BA56ADCCF9A00ULL, 
            0x214AC3FA1BC7DBDCULL, 0xD4841AE2922AD2CFULL, 0x2372BDED8F127E48ULL, 0x7E61F58559F6792EULL
        },
        {
            0x84A71859346C36D0ULL, 0xDEF6378D0739A531ULL, 0x7F1901D4F04ABE37ULL, 0xBD4E9EE39E3C749CULL, 
            0xECF2D48695704381ULL, 0x3F5A98FF2C02C73BULL, 0x36165FEEB7113922ULL, 0x7CF9A251D3D1547CULL, 
            0x36CA9F1FF3DA3E3AULL, 0x78D644E76EDD159BULL, 0x030763A2FE0F69BEULL, 0x127CFEA91AFB645EULL, 
            0x254221211CCDAA89ULL, 0xE083E30ECE121766ULL, 0x65B507E03266A9C3ULL, 0x809C8615FAD7F322ULL, 
            0xA664AA291DFE6A75ULL, 0x0FE352E9F35150BCULL, 0xA190403540D49F3EULL, 0xA41C663CE47E09E8ULL, 
            0x99C21C9BB1704BD1ULL, 0xB998A536E1A0702FULL, 0xF789576E393990CAULL, 0xE97142CFEA02E28CULL, 
            0xF702096B208E7448ULL, 0xC7415286B9BDD637ULL, 0xDB4D593FBA7B07C6ULL, 0xB52503B80F03BACEULL, 
            0xE9998F7499E81278ULL, 0x54DAE108FF127E18ULL, 0x6E92D81B66EA7F9CULL, 0x1A163910D02BB1CCULL
        }
    },
    {
        {
            0x60B33A1CB4A39A9DULL, 0x3F05D3FDD75D776AULL, 0x6DB114F99A1C7145ULL, 0x26C077A810A8E071ULL, 
            0x865D15F75A4A0B36ULL, 0xC32E6427542105EAULL, 0x9FF661A7FD531E9BULL, 0x4F9CFEE045568CBCULL, 
            0x9D136A1779088ACFULL, 0xE5734AE44074A393ULL, 0x174ED1157F38A595ULL, 0xAFC4E1C77C312F79ULL, 
            0xFC3481B5F5ED00F9ULL, 0x057AD9B32AE7587EULL, 0x0CA18280391D59B5ULL, 0xB491B37F9A6B9BBBULL, 
            0xE44E0673814057DAULL, 0x8329484F019FA860ULL, 0x95009F5D0EE0D5C1ULL, 0xA6713D94C17FF698ULL, 
            0xC2144AC1BD0AACA5ULL, 0x9177AD25786C9034ULL, 0x6F24B0A6F24D9F31ULL, 0xACA4EB4D9EB68608ULL, 
            0xD1A4C1FAA6AF5247ULL, 0x6DADC3B167B24007ULL, 0xCC64D4AA8600B296ULL, 0x37F1BD9BA0535AFFULL, 
            0x1B73F97EC65E9E83ULL, 0x938109E3876B3C5DULL, 0x5858CE3E02C0961DULL, 0x3A792D259FE073D1ULL
        },
        {
            0x8259BE3D5D613AE0ULL, 0xEC9A4FDD450CC68FULL, 0x293AE989B7D628CAULL, 0xEDCC85A6BC5522E3ULL, 
            0xCE5C8721400A6877ULL, 0x3E576ED73FCF6BE8ULL, 0x6FAD48B746CE9E1BULL, 0xCEEA848AF25DE10EULL, 
            0x5299836531DD8FEAULL, 0xDFEA5DA1165EFCB0ULL, 0xC8EE33BDE31F9CA9ULL, 0x8D1232C5B7A56525ULL, 
            0x32AAF452DBB5C09FULL, 0xE99E2F6648924B84ULL, 0x51C2238E4E056D3CULL, 0x61BA8B43BDDAB7DCULL, 
            0x6BC91537D46922EBULL, 0x6FA8936F1D4419A2ULL, 0xE61E6B88AACAC6E2ULL, 0xFB39AD1FDC129662ULL, 
            0x91AB5B835A278B13ULL, 0x1CF86EED2BA37942ULL, 0x96ED4A9F8481B629ULL, 0xAA4B89BB4D76E0ACULL, 
            0x46B13C1AB519A593ULL, 0x8CC4A4AD64B3A6E0ULL, 0x5EC01CA3C9A60FABULL, 0x1AA052D020772859ULL, 
            0x8D125CFD1CB81784ULL, 0x04728F15630D56F6ULL, 0x887CA68038EE5D2DULL, 0xB3D94D0992DB4BDBULL
        },
        {
            0x0B70F0AFBC7C3B7EULL, 0x038A48AB0A7E9DF4ULL, 0x7E41AA826EEA746CULL, 0xF7E3D00258A7A4CFULL, 
            0x926E2959DD342C04ULL, 0x55C209E37268A8F3ULL, 0x93E9AAF3649AF190ULL, 0x9C986849420E3CACULL, 
            0x8E9E18E4A1553020ULL, 0xF48D329529AB96F1ULL, 0x3012F59C9DF12D1EULL, 0xBA133A7DFD2A8092ULL, 
            0xF66BC7CB4E9AE876ULL, 0x2DEF7BD58F24B826ULL, 0x605CEA66903284C8ULL, 0x26ABA1477D52866FULL, 
            0x51124B2EFE330BAEULL, 0x2E78432B4D4978EFULL, 0x5ED252147DA7C617ULL, 0x2780E027B4060F8DULL, 
            0xB3B3DDBA306CAFD9ULL, 0x4660C3AFB096074EULL, 0x99E92CAF8550A0D2ULL, 0x7A1A216E431E74AEULL, 
            0xB26DF7F6A6747BF0ULL, 0x845AE368C4395EA7ULL, 0x3620DE1073D2E9C0ULL, 0xAEDAAF66913BE99EULL, 
            0x73C32B9621E32C1AULL, 0xF49D8BC38298C3FFULL, 0x867A6E66528126DCULL, 0xFFE904889F9EE1ADULL
        },
        {
            0xDB4AEE18F989A6C0ULL, 0xAC0D47BCD3366B82ULL, 0xA169354D7B337D57ULL, 0xE414C1DE9C06E7E6ULL, 
            0x083CDB1E2DD09E26ULL, 0x17727F8DD724531DULL, 0x8F35DDFB5E05B6C1ULL, 0xF5AE8BA1021547DBULL, 
            0xBB2CB2EC5EB15C7CULL, 0x228DD9C9A04663D6ULL, 0x63298DDACAB9BC75ULL, 0x38787039F0D8DDD0ULL, 
            0x7D867F5AF3DFFD3CULL, 0x14992840CB95E64FULL, 0x487DC18F96B6A6EFULL, 0x76C983237735BCD2ULL, 
            0x0B7C7E940EE66965ULL, 0x46FFC1D64E39757CULL, 0xB88C685B8CF2672EULL, 0x70AB62D787E363CFULL, 
            0xE5FF9F11DC04D068ULL, 0xE2E3372D2018DA5EULL, 0x2A71679D483EA742ULL, 0x94FD0C79BD674D94ULL, 
            0x2CE74BBFE87AAC32ULL, 0x9145777172D067D9ULL, 0xC838D2632C0BB5EFULL, 0x0FFE6B7A82B3153EULL, 
            0x7342203E70A12F4DULL, 0x965E018E58F44BEDULL, 0x55DD2C640F5D08B2ULL, 0xEE6F7B6E35DDFFA7ULL
        },
        {
            0x24CCDBD3E47556ABULL, 0xB3B058FE9907EE83ULL, 0xCC80058E0BAD6042ULL, 0xF2F84ADFDB6CDEF3ULL, 
            0x2192F1C20482C4C5ULL, 0x41D2D748681A1E76ULL, 0x87F60A4C31967D0EULL, 0x7B9B9150F900D00FULL, 
            0x6F44EDA1420EA01EULL, 0xC7C4250FA93E4281ULL, 0xA0A29E03E72B8049ULL, 0xC6CACD668F2E1B5EULL, 
            0xB6F08F589C91C5DDULL, 0xEF93C58EC695B5C1ULL, 0x882B552A6B358631ULL, 0xDBE5B2C70A224EF6ULL, 
            0xBA5881900C10151EULL, 0xB25FBB98C8E905A3ULL, 0x122F06C27B24D9A8ULL, 0x7FC2C75AC4351974ULL, 
            0xD32BBA6A2FE60B99ULL, 0x58EE8DF854E758C1ULL, 0x880551451ED52348ULL, 0x97C893504D98EC4DULL, 
            0x5019581E03F6FE18ULL, 0x343CC7B4B83FC4CBULL, 0x67FF4A4FCE19A009ULL, 0x1DA7651F4EB989DAULL, 
            0x4BB8BBF09EF9BB34ULL, 0x82E7D5F39899FCEEULL, 0x9B2715385B342D16ULL, 0x6860D5B57939EB22ULL
        },
        {
            0x478396237E0F2EA6ULL, 0xA90852CC394790C0ULL, 0xE9F9059FD1AB045EULL, 0x2287C782D39EAF03ULL, 
            0xA20E0A8181E59407ULL, 0x604CAD07161E2675ULL, 0xEDDBD348C135FC1BULL, 0xEACE281AB34BCC9BULL, 
            0xD70D21A28ECE783EULL, 0x7AD8958D3620D605ULL, 0x6BE00092EA656CF5ULL, 0xE80E10DB1AB702E4ULL, 
            0x3C5E09872BABB3CEULL, 0xDBC40EFE083ED0E4ULL, 0x2C60FF4CD1E80630ULL, 0xF5AD7387F739FE94ULL, 
            0x30DF0E133095DF75ULL, 0x1C10174101DD6830ULL, 0x2CFF9571E74FDC64ULL, 0x51F6CE9AFC8788DAULL, 
            0xFF18F2AB862F1749ULL, 0x3AF37B42EBBC38B0ULL, 0x73DB3C73D026209FULL, 0xC5E6919DA9952A48ULL, 
            0x021E41E6FC88DF18ULL, 0xA918AECA09EE9B47ULL, 0xE20BE6B2312D1B01ULL, 0x72FC0613A637DBC3ULL, 
            0x1ED7C4870B2FF9A9ULL, 0xEED65C72BE719BAFULL, 0x18F008EC27A35680ULL, 0x9B0DF29AB69376C1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mimosa::kPhaseCConstants = {
    0x5BE9669406E67C48ULL,
    0xA15DB846A7415F12ULL,
    0xAD5A67D1520CDE08ULL,
    0x5BE9669406E67C48ULL,
    0xA15DB846A7415F12ULL,
    0xAD5A67D1520CDE08ULL,
    0x93CB208D530816BCULL,
    0x285B6CCBF55F0767ULL,
    0x11,
    0xCC,
    0xC8,
    0x7B,
    0x25,
    0xDD,
    0x5B,
    0xCE
};

const TwistDomainSaltSet TwistExpander_Mimosa::kPhaseDSalts = {
    {
        {
            0x617FC9CC06FA3DA1ULL, 0x775879E9D4753CF3ULL, 0xA36630F7543AC79AULL, 0xE284E7870D41F996ULL, 
            0xFE614FBC2E64F847ULL, 0x980CDC096C0160E2ULL, 0x24659F94901D64FDULL, 0xAC8EA9941AC0FB39ULL, 
            0x64569ECF28EF1B21ULL, 0xA9B6E720F9E8E7EAULL, 0x31948D6F61C70102ULL, 0x2E438198479FA569ULL, 
            0x941DFDD228253EC4ULL, 0x7C82876BE9F3743BULL, 0x9773CA58A52EDBD9ULL, 0x6BC02F9C3BC28FBCULL, 
            0x56F0BF8B0BBDC778ULL, 0x8D53FB42181B7BA7ULL, 0x27E4D18F6F7BDA56ULL, 0x0D991F7E6D6F827BULL, 
            0xFE61BBCB08DD3E74ULL, 0xC4582C4611B00F6FULL, 0xE763F67237996C80ULL, 0xC9D64CA6C035D997ULL, 
            0xF4FBB81CDB664130ULL, 0xA05C22E9AD272F3CULL, 0xF63C9B9E5F1FCEA4ULL, 0xBA46F3C2517289C9ULL, 
            0x1296AF610194F64CULL, 0x6DD8BFACCBBC6BB8ULL, 0x296B5C389FD33B2AULL, 0xD4E20A7D2D61B4DDULL
        },
        {
            0x2C7E077C064BCF61ULL, 0xFD4014924C18D3E5ULL, 0x376794BE3DB035F6ULL, 0x469552FA7E9C1DEFULL, 
            0xA38FA3CBA2666C97ULL, 0x9F8520A753DDDABFULL, 0x33CD507C3378DE8CULL, 0x5510D440C70D7398ULL, 
            0x58D85306A9CBDD99ULL, 0xF2A4779F7B42D255ULL, 0x3F465A6AAC032985ULL, 0x0D92DF3A6D8AE7BFULL, 
            0xB692AE5F39642A34ULL, 0x60E6EB0C05536456ULL, 0xD1CC9193BF47A5D2ULL, 0xD3877CCA755AFE64ULL, 
            0x3634CE5C02D44CF0ULL, 0x1EF9E673A1BF2769ULL, 0x4B55A7DDA7948ED8ULL, 0x82154C5BB9C60FF1ULL, 
            0x3172FACE34385FB1ULL, 0x2B1FAF47279BEC2EULL, 0x30105B72215E7BACULL, 0x507D946DF10C922CULL, 
            0xA762B2D808C66186ULL, 0x90CED89CE26643DFULL, 0xC236102B2482EA1CULL, 0x85A1DD86ADCA9827ULL, 
            0xB105B346FB8FB323ULL, 0x80D1292A4B7CF9DBULL, 0x4F20FB4F5172FA3DULL, 0x31917C82C4702F6DULL
        },
        {
            0x1EA9322EB073FDE9ULL, 0x8D8EDB9106D431FFULL, 0x61B883CB0AC7B401ULL, 0x2213D1AD7AFC1F21ULL, 
            0xFFB0CFBFEADBB16DULL, 0x3109938D337B47F7ULL, 0xF7736DA048AD0385ULL, 0x38E48B247A054D99ULL, 
            0x3DD4F4789B64128CULL, 0xA3B2610774F2C4AEULL, 0x8A269104482C8187ULL, 0x7091ED57D051D711ULL, 
            0x138B8AB1043F972EULL, 0x90C83D99030AE11EULL, 0x5BB2CB8B99080ABBULL, 0x08980CC391F88F15ULL, 
            0x6B4B1C2F34E01447ULL, 0xF67EDCA515886394ULL, 0x5748482B4ACC8E8BULL, 0x51132EC53F05DED8ULL, 
            0xD4751C237A434898ULL, 0x28B7871F09A8E8DAULL, 0xDD1E6D6BEC44A471ULL, 0xA93E7764152F4DE1ULL, 
            0x3EBCF297C3DAD371ULL, 0x0533866A01D35471ULL, 0x5B2C573E20184C57ULL, 0x0487E3FB3D1B84E0ULL, 
            0xCE5E1C79C09F414AULL, 0xE37A6EEC6DC90997ULL, 0xB7C86CA5A8A2EC66ULL, 0x72ECFA1243280E30ULL
        },
        {
            0xF564F3C0E2606AADULL, 0x6026E8F27DF957B4ULL, 0xB2441B00AE70F495ULL, 0xE82606C446382901ULL, 
            0x23ADA19526448AF9ULL, 0xD1E3EBA5D977D357ULL, 0x6E71650B3144E076ULL, 0x8F6EFB1173F0DBECULL, 
            0x2623656A5182EEF0ULL, 0x751A0FC19EC2F3D9ULL, 0x004B226EAD9BCEC5ULL, 0x83C6EA9AF3C743A2ULL, 
            0x183BFFA54C606FC6ULL, 0xEEBBC318C690CF9AULL, 0x9B62EDA070CAB2E9ULL, 0xBE03A844F886661CULL, 
            0xFED5729CF59C1AC5ULL, 0xE73DCEE3EDAED431ULL, 0x560BA84257E83F03ULL, 0x19466139E31D7F41ULL, 
            0x78AE7F1F2FDCFB73ULL, 0x0DE4FC769F19EBB6ULL, 0x05AD4928AA59A788ULL, 0xE74E61FC80B9A0A1ULL, 
            0xF12A90D8E2F6B490ULL, 0x81740E5D05EABCF6ULL, 0x2029703E1981FF9AULL, 0x7831965F5954FC23ULL, 
            0x2CEC14A754669455ULL, 0x0C758C9C71ED0AADULL, 0x76E20568760E09EBULL, 0x6634B1A112E48383ULL
        },
        {
            0x3F7093055E629063ULL, 0x1B8F87B43E179E7BULL, 0xB5B2737EAAB2553CULL, 0x7C586DD791E0ADC6ULL, 
            0x9DF95A5EBB2D11A8ULL, 0xF71C556BAD75A53CULL, 0x569D25AF8CB541CDULL, 0x87FA5E3D0ABFD0D8ULL, 
            0xBBC0718A833F6CD7ULL, 0xECC51F220790DE2AULL, 0x5815728CE573B5EAULL, 0x7A4CBA5624701F80ULL, 
            0x2A446D81DBB05575ULL, 0xC836DE3FB3EDB8D2ULL, 0xFB6657FDFF46AD16ULL, 0x3B92FE7325A30B53ULL, 
            0x9B1A1E1A03D6E1F9ULL, 0x77E9B12FA923933EULL, 0xDEE82CCD8DC0C1ABULL, 0x1E821D4855137093ULL, 
            0xEC71C38AE3A92FBCULL, 0x0860014DD6BA8B94ULL, 0xED4D18B19563245DULL, 0x08202969872738CCULL, 
            0xEF504B1BEB3B8C00ULL, 0xDFE5251188C718A7ULL, 0x163650D620E3D020ULL, 0x62BCFE6A0BD2BDD3ULL, 
            0xCE2B80A50218472EULL, 0x4CA47FE267E057BDULL, 0x3CD1C4A77469AD13ULL, 0xBCF01B0D68F3FDFDULL
        },
        {
            0x39CB0430BCA15CA9ULL, 0x94C6F6D1AEA233EBULL, 0x453BE868C027D4EEULL, 0xC5BDBAF443C86572ULL, 
            0x4F9810CAF931357FULL, 0x024286C8CBC8D451ULL, 0x7ECBA7766729158BULL, 0x8093B9A2F15E7ADAULL, 
            0xCDBDE3C5165683B8ULL, 0xB0870CBE91DE90AAULL, 0x3ACE5F45B06E02CAULL, 0x2BFE0D09CB21E7BFULL, 
            0x09DD6A531F465CF3ULL, 0x4A278B34B4EEAD95ULL, 0xAC892581CE98522CULL, 0xA9A6C5B9F81386D9ULL, 
            0x550832C990746E54ULL, 0x5538F5DFE8B62AEBULL, 0xA6F4C4F57022DDCBULL, 0x5B95AC59A7D2ECDFULL, 
            0x31CB1DA1F40BE748ULL, 0x138B0A0EA9F3E4ABULL, 0xBAB99E502767F04BULL, 0x8011DFF79911CCE1ULL, 
            0x721C8994168F1838ULL, 0xC4DB398AAC3A95FDULL, 0xA5F4D1EA1242719AULL, 0x3AC5CD82C6D58A52ULL, 
            0xA7E782F99A2B4CC2ULL, 0xFE604BE4CB22212CULL, 0x8298E92E13CD6F91ULL, 0x2329DDC3DBC8F7D2ULL
        }
    },
    {
        {
            0x1A9CC5A9E0E438AEULL, 0xC280CBD6C1DE83DCULL, 0xCEBED2011DCB84BBULL, 0x77BA7D231764FEEEULL, 
            0xFD02946941740897ULL, 0xFF44414C51AAA4E1ULL, 0x4264F4B6704D8349ULL, 0xF8D00481E39C3766ULL, 
            0xF86A54F3682768B7ULL, 0x3228451A8DD9E84FULL, 0xD7A72A71C90BAAF9ULL, 0x095E19B699DACEFEULL, 
            0xB80F5C9C81B3D5F8ULL, 0x6F9CAEE75C17705EULL, 0x17FADD7E388B8474ULL, 0x6080762CCFC097F0ULL, 
            0x7A93C6E6DB409936ULL, 0x95C7BAAE586AC258ULL, 0xC58584CD68C6EFB2ULL, 0x679EC1C6BE07878FULL, 
            0x56E911E64CE290E5ULL, 0x405E203208D5C072ULL, 0x7816B056F1879773ULL, 0xA557F9A9EA81C65EULL, 
            0xBEBA47358F5900B6ULL, 0xC7ABFC6AF7871F4EULL, 0x09577A396FE18D4CULL, 0x58019AC6BBF59357ULL, 
            0xC9E39B67A87CBB1EULL, 0x69CA45EBFBF2C02EULL, 0x975F870831F6C688ULL, 0x18F3DDE8BDB1978BULL
        },
        {
            0xEFB973AA634C24EFULL, 0x6EF8B1BE6A9FE419ULL, 0x33A91AD279156F13ULL, 0xD0C3E84BEC09BEEDULL, 
            0x992F16897FDF66B1ULL, 0x7367DF92A69BEDC0ULL, 0x68B12970661B370EULL, 0x23997D6FEABC0F61ULL, 
            0xBF1BCFB948E7F344ULL, 0xABD10C65BEB5E5DAULL, 0x3A2F8BFAE9DC911DULL, 0x9E203F2B62D024EDULL, 
            0x7993E26CD66619F5ULL, 0x087462CE315C23AAULL, 0xFCE14E489266040AULL, 0x75AC7EA2F75C89D5ULL, 
            0xD4D9D9EDB34FFD10ULL, 0x387FC09B4F65419AULL, 0x426473392C849BDCULL, 0xAECC2822A7EB2D7BULL, 
            0xCE92A0A851905384ULL, 0xEC5A85692BE56400ULL, 0xF4A895FCB396A072ULL, 0x5C9F0795D66A5DB2ULL, 
            0x42DE4E71BFE09DEAULL, 0xFCA286F9086425B2ULL, 0x7445655B8BF8D3A5ULL, 0x674BD02CDA8D8BBDULL, 
            0x67C0C592B68573A6ULL, 0xE8CE58631DABF3BBULL, 0x047EAF3FDC1EEE46ULL, 0xE3D0F6D356D62CE4ULL
        },
        {
            0xAE7ADAB5F361C573ULL, 0xA8C22D955260E2DEULL, 0xFBDDDAFC299C0ACDULL, 0x3F4CE4209D1AA25BULL, 
            0x004C511050359843ULL, 0x93B59E6DBBB77EBEULL, 0xEB89D886883F1721ULL, 0x4FCBD7EEC10513F7ULL, 
            0x8CA40BE69B7AD1D6ULL, 0xB1B92B3280F56C23ULL, 0x9FE76B68777DAC03ULL, 0xFD5C06006A667B42ULL, 
            0xF03CCF13D0AF176EULL, 0xE74BF42E1278B1E1ULL, 0x65C533A923D45038ULL, 0x703AA22239A1FD1DULL, 
            0x76DAA5088F07A5B1ULL, 0x95647462C64C7072ULL, 0xDD59D7DAB226D3BEULL, 0x2092512D96CA6EB0ULL, 
            0x14833EE535CCAEFCULL, 0x73B9D89C6358B7DDULL, 0x053DDFF0A03401A3ULL, 0x5347E860201154BAULL, 
            0x3DDC7E5AE5BF7A3AULL, 0xE2A191C2261F422DULL, 0x4616352BC9D8A344ULL, 0x00C12FBBA084990EULL, 
            0x804A666639153000ULL, 0xA0F467E7496C5AA0ULL, 0x5E4477925D6B035BULL, 0x360E5897AFE9FC9FULL
        },
        {
            0x2A579BCF590F0050ULL, 0x15D71875F531518DULL, 0x4271D7D91A435A66ULL, 0x4812AD6A8A61D595ULL, 
            0x5B080DE05DF32C1DULL, 0x536B5B75685D1F7CULL, 0xFBF3DEBDF86243C1ULL, 0xDA06E500B0D42042ULL, 
            0x2F3BB13CF7E50793ULL, 0x6464C68C20ACFFC1ULL, 0x74F9EEDB7AA465A5ULL, 0x8B012FAC75017C93ULL, 
            0xA0FCCA47674B542BULL, 0xDB83A273CD627564ULL, 0xE3D9DD49ECBD8813ULL, 0x727BD8A5C5AAAF73ULL, 
            0x3AFD0AF7119C32FEULL, 0xB12DAD5A234E11E9ULL, 0x4BA2C79CF68C88F1ULL, 0xA2DFBA5A68F5CEE7ULL, 
            0x0C3093C5ACCF0B72ULL, 0x1B64548B9110E331ULL, 0x819AA045F488B253ULL, 0x26869AABF5F7A733ULL, 
            0xBB0419611F8AE32DULL, 0x34265A53346B7BE2ULL, 0x21D2CACA335E5EADULL, 0xF6D1AE189D1EDDAFULL, 
            0xE506E59465E9F0D7ULL, 0x4EDDAB2C67E6A094ULL, 0x6D392FAAD30F2749ULL, 0x303731A53AA5882DULL
        },
        {
            0x44799ED62FEED58EULL, 0x74CB171E4E8129FEULL, 0xB9E17AA36738C869ULL, 0xDA658805636D0992ULL, 
            0xD07FBD0C701919CCULL, 0x9185AC9D723F8EA9ULL, 0x5DBAE040622FCAFEULL, 0x4D62247CFC89F831ULL, 
            0x2BF8D426477FD2F6ULL, 0xE739E6F52E7886F3ULL, 0xE435E8A042C6A21CULL, 0x6F6F8337E1B34757ULL, 
            0x7FB1C06EB675E6A5ULL, 0x8F63B3AB6FB4A17DULL, 0x54488479298A0CAFULL, 0x441BE64AEC07AE99ULL, 
            0xD32B9C5479342231ULL, 0xD0DFD396572AF378ULL, 0xD7F9B1981CB67445ULL, 0xF7BFB390937CC5D5ULL, 
            0x82029B8F47D0BDD0ULL, 0x9B2C833BFBA1AFF9ULL, 0x475B6FCC0C48DB30ULL, 0x0F68E2061172DE46ULL, 
            0x4C671A58D456BBF9ULL, 0x07EDDD041C6DEBCAULL, 0x8E47F2FE75117131ULL, 0xBCBFC7E0F3387739ULL, 
            0x72569B4877046C01ULL, 0x7C87E358FA8A91BEULL, 0xD8964A3FB9D02E30ULL, 0x87D0ABE998060692ULL
        },
        {
            0x5EABB11875B0270FULL, 0x552B6B4A3CC19676ULL, 0xCB056A33C9CE1DCEULL, 0x3727FBE80F3371F1ULL, 
            0x2BC0A9EC7B2EC96DULL, 0x5F276708834D7E15ULL, 0x6A065C584D1ED050ULL, 0x6B9E591B13D86127ULL, 
            0x3214F6CCE1E9C000ULL, 0x06D0F9BA263EE533ULL, 0x0CBE27561FB53AF4ULL, 0x5DC37AE84F0F6872ULL, 
            0x70F6F5C917662F4AULL, 0xDA69D0743798E034ULL, 0xEBAF92F2D6C2B172ULL, 0xB1CC04F7699E3E75ULL, 
            0xC76D5B19BDAEBCB1ULL, 0xC8AEE43DE1146E20ULL, 0x42397474C40260AAULL, 0xB8A976CC18A9F349ULL, 
            0xAFCB25DD81A84BC7ULL, 0x812254ECA5D34BEBULL, 0x3816BD61C18E449AULL, 0xCE5162FB4772E863ULL, 
            0x0E08CCF14F89EA94ULL, 0xAFCA3A5FC2308487ULL, 0x20DC68B486F614F4ULL, 0x1E9E42607624995AULL, 
            0x4586DFB5ADB21900ULL, 0x66957938680CAEA5ULL, 0x88D38AEA6EBA204DULL, 0xB511B2542E36638CULL
        }
    },
    {
        {
            0x17FEAA2C1FF31FAFULL, 0x7570AC948DC07D5BULL, 0x435E7543DB383CD7ULL, 0x9AE0B8289250E424ULL, 
            0xC65234FC1F641CB5ULL, 0xF0B168039AC624D7ULL, 0x6558511467173ED4ULL, 0x47C80C064FC21E36ULL, 
            0x092E1888F4C61ECFULL, 0xADC2B503478A7975ULL, 0x972739660518E581ULL, 0xAA910989B1BD3FAAULL, 
            0x036C5395EEA42940ULL, 0x52376B0D9FC53D7CULL, 0xD41FACA96F25A081ULL, 0x01ECA02AB769D954ULL, 
            0x8C66E7695EC30E9EULL, 0xFBC4196EF65D599CULL, 0xF8058941A33B5F6CULL, 0xE8BC932641F6AE01ULL, 
            0x0CBFF1D4A8DF884DULL, 0x8444CD1E0C7D1501ULL, 0x48235D1E63C06ADBULL, 0xFC332DA0E576BAD4ULL, 
            0xD28113CA6C5E9B59ULL, 0x794CB7EE2A83E4C9ULL, 0x63A04CA6695CA6A6ULL, 0x24253E046281259DULL, 
            0x4AFE01B9EDD0C305ULL, 0xBA746AAC809863ACULL, 0x3C4B862BF70F4C50ULL, 0x1BEEA82C63FE49AFULL
        },
        {
            0x166DD568B00C757FULL, 0x0187C1C23DA4BBDDULL, 0xB498D7995CFB96F3ULL, 0x101E25FAEDE2358AULL, 
            0x92B5C582C5F16AA3ULL, 0xE3BF06563E0E2D88ULL, 0x338AC271BBC0A8F4ULL, 0xE3B7BA57F7867B74ULL, 
            0x3C414C9E75C9B592ULL, 0xF020D426A6DA4035ULL, 0x2615C48AB7EFACF1ULL, 0xE9AE6947DDBCF84DULL, 
            0x7DB3E5FBB4CA74CFULL, 0xA42EBF70CA975315ULL, 0xE66AD76FFE781DB2ULL, 0xB9A63901DB0DDBACULL, 
            0x98D87759309A40E2ULL, 0xDCBDAAB563CCE001ULL, 0x3CEB8DFCA2151F8DULL, 0xAC21B54B13F0F271ULL, 
            0x9E7E9D77773687C3ULL, 0x645609182E0B3FD0ULL, 0xE8C7C1357F253A9BULL, 0x20E0B669DDCFC03DULL, 
            0x7738F24534685BB4ULL, 0x4166875767BA5679ULL, 0xB691380FFA2EBB94ULL, 0x1F6EA4DB30073874ULL, 
            0x220FDBA9C069377AULL, 0x376F5BA6F65B5643ULL, 0x4A00B22EB7DE397AULL, 0xD5168C0B8972BA19ULL
        },
        {
            0x2D136C5DFC8BF941ULL, 0x4F6AA5E788EFC6A5ULL, 0xBA50C61D97F5D45EULL, 0xC1F06F9B7D93E9B0ULL, 
            0xBAA998142BF80E66ULL, 0x30E062F4580A1E47ULL, 0x420EF6413120E97BULL, 0x800EB741B8A3DB97ULL, 
            0xC339EECCF60FA8B1ULL, 0x85F24A3306B8F2B3ULL, 0x80395C0A6A69DD21ULL, 0x1DDEC8C08D46B204ULL, 
            0xE8A212C56268CAF4ULL, 0x59D92503A580DF41ULL, 0x4E64E8CB29DFB2E0ULL, 0xBC013EDF46AE828BULL, 
            0x534D313ADEEFB948ULL, 0xCAD14A466A0A4352ULL, 0xA760A8A2534D8BE1ULL, 0xF1753CA0C1253841ULL, 
            0xCF859C2E7B84DF82ULL, 0x1FDAB25CD809FD7CULL, 0xACC593FC91D600EBULL, 0xF50152CBB963E4DEULL, 
            0xB9F67B203B71B735ULL, 0xF014472E47ACF7EAULL, 0x835F9ACFE156872BULL, 0x7C4DA03C53DFD012ULL, 
            0x96E5090C2FEDA8D7ULL, 0x94DD997668549B90ULL, 0x3195B95741AABBFBULL, 0xA43B58AD8D91ED2DULL
        },
        {
            0x17A19A4A97240F9FULL, 0x6B8812D3EBF07F7EULL, 0x5BF7BD6FE094D35AULL, 0x71107DCCA3E221B0ULL, 
            0x0A35CF74DF2214FFULL, 0x5EBC531082B4A7B5ULL, 0x01E66A5BA8871416ULL, 0x44BE573697003EA4ULL, 
            0x0A205EEAC2F2630DULL, 0x28D8DB76C1143C05ULL, 0x6C3B6025B269F556ULL, 0x013686060938AA41ULL, 
            0x4A9059ECA52CB038ULL, 0xED2050C23A60F986ULL, 0xCD12B81157B3B106ULL, 0x945256163C787A4AULL, 
            0x5A11A4A9FC9043DBULL, 0x2BA066E35FDF0556ULL, 0x1C250E493DB2DBD8ULL, 0xD8BC216E15CAF765ULL, 
            0x4DC08159E302DA62ULL, 0x65530AAF8A14BC99ULL, 0x00083FA96EF3B918ULL, 0x8293193812530C2DULL, 
            0x2492EAD05416A13EULL, 0x9E242524AF8A3790ULL, 0xD3BCB722D3B61805ULL, 0x76D2A64D8E699A3AULL, 
            0xD54C760E2DF93645ULL, 0xC2B133B41641A10FULL, 0x9B49E8F32844906CULL, 0xD91D9795DEA4CE8CULL
        },
        {
            0x867BE26AD94730EEULL, 0x51DD1667036EEF55ULL, 0xE6E4B41FBC21AA58ULL, 0xEA4B0D511396084AULL, 
            0xEACBCC8B97810E17ULL, 0x4E6514F7465612A8ULL, 0x1985EF4FC9CC2C5AULL, 0x05119BD39453F170ULL, 
            0x74907101559A21F0ULL, 0xD822C6C9D92E2C3EULL, 0xD711F6876DFA527FULL, 0x784F320B00FC4717ULL, 
            0xEA6FAC7FB08C9D06ULL, 0xDCD70189DF868B5FULL, 0xD0FBD674583D3097ULL, 0x9F5523AA7EC0F5C3ULL, 
            0x919806A34EE91A01ULL, 0xFB81C2EC0BB8431AULL, 0x85AE2AC9E404C031ULL, 0x115B3332B6370634ULL, 
            0xE9F83FC296C6D7B3ULL, 0x6F4A9EF6A1C98CD5ULL, 0x0334F22249E57BE5ULL, 0xC200FD9E7E22C0ABULL, 
            0xA742292197F74404ULL, 0x88DA0A535CE14960ULL, 0xAE34CEEA42648E3AULL, 0x756B60F78E438501ULL, 
            0xDA77F68480F1C0B5ULL, 0x7B081FD80632F71BULL, 0x7A5D2DEB49925421ULL, 0xD10704761488476CULL
        },
        {
            0x225DB973C26F6C8CULL, 0x3803ABC374DBC276ULL, 0x723F6D7BCA959372ULL, 0x6DD5EEB74B16E43CULL, 
            0xFCEC76B770A321BBULL, 0xE9EF695FED41A2FDULL, 0xCD059F86C698D0C3ULL, 0xB43B02676795477BULL, 
            0x93E0C47157DEF757ULL, 0x70F5CEDD070B0DCEULL, 0x744839E347561888ULL, 0x0A7B2866BDBE2F26ULL, 
            0x206B2458A31DA573ULL, 0x8A7601CA8ECEC248ULL, 0x010846885BC7CBDEULL, 0x32D2BBCA6346BCE8ULL, 
            0x3CF81796F0D268F1ULL, 0x1D3289ABE8F939B2ULL, 0x22E3FF488D071154ULL, 0xD683964E113AC1B0ULL, 
            0xA734F0E777EB9A92ULL, 0xBB8E74C63BC4DD1AULL, 0x1A2B779C4822C6CDULL, 0x083DBFD4FE3C0498ULL, 
            0x6C2AD2B0938A7792ULL, 0x0450D396BE6B0D88ULL, 0x92D26352D7FEC3AFULL, 0xA30665990E4C8091ULL, 
            0x8EEC09704A0E3306ULL, 0x5B8B1185C3A84B84ULL, 0x2389D77F8CD249E8ULL, 0x127163FB620AAEA9ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mimosa::kPhaseDConstants = {
    0xB30B8B1FDF2DC236ULL,
    0x6C0838B45A718190ULL,
    0xCB02722EF6F286FAULL,
    0xB30B8B1FDF2DC236ULL,
    0x6C0838B45A718190ULL,
    0xCB02722EF6F286FAULL,
    0xD33723F6106EF88DULL,
    0x1F303DCF2CF94354ULL,
    0xAA,
    0xAD,
    0xD1,
    0x4D,
    0x96,
    0xA1,
    0x8C,
    0x02
};

