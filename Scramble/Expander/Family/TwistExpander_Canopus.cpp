#include "TwistExpander_Canopus.hpp"
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

TwistExpander_Canopus::TwistExpander_Canopus()
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

void TwistExpander_Canopus::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB2E5F20C771C307CULL; std::uint64_t aIngress = 0xA04C467166D682C8ULL; std::uint64_t aCarry = 0xBBE10825EECA48FDULL;

    std::uint64_t aWandererA = 0xB6C2BD8559E0463DULL; std::uint64_t aWandererB = 0xC218347ED19A8ADFULL; std::uint64_t aWandererC = 0xD8C0E17D18BA0927ULL; std::uint64_t aWandererD = 0x89A7150513E3025CULL;
    std::uint64_t aWandererE = 0x84148E964D5AE547ULL; std::uint64_t aWandererF = 0x8A5A22EE46BE7B52ULL; std::uint64_t aWandererG = 0xAF126BC74D4606B2ULL; std::uint64_t aWandererH = 0x91D52C48CB8A1761ULL;
    std::uint64_t aWandererI = 0xDD19DFBCCD3E81E8ULL; std::uint64_t aWandererJ = 0xC431B3F6116F800FULL; std::uint64_t aWandererK = 0xE38212D574B6A26BULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xC2EF88EF415E047DULL;
        aCarry = 0x82A45FEC60610239ULL;
        aWandererA = 0xF9182F10E7E65E72ULL;
        aWandererB = 0xC470BFE9CEE8023EULL;
        aWandererC = 0x8F2E4E73CAA8CB9AULL;
        aWandererD = 0xBB142B764C6B425AULL;
        aWandererE = 0x94F7CAF9BA27A576ULL;
        aWandererF = 0xB21164C00542C630ULL;
        aWandererG = 0x99C525BF08D37FF1ULL;
        aWandererH = 0xF8705EC6D97FEDF1ULL;
        aWandererI = 0xF881E1FF96249F80ULL;
        aWandererJ = 0xF2B98DD46C09B3BFULL;
        aWandererK = 0xCA90464C4BC67008ULL;
    TwistExpander_Canopus_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Canopus_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Canopus_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Canopus_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Canopus::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xEC0573FECB36E969ULL; std::uint64_t aIngress = 0xB5F6065C93028EDBULL; std::uint64_t aCarry = 0xA654D43BCA4C4A3FULL;

    std::uint64_t aWandererA = 0xAAF73CF2097AE8BDULL; std::uint64_t aWandererB = 0x88D064704C8F335EULL; std::uint64_t aWandererC = 0xD35CA73E4825D746ULL; std::uint64_t aWandererD = 0xAB62533DC1A9A32DULL;
    std::uint64_t aWandererE = 0xC327960261BC84EAULL; std::uint64_t aWandererF = 0x966FFF5D584630A6ULL; std::uint64_t aWandererG = 0x9995E2BD48FFAE3EULL; std::uint64_t aWandererH = 0xE66F67AC68B71027ULL;
    std::uint64_t aWandererI = 0x88B6819499A894E8ULL; std::uint64_t aWandererJ = 0xB96E967232FB91F4ULL; std::uint64_t aWandererK = 0x9AD1487F27FD3A6BULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xD8C372575349CB64ULL;
        aCarry = 0xC563404D56C43A8CULL;
        aWandererA = 0x95647CF7604DC5B2ULL;
        aWandererB = 0xA76DFC2B5AC56E49ULL;
        aWandererC = 0xB4106AB497B469D3ULL;
        aWandererD = 0x874A32CF0F328309ULL;
        aWandererE = 0xA9F8B6ABA541FA3CULL;
        aWandererF = 0xBCFD9E94F072ADA4ULL;
        aWandererG = 0x8C80CECE29E0EF0DULL;
        aWandererH = 0x8C51D38DCA8F7BA2ULL;
        aWandererI = 0x947C1D580527DB80ULL;
        aWandererJ = 0xDC77F8A2827BBE52ULL;
        aWandererK = 0xE61402F77838B373ULL;
    TwistExpander_Canopus_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Canopus_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Canopus_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Canopus_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Canopus::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE157571720800BB2ULL;
    std::uint64_t aIngress = 0xCB72ACF58152C83DULL;
    std::uint64_t aCarry = 0xBE4C4BB8272987F7ULL;

    std::uint64_t aWandererA = 0xC8C685F50F4E442EULL;
    std::uint64_t aWandererB = 0xF78376CBCCD23FF8ULL;
    std::uint64_t aWandererC = 0xA390708FC67EE461ULL;
    std::uint64_t aWandererD = 0xA1A94A5FBCF5F570ULL;
    std::uint64_t aWandererE = 0x87A6D4566F2FD370ULL;
    std::uint64_t aWandererF = 0xD1226472BBFF796DULL;
    std::uint64_t aWandererG = 0xA0B21115D0953BE8ULL;
    std::uint64_t aWandererH = 0x835E084002D1FB80ULL;
    std::uint64_t aWandererI = 0xAEB8447595FD1983ULL;
    std::uint64_t aWandererJ = 0xC7A2DFE84CAE7DDBULL;
    std::uint64_t aWandererK = 0xD630ACAEC427DC88ULL;

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
    TwistExpander_Canopus_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Canopus_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Canopus_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Canopus_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Canopus_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Canopus_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Canopus_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Canopus_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Canopus_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Canopus_Arx::GROW_B(pWorkSpace,
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

// SmartSquash candidate 14 of 33
// Exploration cases: 100000000
// Nearest-family diversity: 945 / 1088 (86.86%)
// Total distance from earlier candidates: 12427
void TwistExpander_Canopus::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    static_assert((S_BLOCK / W_KEY) == 16, "SquashInvestToKeyBoxes expects 16 invest fragments.");
    static_assert(H_KEY == 8, "SquashInvestToKeyBoxes expects 8 key rows per box.");
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 15U), *aFragmentB = aIceLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 15U), *aFragmentD = aIceLaneD + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 683U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 810U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 427U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 86U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 9U), *aFragmentB = aIceLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 14U), *aFragmentD = aIceLaneD + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 972U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 821U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 332U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1084U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 12U), *aFragmentB = aIceLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 4U), *aFragmentD = aIceLaneD + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1091U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 404U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1394U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1685U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 0U), *aFragmentB = aIceLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 8U), *aFragmentD = aIceLaneD + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1762U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 178U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1227U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 971U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 2U), *aFragmentB = aIceLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 7U), *aFragmentD = aIceLaneD + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 62U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 385U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 555U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1344U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 4U), *aFragmentB = aIceLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 6U), *aFragmentD = aIceLaneD + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 636U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1605U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 2019U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 909U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 14U), *aFragmentB = aIceLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 9U), *aFragmentD = aIceLaneD + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 782U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 769U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1734U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 742U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 11U), *aFragmentB = aIceLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 2U), *aFragmentD = aIceLaneD + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 192U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1045U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1679U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 567U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 6U), *aFragmentB = aIceLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 5U), *aFragmentD = aIceLaneD + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 2017U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 930U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 503U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1914U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 10U), *aFragmentB = aIceLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 3U), *aFragmentD = aIceLaneD + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1326U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1673U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 476U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1813U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 5U), *aFragmentB = aIceLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 1U), *aFragmentD = aIceLaneD + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 290U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1493U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1325U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1280U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 8U), *aFragmentB = aIceLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 0U), *aFragmentD = aIceLaneD + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1887U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1674U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 770U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1030U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 13U), *aFragmentB = aIceLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 11U), *aFragmentD = aIceLaneD + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1088U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 640U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1025U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1556U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 3U), *aFragmentB = aIceLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 13U), *aFragmentD = aIceLaneD + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 776U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 39U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1070U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 722U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 7U), *aFragmentB = aIceLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 10U), *aFragmentD = aIceLaneD + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 680U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1542U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1825U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 320U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 1U), *aFragmentB = aIceLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 12U), *aFragmentD = aIceLaneD + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 611U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1304U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 544U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1764U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Canopus::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xFCDBE8E0801D8963ULL; std::uint64_t aIngress = 0xEB5916B4572B3F52ULL; std::uint64_t aCarry = 0x92CF68936C157343ULL;

    std::uint64_t aWandererA = 0xA50B330F1573F4F3ULL; std::uint64_t aWandererB = 0xFDE929002E96396AULL; std::uint64_t aWandererC = 0xBF5AE1EFE9055E7DULL; std::uint64_t aWandererD = 0xCE0F2A9A280FD15EULL;
    std::uint64_t aWandererE = 0xF0DD3EF65639C133ULL; std::uint64_t aWandererF = 0xE65037E5BE974EACULL; std::uint64_t aWandererG = 0xAF992B160CB32C42ULL; std::uint64_t aWandererH = 0xBB7D6D5E9049D3F6ULL;
    std::uint64_t aWandererI = 0xC7AE7A1FDBDE7954ULL; std::uint64_t aWandererJ = 0x9ED6A1B23B2089F4ULL; std::uint64_t aWandererK = 0xA710793DD0CA309EULL;

    // [seed]
        aPrevious = 0xA1F26EE75F8DB1EAULL;
        aCarry = 0x99F6CB193EDBA472ULL;
        aWandererA = 0xE8A1CC764854F037ULL;
        aWandererB = 0xF64130CFFDBC4BD2ULL;
        aWandererC = 0x9256C5E699687930ULL;
        aWandererD = 0xFCC0C0F9E802F0B2ULL;
        aWandererE = 0x9FDF56B74B91B997ULL;
        aWandererF = 0xFA78EC1425D75AF6ULL;
        aWandererG = 0x91364BBC278B6E7FULL;
        aWandererH = 0xBFA5794E6DDC5339ULL;
        aWandererI = 0x8346F2D9BDB9B5A9ULL;
        aWandererJ = 0x830FC8F22955C320ULL;
        aWandererK = 0xBD01C44AB21DDF9FULL;
    TwistExpander_Canopus_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Canopus_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Canopus_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Canopus_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Canopus_Arx::Twist_E(pWorkSpace,
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
    TwistExpander_Canopus_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Canopus_Arx::GROW_B(pWorkSpace,
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

// GrowA candidate 14 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 7122; nearest pair: 499 / 674
void TwistExpander_Canopus::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3724U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5169U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1209U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 754U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4941U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4698U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 274U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 658U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4451U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3627U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7164U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 312U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4234U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5895U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 499U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7150U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 587U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 599U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 696U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 433U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1123U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1069U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2030U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1003U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 624U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 706U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 400U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 298U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 187U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 371U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1082U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1042U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 138U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 216U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 270U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
}

// GrowB candidate 14 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 7129; nearest pair: 513 / 674
void TwistExpander_Canopus::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6402U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3661U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5371U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1965U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 161U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3951U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2302U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3055U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 8U);
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
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1904U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1870U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7835U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1831U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5593U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 951U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 432U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5781U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 861U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 916U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1083U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 674U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1802U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 465U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 61U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1789U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 166U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 100U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1360U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1932U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 577U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1346U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 549U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1343U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1780U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1358U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1777U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
}

