#include "TwistExpander_Sirius.hpp"
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

TwistExpander_Sirius::TwistExpander_Sirius()
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

void TwistExpander_Sirius::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xEBF48900B9BEEBD7ULL; std::uint64_t aIngress = 0xBC1A76A278881A55ULL; std::uint64_t aCarry = 0xB2E32A6848B69799ULL;

    std::uint64_t aWandererA = 0xEBE7ECA67409C17FULL; std::uint64_t aWandererB = 0xB58179EC4127C769ULL; std::uint64_t aWandererC = 0x8AD3872597B7E24EULL; std::uint64_t aWandererD = 0xFEDE65A74E121AADULL;
    std::uint64_t aWandererE = 0x9B92A87392A13094ULL; std::uint64_t aWandererF = 0x90D4D971144844A6ULL; std::uint64_t aWandererG = 0xAA013A3C76018D49ULL; std::uint64_t aWandererH = 0xA948D038B326547EULL;
    std::uint64_t aWandererI = 0xAB0FE9D14DD079FAULL; std::uint64_t aWandererJ = 0xF44BC92343C65B05ULL; std::uint64_t aWandererK = 0xFEFCA46620C94099ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x8185DE58220F111BULL;
        aCarry = 0xDB3E321ABEED54EEULL;
        aWandererA = 0xBC83ADEAC7D959F0ULL;
        aWandererB = 0x973BE443F14F5639ULL;
        aWandererC = 0xFC022B2F2535688EULL;
        aWandererD = 0xE7BCD947BC566EC7ULL;
        aWandererE = 0xE73ABB0845671A8CULL;
        aWandererF = 0xBDE5F38F742AAE1AULL;
        aWandererG = 0xBCE29B571C1C4012ULL;
        aWandererH = 0xA8D3F1D71E249C55ULL;
        aWandererI = 0xD07070DA271916FCULL;
        aWandererJ = 0x81A1EA0382224641ULL;
        aWandererK = 0xC95B4DFEE9943EC7ULL;
    TwistExpander_Sirius_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Sirius_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Sirius_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Sirius_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Sirius::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA756608E406D9257ULL; std::uint64_t aIngress = 0x8FB7F3FBCBA28DEFULL; std::uint64_t aCarry = 0xA7F944E2A087AAF1ULL;

    std::uint64_t aWandererA = 0x98550B6C2DD1A21CULL; std::uint64_t aWandererB = 0xE44A2B814C0C7C34ULL; std::uint64_t aWandererC = 0x96735B532FDE35AEULL; std::uint64_t aWandererD = 0xD9165AE37107CA82ULL;
    std::uint64_t aWandererE = 0xDAB534CF853B36C2ULL; std::uint64_t aWandererF = 0xFBB8D76809FC6900ULL; std::uint64_t aWandererG = 0x9F5A04EECCDA30E3ULL; std::uint64_t aWandererH = 0x9061C102811EFF90ULL;
    std::uint64_t aWandererI = 0x96A4E21949681A33ULL; std::uint64_t aWandererJ = 0xADAB8B80CA8EC042ULL; std::uint64_t aWandererK = 0xB6750F8E18855867ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xEB7CA9A7DFD76020ULL;
        aCarry = 0xB2CB9BB6DF2C4215ULL;
        aWandererA = 0xD69895CC8C28CB9BULL;
        aWandererB = 0xC86D938D1106F8C0ULL;
        aWandererC = 0xE3095BBC5A200751ULL;
        aWandererD = 0xA437F4E61539A5F6ULL;
        aWandererE = 0x960C9D76BC5623C4ULL;
        aWandererF = 0xFA547A99DDA14F9CULL;
        aWandererG = 0x8FD122CE6229D6A6ULL;
        aWandererH = 0xAE0CD43EA30190E0ULL;
        aWandererI = 0xBC41387DD64D7607ULL;
        aWandererJ = 0xBE1B9B170CD772ECULL;
        aWandererK = 0x9406F2BD88F267D1ULL;
    TwistExpander_Sirius_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Sirius_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Sirius_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Sirius_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Sirius::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB7AB41DCF0D12574ULL;
    std::uint64_t aIngress = 0xB2EB3481021F14E3ULL;
    std::uint64_t aCarry = 0xCDC0342B16F90852ULL;

    std::uint64_t aWandererA = 0xB235D37CD29B97BEULL;
    std::uint64_t aWandererB = 0x86837AE54169C95DULL;
    std::uint64_t aWandererC = 0xD6027046E5B55164ULL;
    std::uint64_t aWandererD = 0x80D33161A454AFDEULL;
    std::uint64_t aWandererE = 0xBFFD58E023AA5C89ULL;
    std::uint64_t aWandererF = 0xEE82077116428FBCULL;
    std::uint64_t aWandererG = 0x820C91A5D3E65F2FULL;
    std::uint64_t aWandererH = 0x95279EFEE948A535ULL;
    std::uint64_t aWandererI = 0xBE3A45EDF1527240ULL;
    std::uint64_t aWandererJ = 0xF0801F821DDC5FECULL;
    std::uint64_t aWandererK = 0x99421350B481C132ULL;

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
    TwistExpander_Sirius_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Sirius_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Sirius_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Sirius_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Sirius_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Sirius_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Sirius_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Sirius_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Sirius_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Sirius_Arx::GROW_B(pWorkSpace,
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

// SmartSquash candidate 31 of 33
// Exploration cases: 100000000
// Nearest-family diversity: 911 / 1088 (83.73%)
// Total distance from earlier candidates: 28011
void TwistExpander_Sirius::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    static_assert((S_BLOCK / W_KEY) == 16, "SquashInvestToKeyBoxes expects 16 invest fragments.");
    static_assert(H_KEY == 8, "SquashInvestToKeyBoxes expects 8 key rows per box.");
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 11U), *aFragmentB = aIceLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 2U), *aFragmentD = aIceLaneD + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 39U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1369U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1145U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 600U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 12U), *aFragmentB = aIceLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 10U), *aFragmentD = aIceLaneD + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 662U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 867U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 560U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1655U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 0U), *aFragmentB = aIceLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 5U), *aFragmentD = aIceLaneD + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1003U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1550U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 554U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 544U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 14U), *aFragmentB = aIceLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 13U), *aFragmentD = aIceLaneD + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1111U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 278U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 699U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 474U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 15U), *aFragmentB = aIceLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 3U), *aFragmentD = aIceLaneD + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 187U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 240U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1049U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 632U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 6U), *aFragmentB = aIceLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 11U), *aFragmentD = aIceLaneD + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 464U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 751U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 663U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1738U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 13U), *aFragmentB = aIceLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 12U), *aFragmentD = aIceLaneD + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1799U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1195U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1899U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1364U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 1U), *aFragmentB = aIceLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 6U), *aFragmentD = aIceLaneD + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1722U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 369U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1702U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1737U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 3U), *aFragmentB = aIceLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 4U), *aFragmentD = aIceLaneD + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 726U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 143U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 579U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1685U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 2U), *aFragmentB = aIceLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 9U), *aFragmentD = aIceLaneD + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 323U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 472U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 605U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1293U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 5U), *aFragmentB = aIceLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 8U), *aFragmentD = aIceLaneD + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1217U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 514U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1474U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1022U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 4U), *aFragmentB = aIceLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 0U), *aFragmentD = aIceLaneD + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 566U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 2035U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 232U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 366U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 8U), *aFragmentB = aIceLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 15U), *aFragmentD = aIceLaneD + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 58U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 345U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1858U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 129U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 10U), *aFragmentB = aIceLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 14U), *aFragmentD = aIceLaneD + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 29U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1944U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1460U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1410U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 7U), *aFragmentB = aIceLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 7U), *aFragmentD = aIceLaneD + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 496U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 992U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1502U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1546U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 9U), *aFragmentB = aIceLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 1U), *aFragmentD = aIceLaneD + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 209U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1119U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 468U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1669U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Sirius::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB3170E5B511B3192ULL; std::uint64_t aIngress = 0x91613C0E9554B00CULL; std::uint64_t aCarry = 0xCB833D4F4DAEAA1BULL;

    std::uint64_t aWandererA = 0xE7142108F7FE2C58ULL; std::uint64_t aWandererB = 0xA4A56A8E30AE2C27ULL; std::uint64_t aWandererC = 0xDAFD1FF64EB93C25ULL; std::uint64_t aWandererD = 0xA33E0ED265EA2198ULL;
    std::uint64_t aWandererE = 0xD278BC800EA98D30ULL; std::uint64_t aWandererF = 0xDD40B4B8D33E8BBFULL; std::uint64_t aWandererG = 0xCB634C2F06E5360FULL; std::uint64_t aWandererH = 0xFBDFA88E1BC46318ULL;
    std::uint64_t aWandererI = 0xF2D86F020DD3E2FFULL; std::uint64_t aWandererJ = 0xEED437987E1E4DF9ULL; std::uint64_t aWandererK = 0xD5D6E67059F83954ULL;

    // [seed]
        aPrevious = 0x985158F8CB631190ULL;
        aCarry = 0xB1C3581F3462DFF1ULL;
        aWandererA = 0xEB76D1C852434478ULL;
        aWandererB = 0x8B8B38392823F49AULL;
        aWandererC = 0xC27BDB4FD80617E4ULL;
        aWandererD = 0xBC16B1AFC80472BAULL;
        aWandererE = 0x8732FF6A62BCBCF5ULL;
        aWandererF = 0x81825FF7FC89A6AAULL;
        aWandererG = 0xFB040DE92E5CE4D2ULL;
        aWandererH = 0xC626D0AB09B40330ULL;
        aWandererI = 0xDBC2A5B132171EB7ULL;
        aWandererJ = 0xD3AEC67724CBE4FBULL;
        aWandererK = 0xDFAC1984AB88A404ULL;
    TwistExpander_Sirius_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Sirius_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Sirius_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Sirius_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Sirius_Arx::Twist_E(pWorkSpace,
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
    TwistExpander_Sirius_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Sirius_Arx::GROW_B(pWorkSpace,
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

// GrowA candidate 31 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 16204; nearest pair: 487 / 674
void TwistExpander_Sirius::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3023U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 232U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1620U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4901U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3997U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7438U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7503U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7024U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1163U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1756U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5234U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4506U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5096U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8187U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4388U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1093U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1272U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1920U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 216U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 743U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 497U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1337U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1394U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1765U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 742U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 481U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1331U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1112U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 176U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 231U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 369U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 32U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1522U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1341U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 104U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
}

// GrowB candidate 31 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 16194; nearest pair: 486 / 674
void TwistExpander_Sirius::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 945U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3500U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6482U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4090U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2388U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7408U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3451U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2688U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3377U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3415U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1427U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6664U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 0U);
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
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7936U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2055U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3649U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3257U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1427U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1924U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1426U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 437U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1460U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 979U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1354U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 666U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1014U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1187U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1126U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1490U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1357U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1271U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1086U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1076U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1276U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 725U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1552U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1346U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
}

