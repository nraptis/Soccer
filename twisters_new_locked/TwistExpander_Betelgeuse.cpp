#include "TwistExpander_Betelgeuse.hpp"
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

TwistExpander_Betelgeuse::TwistExpander_Betelgeuse()
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

void TwistExpander_Betelgeuse::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF8642D76DFEE2B83ULL; std::uint64_t aIngress = 0x963F9008E11A07DDULL; std::uint64_t aCarry = 0xC492EED53D2931A3ULL;

    std::uint64_t aWandererA = 0xBF51A69DEA40EEE4ULL; std::uint64_t aWandererB = 0xFC10CA6430D1C912ULL; std::uint64_t aWandererC = 0xA7DDBC6AFFD4149DULL; std::uint64_t aWandererD = 0xF6939922802EF247ULL;
    std::uint64_t aWandererE = 0x8C14B13A36565A0FULL; std::uint64_t aWandererF = 0xC4D847FF8A80D205ULL; std::uint64_t aWandererG = 0xE7744813CE56EC32ULL; std::uint64_t aWandererH = 0xAA6F722928F74D3BULL;
    std::uint64_t aWandererI = 0xB3DCC15CF707811DULL; std::uint64_t aWandererJ = 0xDD9618DAA9E99D75ULL; std::uint64_t aWandererK = 0x97D73A095299A75BULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xAFFBDD3BDEAE3A18ULL;
        aCarry = 0x9651CB2613F95222ULL;
        aWandererA = 0xE896EF4E463E90AAULL;
        aWandererB = 0xBC51466834EDB6D3ULL;
        aWandererC = 0xFA74A1B6E77721A7ULL;
        aWandererD = 0x99C654FD4690F204ULL;
        aWandererE = 0xF972786B4941B619ULL;
        aWandererF = 0xBDCE5DA2EE883FD1ULL;
        aWandererG = 0xB4473F7696354146ULL;
        aWandererH = 0xEE4977734980D59AULL;
        aWandererI = 0xC8A24308503921BDULL;
        aWandererJ = 0xCF1165D9E032FC0AULL;
        aWandererK = 0xD1A6208E6915CE22ULL;
    TwistExpander_Betelgeuse_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Betelgeuse::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE37D6BCDB1232372ULL; std::uint64_t aIngress = 0xE09B386C073FADB7ULL; std::uint64_t aCarry = 0x8546D79E06CFF0BBULL;

    std::uint64_t aWandererA = 0x9055DF08B900FE49ULL; std::uint64_t aWandererB = 0xD52D9B0491803694ULL; std::uint64_t aWandererC = 0xCD18BC4CC8FC086FULL; std::uint64_t aWandererD = 0xEB653B4F5EF8A57DULL;
    std::uint64_t aWandererE = 0xFE51B8853C66AE10ULL; std::uint64_t aWandererF = 0xA7FD66BA8BD0CC81ULL; std::uint64_t aWandererG = 0x89A443CD4D02331AULL; std::uint64_t aWandererH = 0x967CC632E1773820ULL;
    std::uint64_t aWandererI = 0xC6E4F1EB4DF3A7F5ULL; std::uint64_t aWandererJ = 0xB690DFFFB7E21726ULL; std::uint64_t aWandererK = 0xA024E9C200A0EF92ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x884572D151AD1437ULL;
        aCarry = 0xB79BF764D155F0C2ULL;
        aWandererA = 0xE9FCF87CA8FCBAC9ULL;
        aWandererB = 0xE214E220164F98A8ULL;
        aWandererC = 0x8F2D7BD3B504CE53ULL;
        aWandererD = 0xEABD5EB057AB8244ULL;
        aWandererE = 0xB01DDB4DEF70DC41ULL;
        aWandererF = 0xB85EC3F565904CBCULL;
        aWandererG = 0xC0315E207A2399B3ULL;
        aWandererH = 0x868A47CB22FB106CULL;
        aWandererI = 0x9FE1B9BB2C64BDF3ULL;
        aWandererJ = 0xA6B9F95C73B208B0ULL;
        aWandererK = 0xA18229AF69BA0AAAULL;
    TwistExpander_Betelgeuse_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Betelgeuse::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xC9C07645D45A22B7ULL;
    std::uint64_t aIngress = 0xEEF6AEB455740424ULL;
    std::uint64_t aCarry = 0xEE98126056049A12ULL;

    std::uint64_t aWandererA = 0xC6663ABC3020067EULL;
    std::uint64_t aWandererB = 0x8A3086D6DFB0B1A0ULL;
    std::uint64_t aWandererC = 0xC60927B77F205764ULL;
    std::uint64_t aWandererD = 0x9A8B84B988EA361CULL;
    std::uint64_t aWandererE = 0xB168B5E6CE459F01ULL;
    std::uint64_t aWandererF = 0xED00E2065F9CE9C3ULL;
    std::uint64_t aWandererG = 0xA93949A276D71D69ULL;
    std::uint64_t aWandererH = 0x8220061A9F8659F9ULL;
    std::uint64_t aWandererI = 0xCEC81141A241A599ULL;
    std::uint64_t aWandererJ = 0xE49EEABA37398114ULL;
    std::uint64_t aWandererK = 0x8D96B6932B5E3ECAULL;

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
        TwistSquash::SquashC(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, aIceLaneC);
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
    TwistExpander_Betelgeuse_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::Seed_H(pWorkSpace,
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

        TwistSquash::SquashA(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, pDestination);
    //
    //
    TwistExpander_Betelgeuse_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::GROW_B(pWorkSpace,
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

// SmartSquash candidate 13 of 33
// Exploration cases: 100000000
// Nearest-family diversity: 935 / 1088 (85.94%)
// Total distance from earlier candidates: 11430
void TwistExpander_Betelgeuse::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    static_assert((S_BLOCK / W_KEY) == 16, "SquashInvestToKeyBoxes expects 16 invest fragments.");
    static_assert(H_KEY == 8, "SquashInvestToKeyBoxes expects 8 key rows per box.");
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 1U), *aFragmentB = aIceLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 0U), *aFragmentD = aIceLaneD + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 109U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 260U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 820U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1769U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 4U), *aFragmentB = aIceLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 7U), *aFragmentD = aIceLaneD + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1378U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1441U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 520U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1282U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 6U), *aFragmentB = aIceLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 2U), *aFragmentD = aIceLaneD + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 309U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1438U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1210U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1293U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 9U), *aFragmentB = aIceLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 9U), *aFragmentD = aIceLaneD + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1013U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 24U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 580U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1197U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 12U), *aFragmentB = aIceLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 6U), *aFragmentD = aIceLaneD + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1987U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 781U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1380U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 937U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 10U), *aFragmentB = aIceLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 13U), *aFragmentD = aIceLaneD + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 571U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 758U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 203U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 22U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 15U), *aFragmentB = aIceLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 15U), *aFragmentD = aIceLaneD + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1248U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 715U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 217U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1321U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 14U), *aFragmentB = aIceLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 1U), *aFragmentD = aIceLaneD + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 412U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 974U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 486U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1875U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 8U), *aFragmentB = aIceLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 3U), *aFragmentD = aIceLaneD + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 52U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1005U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 2004U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1715U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 7U), *aFragmentB = aIceLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 14U), *aFragmentD = aIceLaneD + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1178U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1677U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1007U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 602U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 11U), *aFragmentB = aIceLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 11U), *aFragmentD = aIceLaneD + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 452U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 842U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 552U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1693U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 5U), *aFragmentB = aIceLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 12U), *aFragmentD = aIceLaneD + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 600U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 877U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1322U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 268U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 13U), *aFragmentB = aIceLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 10U), *aFragmentD = aIceLaneD + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1925U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1315U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 374U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1829U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 0U), *aFragmentB = aIceLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 4U), *aFragmentD = aIceLaneD + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1612U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 396U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 907U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1646U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 3U), *aFragmentB = aIceLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 5U), *aFragmentD = aIceLaneD + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1544U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1421U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 521U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 324U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 2U), *aFragmentB = aIceLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 8U), *aFragmentD = aIceLaneD + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1755U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 91U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1486U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 900U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Betelgeuse::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD430F8A7764516C0ULL; std::uint64_t aIngress = 0xA5B6840E104239F2ULL; std::uint64_t aCarry = 0xAA5D7D7270173BE0ULL;

    std::uint64_t aWandererA = 0xD9B9B946AFDC4C3FULL; std::uint64_t aWandererB = 0xF23712814A31CBA4ULL; std::uint64_t aWandererC = 0x832DD1C1ACD8C434ULL; std::uint64_t aWandererD = 0xFBF235407884BD4AULL;
    std::uint64_t aWandererE = 0xF9AC42589C5D7A5EULL; std::uint64_t aWandererF = 0xEC67B088EFF88E20ULL; std::uint64_t aWandererG = 0xF4E301CD6C580B31ULL; std::uint64_t aWandererH = 0xDA9EDA6E1BF0FDC7ULL;
    std::uint64_t aWandererI = 0xF338004B479D5939ULL; std::uint64_t aWandererJ = 0xD8DB64A6C2AAC39AULL; std::uint64_t aWandererK = 0x97B0113BCBF81634ULL;

    // [seed]
        aPrevious = 0xB311F5C840E9CDF9ULL;
        aCarry = 0xB43A9F08AC089389ULL;
        aWandererA = 0xE5E24EB13EAD6023ULL;
        aWandererB = 0xD72181312C9E2A85ULL;
        aWandererC = 0xE460E6228A47C513ULL;
        aWandererD = 0x8D4ACEC27403131DULL;
        aWandererE = 0xD5B9E7581382BA47ULL;
        aWandererF = 0xB263841D337AA8EBULL;
        aWandererG = 0xCCED3B07E358FCA5ULL;
        aWandererH = 0xF37CD0733A621798ULL;
        aWandererI = 0xDD6177C93C8FAF43ULL;
        aWandererJ = 0xC35F1C8544702B4BULL;
        aWandererK = 0x846CA4A89CA06A4CULL;
    TwistExpander_Betelgeuse_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::Twist_E(pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::GROW_B(pWorkSpace,
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

// GrowA candidate 13 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 6598; nearest pair: 514 / 674
void TwistExpander_Betelgeuse::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 295U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6462U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8056U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7316U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6158U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1874U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 812U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5579U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2818U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2692U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6441U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4732U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4563U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3281U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7883U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5169U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1896U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 578U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 485U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 747U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1039U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 301U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1724U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1507U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 302U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 885U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1742U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1046U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1425U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 920U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 300U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 335U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 988U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1655U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1936U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
}

// GrowB candidate 13 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 6601; nearest pair: 476 / 674
void TwistExpander_Betelgeuse::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 97U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4170U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 550U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3863U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1042U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2451U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2963U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2389U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 24U);
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
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8000U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4290U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4334U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6300U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7619U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3435U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1812U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1651U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1896U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1137U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 540U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1134U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1632U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 492U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 259U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1330U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1438U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 589U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 357U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 299U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1787U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 753U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 316U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1894U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1100U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1458U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1872U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
}