const TwistDomainSaltSet TwistExpander_Canopus::kPhaseASalts = {
    {
        {
            0x76F16B39D44C0D8FULL, 0xD75B2A6F8B3FA935ULL, 0xA01DAE6B22DE9142ULL, 0x68CDBBBD337FF808ULL, 
            0x6091A628B53D9276ULL, 0xAFFAD9880EA64322ULL, 0xAAE7D16D03D9E0C0ULL, 0x5B7D8F444004EDBEULL, 
            0x5E1EA89FADE31B9CULL, 0x42C36EBADA82EE64ULL, 0x3904976DBC314058ULL, 0x0A3F0E0C226E544DULL, 
            0xE071989E54A6F817ULL, 0x0828D607E3B9091CULL, 0x0CC7FF3BA719FFDAULL, 0x3BF177928D82550AULL, 
            0xD6D0B3391AE2C0F2ULL, 0x7A23720BD423E162ULL, 0x33E2763306444D13ULL, 0xB862E47E14DC1325ULL, 
            0xDED2888B80E288E4ULL, 0xCE4B91506519EFDDULL, 0x576F385AB665C6EBULL, 0xCBCE25A6EF9E60A4ULL, 
            0x33B27B65869C0C09ULL, 0xBB2345D01A69A990ULL, 0x598A3FDF0A64884FULL, 0x3C9A8C378657B5F1ULL, 
            0x834836F6A7AA7B1EULL, 0x29498F3BABA5B59FULL, 0xBC1439603E009455ULL, 0x125B0081A77BC793ULL
        },
        {
            0x2E27148647071BB1ULL, 0x1DDCCABF4C7AEFD7ULL, 0xC8F670610646BB31ULL, 0x2854A2599466964AULL, 
            0x659C292F7F178E90ULL, 0x8DB809DEDC6A1A34ULL, 0x8918A54B332A8780ULL, 0xC6D6E73F0EA01270ULL, 
            0xA8BC510E196E9AA5ULL, 0x8C21B549535492F6ULL, 0x2790B33EC25E1FF1ULL, 0xE06C7A7C59FD12DDULL, 
            0x8634EC192EE32395ULL, 0xEF8300A4F673CE33ULL, 0x3DE341C844824ABCULL, 0x2849446B36E65D44ULL, 
            0x1D63F5F95F302238ULL, 0x394A7D74F3A4EE4AULL, 0x69B84A06470846C7ULL, 0xC17B97E9B0205063ULL, 
            0x231D384134851548ULL, 0x9EFEF3777396C863ULL, 0x1E52254496BEAADBULL, 0x4AA95FB0596CD884ULL, 
            0x9D33FF152781B68BULL, 0x9611230F5DEE41B8ULL, 0x9A98B90DC81C40A0ULL, 0xDA2EBB87BD440E97ULL, 
            0x54E34609ED72B243ULL, 0xF73E51A918718B21ULL, 0xE65ACADDB9C029FEULL, 0x98C294FCEEE5BB0BULL
        },
        {
            0x8711DB6491E30B4DULL, 0xF685101D71A4EE93ULL, 0x6A8122F0199B64ACULL, 0x2B7DDC59537E9C4BULL, 
            0xAC96273B85C7D6C2ULL, 0xD8C06D15E61BB388ULL, 0xB41448435EF22E72ULL, 0x1D98169C139F5D4CULL, 
            0x95BF68CD51FD27D3ULL, 0xB1EE67957FB65366ULL, 0xB2702973013E9182ULL, 0x2E9F6AF4828001EDULL, 
            0x6FB127C30A297AD9ULL, 0x967A1B0A346B052EULL, 0x31B68AF65D4358BEULL, 0xC4358D95C8E35F87ULL, 
            0x0BBFAB0DCCFD54CDULL, 0x831596DF3FCF63ABULL, 0xE59FBFED6076F618ULL, 0xA5127CC26AEDD310ULL, 
            0xB033A22E39CEF129ULL, 0xC1993B5D0794D780ULL, 0x3304BEC86328CEAFULL, 0x90BA99F5CA2ABA8CULL, 
            0xE6E5E89A23DFE30DULL, 0x820C5DDC990C2FA6ULL, 0x8C3987F1A050A206ULL, 0xFD3100A6EFB52D87ULL, 
            0xBF78F5CAFD7A21B5ULL, 0x4FD61B4D1145CC85ULL, 0x656A1C3B71898754ULL, 0x6758D4543F4A82E6ULL
        },
        {
            0xF02D39AFCDEF21D5ULL, 0x4C7762E6E66353DBULL, 0x6431E8357D804D8DULL, 0x3578866B08527C00ULL, 
            0xE72D83182A9E07F6ULL, 0x138DB4BB70BF4501ULL, 0x0FBAE49C8EA911E8ULL, 0xB03915E1FABF0BDEULL, 
            0x118B108682EF7C54ULL, 0x9D5EA2CBE7AC4A53ULL, 0xF1CCCBF009135934ULL, 0xBC5DAFEC2A372591ULL, 
            0x597DA6765B836CFEULL, 0xE0BA42433B92342CULL, 0xB3955050FBACC6F2ULL, 0x90E1596A6A0EDD5FULL, 
            0xA7FA9F94241284F0ULL, 0xEF090F5C876D468EULL, 0x76EEDE2ED05CFF37ULL, 0x565932E27A3A83EAULL, 
            0x7407E56EEAA65ED1ULL, 0xE7072CFC5C80603DULL, 0x3DCD054A42EB3493ULL, 0x0C1607E23FAEFA4BULL, 
            0xE06EE747006F73CEULL, 0x3A83BC9E3C9FA028ULL, 0xC4C38E55C809CDB3ULL, 0x6D06C0EDBCABFE9EULL, 
            0x4EF36C2AB921F7F4ULL, 0xCE1D31763EA83DCFULL, 0x10024C6404FD4569ULL, 0x628E29089F843730ULL
        },
        {
            0xA671A0F58E593DF4ULL, 0x5779E316EAA3A52EULL, 0xB6A4B905080240B0ULL, 0xDDB7299E218F11EBULL, 
            0x631CBB896774DA4AULL, 0x8DD1BC9A54997930ULL, 0x75F8279D7F2433D0ULL, 0xFA95FEB00146266DULL, 
            0x07A15A769F99C7E6ULL, 0xE15C2533D93EB84CULL, 0x6232BE049BBC331AULL, 0xC2615454A59BF822ULL, 
            0x73834C74CD1D2F5DULL, 0x82B963BFEAF511DEULL, 0xF19123B9DCE7972AULL, 0x9D3EB016C449A2EFULL, 
            0xDEC6018DD8AA2677ULL, 0x8E32E7191CEAA51AULL, 0xCB2ADB95910FA1E6ULL, 0xA42ADEBD0BAE596EULL, 
            0xC3D434E0A5B6D401ULL, 0xAC783344272107CAULL, 0x1B9B38DBC5B47367ULL, 0x812F23457E228571ULL, 
            0x1DB58274B7A7E6D1ULL, 0xFFEEB63E0E296C00ULL, 0x926697A195163C77ULL, 0xE2D51F4D3810173BULL, 
            0x9F899A66FF607EB3ULL, 0xAEED925F86E913DFULL, 0x22FB6C2A6126C30AULL, 0xCC8874503F0BB633ULL
        },
        {
            0x7C54C13B0106A527ULL, 0xB7A22A52CC2A5EE7ULL, 0xB8D44307D743A31BULL, 0x4C8DCA6CDB298E82ULL, 
            0xA8B597E1D09B96C3ULL, 0xA8A4AE1544E8F876ULL, 0x10546CA63FF5542CULL, 0x77D9FB1FCB26A4C6ULL, 
            0x9BAE3F24C0F1EF18ULL, 0x1A03F146DC614739ULL, 0x379C9E02628A8189ULL, 0xF726D041B9F3BA0CULL, 
            0xBE131CE12FFD28B3ULL, 0x29B27BC443961B38ULL, 0x040D9CA1D3EB9524ULL, 0x93D2080A13104DC1ULL, 
            0x820A30EA691755E4ULL, 0x665C4FA26A8978FEULL, 0x7AE3E3FB4634707EULL, 0x83D2AE7F61D7D3E4ULL, 
            0x05CC3C6C7EF407A6ULL, 0x682B87DE00A4E3D7ULL, 0xE00C4D177D8567AFULL, 0x742BE48DD7675446ULL, 
            0x6FCDD90DA2389FF2ULL, 0x68535073ED806E78ULL, 0x24E284F3566BE94BULL, 0xB052B593FCE00322ULL, 
            0xB055ECEBFB21B059ULL, 0xFA8E5DE33ECD038EULL, 0xA28A1A7DC624356AULL, 0x7F13779053C33553ULL
        }
    },
    {
        {
            0xCAC6BC5FC6C3F94EULL, 0xFA4A8FF1DB33EF7FULL, 0x9C0D80A0431FE251ULL, 0x5D54413193B02E7FULL, 
            0x0FF8DF53B779D4DAULL, 0xAB5F326DC5D3A31AULL, 0x709BF948C215283CULL, 0xF77351ABE02AEB89ULL, 
            0x968D5E35B3AC9958ULL, 0x668B43E51BE37DEAULL, 0x1ECB548C54257084ULL, 0xC4F865A072CD547CULL, 
            0x14EA5A145F36A03EULL, 0xFE01103FCA34629FULL, 0x95AD0F0549F8F0FFULL, 0x269BA1D5F37BDAC9ULL, 
            0xC378A9BE2DFA5C24ULL, 0x9EF590678314F3ABULL, 0xFE52EED9DEE75A7AULL, 0x7168B4755287E03FULL, 
            0x79A1F0783DF82ED4ULL, 0xDD1B028958258802ULL, 0x9BF0CFCE76BCDD72ULL, 0x831C4B3E6C85A36EULL, 
            0x06A590BC67722281ULL, 0xF35606C610A6FFA8ULL, 0x159A02DA8BBB72C9ULL, 0x8945AD0B2F5235B2ULL, 
            0x2D6B64C26356320BULL, 0x55C1C72E884E4F63ULL, 0xF59E58452D70D6E4ULL, 0x7A03A6E89C2D7C04ULL
        },
        {
            0x048E3DB27B6437BEULL, 0x20279D1A332DE70DULL, 0x64CC339C5716CCB4ULL, 0xB4F97296B1638A86ULL, 
            0x257F74954F3A9095ULL, 0x42E86E7D2031352AULL, 0x6C9D6FE84AB61BF7ULL, 0x561045A90B1E018AULL, 
            0x0105BCEF539FBA52ULL, 0x6AEF8B403C740022ULL, 0xB074240CBF338076ULL, 0x6208B2585860240EULL, 
            0x5683AA7D57B9ABD3ULL, 0x8114EF407E7FA041ULL, 0xFD21C57A7879DE1BULL, 0x45A0637DA361FADCULL, 
            0x96D2556CA064EE6CULL, 0x055C0991E6FBAC5DULL, 0x0522477342135E5EULL, 0x64CC70B56C89FD19ULL, 
            0xA8344B1A99F2B779ULL, 0x0BC7B90B7A74E32FULL, 0x5BF2EDD008BF2CF2ULL, 0x2990015CC8BEF9FCULL, 
            0x421EAE16429CDEDEULL, 0x77E1DD9A5DE46FE9ULL, 0x5D49BDD6AEB03295ULL, 0xDC66DCF27A410C09ULL, 
            0x6F33F17239A41235ULL, 0xCF31B19D945771F3ULL, 0xB27BF616479A8E2AULL, 0xB51A989077CA9CA4ULL
        },
        {
            0x974BB17FD4170B8CULL, 0x7AF98BA4F7FD618FULL, 0x1248AD28261699ADULL, 0x1AD5D0D38EA6464DULL, 
            0x5F62B663D33A1FC0ULL, 0x54454961766FB3FEULL, 0x70A2A7BB822BDD2FULL, 0x1A439520E2244CDAULL, 
            0x6CD378320FDE23F5ULL, 0xE7BFAE864DD6B25EULL, 0xB3FAEDA2A9195A6DULL, 0x43CDAC997B76CE97ULL, 
            0xEF2DD81AD335B305ULL, 0x2A87A5E8F07B0B39ULL, 0x1F2E61448B7B0D62ULL, 0x9B0BF99DCA7190DBULL, 
            0x4065CEE79E729124ULL, 0x6649DB53E7AA75EAULL, 0x1D354AD7EABDE8A0ULL, 0x870108244EB29685ULL, 
            0x7F3682B85CFDEAE5ULL, 0x43A0679A1A527056ULL, 0x831469D890B0963BULL, 0xC3AF78A38A75480FULL, 
            0xA4440F8F1B12BDADULL, 0xE88C7D0965CA05ECULL, 0x24766E9C06895603ULL, 0xA506FC07D198D6ABULL, 
            0x104837A31B2B582CULL, 0x3406314B44463063ULL, 0x4503E0C975E5A917ULL, 0x81C1CFE6DE83450DULL
        },
        {
            0xB94BDAAAF4AD86D1ULL, 0xCAEBE9F1FE00E488ULL, 0x055730109E475269ULL, 0xF4EEC23F32890878ULL, 
            0x90DBC306D196D381ULL, 0x6E34883355F89560ULL, 0xA8E6C3C805BB2E60ULL, 0x89360375E27C5F49ULL, 
            0xBDCD0142A72E3E32ULL, 0xC7B5A7293CF80B8CULL, 0x1364329D9B267399ULL, 0x10A0898550015BB3ULL, 
            0x41497323E2709D28ULL, 0xCEA4AA40FB204C47ULL, 0x2946156D23F1A6E3ULL, 0x2BA92FE4E22F6204ULL, 
            0x005A971E648DFA6FULL, 0xE28A5807FE830D4AULL, 0x6E6C2C1326295D73ULL, 0x1D7B7154469F9514ULL, 
            0x22DB4CDBAAB61CACULL, 0x2B918534ED041D5DULL, 0x24490DDB4D0DD7DBULL, 0x7E09E6D15544A4EAULL, 
            0x54CDB4F6F878A557ULL, 0xB66B226C714FC5B5ULL, 0x92A1249653207F71ULL, 0x02A1904C5DA8D59AULL, 
            0xB6A69A459C38B0F1ULL, 0xD4CA7F232546AC9FULL, 0x6C4A97E804CCA2E6ULL, 0x09688130768FF597ULL
        },
        {
            0xDA511F59E1170944ULL, 0x1736A40D738FB880ULL, 0xF76DAC7E78AC6DB1ULL, 0xF95A74CE8CAF837CULL, 
            0xC54E9FC1AD0A0610ULL, 0x5FADF2E428614001ULL, 0x1EE06AC6700A2E75ULL, 0x4340483119005DD6ULL, 
            0x548F93AC96E17EA2ULL, 0x42E3B7A80542B306ULL, 0x494C5080CA4DAA8BULL, 0x84C86C87111C2045ULL, 
            0x7C9B583ABAD8E3FAULL, 0x0F48EE482B55DBE9ULL, 0xE592646F8139C36EULL, 0xBEE3AB303B000E94ULL, 
            0x1F6B9E6DAB98D297ULL, 0x1037298847DD3199ULL, 0x0F95764B722A19FFULL, 0x50E3A6B6C9B11EB1ULL, 
            0xB7E2E215479F018AULL, 0x4FD9D10283B6382DULL, 0x5189D1A054855B35ULL, 0x07CC766AFCA793ADULL, 
            0x6D1E2BEE7947F2A5ULL, 0x2D97363E58BC01B3ULL, 0x907C380065783454ULL, 0xEB7F2BE275A8197AULL, 
            0xD74DED7F0665D0FAULL, 0xD2376A53AABCEEC9ULL, 0x2C0D2F7FEB50D65CULL, 0x6255CB0380279562ULL
        },
        {
            0x8FFF4060E71D19DAULL, 0xCEC5172F1945B223ULL, 0x75EB2390FCEC854DULL, 0xFA1F4BE60D11F3B0ULL, 
            0x4276D1C096267660ULL, 0x8AC936CBD813A641ULL, 0xF25862AE2E599917ULL, 0xBD481EF7F069B3EBULL, 
            0xD5BC0E3C22226CF4ULL, 0xD42F017068D44D7CULL, 0x23D92C588495934DULL, 0xF6F5024FFAE3A3E0ULL, 
            0x7419035789AE2A93ULL, 0x38C8E87BEB41B183ULL, 0xF4ABF33708214AB5ULL, 0x368C67126D4E4362ULL, 
            0xE28417E4E7163726ULL, 0x33B1FED779EED8ACULL, 0x97E15651ED60C153ULL, 0xB7207C815CFC49FCULL, 
            0xD636DE3BCDF77667ULL, 0xBDDD037D87F0ACD7ULL, 0xFCDA19CF68B01AC5ULL, 0xC8EA9ECE9C886D09ULL, 
            0xDD453A0FE477F23FULL, 0x9691E2D55A48A497ULL, 0x7F5B3AEF54603F91ULL, 0x5D7CF99145E1EC97ULL, 
            0x7ACD057C3B850880ULL, 0x815DC4D071D0E038ULL, 0x11A23F784400DB08ULL, 0xB7B451E7C0D6847CULL
        }
    },
    {
        {
            0x86F96CE0FBC5A2CFULL, 0x4040E6BE2AD75C9EULL, 0x963B15111F380FB1ULL, 0xDE297894C6F8AC9CULL, 
            0x97D4D39A8F7E8891ULL, 0x4679D7DC9123F931ULL, 0xB0FA4060B0C01495ULL, 0x6EDF5ADBA10B0477ULL, 
            0x2581921E3B2DAB95ULL, 0x5DD135628145F208ULL, 0xC451DC2F5ACB39A2ULL, 0x081BF8589F3FD8A4ULL, 
            0x65BB0042AFF97262ULL, 0x2574BB9FA3BD5190ULL, 0x17D3BD4EDDCA48CFULL, 0xE681F635C47ED8E6ULL, 
            0xF8181E5C112A0ACBULL, 0xAD8852D282032BBFULL, 0x006ABA5D5F4B6C61ULL, 0x496D21247E346EA3ULL, 
            0x335C417CA8DEC4F6ULL, 0x53872D7444263004ULL, 0x3EEAE20D1D1929DBULL, 0xAB8E4AA7F66148A2ULL, 
            0xFFFBB8A628088F0CULL, 0xDEF970259B230F3CULL, 0x01EE50CCC3699838ULL, 0x8CB6FF3BC70EEE65ULL, 
            0xD46273CCBB5D9A10ULL, 0x47C8FACAEFF8036DULL, 0xBE8A533F8D0FBF41ULL, 0x8FC92F63DAA35662ULL
        },
        {
            0x0487A473327463BEULL, 0x94A15228DC0B8C7AULL, 0x3E1D3976E5C7DBF2ULL, 0xD54C38597BD7AA26ULL, 
            0x04F43C2213948BE6ULL, 0xB4123E0A9CF4F8B7ULL, 0x10897D82F90ABDC3ULL, 0x5A2317904B4ADCE9ULL, 
            0xD2F91879F45E7911ULL, 0xF6DEB66C27339905ULL, 0xA591B1FAAFA96E68ULL, 0xB4B858ABF1748862ULL, 
            0x11F8F2E4026DC58CULL, 0x6340FE346CA5120CULL, 0x9457C79A66564160ULL, 0x2407B6BA1CC2C661ULL, 
            0xD31C67A72801B93EULL, 0xA5641E9319A6B645ULL, 0xC06C6856B2FD6DBFULL, 0xD072EEF5A0872FEDULL, 
            0x28E0AEC780737BEEULL, 0xC53FFE328FF925B6ULL, 0xC99575EDDCE8DD7FULL, 0xFE676704C4EB6ECDULL, 
            0x0EBD12906BB43B9AULL, 0xA29F08364957F2DCULL, 0x8A48FDFDF8B35133ULL, 0xA731A031A0330AA7ULL, 
            0xE9F62CAF54BBCC51ULL, 0x8789AB4D3D627DDFULL, 0xA786A0FCB1857224ULL, 0xA237A410B4813BF6ULL
        },
        {
            0xC54AE5754D3ACA73ULL, 0x3CF27EA9A286D341ULL, 0x73546DB55E46C8D9ULL, 0xFD1C1A76D21B6900ULL, 
            0x3D2A7C9182BD979DULL, 0x9E15004AE12077B3ULL, 0x34D19CF8B0C8BA99ULL, 0x95422643366FB869ULL, 
            0x5E9AC5232345A0D8ULL, 0xEE955891C1BF41B4ULL, 0x47CCBD6A11FB5C3BULL, 0xD7DC4464128AAE3EULL, 
            0xF566F26286620A8CULL, 0x18EA3FA47D7FD7E5ULL, 0x8D2EA0AACEFAD0F0ULL, 0x814600F85016E95CULL, 
            0x126B2104E63E9DDCULL, 0x0F44F8AC8E50D077ULL, 0x82E1FE65B82CDF1DULL, 0xC03B5AD8DF3735A9ULL, 
            0xBD24B83295DF6A02ULL, 0x58739C85BE40BE7BULL, 0xA44A0B049DB011AAULL, 0x19269DA4A1877D16ULL, 
            0xA7F6E3F00794919DULL, 0x3C5D8C4496D6EBD9ULL, 0xAD9688F8E996DD8CULL, 0xFAE7A8C720C45173ULL, 
            0xF249AC7A1108C435ULL, 0xA61982D54B57BD9CULL, 0xD29D3440190AE96FULL, 0xD2A4EE49432A5C2DULL
        },
        {
            0x02B876EE445FB5A4ULL, 0x4AB7FEFE0881E12EULL, 0xEB8C32E0EFD319EDULL, 0x6AAB1B7F4C40CFE2ULL, 
            0xF7E6A4A741FBEAACULL, 0x1E22C7081E8548B7ULL, 0x813CA3529D5108C0ULL, 0x479A97CC8A1D83DBULL, 
            0x20F37DDFAE4D82AAULL, 0x8E95E0A2B34166B4ULL, 0x0458DC8C4D49839AULL, 0xA64E85669883462CULL, 
            0x10B60E3B5E70DE16ULL, 0xAA862D589CB41110ULL, 0xA72EAA6F5E7F92A5ULL, 0x557F71F96553D5AFULL, 
            0x9665D3EA086765FCULL, 0x8810F3E8E5D52F11ULL, 0xFE1299545C2FF767ULL, 0xE5755394726DCD5AULL, 
            0x3114C602A16746B8ULL, 0xDCA7E5BEA97BD8CAULL, 0xF999592D995CC4AAULL, 0x8D5C699E9327FFB4ULL, 
            0x4B1001D5E8353B5FULL, 0x96FC9787B35CB5B5ULL, 0xD34984E08F773A94ULL, 0x3588DA06C577199DULL, 
            0xD0126F44F83E930DULL, 0xDE96D64DBAB55216ULL, 0x088657C9349A8C1FULL, 0xFE42F6496D581211ULL
        },
        {
            0x2342E579ED30C154ULL, 0x272C449432098783ULL, 0x8A12A891A6C9BEDAULL, 0x6F733F1894155C08ULL, 
            0xD676E9704E2BAD80ULL, 0x4BE3458D493A889EULL, 0x455B337E2C9271C1ULL, 0x16440D592BC7A86DULL, 
            0x400E36C1A7A19316ULL, 0xDFCD697531301883ULL, 0xD2CBC1E0F6C40905ULL, 0x4442B7D4A1960EEAULL, 
            0x7F8B3EEFB18EDCF1ULL, 0x0B4FA9C85D0387BCULL, 0x269F162B8929E71EULL, 0xCF0BF35A662FE9C1ULL, 
            0xB4460A3652A3A1E7ULL, 0xEAF74781F335E964ULL, 0x9DAE7A03F886DA95ULL, 0x05D72029B99ECE38ULL, 
            0xDCBCF5DDD8323A5DULL, 0x7EE367C0393A5E5FULL, 0x794F625D597B1B63ULL, 0x1F3DE43879F43F31ULL, 
            0xD0F49D08692F5BE0ULL, 0xBF5237DCBE61ED41ULL, 0x68DC6C2374BB88C1ULL, 0xBC1AA11AFCBD4959ULL, 
            0x1029A560A801FF63ULL, 0xAA462DAF14615F6AULL, 0x8ECFABDFF14287AAULL, 0xCE0669ECBD7D74EFULL
        },
        {
            0xEE7757C7C8EC3039ULL, 0x2A2E06A3AC008E82ULL, 0xC55E33441D5DA4EBULL, 0x312A65199C2613DEULL, 
            0x0B0E74E1FE866383ULL, 0x64A36AB2FC77BEDBULL, 0xC2BF78CC5D2CAB28ULL, 0xE27AC91179246DCFULL, 
            0x29DEE30EBA6AD71AULL, 0xAB5336924E486EAAULL, 0x238909EF1C423FB2ULL, 0x7661995798E995D2ULL, 
            0xAB2960147695456DULL, 0xC369ADE6B00EA122ULL, 0xBCE3AE7FE873EE94ULL, 0x55D486B34D5241C3ULL, 
            0x13F7AFD2565CB5B1ULL, 0xC70B25DFA676961EULL, 0xB8C7AA69F1B3E669ULL, 0xA5CC650DC6E89E81ULL, 
            0x87055DAEB91FFB23ULL, 0x1CA309C423502D0FULL, 0x9D3D80F215C74A9EULL, 0x83B152DC15C1C148ULL, 
            0xC1E5B3F0C870598FULL, 0x2F1C935277C8190EULL, 0x8E8E40FF8781D976ULL, 0x58C0F5B0C401E29CULL, 
            0xE524DF3E921696A3ULL, 0x7A76B408127B80B4ULL, 0xBB26A9D8A5D73DD0ULL, 0xDD80F2566646BC90ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Canopus::kPhaseAConstants = {
    0x6BCA584F6EE2C2A6ULL,
    0x55535BB13DDD3B31ULL,
    0x71538ACDCA2B5B40ULL,
    0x6BCA584F6EE2C2A6ULL,
    0x55535BB13DDD3B31ULL,
    0x71538ACDCA2B5B40ULL,
    0x42E2F249B02E7875ULL,
    0x13E5FEDCB1B3FFA2ULL,
    0x02,
    0xA2,
    0x25,
    0x67,
    0x98,
    0x5B,
    0x5C,
    0x81
};

const TwistDomainSaltSet TwistExpander_Canopus::kPhaseBSalts = {
    {
        {
            0xB1D1D92C1F7CB52AULL, 0x3DF700895E5BC912ULL, 0x3A343647C8A6A8F1ULL, 0xFC09FCE794321AC8ULL, 
            0x06FED5641A379E91ULL, 0x327AF0CC54D6CD7BULL, 0x53BDBBAFF2A96F96ULL, 0x81C7D261B024286FULL, 
            0x9200EED62E222DB3ULL, 0x7FFACD74E95F00BEULL, 0x773C050B9D40C2BBULL, 0x089EF73FA9EBA8CFULL, 
            0x32AB9E1C98AE7037ULL, 0x6B44A647AA8863CAULL, 0xE0F2239E4C167EB6ULL, 0x395DC2170AD01000ULL, 
            0x778433A30FC31FB3ULL, 0xB0DED3DCB303C71BULL, 0xC6616125A7EFF70DULL, 0x08FC536EA156C30AULL, 
            0x7DACDC320025F6D1ULL, 0x0A64594259D4CEC3ULL, 0xCF17F81AE3162049ULL, 0xDF730A5226D5B7FAULL, 
            0x5B4D1E3004C3A0A9ULL, 0x91DFBC21C5CF6973ULL, 0x7E00AE46980A9685ULL, 0xD844CE4209099ED2ULL, 
            0xE5B2705E7563C190ULL, 0xD018CC11FDD12597ULL, 0xBCB955C4E3CFDC8DULL, 0x9B19ED5553FF2BEFULL
        },
        {
            0x304D3A0117B3EA14ULL, 0x484EF577437F669DULL, 0x99C8248681D53645ULL, 0x47525FC4040ABA35ULL, 
            0xAF13F68289A6D1F1ULL, 0x4904A875D6755B56ULL, 0x7D4C74212774B8F9ULL, 0x36C5C67B2C41C3FEULL, 
            0xA5638FF932E5B43BULL, 0xA3FEB2F07C1A8901ULL, 0x4BA338FBFC346CA2ULL, 0x73C21FB9F45154A1ULL, 
            0xB1B478E1ECC52B32ULL, 0x14C067AF0DA06BF5ULL, 0x53A5F49F540A8D7BULL, 0x9339D1A56FE1EBEAULL, 
            0x940CEB5DBA95C13FULL, 0x23915751B655EC3AULL, 0x718FF5891E44F717ULL, 0x8F1D2A8740836BD3ULL, 
            0x2BB8285D8EEA09B2ULL, 0xDDAA8EE57DC4D797ULL, 0xB2960D8BB47DEC0EULL, 0xA27038DE8DE1B39DULL, 
            0x535CE6C39C0EA179ULL, 0xF9AC799439D07767ULL, 0x538F9763874CAFFCULL, 0x48DD996898C89916ULL, 
            0x4E41C33B702481AFULL, 0xB0AD90610156A190ULL, 0x9370225F8F807EB7ULL, 0x77774C9BDAFAAE43ULL
        },
        {
            0xCD2E1DBE8246A3CAULL, 0x49F26D07BAA57377ULL, 0xE7C9E73B69E88401ULL, 0x7182E66C3736485CULL, 
            0x36A76834CC09F7EAULL, 0xF64E9360A325EA61ULL, 0x2FEA5382351B9C04ULL, 0x3C1502901645D120ULL, 
            0x9BA24A7F1F942AD9ULL, 0xCD79C731638851B9ULL, 0x032237CF6643A63EULL, 0xF95362DC5E3C71F1ULL, 
            0x9EEC354C668F58B5ULL, 0x6774C3250CD15D52ULL, 0xDBF2952105924B4AULL, 0xE6ACF82EBF03B9E4ULL, 
            0x74FBE7B1FDB2C2B7ULL, 0x164D29FA28BBA4EDULL, 0x342C15AB53FA6B04ULL, 0xF72A32A8CA06FB95ULL, 
            0xE6C659618C95CD10ULL, 0xE8DE3EF8275E07FDULL, 0xEBB258C9D9166734ULL, 0x62E98930F59B0A40ULL, 
            0x75C9B0906824ACC3ULL, 0xFA9BED0A14E8DD31ULL, 0xBA4BF8DFAD762B1CULL, 0x3C4AB9F550707882ULL, 
            0x468070AF88A9D0E5ULL, 0xAEB65F3D509D62C8ULL, 0x7F477A76B117D39EULL, 0x09B5A2DF4AD8B594ULL
        },
        {
            0x2B93B4EDAD758BFCULL, 0x5B77E5070E392969ULL, 0x88F957AC7D08CBF0ULL, 0xFF439925FFEFE7B0ULL, 
            0xC92E97C41C4B17FFULL, 0xB3228B49782A3A21ULL, 0x8ABC42B403CE95F8ULL, 0x15514D6D3D113B0EULL, 
            0xC0A003B15DA6F86EULL, 0x67BE641983B69D2DULL, 0xDCE964D5309A4AE8ULL, 0xE6B3A3EFF38464DFULL, 
            0xA96A4AAB93DE90D1ULL, 0x3A55D3B7F2DF1C52ULL, 0xA863624912CBE1CDULL, 0x6E61EC801EDDDE2FULL, 
            0x561E1BC508389C51ULL, 0xAF895EC9EBB57E96ULL, 0x7E813995CB98A86DULL, 0x718EE9001B627097ULL, 
            0xCE510A3C2CFF5819ULL, 0xF60BE51404E01BE3ULL, 0xA9E2F33321FC199BULL, 0x87DAA87C6AB4D76AULL, 
            0x6FB472DDD51696B1ULL, 0x01BC1B79EBFCB115ULL, 0xA20F3C5A81B0CED8ULL, 0xC50FBB5EBF17ABC9ULL, 
            0x7D5C5A462BA3B236ULL, 0x1F1B25E651A25F32ULL, 0xE822977933AE9D12ULL, 0xD6691A11C51C3886ULL
        },
        {
            0x232A921D0753346DULL, 0xCB6167045A75D4F5ULL, 0xC2D84EAC4CE52C32ULL, 0xCD192CD5C085EA2FULL, 
            0x09854F9C2875A6C1ULL, 0xADEA820F5AB70400ULL, 0x37636768992DDEBBULL, 0x1766DB79AD86FB36ULL, 
            0x2AB3B9CBC7F2D7A3ULL, 0x189F4E0115A4C01FULL, 0x5AA93AD1CABBDC5DULL, 0x393CD6A1BEEC482AULL, 
            0x5F08223B3440E7ECULL, 0xBD5E006BD6068B58ULL, 0xAD755E5C65A670F4ULL, 0x0B4AB9C4DE8C94EEULL, 
            0x24A465F825FA11FAULL, 0xB4711D0226B0B04CULL, 0x2D777C13BE60CE6BULL, 0x8F41DCCF4B8A2F0BULL, 
            0xA2C7FAEFBFB52E0BULL, 0x0E9E5AB66D83A97CULL, 0x9DEDCD6FA6C357EBULL, 0x99B0E9E3131CFCE8ULL, 
            0xDD39F8B4BDF89131ULL, 0xC4B2D8FB416D8796ULL, 0xE86A44A1698F5053ULL, 0xDCDE3945C50A5A16ULL, 
            0xE713D4E06061CD64ULL, 0x0AAB177FCDFE8553ULL, 0x15344BCEBB1A59F8ULL, 0xD0A7B03757D65A96ULL
        },
        {
            0xC145DA4079EBC076ULL, 0xE196203839A153EBULL, 0x0EE22A550EDE6393ULL, 0xB8055A967F87F528ULL, 
            0x7193AF8A5D9792E7ULL, 0x2273D634F40997F0ULL, 0x8975FDCB9777ADE8ULL, 0x036EFCF78F59ECFAULL, 
            0xFE755275F5A6A969ULL, 0xAC5B4F8A2B651CC1ULL, 0xF2541D38FBE1E035ULL, 0x5D7A9BC64E4C17EAULL, 
            0xE4DD01305B2532D3ULL, 0xF9F9B73D7EC57834ULL, 0x8F6366B68A122D6CULL, 0xAD845518D805EFECULL, 
            0x5483687E82E12B2AULL, 0x99B99F85EF0C0992ULL, 0x2F9C790FFAF1E204ULL, 0xCA41113DC9303412ULL, 
            0xD63D366E2E2E5FDCULL, 0x51EBB34D41395852ULL, 0xBDED566C226B5CFCULL, 0x3201D0EE027E08BCULL, 
            0xD11BDBA85A97806EULL, 0x4753ECEC5B654DD2ULL, 0x7AE67F31CE59C985ULL, 0x85FC75CFCBB3AB41ULL, 
            0x74C714090135DD00ULL, 0x835DF1E442133FDFULL, 0x477452CDB461C1D1ULL, 0x197A3AA8DF7870E3ULL
        }
    },
    {
        {
            0x9B0CAC561AA1BC69ULL, 0xA23A8A25F71E3065ULL, 0x84FB47F87722992DULL, 0xC2C492DD1945F2F5ULL, 
            0xD8EE9FAB1F6703CCULL, 0xF63E0EDA271A139FULL, 0x285F8F80338A7185ULL, 0x79363D68B7ACA188ULL, 
            0x4F77347B382EF6EDULL, 0xDB51984F3040D44BULL, 0xEAD1FCC0DEE374FCULL, 0x5BC69AA4D935BB42ULL, 
            0x112EC722B14F824EULL, 0x70F7BD41017F7898ULL, 0xB80ABA4240CB6E81ULL, 0xB96AEB7DF8479D2AULL, 
            0x28A462129085BAABULL, 0xDBF056B9D035919CULL, 0x19E93F078FDE2B33ULL, 0x1F613500822E105DULL, 
            0x5527E64BEAF2279FULL, 0xF9AA41057C51F197ULL, 0x23F230EB0920EC63ULL, 0x4D932F1FDBC3BB76ULL, 
            0x995D13805E6BD4A6ULL, 0x83CE714302CE6F94ULL, 0xD4DAF60143FFB56CULL, 0x8877765B8E1C6251ULL, 
            0x9BE62B7176919931ULL, 0x37D7217DB2524F58ULL, 0xF75E0830CAC821FFULL, 0xFCB7D074A6320571ULL
        },
        {
            0xAD139C05EAE7C8A6ULL, 0xB801E99EE2A8384BULL, 0x70AFF0AED6618871ULL, 0x42FB015BF21ECB14ULL, 
            0x499EBCEA2303C154ULL, 0x229CF58C57A70DB6ULL, 0x98993E03A102CE93ULL, 0xBA309B0F7CA460C4ULL, 
            0xA19CE9D926221C63ULL, 0x60D2F0AF3B0A6DE5ULL, 0x3BDA2825A252F26BULL, 0x98E1F0A8F29902DCULL, 
            0x1136F266E604293BULL, 0x49D3CED361650D22ULL, 0xDFE7A57F0E1D9E84ULL, 0x5330F300E71C8A81ULL, 
            0xDA37CC8E44440523ULL, 0xD7E0FC605AE5B87CULL, 0xF7FC713770D2320EULL, 0xC117EC35D773862FULL, 
            0x0409E0CF43397859ULL, 0xE14D693729C30A59ULL, 0x5D1D34D3391C0FF7ULL, 0x878AED6BAAE8AE4CULL, 
            0x33E77EFBB4ADF056ULL, 0x81F03BC28354113AULL, 0x322726026218469DULL, 0x70C16917AE32B8C5ULL, 
            0x5CD03E7A3AAB88CAULL, 0x730D25B20F659E84ULL, 0xF87D54D82746240AULL, 0xD88F8D5ACDFE95C3ULL
        },
        {
            0x3618A613B78855F6ULL, 0xC26AAD7AF9635A79ULL, 0xE21D3F7A3888A6D0ULL, 0xB46CE280E90E82D6ULL, 
            0xF400313C6802EF6AULL, 0x082B445B3267D28AULL, 0x3F0290DF08C4E945ULL, 0x6FB030BEBBCB84A5ULL, 
            0x48A8156E78BFF224ULL, 0x0205127860052AD5ULL, 0x7DB247D3F258A040ULL, 0x8359E792351137F3ULL, 
            0x1EB93ACE082381FDULL, 0x2CC941A047AFA1BDULL, 0xA198AA01E5396FCCULL, 0xB303A7FBEF80AA27ULL, 
            0x26A73493D438AAD1ULL, 0xE11D96BB4E79E6E1ULL, 0xC997BADA1C94CC7DULL, 0x52F2E9B755F1519BULL, 
            0xBB1EB18BFD6F1599ULL, 0x7120904F6339C617ULL, 0xE64E1A4565B6923FULL, 0x1F80D2AF540C6417ULL, 
            0xC0BE09FC04536FC5ULL, 0xAFD2C1067A8C76EFULL, 0x63902ADB66BA5FBEULL, 0xA6C0BA6452EA6590ULL, 
            0x65E86CC8EB89B003ULL, 0xE62DF42736F85FB8ULL, 0x1014C02CFFAA2E37ULL, 0x4F20F39CB88C1C46ULL
        },
        {
            0xC5143242D332784CULL, 0x6C9137784E63DA2CULL, 0xFF734D28FC6615FFULL, 0x409553C0EE3F6FC5ULL, 
            0xDC40B4A2FE8227F7ULL, 0xFE5971D49AD75727ULL, 0x1A3C2FF47E5AF871ULL, 0xB0A7F664FD8F9994ULL, 
            0xEB37699F984229BCULL, 0x57D01CD06DE31E69ULL, 0x12DE176E6D8BB201ULL, 0x2E9AEC455F1801A1ULL, 
            0x18F5A0DFD3DC69B1ULL, 0x3B4ADD3EA9DFC7B1ULL, 0xDE858C1114485E38ULL, 0xA8E7DD4ADE518CF1ULL, 
            0xD4FC0F694CF62988ULL, 0xC7F26D24D2B37F64ULL, 0xBF4FEEAF46E15C8DULL, 0xC31B845CAB925434ULL, 
            0xE22FCD69AB1AB2A0ULL, 0xA28F68879F3D94C1ULL, 0x6D5FAEEC732F3875ULL, 0x01477CE05008DDDAULL, 
            0x25B8BC49BB5F1D72ULL, 0x81BDA68140976472ULL, 0x6D2D1E59DD511CBEULL, 0x1516DFA9AE3A6887ULL, 
            0x3072F6392A223FE1ULL, 0x10E0335CB1401014ULL, 0xA29F4DBA8663F91BULL, 0x70BB4D0DDF525817ULL
        },
        {
            0x5AFC067D4E77EE3CULL, 0x8A2AFFE64448C22BULL, 0x67A24DEE5DF2DA84ULL, 0x72C29B34021006BFULL, 
            0x7CED719ADDBFB59AULL, 0xDED3E9DF9C29B30AULL, 0xCB3673931AFBC68DULL, 0x9E64E6CF79697CCEULL, 
            0x215CAA963D7EA73EULL, 0xCACC2D5CDFC9CC53ULL, 0x9BE75DCE5E76A962ULL, 0xF93A6D6E39043B78ULL, 
            0xA552F497A8298506ULL, 0xAEFC3B8B85268BFCULL, 0xEFB9B8EF283261F9ULL, 0x84A009EBCE3A6747ULL, 
            0xBDE686D14986C85DULL, 0x9361A38CAFF0971AULL, 0x5F0E9AEC08A1F950ULL, 0x4C84158DA6BB475CULL, 
            0x40A3600DC16F9ED8ULL, 0x66500B5E8A7A332EULL, 0x53ED2B1416F471CEULL, 0x0500D698AFC30D40ULL, 
            0xA9D32B07CA8A22D7ULL, 0x06045E1B81241354ULL, 0x993B8C43E5B4A8ECULL, 0x1CE06BD70B788038ULL, 
            0x1A49F4D73BBCBE47ULL, 0x76A95BA3189449D4ULL, 0x7266B3667DB3700CULL, 0xFEFF2DC3AF034682ULL
        },
        {
            0x365E95597F35080DULL, 0x586C31941E0A4BA3ULL, 0x8A596F9C6ED93AE2ULL, 0x0745F214A98F9FB5ULL, 
            0x6431965692CDC693ULL, 0xD2E50FE36E9CAE4CULL, 0x505F75EC18928D17ULL, 0x87A9CBE6236A5EC7ULL, 
            0x2AE180A9B337A36CULL, 0xD1667824DC04A027ULL, 0x697853114629A5A6ULL, 0xFF390AE46C2985AFULL, 
            0xDA62C7389D189E53ULL, 0x87D8C6AE1BD18CB6ULL, 0xAB68103896D7104FULL, 0xC672DCFAC97E8470ULL, 
            0x053F98B97CED94BDULL, 0xB0BFE694BF7137DEULL, 0x9BA4F16327CB5B8EULL, 0x9BA460DED46B4E7BULL, 
            0xB4017DA06C790896ULL, 0x7B9A09C8CB26A36AULL, 0xE8F2495B12CA4688ULL, 0xF99FFCA026C22DF3ULL, 
            0xC957E3FAD2EB391BULL, 0x98BD91425DB8F005ULL, 0x434509D3F3D14271ULL, 0x24984BDC61DC21CDULL, 
            0xC6C7B5F07F3D6934ULL, 0xBFE5632F34D4066DULL, 0x7B15887E57BF9A5EULL, 0xE7BA58D8D1293D6DULL
        }
    },
    {
        {
            0x0F263AFEFF3B4B24ULL, 0x2FD377042DB67D62ULL, 0x50F9C7F797892479ULL, 0xB5F06090FFCA487EULL, 
            0xA5E5D7944629999CULL, 0xC347129D54B8204AULL, 0xA0DDDF6CB7036EF3ULL, 0x6ADE6EF88B396221ULL, 
            0xE6E3F223DEC9CEB7ULL, 0xEAC1845CDA95E001ULL, 0x9B80E94B73B808AEULL, 0xB867277B0552CD9AULL, 
            0x229E345EC7880C9FULL, 0x1880133E7DC7A1D9ULL, 0xB72C885FFC32D864ULL, 0xC4C1BACE36B601E2ULL, 
            0x4AABBE78F3E5A8F9ULL, 0x820D3E5A6F12E97DULL, 0xACD6496418B6793AULL, 0x3A74A34CEF0329B5ULL, 
            0x76D3F62D2B8B662AULL, 0x673B44F751588FA9ULL, 0x0A152250F3A2457CULL, 0x53E2472F8E92718FULL, 
            0x49520214A83567D9ULL, 0x8B6C00A3314260FDULL, 0x7C792C0366E6F5F0ULL, 0xE2355833579B020BULL, 
            0xCFEF63EDBD2B9EA0ULL, 0x79A07C00A084F252ULL, 0xDAD46136B529A5B4ULL, 0xA3BABDB57C80DCD4ULL
        },
        {
            0x0BAB789F1DF3010EULL, 0xCC6906D49CD79686ULL, 0xB5595913807AC89AULL, 0x95F68261796010A1ULL, 
            0x40501B3AD706A1DDULL, 0xC3D46219F098F5A9ULL, 0x7E721FE439B25CB7ULL, 0x9EB572EF2DBA8F1BULL, 
            0xEB15DB859ABA351AULL, 0x7F919B9CF980323CULL, 0x0FF4E599F3CB54A4ULL, 0x870CC23D1EF8E9ECULL, 
            0xA6FBDB674B142C12ULL, 0x6E0BCC531EBACF34ULL, 0xFDE255DBB7A84B90ULL, 0xB8CC898AB306E24BULL, 
            0x075A0FC5F5F3EE41ULL, 0x64E4D36CBC0ED44DULL, 0x3EA5F0F8B1FB046FULL, 0x473F5B52226826EEULL, 
            0xD8AAA878CDFA1F77ULL, 0xD5FD311E249A5AE0ULL, 0x4DB5DC77C69AC8FEULL, 0x7B3BA1F20156B3F9ULL, 
            0xC904A8597526B9F5ULL, 0xA346B0D0E986A990ULL, 0x11349B0A8C8A115EULL, 0x7FF68BAEE1821A5FULL, 
            0xD5F608C2E166FE49ULL, 0x2C4F8D043F0E5DD6ULL, 0xD047A1204B2EF950ULL, 0x72C6BA5235DA84C9ULL
        },
        {
            0x80C645CD87487F66ULL, 0x18549F396F635077ULL, 0x1A2A52229395ED91ULL, 0xDECE0CCC9C5C3FCAULL, 
            0x8BD3AB1613AC7AAFULL, 0xC7FCD47D9721B91EULL, 0xE4BCFD03D1DF6FC6ULL, 0x891628812B973CF7ULL, 
            0x235007F660815FA6ULL, 0xE71A5B12694C61F4ULL, 0x1B84DCB9CC1A11C8ULL, 0xB934401DAE7AB6B1ULL, 
            0xF1BADBE92B67ACD1ULL, 0x7AB13168C7C57E11ULL, 0x2D2597E5415873AEULL, 0x770523718307F666ULL, 
            0xAB8496D002D2749BULL, 0x36B097F0DBB6C538ULL, 0x98ED0E9D5C561679ULL, 0x432B8F9E61601DCFULL, 
            0xD1267F965D9DFDCDULL, 0x3F5722F9CFBF84C0ULL, 0x00AF8E48AB9180AEULL, 0xB982FF33692D1B3AULL, 
            0x8F95A93D2C046ACFULL, 0xD682E8F0645B4F52ULL, 0x8FE0069D836865EBULL, 0x20C29A6507007B1DULL, 
            0xE8710CF8A3EEFEDEULL, 0x50A88AC79D1E580FULL, 0x033989352E991546ULL, 0x057EEFA888ADA786ULL
        },
        {
            0xD7961517921A2FC5ULL, 0x4175A0B445232BCCULL, 0xCE4163DEC8816B37ULL, 0xDCC93858BAD0B7D2ULL, 
            0xB1BD2D2784CDF7A0ULL, 0xCE19EB2CF7CD50DCULL, 0x528514EB78F5AE10ULL, 0x44D550BF70956B1DULL, 
            0x4AAE1A7A0DA12F01ULL, 0x677A440D893C6526ULL, 0xD0F1C190C41F6AB2ULL, 0xEDF4FE65B3571EEDULL, 
            0xB8C7F250C583B232ULL, 0xA186F1B2277A1BE4ULL, 0x978A58177B61E213ULL, 0x3426F0A412EF6F9CULL, 
            0xECA096DD962F287FULL, 0x468706C0356544C0ULL, 0x7B588CD50A427AAEULL, 0x6CB2A75F5C6DC5DCULL, 
            0xA8C175AB4C57C7F2ULL, 0xC142296A18FDB46BULL, 0xEA9E5E64C542C3DBULL, 0x91A50B7D25E0CA6CULL, 
            0x85A821433B9A0F50ULL, 0x958968AD75BF2DFEULL, 0xACCD50482E67157BULL, 0xA91AB96E81D2F070ULL, 
            0x22F3B4E21BADC828ULL, 0x95E9EA9B1BF6FCC0ULL, 0xABB1B9156D2D0EFBULL, 0x32729BA74F9006BBULL
        },
        {
            0xA91CD2AEF7F0863BULL, 0x205DB86675118D81ULL, 0x096599295BF6EE8CULL, 0x114E33F288FC0E6CULL, 
            0x07568CFD8509E84FULL, 0xBD60C191EF340FD5ULL, 0xC12E0F75765E3FE9ULL, 0xB6F3CAB0FDA81829ULL, 
            0x3D3DE905B8F21494ULL, 0x81367999CF2601AEULL, 0xBE2E88032AABF2D1ULL, 0xFF0747DE8C6262D6ULL, 
            0x8427E81C20B4F665ULL, 0xE20734B4D65A7BF3ULL, 0x90D99E6BFFD15ADEULL, 0xBB20786F7A07499FULL, 
            0x2FA3857FAE787307ULL, 0x50066B92A1B0BB86ULL, 0x352FD971E62AEE3BULL, 0xE307FBB9FDA512F6ULL, 
            0xBFBBBA922184DD26ULL, 0x177784AAB4F39016ULL, 0xB3EED10D04F87118ULL, 0xDFDF23DD92509CE4ULL, 
            0x6350163E6C5670BBULL, 0x6609A523E1197FD0ULL, 0x56C27FF1E88332E1ULL, 0xE37133B0A7DD44ACULL, 
            0xDB1FD810635BCD00ULL, 0x44F4EE3868784799ULL, 0x0AFE0320CA920D36ULL, 0x4D07BEF806AC99E2ULL
        },
        {
            0x8C8A72D4EBAA019FULL, 0xC943717A82C70FD5ULL, 0xCB38A9D16A4F0F6CULL, 0x66B04FEF52ECDE3AULL, 
            0xFB373F72D7F87EFAULL, 0x625B9B4016CF6590ULL, 0x0BA0AEC6236FEDF2ULL, 0xD7BDC9DC9A7670FBULL, 
            0xB4EEB7B5AD561D94ULL, 0x262A2EBF00E7CDADULL, 0x20C7D2ABCF98CF85ULL, 0x6701B1BEF650303CULL, 
            0x2771F29B23C1AA7AULL, 0x4A4BE9DD17BFC42EULL, 0x6B3BD9FE2DE7864DULL, 0x2B40A9AFCCE14DEBULL, 
            0x4D21F1DD3915B84FULL, 0x7DA645F3CCCCA28BULL, 0x60E67FEB56BA9B91ULL, 0x78E18D82A59D20B6ULL, 
            0x0E1176592A56673BULL, 0x84BC3F18C6E06197ULL, 0x84E5A0643CEAA832ULL, 0x76649ED4E67F7FA9ULL, 
            0x089A32570947E6D3ULL, 0x955CEBA2F19BD603ULL, 0x2D811B58AF6A6264ULL, 0x76998F0DEB30B179ULL, 
            0xCF5ED39E91E5E263ULL, 0x95025AA874765FBEULL, 0x157621A11DF69443ULL, 0xE8120C50E5E33E6BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Canopus::kPhaseBConstants = {
    0x143DE0FB2836E0AFULL,
    0x7773766B81DBA318ULL,
    0xB92B86F24817A03BULL,
    0x143DE0FB2836E0AFULL,
    0x7773766B81DBA318ULL,
    0xB92B86F24817A03BULL,
    0x63585D0DA9DD9BC9ULL,
    0xB0E168711485CDF9ULL,
    0xD7,
    0xE1,
    0x9F,
    0xD2,
    0xE5,
    0xFF,
    0x3C,
    0x23
};

const TwistDomainSaltSet TwistExpander_Canopus::kPhaseCSalts = {
    {
        {
            0x02B1B1972907A969ULL, 0xD1C597510779ABB5ULL, 0xECA7FB46CF59FCC4ULL, 0xC5C14ADBE14D4111ULL, 
            0xFA9B8253984A74E3ULL, 0x2915D6B3A80534A4ULL, 0xA30F67A2D9537E46ULL, 0x81DDBC4E9217EE94ULL, 
            0xDB31431D3561750AULL, 0x12A74D4D4EF04236ULL, 0xDD40B36CC740FA24ULL, 0xEE4002E10EC6C17EULL, 
            0x4020E6F75AD8FE37ULL, 0x8F89A07F0608C1FDULL, 0xC21523221A93AE77ULL, 0x375508C4322251CDULL, 
            0xA16C231F25E3AC98ULL, 0x1518FD995058E7F9ULL, 0x7D381E77C0269A69ULL, 0xD618E6E6489F7F46ULL, 
            0xEBEF0682234A5C02ULL, 0x3873FEDF9924CDC8ULL, 0x94A6CE53ADE8E5ECULL, 0x52B6EBA21E56ED4AULL, 
            0x9C763B7E5B92B7EAULL, 0xA675A56BC30B280AULL, 0xA6D2B4602F20A32EULL, 0xDCD5BA717828E792ULL, 
            0xCA310B5FA2CF32B1ULL, 0x8BC92CC2252DA07CULL, 0xC431B0CA0C1F40A7ULL, 0x7F262A18012A4A53ULL
        },
        {
            0x2A71299A77EC4D18ULL, 0xF7679F5C61DA6CB2ULL, 0x1A495017289C0ABEULL, 0x2B45445A57CF757AULL, 
            0x657FD4E704C13D1BULL, 0x7E60CDE469CEE2C3ULL, 0x6ABA2FA1ECDBA789ULL, 0x9AD722479EC3F634ULL, 
            0xA7ED98AFB0313489ULL, 0xE232A12F070849E2ULL, 0xBCF31423B6FE61ECULL, 0x1D82155D8723F7C3ULL, 
            0x58AF535BEF5E0804ULL, 0x338DA12792CB5843ULL, 0x59A3205F949B4AE4ULL, 0xA99EB5873F2A6C29ULL, 
            0xF4448C53D506943EULL, 0xC9072700DB40F0A1ULL, 0xA02972DF020A11F9ULL, 0x240945B0526ACA48ULL, 
            0xA3E1A4E900C817A6ULL, 0x58E9A05BFCAD6BD3ULL, 0x0B355E99BC15E225ULL, 0xEF5D3AEF4C9D9BAAULL, 
            0x7675BB6AAFFC630BULL, 0x6239406F8C0AE682ULL, 0xA6F01B39083B3593ULL, 0x958BD90793D4BCE1ULL, 
            0x6CF16BE91DDAEC59ULL, 0xC08F3D98AE7B1A54ULL, 0x4398D1F4CE6DA3B0ULL, 0x7C7CBD8CB6598CACULL
        },
        {
            0x326422CA5C38143FULL, 0x370671E569E4B756ULL, 0x7CE7D94CBE4DA7C6ULL, 0x027E88E0C300E0AAULL, 
            0xD25DB734D465BD25ULL, 0x4A0B4A00DD056228ULL, 0x07E7BF354C9CAB4DULL, 0xCBCB2A8E1B90BA44ULL, 
            0xADF46D4FBFC8EB58ULL, 0x30EDF2E1656B4DBAULL, 0xA653CCD6D910999FULL, 0x169FA5C84C9D8C4CULL, 
            0x0113D4DBAF591733ULL, 0x566EB5BD35F188CEULL, 0x96E068B2D0AF3D31ULL, 0xC093FCEC43C4587BULL, 
            0xF07B782C6E023F2CULL, 0x16EB23B35136F1CAULL, 0x4A1DE5F4450A6DC1ULL, 0x084421305B36C9BEULL, 
            0xF6534BFB6182E687ULL, 0xE1FE3FF8FD92E248ULL, 0x5374A6375702EBA7ULL, 0x0B9B3C70AC7D702EULL, 
            0x16529AF2DA3E27E5ULL, 0xCF725FDB84E128D3ULL, 0x42AC0272A92662C9ULL, 0x765D591224B66B52ULL, 
            0x10E39EF0EBFF3200ULL, 0xE05E524EF9164383ULL, 0x7DB2A80DDEBCE4CCULL, 0x87E83084D796AE36ULL
        },
        {
            0xFC67BDEAD09F6A75ULL, 0x8291CBE5143B0F1CULL, 0x472771B61E01548FULL, 0x527A8B671FABFDE4ULL, 
            0xD3F6D906A51C1EB8ULL, 0x5B92ECC3DF6BD177ULL, 0x4B26132106300AE9ULL, 0x1723CD97DB0E1CB9ULL, 
            0x95752074633D09ACULL, 0xBBCF36B5D92A3F14ULL, 0xC4F22E39AFF2B736ULL, 0x9C1B4B816678A5B2ULL, 
            0x028840996C2BD260ULL, 0xB69DC044B149C7C2ULL, 0xD0E337E684F463B9ULL, 0xE947B77EC3BFCE48ULL, 
            0x67E1F00FFB282D75ULL, 0x23E3EE581BD1FF04ULL, 0xC2C7C5FEFE161BEEULL, 0xB8951275BCD8FAC4ULL, 
            0x90C27FB8F54C8DA0ULL, 0x108635B2764548C2ULL, 0xCE5570DBF65DB4E2ULL, 0x9B3E1E99A0AE5B70ULL, 
            0xF79EFF352ADB41C9ULL, 0x5DA9F9784F63E473ULL, 0xE8B320582262E7D5ULL, 0x7EA0D2EE06BA700EULL, 
            0xF532CFA322C47C86ULL, 0xBAF6710306C4A258ULL, 0x15D407A70B4100A2ULL, 0x1AA9D41EA2FA8FE6ULL
        },
        {
            0x008078ABF87E3E98ULL, 0x3F288FCC248F20E1ULL, 0xDBABBB2F16BDF595ULL, 0x44196B5CBA2A74A6ULL, 
            0x67AD1C7B18F5DD7FULL, 0x3B3F13395387DAC0ULL, 0x494B705848D0F864ULL, 0x31625090094B2D02ULL, 
            0xFE625479E7F836CEULL, 0x7444BE67105DC94FULL, 0x9E09BDCF9F6C08B7ULL, 0x25AA139A9BB23F13ULL, 
            0x6F73E3A14A8FB05EULL, 0xCD45EDD75C826F04ULL, 0xC14EB8070666D5E8ULL, 0x2A7BA45B18E15954ULL, 
            0x82EC24558AF39DE1ULL, 0x88181FED4F2DDD56ULL, 0x3511753E7484A5F5ULL, 0x59C3436BF2939447ULL, 
            0x60E31EF00A6C268CULL, 0x92F5F5AF800BEB21ULL, 0x26EFE697FDD81168ULL, 0xB9E2F611C882673EULL, 
            0xE797940F8AC18CFEULL, 0xD5E2D3771A257CC7ULL, 0xED2ECD7303A112E7ULL, 0xF3A603287028D9AAULL, 
            0xEFA8431DE7AA4905ULL, 0x64DC659777AF569DULL, 0xA958E1D2B051A142ULL, 0x534ADC5B10212B9AULL
        },
        {
            0x10F1ED24B2F8788EULL, 0x92697C77D6B31D13ULL, 0xDF5DAC475DCE994BULL, 0xF8C4B9DB8965698AULL, 
            0xB3EAF6BF3253D725ULL, 0x091162BEFDB59EE8ULL, 0xD31560770D249C12ULL, 0xFD78AEFDAFE82316ULL, 
            0x6E5BA4E2A2D31D77ULL, 0x6B1D7746460B1D12ULL, 0x7A4BB3F834535A04ULL, 0xB58ABC8338E7B9F2ULL, 
            0xB836EAFE0C756176ULL, 0xF5DB6B54F29CC086ULL, 0xEFA8ACC7AF0F7B2BULL, 0xCBF6D9E15480A835ULL, 
            0x3ABE97FC067F08E2ULL, 0x5E2D871183A2FE33ULL, 0xF36AD13CFA22BA3FULL, 0xF0292FDC5ADB234FULL, 
            0x74E04719D2830333ULL, 0x18032597226C5EA2ULL, 0x35DA15196AC50153ULL, 0x69852704386B5A07ULL, 
            0x4E62505C33E2EE0DULL, 0x736CC65476C3F11BULL, 0x0FF0C5E5C6A6A168ULL, 0xF77A956DCA0C072DULL, 
            0x8EB54212FB363381ULL, 0xDC79671EDD7866D2ULL, 0x22F6C4AA46EE1745ULL, 0xEA7F3F5DCFD68E95ULL
        }
    },
    {
        {
            0xCD692CC95AC9C438ULL, 0x4A98B121E24C0B6FULL, 0xB59E4E46C168B359ULL, 0xC85F3A3FB50CB465ULL, 
            0x23C565CDC85DE3EDULL, 0x8E72E81160A2D7A6ULL, 0x3FC3A9F5B16BD9E3ULL, 0x748667D85F57C5B5ULL, 
            0x588F3915C331C02DULL, 0x8CE56A22E91E16F9ULL, 0x0261A95600BC3955ULL, 0x6B8F7607208135D3ULL, 
            0x993CE12F90B19286ULL, 0x9A56DAD883C6FD33ULL, 0xC2DC525FC5AC243EULL, 0xC5B1004E8EA266F1ULL, 
            0x244E0E902C28C203ULL, 0x4AF3DAFAB5B5728FULL, 0x61D5C28F350B108FULL, 0x6C809C038C30F067ULL, 
            0xB9AD2CF1A9A564E9ULL, 0x9CC8D7099917AF00ULL, 0x4E9B88111AC17D79ULL, 0xAD8C71881590BD94ULL, 
            0x7DCC97595196AB4BULL, 0x5EF64411D61CE5EDULL, 0x8A7B76BB3A54421CULL, 0x70E0C6587477755BULL, 
            0x3C7D467B8D028773ULL, 0x8432D78689C57513ULL, 0xF8E689466AA46C7DULL, 0x83672266AF15F0C5ULL
        },
        {
            0xCAA71C5AA54FAB6BULL, 0xAF238B8B7DB98A23ULL, 0xCDE47D08CB0E85A2ULL, 0x1003380B63EA2FBBULL, 
            0xBAC4499CB18308F8ULL, 0xCFFDD933B47268CFULL, 0x520AD09E628DE96BULL, 0x551E3EB031BD7BDEULL, 
            0x1BF3DC743FD01832ULL, 0x72643087309DB87CULL, 0xAC75A05568F1E578ULL, 0x06CA7608AF26487AULL, 
            0x739A443A15DE16BBULL, 0x9D1962F33C943C7FULL, 0x0D2D384A5220B3D9ULL, 0xF9E7714C07E2B80AULL, 
            0x11B3638DE74A05E6ULL, 0x031C1C7483CD0F49ULL, 0x8E4669BE1DD24DAFULL, 0xF4BA8A79CF633C5CULL, 
            0x3CCF1690F6CA8C97ULL, 0xBAB7910635384905ULL, 0x07E9AF7A05463BFAULL, 0x8116FA189202D9D0ULL, 
            0x82C716C591984E38ULL, 0x221B23FBE1E2451AULL, 0x18A73124DCE21845ULL, 0x69B174B73775AEB1ULL, 
            0x24F6BFE1871BC978ULL, 0xBC7439767E5F5B11ULL, 0xC2CDC17B5652472EULL, 0x5F4D6EE3B9636C48ULL
        },
        {
            0x44A53009BDB2598DULL, 0x133B418963B15BD0ULL, 0xD6759787DE87714CULL, 0xC6D74E807EEDC87BULL, 
            0x26E195546720C3B6ULL, 0x3760B681A46ED934ULL, 0xAA3E8A5F78C00C39ULL, 0xB509FECBA8E2F8EBULL, 
            0x5837C1DDFF3FB5CCULL, 0xA22C07C320A18751ULL, 0x2A4424607259A737ULL, 0x44F7712CA4B43F0FULL, 
            0xF6DEB078C773ECB5ULL, 0x6D0F3BDC4CF70BE1ULL, 0xC8E67B2BBB137D78ULL, 0x0956F43D5BF0DE5FULL, 
            0xA00D39FFD94AF410ULL, 0x7664B84E23C3C2AAULL, 0x8293B86665979175ULL, 0x260CE21261DACFFBULL, 
            0xD83CEB1603ED07DDULL, 0x6A484A8D1C82FAF8ULL, 0x0DCF13C7E8C37F30ULL, 0xFD9EB0547A92DBE5ULL, 
            0x8CA169261DB72E81ULL, 0xE6A948A785F2AC04ULL, 0x0F5FFEF0AD27E947ULL, 0xABD286018CEEC0C2ULL, 
            0xF27896A5A38A74F6ULL, 0x136FF749C52A63ABULL, 0x181FB7AF541D39E8ULL, 0x508BF335D6C2AF7FULL
        },
        {
            0xC29F8FF6B9DCBE8FULL, 0x873DCF828B58C920ULL, 0x7E53D58CB54AA5BEULL, 0x458A9CFDE85E7129ULL, 
            0xF7A20A92E78AE124ULL, 0x1864606ED982F0ACULL, 0xA543DF6BD375DE61ULL, 0x9CBB9099A26708CFULL, 
            0xFA2D221060EC2931ULL, 0x5DF608ADEEED2DA2ULL, 0x3C494C4DE14E9D2BULL, 0x1077B328248171A3ULL, 
            0xE1B49CE4513E71CDULL, 0xC6D1135E1226FF52ULL, 0xB5673732C442E52FULL, 0x5D7A0F347C295F9EULL, 
            0x37F2A16942B0DF87ULL, 0x27FB37962B857611ULL, 0xCBE99BFCD367BD9FULL, 0x8DB5212316FCF3ACULL, 
            0xBCC4413D10749746ULL, 0x1BEC39EB8437E1E8ULL, 0x6A177EA8416B36D8ULL, 0x5DB0A41023AD813AULL, 
            0x33E8C44D8C6F52A2ULL, 0xF79CD5F1541E5765ULL, 0x4E87A54E47E941CCULL, 0x8ADA789C2AE129F4ULL, 
            0xE3EC10F9187499E9ULL, 0xD84B0E6C80920072ULL, 0x913DAEE845387507ULL, 0x43BCD1C9DEA8B0DFULL
        },
        {
            0xB4C6012718BD4A4CULL, 0x1CCA4F236CBDB056ULL, 0x4D194EB560A8AE74ULL, 0xDBFD263850819237ULL, 
            0x47C64CBDE67343A5ULL, 0x048324B1EF15C76BULL, 0xA818445451F76C90ULL, 0x49EEA74559A6AC59ULL, 
            0xC370D1ED0B3D5630ULL, 0x2A6CD9B3E0BD8BB8ULL, 0x66F6D66DEDE25792ULL, 0x5252D835D8F9F1BDULL, 
            0x82E196D0DBE7AFE2ULL, 0xDA2DBB27810E9C0BULL, 0x0E9FF253C616AFCCULL, 0xE9F78BD46805B20BULL, 
            0x2A0580B885F4138AULL, 0x240F8152537C14D8ULL, 0x00D601025B76FA83ULL, 0x18F56CB24F680E74ULL, 
            0x585131E075A76210ULL, 0xA68F75E748C03301ULL, 0xB7AFA0C960FFBE79ULL, 0x14DC4F9E1339A376ULL, 
            0xBDC115F96318D31DULL, 0xF139C33BEFA87C55ULL, 0x57845CEFD275BC2AULL, 0xA6B93443997AA791ULL, 
            0xD617C309A18A9D6AULL, 0x14FEBF70A38CAD13ULL, 0xFFD622BAA5E8F389ULL, 0x6E865979FB306F7AULL
        },
        {
            0x09C5AEAB0C69C23DULL, 0xE499F3F12406EC8FULL, 0x162CB291E176580BULL, 0x87EAB1E6BC920BAAULL, 
            0x92EDD58E760B7795ULL, 0x7659573EB85DFF2CULL, 0x821F72A7CA8EA677ULL, 0x03DE6FE8D8C93FE1ULL, 
            0xD0AF595C926CBDD0ULL, 0x4F8EDB742F1152F5ULL, 0x4A3709AFB3C157CCULL, 0x45EA82969787AB9FULL, 
            0xE149B978A27D70F6ULL, 0x22590B2F0180E0B8ULL, 0x7AE72BB1BD665733ULL, 0xA4AFB0B1DEC23797ULL, 
            0x26E48518D04B86D0ULL, 0x4B8D8134543495E7ULL, 0x9EC3FEF2403F9649ULL, 0xD924C4FFA4EFB11AULL, 
            0x46D99BD6092EFEF7ULL, 0x12C7B9B41EF351FFULL, 0x36754DE2789A8D42ULL, 0xB1B88893872773F0ULL, 
            0x4750099C47CF94E0ULL, 0x0C60FFBB4A25E295ULL, 0x9D9A1AB7AEF22E89ULL, 0x47DA2F04D240D831ULL, 
            0xBBB442A4CD6A0AE4ULL, 0xC2B8532F89397779ULL, 0xCA19ED836B10DF8EULL, 0x344751BC2E12090FULL
        }
    },
    {
        {
            0x75A4D2572AFCEE8EULL, 0x97AEC151DBE976F8ULL, 0x2EA7903D9625FC63ULL, 0x405847C177F839E3ULL, 
            0x0CBF02283A948742ULL, 0xAC82C2DA7C0AC99DULL, 0x5FD4736E47A1BCF4ULL, 0x2AAAEC5E04F2A6B9ULL, 
            0x9B2234274C18B2C4ULL, 0x2FB7FB9B8DD92445ULL, 0xA55D13CD51ED10A5ULL, 0x3E0173534898CDE3ULL, 
            0x7C483EF043DB7E69ULL, 0xC5E9C72B9BE5C783ULL, 0xBC54E05C51BAE961ULL, 0xAA4FCDBC8F6F5369ULL, 
            0xDFD41C90A00FADC3ULL, 0x8F17DCA1930DCFEAULL, 0xA93DAB1386AEA314ULL, 0x334A788D1515DC46ULL, 
            0x945BEAC1DCA3E095ULL, 0x3EBD8B662F2CD76EULL, 0x0878764FD06325F9ULL, 0xA4AA95DDD0875631ULL, 
            0x7F75E21854D5A5A6ULL, 0x98E128780B21CA97ULL, 0x37FBD0D4855644BBULL, 0xFA3F9D4EBB291F7CULL, 
            0xAD8DD97A14AC6055ULL, 0x72A4EDF3489F8692ULL, 0xB0DCE1C199F606E9ULL, 0x556C6C99D199DD04ULL
        },
        {
            0xC1865F1A69C9B916ULL, 0x44E87D69F5E48A9BULL, 0x8869936C62EC9DB0ULL, 0xC5A27E05C4506C96ULL, 
            0x7CA101664DE7C369ULL, 0x86D996B18AA9153AULL, 0x099CF7FF6276EEF2ULL, 0x42D56A5AF31A2488ULL, 
            0x45941BA22428D45DULL, 0x0ECCD402D7FE4547ULL, 0xEDF909B683DC7C73ULL, 0x02EE19532D9F6000ULL, 
            0x38359C1772A2AEB9ULL, 0x0B6F4220850D959EULL, 0x0876F754117AEC76ULL, 0xF83938E12072858CULL, 
            0xE0CD0E8323024CE4ULL, 0x983BDBF3A2B44C89ULL, 0xB0746CE20FDC0ED0ULL, 0x69CF17A0E9440F3FULL, 
            0xCB603FE1615F576AULL, 0x848F1C25626A4356ULL, 0xD9EB034B75547FF0ULL, 0xBCDA044715660AD6ULL, 
            0xF9730A8E52A7A95EULL, 0xB19107351D12EA83ULL, 0xB2B0AADA173DEF2FULL, 0xC144E022FA35B71BULL, 
            0xC030811D46C19E3CULL, 0xCE6D16A4C7C05B48ULL, 0x62555DF5065B17B3ULL, 0xF79C6078893590D2ULL
        },
        {
            0x6670E6FDA6B4F39EULL, 0x25CC93F18A865DE7ULL, 0xE17A28E99AD51758ULL, 0xF36C5DAFB61332E0ULL, 
            0x20F9712CB5187D70ULL, 0x521546334996EB1CULL, 0x837F3E0B6C34D1C6ULL, 0x016AD50E87294F69ULL, 
            0x68B6EC58CAC4B568ULL, 0x20183E114741101DULL, 0xEBD62B69F3A167ACULL, 0x89BAF83BA97E53F1ULL, 
            0x9E6C2B1E330EC255ULL, 0x647ADC20F7B9199CULL, 0x1AFDD32DADF352DEULL, 0x6988A4F0B34E68BAULL, 
            0x001132B5D9277138ULL, 0xDAB6E78ECCDF69E7ULL, 0x40EAEABCEA46049EULL, 0x4581FE07BEF2E46AULL, 
            0x8A9A2C420FA3C036ULL, 0xB7695D7C5F1D1EFAULL, 0x5F89A538909516C2ULL, 0x006AA055376E4E48ULL, 
            0xAB5301B8B180AA52ULL, 0xF658606066FCEA5BULL, 0x1C73F8A5B4B01C02ULL, 0x75B511B496BBC57FULL, 
            0x2036EA8A036D345EULL, 0x313613E202B34EDAULL, 0x511E0E118F79FFA9ULL, 0x7BAC4EA7E1D216FAULL
        },
        {
            0xACEE855AB4C62113ULL, 0x6DE4328EF31D3E76ULL, 0x4A201ABDBF7EB1BBULL, 0x3F292755777DC87EULL, 
            0x34595725AC2CA5D8ULL, 0x09B8D2863AE09589ULL, 0xE5D9A442D4FAF428ULL, 0xD6E289FD21F6684CULL, 
            0xFB8AEB32FB4C73B9ULL, 0x46C5038C64F466E2ULL, 0x875A2C4958687CBFULL, 0x2FC204BF67941322ULL, 
            0x6F640C87FE6F0696ULL, 0x27CA6F88227A9DABULL, 0xBD5104DAD7D82FEFULL, 0x51C37B38DCF2E81AULL, 
            0x3DD7C85711B6675EULL, 0x74E14F6249CB1BF7ULL, 0x47A0B9EEF8928E38ULL, 0x852907262BF45BF6ULL, 
            0xB363E2788C163426ULL, 0x6DD8717D2B8C1DAAULL, 0xF53B752475F6EC2BULL, 0xD4B122594CE1DA8BULL, 
            0x7A0093FA7C88C24CULL, 0x1B17E85A5FD2080EULL, 0xD129D66CB35C8986ULL, 0xFEFAFAA4D255BC3EULL, 
            0x02A3A9E62F56BBD0ULL, 0xA0DF9A6ABE45A839ULL, 0xE0C4209517D91D4BULL, 0x5E1E784BC8239AEAULL
        },
        {
            0xFFB11B84FF5D1912ULL, 0xAAA7A2219B893891ULL, 0x73C0005CD686B53DULL, 0x2521F7E45A01265FULL, 
            0x3F48AFC2F0C0214AULL, 0xF3FB1E9FF02D7589ULL, 0x24242094A8118C73ULL, 0x9460460E0EA817D7ULL, 
            0xA02FA35E1B4C9346ULL, 0x9FA0B47ACA360918ULL, 0x89F0906CDD4FD21AULL, 0x7FBF03296E1C730DULL, 
            0x33DAF9C6E7F4111BULL, 0x7438DB4376F794DEULL, 0xB892286961D7471FULL, 0x5D825D04F1F90E93ULL, 
            0xF0C4B3C634817184ULL, 0x3DA85CF610857C92ULL, 0xE196D242F1B3FB02ULL, 0xC040E19225F78BB9ULL, 
            0x41164A5C7DDD3299ULL, 0x284ED857B73D4023ULL, 0x4CD37336F7466918ULL, 0x339A2AE4CB0EFAB2ULL, 
            0x2BC5E60760A7008BULL, 0xEFB86D7BD3C586B3ULL, 0xF51252F5C261C56BULL, 0x31F8E37A467C1F5AULL, 
            0xFC3DED5DAD7012CFULL, 0xEF8B5E48020AA63EULL, 0xF3B53E426A551EABULL, 0x261347E319112F89ULL
        },
        {
            0xE42DD33BC53E5622ULL, 0xDF4D3F5CF4872DE7ULL, 0xB6C7526B12F004C7ULL, 0x7B09C412E3D42CB9ULL, 
            0xA8BFFE051D611FEBULL, 0xF6DAF8C9007CDECAULL, 0xD9291C208BAEAFE1ULL, 0x7B652B490B467302ULL, 
            0x9FDA48B71CACA5B4ULL, 0x7A0AB1A8FEC4ED1AULL, 0x0559CE04D154A71DULL, 0x98694EEA8BFC08E9ULL, 
            0x072D15536B864790ULL, 0x2B2B7A48DD4EA384ULL, 0xD1FE3EBEF64B90BCULL, 0x7C65BD41C9F9FEF3ULL, 
            0x1ED5F46FCA171627ULL, 0x8485FD71D06392D6ULL, 0x0D5906CA8EC17B27ULL, 0x013BDDAAA302D630ULL, 
            0x3B8B0E0D9ECE102EULL, 0x1F537BAC3C637012ULL, 0xE3D8F67B804366B4ULL, 0x576031709C0DBF9BULL, 
            0xFD722437F720D28CULL, 0x63561AC9DD979E8AULL, 0xF2702457750B98BBULL, 0x56F2A631305F7C4DULL, 
            0xEEE7C9E3DC4153CCULL, 0x576625D6E083BA6FULL, 0xE08E84560635EF5CULL, 0xA02870B22A03BA9AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Canopus::kPhaseCConstants = {
    0xA7C4410CB5B780A5ULL,
    0x6E98090A824604BAULL,
    0xA72F2F15394944E6ULL,
    0xA7C4410CB5B780A5ULL,
    0x6E98090A824604BAULL,
    0xA72F2F15394944E6ULL,
    0x7E8ECB6360560C16ULL,
    0x2EF473101956D6A2ULL,
    0xAC,
    0x8D,
    0xEB,
    0xB3,
    0xA7,
    0xCF,
    0x06,
    0xFB
};

const TwistDomainSaltSet TwistExpander_Canopus::kPhaseDSalts = {
    {
        {
            0x7972C2C6B46D1C1DULL, 0x7D8673FBF8CCE72BULL, 0xC6EE9B1071EF6CA2ULL, 0xE9539B86F43980CCULL, 
            0xB6CDD2CA527BF4A4ULL, 0x325B3086714F318FULL, 0x8662A7E41475B2BAULL, 0x92E7562CFDBF32A2ULL, 
            0x563D43BD4098FBC3ULL, 0xAAF8091360AACA9FULL, 0xB0211293D62C531FULL, 0x508595F9E15DFF22ULL, 
            0xDC1B3FCED760D9FDULL, 0x841DCC81093981CCULL, 0x73F67178B37DBB96ULL, 0xA158EA9C5CCE2293ULL, 
            0x637FACE34EEA7BA1ULL, 0x7209796B2B569ECEULL, 0x3C24E4D1D9A30544ULL, 0xA09C6FF7E08DFAFCULL, 
            0x75D8E8A8998FD421ULL, 0xB00CCD2C0FA8FDA3ULL, 0x1F7BC2195B568F4EULL, 0x447E6B6A05E50144ULL, 
            0xD366B430D8C5CE61ULL, 0x6AB4EBA6EDEC9E52ULL, 0x709ED6F32F09B387ULL, 0x1976E84AFE6D111FULL, 
            0xE73CD0B7BCF3E54DULL, 0xB513E90F3EAEC064ULL, 0x2D6FB9B6EDC08FD0ULL, 0x079032CC61DE47F0ULL
        },
        {
            0xE580C002A3D4B746ULL, 0x1D046404F6E94BC3ULL, 0x5DC01D0750851DB9ULL, 0xC0426CA5CED690CDULL, 
            0x4FAAAB36C4027C80ULL, 0xB5DC9BE4CB30B461ULL, 0x8A82121AFFB9B386ULL, 0xAD5B9FDE57952862ULL, 
            0x04A8FDFFA60A75E4ULL, 0xB7DB147F12D34DF8ULL, 0x244BE4A3BD5D4C1BULL, 0x4B8203594A6E7021ULL, 
            0x2C5E1302E5ABF236ULL, 0x9C01731DAFE489D4ULL, 0xEDF12F09767C7B3AULL, 0xC76436A58CB9B2E8ULL, 
            0x63B185148F6B6C90ULL, 0xDF417FBF63A27DE4ULL, 0x03C27C2DEB9C0558ULL, 0x2C9C9FBC66384660ULL, 
            0x0F81504D122C5FFCULL, 0xA7B5780538E0EA13ULL, 0x4DBE3C71F8205C54ULL, 0x0308102935DF62ABULL, 
            0x79962B25920C62BBULL, 0x32DFCD1B45B6974AULL, 0x0717B93CF4D4F5EDULL, 0x3BE5F5B6BF7B1202ULL, 
            0x1756705320E6182FULL, 0xB883D5F29CA262CCULL, 0x81975BD05FC54E16ULL, 0x5E6B218D1F8060ADULL
        },
        {
            0xDFAD53C26051B800ULL, 0xEE890F930D3EB530ULL, 0x881CFB3DA4E22EFCULL, 0xB0AD60D5F93FFD53ULL, 
            0x5B66D85628230E77ULL, 0x18AC289BC64CD73CULL, 0x4AB47899F3DE3AA8ULL, 0x80533EBEFCFCECC8ULL, 
            0xF8A810B44E2CF8C3ULL, 0x7C404F17A4A16256ULL, 0xAD0F2499B3881ADEULL, 0x2C4BEA185D51F2D8ULL, 
            0x63918CBD1024C903ULL, 0xFB9D623A8EC713EFULL, 0xD91BF2C907F753D3ULL, 0xFDBAEEF084E7C27EULL, 
            0xB0755220F8A5736FULL, 0xA375C9D254AB92EFULL, 0x56090EC8255F43C2ULL, 0x701316D0564F912FULL, 
            0x932D0462EE80D80DULL, 0x45E473C686053229ULL, 0x6A74D512B591ECDEULL, 0x7BC19B678C8DF8C5ULL, 
            0xEA61E359508DF558ULL, 0xDDAA85874C4DA170ULL, 0xB05B1DAB8EBC2DFBULL, 0x7E362E477900C419ULL, 
            0xA2AFBCB624223B0CULL, 0x649E63195111CF77ULL, 0xCBA177E540CCBCC4ULL, 0xAB8DF75FD64C091EULL
        },
        {
            0x2742920F274AF596ULL, 0x8E74920948075BF8ULL, 0x292A9A04D7AFB79AULL, 0xB67AF02EF58F1F26ULL, 
            0x50E6FFD6334038CCULL, 0xB71C6259DADD6C82ULL, 0x6D9E1F8861F3AEA1ULL, 0x2E39931527832D0FULL, 
            0x09A29180BD272258ULL, 0x926400DF5AAE0217ULL, 0x7249916D2F58D329ULL, 0xADE088B0B5303969ULL, 
            0xC1C51B803BED87FAULL, 0x75402634D1607164ULL, 0xCFF28EFBD6516E2BULL, 0x63FF9AF296ECED77ULL, 
            0x50E03B65905170ECULL, 0xF9FBD9448AAF42D1ULL, 0x8C43E7332D515B38ULL, 0x25B6CC884D67CA49ULL, 
            0x5D4E4003C543557DULL, 0x615B3155DB96D44AULL, 0xDA880B562AC06912ULL, 0x672EC1AC231012C1ULL, 
            0x9AD8D67B03885231ULL, 0x670A9F50FA8E98A3ULL, 0xDFB507A011488842ULL, 0x6C22B16272EEF16BULL, 
            0xBA9CA6F3FA82DEA6ULL, 0xEF7634C8D78C4C9CULL, 0x61FE9888743C2643ULL, 0xE69638EE727F1542ULL
        },
        {
            0xF2284DE750EAE0D6ULL, 0xC4EB8EFCA38C89CDULL, 0x91DD5D4D786B303AULL, 0xE24FA91DDD8D9330ULL, 
            0x1316227DBEB97B6AULL, 0x03734DC2CEDE4BEDULL, 0xDA1126991035ED1EULL, 0x35CA334D8764B549ULL, 
            0x66D05F3835BE5CA0ULL, 0x80BC573A87CD33EDULL, 0xDC8631FDE0BC22EBULL, 0x41A5012CEB4945DFULL, 
            0xFB90702DFD955949ULL, 0xB79956F1670307EFULL, 0x725C2D8225D8A71CULL, 0x1C685EE6B97F9E7BULL, 
            0x3C0729F272B95525ULL, 0x0B89EBB20F98F767ULL, 0x58F4A600F860088FULL, 0x01FAF63B769DD95DULL, 
            0xF622B30364B41327ULL, 0x944455EBEA45E7F7ULL, 0xFA46CBC969E76A1BULL, 0x30178A0669EBE2CEULL, 
            0xE45CF1E88FD66027ULL, 0x682A575BA015946AULL, 0x6AF71F17768BD559ULL, 0xF0A2C86231FC3035ULL, 
            0xB11ECE8E3558D023ULL, 0x038B79BE8ACB020EULL, 0x417C8C3891E166BEULL, 0xAFA26EF9420B4BEEULL
        },
        {
            0x9106C26B487E2450ULL, 0x189A27B17F637902ULL, 0x48D666FAEDA00B05ULL, 0x2B2337C8FD6AA9D7ULL, 
            0xBA33610E4488EC10ULL, 0xDA20E237A37D41E1ULL, 0xDB3CEAFF648CA6BDULL, 0xAC617A7A7BA4F349ULL, 
            0x668A6C46242F42E1ULL, 0xE247921F6E6DFE5EULL, 0x1FD2763C004D6AC3ULL, 0x8CDA966611C8218CULL, 
            0xCB0E9DCBDFDCA4DDULL, 0xFC4582C8FC071F31ULL, 0xC71EF9BAA19F68DDULL, 0xEAEEB21D80B62277ULL, 
            0x007CDF4BC35C1072ULL, 0x8F47A01E3CC191FBULL, 0xCC6E4428957EE02BULL, 0xEEDCD2A52C3CC311ULL, 
            0x93510065DD505C49ULL, 0x7C55487CC0685B88ULL, 0x4CD1E412CA298C8EULL, 0x119DA404C45C4DE7ULL, 
            0x224BFEE11AA4B297ULL, 0x773D521444FC2024ULL, 0x9BEA787DB23A59E4ULL, 0x32F90318B1E87ECBULL, 
            0x76811A0A4DF263DCULL, 0x5578719AB1DF27A0ULL, 0x21477A639EE13DF6ULL, 0xEE0427F684E7023EULL
        }
    },
    {
        {
            0xB71EC895C98B4861ULL, 0xB522627C5696B7F0ULL, 0x6AA503DA0657CDC3ULL, 0xBB460E5303DF8CE7ULL, 
            0x410F8A981FBD672BULL, 0xFFDA5F7110CC7E8CULL, 0x7A51F85A571E7B7BULL, 0x5C3736583B9AF8CCULL, 
            0x72EAFABF074730FCULL, 0xCE3649B278540C80ULL, 0xA5A96439ACA6EE6AULL, 0x38FFEE5E3FA881D9ULL, 
            0x4B1A0CF89EBD9DF0ULL, 0x6A8BD014CC4204CCULL, 0x8DAA2FB52DAE1379ULL, 0x7E53E9DF419744FCULL, 
            0x6DD14A9B7860AAC4ULL, 0x6575FE2D8DBC51C2ULL, 0xDE40EDDB9E380134ULL, 0x044E694371BAB7EDULL, 
            0x56A3C95A3098692CULL, 0x8FD8AF5B29D3A93CULL, 0xC368C190A861009AULL, 0x4B61EB523EB47237ULL, 
            0x3A4090650B4F1F5CULL, 0xCA7F475F43CE4290ULL, 0xB9B32980E20E4025ULL, 0x8763CEEF52DC637AULL, 
            0x2DDF5607B482717FULL, 0x25B6016E3CCD5BF1ULL, 0xFBB375C86EC04016ULL, 0x8684E47964FA3CA0ULL
        },
        {
            0xB8AA2C58C739690CULL, 0xAA61301C7B09F94DULL, 0xB41882E2AF447A66ULL, 0xF490DEED8AC42B94ULL, 
            0x76366502445546D6ULL, 0x6F06CAD4C5F88118ULL, 0x58EACFD7B2525087ULL, 0x74E16353F584BF4AULL, 
            0x0FFC252C40213207ULL, 0xE7A8975E415DD2B2ULL, 0xD936B90FC98A2FB9ULL, 0xE59215E265FB96F4ULL, 
            0x9656F10009BAFC8EULL, 0x26373867951988D7ULL, 0xF1EE808BE1F9CB0BULL, 0x5AF7EDEB50C23F65ULL, 
            0x887D9929F114B4B1ULL, 0x82EABD5DFE0479ABULL, 0xB5B050C366FC6923ULL, 0xE874A74124CD5074ULL, 
            0xC71B86C848410A31ULL, 0x2BD13E4272A283A3ULL, 0xA60E38C877EEEDB8ULL, 0x04B2B1A72CD274E5ULL, 
            0x7306FA87995E97FCULL, 0x2FCE37F13F4511AFULL, 0xA28797E5A8AC1381ULL, 0xAFCCE612282462ADULL, 
            0xA8B0B85E444253B6ULL, 0x9D60C5C562BEFA19ULL, 0x8B18B9D0EBDED495ULL, 0x23D8EB51155E296CULL
        },
        {
            0x94932087E2267DE1ULL, 0x1FF68A3B0C40B860ULL, 0xF5592964F5C256D6ULL, 0xACE7B2930D317BF4ULL, 
            0x8349E2A36D560645ULL, 0xD945013F0E261879ULL, 0x381B00A3FFDAD0F8ULL, 0xAEEC404E5245BED5ULL, 
            0x4FFCBB3C7F1183E5ULL, 0xFEA54A8FCE1C6AE0ULL, 0x66DDAA1845F50AC7ULL, 0xE4027ABB25DDAC47ULL, 
            0xCB76FC9E96A4BBDBULL, 0x9BD8EF99761132D2ULL, 0x1656931B62357479ULL, 0xAEE17AB3FD894E33ULL, 
            0x7F240D6B29BFFBD1ULL, 0x5D9C7A02E1036E63ULL, 0x17E79DD1ABF6C3B4ULL, 0x2E03EA6704B0D237ULL, 
            0x03B9998941A8F4ACULL, 0x59D431B948317D29ULL, 0x2478A70EE3B06978ULL, 0x2712386FBA04CE37ULL, 
            0xA39297F169740E8BULL, 0xFB666C8029190D3CULL, 0xE08C2A5EFF4FA176ULL, 0x7EB74506B5085D17ULL, 
            0xDBB1ABCCB05A7805ULL, 0x7A05551D1BAFACE8ULL, 0xC9FB18243C62A18AULL, 0xF96D550E6F9F0FCCULL
        },
        {
            0x0948C4AC579B2876ULL, 0x93F37396F745A12CULL, 0xC272943F83F83F16ULL, 0xCE7ABD7F8A529450ULL, 
            0xA0967573110FEA48ULL, 0x2640ACA802EE0EA0ULL, 0xF7060444EC7EACDAULL, 0x2A29FB6A0E6671CEULL, 
            0x3FADA3D3E8558B62ULL, 0x183D56060C16EB79ULL, 0x308761B97216416EULL, 0xB6D6F0EBC4A367C0ULL, 
            0xE4C2E76C031B72DFULL, 0xABF2BE481E7E5DB7ULL, 0x8D3016765A92B93CULL, 0x4CA384216733BE99ULL, 
            0x1427D8AD846B9A41ULL, 0xC068EEE2F0617B09ULL, 0xC000300DB2715A7CULL, 0xDE7BA88A8C160B58ULL, 
            0x380C9A54FCCB7E75ULL, 0x25B6599F061D22C8ULL, 0xCE920A86327566A7ULL, 0x401AC545947E1A08ULL, 
            0xF50E1723E51952EFULL, 0x3C7222FEE0ACF96DULL, 0x5DDE4DC25C24DE3EULL, 0x1C149A81A6E1EF6CULL, 
            0x61B626778C852F04ULL, 0xCEE2C130FBCCA68FULL, 0xC004FE1E1433F280ULL, 0x7A3BAE36F2229EAFULL
        },
        {
            0x0FD46C5C5234917CULL, 0x11F097BB96ABAFD1ULL, 0x101E9A21F3C16E24ULL, 0x3F982657686C8986ULL, 
            0x9F55FB93398CD8CFULL, 0x4085CAEC5F10D36FULL, 0x06B476EF6DAEA7E3ULL, 0xC93CE906DEBDD8D4ULL, 
            0x6678BD45CA99954BULL, 0x8D47EE36723E89A9ULL, 0x06ECE376ADA80875ULL, 0xF2A65E69B8F59F27ULL, 
            0xE241B4CE13D0C2CDULL, 0xE9699F964FDB6749ULL, 0xF2180825EDE13ADFULL, 0xBB09D2DB1D0B956FULL, 
            0xA0219A842DA30004ULL, 0xF0E597EAE303A777ULL, 0x6052D3C07ADE06C0ULL, 0xB5299F31EBCEF47AULL, 
            0x34F30EFE5276663AULL, 0x18263A112045F0F9ULL, 0x2E9DC6C6F33344DEULL, 0xC436C95C76B648DFULL, 
            0x98E4721AC79E05A1ULL, 0x5A9F49238F1C6076ULL, 0x1EE9339C054FF05BULL, 0x1E78824A62B07912ULL, 
            0x350A3EDF49F21A0CULL, 0x9A597DEA61576FF0ULL, 0xAE195BAD3B9066B5ULL, 0xC8803D6E913B01F6ULL
        },
        {
            0x6900ED337ECA6949ULL, 0x78CF24D60F0DF9FBULL, 0xC79D7AF6F56023CEULL, 0x06CCC84666C7D856ULL, 
            0x0D390B9A7FFD5504ULL, 0xC8772794E33213E7ULL, 0xBFE47D007423293AULL, 0x44734A4DB04A43A0ULL, 
            0x95585532F13147DDULL, 0x0D313533DB998BC8ULL, 0x411391B86E6DADB3ULL, 0xFCEDFD5C0EC3F203ULL, 
            0x4523F72BAD67DA18ULL, 0x8C60F24C3EEF96D9ULL, 0xA2FAD2F64AF05ACCULL, 0xB776155F8C4167DAULL, 
            0x9717EF8A76DB8AA7ULL, 0x955C0BAC43C1B9A9ULL, 0x99C00BC29F3C6A14ULL, 0x813D4289B2B4A9DAULL, 
            0x3559A3D9F6737273ULL, 0xD445F50B70978D9FULL, 0x4207902D6BA1CCBEULL, 0xA986292FD272914EULL, 
            0xBADCD107D4D90467ULL, 0xBC3A0753884C79A2ULL, 0xD1A1C06DF0AD04B1ULL, 0x30D212DDB23D2D34ULL, 
            0x8333CD19A5A97089ULL, 0x81AE843E68013E58ULL, 0xACEA4770C315C79EULL, 0x5163A4A7BAC262D0ULL
        }
    },
    {
        {
            0x41BB3225B78DDFABULL, 0x3E4CAF51C247DC1CULL, 0x88CD232133C8C891ULL, 0x76B6D63318AC481CULL, 
            0x97ECD4444560820DULL, 0xAB863736EB6C13DBULL, 0x6A6B66148D000D55ULL, 0x93F4C4A0055EA04FULL, 
            0xC6E3004FE3FCACC3ULL, 0x1E7C5D9F5C71A8A2ULL, 0x9F894D355B115B04ULL, 0x30896BD2B0F1A4F3ULL, 
            0xBB8BBC62E7ECE7AEULL, 0x7FA5B11484A91E21ULL, 0x8591C7E50D621CC8ULL, 0x8CFE62A680E05E03ULL, 
            0x9FE598A593D06EC8ULL, 0x7FD7CD025674DAF4ULL, 0x130883461F82375DULL, 0xB2BF69CE5E1142CCULL, 
            0x9C859E7916BD2D47ULL, 0x187DC9BA26DC73A2ULL, 0x3F2D83BF9D66CD12ULL, 0x5C48C7DBBB0663F5ULL, 
            0xA011E78DF02C6F51ULL, 0x6FE948766260F4F3ULL, 0x1D4B655864244DB7ULL, 0x7DADF4DC6D508F12ULL, 
            0x198E724E435AD610ULL, 0xE9E5FA816A63F1DEULL, 0x5055E25FCD9779A7ULL, 0x177F06DAEA9EE1E0ULL
        },
        {
            0x2FD822185E9B8C60ULL, 0xB3050E34C0868677ULL, 0x98D027CB517191D6ULL, 0xE23911F8148CC594ULL, 
            0x0620AFA9A02FC2BDULL, 0x329FE6E5B46037FAULL, 0x4E00F05F5F422510ULL, 0x331A0D4C5F073840ULL, 
            0x490E51314CED2315ULL, 0xC8F1C363C2E4AAB1ULL, 0xD9AD020549B74448ULL, 0xF3BC31FBC71CA6BEULL, 
            0x780938479D0EAEAAULL, 0x89B00D8A9F15FFBDULL, 0xB12ED9840B6735FCULL, 0x5F33C02D2FD2FE63ULL, 
            0x23480C69EB18AC7FULL, 0xBBBCE8A1A15A39A4ULL, 0x6FC49EC40191DA61ULL, 0xFA283888F7DA5DECULL, 
            0x5AF8404EE619DE9CULL, 0x913B8B159CF2D637ULL, 0xC10E9D3EFE9DAE17ULL, 0x5C3CCBF27C128EA1ULL, 
            0x2F55025382805322ULL, 0x9233CDAA1531F936ULL, 0x20F3E357F6445E64ULL, 0xEB4F5E3370B0F40AULL, 
            0x6A08B369035538DEULL, 0x4360E57816864A26ULL, 0xA698A5443368519FULL, 0x46FB425B039C3457ULL
        },
        {
            0xADE3B4314E4652C9ULL, 0x4A2F9F3AC08FE74DULL, 0x0E9D92C3B6B22265ULL, 0x9232D94DCE9FC5D4ULL, 
            0xCE07AF8617C86949ULL, 0x3F3B7E2589ADDD43ULL, 0xE2EDA02F36320210ULL, 0xC28411C5597BF17BULL, 
            0x18D4BF9B5B836185ULL, 0xC1BCBF2643A716EFULL, 0xA487E36050321F29ULL, 0x7DE1F3B655EE18EDULL, 
            0x2BBEFD5605469517ULL, 0x3C2AEB68F22AAB88ULL, 0x758C3E92DF043FE8ULL, 0x4A4F26283E1A1C14ULL, 
            0xBD8CA9416A42F5EAULL, 0x699CAA689103D0B5ULL, 0x2DA95AFB7330BB8DULL, 0x7C60F19471720CECULL, 
            0xD0FA4D0FFAE26652ULL, 0x5B6AA76FCAD54B74ULL, 0x2B9F8BDA18613732ULL, 0x79591CC54A080F3CULL, 
            0x5BAFFA1337025E6AULL, 0xCCD7716694EE471BULL, 0xA013CE9EC994CAF0ULL, 0x5BE8790BEB944164ULL, 
            0x8FE0E872D9BA9096ULL, 0xA9525A248ADFCE90ULL, 0x28A2323A1D2C26C2ULL, 0x249902D7C15EF540ULL
        },
        {
            0x4FC4C12FDAA1D362ULL, 0xB4CE34F5C13E10EAULL, 0xE9B5B454AD5E392DULL, 0xBF0C377782EC7382ULL, 
            0xC2AB138E3F2FA5A4ULL, 0xB77BCF85080C400DULL, 0xF9D4674661961864ULL, 0xCD4C1AE456D0A259ULL, 
            0xD0D5574CA539AA4AULL, 0x0080935A5BEA51DCULL, 0x8E5F854781E9AD13ULL, 0xA4248DF91CE0ED7DULL, 
            0x1F5513481591287AULL, 0xD5480B7DFAC89559ULL, 0x2D621C119708CFF8ULL, 0x837C735F6B74D1D7ULL, 
            0xAEBF0C08C7275EF0ULL, 0xC695403DD79B09DDULL, 0x133CF916E696420AULL, 0x7B84630CFBB0E233ULL, 
            0xEE2064DD8DE86466ULL, 0x7C8676960BF1ADD7ULL, 0x1F95C5AB8E3F7320ULL, 0x6516205C9496F25EULL, 
            0x7D15D885EEFB9EB7ULL, 0xF764295243F9B6CEULL, 0xC2D1E6DCEEF9CAD9ULL, 0x3F91A29D23F42B0DULL, 
            0xBF916269CC6EE20FULL, 0x8151F6EBE869120AULL, 0x9CC7B6531F763E03ULL, 0x29D229D25DF97BE2ULL
        },
        {
            0xF9E5CF373F2702D3ULL, 0x82804E374821670DULL, 0xA2BA0E4C8D9385C5ULL, 0x636004B173572059ULL, 
            0x00C7104C110AC370ULL, 0x7819C1BB820E1DE7ULL, 0x403EC98C35BC837EULL, 0xA026253ED7B952F7ULL, 
            0x5F41E4D3DDCFD7C1ULL, 0x5536DEB0018982CDULL, 0xBF26D16139805AECULL, 0xCF9ED87301D60D79ULL, 
            0xB52794E48D347B6DULL, 0x603EE2D2FA3BAFC9ULL, 0x136B75140A0AEAC1ULL, 0x85579AC637C84A0CULL, 
            0xD5C8853BDED32B67ULL, 0x4EBAF99F6500E727ULL, 0x0BDD3F9079080758ULL, 0xAD68082C6B150294ULL, 
            0x689741C50F7DA26EULL, 0x19B38B680A0E0CA7ULL, 0x0CF2BABF61C9BC37ULL, 0xA56E37BC0221887EULL, 
            0x9224C98F72BB253DULL, 0xECF148B736BCD1ADULL, 0x6883813921AFFF14ULL, 0xFD89A82034EF8B09ULL, 
            0x6DCC8F70F4B72680ULL, 0x16E44A93EE3F1A01ULL, 0xAC5A07FCA6121739ULL, 0xFA629CA4AB23EE4DULL
        },
        {
            0x5D3BF12FF7CABE00ULL, 0xDD4CFE4E93D82580ULL, 0x9D2B299CE6F64CB5ULL, 0xF9174391D04CF01BULL, 
            0x210CAD42E939251EULL, 0x229B6FA21BC1CF94ULL, 0xE8C9BC6130AFE7C3ULL, 0x09F17D8F8A03C56FULL, 
            0xBC6702FA24F060ADULL, 0x2BD81BA38E40C4E8ULL, 0x161D524474E0AA8EULL, 0x8F7857360A6EE429ULL, 
            0x3F421BFFF3B3266FULL, 0x96707A2D492CA020ULL, 0x443991C7E4593A79ULL, 0x26FF2A5AA2C3554EULL, 
            0x032FE66BF31BCF8EULL, 0x466250F45D5EF598ULL, 0x013B892849771C07ULL, 0x85AB813783989667ULL, 
            0xE7371280A2631ED9ULL, 0xF525A1A631AA4A56ULL, 0x311B912D7FF97F2CULL, 0x57FE5AC678EFDA2CULL, 
            0xC3453FAC820C9787ULL, 0x395EDD58A6C9A7F0ULL, 0x89460D5A92D537E9ULL, 0x8D234600D5EC6B86ULL, 
            0xD2ADDB19D47D36DFULL, 0xBEAA04715397D11BULL, 0x7353BB4462935505ULL, 0x3918E2B7CA6B3E21ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Canopus::kPhaseDConstants = {
    0x0DF82F8042E473AEULL,
    0x76E4DB85F21D5234ULL,
    0x466AF5B49C8EA9BBULL,
    0x0DF82F8042E473AEULL,
    0x76E4DB85F21D5234ULL,
    0x466AF5B49C8EA9BBULL,
    0x9456F89FC25C0EE8ULL,
    0x6804B0F50277CDB3ULL,
    0x24,
    0xD8,
    0x13,
    0xE0,
    0x79,
    0xA2,
    0x8D,
    0x22
};