const TwistDomainSaltSet TwistExpander_Sirius::kPhaseASalts = {
    {
        {
            0xCDE0696BE6AA9E3BULL, 0x1F7106BD4A26F562ULL, 0xABFF02F04969B4FEULL, 0xA9DF38260EE7E733ULL, 
            0xD6A7E579E543DE67ULL, 0x60BB5871F47659B8ULL, 0xCDC10027AF90018DULL, 0x95AE63DCE4045008ULL, 
            0xB0434F842489821BULL, 0x483837E3EC65BA7CULL, 0xCFF8E5222541A535ULL, 0x44E30C4C8E2586BDULL, 
            0xC53207EB7E1859B3ULL, 0x7E331F0F1DFBDE6CULL, 0x914BAB75A99A5C40ULL, 0x3994875AEA6C7721ULL, 
            0x61E1D925CC74E6A0ULL, 0x7C77CB416894706AULL, 0x5AA3B4CE315839B7ULL, 0xD5177475B1416865ULL, 
            0x9843B87C7E3EA135ULL, 0x89C224647B19FA9FULL, 0x44DB0B991CAF05A3ULL, 0xE56A9C9F69548F10ULL, 
            0xE2F0702396FF949FULL, 0x92870E401694567DULL, 0x98E7E33D2450C133ULL, 0x32889E99F9C37B54ULL, 
            0x8B9E5388A30FB8A6ULL, 0x037524C877AF54B1ULL, 0xE4FC812472806ED5ULL, 0x719FD1AE90199946ULL
        },
        {
            0xFCA11A1F9FD7CA82ULL, 0xC6917B6FB0905B58ULL, 0x284AF05C10DFCEFCULL, 0x85C8686EBB9121FEULL, 
            0x3680BEB788DBE735ULL, 0x919775357DE0923AULL, 0x8B92F6E41E73ECDEULL, 0xE5B0E85A565372BCULL, 
            0x6B794D334435CCF3ULL, 0x2097A5DFFCEE4CB1ULL, 0xD4DBF66F97F29870ULL, 0x053FA877A9A7D54DULL, 
            0x7E46ACA2C8CA9D0DULL, 0x3AE2938B960126DAULL, 0x68B38F544CFD7ABBULL, 0x0B3233C4DDE36B98ULL, 
            0xB1EDFF22F7B5B833ULL, 0xE159BBD70AC5F411ULL, 0x9CDBDAE90D9FE3BFULL, 0x1D0972056415F4C9ULL, 
            0x2810148EEE79613FULL, 0xD858D147838CD72BULL, 0xAA67327C73F64813ULL, 0x81C9B9237019DFD5ULL, 
            0x9253A8BCF0C1F998ULL, 0x4CA5151333CAFDAFULL, 0x10CB5D5A62644428ULL, 0x1DF05936C750FDD0ULL, 
            0xBACD238317B42506ULL, 0x7027C8FD0E81C27FULL, 0x4CA9A8B033BC4488ULL, 0xD8A19ECAC1A14FB8ULL
        },
        {
            0xF8E8C4BBDB5F48DBULL, 0x9F540F062ABF3C3FULL, 0xE024052718EECA9DULL, 0x92A0624E13626C20ULL, 
            0xE2BDC5192B07A122ULL, 0x4ED11C427AA047CAULL, 0x1549719F03DF7CE3ULL, 0x172B0885E786EC24ULL, 
            0x916EAE81CCCC4D32ULL, 0xEC76A4B73E795A73ULL, 0xC486E01A9C024371ULL, 0x6FC575D121B7D31FULL, 
            0x5D3FEF77799E641FULL, 0x07FC9A08EF16648CULL, 0x9CE7A71794A9F4FEULL, 0x788168D9EF495E5BULL, 
            0xDDC6FF58514C7510ULL, 0x945159DE7D9894E6ULL, 0x765FB4476B5EB046ULL, 0x33969C822523E991ULL, 
            0x069CDFE55804A891ULL, 0x01C557F87C0B59E4ULL, 0x6421872838122A82ULL, 0x06E9352C569C41F4ULL, 
            0xE8B7CC7CB2EED964ULL, 0xED28D6E7D07B8B30ULL, 0x90D4FDDC498A5B22ULL, 0xAC02A8CB79B2E4E9ULL, 
            0x6D51356EBA402DEFULL, 0x3CA066A6F52E2328ULL, 0xB936E187CBB74FE1ULL, 0x6A9A4125833B27DAULL
        },
        {
            0x5DB33C25B648E57CULL, 0x5A77A03D641B12A9ULL, 0xD9C54003C435CE33ULL, 0xFAFA90FC132BC214ULL, 
            0x0B5D12F138B93F5AULL, 0xAE22A808115A49B0ULL, 0x7A27CBC5FA762E42ULL, 0x9D5A50996DA5253AULL, 
            0x1883788D8F66788EULL, 0x2B545FB82E351A79ULL, 0x46DB223DC6BDDA43ULL, 0x6890B21C6FA22272ULL, 
            0x192E3CC02122EAF9ULL, 0xE5B495A2404E99D8ULL, 0xA0CA019E374617BBULL, 0x13406F53059211B5ULL, 
            0x1D9BBE58F6299D47ULL, 0xEDA2179DD5C9B782ULL, 0xA314BA58159F2CFDULL, 0x786CCB3DBE80E3B4ULL, 
            0x9BE96C9EBEED7A43ULL, 0x16B6C13D30EB78B7ULL, 0x656055ED78323BBDULL, 0x42C9203831B4C0BAULL, 
            0x56F39ECFC8B70C99ULL, 0x6AD5208BDBA89CFBULL, 0xBB5E7EA2154FD2BCULL, 0x1B442FCAD7FB0A12ULL, 
            0x778480F05098B78AULL, 0x5ACC223CE5F8BB67ULL, 0x5A28B42DFAE32F71ULL, 0x52242EACEA88019CULL
        },
        {
            0x702445600FD3DFA9ULL, 0x4446F2A101E4F5F1ULL, 0xCDE1589163A2718AULL, 0x8B0369D813DF7E09ULL, 
            0x116E8698D09EBB39ULL, 0x2D2022AED1DB7F70ULL, 0x239668E07FD31154ULL, 0x0C0CDA97BD87713DULL, 
            0x986C611A0DE4DA90ULL, 0xE4D15CA17B72D1D6ULL, 0x045612344031DEADULL, 0xDBA384AA872429A1ULL, 
            0x96AED9E02DCA0710ULL, 0xCC14261C2AA6F577ULL, 0x3F40993EB56B7706ULL, 0x11901B036C3E3C22ULL, 
            0x85474986A521612CULL, 0xBC479C82B6E5E558ULL, 0xE105EAF4B91F7763ULL, 0x68C8C8BDF29D8C05ULL, 
            0x38F2ACE9040B6E7DULL, 0x263232047DCB3A33ULL, 0xC9684FB808099768ULL, 0xF94E6591A6912964ULL, 
            0x17D550349A6CDCDCULL, 0xBBBC9AF499027344ULL, 0xCDBB683EB8B99675ULL, 0x3231983A53C9A4E9ULL, 
            0x5C22FD3ABE78F120ULL, 0x697EAD341C9B91F3ULL, 0xD21BE0710EFFC12FULL, 0x127A710B9045DC4CULL
        },
        {
            0x81276BEBFF495D7DULL, 0x61E663A85D61639FULL, 0xA83A80DEFD013719ULL, 0x9FB3EBA7CFCDA136ULL, 
            0xEF8DBF08DB1A7800ULL, 0x678C31DBF554711BULL, 0x9534DCD0AD2058ECULL, 0x1A91DDE8C31E92F4ULL, 
            0x80DE30F955CD27B3ULL, 0x232EDB37DBE512E1ULL, 0x96F578CC278AAB7DULL, 0x81A8023F0D692CC2ULL, 
            0x1582C4CBE2A7BA85ULL, 0xE4B0A6B0CC284DC4ULL, 0xDE2A1D08A28126B9ULL, 0xA25A53AF605FED76ULL, 
            0x07652FAA3DA11709ULL, 0x3BA561714EBF532AULL, 0x78DF814F8D09B891ULL, 0x50594284E84F7417ULL, 
            0xA8BF5CC35AE4E2B2ULL, 0xE81E017E9B5FE5B1ULL, 0x8AB8963D114FAAF3ULL, 0x70537BA38873393EULL, 
            0xF11030780116FBE4ULL, 0xE5854EFADCA94D7DULL, 0xBB9A7A3919661CDFULL, 0xBA497AF2FC7D1B99ULL, 
            0xF92C1FF5DE5F2BD7ULL, 0x8113F8A68EDF1B56ULL, 0x47CE4453CE8BEDC6ULL, 0x224475C745831A65ULL
        }
    },
    {
        {
            0x5C050787AD18A653ULL, 0x42FEA6ECBD64C7DFULL, 0xD363583458627C87ULL, 0xB7D9D777CB73143FULL, 
            0xD000C01AACB586F4ULL, 0x8DD0FC6DB43F2802ULL, 0x0CD68C0771711A1AULL, 0x5950CE6A582212ABULL, 
            0x3CD451D76FC3D4F9ULL, 0x408E73BAFA28591DULL, 0x22ECC48D8D818042ULL, 0xF588DCEE6E6B1E6CULL, 
            0x17EA0CBB6CFD288DULL, 0x3225196FFA7C7A01ULL, 0x0262FEE5B73A5088ULL, 0xCA7D0D8B22B25BDFULL, 
            0xE1219D2C81BBFEAAULL, 0x267DA3B89AA9755DULL, 0x4F8C3934EAF92F77ULL, 0x6967EC3AB0B726A5ULL, 
            0x87E602C0779DBAC2ULL, 0x13BA021D77DAE00EULL, 0x33611BAB05727705ULL, 0x7B0F25AF842D5DA2ULL, 
            0xBFE6689AFBF30176ULL, 0xA72AB51482A6F42EULL, 0x0F75B32D856831A5ULL, 0xA4062137D2FCFF65ULL, 
            0xC2DF4D564B0C828FULL, 0x18CD508085511584ULL, 0x2EDFB25F405898F0ULL, 0x2E9DAD8D6A0317DEULL
        },
        {
            0x8C299732DA2607B0ULL, 0xF3E272F5E01BE3A0ULL, 0xB5EA04D95819A547ULL, 0x32DD1A8289FCB119ULL, 
            0x4B2FA72162049CE4ULL, 0x3BAF5F56738C3678ULL, 0xB8475264C2119082ULL, 0xF4B145B18FA22891ULL, 
            0x111AED8C6AE8B2BCULL, 0xAD9980CFCC2782A3ULL, 0xA7DABED7DF6DF8D5ULL, 0x454DC1B512196538ULL, 
            0x09A72F27A0B738DAULL, 0x67C2F764DA0F2107ULL, 0x441D03D2EAA8167EULL, 0x59EA04DE258FD15AULL, 
            0x25CE375174A6E2D0ULL, 0xA852D4B60A967F2CULL, 0x93B232F4537F658EULL, 0x9FFBC5AA0FC12A9AULL, 
            0x0C50D399A5ECB2E3ULL, 0xE3FBAA4AC8362547ULL, 0xFB5DC69F09DE8E30ULL, 0xE81868421B768B62ULL, 
            0x752303F5BB706BF7ULL, 0xC476A8476463CD5CULL, 0x4023D1E6D007574FULL, 0x496C619AE04C443AULL, 
            0xD5B89153C9CF141BULL, 0xAE1505A1B84DCDBFULL, 0xD6EFBD9E9FB942C4ULL, 0x2DA1BF24F6333D31ULL
        },
        {
            0x0FA231F6BADDE157ULL, 0x365120B0C28A0CB1ULL, 0x97B6A6BF6BB7FA83ULL, 0xB605FF03BBF149C3ULL, 
            0xF6E41F2AEDF7F87BULL, 0xFFAEBBD23FD3D3F6ULL, 0xEB2486ADD7685048ULL, 0x415148F5EE240746ULL, 
            0x73B933AAB0926238ULL, 0xDAA3C631A4292308ULL, 0x451D3230B3BD930DULL, 0x0900FE97185F57CFULL, 
            0xD25BF9C4554C2CC2ULL, 0x59D58736A8E9EE1BULL, 0x6C0257E29A786561ULL, 0x0682F30B178DDE5AULL, 
            0x9A7C334972AD7FE5ULL, 0xDAC95CA2CEB084E2ULL, 0xEBE9ECED8556A300ULL, 0x06D0A557D3B396FCULL, 
            0xAC922604BE9CEFECULL, 0xD60EA234A4801E16ULL, 0xF7BAB66C756D179DULL, 0x54FFFCB8FF8E14FAULL, 
            0x04B9E9B1C18583F8ULL, 0xA2E045258D2C3B2DULL, 0x7A8F0C984FF34B0CULL, 0x80751BC0EE739E22ULL, 
            0x997DFED37EA3DDC6ULL, 0xE183070ACB3AB0BEULL, 0xFE1DA773FA3BAC48ULL, 0x26428A034710DDBAULL
        },
        {
            0x98D4F0182DA6A1DAULL, 0xE081FF3605DAA570ULL, 0x2E6EC121F5EFDA8DULL, 0x3E0393C463213CDFULL, 
            0x4F2B835E8904B187ULL, 0x207AFC57010CDF4AULL, 0x4CFF09A2F39EAE67ULL, 0xCDDDCE948CD641AEULL, 
            0x0AE74D55B9316E5FULL, 0x5D5120459CAE927CULL, 0x25A27AC8581D125EULL, 0xA0EDED02AA61A2E9ULL, 
            0xD1D8F49547F49411ULL, 0x5942894CF01DEE27ULL, 0x936D04D7689158F2ULL, 0x4133FA5622406975ULL, 
            0xB0C4E3415D5A0D69ULL, 0xF5BB9D298747DDE6ULL, 0x5D37A58F63CA2306ULL, 0x9716F313BCBB6BC2ULL, 
            0x2393C629AE1D9A64ULL, 0xB506DE0E2E74F46CULL, 0xE37549DAFC53D158ULL, 0xF7291258E7C248BDULL, 
            0x283303BAF4035E4BULL, 0xB4D80EF3DC2142B0ULL, 0x7059217DFBAF0942ULL, 0x5FC20E35E0869132ULL, 
            0x14D1B1A3FE5ED2BCULL, 0x41B47A9A9AF9291BULL, 0x391F14A2FB74935CULL, 0xD682FB3B9E05E905ULL
        },
        {
            0x0E5E9704C4269ECDULL, 0x445713CB6F733546ULL, 0x0CB5323AB1E8E28CULL, 0x9AAD20FA711A54E6ULL, 
            0xCC78B08AF06772C2ULL, 0x040AB07F1F16CF5DULL, 0x2A6789CC65F27721ULL, 0xC34B24F580FB4FBEULL, 
            0xA42A13C406DA49BDULL, 0xA878DF09F5E72C2FULL, 0x46FE2A6BEB1F46E5ULL, 0x35E67EB069315C8BULL, 
            0x936AD76B1BD4779EULL, 0x6E981EE38A943D06ULL, 0xDF225C119853C87FULL, 0x5DAB26A2AF78FB99ULL, 
            0xC74230039E844660ULL, 0x125A1C096314035BULL, 0x466ECC54A99362BCULL, 0x9122CE27F251EE7CULL, 
            0xA8D53CB9FAF6FF56ULL, 0x702D6324AE1C90E4ULL, 0xAA14457DCCE0E62BULL, 0x6BFA3051C2B23571ULL, 
            0x231A2AEAC3AB3D21ULL, 0xB60E45BAA70C80D6ULL, 0xC59C5B7BD267A92BULL, 0x3A276B9881F80B25ULL, 
            0xE0EC302E83C73F34ULL, 0xEC07578B736B183EULL, 0x5022F6CA65ADFDD6ULL, 0x982D17BF5C2CAD8AULL
        },
        {
            0xAACD0D80A21EC56EULL, 0xC5E3760596D74E7EULL, 0xCFFAB9236893BFB0ULL, 0xE15ADB7D9EC5C5C5ULL, 
            0x124A11A433C127BCULL, 0x8699FA459A8A0980ULL, 0x2DD265F045F49DBFULL, 0x15ACB1C176D6AB4BULL, 
            0x94103A1D68410DBFULL, 0xB0F59430B2E38315ULL, 0x09F306210570B722ULL, 0xD2AF60E8E337BDD0ULL, 
            0xFCCD1532024DDFF7ULL, 0x9287498C00AAD698ULL, 0x4EBC75B65620D8D6ULL, 0x8FC52FD476F0C902ULL, 
            0x47D06B6F7648C102ULL, 0x41C456E6498140BDULL, 0xFA118125226A6145ULL, 0x2CAA137E7449E15DULL, 
            0x22D1124940EBEA1AULL, 0xF6968A6D37EA0439ULL, 0x9F3CD336039BBA66ULL, 0xC25035B2464BEC9DULL, 
            0xA472B8DC71D36314ULL, 0xF2268C953C20C8F0ULL, 0x266B8803D51D3758ULL, 0x31FEADF7423A7CBEULL, 
            0x98F3E6A0E71DCE76ULL, 0xC084A2F875A13BA5ULL, 0x1A916E28D7D95A35ULL, 0x4DBAB7599755334DULL
        }
    },
    {
        {
            0xCCFB5BF8B9CECBEBULL, 0x0B876D4FE44F4EE2ULL, 0x78BC575B5F1B02F8ULL, 0xBB583331DD0FAA71ULL, 
            0x9BE7B38AA470CD11ULL, 0xE009D37D8376A981ULL, 0xAC5197A46964AE66ULL, 0xA2F6649BF25132F9ULL, 
            0x7312C186AD384F23ULL, 0x00AD20D992C7FC83ULL, 0xA2E83CC5B3C35C02ULL, 0xD836F21BCB2DA0F5ULL, 
            0xE5A664F14F38F03BULL, 0x2E88D6DB4A5E928CULL, 0xAF9A758C04CD558AULL, 0x16152415D2A884B9ULL, 
            0xB8311EE754F4BDADULL, 0x289A04113F252C7BULL, 0x6CB57855B3D7621DULL, 0x4A6405BA2223BA19ULL, 
            0xCC788C639458C435ULL, 0x2B196EE6F478DE9AULL, 0x0D86F255739E34FDULL, 0x72A73F7F03AE2B70ULL, 
            0x6B5A3F3795E10B23ULL, 0xC3437EEF6F747063ULL, 0x08B63283F1FA60D4ULL, 0x876C13AFCA078C62ULL, 
            0x830EE6EF6314F9ACULL, 0xE06CB1E6BD2F40E0ULL, 0x28A1314958B67058ULL, 0xA5F5AB581C78FCC5ULL
        },
        {
            0xA69B981634590733ULL, 0x4C29E0BE15BE7606ULL, 0x7019FD367F596CF5ULL, 0x6E9B2FABFFBDA78BULL, 
            0xB5B502F7D65D7B5DULL, 0x826008927B9C330DULL, 0x07DB07B1EDC5E1D4ULL, 0x92A76C607B0F987DULL, 
            0x03F3B726C707F61FULL, 0xD57041E049A27BBFULL, 0x35DF15ED5D2015F4ULL, 0x4BE9FD70CBFC5B51ULL, 
            0xB42DC5BA8D0783CFULL, 0x9189CD0D10B9ED8DULL, 0x36884DA95E10199DULL, 0xD7BE752AFFF9B07FULL, 
            0x31F7615D7AEC11DAULL, 0xFCB2DA2B569767F4ULL, 0x71B0B14C07486CA9ULL, 0xCE4760B2EE968297ULL, 
            0xF6C88E3C3C7A7523ULL, 0xFEC8CC7FE2A8BF27ULL, 0xD1034EA2836D02B4ULL, 0x12BD097282E5D0F3ULL, 
            0xF15CA84E638B5DF3ULL, 0xF910AB24143546BCULL, 0x184517003657D6DFULL, 0x766C93E0296BFDE8ULL, 
            0xEBE4591CA7974C59ULL, 0x492DCEFAF2AD6D95ULL, 0xF0ACE988E78D2ABFULL, 0x830BC4E24C8CD272ULL
        },
        {
            0x65AA0C1D719343F1ULL, 0x98528975D7D8012EULL, 0x6EA17CC99476B39DULL, 0xCF0F2BD6DBD67B7CULL, 
            0xB3BF2F053E1B3F57ULL, 0x7706794B023892F8ULL, 0x276E94192CF151C9ULL, 0x6EA6DD930765D16CULL, 
            0x900C405DC2EDCB5CULL, 0x99FADE07BF76E575ULL, 0x83F74CD16B25DD72ULL, 0x2E53B126693A7468ULL, 
            0x16C50E99E2E64390ULL, 0x7E2EA0995C09ACEFULL, 0x30B5E055BF837F06ULL, 0xE7589EC4937D02E2ULL, 
            0x795687E8A4B0A2E4ULL, 0x5A506887C740BB48ULL, 0x318EC75C06AB39A2ULL, 0xBAEA2DBEE5F52A24ULL, 
            0x438DD3479FFB1634ULL, 0x7EF8BADDEA7F5501ULL, 0x0BFBEEBBCE368B30ULL, 0xBDF6927A4C59E48FULL, 
            0xF12C03A4D668DD45ULL, 0x4C81E15CEAE7916FULL, 0x11D1DFBB1DA794D1ULL, 0xC59755E62D2D786DULL, 
            0x633ADF9336BC2727ULL, 0xEB0328716FDF0034ULL, 0x798E8FA43A6ED172ULL, 0x64F9F9354EE76CE9ULL
        },
        {
            0xDF8010860290D7CAULL, 0x69E5556C22223D9FULL, 0xC8B1012DB26DBDBAULL, 0x0B43CC1FD211A623ULL, 
            0xC05515F54ABF1FC2ULL, 0x8AE4FB3CAFFDDCF8ULL, 0x2A205CF8D6A2BBFEULL, 0xF1806BC6D2D03428ULL, 
            0x5CDB30FD34AA0BD0ULL, 0xDF57989CC27BB4AEULL, 0x4E52208895F9FDA4ULL, 0x702FCB12286F4F6CULL, 
            0x5D0C9F32FC865D28ULL, 0xDBC2EB0B0BD979FCULL, 0x44F8AA6CC402D910ULL, 0xCEFAD91DFD6C0057ULL, 
            0xF278137F37E48A62ULL, 0x8CDACC263540CA5DULL, 0x3808EF6F0D277390ULL, 0x574F5211EFE8E8D1ULL, 
            0x0F81CF63BAFF3B0AULL, 0xE8E0E2A5B6456524ULL, 0x65666F6EADE59A06ULL, 0xF24229FAE0D9EBA2ULL, 
            0xD0C7F2A005485B50ULL, 0x7D7B1EDEA8670758ULL, 0x3FA9DFFE97D084AFULL, 0x0672B24FDA08F8EDULL, 
            0x9B7E96256955565BULL, 0x1CC50FFA43F379A6ULL, 0x8BA0B2446F68FEF7ULL, 0xCE7187CD9C777131ULL
        },
        {
            0x2DD7CC33ECE41853ULL, 0xB261D170171C7BD9ULL, 0xFA04834593AEDDEEULL, 0x591B8D145A726826ULL, 
            0xFEBD7859D84F2F9BULL, 0xE1F19B2400F729F8ULL, 0x1C021F751CB56D3DULL, 0xF095EAFDCBD40161ULL, 
            0x257FD565B5F6A8C4ULL, 0x920F2AD453F71156ULL, 0xC16F5DFC62F5859DULL, 0xAEA6F11017088217ULL, 
            0xB102AB5E759804DFULL, 0xF971B882E8747A99ULL, 0x2E13CA5967ED10DCULL, 0xEEF35D4A9799CE11ULL, 
            0x13F7DABB74DC7EA8ULL, 0x94E06363967D59BDULL, 0xC9E063352CA8828DULL, 0x8BE89BA1CFEEADBDULL, 
            0x6B3EAFC1B47855C1ULL, 0x208AE2C86AE854AEULL, 0x67655667AE148178ULL, 0x70F7A220DBD79EA9ULL, 
            0xD2FBEAE74A479EC0ULL, 0x9E8C4BC91480612DULL, 0x397813D977514D96ULL, 0xD8C7AE7AD04CDB66ULL, 
            0x725195B4E38303C5ULL, 0x3D967B994E1E09E8ULL, 0x03E187FC365AE056ULL, 0x508124AC93F0CD31ULL
        },
        {
            0x49B94E854DCE055AULL, 0x76EB93292A6B99DFULL, 0x10E06F1240FAAFAEULL, 0x373B3D194E938656ULL, 
            0x2C110AD4D23FB36CULL, 0x89FFFA5A239C41C4ULL, 0x9D413EE9FC56722CULL, 0x069BEEBDD39F5351ULL, 
            0xEEA9D6E41BF7DE18ULL, 0x1E896DBC4D1E38ABULL, 0x464336DE19C1C828ULL, 0x38508A427AA8845DULL, 
            0x7B5158D3D93CE6E7ULL, 0xDF4FF342D8D7FC27ULL, 0x77E5F358FA30DCA1ULL, 0xF643EB6038700F7FULL, 
            0xDEA4252358860958ULL, 0x31F1D442D90FDD7CULL, 0xD1FF064139008289ULL, 0x873979D691728B30ULL, 
            0x84257A58FF3B08E0ULL, 0xB0FFA143001A82ADULL, 0x46F924FC89557AB9ULL, 0x62853319A6CC7FA9ULL, 
            0x05B0FA3529E57BC3ULL, 0xD4508E59CC76F12AULL, 0xDB0BE067FBF737A8ULL, 0x27786F4EDC5EE232ULL, 
            0x81A5897F2D03899AULL, 0x691FB66CF09BC892ULL, 0xAFA2189E1D17D44CULL, 0x5854FA14A642E4CDULL
        }
    }
};

