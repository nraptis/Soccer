#include "TwistExpander_Pollux.hpp"
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

TwistExpander_Pollux::TwistExpander_Pollux()
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

void TwistExpander_Pollux::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xDD0DF11957E33521ULL; std::uint64_t aIngress = 0xF39620CB3303F7CAULL; std::uint64_t aCarry = 0xB66519529C943618ULL;

    std::uint64_t aWandererA = 0x8BA55E359F7A623CULL; std::uint64_t aWandererB = 0x973E96DD97863A05ULL; std::uint64_t aWandererC = 0xDA8D88694A7EBD57ULL; std::uint64_t aWandererD = 0xFE4DEDA9A15EC147ULL;
    std::uint64_t aWandererE = 0xBA20A87554A27D73ULL; std::uint64_t aWandererF = 0xE87B48B66DDAD5DDULL; std::uint64_t aWandererG = 0xCD48E6FEAF325F92ULL; std::uint64_t aWandererH = 0xCFED57303F5B8677ULL;
    std::uint64_t aWandererI = 0x807CCDCF38DAFB24ULL; std::uint64_t aWandererJ = 0xDA00E1E4ED70FF10ULL; std::uint64_t aWandererK = 0xD49ADDDA00555E33ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xDE3FB0B9CDBCE446ULL;
        aCarry = 0xC11ACD6AAFA0C6E0ULL;
        aWandererA = 0xC2A0E7A0D938B513ULL;
        aWandererB = 0x84A7AEA312FB4658ULL;
        aWandererC = 0xCF1158F27D6D3A43ULL;
        aWandererD = 0xECB896DF1FE3C486ULL;
        aWandererE = 0x994FA510A55BCD0AULL;
        aWandererF = 0xD04B99CFAF144A1BULL;
        aWandererG = 0xA2310B9B06E52485ULL;
        aWandererH = 0xFD020A7BC86BD78FULL;
        aWandererI = 0x921A5730F21F3FEEULL;
        aWandererJ = 0xAF5D59DA9DBCB51EULL;
        aWandererK = 0xDA20A56A5DFCB832ULL;
    TwistExpander_Pollux_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Pollux_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Pollux_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Pollux_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Pollux::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x93CC889F73754992ULL; std::uint64_t aIngress = 0xE3BCC0AEB1B2B941ULL; std::uint64_t aCarry = 0xC9BA40F28CF9BD03ULL;

    std::uint64_t aWandererA = 0x940F48DC74A32001ULL; std::uint64_t aWandererB = 0xCBE8944146D0B89AULL; std::uint64_t aWandererC = 0x83441D0BAC2327B5ULL; std::uint64_t aWandererD = 0xC15768E0F76BE809ULL;
    std::uint64_t aWandererE = 0xC121AA537AACC4C9ULL; std::uint64_t aWandererF = 0xFB27A6AE2720700FULL; std::uint64_t aWandererG = 0xE11564B130343EA2ULL; std::uint64_t aWandererH = 0xA7395BDBC5B5EF7BULL;
    std::uint64_t aWandererI = 0xFD474408DCB8B1C1ULL; std::uint64_t aWandererJ = 0xD513DC65100FABC8ULL; std::uint64_t aWandererK = 0xD7B018256D7C0FCDULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xFD174C9A6E0DCFCFULL;
        aCarry = 0x9854465C1A8CB28AULL;
        aWandererA = 0x8C2BC4715E87C2C1ULL;
        aWandererB = 0xE1AC0344FEEADC63ULL;
        aWandererC = 0xB8B6D274DBAC9375ULL;
        aWandererD = 0xB5293258A692B7CDULL;
        aWandererE = 0xA06697C65A645224ULL;
        aWandererF = 0xF6FD3D5E55C3307DULL;
        aWandererG = 0xA3B264B883AB6AB2ULL;
        aWandererH = 0x95B5B5C2759CAFE0ULL;
        aWandererI = 0x852ADADA9763A998ULL;
        aWandererJ = 0xA3E59DE9C42B9223ULL;
        aWandererK = 0x8219E5BE23DD2F54ULL;
    TwistExpander_Pollux_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Pollux_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Pollux_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Pollux_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Pollux::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB7C36E086C7CCFA6ULL;
    std::uint64_t aIngress = 0x9F9BF02DD7207865ULL;
    std::uint64_t aCarry = 0xF083DAD76C07815DULL;

    std::uint64_t aWandererA = 0xB2C2A3AF64C6916CULL;
    std::uint64_t aWandererB = 0x8E07D33CD720882EULL;
    std::uint64_t aWandererC = 0x975CCD4F2AD04822ULL;
    std::uint64_t aWandererD = 0x9148DE103A168FC6ULL;
    std::uint64_t aWandererE = 0x93BA736C7A77BB08ULL;
    std::uint64_t aWandererF = 0xC5FA54F36615BE43ULL;
    std::uint64_t aWandererG = 0xD7832A3CC261B51DULL;
    std::uint64_t aWandererH = 0x866B9C4738917D51ULL;
    std::uint64_t aWandererI = 0xA45D559ECC51C925ULL;
    std::uint64_t aWandererJ = 0xD18F587B93C1D874ULL;
    std::uint64_t aWandererK = 0xCB2E78624831B5FAULL;

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
    TwistExpander_Pollux_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Pollux_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Pollux_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Pollux_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Pollux_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Pollux_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Pollux_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Pollux_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Pollux_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Pollux_Arx::GROW_B(pWorkSpace,
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

// SmartSquash candidate 25 of 33
// Exploration cases: 100000000
// Nearest-family diversity: 918 / 1088 (84.38%)
// Total distance from earlier candidates: 22520
void TwistExpander_Pollux::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    static_assert((S_BLOCK / W_KEY) == 16, "SquashInvestToKeyBoxes expects 16 invest fragments.");
    static_assert(H_KEY == 8, "SquashInvestToKeyBoxes expects 8 key rows per box.");
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 0U), *aFragmentB = aIceLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 8U), *aFragmentD = aIceLaneD + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 702U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 266U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 574U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1541U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 6U), *aFragmentB = aIceLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 3U), *aFragmentD = aIceLaneD + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 652U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1783U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 415U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1085U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 2U), *aFragmentB = aIceLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 6U), *aFragmentD = aIceLaneD + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 925U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1611U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 931U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1368U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 3U), *aFragmentB = aIceLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 12U), *aFragmentD = aIceLaneD + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 810U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1142U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1765U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1737U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 11U), *aFragmentB = aIceLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 7U), *aFragmentD = aIceLaneD + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 522U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 73U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 424U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1141U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 9U), *aFragmentB = aIceLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 15U), *aFragmentD = aIceLaneD + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 359U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 910U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1061U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 943U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 8U), *aFragmentB = aIceLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 1U), *aFragmentD = aIceLaneD + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 425U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1149U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1322U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1962U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 15U), *aFragmentB = aIceLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 0U), *aFragmentD = aIceLaneD + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1970U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1708U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1107U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 108U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 12U), *aFragmentB = aIceLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 11U), *aFragmentD = aIceLaneD + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1940U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1596U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 421U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 596U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 1U), *aFragmentB = aIceLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 14U), *aFragmentD = aIceLaneD + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1869U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 582U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1591U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1428U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 5U), *aFragmentB = aIceLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 9U), *aFragmentD = aIceLaneD + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 697U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 952U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 812U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1589U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 13U), *aFragmentB = aIceLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 13U), *aFragmentD = aIceLaneD + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 831U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 470U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1465U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 26U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 4U), *aFragmentB = aIceLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 2U), *aFragmentD = aIceLaneD + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1974U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1205U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1671U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 310U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 14U), *aFragmentB = aIceLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 4U), *aFragmentD = aIceLaneD + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 285U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1265U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 792U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 864U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 7U), *aFragmentB = aIceLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 10U), *aFragmentD = aIceLaneD + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1656U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 581U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 178U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1597U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 10U), *aFragmentB = aIceLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 5U), *aFragmentD = aIceLaneD + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1584U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 426U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1282U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 536U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Pollux::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE16E8D77AAAC92BDULL; std::uint64_t aIngress = 0xAE86884AFF1F6A28ULL; std::uint64_t aCarry = 0xC07A8EF8E897F143ULL;

    std::uint64_t aWandererA = 0xC2445BC1CD6A8901ULL; std::uint64_t aWandererB = 0x822CCF845F9421B8ULL; std::uint64_t aWandererC = 0xE63B2171B915E90CULL; std::uint64_t aWandererD = 0xFD880BA649D27F26ULL;
    std::uint64_t aWandererE = 0xDFC5A673B3E07B07ULL; std::uint64_t aWandererF = 0x9DC99897A25FFA73ULL; std::uint64_t aWandererG = 0xEDA99DC77A9E6554ULL; std::uint64_t aWandererH = 0xF31B4948494FE88FULL;
    std::uint64_t aWandererI = 0xF4CEE77DBD5851D3ULL; std::uint64_t aWandererJ = 0x9E58B66352A0E7E9ULL; std::uint64_t aWandererK = 0xED2DC3BBCE7DFE03ULL;

    // [seed]
        aPrevious = 0xE98EEC4EC1E9CC03ULL;
        aCarry = 0xA9F292AC2DC554DCULL;
        aWandererA = 0x83BC1D8E19D2F3E1ULL;
        aWandererB = 0xCE99E2995C10873FULL;
        aWandererC = 0xFD7F89B49B6AE6BAULL;
        aWandererD = 0x8A791911AF4808B0ULL;
        aWandererE = 0xB769287C6FD099C5ULL;
        aWandererF = 0xD27F9C5D02B4D087ULL;
        aWandererG = 0xAD922716EE25A9A4ULL;
        aWandererH = 0xF8842D61F6FC8EDCULL;
        aWandererI = 0xBA8C8CFBFC78A3B1ULL;
        aWandererJ = 0xD7EB94A3385B89E5ULL;
        aWandererK = 0xCFEF7B8FA6FA6C08ULL;
    TwistExpander_Pollux_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Pollux_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Pollux_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Pollux_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Pollux_Arx::Twist_E(pWorkSpace,
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
    TwistExpander_Pollux_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Pollux_Arx::GROW_B(pWorkSpace,
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

// GrowA candidate 25 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 13005; nearest pair: 487 / 674
void TwistExpander_Pollux::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6646U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6650U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5429U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1604U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4390U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7503U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 237U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5387U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4769U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6789U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 68U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7465U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 296U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2255U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8160U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 13U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1933U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 80U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 153U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 378U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1504U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1887U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1758U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1910U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
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
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1404U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1279U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1906U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 356U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 943U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 361U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1970U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1260U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 592U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1335U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1626U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
}

// GrowB candidate 25 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 13026; nearest pair: 478 / 674
void TwistExpander_Pollux::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1534U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4232U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2737U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3330U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
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
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7993U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5111U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1856U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1109U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1726U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5295U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1013U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7775U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1205U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4452U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1080U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 542U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1118U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1557U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 37U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 609U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 244U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2022U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 457U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1305U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1927U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 30U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1104U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1003U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 681U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1338U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 809U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 922U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 414U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1092U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1166U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 157U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
}

