#include "TwistExpander_Menkent.hpp"
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

TwistExpander_Menkent::TwistExpander_Menkent()
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

void TwistExpander_Menkent::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xBB3FBD3537BFADCFULL; std::uint64_t aIngress = 0xF9EF8427F8824115ULL; std::uint64_t aCarry = 0xF2FE247A530CD751ULL;

    std::uint64_t aWandererA = 0xB7ED1781A07F1BC0ULL; std::uint64_t aWandererB = 0xACF316703BDC21A5ULL; std::uint64_t aWandererC = 0xFA5336162D54C13FULL; std::uint64_t aWandererD = 0x8FAB220A154BF500ULL;
    std::uint64_t aWandererE = 0xF675F6877A6ED1B9ULL; std::uint64_t aWandererF = 0xFF46EA3C456BA31AULL; std::uint64_t aWandererG = 0xF5998548190E27B9ULL; std::uint64_t aWandererH = 0xB7DE3AA0322874FBULL;
    std::uint64_t aWandererI = 0xFA1DB0C5BFB8A538ULL; std::uint64_t aWandererJ = 0xDB4E0374C1E79F25ULL; std::uint64_t aWandererK = 0xE626B853BBC1C119ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xDABE6744B97D04A8ULL;
        aCarry = 0xB0D41DF097BBFC38ULL;
        aWandererA = 0xCEBF9FA169A81397ULL;
        aWandererB = 0xB9086D6CBBCE932AULL;
        aWandererC = 0x90736A7153386C2CULL;
        aWandererD = 0xFEC84FDCBA1C7FD4ULL;
        aWandererE = 0xC2A65728EF3004D0ULL;
        aWandererF = 0x923B60F716109CADULL;
        aWandererG = 0xCD7FBE534B26444FULL;
        aWandererH = 0xB6417C93DB71C0D7ULL;
        aWandererI = 0x897367B6F4D5A72DULL;
        aWandererJ = 0xCF25D00E9F0C5066ULL;
        aWandererK = 0x9F799415A05D9BDBULL;
    TwistExpander_Menkent_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Menkent_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Menkent_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Menkent_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Menkent::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA3A042A6C7C49015ULL; std::uint64_t aIngress = 0xEEF878A853075C72ULL; std::uint64_t aCarry = 0xE41891EB2EC798C4ULL;

    std::uint64_t aWandererA = 0xFA0294C9F4CED83DULL; std::uint64_t aWandererB = 0xB779FDDCA12FC29BULL; std::uint64_t aWandererC = 0xC925185CBED71C1CULL; std::uint64_t aWandererD = 0xE134958A6E7A501BULL;
    std::uint64_t aWandererE = 0xE96A788C6739029DULL; std::uint64_t aWandererF = 0x95E9A6F4485C495EULL; std::uint64_t aWandererG = 0xE5E8BD5DFB8CC1BCULL; std::uint64_t aWandererH = 0xEA536A5847D72B4EULL;
    std::uint64_t aWandererI = 0xA7F0209101025A0BULL; std::uint64_t aWandererJ = 0xEC84157EADE32A49ULL; std::uint64_t aWandererK = 0x932615A7364EB93DULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xBCF7EE4D3F3C1327ULL;
        aCarry = 0xAB3A4F1725B11129ULL;
        aWandererA = 0x8654EEF8743EE246ULL;
        aWandererB = 0xB3DCE76AB082280FULL;
        aWandererC = 0x8BBC5AA762C8DA62ULL;
        aWandererD = 0xBDD10A875F025CDBULL;
        aWandererE = 0xBA9D3E6900C71297ULL;
        aWandererF = 0x99919DE36C4C8C21ULL;
        aWandererG = 0x829A0BBB3EBD7781ULL;
        aWandererH = 0xD5C52B4C96E524A0ULL;
        aWandererI = 0xF9B1A85F26B4A883ULL;
        aWandererJ = 0x935DC0D2B00F915BULL;
        aWandererK = 0x83F5BF74DDE1C108ULL;
    TwistExpander_Menkent_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Menkent_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Menkent_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Menkent_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Menkent::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE13852114B0107A0ULL;
    std::uint64_t aIngress = 0xF334F5871C29E9BBULL;
    std::uint64_t aCarry = 0xA1EC9B31A300701CULL;

    std::uint64_t aWandererA = 0xA5497A6C61777517ULL;
    std::uint64_t aWandererB = 0xEE4B9D2F1AC61323ULL;
    std::uint64_t aWandererC = 0xC2B1EB0BF0651F3BULL;
    std::uint64_t aWandererD = 0xBCB3F965CEE89A2EULL;
    std::uint64_t aWandererE = 0xF4289C17BC58DBA4ULL;
    std::uint64_t aWandererF = 0x9ECB05568CE62CC2ULL;
    std::uint64_t aWandererG = 0xD3200DAC44F2F01BULL;
    std::uint64_t aWandererH = 0xB7BD93B32D14FE23ULL;
    std::uint64_t aWandererI = 0xC9A94393F1D2829AULL;
    std::uint64_t aWandererJ = 0x9902035F348B7876ULL;
    std::uint64_t aWandererK = 0x90DC3B3EC1D3FAEDULL;

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
        TwistSquash::SquashC(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, aIceLaneD);
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
    TwistExpander_Menkent_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Menkent_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Menkent_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Menkent_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Menkent_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Menkent_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Menkent_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Menkent_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Menkent_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Menkent_Arx::GROW_B(pWorkSpace,
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

// SmartSquash candidate 18 of 33
// Exploration cases: 100000000
// Nearest-family diversity: 908 / 1088 (83.46%)
// Total distance from earlier candidates: 15726
void TwistExpander_Menkent::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    static_assert((S_BLOCK / W_KEY) == 16, "SquashInvestToKeyBoxes expects 16 invest fragments.");
    static_assert(H_KEY == 8, "SquashInvestToKeyBoxes expects 8 key rows per box.");
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 9U), *aFragmentB = aIceLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 2U), *aFragmentD = aIceLaneD + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 274U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 859U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 657U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1363U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 12U), *aFragmentB = aIceLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 15U), *aFragmentD = aIceLaneD + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1464U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 679U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 132U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 134U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 13U), *aFragmentB = aIceLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 7U), *aFragmentD = aIceLaneD + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 998U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 671U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 628U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 356U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 8U), *aFragmentB = aIceLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 6U), *aFragmentD = aIceLaneD + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1523U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1412U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 694U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1593U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 10U), *aFragmentB = aIceLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 13U), *aFragmentD = aIceLaneD + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 882U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 555U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 717U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 32U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 3U), *aFragmentB = aIceLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 8U), *aFragmentD = aIceLaneD + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1239U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 696U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1668U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1353U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 6U), *aFragmentB = aIceLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 3U), *aFragmentD = aIceLaneD + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1674U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 665U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 500U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1856U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 5U), *aFragmentB = aIceLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 4U), *aFragmentD = aIceLaneD + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 115U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 205U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1573U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 341U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 2U), *aFragmentB = aIceLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 10U), *aFragmentD = aIceLaneD + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 603U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1128U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 389U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 52U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 4U), *aFragmentB = aIceLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 1U), *aFragmentD = aIceLaneD + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1817U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1792U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 852U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 122U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 7U), *aFragmentB = aIceLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 14U), *aFragmentD = aIceLaneD + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 790U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 894U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1551U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 732U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 11U), *aFragmentB = aIceLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 9U), *aFragmentD = aIceLaneD + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 958U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 146U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 211U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1873U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 1U), *aFragmentB = aIceLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 5U), *aFragmentD = aIceLaneD + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1465U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1304U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 10U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 359U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 0U), *aFragmentB = aIceLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 11U), *aFragmentD = aIceLaneD + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1925U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1821U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 81U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 236U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 15U), *aFragmentB = aIceLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 12U), *aFragmentD = aIceLaneD + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 199U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1818U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 31U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 2035U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 14U), *aFragmentB = aIceLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 0U), *aFragmentD = aIceLaneD + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1048U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1887U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 203U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 16U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Menkent::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xAD6DD514D06A72D3ULL; std::uint64_t aIngress = 0x9C6720413AF917E6ULL; std::uint64_t aCarry = 0x968D3BB80E8BAB28ULL;

    std::uint64_t aWandererA = 0xA47D33A2B8F577F8ULL; std::uint64_t aWandererB = 0xF36DD32C45D2A9AEULL; std::uint64_t aWandererC = 0xE42D639FEF5A48B8ULL; std::uint64_t aWandererD = 0x9B4DFDCA0A9F3DACULL;
    std::uint64_t aWandererE = 0x8D75E2EC7E4A8F1CULL; std::uint64_t aWandererF = 0xA0653169FA45F13AULL; std::uint64_t aWandererG = 0xDE46759AC471A113ULL; std::uint64_t aWandererH = 0xD53BA656E409472FULL;
    std::uint64_t aWandererI = 0xD3D1562EDF8C2EA3ULL; std::uint64_t aWandererJ = 0xD2177C331AE70237ULL; std::uint64_t aWandererK = 0xDEB1459CF14A6326ULL;

    // [seed]
        aPrevious = 0xB1E8105C315F4226ULL;
        aCarry = 0x8072C694B7124799ULL;
        aWandererA = 0x93A8083413EB1176ULL;
        aWandererB = 0xB5D2A15F815D9042ULL;
        aWandererC = 0xC285A77ADABE7A32ULL;
        aWandererD = 0x8AFE46C8789EE3EEULL;
        aWandererE = 0xB41D8A3CD65A8E95ULL;
        aWandererF = 0xC1642B06F4A595C6ULL;
        aWandererG = 0xB19852D1E2493F76ULL;
        aWandererH = 0x9FDC4727D3862F79ULL;
        aWandererI = 0xC6F5F672CB08EA30ULL;
        aWandererJ = 0xB44E53579ECB435FULL;
        aWandererK = 0xC0D8DB33A8773D89ULL;
    TwistExpander_Menkent_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Menkent_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Menkent_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Menkent_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Menkent_Arx::Twist_E(pWorkSpace,
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
    TwistExpander_Menkent_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Menkent_Arx::GROW_B(pWorkSpace,
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

// GrowA candidate 18 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 9274; nearest pair: 495 / 674
void TwistExpander_Menkent::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7889U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3062U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 19U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7776U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2756U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6982U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4977U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6086U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2195U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1293U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4627U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 988U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3605U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3911U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1195U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4422U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 797U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1456U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1538U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 670U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1591U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1712U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1009U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 774U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1717U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 455U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 966U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 156U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 509U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1288U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 997U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 880U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1886U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 612U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1768U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1034U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
}

// GrowB candidate 18 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 9271; nearest pair: 475 / 674
void TwistExpander_Menkent::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1093U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6844U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2496U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2474U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 112U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7317U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2271U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5297U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3841U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7298U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3334U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7471U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1715U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6897U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6538U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1874U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1914U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1267U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1657U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1870U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1484U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1168U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 606U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1573U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1753U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 203U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 333U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1055U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1835U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1734U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1238U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1618U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1913U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 612U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1956U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1176U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
}

