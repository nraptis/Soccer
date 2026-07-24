#include "TwistExpander_Saiph.hpp"
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

TwistExpander_Saiph::TwistExpander_Saiph()
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

void TwistExpander_Saiph::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA82C94A4976BA6BFULL; std::uint64_t aIngress = 0xA223B704B5C6E1CFULL; std::uint64_t aCarry = 0x9F4F486F29D57963ULL;

    std::uint64_t aWandererA = 0xF25D3C5E6F48C54FULL; std::uint64_t aWandererB = 0xC6E570AD475EFA78ULL; std::uint64_t aWandererC = 0xF29BF23382BB50C8ULL; std::uint64_t aWandererD = 0xE3CC7D365B8F64ECULL;
    std::uint64_t aWandererE = 0xAB993A8B8F2A1FB2ULL; std::uint64_t aWandererF = 0xEE680BC81CF5844DULL; std::uint64_t aWandererG = 0x8D844439F9DA4AE4ULL; std::uint64_t aWandererH = 0xB35D99229A7E72FEULL;
    std::uint64_t aWandererI = 0xC8DE8AC1A5811CCCULL; std::uint64_t aWandererJ = 0xFBD1C1D1243137ACULL; std::uint64_t aWandererK = 0xE8D82DF72C073D76ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xA8BC2DC2705E5162ULL;
        aCarry = 0xD2E6AA8DEE9FCD1EULL;
        aWandererA = 0xB434154FA803A137ULL;
        aWandererB = 0xACFB3E41ADB6BA00ULL;
        aWandererC = 0xF4CFE56AA34A110BULL;
        aWandererD = 0xB56E9FA42E90AB8CULL;
        aWandererE = 0xE4696DD3B2093B7FULL;
        aWandererF = 0xBB78A0B1958F72AAULL;
        aWandererG = 0xF11451DEC5A0D9CEULL;
        aWandererH = 0xD76AA13854C9888AULL;
        aWandererI = 0xB93C870415413103ULL;
        aWandererJ = 0xD3E0B609D851254DULL;
        aWandererK = 0x8C7B390372DF71F4ULL;
    TwistExpander_Saiph_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Saiph_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Saiph_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Saiph_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Saiph::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD3B17C98811EBD05ULL; std::uint64_t aIngress = 0xC9BE383FEB179E95ULL; std::uint64_t aCarry = 0xD980D008526202D4ULL;

    std::uint64_t aWandererA = 0xE3CBE77F011C847EULL; std::uint64_t aWandererB = 0xA0E74B6F0EBEA69AULL; std::uint64_t aWandererC = 0xA975589BF7075049ULL; std::uint64_t aWandererD = 0xB1B92F18F231FFEEULL;
    std::uint64_t aWandererE = 0xD26986AAED76FBDAULL; std::uint64_t aWandererF = 0x9DE8DD2B41EAAD4FULL; std::uint64_t aWandererG = 0xA47BCB3EB7740D7AULL; std::uint64_t aWandererH = 0xC1D8ACCBAA9FF8C7ULL;
    std::uint64_t aWandererI = 0xA2EA1DF1D941B1F4ULL; std::uint64_t aWandererJ = 0xC59A1E61B1A59414ULL; std::uint64_t aWandererK = 0xD0624C4AEFA64A1EULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xF8E85B4AB62A46A2ULL;
        aCarry = 0xED71721C91AB12DEULL;
        aWandererA = 0xC5A52C4C375F23A7ULL;
        aWandererB = 0x8FAE51C4C87BB793ULL;
        aWandererC = 0xE47DA63C1147396EULL;
        aWandererD = 0xCAED203FC24B8715ULL;
        aWandererE = 0xDD26E56428926037ULL;
        aWandererF = 0xBE5A53A796C8DA34ULL;
        aWandererG = 0xC772D23BD8374842ULL;
        aWandererH = 0xA6DF92B944F0F5DAULL;
        aWandererI = 0xA974C345E0AD5065ULL;
        aWandererJ = 0xBDD1124DB34CD087ULL;
        aWandererK = 0xD268784D68408557ULL;
    TwistExpander_Saiph_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Saiph_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Saiph_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Saiph_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Saiph::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD1D7560F47FA3195ULL;
    std::uint64_t aIngress = 0xE95EE0BE967DCC03ULL;
    std::uint64_t aCarry = 0x8B318FFAE3FAE677ULL;

    std::uint64_t aWandererA = 0xF0904ABF78A3C48EULL;
    std::uint64_t aWandererB = 0xCB9CC4269C68DB0BULL;
    std::uint64_t aWandererC = 0xA8E2EAAB3BD2F249ULL;
    std::uint64_t aWandererD = 0xF2383B3148321B53ULL;
    std::uint64_t aWandererE = 0xEACE9376EED5A63AULL;
    std::uint64_t aWandererF = 0xEE937E761D56D0AAULL;
    std::uint64_t aWandererG = 0xD8BF71CDCDF4B70DULL;
    std::uint64_t aWandererH = 0xF39B0B7974B46739ULL;
    std::uint64_t aWandererI = 0xB24523123B8D3798ULL;
    std::uint64_t aWandererJ = 0x952B098D197364A8ULL;
    std::uint64_t aWandererK = 0xE63A1E265E1F5677ULL;

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
    TwistExpander_Saiph_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Saiph_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Saiph_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Saiph_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Saiph_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Saiph_Arx::Seed_F(pWorkSpace,
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
    aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixSelectA;
    aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixSelectB;
    aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixUnrollA;
    aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixUnrollB;
    aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixArgA;
    aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixArgB;
    aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixArgC;
    aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseDConstants.mMatrixArgD;
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
    TwistExpander_Saiph_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Saiph_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Saiph_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Saiph_Arx::GROW_B(pWorkSpace,
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

// SmartSquash candidate 30 of 33
// Exploration cases: 100000000
// Nearest-family diversity: 915 / 1088 (84.10%)
// Total distance from earlier candidates: 27092
void TwistExpander_Saiph::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    static_assert((S_BLOCK / W_KEY) == 16, "SquashInvestToKeyBoxes expects 16 invest fragments.");
    static_assert(H_KEY == 8, "SquashInvestToKeyBoxes expects 8 key rows per box.");
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 6U), *aFragmentB = aIceLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 8U), *aFragmentD = aIceLaneD + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 13U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1979U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1088U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 991U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 12U), *aFragmentB = aIceLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 1U), *aFragmentD = aIceLaneD + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1676U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 479U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 861U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1621U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 7U), *aFragmentB = aIceLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 0U), *aFragmentD = aIceLaneD + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 864U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 79U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1032U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1739U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 15U), *aFragmentB = aIceLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 4U), *aFragmentD = aIceLaneD + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1280U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1938U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1608U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 481U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 8U), *aFragmentB = aIceLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 2U), *aFragmentD = aIceLaneD + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1405U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1211U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 705U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 159U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 1U), *aFragmentB = aIceLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 9U), *aFragmentD = aIceLaneD + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 607U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 869U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 15U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1162U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 2U), *aFragmentB = aIceLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 5U), *aFragmentD = aIceLaneD + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1411U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1340U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 865U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 204U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 13U), *aFragmentB = aIceLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 14U), *aFragmentD = aIceLaneD + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 540U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1352U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 677U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1719U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 4U), *aFragmentB = aIceLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 13U), *aFragmentD = aIceLaneD + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 992U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 361U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 731U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1491U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 9U), *aFragmentB = aIceLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 12U), *aFragmentD = aIceLaneD + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1573U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 172U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1721U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1451U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 10U), *aFragmentB = aIceLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 15U), *aFragmentD = aIceLaneD + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1469U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 496U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 916U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1859U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 0U), *aFragmentB = aIceLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 11U), *aFragmentD = aIceLaneD + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 589U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1046U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1147U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 32U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 14U), *aFragmentB = aIceLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 6U), *aFragmentD = aIceLaneD + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1785U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 851U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 196U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1055U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 5U), *aFragmentB = aIceLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 10U), *aFragmentD = aIceLaneD + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1992U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1948U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 410U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 9U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 11U), *aFragmentB = aIceLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 3U), *aFragmentD = aIceLaneD + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1572U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 636U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 632U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1462U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 3U), *aFragmentB = aIceLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 7U), *aFragmentD = aIceLaneD + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1466U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 801U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1550U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 247U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Saiph::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xC254725A6065C79FULL; std::uint64_t aIngress = 0xD88B836D3C8AF8A6ULL; std::uint64_t aCarry = 0xC0435F01D6A6A91DULL;

    std::uint64_t aWandererA = 0xA57F4126B385E8CDULL; std::uint64_t aWandererB = 0x887BC8D609582057ULL; std::uint64_t aWandererC = 0xDD692199AF07FEB0ULL; std::uint64_t aWandererD = 0x9E176706616ED127ULL;
    std::uint64_t aWandererE = 0xDE4ACDC419D43A30ULL; std::uint64_t aWandererF = 0x840B9838BD737A21ULL; std::uint64_t aWandererG = 0xA8AF5A4DE0B2DF3CULL; std::uint64_t aWandererH = 0xC36A766A4F8AC592ULL;
    std::uint64_t aWandererI = 0xA1B839A344FF387EULL; std::uint64_t aWandererJ = 0xCF1F47DC25660A42ULL; std::uint64_t aWandererK = 0xD4865BDE4B4A6D5FULL;

    // [seed]
        aPrevious = 0xE9D43DAFEADB1D7FULL;
        aCarry = 0xA59C2783AEBAC62EULL;
        aWandererA = 0xA191808035E27EB3ULL;
        aWandererB = 0xB28D70313673B5BDULL;
        aWandererC = 0xC8C54EB2FBD24755ULL;
        aWandererD = 0x9E970586BCEBC886ULL;
        aWandererE = 0xF4D202551D49CC15ULL;
        aWandererF = 0x8995C2190982204BULL;
        aWandererG = 0x9364878AA4F86D0FULL;
        aWandererH = 0xCA29FC51F9B8AD96ULL;
        aWandererI = 0xA36453227C7318AEULL;
        aWandererJ = 0xDD669B20EDB791B6ULL;
        aWandererK = 0xC35BD58BDDDE105FULL;
    TwistExpander_Saiph_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Saiph_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Saiph_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Saiph_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Saiph_Arx::Twist_E(pWorkSpace,
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
    TwistExpander_Saiph_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Saiph_Arx::GROW_B(pWorkSpace,
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

// GrowA candidate 30 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 15675; nearest pair: 468 / 674
void TwistExpander_Saiph::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6076U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1000U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6377U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4418U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5643U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 142U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 23U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4754U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 425U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5793U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2095U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1424U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5592U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1712U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2552U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3904U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1838U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 574U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1634U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1786U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 907U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1773U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 345U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 277U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1992U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1965U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 613U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 201U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1344U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 844U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 632U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1472U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 155U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 89U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1125U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
}

// GrowB candidate 30 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 15658; nearest pair: 465 / 674
void TwistExpander_Saiph::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7146U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5329U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5346U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3753U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4680U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5456U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7027U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 853U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7816U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5639U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7765U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1616U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1527U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4615U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4168U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7031U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 169U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 322U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 154U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1683U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2043U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 325U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 862U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1714U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 367U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 197U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 817U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 766U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 306U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 262U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1818U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1419U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1696U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 835U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 962U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1428U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
}

