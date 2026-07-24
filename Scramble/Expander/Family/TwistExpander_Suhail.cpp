#include "TwistExpander_Suhail.hpp"
#include "TwistDiffuse.hpp"
#include "TwistFunctional.hpp"
#include "TwistIndexShuffle.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"
#include "TwistFarmSalt.hpp"
#include "TwistFarmConstants.hpp"

#include "TwistShiftBox.hpp"
#include "TwistSquash.hpp"

#include <cstdint>
#include <cstring>

TwistExpander_Suhail::TwistExpander_Suhail()
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

void TwistExpander_Suhail::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB3B10D725B99B6A3ULL; std::uint64_t aIngress = 0xEFF23EFD40070CAEULL; std::uint64_t aCarry = 0xB42B3F6006842934ULL;

    std::uint64_t aWandererA = 0x9D6BAF869E19D8BAULL; std::uint64_t aWandererB = 0xDC1BE3A06006B160ULL; std::uint64_t aWandererC = 0xD81A554E0BBC2E8AULL; std::uint64_t aWandererD = 0x88BC9D5B37FE8D70ULL;
    std::uint64_t aWandererE = 0xE0172EE10E6341F9ULL; std::uint64_t aWandererF = 0xD982742D3678653AULL; std::uint64_t aWandererG = 0xD22DDA46DE8BC7E4ULL; std::uint64_t aWandererH = 0x949EBA4DE77BC4E8ULL;
    std::uint64_t aWandererI = 0x93359C00B6EC187DULL; std::uint64_t aWandererJ = 0xE89CE8EC2CCE81E1ULL; std::uint64_t aWandererK = 0x93CA92AD3EA54D93ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xB8E57316FA0BC319ULL;
        aCarry = 0xD77FBCA7972A0212ULL;
        aWandererA = 0x95B257AFC76679A4ULL;
        aWandererB = 0xF6BA0510687BFD40ULL;
        aWandererC = 0x88EB2BF7DF207CE4ULL;
        aWandererD = 0xFCC57A7698B8016BULL;
        aWandererE = 0x8585605D3B0A3863ULL;
        aWandererF = 0xBF1278628B8E8075ULL;
        aWandererG = 0x8C990997A50EBCF0ULL;
        aWandererH = 0xF50D74C53AF45F49ULL;
        aWandererI = 0xC636B93507B7918BULL;
        aWandererJ = 0xAB901D88B94AAFEEULL;
        aWandererK = 0xDD7E9438C9E67848ULL;
    TwistExpander_Suhail_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Suhail_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Suhail_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Suhail_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Suhail::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xFDDAE53F21932A40ULL; std::uint64_t aIngress = 0xC5DB20AFB535451EULL; std::uint64_t aCarry = 0x9A9E68E0B1CA1132ULL;

    std::uint64_t aWandererA = 0xE7D113270BCDD269ULL; std::uint64_t aWandererB = 0xAF64587FC33F3A0EULL; std::uint64_t aWandererC = 0xFC9D558CDABE95FFULL; std::uint64_t aWandererD = 0xFC89D08FC4C6AAB4ULL;
    std::uint64_t aWandererE = 0xA9900C94870F229EULL; std::uint64_t aWandererF = 0xD9FB924A59D69B71ULL; std::uint64_t aWandererG = 0x9104630E9E34B1CFULL; std::uint64_t aWandererH = 0x8A7BE335B455E277ULL;
    std::uint64_t aWandererI = 0xE0A4EDF13BB2A715ULL; std::uint64_t aWandererJ = 0xDFE4C58C7639A9E2ULL; std::uint64_t aWandererK = 0x863B3D984DDE18EEULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x9CF88790C504D479ULL;
        aCarry = 0xA5EA75FD7CC54E53ULL;
        aWandererA = 0xE74EBEC9F46AB896ULL;
        aWandererB = 0x926A2BB014ABEA5DULL;
        aWandererC = 0xC1FD555B8CD97B21ULL;
        aWandererD = 0xAD13460F1B3DB0A2ULL;
        aWandererE = 0x98FA4B12A59A61D1ULL;
        aWandererF = 0x95F7EED594EE82A9ULL;
        aWandererG = 0xE5F5EA74DF916167ULL;
        aWandererH = 0xC32B55B2699AE787ULL;
        aWandererI = 0xB99B24A22A49B534ULL;
        aWandererJ = 0xD728F35D6D8801A5ULL;
        aWandererK = 0xEA8CC3B2BEA77326ULL;
    TwistExpander_Suhail_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Suhail_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Suhail_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Suhail_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Suhail::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x9BE9791F77BF26F2ULL;
    std::uint64_t aIngress = 0xC51F50A58ED30D37ULL;
    std::uint64_t aCarry = 0x9B0CF41063E6C860ULL;

    std::uint64_t aWandererA = 0xA1AD400243D129FAULL;
    std::uint64_t aWandererB = 0xA861A3909E20911FULL;
    std::uint64_t aWandererC = 0xF25E056D0E65AE84ULL;
    std::uint64_t aWandererD = 0xA4D60A79A283476AULL;
    std::uint64_t aWandererE = 0xCD44263782BF636DULL;
    std::uint64_t aWandererF = 0xD0E555ACE79D95B7ULL;
    std::uint64_t aWandererG = 0xF6BED01327F76597ULL;
    std::uint64_t aWandererH = 0xD4D8C6CE637B2DECULL;
    std::uint64_t aWandererI = 0x9846BA397B59E9E9ULL;
    std::uint64_t aWandererJ = 0xE07397D80464AC2EULL;
    std::uint64_t aWandererK = 0xE8DC8432E1D5FF07ULL;

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
    TwistExpander_Suhail_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Suhail_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Suhail_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Suhail_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Suhail_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Suhail_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Suhail_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Suhail_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Suhail_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Suhail_Arx::GROW_B(pWorkSpace,
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

// SmartSquash candidate 32 of 33
// Exploration cases: 100000000
// Nearest-family diversity: 911 / 1088 (83.73%)
// Total distance from earlier candidates: 28902
void TwistExpander_Suhail::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    static_assert((S_BLOCK / W_KEY) == 16, "SquashInvestToKeyBoxes expects 16 invest fragments.");
    static_assert(H_KEY == 8, "SquashInvestToKeyBoxes expects 8 key rows per box.");
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 13U), *aFragmentB = aIceLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 3U), *aFragmentD = aIceLaneD + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 331U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1640U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1194U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1055U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 9U), *aFragmentB = aIceLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 12U), *aFragmentD = aIceLaneD + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 380U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1283U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 241U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1383U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 14U), *aFragmentB = aIceLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 14U), *aFragmentD = aIceLaneD + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 199U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 2019U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 865U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 186U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 2U), *aFragmentB = aIceLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 2U), *aFragmentD = aIceLaneD + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 868U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 403U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 943U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1884U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 7U), *aFragmentB = aIceLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 5U), *aFragmentD = aIceLaneD + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1386U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1730U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 626U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 682U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 11U), *aFragmentB = aIceLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 1U), *aFragmentD = aIceLaneD + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1852U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1427U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1626U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1633U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 3U), *aFragmentB = aIceLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 4U), *aFragmentD = aIceLaneD + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1818U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1907U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 25U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1320U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 4U), *aFragmentB = aIceLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 8U), *aFragmentD = aIceLaneD + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1113U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1870U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1190U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1336U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 0U), *aFragmentB = aIceLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 13U), *aFragmentD = aIceLaneD + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 743U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1256U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 272U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1330U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 10U), *aFragmentB = aIceLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 0U), *aFragmentD = aIceLaneD + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 49U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 2015U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1947U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 606U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 8U), *aFragmentB = aIceLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 7U), *aFragmentD = aIceLaneD + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1888U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 409U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1994U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 323U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 5U), *aFragmentB = aIceLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 15U), *aFragmentD = aIceLaneD + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1550U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 585U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 392U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1509U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 6U), *aFragmentB = aIceLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 11U), *aFragmentD = aIceLaneD + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 896U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 185U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1512U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 920U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 15U), *aFragmentB = aIceLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 6U), *aFragmentD = aIceLaneD + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 466U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 280U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1817U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 60U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 1U), *aFragmentB = aIceLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 10U), *aFragmentD = aIceLaneD + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 950U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1862U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1264U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1209U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 12U), *aFragmentB = aIceLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 9U), *aFragmentD = aIceLaneD + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1233U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1606U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1873U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1918U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Suhail::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x9E963A8912B98E13ULL; std::uint64_t aIngress = 0xE73087D67E9C7E53ULL; std::uint64_t aCarry = 0xD6A8642E557984EEULL;

    std::uint64_t aWandererA = 0x998B01BA9AADA802ULL; std::uint64_t aWandererB = 0x869A39BB99F74148ULL; std::uint64_t aWandererC = 0xFB42A0031FB42964ULL; std::uint64_t aWandererD = 0xAB1AE1328D35C8CFULL;
    std::uint64_t aWandererE = 0xC072BFA1FCE4A29BULL; std::uint64_t aWandererF = 0xA81A87E6E34E276FULL; std::uint64_t aWandererG = 0xBBEF856B6C0C22B8ULL; std::uint64_t aWandererH = 0xD2FB0374526936E9ULL;
    std::uint64_t aWandererI = 0xC87A1C753A4536E6ULL; std::uint64_t aWandererJ = 0xFDC8F2CEFEC86E89ULL; std::uint64_t aWandererK = 0x91F6A3778DFB0110ULL;

    // [seed]
        aPrevious = 0x82967BAEE9AA8643ULL;
        aCarry = 0xBD0ED091A30838EDULL;
        aWandererA = 0xCD75AD815F346186ULL;
        aWandererB = 0xA6BB100052226898ULL;
        aWandererC = 0xF6545CA9C8BDE265ULL;
        aWandererD = 0xFBB2AE1BA05842F4ULL;
        aWandererE = 0x88585CEFC302BCC9ULL;
        aWandererF = 0xF29AED18DF3BE419ULL;
        aWandererG = 0x910F119F14840263ULL;
        aWandererH = 0xFAA9CB43D2BB8395ULL;
        aWandererI = 0x9CDBAE2DCCA137BAULL;
        aWandererJ = 0xE29581E72FD3B498ULL;
        aWandererK = 0xE2594DEAFC1FE351ULL;
    TwistExpander_Suhail_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Suhail_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Suhail_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Suhail_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Suhail_Arx::Twist_E(pWorkSpace,
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
    TwistExpander_Suhail_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Suhail_Arx::GROW_B(pWorkSpace,
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

// GrowA candidate 32 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 16767; nearest pair: 462 / 674
void TwistExpander_Suhail::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5999U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3582U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2189U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4900U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7572U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2289U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7489U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7872U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4080U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5934U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 764U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1562U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8015U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2248U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4470U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2052U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1508U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 336U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 469U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 733U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1383U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1188U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1772U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 296U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 384U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2040U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1680U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1271U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 146U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1565U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1719U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 879U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1746U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1142U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1043U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
}

// GrowB candidate 32 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 16767; nearest pair: 477 / 674
void TwistExpander_Suhail::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3659U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7335U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 441U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7829U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 119U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4197U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7916U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1755U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6343U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3954U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5331U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 10U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2518U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3655U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 100U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 503U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 938U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1656U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1313U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1851U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 981U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1471U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1283U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 694U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
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
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 447U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 134U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 551U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1728U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 42U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1722U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1789U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1844U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 801U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 382U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1822U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 187U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
}

