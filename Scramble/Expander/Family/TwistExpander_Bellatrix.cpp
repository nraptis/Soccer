#include "TwistExpander_Bellatrix.hpp"
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

TwistExpander_Bellatrix::TwistExpander_Bellatrix()
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

void TwistExpander_Bellatrix::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF4E53600248D5CAEULL; std::uint64_t aIngress = 0xAEA9E7B450D2ACD0ULL; std::uint64_t aCarry = 0xD513CE64F345FA31ULL;

    std::uint64_t aWandererA = 0xDE316BB3A34070ACULL; std::uint64_t aWandererB = 0xC93BE3296417981AULL; std::uint64_t aWandererC = 0xFD7B23C4EF5151DEULL; std::uint64_t aWandererD = 0xE34A23923BF09E44ULL;
    std::uint64_t aWandererE = 0xC9DB34B174E24E67ULL; std::uint64_t aWandererF = 0xE4738F2D32034A13ULL; std::uint64_t aWandererG = 0x868F255AF7BCB3CBULL; std::uint64_t aWandererH = 0xE844C4B8DC621F0EULL;
    std::uint64_t aWandererI = 0xAEAD529F4C17696DULL; std::uint64_t aWandererJ = 0xA93BBEC0DD81EFB5ULL; std::uint64_t aWandererK = 0xA8DB5C38690BD802ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x95828869F0D16755ULL;
        aCarry = 0xD66CEDC8C3EA2031ULL;
        aWandererA = 0x9B414BCFB3BF77A8ULL;
        aWandererB = 0xBDD7EF9C6198F637ULL;
        aWandererC = 0x8A7033F538479592ULL;
        aWandererD = 0xFC1FA331E6DBE5A2ULL;
        aWandererE = 0x922185E9B6C5EA71ULL;
        aWandererF = 0x825CB41447A16984ULL;
        aWandererG = 0xF3CFA7DD91E54936ULL;
        aWandererH = 0xA2D932D0F4861D6AULL;
        aWandererI = 0xCA75BA9591C2288CULL;
        aWandererJ = 0xDD2CA6F42B0EAAB7ULL;
        aWandererK = 0xA829FF1462149DD3ULL;
    TwistExpander_Bellatrix_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Bellatrix::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD3E483052854BB2EULL; std::uint64_t aIngress = 0xA4A96F9338A0DA7CULL; std::uint64_t aCarry = 0xB4D2098700563A2DULL;

    std::uint64_t aWandererA = 0xDFBD11C2A5205B18ULL; std::uint64_t aWandererB = 0x82AD9F32E6BBE484ULL; std::uint64_t aWandererC = 0xB28561086F44C320ULL; std::uint64_t aWandererD = 0xEF5C8C55C3D0D746ULL;
    std::uint64_t aWandererE = 0xDE033C14B1237C5EULL; std::uint64_t aWandererF = 0xB3B24139F0BAD4F7ULL; std::uint64_t aWandererG = 0xCB97F376093C1339ULL; std::uint64_t aWandererH = 0xEA308C454E219DF1ULL;
    std::uint64_t aWandererI = 0xA89AAE19CEF5368AULL; std::uint64_t aWandererJ = 0x881BC2E59EF6AAD0ULL; std::uint64_t aWandererK = 0xF862EAF34D566DD5ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xDFB16210E6130613ULL;
        aCarry = 0xDA0F06E43838A4D0ULL;
        aWandererA = 0xA0FB9D15FD6CF6DAULL;
        aWandererB = 0xC152C679FB4E4655ULL;
        aWandererC = 0xF14474EF244275D5ULL;
        aWandererD = 0xBC0FBCAC746D5B62ULL;
        aWandererE = 0xCD39B2E4531B964AULL;
        aWandererF = 0xEE3122470DAD4EF7ULL;
        aWandererG = 0xFA92268D5E84EB02ULL;
        aWandererH = 0x92430E3C32BE60E8ULL;
        aWandererI = 0xCE24AEA11EE2CA80ULL;
        aWandererJ = 0xCD8917C76982BB21ULL;
        aWandererK = 0xEDC39EE8D9A7F486ULL;
    TwistExpander_Bellatrix_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Bellatrix::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xC65439BC8141858CULL;
    std::uint64_t aIngress = 0xE5C9AB539DAFF8B0ULL;
    std::uint64_t aCarry = 0xA7A267CA7BA36B12ULL;

    std::uint64_t aWandererA = 0xFB66CF75A7FD4076ULL;
    std::uint64_t aWandererB = 0xB33CE43245453BC3ULL;
    std::uint64_t aWandererC = 0x92BA4D508C16BCC5ULL;
    std::uint64_t aWandererD = 0xEC1A93874EDF6C8AULL;
    std::uint64_t aWandererE = 0xCA1DAEEB93F6B0EFULL;
    std::uint64_t aWandererF = 0x9073EA7A0E91E7D0ULL;
    std::uint64_t aWandererG = 0xE28C7310DD182815ULL;
    std::uint64_t aWandererH = 0x9C0BE9525E7616E7ULL;
    std::uint64_t aWandererI = 0x8822CD7896D65400ULL;
    std::uint64_t aWandererJ = 0x8272B7D4103A668CULL;
    std::uint64_t aWandererK = 0x864DC97D189AD65FULL;

    // [seed]
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), pSnowLaneD, 0);
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
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), pSnowLaneA, 3);
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
    TwistExpander_Bellatrix_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::GROW_A(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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
    TwistExpander_Bellatrix_Arx::GROW_B(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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

// SmartSquash candidate 12 of 33
// Exploration cases: 100000000
// Nearest-family diversity: 938 / 1088 (86.21%)
// Total distance from earlier candidates: 10475
void TwistExpander_Bellatrix::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    static_assert((S_BLOCK / W_KEY) == 16, "SquashInvestToKeyBoxes expects 16 invest fragments.");
    static_assert(H_KEY == 8, "SquashInvestToKeyBoxes expects 8 key rows per box.");
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 5U), *aFragmentB = aIceLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 8U), *aFragmentD = aIceLaneD + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1273U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 231U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 539U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 799U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 3U), *aFragmentB = aIceLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 15U), *aFragmentD = aIceLaneD + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 551U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 265U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 769U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1464U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 8U), *aFragmentB = aIceLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 12U), *aFragmentD = aIceLaneD + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 497U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 12U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 959U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 248U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 10U), *aFragmentB = aIceLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 4U), *aFragmentD = aIceLaneD + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1867U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 353U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 243U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1098U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 14U), *aFragmentB = aIceLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 10U), *aFragmentD = aIceLaneD + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 271U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1099U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 73U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1847U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 7U), *aFragmentB = aIceLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 0U), *aFragmentD = aIceLaneD + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 204U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1376U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1543U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1235U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 4U), *aFragmentB = aIceLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 11U), *aFragmentD = aIceLaneD + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 23U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 569U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 168U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1204U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 6U), *aFragmentB = aIceLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 5U), *aFragmentD = aIceLaneD + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 424U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1631U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 961U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1962U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 2U), *aFragmentB = aIceLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 13U), *aFragmentD = aIceLaneD + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 868U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 428U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 595U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1155U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 11U), *aFragmentB = aIceLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 7U), *aFragmentD = aIceLaneD + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1361U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1421U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 459U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 319U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 0U), *aFragmentB = aIceLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 9U), *aFragmentD = aIceLaneD + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 999U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 604U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 975U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1515U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 13U), *aFragmentB = aIceLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 14U), *aFragmentD = aIceLaneD + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1272U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1414U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 557U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 122U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 12U), *aFragmentB = aIceLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 3U), *aFragmentD = aIceLaneD + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1697U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1921U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1242U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1131U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 9U), *aFragmentB = aIceLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 2U), *aFragmentD = aIceLaneD + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 2010U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 440U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 764U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1153U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 1U), *aFragmentB = aIceLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 6U), *aFragmentD = aIceLaneD + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 337U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 973U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 522U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1350U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 15U), *aFragmentB = aIceLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 1U), *aFragmentD = aIceLaneD + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 174U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1044U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 2014U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 480U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Bellatrix::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xFE7F45444F3D0C62ULL; std::uint64_t aIngress = 0xAB002EFCD203069FULL; std::uint64_t aCarry = 0xFEF08FF585D5F12FULL;

    std::uint64_t aWandererA = 0x96842EA97DDCF633ULL; std::uint64_t aWandererB = 0xE59788ED780A5926ULL; std::uint64_t aWandererC = 0xE44E78493B2A5A77ULL; std::uint64_t aWandererD = 0xC0F6BEDAF15A50F6ULL;
    std::uint64_t aWandererE = 0xB08DBF77CF158843ULL; std::uint64_t aWandererF = 0xC60A9680B6E4FF46ULL; std::uint64_t aWandererG = 0x999B77391E68F9E7ULL; std::uint64_t aWandererH = 0xB7E363C60D360B2DULL;
    std::uint64_t aWandererI = 0xD974970C60B56A34ULL; std::uint64_t aWandererJ = 0xFDAD0EADA581A563ULL; std::uint64_t aWandererK = 0xB60535F328C6B556ULL;

    // [seed]
        aPrevious = 0xA53523ED08327CF5ULL;
        aCarry = 0xFB39ACC7CBABAA47ULL;
        aWandererA = 0xFBCB5C1E0FF7EB4DULL;
        aWandererB = 0xA38DB45C96B1DB28ULL;
        aWandererC = 0xC957DCC8AD8C07D9ULL;
        aWandererD = 0xC3A874C7E3CDB9DBULL;
        aWandererE = 0xC1C2EC98856C9E6FULL;
        aWandererF = 0x89DA37FC9295EE14ULL;
        aWandererG = 0xCD483BDE93A94ACCULL;
        aWandererH = 0xFAAFB0FB5AFAE188ULL;
        aWandererI = 0xAD9CC4B832EE506EULL;
        aWandererJ = 0xAD420D6FE528536FULL;
        aWandererK = 0x899CF0E5ABED68BCULL;
    TwistExpander_Bellatrix_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::Twist_E(pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::GROW_A(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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
    TwistExpander_Bellatrix_Arx::GROW_B(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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

// GrowA candidate 12 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 6086; nearest pair: 497 / 674
void TwistExpander_Bellatrix::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3190U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1628U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7640U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2112U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2083U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2570U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 238U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1102U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7428U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4929U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2662U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5807U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8044U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5566U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1678U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 82U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 953U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2043U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 456U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 908U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 666U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1869U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1507U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 954U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1297U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 591U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 362U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 878U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1558U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1064U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1550U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 342U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1182U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 738U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1720U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1449U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
}

// GrowB candidate 12 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 6078; nearest pair: 510 / 674
void TwistExpander_Bellatrix::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7826U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3440U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1087U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2385U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2613U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7052U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5068U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5174U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2802U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 167U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4724U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 506U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6541U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2173U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7087U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5399U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1733U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1193U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 472U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1274U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1020U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1139U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1685U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 390U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1421U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 898U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 875U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1359U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1779U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 449U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 755U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1500U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1822U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1547U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1419U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 506U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
}

const TwistDomainSaltSet TwistExpander_Bellatrix::kPhaseASalts = {
    {
        {
            0x9BCDFB698FB19975ULL, 0x0F808B9759AB2612ULL, 0xE475A176C2237FF8ULL, 0xF0EDF8B808D183A1ULL, 
            0x0FDEDF8165CF591CULL, 0x5AF885CC6906AB68ULL, 0x133EA4D635FC84C3ULL, 0xE146DDF47311927AULL, 
            0x6E11C08905AC6ADBULL, 0x5F846D6CADB2336CULL, 0xAD27EDC8BB3BF0F3ULL, 0x67363CEEBD985E1BULL, 
            0x5BEC373F9F0481B8ULL, 0x2735BD2246CD3452ULL, 0x66F78ACEE5BF5437ULL, 0x9475A252C13950ABULL, 
            0x343DA908B5F8C45AULL, 0x8AD029A21BC18BF4ULL, 0x8D6E4087D6331542ULL, 0x7E08AA579CFE763EULL, 
            0xD8049DDA7DC50EB4ULL, 0x5733C28FB06E1E89ULL, 0x372422D17540BDE4ULL, 0xFC0FE1502CCE6AC8ULL, 
            0x47BEDBAB19851681ULL, 0x2BE370003ED61495ULL, 0x8D75993BC01DF8A7ULL, 0xCB0D33D9F45D1496ULL, 
            0x9D9A39914B9F68D6ULL, 0x9D4E96EDCA585A26ULL, 0xBE49451823398FC6ULL, 0x3B8C999BA36E61BAULL
        },
        {
            0xE1682EFF4A6808B2ULL, 0x3A33C5CCCBD9E66CULL, 0x6E13ADC027E522D7ULL, 0x10612EEDC4261C92ULL, 
            0xC7CB83B53BE73FBAULL, 0xD88F8598A26AF4EBULL, 0x14AF027A525DECFAULL, 0x2924620A0082BFBFULL, 
            0x72427306D0DC0918ULL, 0xC39E61FFE5217A13ULL, 0x3DE5C6F98E7343EFULL, 0x836DBDE093C14445ULL, 
            0x1B177210D84844F0ULL, 0xFFA594DF6CB8A016ULL, 0x43A6970A86F04A00ULL, 0xF7328A7F8DB45465ULL, 
            0x113F9F2082A73971ULL, 0xEE73BBD726D15354ULL, 0x16835FBE90C53128ULL, 0xD99A0B9527CD5C93ULL, 
            0xF5694C4A7DE31E41ULL, 0x1B70F453218F6173ULL, 0x93745CFEFD476B47ULL, 0xCE0553B5316292CCULL, 
            0xD8F555EFF9C51812ULL, 0xB8C0ACA6886F6990ULL, 0x86DC3F8678A0E939ULL, 0x3E93F2E013AA8D21ULL, 
            0x1C8E29AFBDEE4975ULL, 0xCFE8E10050D573CFULL, 0x4422C0A76DB4A849ULL, 0xDF420E2C9D115ED5ULL
        },
        {
            0xF3D8224B0E475027ULL, 0xBDE18DDDFC53FF92ULL, 0xA742E1277E6757B5ULL, 0xFD58FEF5538E8F8FULL, 
            0x36349BA1B3FC11E1ULL, 0xEDFB6A147A384E69ULL, 0xE520120ACA15087CULL, 0xEA6ED5B5EC98F69AULL, 
            0x29117F66E049B45CULL, 0x2E43AC8E3DFE7827ULL, 0xE52ED611CF2A34B0ULL, 0x2A87C2F5B26AA7F7ULL, 
            0x5D277B8C81DC49B1ULL, 0x5415435F1D20C567ULL, 0x18D4BB07560CEB68ULL, 0x0D3DAB038291D907ULL, 
            0x6C208335AB4F4FC1ULL, 0x6B090940E00AF3ADULL, 0xC9EC54D54B8EC38AULL, 0xDA9E2B4ADFAB62E1ULL, 
            0x301D3FE7076D9A0EULL, 0xCBE00AE0CC72C8A3ULL, 0x9EE8D767039A0E39ULL, 0xDEF4CEC15426B7A3ULL, 
            0xC8F7F98B0428201AULL, 0xB0E66649DC5C501CULL, 0x7469E61A4D115D36ULL, 0xE8C40A931F2D8FA0ULL, 
            0xE7822FF41E7403ADULL, 0x4F350551C5B0C799ULL, 0x6CE2A9883F2A9E35ULL, 0x85D695A6C7F510D3ULL
        },
        {
            0x8316DCBABAB912F1ULL, 0x7C50D3A3397EE8D1ULL, 0x4571FBB782356CB6ULL, 0x5E15B619F9C9D73DULL, 
            0x9FD224C4A095CAADULL, 0xDC5E8D68B5859CE5ULL, 0x808ED17B395574A3ULL, 0x73EE7527B2AC0767ULL, 
            0xBDA88A338DCDD5AEULL, 0x655024E797B00DE8ULL, 0x40FD2482B8D6819BULL, 0x520375B80F9175D2ULL, 
            0x2DB815D81308C142ULL, 0x005159992EEA6FA4ULL, 0x472F676EBB1C1FA1ULL, 0x09DC9267CF5123FBULL, 
            0xF33201120B0C1495ULL, 0xE5115D70DADC6194ULL, 0x80A802CCC9D12BCAULL, 0x8F072590BEBA5C7FULL, 
            0x672AE634B95CFBA3ULL, 0xE51C031718D39C25ULL, 0x5EA0F50B2348CCCDULL, 0xCFF49986890F1BFCULL, 
            0x10AF8544F7510AA8ULL, 0x7316D92D96E031CCULL, 0x261656E8FDFEBC1AULL, 0x2FC577FFC2FEC7E1ULL, 
            0xF3963F55A3427857ULL, 0x2F0C83EEF787971EULL, 0xD53C212653110813ULL, 0xD25CD4C051EEC570ULL
        },
        {
            0x3417F851C10A739FULL, 0x88FC89F4D3435B63ULL, 0xDBB364AF5DE1C3B2ULL, 0xA4CFE569C4C47543ULL, 
            0x54CE7FB7364F0972ULL, 0xF192D31010897908ULL, 0xF8C0079C54224AFCULL, 0xD98BDAFAE9ED8A1EULL, 
            0x4F811D47171AC135ULL, 0x6FF498A2569E6F42ULL, 0x10F582F483A20917ULL, 0xA1406934393081CAULL, 
            0xB06584946D42B6E7ULL, 0xEAD253F3E255214FULL, 0xB16EA1CB3F7D38D1ULL, 0xB3A2F1FB958EF6FFULL, 
            0x65585D2DCE4AE420ULL, 0xF4026231CDA2AADBULL, 0x8384327F6339C02DULL, 0x22FA12029C751259ULL, 
            0xF4EA2684726A2B3FULL, 0xC5C724DC19C87426ULL, 0xF0BA0FE9966066DBULL, 0xDB0A3C98555E0C4BULL, 
            0xBA59BB98052AFDCFULL, 0x57A2F9B54F0FC0F4ULL, 0xDE3F638732700923ULL, 0x380EBB647FC47D71ULL, 
            0x6516059C0A69BAF5ULL, 0x11635E30CAEECE75ULL, 0xFDB89756408C7D26ULL, 0xAA7C78B925B65A1BULL
        },
        {
            0x4D1A2F7CE3154715ULL, 0xE0261DFAB7356653ULL, 0xE2D03C932A85D31DULL, 0x63BACB2BA7954415ULL, 
            0x9F00BC950CB05D45ULL, 0x7770E26525C5D72FULL, 0x7EEDCBF73F5F496FULL, 0xF6A1802E669CBCB4ULL, 
            0x9F493005F1BBC703ULL, 0xC0D264B6945B6DB8ULL, 0x0D134FDEF07B21C6ULL, 0xAA3EEF23F1F52F59ULL, 
            0x4FF5648AAAF2DF7BULL, 0x61A1F31BC9AC8B44ULL, 0x423DD65A920E0D11ULL, 0xD7AC36F04C93AFFAULL, 
            0xF6981DB5F9EA9F29ULL, 0x41B1B5B62203F60EULL, 0x4EDE5C743701FA50ULL, 0xE04ECBF00BCA5319ULL, 
            0x6036EAEDBBC75E02ULL, 0x1848B4CD20682BD4ULL, 0x0E244651A107BCF4ULL, 0xEEF135E6B561DCF7ULL, 
            0xDD36431F2E4FBD3CULL, 0xAC45EEDD174ADC75ULL, 0x9E3D7CEE5F6C126AULL, 0x2519BBF9557AEA28ULL, 
            0xE874C8A1F677E295ULL, 0x48B036DBCC2E7938ULL, 0x5281B0B23EA2E599ULL, 0x168658409F533EEAULL
        }
    },
    {
        {
            0x38D7331302A91663ULL, 0x6616D4F212214402ULL, 0x890621EBE5DBA850ULL, 0x223ABFCD1C2199BBULL, 
            0x167236CA15C6A4D7ULL, 0x61AF68EB1B679AEAULL, 0x412B53B58877C00AULL, 0xCA172E63BB2684ACULL, 
            0xBBEB5EE09195B47AULL, 0x33498B2109B827DAULL, 0x3883DE56304C904BULL, 0x0F27FB151BE1DD60ULL, 
            0xCC69B45B54640AE9ULL, 0x796B69BF152A5876ULL, 0xB0A4B9066BB8955DULL, 0x65D2FC63FFC70966ULL, 
            0x2E5C5AC8963A1F35ULL, 0x4F49BFD19E2BFDCCULL, 0x733847105255C6C4ULL, 0x646434F3389B1279ULL, 
            0xB2A04D20DCA97376ULL, 0xAA3B630463B6DEF2ULL, 0x328FB76C6AF3048CULL, 0x39CF52ED1D91FAC3ULL, 
            0x6E1F9FBD51D7633BULL, 0x7B4759B657F3C97EULL, 0x2DD04470DAF6E921ULL, 0x89BBBA78E80DDE52ULL, 
            0xC7DDE4EE4A227155ULL, 0x4AC4D24185953F47ULL, 0x18A669AE40E9FB98ULL, 0x89149F1DBC225D72ULL
        },
        {
            0x2D05BE1D3C4AE4F9ULL, 0x500979C5358B54CAULL, 0xB26F6F222EE6B967ULL, 0x8ADEB2A224D512DFULL, 
            0x872FEE0D84D2FB28ULL, 0x65AABD72A02F77B7ULL, 0x23B788C76AEB56AAULL, 0xEE9481385163D7DEULL, 
            0xBBE55F9962F57E48ULL, 0x504F07319CD4129AULL, 0xBBE3A20A9C484425ULL, 0x706EC9302D409FD1ULL, 
            0xEABBB1ECECC8BECDULL, 0xA38B96D0E30972E4ULL, 0xAAB246A44D56D46EULL, 0xFF3E5D175F137E04ULL, 
            0x819EB983F4A5B890ULL, 0x1A4782193E736DE0ULL, 0xD9C116F61FC8B54CULL, 0x09A57256D074D1DEULL, 
            0x3544C58C45241E5EULL, 0x02A0F456A201E116ULL, 0x3433304262EADF6FULL, 0xC51DAF9EAB22D0CBULL, 
            0x0F469FB4FAE83B35ULL, 0x2AD0D5DBBED95E33ULL, 0x5AFBB0287B400A33ULL, 0x0FB310F5614289A4ULL, 
            0xEDCC97CB1E510351ULL, 0xB0628481D104A676ULL, 0x93875275E798EE60ULL, 0x9EB5AAF480FC23E0ULL
        },
        {
            0x1B5B030F00A02AC8ULL, 0xDF8AFD9ED556E740ULL, 0xED9A76F5F3DE6BB6ULL, 0x4E9B176A9D94663AULL, 
            0xBD04A14611C4FEBFULL, 0xBB9A31CB97DD9C12ULL, 0xB6828AC43F58208AULL, 0x495A01AFC8C3B651ULL, 
            0xB73F8C1443A382A7ULL, 0x33B458D965D85CEDULL, 0x13EEF7FA7AA85309ULL, 0x2CC7E81AAFB446D3ULL, 
            0x695D173EB556A1CFULL, 0x0E6678AFE0AB0D9FULL, 0xED5D482662D8CE28ULL, 0xDC6FBAB30F5CC423ULL, 
            0xA45FE04C7E379758ULL, 0x0055B0490BAFCDE6ULL, 0x3111BF81332D6AB2ULL, 0xCB365C9D44AD2FADULL, 
            0xDE91FD27C147F934ULL, 0x0B41725F6161B458ULL, 0x6ADD4D6B8336F076ULL, 0x50DA898A72900EF0ULL, 
            0xA48B29DDFE4823B4ULL, 0xBDF577AA8D170A08ULL, 0x22649D302505D9B6ULL, 0x861453C118A6C8BAULL, 
            0x7645181114296618ULL, 0xE5D2444A1D246E08ULL, 0xEBD0C1DBA9D2622FULL, 0xFE4C0E6870D00D1FULL
        },
        {
            0x7BF4A67881D6FC5FULL, 0x6246BCDC7D3BB1B0ULL, 0xE18F1D029118E19AULL, 0xA46A8C35BBA14F94ULL, 
            0xC8EB8CA7B0861FB1ULL, 0x9BD5A644911CCD43ULL, 0xF81DD939EA9445CAULL, 0x932A434C6B9F5168ULL, 
            0xE29B0A08C0C350DAULL, 0x9B7248D0B8CC3412ULL, 0xDD30852AE207AB85ULL, 0xA16BF626672F6EA6ULL, 
            0xD36B8D0C9CA6FB75ULL, 0xDC15EAF58F245114ULL, 0x22BADF1C77758133ULL, 0x1F3A9BDF4184E85CULL, 
            0xE4E938B2966C432EULL, 0x4994255B45C82179ULL, 0x9960C8991E698DC8ULL, 0x3D963336FB594DA2ULL, 
            0xE313D0992AFBF7CAULL, 0x43CB0DC1C4C440F9ULL, 0xC33AAAE83EB56E2EULL, 0x9098A4B6EB60732AULL, 
            0xCA8080B6B34C9807ULL, 0xCC40A75F672A3538ULL, 0x0FADAB60C5568055ULL, 0x5282C441E0EC4CC6ULL, 
            0xF9518835C41348F6ULL, 0xE72C69839F779F53ULL, 0x2E7FF050300C23CFULL, 0xB4DE23CE644C3FAEULL
        },
        {
            0xA3598E556276155EULL, 0xF9FDA63632AF0EADULL, 0xE2024F4719DA21B3ULL, 0x3E508CC9B15FDBB2ULL, 
            0xE2822D3A7F5B6B1DULL, 0x5558F406560452FEULL, 0x0C9B2A077B0EC135ULL, 0xE140F2E34C088CB8ULL, 
            0x49C2BBC7DF84DC55ULL, 0x75264148675E8C35ULL, 0x2E3334FA94FF94C6ULL, 0xCC522B9B91035364ULL, 
            0x89395916CFA0F98CULL, 0x8B4F7779C7AB03E7ULL, 0xD7891CC1FDB38843ULL, 0xF470E8FED75D00DFULL, 
            0xDDE25C58D7C029B2ULL, 0x6DCD5CE532B67DCDULL, 0x8E9665974A637054ULL, 0xE041EF9316727F1AULL, 
            0xA62FFCB6E304402CULL, 0x8D8D694D3012C955ULL, 0xC11529E55B1FE745ULL, 0xACF4738D7DDB0672ULL, 
            0xBD548230365B33A5ULL, 0xE05F7A59591F3EB2ULL, 0x13AFE0D619207B63ULL, 0xF5855F5F5CF755ECULL, 
            0xCE1E6790295DC287ULL, 0x76EAD79739B984D3ULL, 0xEE9F276E15236E39ULL, 0x870A956CE8810D12ULL
        },
        {
            0xF5FBB75497828FB1ULL, 0x3A39E2C9466FBD5DULL, 0x6B0A41D0CF1E7C89ULL, 0xE82044B125DC70F6ULL, 
            0x243CAA02FD5A81D7ULL, 0x60AFA2D051513723ULL, 0x915BC5173B58E6B7ULL, 0xA75C6D134154C8F1ULL, 
            0x4815B6F3E5558363ULL, 0x3F874455242D3896ULL, 0xC84C0D67D51EE006ULL, 0x909955FA76772331ULL, 
            0x43A81E9309CA8E97ULL, 0xF07817778347CD2DULL, 0x274D200F86138466ULL, 0x67705CF7636E427FULL, 
            0xE0B15045C6F69FDDULL, 0x908EE7165A1D7611ULL, 0xFFD74BA9AFEE086AULL, 0x42854D2E42B6F6B6ULL, 
            0x6D3B0C3D6C6B7725ULL, 0x3B2BF1B918D80C47ULL, 0x03C071296291D686ULL, 0x506AA6494830D4CAULL, 
            0xDD5C003724CDBA56ULL, 0x5D661E9757FB9F71ULL, 0x7E68F2F04E23EB9CULL, 0x22A82E2A8F5E46DCULL, 
            0x8B94E487C3B96A68ULL, 0x5809217E2F800C81ULL, 0x3368178905B9A17FULL, 0x1E8CD7ED2C23ABADULL
        }
    },
    {
        {
            0x98C223A276262BDAULL, 0x2025645D155C1BB9ULL, 0xEBC893EBBBE10015ULL, 0xCD82BCD5E6A8ECC4ULL, 
            0xDAE9F11DA6089D97ULL, 0x7CC1607E277E5380ULL, 0x1A9854EA57095116ULL, 0x0506FFD9E2F55436ULL, 
            0xF8EE79AC4EF553BFULL, 0xEFEE75A0DBD12117ULL, 0x86B2CFEEA5264C36ULL, 0x1982163834FB6426ULL, 
            0xC40B5A7B1BF1E366ULL, 0x406C4EAA8787E028ULL, 0x80E403FE67EFF7EBULL, 0x79D71C57598B2708ULL, 
            0x223DBF79F84EFCDCULL, 0x8F7005FAAF9C6855ULL, 0x1971C3524EBEE09FULL, 0x5AD505E9224972B3ULL, 
            0x2FC6F9DE0823D52FULL, 0x257186E00AA719B4ULL, 0x2EF7C73EFE46121CULL, 0x15C1188AF9BC1850ULL, 
            0xA7E6EB22E0A675DFULL, 0x3CEC36E913AC0E7EULL, 0x92999E9A00DF0F5CULL, 0x03C0396433C6F0F9ULL, 
            0xB49DDE8693887458ULL, 0x56DE9DBD9B4BBEFAULL, 0xC7FF08355B9A3E7CULL, 0xFF7D31BF7A0702F4ULL
        },
        {
            0xC96BE6C7813D5DCBULL, 0x0D08AFA744058AE9ULL, 0x1FD65B01312E8EFAULL, 0xF95517F06276D4E8ULL, 
            0x465EF3C63AF6A1EAULL, 0x21E6E8A31684ABD9ULL, 0xD3CCCF0C23C80591ULL, 0xC4B4BDCEBBD87073ULL, 
            0xF5C7DB4681967FF5ULL, 0x27E246ED16BAAD5CULL, 0x7A8292784467CE10ULL, 0xDFDE63F89D1A81F0ULL, 
            0x7D64B65EDC02B2C9ULL, 0xB2A3508FAB93501CULL, 0xDE05E751F309287BULL, 0x7FC5BF701873F8B5ULL, 
            0x31E74B8ED0F2E08BULL, 0xB809FF31090463E6ULL, 0xB8D84167E75ABFECULL, 0x96DEE48BD06C56BAULL, 
            0x5576952469EE6349ULL, 0x81E6AF7B711A4AEDULL, 0x3EF01666AC44F7F6ULL, 0x2557EB384EEFB0FAULL, 
            0xAB00C69EA7E3ADE7ULL, 0x974E117073F3C45DULL, 0x75D0C650EDF379B1ULL, 0xF738506258DEB58BULL, 
            0xAE39BE8590E21C1CULL, 0x9A73849742F78C1DULL, 0xF3897BCC5A0DD9F1ULL, 0xCC2A7B725C025F17ULL
        },
        {
            0xD8DFF1F682A4D784ULL, 0x099FE45775ECFF13ULL, 0xD5DDB86A84B49E00ULL, 0x4F34D664ACC9ECC3ULL, 
            0x7C3123AE7D521426ULL, 0x3A84CAED2A2B7577ULL, 0x33B87B5F306FF322ULL, 0xF9084A7A844A94C9ULL, 
            0x57FB1CE9BBBA9199ULL, 0x85FCFCBBB4A61D70ULL, 0x44260EBE140C3D53ULL, 0xC870AFFCE1512B6FULL, 
            0x8C50F45F9D180BC8ULL, 0xFF1798DB4581262AULL, 0xBED4E1EF1591A967ULL, 0x545A892134FB5FB4ULL, 
            0x1D0076D325521915ULL, 0x658BB68CB609EF69ULL, 0xE2EDFC33736E3C5AULL, 0x64E96A6444436BE1ULL, 
            0x05F52602E6C2BA60ULL, 0x42F35B4016521B60ULL, 0x877C978C019C7D51ULL, 0x6A0C700CBFD871A2ULL, 
            0x2DB9037FB27F996DULL, 0x09B6735D5C7B8CB1ULL, 0xFB9A9B27FAFC08C6ULL, 0x9728DCC8F5293D61ULL, 
            0x7CE87D3FBE70B9D5ULL, 0x1328B5FC9E23AB00ULL, 0x9509EBF5F6C5FD4DULL, 0xCAD080FBEB45B684ULL
        },
        {
            0x3470C33152B88B20ULL, 0x3C2A2FB063936D10ULL, 0x3A5DC5E59CD29888ULL, 0xB679CFA93727A220ULL, 
            0x848B5BB81AEDA6B8ULL, 0x8A8F1D16407524DAULL, 0xABC98C4F8F649E32ULL, 0xE90A885DC69F43B1ULL, 
            0xA3FA5ACD88D0BD4BULL, 0x98FC54FCA97592A1ULL, 0x580FE1B73A341BD8ULL, 0x4DA02F6FBA419B01ULL, 
            0x8DB1E9DE8BEE64C8ULL, 0x72EBB48220FEC976ULL, 0x6E52094EEEE44392ULL, 0x89AB5DFEAD4B7E01ULL, 
            0xDE83A23516879AEDULL, 0x363607A70DD1825CULL, 0x56CB49F8FD5EB3FBULL, 0xB67A0237EEB3332AULL, 
            0xF546C9886E675F27ULL, 0xD21ED396896735DDULL, 0xAA01783B6EF5FB43ULL, 0x6C21BCCCA881BF39ULL, 
            0x9D8EE54593026C11ULL, 0xE93A1050E0BE5DDEULL, 0x3F8490F3C6D5E650ULL, 0xA69F1B5AD9FDA267ULL, 
            0x5617C7C1904CC4AEULL, 0x6900C3DCDA91BE2DULL, 0xD13CB1809271F10FULL, 0x078D0E9DFDEC02DCULL
        },
        {
            0x0DDB09826C06735CULL, 0xCAF638412F51EDA1ULL, 0x768E7D1AE71D6F88ULL, 0x82A778D9EE1998EFULL, 
            0xD9F17755118F77BFULL, 0xAE4A511EC04A974DULL, 0xCFE727A06BD25022ULL, 0xC9EE9641117FCC0AULL, 
            0x5792E3B9865C5A14ULL, 0x03E8F3281B3B3D25ULL, 0x238C8887D1145E16ULL, 0xBCCCF1D05F90768AULL, 
            0x29420C112FA84996ULL, 0x553AA115E428D379ULL, 0x8A657378C8A3887FULL, 0xC99E73A81BA9491DULL, 
            0x15B89B5C5B2471FBULL, 0x86D8894786C8B3FFULL, 0x00735385360824B2ULL, 0xCD42D5A09945A3C6ULL, 
            0xDB54B007126E79C6ULL, 0xA902912362378050ULL, 0x3D052C0EC37224F3ULL, 0x6055555548E1DFC7ULL, 
            0x7593C051F31A7E8FULL, 0xD3FEAABC38D6472FULL, 0xC798250D0EDD3E49ULL, 0x79826C1DA3FF97A5ULL, 
            0x7225DC126BB9CDB2ULL, 0xF19D98F4AFCD30EAULL, 0x1BA3E98BCA628A62ULL, 0x27A609C15DD312C3ULL
        },
        {
            0xEAA0324865131B39ULL, 0x5225AEB575C65352ULL, 0x54EA96A60C50E69CULL, 0xB4C7EDE5A149B411ULL, 
            0x67BFF3338C950F94ULL, 0x873C29C86985C839ULL, 0xBE3E9D24507C8BB6ULL, 0x506B9CB768AB757EULL, 
            0x72F8B4A30007CA8FULL, 0x974F77F21849558EULL, 0x2A952995ECE9C3F4ULL, 0x376F1E1556F06E6BULL, 
            0xFA95D18E84CCE869ULL, 0xF87D991E943BC810ULL, 0xFCAB12F914DE9C18ULL, 0xE76C401016E2AFA9ULL, 
            0x6BC3E37DC0EA599CULL, 0x3035068E24FBE92BULL, 0x8AC2F87D11FDD56FULL, 0x4CD2AF2DF51A02D5ULL, 
            0x0E00C9F9C08A1CB7ULL, 0xA741874DB1FCFD7CULL, 0x7C2D770CADA09E08ULL, 0x5A826D16F55BA34BULL, 
            0x8AFBBADE2480AB70ULL, 0xD2883D5D39D28B02ULL, 0x8DF8A1E6DEE1A048ULL, 0xC4880756F0DA18EFULL, 
            0xD042A89AEB949305ULL, 0x3DC2C567DDD6954AULL, 0xA6C89F46D502CB16ULL, 0xE8759C568AFBB688ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bellatrix::kPhaseAConstants = {
    0xED8CB484D74AC4F8ULL,
    0x5BE93DB8D176B556ULL,
    0xB4982AFB03CBEB89ULL,
    0xED8CB484D74AC4F8ULL,
    0x5BE93DB8D176B556ULL,
    0xB4982AFB03CBEB89ULL,
    0x963E6D06B40345A4ULL,
    0x2D7DFFDAA9D91ACAULL,
    0xA6,
    0xD7,
    0xDE,
    0x3E,
    0x87,
    0x76,
    0xF2,
    0xF5
};

const TwistDomainSaltSet TwistExpander_Bellatrix::kPhaseBSalts = {
    {
        {
            0x346D635936D95F90ULL, 0x7644E6AC25CD675CULL, 0x43760840CEB0FEA3ULL, 0x440A91604EB5A684ULL, 
            0xEA1C38A326982048ULL, 0x27F957423A14090CULL, 0x911AEE8BCA767BF4ULL, 0xA2B07146CD61E753ULL, 
            0x29F4FF81018C5DEFULL, 0xDD2864D3ED1552C0ULL, 0xFB79EF1AF7B4948BULL, 0xFB983B5EDBD17F0BULL, 
            0xA4D4E7DC26035314ULL, 0x2E3C7860B5990D2AULL, 0xBD61F0FCAD990A6CULL, 0xE48BDFFECDB1D17AULL, 
            0xB8795898B0FDFBC9ULL, 0xF38F24A44391F3AFULL, 0xEF9A095DEB30C5CBULL, 0xC0433476B8BDB3EBULL, 
            0xF16E6A24C22E7524ULL, 0x073AAC813356F349ULL, 0x88B916313AB0CEE4ULL, 0xF4013984C0355055ULL, 
            0x445929C0D52290B5ULL, 0x040FA48266C0E913ULL, 0x31298FFAC5F00872ULL, 0xC872C646A48EBB04ULL, 
            0x26438765F6251988ULL, 0x1CD8F28484EDEA00ULL, 0x26CDC58012FE0628ULL, 0x8525279920303D6CULL
        },
        {
            0x31E9D409C7F5C9E7ULL, 0x1F805A0DBD1909DBULL, 0xC5A45F4FB1041043ULL, 0x1773858623343D43ULL, 
            0x227455AF09936BD7ULL, 0x081C0D4E9122237DULL, 0xAD27AB307F9F2F88ULL, 0xED372CD2F6EAF0E0ULL, 
            0xFF081D6C8DEEEDFAULL, 0x5B55A1C82B2C4AECULL, 0x30E5995A6FBE9DD4ULL, 0x6896ACDC4D09C89EULL, 
            0x4CB0A3F04FE523A2ULL, 0x013C61C3B9D5647FULL, 0x3E02BA3A4D9CDD2DULL, 0xEC14239A32BFCCECULL, 
            0x4DD21C9A5655D22BULL, 0xE6AC9C46B091648FULL, 0x0573B054AA39E6F5ULL, 0x8DB1866B398BC307ULL, 
            0xA2C0F0435D2A547AULL, 0x57ED03CA67F3FD83ULL, 0x43A1BDD87CBF1229ULL, 0xC1EE25F6DD8EAE2BULL, 
            0xFE3B3B13CBB750C4ULL, 0x3E92CA8DA17E5213ULL, 0x40F02E08798DE159ULL, 0x563CC1F431488CE5ULL, 
            0x373D3B91647AA435ULL, 0xB78CF19F65111EAFULL, 0x59951D50C9FAE306ULL, 0x86D298F85E8465C3ULL
        },
        {
            0xA8B514C64DE46764ULL, 0x4762578E26F2B97EULL, 0x12DA612994C75500ULL, 0x7041B7F8897F4CD6ULL, 
            0xC8F79CE35E1ACF23ULL, 0xE7DB2727B94A17DDULL, 0x385255D7C4E12C75ULL, 0xE6A2CC5863D01E79ULL, 
            0x589229F8BDA4389CULL, 0xCF7495152C05ECC4ULL, 0xCF6045332974CB1BULL, 0x907680B3F13E5DF2ULL, 
            0x190C950571425F24ULL, 0x6ABC2A042CBD0429ULL, 0x26F4529BAB020A0FULL, 0xF5A6BBF5F5AC4496ULL, 
            0x4C9BFE0205F948B5ULL, 0x8D7F71E877E21345ULL, 0xBC8048D5A244A8ACULL, 0x86F50F27EDC70CE3ULL, 
            0x7C11EF013402E696ULL, 0x87A43575C3353379ULL, 0xF0E08A188A87D94AULL, 0x035B71F2F0B272F8ULL, 
            0xBD204C8A5133780DULL, 0xDD7CB85A5170965EULL, 0x81DFEDE3DA23F3D7ULL, 0xADA1F420D5E85011ULL, 
            0x222B1F915230E0D4ULL, 0x5A341539D8A613F3ULL, 0x9C55A82D6F83BA1AULL, 0x9DF3D0FD52E11768ULL
        },
        {
            0xA441441ACEE63585ULL, 0x625267C0E231D67CULL, 0xF749B3DC52295CCCULL, 0xF630563A28FCF8F4ULL, 
            0xA92E8435D80F9782ULL, 0x599880CFD3D63B12ULL, 0xACA40A67E9DE405EULL, 0xC91ECA2CD4EAA124ULL, 
            0x93301D68EA7AF50EULL, 0xD6C5D4165485A288ULL, 0xF5E133F59DBF64CDULL, 0x5149A5F5984A45CDULL, 
            0x773096B4D1C67FAAULL, 0x6163FE00545ECE9FULL, 0x88C9EAC3E7B9F96DULL, 0x3A067C7D48106065ULL, 
            0x7222DFC32F46F4FDULL, 0x8DE4763FFB09C2EAULL, 0xF14BFC75291B6731ULL, 0xAD66D8CEDF283AEEULL, 
            0x9F4C558DFEB0AA03ULL, 0x1C438B6608A58434ULL, 0x2A246264828C73F7ULL, 0x111E9AA723BE1783ULL, 
            0x091463E8ED5CC5FFULL, 0x60C266AF9058679BULL, 0x248B90F2B9966346ULL, 0x45444C63FBDE2DB7ULL, 
            0xC11D38A2096DE29AULL, 0x5ED7F25D2DF97569ULL, 0x755238AA20CD2877ULL, 0xEF667280C3F05226ULL
        },
        {
            0x43B13F2D13668C3CULL, 0x27D4CBACDCA7764DULL, 0xE14D7D2DFA7A6728ULL, 0x479EC9FA0BA2248EULL, 
            0xB055F629FEC1DD04ULL, 0x86832F33F6941468ULL, 0xEFF02B90274A7578ULL, 0x3437028952DE6817ULL, 
            0x688CAAA188401D88ULL, 0xB5FBCAF29D01D885ULL, 0xDA610BE73B1DFD9CULL, 0x2C6212E32406E5D2ULL, 
            0x79348FB7643768C6ULL, 0x94E1517AF2BE7D1BULL, 0x9F9B48762D206009ULL, 0xF4CB1502D3E4D7B7ULL, 
            0x2477D780CC276B27ULL, 0x6129EE7417852A13ULL, 0x1C4AC294858081A5ULL, 0xE4C83F72207029BDULL, 
            0x518A84B050B796FAULL, 0x7206F6399FABDAC3ULL, 0x397983A63B7C726EULL, 0xD9A163A5BB6D0420ULL, 
            0xACC0E98D19FE45D5ULL, 0xC64474502AE1D1B1ULL, 0xC99472FCA5AEF149ULL, 0xD1E4386EA3D22DC7ULL, 
            0xFB3DAED2C7F2FD14ULL, 0x3B55D1D8B7AAFA1DULL, 0x612C4744C7452428ULL, 0x085FECFFEAA686C4ULL
        },
        {
            0xDC9E7AC9A44B2A38ULL, 0x28B0CC48E7246944ULL, 0xB3A6A8CED5B70557ULL, 0xAE4DE3EF7CBA716EULL, 
            0x501B59345D34C3C9ULL, 0xF98D4AC92096D706ULL, 0x27D1331AA46590EBULL, 0xD7CFAC39AE40E070ULL, 
            0xFC3E93BC418ED3DEULL, 0x06C93B845B9E326DULL, 0x6BBD32EE80B0177EULL, 0x63C3CAD38FCD7905ULL, 
            0xB4636E750FD3F01EULL, 0x28E26D5917DC8FDCULL, 0x1BC41E5C6000A05DULL, 0x29AF0EE04EAE589DULL, 
            0x6ECF1B9EEF81F1F3ULL, 0x937BB73E938C722DULL, 0xAAD3F0C34B846B81ULL, 0x452233AC9893F099ULL, 
            0xC6985A7EBDC66D10ULL, 0x42237035635DB8C9ULL, 0xE13ADB579D29D2B3ULL, 0xAA514886198AF27EULL, 
            0x23CCF6B0ECBB0313ULL, 0x93A9C7398C85BCB4ULL, 0xCBCB283CFE40080EULL, 0x32857F52C0CDEFD7ULL, 
            0x7B03CE1C7843FD7DULL, 0x818AE9A9E1BD4381ULL, 0x5F7CAB7C3802FDC0ULL, 0xC6632A1A840C4BD1ULL
        }
    },
    {
        {
            0xF1618EB5F372896FULL, 0x7A53A718AF3D71A9ULL, 0x2CA190C3D22C7EA0ULL, 0x950EC9FCCE5F297CULL, 
            0x3D16697F5056A731ULL, 0xBFC1273FBBBDA5C2ULL, 0x16F5D316D80D47E5ULL, 0x51128A2230AFD5CCULL, 
            0xDBF34A6BD86F84E4ULL, 0x6AF4BF00FCD090B3ULL, 0x92C4B9AA491FA2DDULL, 0x07BEC961EB0DA96FULL, 
            0x7C456C151D185FBCULL, 0x5D80B00FAAB750B4ULL, 0xC7BA84C92BA23BC5ULL, 0xEDB05181FCD2686BULL, 
            0x983C79766504F9D2ULL, 0x442425A57B6C537EULL, 0x25750D97847810D2ULL, 0x6C2C7948D115BEA6ULL, 
            0x75312F52734BABF6ULL, 0xA63FDFC702C612EDULL, 0xA26CA0B1502B9A63ULL, 0xCF591AEDA1244547ULL, 
            0x21D73F7A25D8A09DULL, 0x06D5B8CD3F54A896ULL, 0x8F6CDC128BD1D2ECULL, 0x1F809BB87F2233E2ULL, 
            0x2B264AECDDCE5CCCULL, 0x1538F4C547AB8A52ULL, 0x9F826C90019BD61CULL, 0x106486372A15472CULL
        },
        {
            0x4009DA5A186C970DULL, 0x64E353D37BF875C1ULL, 0x63F4A418233AB4EFULL, 0x16F3FA9C7DB4A638ULL, 
            0x258BBCDBB11DE47FULL, 0xC27C504F662AFD61ULL, 0xA9E32E377BAC4324ULL, 0x75EF4271702EF0A1ULL, 
            0x1E2398ADAA762517ULL, 0x65C3DEF690A79EFBULL, 0x37101414A2C73EE7ULL, 0x9851EA1420B46F71ULL, 
            0x86DC6B21516C793AULL, 0x3D2F262440AFD0B3ULL, 0xD284C7F588D622B9ULL, 0xF81BAD27B7CDA3C5ULL, 
            0xF21BCA84BEFB2D35ULL, 0xFBA733A410F0C3DBULL, 0x08B214A36CD809DCULL, 0x66944E5C0493F255ULL, 
            0x8630EE28989654EBULL, 0x5083F45EEA80B1AFULL, 0xB6E559EEEBA7BAB5ULL, 0xA2BB605D183CD8C6ULL, 
            0x631200DFACB1FCBDULL, 0xF2B341CAA884986AULL, 0x884B77AA9A61A781ULL, 0xE9DF67E62C1EAF6FULL, 
            0x24925B08F03409DAULL, 0xE990A08470BE4A55ULL, 0x7B26349347675452ULL, 0xFBBAE7791CA18931ULL
        },
        {
            0xFD7B356177C25772ULL, 0x70494B4E5834784AULL, 0xAE6987E7B4770C2AULL, 0x6AA9CE274EE33C0CULL, 
            0x9E4F1815AC6B65CAULL, 0x3C1F577D3709A4A9ULL, 0xDEC315C1E6BCEAF3ULL, 0xE157F7CDB6B8950EULL, 
            0xC1905A07DFB92C7AULL, 0xC838EAC4D5F88ABAULL, 0x9089F12CA705DBE6ULL, 0xBCCE8BE5AC58BA3AULL, 
            0x3B933ABB13A171B9ULL, 0x647CF4F2E4360001ULL, 0xB178C5B6112448B9ULL, 0x51D1DCED1293031CULL, 
            0xC5D5F3B2D0BC44C6ULL, 0x315B42289F88F386ULL, 0xB1F541C82F623F24ULL, 0x67DC1C461AE2C8F8ULL, 
            0x9B4E497EF7FD00BFULL, 0xF0F672A2D796A304ULL, 0x8A3920A5C9CE8D66ULL, 0x786740C13FC057A3ULL, 
            0xE0C3A8887809FAA5ULL, 0x8DFD5674CEA94EC9ULL, 0xEE95FB5EC600D6B8ULL, 0x55EBBF1342919E7AULL, 
            0xA5144D44886A46DDULL, 0x7DAA1C2464859DEEULL, 0xF6E8AA0D98B23C49ULL, 0x37E884A85C5C06ACULL
        },
        {
            0xD4657DB3E96BC258ULL, 0xAB2F1333A2CD1D0FULL, 0x54D2A2B3EA54260CULL, 0x6FA09D4C81489AB9ULL, 
            0x917DE6F55838304CULL, 0x104817D1BBB53D16ULL, 0x52107B32E5C831C0ULL, 0xEE6AA2774533D462ULL, 
            0x3C0A3F7912B37FFFULL, 0x010F75C09F454886ULL, 0x5F700798C3C09E54ULL, 0xC556A1DB603B71D0ULL, 
            0x804373C340192276ULL, 0xCE93546CA8C29700ULL, 0x0D95E537198EE68FULL, 0x587137FF5733A716ULL, 
            0x5345BEF79E563DDDULL, 0x21FD28E81BFF6C8EULL, 0xFE3761E4E9C58773ULL, 0xBA71656EF85A2452ULL, 
            0x3895CDB74951A502ULL, 0x7C4D79493FE433A3ULL, 0xAF86BA1CC6C1D265ULL, 0x3F2159768ED7677DULL, 
            0xD28BC6FE0E7FAB62ULL, 0xD780C21C0B20C52FULL, 0xC132228F1DF9587FULL, 0x69884EFCDDDC90B8ULL, 
            0xEEE46212D361ACA7ULL, 0x3986BABD020915FBULL, 0x2843BBFA1C64246BULL, 0x2C263FBA1CAC4512ULL
        },
        {
            0x172ACA1526A99E69ULL, 0xC07A6F983DD522F3ULL, 0x55D29997EF8D9F0AULL, 0x28BC1B0980A14478ULL, 
            0x7F3EC3B412BCB3A9ULL, 0x855EF40F6CA30CACULL, 0xF65336FF38136ACDULL, 0x6412D56F2EC219EEULL, 
            0x12116F719B527812ULL, 0xC7F7BA66BA8B83DAULL, 0xDEE9E188016DEAE9ULL, 0xA8C81BF95613C32CULL, 
            0xC19687C92B83B699ULL, 0x64D44A3329550F61ULL, 0x262C9461B7531F47ULL, 0xF51FBC953332102BULL, 
            0xD2EF34D78A5F734AULL, 0xCD4C7E9966886C72ULL, 0x34267E3486BE3E52ULL, 0x7BD3362C57207A0BULL, 
            0x225812869192ED5FULL, 0xA6538FADFD4C44B0ULL, 0x225307BD8F79D578ULL, 0xF6D858A59B2FE7CAULL, 
            0xA4374A9FDE6B86BAULL, 0x57B6E8D5A223E766ULL, 0x8AAE8B9F30FCF00AULL, 0x7D5864F3C807F944ULL, 
            0xB05FFA256B0C57E8ULL, 0x981789A4685D6BBEULL, 0x0CFAA69D9C9645CBULL, 0xC627EA20DF51EBD6ULL
        },
        {
            0x06A6154D222030DBULL, 0xC9F6CB54C1283B66ULL, 0x7CF75A245C0BE41AULL, 0x8AB0982B4E304887ULL, 
            0xE4B0123DCC8579A0ULL, 0x016E90172B7C3896ULL, 0x27EA51CD36B8FDEDULL, 0x597C7B2B1BC0233CULL, 
            0x22EE02261298A644ULL, 0x41A600F40B31E0B6ULL, 0xE498374CF79A6CAFULL, 0x9D608183518A9ABBULL, 
            0xE4BB648C80C43EF5ULL, 0x1938D87BDA468B68ULL, 0x4946371206BE9C42ULL, 0xDB7B738F2ED57A6CULL, 
            0xA329808A48D2D1F3ULL, 0x4DF47331605BFCE1ULL, 0x9E6719572AE5D7DAULL, 0x741CA1F19BBF679FULL, 
            0x6BBCF08DAB2F650DULL, 0xD40A433244D07FB8ULL, 0xFF1E89009CCCF140ULL, 0x636202568E461AD6ULL, 
            0x1F37DC38CEBAEB56ULL, 0x3C5563007E16EE7BULL, 0xFA711711257B0BBFULL, 0x55F63B1B630E23CCULL, 
            0xA2E029F9EED79D5DULL, 0x81C01ED76C763A09ULL, 0x3B48149966AD4B17ULL, 0x41D523E1AED18132ULL
        }
    },
    {
        {
            0xE27D5AB583B0D089ULL, 0xAE628E60EF71D7A4ULL, 0xDD292DD50EAE1AEFULL, 0x2313C8ECD73F8C71ULL, 
            0x38FAFC15A3566BC3ULL, 0x846FA856EC2462D2ULL, 0x4FC5B039440FF635ULL, 0x8154F9DF4798F49AULL, 
            0xE920CCBE55DB7C7EULL, 0x5EA0E829C3F5C819ULL, 0x2000B2114C7A98E4ULL, 0x12ACFED4F775733AULL, 
            0x8B5FAB058C1E5374ULL, 0xDD1C54416B2D6688ULL, 0x7E63F33E158282BFULL, 0xB798B299D887800EULL, 
            0x95A401CEFFB0A1CEULL, 0x557410728FADBD2AULL, 0xB44EA1FB55922CF0ULL, 0xEAA655ADA331D858ULL, 
            0x21D2FA1F6FA24E7AULL, 0x08D3322F96B8A399ULL, 0x103B8C76327A1777ULL, 0x85B1C8E7F96C5D3AULL, 
            0xEBDAE7374631D564ULL, 0x9AA1BC86FC6D1743ULL, 0x72F2C6F63F4E8514ULL, 0x0817272D53334D21ULL, 
            0x740482F03E9B4D7BULL, 0x2E394140C2F8620CULL, 0x858A82B04B6C6D11ULL, 0x549DF7C3EAF94E2CULL
        },
        {
            0x58B9C6446DB51E9FULL, 0x20B83C2560B1261FULL, 0x7FC7FDA1DA14C6CBULL, 0x286D3A8EC898362BULL, 
            0x0A63B2B8EAD72438ULL, 0xF33F59DBFC546266ULL, 0x507EF1640FDB26A7ULL, 0x033017FB79DC7051ULL, 
            0x50F76F782B14F50BULL, 0x07ACC4F47BCC812BULL, 0xE1AFC72FB2230AF2ULL, 0xBCE11EF214961CF3ULL, 
            0x6E1459F2AEF8181FULL, 0xC4E55095CBD325A5ULL, 0x1B39C8DE5B35C138ULL, 0x41FCD61BC1929961ULL, 
            0xE730C14F09AAE682ULL, 0x57180B1F280461E4ULL, 0xD66E732E00392BE5ULL, 0x6A6A934944323343ULL, 
            0x126DA85B1E3ECA65ULL, 0x2660B00AAC0B2414ULL, 0x9C7DEAA5DF4303D9ULL, 0x75AD6BE69BCCD52EULL, 
            0x04EA68CEF90926B1ULL, 0xD35D281707CCEAF8ULL, 0x236A227E2336DBA4ULL, 0x6D09B7CFFF7F4E11ULL, 
            0x2103A5288327E92EULL, 0x587BD7447CA6085DULL, 0x6045A05F1621FBF2ULL, 0x154010078621FCC4ULL
        },
        {
            0x3A781BF70B26557CULL, 0x93736646E7D678DDULL, 0x66972C594CD2E55CULL, 0xE3EB665EAEFB1087ULL, 
            0xAF3178B81CC327BEULL, 0xBBA09B3AC61635B4ULL, 0x54506EA0A4107DE4ULL, 0x63545A7F72D186ABULL, 
            0xDECFF5A395043720ULL, 0x90491C85EB77661CULL, 0xDDA041C7D7B80B30ULL, 0xA34EBD818E0DF796ULL, 
            0x29494863D47F42EEULL, 0x69A9C47A685601C4ULL, 0xE8433165628AADF7ULL, 0x4D5F01B52CFCF506ULL, 
            0xF6002D98D0DBBC52ULL, 0x04845E089A36BB3DULL, 0xEB3648BB2CE34AD0ULL, 0xCFC9F6383567306CULL, 
            0xE646B34B58587790ULL, 0x11FC4AA62CDF3B30ULL, 0x24BF8B969280C381ULL, 0x9587AA337CC2E2FDULL, 
            0x3D144BD50580B6BFULL, 0xC64D923DB83641A6ULL, 0xDF9C6A7D6EB9F5C3ULL, 0xDA5B40BE36422870ULL, 
            0x449AAC9BD62EB3E1ULL, 0x851FE43C307E8A60ULL, 0x8701AC44B40F75FFULL, 0xA36C45C9AD072C32ULL
        },
        {
            0x7FE455CFA7A9B7FAULL, 0xEB9929DA2F1F8614ULL, 0xEC007B316DF642E4ULL, 0x6741B4E5BBFED3EBULL, 
            0x75992F89BA4B7580ULL, 0x520822E0DEFC5D04ULL, 0x00B067846E701239ULL, 0xDB098F6038608CFAULL, 
            0x0870F321B2095709ULL, 0x18132C1F7C995563ULL, 0x61A70B655D8FF2A8ULL, 0x25F0E3F4B6AE21EEULL, 
            0x8C129945786815CAULL, 0x54ABF5F25C72BBDCULL, 0xB24A4F8C84CAF407ULL, 0x9052834E8F03C3DEULL, 
            0x204627D791111C07ULL, 0x035A939DFEFC3620ULL, 0x9645A19FE1B9B887ULL, 0x4B7D53E2A590ECFDULL, 
            0xEC508E41BEB26DD3ULL, 0x45BB5B4E431AAE7FULL, 0x6993449D6C89C7FCULL, 0x1F879586EADB9EDDULL, 
            0x6BB243BCC9FB991BULL, 0x494838719BA0B751ULL, 0xB5BD236C0C3799FDULL, 0x06C4E175256DDEDBULL, 
            0xACCBB14C4207C1DAULL, 0xE41D9FD6D6B84883ULL, 0x8781B52E0B0BEF7CULL, 0x62250871FA2D1764ULL
        },
        {
            0x9115CDA53FAEA3ADULL, 0x4D0E49B66A91891EULL, 0xA3A610004077C51CULL, 0x50A2B9FD2A38362AULL, 
            0x42C41ED1759A5863ULL, 0xAB420192220FA6BAULL, 0xEDBAE92C2C5E9114ULL, 0x732E3A9DBBB448CAULL, 
            0x2DB25A2DD4B5784EULL, 0xC580DBB9C9761668ULL, 0x3C08245149FFD1C2ULL, 0xCF3522BBE4CF1AEAULL, 
            0xFC78C71861711ED6ULL, 0xF91AC73111772B29ULL, 0x078CBA971FBB74DFULL, 0x6EADD969AF7260A9ULL, 
            0x20236B28BEF9B182ULL, 0x19FA4E2666AFDF14ULL, 0x1E8240E276102E6EULL, 0x02479AB7C2289400ULL, 
            0xE3F27914E7AD2B74ULL, 0x783BFFB5400C1904ULL, 0xAB75CD5A1AE51FA6ULL, 0x2BFE63AB7B98C625ULL, 
            0x1589C1CC4FE46A17ULL, 0xA78D9082C965744BULL, 0xD59732A602B358BEULL, 0x0EF96B77FB4B6D67ULL, 
            0xB1427679A8FD9225ULL, 0x115A46AB4F485440ULL, 0x867BA693D249A84CULL, 0xCDA6252681CCCA90ULL
        },
        {
            0x314F7D974E1B1B11ULL, 0x555357677403A18AULL, 0x58AF075583BE9EABULL, 0x4D121AB35BDE276EULL, 
            0x0F4D9AA245D88458ULL, 0x0D9C04C22763026AULL, 0xCDDB6A5DA194880DULL, 0xC9234B235B108F6AULL, 
            0xA4E49639826A519BULL, 0xD9407BD3A431B287ULL, 0x059596735AB1E724ULL, 0x1E58782C359CC637ULL, 
            0x5CF634F917DA43B5ULL, 0xE7CE20C1DE8AA449ULL, 0x803341926DA2B9B3ULL, 0xB94CAC8D49926077ULL, 
            0xDD7B866C5AD22BA6ULL, 0x351705BA714AEC1EULL, 0x1C39DB7CDF0CBE99ULL, 0x61DAF1C9575B5141ULL, 
            0x2D0736F45C8BDA64ULL, 0x01FF557D49A2EC65ULL, 0x34C1A07BE11F5594ULL, 0xEE9039AEF5EC6B60ULL, 
            0xC59EF6CB5EDED2D9ULL, 0xDC016159A5574514ULL, 0x53807158722660E2ULL, 0x2EEAC1C5562AF117ULL, 
            0xFD749CE1D933A918ULL, 0x398CC756472B76ABULL, 0x55BA761B04F33ED2ULL, 0x09F0BD8B2E89BC86ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bellatrix::kPhaseBConstants = {
    0x3AFB0104A326F094ULL,
    0x37B65087CBE2E059ULL,
    0x44D89EE18F585731ULL,
    0x3AFB0104A326F094ULL,
    0x37B65087CBE2E059ULL,
    0x44D89EE18F585731ULL,
    0x9D67DCEBE231E687ULL,
    0xD8E3019A04099414ULL,
    0xC7,
    0xCB,
    0xCA,
    0xDA,
    0xDC,
    0x99,
    0x76,
    0x96
};

const TwistDomainSaltSet TwistExpander_Bellatrix::kPhaseCSalts = {
    {
        {
            0x250912B342409C60ULL, 0x5784F1C8ADE379CAULL, 0xF21E8E9263591428ULL, 0xF821C7C0A2966357ULL, 
            0xF1080FC6C76163A5ULL, 0xB5883637E851723CULL, 0x2B474941C32861DCULL, 0x986B70114ACF7ACDULL, 
            0x17A85E95FF6C85A3ULL, 0x31BCDD75FCF22081ULL, 0x3802273E59A7DABBULL, 0xDD0F6F221992F6B6ULL, 
            0x63F8ED06308387B1ULL, 0xB18EFD83DA63FC42ULL, 0xC1C146910992F5F1ULL, 0x473EE7637E769F27ULL, 
            0x268DC4615973EC56ULL, 0x5D9C53D68579660DULL, 0xDD3819A53A9AF601ULL, 0xD79FD90E0C5AA687ULL, 
            0x45EEC4A9197F9A23ULL, 0xB4BD9D92C33E07ADULL, 0x7C524D286F592AA9ULL, 0xA5752135DC5DAD67ULL, 
            0x2E810F8E4EB007E8ULL, 0x19DFC18F086E5B4CULL, 0xEB6E51863489DAAFULL, 0x67D3D84FA7113246ULL, 
            0x997CE11EE69E70DEULL, 0xD54326851FB0363FULL, 0x63CB6D89FCE46155ULL, 0x2AA33867D8C144E3ULL
        },
        {
            0x545845C336A45761ULL, 0xF53A38F05C53BDC1ULL, 0x548A54D9C25B6B11ULL, 0xA7989D2A32DECB7CULL, 
            0x781F3A79E1B26F0CULL, 0x0EEE593665BF0CD5ULL, 0x8E2779474BAD7AD0ULL, 0x0181E99D53006C6CULL, 
            0xE1A434C3CF275452ULL, 0x5D45440DA94E3664ULL, 0xC75C226E4F944E8CULL, 0x61DBAB0DE0ABB6D0ULL, 
            0x75F083A8157B2DA8ULL, 0x521211E40E048923ULL, 0xC2528EEEDFBD5EAAULL, 0xBBD6B55AA2F2E5D8ULL, 
            0x1E31A3AD788029F0ULL, 0xFA34DB3C2C4F965CULL, 0x2FEAADEA7C1843D9ULL, 0x91DD56804216CCDFULL, 
            0xA25EB6D0891E27E9ULL, 0x7663A84B91B34C19ULL, 0xED08705CC0A3A2BFULL, 0x2B35A9878D70AF92ULL, 
            0x7F72A3263801A2B0ULL, 0x3AA245AE0ACBBA81ULL, 0x1749E03334EBBA4FULL, 0xFAC672C9AD89D3A8ULL, 
            0x164DB927F098396DULL, 0xEE0C42396362987CULL, 0xF770242F91626012ULL, 0x908CAA48536A7AA0ULL
        },
        {
            0xCBE75E5979C4DC9EULL, 0x35BBAF62F826ED6FULL, 0x976EF61E82EB904FULL, 0xD422E4CAEE376F2EULL, 
            0x25415E2F29276096ULL, 0x515A246E3B88A3DDULL, 0xD1C93BC9481489C9ULL, 0x945814E11FE5B03DULL, 
            0x6619A54BE2C8F463ULL, 0xE02FBE957638ECE0ULL, 0xD8E320522A95547AULL, 0x8F43C972CA27DB99ULL, 
            0xB15F88897B96ECBEULL, 0x4539D2A38E05310BULL, 0x5B854C0C77913C1BULL, 0xE0D5F01992237EB2ULL, 
            0xCC6FBBEEC71E64BAULL, 0x7AAF25F454B7B128ULL, 0x1DC4D588A281B85EULL, 0x696FA51F9F19FE83ULL, 
            0x4C0290769C69B0FAULL, 0x5072FFBAD3D8E183ULL, 0xD5160127A7F2938AULL, 0xF65A1BDCE19AD025ULL, 
            0xD7BA5FBCE456F5F7ULL, 0xFC7E243FA5F0A454ULL, 0x0C732AB7B3AD6E27ULL, 0x95E4583ED6596B46ULL, 
            0xE93E42197B8A0D18ULL, 0x59F9BDD41A21441FULL, 0x053331EEB15524A5ULL, 0xEED5543C9CC7BAA0ULL
        },
        {
            0x47806ED1C53F1409ULL, 0x573EF66797D3C979ULL, 0xFC3ACFE8B828B5FBULL, 0x8E794152938D3078ULL, 
            0x38023ADD801CF781ULL, 0x61124B90C8BA9968ULL, 0x6568EC0881E0D0EDULL, 0x2E1F04ED5467E021ULL, 
            0x18CC2C7699E415CCULL, 0x129B2F066803CAEFULL, 0xAF3AD529D2A1BA31ULL, 0x183C9968BE5729E6ULL, 
            0x4CBDA27F83E9451BULL, 0x59B1E504B4F0D74FULL, 0x8D210E8357F90EBDULL, 0xA048E2F9A9E3C56CULL, 
            0x656F3988E658DBB6ULL, 0xABE825E82AD513F1ULL, 0x819E32567D1E9881ULL, 0xDCC7328227EC3082ULL, 
            0xE7EAC818B448DE31ULL, 0xACB813F07CDF62FAULL, 0xD8EF2239A2A5643FULL, 0x771035E253571A40ULL, 
            0xD99116FCA637F56EULL, 0x0C652A4352A4410FULL, 0x0A63D03691D8792BULL, 0xB3078A10AA762AA8ULL, 
            0x3684842094403FB8ULL, 0x4980BDFB9F9627ACULL, 0xA2D0BE893011E975ULL, 0x831C9F98D215C706ULL
        },
        {
            0x89C9FD0F57904172ULL, 0xB3CC270A46C926ADULL, 0x27CE3A3BD5193E3BULL, 0x8948B968057DFD98ULL, 
            0x18E045CA947475A0ULL, 0x36EC465ED3B8CEA9ULL, 0x6A96D1F15EFE9979ULL, 0xFC98BB1F4B1803EAULL, 
            0xC4C7EC83D4FAD9FBULL, 0x03D127A53AAFEAA0ULL, 0xE5A7D1CC894EC974ULL, 0x5478307751F9BC3DULL, 
            0xB2F5A7AF6DF5BA70ULL, 0xCD2081E6B9DEC92CULL, 0xF9A9E1E6F8BA5804ULL, 0x878F8C12B41EE0DBULL, 
            0x5D9CE1CFB6540EE4ULL, 0xAF8BD23811FD7199ULL, 0x3C3E2C17FBA56C46ULL, 0xA568FB853CC6281DULL, 
            0xE7912C19561040E6ULL, 0x54299C0C619B1BD6ULL, 0xD27E69F0C706CEC8ULL, 0x62308C60F5D6535AULL, 
            0xCE81EB1374E0388EULL, 0x8C3D6847995E6EE0ULL, 0xCB7C177A1491FE36ULL, 0x70F7208D164F9343ULL, 
            0x61A54D75126D68B7ULL, 0x77BA4B66DC40BBC3ULL, 0x5A2FE26E4966E449ULL, 0x1E26FE9FD80F8C18ULL
        },
        {
            0xD292928BBD513D3EULL, 0x059A368A08C19CF4ULL, 0xE8BB81CF491EED9CULL, 0x1EE9F6A1558E7589ULL, 
            0x5F313F1F67998372ULL, 0x25B579EA5E16E8C5ULL, 0xD11F429AB6E93F01ULL, 0xAA4ECF4766DAED68ULL, 
            0x3FBBAA26E1CC0909ULL, 0x706A8FF7F63D607BULL, 0x5907674010772D47ULL, 0x2F5FF7296710B966ULL, 
            0x6F0CFA55982151DBULL, 0xC78AAB95980BB270ULL, 0x460B311AA72722EFULL, 0x0DE1A1855B899297ULL, 
            0xD2F9857E07B7C369ULL, 0xE2D864B1E50F6F4EULL, 0x682881F86D964642ULL, 0x237A24950F886D91ULL, 
            0x9E712A24B1F378F9ULL, 0xD660BCDFA7471EC5ULL, 0xA2E0709F952CA885ULL, 0x9A4132B55FD2A266ULL, 
            0x871BC87812500E4CULL, 0xA7D1892165756864ULL, 0x1EDE4F67B7111AB6ULL, 0xFC1C3E48D27E8AC0ULL, 
            0x6FCA46A56AA8D426ULL, 0xA5C864B0EB1E50B8ULL, 0x04A56BC79FB09CB0ULL, 0x543856E4F4553B72ULL
        }
    },
    {
        {
            0x46EB5F717164C68EULL, 0x96423972D425D907ULL, 0xF2728D5DACBD8215ULL, 0x22CEBAC042D4B0FEULL, 
            0xD1040277382BC304ULL, 0xE8B63B5472B8A6E7ULL, 0x0EA76C61017F269CULL, 0x8CF700D00B34AC7EULL, 
            0xDD4901EC51AA51EBULL, 0x54312B70ED26E767ULL, 0x4222617C4371CF8AULL, 0x301F66F336DB014DULL, 
            0xCF8F52112DEAD8CCULL, 0x73C5DE8EAD0CA3F6ULL, 0x4C17DD10DEC8ECB4ULL, 0xCA8BA338191522EFULL, 
            0xAFF1ED9A63660D9FULL, 0xE0D98C03F86B30BDULL, 0x60DDA1A2B6311B30ULL, 0xD1F9959F48A9B243ULL, 
            0x732A5B2CE82BE085ULL, 0x9994408D38491F7DULL, 0x8F21B9E31A7D8A0BULL, 0x723A9CAE5485788BULL, 
            0x80517DE0B70AE4AAULL, 0xCBC3903847A476C8ULL, 0xAACE008E85CFDA43ULL, 0xA231477B4B5887EDULL, 
            0x12F1013AD006A413ULL, 0x9C8B0F8527960AC3ULL, 0xF4F8235170FA0018ULL, 0xB378142C5CC4082AULL
        },
        {
            0xF42FB1D7858FBE3DULL, 0x8B5D4076CC89699DULL, 0x4DBF0527B95C4749ULL, 0xF1A8FE015431DCCDULL, 
            0xB60CBA12F35675A0ULL, 0xDEA606B8782FCE5BULL, 0xD1E50DD7A81E814BULL, 0xBD869563BC409A0BULL, 
            0x5A5F0FDC92E03794ULL, 0x628415146F2C49DFULL, 0xA99FA3C59461D928ULL, 0x7381B2FADA19737AULL, 
            0xF9903561A68AEFDBULL, 0x0CD8CBB985404A9EULL, 0xDC31074CDE02B6C1ULL, 0xC3BCAEAD5341837AULL, 
            0x15E38778FAEC9759ULL, 0x459217F6E800458AULL, 0x00AF579467949585ULL, 0xBA06CDEFB4F5E5C2ULL, 
            0x845E18BA5F799A73ULL, 0xF1A2CF118259C6EDULL, 0xBAB8FEA1AE57E42AULL, 0xF8A7AA91E6957D3BULL, 
            0x361C66A48E84EF32ULL, 0x18A1EDACC1A668DEULL, 0x503F605571D82D8DULL, 0xE431006C17866512ULL, 
            0x98D964B075069277ULL, 0x5641F59B2C4E0D01ULL, 0x66E55E882069C1A4ULL, 0xC9E97C9999004651ULL
        },
        {
            0xDF9FCB02540593C7ULL, 0x65A38FCD6645D778ULL, 0xB44CC9F03D847EF8ULL, 0x0639B7E18C32FA2AULL, 
            0x3F1616DB85E224D9ULL, 0xC6E293CDA02CDE14ULL, 0x458B417A354B73E1ULL, 0x786203152F8D08E3ULL, 
            0xC8BE134962553DF0ULL, 0x0998B48D2F1B49E1ULL, 0x0525E23425A135E9ULL, 0xF7F75CE9D5B98821ULL, 
            0x694E8D2586FF74EAULL, 0xFD1527832CFDEB34ULL, 0xE5CF0F19F669E8DCULL, 0xD3153784FB07A0E6ULL, 
            0xF262DD3CB3421DECULL, 0xBD4A21185FB22260ULL, 0x2F7ED1AC002D032BULL, 0xE665367E25D7CAFDULL, 
            0xFFEFADC10B54D257ULL, 0xFEA734A9B1E4900FULL, 0x5953273EAEFCA023ULL, 0x5C5CA6959459F7D1ULL, 
            0x1C282F904BA7D76BULL, 0x5D0CE33B812E33DBULL, 0xB07B4EA64BA2EF11ULL, 0x39037414268D8317ULL, 
            0xDE437F0ADE3136D4ULL, 0x87EEFD3E9166B4FEULL, 0x1C727F2B964851D6ULL, 0x505AC32BFEC23A08ULL
        },
        {
            0x915D4D2A50E9DE8BULL, 0x96B7D87BF2A2FE0DULL, 0x3A58795B08577D41ULL, 0xF68225F6EC72C958ULL, 
            0x24DE787B4BD78CBAULL, 0xA3BB060D5999ACA7ULL, 0x6FEA8A078DB01912ULL, 0xF011E8B98A82743BULL, 
            0xBA5CFE6FFB3F0256ULL, 0x66D3AAFA0DC9C972ULL, 0xA87126AD2D1E6D8DULL, 0x0DC05B747622E788ULL, 
            0xB0AC2FB2D5D440C7ULL, 0x9D94947BC9081558ULL, 0x05212015247E586AULL, 0x958024D35F37A18BULL, 
            0xD87F9063DF957A31ULL, 0x190A4CF27CBFE747ULL, 0xB37968F6621C5E62ULL, 0xA42304AFC0213A36ULL, 
            0x442656E1DEAE4FE5ULL, 0x146759956AE528D5ULL, 0x28610AFC3577F5BFULL, 0x71DDCF035BA6C3D5ULL, 
            0x1B5763F1B40F7904ULL, 0xCCF88EF4E118A820ULL, 0xAF355B7B2642A9D6ULL, 0x55509EFC73F6C8D0ULL, 
            0xF36FA8CE4C037995ULL, 0xF4BA17D3F99C32A3ULL, 0xA1769E9F19CCDF38ULL, 0x7D172AE990751986ULL
        },
        {
            0x90725B1EBE63FD31ULL, 0x2CF19CD9F5DC35BAULL, 0x13B205394578D829ULL, 0x3628638FED230A99ULL, 
            0x2D69E5C9E835C6D1ULL, 0x433EB5FC2D7586ADULL, 0x9F4FD7FEC6FE4DF7ULL, 0xE70BB91E9A8CDC12ULL, 
            0x71403F2C508065C9ULL, 0x20C14107A94DC57CULL, 0x4CA1A31766284D4DULL, 0x001B40587411756FULL, 
            0x935A81B04EDD1AC4ULL, 0x8EBD6CA386B287DCULL, 0x3EBDC9A7401E8BC0ULL, 0x09368DF4B5EB327AULL, 
            0x44A93DD688480A09ULL, 0x3A2CE82B0B676695ULL, 0x67CC7F1A6D82829CULL, 0x035FA1D620E3DD74ULL, 
            0xCE0D25BA3D60C045ULL, 0x59C71D75F3D29316ULL, 0x684BA565E02BE57BULL, 0x2A21A16B9FE05B9BULL, 
            0xE1185AE63138091EULL, 0x55EB405A29F78287ULL, 0xACD14E896AC3F592ULL, 0x3D49C66FC9135F16ULL, 
            0xE2958A2AC0BB8A88ULL, 0x644A7786B68AA627ULL, 0x708E51DE1AFFE9FCULL, 0xF690B2AC7AB55D8AULL
        },
        {
            0x0E71092A0CFBBA62ULL, 0xA49893F6BF4395AAULL, 0x9945C098045B583BULL, 0x0FED042F52F5F07DULL, 
            0x05CA189D7BB03C7AULL, 0x4BE77455C84F1C0FULL, 0x7DD0C693F4D31C07ULL, 0xC15AF97414B8A2BFULL, 
            0xA4AA6178DB2FCAEDULL, 0x14B406E7345B826FULL, 0xCB7A3D8DD6385ED9ULL, 0x97059B39B6E8454BULL, 
            0xB0DA8852C138C7F0ULL, 0xFD280B417A772B74ULL, 0xEA55B72E3B20A73AULL, 0x8CD9C7FA90CD31D9ULL, 
            0xBB22CE9B22FA0F5CULL, 0x81FC8F5C7DC3A6A6ULL, 0x07A475E3A37E21C8ULL, 0xF3CA520A20774B66ULL, 
            0x5FFEC5FD3C6D6591ULL, 0x9A3B7FB5409C302AULL, 0xF0219B13C4371E64ULL, 0xF4653176255E0487ULL, 
            0x916B4740EFAF47F3ULL, 0xD1BFE7E8BA29F719ULL, 0xA47092CAAFE032FCULL, 0x29859DDF16C21362ULL, 
            0x2E2B9A464A8749C8ULL, 0x25ADE6979A612219ULL, 0xACB88041FB0A6BF4ULL, 0x3E6F7712E4E09B4DULL
        }
    },
    {
        {
            0xCE5AD6A3E1991438ULL, 0xB82DD5E897506016ULL, 0x8B75FDD8A498117CULL, 0x5B9A987150842B20ULL, 
            0xF98FC05CDCB21537ULL, 0x4EA6B80E0DDA4583ULL, 0x8C3EB2A5BFE7650AULL, 0x83A3F438FE83B882ULL, 
            0x557CAD52CE78AB7AULL, 0x947D291DBEA03A57ULL, 0x4177027192AC4953ULL, 0x591CE1E408570BF8ULL, 
            0x23DE7067C5EBA484ULL, 0x2ECEC858A59FAD68ULL, 0xA4115A31D188F73AULL, 0xBFD57041C966F14FULL, 
            0xB40C7695D30FACC7ULL, 0xEB9E4517A33FA04CULL, 0x9E34F96DE762E580ULL, 0xFD0878F2919EBC07ULL, 
            0xED5FBFC8D991570FULL, 0x40EFB2457B674D5FULL, 0x1D5A516EBA79BE02ULL, 0xCA00832C590696E0ULL, 
            0x953DFA89C1068EF7ULL, 0x1922E2E2527B88C6ULL, 0x291D6AC32AE6DC6CULL, 0xA2B2DD1CFAE57413ULL, 
            0xEC905CDABE7EB331ULL, 0x033EF99826FEDAD3ULL, 0xFE0FD59BCF2DA6D1ULL, 0x0CC04F3AAA242CA8ULL
        },
        {
            0x017CD19966DF0E36ULL, 0x32CB067F76C95609ULL, 0x49B9290F267B56EFULL, 0xB8AE88250357F6E1ULL, 
            0xAFD4B229E901EC25ULL, 0x5233615AF309CB8EULL, 0x73E841537A2F321DULL, 0x76695AAB71DF7BB3ULL, 
            0xFD37061CE4C99120ULL, 0x2D0F4925E04F9E18ULL, 0x4D4422D033320151ULL, 0x0E2CE4CC2FAF1AAFULL, 
            0xACA98FF0755F407CULL, 0xB49E6EE73A18A4EAULL, 0x8B661AA39D8F5081ULL, 0x55161E2EFDE5A87BULL, 
            0x4261A31E610C7DFDULL, 0xC97A6B6074C8836AULL, 0x806C5FCA5C081037ULL, 0x3093E7822882CEC4ULL, 
            0x67F609D1E9FD5A9CULL, 0x3F4E177269920EF4ULL, 0x032A6F8DE1177CF0ULL, 0xEA7F0C8AAF821611ULL, 
            0x91EA4D5BAD8EFEE9ULL, 0x37FF94606BD5EE6FULL, 0x5E871590165172CCULL, 0xDAFE6E8281EE10F2ULL, 
            0x6067648A3460FBCAULL, 0x75CBA21976E6C1D0ULL, 0x35C55AAEEA333ACEULL, 0x7C7E9A212CCEC01CULL
        },
        {
            0x8CFB627496168C29ULL, 0x0D3207474B84FBCAULL, 0x42F20FABC8C7861FULL, 0x3DE94AC9F662BD9CULL, 
            0xC8B68CAAF5BE6534ULL, 0x3C417F5E178E8775ULL, 0xFAA701EE89C9AC17ULL, 0x69744E23137AEA09ULL, 
            0xB9FE6610315DD016ULL, 0x29C69CB875CA155DULL, 0x02819C0D1559BB23ULL, 0x78F5CA33C1A7C08DULL, 
            0xA70C137358F852E5ULL, 0xED76EF001671C614ULL, 0x58960330E11DD8D5ULL, 0x8A0F1853AF726BD0ULL, 
            0xDB38333FC5DB75EBULL, 0x202B4242785591CBULL, 0x89670B3B9E74ED16ULL, 0xD4B681C89BFE140FULL, 
            0xD57443E4AD0842CEULL, 0x2F7395C6835BC084ULL, 0x90FED29F61B6E484ULL, 0x4F0BE2B148FA83AFULL, 
            0x33EE3FECC0FD2171ULL, 0x410809EF33934C2BULL, 0xCE22DD2C01493218ULL, 0x08A81AB6F4EF5C8CULL, 
            0x30807F062EC7832AULL, 0x54823F52F3348D2DULL, 0x7C87A0E028BD9F1EULL, 0x66119A4EF0F02C31ULL
        },
        {
            0x6A4E20595F0CDFF7ULL, 0xE6B8D6668BBA536DULL, 0x6B8799E62884AD8DULL, 0x7C824294698051D8ULL, 
            0x1E2081D15CD208D2ULL, 0xB5FDD66A400A3444ULL, 0xC4C6D0E773A220C3ULL, 0xB7A378B00289A8A0ULL, 
            0xB65FBC8F5B2813E4ULL, 0x88DA25BEA9B9E981ULL, 0x47440D11C66B3587ULL, 0x4FA090F5DEAD0250ULL, 
            0x9F0C597DD3F71C89ULL, 0x4E81D2FCF2AEE44EULL, 0x9FA298252C40CB1DULL, 0xFF47B5E0EF9D1753ULL, 
            0x08D52EBD9CDB2B37ULL, 0xD81EA25B33F27904ULL, 0xF4B51732A3EAFE6DULL, 0x4CD20425884D90D6ULL, 
            0x9AF534FEFB8B7A3BULL, 0x2FC4B1F5E3DB7759ULL, 0x42F79FCC52EEB1C9ULL, 0xAF1ABA387BB8C560ULL, 
            0x80003DFC423AB253ULL, 0xDB6055C8BBE89891ULL, 0xEBE97C660162E9BEULL, 0xF5CA9D98C56BEBEEULL, 
            0x8A06BDD3E7D58378ULL, 0x156F05277A220212ULL, 0x60D75C7056D81B3EULL, 0xBD43D0966ACC5FF3ULL
        },
        {
            0x61A3803ACD49007DULL, 0xB026FC5CAB9E0780ULL, 0xF3A3DE1693CD9901ULL, 0x653DE5E2DA2C925AULL, 
            0xDDD5A5CE7257728BULL, 0xED73528D3397FE43ULL, 0xB8831E610F73C7EEULL, 0x1603A4612D7EAD2FULL, 
            0xF915BD983B9AC571ULL, 0x0C660183D1152263ULL, 0xF1D49C9E75EC91C5ULL, 0x85FF127947BE2A68ULL, 
            0x6CA92DBAF9DF18BFULL, 0xD79AF7C0085E9BF5ULL, 0x00DEE0A404BF1450ULL, 0x4262F8DEDDBC3A73ULL, 
            0xC2A76978BCCF3CB8ULL, 0x4C614DA6651E2DBAULL, 0x94D25B24B6676F66ULL, 0x794906DCC6972156ULL, 
            0xEBD94793C04666A5ULL, 0x5190EB8A1458480EULL, 0x96A24AFAD1517912ULL, 0xF2902E7E86AED35DULL, 
            0xAECE4635F25BB2F2ULL, 0xD24AA5A480BD3F02ULL, 0x8997AE2B9A5CC564ULL, 0x6046EBA5E3E78DE4ULL, 
            0xE2B4CAE39C7A8BC2ULL, 0x579C722CB071844BULL, 0xA26C1E719C0ADB16ULL, 0x3705A7ADF43A1A3EULL
        },
        {
            0xDB8A54492F4F5B29ULL, 0xC4A7EA9FF5450955ULL, 0xD8D7D9F82C57BAB6ULL, 0x158AC9D5F2A9A593ULL, 
            0xAB582D4E1970CB11ULL, 0xBFD9B33AB1446E43ULL, 0xC6574825CB12D8D0ULL, 0x8274678BC9AFD91CULL, 
            0x383B5A5B1AF17AB2ULL, 0xE2598E4125C92DA6ULL, 0x52B3E2230A0AC4CBULL, 0xDE04D749B62C01E7ULL, 
            0x1F71310E28DC5444ULL, 0xFCAC6BBE018BCDDDULL, 0x62C251DFEBC21F79ULL, 0x0289BF3206136F4FULL, 
            0x31CAEA6DB3404A74ULL, 0xF56C88CC0AF83FBBULL, 0x0DA718D7CC79445EULL, 0x11BA2AAB55E35AFDULL, 
            0x1292B5DAE09740E6ULL, 0x8B45625993E2592FULL, 0x5EC0B6E465C98619ULL, 0x211A5E712C930760ULL, 
            0xF9C93E295B6B7C68ULL, 0xF9C7A9E53BD5996EULL, 0xC9819189F0B6AC0CULL, 0x01BD55B298B49DB5ULL, 
            0x34466C55B35CF818ULL, 0xC4C802D5B28052F8ULL, 0x05C62F29F91E3F24ULL, 0x23843020653209C9ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bellatrix::kPhaseCConstants = {
    0x9A4C04DE71999974ULL,
    0xF72FEE7EEE9744BCULL,
    0x0A917DD3B9AC3435ULL,
    0x9A4C04DE71999974ULL,
    0xF72FEE7EEE9744BCULL,
    0x0A917DD3B9AC3435ULL,
    0xC29D27350E25F3CDULL,
    0x7A8AABDCD1F17B7AULL,
    0x58,
    0x30,
    0x42,
    0xE2,
    0xCD,
    0x24,
    0x60,
    0x39
};

const TwistDomainSaltSet TwistExpander_Bellatrix::kPhaseDSalts = {
    {
        {
            0x22C2DB0D9ECE0716ULL, 0x4A296F934807FAE0ULL, 0xE83D499190EAAB2DULL, 0x11536FB66D87BBDAULL, 
            0x0B282123B314B4D9ULL, 0x7D00894B184E9952ULL, 0xC33D47693400E85EULL, 0x8B733BB2F65776A8ULL, 
            0xB079266598B5A7E1ULL, 0xD6714B5875487D6EULL, 0x3560A0D4B0BFD43BULL, 0x40242B2444FA16A5ULL, 
            0x2A5E2130DA2B8C82ULL, 0xE4C585BCCEA1778CULL, 0xE3879E54C83082DDULL, 0xA08D70430927AC0FULL, 
            0x740B063608788995ULL, 0x696141C0D2E350A5ULL, 0x04B72BD8B6995F88ULL, 0x898FCFB8CDC30CEBULL, 
            0x4E75D405722055A7ULL, 0x882FA02549677659ULL, 0x0768DE9D283AF3E7ULL, 0x671AE1D6260A1EFDULL, 
            0xCBD05A198345997CULL, 0xE8AA33DBBBF71683ULL, 0xE4A1E8186F489100ULL, 0xFCB9DE4AEC5209F2ULL, 
            0x50F2DD0470ECB9FDULL, 0xF6DC21C0480DB119ULL, 0x127979D5535B7400ULL, 0xA2C710798D42B130ULL
        },
        {
            0x28116AC637E8B133ULL, 0xFCCAD81AAB0856B0ULL, 0xBA7B4D611D5A727AULL, 0xCE6D61B10430F903ULL, 
            0xD8381A63946EB580ULL, 0xC3EFF03A79DCF407ULL, 0x5D449C9F6C2A5866ULL, 0x80140C9A4FF66B79ULL, 
            0x03C934E93FFDEBD4ULL, 0x9EBC4F1020693FECULL, 0x90294BBF12DDA78EULL, 0x9E28AC25D7AFB321ULL, 
            0x6385DFF7F98F5173ULL, 0x4570EC4F9E27FB46ULL, 0x47D99CBFF25FFBEDULL, 0xE11248354D29EB96ULL, 
            0xDE1042E353DE6F51ULL, 0xDA30C2E08AC94E2DULL, 0xE57E7BCA7E8958B7ULL, 0x4B0B466B6446C02EULL, 
            0x24F347915927069EULL, 0xE48DEDF25C16A7C5ULL, 0xA78C35BDA314C41BULL, 0xC7B014B6EEC81983ULL, 
            0xCF4567B18ED63910ULL, 0x17DF5FC3EB28E25AULL, 0x7DCF0EF02AD9D0CCULL, 0x6AB877E37F54503DULL, 
            0x298D01DE677D0197ULL, 0x5C656A70048E690DULL, 0x94CB36BC05A18C70ULL, 0x61C4B43E77FCCE46ULL
        },
        {
            0x9E6C4CBEFA9DDB84ULL, 0x78C000364B229414ULL, 0x767C4858AB1CEF73ULL, 0x6767628D0F36E200ULL, 
            0xFBBEBC8C8113B464ULL, 0x226772FBA579D405ULL, 0x1F1B457B5FB4E22BULL, 0x4D9A96B42C3F683EULL, 
            0xAE930D2A1A06EF19ULL, 0x6ED6F5528AED4B05ULL, 0x8B6B0E4758522C7EULL, 0xA3F8D218E23D94B5ULL, 
            0xEFC6914BF2B8C4B6ULL, 0x721AE88AC789B726ULL, 0x406BCE4466D10B92ULL, 0x1939816B4C5BC3BCULL, 
            0xAA27A14007D91ACDULL, 0x400134124E1FA48BULL, 0xF4C3DC707B4BF9D2ULL, 0xF85C03C627FBEB43ULL, 
            0xD7B9FD10CD4FD0EDULL, 0x143F7B17E8387F9CULL, 0x318F1BC4F3945097ULL, 0x47F1276986D93355ULL, 
            0x6E2F6B26CFEC4C5FULL, 0x6330E972C3C7475DULL, 0x4E2D97B5D73F968DULL, 0x1F03FEC9C9B8DC88ULL, 
            0xFE79550544AD949DULL, 0xD6325613F1930BDBULL, 0xE27EC333095D13E6ULL, 0xE20C3CAB813B9D73ULL
        },
        {
            0xA6F98FED3A8274C3ULL, 0x89DE80A06330D0B9ULL, 0x63D93CC88F8B7AEDULL, 0x5BF29857FC97309EULL, 
            0x9C8D99877E18BF6FULL, 0xC8F5DCF3508A046DULL, 0x59F51F05AD59B392ULL, 0x108D416DD8B4CEEEULL, 
            0x4FC77D055474ABCFULL, 0x30EC1D09029B8623ULL, 0x2294A505B1798E9DULL, 0x9E9DD64C027D1870ULL, 
            0xE0C2F54CB0354896ULL, 0x9967F573917A1A82ULL, 0x203087CBB1B9270DULL, 0x5A39ED555568F4DFULL, 
            0x43EC137221951817ULL, 0x0DC4148CC7D5577DULL, 0x31855BFCC43A90C7ULL, 0xECF17FB76799A8B8ULL, 
            0x7F71EDAEFBB8048FULL, 0xC2800FF076B919EDULL, 0xD61A221839FF9DE8ULL, 0xB9ACA259597BCC60ULL, 
            0xE135643671A26FC7ULL, 0x2F34E764409DD5A6ULL, 0xF6EFF7AFD513CAFAULL, 0xC3838E9FFE8C71C1ULL, 
            0xD18B1A91FDA219C4ULL, 0x764117E7BD5547C2ULL, 0x5986BD667D41EDE0ULL, 0xA73ACB6369456845ULL
        },
        {
            0x42F5018D72D6A773ULL, 0xCB28EF4BC085E761ULL, 0xA10FF006C9D1EFA2ULL, 0xA638CBD4516ACE18ULL, 
            0x12567362823AF1ECULL, 0xB38543772B7B3F06ULL, 0xD6137076CC375A90ULL, 0xB23F7C181D96D4A5ULL, 
            0xE35F1D6398C3AA6AULL, 0xA47F73A44DCE9204ULL, 0x35CC15E83939AD06ULL, 0x1A1B1A8B714D77EDULL, 
            0xA4C3CBA7E4AD7032ULL, 0x52DC2D3D0EB04D3BULL, 0xA163FA30795C28D8ULL, 0x30A20ACF6F76E459ULL, 
            0xA2E25A349D6DC35EULL, 0xE358D730FD201593ULL, 0x5D4C3F92D69E165DULL, 0x4F5F6CD857F0CC05ULL, 
            0xF1E9D995ABB60EF8ULL, 0x66B97427DAB7B9E1ULL, 0x93B32682107E3467ULL, 0xF6AFD533AC166D01ULL, 
            0x6EABF8A4C75D1F54ULL, 0x9C1F4B846A5826FDULL, 0x0F0580341E64AF92ULL, 0x407E3DFD5A942F1DULL, 
            0xDDC15EB2587A06D2ULL, 0x3036356E72635946ULL, 0x264B2BB2F6C01249ULL, 0x945E623259B30B05ULL
        },
        {
            0xF3AA1F571B4D4C50ULL, 0x3253DB68350493D8ULL, 0x4659FFD4430F515CULL, 0xDB16CEEF092C33A7ULL, 
            0x47F4335873490FC4ULL, 0xAC0877F5677DA0F6ULL, 0xCD04A55266F1D5F2ULL, 0x535362452EA09FE2ULL, 
            0x126F3DA632BBBBDBULL, 0x45F18E0C065591C2ULL, 0xD7C4BD5C3EABE66AULL, 0x0F7A3D7B0D0CD77AULL, 
            0xF16BBA9DDAEBC07DULL, 0xC479DCDD1EA958F8ULL, 0x81B9925F68638A40ULL, 0xE0D9F58EC5F2BF21ULL, 
            0x76376906C6BD2FB1ULL, 0xFE40802B2D47BA00ULL, 0x06772732F3363816ULL, 0xE5A7C5902AA52F09ULL, 
            0xB3498080007430F0ULL, 0x69C8577C78BC3CFDULL, 0x7FD25AC71D8FD6FDULL, 0x7BDEF2A554A1CA2AULL, 
            0x3C76D04E6B1FB7B8ULL, 0x52CD57656A3BD651ULL, 0x66E24E30E1EF3645ULL, 0x2E1EC813AAA49987ULL, 
            0x3457368B6F3A4EABULL, 0xBF88B81B134BFE93ULL, 0x1486096BE1006F10ULL, 0x1AF4288ED4EC77D6ULL
        }
    },
    {
        {
            0x18EDA1D015E593F6ULL, 0x617EF7F60B655B4FULL, 0x0742F3B09B43F6D1ULL, 0xC993FC0331C64AFBULL, 
            0x8B55509B4EE2468DULL, 0xDBDD112AD31D3BC7ULL, 0x436AB3BD966AA557ULL, 0xC7D73505AA803D23ULL, 
            0xF5EFC94C1DEA0E87ULL, 0x98120F2E7B4C7F5EULL, 0xD3CD6456D15DCAF7ULL, 0xEB6C5DF6DBD6B2A1ULL, 
            0x1561B87E046814BFULL, 0x0EB8028160098169ULL, 0xC1BEDDFDE9C83233ULL, 0x8F945CC1E8FF4D36ULL, 
            0x71083986D028499CULL, 0xDD96D7820F736DCBULL, 0x72A5D8F529F77A4EULL, 0x3C27782CC1B4AAD0ULL, 
            0x2F84E94E21666890ULL, 0xB87ED2A3E7CDE9C5ULL, 0xDB44BCD6EC049A80ULL, 0xE73C98A94DF35881ULL, 
            0xD0F1AD5D99CCAA76ULL, 0xE176F9A45184E21DULL, 0xA7F8440561DA125BULL, 0x5EE7BAE2A2CE874BULL, 
            0x9364563FED986355ULL, 0x57F62FBF4FB68CF5ULL, 0x25D14137720D8D29ULL, 0xEF61461246D80226ULL
        },
        {
            0xEE11854E63C2798EULL, 0xE4F2CA640053618DULL, 0x248E08971FCD11E4ULL, 0x90B772F0A7B8FED2ULL, 
            0x6CC89AE939450E2CULL, 0x17A7F195E49A0F33ULL, 0x10A972686E277563ULL, 0x21C0F7BE53687E60ULL, 
            0xC75CAF40CEF72E2FULL, 0x45EB6EE6F947D782ULL, 0xE435D6AE01641406ULL, 0xF9F7EFFF6EF2D5CEULL, 
            0x8CC0E727E9239602ULL, 0xBFDA3B250D40B249ULL, 0x017D99982466989EULL, 0xB584944187FAA650ULL, 
            0xB188EA0D51532C05ULL, 0xD909D1BBEFFC04D8ULL, 0xE96E2A5C3A364080ULL, 0xD7793921F91C8E3AULL, 
            0x005AA20A97075B77ULL, 0xECAB540533E4BADBULL, 0xF61377CD8AD3B922ULL, 0xF98A9BDB07CF0C0CULL, 
            0x059F16F25AEBA50BULL, 0xF3606BB132C4B38BULL, 0x1525A5FA1D9E588FULL, 0xD327876ED7E5223FULL, 
            0x5F61241193DA1CDFULL, 0xB045C6CE8CF83F0CULL, 0xAD857DDB21A5C916ULL, 0xF5018FA8CC321977ULL
        },
        {
            0xA7E679B2697940E3ULL, 0xCCDB1678DA61EEDCULL, 0xF344A3A56AA0EE5CULL, 0xE904F60F98B6E7E5ULL, 
            0xEC30D60D5526C647ULL, 0x4EE90D4294E5F7EEULL, 0xFF6D0E9ACAF4A406ULL, 0x9E77AFD81361D3A2ULL, 
            0xDDE2FCE0C6C40349ULL, 0x4BC451527D7665B5ULL, 0x71B1A9E00F380DD2ULL, 0xDE041D6AD407C4DEULL, 
            0xA1EE60FE53375BF4ULL, 0x95C218C706806AF5ULL, 0x179B4A7C564C4E29ULL, 0x86E788C5CDABE6B5ULL, 
            0x18FDF2C926BDE467ULL, 0xB8756A816FF1EC5BULL, 0xF28AD26E0B8167EDULL, 0xF8007A9DD68FF1F0ULL, 
            0x6BAB3C8BB52CFCAFULL, 0x2B063C57C88A72DBULL, 0xCC200EBB6AD8DAFFULL, 0x324CF3F8290790BFULL, 
            0x7D0CA1B25A9C8A05ULL, 0x1A94BD151BC41568ULL, 0x4BEECCD6686A23FCULL, 0xFA1B0B40171588E5ULL, 
            0xCD12D964620250BBULL, 0xF191D1D1E2E0B470ULL, 0xF5356AC62342A354ULL, 0xF718DE74C9D54C60ULL
        },
        {
            0x52050DB60D179689ULL, 0x431C6EF5704EE22CULL, 0x275A42FF27128F48ULL, 0x0A4AC0BB4368D03EULL, 
            0x839434FEA613EA0DULL, 0xF5E948EF99CF93E5ULL, 0xC534714BA11C66E4ULL, 0xA52B37F4675B1B80ULL, 
            0xD3A93B577A4AE333ULL, 0x056AE858690DDF2BULL, 0xF496C2CB2249169AULL, 0x5B3845BBE1152E8FULL, 
            0x60499FC65C14A3D8ULL, 0x2BCFEB8FC63DC8DBULL, 0x9EDE63E0876A5B1EULL, 0x9F0335B61AD87296ULL, 
            0x0E21D9FCF77ABE75ULL, 0x4E4B409A8C92EA70ULL, 0xF5416DC30A0B8EEDULL, 0x2DE4E4CDFDC8DEEDULL, 
            0x3B6A77BB9CDC9794ULL, 0xFBC81FA887929817ULL, 0x72B3F961328C2B03ULL, 0xA5B39F3054270BCEULL, 
            0x53A3AB973CCE3A1DULL, 0x5B3AE586312EAE30ULL, 0x0E5105277A861E57ULL, 0x31198128FEDB6529ULL, 
            0xC3B7BF08B9872374ULL, 0xFE3567999D47FE08ULL, 0xBC552580E37E80C4ULL, 0x01ADB3810B601589ULL
        },
        {
            0xA77A6EA5F7B482A1ULL, 0x89F9DC29F738D329ULL, 0xBD955053A6684687ULL, 0x405F527B4CF6325EULL, 
            0xD60B3A2DCDC2FA86ULL, 0xFD070EEEF889E4E2ULL, 0xC7FD961444A45D03ULL, 0x7025105C78C7E23FULL, 
            0x0B59628C186E55E3ULL, 0x6A77AE1E70E46E67ULL, 0xE43C35C226E2FD95ULL, 0xA103448A444CCEF2ULL, 
            0x2F5FAF467C9E616EULL, 0xF39F06684A402490ULL, 0x8AED67F5E3B109D0ULL, 0x6362D35680F164AEULL, 
            0xADD2154A5E188750ULL, 0xA9D3497F35131FD5ULL, 0x23701FCA7C2B535EULL, 0x6269CC25273B2F73ULL, 
            0x0C9C95841A1AE598ULL, 0xD7939AFED2453F9BULL, 0x70F3C4AA58B0C579ULL, 0x923D78370B36C11AULL, 
            0xF34AC8C2FC474530ULL, 0x8E12B4B5CB825824ULL, 0x80187B0E26F1ED75ULL, 0x7C5A7E762C2E16A4ULL, 
            0x65A7F0D152D875AFULL, 0x277D8F682C4E93B6ULL, 0x0BB5E035649B3153ULL, 0x1531BC0B2C6DDB46ULL
        },
        {
            0x685F749DDD3F429BULL, 0x088C08171363840DULL, 0x824AE23F4529E2F6ULL, 0xBEA4B09BFD718DF4ULL, 
            0x3F611EC2B14C2090ULL, 0x60497850B255D866ULL, 0x34DF2C54D14654E9ULL, 0x0C8AFA77BD8C574EULL, 
            0x1C13CB4BFA00F585ULL, 0x20ABF8BC6166636DULL, 0xCC4E14BA0197E69DULL, 0x517E2450E32ABA3EULL, 
            0x48D58E8D98C8E2C6ULL, 0x9A353FF40A6186EEULL, 0x2A543D35D2C1295AULL, 0x4597F2407BEEBBD6ULL, 
            0xD49E687AA038E19DULL, 0x25DA74F0120C382CULL, 0x0E98E284038D2314ULL, 0x5A953B7627D69C96ULL, 
            0x00C9FD50325F6276ULL, 0x9E861AD7E40EB022ULL, 0xBA8B6655D2AC0D94ULL, 0xDFF656A5DFA1FB75ULL, 
            0x7C3975862B57B15FULL, 0xA035364012616A8CULL, 0x137D4FABBFDF5774ULL, 0x1E91D3D48A94846CULL, 
            0xC30FA0FD52CD5356ULL, 0xC8BEBFA791485B74ULL, 0x2EAD484F5D6B92ECULL, 0x1FA1BA16B36C1ADDULL
        }
    },
    {
        {
            0x21C9AA9F032AB2D1ULL, 0x54F382F0676150D2ULL, 0x24B03CE4F4A014C3ULL, 0x68D08E257F6224D5ULL, 
            0xCF4677FB9CB3019CULL, 0x4CBDB3C5891B92AEULL, 0x7986E00268E7D4EFULL, 0x13D22E5D82E3F5C0ULL, 
            0xAB223DB60C2B520BULL, 0x8458CA5A65D3515BULL, 0x4E384F68EEA051A4ULL, 0xA2A4807DF71FAA61ULL, 
            0x22032EFC55E12423ULL, 0xAA12AFC30A8F3E69ULL, 0xB48C5A8970B6E975ULL, 0xCCA25E50711B6ABDULL, 
            0xA6D46AFDDAECEAE1ULL, 0x5E09465EAB2FAE1FULL, 0x69FBD910188B45EFULL, 0x62EFA66C200C9D0DULL, 
            0xFC9B2651D0A25837ULL, 0x3AA193F81C290CDAULL, 0xA0F0D99A6453A288ULL, 0x7B0D361C6AD2A6C7ULL, 
            0xA280B930AAA94FBFULL, 0x6638C226AF294959ULL, 0x6A7E7AE53467CAB8ULL, 0x47D71ADF638D5134ULL, 
            0xCD141A50D0ADD7FFULL, 0xA3C3E903ECCC9366ULL, 0xFF1C164054FC64EFULL, 0x00E7B5FE5C723F8EULL
        },
        {
            0x490C8422F8C53845ULL, 0x1ECF8A006BE8B67BULL, 0x304D28B509050560ULL, 0x78CE8DD29EDE2D60ULL, 
            0x66224ED320582A43ULL, 0x189AB7AF90F40B3AULL, 0xAFF7725C7A8CE848ULL, 0x0136DDC2FC2E674FULL, 
            0xE9BBC30B5A992AC5ULL, 0xF661C4CA10B87E3DULL, 0x29CA20FD0F1E294CULL, 0x4DEAEDC81A71C40BULL, 
            0xFA7E22EDA82FF0B7ULL, 0x598D9C5469F8B677ULL, 0x61237AF4DF269638ULL, 0x7FB348BBD1080D7BULL, 
            0x99B1980A970687AEULL, 0x4D08BCFBC085D659ULL, 0xA793BDD835E27566ULL, 0x6B18F3EC53A62E3EULL, 
            0xE8E35E3FCA836631ULL, 0xAD62C651AB5F7DC5ULL, 0xBFBF85A9CAB3D6ECULL, 0x4BBB4DC4CAB8FC85ULL, 
            0x123AFE105907E62DULL, 0x2AD64FF2B6535FFEULL, 0xD8D8C812D3C201E0ULL, 0x4DA370C71DA5B281ULL, 
            0xC6260EF9CDA21B0CULL, 0x3BA31F0BD6B66603ULL, 0x45F4811BCCA3D987ULL, 0x3BBDDF797C6F776CULL
        },
        {
            0x015B1B6E5383AF35ULL, 0x0E89D33E24709CF0ULL, 0x1ED076E7B166C4EAULL, 0x7E5B758EE05F4D58ULL, 
            0xBE4388765765C9B4ULL, 0x7CD7317C2F8B049EULL, 0x307BAB8CA27A50C6ULL, 0xAE75CAC8DBDA787BULL, 
            0x764F3131C9CCEEE1ULL, 0xFC4EA6B29B0850BDULL, 0xDF1E266D9041190DULL, 0x38FCCB9B46C4B306ULL, 
            0xAD37947F9A2D138DULL, 0x93ADDF6617DC0F82ULL, 0xAF21062E3893791EULL, 0x7DAC524750E133D2ULL, 
            0x1A5FB28DEC016719ULL, 0x47378F07B3331845ULL, 0xF554370219149C9FULL, 0x2BB4D99371C35163ULL, 
            0xD9EE5220CD1B1E33ULL, 0xB9E2CD6D6BD28207ULL, 0x53DD65731ED53084ULL, 0x04962F0DFC9F17C7ULL, 
            0xCE2DD71CEC41A7A9ULL, 0xEBCC18F1DCCCAAE2ULL, 0xC90250BD0B570D1FULL, 0x011808FAD8068625ULL, 
            0xB37A62220D8FEF44ULL, 0x8AE5C87841D1262EULL, 0x86B16BAD3B308EF8ULL, 0x07CB060E69317A7FULL
        },
        {
            0x93F5F6F03D5EF11BULL, 0x4BAED4BD4F6CB308ULL, 0xA7A6D5CA238EB121ULL, 0x549888EAA6A64BA7ULL, 
            0x0777813DEDFB237EULL, 0x3BA04FFD9F238A7EULL, 0xCFF27AA1B1EFC507ULL, 0xA8883DE692D38BE3ULL, 
            0x491472DA0DF6C648ULL, 0x7386635FC5F9A4DCULL, 0x4B5C3BDD7AE42FC5ULL, 0x40E49D4EB2CFBF6DULL, 
            0xD9045C79E3555E7CULL, 0x9238DD5ED8B87E26ULL, 0xB69BDD8B3E50C45DULL, 0xA56522A5041662ECULL, 
            0x5AB144CB519E2F17ULL, 0x2C3D090492C3D7BCULL, 0xCAB4C641B4967232ULL, 0x48E43EE3DAB96224ULL, 
            0x4A6915F7269CB420ULL, 0xFF1485FD0402B376ULL, 0xD5CB92EA6D8D1356ULL, 0xABB194221E7D40E7ULL, 
            0x9BF723950C13DC5EULL, 0x0A44C303631F66F1ULL, 0xE13B591CC21D6162ULL, 0x9154E7D50AA8C032ULL, 
            0x135C087FB9D4D498ULL, 0xB76F8324C382A855ULL, 0x3A0172B111664EFAULL, 0x6835FFE82CAAFAB4ULL
        },
        {
            0x2CF9EBEAC612397BULL, 0xFD506B4963C78B7AULL, 0xA3CB0DE13BA61A1FULL, 0x3DECD4FA62FB4664ULL, 
            0x2D9981C284A9F9BEULL, 0x1EAE9151CA062E3FULL, 0xE949D2138B75A45DULL, 0x56C87EB96A6D3841ULL, 
            0xE70DE6E9C9B5281AULL, 0xEF31C1DEC50DF4E3ULL, 0xB84B51566C1308BBULL, 0x264B046A81796DE4ULL, 
            0xE610650447F8DD08ULL, 0x7FD6111EF4FE2EFEULL, 0xE546EA477455B75FULL, 0xD2A3F2BB424A70C6ULL, 
            0x43D51373BF857529ULL, 0x197E0654AAA36D59ULL, 0x2460558795E16744ULL, 0x3E1930B0ADA2C9D9ULL, 
            0xF72BBEE9D900DB23ULL, 0x89BBF5E14B0CFE57ULL, 0x43DD2FBFC003783FULL, 0xA718D68F200F6F0DULL, 
            0x695ADA26F35C96C7ULL, 0x8395749CB07E59A5ULL, 0xC7E0C2CB0F3B2AB2ULL, 0x5C2F9A6266BCE215ULL, 
            0x265CA065C1D971C7ULL, 0x35B03E14EF5C2E28ULL, 0xA9CCC96211D6029BULL, 0xC34E2A1058953A1BULL
        },
        {
            0x526A2D4CE38178C6ULL, 0xBCD2CF8D78362C3BULL, 0x1F016C3538F0147AULL, 0xA9560C2516F4BA57ULL, 
            0xD1E4D3751950D8C1ULL, 0x8B226BCC658D53DFULL, 0x9D04216A44071376ULL, 0xAABB859496A57994ULL, 
            0x962BBFE0C1A49974ULL, 0xB617095B9AB03EE1ULL, 0x1BB81F9541364C38ULL, 0x2CD2516B003844AAULL, 
            0xDD8A057B39D60D4FULL, 0x081974526036C84EULL, 0x21CCA1793D713502ULL, 0x7B8B8A4DD5991216ULL, 
            0x5528F3565A01837BULL, 0x9CDC3E8FA11FA6C5ULL, 0xB78956626DE9C875ULL, 0x5D6A18034A33A0BCULL, 
            0x5EE5C82BC71CD27EULL, 0x96EF96822AFB2386ULL, 0x3903F8EF1CE9C8D2ULL, 0x121920147BEE9C13ULL, 
            0x9DBD2CB7BC007238ULL, 0x01B7AA76B8BB3B13ULL, 0x4BA0A832AF5AD63BULL, 0x0E7887E0605A0657ULL, 
            0xEF0C623BC3908AC1ULL, 0x8377EDB97E15A003ULL, 0xA6574296DD5AAF99ULL, 0x72BDE93C6FC712A1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bellatrix::kPhaseDConstants = {
    0xAD3A98D767A3E33AULL,
    0xF0F815717CC75182ULL,
    0xD211A5552B8CE5E2ULL,
    0xAD3A98D767A3E33AULL,
    0xF0F815717CC75182ULL,
    0xD211A5552B8CE5E2ULL,
    0xE0E80AEBE0D39B35ULL,
    0x186B42C654604CDAULL,
    0x80,
    0x2A,
    0x92,
    0x76,
    0x14,
    0x6B,
    0x02,
    0xC8
};

