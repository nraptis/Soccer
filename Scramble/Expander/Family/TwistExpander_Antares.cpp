#include "TwistExpander_Antares.hpp"
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

TwistExpander_Antares::TwistExpander_Antares()
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

void TwistExpander_Antares::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xEDEE5DBCAF899FA4ULL; std::uint64_t aIngress = 0xBC77D9E601E00118ULL; std::uint64_t aCarry = 0xA421C1E3A2856FDEULL;

    std::uint64_t aWandererA = 0x98704A1340150364ULL; std::uint64_t aWandererB = 0x944FEB50EBEAAACAULL; std::uint64_t aWandererC = 0xC37BA52BEE21C04BULL; std::uint64_t aWandererD = 0xFE7EB22AB869C6BDULL;
    std::uint64_t aWandererE = 0xDB38676EA5BBEE08ULL; std::uint64_t aWandererF = 0x8F4F7319D796E8EBULL; std::uint64_t aWandererG = 0xC830AC6C4A55DD37ULL; std::uint64_t aWandererH = 0x9B6F5DF0DDB026B0ULL;
    std::uint64_t aWandererI = 0xC293C6215C01BE09ULL; std::uint64_t aWandererJ = 0x9EB0BF601EEA7C00ULL; std::uint64_t aWandererK = 0xAB82FA09ABFF280CULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xC707A9D1606CE8C0ULL;
        aCarry = 0xEED71DAA31C8DF17ULL;
        aWandererA = 0x9C73DAF08FC1E837ULL;
        aWandererB = 0xBD5DF89008617B99ULL;
        aWandererC = 0xC1FC7C1ADA8F27D4ULL;
        aWandererD = 0x89D0FB6354A392F8ULL;
        aWandererE = 0xCF3ED0E3DB1772C5ULL;
        aWandererF = 0x8F69548EF1C1EC13ULL;
        aWandererG = 0xA7BBA6BD0C51B56EULL;
        aWandererH = 0xFAE329266E9D812FULL;
        aWandererI = 0x90AB39E6EEEDB15AULL;
        aWandererJ = 0xA7EFF2326D0BF6ABULL;
        aWandererK = 0xCCA039959C10EA2FULL;
    TwistExpander_Antares_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Antares_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Antares_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Antares_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Antares::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xEBBB8542CD715648ULL; std::uint64_t aIngress = 0xD2A83A3154C8DFEDULL; std::uint64_t aCarry = 0xE70B423EED3E57AAULL;

    std::uint64_t aWandererA = 0xED8C64BB8DBD534FULL; std::uint64_t aWandererB = 0x8D58C3B51479D806ULL; std::uint64_t aWandererC = 0xEA15F7FC51E80126ULL; std::uint64_t aWandererD = 0xDE01F667603F325FULL;
    std::uint64_t aWandererE = 0xD2CD7D6A1A2DAC1FULL; std::uint64_t aWandererF = 0xEFC0EEBBDC9BAD12ULL; std::uint64_t aWandererG = 0xE4AA5899D93E12D6ULL; std::uint64_t aWandererH = 0xC906D99A8808C46CULL;
    std::uint64_t aWandererI = 0xD454D440874CEA0FULL; std::uint64_t aWandererJ = 0x900105FFEA453BA6ULL; std::uint64_t aWandererK = 0x80C43DB9FB7D3507ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xE03245407722C625ULL;
        aCarry = 0xA92FCB95B580AADDULL;
        aWandererA = 0xF6B6407BB527BC1AULL;
        aWandererB = 0xA0BFF25AE5754CABULL;
        aWandererC = 0xECE75E338D0FC8C2ULL;
        aWandererD = 0xB1A9F8AEB1A5ED3FULL;
        aWandererE = 0xCE1C92566DDF024DULL;
        aWandererF = 0xD825969A4DA5DC92ULL;
        aWandererG = 0xAA5433B0C06357BAULL;
        aWandererH = 0x9108DC8C94B45DE4ULL;
        aWandererI = 0xE7A3DFF5BF8F8E0FULL;
        aWandererJ = 0xA3F550DE36A3325AULL;
        aWandererK = 0xBCEBDFD8C5C2891FULL;
    TwistExpander_Antares_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Antares_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Antares_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Antares_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Antares::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD7775FDE77DDCCCAULL;
    std::uint64_t aIngress = 0xCDABC634154D811DULL;
    std::uint64_t aCarry = 0xCBABE73934F242FDULL;

    std::uint64_t aWandererA = 0x82C55AEDCCD28C73ULL;
    std::uint64_t aWandererB = 0xCFE594F051C6A663ULL;
    std::uint64_t aWandererC = 0xFE060705FD543516ULL;
    std::uint64_t aWandererD = 0xEFD4AC45B4CF06A1ULL;
    std::uint64_t aWandererE = 0xCA1DFBEB978ADA53ULL;
    std::uint64_t aWandererF = 0xC11CC8EF75A38DC8ULL;
    std::uint64_t aWandererG = 0xD13F2484233695A8ULL;
    std::uint64_t aWandererH = 0xF7AD1DF9E4D6B0A7ULL;
    std::uint64_t aWandererI = 0xC87BF6B4542F7EDEULL;
    std::uint64_t aWandererJ = 0xA2EAB048EE26A172ULL;
    std::uint64_t aWandererK = 0x9894DB8CBE235053ULL;

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
    TwistExpander_Antares_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Antares_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Antares_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Antares_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Antares_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Antares_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Antares_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Antares_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Antares_Arx::GROW_A(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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
    TwistExpander_Antares_Arx::GROW_B(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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

// SmartSquash candidate 9 of 33
// Exploration cases: 100000000
// Nearest-family diversity: 946 / 1088 (86.95%)
// Total distance from earlier candidates: 7667
void TwistExpander_Antares::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    static_assert((S_BLOCK / W_KEY) == 16, "SquashInvestToKeyBoxes expects 16 invest fragments.");
    static_assert(H_KEY == 8, "SquashInvestToKeyBoxes expects 8 key rows per box.");
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 13U), *aFragmentB = aIceLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 1U), *aFragmentD = aIceLaneD + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 820U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 558U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1674U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 17U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 0U), *aFragmentB = aIceLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 13U), *aFragmentD = aIceLaneD + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 567U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 684U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 872U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 12U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 4U), *aFragmentB = aIceLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 3U), *aFragmentD = aIceLaneD + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 446U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1548U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 944U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1606U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 11U), *aFragmentB = aIceLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 15U), *aFragmentD = aIceLaneD + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 683U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1045U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1874U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1575U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 8U), *aFragmentB = aIceLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 8U), *aFragmentD = aIceLaneD + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1223U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1290U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 122U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 871U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 3U), *aFragmentB = aIceLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 14U), *aFragmentD = aIceLaneD + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 573U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1457U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 324U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1081U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 15U), *aFragmentB = aIceLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 2U), *aFragmentD = aIceLaneD + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1907U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1909U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 2040U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 935U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 10U), *aFragmentB = aIceLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 11U), *aFragmentD = aIceLaneD + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1464U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 314U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 851U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 217U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 14U), *aFragmentB = aIceLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 6U), *aFragmentD = aIceLaneD + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 847U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1718U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 747U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 73U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 1U), *aFragmentB = aIceLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 9U), *aFragmentD = aIceLaneD + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1496U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 780U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1333U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 222U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 9U), *aFragmentB = aIceLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 0U), *aFragmentD = aIceLaneD + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1215U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1798U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 818U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1873U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 12U), *aFragmentB = aIceLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 10U), *aFragmentD = aIceLaneD + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1596U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 562U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 632U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 479U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 6U), *aFragmentB = aIceLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 12U), *aFragmentD = aIceLaneD + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1538U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1936U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 677U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 345U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 2U), *aFragmentB = aIceLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 7U), *aFragmentD = aIceLaneD + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 216U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 405U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1040U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1902U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 5U), *aFragmentB = aIceLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 4U), *aFragmentD = aIceLaneD + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1861U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 369U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 329U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 619U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 7U), *aFragmentB = aIceLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 5U), *aFragmentD = aIceLaneD + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1486U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1062U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 874U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1190U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Antares::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE3C0E383CE476CCFULL; std::uint64_t aIngress = 0xD466950C4782915FULL; std::uint64_t aCarry = 0x96E540FF705C4868ULL;

    std::uint64_t aWandererA = 0x9B2BD0B8E11A7AE3ULL; std::uint64_t aWandererB = 0xA60940879FD15F42ULL; std::uint64_t aWandererC = 0x90E60167DE353DBDULL; std::uint64_t aWandererD = 0xEE571B5FD9D878A7ULL;
    std::uint64_t aWandererE = 0xDDAEA375C43BA382ULL; std::uint64_t aWandererF = 0xCA3B389162FD8743ULL; std::uint64_t aWandererG = 0x9A95BD9E6A442221ULL; std::uint64_t aWandererH = 0x83AF3FB6B0317890ULL;
    std::uint64_t aWandererI = 0xFF9486C24B6173DCULL; std::uint64_t aWandererJ = 0xBF179F3CF795E6E3ULL; std::uint64_t aWandererK = 0x895D8C7A9C802F39ULL;

    // [seed]
        aPrevious = 0xBD5C6218E9CC0FE8ULL;
        aCarry = 0x8542D5C98503F2C9ULL;
        aWandererA = 0xDF58700C0B847D59ULL;
        aWandererB = 0xB0EDC8C1A7116D90ULL;
        aWandererC = 0xF5E9ACE6C4FEAC84ULL;
        aWandererD = 0xC2EC12BB75EB3F41ULL;
        aWandererE = 0xD56CDF978A542ECBULL;
        aWandererF = 0xD72D68D0932075A7ULL;
        aWandererG = 0xCE62ACA3960F6E33ULL;
        aWandererH = 0xA843EF50D6423794ULL;
        aWandererI = 0xA7BAC1C308209D7BULL;
        aWandererJ = 0xACCB4473B5CE5EDCULL;
        aWandererK = 0xEE48E21DF1FA52ECULL;
    TwistExpander_Antares_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Antares_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Antares_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Antares_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Antares_Arx::Twist_E(pWorkSpace,
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
    TwistExpander_Antares_Arx::GROW_A(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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
    TwistExpander_Antares_Arx::GROW_B(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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

// GrowA candidate 9 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 4463; nearest pair: 484 / 674
void TwistExpander_Antares::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6188U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3650U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5143U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7719U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6281U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6823U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6295U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2391U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5317U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2148U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1815U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7254U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4810U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3556U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 600U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5580U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1785U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1479U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1592U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1782U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 509U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1290U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 99U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 147U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1942U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 240U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1412U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 375U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 365U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1964U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1325U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1049U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 887U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 508U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
}

// GrowB candidate 9 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 4465; nearest pair: 521 / 674
void TwistExpander_Antares::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2365U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7255U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6208U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2600U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 326U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4391U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7926U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7539U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4731U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3965U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1434U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6885U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3169U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4181U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 976U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5343U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1115U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1619U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 947U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 935U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2039U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1692U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 567U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1023U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1615U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 394U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 721U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1481U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1113U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 569U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 862U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1487U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1816U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 627U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1702U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1888U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
}

const TwistDomainSaltSet TwistExpander_Antares::kPhaseASalts = {
    {
        {
            0x7DCD3B0B362B966CULL, 0xE7444426CA07F72DULL, 0x8C704E53EEE78218ULL, 0xF0C7B38A56C5A0B3ULL, 
            0x76AFE75CB07E4AF5ULL, 0x09822EEB32B95B5CULL, 0x791658C0B543FA9BULL, 0xB63682EC604389EDULL, 
            0xEA58694B208D3585ULL, 0xBE41D3809550EB25ULL, 0x2BCE5054D48EDEDDULL, 0x57C1D69780DA22CAULL, 
            0x4AF365F2D750DFC3ULL, 0xF6DD100ABBC32AA6ULL, 0x72A51962F72B39DFULL, 0x59F0F20BDFCB6115ULL, 
            0x147B99E460990583ULL, 0x6B5830D32B36B41AULL, 0x2B46D7F884A52D79ULL, 0x52DE277EEBEE7AC9ULL, 
            0x97D67804B0D27D70ULL, 0x459869E63BD145D4ULL, 0x91FB8CAAD281BCF8ULL, 0x6040BE2774525F35ULL, 
            0x0CDDE9ED4FFE18E1ULL, 0x9416840BD2427ACCULL, 0x9458A2E5D8B623F0ULL, 0xA22B40EADE7C7F4FULL, 
            0xE2BADC0A3A998A90ULL, 0x91CED3F85981CCB5ULL, 0xB5D5D53C8869D741ULL, 0xA20E56ABC99912F0ULL
        },
        {
            0x0E842D51291348AEULL, 0x2AA97BBE6ED2D547ULL, 0xAA3C9F1A56EDCD77ULL, 0x89F3B90278AC18C0ULL, 
            0x2687A93B7043D370ULL, 0xAC4B6E022CACF4FBULL, 0x42AA07A3843305ECULL, 0x6D633617C75CD81EULL, 
            0x446265838658273CULL, 0xB67ED4B6B0D7E012ULL, 0x1A5476A95BF46CCFULL, 0xAB10BB95C2F5A441ULL, 
            0xB1E142557A5BE373ULL, 0xD3D4205322832D58ULL, 0x7BB0AD1D3191E04EULL, 0x08F0742EEE3CE388ULL, 
            0x1A7C2C1CEEFD2094ULL, 0xB9EF31FFC7679564ULL, 0x258436680F265E9CULL, 0x0B35B5F0187DDC27ULL, 
            0x30A99E7B3A0005B4ULL, 0xBBF46D296A535F71ULL, 0xB15A34FE1CCF538AULL, 0xD84CCEF7A3CADDF0ULL, 
            0x1C51ED6C58497121ULL, 0x120E1EC2EF3B34AEULL, 0x90EE5669645ADC9BULL, 0x5744B4050DDCC838ULL, 
            0x3F39C94F900889EEULL, 0x33D7009671019CAEULL, 0xCDBC0010AD820846ULL, 0xBAD8A38A2951A79FULL
        },
        {
            0x663F10050F912C42ULL, 0x7006EFDC18FCB050ULL, 0x3E44B279256B2091ULL, 0x7CCFB4A8F029166DULL, 
            0xB9A5931BCE62F3C1ULL, 0x70E8F71C193A9807ULL, 0xED1F237553D8F463ULL, 0xEA56FE6A62CF16DCULL, 
            0x125EED7538CBA643ULL, 0x8885F94B6EB93777ULL, 0x0D6CE386AA5E84F5ULL, 0x96668C8F91C2F348ULL, 
            0x77D75F16903636E8ULL, 0xC51905602484EC7BULL, 0x27BEA0B0F6E53944ULL, 0x87C5F90BDB80B7A9ULL, 
            0x64F9D9BFFF00BE58ULL, 0xFB8EE2DC5BF66BADULL, 0xFAA618984CE44D26ULL, 0x455B239B412A9CAEULL, 
            0x8E59C823E671B856ULL, 0x50467076AAF59139ULL, 0x40AA32AF6B4D4538ULL, 0x418702CA42964EF5ULL, 
            0xEDE8A1291AF9BE26ULL, 0x06AEDE9E1B008CFEULL, 0xF16542ECBC613AA8ULL, 0xE1DEA645AA91D6C4ULL, 
            0x50206D8E94B44CFCULL, 0xE3F19F17D682B6BDULL, 0xFB3FD42E8C068E04ULL, 0x2EEDC713E8C7CB74ULL
        },
        {
            0xB81795CCC4D49A6AULL, 0x8F859FA7FD21A7F8ULL, 0x23D9F888A5F077D3ULL, 0x9B637A637C977F75ULL, 
            0xBD6152FC55626E52ULL, 0x8A4E69A9589068B0ULL, 0xD7209C5C8309183DULL, 0xE37F83FF239CA4C7ULL, 
            0x2FE5DF38C8467527ULL, 0xD60A756BF02B26F9ULL, 0x7C8F3ECC95B1E1F7ULL, 0x75DF94CC969376E3ULL, 
            0x145655439B8CC8B2ULL, 0xE4C99E8A76076F65ULL, 0xCEF89421EDEB2CC6ULL, 0x39303D5E95F54F7BULL, 
            0xDF76542B2C3CB469ULL, 0x31EEDF6B8FA8AC5DULL, 0xFBA941286356C508ULL, 0x590B7499F2BFBB48ULL, 
            0x06B9F81AEEB62A6BULL, 0x9B2ED9EE7C08467FULL, 0xCA40EB2FC2E3522BULL, 0xACCA33D3C7C2B048ULL, 
            0x6278842091F7747EULL, 0x26CC39984F3CDE5AULL, 0xD513D741241383ACULL, 0x4F2F2C5305E373A6ULL, 
            0xAB4C8CAFF37019F3ULL, 0x6975569E3F6863B1ULL, 0x26343194839AC98EULL, 0xE3278C5B5733239BULL
        },
        {
            0xA2882C45268D7955ULL, 0xC14714FC46B25BFBULL, 0x8479A473F5B4580CULL, 0x1A7691B0419B8C13ULL, 
            0xA372530B88BF3D22ULL, 0x3C850894BAD6C783ULL, 0x993B255437E0F72CULL, 0x657D08820878DA19ULL, 
            0xA43BF85FFA52741FULL, 0xDC9117BEB958EB14ULL, 0xC96C444552C4BDD5ULL, 0xBF4FAEC636DFA91DULL, 
            0x3DD4C70D25A40362ULL, 0xD2902173786B8097ULL, 0x554FA1A8E497B2FEULL, 0x8FEA82D5A7D8CA90ULL, 
            0xB6FA3A74AA382AE9ULL, 0x4F36DBC2B2D0342AULL, 0x233916D19BF6569CULL, 0x848938C7B18071A0ULL, 
            0xD8FE87BB013990CBULL, 0x28DA088304CCB3F8ULL, 0xF50B8305923B486AULL, 0x5929DC655D983EEFULL, 
            0x4487ACFEE4A23C97ULL, 0xABD35AF2F73F638EULL, 0x99B853FCD15BB54BULL, 0xA093FE7D8EB54393ULL, 
            0x3E39BAE8A63566C0ULL, 0x180734C8A9F3FBA3ULL, 0xDD098EC548CDF21DULL, 0xFDA0F9DBA683EBABULL
        },
        {
            0xA0D38672DBD06F38ULL, 0x4339C5E541E0194DULL, 0xAD8961710E4C2828ULL, 0x5B22BDB18980DC5BULL, 
            0x3EBB1F9BE5D8B121ULL, 0x1DA493104AF10C4AULL, 0xEE1996B75A823EECULL, 0x9297B8F1E2503285ULL, 
            0xF38B1D5AF7BC45E5ULL, 0x84A1BC6F7FB60756ULL, 0x0495332E8E29B027ULL, 0x803AF172904D6456ULL, 
            0xACA51E25A1EDF8E0ULL, 0xDB102DC7F1A7B54BULL, 0x02E08229D3779BD1ULL, 0x24B32154972A9575ULL, 
            0x31E546CEDAF299D8ULL, 0x09A5725196850DCFULL, 0x8A19533F87C053C0ULL, 0x7D81CA222BA13DB0ULL, 
            0x883ABC85BE630978ULL, 0xE66AD9317D12CC2DULL, 0x5498DB7E5CCF74A7ULL, 0x099DE83737D7D96AULL, 
            0x30E9FF11E21D6DEFULL, 0xDCDD6D7B174ACAD3ULL, 0xCB0CF27872D4DABFULL, 0x78E54681AA2BF099ULL, 
            0x4B3B625319643F64ULL, 0x7567F781EE0869BFULL, 0x35836D3C872172ADULL, 0x841B0965EEE288AFULL
        }
    },
    {
        {
            0x2A787EF99934706AULL, 0x177D5754F679D457ULL, 0xF3C6B188518D1961ULL, 0x4CACDC04818EAD79ULL, 
            0x51D30309647AA616ULL, 0x6EEA8E61EDDEE18CULL, 0x56AA9BB538531F81ULL, 0x99243C3242A6A975ULL, 
            0x6025BF43C98123D6ULL, 0x8CBECD34478AFC5CULL, 0x5099EEBE474BF415ULL, 0xB8EA74008865E9E1ULL, 
            0xC80CB52B53DD7619ULL, 0x9D8ACD232E999C93ULL, 0x403103208BC7F8E6ULL, 0x2B32B84B8B8CB2BBULL, 
            0x31D566B8BCD84477ULL, 0xD49A81BEE7A66692ULL, 0xCADCB25669FCA7B7ULL, 0x4A510288B19C8A98ULL, 
            0x5501806C1DD7457DULL, 0xF5EB8E93729BABC2ULL, 0x4275CE4E14A0080DULL, 0x09EC8EF67B62EF6EULL, 
            0x10AB89537AA9AA89ULL, 0x62B7CD79E84A5A73ULL, 0xAD98CCBF5CDA1C7BULL, 0x3F64760628CC2C28ULL, 
            0xDC950E155A358332ULL, 0x90BB96779CB8A88CULL, 0x731853426DCBABD8ULL, 0xE072DCD914E09970ULL
        },
        {
            0x8BCD580A5B7E7EE5ULL, 0xB7CA0C0A3A9EE5CBULL, 0x8EFC560C195FD7E9ULL, 0x6B09EB315F5073A3ULL, 
            0x01425DF0DDEFA890ULL, 0x4BB31B3DB5072D50ULL, 0x1BF5F44FFC5A895AULL, 0xBE1227077DF33D2CULL, 
            0x342A668CEC1BAA7AULL, 0xAB712AFAC165E021ULL, 0xA45F9970DC3B2266ULL, 0xDDEAE2EAD6773C23ULL, 
            0x980D0C3BAFB6FC62ULL, 0x580DD4A0AC6B5ED1ULL, 0xFE8CCB2871DF9427ULL, 0x8D93371AA63A92DFULL, 
            0x9B9579A2FE11F80CULL, 0xE809D52DA04BC9D7ULL, 0xFC3071E6326D6E48ULL, 0x402CFDB8C8F56808ULL, 
            0xFFAE0E983A88A0A7ULL, 0xC9B24EA257B9C7DCULL, 0x09CBBB29496E7D8DULL, 0x7F94F7BD5995D059ULL, 
            0xB650EE0E26D6BACCULL, 0xD8CB8F86F16815EFULL, 0x9BAF770F3B485D95ULL, 0x8BD956027F605DF0ULL, 
            0x78D61DEDD3BFFC60ULL, 0xE902B6BD12E9BB5FULL, 0xA3734F3B0F8A0541ULL, 0xF848324731E314A5ULL
        },
        {
            0x14CD502D416BD05DULL, 0xE4439E9D7658B9B8ULL, 0x9DC2D055B925E0F6ULL, 0x65F2E37E81B09849ULL, 
            0x45D5E0FC094BA26BULL, 0x8DE133BF270F0138ULL, 0xC76729C35F4CDDB0ULL, 0x8595EF48F2AE760DULL, 
            0x91E130D0FD27003BULL, 0x5FA8C7FF12F0D67BULL, 0x8CBDDCB5339BEA84ULL, 0x83C48B155EE6D9D5ULL, 
            0x86D4E586BD58E167ULL, 0xFA14F233A60D890DULL, 0xE589D7F241FC13CCULL, 0x4B4DC44EC07437C6ULL, 
            0x2A4ECE8BE7157839ULL, 0x110736AD3D422B2CULL, 0x2ED3326B1A9F12B8ULL, 0x6ED13AD8E3088867ULL, 
            0x5B392D71FB6F13F2ULL, 0x77071E401E66C55BULL, 0x69162B7F5EA54003ULL, 0x048D5141C7FCE173ULL, 
            0xE77EDB965270C82BULL, 0xCC658543D5D1F14EULL, 0x92E17A38266DE430ULL, 0x58315A31B7EF0A2FULL, 
            0xA31DCC80EE457727ULL, 0x427F5FC993E74005ULL, 0x7DDFBAAA882979ADULL, 0x80CCEF8F17CA3615ULL
        },
        {
            0x91D1C29E3EB9A625ULL, 0xD10B12194E205A6FULL, 0xCEDE9CDCE1652539ULL, 0x92DC2221868537A8ULL, 
            0x5E2A0202A6500F62ULL, 0x8E16C8291DE4E07FULL, 0xB60C6EDCA328E2F4ULL, 0x6814392750224992ULL, 
            0xC16E82D0BC5FC730ULL, 0xB127B50E618AEED0ULL, 0x5CE3A2A1BE91AB6CULL, 0x5A1065FBA37CA376ULL, 
            0xCB64B16CB90A5514ULL, 0x96506DD305AC0DB4ULL, 0x139EE2CE7194F349ULL, 0x15D2D3EC3FB31D2EULL, 
            0x6F101572496D579CULL, 0x0628BCAC7681533CULL, 0xA436AC0BF606AC9FULL, 0x185D9BF350E915CFULL, 
            0xD91BC42C591D9AF2ULL, 0x6F024262576A2C6AULL, 0x06994B764405074EULL, 0xDA63B506DA671E1AULL, 
            0x44E6410176788239ULL, 0x4E6DA6E4FF6B19CEULL, 0x93883004867EBFFAULL, 0xB81F573D86167F20ULL, 
            0xE74BE32D1498267CULL, 0x432CAFCD604E6996ULL, 0x8DF2626C592B6BC4ULL, 0x2CB67EA31ED16CFAULL
        },
        {
            0x25905CE0AAAD5761ULL, 0x96CF446C236D15A9ULL, 0x40DB01BCC30AFAFEULL, 0xF2D42312A6905A39ULL, 
            0xFAC2767CC7BB8151ULL, 0x3DC146FAE36FB867ULL, 0x031BCF2E564F5E61ULL, 0x74233C6D9905B37CULL, 
            0x8CFCB128EF46050AULL, 0x9FEF229498CF638AULL, 0x75E8C92242A8533BULL, 0x3A9CBC0B1689FDF8ULL, 
            0x59AA7987A047A445ULL, 0x465FC859FC73BE58ULL, 0x63C85D02862933E7ULL, 0x01145ED4D22F6E6BULL, 
            0xE1680D96926BACD7ULL, 0x4893D9EF068ECE03ULL, 0x4A443103AC030743ULL, 0x90ED2AC8FCED96F7ULL, 
            0x25D9397FB7A041F3ULL, 0x0A02F200237C81FCULL, 0xAB03529C008A62BDULL, 0x1AA1A8CC5523D966ULL, 
            0x3E99C2F3284EC489ULL, 0x8633A4AD5CFED390ULL, 0xB1CDD46E296F09BBULL, 0x48F124F89338BDBDULL, 
            0x13E5804367FB2833ULL, 0x6CEF9537374C6BCDULL, 0x564D4F6F5125C58DULL, 0xA55FF052C407BBCDULL
        },
        {
            0xB1BDEE25C0566A96ULL, 0x28ADD77415FD5549ULL, 0x7C6BADC177740407ULL, 0xE1418BBD8B7ADF1FULL, 
            0x9BCF32B635DBF66EULL, 0x99EADDDAC5CA8D60ULL, 0xF66B5F91EC999942ULL, 0xD13085B77DB762FAULL, 
            0x91B7D905DF5200CEULL, 0x74667E721E5467EBULL, 0xEBBC2E5A0AF8A487ULL, 0xFFC32E3D312192D3ULL, 
            0x3DFD3BB0EC6B8D0DULL, 0xCB3BBA774E23D539ULL, 0x5E60BFF9F28DE732ULL, 0x1190B96500247BA4ULL, 
            0x1BEF80A3F6711762ULL, 0x724862271C61A336ULL, 0x725C279A0104C9E1ULL, 0xCC890E8AE6DFD363ULL, 
            0xB1D179379B60E20AULL, 0xF1D10B394647986BULL, 0xEB0DB89FBB5F6C1DULL, 0xCCD4CE7043E3D93CULL, 
            0xFCA2F22D788CA740ULL, 0xBA674BF01FF39679ULL, 0x8D7852630CC74FEFULL, 0x77CB18B7FE2C87A8ULL, 
            0x5D7BF88999E8CFEAULL, 0x0868DB5406BF6D09ULL, 0xC6E687252F7B730FULL, 0x43A0B691CE898E0CULL
        }
    },
    {
        {
            0x80D8DE43C10C4C4BULL, 0x8D5B5FD0F157F99DULL, 0x59FCC906186EC7F5ULL, 0x6A31799B3121292BULL, 
            0xFD9C1D5333428B48ULL, 0xDE6BE7F08BDA64E5ULL, 0x73CD98DEFD0F84F8ULL, 0xEF099502488D1443ULL, 
            0x26E0D82F69C2A7E1ULL, 0x9E5E20C448087D69ULL, 0xEA2B2F3D11F3CD19ULL, 0x7B00AD92D16387FBULL, 
            0x8B0F166B5CA019A9ULL, 0xA8410F7F3719CECEULL, 0x46C1391E44997250ULL, 0x351926EE6B2DED63ULL, 
            0xDB42E8B4607393F6ULL, 0x90245A1960BC75D0ULL, 0x0CD84B0C3845B2EEULL, 0x4E1979F2AA7DD52CULL, 
            0x72D16F2A4507BD36ULL, 0x107FF6CD30591346ULL, 0x1BFDCCF1FE322E6AULL, 0xD121BAEF7D079ABAULL, 
            0x5267DC384A0946ACULL, 0x21BACB86429FDE01ULL, 0x211BAFE314B47528ULL, 0x39EF3563A04F8157ULL, 
            0x82114AF11E02FE51ULL, 0xA4A6E68368BBDD34ULL, 0x1F006004A483A550ULL, 0x4B7BB918880105D0ULL
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
            0xF6B27DC1F4BDE221ULL, 0xEC8C1C2C8D9A83C5ULL, 0xF7BC7A40B8E92C6FULL, 0x715BC5CADDA594E1ULL, 
            0x61C478C3EE21DD2DULL, 0x7F90DE3280AC4A3CULL, 0xB0166EBDD512464BULL, 0x7538AC87A3887609ULL, 
            0x90472B218CDBEB9BULL, 0x903E3AB3F4461662ULL, 0xF1E569C6096AA94AULL, 0xAF81C4725AAC1D9BULL, 
            0xB2C1E68981F7B2A8ULL, 0x17A69D9A431F0FAAULL, 0x2604126CB817B32DULL, 0xE1745DCAB50B79FFULL, 
            0xC57921C4752BBE99ULL, 0xCF84B3E98FD64127ULL, 0x79ED32440C315281ULL, 0x68384200725AAF5DULL, 
            0xD98515D2B1A971A0ULL, 0xCE9A9406631D1BE9ULL, 0x8EAA16B377111AEFULL, 0xB894DFD8C4E8156FULL, 
            0x42B8F84CB24570EDULL, 0x6EF006822BF05345ULL, 0x9ED381A367F3E42DULL, 0xF55C027DF6477E81ULL, 
            0x1883B1595C6FFA89ULL, 0xCD051207C3B48FE4ULL, 0x64657EF2B57C1F00ULL, 0x61DD66256D6346F4ULL
        },
        {
            0xDE0AA6BD6D4D8361ULL, 0x6D3C0FC4060055B5ULL, 0xDD79783430BA09FAULL, 0x332C01F5A7AFAD12ULL, 
            0xA051F55AA82B62B2ULL, 0x2D29FC723157CB61ULL, 0x8ADBD98E7A8E7B3DULL, 0x3ED932F27089DC17ULL, 
            0x5DDD06ECFAC5F1B1ULL, 0x85647442F9AF42ADULL, 0xAD651D2F7503BEFBULL, 0x8203730C365C03C2ULL, 
            0xEBAC8647830C00C8ULL, 0x25257D50973225DCULL, 0x074CF37AF5C01132ULL, 0x1A9EF543486F2926ULL, 
            0x686DAF0F86171DF3ULL, 0xFDE62DCD1FBCEF30ULL, 0x7557A3C9017DE56AULL, 0x1296C79DF6DEFAE1ULL, 
            0x220A3CABBAFB4623ULL, 0xC2A65FE42B10EC9AULL, 0x78F029DB94E3E9FAULL, 0x912CB5A2ADEF5388ULL, 
            0xC5E0B520CABC0CF5ULL, 0xF6432C4BE1B285F7ULL, 0xF83D2C23715A91B4ULL, 0x2DD1C5921C13C377ULL, 
            0x85C0E214AB2609BCULL, 0xE2274623DDE251B4ULL, 0x1046F7317991335EULL, 0xBAA38C5151596B9EULL
        },
        {
            0xCB218112D8902AEBULL, 0x6F8332415D4F555FULL, 0xB475227906A230A4ULL, 0x587C709B045A632FULL, 
            0xC33076772109B1A3ULL, 0xBF9135C8B4121E6DULL, 0x771C4AC000C6DC43ULL, 0xEDA75B66511CB0C0ULL, 
            0xC87C9BBAB687320FULL, 0x7C95578FFB1902C2ULL, 0x131618E622E38AA7ULL, 0xD5527383F360A836ULL, 
            0x93B8D8157D653DA5ULL, 0x0ABC0D4BDF0498C5ULL, 0x7310BFFFF522068DULL, 0xD6ED72CED6B45CCFULL, 
            0x2B0AC46EC6A3BE20ULL, 0xB1FBDAA1424E7E52ULL, 0x75C27A4AA812228EULL, 0xD188F0B793B22584ULL, 
            0x653A55B5A6FE73A1ULL, 0xC8B4598F327F2734ULL, 0x325FED5BE207FD4AULL, 0xBEFE4008231E9CE8ULL, 
            0xA8A58F2CF3D836AAULL, 0xBCD86B4BC6C94A69ULL, 0xD276DDA49D3DC201ULL, 0x316615AEF0D34A22ULL, 
            0x4E5DEE6173706268ULL, 0xFE92332FF4AFB6FCULL, 0x1B4D6E91E5C1DEACULL, 0xBB3D7B4FF084C456ULL
        },
        {
            0xE03EDA0D1CEB89D5ULL, 0x26BEAEE6AD4CACEFULL, 0x76EB51F6931DBE68ULL, 0x85997CF6191FD5B2ULL, 
            0xF795D67883D0C99EULL, 0xC11B71B71C1ECC1FULL, 0xBB5BC205118F8C62ULL, 0x7EB6F4C6FAF0CDE8ULL, 
            0xABF769F6249084ECULL, 0xBC4D0C2C4C425849ULL, 0x9671D13C3203C38DULL, 0x454F2ABD0FA3EDFFULL, 
            0xBCACFAD82129D9F7ULL, 0x76C7611F7DA586EDULL, 0xCC73461979AB59DEULL, 0x6E2F42890F36B4ABULL, 
            0x0ADBF3F8289D588BULL, 0x39E9AF2043D356DFULL, 0x63FEC2236F4D53D5ULL, 0x44829C81500E6C00ULL, 
            0x0D9543F2EF3EE480ULL, 0x4D18E45D1ACFB282ULL, 0x95DA9BF22B3F4803ULL, 0xA6D7632AB0FCFEA0ULL, 
            0xDC4D90FF1C047D4AULL, 0xC2851A230AA6583EULL, 0x8535404DB4EBD516ULL, 0x7654AB77EFCCBDC9ULL, 
            0x0160ED572B834D6EULL, 0x6B9251A5BC084661ULL, 0x7B72C3658A40BAFAULL, 0x7300B45D2AF5DE42ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Antares::kPhaseAConstants = {
    0x9351C3046642267BULL,
    0xAE4CD130FBD95FA8ULL,
    0xCA059683E05B8143ULL,
    0x9351C3046642267BULL,
    0xAE4CD130FBD95FA8ULL,
    0xCA059683E05B8143ULL,
    0xB2DFF2EF75706BF1ULL,
    0xD1BC407A215BA48AULL,
    0x91,
    0xD6,
    0xE6,
    0x3B,
    0xD0,
    0xD4,
    0xA3,
    0x8A
};

const TwistDomainSaltSet TwistExpander_Antares::kPhaseBSalts = {
    {
        {
            0xE3D2CF54FCC6A414ULL, 0xAF08D39AE6D46208ULL, 0x420D1758D570838CULL, 0xAB0877BC1E4F1F90ULL, 
            0xD0A0C5873AE7AC26ULL, 0x8BC335C3E862661FULL, 0x9590017EED759358ULL, 0x38FFEBB6EED73B7CULL, 
            0xE1F3860030134582ULL, 0x678F8AD74C967BCDULL, 0xB7B30D9DF34FAD6BULL, 0xDB031F2013ED6435ULL, 
            0x0BFD33824505A801ULL, 0xC1908E19E947EF44ULL, 0x7A74433BB0FBB9B5ULL, 0xFD3F830519A62800ULL, 
            0xFBB2FCD4F1F3C8F8ULL, 0xE4DD1FD3C18ED822ULL, 0xE7B663C6CBB5ABFDULL, 0xA93F918A2815EE19ULL, 
            0x65DA8554266ED802ULL, 0x6ABC358EB995223BULL, 0x14741AFFB30C0933ULL, 0x78E6F6355A14701CULL, 
            0x4F1CF38AF53BB621ULL, 0xDE15E525C691E45EULL, 0x3DF7D69773ABCD0DULL, 0xEAC12EAA9DF1EBFBULL, 
            0x890F59EB06997B57ULL, 0xEB47E382BAA2ED88ULL, 0x5B0106E360FAFD2DULL, 0xB306ECAF3C10BEACULL
        },
        {
            0xCA98B29274748794ULL, 0x2ADF74EC3B45B3AAULL, 0x810F718A0FD5F157ULL, 0xA623CC8E4315DC81ULL, 
            0x07B2FD59CD630D62ULL, 0x3E4D9AD60F40F517ULL, 0x5E3CF74F85833D4FULL, 0x028BC0A8076F28FFULL, 
            0x88EC8EC844B4A73EULL, 0x7E381764E7315C42ULL, 0x0EED466914837FFFULL, 0x5EAE083D0043CF43ULL, 
            0xEAB23AE80242D4ACULL, 0xDB4CCBEFA66391ADULL, 0x3C87E534C644784FULL, 0x230F0D776AE68367ULL, 
            0xFC3D2A5EC0ED4300ULL, 0xF9A739C96311ADF9ULL, 0x88D32A39A9467BF7ULL, 0x5C32ADD6C7F44158ULL, 
            0xFAF033E68A0FB01BULL, 0x8F18567986D263CDULL, 0x1168AB632153608CULL, 0xD50828BE872D05CBULL, 
            0xB2A5E7E34C9141EBULL, 0xD04F3C9E4A4C79A3ULL, 0x65A162E01C191920ULL, 0xF738BCA176DCCAA1ULL, 
            0xBD88E7942F3EE8EBULL, 0xC37045A576B9FDFBULL, 0xB4984FEBD4A5303FULL, 0x072F0B2CF556BC60ULL
        },
        {
            0x8D5281C42ED18508ULL, 0x41E160A6A3688923ULL, 0x4A8391D12BCCD044ULL, 0x827772D520865A9EULL, 
            0x5823392EB03393FFULL, 0x9D1E67B04E4F8D12ULL, 0xCE50BCAA9150A193ULL, 0xF9B20B8142D23E06ULL, 
            0x09BFCD916A06B69AULL, 0x9696230088C2C54FULL, 0xE84AE1067398F28DULL, 0xCF963B94B423FD94ULL, 
            0xFAFF7F03C82ABB7AULL, 0xFB47FAEDA29F82F8ULL, 0x719EE25F3B1C5A8FULL, 0xD3C0724448D66F3DULL, 
            0x5D4F79C56FE1D51DULL, 0xAB149409AB0A3EEEULL, 0x3919B8AAFF2A7C35ULL, 0x81BBEB9D55CB2791ULL, 
            0xF06354B47A7FD9FDULL, 0x786C92DD3B7088D1ULL, 0xE6F59F907B135E4BULL, 0x17EFAEAC1D79C017ULL, 
            0x19F100E4DADEE911ULL, 0x186898EFD93616B9ULL, 0x5D57954943809EA9ULL, 0x51993C34B9759FF4ULL, 
            0x84E8F8AC7B96B302ULL, 0x2915B022E1D35F7BULL, 0x91B52A0AE9A22E85ULL, 0x1A4D352310D8FD8AULL
        },
        {
            0x1FB755858BBCD65CULL, 0x2A68177F3C45D071ULL, 0x0242AE63BBD3FF53ULL, 0x0E5F872D8DC94E32ULL, 
            0xF04993A233468699ULL, 0x546DED4E1B9BF0A6ULL, 0x48A14C5B661758D7ULL, 0x6127E572993A2DF9ULL, 
            0x593CDD733228C8E7ULL, 0x0D8B91C7FC59CD75ULL, 0x22CD719958F1DE12ULL, 0xD00EEB00AE139B5CULL, 
            0x2CFC118356ECE478ULL, 0x089A7DF7DE740D01ULL, 0xFC14570FAB0A23A2ULL, 0x906D725B7C0A7CA4ULL, 
            0xC223E5307FEA82AFULL, 0x5E901AC321A55C71ULL, 0x8A26E8AE29A001C3ULL, 0xF1239A20701DCA45ULL, 
            0x93D3019AFD4ADB41ULL, 0x4EC6A132C206C2C6ULL, 0x3395408925AE4765ULL, 0x173158E4C5C4FA04ULL, 
            0x79293E84D040D7CBULL, 0x6970EF574BD01FDAULL, 0x345D3EAF4D8EFA95ULL, 0x06428AFA688376F5ULL, 
            0x70EC295088379F2FULL, 0xC9C42C7CC3AC99BBULL, 0x74355809B51C6885ULL, 0xECBC28BA25A97B87ULL
        },
        {
            0x8881808B0DE6F607ULL, 0xA7A231F3935494BFULL, 0x69DCF5F2D0AB314FULL, 0x009355685751E63DULL, 
            0x05BB6DDA374CD2FFULL, 0xE67F014D67EC16BBULL, 0xAD2A895906B91DF5ULL, 0x0D3D7282A9AF6C92ULL, 
            0x44BFD02D0598C352ULL, 0xB2CC897EC65E1265ULL, 0x5F6282A61C30169EULL, 0xAF869DB21904EBB8ULL, 
            0x259D2F636ACE1CF8ULL, 0x486C0B00E602CE3FULL, 0x9A429D1A16CC519EULL, 0xE7A8A4E46406E02DULL, 
            0x68E94945B4431485ULL, 0xDD461EDC8F4608BDULL, 0x2FC54A96CB4850F3ULL, 0xEDF974AA57DC1C23ULL, 
            0x39231B81A1305E7BULL, 0x138A3F6B1EDAEBEEULL, 0x3269E606A368141DULL, 0x0B39F0ABFD4E9C37ULL, 
            0x14046B39235FA2C5ULL, 0x2DF9B276614D9BA2ULL, 0x2F8EC9010050AF3CULL, 0x1583957361B783B1ULL, 
            0xD50FF04857BE374CULL, 0x461F8897A8BB7F86ULL, 0x5F6F78257119C490ULL, 0x051A1950579F98FCULL
        },
        {
            0x7D7C8AEE0D4A26D4ULL, 0x529255D914664FA4ULL, 0xE22618CA3F3441D7ULL, 0x451BF7A5246DA2D8ULL, 
            0x24CD27A962E5908CULL, 0xFE5B2036AEAD850EULL, 0x24A7FDCA9E56481EULL, 0x0CB83F4B4FFDFB1EULL, 
            0x413CBC35F5A9F128ULL, 0x8EEB797D45AFC558ULL, 0xA4AFC3D3DF260592ULL, 0xD38A29279411A9D0ULL, 
            0xF63B96672A87414BULL, 0xBD259E7EF82B2599ULL, 0xED4796402CB5DD80ULL, 0x8370FE22521ED752ULL, 
            0xC6A02F84E642D582ULL, 0x43D81214A45F12B5ULL, 0xF9EDC829C9045EA8ULL, 0xB035A92114056973ULL, 
            0x7BE5A56871E1F64CULL, 0x11E517C37459B1B8ULL, 0xAE369B1A29265AB8ULL, 0xD38E62C82662AE60ULL, 
            0x98041DA85E6D90D5ULL, 0x1BFF6E773CC7A95CULL, 0x904396B3158D3204ULL, 0x6B43FFA46E6B185EULL, 
            0x5586A7CF37EF9E35ULL, 0xCE58D44C6D80EECAULL, 0xD1FBD5F01D2F57A8ULL, 0x6A574E57984E9FDBULL
        }
    },
    {
        {
            0xBF93C7F78F6F9D8BULL, 0x282F9882DDD9916AULL, 0x7DD4D6FB5F66BCB6ULL, 0xF8FBFBCED124C90FULL, 
            0x90F5A37B2269F59EULL, 0x9EB6456EEBDC008BULL, 0xC1D4AB95EC300A45ULL, 0x6000A8CCD476DA50ULL, 
            0x2EEAD691BB1AD6F3ULL, 0x4B0DCF9FEA05A842ULL, 0xDD6B5FB9700EC586ULL, 0xCBDF3ED0E20A0389ULL, 
            0x19F06EA9FFD8DE91ULL, 0x208389FEF2455DDBULL, 0xF223DCFB3581F95EULL, 0x30DDB57CED0C4D47ULL, 
            0xE669A2BFF0A2734CULL, 0x861F7FA452B884A8ULL, 0xC466569B63787EEEULL, 0xF65B5C0EE5A2E30DULL, 
            0x0194CB7746173EC8ULL, 0xCBEA2C5323A6DFBAULL, 0xC66A7830BB8095E2ULL, 0x001E747D3126F925ULL, 
            0xBDB821630062D9DDULL, 0x724B35B354986553ULL, 0x3A333C3318E65427ULL, 0xDA61CF1AEE161130ULL, 
            0x4D7DC046CA0EF1A2ULL, 0xF86F0C0ED39B1E4FULL, 0x1EB4C5287003C8B8ULL, 0xDAB979959EBAA883ULL
        },
        {
            0x363F380B3B61DC48ULL, 0x65F4D98EF2995D5CULL, 0x08860FA69FE654B8ULL, 0xF9B7AB6F89043797ULL, 
            0x8327A2573E517954ULL, 0x2BFD1672CDA2A8E0ULL, 0x040572A1094D7FEDULL, 0x2DA3E17B20EE8502ULL, 
            0x04778AFF8B01BB67ULL, 0xB6DEB3FC5271A216ULL, 0x955CA4495B4447AFULL, 0x47B8DB89E793070EULL, 
            0x033FADE9BEDBE863ULL, 0xAB5D6C6417F287C9ULL, 0x425F25570A4F7298ULL, 0x16F3D55CDAEFB4A1ULL, 
            0x0CDB90F3DEB5A4A4ULL, 0x4D77C704CB2CA2E9ULL, 0x318559E97429D3E1ULL, 0x76828636A976805BULL, 
            0x22315D532EB25713ULL, 0x019F2C7D970E7837ULL, 0x1A6CF2084F84BECBULL, 0x966DF1AE2D8FDC8DULL, 
            0x6DA936DC2DADD968ULL, 0x5AE5FAC2138A6F17ULL, 0x0A27FD9899D15E7BULL, 0xAF3F6F6EA1975F90ULL, 
            0xA74F3A4DF8A442F8ULL, 0x1420477285F6D176ULL, 0x1BD1ACB1638999ABULL, 0xD17B48ADCD291262ULL
        },
        {
            0x7FA0FA1530974CF8ULL, 0x4DA80046F4373A12ULL, 0x50AC0631C6BBF25BULL, 0x5DE8BC001BC20EA2ULL, 
            0x869612E8F7797E68ULL, 0xDD4EA0C75E32ADD5ULL, 0xB8138779B1FD3B51ULL, 0xE4B53A1749F6E805ULL, 
            0x94771F4F28606FA4ULL, 0x380F34D11122A5D3ULL, 0x45F9F42FAE1F67F0ULL, 0x3F69915D8780F96BULL, 
            0x57F74F3001F0FB49ULL, 0xFB53F6B3F1444772ULL, 0xBAC8C85D5D56C99CULL, 0xCF8C296042F14D40ULL, 
            0x43AE1A642D2D5C78ULL, 0x71D58D5D6348E2D9ULL, 0xA6BD13798884F9FEULL, 0x5DB4C1ED9DD35217ULL, 
            0x4E41C4AA11103072ULL, 0x1AB418F8C7B11A0FULL, 0x6238E3CC838C142DULL, 0x113F35FD52CACC9CULL, 
            0x252D2DA9DFB8BDCEULL, 0x9341C9DF60ADFE96ULL, 0xD71435481773DB3DULL, 0xE43246AC71A4CDE5ULL, 
            0xB667F16D87B317E0ULL, 0x16BCCE5551E33508ULL, 0xEB2BD681B975ABDDULL, 0xA299432FE7B4D306ULL
        },
        {
            0xDF7FBA83149F8D1AULL, 0x7B117ADBA3B2B992ULL, 0xC2AEB0558393957AULL, 0x7B2AD582D0ACD881ULL, 
            0x16AF068A1064D6F7ULL, 0xA641AB428DA0275CULL, 0x33D40E54C0F54A35ULL, 0xF3EB4B8BA93FC1D0ULL, 
            0x2039542C122B00A4ULL, 0xCE270EC813E648D0ULL, 0x4B3E09FF61B7B720ULL, 0xD5436533476A4AD8ULL, 
            0x44C51C0052E277ADULL, 0x40E3F257103C5D37ULL, 0x6FEB5DAF2E5B70A5ULL, 0x3FC402D6464ADB31ULL, 
            0xA78D31843ABC8EB4ULL, 0x3CF78227C45A7775ULL, 0x0681C5E58F30B032ULL, 0x48EB42C6FEC82B37ULL, 
            0x0AB580D75E52C5E7ULL, 0xE1EF3DA2ABE0E6A6ULL, 0x823BA8CB70ADB282ULL, 0x9F08D7A629D0C877ULL, 
            0xA8F31D381469D8C3ULL, 0x6607884CEE8A719FULL, 0x383FEE81F6141526ULL, 0xE546D2E58C4173EFULL, 
            0x8C89B85054D2F76FULL, 0x6E10EB261753C766ULL, 0x1BEBB5492877427EULL, 0x371D36A7B53402CFULL
        },
        {
            0xE878FEC962AF7864ULL, 0x2989F8B0741322FFULL, 0xD45B5980B599634CULL, 0xD9505A6B4B930958ULL, 
            0xD9AF6315AF0138DAULL, 0x5E9AD34435F5523BULL, 0x65ECBC0118C4A0FFULL, 0x91C293BE8775621AULL, 
            0xF484815B694DE90DULL, 0xBB76D83D08962768ULL, 0xA7FC47F00911F394ULL, 0x55E89AE6A90ADE97ULL, 
            0xFD1C3E980E61A7A3ULL, 0xE86ACE14C2EEE375ULL, 0x57381F937874908FULL, 0xBA01BAC755F6EA21ULL, 
            0x0227B6DF1A2F920DULL, 0x99885651466B8F27ULL, 0x2CA1665811D7315BULL, 0x84F6A9C20C6517CBULL, 
            0x44356A8792233F39ULL, 0xC2C4887489F61700ULL, 0xE16E033B885A634AULL, 0xF23FF3FD73CB6BC4ULL, 
            0x7E57D9F3F47651DAULL, 0x3D6200B0FAB79A0EULL, 0x27212BD3A5846E26ULL, 0xFC24E257F5236951ULL, 
            0x8D547C35AC672824ULL, 0xC4974C6102816AAFULL, 0xC7055EDA69179721ULL, 0x1804F109FDBCCBE4ULL
        },
        {
            0xCAFB0A22FA512041ULL, 0xC6FDAC9DF324F386ULL, 0x3C6C308332ACDB45ULL, 0xFFB007D105073242ULL, 
            0x4166C8573FB79B85ULL, 0x25E5F4585DF8925BULL, 0x888B40FB9FDCB8F7ULL, 0x5245FAE3C0CD5049ULL, 
            0x8DC8475F5433C6CEULL, 0x52F43E663F7B99E2ULL, 0xC170FB0CF191EA9FULL, 0xCF739CEB0EC29D1FULL, 
            0xBFBA2A69D3785D99ULL, 0xBA09BCAD7F4345F6ULL, 0x5475FDF61D667EBFULL, 0x66613DE0BD8E835EULL, 
            0x9430103E4FC01E2AULL, 0xC262B8A2B3A417BDULL, 0x8B5B0DD44DEA9C7CULL, 0xBE5D38C32CAE41E5ULL, 
            0xAF931F41A58A01F1ULL, 0xF7C31A864BB684E5ULL, 0x677C8955F90716BFULL, 0x183BA9D179F98FE7ULL, 
            0xE965FEF2C568EBBAULL, 0x437FB95A492CB354ULL, 0x38BE309882018396ULL, 0xCBBBC5463F87E9D6ULL, 
            0xE0E6DBA694F81E86ULL, 0xDCC410B24AE03B20ULL, 0x55DE1A24B6CA7BACULL, 0xC360773F160B151BULL
        }
    },
    {
        {
            0x4E9CC76AC4D4D1D8ULL, 0x1F83501CDB05EA67ULL, 0xE6337B01D818FEB7ULL, 0x0B0E9EFFBA21C074ULL, 
            0x957D16F7F3000247ULL, 0x68AA8B6D94BD6D89ULL, 0x80670DC3EC167841ULL, 0x95169232C39E35CBULL, 
            0x94733923B98BC3F6ULL, 0x29B2AADCD6349869ULL, 0x16558D4325A2FDC2ULL, 0x760488A9FA7FA73CULL, 
            0x5B134A024E2517A6ULL, 0xDFCAB8D64D448AADULL, 0x48196D67D8301A59ULL, 0x6C319155C0E1A1A5ULL, 
            0xFAE4E5ECD082327CULL, 0xBCE93BB07A1E1F79ULL, 0x0B7338F8030B196CULL, 0x95DEB61912D1283EULL, 
            0x727837CB2ED363E3ULL, 0x46121163CBE525D0ULL, 0x9D258C91315CCC88ULL, 0x109275872A4DC3F6ULL, 
            0xD1DBE585FBC2C80EULL, 0xE74058661B217BFDULL, 0xA28F882F3DF67FEFULL, 0xF82D917A861121D4ULL, 
            0x206E965C8592E7E9ULL, 0x362A3D0D265AAD05ULL, 0xFBCFAFADE647D790ULL, 0x578BD3FF64D39F0FULL
        },
        {
            0x9101C61910F95471ULL, 0xCA6EBF4FA1B8D85FULL, 0xBB8705452CE2FDF8ULL, 0x9EF5EC0FE0F0D51DULL, 
            0xED53AA724ACE0707ULL, 0x121F479FAEB22104ULL, 0xE851E8609305DB8CULL, 0xEE29CE84FECCB6F7ULL, 
            0xD0A78991787E6973ULL, 0x2DDC24BFBA77DEE0ULL, 0xA84723515EDF2497ULL, 0x93F298B4DC3D05CEULL, 
            0x56DD4CE879BA4DDFULL, 0x14A2F12834B7C3E6ULL, 0x7933ECA93FC27566ULL, 0x9174DADCBC461FE8ULL, 
            0x2B0DFBDDFD90D6C4ULL, 0xA23ABA1D36960DE9ULL, 0x3A9DF281BC50378BULL, 0xC4448C9C393852F5ULL, 
            0x887EED97074C49C2ULL, 0x4F057AAEA8700A56ULL, 0x79D34AD37F538303ULL, 0x0CE233784B4473D6ULL, 
            0xE9C3D5E4604093DBULL, 0x28121C0B03CE2DC2ULL, 0xF80A201AD6803754ULL, 0x392C47558D2C0CB1ULL, 
            0x1A43C83264D29164ULL, 0xAD44C8B3DBD31D0BULL, 0xF305992D571B6CDFULL, 0xCF27966C973BB84AULL
        },
        {
            0x019E0B5D2A138121ULL, 0xB3FD3870E483D5DDULL, 0x65288C3096BD5CF7ULL, 0xA1AD5EB29CAB54F4ULL, 
            0x3E7E22C061E19D05ULL, 0xBEE40A6EDBD5E58FULL, 0x4898E29D6F39567FULL, 0x188DCC7B0C8B628FULL, 
            0x7339BCA375BC5B33ULL, 0xA3B8F973CA12E887ULL, 0xAA80C339F912F05BULL, 0x753F66D7882A2FA0ULL, 
            0x979216AF6C8B9BABULL, 0xEF0C3B352B3AB6A3ULL, 0x563A59CB84A7A0DBULL, 0x4952632248BCAF5CULL, 
            0x943B8F4E276E252CULL, 0x0D861350BA633937ULL, 0x2E172AD844C9A834ULL, 0x99AD3A6F812DB1B6ULL, 
            0x77F29257776DD539ULL, 0xAB89B4297CB3AAC8ULL, 0xDC3360188C838983ULL, 0xC28C445CD0F0D694ULL, 
            0xADB84EEE0E758EE2ULL, 0x203FBB0522B62C36ULL, 0xE934BF16AEDBD0E2ULL, 0xF8E54921DE659AB5ULL, 
            0xCC621769531FBD0DULL, 0x90631C7CB432D518ULL, 0x0E518EC53F18A57BULL, 0x9571D64FF19016A5ULL
        },
        {
            0xAFB20D03E0D14E96ULL, 0xB38BC6494DCAD131ULL, 0x9290E8BBAA0EA29CULL, 0xB13665F9C17468D5ULL, 
            0xA652EAE956C9D076ULL, 0x5C097386E70A094BULL, 0x9098D3B84B512A35ULL, 0x07AC75DCDB273C24ULL, 
            0x608F7AAB822F03F0ULL, 0x9F71CD1B4256FC6AULL, 0x83E2FA7A18880B19ULL, 0x71B02F7AD0A28459ULL, 
            0x9B3027C68B816B49ULL, 0x8238C48516152BA6ULL, 0x3D0095A1FB1CACF5ULL, 0x6E8F407B815C7992ULL, 
            0x576A8D3CF16AA052ULL, 0x570E1AE74AFD0CE0ULL, 0x50C3AE5FFBB269BEULL, 0x94DEBFE53136F25FULL, 
            0x2441B04A2B307324ULL, 0x371BAFCDA91B6221ULL, 0xD97199F576F16592ULL, 0x1E1DC9B24DC40E8BULL, 
            0x86C2435985ADEB91ULL, 0xFE51BE6448F1B8D0ULL, 0x16977D74D7BA1AE0ULL, 0x7587CD484D84117AULL, 
            0x1BB6479AB3CBB334ULL, 0x5B1FA94196416B7EULL, 0xD073DCA7D56240F5ULL, 0x7A725605FDACF1ADULL
        },
        {
            0x1833683043D3093DULL, 0xE446C237762116C0ULL, 0xA5CBA4B63C0C143DULL, 0xF18B0D88C59D5B58ULL, 
            0xA22B1D432ADCCEEFULL, 0x88DD02F8B4544650ULL, 0xB1859F59A485477EULL, 0xC2E5844674BB961CULL, 
            0xA2B954CC2103DD11ULL, 0x640B66BB38673E7AULL, 0x27621398EA42E60AULL, 0x259780256D76E9FCULL, 
            0x93F49E23ACC18933ULL, 0x1A2993EB8F276671ULL, 0xA94DE2844EB71249ULL, 0xCE41E2B784E55841ULL, 
            0x2D85ABE523F6D955ULL, 0xAEE7C11D6A2969A1ULL, 0x02D9BA3B01D0D82EULL, 0x8C3310CC8CC8DD54ULL, 
            0x400EA9959C52877BULL, 0x68BD6831AFD05DF8ULL, 0x6D3235129996ABEEULL, 0x854F78EC9F665791ULL, 
            0x97483267168CF654ULL, 0x966F94D54976A3BEULL, 0x2A0D56E35834439CULL, 0x64782B31F6F8D257ULL, 
            0xF22E72053EFFC819ULL, 0x3F098EF6E7E34A8DULL, 0xF8063770DD42E987ULL, 0xF34ECEDA985E412DULL
        },
        {
            0x56387198C43C993FULL, 0xDEC40E0906ADBAB2ULL, 0x3DD067D9F60F1F01ULL, 0xA89602C2B91A62FBULL, 
            0xA49350BB1DE246AEULL, 0x35A0B9452799E88BULL, 0x214749760DD1ED7BULL, 0x202BA025CFC2B567ULL, 
            0x8D662F88A3DB44B4ULL, 0x21323B533449A995ULL, 0xFF049BB06CDE61A4ULL, 0x75E6E9BC0608CF08ULL, 
            0xB6EB085AAA4422C1ULL, 0xF463AA8870300795ULL, 0xBF53427A166B4C66ULL, 0xACA3C1B7AB17FBB2ULL, 
            0x7E525CB60B4F2B82ULL, 0x7A866188FD2C5051ULL, 0xF104FC101837CCCBULL, 0xC79D389D11E59022ULL, 
            0xAE17345FD936E197ULL, 0x96295C90313FB061ULL, 0xD33942AF40E2379CULL, 0x375B1EA79F6EF7F6ULL, 
            0xD51E9950E7057A35ULL, 0x0AD4686A7DE34054ULL, 0xE21C05ECD40C6B15ULL, 0xC4B2B69824A45F13ULL, 
            0x7CE81233D4A5F95CULL, 0x8A753E959664CC75ULL, 0x95D64DF7735A5B9EULL, 0x28660E8B6D09912CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Antares::kPhaseBConstants = {
    0x807F1454F7171DF6ULL,
    0x2C5CB9DAFF7C260CULL,
    0x2BC1C6E3FB85E6D6ULL,
    0x807F1454F7171DF6ULL,
    0x2C5CB9DAFF7C260CULL,
    0x2BC1C6E3FB85E6D6ULL,
    0xDBC65E3347EB3D72ULL,
    0x25AD539D66C97A02ULL,
    0xB9,
    0x3F,
    0x77,
    0x17,
    0xA3,
    0xF3,
    0x1E,
    0x9E
};

const TwistDomainSaltSet TwistExpander_Antares::kPhaseCSalts = {
    {
        {
            0x081DE5BF330E5B93ULL, 0xF291AA62C30056F6ULL, 0x0410E721A4E2EDD2ULL, 0xFEB78C1899485799ULL, 
            0x1F2103613B171B85ULL, 0x6900A0E926AB0921ULL, 0x7F90F5AC8215EE48ULL, 0x1981B7FBAE68C850ULL, 
            0x0B1C7C5624EFD465ULL, 0x026D4E8E1DD709B5ULL, 0x1A4F9F817DAAFDCAULL, 0x92616FE226174A1BULL, 
            0xA3E29B6712D4307DULL, 0x091C241E533615E0ULL, 0xBCBF55577C294FE7ULL, 0x1DC384CB8BC07DB6ULL, 
            0x1B2D5E8A1C224A65ULL, 0x033004C3D9AAE9E6ULL, 0x393EBC7FD80B67C3ULL, 0x444AD59A33B02887ULL, 
            0x21F95E8E959F51D3ULL, 0x97A1EBAD6DECDA03ULL, 0x1F683F44E5B8B933ULL, 0x088E7C8200000ACEULL, 
            0xBAC496C63E607B2FULL, 0x9F53F750A412827BULL, 0x20C007B59FFFA7D1ULL, 0x10817AD347F6F451ULL, 
            0x7B4AE55098414CDBULL, 0x2520F617391654C6ULL, 0xD0EEA9076CB72864ULL, 0x3FDFAAF6C210B92EULL
        },
        {
            0xCB2DD8440F8E3938ULL, 0x01DB0249A511C022ULL, 0x60F8105112ADE6FBULL, 0x29B4C18E1697A7FAULL, 
            0xB8A5B1C976821002ULL, 0xBBB13C3575D7F48DULL, 0x6CFBDBC61D7D29B2ULL, 0x8674733B3764BA47ULL, 
            0x6F5B025CB79D20D9ULL, 0xF284E19787D9FD0FULL, 0xD16ACFDD8C44B291ULL, 0xCDDD11579E854B07ULL, 
            0x9F63866CDD5AAFC7ULL, 0xAF3E918EAE5A316BULL, 0x78086F423C9555E0ULL, 0xDF3261992F64480AULL, 
            0xD198F381487573A7ULL, 0x49E18562618D401CULL, 0xB8BE4FB7C29527D6ULL, 0x0D5F6F5BCE06F6E6ULL, 
            0xE989A5B2A5B7D556ULL, 0xC240AFADAC86FAF1ULL, 0x769D868EDDC74C1CULL, 0x5C7D87F9CC3BF0B3ULL, 
            0x82669F227A5303D9ULL, 0xEC8E490778051C30ULL, 0x40D1BFC648F9B4BCULL, 0xE71447670DA19FBCULL, 
            0x4165CA80940D6B2DULL, 0xA8EDFACF1B0FD8AEULL, 0x9723C40ACE44E718ULL, 0xAB14723D7493D742ULL
        },
        {
            0xAE14CD1171B5470CULL, 0x047EB270FB6C9CD1ULL, 0xE26A30BD34297EB6ULL, 0x12286AB4F9799F23ULL, 
            0x00B6D687FAD2FCC6ULL, 0x0DAB8FD34A6ADD45ULL, 0x005CBE5FB7A71AD8ULL, 0x1E8CC3E7575D7A6CULL, 
            0x4C749BECD314AC29ULL, 0x638E3C2FE664FF60ULL, 0xDF657E5FE2242E6CULL, 0x09FB51A13D59F87AULL, 
            0xDB07E0F9CB44BD0EULL, 0x1CD613B660682F99ULL, 0x3F3ECB207228AEEAULL, 0x06DDA5EC39BA4124ULL, 
            0x0472737A080DE3F0ULL, 0x46521BFE765CC81FULL, 0x2B8B9A69B048367CULL, 0x21CCD81D5A415C0AULL, 
            0xBBEDBCE117A1DBBDULL, 0x2F61F43E485F14B8ULL, 0x39E2AEDA5C73F822ULL, 0x36D75DDB1377D265ULL, 
            0xE23ABDB6D50A3A88ULL, 0xC213AF4B226B6720ULL, 0x2DDF41A8084EE091ULL, 0xBEDBADDA5DC35AC3ULL, 
            0x27AC2BD9BB1961C6ULL, 0x3F95A1DC90B11992ULL, 0xB798214987356453ULL, 0xD0AFD57CE7230C5BULL
        },
        {
            0x8BC37A5D8EB562B7ULL, 0x913DA4E4F770D12EULL, 0xE377CCC1E2B68055ULL, 0xDF17615669A23519ULL, 
            0x13ECDB2DEF06E8BEULL, 0x66B2CCA4A66418F4ULL, 0xC6DB042A4CE3E1B4ULL, 0xB94A08AD9870F68EULL, 
            0xFA33EFB905BCC650ULL, 0xE84F28050FFB8DF0ULL, 0x2EC3EDAFB7FC0F50ULL, 0x1355FBC983E23961ULL, 
            0x1FE4E55A656563B6ULL, 0x5198FAC8195A12B1ULL, 0x6199D38C102BB2B1ULL, 0x37F077C3DCA22710ULL, 
            0x100027282DB1DBDAULL, 0xA78FD9B1C118E8ACULL, 0x40120B410D6B7A30ULL, 0x6D35683E73015664ULL, 
            0x89385172DB73BF48ULL, 0xA07DA199A6E583FBULL, 0xE489B33D0B83395CULL, 0x08E9BBB459CC4EDAULL, 
            0x0201F15D6399EE00ULL, 0x700BA98BBD1B6FFEULL, 0x271186068DC7F425ULL, 0x4B1DACAF82A11D4FULL, 
            0xD6169CA1270170F0ULL, 0x1E5541A2B4033991ULL, 0x1C83B47EF7E7C149ULL, 0xAABAF4E9B90BC032ULL
        },
        {
            0x9D76DBE44C7F911DULL, 0x73B875FA5810E61FULL, 0x973BBDCFD1B6CAE1ULL, 0xA172496B26B7EF8FULL, 
            0x9F06966853ED038BULL, 0x57455AD7E11B6F7AULL, 0x269F7924211CF31AULL, 0x3478B003F3E59432ULL, 
            0xCAAE26957456AA54ULL, 0x7736702C81997F03ULL, 0x1E538609E3DDC1A8ULL, 0x558706D395E4E94EULL, 
            0x1B2089FA5422A5EDULL, 0x1EA0C7D9A33CE18DULL, 0x39754B9EB26A5351ULL, 0x77C0A0521732FBBAULL, 
            0xA2BE6EA5C08BF559ULL, 0x020F62EACA474ABCULL, 0xD346C4A838868A81ULL, 0x251ABA71B456A970ULL, 
            0xCEABFF7D2C4A4FCAULL, 0x37F5877DBB3EDEB9ULL, 0x32C198E03791B6CAULL, 0xC3749F972B3882BCULL, 
            0x319860FEFD32FC0AULL, 0x8C1D8D6410B4D33FULL, 0x076EF7D5CE2B08E5ULL, 0x6E1C79D698CD944CULL, 
            0x92BE76159EB29D71ULL, 0x6D1D4FE7B2469B3CULL, 0x4C372AEAC5989F32ULL, 0x6AD220819BB40BE4ULL
        },
        {
            0xADE17ED07FE8A5E5ULL, 0xE93B09CBD6C94401ULL, 0x3F9E9A7970CEABDEULL, 0x27D472C0BAB6E3A9ULL, 
            0x07A936B94882CC59ULL, 0x5CD950116761D9B6ULL, 0x2F025EB2420BF817ULL, 0xB62DBC273665DBF4ULL, 
            0x6F30FEBABE5E8EF7ULL, 0xD43555903D0DE135ULL, 0x45FFA142C1FB4B00ULL, 0xD14A9019D06701DAULL, 
            0x8C6EE459BEAF466BULL, 0xA59DFC1C745B1650ULL, 0xA1BA573EB4317929ULL, 0xE551F37EC02A4669ULL, 
            0xAEF6A660DA2572BFULL, 0x484DD94110B01FF0ULL, 0xA30615EAFFB49E92ULL, 0x9BE913A957D0BAB1ULL, 
            0xF6BE27FA4386CD4FULL, 0x3A8707397C241ED9ULL, 0x522A03C9A44B0AB9ULL, 0xA92CDD78D899B6B7ULL, 
            0x0415C36D37A720AEULL, 0xB015E7CF450524E0ULL, 0xC07C4578E2727DABULL, 0xB0F3665A0F94EFB6ULL, 
            0x22AEFC164BB743E6ULL, 0xFC58B193034D0988ULL, 0xBE2F15E9B55AA378ULL, 0xAF8745AE13827361ULL
        }
    },
    {
        {
            0x6C432F735C3B9D7EULL, 0x6346A7D01A4DC9AEULL, 0xC5640CBF36E95A4AULL, 0xAF05F3F83D059477ULL, 
            0xFF0F63A3BF1E8724ULL, 0x41E9B2B170D3E065ULL, 0xC732B706074E0461ULL, 0x7A6B10A11F77C5F4ULL, 
            0x112DA129E806F921ULL, 0xDF233C60D3C80995ULL, 0x3065850570B815C7ULL, 0x64AD974F4F31DD9AULL, 
            0x5286B2D11A269AE6ULL, 0xA4576070F2E207F6ULL, 0x4D3D7B03EDE5912EULL, 0xC870B82285D0E2CFULL, 
            0xA2A8E31E938B5423ULL, 0x2228885E6A0495C5ULL, 0xAB3523C972A10FBAULL, 0xE3FEEDD8989D716DULL, 
            0x896A6DD0EB0E43EFULL, 0xAEC6199FEA66B4CEULL, 0xEF8A09BDF6DA8620ULL, 0xDF0B1C5B376BFB81ULL, 
            0x7B6F8543C190A2EFULL, 0x108895D372142881ULL, 0xD3C3A331B0C76D57ULL, 0xCA95D1B17DC73C33ULL, 
            0xA4A626CF93F4C0FEULL, 0x72A7578AD42799B0ULL, 0x10490F44169699E6ULL, 0x1389DA12CCF43F5EULL
        },
        {
            0x94B4958589753083ULL, 0x83418386A3C8B018ULL, 0xAA5188F7A6557561ULL, 0x38CF0BB8D77C4F2CULL, 
            0x98CFB51CB6935833ULL, 0xD2D5E6E9C160C295ULL, 0xAB4166772C2B3A2CULL, 0x4C21552A5FA86AD8ULL, 
            0x101E69B2657D0203ULL, 0x73DD2FCBA2AB7EF1ULL, 0xDCF071B3C425D5BAULL, 0xEAD2080EC885A18FULL, 
            0x8F444E5AB8D97CA9ULL, 0x0B44A46ED8F2268AULL, 0x03C9920B824D5777ULL, 0x5DFB8079051D06C7ULL, 
            0x4E9DCDEE413DF2A6ULL, 0xDE28E926E87F4EAEULL, 0x92C55E21B8D7B776ULL, 0x6B08DB570569FF92ULL, 
            0xC6EC045624834B07ULL, 0xA2A9A10DEC780610ULL, 0xB58FD3D5A43B9A34ULL, 0xADD4799F22A893A1ULL, 
            0xC4362D05DBA42E98ULL, 0x1DF5666AC55DCD71ULL, 0x792C16DA1AAE2C87ULL, 0x2BEBD3529293580FULL, 
            0xC1E5F3551406172BULL, 0xFE721DAB08298D7DULL, 0x8A8944E6CB0520F7ULL, 0xA03A35ADB24092E3ULL
        },
        {
            0x7C3B0873C80AC017ULL, 0x5B34CAA00B526885ULL, 0x44BAE0F91300C6E7ULL, 0xF7DE19C1DEF491D9ULL, 
            0x687024399A27C31CULL, 0x17C4C35445362738ULL, 0x9A6CA56F979F39C4ULL, 0x358685CA64779806ULL, 
            0x3A51035FF6F314B4ULL, 0xB3667ECEDF250272ULL, 0x6185F2FAA789DAC8ULL, 0x921C21874D3A4CD7ULL, 
            0xC58C1BB0F63D0CC8ULL, 0xEA8D5E1CA6D0E3A2ULL, 0xEEA8FCFFEE6CAA3AULL, 0xA082D79047098A27ULL, 
            0x5A37114AAEC05EC9ULL, 0xFD1427EA2633A87FULL, 0x6C0646D324BF7EF7ULL, 0xA56C9284A0D09901ULL, 
            0x996EC577DD600550ULL, 0x5B033B727FD57762ULL, 0x35F50C8DF2BB8DD9ULL, 0xBFF9F968BF906EF8ULL, 
            0x722E67992BCF7438ULL, 0x353EA083A77A02B3ULL, 0xBAD0B403206698BFULL, 0x6E48271A0B31E706ULL, 
            0x4FFBD4F0350505CCULL, 0x8DE99024DD6636B8ULL, 0xB2EF995FFEE4AD9BULL, 0xA00976D0E05B892CULL
        },
        {
            0x6A8932C84DF8721DULL, 0x8ADAEE003E2A925FULL, 0xE0FF3F89A3303DA6ULL, 0x47198C5319328D6CULL, 
            0x78DF8A1DEE4D009AULL, 0x2561BDA972C2B51FULL, 0x57CF7A1275C1BECEULL, 0x4F997705186C264DULL, 
            0x213143211B64B42BULL, 0x86F0A1DF9A138FCCULL, 0x8CBDB9A0D2728013ULL, 0xF4EACA86BD4688F0ULL, 
            0xBC0F34E48EF68340ULL, 0xCF0694126ADCCD42ULL, 0x9EFAB88846A36BD1ULL, 0xD750CD418C20FA56ULL, 
            0x2AFC6475E4F70E2EULL, 0x62F8F4AC91390206ULL, 0x163C1E313F6CA325ULL, 0x7BCA392278F17948ULL, 
            0x6F93ABA3884F864DULL, 0x149825A0E0B62956ULL, 0xC18EB42EE9B5D086ULL, 0xB4C781BF9E8FC66CULL, 
            0x104EE70F6ACB6BA3ULL, 0xBEB5185D16AB68FBULL, 0xF35FF325FDEF559BULL, 0x32C413AF51EB5CE8ULL, 
            0xB2C502FFC2E03B3FULL, 0x5FC22333BE289ED4ULL, 0x61A34CC071A8DEADULL, 0x615220DDFBC4829CULL
        },
        {
            0x3E4A5D77FC95A76FULL, 0x44804D2F5126181CULL, 0xE0BD39057ACD8A5CULL, 0xA0B38392029A8238ULL, 
            0x77B48449AEFBC58DULL, 0x2FFC9C4841FA3064ULL, 0xABFBC62E02F25F19ULL, 0x0EA3E473B9F5D58BULL, 
            0xE9509EAED6DC245DULL, 0xC7FAA9CCC2450BA8ULL, 0x2479B43E6D495B95ULL, 0xD1E6D06E9186E513ULL, 
            0xCB491BA342DE24FEULL, 0x113D347F34B055F8ULL, 0xE03D0DE13C2875E6ULL, 0x031E749A0F1BB236ULL, 
            0x512B207E57195C09ULL, 0xC98DF9EDFD9C6F39ULL, 0x6EBC09BE29FA353EULL, 0xD6BD553117CFF0CFULL, 
            0xCC85D089C8467EB3ULL, 0x9643A0AE741F0058ULL, 0x06E8CADAACA4EC38ULL, 0x8123F1564ACD841CULL, 
            0x8331A761EB1E50E3ULL, 0xF159A6287C2773DDULL, 0x71EB942B484DD1F3ULL, 0xF4E3F62661F14FD8ULL, 
            0x0E43D5D547841367ULL, 0x20B5FFC89D03A2DDULL, 0x0BBD3EBEAC99921CULL, 0x363EC5DC83E2BDA1ULL
        },
        {
            0xF73EF4FA163942DFULL, 0x8A21A499E837B716ULL, 0x939DAE9BC44255DEULL, 0xF6022F8AF4CCCF94ULL, 
            0x3270C083C3EF0369ULL, 0xFC1B02EC66380DF7ULL, 0xEC989536ACEF5E5AULL, 0xBB3EA32554B9BC10ULL, 
            0x9FDF9F3FE8140C1EULL, 0x15728751AD6E4C9AULL, 0x308035932655D6D8ULL, 0x93A77E7031C572CFULL, 
            0xE215B4AD00315755ULL, 0x20D7C7759B38BB3CULL, 0x2EE4081C56B45A5BULL, 0x6CB28C95973755CBULL, 
            0xDC8C4679EE43CF60ULL, 0xB174FB0694E4470CULL, 0xBB8972A1C77C08EEULL, 0x985D6AC8EA76F5D8ULL, 
            0x01FB903C043873CEULL, 0x719A0335F47936E6ULL, 0xDF6185D717E88532ULL, 0x5FCBC462F788CCBEULL, 
            0x71CED61FA2F5012BULL, 0x702CA73631E4E412ULL, 0x464D19DEF122D07AULL, 0x0DCCF54474EAC98FULL, 
            0xEA4D5F7BF856C2CCULL, 0x787B285D9264CF53ULL, 0x25E33B53EB501227ULL, 0x58F9A24310DE6992ULL
        }
    },
    {
        {
            0xCDD9F6F781AFA3A7ULL, 0x2029ACE4F68793EBULL, 0xD936194DE99BC4FBULL, 0xE1025DBFD1D4FFECULL, 
            0x1275C90DC85598CDULL, 0x6131004B5192BB4AULL, 0xF0835E8605E0287FULL, 0x0865DBC5C1FE5F11ULL, 
            0xA4A29FA9B359DE5CULL, 0xF512C7E884B95AA2ULL, 0xE40EC0BD4C90DD6FULL, 0x9D326C057667FD6FULL, 
            0xDAEEB617F52B02A5ULL, 0x517AA0BBA5677F81ULL, 0x13CE7DBAC409FF57ULL, 0x34260F453E788761ULL, 
            0x9B0C96545A24DB7EULL, 0x06ED8687766ECFB9ULL, 0xDD7CC391F0A4AF21ULL, 0xB0A50C86FFB07A16ULL, 
            0xD477218BDAC36E44ULL, 0x961BBD37C8A4F6BEULL, 0x265EBBAFF5EEE353ULL, 0xE91369C2BCB1A4C7ULL, 
            0xAE0A03C5C461531DULL, 0xB4C328ACE73E7A3EULL, 0xE0F0692F4390F4D8ULL, 0x7C62D1252A0AFD3FULL, 
            0x95EA9110CD514C6BULL, 0xF34077AC4098CB58ULL, 0xD80A3D92EA7A3A37ULL, 0x8E3156F615D9AB00ULL
        },
        {
            0x66318D8651A22B3BULL, 0xA618CE1447824F71ULL, 0xFD1777E2AFF9568CULL, 0x79E530C696C0C8E6ULL, 
            0xA568F2F1D031ACC9ULL, 0xED7A9842B9735D39ULL, 0xC2A6E14BFBDEEA3FULL, 0x74F81A8A7EB3242CULL, 
            0x1634E92AB290BA30ULL, 0x8A57FDDC49A51FC5ULL, 0xB094DD31C03A0E27ULL, 0xB67118DF186ED108ULL, 
            0x418B45040C226DD8ULL, 0x52084D09C8A2DAD9ULL, 0xCA5698E5C5CE5ECFULL, 0x1915162A7869EA3BULL, 
            0x0AFD5C21E0F2DF50ULL, 0x3F0C406FE2BA7001ULL, 0x49602FED7D700F16ULL, 0x9203C9D6233DD0E3ULL, 
            0xF11D5DD5E8E39CA9ULL, 0x8DD4C90AD3344F04ULL, 0xCC63F664021AB4E7ULL, 0xCAA43488ACB18F19ULL, 
            0x029B1D1262BB5D06ULL, 0xBE310E883BF1F086ULL, 0x4ACC371B31A0720DULL, 0x4EAA2B931BFB2C16ULL, 
            0x99C3D9F1CD20F728ULL, 0xEF22C08DD39FA934ULL, 0x8E9D9FE19B749213ULL, 0x295387C50B34CA9EULL
        },
        {
            0xE569013C72BA24CDULL, 0xBD1E8EA6B7CB0806ULL, 0x7BF8FE7289CB3118ULL, 0x056FD8C2083C10FFULL, 
            0xBDA41CEFF3D6BB05ULL, 0xCB2C7D75D7FD11B6ULL, 0xB2B0B6FD8B610EC2ULL, 0xC374EC62C3D036DBULL, 
            0xE4AFB91CDCA00441ULL, 0x9FC58A3D10318192ULL, 0xFE360BF7FF89FEC4ULL, 0x205D0041ABEEFA84ULL, 
            0x396DB5B6CF59F668ULL, 0x89F8227C4C344962ULL, 0xA26374859A837D98ULL, 0x28AD7E8FA0B8C78BULL, 
            0xFB2B6157F2E38BA0ULL, 0x0A90F48DE4E01F8EULL, 0x6F8E3A6D9B1A8AA2ULL, 0x9020237DCE77592AULL, 
            0x9FCBF26A9279FEE1ULL, 0xD014BAE7CF887B45ULL, 0x89FF70DA7B148C14ULL, 0x75C68565D73D279EULL, 
            0xEF476FB029B98E6AULL, 0x91D0E94D4D53EB4BULL, 0x82805AB9339D198FULL, 0xE368E6EDD29CFF3DULL, 
            0xE6FFC50E7CAAC5E8ULL, 0x2054FE3C2F3B5888ULL, 0x3DF97FB3B5218D70ULL, 0xD0361F1435D018D7ULL
        },
        {
            0x4C34F17AD3F74E8BULL, 0x7F7DD6CEC7A8C0C3ULL, 0xA6DFB01A115FBED6ULL, 0x1F7C58BD5A7A0AD7ULL, 
            0x61ADE2366EF6FB0AULL, 0x1DE8FCC59FCFB02DULL, 0xB90B00C78CA413B5ULL, 0x1B71108AA0008EB5ULL, 
            0x12058B7443C5A496ULL, 0xE37DCC8E80534475ULL, 0x08B6FE222AB44663ULL, 0xCBC276C0B5126A88ULL, 
            0x246BAA0C380DEE8FULL, 0xEFC4D173C20D4A7AULL, 0xDD650FC72C035431ULL, 0x87F67D24F0B05CA3ULL, 
            0x4AA1C89CDF1150F7ULL, 0x70ED678CCC99C0C9ULL, 0xB19390FF13D189DCULL, 0xF89BAF38CE9B603DULL, 
            0x20744095767E3E16ULL, 0xA81604710C7F390EULL, 0xAEF83AB038AE8F30ULL, 0x29FF9CD16D7536EAULL, 
            0x6E0ABC161920721CULL, 0xC71EA60B180A1786ULL, 0x3EFBCCBEA95ECC26ULL, 0x9B9323F9A46A1041ULL, 
            0x9A422190A5133DABULL, 0xE92B517A34C6A44BULL, 0x19EB69ED72BA1824ULL, 0x3D4630BD2E57C606ULL
        },
        {
            0x92180E9110CDB7A2ULL, 0x1A42BDE859CCD03BULL, 0x12588D6B12264EF1ULL, 0xA1EF7B6DF64EF54BULL, 
            0x58054C219A9FDA7FULL, 0x2DB950C9C4900F20ULL, 0x7AE7120704647042ULL, 0x5A7160BA226C1EACULL, 
            0xC051204C5EDDE304ULL, 0xECD9DDF31C978D28ULL, 0x3DB46CE76146E4DAULL, 0xD86DD38B8E2540DFULL, 
            0x5A6BFEB988135A93ULL, 0x2FD0343A051CDF31ULL, 0x87EE2EE0FE61E644ULL, 0x9FB97B266F1A5833ULL, 
            0xF5302B3F8B250744ULL, 0x1E4AF290EED1E861ULL, 0x4D85F8FBA2C9BBF9ULL, 0x98FD08FB892443ECULL, 
            0x9A2C0C5655480F7AULL, 0x0ABEA666747D0B24ULL, 0x5CB40A84B71ED18DULL, 0x2039A45EBA5347DAULL, 
            0xBD013C2C284B96C4ULL, 0xA8F087AF2EE41356ULL, 0xA9CEC6C01F1D5732ULL, 0x8A27B3430FCD6250ULL, 
            0xB3624FE5B6F20553ULL, 0x3313B82B31141D81ULL, 0xA405DDBCEB3378CBULL, 0x2CA031788E20BB03ULL
        },
        {
            0x49E5EA4B6866EE20ULL, 0x6DFFB6D4993FBC5EULL, 0x29C68D4A8E2C956CULL, 0x05D8D5FBDE79973EULL, 
            0x183E1EC73BD46985ULL, 0x3926EF294270EE42ULL, 0xD3F79EF55ADB041BULL, 0x8096BC17BC402F27ULL, 
            0x2AFA18AA5958F0FFULL, 0x2C134AF76ABA8FBCULL, 0x62D56BEAC610116FULL, 0x6641F0C8063FB276ULL, 
            0x1FA2A5C8F6605EBFULL, 0xBAC6BA1675FAB274ULL, 0x7F855FFAEC6B3A71ULL, 0x3A27105A862DC9D9ULL, 
            0x04FC93FC6CBC6B4DULL, 0x0819411AEB70CF28ULL, 0x278CB4754BAB9B5DULL, 0xE547F0589B33DB56ULL, 
            0x9D231D48ED589EC1ULL, 0xBE5383BA6C536EC3ULL, 0x16F664CC34DB384BULL, 0x38F71CA69CCD2568ULL, 
            0x5D06C0AEAB581635ULL, 0xB43D3EE9FAFBB785ULL, 0x3F415A8A25214FCBULL, 0x89F43D50B5B1E6BBULL, 
            0x027B0DF4F466090CULL, 0x1B3338D9F3885427ULL, 0xCE844D0019E07FA1ULL, 0x4BA220436058E578ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Antares::kPhaseCConstants = {
    0x51AEBD349783E409ULL,
    0xC3E4BC9512C69288ULL,
    0xC267E13CF23A606BULL,
    0x51AEBD349783E409ULL,
    0xC3E4BC9512C69288ULL,
    0xC267E13CF23A606BULL,
    0x7A989FF8EDC2FC8DULL,
    0xCE3DFC7BD5BF7B7EULL,
    0xBE,
    0x8A,
    0xAC,
    0xAD,
    0xE1,
    0xA2,
    0x77,
    0x9E
};

const TwistDomainSaltSet TwistExpander_Antares::kPhaseDSalts = {
    {
        {
            0xB523A81C502B485DULL, 0x44CEE6CA629FB529ULL, 0x5954A7C38496B665ULL, 0xE44B1A10120DAC14ULL, 
            0x93CB81E1D07357B9ULL, 0x597BEB6E9AA11AC3ULL, 0x13434DEE3E916E75ULL, 0xCB6CFFDEBB2EAB7DULL, 
            0x8CA73238897B405FULL, 0xB1FCE33DE1383D6CULL, 0x262DBDD8386E570BULL, 0x403134CF9C621796ULL, 
            0xAFF320841211C304ULL, 0xEDD9564B1516681CULL, 0x0974D0E44B9EF0F9ULL, 0x4BCA87157B3FC735ULL, 
            0xC6AA202231951A0FULL, 0x8497CD244533A5EBULL, 0x898927BE4B91395DULL, 0x5A46550AF7980456ULL, 
            0x8FE8A60D7A9C0CCDULL, 0x5113E29192F33B80ULL, 0x0B4ADA4C27100B2BULL, 0xED78D1936F37EC5EULL, 
            0xCAEE2C7ADFBA6CEEULL, 0x1463C2FC0F5AC414ULL, 0x357831081C427607ULL, 0x3FCFD651B947BD84ULL, 
            0xCEF8C26A3D5C3B13ULL, 0xB9A842F688183052ULL, 0xC5A4F114442BB230ULL, 0x49914064D1D61C5BULL
        },
        {
            0xECA1A2A39C6C0E53ULL, 0x2ADA9171AB923162ULL, 0xDB710D7036EB7119ULL, 0x72A99632DC8F32D4ULL, 
            0xB228BFE442F1D854ULL, 0x76AA122B64D54446ULL, 0x2E4557EECCF3C968ULL, 0x3873B7FF68C8EF36ULL, 
            0x632C66838396E4A9ULL, 0xEAE57FD199E65673ULL, 0x6C0031D6D31B216AULL, 0x65CC459D56C2EE0EULL, 
            0x4BA97C802AC6CA6BULL, 0x8C66C0F9F4E9E64AULL, 0x5D8FAE7C0C2B8B09ULL, 0x22C476EDFC286A2AULL, 
            0xD4E3958E4341DC75ULL, 0xE9A908F90A7B974DULL, 0xB16E4FDA7843C4C8ULL, 0xEA4C5C11324D4D11ULL, 
            0x78C66AF9D1D94B1FULL, 0xD8592F7127ECD9D2ULL, 0xCF3C027D0F07834BULL, 0x7013692B0078F95AULL, 
            0x9A9D51D9835C19F9ULL, 0x1E4F3BC991A20E4DULL, 0x276611B1ED4D278BULL, 0x3340EFBD3FCEC899ULL, 
            0x2EE76775EC6E23BAULL, 0xB58A1CA762604CBEULL, 0x2C91B386B2E7D501ULL, 0x539C7968E88DFE61ULL
        },
        {
            0xA1CC2CA9263E81AFULL, 0xA8E2EEC7A3FD0EF8ULL, 0xC2DAE75A43F1B3B1ULL, 0x2FCDAF51CC33E32CULL, 
            0x252AAF04C6620CC9ULL, 0x2F890A0FB0084EA4ULL, 0xA0C3540E2C4BDD89ULL, 0x2CA197DFFC99E3D9ULL, 
            0xEEFB07FFFFB2BD39ULL, 0xA0CE6D52A8CD62A4ULL, 0xE707471B64B5EF5DULL, 0xA141F5BBA927FB12ULL, 
            0x0102BA41875298F2ULL, 0x7A44E3099FF5C84DULL, 0x79A80D34D80ADF70ULL, 0xC617B995B67255D7ULL, 
            0x53F02D1406AD643CULL, 0xE5F77353B4277A1CULL, 0xF895808FAA3BC30BULL, 0x81C97DF438477665ULL, 
            0xB09614094D68C719ULL, 0xC3807F95585419D1ULL, 0xC7284D7E086DBCEDULL, 0x785B745B9AAEFB45ULL, 
            0x31417449268045D6ULL, 0xCA49BE6DD698C72AULL, 0xE368D59892281E86ULL, 0xFA932CE353EF3F13ULL, 
            0x3DB0EE94FB21FFFCULL, 0x45773A942877D94DULL, 0xA366DA68B0FA581FULL, 0xDDF325EC63981AB4ULL
        },
        {
            0xDE88E48055AF7DE0ULL, 0x23503120B3EE3A79ULL, 0xDCFF3FB5E78F49BAULL, 0x62C79E5CEEE320B7ULL, 
            0x1036BF10D39B6C73ULL, 0x0D214A4A41366A4EULL, 0xCCFC440557BC2052ULL, 0x328BE62447CA4597ULL, 
            0xD5B606529D364360ULL, 0x00DB903791A54FF3ULL, 0xCC066F3B07F628D3ULL, 0x509D85DB24190A47ULL, 
            0xA488476741187A74ULL, 0x9577F894A451FABAULL, 0x70C5C0667919E8A6ULL, 0xC8B061BA1D3B5BD2ULL, 
            0x6354380C3FE15481ULL, 0xC280C624F5F37589ULL, 0x551D4B1630C59179ULL, 0x382CB8AC6F1E9E2DULL, 
            0x8436DD7C8F136280ULL, 0x618CFC15058C58D0ULL, 0x5F27B56C8F163071ULL, 0x6FC5C02997D72A52ULL, 
            0x0BCF0F8977F47A8FULL, 0xDC954D50ECD8EC93ULL, 0x60DD37FB9A5F315DULL, 0x3EC5BF764C21EE5EULL, 
            0x5DC94C7B088FDA0BULL, 0x46D77D2A4BA2D205ULL, 0x0ACA2539D0B37C1CULL, 0x3E023A949A9FDB72ULL
        },
        {
            0xCA3D92B3D47F2CF5ULL, 0xEFB63E3EB3699DB9ULL, 0xA768BA705FE81BFAULL, 0xC9F599EBAA15022CULL, 
            0x5BFEB7B128391F8AULL, 0x89A8C15D288A7A55ULL, 0x09CE0EDC84F4B731ULL, 0xC9FDD27A1EBE3F17ULL, 
            0x553DE8F423E3B100ULL, 0x84FE55CA09B82B16ULL, 0x1CC3CB826CE21BEAULL, 0x08FD839C7386AE4EULL, 
            0x7085FD1237ECC108ULL, 0x324AE21625A588A9ULL, 0x664197BE225282C5ULL, 0x8606D4472A49B0CFULL, 
            0xA599B46CF6CF87EBULL, 0x0E802A1F7AD7920CULL, 0x0760283A534A8068ULL, 0xC589A5F1FA20792AULL, 
            0x0100AC907B42AD09ULL, 0x2309229842A09048ULL, 0xD61EA9C83E5D45B4ULL, 0x08DBD5ABBF819B9DULL, 
            0x34CAB2894B5BF4DFULL, 0x46853E5857F54C1EULL, 0x193E28E792CCF0A7ULL, 0xEA7480CCBDB08FEFULL, 
            0x00E3FC1198808E55ULL, 0x0A6153BD384C0878ULL, 0x0D49A9EEAE484A65ULL, 0x972366673C46279CULL
        },
        {
            0x2FA35A69835F4341ULL, 0xC08C34C9A9833F22ULL, 0x83BA080CC977C6A7ULL, 0xF3C744D3F113D83AULL, 
            0xB9521A62213A3FF4ULL, 0x22119292D6CB76EFULL, 0x35B9A2518A90373DULL, 0x442DEAA7A5338281ULL, 
            0x0DFE8642F7D5B41CULL, 0x8BDB18F1DC69F3BBULL, 0x95DC8E6AEE79FD93ULL, 0x8D43B6930D8A0CD4ULL, 
            0x3D2DDCB2DD9865D3ULL, 0xBF76400917A9BDD7ULL, 0x9D03FC04CB6E0471ULL, 0x018DC0C7869C398CULL, 
            0x97153115B2B50FABULL, 0xD6CD0C028E75CE0AULL, 0x9C966C67AA212A70ULL, 0xBBA3A3F1B5BDD4BEULL, 
            0xE704D4B2B5AAEAA8ULL, 0x456F6B2BBC018D93ULL, 0x2D24AC31D115C230ULL, 0x29BCFCB76040D5A6ULL, 
            0xA7CA104DF85C6A08ULL, 0x37D85CEA8502CD44ULL, 0xFC1F23643CAD7D2FULL, 0x6BB9BA8D148E729DULL, 
            0x4211DF4521FB34EBULL, 0x5132099D47C687E5ULL, 0x8AFF4C3F8E337C57ULL, 0x1F2B6C3F1D274D5FULL
        }
    },
    {
        {
            0x1F859679FB5A565BULL, 0xFA38D1C722FABAB8ULL, 0x7FA5E4402DBDF4A4ULL, 0x16303805998197C8ULL, 
            0xB5E26563C64794BEULL, 0x09D4DC2362B356B2ULL, 0xEA5C1ABD4AE3760FULL, 0x84E6986AABD59E84ULL, 
            0x62CCC96EFE7E08F0ULL, 0x62F57146DEA2D09EULL, 0xC4C919C9917B668FULL, 0x246A44690F4496E1ULL, 
            0x7EF0F585346780F1ULL, 0x843A58296D66A8C2ULL, 0xE2F1D2D442F8F793ULL, 0x00BB6C21814D1F21ULL, 
            0xBE1084513CC9046AULL, 0x519E4182BE2A6E0CULL, 0x95A2F2F38AB90C19ULL, 0x535BD1F31A2059F0ULL, 
            0xC9B3337285C97ED9ULL, 0xBF8D99EEF00EABB9ULL, 0xB9B0BC9E46107FEFULL, 0x5F293F87334BC9A1ULL, 
            0x7E6774C73B707713ULL, 0x9C8DA33A3DE592ADULL, 0x2FF4C166FAB7DC1EULL, 0xFE9404BAA3FC1E61ULL, 
            0xEE9FDF54A141A5D4ULL, 0xE90B6519D394D76CULL, 0xA1498D7B5A245C97ULL, 0xEE6E0448A705CBDCULL
        },
        {
            0x23D92E0906A4250CULL, 0xF657ADB16F2350D9ULL, 0xDF661A5BF7B0954BULL, 0x1B93AF46A640E67CULL, 
            0x66689A833CCE9C14ULL, 0x90E470113C3594CBULL, 0x26DC9697361D3EFCULL, 0x5B1AE26E5B4FBB09ULL, 
            0x48FF44911BC09077ULL, 0x57317BE47BF8473DULL, 0x39C05B1D4FB60CFCULL, 0xAB7819B90E1629E3ULL, 
            0x346048D1792E5580ULL, 0x56FD18C948A70010ULL, 0x97BDE8B08424F6C6ULL, 0xF56F1A0896BD2214ULL, 
            0x6EE1DE2697C1AD38ULL, 0xB707C7844D9A4D87ULL, 0xD89C81EBB2DD8D29ULL, 0x89C29F27B69338EEULL, 
            0x6DF11690F7B37498ULL, 0x237993EA71C4CFB0ULL, 0x6B939C3CA8E955F7ULL, 0xCECF011DACE1EA13ULL, 
            0x4468C0E73D3BD5D0ULL, 0x7108A4EEB4D85056ULL, 0xFDD0C4E5D24F07AEULL, 0xECDAD7C577CDE392ULL, 
            0x9D622AADA8C394C9ULL, 0x1F23FA2283B63815ULL, 0x0CD1298E8F9B2EAEULL, 0x3B6483DC189B127FULL
        },
        {
            0xD824233599203E9DULL, 0xD984FF04BFA9585BULL, 0x6CAC8FE752F483D5ULL, 0x50FD03E0990CAA6FULL, 
            0xC5FFC380F3BB838DULL, 0xB9C7A225B4AF234CULL, 0x6731222B28F5B74AULL, 0xC81FC7AFA4C3DB7BULL, 
            0xC925CE48D8BD3315ULL, 0x25FA3C455FE0CACFULL, 0xC46EEA8A5DBBE059ULL, 0xB5AF46DC33DCCB97ULL, 
            0x8BB676F9A305D3FBULL, 0xF2428D3B1EA07B96ULL, 0x96C4F3955B13247FULL, 0x53C24DD8F24A0D85ULL, 
            0x9F7C91322906D126ULL, 0x780BD02A83F18CE3ULL, 0x7AA232C035C90AE1ULL, 0x2C165B5DE1E2E99BULL, 
            0x3AADDD9E272A3464ULL, 0x8E6E03C6EB13F373ULL, 0xCB51B800FA348314ULL, 0xA1FB22F4501DD05FULL, 
            0xB8F2E3F33C0570ADULL, 0xA453322F8B75DA71ULL, 0x83403DC16D4C71A8ULL, 0xBA521863671349EAULL, 
            0xF52B56B307E5E0CCULL, 0xDD31BF67146B4BD8ULL, 0x9B9E587F580AC70FULL, 0xBE7154064BFD2B2DULL
        },
        {
            0xFE6AD41CFEFEA9E3ULL, 0x2620679E7171E2D5ULL, 0x2F1D6ECB8EC0F879ULL, 0x98A6A4AFB39A51C4ULL, 
            0x5B1B47EEC329A156ULL, 0xCB4D576902E9C7AEULL, 0x25D9E2CAAB620B82ULL, 0xB20F877C57E114C1ULL, 
            0x8EE7BC36C7DB54FEULL, 0x2E2CD4E2C21A0E1FULL, 0x00035B38F37C12C5ULL, 0xEDB629A0FA934BB4ULL, 
            0xAC6FC9FDAD4701B9ULL, 0x7DF7EF8D27D24445ULL, 0x0BF10C1E98CFD434ULL, 0x575DF0A25B2B3BF0ULL, 
            0xF501B38A7E5D4C26ULL, 0x783DA41016A1D658ULL, 0x8F5203361194B415ULL, 0x219AD63A02D8916FULL, 
            0x90E43EB54D9E2305ULL, 0x7CF329C6085C02D1ULL, 0x807E8384D21B79E2ULL, 0x1FAEFECA3975260AULL, 
            0x74D9F9D7337D28B4ULL, 0x0445FF7EA9DA5A7DULL, 0x3930A6AA34626618ULL, 0x32A21326244AFF77ULL, 
            0xEE42338D5ABC35E5ULL, 0xD065E475AE3C406AULL, 0x5C38D1DA6F7C4986ULL, 0xCD9EB37597498576ULL
        },
        {
            0x22C70C6FE26AF1AAULL, 0x665BB38E2B14BAACULL, 0x6766EC918C45A3A3ULL, 0xD06A6EE00050FF1AULL, 
            0x8C27DDD590E81340ULL, 0x4A0541093BDE51C2ULL, 0x428F19578D3E4211ULL, 0x7EE9F2CEB8251827ULL, 
            0x76D2C8A1B74C41E3ULL, 0x8413ACB393858AA6ULL, 0x45CB5B0DB3425936ULL, 0xE2AA066EEDFE9651ULL, 
            0x69D9D5B71D1A506FULL, 0xDDDC7FCC7B2B51B8ULL, 0x94924244043E8BBBULL, 0x0AB554AFE0CC40CFULL, 
            0xB2FA3D8699CFE2C8ULL, 0x801A9A027DB41D92ULL, 0x6F1FB9512084B166ULL, 0xB83B4017638AA0ACULL, 
            0xF8F6DBFAF4313B95ULL, 0x4A4524A660D3A0D5ULL, 0x463A0C8D93C1D7D2ULL, 0xF1A765228452ACE3ULL, 
            0xC964CD082E60DE7FULL, 0xBB0AD329CA1678F5ULL, 0x89A0501029CAA57DULL, 0xB8CBF1BF8DBCAED2ULL, 
            0xF2EC94ACE69E3D0CULL, 0xFB345994E6978D34ULL, 0x9411315A3A78BC8AULL, 0xE6AD9B52427E36A5ULL
        },
        {
            0x1FEDDC922027184CULL, 0xA69F1CB08D9D5ADDULL, 0xE9264F5F2C86EEBDULL, 0x426B27E55B9137B4ULL, 
            0x3666273C6FC9FEC7ULL, 0x01A31EA9824D4683ULL, 0xE439A5C497DBDAE7ULL, 0x3BEA97BD7C2F6C05ULL, 
            0x3838A915BC7FE946ULL, 0x026556AC89EB2E08ULL, 0xD0346BAEBB011159ULL, 0x526478E114729D87ULL, 
            0x39BB61AFDA0DFF68ULL, 0xF5C1E7C28649ACBFULL, 0xC3250E7F52B440DBULL, 0xFB576BF009C79C02ULL, 
            0xF51B057AA6BE9152ULL, 0x2D66BA48782F9814ULL, 0x60EE997ECB3847B0ULL, 0x55C7299AEDB053BDULL, 
            0x697F82D243A34F92ULL, 0x2F805B8884064F54ULL, 0x040E1BD1EB47F292ULL, 0x18289110A5C91055ULL, 
            0x78AFA858A36D4C76ULL, 0x317DAAE6A22F7F2BULL, 0x09EBC376F76BDC0FULL, 0x55B57B4D921FEDA4ULL, 
            0xAF2028F45DF3EACEULL, 0x014B74ED3B906E58ULL, 0x28B1BA7476A17DE7ULL, 0x4D6F44BAE7237155ULL
        }
    },
    {
        {
            0xE190A87209648F5FULL, 0x00FA59EA1E664320ULL, 0xBE6F5F71313A2BA9ULL, 0x1DDF9226966BF673ULL, 
            0x4F586AE441F0CDF9ULL, 0xA9F3FDD81C500A9BULL, 0xBA686EB8EC354170ULL, 0xD17EB8107BFFF1CBULL, 
            0x9867676D7DC68051ULL, 0xC5DB562F7D89DD25ULL, 0xB2DDABC02551A689ULL, 0x0EDAD120E09581A5ULL, 
            0xB592D4D0AEF75B63ULL, 0x0EA5DD0084CB3688ULL, 0x859F6E08CF50223CULL, 0x73623BC3493B7DB2ULL, 
            0x2656780C4D5899EEULL, 0xEFA0C19AA94C4C56ULL, 0x8E4B1FA45D2DA2C0ULL, 0x3921AE710B309A59ULL, 
            0x583E9D420A4B1F4EULL, 0xEA3D48C67FAD4727ULL, 0xC76C69BEB57EA6C0ULL, 0x8B19A0E2E25B170CULL, 
            0x893B336877158137ULL, 0xEB5A8D3563549E78ULL, 0x9FD7FC778D51EF46ULL, 0x41076A68C5E91BB4ULL, 
            0x24C32105E617A6D4ULL, 0x0D85D224BC2D8832ULL, 0x3DDADF1A6F228FE4ULL, 0x6664D2A5F9CF0666ULL
        },
        {
            0x7B47A5BAFED241DDULL, 0x0592DBC6A5B0D9D2ULL, 0x46FAF943F27A0C58ULL, 0xB9E7FDFBA21BB930ULL, 
            0xE6C420689183E900ULL, 0x13DF62720A4E6C50ULL, 0x7C4B61470EEEE100ULL, 0x52EFA77FF05B031DULL, 
            0x44645D109FC94FE1ULL, 0x86A5DF65623B7F15ULL, 0x955A910A6032864FULL, 0x2F0E46A36F895FE7ULL, 
            0x392C9FC7582FA68CULL, 0x85AD7450ACDA4574ULL, 0x9844C3936DC3C960ULL, 0x28F58352868E5AABULL, 
            0x13CAFC35A8F6A8DBULL, 0x388C791231CE6C82ULL, 0xB94E00A093968A86ULL, 0x70037C28FAD1BC92ULL, 
            0xC68265A314CCC47EULL, 0xB690ADF99F2D8710ULL, 0x0BB8ED05B29333C3ULL, 0x0C12F18665964F62ULL, 
            0x8915DB10DD0A34E0ULL, 0x04353762E786E61DULL, 0x7B521A8DE989D104ULL, 0xB64038E18E47C105ULL, 
            0xB527A6E864B64C79ULL, 0x317FFFA71BC45B68ULL, 0x44D0C5399A3B70E8ULL, 0xDE9571311BF4C268ULL
        },
        {
            0x3B3A57A64F06E2BCULL, 0x28F13451D0C65F94ULL, 0x58A54B77B620F158ULL, 0xAB37226AA4619635ULL, 
            0xE9DAE3D5578A3F32ULL, 0xED7DC9816AD9F6D6ULL, 0x54A7A0C99798656BULL, 0xD1936764BAE6BB20ULL, 
            0x7B4A288030F28884ULL, 0x885CE92E5E9BEBBCULL, 0x46C785722F7C4B1FULL, 0xB8C469B91CCA6F0DULL, 
            0xF0A5645009C38801ULL, 0x89753906A3A628CAULL, 0x14596C0564CD9C48ULL, 0xFE495C3CE3AA1BB0ULL, 
            0x67B3F5FBFD2ECB63ULL, 0xAE63207E3AC61F7DULL, 0xCA4B49A8B19E4716ULL, 0xC9E228150D8BEFB2ULL, 
            0xDF436EB402932E9EULL, 0x498CEE4BDAF09973ULL, 0x9A9B55A8385A5E89ULL, 0x9F5DCD41FA78D027ULL, 
            0x4D4BB609A9EDA76EULL, 0x3781C11F4B1D6F58ULL, 0x8C15875B74BC6F96ULL, 0xDC61582DA06CC9C3ULL, 
            0xCA51782F26D34DBCULL, 0x22541CBCDBF9738EULL, 0x4632AAE92592B826ULL, 0x29323C6D6BF7FACFULL
        },
        {
            0xEDEA32B171BF8319ULL, 0x04459AF2A4742FBDULL, 0x61765E8BC0569492ULL, 0x2C95F68E084B364FULL, 
            0xB0CD29A4C7C496B2ULL, 0xD290E8926F215506ULL, 0x6A4C74FDD12F7C78ULL, 0x3BD8D4BAF66A0B57ULL, 
            0x21AF2772EFB82960ULL, 0x4DD3278F311E216AULL, 0xDD907AF82378566EULL, 0xDB96D8E88F01B4BEULL, 
            0xDB98371269352A91ULL, 0x68019C91B5B0188CULL, 0x8BD2716B3CC876E8ULL, 0x9127213BE70A98C3ULL, 
            0x1DFDD19FEF7CBECAULL, 0x1D1EB7D7AD562DCDULL, 0x631F5CC1AAB12554ULL, 0x5120037F44463262ULL, 
            0xB93BD44BA29030D6ULL, 0x641FA09F280574FAULL, 0x653A1D1000F5E078ULL, 0x4DEC83D7DFE0D389ULL, 
            0x31EA96B627C30AF3ULL, 0xD2C7E68AEB50B6E5ULL, 0x140AC7DF3835DD24ULL, 0x9C849D08D727E83BULL, 
            0x12EF013C9B0A7DCAULL, 0x26FA00674878D49AULL, 0x69C57164332BACF9ULL, 0x725AFA7AF75AC907ULL
        },
        {
            0xF8D3755A474E6E90ULL, 0xA086D9AE97B0B758ULL, 0x044EFF55E754726EULL, 0x9FCA9D0289306DE5ULL, 
            0xF429CF9AC80D8CE9ULL, 0x8CAC7B197DED05F1ULL, 0x3A914DE88F88D621ULL, 0x6E8E12D62F425233ULL, 
            0xF6FE0A3073F9ED4EULL, 0x3058D6DCA1B06875ULL, 0xB7985AE15EFE64B2ULL, 0x5F752989BE0C1700ULL, 
            0x2B9C0A0FE23DFCE6ULL, 0x7017086BCE1F8FB6ULL, 0xA9356F0671770ABDULL, 0x920FAD9AFDAA5661ULL, 
            0xF1279ACEB6574EA3ULL, 0x22DD608A6D82C7E0ULL, 0xF79D37089DE970E1ULL, 0x77F21CD1250CD4C0ULL, 
            0x59AD4B7E99B4C0F6ULL, 0xDA37FA9C345A4687ULL, 0x99DDCBEA9434E2D1ULL, 0x34B9B90646543ADFULL, 
            0x9D56E600B016B906ULL, 0x21909DD4A38CA1EEULL, 0xA147BFC0D2D05C69ULL, 0xA64C47972CE098BDULL, 
            0x1EF3DF20E443118AULL, 0x39D2886BC568EF62ULL, 0xBAFB69A727A38490ULL, 0x3C8FA7C63224D8E1ULL
        },
        {
            0x5C086EA6B609C79FULL, 0x3B366127219BBBE9ULL, 0x6F1396336CB31E4FULL, 0x8C6A037192571755ULL, 
            0x53250D9CDFA938A3ULL, 0xE7DD4D4DD9009DF2ULL, 0x869E16B4C55BC90AULL, 0xFC75DC16B60C9894ULL, 
            0x300743D49CF0675EULL, 0xCD2711E30B9D2656ULL, 0x4E9DE2471B1D9FDCULL, 0x6B8A181126B44284ULL, 
            0xFC1E539C88499CACULL, 0x3C67A8285470A03DULL, 0x6CF77BA120CAC47DULL, 0x8940DAD1663A5486ULL, 
            0x846BDD18ADD16C3AULL, 0xC3A65CB8DD37D8C4ULL, 0x47EC7EA30A2A226BULL, 0xF6D2E48B078A14AEULL, 
            0x0607C4CF68A7387BULL, 0xE66B720DEE82F2E1ULL, 0xF334782303489C68ULL, 0xB228D159B42ADAC2ULL, 
            0x4ADFF0D2D0FA0199ULL, 0xCB9298D09ACD28F0ULL, 0x616EEC4D21BB718CULL, 0x35C918D9D902CC5BULL, 
            0xCC6FB291ED5BB0E1ULL, 0x3EFF7895E4BEBDC7ULL, 0xF587CC1FE78BE623ULL, 0x1726D0B18A316F8EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Antares::kPhaseDConstants = {
    0x596D63936BD5750EULL,
    0x94F632D0D7281CE4ULL,
    0x995B2931EA82DD1DULL,
    0x596D63936BD5750EULL,
    0x94F632D0D7281CE4ULL,
    0x995B2931EA82DD1DULL,
    0xED693E5ABCC0438DULL,
    0x6C4915A2F9AF9666ULL,
    0xB7,
    0xC8,
    0xF0,
    0x11,
    0x1C,
    0xF7,
    0x48,
    0x7E
};