const TwistDomainSaltSet TwistExpander_Suhail::kPhaseASalts = {
    {
        {
            0xF391AD7460AEEE95ULL, 0xE518595C0A250BD3ULL, 0xB81B3F807F0C3DF4ULL, 0xCB9428450C7A4DD0ULL, 
            0xA201AABED906DE6BULL, 0x95A8833AA7B93653ULL, 0x6347D8FCFDAECD6EULL, 0x5EE9567AAD2C760AULL, 
            0x786A8D3A842AFDB8ULL, 0x9A50667F50139942ULL, 0x9DC51E005E4559ADULL, 0x4234C43B25E7D8DEULL, 
            0x0C54A6804163AB29ULL, 0xDEE8514BD524F4B6ULL, 0xAA4F98FA24083927ULL, 0x5EB25CC0D1283F02ULL, 
            0x00F1C15A9D3C0443ULL, 0x81AF245F80B4886BULL, 0xE0386706695F9BB4ULL, 0x0C3BCCBF7E53C542ULL, 
            0x4918F155EB094731ULL, 0x3429424E1C13732DULL, 0xFAF03256F5934E1FULL, 0xD1775F0A77E20F3CULL, 
            0xBA4491506916D417ULL, 0x0131AD08248CDB9CULL, 0x92296979B7DDAAF2ULL, 0xB74C392DEE3C0E96ULL, 
            0x2F7F6F1E8195CBC5ULL, 0x4366C0926389C424ULL, 0x348FC4FC8C38C76CULL, 0x6D6E7140B2D0860CULL
        },
        {
            0x657A724097B48BA4ULL, 0x002FC5418F5ABC76ULL, 0x2A06D2FB20F085CEULL, 0xBF9F8A22C68CE0BCULL, 
            0xF40879D2BF79EAA0ULL, 0xC28620E9EA81C779ULL, 0x4A8E7A1966861041ULL, 0xF4D69DE1A1BC85C6ULL, 
            0x5B52D62EF15F1A9DULL, 0xA1D685136DC54689ULL, 0x1614C8298537B651ULL, 0xD7E0B3877F75C7D8ULL, 
            0x1513D3CA60D53F6BULL, 0xE0490D5030D81785ULL, 0xD0F9561F944F198FULL, 0x3E970D390C92862FULL, 
            0x45A7997FDE419108ULL, 0x29A6548C2FA7D8CEULL, 0x5B087ED9A7006DCAULL, 0xB212E65D9CD646ABULL, 
            0x226197F401F53B19ULL, 0x0FCE7F02E7B52FA0ULL, 0x2D21421E244FCAFDULL, 0x51E2FBCE968050B2ULL, 
            0x6094E3421C107D6DULL, 0x34FD9ECF8B1E4C96ULL, 0xC1288E1270F9B45CULL, 0x2D99A53193E0418FULL, 
            0xD985BE29A82FB4CFULL, 0x93C2CA1B6A6C6179ULL, 0xC130AC507627547DULL, 0x6B647FC085508D2EULL
        },
        {
            0xAF66AE99A0C5689FULL, 0xD4274D4A9715CA36ULL, 0x0F625F5E71251FB3ULL, 0x51C0EDF407711D43ULL, 
            0xC56422FC097E0D23ULL, 0x9EF9E606C0B989CBULL, 0x67E54D144F1E60DEULL, 0x402E149A47927553ULL, 
            0xB63DF94B42C34F0EULL, 0xC2C4F310627C26D6ULL, 0xAD6D973475F9D364ULL, 0x5CB4BB8D4EC452E8ULL, 
            0x5BEAC7010930BF62ULL, 0xE7E6B236D60B66D8ULL, 0x27DB2FC689E2C492ULL, 0x1E1EF880514E5F99ULL, 
            0xAFEEC29A3FB93C5FULL, 0x6D4E3920BC5CFA8DULL, 0x87409BD2D5F38615ULL, 0xAAD249707118A7FBULL, 
            0xD6F69BE8E2E9F601ULL, 0x255323A3A0C3F4E3ULL, 0xB2636B2086E623CBULL, 0x64735762163E152BULL, 
            0xADD89942EB1D431CULL, 0x6CE836B7991CBAEEULL, 0x504794E66514FC71ULL, 0x0D9609E3B7563F78ULL, 
            0x29F5A22441FA39D1ULL, 0x287612248BA55BD2ULL, 0x7132480FB5920380ULL, 0xEF7A70884DD653B2ULL
        },
        {
            0xCA44884DBAD762D3ULL, 0x97777A1F8012B689ULL, 0xBF093E841C894BA9ULL, 0x2C7ECFCF178BC2DFULL, 
            0x69721A64CA394690ULL, 0x59D48CF4045DBED4ULL, 0x6A0050F477BE31C1ULL, 0x70A1CA58A2124481ULL, 
            0xAA13F96E29430FC0ULL, 0x7DC4BE424D4ADF05ULL, 0x804940AF5F3C85FEULL, 0x472BBE76F9966336ULL, 
            0x69521A107ECA7246ULL, 0xF9F2AD48CB36EB37ULL, 0x459E6F0E1AFC9018ULL, 0xD4EE14B03C5B03ADULL, 
            0x96BDA8A6321AC9D0ULL, 0xB1604E046380D347ULL, 0x39FB4B2D6E11A166ULL, 0x62AF12BEAF4FC60AULL, 
            0x2E42125FA6C4211DULL, 0x0E10A2FAC28F76CAULL, 0x832178E81446BBB4ULL, 0x0E228444F7DDA69FULL, 
            0x41BEE3DF6B1AB1B2ULL, 0xA7912B33DAFF0485ULL, 0xB5BB2A3757596708ULL, 0x3D69F77607B4E5D2ULL, 
            0xC121420AFED69AF1ULL, 0x7D11F8F47C6ACCF0ULL, 0x031FA58FA8BC3A22ULL, 0x528063CCDDA5588DULL
        },
        {
            0xC216138854EBC253ULL, 0x80FD76F733EEFBC6ULL, 0xB65A5A4F4BDCF450ULL, 0x377CDD8A9BF0EDF4ULL, 
            0xF7ABAB0F51574E11ULL, 0x9661B64B6DDB4F64ULL, 0x5F25C450DAC298C3ULL, 0xDEF2220EA35ACDCFULL, 
            0x037D7AC73CE3C3A7ULL, 0xA4C63A55A901C2EBULL, 0xC29096595F970EDDULL, 0xAC3EA2E729661667ULL, 
            0x4CEC978DBCEE703CULL, 0x873486CEBBBD96B0ULL, 0xA109D943B1BB9554ULL, 0xFEDE7A03DE602E67ULL, 
            0xF53DAF248BA9E0A9ULL, 0xAF7E0743AE082246ULL, 0x5B37D081D4A8210CULL, 0x5E741A82506224E0ULL, 
            0x54D18694FD087A1DULL, 0xA728166E15C86B7EULL, 0x6865089F11F13672ULL, 0x88E9AFBEED18193BULL, 
            0x1BEB44A4CF8FC7DCULL, 0xE73A2C2300027E22ULL, 0x97059079B151274BULL, 0xFF543E9A3006ABD7ULL, 
            0x4568C5D71E8DA481ULL, 0x24688CA57DE244F4ULL, 0x684B492D17665E1BULL, 0x132B0AFB381B8020ULL
        },
        {
            0x248A02EAC90AB86DULL, 0xF4FE86E26469B6F8ULL, 0x66E04F4CC9E8D15CULL, 0xC302540EC02A1B40ULL, 
            0x90A68298980843A9ULL, 0x7E34C8D46B7F26ACULL, 0xDED20447CC565463ULL, 0x19FA15843D54C2F0ULL, 
            0x319FF00B86825FF2ULL, 0x41CDC6B12ACDC318ULL, 0x5C6792FCB4B369CBULL, 0x6FB363315C036A56ULL, 
            0xB4A9281CA3FCA6ECULL, 0x2C5079483D460306ULL, 0xAF1379D520D84789ULL, 0xA9660DCC175C7E5BULL, 
            0x07EB8723B1F77969ULL, 0xD4D31018209CBCBCULL, 0x5873871510ABD98DULL, 0x7FA72F00B5E42666ULL, 
            0x510FB170F02CAC26ULL, 0xF21906218DC8B6A4ULL, 0x4672A60DB303150BULL, 0x5EA7ED0B0F82955EULL, 
            0xAD18B116E07BBD0CULL, 0x7ECD23FA4C9A0FBAULL, 0x39685DD4970B9124ULL, 0x8B37DBFF447EEEDFULL, 
            0x3B3227E13BA6FF1DULL, 0x7A79334097760D4BULL, 0x560A9C575CC78F0AULL, 0xF92D0B4EFDB91FB6ULL
        }
    },
    {
        {
            0x511BA7097F1E80C6ULL, 0x6F49DAC2F90DAC39ULL, 0x28987016B1D97F9FULL, 0xF155B91E90772447ULL, 
            0x03F4225962B3EC46ULL, 0x9A0D91EF37C026B1ULL, 0x531783DD0FFB6DE3ULL, 0xC25799EB7DDCDD72ULL, 
            0xE32569F8CEFD043EULL, 0xAD32173490D113ABULL, 0x99BC445E9EA36CB5ULL, 0x247D6CEF35988597ULL, 
            0x440AE70657301490ULL, 0x9DA73254496F4B6BULL, 0xD5EEF526C5D6AA6FULL, 0x8F9D7135E0F149E6ULL, 
            0x980C8617B051FE60ULL, 0xFFA6383A4C6ABF3FULL, 0xF40FE3826072FE8DULL, 0x16DA9853C2007900ULL, 
            0x2E0554222CEF3BD7ULL, 0xD5FC1CE8C3F4DB72ULL, 0x704B38022CD11471ULL, 0x8B946FD69233347BULL, 
            0xA273F424410B1EECULL, 0xEBAFAA78D27E433CULL, 0xABBC574BEAEAD4C2ULL, 0xCCBBD0148EC509B8ULL, 
            0x6718A98E762C1694ULL, 0xF98B50BA8F8A392AULL, 0xA57DC9777A82CDAEULL, 0xE1B2685AC811F0B4ULL
        },
        {
            0x517D5DF1112F0CF1ULL, 0xF2F1AAF12C996C86ULL, 0xEFBF1CED265C5752ULL, 0xCED8E2315367E1C3ULL, 
            0xE482255B09A795C6ULL, 0x765BF60EBDC0B208ULL, 0x3707BE61FD385B6AULL, 0x7C4F674C5154B992ULL, 
            0x2706922A054F9E8EULL, 0x700C165B7A4AFC2FULL, 0x04C410A4DCBEA100ULL, 0xC29FE14B59B51BDBULL, 
            0x0C54A945D0C5294CULL, 0xCF10A1A4FA2DA85BULL, 0x7F77E1D03791F35DULL, 0xD60414AF9DEEA265ULL, 
            0xADA05ABD20CDC817ULL, 0xE7D32DB80262C0F4ULL, 0x949E5B44084B6AB2ULL, 0xF17AD0BE283B8417ULL, 
            0x820B46934D2F1255ULL, 0x371062B03734C2F5ULL, 0x6AB089D7F1A0AF8BULL, 0x7AD5FFFB509AAC18ULL, 
            0xAFEA8D8B3359E36BULL, 0xB9125008251CCE47ULL, 0x029689E554071CB3ULL, 0xE5C6AD91599F0AA5ULL, 
            0x6508452D30393250ULL, 0x497857F4A147506FULL, 0xA22DA3B8C4AB4A41ULL, 0x648B186AC225A563ULL
        },
        {
            0x215CEDCC854A264DULL, 0x0F84421F67B042CBULL, 0x2CCBC6FB2138FAE1ULL, 0xB4CC12F58363FF14ULL, 
            0xF42AA491DA793022ULL, 0xB1143378D9897D3CULL, 0x626257E13E5A64EAULL, 0xEB3FE4C644C37005ULL, 
            0x837650649195FD66ULL, 0x9125BBDD9DF47C33ULL, 0x3014446B2CAFD36BULL, 0x35831ED7C25E563DULL, 
            0x27D7820C1120FFD6ULL, 0xA8F41AC52ECDEAF4ULL, 0x39A3DE7C45B14ABCULL, 0xB66AAF74733EED4FULL, 
            0x8CDB131F2BAFD4E6ULL, 0x3FEFD4755D784B5FULL, 0x9523AFD6A1C14724ULL, 0x5E064B6C405283D9ULL, 
            0x522E5B239F2ADD54ULL, 0x02618BB0DD153E66ULL, 0x09C77A7924BB02C2ULL, 0xC3D017604A9B58BAULL, 
            0xF7DC64680D1FE7EAULL, 0xD9FCCBDA5C1937FCULL, 0x23C72737CF9CD39FULL, 0x80C860AE0CB39D2EULL, 
            0x608BDD751264BF45ULL, 0x4CF1AB1B2843D302ULL, 0x348B42F0897FE4BDULL, 0x7B107CA122A26D0BULL
        },
        {
            0x445F99243B2DE9AAULL, 0x07B5274A9C7FC54BULL, 0x33A44E5314D92DB5ULL, 0x9111D787A37192A8ULL, 
            0x839E5C62302A31D9ULL, 0x18B1135E05AB6CEAULL, 0x5E7D3EC54E124A06ULL, 0xF44CD0D647958F85ULL, 
            0xE175404441F6D9CFULL, 0x8C68E82858B21223ULL, 0x19A4BFD6AC6B13B7ULL, 0x4EF418A9F97ADD90ULL, 
            0x2383CFD8AB18B4C1ULL, 0x8B19CE7A090ECD96ULL, 0x83AF2C14ECC20C7EULL, 0x922CB1AA7804221FULL, 
            0x5FC3261EEE15331BULL, 0xE4357DFCE6E8E2CEULL, 0x4C68E0DE687DC2B6ULL, 0x1C8B41A3F97107ADULL, 
            0x47B3A9F7E60339B2ULL, 0x7C742DC5F7D4F911ULL, 0xEDEB1CD60795BA36ULL, 0x18D4BA5DA6E9089EULL, 
            0x31E80D0A8A6E8028ULL, 0x98F6B1A3E1340128ULL, 0x18606DF6871EB960ULL, 0x59AAC353198E32ACULL, 
            0xCAC5898DC510FF01ULL, 0xE669611ACE0FE19BULL, 0x598434F0B5263F6EULL, 0x683C30B167FD76B3ULL
        },
        {
            0x9872C8B9B83A61C2ULL, 0xD55012BD1CC4D830ULL, 0x74151132F1478C16ULL, 0x1173980109FA84E7ULL, 
            0xB110EB5006E69C35ULL, 0x4EF49D65125483A5ULL, 0x48EC3E1A12203983ULL, 0x49B4E7CA3C323351ULL, 
            0x095A0631AF6A3A5DULL, 0xC672D17B2FD397F0ULL, 0x0388180F5DDC6F43ULL, 0xDCD13125327829D8ULL, 
            0x38F7F033BB91D949ULL, 0x8872F0DD33364B3AULL, 0x161D489A6645126AULL, 0x7BBDD7397046466FULL, 
            0x1705AF157A592F87ULL, 0xB09B7B908EBCF498ULL, 0xB748140EFABF7C24ULL, 0x1BC94D7211EEAB66ULL, 
            0xA961CF14186EEEF0ULL, 0xA3D7AD983DF598B1ULL, 0x9728DC4AC6231979ULL, 0xC096355675CDEC8DULL, 
            0xF80B5261930FC4C6ULL, 0x4A6CCD4E61455DAAULL, 0xC0A5B9CAC6ADC934ULL, 0xE024DEA665FD0594ULL, 
            0x37A0D5F84D4C0394ULL, 0x3621EF11996522A1ULL, 0xFF7D8ACD76127ED1ULL, 0xFB0E68CD7B422A67ULL
        },
        {
            0xB6952081532EB471ULL, 0xED3F07E5A0245B6EULL, 0xE75A846749776BC8ULL, 0x8FCE415D27598C2DULL, 
            0x035C713844257609ULL, 0x63571D36B475A0F4ULL, 0xA0BA98426C9C76CFULL, 0x580A67BE70B7713EULL, 
            0xE89FF568F1A65B4AULL, 0xF0EB452A685CA31CULL, 0x343A5C3106FFB81CULL, 0x1E8F78257A6FBAB4ULL, 
            0x42C0657589D92089ULL, 0xFE38B5AC796F4B49ULL, 0xFF2CDDE4E8A3C613ULL, 0x5CD9508B3C17C67CULL, 
            0xB560D101C7DD83BBULL, 0x36E2265DE83DFA93ULL, 0x2FEF53D878711627ULL, 0xAB94802263456407ULL, 
            0xD968614BBAC9D825ULL, 0x6042B60F8000393BULL, 0x2EA0683D74CA6FA3ULL, 0x9130049CE54AEFC6ULL, 
            0x9962492AE77CEEA4ULL, 0x1B11FBDA8E3C4525ULL, 0x1D42CCBB6C47E029ULL, 0xF0714C0A2B75AF6EULL, 
            0xC159712CAD172A25ULL, 0x6761913F5E38BA13ULL, 0x113DDC18F1545C8CULL, 0x9E71642EC808E705ULL
        }
    },
    {
        {
            0x9777DB1DAEE2727BULL, 0x47C5170065B52A15ULL, 0x29C749B38D836A72ULL, 0xC01CF62C76874E2CULL, 
            0xD326E680EC504788ULL, 0xA5995014B6354770ULL, 0x0F16037AF8143142ULL, 0x7706C91C1CF3195AULL, 
            0xDBFF42489A74BF7EULL, 0x4ED6D511279BAD04ULL, 0x1F13147B1A545FBBULL, 0x39415C5A30A8EB28ULL, 
            0x7EA6F9064C0B11E9ULL, 0x135ECB295D9B6C11ULL, 0x059C9F73B226231BULL, 0x0D48EEE14D27A90CULL, 
            0x50D83AA386FA3089ULL, 0x9EE2CF39E61F54ECULL, 0xD2352A67203E512AULL, 0x87AA0C09D17A2998ULL, 
            0x4F217AAE973D38FFULL, 0xC11C69EFBA62B770ULL, 0xA44E4A8243EA06BAULL, 0x35E9A800C238A6FEULL, 
            0xC9A8A06937967CF0ULL, 0x1C9C718BA55F9F3DULL, 0xA16DF2AC5DA8EF25ULL, 0x632257BBFA5A434DULL, 
            0xDDD555860FAE1ED3ULL, 0x854ED58EA8AF9EAAULL, 0x18D30AE30677E2ADULL, 0x80A33EBD63FB5E33ULL
        },
        {
            0x6365B87C9A13EE99ULL, 0x18F68E737FCEF48DULL, 0x24B052C5B6132B30ULL, 0x815F228D0F99148CULL, 
            0xB0D48AA66CA5202BULL, 0xEBED4524D99B7466ULL, 0xBA9FEAE0482F3E8FULL, 0xFBCA561287256B1DULL, 
            0x3E3A1930E5AD8E14ULL, 0x432AD9A82CBD0CDCULL, 0x9E4866B0981AFECAULL, 0xFD0001171853BE88ULL, 
            0x1B8A83A7C6843BA4ULL, 0x7F8852DDD6BF00C7ULL, 0xA826FA286C982270ULL, 0x373773E659E431BCULL, 
            0x1FDD5DBA83583556ULL, 0xA0FDD1AB291B4765ULL, 0x609321AF275DBA24ULL, 0xCB712C7DC37D5393ULL, 
            0xBB5C059769E8C75FULL, 0x9C9A3CDDA54F17E4ULL, 0xC9E36029126DAF90ULL, 0xF968B4B6DAD49006ULL, 
            0x8D9EFFFD6C9B8595ULL, 0xC81CE4E9F71FE13EULL, 0xEE5CF31516DE6613ULL, 0x841D1423416DFD69ULL, 
            0x74EDD49BAC008CECULL, 0xDFBBE33F94A4E474ULL, 0x78BBF77D99D60D93ULL, 0xA6BE52DF93F9381FULL
        },
        {
            0xC4452ACDF92C1391ULL, 0x1BE32A20678E22E3ULL, 0x21A11CEC137B7C42ULL, 0xED90C739AF6771D9ULL, 
            0x1F0862BD31CF251AULL, 0xE72000DCA3B70B9AULL, 0xB01E8CE8A8AC7E6FULL, 0xB8DF3BBDD6DC2D3CULL, 
            0x5D06EAF602C48318ULL, 0xC28C9AC2108937F2ULL, 0xB517ACB730AE8B2FULL, 0xFCBFBA05AAFA54DEULL, 
            0x1601AA45DCD2E6BAULL, 0x5BF1F09DDF82C746ULL, 0xF473344078215E5DULL, 0xB3A453A8640F8520ULL, 
            0x4ADF0688BEDD1BB0ULL, 0x391BCA8CE7BEE895ULL, 0x89251A2402BF1F45ULL, 0xC773FBE49C304D24ULL, 
            0x0459A9E16C458623ULL, 0x97460285FBA1A091ULL, 0x1D9B169C584EACAAULL, 0x830316735540556EULL, 
            0x43D6CCC46123748DULL, 0x84EF28F51D8E0E73ULL, 0xF8F4B9F64C0E78CBULL, 0x1E9B6F3BB16CC21BULL, 
            0xBCBF8CB7F7998960ULL, 0x6C2B194900FE6978ULL, 0x340F12C43B2C13D0ULL, 0xF9F393ED9DC0025AULL
        },
        {
            0x1742A20BB1BC0256ULL, 0x21BC31B23FF5663DULL, 0x53D45758DEA6D857ULL, 0xF6422D6574B171A3ULL, 
            0xD1F4A3D4F58B8F37ULL, 0xD4CECF438658EF8CULL, 0xD3C08B1D747128F8ULL, 0x10082A4C7B3E4BCDULL, 
            0xD81B685E128706B9ULL, 0xD2204F38E809E1BEULL, 0x72B17D56FD4B2255ULL, 0x2C019C05A94D00A6ULL, 
            0xD49A5A0FAA455C70ULL, 0x35924F1742BF6796ULL, 0xB4C0ECAA033951ADULL, 0x3B063F62419BA52AULL, 
            0x8FD949B31F9A8D50ULL, 0xB2535C4F73D27BBAULL, 0x0C102CED94AA93AAULL, 0x239815E4DEF54F46ULL, 
            0xD39778DAEFE3D5C6ULL, 0x7B0377AB2733CBABULL, 0x928872F02AC1A158ULL, 0x5C9B3787DFCFB14BULL, 
            0x3BB4EB2734493D27ULL, 0x0ED735233E36F934ULL, 0xBA5441E58C1D4766ULL, 0xD1A0E1594F1F5BF4ULL, 
            0xBBCADA3C16703761ULL, 0xCAA67A99D965FDFCULL, 0x00AC3DA774C6462BULL, 0x06BE8D4DD230EBC6ULL
        },
        {
            0xA3759ED373C87F3AULL, 0xDF99DD055C7BB643ULL, 0x9F6AC775C64CF63FULL, 0xFE88439AFA059D56ULL, 
            0xDF246DCA420628DDULL, 0x5A2D2F8A68229C8DULL, 0x0237DD67CF04CB40ULL, 0xF4643F8D62EE0FFDULL, 
            0x7328F81EE6C6799CULL, 0x45FE01462937BC59ULL, 0xFAE7D3C8DFB82613ULL, 0x91E634CD7FE433CFULL, 
            0xB6D3F40BE14551C9ULL, 0x5F8B48EC8A9B4C2FULL, 0x6893473F03189227ULL, 0x2422B4A292D77473ULL, 
            0x1E914E6F2A412CC5ULL, 0x1BEF72A7279C00B4ULL, 0x29F974AFABEB7A98ULL, 0xECDE06340FA22FD1ULL, 
            0x1F05D78C07DEA919ULL, 0x7371C57800F1AAE1ULL, 0x458969D581962E12ULL, 0x4A121D44BD7D2ECAULL, 
            0xE8E444D9D721EB8EULL, 0x2115907C80DFF31CULL, 0xA7805CB1D93C785BULL, 0x65A309EB0C50D891ULL, 
            0x661B8D252D8CE0F0ULL, 0x6E622EAB078CA50AULL, 0xF9F254F3EEA9F3DEULL, 0xC0D87B47A78064B3ULL
        },
        {
            0x3450EF65DFE048D1ULL, 0x567E3CA1FC28BB57ULL, 0xB399ADF170F82A37ULL, 0xB6A37D86B2239280ULL, 
            0x4AC2ED8E349908C0ULL, 0xD6CE6236DCF7D251ULL, 0x118B961560197B81ULL, 0x4FB7001CBE9652C1ULL, 
            0x752A4E36CAA137BCULL, 0x2D07D831F8F0C029ULL, 0xE3F2AE0C3F4DFA09ULL, 0x32295CA056DF4CB2ULL, 
            0xFC7E22AB795663EBULL, 0x41856197840FB503ULL, 0x766DAC00F8381567ULL, 0x9A270ED4FB41A0EFULL, 
            0xD86BE9E3E1374334ULL, 0x75DBCF2A3D63CF29ULL, 0xE1C51E9A4B8D7C50ULL, 0xACEB8ED2FC8758F4ULL, 
            0x61A61AEE8364FEA3ULL, 0x640A60E1D06F5174ULL, 0xA779E6C6F722D3CEULL, 0xF8A5CF9205672056ULL, 
            0x726AA013F6C9FC49ULL, 0x8CE544B91C50A79AULL, 0x81873D356F16320CULL, 0x2718C638AF3DFEB8ULL, 
            0x813BA5ED7F03807AULL, 0xA94F3181B475910FULL, 0x6B019E99AE0EC336ULL, 0x9401EF9DAF92D4BAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Suhail::kPhaseAConstants = {
    0x6995FF0BAC40F1AFULL,
    0x0B9F113B726EBCC6ULL,
    0xC9D13F7F71379863ULL,
    0x6995FF0BAC40F1AFULL,
    0x0B9F113B726EBCC6ULL,
    0xC9D13F7F71379863ULL,
    0x46F7A0A82486A5BEULL,
    0xE00E0FF530237F00ULL,
    0x48,
    0xE4,
    0x36,
    0xE2,
    0x11,
    0x8F,
    0xA3,
    0xE2
};

const TwistDomainSaltSet TwistExpander_Suhail::kPhaseBSalts = {
    {
        {
            0x72DBA5B2EBC8FE18ULL, 0xBE029A6C651192FCULL, 0x5D0DD203CB9716BCULL, 0xF91B2A073F6AA0B6ULL, 
            0x9FA335EB71EDE443ULL, 0x327DEE60938FD981ULL, 0xF2672EDAD3636BC1ULL, 0x39C4402C0D6CC930ULL, 
            0x6BEDCF047C10F52DULL, 0x861CB27D4A75879CULL, 0xBEE9E71CD3C5416BULL, 0xB34F155F5E4856B7ULL, 
            0x6E2AC3819A136337ULL, 0xFB970869092CDE30ULL, 0xBF0024620E96CABDULL, 0x6137F8B3F48B26A0ULL, 
            0x2512269D2835AE50ULL, 0x96C03EC703064F6EULL, 0x6EF3FC3C191801E1ULL, 0x028D64579591CC99ULL, 
            0x19BE6DA6E20A2F8AULL, 0x8ABB5B5951E8FC5FULL, 0xFC51688591339B5FULL, 0xFF00DF872EB305B1ULL, 
            0x3FCE840914289C68ULL, 0xD8AD658476672000ULL, 0x3A5CD2E1F10CC0B5ULL, 0x30D224AE2C05CDF3ULL, 
            0x65E8323029B29CC5ULL, 0x9B51D8652D7F4CF7ULL, 0xA77B7B9AE1B09B58ULL, 0x4A227087A2E4BCBBULL
        },
        {
            0x33A20416E5D099B2ULL, 0xECC53EC7A80CC95DULL, 0xE76DF85DC2E638E5ULL, 0x8B1DEC8103A2EC6CULL, 
            0x87F9601D8CED10FCULL, 0xD148EC06A1855DCEULL, 0x04DF779A83DE1378ULL, 0xEC3AB4B4701C89A6ULL, 
            0x06A6E3A4F69D8792ULL, 0x8D31F92607ED4664ULL, 0x6C03899182005181ULL, 0x89B54EA0A7DBB3B0ULL, 
            0xBB30B8A365AC904FULL, 0xA1DA4A2712462DAEULL, 0x073DAA4815D3C9ACULL, 0x9E0EF58D427A2B98ULL, 
            0xC9A2BE5004188AC7ULL, 0x88448F517C5FBA28ULL, 0xE742609185B56E91ULL, 0xE62A601F869D6F7CULL, 
            0x8FD51C092CAFE7D1ULL, 0xF705EFA5A8B644F9ULL, 0x7C29BCCC8EED7AF8ULL, 0x4DC4757B81825366ULL, 
            0x5819CA929B50E9FBULL, 0xA7E54DABAA317E00ULL, 0xD7A76DCFA55E1113ULL, 0x1FCBE63918FDEF2AULL, 
            0x1665C2BF71A5E5CAULL, 0x0FB3586021A6C5C5ULL, 0x4A87CAA7ECDAA381ULL, 0xA5ACF8C3A2753D3CULL
        },
        {
            0x94CA5294BC3AAA7DULL, 0xFEC8EE91D5FF2FD4ULL, 0x1E09E04D2D2F6978ULL, 0x44D9C7664125CAA0ULL, 
            0xFCB41078E7504782ULL, 0x5CD0D585C9DD5A2EULL, 0xA278C71AFA5BFAEAULL, 0x88D5F5FCC1DC9169ULL, 
            0x660226170E5D7FBCULL, 0xF0D75E8E81E9B428ULL, 0x8A0E1F02E7D4383FULL, 0x014CD40C159D7082ULL, 
            0x876DE2D43DB4CCE3ULL, 0x1138142E4A1F727EULL, 0xA7E973C2FF23E43BULL, 0x996D5A8587D0A70AULL, 
            0x9935F09C7C343C89ULL, 0xA7E7E1DC692AED61ULL, 0x4F1DCDF020D42801ULL, 0xE1640CD2405F1061ULL, 
            0x5EB01D49C05B1618ULL, 0xE8CAE7F4002B4FD6ULL, 0xA6D75568ABD713FFULL, 0xEFBDAF8F53EB9E70ULL, 
            0x3D30A2863B2121ADULL, 0x3BEF20EF2B843C89ULL, 0xBFA35FE6B719AEA4ULL, 0x4C58D9AF19E85DF8ULL, 
            0x472406E236370881ULL, 0x9725AB57514A49D9ULL, 0x42883DCF76E6C22DULL, 0x035E8E528B7DFA19ULL
        },
        {
            0xE6DDA2F85B38CF2EULL, 0xE07E4C6AA9150C00ULL, 0x88259FAA401D2971ULL, 0x592C6FA7B46F8F5DULL, 
            0x7006041A52C6CD38ULL, 0xA11D547908F54796ULL, 0xA7FF9C995F35DB60ULL, 0x739AEFAA71BC1D77ULL, 
            0xDCE226C3413C57B0ULL, 0xB2E387315016D77AULL, 0x89BD6FB6D4F9E10EULL, 0x46E90DCA89C2C505ULL, 
            0x4AFEC2FA4B86A4DEULL, 0x071287554D851AC9ULL, 0xF6BA3490B8E19726ULL, 0x306B5E1F9D94243CULL, 
            0x40588D655842C653ULL, 0x98CCD311E97F3705ULL, 0xF8A831FC1A0CFCFBULL, 0x8B6CC9E1BFC0791CULL, 
            0xC83666FA806B7A73ULL, 0xE132F4C7C7A85BAAULL, 0xA72F6B29A70905B9ULL, 0x2E25E753DE2BCF3EULL, 
            0x8623BA7BD12ADB17ULL, 0x1DFD6B9FCEDD8998ULL, 0x6242424232254431ULL, 0xBF98533DBF761755ULL, 
            0x4BA9A11DDA5325E7ULL, 0x5B99FE330FEDADE6ULL, 0xA38E0EBE3444967CULL, 0x9F62FF7D5F84D8B2ULL
        },
        {
            0x6223DE688DF76EE1ULL, 0xB55946D92FE1C3D6ULL, 0x8A1DA8CC66108E58ULL, 0x63B7772AF35F7A2CULL, 
            0xC56F213C1E0EEE18ULL, 0x2596C6C4585C77E6ULL, 0x0C32944D38629FDFULL, 0xEB5F86E05D924060ULL, 
            0x1CB26F65DD594B92ULL, 0xF0F1B174C89B7BDEULL, 0xA53DCAF1B76AF2D9ULL, 0x58B4FC805D79D687ULL, 
            0x9912739DDCF0C120ULL, 0x70D8937B71250D3BULL, 0x1811CAE58ADC4A30ULL, 0xF61BF9C47CF445F9ULL, 
            0x473A578EA30E4FE9ULL, 0xA025AA439BD445E0ULL, 0x990A0559A45D720BULL, 0x17E21B3D47837C76ULL, 
            0xA077275722EB0948ULL, 0xC9F69C9DBA502E92ULL, 0x177BC8E88EC6E88DULL, 0x67950C7B8D3ED9AFULL, 
            0x7CFFC45D960EE25DULL, 0x613D2EED11D5DB8AULL, 0x2C1E4C32F9269181ULL, 0x31D6B87AF6AF99C2ULL, 
            0x64B3B7F52749D3C4ULL, 0xEDF66013EB904007ULL, 0x1E4DC5735ACAE04CULL, 0x4D3EAFF6F5B40F4CULL
        },
        {
            0x8677AD6CC24C1C3AULL, 0x7A73A92401626CCBULL, 0x9314B4479FD790B4ULL, 0x43C35AC820BA86DBULL, 
            0xDD17D27DDCC8DD34ULL, 0x2B3B09A6D63006C2ULL, 0x05CDD0798A1718F5ULL, 0xBE1DF64E1FDAE703ULL, 
            0x294121EFC5CE41F5ULL, 0xBBE6693D2391701CULL, 0x3EAAC394BE4FAF0CULL, 0x1B7459F2E59D2F60ULL, 
            0x0D2404F4C210A33DULL, 0x99ED8202754F83D6ULL, 0xECD5F8078070EC84ULL, 0x30D895B26A8DCB4CULL, 
            0x13B68B862450E1F8ULL, 0x2F0F3ECC08C3DF8EULL, 0x69B990D2C8B7AEA1ULL, 0xDB776DEA7EEBD73BULL, 
            0xBE2E4044861C84E4ULL, 0x2B6BE53A95B95CAFULL, 0x382BCE568B3AEA56ULL, 0xD492267886D414AFULL, 
            0x3C62DC12DBCC56CCULL, 0x7A7844B5C19F6795ULL, 0xAC4C478A64EDDB64ULL, 0x224290E53CEF9092ULL, 
            0x0BCF55A6481BB5CCULL, 0x7E35492A733D5970ULL, 0xDF27CA7E9372E80FULL, 0xC02A3ACD889D0CD2ULL
        }
    },
    {
        {
            0x967C45D849CDE19BULL, 0xC49307C889CBF53AULL, 0x2E51EF5B88DB625EULL, 0x9E6B095EBA50E2B8ULL, 
            0x6255854409BB40DEULL, 0x4CFB468854B2A3C2ULL, 0x67FE815C863982F6ULL, 0x0C639BC1BFFC45D2ULL, 
            0xAB9D9890A8A572C4ULL, 0x3CEA85DB5BE352B2ULL, 0x8FE54816548DEBBFULL, 0xE704C459DEA3E624ULL, 
            0x500DA890423EE690ULL, 0xAB95CBAEBC8D11D2ULL, 0x1D09D0EE931686D5ULL, 0x592EDA7404EAE26AULL, 
            0x3D0327027DC4F46CULL, 0xBC335525F161427DULL, 0x902F0AD088430DB9ULL, 0x1EDFC6FEF2E539CAULL, 
            0xCC35A87E6D5E0CA0ULL, 0x3E18937E4DB6CA74ULL, 0xF642824547688EADULL, 0x86F0FA302100B153ULL, 
            0x62A48F9D0A2ADFB2ULL, 0x9AC54EFD780347ECULL, 0x456BD3B3297281CFULL, 0xF4B9E99F0A9ACAD5ULL, 
            0x8780817C3FAEF2D4ULL, 0x75A73207F93E0D94ULL, 0x0C242D824DF62F30ULL, 0x1D18DA33634E3A21ULL
        },
        {
            0x050BD7C2DB34819CULL, 0x5824C71966538278ULL, 0x14B3BA8D76F5B4EAULL, 0x8599A911FBE16CADULL, 
            0x3E7B70AD47E9DE49ULL, 0x595FEA76354AF0CCULL, 0x2073EE4F77729275ULL, 0x41CBF9D00C41E306ULL, 
            0xBB88EB9DF4D9CBB1ULL, 0x0B62C90F5D5C85C5ULL, 0x8FAC1E6F02500669ULL, 0x96238AD61B43DEC8ULL, 
            0xF9D89663BEEEB04EULL, 0xA9462CA662F44BF5ULL, 0x8FD993D6D824FA0DULL, 0xC540B52032120ACBULL, 
            0x68EF1F0DB2CAC1DAULL, 0x3AF6766192E7FECCULL, 0x65765087B1C3AECDULL, 0xD2276C814C1D7E26ULL, 
            0x75384D483B24023FULL, 0xB6F27C44A42329A0ULL, 0x49E92759B0533EE0ULL, 0x3DF5EABF94BE634CULL, 
            0x1C8F2EC8D1B15097ULL, 0xFD7E3F136C380495ULL, 0x138C947CD2A32D4CULL, 0x97B47C2FFE0E3DD8ULL, 
            0xC7311AC3B407C325ULL, 0x5050FE6C98A29113ULL, 0x242678C8BBABDAA7ULL, 0xB49C2410034EFB67ULL
        },
        {
            0xAF889665BB8330CFULL, 0x51DCC40517BBBA87ULL, 0x0F3D59DC2C46DAB7ULL, 0xF1107185E12D629DULL, 
            0x1ED8EEE456D83877ULL, 0x6818C5F3D043A045ULL, 0xBF38136FDD13B664ULL, 0xA434A79173EB6779ULL, 
            0x09E6AA7F4174E52CULL, 0x36611210DFC9E6D4ULL, 0xAA9448F13DCFF0F0ULL, 0x1AB70AF7EC9D9B8BULL, 
            0x1843BC50A758FF33ULL, 0xEADA3CDCF301BB4DULL, 0xCA65C0E15FDDAD2FULL, 0x4B883E17B17E4394ULL, 
            0x93F9CBA67F19973DULL, 0x21D5E20D24D1E1C9ULL, 0x8F6E7654C390329FULL, 0x78C42CE9FC13E0CCULL, 
            0xCA74809AFFBA0E98ULL, 0x54BE722F202D1AF1ULL, 0x63EF3BFE717C4B4AULL, 0x1A7A674B42DC0FE9ULL, 
            0x9A74C80A21201248ULL, 0x003B9238F4CCAB0EULL, 0x536A4C276095E6CBULL, 0x67C27D0A0636CB9EULL, 
            0xF25BE615BE593EB0ULL, 0x1853580748FDACAEULL, 0x4F79F20125F945E4ULL, 0x987593FE90421AD6ULL
        },
        {
            0x067BC0CD4454C945ULL, 0x5F934F6CCF28948EULL, 0x5187013F1968EB6DULL, 0xD2603EF35E5C3589ULL, 
            0x11018B7A7F374AA4ULL, 0xF10F363BB94E3F14ULL, 0x99690B2CD3B569C5ULL, 0xDA28313C7A6492D0ULL, 
            0x71A23ED2984648C6ULL, 0x2368CF97FACF05F3ULL, 0xA39BD3E550C561F8ULL, 0x066D3B89CE8FDD43ULL, 
            0x0D29CD39B78DA6E7ULL, 0x04BB7992CF5CDA6BULL, 0x7B1664514DB05796ULL, 0x8A0198531951D3EAULL, 
            0xE2FCAFB7B564866BULL, 0x3274FD109E97C516ULL, 0x28926C901AC62DDBULL, 0xDBC6D1876D327EC9ULL, 
            0x026F255111F2814DULL, 0x38A8675078658A9CULL, 0x1EBCB2B861653281ULL, 0xD1CE9977073F6544ULL, 
            0xDE791A23AEEC79BCULL, 0xC5D2D38629BDBDBAULL, 0xE2AA04E12E6F0B6BULL, 0x156752DC785A4449ULL, 
            0xF8B3EADCC552A9CDULL, 0x1E65DB8D18CA0685ULL, 0x699AEC66EC70711EULL, 0xF5495BEDCE39DCFCULL
        },
        {
            0xD8B1B5EAAF31A8AAULL, 0x892C796CAADE1C1FULL, 0x35CE3CABC1F64EC2ULL, 0xDB83E8D8CB401F2CULL, 
            0xAD5787C9D91AA7F9ULL, 0x955D043BA52180CDULL, 0x42957E30F5D0069CULL, 0x8C304E607282A82DULL, 
            0x2D49A02D4C502ECFULL, 0xCCA511A06A8BCB17ULL, 0xE0D97AC3D2A9CC47ULL, 0xC119C0C046CCCE26ULL, 
            0x7F0DB48904483FB8ULL, 0x5FB6D3EEBCF80CE9ULL, 0x2A2E8FC71D170D5BULL, 0x8FA59D316D251801ULL, 
            0xEDE473088C58795DULL, 0x37511F1E83458CEFULL, 0xB552A2A734F75CA3ULL, 0x89E7BD86F89BEDC0ULL, 
            0x6FCDD036A0524588ULL, 0xF3433B0B89B53746ULL, 0xB548132468E206CDULL, 0x29729F6F15DD815CULL, 
            0xC195370F6A669237ULL, 0x102365746A2F34B1ULL, 0xF0361F7B61DF5A7FULL, 0x5A53527514636919ULL, 
            0x7B0ACB3F7E6423C4ULL, 0xD444A7F75417DA19ULL, 0x763394773E26967FULL, 0x31A65F66E239D201ULL
        },
        {
            0xC97AA09580CF64B3ULL, 0x32E081C790778766ULL, 0xC671994277B8D8E6ULL, 0x3BFCDE2E168ABB50ULL, 
            0x1E21A0B11655E10BULL, 0x8DEEAD654CBAB727ULL, 0x47E5BBCF24328DDBULL, 0x241368B4C295DECAULL, 
            0x8A37959E6A2DB3ADULL, 0x46795C7782DBF9DAULL, 0x747B3BD848BF4E6FULL, 0xEA3E4A05DE160973ULL, 
            0x8157397A6D4AFCA3ULL, 0x03FF97534093CFB5ULL, 0xB3015FF894FE96E4ULL, 0x68670D947BCAC3BAULL, 
            0xBB07A2FDA0AC9F08ULL, 0x8D572666B63BE3CBULL, 0x020D65808E9002F5ULL, 0x6F2CDF75C1B3FAFFULL, 
            0xFC021233581B0D6EULL, 0x9D2579890106E567ULL, 0xF150B1921A32252FULL, 0xF944F8160FA97772ULL, 
            0x6D383D37AFA2D8FAULL, 0xD4266AF47ED028CAULL, 0x37950E25C979CD4DULL, 0xEF5CCADFDEBC48F1ULL, 
            0xCE02E5E78638E1D0ULL, 0x90C3AE5FE78DE1EBULL, 0x9357E7621F082E43ULL, 0xECEA2E64D42BBA94ULL
        }
    },
    {
        {
            0x47E384AA058E6A20ULL, 0x6441ED1B8CC06FE2ULL, 0x87BE1C71D5CC28CBULL, 0xB83862A4D51835F5ULL, 
            0xAACA8EDC88DC9B4CULL, 0xD356CB9F2B03FF16ULL, 0xA0D9E67E3E65196CULL, 0x7374DC3069066505ULL, 
            0xA84337E0F432AA24ULL, 0x66A8ABD70A1C3CD4ULL, 0xB069C28313FE76BCULL, 0xD2AB02B965834C97ULL, 
            0xCF5A5DD7BFB13F03ULL, 0xCC912D300868C043ULL, 0x7D84B3154085AEA4ULL, 0xB2D6293F1046234CULL, 
            0x576FD220D40E06E6ULL, 0x31CFFF4CECF05057ULL, 0x1B6C9F4FDEB1152DULL, 0x3A3E2D85A52A596DULL, 
            0xC5A328872D4A37ACULL, 0x58493C29A409BE52ULL, 0xAC056F75152C9335ULL, 0x752DFC43E9480602ULL, 
            0x163E9C1DEBD28863ULL, 0xFC995122D6E49F49ULL, 0x61BF4E57B27C34B1ULL, 0xEE59D98BB7765E15ULL, 
            0x020AAC82F695A5D6ULL, 0xB00D86AD236E6114ULL, 0x8C07944BE5184E0CULL, 0x5C42D6E042C83881ULL
        },
        {
            0xB4D7C44B2F80FB9BULL, 0x59C5A5BBFE4FF07DULL, 0x07292A152B937D2EULL, 0x37DE12AEC5112222ULL, 
            0x3D64396C806424BBULL, 0xDC19A6FA0A127366ULL, 0xD22B4FEB089C106FULL, 0xBACCCE342F164E7AULL, 
            0x005C2F73A9657DF4ULL, 0x16447FC93AD7EAC1ULL, 0x4A5994B3A0B46AD1ULL, 0x26585CEE37ABACC3ULL, 
            0x892FA3303A906E3DULL, 0xAB22B0AD84311197ULL, 0xF0DCA6448603FE68ULL, 0x38BF9A4110BFC0B8ULL, 
            0x526C713FDFA64790ULL, 0x1BB3915FDCE523F4ULL, 0x3CAB0476B3593E8FULL, 0xEABFAC5158C04DCCULL, 
            0x1A454FC543D331E8ULL, 0x8341CC1860225EAAULL, 0x0F427A2C45A91AA5ULL, 0x5DC32EB30B151048ULL, 
            0x58A4CC08F409BE08ULL, 0xA77B48FF4C359A11ULL, 0xF773C40087AB1F79ULL, 0x1F945A2274E54F92ULL, 
            0xE0A678359190FFA3ULL, 0x7C4D52954038F91AULL, 0xF43C0D52C8A7E31BULL, 0xA5D03CD1CA24E566ULL
        },
        {
            0x966123757874F049ULL, 0x2D4BD7FDECBF08E4ULL, 0xEE188C5CB2F42251ULL, 0x419C6007AC1E99C4ULL, 
            0xFC8E293CD4A82302ULL, 0x4D5BFA2CEDCA7E7BULL, 0x2FA5BACA53C01865ULL, 0x37F3E30FE140EA20ULL, 
            0x10922EF2BCFBDF5FULL, 0xB73164792ABEA4A5ULL, 0x7FDFC5762B629918ULL, 0x63D41D8F3B199CD6ULL, 
            0x3BDEF39CD7950675ULL, 0x7AD74AE4E5071E02ULL, 0xBA0488347C1562E5ULL, 0x0B918E3009F0BB20ULL, 
            0xFC2E2886C4F4F55BULL, 0xC71BAADB730BAC1EULL, 0x1BB66E3371818E18ULL, 0x14E3E530D38BFC3FULL, 
            0x3D26D81D8BF11B33ULL, 0x42CA8EF3B44DF123ULL, 0x951497E48B500EC5ULL, 0x34D4E7AE4C5643BAULL, 
            0x43410F4AE5D04CDEULL, 0xAF0FB0D1E08A9B1AULL, 0x9B8437F4AB51F183ULL, 0x36ABB250FBCE7DE0ULL, 
            0x2BB226B2A26D2D3AULL, 0x41B0F15184D171D7ULL, 0xD75384B9765B6738ULL, 0x7F22410D949F7BA4ULL
        },
        {
            0x46ED6915938308F2ULL, 0x35DB12B35FD0C5BEULL, 0xF41319D989F24C96ULL, 0x7C17976671963241ULL, 
            0x8B0EE46031EA48ECULL, 0x249B34EB2BDD230AULL, 0xA9ED7E5E5D53A5C8ULL, 0x549C5B7C533F4C43ULL, 
            0x283C245A0FA40B93ULL, 0xF8D2FC161D92A690ULL, 0xE8A4E3FD40D3AFB5ULL, 0x50E80BB7D2853924ULL, 
            0x624C350C15244144ULL, 0xA41486A9A0067E10ULL, 0xDBFD59C7745485DEULL, 0x7A70C0911C4222CBULL, 
            0x9BF6B6252B43D77EULL, 0x42FDDE513A16376EULL, 0x7167FCA384ABA2B2ULL, 0x1B861B1BA838DCC6ULL, 
            0x36C0BCD35308FE80ULL, 0x14FB9D5AACB85CE2ULL, 0x098BF737F670B2C5ULL, 0x18E63BB4F5808204ULL, 
            0xBA2C8B00CA0E53F5ULL, 0xB2EEF51A9E1C6684ULL, 0xFFA94F300C7AC732ULL, 0x1DEE0D69E0422041ULL, 
            0xF84655B287577B88ULL, 0x9FB393CAC0F237ACULL, 0x9AF3D50923B05D48ULL, 0x624BE814B61B8758ULL
        },
        {
            0xC48444171E5B0840ULL, 0x4EF18E0A5C17F951ULL, 0x50235A325EC02361ULL, 0x8739272BE58D0E85ULL, 
            0xBAFD06799E8A2F9BULL, 0x7695D1231C56FB26ULL, 0x522519F0363A0B54ULL, 0x94F11C43995ABC9AULL, 
            0x3D4ED4E0FA9BF64AULL, 0x872860A795A2086DULL, 0x83BB0D1620661FCCULL, 0xA54F80DEDC213F39ULL, 
            0xC333925EA1F02D5DULL, 0x16D807FF68DF9443ULL, 0x7EBD50CD0F9D0007ULL, 0x06740FC60EDEB15EULL, 
            0x2ADB7D4DBC766367ULL, 0x90077A46CA9A8830ULL, 0x7B85690AB26B45C5ULL, 0x2C519FBBED3586C3ULL, 
            0xEE87490FD92BF842ULL, 0x84D859C4F80A25D4ULL, 0x71FBEFBB14953C37ULL, 0x9867BE5865B8F232ULL, 
            0x2EB449413F0D75D6ULL, 0x3A27E5E16A787D1EULL, 0xB043849558B0D143ULL, 0x28979897BCE34232ULL, 
            0x25A6CAB5826B0DCFULL, 0x96531715A8566FB6ULL, 0x1A14889DB911BCC6ULL, 0xB793577B91242AB2ULL
        },
        {
            0x6E0E4043AD41EEC2ULL, 0xDDCAAA35FD83EC15ULL, 0x64981CB7A6EA0FE2ULL, 0x1DE65C4378B5A422ULL, 
            0x45B780B12795E310ULL, 0x8FBA0C7D6CC411FCULL, 0x3DEE7A9624B1FED5ULL, 0x37CED2EA5CDA2535ULL, 
            0x5F62C5A8DAD3A4D5ULL, 0x4D388B854BCD7655ULL, 0xF7BA871A89A6F8F4ULL, 0x3EF3699EF31390E5ULL, 
            0xA86869045A51CFC2ULL, 0x8F839EB8A9903A4FULL, 0xA7FE0E98F0C152BAULL, 0xAD886809A9405970ULL, 
            0x0C88A12FA3B8E802ULL, 0x1A1D26CA9795A54FULL, 0xB6C5F700AFD86D41ULL, 0x21DEC73089932184ULL, 
            0xE3E819CAA043A834ULL, 0xFC6BEB054EB82842ULL, 0x7F1A8E76E71DC173ULL, 0x13BA241C875876AFULL, 
            0xA7B46300C50F136FULL, 0xD3EF8217A70BBB9EULL, 0x6337A241DE0671AEULL, 0xBECEF5C8BE54801BULL, 
            0x6FF50F08D2FAF3A0ULL, 0xFA2DFFBE4F627B0FULL, 0x06F7AA86C1CE20A3ULL, 0xA40F50FCB167F434ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Suhail::kPhaseBConstants = {
    0x91D36EF77F4C7A4BULL,
    0x1CEBDB6B227C5033ULL,
    0x00AADFE2726DF914ULL,
    0x91D36EF77F4C7A4BULL,
    0x1CEBDB6B227C5033ULL,
    0x00AADFE2726DF914ULL,
    0x59F50DB97A55B595ULL,
    0x96C70738F072E92BULL,
    0x79,
    0x66,
    0x5B,
    0x61,
    0x56,
    0xB5,
    0xBF,
    0x7C
};

const TwistDomainSaltSet TwistExpander_Suhail::kPhaseCSalts = {
    {
        {
            0xE2B4BAE9FFC88036ULL, 0x2793308B29198041ULL, 0x65C5A6E7E898D2E8ULL, 0x78F4A6E6A80AE394ULL, 
            0x86FB1826726A1352ULL, 0x5C45836C186D2BB4ULL, 0xD2C3D6C208E4FB11ULL, 0xC835BC3316D47FA1ULL, 
            0xF6A595B796EB81BBULL, 0xC19DD5B20D2471BDULL, 0x008B1BA4D6906520ULL, 0xA088EA55D128B6C2ULL, 
            0xEA50C1FC8C370653ULL, 0x290631AC5FC60A87ULL, 0x77863C7434CEF6E9ULL, 0x4D0428FC7BD071C3ULL, 
            0x3EFB8EF87621F48AULL, 0x269B6BCD71AF07EFULL, 0x572A8AE3CD3BBB3FULL, 0x549FC5EF0398A812ULL, 
            0x79E03B72CFB863ACULL, 0x44413BAEFE4127B0ULL, 0x587E4F1B25ADDE36ULL, 0xAD762AE0EAB15C40ULL, 
            0x60795F78AEDE8D5BULL, 0x5414DBE386B45779ULL, 0x5192C057571FEF6AULL, 0x997B4AE16CD45A81ULL, 
            0x4227D92AA615A5C3ULL, 0x7B69B05453F2F628ULL, 0xC524FE51678BA905ULL, 0xD474896C73F0632FULL
        },
        {
            0xD446A3F2D8F455FAULL, 0x18D08BAE9E056A09ULL, 0xED586AC0743DADDAULL, 0x60AA68E377529332ULL, 
            0x320094D184B9B65BULL, 0xDEF76DEF5F9D6ED9ULL, 0x11542B379F7BA52FULL, 0x57E172EADAD96A29ULL, 
            0xD14B7B381E79919EULL, 0x63720F22A0F101C2ULL, 0x80BB6D999B1A206CULL, 0xC7D810D288D9FE9AULL, 
            0x1FB6584F658F210CULL, 0xA7EB8804C86030ACULL, 0x65CD11D78D4DDC00ULL, 0x1F15A4E5A3AA8FEDULL, 
            0x96FF76705BB81242ULL, 0x09B79C85013ED05FULL, 0x1A5CC69B3F2F9417ULL, 0xF5633BC44FEC2F8DULL, 
            0x31C47E008EDFC90CULL, 0x84329F722E338C93ULL, 0x779C4F5090FE7D46ULL, 0x32C34608B1F6A748ULL, 
            0xF069E0B8A106C9C0ULL, 0x3C0B3E607223A915ULL, 0x1B70F40222287142ULL, 0x5EB56F9318DFB96FULL, 
            0x868D66151DADA5E2ULL, 0x6365EF22E9CD8BCCULL, 0x34D9EB2FCEE3295AULL, 0xD8D9496C5037D145ULL
        },
        {
            0x88E0ABE9C3C37AF3ULL, 0x33B872ECA3134B9EULL, 0x6FBEBCA17D7FD79BULL, 0x14E155AE567B2855ULL, 
            0x4CE3A7BE9BC2B2DEULL, 0x824458B002B350D4ULL, 0x20DF78D88384FE12ULL, 0x817D23D589B167E4ULL, 
            0x7964AE854809104FULL, 0xBEB5B1729AC08422ULL, 0x185C975F2288DF73ULL, 0x7508264B55774BEAULL, 
            0x0A3829CCBCEE68A4ULL, 0x6CAFCD67FC39E637ULL, 0x60ED400CC232694BULL, 0xE45FFF38D1F75D0DULL, 
            0xEA166DF40D8FFCB7ULL, 0x132F2F4128CCFA26ULL, 0xB32D07B035EC7ADEULL, 0x2674E409F9235377ULL, 
            0x196EDBCD417F1A7FULL, 0x019C8FDCD0B9EE47ULL, 0xC46A13EA3B7BF341ULL, 0x198F73445BFF2190ULL, 
            0x3068E6BC5AEBFE9EULL, 0x1BAA294896EC7778ULL, 0xFC635CAEA2E83FB8ULL, 0xBFD749558E6B36FEULL, 
            0x89D15DD77A541155ULL, 0x7C31DF0D21FB8F11ULL, 0x5F6BB4DCB4E38C98ULL, 0x235131BF26AC5C2BULL
        },
        {
            0xC7E8100E14CC9655ULL, 0xFEB9839008ED129FULL, 0x21DCDC4BC41BBA5CULL, 0x66E22112ACF62914ULL, 
            0xE2954F10B6E14B69ULL, 0x9FFF3C725E459D64ULL, 0xC0CD2654D3447F5CULL, 0xF50B618DFE71C9F5ULL, 
            0xC6E606871FD6EED4ULL, 0x32378C89081A4F83ULL, 0xFB12B1BA658DBC0AULL, 0x501CD59BE9604517ULL, 
            0xF34F4CBD31F1BF0AULL, 0x3EF651EAC4300D19ULL, 0x4AE1FAAA68A87385ULL, 0x3720E977723B7736ULL, 
            0x1C4FE1B62B8D636EULL, 0xE662672A3644C84DULL, 0x77251C7078D066BDULL, 0xEF915EA30E435AF0ULL, 
            0xD04E0D2C660B5A6AULL, 0x5213FDF8534A04BCULL, 0x0DFADFB9BC640FAEULL, 0xD1E9A43C0B40FA19ULL, 
            0x3061F9DD3872F800ULL, 0x73BAE6ADCD800C2EULL, 0x6CA9BEC48C662C61ULL, 0x6A277BAA0024B4F5ULL, 
            0x0C81BF9B804E6634ULL, 0xDEED2D7F72F2410AULL, 0xF2697090959F0E62ULL, 0xBD2B966F2E79FB1EULL
        },
        {
            0x982A44569389099FULL, 0x4F5D0AE5A611C81AULL, 0x213AF533AE35967CULL, 0x9A164CBC861E05D9ULL, 
            0x5109CAE3A8889831ULL, 0x4CF1C7F7E7FEA188ULL, 0xF4B5C63E0D1BA512ULL, 0xB831187C912EA8EEULL, 
            0xD03C1D3AAAFDB71DULL, 0x9ACC05931788F0C1ULL, 0x870E4416123FDA45ULL, 0x7ABF9C93BBD41027ULL, 
            0x0DF6D917115531E4ULL, 0x90E476D8541D452BULL, 0x5CDB368C1A7BC071ULL, 0xD522A84D9C5564D0ULL, 
            0x6153417D1FB45378ULL, 0x0806EBAEE5FA591BULL, 0x9DA6DC06ADD46729ULL, 0x4C06BD05A81BB33BULL, 
            0xE78CA75FF423DB71ULL, 0xC72B243B6447906DULL, 0x8D6E2B9FD0EE922AULL, 0x69EA1DB919FC78ABULL, 
            0x9617AB71F51CB905ULL, 0x7AF37FD69272DA3EULL, 0x331D47A7EA0377DFULL, 0x091C3BD4BDF69B23ULL, 
            0xF0E8F134269E8C36ULL, 0x0203A45600CDCDD4ULL, 0xB168CF1EB4773DB9ULL, 0x29542DC762702821ULL
        },
        {
            0xA47FE28CAEBE09B2ULL, 0x64B986268A99126DULL, 0x4808043A846FCC9BULL, 0x340070C6C8FF7F4CULL, 
            0xCE4D90E8718CE34DULL, 0x9C2ED70C768C7DB7ULL, 0x2B4BD6D46192F75AULL, 0xE30E827653519B35ULL, 
            0xBF8E7DFB0AD200CBULL, 0xA9DFBD77D443489FULL, 0x4553FDEB73BAFA0BULL, 0x89E4DDFDCA2E6F31ULL, 
            0xF6DA6B8408CC6BC4ULL, 0x7BD7D838A9D1C155ULL, 0x072F0F132FEF9400ULL, 0x7197BFC02CEE0240ULL, 
            0x3181B091BAB224BCULL, 0x21765B02A0B50084ULL, 0x88C8728274250D8FULL, 0x8508F2B2E6A93A34ULL, 
            0xAD9105AC4D9E2C78ULL, 0xE24F831B3A1037FAULL, 0x5D6D51816AB705ACULL, 0xEDD556DA59664ADFULL, 
            0x7141E4C890CB9506ULL, 0x96818931F9B5B5C4ULL, 0xC8A7601AE6F1BAD2ULL, 0x235029A1F8472D3CULL, 
            0x1FCDB273224C42E6ULL, 0x536B0DE636187888ULL, 0xDE70558ABF52DA7BULL, 0x8A99476F7904F156ULL
        }
    },
    {
        {
            0xCFF5D77171967809ULL, 0x6D533B39F8398523ULL, 0x11DECC6EA49EE8D0ULL, 0x4056987D79C2430BULL, 
            0xE5002F5848B6D64CULL, 0x9B57E88C05CFCCD1ULL, 0x739DFD989A85FB18ULL, 0xE37937888BB35581ULL, 
            0x4510D54A4C1CC375ULL, 0x95CE692FA0DB21E1ULL, 0xD9BF65CE03B45D9DULL, 0xD0B6EAF80A66FCB3ULL, 
            0x186495DA0949857AULL, 0x29405AE137F54438ULL, 0xE93E691890CCD299ULL, 0x8D13A57D64B5CBECULL, 
            0xC8AD7DFB359F06BCULL, 0xAE3E9A77DD83D22EULL, 0xFDC97607B6C034F8ULL, 0x8FF87EF6CB1D9022ULL, 
            0x4D3D2941B88F2BA5ULL, 0x19FE5364E1B1E882ULL, 0x3C52BEF2EE9F3ABBULL, 0x8798EAAC12355957ULL, 
            0x5932846534284CDAULL, 0x9DE0B2BBC4B59C67ULL, 0xDCF29552F9575956ULL, 0xAA783F75800DD727ULL, 
            0xCA9B713DFD3ECFC7ULL, 0x6DD5B335902B8CBDULL, 0x49622A26CAF4AAF8ULL, 0x274DF05B4DD62923ULL
        },
        {
            0x565E0134C1B1494BULL, 0x8944E2CD44A808F4ULL, 0x0B0EE8EE5570C9B6ULL, 0xB0331112F8591188ULL, 
            0x1C60C46DABA55881ULL, 0x1F7D812799F2E6ABULL, 0x41D36BDAF592187EULL, 0xEC1863A6DA52CCBFULL, 
            0x4A829BA4444D89B4ULL, 0xBCC8DC28C71D002EULL, 0x4292AB9B04DC1458ULL, 0x9AA7FC282FA5EA2DULL, 
            0xF2BCC65F8ACAE1F8ULL, 0x897638491AD263D2ULL, 0x99CC03C0D4DE4E6DULL, 0x0C81E5519634580CULL, 
            0xFA4B3C85095E08F7ULL, 0x628CA235329DBB00ULL, 0x8FDCBF4880FFCDEAULL, 0x64690EAF850BFDB6ULL, 
            0x14B4A219BE5F7880ULL, 0x008BA39F339F519DULL, 0xDC51CC7BF5D56537ULL, 0xEE8B8DC7C0E02766ULL, 
            0xEE09FEDB12097778ULL, 0xE72E225A9ED6DDB0ULL, 0x4D0E870CBCC8EBC1ULL, 0x0E11DE7F839BA008ULL, 
            0xAEC34C8EB6D8906DULL, 0xFB0C145D5D7B2B91ULL, 0xE7521DDA7C0D1D2BULL, 0xF02208790F287F4FULL
        },
        {
            0xBDC5A79CE16897F4ULL, 0x470135B8EC0E0953ULL, 0x6FCC18186C15FFDFULL, 0x5A78E5E7956AC95DULL, 
            0xC93FE24924C4BEE9ULL, 0x5AFE321B3810706AULL, 0xE8C94D4294FD7257ULL, 0xDFC41DAADCC99F77ULL, 
            0x6C312866252FAE45ULL, 0xED9038D784F14A20ULL, 0xA999B74C1FA3BF38ULL, 0x249B82E7BCFCA896ULL, 
            0x968F285113EC7BDFULL, 0x987180E0FDDF489EULL, 0xE9D72F53ACC7C12EULL, 0xE19EDCC002ED0692ULL, 
            0xD768C165B98D37AEULL, 0xF375A19D981929DDULL, 0x1954B937C15AE827ULL, 0x4474E129F478922CULL, 
            0x3FA813E15C7A7516ULL, 0xB040CC2B94249D81ULL, 0x6CCFA552F7D62363ULL, 0x2F95D9E1E4DD371DULL, 
            0xB388B06DFB9EE659ULL, 0x541BE0AEF6AD4BD8ULL, 0x372A8A38472E58DCULL, 0xD90F5A5AA88F4960ULL, 
            0xC6AB60A1464FB555ULL, 0x8DFB8735B7A3B783ULL, 0xFFE619CB98C43A04ULL, 0x8CF39E4B4403DD7EULL
        },
        {
            0x66835398EA37C7B6ULL, 0xA602A0917C28A20FULL, 0x9B281BAB1A521372ULL, 0xB8387FE0A8EB306BULL, 
            0xA03A0D2CD1BA9520ULL, 0x7929723EE433B1F1ULL, 0xF567777BEB840FC8ULL, 0x69AE482D9B41836CULL, 
            0xF72B2F4FA79FE42AULL, 0xA10067E630772BA8ULL, 0x42877FE06712B7B8ULL, 0xFAB931437E965EB2ULL, 
            0xD50F5452B5D5F04BULL, 0x81224C33CF28A0D9ULL, 0x067C44D6A7303E65ULL, 0x299831FA7607BFAAULL, 
            0xC485D9A595C51ADFULL, 0x3ED694F6DBBF07C0ULL, 0x297C2D0BDC69DB43ULL, 0x5AE95FA25FFA90B9ULL, 
            0xFA4566354D9C4AD6ULL, 0x96C883289C822601ULL, 0xEDB71473445BCED3ULL, 0x5543E8D20EF3B380ULL, 
            0x3AADDFAED38E5C9AULL, 0x494679CC611E5867ULL, 0x57455722C6EF4419ULL, 0xA1D7C4386A5E0B44ULL, 
            0x66212C255AE4852CULL, 0x2092D9532F3F9DAEULL, 0xF2A17D97632E8A99ULL, 0x844CEEAEA220019CULL
        },
        {
            0xB3B85DCA7222DD7DULL, 0x565D10AE69B332EBULL, 0x77BF88C9747AB01EULL, 0x429DE8A0ACD0A3DCULL, 
            0x93058A9A51EF6C35ULL, 0x2D20C4E9D3231500ULL, 0x380297FFD3203062ULL, 0x76C50864FEEB49F1ULL, 
            0xE3AD6F70D89E3F61ULL, 0x9F6952482C9762F5ULL, 0x0A211B0E355551E8ULL, 0xBE37BCD2C539A883ULL, 
            0xD3172821655EB7D2ULL, 0x26EFEB3F30959AA0ULL, 0xA8D5C9D5DC8DD675ULL, 0xEFAEC803966B8866ULL, 
            0x97602C8F6C88CA31ULL, 0xB65DC504983FD2D7ULL, 0xB1684AC7CB104D06ULL, 0x41C7450A8D561A92ULL, 
            0x7EF71A0422056618ULL, 0x1F4986EAFE3E5C93ULL, 0x4F3F2AE7D75A6839ULL, 0xFAB35B0C16AABA07ULL, 
            0xC45598E3DBB1B3A9ULL, 0xAE12A69870D85166ULL, 0x4095A2EB8E20DC4BULL, 0x08643C9C56D6D686ULL, 
            0x66D01D72BFF17CDEULL, 0x69B3345D10C0A80AULL, 0xC45C9088650F067FULL, 0xD43F0D51F9DCE153ULL
        },
        {
            0x6C1AFCD6142A6C21ULL, 0xC5E09A3B2831C102ULL, 0x31A0C93134E6E757ULL, 0x74D9D9292C855C6DULL, 
            0xC4398FFB755AEECBULL, 0xB4391DD7C8AD27DFULL, 0xF5B453CF10F27E2AULL, 0x8AE3BB2AB4D25B68ULL, 
            0xD485D7F5371181A2ULL, 0x953F093856A64612ULL, 0x46E5D19183B7A3D8ULL, 0xC35193EFA1748B5CULL, 
            0x7B3CCF6FA387A932ULL, 0x91F4A4F1549DEB51ULL, 0x7038D9F56A06A804ULL, 0x8E160CC3C8E75A2CULL, 
            0xF3E83CCBC8824E29ULL, 0x19E2EEF178CC6B41ULL, 0xFF7E7BFC897B6FAFULL, 0xD141D6E60ED366DFULL, 
            0x55870C5A6FC27E45ULL, 0xD33BF3C61ED12BC1ULL, 0x53BC8193EC8AC2BEULL, 0x5ADB05A339C60D22ULL, 
            0xB6B70333D9851523ULL, 0x0F75B0FE9DE382D5ULL, 0x9DF822A8842D54ACULL, 0x1F647BB9E2C2290DULL, 
            0x8265180F04A75EBEULL, 0x938647034ABAA5E7ULL, 0x3F4FECEA9E806B11ULL, 0xE4B3854CC1B85F26ULL
        }
    },
    {
        {
            0xC92A583AE5FEB731ULL, 0x3AE8C86DE6D578CEULL, 0x42882448A327CDDEULL, 0x449D8591DD5DD634ULL, 
            0x856D9DDB5F8B4574ULL, 0x7FE656A7C8D64321ULL, 0xAC9997E3484B8AA1ULL, 0x70DF65FC091D1F11ULL, 
            0xFEF2D8C331C197E4ULL, 0xCE48B5E60A50C01AULL, 0x9000AD7D77189ABCULL, 0x790154BE8DF66379ULL, 
            0xE0276B347B87D283ULL, 0xA5ACDF53DD6F116EULL, 0x8A8034ABB5A4262DULL, 0x98F060C2CAD5D7EFULL, 
            0x3B457A146A9C3FA9ULL, 0xB85A08BEA8484B3FULL, 0x6BCD3E813274E1BEULL, 0x5709D816AEC1017CULL, 
            0x5DF50D3BC3BF881CULL, 0xAD98D17F3A3DC545ULL, 0x8193EBF347501B6EULL, 0xEA1D5011E717C200ULL, 
            0xD9002FA971C970A2ULL, 0xE89AE7F81525DF78ULL, 0x1E298C5CE1275A36ULL, 0xA61ADA50BF37672EULL, 
            0xDFF761805C52FC08ULL, 0x3D1535B0CD56CA8CULL, 0x93717A315AB27D7CULL, 0x1A77B4F671F86ED9ULL
        },
        {
            0xCCB31A4AED5A8F74ULL, 0xB68655B9DFA8A8ADULL, 0x7F94F5EBC1DA98A1ULL, 0xC09BCCE723996B81ULL, 
            0x98FD00EB931102FBULL, 0x89C047A0A1F49B81ULL, 0xB0CA3988CDBB6CB1ULL, 0xF293A7EAAE9EC7E7ULL, 
            0x1022810B450AE6F9ULL, 0x938293B2EBE59841ULL, 0x0DA9FA9A6323E568ULL, 0x23DD4EF24E63B2EBULL, 
            0x288E561098A8382DULL, 0x8D2A4A2ED7C77F93ULL, 0x70C068A7F01C557BULL, 0x454100FBA9B1D0E4ULL, 
            0xC81E085E73C77802ULL, 0xB319F0FAB026A873ULL, 0xF49F3BFD0AFD1378ULL, 0x95C6DBD8255F3D98ULL, 
            0xEB8021604EDC56AEULL, 0xF2774259262D5DE4ULL, 0xDA854481989CCAB5ULL, 0x8AC2AF58684F12ECULL, 
            0x4C69818F50B855D5ULL, 0x8DA4A7901D7DF225ULL, 0xFC68B7F11F1D80A0ULL, 0x57100BAB9A4ADBA9ULL, 
            0x94CA47F8F1A3270AULL, 0x415AFCD198E9AB72ULL, 0x183588DBC08C43DCULL, 0x44FCE9ED2F4C5DE3ULL
        },
        {
            0xF6E07BAEC9C5DA58ULL, 0x0CA4E435659C3268ULL, 0x35B0E6328A7197C0ULL, 0x1D5A88640058B821ULL, 
            0x3751BC81C142E795ULL, 0x16D355E9D68E98E6ULL, 0xE5845A4246013F6EULL, 0xEA61763B43540873ULL, 
            0x035D37437528457EULL, 0xC3B90113A2D507DDULL, 0x972D7AEF210E6418ULL, 0xC2430BF296F8FC55ULL, 
            0xA21A593BD89A79FAULL, 0x2509B5C7F0C10230ULL, 0x19F01587A23E1B4CULL, 0xCDA2E875EA2A0E68ULL, 
            0x7662DE12B89BC60DULL, 0x84A6E17F7CAB706DULL, 0x86B177E0C0B86834ULL, 0xC74D32806F7E2A23ULL, 
            0xCF065489FF2470E4ULL, 0xD5CE515CDEA22DA2ULL, 0xA38622257B2DDDA9ULL, 0xA2A3541355B2FA5EULL, 
            0x8FEDC08C54D7B025ULL, 0x93069045AD07D68DULL, 0x9C95A0B5C13D1330ULL, 0xCC8154949E0E1DF9ULL, 
            0x8F7BACAB3DCD5B7BULL, 0x214531287618FF35ULL, 0x7D049769015126A5ULL, 0x615F87747C98F05CULL
        },
        {
            0x81AFAA4F9D1A7AA9ULL, 0x3DD4E65CE7967212ULL, 0x566D6A8ACF549C72ULL, 0xAF7B0D03BDFCF42AULL, 
            0xFE074FE4792151A7ULL, 0xFC6980F971AA85F5ULL, 0x7ED4E7921D6C4432ULL, 0x2FD8482C10F98B40ULL, 
            0x678BAB8249E9322FULL, 0x01304A0BE6D584FBULL, 0x0A1293A6DF7323BDULL, 0xC1C0B3AE7E7D9DA2ULL, 
            0xB9DA155DC4A0AF21ULL, 0xCA1CF3F0A9268052ULL, 0x1885D90DC36EE2EEULL, 0x021BBFFC29AF88DDULL, 
            0xA72520C8E43E203CULL, 0x808EF2A160409E5DULL, 0xDCA88F981F8D981EULL, 0x11A79130B89DD674ULL, 
            0xEC5DEC503269ECDDULL, 0xC91323412BD8240AULL, 0xEA7F7EC8D87D2DB8ULL, 0x30296D70CBF47EC6ULL, 
            0xDAC82F0030A2B8F6ULL, 0xC76D99B2E297AA49ULL, 0x47F7F9143F73506FULL, 0x87B943820FA8637EULL, 
            0xC5CFA60B0FBF0DB5ULL, 0x729AB2E7035EF398ULL, 0x25D649A6A38CF193ULL, 0xE4BECBA499383CC1ULL
        },
        {
            0x0AF807749F9A5F70ULL, 0xE34CA67B1D19D691ULL, 0x4EDC9D47B5804D65ULL, 0x693E0D698044E676ULL, 
            0x833D046F0F643B21ULL, 0xB9601865B1A85362ULL, 0x14339AD18BEE7F67ULL, 0xF60AF8DAB9CBEBFCULL, 
            0x31B66759DF422387ULL, 0xBF76940AD6E25C67ULL, 0xC76145B8010CD07EULL, 0xA145C946BC38A222ULL, 
            0x9FC243794EAAA3B4ULL, 0xEB00FD5275C71480ULL, 0xA749E13293CC60EEULL, 0x0DD504A34AA13F0FULL, 
            0x34E480E2621C108EULL, 0x8057D3EAB0066253ULL, 0x7CCBC49FBA5513B7ULL, 0x62FC19D914C1122AULL, 
            0x00D03A3ACC7BEDB1ULL, 0xD6AD07EC0DD6A444ULL, 0x0385E3E655B8EA91ULL, 0x8364D5B21455AA43ULL, 
            0x565075CFC7458B92ULL, 0x642D56109D09802EULL, 0xF2B9638B47C3DDBEULL, 0x49C7EC024969AB49ULL, 
            0x43A44899810A0F14ULL, 0x01F2B9070FA85E2AULL, 0xD4BBDC30EF1D762DULL, 0x752A2E2759870111ULL
        },
        {
            0xBC06DF2B48BA4D1BULL, 0x09FF9F8862F88473ULL, 0xC29B9EB93C83A17EULL, 0x6F8C3D057A57261AULL, 
            0xE362FA80BE85A325ULL, 0xB4FE698A427D0D18ULL, 0xCB229C3B27A946F9ULL, 0x7ED08D26F85ECEC2ULL, 
            0x5567EF154EBD2985ULL, 0xBCF982EA439EB530ULL, 0x0221E8B8781A32B9ULL, 0x411D4C3250612717ULL, 
            0xDDCD00EE27C92301ULL, 0xBD49A65BA887BE76ULL, 0xE8876B3745D7EC81ULL, 0xE7BDD2D34661C77FULL, 
            0x0AB3EF7B6C1D1DDDULL, 0x6004771C3A26F35EULL, 0x3DD6CF1CB456359CULL, 0x6B4138462D92D2F6ULL, 
            0xD34DF257A2EA32EEULL, 0x7C78CEFB1B2D7717ULL, 0x1F2ED523722FCCF9ULL, 0x73F2879A64E25B9FULL, 
            0x5060C221C8E2C7C0ULL, 0xBFF56247A92F1EBCULL, 0x093592968F69DDC1ULL, 0x1A55FA2D86C19C0FULL, 
            0x968244366BC83ADAULL, 0x1D80C9CF5DBEF4AFULL, 0x9C055A07FAAD054BULL, 0xB5AFF823BEF0DD16ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Suhail::kPhaseCConstants = {
    0x2F81CBCDB55DECE3ULL,
    0x9137BA0D9747E075ULL,
    0xA0CB5DEF5910081BULL,
    0x2F81CBCDB55DECE3ULL,
    0x9137BA0D9747E075ULL,
    0xA0CB5DEF5910081BULL,
    0xF0B8E944F7CE5584ULL,
    0x6D1E57647455AEB0ULL,
    0xD1,
    0x4E,
    0xA7,
    0x7A,
    0xDA,
    0x35,
    0x31,
    0x39
};

const TwistDomainSaltSet TwistExpander_Suhail::kPhaseDSalts = {
    {
        {
            0xBB32BE9CE883F09CULL, 0xAA5A0B91BA30B9C5ULL, 0xEDEBC3E5397206B4ULL, 0x99A2183CE9E646D6ULL, 
            0xD035C088E683540CULL, 0x98688BC801BB5677ULL, 0x3B6249767BCB4247ULL, 0x3D9DDCB1A68937D1ULL, 
            0xF2B8380AE49A37C7ULL, 0x1849BB0920052EFEULL, 0xBD7B9161C98DCC07ULL, 0x3437F73D02F653AEULL, 
            0xC7D175B695381681ULL, 0xBF201127A01CAB70ULL, 0xFDA8DFCCB7BF81DAULL, 0x499137D9BFFF9D8AULL, 
            0x4246B79D753FB950ULL, 0x698EA18899744342ULL, 0x6DB9CF85BD7ABD58ULL, 0x09FD6B93997281E3ULL, 
            0xEC834A3F8A117F1FULL, 0xEEA1C0613046C70EULL, 0xE563C85391581DCBULL, 0xEAE1B6002164BA25ULL, 
            0xB16BC67FEFE9C4FFULL, 0x62CD0AC6BAA8C7FBULL, 0xFEDBC4453904042DULL, 0x41CD675BC393CD4DULL, 
            0xEB6448915114F41EULL, 0x1EDB69778079B1ECULL, 0xA405AE2DAAE9BAB2ULL, 0xF8BC7070A62B5B1EULL
        },
        {
            0xB489A113C3C0ADAFULL, 0x6E608F09049621AAULL, 0x25A5304986212221ULL, 0xC0740DD4A89AE201ULL, 
            0x35E0A9A2830F1364ULL, 0x0122B37535326C5CULL, 0x37CE607246E1AEB9ULL, 0x2CC4B5B37186B562ULL, 
            0x26C102B5F81104E6ULL, 0xB9FF66BD45EA2C64ULL, 0xE8FF0712DE1FDF38ULL, 0x56555EA96A56E58DULL, 
            0x6B810F61E70B4B29ULL, 0xFE1E174E882C9A4AULL, 0x9ADAC78CEC110F4BULL, 0x1488041E4F146BC3ULL, 
            0xC1208E975E347C52ULL, 0xFCDE8312EEFAEF6FULL, 0xCF92C94BB67E4E81ULL, 0xC24AA6A7122CB91DULL, 
            0xF3A5EC2900C51DCBULL, 0x3AF96447951397CFULL, 0xCEF838C34CC8FCFDULL, 0x2AB4A5E627A36880ULL, 
            0x0296B4CA717EEA19ULL, 0xB1BFA0C471B74A11ULL, 0x182F6C803748A99FULL, 0x3281538BEB11091BULL, 
            0xFF1452E769B97A6EULL, 0xE4AA3C2B0DBCA874ULL, 0x156BA7ED976B7F33ULL, 0x7973C745A3A242F2ULL
        },
        {
            0xF626411097028723ULL, 0xFCB91B17BF8A6438ULL, 0xB1A0AAAF1F8EE739ULL, 0xAA6DD70CDEFF487EULL, 
            0xB155834497146DC7ULL, 0xBE11898F04B696B0ULL, 0x6251DE6C310A4148ULL, 0x4DE59BF5B480D4F7ULL, 
            0x1BBD2F969509B575ULL, 0x605A0C3A2DB227B6ULL, 0xE982864C8E14F4B2ULL, 0x21AD982955E541C6ULL, 
            0xC5AC7039BFF4463CULL, 0x22526F34734239F1ULL, 0xE09158FF93A9370BULL, 0x1B257C975114BB7AULL, 
            0x3B1E7BA803602CA8ULL, 0x855ED8BFF8AFF856ULL, 0xFB0CA97384E4B22AULL, 0x6200AA07AB1CC212ULL, 
            0xA46065BF8C01449BULL, 0xB384AFD31095DA58ULL, 0x1F30A5D45BA8174AULL, 0xFEDF963E3EE0F5BAULL, 
            0x2954C74486F99904ULL, 0xD20CDF06D6371E66ULL, 0xC4490178260B6260ULL, 0x1244F457578DDB79ULL, 
            0xBE1C6600BBFA4721ULL, 0xE218695220E28290ULL, 0x902B661B8949C4B6ULL, 0x467E29368B9E1BECULL
        },
        {
            0xFCE79C5E0FD8EC4CULL, 0xFFC79719116FBD74ULL, 0x107CCA50264E3FF2ULL, 0xD6BC439B4A0BB7D1ULL, 
            0x79F253859FE0B497ULL, 0x5AD25CA39E78D260ULL, 0x18717301FD83DBC8ULL, 0x60D5ACBA28B193F3ULL, 
            0x2F8AC21904CA7DD1ULL, 0x510799445A588872ULL, 0xB28A098132EED90AULL, 0xD48C67ACB3BBA920ULL, 
            0x0E6BB9930458A42AULL, 0x0876124B853BC555ULL, 0xD5507B1A82048A16ULL, 0xF6834A7099846478ULL, 
            0xD077AC555B8CFCB2ULL, 0xB759B9257D8C78B1ULL, 0xDEE1E0913E9CF0C6ULL, 0x1D4C6B2FF4DD1DAFULL, 
            0xB2A0F3179A331357ULL, 0x30BD1298A5394F9DULL, 0x0F22B0CF36A1F4A4ULL, 0x306114212B121F9FULL, 
            0x9A2EE31F12C1537DULL, 0x1B780C43767C7C32ULL, 0xBBD1ECEB71441830ULL, 0xE6F993F9691B4C1EULL, 
            0x8F6758C05E912411ULL, 0xDDC06C9B7B7F7FCCULL, 0xCF0E74E9732C74E6ULL, 0x7EF4E2AB055536C2ULL
        },
        {
            0x165F42343B3A692CULL, 0xDE2FCF00087AD85CULL, 0xAB88C48425F68922ULL, 0x52923780840A77D9ULL, 
            0x49B61025E241C055ULL, 0xFD49E41467BA0034ULL, 0xBAA4311FC1E9DB10ULL, 0x5DCB450D0898FC50ULL, 
            0x62B6FABAA546FE19ULL, 0x7C8F846299BC8F55ULL, 0x5CDDB3E567789A23ULL, 0xC5B38721D783BC72ULL, 
            0xDAF16BE11AC67F55ULL, 0x4A22CCDD6C58F578ULL, 0x435C6D3173090FF0ULL, 0x9047EB5DB83B4B9CULL, 
            0x6954A25D239AC76DULL, 0x76AD20C7DBCAC20AULL, 0xB31E7F23D4874D29ULL, 0xD7E41D2EC7A4D6ACULL, 
            0x45DE610D4759FD48ULL, 0x7A056A02DEA257D5ULL, 0x85C9DD120003E477ULL, 0xE16991E82DDDB839ULL, 
            0xB00E6CFDA437192DULL, 0xE977EB7DBFB1F245ULL, 0x4709B38E1861871AULL, 0x79AC8B31815D84FFULL, 
            0x9D884AADD484F50DULL, 0x4D8F90ACB701A805ULL, 0x72BE93AF7D26D5FFULL, 0xA98DC619AB0A1AF6ULL
        },
        {
            0xAC55A667074D1E0EULL, 0x91B49940EF8AEBACULL, 0x95C0F707047DEF27ULL, 0x21482F5D1C3F0258ULL, 
            0x31292EE3C8C27444ULL, 0xB513EE7065B1CE33ULL, 0xA6DFEFB9D065B592ULL, 0x4FB95389B5E6D9D8ULL, 
            0x42DDA0D07C984F9AULL, 0x71AE7D121205E4ABULL, 0x4BA33E756BA17108ULL, 0xDCF6A8CC4632EB68ULL, 
            0xC2BBEEB2DBDE9020ULL, 0x5F9519E85CE88D0BULL, 0x4F711EFDBD5D693CULL, 0xA767D9D36119F881ULL, 
            0x1345216E5F6F4A4CULL, 0x692D1A27530EB255ULL, 0x9021C360D21CCDE1ULL, 0xC4AB8F81E25A955DULL, 
            0xD20B94641E42A2F6ULL, 0xBD0D84860D7AE2FAULL, 0xB21A92E9F51C68D8ULL, 0x0DA314F6C99D5B48ULL, 
            0xA142153EAC13E53FULL, 0x956479D929C22D5DULL, 0xBC113C7D9618A806ULL, 0xFABC56854DABB019ULL, 
            0x8FEC7BF2C03DA910ULL, 0xC0D351159251A6E3ULL, 0x54329B8D58CD8BA8ULL, 0xDE59BE278A3EEDD8ULL
        }
    },
    {
        {
            0xE8C51D540A6FDB3DULL, 0x3F31C0FEA6C66AF2ULL, 0xDA196B5909D5A8CBULL, 0x410D69BD33FB8F46ULL, 
            0x3EB014EDC317861BULL, 0xFC12A560C0288E5BULL, 0x549C19E048492B5BULL, 0x073B25A50ADA5FEEULL, 
            0x4E9439272043C82BULL, 0xCCC714275881A156ULL, 0x04048EB209DF0B5EULL, 0x6838CB44D42672F4ULL, 
            0x0B6082F9B927DCE6ULL, 0xF18C30E78043E38CULL, 0xBA807F8E4C1EEF63ULL, 0x4E2949D56FFC94F1ULL, 
            0x6EA1E2319E1EC63FULL, 0x3DB2F33E944FDF1DULL, 0x15D36C2BA6602E24ULL, 0x8531641BEE486885ULL, 
            0xDE120FF5B5B9E89CULL, 0x599DD49655D70E1DULL, 0x4CA217CB7D0D7CDAULL, 0x840DB76BE21CA4CAULL, 
            0xB0804E687BE86C3DULL, 0x453E268151DB9AA5ULL, 0x580693F5CC068621ULL, 0xB531A13DBA2CA3A3ULL, 
            0xAC1EE9A969D5EA5FULL, 0x4C7214F70BBE2871ULL, 0x058BD3BAF59DCD8BULL, 0xD68F44A4D101703BULL
        },
        {
            0xD12DDD80A7D52CDDULL, 0x68D3523DF061E011ULL, 0x9126489778FB6322ULL, 0x0F96AAA5DA50D898ULL, 
            0x4665BB7448871A8FULL, 0x17C54C73EAB1DA06ULL, 0x8F4541A249307124ULL, 0x1E333174E4A19A6CULL, 
            0x7EA5822B27DFF415ULL, 0x8CFCA372C57EE24BULL, 0x4AB9C38FB1762479ULL, 0x0000C8ABD797502FULL, 
            0x416B196679738E2FULL, 0x344BF104DC6EAA00ULL, 0x3F7182BFD27617DAULL, 0x47DF586D252798F8ULL, 
            0x988F6D99044C1CE0ULL, 0xFF0075749FBC2D2AULL, 0x73CE3F66E2E352E1ULL, 0x4FA16E478B1CD177ULL, 
            0xCCA13FD08DDA720AULL, 0x3EB787AA73AF07C4ULL, 0x2F07EB75E70AD8DEULL, 0x12BD6A1F05CCB241ULL, 
            0x000BF6ACC119C782ULL, 0x8CFECE1411277F1CULL, 0xDF9B7819C47F3760ULL, 0x989B6138EB7D427CULL, 
            0xA30BE82305FB4ACAULL, 0x10A9DC03BA6CDF1DULL, 0x8B9040E082AD1310ULL, 0xF23DAC3D0B3685E4ULL
        },
        {
            0x35F906EF4CA0F7ADULL, 0x39E1541C3026400CULL, 0x64F131551544451FULL, 0x3156F81364B7625AULL, 
            0x8E11FB083114E241ULL, 0xE1F094F2687B610FULL, 0x2595BF02A632373BULL, 0x932C0F1190485B13ULL, 
            0x0453A56A6B096391ULL, 0x3181F3897596EAE2ULL, 0x5DB602A6B54525F9ULL, 0x3B8C9365B0C1DD74ULL, 
            0x5E9736AC868D7103ULL, 0x8A710F044C4DC540ULL, 0xF745712D8634CCF8ULL, 0x3D5E1A5C68DB5305ULL, 
            0xDD907F7DFF4CB150ULL, 0x4F4DDF637365C84AULL, 0xAA07510FEC627C28ULL, 0x6916D414187D9EB3ULL, 
            0x4833936BFF1D2A56ULL, 0x4A655D45A489DAA9ULL, 0x0512A6CCFBD2384AULL, 0xEA9CC2C8E8AB338BULL, 
            0x7C945B0A88EF62FAULL, 0x7223FCC59AD21916ULL, 0xA0613C2AAD3663F9ULL, 0x703E3D60598E90C9ULL, 
            0xA201802AFF590406ULL, 0x66454FB3209E4DEBULL, 0x58A85A5C9DFA9E91ULL, 0xF3D3F2D241401442ULL
        },
        {
            0xDE012E450E611B45ULL, 0x75EB79E11C659FDCULL, 0x61A912A4DF9799C4ULL, 0x6D0521544C0E06FEULL, 
            0x5C626D3D3D186071ULL, 0xC2F80563908769EFULL, 0xD5EC3AC566DEE4E7ULL, 0x48D21D5394CEB91DULL, 
            0xA135D7C616B42BE4ULL, 0xCB92EEDFF340C598ULL, 0xC3C0B1C5FCF333A7ULL, 0x9DFAE15BC2408E87ULL, 
            0xC57EEA13FEE3E4A4ULL, 0x84CB8D8E9FF5E119ULL, 0xE1FF406B855CF558ULL, 0xAA6285E1138685B0ULL, 
            0xA3EA2E6A91E47758ULL, 0xC680854B3CFD9068ULL, 0x5B6E55F82A2643B5ULL, 0xE5414DCC3F8F4E2EULL, 
            0xB4A476DE25477E8FULL, 0x8A275B24A457FE1CULL, 0xC2BAF4A4D1172D14ULL, 0xFF12D56E9B257A66ULL, 
            0x2B7F184B4E5E9A3AULL, 0xB3E18AFBFCC1D658ULL, 0x76FB33B4FBF513B4ULL, 0xF99D83ADE43A6710ULL, 
            0xB737CB111AE9C045ULL, 0xCC58DBCA40D93BACULL, 0x813459BB65E31A3BULL, 0xC047EBEE902B537AULL
        },
        {
            0xEA1BA3A6807C8CF5ULL, 0x00B6E68D7A5DE4C6ULL, 0xD76C8653FAA423F9ULL, 0x2114FE6D4ED0AD4AULL, 
            0x3A5037776CC8B1E8ULL, 0x29FE798C422BFD5EULL, 0xAAD58805035AC52EULL, 0xDB053E3A1B3E72D4ULL, 
            0x21D500F477F0E0EDULL, 0xD880B4E1ECAA73EFULL, 0x05910E1EFA359E94ULL, 0x7A89ECACD88625A2ULL, 
            0x0989DB45C6236DA8ULL, 0x2A7C47D047FEBB63ULL, 0xFBD5CE2ABB381B81ULL, 0xD83AD067593A3338ULL, 
            0x8D0ED2B45B13177EULL, 0x32F3F7F11FB33B51ULL, 0xA715065CF86E36B0ULL, 0x3BF645FE0379E7B4ULL, 
            0xA378900ADADC5632ULL, 0xEFBBC0AC1391451CULL, 0x40AF087A6ACD5686ULL, 0xDA087ADB1279E028ULL, 
            0x96F2312ADB6A417AULL, 0x31EEEAEF77953A8AULL, 0x4BEC2001C7B11184ULL, 0xD140EFC5B68B7ABAULL, 
            0x77A14B751B996026ULL, 0xFDF51D39C4237FCBULL, 0xED7B37A0D592C66FULL, 0xD9A2DF66E2B6D671ULL
        },
        {
            0x2DF60AEF4F121860ULL, 0x3538486F84C39CB8ULL, 0x4AF072958798B7B2ULL, 0x4D6463ADAB5A82ECULL, 
            0x602B8D0E72457DC0ULL, 0xCCFCAD4490C40017ULL, 0x8A0A4EE5A2063DAEULL, 0x54C35E3B3A1AFB1CULL, 
            0x92D7E8B17FAB1840ULL, 0x8EDE4BCF452FD67FULL, 0xC76B632794E6C150ULL, 0x372236DA99116C64ULL, 
            0x784B76475AEC5E23ULL, 0x6D583C97DBE5A86FULL, 0x6101AD83101323BFULL, 0x66A3C7FCC7FCD457ULL, 
            0xE353B442CFF335ACULL, 0xFF73D33886317631ULL, 0x8276E04C61F0E284ULL, 0x78E76F9EB293B5FCULL, 
            0xE89388771A0C86BFULL, 0x292BCC634FA0E640ULL, 0x00C27985586F3D1FULL, 0x755E1423D327F32BULL, 
            0x0CDEF8A5D570130CULL, 0x6A7AB0EB0032922AULL, 0x2A25B606237C4539ULL, 0x5F13C301A2E8CAE6ULL, 
            0xF9878D3138841CBAULL, 0xD616DD3D4E6C7DDFULL, 0x5BD3A3FBD8BC96B6ULL, 0x221789635CB839EAULL
        }
    },
    {
        {
            0x9F0A384ECAF1AA30ULL, 0xEC95FC3DE4212DF7ULL, 0xEB4716FE877F7F0EULL, 0x4F4B4B97087E6899ULL, 
            0x941EB9AE7031F7B1ULL, 0x00A77982D95B4D2AULL, 0x11BA71C3DB1443C8ULL, 0x5BEAE1B9B04F8333ULL, 
            0x4EB9B3FFAB957097ULL, 0xA799DAD33724B172ULL, 0xB07188ED2E389319ULL, 0x8C2007120CB40D6EULL, 
            0xD368817629939573ULL, 0xB59D8952573B12CAULL, 0xB1DD63D1BA3E98AEULL, 0x8809E43B8669B676ULL, 
            0xDB93DC5CA9483276ULL, 0x540B07A405536205ULL, 0xDA2E19A53512D41FULL, 0x3FE3613CD5F1DE7EULL, 
            0xB75981E6EE125D8BULL, 0x6738A9889CBBCF75ULL, 0xB2EDF7D8DD110F8DULL, 0x3796FA6DD7F254FCULL, 
            0x23C93A66AAF1B56DULL, 0x4A4BDECCFABC49D0ULL, 0xC7925B3F67B7BC5DULL, 0x78A35E83AFFE8014ULL, 
            0x295E4406B62785DCULL, 0x4ECCCFEACA3BD787ULL, 0x0F58E79C611DCE42ULL, 0x332468F136240B5FULL
        },
        {
            0x732CF92BE717F8CFULL, 0x82727586E199C307ULL, 0x76CE991A9D7B7F2DULL, 0x2FD7FECD6CB9D692ULL, 
            0x3C94B5472F4DEDD9ULL, 0x9048FFF252A45DCDULL, 0x540B5CAC51794B65ULL, 0x26748033713599B6ULL, 
            0x5CB8A189BA0DBDDDULL, 0x30BDF5F9A51FA0CFULL, 0x2DDD4DC6666C2F00ULL, 0x5CFFA2B74847834AULL, 
            0xD4CB8C9FB8FADDBBULL, 0x0F08FD113AA062B9ULL, 0x52F5854BE7EEC087ULL, 0xCE375293D1372C4DULL, 
            0x872EFF81635688C2ULL, 0x71D8C7C13E8E0B35ULL, 0x7D785550C83607BFULL, 0xB5983209A902A996ULL, 
            0x8566E9D689D9034BULL, 0xD6B749E9A2470BBDULL, 0xCC9AC880789A7CFBULL, 0x402C72C0A58324C6ULL, 
            0x06C3F8E1B5AE0D6BULL, 0xAFDD909C389D5B10ULL, 0x5094D020C178E58FULL, 0x21141C47EB17731AULL, 
            0x00BBAE6A3545282EULL, 0x2CF3E275BEA192D6ULL, 0x7887A0E3A2E9BD61ULL, 0x792F3C7840D38919ULL
        },
        {
            0xFB9A5D63CDF27C78ULL, 0x8B5C568D5C567F90ULL, 0x33CCC57771793AD6ULL, 0xDC9AB0C0BD5EBE75ULL, 
            0xC158190746AF3CC2ULL, 0xABD216AB0F46F3DFULL, 0x7F3AFF24D1DCA51FULL, 0x01D1939AE0413038ULL, 
            0xFA3A3443EF5BDFE7ULL, 0xB2A98212E2742D90ULL, 0xE5AE4ED910382997ULL, 0x2384F3D9332D7A5EULL, 
            0x21BD5EB917F46AF7ULL, 0x229B7EEBBDA310B9ULL, 0x4D29BEC3A04BE853ULL, 0x3AE52F93808033E4ULL, 
            0x12F951483057ABAFULL, 0x9214F2492367EE7FULL, 0x30C479CF5B97ADA2ULL, 0x4BBB9A87D447F5FFULL, 
            0xBF2817ACFFDDA66EULL, 0x0B4D46C384436B95ULL, 0x7775926D820C5030ULL, 0x6584A7F38F369B4EULL, 
            0x3C57D403860FC5E9ULL, 0x39D5FDE3A9F6145AULL, 0x738D121FA78FFC82ULL, 0x8C277C16985A3F88ULL, 
            0x9DEA8C932B8D17BDULL, 0x77C50278F8C3F885ULL, 0x0B4783B8DD480ECAULL, 0x62980B44201D6715ULL
        },
        {
            0x0C7E9C1803D34C42ULL, 0xC31041A6CC3E37A0ULL, 0xED677733E9ADF432ULL, 0xD195D876D04C1B2DULL, 
            0x16B079EEE641B993ULL, 0x565AC903C8BFF9A7ULL, 0xA54ADCD5925105FAULL, 0xBDE7FF2741C677C7ULL, 
            0xE44D3B6325836B2FULL, 0xE8A24603D821175AULL, 0xAA7981E066B04BE0ULL, 0x16DEA4A08730DE33ULL, 
            0x10C77CD2CE756734ULL, 0xD8D3244833877B3BULL, 0x6EF545A9B1978067ULL, 0x988358AF4EDDD80EULL, 
            0x89F724AF6A605AE7ULL, 0xDDAA3FD2D570E853ULL, 0x86690F407082388BULL, 0x4421AFEAFB25C9D4ULL, 
            0xC78BB2EC4725A412ULL, 0xF4A1F4BF898C76A3ULL, 0xBF2FE89A42A0056BULL, 0xB8A29AF0F74BD9CAULL, 
            0x2D8EE1ABC00AB7AAULL, 0xA33269802AEA3576ULL, 0x6F465B241BD593FBULL, 0x5C9EEB11E76F6ACBULL, 
            0x8820138E3F545CCDULL, 0xEED536A35DBBE8A6ULL, 0xD2BC110828B33247ULL, 0x120E16E1C5AAAC2FULL
        },
        {
            0x8713777880DA0496ULL, 0x109AFBAF02BFDFCFULL, 0xA64142C57E57A143ULL, 0x0D2DA4DB1C5EFB55ULL, 
            0x4DF91D659A175DA1ULL, 0xDAC41AC6F1BCCFA4ULL, 0xE1E4E10FDCE572F3ULL, 0x359CFC74CBEA3AA9ULL, 
            0x4F10B25617D939DFULL, 0xC1476EA52FD51777ULL, 0xE73E3BAA3E1749D2ULL, 0x74F39FA4FE7FC55AULL, 
            0xAE8A337458B3942DULL, 0x7E0B22D78F2765D7ULL, 0x5381A457F72B6C22ULL, 0x0D5C1DD4695E4EFCULL, 
            0xB4B88A70C96CB1E9ULL, 0x3772791BBD2C4CE9ULL, 0xA5DE8F1CDA03109CULL, 0xABFFE43898D4993DULL, 
            0x9E1AB85B062FF76AULL, 0xE55542AC674C5577ULL, 0x35068C51D13BC0BCULL, 0xD752032C23BEC54AULL, 
            0xACFF1639E78B4877ULL, 0xC51EE80A905DB4D0ULL, 0x6C6CA64267699129ULL, 0x9BA46C1C2255ADE1ULL, 
            0x385A3C7C94FB74ADULL, 0x8CA2442BE4DAF0EDULL, 0x0092AF88C6E19A61ULL, 0x18AD16575C24CE06ULL
        },
        {
            0x528AFE10E9FCE0A4ULL, 0x101173F01BE75D6CULL, 0xA172DA4B5CBD77AFULL, 0x219F75338C60D9EDULL, 
            0x1DE59F16EA6F65AEULL, 0x18484C80176F3734ULL, 0x49A6C44850ED94DDULL, 0xC42F1EC2C7E74BC7ULL, 
            0x1A7470B1050323C0ULL, 0x2B841E9BF803CD4FULL, 0x4905B5026476C535ULL, 0x634BAD49F308B006ULL, 
            0x7DD9A0B60101770CULL, 0xB8F691828636F107ULL, 0x1FD2F51D953204DDULL, 0xD5898D058CE78163ULL, 
            0xBF40C28A4168E182ULL, 0x831BCFB4233E69E1ULL, 0x28B9652CF3690801ULL, 0xB8E1FA7E5BF7D52EULL, 
            0x59021D970686C99AULL, 0xA6FBBCEC134E0001ULL, 0x48727BEE78759F2EULL, 0x56565A1E93E8127DULL, 
            0xBE97640093A8CC65ULL, 0x731D7DCC021D80F0ULL, 0xF1E66BFC8B1D6E63ULL, 0xF07CE369F48420A4ULL, 
            0x0FD709B60FD274C0ULL, 0x243A0E6335A14D02ULL, 0x6EF93AD06C034A65ULL, 0x38037D0129522F06ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Suhail::kPhaseDConstants = {
    0xC6C8FFDC2FF03866ULL,
    0xE1BD3CD22DD8F42AULL,
    0x368246422B8CDB12ULL,
    0xC6C8FFDC2FF03866ULL,
    0xE1BD3CD22DD8F42AULL,
    0x368246422B8CDB12ULL,
    0x99752F303DEBB40DULL,
    0x07CCF439E93EB679ULL,
    0x68,
    0x5F,
    0x80,
    0x54,
    0x33,
    0xA6,
    0xEC,
    0x63
};