const TwistDomainSaltSet TwistExpander_Saiph::kPhaseASalts = {
    {
        {
            0x46ABC9F381628BF1ULL, 0x90E46E9FC92DD267ULL, 0x0D0CD0C60A558F57ULL, 0xBFDF8249CFCDCE78ULL, 
            0x58F75C088F240595ULL, 0xD5A9FE85BDAAA7C5ULL, 0xE02B76BEFCA06CBBULL, 0x0C626869BD16D437ULL, 
            0xA5F61794D0889091ULL, 0x853B2D0C2B9BBD51ULL, 0x0346ECD5FF43DD5CULL, 0x8C56CF779850F954ULL, 
            0xAD81FD2DCF775F21ULL, 0xD67AA346F203A489ULL, 0xEAB3747CC2E68691ULL, 0x77799479E2EB82BFULL, 
            0xF4C5255B6D0F17BBULL, 0x51C129ABC4BAEAE8ULL, 0xD50D0BDB08B12555ULL, 0x7452DDA0AE1563CAULL, 
            0x70CD3A8FA8E9B09FULL, 0x17BF990FA78F38B6ULL, 0xA0417C93B6B85A96ULL, 0xF0609A54350D102AULL, 
            0x191213A2DF47A5E7ULL, 0xFCA5F7E7CE41A08BULL, 0xA4F55B6E2F42CDC3ULL, 0x61AF9E746DD8B609ULL, 
            0xD67838ED2759188AULL, 0x9D9B845254A20194ULL, 0xF8E8A638D9B79C11ULL, 0x3D002431571DD952ULL
        },
        {
            0x0B82EA5E9A2E6F5CULL, 0x963DAC64A8BF1F5FULL, 0xF1B31ABB4F811BBBULL, 0xB143BFBE9D97AC76ULL, 
            0x97F2209A96B092C9ULL, 0x4B15AD868451FAADULL, 0x9B5E301B4964ED9FULL, 0x3F1692CBD8CD0323ULL, 
            0xAC6654D933CB2AB0ULL, 0x407C0DF25D9505B4ULL, 0x493CFFE2B46B181EULL, 0x72132FC47CC17E33ULL, 
            0xD518562C1FD8FE36ULL, 0x9619CF63ED09A249ULL, 0xB59C4975B1531481ULL, 0xE3A6E8D07F0677A3ULL, 
            0xD82C88C572F1871EULL, 0xF90246EBC5A351FAULL, 0x2D5C0E5785B0A926ULL, 0x8F8F0B7619CEE9A7ULL, 
            0x98AE8B3D852104DAULL, 0x5D5244E77389789CULL, 0x5D3C25E438ABA7C0ULL, 0xC1ADD55933649A45ULL, 
            0xB7800C9DE7F29E42ULL, 0xACCB217718B29B1FULL, 0x37AA42B351A3CB88ULL, 0x8F1ABD1D75554BDDULL, 
            0xED914E4A7B3D282DULL, 0x1B62006BD3135B05ULL, 0x4F8115AFDA8DDFD0ULL, 0x959215D913AF3A5CULL
        },
        {
            0xDD9D051334F8064EULL, 0x3471657460F22B1DULL, 0x7C9F62C0FFB0BF28ULL, 0xBB87CC6C1BA071CBULL, 
            0xD9FF152C6943C981ULL, 0x9C6B9F0C9285DA5EULL, 0xEEF2786D01A4DE8AULL, 0xFED841259CE1B972ULL, 
            0xA1677EF10E783528ULL, 0x59CFBA22DD3DC30FULL, 0xC533E074F70507A9ULL, 0xF4EC8520948F82DCULL, 
            0xAE0430B95EDB4344ULL, 0x9361D38AF56F0ECDULL, 0x0A566152DC2B3B0EULL, 0x4B6FE969B66E08A3ULL, 
            0x30A3BBD18C38A375ULL, 0x45047C88EE805A03ULL, 0x3B3B3AEDA4F5CE44ULL, 0xC0443114E3A25176ULL, 
            0x461ABD48C809A442ULL, 0x22B42ED0D45A259AULL, 0x7E266DCF671F141BULL, 0x14D70E55D4F474F6ULL, 
            0x721DAAEDEED55FFAULL, 0xD2FB2EDF0BA6BAABULL, 0x081C3CCF1D25D487ULL, 0x395A0E6D5F775213ULL, 
            0x6575938386F3C83AULL, 0xFF559975C68C640AULL, 0xFE9FB5E6AC6E3321ULL, 0xF90345995D93F81BULL
        },
        {
            0xCEE5CB5B6912DF00ULL, 0x9CAA2BBED45D03F1ULL, 0x3B264B8C69E398D2ULL, 0xA1D7EB8CD56F1125ULL, 
            0x3344F0A02FD0E323ULL, 0x261E584F7C3C9177ULL, 0x4D232CC3813E755EULL, 0xDCBC36F2B690BDECULL, 
            0xD2CE6AF90B6D4E8FULL, 0x67C9A21B207B77F3ULL, 0xD93380FD59957B5FULL, 0xD2A6677341F550F2ULL, 
            0xE2CB61DC7A8A2380ULL, 0x9160B0A652712AE4ULL, 0xC0DBAAA117275E23ULL, 0x0DA26394534A1DAEULL, 
            0x7D7331F99202D989ULL, 0xBCE0D5F24B864129ULL, 0x636456735FE76CE0ULL, 0xE14902CEC6764933ULL, 
            0x6423C5CBC4D13C7DULL, 0x698A6326896D3AC7ULL, 0xC37A922D5B0ADDE3ULL, 0xAD7509A2F4270A50ULL, 
            0x569EA5669833D804ULL, 0x9CF3652472C0B9CAULL, 0xAB3D88C77700AEC4ULL, 0xF40FB7692801F008ULL, 
            0xD376004D3C659119ULL, 0x564FACB905E3F395ULL, 0x0E9139AF6C2549C0ULL, 0xA5FA4152892AEDC5ULL
        },
        {
            0x372DDE8DC9093AC0ULL, 0xE75C02ADC889D0D4ULL, 0xC5D7317F01779490ULL, 0xEC583128BB8AA4D5ULL, 
            0x11C91C068665ABD5ULL, 0x546A7FE8EBA366A9ULL, 0x60EB8FBE15F586D1ULL, 0xB98C21AE5DCFE47EULL, 
            0x9579F9A306BC2220ULL, 0xAB689D312F4007FEULL, 0xF270D02BEE9C3157ULL, 0x036BEA92E6B3A4F8ULL, 
            0xF94B10733F5D6E1EULL, 0x858871708F1D41D4ULL, 0x294F4F8B72778A94ULL, 0xF7CA448A39FD807DULL, 
            0x17407AD2553310AFULL, 0xB6C901D8C0AE5973ULL, 0xDC071A3E59752F83ULL, 0xEBBD888608E965DAULL, 
            0x25A10C7885FFC025ULL, 0xB1654C8B210FA29FULL, 0x4292DF2A8C33D04CULL, 0x0F7948F042CEA641ULL, 
            0x24FCB7AAACCC57A4ULL, 0x090F81C40ED75AEEULL, 0xAF004EAEF54BE6FDULL, 0x0C6581620840648CULL, 
            0x01A8A607BA4F4AEBULL, 0x278C4A298F65AACAULL, 0xD180811F2B821FD0ULL, 0xE204822483096D1AULL
        },
        {
            0x1E09A8F3B40DF857ULL, 0x56FDE79E05756B78ULL, 0x95C36AD3444E680CULL, 0xF90BDBDAA24D2B58ULL, 
            0x2FCCDA8274D75731ULL, 0x447FF77EC2E39026ULL, 0xDE036313F3FFC038ULL, 0x994FC7A5B534DC89ULL, 
            0x4D271CB2717A4347ULL, 0x725706C091E0CA38ULL, 0x8BDECF9B02182D99ULL, 0xFB4A95AE5E8B389FULL, 
            0xF9D8821A3B3FB23DULL, 0x53F1AC64AA1475E1ULL, 0x851AFB5BE365F65EULL, 0x99ADD2BD2412889DULL, 
            0x2A305504EE000DFCULL, 0x0E531B3BF23C13A5ULL, 0xE9084D0466A2A2DDULL, 0xA7541267A57E590BULL, 
            0x7E7A21BC8681B9ADULL, 0x5C6481C5353E24B3ULL, 0xBDC38180956726D2ULL, 0x8D0EB2526AAE3D3CULL, 
            0xB1D3DE78522B94DAULL, 0x7F39931703E60167ULL, 0x5D7804B29722DF86ULL, 0xC58E805FBE4F9986ULL, 
            0xF1D459504DB35640ULL, 0x329D2A4C4A2F3EA5ULL, 0xCD8FD3112CC6AAB2ULL, 0xC1AEA37C86D772ADULL
        }
    },
    {
        {
            0x25DF33FEEFDCBC32ULL, 0xC34B72E0CC854CB4ULL, 0xEF9BB74121D2A910ULL, 0xBD6497D5FC2A5514ULL, 
            0xC1D91204BF8C81F4ULL, 0x66BB9E5676074EB0ULL, 0x4C733AEF1A8778A7ULL, 0xB99B1E537B0B95ADULL, 
            0x006256854A47B03FULL, 0x5533BACF0558FE31ULL, 0x69931EDC473AAFB5ULL, 0xED7131EA7D24828CULL, 
            0x47DD551F1A4FD6C9ULL, 0xB37D0C7CF5FC3819ULL, 0x5DF05D054786D722ULL, 0x246B17A5230F37C0ULL, 
            0x4B8CC49B01BD8260ULL, 0x6F3144614991EE86ULL, 0x04373C10EE1071CEULL, 0x93B91EC7E81C8128ULL, 
            0x94B1C37211D60E0EULL, 0x67479FD63D10FE3AULL, 0x07B51DFD385667DCULL, 0x2C1E918119886ADAULL, 
            0x39FFB60C75849EF6ULL, 0xCF05475898C616D7ULL, 0xECF1DBCAE64B9CB2ULL, 0xCFDB84FCA32C294BULL, 
            0x8D00A82E241BF24EULL, 0xD73C51B5BAB1FA14ULL, 0x76C08631AFBDA196ULL, 0xF743DF8D33EB8B9DULL
        },
        {
            0x8C7E66165E71446CULL, 0xF54BA9A226A51412ULL, 0x8413491811B56260ULL, 0x64E8AF6930F4217CULL, 
            0x7715DE9D9B102428ULL, 0x51C546BD46F886F0ULL, 0x5B63C88897D60886ULL, 0xC5248A82CD6B02EFULL, 
            0x1617B6DE79FC9720ULL, 0x8E3B2D5223FE48F7ULL, 0xC78BC080D3339B20ULL, 0x137CC8B2508D92D6ULL, 
            0x93A773CE955A57C5ULL, 0x842052AA5E3AA245ULL, 0x0421A475E726026BULL, 0x7171661DBBD87513ULL, 
            0xE52A5DBF579E2A99ULL, 0x125D2E80EEDE1F04ULL, 0x11F90246B3456228ULL, 0xBBA98A5F89F7EA94ULL, 
            0x90D4EDCAE781F5BEULL, 0x56BF61FFD32B21E3ULL, 0xD8D050ACF0AFE0C1ULL, 0x4BB0ADB4E2F54A44ULL, 
            0x892A70443E02489DULL, 0x0592B79A78E402EFULL, 0x502B6D220C99C64BULL, 0x58C4F135DB334D3BULL, 
            0x4C86FE6DE00200D4ULL, 0x55001BAFB8D9B1D3ULL, 0xEA1E66E41740DF95ULL, 0xAFB325D00F10A892ULL
        },
        {
            0xB4DF02505985C44FULL, 0x81BFA78286F60F9DULL, 0xF4C52D487B8D2E88ULL, 0x6B2765A7223FEF02ULL, 
            0xEA989A3BE660D08DULL, 0x14EAD62E91E5200FULL, 0x909936C0F3F42D4FULL, 0x426AFE7BB7D786CFULL, 
            0x7C018903C65D49E7ULL, 0x699C255FAEE8E5A9ULL, 0x0CFD6CAA6A71C88CULL, 0xC471E35A848F4280ULL, 
            0x52C8C87FFB9443ADULL, 0x8250DE90C128EBC2ULL, 0x8D1FBF4F2958317CULL, 0x85F70421ED8396E8ULL, 
            0xA7E6EB893B9A08B2ULL, 0xC292BB721AB79DA9ULL, 0xD12E3E6B7E7FE3DDULL, 0x82F3F42D334D1143ULL, 
            0xBA6D549024155461ULL, 0xE93BA09E6A26E030ULL, 0x42AC46827F2E2008ULL, 0xCB54819382F9357BULL, 
            0x96B59A385F230378ULL, 0xDE23493BA777D714ULL, 0xF27271F01A6DB142ULL, 0x04D36AD241B94730ULL, 
            0xA65F368BF0EF99BFULL, 0x12B8D2E9750A404CULL, 0x9E4F16CFEFC7CB95ULL, 0x2DCBDF77D497BA6EULL
        },
        {
            0xF2D9D99D561121F0ULL, 0x405F7C6BCD5355CCULL, 0xBADDC6F0534607CBULL, 0x360D335DB29E002BULL, 
            0x173FC8B6C882E7C3ULL, 0xDB066D19622EE4FCULL, 0xF4BF15527C07C8EEULL, 0xA886EC538B9FB234ULL, 
            0x849ABE9FE0BE8CEAULL, 0x36897473BE408A13ULL, 0x7409D4FDD0614101ULL, 0x04964439662AF47DULL, 
            0xDFFA3B2B4D1BF894ULL, 0xD10DDD94B0664645ULL, 0x6AA5B67E55E44DF7ULL, 0xC0DD540DB974F920ULL, 
            0x6340D6CF1343CF4FULL, 0xBCDBBA9392AD999DULL, 0xC2A1E08BF83EF759ULL, 0xE5F412394B8CD274ULL, 
            0x4B0B3E73625A71FAULL, 0x5BEDE0CE58F9E8CAULL, 0xAAC38CBBCAC003E2ULL, 0x8C9CF6931129FC65ULL, 
            0x40865BBFEACA22C7ULL, 0x94422E5DA9BA4F88ULL, 0xC29BF49BDE1C24BDULL, 0x208529EF6DF54377ULL, 
            0xC0275E5B59734D9AULL, 0x8FC12BAD8046B8D7ULL, 0x349894B3A7ADC942ULL, 0x33B07DB8A6EDF548ULL
        },
        {
            0xDC87E958D7B74D57ULL, 0x7A3D0B9D6971DB7DULL, 0x74645C0FC5B8D2CEULL, 0xECDD1B8EFAC2240AULL, 
            0xC667E7041F669E87ULL, 0x59657ACD531FC122ULL, 0xA25B6D7D495E0AE4ULL, 0x6B55A7BCEF930AE9ULL, 
            0x8E611B92377053D9ULL, 0x90775E96481430AAULL, 0xB49D398CD117BFB9ULL, 0x11F1EDE5DDBE55CAULL, 
            0x4ED39F301553918BULL, 0xEC7E1D9CE39AC013ULL, 0xD249F1FD85459558ULL, 0xB5CB6DC41D1883DFULL, 
            0xAD3FC094ABC956FBULL, 0xDCCDE84ECCB9213EULL, 0x7F05C4C4FEFE9E31ULL, 0x434CD74A1214B18FULL, 
            0xFB732298412AF9DCULL, 0xE36C602126A14864ULL, 0x9AF350046A671933ULL, 0x2D6DB4435E305E9EULL, 
            0x43693DDCCACB17BFULL, 0x468D1E9C77D3E7E9ULL, 0x0B0A48595ECC751AULL, 0x841C64F3F9A62019ULL, 
            0x20F92D09301DF2EDULL, 0x9B9CBD3C82F4BF99ULL, 0x601EDED3C049E497ULL, 0x3121D1EC501DEC05ULL
        },
        {
            0x199D7542F834B23CULL, 0x637FDDC15B6CAB14ULL, 0x5703798BD0E3611CULL, 0x0D6BBCA870FC1275ULL, 
            0x42B268CF97D0BB6DULL, 0x7C62074BED1D0414ULL, 0xBB4803F2B7F18708ULL, 0xF409FAA4D70E201CULL, 
            0x4400F3566527F4B7ULL, 0x9040C572DDB18776ULL, 0x5D333635B1C152A1ULL, 0xDC714667D2A94C8EULL, 
            0x5B3C45DE25BE165DULL, 0x10D6200C264A67C4ULL, 0xB4B1694A82E499FFULL, 0x6D9488BE79E05255ULL, 
            0xB24C43EBC5614E7DULL, 0x0E3D166EF86E170FULL, 0x0F4EE813997EE8A3ULL, 0xBEA61809A209B6FAULL, 
            0x5CA2C39635B7D51FULL, 0x34F71A0DFAC9836AULL, 0x84FF7D09FF2B0C99ULL, 0x2C0BD64E665D90E5ULL, 
            0xF6BCC234FE2D7B25ULL, 0xEA08AE5E5DD33E21ULL, 0xD04B1E4D62B07EDEULL, 0x214CFB6E26ED03F9ULL, 
            0x4FABA475D0DADAEFULL, 0xD07FCA2A523ECF5FULL, 0xA638A5E76B0AB19CULL, 0xF73A3E6F3D287B48ULL
        }
    },
    {
        {
            0x6632A3CDA25DE826ULL, 0x4E0A33689AF21D78ULL, 0x9CB6A545572DC248ULL, 0x156A3C566D700FB5ULL, 
            0x60ADFB9B7E93D459ULL, 0x3E43B43BC36DDD61ULL, 0xC4AE2DA2C4F00DB9ULL, 0x6E9AAD2562CBB6CDULL, 
            0xCF76B010C20F1F3DULL, 0x3E11F08FE5F7558EULL, 0x3E5E6E0607A9BB60ULL, 0x6C09E5EFA779BEA5ULL, 
            0xBB76B5B5001BC1A5ULL, 0xFC0E41AD10274E75ULL, 0x3415C2458C9BE810ULL, 0x4EB1534F75A0B30EULL, 
            0xA948D28F736D0308ULL, 0xF2102A1C1C042547ULL, 0x3756D3DC7B24568FULL, 0x52754CE3F193D8CFULL, 
            0x7A9608477156EB4EULL, 0xE3C2C6A74E9F43D8ULL, 0x444C16D65A4DBF41ULL, 0xC1D08514013E42B7ULL, 
            0xCC54E8C484594E0EULL, 0xF042738620050B7FULL, 0xB059E60EEC815317ULL, 0x10208AA11F999E49ULL, 
            0x989A98DC349F90E9ULL, 0x71B1DC4548201527ULL, 0xDE5000DF9B0B5BFBULL, 0x2068E34EF95D91F7ULL
        },
        {
            0x76A828DFACC36EC1ULL, 0xF09AA2D75799635CULL, 0xE95873E0A5A66B9CULL, 0xEF0D84AB5B337A5FULL, 
            0x190B4A19C74E8982ULL, 0x9AD2A05EB09CA484ULL, 0x5EA07EFD4973CC0AULL, 0xBD1D509E7FDCFEC0ULL, 
            0x409B9EB316575536ULL, 0x72525C40D7F597DCULL, 0xFE0B49E6024FF455ULL, 0xBE1A7E99BD7C0666ULL, 
            0x372BF5241A69011EULL, 0xFF87749B3DC1EDCCULL, 0x5ED00D7D66EEF9C5ULL, 0x031135147D250660ULL, 
            0x57F3616FCBC3488CULL, 0xE7A750F68F14BADBULL, 0x7CB54DA045F57FDBULL, 0x6E58FDD1137C205DULL, 
            0x0763F2DB57FF0DF3ULL, 0x054317B6B3807154ULL, 0x90D52714FA0BD243ULL, 0x8DBFE798A804C0EFULL, 
            0xA006CFB2DD44BE18ULL, 0x0299BC0D3B38AF97ULL, 0x2AE3FB5BAFE30228ULL, 0xE267FEDEE5084BFBULL, 
            0xD66E4FE2B4AE79D2ULL, 0x9247D080CD88B41EULL, 0x4F3E63EF5413A9C0ULL, 0x900AE343D41516E2ULL
        },
        {
            0xAB8DAC6447F50A79ULL, 0x6C2868EC1F622BDFULL, 0x72DBF52D08B79744ULL, 0x735AEAC6E8FD0FC1ULL, 
            0xAE7D6E301F169ADBULL, 0xEF67A22091B165FEULL, 0x8DEBB277B1A828AAULL, 0x29A50FA3A773F163ULL, 
            0xCE4D524172739689ULL, 0x4FFC82655A8FB420ULL, 0x5FDC08F3A775114DULL, 0x170BA473DCF1A900ULL, 
            0xF5FF625F11428FEDULL, 0x699387E268D4C5F8ULL, 0x1309B6B5C61C2D96ULL, 0xB44EE518EBD4D53CULL, 
            0x49B99958E1F186CEULL, 0x2C87CD7D5A068122ULL, 0xE8640A936FF9F0A4ULL, 0xE0C959192A3FD23CULL, 
            0xD6899668BE9B8579ULL, 0x859838E876669E35ULL, 0x589EA9EF24DFE890ULL, 0x0809A549ED666D31ULL, 
            0x2B4991502B720621ULL, 0xB911373D6D1128D5ULL, 0x259979A8EAF2647AULL, 0x67DC36E65199A56AULL, 
            0xDAE8788D88D8FDAAULL, 0x38F1E41FD1C4DED3ULL, 0x4A20193C903F85D8ULL, 0x765EBFE444A8EA28ULL
        },
        {
            0xC3F4DCEFF0377A93ULL, 0xE77E4531D160C3E9ULL, 0x0B6203693537CB4FULL, 0x019AD59C16CCABA8ULL, 
            0x96501210DCAADBA3ULL, 0x2C0E35C607194DFFULL, 0x81F9192F8A94097EULL, 0x546FB592FEBD36D7ULL, 
            0x366BCAFD2C10358FULL, 0x022D5FA41DFC3ED4ULL, 0xD2F0004DF0F8689EULL, 0xD450FEF96E2A7BC8ULL, 
            0x484834BCEBACF607ULL, 0x585945FA0B582EF9ULL, 0x324D1C6BC4FA708CULL, 0x18A87642AE518241ULL, 
            0x1DD1BBA1324DD01EULL, 0x1DE3107EBBDD59DDULL, 0x8EFAB0446257257FULL, 0x89B93786093AC223ULL, 
            0x47E061515A497527ULL, 0xF84BBE28CFC08C82ULL, 0x87DAA631BAA41802ULL, 0xB1D9590A56FCE4E3ULL, 
            0x10633A254B05680EULL, 0x11BA1498CD0EA0C8ULL, 0xFA3073FDD8CE039BULL, 0xE28914D525FB7AE8ULL, 
            0xACA0FFEE713FE86EULL, 0xD7CAA6E6CD8FD43BULL, 0x5B2530A4287608C3ULL, 0x0730842CC1D45A8EULL
        },
        {
            0x6EE15339C25C90D5ULL, 0x69624053A2919BC8ULL, 0x1AE1E930DD633E85ULL, 0x8E49345C72BFA68DULL, 
            0x44B296E7F1D2D4F1ULL, 0x7EF682B9A54226FEULL, 0x214B67084F3E383BULL, 0x09438F6F6B869E67ULL, 
            0x1E6A9300C7F4EC03ULL, 0xED5F6BE3C378A7F7ULL, 0xD642DA0AA7BD8CBAULL, 0x4E0F931C42C79142ULL, 
            0x15C6AE1C1F5DE64AULL, 0x59BC5F2821F8295FULL, 0xA5A35C2AA4C78892ULL, 0x20E932ECFB4D5408ULL, 
            0x3CB954EB5B935F97ULL, 0x9D32E6F3782FFC4BULL, 0x7FB73040231D76AAULL, 0x4A56CDCE5278AC30ULL, 
            0x209F22EAD6E95600ULL, 0x9208E627DC12EEB3ULL, 0xC817DC59689A4507ULL, 0x8DED9A4EB31FF85EULL, 
            0x999AE00DE494FBC5ULL, 0x1194AC2E3F5045D9ULL, 0x29B202032E761A38ULL, 0x005A0127D12BA41BULL, 
            0xB70CD3ACC2954AEEULL, 0xF95A15DCDD0E64DDULL, 0x43D59228D09B1EA3ULL, 0x66D48F8C27ACC57EULL
        },
        {
            0x1F079421C5E4ACE2ULL, 0x7417F24710DF14C3ULL, 0xC88EEB36807C8AEEULL, 0xB0A7E6441B110B6BULL, 
            0x6AB0BD675FEF129CULL, 0x892BE1F8D70D4B9DULL, 0x2A53E60FA25DF063ULL, 0x3D33D23E2A8488F8ULL, 
            0x7BF3FC82848DA6CCULL, 0x25A68FDD7B725AF7ULL, 0x513D36973CE9F979ULL, 0xDF585ABBC00C2AD0ULL, 
            0x78F14B72A2A76103ULL, 0x7EA742FA7AFA9ACDULL, 0xC7380C9D40402CD6ULL, 0x73F1A41F01AF621EULL, 
            0xB9BE91FE9FE1F110ULL, 0xE9B93A2E21E1E942ULL, 0xB026A012C0FDC194ULL, 0xB569D4C5E6056C94ULL, 
            0x980E99773A8B76E1ULL, 0x3A25BA032FF1281BULL, 0xC2519B82EF038A3BULL, 0x5C4CF8F1DCA4F427ULL, 
            0x92DD62172B97CEC4ULL, 0x692DDB3929E2F50BULL, 0x4772ECA75E4A9107ULL, 0x3E874A7158E91BC0ULL, 
            0x1672E38E974EE9FEULL, 0xA72EAA7C3513AA91ULL, 0xE3BEE68A7C1D7BAFULL, 0xAA34B85D4254F265ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Saiph::kPhaseAConstants = {
    0x40A431E3D50A14DAULL,
    0x21D116DF6B520888ULL,
    0x6E8B7104C5D45089ULL,
    0x40A431E3D50A14DAULL,
    0x21D116DF6B520888ULL,
    0x6E8B7104C5D45089ULL,
    0x54C94096F762681BULL,
    0x7DEE88677C093596ULL,
    0x8C,
    0x20,
    0xB5,
    0x7D,
    0x2E,
    0xC0,
    0x21,
    0x54
};

const TwistDomainSaltSet TwistExpander_Saiph::kPhaseBSalts = {
    {
        {
            0x80512A17854183F0ULL, 0xFC17102245F9255EULL, 0x56E312DFA0FD1B2AULL, 0xBB5A9216B4E2BE7FULL, 
            0x2E380495D4AC8CF1ULL, 0xF78EEA2F2DA2B4EEULL, 0x3492BBE7BF7A123CULL, 0x8E7B6100E75C1C91ULL, 
            0x7D0B3D1A18674018ULL, 0xA354B5065A969078ULL, 0x8EB25A40FEBFB42FULL, 0xA3AEBA629A77EE17ULL, 
            0x7836D62941BA2E67ULL, 0x0E1C4A817769E037ULL, 0x32EEBAFE47655D09ULL, 0x1C06FF00C3BF0259ULL, 
            0x79F85E8462AF59F3ULL, 0xFBCA0E045B78EB7FULL, 0xBA35F4E5EB9957C3ULL, 0xE2FEDE861350EAD1ULL, 
            0xB36BD197185719C4ULL, 0x483FC20037A28408ULL, 0x5E103A3E982203E1ULL, 0x4AC4CE1841535824ULL, 
            0xD859A59340B6A36FULL, 0x1B89012BC2160313ULL, 0xCF065E34FB70B124ULL, 0x9C68614538AB39AEULL, 
            0x1A59D42DC13BE759ULL, 0xF9BF5C86154EA59AULL, 0x66BBB2A24476FF95ULL, 0x12473062100F8F83ULL
        },
        {
            0x8F892C928F730105ULL, 0xF92220CCC4C46B4BULL, 0x33F8E22F5CC3B484ULL, 0x617F9EA67B1EE8DBULL, 
            0x86A8BBA3B5033E4EULL, 0x90EAD804DC220EE5ULL, 0x9ECEFE714F683D5FULL, 0xA5459CC6CD9AB1B1ULL, 
            0x8FD48B3FAC06D107ULL, 0xEE48BF00516B36C5ULL, 0x3D55E0ADCE299EFCULL, 0x37911D97FD471B27ULL, 
            0xB016DF4401191896ULL, 0x2B9AE4F3CD1FF1C3ULL, 0x02C89FF58FFC101CULL, 0x214CDFDC251ABE78ULL, 
            0xA3AA04A602F371AEULL, 0x5304AC9CD8C92AECULL, 0x74C56506DFC79D74ULL, 0x5E972945431933ECULL, 
            0x27DAAA672939ACA2ULL, 0xC22593DA49BF2859ULL, 0x9FCB778E0E5F5EDAULL, 0x832582AF5CA389EDULL, 
            0x218CF8518D4A5580ULL, 0x96FB5E2AF85B0164ULL, 0x7328932B8B6BFDE2ULL, 0x0CCA50A90C354D5FULL, 
            0x677081D8BBB15845ULL, 0x840E7FDB9F9AE80DULL, 0xD8A9BFCFDEA1030EULL, 0x2BC7304A978E7A6AULL
        },
        {
            0x04E440BD22C38167ULL, 0x174F8F98D7F50C4FULL, 0x9E3864585A254824ULL, 0xDA68713076515D11ULL, 
            0xAFE1407F3B4F30D4ULL, 0x52CD398B2A69FCFDULL, 0xDD539A547030CF17ULL, 0x8B2DA961C67EBC9FULL, 
            0x303E72FF64338529ULL, 0x1AC228E1A469CA70ULL, 0xC77C21C658399FC0ULL, 0x22CC22769EB91F61ULL, 
            0x141B975FE574F3FAULL, 0x3B3C5D2B4DE31229ULL, 0x28B9FDB2A4A2FB82ULL, 0x2C2C3EE1540D17F0ULL, 
            0x4F1CC38DCBD76030ULL, 0x2B0BE19E0B67DB0AULL, 0x7F17DB19F8B0DBCAULL, 0xB150EF8EE83F9FD4ULL, 
            0x7B1E158C7CF89CBEULL, 0xF985B3E25680DB1FULL, 0x245E583D6882C46BULL, 0x1A5D1807FD905765ULL, 
            0x4CC81EAA0FD8714DULL, 0xB35C9D7DC2C8B534ULL, 0xD01B916164CE7953ULL, 0x5D3A46EB0BB77BD4ULL, 
            0xC5D5CAF4F78C2301ULL, 0xC7DF5DF7E03DBE89ULL, 0x3B727B1D81AD6515ULL, 0xEDB52486BC992CB0ULL
        },
        {
            0x29E223321A582E9AULL, 0x1D10715B606DA893ULL, 0x5CD896CE6897EC55ULL, 0xC0EA90A42FCB4679ULL, 
            0x43535BDBCA71AE0DULL, 0xB0ED39F7629A4930ULL, 0x5FF91971DA109BB3ULL, 0x901A646360C06D54ULL, 
            0x805C18686E35DA90ULL, 0x9E49AE80F0B259B5ULL, 0xC9C84206EA13D8A0ULL, 0x6330F1C084E092ECULL, 
            0x8BDF5C10C0037573ULL, 0xD52D22AE6D9A031BULL, 0x298EC61ED4E40920ULL, 0x313FC91F5C2C31D6ULL, 
            0x5C37B460E85EA1EBULL, 0x442CF2EA69B023E5ULL, 0x3EDDE36A8FDC1FE2ULL, 0xC9CC95374F9F6BEEULL, 
            0xFE6263424810C7C7ULL, 0x903C2E632092B915ULL, 0x447DB507D523188EULL, 0x94A51394CC2A9CE5ULL, 
            0xB0D3DF6BF1802885ULL, 0x62303209FD7A89C4ULL, 0xABA44B3BA8AD09A6ULL, 0xAB49621B94EE8393ULL, 
            0xA5D0282856CC0A89ULL, 0xF53786DEB41F1E31ULL, 0xFF12CB5CFB6A2349ULL, 0x03E0EEE6D3589039ULL
        },
        {
            0x197A758C3256A1A0ULL, 0x3A4DDEF82BE8855BULL, 0xA816C959613CF38AULL, 0x9368858AF9B10A3BULL, 
            0x56B0FF5C7DA29D7CULL, 0xAEBD8054206D1140ULL, 0x18D75B6210B58EFAULL, 0x3369ECAF56C3D72DULL, 
            0xD64BC3069547F3D5ULL, 0x686D00829A24C1D5ULL, 0x8A963141131BE2CDULL, 0x55A8E570D9DA99B0ULL, 
            0x09100A52CB596C33ULL, 0x7605011EDA9E050CULL, 0xBE813E95D00F90C9ULL, 0xE25B4DE6556AD174ULL, 
            0xE272870403015E5AULL, 0x144035538B63973AULL, 0xBCBC93FCD95E67C5ULL, 0x97A36E4616A4D22BULL, 
            0xB7BD8E5AAF360259ULL, 0xE20CB148C2BCCE11ULL, 0x2388180399CFFAD5ULL, 0x39A7A743DEA8E0AAULL, 
            0x7A8AC175A96DCE7DULL, 0x9E23C20893B632EBULL, 0x904A8B2CA8793042ULL, 0x7ED2F68ACED4BD66ULL, 
            0x12D4D841A3298BCEULL, 0x75EA4181B0A916FFULL, 0xC263001FF579F641ULL, 0xBFFC5B59F6F653BFULL
        },
        {
            0x62BEFE224C1CC675ULL, 0xD3D14C4185E08E48ULL, 0x162254E510D311EDULL, 0x3EFDBD507067BECBULL, 
            0x0C67DF1E1E34A253ULL, 0xF5CD03D8E3C16845ULL, 0x90A44868F393E691ULL, 0x33F84C69E818380EULL, 
            0x70646A330BD03A99ULL, 0xD7DB841EBAC4151AULL, 0xC9537D2E5170BEB5ULL, 0x58CA504EA2066FACULL, 
            0xEEB2E16E31823C22ULL, 0xA92FEBD9F21767D2ULL, 0x3D6BD1A3995F6E14ULL, 0xFDC5A55F89077309ULL, 
            0x76D79859B1AED725ULL, 0xB376119D6969904CULL, 0x122D456784EF091FULL, 0x98A457BCD17AFEE7ULL, 
            0x8CEA441BDE857487ULL, 0xADA72595485F136EULL, 0x98E10097BFF0572EULL, 0x4C474A31C9F1323BULL, 
            0x3E742691B5E5144CULL, 0x9F03AB926CF7FC31ULL, 0x1CA5274FCF6E48B2ULL, 0x09C514841651DBB7ULL, 
            0x685AB71AB685C491ULL, 0x9DFCBD1536C0A627ULL, 0x527DFED069C711ECULL, 0xF5FD689BF276C62EULL
        }
    },
    {
        {
            0x1D669881AC725998ULL, 0x7A43CA1F47350341ULL, 0xD99359A571AA1738ULL, 0x170B61482B7B0A5CULL, 
            0x840C131FE7CD4050ULL, 0x5ED3332C6714CE05ULL, 0x7BBA04D596A19E8FULL, 0x6833CA8337E114D3ULL, 
            0xC6AAF3A63D2888A4ULL, 0x546F5851069CC682ULL, 0xC1FE7C7D931B5000ULL, 0xFE6929DB23544A6FULL, 
            0x4BFE219C9C21C09EULL, 0xCF121344F4090DAFULL, 0xE95A76387C86FC39ULL, 0xA61F1D5B03D45C01ULL, 
            0xFB1ABE64710D0A94ULL, 0x4A9B35D3D619A569ULL, 0xC06E2DEFD88E8E11ULL, 0x77D2F1F710E20523ULL, 
            0xE402E7691E087D65ULL, 0xCA8E59002028EEFDULL, 0xB08C9C263CAA8286ULL, 0x7992F4E92974C66CULL, 
            0x271D2E86D722DF2AULL, 0xBDA97EB042B008CFULL, 0xF2BBB1D25A8192CAULL, 0x1CFE812ACE01FF29ULL, 
            0xE34D754F2902AB19ULL, 0x47AAA09FD221844BULL, 0xF83004AFA9C36F9AULL, 0x799FCAEDC5C35D8AULL
        },
        {
            0x74CAEC926738178AULL, 0x0FDC0FBD67F01A60ULL, 0xC012761945FAEB63ULL, 0xDB3FFC8BCF0C411CULL, 
            0x9960FA39BDE063C1ULL, 0x9D64E5436B652C29ULL, 0x376FF6608085708CULL, 0x88231E7CA4A73EF0ULL, 
            0x67ABA884C993853AULL, 0xB0DDD34B515F2D98ULL, 0x13DD2AB6198C31AAULL, 0x348DFF1E09930FCCULL, 
            0xF991D473C656467BULL, 0xD2DAE5D5E2B44CB7ULL, 0x1FF77575AFB9DB8BULL, 0x82C4D0868D5AE678ULL, 
            0x4286B9C64717F904ULL, 0x21D18A55BC93D4E1ULL, 0x2907BD4180601A00ULL, 0x4D548E083BF92304ULL, 
            0xDEA18EAEA95DC509ULL, 0xB1B4E427D3BFB4A6ULL, 0x944881D01DC0B732ULL, 0x201B483C9EE78ADBULL, 
            0x5CED165C15CC0D69ULL, 0xB3E47E0C4E51E734ULL, 0x78B61AC2C8E9D544ULL, 0x18E951C7C101BECFULL, 
            0xF57F09722BE5E47DULL, 0xC95582958D3285FFULL, 0x3A83F2B431BA275AULL, 0x1478F782F16BD0BBULL
        },
        {
            0x7E2AA870540F5D53ULL, 0xC567E438C52E53D0ULL, 0x833665889AD177B3ULL, 0x973881D2A563AF74ULL, 
            0x9412B4DF49C93FABULL, 0x28603724812D5336ULL, 0xE66476CE679D33B4ULL, 0x86A43F5435040225ULL, 
            0x3B973709FD38BD7AULL, 0x1D55D90EAB2C364FULL, 0x94D219AFEE9CC1E0ULL, 0x67E5355F11F5F8F9ULL, 
            0x7091845438D393EFULL, 0x37FEE6EE4C85EEDDULL, 0x3D80F6CC96EDAEE4ULL, 0xCB076408AB09A35FULL, 
            0x7D981BDDD6DA0B7EULL, 0x22A96460A238F9DDULL, 0xB7B80F987897ECA2ULL, 0xC83651E4C822B193ULL, 
            0x422AACDF75FDDC25ULL, 0x90D5AD5A30B5F664ULL, 0xBEEE1D62A11235D6ULL, 0xA9E1901846FF0684ULL, 
            0x0BD81ACBD4512733ULL, 0x3A2545D561109200ULL, 0xCE4FCBBD98094066ULL, 0x5319D26F4496318DULL, 
            0xD8A5EE61CFD0D4D4ULL, 0x6D82F2E9269F489BULL, 0x104D3744C28555F0ULL, 0x9E309DAD2FAE826CULL
        },
        {
            0x7C2FB6EEED5EBE41ULL, 0xE52A4B49ACED9BC5ULL, 0x899BDAE51B484BE1ULL, 0xCA74713F271BF435ULL, 
            0x2D416311C361F144ULL, 0x6ED41730C1001DC4ULL, 0xDFC923C41D3464E4ULL, 0xC4E1BF28C2D2BD1CULL, 
            0xA8B7D488720D05BDULL, 0x2335412FAD059D18ULL, 0x22808C354465DA69ULL, 0xF00DECB1C8B7C5EDULL, 
            0x6CA747B43590619FULL, 0xC21CA5E78682C87EULL, 0xFD97A449D6A12B9BULL, 0xA06F9EA9269D07DAULL, 
            0x6CDEB69F82D03307ULL, 0xA99C3C1B7014487FULL, 0x5E5D75BAE82E80E3ULL, 0x07F4287EDE5BEE12ULL, 
            0x4ABBA38D477B8911ULL, 0x2B801CF63EC95E6DULL, 0xC00809F6631A29DDULL, 0x82120FA870DC8D37ULL, 
            0x1567355D6C0F5BD9ULL, 0x8150C646CF5F0A40ULL, 0xA2CFB6D062DA836EULL, 0x6247234026B71B83ULL, 
            0x02705AC79E0298D6ULL, 0xBC4D4B2AE048886AULL, 0x88D2635D289BC7DDULL, 0x43EFAABC7049C530ULL
        },
        {
            0x018ED1D3E2929CDBULL, 0xF30B71DD26B1C73BULL, 0xD4131BD0B28441ACULL, 0xDA7B7E1DAAD4361EULL, 
            0xD81C5C83488353AAULL, 0xF6B2D86DA0D5047CULL, 0x8ACD0B05EA3D336BULL, 0x0DD5753A33051141ULL, 
            0x462676741948199EULL, 0xBE4DC3A3CC2246F2ULL, 0xB0F003F90EC2162BULL, 0x60F7B46184C29E65ULL, 
            0x25900AD908755CD7ULL, 0xAF8737EC21C38F78ULL, 0xE57D9B807D69674AULL, 0xD13215456C16866BULL, 
            0x2F2533350BF305A7ULL, 0xD09CB7BCA8030953ULL, 0x9F086E59045ABAB3ULL, 0xB0EE2EC6A0726E2DULL, 
            0x5A657157431CB26DULL, 0x099A6447AE2A61D9ULL, 0xB18815E251F90A68ULL, 0x2DA8EE6C75C2C80BULL, 
            0x193A319AA00AC435ULL, 0x039727F58C990BE7ULL, 0x676C31BBB112ADD8ULL, 0xA3D1BDF1EBA031B6ULL, 
            0xA0C945F851E63033ULL, 0x85C4F10A805FE3A7ULL, 0x53E5601F9071FE0BULL, 0xF53D555CCA5770F0ULL
        },
        {
            0x19749ABAC4836F82ULL, 0x23D8F5A0BF9E5033ULL, 0x0EE430FFF4E95DBFULL, 0x10E04ACAFFCBB3F0ULL, 
            0xBDDB91AA1086EAEFULL, 0x73C55992C1935AA3ULL, 0x4F978A5ED37AB6E6ULL, 0x788C5888093A0113ULL, 
            0xCD62D8D98953776CULL, 0xE1F483A9312402CDULL, 0x8EBD2091D99D5300ULL, 0xF42C9F9CFA8AB19BULL, 
            0xFE7430E6E6F3EB47ULL, 0x4EA0D52665529BB2ULL, 0x09F1C59DC66599DDULL, 0xA2011F5EA416A6E8ULL, 
            0xBBA90E68574785C2ULL, 0x7DFCBB5CCD49EA3AULL, 0x77BDD37A9E3B3A9FULL, 0x9136576B615D8F6DULL, 
            0x96250B3D689B34FCULL, 0xEC3B3037AC643BB0ULL, 0xC71D230691CA7DEBULL, 0x9D8D7C0C9A807396ULL, 
            0x7205231BAAE96D05ULL, 0x7EC270FF36739EF1ULL, 0x6A67E10B94312B3DULL, 0xA4C57DB14E24F969ULL, 
            0x489880616D051F02ULL, 0x5EDD53953F25DF8BULL, 0x25DA289AE1C18FF2ULL, 0x24F39F6366AEF956ULL
        }
    },
    {
        {
            0x9477811A4EFD1661ULL, 0xE2B3B268BC6E7283ULL, 0x740BA8496F25B017ULL, 0xFA94D59FEA12AFC8ULL, 
            0x217EA5977FD1A60CULL, 0x158F32E753A48126ULL, 0x68A727E9D16519CFULL, 0x49E5D72E17B501D6ULL, 
            0x1414318A1BADEA67ULL, 0x0F31169B99353012ULL, 0x8B05A811642803DBULL, 0x47CD4D90CD83172AULL, 
            0x1F54B843C86CAE81ULL, 0x6B180A5270C74F83ULL, 0x65CCAEF46E444763ULL, 0x5FCA2632336B3C32ULL, 
            0xE0074130269E6127ULL, 0xF3CF6B7DCE7FF19CULL, 0xF669049272AF7CFEULL, 0xD6155AD89F4D65F3ULL, 
            0x22BE6BFB4ECCC04DULL, 0xBB03899B3B76FD8FULL, 0x89F273BDA24ED135ULL, 0x6E7E3379D61107AAULL, 
            0xC5D4FDE81DA7009CULL, 0xA920943DDE0DD16AULL, 0xEF92D626B7C864BDULL, 0x76A988FAC58F8214ULL, 
            0x7FE61B433C7A535BULL, 0xF80F8253EB55B43CULL, 0x5E7A66C9AD80A007ULL, 0x3BED114E6166E163ULL
        },
        {
            0xA5E7A40208B8103DULL, 0x49161333966E203BULL, 0x82C3290570E5868CULL, 0x0A87006D29026767ULL, 
            0xE13C0BCEBBF4BBD0ULL, 0x9E3C4E46409109ECULL, 0x7E09B2DC9EE07BAEULL, 0xA5ACBB960BBDC61EULL, 
            0x40093C70B7F754BFULL, 0x7ECF92AEA7845D10ULL, 0xF0A6756C29DC5F84ULL, 0x7BB7726970F6AE64ULL, 
            0x6D609C405A36C2FFULL, 0xAF1EE2E7807DE907ULL, 0x607C64C06BF05309ULL, 0xC195310E108EC979ULL, 
            0xDAE8A61396DE2272ULL, 0x5F0012B4A379225DULL, 0xA8FB72B84B59CE63ULL, 0xBB935034AE6F253FULL, 
            0xA5F6D8078C516661ULL, 0xD7D5CF404FA87B98ULL, 0x17850FAA82D94928ULL, 0x6E3E3737932447E4ULL, 
            0x50384FB3C6428920ULL, 0x9FF44843C4A54A40ULL, 0x707A775858B76C71ULL, 0x13B82A774A656A42ULL, 
            0x1521766A0BC078FAULL, 0x9BB9744BAF61E9ADULL, 0x6F915F386C2235E5ULL, 0xACE52F2E24DE40D0ULL
        },
        {
            0x285C06778A4680B3ULL, 0x2FEE2F7C0FFE9B6EULL, 0x13006B21EF1E2D10ULL, 0x3AB4EB46B2BDB67DULL, 
            0x21483149A04AD06DULL, 0x9EBA383C8840A2C5ULL, 0x5E44EC3DE57B1523ULL, 0x74F6BADE8B050207ULL, 
            0xED434FD3D380F9D9ULL, 0x06CF63E2BF162C19ULL, 0x51D685B0A79FBE33ULL, 0x04A23BB192424B14ULL, 
            0xAE1E2616EA31DBF0ULL, 0x0718557DC5985275ULL, 0x77AD71F4DE0AF58AULL, 0xDD3673B45E33D87DULL, 
            0x4C13A920F2043D4DULL, 0x47AC9682E1384171ULL, 0xB88B1F48950D9E37ULL, 0x71B96D7895885733ULL, 
            0xEB036DE058838FB1ULL, 0x9B54D2E503BC4919ULL, 0x27BA9671528AE6B8ULL, 0xE6872599E9B7D68FULL, 
            0x35EBE37146883902ULL, 0xEDE1DBEDFC1D676FULL, 0x8008034F5457F9CEULL, 0xFFAAE141864D9F6DULL, 
            0x39B3CD8250EB869EULL, 0x94C5A01D8375DD8EULL, 0xD180C03B8C963431ULL, 0x1CE072A02FA06F61ULL
        },
        {
            0x11419232D0E25FBFULL, 0xEA083DF38DE30306ULL, 0x73B9D6F14E7AA4EEULL, 0x744529FE27B61B0BULL, 
            0xAA20D62C48A48B83ULL, 0x87D1260B53D823D3ULL, 0xAC3ECD43E34BD40CULL, 0x099112A6ACA7735AULL, 
            0x667E7B246E1C5B25ULL, 0x5289815D04CE0B36ULL, 0x1525D59ED09D8002ULL, 0xB5A80D59CF3AE65CULL, 
            0xEEC79623C68840DFULL, 0xF1D9928942EEA273ULL, 0x6F622DA9E79BEE6EULL, 0x1368B6FC2E1C9F80ULL, 
            0xEF13CFAF8945E24DULL, 0xBCCE83798FF267F3ULL, 0xBB0DE44896966008ULL, 0xD1E1CA4057C9AC66ULL, 
            0x7F88E87AC32269F0ULL, 0x9F5593FC24A0A63AULL, 0x9CD3D0B488FA8143ULL, 0x4A0FD34F4A2705EFULL, 
            0x12E2A76CCAD8D0EBULL, 0xB4B52E3F5CE51D7AULL, 0xC1B094E79AE6B786ULL, 0x4C940F2A86D39EFBULL, 
            0x81B83DA6957DF5FEULL, 0x12D9F4743307B4F7ULL, 0x5DDF165129BC8CDEULL, 0x161609D05ED9FC29ULL
        },
        {
            0xAAD8B06BE80F78DCULL, 0x0C3B67D78CE9CCFCULL, 0xEB285EFE5850F768ULL, 0xD33B0351F5744F5EULL, 
            0x5830C48EAFB88420ULL, 0x2018328AB69C1415ULL, 0x69C74140F1FF7B87ULL, 0x159E73FB62B8900BULL, 
            0x393BE2970EBEC407ULL, 0x0C4AA4DF5CD14D00ULL, 0x7CBB81384EA19DB4ULL, 0x11CE473B9DD11391ULL, 
            0x5F48C3AE25024F8EULL, 0xEC2EAE06FCB8D7F5ULL, 0x9C0E41FF77431C3BULL, 0x7742F41E50CE84F0ULL, 
            0x16B0D24F3E2A0F40ULL, 0x1C789AE6FBE7010DULL, 0x78C34830C46E056CULL, 0x37F91D62819CA1EDULL, 
            0x8D94EFBEA07FEBBDULL, 0x1B20CA8A1F26D358ULL, 0x88C442BECB9764C3ULL, 0x08C55E99C0D7B3A4ULL, 
            0xFD58646DBC417FF4ULL, 0x4C8E7118EA11162FULL, 0x287505DC9E38B92CULL, 0xC3A6DD9AC312F52CULL, 
            0x544C549E61C1F15CULL, 0xF16878A43D1FF885ULL, 0x26B58193A074A9D5ULL, 0x4FAFD1EF288EBC5EULL
        },
        {
            0x163FD9EEA174EC1CULL, 0xF434B451A2942F3FULL, 0x56EEDB9EF4C45290ULL, 0x641349ABFCB0512CULL, 
            0xCC39E92EB37E4DD5ULL, 0x5FB82837E7162B6BULL, 0x3AF98A0064E53A27ULL, 0x0E08D3FBDA9D4E6AULL, 
            0xB23A094BDEBAA30DULL, 0x28D54A39265A4031ULL, 0x226C165984DF8381ULL, 0x7ECBDC2DDC1CF2B5ULL, 
            0x70BBE0BDE8542D9CULL, 0xB643258258E842F8ULL, 0x8CC44658C1DDC554ULL, 0xD65F47435DFF5021ULL, 
            0x6E3E0B1EE59346A7ULL, 0xFEDBF0C1E2C38549ULL, 0x2772EC4236704B37ULL, 0x62B17BC1388074F8ULL, 
            0x853C805CF24BC51CULL, 0xA3951B2DB48F1A41ULL, 0xDC9E5CCB430D0C43ULL, 0x28B4BCFBD480CE86ULL, 
            0x6EF97835F4666F6AULL, 0xCE360677AAF6CA08ULL, 0xB4A1B6D34D7284FAULL, 0x1F781B114BE6952EULL, 
            0xE8317F4EFDCC801DULL, 0xCF8E368A9D9DF407ULL, 0xFAA545A91EE1CDC4ULL, 0xC8F05292C7AA4131ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Saiph::kPhaseBConstants = {
    0x711FAEF349CA487CULL,
    0x27A00824EC0457EBULL,
    0xD606A19E62899A04ULL,
    0x711FAEF349CA487CULL,
    0x27A00824EC0457EBULL,
    0xD606A19E62899A04ULL,
    0xA7490A3B4E144793ULL,
    0xA4C5CFF43C215736ULL,
    0x9E,
    0x42,
    0xBA,
    0xB5,
    0x90,
    0x44,
    0x22,
    0xCE
};

const TwistDomainSaltSet TwistExpander_Saiph::kPhaseCSalts = {
    {
        {
            0xD1A2546E762034FBULL, 0x9498680E0316AA4EULL, 0x48C3474D6D1798DCULL, 0x87C55D3A1B7C9B5DULL, 
            0x8B5CD58D32A5C473ULL, 0xF53B595DE786D215ULL, 0xA8AD9049F11AC5CBULL, 0xF9F2489FB8D04B99ULL, 
            0xDD294FBF5A69EB18ULL, 0x266D05AEE6302CCAULL, 0xD6927EE359518606ULL, 0xCEBCE83DE0C38C1DULL, 
            0xADDD06579E9EA9A5ULL, 0x1D31E4094F20A365ULL, 0xC61D3FD8C15A90C2ULL, 0x21BD4C6F5CAD55B4ULL, 
            0x63627C941247C351ULL, 0x2BF4D7817D26E374ULL, 0x0BF6B1794C6A059CULL, 0xE879DB0B9312C128ULL, 
            0xA2D5C477773AE146ULL, 0x967F55B16B7FAF2AULL, 0x70AD7C8BB886EF1FULL, 0xAA17362BE48BC788ULL, 
            0xC5C5097A73ABD788ULL, 0x10532BCAAA452ACBULL, 0x0F0B687A4BF411C2ULL, 0xBCFDA0EE8CED2407ULL, 
            0xCC1718769E002691ULL, 0x3F702B874B7BF52CULL, 0xC812CE3805D04306ULL, 0x9037C6DFFE9A8DA7ULL
        },
        {
            0x9966E9B23EE5352FULL, 0x441EA00AF89DE865ULL, 0x939DAE5C9CF896C0ULL, 0x050CAB13324A24C2ULL, 
            0x51CD3E1E2B424033ULL, 0x41E7B2457988B1B5ULL, 0x10B997284039393AULL, 0xDD2D978836403600ULL, 
            0x731E8E34EDF45674ULL, 0x8D4D656DEA7B377BULL, 0x8C624948C44C946CULL, 0xBD53F1BFEBD4D4E0ULL, 
            0xC0B908BEB710779EULL, 0xF45B14469689C7AEULL, 0x45E4F379968B77B6ULL, 0x0D7C462A97FC19D0ULL, 
            0x870F90BC03F937E4ULL, 0x6F62AFB774532FC8ULL, 0x79B3C9678E945BF3ULL, 0x906EC89AEF6A544FULL, 
            0x20C58829EAECF481ULL, 0x134E1E672D6A9A68ULL, 0x514DEE9E5F558798ULL, 0x307075E674617E8CULL, 
            0x3E3E715DEF382D16ULL, 0x16739EE30B2CF3D6ULL, 0xB16A1AB65CC9AA29ULL, 0x789B0061B2A3D26EULL, 
            0x89E9B4A5B7566963ULL, 0x64D94048684D4F0EULL, 0xFC0BA27778668DD6ULL, 0x65AE0E17A2C6B2C2ULL
        },
        {
            0x18406E721B0BF2CBULL, 0x0BBA81D5CFA6FC03ULL, 0xDEE3C39E54113DFCULL, 0x44AAEF8318FF366FULL, 
            0xA2579CFBCB19CC89ULL, 0x91A0CDFDDA3383FBULL, 0x240A7D41D514D4C6ULL, 0x84BBEB6C76E2E637ULL, 
            0x31E6802BDEEB180FULL, 0xA6DEA470ADB53DA6ULL, 0x56C318369A0DC012ULL, 0xC9C96ACA8527E22FULL, 
            0x6CBABFF440A8AD58ULL, 0x7A5A363A8AD8090AULL, 0xE0EF5D94F0DC6598ULL, 0x66E09F6751CFA068ULL, 
            0xEEC9C9CF01894C93ULL, 0x6D60325C1643AA56ULL, 0x50B0C19E7B46840BULL, 0x0C8E89B64768D247ULL, 
            0x3DFF3DEA85CBFA7BULL, 0xE1F3072AAAEAD7BCULL, 0xFBE209299944C19DULL, 0xE0028F5176C07F51ULL, 
            0x58F89DDD9C970679ULL, 0x15CF7932AD735315ULL, 0x8BC452396DD7E13DULL, 0x928E309678DE75A0ULL, 
            0xCE455D13EF0D47A9ULL, 0x6932ADA14C3158A2ULL, 0x54AA67988D236BF4ULL, 0xB1E471CBFE13C32AULL
        },
        {
            0xD27CA9C013735C0FULL, 0xC22148DA0307C55BULL, 0x88F842AE40139320ULL, 0xDCB11686FB7BDD41ULL, 
            0x253E8ED25A1FB3FFULL, 0xE1C2B287CF074838ULL, 0x923788401BE1FF01ULL, 0xBB4B0C47A61D8498ULL, 
            0x84461EFB6BC4D6B4ULL, 0x98737BE4289CFD8FULL, 0xA9E0E8C06B9A9747ULL, 0xD93BAA4EAED088D0ULL, 
            0xADC8A59E61D69910ULL, 0xF41109D08E203A2DULL, 0x6E775FB748884E08ULL, 0x7DD7FE8E7A73B6F3ULL, 
            0xC53B5A75D1415F46ULL, 0x1EFAF730DB311D92ULL, 0xFD12A3A9A005B7C2ULL, 0xB7D129DE98629FCDULL, 
            0x8BA0D861C928EF5DULL, 0x5F58547667B9AF8EULL, 0x29A3BDF8345B0860ULL, 0xF6605EFA0A50AD3FULL, 
            0x47B31CD727EFF3F1ULL, 0x265FA2C22CA98C91ULL, 0x370AF019FA1F5CD2ULL, 0x1D3566E2D121CFE2ULL, 
            0xB9D5D3C6E5A12705ULL, 0x455AF7C332D4CD56ULL, 0x23C83B32ACEC1AC9ULL, 0x5D92B38ECB30477EULL
        },
        {
            0x587BDD6B938A37A1ULL, 0x7B0738F437105D28ULL, 0x2E8761FD2035E949ULL, 0xDD934EDE33103FEFULL, 
            0x48A510F62629EDD7ULL, 0x70B1D1AA3910E9D0ULL, 0x0B26B5184F4698CFULL, 0x5923CBDFCF44A6F2ULL, 
            0xF2082651FDF898FFULL, 0x38CF7EF1CF83C74DULL, 0x7084DF46849D721AULL, 0x34568CA54793CFABULL, 
            0xBCF9BC0098A9E3A0ULL, 0xBC08D6FFEFFAEC1AULL, 0x7C6A4245F59BCA4EULL, 0x15CC243B8B559613ULL, 
            0x497A31CADD1E1C84ULL, 0xB98091305E8B0F84ULL, 0x30745293F7B14CD0ULL, 0x123EDC0252CBABB3ULL, 
            0x3DB4BCBA943C0D2DULL, 0x1108F7215FBB8A53ULL, 0x0D8AD942158FF7B5ULL, 0x3B21136AB36EC7D6ULL, 
            0x046AC564547A6EF4ULL, 0x15322CBEB2692B50ULL, 0x9FD85BC5C5F606D2ULL, 0x569DBF6361DDB591ULL, 
            0x3F189ED677E74B13ULL, 0xB59686FB51E09ED8ULL, 0xEF215A6BB201B3ABULL, 0x19D2C9BDB699123DULL
        },
        {
            0x64C3C3820C1CA232ULL, 0xA1EB5A0C50F96244ULL, 0x70D62C38107EC692ULL, 0xB733810ADC37533CULL, 
            0x2315AFE657FABEF8ULL, 0xFADACD598BB7ED8FULL, 0x89417FCE5F587F31ULL, 0xE61E2D032B1F6EA0ULL, 
            0x91FC96AD360636BCULL, 0x2B658556828D94A5ULL, 0x78BD8D00FDD8EADCULL, 0xC3E62001C85C7A34ULL, 
            0x055D77F77068B51DULL, 0x8AE3AA347072FD96ULL, 0xAB4EF4718DCCCD58ULL, 0x7978FC7E3BF53D4CULL, 
            0x7BF1FE7F93B811BAULL, 0x80987352F1336E6BULL, 0xABC738BD5E8914EAULL, 0x1BF0A5D72AFEDDAEULL, 
            0xECEB8183D5DC58B4ULL, 0x1D3052777D8B40A0ULL, 0x9039BBFB75BBCCFAULL, 0xB75B11DDBDFB97DCULL, 
            0x5220809A37F49AA0ULL, 0x413DAAB2DBDF1920ULL, 0xBAFE1E111570B414ULL, 0x770A77433F6877D0ULL, 
            0xB0EC419D6D7DDE38ULL, 0x616A5322DEBC9019ULL, 0x89F05BD11018A0D0ULL, 0x7C2917526FE1D7DDULL
        }
    },
    {
        {
            0x04F1AA0AEBD2B633ULL, 0xA7AE3F05BEBEBB3EULL, 0x05D0D8D93C2DBDDFULL, 0x58A92E852CAD85A4ULL, 
            0x5557B0557960981FULL, 0x2A63E35851993633ULL, 0x91B5C585048E60F8ULL, 0x74B45086BA366FCCULL, 
            0x930EBFB3EECC79AAULL, 0x68BC08E8CE0A6966ULL, 0x28765332D9A7958CULL, 0x8EE1B6405EE2E271ULL, 
            0x72F1F690CE78EF28ULL, 0xBE449494BB5990D5ULL, 0x81373A75AAB87E9CULL, 0x7B5C1A73EDED9E18ULL, 
            0x7A79B42F6691B8E8ULL, 0x22ADCB18DD0771E7ULL, 0x8441376979C8AEF9ULL, 0xF5867BEE82355C6DULL, 
            0x13F3382850B426FDULL, 0x96BCD9C475D9526BULL, 0x9E720D95B8D800B3ULL, 0x9B4D91DFB127B67DULL, 
            0x5EAE4C3FD1A93E9DULL, 0xA5C47AC84531028BULL, 0xB45F804C330D09A6ULL, 0x2F6E8A87023902A7ULL, 
            0x1F2C571B09B18252ULL, 0x7CA26605AF6D67A7ULL, 0x65B56B799957DE2CULL, 0xA20229428AA4BC76ULL
        },
        {
            0x522AC99F528CF444ULL, 0xB1A8AB726CEFB65EULL, 0x47A281886B9FC860ULL, 0xF6A9D290F7718E56ULL, 
            0x82AF5E62CF227797ULL, 0x75FB3599EAB913A9ULL, 0x45C2121E38493838ULL, 0xB4E09E219CF07D5CULL, 
            0x78DBAE8EF1D7DF21ULL, 0x719D926B6C206624ULL, 0xFBD6FAE80F30D59EULL, 0x87CC0CBB35325673ULL, 
            0xE8B2C69BEE1D98D6ULL, 0x5C04F33D3D477A72ULL, 0xFC017F6F0764FFA1ULL, 0xA986C10407494999ULL, 
            0xCF34D74241FC1346ULL, 0xF001260A095BC338ULL, 0x51D32F6D2CE7D534ULL, 0x4A6F944E665BFBBCULL, 
            0x7E924A493ED9D4D2ULL, 0x198B22F3028F9758ULL, 0x581D5B72D69F2C8BULL, 0x6F127852FE604B20ULL, 
            0x010793E371323AA9ULL, 0x3FF5580D5C3A888FULL, 0x8061E5627349BC2AULL, 0x1E8719AFF89FDC7AULL, 
            0x8EFE5BF30DA2D3C7ULL, 0xB1AD07E17D9CD332ULL, 0xC2F4E590E98A2661ULL, 0x2710EEA7EDD1E5E1ULL
        },
        {
            0x67BABFC9E2674F22ULL, 0xF2EDB5A211BDFBDFULL, 0x8B7829E45BB68214ULL, 0xF9775E1115BA6B6DULL, 
            0x82FE05C3734DAE8DULL, 0x7E52918DBA3DD68DULL, 0xBA898A1C8A907B3EULL, 0x0A83221F825C9DCAULL, 
            0xE9B0714C4D13CA4DULL, 0xEADBE5297097E452ULL, 0xC29D3C2699D67C60ULL, 0x2DC19B0148C4ADBAULL, 
            0x06E600DDB054D99EULL, 0xF1EB231651C67845ULL, 0x16AD9E05E59D2C3DULL, 0xAA77E0CB8600A035ULL, 
            0x21EC1E555022D777ULL, 0xE94753B44A66DDAAULL, 0x03E438A0C89ECAFBULL, 0x509E30D7B234F5EEULL, 
            0xDEC259DBAF1C7FAEULL, 0x381A38485260D81DULL, 0x96834B3E527CA78CULL, 0x5A68F33F7AAACC8FULL, 
            0x141AB9BDB32E17F5ULL, 0xE12245C4CF515A6DULL, 0x4A0F31BF1E61D2C6ULL, 0x78264430EE464A92ULL, 
            0x5E7C4BB76FB90DC2ULL, 0xF63B6DE3A1E588D1ULL, 0x713247EC9D2E5947ULL, 0xEB9612242D6CEDF0ULL
        },
        {
            0x5B3DC4BA0D3C0E43ULL, 0x2437C4B7B43B6209ULL, 0x5BD385D0FC6FE9F7ULL, 0xD9E904F4355D2DA0ULL, 
            0xEB674DE91E913D8BULL, 0x09E924682BCE5EA3ULL, 0x05D6191EC53CB252ULL, 0x57D45EF2658713B9ULL, 
            0x80C908E54808A5C6ULL, 0x00ED708D4574AE38ULL, 0xB7F03A1FD926A1E1ULL, 0x43B37F9DD2BA487FULL, 
            0x99595BDD09807312ULL, 0x7C7C06FCA206A084ULL, 0xF252E0DE143F4180ULL, 0xE2C62B094CDF6EA8ULL, 
            0x7122BC9FACCDFA32ULL, 0x7063E37112A53D6AULL, 0x8B84E8CED978E02FULL, 0xF0EF8B7C3378690AULL, 
            0xBFC5626008F967BAULL, 0x29ED218528E2C41AULL, 0xF781CD2D40470746ULL, 0x462F756BFF4BB313ULL, 
            0x7F1721808A03ED7FULL, 0xDF3E4772AD13B69FULL, 0xB71A87514DD0E453ULL, 0x77A01DBBE08B7EE7ULL, 
            0xFD48309E1CC3BEC5ULL, 0xA9E15F85F7B8EAC0ULL, 0xF23CB5FBB84B3E7AULL, 0xAC7BB6189621DB92ULL
        },
        {
            0xDB2DAF5ED8DF53DAULL, 0x3B6CE5DD6DA7264CULL, 0xE578A474A3D70583ULL, 0x53E7FD352E0C589DULL, 
            0xFEFAB0DE89D8FEEAULL, 0x23E4F82F4A06DF04ULL, 0x404367FAE69D80CDULL, 0x1644D436C439B5F7ULL, 
            0x233419F9BD5CD224ULL, 0x47EDC39898E26468ULL, 0x9C975AAD5CE83E52ULL, 0xB13FECB6E2DF267AULL, 
            0xB90EFE18E1CA4AEEULL, 0xEEDFD5F9582B6A5FULL, 0x3C7903EBCDE15C33ULL, 0x3A7A7650B060DB87ULL, 
            0x2C1F625245A7DAE5ULL, 0x40857A8DD1F2BE97ULL, 0xB3E98D50DDB0D522ULL, 0x6922F34A062C659EULL, 
            0x869F5A9FEA2A5FDDULL, 0x9C71B55E265F4B6DULL, 0xF5A72B42D5AB0B6EULL, 0x3E2B0AB6BBEE24F7ULL, 
            0x4745DCBBF97E32C7ULL, 0xDDF9910DEB0EE3A8ULL, 0x3F56F17DE052ECDFULL, 0x90928C86F27B0487ULL, 
            0x83CD92825855DE9BULL, 0xF0DFE13E34D260B8ULL, 0x9789C475A6B49F13ULL, 0xAE001A7E72AD135DULL
        },
        {
            0xA348F945F0D6D28DULL, 0xD9619B2B8F8293D6ULL, 0x3BF9CCE0F80D3A4BULL, 0xCB2EA7F6079A020BULL, 
            0x7A91EF5146F69CC4ULL, 0xFA0863290D5A721CULL, 0x4018F57B067552B6ULL, 0xB2EF0C3C67DEF92EULL, 
            0xBE697A6DBAB0B27CULL, 0x75783F8363DDB3CBULL, 0x5B36DCD6356B1180ULL, 0xF99F3EBFF571A6AEULL, 
            0x447843A22C646F20ULL, 0xBF687DABC9B5587CULL, 0xD9EF5AECAF404EACULL, 0x7CCA36C42F0EF2C7ULL, 
            0xF40A010E35A5371AULL, 0xB503BC329EE16D09ULL, 0x136A5F31DF6723CAULL, 0xA4C463F40086CDC9ULL, 
            0xDA33F2B27D2F8134ULL, 0xBD4BCA4ABFE25D8FULL, 0x35ED939126747BDEULL, 0x4EB82D479FC6BEFBULL, 
            0x600DFEC5563C8F6EULL, 0x24791CA47A87E51CULL, 0x23BEA45904DA62BAULL, 0x33C5B97AEA1312B0ULL, 
            0x44B6C8B3145A9AC7ULL, 0x531BEE700555382FULL, 0xD96DB2B3AA99B98AULL, 0x8759BB1995E77355ULL
        }
    },
    {
        {
            0xBB260C24EB116195ULL, 0x7F41D01E05B2109CULL, 0x1DDD87653D29F984ULL, 0x75BD350D136D9B89ULL, 
            0x4A68D607412077FDULL, 0x7F13A0D49CECD15DULL, 0x6688FED4168758BFULL, 0xC5BB15692CAED7A0ULL, 
            0xDF2F4CC671B6989AULL, 0x8DFEAC469D4DFC7CULL, 0x66F3158E5530C747ULL, 0x27690F1B73E5E0D0ULL, 
            0x1EB52BCBF0B0A514ULL, 0xEA3EFBB14EFE9AE8ULL, 0x441A87D0F44FF8ADULL, 0xA51BE3F62275E6B5ULL, 
            0x59A00A7B59FD261EULL, 0xF87D2F8E86CC31DBULL, 0xBF52853402D9941AULL, 0xB67DEEA87ACF78CEULL, 
            0x841443EE6D4A05C9ULL, 0x2E3EFB150F200F2FULL, 0x570415048F8C8A2CULL, 0x711E2AE65E17BFBAULL, 
            0x472C084BB6588F95ULL, 0x506060F6C61A813BULL, 0xC524E3C36F1D32E5ULL, 0x1025FDE80C716237ULL, 
            0x5B3156EC1A64784DULL, 0x26B862CBAB71F55FULL, 0x6049CC45E98B9B6AULL, 0xBD5DBD353ADBE125ULL
        },
        {
            0x465EE4985AB1B100ULL, 0x20AB3B2D4F907D05ULL, 0xC0C61573D052B5F8ULL, 0xE133CF66234837C0ULL, 
            0x934734623F88954AULL, 0x98096BA0559D0CE6ULL, 0x99C8DE6073E29D81ULL, 0xB97C72DBF082AE1AULL, 
            0xDC55B4BC9284C5F4ULL, 0xFDBCF88AACC575CCULL, 0xA57D525AB988ABD9ULL, 0x661907E144798BCDULL, 
            0xC62D539F59934152ULL, 0x373C51EE05FB9E6DULL, 0xAEA758E44E6A4C6DULL, 0x708D1AE6AAA91CB5ULL, 
            0x472F6FC083CE3D51ULL, 0x703DD634D9F8EBA9ULL, 0x5C4432617B13751EULL, 0x4748F00D5932890DULL, 
            0x01DABF766998E94DULL, 0xCE6AF9EA541C8C02ULL, 0x5877A2868AAC3900ULL, 0xF8869197E6A5B44FULL, 
            0x9859A4973D47CA39ULL, 0x1A24208AE7C86008ULL, 0x2FAF03D73CB2437EULL, 0x50D143A968941E6EULL, 
            0x7C3FEA3EB6188221ULL, 0xDF4604B1037FAC7BULL, 0xA61EF35012004A87ULL, 0x8ACFD0BE53D4F6CCULL
        },
        {
            0x1E41B1DA2BCA88A1ULL, 0x5BA3E8C5B303E793ULL, 0xA91F6B7270FBF663ULL, 0x4E8B7E1BACAE01B7ULL, 
            0xF02C289B06753A7AULL, 0x5D83FA78A77271BAULL, 0x2A2FCA981F588094ULL, 0x47E97A13BFC4C056ULL, 
            0x5C864605CAE4BF87ULL, 0x71B984057C719FDEULL, 0x7794ACD30EBD868BULL, 0x63D21D04B16B746FULL, 
            0xEB1EE8EEC64E9CEEULL, 0x2244A0FA296A65B9ULL, 0x6CDA84B192EF5DCDULL, 0x96FF4B3374DEADFAULL, 
            0x8AD4802412846D0CULL, 0x665D6C35261B7A4EULL, 0x8C027B6462A3166AULL, 0x35AFB6FA33F88B99ULL, 
            0xF7AEC1D68633999EULL, 0xDA7BACFAB98C0F24ULL, 0x29ED77E70BBA9F9BULL, 0x68DB2A254E8D01D6ULL, 
            0x242A4E53BD1FA035ULL, 0x9D2A121C28500F2AULL, 0xE25C34CEC3E2196BULL, 0x61AAC529818CD0BFULL, 
            0x8F03FC18827B4DFFULL, 0xCD8E46A4B7DAF927ULL, 0x9A6D51FE83AC0920ULL, 0x824B8B5D43CE1943ULL
        },
        {
            0x8391395A50878704ULL, 0xFF7F0EE8A57DBD9FULL, 0x4AA57C677F1732E2ULL, 0xDD10746078307D99ULL, 
            0xE44ACD9576CF83C3ULL, 0x457A61AD5485ADA3ULL, 0x6BDF3A9735C84D90ULL, 0x82DDA7FB7FAACFE6ULL, 
            0x3569E3B4F5075C03ULL, 0xB95B63C1196BD2ACULL, 0xA00C812DDFD8B4E6ULL, 0xA32BB190E0ADF1EAULL, 
            0x3E1AB554EBE5307DULL, 0x8CD6AF01479FB1BEULL, 0x8489ABFD020E8A02ULL, 0xA94C12D2BEC95847ULL, 
            0x5C26C963C923F504ULL, 0xA7F5A243564CEBE5ULL, 0xAA7210EE594C8977ULL, 0xB1B77ED969439B3DULL, 
            0x73DFCE7DE1DB82E5ULL, 0x5CA61A36F7A29142ULL, 0x252A1A75DE204FEAULL, 0xE4FFFE9700BB9775ULL, 
            0xE617741369F192A8ULL, 0xEE24B02D55C22776ULL, 0x1DD71822B18286A0ULL, 0x21EF6AA2FC740A67ULL, 
            0xBF66304891FEE824ULL, 0x363E3FE58406213BULL, 0x4C19DF33E57FB701ULL, 0xFC876BA18BDF497AULL
        },
        {
            0x29C2D68607F31355ULL, 0x5AD345DBACE42DFCULL, 0x291D2CEE668AB15EULL, 0x9875408072B2D524ULL, 
            0x22D4093A40750305ULL, 0x30E8181184D0F303ULL, 0xE17BCD84A8984AA1ULL, 0xA6F389AB0B53D635ULL, 
            0xD2AD047DBC1E8A24ULL, 0xEFFE2F7B27CC1F99ULL, 0x542132E9B8814CFAULL, 0x31A7A81242D590DEULL, 
            0xB71EBE702655D6ABULL, 0xCCCDEDC8A3A51908ULL, 0xD0E647F9C6F92631ULL, 0xAB4511B554F09940ULL, 
            0x92B2AB0891187A4BULL, 0xEC6C290B041F2E1CULL, 0x93F041057357A488ULL, 0xDF6D297F6A193734ULL, 
            0xDB8EBEBDAA789916ULL, 0x7C9B19529D0F318CULL, 0x15B148886FEBD300ULL, 0x05FD391604A1C99DULL, 
            0x8AAE4DCAD3891510ULL, 0x78B61A16CD012ABBULL, 0x77E3F0FF20C0B825ULL, 0x90E29C6975CDE6DCULL, 
            0xF0A125CDA8941140ULL, 0x3EBEAA5F853B4704ULL, 0xE8B9EE41B58B09BDULL, 0xDE12EF3E8B7352B9ULL
        },
        {
            0x0451F1091CE0D436ULL, 0x0C0E543A7EDD8A28ULL, 0xEE809B52ED3620A4ULL, 0x5502D63E308945C6ULL, 
            0x546D08B9E4EA205DULL, 0x8507B6CD287BB4F9ULL, 0x4E3344278727CD1EULL, 0x8BB7AA10F9FD514BULL, 
            0x47821BE65EBDB573ULL, 0xD7315084915988FBULL, 0xFF5B0FA991115EE3ULL, 0xA4CA6B2DBFF4E97CULL, 
            0x0D462BC29C1BD929ULL, 0xF6667BA65F6F2F98ULL, 0xB7DEDB292DCAD700ULL, 0x38547D9317129622ULL, 
            0x1D627B4FBF89AF61ULL, 0xEABF2B284C6AF0C8ULL, 0xF4F2617F243CB123ULL, 0xEDB203300EEC273DULL, 
            0xEA322E9E04990F90ULL, 0x8A08DB9DA58C48E2ULL, 0xEBE4DBAEBB88EFEEULL, 0xD6902F0FB9F6FA49ULL, 
            0x605064A17AB52326ULL, 0x9BF2F694BE325280ULL, 0x23072DD2CE479BA8ULL, 0x3CDFF425D70D2016ULL, 
            0xCD9F16EC9C243570ULL, 0xCEA1BBE793ACFB1BULL, 0x751EBCDF27AB3486ULL, 0x25C3830214B46756ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Saiph::kPhaseCConstants = {
    0xDB4483CC5FBAE4FBULL,
    0x613CFD83774FE1C2ULL,
    0xD2E910AAEB00560EULL,
    0xDB4483CC5FBAE4FBULL,
    0x613CFD83774FE1C2ULL,
    0xD2E910AAEB00560EULL,
    0xD704A889CB3F306AULL,
    0x4406115FE8356942ULL,
    0x57,
    0x27,
    0x93,
    0x5C,
    0x28,
    0x2E,
    0x10,
    0xDD
};

const TwistDomainSaltSet TwistExpander_Saiph::kPhaseDSalts = {
    {
        {
            0xEAF833EC7FA8D09BULL, 0xAEFEBF7225A5BAEDULL, 0xE8FB4697960375F8ULL, 0xB737DE08F264CBAAULL, 
            0x6E89747EBF53998BULL, 0x9CB0DBC9D406FD58ULL, 0x3CDC8F820CF6A046ULL, 0xB9A25A6C74CC8DBBULL, 
            0x02DD565DACBC1C00ULL, 0x063CEA20D2457FE4ULL, 0xA217667D5C972D8CULL, 0x271BB31AA568B926ULL, 
            0x13A2CB9200E6BDCFULL, 0x4F386768406800BEULL, 0xFF3B353E4CCF84B3ULL, 0x69448B06B5AE02AFULL, 
            0x62B8DF7577AF4445ULL, 0xC954F903E47E6A54ULL, 0x21044A24251DE02BULL, 0x6AF46F513BA5FC76ULL, 
            0x1BAD8E878A10B91EULL, 0x9362BB94EB2A689DULL, 0x98702690353E6A90ULL, 0x84D54FA715FA11CFULL, 
            0xAD1BB494F3A27D72ULL, 0x7FFB37BEA34EDC17ULL, 0xA4F0FFE6955B88C2ULL, 0x6CC9857BC3415726ULL, 
            0x5018D617417EEF09ULL, 0xFBC0359190367C16ULL, 0xC1EDCC8C1FD59D45ULL, 0x0C30BC37F46469ABULL
        },
        {
            0xC8CAB7C05E7D2DCDULL, 0xC93C116CB0F291CEULL, 0xA02918A44BBE1D42ULL, 0x4B5E0F16688D1340ULL, 
            0x4E087D2898247A8AULL, 0xDD0F9D76F771928BULL, 0xAF3A06E9FDA01DEEULL, 0x3D4D3A7B4A920798ULL, 
            0xF49454F15FFAE84EULL, 0x57A4663CD8BACEE3ULL, 0x198D083F85CD9CB7ULL, 0x394E33436559992DULL, 
            0x4AF4225F02BA9353ULL, 0x9DE21F2B07E9463DULL, 0x81415CAD751D66C3ULL, 0x6E614A881606A4A3ULL, 
            0x8D8F06B977D11956ULL, 0xB453A0B0475D5C36ULL, 0xB1C256B05EB40A09ULL, 0xF88EA0FC26CE69FEULL, 
            0xCFDFE5132FF6D0BCULL, 0xF329CE4CAFF63B19ULL, 0x34563F187F278739ULL, 0x1F6CF5E2EF1FA59AULL, 
            0xA76A68288442D8F1ULL, 0xB19D1ACCFC9A5AA3ULL, 0xA7F5E5DEC4BDD4B1ULL, 0x0D7E703D83802394ULL, 
            0xF41B2CE59DF2C867ULL, 0x647246AABCFDE8BAULL, 0x0A8A28A6CAEB40C7ULL, 0x9819BE9C2F72D3B5ULL
        },
        {
            0x4D23693A558DF1B5ULL, 0x3CC1AE9BD65DBC8EULL, 0x35BD9F04817EE6C6ULL, 0xA71A86DD58C04546ULL, 
            0xD7A19527535746D0ULL, 0x7D3EA2900D61C93EULL, 0x5DA335680A8E6845ULL, 0x9F4803F5340FE012ULL, 
            0xDDA890ACB13E9D7AULL, 0x3D44B55B299F686AULL, 0x5C9C53D16FDE0847ULL, 0xBAD18AFA3F9E6580ULL, 
            0xE3520651360B2777ULL, 0xFC54C73A0B1DA8E5ULL, 0xB5BE429F6002051BULL, 0x8D9CD23CBD584C9AULL, 
            0x005532DA6C434164ULL, 0x664219FE39E6DD8DULL, 0xFDC797366B419AF9ULL, 0x428DBC0D7DFF39F9ULL, 
            0x37024CFA14407623ULL, 0xBF0E5FB8ADFB4D23ULL, 0x9DC0FEBCDD246C57ULL, 0xA503B61C7C43A1B9ULL, 
            0x8661E3C2F86F6496ULL, 0xCD76C92B35A87A8CULL, 0x46D26415A7A62DFCULL, 0xC46266DF009D8ACBULL, 
            0x19D7738F36B69F98ULL, 0xEEBAD8CB683AA3B0ULL, 0xE95E138E13A8C259ULL, 0xA194C8133C5A12A3ULL
        },
        {
            0x52D2AE7C273C0F00ULL, 0x1D3BA2C815DF7B6DULL, 0x78745C82156F3A34ULL, 0xD03C1CA374420143ULL, 
            0x0B10F7D202FF0F08ULL, 0x9D77D3503981AD9AULL, 0x640274315DB05154ULL, 0x2D5D351BC55C84DFULL, 
            0x1F5776EACF4304B7ULL, 0x01C32FA772D02C2DULL, 0xE99C89B0FC3182CFULL, 0x505B8D5532F22E3AULL, 
            0x5F4FB5B451462B82ULL, 0x3C69BA33BB4A021EULL, 0x144990222236C7D8ULL, 0xE6AA2941DBA7ADE6ULL, 
            0x3620C4446F41C881ULL, 0xF684B9C6B5DCF390ULL, 0xE29B1ED3006CF81DULL, 0xFFA27CB913EEC783ULL, 
            0xA2DAECC9E0D15D5AULL, 0xAC0BED29B35C1152ULL, 0x3C9B6B7F5CE20848ULL, 0x8BF4F26C049CD150ULL, 
            0x30B5A0D0DAD127A5ULL, 0xFA3BA3B35E1C308CULL, 0x935BB3DA3D3D6F35ULL, 0x21B211B3FDAEB05AULL, 
            0x9249A346BB3DC534ULL, 0x30B92DF122547ED8ULL, 0xBD5DA7633B3DF218ULL, 0xAAE00D3072DA400FULL
        },
        {
            0x0DE19A024A569A2DULL, 0xAD83FD621C801B91ULL, 0xF5CF858593C95F42ULL, 0x588EAAB5203C0F42ULL, 
            0xBB3B09139362EAB6ULL, 0x3EB8420C354C4ECBULL, 0x6550B33B99D78D65ULL, 0xA07BC99A1B1CAEA6ULL, 
            0xBB275788D0115316ULL, 0x813A1E7C9814CCACULL, 0x2961D5783F04A4E7ULL, 0x2B168E5BC90AABCDULL, 
            0x736300DEA32AF3BFULL, 0x198ECC4C5ECF1B00ULL, 0x56D78471FFD6D37BULL, 0xEFA926D643E42C49ULL, 
            0x3FF69CD9DA756D28ULL, 0x568088DC85EF8F51ULL, 0x34C42D2A00B9A4FFULL, 0x4D22D07B39E1C738ULL, 
            0x9C856F5EE4FB23F5ULL, 0xA093756B5B9761C3ULL, 0x3617B24601A3A05DULL, 0x28B781B37019A793ULL, 
            0x5099AAE3E2189554ULL, 0x1481BD7701EB470EULL, 0xFED3A64F551E347CULL, 0xD19D62BB69212133ULL, 
            0xDB3E75E57220C3E6ULL, 0xA9A1B88A9A7E0CC4ULL, 0xD8314CABC1BD8CDCULL, 0x7605B9CC3395DB1FULL
        },
        {
            0x8A497E587C97B2E9ULL, 0x6753F0428FEC3849ULL, 0x9F29EB0F9B82C7C5ULL, 0xDBC909C0BB406BD0ULL, 
            0xAA91E62193FB5892ULL, 0x7801E470E55ABD37ULL, 0x82627229F504A4CBULL, 0x9EA8F8865C76B67FULL, 
            0xCC317C410BB3E8A1ULL, 0x0FCA79416BF7132EULL, 0x566018920F36CC4BULL, 0xA435BB3163CF601FULL, 
            0xD49BF589CBBE154DULL, 0x648F61EAE71214C3ULL, 0x93AED1B39B2890DBULL, 0xBBDB1E35E372EA1FULL, 
            0x6F053D6BD5C52458ULL, 0x94BE239F3B64ED75ULL, 0xD895C1D5C7C51167ULL, 0x45B6315269C6D665ULL, 
            0x00EB38A7030444FAULL, 0x5020F6368EB0A450ULL, 0xBA83DB3204C791A9ULL, 0x37E06752CF752F95ULL, 
            0x0E14976E71FC90F9ULL, 0x369470EE89ABA9F6ULL, 0xD2E79D356011CD6CULL, 0x85B1A11066512238ULL, 
            0xFECB4DBB8151E4E5ULL, 0xC7086E29896AD6E5ULL, 0x46293936297E637BULL, 0x0BB815F91A8F428BULL
        }
    },
    {
        {
            0x8E0AE512693E7046ULL, 0x9879CF0B2D94A4EAULL, 0x26F8E09BBC8D737EULL, 0x0C50040CFBA5E96EULL, 
            0x664DC5989B9FBC3FULL, 0x4B358CAAF3FF33D0ULL, 0x4FF5FDDA768C576EULL, 0x8ED18F170FF859CFULL, 
            0xA7D2D2CD3884277FULL, 0xFC0F662CBCE2F08AULL, 0x89F7274F50716AE2ULL, 0x89A203F145689595ULL, 
            0x9095D3569BF2B010ULL, 0xCB26B02E047C29ABULL, 0x9543B262E5AFCFB0ULL, 0xB58C1621346DC827ULL, 
            0x50FC262C1D413AB0ULL, 0xE5805C107C59C6E0ULL, 0x17347BE63CD624CBULL, 0x6CA8DB9DC1D973E7ULL, 
            0xD968C7531D85EF68ULL, 0xECC4635D8C089CE3ULL, 0x253E0344C71CE51AULL, 0xA53AD086938E3D4DULL, 
            0x782E140ABF405196ULL, 0x1D57D51DD423E4EEULL, 0x62E59B78774F9F80ULL, 0x1D87B12A307377B2ULL, 
            0xEF22FFB5377A15E8ULL, 0xA1199AE4D851E7B2ULL, 0x9267680BF018813AULL, 0xCE8B4AC1DD6A4DD2ULL
        },
        {
            0xBA8CD4198E58700FULL, 0x4EF29CEDB20080F7ULL, 0x15F265085A028434ULL, 0xF59C627DC0815F8AULL, 
            0x7D8B35E5269664B6ULL, 0xCCE1B94C10F18D07ULL, 0x9CDD8CAA8C590924ULL, 0xC1BAF94356C13664ULL, 
            0x0E89269F252E54AAULL, 0xE23C020D9357E403ULL, 0x14A2B2A3285AA9C6ULL, 0xDA798364D66A6C89ULL, 
            0x4E5F532CC677AF81ULL, 0x95760EC1AB39DC5EULL, 0x20FE64BD0DC3E4F4ULL, 0x32679DBB9940B256ULL, 
            0xBA15B69F9E11556DULL, 0x1CF91B8EA1E6C438ULL, 0x3BEF1EC662FF08ACULL, 0x4995774AE8C1B9DDULL, 
            0x2A19447417EDD705ULL, 0x0F5BF32F4A3D26ACULL, 0x2D8FE685118045ECULL, 0xFBDB08A6DA56F45FULL, 
            0xB13B1E8186597A3FULL, 0x33A6DC5ACDDDF48BULL, 0xC63C8E152842BB0CULL, 0x6940B6DC83C15D40ULL, 
            0xB7F3DF9293924BFBULL, 0xB5F3140DCFE787DFULL, 0xCFB9F6A0418F2F4DULL, 0x650D665E99AEA2F2ULL
        },
        {
            0xC2AC447FB194AD47ULL, 0x1CF19E73BD168973ULL, 0x4D0F2407C68DA3B4ULL, 0x8B35D3E09B954087ULL, 
            0xD0D374393FFB940CULL, 0xAA142AF156A01651ULL, 0x8495742ADA4575BDULL, 0x9383DFAA4B05268CULL, 
            0x4C79016857B2D69CULL, 0xEF1433C8B84EDE63ULL, 0xAF224C8036E7A307ULL, 0x93985E06CECAC83BULL, 
            0x9BCC9BA1C0DF16EEULL, 0xFC48C77A025040DFULL, 0x6FDF820B999234A7ULL, 0x7542E2F3438E5327ULL, 
            0x0ED5CD1EC6A8C444ULL, 0x48FDE00B55E85D6BULL, 0x6D4F44F6D78BE501ULL, 0x9FC467558BD06069ULL, 
            0x54688A867EE56DDFULL, 0x08DC6D2AE9DFBA38ULL, 0x1FA38A54C7160FD0ULL, 0xA569C2F9C23FADF9ULL, 
            0x9261B8710B381E50ULL, 0x99CAD7CB1A657927ULL, 0x71550C7A03490961ULL, 0x09A1581648E27DEDULL, 
            0x89A8DEFBE1C3E2C5ULL, 0x8857E71FB117BD4BULL, 0xCA89D619A411A0F4ULL, 0x6441B3FAB2C65813ULL
        },
        {
            0xCD6F089F0E423011ULL, 0xF34C960697F66C42ULL, 0xD1B9528173447DF4ULL, 0xDC02C12F28197150ULL, 
            0xE19C5AB78AF09110ULL, 0x22701E11BAF12E0BULL, 0x0C766E08048072CCULL, 0x6497967A439374FCULL, 
            0x0A7FE0DB0394288DULL, 0x3A1F9F28EA2C5341ULL, 0xBB0D63D865B9CD16ULL, 0x9133C4F5BE91636AULL, 
            0xE5956333C24104D6ULL, 0x9B3515B2C3C77B08ULL, 0xAE73C91520BC1A52ULL, 0x28DC1CB3C5301E2EULL, 
            0x83C66ECF757B4C16ULL, 0x9D1131D47702FD2DULL, 0xCCC3667AC7FFB9D3ULL, 0xD883CAAD3468FD21ULL, 
            0x63FE2F0E459A8EE9ULL, 0xFD1A5891C2E6554CULL, 0x90825E06FF821C56ULL, 0x8255F9B00B290461ULL, 
            0xDFC75D882B30D933ULL, 0x0F5FAF6FF110270AULL, 0x760D2B6E70B5EB24ULL, 0x6602948E32A44D59ULL, 
            0x9B18C7E56CCC0BDDULL, 0x7793A95F6492CBC0ULL, 0xED151079357E9F98ULL, 0x4461B9AB90A5C00DULL
        },
        {
            0xC027718E44557107ULL, 0x5F521E0B804412D8ULL, 0xD5BE444FD0EDDBE5ULL, 0xB5E0E9F2E233B147ULL, 
            0xB7FFB2CA2B8C94DEULL, 0x70AA359C1618DA5CULL, 0x90EE5FFE2AFCC98DULL, 0x72053510EA7781AAULL, 
            0x4B618D669206F773ULL, 0x653F2CBFE062D435ULL, 0xAD68A5156D514174ULL, 0x82B4D3DBDFF14BCDULL, 
            0xF5CBCFD9C10EA4CFULL, 0x1CB23C999AF8E838ULL, 0x85C0A2CC03F9F8CEULL, 0x5063BE97BC59A1A4ULL, 
            0x3D6BB717383831E8ULL, 0xE9D8FE5492F3CAAFULL, 0x05F775964F4C57EAULL, 0xFFA1AC00E0768AE4ULL, 
            0xD6436925FB821372ULL, 0x11E9913553854E48ULL, 0x52417CCE057F95F5ULL, 0x3E32F9439C39802EULL, 
            0x8836E44A467309CDULL, 0x4BCB062889E5CE83ULL, 0x20D99DE3D33E0CABULL, 0x836D0CDD610EDCDEULL, 
            0xE2935ED20DA49B38ULL, 0x320C72AE34EE40D9ULL, 0x0100F8F278BAE945ULL, 0xD8FA2314D1156226ULL
        },
        {
            0xEE90B5F2344E559DULL, 0xFDD6B786C9441049ULL, 0x2560F5FE0C5CF261ULL, 0xBB3CFF75CD336812ULL, 
            0x3EC40589E62CBB69ULL, 0x529FAEE5C347F856ULL, 0xA01EB4401B353836ULL, 0xBB3228CE6A27935BULL, 
            0xCAB6AE0714F2EB73ULL, 0xA53EEA83BFA6F9C2ULL, 0x856677F3A41D9842ULL, 0x717509674383C086ULL, 
            0x43CABE9A98DD7649ULL, 0x1D0C72828A51DAA8ULL, 0xE50F5AD957BE1FF8ULL, 0x949EBE2CDF03E47EULL, 
            0x451DD0B3B0CAB210ULL, 0x2230182B35265C6BULL, 0x9E38CE84A5E7664BULL, 0xD8F5AF3E646D0096ULL, 
            0x143F5C296E8B60B7ULL, 0xFD680C8DB49F38EDULL, 0x5D6AF6F40A5CB665ULL, 0xA2677303256E6BF5ULL, 
            0xD475485006A5941BULL, 0x98068050F580535CULL, 0xF2FDC026978E67FCULL, 0x07792CB391AC21CCULL, 
            0x6BCACD5A6D6C4AEEULL, 0xBFFF8B045C363696ULL, 0x5EF7C5FA640E5D58ULL, 0xA2B7DE93DA16612BULL
        }
    },
    {
        {
            0xC089E2083EB4BAD0ULL, 0x900939C6A6412ACDULL, 0xF0B56109446881A4ULL, 0xDAEBD5C0BC5FF594ULL, 
            0x4F0D3EC59C3F055CULL, 0x4246B03F29E8C9DCULL, 0x374D8E9D6799EBF8ULL, 0x6978774850EA6B95ULL, 
            0xEBE81493939EAEBBULL, 0x2FA1E75C45F8F09BULL, 0xEFD2B295AD5A588FULL, 0xF180C05C7FDBA3A9ULL, 
            0x7F2C0D46BD400145ULL, 0xD167CB50F5F18D45ULL, 0x58AF7C5421BF3B70ULL, 0x30A44B55DDF159EFULL, 
            0xCBDCA7BA70D33613ULL, 0x09E916D70120D731ULL, 0xBBBC2BB0836A1E84ULL, 0x3130D86F57C63D70ULL, 
            0x5E60E90365DD0709ULL, 0x32DB7ED8E2F788B6ULL, 0x1B7D078B84A423E3ULL, 0x336A35985340C931ULL, 
            0xE2C9DFB058F02BCFULL, 0x3C90EA136414B772ULL, 0x5F9C469449604CFFULL, 0x392917606045215FULL, 
            0xEA05061CB8CF1651ULL, 0x5CB14F49857036CAULL, 0x8BADDE26FA2CEBFFULL, 0xE1DB5AD9CE91FB8AULL
        },
        {
            0x7073C7C055A79C73ULL, 0xB13ED457591CBDF1ULL, 0x0196B8F6F813B07AULL, 0x59586E069909F7E5ULL, 
            0x7BC7326C70ED532CULL, 0x065C8A78E27840F0ULL, 0x50FF19D636D23B3AULL, 0xD384A68597F8E4E6ULL, 
            0x9F0D9CC70128BA98ULL, 0x468F284B3CFDAD71ULL, 0x3CB8F0F7F9B416AEULL, 0x480A2581F8E46405ULL, 
            0x64F51810B087780BULL, 0x83D1F3E5FA2D0C84ULL, 0xF91AEF1BB54AD0B4ULL, 0x51122C3494C27551ULL, 
            0x696B16C983C08EBBULL, 0xEE476C6113896C54ULL, 0x5B01C20E616B453BULL, 0x61618E20E6FD14D8ULL, 
            0xE1E123C19BA8EA4DULL, 0x471510B62EAFDBAEULL, 0x06568D05D82421CCULL, 0xEE6FE85BF054EEBDULL, 
            0xB49DCF3C2B8849BBULL, 0x33CCBA0C61BD042EULL, 0x28563F179CB7E8D5ULL, 0x702F0D8956AC96C5ULL, 
            0x281418532E393FF4ULL, 0xD6172425DC301004ULL, 0xD909811E6EE376B0ULL, 0xCD2210E978FAA08FULL
        },
        {
            0x9CC9634BC1BC148CULL, 0xBBBC245075DF764CULL, 0x5F2028B8F887E640ULL, 0x47055DB66696D9E9ULL, 
            0x24D1B7AED68DB97AULL, 0x3BF02BCBC8ADDEAEULL, 0xE2BDC040B8644934ULL, 0xA3335E8009E269FDULL, 
            0xE30660565804B405ULL, 0xA097BB01C36C960BULL, 0x20A4A7625E0F3B71ULL, 0x37815CD849DED86AULL, 
            0xA04D333AE2C99243ULL, 0x2D53EA7316078FDCULL, 0x7D562127C0C5FB31ULL, 0x390CB022088BFCB4ULL, 
            0x8E682EACA16E7E35ULL, 0xB46927CF2C0AAC34ULL, 0x81337045DC5BCD8EULL, 0x817BCAA1FF1FDECDULL, 
            0x235E4A24BB062111ULL, 0x1C6C7756587AF2EBULL, 0x4DAE3CE09ED7BB67ULL, 0xFE1156D962BD6F73ULL, 
            0xC4F09924CA0376CDULL, 0xEC3F1F69B82AFCFFULL, 0x9013EBCFBC72A300ULL, 0xBDE57978EEB552A1ULL, 
            0x09864A774650A6B0ULL, 0xA326F8803C8FA061ULL, 0x17CEB1EAE3F6BB20ULL, 0xB13D56FA77DB196CULL
        },
        {
            0x0F8464AF765DFD21ULL, 0xAF31FFA425EF0C00ULL, 0xB810F19A533344B7ULL, 0xE0C1995FD4198144ULL, 
            0x3A483A611DD95F7AULL, 0x48403131F2642D03ULL, 0xA45499385D27F3B3ULL, 0x93664EC5AB114177ULL, 
            0x056C8EE87BA48092ULL, 0xB61CAE1A9E31ED7CULL, 0xC4727BB520F59F09ULL, 0xE0DA100938FAF14DULL, 
            0x5BD2A02CE19C1DA2ULL, 0x6F343BA71227977AULL, 0xE9A326D5AAE76E31ULL, 0x679CECDA90FD2DECULL, 
            0xF0F14E8EB2FCE2F1ULL, 0x6DC19B6C04ACFD3BULL, 0x119B579168F71C0EULL, 0x3FED0A08FC1B34C4ULL, 
            0xEEFAD6246C6B8580ULL, 0xF0980DC43C67DCF7ULL, 0xFC383B2E05E0CEE7ULL, 0x70DE8E12462FDB12ULL, 
            0x766DAD3EF76B75DBULL, 0xDDC6C059A005D1F1ULL, 0xFCD361130B692774ULL, 0x3ADC4F1B7536F26BULL, 
            0xAF2A0508AFBE3CD2ULL, 0x07C96C61AA489112ULL, 0xCFD9D2BFC61ECC8BULL, 0x85A08DB4B8EBBB36ULL
        },
        {
            0xF6CB4C9072437F6DULL, 0x8ED6E9F00BF6B79EULL, 0xFF7D9E6226EFD7FEULL, 0xF93C1E3250CBA280ULL, 
            0x626048D918CE6D1CULL, 0x828DC90B82D7284CULL, 0x83C2F42C4725C4F0ULL, 0x922D6BE28357E904ULL, 
            0xAD072F3053753D72ULL, 0x5AF3FBA65451FC3FULL, 0x761111C5F7A64839ULL, 0x6FE2BD273A0A452EULL, 
            0x212F341F1FD42F17ULL, 0x96E3FB2399CAE9E8ULL, 0x6819F5EDF06EE148ULL, 0x514F8CCA77AD1037ULL, 
            0xD5850F3AC7C7DBC7ULL, 0x96683F86218F628AULL, 0xA79EAEB6FDE36355ULL, 0x308C8E0500EC557AULL, 
            0xEF3E672607D48F33ULL, 0xEBC5E00B5995908AULL, 0xD59A24C996B01E10ULL, 0x4ECF45287E44E282ULL, 
            0x8DFA7E6820314D9AULL, 0xD51EA84AC598C4C3ULL, 0xBC5BA1577A694F3FULL, 0xA2117C63541F6DC4ULL, 
            0xDD14200662893082ULL, 0x52EFAF5FBF69F5B8ULL, 0xB088929124DE323EULL, 0x67171AB0A356011CULL
        },
        {
            0xC2A701121FD1074CULL, 0xE87D83AA7B5BCEDCULL, 0x03F063DC874CBF46ULL, 0x876243B68723C1BAULL, 
            0xE331DAE662DAD6DEULL, 0x88F0748091927109ULL, 0x63D38163EC7E3A0CULL, 0x658CD1DEC0009DB8ULL, 
            0xB3C87626810FA8BCULL, 0x3272CB236BDD4BBCULL, 0xB905428783E31705ULL, 0x9F8F1FC215858CBDULL, 
            0x351310D2613E0418ULL, 0xFA18F5CA15AE962CULL, 0x864F12964A94C9A3ULL, 0xE58D8EA67FD96CB2ULL, 
            0xAEE52C4289BBDE8CULL, 0x8AF7BCBA603B26A3ULL, 0x20E795A78920FCE5ULL, 0xB84F4B91B051A0BCULL, 
            0xDF9B91752CC45B3AULL, 0x5E98827CBF026614ULL, 0x51FE7C4F325DCA39ULL, 0x815D7AA983746BC5ULL, 
            0x031B8EE22BE9442FULL, 0x61C0B1B266DA4B4EULL, 0xC31BF29550DD3C79ULL, 0x84143F741F6240FFULL, 
            0xE6628AA6295345C4ULL, 0x5E9747F05A591B0CULL, 0x0955A84547ADB486ULL, 0xA06D5010CF7768E4ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Saiph::kPhaseDConstants = {
    0x24F332E25F6AC404ULL,
    0x9477FA75EADC9295ULL,
    0x59F91B7ECE4D3C3EULL,
    0x24F332E25F6AC404ULL,
    0x9477FA75EADC9295ULL,
    0x59F91B7ECE4D3C3EULL,
    0x404C8B734E80268EULL,
    0x6086FB8EBB8E79ADULL,
    0xF3,
    0xA5,
    0x83,
    0x96,
    0x6F,
    0x02,
    0xA4,
    0xE4
};

