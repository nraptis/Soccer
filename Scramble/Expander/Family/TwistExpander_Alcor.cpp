#include "TwistExpander_Alcor.hpp"
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

TwistExpander_Alcor::TwistExpander_Alcor()
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

void TwistExpander_Alcor::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x81C3C0FDEA1C818EULL; std::uint64_t aIngress = 0xC83718A9C5FA6E92ULL; std::uint64_t aCarry = 0x95A0289FDB32A4F5ULL;

    std::uint64_t aWandererA = 0xBEF3669E2BE4CB76ULL; std::uint64_t aWandererB = 0x8D710E8EFECA3A69ULL; std::uint64_t aWandererC = 0xFDE1C82BC9FD24D8ULL; std::uint64_t aWandererD = 0xEB387FE717E2D0F5ULL;
    std::uint64_t aWandererE = 0xE37913B667054705ULL; std::uint64_t aWandererF = 0xD61F6471D7394802ULL; std::uint64_t aWandererG = 0xB5B66E97B553BBEAULL; std::uint64_t aWandererH = 0xBD2A0981E5BF21D2ULL;
    std::uint64_t aWandererI = 0x827C48023E548D01ULL; std::uint64_t aWandererJ = 0x93B7554F35A7940BULL; std::uint64_t aWandererK = 0x9513B4A2441FF323ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x9F875485FAA53943ULL;
        aCarry = 0x8DDEF47D6533CB11ULL;
        aWandererA = 0xAD79F51D82FC3B7AULL;
        aWandererB = 0xAF73DB7F7C18E3B7ULL;
        aWandererC = 0x99F14037E7C8B22AULL;
        aWandererD = 0x990F51D44E6ADD95ULL;
        aWandererE = 0xD3624C6AE07DBD0DULL;
        aWandererF = 0xF1A4E49FADC7E9B0ULL;
        aWandererG = 0xB021002BC4CC6CE3ULL;
        aWandererH = 0x8926F80469A0DB3BULL;
        aWandererI = 0xCFD2D2F393886FB6ULL;
        aWandererJ = 0xC973A279374F8BA3ULL;
        aWandererK = 0xECEF0BB1DF1D27E8ULL;
    TwistExpander_Alcor_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Alcor_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Alcor_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Alcor_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Alcor::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA3C9578E20626F28ULL; std::uint64_t aIngress = 0xA9A7609A656CF365ULL; std::uint64_t aCarry = 0xDC7A068FF2076686ULL;

    std::uint64_t aWandererA = 0xCD4985664D804AA1ULL; std::uint64_t aWandererB = 0xDB69C25ADB84C360ULL; std::uint64_t aWandererC = 0xB6222F39F52F3CCEULL; std::uint64_t aWandererD = 0xF71B5AA8BECA42BAULL;
    std::uint64_t aWandererE = 0xB109F7FC3C189205ULL; std::uint64_t aWandererF = 0x8D080A0F88E55E89ULL; std::uint64_t aWandererG = 0x9C47BFE6C98F9704ULL; std::uint64_t aWandererH = 0xDC6B398574634161ULL;
    std::uint64_t aWandererI = 0x9968EA906C906E1AULL; std::uint64_t aWandererJ = 0xDC835A600B4FA537ULL; std::uint64_t aWandererK = 0xC743C069ABDCB5EBULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x97063A9DF8CDF2DDULL;
        aCarry = 0xC873364B60024941ULL;
        aWandererA = 0xE5963B1F87E65044ULL;
        aWandererB = 0xBEB8C7FD9171A307ULL;
        aWandererC = 0x89453458673FCE96ULL;
        aWandererD = 0xFD32B544190D16BBULL;
        aWandererE = 0xDB702899394D3680ULL;
        aWandererF = 0xF5172853234333D3ULL;
        aWandererG = 0xAF8CC77B53918889ULL;
        aWandererH = 0x8E2B1188530EFC0CULL;
        aWandererI = 0xB0388025CFF05A96ULL;
        aWandererJ = 0xF41C1EEE9172691EULL;
        aWandererK = 0xAFFB05C88EB0689FULL;
    TwistExpander_Alcor_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Alcor_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Alcor_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Alcor_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Alcor::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD9492622A2DE1C2AULL;
    std::uint64_t aIngress = 0xE1DAC94A33C35FC0ULL;
    std::uint64_t aCarry = 0xA8D13EDADEEE8A82ULL;

    std::uint64_t aWandererA = 0xD51097CAE58A088BULL;
    std::uint64_t aWandererB = 0x89B817C49F436E73ULL;
    std::uint64_t aWandererC = 0xE739864B711D5778ULL;
    std::uint64_t aWandererD = 0x8301BAD6FE315694ULL;
    std::uint64_t aWandererE = 0xFFDF80EDD87696CFULL;
    std::uint64_t aWandererF = 0xF6B063235009F620ULL;
    std::uint64_t aWandererG = 0xA416A2FC3741147DULL;
    std::uint64_t aWandererH = 0xA8CD559B129D3E03ULL;
    std::uint64_t aWandererI = 0xEAC0DD30791B81CAULL;
    std::uint64_t aWandererJ = 0xA2F9953AE27F12A1ULL;
    std::uint64_t aWandererK = 0xFE6D86F9673630C2ULL;

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
    TwistExpander_Alcor_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Alcor_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Alcor_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Alcor_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Alcor_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Alcor_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Alcor_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Alcor_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Alcor_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Alcor_Arx::GROW_B(pWorkSpace,
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

// SmartSquash candidate 2 of 33
// Exploration cases: 100000000
// Nearest-family diversity: 1088 / 1088 (100.00%)
// Total distance from earlier candidates: 1088
void TwistExpander_Alcor::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    static_assert((S_BLOCK / W_KEY) == 16, "SquashInvestToKeyBoxes expects 16 invest fragments.");
    static_assert(H_KEY == 8, "SquashInvestToKeyBoxes expects 8 key rows per box.");
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 0U), *aFragmentB = aIceLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 3U), *aFragmentD = aIceLaneD + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 754U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1518U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 853U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 797U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 1U), *aFragmentB = aIceLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 8U), *aFragmentD = aIceLaneD + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1955U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1560U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1917U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 122U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 9U), *aFragmentB = aIceLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 7U), *aFragmentD = aIceLaneD + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 407U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1698U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1035U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1736U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 8U), *aFragmentB = aIceLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 10U), *aFragmentD = aIceLaneD + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1314U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 612U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1490U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1431U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 7U), *aFragmentB = aIceLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 5U), *aFragmentD = aIceLaneD + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 974U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 178U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1693U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 620U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 13U), *aFragmentB = aIceLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 4U), *aFragmentD = aIceLaneD + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1485U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 861U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1048U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1379U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 10U), *aFragmentB = aIceLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 0U), *aFragmentD = aIceLaneD + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1045U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 494U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 294U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1645U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 5U), *aFragmentB = aIceLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 14U), *aFragmentD = aIceLaneD + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1623U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1691U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 466U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1830U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 11U), *aFragmentB = aIceLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 2U), *aFragmentD = aIceLaneD + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 173U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 471U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 335U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 359U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 4U), *aFragmentB = aIceLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 11U), *aFragmentD = aIceLaneD + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 632U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1529U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 791U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1289U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 14U), *aFragmentB = aIceLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 12U), *aFragmentD = aIceLaneD + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 668U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 73U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1891U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1760U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 15U), *aFragmentB = aIceLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 6U), *aFragmentD = aIceLaneD + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1771U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1489U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 194U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 2021U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 2U), *aFragmentB = aIceLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 13U), *aFragmentD = aIceLaneD + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1354U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 448U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1317U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1039U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 12U), *aFragmentB = aIceLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 9U), *aFragmentD = aIceLaneD + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1605U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 922U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 801U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 628U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 6U), *aFragmentB = aIceLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 1U), *aFragmentD = aIceLaneD + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1230U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 673U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 616U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1627U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 3U), *aFragmentB = aIceLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 15U), *aFragmentD = aIceLaneD + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1846U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 740U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 15U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1192U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Alcor::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA6A1995398FCCDD9ULL; std::uint64_t aIngress = 0xE81E46663FD9C768ULL; std::uint64_t aCarry = 0xAC100496834088FBULL;

    std::uint64_t aWandererA = 0x80FA4F110CDAC087ULL; std::uint64_t aWandererB = 0xF533109B7B85C123ULL; std::uint64_t aWandererC = 0xA464CC07027640E7ULL; std::uint64_t aWandererD = 0xDB22F76FA9EBC481ULL;
    std::uint64_t aWandererE = 0xF03A52CB0F622113ULL; std::uint64_t aWandererF = 0xD1E65D66622F94BDULL; std::uint64_t aWandererG = 0x9F65DDEA282623B9ULL; std::uint64_t aWandererH = 0xA4D1BB243749222EULL;
    std::uint64_t aWandererI = 0xE86C9ED21C3D308AULL; std::uint64_t aWandererJ = 0x986C45C2C48E9FB8ULL; std::uint64_t aWandererK = 0xEBAD2615E42D05AAULL;

    // [seed]
        aPrevious = 0xDBC39105DC2BEDE9ULL;
        aCarry = 0x8A0A325DBE035D73ULL;
        aWandererA = 0x8B7B0BB118A1E70AULL;
        aWandererB = 0xB4FC96947F406AE1ULL;
        aWandererC = 0x93D0744A5490D918ULL;
        aWandererD = 0xF4AEAFC591AE9C02ULL;
        aWandererE = 0xB0D305A2D3DBCFB1ULL;
        aWandererF = 0xA47D5BA19EAE7DE3ULL;
        aWandererG = 0x880394068BA56667ULL;
        aWandererH = 0xFE5725259EA78A52ULL;
        aWandererI = 0xD3F6498F260E46B5ULL;
        aWandererJ = 0x955930804C3EAC29ULL;
        aWandererK = 0x832A86554ABC1BC2ULL;
    TwistExpander_Alcor_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Alcor_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Alcor_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Alcor_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Alcor_Arx::Twist_E(pWorkSpace,
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
    TwistExpander_Alcor_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Alcor_Arx::GROW_B(pWorkSpace,
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

// GrowA candidate 2 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 668; nearest pair: 668 / 674
void TwistExpander_Alcor::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1662U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2619U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2123U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2650U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8025U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 450U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4007U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2361U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3798U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5991U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7477U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6356U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6174U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 697U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2614U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2832U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 571U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 613U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 916U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1401U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 789U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 223U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 988U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1827U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 148U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1340U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 261U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 954U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 784U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1647U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 687U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1558U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1206U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1391U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1135U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 296U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
}

// GrowB candidate 2 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 668; nearest pair: 668 / 674
void TwistExpander_Alcor::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 890U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5517U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6956U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6036U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 620U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 561U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6052U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 155U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7036U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8155U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2870U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4697U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4358U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 860U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5582U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 53U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1907U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1291U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1803U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 232U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1549U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1231U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1042U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 435U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 613U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1654U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 681U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 324U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1993U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1621U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1853U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 264U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1350U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 781U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1193U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1078U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
}

