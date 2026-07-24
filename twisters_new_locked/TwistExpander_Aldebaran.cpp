#include "TwistExpander_Aldebaran.hpp"
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

TwistExpander_Aldebaran::TwistExpander_Aldebaran()
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

void TwistExpander_Aldebaran::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xAF006D366DD6686AULL; std::uint64_t aIngress = 0xE3C0B0E5F5D54885ULL; std::uint64_t aCarry = 0xA596B4A7E59CC538ULL;

    std::uint64_t aWandererA = 0xF72DA7D091B05B9AULL; std::uint64_t aWandererB = 0xCF199577104A8A00ULL; std::uint64_t aWandererC = 0xC71DCD166797665AULL; std::uint64_t aWandererD = 0x97DB4B8CD1E5620EULL;
    std::uint64_t aWandererE = 0xC087ACEE5319DB2CULL; std::uint64_t aWandererF = 0xC8DEE6895705E9BFULL; std::uint64_t aWandererG = 0x935D9197A4BF12E7ULL; std::uint64_t aWandererH = 0xCA369786B67A08DBULL;
    std::uint64_t aWandererI = 0xD166AE32E8F9E430ULL; std::uint64_t aWandererJ = 0xDF7F75D554ACF1B6ULL; std::uint64_t aWandererK = 0xB93FF319D0B9E109ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xB6D29A8CCA9F6A26ULL;
        aCarry = 0xA96F0F44BB6E0ADEULL;
        aWandererA = 0xAC96499D370567F3ULL;
        aWandererB = 0xEBB71A703A40775CULL;
        aWandererC = 0xCE8907E2066213F9ULL;
        aWandererD = 0xEE7CD5923B329F73ULL;
        aWandererE = 0x83ECD882EE6B21EAULL;
        aWandererF = 0x90195D2FE6F7B187ULL;
        aWandererG = 0x9B79D1FA6062BBAEULL;
        aWandererH = 0x943D633250241BC0ULL;
        aWandererI = 0xEDA8E109A7777728ULL;
        aWandererJ = 0xF51DF3A9091B9152ULL;
        aWandererK = 0x88649E0237015734ULL;
    TwistExpander_Aldebaran_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Aldebaran::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xBD4F93C92DB56C22ULL; std::uint64_t aIngress = 0xF809D2B960A6BEC8ULL; std::uint64_t aCarry = 0xB0D58B2DA295CB1CULL;

    std::uint64_t aWandererA = 0xACA4C8383898A230ULL; std::uint64_t aWandererB = 0xF9EDDAD50BAE4D39ULL; std::uint64_t aWandererC = 0xC90E964A80114C34ULL; std::uint64_t aWandererD = 0xD9E3984C6243DE96ULL;
    std::uint64_t aWandererE = 0xE10227D7E403AE94ULL; std::uint64_t aWandererF = 0x9D61C681C27F1F12ULL; std::uint64_t aWandererG = 0xC956B1E3D0C2A15CULL; std::uint64_t aWandererH = 0xFE2B8032B1F72F6CULL;
    std::uint64_t aWandererI = 0x996F85AD63A5E8B8ULL; std::uint64_t aWandererJ = 0xE486F2A541305870ULL; std::uint64_t aWandererK = 0xA2E87FDD4C41A141ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xD5F9BA916F925DCCULL;
        aCarry = 0xB1E0ABDB94F82685ULL;
        aWandererA = 0xEDCB3CF24D6C210AULL;
        aWandererB = 0xE0A90D9915FED192ULL;
        aWandererC = 0xD7FC17EB6AC01835ULL;
        aWandererD = 0xBFFF5B385094953BULL;
        aWandererE = 0x9B1C891B2C655362ULL;
        aWandererF = 0xB2466E6CA86FA753ULL;
        aWandererG = 0xBFA90A67B4DA3F2CULL;
        aWandererH = 0xA7B0C843D334FB62ULL;
        aWandererI = 0xA15D9A3F8CBEABA6ULL;
        aWandererJ = 0x98F3AABD46890C19ULL;
        aWandererK = 0xFD597CE901B42D71ULL;
    TwistExpander_Aldebaran_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Aldebaran::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x92D247F7E9FDB626ULL;
    std::uint64_t aIngress = 0x8932363CE0ACFEB8ULL;
    std::uint64_t aCarry = 0x86B19A596B28FAB6ULL;

    std::uint64_t aWandererA = 0xB3912D0A81EE2C5DULL;
    std::uint64_t aWandererB = 0xB8F20239FE0BF91EULL;
    std::uint64_t aWandererC = 0x929ECBCDB2BBB0ACULL;
    std::uint64_t aWandererD = 0xBE07D196AF2B76A0ULL;
    std::uint64_t aWandererE = 0xF0347B19B16AF128ULL;
    std::uint64_t aWandererF = 0xE86A843C33045228ULL;
    std::uint64_t aWandererG = 0x84DC03B46A15376BULL;
    std::uint64_t aWandererH = 0x819CD0B0FDB5C570ULL;
    std::uint64_t aWandererI = 0xCA2F4B2FC6AD83E0ULL;
    std::uint64_t aWandererJ = 0xDA97C5B35BBD5F10ULL;
    std::uint64_t aWandererK = 0xB0A671D9AF028C4DULL;

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
    TwistExpander_Aldebaran_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::GROW_B(pWorkSpace,
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

// SmartSquash candidate 3 of 33
// Exploration cases: 100000000
// Nearest-family diversity: 1076 / 1088 (98.90%)
// Total distance from earlier candidates: 2152
void TwistExpander_Aldebaran::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    static_assert((S_BLOCK / W_KEY) == 16, "SquashInvestToKeyBoxes expects 16 invest fragments.");
    static_assert(H_KEY == 8, "SquashInvestToKeyBoxes expects 8 key rows per box.");
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 4U), *aFragmentB = aIceLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 11U), *aFragmentD = aIceLaneD + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1296U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1632U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1699U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 365U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 15U), *aFragmentB = aIceLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 0U), *aFragmentD = aIceLaneD + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 282U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 524U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1746U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1483U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 11U), *aFragmentB = aIceLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 6U), *aFragmentD = aIceLaneD + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 2011U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1637U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 480U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 785U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 1U), *aFragmentB = aIceLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 7U), *aFragmentD = aIceLaneD + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 995U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1995U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1459U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1999U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 13U), *aFragmentB = aIceLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 2U), *aFragmentD = aIceLaneD + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1477U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1346U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1653U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 777U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 12U), *aFragmentB = aIceLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 1U), *aFragmentD = aIceLaneD + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 226U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 35U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 616U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1130U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 7U), *aFragmentB = aIceLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 8U), *aFragmentD = aIceLaneD + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 913U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1786U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 0U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 915U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 9U), *aFragmentB = aIceLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 12U), *aFragmentD = aIceLaneD + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1778U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 655U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 619U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1812U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 10U), *aFragmentB = aIceLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 4U), *aFragmentD = aIceLaneD + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 395U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1022U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1819U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 854U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 0U), *aFragmentB = aIceLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 15U), *aFragmentD = aIceLaneD + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 102U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1118U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 473U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 2035U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 2U), *aFragmentB = aIceLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 10U), *aFragmentD = aIceLaneD + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 944U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1272U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1813U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1899U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 3U), *aFragmentB = aIceLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 5U), *aFragmentD = aIceLaneD + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1031U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1830U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1002U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 426U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 5U), *aFragmentB = aIceLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 9U), *aFragmentD = aIceLaneD + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1422U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 219U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1060U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1908U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 6U), *aFragmentB = aIceLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 3U), *aFragmentD = aIceLaneD + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1563U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1456U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 320U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 127U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 14U), *aFragmentB = aIceLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 14U), *aFragmentD = aIceLaneD + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 968U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1906U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1942U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1437U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 8U), *aFragmentB = aIceLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 13U), *aFragmentD = aIceLaneD + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 603U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1165U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1583U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1075U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Aldebaran::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE45FF512D8BD7CCBULL; std::uint64_t aIngress = 0xD6F934413B23ACABULL; std::uint64_t aCarry = 0xB2E085DED11643DDULL;

    std::uint64_t aWandererA = 0x8192FF3202CB7AA5ULL; std::uint64_t aWandererB = 0xA8D5AFFB4E4C72D1ULL; std::uint64_t aWandererC = 0xF66FFCCB19683FEFULL; std::uint64_t aWandererD = 0x9EF937CA90756FC9ULL;
    std::uint64_t aWandererE = 0xA81D89A7FAAECC39ULL; std::uint64_t aWandererF = 0xB23F6ECB3F01076DULL; std::uint64_t aWandererG = 0xBA4D930742921B35ULL; std::uint64_t aWandererH = 0xE49C538D645D3D5DULL;
    std::uint64_t aWandererI = 0xE2E830635841EE4DULL; std::uint64_t aWandererJ = 0xEB75503B86816D28ULL; std::uint64_t aWandererK = 0xAE0890E754EBA5D6ULL;

    // [seed]
        aPrevious = 0xE589038AD6634D78ULL;
        aCarry = 0xFDBC8213A78CCAB4ULL;
        aWandererA = 0xE7A9C59D699B1E71ULL;
        aWandererB = 0xB20E03055FE4EC9CULL;
        aWandererC = 0xE2FFA5F55C70F892ULL;
        aWandererD = 0xFF49D4A58C2A9BFAULL;
        aWandererE = 0xF5963B95103CAA66ULL;
        aWandererF = 0xEBD29D8374C836F1ULL;
        aWandererG = 0x85DA8BA500778235ULL;
        aWandererH = 0x88664038CD19B3DDULL;
        aWandererI = 0x97D03F4F0716C226ULL;
        aWandererJ = 0x8732A22CDCADB806ULL;
        aWandererK = 0xB0F54BD10B0B041AULL;
    TwistExpander_Aldebaran_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Aldebaran_Arx::Twist_E(pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Aldebaran_Arx::GROW_B(pWorkSpace,
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

// GrowA candidate 3 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 1255; nearest pair: 625 / 674
void TwistExpander_Aldebaran::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3046U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5845U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3511U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 89U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3772U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1558U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6026U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8132U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 8U);
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
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3065U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5981U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6797U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7144U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 275U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4028U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7749U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 392U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1528U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1823U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1478U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1115U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1321U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1002U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 431U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 479U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1447U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1801U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1866U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1783U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1582U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 30U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 90U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1160U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 102U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1000U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1518U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1793U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
}

// GrowB candidate 3 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 1269; nearest pair: 633 / 674
void TwistExpander_Aldebaran::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5620U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2867U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7077U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1259U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6816U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6319U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 478U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1141U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 182U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4514U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4007U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2064U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8001U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7044U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2261U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 864U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 352U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 217U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1080U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1397U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 363U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1298U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1131U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1593U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1166U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1502U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 393U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1477U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1167U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1691U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1379U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1440U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 950U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 292U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1228U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1890U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
}