const TwistDomainSaltSet TwistExpander_Betelgeuse::kPhaseASalts = {
    {
        {
            0x19FB410E05C81B9DULL, 0x4EB3E46D0E8C6D8FULL, 0x2D0C3769F04ADEC5ULL, 0x68EC97AC0951765DULL, 
            0xD950B5929752D096ULL, 0x38436BDA53ACF6F2ULL, 0x183FAB6D863D5CD4ULL, 0x25DD2FF4F5D32619ULL, 
            0x9D22D30C932FC106ULL, 0x33C08CEF6CB7164CULL, 0x3122213F70055393ULL, 0x76D55DCC5F545CFDULL, 
            0x5EF9BAB2E55FA9B7ULL, 0x088132565BD09B66ULL, 0xE06D18FCB4A762F7ULL, 0x65FFD4846333E04DULL, 
            0x7C34594648D545B0ULL, 0x7CA34BAE9E175B0CULL, 0xA51D2E9F16C9D1BEULL, 0x39152A44F8967645ULL, 
            0x863C636232918408ULL, 0x5471255C43D754F9ULL, 0xAC7E679C37EDFB87ULL, 0xF7B4E68FE0CE30E7ULL, 
            0x0387E327E39D91EBULL, 0x4B36CA763EA7B547ULL, 0xE7CC0A9DB2D6C19DULL, 0x3FAD7CEA5F9842A3ULL, 
            0xC893191E90E573BDULL, 0x7B2D19BC0CEC7ECAULL, 0xF47ED808C8ECCC66ULL, 0xB126B29745A5DF6DULL
        },
        {
            0x6D7975DA9DA9D98EULL, 0x3F4A497FB1D41D47ULL, 0xD6238542FD372674ULL, 0xC38404CA4E699461ULL, 
            0x00A86EEFE50FF8FDULL, 0xCC1B09C9EF96F4F8ULL, 0x10314A01FF6EB4F2ULL, 0x6BD242640404A7FFULL, 
            0xEDFD4A429E0DE71BULL, 0x0BF796988FC00C45ULL, 0xC56E2F4A3FAC30B0ULL, 0x58721D9101BC464DULL, 
            0x49080412002B5664ULL, 0x713EEDC92257CD66ULL, 0x0DAF96EF92653F8CULL, 0xCDF637FE5F078F61ULL, 
            0xF0B1093B1541F47FULL, 0x258A030164E13A53ULL, 0x601672E5A5229607ULL, 0x7C39100E7E499352ULL, 
            0x8A5C6F2798F606A7ULL, 0x8BCD74E3B1033004ULL, 0x98ECCFBEB7C3A1E7ULL, 0x3E76F2CE1648FF46ULL, 
            0xBE4BDB2DFA49A7A2ULL, 0xAC7C5B96541FD775ULL, 0x8E371FCCBF2C9608ULL, 0xB67B5B2FC0B96B88ULL, 
            0x3476AC5FD7CC586FULL, 0x20BB2B68F25C1C72ULL, 0x53B70AC1D4E1239FULL, 0x0C1A1F8EC34C9E3BULL
        },
        {
            0x0239CCC27E3DD6D5ULL, 0xBFA5E3AF5C9642D3ULL, 0xBFB98D3193E5641EULL, 0x4B6BCA84C36A39AAULL, 
            0x7EBE3AFF186E357CULL, 0x11F7A1F9CE49364EULL, 0x3B218444B6C71ACBULL, 0x5B091346B591AEEEULL, 
            0x0E7E28373F42F291ULL, 0x9DEE3C2DB3DE2A5CULL, 0x6B77232647C10370ULL, 0x9DFC86A1B01F8A16ULL, 
            0x1C39DFE8DA91E758ULL, 0xFFDCFFA7837390B2ULL, 0x3B89351B688C1819ULL, 0x344F0E88C24E1E9BULL, 
            0xE10BF7355E00BEBFULL, 0x2E330E95E8289328ULL, 0x53CFE60686C83BD8ULL, 0xCA567772CDADBA04ULL, 
            0x02C64C45FAA319E8ULL, 0x1D0A2F27A9591B0EULL, 0x109A6D9A632DC9EBULL, 0x020961318E2FA1F9ULL, 
            0xEE094BC146347BA0ULL, 0x7DA8AD81E1E17BC5ULL, 0x24AB44BF5518706AULL, 0x674B50247E08FE44ULL, 
            0x629ACD685342F12CULL, 0xD3DF34EBAF70FEFAULL, 0x4F8F342BDB25FAC0ULL, 0x459956F8D8C3E6F3ULL
        },
        {
            0xCEC5CB7CC76D5C20ULL, 0x67173C1B57516376ULL, 0x82F0FC16B2E542F1ULL, 0xA3F6724283E823A4ULL, 
            0x2EA137F5B5D03000ULL, 0x67A40B6F68352EADULL, 0xA083E0B2E19D20F0ULL, 0xFC61555D2B0F58D3ULL, 
            0xD8F3B506DEF5FF73ULL, 0xD6D5AAA4FE8DF938ULL, 0xA3B4FFD6B762C898ULL, 0xE20DE66FC2C040F0ULL, 
            0x6E4584A5048167D2ULL, 0x707DFEC32FCC3A84ULL, 0x78093EEA211147A3ULL, 0x844219E062F9B1BCULL, 
            0xB1FF87EC66CF9B4DULL, 0xF22D8F5C62A0B0F3ULL, 0xBC4D4CA1695225EAULL, 0x3E9F8B9808403ED3ULL, 
            0x7B1D6F58F752B869ULL, 0x08F2C46AC1312C62ULL, 0xB5A98FDD09120E1DULL, 0x7A4E4E827596A6B1ULL, 
            0x1CC52911E0CD6B49ULL, 0x3F3B1869CAFED95DULL, 0xB270C9797F867114ULL, 0x0E28B383B2732DC2ULL, 
            0xC8D145DDAB0C6FB4ULL, 0x9A384F7C157AF4A7ULL, 0x4FAAD59140805EB4ULL, 0x58E057EF2A7321F5ULL
        },
        {
            0xF292E247DED23A8CULL, 0x6E904710AD602427ULL, 0x0CF97BA80B3D527FULL, 0xACF51B37203546D4ULL, 
            0x64D747122C2C8BA7ULL, 0x05DEE9022492169AULL, 0x2BE2D152587AAD29ULL, 0x9B82DAE9C0C5A0BFULL, 
            0x90AAE579204C93C7ULL, 0xB4CD6125CC7F7CD0ULL, 0x9A4E80B1C54864DFULL, 0x154A735C46D8E36DULL, 
            0xCFBFA8A15E327C3DULL, 0x9A285B10EB890939ULL, 0x66A05E599FEDA5BBULL, 0xC2D732F06FCB6B28ULL, 
            0x1B60FA20A889C12DULL, 0x299C7BF9061D1082ULL, 0x84DAEA75E9A8216AULL, 0x3DCD0FD8D04DB5C9ULL, 
            0xBA86CC263B6AB5E0ULL, 0xF6681A60C843BFABULL, 0xA26A90B992213AFCULL, 0x14DB29208A81DE8AULL, 
            0x885187776E6A2A78ULL, 0x3D2B7E75F8E8C604ULL, 0xF6D1603B7AD59C5FULL, 0x302EF6677473AD67ULL, 
            0x52D9CE581D49CDBEULL, 0x40ACA169E7CD760DULL, 0x96C2E58F0479E18FULL, 0xD0B6A3CB66FDB6BDULL
        },
        {
            0x229C6C82DC7B170DULL, 0xC69A5A9776AC060BULL, 0x1FB38E5EE57FB1CBULL, 0x7376CB51E228A1AFULL, 
            0x67009A5E2EFD9B97ULL, 0x2A162829E8F61683ULL, 0x53EFAAA019E57B6AULL, 0xE32F27CC34931A65ULL, 
            0xEE2B43F9A6CDBC52ULL, 0xB32CBE9B83DF77C6ULL, 0x94873294D13746E1ULL, 0xE6DCB740E5FD1F5FULL, 
            0x456306241B5B34F2ULL, 0xE05CBA855D0AFE46ULL, 0x1E599DA968181D50ULL, 0x5B83B4E8629DC040ULL, 
            0x2C2FFADD72254522ULL, 0x99031A2291835707ULL, 0x6003C408BC88CFADULL, 0x38319EBC344A693EULL, 
            0x5C9728069DCC1A87ULL, 0x23D3B590267F4A93ULL, 0xB8A83CCC2DEC8EFBULL, 0x443E8883E5AF9EB4ULL, 
            0x6A4AA0E6113886F9ULL, 0x5F63D0611A04513DULL, 0x9D7BF447060D0140ULL, 0xA9FC2883BC15AF3EULL, 
            0x367FECD06EA28C3FULL, 0x70F9BC5DBAD0FF2FULL, 0x950C635406DEA6C1ULL, 0x0C1F587A14FC2BF6ULL
        }
    },
    {
        {
            0x9EEC1D675391083DULL, 0x3F67B68CE5F17CD7ULL, 0x2B7D3614A8A17A4CULL, 0x612C2C31D2034854ULL, 
            0x363A90785B67B19DULL, 0x5962B0A9A29E3EDAULL, 0x0A7BFBE7D472BA78ULL, 0x796CCD47D410D088ULL, 
            0xD174C55B01126D98ULL, 0xFD46390ABE3CEA78ULL, 0x08B644B1DE6D25B4ULL, 0xD4767282EF298D08ULL, 
            0x277C191528F671A9ULL, 0x5C5EA024A1296414ULL, 0xE78EA8530F5A9C36ULL, 0x4DA9B6E1AFD5EA8EULL, 
            0x59942B187693341FULL, 0xE233502E1CA9E048ULL, 0x61305B060CC3267BULL, 0x4CE196C4202063D5ULL, 
            0xA6672A6B5680CA63ULL, 0xE38629BC09EE6FDAULL, 0x4FCF3B2841E3EF23ULL, 0x0C78AAE321D3141CULL, 
            0xC51F8AF3100B649DULL, 0x30B394FCDF7C5BD6ULL, 0x7F335E836ECC760FULL, 0xEC99CCC51892F523ULL, 
            0x1F66473097504864ULL, 0x4C4D61A890EE7CD8ULL, 0x8BD83E622C446F8FULL, 0x1C48E4AB57E8E8D1ULL
        },
        {
            0xDE59D9A6FDE966CAULL, 0xB2E2FA465FDEE074ULL, 0x6B43470BB422C2ADULL, 0x0EE9383C74A793A1ULL, 
            0x3C8324C607719B1AULL, 0xCF43BE308CD8996AULL, 0xC21AED80FC9A8629ULL, 0xD07B9FD2A5829638ULL, 
            0x94CD0AC87A29C9F3ULL, 0x2295CD7D1F505904ULL, 0xF4A69F8EE0092F83ULL, 0x2CEDD9983F7187E8ULL, 
            0xB61373527896FA3EULL, 0x12498E3865D14511ULL, 0xDE44C40816802274ULL, 0xAD07224C5DD3320EULL, 
            0x8CFBF4F86C570CFAULL, 0x8373449026D2C190ULL, 0x4A5FF2DE7770859DULL, 0xFB4ED6DF8EFD7A7FULL, 
            0xF51CEA8419806D86ULL, 0xC1D13F087B0B5825ULL, 0x885CC083A5CE1153ULL, 0xAE3EA84914C44856ULL, 
            0x860463A0FED195B0ULL, 0xA765BAE57D84DE91ULL, 0xD3B596EA59DDBFAFULL, 0xF9DE851D2F2196DAULL, 
            0x24FDBDD5D1FFEE3AULL, 0xFCC99EF2CFE2FD78ULL, 0x21919C364678C270ULL, 0x0B955AFC557BFF9CULL
        },
        {
            0x94D74261104B841CULL, 0x4512274572FD2AA4ULL, 0x472CEB761B6B48DCULL, 0x9CC814AFCCD1E1CBULL, 
            0xA17301C4B3EF0225ULL, 0x01A580698EA71EEAULL, 0x085DB9994AB2DB2CULL, 0x1325371456822B04ULL, 
            0x6ACA93559A5C20EBULL, 0x0EB4AAA421E2FE19ULL, 0x18FF3011C2037015ULL, 0x26B980956A45693FULL, 
            0x7EC8E6096B4439A2ULL, 0xD61A5D6254C64C9DULL, 0xC3E08FAE5B5912AEULL, 0x304F69003649AE8BULL, 
            0x4CE707663D2B6C01ULL, 0x536FD49F968FFDD5ULL, 0x7F02A5923EB8A06CULL, 0xA3531A494B50B204ULL, 
            0x6CE7855C40FB65DCULL, 0x210EE18F139D0490ULL, 0x3E9B89869A697B89ULL, 0x75CEC6C0B94BBE05ULL, 
            0x1F11AEA7A84D5BB5ULL, 0xC90EF47F74D8F0F3ULL, 0x0B7F3C4D21555E40ULL, 0xA3E509F750F5D86DULL, 
            0x68FA57D62C0D4890ULL, 0x1087E02EA29FC5A6ULL, 0xFA65B3ADA00A0036ULL, 0xF5B0753C443B8513ULL
        },
        {
            0xADEF4F83E8D157E2ULL, 0xA876B26E5DFB41AFULL, 0x11557E736C100D57ULL, 0x5C8CAC9BF13F41F3ULL, 
            0x24E2B39108173C21ULL, 0x0768ADB5AB5E5E4FULL, 0x3AB5AFFCEF5B2A7BULL, 0x2839D018419CF464ULL, 
            0x8F175AA517CD52CEULL, 0xBA824EE455218751ULL, 0xA272C2B73A2BCCF8ULL, 0xA1BD3E5DA13E6407ULL, 
            0xDD31E0563F194AEAULL, 0x4C0E771639328BD7ULL, 0x35A356257A2BDC4CULL, 0x56BF21E95ED96291ULL, 
            0x8553468EEB041021ULL, 0xB94505AB2FADB00CULL, 0x1A7F59D9CA0FD609ULL, 0x85FCFA042BC84546ULL, 
            0x225363C8D0F8ABC0ULL, 0x8B99EE75C4F6A879ULL, 0x4ADCF3068F18A1EFULL, 0xE84E8C4E0D08E8A0ULL, 
            0xEB5EED25921DD4CCULL, 0xB9E189B888700E9EULL, 0x5A8A9EC0DBFA45E9ULL, 0x083F6677BA69D5C9ULL, 
            0x93A314570C42531EULL, 0xAE5B5624F71DA77AULL, 0x6E8B06D0CE42264DULL, 0xA731FE9DAC6006EEULL
        },
        {
            0x65106248D78DD091ULL, 0x461761F9288F75DFULL, 0xB2BC237F603E70E7ULL, 0x785730CC11F97132ULL, 
            0x6CA6ACC8B4FE4074ULL, 0x2FB020DAA0A538E2ULL, 0x9FBA385FBBF916C2ULL, 0xB93E1376EA199EB9ULL, 
            0xF9A6F9FDFE73FD51ULL, 0x93DEE9C6AB068A95ULL, 0x5155EAC749652D55ULL, 0xF3A07A794243779DULL, 
            0x2B3E093C32D3A2D6ULL, 0xD7861C2BD0BCE97CULL, 0x1ECCEC350876C9C9ULL, 0x1DA2704E3929C353ULL, 
            0x48C83EF872A6238EULL, 0x2FF49BDAF39A2FC7ULL, 0x96A557B6C00E5D75ULL, 0x1C4006DCDD949A12ULL, 
            0x95947B0ABF71DD01ULL, 0xCDAF5488AADF216BULL, 0x4B67C99B122721E5ULL, 0x457B9F3AE0E3603DULL, 
            0x63301D9247DFE366ULL, 0xB8990F2E971A34C4ULL, 0xFB0064621E104121ULL, 0x107F745C5FA4347BULL, 
            0x8109543F7D197FF1ULL, 0xBBFE72EEBCBC03F7ULL, 0x1C86673721158B62ULL, 0x8034CF95294DFA35ULL
        },
        {
            0x60F0E9F557C72E42ULL, 0x0A8CA22384D548AEULL, 0x128421081845C56EULL, 0x35D06ADCA4E1838EULL, 
            0xA30E6CACF93B3AA6ULL, 0x62B816D273F7D3E7ULL, 0x1AA5D24FC26EA2B3ULL, 0xEB4EFA9392FA27CCULL, 
            0x78DB6B32FBA0587BULL, 0x705232597AF52BF1ULL, 0xA1274BB9918C6FDBULL, 0x811377BE19624C9DULL, 
            0x2632A6F851DE1038ULL, 0x1A19F9268FEA2332ULL, 0x6AC5ACCA2DD7EBE9ULL, 0x39E6616B8A33A716ULL, 
            0xA42A9F219AA716D9ULL, 0xBCF3E455EB993CDAULL, 0x3CC70A47EB685DBFULL, 0xA443E4CE65B348B6ULL, 
            0xA89ABFA8BF182E1FULL, 0xBF9F8F62D88D4AD8ULL, 0xACFE48B8FDEBA32BULL, 0x3A3737EDDCAB7E90ULL, 
            0x32A3344375A534A9ULL, 0x1747B7B877E85346ULL, 0x728A91711CFF04C4ULL, 0x6059B4B6061391C2ULL, 
            0x19FD2F4ED8DD2835ULL, 0x1D5C773AC382CFBBULL, 0x0F3DE96A60F632A0ULL, 0x36BEDAFD06049B30ULL
        }
    },
    {
        {
            0xF8F5303792DC9BCDULL, 0x93E791AD7B3AB7B7ULL, 0xAA338C625DEA5C97ULL, 0x3B882ACB0A6A8038ULL, 
            0xBCA22815EC6713C9ULL, 0xD8DAF977D90C6F46ULL, 0xC33BDE20BD0DCA5CULL, 0x9E7D04DC94DEA1C1ULL, 
            0x82D28F85027ED83BULL, 0x32188ACE3AFB53ADULL, 0xA87393EE0B53FD6AULL, 0x77D0959599F01C71ULL, 
            0x4654D835F1AFF902ULL, 0x70AF7754437B1D93ULL, 0x5CC30F8E025ECEDDULL, 0xD39D5365E2E77E40ULL, 
            0xFD2701CA355EC5D4ULL, 0x2E847A07A38F917BULL, 0x8155FA3833034BACULL, 0x842D6AC83F204049ULL, 
            0x3027CDFCD318F605ULL, 0x3AC2066C1090E97BULL, 0xA4A47202AA9304BEULL, 0xE2898DD8E827B881ULL, 
            0x1CEB14DC536D82B5ULL, 0xEF58A627FD02F108ULL, 0x7B537257157D7B08ULL, 0xE1F81C78B7F95A36ULL, 
            0x861493B8C1D94902ULL, 0x5C80CBE4A43D0E4BULL, 0x7B48036CBD2AB70EULL, 0xB80A01EBED839798ULL
        },
        {
            0xC0324A362B63CCB1ULL, 0x2320AD06A65AA268ULL, 0x32F86CCF531294D2ULL, 0x9B1815EB038101B9ULL, 
            0xD2FFFEB4FB4CDD38ULL, 0xE3A05DAAEFE84768ULL, 0xD1C9FAFF12B05C0AULL, 0x6452C913C5BE38AAULL, 
            0x11D2B8C20F79195EULL, 0x8DD1D45351299E3AULL, 0x6775A667A63D7A7AULL, 0xD924469CD1CF94B5ULL, 
            0xFC3036C398BB37E8ULL, 0x79EE4C20863A63E2ULL, 0xC9A7729BF479CC06ULL, 0x8D8DE3AE93BF3C92ULL, 
            0xCA357865A54877DCULL, 0x8F7573B0C38DAA52ULL, 0x0D55A7B11D58E136ULL, 0x0EB18490CE619E95ULL, 
            0x8654C9FC6066390EULL, 0x660B74809E895ED9ULL, 0xC4FB930487C9B65CULL, 0x1AD24C9BAA3DFD7FULL, 
            0x114D8EC9A7D262D4ULL, 0xA58E626F71CCDC61ULL, 0x4BC4670453A2A8ADULL, 0x46BCE3C617FF1FF6ULL, 
            0x4BC4DEBA7170F1A8ULL, 0x5050AD634A3D8EACULL, 0x7D52087EF31DF908ULL, 0xFC0BB11708D61543ULL
        },
        {
            0xD040F0D32D610CD6ULL, 0x7C11E36BCEEF7724ULL, 0x65FA54070BAC2025ULL, 0xC1452054F6F44E31ULL, 
            0xE3708BADEFF396CCULL, 0x94CAFE1D26F4BF7FULL, 0x66B7EEC290A580CFULL, 0xFCACC00238DC04D5ULL, 
            0x12475103B9EC9E87ULL, 0x929360F8DBE264B2ULL, 0x567E1B1D63FB61B3ULL, 0xCAB4784CE8DCD951ULL, 
            0xC19BD62640006307ULL, 0x83527AA0E8F89D58ULL, 0xE89C86F3CE0E4DA1ULL, 0x4B22BAEBA496FA87ULL, 
            0x4DAD9815BE64F524ULL, 0x83CB1A11A22AFB47ULL, 0xBF223AAADC86E318ULL, 0xE8152567008BF28BULL, 
            0xAF033E7A990852A1ULL, 0x41F95C02C2DDA3F4ULL, 0x7605CD6B726A7F6CULL, 0x0B18F86D27BD4F0FULL, 
            0x718DB30159C8F2D1ULL, 0xA31D27A55E44DA2EULL, 0x5E1219D79F743ABEULL, 0x6CF3AAE5BE4C214CULL, 
            0x4F17EAF5B66210CDULL, 0xF74DD08738AB34BEULL, 0xF403A281A768588AULL, 0x45A9BEFEAE118F58ULL
        },
        {
            0x8BA6D2AEE1BBF0DEULL, 0x8C2F68204F61943AULL, 0x1775136E4CAE4E2DULL, 0x6011D9F4E402291BULL, 
            0xC39D56B81B3E7D1CULL, 0x5129A16ADA26C84BULL, 0xAB023D2EC0982E09ULL, 0x74577E03494AA478ULL, 
            0x611E4A62263A38BEULL, 0xF253E0A01502F256ULL, 0x86613F7A0B192B70ULL, 0x1BB372C92505CC6FULL, 
            0x824AA6C194266F31ULL, 0x18989B693AFABCC5ULL, 0xF7ACED1B76F7DBC0ULL, 0x89961F40BD727A61ULL, 
            0x32A45110847D826AULL, 0x39BDE0B1ECB1AC82ULL, 0xA506A9F398E4A9E9ULL, 0xC5A73594512BB8E1ULL, 
            0x738D404C2A347345ULL, 0x26DDBC9D8E5A1CA7ULL, 0x3259DAFBFC513B0BULL, 0x2FAD3135A0491CE6ULL, 
            0xE452E8CE2B58BEE6ULL, 0x3499994DF82ED068ULL, 0x616C1B8A74075B01ULL, 0xE42B9378DA263A20ULL, 
            0xEBA41DB508C8BDC3ULL, 0x78072F4EC857EF86ULL, 0xF91846C99E40902FULL, 0xDE9900C442C0EDC2ULL
        },
        {
            0x7E60520588B1998BULL, 0xEA562871286DCB6EULL, 0x0A0CE7836CF73D22ULL, 0xD4B2B82D942FBFC3ULL, 
            0x65EB3C0A9E2FC22FULL, 0x48881B80E12744AAULL, 0x0B26545E57BFDAE2ULL, 0xA7A92CD98DCF6740ULL, 
            0xB25E5F1E33B0ED97ULL, 0x8ABBAE744D41A0FBULL, 0x78557928E94C8A5BULL, 0xD1C75F206D16E381ULL, 
            0x2CF7C6B8634B4692ULL, 0xC2D7A960C8AC2C22ULL, 0xA847EF8DEED0011FULL, 0x85BDE0FB4F64A019ULL, 
            0x4380694AA2DC9087ULL, 0xA943E28753043539ULL, 0x5FF5A079DB02BC49ULL, 0xBFB34C0423F8D741ULL, 
            0x2582D342D697E11AULL, 0x84F405BC5280536DULL, 0x9C8A65FEE4B7476DULL, 0x96B0C7015B007C5CULL, 
            0x3EE00C0931F6BB52ULL, 0x068CED341F7D7D28ULL, 0x80119C3899EBD036ULL, 0x7D809E70AA6694CDULL, 
            0x6C2845B8E6882E27ULL, 0xE965A3CD12A1369DULL, 0x416F35E5684DF022ULL, 0x67DC451A05F8356CULL
        },
        {
            0x178BAA730CB9D5DBULL, 0xAFA1EC90F4D950C1ULL, 0xE4086A6462649EBCULL, 0x0847136FBBD2A08EULL, 
            0x9A0F1A447DA13B26ULL, 0x3A2B3D6C66B72F2FULL, 0x6F8DC148C5EA64EDULL, 0x6CC76E4599E68EF7ULL, 
            0xB09A487DC1E9564CULL, 0x3D31E1AEF71E96D9ULL, 0xB14CD2DB9F3E9803ULL, 0x8762D2F891471FBAULL, 
            0x6DE9345079992B86ULL, 0x999093317B119FC6ULL, 0xE6950B12922720CFULL, 0xF39BC258048AFBCFULL, 
            0x5023D4F83871295CULL, 0x6810B4448E95F127ULL, 0x83F5D6029C049AC1ULL, 0xC31B8AF944DA0B05ULL, 
            0x70009E4D3C55D53BULL, 0xCFD352FF24004AFAULL, 0x5F4B6BE0061FA14AULL, 0xD4CD29EE807AAA35ULL, 
            0x4DE6A131E4ED8BF5ULL, 0xBF7AD473F781321AULL, 0xDD219B278DDFABE7ULL, 0xCDD671B592AEEA6AULL, 
            0x9836B2D0FE2F2546ULL, 0x703304E142C4DCB2ULL, 0xB2A96057241C246EULL, 0x44E31E40E2312E37ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Betelgeuse::kPhaseAConstants = {
    0x9085FD2BE5721C15ULL,
    0x8E58B5419107691FULL,
    0xE5CBF045F7DD2A1EULL,
    0x9085FD2BE5721C15ULL,
    0x8E58B5419107691FULL,
    0xE5CBF045F7DD2A1EULL,
    0x110CE4D8A40550D0ULL,
    0x4557E24A23D2DF2CULL,
    0xF1,
    0x12,
    0xB0,
    0x8F,
    0x97,
    0x2C,
    0x37,
    0x0D
};

const TwistDomainSaltSet TwistExpander_Betelgeuse::kPhaseBSalts = {
    {
        {
            0x174E466BCC31D1B5ULL, 0xC3E79A39B3EF0062ULL, 0x2F74C280B3740AA5ULL, 0x1F0FA43E8E3C9EEBULL, 
            0xE84C9B05720F93CAULL, 0x64A7D626E66E6357ULL, 0x21D06B8645677DB2ULL, 0x0509A8FB37CCA38CULL, 
            0xF46A1E2976C56D96ULL, 0x440886DFB0254F40ULL, 0xFB3EB34D02A41649ULL, 0x537A17F19CDAA41CULL, 
            0xE0D103EFBF60666EULL, 0xE3A2D8055F336FF6ULL, 0xC2D9158F6C327F53ULL, 0xF34013BFC699E898ULL, 
            0xEA0BDA8DEF10F2D9ULL, 0x1F015A1F2A8673CEULL, 0xD31DAB09E159487FULL, 0x1EED9B86843F651EULL, 
            0xDAEA0A51910741A8ULL, 0x87C050B68F476D45ULL, 0xD6C2D1C96A4736A3ULL, 0xBCF2629D6051752DULL, 
            0xC53A42457AA934D6ULL, 0x71760463833E79DBULL, 0x2B1304C73D406F80ULL, 0x1C74FCB8A086A2F9ULL, 
            0x05C9B9C9DF984374ULL, 0xF9374E1FBF5BB69AULL, 0xA24DBC4B20342C3BULL, 0x2E31B62C7DFFAC55ULL
        },
        {
            0x18B7CB63B5B2FD90ULL, 0xD903375092288EA3ULL, 0x0939813B72E2A51AULL, 0x89CC93A6879E912AULL, 
            0xF0F80F90E567A610ULL, 0x19DC30D5DE6622BCULL, 0xE8146DB60566D6D2ULL, 0x7B97E3E1973CACC5ULL, 
            0x19B5414E65E8A441ULL, 0x7C463B7D81C54318ULL, 0x2908F0B1F9F6735AULL, 0x48ACDD449BC54086ULL, 
            0x159C4D885E0F3F5DULL, 0x243E97249810F6F4ULL, 0xFBEADBE889BFA596ULL, 0xB4E0FBED5EE47E24ULL, 
            0xF13561511FA3FE4FULL, 0x4D0181D969F4B939ULL, 0x5CF60F8906B4DD5AULL, 0xB2F32915ADDD8011ULL, 
            0x9A75CE434DE0527DULL, 0x7FDB78521E2F1BD0ULL, 0x2272A9822C8B8B4FULL, 0x013C49995921CE29ULL, 
            0x2915CF7CEEF8FDDAULL, 0x5FFAD76E5D72B516ULL, 0x88C9E96D4F619FA7ULL, 0xF0153AB25C7B5BB2ULL, 
            0xD466C482BAC976B1ULL, 0x43EFF70363E7BB66ULL, 0x414D17D4C674235BULL, 0xF1D9D4E11C0EDF8CULL
        },
        {
            0xB6A66E7BAC8EB557ULL, 0x4FBA3E0FF4811773ULL, 0xE8C3CAB6E595DB29ULL, 0x37A1F753A9ADDBBEULL, 
            0x1CF4EEA18856AA1FULL, 0xD3A05E8E4AB688F6ULL, 0x840E33F41A5CC783ULL, 0x0A84B2B2E4CC872BULL, 
            0xA8114443731CE6E5ULL, 0x24348C4C9DA5732FULL, 0xB134AF88F2679FE5ULL, 0x5C5B949CCA3C1388ULL, 
            0x227AB425AC5333E4ULL, 0xA5C5163B4DD672E3ULL, 0x0AC0BD246C13D296ULL, 0xA6161BF4F800F19CULL, 
            0xEED0EC80FBBA3655ULL, 0xA07CC0049D1259DEULL, 0x653FCE19B31C1E46ULL, 0x14BEC10F3C746AA3ULL, 
            0x3FD179CF764602FCULL, 0x5EE21F1957BF7BB4ULL, 0x86E9713DB8CEFA02ULL, 0x4CA13510D477AD7EULL, 
            0xE4BEC65EEF95301CULL, 0xA87BEE03E988E3DCULL, 0x2888FA2C9EC314C6ULL, 0x4EC538C5A034CED3ULL, 
            0x9D1F93BA29A93495ULL, 0x6F8B563520D703E8ULL, 0xF99B762CC5D237E1ULL, 0x3313D303CFAA1266ULL
        },
        {
            0xE6CDF48A3AE3E120ULL, 0x0A525A021DB29B2BULL, 0xA92E7DEAAE551E48ULL, 0xFF62FD3928A53F98ULL, 
            0x4C33962D75845DDAULL, 0x5CE01D4598C1B812ULL, 0xE3DAFD28A9F7987EULL, 0x7545C281E8754391ULL, 
            0x151C5605D3C3C728ULL, 0x8B5E7F0C00DFEC24ULL, 0x15109D855FF564CCULL, 0xF4C64B2C0F93CE21ULL, 
            0xF1ACF7C04E222462ULL, 0x15A7DA8BB688A4D4ULL, 0x786337E78020AFF6ULL, 0xEB28BEEAF6F74349ULL, 
            0xA3A23955E9654259ULL, 0x8F2E621429A49A86ULL, 0xDECE58744A379CF5ULL, 0x11D7660063E58C9FULL, 
            0x80A2E4A05AA87398ULL, 0x7C58C6D83B6856B3ULL, 0x1F514557F9A7DC7EULL, 0x7728C6246F4AC35FULL, 
            0x599EB3CB7D216763ULL, 0x2D8CBF9FE00FB3DAULL, 0x14590446949CE195ULL, 0xC618625E0C2A4778ULL, 
            0x6869DB734AEDEFB5ULL, 0x536602757E069794ULL, 0xAD1BF91E2D9C9DC4ULL, 0xD435F72A63708CE0ULL
        },
        {
            0xFAF57214D21981FBULL, 0xC2F4B00D5D0188D8ULL, 0x8375F2716BD0E389ULL, 0x64655FCE18C09EA6ULL, 
            0xB66DB35704C02D16ULL, 0x7EADCA4A96DA1D22ULL, 0x440185ED31B47CA1ULL, 0x3706B2AE6733A686ULL, 
            0x2F7596FD0AE52C54ULL, 0xF891711775A83037ULL, 0x947DBF9B30CA4F8AULL, 0xB8EEC993290BDCB1ULL, 
            0xF12B965B4EBC46CBULL, 0x1718B76EFC084673ULL, 0x91D80FBD6401EC36ULL, 0x8E01F0D44326363AULL, 
            0xD5267E1A540EFC2DULL, 0x990CD39C9CA8D714ULL, 0xF17824C8A90FBC39ULL, 0x6B98FED0CB7E9594ULL, 
            0x00BE4E5911A54A7AULL, 0x4F9ABAE78F41F32FULL, 0xE08B5B71FFEF4503ULL, 0x9FB86F01CB343248ULL, 
            0x05C6C975A6E28A26ULL, 0xA9DCE238CFD7FB63ULL, 0xEE076D504D93ACB3ULL, 0x7346CB4CE4B60221ULL, 
            0xB61D8E3C9492BB86ULL, 0xC819C50A464D8CE8ULL, 0x3B6E0CC476F40CE0ULL, 0xDF0D8FAE04CC3E85ULL
        },
        {
            0x5F3C1EAD7DB6AAC6ULL, 0xFD1B1594AB590EB4ULL, 0xB1C285909C103D63ULL, 0xED0F290230D44813ULL, 
            0xBC630C94E1743BCCULL, 0x0AB9FFDEF7125336ULL, 0xC41E053422CA69ADULL, 0x11CE64A36ED6AEEDULL, 
            0x0FBE58BFB84CE9D9ULL, 0xAA40ACBB67C7CF9EULL, 0x8036F5B9E75A1B31ULL, 0xB2CBA67B35212DA0ULL, 
            0xDAF7653C37C8D7A2ULL, 0xE083C2705FEE2DF6ULL, 0x0CB5557B49BBBF08ULL, 0x6B06AB6E24A1EE05ULL, 
            0x0FF98BDA77605DBFULL, 0x72567E2F101C07C6ULL, 0x223C8CCCABFC7A45ULL, 0x82D25A8AC41C04BEULL, 
            0x930CC2540235291EULL, 0xF806A0A5B355F248ULL, 0x621BFE514F39DF9CULL, 0x4975C4353DDD22CCULL, 
            0xB62982AA454E9194ULL, 0xF41B7FC44DD6861FULL, 0xA1624FA2458329FEULL, 0x46B420CC32FA858EULL, 
            0xC1EBADBB7EF3E282ULL, 0x8D3ACD83C68E47D5ULL, 0x332C3CA067C90411ULL, 0x16B93DC39A8C0907ULL
        }
    },
    {
        {
            0x6A0A2330B3CEC46CULL, 0x595DAEB79C5DC36CULL, 0x0BC7B1B6CDB3F53DULL, 0x87BC8F8488DBC075ULL, 
            0xA2139858EBABD4E1ULL, 0x0EE0099BC32C7663ULL, 0xEDEBB89727093164ULL, 0xD95C42887A6A99DBULL, 
            0x23FD1E8FDA2B98C3ULL, 0xC74F01BF9101F517ULL, 0xB431A4CD30200F79ULL, 0x4F0D8CCFB91FCEA6ULL, 
            0x0597D26003086083ULL, 0x2D3AEE8B0CA8B43BULL, 0xCA8C47D282C9A675ULL, 0x5D907E00C3691B65ULL, 
            0xFA856E53CB280B07ULL, 0x335B2BB720C57AC2ULL, 0x1BD0FB0F0C08FE5BULL, 0xC7FD129AF79EF14EULL, 
            0x65F78E5E0B7BA34EULL, 0x4F93025D41B7FA77ULL, 0x01477D16B413FEFAULL, 0xEDA365EF7AA44509ULL, 
            0x351890D9416337A7ULL, 0xEEB470E75B4FD26AULL, 0x122785A68E646B7AULL, 0x833E6D3399403EFEULL, 
            0x4BBF639CE3F15C83ULL, 0x8F1376B4292D9E95ULL, 0x8E0EFA623273BCB2ULL, 0x74945D2AAD1E91DEULL
        },
        {
            0x07BD2A9A2E2F40F2ULL, 0xEBF212114CDEA778ULL, 0x3767999BF7378710ULL, 0x3628BDF41336AC6CULL, 
            0x5B16AEE691D5050CULL, 0xD62EB9EA4850A52FULL, 0x0600BC093B2B4242ULL, 0x9A25B6E48DD1E78FULL, 
            0x0A9DEB6A2FBD6F4BULL, 0xD03420828FD06287ULL, 0x358821DE8FF37E81ULL, 0x35B17F904EB8F886ULL, 
            0xB1880FC4407F5AFBULL, 0x1CD36CD469E902B2ULL, 0xAB56AB5ED8A47CD8ULL, 0x8FEC0E1D3045E31AULL, 
            0x0D4159CAC84DC717ULL, 0xE298511D07CA54B8ULL, 0x81ECA6EF9747C9DCULL, 0xF3A3396995604D36ULL, 
            0x0077F5C01F1EDF1CULL, 0xAD653EF2E7BB990BULL, 0x29C6DE6AAA775C1DULL, 0xA9DC4541F74E3668ULL, 
            0xBBA0AB92A8E58BCDULL, 0x8DDBBEB4E0A065BFULL, 0x41CEB799715520BAULL, 0xE01D0289A76EFA1FULL, 
            0x2FCC71F60C585B63ULL, 0x1E37AF4714D37418ULL, 0x2DBDE840E0F580EFULL, 0xDBF3C66827C92757ULL
        },
        {
            0x3696B948282A6E9AULL, 0x8FE7CBFB47CAE6AEULL, 0x3CD24C5F8646CE7DULL, 0x061CA3BABA1BE4F2ULL, 
            0x5652E9F4BED7E811ULL, 0xB6F2B3E2A2B8DE93ULL, 0x3A14D7C596E72EB7ULL, 0x575B5109C10AE6E0ULL, 
            0xF94DE5D0F54AEC40ULL, 0xE0C5E983903DA266ULL, 0xF0F994F16855D01CULL, 0x34976D114756CD06ULL, 
            0x60E9A3F15D3812F0ULL, 0x8701D3A6ED448981ULL, 0x58A76A0868A4EE30ULL, 0x131543F7710AE56FULL, 
            0xAA968C7E1D53094BULL, 0x2C918D79DFD14E5EULL, 0x84CA4D8F576A48D4ULL, 0xD7E899818EBD87E3ULL, 
            0xD02D67A2AB9C62F7ULL, 0xBE5FA017D42B1F9BULL, 0x15F7F63E4C17EE07ULL, 0x51980439F941DC18ULL, 
            0x75290619BA6B26F6ULL, 0x6194B55CEAF9192BULL, 0x4281D4580DDE7BFEULL, 0xE5C447684C0E31D8ULL, 
            0x523DD2DD678A9C96ULL, 0x449D8FA0D763A2E7ULL, 0xF612920BF0A9A6B8ULL, 0x21317DF977A4BF50ULL
        },
        {
            0xA5C24529B251429EULL, 0x466841BD0688E0C1ULL, 0xD7755CD767D82180ULL, 0x2C5D10FD07993EC0ULL, 
            0xF7BB717D15600F68ULL, 0x3A77DD6B3FCB330FULL, 0xFAB88F1F3E3F441AULL, 0x14F2820B81D1D958ULL, 
            0x80630FE2088EE39AULL, 0xA1F6761D517B9509ULL, 0x7E2B70F795DD431FULL, 0xBC3D11DF5BCA216CULL, 
            0x7AA9B65543D6C0AEULL, 0xEA08F85F447B6081ULL, 0x8131041D9ACB824CULL, 0x6479518CC69633E3ULL, 
            0xFE6DEFBF940D3B5DULL, 0x5BA2DC82C240D653ULL, 0xAB207275481C944DULL, 0x9A27B2F2FFED0D4BULL, 
            0x8ED9362903EAAC6EULL, 0x749B4A0318C717D6ULL, 0x4511C00E8BEA9036ULL, 0x34051C48FCDE4C4CULL, 
            0xF81626EDA2FA5C43ULL, 0x9369C14E24D71CFEULL, 0x2E24EA5F40CB5C8AULL, 0x92D2C245C40D2CF4ULL, 
            0xC9B9330A313D22D4ULL, 0x78B506011CCC2266ULL, 0xDBD5974E5EC080A1ULL, 0x7E55660FC63A7E55ULL
        },
        {
            0xEFE082ADD87D31BCULL, 0xD4B320D8B5752BFDULL, 0x9D6D8A24879E0A6FULL, 0x7DAF716987A3E017ULL, 
            0x1294290A8C694025ULL, 0x3DAADE543271E298ULL, 0x7A88A59FAD35E591ULL, 0x4EDD8DE85959FE78ULL, 
            0xB07E4245A1355135ULL, 0x4E973AE106687326ULL, 0x0AB4E2BD0BCABB0CULL, 0x5A6AF9AC9C34952BULL, 
            0x568666F1053FADE1ULL, 0xDED823F2E1F6F0E4ULL, 0x4498EEC3741CEEB5ULL, 0x6DD2885C34DE3357ULL, 
            0x4D5F1BD35F3AFBCAULL, 0xBABA1D31942E1C4AULL, 0x967EB6AAB2ECFC6FULL, 0x81508E8F0D33D38FULL, 
            0xEC913592921837A9ULL, 0x706D1FD8145C77CCULL, 0x410822E668C9DE1BULL, 0xAEFACC7233A6DAF8ULL, 
            0xC246E620A6341415ULL, 0x8D25B08278B59414ULL, 0xF63E83FD611A73F7ULL, 0xCF270B6D9F776836ULL, 
            0x85331A57A35434BBULL, 0x457B618516260465ULL, 0xC4FD4E616F64AA05ULL, 0xDD3C6725654482EBULL
        },
        {
            0x4E636616713C18F8ULL, 0x7F57DBFFBE4EA60DULL, 0x7B64B8DA952BF72EULL, 0xA70C6E6347A3462DULL, 
            0x8D1D12EF1962EF44ULL, 0x3E26F5D1027C7268ULL, 0x3D1088FFCE75C8C1ULL, 0xB4B96F64ABC70648ULL, 
            0x0ACBB47C7748F5A0ULL, 0x742C2002EFF14C5AULL, 0x555106676FACAFB3ULL, 0xA937D89045CC4216ULL, 
            0xD7080CC5C03D735DULL, 0x7D3E056B18DE43EDULL, 0x274A0827A337C9E6ULL, 0x2889D1E4ACB289BFULL, 
            0xD7BB78866E21760AULL, 0xF6B3F60C198EE65BULL, 0xDF2572DAD2A23139ULL, 0x541566A3423FDD16ULL, 
            0xB269FF00B0B60D59ULL, 0x72946168A7B7315FULL, 0xB3DAC098BB4C8993ULL, 0x88A2E7062C4B08C9ULL, 
            0x52F80BF5C3BAEDD0ULL, 0xE89D96F8FC968910ULL, 0x5C16FEDFBEE3CA8CULL, 0x27063934368E74A8ULL, 
            0xD6A6003A7FD64F32ULL, 0x0A18FA553538E3D9ULL, 0xACEFF1B39A4A5076ULL, 0xB6EA5BD1414AB6E7ULL
        }
    },
    {
        {
            0x7AA20FD63BF4EF24ULL, 0xEF797D9090E51E51ULL, 0x24CCC5802AB680DDULL, 0xACEC86A6A256C4E5ULL, 
            0xBD1DCEAE22EED666ULL, 0x435A71A767329CDCULL, 0x617BB616E78BBDF0ULL, 0xE725BC6D9CE30798ULL, 
            0x12C9F0B1612EB586ULL, 0x4293E786FF9B68A2ULL, 0xC826635040F2F052ULL, 0xF82ED3F6D82A4DAAULL, 
            0x8DDAED84DF52F9E2ULL, 0xF31D26B3D9DB8BD1ULL, 0x6E2E04EB5378630FULL, 0x51F14DBCF69507DDULL, 
            0x9FA7659340FC5520ULL, 0xEB44A037383B181AULL, 0x6609E441857E306EULL, 0x7F8864872E7B81ADULL, 
            0xEA51552EAF9B9DCBULL, 0xEF9CD7B348B06D8FULL, 0xDDBFE21546BE0996ULL, 0xF2B82034A462289AULL, 
            0x9C3B92F7DE35C0C5ULL, 0x6635C987EA1382CDULL, 0x7DCBEB0B2168EF7DULL, 0x379F4D898A8F9E28ULL, 
            0x718E41506510D259ULL, 0x45436380F0EFC622ULL, 0x2E215C3265337CFEULL, 0xDE5FAB8B7E041EAEULL
        },
        {
            0x2DFD19EB499CBB8EULL, 0x9F23B8B28D4F7F2DULL, 0xF54A438B1FB66D76ULL, 0x3ABB31A26B5F2B98ULL, 
            0x78F5E805B10BC3BAULL, 0x507E92B6262F9640ULL, 0xD374C2F6EC073207ULL, 0xEA94D8AB7FE4BB70ULL, 
            0x9A5311EA90AE4593ULL, 0x25607B67A088CF08ULL, 0x4D0A1276CFB1FAF3ULL, 0xCE242F0069BFFAEBULL, 
            0xB5F4358F2843F6B4ULL, 0x7F180ACEA45849ADULL, 0xEECE3D32961B79BDULL, 0x56A4BCA469F9DEA2ULL, 
            0x08737A7C2E793000ULL, 0x713A3A014CE76048ULL, 0x458D8C4506C9E8C9ULL, 0x80F7C277D54A0B08ULL, 
            0xEF936C208FE8BB82ULL, 0x5787C197D53A8AC2ULL, 0x983A87039EBA0A75ULL, 0x233BFC72045990E9ULL, 
            0xA310BB030E154025ULL, 0xA5F49CA952DBF3CBULL, 0xB6B86C89AC5C24E2ULL, 0x72712DAE3906D28BULL, 
            0x305A56E5EBFDE6F2ULL, 0x0952873B4CE05C5DULL, 0xF2AF1486305ABAFBULL, 0x66F3F3CD3181EB31ULL
        },
        {
            0x6D2B774012A3D5D6ULL, 0xF50B6F547D1FFFBBULL, 0xB7AEEB31B96F2E9CULL, 0x822F1098FDF97DD2ULL, 
            0x05C5A4D295C99B68ULL, 0xE35E9B4AF22C4C86ULL, 0x8D02070607452D67ULL, 0x6A7345F57D6A4ACBULL, 
            0x89D24E0B13B4C672ULL, 0xB860C0D76362E200ULL, 0xACD84E01781FAD82ULL, 0x029D13930B1FFCF4ULL, 
            0x1C6A385198387795ULL, 0x65DA2B9CEE4FDAF5ULL, 0xA0B06F4DA983668BULL, 0xC2B4BD8360F65A9EULL, 
            0xC4AE984FDEC3DC54ULL, 0xD37F6E9FBF19CD8BULL, 0x280542347423DC64ULL, 0xD5D0EC7CABE66DFFULL, 
            0x6947C485A4319EC3ULL, 0xD8EBD6A1FAAC4FDEULL, 0xE1796F083F0BD9F3ULL, 0xA40F60D13135C17FULL, 
            0x62F1E5FC25DE337AULL, 0xA8768C4391F68D93ULL, 0x8F91D7BFAAA85879ULL, 0x0F2150FB4F9890DCULL, 
            0x87862853C5E9DE5DULL, 0x1375479AE25071D3ULL, 0xD6670F7BA2C62786ULL, 0xF2C9A7EE73566204ULL
        },
        {
            0xDC9F49316F847D8CULL, 0xDAE361E5C29C715CULL, 0x5E8202DC8DF7F2ABULL, 0xB03720BE7BFEE31DULL, 
            0xCC52176B90E9A071ULL, 0xE5B56C79BC043DA4ULL, 0x53721FEAB5BFC840ULL, 0xE68444944C758B2CULL, 
            0xEC5951BBAF479DA2ULL, 0x864A6423226AF566ULL, 0x0A9F83B88E751C23ULL, 0xD769110C3C5C2728ULL, 
            0x2A2D9C71C78E2293ULL, 0x49307338453304FAULL, 0xA4BCAAB8CC6D9FA9ULL, 0xC2F835775C8E1D84ULL, 
            0x4217004E6C8CC2BBULL, 0x67A07452A1F8A1D9ULL, 0xC385FFD37CDC1482ULL, 0x8644719EFC096612ULL, 
            0x8E4792CFB15C4C32ULL, 0x9F5E85846812AD18ULL, 0xF268D9AE69A58815ULL, 0x86843400F1107428ULL, 
            0x1A079057332F171CULL, 0xF50D7570B9DE2DB7ULL, 0x27032788BB5F30ADULL, 0x90EC225C13479EBDULL, 
            0x63BAA09F0F69861EULL, 0xF54B0B7FFF253554ULL, 0xD7D3CB47EF8EFB8BULL, 0x5CA68C057FC8F62EULL
        },
        {
            0xDCF11BF79AA2F627ULL, 0x41AB7F22B05C2F42ULL, 0xFC247517782898F1ULL, 0x738F218926E5CCFCULL, 
            0xCE169D29DB829E06ULL, 0xA4395B9A993C2D9EULL, 0x429D47981B8EFE95ULL, 0xC57E3FC949853ACBULL, 
            0x9F48BA91A65E5126ULL, 0xD42100F1AED87D54ULL, 0xE90D0204B2C56DC7ULL, 0xAF07AF18F36A2674ULL, 
            0x6E3B71935A3BEE7EULL, 0x27A8A6BDD2845E80ULL, 0xA9D08A4C44140F18ULL, 0x2F5AF08F35F5F176ULL, 
            0xEE1441D76FD1AB83ULL, 0x0B7D4403DDC1650BULL, 0x336E798678F28DB7ULL, 0x8240EE14F085026CULL, 
            0xCB91BC2B4872332CULL, 0x5A1A49A74FFF0A9CULL, 0x28652BFB08975A8FULL, 0x0680DCF67F4A0835ULL, 
            0xEB3B7C481C1638EBULL, 0xF4713AE52F0EE1F2ULL, 0x4B4B0BCBEDB5C9C9ULL, 0xD31C2200C032B68EULL, 
            0x3563B71EEB88C0ADULL, 0x09673085990849C8ULL, 0x98E3826BF811EEF7ULL, 0xB0EA45A08CFD4434ULL
        },
        {
            0xAACE6B93040895A9ULL, 0xFBE57F2027842E87ULL, 0x36F757C3100FBCF7ULL, 0x9F79B210980DEFD5ULL, 
            0xFCCA3EC3725B2EE2ULL, 0x420CAA9DB5D2BEE7ULL, 0x067234604075F092ULL, 0x0249B0499086B579ULL, 
            0x5139E818C7E5403CULL, 0x7D5123019E5F3C93ULL, 0xE7885D214C446D81ULL, 0xDDDE0D0A227CF516ULL, 
            0xE47EBD42E4B5E4CEULL, 0x7AE73C147D0F03A0ULL, 0xED279EF14377D8CFULL, 0x3134138947A2A7FCULL, 
            0x849D75FE32B9C151ULL, 0xC986D27B0155EF31ULL, 0x3697880E187F8BA2ULL, 0x3F207EEE2A512504ULL, 
            0xD2C9D65DE2BA1FA7ULL, 0xD5DC5A2CBC7994D9ULL, 0x126F120CC8EC0964ULL, 0x40BF085CBDB3E26CULL, 
            0x107B035CE84FB07CULL, 0x086BB6F1FE1FF531ULL, 0x062738355B548362ULL, 0xB484E1C5E6B78622ULL, 
            0x8E31882637F5C2A1ULL, 0xE5929EDD5B598521ULL, 0x7728BA844F3394B4ULL, 0x0934C55F1FBEDEACULL
        }
    }
};

const TwistDomainConstants TwistExpander_Betelgeuse::kPhaseBConstants = {
    0x6A59D17816ACA74DULL,
    0xC5E958BC9C3DB5B0ULL,
    0x4344D56131F55143ULL,
    0x6A59D17816ACA74DULL,
    0xC5E958BC9C3DB5B0ULL,
    0x4344D56131F55143ULL,
    0x2BDCAF941B03775DULL,
    0xD7D740624942B0D1ULL,
    0x2C,
    0xFB,
    0x79,
    0x7C,
    0x07,
    0xCE,
    0x94,
    0x80
};

const TwistDomainSaltSet TwistExpander_Betelgeuse::kPhaseCSalts = {
    {
        {
            0xF14BC548B058D94EULL, 0x90C43567C1D296C0ULL, 0xACB74A304AFE5C54ULL, 0xCF646D53E629BBE2ULL, 
            0x03C1A588DF1A9134ULL, 0xF5695262585AB000ULL, 0x1B8058881A553433ULL, 0x996529F2A2444911ULL, 
            0x30F11814E770EF40ULL, 0xD9F9598BB46553B1ULL, 0x89D38C704CE65938ULL, 0xE5E5D115F65837AAULL, 
            0x845A73361424B6DEULL, 0x5A0E0ED755006FCCULL, 0x7596EDC146B7AFD0ULL, 0x245A991037001336ULL, 
            0xD2216FEE914E7374ULL, 0x4A543CB7DD7BA3FAULL, 0xB670F7CE43B8AC24ULL, 0x825C7D2A2D247F82ULL, 
            0x62C9E2C5833B8397ULL, 0x856250FEA02F2C16ULL, 0x98F8B9F14139285BULL, 0xB863A1E763096BBBULL, 
            0x050CC7D6204BA5A9ULL, 0x49255E2F703188A7ULL, 0xA4A2B5304275D7E7ULL, 0x16A00AEFC68300E1ULL, 
            0x73EBC26E949ECD4DULL, 0xCCE665BEEC7D1CBDULL, 0x37BA9B6B10272CD8ULL, 0x80BB8F5B6A19FBE1ULL
        },
        {
            0xC57110DC64527D26ULL, 0x448FF4FB25CB7EC7ULL, 0x413CAD1C43460C6CULL, 0x8151B0C197676CEDULL, 
            0xF05D1197D38C8D67ULL, 0xDC687B1DA79E08B2ULL, 0xABBB359D6298E176ULL, 0x81F1FC123514A8C5ULL, 
            0x83B4E973970251EBULL, 0x90670350A0288A96ULL, 0xFF76940D575CD5D4ULL, 0xF8C5F0DFB52C4786ULL, 
            0x60C799B61C4C6566ULL, 0x2D33BDCE14ADD439ULL, 0xFACCDD4BFAE4525FULL, 0x064474BA9BFF5F04ULL, 
            0x8A3B16F30CC66690ULL, 0x259596FBE2E0740FULL, 0x9E87E3B8A3053182ULL, 0xF8B536038A560301ULL, 
            0x337DB4A7EA007EC8ULL, 0xDEDDC77B698150F2ULL, 0x151E773DACEF1428ULL, 0xCC0E25F6BC74EC26ULL, 
            0xD25BB80B248B3EB1ULL, 0xD6541D13D94003E8ULL, 0x6844ADCC6B2EAD6FULL, 0xC71A9434EA26C79EULL, 
            0x929BF213AB50D7D4ULL, 0xF402A493ACC74F7DULL, 0x4F1F6FC4826153F1ULL, 0x63BE6A048BF4B6B2ULL
        },
        {
            0x7ADF2936AE7D44D4ULL, 0x37098B9777463126ULL, 0x16A4FEB920959264ULL, 0xE53351A82A6D975BULL, 
            0xA6E2F1667E4F7E68ULL, 0x06CD24EBD185D75FULL, 0x221482411AC168D4ULL, 0xF291CAAADD5B17D1ULL, 
            0x668741970FCFBD94ULL, 0x783EFB691E593A4AULL, 0x4202CF0207A70E85ULL, 0x4D3AFB7182FA9863ULL, 
            0xAB64A6F13E5280B5ULL, 0x8E77BA46D89D3930ULL, 0xEF2CFF2051A02F0EULL, 0xEA7CC3291C9DD79CULL, 
            0xAF97C01406DC3A52ULL, 0xC731DB0B569ACAB4ULL, 0x659658F91059F050ULL, 0xDB9EB6AE982A999DULL, 
            0x4DA082B6FFDA1348ULL, 0x5E139432B993C30CULL, 0x6AC9A5C06CFC06A0ULL, 0x589E54B453A8B558ULL, 
            0x23F118F177BD4A70ULL, 0xF10E44757A61BC1FULL, 0x028EAF89796C9D46ULL, 0x942B62A95C22E6DEULL, 
            0xC593104E38A6B2C1ULL, 0x317C8B97BFA75D7BULL, 0x50821B46D477AA8BULL, 0x13C6F012575B57F6ULL
        },
        {
            0x925711DA6A7E2A4BULL, 0xC8D0647F5D115E35ULL, 0x2BD539B44A3DA081ULL, 0xDA94CC75DE549944ULL, 
            0x29FF8893A03B007FULL, 0xE36958E0E4219DBDULL, 0xF83BBDDDDD8F544DULL, 0xC6B372B945A515D5ULL, 
            0x0552C51FCC0F2343ULL, 0x3558E142777E61C7ULL, 0x55A61F9E9E07DD99ULL, 0xFBCEF9F3294C85D2ULL, 
            0xCFBCD79553F2E6B3ULL, 0x280BC90B45CAE255ULL, 0xB1709C7D4CF503E4ULL, 0xAC00BFA7CA481F16ULL, 
            0xF45C7E3FEEBE42ECULL, 0x139261A6B1A1EC97ULL, 0x6AD827D2E44F8542ULL, 0xE237E928FD1BD0AAULL, 
            0xBACB161B4AE211B9ULL, 0x806E445535D9B83CULL, 0x1F37C6AFB3ED2DD5ULL, 0x5ED0E2A7D9BF4FA2ULL, 
            0x2C9F53CB4AAAD77DULL, 0x1D9FF86B7AC24691ULL, 0xDC86B1575D4EADB4ULL, 0xA3FDDDD27FA6203FULL, 
            0x14C15A650D58742BULL, 0xF92EB325C1848386ULL, 0x085A4430DD315C51ULL, 0x750B975EB4BC232CULL
        },
        {
            0xC36158300B0FED02ULL, 0xAF705A77B95E8AFCULL, 0x60426C9F70B95962ULL, 0xC52A03C99571B5B8ULL, 
            0x935E49C936046160ULL, 0xBB89FBD2514AB4E5ULL, 0xFF1798A3C341CA2FULL, 0x0BE08574DFC235CFULL, 
            0xF30C2E0638242961ULL, 0xCAC198B038AD6A2EULL, 0xA43408537EEA85BEULL, 0xC90AD69090603A23ULL, 
            0x2D6821F12B52625FULL, 0x5381E1E380D3E094ULL, 0xC7D90B6C28DA8B8DULL, 0x6DC0BE4184C89DA5ULL, 
            0x19909A93E2F8AE94ULL, 0xDA28855A7815F32EULL, 0xEA70C8CAFCACD8C9ULL, 0xB61DCEB0103C1899ULL, 
            0xFE6CF13E41C8D2D5ULL, 0xB7C2B53373BE9EB2ULL, 0x4F80FB7CF674D327ULL, 0x129CFFBB13DE4608ULL, 
            0x9542C2C1F6892A2BULL, 0x3E88BF0E70F5550DULL, 0x7A6968BFF084E276ULL, 0xF0DB45FD3CEE18E0ULL, 
            0x0C5A63533FFADAD5ULL, 0x2A9D0933BBB2B0B0ULL, 0x9B135920CD2E725DULL, 0x4B7DC1EA07314C21ULL
        },
        {
            0xBF76293D0DDD6832ULL, 0x002DCFF25D1431FBULL, 0x6726D884C4954251ULL, 0xAF4181F125DC2FF8ULL, 
            0x86E1976F1F6CC004ULL, 0x6A3B00D285A17334ULL, 0xFC10E426A0EBD1AFULL, 0x3EE28FDF66C76E6BULL, 
            0xBCA2A347BD577655ULL, 0x06CF31CB581B2A2DULL, 0x91D059C43DA678C2ULL, 0xC37B81E1531969BEULL, 
            0x98C6E5F3E4C61254ULL, 0xDC7CEE8D93CA2B3FULL, 0x382DC7204C471098ULL, 0x714BAE2A2A5ABBCCULL, 
            0x03153620A7A05C3CULL, 0x368ED2BEFB245DBAULL, 0x81B800AD7CE66688ULL, 0x4BD42AD18A816EEDULL, 
            0x48D9B65FF9C6CB42ULL, 0x261073622E6BFAC9ULL, 0x09468F445F7EA3B4ULL, 0xCF5332254AFE247AULL, 
            0x2979DD627493B9B1ULL, 0xDFFA0587A33648F4ULL, 0x4AE35BB6D3B09CA4ULL, 0xE81F453073E3283DULL, 
            0xC59A734B6297C3D7ULL, 0x96B88668979D9466ULL, 0x3B7A95E515542253ULL, 0x22533CBBDDB3912CULL
        }
    },
    {
        {
            0x4EDDEC6250D9C7EDULL, 0x894276212998005EULL, 0x0883BF9F132FA9B6ULL, 0x1FCF96075357EAC9ULL, 
            0xDDC0804679E9CE29ULL, 0x0F708746C1B75C5BULL, 0xCB3173202B955383ULL, 0x216831E2E6887C50ULL, 
            0x8ED2B70CBE2CFE0CULL, 0xC9C573906D37AC42ULL, 0x716873BB7F5F4A86ULL, 0xFF11B0C0B9AD26D8ULL, 
            0xF9796281E5562797ULL, 0x5EE277D8432F5E77ULL, 0xB329A25129DDA9A4ULL, 0xB1217B9F3BFD5FF1ULL, 
            0x94AC22B8EAAD28ACULL, 0x4A0BCA424FE4BD27ULL, 0x9FAA9D03350CCB63ULL, 0x655CAA68B7EFC0D1ULL, 
            0x45B2039E3236E9CEULL, 0xF56F7DF6275103C6ULL, 0x9861A977319457DEULL, 0x45A596D9B81E9998ULL, 
            0xADBD5C100B3D5FA0ULL, 0xEA4D1658BA6F6177ULL, 0x5E73B3D1D5ACCB52ULL, 0x2B5FD3CC581B1335ULL, 
            0xCF4D15C52FA18F91ULL, 0x3E1CC36C404EC9EBULL, 0x44F321FF79F22D05ULL, 0x7981BED0FDB14C28ULL
        },
        {
            0xA6BBE00655F088A1ULL, 0xB2DE485A773BE43CULL, 0x34876BDBC99E7191ULL, 0xE741C68287D3B1F3ULL, 
            0x6F73087F07534D96ULL, 0x944DACA8BDAF3BD5ULL, 0x2123FFF13F2A75B2ULL, 0x506BBD0E7BDCE09DULL, 
            0x79B95E186651260DULL, 0xE9E77D2C4BF2BB17ULL, 0x128A0CB0F21DF29AULL, 0x644DA644B906A262ULL, 
            0x07CC5869BD9DDC22ULL, 0x47F4C159C4A8257AULL, 0x9476D1803E5A564EULL, 0x49E2D645E0538F5BULL, 
            0xEE4CD08005BB4196ULL, 0x9204F46D0572D318ULL, 0xADB878E2AB28A9E4ULL, 0x96BC03308AE7AC0DULL, 
            0xF3A147FFFEEFCE9AULL, 0x40EA7A1F08DD9FA5ULL, 0xC070B36CBF09F70CULL, 0x07EDCD3039D54048ULL, 
            0x2017FF2AED0DA4FCULL, 0x5C8C37F8952A35D0ULL, 0xF697ED628B1F793BULL, 0xA4F13F05F35EC21EULL, 
            0x50716448D2C5D5E9ULL, 0x6A2EC6E814A22B63ULL, 0xA0579B8B9EA5C7B3ULL, 0x5605771E386842C7ULL
        },
        {
            0xF7574CAEDFDE8266ULL, 0x0C82838B3863C373ULL, 0x3B7512C1E3552F39ULL, 0xA6397DC90798E456ULL, 
            0xD2C2938D1D1D6457ULL, 0x122BEC21B2A0408BULL, 0x7E0338B37EA66EEDULL, 0xD4C9428E6CA6A217ULL, 
            0x3861218D37F1FC49ULL, 0x85A40DEBF32B2653ULL, 0x5297F806CC8CEC27ULL, 0xFAFA021A3D089A9AULL, 
            0x537F63A1EE805FF0ULL, 0x2BA08EF95E9A6EB9ULL, 0xD97CA151F85C0FEAULL, 0x24509D57480C7C3AULL, 
            0xEBF01F703CE93573ULL, 0x5392A9D08774FFF9ULL, 0x6726E6B0EE99FCEAULL, 0x37B947E19C842584ULL, 
            0xF68466121BDFF937ULL, 0xE4A49161C2C9D70EULL, 0x607DC300F40EABFAULL, 0x96DC3273A48FE4F5ULL, 
            0xD565D3E241A9999EULL, 0x1867CC3D30135A1EULL, 0x530A7408CF22923BULL, 0x605DD58F895409A0ULL, 
            0xFEFADA6CA9F957F4ULL, 0x7E4D1D46A1458619ULL, 0x97509B9175ABBF78ULL, 0xE87652AA46517344ULL
        },
        {
            0xC52F269213369133ULL, 0x09BE4FAF3DC07999ULL, 0xD6D5C3082755AA95ULL, 0xBE9113FBEC896D3BULL, 
            0x3C7D755425F42825ULL, 0x0E216DFBE85E6996ULL, 0x598FF6C3E6AE0A97ULL, 0x3AB09E818FE54BCBULL, 
            0x02F86FC1B622ADBEULL, 0x196DF2A72596C301ULL, 0x058C784FB8ED4BF5ULL, 0xA9C4213534A93861ULL, 
            0xC448D4B40E01BEA2ULL, 0x35A4E92F6909E928ULL, 0x4C9E067233C29604ULL, 0x91AAD2496345E932ULL, 
            0x8AEE52AD73AEEAB6ULL, 0x670872F766C2FCA7ULL, 0x9A3F4E70D27940F7ULL, 0x1D5AAEEF2E59A48EULL, 
            0xB39EAFFBCF0B6DE4ULL, 0xC10FFC45BEA79AF5ULL, 0x919B47DECA00C927ULL, 0x643F7A93C3E67030ULL, 
            0x8248F05ACF1B5DD5ULL, 0x95132E7B66164B7CULL, 0x307A126D3F5A949CULL, 0xB07864F325447076ULL, 
            0x72E43387C4935B95ULL, 0x49DDE6F5796CA245ULL, 0x1B21D0BE49E19858ULL, 0xF69931C2AD242372ULL
        },
        {
            0x307758D43B471F36ULL, 0xB6652B06FA87C1E8ULL, 0x7080FE9CD5B58E3CULL, 0xB18B8E7BAC7D6777ULL, 
            0xC7D274C05CF953E8ULL, 0xFF963ACABF552AECULL, 0x022F448557B2FE3FULL, 0x452B4C2ADF5BAD75ULL, 
            0xDDDF329FC7236304ULL, 0x6530652EC0263E16ULL, 0x5D82E906C833B16AULL, 0x29A389C74F02E84FULL, 
            0x59561AD4D7679074ULL, 0x51763B6A54846507ULL, 0x9199AF081A378727ULL, 0x27F547E1E4A17732ULL, 
            0x47ECF647D48BCB1AULL, 0xADFDEFB7B8B12068ULL, 0x55FE089C005F17E5ULL, 0x1E601AE75F645651ULL, 
            0xF1B57590B2EE3561ULL, 0x39FEC86448416721ULL, 0x137A1875312FEE23ULL, 0xA409FC7317D4F429ULL, 
            0x8C3F26AE9B4F2473ULL, 0xB14635325313F800ULL, 0x1CE50FC913AEEACFULL, 0x8C4B4666A58B8CA0ULL, 
            0xCE1E84D173FAB009ULL, 0x77458563450CD49EULL, 0x65C4EC9A4A396EA6ULL, 0xC45924C3D2441E61ULL
        },
        {
            0x76B8CF0345E77E95ULL, 0x80664B5160DB8B2FULL, 0xD961B959138A216AULL, 0x9D7715C20906DBE0ULL, 
            0xFF042DFD4C47677BULL, 0x2DF8CAA7EBC4C7A6ULL, 0x41306150C96D4316ULL, 0x9D23B092FC1E8F35ULL, 
            0x0A15274DFA0ECBC6ULL, 0x1B65EBE78918F433ULL, 0xCD401A2B7CE6D481ULL, 0x9B9A96990B32DA12ULL, 
            0x6D42E4BABC4CA579ULL, 0x2ED9E370BB6D3155ULL, 0xDB901CC12354012BULL, 0xB3938D17CB915BAEULL, 
            0x8B78481796B36F25ULL, 0x5951C3E1B9BD0D26ULL, 0x06FB41A3D824AD9DULL, 0x2C2BFB5FF5094C11ULL, 
            0xB37FAFDF66777F29ULL, 0x25F8A55A2DDFFDABULL, 0x5B22B619AF63C639ULL, 0x1329401A7A8599D8ULL, 
            0x483E02F250EA0FB7ULL, 0xF142068D4BCEB41AULL, 0x66C02D6A8513A3F6ULL, 0x428A9B00DE78C224ULL, 
            0xE76591A6BAC009B2ULL, 0x06C5F7AEB1F53CACULL, 0xDF27855E379F8461ULL, 0x9D10187F1A234498ULL
        }
    },
    {
        {
            0x0FB70CFA4ADD0FCDULL, 0x92D15555EA60BAC4ULL, 0xB01AD6FFE7AECE38ULL, 0x6AAAD153E0471711ULL, 
            0x08A74827326D6D45ULL, 0x7DDD1128D78C0A92ULL, 0x8A4909841F4539CAULL, 0x9D4B1A6353DD1B66ULL, 
            0x1ABB8F75D9182F1CULL, 0x004CFD5394108ACEULL, 0x80FF439C8E6BD8A2ULL, 0x2EE2287039EC6703ULL, 
            0xBBC56058A084CB8DULL, 0x40593546C7D6831AULL, 0x85968DAC0C91421BULL, 0x01C872833093C636ULL, 
            0x9ADF79B42602B0CEULL, 0x4D4A20436DB5C1FAULL, 0xEA1F4115C1EA37F4ULL, 0x3282553AEA7AA020ULL, 
            0x04E5848D2B2B8AA2ULL, 0x2476D96D6E656BFCULL, 0x9DCEE6DBFEEC6A39ULL, 0x787528A49017D2BFULL, 
            0x0DFDA12F0C5A3226ULL, 0x01E36FF4EA18EE88ULL, 0x80D3AAA0F0F13CDCULL, 0x64FC40DFA2C5F175ULL, 
            0x865F38D6BFD2AC55ULL, 0x68459ADDBC8F5BC7ULL, 0x8474D484EC7EBFC8ULL, 0x5D9427ADC52934BFULL
        },
        {
            0xED87F91010B63E18ULL, 0xA1F622D907D572FFULL, 0xBC7FD187CE400853ULL, 0x58938FDDBDE93439ULL, 
            0x7A943AE696D6C532ULL, 0x6AE6B320234E6D7AULL, 0xAE4BE5FC33CD6BA1ULL, 0x6B48108B30CDFE41ULL, 
            0xFC69DB8A088BAF0AULL, 0xA5A9EAB9404132CAULL, 0x49EF6DB6D81026E1ULL, 0xCAC1AFC0B4184F8DULL, 
            0x06884B681DF9DFC4ULL, 0xDA883159C2257FEDULL, 0xE67C194645D03DA0ULL, 0xE93F648265E51E37ULL, 
            0x0772D9FD922F4526ULL, 0xEDB28A242CE42C48ULL, 0x11CE6287C38E7BBFULL, 0x1BCDDB0D078D6837ULL, 
            0x7B4D51C3E7653732ULL, 0x0FF866CEA0DC45A9ULL, 0xDD8A555B2FCC6274ULL, 0x9CD2F8031933C54FULL, 
            0xD21040B555E787B8ULL, 0x231136C467CAA4C3ULL, 0x9990E0B9E429C7A7ULL, 0x99F80BD90A81736FULL, 
            0x67FE0A1C3114B567ULL, 0x2D332205C02C1289ULL, 0xF6138B1CA202D3C7ULL, 0xD705C4F3BA2CFBCCULL
        },
        {
            0x16459B040744B3DFULL, 0x97CBE09D70E43D89ULL, 0xAB9ABC0B52DFB987ULL, 0xCCB50965FCB90C64ULL, 
            0x5DB9426D22FDEDB3ULL, 0x1455C00EFB97F2D7ULL, 0x3A2D9D29FA1EB1CDULL, 0x476E41FB1570C9A9ULL, 
            0xF6A736506D47645EULL, 0xBB289A3EB8E518ADULL, 0x86F4247DC7FDE982ULL, 0xACD44DAAC33D964EULL, 
            0x9CF7CAB5D97BE3B2ULL, 0xF4E5C32056DFDC2CULL, 0xAD340B4BCDAA970DULL, 0x141F5D88D1C6EB90ULL, 
            0xB7694AAD1A27B3C3ULL, 0xE8605E8C45B228CDULL, 0x774A7E243270CD41ULL, 0xBB426BC010EDF9D5ULL, 
            0x89E2428E9D2E3BB6ULL, 0x969E6E033AC7F843ULL, 0xF48805AF81AA7C25ULL, 0x70CC567280D30C0BULL, 
            0xECE5E125F5E63053ULL, 0xC2E7E4EB6BC4BC0DULL, 0x219276CD548A00CBULL, 0x6071A04201669EB8ULL, 
            0x4E52F150DE16FA93ULL, 0x04EA5E2FEFEE6531ULL, 0xAB375B437342E107ULL, 0x8BCDEBF6A4710E6CULL
        },
        {
            0x5092B3F69067F9DEULL, 0x1F1A85C988D8502DULL, 0x2A45F27A49CE2198ULL, 0x1E4AC6987AA7CB74ULL, 
            0x8723196CAFD8920DULL, 0x31F4196ADD21C6CCULL, 0x0094613A55F0C1D2ULL, 0x9A99BBF1524EFF40ULL, 
            0xF598AFF8BF2257EAULL, 0x06A71965FA18C45DULL, 0x2FD852334F4846AFULL, 0x603B30A48A32B6D5ULL, 
            0x0E5D0061F4AC664DULL, 0x3A44C3D56C3623B9ULL, 0x929310708738E203ULL, 0x6A2B003F99EB5196ULL, 
            0xFA3D31123B305F79ULL, 0xC12CB769531AFC9CULL, 0xD2D7C9F211EAA454ULL, 0xF23123AD55A2E98DULL, 
            0xE35B305F772D2818ULL, 0xFDFAB06E1CA5DFEFULL, 0xF4871C2120F08B72ULL, 0x33FDDBD34265993FULL, 
            0x78094BA4EE4D279DULL, 0x2C0532D8F3C0F948ULL, 0x48C4532F81481CCFULL, 0x68A3669D9A9F61B7ULL, 
            0x4C77CFA2D1F86FADULL, 0xF308766585822928ULL, 0x7C45A95126D3F481ULL, 0x746E8294F074D360ULL
        },
        {
            0xDC11BE304F1A55B5ULL, 0x561D011727E2A427ULL, 0xBC2D4AAE25592A05ULL, 0x4649D6882C08819FULL, 
            0xA04C96904202A2B0ULL, 0x953217AAB107F911ULL, 0x0613EBB58702F710ULL, 0x7299764EB5F465C7ULL, 
            0x906481814AD70336ULL, 0x8ACD7D0E74B79F0FULL, 0x1C4720C5534864D1ULL, 0x4C7F2C286B3887D4ULL, 
            0xBB26B510AE8D8C01ULL, 0x810FD7A8EB52CCFFULL, 0x63F88D868DD83AE6ULL, 0x4679463B429FFA83ULL, 
            0xE66CCD1BD7D650E7ULL, 0xA476AF7DA70B011FULL, 0xEF9B6F652D3196A5ULL, 0xD0497D3890DD790CULL, 
            0xC89CA265C51D26E3ULL, 0xDD99EE56404BB7D6ULL, 0x8C6121C651462441ULL, 0xC5A26BEE7C9EC11FULL, 
            0xA82AFCC67406ED3CULL, 0x5C08B8D69D629494ULL, 0xB9A011B4F7075FA3ULL, 0x1B44EB2292C399F8ULL, 
            0xB27EA056580F33D7ULL, 0xA76499F9A10D4641ULL, 0x56FEAE5B83FFBEF3ULL, 0xA555FE27DECD8474ULL
        },
        {
            0xDBF97FFDDA5B55E8ULL, 0x84A97E5FDE5ACD8EULL, 0x041FF4F23242811AULL, 0x7889088441155D49ULL, 
            0x551C355929FDF28FULL, 0xD2FF8B59FFC0B9EBULL, 0xCC2DB0E0D38131D6ULL, 0x3B5F39D512105DA2ULL, 
            0x21E675C704C877C3ULL, 0x4E8C94440899F5FAULL, 0xAAF2811BD4A1360DULL, 0xD07830C25F43F9ABULL, 
            0x883A06D5634B01E9ULL, 0x7AE33DC8CBE3316FULL, 0x2D775F6F82A19770ULL, 0x3FC21F3D03131311ULL, 
            0x06BF1778524E7855ULL, 0x895197DE569A788EULL, 0x9288595E49B644C9ULL, 0x9C623BC0ECF2CB93ULL, 
            0xC74B2A73A09C0B07ULL, 0xF9A01B02F3BA7EC5ULL, 0xCF7FC698EA9201E8ULL, 0xFB60F76823972D06ULL, 
            0x070873A0D9B662F4ULL, 0x13ABE9790A3E4651ULL, 0xCAFE41F27659AE3AULL, 0x9AE2AABFFA1BEE7FULL, 
            0xEB32A2CAFA2201ABULL, 0xF88EA0444C88F07EULL, 0x39342FE494DC6C54ULL, 0x78C3C0786F6AE93EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Betelgeuse::kPhaseCConstants = {
    0x5739C53F2B8511F1ULL,
    0x2E563739B97961B9ULL,
    0x88A627F4208303CBULL,
    0x5739C53F2B8511F1ULL,
    0x2E563739B97961B9ULL,
    0x88A627F4208303CBULL,
    0x543569C6B5ED2763ULL,
    0xF0E66733B4C938BAULL,
    0x2A,
    0x04,
    0x91,
    0x56,
    0x8A,
    0x03,
    0xC6,
    0x27
};

const TwistDomainSaltSet TwistExpander_Betelgeuse::kPhaseDSalts = {
    {
        {
            0x62CD16F586EFD888ULL, 0xF28DACFDBCE8F413ULL, 0xE81E7D3317ABCA1BULL, 0xEBDD8A355DA15462ULL, 
            0x76F332B896A4AA8EULL, 0xC89D95054C417F22ULL, 0x5275C32EB7D86108ULL, 0xFA2BBB165A8F626CULL, 
            0x404E549AF223C767ULL, 0x9472AB7F695FE2FDULL, 0x39884F5D6413B152ULL, 0xDD221F3303F5B575ULL, 
            0x738DB95974FEDC67ULL, 0x93798EBA4D871E25ULL, 0x6BC236BF4E4D3C07ULL, 0x10A1A72F25D7831FULL, 
            0x74FA5577B4832198ULL, 0x0D901AA28BF16132ULL, 0xC49091815C33894BULL, 0xF4A184CABC237BFEULL, 
            0x5B4B7EBF7561D2B5ULL, 0x48AAE1E91E71B7E5ULL, 0xFE31363D71F91147ULL, 0xA39DBD9FF52EA192ULL, 
            0x6A1872EABD24CA23ULL, 0x3A9CACFFE766F39CULL, 0xB00DAEDCB4B18978ULL, 0x52D982ACB871D08AULL, 
            0x580C8D16FDAB7EE7ULL, 0xCFA0066E2B9E4F72ULL, 0x7057D8C5B61B3D94ULL, 0xBC5B86A9707D1A2AULL
        },
        {
            0xA39EC764CB691F06ULL, 0x25F4F771C741FCDCULL, 0x6FB052A42D00D844ULL, 0x178507AE1168A7D0ULL, 
            0xED27F522A211A2FAULL, 0xDDBAA7A15C71DCBBULL, 0x91F9156DE56165F3ULL, 0x3BDB52EF2812BC8FULL, 
            0x4740D56D9C76D3EAULL, 0x671CC6C3AE31B8CBULL, 0x816B127008ED358FULL, 0xEF03796FC14181B0ULL, 
            0xE9EB04DE56474068ULL, 0xE2C91A2CC1E7E009ULL, 0xCB94FB9D5ABFBE16ULL, 0x0F46E3670C630F26ULL, 
            0x8219E6476795690CULL, 0xE2155F7C0F902FD6ULL, 0x491D0299381AC180ULL, 0xFA60336828064749ULL, 
            0x96D60BD24D2B5DE9ULL, 0x097F1B1A81C52ACFULL, 0xDF5FE562CBC389D7ULL, 0x1625DF17A5893ABBULL, 
            0xFF14A9EFD43262E4ULL, 0xCE6EED27008D01C9ULL, 0xD4D06AA468ABAD0EULL, 0x2A9456C76BC33A62ULL, 
            0x9072B6F54B2A931BULL, 0x9046683D97E19636ULL, 0xBF7CD28B70985E2AULL, 0x404CCBE1B53D96C9ULL
        },
        {
            0x6B8A8DCB625FD6FCULL, 0xB401A6784C23A3A9ULL, 0x9AAF5B86A26F45BDULL, 0x0E5575D0E0D480A4ULL, 
            0x961284C5768DFA07ULL, 0xF298AC814137BE36ULL, 0x15BF8936637B01FDULL, 0xC495D079691984C3ULL, 
            0x0ECD9F7D346D7D85ULL, 0x98B2816F627ED720ULL, 0x437ACE5FFA78659DULL, 0xC65F4C3A12CB6323ULL, 
            0x04946A04CF80DDE8ULL, 0x7BA4A7DE41D31EE3ULL, 0xEA3E49F0C9270DB6ULL, 0x9199BA67F2C72E87ULL, 
            0xD437DFF944932FC1ULL, 0xC9E19EB20230D4D2ULL, 0x9D6371C576594A35ULL, 0x6589EAE931BB9B1BULL, 
            0xD1203B74F784D029ULL, 0x0CF3B7D87A2AE400ULL, 0x15D54340AE79E19AULL, 0x2183F9639E7A0F42ULL, 
            0xBA13BE166C417F36ULL, 0xA58FBECA8462886BULL, 0x6DD0D13C984D9A9DULL, 0x085A8054D48EA156ULL, 
            0xAE4A59050FAE11C7ULL, 0x11CD103F97A595E5ULL, 0x5851B97BD5FDFF01ULL, 0x79F30ABCB9C7105BULL
        },
        {
            0x5889D71057248596ULL, 0xEE229998CEE72F91ULL, 0xE2C091DE0416D470ULL, 0x275E1B94C6C37EA1ULL, 
            0xAF37FC7E5888C683ULL, 0xECD2DD51A4E6DB87ULL, 0x2C630ED86A14BE50ULL, 0x251B140A974E8A4CULL, 
            0x3E441FF2253DF2EFULL, 0xA7B6E1D506AFA730ULL, 0x536D3C7DDDCA0586ULL, 0xCED929D2133F2954ULL, 
            0xE815C93969167819ULL, 0xC25BC70AD7447052ULL, 0x61AA9F684172814DULL, 0x33B8D10740D4334FULL, 
            0x3EC82218B6D13C7FULL, 0x86BCB4612A903F17ULL, 0xC9C81CDAE22FA318ULL, 0xE03C16FFD4FC959AULL, 
            0x3E5FE5D238951EDFULL, 0xA6B8F4300432190FULL, 0x92D83BB24213D58DULL, 0x795DE626131AAE0FULL, 
            0x16C0E7B21893063BULL, 0x639CB913921C03A7ULL, 0x6655B8E6AA9AB815ULL, 0x1AFB269A8F3E1DDEULL, 
            0x2B94A441B7CEB0A0ULL, 0x67E26F8F4A9C3DBAULL, 0x7AE43151B909611CULL, 0xB4DA51DFCA371E67ULL
        },
        {
            0xEEB9743E83089616ULL, 0xCDC3DCD3A11DE0F3ULL, 0x37336B15FC76B36FULL, 0x5E9939853416F7EDULL, 
            0x6454DB0A03C9BDC1ULL, 0x2E70E048B052932FULL, 0x6E9E7FF415838B8CULL, 0x95D15C765E4C8F99ULL, 
            0xB081D41682377D42ULL, 0xCBFB90B079CE8D22ULL, 0x3DFB183B9EB9AAB5ULL, 0x932D96FE08A031D5ULL, 
            0x42E856FB6177676EULL, 0xA02BEFF1ECFCF362ULL, 0x76F3C01A5EADF15BULL, 0xF721162AB43B0293ULL, 
            0x8F92A2EF00B453AFULL, 0x359A698D7CDF8133ULL, 0xFB01A501AD792DCCULL, 0x328510EFCAE2130DULL, 
            0x43C5BFFEBE545D3CULL, 0x17392E818E19E3FAULL, 0x2F062EC77D3DE178ULL, 0xF8916F89D740B716ULL, 
            0x6782161951DDDD74ULL, 0x481264AE9695B7C3ULL, 0xBB9A78B0FF448ABEULL, 0x73B8C0897CB76E3BULL, 
            0xA501222BC327F506ULL, 0x554A6312DCAAF0F9ULL, 0x7A35E970330809E2ULL, 0x686936253E5BBE42ULL
        },
        {
            0xD7C6941989E90EF6ULL, 0xDBFECEB7361AADEDULL, 0x1BF62849EB010520ULL, 0x9276FD9890CBCAD5ULL, 
            0x35F270C9C33EBF00ULL, 0x73525301CFC436FAULL, 0x9B7A24AAF2E3DBC3ULL, 0x7E7963CC2F0281D3ULL, 
            0xB922D1470B7055BCULL, 0x52FEED1201203F5CULL, 0xA0C9CA2D0665AE61ULL, 0xF11CC001B54FEB55ULL, 
            0xE97AFBEA72CF54E0ULL, 0xCCB31D76B48E8E09ULL, 0x91019006BEA88C69ULL, 0xB07915FFEEB6E37CULL, 
            0x50C244514CFB80DDULL, 0xE62948DA7A2C7877ULL, 0xF6F5CF22C9C74F79ULL, 0x1F7F0C8142458512ULL, 
            0xA2297C0E23C5A0CFULL, 0x3EA7FAFE2C359C57ULL, 0x7F0E13AD7A7F7B67ULL, 0x9E557F4AD056E739ULL, 
            0x9D4AAC73B1AE84EAULL, 0x693719664A075760ULL, 0xAA6BCDB161716CC4ULL, 0x32786CBEFE64207EULL, 
            0xE91E29A493797958ULL, 0xC2587EBAD8909EEBULL, 0xB3F073D56AE77EB6ULL, 0x48806D23C0AA2503ULL
        }
    },
    {
        {
            0xC9874795F3142582ULL, 0x0276957A4297F7E2ULL, 0x68659B41EB5EC6CBULL, 0xCB0387FE087339E2ULL, 
            0x49692904C704DE01ULL, 0x39E7BDE3D563BE53ULL, 0x0A9163CAA31C7365ULL, 0x99AE63B67CF9666EULL, 
            0x458C3A3DD76A0EF4ULL, 0xD646CE43A4FD498DULL, 0x1CEE6D1990C55437ULL, 0x5B8F8E6A368E1DC7ULL, 
            0xEAAC02734ED011AAULL, 0xF49C6E521A5BBEF3ULL, 0x1D69151D5781C266ULL, 0x5494BFCF8720A808ULL, 
            0xADAA2C47BBBF7B21ULL, 0x06A3747BD647C59CULL, 0x3EF27F343C6EE611ULL, 0x273F8EC3C6FCCA0BULL, 
            0xA023EC1327564BB6ULL, 0x056DBB00149AA127ULL, 0xA654CAB71BC2CD26ULL, 0x8FE21F49BCE39366ULL, 
            0xD2E4E9F93253B211ULL, 0x289E3D9F5E57EFA4ULL, 0x2939D9F7912550A0ULL, 0x2C7C1E71559E5981ULL, 
            0xD4A91664CC374F87ULL, 0x321F543D4D91B5EDULL, 0xDF3F7432EE06DE34ULL, 0xC141C603B115AA60ULL
        },
        {
            0xB20A15E76427BE8EULL, 0x7F750EE60BC874B9ULL, 0xE61335063C7B9FC0ULL, 0x2685F6B83F905264ULL, 
            0xD1E0949950E05DD9ULL, 0x8AFF9A39979ED78EULL, 0x83A914BE73FB368CULL, 0xD3EB2342B437FD2BULL, 
            0x8C62B71917C48D8FULL, 0xB20406AD603731BBULL, 0x95766C15D2429C9DULL, 0x634FE7E9AF3B39D7ULL, 
            0x39FB2FD7D30016F8ULL, 0x8BB4C9A9E85FA63EULL, 0x439C17850ECA9EACULL, 0x85DA51CDB33EC05DULL, 
            0x9E9959E9F707470CULL, 0x7CB2CE8875858B25ULL, 0x4A50A2358D132D14ULL, 0x9E0A995ED7B927C4ULL, 
            0x1B23F5EF3F4A9AFDULL, 0xE501E3E2369281D1ULL, 0xA91C9BD691C75720ULL, 0x2A81E82EC4848318ULL, 
            0x920C51577FC7D8CBULL, 0x95E03A20B667CE2CULL, 0x93BE87967C60D10EULL, 0x150B574AB6CCC8F5ULL, 
            0x6D5DE9E701DEC56FULL, 0xC840A9449E19B396ULL, 0x584E99848064FE17ULL, 0x8489D38C0D372412ULL
        },
        {
            0xBB2F028FCE8A4ED7ULL, 0x066E770075216E41ULL, 0x3440E8B506406710ULL, 0x43E549FC7E784589ULL, 
            0xB7B12262EBAD0917ULL, 0xD7E4C1AD53D755CAULL, 0x043F50338EC2C984ULL, 0xE1AD5E0D556ABF75ULL, 
            0xDCF1D64A94FFC7E0ULL, 0x80CD000FF8997B96ULL, 0xD1BDBAF0E0A23710ULL, 0xC6164AE81FC8D669ULL, 
            0x5F81AE82F34251BBULL, 0xA7C9855020AABF96ULL, 0x7B29F5D6499145E7ULL, 0x6A0FF83D8A666978ULL, 
            0xEA4854F0316B9242ULL, 0x2C6E127987ADCBABULL, 0x749A94582B3A932CULL, 0x1D2162950DF39E2EULL, 
            0xEE00BD15A9B1E568ULL, 0x6B130F4F2F352E21ULL, 0x9B20748016198D0AULL, 0x5EFA1A9C5004A6C7ULL, 
            0x80080437814762C6ULL, 0x6F6EFD7773D08F23ULL, 0x680BA8789A56FCA7ULL, 0xE510BCC17661701FULL, 
            0x448ACDCB848F85B6ULL, 0x630C331D4836E183ULL, 0xBD6DDC1F9D330D7AULL, 0xB82D1D475614DF99ULL
        },
        {
            0xC3844341A424CE49ULL, 0x07F6BB561BEBABCCULL, 0x5751FB14FB9DF931ULL, 0x09BFCAE7ED8776FCULL, 
            0xC1D03009D54B5AC7ULL, 0x713DEF8948F0960EULL, 0xA7DB7C1C55A81F71ULL, 0x70A085E38777ECDEULL, 
            0x5718EADC6E51DDC5ULL, 0x675ABC89D56FEA88ULL, 0x448DBD185E275FB9ULL, 0x779ADB197EA22EEDULL, 
            0xF107B7166435B656ULL, 0x29972C010B290408ULL, 0xAE424C84B9D131ACULL, 0x83757778C50C8233ULL, 
            0x5EF7563F35748847ULL, 0xE2E639EA610532F4ULL, 0xB4711FED34513FCDULL, 0x495E298A30F5111AULL, 
            0x70F7CAD511A28E11ULL, 0xE0C91470FD979A46ULL, 0xCA05CDB24C5084DFULL, 0xBD1A26C2C9E7A4B8ULL, 
            0x5645418D2ACDE991ULL, 0x061AE648BF183D6EULL, 0xC9F87F8FD69E97F2ULL, 0x59A6CAD3D2B060CAULL, 
            0x4CFDC3C5A5DDDCF2ULL, 0x9ABDC1582EDC5A30ULL, 0x5E37F94B84897E4EULL, 0xE3A84A31A8E0D2CBULL
        },
        {
            0xBDEB9078EBBC5D8BULL, 0xA01E456E4BDE45C1ULL, 0xCF923E17C38C8E97ULL, 0x31AE3F1A0E16C6DFULL, 
            0x1DB2F4093208DF35ULL, 0x756AEA11799204EEULL, 0xA9C9742882CAAC86ULL, 0x77D7035ED7222242ULL, 
            0xAD41ECC87F5CD222ULL, 0xEF444604838AF4CFULL, 0x13AFE9255292C195ULL, 0x585F2A6CC87597F0ULL, 
            0x01274396E221ECE2ULL, 0x7590727DA1F518EFULL, 0x3E8D2C80B062685DULL, 0xF2DA892B38C207F6ULL, 
            0x5FEFF1155E68C154ULL, 0x6F9E7E7A15BA35B4ULL, 0x10393E8B6125E8DCULL, 0x6DE02E12ADBA6203ULL, 
            0xA17609CEC6F65F1AULL, 0xF2089158AAD0296EULL, 0xE4F1470F1F84454FULL, 0xD156C5763EBB3506ULL, 
            0x9942FED3D520C839ULL, 0xBC2FE893F7DB49E9ULL, 0x57FFDB9A5BF051CDULL, 0xD397BAD51D9A6625ULL, 
            0x0DDC1CD9233A9F28ULL, 0xF6C6F4C1DDA04B6AULL, 0xB68EE16236AAE392ULL, 0xACC74A3B256AF6CBULL
        },
        {
            0xBF3D5A4B923B3792ULL, 0xD998C0973BE8C4BCULL, 0xE3F7F5076AF4CC9EULL, 0x8DEE41090115DD84ULL, 
            0x7929316445E104C2ULL, 0x0431F992C3A8770FULL, 0xC96708CDFC2A1B1EULL, 0xAD12157EF125572EULL, 
            0xA3918A39FE8569A5ULL, 0xC03C4F6BCBD0C64EULL, 0x104D4C205B72F86CULL, 0xBFACFE4B8F4C4F48ULL, 
            0xCB77C523A1EFDB59ULL, 0x20D9D9C71C7FEE08ULL, 0x66A3361330B68DA8ULL, 0x8DA7015291FED221ULL, 
            0xFB97F55F01F783C8ULL, 0x5B403507C9C351A2ULL, 0x79781A68E4A523A6ULL, 0xDBAF28FE6BC78F37ULL, 
            0xE15E978A4158C634ULL, 0xC5B9CCA2D0B3880CULL, 0x12A134DE59426FC3ULL, 0x79E192657568ED2BULL, 
            0x62373FA6ECA8250FULL, 0x6A0435697F4A31EFULL, 0x8B21A08264A0A5C6ULL, 0xA121CDD9255F51EAULL, 
            0x4FCFD5ECB1A22735ULL, 0xA31F12BA81E21107ULL, 0xD7D453361FDD2F84ULL, 0x285816E1E431BFDFULL
        }
    },
    {
        {
            0x60D351DD4B456BAFULL, 0x008CC39F7A54A699ULL, 0xC53E70EE186BF81BULL, 0xDFA2C8B2441FED14ULL, 
            0xF7293FD4FEDFE76BULL, 0x7E39FACFA7C0BC6FULL, 0xBEB9047173CB448AULL, 0x68694CAB030A3C4BULL, 
            0xA6562A96E67AF6BEULL, 0x7595896BB4D22E05ULL, 0xC4FA605EB1C1F036ULL, 0xC129E64A0B019DA0ULL, 
            0x47014F980D00EF2BULL, 0xF2BA9860752B797AULL, 0x44C30A912791CBDDULL, 0x1267D10A00769B26ULL, 
            0xED3A0FA11B93B865ULL, 0x67DF602B230BE8B3ULL, 0x284E394855A2282EULL, 0x4B0DE3FA0D923812ULL, 
            0xBD11B1CC8C21E6C5ULL, 0x4357126AABCC1709ULL, 0x037E64DE39FEC0EBULL, 0xE9325623AFDB2471ULL, 
            0xA287B47A2EC304ECULL, 0xECC65344C43E76E6ULL, 0x145D0352AA3A114FULL, 0xBF1F544EFF7925E6ULL, 
            0x8640D3596BAB2816ULL, 0x9DC6B94008D280AEULL, 0x829A3AEA3EEB7C4EULL, 0xB03906CBB251B3B2ULL
        },
        {
            0xB64826289F9A2A15ULL, 0xCF3CFB0367FFA3D2ULL, 0x9E23E19832A25A91ULL, 0x9A01DFA230CEBD44ULL, 
            0x24A7AB5D8794CE4BULL, 0xDB39BD87CA1D0884ULL, 0xC757C0207A3D7094ULL, 0x1B2B07D996EDB265ULL, 
            0x4F7B3834DA1A2337ULL, 0x5AAE6BC9F677855CULL, 0x6E80644A3A32ADE2ULL, 0x61968AE84680B9B1ULL, 
            0x94C78B19E68C8E2FULL, 0x2A5AAA887DE34FEBULL, 0x4ECD3749CF02BA69ULL, 0x44C267BAE31921CCULL, 
            0x32937E35B47C8DBCULL, 0xDCB68B026C93309DULL, 0xB5422BE7E05E8C57ULL, 0xABA1681AFFA17742ULL, 
            0x6995A4C8A37790A9ULL, 0xB6A7DFA2D5C46BA2ULL, 0xEDAC43C13C42B721ULL, 0x5F21BED50E6FF46DULL, 
            0x5CDF321D646F1564ULL, 0x29342B99FD7C8AA7ULL, 0x6312F7CEC40AC445ULL, 0x66421057A2AC5D94ULL, 
            0x512122C5C8F73A41ULL, 0xF71D7D095C08E5A2ULL, 0x93FC287BE0C9658EULL, 0x2A91FEFD4EFF1197ULL
        },
        {
            0x4FE704BFAB33AE7BULL, 0xF074826132F21EF8ULL, 0xB0C35FF7F86B98AFULL, 0x4967151BC8098054ULL, 
            0xFFC1E80AFE8AA952ULL, 0x26D09D119C470D02ULL, 0xB4B659CCAB2F18FFULL, 0x691F20F2371D3D9BULL, 
            0xD5DCC3D23D6E7082ULL, 0x5584D6964A1F1EE6ULL, 0x1919848FB68D564BULL, 0xBA39C6FB1AE48BCDULL, 
            0x20A6A86F09554A7DULL, 0xAAA2D9295709CE6BULL, 0x34DABD0F269FBD73ULL, 0x1D0DC33428E63769ULL, 
            0x8F024A2F6959E5C1ULL, 0xC425577DD047279BULL, 0xC2F1B6B5380AAB70ULL, 0x95648236481A7D07ULL, 
            0x83DE7B3BDA2E5265ULL, 0x4DEBBD4BEA92250FULL, 0x9266AE6C4B87C225ULL, 0xDF33F6B01EA36AFDULL, 
            0xFEFD06BA2B2C4878ULL, 0x31B5B86DD88A2502ULL, 0xF2F323B804B46D08ULL, 0xF30FE64B1BAC8FFAULL, 
            0x8FE25AD546DF8179ULL, 0x655B0D02AB189A7BULL, 0x80783427658CFCAEULL, 0x1BB614AC15D606ADULL
        },
        {
            0x99E50235B2EE3D23ULL, 0xE2B3BEF597C73706ULL, 0x0451728659BFAA44ULL, 0x65F5F7FF8B34449BULL, 
            0x25D1ADE11B0DD333ULL, 0x921A7A2F80FD9AF5ULL, 0xF497CC16B1699C47ULL, 0x62E454A69F9F0A5EULL, 
            0x447F9972F14A70FAULL, 0x6A09F1F936F28318ULL, 0xE8967A6644359B8DULL, 0xF666485502522C46ULL, 
            0xD287FC0CDB288E54ULL, 0x163F9857D991359DULL, 0xCA589C20B583CFF2ULL, 0x41C2A8584CF6FDFEULL, 
            0xD04E7680192B3642ULL, 0x517C79799162C8AAULL, 0xA8D7D7123BE10153ULL, 0x7A3BF96E27AA4179ULL, 
            0x78407DD1E061CAA6ULL, 0x90431F2C572691F5ULL, 0x5AA614670C25E1F5ULL, 0x1E9EB92382DC58BDULL, 
            0x2F974D27FAA028C5ULL, 0xB6F23D911DF3A238ULL, 0xA051C50196CBE6BDULL, 0x8159E3119E095C3CULL, 
            0x1F733DDD59193CEFULL, 0x973212493A3FC589ULL, 0xD32DB72ABB8EEC87ULL, 0x8157BDBBAD737925ULL
        },
        {
            0x860834FDC20A4C9BULL, 0x5F85D6A02E5422FEULL, 0x30A7F493D05E6AA3ULL, 0x10B3C69D55288FDBULL, 
            0x47098BDAA39826A1ULL, 0x280187C265A1F952ULL, 0x1F04FB1B0BB604ABULL, 0x5A69A667A0CB2543ULL, 
            0xF3235E558C41E050ULL, 0x0E6C1B0473F8C27EULL, 0x074EB9104798B42AULL, 0x10DF972699F96E60ULL, 
            0x7AA7CFAB0D18C1C3ULL, 0x09C4A3D80347F90EULL, 0xF38C94BD831C487EULL, 0x5288F738096F0D2CULL, 
            0xB4CFAA95F3A0B265ULL, 0xB7BFDD43777ADA5DULL, 0x58C739DBBE3D4ED0ULL, 0x0309EC06901039E7ULL, 
            0xC7D6859A1E3D9D34ULL, 0x09BD8BB57139F1F7ULL, 0x146B98579B1BD38AULL, 0xBCAF8B0197E593B6ULL, 
            0xD1F3F3F947C94ADFULL, 0x93D23F48B6F0CF5FULL, 0xDCC1D704CCDCEDB0ULL, 0x61CCCF0596E2383DULL, 
            0xA122E69A3B594B33ULL, 0x8588AC850E157694ULL, 0x73775C25F3673A3DULL, 0x0F7AE1706341EC2EULL
        },
        {
            0x234191C51984D150ULL, 0x4AA6257F60FD2A1BULL, 0x12CAB6F840E45798ULL, 0xBB0529C0FE8AE0B5ULL, 
            0xAFD21000255370CDULL, 0x2BDA0C6C1C2FFFF1ULL, 0x71F70F8B4390D8FDULL, 0xFC68950188F55FC6ULL, 
            0xFDB2713B078B76BAULL, 0x3C3D456379146D6CULL, 0xEDC9029FB571610DULL, 0x4759F8127BE3E044ULL, 
            0x5826E6C471682CACULL, 0x0AE3249DDB4B51D2ULL, 0x689E2ED5C0FF745FULL, 0x7B3E854628CDC55AULL, 
            0x09CB1430BC91CE88ULL, 0x8757E8EED07560D0ULL, 0x0B8F84C93C5FD432ULL, 0x7484BB4583129E0CULL, 
            0xDAD62E09BE19D0BEULL, 0x6461AA644335B76EULL, 0x5B6DE571460C6B20ULL, 0xB275EB241EE48F2DULL, 
            0x7A7D7FD69AA1BA5BULL, 0xAA67434BD0758138ULL, 0x15EE69436ABAEC65ULL, 0x387A0BD79C96FCD4ULL, 
            0x7D4C1D096B373571ULL, 0x4567F97D5336D6D2ULL, 0x2C708902007920FAULL, 0x552DA744ADE5B233ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Betelgeuse::kPhaseDConstants = {
    0xCB1E61ED0C164F5AULL,
    0xF199CDB20A10E653ULL,
    0x72388F23B0D28B84ULL,
    0xCB1E61ED0C164F5AULL,
    0xF199CDB20A10E653ULL,
    0x72388F23B0D28B84ULL,
    0x0F945F7C81D316D5ULL,
    0x1A324C090568AD7EULL,
    0x09,
    0x22,
    0x9A,
    0x36,
    0x7E,
    0x3D,
    0x9B,
    0x06
};

