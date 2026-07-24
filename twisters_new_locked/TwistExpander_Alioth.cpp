#include "TwistExpander_Alioth.hpp"
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

TwistExpander_Alioth::TwistExpander_Alioth()
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

void TwistExpander_Alioth::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xCE8D67D1A67750DDULL; std::uint64_t aIngress = 0xDA441CA7A589A88EULL; std::uint64_t aCarry = 0xDC22110F696AD54AULL;

    std::uint64_t aWandererA = 0x8F47FA2E6C1BCD05ULL; std::uint64_t aWandererB = 0xC9B9BA2D9F59070AULL; std::uint64_t aWandererC = 0xE9486DC9587E90C2ULL; std::uint64_t aWandererD = 0xCBE3BFFA6FBC9970ULL;
    std::uint64_t aWandererE = 0xAD6E85BBBFF3FE5CULL; std::uint64_t aWandererF = 0xEC12A772E3AE52D7ULL; std::uint64_t aWandererG = 0xDBBC5C8EB36DCE52ULL; std::uint64_t aWandererH = 0x89FD674C6B350F07ULL;
    std::uint64_t aWandererI = 0x9D50A9E8C1B3B37AULL; std::uint64_t aWandererJ = 0xD21E6E2D9A2F696CULL; std::uint64_t aWandererK = 0xC1B50157E5B78A7AULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xCB3F3F8DCA721DF4ULL;
        aCarry = 0x8CAD904854A3FA33ULL;
        aWandererA = 0xB5442F31534D66D1ULL;
        aWandererB = 0xF9B628280435693CULL;
        aWandererC = 0xC9BB8F9199249C50ULL;
        aWandererD = 0x881847F67167D52AULL;
        aWandererE = 0xECC5FB6EC54A88F2ULL;
        aWandererF = 0xBBDF95A18268ABBFULL;
        aWandererG = 0x87F3E0940B7102FAULL;
        aWandererH = 0xBA1F3C6CCEBCAA84ULL;
        aWandererI = 0xADDD32C55BDAE98BULL;
        aWandererJ = 0x89A106A2EFF8FE5CULL;
        aWandererK = 0xFDF332D74EC2CC36ULL;
    TwistExpander_Alioth_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Alioth_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Alioth_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Alioth_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Alioth::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xEFD809BBADDB8F80ULL; std::uint64_t aIngress = 0xFA093E4ACF5ED527ULL; std::uint64_t aCarry = 0xD66DC3A3B9EC4C8FULL;

    std::uint64_t aWandererA = 0x8EB3EAAFAC502564ULL; std::uint64_t aWandererB = 0xCFCEA42A77E52BD0ULL; std::uint64_t aWandererC = 0xCEBCDE7C5C0AB4AAULL; std::uint64_t aWandererD = 0xADDB36D40EA33FE4ULL;
    std::uint64_t aWandererE = 0xC84B577A8C0C8D61ULL; std::uint64_t aWandererF = 0xFA756B1605080EEDULL; std::uint64_t aWandererG = 0x9DDBCF43BB44F65AULL; std::uint64_t aWandererH = 0xA408C7EB6AC81AD2ULL;
    std::uint64_t aWandererI = 0xD3067039B540C87AULL; std::uint64_t aWandererJ = 0xD96C0DB1F4ADDA62ULL; std::uint64_t aWandererK = 0xB4E3D67B08D9E491ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xEC18FD41F732CAD6ULL;
        aCarry = 0xE514365870310BF4ULL;
        aWandererA = 0xBBEAEEBA4D9A85C3ULL;
        aWandererB = 0xB6F172166C6AD19FULL;
        aWandererC = 0xDAFE6156FF4358F4ULL;
        aWandererD = 0xDB463CAD35F16680ULL;
        aWandererE = 0xA2FA71168B095DA3ULL;
        aWandererF = 0x87874824694287C8ULL;
        aWandererG = 0xC9FE32EABF1E3724ULL;
        aWandererH = 0xF93CEEF4E4DE4495ULL;
        aWandererI = 0x97F8A27A9A8072D7ULL;
        aWandererJ = 0x99EDB931D082EFB5ULL;
        aWandererK = 0x82F34BEFD70D9441ULL;
    TwistExpander_Alioth_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Alioth_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Alioth_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Alioth_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Alioth::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xFFAB46604F1D5AC4ULL;
    std::uint64_t aIngress = 0xAF88586D6C3ABBA4ULL;
    std::uint64_t aCarry = 0xEE9E4368283E4126ULL;

    std::uint64_t aWandererA = 0xA77C97A004DA21C0ULL;
    std::uint64_t aWandererB = 0xEE723F463960FBA3ULL;
    std::uint64_t aWandererC = 0xA202FF9CB86E6C99ULL;
    std::uint64_t aWandererD = 0x8F26E6022D3E2C35ULL;
    std::uint64_t aWandererE = 0xDFE16432C498C4C9ULL;
    std::uint64_t aWandererF = 0xA42C91F64E8B48D2ULL;
    std::uint64_t aWandererG = 0x8D3B131209FC4D27ULL;
    std::uint64_t aWandererH = 0xFCEC3D669632C587ULL;
    std::uint64_t aWandererI = 0xA47B63CE64C2D6A6ULL;
    std::uint64_t aWandererJ = 0xC4271FF363E6D89CULL;
    std::uint64_t aWandererK = 0xE6E3ECF49B36D402ULL;

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
    TwistExpander_Alioth_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Alioth_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Alioth_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Alioth_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Alioth_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Alioth_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Alioth_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Alioth_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Alioth_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Alioth_Arx::GROW_B(pWorkSpace,
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

// SmartSquash candidate 4 of 33
// Exploration cases: 100000000
// Nearest-family diversity: 1028 / 1088 (94.49%)
// Total distance from earlier candidates: 3096
void TwistExpander_Alioth::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    static_assert((S_BLOCK / W_KEY) == 16, "SquashInvestToKeyBoxes expects 16 invest fragments.");
    static_assert(H_KEY == 8, "SquashInvestToKeyBoxes expects 8 key rows per box.");
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 10U), *aFragmentB = aIceLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 10U), *aFragmentD = aIceLaneD + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1889U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1044U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 788U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 396U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 7U), *aFragmentB = aIceLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 3U), *aFragmentD = aIceLaneD + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1678U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 134U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 293U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 542U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 1U), *aFragmentB = aIceLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 14U), *aFragmentD = aIceLaneD + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 265U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1393U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 359U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1936U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 2U), *aFragmentB = aIceLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 12U), *aFragmentD = aIceLaneD + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 578U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1346U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1239U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 378U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 0U), *aFragmentB = aIceLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 1U), *aFragmentD = aIceLaneD + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1502U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 580U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1720U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1115U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 4U), *aFragmentB = aIceLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 7U), *aFragmentD = aIceLaneD + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1672U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 156U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 854U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 614U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 6U), *aFragmentB = aIceLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 4U), *aFragmentD = aIceLaneD + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1093U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1655U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 995U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1768U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 12U), *aFragmentB = aIceLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 6U), *aFragmentD = aIceLaneD + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 65U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1427U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 506U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1523U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 3U), *aFragmentB = aIceLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 0U), *aFragmentD = aIceLaneD + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1276U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1165U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1577U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 59U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 8U), *aFragmentB = aIceLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 2U), *aFragmentD = aIceLaneD + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 56U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 290U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 344U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 398U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 13U), *aFragmentB = aIceLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 5U), *aFragmentD = aIceLaneD + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1241U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 903U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 741U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1552U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 14U), *aFragmentB = aIceLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 13U), *aFragmentD = aIceLaneD + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 590U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1356U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1651U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 582U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 15U), *aFragmentB = aIceLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 8U), *aFragmentD = aIceLaneD + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1984U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1867U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1730U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 179U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 11U), *aFragmentB = aIceLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 15U), *aFragmentD = aIceLaneD + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1050U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1613U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1778U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1641U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 9U), *aFragmentB = aIceLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 11U), *aFragmentD = aIceLaneD + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 113U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 391U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 34U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 889U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 5U), *aFragmentB = aIceLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 9U), *aFragmentD = aIceLaneD + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 313U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1357U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1081U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1520U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Alioth::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xCCB582C33DB2DAFDULL; std::uint64_t aIngress = 0xC5376F16FEBF9DB8ULL; std::uint64_t aCarry = 0xFB1834CCB29ECE45ULL;

    std::uint64_t aWandererA = 0xE43EF1262822A1D3ULL; std::uint64_t aWandererB = 0xC26BEF8F7C15D0D2ULL; std::uint64_t aWandererC = 0xE32DFEF8051CD658ULL; std::uint64_t aWandererD = 0xF469C4B743B61AB2ULL;
    std::uint64_t aWandererE = 0xBFC5434D9AEEA43CULL; std::uint64_t aWandererF = 0xE5DD5F00C9B12242ULL; std::uint64_t aWandererG = 0xE074E6D56332C7BCULL; std::uint64_t aWandererH = 0xC982E367ED70E50AULL;
    std::uint64_t aWandererI = 0xCCF05877E8CA0A45ULL; std::uint64_t aWandererJ = 0x948ECCDBD7386887ULL; std::uint64_t aWandererK = 0xA79850DB33A72FACULL;

    // [seed]
        aPrevious = 0xFDED71DAB904E3D8ULL;
        aCarry = 0xC74CCB43B4B89F17ULL;
        aWandererA = 0xFA364B83F7BC6F71ULL;
        aWandererB = 0xEEC31CB1B0A25A19ULL;
        aWandererC = 0xD06E9F0F88A58EA3ULL;
        aWandererD = 0xC37A216550754772ULL;
        aWandererE = 0xEB99CCE3FE8892B6ULL;
        aWandererF = 0x969813D958FAE330ULL;
        aWandererG = 0xEADFAFB97AC7B422ULL;
        aWandererH = 0x8F5CC142976D9E86ULL;
        aWandererI = 0xA7D69D54DC0E839DULL;
        aWandererJ = 0xD45C2B339DD0471CULL;
        aWandererK = 0xAB21B3146E713F21ULL;
    TwistExpander_Alioth_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Alioth_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Alioth_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Alioth_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Alioth_Arx::Twist_E(pWorkSpace,
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
    TwistExpander_Alioth_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Alioth_Arx::GROW_B(pWorkSpace,
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

// GrowA candidate 4 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 1800; nearest pair: 595 / 674
void TwistExpander_Alioth::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1531U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4227U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3168U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7159U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4555U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 832U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1020U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5344U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5462U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2523U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6437U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5260U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1294U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3140U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6580U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2733U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 307U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 600U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1863U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1966U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 105U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 666U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 873U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1643U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 195U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 733U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1552U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 664U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 45U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1321U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 293U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1041U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 845U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1781U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1051U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1985U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
}

// GrowB candidate 4 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 1796; nearest pair: 587 / 674
void TwistExpander_Alioth::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2555U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3063U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7894U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2867U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2613U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2961U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1578U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2192U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7556U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6135U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5361U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5321U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4493U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4656U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2063U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5734U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1661U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1648U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 517U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1399U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 31U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 566U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 344U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 232U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 719U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 377U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1307U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 127U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1704U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1561U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 682U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 909U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1978U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 398U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
}

