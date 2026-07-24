#include "TwistExpander_Ankaa.hpp"
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

TwistExpander_Ankaa::TwistExpander_Ankaa()
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

void TwistExpander_Ankaa::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x8C1A05B8A9E4C789ULL; std::uint64_t aIngress = 0xBE521569BD743BFAULL; std::uint64_t aCarry = 0xEABD419281F89B31ULL;

    std::uint64_t aWandererA = 0xDBFD60014161D360ULL; std::uint64_t aWandererB = 0xEF111E7174ACE5F3ULL; std::uint64_t aWandererC = 0xFE03623E77BFCB5FULL; std::uint64_t aWandererD = 0xFC16FF8CF1A912FBULL;
    std::uint64_t aWandererE = 0xD6707D826B0C1C49ULL; std::uint64_t aWandererF = 0x9DFDC89173D2AA34ULL; std::uint64_t aWandererG = 0xAFABAE6B2641C2B0ULL; std::uint64_t aWandererH = 0x97E1E87FCA7154F4ULL;
    std::uint64_t aWandererI = 0x9D03F460202D2BB6ULL; std::uint64_t aWandererJ = 0xB916E045D14947E1ULL; std::uint64_t aWandererK = 0xDD140173DD9F60D5ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xBE8BAFE2C3339AA6ULL;
        aCarry = 0xC568F3E35B9A881DULL;
        aWandererA = 0x83401D4B31DFA8F2ULL;
        aWandererB = 0xC928033B7BE5A4F5ULL;
        aWandererC = 0xE79EC9CB50ED2D79ULL;
        aWandererD = 0xC7A38361241D04D8ULL;
        aWandererE = 0xB836E41531690577ULL;
        aWandererF = 0xA577F60067E6237AULL;
        aWandererG = 0x960DC2AF5D74F17BULL;
        aWandererH = 0xF46513AC27D11FFDULL;
        aWandererI = 0xA8BC5B64E24796C4ULL;
        aWandererJ = 0xCCE95A89ABAD544FULL;
        aWandererK = 0xB58ED848E5DA8B5AULL;
    TwistExpander_Ankaa_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Ankaa_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Ankaa::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xC8DC99FE043DB575ULL; std::uint64_t aIngress = 0x86624F0818D356A0ULL; std::uint64_t aCarry = 0xF07B7B2F6E674BE0ULL;

    std::uint64_t aWandererA = 0xAE29A195774AE745ULL; std::uint64_t aWandererB = 0xB638D5144ABE82C0ULL; std::uint64_t aWandererC = 0xE7BC9830083C3FC9ULL; std::uint64_t aWandererD = 0xFCDD2EAC855BCEEDULL;
    std::uint64_t aWandererE = 0xE3C128F78B085F96ULL; std::uint64_t aWandererF = 0xECB5EC29B5576BD4ULL; std::uint64_t aWandererG = 0x88649F4472936336ULL; std::uint64_t aWandererH = 0x90B478D8A9677B98ULL;
    std::uint64_t aWandererI = 0x9124A193CC933D12ULL; std::uint64_t aWandererJ = 0xA15551E8F0F95F47ULL; std::uint64_t aWandererK = 0xEBC454E30EB9428DULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x97A7073281F810E4ULL;
        aCarry = 0xCB4D1C0125D7C2DCULL;
        aWandererA = 0xD401994B4A813195ULL;
        aWandererB = 0x983BB7290D628DDEULL;
        aWandererC = 0x8C5C54267EB57F57ULL;
        aWandererD = 0xF3D9A2B0F653116EULL;
        aWandererE = 0xE81D4D0ECF007BDFULL;
        aWandererF = 0xF08477D7CF3FA4C1ULL;
        aWandererG = 0x86B2F0438B8FA1F1ULL;
        aWandererH = 0xB8339F0280F0CFD2ULL;
        aWandererI = 0x99ECF1F52352233EULL;
        aWandererJ = 0xE643B8EAA436DB88ULL;
        aWandererK = 0x95517C5007CAC53CULL;
    TwistExpander_Ankaa_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Ankaa_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Ankaa::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF16B5D11928F0FFFULL;
    std::uint64_t aIngress = 0x83378ADDF89A2375ULL;
    std::uint64_t aCarry = 0xBDEFA2E7C689AD4DULL;

    std::uint64_t aWandererA = 0x9498804F70C7F438ULL;
    std::uint64_t aWandererB = 0x938610AD108FA4DBULL;
    std::uint64_t aWandererC = 0xE8E85CF8784F0ECBULL;
    std::uint64_t aWandererD = 0xDDBD4139E7878D7CULL;
    std::uint64_t aWandererE = 0xC51D352D1BF4C8C9ULL;
    std::uint64_t aWandererF = 0xB4F830E72DD0C9A9ULL;
    std::uint64_t aWandererG = 0x9782514131076CA1ULL;
    std::uint64_t aWandererH = 0xE5636428089ACD68ULL;
    std::uint64_t aWandererI = 0xC3AE6200E4C8AF2DULL;
    std::uint64_t aWandererJ = 0xFD31710ED6745FEDULL;
    std::uint64_t aWandererK = 0x90C9A205665F0A9EULL;

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
    TwistExpander_Ankaa_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::Seed_C(pWorkSpace,
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
    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgD;
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
    TwistExpander_Ankaa_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Ankaa_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Ankaa_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Ankaa_Arx::GROW_B(pWorkSpace,
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

// SmartSquash candidate 8 of 33
// Exploration cases: 100000000
// Nearest-family diversity: 953 / 1088 (87.59%)
// Total distance from earlier candidates: 6736
void TwistExpander_Ankaa::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    static_assert((S_BLOCK / W_KEY) == 16, "SquashInvestToKeyBoxes expects 16 invest fragments.");
    static_assert(H_KEY == 8, "SquashInvestToKeyBoxes expects 8 key rows per box.");
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 7U), *aFragmentB = aIceLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 13U), *aFragmentD = aIceLaneD + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1069U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1787U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1415U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1271U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 2U), *aFragmentB = aIceLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 5U), *aFragmentD = aIceLaneD + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 2023U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 327U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 686U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 143U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 0U), *aFragmentB = aIceLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 15U), *aFragmentD = aIceLaneD + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 809U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 831U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 423U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 921U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 6U), *aFragmentB = aIceLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 0U), *aFragmentD = aIceLaneD + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1827U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1179U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1145U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 893U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 15U), *aFragmentB = aIceLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 4U), *aFragmentD = aIceLaneD + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 773U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1939U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1052U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1891U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 14U), *aFragmentB = aIceLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 9U), *aFragmentD = aIceLaneD + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1516U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 867U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1217U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1186U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 9U), *aFragmentB = aIceLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 1U), *aFragmentD = aIceLaneD + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 940U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1785U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 397U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1543U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 3U), *aFragmentB = aIceLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 7U), *aFragmentD = aIceLaneD + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 911U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1318U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 509U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1601U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 13U), *aFragmentB = aIceLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 10U), *aFragmentD = aIceLaneD + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1166U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1702U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 193U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1306U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 12U), *aFragmentB = aIceLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 6U), *aFragmentD = aIceLaneD + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1127U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 408U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 480U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 463U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 8U), *aFragmentB = aIceLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 3U), *aFragmentD = aIceLaneD + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1471U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 474U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 803U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1701U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 11U), *aFragmentB = aIceLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 2U), *aFragmentD = aIceLaneD + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 10U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1575U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 203U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1007U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 1U), *aFragmentB = aIceLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 14U), *aFragmentD = aIceLaneD + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1955U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1075U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 790U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 943U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 5U), *aFragmentB = aIceLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 11U), *aFragmentD = aIceLaneD + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1536U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1836U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 353U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1779U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 10U), *aFragmentB = aIceLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 8U), *aFragmentD = aIceLaneD + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 724U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1741U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1100U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1367U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 4U), *aFragmentB = aIceLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 12U), *aFragmentD = aIceLaneD + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 597U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1938U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 609U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1218U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Ankaa::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE1065D1A94E0A29BULL; std::uint64_t aIngress = 0xB46FA7E11DB2893EULL; std::uint64_t aCarry = 0x809B4B4F0ABA67BAULL;

    std::uint64_t aWandererA = 0xADB515710BB2BEC9ULL; std::uint64_t aWandererB = 0xD9A5CAD1AE7748E9ULL; std::uint64_t aWandererC = 0xE2B63A916C127E18ULL; std::uint64_t aWandererD = 0xB652D963997B2F33ULL;
    std::uint64_t aWandererE = 0x9717DCF3F0615FEFULL; std::uint64_t aWandererF = 0xDE0FF9D69EA4B3ECULL; std::uint64_t aWandererG = 0xF6A4551C317E63E9ULL; std::uint64_t aWandererH = 0xCB33BFB61D325589ULL;
    std::uint64_t aWandererI = 0x8C38A765DE683221ULL; std::uint64_t aWandererJ = 0xD19CB68D6BCFAD83ULL; std::uint64_t aWandererK = 0xBB2ACCC16EFF691DULL;

    // [seed]
        aPrevious = 0xDF836AE961FEE513ULL;
        aCarry = 0xBF46E41398C59800ULL;
        aWandererA = 0xD9315D395AC7BB87ULL;
        aWandererB = 0xCB3E02B7987D3FF1ULL;
        aWandererC = 0xA4CDF1E95AB62E2EULL;
        aWandererD = 0x92DFE11BC56ADD69ULL;
        aWandererE = 0xA03E68E2E32A837BULL;
        aWandererF = 0xB48B436423802E41ULL;
        aWandererG = 0xA577EA5426F8AA8FULL;
        aWandererH = 0xB49914010CCF04AFULL;
        aWandererI = 0xE3AC266AF59DE180ULL;
        aWandererJ = 0xFE880C8C84BD468DULL;
        aWandererK = 0xC372D483536FFD97ULL;
    TwistExpander_Ankaa_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Ankaa_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Ankaa_Arx::Twist_E(pWorkSpace,
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
    TwistExpander_Ankaa_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Ankaa_Arx::GROW_B(pWorkSpace,
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

// GrowA candidate 8 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 3941; nearest pair: 504 / 674
void TwistExpander_Ankaa::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6047U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3710U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7726U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 751U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
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
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5355U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3446U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 438U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3972U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5729U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2876U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2981U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 210U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 728U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4201U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2182U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6326U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 40U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1325U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1936U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1226U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1267U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2035U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1978U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1757U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1678U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 916U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 724U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 601U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 168U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 635U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1784U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 712U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1748U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1606U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 689U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 2032U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
}

// GrowB candidate 8 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 3941; nearest pair: 518 / 674
void TwistExpander_Ankaa::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1020U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5315U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4780U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4948U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7096U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3184U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2017U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 617U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4682U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5689U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 234U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2510U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6297U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4036U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7017U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7960U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 48U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1047U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1236U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1235U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 158U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 261U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1132U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1367U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1191U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 347U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2035U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1039U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 49U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 13U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1755U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 583U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 211U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 669U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 876U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 766U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
}

