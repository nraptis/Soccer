#include "TwistExpander_Naos.hpp"
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

TwistExpander_Naos::TwistExpander_Naos()
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

void TwistExpander_Naos::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xCA5DEE671BDE6036ULL; std::uint64_t aIngress = 0x8BEF57DE8A91BF83ULL; std::uint64_t aCarry = 0xB7C602C4F457EBB7ULL;

    std::uint64_t aWandererA = 0xEAF4FB2A1B1BD732ULL; std::uint64_t aWandererB = 0xDD0D88A83CB7E93AULL; std::uint64_t aWandererC = 0xD75B87F103DF20BDULL; std::uint64_t aWandererD = 0xD87600306589745AULL;
    std::uint64_t aWandererE = 0xEC2FA4F804F48173ULL; std::uint64_t aWandererF = 0xB73253B846238E93ULL; std::uint64_t aWandererG = 0xAEC8EF36686B4071ULL; std::uint64_t aWandererH = 0x8DA8E934391FBDE9ULL;
    std::uint64_t aWandererI = 0x92BEF22C0EDF57A6ULL; std::uint64_t aWandererJ = 0xBA61876AD37C6CF9ULL; std::uint64_t aWandererK = 0xFB069CCC5C035135ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x8462AB94EBE94BE8ULL;
        aCarry = 0xF5689D568D7CD891ULL;
        aWandererA = 0x8003D4D156DDC3E7ULL;
        aWandererB = 0x9F1C0844A5264440ULL;
        aWandererC = 0xA286C844445585BDULL;
        aWandererD = 0x9960E12F72E0D9E4ULL;
        aWandererE = 0x8FD6298DFA3E3320ULL;
        aWandererF = 0xE2560E082784C92FULL;
        aWandererG = 0xEC3B78BD2195CA49ULL;
        aWandererH = 0xECB4DFA1C4DB9F82ULL;
        aWandererI = 0xE0D99D08C7DB6733ULL;
        aWandererJ = 0xA7C20FB224AAAA46ULL;
        aWandererK = 0xD739885195CAE31EULL;
    TwistExpander_Naos_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Naos_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Naos_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Naos_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Naos::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x9CF17BDDA8972FC6ULL; std::uint64_t aIngress = 0xEAE98AD050A2BE32ULL; std::uint64_t aCarry = 0xACF159898832E427ULL;

    std::uint64_t aWandererA = 0x9ACACEDE5E0844E2ULL; std::uint64_t aWandererB = 0xDA6E5018162064C2ULL; std::uint64_t aWandererC = 0xD52293A0BD6CB195ULL; std::uint64_t aWandererD = 0x89874A04DC64AD4AULL;
    std::uint64_t aWandererE = 0xC756350AD4F49C7EULL; std::uint64_t aWandererF = 0xAA6FE8F295A78759ULL; std::uint64_t aWandererG = 0xFF9FBB3F391506E7ULL; std::uint64_t aWandererH = 0xF9C1CA2EAF9FE38BULL;
    std::uint64_t aWandererI = 0xD1B19FD8A3CAAB42ULL; std::uint64_t aWandererJ = 0xDF3D4FE6605B2C96ULL; std::uint64_t aWandererK = 0xE8D53BC57BA383AEULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x85FC40236EB5D12DULL;
        aCarry = 0x9AED1D880865033DULL;
        aWandererA = 0x99997BC5CD292115ULL;
        aWandererB = 0x93BD777CFBE6000EULL;
        aWandererC = 0xDBBE9D937007437BULL;
        aWandererD = 0x9BEB6CB134F1EE0DULL;
        aWandererE = 0x86564ED851C6CE9DULL;
        aWandererF = 0xB0EB63DBB49B2A7FULL;
        aWandererG = 0xF76F0BF227E00E2AULL;
        aWandererH = 0xEB207A5BB50421C6ULL;
        aWandererI = 0xD969A511A9485B6FULL;
        aWandererJ = 0xC7C01542DEE22C0CULL;
        aWandererK = 0x9729A4BC77934CE5ULL;
    TwistExpander_Naos_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Naos_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Naos_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Naos_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Naos::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x8C3624099740094BULL;
    std::uint64_t aIngress = 0x81F0CBFAE21C33B2ULL;
    std::uint64_t aCarry = 0xD66E46A005F6DA70ULL;

    std::uint64_t aWandererA = 0x8434059CD6083948ULL;
    std::uint64_t aWandererB = 0xE8E6D3CF0C7D586FULL;
    std::uint64_t aWandererC = 0xCD2B8B8AC9134F0CULL;
    std::uint64_t aWandererD = 0xDD6B0F09784DE213ULL;
    std::uint64_t aWandererE = 0xBB30B56AE852723AULL;
    std::uint64_t aWandererF = 0xFC0E13DD9B86AD0CULL;
    std::uint64_t aWandererG = 0xA6213EB940D551BEULL;
    std::uint64_t aWandererH = 0xA53EEA7E00AD44FBULL;
    std::uint64_t aWandererI = 0xF9203FF2096BE1CCULL;
    std::uint64_t aWandererJ = 0xECE43E1E7E36C7E7ULL;
    std::uint64_t aWandererK = 0xD9E597A5368850F4ULL;

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
    TwistExpander_Naos_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Naos_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Naos_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Naos_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Naos_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Naos_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Naos_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Naos_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Naos_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Naos_Arx::GROW_B(pWorkSpace,
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

// SmartSquash candidate 23 of 33
// Exploration cases: 100000000
// Nearest-family diversity: 920 / 1088 (84.56%)
// Total distance from earlier candidates: 20544
void TwistExpander_Naos::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    static_assert((S_BLOCK / W_KEY) == 16, "SquashInvestToKeyBoxes expects 16 invest fragments.");
    static_assert(H_KEY == 8, "SquashInvestToKeyBoxes expects 8 key rows per box.");
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 15U), *aFragmentB = aIceLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 15U), *aFragmentD = aIceLaneD + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1022U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1984U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 754U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 109U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 2U), *aFragmentB = aIceLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 7U), *aFragmentD = aIceLaneD + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1029U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1377U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1356U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1242U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 1U), *aFragmentB = aIceLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 12U), *aFragmentD = aIceLaneD + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 574U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1779U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1249U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 694U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 11U), *aFragmentB = aIceLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 0U), *aFragmentD = aIceLaneD + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 235U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1639U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 391U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 873U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 12U), *aFragmentB = aIceLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 9U), *aFragmentD = aIceLaneD + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 640U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1665U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1921U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 916U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 14U), *aFragmentB = aIceLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 6U), *aFragmentD = aIceLaneD + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 787U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 107U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1717U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1997U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 5U), *aFragmentB = aIceLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 10U), *aFragmentD = aIceLaneD + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1663U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 240U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1123U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1845U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 3U), *aFragmentB = aIceLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 2U), *aFragmentD = aIceLaneD + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 806U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 635U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1819U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 309U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 7U), *aFragmentB = aIceLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 1U), *aFragmentD = aIceLaneD + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1486U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1200U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1943U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 141U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 13U), *aFragmentB = aIceLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 5U), *aFragmentD = aIceLaneD + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1371U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1229U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 192U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 84U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 4U), *aFragmentB = aIceLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 13U), *aFragmentD = aIceLaneD + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1271U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 843U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 795U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1584U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 0U), *aFragmentB = aIceLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 4U), *aFragmentD = aIceLaneD + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 81U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 320U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 398U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1632U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 6U), *aFragmentB = aIceLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 8U), *aFragmentD = aIceLaneD + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1546U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 762U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1677U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 580U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 8U), *aFragmentB = aIceLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 14U), *aFragmentD = aIceLaneD + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1011U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1437U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 595U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1695U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 10U), *aFragmentB = aIceLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 11U), *aFragmentD = aIceLaneD + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1454U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1773U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 658U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1489U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 9U), *aFragmentB = aIceLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 3U), *aFragmentD = aIceLaneD + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 639U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1544U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1315U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 739U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Naos::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x95F4D06D5BDDDCA0ULL; std::uint64_t aIngress = 0xDCFDB7CE9D859180ULL; std::uint64_t aCarry = 0xE28ABE39261A8728ULL;

    std::uint64_t aWandererA = 0xAEDDE319C4E5E794ULL; std::uint64_t aWandererB = 0xEC005C397991BAB3ULL; std::uint64_t aWandererC = 0xCE230D7ABFBAEB1BULL; std::uint64_t aWandererD = 0x966D5B96E8CE4423ULL;
    std::uint64_t aWandererE = 0x97659F670DE12242ULL; std::uint64_t aWandererF = 0xBDF320E0C21E4D7CULL; std::uint64_t aWandererG = 0xB21D98E77F50B5BFULL; std::uint64_t aWandererH = 0xF0502F3C6BF73954ULL;
    std::uint64_t aWandererI = 0xAA17AE114062AD50ULL; std::uint64_t aWandererJ = 0x9F4B39C686B3DD07ULL; std::uint64_t aWandererK = 0xF4D217ECC22A5CEEULL;

    // [seed]
        aPrevious = 0xEF7B093DE4A01EA7ULL;
        aCarry = 0x9ACDE64A55B2B768ULL;
        aWandererA = 0x8B7760425965EF6BULL;
        aWandererB = 0xEF3EFA4F79619300ULL;
        aWandererC = 0xDD0CA20D883CC497ULL;
        aWandererD = 0x8B4E5EA57164D214ULL;
        aWandererE = 0xAD9C0D1559011CF0ULL;
        aWandererF = 0xA43F0D2B0CEDF1B8ULL;
        aWandererG = 0xF0F172562DABE955ULL;
        aWandererH = 0xD7028E0B185064E6ULL;
        aWandererI = 0x979A3411433F6BEAULL;
        aWandererJ = 0x832F7917C3662D9CULL;
        aWandererK = 0xE0C9BD545E3579F9ULL;
    TwistExpander_Naos_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Naos_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Naos_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Naos_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Naos_Arx::Twist_E(pWorkSpace,
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
    TwistExpander_Naos_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Naos_Arx::GROW_B(pWorkSpace,
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

// GrowA candidate 23 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 11945; nearest pair: 491 / 674
void TwistExpander_Naos::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6408U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5204U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2589U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 786U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6577U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5768U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1307U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6697U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1343U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5277U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2237U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1820U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
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
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3460U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 688U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7375U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4792U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 959U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 63U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1386U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1344U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1714U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 951U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1488U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 694U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 270U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 978U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 720U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 961U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 882U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1986U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 190U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1491U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1979U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 731U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 548U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
}

// GrowB candidate 23 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 11937; nearest pair: 455 / 674
void TwistExpander_Naos::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 352U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1329U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6459U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1773U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1645U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 136U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4084U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5958U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3953U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1460U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2861U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4661U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3109U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3178U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8169U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 893U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 638U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1026U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1038U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 665U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1313U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 564U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 290U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 935U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1145U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 277U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1161U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 337U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
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
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 111U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 854U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 378U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1879U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 503U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 394U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1992U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1618U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
}