const TwistDomainSaltSet TwistExpander_Alioth::kPhaseASalts = {
    {
        {
            0xCFC26F0F40C34040ULL, 0x6DE57829B2B34FF1ULL, 0x299E3A6D02E3CE20ULL, 0x680B9835662B38A9ULL, 
            0x90C50E3D16794117ULL, 0xFAF938AA81446651ULL, 0x1C3F3359061496AAULL, 0x2260C52D76F5B5ABULL, 
            0xD85C5C2975A52023ULL, 0xD6BFE12EA400E806ULL, 0xE8ABDA2181B73DA8ULL, 0x4F1B5105341E680CULL, 
            0x784CB82C6569377DULL, 0x5737604E08F8AAB6ULL, 0x1175589CD82905F9ULL, 0xDDC2541D9E0DDB94ULL, 
            0x7D54F34E7FC0C883ULL, 0xA022037B02AB5098ULL, 0x446B62EEC3F39647ULL, 0xE97CE884387E6ECEULL, 
            0x3412A4DFA0A35AC8ULL, 0x4BB1811BC95560EAULL, 0xFF38C215B690EDA7ULL, 0x0583D67A87EAB7CEULL, 
            0x868D56321643C6DEULL, 0x5CE04FBA37D671D3ULL, 0xE25B9714719F0122ULL, 0xFAA4D4A5A89E2C88ULL, 
            0xE94C5726FFCDA5B1ULL, 0x1F47EFC00E2325B3ULL, 0xD9F535A2F226246CULL, 0x7FB78C8B4E30ADDDULL
        },
        {
            0xBB2696DCB8267508ULL, 0x5EA4363DA2B3FB34ULL, 0x60AD8EE71E53516CULL, 0xCAB151DF32D6426BULL, 
            0x4F7AF20A36DF3225ULL, 0x4A2C23797BAC1CB6ULL, 0xD429D1F8A6A4435DULL, 0x789A1E7847053D8EULL, 
            0xEA58C078EA31297FULL, 0x5DC36CD71EBF48D4ULL, 0x6B4CCC6BB20ED7BBULL, 0xC2A98AB173C930D4ULL, 
            0x27C83FD66586B611ULL, 0xE3B1F51B2636D291ULL, 0xFFC5E17BBDA8F311ULL, 0xA653E5F539136EB1ULL, 
            0xF0C31B08D9442287ULL, 0x82693C43A6AC01F1ULL, 0x15D0C8747B25F232ULL, 0xA82B570C1B96CD88ULL, 
            0x47906F679E65253AULL, 0x926E4564BE5CA705ULL, 0x9CBDA74EF1A92CC4ULL, 0x9D203D8D00CF2D71ULL, 
            0x563AB6E48E614FB9ULL, 0xB408FC6CBAA394B3ULL, 0xD98A32D1E7C6D8DDULL, 0x851A3E59AEA9E852ULL, 
            0x3802396110836C3EULL, 0x63F97BE0B1ABF4D0ULL, 0x31CE9D3A71914F3FULL, 0xA55FB12F0D6F2261ULL
        },
        {
            0x079C4900FC1B3245ULL, 0xCE86E0FC2382526CULL, 0x8487F9F46BA89588ULL, 0xFBA0C6686ABB31DAULL, 
            0x714A0C78EFED3445ULL, 0xE2F0CA322D454CF3ULL, 0x25A0E10315E39DC4ULL, 0xE0197003FE4A9993ULL, 
            0x7AAEEBADC9F0C14CULL, 0xC0FC88A611E9BE6BULL, 0xE056D908E50233F6ULL, 0xFDB87F9E0ACD18F5ULL, 
            0xE2EB0459871596F3ULL, 0x8681A1FF5441BE69ULL, 0xD8A6D6BF81389039ULL, 0xBBB405F5D30497AEULL, 
            0xF108E4016B879624ULL, 0x097C5598B1CBD174ULL, 0x845D468A85DB28C5ULL, 0xEBCD8A39EFE70732ULL, 
            0x3DE4031A1F608D44ULL, 0x4BEBDC542A6DE85BULL, 0xE53AA9B0A52DB9F5ULL, 0x27E9A5AF6F18B0EDULL, 
            0x672E05E482C67448ULL, 0xBB789F66DA0E5D0EULL, 0x9E22B9C0187AF78AULL, 0x811F2E08AA881E94ULL, 
            0xCF45929CED43D058ULL, 0x403280DC6002599FULL, 0x34492D0CD2088D87ULL, 0xF36992ECAA7B7F0BULL
        },
        {
            0x3E3F3E344AFAE089ULL, 0x7E37A07186C4C27CULL, 0x0D2DC9213A289472ULL, 0xDF487C1082ECBDC1ULL, 
            0x20D6ABA1897F1901ULL, 0xC624D63F3A121638ULL, 0x0DEA54F60C8075C1ULL, 0xD5C9611AE7E19F39ULL, 
            0x8A0AC498E92965C7ULL, 0xED8D00A45E7DCEB6ULL, 0x19F2D49C4BD7E14DULL, 0x41AB2F771EDC3279ULL, 
            0xCE0FB275890E0D60ULL, 0xB6ED3BD632588190ULL, 0x1BE7EECFB5E1D0F5ULL, 0xE8795E43B1701A40ULL, 
            0x2BD2A7742CA61E3FULL, 0x13BEC4467A60A6E0ULL, 0x5A823C77F6E5E373ULL, 0x1CC83E62384D19DCULL, 
            0x17C24623FEED8F0EULL, 0xD59551184B1BC1CDULL, 0xF17E7824289263A6ULL, 0x8895B286AC9827BFULL, 
            0x9F77A9B6643928D0ULL, 0x572003DB0229BF62ULL, 0xEBEC41196ECE43E9ULL, 0x27890A535D9E9032ULL, 
            0x2A87EFADD1DE9497ULL, 0x0B11F6A3B9BB50B0ULL, 0xCE8495DB5F9E2BD4ULL, 0xE081FD7200138BC8ULL
        },
        {
            0xEC4A4E8CA1F2C336ULL, 0xC172DD1CC919CDBDULL, 0xDDAE0723FEA76756ULL, 0x7716BF273E60C1EEULL, 
            0x7EC92D5F3800AB6AULL, 0x00FCE4445C802AAEULL, 0x988F1F12C5602CD4ULL, 0xF0C325C2D3B88829ULL, 
            0x1E8057EA1C9728B8ULL, 0x580BFA656540B052ULL, 0x07115F7C56B28045ULL, 0xB809D61C3C0D849CULL, 
            0xA8B6B30F33FEE015ULL, 0x63586C40E76FF7D8ULL, 0xBB296632326AC093ULL, 0xDD2BD1658AECDADDULL, 
            0xE89B8F872953B3EEULL, 0x219F1A518E2B9D98ULL, 0x4CF508D5D5D2A864ULL, 0xCFF6EDBFEAB82EB5ULL, 
            0x5E53DF6620CF6F84ULL, 0x42D80CA64B95E4ACULL, 0x10E65B5D37952E3CULL, 0x3312CF2DB5EEAA04ULL, 
            0x83242AAAAD1DF164ULL, 0x856B6D26B94BE032ULL, 0x06C77AF26D050FF6ULL, 0x05A7EEF1438A6F9AULL, 
            0x83D501E61459C738ULL, 0xDCCA9A3CAE2C8CB1ULL, 0x25C26CACAEE7106AULL, 0x02357C11D17475EAULL
        },
        {
            0x9F6ECF1036212CC0ULL, 0x91C39237D4B7372CULL, 0x1C8412E337F8F166ULL, 0xF15F8D41BD0D3AFAULL, 
            0x9634CFD19550979DULL, 0x188CF9F57E4DE0D3ULL, 0x446058122EE7BEE6ULL, 0x98EC773173223100ULL, 
            0x047B987D51769544ULL, 0xCFA998CDCCB5F1A3ULL, 0xB67CB1E302520ECCULL, 0xE2841AA30A845FF8ULL, 
            0x75F72F9130CD4EC7ULL, 0x9F362224892D8113ULL, 0xD1A212E3AD8AFF00ULL, 0x3D3999D8D50C5CA2ULL, 
            0xB7DF91D57EC5F415ULL, 0xBE6E26AADFF909E4ULL, 0xC259DF24A0310DD8ULL, 0xE81A01C136A7AAB3ULL, 
            0x2E11AB7C7C860CC8ULL, 0x5A4585DCB1DDF611ULL, 0x7B7A2EB897BE1045ULL, 0x8D7E4DA1B5A9F251ULL, 
            0xD2190D6FF7FCCC5AULL, 0x5894940304B8160DULL, 0xA81F873C4D793147ULL, 0x5717E658BEBBF32AULL, 
            0x9EF21A59B19F6852ULL, 0x710D55AF859D485EULL, 0x4752F8E780CE8B34ULL, 0xEF47D2D054987C6CULL
        }
    },
    {
        {
            0x83811D80CC3CDC95ULL, 0x903F71E13A3FE9D6ULL, 0x0F2842BA75C725EEULL, 0x5E5AC41F3690DBDCULL, 
            0xE08D8F003CE31550ULL, 0x0590C8A01FCC83EAULL, 0xE78841EF9BB17F5EULL, 0xB825DDF51130D704ULL, 
            0xABB34549750544B9ULL, 0xC3D9D9D71F47C7A9ULL, 0xDEF7BF560A2D049BULL, 0x37D458B2FE12FAA1ULL, 
            0x2622B59C90322FDEULL, 0x83B0E8F7F096CB8DULL, 0x67F9E7156F03D71DULL, 0x5214C5E49EC05760ULL, 
            0xA2F53A1D407E5DFDULL, 0xF706017557F2D66EULL, 0x8F5236F2E4A85B86ULL, 0x3DD2AD35595F2166ULL, 
            0xA94F3FFB80F06DB2ULL, 0x763CFA540695A860ULL, 0x4EC550D5EB5ADC4AULL, 0x1BD7FE45856CE983ULL, 
            0xDDE44DF08053B9CFULL, 0xA0D6E1161202AA05ULL, 0xFE33BC0B8652D701ULL, 0xBA1E99E1236FD48CULL, 
            0x295357E9D8C69FB4ULL, 0x431D54E240085243ULL, 0xC82364FAB3B242B0ULL, 0x44BBC840D61FB9B1ULL
        },
        {
            0x4541BD74D51C69C2ULL, 0x6C914D3C40799649ULL, 0x2CEBFD8B16422824ULL, 0x576C9D0C21333D16ULL, 
            0xB00C2919155B22F8ULL, 0xCAC9DE8720AF0101ULL, 0x9248014D650FC59DULL, 0x78AD87CB1857A3D9ULL, 
            0x283FFB6D9330581DULL, 0x866778DFA368E498ULL, 0xB7A16833625D5805ULL, 0x0BBFD2DC016CE63EULL, 
            0x615D62C6E324D073ULL, 0x74CE846CE0406885ULL, 0x8CD90F747263E31CULL, 0x4658C28C595AC1F8ULL, 
            0xB981399928037A59ULL, 0x3303052770C42A91ULL, 0x0E433F6E534F369FULL, 0x3CBD2617A032746DULL, 
            0xF8AA0871D39C2DEBULL, 0x9DDE593CB5CF9996ULL, 0x0AC13A646DA79C9EULL, 0x0AA3303A451F5D5EULL, 
            0xEA4BD9EA29E61E30ULL, 0xEA676D834604E96EULL, 0xCB376C15FC1550CEULL, 0x66C837A829582B01ULL, 
            0xD012A30FF945A518ULL, 0x26E11D17BA894A71ULL, 0xFC48F82136D76DE3ULL, 0xFE586FFBDBE3CB07ULL
        },
        {
            0x0CA1145DD4C56F23ULL, 0x65125F8D0FCB9770ULL, 0xAF611B7BA0A73BD6ULL, 0x689351C4ED18926BULL, 
            0x14C79932A233E9C9ULL, 0x79DAB06F64089DC6ULL, 0x98C77A3851A7A9E8ULL, 0x228098FB9B7EAD26ULL, 
            0x48F517D5E6A3B961ULL, 0xDF9A450DA92B29E9ULL, 0x8BC44BC03861A02CULL, 0xDB40B8B17F4A5B3EULL, 
            0x2E3DB1D3C6CC1890ULL, 0x4E01EC259F11C699ULL, 0xA7B328723CD25DF7ULL, 0x67698FC2AE5D2D0FULL, 
            0xC816EFD0CDD2F452ULL, 0x178ECE502F55DEB4ULL, 0x21BE6DE25FCBD665ULL, 0xD1335A63615CE046ULL, 
            0x64F20E8D3326A9FBULL, 0x12B65DF1BE48E83CULL, 0x4FF25FB337F9BCCFULL, 0x85E755265010C891ULL, 
            0x84671F6D0BD53C55ULL, 0x72DFACCEF74BA1A5ULL, 0xA00CDCD4D118D5DBULL, 0x62B61D803110526AULL, 
            0x3E3056ECDA2C02C6ULL, 0xCDD0BD7F0018B0BAULL, 0x8D745758EE43764EULL, 0x1EA7FB7D725F6A04ULL
        },
        {
            0xBD65F9AF70B05B57ULL, 0xD573E4544A0BC40FULL, 0x37E030489E5A8300ULL, 0x97D66DA43F375762ULL, 
            0xD46575D6E56BEE49ULL, 0xB2F9DA5772B41B2EULL, 0xE3F3141444270362ULL, 0x62B1189F2C5A8A21ULL, 
            0x08BFE2E5724A4D48ULL, 0xCD5C5A348C0AC35EULL, 0xE6D6D73BCB8E8181ULL, 0x20EAA3D8BE40B496ULL, 
            0x9F811BCD17935C50ULL, 0x6F8054C2D9078A6DULL, 0x2D59B4831ACF1843ULL, 0xD17A5DDB7438475AULL, 
            0x7F13A6414490EFCBULL, 0xDF1604B155CDA1B2ULL, 0xF6AE9DD40C4C0221ULL, 0x6C45028DC2BC1FA1ULL, 
            0x692980033B80F687ULL, 0x4CB1CAB85A92DE3FULL, 0x7EDF899346381C9BULL, 0x5A815E361F067FF3ULL, 
            0xEBF4B91B1E4E4450ULL, 0xB29453A430FA9867ULL, 0x7CCEC8E054E48AD2ULL, 0x038AC0A3718C7464ULL, 
            0x641328334180AADBULL, 0x02A123F2DA035966ULL, 0x27E4E3FB3F64BAABULL, 0xC7E9D359E4AC09ECULL
        },
        {
            0xACE06B12637612FEULL, 0x053FD3969227B4EBULL, 0x616F480302115F72ULL, 0x70119F567251949CULL, 
            0xEEA548D59D8E923AULL, 0xAC5AA0FB7CF89ECEULL, 0xD0EF56005F3E4930ULL, 0xF1809206A8267D87ULL, 
            0x553E59E48AA8AD45ULL, 0x17AA5D00B0FFA0D5ULL, 0x15F38FD5F236F966ULL, 0xE8DB23EB5E163841ULL, 
            0x1C85C0100ABEFB03ULL, 0x68EB5C09ABA8F423ULL, 0xBA387BA1E0CFF57DULL, 0x07A337D53B63F7E1ULL, 
            0x5AD61D990DDE0008ULL, 0x74C5B3ED7C1FE4D3ULL, 0xFCBAE066578A89A9ULL, 0x9EE7F385112C2E4AULL, 
            0x10CC5812AA60750DULL, 0xF68CDF9CCA7B4D7FULL, 0xDB2C6F78CBA254D3ULL, 0x7D596993532C3BE2ULL, 
            0x095526C430661802ULL, 0xEC57FE0BC30282F8ULL, 0x6695CF2D900FCA48ULL, 0x0E8C2EB10AFFBCE5ULL, 
            0x5F43522F93640983ULL, 0x9C59DDB2564A7CBFULL, 0xE6EDF2FF4AEBA2E5ULL, 0xC9E8E327421F7CF7ULL
        },
        {
            0xFB21A5D38E867361ULL, 0xD89B2DBAFB8EB475ULL, 0xDC1B7F9EE4F9D2BEULL, 0xABDED4E41C1C676CULL, 
            0x937FCCAE39319183ULL, 0xFDA094F301804E93ULL, 0x0602CF3C19792CDAULL, 0x0C9C825A797F1644ULL, 
            0x197217625ADC3140ULL, 0xE3973865CA5E2F5CULL, 0x01EB33575FEB703DULL, 0x6E2D1BCF1F25C658ULL, 
            0x6DAB12A1E5FC1D42ULL, 0x5C5B04B364DA30EFULL, 0x304DAF6BF0BB9502ULL, 0xCB77859BB1B48B46ULL, 
            0x60C39DA43F2E8F4FULL, 0xC55D772FEE80FCB4ULL, 0x293F51FB79C6D396ULL, 0xEEBE743EFB2B4A68ULL, 
            0x193B93A51FE19465ULL, 0x0CF59FD632D05044ULL, 0xF48FFB2A48EA351CULL, 0x0E921B506CD3F009ULL, 
            0xF293B2C7FDF5BA27ULL, 0x1DA9CA54433F89F7ULL, 0x5CF04FD1BE56C5E9ULL, 0x26361E45848DD3F3ULL, 
            0xB832D5550BC193C0ULL, 0xA4BBD0824121397EULL, 0xF997DF39B7F81033ULL, 0x44FE5234E70161D5ULL
        }
    },
    {
        {
            0x3726CC837D499B41ULL, 0x09A703BB43ECE22EULL, 0xDEC60EAC728159CBULL, 0x32537860B2AF1A8DULL, 
            0x1E8FE17B32C15F80ULL, 0x5A8D92FDEE51FAEDULL, 0x3E00D3BC6A6CA165ULL, 0x0A224F0FEE6FF786ULL, 
            0x2D1226F3D6AD9204ULL, 0x443BC19EF76E5A7AULL, 0x56DE063329541975ULL, 0x0C966755D4EC0146ULL, 
            0x6366ECF185E4B6C0ULL, 0x84DFC3709B34FAECULL, 0xF4588158AA62E57BULL, 0x9EF83E71B3E19958ULL, 
            0x7A9E53444E71D8C2ULL, 0xDD874BEA32595693ULL, 0x2831E7958A062BBDULL, 0x4195F8551BFA31CFULL, 
            0x77D1F1223A0CB7ADULL, 0x731828E0F2249C82ULL, 0x104595CF09AB1A49ULL, 0xBFB8C05F02FD8753ULL, 
            0x0709DE8ECCFF19FBULL, 0xFA73CCF8C6A36757ULL, 0x2A00285398A7F74DULL, 0xC15BF1D4875F5D23ULL, 
            0x4FB99935438EF103ULL, 0x1F5236946D0C8F50ULL, 0xF3538385D057AB53ULL, 0x9578F2443CBC1B01ULL
        },
        {
            0x5961EA7EE8DFF97DULL, 0x274E568ABE778478ULL, 0x0AFAA4D312B045E0ULL, 0x115ADE111FE6155AULL, 
            0x3B0718F6EDAB6B1FULL, 0xD8F7F82BF05CF1DDULL, 0xCABBE47017FA1B7BULL, 0x02ABA4E7A808F26CULL, 
            0xC11B83011AD7FF07ULL, 0xA052FECF088078D9ULL, 0xC686A183A4E812D0ULL, 0x172D3DBF8F199A10ULL, 
            0xD93D4ABD4765286CULL, 0xD1A4C7300BFF608BULL, 0x1E845671647ED446ULL, 0x9335BE76FAA3C878ULL, 
            0x93BF8A4B2FE0AF47ULL, 0x77E2FEB786D074F3ULL, 0xBDD66A94952103E3ULL, 0x6AF4D926FF3A2154ULL, 
            0xCAE7CC2922DBB0FEULL, 0xDC08F44510F63DD2ULL, 0xAB9AE15EB4426430ULL, 0x4E72978C2C4528CEULL, 
            0x887A5605B54447A2ULL, 0x46AECAA909DAA4E7ULL, 0xBC6354ED1E6EDB46ULL, 0xD227AA16252FB34BULL, 
            0x69E28CEA72244596ULL, 0x1E26699AD62E5488ULL, 0x76A60FAD288615F7ULL, 0x09139AD1E500EE96ULL
        },
        {
            0xCE6BBCC0E8AFCC00ULL, 0xDB24193234EA5A6AULL, 0x94C7DA60368F0F0BULL, 0xAEC334EF7FAD9FECULL, 
            0xD58EB3E770923226ULL, 0x351DE54799400EDBULL, 0x4678CC21C7B0BDC7ULL, 0x562157ABD2B2090EULL, 
            0x4815BF862900FB87ULL, 0x7CD5D39BF4636C01ULL, 0xE9472CA451B2C5BDULL, 0x6188ED570406D37BULL, 
            0xE3E68FCE433EE925ULL, 0x4B119F0F3B74D4BAULL, 0xD5361B449124F7D9ULL, 0x17F6B52CE0D4B57EULL, 
            0x1F1C2B2172A4F5DAULL, 0x044094B943DFEC03ULL, 0xC61DECA7C43597F4ULL, 0xC36C5695060C8133ULL, 
            0x511D6A0A121650E0ULL, 0x846ECA20DE72872EULL, 0x4F1EF8F62FDAA076ULL, 0x9BB8CC678EDC527EULL, 
            0x471BB8DFE2DCCB5CULL, 0xF80F12C32AFD7B0EULL, 0xF02FB866A39EC70BULL, 0x14A73D999A572C0FULL, 
            0x09E2C47A054F6FB3ULL, 0x5F0985CD3C198C9CULL, 0xACFBC9765773E046ULL, 0x65FD2458D35C5A94ULL
        },
        {
            0x08970630C833B6A3ULL, 0x1D7FC7747E200DDAULL, 0x58AC86FE56A412DFULL, 0x8F3CF73756E5B388ULL, 
            0xB60F7F67C6B1D5C1ULL, 0xF8ECEAF884CD9FF6ULL, 0x48728EF2350C857FULL, 0x8837A04F7815CDB3ULL, 
            0xC5F65038C9EE2D03ULL, 0x3050A4079D6B6E98ULL, 0xB9CA4D847526D750ULL, 0xE7CD62AA8139549DULL, 
            0xEF0414A6EC75FDAFULL, 0x72A540818DD47808ULL, 0xB3EAC44E30ED9F13ULL, 0xE38F753FFAB513BFULL, 
            0x99805296A1CE48CBULL, 0xA867BF0613D3FD29ULL, 0xBA7A266B284F07EBULL, 0xF2AB3770647A1D39ULL, 
            0x698BDD52CCF54AB1ULL, 0x535358768351A8CFULL, 0x9AB85340610C89F3ULL, 0xF6C4C93B65147F48ULL, 
            0xEA231F878B90FBEDULL, 0x83A27703ABB80561ULL, 0xB1B73E71E9DF3B45ULL, 0xD3CBBBC076CE09A0ULL, 
            0x4FC096EB724693EFULL, 0x728137D50371DE02ULL, 0xF8847D0CC2D69225ULL, 0x6F41A127F0C0439CULL
        },
        {
            0xFA3780490E477293ULL, 0x24C6427C72B99F6AULL, 0x437D5EADE8146F39ULL, 0xBF79D4D8BADC4A8EULL, 
            0xD36F1BF6B2CE4DF0ULL, 0x53A680E0310A51FCULL, 0xDA3A89B093B84157ULL, 0x2180E6870C825A51ULL, 
            0xE5564C227B539C36ULL, 0x002978010AF2E0D2ULL, 0x884409D5AA48B555ULL, 0x6656F9DC396BD595ULL, 
            0x744216697FD1DCADULL, 0x9878244F00974A63ULL, 0x670575D81FA4922AULL, 0x72B3F501D08D9CDDULL, 
            0x79D64EAF1F0668C4ULL, 0x3171D7E42CEDC588ULL, 0xFD908A0123C5B039ULL, 0xADD11BA669EBE541ULL, 
            0xBA04E7E47E159FF8ULL, 0xF9DE2CE7DB34ED46ULL, 0x54E1DD09FA72A86FULL, 0xBCBD7262A83ACB91ULL, 
            0xE6CFF71155238529ULL, 0xA6C431B33DEC5127ULL, 0xBD0AA6F2639D13C9ULL, 0x13A868CD4B4C0AB5ULL, 
            0xAF24EA363E519C9EULL, 0x4A51DB17A57788E0ULL, 0x433BFA4A67424FDDULL, 0xED7B5EE37D640BD8ULL
        },
        {
            0xCCF339170A24D26FULL, 0x30DA5FC09830D9B8ULL, 0x78448AF786150333ULL, 0xE6C1C2210E1055E3ULL, 
            0x58CB3A7538B84FE2ULL, 0x2082D3209673E90CULL, 0xE25EC039EE5C64DBULL, 0x60A219BFA27BD1D6ULL, 
            0xB9029DF6DD09976BULL, 0x7F7A7FE7C19EE1B9ULL, 0x9477F2E89105D88EULL, 0x17A0809575633C81ULL, 
            0xC76C6DDF3F24DDA3ULL, 0x8502420F4DE894EAULL, 0xDE0A940C85C86BC5ULL, 0x40AA6297F7B832EDULL, 
            0x600049389A239824ULL, 0xF1900C0D5407124EULL, 0x4C4823BB429AD7D3ULL, 0x7DA1B3AAF1294506ULL, 
            0x5E6B1A97CD09B3EDULL, 0x1FD67A3028C10C77ULL, 0x7930DAD407A137B5ULL, 0x4A249A99A3A0B979ULL, 
            0xC82EF02807E4A6D7ULL, 0x829A5027BEC8A3E5ULL, 0xDCF346FFD5040DDBULL, 0xBB739EC565B480D3ULL, 
            0xE836EB403124C135ULL, 0x0BD2C6B3DD8DA38CULL, 0xD52FF1FAA2775633ULL, 0x09369C6532B53368ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alioth::kPhaseAConstants = {
    0x4345D629C90A033EULL,
    0xB7D3036C8A9720FDULL,
    0xE129B156C878F734ULL,
    0x4345D629C90A033EULL,
    0xB7D3036C8A9720FDULL,
    0xE129B156C878F734ULL,
    0xDDC39CD1146717A7ULL,
    0xFBDFA01D6FED42ADULL,
    0xDB,
    0xE6,
    0x22,
    0x24,
    0xC2,
    0x7B,
    0x99,
    0x5B
};

const TwistDomainSaltSet TwistExpander_Alioth::kPhaseBSalts = {
    {
        {
            0x7B8F39892A233DBFULL, 0x0A890323AC88AD68ULL, 0xB55C5EA92B0CFB52ULL, 0xD95DED9E08C4DF41ULL, 
            0x878D1F777E967C5BULL, 0x547DA57A49419A2AULL, 0xD296839A873D56B9ULL, 0xBAD3E0536686971BULL, 
            0xCB9D9F0629C90EB6ULL, 0x63FDC3F64D86966AULL, 0xD916463894454632ULL, 0x118ECEE4F332D973ULL, 
            0x289ADDC6D342CE5FULL, 0x2795AF0A6EE9A3F7ULL, 0x9620D97A526DCCB7ULL, 0xDE82A8688180BEF7ULL, 
            0x280AF556CE830F7EULL, 0x8BF95A550B4810DFULL, 0xF773EF98D1640C41ULL, 0xBABE1248166DCDC6ULL, 
            0x4FA5CA21D209264BULL, 0xA5DF45724B68A2A9ULL, 0x911C537C56B3B110ULL, 0x791C1E278156A8BFULL, 
            0xE346B1CCD51997BAULL, 0x748FD2E78FA5F5E5ULL, 0x8D160CF25F04A801ULL, 0x293EA047D8A47196ULL, 
            0xABD63F149AFBE9FAULL, 0x30D37F23B811BD08ULL, 0x9D928AA37A543BE3ULL, 0xB39DDB4E32810318ULL
        },
        {
            0x425596A672828C2FULL, 0xE11869AA10F6C3DBULL, 0x049EC82852D77ED2ULL, 0xA3CBF78E2BE5915EULL, 
            0x3AC20476935FC570ULL, 0x24AF3CE5B4E92584ULL, 0x033C5123802FBBD8ULL, 0x69405E4C3DFCB067ULL, 
            0x33800DBF35D3B00BULL, 0x50230570C1CEFED0ULL, 0xCC1FC9A2935C88CAULL, 0xBB40C2E985FA9487ULL, 
            0x3E2C80AF15205B89ULL, 0xBA5E7047A24489AEULL, 0xF026AC243ED4A94CULL, 0xFEFE84652D6ED913ULL, 
            0xD7354E32094F9244ULL, 0x9D1E6D19704BAB27ULL, 0x054441E32D333DB0ULL, 0xD16E7D672D6CBC18ULL, 
            0xF5ABE2B58EDBD33EULL, 0x881A7BC8CE63B25EULL, 0x3B8C3719CC893545ULL, 0xFAD9EFAC8DA00288ULL, 
            0x3D6ADDF0EE62F6D7ULL, 0x5D463FD6AACB7E0EULL, 0x1CF9182BC055BEF1ULL, 0x309779AE536D0AAEULL, 
            0x503910E340D03625ULL, 0x806330ECC24E561EULL, 0x3B05F23D27C3BCD8ULL, 0x7496C7CA3C2A39F2ULL
        },
        {
            0xA94F07CA10D8FF36ULL, 0x466299C97EBBCA52ULL, 0x38B25DE67782908CULL, 0xDFE50FCBB2007F9DULL, 
            0x9EAF4394BB5B1DB5ULL, 0xB096BBF12AA6F408ULL, 0xB9A7CAB3B438F252ULL, 0x1965ECC5587DA6D2ULL, 
            0xF2D8E2C46250F8A0ULL, 0x51CEC78C4C38E17BULL, 0x25063889B96CFCEDULL, 0x74F11AAB23BD6AE3ULL, 
            0xE49667E76023C8D8ULL, 0x639EF49255B8B17FULL, 0xE6B3FBA363BCF884ULL, 0x258E2FD62428A215ULL, 
            0x9AC3C3FBB5261B05ULL, 0x6C724C342990E3E7ULL, 0x50F127A95F6D4BD5ULL, 0x4E43295C8E2B89CBULL, 
            0xD3F4A5B8F3AC3CD9ULL, 0x59D638576ADC4E7FULL, 0xE1C4EC931B6E21CDULL, 0xCD74A5C79ADF51F9ULL, 
            0xD16C1AD13D6A46E6ULL, 0x60200F7127EEFB2CULL, 0x6D2883CDB573AA27ULL, 0xC606815FB29FFC26ULL, 
            0xB75A296B52AFCB40ULL, 0xFEF36AC741CA805DULL, 0x6D3457F388B90153ULL, 0xDE2D3ED26B9CC54FULL
        },
        {
            0x26BA0E4CCA4D3B8DULL, 0x82AA2040D1774088ULL, 0x724FBB7591F4CE06ULL, 0xFB8CA0E0804161DCULL, 
            0x4BFA88C75C4FF40EULL, 0x2B34923970823C4FULL, 0x2B17F23076DABC9BULL, 0x3B2526273571A555ULL, 
            0xDA88FDD1464EF6A9ULL, 0x8892CB6D5DB83359ULL, 0x653C4C8773587044ULL, 0xC8C6BD8F18638842ULL, 
            0x430724D9414F0947ULL, 0x75F0596AB4166F97ULL, 0x1B47B88BEF51B56DULL, 0xD36284895F719832ULL, 
            0xC2681A978809629DULL, 0x4E0004550CB7C803ULL, 0x35FE9E9ED64C1BBBULL, 0xB4DF5509B3AF4C08ULL, 
            0xF87DD43988F3A75FULL, 0x53FAD3C326BF4A6BULL, 0x99958782436D877FULL, 0x5CCE1A686BFA1E7BULL, 
            0xAB75A508B6A79C05ULL, 0x3CA098DD1C3F6134ULL, 0x2C2FF88A92EDF3DBULL, 0x1B30DC50D9E9860BULL, 
            0x2B3870027CDC21E7ULL, 0xE5F38CE93040109DULL, 0x226258D366EEB823ULL, 0x200EE0F51131A790ULL
        },
        {
            0x488E4616349C6D04ULL, 0x335A88CA4AA63221ULL, 0x3F04B5138BD0D69AULL, 0xC7B2B016109983B5ULL, 
            0x9F1E2F890B611A97ULL, 0x04B9219263EC132AULL, 0x5689FC4F08C55004ULL, 0xD3D2592F54DA7203ULL, 
            0xAE0774BD2347CDD2ULL, 0x2D7D86A296394F96ULL, 0x2D8DB50F3271C459ULL, 0x9E6DE9C441C24044ULL, 
            0xF1B2C641691B4159ULL, 0xF220F3D93FF760F2ULL, 0x6D1F982760DE9CEEULL, 0xEA85643B514BE3F2ULL, 
            0x102A3176AFC2E9A4ULL, 0x65628E37AF2707C1ULL, 0x91F2E56C994D03BBULL, 0xBA054CCA5C07F900ULL, 
            0x77B260E582CFD1EEULL, 0x7EF2F237FE12813EULL, 0x43F2658CED6A8EC3ULL, 0xE8F26F6EFA2F78F3ULL, 
            0x2E785971B78C5140ULL, 0x293D898413D9C473ULL, 0x937169D1AEF0150AULL, 0x301829FC547E0968ULL, 
            0x8D7471F0DC01EDD1ULL, 0xE6D2643EA4CE82A6ULL, 0x713DBDAA5EBE2A5BULL, 0xEF64D986B252E63EULL
        },
        {
            0x25E41DB1823AD787ULL, 0x322294653F5315E3ULL, 0xDFB3C781198AD8DDULL, 0x8C68985ABAC0A086ULL, 
            0x6D36D501B71728B3ULL, 0xB060F2665706B711ULL, 0x15ACF8362F4C6525ULL, 0xAA4628FC101EE35DULL, 
            0xEEE2EB6B9614AF3AULL, 0x815862FE9286A90CULL, 0x12B982CD2974ABDBULL, 0xF74A96F7E4B5D356ULL, 
            0xFFBB97D7D1E949C0ULL, 0xCAD2BC8EBBF9306EULL, 0x9CC13FEA5F9F6505ULL, 0x2834130C1BDE38DEULL, 
            0xBD982DC90E3265B2ULL, 0x1D03400756942354ULL, 0xF72A88ADDEFB9C2BULL, 0x48F3D110D043A4ECULL, 
            0x9FECD995AD34EE5FULL, 0x98114E6AF1E43CCAULL, 0x081A78D4401A3EFEULL, 0x060B0CE68A5FC2CAULL, 
            0x6BE4E2CC02AAC3A6ULL, 0xBB5C59783BAFCA22ULL, 0x2C7ADDF1AABB3BE0ULL, 0xF870D278F2B0E1DEULL, 
            0xFA96C725A7E205D7ULL, 0x924C8C6D5DB7701AULL, 0x36957E1474F70141ULL, 0xA430A50E7A78C0FEULL
        }
    },
    {
        {
            0xB6F5655293FE27C7ULL, 0x679A805C42B50FD8ULL, 0x71938D64FD08C648ULL, 0x2D20EBF130BBC751ULL, 
            0x608C063CB0C59A8FULL, 0xC6E353BAD564B81FULL, 0x89E8117A7772701FULL, 0x21822884FD5F72B3ULL, 
            0x3715EA7EBB211B1CULL, 0xA2A78DC816C3B8A5ULL, 0xDAAAEA1EB8477BA1ULL, 0xED8FB0380D51C4E1ULL, 
            0x7CC8108116F86FEDULL, 0xEDF3EDCDA4B399C9ULL, 0xF805371CC614D880ULL, 0x95FE2AA505261E4EULL, 
            0x28845CB448D8AA2AULL, 0x648D714A59445F16ULL, 0xB81FE882BE218C2FULL, 0xD51723D0866F2F4CULL, 
            0xA4087B0CF227D157ULL, 0x3125F2959D4661E8ULL, 0x71A82EF5AB3B2F7BULL, 0x4B2FA9293B25F31FULL, 
            0x0F1B179B9024B22FULL, 0x92114F574CEB0D4AULL, 0x124E18306B23024CULL, 0xC75882427795ED80ULL, 
            0x264B1C99817674AEULL, 0x3B45648E186A35D2ULL, 0x5C148ECD830C4053ULL, 0x0705567EC92A67C8ULL
        },
        {
            0xFFAAE26D0D9AC80BULL, 0x1B926736E6CD4EEDULL, 0x2F091509BC9F15C4ULL, 0xEFE3EB1F4E67B6C2ULL, 
            0xD3C9BE499A9881C8ULL, 0xD15D73AC7A400AFDULL, 0x2C6308CD31908E83ULL, 0x27DEA0593E3AA6C0ULL, 
            0xC164C20555C826CDULL, 0xADC5290AB5523D96ULL, 0xF177ABAEEE5C40ADULL, 0xD3FBA0D9B60D407FULL, 
            0x947FD4C5044ECEFAULL, 0x794DABC858754E32ULL, 0xBAFC0A7A4A1E1174ULL, 0x9A4F15DAD0E924C0ULL, 
            0x93A2CDBEF8B353FCULL, 0x03D67BB5EE9665A0ULL, 0xF1F37E4D8CD4E22BULL, 0x69B9AC52F133B1E1ULL, 
            0x50E6EC30EE380E26ULL, 0x465DDEF54B552D62ULL, 0xEEE90D21C444C288ULL, 0x3F124C7122F55B1DULL, 
            0x78079B3A1E10DAD1ULL, 0xA08417EB092F6AF9ULL, 0x423C077E576FBC3AULL, 0x6FC80842B9BBE2E6ULL, 
            0x8DF027E0B3943C5BULL, 0x1F897B7C86E94776ULL, 0x8AE8168FEEEDF3C2ULL, 0xA2CB3B9EF193BC2FULL
        },
        {
            0x05BBD7FAFCF3BAD7ULL, 0xE036A0E184A1959DULL, 0x14D8E15E0A036E90ULL, 0xBC3B16A90E9BBF1DULL, 
            0xF01D2E83C6B6B265ULL, 0x40D3095C470C7269ULL, 0x6ECE1B6CFF1C0C7BULL, 0xF4278046BF80B3C0ULL, 
            0xB0467C380DFB2D8FULL, 0xDCF57B490F6882CBULL, 0xD8790CCDF510EA73ULL, 0x62C23CB693C7A15DULL, 
            0x64B42EDA1C25ED0BULL, 0x5B270A43CD954788ULL, 0x0AC3CC29730B3B6AULL, 0x5CE54DA70B336CB3ULL, 
            0x16567C2776C8791DULL, 0x88AFA2288291D31CULL, 0x50D54EF7FA4D53DAULL, 0xE0FE3BE21B2FD71EULL, 
            0x9BB09FCA7291BDDBULL, 0xB9B811AA4BEB1E58ULL, 0x95D773E70324F82EULL, 0x229353CC892E232FULL, 
            0xBA1C7A3D3E00177AULL, 0x14E309A356BB82DEULL, 0x4CAC08A743E1DD14ULL, 0xF7694CBC93FA9069ULL, 
            0x7FDB98AB647CB837ULL, 0xDD402EF43814A0BEULL, 0xA3DBC2D99089FD94ULL, 0x534CA0D4A0BAAC6CULL
        },
        {
            0xD49081FFE60BD123ULL, 0xCFBEAEF1530EE9F1ULL, 0x3811FBA5327A06CFULL, 0x0A406D1D13F392E6ULL, 
            0xA89829B22B396CDBULL, 0xEC019D1FA0041DAEULL, 0x3453AC228D4A0A5FULL, 0xFA27148313144532ULL, 
            0xC00FF20E66A27FB6ULL, 0x5395DA62809A27E5ULL, 0x25E717CD1E056816ULL, 0x3DF6A08C2557B5EBULL, 
            0xEA40697393A9489BULL, 0x2C0DC6D18FE1C0D8ULL, 0x8197E77A534EA804ULL, 0x77675C33F2D050D1ULL, 
            0x0D9C4E11C9063146ULL, 0xD9FB23FF8F79F6DAULL, 0x33E64823B1A443EDULL, 0x665B8B783D66E2C9ULL, 
            0x4EAE74566FE8C0EDULL, 0xDAAE4BBBDEDE57DCULL, 0x80B8AC352E212C5EULL, 0xE0B43AECA1235E9AULL, 
            0x3E7AF89C3DC4F7EAULL, 0x01050BE31AB59ECFULL, 0xED4CC9E43485BFA4ULL, 0x562E09ADA00D6E16ULL, 
            0xEA88693FE5D52D0DULL, 0x77300A431864DB87ULL, 0x1D01754B9DBCAD62ULL, 0x09E062F8837C4430ULL
        },
        {
            0x14377A5C3B79B312ULL, 0xCBAA88F1DCE48E19ULL, 0xE931C6DE0FFC0989ULL, 0x1F086CC31E65B346ULL, 
            0xF66163BDB65D998DULL, 0x275361D10A205432ULL, 0xC278DF7E9D98C185ULL, 0x3676006EE4C98166ULL, 
            0xB74426EA7B45156AULL, 0xA7C0D9DFFAD7985AULL, 0x0E388916717BCD24ULL, 0x0EC69E073E498B9AULL, 
            0x27A838F7CA3BEF2BULL, 0x9A9A921CD8C9FD7CULL, 0x9E6DB238C0A71278ULL, 0xAEC8D556D3F19E25ULL, 
            0x9DE64ACF77C2E605ULL, 0x6B791152B9002867ULL, 0x0B956B2E9D0A580EULL, 0x94FA781660F70DD6ULL, 
            0x8F12CE3DED7B24A5ULL, 0xBDF9F39EFDE01DF0ULL, 0xB5881E560252ED99ULL, 0xFA073C4C3D21A0CFULL, 
            0xDA0F7E95FC810A1DULL, 0x51BD90AD6FCD0E6BULL, 0x83A7333B2DCB3335ULL, 0xECACC9C0A42276C6ULL, 
            0x24E054B340F4D942ULL, 0x286043CB0E24ACA9ULL, 0xD8AB060CB8916D58ULL, 0xF463A048544E7A83ULL
        },
        {
            0xE112D0A91BC5C21DULL, 0x2086F22AC1C7559BULL, 0x12E29DAF3C54A068ULL, 0x56B63B3FAA67C0A5ULL, 
            0x7FDF5710E7338EB1ULL, 0xD28E2C400DC4C21FULL, 0xBD10AA72FB19A103ULL, 0x0EFFCB31ED988852ULL, 
            0x84C047A3377FDD2CULL, 0x41E34FCBA3DFCF9CULL, 0x801870F7D71BD5A3ULL, 0x3D476FDC2469F40BULL, 
            0xB9594600B048E1FDULL, 0x557381443E132E8DULL, 0xD5C0E41C5F7D06B4ULL, 0xAC0A62B46D98BF67ULL, 
            0x071138CB7C1A169BULL, 0x9890D878EF0B64F6ULL, 0x92D0DD153B4E3C9EULL, 0x2DC3C392C70A2F53ULL, 
            0xC59770BF24D0A133ULL, 0x449F2F14B4E648F1ULL, 0x9E461C84543BA449ULL, 0x6F2FD3062C2AF924ULL, 
            0xCB4271225108EA93ULL, 0x824F542630BBD660ULL, 0x5C732F69F9F473C8ULL, 0xA3A2532162B17737ULL, 
            0x7ECF0C4DDB165D59ULL, 0xCF8D714FB431B45CULL, 0x2076BA6B05125828ULL, 0xDDAE373D61245C6FULL
        }
    },
    {
        {
            0x50E04CEBC04937F2ULL, 0xEE9E447895574FA9ULL, 0x362F6AEE5D843EE6ULL, 0x16491F34A351CB73ULL, 
            0x57DAEC16CF378774ULL, 0xA604043B0C01AA81ULL, 0x494B195D93D9DD1FULL, 0x00C8C0397660219CULL, 
            0x0A85DEEE9CF7C357ULL, 0x7C276BD1B24FEE95ULL, 0xAFDC5F58DEFC1F4AULL, 0xE9EEEC63E62EC3C0ULL, 
            0x5C6CE5C1849536A7ULL, 0x62A47DD7F84C3A9EULL, 0x4E30AA6911EB2CA8ULL, 0xAE4408EBB4947EA1ULL, 
            0x0D3E564F8F0C50E1ULL, 0xC56E7274AF8E03C5ULL, 0x03B89657A70F1F60ULL, 0xF5E82E3FE1B30BCAULL, 
            0x4C5130FC381BFD45ULL, 0x1D2B6439B69184EBULL, 0x551B9A71360DD3DBULL, 0x96DDC98A3FF1BDB1ULL, 
            0x73B732F5C1F6C8ADULL, 0x4A0E015C794AEC7AULL, 0x9565B1810F48F6B3ULL, 0xBCE26F05F17DAC61ULL, 
            0x4841F9C4F37D9864ULL, 0xB1C8DD4F82DA49DFULL, 0x2906C5B9DA059DDAULL, 0x92ADFAF6C30EB707ULL
        },
        {
            0x0BAA9EE794697CFDULL, 0x0CAF447A2F042745ULL, 0x484A4F7794F9CD45ULL, 0x45B2B279FBC451D5ULL, 
            0x8E5260DCFD3E20ABULL, 0xC540BFA21E45558FULL, 0x2AC07AFB0BE6F171ULL, 0x404DB1442618244CULL, 
            0xBD33BD4306C2479CULL, 0x87D805C8CE4D4AA1ULL, 0x11B9893E05EE7684ULL, 0x20148C1EBE76B10FULL, 
            0x2FF51BC085F85BF2ULL, 0xE9009DD54EA2591FULL, 0x0BF5C77576B2227FULL, 0xEB4CAC0A24B5DE17ULL, 
            0xF8FA513AF21D41FEULL, 0xCA12189DB91190D9ULL, 0x40FDFC3FE838D257ULL, 0x3B708F53A8B696ECULL, 
            0xB6421BC92EB4BD19ULL, 0x767B189E1E215953ULL, 0xFDD1E1EC10864D51ULL, 0x89529B98B0DDAC2EULL, 
            0xB918FD9144A5199AULL, 0x12E5641762B1511EULL, 0xEA3230EFEC230C4EULL, 0x071DA9A0A7269032ULL, 
            0x95057CAE690BB0B1ULL, 0xCEAD93940C56593EULL, 0x01B0378D25564D97ULL, 0xA8653279626697DEULL
        },
        {
            0xE51A16AA3FE673E7ULL, 0x24C211436FCBB63CULL, 0x9FB4827F50D2CC03ULL, 0x299B055AABB65E28ULL, 
            0x18FB68E4643AD67FULL, 0xFFA7C65A50EFF2B9ULL, 0x98E8AF70DBDC3304ULL, 0x824DB2A995008D31ULL, 
            0xFF898372679CCBAAULL, 0x003A5311B04F2C4CULL, 0x5BDB5A09ADA76667ULL, 0x4C3CE3DDD21A86D4ULL, 
            0x1CD5F8CFB5285713ULL, 0x8B79315C5DD421A9ULL, 0x0E97A6ADA0C3807EULL, 0x8973ACF585952ABAULL, 
            0x718464FA714ADE61ULL, 0x4E6969198BE7CE3AULL, 0x7F9B2E93A6F8AA0CULL, 0xD8A63579530F0FF2ULL, 
            0xDBFBA9306ECC9A29ULL, 0x47C330A6D3532BBCULL, 0x74C68C591E3F482CULL, 0x73A8C55CBAE75C17ULL, 
            0x18321977B23668D0ULL, 0xC2B45D8B4EED501AULL, 0x6AD8C6A793870AC3ULL, 0xA03099E798417A9AULL, 
            0x92C8AD817403DE47ULL, 0x964E9B572A1BF920ULL, 0xC6076F01A3D862F0ULL, 0x7B3605232BD682D3ULL
        },
        {
            0x25F92A7393B57ED3ULL, 0x6E95B247CFE0AC0FULL, 0x085FD1DD390876F9ULL, 0x668853E22A7F97A5ULL, 
            0x896B68F6DE1A9BA4ULL, 0xC604418076C777E8ULL, 0x53C80FCABF05DB2CULL, 0x1698BE8719D32680ULL, 
            0x2FC20A070C03CD62ULL, 0xD16ED96A31943D02ULL, 0x215313DE0E847B59ULL, 0x0A200522055F7015ULL, 
            0x7ABF2BBFC82760E1ULL, 0x6406A93AF9694E06ULL, 0x2C2761D21E3CC630ULL, 0x7904239DE62A41AAULL, 
            0xAD9F87D604DC1B30ULL, 0x1833DDDFACB47E5CULL, 0x47FFDAD3C40A42BCULL, 0xF1C89406EDED5D2DULL, 
            0x1716940E7CD20486ULL, 0xC377038DB8566157ULL, 0xBBB6AAC7A102F841ULL, 0xB61FF76DC09A37CEULL, 
            0x1A5082C21BE2FEB0ULL, 0xF7A747C896848BB9ULL, 0xCB52A8E071421787ULL, 0xE4331A964D7B8EF4ULL, 
            0x0CEA3E8EFC3B3943ULL, 0xF1036FBDE3F8B1A7ULL, 0xB328CBA12A2E02ACULL, 0x63330E8477274D07ULL
        },
        {
            0x23FEE98B5BF2686EULL, 0x5135C1C0688450FAULL, 0x544DE4B8C56C0FA5ULL, 0x81449B81904FD5C1ULL, 
            0xDB482295A0C65D47ULL, 0x8E9399903CA3F45FULL, 0x838C8D52974FAA6EULL, 0x226E62AF206F7570ULL, 
            0x0CB6D37CBC19DE7BULL, 0xECC27E070B91F408ULL, 0x5CC9FF47929916F5ULL, 0xF04D5FC7244C6887ULL, 
            0xF46589AE4029DABEULL, 0xF4F7FA0943AF32D5ULL, 0xFCEBD724863949F5ULL, 0xE2C151F3327AEEBAULL, 
            0x95E8B6E2C131AACAULL, 0x3CB04C81820114A3ULL, 0x37052035D50AA5A5ULL, 0xF9CB9CAFA4860BDDULL, 
            0x74524790F6A7E588ULL, 0xC11DDD44905DFC79ULL, 0x46F5B0FE934F8293ULL, 0x672D9CEA45BAB95FULL, 
            0xC97E92A22E5E0DC0ULL, 0xA65E2C8DFDC81E36ULL, 0x4CC44CBFE7D868F4ULL, 0x23725945E7627854ULL, 
            0x736EF5F27ADE4030ULL, 0xBF5FAC1ADDEB53BBULL, 0x37F113E530D76136ULL, 0x5833EC938E25903CULL
        },
        {
            0xFE3C48D080B1E733ULL, 0xA5A5B11878DF0C60ULL, 0x065727299AD8101AULL, 0x64CF4BD19168D917ULL, 
            0x7CC9710BE12AEA69ULL, 0x2FE65383C2A26074ULL, 0x5BCF4F6B3B2E1D51ULL, 0xA1F2ABBE8D1611A6ULL, 
            0xBECA9880B94F1459ULL, 0x416A29098862DA85ULL, 0x34E2BBEDDF9DE056ULL, 0x7E6B2F380DA577ACULL, 
            0x57E6CBA26430D461ULL, 0x1C7A5C7B551323DBULL, 0xCAE23ECE8C6A088DULL, 0xBC3B8136B950634DULL, 
            0xB5525485CEF3673AULL, 0xEC8F0CDCC6891535ULL, 0xE9D61BC4F3CF75FAULL, 0xFC3304F3837842ABULL, 
            0x16AF6F2076E2340EULL, 0x7ED515276DCABC97ULL, 0xFD93EBB7D91FE70EULL, 0x7743C4865126C13EULL, 
            0xB429754B11038633ULL, 0x0E0C91513008C892ULL, 0xBB2AB71BF27B2017ULL, 0x4A5B6F0F4AC52728ULL, 
            0x6270813098BEF847ULL, 0xFB55066296863CDEULL, 0x0DF15D818981ED36ULL, 0x1BC967E4615F883CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alioth::kPhaseBConstants = {
    0xE3E708E93EC247F3ULL,
    0xE61ACCBD2BCD7D69ULL,
    0x272E97E204DF7EDAULL,
    0xE3E708E93EC247F3ULL,
    0xE61ACCBD2BCD7D69ULL,
    0x272E97E204DF7EDAULL,
    0xBC2EB20A1B04406EULL,
    0x5F07282F91E50D92ULL,
    0x56,
    0xE9,
    0x9C,
    0xCD,
    0x90,
    0x08,
    0x3D,
    0x07
};

const TwistDomainSaltSet TwistExpander_Alioth::kPhaseCSalts = {
    {
        {
            0xD3FD149130D963F8ULL, 0xD02F464B67644F2BULL, 0xBC3385F3BD68CD90ULL, 0x4B50405A24A636DDULL, 
            0xC12F8E35256676A7ULL, 0xEAF79F13F5F980C2ULL, 0xE22551F27BE90F77ULL, 0xC66B17CC05AA5C52ULL, 
            0xA816AE349616A4F7ULL, 0x2DE8A6252A336F69ULL, 0x737DC8DBF1EDCD32ULL, 0x9C9B9C2E07DDE727ULL, 
            0xB6B0BFD4A21ADC18ULL, 0x2F7D6870C6936104ULL, 0xB47F0AAE9C8DFFADULL, 0xD7CEA010FC99D202ULL, 
            0xCD8D292FA1251A29ULL, 0xB3C6A83D11CDB635ULL, 0xB221325E3996BDDEULL, 0x02132982BCDC2C75ULL, 
            0x54CD648C1D1E199BULL, 0x3EC7C489F518EB27ULL, 0x1E9D528A8B14DE85ULL, 0x9BC87F2E510201FBULL, 
            0x3E5770347270A0A3ULL, 0xC32443D800C18314ULL, 0xFE101A2C9934A8C8ULL, 0x31029EF3236AFD2EULL, 
            0x5C29C9C60D271751ULL, 0xE3748ACB8BDBDF57ULL, 0x2400EE80BE3305DBULL, 0xB5D45B0017B51177ULL
        },
        {
            0x40603CECB9AA90CDULL, 0x07AFB70FEBF3FCBEULL, 0x6DD3702442540BF3ULL, 0x2EE0BE06949F2771ULL, 
            0x112B59DFB34CD0EEULL, 0x43DE54FC2472695EULL, 0x93B2094AE3DBBF40ULL, 0xE7A579AA03A34874ULL, 
            0x2CE1F0AC6B5DAB65ULL, 0x35F07AAF4AEB3F9BULL, 0x39B06AE8618CD51EULL, 0x29A63E9AF95556D1ULL, 
            0xBA7EB7D0BBF2F0E9ULL, 0x27DD9FE7FBDBDA68ULL, 0xF1833B9243A7C14DULL, 0x958125A2F3751DA0ULL, 
            0x4AC584B0286CD3EDULL, 0x130AA8CB77994743ULL, 0xEE1AC52889B29E02ULL, 0xA13724D47901565AULL, 
            0x56258FB38844E640ULL, 0x79CC26F1384FF4A7ULL, 0x053D23767CD3C456ULL, 0xBABF177BE5DFEF27ULL, 
            0x992798C3DE4D98AEULL, 0x44D1C4C92138A3A7ULL, 0xADBA8A3DEA6B1A10ULL, 0x0D1AD7789FDBB4CAULL, 
            0x195B47AA36956101ULL, 0xF4FC04AF84D76D0EULL, 0x03BE13E2A591202AULL, 0x8CE8CF3C605A2C15ULL
        },
        {
            0xDBBE714D28B60877ULL, 0xC8A705E47909A623ULL, 0xC89AAF32C641EC8AULL, 0x98F4F4552BCD417AULL, 
            0xF8710F119D4AEA73ULL, 0x20710B78FDC6BCE1ULL, 0x8968011B25C6CC99ULL, 0x39F8F6F6A3791701ULL, 
            0xB6A0034D5DA6334AULL, 0x530E9F6258ABC9D6ULL, 0x98F016BFE3957B07ULL, 0x8A945DE9F1AB8FABULL, 
            0x0C4F483B6E0CC974ULL, 0xF329C7A1CF0924B1ULL, 0x89C8300575BFF047ULL, 0x953A220406E377B6ULL, 
            0x3D5CF2B0881406FDULL, 0x36D70F4378F5D250ULL, 0x32AA2D900DC0AE2AULL, 0xEC79193DEFF6FB75ULL, 
            0xDA1213B59597C4A5ULL, 0x783B7886B893A01FULL, 0x420A3B1750529316ULL, 0xC09958B3A211D87CULL, 
            0x2CFE7A68B8B706E2ULL, 0xA6E4E652B39BC8C9ULL, 0x27C17DA6FFD56D70ULL, 0xCCE24A293880B309ULL, 
            0xCE8EA0A7784CAAA0ULL, 0x28CBBF22F40B6C5BULL, 0x7B4DEDC86506546EULL, 0x839F8CE30996AE62ULL
        },
        {
            0xF60CCFCF22E59665ULL, 0xF03CE63EA09DCE47ULL, 0x8F034AC06D549CD0ULL, 0xAD5209083E1D25FBULL, 
            0x4FF952C9E6E0DB50ULL, 0xB20D3A2B5D534D32ULL, 0xC3CFC38A8B663922ULL, 0xDAC800CA7887324FULL, 
            0xAE51808B048A188BULL, 0xA8A9D4B75DE7CF92ULL, 0x4017820F8C87BDD6ULL, 0xDF77E3AE1637FE39ULL, 
            0x05E3DF9AD8C2CE41ULL, 0x27E04E6AF9E4D8B6ULL, 0x87C581E04937B590ULL, 0x7E3F5A2CEC41D6CBULL, 
            0xBE0598F5CEB28AC3ULL, 0x0560673DD5BAE376ULL, 0xA1040AA8EE8193A1ULL, 0x8F136A43AB2F4ED4ULL, 
            0xFBF8788A4A8D6A58ULL, 0x472DB99020DAE9ACULL, 0xAD7904BD186DB779ULL, 0x2693D814084AD868ULL, 
            0x177E7297E5BE931DULL, 0xDFEA68319DA99659ULL, 0x358FF5D3C45BCF6EULL, 0x62B1220D141504BCULL, 
            0xE2A374EDA1314912ULL, 0xB126A30DCB94F340ULL, 0xFA28463C81F81878ULL, 0x8F309AB11D412BCDULL
        },
        {
            0x14922904D87D76DAULL, 0x9E2FD8ED99FDCFB0ULL, 0xF26A3ABA4041529EULL, 0x9349071EE2679062ULL, 
            0x292E726E93E1C68BULL, 0x6E1E7A88778839B7ULL, 0x7BA5B9927F6CA7AAULL, 0x19D3C7496498BD48ULL, 
            0x5D921810D3F1A3AAULL, 0x0DACB37803DD7B56ULL, 0x3847017B71F92A82ULL, 0xF6D6D7324B1AB51BULL, 
            0xD6C02985D569CA1FULL, 0x9EC374AA6EA4E01EULL, 0x36E95516ACA6BE1DULL, 0xF6E7E37542905897ULL, 
            0xE6620E85040BE0A8ULL, 0x682CAE33A5774B7DULL, 0x955BCEB9A14BB6F3ULL, 0x3541AFDB2986B557ULL, 
            0x71CA520C163EDAF6ULL, 0x31EAB6BB6E66474AULL, 0xA830CE13D78751C5ULL, 0x76595780A9DA7C08ULL, 
            0x2E6BB786A88D327EULL, 0xC8F55F19E52970C0ULL, 0xFE7E54D97ECD04E1ULL, 0x5C15E042476D7C4AULL, 
            0xF974502D1DF8F9E2ULL, 0x8ADFD5759FDAC5AEULL, 0xFBE1D64F56C3152FULL, 0x910705FB821A1C40ULL
        },
        {
            0x91B813EDE8B5E07AULL, 0x8E1AEF71836BBFDEULL, 0x6D6B49A268E39980ULL, 0x0A4A80744481430FULL, 
            0xB0E38193F917A910ULL, 0x30F8E185898C9FE9ULL, 0x705F8EB41761B499ULL, 0x35E8E9907824ABB6ULL, 
            0x7D5934A9C6641CCEULL, 0x5D84AD1BEC18212DULL, 0x4431E6F594481FBCULL, 0x543ABE03ACEF21F5ULL, 
            0x7F12F7B7A1B8BC1AULL, 0x5A4F5EA5C5A72434ULL, 0x77CEC05F5BF890CAULL, 0x0386EC75ADED9D6EULL, 
            0x90C65792C3FEEE7AULL, 0xC97A61EBF75D84DBULL, 0x87CC8ED49742ED6CULL, 0xF6EA21EB68968E2DULL, 
            0x452FDAAC07F4B561ULL, 0xD01FF67C35A5E400ULL, 0x61703C19886E8FEEULL, 0xD739DBF82B87FABAULL, 
            0x1545FCCF0878C670ULL, 0x4F489CABC6E142EEULL, 0x46AFB171A7264771ULL, 0x4415C4BAF81B9CA5ULL, 
            0x08D0EAD2E453D4F6ULL, 0x25D5433DF727B92CULL, 0x41140DA1D0D2BB89ULL, 0x280E8432F0CCDC1BULL
        }
    },
    {
        {
            0x914A55FCB5C5C665ULL, 0xB97504D1374E20FCULL, 0xB376E1E90FD55F56ULL, 0x457C344E4EAB0806ULL, 
            0xE0599B450CD22AB4ULL, 0xB182337201E78F1FULL, 0x0487F52FD9B1D65CULL, 0x2A2F55D0CEFFA6EBULL, 
            0x9F9BDC676639FAC2ULL, 0xCC9C64AD583EACC3ULL, 0x9009EC411E5B2414ULL, 0x4F983A3D4ECCE328ULL, 
            0x22BB8DB2B59A7214ULL, 0x1860413FD3BBA2FBULL, 0x9D8E7C162696A7A1ULL, 0x6C943224459A7487ULL, 
            0x36078AA98625CBD9ULL, 0xC3A72DBC524BBE68ULL, 0x7ABA71902686DB0AULL, 0x4B52396512F42CCFULL, 
            0x8ACD91CA2EB3DA6DULL, 0xB4936856175F2C25ULL, 0x96E6ED2E72D26B9AULL, 0x0846B0DFE3A24839ULL, 
            0x193383F3FD8DD057ULL, 0x2C08740BF48ED3FFULL, 0x32890AE88BD855DEULL, 0xD41D0A382113DD9FULL, 
            0xAFAF10DF66DD2B03ULL, 0xA32817BBD99539DDULL, 0x89C3B4E8F0E8EF13ULL, 0x24A73CBFB1E3ABBBULL
        },
        {
            0x9C1434B804F47CCBULL, 0xB1D1A2F0CA9AF88AULL, 0xD2D75E2BEF353A87ULL, 0xD6DA23F78B8DAEA5ULL, 
            0x6E4BCB6B0B7CEA38ULL, 0x27D9B2DF672EE957ULL, 0xA00DCA5606D869F3ULL, 0x453A00AC6522C000ULL, 
            0x9CC4F9EA4D870C08ULL, 0x46DC979709D5631BULL, 0xA426A607B7EE6E43ULL, 0x7B120ED3E60DD9CBULL, 
            0xFDD51EA4BACCF13CULL, 0xD1876832E656848AULL, 0xF3D25D3FE3AF3617ULL, 0xC99C1BB7D3EE2AC0ULL, 
            0x00B6DCFBE93CD6A5ULL, 0x4F8FBEE268AE3B0EULL, 0xE6FC1A0F2722B44EULL, 0x38C2BEFCE896D245ULL, 
            0x96F8DD9A5E5C6A4CULL, 0x390FE983341ED378ULL, 0xE9B10102AE34FC13ULL, 0xC20F494BE3E65EA2ULL, 
            0x133F0BDD96B484BEULL, 0x50735E278F9E64BAULL, 0x349D361B42E6CB00ULL, 0x8F85DA380A1F62BAULL, 
            0x4F98B4F0FEB7F016ULL, 0xB5882072E239613FULL, 0xC7060AFCFFEB2171ULL, 0xB9A44D4739E0B9ADULL
        },
        {
            0xC3AE3C7B94539039ULL, 0x3405C34604845960ULL, 0xF9F4DE8BA0E20AE8ULL, 0x0B4DB256F6E515D7ULL, 
            0x31F4DBA0B8D72FA4ULL, 0x0DD2AB0171F4F509ULL, 0x38938FEE0F8EEA6CULL, 0x176D959314596CDCULL, 
            0x3394242CD354A3E8ULL, 0xD142F4CC484C174DULL, 0x1437719D19EC84D8ULL, 0x7C2E96FB0B6317AFULL, 
            0xFDD7085C6830C48FULL, 0x8A7DF8F07A696ED7ULL, 0xDE9341D92B8916F4ULL, 0x844998A0DD412C52ULL, 
            0xC5D68311CCC8BE69ULL, 0x809E63359034E6F5ULL, 0xA631E3B90A865976ULL, 0xB04EDE89CD6501F1ULL, 
            0xC9470F0F2AD06013ULL, 0x83FAAF355CC80602ULL, 0xD9695078A74D6B33ULL, 0x8AFAAA293D2734B9ULL, 
            0xFCEDF3677FDBE1CBULL, 0x92D6A7D500E270BBULL, 0xE5EC3A32CD7EA22BULL, 0xDBAD460F2D7A3E97ULL, 
            0xA0B061F21AFB44A0ULL, 0x5B5BF5BDB0A48825ULL, 0x71B3AE1612C4F44AULL, 0x24931AB1DDF26C8CULL
        },
        {
            0x2C2A1094A04FA44DULL, 0xB1B773CAB1E55CB9ULL, 0xB439DE95D5196D42ULL, 0xAECB146839D0667FULL, 
            0x5B9DB4B194099D8CULL, 0x9EA606FF51AFA0D1ULL, 0xA5C3C7DFFE6A1AF8ULL, 0xF582236BEEC30FF3ULL, 
            0xCD4E1C97A03C2136ULL, 0xDFB4203F56B6CF23ULL, 0x7A0DC245CC23CEA5ULL, 0x0C9D74C2FDC70649ULL, 
            0x1E81C64395C31812ULL, 0x531598D893E833A5ULL, 0xA8D8A7E8AA777D83ULL, 0x0C9EB114AAB8BF1DULL, 
            0x7934DF44C1EE7E08ULL, 0xDA61C58E85F62DB3ULL, 0x21D12A95E1186856ULL, 0x50224FA16D2B6830ULL, 
            0x02CE37938C657AAEULL, 0x82BC34F0F647A98DULL, 0xC9599915508121DBULL, 0xC3E64ADD2F455AC5ULL, 
            0x1CDB634A290867EFULL, 0xD80AB33876FF65B7ULL, 0x9FCD1F2CC12C9F2AULL, 0xF00CCE15FFC2843CULL, 
            0xEAFD8395884FCE49ULL, 0x2374B33E7475D501ULL, 0x8C1CCBDDE5AB4CEEULL, 0xDF365FBDDB89FF96ULL
        },
        {
            0x4020A7B048673956ULL, 0x46AA176B87D6FAE2ULL, 0xE6EEC72FD8B19D99ULL, 0x03C8DF6A34FF5DA6ULL, 
            0x4B3D9BD80B6B017DULL, 0xE854ACCE38129998ULL, 0x0079CEB50FDD7DFCULL, 0x47003AC9AF4E4E8AULL, 
            0x91C018C49F29C645ULL, 0x3A674CE5C3B034BDULL, 0x2D519519B611B253ULL, 0x0531A088820FE3B8ULL, 
            0xA5E729ECC9CA63A1ULL, 0x6F4ED1BA17ED4D8EULL, 0x92AC256DBDF56D24ULL, 0x5795E96A934023EAULL, 
            0x7F1402EC9DBEB0EBULL, 0xBBD5DBDE94ABDA14ULL, 0x822D799EDA0BF266ULL, 0x7CB19ED248BB4A39ULL, 
            0x73EA2041B8A3E835ULL, 0x9B5A02CACBCB9FEDULL, 0x2FC30B56364A38F2ULL, 0x9E0958BFC2D3CEA7ULL, 
            0x01C8216341D7C769ULL, 0x14BFE852087F4A36ULL, 0xFBCEF6EE68A8D082ULL, 0x6A638D9D86108CE7ULL, 
            0x46CABC2786FE6B28ULL, 0x1A2612AF272D394BULL, 0x617ABBED1264CFF0ULL, 0x9B7C46E8B8FEB860ULL
        },
        {
            0x01B1A6EC1C6ECD37ULL, 0xBA4326F44C646B43ULL, 0xE4A96454C7BED137ULL, 0xEBB4355D963C9D3FULL, 
            0x7FF52B4225577D09ULL, 0x81278A1B778E24E6ULL, 0x85DD2DED60FE2459ULL, 0x798619211001313FULL, 
            0x1DF2FD00632DBEFFULL, 0xCA940B912CC95D4DULL, 0x94CAE61F94E6D9B2ULL, 0x61CEB83CE934ACBCULL, 
            0xD71DC900A1C03E72ULL, 0xA95114F2569F1FC4ULL, 0xE939BC74C61330FDULL, 0xA611848A0FAF8997ULL, 
            0x46C39D1551B32ED6ULL, 0x641CE5FFA6753985ULL, 0xA5AD54848BD82FBDULL, 0x05F11A4D730CCB36ULL, 
            0x64E4971DB13E9547ULL, 0x7811FD168BC8B09BULL, 0xFAA1B614FB375429ULL, 0x649F202F62D47E12ULL, 
            0x80540B99F80F5040ULL, 0x2BCD85754A5E5CE3ULL, 0x0CDCED2B3874B239ULL, 0xDD129845153B7395ULL, 
            0x59A112E035717AABULL, 0x16D7C3FA87D7FF9FULL, 0x8D45973CBEDC96A0ULL, 0x0E2C7A10FC3DCC6FULL
        }
    },
    {
        {
            0xAB773E3179D3032CULL, 0xCFCC57DEBFEF9389ULL, 0x9926CCA4CA878AF4ULL, 0xE674458E0FDFC63CULL, 
            0x261E61389FBDBF59ULL, 0x92EED42089F48E48ULL, 0x55FEAE147AB5B9BEULL, 0x1F64A1CD4C8BEAD3ULL, 
            0xD546F8608A009294ULL, 0x558D7C8D6D0AE1A4ULL, 0xCC30A6A13B50DA6DULL, 0x2C53C9E508831821ULL, 
            0x1CD14AD563B14294ULL, 0xA9B226889E9E7E47ULL, 0x41C886CDA390D223ULL, 0x9539FC00985AF955ULL, 
            0xE9D4D692D3CF0CCBULL, 0xC4C438AC2ABE35EFULL, 0x5FD809AE3EF34388ULL, 0xBA7AE18FFDEB2E60ULL, 
            0x0F8BF5DD6321B1F6ULL, 0xCBA8FD05096E690CULL, 0x6F7243ACBFABB13FULL, 0xA44CD7B6EAD465A2ULL, 
            0x88D825216474E11DULL, 0xAB4554C57E679F4BULL, 0xEBA99F14989D66BFULL, 0xDAF1199C24FE7704ULL, 
            0xAD572E7EB9B2B8A7ULL, 0xD66B7B88B30D9200ULL, 0xFF5E67DC9D9EF350ULL, 0xDF5BBD5BE0ACD61FULL
        },
        {
            0xDFDA968839CA35CBULL, 0xC3A8C7504C7918D9ULL, 0x1FEABE94AC5C5890ULL, 0xE22F8FDE9D6B661DULL, 
            0x794C466A10A9AABCULL, 0xF38DBC3D3DACF170ULL, 0xA762F2765609847DULL, 0x6792DC8DEC7D3CD3ULL, 
            0xC483DA9316DC9283ULL, 0xAEAD510B52E7B2E0ULL, 0x17D6E22984319C3CULL, 0xA0B6E7769292A5C5ULL, 
            0x6A663EBA52C81628ULL, 0xAA5655988684A6E7ULL, 0xE86AD413070FF9D5ULL, 0x3DF78F1CDE75EB31ULL, 
            0x4C3B96105A02FCD8ULL, 0xD3BD3C82B056F2CCULL, 0x58011200873031CFULL, 0x966817369FBE2FD0ULL, 
            0xB8865C9B0CE52ACDULL, 0x2D6448BF6DCE984DULL, 0x04D0CA27BE1842C9ULL, 0xCF26AE169C5A6161ULL, 
            0x330F577716767615ULL, 0xFE6EF354852B64ECULL, 0x66ED44614E655EA5ULL, 0x73F9932BB152026CULL, 
            0x62360A8AAC3DE6A5ULL, 0x803F0D23A592D6B5ULL, 0xF8F57850117BE0E9ULL, 0x0837260731944E94ULL
        },
        {
            0x8B2F0F312B43B8C3ULL, 0x6FBFC23B1873DC1FULL, 0xE037FE40F280AE2DULL, 0x9325CAC6D35C5CDCULL, 
            0xE2AE3E3CA7AAE54BULL, 0xFDD892B01B1C7E6BULL, 0x4D9939E927BBF44AULL, 0xD4A7D6ED4A2D5982ULL, 
            0x6F8A463BAC2B2A40ULL, 0x05E5E603B65D5FFBULL, 0x2F0CDD2B01F96751ULL, 0x9DCA1011F6716763ULL, 
            0x0E6483342899E3FEULL, 0xCF9EB921B135F6DEULL, 0x8454E5E3D6D28A49ULL, 0x8665888AD7047605ULL, 
            0xC317ACFF70B815E1ULL, 0xA0891A4F165D3A60ULL, 0xF4442A8110DEB468ULL, 0x6F14D13E3836FD1BULL, 
            0xCCE9038124088BD8ULL, 0xDF6FE3CAC8F6C89AULL, 0x350A57BEEC3CF954ULL, 0x08B90031BC9EE2D8ULL, 
            0xE6746A1469C3A0C2ULL, 0x7FCE54DE94D86B87ULL, 0x820F59CF72B98555ULL, 0x680526674E93EE14ULL, 
            0x2AA22A402645EEACULL, 0xCF8A64CC7C425A82ULL, 0xBE6E84C94F6A14A7ULL, 0x1DD3391A8A00B39EULL
        },
        {
            0x444484AEBC0522B0ULL, 0x6AC86FF538CA8399ULL, 0xCA1826C1F1BB40CAULL, 0x15DCB889E2C73F50ULL, 
            0xE38042BC65795815ULL, 0x9ECDEFDE316F3C53ULL, 0x49D106020D2C5AAAULL, 0x8882027156112DEDULL, 
            0xDA45641A42082370ULL, 0x0C2511FECE9AEF96ULL, 0xFCE359FD12DBD150ULL, 0x5826254737F8BF64ULL, 
            0x236D01DAA92C2E5BULL, 0x1CD7A7D9BFDD5C8DULL, 0x21F8FE218E50E442ULL, 0x8FAC45753379B445ULL, 
            0x822CF8EE9E3A195CULL, 0x4FAF7C3E76974C88ULL, 0x3687220792CC908CULL, 0xAC170BD83C7DD658ULL, 
            0x5FB1D8EA5E1BF120ULL, 0xDF3FFED407ADD195ULL, 0x4892DD3958998B12ULL, 0x703322711CC998C9ULL, 
            0xFD3EBB4F1F41602DULL, 0x7CAD119BDE2FCC8FULL, 0x13C6B9D97433CAA6ULL, 0x508EC90AAF4CB7B6ULL, 
            0x4CA5F9996DF9E96CULL, 0x6FC4B776E821D577ULL, 0x8CD0B66479AABAFAULL, 0x5A0103AF0F59DCD9ULL
        },
        {
            0x573A2078323028F8ULL, 0x18E153E0876B19A5ULL, 0x8B79CD60EF5D81C1ULL, 0x575782A4A867B25DULL, 
            0x0967E4D6E58CC50DULL, 0x8565EA20C0699A5DULL, 0x541BDFA7C0082DD5ULL, 0xEE6D8D4244602478ULL, 
            0x177FA3C9A8FC526CULL, 0x3254C4AF0D3298D2ULL, 0x2CC26078D8E1B265ULL, 0x5CF61BC67E1091ACULL, 
            0x2BA51811EE6824DCULL, 0xCE00D120DAA7590DULL, 0x6A4D521AF8BE32EFULL, 0xD3894562C1FB5AE8ULL, 
            0xE479F24E1309DDDEULL, 0x17F50F4BEAA53A88ULL, 0xF463D262D77D8AAFULL, 0xC68A28A1F9D63632ULL, 
            0xDE721EE2EB9AC50BULL, 0x63AA2E135D5FA61CULL, 0x60EFE863E180650EULL, 0xF3BF9CBCC57BA5DAULL, 
            0x410A4E2F1541946CULL, 0xCAFE2BC83FE6E519ULL, 0x105FF33FA7F33B0BULL, 0xB4C3A931F82F4DADULL, 
            0x8B7EE6D8CD696A95ULL, 0xD27942B897265FE0ULL, 0x3C6AA9273F7CE733ULL, 0x4C9B171B0A2F33FAULL
        },
        {
            0xF988E1650B1A9D4DULL, 0xF20B139F7D4A8C1AULL, 0xA460E44B9ADCE5A9ULL, 0xE879B86BE632D58DULL, 
            0xD817AD7A237E4B25ULL, 0x909A655A1E749F1AULL, 0x0D63C6808801AD3BULL, 0xBBAA0C0BA4B4AE81ULL, 
            0x433C7FD70D2DE26CULL, 0x9E4BE723E38B7761ULL, 0x289924B2A0937C30ULL, 0x208E82B8A0AB33F8ULL, 
            0x0492EA48E07FCB7CULL, 0x8D519FEBFF24E6AFULL, 0x1C574E750CFC4332ULL, 0x5CF3886ED6332993ULL, 
            0xA071D574DAD9D487ULL, 0xE177D2474A9B33ADULL, 0x1653ABDE414917E5ULL, 0x4A6A42854EFFF2C9ULL, 
            0x717E64DC5110E9D2ULL, 0xC9554E187166251AULL, 0x9A83FC531972C4B3ULL, 0xC926C3613B68E57EULL, 
            0x4FA788BCB2EE0C56ULL, 0x313496890E6098EAULL, 0x0A948356F829D4C3ULL, 0xCD86371003303273ULL, 
            0x1A31A99ECA0F0F08ULL, 0x6790E7A7131D98C9ULL, 0x083119E97E450649ULL, 0x5A8849AD97B2ED59ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alioth::kPhaseCConstants = {
    0x7EB58542F836236FULL,
    0x2B208D3A94EDC41CULL,
    0x487AAE80BCEAAFFEULL,
    0x7EB58542F836236FULL,
    0x2B208D3A94EDC41CULL,
    0x487AAE80BCEAAFFEULL,
    0xC27109D9682869C1ULL,
    0xB15F29EDD6553E7EULL,
    0x15,
    0x8B,
    0xE3,
    0xFF,
    0x99,
    0x18,
    0xC6,
    0xE6
};

const TwistDomainSaltSet TwistExpander_Alioth::kPhaseDSalts = {
    {
        {
            0x95DD7C1B121CA90FULL, 0x817D7B93B59C649BULL, 0xD46B2F9617F1C4DAULL, 0xF5858873C126F131ULL, 
            0xE6714E16EC28B1D5ULL, 0x74A900B84D5C420FULL, 0xEC4B3C1D97C62BE7ULL, 0x1B6F8C456BB3BB9BULL, 
            0xA22C8378F6101F76ULL, 0xD89476A0FD9B0850ULL, 0xF01EF4108364D69EULL, 0xCDC9942919B9105CULL, 
            0xBEB44A88B1EBF0D5ULL, 0x84F9A2C0C085A32AULL, 0xDE2F9FA1D6444C20ULL, 0xBF0A0DDE3243C644ULL, 
            0x1004C1FEA6EC54DFULL, 0x849AD20F663144DBULL, 0x7C37C1CE927A2287ULL, 0xCDFD1B0B49700773ULL, 
            0x5FA6ABBE8FBC04B1ULL, 0x5B47C6912FAED048ULL, 0xC0390ECA82D663C0ULL, 0xAA579FB25D86BF6BULL, 
            0x6101222428E4BB22ULL, 0x79D180B0CD9C72B8ULL, 0xD5BBC8228192EE4EULL, 0xEC3A552BA3BCD484ULL, 
            0xF880D969659AFF40ULL, 0x7D70D41D4CEF0833ULL, 0xE03EDEB4B88F6AB5ULL, 0x528E36E2740445FEULL
        },
        {
            0xA1ECD748B37C4CCAULL, 0x33A152EAF5150276ULL, 0xF3C5A3433E70761AULL, 0x31EC28DFC0A12DFFULL, 
            0x6D640BEF1EE849C9ULL, 0xC16AE9460E0AB2C9ULL, 0x2D84C751AC86628DULL, 0xB3CBBF602EF768E4ULL, 
            0x05D859EE6DA99F9FULL, 0x56CA2ECEC22C2DAFULL, 0x1060C680E65B4B12ULL, 0xB769EC6E7AC55645ULL, 
            0x18F2DD7211406037ULL, 0xF55C4583BCD564EAULL, 0xC9220F8C45F9F81DULL, 0x6AF8BD1A015DA5DBULL, 
            0x2DEDC2D15018B89DULL, 0x6943F479FC7FB8A4ULL, 0xD9EF3DBF8D1E63C6ULL, 0x6770E57D01ED65DBULL, 
            0x7A814CA56F3BAB61ULL, 0x88B1E2168221DDE4ULL, 0x995C26935301550CULL, 0x35E8213639624A94ULL, 
            0xF1CACCBF24E24AE5ULL, 0x98461180E8181B6EULL, 0xB0898ABDA51721C4ULL, 0xA74F526C9550348AULL, 
            0xD171A97234111EDCULL, 0x0CD87D20A9AC6FF0ULL, 0x6B2553C9CA9A8E1EULL, 0x728F8B7B82F2E314ULL
        },
        {
            0xD664C4644B9AFC22ULL, 0xD3C8E4A7E5E359FAULL, 0x0F2F081614DF8BEBULL, 0x390946E5B7EAAFACULL, 
            0xEBF5675A4D6DCF6BULL, 0x21AE38F56F4F5DD0ULL, 0xDC4989E004152054ULL, 0x768AF071FDBFC2F2ULL, 
            0x5452DF60B8A0AF7CULL, 0xEFA3FE4ABD0912E3ULL, 0x6E12DD689D18D817ULL, 0xE5BA2A64303B2F4FULL, 
            0x7832201C520B6198ULL, 0x84E66DC7C6AA20C1ULL, 0xCE5211948E5D8821ULL, 0x583F77AF28094A20ULL, 
            0xCC34801B526AFBAFULL, 0x270572CF2A05B742ULL, 0x3426C3C28A5CABD0ULL, 0x5FA6533DE732E638ULL, 
            0xB129BF7829D3148EULL, 0x8403301D8B09C68CULL, 0x64D772B1740FB766ULL, 0x5B300A0BFFD84BD5ULL, 
            0xE8A9D9BC6EAE484CULL, 0x2D7D657460A9D20BULL, 0x32E1DB79B9D97088ULL, 0x8E6E586BA25AC6BCULL, 
            0x8D4CE410A726D05EULL, 0xF655877E8EC78D07ULL, 0x12DDAAFE16B07FE2ULL, 0x33F76EF04BE38C59ULL
        },
        {
            0x3302CB303E6A16BFULL, 0x3C02E24957D9206BULL, 0x1AA70275D1401336ULL, 0x964A376B4BFF7439ULL, 
            0xE8FE4FEB0F6C65D8ULL, 0x8BD0B2D5A8409677ULL, 0xA160653B4E61E9D6ULL, 0x2F044C3F6884A540ULL, 
            0x748560DB6C428DD8ULL, 0x86E3E336A4D9385CULL, 0x4475AD65F654ABAEULL, 0xEE8F696917151F17ULL, 
            0x8BFE971EB0CD7128ULL, 0xB2489DAE6EA7199FULL, 0x14938E1CE8870AC8ULL, 0x97D1F8C13014F8C9ULL, 
            0x2F5669E1559F8101ULL, 0x9671696CCB6EF92FULL, 0x076E55E60DFC93BAULL, 0x77D0E863051A50D2ULL, 
            0x135D1B00E96AFB7AULL, 0x22A382E89D58EB45ULL, 0xF29C5D208C6D179FULL, 0x7C047E3B2D7D46CDULL, 
            0x8FCBA346E409BFCAULL, 0xF417A735FE60E7D5ULL, 0x72EF9E8E3C8A9E77ULL, 0x9DFF9907B04EBD3CULL, 
            0xD2FA449EC9A09513ULL, 0x90D03FAD58D69682ULL, 0xD9787CDE5B2D51B7ULL, 0x80491B4749CBC921ULL
        },
        {
            0xC499CC350AC6D97AULL, 0xD65D46DFB2CA6672ULL, 0x93E7052D1D5E816AULL, 0xFBAD635F40000880ULL, 
            0xB4017DB3292FC56EULL, 0x50661BA84D03AB11ULL, 0x5ED780C82B7120E3ULL, 0xC07DEB01C7F11BB7ULL, 
            0x627D78A5BD5A40C0ULL, 0x3589D817553E7AD8ULL, 0x17DCB2565E32395AULL, 0x7299D061AF25D57EULL, 
            0x1929A8455D421C2BULL, 0x2656F751E2713A06ULL, 0xF174A596E9A0AA0DULL, 0x4D7E59FC1278631CULL, 
            0xC36BAC221ED10A28ULL, 0x01C0DF4FDB8E1076ULL, 0x982B0318B22A3DC0ULL, 0x0FC2B4ACC9DA2ACEULL, 
            0x5190145A8C240477ULL, 0x9C81656FB09D56EEULL, 0x2B55694F12A4FA76ULL, 0x3CD26CF072FB4618ULL, 
            0x34CAEE3F6EA45D99ULL, 0x93DBBA4CDC8C89C5ULL, 0x02B7F17206E8061AULL, 0x8E822E5580B4D714ULL, 
            0x42B9175E3296EA00ULL, 0xC0C4B3C6B4827C41ULL, 0xCBED8A1538C740E0ULL, 0xA3CFD00F71ABD217ULL
        },
        {
            0x8554023C1E06C8A2ULL, 0x8C76B4BDC58D8745ULL, 0x5E3C402E9727C0D2ULL, 0xE1087DB89C1CB434ULL, 
            0x770F9C19BA77F21EULL, 0xBD327398A5777C33ULL, 0x65301E8072B215DAULL, 0x2686B960681076ADULL, 
            0xADE903AC4664856EULL, 0xB0731F99ED995D98ULL, 0x5E65E8F9761BC462ULL, 0x059408800723007FULL, 
            0x245B7C17F3E8D0A0ULL, 0x1FAFE8737E9BBF38ULL, 0x80E0802D221E3AE1ULL, 0xDF51D84213751001ULL, 
            0x86BD2C9699EC9C2AULL, 0xCF5F0643666406E7ULL, 0x361952161126D796ULL, 0x792649C9E9A37D23ULL, 
            0x7CD32F50583AFA4FULL, 0x1E2F85883C1ADC68ULL, 0x1ED7A8DCA0331F97ULL, 0x70F0EA00CD59517AULL, 
            0x5C909E8A7BC37932ULL, 0x3D9C79AB0B9507B3ULL, 0x94E4C4ED18005AF6ULL, 0xEA0AE5DBBD02FD69ULL, 
            0x08C7EF59C401A93CULL, 0x303CF6BB20E09229ULL, 0x5299560DEDAB491FULL, 0x71350DD0BB1E2815ULL
        }
    },
    {
        {
            0x108E2FB9C390F7C5ULL, 0xA731E302C0EDA336ULL, 0xE275E080C65785FFULL, 0x34A87CF1DE31545BULL, 
            0x0250BA4B8B608F5BULL, 0x26009B9F95420CBEULL, 0x61A027FE72C79279ULL, 0x418797832D07525CULL, 
            0x4C72298CB6883DB0ULL, 0xD6F08E51B9A9E973ULL, 0x35FDCBEEAE55EDECULL, 0x7EB81DCE8B22E95AULL, 
            0x375B7CDF64B398F0ULL, 0x465546B0C6E55A13ULL, 0xCBA0B210DAB7D09DULL, 0xF237CD6EF4C589CFULL, 
            0x09368DC09EC839C2ULL, 0x66F0ACEE2F20EE5DULL, 0x0455CF50CB624842ULL, 0xE0C4A6D5F892CF6CULL, 
            0xF3C9266DA7B4468BULL, 0x2AC298B46E4E9A5CULL, 0x0D49C79223F836C3ULL, 0xE0C2DFE9D09C8C0FULL, 
            0x5ACEC2E88FC0B269ULL, 0xD5F8E7F145F15BB1ULL, 0x235A9F84721193A5ULL, 0x9F868331974BA0E1ULL, 
            0x72247D2E7DE89E52ULL, 0xA2097D200C458777ULL, 0x408EC79504F5B5FAULL, 0xA74368F66AA60D92ULL
        },
        {
            0xD14DB373708283C9ULL, 0x16056C3E560451D0ULL, 0xCC979707F3BD5245ULL, 0x411F8D371AE8FBBBULL, 
            0x87E2276B6F60A34FULL, 0xB9F544158948DC07ULL, 0x503B12572D85E31FULL, 0x63E4DF1D0CFB2748ULL, 
            0xD4D0E161E66D2825ULL, 0x15EBBFF14FCBC56CULL, 0x96EEE7194CF40ACFULL, 0x9F63F5AD29DA9F46ULL, 
            0xF692D2DA30EEF0C7ULL, 0x6C5FE1ACD1714450ULL, 0x5726BCA4BA2AA5F9ULL, 0x8A13ED7E742FD206ULL, 
            0x63360268705B2357ULL, 0xEDAFF3A0D01BAC59ULL, 0x8CB8C07E88D07783ULL, 0xA2DE8AE2FA1773EDULL, 
            0xFC1F5CB83841C59EULL, 0x8A5C8A6A99294130ULL, 0x5877AFA34647287DULL, 0xC41795AD642267A1ULL, 
            0xB74D2446C238950FULL, 0x378AEA6B152255C4ULL, 0xF38DE6B5E5BD20D0ULL, 0x6E79E4CAC662085AULL, 
            0x61B44E3A1938CCEBULL, 0x56378FBDF9D7D62CULL, 0x222BFBF218B56742ULL, 0x28EE23BE481ED34CULL
        },
        {
            0x3024036F6889ECA4ULL, 0x22FB527593D837F4ULL, 0x4A7D7B87154BE752ULL, 0xC6C424D2F9962289ULL, 
            0xBB01E44F0A5A8892ULL, 0x326A607BDE3C4CD7ULL, 0x1F01F65CA2755ABEULL, 0xF7002FCE428AE9C6ULL, 
            0xE8B86CEC48AB4B70ULL, 0x644F20DB13C5809BULL, 0x7E758D5772BD1458ULL, 0x15EB90A6E178A4C4ULL, 
            0xC5D4A86C142DA2D6ULL, 0x7E15B73849CEB180ULL, 0x2CE1CEC98762D9D2ULL, 0xF7BDD6AAEAF6695BULL, 
            0xA5D3DEEF2ED189DFULL, 0xA8E2D24B1DD9C286ULL, 0xDFE53651A8DAFB02ULL, 0xE77FB44CE8C97E00ULL, 
            0x51C6CDA335473C35ULL, 0xCFAC243A808E68FEULL, 0x5656DF83EB02A52AULL, 0x4E64FE00ADF16D27ULL, 
            0xAF83ECCC2B09F08CULL, 0x7760339DB7FAC351ULL, 0xB5F685FB294E1C86ULL, 0xC15C8F5D554BE3FFULL, 
            0x672969BB4BD11B13ULL, 0xD8896B3DEFC73741ULL, 0x822B2931DB045435ULL, 0x32C610250E10A9F4ULL
        },
        {
            0x23F6903556299822ULL, 0xA9B1672666977CAFULL, 0x3C53C5CD734783B4ULL, 0x5DAB183E8F6C5A07ULL, 
            0xF561374E109F378AULL, 0x3DC2D559436151D1ULL, 0xE54C81CC2BA22B8CULL, 0x8CDF8780B6E649D0ULL, 
            0x08E478FC996DBBD2ULL, 0x1F43909DA2A8E376ULL, 0x14C599F6C572470CULL, 0x5AE8EC7D52961B0EULL, 
            0xB68F0B6D6B32F50EULL, 0x4FD0CB8FEA982714ULL, 0x2EC69F6D8FCAD0DCULL, 0x447EA8DC046B91E8ULL, 
            0xE08FC767C43E360FULL, 0x8F571B2F83294694ULL, 0x14900C9E8D421DAAULL, 0x72B458A913BC65FBULL, 
            0x5AA141EF0B0EC967ULL, 0xFE95EC7AB5C452A7ULL, 0xF4D53ADD82CD9BECULL, 0xB6D9A6A4EA9A0915ULL, 
            0xEEFFCB10BF3C4525ULL, 0xB2117AA1170384A2ULL, 0xAAA09E8B6D94D534ULL, 0x07870E0BAD753E06ULL, 
            0x8A3EF3FBE516E288ULL, 0x53EEAA128D8D761BULL, 0x00DABD90A9A18ACEULL, 0x861C903644801862ULL
        },
        {
            0x44F7D2327A38D496ULL, 0xFF3C387AADB65A72ULL, 0x632A41D715A30C09ULL, 0x7D2E8D79FEB9D1D4ULL, 
            0x12EDBAA56E950CA0ULL, 0x22556F493584A62BULL, 0xDCA97D8F848E4DB6ULL, 0xB74111012353C0C0ULL, 
            0x264CCE68D5701335ULL, 0x0DC01CC85A3E8A5EULL, 0x9CB87D6779A28846ULL, 0xD771336ACD1D2AD4ULL, 
            0x054A1D7600F91A02ULL, 0xC78D22AC91FE824BULL, 0x86E9E54D1A6BC2C7ULL, 0xF718E3512D9C8ECAULL, 
            0x7DCE9E6047A98B98ULL, 0x6B00A3DA6F7366BDULL, 0xDFF67F21F1B78CF1ULL, 0x5B7FF1058691A8D5ULL, 
            0x3BDDF720B61CEBCBULL, 0x55D6164FE35ABBA2ULL, 0xA07E2705340874AEULL, 0x47B51CA0804E4DF8ULL, 
            0x7C78FC83F8EA2CBFULL, 0xF2A0762C4ADE85AAULL, 0x918846667477C02BULL, 0x5974D8C318E69E78ULL, 
            0x789632DD83524563ULL, 0x561231BEFFE5DAB1ULL, 0x440EBF2FFA8E5D59ULL, 0x56AC8B7A749A1C96ULL
        },
        {
            0x70CA4783FD9C24E4ULL, 0x6324A16166889F4FULL, 0x64B5772DA8742206ULL, 0x68ACCE0A5B0A7A40ULL, 
            0xEBFA769CF199E7B3ULL, 0x5000C99BF0C8197CULL, 0xE0AB01E75550DA14ULL, 0x8BA9B70D0615869BULL, 
            0x39496A55D5276C07ULL, 0xED8602293413088BULL, 0x73CAFD74E54ADD60ULL, 0x5D0FA4C2202508D8ULL, 
            0xF0AE30E00ACFC445ULL, 0x2D8E8F702EAD597DULL, 0x91531254A4B17035ULL, 0xD447FF143CC5C5A9ULL, 
            0x6C272ED63B5106E9ULL, 0xBDF622E4D73A4789ULL, 0x9A10B0789E923BEBULL, 0x846E4A554C1B1D14ULL, 
            0xAA9F404A9626D9D5ULL, 0xC78AACEFDDF5B04BULL, 0x33BD17D5908D3433ULL, 0x5E3F83C6CAA14C2AULL, 
            0x977318B385406097ULL, 0xDD0F39F71E2D329DULL, 0x03EAD7F31108EF71ULL, 0x9A8164A198700126ULL, 
            0x4A070AC00124D5F1ULL, 0x4514A1E3FE69274BULL, 0x0E4B6A35E7C16D22ULL, 0x2E6138AD6A98D936ULL
        }
    },
    {
        {
            0xBCCC956411FB9B48ULL, 0x04004ACFDEB3A2F1ULL, 0x66FA44D88D54EE44ULL, 0x9DE20834C2C1A593ULL, 
            0x21FDEDC2AAAF9CE8ULL, 0x4E7A88DFDED63579ULL, 0xB3A658AA5B2B7D9AULL, 0xCE6C1CE25E2C97B4ULL, 
            0x942BAA49C7CB2362ULL, 0x2FB7C3EA6D23D27FULL, 0x7477B0972813A442ULL, 0xC17262E1FAC80D1EULL, 
            0x4E971243FC060550ULL, 0x16014BABCA5022CFULL, 0x2FEC21DCDEE40FC2ULL, 0x29DD174FEB47B46FULL, 
            0xC34ED5B5E869D645ULL, 0xFF8A200DE7E0EB33ULL, 0xA7E2EB2057605456ULL, 0x6189BF48C9CF2458ULL, 
            0xC73FB4316FF79FAAULL, 0x3080DF5E2468B67FULL, 0xFB20899705315676ULL, 0x213B84317EC5AFE4ULL, 
            0x87A902AF5A0B766BULL, 0x30C5EFD2A29F1E75ULL, 0xE0EF5B03BC58B7D9ULL, 0x0736BD9976CD3B7DULL, 
            0xD1D9121756EEE10DULL, 0x616B5C7993CF0AFFULL, 0x67811DCBA21A6831ULL, 0xF913366D614B5B96ULL
        },
        {
            0x5C7EA5039357F67FULL, 0x3006364A16A2EB22ULL, 0xC3BE7748EACFE794ULL, 0x778B4231E9F3AD25ULL, 
            0x08BF014869D2DA75ULL, 0x0B21AEE8C5A158DBULL, 0x06576F4875796492ULL, 0xAD91B88F05CD62B5ULL, 
            0xC6D74B8F50966F9FULL, 0x69A5EB243790F3E0ULL, 0xC8522BE06CD5E65AULL, 0x2566EBC3D23EE31FULL, 
            0x5BE8FC2B528C845BULL, 0x98EF4832D4596C3EULL, 0xBE5887871AA5374CULL, 0x1A6285C55FEA7A90ULL, 
            0x0449A55247DDC192ULL, 0xB3293154586B0197ULL, 0x4332389DF65BC4FBULL, 0xAC8FBE9F2C482659ULL, 
            0x60DF30A74A36E015ULL, 0x8D0671B4071372D1ULL, 0xA8B233C2B683FA19ULL, 0x24874B7E8678677DULL, 
            0x79262AEA45257889ULL, 0x75C31934DB013EA0ULL, 0xA8552A1EE0115B6FULL, 0x4B4D51211757E8E3ULL, 
            0xE550276855A82B49ULL, 0xC05DF4179414B407ULL, 0x7E13F0471E29E3EDULL, 0xE020116E4F60FEF1ULL
        },
        {
            0xDFED96C8507A5CB6ULL, 0x91CE67FDC9D50003ULL, 0x3B58419EF627EA90ULL, 0xC6ED6C98985D5AD7ULL, 
            0x76EC39D5FD8D4609ULL, 0x8F1B68C813D13162ULL, 0xC7D9D84FA5F60C83ULL, 0xB281C0AC2F9F92AFULL, 
            0x13C0821738A83755ULL, 0x6686312ADC635FC4ULL, 0x52B626049E3AD2DEULL, 0x375B1DEF35FC8CA7ULL, 
            0x7861CFDE52CC05DAULL, 0x332200E58A481BB1ULL, 0xEC6E8D41F8DE65F8ULL, 0x39D594C73F9723F1ULL, 
            0x53992D9D00BD3381ULL, 0x19CE898BD68E23B0ULL, 0x4F99C56EF86882ECULL, 0xE6B679BB2B1B119BULL, 
            0x8149919251BC0D24ULL, 0x85E78252A66264E8ULL, 0x823FA8078DD3530FULL, 0x3AB04A1BFE7568EFULL, 
            0x386930C5806DD4F6ULL, 0xD24610A40166999DULL, 0xB321545C80F730CDULL, 0x670DFC27839F56D6ULL, 
            0x0DE368C66B8685EBULL, 0x45566A19A2E49A6FULL, 0x539D31F014BECA9DULL, 0x2CCB21557B1E41F2ULL
        },
        {
            0x4624FFD764F3A71BULL, 0x6CCE04211F15FFDAULL, 0x310AE9DFC24ED9F3ULL, 0x1DAC889D65E56675ULL, 
            0x2F76660F32429E06ULL, 0x306D4D9E37A21148ULL, 0x93FE21F807E178D0ULL, 0xF898EE35118906B8ULL, 
            0x6268568BFCE713B2ULL, 0x3AE6807C8B52F355ULL, 0xBF1F3651FBA437A0ULL, 0x46CB9376DAE75C39ULL, 
            0xBCB62BCAD1854CB5ULL, 0x96C85D67B2291AA2ULL, 0x10ACEB69F8EE9871ULL, 0xCD87098C1F51770EULL, 
            0x65E9FE81328272CAULL, 0x3AF1A850562127AAULL, 0x18838DCE392E178FULL, 0x8D4ACA21B3DA02D2ULL, 
            0x5866A0E3772F2E8DULL, 0x024C6C3962E1BB7DULL, 0xC48441D3E6F8293EULL, 0x707DD2256B7AE6C6ULL, 
            0x7DEFC25191AA7940ULL, 0x2ED25101666F16DFULL, 0xE2B516A91EDECE15ULL, 0x0747190209AAAC01ULL, 
            0x740EA433084CA9BCULL, 0xDE96365562C33642ULL, 0x341C53AC911D5E00ULL, 0x855D76B524BF3311ULL
        },
        {
            0x0F733AEE0AC89176ULL, 0x69694FC2A422D245ULL, 0xDFFEFFB9E65F81F5ULL, 0x1E8680759F29345AULL, 
            0x35C01C6789BF8F72ULL, 0xDDEABA3E8CA744C0ULL, 0xC2B0CD6A0CA8835EULL, 0x55E9D23787C50C16ULL, 
            0x6051326FB158834AULL, 0x96DDBCAFC6380064ULL, 0xFDF2839F16734C6CULL, 0x1C6B879E86E7D88DULL, 
            0xC653C9A8141E5EB8ULL, 0xA8F1A4E95CBD66C2ULL, 0x9400DD05733A7BD6ULL, 0x0CA13EA762993198ULL, 
            0xBDF654653CAC1F34ULL, 0xAB5D8D63D35A0647ULL, 0x91941D855C986DC4ULL, 0x75057D1D339A3F84ULL, 
            0x0474AF408B10FD51ULL, 0x2F78C7E75E0C4BEDULL, 0xF42BBE70DF26C40EULL, 0x8B24FA49E4D1A89DULL, 
            0xBA2828C02D493C69ULL, 0x9A3070F9C9915B03ULL, 0xC1A7EA16D9771D2DULL, 0x3E3039D8BB5AC730ULL, 
            0xA535FAD95C1C048AULL, 0xF5C54B1D108455C2ULL, 0x741BDED5B33A390FULL, 0xB5908A2CDCA581D6ULL
        },
        {
            0xBE9A4619939152F0ULL, 0x61233F2E9C6525E4ULL, 0x1DE0FC97EB8EEA2AULL, 0xE11453395DC94F85ULL, 
            0xFA1028B74D621EA2ULL, 0x65601F2C2BB21C35ULL, 0xB82E059FBF9D04F7ULL, 0xAF2851B6990F5FC6ULL, 
            0x129DE1756A8B35AAULL, 0x496AF7F0B8D16692ULL, 0x2C394F2D61BC6BA9ULL, 0x5FE77D6D76EF5984ULL, 
            0xFAE22885FFEEC807ULL, 0xB3623809F932E73BULL, 0x8E7C9892315303A5ULL, 0xC33162E669D06DFAULL, 
            0xC7793F93CE7AC279ULL, 0x8ACBC1C4E548C6F3ULL, 0x6230D84856BC9B80ULL, 0x6E15807BE0D08D15ULL, 
            0x758A98CD2B6FBCF8ULL, 0x04E4EB12B24FD737ULL, 0x7166DB9C0E4D87C5ULL, 0x13356E6120F0DD42ULL, 
            0x460D687DA591AA30ULL, 0xCD536BA75EF515E8ULL, 0xC93CCF6E9CA819F7ULL, 0x2C3160751C5C12C3ULL, 
            0xA01AD38F2BE531B7ULL, 0xDD1DA9BD4B7A4B20ULL, 0xF4EE8443EE1F1521ULL, 0xBB4130DFFEEC04B0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Alioth::kPhaseDConstants = {
    0x83B4AB94CDFFE234ULL,
    0x867D38D08CAC8420ULL,
    0xF76C48E4ADD2DCBEULL,
    0x83B4AB94CDFFE234ULL,
    0x867D38D08CAC8420ULL,
    0xF76C48E4ADD2DCBEULL,
    0x0C675C3081289500ULL,
    0x1FFA69DDEFC0F934ULL,
    0xBA,
    0x64,
    0x3F,
    0x9B,
    0x8B,
    0x24,
    0xEA,
    0x98
};