const TwistDomainSaltSet TwistExpander_Ankaa::kPhaseASalts = {
    {
        {
            0xE3490177608E8CD8ULL, 0x67394CF21039699BULL, 0xA5A78A0DA84E6DEBULL, 0x8FAA03B3ECCD2E9BULL, 
            0xC6DF8B302F65FCA4ULL, 0xE6F1DF19069F992FULL, 0x1D26163BB2719149ULL, 0xBF2F0DE0F1D7B994ULL, 
            0x6C92B3F90E9D05DCULL, 0x086029089733FDFDULL, 0x5261321486B82383ULL, 0x29A0234388655D77ULL, 
            0x093E811DAE0915F1ULL, 0x6AE754990DF35091ULL, 0x2307815FC23FE3ADULL, 0xE077B36078E2156AULL, 
            0xB730C9AC27429F8CULL, 0x46F7FA1F3F3BBE27ULL, 0x3C1AAA634858FF04ULL, 0x5E08DA4FC6F8CEA9ULL, 
            0x1133ABD4225E3A77ULL, 0xFDF5AB8B51292A7BULL, 0x8740618A47AAD2F1ULL, 0x479DADAEBA9749E6ULL, 
            0xD1B2A071443EC3DBULL, 0x50BEC449BC150472ULL, 0xF8F7B5AE63AE01D3ULL, 0x7A8CEB1CB6D24386ULL, 
            0x3CB73A082DEC5A5EULL, 0x3DB6561FA50F8A88ULL, 0xFBBBBEBA8F63F7A8ULL, 0x67855BF7DD82F59FULL
        },
        {
            0x1E03DBF339062A33ULL, 0x822147BDE5176ABFULL, 0x0CFBBD10583A0159ULL, 0x65F7B41281094413ULL, 
            0x289118910D93636CULL, 0xA870B6E586F8C406ULL, 0x683B3ADB45C12392ULL, 0xBE81E9F1C00205B4ULL, 
            0x518558DEAA20AE07ULL, 0x8FC9C019D20B7DD4ULL, 0x4B389C67FDDE6BACULL, 0x334DA5D4DD00B5D3ULL, 
            0x2672961BE1909B00ULL, 0xB52BEFC770639BA6ULL, 0x2348313B3713ADC6ULL, 0x247A18216269D4DCULL, 
            0x78621277A1C7DD71ULL, 0xE1048EEA61C258F1ULL, 0x297A326AE04070E5ULL, 0x5FFF5F767411D65BULL, 
            0x12742D6D93424EABULL, 0xC66E5299297127CCULL, 0x6D239C2284E48A50ULL, 0xE3E05747DF159763ULL, 
            0xCBD38112215E9A0EULL, 0xDDC5D6D123D01CF6ULL, 0x8E639DFCD36FB7CAULL, 0x4F01E539F5CB1AB4ULL, 
            0x7B15C597F114C11BULL, 0x99739BF0687A9902ULL, 0xD5C415A38F26DC9EULL, 0xDFB5EC2180FEFB74ULL
        },
        {
            0xD8027C7E0C34AA00ULL, 0x6359ACB6222A9285ULL, 0xE2DF8C5AFC7A49D4ULL, 0xA8D20807426B6F9FULL, 
            0xDD128F54C167B6E7ULL, 0xD6CCF79961AB03EAULL, 0x0ED95F76EC6D1B2EULL, 0x215CBF169E0A5A80ULL, 
            0x4C9E65522BA047D5ULL, 0x4016F8BDFB7590BAULL, 0xE3F2166D5CD7B5F3ULL, 0xC3B40E22D08D5804ULL, 
            0xE545DC2153BFCAD7ULL, 0x1A2ADCB7F9CD96D2ULL, 0xA96D3521E3AE3618ULL, 0xF141BAA6ECCB30B0ULL, 
            0x4105046332311DB0ULL, 0x5B3191C5CF2EA0E8ULL, 0x75F1707FEF7E7B74ULL, 0x6A00049E1625CB41ULL, 
            0xCAEEC389AB08E1FAULL, 0x6040FC45F8FB9F28ULL, 0xC322E8839C45FFEAULL, 0xE978C0DB7E460824ULL, 
            0xF26A632F18225AE2ULL, 0xA24A72EA82FB14C7ULL, 0x56E1965EA9E33389ULL, 0xFC556CB0FAAFCD9FULL, 
            0x041ACF1E85C8DE6AULL, 0xE91937AE89899983ULL, 0x7DD01FA79298407CULL, 0xA64AC5F47D7D3A30ULL
        },
        {
            0x7DF6B38FE8ED350DULL, 0xC297C57F280711B5ULL, 0x3B16FA1F85AA440EULL, 0x34543AC57B07235AULL, 
            0x3DF29D163434B6CEULL, 0xC2B5D2D941C462CBULL, 0x6FE154E73D333DB9ULL, 0x873C60EE6F39B0F5ULL, 
            0xE1331972421A64EFULL, 0x91FFFA05571F44DCULL, 0x015776A348802B18ULL, 0xDD0B761821DFE5FDULL, 
            0xB5FDDC710CD03B3EULL, 0x8570F73B4503499CULL, 0xDA85F1546074D9F9ULL, 0x35CD328FAE951C85ULL, 
            0x68BB30C8B90184ABULL, 0xDB1BE13B5B1A16F1ULL, 0xE184F6B24517F2C1ULL, 0x8A3D6605424E0D50ULL, 
            0x2858D605F5DC72F2ULL, 0xF453CA32BB338023ULL, 0x76140C9E8FDD884DULL, 0x762CA6117C30407AULL, 
            0x2E293D4A910918ABULL, 0xF176A38D7B94CE66ULL, 0x7FF10E5516B5BCD4ULL, 0x966D9C6530A17D3DULL, 
            0xEB55F56795CB2CDDULL, 0x89B62BB7D676471AULL, 0x7D5734B76EB785A2ULL, 0x241B91F787D3A977ULL
        },
        {
            0xA2BF23E8BA18D4C8ULL, 0x3D34950E47D9415BULL, 0x24787B567E58EB08ULL, 0xD5D96190212BB2D3ULL, 
            0x039B1AC8074C5C2AULL, 0x0B902F950FB20238ULL, 0xA91A5DC98689D844ULL, 0x7F087E4FDD124B5AULL, 
            0xC7A5338255928A22ULL, 0xB5DD191699B05F89ULL, 0x7ACC6BD1D4C04715ULL, 0x795A79345CF3E5E8ULL, 
            0xA7EB064DC2799058ULL, 0x2B667E2977E560ACULL, 0xC97BFA2D91438A0DULL, 0xC1B17EB4D5BB5D39ULL, 
            0x4DAB521D77739A3BULL, 0x3E25133CD812491CULL, 0x589497CFC45AADE1ULL, 0xE3857E908EDF5485ULL, 
            0xDF1C47173A60246BULL, 0x02B9F9E71032F98EULL, 0x353CD41B1A16221DULL, 0xF7F5F49EA5004F65ULL, 
            0x95038B234828E489ULL, 0x571264DF73CE87A0ULL, 0xA8AE3763D297EF97ULL, 0x0E94970847ED9990ULL, 
            0x63F6F7FE4AC09163ULL, 0xCB5DE294693D88CBULL, 0x2917C1FE34F04D47ULL, 0x84C24C397799297AULL
        },
        {
            0xB856B4CB09FB3FB7ULL, 0x11B1DAB9787942ACULL, 0x3990F5CCF5FF445AULL, 0x503B664F4F0FA94CULL, 
            0xB94C523C1EE6B6E7ULL, 0x9222001E46F74D9FULL, 0x4FD3FA211B15267CULL, 0x5C504CE53E9D0287ULL, 
            0x88FF75466EB2BB6FULL, 0xDF6C807983A03362ULL, 0x8AC5C3C9D7CFA042ULL, 0x272F1D86CC51CA09ULL, 
            0xA0A4D8A4C9E1800BULL, 0xB1B5F43AFF855443ULL, 0xF16074DECF571EFEULL, 0xB66A00A1E5633BC5ULL, 
            0x0970934F0736CBCBULL, 0xE09F529C6A91763BULL, 0xC2CF0439EBB09A13ULL, 0xB7774579100204AFULL, 
            0x96CD9D417A188573ULL, 0x2F7F0DDB3285F09DULL, 0xEDD85696D112D1A2ULL, 0x104DDDBE8F14A2C2ULL, 
            0xA188823A7B888749ULL, 0x012B0DC5A24EB03CULL, 0x395C1385685B5B95ULL, 0x660924AD7082B705ULL, 
            0xD7C31AE85BCF646EULL, 0x8E559A0E0D7000CFULL, 0xD4411E882DA8652CULL, 0x9BE23585E1D0AEA4ULL
        }
    },
    {
        {
            0x29615FAA3AD2DAEEULL, 0x06E6E639FB04FEBAULL, 0xBEA18BE72B2871EAULL, 0xD337F4C92048C6D5ULL, 
            0x732F9BBEB7004AFBULL, 0x53F4F92763432AA0ULL, 0xAE3436CDE9C9FC3CULL, 0x0E277913DF0F3940ULL, 
            0x73735D0CDC289542ULL, 0x5A9A482DD23A6BEBULL, 0xA1081ED1A07A16CCULL, 0xF669893AA785BE39ULL, 
            0xBE0D9277CE7FF2EFULL, 0xAB670E79330298B1ULL, 0x384462E91CF51152ULL, 0xD35E910428CB6305ULL, 
            0x84C0BFF2134CB247ULL, 0x8BE39B1455C6C76BULL, 0x43269309A1292AB0ULL, 0x2CFE54E2B6F797ABULL, 
            0x904F94210CE6E3B3ULL, 0x4DC4A4801E434F84ULL, 0xB1D8F7103543994DULL, 0xE1176AD85544710AULL, 
            0x571E4D159EB7FCDCULL, 0x0625033489303ACAULL, 0x4251366B62F48F13ULL, 0x4BB9DFCD5ECA8AA5ULL, 
            0x36070B912EF650A0ULL, 0x01AE3EBD71B7EE55ULL, 0x486EA998EB83DDD6ULL, 0x1F4B9664B6160E14ULL
        },
        {
            0x5CCC843A146764CBULL, 0x0F94163308708D08ULL, 0x072010672E8B1A9AULL, 0x94CC2F89F7B01870ULL, 
            0x1A1C13205C779981ULL, 0x1C1C5A41F1C715EBULL, 0x1FE0C53463F81946ULL, 0x13BD8649FE3DCAB3ULL, 
            0x51A91F902C91887BULL, 0x1566952CFD87B374ULL, 0x9502EF44116DF1B0ULL, 0x09BCADFC2EC4738CULL, 
            0xD61FBA63D717B535ULL, 0x2BA24C8E6ECCF96AULL, 0x83A9CA25537F4882ULL, 0x998595139D1101F0ULL, 
            0x8D4B7B94D2EB4FCDULL, 0x12B8A3B3083B0A22ULL, 0x5A9BC9A92123F9B4ULL, 0x16AAF7CB90C6A89DULL, 
            0x3CD19FBE2CE61B47ULL, 0xCBC509DA3736783AULL, 0x04944F44E35CCD71ULL, 0x4E34939C22FD205DULL, 
            0xD93B6AEDE3F0FF41ULL, 0xCB0F020B5FA6C989ULL, 0x7EF372414C54DA01ULL, 0x83E0088DB95B5C04ULL, 
            0x10447C42C709A1F3ULL, 0xD371C43B55BC261FULL, 0x9D1911D82A35D132ULL, 0xE0C6F47569F5C4F6ULL
        },
        {
            0xD35EDA1B506456F8ULL, 0x5393582A35AD0A57ULL, 0x583F3F8744963E0DULL, 0xEED4F9AA6763CAAAULL, 
            0xC03ADF7183079249ULL, 0x1DF4ECBFE8AA3278ULL, 0x8BADE495752D8C45ULL, 0xA8187717BF777DD6ULL, 
            0xAB68DBA3E71FBE6DULL, 0xF37CEE91E39936CAULL, 0x8CCC05AB41DDFE12ULL, 0xA18F963FA9FBDDB5ULL, 
            0x295E72AE1646E7F1ULL, 0x81CBDC5B27D298B9ULL, 0x1B725CD9B3A7B53BULL, 0x925C5F2502C8A5B8ULL, 
            0xC3D5F49B808685D0ULL, 0xA714F27833BAF19CULL, 0xA976207F5CC8A374ULL, 0x8497C5AC434A3EB8ULL, 
            0xA9F5668E45902ECCULL, 0x1B5859E64D09A54EULL, 0xD454BE109DAE732AULL, 0x1F0BE4C76DDA44E1ULL, 
            0x03A16764B59333DDULL, 0x85DE3939A28FC853ULL, 0xA2DA007F466A29AEULL, 0x8D955484DE596599ULL, 
            0x621BC2EDD735A8EEULL, 0xFD6AA15ACDF59A65ULL, 0x8387EF2BFC505623ULL, 0x0B56B10F24FF2BB2ULL
        },
        {
            0xEBF544125D2E2632ULL, 0xFCEC135FB8A143C0ULL, 0xEBA839244A4F3E1AULL, 0xB7802C9DAABECA3AULL, 
            0x50C065660F20692CULL, 0xE5B341D5BE9ECA9CULL, 0xA547A360F78A547BULL, 0x24D91747220DB7F0ULL, 
            0xC70E791663028F4AULL, 0xB1F6C5AB46F662C7ULL, 0x6B19AFA17E88C194ULL, 0x5B2651B5BC7B0423ULL, 
            0x2AD0B25EB40F2E50ULL, 0xECA3ADF491EBB57DULL, 0x90F6E75785645A03ULL, 0x9A6C07529100C095ULL, 
            0x3D1CBE58A6368F05ULL, 0xA78503E8AB9450F3ULL, 0x2BE7F71CCCD93C41ULL, 0x877120358A2D0D29ULL, 
            0x5EEFAA5372CE5625ULL, 0x7E6C715F5D89D455ULL, 0xAF98CF8A6AFD3675ULL, 0xAB14E7617660FCC2ULL, 
            0x9148743E72F12E6DULL, 0xDAB401F5323EA56AULL, 0xB9589CA3E88931F0ULL, 0xB49C6644312931D8ULL, 
            0xDF21292DAA9630F9ULL, 0x5F3BAB60F2BD4516ULL, 0x2B11BBC31133065CULL, 0x5A87F814397014E5ULL
        },
        {
            0xFEAB28E1FBA1B65CULL, 0x29801F4A9A586194ULL, 0x9FF5CF2AF7A09153ULL, 0x5131E34CAE6409B0ULL, 
            0x858B85049DF92CE2ULL, 0x4DEF51F35C255C9EULL, 0x64DBD937665E30BEULL, 0x4505EB6E0A8B5B0AULL, 
            0xCA3256B2A8E521B1ULL, 0x8BB9F92E07156073ULL, 0x45A19489A7C01527ULL, 0x90E08898FC6E7931ULL, 
            0xD4A538FD0E87584EULL, 0xE8AB1731E142CD2EULL, 0x95E1CD3F6E3814F1ULL, 0x074B34B37D814CB1ULL, 
            0x480D370B7516D6F7ULL, 0xF49AC660AC9976CDULL, 0x441CE710FBE6AFF8ULL, 0xD0FD8172DC3A5787ULL, 
            0x75F7BEAE6FDDE742ULL, 0x92F87AC93656424BULL, 0x9E845FF7F4084BA2ULL, 0x5DC56361C1E877BDULL, 
            0x177C2380F58C0CB2ULL, 0xDC2BF83841C879D1ULL, 0xC30FA589F2598AF4ULL, 0x57BC77AB09E12166ULL, 
            0xDCA539BC3D7AF3ECULL, 0x4282023EE5FCE315ULL, 0xF6CB7F2589503507ULL, 0xED3D432F132875F4ULL
        },
        {
            0x6F35E36A5E4027E7ULL, 0xDDCBD5E08BA48E25ULL, 0x3BE7A4A87FEF02C8ULL, 0xAAFE145B4609227CULL, 
            0xBF5BD52C0DC84442ULL, 0x2EC3079E0BE436ECULL, 0xCC9F9CC3C170D00AULL, 0x5D6F5DF50580D1D6ULL, 
            0x7DF68C6F8C1FC3FAULL, 0xE7C911A716D7C28BULL, 0x492AA683471DD375ULL, 0xD879AE8BCE503955ULL, 
            0x36E765CA362D0C41ULL, 0x3C48FA32F7F9552BULL, 0x11D43E70BB40269BULL, 0xE71FB66D74304E93ULL, 
            0xACC980C87B4EDFAFULL, 0x5CEA3DDB2EC5F560ULL, 0x1247518A2C6B7273ULL, 0xC85852A8E46CF98FULL, 
            0x9476178944E51EB7ULL, 0xCAB616AD57EC71EFULL, 0x3EF0D9B7328BB8A4ULL, 0x2E196A09F4F5F46EULL, 
            0x7331599D4B010373ULL, 0x0CC7F9B44C0292B4ULL, 0x6AEF8C5EE379654EULL, 0x7891FD35690D067DULL, 
            0x0D346BCDAD7088BDULL, 0xBE326434390FC2C8ULL, 0x58098E00842B8553ULL, 0xAB642C4FDDC92BA1ULL
        }
    },
    {
        {
            0xC5AFDF170682DEDDULL, 0x0E716E1F8A1F35BDULL, 0x790B60C082740EEFULL, 0x701A4DC24E7029B1ULL, 
            0x6EC0F6A94BB9293EULL, 0xB4AF7F86ABE436B9ULL, 0x5713965C1F9DCD8DULL, 0x0F6FEC96E9B58E1EULL, 
            0x311405DDD7E07BA2ULL, 0xDDF818E1E29A31FCULL, 0xF425CDA199771AB4ULL, 0xEE297CF56280DCEDULL, 
            0x3D3B00EDC06CFE8EULL, 0xAFB497BA5A7172F1ULL, 0xA360214BF0B7D40FULL, 0x6D6D3DAC04D86698ULL, 
            0x00DE7DAA8A455622ULL, 0xBA8B1269716AAD4EULL, 0xC7AD368A13947043ULL, 0x532F4BB098324DAAULL, 
            0x7B0D5F0865BF9986ULL, 0xAB3714BCAD0D5678ULL, 0x51A1ACB2AF96F0CFULL, 0x2D2EA91A4CF2A29AULL, 
            0x1E07CED3A306159BULL, 0x2F3F2FA7619D15BDULL, 0x1738EC1E52C01E52ULL, 0xC1E3C6945BBC3699ULL, 
            0xFFC233F4F3DC8636ULL, 0x8FFCEDA9E02CE981ULL, 0x480D373D0C1290D9ULL, 0xA555BE31E63673F0ULL
        },
        {
            0xE9BBC7CD8B5A8751ULL, 0x8CC40F4C4C44CBC0ULL, 0x58D1E679E1B1E1C2ULL, 0xB03B86F337990BB9ULL, 
            0x4DAB1D6C0AF9EF4FULL, 0xE1FEA029054D3BD7ULL, 0x7070ED4D113D0EA3ULL, 0xE92CD20BD0478E7BULL, 
            0x5AE5B5931FD88C55ULL, 0xBD10A86C2090EF81ULL, 0xD381F53092EDAD8EULL, 0xBEF643CC0332426EULL, 
            0x332DCDBEF6DABE30ULL, 0xC764731209E1434AULL, 0xA0B6CD5701DCCABEULL, 0x36B703981B0563A0ULL, 
            0x7051E2929CB90EA1ULL, 0x7A845FC135951550ULL, 0x34D4298604684607ULL, 0xF0A4788B6AF341BDULL, 
            0x19C05D95E84778D9ULL, 0x46858B349F89C6F5ULL, 0xAE98AEDAAB57F18AULL, 0x5AB04A802517870EULL, 
            0xD0E3191057F37E1FULL, 0xB18D3FC4DFDED190ULL, 0xEB79B92169993A80ULL, 0x5BD13408940E8D28ULL, 
            0x4FB513054ADF0429ULL, 0x9167182FC5A05B55ULL, 0xF28A03C03436ABD1ULL, 0x9EDC007E6C698AA3ULL
        },
        {
            0x68C5EED1AFE0079BULL, 0x2DD878C67AE7C565ULL, 0x651CD4F965772F1BULL, 0x66BDD275E777AAE9ULL, 
            0xF5C81836BF88BEA5ULL, 0x8687D550EFD91619ULL, 0x18A171F4F2C5DD65ULL, 0x3E1CEEDCFE5DE6DDULL, 
            0x346EF6C2E399BFFAULL, 0x96C9FFB9FFFA3DADULL, 0x572126FDB3667430ULL, 0xFA6BBE898C3C4EACULL, 
            0x56D33C80A7CA1750ULL, 0x6B1563AA43F7CAE6ULL, 0x6249FF69D0D4EE24ULL, 0x8354D8356382319BULL, 
            0xA6287531DCDA52EEULL, 0x577025415B1721F4ULL, 0x26F7EE7D08D38B5BULL, 0xFAC30ABB46517498ULL, 
            0x27B932EDAE836A22ULL, 0xA9925681E5A14B1DULL, 0x67646D2A97CF6C1DULL, 0x46E7EFA2475CE11CULL, 
            0x10D48138D0BEAF5CULL, 0x8B4CB0BE9781C66BULL, 0x9434BED7991EC6B9ULL, 0xBAE160EC7002AF12ULL, 
            0x4A5D67A8A0A1DCC0ULL, 0xA6E8764BEDB64091ULL, 0xF962DA06DC7F8478ULL, 0xEB731A62CEB26536ULL
        },
        {
            0xD67BCCFEB7A17125ULL, 0x80BD2FFE012256B0ULL, 0xCE9432A1F80849D5ULL, 0x790B7D75F975D311ULL, 
            0x4182F6504DF1097BULL, 0xA6187C2F3257734AULL, 0xDE30F37429417ED9ULL, 0x7093BA15B26F1ADCULL, 
            0x52B6C0E99295F293ULL, 0xF0A08C7B59C97B7BULL, 0x2D4DDB68D8D47C79ULL, 0x58730CC8BF408B09ULL, 
            0x986F33D280833DBEULL, 0x1015484E32952775ULL, 0x5980531D0C0C6CF8ULL, 0x798523ABDE757269ULL, 
            0x7383E30BC3610530ULL, 0x0E155A37986890CAULL, 0xFB5D2EC46C04DA57ULL, 0xFCD6ED603A5B94ECULL, 
            0xEF17E6187FB452C6ULL, 0x2082192DFC504BF0ULL, 0x723CCEBD06109019ULL, 0xF6055AEC258B74EAULL, 
            0x7566E668EFE4DC6FULL, 0x462C1D1C71B245D7ULL, 0xDF717426A70171DBULL, 0x36CEDE21EF185406ULL, 
            0x3D66DDF35A16981AULL, 0xAC2B0C321672DEB5ULL, 0x284F1191AD72C0C2ULL, 0xEBD9325F6EFB0C1CULL
        },
        {
            0x5C649E65B51B9D8DULL, 0xEF3E6E787301D4E8ULL, 0xF0B4B4C806F34A43ULL, 0x379D5E44EF2864D4ULL, 
            0x510719C5540E57A7ULL, 0xB90E93D14D66B26EULL, 0xA5FFB15F8B2048E0ULL, 0xDD95024248D841BFULL, 
            0xF28C41F717C26C66ULL, 0x105435A4888CE934ULL, 0x1B6F6E14D8F121C2ULL, 0xEC775947499D67F2ULL, 
            0x2FA1979DB5483DD3ULL, 0x276A79F1E8DC176CULL, 0xD34C6F0B9EDD577EULL, 0xA519C2C7D00A040AULL, 
            0x5E98917B94AED77CULL, 0xD6667F9E9F3FEBEBULL, 0x68C521F84E441952ULL, 0x6C79A98766E60048ULL, 
            0xD64093EC98E0A11FULL, 0xADB15573D7AB3080ULL, 0x70F233AF7B5ACD68ULL, 0xF4D46B4E7BAD96A1ULL, 
            0xC5AD199A67E8A9C9ULL, 0xC4C47205D7B28574ULL, 0xDF59CA730F8E934EULL, 0x84E69202AB0D4A79ULL, 
            0x885DE528E3A11324ULL, 0x5898D744C7943794ULL, 0xF35EA9F86420C471ULL, 0x3E824641D59AD48FULL
        },
        {
            0xE918F279FCE53480ULL, 0x287527D478D697AFULL, 0x9BD454B3567F0C19ULL, 0x8DA8E8619AA0DE9BULL, 
            0x27D2B76190438E22ULL, 0x52A82FF8A6A93234ULL, 0x97D53CA8CA5409D1ULL, 0x6105270544DD707EULL, 
            0x074BD9E24F937939ULL, 0x4722B4345987C3F7ULL, 0x95122FE7621FA7A5ULL, 0x0912AE036DFFE69EULL, 
            0xC7F4730AE61DFE52ULL, 0x6ADC74DBD03ACC56ULL, 0x85D0F51993CBA30FULL, 0x263385C827B539E9ULL, 
            0x02688F135B5513EFULL, 0xAA727FABEF477336ULL, 0x8122C81067918105ULL, 0x3EF25E4BB0FAC094ULL, 
            0xAB5E5E14553FCDD6ULL, 0xB1E322CECEB720ABULL, 0x67AB0235CFC0FD59ULL, 0x3DE0CA861FF9E73EULL, 
            0xFE333A8662F77C36ULL, 0xDD92C6158C3DA31DULL, 0xD632D9C09974E29BULL, 0xB8D614E5923F0549ULL, 
            0xFB8CC97FF1C86ADEULL, 0x7FD44FE312F22659ULL, 0x11A496B8332AB39AULL, 0xF5158B00F332846FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Ankaa::kPhaseAConstants = {
    0x744CD8086056F0C5ULL,
    0x5EC178EAA776B0FCULL,
    0xCBDBA7E71F03EDD2ULL,
    0x744CD8086056F0C5ULL,
    0x5EC178EAA776B0FCULL,
    0xCBDBA7E71F03EDD2ULL,
    0xCB862A12A4E89579ULL,
    0xC901F29893AB29F5ULL,
    0x39,
    0x92,
    0x6F,
    0x33,
    0xE0,
    0x82,
    0xA0,
    0xA0
};

const TwistDomainSaltSet TwistExpander_Ankaa::kPhaseBSalts = {
    {
        {
            0xAA9F9E3A3425335DULL, 0x03E7B57A30B3A13EULL, 0xA6C8CF42A933A4CCULL, 0x6843FADD5CE7916DULL, 
            0x668AFD44EA52E013ULL, 0x33F3ED51460303AEULL, 0xAFBA7529F12DCAB9ULL, 0x09E658214E1F23EEULL, 
            0xE605B76EB58F0BB9ULL, 0x904B16D1A4D01FD8ULL, 0xD92034D8E6C80385ULL, 0xC84E90337AC8D990ULL, 
            0x0AF21F458D1119AFULL, 0x089ECB36C0F33837ULL, 0x1DB85027665CC3E6ULL, 0xC32588E815ECB54EULL, 
            0xCFE5A5DF9CA7371EULL, 0xA74A8D30B50A964EULL, 0x027EA911C73B757AULL, 0x7E5CB550DA34B7DAULL, 
            0x2E27BD27D51753ABULL, 0xEE80EBF428E3B60FULL, 0xB80031CB6CC7ECD1ULL, 0x171EC6EE4CD4CE0BULL, 
            0x16E0BADBC5F5E2F2ULL, 0xD38BD9288DA1A3A0ULL, 0x9C7002399451D8BAULL, 0x161CCE4E537E67ACULL, 
            0x01142936BFE85528ULL, 0x50BF6ADC50BAA867ULL, 0x97664999E47E4043ULL, 0xEEB22B90CC7CD05EULL
        },
        {
            0xECAD1659340886BBULL, 0x0E1420E7D412A766ULL, 0x70B83CD757A2ECB9ULL, 0xB4806B99328000EFULL, 
            0x71DEEFFBD732081BULL, 0x07BA59817B31C3B3ULL, 0x17C173366C1B02FAULL, 0xC5903908FC66BE53ULL, 
            0xD232E8D199452EB3ULL, 0xD1FF3501486A2C0DULL, 0x4886E36D1A7CDEC7ULL, 0xF37F0DD9ED7ACD96ULL, 
            0xBE93FFA91D222810ULL, 0x5535D6ED1363F6B7ULL, 0x9D904F9D83196E9EULL, 0xB139D7EAB65567FCULL, 
            0xC7838D5521CAC7E8ULL, 0x3B8B949324C3FF9BULL, 0xDF576996D3DAE611ULL, 0x3323FDB46013979BULL, 
            0x1643A87C152FA301ULL, 0x21CCC190741EDB8EULL, 0x27F1D3BD244208A3ULL, 0x17CA2F6CCB8B9267ULL, 
            0xDC2A1E61033516EBULL, 0xF1D700ACA6B56881ULL, 0xD831D2A717F8318AULL, 0xBA6A8FCDFB7E36F3ULL, 
            0x6BA3AA4104A29A2BULL, 0x6545FD455D7E21BAULL, 0xA48A7BB080F360DEULL, 0xC7D7A485BEA29666ULL
        },
        {
            0x09030B26FEB8F26FULL, 0x411A094986BF46F2ULL, 0xDCED5B72436BDA79ULL, 0x60B4AEF12E354686ULL, 
            0xC6C56F205132ED93ULL, 0x796D80316E3A9BA7ULL, 0x26BD8170A385A585ULL, 0xAC8064B523D204F1ULL, 
            0x3F54300294CCC24EULL, 0x00BE1D4EABC1084CULL, 0xD7169D487FC08CE2ULL, 0x55E9EF358BB76752ULL, 
            0x8400146DA1EFD261ULL, 0x86638BA740FF6445ULL, 0x520E73671BBCC950ULL, 0x144338C10A382A35ULL, 
            0x5DC5079D909A97EDULL, 0x4C56C87AF6FC46ABULL, 0x71F9AB9D6F4A340FULL, 0x243AC75A078CFA26ULL, 
            0x12D3A9727B65BA8BULL, 0x9318FBC0C3FAF871ULL, 0x4C6FE0DE68963AEDULL, 0x2C71CACBE71A4DA2ULL, 
            0xFEDF0300B30B47D3ULL, 0xACA7F4B5C1F0BD4DULL, 0x5993425395098537ULL, 0xBCA06D98175CCFFFULL, 
            0xC6695B1AE985702EULL, 0x8D27AA4BA112771FULL, 0x8C9F09E0BD3C5CB8ULL, 0x4BE9BB8895C30BE4ULL
        },
        {
            0xE32F6C8F968209D9ULL, 0xEB107425CBA3A084ULL, 0xF81A8F0B95F31062ULL, 0xD65ECA3A9521791BULL, 
            0x3C837A2D160BA0E2ULL, 0x89A71FC2C21C6112ULL, 0x2912BC5004F6DE7BULL, 0xE97967AF19C2E091ULL, 
            0xE3B1EB2F38D7F2C3ULL, 0x205AD22017CED2D8ULL, 0x548ECC63340344D4ULL, 0x2ABE53B03BCB2F0EULL, 
            0x6BE31ADB8F2522E5ULL, 0xD39F86EFCDA06AAFULL, 0x639DA23A43DD7CF4ULL, 0x900C137044845247ULL, 
            0xD4011F593A89F660ULL, 0x8C5A513AC40094CBULL, 0x753ECB6BBA724218ULL, 0xDB57822E9BB220AFULL, 
            0x6A99418ADAFD20BBULL, 0xB6A7C5B36EB54572ULL, 0x04DA6AFF40DA45CCULL, 0xB34C9B3401D9874CULL, 
            0x3ADD9F3E40A46CB1ULL, 0x6AE6D5A029877086ULL, 0x1637EE02897984E9ULL, 0xEED99A878BCC4384ULL, 
            0xF31AD9CC35A567FFULL, 0x5519A959722E1EF7ULL, 0xFA3898FB44710016ULL, 0x6F90AA8EDC3F2B39ULL
        },
        {
            0x07DA19C96019ED7AULL, 0xD8BBFC4100CD700AULL, 0x9FEED4A6404963B9ULL, 0x04D926FE7580C962ULL, 
            0x0E8DF10131109D50ULL, 0x33466983523BFE02ULL, 0x399B78AA4FDCEC56ULL, 0x15270B95716E3DC0ULL, 
            0x9BA74771764B7AACULL, 0x372ECA11A372E4A9ULL, 0xCCA7BD22F3523F99ULL, 0x74EA79CEAF181569ULL, 
            0x92EFCB2B47FF87C2ULL, 0x243330BA41D7819CULL, 0x845A0A2275C782EAULL, 0xD1FE7BA719C07289ULL, 
            0x5548488B54130D8BULL, 0xBD11BFF2C7FBE095ULL, 0xFFD42D91598CC504ULL, 0x51C04B356A816BD4ULL, 
            0x31AD8C1861009DFEULL, 0x70808875994EBC62ULL, 0xB4E91FE1333D0214ULL, 0x450A0AAEAB50B259ULL, 
            0x15E71C109F73D121ULL, 0x218BCCD1222CA74CULL, 0x06F3574BFD50F852ULL, 0x22315604322E80C3ULL, 
            0x9446DF629F3E2FC4ULL, 0xA0C7121CB7097D9FULL, 0x43BB1D553BD8BEACULL, 0x5C0C54B5F2F8E229ULL
        },
        {
            0xB6BC100246CA2CDCULL, 0xC44B86B9D78D3CE6ULL, 0x87665CD16DD0CFBFULL, 0x3FF3A1762A5C582FULL, 
            0x2CA7CE95580899E8ULL, 0xAEBA623A4CAE17D0ULL, 0xB9A6E955157C3D51ULL, 0x3A88D5901A450360ULL, 
            0x601FDBFED1DEA01CULL, 0x8A40573A633DE280ULL, 0x854FE2C184D6FD31ULL, 0x397846015AA5E351ULL, 
            0x3C2A4A649403BB6EULL, 0x08DFB6812BEA134CULL, 0xF3DB3C4E815DEB6FULL, 0x3957F9D95E027DCAULL, 
            0x9A7BA44F6DAFA596ULL, 0xB3945DCA92E3583AULL, 0xB4F2FB5F0689E4D5ULL, 0xAADFE7EAAA3FD175ULL, 
            0x84A4AE4C0BAD0CF9ULL, 0x3F7B696E08ED565AULL, 0x6E980EBA70CBDC34ULL, 0x7FF83819F83A99A9ULL, 
            0x9BDA4810B3E72552ULL, 0xBF7ADCE81F012CD8ULL, 0x8109701458DC483DULL, 0x8424EFFB0B9D48C4ULL, 
            0x1156821979FA39AAULL, 0xFF29F361777C9396ULL, 0x318A09EDCD10BD12ULL, 0x024043F3B09F6F6EULL
        }
    },
    {
        {
            0x5532365BDAA64040ULL, 0x91E300239AB935E4ULL, 0xD9089C3484BA063EULL, 0x9981E77BD65AC9F3ULL, 
            0x8BD770772CBA6724ULL, 0x69EBF82F730EC562ULL, 0x30E47F992D026300ULL, 0x785E7C7D631131CFULL, 
            0x35371E94A34ABA1CULL, 0x629A2B249B80D40EULL, 0x2148D87A66900816ULL, 0xBD25B821FCCAA07AULL, 
            0x572A8C4EE4544B25ULL, 0x9EDAA29DD8966A9DULL, 0x98FDBEFCD859E74DULL, 0x0FCAD66EE16AEA27ULL, 
            0x4606F139A3BB831BULL, 0x2FAE96C491F9009CULL, 0x5DA9FA90C0297D45ULL, 0x9C73ED32737DD2ACULL, 
            0x4D07236C7CBECF14ULL, 0x7E44846F177D8C9AULL, 0x24A33017F5C4DDF6ULL, 0xEC513D8CCAFC771CULL, 
            0x853F9BE9141E95B0ULL, 0x7F3773914C38A008ULL, 0x8EEA3BC187D2CDCDULL, 0x2AB7596DF456248DULL, 
            0x100F77E4453009C9ULL, 0xA33333EF8CFA1C32ULL, 0x42E02D76678DB61AULL, 0x96A55BF71D2C83F5ULL
        },
        {
            0x352A12CBD2B03A29ULL, 0x0D346C02A0ED7BC6ULL, 0x568F5718C16CF642ULL, 0x73C4574F6CD102B9ULL, 
            0x4685292510515CDAULL, 0x5EC6E00F62755E19ULL, 0x07C4E3DD792A5122ULL, 0x217DC417F33399F7ULL, 
            0x825C34CE2711FD8AULL, 0x4A9DD81F63A3406FULL, 0x6AE2C30836771117ULL, 0x966FA1AC1DA8C1C0ULL, 
            0x14DD7883A4C13045ULL, 0x0DE7AE138CBC383CULL, 0x514DE6AE80760871ULL, 0xF7807EA00F600DA5ULL, 
            0x87F69F7D1D47FD30ULL, 0x76E3FF39C4591BCEULL, 0xB3C440DFF90A27AFULL, 0x85D2FC5CEDCA3393ULL, 
            0xDAAC59BFC4F6A84BULL, 0x322DEB033D25BE25ULL, 0x39C1CD3AD98F3F07ULL, 0xD44091AFE21C3B72ULL, 
            0xBCCAFF923DBF1A56ULL, 0x804D2F44569A290BULL, 0x8F8ED1B21E1EF90EULL, 0x0389E997F35D45EBULL, 
            0x867A1617CCB83FCDULL, 0xA01CCDF3B92EF831ULL, 0xB19834553987FC38ULL, 0x899930D092913770ULL
        },
        {
            0xF78629278450DDE4ULL, 0x32A566121599A2E4ULL, 0x7D5D141D429E6668ULL, 0xC1BD1FF66AEE0C5DULL, 
            0x2C787DD21DD52C45ULL, 0x62F5DEF967BD329DULL, 0x02F66DDAB47086F6ULL, 0xCFAFD661AA982FB0ULL, 
            0xD30D8D637795893CULL, 0xF44A85845DDAE74FULL, 0x10A69643BBEC02B3ULL, 0x0F15C4D00EA8875CULL, 
            0x94BDCD0D8CB0BE11ULL, 0x2601CED67771067BULL, 0x3C0ED8C82B87AEFBULL, 0x434D30B295D2B19EULL, 
            0x9EA8B8501D8ADFE0ULL, 0x677304D48C03BFD3ULL, 0x54839E168E3B9AC8ULL, 0xE2F907910CF77AE5ULL, 
            0xAC6B825BA3D1DB52ULL, 0x69CC56BFB9FEF6A3ULL, 0x89027D95ADAFC51AULL, 0x5D12DA72B28D3AF1ULL, 
            0xEC4C75E5EE4FC1CBULL, 0x815EC704615359FEULL, 0x81C3AC0CA8273947ULL, 0x5803A403B2927740ULL, 
            0xE5A79CDF9BFEB0A4ULL, 0x4D4131008B004B85ULL, 0xFB8EB2D390519599ULL, 0x918D3DB9A2E3C5F4ULL
        },
        {
            0x0FB6953305F6D670ULL, 0xC32FCCFCC0AFE0F4ULL, 0x41AE696F2DD32232ULL, 0xBFA14B9B3113F1D7ULL, 
            0x513E29C564754C1FULL, 0x654324A7CBE2C50EULL, 0x256D54A4A0EEA8D4ULL, 0x32F0414429D2EA3CULL, 
            0x2AF57B23731347A0ULL, 0x0455CFE00951FA79ULL, 0xE27D34FE43FD4C30ULL, 0xAB566976274CE2B3ULL, 
            0x4494197CF42DC428ULL, 0x67D4800C5233FD9AULL, 0x215CC36185054C91ULL, 0xEE6EC188D99BED78ULL, 
            0x74C3013F25E0A80AULL, 0x20A4FAA208C9E469ULL, 0x9A0694132A540F05ULL, 0x7AB7BF7D40ED9604ULL, 
            0x5B0FF7DC7F220DE7ULL, 0xAE56A7A8072EFA86ULL, 0x97B7C0A62FAB66C0ULL, 0xCB88999D1481D845ULL, 
            0xDA145FEA7363D76AULL, 0x912F91D18E19CDECULL, 0xF373AEFFDA512425ULL, 0xDCD5E6E42E100F10ULL, 
            0x1C00AB35088D8988ULL, 0xB49514A35F3F5BEFULL, 0x12712D18DCCDCCD6ULL, 0x33F83538DD21DD37ULL
        },
        {
            0x627E44D2ACD8C584ULL, 0x8B4D52ADE9096DF0ULL, 0x1C4E7780FFCB7416ULL, 0x3CC2322766B3135AULL, 
            0x07A07EA676A966E5ULL, 0x98D6CBCC52A7B289ULL, 0x7D78581361E8F583ULL, 0xF1EAB62E4805B45DULL, 
            0x15B3FA98145156C4ULL, 0x5FE2A96636393961ULL, 0xAAB316BF38513D00ULL, 0x92B3B0367A6FB675ULL, 
            0x0901E5E9276584F1ULL, 0x3EB9BA151EA060DAULL, 0x428B84275ABFAADBULL, 0x430637AB4E025196ULL, 
            0x57BF637FC4C5DE4EULL, 0x9F832D3700AE7D0AULL, 0x9EC041507FE41F5AULL, 0xF5AC7D997FD35296ULL, 
            0x4FEE318734B9D589ULL, 0x49E4DEA92FC13816ULL, 0x15516290C5A88EC8ULL, 0xFCF9F0CA9A693465ULL, 
            0x2871689C36ADD5FEULL, 0xB122C58965C4B09FULL, 0x8FA20D8DA30BB702ULL, 0x81C8EF58FE378337ULL, 
            0x6A52EA41E33D5CA3ULL, 0xF4EE9C508AA77315ULL, 0xCA16F8EF4A56AA4CULL, 0x60A54A4F107A42DEULL
        },
        {
            0x44C9903C68958ADDULL, 0x144381A2CB647AB6ULL, 0x6745648C1CA05D6FULL, 0x954C8A873A945A4DULL, 
            0x48083C90E173DE28ULL, 0x6B5F99FACBEACC62ULL, 0x52F197C106AA9DC9ULL, 0x6CBF9A808A939C69ULL, 
            0x17818E9DF007028BULL, 0x23C89D31E986A528ULL, 0x77DC9404D24FEC06ULL, 0x0CF157EA67FFBAD6ULL, 
            0xF71896315D1C8BBDULL, 0xD47BA9EF7A50DFA0ULL, 0xEEE26E6CBF7F45B1ULL, 0x472B05B91B8E6358ULL, 
            0x0926FE178BF85D34ULL, 0x0AD3301F88F64FFBULL, 0xF3F75A0774559D32ULL, 0x473B6FB806BF19E2ULL, 
            0x0E53518C3E1699ABULL, 0x0DA945E0AF362E11ULL, 0xF051C10C1C788D99ULL, 0x2504AF99A63A4CDAULL, 
            0x00FA1ABF7FC606FDULL, 0x1186E4ABC036C51DULL, 0xCE417AA83B727DE5ULL, 0x380010009951D4BFULL, 
            0x7C917CAA032F6A78ULL, 0xC2C3B8B8F95B7D75ULL, 0x76BEE930D45E848FULL, 0xFCAD9C3E3014516CULL
        }
    },
    {
        {
            0x34D85949A7B58F3BULL, 0xC452FF6BF069E62BULL, 0x50C69302CB13A963ULL, 0x523947CCF6FAA086ULL, 
            0x0247C2D93DC243CFULL, 0x85188CC98794BDE0ULL, 0x70DD7BCD4C9D84F9ULL, 0x2C49E1090912A081ULL, 
            0x580973379C8F9AC7ULL, 0xFC3EAD9292EEFE14ULL, 0x7B747B8A00FCEACCULL, 0x65873E5EEDC5F37FULL, 
            0xBEE42E9EE0DB310AULL, 0xA4194DE2C487DA9CULL, 0x6F81CC5253CABF2CULL, 0xDDFF6FAF10B8F32CULL, 
            0x6DE5314D8E8C18CEULL, 0x8DBC1F53423C3909ULL, 0xDCDBA8C939787B43ULL, 0x42961775BC8C9DB1ULL, 
            0x1EFE95F4C55821F1ULL, 0xDDDECF0B5162D509ULL, 0x18DE34CB2115201DULL, 0xA1D02B96C0FB52D2ULL, 
            0x13C60209B999F679ULL, 0x8C23E9BB9FA4C864ULL, 0xAF7239D44ED3E0C6ULL, 0x0DA11D26524ABF00ULL, 
            0xB657D0094767CFCDULL, 0xF986D44363751D2CULL, 0xE6164D2675824277ULL, 0xE03BF3F73C093B3AULL
        },
        {
            0xE51606C611ED5E54ULL, 0x03A4437A769461CDULL, 0xA6E1B69D96275828ULL, 0xE3C254989CEB806EULL, 
            0x1FBA0043BC53563DULL, 0x6C3C05DFF248AD24ULL, 0xF3BBE7B9E6AB9567ULL, 0x7D92B645649C44C1ULL, 
            0xC8E1F75BA9337031ULL, 0x807556494DF88E7DULL, 0xA00980C3A3B6E220ULL, 0xB11E7923AEEE0854ULL, 
            0x92D1D49695E399D0ULL, 0x52937C61B7BCB304ULL, 0x28E58A1199B5B248ULL, 0x11C413035EBE2A12ULL, 
            0x09D7C55F4E4E9778ULL, 0x48F5ADC7CBE7D67FULL, 0xDCD3CFFF7F52FE70ULL, 0xF6EE963D40A567D6ULL, 
            0x96FBD60A77CBEA12ULL, 0x743DF0C21E1F317CULL, 0x2B95B030D0406AF1ULL, 0x7E5FDAC45476032FULL, 
            0x7547EB292B57CC4BULL, 0x7B81E0A5725629AFULL, 0x8013E292722C4010ULL, 0x8C6C5B4F5D64FC42ULL, 
            0xBB5C3D8C49F234C6ULL, 0x2F69331EE3E36546ULL, 0x780B4DD6E2234C6EULL, 0x18A367F099F8A802ULL
        },
        {
            0xEEDD6961558510ACULL, 0x1F2E0CDC4CEBC2E9ULL, 0x2462755FFBA62846ULL, 0xDCD5C199E853C2CBULL, 
            0xEC9B22490E6E934BULL, 0xA2FC29E3E19EE8ACULL, 0xB7A8220B7C363A0AULL, 0x7ED20922C43DA7A5ULL, 
            0x5EDAADC519611EEFULL, 0x8F0E2529309E81D4ULL, 0x67B578639B7A5E60ULL, 0x304D21B4003BCE35ULL, 
            0xED67CBD1C674352AULL, 0x1A1A511F609A83DBULL, 0xEFDD3AD6A80BADA8ULL, 0x03E5188807F09B0BULL, 
            0x5C65D77C001CF842ULL, 0x179AAB4159B79FA9ULL, 0xCEA01B7C4D60F0A5ULL, 0xEA8190C85D8FD99FULL, 
            0x7A2F9F011DB0AC93ULL, 0x8CDF6A1CF6FDF260ULL, 0xB0C5FBFE14FFC19BULL, 0x42021F4DEE657DA9ULL, 
            0x20DE3A32B1EB24F1ULL, 0x4ECE5570AFE74CACULL, 0x76C1F4311AFE36C6ULL, 0x192D6C61BD9419E7ULL, 
            0xCF16CDED5CAA4EBEULL, 0x06DF7C9F46FF65E7ULL, 0x915170A3315B4FF9ULL, 0x7C56A62FD4CE749CULL
        },
        {
            0x26EFDA4A79781C5CULL, 0x957D676CB62D0031ULL, 0x2C01C874A7A5E8A0ULL, 0x2D92D58CDFF9082BULL, 
            0x7C0C9A1E9116BF3DULL, 0x55F016500A514460ULL, 0xEB2B1BD5BC66B3ECULL, 0x37EA302A07876372ULL, 
            0x64FBB35F254B8373ULL, 0x4880EEF2EF354596ULL, 0x03A4EB963EA8AB1FULL, 0x58B0BD22F7C44F72ULL, 
            0x6D830B5640169D47ULL, 0xFF5F7BCE6620E35CULL, 0x4F791A2E2C514811ULL, 0x9376D5BCC75BAB93ULL, 
            0x30F4DF1D2B365C21ULL, 0x6887388C444AD906ULL, 0xBB10BE49A41DF104ULL, 0x581AC55C9AD5A5B2ULL, 
            0xA5DF9E7F8E6D3F94ULL, 0x4481C4DDFD5265DEULL, 0xB5DC140C8C7B3B9AULL, 0xE3C0215485781DF7ULL, 
            0xC68009655F5CB5EEULL, 0x46DB4F74DD7DD50EULL, 0xC0C04C768838AD9FULL, 0x2A4EDF4DAFC0F928ULL, 
            0x1C27F2B42A4C3A44ULL, 0x6092C7743753DBC8ULL, 0x37157A1C830831C0ULL, 0x085B7237714CF17EULL
        },
        {
            0xAF718B677E5F427BULL, 0x5987550173C7F896ULL, 0xD7691B135B96A87EULL, 0xB465C27C1721222AULL, 
            0xB570F7E09877B086ULL, 0xD55B9E39717EDBF7ULL, 0xE8DF8BD88E66595EULL, 0xA4CB5B052EC05BEDULL, 
            0x306337CFE2A7FDD5ULL, 0x611015E375595DA0ULL, 0x73F2FBF0E2A91866ULL, 0xB8D96B98D2724D45ULL, 
            0x6D1E6CC43ADA6A8BULL, 0xEB0BA4F08FCEE100ULL, 0xF3EB708974897067ULL, 0xBCE1B3FDE3D4261CULL, 
            0xA9D129FA23B9E023ULL, 0x670A8F47C68380ACULL, 0x4C5D9AD1B6F7816BULL, 0x2CB498565B21E8BFULL, 
            0x216FDB0793C58FAAULL, 0xD4410EAB881BFA42ULL, 0xDFD9B656C1872CE3ULL, 0x291B721A5D09755EULL, 
            0xEE80814F79641903ULL, 0x1F96D3C27AC11E08ULL, 0xDB6613BD11515470ULL, 0x7034374250BAFF91ULL, 
            0x168B2ADFFF04D666ULL, 0x47237BE588341785ULL, 0x9131DB780BCF0AF1ULL, 0x37F94D69673C93EBULL
        },
        {
            0x11D64C9F191BCEB2ULL, 0x1F7D3D7A647290B0ULL, 0x8720877F25022CE0ULL, 0x98E7BF75F6F51CCAULL, 
            0xEF357EA6BC93E5D6ULL, 0x4E46763FBACCAD47ULL, 0x382F87CDCA50A2A0ULL, 0xB187EDFDAA8C14FFULL, 
            0x1624AB3974FD7DD6ULL, 0x0D7127ACBE18031CULL, 0x6070FD8361AAFE46ULL, 0xB2CD82B3DFAC150DULL, 
            0xABA728657A2A7558ULL, 0x05FBC41B04D0A8BBULL, 0xA310BAB69D7A7CDFULL, 0x2D50B0746E35642CULL, 
            0x3052E6649BC9E2B8ULL, 0x5E0C4286A5BF0FEBULL, 0x7E88F66E75AC9EEEULL, 0xDC9F55531E6A0ECBULL, 
            0x892CC3F8425D4952ULL, 0x4EDF7F9072808668ULL, 0x0AA1415BA685C163ULL, 0xDB9ADFF955DC8FEEULL, 
            0x747E041011B5F9C1ULL, 0xBB339D2D3BF8B704ULL, 0xE6DDDE3F5852F235ULL, 0xA2998494C252133CULL, 
            0xCAB347F8CD4A4A42ULL, 0xAB0ACC28C139F384ULL, 0xC6D4E5854AE9F585ULL, 0x0B08538D4AA80831ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Ankaa::kPhaseBConstants = {
    0xB8B74D413E33245EULL,
    0xAAD1984B4AB009ECULL,
    0x5C1D53EF7B35A535ULL,
    0xB8B74D413E33245EULL,
    0xAAD1984B4AB009ECULL,
    0x5C1D53EF7B35A535ULL,
    0x17246880748F3FC1ULL,
    0x47010CEFC8CDEBEAULL,
    0xD6,
    0xC4,
    0x74,
    0x4C,
    0x95,
    0x73,
    0xBA,
    0x13
};

const TwistDomainSaltSet TwistExpander_Ankaa::kPhaseCSalts = {
    {
        {
            0xC217270DD6D15933ULL, 0x29E397EF6BC8F97AULL, 0xCCFB8B425466AC68ULL, 0x6D461DD04E785A58ULL, 
            0x0590D45659DD2F3EULL, 0x6E0B05C5466AC934ULL, 0xCD2AD676BD2BDB93ULL, 0x3D7C45A4235B3907ULL, 
            0x1A434A191FDD3A16ULL, 0xCC8DE8E7478E5C60ULL, 0xDA87E1695A7828F2ULL, 0x43A03814DC5C22A1ULL, 
            0x3C51318A809F41F6ULL, 0x04E296A4C01A31BFULL, 0xF799E132B204DF06ULL, 0x3F4D77115DE57610ULL, 
            0x29F8E43B3037BB2EULL, 0xEAEFD56B163EF039ULL, 0x029C5B4AFBB1F62EULL, 0x22FCAC495C66DB55ULL, 
            0x7782898A9E979D1CULL, 0x00EB17E0CED3F07AULL, 0xAA0D90140520C458ULL, 0x0ECB7C2C82FECBE3ULL, 
            0x78B70F1C72A1E39CULL, 0x0E0C02AD6D87E646ULL, 0x7FCBC3745B843188ULL, 0x0D3E6D27A3B8133EULL, 
            0x0BB742BBFFE37E9FULL, 0xA586DC19D448AB2BULL, 0x5DBF8B29DE9F2FFAULL, 0xA35B94ADDFFA1123ULL
        },
        {
            0x249C621EE8C20C72ULL, 0xA4E2CC78476658A3ULL, 0x505475F4DDA9A873ULL, 0x5E25BE6258E14FC8ULL, 
            0xFC5E235553356249ULL, 0x3E7F8889C0A26E68ULL, 0xA023829EDE40F5B6ULL, 0xCAF7391A010985D3ULL, 
            0x375557279B918D94ULL, 0xA3317D7D1F7E4AD7ULL, 0xA2B72684CFC07842ULL, 0x63E6DC4EC3008220ULL, 
            0x2ABEFBDD7936FE58ULL, 0xBD063C3E75ED642EULL, 0x95B37EE50F2C1C3BULL, 0x1E1A34C20FDAF9CFULL, 
            0x22A0146580BA0E44ULL, 0x826CB1395BF53C7BULL, 0x5C24AD968EC95B58ULL, 0xF541EF99E4CEEC7DULL, 
            0x4E972747A8A0C0DDULL, 0xB7F2185BE3FA57FAULL, 0x5CD4D3F27ECFFC55ULL, 0x7066B943780D30C2ULL, 
            0x35DD484836904749ULL, 0x59F12D9AD9A297AAULL, 0xEC75788F9E5ECD7BULL, 0x7953607E5D1D0D75ULL, 
            0x54BBEF9F637BABD3ULL, 0x582CC834565D5268ULL, 0x952823FD20CE932EULL, 0x4B51058DF6480C08ULL
        },
        {
            0x9DCAA939B2261A9CULL, 0xD72E2F5030D344E0ULL, 0x17B807548810718AULL, 0xB5ECA137CE7EAFECULL, 
            0xD21F0ACD3604144AULL, 0xDF7932EEBBC4F9B7ULL, 0x90748A5584EA6C3AULL, 0x798EC688B254ED8DULL, 
            0x7444B18DFDE11280ULL, 0x0D2A61291349C905ULL, 0xF7F9079412950CBEULL, 0x7E716E904776C427ULL, 
            0xBAD20C80E8642872ULL, 0x9774D15036DF2B10ULL, 0x6390AB6947523289ULL, 0x316B6459C51C5E3CULL, 
            0x2EDEB92966682C3EULL, 0x35878BF13B73A2FBULL, 0xF5F447F9B60F6481ULL, 0x6B988A901063A147ULL, 
            0x0DA140AFBFAFE576ULL, 0x9A70A0C273AF7A99ULL, 0xD4F0D45E44DA7EC4ULL, 0x4DF3B1EFFCE546A3ULL, 
            0x4C49E42EDAFCB4C6ULL, 0x7254681BE57E5ACDULL, 0x528AA54F14E48372ULL, 0x7B422D53E33E5C0FULL, 
            0xDBB151292EDF4B0CULL, 0xCCA318F6293084D9ULL, 0xF093FB990669B4CEULL, 0xBFE33EC8ADF03E8CULL
        },
        {
            0xCDFD95C55A70341EULL, 0x51EED59EA355500AULL, 0x795019B2A8BF7FFCULL, 0xD4CCEDC9EA9DFB71ULL, 
            0x0F20A7FB298B17B0ULL, 0xDB60FA07A1B4B7CFULL, 0x48499994A0B7FA14ULL, 0xCE68DCD6A298F147ULL, 
            0x986D503F04AF02C2ULL, 0x11712351DB16B5DEULL, 0xF76BCB613FB55FEEULL, 0x24AF5F857B5D2F64ULL, 
            0xE6F108FFE6013908ULL, 0x3A1344528987B2FCULL, 0x7A8A7F302BEB7BBDULL, 0x48F1E0B981E5CCD9ULL, 
            0x994CB208B74BD7C1ULL, 0x46613F99B8501E5AULL, 0xF402A6623CCA0037ULL, 0x3A0DE7DCAD4667E1ULL, 
            0xBD5B3C43591F1162ULL, 0xEAE0A5864F7A4886ULL, 0x585AB9C1E2A463C8ULL, 0x07B28F57C76B12E1ULL, 
            0xBED8DF1CCC4A91BCULL, 0x8E351EAD6FE5A374ULL, 0x71E90E4CE0DD8992ULL, 0x6690CE2B92D8FA25ULL, 
            0x2F53186DF4FC635DULL, 0x573EB46AD3506D52ULL, 0xA386128762E949ACULL, 0x2B8B0ACA3513243FULL
        },
        {
            0x409A59E9404FC3ECULL, 0x71A91FEF0E092E28ULL, 0x2262368394CFB663ULL, 0x1A325422B726DD19ULL, 
            0xD4A95278D3EA5040ULL, 0x768785DD7A0211C8ULL, 0xA1D3F464367DFFFFULL, 0xD62D26FF37628C12ULL, 
            0x73FC9F43BEBB1504ULL, 0x9086F54EC684AFC3ULL, 0xDAFFD8C49C2D4721ULL, 0xCE159CD5A96BFCF7ULL, 
            0x17AFDDE74F9630F5ULL, 0x3F15D4E3BC11F40CULL, 0x86F4B95CAB86685CULL, 0x510329B5A7C449E4ULL, 
            0x5D5E1E257A452700ULL, 0xB1D553C4F90FA25AULL, 0x913E0A886AF5146FULL, 0xC020D51998C80330ULL, 
            0xB86E9C9E0F0FB7EEULL, 0x8A128D73C8D62276ULL, 0x33F30F99A82B1D86ULL, 0x42D2D3280CADC050ULL, 
            0xF2CACEAC529148CEULL, 0xADAF663F1C416E08ULL, 0xE8247CB0EFC93E97ULL, 0xFFA1ABB4806CA044ULL, 
            0xF91F77FBE265C0EEULL, 0x3C4925DC4514A48DULL, 0xA4B09E5BF51FD575ULL, 0x43A615D5BB07E6B4ULL
        },
        {
            0x0F74A2C745E4953FULL, 0x980B6C864FE6AD65ULL, 0xB57C90CE52CE7743ULL, 0xE4B198987D31A9DEULL, 
            0x1077A81870F33AF7ULL, 0xEB4649B1C58BDA5CULL, 0x11C479DF6E4F1EECULL, 0x58D13262714AD903ULL, 
            0x2278BB46E5C50130ULL, 0xF05D7046003D1458ULL, 0xEBBFB81DAF68BBA7ULL, 0x70F7E96203564159ULL, 
            0x9F688F23020F333BULL, 0xB25B7912CFCEA989ULL, 0xB37D7D76529EAD47ULL, 0x262185C94C0A9055ULL, 
            0x87815979412ADCA9ULL, 0x3B449537D57E0AB4ULL, 0xCD91F33C5A7EBAEAULL, 0xB3D35CC74D54801AULL, 
            0x49A7F2278AD3C7FFULL, 0x2BD9EDAAA4D72EBAULL, 0x1233F3F774D3CBBAULL, 0x9183C8DED6BE3508ULL, 
            0x92317D9F638E9FC0ULL, 0x61B6DBD073F1F57CULL, 0x8EE6E6A5EB24E239ULL, 0xB7C35C299F4AA21AULL, 
            0x67D3ADE6DF2E45D9ULL, 0x33ECD81427838BBAULL, 0xDBD8D175AD9E1A49ULL, 0xB3127B37F1445D5EULL
        }
    },
    {
        {
            0xA07C30D9F5933392ULL, 0xC191F1C45F6923A5ULL, 0xDACE51475B5E0772ULL, 0x0A594FEDED287F40ULL, 
            0x80B352BE3C2565DCULL, 0x6402A21FB920CE8EULL, 0xBFF10FDDAC14CD89ULL, 0x6D20CF6A0DA2D02DULL, 
            0x3BE402ABD64954E1ULL, 0x825F9E2D5270866CULL, 0xF8C0BEE2625E8104ULL, 0xA132C94116843925ULL, 
            0xE8B66EDC556F4AF7ULL, 0x38B307BD5D85EE53ULL, 0x32EA35BFDA9F68AAULL, 0x5D6AB840D3E7D884ULL, 
            0x7EEA1DBA1FD3DB0AULL, 0x4A2A4604FA2B40C6ULL, 0xBE19DC77C2ECF10CULL, 0xB5F9BDFD0DBCA08DULL, 
            0xA6FFD9CB990D85F5ULL, 0xDB9575432B256D60ULL, 0x1EDD11BA6AB4A69FULL, 0xA1C6D1ADFCCF030DULL, 
            0xF6E75AE6956C0753ULL, 0x275F030E1F82CDD9ULL, 0x8A0765351AC27728ULL, 0x61ADE0ADA648E92BULL, 
            0x691D081E71CFA89DULL, 0x06C94BB4C7DB344FULL, 0x560307F1E677F880ULL, 0x619F0C801A370702ULL
        },
        {
            0x71099792B20B084AULL, 0x265F6F3D3DDEE41BULL, 0xCAE9237B6EF67802ULL, 0x62D144FE9CF296CCULL, 
            0x9DCFAEA3637626F0ULL, 0xC3BBC4D04D2E1ED8ULL, 0x0E314F3A99632FD1ULL, 0x9E138467784730AFULL, 
            0x787096C99F356C13ULL, 0xA8E1509249B35465ULL, 0x0E853DDF3C926061ULL, 0x7ECBD5430CD303DCULL, 
            0x6348A292907FCDE8ULL, 0xB19C84E1B5C21C15ULL, 0x3F284BDDE5295C10ULL, 0x4A0671F6CAC97E43ULL, 
            0x440DD7991B636B73ULL, 0x35DD5C06591AE212ULL, 0x6A0AEF7978761E24ULL, 0xC19CED15DC495E5BULL, 
            0x34621A541A5C0BE3ULL, 0xEC54E6D81F6AB3AFULL, 0x973F083832B3F98DULL, 0x5CA0E4DA0A7DCB78ULL, 
            0x7F7ABDD1837F45D1ULL, 0x81FFBE27E69E0785ULL, 0x18B2D83695CF8735ULL, 0x610F24DE7DCC2C1BULL, 
            0x4EABBD67BA80464DULL, 0xD5EEF3D4F19983C7ULL, 0xF1C8EA8CA23FB484ULL, 0x9A5F513695260D5EULL
        },
        {
            0xBB4F694C938D1E32ULL, 0x12401F9902F8AD55ULL, 0x23F7F935AE6B61D6ULL, 0x3C8199FD2B9AEF2AULL, 
            0x361A9F61D64DAF7BULL, 0xFF3F0C6973A178D7ULL, 0x2252B7CFF24701AFULL, 0x836AC19FFC078E68ULL, 
            0xCE27BBF8DB61321EULL, 0x0ABA03361D6B9BD7ULL, 0xC6D9964A1F2614F9ULL, 0x778DF4A0D2E21471ULL, 
            0x014D0436E1CEE272ULL, 0xCE1F41CD1EFDEF7FULL, 0x3A0B04068809207CULL, 0x80291470F0ADDFD7ULL, 
            0xF2B527F108FFAAF8ULL, 0x1909B6A9F77DAD4BULL, 0x32BA4C8C579209C9ULL, 0x2BBBC84406E9E384ULL, 
            0x84D0DD8286A289C5ULL, 0x19475EAF374E4F2EULL, 0xC47FD80E254F396AULL, 0x59F98FA273054BDDULL, 
            0xBAF43097932F9239ULL, 0x965A4DBD486ED946ULL, 0x678FE2E491B44346ULL, 0xD6FA140533F8DA8EULL, 
            0x3474EC9997D8AA89ULL, 0xEFE94B47D7E09BD5ULL, 0xC807D1894171D829ULL, 0x38BC4B5CEAC5B2BFULL
        },
        {
            0x5D8567E208F34911ULL, 0x0205FA6AF74E1E99ULL, 0xC180CC612517CF3EULL, 0x07062B445A66F337ULL, 
            0x53BB7D700B7CDFADULL, 0xD98874937D29857FULL, 0xA5EDCB4FE3BBFCFFULL, 0x11236F8917AA38EFULL, 
            0x75D731A342D491F2ULL, 0xD36EB6539E26076CULL, 0xDDF24F1DA68D0F6DULL, 0x1B24B8B99E1033F2ULL, 
            0x0061CA50C5CB7E25ULL, 0x820C5CA242F616B0ULL, 0x0531E2CA42D44A6BULL, 0x06C7126E9558DE9EULL, 
            0xFE3EB7C82F1E7F14ULL, 0x6499F498EE911121ULL, 0xF9FAC99821436B67ULL, 0xF153E0F4643ABF43ULL, 
            0xC34511B1D7E9E7F6ULL, 0x2E323D14E567C80AULL, 0x12CB5B3EB6153028ULL, 0x8759D087B668ADD2ULL, 
            0x8B53949C4D64C39CULL, 0x2E2EF9FD13924A36ULL, 0x4AF3532A86D45718ULL, 0xE53BBE451B61C043ULL, 
            0xA5F657D2B30EEC10ULL, 0x7122A44A66AECEBBULL, 0x5D48815B87F4F00AULL, 0xA2A7631848841B7FULL
        },
        {
            0xDFCABFA6154FC098ULL, 0x9ABA7D0859CF2B64ULL, 0x0DE9E0FD7F7AE841ULL, 0xA8B987658904F638ULL, 
            0xEEEB3450620FAF40ULL, 0xA9EF177216B97976ULL, 0xD4AEC61B8804C819ULL, 0x4ADD0293FBC06A2FULL, 
            0x319CF40481455C76ULL, 0xA048C7E285A232B6ULL, 0x03029CF11FF1123FULL, 0x3C91A6ABC8497419ULL, 
            0xD48BA77345E725B8ULL, 0xDF466F26BBCF0894ULL, 0xC4F7B90DEFC0E512ULL, 0x399F4181C3933753ULL, 
            0x695E210F34B16374ULL, 0xEEF832D6CA3D6B63ULL, 0x73C397E6FCC52B76ULL, 0xB4BFF921CFCCE258ULL, 
            0xE6366E955639F1E1ULL, 0x23AF1E61EDDC20A5ULL, 0x6B15992F80A3B445ULL, 0xE14AF6037189B5F6ULL, 
            0x9463489AD4C95B9EULL, 0x0B644BC8EEE9BE33ULL, 0x274B01C52EE028AAULL, 0x00880E5104A2676FULL, 
            0x6911740EF1999FDEULL, 0x7CD06295B79BB6DDULL, 0x50BCE11DF3C3DE17ULL, 0x4F4FBDC0A077DD15ULL
        },
        {
            0x55C24F8953CE89B1ULL, 0xF1096303C33DDA4AULL, 0x878E8E25B2EF6829ULL, 0xC92B0B502CEFCBA6ULL, 
            0xD1CE1A836C5797C6ULL, 0x47E9D6E781080FA7ULL, 0x34FDA28B7A07863AULL, 0x32DFF88118E6F265ULL, 
            0xFF6CE6598BE15158ULL, 0x130F0130ACC313EFULL, 0x6A9961BC09E9ED79ULL, 0xED2C93F91193D5B6ULL, 
            0x77060200E1A4EC72ULL, 0x38B21DBA24E96F12ULL, 0x39C9D2A4D9AE7E61ULL, 0xD7655AE0211D80BFULL, 
            0x2ABD497F70212139ULL, 0xEDC67887D11BD4D9ULL, 0xC17DF91A0531F803ULL, 0xAFFDF6C73D3E5389ULL, 
            0xAAA5FCA2E7902FF9ULL, 0x4608BD1DC3DFC8DDULL, 0x965B5BD5D2E36453ULL, 0x985AE845E7B6B7ABULL, 
            0xF16D5192076C1792ULL, 0x62831AD6C3933EFEULL, 0x54F69E569BE6006FULL, 0x48AD7260BFFB1241ULL, 
            0x5BD6AC0CA767FD99ULL, 0xAF8AF453C8ED5D72ULL, 0x1DF637979006FB5EULL, 0x9AE09AF41B8286B5ULL
        }
    },
    {
        {
            0x09D8A3995CAD3EE4ULL, 0x9E7D599819696C63ULL, 0x2907E8B37C1AEDB7ULL, 0x7242972E93B9D18CULL, 
            0x3652593F3D1B0A41ULL, 0x6F3B7A822D484300ULL, 0x16189D8D01847C09ULL, 0xB257880DF736AC08ULL, 
            0xE5B4FA0700B176EFULL, 0x8E39A632BF533537ULL, 0x0A70F58CB9EA7BC5ULL, 0x8D1DE52BA0A8E9D3ULL, 
            0xF2C75E2D678B54B4ULL, 0xC8FE300FE8DF22B1ULL, 0x497B77F5DCA15EEEULL, 0x53D124B3EE742550ULL, 
            0xF15F0088A99ABE79ULL, 0xA813F62468512EAFULL, 0x3351B3C76065C9F6ULL, 0xC58953959CB9EF1FULL, 
            0x0465D95672BEB51EULL, 0x4ECD3BD7E0320980ULL, 0x330B5EBB659F32B8ULL, 0x0A392FA7F6B8760CULL, 
            0x66A3277687E68027ULL, 0x6D92858150571ABAULL, 0x0DFC7D67B538FEC7ULL, 0x72A80F7AC58E5D68ULL, 
            0x2359C01FD39EFB86ULL, 0x1C6A6C5B39F4ABFCULL, 0xA43DCEC2A390572FULL, 0x2CC0FD71C46CB574ULL
        },
        {
            0xDA963F0B559B57D8ULL, 0x8446A17DF6E8598FULL, 0x430BDC449E9D305FULL, 0x419059FFB8A18D73ULL, 
            0xCC03C240B2D99CA9ULL, 0x20400AAA08A128E2ULL, 0xCAD33F03F61742C5ULL, 0x73F1A204B20C9114ULL, 
            0x0D267F512B6F7943ULL, 0x82DB3E1D1FEF6681ULL, 0x9D7C52F0C647261AULL, 0xD6178B24C3FB0948ULL, 
            0x7BAD5F53BFDB131CULL, 0xF4E631BF4CAFFAA1ULL, 0x1DEB2791A3D179EFULL, 0xB776EF9BAF83DD21ULL, 
            0x68AC38C81F8DCC17ULL, 0x80748FFFC7C15BACULL, 0x6F5A8AFF8B23C08AULL, 0xF615FA23B398E72FULL, 
            0xBAFB1313A5926BB9ULL, 0x2BCF4A431A8E778BULL, 0x9442C6D86B10AC2EULL, 0xA269943DE218997AULL, 
            0x8D24697DD3C6CBA6ULL, 0x176B2A7EAF5BF2EFULL, 0x9381C51E6F7A1D44ULL, 0x6B5D79CDFB3005BEULL, 
            0xED8371F3A543F3FEULL, 0x8156431F487DD43BULL, 0x33EBEC7CECACF6EFULL, 0x25813C485DE0465EULL
        },
        {
            0x372B2A6DC60021A2ULL, 0x95133B8FA36A7D1CULL, 0x79B1F60C618A8FD0ULL, 0x503F28ABD46CC5A0ULL, 
            0xFA8017E9D838D71CULL, 0xA0D2426F95A635F2ULL, 0x4C666AE64BDCB66BULL, 0x04BCC9E6B7AB8B8CULL, 
            0x1EF68CD463D7C88BULL, 0xAA03A1217B6A4070ULL, 0x5CBD4C2C8BD3C174ULL, 0x3D2AB56F4394C7C0ULL, 
            0x282993EFC33B2AEFULL, 0x428C1819C7065D4EULL, 0x98F1F2E888E0CDA4ULL, 0x5D8FBA54D30FF921ULL, 
            0x7D9E373B36317FFFULL, 0xD9D219493ED6071AULL, 0xA3FBB2AA6C6428A9ULL, 0x5BA28AF76F3F23B6ULL, 
            0x56F68049BA781635ULL, 0xAC15AB7187FA4106ULL, 0x3CC1E4FEC49B883FULL, 0xFE0C4A6975F913FCULL, 
            0x0941C0F60417C070ULL, 0x35261AD73B7B21A3ULL, 0x13B14589ED3B227CULL, 0xF21EC7F6B14849C8ULL, 
            0xAF7CAC89475CB783ULL, 0xC19C1C25085936E9ULL, 0xE3480A8197746201ULL, 0x2F1C329E6EDD94D7ULL
        },
        {
            0xA8FBCD74599D9B88ULL, 0x732E43F96B8BEED9ULL, 0xD58547F39BF6F80AULL, 0x5E99B54E702787FEULL, 
            0xE7E2D4CE7CF04063ULL, 0x4C755DD3ABF81427ULL, 0xCC474A37F498AA3AULL, 0xD3335EE2DD4C27D9ULL, 
            0x9620BE877A709821ULL, 0xEDBDDFAF829EAE69ULL, 0x5FAF46111643C187ULL, 0x33974C304AE110B4ULL, 
            0x06281A0D955B1E5FULL, 0x07177BAC434C17D4ULL, 0x0E19B5CA21507A0FULL, 0xFF01C6C9B7E95E1DULL, 
            0x4F4C98A51C6AF46EULL, 0xCDEF3410CAF667F9ULL, 0xE8A2A4BC84858C79ULL, 0x05B69C7215CE923AULL, 
            0xCA5ACD67D2AB9F1AULL, 0xDC64536805FE5743ULL, 0xC64F5A26FD3AD882ULL, 0x8E8EF19AB0283FB9ULL, 
            0xA9DDF6A1B7BB66BFULL, 0x12ADFA3303C53892ULL, 0x03F9A715FEB23B2DULL, 0xEE07FDBC0A5DB6AFULL, 
            0xBA7E40467B884E97ULL, 0xAB933CB703CCEB10ULL, 0xB550CDEAE06FF2FDULL, 0x56347B8920558678ULL
        },
        {
            0x4738D65150E43BE6ULL, 0x4A57E27E9E6727E1ULL, 0x4C4F815ED87F2834ULL, 0xC1B70728E755AF2CULL, 
            0xDAC8D8E87D2C968CULL, 0x1040A677C1A92145ULL, 0x896F1B14BA331001ULL, 0x2836C85C9862CA27ULL, 
            0xC338D3CD9418B5C6ULL, 0x3B17105D5F24630AULL, 0x084E91934C101F80ULL, 0x9F75A5B698211D2AULL, 
            0x37FBBEEE88D83823ULL, 0x47B029A7292419FCULL, 0x59B7C484EE8482F7ULL, 0xE239D0C3500A36E4ULL, 
            0xBA770420AA09F483ULL, 0x3BB384FF3191C7D1ULL, 0x25AFEBCFE78710B2ULL, 0xA6EC1D45474F7387ULL, 
            0x65D7F0B01553AE48ULL, 0xC047B6C405DDE55CULL, 0xD58DE64BD1ED86A8ULL, 0x6D0E252874580D0EULL, 
            0xDCC677A12EA12E1FULL, 0x41246FD3D97B5DA8ULL, 0x75826C7FE52429CCULL, 0xA648732ABD9392F1ULL, 
            0xA50AC17539D9AB7BULL, 0xA0B511DA76BB7BCEULL, 0x9200E3B179DAB770ULL, 0x09FC0DAAAF3CEB95ULL
        },
        {
            0xCC81504EEC0D6467ULL, 0xFBB4E708FFA563B8ULL, 0xFBFEBDEA4309B38FULL, 0xFEDA82AA1C238B2BULL, 
            0x07D59239757FF902ULL, 0x0D31AE4F591F7D12ULL, 0xE82F4BBA57C3F9FBULL, 0x8B9BDDAF659FF50DULL, 
            0x9DC346855D6C114BULL, 0x46C15C4057EEAD90ULL, 0x35FECACC2FFAC22EULL, 0xEFA633A04C1760C3ULL, 
            0x7D95BA9C0055DCC7ULL, 0x9B918485CBE4976BULL, 0xF56AF3E83301C4B6ULL, 0x8532D3F5BFD9CD25ULL, 
            0x25545DDD3946A8C9ULL, 0x5B941FBBC36E8ACDULL, 0xE89A93BC2959CD9CULL, 0xD08B30B9572847DBULL, 
            0x90E22366D87C871CULL, 0xBF8EF9D4E848AD82ULL, 0x625387FF9BBC1907ULL, 0x609C487E96426ABAULL, 
            0x11545906CC25C0B6ULL, 0x11F0F44DE9EBF3FDULL, 0x2DF0EAA0AE497CBEULL, 0xD96D844CE01FFB26ULL, 
            0x03819A04E06CC28DULL, 0x54A0873B7A5D80E4ULL, 0x1785E6EC5F32140AULL, 0xA4A1C826FEA72200ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Ankaa::kPhaseCConstants = {
    0x6FFCDEA03338474DULL,
    0x16E11D800FADC496ULL,
    0x1C91B00AC3CE77B2ULL,
    0x6FFCDEA03338474DULL,
    0x16E11D800FADC496ULL,
    0x1C91B00AC3CE77B2ULL,
    0x7C3603BA376EF88EULL,
    0x1E1AEA007E5FFB17ULL,
    0xC4,
    0xC1,
    0xC8,
    0x85,
    0x07,
    0xBF,
    0xA4,
    0x2A
};

const TwistDomainSaltSet TwistExpander_Ankaa::kPhaseDSalts = {
    {
        {
            0xF8F8F2E01848E39FULL, 0x8EA5898A7F63049BULL, 0xD23D721581D7EE96ULL, 0x2B4BF81799934134ULL, 
            0x039BBD832151AA40ULL, 0xE36163A412ED1BE0ULL, 0xC75ACE711A738A1DULL, 0x5B700A038D59FEA6ULL, 
            0xF195D1701FB5D4F2ULL, 0xAB0D1ADE08D19ADFULL, 0x730B96075A9F90B9ULL, 0x1B8C6992C3270DABULL, 
            0xE686B6CB97735A90ULL, 0xB3F607674480B604ULL, 0xF648C65203BAAC89ULL, 0xF0E9F9A0136558F8ULL, 
            0xDA22EB6AD94D52A9ULL, 0xAA08442EFD19F795ULL, 0x125EAB4CE28FE28CULL, 0x2CD5981C9F46B153ULL, 
            0xDBDC5A5B8BEC7FAAULL, 0x3965DD36D01867ADULL, 0xD572163174DB6525ULL, 0xBE03C58B53EF2855ULL, 
            0x936B10CC8B0350D8ULL, 0x8FEF6650BCEAC0F0ULL, 0x574161BF39BDEE01ULL, 0x036A71C3D801F3F1ULL, 
            0x1FF597B26E129AB8ULL, 0x47637B8E6664A8CBULL, 0xC5FF25E02C2A3141ULL, 0x1B996817FEEB0372ULL
        },
        {
            0x507D90E6EEFCCBE6ULL, 0x80653CD07C9A2D4FULL, 0x04AC28B8EB3B3C65ULL, 0xE579B7251A8704FEULL, 
            0xDB200DBCC06D30D1ULL, 0x2C5D5995AFA522B2ULL, 0xE0C27136EAC3F1ECULL, 0xE106F31F89FF76A7ULL, 
            0x3B8997719208D6BFULL, 0x2D009507E23CCEF1ULL, 0x47395D637B3BA930ULL, 0xDBA73B35E6E6229BULL, 
            0x224D39C0CDC69666ULL, 0x48AFD56099E49ED4ULL, 0x62AF23E7B8D0C860ULL, 0x377D722F6AB06535ULL, 
            0x2D80F5447DE4D590ULL, 0xC57B2057C1D259DAULL, 0xC613AC94A4688EDBULL, 0x8B093B69BE61F144ULL, 
            0x708C53D7BEBF08EEULL, 0x6313D37222C86D7AULL, 0x52180AD00CC10147ULL, 0xBA1044E2C2F1423FULL, 
            0x18841625A8F490DDULL, 0x88FB565D88D14FD0ULL, 0x22E43C7911CD86A7ULL, 0x165647C62D794831ULL, 
            0x2DA261D2705AAA0BULL, 0x0786D7250CE0108FULL, 0x9AC79728F30058B8ULL, 0x7D8A4A5280F4C691ULL
        },
        {
            0x366A2822B81A622EULL, 0x34D320439B13206DULL, 0xA447B78E4627E296ULL, 0xB2B65BCFD4B23BF4ULL, 
            0xB3B74F10C09197F5ULL, 0x29D8EA356004878CULL, 0x82485557A51C14AAULL, 0x05FC441A5CA39BDEULL, 
            0x227CDFBD56BE7D22ULL, 0x52582F20A41B8FE4ULL, 0xC7D9776401195D30ULL, 0xFC3642521E373544ULL, 
            0xADD1A138D9370439ULL, 0xC8061DEF2AB90438ULL, 0x9FB8B45640B8B400ULL, 0xDFB2DE993B19F6CBULL, 
            0x971EE39C6FF746CFULL, 0x9DBDE30FF077F6EAULL, 0xA1B05A1646360A3BULL, 0x604BAAA4ADC90A77ULL, 
            0x0CDC01FB57DC9FE4ULL, 0x6935D95ECDB72A4BULL, 0xB2A25D17FB4DBFC4ULL, 0x07FA0E5581FD787AULL, 
            0xC94B59E847E8BCE5ULL, 0x1429B571389ED006ULL, 0x0A79B2EE70F08E19ULL, 0xBD55A6573FF91C39ULL, 
            0x93419D4341A6A76AULL, 0x7FE5952590F12F92ULL, 0x7EF1E03ED49102D6ULL, 0x6A6D344BA004CDF9ULL
        },
        {
            0x7CC6EBDC9B4E7123ULL, 0x0AA5733B8075120CULL, 0xB45B67C988D04C97ULL, 0xDFEE0A83F413CFC6ULL, 
            0x27321E8C89382458ULL, 0x2B7A8538002C8E61ULL, 0xC185E1820F66DB98ULL, 0x3F2D20AE98B08976ULL, 
            0x7807E6EBA8928E5BULL, 0xB2DA19A13EA132AAULL, 0x4706CBFB320C511EULL, 0x7D35CD6E2EB4071CULL, 
            0x5EF4BA3B7FDCAA31ULL, 0x9BDB0CDB5396E915ULL, 0x7B7F017042C0F931ULL, 0x72B0054E57FCCE7FULL, 
            0xEDA0D2D1B1033BD9ULL, 0xB5917E86A959EFEFULL, 0x2BF0156A8BB3A7F0ULL, 0x57C34F4DFA50202BULL, 
            0xDDD1F230F0BFF38DULL, 0xEEB06BCF25512C1FULL, 0x1B47FC1D0E6C0E22ULL, 0x3E82476138297CF3ULL, 
            0x5F01629C62836BF1ULL, 0x05B471EC62AF2965ULL, 0x944EC4226A4F348DULL, 0x5335458722911FF5ULL, 
            0x0E2E957003EB9831ULL, 0x229F177626363BD8ULL, 0x59D7013DD7BDB9F6ULL, 0x7983F9410FEADA4CULL
        },
        {
            0x21A38B00DEA316DDULL, 0x19194F276DF49501ULL, 0xAAA1B27F5DAD130EULL, 0xCD718A5AB4EC0FB4ULL, 
            0x162BD16734EC18FEULL, 0x36252C2E23217D92ULL, 0x0A63142F778F8B61ULL, 0xD7173CA28ECF2439ULL, 
            0xA910FFB455FF0069ULL, 0x654C50B35528BA8AULL, 0xD51E0C6298F7B625ULL, 0x5F39A6BCE7EC8219ULL, 
            0x32AE8059688025B9ULL, 0x1F29ADC3E2F5CE4BULL, 0x877B0E5C906A584CULL, 0xF6C2B027C3720666ULL, 
            0x660C6BBF4D5996E4ULL, 0x1C3DE7DD4EA15A83ULL, 0x891CE995F7143139ULL, 0xACD09C6F11DD493FULL, 
            0xBE22F5AA9BF88830ULL, 0xB46782D426619201ULL, 0xAB59C269840AEAFDULL, 0xEC7F4C1894CCA38EULL, 
            0x3E85C7393F767B50ULL, 0x580238486C84456AULL, 0x8235BBC9408FEA3BULL, 0x1BCD0E45128EB72EULL, 
            0xEAD44E9163F52AADULL, 0xB600A043EF10634BULL, 0x92CBFEC099B05863ULL, 0x723DAE2C03D743E0ULL
        },
        {
            0xCFFF07277169B15BULL, 0xB87718C8266652C1ULL, 0x9A1CAA8ED4A172A9ULL, 0x399E9AFD158042A6ULL, 
            0xA405D666678EF4F1ULL, 0x76EB8D5CB88C7220ULL, 0x37F13E3EF210766EULL, 0x810E56A4FE2A212EULL, 
            0x5BEC652F7FF1E7A8ULL, 0x33DE6DA5002DEA85ULL, 0x6EFFD4C2B41796A2ULL, 0x91B02B3568F42963ULL, 
            0xF2766242F5778E7AULL, 0x26EE875E79DAA2B4ULL, 0x4BFAB45DF43B6AF7ULL, 0x890CCE4A0DA6B8D2ULL, 
            0x2410FDADE74B3178ULL, 0xD46E992CB83AF11CULL, 0xB85DED22D9C2553CULL, 0x3176258F8D8D4339ULL, 
            0x8C329716D55A340DULL, 0x5665F50017D93766ULL, 0x3A7B5680A7E2BD26ULL, 0x392651494E432BA3ULL, 
            0x82982E1AE77FEC4BULL, 0x345F970770C2E664ULL, 0xD41457C95B57527BULL, 0x41C79B1109ECBB92ULL, 
            0xF4F004255F4C638AULL, 0x6FCFDC302F13EDB8ULL, 0xEB64CA30CC20E6DCULL, 0x7E616E46FE6B752AULL
        }
    },
    {
        {
            0xF8B38BA4F4599C6FULL, 0x2E5AAC5AAC6362D4ULL, 0x4E6D7D8DCDFE5D3CULL, 0xCA9D63F551AC2E2CULL, 
            0x34B1ED2C1106F8C2ULL, 0xAB12509FDD26FB4BULL, 0xB0AA3CB5BF801521ULL, 0xCF968A8310315F25ULL, 
            0x87603C24840F1A84ULL, 0x3FF1B75BBBC5DA27ULL, 0x64DDFFADAE98BCC9ULL, 0x649D28FF97181E93ULL, 
            0xD3B0A77261702C32ULL, 0x81DC80E7FD8CD4A1ULL, 0x6D3CF1D77CE37AE1ULL, 0xCCDEABCA99784B92ULL, 
            0x3404302092895E4FULL, 0xCA99B739A8CD31B2ULL, 0x1504790DBB8A7DB1ULL, 0xD67C97241E802B63ULL, 
            0x5B8B6CA69DCA76C1ULL, 0xA6B1AFC3168579C0ULL, 0x127D12F1F3D7D360ULL, 0xB941441BCAB87353ULL, 
            0x1A2FE1DF81A2BA50ULL, 0xB6812408FC3B2E7EULL, 0xA72D373C59BA510BULL, 0xAE2546C8A5B648F6ULL, 
            0x6C051D86F7356C7CULL, 0x83DE04E492FE1A49ULL, 0x82F4E2C09F6B5F16ULL, 0x7FDF9EFDD6F343E5ULL
        },
        {
            0x6231A2EFE96CE315ULL, 0xF971B9241FC2864EULL, 0x722B6089E0856344ULL, 0xC97A0B5F950606C3ULL, 
            0x1E2CAEF5826B4795ULL, 0x45A804F3F392E761ULL, 0x2EE8AC64B36A72FCULL, 0x741B0A3098203A08ULL, 
            0xA49ACCF30BBFDFDEULL, 0x473ED4B97DAE9960ULL, 0xE1DC81B34267842BULL, 0xC4E12F7C0F0560F7ULL, 
            0x9CBE632CC9EEA101ULL, 0xF800F6ABBCE0CA9EULL, 0x0BFBD3AA0F47612BULL, 0x39F358B28F3F93F8ULL, 
            0x9A598B4709ACFDA5ULL, 0x5A9BBC57D4D6C798ULL, 0x7AA13F03354A3957ULL, 0xEE57711A4FE34431ULL, 
            0xC8230C0AEDBEAA10ULL, 0x6E1F409159C6F9B7ULL, 0x07A49D3A98B8AEB6ULL, 0xD279CDE444B0DF70ULL, 
            0xBC3E5332BCBC2EC7ULL, 0x41F0F661586533EAULL, 0x5594C6A01071B765ULL, 0xB629AA69FE4C3EF2ULL, 
            0x3B8630F0E1FF68DBULL, 0xCA799931CEB95322ULL, 0xECC2F10A98B25ECAULL, 0x61F5E762761F6AD9ULL
        },
        {
            0xDC800F9791DE8CABULL, 0xF800C8074A937EC0ULL, 0x4A587596A60631CFULL, 0x1E9A19C6BA3CAE54ULL, 
            0x68CBB4A1C5219C44ULL, 0x747A71A86AC784A7ULL, 0xD93DF2CA28F26B55ULL, 0x178138D4FBCB64BCULL, 
            0x162CE96890BACFD3ULL, 0xCF61C7A725D6694CULL, 0xFB6C2D2AE62237D2ULL, 0x317B34C20481477FULL, 
            0x7D81039EB1F5C53FULL, 0x1EF3ABA12628C150ULL, 0x3D47AE99B9E39182ULL, 0x93D9D4120795260BULL, 
            0xB3F521462D9CB529ULL, 0x2749B2DFBBA987CAULL, 0x8DFEFEC0571B65FAULL, 0xCD2C6A95058A9D2AULL, 
            0xC29F84D46538FA46ULL, 0x8A88AE0195FBE239ULL, 0x142BD8145D6F7ADAULL, 0x09E9E5CAA90175C3ULL, 
            0x03FC74DBB19876ECULL, 0xE02EEFEB36C8200CULL, 0x52CE78333059561EULL, 0xB74A611D5043C61CULL, 
            0x27F1EF2A7B64F251ULL, 0xFB0942A419FAF2C6ULL, 0xB9FE904C6DB51067ULL, 0xA95C881005AA75F9ULL
        },
        {
            0x15673E832C90FFA2ULL, 0xD055E33BB0EBB0ABULL, 0xF0159351507E52C1ULL, 0x6A52474C0492F99AULL, 
            0xE5FD78066790F6C3ULL, 0x9DBB22C96F62DCEFULL, 0xEBD0F801CBC74AD1ULL, 0x9D3D7F2BDABA9D11ULL, 
            0x4E62630DAC985B01ULL, 0x86B93710A47B29BBULL, 0x716CA388D4D425A3ULL, 0xC0E9B76E2EE13636ULL, 
            0xC6B6D9DB61FF31BCULL, 0xD5B2BA0069FBD2DDULL, 0x06EF9E4F658C3570ULL, 0x52032E3EF9D989F5ULL, 
            0xBBB96C6F4228D40EULL, 0xCE26432FCBD2E1E4ULL, 0xE544E01A798FAAE4ULL, 0x6C0D4E1AC97ECF8EULL, 
            0x7626C1F77490A27DULL, 0xD4418BB02B3135E0ULL, 0x6F67EA2F9B85D772ULL, 0x14D254D34E6D7879ULL, 
            0x6CBE04AFBD2CDDB3ULL, 0xB0C728CB3F1AAAF1ULL, 0xACF44DC44F81754FULL, 0x39419B20D3597529ULL, 
            0x0CAA2C2F582E1CF3ULL, 0xA4CBF71A62144586ULL, 0x04CA55052771C9A4ULL, 0xF7DEBB7ADE266119ULL
        },
        {
            0x30BCBCB45C254A6FULL, 0xABDE4354E6C2CCB2ULL, 0x624546E8FBA098A3ULL, 0xA68D1D2C1B17447BULL, 
            0xF8DC4E55B2043CB7ULL, 0xBA7586E2CFBAFD92ULL, 0x41F1E516B5AC5C22ULL, 0x04D5DA2507263C91ULL, 
            0x8CD0DF4878C052A1ULL, 0xD241FBBB5477821BULL, 0xC5D8E2E18B42D00AULL, 0xA9A3B1E768554548ULL, 
            0xDBE05C6704FF59E7ULL, 0xFE74C26F99853DB7ULL, 0x49EBB4DB6156BAB0ULL, 0x190FB0CD19D7B48BULL, 
            0xE6E689708ADE951FULL, 0xFAD607DC21276461ULL, 0x0F3945E8F52CE250ULL, 0x923CC3188BB25FDAULL, 
            0xE8203D6978FA3046ULL, 0xAA0349A8D7FD7145ULL, 0x08A948ACA1654BE2ULL, 0x80FC760D96E39A9DULL, 
            0x3A6B768FF651146CULL, 0x35B3B410ECBF4950ULL, 0xD3FF727407BF6281ULL, 0xE641BFA0E76A45ABULL, 
            0x6254D35B2198CDD1ULL, 0x341FE8052C51796DULL, 0x1A2FDEBFBC965EC3ULL, 0x1032B409E042735FULL
        },
        {
            0x66E2E8564FE35388ULL, 0xAEA482E03CCA30ACULL, 0x5D0A7DE973AEB96BULL, 0xDA38F17D575976CEULL, 
            0xB87124B9312CFCA3ULL, 0x263BE7BB537207DEULL, 0x5F26069561DD4698ULL, 0x1F634736D3CF4A97ULL, 
            0x12929D40D15AE5EEULL, 0x76A57CD450F7AFD7ULL, 0x3D3D604F8560C6AFULL, 0x3D36C4D8A242C407ULL, 
            0x5564C9A60CC6F3C0ULL, 0xF8D018DCA4117583ULL, 0xAF1444024BF3B718ULL, 0xF9867DDAC623F9D9ULL, 
            0x862DD8F6DCD8F169ULL, 0xA5149EB8AD9425B2ULL, 0x1896101A2456FBAEULL, 0x98C8A429C8039074ULL, 
            0x0FC26484988AF6D4ULL, 0x13A946E877D62EA1ULL, 0x915D3DE1313562CDULL, 0xF60698736918EA59ULL, 
            0x4DA2F43327514D1DULL, 0x950AB763E8DE6732ULL, 0xF8C139855CB460D0ULL, 0xA79956DF5F4A93B9ULL, 
            0x3F087B7C906DE553ULL, 0x10B74EC769AF9491ULL, 0xB07E06EC54BF59B6ULL, 0xB97E5E367040DC14ULL
        }
    },
    {
        {
            0x1D98B25AE3E77DACULL, 0x59B54B34EA6A4EC6ULL, 0x96657C4ECF64C09BULL, 0x6060239614A76963ULL, 
            0xB0AB479DC848E7CDULL, 0xC8A6876D04DB99D1ULL, 0x7F669091B9FCFDD9ULL, 0x5844CA0E36B174DEULL, 
            0x16A7171DB672DC16ULL, 0x1D7540381C1FEE3FULL, 0x1D1E94995D1E2E69ULL, 0x8853ED55B1E1AF58ULL, 
            0x4C4020C963031031ULL, 0x3985D658AAE1A9EBULL, 0x62ECCD23F1BC091BULL, 0x4CE8F2C3C1698BDDULL, 
            0x60AA313E4F44A7CCULL, 0x72B07FF12DA6341EULL, 0xD6282950389B6182ULL, 0x6B974BDF8E21A16EULL, 
            0xAC24E39BE6CBFC64ULL, 0x44976BF02A75FEE6ULL, 0x3AE456C2422EF395ULL, 0xF7B84BBC12FAA480ULL, 
            0x819BE5902C8085E7ULL, 0x3B31C9DC729049C5ULL, 0xD79DC10FCF906F7FULL, 0x52696DDD615C3AB2ULL, 
            0x52DD1426C0E3D369ULL, 0x087691D781292519ULL, 0x5DBE6C46024042FBULL, 0xF19CA5C94602B634ULL
        },
        {
            0xD666EF9C60E057B8ULL, 0xB03F1E3D31FEBD63ULL, 0x142C607B9E0D0310ULL, 0x999EB97777552208ULL, 
            0x60ACB012527AE49DULL, 0x368C421E798763CBULL, 0x893D35E6D77E52D2ULL, 0xD3EE409EBD41BFE5ULL, 
            0x2965457B3236EA2FULL, 0xD0EE35BABC5B748FULL, 0x843C2D9AA506CEEFULL, 0x3ECD06CA136E304DULL, 
            0xCBCA02F969DC7B45ULL, 0x0E83CFD83EB79A62ULL, 0x7A2C3C4CB9210F71ULL, 0x7E4155835099A3D7ULL, 
            0x7CC5E4EF4510D197ULL, 0x69A3ED1945C396B0ULL, 0xBE42DC527219475FULL, 0x2D1486763B06C068ULL, 
            0xC2A2D8B7681CDB95ULL, 0x31F0DA5730388066ULL, 0x241FA3EBB225F2FCULL, 0xF7D956C841802E6FULL, 
            0x3BDBB54C4B38C9EFULL, 0x94949267316D67B3ULL, 0xB9526E50A552FB10ULL, 0x3BE6F5AB036F1A96ULL, 
            0xFC2D94D961CB2974ULL, 0xAF2D44FF0FE28890ULL, 0xF2710F6F4D4BA456ULL, 0x40AAC1F402BF88D5ULL
        },
        {
            0xC5D273746F2F23DDULL, 0xCA8AE4BC7A693AECULL, 0xA1A9FC19870F07CBULL, 0x65EFB392001FAD7EULL, 
            0x6500764D722936CDULL, 0x2693AF035719B5A9ULL, 0xED87A67643D81C63ULL, 0xCFE8534C41513EB1ULL, 
            0x971B0569C28A404DULL, 0x8AFF94AB77641D8AULL, 0x2EF0FCB67F8DC0F2ULL, 0xE6F5F7D473F58E40ULL, 
            0x7964146D59D6DE05ULL, 0xBDEE01FE3F21A09CULL, 0xC12636F298738B60ULL, 0x9BEB5CA7AF9F1E7CULL, 
            0x75C81369ABCEF80DULL, 0x1CB67F3BB16718C5ULL, 0x80893347BC28C9D6ULL, 0xB1243D894D6C7A90ULL, 
            0x3EF5D33942F3EF82ULL, 0x9736D87207962CD8ULL, 0xB38B6CC2F7AF2F19ULL, 0xFF693AC0C1237ED0ULL, 
            0x31C5B261DAF5FCE1ULL, 0xEC92A5BB1F54D567ULL, 0x755AA3FD87BF3ABFULL, 0x5F78C29347EA9823ULL, 
            0xD4E943C961657E5DULL, 0xD562EDCC50BD9264ULL, 0xB2492BCA8236097CULL, 0xB0EE0F30597A0CFCULL
        },
        {
            0x6E33F3CC4DDC6C8EULL, 0x267C25B448BFA012ULL, 0x5BB3F2AB6372E1D5ULL, 0x7FBEE49DD961478DULL, 
            0xAD725724F5E43C3EULL, 0x0B6B6CEF4B16906AULL, 0x2C200EB39B2B6F10ULL, 0xA07695FEB568FEA5ULL, 
            0x9F15D46311D67B80ULL, 0xE0B7185AB5D10191ULL, 0x5A1417FA6A5CFE26ULL, 0x749BFC047446DA76ULL, 
            0xAA0BA612909C8B16ULL, 0xFCD680D619D055A9ULL, 0x2ED4CF867F4BBC07ULL, 0x8B8B37FF338156D9ULL, 
            0xE06BE36BBFEC4C22ULL, 0xE84775504FFF5E1FULL, 0x0409BF4EDA8443A2ULL, 0x089FAACBBFD50AF5ULL, 
            0x70FC6A08BD52BD02ULL, 0x351C683036AC73FFULL, 0x8E6535195A280C3CULL, 0xFBD9A05DC5657928ULL, 
            0xC67CABF7A9E4133FULL, 0x932D6CFC3FCEE205ULL, 0x71DA5D189104B0A1ULL, 0x87588BB290534E0DULL, 
            0x87FFBB4863406F5CULL, 0xC0ED2E3DC170E51BULL, 0xD5E6B24A21182DA0ULL, 0xBBE653BCA5AD7695ULL
        },
        {
            0x6418CDF4B2DD438FULL, 0x0BC7E3D5FAE6A815ULL, 0x5B2B28279DE61E95ULL, 0x2CD551FFCFEB8566ULL, 
            0x313009E4F8594123ULL, 0x4F7B148863B0DCEFULL, 0x0DF1466AEF389C18ULL, 0x55503CCEAD251FE9ULL, 
            0x2E5EB8586E0C99B8ULL, 0x6815244666EB9355ULL, 0x2480BFC7FC07F783ULL, 0xF6DD295E41B66291ULL, 
            0x8EED9DBE05E02938ULL, 0xFDD475468413AE6FULL, 0x31C9883AA772DCA1ULL, 0xAFE61EB5308131CFULL, 
            0x2A155595B2013762ULL, 0xE09E78BC28090D8DULL, 0x48E5D07666687B99ULL, 0xAB828D658B505CB0ULL, 
            0xC90781AC7F32C2B7ULL, 0xDE29619EE31599FAULL, 0xFBD0A7E427E181FAULL, 0x700914B9DFFC1FCBULL, 
            0x9066E0A046A1EC22ULL, 0x74BACB18EF570247ULL, 0xA9D87D7104BE659AULL, 0xE7FE06142098DA59ULL, 
            0x62765A60250FD556ULL, 0x9FD973FF53628BB6ULL, 0x696DAD5753F6B3BFULL, 0xEB0A738880075969ULL
        },
        {
            0xBA76900205556E3EULL, 0x2EE36A3EDF787716ULL, 0x9B995C49C0728E34ULL, 0x833F327928A32C22ULL, 
            0xE99E8628C4C485EFULL, 0x06EC418DA809AF24ULL, 0xC4963170F8536FE5ULL, 0x2764441FBDEF5BC4ULL, 
            0x989E162DC3464E5FULL, 0x397ED711649FD83DULL, 0x652DA1C6DEFF78B3ULL, 0xEA605580988753F4ULL, 
            0x99CE01E90670408CULL, 0x8C9B3C46B5C4CA66ULL, 0x769DDE16842205C0ULL, 0x9FE8BFAFF6EBC06CULL, 
            0x4C9758C4467A2E88ULL, 0xF456BC70D45FE4B9ULL, 0x09C97E2DFECA7577ULL, 0xE10C2BAD27CDB108ULL, 
            0xBA86CCB353B8FD72ULL, 0x9D1C89D0E30E7062ULL, 0xE2D58F65AF822EBDULL, 0x26BC405DB5F50970ULL, 
            0xDD5846F1A0EB54A2ULL, 0x86AE23DC19CF5414ULL, 0xFA18C7DF5D910D51ULL, 0x76DEA4B0A80E6C7DULL, 
            0xBF698D76F490C6ECULL, 0xD7048A8C24C005CFULL, 0xE2FDA391493ED701ULL, 0x8E22F41F5E8353F8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Ankaa::kPhaseDConstants = {
    0x507CD428BFB0A0F8ULL,
    0x16118E0B7994E1DFULL,
    0x51F26134AE80DEFFULL,
    0x507CD428BFB0A0F8ULL,
    0x16118E0B7994E1DFULL,
    0x51F26134AE80DEFFULL,
    0xEAB788A209462053ULL,
    0x66B3C9138CB0665EULL,
    0x0B,
    0x06,
    0xBD,
    0x89,
    0xB4,
    0x6F,
    0x9F,
    0xE9
};

