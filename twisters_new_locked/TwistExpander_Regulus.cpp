#include "TwistExpander_Regulus.hpp"
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

TwistExpander_Regulus::TwistExpander_Regulus()
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

void TwistExpander_Regulus::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xAEFCA372C1030F25ULL; std::uint64_t aIngress = 0x92F4770B665BB321ULL; std::uint64_t aCarry = 0xA66D31BDA6F99EF6ULL;

    std::uint64_t aWandererA = 0xA7E7DBA6D6986FE6ULL; std::uint64_t aWandererB = 0x9C9189A82A749DD1ULL; std::uint64_t aWandererC = 0xC5F208C255BD929CULL; std::uint64_t aWandererD = 0xC61ED68E1049BF30ULL;
    std::uint64_t aWandererE = 0xE6429B086A0D941CULL; std::uint64_t aWandererF = 0x8DAADC0D93282D47ULL; std::uint64_t aWandererG = 0x96AB167D15D07057ULL; std::uint64_t aWandererH = 0xE39FE55D403754F9ULL;
    std::uint64_t aWandererI = 0xBC5BA7A8EE6DE409ULL; std::uint64_t aWandererJ = 0xC4F74E2099C988E8ULL; std::uint64_t aWandererK = 0xC7D213C7FE6A2F03ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xFDC5B132DD5ADFA4ULL;
        aCarry = 0xA030B0F2316F6F85ULL;
        aWandererA = 0x8360E8559EBAA0D0ULL;
        aWandererB = 0x9DA9F422827220E3ULL;
        aWandererC = 0xCF8E66E9A9050529ULL;
        aWandererD = 0xDEC8BD49BF79D73AULL;
        aWandererE = 0xC8112ABAE3EE1728ULL;
        aWandererF = 0xE204BF56E7B719D6ULL;
        aWandererG = 0xD71C95FD17C093F6ULL;
        aWandererH = 0x96AFB3D4E4BCDB14ULL;
        aWandererI = 0xFBEB728438E8F984ULL;
        aWandererJ = 0xBC75BF33CC6451E0ULL;
        aWandererK = 0xDBD0B40E3793964BULL;
    TwistExpander_Regulus_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Regulus_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Regulus_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Regulus_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Regulus::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xCD7D7179049044F9ULL; std::uint64_t aIngress = 0xAAC83B592C57BB04ULL; std::uint64_t aCarry = 0xDA9956DE81B57964ULL;

    std::uint64_t aWandererA = 0xA941E9F969B1CF3BULL; std::uint64_t aWandererB = 0xF0A87B2D4C761632ULL; std::uint64_t aWandererC = 0xC645FDE20DFC7221ULL; std::uint64_t aWandererD = 0x81024DB87B5C7019ULL;
    std::uint64_t aWandererE = 0xF15AA0DEE2E93C87ULL; std::uint64_t aWandererF = 0x9BAF53E8E409FDAAULL; std::uint64_t aWandererG = 0xC2D7119948F4FE1AULL; std::uint64_t aWandererH = 0xFE430926DFE674CBULL;
    std::uint64_t aWandererI = 0xC1E0453C99900A82ULL; std::uint64_t aWandererJ = 0x96F55A04641178ABULL; std::uint64_t aWandererK = 0xDF0F28587767BD59ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x86811D9EA51684F0ULL;
        aCarry = 0xA708218A89907273ULL;
        aWandererA = 0xDB786413B87BA612ULL;
        aWandererB = 0xD18BAA31FF1C46FFULL;
        aWandererC = 0xF980232C8506634BULL;
        aWandererD = 0xD552F1679C446731ULL;
        aWandererE = 0x99BAB036B4A65525ULL;
        aWandererF = 0xFCAE19630B107B24ULL;
        aWandererG = 0x92FCAE908BF06958ULL;
        aWandererH = 0xDF71069C0C138D64ULL;
        aWandererI = 0x9DAB30EC84D0FD68ULL;
        aWandererJ = 0xF9175468B20BF4B5ULL;
        aWandererK = 0xEDE2655E8B24D46FULL;
    TwistExpander_Regulus_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Regulus_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Regulus_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Regulus_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Regulus::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD4326987BCE8127BULL;
    std::uint64_t aIngress = 0xAFA702A3E2B8FB6AULL;
    std::uint64_t aCarry = 0xA262CA401EFF99C7ULL;

    std::uint64_t aWandererA = 0xA3E0F044D0BF72D0ULL;
    std::uint64_t aWandererB = 0xA5A1ED7D4FFA8C6EULL;
    std::uint64_t aWandererC = 0xCA83BC46A53E472DULL;
    std::uint64_t aWandererD = 0xCF0D34F0A70369EEULL;
    std::uint64_t aWandererE = 0x817248B6286983D0ULL;
    std::uint64_t aWandererF = 0xC39B603FE3523207ULL;
    std::uint64_t aWandererG = 0xAEE199DAB6F804F6ULL;
    std::uint64_t aWandererH = 0xA51FAF4926856DE4ULL;
    std::uint64_t aWandererI = 0xBE599CE3BF759E64ULL;
    std::uint64_t aWandererJ = 0xEAB43890E2FEA392ULL;
    std::uint64_t aWandererK = 0xF15806DB51BA3F34ULL;

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
    TwistExpander_Regulus_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Regulus_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Regulus_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Regulus_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Regulus_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Regulus_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Regulus_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Regulus_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Regulus_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Regulus_Arx::GROW_B(pWorkSpace,
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

// SmartSquash candidate 27 of 33
// Exploration cases: 100000000
// Nearest-family diversity: 914 / 1088 (84.01%)
// Total distance from earlier candidates: 24266
void TwistExpander_Regulus::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    static_assert((S_BLOCK / W_KEY) == 16, "SquashInvestToKeyBoxes expects 16 invest fragments.");
    static_assert(H_KEY == 8, "SquashInvestToKeyBoxes expects 8 key rows per box.");
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 14U), *aFragmentB = aIceLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 13U), *aFragmentD = aIceLaneD + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1893U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1299U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1480U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 855U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 8U), *aFragmentB = aIceLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 12U), *aFragmentD = aIceLaneD + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 617U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 946U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 805U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 958U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 11U), *aFragmentB = aIceLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 2U), *aFragmentD = aIceLaneD + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1703U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1921U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 394U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 301U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 6U), *aFragmentB = aIceLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 15U), *aFragmentD = aIceLaneD + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1886U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1136U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1550U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1969U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 5U), *aFragmentB = aIceLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 9U), *aFragmentD = aIceLaneD + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1000U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1165U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 848U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 311U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 13U), *aFragmentB = aIceLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 5U), *aFragmentD = aIceLaneD + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 830U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1967U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1509U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1010U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 1U), *aFragmentB = aIceLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 7U), *aFragmentD = aIceLaneD + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 406U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 354U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 181U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1699U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 7U), *aFragmentB = aIceLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 3U), *aFragmentD = aIceLaneD + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1920U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 305U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 417U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 670U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 9U), *aFragmentB = aIceLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 14U), *aFragmentD = aIceLaneD + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 69U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1740U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1700U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1729U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 10U), *aFragmentB = aIceLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 6U), *aFragmentD = aIceLaneD + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1938U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 74U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 547U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1001U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 0U), *aFragmentB = aIceLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 4U), *aFragmentD = aIceLaneD + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 566U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 158U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1041U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 752U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 12U), *aFragmentB = aIceLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 11U), *aFragmentD = aIceLaneD + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1929U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 514U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 980U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1204U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 2U), *aFragmentB = aIceLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 1U), *aFragmentD = aIceLaneD + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1231U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1038U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 612U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 433U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 4U), *aFragmentB = aIceLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 0U), *aFragmentD = aIceLaneD + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 308U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 66U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1048U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1669U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 15U), *aFragmentB = aIceLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 8U), *aFragmentD = aIceLaneD + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 197U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 873U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1854U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1818U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 3U), *aFragmentB = aIceLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 10U), *aFragmentD = aIceLaneD + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 936U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 657U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1453U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 2034U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Regulus::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA985C66F49BDC920ULL; std::uint64_t aIngress = 0x800DBABD82CA6628ULL; std::uint64_t aCarry = 0xED2B6731AA2D8AFAULL;

    std::uint64_t aWandererA = 0xF98A2C612CC370D9ULL; std::uint64_t aWandererB = 0xD95DF6D10D3CB0B5ULL; std::uint64_t aWandererC = 0xCB35B03BB3BD0107ULL; std::uint64_t aWandererD = 0xD7CF84C2CC51843DULL;
    std::uint64_t aWandererE = 0xC3C2F0A4A40980D8ULL; std::uint64_t aWandererF = 0x93EBDCD273296F63ULL; std::uint64_t aWandererG = 0xFFB84CE8E2FE57A1ULL; std::uint64_t aWandererH = 0xA9D5002E8103F247ULL;
    std::uint64_t aWandererI = 0x81EF21F722387BF9ULL; std::uint64_t aWandererJ = 0xD62968537B35230EULL; std::uint64_t aWandererK = 0xFC8261D947486A99ULL;

    // [seed]
        aPrevious = 0xDBAF9C4252DFC732ULL;
        aCarry = 0xA17FABBBAFE61DE1ULL;
        aWandererA = 0xA077D7C78DBAD9D6ULL;
        aWandererB = 0xCB44C5D36C78A91DULL;
        aWandererC = 0xFF60E33275D839AEULL;
        aWandererD = 0x833927DB8CA76306ULL;
        aWandererE = 0xD7D48749F76E29CBULL;
        aWandererF = 0xAD2EE12F13127C40ULL;
        aWandererG = 0x9000DF6320BF06C3ULL;
        aWandererH = 0xE9D9F2DDC339EEFFULL;
        aWandererI = 0xDB6F2709239A9927ULL;
        aWandererJ = 0xD4E8BC93CB33FAA8ULL;
        aWandererK = 0x88891EC751CD8DA6ULL;
    TwistExpander_Regulus_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Regulus_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Regulus_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Regulus_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Regulus_Arx::Twist_E(pWorkSpace,
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
    TwistExpander_Regulus_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Regulus_Arx::GROW_B(pWorkSpace,
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

// GrowA candidate 27 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 14075; nearest pair: 480 / 674
void TwistExpander_Regulus::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3571U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5884U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3893U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7337U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7518U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7143U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4588U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7548U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 472U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 782U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6097U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5764U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6891U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1774U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7697U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 603U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1283U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 76U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 910U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1864U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 999U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1290U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1504U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1687U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1114U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 729U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 627U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1097U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 416U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 331U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1967U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 9U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1713U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 419U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1471U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1191U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
}

// GrowB candidate 27 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 14074; nearest pair: 482 / 674
void TwistExpander_Regulus::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7197U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2746U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3640U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2133U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 8U);
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
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7458U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6552U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2785U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6397U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1492U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 718U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7866U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2625U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4955U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7425U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3047U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5671U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 0U);
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
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1957U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 964U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1595U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 486U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1059U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1996U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1647U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1919U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
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
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 104U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 833U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 705U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1867U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 978U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1169U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1727U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1605U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1128U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1113U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 185U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 53U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
}