const TwistDomainSaltSet TwistExpander_Naos::kPhaseASalts = {
    {
        {
            0xB11FB1A1452AED91ULL, 0xF5ADFC9118FA9842ULL, 0xEBD8AD70BC0CC8CCULL, 0xA23523E9440BDEE5ULL, 
            0x2D88B73296553CD6ULL, 0x393F4522FFBA7DFFULL, 0x9E5C17E1C60CFAD2ULL, 0xC708A35865EB6BA1ULL, 
            0x90722458ABC5C393ULL, 0x798E5A766CC674A4ULL, 0x929956FCF15EE6F4ULL, 0xBCDC901F8B7FEB67ULL, 
            0x2894173B57CA53DDULL, 0xFC3942CF3AD9171DULL, 0xA9C2522CCF770265ULL, 0xC7C0D87C95CC45BDULL, 
            0x5C7E61B51440C440ULL, 0xD8DDD0B9C1036173ULL, 0x2ADC70CDD53A9857ULL, 0x7654C28BFE267CE7ULL, 
            0x1D44E1A3A2B36A3CULL, 0x9F986B161B8C3823ULL, 0x0BA51047F824B6ACULL, 0x516973B79BF24662ULL, 
            0x67E1BDF58107F49EULL, 0xD8DB98E6456284C1ULL, 0x9DF79E75B6882400ULL, 0xC2FCC4CEFE7275D8ULL, 
            0x96F5235310CFFF7DULL, 0x77406D1215DFABE1ULL, 0x80AED25B7B3FB2C7ULL, 0x7DD0CA19BE2DEAF7ULL
        },
        {
            0x6F5977E4938AB514ULL, 0x910D6762CE09FEE2ULL, 0x7882B7ABA041E2D7ULL, 0x58D15045A888D42DULL, 
            0x5C483692EC4D32DEULL, 0x799D89AD4C6F172AULL, 0x4E977638E9813891ULL, 0x1B87593049CE2E37ULL, 
            0x27DDA6739D82FEA8ULL, 0xD29FA4540A748F9CULL, 0x66282551CDAFD583ULL, 0xC3256B00FCE6DE93ULL, 
            0x167AA0451C25C370ULL, 0x39A0C0BC497CBBCBULL, 0x69826065E183C8E7ULL, 0x273508840D13B379ULL, 
            0xEAA9694419D228BEULL, 0x9CDE8519E49E2AE1ULL, 0xF1AB684E854BB3A2ULL, 0x48B744165E2B0867ULL, 
            0x28D18C2A3D7A0718ULL, 0x93805206DA9DC224ULL, 0xD0BD9AE4B18EB0C7ULL, 0x23E9AB1E68B7285AULL, 
            0xF14650F1D0CAFD73ULL, 0x6224BDD40FB872FFULL, 0x540044D5532AC55BULL, 0x4749E1B0FA29BF1CULL, 
            0x8EDF8EF2CB747FF8ULL, 0x960CC9043D6E0635ULL, 0x3D797074560F2CB5ULL, 0x13A9A89691A42FA5ULL
        },
        {
            0x6DE924657B76A28AULL, 0x76F3EC4B923637C8ULL, 0xEB0868B8983ED14DULL, 0xBED9991B94A38A83ULL, 
            0x4A14869D63E7EE58ULL, 0x29A20A33A4FB9B2BULL, 0xA09793F70DFBB957ULL, 0x09FB5D0196975FF6ULL, 
            0xC7AC8BE5ADF9B2B6ULL, 0xA97CFF0217E226F3ULL, 0xCE0A65CE2F885DA2ULL, 0x621C09918CCBEFE5ULL, 
            0x6FDAC06600183AB5ULL, 0x85A4E9A323169E0FULL, 0xBE55CCC93D532778ULL, 0xDC54B0A303749154ULL, 
            0xE215F3F56DA6DB43ULL, 0xB6452EC0E31FD495ULL, 0xA8CB360A4E052826ULL, 0x02EBABCB0F77E33EULL, 
            0xD9A474E5D55F1780ULL, 0x574232282003A6F6ULL, 0x7E7B41A70915896AULL, 0xA5110D1FFE68C8C8ULL, 
            0xD26DD311A8137FADULL, 0x76FE74D60A5F4CECULL, 0xC80A6BF8294D63ACULL, 0xEA6BF69F7B0112EDULL, 
            0x695092B7DC015350ULL, 0xC1ABCD1377E5EDB0ULL, 0x4CF357CA0E4C357FULL, 0x6D1E4714B8059E21ULL
        },
        {
            0x29FDDD94A9CD0653ULL, 0x53266707B32E3F17ULL, 0xA7F0598284AD94B6ULL, 0x0B57931BB75FFA2CULL, 
            0xA855C773BA5BF260ULL, 0x5A19C9784CA0C2BAULL, 0xA95DD1DFB0D95B8EULL, 0x627CAFD6F07018CAULL, 
            0xB95502A6206999AFULL, 0x785D8E4A51843154ULL, 0xC213087143722B78ULL, 0x80BD5A40711AF724ULL, 
            0x6F5A817B3973D3A7ULL, 0x6DAD5A7AEB6E2D38ULL, 0xB16D738D8F835CDFULL, 0x4BBDEB9D9A5ADD85ULL, 
            0x8856E7D3BB5AD358ULL, 0x135FEBAE3E4E7B7EULL, 0xF96A8B1AFBDB91BDULL, 0x63CF548F77745A69ULL, 
            0x64DB471E3BD60672ULL, 0x0C061ECA4145FF08ULL, 0x103C8A762ECCA0E6ULL, 0x03895150DA4CE739ULL, 
            0x6AC6E99E666CE381ULL, 0x044944AA552F5055ULL, 0x125991626FA16E38ULL, 0xC4301BF45A5008F9ULL, 
            0x0E6722B924E1E5C6ULL, 0xAAE706600F0F9A3AULL, 0x29C17B13A307B4DCULL, 0x5ACC31745C88793CULL
        },
        {
            0x7332F6A08A1C4223ULL, 0x28EE7D11A6A1EECEULL, 0xEBC0E94DF70BD207ULL, 0xB232EC4F0A55D044ULL, 
            0x1D49B4EEB5399C6BULL, 0x833772AFD8D4CF57ULL, 0x0F18AAF018385AD1ULL, 0x5C7E054C9A9C40C6ULL, 
            0x554EFE3CD225F2EDULL, 0x82EACC41590AA787ULL, 0x3FDFFBC9CD75729BULL, 0xFB0278FEDA9EDC66ULL, 
            0x568C15FCDAB92E1EULL, 0xD691E73424194E7EULL, 0x651DF4549212ADA0ULL, 0x2F446C5ABD12AD08ULL, 
            0xF7286D3AFD96DD24ULL, 0x3A301C770C6EE75BULL, 0x9CDD4D5FEDEB2EC4ULL, 0x6D79F54FB5A989ADULL, 
            0x25A024EA7231A511ULL, 0xD4A5C00BEC651515ULL, 0x9C123F7D657DCC8CULL, 0x8F65599EA46A773DULL, 
            0x6627BEF6D8657E7EULL, 0xEC76F1C7555F5C07ULL, 0xD539DB3BFCF6B6DBULL, 0x1B16A6E0A20D984DULL, 
            0x8224E989E2D38156ULL, 0xB51DC23980251C4AULL, 0x0049E006704F41B4ULL, 0x84C9F5778D4EC362ULL
        },
        {
            0x0BDAD77604CBAAB1ULL, 0x19D4EDD356BBCF9CULL, 0xBAD80BBE10090397ULL, 0xFB432F798FC34697ULL, 
            0x3972444C16CA6894ULL, 0x1332FB0668A4339EULL, 0x5C6363FF5D531205ULL, 0x2A6B7F5AACB0BD3EULL, 
            0x6C972A7E1FC68D2DULL, 0xF24A872798C2C54DULL, 0x7AC516EFC5DFB7C3ULL, 0x4D04028AD7086483ULL, 
            0x60D2BC8AA7523B0DULL, 0xE7D69F9C6E1A22E0ULL, 0xAD0D32A94155780BULL, 0x5E95FA4A288F950DULL, 
            0xE44B66CB64BE9D61ULL, 0x5C6275486952887EULL, 0xC9D36CB4868EFBD2ULL, 0x37789B780FDB6FBEULL, 
            0xEC99804226DDE258ULL, 0xCB8FC45AF30A54B6ULL, 0x7346CF396F035D4FULL, 0x5F2B4BBE61650A97ULL, 
            0x085AE63408F917F0ULL, 0xE502062741DA7334ULL, 0xA9CC1610359BECC0ULL, 0xDF7ADF7E10109C28ULL, 
            0x4BCC4AE357C68B8DULL, 0x932E6E36ED1E8AB2ULL, 0xD9FECEBB730FCCBCULL, 0xB21EAEBA289FC8A8ULL
        }
    },
    {
        {
            0x834EF81FA6A132F0ULL, 0x625B06CCADCAE02EULL, 0x5C806F4908EE0D4AULL, 0xA9FE4A910F45CA98ULL, 
            0x5F78FAF0672ED5F9ULL, 0xEF0EBC222F1E6049ULL, 0xF90BAAC0F34001AFULL, 0xAA6A4D31D30E1933ULL, 
            0x9F020DC0B3A46A6BULL, 0x0E7329F6AC2A5C91ULL, 0x5EB83F1F3F491BDCULL, 0xD0ECA1C1849ED29DULL, 
            0x6259D95B8FC90255ULL, 0x58D581F880D83FA9ULL, 0x62A35F2A8A9A9E36ULL, 0x1AB435DD58C6657CULL, 
            0xC65EE72245D79106ULL, 0xA70AB3493F0D9038ULL, 0x5533E2C0CFF19A20ULL, 0x56D3F2AFDDF1FE42ULL, 
            0xA2E91400FBE874E8ULL, 0x48D954C4176CE8EBULL, 0x2743819154B89B48ULL, 0xEC013DEAF8C0AA53ULL, 
            0x5062A642D73946E1ULL, 0x554BFFCF1527925BULL, 0x45FCA696F7F55863ULL, 0x339CE4BD3AF761F1ULL, 
            0xDA388C301555CA0BULL, 0xD2E0133B01FDA661ULL, 0xFA697811082E20F7ULL, 0x022AC63FB140D4AFULL
        },
        {
            0x60B40B9E80E24C9CULL, 0x5BF2A430293B2939ULL, 0xFC5D6DADF3AAFF1EULL, 0x583A8275A0F03B37ULL, 
            0xE42DA45D73F9EF02ULL, 0x353D8DEAB66DD6A0ULL, 0xBC11D8FA5A11B11DULL, 0x1F62322CF15A01E7ULL, 
            0xF59C18A4AC824918ULL, 0xEE040D19CC3AACFEULL, 0x87DAD55C97331416ULL, 0xE126D80BD18ED2F3ULL, 
            0x073ABF9229CF97E1ULL, 0xF0B49233C379551EULL, 0xD6B0DF6CC114C619ULL, 0x3CA1336A72726537ULL, 
            0xEBEF60AFF2694F0EULL, 0x611C52965AF5B340ULL, 0x096CF1CBD1F02A6AULL, 0x8AF2292D7FB5DA92ULL, 
            0x2C9F32A61B40EEF9ULL, 0x8E00BB1D3B3DE681ULL, 0x9EADF7379445BF24ULL, 0x9BB25057CAFE47F0ULL, 
            0x193FC70F8CC812D9ULL, 0x9FDA71DC4198912EULL, 0xDA176A8F6F24376AULL, 0x8F9B57009D677303ULL, 
            0xDBFEECFC44D6E211ULL, 0xE84D9748086FA8D9ULL, 0x6C2EDBFDB6EDBF48ULL, 0x5D4C21880A1D1D5AULL
        },
        {
            0x4D3276B920F9C1F8ULL, 0x818D78D2FE072A23ULL, 0x43D47A149AF71814ULL, 0x72A3C010449AF675ULL, 
            0x388218CCA803A62BULL, 0x5CF4C6DF622133F4ULL, 0xA1374A7270F8EE19ULL, 0x22B7D8574B54516EULL, 
            0xA88C57005BD8C094ULL, 0x25CF6D6F5B302E40ULL, 0xB3D8E00003F73C03ULL, 0x443E933BBA846103ULL, 
            0x64D7458670045326ULL, 0x2066163ED8DB12CFULL, 0xBFF8DD3FDDC03F49ULL, 0x878A5FF7092F1D9DULL, 
            0xDA34E1FEF3FB1CE2ULL, 0x9C7473EA15A5B2FAULL, 0x1C24A6C3B9EE07D5ULL, 0x2B798ADC8DE88324ULL, 
            0x1F22A3F2DD5014FCULL, 0xE0E9629B27FC4F82ULL, 0x7423F824921FF743ULL, 0xA817744144D9E809ULL, 
            0xE4D1B9CC0C418F39ULL, 0x777015A108258FF6ULL, 0xACEC28A0353F4EFFULL, 0x6288EBEF933EB603ULL, 
            0x20256E36FD12572BULL, 0x6181A27CEBC3775CULL, 0x0F0319BE351E44BCULL, 0x118F4F5EDA92BC84ULL
        },
        {
            0xFF9884A1C8AF8451ULL, 0x2F5719DC5B73A894ULL, 0xF407FF859AF960C2ULL, 0x1A9ECF073EFA5F79ULL, 
            0xBDA4FB967CBFD96BULL, 0xFDD7254815239D45ULL, 0xC89DBC9EF8911C34ULL, 0x5FA8595F0D778A6DULL, 
            0x876EA73F4D8185F0ULL, 0xDF22BA258C808E6BULL, 0x26AC227481C3F47CULL, 0x6621E1D5B2147E34ULL, 
            0x1C4BC8106E0E079CULL, 0x418DEF5DFB9069BAULL, 0x109CE7411C2654E0ULL, 0xD3A0EE93AD7F71CBULL, 
            0xF2434620D7F6E4E5ULL, 0x8FEA6D010EF67AEBULL, 0x6A9A68A8CBC9DB24ULL, 0xECB3E74DB8FCAA54ULL, 
            0x64605D26A8421587ULL, 0x451F41DC9594A9C4ULL, 0xB98BAAA8FB073396ULL, 0x3578C553017424C0ULL, 
            0x47782CA5B2E5601AULL, 0xF6EDB1AE3F3FE753ULL, 0xA77B6BD5DD507A2AULL, 0x1BE10E9A68FB5783ULL, 
            0x801B6479C0FDB152ULL, 0x11953DCE3A5947FFULL, 0x57204697DC4294F8ULL, 0x98E894EDF1ADE827ULL
        },
        {
            0x435264547501F330ULL, 0x1041E157F2D7251AULL, 0x62544B209E8FEE43ULL, 0xB0424168C9621085ULL, 
            0x7AC9631EEA7EFE61ULL, 0xFED5C2B9E7CAF40EULL, 0x409F6FA041C293DFULL, 0x0F22B026B0E65F30ULL, 
            0x6A59A6CC8784E559ULL, 0x62C56FEB6E28E2AFULL, 0x8CD9F022B3439812ULL, 0xA632873BC3E52249ULL, 
            0x2AE58502E1917DA9ULL, 0x9E2FA1A774CD6F47ULL, 0x434BB4C3AC1508F6ULL, 0xF115AA81644432DFULL, 
            0xE8092279CC2E7268ULL, 0xC5E42482CBFF6A55ULL, 0x6D4FDAD54472A78FULL, 0x97FCAD84A6C7D97BULL, 
            0xA25972A57EDC48ECULL, 0x9E7F3E22C058B4C0ULL, 0x4525BBB87E86EFF6ULL, 0x57AE9A2A65CBE425ULL, 
            0xF1A71C599B01A04AULL, 0x28720A7142C0F66EULL, 0xFBBE89B57CD95255ULL, 0x00B2F23561050C7EULL, 
            0x451B8042FDE97ECAULL, 0x7C45F4958E393EFFULL, 0xC1B990F8EB8A5253ULL, 0x01775CEA19CEA052ULL
        },
        {
            0x88A94361016EA814ULL, 0x8D6BB98CE1A50FB2ULL, 0x8E8DA0712D3B24F6ULL, 0x90409BCE29FEF780ULL, 
            0xB92E51D7B4A3DD3DULL, 0xE19ACAB909FE0C8FULL, 0x98B9DE5C27D80D78ULL, 0x94C58C68D6251046ULL, 
            0xD8311B167A65AC6DULL, 0x0544B1F5081AC2C6ULL, 0xC7CA7664C42BD5FAULL, 0x93A8E324CAB234B1ULL, 
            0xF4798FE57CA2ABC1ULL, 0xA535BA275B3D6712ULL, 0x8EACB5F841DDCCAAULL, 0x95EA2B05844700CBULL, 
            0xB6624AF1B26383E0ULL, 0x82BA0BB36595F163ULL, 0xFA4CDE2796D0A828ULL, 0xCEE108A09346E8E7ULL, 
            0x8F3127FCACD63F22ULL, 0x592CB226738853A4ULL, 0x10761E94F5839224ULL, 0xA55CC8CD020C8C8CULL, 
            0xFF95783170D3A9F7ULL, 0x4AA114DF91B185A8ULL, 0x9A2766ECE8D56438ULL, 0xD47EB05EB3DA5842ULL, 
            0x08659892284D48B3ULL, 0xA96008B12359E254ULL, 0x354C817E37C7F4D1ULL, 0xB52119B78CC23AF3ULL
        }
    },
    {
        {
            0x3F7859D98F057583ULL, 0x6053A4FD933E72E7ULL, 0x16EC889BF7FAA28AULL, 0x2B845187ED79209AULL, 
            0x41DBC3445A982AC0ULL, 0xE25CA3E040D345E8ULL, 0xFD39B788CA02F50AULL, 0x8E57A2DE7FB2DF40ULL, 
            0xA6B3FD3152490305ULL, 0xCB91C12E8E4B034BULL, 0xA70BB3892B6A4906ULL, 0x837D5607F33BB1FCULL, 
            0x11CE75BBB9D57388ULL, 0xE3E5211AE02487DAULL, 0xD285CD1F7613E1D5ULL, 0xEF654FE6BD3D2229ULL, 
            0x375B46D87C4DB9FCULL, 0xF6739CE31803AAD2ULL, 0x63860CFD57A92F50ULL, 0xB223E203169B00ABULL, 
            0x1AA09F19402950BFULL, 0xD3A46D33E2D087ACULL, 0x4F24293C8EBB432DULL, 0xAE007B6F3817A775ULL, 
            0xFCE723E114C2FE14ULL, 0x30EE31399ABC0F84ULL, 0xD639D40BB253F47FULL, 0x9A81974DEA1C1103ULL, 
            0xD59134B55E08324AULL, 0xCC1E0EF9A87D0307ULL, 0x549255A167B5E758ULL, 0x248084932F905A95ULL
        },
        {
            0x3D4B648D1B7548EEULL, 0x0E0B29B74B56C767ULL, 0x815FE5B6234426A5ULL, 0xB92596505D7088B4ULL, 
            0x1E924E237B9003A7ULL, 0x2A9B21EDA1DCE779ULL, 0x250672728E08286CULL, 0x9BC3403174688FBDULL, 
            0x48409DBF113091CCULL, 0xDD997376E1EE7A26ULL, 0xDCCB1132DF47EB7BULL, 0x9CDE754D4E555DFEULL, 
            0xFEB2D6C4AE53CBB9ULL, 0x415DA3B09F6E064BULL, 0x7131AC79AC5B5545ULL, 0xE8854D1E463408EEULL, 
            0x406FD6983791D5A1ULL, 0xBD1841C9FB495F92ULL, 0xCA237AFDFCFCA968ULL, 0xA07A9B470CAD3AB0ULL, 
            0x73783BE990AFD09FULL, 0xC20159E2D923C834ULL, 0xB7CCEB8C7A66DC25ULL, 0xF84424A7F216ED79ULL, 
            0xB7299ABC5E643BF2ULL, 0x12A120014EF90C62ULL, 0xE4A17327990E2332ULL, 0xAD9213F9DCB3C830ULL, 
            0xBA0C5DD5B01A0C45ULL, 0x240E70F764B633EDULL, 0x12C15A2AD4F9523BULL, 0xF4B8CF750091E308ULL
        },
        {
            0xC0B72B0DEB989EEEULL, 0xE05D61ADC2CF7962ULL, 0x7FABC2D0E093ECC9ULL, 0x07B6070AAD7EF393ULL, 
            0x13585987B3FA0A94ULL, 0x7ACF893D2CD020FEULL, 0xBEF6E7E1AE2806B8ULL, 0xBAAF49C89BC8866CULL, 
            0xF1368CAAEBF356E3ULL, 0xE9C17F75ABB70CE6ULL, 0x286EEF13DB40E2F3ULL, 0x537773CBBFF82388ULL, 
            0xF1B6C1773AB268B7ULL, 0xD46D9A7DB61434FCULL, 0x1CA384A30CCA0D69ULL, 0x74BA5C572F6D6AEFULL, 
            0xDCCFBD918E7B6D0CULL, 0xDAB3DE7085B4091DULL, 0xF325080A1D112FF4ULL, 0xE7EB419CE72E3E5AULL, 
            0x724BBC11E329AA85ULL, 0x689039A1E49C77CEULL, 0xF6E9F6B0AFDD2929ULL, 0x0979A894DC881393ULL, 
            0x3807CE095550EB85ULL, 0xACC2299448FA8F84ULL, 0x1EF90A3FC2952377ULL, 0x57589BE981A8E7D7ULL, 
            0x872777A9EDD96A03ULL, 0x9C816D59B918382DULL, 0xDEFBD430CAEA8E75ULL, 0x301A31A2A546BA31ULL
        },
        {
            0x8281ADE6B32A2632ULL, 0x58BE58FFC55B5BF9ULL, 0x472F633F33316B3EULL, 0x44A425B9772D2D6CULL, 
            0x939A28556DDF2143ULL, 0x5DA2F6D40512772AULL, 0x1494C95754A7FB9BULL, 0xCC84F38191C04DADULL, 
            0xC97AD7F5999FF7D5ULL, 0x8B0AC30039B79133ULL, 0x4274FA0C3205F813ULL, 0x73776A76DD3DF755ULL, 
            0x5CB0323F7DBBD071ULL, 0xA58FEC8D03686A06ULL, 0x486BA5D50ECB0174ULL, 0x3A9713042C0F30D3ULL, 
            0xC6DEF4202ABEDCC0ULL, 0x9DC36E4196D64F0FULL, 0x48BEF561CB19638AULL, 0xB3872EEA5A92AF34ULL, 
            0x6A93E10FBDCBB67AULL, 0xAABFC30E64C0E2C0ULL, 0x5CFBCD73458EE0ECULL, 0x7CCCD925EC6C57C5ULL, 
            0x06AC4EDD0758DB4EULL, 0xA3DC49611E27BC68ULL, 0x0977162830160088ULL, 0x3780079F5C92AC8BULL, 
            0xD1D40F791E5606A4ULL, 0x2DB5EED4A3780BEDULL, 0x1C5A173E7E42FEBFULL, 0x052304C3AB6DDAABULL
        },
        {
            0x9E93098A9633275EULL, 0x2B61B5793CBEEB74ULL, 0x71E41A0E1944F0CDULL, 0x99568B3245C64063ULL, 
            0xEB1DF5D93863A78BULL, 0x802D9060697568D2ULL, 0x2D09EE5CA34B592DULL, 0xFC7914C53704BC4AULL, 
            0xD589AA3582473348ULL, 0x173F0175058C4287ULL, 0x85E5717365F922D6ULL, 0x5E09D92350FC1DB3ULL, 
            0x66537D99599ADD87ULL, 0xF4A8769D8465D6F9ULL, 0xA04CABED89A0E382ULL, 0x912790E0D585E0DAULL, 
            0xBDA34B63558B6C1BULL, 0x0F91CB9CE63F0B07ULL, 0x0B5FCA0EEDC5C852ULL, 0x3805DEF7A082C9C1ULL, 
            0x08B4256714E167AFULL, 0x14B4087A8B950632ULL, 0x92FDD0443DA73A46ULL, 0x8E619A2C7817AB02ULL, 
            0x9B27A1C327C06FF3ULL, 0x22B173F72BB435C2ULL, 0x34261CDECC6D01EAULL, 0xCE4C9688D401D684ULL, 
            0x8894703F046D19BCULL, 0x499642873A0DCBCFULL, 0x84CE97CDF3CC1267ULL, 0xE318906E2257717FULL
        },
        {
            0x965C3FBFA434BAF4ULL, 0x509ECCB01F8818B2ULL, 0x4FD55B10ECBDE0A0ULL, 0x66C4D61B37222DEFULL, 
            0x15FA9D4F3410AFADULL, 0x415A97EA3AD6ADA4ULL, 0x68F5F416ECC55ED4ULL, 0xD4C3804BB5F93EC6ULL, 
            0xBC0A036CE2DE8077ULL, 0xE412D44994CBB08EULL, 0x813FCA207D918D91ULL, 0x9D94B9165757F304ULL, 
            0x0A7C5CEBFD31CD34ULL, 0x4EB85ECD4D52D929ULL, 0x199025B09AD73CDCULL, 0x6203200911B0DADEULL, 
            0x5757A867942C8331ULL, 0x1C9137EF395995EFULL, 0x780E68317FF0A4E0ULL, 0x6253A09F7C6E0F53ULL, 
            0x76992BD82FCB6A5AULL, 0xABA678FBD605530DULL, 0x53D2AE17787A9312ULL, 0xA7C1526E006A184DULL, 
            0xDE68F43A8F1B40C6ULL, 0x2D0078B189148C5EULL, 0xE53FA73EB83BBE95ULL, 0x315C3E5D2A2E5DEFULL, 
            0xD89D09DAF06A83E1ULL, 0x341E2977EFCB50ABULL, 0x4AB7807DB3810FDDULL, 0x0C97037C322D323BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Naos::kPhaseAConstants = {
    0xB018557ACB1B7EB1ULL,
    0xC7FC7284AC149E19ULL,
    0x678544192C73AB1BULL,
    0xB018557ACB1B7EB1ULL,
    0xC7FC7284AC149E19ULL,
    0x678544192C73AB1BULL,
    0x95E0AA2CDC681D44ULL,
    0xA057169799C9CCFEULL,
    0x18,
    0x68,
    0x64,
    0x13,
    0x2C,
    0x09,
    0xD8,
    0x50
};

const TwistDomainSaltSet TwistExpander_Naos::kPhaseBSalts = {
    {
        {
            0xB516CDE2BC770105ULL, 0x805D8D41A72EDEFAULL, 0x16A637967A39F9CEULL, 0x785DBF9E94F5DDA7ULL, 
            0x8122A62928765D0EULL, 0x33CC3B82C8341B2EULL, 0xF2082EAEF934EDB6ULL, 0x113D136B893004B4ULL, 
            0x6EFE28D9C1817B10ULL, 0x43809143A4134C3CULL, 0x2B9F8CE4013D2CF5ULL, 0x744C4E5227BC27F5ULL, 
            0x69BC68EA6784E8D5ULL, 0x7B9FD5EB56FE5DC0ULL, 0xFDC94E58DAC51B48ULL, 0x8382DAB616125D20ULL, 
            0x2BF5F52BB5AAB85AULL, 0x38CDD21D57B0377FULL, 0xCA7EDFDD157C55BCULL, 0xAF69D522472FAF29ULL, 
            0x1DFEE150DB043081ULL, 0x8F3C15ED18AAF7DFULL, 0x2EEB0A06513FA9F1ULL, 0x0447589163142666ULL, 
            0x663AF646F50C457BULL, 0xC368E4EDF81B4D16ULL, 0x0E58556DF5B7DB4FULL, 0x0BAB4897F0B37A93ULL, 
            0xC897F8CFF4018FD6ULL, 0xA3A9C57C5354518FULL, 0xBC2CBC59D378BCDAULL, 0xE7FFA1AACED96BDEULL
        },
        {
            0xED320273CF20A657ULL, 0x91197D5F57BADA4FULL, 0x3FD32F30DE49CC13ULL, 0x7FE65C9EC0ECF881ULL, 
            0xD23191BF04D2A60AULL, 0x34F894659556F2E2ULL, 0x116010A84F02C8E3ULL, 0x8E9118B0C8C74B93ULL, 
            0x81DEFF80F74C4BB8ULL, 0xB30D84E9F3B1235CULL, 0x91A0441416946249ULL, 0xC0239A0DE59030B0ULL, 
            0x6F201935BDD3CD89ULL, 0x11A79F211BF30D63ULL, 0x07853ABC6FC54C60ULL, 0x085E278414BE0FE0ULL, 
            0xEAAFAEB5A8F2F71FULL, 0x5738FDCBB4CC7808ULL, 0x0D94D11B4CBFC464ULL, 0xD9D4BFCB3E67306CULL, 
            0x72DDB5A10F38FC30ULL, 0xB23517C0B7210C68ULL, 0x4B8C6E8701790C86ULL, 0x2A57A643F3EFD4FCULL, 
            0x5CF5238B1CB81C94ULL, 0x500D00A5CB2A4FFDULL, 0x929620AA64C9BEF7ULL, 0xE51DB46E59266B48ULL, 
            0xC39198AF1EE88C34ULL, 0x491E7777AFB396E3ULL, 0x7D3A25C8AB6D062BULL, 0xDD1EECB27C82C622ULL
        },
        {
            0x228826E6B76BEC7DULL, 0xF6570B0C94105523ULL, 0x5FC9E3439ACFD56CULL, 0xB3391A604E45FB91ULL, 
            0x6A9FEFDB9CBF6D4DULL, 0x56DD553A51596C66ULL, 0xFC629497838B5712ULL, 0xB6BAA2E1FBB24ACDULL, 
            0x3692C9817289B7CCULL, 0x647E224EA7361061ULL, 0x536EC036DF2CF2BBULL, 0xD9990F03B45E1ACEULL, 
            0x0FC2A4557EE7069BULL, 0x5100F7DD17FEC6D8ULL, 0xA58B5C1F8CADC9B3ULL, 0xB0AD6311B8E1ED40ULL, 
            0x629DE2957937572CULL, 0x4FBC3956F6286458ULL, 0xB9B30B4C7AC84222ULL, 0x2EBE577213A8CEAFULL, 
            0xCA367D829CBED6E3ULL, 0x7FDF0B5B201806F5ULL, 0x83730E56B64D6056ULL, 0x427778A9FA155669ULL, 
            0x9582791F61ABF09AULL, 0x7194349692928583ULL, 0x7C59B105C3C269E6ULL, 0xB7422318F897D310ULL, 
            0x62B483B254DA22DFULL, 0xAC587594C0DD3D2CULL, 0x5F1BBC87FEB9BDAEULL, 0x75CD138A12470160ULL
        },
        {
            0x8F4F8D3A8AFB29F0ULL, 0xB87D612BF228E0E9ULL, 0xB453867C4517FEDFULL, 0x339EAF98257485AAULL, 
            0xFAF9F5BBB7705274ULL, 0xE59BAD8E435B81A6ULL, 0xB70154769FFA1AA7ULL, 0xEB51C599DCF5D793ULL, 
            0x25369608ECBB58BAULL, 0x7650445F1B677E29ULL, 0xA34F2C8FBC424273ULL, 0xC0250BBD749E38DDULL, 
            0x1FAE9F2BEA0176CBULL, 0x3A8C4C4878C7750BULL, 0x51AF432EB42B7B57ULL, 0xA7A0B4CD6537B7B6ULL, 
            0x325E3E106327B6BFULL, 0xD4CCBD1B8331A5ECULL, 0xA74B62B9447B23F0ULL, 0xCDAD55E599599F8DULL, 
            0x56A169233A7FDD16ULL, 0x10D365D10EF98DC3ULL, 0x114B28EA85BF4F55ULL, 0x75F63618F5027735ULL, 
            0xC4AE8DD00FD84181ULL, 0x3155823085EBE081ULL, 0xFC14D37F44D115E8ULL, 0x1D86CB3AAA54826FULL, 
            0x0C94C571CFF49161ULL, 0xB7096F3D177E64F6ULL, 0xF5ED8DD07993E544ULL, 0xBE9751F2EFE44166ULL
        },
        {
            0xDDDEDF5B206EC0B5ULL, 0x5DBAC888D5EC1B14ULL, 0x412A355CEF75D4F2ULL, 0x9383589FE601D98DULL, 
            0x2005B616FE0DE0EDULL, 0x406CB7D324ED835DULL, 0x2E93A5EE338E8336ULL, 0x9EF4FE2D9088FE1DULL, 
            0x9F419A92C0918FE6ULL, 0x2D3CC9218805EA57ULL, 0xF4C24FE01480EB47ULL, 0xA4F4C1BAC2B44EDEULL, 
            0xD537B95164D99428ULL, 0xFCCB14160C10D1B5ULL, 0x63B0FCD17F670122ULL, 0x6F1D64293891B0A4ULL, 
            0x51C5C24FCEE09F05ULL, 0xCB3807E89AFB8FD5ULL, 0xD95504C538438D6FULL, 0xE78F024ADB620F27ULL, 
            0xC5FAE314F5B0091CULL, 0x3883FA06FD2680DEULL, 0x44DC774E4E1F4500ULL, 0xC8507EF9C2355A6FULL, 
            0xD9F008A555297885ULL, 0x5880C6F7C8FAB79EULL, 0xBB034C03B1A8176FULL, 0xDE25C95A16320CE2ULL, 
            0xB739CCE3F7A55467ULL, 0x64683EB917F467FCULL, 0xE11EEA9F25B75740ULL, 0x3C2B937B685AA34CULL
        },
        {
            0x0E77CA5632397DA0ULL, 0x40671DCC52614060ULL, 0x23E3F0DF206962FAULL, 0xDF4F4E5866166DB4ULL, 
            0x025F255DAF5EF445ULL, 0xA1A176D9820FDD40ULL, 0x076984C462942932ULL, 0x7455CBF43A90AE53ULL, 
            0x0F15489C3DF41E99ULL, 0x77E76D91601D9BAEULL, 0x7A52B8E8D1451D2EULL, 0x4A2D5C6CBDA59F05ULL, 
            0x0C4CE50AFD441D7DULL, 0xAC4C407511399DD8ULL, 0x3420F5D9BB985797ULL, 0x56AAE3FD107FE80CULL, 
            0xDB89F9C4111FECBBULL, 0x597499B462AC7C6FULL, 0xA76E1B4A5821DF4FULL, 0x74EC6E8AEFD7804DULL, 
            0x8BCF34895DF5EA74ULL, 0x56DCC83D7D2F2B2DULL, 0x3A29F506BC6A58F8ULL, 0x4A445B68DACB075FULL, 
            0x5164C9549FABB25DULL, 0xC9276892644BBB48ULL, 0xB62FE160C96C5A07ULL, 0x5C023AC58AD10A52ULL, 
            0xCB84FF655EFFF986ULL, 0x6A5ED90D7901F779ULL, 0x394DB961E7296EB6ULL, 0x4806A41A90F67C7EULL
        }
    },
    {
        {
            0xF52EDC802F1ACFD9ULL, 0x2E3F61E2125B0BC8ULL, 0x131D104BB53902D8ULL, 0x4A2556E900B1A24CULL, 
            0x47DF4DB92FA8A84AULL, 0xA431A798442A5C85ULL, 0x8044C417DD3F71AEULL, 0xB5EA96EE8239CE46ULL, 
            0x13401EAE7724B480ULL, 0xF8D7BA86F652AE05ULL, 0xC14FBAFF2B732EC5ULL, 0x5DEAEDF7EA6CC263ULL, 
            0xE9433D760F314AC8ULL, 0x785C3F0F74096D18ULL, 0x9E677760F2C45D6FULL, 0x0890DB2DF1357E9EULL, 
            0x01581ECFCB6A69C1ULL, 0xF413882D55022B5EULL, 0xF1D8C83EFAE8C76EULL, 0xC6206DF54071D6E4ULL, 
            0xC58C640CAD70BFAEULL, 0x55470706C8ECB136ULL, 0xA521815C9A1F8F1EULL, 0xD52CC75A88D0F050ULL, 
            0x6E17F35E559FE794ULL, 0x1BDA27FEE2776A7DULL, 0x928CBC2873BE5B5FULL, 0x20B500E2575332A8ULL, 
            0xE90BA3706BA109CFULL, 0xAA62DA8F0F9CD37AULL, 0x6B04579914553450ULL, 0x40353021807B2075ULL
        },
        {
            0xF4BF682C1C0AF4B9ULL, 0xC86C903BDBC322AFULL, 0x79B77A73417DBE9FULL, 0x6D3BE683E9793516ULL, 
            0x350A0D64CA7847FEULL, 0xEB87863083897F41ULL, 0x9D4C39DADFBB364CULL, 0xD48C5BD2B64DC20DULL, 
            0x2FC18D1B8E0B9539ULL, 0xF1AF9F2FCE511DA4ULL, 0x16E60CB04FB97738ULL, 0x9E8D87B256A18E9EULL, 
            0xCE25B80DFDFBD015ULL, 0x6C953983349AAAF8ULL, 0xCB4C70C3516A3122ULL, 0xC91D4CB6B5724BDCULL, 
            0x7C64BD920B2DBB68ULL, 0xF40973F3ED1FDDCDULL, 0xC749C25F063AA9F8ULL, 0x84F11FD2A2F5BB31ULL, 
            0x5968BBF65C2D8407ULL, 0xC27FD0A8B033C185ULL, 0xFC2B7F0434097BA3ULL, 0x931B4465E8216FBAULL, 
            0x79B3EF15BA486FC6ULL, 0xAEABDBC3F9488E37ULL, 0x2205D911E85D5FB4ULL, 0x0AA62E18AEF25357ULL, 
            0x0A9565041EE900B9ULL, 0x5CEB80A771541829ULL, 0x83699D1CDF98EC20ULL, 0x1FB99DCCD526F4F7ULL
        },
        {
            0xCF4A5888A8B0E7F3ULL, 0xA662265447B00959ULL, 0xA2B4F3ED6B546D6EULL, 0x9D7118DE77B6E5A6ULL, 
            0x8A1877BDC04FFA82ULL, 0x654EF67CE1459FFBULL, 0x9C5B08D2DBC6B11DULL, 0x7D763830871A4699ULL, 
            0x4323F88E35CAFC7AULL, 0xC208AF946341C77AULL, 0x5DD2F0AA31D75E77ULL, 0x448DD3F08E6A7AEFULL, 
            0x62E664111C922E7FULL, 0xF18DEDA7FEBF2ED3ULL, 0xDFF7E86ED1A09571ULL, 0x87A69F871FA37384ULL, 
            0x1CD8C9D7138D5440ULL, 0x385198C0B53846C8ULL, 0x7EA6055616AF8636ULL, 0x31DDB6072C05FBB6ULL, 
            0x323A53990B78CB6CULL, 0x381223EB60266380ULL, 0xA778EBBDC5A30411ULL, 0x5B0F41708FBF5D28ULL, 
            0xC0F703DDB4C4AA8BULL, 0x19443BA99A141122ULL, 0x7E21EBB37BFFB9F9ULL, 0x6C108FEBD91A7499ULL, 
            0xC262329C7288F550ULL, 0x6C5AE80B19B94AB2ULL, 0xC9472972F41C7B01ULL, 0x2284E5A963C33689ULL
        },
        {
            0xC0F01109A11BD092ULL, 0x1819AE2B33F4A9ACULL, 0x4CADD66176F1DA88ULL, 0x2FDD4E78DB41D0B6ULL, 
            0x2EB8FEF420E2556EULL, 0xEC45A000523A799AULL, 0x7096F15F155CEBC4ULL, 0x6F7081B800EA7345ULL, 
            0xDBEECEDD824CCCEDULL, 0xC5C7E396BCFC4216ULL, 0xC63090508A657726ULL, 0x7575AB7E1F7EEC41ULL, 
            0xBBBE276D6C28E2CBULL, 0xFC7B20BCC4B40BADULL, 0x948EC6F1A7CA4161ULL, 0x54AD3658CF2FFB59ULL, 
            0x76F68AFC20C872EEULL, 0xC75D9BF8ABBA60E0ULL, 0x3895699FF538531FULL, 0xB20794766FD38F37ULL, 
            0x0524286B1EBE99FBULL, 0x8BF55247BE39470BULL, 0xEA29D931CD3DA0ECULL, 0xA74A18E15E48DA17ULL, 
            0xFB8498FC494C85D7ULL, 0x9785274F7B2C73E1ULL, 0x0EC7B6E71C488E69ULL, 0x19CE4C8698E829F2ULL, 
            0x28BAB0420730BB09ULL, 0xA9862E92308955F2ULL, 0x405BB2A695C56E57ULL, 0x5D1D4F912DB99536ULL
        },
        {
            0xD6DD9DF2C2C77B98ULL, 0xC31CA8695D433D54ULL, 0x1EA5BA978590ECF6ULL, 0xD834E04E82B44288ULL, 
            0xA1FCAB6C0B2B4934ULL, 0x60A27DCA09EEEF02ULL, 0x3E88F09448E7AEC9ULL, 0x1BC1AF76B70841EBULL, 
            0x2C3AF93EFBECC6E4ULL, 0x592E8F887DB5EB58ULL, 0xEC5AFF5D16D647B1ULL, 0xCDFF422829873969ULL, 
            0x6D68656B588F02E8ULL, 0x0619764DB4BB5D9EULL, 0x944A96509E15AB68ULL, 0x73AD970FF8CE22A9ULL, 
            0xB8CD94C5AA47AB40ULL, 0x0830D4E874AB2CA2ULL, 0xF7CEDAF275E6DEE7ULL, 0xC04075AF85C09960ULL, 
            0x2991C53416938AC1ULL, 0x4C6CDBB6893B1C1CULL, 0x97DC46885149EF41ULL, 0xB6E10E5711F8ED66ULL, 
            0xB61F8922164E85D8ULL, 0xA021A691840C1C63ULL, 0x36F1D80CDD45371EULL, 0x08D05B931739B6F8ULL, 
            0x7D9E40FEB5BF00F3ULL, 0x335D0A42040B440FULL, 0xE4F5B7E3D8B9A0E7ULL, 0x4504A87178A7EC24ULL
        },
        {
            0xCD56E3FA05D8E1F7ULL, 0xAFAC5D4C8182743CULL, 0x82E1E267C39B2C10ULL, 0x020D49CAC36B44B3ULL, 
            0x2CE0A8CB62E08452ULL, 0xFA72BEA1BC6C4F2CULL, 0xDA083E1BE06339F9ULL, 0xC80036BE5784F4AAULL, 
            0x5F724CF17DBE1B0EULL, 0x911699BF99167677ULL, 0x441EB463ED890CF0ULL, 0x4987F54599295F37ULL, 
            0x2DACB7EB1E1EF629ULL, 0xD7CE15990E1C86F5ULL, 0x536D811C8F33215FULL, 0x4F635506DCB97E0FULL, 
            0xBBADE1CE9B8BCAC6ULL, 0x9D80BC8CD154E7EEULL, 0x552A9F35BE0492B9ULL, 0xC786262564876082ULL, 
            0xECAAB41B43D5C615ULL, 0xD3E92FC4415AFC04ULL, 0x10EBABFEB95642EBULL, 0x5B7136746BD1EFABULL, 
            0x758959817C3A8897ULL, 0xFF54B46ED44F781FULL, 0x23D54D3044727CA8ULL, 0x30B41885DAA984CAULL, 
            0x030AA2B31B09BC3CULL, 0xFF0A5E3B5097D4ACULL, 0xC93B569061DEFE1DULL, 0x36965D7537A41312ULL
        }
    },
    {
        {
            0x8888840F1D8651B0ULL, 0xB0C2501E34254D8AULL, 0x2A52A1A4C8208CA4ULL, 0xF78394418ECC451CULL, 
            0xB6E516B0E57472CBULL, 0x90D8749712FA081BULL, 0xD46B386EFC07E104ULL, 0xCAA214F4822154EBULL, 
            0x6346920B78D138A3ULL, 0x7C5A0CAFAF50CBECULL, 0x996671D0B999AED5ULL, 0x8E3B4237876B643DULL, 
            0xC29858EDB38F6D18ULL, 0x19D76BF89FE95442ULL, 0x0A5EA7CBD568A655ULL, 0x2D3CF53A514370A4ULL, 
            0x874FB39BBF8E337CULL, 0xC6D34D6EED774955ULL, 0xFFC7E51B92F8670BULL, 0xA379674A22C2C5E7ULL, 
            0x4925DB2DAEDBB620ULL, 0x64D5D789624468E6ULL, 0xE3D94B306115C6B1ULL, 0xE2F43B571679ED58ULL, 
            0x09361DD2043B4DAFULL, 0x45D4BA05249062D8ULL, 0x665EF74B75387692ULL, 0x24735B058DC07FDFULL, 
            0x5C82157047F4CF39ULL, 0x83FD7E9899889C35ULL, 0x9D06A0F2EAD38FD3ULL, 0x1E5B0E67D6D986DFULL
        },
        {
            0x050A7DA3DCD18DA2ULL, 0x1F2D8EBF0AF3BC03ULL, 0x6A80A2D2044911FBULL, 0xCFE8F3D3B607360EULL, 
            0xE67966C7E416A319ULL, 0xC263D55BCCB83FB0ULL, 0xF3259100B88F5C1DULL, 0xD58D45BAF6951630ULL, 
            0xB0A734E6EC25DDC2ULL, 0x490E8EA4FB9EF87AULL, 0xB8B6B494AF3320A3ULL, 0xBFC44B7CC430414BULL, 
            0x620B0B22B9016B52ULL, 0x07C041F9B05E81F1ULL, 0x2A21FB01C7AE5EEBULL, 0x1497487A6DD2A7B9ULL, 
            0xC5CB8C3F658F2E31ULL, 0x4B00E4CB2D9909B3ULL, 0x97CB04DF0510E550ULL, 0x27B89172FFA641EDULL, 
            0xEB41323F58F71E1AULL, 0x88E2909FB9F9C9DCULL, 0x2BD68FA0A79ED43CULL, 0x2FEC0E07C1D666F1ULL, 
            0xD024A8224B443E3BULL, 0x9BFF87C0E0CA7749ULL, 0xC4B988D098227D61ULL, 0x258EF6DEC7E0B9A3ULL, 
            0x76772525AE17568BULL, 0x8E76B23D4740385EULL, 0xC30806FFBEF4FC95ULL, 0x070CAA5988814DF1ULL
        },
        {
            0x1A82259521825A0AULL, 0x3F80F7C4729CD150ULL, 0xA390B92D6FE50549ULL, 0x5F6ADC362D345590ULL, 
            0x0BBB6ECC8E79664DULL, 0x1249D5A9C37D2FC7ULL, 0x490FBCCE620F8ADDULL, 0xFA0AB6D84086A62EULL, 
            0x22E9CC669CB482EEULL, 0xE6BCCEBCFC0C706AULL, 0xDFE409C6D49EB54CULL, 0x23B17C28D56B5E88ULL, 
            0x6A36A8EC2053F419ULL, 0x83AE3F86A3FBF6BBULL, 0x3C1C76D5F68E0BB9ULL, 0xE37700BDE1233B5AULL, 
            0x53F66B2F16810080ULL, 0xFB8A444111659CC6ULL, 0x6A4D7ECDA7E677ABULL, 0xF41A24281FD8A375ULL, 
            0x3003942748EA111BULL, 0x4E324C9B9A492CC4ULL, 0xC3306D0BC6B6C49CULL, 0xCB4792C22EBE05D5ULL, 
            0x1915289C87160160ULL, 0x0739E5807BFDE872ULL, 0x1FCB4C9A6B89A94AULL, 0x8348087E6D79BD52ULL, 
            0xCE2FE84EA9DFF7B6ULL, 0xA403E0FDF8EEF097ULL, 0x1767597B7EB89A8AULL, 0x1B3FA515F9CA061AULL
        },
        {
            0xD72CA6307A4FC973ULL, 0x2E1C99B7B01AFBF9ULL, 0xECEEBFA7CD712AC1ULL, 0xF12E5891D5613B3CULL, 
            0x8CD2A3389AB1E0E6ULL, 0x95D7425C2F0654A8ULL, 0x98BE5352A5251D31ULL, 0x8A269EB10697B914ULL, 
            0xDB98F220B2FB65ADULL, 0x7A74B86EF977A9B9ULL, 0x3B4564C1AF5F1E89ULL, 0x9046A9AE9F849AC6ULL, 
            0x710156584D8ED4DFULL, 0xB8D6550C0562045EULL, 0x1F5F73E282C623FFULL, 0xEF111E4079C65C51ULL, 
            0x1BEAEA7017488F86ULL, 0xFC6C20F5B37AA161ULL, 0x9154126E4F8E7C51ULL, 0x77EE0D82BD6D9D11ULL, 
            0x722002C1BE980AE9ULL, 0x2ACA3C1EE71F11C2ULL, 0x71B0F6DAC2A400C8ULL, 0xE0AE5AF0C1416E3EULL, 
            0x4C90727342643008ULL, 0x5E1B741D9839A861ULL, 0x953293D88506CD82ULL, 0x99D252DF796CA208ULL, 
            0x1725CA7A68BBBE5CULL, 0x0396D9262B045339ULL, 0x4C2FAC95F7BC9342ULL, 0xE55FCD8CB81DB9B5ULL
        },
        {
            0x2F3C0C444BECC1DBULL, 0x4BD81CD1BE1A51FBULL, 0xF48731BD196AD311ULL, 0x5B101E53FB09D0F4ULL, 
            0x5E159E407143105CULL, 0xCF4ECEBE800151BAULL, 0xDEFE9CD8DB1D6568ULL, 0xA520C924362F140BULL, 
            0xDA8709D33F44EB6EULL, 0x378B28D847577797ULL, 0x1EF410E7ADBD5FA9ULL, 0x4560D02842846802ULL, 
            0x1CFDB596C40AC01FULL, 0x7CE60E4006A212C9ULL, 0x053F8F50B19F4AC6ULL, 0x25FE3678A97E60F3ULL, 
            0x82E1BEB4AD5BC72BULL, 0xCD6F6F23AC123C7AULL, 0x03C3D256CE86127AULL, 0x316A33E2653A74DEULL, 
            0x4C192DF7292D0901ULL, 0xEE015CEBE82CE21EULL, 0x9E5AC10B9BB22E64ULL, 0x0961523973251773ULL, 
            0x8A17CD36E880C256ULL, 0x9F9B4373283477CBULL, 0x1B759F386D375352ULL, 0xCCEE29D5ACDB29BDULL, 
            0x609A343C7EB6FB9BULL, 0x3297B0CD65B2C003ULL, 0xF1DA386C2180F0BFULL, 0x30ED75130166B4AAULL
        },
        {
            0x0BD54A67D324E70FULL, 0x2835AE376567BC88ULL, 0x6F8873B81D41CB5EULL, 0xD338A5A633D3D7B0ULL, 
            0x355C1DD18E5C37DCULL, 0xE15F0232F7EBA966ULL, 0x90112C881D8C8249ULL, 0x4FF01467ACFFA7D0ULL, 
            0x6847755B642D8F7EULL, 0xA362623C0F7DE11BULL, 0x29EFAB2EE3B7601EULL, 0xFC884F586F8340D0ULL, 
            0x2C9622B4C318AD6CULL, 0x86D7279DECBD3198ULL, 0xBBCA4A485FDEC532ULL, 0x9316BC1797E0CEDBULL, 
            0xAA441620220CE3B6ULL, 0xE58CCB400A852D33ULL, 0x5AC5C7E00E364E33ULL, 0x4A3BFE9C90B7CD70ULL, 
            0x8C92D011D23F5469ULL, 0xE15A9434DCABA8E2ULL, 0xA2C917375B1DEB43ULL, 0x65D3954AFB9C0C47ULL, 
            0x2EAF1DD92A7BA21BULL, 0xB46FF79E6D455629ULL, 0xC240797E3DFF94EBULL, 0x2FF25229F233621EULL, 
            0x6CADC866504F15E0ULL, 0x88E04F0E5AFDBA32ULL, 0x24D4931B70C96C6AULL, 0xFD78EBC6F70BC2D7ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Naos::kPhaseBConstants = {
    0xA9CE14B6E19ED767ULL,
    0x55CD3F24BE63835CULL,
    0xF44CD8E111496B08ULL,
    0xA9CE14B6E19ED767ULL,
    0x55CD3F24BE63835CULL,
    0xF44CD8E111496B08ULL,
    0xE9800CB10C7F4EE2ULL,
    0x9DCF1B7603EF7EB1ULL,
    0xC0,
    0xEC,
    0xFC,
    0x34,
    0xF2,
    0xEF,
    0xB0,
    0xEB
};

const TwistDomainSaltSet TwistExpander_Naos::kPhaseCSalts = {
    {
        {
            0xD30532C79EA6E6E2ULL, 0x958BCC7D34A942EAULL, 0x059B6CFA3B5B70FEULL, 0x66E45B8F894D18FBULL, 
            0x1E46CB530FB8E252ULL, 0xC5F2C57D9C3D98AFULL, 0x34343C232A276214ULL, 0x23DA5EE06DDCC53DULL, 
            0x8E328BE5BCC3DD66ULL, 0x6617DF296D10FB81ULL, 0x9FBAF3BC7209D40CULL, 0x046B5B10E50A0AFFULL, 
            0xD946C6603E3EF7C5ULL, 0x41F668246A34D48AULL, 0xE3608558D70C4B8EULL, 0xE9F464E60A96E7FEULL, 
            0xD49DF9AABE385EBEULL, 0x87D1ABE105B8DCEDULL, 0xC59348C272249939ULL, 0x49ACA3C9BEA210FFULL, 
            0x501AB61E96792967ULL, 0x6A1CAEC86EEDB7A4ULL, 0x1E2646B02DA25C6BULL, 0xA1441AA649BEE64DULL, 
            0xA63D61E27274300CULL, 0xC586E92C384C84F0ULL, 0xAFD00197ABA08D95ULL, 0x0BE64F32FCDD1B1AULL, 
            0xD3600D23E99A942EULL, 0x5DE593F9022B9E5CULL, 0x07652710D64EA042ULL, 0xFD6955DA164CAAF1ULL
        },
        {
            0xBC12E1E8A50B2B65ULL, 0x92FF61C3EEEAAA3AULL, 0xFE9E54D52B99D80DULL, 0x298E10579E3452C6ULL, 
            0xF6ACB7B8EFCF31C0ULL, 0x557E224F9234AAFCULL, 0x3FF241A73C2BE43DULL, 0x0CC9F0B8914956E6ULL, 
            0xA053EE134FE6B7BBULL, 0xFDA1AE4E8405E0C9ULL, 0x6A54091D995E4AB4ULL, 0x8DA8FC92C9CDEA05ULL, 
            0x4EE7A7530626BE38ULL, 0xCC97B27D30F6F9BBULL, 0xC22F0AFEB77943A4ULL, 0x9288EE1EE7F00AA2ULL, 
            0x1AF47BD42A1C0E6FULL, 0x0306EECE5DD63981ULL, 0x2225C2FD9A149236ULL, 0x03401EB9881B77F7ULL, 
            0x1207DE4D536DBF05ULL, 0x439EACBA8E1FB2E3ULL, 0x4EC7177C3870995AULL, 0xAB91A2C1E0567018ULL, 
            0x27EA1E87AB652964ULL, 0x2A234D1A23D6BD31ULL, 0x9CB12D404E1D4AEEULL, 0x8F53A00828ACA2B5ULL, 
            0x7D1DF502565E59FEULL, 0xBF46B21C443D096DULL, 0x7F0A68EC2CA31C47ULL, 0x86F6CBF19A2AA52AULL
        },
        {
            0x8467DC2F2199AE2FULL, 0xF2BB63922D556F1BULL, 0x57A23E8CA6EA43A5ULL, 0xC1519D5A089D5290ULL, 
            0x1162F1B7BD0F794AULL, 0x08EA9C8D71E70B30ULL, 0x481D70A7083DD024ULL, 0x950AA3B9AC12D0C4ULL, 
            0x5268898B998A0E8BULL, 0xE9B43AA7885FC3E3ULL, 0x8E20090947AE5B8EULL, 0xD66F6946A4C442C5ULL, 
            0x92A0DF40358A36A8ULL, 0x00A37FC8939D0BA7ULL, 0xAAC64E257C9130E3ULL, 0x8C555D8BA4EE0CE1ULL, 
            0x33450C0074534B36ULL, 0x2ACBFAE6EDE0F40BULL, 0xC74A15D839D38CF6ULL, 0x5D8ACD4A5A56E19CULL, 
            0xAB2A85CA36282C85ULL, 0x89357E9F740B373DULL, 0x6DA25FACDC92BE7EULL, 0x65257A7181100F15ULL, 
            0x1162FF131964609DULL, 0x95DE5FCBCCF08422ULL, 0xE0732A3431FED586ULL, 0x467970ADAA1EBD83ULL, 
            0x0F25C0786E15AB86ULL, 0xC6D58765337CD9A4ULL, 0x22F40DEA40BBF80AULL, 0xAF321B23CE6B09D6ULL
        },
        {
            0x56E2010F2EEAB3ECULL, 0x9BFA6F7095A2EB1CULL, 0x1355206EB6D3B66CULL, 0xA9AA5A7322544F05ULL, 
            0xE3CFCA1965A0AC8FULL, 0xBF03A85FAF94B171ULL, 0x9E0EF18DE0F5FF7EULL, 0x14D1F5F4F8E27DA6ULL, 
            0x5BAEED797B79F85FULL, 0x632446A9A71073C6ULL, 0xC13D90A0AE66A89AULL, 0xDBA1F4BF6BA3640AULL, 
            0x5EF85C867331FF68ULL, 0xE85CAB63403D9133ULL, 0x9E3D363DD6EDC394ULL, 0xB5CBB0F320160927ULL, 
            0xA4BA4446AC43644DULL, 0xB67A7DD9F234516FULL, 0x808519E2C432D5F2ULL, 0x744EF3F066ED1153ULL, 
            0x0F28024C0673B8A3ULL, 0xCCCD3CB712939FA5ULL, 0x4E5C9A564A085CE9ULL, 0x53F0D2C85763F859ULL, 
            0x6A436763848E6552ULL, 0xDB76C04CC542A80BULL, 0x79F875ED24A0C3DAULL, 0x6CDE8DDE08BBB145ULL, 
            0xF20C29F73E8A9263ULL, 0x3E47379F28C95708ULL, 0xE2EBD10C3316ABBDULL, 0x62F739B4662CCE40ULL
        },
        {
            0xA5779B07D542B3E3ULL, 0x5C79ACFAC08BC71DULL, 0xAC2E88F42DFAA057ULL, 0x1FD9FFBB52344036ULL, 
            0xEE43A2759053557EULL, 0x8D2A6CEEB1095B02ULL, 0x7DE3A9ABF42733A6ULL, 0x67D5FAA4D11C4E46ULL, 
            0xD1E58916A62723D5ULL, 0x5DEC88F7E9F1DB2DULL, 0x9959B6B7C09F6E1DULL, 0xD175B3921F54465EULL, 
            0x3165DB07FEC0CDBDULL, 0xA98AAA0F1CF29153ULL, 0x810AEBFC64272116ULL, 0x6AF84D8FEE397920ULL, 
            0xF034908B362E9F54ULL, 0xD0AC41DD367DCD9EULL, 0x9F83108F60FAA1F5ULL, 0x2A38C0EB5FBFD6B8ULL, 
            0xBAB00C2184E2ADDFULL, 0x81D7AF7A71C9DCB5ULL, 0x04CC046AB32E95B0ULL, 0x58DDE591C2AB8216ULL, 
            0xE3EECCD158F1C621ULL, 0xE13F7BC457B6BBC4ULL, 0x030ABBA29665EB6AULL, 0xE3F9F01C24CFC156ULL, 
            0x6BDF2DAE989AB57DULL, 0x0031DFE093E12849ULL, 0x134BBB1B2B9CAF4CULL, 0x8B6AC0C51146FC01ULL
        },
        {
            0x2D1C4C1B78C6FB1CULL, 0xC25F44790D154172ULL, 0x4D1D09E0D0AA4D8FULL, 0xE0D7D7DABC065BB8ULL, 
            0xC735311FF7ACB3ACULL, 0x6A3E1DFE53D7B646ULL, 0x711FDA1C12FFC291ULL, 0x24ACC36730EC79EBULL, 
            0x49A6D2ACCCADE544ULL, 0xCE663B8FB22B31A0ULL, 0x3D6F3F814AED2C46ULL, 0xB5DB47BA70B552BBULL, 
            0x2711A12F1C61AAD8ULL, 0xD88CF147E7B0A760ULL, 0xF168D5DC69894757ULL, 0xCF7C1E09F99B6121ULL, 
            0x9B9CBBDF6FA93EDEULL, 0x37D5E6C7192F62E0ULL, 0x9EFF9EFFDC4B5B00ULL, 0x999B93BE964C8A96ULL, 
            0x2145CEF3365906F3ULL, 0x7A3EAE627A99052BULL, 0xE66D88C073812392ULL, 0x02B95EE1E6FFCFBFULL, 
            0x04AEBBFA3A99A541ULL, 0xA247F510614CEC9FULL, 0x03E49BC8F2A0F2D0ULL, 0x89C7A0F11E7874B7ULL, 
            0x769C9E41741A9648ULL, 0x08DF9C6A2E84DC99ULL, 0xD5984EE9FC9E594FULL, 0xB0EBFBDAE70E0CFAULL
        }
    },
    {
        {
            0xA08272F76ACEB925ULL, 0x2C5B3FA9040DEA88ULL, 0x951E9C74687E43A5ULL, 0xAC425F4251C78557ULL, 
            0xE8AADB62E7610AC4ULL, 0x37C6E886B74F0329ULL, 0x3A467E41044CFE20ULL, 0x59AA17412A24DE60ULL, 
            0x42CC1D2B4FF97EDDULL, 0x1B7FC3370989EFF5ULL, 0xF84F6569DBAFB495ULL, 0xC949F1DE82159340ULL, 
            0xE805E1542A392458ULL, 0xF9238A985194F611ULL, 0xF74CA1EB33A2781AULL, 0x4CE70D86289097B4ULL, 
            0x8E93CAFBB40EB678ULL, 0x8CEF23BB690E5923ULL, 0x17CC3742DFB86FF2ULL, 0xE109B7044ACE9169ULL, 
            0xE520DD114AAEFB55ULL, 0xDC046990B1119213ULL, 0xB8A0B9AE73EF0713ULL, 0x4D88F9276F52503FULL, 
            0xEBDF2B70A2A2E6F8ULL, 0x8A9081607636DD28ULL, 0x58B13BF7A89CCA04ULL, 0x9416CA1599EB480DULL, 
            0xDF9F5AF42D19996AULL, 0xA97FD2AD1DF28C12ULL, 0xF5B4FEBA3DBF8776ULL, 0x2461A1CC9BBB7DADULL
        },
        {
            0xDB96EE7649133E9AULL, 0xEB0220AEF96B3C35ULL, 0xBE7CC04EE866A4E6ULL, 0x90FD62BB293DEB4EULL, 
            0xAFF0631CB65A3C2CULL, 0xCE4C1B6AC31E49D7ULL, 0xCAD6BF80A528C634ULL, 0xC989B6E9030F89BFULL, 
            0xE89938EBD4F671BAULL, 0xFA5DCABB59656541ULL, 0xFF8960743A7DC34CULL, 0xCFA333609C1CD4CFULL, 
            0xC2304C0AEB08B114ULL, 0x5DBE62754125FE27ULL, 0x9B4BE03BD1206E1AULL, 0x78696CB81068668CULL, 
            0x9B81564CE79D7A64ULL, 0xD961CDBD152F26A2ULL, 0xBE4EA8B549E369F2ULL, 0x5EF28E2F5CD31683ULL, 
            0xF49BFDE1F0273881ULL, 0x3EB4746B2D32D420ULL, 0xA89D7FDA67790727ULL, 0x5EDD7990BFC49B2EULL, 
            0xAB80D558BC816285ULL, 0x43375D672DFB3608ULL, 0xC1B4D690BAB64FB6ULL, 0x168A64067DB75D40ULL, 
            0x805A05DAFB6E6884ULL, 0xE0427C77D8E7A387ULL, 0x5E76EB7893A256E1ULL, 0x88C0CA197862A5A8ULL
        },
        {
            0xE3109D1DB6D41B5EULL, 0x0140FE3536567C78ULL, 0xF7F6FF80711D5A88ULL, 0x9FD1C349AD175933ULL, 
            0x6166260CA74F1961ULL, 0xB6E83342C03CF2EEULL, 0xD29C2BDFF228E04EULL, 0xEA20214FF05A0A0CULL, 
            0xBABBE346901CAAEEULL, 0x36A092AA1B70FF8BULL, 0x7592A68F364109C5ULL, 0x3991CDF34DE80EAFULL, 
            0xFDD1EB764302F4E4ULL, 0x97E1756A26105EACULL, 0x9F837377A4D13F0AULL, 0x05FB2E084A808985ULL, 
            0x0D8C1822D9F7C2A0ULL, 0x7EAEEA1CA2379596ULL, 0x854254EE11D8A875ULL, 0xCE60FA29F413B7D8ULL, 
            0xF131984560704BAAULL, 0x1D328419858DB643ULL, 0xDAA216421EC2799EULL, 0x9D922B4421CA28F4ULL, 
            0xA8DA9840546261A5ULL, 0x01ED789CC0CA201EULL, 0x77AA5DEF58973094ULL, 0x64425EDB20BA16ABULL, 
            0x50ADAD0B13261623ULL, 0xA4D7907DE5ACDCF0ULL, 0xE6360ECB8F8626C3ULL, 0x9DC60B2658DB1E87ULL
        },
        {
            0x7A0F99A24E728DBCULL, 0xEF6910AEA8F587A5ULL, 0x23008E33819B5F26ULL, 0x204BFBC82F480438ULL, 
            0x9312441C22141D97ULL, 0x8C4F8BAAB6685451ULL, 0x058C9E60D1750586ULL, 0x8FEB37D47715571FULL, 
            0x9E3D32D973C24D36ULL, 0x186A1EE142ACA8B0ULL, 0x63EC17162305C903ULL, 0x286011AD8C49532EULL, 
            0xCDB7721CE8B13D48ULL, 0xB3B858EF346ABB9EULL, 0x81FD7378932A60ABULL, 0x6447C649FFBF5E9BULL, 
            0x7B7FE6854BE2B610ULL, 0x4B719362D10F133DULL, 0x1574923EF6293CD1ULL, 0x30BE4E41466E43DFULL, 
            0x9994277B3330D42EULL, 0xE2673B3E37EFAE27ULL, 0x852A24AE9C9AC874ULL, 0x053E632C6C548342ULL, 
            0xD590C8B3DE0D252FULL, 0x4BEC89267D371258ULL, 0x5FF5B71D1EA76173ULL, 0xE3DCB475880E2950ULL, 
            0x263E04397DD6C745ULL, 0x8C2C9958E266B000ULL, 0xE5CC9AFCC1C3AD18ULL, 0xA0A9014A45611F42ULL
        },
        {
            0xEBAE581338C9D6C0ULL, 0x306EC986C9B8B63EULL, 0x8DFB502DC55403DEULL, 0xB4CF94F53E6ED46AULL, 
            0xCFAF9A11C3D741A6ULL, 0x330B4A2EC835174BULL, 0x03F157ED6C7C36B9ULL, 0x2FAACCFECE92DDFBULL, 
            0x0FD52A0BBC805BA9ULL, 0x791B5B92932FCED0ULL, 0x79E3CDA690D808F0ULL, 0x17F1129740D50B0FULL, 
            0x0788E48527FE632FULL, 0x1023FA24B53360ADULL, 0x19E70191668CB04CULL, 0xF543E58A586F0E7EULL, 
            0xF1EA61725CC282E7ULL, 0x2384A76041CB685EULL, 0x37F30CCEA761CD73ULL, 0xC1A7E27D1FB38917ULL, 
            0x6532F40BB8EAC90BULL, 0x2529AD3CD9D1FEF6ULL, 0xF45CBD61B1CC6ABAULL, 0x60C2594FD4149E49ULL, 
            0xFA2B4E981ECC7C85ULL, 0x34DD29D00B41ADA5ULL, 0x516765B192723B71ULL, 0xC0273A9E3EE3B585ULL, 
            0xDEFC5C79BA781ED4ULL, 0x832DCE3545654158ULL, 0x6C52795F99679F73ULL, 0x0557F32E6F17FD52ULL
        },
        {
            0xEFE2355FFBBBF120ULL, 0x4D80BA28576D6083ULL, 0xD6A86A12A251544AULL, 0x418C6DEE20AF5FF1ULL, 
            0xBCB248107A08FDBEULL, 0x4F84798F8FC80A7EULL, 0x273CB4F3FC3A26E1ULL, 0xBDC6B3CEEC797C10ULL, 
            0xE7DF642085FAECFFULL, 0x2F772712A6EA44E8ULL, 0x765DB17DF1B8F6E4ULL, 0x490B392452D55C45ULL, 
            0xA29F67063978FADDULL, 0xE0174B9E6EFA0C58ULL, 0x00FE66530E92F5F6ULL, 0x2801CE9231CE5A70ULL, 
            0x795FDD4ED7017048ULL, 0x60CFEA6E5DCE3C0AULL, 0xE9C8707B11B72899ULL, 0x292EF77AFA0A0B34ULL, 
            0x1285376A33AD72ABULL, 0xA0A042CB0D297083ULL, 0x48DB3B382BCDCF22ULL, 0x64E26C5B26253368ULL, 
            0x8DCB7CEA49AEA206ULL, 0xC6425F0A6252E782ULL, 0x754450C7D9655208ULL, 0x0F15D87730ACBD50ULL, 
            0x3FAE74628BE59EFAULL, 0x40A743069261A264ULL, 0x051927B1D9A9B3C3ULL, 0x62F8EF0D3B7D1352ULL
        }
    },
    {
        {
            0x1564016D65D95A94ULL, 0xB0F5468661E43EFEULL, 0xB560E2DB204087EEULL, 0x0712AE5D0533662AULL, 
            0xFCA3D7D4E0657BADULL, 0x2EE870087F777851ULL, 0xB013B3639D1698A9ULL, 0x7AF2DE8473112B96ULL, 
            0xFCA8541DBC11EE9DULL, 0x2AC3A51F568841A8ULL, 0x468A4326DA806979ULL, 0x35EA6F00AB53D6CFULL, 
            0x6649BE0920F3FC2CULL, 0xC7B303E25917CA8FULL, 0x171B6977EEA6177AULL, 0xEDE47AA4FF6A21B6ULL, 
            0x03E1584087DEF677ULL, 0x65A5C602462D2161ULL, 0x34A661CF9E0AA8D2ULL, 0x9EC09BD7306343B7ULL, 
            0x38078FC61D21F273ULL, 0x8121263AFE10093FULL, 0x3263C0C3CE3340AAULL, 0x9081627948BC67F6ULL, 
            0x8139B635EE075D12ULL, 0x3D24BA3D7C3695FEULL, 0xFDDD45218356F521ULL, 0xDBC1908650DCFB39ULL, 
            0xCC79FE151C723C04ULL, 0xE2607055CF933971ULL, 0xF59F53E863A4B0A0ULL, 0x2D85CA56B467C5DDULL
        },
        {
            0x2B2D1695A3E08E11ULL, 0x37F21A6616FF2939ULL, 0x193159B5208A816EULL, 0xA6E435ADBC3AB240ULL, 
            0x2DD7E3A9CCF0BCCFULL, 0x6E4C76223B0489AEULL, 0x85517482C1CF0B83ULL, 0xE2289A85F49FC907ULL, 
            0x61F8F9F69ADDC547ULL, 0x7658617A80B825A4ULL, 0x697152CD60B9ADB2ULL, 0x29DBC3D480B43057ULL, 
            0x6FB7B0276B4DED48ULL, 0x8B7FE55768A46201ULL, 0xD64E5474BAFC694EULL, 0x0C0B34F5B4A7F59DULL, 
            0x91BE8E1E99583933ULL, 0xE98C3A3A744700A6ULL, 0x904D376B81E0E69CULL, 0x3DA7C0C855B3CC3CULL, 
            0x7D783B741CD35205ULL, 0x51E81D520285264EULL, 0xB06CC56002A5AB37ULL, 0x093BEE264D34AA43ULL, 
            0x2A9167DE9116C134ULL, 0xA810244EAE2D405AULL, 0xE21AB63D46D658FAULL, 0x747E7A96536753CBULL, 
            0xE095AEDC6A465B5BULL, 0xD2E6719342C8EC69ULL, 0xD3DE1A879F3C2E6CULL, 0xC82A5F1278774443ULL
        },
        {
            0x918E2ADE748D0A03ULL, 0xE2B60318B9F9B75EULL, 0x275BED507B128BBDULL, 0xA235CD8E209C5F3EULL, 
            0x7C3F9402A2CB21E0ULL, 0x5B827941D93D4F2DULL, 0xEEDC3DF8AECA52C3ULL, 0x23B6A2D8125D66D1ULL, 
            0xA7F41C4E14B0B4E8ULL, 0x2FB68093CCBB5703ULL, 0xBDCE9F1E67082CF9ULL, 0x98F4F06AA080759BULL, 
            0x92A309EA570FCF31ULL, 0x22F651AC931FAD68ULL, 0x0AAE4B53891ECC37ULL, 0x9D1947C911D14604ULL, 
            0xD1F003BB9CCF4029ULL, 0xB616A2C125E9B919ULL, 0x279CA9920930F8A3ULL, 0x1CB434DA24EA2EF8ULL, 
            0xE1EE6FFEE4FE6D7BULL, 0x36027AB6E5E05166ULL, 0x81DC63E64ADEA795ULL, 0xB49315EBCA412423ULL, 
            0x6677A9837B11D257ULL, 0x78EC5156A5A64EC8ULL, 0xB74DEDFEC9FC6D45ULL, 0xFCB1DC78731EA333ULL, 
            0xB0E46D0FAAE6A8E9ULL, 0xA8D0141ABAB03CF7ULL, 0x4FA67B79A5F66976ULL, 0x2E0F6B8607C4CF9DULL
        },
        {
            0xC7E42BA86700A080ULL, 0x508CE3DE0A5D6CBFULL, 0x854F7B656D31B461ULL, 0x5AEE5CFCF0443147ULL, 
            0xD8F582A4BF2C348CULL, 0x6FA0295D7BBA22FBULL, 0x1736D23967FCE0EDULL, 0x45BB08FEC816EE50ULL, 
            0x79EBA281E25AB378ULL, 0x89A3F525D8CF3A1FULL, 0xDF73420997674021ULL, 0x462F1AB781A53498ULL, 
            0x049BF0D0BFFF1AA3ULL, 0xDF0678D55CEBF2C4ULL, 0x7B4D7F7EA2A7D16EULL, 0x584ADD8F3B484120ULL, 
            0x83DDE19FB5396CC0ULL, 0x0348B6DBA4D50081ULL, 0x8C09824234893AC7ULL, 0xDD7A183CCC9939ABULL, 
            0x901171B4B4368031ULL, 0xA86A115DBB299A23ULL, 0x07867EBC2D0BE599ULL, 0x0625BF3F85702D70ULL, 
            0x0B808139B6C9917FULL, 0xB3071E6AC3EC4B52ULL, 0x150B35AA539A799BULL, 0xE0D97C0B67817C76ULL, 
            0xB7C74892AB1666E7ULL, 0xB84FA8D02DC93BA4ULL, 0x577648BB1566F996ULL, 0xBF21B76C0263A337ULL
        },
        {
            0xABA913916B140FE3ULL, 0x9758B02C04CB786BULL, 0xD0546F8958762A17ULL, 0x31F3302FA178A743ULL, 
            0x251B8F59FD5414C6ULL, 0x99E22E1F2FE0CFADULL, 0x1DA528F5E2AA8160ULL, 0x02C7B6ADCDA4197DULL, 
            0x5E3B5B3435A55CFCULL, 0x380AC6D84D885048ULL, 0xB1364CC65142F2F7ULL, 0xDB75FB82F2535983ULL, 
            0xC3550F6E03D32581ULL, 0x9557BB0BFDF058DDULL, 0xA9BCBFB095201F9BULL, 0x760DC7F3160DBC49ULL, 
            0x9C5686807CF5B09DULL, 0x2E7A174A23A878D5ULL, 0x75CB59D8294DAC98ULL, 0x835822DC73F63BD7ULL, 
            0xC09CDDA7DAFFE4AAULL, 0xBB55357F45437169ULL, 0x4A91BE275A6118ABULL, 0xAFD954E95DA1F4E5ULL, 
            0x44146BDAA17D34DDULL, 0xB39D1823665FBE0FULL, 0x730FB909DBD8E657ULL, 0xF5A14EF1392CD15BULL, 
            0x0B338D27A8F960D4ULL, 0x7EC48063DF439E71ULL, 0xD1AD2E7C74B96780ULL, 0x336714FDB077333FULL
        },
        {
            0x496902013EB2F1E9ULL, 0x7A2F17BEAE93AE62ULL, 0x2D49944C472DF055ULL, 0x25EE438996751707ULL, 
            0x53EF57AC1DB65148ULL, 0xC10AD483B84A2CF7ULL, 0xEC05C61881F5229EULL, 0x816C6CC698CAF697ULL, 
            0x1FDA4BE30C510FB0ULL, 0xCAD987037B2947E7ULL, 0xC9A94ECD302CA000ULL, 0x40648299209C766DULL, 
            0x7ED89EFED67F2784ULL, 0xA0FC4713DECC518EULL, 0x7ED21EA419DF960DULL, 0x362583D26F0FFFE9ULL, 
            0xC1AAE4B164DC26D1ULL, 0x71C18A29B9C6FB73ULL, 0xF545BD2D78D76386ULL, 0xEEC43238E0B46D8AULL, 
            0xC2543A27E9951495ULL, 0x7E8480E9B42FB377ULL, 0x61A6213410D85443ULL, 0x8F3F622BA7270373ULL, 
            0x2E33862CDE6150C7ULL, 0xC31673B00B8E4D2CULL, 0xFAF700D9F726F6EFULL, 0x4AB17A1D2B0334CDULL, 
            0xF289EC577B91B972ULL, 0x31D35E8C7EE836C2ULL, 0xDA15E6D0DE439368ULL, 0xE33E8DC7AA57BE95ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Naos::kPhaseCConstants = {
    0xF3C41611D0205B4FULL,
    0xFF337934190F3A2BULL,
    0x78AC02B5DBDEC23CULL,
    0xF3C41611D0205B4FULL,
    0xFF337934190F3A2BULL,
    0x78AC02B5DBDEC23CULL,
    0x9FA5C431C113D4A8ULL,
    0xEBD26C4868B884C3ULL,
    0xCA,
    0x04,
    0x2A,
    0xCF,
    0x63,
    0xFA,
    0x69,
    0x9C
};

const TwistDomainSaltSet TwistExpander_Naos::kPhaseDSalts = {
    {
        {
            0x73B3C1F516A37DCAULL, 0xFA0BC70430ED5DEAULL, 0x382CF6E56DBC0485ULL, 0x84A88385734123E4ULL, 
            0x2C7E9B9C382E3346ULL, 0x725A782BFFE51FD1ULL, 0x70FA4A60ABB575BCULL, 0x4A056A22B675A517ULL, 
            0xA839E37E817642DDULL, 0xFB34E23BC5E48F33ULL, 0x45865702F10B7DA0ULL, 0xD70DD066CB63E993ULL, 
            0x168966F1986FBC14ULL, 0x6A37E6E7947FD475ULL, 0xB1F2F56EC27886B4ULL, 0x7B9B67DF9042BD24ULL, 
            0xC242F335CF40C835ULL, 0x7E8E7A423C142B65ULL, 0x5583C8BBB623D59EULL, 0xD8604661BC246DDFULL, 
            0x5331019D2989539AULL, 0xBE148EF7BC3DF45BULL, 0x087C4F09A830F61EULL, 0x8FA89B149ED719E3ULL, 
            0xE251AA948FDB9A71ULL, 0x9A3D6308E5D9A6FAULL, 0xBF4D3D10CC17CB79ULL, 0x15C3CB034B1A3069ULL, 
            0x7622B326EBB8DD9FULL, 0x11674C62C56AD7A6ULL, 0xC6DA2555D5571A28ULL, 0xDD401AD55371D618ULL
        },
        {
            0x2645CD5F41430D99ULL, 0xB76B99B2D9E64214ULL, 0xF35AF1487BE7B6EFULL, 0xF04F1E20BF121052ULL, 
            0xFD01CEF4CC5CC7CDULL, 0x1C905AE1D0BD815EULL, 0xB4107B2287278F4CULL, 0x8D9FB69670F3894EULL, 
            0xD93DC0680112BC4DULL, 0x7A6A5CA8885CF69AULL, 0xF4ADAAF8833A2948ULL, 0x6AB48B8BEB9C136EULL, 
            0x7113A81F514D4787ULL, 0xF1F32D5D160A9295ULL, 0xE0051F06B352CF7FULL, 0xACB044370011DC92ULL, 
            0x1F14D49F7CE38264ULL, 0x98D9F9EA938F7D93ULL, 0x09EB1E86E31310F8ULL, 0xD4E6736DBD2D40B3ULL, 
            0x4B543BA9EC6E0D54ULL, 0x91CD8844C366A55BULL, 0xCF230130D162E1B8ULL, 0xA321556E857E55CCULL, 
            0x8E8D617920B2A8FDULL, 0x56F4B8F573A3C966ULL, 0x0C6004FC7906F117ULL, 0xEC2E41660F7C2817ULL, 
            0xC84FC0C065409445ULL, 0xC511FC0805A7D7D2ULL, 0xD3377062F0E444A6ULL, 0x36D891E7EC741A28ULL
        },
        {
            0x6C63019B37FA1856ULL, 0x75020B7B037DBFA1ULL, 0x4C2F78FFB7A91BB8ULL, 0x424F15F4430BCAD0ULL, 
            0x578D02D336817563ULL, 0x030474A11517C00DULL, 0xF02C57522E9F3642ULL, 0xF42BC4D7B62F9A04ULL, 
            0x0DA44588D56D83D0ULL, 0x106AC46C57DC6A3BULL, 0x6D1FD739D05989CDULL, 0xBC6E4D9B71C114DEULL, 
            0xD6CC07A51DA7485AULL, 0xF6F6FFD400041C92ULL, 0x22EC59C56F0CD526ULL, 0x6457614550D12EF4ULL, 
            0x966294BC3F9E73A6ULL, 0xC15CF8432C428E77ULL, 0xE8D8A5A5225D22A1ULL, 0xFBDB207BAD6C6711ULL, 
            0x081899AB0484D4D7ULL, 0xF6965DE63F60CBEDULL, 0xECBC2626410DFB9FULL, 0xCA9B9B13BD81CF0DULL, 
            0xDF483FFEB39927C5ULL, 0xDE7F40C103405221ULL, 0x01BA05CB21BB8F57ULL, 0xBC62681894142EB3ULL, 
            0xEFB0A0E3B927A701ULL, 0x5A32175994AF7391ULL, 0xB13CD9E403B2E62AULL, 0x0F777CCA02DF53B2ULL
        },
        {
            0x3D0CE02456B5CB33ULL, 0x47AD79DCF6DB143FULL, 0x2AB81C5F544918E4ULL, 0x625B8EE0B81FB921ULL, 
            0xCF422D0E87687DFDULL, 0x8EBE325AF9746114ULL, 0x5177E7C32FD28CBFULL, 0xF5F015821418ADC2ULL, 
            0xC4663A1991944435ULL, 0x3C5E65686422C9B2ULL, 0x2233D2321A2764D6ULL, 0xEA3F518677F0CD05ULL, 
            0x6A0525AD6432DFD4ULL, 0xF3ECEC21759E57DFULL, 0x654699BEE3552999ULL, 0x3DF427333ACCBCC6ULL, 
            0x2DD9C870405A3B02ULL, 0x91791AD6E20C3C72ULL, 0x25D11FD11FA09AD9ULL, 0x64B7C92E2696BB2EULL, 
            0x932088E579BDE124ULL, 0x09A358BB43587130ULL, 0xA62C114EE7DA8186ULL, 0x3A531A500ED17905ULL, 
            0x19971F6FB395DA03ULL, 0x8C1E4A147D3AA208ULL, 0xCF7BCCC3EA1D9DB1ULL, 0x2881F64E749C54E7ULL, 
            0x31B3B6BFE8668AE3ULL, 0xFB84A908EFFD7C7EULL, 0xD77399D3EB82A63DULL, 0xA22CFD1CADE60A23ULL
        },
        {
            0x0D404297DF664A6EULL, 0x3C77CA8A022E2151ULL, 0x3511B9E980B13C0DULL, 0x966FEDB8222E99CAULL, 
            0xFD342A4EB7673DE4ULL, 0xCC7B321D9CA3A015ULL, 0x624C494F16587C7BULL, 0xE8C9B347D1E4A409ULL, 
            0x5C8BA47BAEE773EEULL, 0xC6292AD54A6AB875ULL, 0x82DBF1C2B3792F80ULL, 0x210E1556476490C7ULL, 
            0x3EC409002071CC49ULL, 0x7E500E2FAE6DDDD3ULL, 0xB7EA2AE01F04776FULL, 0x2D41C1E183287D05ULL, 
            0x226AF9AB6018CBD9ULL, 0x896F92138898184AULL, 0xA447D869C8C35014ULL, 0xF6B909AC9D3AC40FULL, 
            0x0835D43D8E6CDA2FULL, 0xD029B1CB30D1375CULL, 0x1EF3FC99E235ED7AULL, 0xB709D5D95193ADB9ULL, 
            0xB19B2A5D777BB2D2ULL, 0x8B42BAF6D3E11E91ULL, 0x145EFA30E6625EAEULL, 0xE26ED77A1E4ADE57ULL, 
            0xCE2D0D16C05D5779ULL, 0x02A98FA051F659A4ULL, 0x05FC942EFF9BCA8AULL, 0x63CAA87857C1B226ULL
        },
        {
            0xE1449C25A3744F9DULL, 0xC308856087E5C371ULL, 0x6833858D5E9C1575ULL, 0xFB20831158200694ULL, 
            0x40985F73DA8BBFDFULL, 0x03C8809A3522B341ULL, 0x7AEB006515C11B49ULL, 0xAF14D08DA59E719BULL, 
            0x3DD8CDF089F3D9E6ULL, 0xC7670ADE8E921FC0ULL, 0x8AC2B6BA9AC79467ULL, 0x959AB86DE4405B77ULL, 
            0xD891EF970F7B75BFULL, 0x479E12F7485D4780ULL, 0xCA2A334E8E587359ULL, 0xE8FC88AFEE96DCE7ULL, 
            0x178AF90BBC0807D4ULL, 0x79C5B5838D206647ULL, 0xD761E570735F6DD9ULL, 0xA610B57A2F74D0C6ULL, 
            0x8FC75EAB37AB42A1ULL, 0x2B033A61D23A1DFDULL, 0xD1A99A61B69E6365ULL, 0x0DBDACAF4C656221ULL, 
            0xEA880FE5A111EA85ULL, 0x2D57A8A55648F19BULL, 0xD013261D86EE344AULL, 0xB6952482EB0FFC04ULL, 
            0x4E789B061F7BC58DULL, 0x5A55A7BE11A688FCULL, 0xD84CA7F6BE3D1E21ULL, 0x24AA5476761F810DULL
        }
    },
    {
        {
            0x2CF309934CFA1BC0ULL, 0xECA05ABA1F2F371FULL, 0xCE16CF9D8CE501C0ULL, 0xC3AEB5BF9B05ED95ULL, 
            0x668EA38CCB3D7734ULL, 0xF12E6C18B56FD758ULL, 0x901228C697B87BFAULL, 0x79881CE6F3048035ULL, 
            0xF716D97A086DD602ULL, 0x7B0D5D81ABC07711ULL, 0x216CD81FADB25C6AULL, 0x0DCDB99916ECA189ULL, 
            0x079AEFF261F51572ULL, 0x97B15AC68D09F83AULL, 0x9DC5344BB3EFCC1BULL, 0x71D0FD77B306B046ULL, 
            0xFF8BAB823101F968ULL, 0x58F4C9685C979930ULL, 0xE1CDA2E28864D4CEULL, 0xF2CCA376D17B96A4ULL, 
            0x4D6667B92696090EULL, 0x3864B17656440F4EULL, 0xC19944740AEEA366ULL, 0x4256AFB93B1171F8ULL, 
            0xF99D70BAD6B527A6ULL, 0x0D50F5C6D81E23ADULL, 0xAD381C2664EB7225ULL, 0x74AE2331A45D263AULL, 
            0x79C6BA155E4A1066ULL, 0x3CB294F13D4ABACDULL, 0x617F62C2832D4434ULL, 0xDDBEAAC816273940ULL
        },
        {
            0xB743B665A131433EULL, 0x0327BF8DAA942A82ULL, 0x0EC39F082CC9E946ULL, 0x693C0C38822F1FE1ULL, 
            0x8CE6AEBE39424EE0ULL, 0xF42CDB9570A6BCDDULL, 0x7DA7C4BBD288A6A7ULL, 0x5875BB23A46EEAD7ULL, 
            0xFCBFD693F9FD735DULL, 0x398B298B275899F0ULL, 0xEC75E5FD2D412680ULL, 0x277E4389C54A28EDULL, 
            0x6C991B7D82B60DA9ULL, 0x9BE39F52CB724EF3ULL, 0x82C91DCCD34B9AD3ULL, 0xE0FAA0BA57B5E1F9ULL, 
            0x252029269A5D2ED0ULL, 0x053AC4DAB40B2DE5ULL, 0xC14F0A73469E0014ULL, 0x2BC867F0C5B0B02CULL, 
            0x398D78F3B0FA8798ULL, 0x2973F510F6EE4FA7ULL, 0xAFB2236737F93BC9ULL, 0x985DC750C1767583ULL, 
            0x830576B71B13A734ULL, 0x422A972A896895DEULL, 0xC34F58A68FFF7189ULL, 0x76336B58EE69C12EULL, 
            0x323C099F5C35F73FULL, 0x7D11E43A030877E4ULL, 0x3509CF046FE18214ULL, 0xC3B2CB4AB49B813AULL
        },
        {
            0x115A2C7A46C93499ULL, 0xD431898D782D914FULL, 0xBA47F7AB5E9A5C1DULL, 0x4ED146AB148F6C34ULL, 
            0x226BD65735E469D8ULL, 0x59E0D7484FBC0100ULL, 0x45CF1DDB635F6246ULL, 0x923D0263C1E7D2FFULL, 
            0x7DF9893AEFC5312DULL, 0xE070FA23844A6672ULL, 0xD48A697BDABA6306ULL, 0x59434F1083D906C3ULL, 
            0xAB9DA1DDEE57E4B8ULL, 0x78420D4C2CBA04A4ULL, 0xAA7456CEE34FECE6ULL, 0x079A1127CA79F21DULL, 
            0x93ED6DF38C38063EULL, 0x846B5C53F624A4DBULL, 0x2BB75E70E784BC92ULL, 0x362F9BF9D3BA1B30ULL, 
            0x46892A5668131ADEULL, 0xAA27CE6657CBABEAULL, 0x6743F418D740F91BULL, 0x15AF84A7B5547015ULL, 
            0x2B55FBFD97D13DB5ULL, 0xFB5F23C5D0E380BAULL, 0xEEB8C6E63FDCC1C6ULL, 0xB293FA2F50A60EC3ULL, 
            0x6C8A89E226A6A1A3ULL, 0xC8278C02CB92B30CULL, 0xA17D8EBF95BF1CD1ULL, 0x2C06D329A741CD4DULL
        },
        {
            0x8852E409CB89943BULL, 0xC3325BE832120DA6ULL, 0x0214CEFD09FC53D4ULL, 0x45670D4C995F34D8ULL, 
            0xF00BB7F0A7FEE53CULL, 0xE990915926472747ULL, 0x8E2744936C6CBC31ULL, 0xF969173121C720F5ULL, 
            0xFE8662901DBCE390ULL, 0x036D077D5BF48F7BULL, 0xE2A076B8F012AC7BULL, 0x01723CA69E5B3974ULL, 
            0xBDEA2AC9C8C09415ULL, 0x5DADD3A0E2C69BBDULL, 0x24A4E280F0178E59ULL, 0xC94DD5AC5CC80256ULL, 
            0x9EC18364DE60F75BULL, 0x5B1DB6E188167A67ULL, 0xA3645DEE01D15804ULL, 0x9ED80ADF830B875BULL, 
            0xDD36C0ADA8D17825ULL, 0xEEDA0727EC3A04BEULL, 0xDBC614954B735E96ULL, 0xFC044037EA950103ULL, 
            0x33F3415322B622F5ULL, 0x1FA356B06E7E11BEULL, 0xB0D5A962EE5D3576ULL, 0xF52A9220363F519AULL, 
            0x4E695BD035A75DA6ULL, 0x109B7B0AB92A3918ULL, 0x37B525C778F1ED28ULL, 0x014C3C19F039D510ULL
        },
        {
            0x286291D5FBD354EBULL, 0xD2BFA7AE261FD900ULL, 0xFB4FBB62F4AA03FEULL, 0xC2DAF64204D7ED54ULL, 
            0x4507EA0FE7B7C44DULL, 0xCE83E9E045BEE2F9ULL, 0x643B2223FF686EB7ULL, 0xBA9B0B8B417F768BULL, 
            0x4E4CC03DE8AA6D72ULL, 0x9B3A5238CDE36A79ULL, 0xE158DDD8B35E4829ULL, 0x3A4C492F55758F10ULL, 
            0x7393A8CC6BC19FF9ULL, 0x657DD78430EF1227ULL, 0x7887EF6BA5EC57BDULL, 0xDFFDEB2C10DB0806ULL, 
            0xBEB784BFBDE2B56EULL, 0x7043D53F95B61315ULL, 0xA4C37222FEB560F0ULL, 0x5B88FEF701823243ULL, 
            0xA5EC1875575E7431ULL, 0xFF9039D699571161ULL, 0xF30192628181CF3AULL, 0x2350C87D97FB3EC7ULL, 
            0x02AB2D5CEDC4914BULL, 0x1E4799DB80B02D58ULL, 0xA6DCCD7A6E2C4ACFULL, 0xF401AF0CF38E37C1ULL, 
            0xDCC167813E190269ULL, 0xBC5ACAC4DA4C5D9FULL, 0x5C3CA8E3D0517443ULL, 0xCA676D986AAECA8CULL
        },
        {
            0x8FF9ACDAD0A1530CULL, 0x09C7066E8ABF2D87ULL, 0x8D0C804419975EA8ULL, 0x29EFD2DF63633398ULL, 
            0x4E32A474A40E6B90ULL, 0x50A2D48D9C09314EULL, 0xC689A387B00080A5ULL, 0x24F378F8941B1E94ULL, 
            0x76E6CFB690AAE512ULL, 0xD851A77BBFA28AAAULL, 0x8A0A6A58D31EE7B5ULL, 0x44FE3CE34D23240AULL, 
            0x50F826A2DB61255DULL, 0xDB834CDFCCAE4319ULL, 0x31CF1A88218311FCULL, 0x988E5069D0577129ULL, 
            0xF56DD646E5530643ULL, 0xF9C053B0EFD9D321ULL, 0xE3385CFBA615259EULL, 0xC9664609638DDDB0ULL, 
            0x9BC5AF7F63953B60ULL, 0xBFEBA7B1C44D7310ULL, 0xD91B30E0EED70FA2ULL, 0xB0AE7B29D66892D2ULL, 
            0xCD2B2BADEE1BFEDFULL, 0xE475FEF3DF7A6393ULL, 0xF3F00880B2D36F99ULL, 0xCD2C1F730D4B9926ULL, 
            0xA7B4A89B5F8C38E1ULL, 0x042D1CBDDBBFC09DULL, 0x0BC1E88EA2299983ULL, 0xCB1DFA191B70EE2FULL
        }
    },
    {
        {
            0xE9360A865576646BULL, 0x12F5D91C0C9FC1A7ULL, 0xD29B8B1C21386D7EULL, 0x3B95413CDC50F077ULL, 
            0x0D3A8FBDB06AFEB9ULL, 0x4F6265EBFC290B7EULL, 0xE15EB7537FB0C7A0ULL, 0xC2E49E00C7C80BACULL, 
            0xD156BDC7E1E9042FULL, 0x0589F55DD727DBAFULL, 0x43E13D38023DF428ULL, 0xD3EB8811980A0F91ULL, 
            0x3A380D3F62B11E38ULL, 0x4C54FA2BE99C0E4BULL, 0x91799C3B19D359CFULL, 0x52D911603422BE5CULL, 
            0xBB33B96033D4E6E9ULL, 0x99F1730E7EFFCF98ULL, 0xFD034E46C9B7DBBFULL, 0xE9D8E628E09253B7ULL, 
            0xD79B9DFC2165B011ULL, 0x0D5F86A05B3A8F6DULL, 0x16E252EBCE0F8D8DULL, 0xBBC734E9939821CDULL, 
            0xEBF04BA6E5B33A30ULL, 0x807AB6C5C518B4FEULL, 0x805D41D85880850EULL, 0x45E3A2852903D3A9ULL, 
            0x6A7268DFFAAD7232ULL, 0x971EB115DEC7C7C4ULL, 0x1C5580CB852A60E9ULL, 0x424AAC2DB1DBA9D4ULL
        },
        {
            0x820E3987BDE0E7B1ULL, 0x984D9DD61C374B28ULL, 0xFB14EDCB451D3CDDULL, 0xA3C1BE6361CE164BULL, 
            0xC91AC3C5F61C8064ULL, 0x0355C5B712C4D5EDULL, 0x6B7CDF2599E279C8ULL, 0x8DFB52D113B1DBABULL, 
            0x7FBB2213CEC16AC5ULL, 0xD3B389DE994E7E67ULL, 0xB6667E2796EC7481ULL, 0x9701FA860FDF7037ULL, 
            0x53BE1BF4F702B29FULL, 0x869A2508ECF8719CULL, 0xA08FFE90FBBD44CEULL, 0x9F6B0F660881D79AULL, 
            0xF814EE1D11A65833ULL, 0xDA270DB3049996C7ULL, 0x5C349673CB213988ULL, 0x44E29E2D25D2A526ULL, 
            0xCAFE934B8B23E31CULL, 0x9F7B62612CF5941AULL, 0x83CE0375A78D2191ULL, 0x8828951CC38C8AD0ULL, 
            0x355FB7047181F21AULL, 0x954DE30F167DAF93ULL, 0x9185544D9C1BB891ULL, 0x41D04D264483BE2EULL, 
            0x2ACC557435530B6EULL, 0x3DC4ACDA641C4456ULL, 0x797FF052BB9C6E88ULL, 0x78ABE63ADF93F53CULL
        },
        {
            0xE88C315B05BF8934ULL, 0x3AE1D51DC3C809D4ULL, 0xC3142F0E9D27CCD8ULL, 0x7E572BCBB9D47C96ULL, 
            0xBAC7C68E2CBECAA5ULL, 0x3BD786262DE3EB54ULL, 0x5C35313B34383714ULL, 0x4D7B129ECF387851ULL, 
            0x9483FED358B0C793ULL, 0x7FFF5CD8DFBA1416ULL, 0xFA205DDA0F27A9A4ULL, 0xE8B307CF8345FF27ULL, 
            0xD9317C5A27601B7EULL, 0x5CBC4A795546D0EAULL, 0x64830CF72700511FULL, 0x32DADA2623B1DDF5ULL, 
            0x84B5CE13536A481BULL, 0xEDD0BEB988816E80ULL, 0x5D8F15083C5007E2ULL, 0x71808F2279F3634FULL, 
            0xDD52D4DA1929AAE2ULL, 0x7762C25069044977ULL, 0x68EBA1BE99374576ULL, 0xBDA8674685E801E7ULL, 
            0xD444B07DF1E8D25AULL, 0x76116FEC2AA40F04ULL, 0xD72E6C681E5E4BA8ULL, 0x3D6F952841AD2541ULL, 
            0xBD1AC1E140B4DE28ULL, 0x9558A3AD401740D2ULL, 0x9BE623C5C289876CULL, 0xE5C452CF2CD57268ULL
        },
        {
            0x2AD5B36F4258EB73ULL, 0x52BE192D73C8C2EDULL, 0xD6C353CD6B8CF5B2ULL, 0x5C10B8105238B195ULL, 
            0x87F88E5BFC598E1EULL, 0x4DD68639C5142269ULL, 0xE2BBFEAD20E744B6ULL, 0x2643E76BB679A4BFULL, 
            0xBFF56947158D2726ULL, 0x000A0ECD13D7CA1AULL, 0xFF54A5B1FA8EB9CEULL, 0xB2A6BCEF9B5141EEULL, 
            0x5B3AE61B1946CE5FULL, 0x317784004B4B1CC2ULL, 0x08796F614F05549BULL, 0x911AF95242016A19ULL, 
            0x1DD5B6D8F5CE2378ULL, 0x45C8BA64C45D0F8FULL, 0x9720EA9C4E0919C2ULL, 0x8A518BFFD897D2DBULL, 
            0x0EAFCAE2320FF261ULL, 0x7D91068FD49DEE1EULL, 0x35E2E4E2E40A8F0BULL, 0xA919A676EEBD18E5ULL, 
            0x64B39304BD5575B1ULL, 0xA5D5BA6EA90FF3BDULL, 0x0771EB6778F520CFULL, 0x1C3B8AB87918AC9DULL, 
            0xD2143BB0C252DA10ULL, 0x91309DD3350AC134ULL, 0x1C769122E0BF0918ULL, 0x98243600AADD5A00ULL
        },
        {
            0x8A92A5E7B6E8ECE5ULL, 0xEFF05CD9C252D79DULL, 0x5817188334428C3CULL, 0x130F601B623F9799ULL, 
            0xB12D6E60A55AC1B9ULL, 0xC0061AF31A401059ULL, 0xD13C1678EB8B6D4BULL, 0x14A5173C1724C3BAULL, 
            0x8B89E8C2997C96D8ULL, 0x579BD619119BBE1EULL, 0x65D1CCBF2CEE8DBCULL, 0x46621A18548EC70CULL, 
            0x6AD0FC67FCD66CEFULL, 0x9BD830E5A4442A58ULL, 0x5F5BFDA1F7609845ULL, 0x392C50C0BD88DC59ULL, 
            0xF12F65DC75B5892EULL, 0xD729F7345B2FE41CULL, 0xD175B911BEE112D3ULL, 0xE5F7A148D998A566ULL, 
            0xAEE32B46C9288DF2ULL, 0xE41509B07BD180A1ULL, 0x3D4C6E7366B1FE3AULL, 0x8D8AAB10D58C5854ULL, 
            0x05F377148EBA95B1ULL, 0x39A7D3BC1DF93FB6ULL, 0xDDA84169EF0BD010ULL, 0x8875B7014A48094EULL, 
            0xDE7698E6AA78A487ULL, 0xCCA990307EBE8098ULL, 0x59717E8758E9F109ULL, 0xA173AADB68BDA871ULL
        },
        {
            0x59744EF3FB3CA8EEULL, 0xE6E3BDE4EA298706ULL, 0x8E1D27994606C40FULL, 0x032724A5C430999EULL, 
            0x2A67DF999107C493ULL, 0x72ACF5F675CBF6ACULL, 0x6C90902FAED43557ULL, 0x9FE70168C3ABA9F8ULL, 
            0x7F96754D5AA876F1ULL, 0x0EB9868A260EF583ULL, 0xA53AA2C62F83A4C2ULL, 0x06DBA60B0F53099BULL, 
            0x6F967746AB385520ULL, 0x8C039DE59068E762ULL, 0x8265B295AE9764D2ULL, 0x1A317D04842E020BULL, 
            0x84E4F8A1C9CEB6EDULL, 0x806126AC9AEB9916ULL, 0xD539CD57B3EE2014ULL, 0x1A7FF9C1BC026AF4ULL, 
            0x6A3EF9E5C3F0AD26ULL, 0x179CE15E38175159ULL, 0xC8AC532C8161CD97ULL, 0x5AE203D6DBCB2A15ULL, 
            0xC30E8EF0EDCB1AA1ULL, 0x7E7D079D62B5239AULL, 0x594EA40E9EA5B601ULL, 0x57042DD13FF1ABC0ULL, 
            0x41B509D5E89A4E0EULL, 0xF8C7E9828371A5E1ULL, 0x1C82BD44AD03B370ULL, 0x8422E73A93AFB912ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Naos::kPhaseDConstants = {
    0x42B51073229677E2ULL,
    0x83EC3AE43F87772FULL,
    0x143276413E701005ULL,
    0x42B51073229677E2ULL,
    0x83EC3AE43F87772FULL,
    0x143276413E701005ULL,
    0xF6BD42EA824A067BULL,
    0x2D291A4A507E3608ULL,
    0x88,
    0x84,
    0xD1,
    0xF5,
    0xBB,
    0x14,
    0x10,
    0xF5
};