const TwistDomainSaltSet TwistExpander_Aldebaran::kPhaseASalts = {
    {
        {
            0xCA8FCF478ADE79C4ULL, 0xBE1ECC87ED15EF8FULL, 0xBA25EED6B81A2762ULL, 0xA101B4AB4CA556D3ULL, 
            0x8826B1189B16A419ULL, 0xF8995F8F407D7F75ULL, 0x11893E829CE28130ULL, 0x06CB00FA7A29093DULL, 
            0x3231DC29B7ACE965ULL, 0x247554E0F2F49521ULL, 0x8A6CA4696FB4FFD0ULL, 0x564D368B1A2D928CULL, 
            0x0CA5FF04243C640EULL, 0xDC2A9E737A675D0BULL, 0xA044A25DDE855468ULL, 0xF7217746A91A8240ULL, 
            0x87A27159C7619200ULL, 0x11E69DB2642DD79BULL, 0x25A03BD2AA6BD442ULL, 0x552A10D5F064936FULL, 
            0xF54989DE8527ED05ULL, 0xB37480D57E967E31ULL, 0x8A7E31D3AF50B308ULL, 0xF3CE4F4D306FBF2EULL, 
            0xDDD42B84B9A494FEULL, 0x30A8EF1698236BD1ULL, 0x6DE454C08DA3C6CAULL, 0x16CE62D26A6DC9A0ULL, 
            0xFD703D2EF9243183ULL, 0x3C87503810B78A47ULL, 0x3FE8AEFD99E62509ULL, 0x7BBAB58E9EC8B73FULL
        },
        {
            0xAF1DA36B1CFBB842ULL, 0xE5320C1F132D7E1EULL, 0x20E95A0F03D17B50ULL, 0x32C9491A3C3A5833ULL, 
            0x96492044DA49C792ULL, 0x79E8EEE413BCAE22ULL, 0xEA02BF8ED8524B00ULL, 0x91D1FE24F4B161B1ULL, 
            0xC9FA8E5D4C9DD114ULL, 0x95967274146C9DC8ULL, 0x8FF8A34BEE4393BDULL, 0xDB9C491B17B64B24ULL, 
            0xF6BA1C8740F4C1F3ULL, 0xF2B1B82D51D0B774ULL, 0x0C7BAD4B06F993FCULL, 0xE127FF7F38E4686BULL, 
            0xE6CE7F7AF6A51BAAULL, 0x102D9A3ABAB4FE91ULL, 0x9D59B7F7748E2323ULL, 0x49E989F9BF0AB625ULL, 
            0xDA72149492408713ULL, 0x048310B91E608E79ULL, 0x1D9013E102935285ULL, 0xCC6A66B133779A6BULL, 
            0x0BFC367BC60FEBD2ULL, 0x3406CE457673C4B2ULL, 0x22AE960BB2098348ULL, 0x95C4A660D4020E3BULL, 
            0x153040D1E94DDE52ULL, 0xD0B52548625EEEBDULL, 0x2F46E45464ACC7DBULL, 0x666C5871BD9FB9C2ULL
        },
        {
            0x38E694F37CE03427ULL, 0xC8182A4B31117C40ULL, 0x1F8E8D6E98A6B7D3ULL, 0xD2650B9135C2AEB5ULL, 
            0xD3A72445279D62E6ULL, 0xEEC26B20B4F0DD44ULL, 0x6CF0658963957246ULL, 0xA5D6F4E3198E6D5EULL, 
            0x10007E6C0A14B2F7ULL, 0xAB8B8A968C9F15CBULL, 0x2E09AA498DCCD487ULL, 0x1CB5BE2FB7CE9383ULL, 
            0xF202C7FC9E16E8C0ULL, 0xC61EB5379F8B9489ULL, 0x22B42E26809DA3B5ULL, 0xBD5348ED9A4C7C87ULL, 
            0x9E0179FC79F69A7FULL, 0xB07DD65FD9CE015BULL, 0x122C5894B2229115ULL, 0x7EFE9ADF43872E43ULL, 
            0x7B0CBC5C61CA5889ULL, 0x591FFB75DA0A1751ULL, 0x6F900548F9F5BA4DULL, 0x27980BA4E10CA2E3ULL, 
            0x4E64664808AFC7D1ULL, 0xF79D255D1ADB1223ULL, 0xAF6B21C48725293CULL, 0xAD4950B5A647CCC2ULL, 
            0xB1D3C87F8A4EFC92ULL, 0x789717960EE414CBULL, 0x0CD95C8F30FD6FCDULL, 0x603CDCDA1FA69D94ULL
        },
        {
            0x63369D6752B2CF5AULL, 0x7E9A3A42BFBE63A6ULL, 0x9B5988F4EDF8420EULL, 0x99DCA2F5D848F353ULL, 
            0x884D274D586539E8ULL, 0xBAD111DCA1077703ULL, 0x7D6B3E3C66344070ULL, 0xBF55206F57AF976FULL, 
            0xF6621562D6884CB8ULL, 0x528688EC753105A1ULL, 0x3E373112954477C3ULL, 0x8AAC8DF21ED3E797ULL, 
            0xACB76BCFBC07F5AFULL, 0x86E748AD9259D8BBULL, 0xABBF6A98FA322687ULL, 0xCD4FF61E1AD53E39ULL, 
            0x97508AC6C38C18F6ULL, 0x5A5A5B7571291BA1ULL, 0x5C988613A7CA86A3ULL, 0x9794DF1C43CC3B71ULL, 
            0xD3F0501001B934A3ULL, 0xB89C30D75EDB4293ULL, 0xD1AFD54888CF09EAULL, 0xAB57F3698875C9B9ULL, 
            0x82B3FC9910F7E01BULL, 0x8FBF1D90067E963CULL, 0xF75BDE85FA5825C5ULL, 0x50A0DD90A18CACEBULL, 
            0x902904C99B738501ULL, 0xB23AA74D0811689AULL, 0x308FE20D93B86D9FULL, 0x1D0D03997AA886BCULL
        },
        {
            0x9C8A1C4A7A0B7DD0ULL, 0xC660F0E75BFADDA8ULL, 0x9004AC32AF9AAF77ULL, 0x41BF88A769B6AB2AULL, 
            0xA05ED13614B4CDBFULL, 0x8D8C3D42A20A799EULL, 0xB4E9BB7C961F46B3ULL, 0x729DD1BC8AEFD8A2ULL, 
            0x2F95337714F4B70FULL, 0xCB91B6A4C24AEE31ULL, 0x6D18990982F6816AULL, 0x3D645E2DE00DD3AEULL, 
            0xA977FDF2E2226D9DULL, 0xA6BE6520CDB4A2BEULL, 0xFDFE012A8027297CULL, 0x5F002B38BEF034ABULL, 
            0x629021EF0255193AULL, 0xDA2549041E92A412ULL, 0xC43AA88122F674A4ULL, 0xE7C1714216AA409AULL, 
            0x16248605A06DDDC1ULL, 0x418B5F5802E7294EULL, 0xE27A37A1E2599390ULL, 0x8DADDABFF61D80AFULL, 
            0x19D42B388FBE2B73ULL, 0xACF14FF3A27DCB09ULL, 0x388C3E0AC5BA3DCBULL, 0x148A1B6C31F128F3ULL, 
            0x5A0EEE3C9351358FULL, 0xCE265CA9B781097AULL, 0x52E9A55E37FAE511ULL, 0xC305C6ED06AD04A4ULL
        },
        {
            0x328026299BF35AC3ULL, 0x1730F4377CEC3A8EULL, 0x5E136DC78F9304E1ULL, 0x1830C5768080232AULL, 
            0x87EB3F157FEEA8E0ULL, 0x5996EEDF1D4E1813ULL, 0xCB73B922ED54035AULL, 0x81437305FDD6403EULL, 
            0x939FD5E275C0C275ULL, 0x89C2B84F943691D9ULL, 0x4430092DE1995407ULL, 0xDBFBED853878105BULL, 
            0x27934FE2EA229946ULL, 0x231EF1D6E7D81A37ULL, 0x13A6698B53FEC7AFULL, 0xA3CD5FB9A4E0A3C4ULL, 
            0xB7E01839D77EDD30ULL, 0xD8279431180369A3ULL, 0x0531C8AA485FF43FULL, 0xB1ADBCDBFE08F94DULL, 
            0x9BA4CC0BD0161D26ULL, 0x463C1E9D9567E02BULL, 0x666D28BB1711E001ULL, 0x88906C0DB6035E80ULL, 
            0x23F47EBF4713D252ULL, 0xBC6B5CAB902D3403ULL, 0x220EF033DA319B92ULL, 0x7B04EBD2D4DF76C6ULL, 
            0xC98424EF914FD531ULL, 0x659AC0FB94893167ULL, 0x7759DDF29F1ADB1BULL, 0x00E39293BA6BCC7DULL
        }
    },
    {
        {
            0x4111077B370918CCULL, 0x3BCFF6A1825253B1ULL, 0xBC211B9890F6C473ULL, 0xB25D0DA4681C60C6ULL, 
            0x63A87F7C7595E827ULL, 0x0567C96B9896B9BEULL, 0x51E8BBB13264D395ULL, 0x4C19B65C8DD3D7D1ULL, 
            0xFDB1FAC1CFAA3993ULL, 0x4D1167D4962C7639ULL, 0x75AD8D2BB06B8BB5ULL, 0x6DE6BA7FE51301BEULL, 
            0x49FA6C28889AEEF6ULL, 0x360BE69A3B975333ULL, 0x9796767808D1028AULL, 0x15BD00E2AD66A8CFULL, 
            0xDC9FED53AC851305ULL, 0x2EFD25E7C74E7930ULL, 0x998E92E656DF27CAULL, 0xBBAC66DA1689A156ULL, 
            0x76249BA1F2243ECDULL, 0xFD7F14B7BB52BD6EULL, 0x6E195184865B95EAULL, 0x74978DC294D84833ULL, 
            0x873A81FC6C55521FULL, 0x3725EB176C6F038BULL, 0x3FDEC01007002BB9ULL, 0x2147E884DCED27F1ULL, 
            0x0C8A621B8173FD73ULL, 0x52DF7B1C2E2820C3ULL, 0x86F7B97D240E05B3ULL, 0x0916977DCA571D46ULL
        },
        {
            0xC06EA4C1BDFC1DA1ULL, 0x587295BFF83CAA79ULL, 0x8FDB0CF889BB1DE7ULL, 0x30AACDF24C2BB229ULL, 
            0xA68A156B1474D525ULL, 0xF713228B9F365560ULL, 0xE7E1322B3203DB77ULL, 0xA97CD45A35214245ULL, 
            0x5D44F1DE463009DFULL, 0x0E92740997E2C0F4ULL, 0x1858036A366F8677ULL, 0xCCD4938C33E874E9ULL, 
            0x12CD0952F80A227AULL, 0x2D104442C7E52B03ULL, 0x81C8E287F85ED118ULL, 0xD2B3C28A7323AC80ULL, 
            0xCBE28CA42C688F44ULL, 0x816B0816393AF0AFULL, 0x228B5004395310B8ULL, 0xC056E38826AF3105ULL, 
            0xA88177E46F569422ULL, 0x1CAE4A71C59A409AULL, 0xD8FB6FC0C852F228ULL, 0xDDC6E4488C9A0FFEULL, 
            0xF39E7562FB293341ULL, 0x812262510BE191A9ULL, 0xE2255D4E91F2C0C2ULL, 0xA8A79F5327C5D368ULL, 
            0x2E711348E0FAF990ULL, 0x25B9E35AC685D16CULL, 0x22050A7F8A5A878CULL, 0x250873E441A49254ULL
        },
        {
            0x30E61DDABA3D909BULL, 0x4F682D05C7BD9E7FULL, 0x3E55040826DC6127ULL, 0xBDF7BB76784D64CAULL, 
            0x81554C720232AD6CULL, 0x251C4E331F7C9DAEULL, 0x0CD59A22B8E5BA19ULL, 0x1D640B793857EF23ULL, 
            0x52858D470FA1DC15ULL, 0x97D4A918060F8324ULL, 0x855E439097B61ACAULL, 0xC176146B92E7CA5FULL, 
            0x24C6C7858F482B0AULL, 0x13EB04DB9ACA0DFBULL, 0x2242DF3D4A6A5E99ULL, 0xAB90E05A816D28CFULL, 
            0xF0E34864A4703EEEULL, 0xD2C3C5D16B118C92ULL, 0x1D13144446AF1330ULL, 0xF1E0911A24DB1CA4ULL, 
            0xEEEFD51E3ACA0491ULL, 0xAB6F9881DC7B553EULL, 0x962EF33979ED3C98ULL, 0x1AB709420C36B05AULL, 
            0xE7F63C4D9F225710ULL, 0x2B09A3EBB10AC8CEULL, 0x48BC9B8E6A3582C9ULL, 0x0279A2DF3671BA3CULL, 
            0x51C2758B9F354D66ULL, 0xAAF0359C1FA2A356ULL, 0xD6A285D29353E256ULL, 0xFCE57EFA354D22D4ULL
        },
        {
            0x02BB7FE852D1398CULL, 0x6EE335534DFB6345ULL, 0x31F654257461A808ULL, 0x93C59CAD682B36E9ULL, 
            0xE8DA36746DA67549ULL, 0x3A184D045FDE1D5CULL, 0xF9B913F2A5DFEE7BULL, 0xD1561DC8910CD385ULL, 
            0xCC1B6AF4EB023FAFULL, 0x5BB267098D0F8A79ULL, 0x96F454E55F9FD614ULL, 0xD46311C0E04983B1ULL, 
            0x98D020C1E8CE0550ULL, 0x442E3734642CDF9DULL, 0x9BB2AC5387EA553DULL, 0x80748D5C95404A7EULL, 
            0x7D383AF2FC1F5F93ULL, 0xEAABBA5ABEE0FEA7ULL, 0xC4CEF81E903D952CULL, 0xD8967B06C7B8CEF4ULL, 
            0x8C198A20F5B65A0EULL, 0xA10DF760009762B4ULL, 0xD888A14D637AB9CEULL, 0x0863751C83725B14ULL, 
            0x4F6DB08DE8652B82ULL, 0x9FA9CB15A1102E88ULL, 0x2AA7FF1A66019B7AULL, 0x8A4E85FA3660B5CAULL, 
            0x7071B1EB0A436478ULL, 0x412253721CBD4B59ULL, 0xC957E5AF3CB0BA16ULL, 0xCB8761CE5A87F8C0ULL
        },
        {
            0x2B0A1A8A4AFD7313ULL, 0x159BD65486693D96ULL, 0x3DCF3B2619AA4386ULL, 0x2F28F894D93408B3ULL, 
            0xCFDA9C4963358790ULL, 0x4C69432BEA5A015DULL, 0xD00FC8E4DD03ABEEULL, 0xABB8A49693EE1082ULL, 
            0x381A939FA057D50EULL, 0x0C58B6E0D5DD40DAULL, 0x98DCA0AADF851FBDULL, 0x57B607F5304C5A6BULL, 
            0xF7923BC63C3BCE7EULL, 0xA551377BE886F76DULL, 0xCEB568FD4A88F16CULL, 0x62408B33741AEED5ULL, 
            0x6387D41B38B45174ULL, 0x4B4AD5093B0CF845ULL, 0x0473FAE1A2AF35C7ULL, 0xED054727E2EF5A2EULL, 
            0x35FDCAC8349C0D6CULL, 0x1395417DA93E6853ULL, 0x9F5D56C78327AE25ULL, 0xEEB37D50164590E5ULL, 
            0xABAD035D01B1FA03ULL, 0x67ECD0EB797E4863ULL, 0x272DC3306B291671ULL, 0x5435587A5AF85205ULL, 
            0x64141FD8B3A359CDULL, 0x674CEE87E2B906DBULL, 0x6001D8232A876C6DULL, 0x8E33E5D4623C9B9BULL
        },
        {
            0xACB7BCE4214F73FEULL, 0x1F9C40E33BF7D569ULL, 0x73794C133CAB0413ULL, 0xDC491E173C8E469CULL, 
            0x24AD72DCB5E49600ULL, 0x9B9C286E1025F918ULL, 0x5EA376E7C9F1D9F6ULL, 0x6223C4991E30C61FULL, 
            0x6A6BD99209D21077ULL, 0x186654530E348762ULL, 0x135BE1D4515E4897ULL, 0x8F861E56BB77C540ULL, 
            0xDB68E5449597D751ULL, 0x5B60C0B23C10D36EULL, 0x666CE91E0F07BFF7ULL, 0x96A56F7CBE1F6CA6ULL, 
            0x4C26FDB8871481B2ULL, 0xEDAFC17D8A8BEBD5ULL, 0xE73514B9549BC9DEULL, 0xC53BF9A0FAC9611DULL, 
            0x3BDC533B2AA4EAEBULL, 0xA1EC0AB6B639122AULL, 0x27D506A4DD1166A7ULL, 0x2A0FCE3743068ACEULL, 
            0x6A59BA937CE0B4DAULL, 0xF70872128DB9CD2DULL, 0xF59F3D01CCC72ABAULL, 0xECA1EFE4ED3EC629ULL, 
            0x1C1AE5A2B3F32779ULL, 0x563FB5D98C0E0D01ULL, 0x242BF17C5585F5F0ULL, 0xC562B03712E6FF1DULL
        }
    },
    {
        {
            0x3384187225D4C647ULL, 0xD4FD4AF6D221874AULL, 0x0331EE148A580601ULL, 0x956B4FBA769F3528ULL, 
            0xFBC4EB14CC5DB1E7ULL, 0xBD03554B62932A98ULL, 0x6533C2315EF619EEULL, 0x1DDD1FC2C369F745ULL, 
            0x1B1B4414E93B6838ULL, 0x23F3ECF969A7970FULL, 0x3A9B2521878E99D9ULL, 0xAA5B92201F662289ULL, 
            0x8B0F050E6FB0CF4EULL, 0x96FA769BA3024719ULL, 0x6C3E2B0233444AB4ULL, 0x39CA53BE89D0C7E7ULL, 
            0xC66D1E97590ABF46ULL, 0xA5FF50F161853B72ULL, 0xB668074F1EB584F8ULL, 0x7E0494E4D263F1DBULL, 
            0x89928F6DAD4326B7ULL, 0x743FB8F8DB406F8BULL, 0x09502F164D0ADBE0ULL, 0x3CC66BFABA69B425ULL, 
            0x1E22C420F5A7A95FULL, 0x34941D1DBE0E2063ULL, 0x8BC4E25E6DEED5D4ULL, 0xF68755CFA7B986FAULL, 
            0x357134F7AC9C7B04ULL, 0x161036CD8A2C1354ULL, 0x63E0A3CBC0DE9399ULL, 0x62BC5BA9B299558DULL
        },
        {
            0x2F8C03DB1F05D41BULL, 0x86626FBAE64B87CCULL, 0x12AE6665D40F70CCULL, 0xCAA8F8DE72594556ULL, 
            0xB5A21A45AFF7297DULL, 0x545F95CFA19B7B9EULL, 0x84891465989A2499ULL, 0x8647D0BF9885063DULL, 
            0x831E97A6128BA2DFULL, 0x3BAC395A700DA8A7ULL, 0x4C148376EFFC7BF8ULL, 0x779D3EEF0CB51728ULL, 
            0x4E0FC01D9A1D5A5CULL, 0xDAB98B17323017BEULL, 0x6817885337C9A285ULL, 0xD94CBE29D69BC42AULL, 
            0x3D37A508A70EFEB5ULL, 0x24717ECEE399CC07ULL, 0xCE3CF59F14BB141EULL, 0x96187A8A4227F56FULL, 
            0x3C9F4C269B890E13ULL, 0xB7AB5A067C35BF8EULL, 0xEE8086CD36E31EEBULL, 0x64008566F0A75593ULL, 
            0x754991B38DD3FDB2ULL, 0x274FF5EF6FCB0BEFULL, 0x1F7FE301C06BE45DULL, 0x853EA83AF867AB58ULL, 
            0xA8B463458B13C804ULL, 0x49F531ADDAE896BFULL, 0x31BF2CEAEB1EF4B1ULL, 0x58F7D74B08B4063AULL
        },
        {
            0x8312766967CBF006ULL, 0xFFC1024370F91042ULL, 0xEDD2EF4FCA0028FCULL, 0x1C27576788413A89ULL, 
            0x10477D6FE7A6063FULL, 0xB528F59E203A38B6ULL, 0x72B04642573C4AD7ULL, 0xAC0EB271432EA6BCULL, 
            0xE7D487312FF3F5A9ULL, 0x59DFA8FCBC5BAB26ULL, 0xE482EE75FAE79208ULL, 0x63C7C420017F3EB9ULL, 
            0xA587098303621FADULL, 0x1198DCF51ADE796BULL, 0x2BBC04570F315CBDULL, 0x8145DBDE04C8F33CULL, 
            0xDA1AF271C087EC10ULL, 0x49F2B8DD7D50CEFBULL, 0x21773A80044B654CULL, 0x3B770B73D4C454BBULL, 
            0xEECF5491E5F9235EULL, 0x9047F6AAF5942654ULL, 0x183C099186A6D059ULL, 0x16350BAEF1EA9AEDULL, 
            0x6C3ED289C2072BF7ULL, 0x5017F208ECFC8C23ULL, 0x24E8DFF0C5891224ULL, 0x80B286F810951457ULL, 
            0x0DE848E80E983D0EULL, 0xE1C25EAE84780204ULL, 0xF6D655D32908B9B4ULL, 0x65B3B27F9714A36BULL
        },
        {
            0x2078BEF49CDDC3BAULL, 0x19A41652330E651FULL, 0xF2F2551CEFF99FDCULL, 0x7FE567CEAEAAF3F5ULL, 
            0x9EA5AA35BF847D5CULL, 0xE935BB1F101B1857ULL, 0x79A2134966260E6BULL, 0x821A9B54B087CA88ULL, 
            0xE86B1CAADCFC6CDFULL, 0xE917EB8B9183A8EFULL, 0xFA0B8AD044DEA105ULL, 0x53ECE4438819525CULL, 
            0x34BC8E96983DEA08ULL, 0x07380F72E8FE18F4ULL, 0xA1529FC3063A0A0AULL, 0xD07BB1526CA598B4ULL, 
            0xABA0E1979FE79C86ULL, 0x035924E9DB18553AULL, 0xB53BBDAB0AC10AE9ULL, 0xACD9150A6EEF2075ULL, 
            0xA1832BBE07BDC138ULL, 0x5747C40E1AF42912ULL, 0x7DD81ED99082EBD6ULL, 0xC9A9D3C0F8936B6AULL, 
            0xE7B36A61D73887A3ULL, 0xDB790D27A426AE17ULL, 0xD4C4D3C6EABEDD2BULL, 0x67FE9D3D8AD839B0ULL, 
            0x9B8E1486B115B826ULL, 0xADD0965894D25B06ULL, 0x627EDCF6CF7D3B1CULL, 0x06FCAFCBDE516B31ULL
        },
        {
            0x3AB093EA475A77E5ULL, 0x9A0BCB22D156B316ULL, 0x4670C2DDD2587749ULL, 0x7582D2C19CFA90ADULL, 
            0x0A9447C0103E528AULL, 0x3E30C63CF97271BFULL, 0x6997FC648A96E43DULL, 0xF734926C8D95CF01ULL, 
            0xB8EE0CEA88C3165AULL, 0xF540FE6B594330E3ULL, 0x766BCED41F71C571ULL, 0x4CF3BDC0F4AEAD06ULL, 
            0xFE7C79118E1983F5ULL, 0x204457E9E6603898ULL, 0x1922859F3FA93C43ULL, 0x783662092ECC90A1ULL, 
            0xAC2E0272F694BB03ULL, 0xA8964B4DA72B92ECULL, 0x0ECCF24E5D61AB08ULL, 0x5FABBAC11CB866DBULL, 
            0xF9EA34622732B7BCULL, 0x03708F8FA4EABE7FULL, 0xE8A8D0ECBBA4A206ULL, 0x65B91889748AF289ULL, 
            0xCF2E8D3FE98203F0ULL, 0x709D86AF0C8D6DBEULL, 0x84DC0A05877194FEULL, 0xEC888E40C73B2D87ULL, 
            0x0126C04FC5D9D768ULL, 0x0D4407CBB613608DULL, 0x3A6AC25669CF88A8ULL, 0xD1AA11378DDDA371ULL
        },
        {
            0xF5ABA2868943DF19ULL, 0x474E993A39262387ULL, 0x2E6454F480EC1794ULL, 0x3ACB44CC21A9D865ULL, 
            0x969D56CEBA1E9BE4ULL, 0x53603CAE627CCE5DULL, 0x9668DC1FDB484DAFULL, 0x6CCBA0836EC68F80ULL, 
            0xA712BFCAD8242311ULL, 0x3325225F244685C2ULL, 0x09F1A9DE4C5B374BULL, 0xEF5BBEF7D3E4A919ULL, 
            0x1090EF1F8783A4CDULL, 0x8AAE7B0B362754B7ULL, 0x886C83FA4557EA39ULL, 0x299369C9BF6B734EULL, 
            0x41C7DB10932DF8E1ULL, 0x2F91DBEF97AEE759ULL, 0x2150DF36D04AE266ULL, 0x81F32187448783A5ULL, 
            0xC0E716E1DE351E56ULL, 0x6313E7E367D0F35CULL, 0xCEB3B703962D0084ULL, 0xB3EF4613745CBC62ULL, 
            0xC36DC079C06BE2E4ULL, 0x290B093FB9B4A17FULL, 0xABDC3953F9EB5D3AULL, 0x38E6C5D465DAE78BULL, 
            0x95B6D70DEFCE6D86ULL, 0xC9EE5A46201CA288ULL, 0x3D02741FDA1E21DBULL, 0x4F9CD48F6A8D5CB7ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Aldebaran::kPhaseAConstants = {
    0x8C19726E685F67D1ULL,
    0xAC478C6178AC06B1ULL,
    0xBC4B6B1119770F75ULL,
    0x8C19726E685F67D1ULL,
    0xAC478C6178AC06B1ULL,
    0xBC4B6B1119770F75ULL,
    0xC48353E58060FC5FULL,
    0x454B95342A68B927ULL,
    0x7B,
    0x7E,
    0xFB,
    0x20,
    0x59,
    0xCE,
    0xEC,
    0xE0
};

const TwistDomainSaltSet TwistExpander_Aldebaran::kPhaseBSalts = {
    {
        {
            0x9C16990D1797575DULL, 0xC7DFDA7B916D648AULL, 0xADDFE5BFE45C5477ULL, 0x1503551CA9A57869ULL, 
            0xB3969A46F982F898ULL, 0x232DCB53EEE865C1ULL, 0xFCE44DB4B238BE1FULL, 0x06B4F14DB8CFBC6BULL, 
            0x043AAD57E78B8E73ULL, 0x5BFF25F4209234C2ULL, 0xE98ADB6FDD5F102EULL, 0x19D33F6746128F09ULL, 
            0x849AD50AE0A06868ULL, 0x75F0699172E97A6DULL, 0x6A8A9D9A94EC4540ULL, 0x2A8299003D460C99ULL, 
            0x8F03AB7C4AF79891ULL, 0x3B2D494682E903E0ULL, 0x10F90D6A779729BFULL, 0x8B09E94DB16DF6A3ULL, 
            0x133C2E3C270B2421ULL, 0x1BB98A2A716A2C5AULL, 0x7C1D1869AAF799CCULL, 0x7B2EAB77B9A22536ULL, 
            0xB1DCE6414C91468BULL, 0x9DFE4C9FE8756D34ULL, 0xF7AFE2F13649C2CEULL, 0x582AC6807C8A59E1ULL, 
            0x41E68F32738FACA0ULL, 0x962AF52DDCAAB649ULL, 0xBDC194DB5F66DAFFULL, 0xB3AEDF03BF6464F5ULL
        },
        {
            0xE6D39B5AEA300995ULL, 0x8C18132A793D2DB7ULL, 0x57C345A81F5CEB1FULL, 0x7C2EBFCA29621AB5ULL, 
            0x364DD90EB571D8F7ULL, 0x1B0E1CB7215E6324ULL, 0x65ECC9C3BF271DC9ULL, 0x25E1A0FA03D0E6EEULL, 
            0x12EF5C374DC3E751ULL, 0x926FA9DC48578629ULL, 0x57859474DF5FE52DULL, 0x65D21AE659CF4B33ULL, 
            0x36D3CDE1E72A36FFULL, 0xC024C67D50D2F056ULL, 0x18E9BD9AC3E99706ULL, 0x8636F62A6E43E933ULL, 
            0x4349FB71C406AF34ULL, 0x1279F2DFBC4B0596ULL, 0x29AA8E9DA000B206ULL, 0xE48453A0BA9369F2ULL, 
            0x885BA8E65529A7C0ULL, 0x7E4D6F209AA6EBA3ULL, 0xA1B3442B5E347743ULL, 0x823B77EC463B56ECULL, 
            0x1CCB124CC3CAF8F2ULL, 0x44D3B2F400DD62EFULL, 0x4A4291E9A74A9B0DULL, 0x3966DDD0107557B0ULL, 
            0x9636D9D0E94E6D56ULL, 0x9FD72069AFEDDE75ULL, 0x1A0635D5F3D4B13EULL, 0x54C7D875B2B30D8DULL
        },
        {
            0x80548BAC968A7834ULL, 0x8A0BEADD27EEF67BULL, 0x108BD9A5114BBCDDULL, 0xFC37A21100969149ULL, 
            0xEA0F0CB518E82377ULL, 0x3C366D3706898586ULL, 0xC9495C5F95CA7A51ULL, 0x5FF469EF747146CDULL, 
            0x85324A3459C85953ULL, 0xD3F99740A878BDFAULL, 0x1556879954A73D6CULL, 0x202A5E20963CE569ULL, 
            0xA38C13926DAD69FCULL, 0x2444D79DD8267121ULL, 0x3C3C9204764AE084ULL, 0x65BD37C1087BCFBEULL, 
            0x8049C6A75892150AULL, 0x9ED0FE78DCAADC44ULL, 0xC04C915B2593DE37ULL, 0x3ABD68F66AF57F57ULL, 
            0x221B6BCFCEF5697FULL, 0xEC616969D4D9C9BBULL, 0x7FE9991D6E448DD5ULL, 0x270BFE8FF789D43BULL, 
            0xB13E2D74EAC6D48AULL, 0x3E3C835C2FA62565ULL, 0x5F8F6847BC885332ULL, 0xFE1171CEF78F064EULL, 
            0x23E824A7ACCCC68EULL, 0xCC39EED2883EF96FULL, 0xAE80CE4536653698ULL, 0x202D3B62F72B087BULL
        },
        {
            0xD634AA54B7CEB400ULL, 0x6953D1BE78C6C599ULL, 0xFC02FE0E6422D2D7ULL, 0xC2824F8850CD547BULL, 
            0x855779CA92A279C2ULL, 0xB9B84CCA37EBEA7DULL, 0x93D8E4A3FA1B5497ULL, 0xE69BAAB48117C1F5ULL, 
            0xFDC38B862750D22AULL, 0xDE226029E26E33A1ULL, 0xAD5F3F2CDCDB4280ULL, 0x557F3D0660C9122DULL, 
            0x672CC010DEB04E79ULL, 0x5BE338988E708631ULL, 0x4F293C97252E1527ULL, 0x84EA503E1E7A14B4ULL, 
            0x408CE8A3B154FEA3ULL, 0x172A834B42D1BAAAULL, 0x00BACB44CD24009CULL, 0xA82C6DA16CF4A1CEULL, 
            0xDDD227375B922216ULL, 0x761F505E25BA0073ULL, 0x9B80E7157E5FA66AULL, 0x374255BC24EBDD8BULL, 
            0x2FAFE7D70B9A2AD4ULL, 0xB931E4989A8321E8ULL, 0x6057206DD1654D01ULL, 0x9DC0020380165941ULL, 
            0x054196D637851BC9ULL, 0x94CFCC8D4E2C1E7FULL, 0xF0D1D5252E7A95C3ULL, 0x99416067EA34E39CULL
        },
        {
            0x89AF90F57059ADC3ULL, 0x7C232B68AEBBB1ABULL, 0x84E64D533247E08CULL, 0xA649B02504B13993ULL, 
            0xB34C2AD915BF5407ULL, 0xCF95B983610B1A51ULL, 0xAE5273A1C30B1874ULL, 0xC44731B65C0D10B7ULL, 
            0x380D2045A59D813EULL, 0x3055C1E47D3B09EFULL, 0x3CA13C908CFDB116ULL, 0x90F3E3F81FC6D982ULL, 
            0x65AC7F951D4E0D7EULL, 0x3E5663D0A84D8883ULL, 0xC992485B1630CE85ULL, 0xE5B661F3F18B39B7ULL, 
            0x98F99A966358A854ULL, 0x24092FDEB0394F29ULL, 0x006F42EDCD52C065ULL, 0x73B18B8458B401C4ULL, 
            0xDFA1ED4056D4B9EBULL, 0x6B61F3B225935793ULL, 0x82CE026FE7BE6849ULL, 0x32932F83C14F8D0EULL, 
            0x5443E9BA0AFAC3DFULL, 0xB9CDD37B90FB39D1ULL, 0x15B4F0F36D8D8326ULL, 0x614B4FBCAFBCCF85ULL, 
            0xB979AA040FC400BEULL, 0x31E29103743A1F1CULL, 0x0F87E18389B9B37DULL, 0x98DD209715BC5DBCULL
        },
        {
            0x8FA58802821D999EULL, 0x9348182B1B847242ULL, 0x9208C2A3348D7FE4ULL, 0x8AB8392C936C23CEULL, 
            0x510B6AAE7E481DD2ULL, 0x274704E4B660DAE1ULL, 0x5E2BB411047ECDA5ULL, 0xF8D46935070134E8ULL, 
            0xF0473C2456F683E8ULL, 0x631F516514216DF8ULL, 0x347D5479623067D2ULL, 0x452BD014A49AD695ULL, 
            0x47AC326FB4B3C0D3ULL, 0xD040D17E6760151CULL, 0x9A559CA0C5F30EB7ULL, 0xAFA160C7F84EFB70ULL, 
            0x5E5E67FDD2449B2BULL, 0xB1A248625EE90C22ULL, 0xD50C863AA42C8A09ULL, 0xD141E224424D517EULL, 
            0x8A8647961DBDB104ULL, 0xC3E2ED08DF0723FEULL, 0x2E40C25E243476C6ULL, 0xAEF218136AC9540BULL, 
            0xACDAE7B822024B82ULL, 0x66E6A54D67C6C816ULL, 0x8C8B9EB6BA6197A9ULL, 0x46EB91ADF2708D8DULL, 
            0xE58903E06D27883EULL, 0x8545EFA3B9350D62ULL, 0x2AD9DC428117E636ULL, 0xB2E3DAF518C849AFULL
        }
    },
    {
        {
            0x8CDD1765DEF32B63ULL, 0x4DF55C7B8370380AULL, 0x94BD98297682E92BULL, 0x9D8B8A80E7E2B8A9ULL, 
            0x12BA65DD4F201D1EULL, 0x4468832321D3040BULL, 0xA97B24834C97A82CULL, 0xB89E8FD03EEAEC1DULL, 
            0xBAAC44B47550084CULL, 0xA63790F426A23ADCULL, 0x1A0981095CC21962ULL, 0x7CD9FFD5B7AB6993ULL, 
            0x97310BE0AA918BD9ULL, 0xF98C838CC32D19E2ULL, 0x5B4119351B4E9358ULL, 0x31CDF75228CD9B67ULL, 
            0x31B29460F1A1EAC7ULL, 0x1CF2AC7D3C3219C6ULL, 0x53CC2B079DDB9126ULL, 0x4732DEE0DB2B913BULL, 
            0x6BCB38ABEF444A10ULL, 0x0E208CA621977AFEULL, 0xAEB77C295D22E537ULL, 0x53E044D413D1672DULL, 
            0xBCCB56688B83E413ULL, 0x51642BDFC05DD517ULL, 0x381E443414C0B012ULL, 0xA67A63991D3AF6DEULL, 
            0x5CB435C4EABDBCC1ULL, 0x1A5AE180EBB6CE3BULL, 0xF690176E38506AF0ULL, 0x478AE106EECFAB05ULL
        },
        {
            0x1B0AC338DB65BA5AULL, 0x6F0F26057607F085ULL, 0x167C87099652990CULL, 0xA37CDB9F8ADD19ACULL, 
            0xF8F38A4304E41F71ULL, 0x35FC9D252880DDD2ULL, 0x7350B14283CB8069ULL, 0x94727A8DE7046A23ULL, 
            0x384529831D8E5E07ULL, 0x8E40CCCD5E18ED16ULL, 0x3C949E8D8CEEF657ULL, 0x3CA88398C8D0651DULL, 
            0x861A98DF7C4B82EAULL, 0x2965587112B80F75ULL, 0x6A113A0A907FC161ULL, 0x82E813DF3A8C7EBDULL, 
            0xD951BD15E190FEBDULL, 0x41766D391A7C62F2ULL, 0xA77DCC4EEEF23A07ULL, 0x7800DF43A2ECFAEBULL, 
            0x3BEA7A18596067F2ULL, 0x234E3EB6C4B7660AULL, 0xB3C2F1046E26964FULL, 0x42304A8B80691261ULL, 
            0xE16528438BEE396CULL, 0xDDCF24211CC9A24CULL, 0x1F37CEC9B2F93890ULL, 0xCB7C2CB7EA2D0271ULL, 
            0x4E6B4C3413075402ULL, 0x1C7C3BE1C15C7A17ULL, 0x574682A86E3BBE14ULL, 0x714BE2308F23E691ULL
        },
        {
            0x5D16E846BDBACCAAULL, 0x5D53D00B15E47DCFULL, 0x04E008E23D0342F4ULL, 0x4D96C33366C43E69ULL, 
            0x1FA92398C4546165ULL, 0xB0B49EE9FF668EB6ULL, 0x4A66BAC10AA6DA04ULL, 0xF6BD788D11F9DE8AULL, 
            0x0322F6FCE35ADF5EULL, 0xC14730A0872A2D85ULL, 0xD7E24C24EC1CCA85ULL, 0x916A241B393F745AULL, 
            0xBA8E2050A341AA18ULL, 0x515C0E772FC2A083ULL, 0xD2739BABF75AE16CULL, 0xA03DE09D8528A417ULL, 
            0x4A7B0DDF92A93FCCULL, 0xFDF4D749E4610960ULL, 0xD3D84983D3DE9351ULL, 0x779FF645C5DDE995ULL, 
            0x3984F41BC1ED98C7ULL, 0x708CB21DB72E89E2ULL, 0x62E4580EA890812DULL, 0xD8A4EEED993A1FB5ULL, 
            0x4D2CB9209BC9FD7FULL, 0xD0F51B22C4F92952ULL, 0x12454E5BF967AD77ULL, 0xCF478A49F4F60D95ULL, 
            0xCA1F2222B59FED09ULL, 0x7B53D1C0D26BDCE8ULL, 0xC955539EB6052916ULL, 0x29F5BBA71FC5A7BBULL
        },
        {
            0x04346C664367400AULL, 0x1669DED6318FB00FULL, 0x72EA1FA7D2167355ULL, 0xC31C383686623BE7ULL, 
            0x043D48E7973C871AULL, 0x344957252C858B4EULL, 0xC3EFC3138A16F15EULL, 0x8B697A7619EFB64CULL, 
            0x3DC135596268150EULL, 0x366BD617480E2D0DULL, 0x59DE97DBF4F80BA2ULL, 0x6943A5B7E71944F6ULL, 
            0xFA604360F931B6CDULL, 0xC6B25A6FDC9B6839ULL, 0xBCD7E2A5EBABFD2DULL, 0xFB69EB8E56450E0BULL, 
            0x0F5EAFC5DD91A4E3ULL, 0xA3EA3FAA4996F49BULL, 0x6E5020AEDFDFEA80ULL, 0xB5338B8251740035ULL, 
            0xE61B79312EDFAD3EULL, 0xAC2395FA46395946ULL, 0x03F9E29A7B076C84ULL, 0x8416DDDBC0BA6013ULL, 
            0x8B2124ED04381F92ULL, 0x6F4400D984444FBAULL, 0xD6CB0C0FAEF4D446ULL, 0x7AB7DFAB00A921C7ULL, 
            0x5E37F5B2AA216398ULL, 0x2AEFFC12009199FFULL, 0x51E72E7243AA23B1ULL, 0x85B0AF0065CC3A1EULL
        },
        {
            0xAC34B379C5524D45ULL, 0xC3820D0FDD8FD89EULL, 0x5D7AD3A112F82C0BULL, 0x69F0BBB285D99D57ULL, 
            0x334E0C74CBF903FFULL, 0x09F685A85EE1BBC5ULL, 0xE152ECE4C24A40A9ULL, 0xF51D43BF1D5EDB45ULL, 
            0xABFE66C013D6135DULL, 0x2A6C0ADDC0BC3E7AULL, 0x7700901ED25EC58DULL, 0x79EA80E8BA7A4683ULL, 
            0x4E010DF16B02A878ULL, 0x8B2D611C71E2B9C3ULL, 0x7B5AB091833B8010ULL, 0xEE58039DA31B5419ULL, 
            0xAC07D53947E05D78ULL, 0x72784DB9894D9BEBULL, 0x0CF769E037861EBBULL, 0x335109E9D5126BD1ULL, 
            0x81DFA8DC2CD1DEA2ULL, 0x6ADE7CE0C7CF2C58ULL, 0xC9AD7EF5F97832EEULL, 0xB99B2539BDFD577AULL, 
            0xF2462AA796167F00ULL, 0x430B6CFEB9BB8D86ULL, 0x3DAFD2FAD2D3915DULL, 0xFC0B1AE173C3D3C6ULL, 
            0xE35D23015CA4F4F7ULL, 0x997CD28B91305471ULL, 0x25FF4492A83696B6ULL, 0xE46B3F6947C03916ULL
        },
        {
            0x1CDCAAB643FABB88ULL, 0x4B9395C8FD35AE90ULL, 0x5AC61861AB749ABAULL, 0x784A414FEB4ACB18ULL, 
            0x04C77B59A1E91C73ULL, 0xC83CD3B06FD7400CULL, 0xF871513572F235A6ULL, 0xE447E63E1C3FF2E0ULL, 
            0x54B49669CC5F1A69ULL, 0x1DEB3BC6D6AF492DULL, 0x49AD22EC1761C8C6ULL, 0xE801AEF56D260CA7ULL, 
            0xF5B804A7E14F28EBULL, 0xFFE660516C468659ULL, 0xFA92D208FD5C64C2ULL, 0x14CE5C51BF13E87EULL, 
            0x29F985EB9355A841ULL, 0xC47776598089D3EFULL, 0x99B965D333D50CEEULL, 0x261F7CC468D81811ULL, 
            0x2438AC5113FF5F8FULL, 0x3134BD7659FB2E39ULL, 0xCC858C5A6D4D39C5ULL, 0xAF79E05923095353ULL, 
            0x0BFB1F5347C5F55DULL, 0xFD1CFFB6FCF8A66FULL, 0x63A58B10C02E390FULL, 0x68BA1915826731FDULL, 
            0xDCDF712EDB659D16ULL, 0x548825D15BCD4027ULL, 0x775703F29DD274FCULL, 0x4AFB3885E56562DCULL
        }
    },
    {
        {
            0xE58D21AA7B8F9085ULL, 0x10F0EE19FC298E71ULL, 0x4B62E1DE14AEB168ULL, 0x974ED613086405FCULL, 
            0xDF947329BDB9AC88ULL, 0x737FCEB9CBA46FB5ULL, 0x80E738A1D933FAB2ULL, 0x9D0DABAC859BE17DULL, 
            0x7DE6B34C1EE70752ULL, 0xCA46B2F86AE5BEA2ULL, 0x959B49BEBDE2440EULL, 0x37FCD1426FD81626ULL, 
            0x11D3BF724206D58BULL, 0xBEE522B20331FCC4ULL, 0x4CC3064201FABA9BULL, 0xCF6416962D474366ULL, 
            0x4EBF9B497F01BDD6ULL, 0x26E8AFE3669A992DULL, 0xAC5096E94280488AULL, 0x11C200B998C6AD6BULL, 
            0x26B92250ACD61257ULL, 0x6C0EA75B0624D310ULL, 0x3D5D47FA9FB289A4ULL, 0x8B3540DB8C466138ULL, 
            0x5ADD64C92386CF3DULL, 0x18B1FF52A8624D50ULL, 0xF16D6CBCF85633FAULL, 0x54E2D438CEBB4170ULL, 
            0x8D89ABC4187260D3ULL, 0xA8770A093B7225CEULL, 0xD4A1E59592BBF7A3ULL, 0x4928C3536401A0B4ULL
        },
        {
            0xC297AAFF35A0F16BULL, 0xDF2BA584F1509A63ULL, 0xB732B9E16F2381D2ULL, 0xE3662C3F47CAE104ULL, 
            0xF41A1EC2537C11F3ULL, 0x49F4A7DEC0509EBEULL, 0xF824F9341F2A26E3ULL, 0xDBEB9C0A0E208309ULL, 
            0x3D91E25E05DB4EA9ULL, 0x52B5611FF315ACE6ULL, 0xBCA3CF59F1AE6506ULL, 0xB639B8B862DD8994ULL, 
            0x002099FEAE9977FFULL, 0x2EB18335680BF29CULL, 0x80AD9B50691B68D1ULL, 0x95AE0FAD68AF525EULL, 
            0x89F4A1D8265D5FFCULL, 0xDA38F9A73D290C7DULL, 0x1E77F29C33474FE4ULL, 0xAF68236FAF2217D6ULL, 
            0x55D9AEFB03E3B03EULL, 0x93BC7BBF0F898D3FULL, 0x5EE369DB286071FAULL, 0x14FB19072F48371CULL, 
            0x091968207C3FC747ULL, 0x76236F5E82A611D4ULL, 0x189E1792E4FB5FA4ULL, 0x8CD79133270AB89CULL, 
            0x254C540D19E62F39ULL, 0x8CF6D29B9FFE3DA6ULL, 0x15F660A6B78890D9ULL, 0xCA68F2995DF4B1E3ULL
        },
        {
            0x6F29CD0CA8503265ULL, 0x608274B5B5FFF6F7ULL, 0xD08ADD8582361261ULL, 0x6062AC48FC2AB7ACULL, 
            0x8B716E7358F264FCULL, 0x96B27283E0BE0075ULL, 0xD06C7A4087FCF52BULL, 0x775F8A88CAB07424ULL, 
            0x7149D219236463F8ULL, 0xE4F2D125C0077480ULL, 0x7CE62F9EC61ACE5BULL, 0x34C1805B60DB224FULL, 
            0x766DF8C63DAF3B2DULL, 0xC78056AF3AC2CDB8ULL, 0xFF049B206B2305A0ULL, 0x0D5F271E9698E793ULL, 
            0x00F2AB9276174ED0ULL, 0xF219917794BDEE1DULL, 0x923C0DA836A25705ULL, 0xF2FB60E904541AD9ULL, 
            0x5E80B9F00B7661A2ULL, 0x33AAF8925A055512ULL, 0x86229D92DE9DB816ULL, 0xE694828D3FAEC9E3ULL, 
            0x4CB8048B79D57FFAULL, 0xD361EF0296212C2FULL, 0xD026886D6925EB3EULL, 0x1EC41D8BC6030469ULL, 
            0x40CB43984760773AULL, 0x3BF6C1B0C73D2D58ULL, 0x710BF6BC1A9C5FA1ULL, 0x352DE3F71FE24596ULL
        },
        {
            0x5FD5D8B3674D3060ULL, 0x2C631C1D532C4C4FULL, 0xF0F9BA77C116486CULL, 0x5D759441D7B5353FULL, 
            0xC4B850ECFA69A06AULL, 0x9BDD33C508F7F939ULL, 0x28E8CAD815AE8128ULL, 0x4E26BE7845E83A58ULL, 
            0x6E87BCFD5ECECA0EULL, 0x273C1533D43C230BULL, 0x133F6D6E3A180D53ULL, 0x2307A6C832CFAD8DULL, 
            0x8309EABB627632C2ULL, 0xAE46D7A810323C7DULL, 0xF9883F3139729B42ULL, 0x7FDFC60042D63DE9ULL, 
            0xF056B1451E099464ULL, 0x32AE9F9F443812B6ULL, 0x8ADB1D53C1D07941ULL, 0x43ECF14DADB85EABULL, 
            0x297683CBC1861A9BULL, 0x4EC264FC0E9B2095ULL, 0x5389202B9B535526ULL, 0x5C3A59B06657E298ULL, 
            0x3D2D06C9641CF77EULL, 0x254B58E9AC81BFC1ULL, 0x09E71526CCEA2DE7ULL, 0x22ECA42043E57968ULL, 
            0x82DE727409BE6703ULL, 0x1F77A25BDF5FEFE9ULL, 0xF41A18F452C1CD40ULL, 0xAF71C301F04CB622ULL
        },
        {
            0x00276B993C9B1841ULL, 0xB8A60B715FAEADDEULL, 0x6A91ACB711740939ULL, 0x1D62A9CA36406C12ULL, 
            0x82D424B4B4A8A469ULL, 0xCA54BBF8F8FF6A1CULL, 0x7DE917C34BC7D6B9ULL, 0x64E629AFDD8BADA7ULL, 
            0x73AF3B63E067C66BULL, 0x36455231589DCD70ULL, 0x29DBFEDDC1DB930AULL, 0xFBBA3B06B00CC270ULL, 
            0x345013310591203EULL, 0x9C89BC7D0CCEE0BAULL, 0x1478364794EB81B0ULL, 0x6EB5458C2BFF766AULL, 
            0x5672D10B08D177F3ULL, 0x44EE46BA99AB04E5ULL, 0x0BFF84DC3599A29CULL, 0xDBAF42EBED3D4449ULL, 
            0xDC0BF8946A65F3D0ULL, 0x7F55CC9FCF79B072ULL, 0xC83F66CD8B261407ULL, 0x7016A603D87A98ADULL, 
            0xCB4DC43A1BF2C543ULL, 0x20098E2D56F223A2ULL, 0xF7EF4B4389F3C955ULL, 0x0DA8D5F1DB249333ULL, 
            0x531463FA59674DF7ULL, 0x394A73B6C81DFE6FULL, 0x5A235EED6720A2FCULL, 0x3AA3D36FCDB4902DULL
        },
        {
            0x47DE8D1E988A2B6AULL, 0x18FB65E25D739475ULL, 0x3B56746DE0B82BFDULL, 0xBA76FD42FFD21406ULL, 
            0xE9418EA902B451B1ULL, 0xEE2245F76069D82BULL, 0xB99D3E2F1AE0C2CDULL, 0xB9371A4322FB8451ULL, 
            0x946F883CBFF5E576ULL, 0xF76CFA0A75885919ULL, 0xDB1BF48257C0EBFBULL, 0x528B8634B2769320ULL, 
            0x246175E11A44091CULL, 0x136E37A4CA4B2369ULL, 0xBDA64A0AE434AF8CULL, 0xC10A892ACCF92DA2ULL, 
            0xB03060B74466F620ULL, 0x3700CA7E891B83FAULL, 0xE526C5F9D8815B3DULL, 0x7CD5F07326954D17ULL, 
            0x56F2562183B535FDULL, 0x9A2DCC1A1C16ED77ULL, 0x09B4787A2B9CC77EULL, 0x56C266C4A39E82DEULL, 
            0xB25C518BA185E96AULL, 0xC18B411BE523D78EULL, 0x21D9C649651E3E96ULL, 0x044D36A66C191251ULL, 
            0x4F773BB9C7616F6DULL, 0x1C2F925ABC716C81ULL, 0x903CC6E5F4EC8713ULL, 0x3D9E34674E462895ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Aldebaran::kPhaseBConstants = {
    0xFC62FCB7F64E08E9ULL,
    0xDD9B7486D63F9EADULL,
    0x42CC20E16211523AULL,
    0xFC62FCB7F64E08E9ULL,
    0xDD9B7486D63F9EADULL,
    0x42CC20E16211523AULL,
    0x5325A287C4A0B492ULL,
    0xC582053EA07C049BULL,
    0xDB,
    0x1A,
    0x03,
    0x9E,
    0x23,
    0xB2,
    0x84,
    0xB5
};

const TwistDomainSaltSet TwistExpander_Aldebaran::kPhaseCSalts = {
    {
        {
            0x625DFF68A0DD67C4ULL, 0xD44C78475563A1ABULL, 0xC8EEB1965E841795ULL, 0xD7F56574833DD698ULL, 
            0x1D35DA2042613A57ULL, 0x0DEBC6FD36689D4EULL, 0x161ACEEF6FDEE390ULL, 0xD8AAFF147A6BDE55ULL, 
            0x607D9E53A41781D3ULL, 0xBF5456B818FB9181ULL, 0x2FA523570B5EA976ULL, 0xAC445633A93A3EDAULL, 
            0x59B3CCCD1F0FF624ULL, 0x6921C0D3A185FCD2ULL, 0x7A899E9F4759270BULL, 0xAA4E10E4AA19FFB5ULL, 
            0x616BBD44E08DBC68ULL, 0xCCCC934F04FE2F99ULL, 0x229045D005842837ULL, 0x448AE41272250528ULL, 
            0x2C8712823324105CULL, 0xC0CEBF1F784CCBB7ULL, 0xDA26BAB1ED38B6FFULL, 0xA6F38C7B3A336BF3ULL, 
            0x8B177ED167E7F33DULL, 0xE4F8E150891D1297ULL, 0xE2972F38D0FCDF52ULL, 0xE81995E6C4C7A7E1ULL, 
            0x0F324E61329BCEC9ULL, 0xC31ABA0DAD1965D3ULL, 0xEAED13B26ADDF4E3ULL, 0x924B49B604BEB520ULL
        },
        {
            0x8C453B59DA60E6EBULL, 0x903111F9650F9155ULL, 0x4C066C14924D922CULL, 0x37D41CBDE2280936ULL, 
            0x75ABCFCC864887BAULL, 0x0A7F01CB911FE80CULL, 0x046B8C1C33B9BB06ULL, 0x71A38C3404EE9245ULL, 
            0xAE10D99174FAA79BULL, 0x8ED4CDD4BEC54AF5ULL, 0x807496356DD0F150ULL, 0x238B55530289C5E6ULL, 
            0xAD77F36B27E378A4ULL, 0x0A303A679D82DFC5ULL, 0xD08118BD67DF32F4ULL, 0xBD2E644121A41504ULL, 
            0xCED8E1FD7F177527ULL, 0x091FFDA9CEF0448CULL, 0x57CBD88A7BBD03C3ULL, 0xE8D1633178025385ULL, 
            0x5BB3900C56E71979ULL, 0xA3705F935D9CD28BULL, 0x89EE546856BDF0C5ULL, 0x7B12B66D0338D7C9ULL, 
            0x05CC7B4476FC3823ULL, 0x0DB19AAD3CAE4026ULL, 0x2799C807B4A07C7DULL, 0x2F9C3D736259B8F8ULL, 
            0x3111A617EF903141ULL, 0x6049517221C1AA69ULL, 0xF74DA6B8006243A8ULL, 0x551F2D4F2CC2C6CDULL
        },
        {
            0x1387B2E76CD48DDFULL, 0x9AC7300BCCCB6E43ULL, 0x08AD512ED009C1CEULL, 0xCB4F2892500A03E0ULL, 
            0x00979FA69543DD3EULL, 0xB6078A128D85B751ULL, 0x6F9A9EB77634D4E8ULL, 0x37227A9E58D37D99ULL, 
            0x805133EC67C4B13FULL, 0xEBD891074889E6CEULL, 0xB163FFB6842CFEB4ULL, 0x77B76A27FFDF4B2FULL, 
            0x7C67F47BD96688FAULL, 0x933CDB94AD0B7D9BULL, 0xE98B61715EF83B73ULL, 0x28D053E24F63B297ULL, 
            0xB7BEAA36339B285DULL, 0xB4835E6AC9509C44ULL, 0xA05DF88E5C782B89ULL, 0x143C68C67DFB98E7ULL, 
            0xF07603C33BEC86E3ULL, 0xA74A29D13467E520ULL, 0x7AD01C10F3EE9301ULL, 0x56C7BD6DB3B86184ULL, 
            0x66173669F3B850C2ULL, 0x4A0928C84B880A6AULL, 0xF7FD4C3E190C60D9ULL, 0x36375BCE179CD2ECULL, 
            0x8EA5D72035116B0CULL, 0xFE012AD2BD025BB2ULL, 0xB5B92AFAFF3CA367ULL, 0xE6056DB212511696ULL
        },
        {
            0xAEAA308109A1D9D5ULL, 0x690F974A90FADB8FULL, 0x7747FCCF6B460ED2ULL, 0xCA943DE1F27B2CB3ULL, 
            0x4968E61DD2E6A6A3ULL, 0x46B8645483EC2198ULL, 0xC8754E2343B8CA5FULL, 0x0EF6F348F08D559CULL, 
            0x4741214F6943A99FULL, 0x31E94C6E2E10F57EULL, 0x76DF6C965E22B853ULL, 0x2240E67938498527ULL, 
            0x66266ADA16C049F1ULL, 0x792E73986FBDA8CEULL, 0x64C2CF403EF7441FULL, 0x6945DD5B980BBC5CULL, 
            0x356C4312065F9B25ULL, 0xED4D58AF77C7421EULL, 0xCED49ACB0A3AAAECULL, 0x528359814C75FB76ULL, 
            0x9DC43D59279B8DFDULL, 0x129A3B996F7DD98EULL, 0x619420E30DF8A6EFULL, 0x6472F2766308F3B9ULL, 
            0x0B01114929F27726ULL, 0x0141AA991B10A91CULL, 0xA9F85BA40F4DF3F0ULL, 0xB905167F11505C0FULL, 
            0xB8DE95005F97E1B0ULL, 0xEA1740B052D5FA75ULL, 0x0DA4903C85174F9DULL, 0x8359E1EAE4FE08D5ULL
        },
        {
            0x0E572E6586D3B3E4ULL, 0x935875D8678AFA51ULL, 0xF9E12FFEBA90BFB1ULL, 0x276898809EEA5F31ULL, 
            0x96A35D73DE3C4504ULL, 0x597B3DDDAE305F6CULL, 0x6DD0613A0936CFD5ULL, 0x9DAE55AA2F5D0983ULL, 
            0x1AD45FFFD87D8925ULL, 0xD677417779EF361FULL, 0x9AFB887494E2BA9DULL, 0xD128FA3FE8ED984BULL, 
            0x284F6A9C3CB142C5ULL, 0x09996103C5EDB7D1ULL, 0xECE5771F05245EB8ULL, 0x5686779EACF2C145ULL, 
            0x414B95CFBBE2091FULL, 0x2CA8C383F8082C8DULL, 0x6A4E5E811D8E939EULL, 0x34BC0E7CA2139E90ULL, 
            0xC690FEF84EB43281ULL, 0x86F957A8A7942FFFULL, 0x67B07FB1C349D5B9ULL, 0x43D03F181DEA0DBDULL, 
            0x7D4570AB5F94AAE7ULL, 0x553B862BD5E36A93ULL, 0xEE7C51272B91A0E8ULL, 0xD88E54761EB8B89FULL, 
            0xE03074CAA778995DULL, 0x927EFAC6C05917F6ULL, 0x9FAC43E161B0BB53ULL, 0xCE333630127D7DB1ULL
        },
        {
            0x7F4E0496B30D03F6ULL, 0x968C0D772BD258BEULL, 0x450B0B2AEBE1B658ULL, 0x5454AD76930BEBAFULL, 
            0x90158A43EE4AA861ULL, 0xE56A541ECCA6A7CCULL, 0xDA3565B90F5364FEULL, 0xC9F92FD015B75212ULL, 
            0xD9065056B3BC60D3ULL, 0x565DF9B21CDB6521ULL, 0xB216DA79FF7E89A7ULL, 0xC19242B4DD5A0C0BULL, 
            0xC9A5AE4CF377053CULL, 0x636E37F247EBB161ULL, 0xA8FF01D520C71E17ULL, 0xA8080ABD9FABA0E7ULL, 
            0x4DC79BF2864C72EAULL, 0xA5968033A91F1EC4ULL, 0x6926FAB379C6C176ULL, 0xFB4E2531BB95FA13ULL, 
            0xEC238714CD90ACFDULL, 0x23D40D279007A6C6ULL, 0x513C649598F559E0ULL, 0x4EB09524AEF48382ULL, 
            0x5CA6811C1235AEFBULL, 0xD5B1D992C20EF67FULL, 0xEE125EB58788A048ULL, 0x77B61CBAA616D26EULL, 
            0xD28023436214B937ULL, 0x1C8E8D20AB26C971ULL, 0xD45E0B831D4E8402ULL, 0x850A404FA5F4F587ULL
        }
    },
    {
        {
            0x81D6B333E056C857ULL, 0x7FCC6ECC6542866CULL, 0x18CBC26F65EACAA5ULL, 0xD211F67FB7831A18ULL, 
            0xC3C03CC1C61D771CULL, 0xBA37139BF2458C77ULL, 0xD1E30C3383B74646ULL, 0x2AD4D0C1300C0A0EULL, 
            0x761BC4F21F214249ULL, 0x6FF3316B95D2796BULL, 0x45287123AA4CB6A9ULL, 0x41505899772E2DFEULL, 
            0xB065EDBADC3ADCFAULL, 0xD0BDE7422B64DA42ULL, 0x076AFF8EBA55E8DDULL, 0x4A57067CDE5AEA52ULL, 
            0x32D2358B9A6E7670ULL, 0xABAC45DE2F88A67EULL, 0x62F20925D8080FA6ULL, 0x76E9B3AD3FCBA687ULL, 
            0xF6A89792309565A3ULL, 0xAF4837CAB8855FB8ULL, 0x132C8AE31497552CULL, 0x205DEDF8FE539C8BULL, 
            0x6E6976D755004976ULL, 0x1AA1E37F31BB81E2ULL, 0xC763CB965ECC2E7BULL, 0x82DE0BE2A41EC73CULL, 
            0x2BF7285F5B54739BULL, 0xF0B63E5871B67756ULL, 0x1DCF4D1D830E8E88ULL, 0x8D1215F51E5A6AF2ULL
        },
        {
            0xF226047C33A91A3CULL, 0xE20ACC00A08D44CFULL, 0xDB530F68BE2F6830ULL, 0x3754CA48D075E10CULL, 
            0x89A1B3DDEDEFCD73ULL, 0x08BCF35AE5CE44E6ULL, 0x4C2F5751C8121800ULL, 0x88964F6B00267FA8ULL, 
            0x90D30BEA329D6B77ULL, 0x2D1044C9089D1489ULL, 0x2BB3A513710F0CD5ULL, 0x58B5F9A65C2F4BDFULL, 
            0x3DC63355704EC205ULL, 0x0178E8DA6178ECB9ULL, 0xB91A8EE85B9D909EULL, 0xEA5C10C6EC380E7BULL, 
            0x2C948ED89FFF5A5FULL, 0x10A6B8C1ADB4294EULL, 0xEF21FF92A15CDDAEULL, 0xD24AB766F3527552ULL, 
            0x20E83E671F8BE61EULL, 0xC36B5561286CFB1CULL, 0x772BB77F976AC749ULL, 0x2793255F0854F291ULL, 
            0x38F2378F23EE949EULL, 0xFC2E1F1A2A9EFE51ULL, 0xA30AF19ED13B21BBULL, 0x99E46D5350019EF5ULL, 
            0x4C2959EA1EBDD47AULL, 0xE7B0FC0E56A1861DULL, 0xF3B1803D3F918ECFULL, 0x23CD069DB1B0C4AEULL
        },
        {
            0xD6CF36277F1D1428ULL, 0x5CCC3AC739B27CFAULL, 0x75109F9D10D5EA00ULL, 0x05A475D78D0DF5CDULL, 
            0xC58F05E7EC8AC527ULL, 0xABB17CEE5002AD63ULL, 0x13C2896631750E04ULL, 0xA0184BAE9C1A9278ULL, 
            0xF5A746D1EBA495ACULL, 0x1A2A882205E7F178ULL, 0x2FDF888D3DB4A08EULL, 0x69AA3902A1B219EFULL, 
            0x36C1C6BC745C52F2ULL, 0x03AEB2912163D2D5ULL, 0xF158D5785EA1F87DULL, 0x83C9D6527799CF84ULL, 
            0xFA23150EBEA892A5ULL, 0xDB10C8FD341FE123ULL, 0x0A90916B9227551CULL, 0x1C9A51F142C14E5BULL, 
            0x5075DCF0CA13C91DULL, 0x5524149A4F2BD912ULL, 0xEC8115946D3B0CC2ULL, 0xAE7B4181FCA9CE7EULL, 
            0x118E9D6434614C20ULL, 0x6C79AF846C5A8216ULL, 0x774D4CB4712F7C81ULL, 0x9B99CEDD366DCEB0ULL, 
            0x2736688FD0F3884BULL, 0x93C91731F160AF5EULL, 0xDEB6433B950DC33DULL, 0x46C2F2F5969BA9A4ULL
        },
        {
            0x1DD84164676118FEULL, 0x9D763A0609B02ADFULL, 0xF4182AB909DBEA02ULL, 0xA1CAD4F8ABF95691ULL, 
            0x176DD7C4A4B87D88ULL, 0x94345136F829956DULL, 0x80F1B5125EDB52D1ULL, 0x54BD55F59162D1E6ULL, 
            0xD8E6B3DDDF8B4DF6ULL, 0x9F70AE033ADD90E2ULL, 0xC94B99DEA82EF93BULL, 0x079EC59A8B09FB5DULL, 
            0x8118018C35F6974BULL, 0xDB31EEF9B53B6AB4ULL, 0x8C2B3ACE4B955884ULL, 0xEC4F0A1E7528256EULL, 
            0x1902DDD853067567ULL, 0x85519CAE31317F25ULL, 0x208E41BDBC6F1EB4ULL, 0xCC23BAB50E9CD3B7ULL, 
            0x577F326105898EB5ULL, 0xF3CB366A6D2052EEULL, 0xE5FA96936CF7B698ULL, 0x6A65CBC1270A41C3ULL, 
            0x6F4C0B46A329F671ULL, 0x7A1704ABE6529FDCULL, 0x2BF72603F76B5043ULL, 0xB09781BD028DA858ULL, 
            0xA974D3DEEF881DA2ULL, 0xA3C4AAC4BF140B27ULL, 0xF97EC22D51C4CC6BULL, 0xE1A3A3B810398E8FULL
        },
        {
            0xA28FB789EAD5ADDDULL, 0x3037A03833F7284AULL, 0x2F740E6602B9E8B9ULL, 0xA1F4C9EE1F416698ULL, 
            0xAE93A6CC08725589ULL, 0x036A30BF70A7FECDULL, 0x4927F553C18533F5ULL, 0x99AA9AEBCF9FA3B0ULL, 
            0xD838BCDD9E73179BULL, 0x59979DFD510BBEE5ULL, 0xF3EE465A29F50BF3ULL, 0x20D4B7FB5F22CEE5ULL, 
            0x6ABE0444DAE34A99ULL, 0xFE7F68F390C45576ULL, 0xCA991F4D4342A791ULL, 0x09D3B0ED6F2DE922ULL, 
            0x4AC8D33610A2EE13ULL, 0xBB5A8B66F7E17587ULL, 0x3950E3ED695BEED7ULL, 0x0DDBE11794F96AAFULL, 
            0xA992C7ECE3CD51D5ULL, 0x096A52CB349671C4ULL, 0x942A069D3A7D84DEULL, 0x04C296CA98A2E31DULL, 
            0xAE681AC487358871ULL, 0xB69A2A650FF4366CULL, 0xADB3A3475501EFF8ULL, 0x0E323F5B75ED3F49ULL, 
            0x8CC1E4A1A93753E5ULL, 0xC5516DB907F71D07ULL, 0xB62F6E8C8A71D76FULL, 0xFD410CF66F64A5F6ULL
        },
        {
            0x5693726B9C1D0A7EULL, 0xF08B361C6569DFD6ULL, 0x3480470DC00106E8ULL, 0x426523EF36BC774CULL, 
            0x183D89F1C102A7D2ULL, 0x085D01ACCE58C74CULL, 0xB3A4BAB8C71B17E7ULL, 0x26EADABB6526B6D3ULL, 
            0xC86BC8C936E25AF8ULL, 0x580F2598E33B2482ULL, 0x39EF1352BAE001DBULL, 0x60C0B3963131483DULL, 
            0x9D1618C589F93D63ULL, 0x8F17ED5B69184BC6ULL, 0xBC27719816E584ACULL, 0xA3DFCB87EBA70BB5ULL, 
            0x0E5EF0B004D0CAE9ULL, 0xB99BC5BC602A4665ULL, 0x7D33D29D012E79E6ULL, 0x8936418DD7CFBB79ULL, 
            0xBE5BBA66E6C66CF0ULL, 0xC2DA1D11AC6A2379ULL, 0x47D4D696A8A000A2ULL, 0xC511F3EE520CA223ULL, 
            0x1AED61F881958EF6ULL, 0x2CC80A8ABE57D139ULL, 0x43E1B7F97762E129ULL, 0x62229963C3FC7A1FULL, 
            0x23DA3734CF1A8593ULL, 0x098E342DF0334D9BULL, 0x6287D76FABB6FDCDULL, 0x794808657F899A64ULL
        }
    },
    {
        {
            0x80E1A9685B64FFEEULL, 0x03A02C1E96285715ULL, 0x791451252FCC982AULL, 0x8DC89660A889FC77ULL, 
            0x9264BA7953B967B0ULL, 0xF1CEA10D7EF2C590ULL, 0x3F00F75FF6FAED70ULL, 0x9CDD0E0EA2A32833ULL, 
            0x698CB7D43A78EE0EULL, 0xA10ACC9813E934DCULL, 0x091C5E1F5676995EULL, 0xCA49C12239FAA844ULL, 
            0xD2510E5C9B1FE752ULL, 0xB88D01CCC31293B6ULL, 0x11EA421D3B4AE0C6ULL, 0xD66379190CCA657BULL, 
            0x1F2214AE75252452ULL, 0xE3125ACC8844972AULL, 0x3C1FC690356852F5ULL, 0x6621B6F25D612C13ULL, 
            0xAB9208827938262AULL, 0x1D39A4112CC405A6ULL, 0x72A03C11066F80C2ULL, 0x4E05166A587ADF6AULL, 
            0x3DCD93F0AFDCAEDFULL, 0xA9746CFF6635418BULL, 0x13B9112269BA6762ULL, 0xE33AEA516B13F8B0ULL, 
            0x4FF728C14A9A57D5ULL, 0x127541B5C507C352ULL, 0xC0A5F1B8F7AC5142ULL, 0xB8278385136CE149ULL
        },
        {
            0xA3A024352699DDBAULL, 0x4264FA4266234D9DULL, 0x9F448BA7F1EDA92DULL, 0x65BDDC1B90F4D593ULL, 
            0xB58C770DFE6E1118ULL, 0x72D11606B2521E15ULL, 0x96D6B7AC092123D2ULL, 0x1BCBC5C48E06D3D6ULL, 
            0xF3188F0C8A3B3152ULL, 0x64B4800726A321D8ULL, 0x071E4E3C60B00A40ULL, 0x43A49939E8918768ULL, 
            0xCD033883B93FD88FULL, 0xCB4595AEDAF5817DULL, 0x2F3D0E2C1BA4443EULL, 0x7C46CDDF0CA662EFULL, 
            0xFE2053464274DF86ULL, 0xDCCB4EC1799F2CA4ULL, 0x1283559E7C614363ULL, 0xA644292633AEB2C8ULL, 
            0x432E9DA8F9F8A230ULL, 0xEA287251C112DE26ULL, 0xE9E381D1A797F6F8ULL, 0x30686CD532F92740ULL, 
            0xBA0494A59CA4DA24ULL, 0x7161169A95EDBB9CULL, 0x1B91317DDBE929E0ULL, 0x8F4B923256775DD7ULL, 
            0x8BB196A649B1AAC8ULL, 0x07F8A3AEA263B636ULL, 0xA82208B92A29D0B9ULL, 0x56F20CED8D0456A1ULL
        },
        {
            0x4947088E3EB481EBULL, 0xEE6181123FB26B66ULL, 0x1436DDCAE6B22E3AULL, 0xF1DC163A91B59674ULL, 
            0x84CD2C0DD0214953ULL, 0x925659F2F3FF8C00ULL, 0xB2DE0E07F1A26AC6ULL, 0x472EA67178183E0CULL, 
            0xB987D6265A94ED19ULL, 0xAA38E2ABB3521EF4ULL, 0x6DF628573FD2F6F6ULL, 0xB2E646BF23DC3F7FULL, 
            0x4B1B3E9173700FC3ULL, 0xB8E5854E9E6ED5DFULL, 0xDD6DFC5B31443A31ULL, 0x43B7F18D5033B626ULL, 
            0x2E0DCE903F5F0EC7ULL, 0xDC0E1DE4A64C00FAULL, 0x33A611EB1933736EULL, 0x0552EA62EDF8E604ULL, 
            0x76ABAF0D8B402BA8ULL, 0xBAC21733A923374DULL, 0xEF139896B872C683ULL, 0x4FCDB8FED1FAA915ULL, 
            0x19B7A370A512CBEDULL, 0xE9E1CDD8A3E08EAEULL, 0x2DDA3BE80000E44EULL, 0x50D1E6065BD3AB06ULL, 
            0x2A5C8B2AC0A704F1ULL, 0x8C4471C0C5BC4AB8ULL, 0xEFC43ECE9E5FA65AULL, 0xB4A613DDA663F730ULL
        },
        {
            0x8CB819A1925365D9ULL, 0xCDECDB9CE5B1185EULL, 0x3E1E58A70FEE49C5ULL, 0x376404E3AF010D0CULL, 
            0x1E22988FE8CF01AEULL, 0x4DDDE974D1E1F6C3ULL, 0x19AE6E7A3E1BD952ULL, 0xE052A4AC7F247103ULL, 
            0xA886C4F3C08EEDE8ULL, 0x770A439F7EE259E9ULL, 0xEC92DB37CD31B2A6ULL, 0xE31D99A628A4A5CFULL, 
            0x5BA713DA853B3E86ULL, 0xABCB30FAC7286ABCULL, 0x446E86FBC6D95ED3ULL, 0x9C18E78964E3C9AAULL, 
            0xE3928AFD2C555356ULL, 0x1B0015AE7EDA7F13ULL, 0xEC12A876390B8A9FULL, 0x931FA78152E0D764ULL, 
            0xEFD2EA60F8084662ULL, 0xC520C02B0F6C868BULL, 0xAD76A09D04947776ULL, 0x88C227A054B9D02FULL, 
            0xED7AB48C74DCDAB5ULL, 0x42882CD7FDD787B1ULL, 0x1AF822B1D3146FE1ULL, 0x176C1AD2E394ACCCULL, 
            0x2B2C147CF112FE78ULL, 0x75C607AA987BC99FULL, 0xC96324A448459EA3ULL, 0xF73817D6B580F6A8ULL
        },
        {
            0xDE3608BD05E7C3E7ULL, 0x729E502CAC0FC3F1ULL, 0x2B78DC959B951C55ULL, 0x16D50948848A4AA9ULL, 
            0xCA1C7231EE4DC39EULL, 0x4CEBF1C9F3BAE5FEULL, 0xE3F892E033A2B75FULL, 0x115FD0F941476D1BULL, 
            0x8662E3C0CE4B2373ULL, 0x68424CFBD043634BULL, 0x59E6715A64BE27CFULL, 0x28BADD9F023281B3ULL, 
            0xA1DE8BF78C5B894DULL, 0xC7013E2B28F81B17ULL, 0xB0F3F01AEB1EAE81ULL, 0x8E2E6C5380F67316ULL, 
            0xC900EDEE8C483986ULL, 0x5F1187D0946B7C91ULL, 0xEACDCB201E53E6DDULL, 0xB7FBC6AFD1D9C43AULL, 
            0xBD1EA6CBDE6977B4ULL, 0x0055FCE3E02C1A5BULL, 0x13DAD9EFC7951240ULL, 0x26CFD8B99439526FULL, 
            0xCD891CB507E0407CULL, 0x52F7CF723B7E6D59ULL, 0x14AA51A3875E7450ULL, 0x88051BD57A530528ULL, 
            0x57B39BE76587AA7BULL, 0xD265253E35B4517DULL, 0x4AB8472C80EC2EFAULL, 0x2AD4E04DF3F6994CULL
        },
        {
            0x702116A8509CDE2FULL, 0x23AB2586F8DFB445ULL, 0xFBE4245FE0C18A3CULL, 0x5D5F145D5B54DA5CULL, 
            0xC4BBBE0A5DBCFF27ULL, 0x9B9FC241C9B4E6E1ULL, 0xFFC0F5CF6E2A50AEULL, 0xB41799694FCF9889ULL, 
            0xCA4452A52D56FAD5ULL, 0x0B5A8358DB8E5DD7ULL, 0xF21EC8814329AAAAULL, 0xB95222F6C81D43D4ULL, 
            0xF14843ECD7B56680ULL, 0x5B6A8166F3BC42E9ULL, 0xE09BFE8CD138F5F0ULL, 0x04E2E4B5510E0F0DULL, 
            0x896CFA66557632AFULL, 0xB2A39FBAB21DDFB7ULL, 0x98FE3FEF67906D36ULL, 0xD73A8E36C081E8FEULL, 
            0xAEF913FC7BBECBB9ULL, 0x9D8A30AFF9F3AB1CULL, 0x76AAE8661D1BACC1ULL, 0x566EC2CB949FC3A4ULL, 
            0xB1AEF2C6ADDF94E0ULL, 0x685DEF3BE6CAA974ULL, 0x43141405F1F36357ULL, 0x4A97A14C001BCB7BULL, 
            0x00EEF48421F4335EULL, 0xF4620BF120B0CE9AULL, 0x6AA5FA0949804D86ULL, 0xE85088D55C3B8320ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Aldebaran::kPhaseCConstants = {
    0x37AA5FD67629D5FCULL,
    0xA85D8C44DB40C2A0ULL,
    0x7561E248B15B091DULL,
    0x37AA5FD67629D5FCULL,
    0xA85D8C44DB40C2A0ULL,
    0x7561E248B15B091DULL,
    0xDC8B81812FA73E21ULL,
    0x35F55A6D2538A82AULL,
    0x75,
    0xBE,
    0xB9,
    0xFF,
    0xEE,
    0x4C,
    0xC6,
    0x05
};

const TwistDomainSaltSet TwistExpander_Aldebaran::kPhaseDSalts = {
    {
        {
            0xC8828F8FE5CF6535ULL, 0x48687325AC469749ULL, 0x73A643E2285CFD85ULL, 0x1BA25031F9679955ULL, 
            0xEC832C96C48D3AE1ULL, 0xAA58E2DBB099103FULL, 0xE9D2EABC1B790B58ULL, 0x219C9C75D4DFD829ULL, 
            0x65DE4ABB6BE9FA1CULL, 0x7C88C9F46197513BULL, 0x4A30196BA8CA32F0ULL, 0xFF0D88B64789B5F6ULL, 
            0xA9A63B008B97DF70ULL, 0x5BA6623035617627ULL, 0xFBED2CDBA8DAB448ULL, 0xF56600714E8F2E67ULL, 
            0x1FA0D005D9AAA419ULL, 0x57B7DAB4C798471BULL, 0x561FC30AE745B06FULL, 0x2F7D632EB7E1C758ULL, 
            0xDDA79C3350C498B8ULL, 0xB7B3602C0BE041D1ULL, 0x9F967331E20FCEACULL, 0xEC2D33EC5416FC81ULL, 
            0x7FB31115A9ADBDF0ULL, 0x1154388CF87FF76FULL, 0xD24DCCC18B8737B3ULL, 0x8B0E19EF0DA33A9DULL, 
            0x6ECC5D1267861743ULL, 0xA32EC4B7D797C802ULL, 0x34CE16B057371BFEULL, 0x74717E6D1C730F07ULL
        },
        {
            0x7FDE512B26EF1189ULL, 0x9D48BA9ED22196D2ULL, 0x66344D9493F82E4CULL, 0xF28C6813C5D825C5ULL, 
            0x5917A55D839E93C5ULL, 0x46280E306D33F762ULL, 0xA22F7EF86B6EA50DULL, 0xE30E9ACE71E1923BULL, 
            0x1F714049E634A871ULL, 0xF35F5888D57D1B3FULL, 0x9EB2F2663540921FULL, 0x12225A94F5445323ULL, 
            0x2D27CE3299FF9EE4ULL, 0x6975AF92BC7BE480ULL, 0x89F62B0EAACABE11ULL, 0x76036F5831AF104AULL, 
            0x9C33003C6F76FAEEULL, 0x79BD7E1654B9AFA0ULL, 0xAB38868388C02A69ULL, 0x72855492A37AC28CULL, 
            0x898BF4A29AD960C8ULL, 0x631F28E4C10C9CC7ULL, 0x1DEF5D5522D617E0ULL, 0x832673EFDAB2A4E1ULL, 
            0x5997185C338C6159ULL, 0xA0EB040A3AE5B13FULL, 0xF0656CF20D3877D0ULL, 0xCC7502C29E0CC721ULL, 
            0x1CB5D659A316F793ULL, 0xD5A364C6F4C20CFAULL, 0x8CB305C935D35AC5ULL, 0xB404B21303F7B713ULL
        },
        {
            0xD84BFD7A8D8C0271ULL, 0x81D262F1FD42C335ULL, 0xCB84B1A8F4143011ULL, 0x81CC824AB48FF158ULL, 
            0x2E86F03C9A59537EULL, 0x7FF13A15B0612189ULL, 0x4B652F426F456142ULL, 0x39220D20335DAA95ULL, 
            0x94EE39AA917432A8ULL, 0xDF41B3F301FC59CBULL, 0xB7E26762432AD5BBULL, 0xFAD210982BA6F830ULL, 
            0x1D8E936EDE09D8EEULL, 0xD991972E75F74174ULL, 0x745ADB18B6851C25ULL, 0xE124A24A40928273ULL, 
            0x620A4459072657EFULL, 0x5BA24A576D792468ULL, 0x07E543ABB2F4410DULL, 0xA3866DA346F812AFULL, 
            0x032763B7A1724EE3ULL, 0x0BFCB1E8B23021BFULL, 0x50BCE61B427539D7ULL, 0xC405A177B01F4170ULL, 
            0x04884FBD68774D7FULL, 0x0C60E47DAB72868DULL, 0xB18E271DBA529CA3ULL, 0x9F2ED61BC655C054ULL, 
            0xA7497269A52364BAULL, 0xC8E39480F0948610ULL, 0xCC26E8069726C793ULL, 0xE646AB6AAFDD3D0FULL
        },
        {
            0x2EFEFC3B830436B6ULL, 0x1EEE48AE07E51830ULL, 0x5D5CFD005E34758CULL, 0x16C3B58F1AF02270ULL, 
            0x0A935D4EF1FC548EULL, 0xB3987C3AFBBA1B3EULL, 0x19154AD27F5F6343ULL, 0x9D4BC423EA8C4B1BULL, 
            0xA78F018FC7759F7BULL, 0x8857865122249276ULL, 0xA29282721C748983ULL, 0x0128E89E9E16EC0CULL, 
            0x32891193C321B85AULL, 0x2B813E34A6F90394ULL, 0x32EC30FA92B3309FULL, 0xD4EBEC834FC35963ULL, 
            0xC38DEB60DCA62AA8ULL, 0xD701DA8C3E2CFD2AULL, 0xC454557B88570CFAULL, 0x211D29D89B3757B5ULL, 
            0xD62C8522FA09D89BULL, 0x2F741DE2409B90B0ULL, 0xB967883FB212D6F9ULL, 0x5B4189E4BE2AC438ULL, 
            0xCA0F09FAD99023E7ULL, 0xC345C0B2ABF6F2D4ULL, 0x027EBE3FAF79F09BULL, 0x1A894BFE8C747BCAULL, 
            0x941FB58E7A41EE22ULL, 0x12502B39E986B91FULL, 0x6043C205E42AF9A4ULL, 0xA3E6FCA046290862ULL
        },
        {
            0x8A6FCDE55C9F5ED0ULL, 0xB444D5027366FA46ULL, 0x67329ED559B125AEULL, 0x5BBE4F69DBD80002ULL, 
            0x6FC73070C74CD112ULL, 0x93EEABA249DC0925ULL, 0xDB25F90988A14F5FULL, 0xD2A73F5F25A41DB2ULL, 
            0x5DBE74BD0BBFE075ULL, 0x07907EB3CD3C49CAULL, 0xCFB22EA9304D0A40ULL, 0x3D3BF61BEF89C2F4ULL, 
            0xF2206ADB58D323CAULL, 0xE0BC6365BC9F4161ULL, 0xDF8323C8810E07BDULL, 0xB8CF168AF5C15D7BULL, 
            0x18AF67709BE61604ULL, 0xD96CC7BCF51CE82CULL, 0x7164FD2A933E4B5EULL, 0xD8F23FB79D2D0E04ULL, 
            0x6D01B0AF8A317B74ULL, 0x1C76FDB9530C08B5ULL, 0x21B58A357A994CD2ULL, 0xC8BF732C301C7D4AULL, 
            0x8D16D007F2754EB8ULL, 0x7C16D19F19BCB704ULL, 0xD35B6724D4A5B3F1ULL, 0x85F457C57B52857AULL, 
            0x069E67DFF95AD280ULL, 0xD40EC6B11C889BB9ULL, 0x256850CC08F3AAE3ULL, 0x0978FE2DC6DB39CEULL
        },
        {
            0xEE18315ECE5F9510ULL, 0x0267B4D1FDBAFD16ULL, 0x42703709BFE5BEFFULL, 0x886C1FA68530C896ULL, 
            0x047581E1164320DDULL, 0x5B2C64C328046AB9ULL, 0x42567B1E0900C81FULL, 0xF8487B8EA24D5F61ULL, 
            0x198480B11DEDDD22ULL, 0x4296A2B9A132FEB5ULL, 0xF154C9013FA112CCULL, 0x5D242014D704746BULL, 
            0xB50831C7B07A8B85ULL, 0x181EB88E549673DFULL, 0xA4B24EBE892F1FDDULL, 0x4BE50A7A96EDBF17ULL, 
            0xB888C36F520BC560ULL, 0xD9FC817D31F39BB8ULL, 0x3817344EFCE65B8CULL, 0xD16D139A6F2AE581ULL, 
            0x6F2CAE8599E22FF0ULL, 0xB70FDC595A80DC49ULL, 0xACDEADC03255CD03ULL, 0xF85F0E75F93B523BULL, 
            0x51E364BCD1212EC7ULL, 0x8CC3B6A9EA32EAB0ULL, 0x799E60A9E3559006ULL, 0x45157AC9EA1F036CULL, 
            0x4AD874BCD5F3EA0DULL, 0x3BA0EE0295C2C82BULL, 0x016E8048E3041F3AULL, 0x6EF7DBBC248D5F21ULL
        }
    },
    {
        {
            0x6FF20EEBDF66C5F3ULL, 0x092AFA7385C19714ULL, 0x9F4888DC3BD85153ULL, 0xB3618E8AFAB81403ULL, 
            0x6C619DC93D026D52ULL, 0xA589D8340B4977A8ULL, 0xE12A458F3CFDBEE9ULL, 0x7A23379CD7651281ULL, 
            0x05DD424EDF042D49ULL, 0x1F9D6B3EC323E343ULL, 0x9A51F54EB91CB9D0ULL, 0x1BFB504D1BA37CC9ULL, 
            0x2D102D6910BFDFE5ULL, 0x4E37C63CE6645573ULL, 0x7F58A3C9FFF9D59EULL, 0xD8F1F5DC60185693ULL, 
            0xED987A697089C7D8ULL, 0x9E05C830C840AB96ULL, 0xA661A194D7CF8FE1ULL, 0x90D584907E46739FULL, 
            0x2264F175D672A443ULL, 0x020CD5A0CAAFE6FFULL, 0xDAFB91EAFD919F63ULL, 0xB01EB5848295C24BULL, 
            0xAA603EAB3EF0F54FULL, 0x94307CF7126C68F4ULL, 0x5BF2B5DD91CF5083ULL, 0xC184B13469D03DD9ULL, 
            0x507D7D16B5AE3320ULL, 0xEDE21E6A213E3740ULL, 0x493719416551D51FULL, 0x4E62898AE39163D5ULL
        },
        {
            0x0D4AADFB6C81A915ULL, 0x00DD2756A4BF1887ULL, 0xF1C35789203B6EEAULL, 0x4E54306B48802A3CULL, 
            0x4EF2E0CEA7BEFBB7ULL, 0xDE7543C505603880ULL, 0x31BA267FCAD7E42FULL, 0xC3274114DE9FD356ULL, 
            0xB85E771E4710A0ECULL, 0xF0C8BFD4C155AE24ULL, 0x51270D6A25E4D14DULL, 0x7ADD953C64A00D4EULL, 
            0x386097D90E0FCDE6ULL, 0x2327A94F826D39E7ULL, 0x445882B44279EDF1ULL, 0x24286A57C889B6B5ULL, 
            0x6FEB18AAF07A0430ULL, 0x8A22FEB033EB4F2BULL, 0xC3996B9D4D1B6EEFULL, 0x282836575A4FDF79ULL, 
            0x34A11580F05646C0ULL, 0x735F7A2A1CAE58E6ULL, 0xB4F740C829690CA1ULL, 0x34AED4DCB25B46B5ULL, 
            0xA7FF7BAEC2DE8096ULL, 0xEE0CD6D92794D417ULL, 0x1E045F4A204BF39CULL, 0x19766D98AE2C60D3ULL, 
            0x1B5B1B3C203C172DULL, 0x8EF39DF8635FD8E9ULL, 0xD345CFE44574CDD9ULL, 0x6DBB67CC43F4DB29ULL
        },
        {
            0xA52A38BA31A62DA8ULL, 0x2E65500227602C6FULL, 0xEC7C00DF9FCD67BFULL, 0x3A825A2797EE341AULL, 
            0xD4C83E7740A54C27ULL, 0x508AED8AAA0F58EEULL, 0x33B9A98203AEDFDDULL, 0xDFEA25B43D9CC08AULL, 
            0xA273312F431B5E8AULL, 0x24739A9D959B1665ULL, 0xC93331A417326048ULL, 0x9DBB3A8DAA3AC215ULL, 
            0x04AC9C9E9240A7D0ULL, 0x5823A2D2F8A7BDDDULL, 0xD0D0397FD892BE61ULL, 0x24AF38837D2B9082ULL, 
            0xF45B03A0764596A8ULL, 0x7E19B9B2E79B1048ULL, 0x03EA8844AD2501D2ULL, 0x2E02E189430C4E85ULL, 
            0x6A3E517BB210CD2BULL, 0x844EB09016A0B678ULL, 0x32F601CC86F4EB6BULL, 0x2E88D538CE0BF8DCULL, 
            0x2C4407E1B6E3946CULL, 0xD8C71C55B596B874ULL, 0xB756D303A54D55EEULL, 0x7ED37AA0AF33F79AULL, 
            0x879429D6231953ADULL, 0x85366C0FCA1323A5ULL, 0x9E56DC3DFEFF6EA9ULL, 0x03D0DF5A4B9FB1E5ULL
        },
        {
            0x3D89C06F3B166B84ULL, 0x2195298E46B2D17AULL, 0x851337E5B0166CAFULL, 0x464F883BF88E487AULL, 
            0x60CCEF0BB8B59352ULL, 0xA9FA8BAF1DC03706ULL, 0x3622D8BEA5EFC909ULL, 0x3058DDDEEE08A225ULL, 
            0x9E7F7C9DE4E358E5ULL, 0x7EDA4A4A23597024ULL, 0x7989AA13D55D6106ULL, 0x0466FCDFD754D3C7ULL, 
            0x7B567389F3A97CCDULL, 0x65BAD636C64294C0ULL, 0x83295EA34021FCE9ULL, 0x4710FA78ED230ED7ULL, 
            0x681842FD7032ACFEULL, 0x4D2E3456BA7BD0B4ULL, 0x11B54390E92DC8B8ULL, 0xF95F7A8B5A2053E2ULL, 
            0xB4EC591E316871ABULL, 0x2154CA7E510B270FULL, 0x6627C6C95F6D9172ULL, 0xE503CFE6603368F9ULL, 
            0x26D130609F202344ULL, 0xC7E4F014FB78B769ULL, 0xD12B24FF3A303255ULL, 0xEDE0CA2BF7839E92ULL, 
            0x93C76FCA5E95D6D3ULL, 0xC0055CE000EAE09FULL, 0xC658FFD2A11D642FULL, 0x8B2DB42C1C1EE90AULL
        },
        {
            0xEBD023AB5502CA30ULL, 0x0E3DF234B3F09104ULL, 0x4C352B301A403C05ULL, 0x03C4764AF089E99AULL, 
            0x88A2572E413C142EULL, 0xA53567C87F149686ULL, 0x42527C727F6D3AE4ULL, 0x5213657F977DEB9FULL, 
            0x6B8990CC569E8994ULL, 0xB749A340B2E87B9FULL, 0x825B9409996E7571ULL, 0x4FD76F8D3AB035EFULL, 
            0xCF1BBA8469A695C2ULL, 0xC3A44E0B1D0658DBULL, 0x9542675EF92DA44FULL, 0x94BDBCF9A8304B89ULL, 
            0xC2D7E89CBAA8C697ULL, 0xC458B3D843A7C423ULL, 0xFC7D57323E33508AULL, 0xBBD049476A41F173ULL, 
            0x343DE504CD5FD612ULL, 0xC3484AB2B4C266E2ULL, 0x5F549E9A5A124DE6ULL, 0x86E2FB7FC375614BULL, 
            0xB7D035E3F37A7BB5ULL, 0x8B0E1C75382EE3A7ULL, 0x5ABA39F7A5641EBEULL, 0x3E956E4E7B66D8C9ULL, 
            0x8505BBD07A5F9F19ULL, 0xEB73CDAA30D3594BULL, 0x39C9FCE96C3669AAULL, 0xDE47ACF77AF38937ULL
        },
        {
            0x055BF60E7A58B7AAULL, 0xE4EBCB4B318B56DCULL, 0xD19030A3591A7F9BULL, 0xE32B4AD9B8519971ULL, 
            0x2A4CA0DE08235D8AULL, 0xF1D9FB8E4DDEEB39ULL, 0x167A76B754936984ULL, 0x820644D5E51CA87EULL, 
            0x770C3F8FBB7D7167ULL, 0xC0A0325FE680C34DULL, 0x49B948B085FEBC6FULL, 0x7B458B6FF9A509BFULL, 
            0xB23B4CAB898D147CULL, 0xE9F8BA1A61450401ULL, 0x02C1B83C7F9C5C8AULL, 0x0F017C64F1C63E90ULL, 
            0x5E29992E1787BBC3ULL, 0x7CDEB40275A3F41FULL, 0xA156B91EB05EF2C7ULL, 0xC4D9E9422E7C1520ULL, 
            0xD517646BB7E51523ULL, 0x98E380FBC7DEF4B9ULL, 0x5BA0FE2111A786F2ULL, 0xE5C2ECE134A8AE65ULL, 
            0xD1C2763DF381EC16ULL, 0x04C19D29548D19B4ULL, 0x96771114AB2F9AB6ULL, 0x2EF8CD74865EA916ULL, 
            0x5C9D197A05FF745FULL, 0x04A0D4B24D8A256CULL, 0x94D66DC91CF25591ULL, 0xD64348851240310AULL
        }
    },
    {
        {
            0xB2721D081B8EA52DULL, 0xB66F4C03985F8DDFULL, 0xCFD5C1FC0D169321ULL, 0x29FB1203E8F489E7ULL, 
            0x973247E7D919FC2DULL, 0xB25E2A20AF246FFCULL, 0xA8432951E7ECE6C4ULL, 0x6BCB4D7D8511D100ULL, 
            0xA3345B14B4D860C3ULL, 0x40CC920A62D54463ULL, 0xFF95B47BEA5BE0BAULL, 0xF5370136AD73F06FULL, 
            0x6192B2AE5511BF2FULL, 0x57ACD403C79CA0D1ULL, 0x4AADAE8E21322576ULL, 0x61620ADA3A5FE954ULL, 
            0xE947433B0C078B70ULL, 0xFE4671B7D2AFE379ULL, 0xE3349B9A97877E3FULL, 0x0B8BF3AD29A2CF74ULL, 
            0x49B88D70BE8B240DULL, 0x70765A9C81F82114ULL, 0x98E7F2F16C10EDCFULL, 0xDB375BD01AB6DAF4ULL, 
            0x006F08C0E206B2C2ULL, 0xBB59B2AAF75DC06BULL, 0x7E360318A098BCD2ULL, 0x8C2CC1B5A496129EULL, 
            0x26B3BFC48C87D34EULL, 0x74A1A66BA2F25030ULL, 0xF6029FE40EF16197ULL, 0x48E7CCB5261A0717ULL
        },
        {
            0x8CECC182E477682FULL, 0x7640E193DFFC37ADULL, 0xC174D9BF53682DD3ULL, 0x531D93DC325577D3ULL, 
            0x12B0717B1328F032ULL, 0x25CBA2D17816B058ULL, 0x9A2306E68BD765DEULL, 0x466878F36C83F9F5ULL, 
            0xE3D71F06DC7AC282ULL, 0x0639079BEE182687ULL, 0x8D253EA114849940ULL, 0x09D083E4A49ADFC9ULL, 
            0x28AE1FD649244091ULL, 0x12ACCC871B5F4D0FULL, 0xA8C22FA5D1260492ULL, 0x8DADF384BC519DC9ULL, 
            0x7CC847ECDF7E66E4ULL, 0x0592BB2E073918C1ULL, 0xB9C8B336C34A9F14ULL, 0x45828EB8D2C981E2ULL, 
            0x930E80253C83BEC6ULL, 0x3529B355CB981C35ULL, 0xC326AE38486C59BFULL, 0xAC93E3BBF33DF96BULL, 
            0xC8071E1533A25AABULL, 0xE7599C3227AEDEF2ULL, 0x1E7D3A1D97D871A8ULL, 0x447E107DFD3A8637ULL, 
            0x5EED3F8B708BE5BAULL, 0x284E4A229128B4D7ULL, 0x385F2C46276339A4ULL, 0xC9A5CA220C48C8A8ULL
        },
        {
            0xF44FA07FC2498DF3ULL, 0xA83DBC5D3D6F78D8ULL, 0x82929CF787DE5CD7ULL, 0xE9C8AE64F096C768ULL, 
            0x4F46B100D4569779ULL, 0x706FDC3AB1B763DEULL, 0xB92833662FD14B9BULL, 0xDEA6D0857AC974BFULL, 
            0x3C0C052D82ECCFFEULL, 0x0FC812CE1197C093ULL, 0x529CF58B651A140AULL, 0x32874EECBEADF0B6ULL, 
            0xB8E1B3B3D017658AULL, 0x45E6064F33C38A4CULL, 0xE9D64733B9A7C0CBULL, 0xD659DB341AE41AA5ULL, 
            0x71FF3CC7407D257CULL, 0x6E51FBC62A6195C1ULL, 0x843CA462990AEE91ULL, 0x057B52A96CA0719BULL, 
            0x5FC4312A8ABE30C7ULL, 0xAB05BC00BC457680ULL, 0x4BD181916FFF5424ULL, 0xEE7BBE41BF489998ULL, 
            0xF66D4AC7452DEE13ULL, 0x8C0AB77A09FEC02DULL, 0x19E4B21F75956157ULL, 0x5CB6B4A5DA4075BCULL, 
            0xC3F6DC9A01F90276ULL, 0xC33A85E076FF1C41ULL, 0x7C496BBCEDE553C6ULL, 0x47B7E020244A7D3EULL
        },
        {
            0xD9D531E377BFDD70ULL, 0x5AF99787F592624AULL, 0x2D2C11FCBFAFEFC0ULL, 0x0D624866DDBE2CD6ULL, 
            0x512DB2F12D9F0012ULL, 0x50B16B43E401A8E7ULL, 0x6AD53D1C085FC60CULL, 0x43D2D2318794FFF6ULL, 
            0x06297504B0EF3691ULL, 0xDEA306C79FEE017EULL, 0x4AC2366136D2953CULL, 0xA5DB5BBC5392EE00ULL, 
            0xB6506E428AFFEDABULL, 0x01F45E1E68318048ULL, 0x736B2AD9F154ACA0ULL, 0x8787070DA8B4839AULL, 
            0x3C0C0766A1D02C0DULL, 0x9D376FE9BF3F5C10ULL, 0xF79D525E2D20A401ULL, 0x3E71F89D2CFBB6CFULL, 
            0x926C6D3C4CABE017ULL, 0xE394744230D8E96EULL, 0x05B52097094D295FULL, 0xE3627214E6B4D10CULL, 
            0xF5CF2BE4DB3EDFB8ULL, 0xA4EC4DCF2E847058ULL, 0x30909330F7E4F500ULL, 0xDBC87E3AFB818BF7ULL, 
            0xD662C3002162DDCCULL, 0x48252FE8F432763EULL, 0xE4D8509398C90163ULL, 0x8AB94FC924C0B70AULL
        },
        {
            0x1B5DB37195A2D09FULL, 0x02B08AD3A5EF7C1CULL, 0x26BFEF940805D9FEULL, 0xC85B318AABDB224FULL, 
            0xDCC0F9FB6D8F7988ULL, 0x2CA76CEEFB4888C3ULL, 0x0BA39CB30AC05921ULL, 0x624C5B947EE1FA20ULL, 
            0x0C9D5461C219B2B9ULL, 0x88657DB06049634AULL, 0xCCCCD66881DE5575ULL, 0xBFE59DB3EC896510ULL, 
            0x851F4DC0F54AC467ULL, 0x26A179B340807F31ULL, 0x937580D5C21DEBF6ULL, 0x1360BBC11DEDA13BULL, 
            0x74AB8D08FF08192BULL, 0x1B90F2E86E140285ULL, 0xAB06E4809FD32BB4ULL, 0x1C8599F9E878856CULL, 
            0xB11AED1D8CDFFB16ULL, 0x97B85D4F4DF24A5CULL, 0x19E414AC28118A1FULL, 0x09ED5C2596E75056ULL, 
            0x79806B078BBD3C32ULL, 0x264BCD85B332E3FFULL, 0xDC8062AC4AD7FD5DULL, 0xD3C12783525FAF70ULL, 
            0x95AC30E0F8F6C7BBULL, 0x736745D49FEC7605ULL, 0xA75A79ABA952D8ABULL, 0xDF02396BDA83CF0EULL
        },
        {
            0x6C810BCC91CB5E0FULL, 0x73A8732B4D8EA7E6ULL, 0x9FE9F45DC9501D7BULL, 0x43E37079503C0B16ULL, 
            0xB906DCFC296AED5AULL, 0xE50E5BBF9AA9B4C2ULL, 0xDD7B4E6CBE8422C7ULL, 0x6AE1D89A0D15A178ULL, 
            0x5428DF5547C81DE5ULL, 0xE3CD06E029F6941BULL, 0x81539D34489033EDULL, 0xCC513A0B6FC02594ULL, 
            0x7D8C42D9E7DEB443ULL, 0x4184DA60D38C7325ULL, 0x245D7C084865EFD1ULL, 0xE05CF1E0D60A176BULL, 
            0x041F8373098C36F8ULL, 0xBED954E1CA57453EULL, 0xFC29C55D4F0BF4C8ULL, 0xA936A16C31AA7282ULL, 
            0xF1A7C9299F13A4EAULL, 0x9E3EE227850EF58CULL, 0x69805CC4CB13E833ULL, 0x816061167D66BCBCULL, 
            0xE5FB14A9FF55E752ULL, 0xDBFF85E441CFE2E7ULL, 0xE9166DFE2FBB3793ULL, 0xFA416D01C77D5D69ULL, 
            0x5AFD6DFCE1E77E70ULL, 0xCE582B0487D1C3B0ULL, 0xA746617F66A665D4ULL, 0x6B48D5C277DC49FAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Aldebaran::kPhaseDConstants = {
    0x9B813EEA28FE509DULL,
    0x17DCE42D1E4E2F65ULL,
    0xA22D801E66B9E562ULL,
    0x9B813EEA28FE509DULL,
    0x17DCE42D1E4E2F65ULL,
    0xA22D801E66B9E562ULL,
    0xE442B973DF6871B0ULL,
    0x3B8425D48803901FULL,
    0x63,
    0x5E,
    0xB6,
    0xEC,
    0x7A,
    0x19,
    0xF2,
    0x6A
};