const TwistDomainSaltSet TwistExpander_Menkent::kPhaseASalts = {
    {
        {
            0x922F003B257CECF7ULL, 0xEC11E8BB59EE670CULL, 0x2D1AF792C3C7480AULL, 0x4CC84EFCBD28692AULL, 
            0x54AF233E932E1E58ULL, 0xB6704FC26CE911ADULL, 0x6F84A131CF5D00E0ULL, 0xE456F824CF6FF57EULL, 
            0x5F44526F18EB9997ULL, 0xDACE59D43F23C467ULL, 0xABE9827F31A1C8A0ULL, 0xDB8C495F05E86559ULL, 
            0xDADBC7B93A2B905FULL, 0xD432E77E0BAF5B8BULL, 0xAC557F88E1215918ULL, 0xC20C08F340C4DB1CULL, 
            0xBB595AE7CA1303F9ULL, 0xEF795041BDCCE34DULL, 0x11684838131D73FEULL, 0x197ADA6C6CD93D3BULL, 
            0x1C0F479647872F86ULL, 0x799E818614C40540ULL, 0xB060D8896B8A0EA0ULL, 0x91AB4ABE5490A5EAULL, 
            0x9C59FC0FDB276526ULL, 0xDB4BCAB7CF416538ULL, 0xBBDF3FAD9FEDD5D3ULL, 0x471EAAD29619D36EULL, 
            0x032B84A2C478297EULL, 0xC40128F0E9279164ULL, 0x232AD3845C7ED071ULL, 0xB9A4D6B692C191D1ULL
        },
        {
            0x281536F2EF581FB2ULL, 0xBB577DA4CFFE1E76ULL, 0x38C0203EBCB52E08ULL, 0x3EAD3FA5BF6F2A8FULL, 
            0x016FED4D173E043CULL, 0x4C8030FABFA9CEBEULL, 0x93FF933E8B2A20FCULL, 0x2C1A8CDAEFAC7AD0ULL, 
            0xBEAF43D8171CE466ULL, 0xDB0E557CF7CA0977ULL, 0x1AD771420AF08F4CULL, 0x7D13D698F9977A0FULL, 
            0x9C76E0CB174400F1ULL, 0xC0A00FE0ADECF3BAULL, 0xC5ABCB07699AA1B3ULL, 0xB8771671445553B6ULL, 
            0x482065D5CEAD0A0FULL, 0xB80E4FF3EAEC44A1ULL, 0x86ECAC8456B9721AULL, 0xB30A5BFB670145AEULL, 
            0x5A9DBFA4E80B3C60ULL, 0x16E2FE0315231E9BULL, 0x49072B10FA6D69C5ULL, 0x330FE232CE165AB7ULL, 
            0x6C7A597152A29E59ULL, 0xE5C9A548AA287657ULL, 0xEBDCB10B087555DDULL, 0x2718DC097378C127ULL, 
            0xB73E872F5EAA2746ULL, 0x275A80C19593DE1CULL, 0xD2D32BD9717946ECULL, 0x46969F0C2BBA743AULL
        },
        {
            0xF76F6770E857AB2BULL, 0xC9BCD1FFF6456D3CULL, 0x22AFFF3BCA6ACECBULL, 0x88487C08AD1DDD8AULL, 
            0xD9FB1643AAD2DDA5ULL, 0xD2BEAD06E8B04D59ULL, 0x65F92ACC54DF856CULL, 0x092D0237A2A0BDE7ULL, 
            0x4CCAF52FD0F521A2ULL, 0x223C2AB2999902D4ULL, 0xEAD8C8AA5620A025ULL, 0x4E1EEF6C0779ADFAULL, 
            0xAE1A7D12C0FDDD02ULL, 0x9B01C091F2C25947ULL, 0xEC210BB1EF69CEC6ULL, 0xA490A9CCF99E930AULL, 
            0x36C419A6530BAE66ULL, 0x86B8FC9858F6167FULL, 0xC402002DB64D1687ULL, 0x29599A9B3A896475ULL, 
            0x9BDEF4A1CDE2780FULL, 0x0DA2F69E18E9B1E1ULL, 0x3426962E9A09FC2CULL, 0x6BC50303A65BB77CULL, 
            0x35C16721889F8DCAULL, 0x3024BC7A231B9014ULL, 0x434D85D5396CB103ULL, 0xBE3127018B215F74ULL, 
            0x25D69477FABCEF99ULL, 0xB8E956445846DE39ULL, 0xF4D6E19934C29401ULL, 0xCD012FF42069CC9AULL
        },
        {
            0x5A17DBC644416916ULL, 0xC17D50ED5632CAF7ULL, 0x9BCF4D7F4516CA4FULL, 0x3966CAD7532B2FA0ULL, 
            0x24EBA8865C239337ULL, 0x35E851106C02528DULL, 0xA417B359579D618FULL, 0xC3D569FBACC9274AULL, 
            0x775778FCDFACDAF1ULL, 0x900A7E72F6472B6AULL, 0xEE811D9BDE34D475ULL, 0x96B0C99745C6867EULL, 
            0xF8AB927481540102ULL, 0x1F56F3628A91ABA2ULL, 0x054644856EEC909CULL, 0x99936BA6792122A8ULL, 
            0x6BE9051E88B4D592ULL, 0xA403455FC46263CFULL, 0x71217F65C45F473CULL, 0x4D886D85956B8E5FULL, 
            0xC6E9C98FE33965A2ULL, 0xF420E075F47640EBULL, 0x6AD316C9B79A03FCULL, 0x073A3C8DEC3BA9C4ULL, 
            0x05BB2FBF844E96E4ULL, 0x54FD556C36AB3697ULL, 0xE607C8404C2DBD1AULL, 0x40C93C5A6BC6232CULL, 
            0x0102143617FD9514ULL, 0x93CFBAED7B8588E7ULL, 0xF9E5D2F9FC3FD31DULL, 0xFDD7A446532FEDFBULL
        },
        {
            0x27CC4FDBC53807AEULL, 0x5468ED39D494E45AULL, 0x9E231A960271252DULL, 0xF1908CA8C689F288ULL, 
            0x3A4A0D5F5493ADCAULL, 0xE352EC8714365586ULL, 0xAEDB50EDB23F8BA8ULL, 0x7B474E9F74CACE73ULL, 
            0x6DCF40144845149CULL, 0xC33761911CB1621BULL, 0xDB58DE96D830A895ULL, 0x357292E8EFC8600FULL, 
            0xF210A61F9E0F44D7ULL, 0x707E4E61C5E59A89ULL, 0x10D8CF27C3579999ULL, 0xA23B164C8DC2D329ULL, 
            0x1F0CEC56F0522D08ULL, 0xE32DBCEF0FEAF48FULL, 0x192577B244A8E8C4ULL, 0x202539E772AA445CULL, 
            0x12C3728D3E10522DULL, 0x6409EE701EF4A5BEULL, 0x4BD3B4F177C5CE28ULL, 0x24342C3BDC836383ULL, 
            0x39AF56EA33E2CDF0ULL, 0x02EC07C148C91183ULL, 0x344E30965E602128ULL, 0xF332D406F7736856ULL, 
            0x04AC93F118AC1175ULL, 0x8A4DFFCA771B5383ULL, 0xA64478D8AFD84AEFULL, 0x644D0CE55F9D9CE5ULL
        },
        {
            0xD7A7C88FB976EDE8ULL, 0x8D5FF0ACB43D4F34ULL, 0xD7AC09DCF12537EFULL, 0xE6475389C726F5BCULL, 
            0xEE5E9EB066752A02ULL, 0x3A8059CA01894816ULL, 0xBB349597A8DD1760ULL, 0x6563309517232F74ULL, 
            0xABE0B465E0CFEC6FULL, 0xDE174583D73868BAULL, 0x7FD3C8E6E74A7010ULL, 0x7C529224F12615EEULL, 
            0x6A1652488276AD6BULL, 0x0510BD8EDAB379BFULL, 0x10AF2BF525CC7183ULL, 0x44BEA6A55B45ED22ULL, 
            0x66797CFAB16FD695ULL, 0xB8A685298FC44764ULL, 0x4E70B165A88468D7ULL, 0xA1D0FA954FE77214ULL, 
            0x40481942ED46828FULL, 0x60BEDB9F92E38FF4ULL, 0xADC02ABBA747E862ULL, 0x01D4B1C8515503F9ULL, 
            0x9DA1ECA4BDAE393CULL, 0x91BD33EA9686EF39ULL, 0x98C9662C7DCFA7A9ULL, 0x276BBC71356575FFULL, 
            0xD13D743520D696C6ULL, 0x67A2C1794270F43DULL, 0x2091D30A538743E4ULL, 0xC161C68A5848C0D1ULL
        }
    },
    {
        {
            0xDFCDD68FE8508023ULL, 0x03C2F5F38BE786BAULL, 0x44BCAFCA366452B6ULL, 0xCEC6CB9D897BD29DULL, 
            0xC53BD98C1D969E18ULL, 0x32522DAB93B3776DULL, 0x41C9C7C3FC8AFD5CULL, 0xE06198810E2ADCCAULL, 
            0xC373DDBEC28D0016ULL, 0xBC86454151BED759ULL, 0xD8C2083CB8C4C183ULL, 0xEE3C1101550FC25BULL, 
            0xD04021740D2B662DULL, 0x8474595DC2D0B383ULL, 0x06248560302B23FDULL, 0x8706DD0AD21B20B2ULL, 
            0x9C2A5F54EECD3576ULL, 0xF6DF8C423B09481AULL, 0x599AFF422AF13CFFULL, 0x3A91FA8BED87EE08ULL, 
            0x147A6A84FD7F6472ULL, 0xC1448E865250644BULL, 0x5E2106C64B01244BULL, 0x2B49DA0DC95F684BULL, 
            0x08AA3C569FC73B06ULL, 0x9E5AF62685E074EAULL, 0x61B19D95C16C7D39ULL, 0x9AD2D9410942EEBDULL, 
            0x82D168A152FEFDCEULL, 0xC34AB17305D12399ULL, 0x1E568FB8782FF67DULL, 0xEEF0EC22F7FF4354ULL
        },
        {
            0xA53AED78232860B6ULL, 0x073B76803E1C4682ULL, 0x1C05CB494DF73B2DULL, 0x53B6EC1229D8F283ULL, 
            0x3FDAE4913E02425FULL, 0x0E6773A8B58B9971ULL, 0x6D833805D9366AACULL, 0xE2C4E731AEF086CDULL, 
            0xB9B64BBCCF4C9FABULL, 0x461014F8B88F9B4EULL, 0xCC638BEC05C9BE5DULL, 0xFA78DD47921BAA11ULL, 
            0xBDB87B1EEE197948ULL, 0xDEB9AAAD09BE03E0ULL, 0xE4519B8EA4644F74ULL, 0x5C73190008CFF4FAULL, 
            0x97A8E782AC640FA2ULL, 0x5558F6722F1BE0E7ULL, 0x1ADC5D3F1E726682ULL, 0xAB89041B9A1FE7EDULL, 
            0x451B471A431AD4D4ULL, 0xD51D0F5A8235F946ULL, 0xDB017EE04DBBFFBCULL, 0xA89C1DA9A416F046ULL, 
            0x6AD23092B3CAF7B9ULL, 0xD925773707743902ULL, 0x72491D42782E9311ULL, 0xB214036B24F4C4EFULL, 
            0x8658A22591EF675AULL, 0x8F936E4AFD81BE17ULL, 0xFA0E9E40A98D9BE2ULL, 0x76C1612B2CC9FC2DULL
        },
        {
            0xB94DD200749368F0ULL, 0xDC6BFB1A36DF81B2ULL, 0x4E71B08B02957DA5ULL, 0xD533D6E6BF0D39A9ULL, 
            0x10E5888495A9E4E1ULL, 0x483F78EC7E06074DULL, 0x80244F6E4892FDFBULL, 0xFDE6EC33CE4204E0ULL, 
            0x50F823A0587D0FC2ULL, 0x75F57DDF27064A72ULL, 0x8A618DFA20EE68D2ULL, 0x5FB9AC38C872342DULL, 
            0x56C275AE42A08A71ULL, 0x90ABDE37211359CDULL, 0x4E9FB6FB936EA976ULL, 0x3FF356741213FFECULL, 
            0x42C3FA478A754EB8ULL, 0x8AAEEB02C37CE877ULL, 0xB00E8EA2499E4DF5ULL, 0xDA846D062FC78F16ULL, 
            0x575E54DDADBEAB03ULL, 0xC473EBDF165FEDF6ULL, 0x8B5035B35B8B7FBFULL, 0xA5189D2D9AC533BCULL, 
            0x68F90B2A53053917ULL, 0x66CF9E2E14F9BC7CULL, 0xB47A3FC20B238896ULL, 0x0D8572893933163CULL, 
            0xA3BBFCBD2EFCE447ULL, 0x674548F6ACCBA1CBULL, 0xBE7407199CC6F71DULL, 0x3059F2BA9968F3F8ULL
        },
        {
            0xE2D2938F77CBA64DULL, 0x621C00F5FAE0B13AULL, 0xB40475DA9D3A77C0ULL, 0xC0F2FA5067306334ULL, 
            0x86AD07A101786AA4ULL, 0x794E770DD30E2C61ULL, 0x141C18250E571AA9ULL, 0x40A24F0C0EAA7BF3ULL, 
            0x458E6E8183792C50ULL, 0x429A7CD72A2AA947ULL, 0x7E635F0D6B5BCF94ULL, 0x0B9A65CE066BEA3DULL, 
            0x610CC9684CFE7DCFULL, 0x6BF8B37F89A99AA8ULL, 0xE22EA8CEC6157757ULL, 0xC4E30DB3090C3022ULL, 
            0xF0CB9AF11A9468B4ULL, 0x6589494B49C7B4A7ULL, 0x2089222F036B6E6FULL, 0xF59675A36532D45EULL, 
            0xB69C22F7C4A70EDBULL, 0x8E497C6C79AB1A22ULL, 0xC0135F2AF55F7DBDULL, 0xFC7C61E3C275454DULL, 
            0xDAA905FFAFF5D0BAULL, 0x03BB960E87399D74ULL, 0x8BDB3298C022D3A0ULL, 0xC4574D27B61CF3E3ULL, 
            0x9C600D5F80A8BDD5ULL, 0xD1B8F6EC5B69F2BFULL, 0xEDBDCE20C924204CULL, 0x99420A7991C40F38ULL
        },
        {
            0x514B94610EA8A4B8ULL, 0x77C0DB75B480667AULL, 0xFAA75D646600ED3BULL, 0xBF46B9FAB7BC3D6AULL, 
            0x6D54E5D2AABA5596ULL, 0xC70C31EE3D5E5696ULL, 0x8A26F22552CC4467ULL, 0x64784F1D3DC62029ULL, 
            0x0EA89C9CD3D43288ULL, 0xC8688457C350F365ULL, 0x1ED2D154BA8C4594ULL, 0x01324927E0A41E35ULL, 
            0xD21ACA7A545275DFULL, 0x5BC72CC3F979B98AULL, 0x6AD4BB727BF0039FULL, 0x05D72F6A83012BE0ULL, 
            0x6750F117D046D6C5ULL, 0x89367286C6B7F790ULL, 0xD2E7470B7782142BULL, 0x50F93BED0622CF91ULL, 
            0x199395EAD1BC2C5EULL, 0xA3889C76BBC416A4ULL, 0x444BC2DFFAF6DFD6ULL, 0x8F8ACC00BE889F81ULL, 
            0xF199E8EFD9113EEFULL, 0xA1C392BBCAAAD473ULL, 0x96B45A26E55B51DBULL, 0x340C2C2393E89061ULL, 
            0xCBA7BD5FDB8A316AULL, 0xBAE633795E393B21ULL, 0x71E3013CDAFFA3F1ULL, 0x5F9381F93D819C3CULL
        },
        {
            0x86018FFCFDF39DAAULL, 0x470DBA3DAF35A719ULL, 0xF4F034723D7E917FULL, 0x83071C54BC181419ULL, 
            0x3F4BD838C15ADF0CULL, 0x16D7760D7FCE7F7FULL, 0x7BF5D48BABFEF64DULL, 0xF6CA84B43A400554ULL, 
            0x14430B4A49AC1A5AULL, 0xBB4A3F877AFB68D6ULL, 0xCEFA7A0D5AF85830ULL, 0xC64C63F742C3B6A9ULL, 
            0xAF7BA0239DA01ECFULL, 0xFBE10A10C741372FULL, 0x90535E2BB6E9E69AULL, 0x433034088ABC992EULL, 
            0xBF5EBC055F14049CULL, 0xAFFDD123714BBB08ULL, 0x44E842CC393D4D88ULL, 0x38439DAB7ED71B1EULL, 
            0x0943D95C7CACB9E2ULL, 0xC02D89E9075874D4ULL, 0x822A2CD19936830AULL, 0x6E0518A972190655ULL, 
            0xD8992FECB6CA9F94ULL, 0x698639B2720DB706ULL, 0x0FDE29A64201439AULL, 0x9282CB3B8CFF0B8BULL, 
            0x6621EBB8AFD352D6ULL, 0xDC1F3761B80EA16FULL, 0x19F14210722B7D0EULL, 0x9DAEA0C8F9A8B94DULL
        }
    },
    {
        {
            0xC917D33B2E863516ULL, 0x8C9B108CE16C43CAULL, 0x8B7BC6D3CED0D72CULL, 0x9E280A55AC5BD88CULL, 
            0x5164C1AD8E96C651ULL, 0x356A0C55C1DE0081ULL, 0x8A80A9ECECA80969ULL, 0x669581BBC9573B87ULL, 
            0xD5A7C7520772B775ULL, 0x169AD9DCEFE5D8A3ULL, 0x998863CB4E04A07CULL, 0x201A2BAA8DF88D0FULL, 
            0xFB2091FEA549DFA2ULL, 0x26F1C61A8EF3DE83ULL, 0x7D78D25A26CD2CFAULL, 0x95070C685C1DC77CULL, 
            0xD30A803FE5034BCAULL, 0x6EDFA9DB976ACED6ULL, 0x299766D0CC8ED410ULL, 0xD5D454984251DFE9ULL, 
            0xD3BAE1C42B45562CULL, 0xB7466C372DF2BE83ULL, 0x5E2BAA5E772FE7C8ULL, 0x63ED8022E688AD6FULL, 
            0x7D3B3F65BA6BCDC1ULL, 0xE873AD84BA267BABULL, 0x51E7D6B02E5CD04BULL, 0xBF071EC33EF31843ULL, 
            0x1F4D62DE61DA8D4BULL, 0x0F84189A04A2B9E3ULL, 0xA26B7FFD3BB8A359ULL, 0x28EB17A5DAF9F944ULL
        },
        {
            0x2714E9F378821322ULL, 0xEB1DD08E01CEA12AULL, 0x9506FF13DA2D9033ULL, 0xD80E6F7F9729591CULL, 
            0xEFE01BF6EB2802EBULL, 0xA1F481039A15B5A4ULL, 0xDBFCEE03840B2D00ULL, 0xE0937BE349916362ULL, 
            0xCBDC46859441DCA6ULL, 0x0879E77A4162CD2BULL, 0x85F09BBB148AC7DCULL, 0x4B9F60BF53BE6184ULL, 
            0xF4A5BBFB8EA8ADE6ULL, 0x717D21C4061599D8ULL, 0xC4EEF34689CB5B53ULL, 0xAB6B7244188906C4ULL, 
            0x05E3044234780F7DULL, 0x5F99166EA4FC728BULL, 0x3B2F1E89E5C76BA9ULL, 0xF5FD4D3B587DB242ULL, 
            0xF8D9CA620048DDA8ULL, 0x7604051D571F784EULL, 0x715998A655C80586ULL, 0x6B8333BB4F7CD186ULL, 
            0xD8F9A7817C9AF532ULL, 0x7820912F1D55152EULL, 0x68AE3C132180E8FFULL, 0xC39AE6BA571F9314ULL, 
            0xFC6CBA74E66B072CULL, 0xD09D02D0AE69A668ULL, 0x0787803370358CEBULL, 0xF61E9FEB375D652FULL
        },
        {
            0xD6CB1CBBE17FA803ULL, 0x4D77113FC61EEE75ULL, 0x95B1C6B4F180C353ULL, 0x0408D97A66DF4078ULL, 
            0x67882421AAAA4B84ULL, 0x104809C97A03B4F7ULL, 0x85FF8F0E4414A4E5ULL, 0x91313F188655A504ULL, 
            0x3EA7B3B46EC83CF6ULL, 0x3AE4BF43F28096FCULL, 0x85295A6272C7040AULL, 0x38A8D1F6DAF09856ULL, 
            0xDAD898F2DA0B5F05ULL, 0xF12EF47D603596E1ULL, 0xF452589DF2158549ULL, 0x9B7DDC23BB819EC7ULL, 
            0x203D6520507C6DFCULL, 0x44CB4FE64690101DULL, 0xFC81F87BC41986E3ULL, 0xCC5C73ADAF559F98ULL, 
            0xB58D21E703674850ULL, 0x40EB1281D20AED87ULL, 0xC5E435B0886DAA1EULL, 0xFDDFBC96C43BAF26ULL, 
            0xECE81CCB3450BC24ULL, 0x5D449FBB3B0982D5ULL, 0x86CF41A617D11859ULL, 0xE29F97406B3824B3ULL, 
            0xF9CC50E5C2BB4F4CULL, 0x7F13E4DDDC2C21ECULL, 0x3B42293218956940ULL, 0x92345C0E0B93E4A6ULL
        },
        {
            0x6CB582A13342D1E3ULL, 0xEA644E8148D1793DULL, 0xA396EE916B124AA2ULL, 0x56FCF24D35AF8333ULL, 
            0xE4138BC57C09A5DEULL, 0x8CB2F9F59B60A3DEULL, 0x52C1FD3CA1F9613AULL, 0xC5B517953EA91634ULL, 
            0x8FFFD16F727BD71FULL, 0xEECC4E81CA41ADB6ULL, 0x6FABCDD327498744ULL, 0xD7C658BE5B259809ULL, 
            0x346B19B2B96EE411ULL, 0xCC9312783E044FC3ULL, 0x90E1BB47AC8344EAULL, 0x63A64451870A8964ULL, 
            0xB516E57973114904ULL, 0x473CEE23DB0898DDULL, 0x759DFE031BB1A20EULL, 0x39746D0876020FFEULL, 
            0x1EAB25126E655E03ULL, 0x53EF585398C9EFB6ULL, 0x8F28C69EAF7144A7ULL, 0x6EE014D40162202FULL, 
            0x302F34EC90FE29ACULL, 0x5AB6A812B3EF4FF7ULL, 0xC6F5EE5AAEA462A5ULL, 0x53DDAEB0EDEE0F73ULL, 
            0x7B9049AD95DA1CF5ULL, 0xDA63A6F0EE349BB1ULL, 0x9AFBFCC05CAA3B3DULL, 0x3C5659EF07AA66EFULL
        },
        {
            0x8C69C54B4DED13EFULL, 0x2E2C0D619A25CF8AULL, 0x4717D6BAF4FF3BEFULL, 0x3684E6EC5CC9E9A5ULL, 
            0x0AF1F1FF4C960C27ULL, 0x331CF786387050A6ULL, 0x579D772FAC6E8007ULL, 0xFBD540BB76A4FBAAULL, 
            0x054CFDFDF78D723EULL, 0x5E5C2D34286FAEF4ULL, 0x5B9F99F092468826ULL, 0x176191789E0F37E1ULL, 
            0x05CA5CA72ABB8A76ULL, 0x549D562560E6DB03ULL, 0x6D6196E430F8B012ULL, 0x7DC5B653B8B4F15AULL, 
            0xD5989D77C549336DULL, 0xA44A50C36EB0AB25ULL, 0xF1F04E2FA77034D7ULL, 0xA4115FCFE5B4E457ULL, 
            0x1C178179AD282161ULL, 0xCED20AE12615F1C0ULL, 0x8F729DD9C0E36AC2ULL, 0x4BC40CFB152816E6ULL, 
            0x236B55A2635E5D70ULL, 0xE559F8A38088E620ULL, 0x2DA6B2A1263E19BDULL, 0x0ABFC7E124859B57ULL, 
            0x54E5A9441C446B65ULL, 0x848402996B1B223BULL, 0x1B40E4B2B633BFEBULL, 0x236E4ED164CA4C9CULL
        },
        {
            0xC51EAC713F5C3423ULL, 0x1671C8AD61D899B5ULL, 0x7C6AC4C2B4B3A6FEULL, 0xC9D623F44C3631C0ULL, 
            0xD14E6D9E5A2B968AULL, 0x42819814845DA1BFULL, 0xE627C7771327869BULL, 0xE7926450301DF12CULL, 
            0x8652A63B7AD1A616ULL, 0x1728A8E0E91E3DDDULL, 0x167EA78F489DD337ULL, 0xC2D55EC7E4E7AC6BULL, 
            0x033ACB9D0797B488ULL, 0x0B0D52CCB78B7510ULL, 0x5D71D22376B90BC7ULL, 0xE9610B9F62B9DB2FULL, 
            0x4DDC350113CCBBE8ULL, 0x9DD07B1A0DC5B388ULL, 0xC2ECB4C51A667C23ULL, 0x924586DB0FDD9371ULL, 
            0xA5BF77734C6D8970ULL, 0x3B26B7344950B295ULL, 0x3E4FD668BE4D0002ULL, 0x1B2CFED91F98BD6BULL, 
            0x1C22E5770DEC9680ULL, 0x56C941059E3C8E37ULL, 0x1E871E2E822445BCULL, 0x01599F4FF20EE255ULL, 
            0x422C4540E5FB6B2EULL, 0xBE4D9769EDE02A4FULL, 0xE4A700EC009E0FBBULL, 0x2ECE8FDF2B3B338EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Menkent::kPhaseAConstants = {
    0x4600FD352C5EBD91ULL,
    0xA889DB924E8A1271ULL,
    0xF8D159C2C52AB4F1ULL,
    0x4600FD352C5EBD91ULL,
    0xA889DB924E8A1271ULL,
    0xF8D159C2C52AB4F1ULL,
    0x810A7703071101C2ULL,
    0x052B8224A526FD72ULL,
    0x18,
    0x0A,
    0x03,
    0xEF,
    0x27,
    0xDB,
    0x1D,
    0x8C
};

const TwistDomainSaltSet TwistExpander_Menkent::kPhaseBSalts = {
    {
        {
            0xF6F14F9F7064A412ULL, 0x15F807CC58AC2F6BULL, 0xA96F40E6F58C6E17ULL, 0x27B34BA34145DB86ULL, 
            0x5588C903ED55397BULL, 0xB3B0EA8C7920A780ULL, 0x51462EFF5D641137ULL, 0xEADAF33F18347240ULL, 
            0x3E9624270663D376ULL, 0x8D11C8AE44C78359ULL, 0x44612D005E78FEB1ULL, 0xA940BEBE92E53D0DULL, 
            0x543D86D60B7C16E6ULL, 0xC7D37F564C2AC83DULL, 0xF95FD59DE386D5E0ULL, 0x12BF98EF56A9CBD6ULL, 
            0x4E594C8EC61CCB40ULL, 0xDAE6D48667CD9BA7ULL, 0x6315E0A1A04E238FULL, 0xC1E343C57D265EE8ULL, 
            0xA7BD60EF9D85333EULL, 0x2D85BEB1983DE972ULL, 0x50F0B45B2A64DDF2ULL, 0x57E3BC52AACD6B60ULL, 
            0xECA302B30290CCE5ULL, 0x98CF0C4199D359DEULL, 0xF9A3DFCF20994B2EULL, 0x84A708B5D6024ECAULL, 
            0x6420311A79513035ULL, 0xD1D98E2EBB7E92B5ULL, 0xF8EF2D3C8762FC84ULL, 0x118CA88D46F5CB99ULL
        },
        {
            0x86B3586F110FB9C5ULL, 0x5B05F3B451DBF126ULL, 0x2B0A59CFE19F3248ULL, 0xE88519169DF5BF64ULL, 
            0xF25ACE9C5A1E55A0ULL, 0x8CC8E856E9ECA571ULL, 0x5AB2D2B8CBA167F7ULL, 0xE177BAADF4DF8F79ULL, 
            0x572F6A65CE8BDB01ULL, 0x67B4F9C94CFD90B9ULL, 0x2FF90448CD49446BULL, 0x7028AEFD9C1A257CULL, 
            0xC8BD3A2262E33A34ULL, 0xFDBE3964D505EA5EULL, 0x37FDB08AF0793ED5ULL, 0xAB861C4D3F5FE421ULL, 
            0xF83BDABC7C312ACDULL, 0xB13A8591E5A0C575ULL, 0x093E5A863673620DULL, 0xBC06EC62C790AD4BULL, 
            0xAA341DF11D742E14ULL, 0xAA154A2F3BEB277EULL, 0x7F68704B95B7275CULL, 0xA794EB8F47D1949BULL, 
            0xBD94A4904380086FULL, 0x9B79BC4667D64D67ULL, 0x03716A39CF482415ULL, 0xA6AB9A147DB4A5A2ULL, 
            0x1E98D73BEF774BE1ULL, 0xFB949B12A8113F4BULL, 0x443595F77B71F76DULL, 0x12632EDE8909E411ULL
        },
        {
            0xA0B20F7F8DE9D515ULL, 0x52F794B2129EDF71ULL, 0x778024E21E7B5FC9ULL, 0xC55C94E02F72D86BULL, 
            0x967F2EA132BD90A8ULL, 0x15FB52FFDE34C646ULL, 0x1914B77AFF05984BULL, 0xDDDC978AD5496219ULL, 
            0xE649DC4ADEEC8BE5ULL, 0x4BADD7B0FD4DFCC1ULL, 0xCA0B3C3A18F19E9EULL, 0xC6093C9AA41A7E1DULL, 
            0x8DF44EC16DB03EF1ULL, 0xA90CEC64B193FA8EULL, 0xF47FAEE8870069ADULL, 0xB2A96C6C6737E425ULL, 
            0x9621EB596561C25EULL, 0x17B16AA4B081E3F8ULL, 0x62F28B7AB873C703ULL, 0x3B8479C1D7861558ULL, 
            0x2D658EBBA12A66E4ULL, 0x7F428E77C4C319BFULL, 0x5376E0C7C4D35E1EULL, 0x26588667E9A52142ULL, 
            0xC6B61EC3671D8876ULL, 0x56C527480D7D2506ULL, 0x734F4B0F24CFCC2EULL, 0x06B0B563774BCD6FULL, 
            0xDC0740B633B344BDULL, 0xA415347A489B881CULL, 0x5D18C4C4C8D9BAB1ULL, 0x9C8045F2C70743DDULL
        },
        {
            0x1F65F71268127720ULL, 0xD1791FA2A5E0F954ULL, 0x54DD39E19BCAE4B6ULL, 0x98DEEB631020741CULL, 
            0xA97C71577C7DEE67ULL, 0x5B96AD29212D1AB8ULL, 0x10C2047FF55803FBULL, 0x7332CC82D0372AEEULL, 
            0x2E5BB8987C4C9D32ULL, 0x0951900F03B3A03DULL, 0xF4AB9460D63D7232ULL, 0x6427DABFE82A781DULL, 
            0x98901F9A8A2DA40FULL, 0xE7D0B9111717E024ULL, 0x019F76E08D5ED3E1ULL, 0xC4DEFB60E34B1221ULL, 
            0x69BC61E75300699BULL, 0x385F7F030DED38ECULL, 0xDF5C3BE5D1E1976DULL, 0xE94A47A1FD09C3C4ULL, 
            0xED4A56D859C2507FULL, 0x65687AA33DC2988DULL, 0x8B21E85AC7E2F778ULL, 0xB750A84FE1D2D0FDULL, 
            0x27F7DE8576D070F6ULL, 0x163A26116FA8F07FULL, 0xABCF5803DE5613D2ULL, 0xBCE2CC40B6D4C3E2ULL, 
            0x847BE2145ED2DCF2ULL, 0x72A8FC670A070F1BULL, 0xF05A29A110912C3EULL, 0x56A55714F8069D54ULL
        },
        {
            0xA9254590AFE093E3ULL, 0x9EA74AEEFC866EE1ULL, 0xB3DBB70B1872A81CULL, 0x03FD7EA940C36D5FULL, 
            0xEC98D29AF6846ACBULL, 0x147B633B9839DBD5ULL, 0xDD98788CA6579DAAULL, 0xA50211C1432FE1A1ULL, 
            0x1E8466608CD465D3ULL, 0x9E34EE95656ED009ULL, 0xC4AE58D5F7C14377ULL, 0x6FBCA8DAE1F3926BULL, 
            0xAB0BC5CAE897A7EEULL, 0xD5259FE3328ECB56ULL, 0x1C0771D3BBE9D650ULL, 0xCDB64BF26F044EE6ULL, 
            0xD1C055898B91F2EEULL, 0x10CE8C0D0F53A467ULL, 0xB41A585C98B32366ULL, 0x27357AE8CE797855ULL, 
            0x04A05ED78AB2C6D2ULL, 0xEA9DD41C37A1DAE8ULL, 0x817CEFAF691C13B3ULL, 0xE834459E609D1DEDULL, 
            0xCCEC89FBC65B40FFULL, 0x0530B9114EA9CA59ULL, 0xE72D68F12CFC9143ULL, 0xF9C4E191AB26E57AULL, 
            0x05366F4B1C7F650DULL, 0x475AF10F6E2CC95CULL, 0x438112D5C9AD02E1ULL, 0xCD70A369967DADA4ULL
        },
        {
            0x0C21922E1C8FA678ULL, 0x28CB3418B22A5A56ULL, 0xF7490550802D3943ULL, 0xC22F39BF640B621CULL, 
            0xC7A65E980A4F20E8ULL, 0x0BC48D29F560A7A7ULL, 0xB8787EF301D686E6ULL, 0xE3413AE1DCB90D30ULL, 
            0xEAE339F4128D0B09ULL, 0xB6189E42D5FDF954ULL, 0xBC5AC76947DD9106ULL, 0x70603C4847B4A090ULL, 
            0x18885876F0EC4D00ULL, 0xCDAD74369DF21AB9ULL, 0x6C62E6A691BB84D8ULL, 0x3B8EDFF164848DD2ULL, 
            0xA4453EE89F830809ULL, 0x8629A3EC48522842ULL, 0xDB7F1576E9555390ULL, 0x873D9992807B1268ULL, 
            0xAB7492E7C1086378ULL, 0xDFC6ED18B7A9E653ULL, 0xEAD9BD3529709E21ULL, 0x6AC62023ABAA8C70ULL, 
            0x49E44738D38AB277ULL, 0xFA0BBFD7B01F7CA5ULL, 0x06994966D60BD500ULL, 0x8B8C07E89F3A33D2ULL, 
            0x22B01EED5016DD44ULL, 0x5A955772F14D6695ULL, 0xCD5217B071865D58ULL, 0xCA0B42F7FDAB92C3ULL
        }
    },
    {
        {
            0x0B1612FDC3BFE959ULL, 0xF35D7F124055B627ULL, 0x10065A7BC1F941DFULL, 0x3ECEE875EADFCB8AULL, 
            0xD2EEBD40BDA5F4E2ULL, 0x09171A0EE5F36FF2ULL, 0x8821C3F45AFC98B9ULL, 0xF68BA8278AE4B3F1ULL, 
            0x69F86C004C23AE6EULL, 0x6204F095488C092CULL, 0x9A22C9AF6B7ECCD6ULL, 0x64CBBEA4C62A051BULL, 
            0x4BAB04994ECBD5D5ULL, 0x366FFB40F80E1402ULL, 0xD3BB6A2958FCA075ULL, 0x8A13B584A65A92DFULL, 
            0xEDCD14B03B06E976ULL, 0x2EF12F2FE135E2D7ULL, 0x5C80C3F1ED6C6DF1ULL, 0xA77FBF5673D7FD2FULL, 
            0x53D7694244D0C6D8ULL, 0x1C88BD28AB04EB13ULL, 0xA44341A8A9B43642ULL, 0x39DC23ADC1008888ULL, 
            0x540E3E32FE238B08ULL, 0xF6D67A57695947E3ULL, 0x8950E7734E6AB21CULL, 0x955596A78BEC6961ULL, 
            0xCC9D91FCE6909400ULL, 0x160E6D92A56D3DE7ULL, 0xE19FC1FD5EE1136CULL, 0x68AFE2442E5DDAEAULL
        },
        {
            0x92506DDA9FA6740DULL, 0xBB4F2B2D1E4B62BAULL, 0x733BF74E39A94341ULL, 0xBF634DEBFE798825ULL, 
            0xF1D848EC143239E2ULL, 0x15AD404B14057586ULL, 0x779D6EDBFC272E86ULL, 0x72933BAEB1471582ULL, 
            0x9838358EB91A1DDBULL, 0xD8918D0929986828ULL, 0xF1FF2B94006DE429ULL, 0xF0B6089359911A56ULL, 
            0xFC8B21AB4DE7D717ULL, 0xE02AF15F49DDB093ULL, 0x0CAACBEEBC596179ULL, 0xE739ED6A4D986386ULL, 
            0x7A7D95D3E9D9E569ULL, 0xB9C298CE66C8730EULL, 0xD7E369C587D47576ULL, 0x21DF056AB7FD24ADULL, 
            0xA4A8EC56EECD47AEULL, 0xB241C7575BD382EBULL, 0xDC405D1287F75350ULL, 0x0D3D1107D57FBB74ULL, 
            0x6BB523FDD97F5A45ULL, 0xE1473DF18B078BDFULL, 0xB3E869D70B8EF4F6ULL, 0xB2474F318B57C049ULL, 
            0xA3D61E4A303CB891ULL, 0x5EEEB197FDD68585ULL, 0xAC313392A50ED529ULL, 0xFD61E1186BB392D0ULL
        },
        {
            0x7008AB25A651365DULL, 0x397E932823B904A0ULL, 0x91A0C53903922429ULL, 0xF751DAD01C5CFBEDULL, 
            0x6B8FA6AF2CF7A1BAULL, 0xCEB928F52D85632AULL, 0xEA0948D345641119ULL, 0x62D1AE3B3CD738FBULL, 
            0x89A97D82A99713F0ULL, 0x484BF33F2359B770ULL, 0x903FCAD156A6B1CBULL, 0xDE418AB9576DC18AULL, 
            0x0EB659275184708CULL, 0x44BE5D4148F04B5AULL, 0x0E80E41329A1EDEBULL, 0x9ECC4E1379637CAEULL, 
            0xF239A1BA9F76980FULL, 0xDF11EDDD227956D8ULL, 0xFC0B5EA7E0854344ULL, 0xC6A828C278851B07ULL, 
            0xB36BDC23F4D2B130ULL, 0xE56CCABD54A1C5A5ULL, 0xEA68FEAD3B160FE3ULL, 0x1E3F013B5B6C6A6BULL, 
            0x3E6FD9DC3DEFCC0AULL, 0x0E91A037E9243F09ULL, 0xE48B83C528123810ULL, 0x3F944420011E5FC7ULL, 
            0x8BFB18A8A4CCA998ULL, 0xC164B2EDAF461A6CULL, 0x5DE4B36E64DAB5C0ULL, 0xEF70212D59D22A5FULL
        },
        {
            0x5949A4A7B0261CA2ULL, 0x3D2A9493067152E7ULL, 0x8C1BB6D75098D3C2ULL, 0xFC7B2C9D40EDC6C5ULL, 
            0x013ACFC0B5632D68ULL, 0xFC6C7F3E92CB8538ULL, 0x5D73587E02549C01ULL, 0x86DF1D26A4C482E8ULL, 
            0xB15DAD59BB23EB76ULL, 0x8B749AEEF3B27FF1ULL, 0x5D1AD53FC8A4CAE5ULL, 0xECA0B2F3583D5544ULL, 
            0x86818F7356B2B7BFULL, 0x5D8B10B4E79500C0ULL, 0x7BD047621BFDB4B1ULL, 0x88C9ADAE4245A896ULL, 
            0x64982388D48BD215ULL, 0xEF90E9ACB1FB15C9ULL, 0x07893515CF253A21ULL, 0xCE0A39C6543F027BULL, 
            0xE95FE4902B1CD989ULL, 0x72FBB800E98EED05ULL, 0xB0C9827CBD31C49DULL, 0x88FF03BE7D968566ULL, 
            0xBA0531FA0EEEEE54ULL, 0xE5726A2070BA160DULL, 0x8DFA466F3730A913ULL, 0x04F376BA02AAC107ULL, 
            0x13093373614F1FB7ULL, 0xBF96C569654DD0BAULL, 0x8BFC685A22976A4FULL, 0xE9C9D61E14217BDFULL
        },
        {
            0x60C63702A239B47DULL, 0x751C65C56DE4801DULL, 0xCE10491C27416F4EULL, 0x498660B07101CA6DULL, 
            0xB80D664A54818D56ULL, 0xA0219C69114F101FULL, 0x253CF4759DA206F1ULL, 0xDDD96B0DC46F1E5CULL, 
            0x7E5379E1C80E7B39ULL, 0xC82ED5BF1F8FD4D3ULL, 0x610B42133340794EULL, 0x8B0D88FBD5023137ULL, 
            0xCF7C0E20FD8BB3A8ULL, 0x283A82B58C2241D3ULL, 0x2139268B7EB4E52EULL, 0xA93A32856FB0F13DULL, 
            0x331547ABAF0C5C95ULL, 0x6805011455DDD630ULL, 0x6B801432C1312153ULL, 0x5FA255BA399A7825ULL, 
            0x2409B5F527E48AC5ULL, 0x000D927B0A7F8A96ULL, 0x03177E82CF944536ULL, 0x2F361EAC10174BD1ULL, 
            0xDAACE0C173F91620ULL, 0xEA873BF85D9C04A6ULL, 0x896DFE8CC090CAB1ULL, 0x6EC05E9273E2D13EULL, 
            0x08D93206AAC88B66ULL, 0x2612C33C03DB892AULL, 0x3BC31F053D2330F6ULL, 0xF30BE20CC1B64F78ULL
        },
        {
            0x53D3C4D64D036873ULL, 0xCC4F92FC7D878171ULL, 0x5CB243BEC9BE2D53ULL, 0xCFFA565939D1607BULL, 
            0x3EC05F21F8D8399BULL, 0x1813324DBC6B43F5ULL, 0x0CC877D08ABC1F68ULL, 0x67AEFA9EF06E2196ULL, 
            0xF5C62EAE4E4EF739ULL, 0x927AA74340E51DEEULL, 0xE28ED9DFCB7099CEULL, 0x79464EBDF5E0FAFEULL, 
            0x515B367F5B64CB55ULL, 0x8E4F31CBCC766F93ULL, 0x34479BB5865145BAULL, 0x399EBA56BDA85573ULL, 
            0xC7C0B5E37BE8DF19ULL, 0x098E3F91BDD54DFFULL, 0xFCDA8DC9DEC77811ULL, 0xEBB03A2689A71D80ULL, 
            0x4F8CDCE8087E35E9ULL, 0x7177EF55F0DA886FULL, 0x62BFB39C09417BECULL, 0x1310B73AD9215CD7ULL, 
            0x0EF5D1C6B53E11BEULL, 0x859F173AA7EEFB1FULL, 0x593C383CB6F1A003ULL, 0x0952EBE5D3FD3FA1ULL, 
            0xD70401EECD8E502BULL, 0x2DA60B73A9D31434ULL, 0x18824B24635AA01AULL, 0x02D74F43C17291EFULL
        }
    },
    {
        {
            0x60DBC1F2048A59AEULL, 0x0801C48CA7CEA937ULL, 0x5A170318AAFF3E4CULL, 0x307CE9DBBA00141AULL, 
            0xDDD6842022989D33ULL, 0x2C66CCC80FB9F0B1ULL, 0xA4D9B20C0230947DULL, 0xFDB79572B492055DULL, 
            0xCD1E23F4E74051D0ULL, 0xA36DF919A2D1B8A3ULL, 0xD0B1BBB599F8E60CULL, 0xF541D1703598B844ULL, 
            0x0F6F49869B0966DAULL, 0x40E267807F93F0A3ULL, 0x7F579CEF84785FBCULL, 0xDF8B42AC57589A62ULL, 
            0x6A2E53B704A73816ULL, 0xE062121E4674F9A3ULL, 0x31F7BE44735D2433ULL, 0xAE155C7DE8D9D24CULL, 
            0x921C1685D3C06B34ULL, 0x6A90CF6E41EDDD52ULL, 0xE904224BB5FE679AULL, 0x8E445FE221DDA7B7ULL, 
            0xE9F11380C60FB0E9ULL, 0x9FC17F0D704611DFULL, 0xA904989D50DFDDC8ULL, 0xD03B12FEFF621EE2ULL, 
            0x7374617DD6490751ULL, 0xAA403B5F83F86AF7ULL, 0x365B28CA23887C6EULL, 0x3C71E58C68CD2654ULL
        },
        {
            0x102066EE3785D106ULL, 0x1B9B3DEC78A891EEULL, 0x4C769E3D8A7ECED6ULL, 0x51709557570AD18CULL, 
            0xFA16AD9C1AA46A63ULL, 0xD4F1E71D665D96E1ULL, 0x0125FF01D7B65B4FULL, 0x667D4157232F6A50ULL, 
            0x693B3CE68FFA2940ULL, 0xD104F7242A0232ACULL, 0x8AD61B0AAF2D6FC2ULL, 0xA3DCF35E00F71847ULL, 
            0x9F10AD430A1F4C7FULL, 0x5C44ECFF6C33CC7CULL, 0x6028899120D658CCULL, 0xFA2E6C771E39706AULL, 
            0xC5A02949BBFEFA20ULL, 0xC70F9D4248B1CD56ULL, 0xE5F7FD5E5593F60FULL, 0xC8E37F36D573D305ULL, 
            0x55A577B3F7F5479BULL, 0xEC83004608287E00ULL, 0xB1D7E8BAB562BF72ULL, 0x7591D687C713A7A3ULL, 
            0xED57F094E31AD7AEULL, 0xAD0BCF25BDE6D216ULL, 0x067B845AFBDD2A12ULL, 0xD02FA884CB38DBDBULL, 
            0x7EB657609C12843AULL, 0x865E9761BECB85EAULL, 0xFF29D4B8693E5ACBULL, 0xDDBFE26719316567ULL
        },
        {
            0x61E2DE4CA4FB4002ULL, 0x351FF78745F7F849ULL, 0x5239FA428FC239D6ULL, 0xFEE0AB2E0911B9A0ULL, 
            0xC7128E21ADD74E78ULL, 0xD130810FB623B161ULL, 0x2F6C9C95641F1A74ULL, 0x410F424A79EED467ULL, 
            0x3DF211196100A0DBULL, 0x8A4DB4B29B348041ULL, 0x552ACBAC67975C90ULL, 0xC336D9A1EDDEFA5AULL, 
            0xF2AF621104302FEEULL, 0xD0F80852FC407117ULL, 0xCC4CAA85A958C21CULL, 0xD91B6C522454DE39ULL, 
            0x0F1F7B8322CFED5EULL, 0x1FE0CAEE6360C91FULL, 0xC99D94DF5A548253ULL, 0x1AB353F2C9AA0DC3ULL, 
            0x59D21311CBFEA524ULL, 0x8FA2A41D9535AA64ULL, 0xA60608936141C4FDULL, 0xC6BBA4B734491857ULL, 
            0x735F119FB9294C54ULL, 0x887F316D226F4A12ULL, 0x2085C97F9A6E9D42ULL, 0xDAD7C39E6C3A2BA2ULL, 
            0x48DE93190E07D6ABULL, 0x21C9E6C167765CC5ULL, 0x2AFF3766C19AFE57ULL, 0x44611C19191693A4ULL
        },
        {
            0x01D4138617ADFC2CULL, 0xE7FDC6794CAA41BDULL, 0xBFE9B61722EC60FFULL, 0xD40A1F1B8E954C14ULL, 
            0x1AC2468D5B112030ULL, 0x5CE80A07CB781899ULL, 0x0DF0D6DD060A47E4ULL, 0x3B341A6B0DCBF79EULL, 
            0x111B3AE464390630ULL, 0x795BBD8FC14EB5E9ULL, 0x2FEF8FF5A8107EE9ULL, 0xCBC1E5E12A488635ULL, 
            0x0EF839486C35A066ULL, 0x9D1B1AE7E4527FFFULL, 0x8AA5BB7FEC295202ULL, 0x635DA392D3A7A696ULL, 
            0xC0C92D4F479FB72AULL, 0x91BFF182AAD31C01ULL, 0xEA035EF1B8FFC6F9ULL, 0x36980018ED9E2B08ULL, 
            0x545176A35CEA7427ULL, 0x073B47AE49E4F823ULL, 0x5E257ADFC606646FULL, 0x5FEDBBEE433025A3ULL, 
            0x4EA20DC3FA9CC9F6ULL, 0xC0331D11F54D5864ULL, 0xBF8E2387CF7D3A26ULL, 0xFA16F68B2633C229ULL, 
            0x58A9DECE755C1CA8ULL, 0xF266C55E9C89DC7DULL, 0xA5D3A7F50334E7E2ULL, 0x6EF5951ABF650FBFULL
        },
        {
            0x5954F9D1D1E1D08FULL, 0x5EDE88512FB0BE72ULL, 0x5FE46C6F8802D596ULL, 0x98DDF9275F130233ULL, 
            0x8CAC7CD68D692997ULL, 0xEB5492BF6029E887ULL, 0x9E9D6FEFA4CD06DAULL, 0xB68E3C18E5D8211DULL, 
            0xDA819BBB45CD13A9ULL, 0xE9B2554E40570F47ULL, 0x1CB75354146B0C01ULL, 0x2415FFE21DDEC606ULL, 
            0x9B1F580EC15CB8E2ULL, 0x927D9139671C35E2ULL, 0x998DD20E14060E61ULL, 0x8D156437CA87B3CBULL, 
            0xCD1D008793D41F00ULL, 0x2097D53779F4BD9BULL, 0x9B721224D1544541ULL, 0x0E5042E5287C907EULL, 
            0xBCCAB96403113667ULL, 0x49971FF3A1C9F38EULL, 0x3E5D722D36D70F49ULL, 0x151988A3C08A902EULL, 
            0x4B3C71E77F724596ULL, 0x00871580C0E76F29ULL, 0x26565040502050ACULL, 0x268DE166D42ECD1AULL, 
            0x78C805FCE63F70BAULL, 0x627E97FE6E4A8306ULL, 0xC7618523315E1243ULL, 0x2E25334F2937F27CULL
        },
        {
            0x5CE9CA7D6B48AB86ULL, 0xCDE4467FFCA1183BULL, 0x790D982FA4582577ULL, 0x822B394745BB654CULL, 
            0x85D1F85C8A7FCC7EULL, 0xE420B6F73C77931EULL, 0xD828061FAB1FF833ULL, 0x004BF37FBA9BC2ABULL, 
            0x966D6815EFE259BAULL, 0x0BB5BBF75C722291ULL, 0x148C8D5F6B6F7394ULL, 0xE6DD7D8E67E3A3CCULL, 
            0xADE90AC2C63B1E87ULL, 0x5D8CFC149B21A390ULL, 0x5DFD6DE604810558ULL, 0x1EA180A3738715EDULL, 
            0x789D4579CCFBC1B3ULL, 0x6A19AD28F4225DE3ULL, 0x89CE494BE408211AULL, 0x744D65F27FD2881EULL, 
            0x518E09C98B4E6828ULL, 0x1C21B3DCACB8F80AULL, 0x356C6021A0597556ULL, 0xD96A0AB1FDD3C1A8ULL, 
            0x7D9E2F7ED0A5A07DULL, 0x984CEF5111114F93ULL, 0x42214D08C5588A40ULL, 0xD6502AD0C9638376ULL, 
            0x3B480AAC80B6909DULL, 0x66A7DC18D58DF745ULL, 0x1E23CF3C351FE82EULL, 0xA8186D39ED5B28D6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Menkent::kPhaseBConstants = {
    0xED69B690AADB63F8ULL,
    0xD12439A2686176BAULL,
    0x16DF7B32B797A984ULL,
    0xED69B690AADB63F8ULL,
    0xD12439A2686176BAULL,
    0x16DF7B32B797A984ULL,
    0xD919B85A86A8D565ULL,
    0xAEB532366122F6CFULL,
    0x70,
    0xBF,
    0x5F,
    0xF6,
    0x0E,
    0xA3,
    0x62,
    0x93
};

const TwistDomainSaltSet TwistExpander_Menkent::kPhaseCSalts = {
    {
        {
            0x3085CB3F80A51DDCULL, 0x3B700FCFAE349FC0ULL, 0x6341EF49B35B687EULL, 0x6BA3AA339D1084DDULL, 
            0x0CB2255BFB3A3560ULL, 0xAAD2011C79C81E9BULL, 0x1679BA1331713978ULL, 0x8B4E28575FD8A0A4ULL, 
            0x949A2F0F7E73462FULL, 0x8FCF6913496C66DDULL, 0x22A6F992F912EFB2ULL, 0x98640D7F2F09F1B6ULL, 
            0x3084C938180BB071ULL, 0xE5CBEEF8FA81F2E7ULL, 0xF611DB7FE6E9F09DULL, 0xABF9B770C024D76EULL, 
            0x89BD156C586B42D0ULL, 0x3226C3F528B298CEULL, 0xC8E1BB84B6B5771CULL, 0xB50B7E659F2AAD8FULL, 
            0xFC82DFA917540C1BULL, 0xFDE0FF8032FA3D3CULL, 0xE032199D8384F1FAULL, 0x7115B62DD3CD9F1EULL, 
            0xE6E979D8EEF1C997ULL, 0xB82F85B3B704B93EULL, 0xFD587804006F2A72ULL, 0x32871334950D3EB1ULL, 
            0x05CA1ED7B94502F8ULL, 0x7BB966DB59BCA279ULL, 0x67F9DD410E46872DULL, 0x099528AA9A804A8EULL
        },
        {
            0x4A6D2C5011BF1115ULL, 0xC15C0959C180BF6EULL, 0x2559CD50B2065CBEULL, 0x954DF2BC8F850EE7ULL, 
            0xA30FDE5461A1A33FULL, 0x3D6DFE0904A6D765ULL, 0x09C02FB1533E7965ULL, 0x14248EB8F740E746ULL, 
            0x0004DC80562C86B6ULL, 0xEA78D669F475AD97ULL, 0x7D062606DBA401CEULL, 0x7C3CE09A5E6777BEULL, 
            0xD65545E0C22343C5ULL, 0xD9A919918311B258ULL, 0x6843926A46543412ULL, 0x81F7C3FC96C1E9A9ULL, 
            0x1D3FF25FBCD92C87ULL, 0x07A3A60E152CF391ULL, 0x69755617448F5B45ULL, 0x0CD3A45B5D3996C5ULL, 
            0xEDE3DC07F65E4648ULL, 0x4940CC78FB5FE4C6ULL, 0xEE474BCD3AFD023BULL, 0x51C29E03A49DBB05ULL, 
            0xE8BAD4C8285BD0F2ULL, 0x02B833F36EF128D2ULL, 0xBF7E886442BC624AULL, 0x6F1C266F02BBB0CCULL, 
            0xB74DFE995E794E8CULL, 0x640B300DB36B10DDULL, 0x06A45919E8E8CE38ULL, 0x87F2FFB9D0201C67ULL
        },
        {
            0x04B35E5ABD0A8193ULL, 0x8AC6BF518CD84150ULL, 0x885ED48744A657B0ULL, 0x6D785538F63F0560ULL, 
            0x5E778F69F26AF869ULL, 0xF85777168FBCC500ULL, 0xCBF5B5F8FDEE677CULL, 0x4127A9EB2DFF2DC9ULL, 
            0x4F01ADC63CED03D5ULL, 0xA4450E41A309A25CULL, 0xF1771FF86818DEC9ULL, 0x0F4FB75472F793C1ULL, 
            0xEEC49C8BF1B25346ULL, 0xE6B2C7F5DC33082AULL, 0xD4179F8743ABC855ULL, 0xF666EAE3E01DAEF0ULL, 
            0xC5D1F6BC600153C1ULL, 0x886690BBA3066E61ULL, 0x495748CF4210B884ULL, 0x6D9F7617632DC499ULL, 
            0x87FDA76B8CA23E39ULL, 0x6DF2C31AF2F198B7ULL, 0x8B8B6C64D2F5E9E8ULL, 0x79D728C7EA695036ULL, 
            0xDD9B49C906DEE26AULL, 0xAEC589A10C0513D6ULL, 0xA431C6892F37B0B2ULL, 0xA6A2C66CC4C19AFEULL, 
            0xDCA026B5F65BE78EULL, 0xF56FF362C47F2127ULL, 0xDF0C0E87FB5ED601ULL, 0x68C33756E8663E31ULL
        },
        {
            0x223AF8A300201A6DULL, 0xDB81DA3B3542EA85ULL, 0xBB1B0DD630E71283ULL, 0x425FDA793EF95ED3ULL, 
            0x5913D4D077E12107ULL, 0xB383B84345C36714ULL, 0x18C39EC54AB4EFF8ULL, 0x578D984C45FB9E2FULL, 
            0x9D5F1E8C6ECF1FEEULL, 0x20E2A727C93CE247ULL, 0x2295138E71EB8564ULL, 0x75DB617B35610F1BULL, 
            0x06368751EFC2583AULL, 0xCF58CE589DF62F6FULL, 0x5FD5D7B53105E1CFULL, 0x92F858F6BC16BDD4ULL, 
            0xFD013F0218856A62ULL, 0x6E1930117D2D5539ULL, 0xCEF6764BBB513748ULL, 0xB3801995A9FA39E0ULL, 
            0xEBEC4F25DC128D2CULL, 0x3A678F005211736AULL, 0x87A21BF6F3827AEFULL, 0x127DA68F69F43BD5ULL, 
            0xEDE3E55D167F6506ULL, 0x77A314C2986020F9ULL, 0x8FBAFA6E63AE8C68ULL, 0x57E2C2817C85A572ULL, 
            0xF1780C657662180AULL, 0xC1DDE73D346568B1ULL, 0x2312B9FD81FA69BEULL, 0x4E864D8B9ACBFBEAULL
        },
        {
            0xF45B76C695EE60ECULL, 0xE53B1CD7F46F6009ULL, 0xD433EEE646FD776EULL, 0x760AAF8523ED5C58ULL, 
            0x17124580886ABD69ULL, 0x498E729F9CE039A7ULL, 0xDB2B02F095F3AF2DULL, 0xAAAF6025FAADDB39ULL, 
            0x84AFD48A53C419B8ULL, 0xDF8C26A545F449E4ULL, 0xED7CE3EE9831E9EBULL, 0x5E86A67367FC1FE0ULL, 
            0x130744B51E19E975ULL, 0xAFBC04930F7E4DDDULL, 0x1AAB0369F9F36D37ULL, 0x6BC0291FB73E762FULL, 
            0x9B6459917D89F5EDULL, 0xB298EFCA92BE981BULL, 0x1286ED7A280ED793ULL, 0x5F647D4EF017E7BBULL, 
            0x366DF4C641C1FE7EULL, 0xDDB238B3F7105E9EULL, 0x99DBB779B5590329ULL, 0x6FAB07426E261F04ULL, 
            0xC2B6A7FADA817457ULL, 0xC5D04EE0FC70A270ULL, 0x0A6F0C91581D7194ULL, 0xBC4B5C50E030D22CULL, 
            0x53BD5C259C3DABC3ULL, 0xD50AB4E72A65A1ADULL, 0x991CD94CF14FCF59ULL, 0x03387DF99CFAC3A3ULL
        },
        {
            0x0ECB348F632C3435ULL, 0xFA88D6D9702F14B0ULL, 0xE327DF5E6A02C82EULL, 0xC1F020B11F6433FFULL, 
            0xF958EF13DCAF2FF0ULL, 0xF8F585F47BD67CBDULL, 0x8BCAE13533489C9CULL, 0x365AE4498780DDF2ULL, 
            0x7DE80BD36286CEFBULL, 0x0681B804883594F6ULL, 0x0D526D26DC008A59ULL, 0xDC0810FF89F469ABULL, 
            0xBE30FA471D9BFE4DULL, 0x11CA5D808A4D9CCCULL, 0x18B6832C69EB9F69ULL, 0xC4E139168BE15449ULL, 
            0x478CD2083E5A4F5DULL, 0x33031F3EEE24628DULL, 0x6F66B6001B50BD1AULL, 0x4B138C5E5444E0C4ULL, 
            0x110474241AF5EB3EULL, 0xFD758B485F9468C8ULL, 0x7DB36016FBEB3811ULL, 0x011301674B114721ULL, 
            0x88DE5BEB0AC66534ULL, 0x39976F9DEEEE688CULL, 0x87FE46BB0DD989FFULL, 0xD1E40E860075A58CULL, 
            0x6BBF974321A34904ULL, 0x9AD59A88D0021BFBULL, 0x1F025DA65555482DULL, 0x39DBA2DA3D934160ULL
        }
    },
    {
        {
            0x2234BFBFD0A577BEULL, 0x148C1A53C976C28DULL, 0xEE3A13629C02EEB3ULL, 0x277E8A349B790893ULL, 
            0xCE9A444AA826EF12ULL, 0xDAB2CD7754DD6268ULL, 0xDF75BF9460CA0565ULL, 0x8DF018C53C8AC219ULL, 
            0xBD946B6F3A26A6E6ULL, 0xBA004351EDECD226ULL, 0x4D71095AA609E2BAULL, 0x948F5C8E5E68A0C7ULL, 
            0xA615CB9070C6578CULL, 0x4A997BC97A59B199ULL, 0xBC6A5AFDEAC8C44FULL, 0x57154BE680DC8C6CULL, 
            0x58A665C9970F0286ULL, 0xA3F3C4B267B52165ULL, 0x7A54038B91E544A4ULL, 0x0D33277D1EC145F0ULL, 
            0x585DA7EF91AB6A2EULL, 0xBA9DFAEB554CABFEULL, 0xEE57F27EE87136ABULL, 0x547A0242E8DBDF50ULL, 
            0x4200365078F2208FULL, 0xB1C408B371AFC9C5ULL, 0x6027F7C7F8C76F90ULL, 0x8202388671F5B532ULL, 
            0x4F515DFA21B319BDULL, 0x935D984D1AA04E95ULL, 0xFF4D268B905C04C0ULL, 0xAED9158CFF6719F9ULL
        },
        {
            0x006562DE970F86D2ULL, 0x977327805E74E879ULL, 0xFA2B361043371FD0ULL, 0xD8339B6A3C71DAC1ULL, 
            0xC8D6E7A7E4B0604AULL, 0x31290DD32D9B2950ULL, 0x4A747EBBD518A267ULL, 0xB8B6EDC9A51F9BC5ULL, 
            0x6BC235EDDA244964ULL, 0xB62A99122B8096D5ULL, 0x7357F78997A97F74ULL, 0x68FE7C838784CF32ULL, 
            0xCBC1C43A779481EDULL, 0x4A6DF925A3A96684ULL, 0x3798A17A7CE50D87ULL, 0x17AD30338E9EED20ULL, 
            0x064917AAF990F003ULL, 0x83F86BD5A685DB86ULL, 0x315D9ED70041A0EFULL, 0x5B6A3D92A173DAE6ULL, 
            0x9BA3697E5DD351F0ULL, 0xF57B94FE07CEB3E7ULL, 0xF150FDB711E4B6F5ULL, 0xE8599933347955D4ULL, 
            0x6EBA5CAA93A4EF95ULL, 0xFE6B8F31EBDB228CULL, 0x9FAC6696F8EDA5ADULL, 0x35629C482D4887C8ULL, 
            0x4173225EA58C74A5ULL, 0xC5E2F6B150FF0FAEULL, 0xCEFDBED5D5030E16ULL, 0x11B1CAFFB4F1A530ULL
        },
        {
            0x705FD53865D62ADDULL, 0x56B2CD11128D8A60ULL, 0x640D745D58D36BA6ULL, 0x44309C2256646CBAULL, 
            0x3F0B6606D57A29CBULL, 0xEEFC0782E84F162DULL, 0x13B8C9F98380ABFFULL, 0x7AB48A6941AED1D3ULL, 
            0xFD6601AC779460D6ULL, 0x63441DA97BCF07C0ULL, 0x52CADAD5674B4769ULL, 0xF78F31B8DD0666ABULL, 
            0x51D4795A029FF745ULL, 0x7EF8DE937CD1DE5CULL, 0xEA62D9DA92BB6AD2ULL, 0x8EF1ED4CCC6253A5ULL, 
            0xFAD83794DF38BC7DULL, 0x3ED3A124EF45534FULL, 0x682F0A514D01E3D1ULL, 0x937DD09A8339898BULL, 
            0x254F6C7757A24258ULL, 0xEC0AEC763D148EC0ULL, 0x285D959D85F91F89ULL, 0x728C1E5575BCCB68ULL, 
            0xB6335734C17B2D91ULL, 0x0C8930C90431172CULL, 0xB7A1937BC6D539EAULL, 0x386167D171F12C58ULL, 
            0xEB181B56D3CD25AEULL, 0x05E37DE3525A3075ULL, 0xB48E85123BD7C7E2ULL, 0xD0D6887DDF96BE94ULL
        },
        {
            0x63A48F786EBDB26CULL, 0x6B7C1CA1232C9241ULL, 0x4F8C53816073CE2CULL, 0x03018D72D95FA8A0ULL, 
            0x7B9EB10C57181B6FULL, 0x3ACC8B728558D2B5ULL, 0x224A4B32D63141A9ULL, 0x4C44A99CB989CC76ULL, 
            0x8066E8B13A518D3EULL, 0x40F1674CB3610A42ULL, 0x425185A0547DC4C8ULL, 0x19D6633E32C4FBFDULL, 
            0x142FA079C7717004ULL, 0x4B0BB89218956FCAULL, 0x6D2F5CB5A01A3439ULL, 0xE0DCB9BD8FFB19A0ULL, 
            0xD565706E364B008BULL, 0x440461F4528ECE22ULL, 0x4E2A1B0FF3CBA019ULL, 0x183BA7323BA513A9ULL, 
            0xFDC949333DD9F9E1ULL, 0x4737C56C43C266FAULL, 0x5969D7C4D600A0A0ULL, 0xFC6E22341933E733ULL, 
            0xD470F5FA86AEEB19ULL, 0x620C15311F717750ULL, 0xF5C8CD39B73C5E6BULL, 0x646BB2A6AFFD303DULL, 
            0x695F1A6D07877F89ULL, 0x559CECE990CF8D15ULL, 0x7578F458A4677203ULL, 0x7CB4FEB4E52496BAULL
        },
        {
            0xEDE6076AD7DED488ULL, 0x0780294C55114732ULL, 0x0CDA2E1A28FA6FBFULL, 0x5C104453F668110CULL, 
            0x78C1E7ACE6760767ULL, 0xCEB8F0267005BA1EULL, 0x8F4697A3C36FBDAEULL, 0xF28F569A2076AFF2ULL, 
            0x0071D7C97307B08AULL, 0x1DCDFC920BCC4F31ULL, 0xB604A25BC2712357ULL, 0x4DBB91A40FF547B7ULL, 
            0x96E27DB06ADE6FF4ULL, 0x0F76B4DC70C8C020ULL, 0x317DFCC1576DAD55ULL, 0x899D345CE2C681C0ULL, 
            0x9D598C668ACF82EBULL, 0x27D6FDDA68EF746FULL, 0x15A6A5A1692E1100ULL, 0x5F032A9886C7CB38ULL, 
            0x7F4B4A33A4358140ULL, 0x3D4196AA78B14D7AULL, 0xF17173D9750CE956ULL, 0x0B09D2142BD67032ULL, 
            0x9FA4D697AA601C7AULL, 0x4E28A1BE22B44117ULL, 0xC73996D32BBB6D75ULL, 0x60D21EDE3D62ACA3ULL, 
            0x1D97BBA0F5BD057FULL, 0xF305EFC302344084ULL, 0x38D7275C69D5512CULL, 0xF9A7C7ED91710B30ULL
        },
        {
            0xC7AB5E27E4013310ULL, 0x3F08C683C6642383ULL, 0xECF85A1469D031DBULL, 0x5AE6043DA32E0AAEULL, 
            0x6D7A3D289FF6B08EULL, 0xFB60580D26E79A85ULL, 0xB647BF0998FE8676ULL, 0xB7CD04E3D5E1127EULL, 
            0x6FD35CA521257096ULL, 0xCDE3248B4AF02E9AULL, 0x4CFC3F77B2183FCCULL, 0x4157C1D461261952ULL, 
            0x27BE722CC8805404ULL, 0x57DF0E6A003A2ABAULL, 0x9B333E7E90011687ULL, 0x659B848B8C2032CCULL, 
            0xE91756D30E3D7926ULL, 0x0C6076642866C398ULL, 0x91F610A63DF30527ULL, 0xF3EEAFD5A0FE5D78ULL, 
            0xA8A3F86FBB5D7083ULL, 0x2F2EC260DDB1FE16ULL, 0xD63BEA6D9ED8D8F6ULL, 0x51E682A2B17F82EBULL, 
            0x88D2693B535DD830ULL, 0xC1BD6A2572ADCCF9ULL, 0x3AA90FB9DB32134BULL, 0x7E6BF01C93CDFABCULL, 
            0x4702A46D36594E8CULL, 0xF7E8F5A532A5F132ULL, 0x7F2E1FABB01CD263ULL, 0x0D524419ED6A0DB8ULL
        }
    },
    {
        {
            0x7DB255C452C066E1ULL, 0x3A9A09F97068BDBFULL, 0x4C8EF0EA6C2914ADULL, 0x18AC71B7BD26A06CULL, 
            0x9EB7E4158D414FAEULL, 0x775CAD8AC50B76EAULL, 0x97701DF326EC20A0ULL, 0x7D099BCA1E98F25EULL, 
            0x1752C4699369FDFFULL, 0x1A9446F70866AE84ULL, 0x8F24B900710B459FULL, 0xE2F436B6CA590EADULL, 
            0x58B6DFC864010F9EULL, 0x5BF62D2155C41105ULL, 0x15079DB3A68A57FCULL, 0xC82F89EAEF441799ULL, 
            0x4FE0E702ED87B6C3ULL, 0x3C34F4A54CBAAB50ULL, 0xB37C653A5986C5E1ULL, 0x6E752D64AC91C95EULL, 
            0xDD6B577C072E6DA8ULL, 0xD42BA4A73934B036ULL, 0x6CA9BEAC2FC9FADBULL, 0xE81F6BBF0D384ACAULL, 
            0x2941BD0E081E386CULL, 0x0ABE3E7019845168ULL, 0xA1D0686A0A704859ULL, 0x6FFCF415849FE5AAULL, 
            0x8E526AE4B7CB344EULL, 0x86EC04C030078228ULL, 0x0AC3819D91B0010FULL, 0x2DBD38C69C561C7CULL
        },
        {
            0xA7E761337AD44C33ULL, 0x05A16B8CAD13B1C9ULL, 0xE9E5A923B1AE5964ULL, 0xBC661972EBB54712ULL, 
            0x6891639DD70C11F6ULL, 0xE1F98D744902D59BULL, 0x6A7CD20429A60120ULL, 0xE9C66B3809AF676CULL, 
            0x7932168D6E3FCD0AULL, 0x5DE2F1383391F6ACULL, 0xDCE20E7CF6A1B5F0ULL, 0xF89EE0A398D74021ULL, 
            0xCA7E24D15911DF12ULL, 0x1CB38F04BD2AD1ACULL, 0x46EC1ECBDE45C19DULL, 0x8D798A3003CCF172ULL, 
            0xCC2456D0A5B5BF74ULL, 0xD6EDB91BC48D8904ULL, 0x528A002CA89EA10FULL, 0x3DFC84F39C77B93CULL, 
            0x2BE58C6C659F3D1DULL, 0x5D0A87F728957718ULL, 0x964BF8A28B8641DCULL, 0x2F6173B3E1D4908BULL, 
            0xA2CADC738D936E50ULL, 0x02274D75BD0B7432ULL, 0xA47868BF217AF627ULL, 0xB448CF872BBB9FEEULL, 
            0x3787A8BD7CCBB108ULL, 0x3F75D590AC7649B8ULL, 0xEAE06757B1940383ULL, 0xC964084912170922ULL
        },
        {
            0xCD6118278546E38DULL, 0x03651CFE0911A2B7ULL, 0xF3E8627AF7CFE5EDULL, 0x040164E43E4DAAAAULL, 
            0x3D7E554071E2F8C1ULL, 0x4170EA4C3B451B26ULL, 0x0E1C54E4A5794ED3ULL, 0x170AC9C887371EC2ULL, 
            0x6FD5CD4028B6B592ULL, 0xE25F4F57FA244CF8ULL, 0xC9BA3F96D175FA81ULL, 0xA12AFE5B4230E6CEULL, 
            0xDCA6CB4C1830EAEEULL, 0xECC025A00B22398CULL, 0x5E5478BD52E19E4CULL, 0x74C24C606F80C19FULL, 
            0x07987B61E1393199ULL, 0xEAAF59A88C4C898CULL, 0x4EDCBBD8E27E0C38ULL, 0x1BD59A87F3EC20DCULL, 
            0xE96008839081E680ULL, 0xF166C5765E2CFA98ULL, 0x822DDC03B0B1FA3CULL, 0x8B89B3E5651E69D1ULL, 
            0x93F37D93A45BC4F4ULL, 0xA37038445C0044F4ULL, 0x194A94C41EC12E8BULL, 0xB5D067E66181BAFEULL, 
            0xCF83D8F9FDA2BB75ULL, 0xE65292233D6B2A38ULL, 0xE6E3BF92DDEA53D5ULL, 0x3B68E19916861507ULL
        },
        {
            0x9500B6851515A6A5ULL, 0x6180F105633A563CULL, 0xB6F5A4264DD4C1B6ULL, 0x51ED28E1F79AEB47ULL, 
            0x7EA001FCF3C0EFDCULL, 0xC123FD4D7A9EECE7ULL, 0x3596857DD44E7711ULL, 0x14756365B542833EULL, 
            0x97850CE461F17EDCULL, 0x16AFB72FEB33AAD9ULL, 0x936AA0F9ABE40B82ULL, 0x2E95F397A5468C2AULL, 
            0x5B7A4D789A54C0A0ULL, 0x87B222D76C8236FCULL, 0xAC3F335FCC8D7E8DULL, 0x9FD2C0C04E88BC32ULL, 
            0x45B1EA94EF987565ULL, 0xE6A1C30178AEF27CULL, 0xD945BC7168D10653ULL, 0xAA741BA2F373AC63ULL, 
            0xC7590E729B319C6EULL, 0x16D81B21EC0E864BULL, 0xCA409FD449D5F2E7ULL, 0xA01900E2E145C7ABULL, 
            0x284DF153CC7D5180ULL, 0xF6644584B0FDD0A2ULL, 0x6524F5FDA9744F8DULL, 0x64F780DD8EFA3CE6ULL, 
            0xF044A14EFB558ED1ULL, 0xFCB97A87348A5094ULL, 0x8E1D1FBF1A3E6DEAULL, 0x92C033E496687373ULL
        },
        {
            0xC2865DD9CBE21F3EULL, 0x08313EDD2CC19FBAULL, 0xD918D896F69F1683ULL, 0x8C8929A0585FAD4EULL, 
            0x65B2A6CB82258736ULL, 0xB25AA43346C8A017ULL, 0x9C553E025240CA39ULL, 0xE11C2025E352F54BULL, 
            0xB14BCDC3B1D5E0A5ULL, 0x310A81F65E5D1426ULL, 0xABE44D6F1625C169ULL, 0xCA5536CC67B66AA7ULL, 
            0xBB65949115819A52ULL, 0xA99925CFBDD170A3ULL, 0x3130B8CF09AEA6DBULL, 0xBAF7679E8C61A626ULL, 
            0xF898EF22D6D341D2ULL, 0xF14E9F7332710C6AULL, 0x4F6CEE153D0D6995ULL, 0x1761A12D17A11274ULL, 
            0xDD76ED33BEC1CE4FULL, 0x892A4A13C086EB5CULL, 0x84194A49B630BDD1ULL, 0x8ADB9C45EF3C2FC3ULL, 
            0x589911A7CF626985ULL, 0xFE4489C67DE06378ULL, 0xC15A58BDA9778687ULL, 0x169E96C0EBD2274BULL, 
            0x738598AF67AC260EULL, 0x29C22767004FCC4CULL, 0xC2A67D72366A9E7FULL, 0x6248477DE26E48C7ULL
        },
        {
            0x8B29A865BDA4F05AULL, 0xA0E40945BC33D7F9ULL, 0x0F8D93723326C137ULL, 0x5ACA81916F8B224FULL, 
            0x7A2F5B56AFAB2265ULL, 0x712A09A13810A9B5ULL, 0x236F27E376893816ULL, 0x2F9809DE79CF431EULL, 
            0x4926A50D71167589ULL, 0x9467C0068202A43FULL, 0xCD331EE2CD93EF59ULL, 0xA90CDC1F71E29D0CULL, 
            0x30CAB36019ED4D9BULL, 0xE9C418A546E73F11ULL, 0x69324A26272CE578ULL, 0xD5425A7C4259E862ULL, 
            0x90BDC928358DB602ULL, 0x63B1EC1F8644CCFDULL, 0xA215D6131988C86CULL, 0x7574042948B739DCULL, 
            0xE66AD8CF8E672991ULL, 0xCAA80922940A5A4FULL, 0xF960632DF7CBAA13ULL, 0x07FB3B0CF0901E08ULL, 
            0x641A72168932CF18ULL, 0xD45134149645F884ULL, 0x7D171BAA917E1F90ULL, 0x66F96A37E05E142FULL, 
            0x87C1717493B7206EULL, 0x03AE59E918EC1BA7ULL, 0x4AD7DDE354281BA5ULL, 0xE59BD80E838620ABULL
        }
    }
};

const TwistDomainConstants TwistExpander_Menkent::kPhaseCConstants = {
    0xF8BBE5BC1EB7FFDDULL,
    0xE960B08BABAD512CULL,
    0xB80032A15EBA4138ULL,
    0xF8BBE5BC1EB7FFDDULL,
    0xE960B08BABAD512CULL,
    0xB80032A15EBA4138ULL,
    0xF33AA4264D95DD45ULL,
    0xDD1B7E9A80D1E633ULL,
    0x26,
    0xF1,
    0x82,
    0x43,
    0xA6,
    0x49,
    0xDE,
    0xEE
};

const TwistDomainSaltSet TwistExpander_Menkent::kPhaseDSalts = {
    {
        {
            0x52C893F569189308ULL, 0xF06D7CC3D9063113ULL, 0x59954B51D2D9DB01ULL, 0x311B33FC9BF3B206ULL, 
            0xA5404FFCDB70F123ULL, 0xEE9AFFF8942D45AFULL, 0xA79F7D2FDCA6F6F8ULL, 0xA870B4C0EC2674E2ULL, 
            0x92D798C9EE76CF53ULL, 0x6C5CE7F9127B9EFFULL, 0xCE5EC3FDCFC5B6DDULL, 0x9EBAA584F71D6E4CULL, 
            0x409F7467692BFBD6ULL, 0x34B696205DB7C253ULL, 0x6216E6821A6ADC8CULL, 0x4AA0A505B2E1DA41ULL, 
            0x678E8C5D2ED7FC95ULL, 0x0A6A72C94580B877ULL, 0x65DAFE9EA982FD42ULL, 0x6EB420BA815307FFULL, 
            0x1DB12D2B30D27E83ULL, 0xA64819B7DF83FFB1ULL, 0x82AA2840CABCC648ULL, 0xFB867C0D27546175ULL, 
            0xA663A823C079EE6BULL, 0x1D1D9BC220CE1009ULL, 0x797537D8CD5B0F6CULL, 0xBB8665D310FEB738ULL, 
            0xDABCABF604F8AD63ULL, 0x359B5887B286BCF0ULL, 0xD04A3ABB30CB1C52ULL, 0x6D90BF969202D268ULL
        },
        {
            0xFB5CC4E99B054ABEULL, 0xF208C2C693A29BDFULL, 0x435FE07B28E1FA25ULL, 0x43D41835B0440316ULL, 
            0xC2F841FA095D4DA3ULL, 0xBE77CC654C251734ULL, 0xAD6F33D25E2F9D0FULL, 0x710AC90738C1C0CEULL, 
            0xB636BD19E6D760E1ULL, 0x6CE31C6AE59A70FCULL, 0x69F0077D6083E6B7ULL, 0x9A279945F6191D97ULL, 
            0x050DC00DB38E7188ULL, 0xC32939FE8257F354ULL, 0x4CE66564F52EB6CDULL, 0x0D0C16201DF001FFULL, 
            0x5D24E21C525A997BULL, 0x7A5484A4877B3589ULL, 0x9EC4613F46F63B49ULL, 0xC9E3247E684C0BD0ULL, 
            0xFEE3A2860F897374ULL, 0xB8AE8A53D857614FULL, 0x1E0D810B664A3F65ULL, 0xFFC571A4DA1B4C15ULL, 
            0xEB2D72F84615EA87ULL, 0xA7C56D59EDD7F98EULL, 0xFE3EA77C1777737CULL, 0x733BFE6C0D28708CULL, 
            0x0BFCAFCBA86DCFD5ULL, 0xB8B30F35022D196CULL, 0xCE7161AA9316CA0EULL, 0xDC765DD7C65B6FD3ULL
        },
        {
            0xE1D935A7BB8144D9ULL, 0x897DB7F788BAAFFAULL, 0x4B5AC368D8D9DB60ULL, 0x9BE21D0163092749ULL, 
            0xDBA606CFAD41D301ULL, 0x155E71325408BAFFULL, 0x268F54C557E22576ULL, 0x41C1441F1D3E7DCAULL, 
            0x8C61AB522414F700ULL, 0x0E992639B6F5A771ULL, 0x442A6583D9A93181ULL, 0x1D88F67646487CCDULL, 
            0x46A36F442E53CAC8ULL, 0x9B3186B98E98A91BULL, 0xA8BDB2146C3D2BB6ULL, 0x81581CCF4AD5C3C9ULL, 
            0x4218F65DDB19C1B5ULL, 0xA2E293B3CD4DEB58ULL, 0xBD04C0054B52E163ULL, 0xC469A2DA6578C2C3ULL, 
            0x49548B48C3FE6BCFULL, 0x36F192382F3A895BULL, 0xF9F9D2F03D14205CULL, 0x8D0763A7A37067A0ULL, 
            0x4AB3C92BD0CCDA18ULL, 0x490BFECE90545F46ULL, 0xC924B96848768E74ULL, 0xF99E01EE7E57C3C2ULL, 
            0x500B6113DA69EAF6ULL, 0xD7CEF4306C9191CBULL, 0x48D8F946D2D585C5ULL, 0xF9256AFE2931866EULL
        },
        {
            0x1B48622C127D202BULL, 0x0268FCE84C8B8606ULL, 0x6C14C9470A46E903ULL, 0x037E2AA13C59B9C0ULL, 
            0xC9B0A1E35749E4E8ULL, 0xC7758FB1CB79537AULL, 0xD167EDD0B6E5DEC6ULL, 0x207855F22B917A65ULL, 
            0x420CDD366DDD42A6ULL, 0x24D47977A8F4B287ULL, 0x6DDB4B1515D4E811ULL, 0xF85E6389C8CD6EA4ULL, 
            0x54E2C3C1689D59DEULL, 0x8BDD3EC4DACFF213ULL, 0xB20D2AD5FC817BD5ULL, 0x1A0CDED5A9951095ULL, 
            0x2B39AE8691DF41FBULL, 0xB3B7F27CEC96F39BULL, 0xD6CE56BEBB40323EULL, 0x9A7CB4A0E8D0D68AULL, 
            0x1419478EB21A4D1AULL, 0x8BDADE01923EC306ULL, 0x8DC74FFCCABF1B8FULL, 0xC8AE8A5623F195A1ULL, 
            0x92E8C1A96A8AD90DULL, 0xCA1B9A816A88EA4BULL, 0xFF2D6BC7D5EA9BA7ULL, 0x6DB0BD9F717445C6ULL, 
            0xF817ED62D642C07EULL, 0x8278BDABC902922EULL, 0xD284EA157F646D04ULL, 0x894AF901CC730A9DULL
        },
        {
            0x0A93F8938EEB034BULL, 0x777B6BA2C68ED4AEULL, 0xEBD2942AD63512F2ULL, 0xDDD5680999A118ECULL, 
            0xCE8E0AD455362A62ULL, 0x6F3EFA1576A2DCB5ULL, 0x38561ED6D651A99FULL, 0x76474642B855CF6EULL, 
            0xF5896A4B615A68EBULL, 0x3561ED536B260463ULL, 0xF37DDF3CC9438751ULL, 0x1A23410D89376BA8ULL, 
            0xE5A38F2D196A2519ULL, 0x527054FFF8165187ULL, 0x8B1172D3FD085444ULL, 0xD23B934B9FC0EFD9ULL, 
            0xFDBC337E1EE42085ULL, 0x8EE31767FF2980B6ULL, 0x21C9F97F594B2351ULL, 0xA6616E9E18FBC2B3ULL, 
            0x5A942654B205ECA0ULL, 0x1B8CDFF39E3F3924ULL, 0xBA8A79604701B94DULL, 0x8EBC6C17B2DB4503ULL, 
            0xE25EEDDB9D1D282CULL, 0x443C71E76ADD82EBULL, 0x555DD9F57680CB3CULL, 0xEC6D1CF911580A94ULL, 
            0xCFB74B98C30C44D9ULL, 0x87D34339A0EA6B9EULL, 0x8F833549A2687C9DULL, 0xF521B201C2526AC9ULL
        },
        {
            0x6ED0AF91514906BEULL, 0xA94144092BD02865ULL, 0x9A83AA16E2B7D1DFULL, 0x03BC478B032F8A5BULL, 
            0xD9F7F76E2C18A1ADULL, 0x6B8A2ED2DF0C70AEULL, 0xFF61AC12C8A0A4BAULL, 0xD2B4B45997C9A10EULL, 
            0x33D62A4FAF810331ULL, 0xEC6526D6DDE81A8BULL, 0x6DB75CE10C4E88DDULL, 0x6CF5CE29280A9F98ULL, 
            0xD40CF392D992EE45ULL, 0xAEB1E10A3E5A39BBULL, 0x9E2CC587EB6D41AAULL, 0x540404A3BD4086BDULL, 
            0x15758956870A7D9BULL, 0x97788D726B3FB3B9ULL, 0x0F286112C6E84A83ULL, 0x2E5AB708F2C44826ULL, 
            0x2290F88BF46B7333ULL, 0x486A3E34B9AE49D2ULL, 0x9CDBD2667EB06D57ULL, 0xAED79C2B9EB86A8BULL, 
            0x720A4E6B23610030ULL, 0x7909643D63504FEBULL, 0x859C212BD8A7EA35ULL, 0x06E824366C7A180DULL, 
            0xE0A8EDD22441F724ULL, 0xF9C7684A9D48623AULL, 0x02E338B88022477CULL, 0xA3D098F1292CEE1BULL
        }
    },
    {
        {
            0x389ED25A4612B0AEULL, 0x1A749565C868EE54ULL, 0xD13CBD2C240D9A4FULL, 0x82EEE7C961156C98ULL, 
            0x200E204313ECA7ACULL, 0xE82273B939E35B51ULL, 0xFFC2F920D4D885E7ULL, 0x7437850FF10DFF9BULL, 
            0xA3736FB7720BDC33ULL, 0xD077AB255DB8F0FFULL, 0x1FFC8912AB7E53AFULL, 0xBA0C7FFA454D4866ULL, 
            0x4282439D4B6A932DULL, 0x6D80FD7AAC9E7699ULL, 0x388D3D86A21DC720ULL, 0x76C50FFD705164F2ULL, 
            0x11B811860F9AACAFULL, 0xDE5FE2ABE5029BD3ULL, 0xACC1FBEA4B86D410ULL, 0x6170CC3041E1D2BCULL, 
            0x0DD55DC7367F2882ULL, 0x67913688632D703FULL, 0x221464FAC92C23EFULL, 0xAF18E2299176E9ECULL, 
            0xD506F5B0EDD45764ULL, 0x81000F8AF5A67B0AULL, 0x733B013CBD9C1FD4ULL, 0xFB3B2B551502229AULL, 
            0x8381DF98E272AA42ULL, 0xA9E792F9D2E0CCA6ULL, 0xEE12DD4193932B94ULL, 0x20604F1607A9A20DULL
        },
        {
            0xE15AC8B6917E9B87ULL, 0x5FACA9840CA9F234ULL, 0xB6BC94D6BAAEF2B4ULL, 0x07F8707E888BA5D9ULL, 
            0x6AB0D2F13AC73080ULL, 0x84AC28F266BD4A55ULL, 0x5147F74036E3FC6BULL, 0x59F72CD74C2CAF34ULL, 
            0xDD7F6FCB7D416886ULL, 0x521479CAEC08FE07ULL, 0x74F1F204BBE4115BULL, 0x1AE93B4B827D6596ULL, 
            0x444932E90AF079C5ULL, 0x8758DB58039678E6ULL, 0x93B90417363AF031ULL, 0x7E31E8EDBC74D412ULL, 
            0x5D6F508DDD46DB20ULL, 0xD0D0A23DE335A4CBULL, 0x059882007CE1FF1FULL, 0xDAE20BC413801D5DULL, 
            0xFD641CBE99A749CFULL, 0x523C5EE880AF98AEULL, 0xBC0525FF02F8E8EDULL, 0x80AFBA93EC0B6BD1ULL, 
            0xB70B3A07687B9729ULL, 0xACF087109747CAE4ULL, 0x1312C037E9AB6BF0ULL, 0x609C6855B91113EFULL, 
            0x22678A9BB8E0C51DULL, 0xFCB60DBF55CDD7C7ULL, 0x2143E57CE127B9F0ULL, 0x88BC662D0EE33355ULL
        },
        {
            0x8113D07259C45EFDULL, 0xF5C3CB7CAF02792FULL, 0x65BD7992361281DDULL, 0x2DCEE97E3FDABE45ULL, 
            0x69E5241108A9286EULL, 0xDA3F168A794B7D2FULL, 0x7171955C68CA0E60ULL, 0x101CEBC4767F35ADULL, 
            0x79D22F54427E33B8ULL, 0x46602B1416921C28ULL, 0x8CF01F784F19CF39ULL, 0xAA598C977311C3ADULL, 
            0xD15A41EE4BB5C562ULL, 0x20D866BFD29EEAE5ULL, 0x728575F0DCB312E6ULL, 0x7347730B3C4D3F68ULL, 
            0x88B7BAD5B1030401ULL, 0xBADF1D4E3ADB7112ULL, 0xA51350A761F91B77ULL, 0x20678676382498F4ULL, 
            0xC38AB03B89B6B2D3ULL, 0x611C53945474C616ULL, 0xB0B3C0C4D3A6F394ULL, 0x6B38C2C200FA98D0ULL, 
            0xE6039ABB00B43CD2ULL, 0xE40C51A09F48F025ULL, 0x777FC4ABB8BA61FCULL, 0x88AEA4A7C84F3F36ULL, 
            0xBAA4951B693CA30EULL, 0x96B9B5CA9760876BULL, 0xC219B3A7B05CD383ULL, 0x8D5BAB861430FC91ULL
        },
        {
            0x35F088769E44F0D8ULL, 0xE2F8B9684AB31D48ULL, 0x566DFDDF474C8A67ULL, 0x77BDE223F9994C42ULL, 
            0x7DF7D610E84F5414ULL, 0xF2FF50B0EBD969F7ULL, 0xC54799606D4DD5BEULL, 0x8D5986C8B87E8E19ULL, 
            0xB7FBAD06663A0158ULL, 0x9B9F16D086183361ULL, 0xB337CBF017A6A430ULL, 0xE4D5333372EA7955ULL, 
            0x9A767D53272F30A7ULL, 0x39A5F1074BAC792EULL, 0x8D33AD75A21F5310ULL, 0xC5969386B6C68666ULL, 
            0x8B93FEBD191E59CDULL, 0x2F3DA7DE6A035624ULL, 0xB2A1D9FEFCF8FAB5ULL, 0x091AE75ADBC20785ULL, 
            0xB3F3A19B329CE497ULL, 0x388BC88EE7B9A2A8ULL, 0x6118B79D37A2609CULL, 0x982CF4E8D4A6CDADULL, 
            0x308C9537FEA10481ULL, 0xF380CDAEE61D5341ULL, 0xC33D88E2112A6F03ULL, 0x4383EE20040DF9FEULL, 
            0x5EBD82DAF806C696ULL, 0x21A1052A71FAA6F1ULL, 0xDA59D89C2C989A75ULL, 0xA78DC4F67BD3FD86ULL
        },
        {
            0xAE71587AF12E3EDBULL, 0xC1BA64D333C11189ULL, 0x4AFDE723A252C876ULL, 0xC7ED96664BCFC785ULL, 
            0x0F60D203F038F621ULL, 0x0A5260FD8810E776ULL, 0x1F6219D963B26892ULL, 0xD51F1F957E21DD86ULL, 
            0xB7512E3D8F676C5BULL, 0x2F8FB554644B5D99ULL, 0x864B66E448373A8FULL, 0x062D02D00E9173DEULL, 
            0x257EC54B69D0C898ULL, 0x23878915A1895691ULL, 0x5B4CBFE96FC6BF45ULL, 0xF27264DE7FBA7CD9ULL, 
            0x59742CB87D765ACEULL, 0x2A2ED36CADBAA51DULL, 0xF5994120CCC1CBC8ULL, 0x25586893F2B630A4ULL, 
            0x5CA5A90ECE3EE844ULL, 0xB5A01991A1C22CF5ULL, 0xBD21DA135E6EEB15ULL, 0xC06248AF42440B9CULL, 
            0xB76CB4253AD7D638ULL, 0xECEB6587DA126C3DULL, 0xF6695AB0067ACEC0ULL, 0xC047BF89CFDFE872ULL, 
            0x06AEFBA46C5F3FF7ULL, 0xF2A0018EF86C9DEEULL, 0x18757C5B080C6AB1ULL, 0xF3468A09CB0DDDC9ULL
        },
        {
            0x62F91F299B5C34E2ULL, 0x946113A73B936C9DULL, 0xAF06F342EA379119ULL, 0xC53C8E0A5FF95E3CULL, 
            0x0AC16F3609E9AB46ULL, 0x969602481E229723ULL, 0xDC3F9792BD0EEEDCULL, 0xBD09FF34586217D1ULL, 
            0x1816D92A3047677CULL, 0x899CB22F84020960ULL, 0x2CAD5F5700EF0AACULL, 0xE0A754BAF5D18994ULL, 
            0x7EDFADBEADE51DA8ULL, 0x1C5009AC77A6BB52ULL, 0xB92E7E5C0A076CECULL, 0xA6C3A6FAFCED75B4ULL, 
            0xF103754CEBA821A2ULL, 0x979F49C4724874AEULL, 0xF505ED751383E75FULL, 0xE0FB4B530F884E8DULL, 
            0xAEF0AE14CEA3DA67ULL, 0xB3786600441E3098ULL, 0x9BD007D1C1C8A6AAULL, 0x8D5D23ECAC9415D7ULL, 
            0xF67F8F90AE7AF7C8ULL, 0x693ED1A0D2225D0AULL, 0x83E830FE32EEF6AEULL, 0x69FC09A0411D19C4ULL, 
            0x86224B1AA2C01D2BULL, 0x473D14BA7813E7D7ULL, 0x80009222D9E430F7ULL, 0x08999C223A4137ADULL
        }
    },
    {
        {
            0x0BA5C5E87C68AEB9ULL, 0xD6D9A20D102207D0ULL, 0x011CA14A6DD99117ULL, 0x7221855AF1D29027ULL, 
            0x3B2277914785B817ULL, 0x5C9ABA545BE64B75ULL, 0x3B3F49907BA5A080ULL, 0xF11DBC7978FD4CD7ULL, 
            0x081834D754F98A9CULL, 0xBC3CA76425E4BC1CULL, 0xC9CA1EF8A2502816ULL, 0xA63696C1941CEC10ULL, 
            0x5824A746108EF586ULL, 0x081CEB1BBFFFF6FEULL, 0x13C86B25025158B8ULL, 0x6BEF558D0ABE6FC1ULL, 
            0xE6A761516A060C81ULL, 0x1BD525304C4C7048ULL, 0x9F56E5944E0AC7BDULL, 0xEBAE1A2C9E05E7F5ULL, 
            0x1E4C5B1C189A42B6ULL, 0x32FB46DF2B8A22C5ULL, 0x41D33F5FEF64AC24ULL, 0xF19CD158B53FADE8ULL, 
            0xB59BE4949D2FF47CULL, 0x54742F7FEA2CFE43ULL, 0x5A24B4CCC059C860ULL, 0x33EB4EA20C2BB705ULL, 
            0xD8408E592674B688ULL, 0x8CE9964DAE771B45ULL, 0x2E90A4700F990849ULL, 0x31BCC1EF41E103AAULL
        },
        {
            0xD56F7A94B53BC85AULL, 0xE36BBE523A73686AULL, 0x84AE17CCCFFC8C7CULL, 0x63A7DBCB6F568AF1ULL, 
            0x83090505009ABBD4ULL, 0x8D9E5898C047F94EULL, 0x13966C8E2088BE12ULL, 0x0CA8DE3A0DF5916EULL, 
            0xF13D23474F351B0AULL, 0x2BCF5389FFBF6DFCULL, 0xE453196E2AF17103ULL, 0xFCAA7F33434E1EE4ULL, 
            0x61CCAA0AD3C67766ULL, 0xE88BD7B24709C238ULL, 0xD9AD4E4D92C607B9ULL, 0x00990B647AF9C1C2ULL, 
            0xEF2C7EC30D9389D3ULL, 0xF107BD2A26A6CE7DULL, 0x423249FDD4A15860ULL, 0x438C8DBFFBB2E7C9ULL, 
            0x4DFAC89D5D710EB1ULL, 0x9D05CBEA39ADF647ULL, 0x283DDB8C8E975BBAULL, 0xBE67DD84E1D9EF3EULL, 
            0xEEB4AD34FC742476ULL, 0x604CF45F4ADD2BF8ULL, 0xA661F3272798A8EEULL, 0x019FDCF3E3A48C6EULL, 
            0x62A8BF86F15D1CD0ULL, 0x7C638354FB1579EFULL, 0xD3F58D7883906582ULL, 0xF19ACA77297236ACULL
        },
        {
            0x92FB63121ED722FCULL, 0x018102EE9F57E716ULL, 0xCA31C2F6882E8778ULL, 0x8C2F6449AD84832AULL, 
            0x76DD3643107EFDC2ULL, 0x133D23A36DA78F54ULL, 0xA48A1F4B3383E53FULL, 0x76306E4A94B3630BULL, 
            0xD85773BB04E8FB49ULL, 0x4AFB4E3448891A8CULL, 0x9B56344C4C96BA99ULL, 0xF9B204E67B8550A2ULL, 
            0x9272E6EEF444EA7DULL, 0xF513237D4BBE6A48ULL, 0xF42D73AA4F2E8898ULL, 0xCC55A9986B3592BFULL, 
            0x0E617F1791980E96ULL, 0xFC7A69D1258A097FULL, 0x86AD952A69C744CFULL, 0x0F4FF5EA67E00EEFULL, 
            0x81AA69E710ACDF4AULL, 0xD004A2D4AD5D4DBDULL, 0xFB8331B3BA554096ULL, 0x99430120A0C6B6A4ULL, 
            0xEDC7BBAC8DC69B47ULL, 0xC4ABAA2B33C84B7DULL, 0x1EA0E3A2A0437FB4ULL, 0x7DD35200D81265A2ULL, 
            0x1EEBB1F4783E2F70ULL, 0x3BB9F00ED48AA8F5ULL, 0x5D39F35521481C4DULL, 0x2E5AC9894BC82F0CULL
        },
        {
            0xD03117D34CAD7E0FULL, 0xB4331C9C52CDB2E5ULL, 0x0D1A978F92B3A41AULL, 0xE3ABF4DCAE4A65E6ULL, 
            0x7979BF2A33BEBC59ULL, 0xF58F273F0DEE99BAULL, 0x380740BA387E6BB9ULL, 0x5E63288F88CD7213ULL, 
            0xDDBE5181589A9E72ULL, 0x6EB74F79E5C02F13ULL, 0x8872F5A3D8E25A0FULL, 0xF60DDD11A18FD1CBULL, 
            0xC5D1A69ACC3BE36EULL, 0x38092D5E94ADB4B6ULL, 0x7A0B99AF0C66221BULL, 0xCFCC3C7107500988ULL, 
            0x7169AA865197C4C4ULL, 0xFD3B831805113DCEULL, 0xC7EC210A991A279CULL, 0xDB0AB6D28FCDA8AFULL, 
            0x1D4AE3BBFE45AA21ULL, 0xF519B97D0BDE2882ULL, 0x89A218A591621E59ULL, 0x5F49FB98ACCB4BFDULL, 
            0x140A25B69C7E5B8EULL, 0x85C35513FA69FE15ULL, 0x1D52535CC0C21603ULL, 0x49E3227D350B5571ULL, 
            0x030BE2B8E6A66FB5ULL, 0x5108C88CBF0E7911ULL, 0xAF6B31464731CFDAULL, 0x13D1D74662F548EBULL
        },
        {
            0xC3F7122B9D4D8935ULL, 0x3ACCF78D9E8A64B8ULL, 0x1CA295063711C49FULL, 0x3C74BA08483D9FAEULL, 
            0xBA8FEF1859BE16B1ULL, 0x8333A4D010E76A16ULL, 0xEF0FE4E080BC1A17ULL, 0x931458230926D597ULL, 
            0xDA2223C08098E96EULL, 0x3719E20E73C99B6FULL, 0x1D0CCEE45FC7A845ULL, 0xCC5988280ADC9E54ULL, 
            0xBA61D245802B9AB3ULL, 0x889BC6768B1A3574ULL, 0xF97CEA469AF59A21ULL, 0x83302607803C708AULL, 
            0x957E0FDDCAD445FBULL, 0x73BB9FAB6FFFF4EBULL, 0xDE70DB021DDDE77DULL, 0x2BB1E738A072E541ULL, 
            0x71D99CAA24B6E7EEULL, 0xEF1AA5825AC72AABULL, 0x66608E4E2F7A2A5DULL, 0xE6AF893BDD8C7B3CULL, 
            0x08FBA59237F17A30ULL, 0xFB00174BA8D4C107ULL, 0x3C06BC367EBD00F6ULL, 0x93A54C254104E8E3ULL, 
            0x2C57AAA441310F63ULL, 0xC534C68646B80068ULL, 0xDA9446293D21F11EULL, 0x228BC50C71108211ULL
        },
        {
            0x559DFBA7F0CE92B3ULL, 0x88B6DBA7189A0D4EULL, 0xBD291F11A98E630DULL, 0xD3220082CF16EC9AULL, 
            0xF64FA99F13C443A6ULL, 0x79781E8E6832D87DULL, 0xF0341FC3C7AC0D79ULL, 0x6FD9B7FE6D76B939ULL, 
            0x2688C5EF257E2EE7ULL, 0x50C98DB36427BBD9ULL, 0x740133D8CF26DCAEULL, 0x93797A602AAE7530ULL, 
            0x4D4FC3E8BA2DF9A7ULL, 0x3641EF702BC22328ULL, 0x5A032CFF2848C97BULL, 0x19A60470CEB0CFCBULL, 
            0xF69C5C03920ADB8CULL, 0xE1BBF644BD034DE4ULL, 0xD824513FD2B4ADEEULL, 0xB07774E1509C4E29ULL, 
            0x03F27367C48954E8ULL, 0x3E7A8D2DB4351A17ULL, 0x2F93402BEA21FF23ULL, 0xCA016B25028AF7CBULL, 
            0x377DE7958D5DBE89ULL, 0x88ABF2E6A826E8F4ULL, 0x1B49B8D21F21C897ULL, 0x19001893EA604CF2ULL, 
            0x74ECBBB7056A79B9ULL, 0x15E527697A4EBE3CULL, 0x9D5C97FA3273DF62ULL, 0x5610503A3B9D94F5ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Menkent::kPhaseDConstants = {
    0x88E6DA5F3EA11ECBULL,
    0x0DEAF777D168B15CULL,
    0x6FF980654DC4A7CCULL,
    0x88E6DA5F3EA11ECBULL,
    0x0DEAF777D168B15CULL,
    0x6FF980654DC4A7CCULL,
    0x192756DC5CD60FCCULL,
    0xF0BB5DB6FE85EAFCULL,
    0x41,
    0x32,
    0x4D,
    0xE2,
    0x0C,
    0xC4,
    0xE4,
    0x55
};