const TwistDomainSaltSet TwistExpander_Alcor::kPhaseASalts = {
    {
        {
            0x77D7BC4F01E48773ULL, 0x2EBFBDC0153650BAULL, 0xD2BF58D449474524ULL, 0x9044F116098DDEF3ULL, 
            0xA1F1243036029DC3ULL, 0x15B4484F6371EE6EULL, 0x8CC50BC0D3B594B1ULL, 0x8A8BA6CCE3CA898BULL, 
            0x75F0D260A44D9954ULL, 0x7968A4CD283CEC73ULL, 0x9B9F3196D05770BEULL, 0x25550B86E5D0C88FULL, 
            0x9EC234453FF31D4CULL, 0xBBCC4CF80891C78FULL, 0x124418D660511B33ULL, 0x9933AAC9F31A4FBCULL, 
            0x9529DD6A3B0F4E93ULL, 0x90B538BD30C122B7ULL, 0x91944BFCD757F05DULL, 0xCE55B00FF6B6FE25ULL, 
            0x1CAFC2E6CB3BA1B9ULL, 0x9A8DC33CBAA7DDD5ULL, 0x0215705F0BD3C3CBULL, 0x004591DE5252E216ULL, 
            0x4C6843E2B06463DAULL, 0x2BB323FC72D59B6AULL, 0xA609B41946501C91ULL, 0x12378B7D9FF44D50ULL, 
            0x734E1B8EE0B6D521ULL, 0xAB9B71CFA15F6491ULL, 0xCDF9380440E361E3ULL, 0x37AA7295A0C79B07ULL
        },
        {
            0xD0A1918960FC298FULL, 0xC8522C95545D6385ULL, 0x826AA9B7536BF5FDULL, 0x11CB8914983274A7ULL, 
            0x313F0ABBA5B07D5AULL, 0x5637FE1BCA830B34ULL, 0x770D549F54671CD9ULL, 0x9029F2E76B9C5B78ULL, 
            0x373D0B69002A0EACULL, 0xE95E9C4D78665D3EULL, 0x56835586FE0702F9ULL, 0xB7B10E5EE5F4163CULL, 
            0xAFE2A6C2E260F629ULL, 0xE6B6121904C5597EULL, 0x19EE58AAAE45AA8AULL, 0x1ED2248728A4473CULL, 
            0x4B3DC2C171343120ULL, 0x3A35D1B420B2A0FAULL, 0xEB9B5853E6C28ECFULL, 0x2D99B29601BF1DADULL, 
            0x4BC5FC0CE23B27E0ULL, 0x40C0E7DC450ED8B0ULL, 0x474594FE57A7461CULL, 0xEB10F6DA862EBA7CULL, 
            0x84E86523BD4B1F98ULL, 0x58C737A1C5D22602ULL, 0x13754C8E1092266CULL, 0xC861A1B94311DE26ULL, 
            0x2BF2B5507E3EECF3ULL, 0x34ED93C536DF6B1FULL, 0x1CED1FC4D7292F1CULL, 0xDE73C7B521C4258AULL
        },
        {
            0x6AB1A05CE651F752ULL, 0xAF25078B457E9EC5ULL, 0xDF70BC233989A8E8ULL, 0x29661E1EE0DC2C01ULL, 
            0x4CED4CFD6129F585ULL, 0xA6F75F3C49F10763ULL, 0xEEFB445D2A73D944ULL, 0xF639CF776CA30F06ULL, 
            0xD7F28E7B86216471ULL, 0xC9A87FBC7569E5F4ULL, 0x828E5C6563161F71ULL, 0x6FDB3B16F2948097ULL, 
            0x872E62D0580D46EDULL, 0x2331BE0042E70E0EULL, 0x626282C39033A3C4ULL, 0xD989B8D15F23E1BFULL, 
            0x9FF869859FF557E3ULL, 0x03686FACF031CD6EULL, 0x7A9FF2C17AB2BF10ULL, 0x7D6BEE11856C43CBULL, 
            0x742C47D32361C902ULL, 0x915B7AF41F1E00DAULL, 0xE24E6539B25186C1ULL, 0x82B628FDF63A7D69ULL, 
            0x38539DD06C3C2A67ULL, 0xC55C0B2BAF33CF7FULL, 0xB5856DC212E593C8ULL, 0x53645626DAAD97D1ULL, 
            0xC9B77A213EBFBF8DULL, 0x1BEDBCA98C24753DULL, 0x20E7B10B21D266C4ULL, 0xCFF882F6AF7FECB4ULL
        },
        {
            0x9879C72A84F4785BULL, 0xEEF18E1D1B811567ULL, 0x02329B56E7CBB9A8ULL, 0xE0EA727D86B57F24ULL, 
            0xB37F23B7D5B9DD3AULL, 0xBFF4F6095193D637ULL, 0xE91CB1117FF0A976ULL, 0xBF3487A8A20BED49ULL, 
            0xF163058C96912E1AULL, 0xA6AB4A3583091AB9ULL, 0x2F7AFA592628EBA4ULL, 0xA617934F06B284F2ULL, 
            0x747F024DDBF8C56DULL, 0x0EA4FA68230979ECULL, 0x3A2F252EB56C3607ULL, 0xF8486F186AAFEAFCULL, 
            0x460017E7408FE1CDULL, 0x9273F43EF6075F24ULL, 0xCE89E1971FC1074CULL, 0x234ADD24268B0E53ULL, 
            0xD1BC3C97C7DBCA01ULL, 0xD024E9A4C20EE74CULL, 0x8ADE3233184C3860ULL, 0xE0B64017A8DC0C31ULL, 
            0x9562EB68F7AE92C0ULL, 0x9ED4C2C1B9B7B39EULL, 0x7A56123E9FC03BFDULL, 0x1BF7C428BBA481A3ULL, 
            0xB0DA637FF9290657ULL, 0x596099D68F72C12BULL, 0xBD00574C09EA184CULL, 0x38C0E492A404791AULL
        },
        {
            0x7D3B8C1CACEAD8BDULL, 0xF14D016E5A00C066ULL, 0x14BBD9F5F6A5AE28ULL, 0xCC678EE0503A9096ULL, 
            0x2AD239B456012471ULL, 0x29D3572D93C454EFULL, 0x70AF50A3CC123445ULL, 0xA69F5484D874302EULL, 
            0x6A4FF6B654EFFC7AULL, 0xCD8EA16A789D2849ULL, 0x9F2AC8E7970978F3ULL, 0x2B625D53646B6D5DULL, 
            0x49DF085ED0A4E2B2ULL, 0xE215CFCB41600927ULL, 0x6525DA5D116E77D1ULL, 0x2D7DCE88807C95AEULL, 
            0x7A2BF9BE477E9C87ULL, 0xC47D61E25175478FULL, 0xE8B08FD93C85618CULL, 0xC2C8C52D312333B1ULL, 
            0x70337560E7649253ULL, 0x20A0900E1C024C6DULL, 0x10049FB1CF8FFFEEULL, 0x4A1E66451B561645ULL, 
            0xD4964E73B0A15DC3ULL, 0x78DB5DB9B4C9928DULL, 0x2EC0C0129EB8CC35ULL, 0xFD1780980EEAE7FEULL, 
            0x6AC93AEB49ED9AF1ULL, 0xBBF560885CA52AE1ULL, 0xBA633937C7917427ULL, 0xACE8817A4CA65EE0ULL
        },
        {
            0x5BD490B22F208DB5ULL, 0x5158BB33B65385BFULL, 0x6AE1041D85851FB2ULL, 0x5310E9166A765140ULL, 
            0xDCB7F9346794FE5DULL, 0x318438929CC0C789ULL, 0x9E0401B9B83821F6ULL, 0x4151F3C320C21BB3ULL, 
            0xE7E8C6D0F1B72AA8ULL, 0x969A36A9ADB4737BULL, 0x00019C5469D378B3ULL, 0x89FDD3C10C34D527ULL, 
            0x30CB7312C2E1F8E0ULL, 0x6F74E46E87074A58ULL, 0x602F034DBD17DFD0ULL, 0x960DF38D1D24A629ULL, 
            0x5A8044B3571518DEULL, 0x949F5230C5DB7617ULL, 0x8E705D67BB588C38ULL, 0x1792E68937DB5AFDULL, 
            0x71EA486FE4F28C87ULL, 0x3539321D1BB4BDBEULL, 0xE1268F728EC584DEULL, 0xA6BE2CA87C8B2FB1ULL, 
            0x929A6C732BB61FC0ULL, 0x0BF9B6E4696FAB1DULL, 0xC9BF4F7F14ED0B6DULL, 0xDEE99C1F39124480ULL, 
            0x4CA67BFB117B0C3AULL, 0x910C7D3EEFA465B2ULL, 0x2FF4CB878DE3BEADULL, 0x92F57CA4D95FE297ULL
        }
    },
    {
        {
            0xD8D316D3A302FAA5ULL, 0x80DCA3B95A8DBFD2ULL, 0xE0B03815DBB54B41ULL, 0x083EADD0B094E692ULL, 
            0xD820396E55553C2CULL, 0x2C6A496A0D54AB2BULL, 0x84B065B95DEE92B1ULL, 0x2996C9F8066D6C48ULL, 
            0x30C384AA9BADAC23ULL, 0x89C0571E29172804ULL, 0x254D58C689A1C005ULL, 0x71067003C3034E62ULL, 
            0x084FB6AA18A4AD2FULL, 0xB69FF9FE52277DAEULL, 0x4943FE35574CB7DAULL, 0x5CA0ADF1E3F3253AULL, 
            0x8AA82AC39822AF7FULL, 0xE4BA12F5FC48400FULL, 0x5A086D790F8AE2BBULL, 0x14C63045CD37618DULL, 
            0xDE66691F6719A1CAULL, 0xCF94CB7537FDAA4EULL, 0xC809722EF30AF9D8ULL, 0x5A9BE5C595D1C036ULL, 
            0x3763914752A53BB0ULL, 0x340EB1CA811293C7ULL, 0x55C077D5F99F2732ULL, 0x44CDA05CDE4DB36BULL, 
            0x2FA5A7439144A9B2ULL, 0x9891314551994493ULL, 0x5D3B0ABDDFC12611ULL, 0x86B2D39FB8378503ULL
        },
        {
            0x9E3350B118ADF6EBULL, 0xA9D80BCA7D546D0BULL, 0x9A82DCFCF9DC46F4ULL, 0xD0E0C7F084A8B822ULL, 
            0x871287F7F29FD029ULL, 0xAF3CF3B025187BA1ULL, 0x407DB882C219A624ULL, 0x7C78EDD49C754F43ULL, 
            0x7E7B531A79026E3DULL, 0x0528E3BE54565AE5ULL, 0x5E75786CA35D8280ULL, 0x23F6F2ACD1865BAFULL, 
            0x665EAC99A9D68F80ULL, 0xC3B6E57379E668B7ULL, 0xEDA0FF3375B8F399ULL, 0xCB2B733B66BCCDF4ULL, 
            0x0AE0F2FAB12E30C4ULL, 0x83E3D5628427219BULL, 0x317C12CEA0D5F86AULL, 0x894DFF027ADE1D53ULL, 
            0x5DC0B96DAAFA40D6ULL, 0x670765DDEA53C75EULL, 0x653F541457F6B7D9ULL, 0xECF950D1BAE293E7ULL, 
            0x22B93B80260E7B5CULL, 0x95118117CAF4DCFFULL, 0xAEA64B93A30F9EF9ULL, 0x8B7C685B08BDEEA6ULL, 
            0x9436768B85787F00ULL, 0x9E787CB36787CD1DULL, 0x96BEA1478979F103ULL, 0x6B41E6D907B91F38ULL
        },
        {
            0x691E66909FE98C85ULL, 0xE93020F819E22C9EULL, 0x62656F1B14AC2D33ULL, 0x79EA7D6C416A01A4ULL, 
            0x5E4134E33509ED7DULL, 0x4D4A92211447EF43ULL, 0x892A68537A4216AFULL, 0x8FD04FBC4957982BULL, 
            0xE7F76D678F329A82ULL, 0x976E2A66072E2EC2ULL, 0x2B60F1D88227CB17ULL, 0xFE30F7C2A7599F7AULL, 
            0x4ECB1BF4AE026C62ULL, 0xB825E7CBA89DD748ULL, 0xBCD7ECD5D20ADCA9ULL, 0xD256E2A0228E261FULL, 
            0x8E14552E2064F77EULL, 0x6143F28BA1F34CF7ULL, 0x314D6B794A02AC6FULL, 0x63648BDD802DC40FULL, 
            0x3CEFE9DCED5F1526ULL, 0xF77D909C1DB2B9FDULL, 0xB527964BFF4DF8B5ULL, 0x0FF3EC26CF25809CULL, 
            0x3EEEBB6104F22A5AULL, 0xBE857812E5B23ADFULL, 0xB546249569D89990ULL, 0x90F812567B8B4FA0ULL, 
            0xD49D508EA476D252ULL, 0x6DF0F3F948955F8BULL, 0x21729DA063DF410AULL, 0xE9B0E512F7B04FBCULL
        },
        {
            0x66ACB08A70954220ULL, 0xBCB7037374D10EC7ULL, 0xF6264FE0AE6728B4ULL, 0xA9469F3672083F23ULL, 
            0x938E1F4341E188AFULL, 0xC1892C70638F0989ULL, 0x5A1277EAB601CEB8ULL, 0x4D89F29C7C5EE629ULL, 
            0x4BE8842BF6E9B81DULL, 0xF7F4098BAE7513E1ULL, 0x95B1E7818FE86969ULL, 0xEDDF0A0DC5D6AF1EULL, 
            0x237FF8C60B0FACC9ULL, 0x71872BB5CD3065AFULL, 0x9BF54611CACA3A86ULL, 0x363852EE67AA9F2AULL, 
            0x65E9799351491FDAULL, 0xEBEC3D57AF90299AULL, 0x14569A31A9BD538FULL, 0x7334442240D6BCB5ULL, 
            0x1741D049C68840F6ULL, 0x74290CD7BA26BE9DULL, 0x61D64B10561AE33BULL, 0xDC5010939CCB3F4CULL, 
            0x2145B91164BAB472ULL, 0xCA07B2FB3E744051ULL, 0x51A087E0CA9880FBULL, 0x6A6443FBA9BF266DULL, 
            0x4E9C3AE538FBD158ULL, 0xFCB49630B54E6E2FULL, 0xCE47E52DCC4F9BBFULL, 0x0F75164542975ACCULL
        },
        {
            0x5EA45844ED86FA74ULL, 0xA9FAFC088ADF6CE1ULL, 0x33BC34FFBC31B928ULL, 0x7F9C0392E1A0125FULL, 
            0xC125EC3B264CE1CEULL, 0xA4BAB8302ECFDA25ULL, 0xE2ECA336CA1A1407ULL, 0xF08DBD5998720E31ULL, 
            0x2CB65C0BBC54C8F8ULL, 0xA58DF47918FFC9A5ULL, 0x3708F11D4D76C2D0ULL, 0xA4118FD17091FF10ULL, 
            0x9468246B84920C8FULL, 0x0BBC03419156F511ULL, 0x79172AFA0FFAF8B4ULL, 0x3623F6E9918EEF52ULL, 
            0x2FDEC6B0BB1DDF1EULL, 0x9B7D26B2CB09330AULL, 0x7F77B3907935232AULL, 0x2436BC4380EF4571ULL, 
            0x620C62F3337BA6B6ULL, 0xDEBB1FAA32DCA3C6ULL, 0x461B2A34EA3E206DULL, 0x64B8A2CE9C49BA76ULL, 
            0x7F4509BE25D67BEEULL, 0x7B5F59DF6B51F200ULL, 0x2D6D1ED0F7ADEA6AULL, 0x9B19F3F96A88AE25ULL, 
            0x825FF02FF9382FE9ULL, 0x6BD00E46C11DA085ULL, 0x9D5BD57D60AA365FULL, 0xC75F42FA148C8657ULL
        },
        {
            0xE90516226500E80AULL, 0x7B58911644982F5CULL, 0x638E479DFB9886FDULL, 0x350607667EA36AB4ULL, 
            0x186826511ED6D89AULL, 0x2D5852AB85874CA0ULL, 0xB584DEA54E3AE43DULL, 0x7621DC49F8AEC20FULL, 
            0x42B9F55BA4875161ULL, 0x20749E70C383F09DULL, 0xC6D971DE9C9AE355ULL, 0x529549F598F4628BULL, 
            0x04CC02C1FC096348ULL, 0x109328DE5BB8A97AULL, 0xBA8F8DCC74A5603EULL, 0x961CBAEF5B37D801ULL, 
            0x425BFFDA23B787C7ULL, 0xFE82ECA216E9AABAULL, 0xDF7F9944FD83584AULL, 0x0896BF3BA8FFB320ULL, 
            0x348F2A85A0FCD14AULL, 0x4C968282D6EA8C79ULL, 0x38CD9D8E8A3C338FULL, 0xAB28F89A8BECBC59ULL, 
            0x412EB4380EC024CCULL, 0x134DE8E04EACAAE2ULL, 0x70298AB5AF8E88C1ULL, 0xC174B0D2A1461371ULL, 
            0x957D413B6853AE31ULL, 0xD7771B1C9A950135ULL, 0x6EBA50B6924A3165ULL, 0x5EBA1473FF2621FEULL
        }
    },
    {
        {
            0x8AB22A46EA3D77E9ULL, 0xAF5409E3311613F6ULL, 0xBF2D1E42D7447189ULL, 0xEC21268AC83D2919ULL, 
            0x3BADF8E83EA5C5C0ULL, 0x7AE8A1D3A67BC64AULL, 0x3C2853260B821A49ULL, 0x7A55C4DBFB988219ULL, 
            0x7C7772AEAE8681B2ULL, 0x2E21DCA33EA61650ULL, 0x04B1EFF849D6430FULL, 0x228F2F9E63AF8B0AULL, 
            0x6950EE1E919D44ACULL, 0x0D1449E2C622C886ULL, 0x3605860C4BC035E2ULL, 0x98C00D07C0908CE8ULL, 
            0x4B4D36ADEBA99D82ULL, 0xCF0ABC5BBCC4EB31ULL, 0x683783AD4F633BC6ULL, 0x71468CEC1C984B31ULL, 
            0x39F83DC4C5BD6C11ULL, 0x1EA12B4F1721E346ULL, 0xB99C043FC330824FULL, 0xE3EFD6E63C7F9386ULL, 
            0xBC932EBC84518419ULL, 0x8D471E1C5A8B1DB4ULL, 0x7F7DCE2E8D4AD36BULL, 0xC8E526FFA9B5B8F9ULL, 
            0x9EEAC8054BBB555AULL, 0xA8331886FBC0869FULL, 0x7EBAFD8EABAF3AEFULL, 0xFB949E402E68BEEAULL
        },
        {
            0xFBA4971B1F43B05FULL, 0x2BD207E46A6B02EDULL, 0x242625713A4B270EULL, 0x7F4281B82117716CULL, 
            0x5C26D70E4FD19F35ULL, 0xCBA2C2F564C39665ULL, 0xEB1D03C2128BBB4BULL, 0x005E4F056F332D2CULL, 
            0x7C99A02CEE1627D3ULL, 0x3865941FB16814A1ULL, 0xEA55AB5EB39B0B21ULL, 0x5F5499B37B0F761AULL, 
            0x64A154D9E23A57D6ULL, 0xB55424366DE0BB46ULL, 0x5F734665B00A68E7ULL, 0x1011ADDB3CBC84ECULL, 
            0x0E4C989F198E16E4ULL, 0xCBBFB9DF83F457ECULL, 0x41435521EB16B33CULL, 0x0406ADADA8F0E118ULL, 
            0xA60AA637C63CDE6DULL, 0x9019ABA17270F404ULL, 0xBB787CB76AF1DF6BULL, 0xD160F923B32D2374ULL, 
            0x75BF01C890C7AEB8ULL, 0xB561E269FB76DFEEULL, 0xFDA72045C9D35C44ULL, 0x090EA9AEF5775C5EULL, 
            0xB03FC0C9EDA36E30ULL, 0xE6650D967906C3CFULL, 0x4EA15F1323EA2DF2ULL, 0x2B9455B126141C81ULL
        },
        {
            0x6A8772CAAA855DCDULL, 0xC7C64D9A435FE4EFULL, 0x76C0F37369C929D3ULL, 0x52E1E470CE2FE2D6ULL, 
            0x5DC4016EF0A47AD0ULL, 0xDCDAC1348429F362ULL, 0xF3CE511D1F5DD0CBULL, 0x0B108B9FA88DD59EULL, 
            0x3250BDCBAF36359DULL, 0x35C6508B62AEBCCEULL, 0x69C9277665030E88ULL, 0xC6BDA863042B6EC1ULL, 
            0xA47E43B9245BA084ULL, 0xA13065D15A931485ULL, 0x1BC9507F402AD805ULL, 0x1D2EADD79B190049ULL, 
            0x2DA947E7B2972948ULL, 0x3DF46EEEA0757BB7ULL, 0x5E29F0350086F1A7ULL, 0x08BE99D0024AA668ULL, 
            0x63FB45D2D3691FCFULL, 0x0FC23E83F053CB99ULL, 0xDCA41C14A0B5D37AULL, 0x946C0B2D16F1E1E8ULL, 
            0xF4E7B2FB17CA8573ULL, 0xD8A27CDA3DC0D93BULL, 0xB0765D739A87FC23ULL, 0xF7836D39C044BF45ULL, 
            0x593F8362D2ED4CE9ULL, 0x05C2EACE3DF1665AULL, 0x07844B49F0946063ULL, 0x0180B49C8CB8CBC3ULL
        },
        {
            0x0BDA6CFFBB1DC522ULL, 0xFFD936AEC323869EULL, 0x2A4256DC48BB8C74ULL, 0x8331AEF273C0EF99ULL, 
            0xFCAF7A8E1F112A34ULL, 0xAAEB27097BB46581ULL, 0x91588D5EA56BF57EULL, 0x940A2D76D482AA1FULL, 
            0x5BB3AD56A321039BULL, 0xE9F8211819508526ULL, 0xBBBABAAD137A7997ULL, 0xD2105067E21FF183ULL, 
            0x03CB6E4FDC202F3AULL, 0x8A6705FE3771FEF7ULL, 0x3D715F50E82EA2FAULL, 0x898EF11B8E01D840ULL, 
            0x8081BFC098A41A0FULL, 0xB1D40AD1BCF69939ULL, 0x4B10D46A3011AAFAULL, 0xB052461D75042076ULL, 
            0xA234085CDB09301CULL, 0xFBC4F87E494A0770ULL, 0xB0BCC19316E0F270ULL, 0xB494466F57B46079ULL, 
            0xAEB7C27701CDB3F7ULL, 0x615F4D1435DB2039ULL, 0x8EB028FD8A56FFE4ULL, 0xDFB9F49AC7AE9829ULL, 
            0xFD07E8409B6DB2ECULL, 0xF4A94F41C393254AULL, 0x0FAC11A9D347E660ULL, 0x057B80A48823C82EULL
        },
        {
            0x389A35586C9C66D1ULL, 0x58793FA027779D48ULL, 0xF7599734F5C8E405ULL, 0x423F4A56D9A3E08BULL, 
            0x1F24E2CD660CE516ULL, 0x0986865A895D4465ULL, 0x4652B7167E2D4121ULL, 0xF8232D833A213DE4ULL, 
            0x65876FE5B2C3E90DULL, 0x5807ED4083E13382ULL, 0x45B8A338D4A5DE03ULL, 0xB4E06318218D18FDULL, 
            0x2A1916BB5FD62C3FULL, 0x4362125CF48F70D6ULL, 0x7055B1CC145F62BBULL, 0x9B465A8E2EC1A7D1ULL, 
            0xA8C5BE77EC9CD2E7ULL, 0x8D3352B900279B12ULL, 0xD54DA3CC7CDBA6C8ULL, 0x104BBCAC33E89C7BULL, 
            0xEB2C236710E6A396ULL, 0x64F3DA75E52B28AEULL, 0xE228777EA9E09585ULL, 0x75C2A7E4C0CA4AB9ULL, 
            0x15FB03716A817B1AULL, 0x7AEBFC64D58799D2ULL, 0xF34EBAFFF92747D3ULL, 0xF71DBEF24EE9CBAAULL, 
            0xE88A2A06A17AABD3ULL, 0xAAC07CC5BACB8A0DULL, 0x4E6AB2D5E0F24A03ULL, 0x7EB08F9938016F33ULL
        },
        {
            0x2ADEA236A420C914ULL, 0xD2579F0F024026CDULL, 0x93259B122BFEBD07ULL, 0xEC70930825084E8DULL, 
            0x9AC1E1C008724C2AULL, 0x14CC076950BE24DDULL, 0x632C408B845995E5ULL, 0xE5A0B9D61C63320DULL, 
            0x0AED9F806F460FCCULL, 0x711B95B10CE85932ULL, 0x57443F6DF20648B0ULL, 0xA3A4FF5AA59EE0BCULL, 
            0x564468CD2606C5E5ULL, 0x2D40735816534567ULL, 0xB55413777FE0822BULL, 0xCAD72FE5AC42AFDEULL, 
            0xF99AF1C58393A75CULL, 0xA9C4F678619C2480ULL, 0x5E35D7C1570A9073ULL, 0xE6FC3DB912A401CCULL, 
            0x0279F0518827C2A5ULL, 0x8571F82DEFD27B22ULL, 0x143E3E474AD2665BULL, 0x8155DFE457F5CE69ULL, 
            0xAD8BB2BF2B4AA6D6ULL, 0x2326ACCF1442B974ULL, 0xCC37379F3DB6E5ACULL, 0x4D0AE0C3B31FD39AULL, 
            0xF16235D9D45F5006ULL, 0x60F9C6687D22577FULL, 0x57D7004B7A4BC114ULL, 0xBFD0848B426C0FE2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alcor::kPhaseAConstants = {
    0x890185C41A9A3F03ULL,
    0xA4B8E37053C2A6AEULL,
    0xE9542A8A59B24430ULL,
    0x890185C41A9A3F03ULL,
    0xA4B8E37053C2A6AEULL,
    0xE9542A8A59B24430ULL,
    0xA68738128E69115BULL,
    0x265FAAF6304D9CFFULL,
    0xBD,
    0x15,
    0xE0,
    0xFB,
    0x04,
    0x76,
    0x42,
    0x4C
};

const TwistDomainSaltSet TwistExpander_Alcor::kPhaseBSalts = {
    {
        {
            0x5E20C602A1BCC09EULL, 0xE9B60349FAA55E2AULL, 0xA0214F9D35DCB85AULL, 0xF24401027705C1EDULL, 
            0x26D6A54DE9F1208FULL, 0x413A50D35168111EULL, 0xFBEA749F2378D215ULL, 0xCA9BE8DBF39AC6CCULL, 
            0xA54F39FC932C611EULL, 0x401ED0978DD310B1ULL, 0x865AAE21E0E4C6E5ULL, 0x1A966EA4630E139BULL, 
            0xB107B933A3C90DBEULL, 0xE735CA5E55F7DC6CULL, 0x54176CB5B3CBC2BFULL, 0xB889FF073DE1491FULL, 
            0xE433EE2227761197ULL, 0xD00592507796E283ULL, 0x80D706E9B4A3FA18ULL, 0xBEF83D2F021758BFULL, 
            0x9EF89A39306F7A2AULL, 0x4F8F9EBB002AA94CULL, 0x3E6DDD2CB6702F60ULL, 0x399520B394F4E4C3ULL, 
            0x535107B15BBD22BBULL, 0xAF333419A7B68CA3ULL, 0x7BBC113C2DFDB037ULL, 0x48BD9BF2564C7902ULL, 
            0xB3E131D7C6F1AF3EULL, 0xE04CB0DF09E9E8A1ULL, 0x791414C14C1DB197ULL, 0xA109A483CD089AA9ULL
        },
        {
            0x4EAF7DFA1A96B64BULL, 0xDC78AE69D023D8CCULL, 0xD13B5C3BA48DB09BULL, 0xDFA633086DF396BCULL, 
            0x8CA86CC486F6F83EULL, 0x776D17343C2FB430ULL, 0xF24572C7D21D4B99ULL, 0x30002CB303F3EAF0ULL, 
            0xEBA78397FC86BBE0ULL, 0x04257A1DCA67346CULL, 0xE8BEC87F98467D1BULL, 0x736F05ED4B5C5F24ULL, 
            0x68EB5D1F6C5D053AULL, 0xE3EF916E9E975085ULL, 0x65BA8208BD8A02E5ULL, 0x2D006F622F971441ULL, 
            0x076C33EE34C46962ULL, 0x4BF3270EE32C16A8ULL, 0x9E62D68AD1EB230DULL, 0x809D7F7D8CD504D6ULL, 
            0x6A4C538A11CA6B93ULL, 0xAFD64E31A284F2CBULL, 0x69FD788F088650F1ULL, 0x931DBD09D2317975ULL, 
            0x796F3984DB690118ULL, 0x57074903D5021047ULL, 0x91E90F898CE2E228ULL, 0x78F718E68BADA6DAULL, 
            0x717476BE86AD3162ULL, 0x82679B82EEC3522EULL, 0x7D19C923E72C4118ULL, 0x75126CC9DFFD9825ULL
        },
        {
            0xB58F2A803878FB9CULL, 0x2C8070DA30E5DF76ULL, 0xCA8A04254BAD4DBAULL, 0xB259A792A2203134ULL, 
            0x133967B3BA022019ULL, 0x20AD823BFCB00EB6ULL, 0x87F8CD99DA1EE0CFULL, 0x99F978244A14E981ULL, 
            0xEB4C46B255B0B5BFULL, 0xA1A1F41A1066DF02ULL, 0x686F7B7B8948ECC1ULL, 0xA75C609417A30317ULL, 
            0x16B746B61D3223C8ULL, 0x414C067B73C9628AULL, 0xD9E0EAD18764F0A4ULL, 0x690E7C953BC47869ULL, 
            0xB5FA8081B098D744ULL, 0x70041192257A7E7BULL, 0x295FB4710224E780ULL, 0x310995DCDAA52FFDULL, 
            0x16ECFD0E538A1AEBULL, 0xB3223B7CC0F885DCULL, 0x14382DD53CA90336ULL, 0xE7C544649A9AE591ULL, 
            0x629F08804D97633DULL, 0xDB6C6ADAE3CDAB0AULL, 0xDFFB38B227330BD0ULL, 0x4CEAF03893CC00EBULL, 
            0x41FF999244AB7670ULL, 0x078A4FF0E7E88EE3ULL, 0x7846B4ECF9916289ULL, 0x59E4CD06319A886CULL
        },
        {
            0xF76A7FA35946B0C9ULL, 0x31A80B167D52C47AULL, 0xACCEA9381BC5AEC3ULL, 0xF297CF9DE1A2F4C2ULL, 
            0xED59E0EC081FD530ULL, 0xAC3740F4333FD323ULL, 0x6C967AABB6D085E6ULL, 0xA3835F7F7E43DE95ULL, 
            0xB9BB1B5F83C39698ULL, 0x8B3396D4E870ED52ULL, 0x6ADDAC0639BE5355ULL, 0xD4F7FB32309DC147ULL, 
            0xF31C8E6D157738D7ULL, 0x707917C8F5541735ULL, 0x83340F80F7DEEBADULL, 0x0C189C7A9CCA4336ULL, 
            0x1479EA04F1C0353AULL, 0x3EF8DE1C23D28BC7ULL, 0xB593269DEB1BDD0DULL, 0xEB8DADE463764137ULL, 
            0xDBA8E76B11DD1E46ULL, 0xC740C1C2C6E139FAULL, 0x54FFEEC496AF5383ULL, 0x4E4727E1CBFD56EEULL, 
            0x764C931707384E55ULL, 0x3C6044C78721186CULL, 0x2C42D9F685A6E408ULL, 0x136702E20D4DA360ULL, 
            0x0C20CACEAD3F34B2ULL, 0xEED9A218912FA20AULL, 0x321A63A1118E9F93ULL, 0x0C7DF580FE73B41EULL
        },
        {
            0xD691A29CB004B107ULL, 0x58259640390506D7ULL, 0x6D0A13CB57626741ULL, 0x08DCBC6E1FA42186ULL, 
            0x9BF198A2DA7E9644ULL, 0x3D95C3802208F621ULL, 0xC7005F4B8A4564E0ULL, 0xF772D77CD12465BBULL, 
            0x2C2E45C26A060E5EULL, 0xC7BA60C5AC7FF364ULL, 0x5D6DF37BCC83BD4DULL, 0x33FD55F744952B0AULL, 
            0xC0C8C141B47CC978ULL, 0xCBC881FE9C39DB8CULL, 0x66EEB2F4992873B8ULL, 0x4C284F688CAC70BAULL, 
            0x43BC9888EB327561ULL, 0x8F3FF278DA625F43ULL, 0x0419C76A93EAD14BULL, 0x4DADAE5F9CF0B9F3ULL, 
            0xF1DE772650062A69ULL, 0x252C975D601052F7ULL, 0x12E068B5F6A7E054ULL, 0xD776CA186789ED56ULL, 
            0xEA3CFD88C7737DB2ULL, 0xDDCB0FE229CD33B1ULL, 0x24723A1C159B64E8ULL, 0x61EBAEEAE16B3C6BULL, 
            0xC2D13834B1B70BCAULL, 0x209118807B7925EAULL, 0x9FFFD7FB876C50A4ULL, 0x95BA7A49BA7C455CULL
        },
        {
            0xAF82B363F341FE3AULL, 0x08801F7A9E2D6427ULL, 0xFF2256CF1C1C5762ULL, 0xA125AE34F50F2C47ULL, 
            0xF2FBCF0CAA4DB656ULL, 0x5407FFB30E8D10A4ULL, 0x807843F0F00267A2ULL, 0x172E702F64F86C2EULL, 
            0xB0EA2383D71333F8ULL, 0x3D1DDF0FBEF03C87ULL, 0xBB7D4C421EF2E0FAULL, 0xCF6ED3567395D122ULL, 
            0x24F8519957F0A088ULL, 0xAA6FDCF0DB292FFEULL, 0x3E33A089E8F7220AULL, 0x1021F35BD481B51DULL, 
            0x3D114C54A7127D24ULL, 0xA740E235ED8A506AULL, 0x3552EC63AEFECC39ULL, 0x3EE630A8509618DDULL, 
            0x7A40C2C1A87FFAF6ULL, 0xCD1A69DABEA24858ULL, 0x3C43D4C5B8BE4229ULL, 0x373ADD1C6F6568CAULL, 
            0x7695FAFA0BBD5E6EULL, 0x609FA835AE99AC8CULL, 0x877C4046D6910C68ULL, 0x2D1AE12AE9EB76E5ULL, 
            0xD7E8E0F103B22908ULL, 0x2CC8BEA0EE9CA4E8ULL, 0xC6227A114D5EE4CCULL, 0x21778B331E1920A9ULL
        }
    },
    {
        {
            0x0E14E4BB377E3753ULL, 0xB9E4BC648F2008E3ULL, 0x42F2F266D6599E70ULL, 0xA653FE320C33FFA8ULL, 
            0x1618BDC067F0456BULL, 0xB46E3BA74B477A8BULL, 0xA102E6066B2AA5C2ULL, 0xE2E91A8BD1EB4990ULL, 
            0xA55545DFC0345A20ULL, 0xD37A09888BB374CEULL, 0xFD1E81F27AA2519BULL, 0x3EF8F4A733E27C49ULL, 
            0x1F1BC7B153398F0CULL, 0x0011F94A9899FB8EULL, 0x5F5922D85AF69748ULL, 0xAA9519B10C4A14C7ULL, 
            0xE6E194918CC6BB75ULL, 0xDB7D17A0664BD60BULL, 0x1000C3430911FA04ULL, 0x64258F7A81D40260ULL, 
            0xBE7CFE618E7520EBULL, 0x03D8AD1F219A6D00ULL, 0x5D08EE583B540D86ULL, 0x340BA5801141AC18ULL, 
            0x8FE914D8E823CAE6ULL, 0x99E70871D5A67201ULL, 0x98279CF4BBA43DC5ULL, 0xF867F0AEC36B51C9ULL, 
            0xD3843C70CF25E3DEULL, 0x7002DA4ADF2758C5ULL, 0x2EE36FF8051F8777ULL, 0xF89009A4FAF5068DULL
        },
        {
            0xB149B7294F641FFAULL, 0x0BAADCC185CD06E2ULL, 0xE692FCE27383ECDBULL, 0x255353E21B0292CDULL, 
            0x9620660DBF59579EULL, 0x1B7B9CEBB05A991BULL, 0xBE02C2E3280793FBULL, 0x5425B1CFD673C3CDULL, 
            0x7C971AA5A9D8A1DDULL, 0x6B5F126A688AECCCULL, 0x22E45F65BF635A9FULL, 0x5645BD9CF184FBBEULL, 
            0x1764CDF0D6B9A058ULL, 0x577DD7AECAA34EFFULL, 0x9FA66178816B6C2AULL, 0x6C930E0580202547ULL, 
            0x8186F8E46AB96E92ULL, 0x9768D650A0577966ULL, 0xE3C4CB8FE71BCCC8ULL, 0x6176A04EB8CE5DFBULL, 
            0xB7DA66A323202A06ULL, 0x299A9FEF0894F39CULL, 0x0F5B23F6B8F7A69AULL, 0x6BCFC56EED497278ULL, 
            0xB21E959EA03D9DECULL, 0xE4F13084A3F80EC6ULL, 0x517070BDBAC10E3CULL, 0x80F3353251278FD6ULL, 
            0xC5B9E598ACDACE2FULL, 0xA9D9474B87E2E0BBULL, 0x3D4AF60B583A5458ULL, 0xDE7DA8180FCA2E8AULL
        },
        {
            0x699E4EA42F4D5CD6ULL, 0xDDAB76E8EA972713ULL, 0x1EB504EC123FCFA5ULL, 0x65F6E177F8200028ULL, 
            0xFBA5ADC5A4A09497ULL, 0x411D809917EFE43AULL, 0xFD52F2FF4986F7FAULL, 0x417C43900F7E576EULL, 
            0x889022B3887513FEULL, 0x493022BC60E956E7ULL, 0x074595AE13FE1F24ULL, 0xD2F45AA9EC99A2D1ULL, 
            0xBC2888355A1E1D4DULL, 0x854792BBEC48813DULL, 0xF7A5EDAAAE8B1DA3ULL, 0x9FED1C2EE8A3A737ULL, 
            0x9369AD983788E6BDULL, 0xECC7EF69893B6B47ULL, 0xFB05638716BBFFD8ULL, 0xB0120D1C3964F03AULL, 
            0xBB69A47A958935A3ULL, 0xEA53903C0AF6BF6EULL, 0x3324152EC4C9F950ULL, 0x7F6CB8799C762AD8ULL, 
            0x33D10BA21E4D26B1ULL, 0xC7DA131270840C0AULL, 0xA350F93BBE9AE4DFULL, 0x47FFB9AD1894B24BULL, 
            0xFF9A7BBAFC25C061ULL, 0x5C9CAE4427688006ULL, 0xD33EBFDFFA3BB621ULL, 0xDCEBFA80C2766471ULL
        },
        {
            0x84CEF010DB4098A2ULL, 0x060D931F1CF2D562ULL, 0x0EE218E5F0AD1CA5ULL, 0x8F542E8EB0EC7211ULL, 
            0xFF669D3A7CC4018DULL, 0x753E839A60EA3869ULL, 0x1D93AAFC5D6E1145ULL, 0x4BA231D6DA62AB29ULL, 
            0x0DD1C6485540AE98ULL, 0x28E9D80EB71B8D4BULL, 0x78104241C1AC1A4DULL, 0xD0B968A82011C9B3ULL, 
            0x889144E101D36EE9ULL, 0xE699F47087EBA86DULL, 0xD30A39E8820C234DULL, 0xF770924D762731E2ULL, 
            0x4ACB3783149FD4DDULL, 0xC4DE877256E1D013ULL, 0xE9022FA556EF228DULL, 0x885BC0252EE5C88BULL, 
            0xA6B0D6DF63E6FDDAULL, 0x31E084A919066486ULL, 0xCD27485953B6B5B6ULL, 0x9CDE69FBF146E593ULL, 
            0x4B15CAD103F369FAULL, 0xF1043B02268B5EF7ULL, 0xC656A6F327097086ULL, 0xCFBEE7A4146895B8ULL, 
            0x6894EAEA72B5F29CULL, 0x7F47277E6726DEF6ULL, 0xE7F399371CC1F46BULL, 0x0B025CB3F898E589ULL
        },
        {
            0x1ECAAC1CCB611F83ULL, 0x843AC165E93058BDULL, 0x5F5550BE43501CE7ULL, 0x3E019C92F3F2B6E6ULL, 
            0x50FEC99EB149629FULL, 0x5377019D22A2DB62ULL, 0xD2566C8A1D6435D6ULL, 0x121F815CBF626067ULL, 
            0x20D00EA134D43E5AULL, 0x98AD5D22733AA4C8ULL, 0x305C8C0E72EBC211ULL, 0x03C9668A27295B13ULL, 
            0x141008A1959BD15BULL, 0x56DD0B1AEABD18B9ULL, 0xC7556A64B0ED3F4BULL, 0x3C5CBAB815752D05ULL, 
            0x0E4BF96F66D8BD12ULL, 0x18AC14FF1844B6F4ULL, 0xA9A3498E575608C5ULL, 0x1D6A41BFC8CCC5C5ULL, 
            0xFB537730A1C91BE0ULL, 0x972BF296474AB1A6ULL, 0x7E785ABC8AC26200ULL, 0x51FEC8C639EF4F23ULL, 
            0x3409D62956F813BCULL, 0x4DBC715AA2A1596EULL, 0x9C60EDB1045715F0ULL, 0x4F9B03079DB806FBULL, 
            0x31F0A3EEB087DCB7ULL, 0x5247BF59EC0A3E10ULL, 0x4F2B1701AF2F0EAAULL, 0x214208F7D2840BECULL
        },
        {
            0xE2D51080B5AC4C11ULL, 0x75F2A846BDBBD4D5ULL, 0xBCE3E259D9425C2AULL, 0x7D677C439446DD24ULL, 
            0x36F6BA7CA058463BULL, 0x5F8AD3F44F8EB2CCULL, 0x03D91E0241C838D7ULL, 0x94B8018F53A5F827ULL, 
            0x1B84CF2BCF662FB2ULL, 0x8865BA30B8A26C74ULL, 0x8D1100F2052CEA5CULL, 0xB05954A9252F423CULL, 
            0x03F7685AB07CDF68ULL, 0x3202A37CA3EBACF5ULL, 0x53A5E860B9A56B89ULL, 0xB3562C7D3B14C3D9ULL, 
            0x1EE388D18ECE7BECULL, 0xEF2AF6BBBC5315AFULL, 0xA5EE9562B626AFFFULL, 0xBCE4FE715271414CULL, 
            0x9524A57A199FEAD5ULL, 0x1B5A6A8097C13F5CULL, 0x4BEF633F7B34DCFAULL, 0x1D5A7935A193DDB8ULL, 
            0xF4D53624F74A7052ULL, 0x0CCB87AFEDB60C30ULL, 0x8578C421F9AA8196ULL, 0x3763EB1BF42C9311ULL, 
            0xBE7B5DE689C33353ULL, 0x0876DA3572843FF8ULL, 0x6FF77C51CB8C7A94ULL, 0x2EE1EC7832EB8028ULL
        }
    },
    {
        {
            0x5351BA769276232BULL, 0x69DFA1AA7D83A4ADULL, 0x6BEE3D7DC97FF548ULL, 0x2C93DF260CBD42B7ULL, 
            0xE8B296F9591DF555ULL, 0xA6961EBC847FBADEULL, 0x6E2113B17F1F3ABAULL, 0xCB79184A15FCEEF7ULL, 
            0x135869F7BA321EC1ULL, 0x6EA9A8ABBF8DC2F5ULL, 0x0E0A75E7FC100FC3ULL, 0x055C873A2A43E468ULL, 
            0x4F6BDEEDABCBD823ULL, 0x0A80350BC5F055B4ULL, 0x8C32900B49E7A4C0ULL, 0x6E3226381002AEDAULL, 
            0x2EA56B548D064F68ULL, 0xD83690AA3105C067ULL, 0xD2569C6E57F9BCDAULL, 0x9E64A9E9641C18CCULL, 
            0x6BE25FF9AE7E1B2FULL, 0x89D0F81AD190C1F5ULL, 0xDD1D69C31A3E3D04ULL, 0x5E9625F999289AFCULL, 
            0x6B6B2972EAF81462ULL, 0x20F862CC3DD3A8C2ULL, 0xDF0D3D7AF738229AULL, 0x2F6FBE6204862FEEULL, 
            0xB1A01FF9736E14D9ULL, 0x932A2D17F0A76DDBULL, 0x7845AB84AAB243B4ULL, 0xF7B13E2783938F8AULL
        },
        {
            0x9B9C6AD6C0A79CE4ULL, 0x8814AEB09C1FB144ULL, 0xF276B4BFC0E08A9CULL, 0x0B437EFAE711C335ULL, 
            0xB880579EA3F82B6DULL, 0xF775EAC460BC6B3CULL, 0x28EF8115AD912DADULL, 0x2014B8BEF3A49A59ULL, 
            0x897567700253B419ULL, 0x42F32084D35D29C2ULL, 0x9C8E9DDD86728C00ULL, 0xADDD33F7F7EA33F9ULL, 
            0x18308951C6F060BBULL, 0xC40FB62C711FEF95ULL, 0xC0901D49C4CEF740ULL, 0x8429B194A1BCF22EULL, 
            0x9917D531327A385FULL, 0xCD6E41E35B176DEEULL, 0x08FB5948A728C40FULL, 0xFB757B2D9CE7F503ULL, 
            0x935F7C9EAA1AE1A5ULL, 0x0646D9979140F1D5ULL, 0x2AF3EFE09A093680ULL, 0xB5D6F2FD06AB5FBBULL, 
            0x86B5CAC834F454BCULL, 0x101DCA88B755B4E8ULL, 0x44B81DE88E7B04DCULL, 0xC8DB59CC53524114ULL, 
            0x24CBF3C61AD13F21ULL, 0x8D438DAF23454BD2ULL, 0xBCCBADBBABC9CFF2ULL, 0x2289D7CCDB2C5A6AULL
        },
        {
            0xC910324CF4CD20DAULL, 0xD7841D310BD5EB1BULL, 0xBD8079BEF97CA2F6ULL, 0x87F8632A3F945828ULL, 
            0x8B91A389CD2D9137ULL, 0x8B139ABD59B020FDULL, 0x536C8C38E12A9AD7ULL, 0x6BF77B799AD142BEULL, 
            0xC7CD20456F3528F8ULL, 0xEA664ECEFA8DDFAEULL, 0xB7FBC60E460F41E3ULL, 0x8EF6442873ACD104ULL, 
            0xE22B8ACCCB795823ULL, 0x7DECF9CFF7E8A16AULL, 0x3C5C7417D2157D7FULL, 0xCBEE720C91D06D8DULL, 
            0x549BB3AA082EE4B1ULL, 0x964B11641ED60BD5ULL, 0x22F7DBB928F6A29EULL, 0xAEA43B64FF6D8259ULL, 
            0x39483670E0E94AC2ULL, 0x384E74B31FD6F814ULL, 0x05726A61DB761EFBULL, 0x933F15CE4F278446ULL, 
            0xDEA8C6BAD8CEC5E8ULL, 0xF897916DCE0962BBULL, 0xB22DEB4B9605B0D0ULL, 0x924DF4953AEA6BBCULL, 
            0x47466E0A387EF444ULL, 0xC06D380ADD16BAEBULL, 0x911511DA239304D9ULL, 0x81E46C211C539ED6ULL
        },
        {
            0x74FD1EEDEDEBDC36ULL, 0x87763FCE6F8D43E4ULL, 0x334481A2ED32C805ULL, 0xDD6F51CBBF42190FULL, 
            0xA54F5F516760212FULL, 0xD3DF1F40459EEB70ULL, 0xE759A3958597829CULL, 0xDF2E5A8B959FA4E5ULL, 
            0xA879D0CD5E1E2295ULL, 0x81397716595E3127ULL, 0xF358EC45AB8795D0ULL, 0xC9F82D4321D6B18FULL, 
            0x226DEE91B8F446C8ULL, 0x7080D34BAD09286AULL, 0x6EDDBB5A841A20A6ULL, 0x8DDCD90366B3F74BULL, 
            0x067BBB20DFD1F879ULL, 0x54894B5385E97F18ULL, 0x13B7823EADFF233FULL, 0x8514CFB178897D95ULL, 
            0x8F780FC172DCF500ULL, 0xBB94C0A293DFECC1ULL, 0x6541FF1A18407DFEULL, 0x8EE472C00A823AD3ULL, 
            0xB3E4E510A9471020ULL, 0x7C4B8A3161C7A063ULL, 0xCA373BCECB08758CULL, 0x3BE905E8BCB8634BULL, 
            0xF4C8A8CF03B94994ULL, 0x0BB6F6F5D81DCAB5ULL, 0xCC222DED1F183B56ULL, 0xFA19D2508190941FULL
        },
        {
            0xDD395271F026E8D3ULL, 0x4D51E6DA8E1F0B7DULL, 0x28ED126FD0C6A14BULL, 0x67655CF347DEC1E0ULL, 
            0x48D9CA57DA151B97ULL, 0xC7563810FC52DE4FULL, 0x8625B1117A25C7C8ULL, 0xB54BA3EA01816DF3ULL, 
            0x1B1BD76F75C8189DULL, 0xBA4B592B26A70FADULL, 0x34419A18CD0299C2ULL, 0xDD09A01FD8ADC8E3ULL, 
            0xED775FB193F744FEULL, 0x87E9BE95B03D2308ULL, 0x44FDEC639F4BD382ULL, 0x0E1F96A69FE623BDULL, 
            0x75FFEAE05355C140ULL, 0xC60E5C10F1503F61ULL, 0xD67D6B20E7C252BCULL, 0xB5B00DDE909FD5C1ULL, 
            0x84AB10834BDA769FULL, 0xCB144C8000BFA52AULL, 0xF6944748D060FBF8ULL, 0x59076C7F54D7C245ULL, 
            0x996B8052A7DA22BBULL, 0x028EA0B867C3C39AULL, 0xB61D341165FAE55AULL, 0x987E21C6844A3ED2ULL, 
            0x2DD79BDAE08DE039ULL, 0xF48817E1A268DE8AULL, 0xEC775120D0CE1207ULL, 0x6797413BB893141BULL
        },
        {
            0xFA99D537C9A787DBULL, 0x563A4F30A5DD23F9ULL, 0x8E68B2F10807CB47ULL, 0x7D54D63E344310D5ULL, 
            0xCA0DACEAD5F5C187ULL, 0x658DADF0CD451578ULL, 0xF0D9ABAE948D1584ULL, 0x8FDED27CDD552C1DULL, 
            0xF14C8D6152C2A103ULL, 0xC02218AAB7FF6BBCULL, 0xAB58C0D00E413D45ULL, 0x123CD4D6897C9C39ULL, 
            0x396313D221C10C19ULL, 0x803152FD7E4A7D36ULL, 0x406BC690DC596CD3ULL, 0x84E8C877DB56EB53ULL, 
            0xEC49CA6476C247C8ULL, 0x572C37EC65ACA109ULL, 0x0EAA796B05EA67FEULL, 0x317E4AADFBAE3AFAULL, 
            0xC88AA893526AD07CULL, 0xC7B9D401A4B20B06ULL, 0xDD8B7C7FC2CED1FCULL, 0x82E425EADF44C7C6ULL, 
            0x0D3DC421752EEDFDULL, 0xFB816C79D58A7B91ULL, 0x9D7E325B64989445ULL, 0x635E92BF1E18BF5AULL, 
            0xEE90F88CAB9F762FULL, 0x433A196D69130B89ULL, 0x7841E43D54070588ULL, 0x80CAF86822554731ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alcor::kPhaseBConstants = {
    0xB2E852DB62BB7824ULL,
    0x200660098BFD2053ULL,
    0x980257649BF8A864ULL,
    0xB2E852DB62BB7824ULL,
    0x200660098BFD2053ULL,
    0x980257649BF8A864ULL,
    0x98EE2D5A5E8D9B28ULL,
    0x112F631B0AA88E52ULL,
    0x70,
    0x45,
    0x90,
    0x1B,
    0x24,
    0x2C,
    0x88,
    0x89
};

const TwistDomainSaltSet TwistExpander_Alcor::kPhaseCSalts = {
    {
        {
            0xBB4CEA9974AE7503ULL, 0xCE43D8F8285C9B84ULL, 0xC89B759F848ED953ULL, 0x6D4C3ECF7CF48FBCULL, 
            0x53FF1400DCB5D07BULL, 0x2BF583C63C2E2E9DULL, 0x01DA52A4F321FA3CULL, 0x711BB135806D6BC5ULL, 
            0xDF28BD829AEB65DEULL, 0xB9467B1514D92EC4ULL, 0x07D02D23C3C44343ULL, 0x8377C7B57E4F9F0CULL, 
            0x7D0C9870B857E686ULL, 0x32BF8528584683A5ULL, 0x6DAE93D5095527ACULL, 0xE7359502D2B0BA65ULL, 
            0x478AD468AA93CF75ULL, 0x381FD366DFB6CF4AULL, 0x94415F719F8D17EDULL, 0x8FAF637C409E775CULL, 
            0x3F61770587F62EC4ULL, 0x03E64CB65A2047C5ULL, 0xE9DAE72E22DEA158ULL, 0x94A43DB05D437FCAULL, 
            0x010D8E8FA244AB7EULL, 0x4455A993E33E95F9ULL, 0x1480985AA333EEF0ULL, 0x8B6B35C14B8A52CFULL, 
            0x2D23D9B2989B655EULL, 0xD0EDCAB2A276BA67ULL, 0xDBE18FA2936D92D5ULL, 0x9652EEB5E3CB42C5ULL
        },
        {
            0x5B381E37C044C579ULL, 0x0DE54354A66CF291ULL, 0x7446D1B16EB8FA13ULL, 0x2A775252CF1E6B87ULL, 
            0x6A1CC53FF806EE3BULL, 0x04B3B877AC47BA09ULL, 0x78D58516F266BF07ULL, 0x15C585AB5A701F65ULL, 
            0x65FB03244792C18DULL, 0x70BA19BE17B5F8B5ULL, 0x9E8AEB52606024A9ULL, 0x6CFC2CE79D4B2CF4ULL, 
            0xD34F6681B6437016ULL, 0xFFC6BFCDA99D0D2BULL, 0x176452B683659CA6ULL, 0xC37D3D27D4B80572ULL, 
            0x16C948A1A0D670CDULL, 0xF6D4542ADB739031ULL, 0x6708D1E50793E121ULL, 0x48F59F58EE768858ULL, 
            0xC9ABC0F31754C777ULL, 0x417F0A972940E811ULL, 0x7083EF609C1B7876ULL, 0x1FEE37AC5D35AFE7ULL, 
            0xF9AC77C0A1F890F8ULL, 0x90EA65B8EF769699ULL, 0x0D403D91BB950D0AULL, 0x79F0028A3217D151ULL, 
            0x5FD7494598D84239ULL, 0x42C7410B08CCEBF8ULL, 0x1FDB4F7C7030750FULL, 0x58E158B91EBB70C6ULL
        },
        {
            0x80DC3CB947C7C3CEULL, 0xD1F476DC800AE8E0ULL, 0x494DEF166739FB0FULL, 0xE2F465F99444E8EAULL, 
            0xB08665BC8016BC73ULL, 0x0B6AA15F2FBF40C3ULL, 0x6B1CAB8F583FB697ULL, 0x529AD0F171299937ULL, 
            0x5E15E613CE7F02E3ULL, 0x739C2B23E38A5D1AULL, 0x5550783F989208E7ULL, 0xD18B1E449D878FE2ULL, 
            0x2C1985DA5986CCA4ULL, 0xE00479A27D98906FULL, 0x62E48B776DEAC4D5ULL, 0xDE262A3A6F9AB7E2ULL, 
            0xF694887199E350C5ULL, 0x0E6AA2C40A23A162ULL, 0xBB22C2A13614FBB6ULL, 0x2A54214F8A9FF46BULL, 
            0xF90BFB12B84F8EC4ULL, 0xFD8BEA46CFBEA2F4ULL, 0x85D1CF5404CB2465ULL, 0xDC1B308463C6D55EULL, 
            0xCCBBB3B59E80E0BEULL, 0x68B2B1F2058289FAULL, 0x4B9C19A2F7809027ULL, 0x272E738C05414057ULL, 
            0x3ECAE2070353BE81ULL, 0xA932335B6813E083ULL, 0x6C3F417AE90E54B2ULL, 0xC41F98EFDF1F38DAULL
        },
        {
            0x80988719755B7202ULL, 0xF56F1B6757C64CB5ULL, 0x5F7847D62B616E1CULL, 0x8CB9058803B59C8FULL, 
            0xDED3287048979BDBULL, 0xF07996F0B31745D8ULL, 0x1B49584CBF7B7004ULL, 0x0E0DA8353C138747ULL, 
            0x838B097F71C7E885ULL, 0x6BF7583080B362D5ULL, 0x4EFBD3152405881EULL, 0xA3D2856B96E5128AULL, 
            0x53AA825AA1762F24ULL, 0xB59697E0BC499433ULL, 0x5045CDE27AEB4EACULL, 0x3C1ACB3E2CD52920ULL, 
            0x3DB6CB413D31367AULL, 0x38126CF1E47EDCE5ULL, 0xF35BD6AB8601C015ULL, 0x10429C379B0D2877ULL, 
            0xC0F4A669472469F6ULL, 0x412A3FAA3AC8266FULL, 0x5E85BD96ABC98033ULL, 0x1CA46371177536D0ULL, 
            0x90BF348CC0E01C14ULL, 0xC5E99325205A1723ULL, 0x74DBDADD4840B000ULL, 0xCC81A67198A5E605ULL, 
            0xD01D198476E3003CULL, 0x451B755937EAD825ULL, 0x491025974995EBD8ULL, 0xD2FFE42D4FD75A24ULL
        },
        {
            0x42A87E1C94E04A69ULL, 0xD7AB68151C01994FULL, 0xF491D81B3C801221ULL, 0x8D41C9D7C12F52B2ULL, 
            0x4A07A3315E82F6ACULL, 0xBA240A79ADE73C41ULL, 0x75DE65BF423C0C68ULL, 0x8F954B4CE1E06E4FULL, 
            0x24B4C58576DA6F43ULL, 0x89936360019D1948ULL, 0x179B9169BAA3A646ULL, 0x43D1E2197A94A17CULL, 
            0x0B18B2B269FDC983ULL, 0x7126ED7B31986346ULL, 0xF62BB706F0306D2CULL, 0x55BA6F2E05A50143ULL, 
            0x5F3EB8F36047CC16ULL, 0x0978E838E75923BCULL, 0x7C56F1BB3294A24EULL, 0xCAD1F4C3B47E8FBDULL, 
            0xAE1FB971F2E1C7CFULL, 0xF4C77F3B83B374A3ULL, 0xFE3F5F6E1DFAFE88ULL, 0x4B2330AD80984BB1ULL, 
            0xF5E510F857452A58ULL, 0x6586CFEF83980903ULL, 0xC1126867E7190F77ULL, 0x0680C7220A9FB9F2ULL, 
            0xB0F40B342D3BB866ULL, 0xCE8AD4C6F3BA8E25ULL, 0x468F9C41753FC9C4ULL, 0x9431E40DB0F82AF9ULL
        },
        {
            0x35E562A64E11423EULL, 0x17BAA86EB22ABC47ULL, 0xBEE44BBA87A78669ULL, 0x220C5ECC573A5074ULL, 
            0xD2C03C35BB1DF85BULL, 0xFAD726552A489FC7ULL, 0x40BEFB6FB6EAFA37ULL, 0x9A6626EA69F17485ULL, 
            0xD13B2E89B5E30707ULL, 0x5A6C51414990AF71ULL, 0xA788833D11FE5194ULL, 0xC7B18B4FFEECDB07ULL, 
            0xC330590E66EFBE44ULL, 0x086B22CF3328B9D2ULL, 0x781E7076D559F0EBULL, 0x9078875F211EE098ULL, 
            0x490FE9EC57C96145ULL, 0x8F16A6383A5E4315ULL, 0x7A2E975552F6F0BDULL, 0x8C610A913189A5A4ULL, 
            0x3646D829CBF25206ULL, 0x50FCF7DFA3CFB6CDULL, 0x9619C7EF689A70C8ULL, 0xA422098231539183ULL, 
            0x2E60DBC35305F30BULL, 0x664907BF9B4FA0C1ULL, 0xFBC8E0DBF785EC4AULL, 0xF06E7A9B1ABBD408ULL, 
            0xA9C3CA605B29C2AAULL, 0x8B96CB331C840EC9ULL, 0x907E4D4E352C0A2CULL, 0x9B8CDC03D5199BEEULL
        }
    },
    {
        {
            0x61A2A8E91842DE72ULL, 0x3B78C578DF945B15ULL, 0xBFC239359C22377AULL, 0x41985E85CF9182E9ULL, 
            0x73E7CF24A15DEC00ULL, 0x4954EB1864E45FACULL, 0x566BF0133186775DULL, 0x064C0B04B8CBE0DAULL, 
            0x475AA71E3B837498ULL, 0x2CCB0305E513E62FULL, 0xE1719ADF3ABB4787ULL, 0xEECC61820C5D32B6ULL, 
            0xDE0550AECC21DEADULL, 0xCC4125ED6BE3667CULL, 0x2D1CE1159C9E94FCULL, 0xB38BDF376D968994ULL, 
            0xA84CE52F063DCAFFULL, 0x0ABA0C9A1EC63EA2ULL, 0x0FC67AE159F0323DULL, 0x74B3185D9B6AB92CULL, 
            0xAAC3E748D6AFA457ULL, 0x4BA43622D0CBD9BDULL, 0xD3798870B9FE7BEBULL, 0x863BFC614B200CB1ULL, 
            0xC298A1C4E31A93F8ULL, 0xA5A88E1D9C283EE3ULL, 0xD06D69866A50EE1CULL, 0xB1CFAB1EF00F4F9CULL, 
            0x9744C9E1FFC33821ULL, 0x5491539982601AA6ULL, 0x841A7AE29D81A3BAULL, 0xC68E249879DE760CULL
        },
        {
            0x1E7A1466FDB1BE18ULL, 0x4826DA02A71BF6BCULL, 0x8C3F9B27A8218F3EULL, 0x3368FB60D5EAAC4EULL, 
            0x45303F8CE0393ED7ULL, 0x608A2690D7EB4342ULL, 0x932C8B4536DC6CC5ULL, 0xC24A12126E3A29C3ULL, 
            0xF2DE0F7CE5EF6D53ULL, 0xE6089C2D2D41B0DDULL, 0x9B4B62D4D29E56E8ULL, 0x656D683E0ED773CCULL, 
            0x44139E053CEF7A35ULL, 0xD023C1CCD7F8FF5CULL, 0xB93D85875FC57D06ULL, 0x9E3684D9669DF85AULL, 
            0xEFD83CB49D556FB1ULL, 0x0C5DAB8CA41DFBC4ULL, 0x09B3839E56B898DBULL, 0x3F39F2EC67113A07ULL, 
            0x775BBBC3B6FA8107ULL, 0x0DA90137FDE19E7EULL, 0xC7898B4B44DA86A0ULL, 0x57E4E8120AB81B5BULL, 
            0xF9B21E8E549FABC1ULL, 0x8967F7A1E7C98D92ULL, 0x5C86ED261D215185ULL, 0x10F904B027FE0B37ULL, 
            0x93E5D2B592F47A64ULL, 0xC54BB1ED5BA1BD46ULL, 0x5C4EE9D10AEE59A0ULL, 0xE0ECFE3FED22093CULL
        },
        {
            0xA532E1603375ABB0ULL, 0x2496355AFA484697ULL, 0x567196408864979FULL, 0xBD7C833A877990A0ULL, 
            0x19D716F8E03018DFULL, 0xBF5F813563160904ULL, 0x09E35788D4F424B7ULL, 0xCB4F458990671EFBULL, 
            0xC557C911D8CC0189ULL, 0x5F3CA7A2D500B67CULL, 0x3A3CCDDFA5ECA432ULL, 0x000662A400B24938ULL, 
            0xB8B9374D1E971840ULL, 0x0D4A24431F84DBC0ULL, 0xF7F6936B54A18FEAULL, 0x2B4B037925FDBFAEULL, 
            0x5A5D3C209052F6D9ULL, 0xB6FC3469A8506CD1ULL, 0xD161B1B45B47CBB7ULL, 0xC3F4209B21BAA83FULL, 
            0xA3B9B9BDCDFF7472ULL, 0x50DB34E9CFFAB638ULL, 0x98D5A4CB274F865BULL, 0xBD6BCD466BA9CADAULL, 
            0xEBBFD2D6B7CA5ACEULL, 0xBBAAA2C3F2F1ED06ULL, 0x533C18E6A0C5540CULL, 0xB45C7A25C7082613ULL, 
            0x9101010A4CD1278AULL, 0x5CE5F7BF4F1EF7CCULL, 0xF7EC294994CC1F97ULL, 0x1C141E412137EACBULL
        },
        {
            0xCDDADE4AD94007A4ULL, 0xBBB375B202F4F44FULL, 0xAD4B785A2C54DBE5ULL, 0xAA7D9AE8D5F2BDEDULL, 
            0x56CAA4F231949EE8ULL, 0x1732E71F9D671F06ULL, 0x581877078308E9FFULL, 0x24F4486188852410ULL, 
            0xE2F7220D1ACB5633ULL, 0x1CC202AD4FBF285CULL, 0x9C11DDDE34F3CFB6ULL, 0x9871511967AE0B19ULL, 
            0x617920A63E81CA30ULL, 0x77E6E9F9E2164B4CULL, 0xF363C6894F0DD340ULL, 0x4D43EC179EB72959ULL, 
            0x8F27B35CDD23F641ULL, 0xE48584198184C16AULL, 0xACF8A25727D2BFBDULL, 0xB59E9FE3E29EE21BULL, 
            0xCD7D1F112883F4A0ULL, 0x9EFEF04D583B9BEDULL, 0xD9E5F39EC337C5D3ULL, 0x8229D3744D554367ULL, 
            0xFF0D57E537FF17B8ULL, 0x1FEEF594FDC12154ULL, 0x391E860238223867ULL, 0xEDC92DC73A514C51ULL, 
            0x68CA4032F31A3849ULL, 0x53C237469162F443ULL, 0xD8FBE12CE2948206ULL, 0xBB4C1A461DCF5E8FULL
        },
        {
            0x21B6FB664F9495E2ULL, 0x5E21B05729BD23DCULL, 0xB1A1AC1DAE583D02ULL, 0xA9309F38BE2A7A85ULL, 
            0x496DE9968C87F838ULL, 0x07E13ECB9F4E61A9ULL, 0x96CE91BAB7EEDAE2ULL, 0x36344F92240B043FULL, 
            0xA2DC3A1FEF126C3DULL, 0x56D47624FCB3FBB7ULL, 0xF1C1CE0CC8F974BAULL, 0x3D57B3E70CA0C7C2ULL, 
            0x873D76D92FA8EB55ULL, 0x405F212E5AD995F4ULL, 0x8F9CBE970029FD45ULL, 0x4F9C2F585EF2808CULL, 
            0x843EB0484AF9848BULL, 0xF8F0B063EE031F0BULL, 0x5578CF1F1A8A4613ULL, 0x762CB30E66C356BDULL, 
            0x7FF729BCF22974C8ULL, 0x703D024B45201150ULL, 0x88A0A6F7D729AF9DULL, 0x5F5E39A32C2FFD27ULL, 
            0x8A7F2A381C1E057DULL, 0x5BC425D483F8F63DULL, 0x8FD6F99FB443E117ULL, 0x309A43E69EEEF853ULL, 
            0xDCE2EA8BAFC5DC14ULL, 0xBEF27EB3763B3CC8ULL, 0xB3DDCBAE8E16B788ULL, 0x183F0E886D5F5AEFULL
        },
        {
            0x88460D5F90978BFDULL, 0x131C158DEC75924CULL, 0x63C1FEE099EFFAF6ULL, 0x787D59189AAF7C0FULL, 
            0x1CAD96BBB043D57BULL, 0xFCBE0833ABE4025FULL, 0x87AC3C12013C5C04ULL, 0xEE57E6F394904FE9ULL, 
            0x48ACAB3C2D0092B7ULL, 0xA740893E0BFB319AULL, 0x3E6DBBDCCCB7B631ULL, 0x814EFD110FCB5D0DULL, 
            0xF433197B09B85008ULL, 0xD55FF25C035BBCF8ULL, 0x50385A19DFBB69F7ULL, 0x3E10B21AAF5FE8CAULL, 
            0xA887F0387BF13C40ULL, 0xF88D3912EA6B00ECULL, 0xF2859995694039B2ULL, 0x5972064BE0047FCFULL, 
            0xA5B4D0933F7AD7BAULL, 0xDFD147B888E6B656ULL, 0x1EDA5BD6CC1841CAULL, 0xE2A214707D6FCEEDULL, 
            0x1821B9F24472D798ULL, 0x52F77F8BA06946BDULL, 0x61400B6C845FD9A5ULL, 0x7B972028E0EF1A9CULL, 
            0x95FB423EC64736BFULL, 0x8806FEDAA60DC1B4ULL, 0x7567A3C596376588ULL, 0x86F80437F97686F4ULL
        }
    },
    {
        {
            0xAC29E7939A05EC6BULL, 0x08A8E2EF550B2673ULL, 0x78DD72F3B5530169ULL, 0xE907ED1BBBDAC2D1ULL, 
            0x71F41F29CE0E5BE3ULL, 0x4DC0544133C869F7ULL, 0x562A580B6B8D86AAULL, 0x8730417140D1F224ULL, 
            0xC6DF7F43D24FAC3EULL, 0x3768570DB6D86E7EULL, 0xC8C72D9D2EB4FBCFULL, 0x0F1BE16F16E3A09AULL, 
            0x956E4728FEB37BF2ULL, 0x2D977BFD07F00B7FULL, 0xAFCBB178C29E1979ULL, 0x8FAF9D4E1ACFF801ULL, 
            0xA7A4B8FA140C432CULL, 0x42419032060FDB7BULL, 0x421780C2CA048F9BULL, 0x60E4DE3DD6F28368ULL, 
            0x2C0E5CD6D21CE7D0ULL, 0x2B3A38AB5496CAD4ULL, 0xAB207B05CE3396DBULL, 0x1302453A62B36625ULL, 
            0xAAD790AF6843A64EULL, 0x0D3AE67223BD8C10ULL, 0x212915B64D98537CULL, 0x7A8BFDDCA06610E8ULL, 
            0xD05F94EC9FBF8812ULL, 0x994D9B1402384626ULL, 0x5580A1334F623F58ULL, 0x23187E723FFF18F1ULL
        },
        {
            0xB40034609803D40CULL, 0x21B59BDA198B2FE7ULL, 0x6B7D407BAE099D61ULL, 0x6AD1AB45A1586F5BULL, 
            0x423547E424ED7AF1ULL, 0xC4173E24590207B9ULL, 0x8A68C46315D3C5AFULL, 0xEF42CF62896B582AULL, 
            0x3061A6FCD9904111ULL, 0x7699A180026B0EDBULL, 0xE6BF4D83EA4A4E8AULL, 0x75044D742F3408A1ULL, 
            0xFF0461C1382065AEULL, 0x8EA31952980189E2ULL, 0x10DC8B4E7C9ECA33ULL, 0xCE8F9DAA2CAC6BCDULL, 
            0x0977B3BDD2311E91ULL, 0x9704ED6D54E34824ULL, 0xBEFCC27D500CC14CULL, 0x6C3A5063C5B600C3ULL, 
            0xE8858CCECB7781A7ULL, 0x17EB65EA4EBA1D92ULL, 0x36BAD1BA05F0E080ULL, 0x0F3A09C09D72C7F6ULL, 
            0x5237052F4BCF265FULL, 0xB8CC4FE7E3F854F9ULL, 0x07019BDD9643C640ULL, 0x948CA6F1B5294868ULL, 
            0xD72D7C1B73F134BEULL, 0x5D26C5C890D0E9A1ULL, 0x7F17DC8363F9DB44ULL, 0x93FB2109F23245E8ULL
        },
        {
            0xBB43F04BDC93F672ULL, 0x8C383CCB4EFD11BEULL, 0x47097AA37F84B713ULL, 0x504B749BB37E7F64ULL, 
            0x7C8A4955554629D3ULL, 0xE0569B9817A7915CULL, 0xC574BF195FEFADA8ULL, 0x650E1C50F763C879ULL, 
            0xD5E9C9D822333422ULL, 0xF0E304213F0D2789ULL, 0x17B504B3B2A99DACULL, 0xF654769C85AE79A6ULL, 
            0xA5100F4524DD144AULL, 0x60F588E39BF4545FULL, 0xB4305613B5054AF7ULL, 0x50A187BDA497E828ULL, 
            0x83A805EF5F66503DULL, 0xCD4EC8ABA509B171ULL, 0xAF9405DB0FAF7BC4ULL, 0x25C474A3B81FE2C8ULL, 
            0x3FBB54945CFD1A48ULL, 0xA7425A60984B27F5ULL, 0x18F33300438DC2D4ULL, 0x8D3BE554BCB0CBEFULL, 
            0x4CC2EE4CD40A9B39ULL, 0xA76683C8F8D86B70ULL, 0xED563AC0623931F7ULL, 0xAA09CC9B7F4AB0C0ULL, 
            0x3C5792E3A8E56F5EULL, 0xA837712A061D2CB3ULL, 0x6E90D913B105EC18ULL, 0x5B984CEE435A1004ULL
        },
        {
            0x20C3A831B46C055DULL, 0x3FA3BEF08FCD571EULL, 0x600A13CC1B709B16ULL, 0x238879CA3D6EE975ULL, 
            0xCEC72372B1AFFC21ULL, 0x9C6E2A60CCDAB084ULL, 0x0AA47F26DC73A379ULL, 0xAD6C27FFC68E0787ULL, 
            0x883C3E76D85F7E90ULL, 0x3DC318A9544C9397ULL, 0x500B8E625B9B822BULL, 0x9D83A31345113960ULL, 
            0x62AB91D7065304CCULL, 0x24780EAFBF611B85ULL, 0x6A438EB1280D33DFULL, 0x073557F780B9AEE5ULL, 
            0xC15703E92FFCF672ULL, 0xED6F3508757685A1ULL, 0x0B43EB29A41925D0ULL, 0x5F198963CFFA0822ULL, 
            0xABB682FCE9BE46BFULL, 0x4A227549677B4F14ULL, 0xD862E973295503EFULL, 0x311B4F47215B6F80ULL, 
            0x95C5E2111B6CAA8EULL, 0x683C507392E02210ULL, 0xCCAC8680E5226B05ULL, 0x0C76F926C096673FULL, 
            0x27C7B08182F0A477ULL, 0x76FEBCDC7FE891B6ULL, 0x237EAEF666B6B6F6ULL, 0xF0D0957A9AD593A0ULL
        },
        {
            0xAD8531B81E60249EULL, 0x6DE5604D5A09E3A4ULL, 0x0DAEE721E73F5F90ULL, 0x96CD95AF5AFAF7ACULL, 
            0x07B4A56AA2182E10ULL, 0x67BB008FB13F3B2BULL, 0x33D776F040C133BDULL, 0xBD04B6B07DA3F7ECULL, 
            0xD7DF11ACEC9747EAULL, 0x38B9FBB68074F7ACULL, 0x2BCACBD8229F258CULL, 0xD2AB399D3DAA8E83ULL, 
            0xE0C65EF1D195E4CBULL, 0xE030148E27955AA4ULL, 0xA1D3483F34EFC715ULL, 0x5F97CFAD7CA92CAFULL, 
            0xEF8F6F423B047ED3ULL, 0x9D5DA6A9BDDE5BF3ULL, 0x2C5461CCCD828B21ULL, 0x884186F56D93771AULL, 
            0xA7608B29D2705B9DULL, 0x6D269C108FE13178ULL, 0xCB65E6974596811AULL, 0x907B53AC831957BBULL, 
            0x3EE59E6EFFBFFC21ULL, 0xDCD750990450A642ULL, 0xE26C42384D9BBAFCULL, 0x92B634AB0BB430C6ULL, 
            0x4383B9CA2DEBC9CEULL, 0x2BA418017493AE9BULL, 0x75DF7FDE9B959DD0ULL, 0x35F1395F51A94027ULL
        },
        {
            0x184F02D09F97E8D0ULL, 0x843F40CE9CD753C4ULL, 0x4886AFAB861F964FULL, 0x0BF9B23BA78D7740ULL, 
            0xA7C6C7A68BCFF29BULL, 0x157402FDBD288B98ULL, 0x884620725BEF647AULL, 0x64BEE5030EC00A3AULL, 
            0xFC933F9AE70AD4BBULL, 0xD69338DB09F9CBB4ULL, 0x10EF613F342DC28EULL, 0x5160D24D4FB0A539ULL, 
            0xB8C7D929479B5A09ULL, 0x9AE12402F86278F8ULL, 0x4905946596C8C16FULL, 0xF0F592017CED3C06ULL, 
            0xFE96B9EE958F6382ULL, 0x55B5188300C58ECAULL, 0xF33A44FA5B87D282ULL, 0x2D878FFF03F13C05ULL, 
            0x9C551BB77137AA1FULL, 0x66523C3D9DCC22F1ULL, 0x731500576D0FB16FULL, 0xDD504A1BBE08BBC7ULL, 
            0xCF61BA4ED76756ECULL, 0x7C2F4C528FB3EA30ULL, 0xD3F4C55D9FA99EFBULL, 0x75F6F87BBC83AB63ULL, 
            0x70B42F97C28DD417ULL, 0x92F6075E56C5B576ULL, 0x31617C55F3C9ADDFULL, 0x03CA8F713317A508ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alcor::kPhaseCConstants = {
    0x5D94FFF3FF11BF07ULL,
    0xF2BD58A6FD7D10C2ULL,
    0x487B3F646E7CE4F6ULL,
    0x5D94FFF3FF11BF07ULL,
    0xF2BD58A6FD7D10C2ULL,
    0x487B3F646E7CE4F6ULL,
    0x9B7F8C66B3FC9C93ULL,
    0xD38A7A56BA6BD960ULL,
    0xAF,
    0x59,
    0x42,
    0xC0,
    0xBB,
    0x11,
    0x22,
    0xEE
};

const TwistDomainSaltSet TwistExpander_Alcor::kPhaseDSalts = {
    {
        {
            0x43308A6CB658A8BAULL, 0x3172FB41CF272089ULL, 0xB9F19035786180C5ULL, 0x2BF832A1039C9600ULL, 
            0x5C51A20D690CEE68ULL, 0xBFD8229EFAC157FBULL, 0x184B1AC03C404604ULL, 0x5783D0381B7C05E1ULL, 
            0xF12312F8DFFFBE46ULL, 0x4B22CDC563663239ULL, 0x7D109237C61A13CAULL, 0x325476129902E05BULL, 
            0xF22271C5E4FE09B3ULL, 0x049657CFA15515A0ULL, 0x1C194B2A36AE379FULL, 0xFEEF60D29CD10D2CULL, 
            0xD42D47FD43F23CF9ULL, 0xEAD278F2E71386D8ULL, 0x34504370ECAC8FBFULL, 0xF07A2EB5CCB35CD4ULL, 
            0x827000AF2FCF6A73ULL, 0x34245B1A0C1E4C36ULL, 0xF15FD21C2EA6A73AULL, 0x13E89AEE7DE47EC4ULL, 
            0xF0E28E5D98A23D33ULL, 0x83439EF97892D7D0ULL, 0xC98332E1ECA5A41FULL, 0xB26047DA8F554F5FULL, 
            0x5F2A8DA80756B5F5ULL, 0x5A47079F30AB465DULL, 0x8A12FF4605E167B0ULL, 0x306D984FA300331EULL
        },
        {
            0x65798A48511DDF87ULL, 0xC31BEC36D588E1D5ULL, 0x06DE7A57F3026F88ULL, 0x703F050F0B4E9125ULL, 
            0xBBDD83F24E015403ULL, 0x822B1C8502778097ULL, 0x45C43A4F7090D082ULL, 0xC4029E2835F763D9ULL, 
            0x8BF5912152027C5AULL, 0x640B1EDC2D6CD9F5ULL, 0xFA3EBFFAB0988023ULL, 0x81ECBB4FDBE1F897ULL, 
            0x4578FB2801C2B887ULL, 0x486F28309DDC2E55ULL, 0x5DE7410C875EDDC5ULL, 0x2267FAE4A076E4FCULL, 
            0x983F953B3770AC31ULL, 0x46969CE2DF827740ULL, 0x188912543203033EULL, 0x45D57EAB9F26A5B4ULL, 
            0x8437EC228D4F353AULL, 0x94E0CFCE20900CA0ULL, 0x6A62AA9FA7BF35C2ULL, 0xEA59CD7B6C742AD1ULL, 
            0x0DE0CCD69F025508ULL, 0x075D79FDC2A9EBB5ULL, 0xCC95F41C79F65476ULL, 0xE21392EF73642F30ULL, 
            0x6CD84E2A16F1B1D1ULL, 0x5BDC5E02502CA3D1ULL, 0xB19B9D1E04AB07FFULL, 0xE877C65B173C8FEAULL
        },
        {
            0x524A08B707486732ULL, 0x0859D980A5F1E502ULL, 0xAA08ABB970137611ULL, 0x0E3585E6352C5A0CULL, 
            0x4EF887487475BF6DULL, 0x10B7B803D1D70D99ULL, 0xEB75F81C4E8DA23EULL, 0x8217258A4D3849D0ULL, 
            0x59ECE9758F8BAB6FULL, 0x9185B11B09E319FFULL, 0xDC225B13906D6E32ULL, 0xB6F275EB7E14D1DCULL, 
            0x8688D6E2B164D85BULL, 0x4AC7DCCC86F1058DULL, 0xA258CDD0680B9582ULL, 0x7099DE90EEBE15C7ULL, 
            0xC65D2942440C9155ULL, 0x04D9ABF149128A07ULL, 0x7947762EFE5C72C9ULL, 0xFBCDDB4663C81595ULL, 
            0xAE6B59DDFC173890ULL, 0xDC521C056B013D49ULL, 0xDEC9BA4DAB8DF0BDULL, 0x0153D36C6E009BE3ULL, 
            0x998524BC9309A862ULL, 0xB25472FDAEC578D5ULL, 0xA0F182A5FA2328DFULL, 0x5709AF27858B567CULL, 
            0xDD03ABC3FB32A6ADULL, 0x4F53DB35B257D415ULL, 0xEB3FD4048E5F6C8EULL, 0xCD92A446BCC62740ULL
        },
        {
            0x4F5A5119A24130C7ULL, 0x305E2F9BBB159958ULL, 0xC2E621DE0733A466ULL, 0x26AD8F9DCA01D507ULL, 
            0x836FB9D801458394ULL, 0x6B4B45EE7320EEE2ULL, 0x4D7A8D0202DB5E67ULL, 0xBB81962379E5A1CCULL, 
            0xE4589E19617AAF33ULL, 0xFFE8CC668130416BULL, 0x086367C66779A8F3ULL, 0x92ABB78F97B0A9DBULL, 
            0xD23D5449DD25F3C2ULL, 0xC345A49B06AF5972ULL, 0x7CBF7C3F3E1BD494ULL, 0xFB4D0586C0717364ULL, 
            0xC879D0AB19C7A32AULL, 0x2D473EAA61941987ULL, 0x12087B3BD306F517ULL, 0xA7A8AFFF9846626EULL, 
            0x16D3B8E90D1208C9ULL, 0x7C1C7904AEEA175AULL, 0xE6337BD03584ACA4ULL, 0xFB634AE84CB6FCBCULL, 
            0x053E5CC066148F49ULL, 0xF63518392F1BEFADULL, 0x92E573170E4197CFULL, 0xC1ED94DFD59B8221ULL, 
            0xAFE25ED0DF20D53BULL, 0xB8DA715CF4445BC2ULL, 0x91A7BA192BF65779ULL, 0x462B729C2228A9C0ULL
        },
        {
            0x3BCD785C3E7FA64CULL, 0x797BE4F5EF9D300BULL, 0x2F5744666556B50EULL, 0x62C3C23C3BA2F0B3ULL, 
            0x369C9E54DEC8283CULL, 0x2515600E76868FBDULL, 0x20F9B28D72A62096ULL, 0xFAF8BB20355E5D16ULL, 
            0xF1F8F08D5E96D14CULL, 0x5D63C7FD6FB9FBF5ULL, 0x3BE2EF1775C89A01ULL, 0x03ADEDBE00BB6A9DULL, 
            0x42D1A4BBD738B4D6ULL, 0x12CA92A77A23FC25ULL, 0xAAF145F79450C97AULL, 0x02964896B37B3D0AULL, 
            0x6E7A295C8FD36DA7ULL, 0x908EDC280033274EULL, 0xA09852D52A010A9DULL, 0xBE9FA1E7F1BAEA83ULL, 
            0x80AE4AE5EF691B1BULL, 0x87D0B45BC48D83DEULL, 0xD20186A12F305205ULL, 0x88A058F4444620C6ULL, 
            0x7226B63E47D3D777ULL, 0xB2AA1BB08B415492ULL, 0x3E52591409757CEAULL, 0xC27A4E449F3691EFULL, 
            0x9000E77888A6031FULL, 0x43441DC4928499CFULL, 0xF7D25E375323680FULL, 0x908D42B2975BF175ULL
        },
        {
            0x40D70F2E55AED644ULL, 0xFC7074B013722B3DULL, 0x4A1D993884B44671ULL, 0x3C8729A7DAB9CF36ULL, 
            0x397055D52100A8B3ULL, 0x79DA5C38C055B46BULL, 0x5234340918EF26AFULL, 0x4C4FF22A7043B995ULL, 
            0x51041EDA39508787ULL, 0xB56E29D977F2FC53ULL, 0xB66E3112F743A3D6ULL, 0x7DD4E6F8C453B928ULL, 
            0xC134205DED6EE3C5ULL, 0x1BFB0DC64A402591ULL, 0x120BD37564C2DB47ULL, 0x87CDA52675A1D0C1ULL, 
            0xA8468B0B67B3977AULL, 0x73E9E460CCB1930FULL, 0xAF44348B3D29FCF3ULL, 0x1ABA9A21976FBDF5ULL, 
            0x8904546629B639A5ULL, 0x5AB569E8ED3B8589ULL, 0xEE87A41127F43AE8ULL, 0xDA6FB7B693240BF2ULL, 
            0xEC53F1EEBAC25716ULL, 0xA9137807416680ECULL, 0x48E77F93CD47CF44ULL, 0xA8BE693BAF610F92ULL, 
            0x673A60D1D9629CCDULL, 0xD8F171E2CA2DC336ULL, 0x428363F12290D6E5ULL, 0xCBAC2C3904D8C9A5ULL
        }
    },
    {
        {
            0xF924383726ED4023ULL, 0xEBE406CCA5153627ULL, 0xE7B4878D2CD8C0A5ULL, 0x2FA31FADC30A3F4EULL, 
            0x445128A237E9D55CULL, 0x9A8FB08EC5CDAF40ULL, 0x64708CAEEC8A987BULL, 0xEF9E2471B033AD39ULL, 
            0xA2A84E23A7BC725CULL, 0x52D543EE4C48C9E5ULL, 0x2747056A9B6B827FULL, 0xCB583A8DEF6DFF7EULL, 
            0x0A2A2428A16C524EULL, 0xB2CB2A725AFDEC2BULL, 0x6D99FE04FB06E86DULL, 0xFB853F3CB4D2214FULL, 
            0x10D62AF4E3802272ULL, 0x820F47BB2A7AFE46ULL, 0x8DE0A1FA2C45C279ULL, 0xF1F1B6CF8DD8D7A9ULL, 
            0xA522E61A7FE30F7FULL, 0xBDD4BDE2A6EFCA32ULL, 0x24313676C4794B02ULL, 0x55A5AC0F8CF04330ULL, 
            0x304C824378F6730AULL, 0x89B6ECD4DF3FB7BCULL, 0x0FED95E85521C97FULL, 0xE745410364829615ULL, 
            0x6BDEDCE399B3410CULL, 0xE9D251CE58AFB7E9ULL, 0x55DF788CBD39E7BDULL, 0x046BF9383F03DBA9ULL
        },
        {
            0x6D4D91F811B3B234ULL, 0x6C967DA92D7CC275ULL, 0x01B8A5CF958CA858ULL, 0x85E838215DCA6525ULL, 
            0x68C41F52A3F5F57AULL, 0x60BB4A58F8DADB12ULL, 0x482E5CD277FE9620ULL, 0xCE987A4DB543A4B0ULL, 
            0x01488E7B0314493BULL, 0x055E42F05FA2E04BULL, 0x15A602D941CFC884ULL, 0x060DBBC5B51955C6ULL, 
            0x222E06E04200C940ULL, 0x8413A2B03C6F05AFULL, 0x2E46541023F715F2ULL, 0x33504DA290A50CD2ULL, 
            0x751D44C2D56B9297ULL, 0x25E0C1138F103317ULL, 0x7F4C6FE791781EA2ULL, 0x1E078E74D931EEB1ULL, 
            0x8F44D7C367061DB0ULL, 0xAE86CB4BB1311F3DULL, 0xD6BB34B95A867459ULL, 0xE1AC6A3372DC7378ULL, 
            0x171007C6C1256D78ULL, 0x009D7E0D02180CA2ULL, 0xE6458DEA5CDE7522ULL, 0x43390D4707236048ULL, 
            0xDCC95D1E62F188D1ULL, 0xD5E3BD7118DA965EULL, 0x55A6786777870B38ULL, 0x703DF13C39874E69ULL
        },
        {
            0x6411B46CC84F5BB7ULL, 0x5D3B6F72029D1663ULL, 0x8531A6DA06709C54ULL, 0x94FB08997D699B8DULL, 
            0x5964E3A24195B44CULL, 0x264223AEFE7E8697ULL, 0xA122F8085AFEDE26ULL, 0x814161D1EBFF7113ULL, 
            0x90A15CD23D643B3CULL, 0x0BF4E10CC882D449ULL, 0xACEE4734A3B40604ULL, 0x9B95326E5E2247B0ULL, 
            0x8197F8997954C602ULL, 0xA345ACC68E2BB244ULL, 0x8AF3EE4804DF9A19ULL, 0xDB2DF2EA2C50D66AULL, 
            0xC02F36A6F46D6FDFULL, 0x5655F416D436345BULL, 0x805FC12910BADFD4ULL, 0xBEA7E71153AE1807ULL, 
            0x4C40058ED6ACFF04ULL, 0xD95F7E21A14CAD5EULL, 0x5C29B6C1A00E9D85ULL, 0xABB69579697CBB3DULL, 
            0x84ADB86C3DEF13B5ULL, 0xD8803A055BCCB4D4ULL, 0x8AFAFBB5978C57F2ULL, 0xAC4341C62D5CD809ULL, 
            0x47DB26B628F63549ULL, 0xCB148CE7B6EC5A69ULL, 0x6A72F7C94C9A8F47ULL, 0xB93B91B2EBF6640EULL
        },
        {
            0x4077E0E1D8928BD0ULL, 0xB8EB675315FBF83AULL, 0xEF5203C9BDDD2FE6ULL, 0x1B918249CC74A6D2ULL, 
            0x30817C3AF46C10BAULL, 0x4A19F34EDA03693BULL, 0x7FD2D296CE31941CULL, 0xEC62FD505037CDDEULL, 
            0x7FC05D69327957BCULL, 0x891CD59A73D37E2AULL, 0x8039AB52EAFE9D65ULL, 0x99D15C1FABEBF96FULL, 
            0x562DC417FE12C6E1ULL, 0x5968335E9844B0C4ULL, 0x53A3B407D5AE5D05ULL, 0xC156734A53FABA4BULL, 
            0xAEF9CD7101AEF4FEULL, 0x029DE37B087A5566ULL, 0xB223208EDC08B597ULL, 0x1C08BF3D7F122B15ULL, 
            0xFF6A1C4C9E36CCC0ULL, 0x2E68126883D88AD7ULL, 0x508F8F5A3A367ECEULL, 0xDF22621E9E587112ULL, 
            0x350EEDD4D7BE771EULL, 0xFB607025DC7B4E31ULL, 0xE80C9F47C4D3CFCBULL, 0x491EBDB264642FB5ULL, 
            0x193A9B52AD3C723FULL, 0x6086F9EF65220470ULL, 0x96EAEFC7D669BA0DULL, 0x29CBE34C890005A0ULL
        },
        {
            0x067ABE2B3CAFAF0FULL, 0x01F3323AF59EB329ULL, 0xE8D6EA7A446D0A11ULL, 0xAC788142CAEAE7DAULL, 
            0xB430ED3B13E1B285ULL, 0x91D73A2061E6C871ULL, 0xCE69039CB8E84618ULL, 0xAAEA640A003C33C2ULL, 
            0x8AD0FFED320C3C56ULL, 0x04F53839B83703C5ULL, 0xE2935A46CD5FB395ULL, 0xFBF82A941BB0FEC7ULL, 
            0x8A9FD7C175AB1306ULL, 0xE6ED63E11CF54051ULL, 0x6EC854492FEB132AULL, 0xB104395F54547962ULL, 
            0x56CC8583D268265AULL, 0x0429FDFDC0E1017FULL, 0x9CF1913C9C73D1E2ULL, 0x52F99D1FD6169698ULL, 
            0x9C69B77B9BB3445DULL, 0x013DB007CBA32282ULL, 0x21EC39E0F4D1F580ULL, 0x720E72422E916932ULL, 
            0x5AFB4CC3CBC27EC9ULL, 0xDADDE524950D5736ULL, 0xACB78F6014B9A435ULL, 0x45C89D04EB3D6E67ULL, 
            0xC65FE5EFF7F49361ULL, 0xA0C4448B443705ABULL, 0x7348C1E87CDF49E1ULL, 0x1F9DD0EFC4FD952BULL
        },
        {
            0x316C761CB0B91B36ULL, 0x2A94AB32483A6688ULL, 0x7F37DE6B55AA83C0ULL, 0xE92C61738D342C6AULL, 
            0xA12CAB23C8E66ED2ULL, 0x21A8067C25EBD9D2ULL, 0x2DF1E937C0E30117ULL, 0x3C8470A7228C6603ULL, 
            0x1BC755E02F73FAE7ULL, 0x2702D2E8E4CD3C88ULL, 0xDC5D2644EAD894D6ULL, 0x98B9F1C65DE5F7FDULL, 
            0x2EC64ABE2E9EB4CAULL, 0xB83B248D9BA7B068ULL, 0xD36F0CDC88732A4DULL, 0x6A93BC38198CF380ULL, 
            0x7CBF01277724DD33ULL, 0xF0C412756F00F800ULL, 0x03F6490A70E6D471ULL, 0x56A0BF5EBB17263DULL, 
            0xC70A7576265A3F1CULL, 0x3B48394D824A2484ULL, 0x4106C1CA4387FD8DULL, 0xC3ACFC9222127428ULL, 
            0x895BD4A533E447F2ULL, 0x052812CE162FA60DULL, 0xCCE680DE81EEC109ULL, 0x3AEA61500E3AEAC7ULL, 
            0x8B0B13B9AB97D0E2ULL, 0x7F1E29969DBE7E99ULL, 0x3593C3E31719A01BULL, 0x5188B2C0464FC314ULL
        }
    },
    {
        {
            0xBCE51DEA995788B7ULL, 0x24BDBEFD22F8E433ULL, 0xDF0FFABD9A065350ULL, 0xFDF24E425E920D51ULL, 
            0xE7FC59FDB7BB1EB4ULL, 0x8920A752FE53A710ULL, 0x925A6909A4C6CFE7ULL, 0x13132F89D4EB0BDEULL, 
            0x4055BE186B35100EULL, 0x26FA2EEC7520782CULL, 0x0011873F413232D6ULL, 0xBF224BCBF1690F0CULL, 
            0x25369A353F9424F4ULL, 0x0AC1022F5DF47733ULL, 0xACE1509ACC93A51DULL, 0x6B091334BF06D33EULL, 
            0x8BD2F287DBF44B9DULL, 0x45FB2F1EB3BB07DBULL, 0x6B81E34EC31791F3ULL, 0x404BFBEE44B2438AULL, 
            0x8A706474D84BBD6FULL, 0x49C9C940D19E7DF0ULL, 0x53F2637BE99D93ABULL, 0xAC30041F804DDEE7ULL, 
            0x5493D7961B342AB2ULL, 0x7D0BA0DA710E4B3FULL, 0xB17CE17EFC1D88D8ULL, 0x6A847214DD44D1CCULL, 
            0x6FD2844A52661C22ULL, 0x4BDE24A5EF551EFFULL, 0xD1AAC6DC9AA85EB4ULL, 0x50060FD73808F070ULL
        },
        {
            0x52FC196AF0C93241ULL, 0x8DA8DC528B19BEACULL, 0xC155B54C806E5228ULL, 0xA145C626EE40546FULL, 
            0xDD043302497A9B4DULL, 0x39CDB5364FCEFA00ULL, 0x456041296217E953ULL, 0xE62DB65C4454B203ULL, 
            0x00BA0850CB776035ULL, 0x32FF411817E86B71ULL, 0x9782374A61A6F079ULL, 0x65B3376F89C439D2ULL, 
            0x44ABE5F7EAFC22B4ULL, 0x01F7485DE2AA25C0ULL, 0xA4075B59CCFC46C7ULL, 0x80CD64E157CA891CULL, 
            0x3FCA4491C6E6BE6EULL, 0x97C388E502CE59F0ULL, 0xE72B52D30C152AE4ULL, 0xFEC5758AE7B1CA72ULL, 
            0x853B08491E308361ULL, 0xEB93AFF3DAA1D7BBULL, 0x713F4B02D6F216F2ULL, 0xC17C91E89596A5A6ULL, 
            0xEB6977BE74284AC9ULL, 0x4277963C4BF342D0ULL, 0x44AFEC31213A2603ULL, 0x3D74B15F7BBDFF0EULL, 
            0x1B74F8AFE173220FULL, 0xE73C7AC0857DBAE4ULL, 0x885464416C4976B3ULL, 0x0C0CDC0964882712ULL
        },
        {
            0x9A6F157CA5C415A2ULL, 0xA23F2ACCBC0D8301ULL, 0xD18AD21C126576D9ULL, 0x966E23F64D0D2C88ULL, 
            0x5103814811938689ULL, 0x32CDD9FD5C0D006FULL, 0x4A7226440E9F3A39ULL, 0x7725208136659C35ULL, 
            0xF1C84A0EB64E133CULL, 0x005EB7F27D8B3E3CULL, 0x8C6D727E037B1F02ULL, 0x18B2CAA5CC6973EDULL, 
            0xF48FFCC4B70A40BCULL, 0x9E3D0FA0B8A8A344ULL, 0x3791EF96D6B94F7FULL, 0x422518D53FFE9868ULL, 
            0x56B7E658D03608E0ULL, 0xDB3D25BD0D9E3564ULL, 0xAA73D1173333B2EBULL, 0xC0B8CBFADFEEA895ULL, 
            0x78EE10F36C7DB8B1ULL, 0xC0CDD0CEB4AACF19ULL, 0x0AAC2B0F5E5434DAULL, 0x61F5A6B52CD2C2CBULL, 
            0xA2DE45AF8EC1594FULL, 0xA3FFA65E6233AFE1ULL, 0xADD32B69C6A5CC77ULL, 0xFD0096290E2D1A1EULL, 
            0xC4BB7365244AF5F4ULL, 0x756B936E2266281CULL, 0xD7F5C3B815209BE0ULL, 0x5CC9A273512C16D7ULL
        },
        {
            0xC15033BFD27FDA86ULL, 0x0DC8B6C2E61344FEULL, 0x70C0E0A0786DF611ULL, 0xD3B1D88FFB5AC9B6ULL, 
            0x7C1C00BA6DDEE283ULL, 0x8F6DB27D14E889CBULL, 0xDDF91FEB2A880253ULL, 0x8E02FA813690603EULL, 
            0xA1268455361328DFULL, 0x8E1D1E53B835F27AULL, 0x5F33FD32C040307AULL, 0x2A3F0A3E15F7243AULL, 
            0xAD028D32B64800C3ULL, 0xD65EB794F7938CD8ULL, 0xD096C2D6B4763C5BULL, 0xE7FCE8A8F2219329ULL, 
            0x59BB46C2940F87FDULL, 0x8B44985715942981ULL, 0xD18EA6074CC1F3CCULL, 0xB9D122EDB0254CD3ULL, 
            0x75C861D5A56461CFULL, 0x44F853BEDFB717A2ULL, 0x55420999FFE7FEACULL, 0x6947B88E2224E904ULL, 
            0xBB11E4BFFBAC0C07ULL, 0x35DDB5769C89B169ULL, 0x053886AFEB538A1BULL, 0x8D1925458CC2B5FCULL, 
            0x3B45DA8DA519DDDEULL, 0x737EC8954991A28EULL, 0xE7400DDFDFA7DB7FULL, 0x8AD0FEFF3090D3DCULL
        },
        {
            0x843B5DA0E832A765ULL, 0xC394D765A0D05C5EULL, 0xA358F4400B344A14ULL, 0x68EE1D6A0ED773E4ULL, 
            0xD272B7266D9C7567ULL, 0x0FEB5B83AEA79CE6ULL, 0x66AD26FDB146721EULL, 0x58C336A5232C7C25ULL, 
            0x208B45B14F8BA0E8ULL, 0xAD01804DDA6AF3D0ULL, 0xAE508E371E875882ULL, 0x3A9F7620CE72B617ULL, 
            0x49F36E28A98A0902ULL, 0xBCFB45F310872FDAULL, 0x04DF90BCB23EB432ULL, 0x3484CE809D07DB80ULL, 
            0x7309FCC3F5692B72ULL, 0x9E357F251D8DFEF1ULL, 0x199E6BD6E496BC64ULL, 0x3F21FCBF918BBFD8ULL, 
            0x7C2480B5529F2C37ULL, 0x8DE9CB8B24961C0CULL, 0x9D7D8D5488385915ULL, 0x4A9817DC26260557ULL, 
            0x017C2DE663B34A92ULL, 0xD953E8F0970E72ABULL, 0x644B455160B4DA0DULL, 0x3AC78C6835C69FEAULL, 
            0xF5EDCDDDEE5BD35BULL, 0xA971C1B7D442B75FULL, 0xB47D7455AE058C28ULL, 0x76226B9D55513268ULL
        },
        {
            0x400AF206EA7602A1ULL, 0x826CE2E52DA5716AULL, 0x6EF21CDDFEF218C6ULL, 0x08883959861943C6ULL, 
            0x1C8CBCA627C2D4F6ULL, 0x83541653A1D3CD96ULL, 0xF4843E86C93DF124ULL, 0x26CE7850F493F5BFULL, 
            0xEB1DDB917DE40B07ULL, 0x618BB1F367253693ULL, 0xB28782E7C9F361AEULL, 0x6AA7A12E19EA91CEULL, 
            0x6EFE29BDBFAE4989ULL, 0x6510D9395484F638ULL, 0xC430CDF0021BCCE5ULL, 0xA141C08492FE7568ULL, 
            0xD1B5A18779F06273ULL, 0x1351E1D2AB18F556ULL, 0x1C3649F4E652B8AAULL, 0x755201F7B97A995FULL, 
            0x1FCBD7340088C9B9ULL, 0xD161B0D6488EEC30ULL, 0x0269224C75698F51ULL, 0xF1E3ECC126A7C12CULL, 
            0xB658BE639B2C4486ULL, 0x183CEAC214F5A20EULL, 0xD654C72A1A73E370ULL, 0xF51792A7F1F0649CULL, 
            0x254D937169A736E3ULL, 0xB4A2E7812DCCC55CULL, 0xCBAC622120DFBF70ULL, 0x5C7C9AB8F6B01F6EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alcor::kPhaseDConstants = {
    0xEB14DBA84CC20655ULL,
    0x2A3E34FECADD6125ULL,
    0x6384A9181CB6E17DULL,
    0xEB14DBA84CC20655ULL,
    0x2A3E34FECADD6125ULL,
    0x6384A9181CB6E17DULL,
    0x19DCE846843C7B82ULL,
    0xBD1D993FB5AB4D0AULL,
    0x42,
    0x02,
    0x9C,
    0x98,
    0xD1,
    0x57,
    0x1D,
    0xD0
};

