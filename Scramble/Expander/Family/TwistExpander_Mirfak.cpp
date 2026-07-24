#include "TwistExpander_Mirfak.hpp"
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

TwistExpander_Mirfak::TwistExpander_Mirfak()
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

void TwistExpander_Mirfak::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA568687376EA59D4ULL; std::uint64_t aIngress = 0xA38090152108A567ULL; std::uint64_t aCarry = 0xE255AB623B8A8753ULL;

    std::uint64_t aWandererA = 0xE61C95AF96A50C1CULL; std::uint64_t aWandererB = 0xAFCA8D216EA0594BULL; std::uint64_t aWandererC = 0xD7C8D980A3A46993ULL; std::uint64_t aWandererD = 0xE78F3E803C031481ULL;
    std::uint64_t aWandererE = 0xDF0AA4483C0654E4ULL; std::uint64_t aWandererF = 0x8C0E6E0B1BE6FD12ULL; std::uint64_t aWandererG = 0xDE2DAE17EE80DC9CULL; std::uint64_t aWandererH = 0xF52A1EAB304F8799ULL;
    std::uint64_t aWandererI = 0x802301338C657022ULL; std::uint64_t aWandererJ = 0xD7D480E2C86E9298ULL; std::uint64_t aWandererK = 0x8C50FA1533F1E14FULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xA2D110B2711B0786ULL;
        aCarry = 0xED1852A5CD38C290ULL;
        aWandererA = 0xBBF2FA817E8528CCULL;
        aWandererB = 0xB04A942CD743334EULL;
        aWandererC = 0xFAF7AC6165B23649ULL;
        aWandererD = 0xA669868779C6787CULL;
        aWandererE = 0xDD0B26DEB5A00ED3ULL;
        aWandererF = 0xCCA7F7D7C8F16A52ULL;
        aWandererG = 0xB727F7A7D28FD329ULL;
        aWandererH = 0xAE03737C373835F0ULL;
        aWandererI = 0x9F61AB7FF88EE3F8ULL;
        aWandererJ = 0xBCAF37C3641A9D6CULL;
        aWandererK = 0xB0FEC91C3862F758ULL;
    TwistExpander_Mirfak_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Mirfak_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Mirfak::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF2DAFABE5E46AB95ULL; std::uint64_t aIngress = 0x98C1FF3DD045B6CCULL; std::uint64_t aCarry = 0xCA91B380A05D039CULL;

    std::uint64_t aWandererA = 0x9FD54C762BE200CBULL; std::uint64_t aWandererB = 0xBC522018489664FFULL; std::uint64_t aWandererC = 0xBDB3757B7C3B99E9ULL; std::uint64_t aWandererD = 0xF7D0311AEC9FCD92ULL;
    std::uint64_t aWandererE = 0xE4AF9061B0D5E243ULL; std::uint64_t aWandererF = 0xB7F8711D94250433ULL; std::uint64_t aWandererG = 0xFED74D4C042EF502ULL; std::uint64_t aWandererH = 0xBDB0415419D8656CULL;
    std::uint64_t aWandererI = 0xFE493CD20CE75B9BULL; std::uint64_t aWandererJ = 0x9864BBBF28033B5CULL; std::uint64_t aWandererK = 0xDC0FC059575841E1ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x896866DF4AA0F7D5ULL;
        aCarry = 0xD2BD56D8440D6BD7ULL;
        aWandererA = 0xAF3D823880A56039ULL;
        aWandererB = 0xF72696FB63703E31ULL;
        aWandererC = 0xA12DC675A51FFE59ULL;
        aWandererD = 0x9232C415502A64DCULL;
        aWandererE = 0xC132EC736FE4D46DULL;
        aWandererF = 0x8683E2F9A0B07881ULL;
        aWandererG = 0xAB8531AA4BA40F17ULL;
        aWandererH = 0x8FEE0B71C69CFF67ULL;
        aWandererI = 0xC893436F8496EE80ULL;
        aWandererJ = 0xB20431F1B72CB508ULL;
        aWandererK = 0xE6FEE27DE0573765ULL;
    TwistExpander_Mirfak_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Mirfak_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Mirfak::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xAB4D04CBE9663131ULL;
    std::uint64_t aIngress = 0x98E68946643C480DULL;
    std::uint64_t aCarry = 0xC34981CD91446C76ULL;

    std::uint64_t aWandererA = 0xC52DD71179AE4338ULL;
    std::uint64_t aWandererB = 0xC7FA91F26B2975C6ULL;
    std::uint64_t aWandererC = 0x806675F2BE8E623AULL;
    std::uint64_t aWandererD = 0xEA5DB4D9ADA83772ULL;
    std::uint64_t aWandererE = 0x94CE780A0803FEF2ULL;
    std::uint64_t aWandererF = 0xF2BFF487705093DCULL;
    std::uint64_t aWandererG = 0xA37B0781CC252BF0ULL;
    std::uint64_t aWandererH = 0xA88B7FED5A1725C1ULL;
    std::uint64_t aWandererI = 0xBB0A3E568538BB9CULL;
    std::uint64_t aWandererJ = 0xB73D96D0698786F2ULL;
    std::uint64_t aWandererK = 0xC343E15FDF431F44ULL;

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
    TwistExpander_Mirfak_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Mirfak_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Mirfak_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Mirfak_Arx::GROW_A(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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
    TwistExpander_Mirfak_Arx::GROW_B(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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

// SmartSquash candidate 21 of 33
// Exploration cases: 100000000
// Nearest-family diversity: 922 / 1088 (84.74%)
// Total distance from earlier candidates: 18692
void TwistExpander_Mirfak::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    static_assert((S_BLOCK / W_KEY) == 16, "SquashInvestToKeyBoxes expects 16 invest fragments.");
    static_assert(H_KEY == 8, "SquashInvestToKeyBoxes expects 8 key rows per box.");
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 7U), *aFragmentB = aIceLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 1U), *aFragmentD = aIceLaneD + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 297U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1308U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1396U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 157U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 14U), *aFragmentB = aIceLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 9U), *aFragmentD = aIceLaneD + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1574U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 695U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1832U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 607U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 12U), *aFragmentB = aIceLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 4U), *aFragmentD = aIceLaneD + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1272U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1173U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1121U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 919U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 4U), *aFragmentB = aIceLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 14U), *aFragmentD = aIceLaneD + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 707U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 314U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 938U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 40U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 6U), *aFragmentB = aIceLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 12U), *aFragmentD = aIceLaneD + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 80U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1944U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 798U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 952U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 2U), *aFragmentB = aIceLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 7U), *aFragmentD = aIceLaneD + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 429U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1134U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1910U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 667U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 9U), *aFragmentB = aIceLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 11U), *aFragmentD = aIceLaneD + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 378U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1855U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 120U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1651U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 8U), *aFragmentB = aIceLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 13U), *aFragmentD = aIceLaneD + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1042U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 808U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1076U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 993U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 13U), *aFragmentB = aIceLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 5U), *aFragmentD = aIceLaneD + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 636U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1955U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 849U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1067U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 15U), *aFragmentB = aIceLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 0U), *aFragmentD = aIceLaneD + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 2009U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 468U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 415U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 652U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 11U), *aFragmentB = aIceLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 10U), *aFragmentD = aIceLaneD + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 104U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 841U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 306U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 4U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 0U), *aFragmentB = aIceLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 3U), *aFragmentD = aIceLaneD + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 790U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 144U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 698U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 334U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 10U), *aFragmentB = aIceLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 2U), *aFragmentD = aIceLaneD + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1765U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1149U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1701U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1500U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 3U), *aFragmentB = aIceLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 8U), *aFragmentD = aIceLaneD + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 234U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1962U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1640U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1040U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 1U), *aFragmentB = aIceLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 6U), *aFragmentD = aIceLaneD + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1352U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1591U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1402U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 553U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 5U), *aFragmentB = aIceLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 15U), *aFragmentD = aIceLaneD + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1732U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1303U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1257U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 420U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Mirfak::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xADB033E5573B7A4BULL; std::uint64_t aIngress = 0xB367642307EDC3EAULL; std::uint64_t aCarry = 0xFFA44B03A8D89CD9ULL;

    std::uint64_t aWandererA = 0xF3FD13B824DFD28FULL; std::uint64_t aWandererB = 0xBFE066BE1D7EED42ULL; std::uint64_t aWandererC = 0xFCDD1315817D14BAULL; std::uint64_t aWandererD = 0xC961ED31F8F9BCBBULL;
    std::uint64_t aWandererE = 0xE7AA6D22F0075BEFULL; std::uint64_t aWandererF = 0x8C0BCC298B0D4D2BULL; std::uint64_t aWandererG = 0xD595B939163E5C7DULL; std::uint64_t aWandererH = 0xD7107AC3AB3FB33CULL;
    std::uint64_t aWandererI = 0xB3DCE6817B30D936ULL; std::uint64_t aWandererJ = 0xB9DCC6ADF9F2981DULL; std::uint64_t aWandererK = 0xF7C83745CE6BF1ABULL;

    // [seed]
        aPrevious = 0xEABFE593E2EFEC65ULL;
        aCarry = 0xE93EBD512A4D866FULL;
        aWandererA = 0xB07FD5C28DA7C49CULL;
        aWandererB = 0xB87425D857839F6AULL;
        aWandererC = 0xDD659D2A336E68CAULL;
        aWandererD = 0xE66773DF3F1A86E7ULL;
        aWandererE = 0x9183B47E5F04F1E6ULL;
        aWandererF = 0xD157C9C5FE57C8B8ULL;
        aWandererG = 0xDEC2315F570E2454ULL;
        aWandererH = 0xDDD25C7CFEBF31A2ULL;
        aWandererI = 0xDD720B0435AF9134ULL;
        aWandererJ = 0xCA9D9C84DAF56A69ULL;
        aWandererK = 0xE13343B3FC6BD8A9ULL;
    TwistExpander_Mirfak_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::Twist_C(pWorkSpace,
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

    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseAConstants.mMatrixArgD;
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
    TwistExpander_Mirfak_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Mirfak_Arx::Twist_E(pWorkSpace,
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
    TwistExpander_Mirfak_Arx::GROW_A(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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
    TwistExpander_Mirfak_Arx::GROW_B(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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

// GrowA candidate 21 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 10879; nearest pair: 499 / 674
void TwistExpander_Mirfak::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4299U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3072U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5789U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1889U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6972U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6240U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6823U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7187U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8166U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6982U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4438U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6939U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1376U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7090U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6754U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2523U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2009U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 689U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 758U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1958U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1277U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1044U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1144U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 773U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 377U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1504U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1851U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1231U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1808U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 815U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1118U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 169U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 802U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 528U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 521U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1621U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
}

// GrowB candidate 21 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 10876; nearest pair: 495 / 674
void TwistExpander_Mirfak::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4891U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7574U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7320U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3771U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5428U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7336U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8114U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5164U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4791U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 978U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2948U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2528U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5138U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3130U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4194U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 608U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 381U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2006U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1392U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 65U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1699U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1599U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 750U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 945U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 77U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 395U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 921U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1035U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1812U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 917U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 671U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1192U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1128U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 599U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 879U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1400U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
}

const TwistDomainSaltSet TwistExpander_Mirfak::kPhaseASalts = {
    {
        {
            0xCD2C944CF4E764EAULL, 0x002D1FF4F5E6C1A8ULL, 0x1E1E8E1754CA24A1ULL, 0x3F4FF0765542196DULL, 
            0xDBD52E3E0C51A8D8ULL, 0xE04FF3EBD04B24D8ULL, 0x44EC3E5B90876546ULL, 0x9BAAEC0423187933ULL, 
            0x2134F81FBA12D840ULL, 0x8EF96D0DB2967EFEULL, 0xD0E743B5EC5ACC75ULL, 0x5036F33257EBD2C3ULL, 
            0x4CF0D833D0455333ULL, 0xCD15867105048636ULL, 0x54E5CACC37476A89ULL, 0x37FA516263B87505ULL, 
            0x1F58A7B93217D09FULL, 0x082007C811A51B85ULL, 0x9D042E37EF2B81BCULL, 0x52AE437485E30341ULL, 
            0x91A35AFC05D525CBULL, 0x63C82DC583851B4AULL, 0xC50086137F6528AFULL, 0xED7A68BDEBFD1C08ULL, 
            0xCCB49AF3A40D0A46ULL, 0xB43A16C7A0E465DBULL, 0x5BCE17022EBA3F7CULL, 0xBA013E18D17ED5EEULL, 
            0x5AB43B90EB712689ULL, 0x554691FC36B87AE5ULL, 0xA8EECB8EC8CA5F40ULL, 0x8D177A639B43E653ULL
        },
        {
            0x55C31A5271FFA478ULL, 0x5CAB3151FA4AC090ULL, 0x3B4A3EE9F4447775ULL, 0xB77111764DC21126ULL, 
            0x6A930A8C67D92828ULL, 0xEC596B9808CF0740ULL, 0xFE4512ECED0C88E8ULL, 0x5B7C47DCEB4E682EULL, 
            0x75D260912CCC90ACULL, 0x2F27D39F66334808ULL, 0x6856DF3AC9838913ULL, 0x93BF20D80A7686BDULL, 
            0x2DB593A1D05730CFULL, 0x1E2FF362EE73DA08ULL, 0x8D7800EFC1374E5FULL, 0xB3FAECB930BD97D4ULL, 
            0xD8CBD81A4C3245F1ULL, 0x3FBD6127F990D05EULL, 0x6C2B5BDBDF7F3EF0ULL, 0x4C0733FA275CD295ULL, 
            0x08572863719DCBB2ULL, 0x684197DBB65C449DULL, 0xA1135F536F24AF4FULL, 0x60EF8541FA3D79EAULL, 
            0x58BD6738EA35DF06ULL, 0x4DD88BFB573145D6ULL, 0xF06EAA063EE1EEF8ULL, 0xD9D8D3B191ADF2BDULL, 
            0xC1F53C10A1C6A017ULL, 0x485DA334E59A3042ULL, 0x4679D44A0B1914C9ULL, 0x98D365652DBD10B5ULL
        },
        {
            0x0F8574AD1D3C9188ULL, 0x5FD7FB07218A4FD7ULL, 0xAC7B8037423B6D10ULL, 0x1B7E3039E4A21068ULL, 
            0x9954C95A01D90A2EULL, 0xD124B6714B6ED3ACULL, 0xAF4AE1CD05FF177EULL, 0x13C9C8AA844B3C22ULL, 
            0xA1392A1D9884CAB7ULL, 0x12073778B159C70BULL, 0x68F9F8A3E8C1C2EAULL, 0xEA04641F108C4F32ULL, 
            0x4626FFE3AAF53F37ULL, 0x07D723DF404A9086ULL, 0xA2A080F5577EB8CAULL, 0x3A809D88EABBE890ULL, 
            0xF204EC2502CDB369ULL, 0x690379E7668AFF7DULL, 0xF27349DA18AD7D2AULL, 0x0C4124E63C79582FULL, 
            0x7EC209691907915BULL, 0xD3AAFF79EE998C43ULL, 0x7874E58811A85EE2ULL, 0xF3F67035B461CABBULL, 
            0x403B49FE46335B5BULL, 0x94F362E1156ECE18ULL, 0x01EF79F9BD297C4DULL, 0x66C7B39B46B155A6ULL, 
            0x57496D5B400585BDULL, 0x3FC73DA39C26E6CFULL, 0xA3C4040852EB6E90ULL, 0x9D46168651B89139ULL
        },
        {
            0xB10EFC7510119918ULL, 0x820C660868A8D508ULL, 0xEA9199A7A56E8FE7ULL, 0xB5009AAAECE43091ULL, 
            0x4552118DACDC7879ULL, 0x8F2B197F30BD6BC1ULL, 0x8E5DED351128D6D2ULL, 0x97992A72098F06B8ULL, 
            0x1F50D44C97EE49B1ULL, 0x7D86334420FCA4C7ULL, 0x3A9D5BD5E369B243ULL, 0xEB4C31F5219BB3C6ULL, 
            0xBA610FD6EE8F65AEULL, 0x0509B7790B607D8DULL, 0x13EB3E6F018C19B5ULL, 0x25BE3821DAC4DE92ULL, 
            0x4B3C4CBB2C6E9A4FULL, 0x0686613A369206AAULL, 0x97626BF42ED01E20ULL, 0xADE14B897D43F51DULL, 
            0x70D183AD508F7F6CULL, 0xE74A6317671378D4ULL, 0xB9D2C7B4E9EDBFEAULL, 0xFFA2E188B18199AEULL, 
            0x525A44E882F02FB7ULL, 0x4AC917F4960265A4ULL, 0xE5DFD2F99BA2DADAULL, 0x3CA2DB94FE9A8C7DULL, 
            0xDEE7492978BF8DE1ULL, 0x37DA94D6F30FD7DDULL, 0xBA9EB5CA545B917FULL, 0x615E9EDDB6567989ULL
        },
        {
            0xBBCDDEE45647D72AULL, 0x420F76B283AB5E94ULL, 0x9383AAB55AEFC683ULL, 0x79FE1CE4B2561B3AULL, 
            0x0F44CA1C65DF0617ULL, 0xA52D5F3B87676078ULL, 0x119BABB86DA5997EULL, 0x4377F39CC9CE371DULL, 
            0x45451A328933D38BULL, 0x49DC13FCA18343A6ULL, 0x3A92D395AE78428DULL, 0xB32FE245088E74AEULL, 
            0x7A1A525616307DB0ULL, 0x590E2C2030F56FA6ULL, 0x958BA549A9504EF0ULL, 0xC37A9C1F1F6E1F29ULL, 
            0xD4BA128BEDFF6FE8ULL, 0x3D0CD5C6E3ECFD3DULL, 0x5C242834BC4D6591ULL, 0x32C240D068505BBEULL, 
            0x0E9C9DA5A46C83CBULL, 0xA077B0DDA22A2A21ULL, 0xA9A224CD464F0080ULL, 0x331D35EC1EED4A88ULL, 
            0x6340C1F698E29BE6ULL, 0x0473508259BA5042ULL, 0x24287F2E631EDE96ULL, 0xB0F994F51871770BULL, 
            0x5B488B74C61A56F5ULL, 0x271ECBA141B1791AULL, 0x2223E8EB9B3FBE08ULL, 0xF8933116EC51633DULL
        },
        {
            0xC25A93A4301C1919ULL, 0xA500771D77BB8274ULL, 0x170932DB858CF8BCULL, 0xB03F33AD843A6FB5ULL, 
            0x227197815AF1C714ULL, 0x1513BD10F8EE7114ULL, 0x8D6424868B47062DULL, 0x9E549440498F914BULL, 
            0x6F2953DD51651E65ULL, 0xBA61082C6621FB7AULL, 0x1A77B4627BD6FC55ULL, 0xB61A437A74D9B2A3ULL, 
            0x9EAA4F08F079B0E6ULL, 0xF46524A8CB25C35EULL, 0x975A16C86B49D4C0ULL, 0x69726BBB150B70E8ULL, 
            0x86D94A02A52A7A65ULL, 0xB42CCB503680273FULL, 0x7EFF058340CD796BULL, 0x20111485BB4A2DE3ULL, 
            0xECB639940A390874ULL, 0x3A903B84C3B15D2DULL, 0x63BA2E54C3DA4BAEULL, 0x00F1DCBD10E76D6FULL, 
            0x37131B60AFD56B3CULL, 0x76A5B556E8DD25C7ULL, 0x8B009CCE421B47E2ULL, 0x11E723E871E7D01FULL, 
            0x1158AF78A44DB938ULL, 0x6568E9287B704D19ULL, 0xA9C27A9427B7290CULL, 0xA7DAFE54B65F4CC2ULL
        }
    },
    {
        {
            0xA1B74C8D4F0FDA46ULL, 0x3B5BFD0ED2674F13ULL, 0xBDB9CC0A7B461081ULL, 0xB73EBA538C88089EULL, 
            0x3F0E0D17589A01C0ULL, 0x75418BDC3A1D3B1EULL, 0xECF2E6F5D2DA5B42ULL, 0x280D7579BF9E2A36ULL, 
            0xAF5A9F42323815A9ULL, 0x18718FB07A19BAF6ULL, 0x5D301CFD0F4EC05BULL, 0x60568E423FF6BB09ULL, 
            0x8A50A78D616B7EB9ULL, 0xABAF4947298EC245ULL, 0x5AB9AB0CE1915A01ULL, 0xBE2FE73E79117E87ULL, 
            0xA24D523FAE8A4BE8ULL, 0xA9CBC80708C218A6ULL, 0x00500C67A6C0039BULL, 0x292DC74D1147C8E8ULL, 
            0x21BB54913E673F14ULL, 0x9893E6AA168A4B83ULL, 0x010044F9791FE549ULL, 0xF51619A6A8D3F725ULL, 
            0xF84AA43E830E6A33ULL, 0xB9A838AF5977975CULL, 0x3BC22E68DA90FDF8ULL, 0xF6949F88227B8857ULL, 
            0x1554737ED5159760ULL, 0x8C98268421869309ULL, 0x3DA0DBE6C2859199ULL, 0x9456316E1121FF7DULL
        },
        {
            0xC94CB72F9285BE22ULL, 0x1EB103C95E607553ULL, 0x212E9406A5E24A6BULL, 0x80D5189430442470ULL, 
            0xDCAA5ADF5DDA9729ULL, 0x1E37A0EA08E57EB7ULL, 0x1AB8ED652C4D6A0DULL, 0x074397456DD3871DULL, 
            0x875B0404398E4AA1ULL, 0x5CB8039569CEB81DULL, 0xFABD07326358F918ULL, 0xF3CFEEA9326F22F5ULL, 
            0x70D5DB2F5B00395CULL, 0xDC2189BF78CC1081ULL, 0x14FDD8458FAAC07DULL, 0x1E1CCABCEF195D08ULL, 
            0x38F5B82A62A3CA64ULL, 0x503B1003EDFB27BCULL, 0x7B5AC3BD762B0259ULL, 0x08D6D7E183A97D00ULL, 
            0xE688081E5D27D2B3ULL, 0x9FC0032AD3691EC3ULL, 0x472660ABEE60455CULL, 0xA8D9D590E583516DULL, 
            0xAB2FF298402D6083ULL, 0x17BB671A76C6812FULL, 0xC5F92FDA86AA4F9FULL, 0xD878CB344DDBB796ULL, 
            0x58F0965C572D9110ULL, 0x31E69C66C83AC8B3ULL, 0x52ACD735A001CECEULL, 0x707D8CDBC168577BULL
        },
        {
            0x85B19A0BC64510F7ULL, 0x423762F38CB65AC7ULL, 0x598484BBD493D51CULL, 0xE446D24472EEE8DCULL, 
            0x9AB6F643FA095F30ULL, 0x366D496D068F7F3BULL, 0xB8603272635B2769ULL, 0xEE60CBECA3EFC578ULL, 
            0xEE954BFBD1EBA94BULL, 0xB1581848789750B5ULL, 0xB73C6DDB77FCC725ULL, 0x896ECAE35A52FF4EULL, 
            0x9800F4A7ABD0BF29ULL, 0x8211827E04460BCDULL, 0xD6732EB5F96E79A6ULL, 0x509C8820DD9A507CULL, 
            0xB677A4EC0BAA49D9ULL, 0x2C767C9570BBEAD2ULL, 0x2726097EAC0D7819ULL, 0x9F353876194CA49FULL, 
            0x1F2FED96CBB9B8CFULL, 0x06C78D6EFAA133E3ULL, 0xB2152D397BF9EA2AULL, 0x005D046273DCB6D0ULL, 
            0xFF7302D42AC6A91AULL, 0xC5AF02228097658EULL, 0x267A4E2D1012AB77ULL, 0xF486422BA061F500ULL, 
            0x042F1369B9D2F830ULL, 0x522BD8EDB065C3F6ULL, 0xCD9640DFE437E347ULL, 0x5B7DCCE18D4F732EULL
        },
        {
            0x9A628C9EE229142DULL, 0xA0648CEDE60148BBULL, 0x800AC0AD3C9C7B08ULL, 0x5A63CB8034172249ULL, 
            0x430E493C038D6F79ULL, 0xB15D6F46939E8F9DULL, 0xFCBBB9B13FF98534ULL, 0x405CA85CC4281ED6ULL, 
            0xABA60F29138752DDULL, 0x4D47470ACE757C94ULL, 0x2D352BB279466234ULL, 0xCCC7AA8653AA6B5DULL, 
            0x0B1A296D22D7B2C3ULL, 0x2A50831382EBFCE6ULL, 0x1EA4C5A3D38F4373ULL, 0x07004413C6D4941AULL, 
            0x03FA6AEB114DCC69ULL, 0x0C3DBA06962B6613ULL, 0x812B6AF3E1FBEF81ULL, 0x74F5697644C681ABULL, 
            0xEA5F66584140C819ULL, 0x039D4EDF951B1CC1ULL, 0xF8B79D30CE226C9BULL, 0x05540BB63891DB1DULL, 
            0x9678EBF471A2D6DEULL, 0x2B159A23B6AA3FF8ULL, 0xC0C892EEE9F018E7ULL, 0x28818FE044191A4AULL, 
            0x9A355B5CA01ACA58ULL, 0x67CF3A2E05F2AA97ULL, 0x2FB4CCF294EF2849ULL, 0x7F7A1181B993CC7DULL
        },
        {
            0x0BB3C8774A545724ULL, 0xCAED037754D69375ULL, 0x89EFFE0488B9A171ULL, 0x5A8BF6F7778F075DULL, 
            0xF3FB2F2574DD076DULL, 0x9694657A88753D15ULL, 0xD8CD3EC47D3D3170ULL, 0x3983B51A99754AC2ULL, 
            0x6C85E9C9899B8126ULL, 0x5515A0CC2F19EE2EULL, 0xD7D16D580F61E3E9ULL, 0x02BAA031E7CB7247ULL, 
            0xAF2C3788E266ABE2ULL, 0xDFFB1C6F1A74F100ULL, 0x4AC675B534ED4B87ULL, 0xCBB4281364E4B3BEULL, 
            0x6056E9BFD23EA321ULL, 0xC55F7FB28D97C8FAULL, 0x321C0BEC9D972AD5ULL, 0xBC6BFA58525DA168ULL, 
            0xA39F5197CA542A94ULL, 0xD447E86C53948777ULL, 0xE687966B7C17D6A7ULL, 0x085C90B7AADA8251ULL, 
            0xD8A7269E20923CC4ULL, 0x2AE6804D139A9221ULL, 0x1ECA5E4C31186E7AULL, 0x73AA4C3A4B78A356ULL, 
            0xA1CDE64A7C382994ULL, 0x7EFAA4C6289339A8ULL, 0xA922D9D165FB8846ULL, 0x819AD96179919494ULL
        },
        {
            0x46D5358E2F608639ULL, 0x1C1E4137330E62F3ULL, 0x5E893B582E77FE4AULL, 0xF8655283460D5EC1ULL, 
            0x7F9BB67EE2476E33ULL, 0x27266680B1F634C3ULL, 0xBD919383FED8EBA8ULL, 0x2F4746256265857BULL, 
            0x9FF5D07003F29591ULL, 0xDA6AC48F6F1E8150ULL, 0xE9D2978DE7F90068ULL, 0xD0DAFAFA614D1AC0ULL, 
            0x20E79AF2D1732FE0ULL, 0x61F4BBCF4846054AULL, 0xCA207CA4B27E7A73ULL, 0xA912FA68523BF93BULL, 
            0xA7091523655D391BULL, 0x80D4BAB52656176CULL, 0xBA69383F8CAFF45DULL, 0x3E4376D285F18338ULL, 
            0xD1180634F3A817FAULL, 0xF107EBD4F2CBB52DULL, 0xF812CE707B2F9CCAULL, 0x7C37AB67A818FE69ULL, 
            0x0181BE204C65E172ULL, 0xA0DEFC886D7AAA2BULL, 0xBCAEB3C487DD4A02ULL, 0x77760E7063C7BA45ULL, 
            0x9D4E6D0005EA87F9ULL, 0xAEABD9F67CCDE4E5ULL, 0xDE7A1747A07583AEULL, 0x6D15893791FDE5DAULL
        }
    },
    {
        {
            0xC833388641B3FEA8ULL, 0x08D7919A86430CBFULL, 0x30BFE19140607A15ULL, 0x2B7CCE098AE73534ULL, 
            0x37685C40E4AC2EA8ULL, 0x6968B3A87DA1A1B6ULL, 0xF7698EBA6AE118D0ULL, 0x81ED95A983CF34B5ULL, 
            0xBF8A5F3F4E635F18ULL, 0xC614BEF367E86730ULL, 0xE7BD542042DFC283ULL, 0x75C66E34B25553DFULL, 
            0x02DE41118199FFC8ULL, 0xC480F8495413670AULL, 0xF71D3CD5948F7DF5ULL, 0xF82992C924208E30ULL, 
            0x84BFF77384DCB019ULL, 0x68346BDBE3522483ULL, 0xEC710C3C00C5F086ULL, 0x692CD5A413B2D105ULL, 
            0xC04699070E820B89ULL, 0x786BCB6414A88E98ULL, 0xB5E2A3D66B3532F7ULL, 0xF814F2B5D8D4E3A9ULL, 
            0x065BEC7BA359257CULL, 0x6AAA24CE8FC923D7ULL, 0x1AAF923121D82E94ULL, 0xDF3912222DCBD68BULL, 
            0x454D587D93985D22ULL, 0x289007978F91B98CULL, 0xE8947665530212CEULL, 0xC1DAB2A306DF4F5AULL
        },
        {
            0xAABF8C97E4683F9DULL, 0x05BCF1E9D52B4FE0ULL, 0x8353860023CC3F2CULL, 0x5212951D3A632E24ULL, 
            0x96D8DD0D5DED39F7ULL, 0x2C9FDF4CFC5A1980ULL, 0x0E5A00A61127E36BULL, 0x2264B67E53DFCB0FULL, 
            0xA56F01141CB1C95AULL, 0xF7C454CD8CC4ED04ULL, 0xEF48016B2236E317ULL, 0x3F29678581008F7DULL, 
            0xE7516A4FBADB75F0ULL, 0xB589749F6752EAA6ULL, 0x1363833B9725572DULL, 0x19B21D3F993FEED1ULL, 
            0xB5FE26291014AFD7ULL, 0x258AB70DE2805F83ULL, 0x4C1F8AB19E3D50BFULL, 0x688C7A09FD54040DULL, 
            0x5156D7F21FF72B15ULL, 0xEAAE7A64502B2E6EULL, 0x46E1A539B36C808BULL, 0x9B3D577BD01FFFA6ULL, 
            0x4E44F0B8124647E3ULL, 0x5EE1D22C7495275FULL, 0x9DE7A7E24D238DF4ULL, 0xECC9F1A8FB790FE9ULL, 
            0x3C8BC92E31FB731FULL, 0x9046F11D0AD1F0F9ULL, 0x5209DB7DC5815493ULL, 0xB48C98B148794FDCULL
        },
        {
            0x43C193B03172524EULL, 0xD618A93791B54054ULL, 0x3FED69FB04C43367ULL, 0xEBC33739B3E40977ULL, 
            0x1933D84BE34E0F38ULL, 0xFB035C01ED72245AULL, 0x18AADB1DFC0CFB2DULL, 0x24AF8FC112B8F90CULL, 
            0x244E7CBBFD8222ABULL, 0x09BC096500459EB9ULL, 0x97433937C3884AF6ULL, 0x0F47E0D72E861E0AULL, 
            0xE87BB92337254A28ULL, 0x024DA00C30C101BEULL, 0x6C9BF4698B53D58EULL, 0x96D53135D74E5D22ULL, 
            0x389C48A2468F9DEBULL, 0xDD635BBF0A51C203ULL, 0x7E87B5E8E54F3998ULL, 0x022EEC2791FFBC94ULL, 
            0xD847C2F098860EDDULL, 0x4EE6DAAD37758F09ULL, 0xAAFD5704ACF89F57ULL, 0x42DAAE53CAA5B185ULL, 
            0xA131C772814163F2ULL, 0x9E375EB51E7563D7ULL, 0xA2D7A2F98B95D303ULL, 0xF393F16C05E70762ULL, 
            0x7F0EF58480F1CB76ULL, 0xA9713850682A5773ULL, 0xB1F936AE57CACE62ULL, 0x3D33DC6DCE124B27ULL
        },
        {
            0x3BD2DD91CA8DC327ULL, 0x00A33009B34A2D4AULL, 0x1B4598F2F0DFAA18ULL, 0x79A3D141971480E5ULL, 
            0xCD8974C013BF1602ULL, 0xBC858ECE89063D9FULL, 0xAC7A82B228B26857ULL, 0x7059014BDF257FAFULL, 
            0x3BA095AB8FD9DCD4ULL, 0xC6BA26FB8CE58DE5ULL, 0xC197F02A9BE79FB8ULL, 0x3927C7F2BBE60B82ULL, 
            0x2A3CF7090F13304AULL, 0x209A3D0FA2598E8CULL, 0x123FEE187BCFB17CULL, 0xE69FC1AC3E4C330DULL, 
            0x397A9CAE8108A3FFULL, 0x177CCAA4B5A72459ULL, 0xCCFE79FA586436C8ULL, 0x342B01FBB4C964FDULL, 
            0xB93BC4BEA29FDCA6ULL, 0x3CC0E7AB16556CBBULL, 0x3E4659AB18D61057ULL, 0xEFB4AA0EFD39FC80ULL, 
            0x4D438F2FA99F0789ULL, 0x07817C479D241C8CULL, 0xB5D943B0E13799DEULL, 0xF6CA785A44E5DFAFULL, 
            0x8E78290E74B08BAFULL, 0x92E4012E64B95B4AULL, 0xB3BAC1E6DDAE3DB8ULL, 0xFC4A0EE0713368DFULL
        },
        {
            0x80BAEC1A1B4BDCDFULL, 0x9237A13543C7712AULL, 0x50A665B0E4E77725ULL, 0x7488BBF2D6B60D45ULL, 
            0x6AC1507419AD8DBFULL, 0xDD4A8F68BBF7650DULL, 0xADB5A9811C450430ULL, 0xC5463052506AF242ULL, 
            0xA59C08388FE922BAULL, 0x40CCA1FAADDB85D7ULL, 0x10569B8AA074BFF7ULL, 0x7F134C845EE1E2F8ULL, 
            0x5B83835BCB4F0901ULL, 0xFABCE35ADBF7A815ULL, 0xD8D973013B9316E7ULL, 0x11152998A53B963BULL, 
            0x4D3D929840554130ULL, 0xA0E70FB8D8BEE659ULL, 0x20410C1D682BADC7ULL, 0xD4D461038E951B07ULL, 
            0x194F16F566486287ULL, 0xD71F865F857F5297ULL, 0x9269F69019610B02ULL, 0x89A6B8F31F0ED02CULL, 
            0xDEBEE9386D6391C9ULL, 0xFEAC88D1D73C3F21ULL, 0x494FD170274D55B6ULL, 0xE44E8BDFF1355B65ULL, 
            0xCE86779E7FEFF308ULL, 0xAE77EDEC95FFF12DULL, 0x7168145EBD5256E7ULL, 0x40E2548B5A6F4AB6ULL
        },
        {
            0x128FE157D0D0EE49ULL, 0x379F0D464AEB61C9ULL, 0xB5819A0D1A711DDBULL, 0xD58D3370349F8FD1ULL, 
            0xDBBDEF65F0BC4AE3ULL, 0xBBB786531B5B4E76ULL, 0xB3DF410FFCC26FA6ULL, 0xF6651B894DE177C5ULL, 
            0x827893067F55FF99ULL, 0xB4295AC928FFD0D4ULL, 0x915EE8C773BE3DBAULL, 0x612C868F560015A5ULL, 
            0xEE3D08D7F6C27AB8ULL, 0xCCB4916099DDAF7CULL, 0x7123A90571A15F53ULL, 0x4DD73DA128341CF4ULL, 
            0xDF11BC7BD027ABA7ULL, 0xCFC83683358609E4ULL, 0xE2D4A471B260E920ULL, 0xC313B75994192D9EULL, 
            0xDB2838E6DCDFB25FULL, 0x11775BC29E21A0C8ULL, 0x3298492DDB0A4D20ULL, 0x4FC02EDA2F856615ULL, 
            0xB0E20798F90C4A02ULL, 0x4F4C69E695CE05F0ULL, 0x8DFA37A3B4C2AC37ULL, 0xB5C83D234059EF91ULL, 
            0xCF4F75B6ADB32AA3ULL, 0xA69F7082ADE05FA5ULL, 0xFF012BC5FACE336AULL, 0x7CBC6C638D0916E7ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mirfak::kPhaseAConstants = {
    0x85E98D92C3189B3BULL,
    0x24E32E6983AC7766ULL,
    0xE0B6FD802B075E63ULL,
    0x85E98D92C3189B3BULL,
    0x24E32E6983AC7766ULL,
    0xE0B6FD802B075E63ULL,
    0xB455476772B096EBULL,
    0x2BB0B0E72CF02575ULL,
    0x89,
    0x02,
    0x93,
    0x97,
    0x59,
    0x82,
    0x90,
    0x3B
};

const TwistDomainSaltSet TwistExpander_Mirfak::kPhaseBSalts = {
    {
        {
            0x86726182F89E7E19ULL, 0xC9048EC3A49566A9ULL, 0x34FE11BE20EFAE08ULL, 0x09B44853961CBA86ULL, 
            0x1CFC8E6A56ABEBE5ULL, 0x346438834CE40F97ULL, 0x0116DD58C3F218A7ULL, 0x22AA2B335B98802CULL, 
            0x27FB10388CF270E0ULL, 0x1B7714B7E9477EBBULL, 0x613732663ED53059ULL, 0xFA08D98E94F21BC5ULL, 
            0xDC2EEE2F8FF30830ULL, 0x8B82EC4BA72DC2B8ULL, 0x64571485DCAFD41CULL, 0xCDF9F4F1A17E0303ULL, 
            0x1F76F72415CA27FDULL, 0x0E1F08ECDEDC8787ULL, 0xF6AEE76C179BBB21ULL, 0x9E2DBD13C4C3D738ULL, 
            0x0E41AC4A64D56D22ULL, 0xF45404D6DC549CD3ULL, 0x9E67711443CD324FULL, 0x9A1E3F19990CFBC9ULL, 
            0x2295DE057B6BDB04ULL, 0xEB95833BF6863FCFULL, 0xAE10C36FCEC3DB80ULL, 0x273A0032DBBB68ECULL, 
            0x54F48134151C1BCAULL, 0x3AEBC01EEA45EEBBULL, 0x142AF015EDB7B4E2ULL, 0x77FDD3A72BC27C98ULL
        },
        {
            0x2CD39BE11FB5E7D0ULL, 0xCEA261D726C31345ULL, 0x1986E46AEADBD3F7ULL, 0x29BF0A472B03069AULL, 
            0x038C82E3AA2BBD81ULL, 0xC96151DF58463A99ULL, 0x59DDAE7B512CE637ULL, 0xC16AD5F6581444D4ULL, 
            0xCCFAE7FE88DE602BULL, 0x352F7038CC7DF413ULL, 0x0742468F5843CC11ULL, 0x40DD0FE33A5660D6ULL, 
            0x2DE3CB713C886857ULL, 0xE95F6DF475562D6FULL, 0xDBE76F63A24B6EADULL, 0x820058187C9EC2FCULL, 
            0x1EF5AC2E35C0C07DULL, 0x414BF3F234BD63B0ULL, 0xDF7D07E8414707F4ULL, 0xAE91AA270D957630ULL, 
            0x33152F34B295B8B7ULL, 0x6B60B8C2BD847EF0ULL, 0x4791A2C4B2E51E7CULL, 0x8AEF38751CA2C434ULL, 
            0xB1E02413DD0903E9ULL, 0x3FBB5C410BB8F54EULL, 0x48C3078D12944C6FULL, 0x8499324EE7CECBAAULL, 
            0x16FEAE6122485637ULL, 0x80FB1419A5263110ULL, 0xA3061D0FA472FAE2ULL, 0x845C5FB4F7D03A3FULL
        },
        {
            0xD5A967E8DD4EA707ULL, 0xB12FD9CFC0A23954ULL, 0x83D9CA4BFA25F80BULL, 0x8870F8234CF0E85EULL, 
            0x5DCCE9B81B3795E8ULL, 0xB6F8C23646553839ULL, 0x2D82533474AF81A3ULL, 0xFD6FDC7699077220ULL, 
            0x9A77806A2BE592FBULL, 0xCA7850B1390CC493ULL, 0x807B98031687DF0CULL, 0x8DF0A8BC77505BB9ULL, 
            0x41DDAE959F60FEB2ULL, 0x74C5ED1D07633F79ULL, 0x470A6DAB76358C71ULL, 0xC7B0EAA6DD430C14ULL, 
            0x90F5313DC768B280ULL, 0x75188302FB874F2CULL, 0x412F2E12BF743FA3ULL, 0x04F8E7DBC7DAFF36ULL, 
            0xD4C11CA66260A8CBULL, 0xD8D36CA26286E7FBULL, 0xD640A4E1966823C0ULL, 0x50B1A07BCB13D54CULL, 
            0x856452076E6C338BULL, 0xF8322A3EEC75D7CDULL, 0x2461C1F06D889B0FULL, 0xDA3BEBF7541BB81EULL, 
            0xC11678FD651CCD23ULL, 0x07D88F1D233325B9ULL, 0x64E387D72B3E8571ULL, 0x5ABDAA5F92A650F2ULL
        },
        {
            0x3CB160B1DC25C71AULL, 0x594BFCEE125363B2ULL, 0x23237D480B0FD948ULL, 0x99D0C58BC67C5E0CULL, 
            0xF8C18CDAA492F254ULL, 0xC1941EB1D1026998ULL, 0xBA96AF6DDBEFEB59ULL, 0x820A052D560DC70AULL, 
            0xA079E1281E24246BULL, 0xA9C45BB080172EDCULL, 0x462442EC0A27BC7EULL, 0x3564E3277694F0FBULL, 
            0xD839591ABEA2CDE3ULL, 0x8538EC8A55857E3BULL, 0x9AF8A57136260FE1ULL, 0x983B214BDC553E26ULL, 
            0xE5B844E422DE06DCULL, 0xD172085CB485CE3DULL, 0xF1F699CCEFA630EDULL, 0xEA7C0F2303021520ULL, 
            0x2DB89F9DA50D24E6ULL, 0x8B2F83BBDD3E9C65ULL, 0xF527D7B9FF0EB6A8ULL, 0x3AEDEC46E3AE8D7BULL, 
            0x1348706B1642460EULL, 0xCEECEC1D388ECDBBULL, 0x6B8FC9C71B66DFCCULL, 0x05EA60B294DFEC2AULL, 
            0x06EE9EB78A746EFEULL, 0xF7019D7B90A7D30DULL, 0xF1DC4F2EC4E66E06ULL, 0x987D5A668E3D4D69ULL
        },
        {
            0x438362078565E15DULL, 0xE3BA428DCC595DC9ULL, 0xF9182F46A3FF04F2ULL, 0xF7887354A7DADC0AULL, 
            0xF4CCED27B566D3B6ULL, 0x68E6A3DC39C5DBCBULL, 0xB7B4FEA31E870FB8ULL, 0x6A43C965C3E5D6A2ULL, 
            0xD7339A94A9B6FD63ULL, 0xDD9F702E94A3D7D0ULL, 0x48F347190D296F0AULL, 0x8192703BF1709D00ULL, 
            0x84739493A94EC62EULL, 0x0DCE7D8E5442E024ULL, 0x7863BFAF28A918FBULL, 0xD5FA829871B0DDBAULL, 
            0x4EC33BFC042CD491ULL, 0xBE6195A1947742E7ULL, 0x645977B36536433FULL, 0x2ADB94DE44C3D6A0ULL, 
            0x83BED43339CD2E5FULL, 0x878C3E15BFE198AEULL, 0x56469242F43C5725ULL, 0x1D63346142F2B4EBULL, 
            0x7583134514CE9615ULL, 0x320A9164BE8A4571ULL, 0xCCA89F32C338E4DAULL, 0x9B79D28854880033ULL, 
            0x7128734B8D6CC855ULL, 0xB349658E37FCF211ULL, 0x87F9EFA08592A800ULL, 0x544CAB72E63E0740ULL
        },
        {
            0xF049713ECF449FF1ULL, 0x01DE6FBBF9CADEF9ULL, 0xE3E69878EFE438F4ULL, 0x20C05CA29F33C1D2ULL, 
            0x1C088A56BF17B092ULL, 0xB650831A8B29A7B5ULL, 0xDDB4B9BDCFE55A75ULL, 0xA2F708B653E69312ULL, 
            0x5C8C809CBE620266ULL, 0x2D70078D86003E24ULL, 0xA411AB435F4C0601ULL, 0x0E66F9460017CED8ULL, 
            0xED6D08B02D13E5AEULL, 0x3D9D6F0D6E770AB9ULL, 0xB3548CBB706E6F05ULL, 0x1247E3D17DD5B78FULL, 
            0xE51AB48C34DDC930ULL, 0xAA65A200340854B8ULL, 0x98DCFC79848C3782ULL, 0xF2F60A6249C410D8ULL, 
            0x7BFA918A6A0406D2ULL, 0x7B5EDBFE4E2C8FACULL, 0x74B5B8DB95D53A64ULL, 0x6DB679F0EA9A7E24ULL, 
            0x45D27BC387DCF2A9ULL, 0xA0F807A96B1ADDB0ULL, 0xFED167F2BFD1E9F7ULL, 0xDE827BEF4DDEE3FCULL, 
            0x62C3BCA5E1E0A2CCULL, 0xC9E12AA8489F17A7ULL, 0xA113940084052628ULL, 0xD136176DD5E9D4C4ULL
        }
    },
    {
        {
            0xB4F59F703D1F1D9DULL, 0x71C2DF7FC65082DCULL, 0xAD7534B50C58E73EULL, 0x4FE9180F3DED51FDULL, 
            0xADEC4EAB92621AA7ULL, 0xF0D3ACBF377BDFABULL, 0x88A95E3D8BD8BB62ULL, 0x31F12B669A8751BEULL, 
            0xBCF0A78666019112ULL, 0x04BF38A035F8B999ULL, 0xEDC047C84ED8DBEBULL, 0xBBFED4021110387AULL, 
            0x95F19F179F5EA85CULL, 0xA13F3941B006634FULL, 0x8231744F5D5D85ECULL, 0xBBA15931F8CDE940ULL, 
            0xDE83E4C24FA53326ULL, 0x4EF8E83E5A2C3DF9ULL, 0x050B4486C1C8CD1FULL, 0xBB23A168233BC54AULL, 
            0x06CD76E8A20813BCULL, 0x464865CAD009C6F2ULL, 0x9C6448E304C56655ULL, 0xF9AC0C546CD7DDBEULL, 
            0xDB273D5F1CC22E66ULL, 0xE1F943485479D869ULL, 0xDCC3AB6A3013476FULL, 0x2665722946767926ULL, 
            0xEA1D913B82FB7AD1ULL, 0x0C7F865D983FC95BULL, 0x95F01C33E5B03C4EULL, 0xC25D10BFD42E532FULL
        },
        {
            0xB4E25840FB582491ULL, 0x92899C3420B301F0ULL, 0xEE1D413944D9FCE2ULL, 0xE1D059C33778BEBBULL, 
            0x4C093A4C38E85ED1ULL, 0xCD5110CA2493AE22ULL, 0x2328C80B4FFBBB98ULL, 0xF14A2FA04B770387ULL, 
            0x675E773AF2242AFFULL, 0xFB69B31A3E50E9FDULL, 0x30451AC8C6E8364CULL, 0x7912EDB5BB4E301AULL, 
            0xAD9BE73718D1B6DEULL, 0x092AC831DDBDF516ULL, 0xCABD2F4A128457BDULL, 0xCEEA318730C3DC3BULL, 
            0x843806F19461DA89ULL, 0x28241EB70701FD3DULL, 0xC1FA891B041C88EBULL, 0x8D69613A51697F75ULL, 
            0xBCBFB171C390D091ULL, 0xBCE0641278F99843ULL, 0x7BE7D3533921A085ULL, 0x3046756C2D7BE1CCULL, 
            0x8A2A412A40D3A52FULL, 0x4F700613ECA4D865ULL, 0xCEFD694550903948ULL, 0x4BE18386647B6217ULL, 
            0xE409F332F890B621ULL, 0xE797F7B19AC97E03ULL, 0x069900F7305792D2ULL, 0xC72E985FD6933C4AULL
        },
        {
            0xDC846424983C04EFULL, 0x30FEFC32DB38F109ULL, 0xA4F4DC6738AC8970ULL, 0x15E30AAA4A341BC8ULL, 
            0xE4685BEC18F58CC4ULL, 0xC25FBDF437991246ULL, 0xAB90B8C4494E5163ULL, 0xF800521761F06471ULL, 
            0xA7F32141E3B1D638ULL, 0xA804A6724CDA43E1ULL, 0x5B79A881F420AD60ULL, 0x12FAA73DCC91BCF9ULL, 
            0xED15C8CEBFF873D4ULL, 0xAC4747EF8683B829ULL, 0x2032A65ED8860AC4ULL, 0x5A47C7A3B0BC2B90ULL, 
            0xDA4CBA4455540D59ULL, 0xA9A059284AFEA13EULL, 0xE295FB55C4704939ULL, 0x92CAFFEA56C29DBBULL, 
            0x4A79A43959A99778ULL, 0x700C955FC5C14002ULL, 0xE877065F83F5EE74ULL, 0x0428C7A39E1FDF6CULL, 
            0xD611E912E53E81D3ULL, 0x51D91746FCD32F5FULL, 0xB8BC5ED3386EA811ULL, 0xEC420399A491FC83ULL, 
            0xEB6F416B4045EE56ULL, 0x6B22B6C3C7D5C5D5ULL, 0x802C9FFABD19267AULL, 0x4647E50B953CBBFEULL
        },
        {
            0xC09DF065068D511AULL, 0x4530E1C0FFE60874ULL, 0xEA947EDBBEE2D1AAULL, 0xB7F42A622F4D1AD3ULL, 
            0xB850A46C06AA4FDEULL, 0x836EB288BF5A629FULL, 0x9BB078899E05C903ULL, 0x7E595C7C54CEDE7EULL, 
            0xA8181F480C6AF298ULL, 0xDC8CCE2453D151D4ULL, 0x184D772C29E0B69FULL, 0x63797DD0F69F3031ULL, 
            0x612A6BBFC062422DULL, 0xBC6DD9167FB0C800ULL, 0x6CC065DA8D75634BULL, 0x32918C5A3862A438ULL, 
            0x115F0A8475DC3455ULL, 0x5DE5917667B704EFULL, 0x360A3FF24FC891B7ULL, 0x7D2D0485514A67D6ULL, 
            0x68193AC7EB6C5C53ULL, 0xFABF9B9D6C0B3C27ULL, 0x64DED77D498C6D6AULL, 0x551CDBEA93B793FFULL, 
            0x69C6589F29A9261AULL, 0x6A025E11AADFE4BCULL, 0xC1DC8B10163D11D3ULL, 0xF5846FC3E1C8CA90ULL, 
            0x8739B125396C6A52ULL, 0xFF1F4D2A618A1F7AULL, 0xDC6C30E492EA04D4ULL, 0xAE25B0F94210BF58ULL
        },
        {
            0xFFDADCD114B0A697ULL, 0xA10E7FE9D604B080ULL, 0x4C8DA619EF1A3697ULL, 0x70697B22D32749A9ULL, 
            0x58D04EF6B37D2685ULL, 0xE38B0549ED550E46ULL, 0x0B62130904704D9BULL, 0x39D70097E934C740ULL, 
            0xEFCA6AFC325EBFCEULL, 0xAC8A80C5E2887A8EULL, 0xFC0195CE8362F41AULL, 0x36C9EC6B98603530ULL, 
            0x477AE7C8BAC5D317ULL, 0x64E0ECE251AFABD8ULL, 0xD0F3505F83E60CA2ULL, 0x896B698FF98181F6ULL, 
            0xB42B47E1D8318505ULL, 0x9C876555DB4A3C5AULL, 0x25C3FC1F81FC131DULL, 0x2313E6457D9D5B8EULL, 
            0xA675C3329D9435A8ULL, 0xC486A3FEF50AAC91ULL, 0x2056D322E00B7AF8ULL, 0x96B863FF3BC40490ULL, 
            0x408430FBDE810412ULL, 0xC7C14E6CFD524BACULL, 0xDDF2610BBCD592FAULL, 0x2BC1B9E01DA6FADAULL, 
            0xBCD5675CDD59FE69ULL, 0x856F618AA078850CULL, 0xE51B53C3883AE1C0ULL, 0x9270629865D4F4BBULL
        },
        {
            0x6A532519EC66F7A0ULL, 0xD9F8C24CECDE334DULL, 0x7244AC05597F01E0ULL, 0x016833C22FE19BE1ULL, 
            0xBFBCC5F3AD950D30ULL, 0xC08BECA90C2EF4B3ULL, 0x301BC871779665F8ULL, 0xC71EE281731C8AD7ULL, 
            0x0E043F27A9772764ULL, 0x909494C24B52B966ULL, 0x0A4D6400B9B740A3ULL, 0xFABC82BF6AB1A6A4ULL, 
            0xF6A8DD7D72D87217ULL, 0x8B16AC2615CB1FCCULL, 0x83FE001C093D3050ULL, 0x186F61B7C58173F3ULL, 
            0x3287255FE40BB5D4ULL, 0xE86856FF9B055607ULL, 0xB681ACB676847927ULL, 0x857E0969BC757291ULL, 
            0x7D5CE074139D4F4CULL, 0x18AEFFE39AB65135ULL, 0x186AD31675EB44FBULL, 0xB28CD5E5495CD0FDULL, 
            0xBB3652B0A87B1322ULL, 0xE2F65C726012D6D9ULL, 0xD7A6CE170D267303ULL, 0xFCC72278C5ACBFDFULL, 
            0xF0C1088A14A5226AULL, 0x0C63B377B8A762EBULL, 0xA62F1A190FC67584ULL, 0x04A1917C2F425F43ULL
        }
    },
    {
        {
            0x87C20E23856B0FB6ULL, 0xD8684660E0D29CB9ULL, 0x072CED33EA321180ULL, 0xF51CE9A1EB540B63ULL, 
            0xFB2E36DE27EBCC43ULL, 0xA3D34902F25DF473ULL, 0x59BA1B8BF58C5F01ULL, 0x4EB9E90FAB286D56ULL, 
            0x3C37E5BEEAE96ECFULL, 0x1C62D4478E798C37ULL, 0x3AF00E2AC76D2DDAULL, 0xBAF7D8218954C8B8ULL, 
            0xDF0844AB1B4D4CEEULL, 0x9C8A39744203AF8DULL, 0x980AC48B40B690E8ULL, 0x46AD27D55F256247ULL, 
            0x56ADFB947F52CCF9ULL, 0x124797623C1DC515ULL, 0x426BD43BBB99A671ULL, 0x04425DE119B788E1ULL, 
            0x3F150466E0F8D84FULL, 0x79790A5C62EDC143ULL, 0x8368AF4F24143B45ULL, 0xEBDA5D4D1904EBB2ULL, 
            0x7B1EB43FC0075E6EULL, 0xAB7BEE188504F643ULL, 0x63A965B29EA2D274ULL, 0x4F85DA4AC064F5C3ULL, 
            0xCA3F16A114DF80E6ULL, 0xF4A1691D102CCB30ULL, 0xAEF220905246E442ULL, 0x54FF737B2050E84DULL
        },
        {
            0xCB5750D6362DA455ULL, 0xC9E8B6B57E412597ULL, 0xCA4D116311A2A951ULL, 0xAB2312DB52482635ULL, 
            0x630D0F19BEBACCEAULL, 0x6C43E3167DADDC64ULL, 0x969D2D4915C0424FULL, 0xE6AA67D9CC4912E6ULL, 
            0xABCF0E97C3FD0E62ULL, 0xF2A0349A69695B5CULL, 0x31CB862F7DC9542AULL, 0xCE9E4B3EE4E4D28EULL, 
            0x555EE7AC97C37C86ULL, 0x0A8E3280EE1AA2FAULL, 0x50089EDE97154D98ULL, 0xF09E5BBCD65002ACULL, 
            0x2EAF27739B2CCAE8ULL, 0x2694B4DF317BBA36ULL, 0x3459CCC27D656E26ULL, 0xCF4D816BFFDC87ACULL, 
            0x44E8DACEF94A56AEULL, 0x9D859DA2040D09F0ULL, 0xC1ACD1DDA7D9875EULL, 0x796A74310026674EULL, 
            0x87B62D9BA180ED1EULL, 0xF72A3851C74C5167ULL, 0x6891E00F75BF38D2ULL, 0xCD79687735F0F2D9ULL, 
            0xD626D366ADCD779CULL, 0x08E73BE800DAF41DULL, 0x011AF4906FEA113CULL, 0x994A7B246B798F65ULL
        },
        {
            0xD84FEA4E0195EEE7ULL, 0x6E2F8F466E173882ULL, 0x96368968F3719601ULL, 0xB318792603210340ULL, 
            0xB20E2000133BD96EULL, 0x84B0BED76768E6C6ULL, 0x65E4A89E5A55FAB4ULL, 0x7112DE216F12A421ULL, 
            0x1A5DB192DC1C5320ULL, 0xBEA0CD7F891736F2ULL, 0xA5833B19273B5C37ULL, 0x1FC7D86330E352A8ULL, 
            0x348FE58EF9F3226AULL, 0xCAA66AC603E9957AULL, 0xB2D519E9C7BAEF0AULL, 0x1894761D50DBEF09ULL, 
            0xF887533284BCF608ULL, 0xD00C7BC7552C4C43ULL, 0x85524E48A36DF48BULL, 0x07B0DE9BCBC2DD6EULL, 
            0x3588C53E1483A303ULL, 0xAA59AC306B052BAFULL, 0xEE5D960FD2ABB02CULL, 0xCF7D5F778388B44AULL, 
            0x13B16C64114AB7FAULL, 0x1EFB58EE9185A67FULL, 0xFEFE3DE969D1B4F2ULL, 0x28C41295F7EB9634ULL, 
            0xD517C9559BAC4A70ULL, 0x2231DB15E32A852BULL, 0x6BADFD43C51135F8ULL, 0x7721E2546FF714E5ULL
        },
        {
            0xA47F31CACCF07508ULL, 0xC62CC4D6977CA8B9ULL, 0xD41E2F46A3BB21A1ULL, 0xD0CAE6D1C9E0D0D1ULL, 
            0x8D51FEE9B7247838ULL, 0x2CCE7B3A5B4B59F0ULL, 0xF21D7685BA0DC992ULL, 0xB7F288084F9F08F4ULL, 
            0x93F10394D78E3905ULL, 0x8CCBB3688C9C9C59ULL, 0x776DC9B49A6EB692ULL, 0xFAECC28ABEFB2058ULL, 
            0x4F860E0FACDE9330ULL, 0x51A9C4828D7A1725ULL, 0xE84DFF6595CCB451ULL, 0xEE012EA13E26899CULL, 
            0xB68BF1FA5665DFF3ULL, 0x542AD6DF661A7165ULL, 0x7089D42C2C4ACA1CULL, 0xD69EE9C3E807ABB3ULL, 
            0xB6F96309210D5A7AULL, 0x14EF05D47B9A591CULL, 0x02F1ECBA72180045ULL, 0x800B47B186AADCC3ULL, 
            0x021D9D5AD95F1051ULL, 0x0E71AA6CE93EF4E9ULL, 0xA8AED32328313381ULL, 0x5F18713A5185C062ULL, 
            0x2CB42FD88152D3D5ULL, 0x771AEB53D08B42E6ULL, 0x271CC39546856402ULL, 0xD513B8C08CA8630CULL
        },
        {
            0x73093A63013EF3B1ULL, 0x793E5BC3E66F4CFDULL, 0x9716C49C0F1F9CE6ULL, 0xC92D29DCB72E7181ULL, 
            0x5D99078B8630398AULL, 0x66A8A7F053513D1EULL, 0xF9DD82DA953A97FAULL, 0xFC6568F7E3CB8039ULL, 
            0x9680640200D343ADULL, 0x5C4C4AA033AC1EDCULL, 0x321E6736953A27F0ULL, 0x3AC1498811DD5597ULL, 
            0x8A18F5B318D27696ULL, 0x2DCDF385156E0F99ULL, 0xFAF0501234E49C78ULL, 0x871EF0924B572C73ULL, 
            0x6B7007266DF78F23ULL, 0x1D30AC9F938A6B56ULL, 0x81CEE5077CB3E608ULL, 0x52550CEE9AFF2450ULL, 
            0xF059666B18AB1870ULL, 0xE2E8684C0B6E6D28ULL, 0xD219E8F879CDB9E5ULL, 0xDC9E943E2655FD0DULL, 
            0xE24F2190C274CE7BULL, 0x6D7BB9A0019A4935ULL, 0x722B38BC092EDCA8ULL, 0xFF40A084108B6205ULL, 
            0xFF0365BE91B370F8ULL, 0x10D66466AC590A5AULL, 0x171BA660B17ED98FULL, 0x51749146FAD65FEAULL
        },
        {
            0x085CBB8B2A4480E0ULL, 0xC49565494F60D734ULL, 0x9F19F450366566D7ULL, 0x00D3B5BCEF4D5445ULL, 
            0xDBEB729A497130F7ULL, 0x47C6D5B374EFD327ULL, 0x5ADFB4F33DCA57E8ULL, 0x251682C60F38C329ULL, 
            0x4572F55C8A7382CCULL, 0x35F7C425493445D0ULL, 0x231F4CBD29664442ULL, 0x5C076DAF5B9D390AULL, 
            0x495AE997D0DD0DDEULL, 0x48BFF1A17EEF6E7CULL, 0x946C155FDA8F5277ULL, 0xD883C829DBF58236ULL, 
            0x9EFC1200428395F7ULL, 0xB47F5352C52A01E8ULL, 0x85E903313BE33081ULL, 0x946EB2D7E1BB82AFULL, 
            0x8B27D34D1411238FULL, 0x045886253CDB9F6BULL, 0xB9472F700F1B8CF5ULL, 0x428B208A54AE30F4ULL, 
            0xB2FCC7EC5C90E588ULL, 0x237EC2C3009016D9ULL, 0x71191B2EE181F275ULL, 0x9E80D3A2A7DBCA6CULL, 
            0x0766E6BC8756BA37ULL, 0x2DC8991BE1D27C20ULL, 0x0368983E856D369AULL, 0xCD9BC719BEFD72A2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mirfak::kPhaseBConstants = {
    0xAA2DDB0F496858EDULL,
    0xD199D7F57C99D595ULL,
    0x17E263AD63DBBE9CULL,
    0xAA2DDB0F496858EDULL,
    0xD199D7F57C99D595ULL,
    0x17E263AD63DBBE9CULL,
    0x9601417C757F3024ULL,
    0x52D100559E976A16ULL,
    0x42,
    0xBE,
    0x82,
    0x31,
    0x25,
    0xD2,
    0xF2,
    0x76
};

const TwistDomainSaltSet TwistExpander_Mirfak::kPhaseCSalts = {
    {
        {
            0x2D5A397BA52EF9CAULL, 0x892449D8D03265E6ULL, 0x1A9C558C9E81A189ULL, 0x38AF241BE0C88359ULL, 
            0x492B8864A916BDF9ULL, 0x4EC6D1E127CD305DULL, 0x30E6AC67A3CA176BULL, 0xA4D9375E03A0F3D0ULL, 
            0x9BE3D787733A3FD4ULL, 0x4D78587AB6CD140CULL, 0x551E183050DEDCFBULL, 0x0310D35C46684A90ULL, 
            0x976DF139B6A2A4C3ULL, 0x4E3852D9F1764D6BULL, 0x3C06386441B0DC77ULL, 0x6D7A7B445DBA3D1DULL, 
            0x071BCD26875E4A54ULL, 0xEBF5E31D034F0450ULL, 0x7FCB8936BD353B14ULL, 0x604E42D22F69A697ULL, 
            0x0D64B58A910B15B2ULL, 0xD3D9753A6F18A5FDULL, 0x88DEFD77B5DBA2A8ULL, 0xE52625BFB0598F1DULL, 
            0xE5AEFDAFE483B54FULL, 0xD253BAE2D24F0A40ULL, 0x57DC3F1A0A5F3A9EULL, 0xA6A6252D0A21601DULL, 
            0x8AB7EF3F92579767ULL, 0xFDED77F310579AAEULL, 0xDF21FB13ABA73EA3ULL, 0x373E273323002350ULL
        },
        {
            0x4D0793BAB2975EF7ULL, 0xD8C7109932CA47FCULL, 0xA09C4EDA69B99373ULL, 0x2CA3AB458761147CULL, 
            0xABBE82D28BBD3662ULL, 0x45E617EFCAE9349AULL, 0x7A782815682A2F42ULL, 0x011D9A79E5439032ULL, 
            0xACD6EC390FA053FCULL, 0x6B59E86C809C4C63ULL, 0x827675E64B0E8059ULL, 0xA94651439191B85BULL, 
            0xD190B89B9056D13DULL, 0xE1ED8A059F440099ULL, 0x3CBDB0AD6645058AULL, 0xCDF1EE801EF77EB0ULL, 
            0x3A58EBABBAD4A946ULL, 0xB218EB90556506F3ULL, 0xEA13928CAEF30D39ULL, 0xD212C827EB39875FULL, 
            0x26BAD2925BEA72D6ULL, 0xDC7BD917B6AE1CE5ULL, 0xA2A899731AA95260ULL, 0xC77C3540CA167C3BULL, 
            0x125B7B617D6E0CC6ULL, 0xEBB3058AA2D9CB1DULL, 0xDA9AC7593F51D1ADULL, 0x23ECC4950227E89DULL, 
            0xEDA8310D54C60F12ULL, 0x463F1E6B4A75495FULL, 0xC0C3597DF20856B5ULL, 0xE2B5A72AFC309093ULL
        },
        {
            0x485ECFE190AA5646ULL, 0x21A94A3B867E098FULL, 0xFC54E3743CB60D3DULL, 0x3172CCB5E4190148ULL, 
            0x74FBF9D0647E6F5CULL, 0xA65CCB12D76B3A34ULL, 0x9CF774F470C1C787ULL, 0x0B492016AC12F336ULL, 
            0x28400838BDCB02AEULL, 0xF9915C0EFE29A219ULL, 0x306E13C1CDDA692FULL, 0x778C8E0A4422BF71ULL, 
            0x9B458E432C30DB82ULL, 0xA156CFB59ACA3A9EULL, 0xC748290F65B62BBAULL, 0xE95DE646A1DEA5AFULL, 
            0x5B9E270BE9767C28ULL, 0x960A06F5C99669FBULL, 0x09779A44D926FA5EULL, 0x3D93446ACB7B4CB1ULL, 
            0x940F2851FB8B87A7ULL, 0x57868B4274EFD881ULL, 0xEF62B41279388538ULL, 0x8CA2CA520CCA2FC7ULL, 
            0x189FB8A99D01526AULL, 0x8C1C773BFF9BEAEFULL, 0xD17A49FFF75E9D1EULL, 0x888CA088B825CA4EULL, 
            0x267562E91E4AF999ULL, 0xD06086D65B9CD29CULL, 0x64D31F844C4F75F0ULL, 0xE281B22722F152D1ULL
        },
        {
            0xD0E70427580073D6ULL, 0x86065EB823C71098ULL, 0x7BDBEBEA30C08955ULL, 0x3FC8BFB6D17462FAULL, 
            0x9ADAAD985B0A29CAULL, 0x0633887D66E2340DULL, 0x840158BBA4EE7B86ULL, 0xE7020F9D914457F3ULL, 
            0x75FFE7FA0830F19DULL, 0x2D674551B00EBDFFULL, 0x345FD8AAE3A263E2ULL, 0x48FDDE3EA797D96FULL, 
            0x2DE4992950DF1F50ULL, 0x30BD9BB8A31626A7ULL, 0x08AFA5E43F551869ULL, 0x578526B83504DCAFULL, 
            0x917C89985965E67BULL, 0xAA660CE3D601DC45ULL, 0xD0354C8A884B9630ULL, 0xED2EA2FD1EB4E459ULL, 
            0x47FF6FF85965D5FCULL, 0xC5F2C3E95B7E3A8BULL, 0xE866D6075E6B8300ULL, 0xAE15B35D8408282DULL, 
            0x2B50FDD3EAE4152FULL, 0x725A8194634E39AAULL, 0x998DF8B39B6E6EB3ULL, 0x54B61534127B8EBEULL, 
            0x2F6814C1C100F317ULL, 0xC552465D3DF4D05FULL, 0x5C5621D3839445D3ULL, 0xB9E04D264C91C4DDULL
        },
        {
            0x62F0E884166626F7ULL, 0xF6330E482A6E395BULL, 0x6A3B0CADE308F9D9ULL, 0xFB58E5B576AB122FULL, 
            0x12C160F1E2CD259DULL, 0x765FDB43B6AEDF0EULL, 0x89D05164FE7F4CFEULL, 0xBBDFEB007D394995ULL, 
            0x2476F8EF29174D19ULL, 0x9BD78923D8A563B2ULL, 0x6D3570EF917A568AULL, 0x0C5FAAFDEA41759EULL, 
            0x65623F9139880D55ULL, 0x726B8CC9090353DFULL, 0x7F10A765FC108EF9ULL, 0xA1E5A69D8F2B5473ULL, 
            0x53CBE5344060E1DBULL, 0x6C408843EDB28EA6ULL, 0x5CFC583B6CCFFA6AULL, 0x02C587C9BA1F3A63ULL, 
            0x3BBF82FE861D725BULL, 0x62AFDAFE79E9CE54ULL, 0x5C7F25178410AC38ULL, 0x6EA42520B25712E8ULL, 
            0xFC7A7828EA03AE48ULL, 0x4DDA3741C1E81D90ULL, 0x250495CCF6A35DA7ULL, 0x37B427F128798F04ULL, 
            0xE646C246CB0718A7ULL, 0x4980AB8A94DC3555ULL, 0x40742055ED8C2B11ULL, 0x623872518C149928ULL
        },
        {
            0xBEDE1FDC18797EF2ULL, 0x1AC84051A978550DULL, 0x2D28EBAB0C927C29ULL, 0xDA2D72E17294926CULL, 
            0x992AF67B1DBA4E8DULL, 0x4E38E817EBD14999ULL, 0x76FE43B325914455ULL, 0x97DA8391A0A7A78DULL, 
            0x10CD373515B49A8FULL, 0x0CFA94A2CFCDBCF3ULL, 0x14C89B80D7FA505EULL, 0x2E20C45F25C119CFULL, 
            0x70647AE346DFED28ULL, 0x23D69095256C5853ULL, 0x7FB01318BBD66DD2ULL, 0x875289FFE1635F67ULL, 
            0x082BF87930264146ULL, 0xD450DE42D293D004ULL, 0x033DD040993B5F74ULL, 0x4C66C41F657F979BULL, 
            0xD0C29368C0A4999BULL, 0x67B25CF6E270A511ULL, 0x625931540898DCAAULL, 0x0D74B1895E598481ULL, 
            0x33471AFE9610D54FULL, 0xC95974BF97CAA91DULL, 0x3D3E10DB76FAE970ULL, 0x0759C9C181297BE7ULL, 
            0x6C8F9E2E093E6E64ULL, 0x673C1F3C45350A19ULL, 0x8536B21B193E0321ULL, 0xEEEF6FDFC966670AULL
        }
    },
    {
        {
            0xB7949ADAC13DE39AULL, 0x0BBBF4154F095E1EULL, 0xB441F396FF876C71ULL, 0xF7D7446E4473D8C9ULL, 
            0xF6A010A75667E098ULL, 0x582D5F6B901B9E75ULL, 0x0FFA61911108379BULL, 0x7F7B67F3003949A8ULL, 
            0x9FBCF022059B60AEULL, 0x59B9E1D56E203F99ULL, 0x322C79A7CF756E56ULL, 0x3DCFE7C880B5208AULL, 
            0xD6122EF5D105609BULL, 0xAE759A138373A5D3ULL, 0xA2792D3D51849C85ULL, 0x69C6974751B5F4F1ULL, 
            0x41FC9BDFAF1C3E5CULL, 0xA49B57B7BCF710A6ULL, 0x7570A5049F4092FDULL, 0xBA852A1A35B0D2C4ULL, 
            0x3215B5B8EF804FACULL, 0x8A85BA8AB5866E63ULL, 0xD07D4A9223E0AF89ULL, 0x3271681C1A539099ULL, 
            0x1A114986556A4665ULL, 0xBF2D034431064FC9ULL, 0xFC9D05CF7F270019ULL, 0xA4B6001E01E75AD8ULL, 
            0x2F570C60F37F12E4ULL, 0x4B20BCD2032B3243ULL, 0x0997888C2BADDE3DULL, 0x661A4384538F6ABDULL
        },
        {
            0x56E48E0EB09F1164ULL, 0x8FBE908DF621BFBFULL, 0xB9BB1505CFB75873ULL, 0x33D1CD2A2D71D72AULL, 
            0x4A47F504584E3B1AULL, 0x6FC244478B4C4891ULL, 0x5981A6252A89970BULL, 0x4678CF9B3362407DULL, 
            0x81B59CF7CC18D65BULL, 0x0752FB8B1B501A25ULL, 0xE0DFE8E633059671ULL, 0x36BB3938A768CBF2ULL, 
            0x325A06997251A6FFULL, 0xF09C77F7B7B6AE17ULL, 0x68B125C2958054BAULL, 0x6E2B26C875F5F273ULL, 
            0x682A692A871C6E6AULL, 0xE2A00727EA72DA2DULL, 0xA8B06B47EBBBE970ULL, 0x8C7F7BF05EBD8523ULL, 
            0x8BFAC9BDCD54D937ULL, 0x47DF1E4D153FAA8FULL, 0x3C65FB25E718A111ULL, 0x0C6EA39EB8E25390ULL, 
            0x9597EDF6B5F504BDULL, 0xB8395C3DD8967A1FULL, 0x693AB986CAC72293ULL, 0x9BF8DC0F36DA92FFULL, 
            0xEF3A50DE4B4436B2ULL, 0x295461E307B5B33CULL, 0x01AD753B90132949ULL, 0xB714BE0EE907E145ULL
        },
        {
            0xF1BF763B3B3F7370ULL, 0x636BD41ABE459430ULL, 0x01E1888CC9C6AE53ULL, 0x73227B0B32294509ULL, 
            0x8BBC034E502B4DD9ULL, 0xB6DCA37085F3C54CULL, 0xB480D16797D7D180ULL, 0x18A881B5D6682AD0ULL, 
            0x300DACFE7279AF49ULL, 0xB86E0908C5E5EF6EULL, 0x7D32790C54D2B27BULL, 0x9B351CF9FBB95415ULL, 
            0xBF235B93910C1E8FULL, 0x9ADD8C6B445CF4CFULL, 0xB2B320B0F5C25189ULL, 0xA3F98C1593FFA204ULL, 
            0x18707FD1A007934AULL, 0xE1DDA7CB36EA1212ULL, 0x7074F94B638BE270ULL, 0x67FAE61B43370485ULL, 
            0xC0E51F1A809A62E4ULL, 0xE495E1530D14EA02ULL, 0x7E5D70FE8BC6918FULL, 0xAF07A59A8FC687C2ULL, 
            0x37C3A66EE1218F6BULL, 0x784FD90E26F855E0ULL, 0x2997BE1DC3C22051ULL, 0x2A1F175E9DDF8E0AULL, 
            0x51204319E78E8A95ULL, 0xDC8EB6EDF02B6874ULL, 0x4312E4ADB9D15464ULL, 0x9EE4878E8ADE7B71ULL
        },
        {
            0x50B77C9A5025B467ULL, 0xB37423EB580ADC59ULL, 0x2A9DD7182A9838E3ULL, 0xC0A7A2110A914962ULL, 
            0x114A7AD8833E51C8ULL, 0xB80A1EEE8A75A5EFULL, 0xA14DCF8E40519BB8ULL, 0x1088D6F6E962E579ULL, 
            0xE36ADD22924E916DULL, 0xBFE01813244E5EE0ULL, 0xA80B84890F91CAD0ULL, 0x77A043EFDAAA6F99ULL, 
            0xCF4ED9E9E94DF213ULL, 0x88C42BF745BD7229ULL, 0x29F56AEAD8B809DFULL, 0x838E838EFECE9425ULL, 
            0xCC7AB8CA24A9C3A9ULL, 0x07367BFC94247381ULL, 0x6A7ED7DFE0848144ULL, 0xAAB5ED8678DA4800ULL, 
            0x84C147D7547764D9ULL, 0x1A84409BFADA73F0ULL, 0xFCBCA146ED291B9BULL, 0x7F02CA51552821FBULL, 
            0x390F23EB7E2CA1BDULL, 0xE787F5736267F297ULL, 0x88155E7DE2BD523DULL, 0xB9D342C94474D019ULL, 
            0xD09D0CE0995DABF1ULL, 0xCD10FCEF0C2FC0FBULL, 0x51B3E209F1FFB12FULL, 0xC7A9130674DB328DULL
        },
        {
            0xE7F78E2E1CA2A9F1ULL, 0x11BA0DC90A683F4AULL, 0x423D7923038BEC0DULL, 0x87EEBC5745157965ULL, 
            0x049FFB7E85643EE8ULL, 0x0D76510559B41C69ULL, 0xC0B84AD791CE95A7ULL, 0xCD5A8F7C16FEA97BULL, 
            0x970E8BBA487FD015ULL, 0xA1E65707E1E08F97ULL, 0xC7DB31B0A41BD659ULL, 0x3D56199BCAD42C13ULL, 
            0x5D3141CD61A1B6C6ULL, 0x071823C1353EBD43ULL, 0x14CD5DE86059797CULL, 0x2628A79AFA3F83A4ULL, 
            0xA16C76F744D9CCD2ULL, 0x57CC72471D4272B7ULL, 0x6DA52272B5C4F58FULL, 0x9D43C1B3D10F9706ULL, 
            0xD9961CAFB78D7BB8ULL, 0x43CDAD673EC1B866ULL, 0x88512006FE57A951ULL, 0xF745378C32B1D8FBULL, 
            0xE193727902F4BCB6ULL, 0xD89801F19AD264AEULL, 0xA339D5284D5216F4ULL, 0x32292E7A5EB92A1CULL, 
            0x55F5B101268691B9ULL, 0x9C7B7018D52A7051ULL, 0x57ED2FFEED83F077ULL, 0x2B285ADD1448B3AFULL
        },
        {
            0xB6456AF553F42467ULL, 0x2E5BA9AE6FABC656ULL, 0x5502E948E39CD31CULL, 0x555CD96781351B77ULL, 
            0x1E60FACBF9DE9A90ULL, 0x019C84D9C32EC706ULL, 0xC53FF7069D32CDC2ULL, 0x2FF4769D19F5B0DCULL, 
            0x9755CE5C2228D4C5ULL, 0x3FE302C453B137A4ULL, 0x9A81D07F826856BDULL, 0x4C2B5D5C5F173ACCULL, 
            0x00B1D43767FBE6C4ULL, 0x40E449402285BD9FULL, 0xFA84949496A4811FULL, 0x21DEF419F89A6CEEULL, 
            0x282AA553DA99197AULL, 0x4023A8C7D7DEB483ULL, 0x2908E44E0C75EDABULL, 0x4577B755D9EFCBAFULL, 
            0x52E1C9DFFE36B33FULL, 0xCA905A8DEABA1E9CULL, 0xAB29C21979E99418ULL, 0x1ADD740A4F3656B2ULL, 
            0xDD2FAC6A8FC635C8ULL, 0x844595C01DF618A5ULL, 0x1EFE6FE650749575ULL, 0x9B8C119F5259A9B7ULL, 
            0x4610D32A00D946F6ULL, 0xE1857A17EB52865EULL, 0xC9F32B8F6656CAF8ULL, 0xAE2C6701FA0953F7ULL
        }
    },
    {
        {
            0xA336030D28009F8FULL, 0x3B43A9A3E6F98E1EULL, 0x7D72EA868CE49989ULL, 0x257F4E7FF650CEF8ULL, 
            0x0693394CD4F8ED8FULL, 0x2FBCE6746AF965F5ULL, 0x6390071FA8A9A429ULL, 0xCF862CD0B5DF0CF6ULL, 
            0x033351F12B698CA2ULL, 0xE254141FDFB82133ULL, 0x31550C5F25D9A8A0ULL, 0xCC407F60FE790B1AULL, 
            0xCA90E19E12CB10F2ULL, 0xD5E9EC4056A4AF42ULL, 0x4C1ECA408FDC7244ULL, 0x08F82347CC76307EULL, 
            0xE7E359645355DF92ULL, 0x27318AE3269EBC7EULL, 0x1164E9E909B1C3D9ULL, 0x2CC72DED0F192A77ULL, 
            0x49403599815AEFE2ULL, 0x92A91B4E602BDDB0ULL, 0xCD9710A48DAB5B5DULL, 0x4209468D957DAF59ULL, 
            0xDA3160A45CFD8601ULL, 0x7AE8D99BD2323BC4ULL, 0x8D702907E02A85AAULL, 0x01AA47D2C6867792ULL, 
            0x4FF7458E1B3E729DULL, 0x67437DF4BE84EEBDULL, 0x8073A4387C6E3386ULL, 0xD7E565307BA8322AULL
        },
        {
            0xAD51D542620B191BULL, 0xB4FCB4AD40A04923ULL, 0x07C8670C827916B3ULL, 0x341A72D2E2DAE060ULL, 
            0x42CFD998A2A8D0EFULL, 0x916689786AFF5956ULL, 0x91F839D3FF00F210ULL, 0xD02848B64925DF52ULL, 
            0xC620F5382029EFA6ULL, 0x8E9B4D08D59B1045ULL, 0x385BD9DF102B3CBDULL, 0x6D246B147EA75C65ULL, 
            0x181EE8DF0551FB79ULL, 0x312DB9743F8F5118ULL, 0xA5DC6D68E028CA1CULL, 0xA5BF8F36EA4D4704ULL, 
            0x03177DD74F23AC6CULL, 0xED23041E55D9D344ULL, 0x22FCD6CDB053A2C9ULL, 0xD99269CE0F666238ULL, 
            0x1A53B1FCC7CDF642ULL, 0xE9CC967EEA77526BULL, 0x4A713DD3450313DDULL, 0x8E2746D41655E4C7ULL, 
            0xE450BB312411B71DULL, 0x675935848B06A60AULL, 0x708CDE6C23609394ULL, 0x15038BA8347891B7ULL, 
            0x713F3B216C827BF4ULL, 0xA9AE321E6D82506DULL, 0xA313817F16723300ULL, 0x0D3B18B947ED4605ULL
        },
        {
            0x0D423CC99F23BA00ULL, 0x1DE2F7FC1EDA37B5ULL, 0x0E27EF62612D4886ULL, 0xE216DCDF365CA6B1ULL, 
            0xC4B486FA642789DAULL, 0x4DA5D61EED7AAB80ULL, 0xBEC011CE155BB377ULL, 0xB6F6C4BC9B373169ULL, 
            0x6D197D79F85C09AFULL, 0x27885CCAF291107FULL, 0xD5A71CED2859C0E5ULL, 0x718068946B85E723ULL, 
            0x939D71945542C0C3ULL, 0xDA9F9167DEA5CFF3ULL, 0xA99FCC40101A8F9BULL, 0xF0AA9F56735243B8ULL, 
            0x97348B3D91B7B0D9ULL, 0x160008D8176E2EF9ULL, 0x7BA26DFA0F14150BULL, 0xE74C0A5C10915AABULL, 
            0xBF945FF7FDB26C58ULL, 0xA7A178C6213F70A9ULL, 0x41B05517FC81ADC7ULL, 0xAE29B68E8A3F745FULL, 
            0x2E78BCC90924C9FFULL, 0x3373E08F048C0A5BULL, 0x324F77638BA3915DULL, 0x2C64DEB03BDEEF86ULL, 
            0xC1A5F9039CD03882ULL, 0x92A31CD130335067ULL, 0xC46978AD235CE35AULL, 0xDA80DB3F53339661ULL
        },
        {
            0xC9E1EF5F0EA99728ULL, 0x67D4DDE2331ABE73ULL, 0xC8F91322240E8941ULL, 0x6919714B6EF609CDULL, 
            0xB754B29230FC4D72ULL, 0x18A38E35EC40E643ULL, 0x1F7ADDB918D72795ULL, 0xAF7077BC6B6BEBFAULL, 
            0x25E4D0A478B4726BULL, 0x0FD4B8E9464EA27BULL, 0x992665294BA59153ULL, 0xAE60D7F56D296740ULL, 
            0xF8DFA1F37F3E1488ULL, 0xDAEACDAAF0012CF6ULL, 0xC1C1D9739F7E3CC0ULL, 0x511929650ECC6DB6ULL, 
            0xA3BB0C7263D25ECAULL, 0x249DD2A5D9039A1AULL, 0x5506B530BCB8CE23ULL, 0xFB512089B97FC739ULL, 
            0xBC477671FFA92F99ULL, 0xBC2D562F14DEAFC1ULL, 0x70427732278239F4ULL, 0x053572E83998F565ULL, 
            0x07BFFA067A711BE6ULL, 0x6BA9120E4D558932ULL, 0xC7E22E82F3989170ULL, 0x45377580751D43C2ULL, 
            0x6954F0D3EE2C8ED1ULL, 0x4826C49005F1F8CEULL, 0xA8FDFC0BC8950CD2ULL, 0x4A762F34925745C7ULL
        },
        {
            0x6AC6149139067296ULL, 0xF2AEF89BAB68B974ULL, 0x37D2DB4F440AB3B7ULL, 0x87BCC915CFEC079CULL, 
            0x970397BFB7F61E55ULL, 0x21C956DC360A4B2CULL, 0x6D09E1B154372726ULL, 0x91EB334D41379072ULL, 
            0x865B589D60427A41ULL, 0x60D4EF8BC341157CULL, 0x1097927A119D7AEEULL, 0x897C00A3960FB833ULL, 
            0xA1AE7282DEA573F0ULL, 0x8BAC0D4D1B020340ULL, 0x56C76E0BAA1D2B4BULL, 0xDFAEF54C46A206BAULL, 
            0x778EBEDCD94CC87EULL, 0x5AB81D5076FF9740ULL, 0x4D1820C835D97425ULL, 0x4825F85B33A0E8DDULL, 
            0x96470B114B9EF238ULL, 0x2DE4827BEE996B61ULL, 0x9C4C16F2E7719B4DULL, 0x121235FF889C7A0BULL, 
            0xBAE9CDFA67BBB4FEULL, 0x583B8BFB840B4560ULL, 0xF784E4D8B8C4E9F7ULL, 0xF82B3C4027567956ULL, 
            0xB793536468279A1AULL, 0x795CD31E1F980A40ULL, 0x313A5E0726399835ULL, 0xA74418380425D5A4ULL
        },
        {
            0x32F6D5A8F8E421A8ULL, 0x4F1E5361F5D31033ULL, 0x1EF5B1C4F3E0F410ULL, 0x0BFBE5C4011E5988ULL, 
            0x0209EF02C50FA5DBULL, 0xC7CC90C6E4EB7C16ULL, 0x5EB3D8646260188AULL, 0x6620F6D5C4549878ULL, 
            0x4B5D04844D25F254ULL, 0x51C23CFD46F33262ULL, 0xCF910A4ACFC8A6D8ULL, 0xEAB2503774F1F586ULL, 
            0x443D619AE451E761ULL, 0x039E5F9AE23348EDULL, 0x30AC712C7CB3DE11ULL, 0x33EBA15F1EB0996DULL, 
            0x627507E23BC4100BULL, 0xFD2C2AAFCB96B84DULL, 0x4414E1AE89F8AA55ULL, 0x52E3B2D24B3E86A8ULL, 
            0x7C01D8AFF042AE15ULL, 0xB05D4DBA82079610ULL, 0x709E547E66C3787FULL, 0x87883351CC588553ULL, 
            0x6FA5F16709490C29ULL, 0x1334DF878DFFEE5BULL, 0x7C7ACC6685B246FDULL, 0x26944A1AFF1DFADDULL, 
            0x5B52BB69A129AD33ULL, 0x091917EE1D8DFEDEULL, 0x7BE46A8070797403ULL, 0x9B8A5D84768B8BAAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mirfak::kPhaseCConstants = {
    0xB612F1E98B00024BULL,
    0x8D3283E35108AA1FULL,
    0xC0D6258DF7A346D3ULL,
    0xB612F1E98B00024BULL,
    0x8D3283E35108AA1FULL,
    0xC0D6258DF7A346D3ULL,
    0x82C6224889331D0BULL,
    0x891BB0C5FB170692ULL,
    0x8F,
    0xAB,
    0xAA,
    0xCE,
    0x73,
    0xC0,
    0x43,
    0x38
};

const TwistDomainSaltSet TwistExpander_Mirfak::kPhaseDSalts = {
    {
        {
            0x20E0D9AD54749E5FULL, 0xBA98EEFBFEA18CC3ULL, 0xD90643BB09BD7CC9ULL, 0x0B8023AFD274A0F6ULL, 
            0x96415E709CF6C99AULL, 0xA1504845FFEB8950ULL, 0x5E7354FDB89AB3C5ULL, 0xC119F8BA7E9EA2EFULL, 
            0xA1FD2DE2637C80B2ULL, 0x9761D018EF329AB3ULL, 0xC1B40AC1CB6D4C09ULL, 0xA367222C08354369ULL, 
            0x47A7A6EDC91B873FULL, 0xFEDE76346DD81F79ULL, 0x4CDEB9E6BFBA51C6ULL, 0x201CD45561739FF1ULL, 
            0x4137A174B60B4816ULL, 0x52058E25CED93C50ULL, 0x3C0CAE84B926A7B3ULL, 0x1EEC5104470CD1B3ULL, 
            0xC81830D956B2AFB3ULL, 0xCCBDD73412643F0BULL, 0xCB6050FE94CA129CULL, 0xCC32266F53081BB8ULL, 
            0x656FC80C9EAB8BCFULL, 0x29122DA3BC8161B2ULL, 0xEAF8A61669066377ULL, 0xEDEEB3ECAB5B19A9ULL, 
            0x95E809693302920DULL, 0x0A375ADD873AC5B1ULL, 0x19BC4CB93572E5D4ULL, 0x31815EE3C9C0F766ULL
        },
        {
            0xA02AFE1C8D5961F2ULL, 0x2AF73B0852285B84ULL, 0xC639FC96135E0BF9ULL, 0x312893821F68C0ECULL, 
            0xECC98703DF647166ULL, 0x7AA31F639FDE7B4DULL, 0xFC792755E4078ADFULL, 0x3005A9B33758C9CCULL, 
            0x61F8006C59300B43ULL, 0x203819669EFB95B9ULL, 0xAC23F71367499F3FULL, 0x2D1AAE4E78A855F2ULL, 
            0xC6C5DECEED343F0FULL, 0x8517EB5F07ADC068ULL, 0x5E42FC3AE9310602ULL, 0x3F76487EF2781132ULL, 
            0xDBD5851A0EF06611ULL, 0x2B46DEED6625C848ULL, 0x28182EE803CBFD7EULL, 0x197F312C09BCFF4EULL, 
            0x7C7AD1BD031CA02DULL, 0x217965E78DC18210ULL, 0x311E86E18EAD7C5BULL, 0xE531A6C93239F7FCULL, 
            0x849EDB94FFEEDB7AULL, 0x52008633580AD603ULL, 0xD641256143BC0803ULL, 0xBEEE432455BF2431ULL, 
            0xFCF4B7959C75E530ULL, 0x45D160191E9C8C29ULL, 0xA17BD7004D4889A0ULL, 0x0B469B58C3938F36ULL
        },
        {
            0x7BF24C979BBA17F8ULL, 0xFDE01E1CEF41E381ULL, 0xA1806E5D3E4C05BAULL, 0xBCFCB522B0E037CCULL, 
            0x1413BCBBDE214400ULL, 0x4BDBFC0598A0B0C9ULL, 0xCA93276E8EE1589FULL, 0xCBB1DC0E994A9292ULL, 
            0xA17B790F909F61D3ULL, 0x9D5E67828C7AD674ULL, 0x2A7D77E15829A0E2ULL, 0x6D76180C7B06830BULL, 
            0xD528D4BF5D68FA66ULL, 0x69055499C4C5E4D3ULL, 0x21A05EDAA2F82B6AULL, 0x711F4C4C907A64D3ULL, 
            0x469F33ED2A533C68ULL, 0xBECDBE2A17C45C74ULL, 0x653A1458C11BEEA2ULL, 0xEB5BA18A733DFF8DULL, 
            0x1F1C86A4B3477786ULL, 0xB6A428E60699F4E2ULL, 0x0CDF98B3733A5D92ULL, 0xFF87BE6CE858C65DULL, 
            0x57F956964B0D00C0ULL, 0x03820639CF64D975ULL, 0x8A118FA8B3643F94ULL, 0x331AE215EF3A3ACCULL, 
            0x5D8E34DE9881350CULL, 0xC24D137772DA6E23ULL, 0xC96CA45C9ED3B4FCULL, 0x334726D87BF393A4ULL
        },
        {
            0xCFECD0FC2CE90F1EULL, 0xEC0600C791F01405ULL, 0xC123F903AB0E5167ULL, 0xD2DA41593DB928A6ULL, 
            0x8603589661043216ULL, 0x5777D691F6FFCD79ULL, 0xEA4EE3DD09859B9CULL, 0x83756409BC0DC218ULL, 
            0x077D2E0F4C591D7AULL, 0x475CC58E48B99597ULL, 0x42B628CE522516E0ULL, 0xF7188898A27A97D8ULL, 
            0x216A970A9865EB9DULL, 0x41062D537E2CC359ULL, 0x9502101E992B574CULL, 0x98081803C360B376ULL, 
            0x143785D14D07246BULL, 0x19A45CDCFD4B1AF2ULL, 0xBAE1FD7F6A362774ULL, 0x69FBA2C29AAE8AE0ULL, 
            0x98037E484B4BF7B4ULL, 0xADE87B8B60E7C4CFULL, 0xC6EB855B92BF82C6ULL, 0x5D2B49C4346960B0ULL, 
            0xDA698BD29AE686A4ULL, 0x57E5EE75D7C9E7F1ULL, 0xB4255D928F599F89ULL, 0x765A91EC4BF36F55ULL, 
            0x29A9E238BB21C051ULL, 0xBD9843AF6049EFF3ULL, 0x6F194197A677CBB7ULL, 0x46B564A33B440CF5ULL
        },
        {
            0xD90B01741A5B0F17ULL, 0x2CDFA95ABB0D225CULL, 0xEE4B3942628BAABEULL, 0x96B483C5B4850870ULL, 
            0xF18FF42A7E3F25B4ULL, 0xA15819C0DE104BF0ULL, 0xD7618FD0B5317A5EULL, 0x37E5BA3125D1182AULL, 
            0x4D6AF78415ED4BFEULL, 0x1BA6257180FC32E7ULL, 0x6CC39BB85BAAB3B4ULL, 0xFB6CD0A921ECAE72ULL, 
            0xD03BEDF93F11F125ULL, 0x7320E342365DDC86ULL, 0x082258749C99DCCDULL, 0x6C5353A9AA04B54AULL, 
            0x5AD03ADB96DB33E1ULL, 0x47C12E7CA56CCBF5ULL, 0x8F104077A3C7DE62ULL, 0x0EE66DFD40D40B1FULL, 
            0x736BA9403855F6E9ULL, 0x3A2E8A7577C4604AULL, 0xD74736DC8301EDD0ULL, 0x539288C3F1C30E63ULL, 
            0xCE436FD2788618F0ULL, 0xED7D738C33EEB7F6ULL, 0x61F1778F92E553F0ULL, 0x1D4AADF7262326DAULL, 
            0x87C3519255B8DBA1ULL, 0x00424ACFAA68D4BEULL, 0xAB583B7C7D2C1C9EULL, 0x33246C6EFA7CC16DULL
        },
        {
            0x11C7D186364C4BA2ULL, 0xCC9BF08DD5704CEAULL, 0xE2D23039A03D6DA3ULL, 0x6B58BDF5701B065EULL, 
            0x753FEFE9CC2C3E6CULL, 0x10D3A29E92DCE6C7ULL, 0x615F53F752FCC0CBULL, 0x16324E86C29A5BE2ULL, 
            0xDCC3B5E9D8C243B9ULL, 0x3176023AF3A91AE9ULL, 0xE1F3CA5AD18EDF35ULL, 0x929DDD41D0EB5AF8ULL, 
            0x69287970BB9AE437ULL, 0x0705779253768B69ULL, 0x943AD9FC5A6AAAD1ULL, 0x687D8EA2746C9FFDULL, 
            0xEF44AD33890BA17FULL, 0x527A4EE470D492E1ULL, 0xE3AF5F224B2733EDULL, 0x131C5E23740058D2ULL, 
            0x93EEF7B8472E74D9ULL, 0x26989D4964B49C9BULL, 0xECEAD81C3732F049ULL, 0xA4BF8ECA581AB215ULL, 
            0x90963508EE0A387BULL, 0x6BA1BEF0741F101FULL, 0x24B949461DBBD870ULL, 0x75DB0352EF9E7EF4ULL, 
            0xD60EEE0C68662CBDULL, 0x9F576FFF617E26C2ULL, 0xC023BCBA38511E8BULL, 0xC6B65C978E2AFC1AULL
        }
    },
    {
        {
            0x8FE64BE81DEDEF9AULL, 0x8CE0C94AFB73F3FEULL, 0x88576DC9BFC206E7ULL, 0x5C0740AA886FF074ULL, 
            0x242E05D293547B25ULL, 0x3716010F28E16F63ULL, 0x63E00A50E10EAA3DULL, 0x395E0C1C6A73620AULL, 
            0x767C2523D6CFC544ULL, 0x8FB349971FCDE50FULL, 0xA99BD64D9E05537FULL, 0x749BC638E29E78C4ULL, 
            0xF553DA18F53E2712ULL, 0x09D6CF97E99B6574ULL, 0x14520EA6355D790BULL, 0x80EA8E189A9A558CULL, 
            0xF15E18993D2C0BD1ULL, 0xC78BE922220E7080ULL, 0x698C36302FF064C3ULL, 0xC8BC0FF8BAFF068EULL, 
            0x82A1A61EFC9F53DBULL, 0x5F26B0AC8D184185ULL, 0x616576CBD35914ECULL, 0x3CE305EDA08DA29EULL, 
            0x3C3B16B7D7DA8607ULL, 0x711BB89D00B47527ULL, 0x2DA93BD91D335C75ULL, 0x90209D0FFA8E7F84ULL, 
            0xFC6D677B5D62B175ULL, 0x76119206E0A320C2ULL, 0x1AB1E7BDA0FA663DULL, 0x12427DFA3BB79719ULL
        },
        {
            0x23BE6E3E927FAC41ULL, 0x12169EC34D6B524BULL, 0x3592A9555AE0C6DEULL, 0x032E9B18D55777AEULL, 
            0x08519FB8341E0B5CULL, 0xCB91D604874DE5D6ULL, 0xC557D39634394BE9ULL, 0x47744F7D08D9FBFCULL, 
            0xB0C6FBF59271E543ULL, 0x01CA21D7CD217888ULL, 0xBBA5EA37B3F04D97ULL, 0xEEBE20AE9237138EULL, 
            0x675A3E54C78495A0ULL, 0x063C6C976CA3CF52ULL, 0xC817A91E3265323CULL, 0x39E3F623AD9ADBD5ULL, 
            0x812B42F6E86D52B5ULL, 0x959A47574343FA20ULL, 0xA40709D3A8D047AAULL, 0xF0A16545760270C6ULL, 
            0x04616AE62812A7F3ULL, 0x613678380FF08AF0ULL, 0x63B516BE89D28E85ULL, 0x4E1DE9C952F6BD98ULL, 
            0xFE6BE8AE22E755E1ULL, 0xCFE280C947AC94F6ULL, 0xBC86D2D6441ED3E8ULL, 0xA21D72F5E8465327ULL, 
            0x69443F6DCD2C0966ULL, 0x315A5D22B7842E81ULL, 0x8323F98A3AD86B2DULL, 0x3970890CFFBF5859ULL
        },
        {
            0x80777B8A8E6161E2ULL, 0x0B8498CFFEA30262ULL, 0xF159F06E60E0A88BULL, 0x571E4E49345BBE92ULL, 
            0x5FB7720A78CDF4FDULL, 0xDC7A9EEE058269E1ULL, 0x25EE70234E06C8A7ULL, 0x2D1CA63A3A5D31F6ULL, 
            0x65C7DA28027FD2A1ULL, 0xDB7EC55218727A96ULL, 0x22A95EEF59517BFBULL, 0xAC34F1F5FF9BD8D7ULL, 
            0xAF8CF569341A65BBULL, 0x518185B62B7C6E7FULL, 0x93CF12844BD04258ULL, 0x856E6A0C947ACCC0ULL, 
            0x8B14C8CFBC858EB2ULL, 0x14CB5892EA736A95ULL, 0x92DD64B5CDA1DF16ULL, 0xCE34D81C4431C2D7ULL, 
            0x15899811BD1CE87EULL, 0x313816C43B00FB0DULL, 0xC4E603940B8EE705ULL, 0x3C3BA13AF3E7C68EULL, 
            0x751FDE2D8EFC9AC9ULL, 0xCDEC0056C0BA0EDEULL, 0x0D86EEAC1DD082B6ULL, 0x9B9C14BE54EFA9F0ULL, 
            0xB68A0E3766B3572BULL, 0xD1824D935F689CF9ULL, 0x840470DE26092D2BULL, 0x9CE0D9302B1CC654ULL
        },
        {
            0x485C0EB92E34FEC6ULL, 0x187A7DCE0C7C0D60ULL, 0x8D4DE0D0190A162DULL, 0xE1D5C50985D6B7FAULL, 
            0x36E9BBD6589F5E39ULL, 0x2F24B00A9A0EFEA8ULL, 0x3975236119845349ULL, 0x5B4B93D531547BD3ULL, 
            0xAD545F8BA8934A7CULL, 0x6069EA86EE54A206ULL, 0xC23D8290AC405EC3ULL, 0x35AA64B424DCB86DULL, 
            0xF77D3891D33690C7ULL, 0xA6A389B0341CAD27ULL, 0x55682D4B584311C2ULL, 0x7515BA645480D197ULL, 
            0xB77A674A3A36F280ULL, 0x41D413236134A2C2ULL, 0x1C8A4080C290C67AULL, 0x89EAFD9A928E29E2ULL, 
            0xE7BE2588128F0ACDULL, 0x7458473759701068ULL, 0xBD4B8CE331A727D7ULL, 0xD28328B9E03C505EULL, 
            0xADA77256A1E27C2DULL, 0xB62EA07839493465ULL, 0x8F8EC2798DF659E3ULL, 0x0967E475D91983FFULL, 
            0x1387FA4B94D13BDFULL, 0xD287ED1654424DB1ULL, 0x462697364301AE2BULL, 0x3439856A75A6AAE3ULL
        },
        {
            0x6FB635148E53A6C1ULL, 0x193D6BF94E061725ULL, 0x90F21897C3632643ULL, 0x27AC20F74EC1AB37ULL, 
            0xDD64BAB3DCD79419ULL, 0x1877D533F6EB452CULL, 0x487958FC6D661F2EULL, 0xF9EAE34490FD1F28ULL, 
            0x19578F32ADF2E4D2ULL, 0xEFB91D016D7B1182ULL, 0x225BEE9F1623163FULL, 0xECDE3A91B114EA1DULL, 
            0xDA44A6A77F88A2A8ULL, 0x68288E504FEEC731ULL, 0x26BA5B821A50F1B6ULL, 0x8EBF151EF06B7FF7ULL, 
            0xAC1693D7B000DEA0ULL, 0x19C319DE29C906DEULL, 0x6B6F7DB8F7006B14ULL, 0xC036540F6B94C2E9ULL, 
            0x23CB8E11ACCAD3E8ULL, 0x3F258786B999D56AULL, 0xFD547204ED8296C1ULL, 0xE2A1F36BC01DFA15ULL, 
            0xF1AFA680794EB3C1ULL, 0x7E8B00D021A70169ULL, 0x0110946FA2BBC09FULL, 0x91ED283D9C09D8B7ULL, 
            0x5F97C5E03786FA57ULL, 0x87DAD5E953178F25ULL, 0x1BBA81176CC16EACULL, 0xF2337016F263DA4EULL
        },
        {
            0x2BECBB6D23A8CE02ULL, 0x9B3A9090B9D5220CULL, 0x8538FA2BE904E465ULL, 0x25832783C283AD7AULL, 
            0xBDF308457E6B2BFCULL, 0x1DBFCC5E30912FFAULL, 0x4AF948806582DB77ULL, 0x2EC0DC995B639554ULL, 
            0x42EF3EBDBEFA4A5FULL, 0x25F27F9CC8AD3E44ULL, 0xC3E4A54CD1FFEE0CULL, 0x9FD4B4D08AD90EEFULL, 
            0x85960AAE17B4A436ULL, 0x2ADEE30739202A20ULL, 0xAB5423490551D21BULL, 0x830949DF3A8B49E9ULL, 
            0x8E2B4AD762535BA4ULL, 0x050E44D50B460136ULL, 0x79E31F296D11EBF8ULL, 0x30D579EDE602E061ULL, 
            0xA9438F5A025A2072ULL, 0x1248B356ADC95DF9ULL, 0x4C01F43A4B80BB7FULL, 0x8D8AD4333670D15CULL, 
            0xCE2918EEE140BCB9ULL, 0xEB22DFD73DF3FC7EULL, 0x92F72437D99CDE8EULL, 0x147E82844277F9ACULL, 
            0xD3402E2DC774F049ULL, 0x501564648F3ED5B7ULL, 0xCD54C546DD96D766ULL, 0xF0EBE9F26E580F7CULL
        }
    },
    {
        {
            0x6DB743B3E4767104ULL, 0x0C504394F134018CULL, 0xBC4759A78D62DE62ULL, 0x42C1986BD1C8BF09ULL, 
            0x300DD49CF42E0610ULL, 0x07FD0BE4A6B997B9ULL, 0x6B42628C47E7A175ULL, 0x9CB7840AB72A38D7ULL, 
            0x65AE7D59488BD343ULL, 0x5A9E86F1D73AD0B3ULL, 0x92EB78A882BAACC5ULL, 0xACC95B188FCE6981ULL, 
            0x0AC4B22355E20D44ULL, 0xE4A637B64B20DD62ULL, 0x64C2E6FF7381877FULL, 0xC17E47127F69790CULL, 
            0x1FC5A4714BFE7E22ULL, 0xA4CD81A8C8C4231DULL, 0xB6F2C0F7B737ABD3ULL, 0xFC9E49E4FC5B549BULL, 
            0x29C4F37C0B736ED0ULL, 0x3769F5950C50EA0FULL, 0x3929AFFB02E56F72ULL, 0x1042615245E237E8ULL, 
            0xAB7ED6F43F65C710ULL, 0xABEBE58C3FD89A88ULL, 0x88C3D655BEF72AD9ULL, 0x4CB4196673C2139DULL, 
            0x1FD3C18304DE9F2DULL, 0x94E4DD059108CC9CULL, 0x5CE9D0E1FD8078E0ULL, 0x1837A71D860B0D40ULL
        },
        {
            0xD2B07CC76CFC58C2ULL, 0x35C745D3CC358FCDULL, 0x2575CC1C35561238ULL, 0x378234BFCA766EFFULL, 
            0x4A38469566E8806CULL, 0x9AD3A410DFB9EFC9ULL, 0xAB59FA5FF539F0C2ULL, 0x43B0E55AA7F8234EULL, 
            0x0D8EC5A4C2AED5ACULL, 0xE1BD8C1445947BE9ULL, 0x5E7B79CC4ED7B80EULL, 0x67ED8D593D4D689FULL, 
            0xE04AE966D0A96F08ULL, 0xF73C66FB2C30116FULL, 0x73221C57663F4F0BULL, 0xFD63BE46D97D8352ULL, 
            0xFC6B36E931DDA2E2ULL, 0x9086561E13D5F613ULL, 0x04B9619026C62066ULL, 0x967669BA38E0088DULL, 
            0x12C68FB50BAE1493ULL, 0x43B5F6451E6C21C6ULL, 0x327C94AC3713FB3EULL, 0xCD7A3C71AB6F679EULL, 
            0x6D4F81D61CE33E25ULL, 0x85E76213E6B8BBC9ULL, 0x6753D84A78DE2D5EULL, 0xE2F49D4B13D67C54ULL, 
            0x823D86FB42F27911ULL, 0x7EE1D5FC5DB75D42ULL, 0xBA7FEE825B11CC77ULL, 0x565C374E75350EBCULL
        },
        {
            0x4F4393EDCA637AE6ULL, 0xBB5A5F01DEE483C9ULL, 0xCA7391B72EA89839ULL, 0x439861DA8E920597ULL, 
            0x5C6F5A3A8B94BD2BULL, 0x473913128D6BFE62ULL, 0x1D1A3919854F37FEULL, 0x76A6E1CE19E4780AULL, 
            0x5FDF9D94F88D6F3FULL, 0x8C33DF121A1576A3ULL, 0x3793D2C812EF5672ULL, 0xCC79C598BE04B592ULL, 
            0x9B5B4E42F522C8E3ULL, 0xD6E7FA7DB9603F27ULL, 0x5B3045E27F171DAAULL, 0x3A3961E6711F05C7ULL, 
            0xC3A382AFCC482A35ULL, 0xF07ECDC45F10FFA8ULL, 0xE7386A3385EB0CA6ULL, 0x1DB31F5C35A0100BULL, 
            0x1E68A20BBD48B413ULL, 0x2217A422E584CBBEULL, 0x3DFE84CAD438621DULL, 0x0949ACEF75C32533ULL, 
            0x2DA2516A8E1BCAA5ULL, 0xF4C4981BFDCCD0DDULL, 0xE7DB9293209C6783ULL, 0x715EEE691D144E68ULL, 
            0xDBE622E48D2778CCULL, 0x0156EE8ADDC86F5EULL, 0xAA0C2675FD5CE6E5ULL, 0xE44BB3C4D0FF1298ULL
        },
        {
            0x15E027EA45547310ULL, 0x196081647D8C2B48ULL, 0x4C86FD103F5560B1ULL, 0x5C93727DCA1A2D38ULL, 
            0xB42E42BD9F463302ULL, 0xFD5A728FF63BA94FULL, 0x640929022E031B1BULL, 0xEFCFDBDAB1676D47ULL, 
            0xCDD4D6D23419FBABULL, 0x9A1E2511123FAF60ULL, 0x3B626EE1AA269CA5ULL, 0x78DD30B7AEEA1C71ULL, 
            0x40317CA9624A7B86ULL, 0x1E16462DE30AEA15ULL, 0x702AD5CBB606D837ULL, 0xBFD34F83D9C03114ULL, 
            0x3424BF7186D1B624ULL, 0x4AEF99E30F014145ULL, 0x10557E8F16A375C0ULL, 0xEA307B60B696BF2FULL, 
            0x07BD8A34AE36E05DULL, 0xF0BF23D25888E364ULL, 0xAF154C6E924FE137ULL, 0x9F9A6CC7ED70C994ULL, 
            0xBF3ACE1F6B84AAA6ULL, 0xD473345DCE656B14ULL, 0xAE62CD8573DB28A6ULL, 0x906F5B15109AD28AULL, 
            0xEBB771918D8E5E47ULL, 0x1E08AF1ADEF8D114ULL, 0xB12F9782C261B2C1ULL, 0x1C207DB05878D513ULL
        },
        {
            0x444C788B8E2A5533ULL, 0x705B11DD5DEC24C9ULL, 0x0AAD219AF6AA327EULL, 0x434A7F77CE8E07B6ULL, 
            0x4D28BB3B44A2BF22ULL, 0xDA684BCE0EB03B14ULL, 0xE02C5A8A3A798FECULL, 0xE848F9F201856D25ULL, 
            0x530261677A1EEC12ULL, 0x9416523E033CB43AULL, 0xC95CEB73AF11A09FULL, 0xAE25A5C4851330DDULL, 
            0x62CFDDD92B05C401ULL, 0x73A59BD639D5C67CULL, 0x555299A711D8BDCFULL, 0x2F82307BEF63E985ULL, 
            0xE982C0A4A62773FFULL, 0x81ADED3908A1FC21ULL, 0x9903AF8C2ACD6475ULL, 0xAD7327E18F98AFCCULL, 
            0xD93367B1BC6E764CULL, 0xA7A8D1185521AB0BULL, 0x94F858E8BF2EC017ULL, 0xF57963A5EF3FC8EAULL, 
            0xE4784B2DAE29B7A7ULL, 0x34E7D37675FF2BBCULL, 0xC841E7F0E9B84441ULL, 0x69AE91F59131AB31ULL, 
            0x2DAEFC10563BE8FFULL, 0x1106E8AAAF3DA9B7ULL, 0xBEBCA32EB57A3A20ULL, 0xFD93C8F31A0E13E2ULL
        },
        {
            0x287951C784C259EEULL, 0xBA6CD412DAEFAAB4ULL, 0xB94993AD28BA1E4AULL, 0x16072DA661CB6D0CULL, 
            0x95E07BF3A084DB27ULL, 0x9314B14EAF7CC251ULL, 0xD90632656582B340ULL, 0x44834418692EA1F0ULL, 
            0xBAAF99A02DC005DDULL, 0xD2F7309417D581DFULL, 0xC9A0D34F8DC48658ULL, 0xE937269AD02571DCULL, 
            0xFCE12476AA5B4795ULL, 0x3445F89EC90E0B4AULL, 0xCB6B0C7ECD617FCFULL, 0xD8CAF9D8590E87C1ULL, 
            0xAEFD5840F3B2211BULL, 0x7FD7A05FBF44B7C5ULL, 0xCDA9E0AB8FDDD4F7ULL, 0x624B5227FA3A12B7ULL, 
            0x760881EE3F5601AEULL, 0xEB5231032CC8FF51ULL, 0xBFF8CBD6CECDEDD4ULL, 0xF45EC33BDE0AECDEULL, 
            0x684367FF1AE56EE6ULL, 0x9161B3F96FD1A92BULL, 0xF8A0F34EADB217D6ULL, 0x0626F0DFF8A278B3ULL, 
            0x58360DE501B1C037ULL, 0xC5F57C918E350432ULL, 0x7758ECDEFBB3AE07ULL, 0x3D07587201D562B3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mirfak::kPhaseDConstants = {
    0xEEB12D667EA2518DULL,
    0x5F5616D59928D1F1ULL,
    0x1FBA72FB24B8BF01ULL,
    0xEEB12D667EA2518DULL,
    0x5F5616D59928D1F1ULL,
    0x1FBA72FB24B8BF01ULL,
    0x7019D662C9A945E0ULL,
    0x2D068645FE8C873DULL,
    0xFB,
    0x67,
    0x47,
    0xF4,
    0xCD,
    0xEC,
    0xE3,
    0x7B
};