const TwistDomainSaltSet TwistExpander_Pollux::kPhaseASalts = {
    {
        {
            0xC1EB78A403310E3DULL, 0x5EED9CA41B954C3BULL, 0xBAAE410B23B818D9ULL, 0x936946E18D283EB0ULL, 
            0xC70E2D1926DB026EULL, 0x0AEB49EA9A91DF11ULL, 0xC9677D6FEC43402BULL, 0x05B5F2757B04AC7BULL, 
            0x1C92E37DB9E483BFULL, 0x4083ABB8AA4A6C1AULL, 0xDBC66C2307DA2E0FULL, 0x375E80DD58689C15ULL, 
            0x77EAB8C86EEE33CFULL, 0xE4D602B1FB92B590ULL, 0x1BF8277AE0D42998ULL, 0x9BEF463F371CC38DULL, 
            0xF68CFEFA78FE5EEDULL, 0x832CB5C376143FC0ULL, 0xDAF722B02D055FB3ULL, 0x48F1320EC6A0EBC0ULL, 
            0x0CDB9963952281BAULL, 0x03800ED7A462D5FEULL, 0x18253671A7539C1AULL, 0x18C6B08F2C76ACDDULL, 
            0x08F6D057C879E783ULL, 0x2CAD050B45FDBAF3ULL, 0x345D5D85384AC377ULL, 0x3CF6C8CA50387630ULL, 
            0xA3A76A159E0BE01FULL, 0xF7DFA9792E1B4F8CULL, 0x3F4304323DE0DF1BULL, 0x173AAB378D8D86BFULL
        },
        {
            0xDD6F71F861E3BB3BULL, 0x0E99A45709E1865AULL, 0x0FBE1994BF97190DULL, 0x4AF36DE7B73B1E3FULL, 
            0x5FCEA8054D7F2563ULL, 0xEA8CAFADA640F87CULL, 0x58D2768F2D3D33C8ULL, 0x375F2E47B1929D11ULL, 
            0xC6CC4750740FF67CULL, 0xAEC0BF06CE536004ULL, 0x482517050119F958ULL, 0xBE1B19ADED7AABABULL, 
            0x7AB1465DFA54A859ULL, 0xDFB6D0ABC6CE166EULL, 0x0864C8116E0B0B91ULL, 0x982ECC25476E4219ULL, 
            0xD42793B88B7700DAULL, 0x50746B5AC93D380AULL, 0xC10A56FB92D4FD2AULL, 0x2A3696C6E155E2C6ULL, 
            0x974DD11F44C537BBULL, 0x8EDD6D4CB8068BD7ULL, 0x232673A9619C2C18ULL, 0xEC0B234E6FC765EEULL, 
            0x967EFEAB22B87E10ULL, 0xD6B04CDF1D9C235CULL, 0x27016D56395B80AFULL, 0x81C9CE4F08D4638AULL, 
            0xC03AD05F4E5EFBBAULL, 0xEB71B668D612F772ULL, 0xAE959D527ADD7E30ULL, 0xE8BC071D73913F4CULL
        },
        {
            0xECB836A4BC5F3EC5ULL, 0xF37F56B6A7C329B0ULL, 0xDD4A1A4D161C71A4ULL, 0x3C862FAFF3F4FA08ULL, 
            0x550116A502110E67ULL, 0x4DA1749C67661107ULL, 0x2A7FF5F2F347DA5BULL, 0x70BD7D0EA6D2DF91ULL, 
            0x8B3640666D3A0AD1ULL, 0xCB77BAE2EB51A136ULL, 0xB74AB277944174CEULL, 0xD950A87C594B9774ULL, 
            0xE3CA227763AC7A1DULL, 0xBC93D251DA56ECFBULL, 0x9D39E52E4076C273ULL, 0xBBBC3816518235EAULL, 
            0x249EAEDDC30E8263ULL, 0x139599598327AD1EULL, 0x5F90D32D09994E9BULL, 0x4F90FAF3CED0C10DULL, 
            0x6AC38BE5E8E2E805ULL, 0x8FD31620A3F8412AULL, 0x09D527727F0B8C03ULL, 0xFAB6E0964674F321ULL, 
            0x5510008AC20E8C89ULL, 0xAE7B1891172DF268ULL, 0x21B3A225007B009CULL, 0x17C641891FB19422ULL, 
            0x9DDD025C565A0FBFULL, 0xBA7789BFA4B2E59EULL, 0x8BECFC8294010DBFULL, 0x2EE451D1E00DD626ULL
        },
        {
            0xB3843107A8B6786DULL, 0xDAFEC88CF70C3FE9ULL, 0xAA74668D5C75A312ULL, 0x85F6BFF2D13A9273ULL, 
            0xA6FE29E8EA715385ULL, 0xC3546542C7ABDB39ULL, 0x977980DFCE721F30ULL, 0x99237BD30460EAFBULL, 
            0xF75F935BDE9D9D35ULL, 0x6C896B70D255EF23ULL, 0xEACA3AE4313F5BDBULL, 0x2222C04198281B85ULL, 
            0xB95F6C5C4401D4A3ULL, 0x3CCF7836AC38D515ULL, 0x2706CFD871A14768ULL, 0x10CE535ED662F4FDULL, 
            0x455FC40B83F8AE83ULL, 0x10FD553E17AB2A98ULL, 0xD0CE12AC8CDD35E5ULL, 0x21F5D045EB775592ULL, 
            0x8B16CF7107B0CE48ULL, 0x8D3424E3CC58BD38ULL, 0x6F83C0A2167B54CFULL, 0x5A2915BBD691C05DULL, 
            0x246A7B173343F09DULL, 0xE850738C6347C92CULL, 0x61937DD5ED20127AULL, 0xA69EE52D938D3549ULL, 
            0x9473025160AEDDADULL, 0xD92DD433C5D13FCEULL, 0xC5DE012B13B3E101ULL, 0x9E1A6357210A371DULL
        },
        {
            0x2F3A54899CAEE124ULL, 0x18C2325F053E87D8ULL, 0x3E9B370FEA348A1EULL, 0x786448518AC69D71ULL, 
            0xFE097D21B05A7F99ULL, 0xE2A2BC54594AC640ULL, 0x903BA1D3F9AC3D5EULL, 0x9A2913EF888E588EULL, 
            0x70D691130EFCE59CULL, 0x70AF50FA8F87CE76ULL, 0x1D98500153604DC2ULL, 0x78C678182BD2FC06ULL, 
            0xE1513C884EC30800ULL, 0x7FBD1F3FFB18361CULL, 0xC91322039E27CF3FULL, 0x97E514A7BA0FE7D2ULL, 
            0xC6DBBC9F88F440F5ULL, 0x59E347444F266606ULL, 0xBCD19DA1FB8C2A0FULL, 0x0626ECA217F16A17ULL, 
            0x7D13445409DD4EFAULL, 0xD7BEAC9909F4C429ULL, 0x68EBAE194475451EULL, 0x9DED99A05C729C5DULL, 
            0xE23C05038B2808AAULL, 0xC21D7138924D7B2EULL, 0x06954D3FFFF782B4ULL, 0xF6341A56611A1BEAULL, 
            0xEF511702F06185DCULL, 0xF05C76F989F52432ULL, 0x546D77B97D767784ULL, 0x0D1A1DCAFCD1682BULL
        },
        {
            0x3E402F12A400B9A0ULL, 0x8AE128C7BB0FD3CEULL, 0x892F888E1D67624DULL, 0xFFD7403796109B81ULL, 
            0xA5FE4111F862E421ULL, 0x8760997D7B9BBA11ULL, 0xEAD9791AF3D8A692ULL, 0x427D31A6D991D920ULL, 
            0xFBD6B89E52F9A57EULL, 0x825759F9A546FDD6ULL, 0xB58D4DC1F7DF1AF4ULL, 0xAB9819C964E5ACA0ULL, 
            0x2D68B1D2105838E7ULL, 0x0AF81103C14C3338ULL, 0xE72C6B75584B26E2ULL, 0xAF9065B2449D3987ULL, 
            0x8D4877D4A9BA1910ULL, 0xBE7D8677F41F4B2BULL, 0x49B05C7C7C22614DULL, 0x9EAEEB2E4F709D62ULL, 
            0x0FBFCCA949644394ULL, 0x0F2D197010F221D9ULL, 0x3963F61A0799A843ULL, 0x8F9480C51E76467BULL, 
            0xAC5A25595A357492ULL, 0x8EA3DE9E3A92A653ULL, 0x2A77E6C022C93631ULL, 0xEF92D5FAF62861B1ULL, 
            0xF78BFABB1A7D1830ULL, 0xC1BA7DC3B9472C49ULL, 0x12522DAA79B7A4CAULL, 0x4D90384F0DD93281ULL
        }
    },
    {
        {
            0x569ABB259E8A3D12ULL, 0xC72378369DBA2461ULL, 0x24AEE5D3D8FC219DULL, 0xF0B92CD4FBFFFFC8ULL, 
            0xED9C7DE508475E4AULL, 0xAD484C8CB8AF8D77ULL, 0x373071B5A72DF3F2ULL, 0x07CC2DE3BF3940A2ULL, 
            0xA8778BE7CDA05405ULL, 0xD83E9E12F0BB2927ULL, 0x34E5C2994A4BAE40ULL, 0xB9F38689107CEF85ULL, 
            0xD468144AEB88AF16ULL, 0xE862B9C105F767CBULL, 0x43EF7EF7A871094AULL, 0x49D9CE407EE4C0C7ULL, 
            0x400F6754E246C71CULL, 0xFBC107915EDADECDULL, 0x3A3297733B678D7FULL, 0x37EDFBF809E0F9DEULL, 
            0x368B401994E07B94ULL, 0x63C5245865844191ULL, 0xA5813BEE54AD32C4ULL, 0x98AA12ABB5DAEFF5ULL, 
            0xDE4E504C47697C99ULL, 0x6FB5C51891113742ULL, 0xAE753220B596B326ULL, 0x94CD39CC028EF3EFULL, 
            0x5AB59D11C048CE4AULL, 0x2083242944EF6C89ULL, 0x94D810BAFA11CCD3ULL, 0x43B18817216A5EACULL
        },
        {
            0xF8554DA3F06E0C3EULL, 0x235AE0CD970A0BF5ULL, 0xC682038F1D92686EULL, 0xFB0B77766BFFACE1ULL, 
            0x02D7AA78AD9AFF51ULL, 0xD790B70072C686BFULL, 0x804A23D2AB0817B1ULL, 0x5FE769113A3ACD99ULL, 
            0x64C189B13B4AF6AAULL, 0xA22EEB24FCA6E61FULL, 0xA147AAC5E0F250EFULL, 0x5B16C3DCB12E9FA8ULL, 
            0xBAA3DC7D7AFB2DABULL, 0x8C188B9A3CE5F487ULL, 0x65BFF947980131E0ULL, 0x0E565415BB00C44FULL, 
            0x7B88B9BDBFD05384ULL, 0x61FD12FBEBF032E4ULL, 0x3E7A7379CF36AB39ULL, 0x5581F46B8E9D507DULL, 
            0xE197FBB06ED91B9AULL, 0x856139D9897DF526ULL, 0xED71838126D02CFAULL, 0x7692676076697D25ULL, 
            0xBF3A1CF918D99463ULL, 0x06A14C8BA542AB1FULL, 0x1B76501529003936ULL, 0x22B3D602B004AEC2ULL, 
            0xC6D917C31F401D0AULL, 0x0E06A8A7CD93D24FULL, 0x2BA1518E6B98977FULL, 0xCBAC9446C9EF3C7EULL
        },
        {
            0xEA1C41B614058F09ULL, 0x3A3D7D267EDDC531ULL, 0x7FF6C7C45E4119E2ULL, 0xBB216448F9D793F9ULL, 
            0xF06E36B04E5EF467ULL, 0xFC4BE0702071DD3CULL, 0x0F825CE6E39DFEEFULL, 0x151E532F2F9BB96EULL, 
            0x1A3AEEA96B5C5418ULL, 0x4B595CA16479F944ULL, 0x5CC908C98927302EULL, 0xEB313DEFF22A1453ULL, 
            0x5D4A6C9687DFD547ULL, 0xEB8AE13766603589ULL, 0xC04B0E8C8B845CD4ULL, 0x002C8672CE289B09ULL, 
            0x4434E0D5E3FDCF93ULL, 0xB64B1F7E0B650AAFULL, 0x95019A9B2E6080F9ULL, 0x8A02F942729F3C81ULL, 
            0xCADC464F7DF8088AULL, 0xAA311446450F2C20ULL, 0x3DE89D5EBFECA2D4ULL, 0x29D2CE1CBA361790ULL, 
            0x705518F240209B48ULL, 0xB30FC95E3C688210ULL, 0xC99710752AE58A1DULL, 0x63A5CFB839651331ULL, 
            0xFF30C758D84E4387ULL, 0x12B432F1731AF01CULL, 0xBB69DA0E50623578ULL, 0x9B2EDE971741E8FAULL
        },
        {
            0xA52EE3353011BE5BULL, 0x4D656FCCDD0B0246ULL, 0x0CE931ADE6F5D8AFULL, 0x7FF7044B7DA616D6ULL, 
            0xCDBAA7F796A640B0ULL, 0x1469C593F2084A4DULL, 0xC56E6B18AC5ABF16ULL, 0xD0B81A3BF9E03934ULL, 
            0xBB07A6AE7116EB75ULL, 0xB811E5F1E49BE5FFULL, 0x9394919A4A60619FULL, 0xA7880BF960FEBB76ULL, 
            0x8D13441AF3FA3599ULL, 0x0F62C70583939490ULL, 0x3D253A3721A8531CULL, 0x0400F41FE93101CFULL, 
            0xCA7EF83315690614ULL, 0x1D4E9DFD624D5934ULL, 0x42173D2089BB686DULL, 0x5FF528306123520CULL, 
            0x2E1940B902ECC30EULL, 0x8CD34CEA94339542ULL, 0xAEA6DBFA2CEC3E84ULL, 0x5F26BB3606A4B448ULL, 
            0x2EE29E2141FCCDDFULL, 0xED7D847E367B1FA7ULL, 0x391EC88280175507ULL, 0x886B298808D45B9EULL, 
            0xB4814F5DDA122E6EULL, 0xA5E52E13FBD72CE4ULL, 0xB1E4446DA30F481EULL, 0xF4CFC223808D38DBULL
        },
        {
            0x2BEAB9D4A4A7379DULL, 0x8ACAC732241DA6B2ULL, 0x244273E9BD50440EULL, 0x4F23CD42412603B6ULL, 
            0x7A28B6E7CB5DF86FULL, 0xFCE83263A1222600ULL, 0x166030BFF7C6573DULL, 0x1027AF7F23D2E339ULL, 
            0x846654808C720E16ULL, 0x86F490D2811D6126ULL, 0x59D40DFEB8ED81EFULL, 0x63D16252B9649F46ULL, 
            0x86CA5622F8585D84ULL, 0x035713FBE75EE98FULL, 0xD9EA97F4E8C48FF4ULL, 0xFF4C7CCFB6F7E9F2ULL, 
            0x6AA6D7E1BA5F7236ULL, 0x42D475B39BC1BC26ULL, 0xA3B6C118367EC876ULL, 0x926943CD35DD6F13ULL, 
            0xF7EF98B8CFA52A8EULL, 0x94F30C08984F7BFBULL, 0x40AA218B82F78A66ULL, 0xF1A679E219E90D96ULL, 
            0x954677534A072AD1ULL, 0x40860C664BF7943BULL, 0xE413DFD485820B46ULL, 0xEE255BBEB29BABF0ULL, 
            0x2357A9F2C7205A56ULL, 0xDB7D038D899B3DE2ULL, 0x014653E816FF9899ULL, 0x6607D16BD11D964AULL
        },
        {
            0x81F373B2A48B67DAULL, 0xDBD5356A5DA07EA1ULL, 0x1501878D9CEEE808ULL, 0x3F4347428642AB48ULL, 
            0x98675EF09CFED43BULL, 0x4F19EF83AA98CE7DULL, 0xF46EF0A74369DB02ULL, 0x0B1CF8A82B750565ULL, 
            0x314580AB09150D7AULL, 0x3F9F60148AB25D0CULL, 0x039BE61546CB72B9ULL, 0xCA8803840F5D634EULL, 
            0x771C4B36ECC3E670ULL, 0xBAEECFE0715517F7ULL, 0xD3F580A00602FD91ULL, 0xAEC139CB2C56E655ULL, 
            0x02A4812B45FF2CE2ULL, 0xA0AE3B0BF332DCAEULL, 0x127B0884D07ABC65ULL, 0xA52304AD955C03BEULL, 
            0x063C2D772DD9DEBEULL, 0x5281154BA890DED3ULL, 0x072269B91EDC3FA1ULL, 0xB4B822C3856D8514ULL, 
            0x5556490D66CCA901ULL, 0x39AA038DAB76AA61ULL, 0xB32568ACD518962EULL, 0x8760DC85241B45B0ULL, 
            0x3715A60DE70EAFF1ULL, 0x6C93AF3C84B7A708ULL, 0xDE4919EAB92619B0ULL, 0xA90903C059642C75ULL
        }
    },
    {
        {
            0x9E758C6A44446498ULL, 0x19FCB2FA5E3C87AEULL, 0x5308FD8CE6C70BCDULL, 0x5C82580771D4F9F5ULL, 
            0x839B29CBE1CDA181ULL, 0xA5BB7154D7E4A36EULL, 0x7AEFC58EAFAA3DAFULL, 0x67159FA7D64BC8B2ULL, 
            0x9670744CFABF5FF0ULL, 0x92E93DC00C0FD472ULL, 0x8824DC6FDD327A2EULL, 0x9B1F9C1CDC838536ULL, 
            0x89C1346EBB032C15ULL, 0xE9BFB33D3C2B6C43ULL, 0xB240FE28682FED5FULL, 0xA8B6AC2871AC7774ULL, 
            0x5EFCE885994DF8FFULL, 0xB88040154D0DF7F8ULL, 0x4BBA9B88A18EECDEULL, 0x3FA42144068688FBULL, 
            0xAB055B7E83A8996FULL, 0x999AFDB143ED7DF8ULL, 0x8F91D8EF257E810AULL, 0x05976A64205E41CAULL, 
            0xEA81EC94B0B0A8A0ULL, 0x7F5C963013FF257BULL, 0xCCEAAA69908A2371ULL, 0x56BBB8F0980319E0ULL, 
            0x896F74BE410EABEEULL, 0xC774989672CE1BB7ULL, 0x3D704626003D79FEULL, 0xFDB1B9B28D51C8D2ULL
        },
        {
            0xBCC0B9C8A33D8798ULL, 0xB490DCAF416AAB8BULL, 0x32313A28AD0262BCULL, 0x94C5EBA03D824AD8ULL, 
            0xD4C00FD30278E30EULL, 0xC5B211A38298521FULL, 0xC9FEB6494EF58110ULL, 0x0371BC79D6F44CEBULL, 
            0x0D918D5DAC685B95ULL, 0x318162B1FC5BAC36ULL, 0x6505CD6EF47FFA45ULL, 0x20612B47F7299707ULL, 
            0xA7272C349D34BD6CULL, 0xFDBE069A0765FCD9ULL, 0x928EB7C0E3E419E9ULL, 0x5B77A7D829B27B3DULL, 
            0x0F47F5DBE501F266ULL, 0xE7153D40A9F25B88ULL, 0x653AE36FB94B8C5FULL, 0xA7B803BA70E001E0ULL, 
            0x3F71EF9E60C6F5B8ULL, 0x2D7178C038D14A73ULL, 0x0CD3DF5643E02853ULL, 0xFE96EA0D4615FDFFULL, 
            0x7911998E13B57252ULL, 0x0BC0DD33462F4E2CULL, 0x1EF090BE5154A5CAULL, 0xED40BCCB70437A9AULL, 
            0x607D93F1048A687DULL, 0x15A4508876E50B23ULL, 0xF9EEE87C62D92CD3ULL, 0xD5A3DFB10C68B8AAULL
        },
        {
            0x2730C9146632A44EULL, 0x8678621E299A26D5ULL, 0x2D5D161C76291FC3ULL, 0xDF825FEB7724781AULL, 
            0xC71CB4CAAAAF6852ULL, 0x131767855963A72EULL, 0xB57006CD1FF69B95ULL, 0x1ADBC80D48977486ULL, 
            0xEAEEAE0DEF89820DULL, 0xAEAF4B3E016A2070ULL, 0xB13A7BBAAAE96021ULL, 0x72B73DB51F57E259ULL, 
            0xC299ACB9C80E5B3BULL, 0x444A564785479570ULL, 0x19E43B93A08D0826ULL, 0xE5BDCFA486AC0B6AULL, 
            0x44E54CEEC2F70F3FULL, 0x2D9A8473B6A6CD32ULL, 0x0A540A049385BB15ULL, 0x804084F01CE0F9C3ULL, 
            0xDB4807C82825D69DULL, 0xDED45EE537996439ULL, 0xFEB9D1DCD5D0330AULL, 0x633398C1EEFBF164ULL, 
            0xB98AACBE90EA1E3BULL, 0x06B2518D45CD97F0ULL, 0xABE21927E76D903CULL, 0x10EE14D849358CA1ULL, 
            0x82C30325590EE2FCULL, 0x36E1820D6E456990ULL, 0x9B3FE38EBFAFA36BULL, 0x2C1C088EEA67D2D5ULL
        },
        {
            0x24F3C6FE143CDD0CULL, 0xAEFB7A9FBEE86BC9ULL, 0x949DECEE5202917EULL, 0xA04E3B0DB2544967ULL, 
            0xA2979BE7AD833969ULL, 0x74330932BC6382C6ULL, 0x2AA384609D4E31CAULL, 0x0A560A7303648604ULL, 
            0x9485F85740ABF51CULL, 0x64C4E219BF540109ULL, 0x025469D063A623BCULL, 0x44A2009D222B9760ULL, 
            0xDE4CF1BD726F34A9ULL, 0x0B84F4875C2BF65AULL, 0x00BF3105889478B4ULL, 0x9A50301C145ABAB1ULL, 
            0xA4CEBB5CE4DC9DE6ULL, 0x6BA12C663E851F02ULL, 0x2299490F064035AFULL, 0x7155EB0A537BF3FFULL, 
            0x2F379E7BCC5EDEAFULL, 0x665699B7B99F36B3ULL, 0xCB797C255E7E7281ULL, 0x27A0F49229F4CDBEULL, 
            0x2851665418C51EA4ULL, 0xADB5C1C16A74CC61ULL, 0x11217E883CEBF027ULL, 0x5431C4CC2AFD6070ULL, 
            0x9637E1F9F8DC5D93ULL, 0x1C5AB0F639E355B6ULL, 0x7F1AAE3CBA38CDB4ULL, 0x5FE0CB61B28692BFULL
        },
        {
            0x1BBDE38811A502E7ULL, 0xBE541ACA7AE6C973ULL, 0xA250B736730DEA97ULL, 0x85A68FCE8CE13CF9ULL, 
            0xE60A844599C6EE4FULL, 0xC6A0943B0284F974ULL, 0xCD4FEB6672321917ULL, 0x5C4DF445F2DD7ECAULL, 
            0x2D9A458087DF1E75ULL, 0xB42C63E96EBE2DA6ULL, 0x8CCE8F18A48D3644ULL, 0xA99C3423056D2520ULL, 
            0x8D360BD3104F57FDULL, 0xC8C963FE9CC4CF09ULL, 0x0FC90F4F790A37A6ULL, 0x6FEE1E74DAEACFFCULL, 
            0x2263E52062E35C4DULL, 0x423461DF942C8AC7ULL, 0x324486782DC0FCB6ULL, 0xCF231FB93100450EULL, 
            0x57CFDBC8D072A346ULL, 0x48705D5746B44D45ULL, 0x160D5C36289D71C3ULL, 0x54CCF6296B84D37CULL, 
            0x8CD6F168614F5BB3ULL, 0x38EB26ED976CE1E2ULL, 0x6B801F466D35DAB6ULL, 0x28EC9CBB53CE2F2CULL, 
            0xC62DB0548EC98D0CULL, 0xAA6ED5A6104F98AFULL, 0xDF09F095C67A3DE4ULL, 0x29DF2D8FEF60D322ULL
        },
        {
            0x7A7DD71274ED05FEULL, 0x41D049FD2AB40397ULL, 0x2DAF9FDE5544DE64ULL, 0x5D11DFE2F3A35481ULL, 
            0xB1CC2006EAA855FDULL, 0xC3E17009E36A28FAULL, 0x74AFC251D0AD5A2DULL, 0x582932220BC94476ULL, 
            0x0DD6544F2A8EC855ULL, 0x60E830600AB6E98FULL, 0x79C0108C5D59785BULL, 0xBEE157782459A059ULL, 
            0x2A958A9869E0F813ULL, 0xEDACB9222519359CULL, 0x7485617BB478F40DULL, 0xF1AD615EDF357DD1ULL, 
            0xEAE411A15F7D00BBULL, 0x1312C98E75CFF515ULL, 0xA286DC35840C00A5ULL, 0xB36544A5F143B2F3ULL, 
            0x7D40412E564558F1ULL, 0x8A3F189A902E00AFULL, 0x8C6934582DBFBACBULL, 0xFFB6E3E9DC886646ULL, 
            0x5A1958C246CBFC29ULL, 0xFD36AA0EF62F621DULL, 0x39252B491B5B909AULL, 0xBD2F23317D28FB7FULL, 
            0x426C55C376F579C1ULL, 0x50EC89C3385CDB96ULL, 0x9FF158E96A63F029ULL, 0x24FE6C7574DB81E7ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Pollux::kPhaseAConstants = {
    0xE790AC9ECE73134BULL,
    0x68C5888FFBEAAF88ULL,
    0x972B7A3E6C151B07ULL,
    0xE790AC9ECE73134BULL,
    0x68C5888FFBEAAF88ULL,
    0x972B7A3E6C151B07ULL,
    0x124AA2C10EC5EF78ULL,
    0x57D6DAE58EF0FA6FULL,
    0xE0,
    0x7E,
    0x7D,
    0x05,
    0x3A,
    0x14,
    0x0D,
    0x07
};

const TwistDomainSaltSet TwistExpander_Pollux::kPhaseBSalts = {
    {
        {
            0x049AB77D61F23485ULL, 0x8416F341D9365918ULL, 0x6ED901D8C09774AEULL, 0xC124890426F982E0ULL, 
            0x266775A4D87DA7E4ULL, 0xFA2FAF07A158A464ULL, 0x2EFBAFED224DFC45ULL, 0x1A16A1C0677EEBF0ULL, 
            0xB65CD429798A4811ULL, 0xEA5009B9901BB107ULL, 0xD90AC4574F033BF8ULL, 0x76E9B976EDD4DD75ULL, 
            0x4362F027C1B1DA01ULL, 0x06E919E3B9C354B4ULL, 0x3A0719ECB8272225ULL, 0x85E8EE28050EDD31ULL, 
            0x7F6B2443D971F0AAULL, 0x84FBB63940AF330BULL, 0x3290C7F9FC48A24CULL, 0xFD28D0325BD7A75EULL, 
            0x16F0581ED3DB5FC2ULL, 0x2D9B78E3321FA11DULL, 0x939058BCCC7FCBF4ULL, 0xB3E0B86EC1FE01CAULL, 
            0x48EBFEA972435B45ULL, 0x66D60DB31EC52DE8ULL, 0x0D6AEA45CDCAAF4BULL, 0x8B197A3C4E092BC2ULL, 
            0xA8505ED9BD9E7C5CULL, 0x3D6C9D16672EF15CULL, 0x79B496A60C9F309AULL, 0x2B356C3D7F0FE89FULL
        },
        {
            0x1AE5B89D833CD29AULL, 0xEA19D0AA9A728900ULL, 0xB10AAC2DA70ECB95ULL, 0x78F00D9F51B38808ULL, 
            0xDCCC8574EE731AE3ULL, 0x8AACFFD0B05BEA79ULL, 0x695DCB180FBE850CULL, 0xFD633DF8413B99DBULL, 
            0x1DC1F6062DF23C11ULL, 0xF9697048C2DAF7A4ULL, 0xD018F1BB2C3232C7ULL, 0x923133380ACC52C8ULL, 
            0x92D1B8191F0EDBA2ULL, 0x64B4CBD4DE964153ULL, 0xAB27B5A59BD67F85ULL, 0x9B685B5034AB7A26ULL, 
            0xF0B752582CE9267AULL, 0xE923418EE972F949ULL, 0x22EE01EA114F10EDULL, 0xC8240BA46DCF006CULL, 
            0xD9ADE63D36DBC5AEULL, 0x2F5E2F13F50DF22CULL, 0x0A204F945E4CC507ULL, 0x2AD17FF7FF3BBBD2ULL, 
            0xADABF0E65D88CCC0ULL, 0xB1925B4CD726E842ULL, 0x02B65C891FC99F85ULL, 0xBBC93D8819C29FF9ULL, 
            0xD76836216F92EDF1ULL, 0x4963C8246481C313ULL, 0x47F764ADE1B12B62ULL, 0x902EA6C80F56163DULL
        },
        {
            0xF923624A9E5D4E06ULL, 0x57BD85BED1AF903CULL, 0xEB631BC4B7F48330ULL, 0x79ECABAC654C15EEULL, 
            0x1EE5C5B6BF341EDFULL, 0xFD9E43B806C3C7E1ULL, 0x9FAB2C52AA4E028DULL, 0x7271F111027CF88BULL, 
            0xF09385A0E197011EULL, 0x252879EB7B052088ULL, 0x5E3296819EEBA76EULL, 0x66B58B637EEDCDABULL, 
            0x02C254DCDC65118FULL, 0x438CE0212BC655B9ULL, 0x44A565F03D02AEC4ULL, 0x0220B0A9BF93BFF4ULL, 
            0x3B2AF889AFCE588FULL, 0xB7BF23261B3A51F2ULL, 0x3C5F061E37EACFB6ULL, 0x85BC84A76811B2C8ULL, 
            0xAB344694C0305951ULL, 0x8C46E72639F0DA8AULL, 0xEC3F1E43AAF43414ULL, 0xE9BA322D5C8509C0ULL, 
            0xC0EEBD20053E7786ULL, 0x9DD0B94F936E9E2EULL, 0x35B20FDC900CE5E3ULL, 0x9C0B56DDC31666AAULL, 
            0x324E518836CD2FFEULL, 0x5A3678D5A85DAE08ULL, 0x650C2AAD5D19082CULL, 0x185AE95C83E182A2ULL
        },
        {
            0x9B02330CDC726FDBULL, 0x7874354B33DA34C6ULL, 0x7D2B44CAB0551FE5ULL, 0x87C208A40000F85AULL, 
            0xC58E401232B32095ULL, 0x765AC8ED82D7E390ULL, 0x7A763CA695947A46ULL, 0xC1E4C0D432A1AAF3ULL, 
            0x6057941909A7CD70ULL, 0x5BB94E07F546A8B7ULL, 0xF8FF1BD711B63F4FULL, 0xF420E035C35EA92EULL, 
            0x91CDBFFD1E678A70ULL, 0xB7A04606FA88DAF2ULL, 0x839D384C702696A1ULL, 0x96189D88710FC003ULL, 
            0x2EC1E66127B31090ULL, 0x4DEA37F8C179F47BULL, 0xDEA2B2D0FD86D061ULL, 0x9A109CD45DE7D24BULL, 
            0x4164D3CE002D27D0ULL, 0x1C07403598C43463ULL, 0x6F907E6DBF123F9FULL, 0x4D2C18753AFE44F5ULL, 
            0x13BFD8D0DE62840BULL, 0x6A122DF9A6EC6C08ULL, 0xBB4DA38EF993EF67ULL, 0x869664E055005721ULL, 
            0x91E0294C4DCAB0E9ULL, 0x62A65D451C7B2893ULL, 0x30C13104E3D33FC9ULL, 0xBF60A80C7C9FE964ULL
        },
        {
            0xB33B24E3CECFAAAAULL, 0x40E119C8B2CEEF0FULL, 0x2E76A0DAF29E252EULL, 0xCCFA3F9966A0E6CFULL, 
            0x9D7B1E156FF91225ULL, 0xA29D283496AE4D95ULL, 0x9789DF41324A1BDEULL, 0xB5BD3A501B4BDFF2ULL, 
            0xD442F5C40905D568ULL, 0x9E8777BF7501EE78ULL, 0x7C9F61E94DBBFC1CULL, 0x4883244E65DA3C83ULL, 
            0x3E5EC3376001779CULL, 0xB4C5B83E25807EFDULL, 0x48F395E133A6DCC1ULL, 0xDF403D8E9A20BBDCULL, 
            0x07A3B7BE291E835AULL, 0x6D7778A064BE8593ULL, 0xCFFBA540014FBE99ULL, 0x02EC81719ECD579AULL, 
            0xE015D0845E8D0A78ULL, 0xC58ABF2D735624E6ULL, 0xCF1A00762B2AA4F9ULL, 0x43C3A9341604AEFFULL, 
            0xA8F52FD66337139AULL, 0xA3F254300E07FC88ULL, 0x5BE639D0DE1003E7ULL, 0x218EC42D5278C5A4ULL, 
            0x3069EDCD04FB1D47ULL, 0x08675940A9ADF860ULL, 0x9657D061AC1BDD39ULL, 0xD4430E730A63CF6DULL
        },
        {
            0xC4E93A26EAC4FDCEULL, 0x8FDC258FA3D7F238ULL, 0x9BFFAD6368627689ULL, 0x37E410911F86A5F1ULL, 
            0x04F774BE9B036EEFULL, 0xE641C0324285BB7BULL, 0xBB79844E68E94668ULL, 0x4DB78841B3FEF7A8ULL, 
            0x868ABC8FEAD97D2EULL, 0x6C6221EFBA67F567ULL, 0x8EF0020767298891ULL, 0x84F63E7CF13E9BB5ULL, 
            0x628A5142E282A147ULL, 0x37C672889077FEC5ULL, 0x2969BF0690392662ULL, 0x7612D4541C014152ULL, 
            0x330617FEC383B1AEULL, 0xECAAFD0C153C8091ULL, 0x82B535B6A73E038FULL, 0xEABFC0A2EF8C9022ULL, 
            0x26AC73A751C67FEBULL, 0x733CA116026A5384ULL, 0x8F888C92BD9F693CULL, 0x9DF0E5EB09D32FF0ULL, 
            0x87202B1B0CFB2694ULL, 0x41CFCD171DD7C020ULL, 0x57D7AF663F985918ULL, 0x23B858217C53A8EDULL, 
            0x211D21D06526052CULL, 0x6533FFF99797BF75ULL, 0xDD29AC2620C6CC2CULL, 0x4BDC0E6E912B8EDBULL
        }
    },
    {
        {
            0x3E415E7ED6B83441ULL, 0x79706062773D945DULL, 0xE48A65DE63AD0031ULL, 0xDF28496164AEEAF3ULL, 
            0xE8876C0D15F690C8ULL, 0x96849AEAB3910B3FULL, 0xBF64E619648F80CAULL, 0xAD9CE60E7D13764AULL, 
            0x62C5D3B4668B249EULL, 0x37D080A24A1555CEULL, 0x8FD50FD2DD95D77AULL, 0xF0B3F6E700F7EFB6ULL, 
            0x799F076E4BB2CFA6ULL, 0xACB75B3471EE6C64ULL, 0x7671CFBAC8A62DE1ULL, 0x03D3282AFEA396BEULL, 
            0x87788BB82006796BULL, 0x4D8DB1023740D168ULL, 0x105151B7ED2DBE39ULL, 0x320D2A154B202FA7ULL, 
            0xABD5B6F561424445ULL, 0x66C059093F5315ADULL, 0x90BD7EC86C4BB617ULL, 0x7AA372015664BFCFULL, 
            0xEE74CE14CE6E286FULL, 0x1962D0FF308AF446ULL, 0xE1F0C2A426E43118ULL, 0xF58AD33DE763EBD3ULL, 
            0x23017AB1C39DFDE6ULL, 0x530377B457BDB5E0ULL, 0x6FF9714265A453BDULL, 0x8385B3A3E894D25CULL
        },
        {
            0x58B7CC2B798E1C67ULL, 0x520461F82850C6F3ULL, 0xA3CA60CEED14614FULL, 0xFF2910F493A45347ULL, 
            0x760CEBEC5C1DF2A2ULL, 0xA7AB261E837DD81AULL, 0x01523B783D66DF06ULL, 0x5142B6C6390661F0ULL, 
            0x5F5D534BAB1CE1E4ULL, 0x141EF176DF8FB6B3ULL, 0xC170992625AF5A57ULL, 0x04863844DE903965ULL, 
            0xD3F6690692E7DD4CULL, 0xE5B8EDDB3B5BA7FBULL, 0x689BA400159AFC93ULL, 0x76150C1DB3342465ULL, 
            0x49570258951DEA08ULL, 0x1CF337B26D53894EULL, 0x1542D90F23027A2EULL, 0x812EAA6253D1199FULL, 
            0x48BEE88D5C209115ULL, 0x673DB86DBF25BF2BULL, 0x87D84D38B8200F11ULL, 0xF59FEDB1730A15CBULL, 
            0x5EDC73B5CD7C5ECEULL, 0x59375F5C4DDB6FE6ULL, 0xF5685A83318849B3ULL, 0x896474E70BBBA310ULL, 
            0xE0446B7A4113C2FDULL, 0x32A954CF0BADBFECULL, 0xDF54CDA457A5E08EULL, 0xF20CE72AEFEA2AB9ULL
        },
        {
            0x7FDAE55B971D2127ULL, 0x6A91613F89B48CDFULL, 0xD815851446946C0DULL, 0xFD5D06C567930512ULL, 
            0xB7D29CBC555F2D3AULL, 0x4EDCB28A7F583EE7ULL, 0xCFD2978245AB9E95ULL, 0xD8CCFDBC34F6F304ULL, 
            0xA61B8C193BA34438ULL, 0xBE883A67BC5FD98DULL, 0x796C6FEB531FC078ULL, 0x991834134F3ABBADULL, 
            0xFD89DF8168457C17ULL, 0x0493D2EAE9FB1566ULL, 0xC56AB73DDD0DA5AFULL, 0x4A44649C85CA324BULL, 
            0xC6BD186AB14AD2B1ULL, 0x37B2F8D6D110FF4EULL, 0xBFA0CB65A35ECF4CULL, 0x3E853EE14D34E1D3ULL, 
            0xA0C41D7EF40128E6ULL, 0x9FCE602E3D739A8EULL, 0x281FE81E86CE93B7ULL, 0x40721AC9BBC23E42ULL, 
            0x857D5EAE5ED57305ULL, 0x6B2F2E4EDC8C1693ULL, 0x7700C5611B6BF49CULL, 0xC46189C77CD89E06ULL, 
            0x7A95EB3F425C6693ULL, 0x7852210566828DDAULL, 0x0C8BAE3A6EC73558ULL, 0x41C5F9F663564389ULL
        },
        {
            0x1F809DF3BA91693FULL, 0xD2BD3E8D26A6203FULL, 0xB3C59A29F54352BCULL, 0x814DB73FC1783F4DULL, 
            0x9C8CE57E89B326C9ULL, 0xE30B63D2021B60F6ULL, 0xBDF425AD64D75354ULL, 0xF877D81227CD44E2ULL, 
            0x8913243DF1EE7380ULL, 0x4C492501D74599BDULL, 0x4949E8C4F822859AULL, 0xA011D979A2539CA4ULL, 
            0x438F0B6ACA0A5399ULL, 0x3C630496EAB4E23DULL, 0xB34F9CAC2F2D0049ULL, 0xCF0D7DC30A0F18B3ULL, 
            0x5671A5ADE77C5F64ULL, 0x66741F37AEB175CCULL, 0x260E98A19F8C2B5FULL, 0x6441B65299855716ULL, 
            0xB37951F869832F98ULL, 0x33D3A7863D06E043ULL, 0x588B8E5EEF7083DAULL, 0x01EC0AFA624C8685ULL, 
            0x8C1EF48FF74E9638ULL, 0xC7D576975C00281BULL, 0xBEFF3F3A4D2EB1CFULL, 0xF1ADF0531A2D6EFAULL, 
            0x48347C6B81A9D714ULL, 0x145E511E019A8FE5ULL, 0xB771B2FCE35CE8E7ULL, 0xAC798D48F233E534ULL
        },
        {
            0x04BA85D882AD8F72ULL, 0x3D79F36884046D6AULL, 0xA2CF296064802FC2ULL, 0x3264FC95F79409ECULL, 
            0xAE8CF752C2AEB801ULL, 0xDC93E9D79D5DE606ULL, 0x52AAF11A96952441ULL, 0x4D131FBD9A4F3AA5ULL, 
            0x39C545FA3C7E0EB6ULL, 0xEC125BD9FC6E6AEFULL, 0x25B2A3758A5C4382ULL, 0x8EF15F506618C7BBULL, 
            0xF562E62BE3A11D08ULL, 0xD139F41727E0132DULL, 0x2CAC8A80AB0214E1ULL, 0x08637D5EF3F43A7AULL, 
            0x49BC521A917B655FULL, 0x4D1A86783E9E964BULL, 0x91482C08E6A43031ULL, 0xF3CFBF4461288765ULL, 
            0xF838756B86DC5682ULL, 0x2FF44E5D3D643FEDULL, 0x383F495F58D83148ULL, 0xFC6B9BE417438920ULL, 
            0xDC8E2B0E188FAF37ULL, 0xFEF530721376678CULL, 0x30C68563B7603E05ULL, 0xFC6319E83A427F0EULL, 
            0x9D7076E2F5BEB48FULL, 0x45E41429E2974740ULL, 0x681B84CA5DE31EBCULL, 0xA66D71D636E0AF37ULL
        },
        {
            0x4FDACC5DD8CE24B0ULL, 0xE9E0A34FFC8263F3ULL, 0xC3DBC1FD8E31389EULL, 0x71C8FAF5CA05E835ULL, 
            0x510CB8D2D25A4658ULL, 0x3C1E40DC1B7ACAA9ULL, 0x424C602528B2470DULL, 0x12871191511FFC71ULL, 
            0xE94FD749A6E0450DULL, 0x19A6C55DC944B563ULL, 0x56388011B26B3F0AULL, 0xAF76F430FACE3198ULL, 
            0x3FEACFBFBF0DC533ULL, 0xE1AC03D55483AD06ULL, 0xAC0D53FB0CB4952EULL, 0xEBAEEDAF2416E187ULL, 
            0x0C389EA99B568991ULL, 0x89B7B09327A3769CULL, 0x91FD5AB0175B2A89ULL, 0x4136826FB26E903CULL, 
            0xA528ADB6D12BB9E5ULL, 0x698471EF4A1A2136ULL, 0x0001C676C2B3F1A3ULL, 0x204A2539D7EC3054ULL, 
            0xA3850D934D4B6BBCULL, 0xFE0E5AEA34CBB8A8ULL, 0x9C73B01968AFA5B6ULL, 0xA416FB8BFDB6E773ULL, 
            0xC8400A68AFB2B288ULL, 0x78F30AA22C490C8CULL, 0xC3C34836165BC8CAULL, 0xA90E72D1968A8413ULL
        }
    },
    {
        {
            0xEAD486E198437ADFULL, 0x711BA755E4D3C6CEULL, 0x35391D1C0CFE451AULL, 0x70C63C194DB63238ULL, 
            0x4DCE1AE88DD6881AULL, 0x489A53BAC3ACCAEFULL, 0xB58CD05A3A189606ULL, 0x0D51F8BC39C939BDULL, 
            0x1CB309D644BC54A4ULL, 0xF4894D1BD1A464C0ULL, 0x17D74E1E5ED1F6EAULL, 0xE611B2E65722F8B8ULL, 
            0x85BC6DB029BFBFC0ULL, 0x62DD2DED0F63C331ULL, 0x2CBACC6E03BCE7B8ULL, 0xCC4EB9169A8E1954ULL, 
            0x1798B34661DA7443ULL, 0x9E096EB8B91F1C0CULL, 0x15C1434875A6F9BBULL, 0x37ED03BA31734A1FULL, 
            0xC3F13E6696883C51ULL, 0x59E3FF201D52A22EULL, 0x242BDCFC3EBE30C6ULL, 0x46F30A4AF3D30BE1ULL, 
            0x60B17283CC8C1874ULL, 0x6805DED9F382DBD5ULL, 0x3DD1895E474C98EFULL, 0xBEAE434D146E5F4FULL, 
            0xF8D24F1A4EE0A8C5ULL, 0xAEF715E886455EDDULL, 0xAAEEC32C074D130EULL, 0x5A5CCF714A18BC27ULL
        },
        {
            0xF82D0AE933B8F991ULL, 0xC038C344053C2C9AULL, 0x20ECED32D00FE76FULL, 0x6D648CEDFA55DB05ULL, 
            0xBB5FC1F4287B5F5AULL, 0x19DF21810C208817ULL, 0x32D93C10BFC3C426ULL, 0x9D65A67FF4E1D4E3ULL, 
            0x3546C1FE96488B05ULL, 0xF2EA476272687F4FULL, 0xCEBB4CEBAF45AFBAULL, 0x487295FF56DE74A9ULL, 
            0xC950C0CFD75C69CAULL, 0xD8639BB709DE6285ULL, 0x075180F7CCF1087CULL, 0xD950DD09538FF5D9ULL, 
            0xC0011D25F14B20AAULL, 0xABAB6541C1DD4C8FULL, 0x6B1E9FD507CC1C99ULL, 0x78967ED6C92956F5ULL, 
            0x31B6267F5C1F42CFULL, 0x5E6914AD450E5876ULL, 0x4ED5957AD1A66144ULL, 0x4693797E6F8491E9ULL, 
            0x166817E8548E44EDULL, 0xBF0C36895699B5DAULL, 0x9560BB2CFF2BD741ULL, 0xE15F5E790279E012ULL, 
            0x2FE52876F410BDF8ULL, 0xC87B5E3628DB7EF6ULL, 0xCF9B0085FA5AA9C2ULL, 0x789602C3776E46FAULL
        },
        {
            0x9C52206858A4D8AFULL, 0x9C115C8637E1E066ULL, 0x1DDE0872CE5C6F66ULL, 0x10D0C608342EBE65ULL, 
            0x6A9B3E1C96BDB00BULL, 0x0F65237ABC6A84EAULL, 0xE966BAB9C9365262ULL, 0x4862535999A7D551ULL, 
            0x747EDF8A0D2425C9ULL, 0x17D472B770CC4809ULL, 0x3DA57DDF51B25B19ULL, 0x932A60D9335D2B19ULL, 
            0x7882F5B0038CB506ULL, 0x32B20002D611D653ULL, 0x3A997A38B56A8EE3ULL, 0xFD5B1979116AF883ULL, 
            0x1A4F144FE196CE9EULL, 0xD2421E586DB5AC76ULL, 0x98C0ADAFACF3C39EULL, 0x74B769E72C812607ULL, 
            0xB23C33596BAC6131ULL, 0xD8F11D6BA05D542AULL, 0xCB756032BA8FBBD3ULL, 0x58B08A761A4EE3AAULL, 
            0x4BC44FFDA0C803BDULL, 0x78B8A9036591111EULL, 0x3BFA67A30D7167BDULL, 0x9B07681B5EDBA9C4ULL, 
            0x39069F45FAF30F4AULL, 0x4DBFE9AFAFA7A1C5ULL, 0x2326FFE818EBD3FAULL, 0x193760CEFE1B3F13ULL
        },
        {
            0x9826ECA117BF4607ULL, 0x3CE2D3CC1BF4DF9DULL, 0x63B83307EF5BC6D9ULL, 0x01B56F345C8669DCULL, 
            0x383BB0A171E745F5ULL, 0xD684812C4A758769ULL, 0xEC8BD7C7FEE672BDULL, 0x3103E0E71B4B618FULL, 
            0xAE8CBF2A19EB6838ULL, 0xE438DC4D2F8E4103ULL, 0x013609291161C670ULL, 0x7957B60D4FECC932ULL, 
            0x34D6422407F5200EULL, 0xA449DFE666CF5E3AULL, 0xF74F7B995D557306ULL, 0x844FEDE44CE8A022ULL, 
            0xFEB81DE3A645189CULL, 0x1628E4C484BF87C4ULL, 0xFDFB5111D2F14E99ULL, 0x734E7C9B7A631954ULL, 
            0xD14555CFCFDE71FFULL, 0x181E67E4EEE98479ULL, 0x24E0B16522163535ULL, 0x952357CA6989B191ULL, 
            0x5F37B880E50958C5ULL, 0x27988A666150D234ULL, 0xECE0169C96BFC5DAULL, 0x69E93EA3717D3655ULL, 
            0x43D92CBA7DA3E4F2ULL, 0x858A14AD5D98CE6EULL, 0xE00D6B5703A611FCULL, 0xC6C1C83788CE45E5ULL
        },
        {
            0xFC8FAEFEE346926CULL, 0x79B8B553916A040AULL, 0xB516FB4A031B5F8EULL, 0x598F726C7A5ED2B9ULL, 
            0x86310FEAE6BC89ABULL, 0xEE8587A0A7A0235EULL, 0xAE78B5A51855FD40ULL, 0xD53CF3EE1CC042C4ULL, 
            0xACA006E980DCD639ULL, 0x344F12DFBC88AF4FULL, 0xE36FBE9E31CF2ADAULL, 0x999E7C0E2B4007C7ULL, 
            0xAC8CA89B69EDCFE7ULL, 0x095D1F183623E25CULL, 0x8E98F664CE830EB8ULL, 0xA4BB39CB10108324ULL, 
            0x7D37F8901CBCEBBFULL, 0xCC2F75654BF6C6E6ULL, 0xE906F36F79498C01ULL, 0x1BA4F9AAD2F7A712ULL, 
            0xCEA34EC2D2214F7EULL, 0x95F7375AD0F6B4BBULL, 0x8FF9E39DEB3D1DF0ULL, 0x8A6E3416EE80A461ULL, 
            0xA6A3814CC8CFF60DULL, 0x21E0D4FC98BCCECEULL, 0x9EBC38B29C3C5701ULL, 0x36EBA6F841B3F104ULL, 
            0x6C2027A553F71A2CULL, 0x8887B2C9C319D874ULL, 0x07C331D422AE72C3ULL, 0x5105D5ABC6D1BF78ULL
        },
        {
            0x7E48AFC4CC776599ULL, 0xF5A2D1A8E2447C4FULL, 0xF24A1592A381C1D4ULL, 0x73EC06DCAC62136DULL, 
            0x832E28619F49A397ULL, 0xD884AA888F788C0CULL, 0xADD9606F14C00FFCULL, 0xE062E0B2712F0904ULL, 
            0x38C389B79DD0FDADULL, 0x9E5434D95393CDA7ULL, 0x8FA6642081C4CBE1ULL, 0x4FD97E4787975AEDULL, 
            0x7BAB1030E992FDD4ULL, 0x40D498E44094BFDEULL, 0x61FF8AAB87AF81CFULL, 0xB26E77ACE44D78CAULL, 
            0x1AEA01EEC22A88F6ULL, 0xBBD7574A8C88C445ULL, 0xF4A178059A34CE19ULL, 0x0EA215A80A9F0BBDULL, 
            0x8E71F49F9B8BFD46ULL, 0x581D14DF792E3DE1ULL, 0x263A6ECD14BBF321ULL, 0x36B64038C78D1B9BULL, 
            0x758B18E6D9A31491ULL, 0x1C47CEB053D268ABULL, 0x5B8FC94A3AA4079CULL, 0x3B2ACEEFC230F2D5ULL, 
            0x224F1BC852723AC0ULL, 0x87F9BB51759943D5ULL, 0x616BBB08DAB67467ULL, 0xEF7CF31052E54AFCULL
        }
    }
};

const TwistDomainConstants TwistExpander_Pollux::kPhaseBConstants = {
    0x85EFBFCC4E6483ECULL,
    0xEB5D8EA75F8320A5ULL,
    0x9BCCE184AB5704D6ULL,
    0x85EFBFCC4E6483ECULL,
    0xEB5D8EA75F8320A5ULL,
    0x9BCCE184AB5704D6ULL,
    0xABA9457EBFAF3AD2ULL,
    0x668218C25F9512D6ULL,
    0xEC,
    0xA7,
    0x4F,
    0xDE,
    0xCB,
    0xFC,
    0x99,
    0x1C
};

const TwistDomainSaltSet TwistExpander_Pollux::kPhaseCSalts = {
    {
        {
            0x1BDCED0390B1B589ULL, 0xB3198ED5E6BD79BAULL, 0x5C2B7D68DF96DA46ULL, 0x5FA1094551F09B3BULL, 
            0x52078C38E8C13F54ULL, 0xACB5ADC046DB4EF3ULL, 0x04017B790690B6C5ULL, 0x6CB728E1B7F7F2C5ULL, 
            0xDA14B2E530A627D1ULL, 0x675CD4B6161441BFULL, 0xAA7D4CB0DBDBEC24ULL, 0x0D740D0F52967754ULL, 
            0xEE64CCEFEC37A6B1ULL, 0x069DDB09E395EB5BULL, 0x1A3D3C149EBCC187ULL, 0x0374F965222ED592ULL, 
            0x0AA5E5C3D3FD2EEEULL, 0xF368B0C9DB784941ULL, 0xB4FEE5BFE4E38B3CULL, 0x4E295388132F9D38ULL, 
            0x8F2F2AE9395BDF74ULL, 0x445E2AD1E2BF654FULL, 0xDE1D4DA42C99E16DULL, 0xBDDA28034B30108FULL, 
            0xE668ECDB9943CED8ULL, 0xA98E88FE2DCA3C24ULL, 0xF02020AE84C2EE9FULL, 0x1C7A6243CEA9CFBEULL, 
            0xEA88EFFAC9AB287FULL, 0x1E2D79F0F0D37D3BULL, 0x9869149881A68918ULL, 0x911951CE1E6188B2ULL
        },
        {
            0x9805AEC44E553881ULL, 0xC89B047A298802F3ULL, 0xF8216B57751B3801ULL, 0xBE4B65C52B7E2E1DULL, 
            0x8B73727BFCE7DF02ULL, 0xCFF5AD0D23041A41ULL, 0xF61A5A0E66E182CFULL, 0xD67117CB2BC6157FULL, 
            0x72C4BE3FE90FBA80ULL, 0x79447170E1692F57ULL, 0x998B186312E6E9D9ULL, 0x013F190882555BE4ULL, 
            0x8CB0D33C483A5E9DULL, 0xA48A80D312CA3334ULL, 0x903FD49EBCE38FDDULL, 0x8A81463E67C3AAFDULL, 
            0x13E542E3BCF80201ULL, 0xAB3916531C299BA9ULL, 0x923647B0977888F2ULL, 0x9FEC65F1B4B8D190ULL, 
            0x8A128B8B52BCE43BULL, 0x9F37E26E542FFA04ULL, 0x9CA60A220EF3B265ULL, 0x4C25435BE55660E3ULL, 
            0x93A9B049DB524C83ULL, 0x161064F2DD47B66CULL, 0xB8A16E356887BB94ULL, 0x631988429C594963ULL, 
            0x2919D1D5FB831967ULL, 0xE854F7AFF2AFE190ULL, 0x2ECB1396EBF5443FULL, 0xA14E591FA7DA56A6ULL
        },
        {
            0x6B9035264D39DBDCULL, 0x9F57C529DB8A8FC5ULL, 0x3484FB914A428032ULL, 0x35B74ABB4809B2A7ULL, 
            0x709B472E544DADC8ULL, 0x6B4047235C53248CULL, 0x9303D768F67C6894ULL, 0x7966967CCAE566DEULL, 
            0x6AB8295E2FEF5DFDULL, 0xC882C3927E9BEF68ULL, 0xE73D7D8F42164568ULL, 0x2E9DE58E91C2BFF7ULL, 
            0x0A1C125EC3BDA20DULL, 0x06A3C66990F42F9FULL, 0xB37436D0EED222D3ULL, 0xAF922BC94C6FA1CDULL, 
            0x0482B0187E44861CULL, 0x6912D2C7552126D1ULL, 0xD1AF348A915AB104ULL, 0xA13893D6B7AC5D00ULL, 
            0xDAC58A1D5012A641ULL, 0x64CF7C0ECDB39076ULL, 0x45A3440B124134BCULL, 0x79C2205A1DC136BAULL, 
            0xA4E04E4DFF1BF752ULL, 0x242696C3C678B389ULL, 0x3398DB4D44BED8F4ULL, 0x71AD45817CF1B6F8ULL, 
            0x8F67FF08E17F8629ULL, 0xE38CB56937296BD8ULL, 0x242D14966280E645ULL, 0xDA1477DF073A3107ULL
        },
        {
            0x2FD297CA4E7F30F8ULL, 0xFC2D3FC282700892ULL, 0x78C6155E8FA2BA52ULL, 0x616A2B88A9A372C3ULL, 
            0x4DEB0E08D3F7D2B7ULL, 0x5A7DB5A808D1D85CULL, 0xC7576C05DFF2916AULL, 0x3494E06684A8BF39ULL, 
            0xE21CF6207D5185FCULL, 0x9E303FACA87390D9ULL, 0x4150B65C08BF2485ULL, 0x707F043C3E041E0DULL, 
            0x493BBF91F3BBFA3BULL, 0x9200921B6E9CD8D6ULL, 0x864B03B0B29CE8DFULL, 0x8D0ACE0108C91961ULL, 
            0x1D56F6452BA00899ULL, 0x3471BE0345743D01ULL, 0x879DC909F97BF5A5ULL, 0x9620DA611056106AULL, 
            0x4B89A07197C86436ULL, 0xB882B32A9C29E84BULL, 0xB1FF8C384E12D91EULL, 0xA1E8CF3B58EE0AB0ULL, 
            0x6027BF0F66A0F8E8ULL, 0xB221A518B1FA679EULL, 0x77CA39963A595582ULL, 0x54715D85A8788FE2ULL, 
            0x9CAAB60CF6AFFBAAULL, 0x85D01E65F857AE3DULL, 0x96D2C0DE13DD3D52ULL, 0x179932F830431488ULL
        },
        {
            0x86B709BD847204A2ULL, 0xDDD19B3A66117771ULL, 0x7A7D40CE9C987E3BULL, 0x35A24C05C6F7B54CULL, 
            0x996502C8A1E7651EULL, 0x42AD4C7A1C618FC4ULL, 0xB92610DD3DD998E1ULL, 0x3960AE3C0A89649CULL, 
            0x25F9BBF77E10C090ULL, 0x542155045F6D744CULL, 0x50A57D330F0DD497ULL, 0xA55FBFEA1C39EA4BULL, 
            0x7748A94D51526334ULL, 0x4D8202CD05FC7982ULL, 0xE0DF902FAE40A930ULL, 0x8ACAA8C214BB1F82ULL, 
            0xB35C09E5A5FEAD7DULL, 0x03530B4EE194BB84ULL, 0xB8713CB0BD40561DULL, 0x8F4B26238E2026ADULL, 
            0x037F6BB1B9CDAF25ULL, 0x99F1EBB710F95832ULL, 0x750F3C0C7244ECF3ULL, 0x986B2D04880DA668ULL, 
            0x17E4A0BF23680CC4ULL, 0x9A312F970244BF64ULL, 0x335B98FF2EFFB244ULL, 0xA90DEC95B14DAC33ULL, 
            0x1DA7A8718E20ACB7ULL, 0x6404E740D64DD8DCULL, 0x0C0003390E01B08CULL, 0x4548314BB1B3D817ULL
        },
        {
            0x58A1A7D89B3BBBE7ULL, 0x15B717A277C1C84FULL, 0x85E7475A18F60671ULL, 0x31F35B1C8F57AFE5ULL, 
            0xC20B4D6CB8B165A9ULL, 0x6BEEAFD606B52804ULL, 0xDB477EBA5046AA51ULL, 0x877925F161CDF51EULL, 
            0x8B4685DC1CCB5208ULL, 0xE0860714967271F7ULL, 0x57598F7A2AC006FAULL, 0x9429C5FAA96B0FDEULL, 
            0xDE1D629842CB5B48ULL, 0x287177CCCB7C6D48ULL, 0x833593B8CBE825BAULL, 0x55FE4CA338D507CFULL, 
            0x044260702C605B72ULL, 0xE4C7A16E9228D297ULL, 0xCC23BC125B18EC6CULL, 0x2F32F140299E3A75ULL, 
            0x74EBD75E9E859FD3ULL, 0x2DDE715DCED4B2A8ULL, 0x5F42591576943777ULL, 0x36A5FA27A20A0B7CULL, 
            0x704895F48696E877ULL, 0x1ED8CB8823BB3F67ULL, 0x1FAA9087FA5488DEULL, 0x0908DCBE4F67828CULL, 
            0xE647909867E4643AULL, 0xEC6B3A57F0A4DD80ULL, 0x8D8F39C094A52C96ULL, 0x52E677514CE211E0ULL
        }
    },
    {
        {
            0x4155AB832F8A8DD1ULL, 0xC17E7DF13D245145ULL, 0x6132EC0626276A39ULL, 0xC01FCFFF4918921BULL, 
            0xA9B9F73E07168B93ULL, 0x75E04A8EA5CACC65ULL, 0x7CAFE3E0110858C7ULL, 0x05CFBD1CBE2F5435ULL, 
            0xCDDA95FD30F34640ULL, 0xE57B577014699C4DULL, 0x40CACD0C77AEBDCBULL, 0xF64256DB5506B93CULL, 
            0xFA7A9549ED8AB0E2ULL, 0xEF64F009D0804E50ULL, 0x8B066582FC28E852ULL, 0x72E1216387713EC4ULL, 
            0x6E2B8938E0168C6BULL, 0x3400B512002ABC90ULL, 0x3DA1BCA2FE692FBAULL, 0x002193BE7D57FA5CULL, 
            0x23E5E7D332BFAA19ULL, 0x8E0BE78FE4FA2B79ULL, 0x53237883FD37310FULL, 0x0A741C41897A2FDAULL, 
            0xCBB310597472C995ULL, 0x8361D8FF7AB7415CULL, 0xEEEAF8B09A144687ULL, 0xDBFA8CBD4F829E18ULL, 
            0x3266D33E2EB1A382ULL, 0x888AC3306BF604B5ULL, 0x9ACA9944BEE30845ULL, 0xE21DF9731755A8ACULL
        },
        {
            0xECD06EE2B63FC9FBULL, 0x9C6A714D8203DE61ULL, 0xE98E6B38B8E03172ULL, 0x4F28AB06B771C972ULL, 
            0x252E0F5F9EB23BDEULL, 0x76EC5B8B01D67868ULL, 0x9EB623B98A42DA65ULL, 0x242DCE0EA07C74FEULL, 
            0x537E2D51EB3F8083ULL, 0x950A4197DA264B1CULL, 0x1C962530B8578D7FULL, 0x218F4537C3C0C808ULL, 
            0x86454C1B282AD4CDULL, 0xCCBD5A6B1A5C4E05ULL, 0xAE368757DA5336D7ULL, 0x5D40F721A68B9DB9ULL, 
            0xA2C634ECA1425876ULL, 0x1BAC4ADCA670A954ULL, 0x4AAAD5FFD926FBA6ULL, 0x9D67AC61A1B909BDULL, 
            0x8B3CA71DE833AB45ULL, 0x72F72CB4AFDC4761ULL, 0x5D755D1445363823ULL, 0xEC7BA131A818098EULL, 
            0x673ECD46550953C9ULL, 0xCF9AAA3D62316907ULL, 0x27262CE52D0A1196ULL, 0xAB6B89D60647FA62ULL, 
            0xC3026B3DA5411041ULL, 0x01EE29AD272006FBULL, 0x7C233CE910368B02ULL, 0x8629863DBB8D9560ULL
        },
        {
            0xEEDB3F2C6B9F6BFBULL, 0x90BC03C9D2D88A86ULL, 0x269492277B503184ULL, 0x4EC546EBDE51D3F7ULL, 
            0x77E8760F2A31A0F9ULL, 0x42C1AB138B2457C2ULL, 0xE42FA8637062E51CULL, 0xFF42F757CEE00456ULL, 
            0xFE02BEA245FAA314ULL, 0xAD64B1EA5A403CE7ULL, 0x80CE23D789C62DAEULL, 0xBD7F018773F149CDULL, 
            0xB402C125080BF39CULL, 0xBF31661849F31199ULL, 0x740CD31602985845ULL, 0xBFC02E3E40AEDA01ULL, 
            0x1AF4022A15CB3214ULL, 0x80FA8963201DDE55ULL, 0xC50ACAC9C5BC380AULL, 0xAEDF202E0C39DAC9ULL, 
            0x6FC7E6B7A1A60B01ULL, 0x091C4D2F0D72EBC0ULL, 0x7863308736693645ULL, 0x32A8CA5383D70E71ULL, 
            0xDDD5011C85D9B664ULL, 0x0E9F0E0FCFF822EFULL, 0xBE29C5612F5C681AULL, 0x319EDF3A07119C56ULL, 
            0x8702A24C741E57BBULL, 0xFD484F00B26A499CULL, 0xF0A5CA9D296D2C29ULL, 0xDE335492A7D64C26ULL
        },
        {
            0x44B2B14F5ACCBBF3ULL, 0x76E9113EB064E8F7ULL, 0xD3E49E5765E68231ULL, 0xD4BCE8F091AE8729ULL, 
            0x2E8BBA47C79B7D61ULL, 0x6DD476B8C2560495ULL, 0x8612AD6446641A5AULL, 0x239AED1C7AC9E5B1ULL, 
            0x8C9F19E9871CE0C0ULL, 0xDB7182CBF1FA65B1ULL, 0x638A4930F91AE49AULL, 0x3259B59303D931F8ULL, 
            0x9C03C854BDB4C1F6ULL, 0xA0B51B44D6CB897AULL, 0x4B28B868DF40AD58ULL, 0x2CD729BAA0533735ULL, 
            0x25062BBD0E7A66B6ULL, 0xB17F59E30B35B8B1ULL, 0xF1B24970D74FD8DDULL, 0x34E0EB439B9F939CULL, 
            0xBB91C97A3E0034ECULL, 0x1B75BF7FFB1D51A5ULL, 0xB3FF5EEB46E5B875ULL, 0x335CA1860108B59CULL, 
            0x660C222279224E6FULL, 0x02F2406B8058FDA0ULL, 0xB64CB7DDD2CD3DCBULL, 0xE02E3301DEFDE621ULL, 
            0x1400D6985E29297FULL, 0xF68E4532A0353F80ULL, 0x54D9DB2B9FE1A80DULL, 0x5BA21149538CA2CFULL
        },
        {
            0x1FF996D01604F835ULL, 0xAE545A204298BADFULL, 0x66005F1A6B17FE38ULL, 0x90DF1F521CA7190AULL, 
            0xCDB4E765B0B66196ULL, 0xA955825951328101ULL, 0x31B1FF20C0973A1FULL, 0x744769418A91827BULL, 
            0x1B93247322EC565AULL, 0x5D0E083340243138ULL, 0xE1B1997A562B0B2EULL, 0x5450FCA0EBB3DA08ULL, 
            0xB4030B1DCA747B37ULL, 0x10577265CA27F8CBULL, 0xB01FCA08805C8EE3ULL, 0x820595CEBCD3A162ULL, 
            0x8BD0D8E0A046B13AULL, 0xF113A22352560934ULL, 0x60A0765B0D860FE0ULL, 0x1860BB2E82076ACFULL, 
            0xF077A9108D89CBF0ULL, 0x2D3F89823570D83EULL, 0xF8C429A2944A799FULL, 0xC32F6C746AA1E78CULL, 
            0xFDA0339904CEA61DULL, 0x4BCB5CA27FA81447ULL, 0x6B3D227DA95D92A9ULL, 0xC510B3AC6872241BULL, 
            0x6A9383478AE27539ULL, 0xABA53D6FAE057E1DULL, 0xF6E98BD3C61C2D6AULL, 0x61C5027EF01DEDFEULL
        },
        {
            0xD1527AF6DCA0D036ULL, 0x80DD8D2B9F81D24EULL, 0x12C599AB1F012593ULL, 0x9F59A8FE91615E2FULL, 
            0x8DED6357E33497D4ULL, 0x42351B357E5DD7FCULL, 0x7B1F3AB480A9EB1DULL, 0x7770380C45B2DC27ULL, 
            0x67BD70E7F5829178ULL, 0xAAE60D1DFE29F8D6ULL, 0x5EF9C725E7C9F595ULL, 0x97EF11715C69FE41ULL, 
            0x1DC30C1D513DE2F0ULL, 0x13E162171D56DD89ULL, 0xF7A6451AEFC3C306ULL, 0x49DBF58E8FE4C33CULL, 
            0xDD03C2F68BCFADB9ULL, 0xF620AA4E78F752C7ULL, 0xBCE745A1CF6597C5ULL, 0x70AD61D62FB6922DULL, 
            0xA10FCF676478AC71ULL, 0xF50B3295766FAC6DULL, 0x81EACCF42634E876ULL, 0x8FC8891D13794BDFULL, 
            0x818A8C0FFE4FC8CCULL, 0xA40D639936534066ULL, 0xA39BE98960F8A47AULL, 0xF8B65456404BAC59ULL, 
            0x5B476822BE0F1C80ULL, 0xCF900EE34DD42846ULL, 0x6053BD1B5FFAB4EDULL, 0x69ACDEDB48F07764ULL
        }
    },
    {
        {
            0x34CFAC47CC6F620AULL, 0xBF21D9EE99B06AADULL, 0xA692965302737E73ULL, 0x3A838551098CBC4FULL, 
            0x47B8062BCF1780A8ULL, 0x5428DFF692C99E95ULL, 0x2BBAF796AEBD19E5ULL, 0x0203F7DF8E906206ULL, 
            0x73CF9912EACC7B9CULL, 0x0ABAA5039B37A36BULL, 0xE6FFAAB5EFAC5F1CULL, 0x58FEF46DFD54E02DULL, 
            0x6D669AE486FE0E7AULL, 0x4498548E3C417059ULL, 0x82A733376644FB8CULL, 0x1E63C1E71DE7B2F3ULL, 
            0xEF12E37B8B0FC22EULL, 0x07E33635F2227186ULL, 0x8649035D47045A86ULL, 0x9E9BC479083901FEULL, 
            0x22E5FDF1EF8ABCDFULL, 0x87F3F97CEF764676ULL, 0x96B797A0504EAC64ULL, 0x20D8E788DAB47717ULL, 
            0x231D3458E84C2B43ULL, 0x2ECC0C0625510784ULL, 0x35442435985AF9D7ULL, 0x3FF26DE128A3DE7EULL, 
            0x636215D28EAFCA55ULL, 0x8D86E42E34CC8BBDULL, 0xB5CC4CCF2473A832ULL, 0xB20A2A338A420382ULL
        },
        {
            0x432548BBA41C4B8BULL, 0x456091DCEFDF1DB3ULL, 0x78531D2284DE3D75ULL, 0xB65EA74542B01286ULL, 
            0xE8686513B4C96D12ULL, 0x30944EE008E93684ULL, 0xD2BD59E3FF513BDFULL, 0xC841A35009B95523ULL, 
            0x80EA1B4FBA4C7407ULL, 0xA48DE28911E5AE9EULL, 0x9C46BAC6B090A906ULL, 0xF56F13F1DFD07B0EULL, 
            0x1FB3BA8DD41B2128ULL, 0x6D881A910AED70A1ULL, 0x11CED64E4AE46848ULL, 0x092D35307ADBCF28ULL, 
            0x3BFD7BCF0D76BE7FULL, 0x51D28EC5FCFACC2AULL, 0xF470BFDDD7CAA114ULL, 0xBD0FD44554981929ULL, 
            0x3656AB4FBE838200ULL, 0xD81FCF226C598E95ULL, 0x29F5A7510190FDD6ULL, 0x109031D6E444FFC3ULL, 
            0xCA6E82BBCE599C6FULL, 0x4077B6E764B37DD2ULL, 0x2AA30A4992222E59ULL, 0x3CF9D838D418D80EULL, 
            0x9F27B913FB9C2933ULL, 0xE3ACD3A50BA4BFF0ULL, 0x8D1A884A1EADFA4BULL, 0x750223238A9B8223ULL
        },
        {
            0x93E590DDACAC925FULL, 0xFF3DF63756D46FEDULL, 0xB052F35906F5CA49ULL, 0xC36207B0BA6A1A0DULL, 
            0xEAAF66D0328D38F5ULL, 0x39000EE33191DABCULL, 0x2898444966F9BF7EULL, 0xA45A42ECF09B05EBULL, 
            0x95515C407370E6F4ULL, 0xB0CDE1EBB1001B9DULL, 0xDAE868E60B1A3BE3ULL, 0x6E64FB4A24B9FFD8ULL, 
            0xBEF9F1C7F76D2825ULL, 0x984A534B9C884B9CULL, 0x4047CECD3753E97BULL, 0x1877577F98ACAB70ULL, 
            0xCEE60C9535948636ULL, 0x12D51AF336214CCCULL, 0xB4AC3CA29F737E3EULL, 0x2770FE0C48C96EB6ULL, 
            0x74A1088284019ADDULL, 0x39681CAC1F7E8617ULL, 0x7A4E853BFD8A8DB5ULL, 0x0EC0ADE80081B1C7ULL, 
            0xEF9741E02573CD7AULL, 0x5AD050E4BAE697DFULL, 0x6AE9ACB090A25EF2ULL, 0x389E47B630ECFC03ULL, 
            0x3669766681D738EEULL, 0x74666EFA093867E2ULL, 0x8C965FE028D7B165ULL, 0xBD0AB15D30AA0D41ULL
        },
        {
            0x8A8BD2613078A80DULL, 0x6186B7E4AA66252BULL, 0xAB022113B67E8FB0ULL, 0xE1F3EF86F8FBF238ULL, 
            0x5838E07FBB3643DBULL, 0xB99DE7F7B896369EULL, 0x195BB466A82BC7F6ULL, 0x092F17E986EA4EAEULL, 
            0x92504CBF433477B2ULL, 0xFE9D6EE69D83DEEAULL, 0x15A6C71C6D414DBDULL, 0xB802B28F6B98B699ULL, 
            0x3D7E2164CB190BBEULL, 0x1FB009FBB819F1B7ULL, 0x1621DDF0C780DC70ULL, 0xF3B67A4213AC5CAEULL, 
            0xEEAD887D6DE5C009ULL, 0x61CEE2ECD93038BFULL, 0x72E038F8D5EA5CF5ULL, 0xA73CF4186CE1D677ULL, 
            0xD3E2DE06317DA00EULL, 0xC75D70CCBE01FC80ULL, 0x2B5578813B76A18EULL, 0x5432A547D65D3E39ULL, 
            0x42A2A161E51AC09FULL, 0xF64CCCABA6A8C381ULL, 0xEBAF8976010CE613ULL, 0x7C210598F3AA5E17ULL, 
            0x083634342AD8E0BEULL, 0x6480816D923727B7ULL, 0x8606E2DC7AEED90CULL, 0x906A1DACBBB8DF5FULL
        },
        {
            0x281FF58109062E40ULL, 0x5DC5B4E1EAABB6C0ULL, 0x82364AB720802250ULL, 0xB6896C097756BFC6ULL, 
            0x4A675CE46132D9B5ULL, 0x3D56F661FFA91472ULL, 0x230B57A4DF9770A0ULL, 0x290E9419C090BEC2ULL, 
            0x76CE5A540024D53EULL, 0x5A08F4B3E74C0AD1ULL, 0xFC2CCFBB72488169ULL, 0xFE3C2396BC738AEDULL, 
            0x008AF4FDE73F5614ULL, 0x65954AFD7ECC0A69ULL, 0xAE6B14602A2CBD6DULL, 0x85E348EA800804FBULL, 
            0xB6DE7142D255E44EULL, 0xAE3107D2CBCE7C99ULL, 0xB1A0FD8E08615152ULL, 0x6AC60E5CBE571B47ULL, 
            0x4EE59933728242E8ULL, 0xFCD358C27C26B1AAULL, 0x50C852A762EECDF5ULL, 0x75C511FDCD9E9250ULL, 
            0xE3C8989B18D09072ULL, 0xD5F3875DEE111FC9ULL, 0x38E8CDD976C0EEADULL, 0xD163D75E8E7B82A8ULL, 
            0xD4C4A0EFF4E95B33ULL, 0xA33D177750FEBA66ULL, 0x573271441C3E01B3ULL, 0x20A7175A04CFC311ULL
        },
        {
            0xDCB742B7079DCEBBULL, 0xB241AC4A99DADA63ULL, 0xAE64EDD1E17F3002ULL, 0xBFE17913630772A8ULL, 
            0xEB6EE3488737CAA9ULL, 0x2684E690B26BFA97ULL, 0x5C100201FA01AF62ULL, 0x1DEC14E73CC18D09ULL, 
            0x8CA3A1B3BD44706AULL, 0x7CD02D0B3885B68EULL, 0x3599BA363F112FE7ULL, 0xEBAB7FA769C7BFB2ULL, 
            0xD2D8016E6A49B61DULL, 0x77D5382644851C0EULL, 0xA762E70A02548940ULL, 0x3B7D9F21D96553C6ULL, 
            0x4D670FA4820FC8D2ULL, 0x325D73CF9E5F463CULL, 0x0B0263BC1E3854BFULL, 0xAAD538BDEE5B5F74ULL, 
            0x66BA42347EEF933BULL, 0x9A44314103A6D9F9ULL, 0x92582679FE86B161ULL, 0xD2A43000965FE31EULL, 
            0x71550A27B77B5910ULL, 0x8FE5766C5FBCD7F1ULL, 0x40836E8DA6B8CD7AULL, 0xA1E82BB33A53AD72ULL, 
            0x34B1CCA9FABA133DULL, 0x37EFE4AE862519FFULL, 0x0584F3C87CBD5169ULL, 0x83016EBE271FE195ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Pollux::kPhaseCConstants = {
    0x6F3F07E00C3EC9DCULL,
    0x36678F3FE8E71F79ULL,
    0x1E11E2FB37B5A0E1ULL,
    0x6F3F07E00C3EC9DCULL,
    0x36678F3FE8E71F79ULL,
    0x1E11E2FB37B5A0E1ULL,
    0xBE447865AEF1D46FULL,
    0xB58D25ECED76812EULL,
    0x39,
    0xDF,
    0xCD,
    0x08,
    0x43,
    0xC3,
    0x4C,
    0x2F
};

const TwistDomainSaltSet TwistExpander_Pollux::kPhaseDSalts = {
    {
        {
            0x905321009F3F7B69ULL, 0xB0CCD264CADCDE51ULL, 0x840A360824C5845AULL, 0xEC03161CF79B4432ULL, 
            0xB73EE710266E03E2ULL, 0x4F400FB92C3BFEA6ULL, 0x755019FAB52DB2BFULL, 0x9501831D4FC623CEULL, 
            0x756309F8529A2251ULL, 0xB36A3029B8B175DCULL, 0x133D3A691FCDC04CULL, 0x0664232C472FF6FDULL, 
            0x9E42A5D629009883ULL, 0x5AD3931141DC650CULL, 0xD9DF368657CF72C7ULL, 0x3FFEA9CA5400DED5ULL, 
            0x1D6DECAB987DDFAFULL, 0x02251903E2A44C81ULL, 0x9CA06A3DD77689AEULL, 0x04367E21741509C7ULL, 
            0xB577DA6F6F2B5CACULL, 0x1CEECBDC4A73DAD8ULL, 0xFE8FFE71908C796BULL, 0x87993644F07FD49DULL, 
            0x44CAF67B4E744D40ULL, 0xF2F09B8605DD985EULL, 0xCBE54E4B303028CDULL, 0x038C28C15E701CFFULL, 
            0xA0E750CEB9B07773ULL, 0xCA7B6A8F765752EFULL, 0x29FD543A66073949ULL, 0x7A394C6C1F1463D6ULL
        },
        {
            0xD9D772442EFFF992ULL, 0x3370842D6B06DBC9ULL, 0x7CEBF3FF166BDACBULL, 0xD8FFA24B5A364A3EULL, 
            0xDF07BC364E00EDD5ULL, 0x5FEE8F1C54758B48ULL, 0xA8F95E80DAABE699ULL, 0x4DCB72C4F32BEF9AULL, 
            0x55EEE8E849D0F31DULL, 0x1967E37F6EF87376ULL, 0x1B0EE8FAD3701FD4ULL, 0x71CEFEB809A0DD25ULL, 
            0x6A976180C5E93867ULL, 0x22F2ABE5C0DC79B9ULL, 0xAA227548A31255BAULL, 0x235C4DA5483EB1DFULL, 
            0x161B981CA8EE1D78ULL, 0x1EA61835E4E990A5ULL, 0x3BC73E554B3943B8ULL, 0xEAEC726AB43C5354ULL, 
            0xCFE4CEE13C6B272CULL, 0xA99DF02AF5F81E1AULL, 0x927E95058ACC6D19ULL, 0x72F7B23C85259347ULL, 
            0x79EF4A302D877959ULL, 0x7A2FA771E904D0B8ULL, 0x31CE383E24BF29F1ULL, 0x212AB1BE96521D57ULL, 
            0x76D43A0DA7354F85ULL, 0xF4886A0D6774EFF9ULL, 0x9A639C0557E7C7D6ULL, 0xE1F7018C8CBE57A4ULL
        },
        {
            0x4EF6C72C12DFEA28ULL, 0x1F8B2944BCE8FA3AULL, 0x9B644D62C1F82C5DULL, 0xA9D7B0EE364F87A6ULL, 
            0x797AD3A578CB6FE1ULL, 0xB7796BC631E0D18CULL, 0xDFE65B0C363031BAULL, 0xB083C3818821887AULL, 
            0x1DF3CC52EAEDC69EULL, 0xD877BA3392DE2AC5ULL, 0x200B681894D88996ULL, 0x4052DC78797222AFULL, 
            0x338D0733B77F6AFFULL, 0xFEB0CD558E799823ULL, 0x3E8270C56E217FADULL, 0xD8CC8E0027F1D1B5ULL, 
            0x2EBD84D5B4762D52ULL, 0xDB4F82C4B9B7A787ULL, 0xFAF2E7E68D51AFCCULL, 0xD4942F0F7C19B19EULL, 
            0xE5A4A128F257EE38ULL, 0xD731309EDC5C421CULL, 0x04C7F8302F73F120ULL, 0x49FC49DB5A3A2278ULL, 
            0xD38C8C41AF934898ULL, 0xA63BE5587A85870DULL, 0xE05F2F801919BA78ULL, 0x1C3BE2A6A3722EF9ULL, 
            0xBE52DEDC5DC8F6C1ULL, 0x283B54C88937B234ULL, 0x6125BF7DAE675BCEULL, 0x700248BA19C638BFULL
        },
        {
            0x9B2091CD44D9B267ULL, 0xECFCBABF51FEDCD5ULL, 0x77BE06A5225C1201ULL, 0xA232078E15BFF647ULL, 
            0x038C075C7320581AULL, 0x0021939661FAAD91ULL, 0xAEA4CE92CF70157AULL, 0x399973802FC3E73BULL, 
            0xEA2259B18C1A151AULL, 0x439E18B1B73474CBULL, 0xA45FD347593D1F9BULL, 0x448B8632F6F50EEEULL, 
            0x9B3D2C48595E82C1ULL, 0x44D04FD5F108D1E4ULL, 0xB00EEDEFE2A72F18ULL, 0x52BB6B40C1E40CEAULL, 
            0x6EA18E6C4C737010ULL, 0x103D510AB9F22D6DULL, 0xC2FD8B04560FE894ULL, 0xDF80A12435DC1AFCULL, 
            0xD107799A25591735ULL, 0x9289B3AA013A1437ULL, 0xD22E95D03CF7B569ULL, 0xE15BC1AE8CF7B5CFULL, 
            0x26639617BD690E56ULL, 0xC6F569FF4C38B892ULL, 0x67A1D4C9250ABEE3ULL, 0x07FF5442BF79E508ULL, 
            0x6E193493831C1EBAULL, 0x045453A1FD8CD81EULL, 0xFE74F2F781DE2272ULL, 0xF4DCFA45559DC93BULL
        },
        {
            0xC1FB1DB1E947B297ULL, 0xE1F26FDE4DC1D14DULL, 0x25180B5D88BAB35DULL, 0x6A5B5893F9556FDFULL, 
            0x74103A59B18E71FEULL, 0xCA724F04DB23D0E1ULL, 0x758C7DBFE42D421CULL, 0x3351465B052622DDULL, 
            0xDB4894B28801F991ULL, 0xA0052390141599DFULL, 0x12B54925320240C7ULL, 0x986967F0EBB78A56ULL, 
            0xFF723CA61A05C188ULL, 0x4247AB91B3EE9EF8ULL, 0x3D4A4251F69BC793ULL, 0x2D35BD6EACFB0E38ULL, 
            0xA465CFAFE7EDA3B6ULL, 0x84905C146A539545ULL, 0x340D6A3B5CFE5D78ULL, 0x54B69B0E22CB966AULL, 
            0x84B2467CC8E62857ULL, 0xB86071B017A3F728ULL, 0x0DF3C12A9AE8ADB7ULL, 0x9822F2AC70801F42ULL, 
            0x6540B080A3C6F591ULL, 0x661A13068F83DC68ULL, 0x6D223EE09845706BULL, 0xA4499DF04B2F429EULL, 
            0x1D9B04B28ED7BB73ULL, 0x33F514570490B3DFULL, 0xDC8BAC9FAC2AD11BULL, 0xCC348FEA7F7D0600ULL
        },
        {
            0x8E72A331D38233E9ULL, 0x82EA5C15BC6806E1ULL, 0x4B9A6E6354C6F22EULL, 0x0ECB5ED8B3396CB9ULL, 
            0x982E4743252406D4ULL, 0xB1D146D4EEB0B8BDULL, 0x1B5ACD5C2537E839ULL, 0x48C9A1E3957D3449ULL, 
            0x26E2D97F2C08ADB1ULL, 0x445EA6759BF80D55ULL, 0x912C2CD086D0C83CULL, 0x3E7E8D74650FD622ULL, 
            0x4D18114E7043DBFAULL, 0x626159D117AE5460ULL, 0x00BE0BB286B066E0ULL, 0xA1221BB23298F378ULL, 
            0xC7A921A8A17BFE93ULL, 0x3C4F3DC2F4B5456BULL, 0x0E26AD31962FD877ULL, 0xC2982B087C44AC2FULL, 
            0x41B3BC27CFD51A80ULL, 0x2D12515474604E32ULL, 0x3B2B53F80D127583ULL, 0xDE358575BBF81642ULL, 
            0x92752A7B9EF942AEULL, 0xBEC50FDED0A162C8ULL, 0x2FE49066FAF11959ULL, 0xA82C6777EE592792ULL, 
            0x82C6BB83A01FB05CULL, 0x5B9C19BC8A6D8243ULL, 0x3A90B041206EE296ULL, 0x385AE902D825B324ULL
        }
    },
    {
        {
            0x668132D30CBCA221ULL, 0x4C21F37693152D14ULL, 0xF0229FE8D531CA96ULL, 0xF5A9F8E4E4BACC8CULL, 
            0x5C14B6ED38D87A62ULL, 0xBAEBF0F2ADA7C8DEULL, 0x1D69BF97E341AAF2ULL, 0x86F37B9B4022F3C6ULL, 
            0x506AAD9999308171ULL, 0x4B439B5D1BC3FAFFULL, 0xEDEA06952B177D37ULL, 0x14BA77B6E986E600ULL, 
            0x5FF63EAB11E65081ULL, 0xF7BD9BDD32F9FBD5ULL, 0xA0C8AF4DF4E6A332ULL, 0x6291D500F0C098E1ULL, 
            0xB7B691C23FCE989EULL, 0x12304BB08EDCAE31ULL, 0xEA77B35FF721F1DDULL, 0x893D4761528056A2ULL, 
            0xBB943CCDF3A3947AULL, 0x65757AC2C1819D7AULL, 0xFCE442519F6FAE7AULL, 0x7E697D5A836A225AULL, 
            0xB1450287CFA6E9E8ULL, 0xCAF66FCCCD445DF0ULL, 0x7DE13B62081FAE9AULL, 0x30629B9AF68AE635ULL, 
            0xC7170F392964F7A6ULL, 0x4DA97E652C95C4F7ULL, 0x5D0FF1FD43BB21F0ULL, 0xB40A5CB533669854ULL
        },
        {
            0x239B684A232BC4ADULL, 0x9EC286C6E6866B76ULL, 0x045C4354AC6B4302ULL, 0x15882967B8898266ULL, 
            0x0B71C44217DA3DC4ULL, 0xFEEB5E431C4E8E25ULL, 0x9D2FC91E1B5582CCULL, 0xAEE236202BBE5C6BULL, 
            0x11B945848C08E7F1ULL, 0x1EBFAECD4320BE6CULL, 0x32E324E9F3AE9905ULL, 0x00E5C007E0B49934ULL, 
            0xEF46AC6BFCC43917ULL, 0x2724B921E1805436ULL, 0x4B0F251DED6A1286ULL, 0xA7CF6012FB7F0C45ULL, 
            0x2449748EAE080AD3ULL, 0x8EA97B9B88E8642EULL, 0xA25D355DFC01E046ULL, 0xDD4A2B5A631D9172ULL, 
            0x6D770BC3F807C9E7ULL, 0xD1F66425CA9E233FULL, 0xB07577C1960B7B02ULL, 0xD2AF46D33B82F628ULL, 
            0xCE2F3F3A0E8EAFEAULL, 0x787BC695934D9A3EULL, 0xE9510C71E94ECB9DULL, 0xF6F12AF4EE4A65DCULL, 
            0xEC4A6CDC5C341100ULL, 0x645907E6EEE2AF4FULL, 0x50C6F8EEC54C296CULL, 0x3855FF380D8BBED4ULL
        },
        {
            0x129494C66ACBF1F7ULL, 0x0E630092A67840B5ULL, 0x0F30A774772A0303ULL, 0x701CF61C58735B59ULL, 
            0x919E1E56B71A1CA4ULL, 0x20E54450A18A056AULL, 0x9BB2D6ABB4F33C55ULL, 0x68FAC63C63C5E0B2ULL, 
            0x7F16E171336BF975ULL, 0xF841D7F74A22C53CULL, 0xF7975C01231031D0ULL, 0xE62A63DD9642D452ULL, 
            0xCE09B76881809A3EULL, 0xC7570553EB20B533ULL, 0x428055FC7DFCF9E4ULL, 0x13E4060E96C9C471ULL, 
            0x453AC2ADD6BD4F30ULL, 0x071B494C231FB099ULL, 0x1804512B37D04967ULL, 0xA6685B8B5723F964ULL, 
            0x5EF7F1B683E8B4C7ULL, 0x3D4ADC70B46C095CULL, 0x7AFAD59560956C29ULL, 0x29E57917686BF1FDULL, 
            0x4096F36AB40D4385ULL, 0x2C52DC3B6E098F77ULL, 0xE69CD49B77C36CB2ULL, 0x9B9328F8CDA261F5ULL, 
            0xBFAFD2C2F957B6F9ULL, 0x34D724E763B9349EULL, 0xE18721F80A1896B2ULL, 0x46D75DC78D430A3BULL
        },
        {
            0x2CFCB08151EFF894ULL, 0xFEE524C8A5B4FFC3ULL, 0x86B8BE1DBDDE1448ULL, 0x1B64142E948B79E0ULL, 
            0xCA49769FE606F80AULL, 0x48BE7030461F16B9ULL, 0x65382BE002A56669ULL, 0x9AF9DFE66D96FC28ULL, 
            0x6A15C29B083D04EBULL, 0xA618534AA53A5066ULL, 0xB46AEBD4243AACC5ULL, 0xBB23B6C491CA8173ULL, 
            0x7646EE55F1F9306AULL, 0xE38FA6D8F7D09651ULL, 0xA12575AAF27F894CULL, 0xDB245C5E84D9A857ULL, 
            0xA9A1490DCB4273EBULL, 0x1E3DA2E1DB8C7D36ULL, 0x3FB72DCFEA020FCCULL, 0xE4A36C9E6BAD59F2ULL, 
            0x7CDAD1E2E2905621ULL, 0xB5A67963B63BFE5BULL, 0x3BB080BD31322E3FULL, 0xBD73712DD1188169ULL, 
            0xB8B9798FFF7AB732ULL, 0x10888B2FDEA1AF0DULL, 0x05BB369568702EE6ULL, 0x31EFF5DEB9936708ULL, 
            0x0BFCA1FC705BBE4AULL, 0xE5B2FD2DDB3562C1ULL, 0x4A17C4C1EE8C762AULL, 0x438578DB7F3FA76BULL
        },
        {
            0x187255EA708CA10CULL, 0x5E83DD76B4047E33ULL, 0x3CD5556DFF644FACULL, 0x394DED199F99B185ULL, 
            0xABF7C196341AC608ULL, 0x38A0B54044D30A7DULL, 0x48CD83122D42C44EULL, 0x01815D04064AA789ULL, 
            0xAE6FCB0990CFD91BULL, 0xA4D0C5BFD2000C57ULL, 0x9690210ECFE1B6D7ULL, 0x63AE44F280053B58ULL, 
            0x126E643265914E1EULL, 0xB9E3A0C1B841E0EBULL, 0x9EBAB964800FE4F3ULL, 0xEA8732BE4819550AULL, 
            0x29527972B3B87A27ULL, 0x5EE260DE12784419ULL, 0x7280CFAB57601B1BULL, 0xB0B09016645ED1F5ULL, 
            0x50E9FF7593C4109BULL, 0xE78B4558AEC27528ULL, 0xA51D44AB0EBD4D01ULL, 0xA1654FC78DB57238ULL, 
            0x8343AC1ABBDA13FAULL, 0x6156E9F28B81E23BULL, 0x00D9BDBA5E53BD29ULL, 0xDAC4C1BDC68D48A9ULL, 
            0x4E0E78AD021AB4BAULL, 0x07A721830B20D0D0ULL, 0x89158A3A4338423BULL, 0x833D6C8EBB184FADULL
        },
        {
            0xC9F3B0F93A85654FULL, 0x927959781537E9F5ULL, 0x9A87E85E588C478CULL, 0x4D1870C175899467ULL, 
            0x27369C320D8112A4ULL, 0xF4B36B016BB5C6F5ULL, 0x826EEDFD82FDF80EULL, 0xD84C99602A93D763ULL, 
            0x5DA83FAFCC899124ULL, 0xF4805F151DA4504CULL, 0x91D34697C8AE8584ULL, 0x7137FBD139B06234ULL, 
            0x4D94C1BBFA36054DULL, 0xA09B553349845153ULL, 0xE3E6AD34BE1E956BULL, 0xBA5208AA5A87CF4BULL, 
            0x1F0112B7B68DCC49ULL, 0x37CE0C2C841153CAULL, 0x37C6032C7746E623ULL, 0xB2CA39D980881544ULL, 
            0x848FFA1588962317ULL, 0x8D1685C7BA467890ULL, 0xDBBC0AB0B5392966ULL, 0x37C95B8C07D72E65ULL, 
            0xC2CCF38816990DF0ULL, 0xB94CBF593AE90771ULL, 0xBD2C1B8D77991BBCULL, 0xBA4992148BBD7F1BULL, 
            0xE1939FEBD3ABC58EULL, 0xE23A86D3733E5053ULL, 0x55BE96036D76937FULL, 0x685A5982B3A2A0EBULL
        }
    },
    {
        {
            0xE4E3FAF4278592D5ULL, 0x2BFE6C10A535CB1DULL, 0xB5D0A47BF1496EC8ULL, 0xA1A9C46C4C4A1269ULL, 
            0x5A067F631C6C4F96ULL, 0xCB68D8FEA8C538CFULL, 0x8E80957A6962CA78ULL, 0xAF469B80381A871AULL, 
            0xB12ED15DA39A840BULL, 0x74B82609730CCBB9ULL, 0x0D277B2D3A989166ULL, 0xBF8D89F1805EF607ULL, 
            0x8C2246A618C1B135ULL, 0x4DA3D0BC5950EC8CULL, 0xBDCAB81BBD5BECB8ULL, 0x9C06E47E4F477071ULL, 
            0xF0C6A54D290F913AULL, 0xAE44DCD4042ED81BULL, 0x5C3ED566F9E8421AULL, 0x0C094332C9E71C41ULL, 
            0xD801B9639282141EULL, 0x7529792E84D98EEBULL, 0x4054AF241A5499B1ULL, 0xEF5166E734A67CB9ULL, 
            0x248DC06B964945ACULL, 0x9AC26AA94FEBC8A0ULL, 0x1F872E9DD608C31DULL, 0xFF45FEE9F8694060ULL, 
            0x008E35D5E2332ABFULL, 0x040D648AC9419CDCULL, 0x173865B0B089ABCEULL, 0xB137FF969C2A4C5EULL
        },
        {
            0x242B03056DCFC65CULL, 0xDDD5593F1D285846ULL, 0x056F360E61F5153EULL, 0x333CD6F00293014FULL, 
            0x2A4EF107F97BF54BULL, 0x4BEE7EE45BC043AEULL, 0x9BB2047C335BD536ULL, 0x02B374752705A7BCULL, 
            0x80E5AAF4ABA8F7B9ULL, 0x9E456F3359441B25ULL, 0x1DF56348BE85674DULL, 0x89F2A8DFF995CE7AULL, 
            0xDC046FD8182E0F75ULL, 0x688AE00A9AC34859ULL, 0xFD0BDF1635FF3C39ULL, 0xD8EB4BF7E4E29F59ULL, 
            0x90F8AE8EE6033275ULL, 0x3918CF57A6FACBBBULL, 0xD71075890D2D5FE2ULL, 0x1ED026006D8CDD11ULL, 
            0x77EDC0A9501F9D1BULL, 0x888283E3879F2DBEULL, 0x7D886DD1D62DC123ULL, 0x5C72D48EC1950AD0ULL, 
            0xC07D330F93C5133BULL, 0xB912011692B72BE9ULL, 0x99B20EE275DA0736ULL, 0x9FE04C4D8BC80710ULL, 
            0x490845E4F7D83D46ULL, 0x3B0357467C283B00ULL, 0xD25921477A3193E7ULL, 0xD2120A7A3868C7BDULL
        },
        {
            0xDCAE4BBA3FE7C06AULL, 0x399C3C42B753A786ULL, 0xEE4174A0F6AF64CEULL, 0x9420CAD8B8938819ULL, 
            0x0C9E834B3A1E1833ULL, 0x7C304483F063623AULL, 0xA29F8F17DC02B843ULL, 0xC8DD779BCF9B54E3ULL, 
            0x6B54C8392E37313AULL, 0xD702AD5A648B2BC7ULL, 0x0B2C21B8A16943DCULL, 0x29B82AD21EAFBD52ULL, 
            0xC82552025D900CA1ULL, 0x1B9ED450AC9E28F3ULL, 0x5EE4536F98B1F572ULL, 0xB9901BFD6B38D60EULL, 
            0x7DA87BE1149533AEULL, 0x9FA00BB3D6C4B88EULL, 0x22F5DD749FC573C2ULL, 0x3DB18DA1641EF4B7ULL, 
            0x7AC87EF28E05403EULL, 0xE083EB378B663775ULL, 0x4A0BBD59ACF79552ULL, 0xD4B1F0068C073F18ULL, 
            0x0110953096D772C2ULL, 0xB2B4073114915F88ULL, 0x40125368AF2B0A61ULL, 0xDBA6AFDF398B165DULL, 
            0x4C3561C1CA8EF735ULL, 0x0293F708BD97441DULL, 0xD54963BDB8207608ULL, 0xB2B2910525654292ULL
        },
        {
            0xD147CAFE9A17265CULL, 0x3155E80BE00712F4ULL, 0xEC16B44EF9CEDB45ULL, 0xA22CECA315D95FC4ULL, 
            0xB6CF5F04195D1842ULL, 0xDDE1A0514889F93EULL, 0xB5E8AB4F5ED41CDAULL, 0x49DB71ADB77B473CULL, 
            0x212199F2A0A8C326ULL, 0x340E8D5AE360611DULL, 0xF8E43AA79070DA93ULL, 0x421A33EC591A296AULL, 
            0x3079B655E1D5B022ULL, 0x057D00212BC262EEULL, 0xF1FF8F7DB09B54CDULL, 0x0F4755ED07B9A5B5ULL, 
            0x46B49DD315EB11E7ULL, 0xDD87F3D8899F3CFFULL, 0x6B84458D2E9C836AULL, 0x5B19D23327DB6935ULL, 
            0xC34076F1F7E1A39AULL, 0x795F6A5CD5D8E46FULL, 0x4CE0AB4E8A100BBAULL, 0xBD354CF35B9AB7F7ULL, 
            0x0A3262493354BB50ULL, 0x639C54F2C09FB425ULL, 0x660B50D42DB5B187ULL, 0x136E138061645835ULL, 
            0x264858F1AA95E589ULL, 0x9101049CE6BCE216ULL, 0xC51FCBE470DF463FULL, 0x276AFD61E92EC8C0ULL
        },
        {
            0xCF37D70F430A15C2ULL, 0xA1005B804599B77CULL, 0x325CB130A486AE45ULL, 0xC4FC806E22F1D6B8ULL, 
            0xF54020DA8449B26EULL, 0xFFC7A8BC1AB3D24EULL, 0x168D00E17B0D587FULL, 0xD689DC6EEF83FFEDULL, 
            0x5D0B628C044EB2AFULL, 0xDB19A297D2C43B39ULL, 0x0C23557E41D2061DULL, 0x1A9304EE10965564ULL, 
            0xFF824CE23A0DC9DEULL, 0x7A77C22B0893BA47ULL, 0x753F38A8969F16A0ULL, 0xD5C98190868B2F64ULL, 
            0x0202C69A8CB884B0ULL, 0xBF1903ECC0B2470EULL, 0x16C5205E87CD7CD1ULL, 0x7A164325F0887660ULL, 
            0x86E4EA3E84E6FCFBULL, 0x815044ACDD0FC8C7ULL, 0x35EC12BB0D57AA92ULL, 0xABB31B11F8BB0DC1ULL, 
            0x3D39C12A405F23F2ULL, 0x79120E5A56043F9FULL, 0x9F911516B6D6DA53ULL, 0xD0D7C5239B7554E4ULL, 
            0x1D5E93DD0FBAF5BEULL, 0x3020EA832D36A5CBULL, 0xB11D66A98F3CE1EAULL, 0xDEDBBD3C86E36CD3ULL
        },
        {
            0x8D200EBF41CA3193ULL, 0xB70BDCE5A50DC9C4ULL, 0xDF04C7CB8D72F410ULL, 0x360B7B95491CBBA6ULL, 
            0xF924A4346A0C4158ULL, 0x4E8AAD4EFC18514CULL, 0xF9CFAF7BA5740974ULL, 0x25D9A15A68F33678ULL, 
            0x48A6CCB93F5E4551ULL, 0x46162D018BB57E76ULL, 0xBA30C258F5614371ULL, 0xAF03D0032D6CA346ULL, 
            0xDED4350F16241C64ULL, 0x78790F2A494A3F2CULL, 0x4102B7215B3DD7AEULL, 0x28C30EDED2F4B420ULL, 
            0xB00609DEBA5260A2ULL, 0x8DFE25B9A6174D0DULL, 0xA29E652999DC94C6ULL, 0x08A3E55E94AC0E2AULL, 
            0x3BC9173CC2F2E184ULL, 0xD6E056470E8CE5C3ULL, 0x7978B06001E8E767ULL, 0x4CA012EFAA074939ULL, 
            0x714614EDF459FD58ULL, 0xC2EF33C63BAB6B1BULL, 0xD86A3E061B03DF60ULL, 0x78D98B672B30C673ULL, 
            0x74249E48F4538E6BULL, 0xFA5B108541605140ULL, 0x9F5AF15AC645F00AULL, 0x214FCAE3E76AA5D5ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Pollux::kPhaseDConstants = {
    0x8B54908EFB595B30ULL,
    0xEC338EBC5EAD4423ULL,
    0x196943233B78073BULL,
    0x8B54908EFB595B30ULL,
    0xEC338EBC5EAD4423ULL,
    0x196943233B78073BULL,
    0x1A525C202D581B89ULL,
    0xA9049B734D9A0D2DULL,
    0x48,
    0x57,
    0xD8,
    0x31,
    0x9E,
    0xEE,
    0x39,
    0x03
};