const TwistDomainConstants TwistExpander_Sirius::kPhaseAConstants = {
    0xA73C9B2F85D5421BULL,
    0x6DB1F8C4AC304F1BULL,
    0x40E5D9A26CFD4360ULL,
    0xA73C9B2F85D5421BULL,
    0x6DB1F8C4AC304F1BULL,
    0x40E5D9A26CFD4360ULL,
    0xAD8CA36391F342C7ULL,
    0x887CB6083109E617ULL,
    0x50,
    0x8E,
    0x4F,
    0x5D,
    0x06,
    0x30,
    0x78,
    0x57
};

const TwistDomainSaltSet TwistExpander_Sirius::kPhaseBSalts = {
    {
        {
            0xF9AB79D739ED9605ULL, 0x58F94B137A3CC5F1ULL, 0x2F51FFC98862BA43ULL, 0x65107BF57E6BBDBCULL, 
            0xF6A0647C789DC35BULL, 0xCA66C5C331B14A7DULL, 0x635457862A329EA3ULL, 0x446CBF6468BEC0E5ULL, 
            0x9E8F746AC6A6E585ULL, 0x9EDF1ED7E028F7A2ULL, 0xBFE2A7A811A380D8ULL, 0xB461BD6D0AC755C2ULL, 
            0xB78C5E9DFE468CA7ULL, 0x34B078E1088A5B0FULL, 0xF627ECE4CA4B6706ULL, 0x90D30CA2E1043C15ULL, 
            0xE7BF77BAFEA38333ULL, 0x4572DF404904DA60ULL, 0x26964EDA5E4C3A51ULL, 0xDA2E55527B769101ULL, 
            0x44777C5B788EEA09ULL, 0x061DD15BD5B456E4ULL, 0x8E29CE9815192CD3ULL, 0x6E0AEB8B487833DBULL, 
            0x2A1937F2AE053A8AULL, 0x7753A8B8DD415278ULL, 0x44DA97778325D4D3ULL, 0x1C92D3E4A186051CULL, 
            0x9A5B629FF48583A5ULL, 0x307D5E780072DECBULL, 0xBC93CA5D934CD5CDULL, 0xAE55563139B9D2DBULL
        },
        {
            0x0C4A39713646B3A4ULL, 0x2482B50822D6C8DAULL, 0x52A7C856303A5B32ULL, 0x9FD0439E2815679EULL, 
            0x32966F0D0605A0DCULL, 0xD8EB3FEE4701C8AAULL, 0xA3707571D50D1D27ULL, 0x3B469706977341A2ULL, 
            0x9A3384AFF1F76E27ULL, 0x0A578567B2B3B266ULL, 0x1A073FEC2B36265AULL, 0x13F50CB9D0D2B253ULL, 
            0xE173A12C2EE735F0ULL, 0x67E734B80ABCBC9DULL, 0xA11D1CBE370ED038ULL, 0x0026B92E63FD20C5ULL, 
            0x62FF710A2569C838ULL, 0x38201D27DDD6D5CFULL, 0x6EAC28B88BF2339AULL, 0x972D63F333C00E3EULL, 
            0x3749863D70D1E04CULL, 0x6C60BAA7E342449FULL, 0x99D797DE422210FFULL, 0x7EB6C6DC65989813ULL, 
            0xD89E8B93BC2A5F5CULL, 0x3550D024B971FF7DULL, 0x617600D5BEBB0189ULL, 0x9E823C5940464F8EULL, 
            0x323A6B8CA9FA7875ULL, 0xF6BDFACE659DE8EBULL, 0x6136293CAB28D79DULL, 0x1411282E678E1C41ULL
        },
        {
            0xCA7C496572B893E9ULL, 0x0DB76134758BD297ULL, 0x53BE511BF1D009E2ULL, 0x3C3A670B78673403ULL, 
            0x0607A68A1D37DD3EULL, 0x606B7928C6109363ULL, 0x2E8CAC8837F47EEEULL, 0xDF68E61AA8DE0CA8ULL, 
            0xF83925E29FDEB813ULL, 0x365A02274CB21FCAULL, 0xD74CE2CA239C9A28ULL, 0xEA56D14AFF34EACBULL, 
            0x7E57FFEED2C619B2ULL, 0x3DAB7253C409064DULL, 0x009E06D663199BA5ULL, 0xBE85953FE3B49106ULL, 
            0x1EF97414E1CF0306ULL, 0x55FE29645C63F748ULL, 0x7D514D26D8699E29ULL, 0xC244F9540DD5B365ULL, 
            0x93402772936AEDB5ULL, 0x9E4D7DD832673B03ULL, 0x6709C2979246E51DULL, 0xBE11B4F5637C9F7DULL, 
            0x6FC7F661FD580B6AULL, 0x57C22AD43CE5AD19ULL, 0x89927787E963011FULL, 0xBDFE325896790977ULL, 
            0x37B745D27A375B83ULL, 0x7695C91D99F57C73ULL, 0x4B3649F732D919ECULL, 0x3B29E3EB21D3749EULL
        },
        {
            0x10E5B0B748B6E1DCULL, 0x7337B698A5E1E914ULL, 0x7749E95B8EB994D8ULL, 0x74E7B9BBCA818CC9ULL, 
            0xDA2BCFDAA613F212ULL, 0x2FAE640A76B04C56ULL, 0x9D53B35E5514DDFAULL, 0xB55005297391C2CFULL, 
            0x47EFA7C3B2E5C672ULL, 0x0913CEDF62609E3DULL, 0x0D957DC7526ECCAEULL, 0x7CDBF558127583F6ULL, 
            0x7C1EEF333D9CD5FFULL, 0x2CA0C438890F35BDULL, 0x5817B31193B2D86DULL, 0x8457D567C774B325ULL, 
            0xAD156EA89B40822DULL, 0x1C36E5018FF21B1FULL, 0xFEC8F44674D0FBA1ULL, 0x464F623EE5A49C5CULL, 
            0x503B3C5C72A52161ULL, 0xE6BED7ADC2F61447ULL, 0xF6BA7FF5CF8B4257ULL, 0x1C09FDAA9FD256A7ULL, 
            0x7DE2F410CDAB11D7ULL, 0x02C9B88CDBBF56D7ULL, 0x1FE16455A0805BB1ULL, 0xE4BFDBF59EAFC131ULL, 
            0x9F8FA7728B23E98BULL, 0x4A08BE94AEB033D2ULL, 0x436FBDF4D30F5F06ULL, 0x898902EBDCC88D5FULL
        },
        {
            0x58508B7A726DED87ULL, 0x61996393624B2A55ULL, 0x5781C099F1C3A29CULL, 0x9A29A6888BE71476ULL, 
            0x2737FDA60307345FULL, 0x6A26D3514900E5A8ULL, 0xFE443E78EF73AD27ULL, 0xEF53285530BADEDCULL, 
            0xE9322752CF9C9348ULL, 0xF58FB28A46759CD6ULL, 0xB153403F5418AEFEULL, 0xBDBD08565FC1B6C6ULL, 
            0xC5AFC60AC83DB756ULL, 0x037A72ACB84CE68DULL, 0xFBFE419EB7AC8BEEULL, 0x361FC37F0C18B8F1ULL, 
            0x404B4CB2A23E053DULL, 0xAE2EF57452EC0C45ULL, 0xBADE51339907ED60ULL, 0xD49CC0B985BC952AULL, 
            0xA185766F4233D114ULL, 0x808A1875C2C29C67ULL, 0xB98240E4DFB34626ULL, 0xF6DA552C42014516ULL, 
            0x9266476849B11463ULL, 0x3D3956A6261D300CULL, 0xFC68EB855D3484FBULL, 0xDBECB707F043DDB7ULL, 
            0x5C7B4A850C02BB25ULL, 0x3BAB6DA5CB4F383EULL, 0xF4C6C2E3CAB46E5AULL, 0x66A160316FAF2DBBULL
        },
        {
            0x3982B46F1D8892E2ULL, 0x9E57D24677A8F046ULL, 0x256C375B3DF16850ULL, 0xBDB1A0883949843AULL, 
            0xEEB6D9B6B35E84C6ULL, 0x97EB3E3340B19237ULL, 0x0166EA5B2B307294ULL, 0xA34B2907BDB26AD3ULL, 
            0x252FC512DB8E5822ULL, 0xBA7F92AEBD689D26ULL, 0x78B991E18CD3A70BULL, 0x2080795AE15B6B96ULL, 
            0x66F08F2EBCE00E3FULL, 0x43E495574E01BEB8ULL, 0x09C37C683BACAA78ULL, 0x58E41068AC7CF64FULL, 
            0xF46AF411808D02D4ULL, 0xE63380C506CCB03DULL, 0x9253B91FD63FBDF8ULL, 0x21B6238D886A316CULL, 
            0xA7BF2BF65FFE3673ULL, 0xA017F5C38EDE79C2ULL, 0xAB069F17F9B4D2FBULL, 0xE3616BD924D2CB60ULL, 
            0xDBC923F2BDFB6C74ULL, 0x80B8D48BAAAB7DB1ULL, 0x1A893032548E830BULL, 0x502F659905B9755DULL, 
            0x2FACD33DA721293DULL, 0xE875201292D7F164ULL, 0xF2C1BDF0F93C568AULL, 0xFF8AB27A5DFA73A5ULL
        }
    },
    {
        {
            0x12112C648879F587ULL, 0xFCB8BAD575B5905BULL, 0x1648ABA21965706BULL, 0x5DCA65A411AD35C7ULL, 
            0x6EA719726B600859ULL, 0xB49CBE3D2458728AULL, 0x46FBF3CFB148BAA6ULL, 0x8E27058DBCBE4427ULL, 
            0xBD4B95E3163AD83DULL, 0x7D85E1A871EB2C30ULL, 0xD2273C25FBE7AA0AULL, 0x24F5337705AE0F1DULL, 
            0x204183682E4E0D04ULL, 0x4DF296080001E3E6ULL, 0x95F3600A0C83B1B7ULL, 0x9CC2E4993E4E0491ULL, 
            0x2C311AA5166068B0ULL, 0xECB3027F939EDE53ULL, 0xBC0EF8FD6D0406D3ULL, 0xE4A63A7B99A7C567ULL, 
            0x22365E920438B9C7ULL, 0xA6E419549707C2DFULL, 0xC679CA90F8FA27AEULL, 0xF43B4CFD1F5AD142ULL, 
            0xDD6A3A553ECDACBBULL, 0x76269395C023D202ULL, 0x7CCA9C117248E6CAULL, 0xF83DC43630B4FFA3ULL, 
            0x4E8D9C2C226AA94CULL, 0x32B3E81EA5955C44ULL, 0x8E7E4674DC8F1485ULL, 0x1909FFD58A898EBAULL
        },
        {
            0xB802620BB3826241ULL, 0x04F0F19003CD48A2ULL, 0x05849B8592CCF861ULL, 0xBCBD9B8C503D31DEULL, 
            0xA47ADE7DE7DB8FADULL, 0x085DC4754DA6C84CULL, 0x50977AB28A22F76DULL, 0x8CCEF9091E24889CULL, 
            0xC7C62479F5B260D7ULL, 0x68C0AC9B5EE0B6EAULL, 0x267910848F6A597CULL, 0x90AE4695307CF122ULL, 
            0xDFDCE1B6DFB3AB48ULL, 0x0CB5E6F9A10CC279ULL, 0x2AC121AB9EBB2C40ULL, 0xE4F46E2548802D7AULL, 
            0xD02EDB742BF77BAAULL, 0x82CABDD8F74138F5ULL, 0x28E7C8C3425B4C49ULL, 0xEC92119DEEE0D0EEULL, 
            0xB93ECDD5624E87D9ULL, 0xD058FE008B8C0305ULL, 0x37789D1F53F06989ULL, 0x2615C813FD0F594FULL, 
            0xFD8E2235C77551BBULL, 0x661FB4FEEB6A2401ULL, 0x34B6B98D8638D869ULL, 0x7D96B008F3BA319BULL, 
            0x70CA4917085A1FD6ULL, 0xAD1DBD7A7C5CC437ULL, 0xA66A43C4DAB7A8D0ULL, 0x8CDE5D9482AE83E7ULL
        },
        {
            0x1CA656B7111693ACULL, 0x957530203957862DULL, 0xD43F8A697A19D035ULL, 0x2394A50B975A641CULL, 
            0x48038A55207EFAF4ULL, 0xC8F0CF913888D4AFULL, 0x0AAF708AD02D948EULL, 0x5DCC353458130FA1ULL, 
            0x37DB99288D9417B3ULL, 0x8C7545C64F670482ULL, 0x4C991EA0CB0CF72AULL, 0x53A693DE3AFEB4DDULL, 
            0x72A003E236EDAA16ULL, 0xA666BC78CE31699BULL, 0xDCB647375740AA51ULL, 0xABE712193F11F46CULL, 
            0x93C1CC9A95E80188ULL, 0xFCC14FF6E43F2756ULL, 0xA0222E04512E50C7ULL, 0x37E08B740B7E945CULL, 
            0x32BBB32622864B74ULL, 0x9EE946AAC9CFD554ULL, 0x9CD10C2AA7FA2DE2ULL, 0x48B61AF005A95EEEULL, 
            0x5F665F0F386331D0ULL, 0x89DDCCD7C79E5735ULL, 0x88F7104F1EAF20CBULL, 0x690A039421B5128AULL, 
            0x7D564500B43835AFULL, 0x3CA9FFE438C5DBB9ULL, 0x6EBE788F267C5CF7ULL, 0x41771357047F2297ULL
        },
        {
            0x426FBD3922396EEEULL, 0xA9420FE7D7C28804ULL, 0x0883264E682A87CFULL, 0x0B5AD693B9B42852ULL, 
            0x2648638BBEC0C269ULL, 0x50504667E5A0C561ULL, 0x04F1E95BD3CD975BULL, 0xFCF03080F953E96EULL, 
            0x0A4AB3097B170A63ULL, 0x209D0B0CCE5E8AA3ULL, 0x9921B68D14BDE89BULL, 0x5505A0D2822F22AFULL, 
            0xC939049EBD50FA3CULL, 0x7EBD4861ACC707C6ULL, 0x13D127E4D72A2BC2ULL, 0xB73D29665CC28AC2ULL, 
            0x2E9D9C74F1ECAB8EULL, 0x22F2FA7E2B03B7CEULL, 0xBBE99464F670F1A0ULL, 0x68BEDE065893CB4DULL, 
            0x7BD58D6762FE21C9ULL, 0xCBE89756F8B43F62ULL, 0x2E8FE3BC7F23A2C0ULL, 0x997A30F992C4DA03ULL, 
            0xECA87D3067D9B333ULL, 0xECDADD3FF3F9178FULL, 0xD70E0A34901A0BFCULL, 0xCB027A9148F09CB8ULL, 
            0x5FC0C6BEC2F20911ULL, 0x83470463EFCA503FULL, 0xA423429B008D4E50ULL, 0x2C5863E3D63D2622ULL
        },
        {
            0x4C1BBC7E09614CD6ULL, 0x6E25C70454348902ULL, 0xCCF0B980D3C57BA3ULL, 0xE43DBE882EDD006CULL, 
            0x4418962A7BB39D14ULL, 0xB83C6907F84DB2FFULL, 0x6AB43409CDCE5F65ULL, 0x99AFED9010A14701ULL, 
            0xC659F152DB557814ULL, 0x6FCE9ABBD6C230D1ULL, 0xEAD5F6023FA8AF41ULL, 0x897293C68E21D73BULL, 
            0x419885C959C3BA3AULL, 0x5DB0088FC5228BEEULL, 0xFCE561F3DEACAFE0ULL, 0x3AEDB2DF947EEB0AULL, 
            0xC3DB19E19A2FA8A2ULL, 0xC00AAE2E08E9A5C7ULL, 0x5232D976275CF5DEULL, 0x2B5BF8B12583CFDBULL, 
            0xA32FA1023984BC28ULL, 0x82349240FBFA02CCULL, 0x54680B8D0189B54EULL, 0x8A73A437D416D8F6ULL, 
            0x56B3A3A23138B22BULL, 0x4DF49D0C4E55E585ULL, 0x4C2C4080132B1299ULL, 0x64935E2A9B29AA17ULL, 
            0x9A11149031E6188DULL, 0x708D910EC6A9EA36ULL, 0x6521FA73BDAD0115ULL, 0x1A22C983E2E2F1CAULL
        },
        {
            0xB8E106BED0B45BDDULL, 0x141FF1816680F51EULL, 0x1A38BF691CA2DB7DULL, 0xA8AC00A16F4B95C0ULL, 
            0x7A67BDE25CCF5FAEULL, 0xE380439CAB9A499FULL, 0xCCC148D29CFC9209ULL, 0xB4FA55B99D85E33EULL, 
            0xEF99066C1AEBEFDAULL, 0x9FC98C2BA0836298ULL, 0xA7A46FC4D6BA58A8ULL, 0xB807656E7DBE7D5DULL, 
            0x31E3F4F505EC36B7ULL, 0xEC6E377F8BE82253ULL, 0x8F1AEB13BB4443F2ULL, 0xD93B023247984DFDULL, 
            0x0C3E7CCEA2711486ULL, 0x9080933DD0B091D7ULL, 0x7744EF4DC9C49458ULL, 0xA9D8F8202A359724ULL, 
            0xB29991605FCD782BULL, 0x7621F4981F73A3EFULL, 0x0EBEE819E32165B4ULL, 0x4F0A0F81EFA0900AULL, 
            0x1D904015EFE8E6DAULL, 0x5B38A07857697888ULL, 0x6608DDE277B68B27ULL, 0x61931A436E00D8D8ULL, 
            0x356EBA4A10F1E772ULL, 0x631ADC810C4AE7ADULL, 0xCE4278AFA4C9BDD1ULL, 0x45ACC96D31633D11ULL
        }
    },
    {
        {
            0xE3E1B545F164A4E5ULL, 0x7ED7985E03645756ULL, 0x0E502C2E6DA59811ULL, 0xE947B2F04F8C1745ULL, 
            0x6AADBA0FA28282CDULL, 0xA510F33E160F8FF9ULL, 0xAA3A000D126EBF91ULL, 0xAC689386F89080FCULL, 
            0x55D10F7C3280FBF6ULL, 0x7943C07A3E4C255AULL, 0xC78D2E04BF840C69ULL, 0xCA21FA9AF9A280ACULL, 
            0x18AE904EF13FE411ULL, 0xEDEBA243FF9168E9ULL, 0x6385D20DBAC5DDB6ULL, 0x8BF4F328379F59EAULL, 
            0x447A9AF785E7C41DULL, 0x26FC486CA12AE6DBULL, 0xB2A042B35E0AE398ULL, 0xB3A91964B410B09BULL, 
            0x6AB79F1EE5804301ULL, 0xF5CFF8528DAB188EULL, 0xF0B0F97D2B7E154DULL, 0xE23ECB3EED11CD8DULL, 
            0x8CB04480B8D88C18ULL, 0x3686F0F72B2E30D8ULL, 0xA7E83546514B4F35ULL, 0xB9C2034B00922FD1ULL, 
            0x87716DF2669C405EULL, 0x8BFD51B971C33C2EULL, 0x31FB633686E5D500ULL, 0x887B9CE73A224636ULL
        },
        {
            0x68F0AA9F80397AABULL, 0x5FD57BF5B4357C3FULL, 0x81F3D250BF8D2641ULL, 0xB469B87BC547EF44ULL, 
            0x9FF65219B5AC072CULL, 0x27A64AEDDA45AEDAULL, 0xF7D592E27791A65BULL, 0x8712755F627F8419ULL, 
            0x5A4409ECD0CD1862ULL, 0x930DB9168DB1692CULL, 0x97D61140A30AB4F5ULL, 0xA919BDEE97ECEEBFULL, 
            0x64C6A39C662591D3ULL, 0x32123233A38DF3C6ULL, 0xC6AF94129B74212BULL, 0xFC4C10A8C5C786C1ULL, 
            0xF780E3F9E4264D26ULL, 0x3C7B66AF6A32812AULL, 0xEC6519C759381CC2ULL, 0xDACD2C80F30BB051ULL, 
            0x4C8458439ACC0698ULL, 0x5132ABC5DB585CABULL, 0xEEAF8B900D5A6C1FULL, 0xBF228CB64F75103EULL, 
            0x9FC0356B48DAE881ULL, 0x1E2D90D79528EF7CULL, 0xCB791C9AAE91AC60ULL, 0x608DA8C9618CB3A6ULL, 
            0x257E2A6547A8F2DEULL, 0xD341092F0284794CULL, 0xA86C72BC5073CB7CULL, 0x02BF10F22824FEC6ULL
        },
        {
            0x4866925D033942CCULL, 0x26353B0FC7FE6737ULL, 0x45734B8A490FAA7EULL, 0xC4AF8426DAE7CB16ULL, 
            0xB3FE2803B89EA5D0ULL, 0x19BA0BF916C6C78AULL, 0x6428EC87404C4BBFULL, 0x1886A8B0F03689FFULL, 
            0x1F834E00AF2F2C88ULL, 0x4E2D2159B6FAD066ULL, 0x1105384F3E7A7085ULL, 0x12F98E9CDADE43B9ULL, 
            0x620F3B8A4045D982ULL, 0xEF0286A87427F803ULL, 0x82990F6875CD68AAULL, 0x4548F46A10CF5BF7ULL, 
            0xD6A67285D07981A3ULL, 0x0875CB982E759123ULL, 0x293D4BEA28682802ULL, 0x6B756B2CBA2A5DBBULL, 
            0x7DE070AFD68292D1ULL, 0xC0E605E2BAA8CF79ULL, 0x4FBC77C777DA697DULL, 0x2876A3BDF4F7F01BULL, 
            0x53F829963D7EDE35ULL, 0x9CA49665CB3CD675ULL, 0x323C57A8F0D696B2ULL, 0xCAC33DEBCD7A6D52ULL, 
            0x574454097F8EED4DULL, 0x0AE922A98EDC18F4ULL, 0x9615C42DB2BEEB98ULL, 0x1BF80B6352584E37ULL
        },
        {
            0x201857C953DAE154ULL, 0x2A6E6CB6AA08429EULL, 0xD671387C034713B7ULL, 0xD20E8F8377FC1642ULL, 
            0x7C5C9D9367E15DD4ULL, 0x1A8E2292EB9D0C92ULL, 0xD49BA8A9D6483788ULL, 0x444D4BABB88CD176ULL, 
            0xC3A645E3AB10C070ULL, 0xD4CE5470DCCF4AFDULL, 0xF57D155B80A6A1A4ULL, 0xB55C15E017C9BE30ULL, 
            0x29F22ACA4F5440F5ULL, 0xA11206DB40AF1E21ULL, 0x022C7D7259FFC65FULL, 0x3E32425C14BF8BB3ULL, 
            0x9333793DDC80A9A5ULL, 0x1FABC9825E855870ULL, 0x772C974BF6B32E8AULL, 0x6708357FC7175138ULL, 
            0x3285169A2C92560BULL, 0x52FBAB64C120E750ULL, 0x5F4FD77CAE780869ULL, 0x588DD5F819F077FDULL, 
            0x586EA7D776328EFFULL, 0x0CDBBB6E3174EDDFULL, 0x031A31A59E5A7170ULL, 0x9EF9A0CB3CD0C63BULL, 
            0xB02809589853CF9FULL, 0xEF155908EC751C47ULL, 0x74B6A187479285BAULL, 0x6EFFFB68A3863173ULL
        },
        {
            0xBDB74D8842783B5CULL, 0x7736881DF9AB441DULL, 0x39A6AA9384CAB1CDULL, 0xAF6C032F082EB092ULL, 
            0xEED4705C9676DE97ULL, 0x96DB759DCFED1922ULL, 0x318D9FC8A9543D76ULL, 0xA587FA0B0D47E742ULL, 
            0x70E1D785DF169F9BULL, 0xE61D2A448581C02DULL, 0xA0E764202618BAAFULL, 0x1CAE1A02A62E3E98ULL, 
            0xB540BA95A4270E9CULL, 0x4612BA845037BD28ULL, 0xE7075F55E713AE10ULL, 0xA3DCD885D58B1430ULL, 
            0x6E6CF60EE099818FULL, 0xB267DBF2CB9BB88BULL, 0x388D68AE126012D8ULL, 0x71A0303EC408AB0AULL, 
            0x53EAA7464A2D2F9AULL, 0xCA6CB2E508147A28ULL, 0xF426601801C9A4E6ULL, 0x2431173905F549ACULL, 
            0x9617881976C486B0ULL, 0x1BF63125FB12D87FULL, 0x4EABA2F0ADBC6B92ULL, 0x94BE2BE5EF1A2546ULL, 
            0x4B216599ECF91E13ULL, 0x137F0B6CC4121AD7ULL, 0x833D54D99DBE2364ULL, 0x5B5ACD8BCA89C342ULL
        },
        {
            0x2EB04ACE7B8DAA6AULL, 0x919E24AC852EC1A3ULL, 0xA831A460C9E3F0F4ULL, 0xAA09A11E3E588BB1ULL, 
            0x4EC733E8AFBBE15CULL, 0x449AD737CE8FDCBBULL, 0xDC6421362A350CE1ULL, 0x5EEFF6E2CB618E5EULL, 
            0x402666E91B56101FULL, 0x3BE6EC59529E0DB3ULL, 0x0DD576A6815DFFBDULL, 0x5EDAD71212EEE539ULL, 
            0xBBCE4D2710BD5A4BULL, 0x03DAC7ED8B8317D9ULL, 0x94A4699C0BF12CBAULL, 0x48C4303CB7B32B8BULL, 
            0x25F0E6BA2ACF44F2ULL, 0x46EB5B0A2F291A2FULL, 0x9FD10D39F5F2E7DCULL, 0x0889958AC82E5732ULL, 
            0x8D52FDDA5E9F7D04ULL, 0x3915D780A11D1610ULL, 0xADAD9D6C0CE75F58ULL, 0x6B20488997F7690EULL, 
            0x2131A7C096D2371BULL, 0x48A590D74CF0E62CULL, 0xE17637BEE2700960ULL, 0xE3B47EF47C677CF9ULL, 
            0xBA71502B8C198BD8ULL, 0x940C9FB0ECD5AB5FULL, 0xBDF86FC06BD3B075ULL, 0x4D78D53538234DC1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Sirius::kPhaseBConstants = {
    0x22035E121331B2B6ULL,
    0x8D5472C72C61BE26ULL,
    0xAA62658B957C6DF0ULL,
    0x22035E121331B2B6ULL,
    0x8D5472C72C61BE26ULL,
    0xAA62658B957C6DF0ULL,
    0xD2334AA4FEF5E594ULL,
    0x2D5F5D0A48A98096ULL,
    0xAC,
    0x4C,
    0x4C,
    0x1F,
    0x97,
    0x2E,
    0xD0,
    0x50
};

const TwistDomainSaltSet TwistExpander_Sirius::kPhaseCSalts = {
    {
        {
            0xAEDBA9B64F3FC477ULL, 0x075EC61CD54BEFD4ULL, 0x6DB2A2BA2F46B717ULL, 0xD7EFB732103CC9B2ULL, 
            0xA1D23A161552EE25ULL, 0xBA2803769CE298C0ULL, 0xE2D48D63B8F5A8ABULL, 0xC7EC9FBA4799F52BULL, 
            0xEECF52D7A031699CULL, 0x9CABAB279DDB0E47ULL, 0x3FB9392F6A790EADULL, 0xF675D506FD770CCEULL, 
            0x8FB9C7ADD339BA16ULL, 0x33F46EAD7970D460ULL, 0x46D8F294E7857366ULL, 0x9DC074EAAEDDE78DULL, 
            0x3C0E5811B4641209ULL, 0xD0530B445DA1BA18ULL, 0x6535F40D9FDAE18FULL, 0xBFEFE6B8272CD877ULL, 
            0x7BB239745B9E8BBDULL, 0x0E2C54B37B47B809ULL, 0x0055CB3A1421B873ULL, 0x9C0BDF524848F53FULL, 
            0xDE3D2AEFEE35AD64ULL, 0x1092B72396735482ULL, 0x7F2632E6FCB03261ULL, 0x63E9782C07F91F3DULL, 
            0xF12F3B64046C0449ULL, 0x378E704E948A5DC4ULL, 0x6EFCD54672CCBA54ULL, 0xCE31C4C44AAC16D2ULL
        },
        {
            0xEBC8FC1E13852B4AULL, 0x9E36D92076A5A37CULL, 0x921A051342CB1744ULL, 0x8F39C4E8973F5C65ULL, 
            0xA1FB5807FA00E253ULL, 0x040DE8D3448C72DAULL, 0x113920E53D318689ULL, 0xD4DCED0029736C38ULL, 
            0x7E96D41CE9CCCC63ULL, 0xBDE8FA52128E91B2ULL, 0x342EC8BF2539B991ULL, 0x20108C3E51CCE744ULL, 
            0x47F01D7D1A32F9D0ULL, 0x622AAE000F43AFECULL, 0xE26B544265B1E30CULL, 0x3C164CB2A8E4A055ULL, 
            0x16DED6FBD4800E47ULL, 0x9039D1422A3DB330ULL, 0x2908B8117590D4E0ULL, 0x4E3A03CB38CFBF7CULL, 
            0x5E7FF1B906E8C09DULL, 0x794A0C7D48F87218ULL, 0x5048ED2E4977447BULL, 0x3C3B36E381BD784DULL, 
            0xAF02F1386E161C27ULL, 0xB1908476D6B774D7ULL, 0x6D7B65681D42D479ULL, 0xCE347BBD1529E536ULL, 
            0xE490C1CFE110C08BULL, 0x007FFE46405F14BCULL, 0x89F98CA347A25599ULL, 0x167B2C16845473EBULL
        },
        {
            0xC0AD30EDB7BF4B5AULL, 0xB5940771A6555455ULL, 0xDBC9D6B08B0920A6ULL, 0xF918046E66C3B738ULL, 
            0x2A2AF7FBDDB70A16ULL, 0x8A769694D74CAE07ULL, 0xF87EC55AF16D8653ULL, 0x7E224CA8E5520988ULL, 
            0xAF324A7C31067FFAULL, 0x6E4F87A6884209FEULL, 0x4E1B88CF97D92C03ULL, 0x52493D31E50F977FULL, 
            0x22AE3686850AA8C6ULL, 0xAB0F9B33EA48F6F5ULL, 0x917C7139CEB7778FULL, 0x61BE568B0F3D726BULL, 
            0x55E3CBF0E321D8BAULL, 0x456C0CF1D5D7602BULL, 0x9FB07E94D97AA740ULL, 0x2579ED2383F97B9CULL, 
            0x4835D223FAE08DFBULL, 0xB6BC8F893C4F50F3ULL, 0x8219EDEA6BF59AEBULL, 0x532D1F224A61599AULL, 
            0x0E9A22BC61FB7015ULL, 0x961464B8076D1D43ULL, 0xBEF1730E82E84218ULL, 0xAB51890BB2B09E4BULL, 
            0xC31FDFD73EF26AADULL, 0xD8D430B81E293793ULL, 0x49822653ED4FDB9EULL, 0x7AB2A29266200F0FULL
        },
        {
            0x6B24209FCE6AEA95ULL, 0x7CDB138E02316892ULL, 0xFF8B0A4696323744ULL, 0x11623F82C4F3BD13ULL, 
            0x1DC4CF2611F344C0ULL, 0x6993FAA154285D75ULL, 0x5DC6B5EFE195B91EULL, 0x900431EDE1B62A23ULL, 
            0x0A0D531120E3BFC1ULL, 0x2F0B103F1A616DEDULL, 0x913D7083D257DB17ULL, 0xFBF5337C823A1604ULL, 
            0x9B53BD934031F914ULL, 0x202FC29A2F6729E5ULL, 0x93682F087DFE0B4AULL, 0xB8434D124A825B13ULL, 
            0x26FF9222D31147D7ULL, 0x68FC0BCB28AFE8A3ULL, 0x5A7F5725A7F28476ULL, 0x417C068817238CEAULL, 
            0x65C4CF32B151F1DFULL, 0xE1D45EA46A66F6E5ULL, 0x6C0A5706D6358412ULL, 0x277BC652658CADEAULL, 
            0x3FBEE1A5C0E2C560ULL, 0x3840D1E1A12698C7ULL, 0x088383968F3C26C2ULL, 0x8E402BB046074A3EULL, 
            0xE97211B3CA96AAF1ULL, 0x6CCEC2BDF5DFE200ULL, 0xBB799584D5DB19A4ULL, 0x0204FAB602E4220FULL
        },
        {
            0xBE8915540680082FULL, 0x77D2F2AAE4C63D83ULL, 0x85602FB9A2EF1480ULL, 0x0E4FA54E8404CC35ULL, 
            0x9C951CCA3384106BULL, 0x194CC964AF2B4E93ULL, 0x471079DB81B2F67AULL, 0x79D01C00E8BA55C9ULL, 
            0x96ECE63C41774D6AULL, 0xFDE47A516A83B28BULL, 0xA881AD06380C789DULL, 0x5731E358DF4D00CFULL, 
            0xB5B285A28F6A7184ULL, 0x6803EC034E32C7A8ULL, 0x6BBE38591DAA59C8ULL, 0x7713D600179E86E9ULL, 
            0xE853BCAEFEF64196ULL, 0xC91602BB755ED027ULL, 0x8B7AD1FE8F7C0B0FULL, 0x65FC8221C9964891ULL, 
            0x6DC23587C7D37087ULL, 0x885793CAD10188D1ULL, 0x30A8FD260E985AC8ULL, 0xED05C8FE6EF7A36AULL, 
            0x4E98093BAD2D011AULL, 0x7D96BD6631F64CFFULL, 0x4B0A5E568A36B78FULL, 0xC8A0C763DF67DB6EULL, 
            0x0341E88D92D59861ULL, 0x1A387C2CA2DF86A0ULL, 0x76932C40BFBC149FULL, 0x45242115FCDC87B5ULL
        },
        {
            0x8FDC982AD9CBD270ULL, 0x10A3249E59141A9FULL, 0x8585F3776BD5745EULL, 0x2F79B81FF39FD038ULL, 
            0xB0E89C9877351134ULL, 0x45F5482690AC2461ULL, 0x0CC87A1ED5F16402ULL, 0x85A107FBDA1DE1D8ULL, 
            0x385789F02B2F044FULL, 0x586A4EFE05C92DCAULL, 0xA2C58D459427CEC7ULL, 0xB38F96B2A9BCA047ULL, 
            0xF967768592B98FD6ULL, 0x841F566D6B045892ULL, 0xAA527197E8AFF36AULL, 0x672D4D4C0D349D2DULL, 
            0xDACD0EBD5872A724ULL, 0xA079704BA12A8E5DULL, 0x3849267D1B04118AULL, 0x99A10DC0376569B8ULL, 
            0xE72A9940B2DE8E28ULL, 0x5923CDC2E3F22556ULL, 0x1B31776C41CB2166ULL, 0x3F5B840A94FC5404ULL, 
            0x9C0D6781C18DE7C8ULL, 0x18A05C4387788348ULL, 0xDD891310E417A0CDULL, 0xDD1F6854AC44C8FAULL, 
            0xCCBC9E1CE0947AFEULL, 0x8A7C1F53D46A60D7ULL, 0xEA6C42F93F861A39ULL, 0x84BD6C5A08C4D5B3ULL
        }
    },
    {
        {
            0x7188D52A2D4EBB2FULL, 0x68210D5534FB560DULL, 0x7C6A84F45E0DB5D4ULL, 0x96C0C603B3BB5FF9ULL, 
            0x9539340568B6BF74ULL, 0x1F4C3DAAD18F05BAULL, 0x0B140E6CDCA67106ULL, 0xE98E5E5839DF8B8FULL, 
            0xF47E002CB3B3B4B5ULL, 0xEBC6819F779CD20BULL, 0xB8916DBC758E3504ULL, 0x74189CDA0AC0F194ULL, 
            0xB7562D69B9D29388ULL, 0x00DE7CC7A91A9890ULL, 0xC245B0381E220A19ULL, 0x40C77AB3667FAFFCULL, 
            0x70771FB0BBE1068CULL, 0xD4AA2499A2A9BDBAULL, 0xC0AA608212F97493ULL, 0x5B64213C7313B608ULL, 
            0xEA417EAE298CF4C6ULL, 0xBF983D1626AC5954ULL, 0x44B24624286F8496ULL, 0x6DBDA566FFD2FD7DULL, 
            0xB2E1B844550DE07EULL, 0x6B7E01899D8B9C0DULL, 0x64B6722E7E1A2D9FULL, 0xFD4F255EF8A398D1ULL, 
            0x6F98F21BC90913B2ULL, 0xD67A8EF9F6790AC6ULL, 0xE5C7BC72FE83F5ECULL, 0xB75FDA2514915880ULL
        },
        {
            0x3396C32E308F623BULL, 0xF5588FF4CB7DC560ULL, 0x12407E62F69C57EDULL, 0xCF0B1C886AEE45CEULL, 
            0xB139DDDAF6DD7406ULL, 0x80B43D41F105701CULL, 0x846E3293A4071A2CULL, 0x878F79F210AE38A4ULL, 
            0xD2512CC89C1EAF3DULL, 0xC7C9C012E7F09EC2ULL, 0xB1E586086AA946B8ULL, 0x2EC8027C0EDEED58ULL, 
            0xCCACE07A45C2A844ULL, 0x968BB4730A9E47E6ULL, 0xF71545C9D212A183ULL, 0x265BA45A2D11897BULL, 
            0x2AD5B1B48A071926ULL, 0xB4F26DF7FACE2C62ULL, 0xBB11AD19FDC0E3F6ULL, 0x5279848DFA86476CULL, 
            0x5D40422EEE77BFB6ULL, 0xC5F327B8441F3533ULL, 0xBA5D55872F83A506ULL, 0xDA85FDA2CB54E71EULL, 
            0x2E1A23B4126BD5B8ULL, 0xAF651E9D006D494DULL, 0x8B17858A6F11EB9EULL, 0x7345FEDCE10C3C5EULL, 
            0x43B404DAB2A5E7A3ULL, 0x75AC7297299703DCULL, 0x783692FD4BF3ADB5ULL, 0xF724A6E5D350289AULL
        },
        {
            0x551AE338FC76AB1EULL, 0x85BCFBC5927CD0F3ULL, 0xD234E891FFD8E1E7ULL, 0xAF50B177CCA15278ULL, 
            0xA559FB1F776AA8B2ULL, 0xCCFB598174E1F5D1ULL, 0x9F108D429073EDF3ULL, 0xE2FDF4B1ADF31ED8ULL, 
            0xDA8E7B9B9D970884ULL, 0xB0589C97B4400E5CULL, 0x11AF3C742D0B2C8CULL, 0xF0BCE69443236766ULL, 
            0xEC84DACF367E746BULL, 0x89DF4210833AF255ULL, 0x7EAAD76A30A56B02ULL, 0x393ADE7E34C32657ULL, 
            0x800D15EB4D37B90FULL, 0x724DB974393831EFULL, 0x6CC85C7F638C0ACEULL, 0xBE70983F7D4C2E13ULL, 
            0xF79F00638D67A0CBULL, 0xED42DFE15880B2FAULL, 0x35D55955C347CB51ULL, 0xF0E9652A232623C4ULL, 
            0x720F5B3548C68A28ULL, 0x072CDB1E9397A9A2ULL, 0x4249487B64B876BFULL, 0x75FFA95A5FF9B079ULL, 
            0x31B97D07E1FF2F9FULL, 0x88845BEF72B92A85ULL, 0x05F163581A9AEFD0ULL, 0xD62649E49587E839ULL
        },
        {
            0xABE39F746A70F4D2ULL, 0x14BF4AF4719D0778ULL, 0x2641A8DE7688FFE6ULL, 0xB3C07BAFA8CD387CULL, 
            0x8C60EA5FBE0B9C89ULL, 0xBA645DFB1A924419ULL, 0x4AF7F8AC060ED842ULL, 0xEAB85F6B514E4D9EULL, 
            0x9809E25B617C8DD2ULL, 0x3127330CB3B6F538ULL, 0x5E8B5E01ADBABD3AULL, 0xC38F9A8745C9E636ULL, 
            0x791A5C1B77B3DCF3ULL, 0x0DC1C8BCA778E2E1ULL, 0xEF71BFCF40E04F38ULL, 0xE4F0012038EBE69DULL, 
            0xBED9BA1C68927BEDULL, 0x301D6C879CF688A1ULL, 0x279796E85DB5E121ULL, 0xA7920C1D3E638D77ULL, 
            0x2182F50176E921CBULL, 0xEF2C7E9754B7D548ULL, 0xBCA62CFE00BAE388ULL, 0xAC46E521EA4573B6ULL, 
            0x602B5B8BFDCB95F2ULL, 0x78D23A26EEF7D7B2ULL, 0xED046FDF8AD6D302ULL, 0x749B2A9684C9DE49ULL, 
            0x09B97BBBE1CFDAC5ULL, 0xD32CCAC7D8970445ULL, 0x3636B77953EA20B4ULL, 0x725ED9C675ECC08BULL
        },
        {
            0x9BDF1B2F34C5D0B9ULL, 0x54FA3A64E4F855A5ULL, 0x201FF1E21CB07DD1ULL, 0x4B0F395DD0C5B3ACULL, 
            0xC88763387BAD5813ULL, 0x353315158CC0F5AAULL, 0x8A981F8422866A10ULL, 0xC76131ED0E463636ULL, 
            0xAF28113BF69AA5B0ULL, 0x1F82ECF891B6C84EULL, 0xAB128E9D704D8859ULL, 0xED2AB520D6FE58C5ULL, 
            0xB7CC7AD51A88D0C1ULL, 0xBFCD21A089A64B77ULL, 0x66AF9B22AD1085E7ULL, 0x399FC44EBFFAD952ULL, 
            0x79FC02E8754E61E3ULL, 0x8EDB364CA553488AULL, 0x9F7042B1B964179BULL, 0x4671EB2D9014418EULL, 
            0xEE8EB739853A5BE1ULL, 0x0A9A20B5D22CD2D4ULL, 0x180D8730CFE81B59ULL, 0xD73F4F734F9728A7ULL, 
            0x7AA436921B807C7AULL, 0x61033B460CEF3A63ULL, 0x79BB47FEEC59567FULL, 0x3669814E4947865EULL, 
            0x7E3ED4D212D28CA4ULL, 0xE80D67E2602A0A24ULL, 0x221A401B291A71ACULL, 0xB38035006DD53DC6ULL
        },
        {
            0x33C6FDFFD79B984EULL, 0x59F711AE14FF9C2EULL, 0x13CBA5129C03E19DULL, 0xF1C996770F11F9B1ULL, 
            0xE1E47A5DCE5272D4ULL, 0x3F1807B35DB6052DULL, 0xC709B1CE6F9B826EULL, 0x4278521F9EA89942ULL, 
            0x6BA1260017CCFBB1ULL, 0x5E94F74D56B35158ULL, 0x34A0EB9AAFCE7261ULL, 0x60062BFFD321AD4AULL, 
            0x7AC71B25CE0934FDULL, 0x88BCD64E4386195AULL, 0xECB05B065E4F441FULL, 0xD95CD7AE4F150BB3ULL, 
            0x3C267A3AC7836E72ULL, 0xE532A5B648C382A6ULL, 0x4AA7801B8AF5795BULL, 0xE2A156B5CE1FE1B7ULL, 
            0xC83E271FC6015671ULL, 0x1D1BE51ECD6754B3ULL, 0x4669958BAF460E64ULL, 0x761FA34964C5DB6DULL, 
            0x90A1D3862A165592ULL, 0xEC5FC30FE5DD5BC5ULL, 0xB1DAFCCE4FE7CDE5ULL, 0x7B5B2F53E866B5FCULL, 
            0xE2EF302818987BDCULL, 0x3D3B0999E05ABBB3ULL, 0x658918BF0E532419ULL, 0x91EEFF1E5D1F9824ULL
        }
    },
    {
        {
            0x3B9DDA7C8018C24DULL, 0x106FF1658D7BAD75ULL, 0xFF98BCA07AEAAB8DULL, 0x6261BD16230589F1ULL, 
            0x5D1DF7B8649C5429ULL, 0xF5ADB4930079FC88ULL, 0x87B1653E92B36D05ULL, 0xD811E18CF5D2FB9FULL, 
            0x4D86FE49A6485445ULL, 0x4C4C788F90C4BBD5ULL, 0xB3827170F3A201E2ULL, 0xA1299948BF113F12ULL, 
            0x29063F02888ED99DULL, 0x92868A566F79BA5EULL, 0xB1AF4A28AF7CF8F8ULL, 0x1B029D53C004B3D8ULL, 
            0x93432B72721733EBULL, 0xA959CF675E5233CEULL, 0x03B22B91EE02687DULL, 0x1E82E61371FE19FEULL, 
            0x9B95B3B66866BDF0ULL, 0x732BE4218D5BD4C2ULL, 0xB615C1BFFB91E7A4ULL, 0xBF9705E98E8C8BF9ULL, 
            0x10ECEC579CEF4080ULL, 0xE1F91A8546646D04ULL, 0xAC1729E73DD2D283ULL, 0x70492A851FB08957ULL, 
            0x3CF0A9BF57C563B5ULL, 0x90E0F32D3127124DULL, 0x03DE3508BD7464C7ULL, 0x44504DDAA1C4516CULL
        },
        {
            0x4041479FDE5A9AAEULL, 0xFDBF7F326CE3CCFAULL, 0x06A3242FBFFB6CC7ULL, 0x4F984274F5365228ULL, 
            0xF54C5E39C69557E7ULL, 0x64F20175844DAB36ULL, 0x40AB3BA0B80B40CBULL, 0x308C1F7F9E9857B5ULL, 
            0x7B705E2B6128FC64ULL, 0xA6BD31C5BE73366AULL, 0x195D0D99132F0D76ULL, 0x8250FFEBE0073A43ULL, 
            0x8EA7D9E66512E953ULL, 0x438DF0BDF93AA385ULL, 0x039703DD82F5D4DDULL, 0x99DBDEFAB397A4A0ULL, 
            0x8AB64BE768683B1EULL, 0xC67666E83827FF96ULL, 0xF080C7EE0A9034B3ULL, 0x53FB051FE26F5DB3ULL, 
            0x3BFF61A20BB9FB84ULL, 0x512DFEA6B6806385ULL, 0xE604D747AA65D934ULL, 0xDC67C6F18E7114C9ULL, 
            0xCA7F602E824E08DBULL, 0x7A841BCA82A5D157ULL, 0xCF489ED0E3825AA0ULL, 0xCC0DB84F35FB3F53ULL, 
            0x009D297F948DDF33ULL, 0x616E42783B978B8DULL, 0xC468906B3E26FD24ULL, 0x379C56C87CCA3E52ULL
        },
        {
            0xA28EBDDD8D4B5783ULL, 0xAB4DE784F467781CULL, 0x7AB4239E2D248ADAULL, 0x93D929EB2BF82E5BULL, 
            0x4F01A6D83DB7F36DULL, 0x86AFE41F53979967ULL, 0xE9093A74BB0933ABULL, 0xACFED5EBEBCF7607ULL, 
            0x8181018B0FB9D4BEULL, 0x4AA009BFA90B6E85ULL, 0x7AE12739F5F61CC4ULL, 0x2127D717B4E34205ULL, 
            0xB6414B01A5B9BBA4ULL, 0x1B83BB34AA23017BULL, 0x827C9C77EDDBC970ULL, 0x8B7176D33B985A90ULL, 
            0x5213FABCD149FC10ULL, 0xD824F4901EE6F4DDULL, 0x2C67F36AFA1190BFULL, 0x76E763E24E51805CULL, 
            0xC73DE8103A85C815ULL, 0xCE97BA4A83D0A563ULL, 0x24A59EAB9053C3A5ULL, 0x1AC441C171974EF3ULL, 
            0x8CC3006C905E8C20ULL, 0x925B95A7B4972292ULL, 0x17C3EA235B96D854ULL, 0x7D04930F619EB8C9ULL, 
            0x36A6AC663C5C9B73ULL, 0xD47DAD666777635DULL, 0x440D3707237A649EULL, 0xB2B2F99F77EBC28CULL
        },
        {
            0x2B60E080557E6419ULL, 0xC3A713EE45DFC7A8ULL, 0x2225C12BF63A5866ULL, 0x3217CBF0D218B722ULL, 
            0xFABD11940ED8177FULL, 0x58671100802FF458ULL, 0xA6A154EFCC5521A6ULL, 0xB6E9CDCAA2CA437DULL, 
            0x7A3EB84ED1B52EABULL, 0x8E3AAFC471903FA1ULL, 0xE97139B00C6818AEULL, 0xEB37EC4F293A826FULL, 
            0x90CC87F88DB5C5D4ULL, 0x2D4084D5D090500EULL, 0x8F4321ECF6C98CC0ULL, 0x3CC1CFBF7B2C52C4ULL, 
            0x8637F5D052032895ULL, 0x1B11CA359FBD174CULL, 0x54339DC41093A7E8ULL, 0x86865589F45E09C2ULL, 
            0x0222C4C5447C0CC8ULL, 0xDB23B2CCD6DD6612ULL, 0x142766077580F4AEULL, 0xA847FDB2CB765254ULL, 
            0x8E4288EB038A3C7EULL, 0xD822C344BDFC6129ULL, 0xB7104614203F6B36ULL, 0x87F85813BDC9FE02ULL, 
            0x4A7E4F5116AE269DULL, 0xA789B1F2A8FAA6D5ULL, 0xD5A028BFDE859C4FULL, 0xA1B858D8D841678CULL
        },
        {
            0x551B5C6C63000356ULL, 0x76AFE80411235D6FULL, 0x8962D87C4FD549FEULL, 0x34A34804393A73D2ULL, 
            0x630A40094DE71F84ULL, 0x9614EDF0B7F842B1ULL, 0xEDCB79B5469B042FULL, 0xFFD187B6A7E547C1ULL, 
            0x6CFC66B3440B103CULL, 0xEB151DBD9107D3DAULL, 0x04BEC1D04C8B7083ULL, 0x3F3E87D659950D3CULL, 
            0x1092E06755547FF4ULL, 0x84AF3713743CC9B7ULL, 0xE995D66D66DB642DULL, 0x965A74B261ABBE8DULL, 
            0x19E54C5CAFE870C0ULL, 0x965D20575CA71D4CULL, 0x4427D4E951343256ULL, 0x9306D6424E3E57FDULL, 
            0xFE612656CA30C4C0ULL, 0x420FFA257BBF8A55ULL, 0x774AABCC23C969FCULL, 0xB8D0A84591991DEEULL, 
            0x50B903BF03712319ULL, 0xC559243072650628ULL, 0x8B77EDDDED45E85DULL, 0x01E8A114EE6AC15FULL, 
            0xB3A1B6FF048B4873ULL, 0xAAB8AAAC25DF5F6CULL, 0xEF4324697A08918DULL, 0x0F9F1A97EBF8582EULL
        },
        {
            0x775BB10D3C477B9CULL, 0xEAFB20EECD3DFACCULL, 0xEDB9417B4F13062DULL, 0xB7005670766288F4ULL, 
            0x4B4343134F103EA3ULL, 0x390BC391E7DF61B1ULL, 0xD983C5AFEB48BB70ULL, 0xFA5B6E0FDBC8F647ULL, 
            0xF8B2B1F5727CA161ULL, 0xF580A4A34B711C4AULL, 0x81FA7066D51F194CULL, 0xF9E7DCCA37E80132ULL, 
            0xF645D5FD67E95959ULL, 0x3892F81F1D0521BFULL, 0xC07D64EEE63FBFF8ULL, 0xF0CC4368FEE01AA7ULL, 
            0x98F5257EE810E094ULL, 0x6E8A0D6218648097ULL, 0x9240CF345C880177ULL, 0x08412FFA030543F0ULL, 
            0x7CA2E8B912F27EADULL, 0xFF7E2F948981E43BULL, 0xBBF0838B1FB893B3ULL, 0x7B605C7BB2A9842DULL, 
            0x34E645523E66BB57ULL, 0x0D97691861BDD303ULL, 0x3564C8A1FE779598ULL, 0xEE2C1674B56D7AF0ULL, 
            0x182ECFCD00EB86A4ULL, 0xC7F43936A5342E6FULL, 0xE74A9CDAD0CA2A17ULL, 0xF08D20D886FB9C9CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Sirius::kPhaseCConstants = {
    0xBE0331BF04D1DBEBULL,
    0x1AD420AB21C9B400ULL,
    0x0D9E2CFF0F30BC77ULL,
    0xBE0331BF04D1DBEBULL,
    0x1AD420AB21C9B400ULL,
    0x0D9E2CFF0F30BC77ULL,
    0xC3B0EFAA4EC92045ULL,
    0x82366DDF8C02F339ULL,
    0xD7,
    0x4F,
    0x8D,
    0x88,
    0xDA,
    0xC1,
    0xFD,
    0x8E
};

const TwistDomainSaltSet TwistExpander_Sirius::kPhaseDSalts = {
    {
        {
            0xD7EBD55A6D1896CFULL, 0x3EA7B2F35A9CED00ULL, 0x20B44098EA4D9240ULL, 0x3E1E93424E9A1B94ULL, 
            0x331E78ACDE568A02ULL, 0x27E254948DE89E6CULL, 0xD5F1CB4BF00E1DB4ULL, 0x2EB6A0AB16FA4ECFULL, 
            0x839952D6A9BAE871ULL, 0xA3372F17CE79E06AULL, 0x1D18E48DA685DA04ULL, 0xC6F7E897DBF71318ULL, 
            0xC08233531F82D660ULL, 0x718DD8B1BE6641BAULL, 0x85F165B8C5C06792ULL, 0xA5063A59725CA60FULL, 
            0x8C8D335CC942ACC3ULL, 0x0F7F2531B150BB02ULL, 0xFE55D2099FCEB327ULL, 0x92C44CFD44A17016ULL, 
            0xAE3C5013D28E2C23ULL, 0xABBF6CD362C1CBD4ULL, 0x83AA236950F2EFCDULL, 0xA78DD2049F427A73ULL, 
            0x2899F9761D92A398ULL, 0x74D7B67B7EBAB309ULL, 0xE053B731E051B426ULL, 0xBFF1942122F9B588ULL, 
            0x7F1CB26B7871BE4BULL, 0x68B013C68FC62CB1ULL, 0x35E784611755FC23ULL, 0x4E4406E7626AB476ULL
        },
        {
            0xBB78D06BDA1814A3ULL, 0xB97E791AE4558839ULL, 0xF32A984462751C62ULL, 0xAE20D15E012D4F33ULL, 
            0xA96756F171B9EF4BULL, 0x2DCA4D1DCA4FC443ULL, 0x1A7A7E6C41F30E1AULL, 0x25CFB9FA72D9D95AULL, 
            0xE8468BFFE5A87B29ULL, 0xF07D16EC7C147E55ULL, 0x822D6EBE66DD2E4DULL, 0xE361997F1D72305FULL, 
            0xD573580F02A1D99EULL, 0x89A7AA08AD8527C5ULL, 0x2C4E49E6DCBFF354ULL, 0xD4B7195C7FDBF202ULL, 
            0x5A4E85E5B1A1579EULL, 0x3201B28572519330ULL, 0x694CF03939B7305BULL, 0x064CF5479BF27EE6ULL, 
            0x2807FFFA25BFBA20ULL, 0x19D415905B6013D8ULL, 0x3AFA05191EAA58A6ULL, 0x8105F460EE990155ULL, 
            0x5D3280B757615F9EULL, 0x0A86BB3E914B5C8EULL, 0xDC21CE7F7B0F025AULL, 0x122BBF665C04E822ULL, 
            0x256329DD78401355ULL, 0xE3092CCFC10B5DFAULL, 0x0031D77BB240A5E8ULL, 0xE42BE0C61AD06FC5ULL
        },
        {
            0x47C37A19BD2FB30AULL, 0x04855458279F38D7ULL, 0x5F82DFC30F624A62ULL, 0x64719C58F0AC6D8BULL, 
            0x6E455E596723DD6AULL, 0xD93FA9338B845740ULL, 0xD3400BF154DAA4ECULL, 0xDD197BDC3E63E43CULL, 
            0x44B9A694983C8FD4ULL, 0x7B130F1BF97866BCULL, 0x5304A344FC59D4C7ULL, 0x1EBDCC47FFBB9FF9ULL, 
            0x513F90766D495EBCULL, 0xD0443F9383C03B85ULL, 0x24944B558C520868ULL, 0x4EFF60BD04F8E09FULL, 
            0xF0CEA3676BD16C27ULL, 0xE5CCE2C8D8557376ULL, 0x884F05F3F091A836ULL, 0x413281A2F0FCF369ULL, 
            0x9D258F855C21AA56ULL, 0x2323ACB09CE7742CULL, 0x2D3B00B4D4BF92CFULL, 0x19CC3A265A47D782ULL, 
            0x91E9846A96A5E4BBULL, 0xC31919DCE6BAFF6FULL, 0xEF0254C3A4349C5BULL, 0x0C07CBF7CEE5045DULL, 
            0x4B4599F7B378AA7AULL, 0xB53D603167E1AABCULL, 0x8BA963F08DAC3E66ULL, 0xC95C81C539A14BA2ULL
        },
        {
            0xE62B2D0A5A8A29D2ULL, 0x8DB7E9E9F1504724ULL, 0x8ABBBC01D4ECA3E4ULL, 0x693CFBD8E6A1ECE3ULL, 
            0xE31E3F66BF95DE0CULL, 0x509554833150C39BULL, 0xB7316038709511A9ULL, 0xE5CF34E6A9DC7C3FULL, 
            0x9D91EF32E3D14C9AULL, 0x43883B5FFD3E3A16ULL, 0x4263AD1FCE746C05ULL, 0xEAD2A2674412C080ULL, 
            0x642D7BBD12594C62ULL, 0xAE3DB4FF6728238BULL, 0x836F82AE9794AC94ULL, 0xC473FFF32C868035ULL, 
            0xE625A10733FF0072ULL, 0x07F715F03A4DCBF0ULL, 0x4F856ABF59645F28ULL, 0x0EB06473C6EDF0BFULL, 
            0xA468EC408753BF82ULL, 0x20CBA8B3A923FF8BULL, 0x5FFAE16A3F023E53ULL, 0x0D6E99C2E4654AC9ULL, 
            0xEAEE3F9DCF500119ULL, 0xB59DFD720027B48DULL, 0x19A3F5EBE557CC38ULL, 0x15354BC85640FF11ULL, 
            0xC81DF16339790625ULL, 0x4143B668EC237BC1ULL, 0x6F03398F80148785ULL, 0x29854F1C3E24EBF8ULL
        },
        {
            0x6754CD7421A9BBBDULL, 0x8EE8816698481B7EULL, 0x593DB5A2385E2EE6ULL, 0xECB8A81CDA1BDD66ULL, 
            0xC91DAD221EF30A41ULL, 0xA801D8AEBCE95074ULL, 0x19F6BCBB526281C6ULL, 0x7AE0DDA183623AF7ULL, 
            0xA345FDFB93CA46A3ULL, 0x390FAFA63D916B53ULL, 0x97ED5FDA8C56A61DULL, 0x3C79A0A68FDB1195ULL, 
            0xF82947EC4F6FD477ULL, 0x75CF4B559F8E0430ULL, 0xBFB273FB40778889ULL, 0xA2DB91846E2EC97AULL, 
            0xB363DD0F6473D57DULL, 0x2B33F7947957E254ULL, 0xA8128BA9ED5DF838ULL, 0xC89CDE1AA1C8D463ULL, 
            0xCF6335A5320A5AACULL, 0xAAB719DADCBA2AF5ULL, 0x9471E38430997077ULL, 0x9EA9BE24B62342D3ULL, 
            0x5B34231013DFDADCULL, 0xB9B66FF390B2BB65ULL, 0x7B665BAE3E91A208ULL, 0x7A2A6A06491DBB2EULL, 
            0x2A9760386AE6F83CULL, 0x846DEA53276412C2ULL, 0x824116B9030F21E1ULL, 0x9002F052E80AF129ULL
        },
        {
            0x0A0F8E3CC497CC52ULL, 0xFFE8799E239FBCD7ULL, 0x04DF4BCDF5A58CD8ULL, 0x2B1CA92F8C755BD5ULL, 
            0x29F2072191E62EBDULL, 0x889E2F9D01352B77ULL, 0x4D653C23309587FFULL, 0x2B999CCEEFE2E844ULL, 
            0xCE7EA3B4D2E24E3DULL, 0xC27AB05768BC7C6AULL, 0x0324D38EBBCB8B47ULL, 0x14EF7C021173F093ULL, 
            0x89FF810260DA0A48ULL, 0x3353AE9E922A7FCBULL, 0xA003CE6D34779252ULL, 0x2906E42374D41DF7ULL, 
            0x1D86C0163061E1D1ULL, 0xAFF65B70FB2A2BFDULL, 0x7903E655C902C861ULL, 0xF8046864322DC80EULL, 
            0x135ECBB60D1E51BBULL, 0x62A168BE1194EC8AULL, 0x8CD89A27455CA90DULL, 0xD4E755E815B8F8DCULL, 
            0x93009A5E1BA21823ULL, 0x354CD5B4C24323D7ULL, 0xF9AB55660D105B4BULL, 0x2411B88F02233201ULL, 
            0x33C2CE14F9DC191CULL, 0xF97B6221A4A91488ULL, 0x48FF324265195ADCULL, 0x44B37C7FB959AFB1ULL
        }
    },
    {
        {
            0xDCF6CBDA8965FEB4ULL, 0x807EDD3A47739864ULL, 0xF6C3C8059B1E31C5ULL, 0xF2D49473E98F2E35ULL, 
            0xF119A0F7BE57046BULL, 0x8014ED40B3C1485DULL, 0x3DCBFE4B074B7200ULL, 0xE6868BC62D9C83E4ULL, 
            0x37E5B5E39775F920ULL, 0xD47F70E0EF1B7AB4ULL, 0x9A83BC13BF139CF9ULL, 0xC7DF7868F801CC9AULL, 
            0x5336CA1319E436CEULL, 0xE630C45A09B079E4ULL, 0x4D834CB51AEA2830ULL, 0x36229484782A0EBFULL, 
            0xBB387A46D4FF406BULL, 0x2C996478D61E4EDFULL, 0x7E5BFE5093C70C87ULL, 0xA88B410E895FFDC5ULL, 
            0x32516C932F77E2DFULL, 0x3197BFF9680EF105ULL, 0x845ACEB2326EBA6CULL, 0x66B0E40DFCDE68F4ULL, 
            0x18FEF1F667BEE36DULL, 0x58B9E2AF8E9DDDC6ULL, 0x72919DF8D4318EE3ULL, 0x65568972ACF27B83ULL, 
            0x03B5D29A45C2C13AULL, 0x572C8AC5A74A7072ULL, 0x81939008A502E23EULL, 0xA35F43F7C8627AC1ULL
        },
        {
            0xF303BCDCC0FFF4CFULL, 0x689878D87BB407D4ULL, 0xA817BB430B3BA292ULL, 0x1A08415B2086188EULL, 
            0x2474415AFDA46350ULL, 0x05AE22740825507AULL, 0x78578BA24AA6EB33ULL, 0xBF88C74A6D047E2CULL, 
            0x8A35B1B67E806048ULL, 0x037B52224CC600D2ULL, 0xA48E97A95F656DA9ULL, 0x47F0848A8DA1F792ULL, 
            0x037B6EFFEB3D85F7ULL, 0x058020C495271B96ULL, 0xEBB47D47C4B0D0AFULL, 0x51D612AC0BE8F692ULL, 
            0xBDED3CC9DA6C3BE2ULL, 0x8424D497961AC7F2ULL, 0x44CB95EC9ECFDDD3ULL, 0xCB2E22FCBA829077ULL, 
            0xCBF65ED945193596ULL, 0xFFDE529F04E34CFBULL, 0x9CDA65F83461CB84ULL, 0x6DC21BB69F6CF4B3ULL, 
            0x3D4E4F3D69C8A363ULL, 0xF67754116A775BEEULL, 0x1F81BFBF16DAE5E5ULL, 0x70579031F2920637ULL, 
            0xE59C635493A52DF8ULL, 0x64B984C0A07869ACULL, 0x5AC2FE984366DDF9ULL, 0x4CF334674D428277ULL
        },
        {
            0xE1143C2A86ADD80DULL, 0x045624FC35100212ULL, 0x0E7114B795AC1640ULL, 0x0C937F9AE42DC27DULL, 
            0x680D0C29AB039203ULL, 0x107E95786BFDA608ULL, 0x8887FD427BB13FECULL, 0x1E6FB3956D1A7D93ULL, 
            0xB28A71C7D7B79AFDULL, 0x88FF48678E0E51A5ULL, 0x54248CFF6D00A734ULL, 0xBB026C9487915D41ULL, 
            0x857532CA3AD2A794ULL, 0xE5C3064BAD6D69DDULL, 0x89451E5C642C43CDULL, 0x08596846EE3C062EULL, 
            0xC5E620F126BFF666ULL, 0x18C30396DEB5FA5BULL, 0xD487270C8A9BD4FFULL, 0x1DFB7AFBA685E790ULL, 
            0xD610D1DB215AA82FULL, 0x68665AF4A82F3DB5ULL, 0x4561C41EC83CE05AULL, 0x6233735D0AF50D57ULL, 
            0xC5BF16068D554EE3ULL, 0x296283D342867369ULL, 0xCCC82F0BC5657804ULL, 0xB1A620E6BD76A5F7ULL, 
            0xC721642BE49A09D9ULL, 0x1A6DA971D8E83353ULL, 0x51BA370F63E6600FULL, 0xA8CCE80816AA2E29ULL
        },
        {
            0x65257AEE116F97A6ULL, 0x73CF370C4253FF67ULL, 0x01A66A088CDC7EBDULL, 0x0CD82AF739C4BF48ULL, 
            0x544BADD02621A903ULL, 0xC1506E8AE3234923ULL, 0x34DCFFFF3F407B10ULL, 0x687CE860EFE5957EULL, 
            0xEAB986DD3202F160ULL, 0x4B6BA00FCB415994ULL, 0xB9E24B75C48980E7ULL, 0xAC051738AFC18934ULL, 
            0x21E0B4A934BDC693ULL, 0xD1F82FF70335DCB6ULL, 0x512265CD59D2ADE1ULL, 0x392FA059398BD7AEULL, 
            0xEC16A45C2D328E86ULL, 0x06894DCEF5ADF871ULL, 0xB4D5B34CDD8BCB63ULL, 0xF9A87E466BDD7513ULL, 
            0xF16015874355109EULL, 0xC831288121C87A02ULL, 0x7D529B0EB7F75909ULL, 0x6EEAE1A9C9E2C074ULL, 
            0xFB087C3E72BB460FULL, 0xC5355626941843B0ULL, 0xCF76178E8867F381ULL, 0xBB58BD8FE75FCBC6ULL, 
            0xC0329CA2771174A5ULL, 0x072ECDF6F7BB64CEULL, 0xD627049DA226C53EULL, 0x1B987C6BCC2A4D5FULL
        },
        {
            0x881E7115492334B4ULL, 0x8FB8236237947D1AULL, 0xE3AABC1812F4E489ULL, 0x747C9B1D030A6E3FULL, 
            0x307E44DAC6E6258BULL, 0x4D72369EC3293DBBULL, 0x028F1D6493B3886AULL, 0x43534EC13D51DA37ULL, 
            0x38D1E54BBDF899D8ULL, 0x4992D0A6E0488AF9ULL, 0x8C79B965D562F308ULL, 0x7410CF91366F8BA5ULL, 
            0x47395138B9631A97ULL, 0x307D0FA29A745E98ULL, 0x8E90A3AA7A70C397ULL, 0xFB4A9AEE9FE3FFD9ULL, 
            0x04682FD517A0A23CULL, 0x4477874530FB435BULL, 0xC6BC988F4FDD34B1ULL, 0xAB6E756A0BCFD6BEULL, 
            0xEA56C9971A943BCFULL, 0x0CF013D7BEF77711ULL, 0x3E364E4F9EC227D4ULL, 0x6D580813115F1091ULL, 
            0x5E892012B029F9C8ULL, 0x74CBB5F201241E97ULL, 0xF5B78943FB91AF57ULL, 0xA1A88FBB6483766CULL, 
            0x9C100CBBA7064336ULL, 0x039CA5335698DFC0ULL, 0xADFEBFA00113100FULL, 0x8A78871C1860274EULL
        },
        {
            0x549EEB0E6A5A693CULL, 0x0BE46A912843ACB0ULL, 0x626D817F4A1007DEULL, 0xBBB6743A7E37D8C7ULL, 
            0x078444766606EAD8ULL, 0xD076D4069E352032ULL, 0x0EB1C13D0331F75FULL, 0x1D198A69FDC93EEBULL, 
            0x494B7543981DA238ULL, 0x337E29126B8E9E70ULL, 0x92C62402FB222353ULL, 0x14078704B2CE21EAULL, 
            0xFEE670F49D5F30CAULL, 0x8B4B8A335CF6BB70ULL, 0xF0FB2CAE1626AA07ULL, 0x6D438AE924379416ULL, 
            0x8EA1B0BAC4510EE1ULL, 0x5A2D7612979CB1CCULL, 0xF245BB3AE5E1D578ULL, 0x4E674B2402078E1AULL, 
            0x4D05709FD1635D82ULL, 0xADAB0B8A162AAED0ULL, 0x21AD1AE8D22DB898ULL, 0xEA2917CDFD4E22BEULL, 
            0xFBB60D7888988F19ULL, 0xE47C0DAEEEB22949ULL, 0x95945555064922B7ULL, 0x602BD19F4408B69BULL, 
            0x80A907F190378EE6ULL, 0xA3258C6E8A73B35DULL, 0x94B5655E0A08D3C2ULL, 0xDAECE7D12140919BULL
        }
    },
    {
        {
            0x960BE196C7ABBF53ULL, 0x59F5ADE2D6230AE2ULL, 0xB90A558DB042A237ULL, 0xE6B4226A2A20FD66ULL, 
            0xF5E672E98FCD36CAULL, 0x9E8E0639985D7A4AULL, 0x0CF46734075E86FDULL, 0xE0EC1C5FB2FE0D5BULL, 
            0xB7AC3FA85365CB0EULL, 0x7EACBE7D20FCA0B7ULL, 0xAF04B53DE1315753ULL, 0x3A0E7B0CED7D5C94ULL, 
            0x5876CEB1C07716B4ULL, 0xEB937AEACF2DA502ULL, 0x3C2C61BCDC65667FULL, 0xA9A0AB69F78D1BE6ULL, 
            0xA237E2B22DF372EBULL, 0xBA3080067AD2F132ULL, 0x5C19EA9635419C94ULL, 0xC187569CE4ED58C5ULL, 
            0x95B741983ADA0618ULL, 0x3361F7947BE0980FULL, 0xEFE1CF7A3434474EULL, 0x8F100D774A97E1B5ULL, 
            0x0F19ECAD8FEBE341ULL, 0x6F2B3E6905B3BB61ULL, 0xBD499C89EF3882D7ULL, 0x6D76484D94025619ULL, 
            0xBFD20B27FEC7F4E6ULL, 0x3AFB8816E926CB09ULL, 0x908FFB4FC3603A1BULL, 0xAE53EA75D1F4C4EFULL
        },
        {
            0x0F1B874350F9C58DULL, 0xC07410193F83AC5BULL, 0x5068901EE86AFFB0ULL, 0x6891814AF5890BCFULL, 
            0x97D5BE83457DE38BULL, 0x7FD0E0F5F5C26A8CULL, 0xA461CE129D710B82ULL, 0x1F1A3384517DCF4BULL, 
            0xDA2005B91D064523ULL, 0xA30241768C5F931AULL, 0x5B89686B952A849EULL, 0x2DB70B78FA56951DULL, 
            0x75681AAAE6B81E20ULL, 0xE97961B02738D381ULL, 0x8573BD6D2626CE3EULL, 0x377468EAE98EBAB0ULL, 
            0x45BDFA9A364AACC4ULL, 0x1F48F3F8A81FF64EULL, 0x338D51CAA9742E13ULL, 0xDFD54E8C5E19BD81ULL, 
            0xFDD9CC0E0C7F013CULL, 0xA86AFAD581E530A9ULL, 0xA803BB8245580741ULL, 0x3C20308EE6C29C76ULL, 
            0x4C337458DE68249CULL, 0xB814F7F8FD01061DULL, 0xADE27B6194D89A48ULL, 0xC39C2920B7843EEBULL, 
            0xAE1DAB4A76B730DDULL, 0x43846C240FA27C16ULL, 0xAC969C1F3E600DC4ULL, 0xD433FFDDB858B449ULL
        },
        {
            0xE7FD78D7DB4E4AB7ULL, 0xCE0DB76C62F9ECC1ULL, 0x4B2EFBD703194818ULL, 0xC83C892540B385A7ULL, 
            0xD4A530167ABB86D7ULL, 0x4A2258D19EAFE002ULL, 0x72B1EB41954CEEABULL, 0xA9BDC332B21444F2ULL, 
            0xB7511A021266CEE5ULL, 0x70101174FFF7DEC5ULL, 0x881FCA288DC28FBAULL, 0xB48FD4E0F1A03745ULL, 
            0x353AA4C81C9E5F44ULL, 0x689C174963D8D364ULL, 0x1A0E518D34611411ULL, 0xC11DF54120D70707ULL, 
            0x2941AA18DD118CEDULL, 0xBBE2237153D0C5EEULL, 0x22109C697D709917ULL, 0x3A406C6D823BB487ULL, 
            0x36BC950DCE98F8AFULL, 0xB22420D325BD56A3ULL, 0x4AD09D9575053FCBULL, 0x774CC0A52DD6DA0AULL, 
            0x21487E7E1156BDFAULL, 0x357A75FB39E5D1CCULL, 0xEAF1412E6C549FE7ULL, 0x471A0F887D45132EULL, 
            0x7269A350346B54FFULL, 0x2AB1D7711E0A958CULL, 0x3FD8C66327FF28ADULL, 0xAF6FCDE063CAD039ULL
        },
        {
            0x3088B712F20F0680ULL, 0x0508047A0ADEA601ULL, 0xAE8EAC12CCA5C314ULL, 0x7A74C79912EDBD0AULL, 
            0xF6F652515C26CED6ULL, 0xD4DF7BA26CC37F0BULL, 0x9156DD6509D671EFULL, 0x9099A9656598472CULL, 
            0x9DAEB86C1AC74438ULL, 0x4877F060D7FA8B68ULL, 0x2B8A3ABC6404B15FULL, 0xD56FA25B4EF3916DULL, 
            0x233E6C00FB02A6BBULL, 0x7D8259AAA7434142ULL, 0x75A34E5901D9C37CULL, 0x24896A80359DC7B2ULL, 
            0x853B54F14EB244D6ULL, 0xEF1C4488A16CA435ULL, 0xBED636439453BC57ULL, 0xC886236E3AC65C49ULL, 
            0x8D5EC9DAD6E29BD3ULL, 0xCAD1F24FA77BC718ULL, 0x632341D176CD5350ULL, 0x3ADB936D9CCAE228ULL, 
            0xA2333AD69669D625ULL, 0x4B2DA63CA77FA1E3ULL, 0x5EE717B09373FE84ULL, 0x9F95A7BEB1732DC8ULL, 
            0xD70E238611952D3EULL, 0x663ABD5D3F8CDC61ULL, 0x2BEB7AE290ED82FFULL, 0x316F238AAECD3995ULL
        },
        {
            0x61DC48EE26A2BD38ULL, 0xA46AB040C7D078B0ULL, 0xA63356DBB789D8B5ULL, 0x4E4B9E9739185251ULL, 
            0xF7F133D4EB42C66EULL, 0xBE7A59114C1C0819ULL, 0x8B276F5052D28AE8ULL, 0x6E1FB10CEF7D6ACAULL, 
            0x8BFCA229017B2A65ULL, 0x601CDE160731DD30ULL, 0xFC5C1D2037197093ULL, 0x7F3195E2673D84ECULL, 
            0x166983ADC93E7DCFULL, 0xBC58AEB5D3D6946FULL, 0xDDC5488642ABF30CULL, 0xA0A644ACB9FC4FE2ULL, 
            0xF3D387F3A874673FULL, 0xB6FE69091B647B3EULL, 0xDE4DB22F7AFF3983ULL, 0xE2620903BF7619E7ULL, 
            0x2E56F4BFC24437B1ULL, 0xB6E0A6C69FBD9A7BULL, 0x1B24EF65EEFA1778ULL, 0xD9AAD312F9F20CC4ULL, 
            0x7EB866218668DDADULL, 0x2EA5AC5EBE4A412EULL, 0x4AC94F2336AE5772ULL, 0x68AA2DAF7FC22E6CULL, 
            0x1155C91B5BACA3B6ULL, 0x753A6AB2E5A6BC81ULL, 0x2DA627A3894D0F47ULL, 0xA1D4C06E5A710976ULL
        },
        {
            0x9C921C354C3EA6E2ULL, 0x94CC4228B0AE1E88ULL, 0x3EAB644807BD1216ULL, 0xA57B847F111968F3ULL, 
            0x4683E660FC00FC49ULL, 0xB9766A6CE58F1118ULL, 0x505D14AED00C60C9ULL, 0xFA72B27AB2190A7EULL, 
            0x1018D2897EB8D362ULL, 0xF2D15936F1AFA881ULL, 0x2D105966FD8F99DAULL, 0x87548DE7F2BB25ABULL, 
            0xE9E108473033BB22ULL, 0x16DEC76640B53C89ULL, 0xB1411D5D6516B111ULL, 0xA20CADB9D7095103ULL, 
            0x3726F197151A91CFULL, 0xE76D79DD3E565937ULL, 0x8B2F2599A4A3D27EULL, 0x05D7BCE80305588FULL, 
            0x81F9430973C9B53CULL, 0x8F09C9B14B51432EULL, 0x41AAEB6260F9F955ULL, 0x6B45ADDB7A352FB4ULL, 
            0x322DEE5EF1C1208DULL, 0xB05DC69C58A8416FULL, 0xCC15C5C8B24069A7ULL, 0x2FF986829CD00C4DULL, 
            0x851E3EFE299C6F03ULL, 0x29DABEC6616A4B8EULL, 0x62664B7BE3F419CCULL, 0xE65BF85D42238F58ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Sirius::kPhaseDConstants = {
    0xD7E1B6395A1931B0ULL,
    0x8A8DD61A41EF0653ULL,
    0x0F527A010AC0CBE0ULL,
    0xD7E1B6395A1931B0ULL,
    0x8A8DD61A41EF0653ULL,
    0x0F527A010AC0CBE0ULL,
    0xEFE27CC953FE2D4EULL,
    0x2B953EF4A0304C12ULL,
    0xF7,
    0x10,
    0x8F,
    0xB0,
    0x84,
    0x01,
    0x25,
    0x07
};