const TwistDomainSaltSet TwistExpander_Regulus::kPhaseASalts = {
    {
        {
            0x56655450CC1FF300ULL, 0x9EB679BD870513D4ULL, 0xF6B18B0FBA726649ULL, 0xA6071512FEBA93E6ULL, 
            0x773018F4B6E70FE6ULL, 0xA71E92D732013EF8ULL, 0xDA028BB48BCE06F7ULL, 0xB1BE4A2578CE3DAAULL, 
            0x14A676B2D420EB14ULL, 0x135AC5D1E03A8BABULL, 0xA74E0050A57F5F7DULL, 0x9D76E25EAAF7687DULL, 
            0xD1B348D0E47813C3ULL, 0xB3EC37BB8E6138B9ULL, 0xF60E1D5B163E9A4CULL, 0x8F50A5086EB64575ULL, 
            0x34038103DEDADEB7ULL, 0x121E68352B4EC9BBULL, 0xB7A929D96FDC6F1AULL, 0xD0A2FC5A019FF375ULL, 
            0xCB394B588DFB9AAAULL, 0x8C62CB6A645226F5ULL, 0x6BCF1DCCCD62D8BAULL, 0xD57B275E656CC215ULL, 
            0x3B3350B8F32E1859ULL, 0xEF174598C04D2A91ULL, 0x168EA17733237BF5ULL, 0x350737E2EB73D303ULL, 
            0x3395EA43C35F6A87ULL, 0xB44CCC2879FA0127ULL, 0x70625735599F7B95ULL, 0x7B22C9D03F719648ULL
        },
        {
            0x59B33A57937FADC7ULL, 0x8F07260E714D7A6CULL, 0xCD3E244113F5E2EBULL, 0x9691D896C418F89CULL, 
            0xB64C3C5E884B8838ULL, 0x2FF95C963964C363ULL, 0xB6069F4D36DC3A3DULL, 0xAA8C78497547AA93ULL, 
            0xC145156029A5CDBCULL, 0x9626943AA56BCB26ULL, 0x1169ADBAB983F982ULL, 0xFB49618C0B79EF76ULL, 
            0x5D4F447B995E0FA1ULL, 0x71C0F1391D996300ULL, 0x23F6A337103BDBA9ULL, 0x8C6E1F3D6E40B94DULL, 
            0x3D3CE65F26A4CEF4ULL, 0xFA09FD0C750B3787ULL, 0x68BFEFBD39309E6DULL, 0x847B495E86027B51ULL, 
            0x307A1B88999F6025ULL, 0x571C7187378A1E2CULL, 0x6BCA8243D195135FULL, 0x2A8ED1DA65B9082EULL, 
            0x41A29028E8CA0A47ULL, 0x4920927257B30B09ULL, 0x3C520ABB3622C255ULL, 0xA18E4C48D9BECE58ULL, 
            0xA1FC4275A254B01FULL, 0xAA4F1435CD94B04FULL, 0xF194B8F093E45589ULL, 0xE8BB18AB3D3903D3ULL
        },
        {
            0x8AB596BAA77A7ECEULL, 0x4445068ED53966AAULL, 0x4DF7A0EB0E0A1A50ULL, 0x56B4C50CBEF2FCADULL, 
            0xF080D427FD397F64ULL, 0x113596F6F7C1351FULL, 0xA4463CF3F655F6D2ULL, 0x237ECEF8536CE055ULL, 
            0x82758DEB5FA90E81ULL, 0x9F00BA8FAC6609D3ULL, 0x6162F58D535A78FEULL, 0xE1A3C3C524223323ULL, 
            0x1996B90DB4DF56B3ULL, 0x461748A8E15D8E63ULL, 0xFD9174CAB72F115EULL, 0x60913F9D5C9C52F6ULL, 
            0xBBC149D0FE13C47DULL, 0x482F4AB8623B73CEULL, 0x5B156C7665C90CBDULL, 0xDCBE5C3B8BFF10D0ULL, 
            0x66F088205C410DF2ULL, 0x6A10B49733586C74ULL, 0x9A0B94C659FE3AE6ULL, 0x2043973B6D87F06FULL, 
            0x0CD8206AE72EDC69ULL, 0x53876E4FF8FF079BULL, 0x008190628C710CEEULL, 0x3263D41070FCB425ULL, 
            0x22D3358429F3BF00ULL, 0xB568CE207EF51904ULL, 0x944ED5F64FD94A67ULL, 0x7CAD81FE2EAF3FA4ULL
        },
        {
            0x2E97F3ADCC0C36F2ULL, 0x79AE445E9A607A53ULL, 0xF3C4C4B4246ED515ULL, 0xC95FD8DB033F5D6DULL, 
            0x0998339032BED6F9ULL, 0x5381D406955A4971ULL, 0x44B174ADECCB75EEULL, 0x544562970CA8F2C9ULL, 
            0x8B0085BF411C606AULL, 0xBFDB66D7C351EA0BULL, 0xDBEFFB8210681AFFULL, 0x915C78667BCDE3ADULL, 
            0x2D05B86C71496CF7ULL, 0x39FD3673B01FF36BULL, 0xCB8EA5A2D58668AEULL, 0x885E12893ADC99F7ULL, 
            0x9E990B464412ACE3ULL, 0x940E01A4C943E30FULL, 0x7F1FDEB9600F1293ULL, 0xCA8FA7946D2EE628ULL, 
            0x2D25CAAE1215C6EEULL, 0xF7F25FB5F650759FULL, 0x4A086450FBB41046ULL, 0xA3A8708ADACE8D71ULL, 
            0x0531D2CADBCD63B3ULL, 0x27172894A2477D3CULL, 0xB65489882F8C0FE1ULL, 0xBB7C26489D11FD36ULL, 
            0xE35D6BE53E34587AULL, 0xC739D692EE1A070CULL, 0xEFBACDDC50FD64BFULL, 0x67E2936FCCBA83F3ULL
        },
        {
            0x179E377B82BECB12ULL, 0xE5B8994C5CE53904ULL, 0xBA9E5628167E3520ULL, 0xE1C547877E286F40ULL, 
            0xCAD411567BE83CA5ULL, 0x76A7545EC73DCECAULL, 0xB7E7FA1FB119C14BULL, 0x5959687F98C7AA8EULL, 
            0x37378D3205719A7FULL, 0x00735DDEB6FE5B1CULL, 0xBF8BD5DAE7CAAD07ULL, 0x0F686A90DB47E96FULL, 
            0x93473CF2C34BC48DULL, 0xEB7C7D781830AE05ULL, 0xFDB6047131CF5F6FULL, 0x720753E6CBE3E1E2ULL, 
            0x944874E5FDA5B429ULL, 0x7496CDB42D937FF7ULL, 0xDA01DE332C5ACBE5ULL, 0x2888B8E664AB4A6DULL, 
            0xFF0678A62061F7FDULL, 0x68C8CADCC6D54863ULL, 0x6BC65B84053139BBULL, 0xC61F4E753A82BCC0ULL, 
            0x051C1CF98EA99E69ULL, 0x4A9950757031AB7EULL, 0x32662A759741E79FULL, 0x3679D3B541067933ULL, 
            0x62ED6F2DB9C2DFCFULL, 0x81BBB092DAB6048DULL, 0x3C147626CCF60AFDULL, 0x1F8B0BAED65D32A0ULL
        },
        {
            0x63C5884EC6DF7502ULL, 0xF3AA1A3308C5557FULL, 0x2B5B0D464363270FULL, 0x3F53850E54D35CE0ULL, 
            0xDD53C17632D80B8EULL, 0xA0741503A6512B70ULL, 0x60B6C5C131FD1751ULL, 0x3ADC2D43779AB5A8ULL, 
            0x998201CA49B8415DULL, 0xE5DFA6618E4104AAULL, 0xB43CF1AAB19267DFULL, 0x208E2D8B03AA9336ULL, 
            0x5B60D9F0BC51DE75ULL, 0xDEB782F7728761ACULL, 0xC7220BA5BBA8DDEAULL, 0xB0EB86A43DD889DEULL, 
            0x511449E5075A4EC8ULL, 0x2ED47857A6A56B6CULL, 0xFD47E18C2B5EA4BDULL, 0x5E3CD619C9CA2B43ULL, 
            0x4DC7FB27D79A75B6ULL, 0x2166503B90E708EEULL, 0x4ADB74CA38D96564ULL, 0xD86580D76818AEFCULL, 
            0x563F3899AB9B692DULL, 0x58130E847D441C6BULL, 0xA650ECD7D71CDD21ULL, 0x113D8CBBC57E59E9ULL, 
            0xD4E3704BEA2CBA58ULL, 0xC30C16DF23559E13ULL, 0x0AE953CF85A98B90ULL, 0xA4C043DBF436E2F6ULL
        }
    },
    {
        {
            0x961410EC791C231DULL, 0xA80D4272750BBA11ULL, 0xA8A6ECB02F8B08A6ULL, 0x43CB76C276032A58ULL, 
            0xB9DD613D5729D17AULL, 0x5F596B12DADCC641ULL, 0x50747E5D30729DA5ULL, 0x86B18A92EA920E19ULL, 
            0xBC909FF30266819EULL, 0xB932D74088194C0BULL, 0x3EAFFC39C7EBC833ULL, 0x6CEC5BF4330B8FCCULL, 
            0x1B3FC0F200AF20DAULL, 0xC745B169A6E9F7DCULL, 0xBFCA15268DE61A9FULL, 0xF76222CD562CDDE3ULL, 
            0x9A5BB72387A4CF98ULL, 0x082C8DB819966F22ULL, 0x8C132A0B25F5E242ULL, 0x2781085025F0A17AULL, 
            0xE23313196DCF6F0FULL, 0x0FFD77B05B96FB9EULL, 0x5F2AFE94D8563522ULL, 0x36E0D7F6C2353270ULL, 
            0x0965D5D6562C261FULL, 0xCA7572340205B839ULL, 0xE9B9992FBE97A79FULL, 0x3EA0216599ABE3E7ULL, 
            0x101630CCB11994D9ULL, 0x605A0FE85C301371ULL, 0x066A8F7FE3BF523AULL, 0x66EDEE1CFB2D9A23ULL
        },
        {
            0xC67CD444D4A68A50ULL, 0x904A922339E28B4AULL, 0xAA07FCD80B50F49AULL, 0xEBAC7ACB91B09C3DULL, 
            0x122194867CB3549DULL, 0xEF507E2C8416C14FULL, 0x04D54C309B771E24ULL, 0x26BF2AA292438451ULL, 
            0xDF7C61F5C3459CB8ULL, 0xC7459DD4CC5A450FULL, 0xDEB76498FF4F5174ULL, 0x2F70A40748A2BC53ULL, 
            0x498F3204BD427CE4ULL, 0xEF9786B42ED10881ULL, 0xB4FEFAE9850BAC33ULL, 0x85165EB69DF9E835ULL, 
            0xEB080469EEE1948FULL, 0x9D555A9BFEB34407ULL, 0xD51579D761E33426ULL, 0xDAB3AEEB643E536BULL, 
            0x1A8F6328BC2BF80EULL, 0x241738B26F560FFBULL, 0x3CE1D9224113A09CULL, 0x157F322D834D1D0DULL, 
            0x4FCC9442FCAD303AULL, 0xBEC047C7FD860870ULL, 0x6AAE06482EC0E5FAULL, 0xCBE7B6FA5102C46DULL, 
            0x558B6BDBE5CDC85BULL, 0x903741B051ADC91BULL, 0x9724D30B07962156ULL, 0xB27164B27F406C3CULL
        },
        {
            0xCDFC1869539B6F85ULL, 0xADE243AD7BA55B00ULL, 0x5400D7EE8CC2BB3CULL, 0xED141B4C29425B75ULL, 
            0x90A707AF22A366E6ULL, 0xF33C9AF535760DF9ULL, 0x2CE2C6CC7B6013C2ULL, 0x42757DCEB28E57D7ULL, 
            0x8F081E86BB8EF65FULL, 0x8D98A68E31788F5DULL, 0xFBDFC6AA4C3B8DFBULL, 0x305BE11DF0767998ULL, 
            0x4D39B59FE594FA5CULL, 0x1A8883A25FAF9C29ULL, 0x74C050FE97C1AEA5ULL, 0xCF762F4B1D6EA8EDULL, 
            0xA0EC2BB02FC5AC4FULL, 0xB4C5F495E05BB463ULL, 0x7AB74ACE5DE65356ULL, 0x0A5CE849CFC3511BULL, 
            0x2476A3205EFF7E60ULL, 0xD44CD4CCC427F1AEULL, 0x1B485E320EA86E46ULL, 0x150775FF1C52E0E8ULL, 
            0x690047D697525D38ULL, 0x6EEDCFFA2C660F09ULL, 0xC40E306ED9304516ULL, 0xCB37DBAA0E79D80BULL, 
            0xBA58B981AD250299ULL, 0xB578671E20ED1EABULL, 0xDCD74F3FDF8F6779ULL, 0xD75DBB18DCE02DC8ULL
        },
        {
            0xB410675B3C80B3F4ULL, 0x7E489F48C8BCEEA4ULL, 0x78B36D24D76FD3E7ULL, 0x9828F299E4677CEAULL, 
            0xA9D4DCCA4BA73CDDULL, 0x605622E47C258E41ULL, 0xC8DF05C00CA0E999ULL, 0x4EAF6EDE9D1218F0ULL, 
            0x9CFE3AED3B6F3821ULL, 0x29DA7FD6F20FC027ULL, 0x9EDD093F936592B3ULL, 0x8C1C3A645343D379ULL, 
            0x4996E72E5661AC4AULL, 0x6A10E17FF06E251AULL, 0x8E4CF25D5F1EC618ULL, 0x0E24BD356B46D5F6ULL, 
            0x6AB8E505EFAA2E81ULL, 0xF979951245592C1BULL, 0xCC9092C0146E80A8ULL, 0x8BA927CDF7CE2D63ULL, 
            0x86C00E607ED6E537ULL, 0xC18F26C458A81867ULL, 0x10F9381EC3D55D7AULL, 0x4797AFC9F2634A81ULL, 
            0x92B015D03486286FULL, 0x1396C06A0BC6C405ULL, 0xC165FB14A455685CULL, 0xA7DD065CBD75EA62ULL, 
            0xDD88CCB440089FBAULL, 0x7523DB075893FE31ULL, 0xEDD9B1E9E2BD7441ULL, 0x48DABEDEC3E20B99ULL
        },
        {
            0xF4E202DAE4D09B3BULL, 0xFBC872C7430126ABULL, 0x0AD0F4291C6CCC9DULL, 0xFF7AE8B101EECBAAULL, 
            0x5F40CA855A2C3537ULL, 0x3CF9A3A524971E75ULL, 0xB49C10BC312A31FDULL, 0x42325186EABED443ULL, 
            0xB6BBA00DE362C6FFULL, 0xED3DCE9BB0AABD49ULL, 0xF74FF6976D45EBD8ULL, 0xD957A1A3E0E6886DULL, 
            0xE81B86220A0536A2ULL, 0xECD5ABC62BFAD156ULL, 0x39417867523CCD94ULL, 0x4FBC79F5361CCCCFULL, 
            0x4D52B0C4227680FCULL, 0x29699A7AF4530179ULL, 0x8E2EE222C1FDD80FULL, 0xEDF87AA07AE0D2F0ULL, 
            0x086350C257298A8EULL, 0x66A7D2560057F09EULL, 0x0944CE6AE12E1C57ULL, 0xB96E8632264613C7ULL, 
            0x1550EDAD401B316EULL, 0x797256C36A77C868ULL, 0x2F45D93A20EC1DBDULL, 0x56E3AEA9A95073B3ULL, 
            0x7139044F61764CE2ULL, 0x3257987F795DC42BULL, 0xE920BE9E0580A31EULL, 0xF7274B3BF5A2FD5EULL
        },
        {
            0x2D7C8258C2BA783DULL, 0x041FD687A5BA20DEULL, 0x38158C833CF0BAB4ULL, 0xAB766DC96C6FFD67ULL, 
            0x532C6731B68CC5DEULL, 0x733FCCC21FFA26ABULL, 0x65BDE7186B837C55ULL, 0x5CD5DB69CF04BE2FULL, 
            0x11035CBE723F9EACULL, 0x9FF1305087F0888CULL, 0x2F8803FFC1D18F71ULL, 0x71B50CCA3D5A13FCULL, 
            0x6B24132FA72E4AD3ULL, 0xF0A06E06BE61EF40ULL, 0x18E444031A3237BDULL, 0x36936BA3DE160789ULL, 
            0xE5DCA9B72D157E5CULL, 0x8E4DBE23EEF73CAAULL, 0x4137708B0C946481ULL, 0xD8A2CFF7EEACE63CULL, 
            0x628937007982D5FBULL, 0xDFBF8D459578C110ULL, 0x3130949BF2CC563AULL, 0xF949362B21EC19A3ULL, 
            0xA8460BB6ABEC7FBBULL, 0x7A68AC3EC2F02A06ULL, 0x891E71D262DFA7A2ULL, 0xEFF6ADC8E38E644AULL, 
            0xC2BA361E5928945BULL, 0xCAB0B66FD0855F00ULL, 0x6B52ADE84F504D44ULL, 0xD0974D4194ED4F33ULL
        }
    },
    {
        {
            0xC5FEC3BA120213C6ULL, 0x05B2BCCAA9F76AE2ULL, 0xC5FF1BA855125ED8ULL, 0x337514FFDE718148ULL, 
            0xE0232C5093B55AA7ULL, 0xACA37ACFFC8983CEULL, 0xB094520D87744736ULL, 0xC14CBC4CAC4A27D7ULL, 
            0xC21BA6DF0C21904BULL, 0x0AFBCC1AC35ABF72ULL, 0x79516FD9B5E7F280ULL, 0x9B35525E434752C9ULL, 
            0x836629BB11D283DEULL, 0x86E74D1CD2955AE0ULL, 0xD243E2CF27628A4EULL, 0xD95931FDE90E4BE4ULL, 
            0x50E420D0031E0A85ULL, 0xE37C51CB5A7F8CDDULL, 0xD52B1FC9386F723AULL, 0x9A1363C92ABDE539ULL, 
            0xD84A6EA54B243395ULL, 0x7EEEC129F12BE4E0ULL, 0xE60DD62FE48F9E07ULL, 0xB11EBF2A2749E482ULL, 
            0xAC3241A5895B7498ULL, 0xEB8AD66F0AB5296DULL, 0xA482D603863AE007ULL, 0x61AC9BC6D6788B30ULL, 
            0xE0341424FFE87D59ULL, 0xD2A9A07F044831D0ULL, 0xD69CC2C15A76A404ULL, 0x292D0A8ADE39E463ULL
        },
        {
            0x0E9A55D2B53CB32AULL, 0x0537F125E2C35327ULL, 0x076DBC9323E3C62BULL, 0x17557B87EEE2D5A7ULL, 
            0x33287D1743EE355DULL, 0x159208B8A0F02690ULL, 0xF12AA0E6B0F704D3ULL, 0xD37561306A9990DAULL, 
            0x2B9E3476E8C60630ULL, 0xA6F2719CFC8E6FF1ULL, 0xDF962D2C1D7C88E7ULL, 0x0BAFF2ECE7588C2AULL, 
            0xC88F49F1C8292D37ULL, 0x1269A36640B93962ULL, 0x66FD7FE546C18924ULL, 0x57CEDEE61E53DB1EULL, 
            0xC9A6AB1750F4F609ULL, 0x84078DAEEA015B5BULL, 0xC6F348FD1D3C2CF0ULL, 0x93909D4B452D3552ULL, 
            0xDC50D2FCCBBAC7DFULL, 0x2889B6E7939DBEA6ULL, 0x69A197D4C26C7395ULL, 0x3A3D31ADE84DD1B4ULL, 
            0x3454C8DC47BF78BDULL, 0xFE0D34A196DE3C22ULL, 0x79C8BB633E099E76ULL, 0x3CA59154B73AD65AULL, 
            0x711363503C97E95AULL, 0xF54D28CB4B8CAC0AULL, 0x6EEF81CAAEBBCD70ULL, 0xDD02620B4137A731ULL
        },
        {
            0xD28F9EB6EBF9AC41ULL, 0x8D70C45E8BD173AAULL, 0x2F6EE5263FE33B8CULL, 0xC62B7040127035CBULL, 
            0x91B81DD6D931A1E5ULL, 0xEF5A658483EAF3C5ULL, 0x8DF8CB059A822A9BULL, 0x10A8CEF08C99C891ULL, 
            0x8D10591D3FF9B2D8ULL, 0x078DDBDFB8C450F9ULL, 0x0F29AF9AD671629BULL, 0x6414EC4E6D67850EULL, 
            0x843CB9F545E5253BULL, 0x5FE0C22B3C89572BULL, 0xA35EAD6E0E24F8B9ULL, 0x1C679FF189EE3A13ULL, 
            0x375CF225BA5BE1ECULL, 0x566F7C828BED4E85ULL, 0x2697B07A6CAB24B4ULL, 0x96704D817EAEB08BULL, 
            0xE59A97BA40A89B14ULL, 0x1B8BE344A1E3D35FULL, 0x55A6A72EB4F6D9D1ULL, 0x1FBD3CF2F575B940ULL, 
            0xA861E78F1ED395DDULL, 0xF3987F4366F07870ULL, 0x820D456CB5ACE496ULL, 0x7963C1C014DF6C88ULL, 
            0x43EDA10783E4349EULL, 0x782A9B2BFDD34FF2ULL, 0x900898EB3AD67814ULL, 0x8B334E54F67965F7ULL
        },
        {
            0x7D5F461C611C317EULL, 0x2F0D8E5C9AF1CFEAULL, 0x329EFF49911BE8E5ULL, 0xD7CE6365C3A46A67ULL, 
            0x95E21513B3D92B66ULL, 0x8485D56E9D065FF0ULL, 0xFC875ECB79AAF52EULL, 0x6568EF5F476C1399ULL, 
            0x935760B5B1AD7797ULL, 0xF74CA28C812F2DD0ULL, 0x48D81FDAB8CE66D2ULL, 0xA05C8E28FE9EC124ULL, 
            0x272E928BD6261C00ULL, 0x312E310599A20902ULL, 0x6F0F61F6C2108400ULL, 0x3D1A3F2662BC3DA2ULL, 
            0x9DA0281EF8E03991ULL, 0x2D8E3EEE226D5437ULL, 0xA9C057F00CEEA741ULL, 0xF56DBF360188D498ULL, 
            0x289BF64A3B8E0B9CULL, 0x9F9A72B3E255477DULL, 0xD9509F728C51ECD1ULL, 0xA7D876598495DD07ULL, 
            0x677402391F931077ULL, 0xCB3FC97A33C22869ULL, 0xDFA887CF6E04659FULL, 0x726E4FF5D074D9FAULL, 
            0x25DD3459299E78AAULL, 0xAD048BD58685C44FULL, 0x9B7A51B649555F42ULL, 0xA6BDD207B36B209AULL
        },
        {
            0x1ECAE0211FB8ADFAULL, 0xAC1589620B33E15CULL, 0x553006F2E12A1B39ULL, 0xF2210AE92B1BBDCDULL, 
            0xF9D5AD5AF7D68802ULL, 0xF03DE28AE5B4898DULL, 0xD4EBE756F1A61610ULL, 0x6961E56C8F6CE05EULL, 
            0xAED92519CBE8EC1CULL, 0xD9270C7EDCB33768ULL, 0xA6AA8B84C081CD51ULL, 0x031F14F50363DD39ULL, 
            0x3EDCE664D8435A95ULL, 0xA7A2A68FF0CE9036ULL, 0x05AED4681E4DBACBULL, 0x9159292C2CB3C441ULL, 
            0x8287C7CF26C4CD21ULL, 0x199D0AF6D422B1C6ULL, 0x3FC1903083EB22C8ULL, 0xF122A2D4228823C4ULL, 
            0x7E83037F93ACC5EFULL, 0x74CE9D64A2B56647ULL, 0xC5943306F20E94A5ULL, 0xBB2D848E4E7E3A6EULL, 
            0xD9C1687A22A18D53ULL, 0x66D513DB70DE0292ULL, 0x4193AF5AC9D3BB22ULL, 0xBC073C37B7673C74ULL, 
            0x4452286111B64E31ULL, 0x512EAF8CF2F72C05ULL, 0x50C68ECED22F54A1ULL, 0x3DCFCEFE8D397C94ULL
        },
        {
            0x39CD2737713B8E09ULL, 0xD80C9BCA0F91B5E9ULL, 0x9FB37B58310C1DA9ULL, 0x5B3FCBCE19295E86ULL, 
            0x9F9EF35EB8C60354ULL, 0x8219200812AAE956ULL, 0x8FE63AA9AB4E2291ULL, 0x3F2EBF5404F95693ULL, 
            0x54E31F9FEB503F83ULL, 0x8744D32307D577D2ULL, 0x2C79D11333DF7580ULL, 0x240FBA1B418CD569ULL, 
            0x5637E5B0CFF6FD83ULL, 0xE2728131EEAD2596ULL, 0x79214A9D9F9F90CBULL, 0xCB6EC49FEC9CFB2EULL, 
            0x8234FF2247B304E3ULL, 0x39A1741316BF8A7EULL, 0x57F4551D4206BC39ULL, 0xEAF6126A8B483255ULL, 
            0xB1D03F414E907D67ULL, 0xFD257D78698CA8BEULL, 0x9365D85C0CF9A0AEULL, 0x8B87AD76308F0958ULL, 
            0xB7F95D1B0961AABDULL, 0xF08B2A0D79D33A03ULL, 0xFCDB5E836C891DF6ULL, 0x8FC1CC4B8BF75DE7ULL, 
            0x686194951E315A61ULL, 0x9BE801EC92356E6CULL, 0xB7CAC448820F87ABULL, 0x6876717FA9853648ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Regulus::kPhaseAConstants = {
    0x31B3662D53C12AE7ULL,
    0x8924FD88D3C0F4EBULL,
    0x725770CD59B00D78ULL,
    0x31B3662D53C12AE7ULL,
    0x8924FD88D3C0F4EBULL,
    0x725770CD59B00D78ULL,
    0x4C0D838DDFE273D8ULL,
    0x3163B6DDC8D6E916ULL,
    0xAB,
    0x2B,
    0xC0,
    0xBA,
    0x49,
    0xD0,
    0xBB,
    0x24
};

const TwistDomainSaltSet TwistExpander_Regulus::kPhaseBSalts = {
    {
        {
            0xF51ACDCF6731F93CULL, 0xBCCA14946DD2D3C3ULL, 0x9081520D3CE5696CULL, 0x0A49E33D1392E64DULL, 
            0x1062CB705AEAED85ULL, 0x889E005A953BDD88ULL, 0x1F8C8540DBA5DBCCULL, 0x2770B73731E7DD9BULL, 
            0x04B66DF083A25CDEULL, 0xB714EE28C0DF27A0ULL, 0x622CA4CD180B6763ULL, 0xF9224FB448F8D248ULL, 
            0xEEAD58E19537C82AULL, 0xB60B19413BED0912ULL, 0x1D08C30240AB180FULL, 0xE942F4021D63A29FULL, 
            0xDFD3461C46298F54ULL, 0x6BF4A83BDEE61F0DULL, 0x8244C8D3A2D6B052ULL, 0x50C8C78C80B280EBULL, 
            0xD26583BF7D3514A3ULL, 0x691D3190C5250EACULL, 0x063CA1BE0A8EB2ABULL, 0xCF24F0E9E33449FEULL, 
            0x2B38044E61A5E218ULL, 0x6D0457A4D7DF4E3AULL, 0x0CEB173216E2A5BFULL, 0x7ED6DC69D1E42B52ULL, 
            0x88AB72DB6E06CEE5ULL, 0x5D478278AFBC8FF0ULL, 0x1686374C29F7D12EULL, 0x01916A3E49A4CEBAULL
        },
        {
            0x919C16FE80F046E4ULL, 0x5DA92AAE919BE309ULL, 0xD60C2E2A5938EA79ULL, 0xCD5097177CE99F2AULL, 
            0xDAAA4E962B48E7EFULL, 0x293CC4BA2E354573ULL, 0x1ADBE0C6712249DEULL, 0xFC04027CDF7FB267ULL, 
            0x4FB6AA8396989B9DULL, 0x04B10848232A4D61ULL, 0x768054AFE9A75D75ULL, 0x8BA490FEE5DB1FF9ULL, 
            0xAABCEDF60647BCD5ULL, 0x26F2151A113B978BULL, 0xA8DCFDB4486DFD32ULL, 0x55FCE37EF4EB3CD4ULL, 
            0xB702932686368AECULL, 0x058CCAFB2F42083EULL, 0x86746354C9FE2330ULL, 0x4FFDE4523A7FB077ULL, 
            0x62B7D34285ED3D21ULL, 0x14FC727806ED1E1AULL, 0xFFDFA5B6F8E2612CULL, 0x634EDCE7329A1AA1ULL, 
            0xAF827E4EED31B972ULL, 0x1BC414A94BD5FC60ULL, 0xE19EBF05FA9A799EULL, 0x52F042B06F277FB2ULL, 
            0xA726E77BEE6C5608ULL, 0x3CBA944D017165C8ULL, 0x12C21A7871017596ULL, 0x8DDF1F726559BC2FULL
        },
        {
            0x2F5BA95954932E1CULL, 0x308CF5059E319D8FULL, 0x7CA8895837B2CDC0ULL, 0x89E4895402A355F0ULL, 
            0x7DABD46BD629DB03ULL, 0xFECE644908EA0750ULL, 0x63288C4D26DD65CCULL, 0x1E53D7E1656D4851ULL, 
            0xEE7068EE11B977D6ULL, 0x6125445F2FB567E0ULL, 0xEF9A7B8B5AEBF171ULL, 0x831CFF02B99F2D3EULL, 
            0x91F36F705C20A814ULL, 0x0FE63D037A2B5A67ULL, 0xD07EB9E92627BE8DULL, 0xA477411C49DDCD22ULL, 
            0x49A469AC0355F989ULL, 0x875BE75437F3E437ULL, 0xE2CD5C11D8B53817ULL, 0xE2F80252A35AF1C8ULL, 
            0x1407BBDB42229D1BULL, 0x6E5537592302B069ULL, 0xBA9C0A2D6ADDDBCDULL, 0x0CE325CEC1B7993CULL, 
            0xB5F2279FB890AD36ULL, 0xD74C9C0802F94B91ULL, 0x190BF6FE74FA2856ULL, 0x7CAA6F2DEBB7CE47ULL, 
            0xE725641BA9693606ULL, 0xDE9FCB9BB58625D9ULL, 0x4B5B3CD8A3CB6B98ULL, 0xE2DA771ABC7FD0A5ULL
        },
        {
            0xAE8A5467519C75D1ULL, 0x23B78DEDC3226E30ULL, 0x876DAFBE609AE3C8ULL, 0x38F995B3ECD4E6B7ULL, 
            0x52ADB0C7AB603CD1ULL, 0xABE42D48738EE6F3ULL, 0xC0ED694BA1120B59ULL, 0x59B8EEB1C0491BD7ULL, 
            0x2B05033DA5A11C5DULL, 0xA4C725E961AA554EULL, 0xB4863454B2E063DEULL, 0x622211352DEEC116ULL, 
            0xB87060A3EB722BB1ULL, 0x7F480C98390CC7DAULL, 0x199BCC21A6A1DD6BULL, 0x41D74C501DD99D62ULL, 
            0x534C7AB8C80DAE74ULL, 0x169539FDFBB7677CULL, 0x38FCD1E1B7DF2365ULL, 0xE69B67A2043DAC94ULL, 
            0x134FC013221F2B90ULL, 0x76542B1043FD3FAEULL, 0x39EF5F2F03D69B19ULL, 0x4C99BCAA4C3E9AE9ULL, 
            0x793B7E71A0EC8B31ULL, 0x27D71C88A37378ECULL, 0x4E13CFBCC5D41546ULL, 0x97A8954EC6CADB72ULL, 
            0x01BC760A4FBAADF1ULL, 0x9A621784C6090F73ULL, 0x584932BE3BCA0E37ULL, 0x871A7C2ECA1CBB21ULL
        },
        {
            0x19CBFFFB0A9822A1ULL, 0x368A747C6960E890ULL, 0xC3D0EE58A206AB5BULL, 0x0C57581DB72BC11DULL, 
            0x2D197094AB216B08ULL, 0xE3EADDF55B5DD1D9ULL, 0xC99AEC23507BCF55ULL, 0x64275D6073D6EBFAULL, 
            0x124CE6E5B102ABE2ULL, 0x8127C64727A49824ULL, 0xE45F279CAD716082ULL, 0x79F4CBB5D1E327C8ULL, 
            0x44D133DB56459BCCULL, 0xD2A473390DD415EEULL, 0xC4B64F3047DB90D5ULL, 0xD781DCCAD8BE4B81ULL, 
            0xDDB387CEF4F6DE87ULL, 0x1703876D010D738BULL, 0x79240BB83D72A6B1ULL, 0x99DD47D9B943FE59ULL, 
            0x83BD409289B0B5D9ULL, 0x5CFB75F7A60BC2E8ULL, 0x2C0063025CA40903ULL, 0xECB2817E7B7EB8CFULL, 
            0x659F5ABC11BE3445ULL, 0xE49E1E29BF42AA4BULL, 0xF273144D9BE67F8BULL, 0x10B2C1DFA72F49D8ULL, 
            0x8214470B931A13FBULL, 0x3BC35919E13463F5ULL, 0xB70F667D1DE51007ULL, 0xDB7DB854B28FD004ULL
        },
        {
            0xD52AFA55DB2AD462ULL, 0x3F1E61FBEFBD8E11ULL, 0x7EC67F6022F8D0FFULL, 0x016F591973EE8185ULL, 
            0xA84F21E699CA297CULL, 0x6BECE6DDDFB2022AULL, 0x0BE14CCFF547E3EBULL, 0x87FBF58237783A9DULL, 
            0x6A944BFD28EE53F2ULL, 0xC3BC8F6A74C22F16ULL, 0x98070EE089B5D2DBULL, 0x6728DB063781DF40ULL, 
            0x312ABB8052DF7D88ULL, 0xDF3216E9095BCF68ULL, 0x76518AB7A117243AULL, 0x4518D411942C4CCBULL, 
            0x5AE6229309A9953AULL, 0x5E4F89B52DB67AC1ULL, 0x15D78DB366E4091BULL, 0x2EAD03B869643A24ULL, 
            0x5B4E4D3095679470ULL, 0x46AE5D4426B0407FULL, 0x26F96CCC65C4A964ULL, 0x89638E18D4513189ULL, 
            0x785B318DCE5153AAULL, 0xFA07548976141BE1ULL, 0xDBE0C16583BE6973ULL, 0xEAB1A3D8411CD5E1ULL, 
            0x09640243E8842658ULL, 0xDBDE9A225225CD17ULL, 0xEEAD34CFE3C67430ULL, 0xA4DE33D6BDFE6214ULL
        }
    },
    {
        {
            0x148EC9722A682B64ULL, 0xB69A5C2BCA686680ULL, 0x410102B0C18A08A8ULL, 0xD79AC3CA01373EADULL, 
            0x30AA15A43490CC54ULL, 0x3E8A3867A8969F29ULL, 0x4F141E066308E0C8ULL, 0x18D17C5424549F71ULL, 
            0xAC187BB193A4533AULL, 0x376F7DD3F710A4D4ULL, 0x4FA511C8E80404BDULL, 0xDEA5A64207505CFDULL, 
            0xA31274AA5E70E1FAULL, 0xB1443AE2FFEB0600ULL, 0xF555AA5F5CAF8E5AULL, 0xDCE1F0537B355B57ULL, 
            0x7C194436EB5624D7ULL, 0x7875BABC9828F677ULL, 0xE0D010F59FF08F89ULL, 0xE51B874EF9C88633ULL, 
            0xB1F9966D9877F8BDULL, 0x7F8377179E21F95FULL, 0x31F92237266DB970ULL, 0x528A959EA834111EULL, 
            0xDA553DAB2B53EDF5ULL, 0xEB70620A61B13C9BULL, 0xA5AE709A9AD1A5AFULL, 0xE1E187ACEA8B7A35ULL, 
            0xB8704593A73DCFCEULL, 0x195535B7E155B943ULL, 0x793EB53F705EBD99ULL, 0xC9AC42704BB1A45BULL
        },
        {
            0x3C657C60760F416CULL, 0xD6F636FA1DB5EABEULL, 0x596DE6552522EDEBULL, 0x9964F431EA86904FULL, 
            0x38AF09F843433219ULL, 0xFB54D47771E40CF8ULL, 0xC586449F8DFEBAC3ULL, 0x0450E9822BC3AD89ULL, 
            0x60E36C33F9B3D993ULL, 0xFF15E8151E21B1FCULL, 0x905130F1341399F8ULL, 0x97CE14016FCC9E9DULL, 
            0xC76897DA20E8AECCULL, 0x374418F4290DA89EULL, 0xD13A7EF2F74FE29AULL, 0x0239CD04859B5984ULL, 
            0xB2D7BDB9666F8123ULL, 0x1030CBA7D30DCEDFULL, 0x5140159C4C7B3F42ULL, 0xBD6A2CD7C2D28605ULL, 
            0x35C31894E020879EULL, 0x42C43BB7F9294172ULL, 0xD08A50F0BACC9063ULL, 0x203B9B2CD86B52D5ULL, 
            0xD03B742A94B27584ULL, 0x1005DA4B6D359AF4ULL, 0x3C77C4B1BA3CADFCULL, 0x0739CC177D2A3EE4ULL, 
            0xFFD90ACC66EA6311ULL, 0x2CE67723D121B08CULL, 0xAF0AB68B4F5C00F7ULL, 0x64F3592E92102ADEULL
        },
        {
            0xDEE8C51CB22DE1A9ULL, 0xD2A8D43BAEB556D6ULL, 0x3FDE968D3E2D5FE6ULL, 0x609744D1B4C0D9C4ULL, 
            0xFC34BE5A26CBC1BCULL, 0x598B31B96802CA6BULL, 0x0B621EF6B20B33CEULL, 0xE9581C5C7A736B80ULL, 
            0x038E6844A7A918ADULL, 0x4F3A2D781982B82FULL, 0xB174C9E98EF83F14ULL, 0xC4BA125B2CFE9D3EULL, 
            0x2261C9DF021912A1ULL, 0xAE88E686E12FB1EAULL, 0xF4112B855BB834CBULL, 0x941486EF0DDB370FULL, 
            0xC92900A238F6F9C4ULL, 0xD4D7F01CC3423FF1ULL, 0xEDE8D333A137DD80ULL, 0x186D5A8DFFE3B070ULL, 
            0xA0106F079D28123DULL, 0x5120DFB0D942BC0BULL, 0x9408D1229252F47EULL, 0x715DFA7567255F8DULL, 
            0x22EF54F1DEA0C816ULL, 0xA48B8E17A421B9B0ULL, 0xB04BC9A0D35EDB91ULL, 0xB40049DAC0CFA9D1ULL, 
            0xA7C4080CBCC24B31ULL, 0xD7D7FF3D52661894ULL, 0xF87480453B2080ECULL, 0x2573217771C753EDULL
        },
        {
            0x3DBBE49FF8E3EC15ULL, 0x5842244AEF76FB7CULL, 0x0A1E2AF98D3DEDB5ULL, 0x598CFBEE2FF51AC8ULL, 
            0x29F740631D6AC298ULL, 0x3B5FEA24A090615AULL, 0xE31D106BD07839E1ULL, 0x4A75B8D334DC3B8EULL, 
            0x79F6BD5300F5B990ULL, 0x871B4B9DB79F2669ULL, 0x82DCE288B0492109ULL, 0xD429EFCAC1127864ULL, 
            0x76FF33CD01BF6BDDULL, 0x760C2CDF3957C449ULL, 0x8D7B34FA26527346ULL, 0xF551FDC3C79BC4E1ULL, 
            0x7FC5154784F21D94ULL, 0x2CCDB30D6256D553ULL, 0x2465BEEDD2FAEA0BULL, 0x8A9800731039D81EULL, 
            0xD566E8C026221336ULL, 0xE6E22AB9BE93E1EDULL, 0xB093F4193BDE03BEULL, 0x7C59D03D3297101FULL, 
            0xB5EC500BE3A03AE9ULL, 0xECB324F70ABF9F2BULL, 0x9B90FEC3082714AEULL, 0x0EF702134DD96908ULL, 
            0x1135440A6B1B926CULL, 0x5CE900BFE391E14EULL, 0xD4D14C86814743B7ULL, 0x0EB0F8DE8E10FD55ULL
        },
        {
            0xED37E4852FA80B04ULL, 0xF423973666FFAF46ULL, 0xC0FD5E55A2077DAAULL, 0xE31CEBDDC6832B41ULL, 
            0x7202BE5B8B3AC76AULL, 0xB037CC7C714A06C6ULL, 0x7A5859E2FB53CF47ULL, 0x2CE772B0A63952B8ULL, 
            0x8B38CD06BB0F63D4ULL, 0x5EA9DD2DC5254A75ULL, 0xD8468D7BEB543A15ULL, 0xEFE3A7CF7218488AULL, 
            0xD22392489E91801BULL, 0x2D7E5F8D93D34DD9ULL, 0xBB621F17E2CD6983ULL, 0x2D27D0D34F498199ULL, 
            0xFCB6CC2F0228AD6AULL, 0x1BD50DE5E7B68404ULL, 0x4233FD07127B2383ULL, 0x4DE24709FBB555B2ULL, 
            0x5FF7E0E7FDA63E4DULL, 0xE971C1DBDEA3DA1FULL, 0xD27DC4963AD4866FULL, 0x8816F4A93FA60112ULL, 
            0xE52FB1D330C3AE94ULL, 0x16733F0BA179FB50ULL, 0xD35E286B1A370CD5ULL, 0xBFF615C0A6285B4AULL, 
            0x2D26314BC1EB77AAULL, 0x1FDB2FDD8A8D9E19ULL, 0x1D43AD9E08485C83ULL, 0x411DA354CF0A3A61ULL
        },
        {
            0x15BF385FBF3E8EA9ULL, 0x51FD1C4BAAF58547ULL, 0x20BB70FD83464C11ULL, 0x72F4306352305162ULL, 
            0x8B88229C2A15D9F4ULL, 0x6B408F5733E899C7ULL, 0x7BD8F74D8A68A803ULL, 0xEC2E4BC46D647312ULL, 
            0x52F5189DB1157F80ULL, 0x63B1C2CB44D54E7FULL, 0x7B456E330B770AA9ULL, 0x9DD73847BACB978DULL, 
            0xFC41313C0A6DEB14ULL, 0x95F9B1ABDF5FC280ULL, 0x41FFAA6CAA46A0A1ULL, 0xDF1232370E528406ULL, 
            0x82E4B3FAB685D99DULL, 0x3CC7EEF220757A4BULL, 0x6AC4734C0C5B60EBULL, 0xDCC9D8CF7184CC14ULL, 
            0x4831B30E2B4109DCULL, 0x7ED8996FDA59CB8AULL, 0x12D3AE945DE38FB0ULL, 0xD8D2B5542BA16291ULL, 
            0xA6B4B663EC69101DULL, 0x267B8A8AEBFEDD25ULL, 0x501B7810B4E90E00ULL, 0xE6FC9C1BFB820A7AULL, 
            0xF88FA9F10414BE2CULL, 0xC52316D5D8970581ULL, 0xB1EA25212A47761EULL, 0xEAAB14532143A955ULL
        }
    },
    {
        {
            0xA654998200566F86ULL, 0xFEDA860A4D773CF4ULL, 0x759C8B22BF9EB793ULL, 0xDC95D537B6BA85DAULL, 
            0x700672475141BA6DULL, 0x729CD118208A003BULL, 0xE8F68A80D449BE2DULL, 0xE1A34645DF190F08ULL, 
            0x22801A0ACD30E179ULL, 0x7A455DD1AFA995ADULL, 0xF8DAB4616C9B16AAULL, 0x0AF1F9E078FC7963ULL, 
            0x25D13694B88B9E7CULL, 0xF7AB9E7E9A057F19ULL, 0xAA890E81F23AD4BFULL, 0xC35232EE08CA0DB4ULL, 
            0x4661B374AEDFD4E9ULL, 0x41433EDB8B78D847ULL, 0x8C0522D8036A6260ULL, 0xB4281EC8E6439261ULL, 
            0x964C39FE208CAEF0ULL, 0xB2D5078B4A992CDAULL, 0x6FEAE133EEDED83DULL, 0x8853C1C518F48F4CULL, 
            0xE2204624E343B93AULL, 0xF98C1F29A77B7F48ULL, 0x16FF3636C35FAAC1ULL, 0x738C2F16A280E674ULL, 
            0x8D676E39605D0DCFULL, 0xB87D640BAC5E231FULL, 0x0A8584F16902D792ULL, 0xD54A5DFFF5054D73ULL
        },
        {
            0xC240D0A247F9B0C7ULL, 0x3304722A88D6630DULL, 0xEED97D162A05D932ULL, 0x84D43F911C322643ULL, 
            0x5F3AA1E99B27A534ULL, 0x0EB3A1C0C7F6C0CCULL, 0xDB27403FB7FA66E5ULL, 0xB07DBF50A95BD2ABULL, 
            0x99AA3CCF6EBE4573ULL, 0xB7A9AEC1A470C21EULL, 0xC9E4DA15A6A3C88FULL, 0x1DBAE5B80DF8CDC7ULL, 
            0x324C6E4FD47BF099ULL, 0xDE82E364CC413AD5ULL, 0xD6AFCC4272228297ULL, 0x09E31C3F9539EA64ULL, 
            0xE025BF232176F942ULL, 0xF74B590F69624FFBULL, 0x7BDE5407AF6BE70DULL, 0x261A8CC3EA11E64BULL, 
            0xAB2641622D0D5A43ULL, 0xE8A2FDA6D3384AB2ULL, 0x227C06D74825EDF0ULL, 0xB7FBF652BD7462F4ULL, 
            0xB3C7120988F06F8DULL, 0x77EEB68CF6EDC515ULL, 0xFE72F278D85D8077ULL, 0xC6C0271B7FF01241ULL, 
            0x9414512E565FAAC9ULL, 0xA309E313DDA9C783ULL, 0x774A3A14B7955F1EULL, 0xAD091FC7913DA62DULL
        },
        {
            0x440F6B8C357364BDULL, 0xDA2005518E1DE2DFULL, 0x5D4342A0C11D4A47ULL, 0xDD33A33FA265CB0AULL, 
            0x930E04B3F175A2FDULL, 0xE1B9FED36367CCFEULL, 0x0A1EA7A96068CBD1ULL, 0x4A15E02DC0B1A1D5ULL, 
            0xC218CFA92753B2E5ULL, 0xB668B46B17EE246AULL, 0x685EE9D1B43ECE7DULL, 0x960F6EE8EB561F8EULL, 
            0x346E88EB0F0D5B3DULL, 0x295309788B08199BULL, 0xEE1A0A62113CB2E0ULL, 0x3F7EBF5557F6DC33ULL, 
            0xCB5870A35A12D868ULL, 0xC25D2858D16E3A75ULL, 0x1D6DE9B1FC8988B7ULL, 0xA7E0681D284312DCULL, 
            0x19B12351FFA6F22AULL, 0x5393AD64DECE67B8ULL, 0x5B8AC7368FE03856ULL, 0x7010F45C856415F8ULL, 
            0x78B6BD2ED25DE0C2ULL, 0x37CFE13C5213F6C8ULL, 0x326A150CC2B5CDD3ULL, 0xFB5D0995BE5662D5ULL, 
            0xF382CD2AA8893D00ULL, 0x4C7959C666A53C01ULL, 0xA0732867D5DFF386ULL, 0x7E1CE5DFC0C34B80ULL
        },
        {
            0xC4FDCABCEFE4B9EAULL, 0x5CCEE777E3572365ULL, 0xEBC95F143BAA3B09ULL, 0xEA75B8EB5D44E72CULL, 
            0x4E472BAA06B468F3ULL, 0x1A3F7E6901843894ULL, 0x806BA59B6607B10BULL, 0xA98A7907BFD0C584ULL, 
            0xB3B3353B10829956ULL, 0x42C836D2F49F24CFULL, 0xC77F2D4CD285E90FULL, 0xFB1D4BEDC6A025BAULL, 
            0xD72D7F238FA998F8ULL, 0x0E0890C4CBBD8E04ULL, 0x3785EE8B5ADDB14CULL, 0x20853305495AAA5DULL, 
            0x6D48012649837064ULL, 0x82C02721D92498FFULL, 0x4AABBBF1DF6B2F72ULL, 0xFBCC3CD35972D183ULL, 
            0x17E6A8BB82DFE4F1ULL, 0x7DC5D4FD82D2F2E2ULL, 0x57E5FFC96C9713F7ULL, 0x3C061FB3D83B37B2ULL, 
            0xE6E9F277D9E0E32AULL, 0x8EF92E15190C84F3ULL, 0x2C6A867ACBE1DCCCULL, 0xCCAB122E1EA5B6A0ULL, 
            0x88C20C6763E86086ULL, 0x89ED117C02090D60ULL, 0x00801BC464E0B759ULL, 0xBA4F3560DB4FE814ULL
        },
        {
            0xDB88BA91390CCFE7ULL, 0xCA1CFE08D90C3ECFULL, 0x75FAE320DF095362ULL, 0xABAC123BACBCF3C9ULL, 
            0x94134F38569CD4A0ULL, 0x2F80CD56E6F8351CULL, 0x2901FA993D9C0EBEULL, 0x04B3AB759FF31E1EULL, 
            0x08235006DE167E6DULL, 0x2FD1E255B0A0B93EULL, 0xD5EA8824B78949DBULL, 0x7E45124F97ECDBFBULL, 
            0x81D68622AF517429ULL, 0xDD87188303088E51ULL, 0xA0DDD41E252256C6ULL, 0xA677E84F7BC9A97EULL, 
            0x53A89988A4842C45ULL, 0xF6E370FED31555ECULL, 0x354F3601859E7CA0ULL, 0xE67ECC2A55F0486DULL, 
            0xABB35E34AAB1787BULL, 0x63D4FE9784F435DAULL, 0x8F17CD38CE9C7277ULL, 0xE7FF4A1BECD6E408ULL, 
            0x2903B65049CC5BF8ULL, 0xDF7515748ABC8108ULL, 0x98A110CA274FECEFULL, 0x37CEC68FF0899566ULL, 
            0x97FB068BAEE55FFCULL, 0x5ED34D6CA40D8C03ULL, 0x694ADE4F097F64FAULL, 0x4506B14FB7E62E01ULL
        },
        {
            0x856C6D31D08E9A28ULL, 0xBCF4963D3D262301ULL, 0xD5614F85B0A44361ULL, 0xA13810C2F91F00D9ULL, 
            0x26836252C67CEF18ULL, 0x52DC93AC6EA2AFE4ULL, 0x438B9718BABEFE0FULL, 0xDFA24F6108881255ULL, 
            0x6B033CDA95E2FCABULL, 0x692A16FEC1599CF4ULL, 0x99350A95ECBDA047ULL, 0x0ABA2D72410C8B46ULL, 
            0x32EE510C1CBF6C5DULL, 0x86AB32982A53B862ULL, 0x48FBF295CA40C69AULL, 0xFE2DF0EBA3EC255BULL, 
            0x26650340C18F8A09ULL, 0x398CEF36A3A74241ULL, 0xB1B27A1D84767BC9ULL, 0x4156E79103A3FFE5ULL, 
            0xADDFC57D486481F9ULL, 0x157118249BF59CBCULL, 0x7B2B979931B3234CULL, 0x83FDC71AE40E6BB6ULL, 
            0xEC415D288CE9C223ULL, 0x481339B7D2B2B0B4ULL, 0x2136D1B6AD2301FDULL, 0xD349D975755EA6B5ULL, 
            0xA14B694A07665EE1ULL, 0x0A744C418E640653ULL, 0xBDE09600BD8A4677ULL, 0xEACD112DCEF410F0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Regulus::kPhaseBConstants = {
    0xEA0C54BF12B7A215ULL,
    0x3BF7EE12911DCAA6ULL,
    0x15AD1D8BF9957480ULL,
    0xEA0C54BF12B7A215ULL,
    0x3BF7EE12911DCAA6ULL,
    0x15AD1D8BF9957480ULL,
    0x71A1F58E78BC0851ULL,
    0xFA37298D1DE524F1ULL,
    0xC6,
    0x15,
    0xB1,
    0x13,
    0xB3,
    0x70,
    0x64,
    0x37
};

const TwistDomainSaltSet TwistExpander_Regulus::kPhaseCSalts = {
    {
        {
            0xECD0E8634DD60800ULL, 0x5EB7748BA9F38FAEULL, 0x2F8B1B81CE90558FULL, 0xD12CB6D85901D548ULL, 
            0x31880D1D1B88257DULL, 0x2FD3D31B10B94F7CULL, 0x50C68524E1FB396DULL, 0xCE0A180A80BC019EULL, 
            0x8B283C673ABFCAABULL, 0x9ED59AB56AFEF9B6ULL, 0xE035847FE60C46ADULL, 0xA34466B5FA97125CULL, 
            0x701AB241EAE2C78BULL, 0x268FFF421D1312FAULL, 0x017E167DC84FF418ULL, 0x59B47BD85BA28DDCULL, 
            0x10F03FCB720E3804ULL, 0xDFDDF4AE382404B0ULL, 0xFDBEEFBF8A591CB0ULL, 0xCE0507F3EA1A12BDULL, 
            0xD2A97C04DB23C84EULL, 0x506845F903A87777ULL, 0x6963AF9FE759E944ULL, 0xA1B2F58CC9E25646ULL, 
            0x9B2CA1FF0BD68866ULL, 0xA7021AD920821C0FULL, 0xB63F4DA348D109A2ULL, 0x47C0DADEFADC4FF4ULL, 
            0x628E5D5962264207ULL, 0xBEED9239E9CE7C86ULL, 0xD41BBAD0F666438CULL, 0x3BB66032316D6A2FULL
        },
        {
            0x22A0C436854E86BBULL, 0xAC8F6B2729E7751FULL, 0x240DB49032644F58ULL, 0xE61C62433A0A878CULL, 
            0x23C0B495C6CC162DULL, 0xA34459BF53608CDBULL, 0x3A611F43BCD2642FULL, 0x7D56C7AF454EE11BULL, 
            0xF53DECD7E54A4EF3ULL, 0x0E21FD56507525ECULL, 0x7B1D9F94F639BD9AULL, 0xA597B00738D4A1AAULL, 
            0x256F88D6820FA38AULL, 0x3FC30809A8CFD090ULL, 0x41B3D692F2929F93ULL, 0xDF5B3A8076129126ULL, 
            0x0639B0B80901C68FULL, 0x2A40F86021FDB238ULL, 0xA12B27A1F64441C4ULL, 0x360FEB02FD8C130CULL, 
            0x530EA57A9ECC37E0ULL, 0x3D8B335777DDFD40ULL, 0xAB28ADC2D35B5F0DULL, 0xE6D629A1D7D0EF82ULL, 
            0x74B58661737AB1E6ULL, 0xD9185513CCA902E5ULL, 0x08B8BA5E08DCECECULL, 0xD9816DB64086520FULL, 
            0xACBC1107DA820EB5ULL, 0x6273236021DC83F4ULL, 0x364691D2D295154FULL, 0x2309027B30DF42E3ULL
        },
        {
            0xA72B69CF85405937ULL, 0x4CCB6D024A443229ULL, 0xA699953FD5320216ULL, 0x951B1AC6098D217FULL, 
            0xB7C47F2CDF0D2632ULL, 0x288F79DDC882E173ULL, 0xD8923CC368CC1279ULL, 0xAACC67A305EF16DFULL, 
            0xBB504CB0285343E1ULL, 0xED602E002D677645ULL, 0x39CAA6646624CC56ULL, 0xF1E113CDA7423201ULL, 
            0x6C1709D0FB550BF4ULL, 0x80F4807276AB387FULL, 0xEE9574488D5BB33FULL, 0x684BB46BE8C8BD72ULL, 
            0xFCD788D67651F122ULL, 0x5C54A9C42A07A81FULL, 0x2F18F220F155EE1CULL, 0xB0ECDE3519FF813BULL, 
            0x9062E69D8DF47720ULL, 0xCA1997304939FE58ULL, 0x3E87C16D7F6A88C9ULL, 0x678205B7E924E581ULL, 
            0xB6EA3176DC16FAFAULL, 0x5441D56C0C89CE41ULL, 0xA34DD36018D6EC33ULL, 0x509AE638F220DCD3ULL, 
            0x1316986C5DA881CCULL, 0xA22CAD627650584DULL, 0x7F65197609178521ULL, 0x5F649C4ADBACD86FULL
        },
        {
            0x84F0938DC0B6173FULL, 0xDAEA92B9ED076E5BULL, 0xFAB914994576C86BULL, 0x0F03BB71520E6DD1ULL, 
            0xFF40F10D67083007ULL, 0xD55459CF4EC30572ULL, 0xA6D4E09A60B600A4ULL, 0xEB11488B26940DC4ULL, 
            0x9DFD0F64385BC8A7ULL, 0xAD299E51EA71C509ULL, 0x81CAC2C6FE05FBBAULL, 0x581577C5B9EB1B99ULL, 
            0x106A5D742AC6577EULL, 0x7BDDE517F021CC31ULL, 0x43881790C5B7B388ULL, 0x120A89274D06A771ULL, 
            0x84D3A64E5F8E6647ULL, 0x16EB18325AC28CC5ULL, 0xE19A7AC9E5345EE6ULL, 0xE3EAF678B30B64CBULL, 
            0x64492CE141BA5364ULL, 0x96B5C3FB1FDD3B0EULL, 0x46C1FFA28A20E11EULL, 0x912DCD91C70BD528ULL, 
            0x35324E6D284E28E9ULL, 0x59E80A55819C4650ULL, 0x073F4F4256459378ULL, 0x09D56E7883170A54ULL, 
            0xE266FEE17796E4BBULL, 0xB4DD164D053B0086ULL, 0xC70143B9F68DB938ULL, 0x1BB2DEEB92367004ULL
        },
        {
            0x245493AFC2C24B26ULL, 0x3FE48B3E702E7467ULL, 0xC8A886F16FEAFA9EULL, 0xAC617D4F9A16A588ULL, 
            0xC2D67C0FB04569F1ULL, 0xB5375672EA644484ULL, 0x37AF4A836B71DB28ULL, 0x51F78D370F8D9053ULL, 
            0xE3217012CDB199D3ULL, 0x73666D6B5FBE14E7ULL, 0x1E50C81A19AA21C9ULL, 0xF0747E7E51FD1798ULL, 
            0x74BA2943C28A3025ULL, 0xC001C21EAA04C408ULL, 0x098AB64187FEBF12ULL, 0xF29DC19C1A6ECF72ULL, 
            0x76BAC913A598F619ULL, 0x82211957A3130C72ULL, 0x6DBE310D549499EEULL, 0x1E1E243E0A827E7AULL, 
            0x0549716D4574A14CULL, 0x8D5C7724EA8E82B1ULL, 0x3F2F93F59BE6BB62ULL, 0xBA7832576C1DF899ULL, 
            0xD72E34BFDE782E2DULL, 0xE55654E72AAF4EB6ULL, 0x61DF711F9733E4F0ULL, 0x64E7B3D0B398D1F8ULL, 
            0x814BFA77F970E817ULL, 0xFE32B51CEC029BFEULL, 0xAD34E8A8D0FAC3B6ULL, 0xCAEB6C46629F5762ULL
        },
        {
            0x64421B20EB7D745EULL, 0x0AA7353232A1EC9EULL, 0x0BE29F3524E0BC06ULL, 0x71FF2563E41C655FULL, 
            0xA5800D66389EC741ULL, 0xA9819E707401E136ULL, 0xF04F596E28B60DDDULL, 0x109BB72076D1D012ULL, 
            0xE565980B3C1EE509ULL, 0x0B09B35F06FE718BULL, 0xD93960490F4AF0FEULL, 0x64D741F507494E7CULL, 
            0x66E68C39FBB9CD94ULL, 0x8CBE36DCC3C2DE8DULL, 0xBEC450A807E1C7E1ULL, 0xA54B5FEA94DD4169ULL, 
            0x287F63E6E52718AFULL, 0xB4127AD8F8AF41BAULL, 0xDEF7D399B9A949D1ULL, 0x880D84C453A44619ULL, 
            0xA86296C4D239FA2DULL, 0x5188E0D2BF51FD68ULL, 0x3E909621E00B930DULL, 0xA1FF8B291819D5A0ULL, 
            0x3DB726B6DABE5EE6ULL, 0x07BAB743C44BA152ULL, 0xC844E2D6093188E9ULL, 0x8F586F2B5BB81942ULL, 
            0x407104D513B4B507ULL, 0x99EADC64049B9436ULL, 0xB56D72FD0397728BULL, 0x66AB21A853C2ED59ULL
        }
    },
    {
        {
            0x4DB49F263FA75EA6ULL, 0xC96797170D5EFC51ULL, 0xE59A98F352CE86D4ULL, 0x61AEE1C03C1108BFULL, 
            0x8906FE376A35F37BULL, 0x010BF85B0A0AEA71ULL, 0x9AC18F1362598E4BULL, 0x3B2E0ADF92EDFA6BULL, 
            0x6D4ED91DBEDEC289ULL, 0xFFFB86E292B20746ULL, 0xCD64964C005D4522ULL, 0x0B13C108016E2E0DULL, 
            0xC0B89D95C1E5AC17ULL, 0x8CC3172C8FF0CCF0ULL, 0x89403AB22CB2C505ULL, 0xD65107E3DBB24A36ULL, 
            0x849C00B7D05FB623ULL, 0x6F029CD8387DA2CBULL, 0x6D29464BEFCF81E8ULL, 0x33D21BB8820951EFULL, 
            0xDE761DAA8980E5E3ULL, 0xE1E95AF5CCB7448FULL, 0x89DB537568C79765ULL, 0xAB9C20A2EA076733ULL, 
            0xC6A73935F11D02D4ULL, 0xA1073E2741A59E54ULL, 0xFEE1F57D29027FAFULL, 0xE8C732BDE3F9F590ULL, 
            0x56D56C20E60705B7ULL, 0x6C7D2180562E00B7ULL, 0x7F0ECA6D997BFC2EULL, 0x3D520023F6FAE0F3ULL
        },
        {
            0xA161244F44597766ULL, 0x7C39C0B950A665F3ULL, 0x9AB5B6E7E766B0BCULL, 0x3345EE57911789CFULL, 
            0x3E152EDFAB073E90ULL, 0x2F8973176E9CB2E2ULL, 0x3EA68916C117B509ULL, 0xF23447DE870D4C31ULL, 
            0x604078F42AD7999EULL, 0xB8665A3BAD9E543AULL, 0x0C298C0BAC8FA308ULL, 0x4D6BB45C398C01CAULL, 
            0xD665A0B3A3A8532BULL, 0xE1C481053779CAF6ULL, 0x89A32D3476612C29ULL, 0xBCC454C61F973DEDULL, 
            0x16AA6E0AEFDFD664ULL, 0xD33F20D1A1AAE7FDULL, 0x8D3550241AC78EEBULL, 0x07D05EEA38E8483EULL, 
            0xBC2727E12990E29EULL, 0x16370D7D7B51455EULL, 0x707F1C9B0499D711ULL, 0xA8E9B893732C4629ULL, 
            0x0CACF03E0054E959ULL, 0xB4C32F4366407912ULL, 0x1BF307398FF0E2DFULL, 0x2FDAB14DE5CEB629ULL, 
            0x67E3415BECD2FBDCULL, 0xFFDE4071248BA619ULL, 0x1A67D561DF9CCD75ULL, 0x3BFC9839D24E11DCULL
        },
        {
            0x3679E6C99732ADD3ULL, 0x331F9A3FA1FEE220ULL, 0xF44D7B57A74F732DULL, 0x11DC19663E70FE67ULL, 
            0x7B98D14ACD42D96AULL, 0x4D681CA2D0A7F98EULL, 0x710997F94BE58D35ULL, 0xD473A128B60F9516ULL, 
            0x187F8C7E6872BEB2ULL, 0x4D587685BAD48095ULL, 0xF5D0FA487BEA4428ULL, 0xEA463043D9F992E3ULL, 
            0x3E411F4F5E4409EAULL, 0xA73D43DB9FC5C966ULL, 0x9092159153B5FE65ULL, 0xCE4A36AE440BCBAEULL, 
            0xE46983DC58EFE240ULL, 0x7A04B55757AC200AULL, 0x486496BA58DDFF2DULL, 0x2A1D2A81E55A4343ULL, 
            0x2B46FC87E3983608ULL, 0xB8A10B5ED8D0DB8FULL, 0x6BB658660A75B840ULL, 0x0778F87BE7CE96A6ULL, 
            0x2AFA4192FD9092E4ULL, 0x71BDC0C853BA6A72ULL, 0x7C7450E216906ECCULL, 0x054EBDB38A6381D2ULL, 
            0xD854FE54DC12D0FFULL, 0xB5A58A95F7B30AF6ULL, 0x160DA3FC690DDC3AULL, 0x4433728794B502FAULL
        },
        {
            0xD0D49A06B2E7E0C9ULL, 0xC670E53DF96DB886ULL, 0x7AFA827DD454C82DULL, 0x1C776E0FFAC7DAA8ULL, 
            0xDDBB1E4A6FAEF4B5ULL, 0x314EF4F0F465CDD0ULL, 0x14840E0727047992ULL, 0xEFEF75972A5B2236ULL, 
            0x1213F406913EDAC9ULL, 0xA07D887FAC5C4068ULL, 0xDBECA475D7204809ULL, 0x0DEC327368C4C7C2ULL, 
            0x0C79EB665149CF25ULL, 0x371FF1EA5D9218DCULL, 0x63E6259803329044ULL, 0xD5343CC1FC3E8227ULL, 
            0xD23C45C13B6A3DAAULL, 0x0C712F8D9C7319F4ULL, 0xE6A982FF3CE900F2ULL, 0x2D66AED481819945ULL, 
            0x6740981241CC6788ULL, 0x4F39609E4AB52D1AULL, 0xCD8BCB51496FC0A8ULL, 0xC1D2CF84116357C8ULL, 
            0x65D3EE3363FA9FA8ULL, 0x77236DCA1C27B4EEULL, 0x27CFEB6D64D5856DULL, 0xE34168395F2532B7ULL, 
            0x1B195BE698736265ULL, 0xBC8F8DDEB7100DBEULL, 0x20A77DE476234A30ULL, 0xDDB3238DA569F4C9ULL
        },
        {
            0x97E7DB1663D66232ULL, 0x06511E4BC45C60F0ULL, 0xC54587CF03094EC4ULL, 0xF4D1FEEE701AF9C4ULL, 
            0x1D2BEC34EDDE83AEULL, 0x24CBF0AD64545B9EULL, 0x0203F6C00DDAD6FCULL, 0xACDCD449B80C8DD7ULL, 
            0x89824A469BC231B7ULL, 0xF34A308F08F05A74ULL, 0x142CC6F22CB24EA7ULL, 0x007964C7310687A2ULL, 
            0x5E326C949230FB90ULL, 0xF525F97F9C7D2D8DULL, 0x90F054215CD8CF79ULL, 0x969C9109714493C3ULL, 
            0x1D4A71A9F697403DULL, 0xD0DF2BDB796F1D6BULL, 0x38F1974D86518AFDULL, 0x20B1275AC8792E59ULL, 
            0x41FC891276439708ULL, 0x274BF322F0B00E38ULL, 0x97BD48C8EB5240ECULL, 0xEF5BDAE5C1D6B0A1ULL, 
            0xD3306370FDD59BEAULL, 0xA6B82F141F36DAC2ULL, 0x8F8BAD34241B5121ULL, 0x945B908E9A679807ULL, 
            0xFB467D773D36DFD5ULL, 0xED7EBC43DD9E22E1ULL, 0xA7073AFDAF52E0CEULL, 0x50123A10309E7437ULL
        },
        {
            0x0484A574EDB19890ULL, 0xF552A7EE2DE36332ULL, 0x64D284FB2306E171ULL, 0xA126B397EAD57DF8ULL, 
            0xBEEFFA026C473BDFULL, 0xC929DEA1F8B79694ULL, 0xCF7F8D570A80545EULL, 0x4B5DE935A38A6B33ULL, 
            0x33E63D038A5900EDULL, 0x73EDFB1E586B2FF2ULL, 0x987C1F7DE6704B6CULL, 0x6FFBEC00C47DE102ULL, 
            0xB2A7FF0218668BC3ULL, 0x74D5ED1CCE54D4CBULL, 0x96E594D156DA49FAULL, 0xBE0D56FB74888BA0ULL, 
            0xE8FCF032FBBB558FULL, 0x38C33C544A587A32ULL, 0x623DCB0817DC818BULL, 0x42ECFC2D0A49995CULL, 
            0x2F1D02C42AAD61EEULL, 0x16E7A46CA8017F10ULL, 0x7E85B90B509E0CD6ULL, 0x908C0F02ADB6BC1BULL, 
            0xAF05BDA93F0CE67FULL, 0xAEB8EC5CEC404690ULL, 0x6B947128CC1EF510ULL, 0xC840D75153AD9D1EULL, 
            0x2EF4E8FDBEC58D2EULL, 0x3789F03D89A87731ULL, 0xF91090774CC42539ULL, 0x350FC4CE75B6B1E2ULL
        }
    },
    {
        {
            0x7660131E519085B6ULL, 0xAFF71104B6711D2BULL, 0xBCBBDA27E9EC6F4FULL, 0x6612244EBDFCA16BULL, 
            0x2DE91180AD23B4BCULL, 0x7FF1131C26F41E12ULL, 0xE8EF52C6FA7E811BULL, 0x4AD789497C6311D6ULL, 
            0x36DF9264349B64E3ULL, 0x052CDDA2A6DE6380ULL, 0xCD8DEB557381F3B9ULL, 0xB36252EF27357A63ULL, 
            0x3921B3CA5777E02DULL, 0x1B508DD1D6F89A7CULL, 0x5EF44CB062FF70DAULL, 0xB1361548CA0129F1ULL, 
            0x97592CF4D6EC7190ULL, 0xB40E98FD0846D5F9ULL, 0xEE7997B39E9C2108ULL, 0xB6DBEB28FD2DBB23ULL, 
            0x87D44F7F661A47A5ULL, 0x3D8EC43B81F9A97BULL, 0x5DF44D85ACE13FDFULL, 0x8983FEF93FC1F3A5ULL, 
            0x792C1D6F61210BCDULL, 0xB2E55C646DD69AE6ULL, 0xAC290003CD14A76DULL, 0x426F1555428176E7ULL, 
            0xEE962B876F805AB3ULL, 0x96F4973DF448A223ULL, 0x7138811619CCEF02ULL, 0x44026A0232F52A79ULL
        },
        {
            0x0389DB3B6535D186ULL, 0x52C6A724D9462043ULL, 0x572E5EFD1F11E317ULL, 0x05D75FBB83F71D76ULL, 
            0x3A11CC3D1A628CEFULL, 0x09D01D1C38A2DBAFULL, 0xFB3A1A05AAC11A3DULL, 0x2CB8158C626EA201ULL, 
            0xC9031470A3465587ULL, 0x3F0687A9DAAC02A7ULL, 0x064D0615F1E5D3B6ULL, 0x2A17A5B31016215DULL, 
            0xDC5E940613CF2E0EULL, 0x8D7D3D43C2AEEF3EULL, 0x2682429F584A8062ULL, 0xE887556F22A2E1B6ULL, 
            0x2A036D64D8CA6EA3ULL, 0x14693BB72FB14081ULL, 0xE526E82AB67B7630ULL, 0xB1888C48509D8063ULL, 
            0x84466E5022D6F2F1ULL, 0x106E9A5CA63CEF41ULL, 0x0E2ABE4ED99DB614ULL, 0x3E39DFDF1AC26E0EULL, 
            0x176BCCB884C5EBE7ULL, 0xE8A7D1BA0F2EFBE2ULL, 0x8A9C919161AF21BCULL, 0xD1D939E4F951CEB1ULL, 
            0x365954E1A10EBD6EULL, 0x4E8B4F69311311E8ULL, 0xED214A973BDD7B4FULL, 0x66CE4602EAB0C4DDULL
        },
        {
            0x1B3377F09E8677A9ULL, 0x15E5E6990EF27C74ULL, 0x676C104599AA99C7ULL, 0x3258A7C98B28FCCDULL, 
            0xA98D32F98DF80546ULL, 0xD5255C74EE1E2996ULL, 0x2C4C0689384F5061ULL, 0x17D858B4C91788BEULL, 
            0x88F5D8180FA96D02ULL, 0xAE808C59D89B83A7ULL, 0x0F5FDAE72FAD4A1CULL, 0x6079973E55D0E8EBULL, 
            0x5393CCC3B048A68EULL, 0xB56F44E545C01CF6ULL, 0x875CA1D40317AFDAULL, 0x73799149F6F3EFD6ULL, 
            0xEAD4D9C21CC365F2ULL, 0x1ECF27702581239EULL, 0x9E9410138868F2E9ULL, 0x48A8B9386EB68375ULL, 
            0x5F7B2892A7072C33ULL, 0x5A359BDA18EC2CA6ULL, 0x879BEBF934A28956ULL, 0x0DFEE824A206FD6FULL, 
            0x612C99346440BB68ULL, 0xBD3BFF7B5BB3E293ULL, 0x490214CD50129A2DULL, 0x7F7C575356DBD55EULL, 
            0xF3F7C8A50E6B98B0ULL, 0x254B76A701D452C1ULL, 0x2E838C13A5BAADD9ULL, 0x4F535E4E472B09D2ULL
        },
        {
            0xF1BA43DBEA460050ULL, 0x99D018883DFECF15ULL, 0x2A8B5AB58A36FA42ULL, 0x14154EE7969F1307ULL, 
            0xE1F82B1CDFE36FD6ULL, 0xDD86F1A3D8B36B93ULL, 0xEBD9FBDB0FF155ECULL, 0x9C678CF48FE09F3EULL, 
            0x0BD25F172B4B2A24ULL, 0x7BE66B03DB633D74ULL, 0xE8E8AD87E50D6AAEULL, 0x8ECC58EF7A07BA19ULL, 
            0x482C80AFAD91B6EDULL, 0xB8F2385FB62B8D0DULL, 0xEA4844313DF6EFC9ULL, 0xD39F2761DF00391AULL, 
            0xDA5D25055DDE0F9AULL, 0x9A728A652B5D420BULL, 0x500DBBA5A1DCB18DULL, 0x73E8BD2A4039C80EULL, 
            0x8807B5E640322595ULL, 0xB0BEBF39F4C94B80ULL, 0x6D940151C6F6C3A2ULL, 0x473D5A06E8B4BE25ULL, 
            0x9E9D99549E035183ULL, 0x7E8663AAF97BD94EULL, 0x27CABDC4A36A6988ULL, 0xC3F13DD14F82C9C3ULL, 
            0x386B1AF4E7CD52ECULL, 0x93A10CA867A93AD8ULL, 0x96682B7DBF32E69BULL, 0x4026FB7898883216ULL
        },
        {
            0x631B88D4678E3C2EULL, 0xA046E37FE548D85CULL, 0x4C6948761D881914ULL, 0x07EEB9F375FB9A5DULL, 
            0xB5BF41C3D980C8D6ULL, 0x22A72A7542778871ULL, 0x7374C78799670A74ULL, 0xDB842AA04680A69CULL, 
            0x3C95E212DF7E4330ULL, 0xB802635B551D5BD5ULL, 0x00E8196408B131E1ULL, 0x6CC5C9335B1AD31AULL, 
            0xC7662C9DF511B292ULL, 0xF2EFA5FD7D175B0CULL, 0x21462AA1531B83C3ULL, 0x3AD03CB89091B029ULL, 
            0xB4F224BEE8CB18DEULL, 0xAD28E6CC312E270DULL, 0xD71AEAB6AA01DDDBULL, 0xE40B8B4BD314A781ULL, 
            0x7CD5B1DC54FFF7AAULL, 0xDDAA1B9727F2BB83ULL, 0xF0F415777232DA10ULL, 0x3D3170AC139CEC83ULL, 
            0x9E4BFF2AEC0B6634ULL, 0x895DA0BE05B949E2ULL, 0x964FD4D7755DEC3EULL, 0x12E182B888277F3DULL, 
            0x71505331FAC8D9A1ULL, 0x387A43BB48A46D41ULL, 0xA0AB8FB8C91F7356ULL, 0x25FE0E11CFC5FD4FULL
        },
        {
            0x41134858EF042762ULL, 0x5BBDDE7DCFD46FC3ULL, 0x86615196E0FF9647ULL, 0x95588060CA3EA964ULL, 
            0xCB74811672644461ULL, 0x913C776B6044B8A9ULL, 0x7FE5C055E2F7D4C3ULL, 0x37999D29BD7164A7ULL, 
            0xA24B45627B1EDF49ULL, 0x9ACE58F61E9C22BEULL, 0x743E74AAFFB5CFDAULL, 0xC464B942389207FEULL, 
            0xB7A57D0C3D246119ULL, 0x6B4EA2E9C7AD7E57ULL, 0xC994BFFA9F84ACF2ULL, 0x2FEC25F4AC092D23ULL, 
            0xA5FC622B8E7B0223ULL, 0xA212F493E016B99FULL, 0x68B745D6123C3911ULL, 0x962731ED268F037FULL, 
            0x648B8B0D68DD21B4ULL, 0xD2B201392FB985FCULL, 0x32C04E53DC0F8310ULL, 0x4EEF03F9FA25B2D2ULL, 
            0xFC6B787B4AF38F2AULL, 0x5E2DECCAE011B685ULL, 0x4FF61CC9880169A7ULL, 0xDF2760A91AE61571ULL, 
            0x57D8A96929039FA3ULL, 0x3BC55D473AA50856ULL, 0xC16E365AB4CB21B6ULL, 0xC285B78CC6471B14ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Regulus::kPhaseCConstants = {
    0xF66E040CC94A155AULL,
    0x716291D294A259A3ULL,
    0x1720A1217C38FFE3ULL,
    0xF66E040CC94A155AULL,
    0x716291D294A259A3ULL,
    0x1720A1217C38FFE3ULL,
    0x74136D1C7C6D36A9ULL,
    0xE54161B3EBFAE7C2ULL,
    0xBB,
    0x08,
    0xD3,
    0x7C,
    0x4B,
    0xD0,
    0x3E,
    0x16
};

const TwistDomainSaltSet TwistExpander_Regulus::kPhaseDSalts = {
    {
        {
            0x22F2ABE0047CC3EAULL, 0x1DEE60D8FBD147B2ULL, 0xC2669A186D935FC0ULL, 0x3456341905BAACAEULL, 
            0x512B43875FD0EA24ULL, 0x42B01C50A447AE75ULL, 0x95D24DB1625580CCULL, 0x048BD5456C86E4D7ULL, 
            0x18072DE9D81BB672ULL, 0x716C5F763D3D9A9EULL, 0x0A079C2E9575B836ULL, 0xC5804E1A77ADD1D6ULL, 
            0xFBC8BF80F24062CCULL, 0xC5B4DE742902D5F8ULL, 0xF0DDD8ECAB223A15ULL, 0xDC0A1504225E84E0ULL, 
            0xAE3DC1071F4FBB48ULL, 0x270295E243E2BBB0ULL, 0xCCC6ACD80D8B22DBULL, 0x1E49E010941572B1ULL, 
            0xB7D25B5E13260BBFULL, 0x689E7071858CF4B8ULL, 0xBB7A943FFCD60CC0ULL, 0xCCA41AE20E4A7169ULL, 
            0x511869AE8B605A6CULL, 0x14E56F84270EFA5BULL, 0x6525F05905A9F2EEULL, 0xD14D7B8EFB4FECFDULL, 
            0xC4204AC6699C1AB6ULL, 0x96D61C52894C38E8ULL, 0xCDEFB4A1D3745910ULL, 0xEC3F21103E5323FDULL
        },
        {
            0x9155EACA2611798DULL, 0x02F44C5F054442B9ULL, 0x8F2D807C94907ECAULL, 0x6B4352EE234EC11BULL, 
            0xD6FC1107A635F60EULL, 0x2F79918CD96EBF08ULL, 0xA052850F62D01B71ULL, 0xF3C3CB908A0BBFE3ULL, 
            0x263E5E793F890B29ULL, 0x08125A4C2E60A4B2ULL, 0x4F66783C10E94B11ULL, 0x2486B4172236488FULL, 
            0x87904A3F1057B7C0ULL, 0xAAF31F240FB5BF72ULL, 0x5ACF584346EB6B05ULL, 0x4F8D06B937ABC7CBULL, 
            0xB7BF7B69ED50B7A4ULL, 0x08F0015E63D50D6EULL, 0x000B799E8243A482ULL, 0x5556818EFED184EFULL, 
            0xCBA8428F8BA8932BULL, 0xEB6684349F8BB195ULL, 0x5F685CF7226C4E7BULL, 0x54C6068DA2675508ULL, 
            0x22C30DFD973FE020ULL, 0xF5043D79FE0A17F2ULL, 0xDEF0C1FF67CB6BB6ULL, 0x60C55C771099FDA9ULL, 
            0xC3C6BA88EAC7901BULL, 0x290860D4316EF312ULL, 0xEF939C800B3B6C26ULL, 0x809427F2768EF100ULL
        },
        {
            0xDC75BAD999D54D71ULL, 0x6D1FF4B34864FA45ULL, 0x650B59BF0ACF416FULL, 0x28399AB6AE385544ULL, 
            0xDC86886648247111ULL, 0xE6CB00BC9C12EF18ULL, 0x916A610499D85AB3ULL, 0x689D157EA1FB5056ULL, 
            0x2D2FB4F7751887E0ULL, 0x66F8C597361B6966ULL, 0xDE2F9F88E9054DBCULL, 0x43555769865DCA79ULL, 
            0xAB90195A968482D3ULL, 0x5A09655D685F9EA7ULL, 0x100CA5E114CEEBDEULL, 0x646A5B85A9411451ULL, 
            0xEE2BB1F3EA2822B2ULL, 0x8730313DDB6D936DULL, 0x87534F4A15DBBD26ULL, 0xBEAFD0491BE27BA4ULL, 
            0xA8A8C32C160FF9ABULL, 0x10988A67FE6FF015ULL, 0x9E0249B9B6EA0644ULL, 0xA4CBB1B819B628A9ULL, 
            0x8CA4CB101907F378ULL, 0xC7D699DB5AA7508CULL, 0xD4F33C0CCAF82EF0ULL, 0x16BBC0C532002666ULL, 
            0xF82A908ED2DDA035ULL, 0x924DA0B5EC632BCEULL, 0x17F06B84ABDC8AF7ULL, 0x922E1619C8594EE2ULL
        },
        {
            0x2F2D3E485DA32C1EULL, 0x9BF9A08BE31EBFB6ULL, 0xAECFA2006842A908ULL, 0x816517FE54F659C6ULL, 
            0x651CEB776FDE1605ULL, 0x650820492F78E207ULL, 0x5436A9FE7D790210ULL, 0x8C721FB9E73FBB49ULL, 
            0x3F6838523BBA3324ULL, 0x9DB65974F7A0E11AULL, 0x25A44E8CB48EA2C3ULL, 0x63753CF34C6B33E7ULL, 
            0xC40E2D3DDCE348B3ULL, 0x3F887939FFFA8CD5ULL, 0x1A8AF10728A76635ULL, 0xE0BDC736A9B9AD16ULL, 
            0x578B2EED096D45FAULL, 0xDA0E76AC29A5A2ABULL, 0x932EC2B6E34F1084ULL, 0xFE7605173DD1859FULL, 
            0xC904B85877FAB96DULL, 0xC1A2D9EFA2FD8577ULL, 0x4EE18EDB7D87B0CDULL, 0x3FD7E9160C72C6A8ULL, 
            0x114252EA49108BE9ULL, 0x8CF658693B0FF3B3ULL, 0xBC2F7D47CFFF7BB9ULL, 0x77F1CC4B2A55727EULL, 
            0xD66CDAC576DFB1BEULL, 0x92900D21DF18DFC7ULL, 0xBF03006CCA687BDBULL, 0x63118B1F2028C6F8ULL
        },
        {
            0x268D861E833CF7ADULL, 0xA523F6FE91A70565ULL, 0xBC287BF72807F733ULL, 0x39017D54875C7271ULL, 
            0x6BA86C2561964A57ULL, 0x9CC0CC79CF4CE85FULL, 0x17DD2D03164440A2ULL, 0xD48195609F3E2EB1ULL, 
            0x76C071D925E93FB2ULL, 0x7D2945246698EE0EULL, 0x11344DA7F30A5C2FULL, 0x4CE4687C68CBB2FAULL, 
            0xB4C22DC8C82EE2E8ULL, 0x13E89FF05E5D6E1AULL, 0x19E856650D1C2208ULL, 0xF3C3C9AC2BC22DD3ULL, 
            0xA65674B14934E230ULL, 0x6188E1678F9145ADULL, 0x60F11F4F35016C3AULL, 0x16F67A553ACE5121ULL, 
            0x5EB7F183C638E829ULL, 0xAA76CE968C717358ULL, 0x6F339D6E83D007FBULL, 0x61E115AD6ACCC43BULL, 
            0x70D0D40CFBDE47CAULL, 0x73CAD315E785E6A8ULL, 0x4DEE5B7538B43907ULL, 0xD5AD508A748EBCF1ULL, 
            0xA53C68C9C020A096ULL, 0x10D2F120E81F3A00ULL, 0xADACA98AB5E1ECE9ULL, 0xBA02BADF994D27A6ULL
        },
        {
            0x7BE33D325D31B65FULL, 0xD45B06AC6FE525A2ULL, 0xD65732AC58D31B9AULL, 0xE0FA937600D1E4D3ULL, 
            0x0231AEB066F425F5ULL, 0xB60CD5DC0D321FE3ULL, 0x9817AD5A804CB3FDULL, 0xAAD3DB3583C991D5ULL, 
            0xB61091003241FB6BULL, 0x51B1A30698E9533BULL, 0x50E12FA597C0395DULL, 0xD243F6A26124242CULL, 
            0x1FB7B5F192B1429AULL, 0xDB699E9119828A84ULL, 0x00E7C709E79EB097ULL, 0xF3AF5E1325AC07E5ULL, 
            0x2554B71073821DA4ULL, 0x9CFBE3B6F6A05FBCULL, 0x59A26E721E33A68AULL, 0x5A746A5B983F03A7ULL, 
            0xC7D3B65B5D5EC153ULL, 0x4F3994238ECD152DULL, 0x105BD3A5BC4BBCF1ULL, 0xBF1C4073153A9E9BULL, 
            0x1BE9ADE6CED25ECCULL, 0x36C628CD2F4A5FB9ULL, 0x02794B5E9C6C875FULL, 0x38112B424A10C504ULL, 
            0x1780AACBE93A17FAULL, 0xA54A0CC297988D2CULL, 0x3DB28AA5591552C0ULL, 0xF0BED59597F4BB48ULL
        }
    },
    {
        {
            0xB1AA1D036FB760C4ULL, 0x92814354C1C2B4EEULL, 0xA7287370C59EA1D2ULL, 0x69E57254F095758FULL, 
            0x2C996A6584BAD9B3ULL, 0x9A4BF17EDAD9F4E1ULL, 0x78622A57FF8E6653ULL, 0x40BE75151BB8088EULL, 
            0x013EC6272E8E3038ULL, 0x5C0E7219D3147E3CULL, 0x833372FB15004093ULL, 0x98007000BB6E126FULL, 
            0x9165A77E9739B26DULL, 0x8D6E610442B38A44ULL, 0x6F596CBC7044E3B5ULL, 0x7A7467703576CDFEULL, 
            0x45E95F1BB5B4CD79ULL, 0x9FA03F953793D6D8ULL, 0xB39AB2AC46FDC291ULL, 0xC29D947B894198CAULL, 
            0xC4966997421D8CF3ULL, 0xD5ABB8E1B62636C8ULL, 0x5EC65F32CA4EB937ULL, 0xCDBD9AE481276C4BULL, 
            0xA5CD77C40242CAD5ULL, 0xB0F4313D74F75CF2ULL, 0xD896F2A69EE2371EULL, 0x7D400FA30B0D202BULL, 
            0x3A7CAE32B7E4AAE6ULL, 0x5EC92412B97B7B1CULL, 0xCD9069D8307B4306ULL, 0x63B70DC48D2DEE5AULL
        },
        {
            0x26AB27E4B47164E9ULL, 0xD4B48680F28C4D19ULL, 0x8CE5F60F6EFE93C0ULL, 0x819DD60DF098D99BULL, 
            0x57D80FBE5E3ACB37ULL, 0x2DE2254F1879A1F5ULL, 0x6610948A3D50BA26ULL, 0x267B43D81A80BC99ULL, 
            0xBB07E3B7D7B59236ULL, 0x6CBD4EE17A395426ULL, 0xE38F34C2C08418BBULL, 0xD0FA2527A8984216ULL, 
            0x83282ADF1DE4CD31ULL, 0x09178353BCFD0A1BULL, 0x776711923AAF3B3CULL, 0x4574F73D25602AF9ULL, 
            0x07355BE21BFE9215ULL, 0xBD5F2A82447173EFULL, 0xD1E064EAC84CA66DULL, 0xB166A51527EFC7CAULL, 
            0x85FC97604113165CULL, 0x66B482FAA93D1F1BULL, 0x61530CAD2A214D67ULL, 0xB69BFE281D78DBB6ULL, 
            0xDB6406F36B058DC8ULL, 0x87DCC15488065508ULL, 0x862D48A2594F66CEULL, 0xEF8621771BF9DFA9ULL, 
            0x4516BD202DF15F90ULL, 0x147EB673E10A114DULL, 0x052AEE56AE7A0B58ULL, 0x3642E88A2F180EA8ULL
        },
        {
            0x67E8118F18F19A8DULL, 0xD61BBDFC53E6DE77ULL, 0xE87779389A70F5C8ULL, 0xFAA192BC96CBFAA9ULL, 
            0x2B93FE0C3146824BULL, 0x8CEE4223761E01F6ULL, 0x257028E3FB6304B1ULL, 0x0727D402C4AA43B6ULL, 
            0x17AB41C21D49C2CAULL, 0x97B311C36F4F34FCULL, 0x5610199A6E8D0E09ULL, 0x981B8D3297027C46ULL, 
            0x639B9A24FD995A01ULL, 0x6662C9ED8E9CD28FULL, 0x06B97C3807E1FDE8ULL, 0xCD2FCE0EE3EBA134ULL, 
            0xFBD9AB73380EAB38ULL, 0xE4C549A8C1C62253ULL, 0x28D98EF28117B629ULL, 0xDFC5F79FE2E151C4ULL, 
            0x404AC171A09C6A44ULL, 0xB22A38DCE934131AULL, 0x20045EC0C6C3B433ULL, 0xAF02FFCBF4A7B974ULL, 
            0xA8E89C7BB6A7F58FULL, 0x18B411C7118EF03FULL, 0xA5173C43BD780663ULL, 0x814D15D6E27B0CC4ULL, 
            0xC072B18A62B3B98EULL, 0x457E455DF6A3DB56ULL, 0xFFDBDA0112C5D3F3ULL, 0x3FEBBADDB095EB0EULL
        },
        {
            0xCD7E299C0FBCF75DULL, 0x4B738BCC45738954ULL, 0x0B6CE9D35F17986AULL, 0xD8EA65A64DFE7A1AULL, 
            0xEE6DE9BAC74A1BF4ULL, 0x8A92778B481E8E95ULL, 0x21B9FEEFD2EB161CULL, 0x47708AB8673D772FULL, 
            0x48A220337C691F86ULL, 0xB3992CFAF67B294DULL, 0x721901AD03BA3698ULL, 0xEAD2C0B9BF8F37B6ULL, 
            0x8653DE6AC6FDD12EULL, 0xB14635588E89AFC8ULL, 0x23A2550BD4256436ULL, 0xC4723EA7B4E08991ULL, 
            0x4D2ACC3C09F3653BULL, 0x54FB99E99938E145ULL, 0x432483E0250FB462ULL, 0xC500EF5D0556193FULL, 
            0x65082103D92825AFULL, 0xD9A8B9F8C44250CAULL, 0xBF46572A50F7BE75ULL, 0xCDC219C0FE8905B5ULL, 
            0x3B4FF62414404BB0ULL, 0x243B16BAEC240880ULL, 0x5B707418EE57E3B1ULL, 0xFA31A52372306643ULL, 
            0xDD69CFA209372400ULL, 0x76ACD01A22E95790ULL, 0x641D39C038233E88ULL, 0x30D1433645EF9AC4ULL
        },
        {
            0xBFAC3A37CB3E011BULL, 0x8E015943A311CD49ULL, 0x480A3BB287A7F254ULL, 0x3D1C2434FC6B098DULL, 
            0xADB56F8112AA289CULL, 0x7A6FF68ED9F3DB53ULL, 0xB813DAB570142248ULL, 0xF1CFC0EDEF60D799ULL, 
            0x9C3ECA9A87344A66ULL, 0x63DC1B5BAB85AE59ULL, 0xD6F0E9C6699D9CBFULL, 0xC74936A12E22E104ULL, 
            0x0ACA33DCD64EF4A2ULL, 0x2F6747D746D8EC09ULL, 0xB88049F99601E27DULL, 0xB4CC2A0F2A0F3F2CULL, 
            0x7CF435E120A6F3D5ULL, 0x8D14B593616528B5ULL, 0x29334A3D47085EC4ULL, 0x9211E7293448F7CEULL, 
            0x759E43CABC9664F0ULL, 0x6AEFC07C6B80942AULL, 0x998D5417ED09ABC9ULL, 0x9439680119E8FAE4ULL, 
            0x00EC986242AC4571ULL, 0xA7600B8638634F59ULL, 0x7872C7312F0CE8E6ULL, 0xF21EDBDB00042EC4ULL, 
            0xCAB59B6CB38812D4ULL, 0x04D2166E170E70AFULL, 0x0680C608B525D327ULL, 0xEE6BDD25C2C55822ULL
        },
        {
            0x44A43CD317521326ULL, 0x68E94273F7252A91ULL, 0x75DC5336AAEB577DULL, 0xF1C22AD41D4D4FB3ULL, 
            0x7ABFD6103AF86590ULL, 0xC3EDBCEA4131A092ULL, 0x73A979074E0CD869ULL, 0xD38FAFC861F40075ULL, 
            0x58A7C3677E83DE4DULL, 0xBDD573B4F66CEA69ULL, 0x8F68177345747B39ULL, 0x218150CD6D8A8F46ULL, 
            0x8A24C8F921E8B7E3ULL, 0x5DF8434DCC8D025FULL, 0x9871DC15460A2914ULL, 0xD75C5D9BDBD3BD00ULL, 
            0x8D661B569F506846ULL, 0x6C15C7E4D368F9EAULL, 0x20B62171727D32F0ULL, 0x555DD5E8E3507043ULL, 
            0x630EEE77F0893E1EULL, 0x5384EA1BC9F8DBBBULL, 0x11A356B96285EB43ULL, 0x1CEC48FB254DEA60ULL, 
            0x474FC33A8ED810B4ULL, 0x09482286356F0E45ULL, 0x45A7356272BD4B35ULL, 0xC1873D4EE9B57151ULL, 
            0x4BAFA9F2610E82DDULL, 0x2BAA5848DF1DDAACULL, 0x4B1ADB64E209E27CULL, 0x7A65E18E3776066EULL
        }
    },
    {
        {
            0x371904D42A11809DULL, 0xC73DDD16511B9B41ULL, 0x87A1FA74F84A33E9ULL, 0xBBB5F1CFD95070E2ULL, 
            0xA2431614FA04CD27ULL, 0x3E83424745686753ULL, 0xD1BAD448D084EB31ULL, 0xF9739E854A8E3356ULL, 
            0xD5B99E7B56B6F0EBULL, 0xF1DB9812DD2D970EULL, 0xA3D525C7DA1C94EBULL, 0x94102AC96423C793ULL, 
            0x5DE98E5FB877BDCDULL, 0x1F4818A3ECDCEC01ULL, 0xD6D59D5184DADFABULL, 0x4A192B8C10D707ABULL, 
            0xF2FFD107D4682436ULL, 0x4D4509D0CBA2A895ULL, 0x9F4AA2FDE846A91CULL, 0x8088F998DAA7F8F4ULL, 
            0xD61919196E20FFE9ULL, 0xC470041D3FC8C031ULL, 0xC0626AA15FC702A0ULL, 0x5DA156BCCE59926BULL, 
            0x3D16DBE355D57E4FULL, 0x792DC9BB0D2742BBULL, 0x322B05F6B31DC4B6ULL, 0x4E070FBB7E324F6AULL, 
            0xDDD4267297422922ULL, 0x3192F1399E5FB191ULL, 0x3C360B65BA4AED4EULL, 0xB1588C4928EE349FULL
        },
        {
            0xF5B94ED42CDB8088ULL, 0x7643C8051E1A7C6BULL, 0x5E8872F5AB9DF4EDULL, 0xE51D04C6BF70D3A6ULL, 
            0x6720B2B24C45968FULL, 0xF823AEA06F88550CULL, 0x0780FBD6075340F4ULL, 0x86742CF0CEEC3213ULL, 
            0xD7798ED26D38D194ULL, 0xF09DB6E82B61CDCAULL, 0x34BA6822AA8B3766ULL, 0xD86056CE262DEEAAULL, 
            0x5C3CC848D964961EULL, 0x716CB91FA15CD72CULL, 0x2A3F7FA950BAF76FULL, 0x5F083997D1D09A2FULL, 
            0x147C063DD7DC89ABULL, 0x1296F6A737997B9BULL, 0x0CA637584C46C8FCULL, 0x90BEC3FD5138871AULL, 
            0x58DF5F98005B3CC3ULL, 0x10EA8F34655D6BF1ULL, 0xD9C55AD7C1A4BC76ULL, 0xCE8885BBD408C97EULL, 
            0x7E31BABAACF345C3ULL, 0x339D6EA344E67663ULL, 0xEB983D1DA8F13D2DULL, 0x0DCF1F94E011B21FULL, 
            0xCC95AC89130D54FEULL, 0x612F407D230807DCULL, 0x992D7EBD82E9E350ULL, 0xC90638ABE83B6CE3ULL
        },
        {
            0x5F18264C25607177ULL, 0x581EC1B4F283458BULL, 0x810FF4EA2385AD1EULL, 0xC935FB6A8B9B3B4DULL, 
            0x89D254C61D4FCBF0ULL, 0xD00562314F25722EULL, 0x441D661D9EF35FC4ULL, 0x7249EE58C8BB687BULL, 
            0x8D261D2BC25DA476ULL, 0xA0992786FD0E2C34ULL, 0xAD87A13C18C341B4ULL, 0xADF732A1E7B28B7DULL, 
            0xE51E03AF48767FA3ULL, 0x619F178242807AB0ULL, 0x7F548691CB67C9B8ULL, 0x3CD80AAD47686FB0ULL, 
            0xC1330001497FF80FULL, 0x58A46B6D1A2ED8E0ULL, 0xD53C8697580078ABULL, 0x80F92399757FDEDAULL, 
            0xBDC7C5DCE9ED95C3ULL, 0x1B5A664D5499F3CFULL, 0xA516FAAAE5A2685AULL, 0xD71BCE430EF70BF2ULL, 
            0x91B4AA5F4326ADFDULL, 0xF9ACE70246AC8AACULL, 0x57B2EFD00208952BULL, 0x0D9DB8D803246434ULL, 
            0x08E8E834B134BEBDULL, 0x9C0D287E6FEB931EULL, 0xFD3FDB3451F7A921ULL, 0x3865972233B84B05ULL
        },
        {
            0xEEDE820B206C2A0EULL, 0xA3AEC85FEE2BA106ULL, 0x8D36D11531934E08ULL, 0xDB7E71447091CB7FULL, 
            0xCB2AA1707F4CD4CAULL, 0x5F3E1398D9C69E8AULL, 0x24E0C2D693FAC210ULL, 0x4E6C8279970CEC80ULL, 
            0xE26D8633A7A786D9ULL, 0xFDA18AACCAE63CE1ULL, 0x6C166357502BF6CBULL, 0x6A07B5F281927FA8ULL, 
            0x7B91B3D706ED1AC2ULL, 0x851785EEA3446275ULL, 0x2929258FB221EE05ULL, 0x7BB2C13F0B72EA22ULL, 
            0x9A3160136BFC4D03ULL, 0x7B337FA39DD562D1ULL, 0x751E5846146FDF2DULL, 0xE7DFB046C06DF089ULL, 
            0xF9ABF69B60DAD66FULL, 0xA3642FB835E1DA94ULL, 0x692447AAF71193FBULL, 0xAEB5C088296708BBULL, 
            0x3020928F9E0F5DB9ULL, 0x3922ACC96F45352BULL, 0x6C640A781C399F7AULL, 0x57A885477919F9F7ULL, 
            0x9C0FE4D9C574B7B1ULL, 0x34107F515F6B72BDULL, 0xBCFF65EB9361CCFDULL, 0x07F1614D7A35640AULL
        },
        {
            0x39F3914C28009AE6ULL, 0x01C3E198202116D3ULL, 0x1617871C58B3B8DFULL, 0xC3B1FE4E107B196AULL, 
            0xFDD33987994D5086ULL, 0x723527A80866B97EULL, 0x6DC50CD2CA7FDCAEULL, 0xEB56D45055D3111BULL, 
            0x6F47724B00668DA5ULL, 0x65BA0BCBCA9A36FCULL, 0x717E5F4FB3E95CD4ULL, 0xCDF9C89A5A639BAFULL, 
            0x9665354F8C6569FFULL, 0xEE4EF4D7FBE00892ULL, 0x4CE531BE6724141DULL, 0x89F0B00F0A3B4E83ULL, 
            0xA988D7FCF2EA1772ULL, 0x91B3A84AB0987A23ULL, 0x04CC2BC6003C5D90ULL, 0x5F716D4A2A7ED1EEULL, 
            0x6AAAA146FB79781BULL, 0x9965DA4091D81CC3ULL, 0x543543735EAB0957ULL, 0x2999D7249FE85F3FULL, 
            0x8E9381BC37504C3FULL, 0x916DA78E85B6A0C9ULL, 0x6F68B2C2AE25FB0DULL, 0x89B3C58382C7B5A4ULL, 
            0x9F3144E52CCBE057ULL, 0xDAE579F0989C7343ULL, 0x19FAC955CA24E9EAULL, 0x13945DADD36942CCULL
        },
        {
            0xECDE3A38F2861DBAULL, 0x656970280F4DC4A4ULL, 0x817155585C13E2CFULL, 0x02FDA52DAD644B87ULL, 
            0x37F0554BF1838C8BULL, 0x6E0A22E7E4C69B48ULL, 0x44C13F9FD83C1289ULL, 0x60F5BB345671CFB1ULL, 
            0xE3023A30D26F72E3ULL, 0xDE2B2E96556B9454ULL, 0xAE56C4661F29112AULL, 0xF6738400BB8685C4ULL, 
            0xF508345B77B5B389ULL, 0x18EC3464A553687FULL, 0xDB52D55710E9C9FCULL, 0x068E12B8CA30D988ULL, 
            0x0BEA79C04A19F843ULL, 0x94AB09BB0565F4EEULL, 0xB11676C4B3C745FCULL, 0x75F2ECA4E985FF34ULL, 
            0x89A5A69CFF1BD328ULL, 0x5B01157810DA22CBULL, 0x393D2B41FC5400FDULL, 0xD6056905E9B4F81EULL, 
            0xDAC211556A9FFCFFULL, 0xA47C3FC5D16C48DFULL, 0xC71A47E3F0B7526DULL, 0xEEEEB52DA51110BBULL, 
            0x245B955133AB2594ULL, 0xC72A8FAC0DCEFBC7ULL, 0x6F0B3389AD73C670ULL, 0xE75AA45AC6A8308FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Regulus::kPhaseDConstants = {
    0x40B957798FF3E586ULL,
    0x7E4E5E007649F51AULL,
    0x29185027B5B78317ULL,
    0x40B957798FF3E586ULL,
    0x7E4E5E007649F51AULL,
    0x29185027B5B78317ULL,
    0x61ADFCA2FA95E368ULL,
    0x5B8F17D4EACC708EULL,
    0x61,
    0x6A,
    0xF7,
    0x4F,
    0xCC,
    0x04,
    0xE8,
    0x07
};

