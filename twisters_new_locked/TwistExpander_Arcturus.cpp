#include "TwistExpander_Arcturus.hpp"
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

TwistExpander_Arcturus::TwistExpander_Arcturus()
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

void TwistExpander_Arcturus::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE50BC3D6EC0B2F0BULL; std::uint64_t aIngress = 0xB1A1F3CDF53BC7C2ULL; std::uint64_t aCarry = 0xE5D949FC452CE2E7ULL;

    std::uint64_t aWandererA = 0x98C10499B2DC7FA6ULL; std::uint64_t aWandererB = 0xF9EF3504E37ADE92ULL; std::uint64_t aWandererC = 0xBBC3D76727C9B80CULL; std::uint64_t aWandererD = 0xF697296C7169B9A1ULL;
    std::uint64_t aWandererE = 0x8F97CE1D944811D5ULL; std::uint64_t aWandererF = 0xE8EAB8E7042B3045ULL; std::uint64_t aWandererG = 0xC173D2CA1D998700ULL; std::uint64_t aWandererH = 0xA4070E5A1CACDC90ULL;
    std::uint64_t aWandererI = 0xDB68329C6448E35AULL; std::uint64_t aWandererJ = 0xF77AB383FA2A3A26ULL; std::uint64_t aWandererK = 0x873A9785FB2E7AF5ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x9184D57C938893C0ULL;
        aCarry = 0xADB99C119B78A5F3ULL;
        aWandererA = 0xB9E163EEB544E68CULL;
        aWandererB = 0xEDE37FC10A1101F6ULL;
        aWandererC = 0xB28B7B3E23D0E291ULL;
        aWandererD = 0xB619F469C5A2F835ULL;
        aWandererE = 0xF039F1F3369217E8ULL;
        aWandererF = 0xBB60A32744D91F7CULL;
        aWandererG = 0xF69E5ECF4449C93EULL;
        aWandererH = 0xA82A7D2C9A6053A1ULL;
        aWandererI = 0x84AABACE1A23A527ULL;
        aWandererJ = 0xC19EAEC715711860ULL;
        aWandererK = 0x8EC58336D6574C61ULL;
    TwistExpander_Arcturus_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Arcturus_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Arcturus::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA6C09FE579C3C60DULL; std::uint64_t aIngress = 0xAA98153C6034820EULL; std::uint64_t aCarry = 0xDA91A31117D32844ULL;

    std::uint64_t aWandererA = 0xA2A25BE05394ABE6ULL; std::uint64_t aWandererB = 0xE100DB20DF425ACFULL; std::uint64_t aWandererC = 0xB8618084B1CFACB1ULL; std::uint64_t aWandererD = 0xC59932DC2BB906F1ULL;
    std::uint64_t aWandererE = 0xAAAD303EAE62A044ULL; std::uint64_t aWandererF = 0xCBB4BFB2AF7C5314ULL; std::uint64_t aWandererG = 0x9026048706D64759ULL; std::uint64_t aWandererH = 0x90DE087F8B31FC52ULL;
    std::uint64_t aWandererI = 0x8A27AC2C9263CB00ULL; std::uint64_t aWandererJ = 0xB334F7CCAB80BB60ULL; std::uint64_t aWandererK = 0xE951701E5BA82CC7ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xFBEB3FFF802596A2ULL;
        aCarry = 0xE746C146C81B5E61ULL;
        aWandererA = 0x90FA32355CB82DC6ULL;
        aWandererB = 0x8E1CD2B101057AFAULL;
        aWandererC = 0x857EAABAFC0CB703ULL;
        aWandererD = 0xD1589218381EA615ULL;
        aWandererE = 0xF3208F3F5DA13AD1ULL;
        aWandererF = 0xE56CC462BC04E3ABULL;
        aWandererG = 0xA73053B0B77090F1ULL;
        aWandererH = 0x928DBD854CB35F3EULL;
        aWandererI = 0x82F0FA0ED92906E9ULL;
        aWandererJ = 0xC6D554AB4B90EC4DULL;
        aWandererK = 0xE49146056C14E961ULL;
    TwistExpander_Arcturus_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Arcturus_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Arcturus::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x8DE809CF79CA90C3ULL;
    std::uint64_t aIngress = 0xF3E131E55B72E878ULL;
    std::uint64_t aCarry = 0x822395C716AE4A4EULL;

    std::uint64_t aWandererA = 0xA2DBB3398CDD326EULL;
    std::uint64_t aWandererB = 0xC9F3CA68D67444A2ULL;
    std::uint64_t aWandererC = 0xF8382126742FE06EULL;
    std::uint64_t aWandererD = 0x8A7F2C4408E052F5ULL;
    std::uint64_t aWandererE = 0xB69DC61C1BE157D9ULL;
    std::uint64_t aWandererF = 0xF03078534406A11CULL;
    std::uint64_t aWandererG = 0xC1DD74B44CD02AD3ULL;
    std::uint64_t aWandererH = 0xE708BF3B652D2F7FULL;
    std::uint64_t aWandererI = 0xB639D2738618BF7AULL;
    std::uint64_t aWandererJ = 0x999BD3FF46A3F999ULL;
    std::uint64_t aWandererK = 0xD8A84641D64D6DF4ULL;

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
    TwistExpander_Arcturus_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Arcturus_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Arcturus_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Arcturus_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Arcturus_Arx::GROW_B(pWorkSpace,
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

// SmartSquash candidate 10 of 33
// Exploration cases: 100000000
// Nearest-family diversity: 945 / 1088 (86.86%)
// Total distance from earlier candidates: 8644
void TwistExpander_Arcturus::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    static_assert((S_BLOCK / W_KEY) == 16, "SquashInvestToKeyBoxes expects 16 invest fragments.");
    static_assert(H_KEY == 8, "SquashInvestToKeyBoxes expects 8 key rows per box.");
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 9U), *aFragmentB = aIceLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 5U), *aFragmentD = aIceLaneD + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 302U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1413U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 755U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1041U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 13U), *aFragmentB = aIceLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 2U), *aFragmentD = aIceLaneD + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 2014U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 405U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1564U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1926U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 3U), *aFragmentB = aIceLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 11U), *aFragmentD = aIceLaneD + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1393U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1619U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1034U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 459U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 15U), *aFragmentB = aIceLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 14U), *aFragmentD = aIceLaneD + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1644U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 774U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1477U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 902U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 4U), *aFragmentB = aIceLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 13U), *aFragmentD = aIceLaneD + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1737U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 21U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1430U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1759U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 5U), *aFragmentB = aIceLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 12U), *aFragmentD = aIceLaneD + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 372U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1026U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 68U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1646U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 2U), *aFragmentB = aIceLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 6U), *aFragmentD = aIceLaneD + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 485U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1540U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1951U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1005U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 7U), *aFragmentB = aIceLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 0U), *aFragmentD = aIceLaneD + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1501U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1972U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 971U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 878U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 12U), *aFragmentB = aIceLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 1U), *aFragmentD = aIceLaneD + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1021U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 795U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 575U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1613U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 6U), *aFragmentB = aIceLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 4U), *aFragmentD = aIceLaneD + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 118U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 101U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 446U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 696U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 10U), *aFragmentB = aIceLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 7U), *aFragmentD = aIceLaneD + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1685U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 905U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 470U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 839U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 8U), *aFragmentB = aIceLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 9U), *aFragmentD = aIceLaneD + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1897U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 38U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 238U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1452U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 14U), *aFragmentB = aIceLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 15U), *aFragmentD = aIceLaneD + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1002U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 256U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 393U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1152U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 1U), *aFragmentB = aIceLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 8U), *aFragmentD = aIceLaneD + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1560U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 674U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1984U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1335U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 0U), *aFragmentB = aIceLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 3U), *aFragmentD = aIceLaneD + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1655U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1962U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 183U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1067U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 11U), *aFragmentB = aIceLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 10U), *aFragmentD = aIceLaneD + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1863U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 604U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1773U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1763U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Arcturus::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xC2D26E992B200F37ULL; std::uint64_t aIngress = 0xCBD434EE16ECC976ULL; std::uint64_t aCarry = 0xCE68EAE3D0153C6BULL;

    std::uint64_t aWandererA = 0xF74BF7B2703F5C25ULL; std::uint64_t aWandererB = 0xA11658BAB1E5A06EULL; std::uint64_t aWandererC = 0xB1D1830BD38631D8ULL; std::uint64_t aWandererD = 0x90D3678C93F478C0ULL;
    std::uint64_t aWandererE = 0xAD5494A883A04757ULL; std::uint64_t aWandererF = 0x8924D4EA2CC47D10ULL; std::uint64_t aWandererG = 0xF44447E37E93CD49ULL; std::uint64_t aWandererH = 0x8F9853EC6D4C1099ULL;
    std::uint64_t aWandererI = 0xF0421E29990260A3ULL; std::uint64_t aWandererJ = 0xB441F09A9C4C33D9ULL; std::uint64_t aWandererK = 0xE79D2D2ECB1241D8ULL;

    // [seed]
        aPrevious = 0xA92C54D551247773ULL;
        aCarry = 0xB8B8F11F7EBD72BAULL;
        aWandererA = 0xB54B3EF7D4E0180BULL;
        aWandererB = 0x86A21C53F585A245ULL;
        aWandererC = 0xABBBA9052DD965F2ULL;
        aWandererD = 0xFAEB9D22410DB346ULL;
        aWandererE = 0xC72BC750DF6AF1C3ULL;
        aWandererF = 0xE5D62A8BC09F82B5ULL;
        aWandererG = 0x87719A8B8212E274ULL;
        aWandererH = 0xD622E9919A88311BULL;
        aWandererI = 0x86D03E244DD724BFULL;
        aWandererJ = 0xD3614EA9B099DFD1ULL;
        aWandererK = 0xE5C4B27954185435ULL;
    TwistExpander_Arcturus_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Arcturus_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Arcturus_Arx::Twist_E(pWorkSpace,
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
    TwistExpander_Arcturus_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Arcturus_Arx::GROW_B(pWorkSpace,
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

// GrowA candidate 10 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 4980; nearest pair: 474 / 674
void TwistExpander_Arcturus::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7560U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2804U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1007U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1997U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2877U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2277U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7509U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 818U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6915U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4183U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1806U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7512U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2466U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5577U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3239U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7358U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1135U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 515U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 325U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 782U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1316U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1010U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 688U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 336U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 885U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 555U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1281U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 922U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1599U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 167U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 292U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 47U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1685U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 936U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 566U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1890U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
}

// GrowB candidate 10 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 4983; nearest pair: 499 / 674
void TwistExpander_Arcturus::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2634U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8038U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2971U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7024U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 788U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4575U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5883U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3137U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2590U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5372U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1624U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3780U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3676U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6525U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3562U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1650U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1181U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1138U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1747U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 27U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 742U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1201U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 732U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 120U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 474U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1107U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 898U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1013U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 984U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 866U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1952U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 368U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1373U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1148U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
}

const TwistDomainSaltSet TwistExpander_Arcturus::kPhaseASalts = {
    {
        {
            0x2E082DEBEB531BFDULL, 0x207459CEE01C0E55ULL, 0x7C7143E736EF0B4AULL, 0x338450707588FC22ULL, 
            0xE75B441D21D1A597ULL, 0x4DA0580F5AC1D7A5ULL, 0x893B36F81580BD90ULL, 0xD1B90FB86055CE9CULL, 
            0x7FCE7B931BAA8D38ULL, 0xA5980F64ACC5AE2BULL, 0x94B91A1E69C5C47FULL, 0xA8A0A7D9D82E28E5ULL, 
            0xBC7D9824AA2E4A67ULL, 0xE3E17832F7841E78ULL, 0xBF370B4EEF603FF5ULL, 0xF641804082C5E82DULL, 
            0x1188BA3460632DC9ULL, 0x1F7ACCC42D65E9E2ULL, 0x2FF0C0F1B51046B5ULL, 0xDF06122C04573F22ULL, 
            0xB92922B4898ECFC1ULL, 0x4EA31D3A8D318DA7ULL, 0x5658940C8D9E3BB1ULL, 0x486853A1D9C16443ULL, 
            0x0F0B8F9E957670D9ULL, 0x0464B734C3D2A789ULL, 0xADC4C8FCD0B4BAD7ULL, 0x0E353FD977BD1414ULL, 
            0x94EF02235198DE1BULL, 0xDD19DF787C5E79D1ULL, 0xFA26907DC9BEBC63ULL, 0x4E0A87ED324ADC58ULL
        },
        {
            0xBAC6B5602AA677AFULL, 0x68240C4A04E94596ULL, 0x307F3E1A90907D2CULL, 0xDF25F0E6E5DAF3C6ULL, 
            0x184D440B91798FF9ULL, 0xB4029F5337B0CCFCULL, 0x69A1902508551719ULL, 0xBD7C8BEE05964DE8ULL, 
            0x6F2C8514D6F4CCF9ULL, 0x7CA4F2A5EC77C1F0ULL, 0x2438C017938340D8ULL, 0x75A1134AF5CD7840ULL, 
            0xB77C02478BF35AF4ULL, 0xCE30070769968D7EULL, 0x06E592A8534ED4D7ULL, 0xF02B37F9C4542734ULL, 
            0x4A107EC9C5ECC895ULL, 0xE598CEBAFD9EC3E7ULL, 0x22EA6056BF45D2F8ULL, 0x77882CF1DC2EA8B8ULL, 
            0x2B0998564AFB174EULL, 0x4247A75628E99749ULL, 0x5D998587D0C4C20BULL, 0x2882C25A0949E198ULL, 
            0x9F5DC7AFC2FA2848ULL, 0x3C67BCBDAF38151FULL, 0x525CCF000D88053FULL, 0x0BF3CC43F3FAF6B0ULL, 
            0x6000B07B99F53ED2ULL, 0x521A585C7ED3197BULL, 0xB64587304952FAE2ULL, 0x89E23EE51738D4AFULL
        },
        {
            0x9E71B2DF6964B5E3ULL, 0x268BAC11EA2F812BULL, 0x5AF15678C495F377ULL, 0xA3F8F39876A2499DULL, 
            0x74A7A0BE5B53B64DULL, 0xC566FF9081BB916EULL, 0xFFC0B8344147C016ULL, 0xBF392AE989D5EE5DULL, 
            0x1EC9F75DEEF9AC37ULL, 0x14AE92B7C88B406DULL, 0xB5459942F7993975ULL, 0xED6436C249A3412FULL, 
            0x3B6A5D4C3DE86199ULL, 0xB9096A497367F016ULL, 0x5754921254CFE08CULL, 0x7008A6C66EE028ADULL, 
            0x3441E9AAEA176E13ULL, 0x6A04BB2824805203ULL, 0x5E665FA090068FEEULL, 0x882B26512016E202ULL, 
            0xE91FF06D9593602FULL, 0xC6183715C4D88299ULL, 0xD26D449363C43588ULL, 0x2CE7AB47BE23B6EBULL, 
            0xA962CA56ED943ADAULL, 0x3162EF3143C04529ULL, 0xB6C8010E17434831ULL, 0x039A2C1F60D71F14ULL, 
            0x15ACBE76573D314FULL, 0xC8B929FE9FF1A68AULL, 0x0BA0B0A339E4FB3AULL, 0x387328F06DCBB77DULL
        },
        {
            0x6043381FD008D9C6ULL, 0xD311A24F3708F9D8ULL, 0x6BED51785FB0F8F9ULL, 0x196CC77ED10E6FB7ULL, 
            0x6A6E074BF0651387ULL, 0x560D356575EA626FULL, 0xA4C05E4CACA11B68ULL, 0xE5BD8B2DFDCE8763ULL, 
            0x6C715A00B5E07239ULL, 0x8F216EE0D51C2BDEULL, 0x40BDB41D2D6B78CCULL, 0xF126998C2F60E6FEULL, 
            0x4CBF4BF01CA6A9A2ULL, 0xAF41B21D215F22C0ULL, 0xF9434ED10F4948DBULL, 0x4AEBEB6CF4309D12ULL, 
            0x46C4DC7127CC5B2AULL, 0x137C3F688B9E4539ULL, 0x985FC46D369D818CULL, 0x737A930C3E4A6A69ULL, 
            0x20668FA2D70B5F85ULL, 0x02D56DF871177B10ULL, 0x9A9DEF9B7B3E05E7ULL, 0x5479256A7816CEFDULL, 
            0x0F482A534F8ACC2FULL, 0x4034299AEDB3C1EAULL, 0xD1574DEC1619692CULL, 0x59DD84002E1E70B9ULL, 
            0x0691F202F4C64BFFULL, 0xB8809F53ECFC944EULL, 0xBEBA64B9708A0A66ULL, 0xE498121442AFE4B7ULL
        },
        {
            0x4231458E2D6CF898ULL, 0x6CE82442E144B0E2ULL, 0x89976D3E98265F31ULL, 0x8278459CC335E296ULL, 
            0x67B2E4987F0B37BEULL, 0x03C524DEC277E302ULL, 0x5D621DDDB164E176ULL, 0xC7B4CDB4DA3369A3ULL, 
            0x1EAFDA0D07922AEBULL, 0x11F8288640DB6FB6ULL, 0x717C85E0CC7FB36EULL, 0x94A08867C3145E48ULL, 
            0x8C0D0053711A0EC8ULL, 0x91D963C26ED4DFFCULL, 0x772DF371408FE1E5ULL, 0xB505566A84C08732ULL, 
            0x3E6B1687AC25DF5FULL, 0xC9A372C6C85AE1BCULL, 0xBB63A1FA51385CC6ULL, 0xCFB35B275A9CF780ULL, 
            0x26A4DF183B36349DULL, 0xA38B9E9DA37458E1ULL, 0xB2A7E4B4D3F85A4EULL, 0xE98C5AE05D8A0005ULL, 
            0x1C2BD7A65FD97D7BULL, 0x4941B3368F4EAB47ULL, 0xB8196312D3CFD975ULL, 0xFB5D8136EFDE8E1EULL, 
            0x240D5D4000E91BFDULL, 0xDC59ABC96575C4AAULL, 0xBB5FFA008A6F8BBBULL, 0xC2A716067560CF26ULL
        },
        {
            0x63CC5AE1E233320BULL, 0x06AE75B53296797AULL, 0xBB096ED538104E91ULL, 0x1D9F1F0E060D84CBULL, 
            0xB204AF12958B4CB8ULL, 0xF5D7BD06D86214F8ULL, 0x12EF645C74413830ULL, 0x2FAC3C227074F97FULL, 
            0xE8962E04A24CEBC4ULL, 0xBB4663D4A38284FAULL, 0x1A963F825B0C04DEULL, 0x30B736634BC7E6B1ULL, 
            0xF6BD5A19ABB50310ULL, 0x7AB12E56092C75D1ULL, 0xD367B4FC4E2DD8EBULL, 0x9D86D0093F65D0C5ULL, 
            0x3C10BEA0B7FAADE0ULL, 0xEA3CBE6DA465ADB8ULL, 0x85036644A9CBB1FDULL, 0xEC07D51528D41BEEULL, 
            0x2EA4403FF70BBC52ULL, 0x33BF889732448CEDULL, 0xC7C0D3FC62E01750ULL, 0xF398201B115C21E2ULL, 
            0x70F1BF1C96413411ULL, 0x069D53B0D0CAA647ULL, 0x7BECC7610039ADB6ULL, 0xC5BB1EF8B0BDE696ULL, 
            0xE630751F5C74EF58ULL, 0xCCC6E8D0D2BF0821ULL, 0xB9347CB94C556175ULL, 0xD7357FDC0B2B8840ULL
        }
    },
    {
        {
            0x47425B90E41C0253ULL, 0x7D6EDC8050B0A1D5ULL, 0x85C2431408DB1F65ULL, 0x3AE7647C0D3452EAULL, 
            0x17AE32E57A643220ULL, 0x5124B594505C8670ULL, 0xEDB622EF6FD836A8ULL, 0x50B044362E784C04ULL, 
            0x26AFC1199CEE6864ULL, 0xC21F5A6E2F332490ULL, 0x87AF88B8260D5E7CULL, 0x90024329F7A732DAULL, 
            0xC228FACC116CCCC5ULL, 0xAC47A441DE3A469AULL, 0x9A968D3824C6CDFCULL, 0x3BE5C56F952F2E25ULL, 
            0x31D408AA570D04ABULL, 0x0CC2AF44EA59BB98ULL, 0x921DD7B26F00BF9AULL, 0xD586B416161C8E6FULL, 
            0x3D1DF628A3E3D467ULL, 0x776DBE3414C16761ULL, 0xBF70AF14C4E476D0ULL, 0xCA03F511DC7BECC2ULL, 
            0x9BC4606EAC2F0010ULL, 0x5AAAF7369B779FB4ULL, 0xED243A6AD322EE6DULL, 0xAE6F7E89A758F12FULL, 
            0x0BEC25801781B2E7ULL, 0x36C768E5FA3DEAA7ULL, 0x80022CAEB61E6AF8ULL, 0x53FA831CABF5E23FULL
        },
        {
            0xF9805E6B833CC761ULL, 0x7D85D9CCC8C64FCAULL, 0x5ED0FF494E8E1BA3ULL, 0xFB93EBE0400E651FULL, 
            0x6A8198C081491CE1ULL, 0xA8DF069FD95C74D8ULL, 0x78AC0907B36DBA12ULL, 0xD05E2CC6EB0842E2ULL, 
            0x03A0FFE30E7BCAF1ULL, 0xB081986D52E101FAULL, 0x0124141E05053E04ULL, 0x72DBDF78CF357699ULL, 
            0x15C638FC30945CEBULL, 0x56D37F888D1093F5ULL, 0xD133E6E9F4F8DC44ULL, 0x0AF716B64BD9BCCAULL, 
            0xD16ED65CAB7E4D09ULL, 0x073395B5DF152CD0ULL, 0x06865B9B72DF72A9ULL, 0x57760F5E23C87B81ULL, 
            0x8A3763D46CC6ECC1ULL, 0x35DBB6E9FF362218ULL, 0x0CA80304C9E69810ULL, 0x65AFD2D580727C51ULL, 
            0xB2A08129A2B02A86ULL, 0x7F3A0E9969E40479ULL, 0xD7F9EBDAC46161AEULL, 0xBA6674ABE2D2B858ULL, 
            0xDAB71275534D7703ULL, 0xDA5D3135A06ACC98ULL, 0xF8E5E2ED90365E47ULL, 0x2AAB55CD8DC78515ULL
        },
        {
            0x0E4F60D776B2D883ULL, 0x065B94F41F934A0CULL, 0xCCE479D11234A202ULL, 0xE98EE995B9A0E804ULL, 
            0x242C37411810A16CULL, 0x6345E79DD8B8D054ULL, 0x4FF21C3973A35DB8ULL, 0xEA0CF9ACCF1F35A1ULL, 
            0x80F9EB4283D8C0AEULL, 0x9F8908787811E852ULL, 0x9BEFD143CD72A144ULL, 0x8E55FF9D8DB94BF9ULL, 
            0x20DB2B217E496915ULL, 0xC19D0AD63DB9C41BULL, 0x4477297BB4265E9BULL, 0x3261C41AAE78F38EULL, 
            0xC413641DBC223E2DULL, 0xC9BF8DF586BE806FULL, 0xB27E2E22014FD19EULL, 0x6B4BB24A2482DC0DULL, 
            0x64FF2B671921443BULL, 0x6EDC005B392181B1ULL, 0xBFFBA7D41A450EDAULL, 0xBF51999542621ADDULL, 
            0x068557CD7FF02A73ULL, 0x9B6CE5EFDC61752FULL, 0x03AF756F3D8336D5ULL, 0xA80214C3D680E80BULL, 
            0x892FCBF505D3238AULL, 0xF20AA72706084CD6ULL, 0xF368D8CF1B514BD7ULL, 0x1D4B93D763969C9CULL
        },
        {
            0x1781C6B2057838C1ULL, 0xA0E7220E68EBF7EBULL, 0x5A0BAF63508808A1ULL, 0x157D860A8102636EULL, 
            0x4185BEAE07896474ULL, 0xEFEF943AD7B36FADULL, 0xE0572F972D863A57ULL, 0xF9DB4E3088B2E02CULL, 
            0xDAC6B47E22EAEC8CULL, 0x290DA3B34F4AD7E3ULL, 0x86E98AC8C900101BULL, 0xA8D468200AEF77CFULL, 
            0xA3F4F6CC745CEAA1ULL, 0x2788621F1B8E5888ULL, 0xB12D64EAC01A5697ULL, 0xB469CA5B5EC58647ULL, 
            0x229D18A0D4F18609ULL, 0x4F758A94C6B4AE87ULL, 0x31EC452BAEC4646FULL, 0x2998F83A475050DCULL, 
            0x54054FAB0D213EADULL, 0x4822D65D1A3554E7ULL, 0xB35B4F097BF86B86ULL, 0xB5EC69E4BE7B9ABCULL, 
            0xB55785F980A786D5ULL, 0xEFB6FD9726104DAEULL, 0xEB55968903D874B1ULL, 0x6CEBA8EC659D985BULL, 
            0xF5E5A3922146931BULL, 0x8C753FBE17C51BB7ULL, 0x806C9336E9130928ULL, 0x9D741583DC8CACA6ULL
        },
        {
            0xE79571F4E57C8076ULL, 0xCC2515C7C4871248ULL, 0xD895F8ACCE322BB0ULL, 0xCB6F34BA940EBFA5ULL, 
            0x7DF2464DC30E54DAULL, 0x981320F295BC8FBFULL, 0x388FBD54AA49C3F8ULL, 0x83C24A107F5F231EULL, 
            0x9B49A4F476F2F486ULL, 0x78330854A1F478EFULL, 0xB8431DE4BCE5E46CULL, 0xF56659EC9628FF88ULL, 
            0x9314E85E7C4378AEULL, 0x602800177899EFDAULL, 0x8D95AC373961112AULL, 0x714EEF3CD764D362ULL, 
            0x6A21E2FB020FF774ULL, 0x0F5B98813F49C372ULL, 0x96E002E1913E3A8CULL, 0x70F7D428DA58B0BCULL, 
            0x69DB4A0C6786A560ULL, 0xBE9C06D8AD697ADAULL, 0x0C93634B12D17761ULL, 0x20419D74082E6A22ULL, 
            0x5ABFE4D17565DFBAULL, 0x8D0F509EB91FED4CULL, 0xFE2896638FFD1D08ULL, 0xCC0D73AB480C410EULL, 
            0x24013AEF1DB0AB5EULL, 0x755A108021928EAEULL, 0x0FDC8468E70FF21FULL, 0x2CF51079E805FE9DULL
        },
        {
            0xEC24021819D2DF3DULL, 0xEA42E28F3D7DDF51ULL, 0x8D38D139539E8525ULL, 0x8819622DBFD4F0B1ULL, 
            0xCEACAA1072A5CFD3ULL, 0xCBF42C9632F24FA6ULL, 0x198A28325477121EULL, 0x945EEC1EDDC830A4ULL, 
            0x83C0F659FBF88C8BULL, 0x969329EB6C07A696ULL, 0x85A4CAE9E20CF2B7ULL, 0xF4E30546CC212200ULL, 
            0x3C15CDFD2EF3D615ULL, 0xE5E4F5653FD0F415ULL, 0x3AD0D06F6C50A78FULL, 0x7D3BEBE3797E9B1BULL, 
            0xDD1E39E88BD454A6ULL, 0xFEF211B8F7D0ED6CULL, 0xF72C2FD08B4EBFC0ULL, 0x44231C5D5A8D6142ULL, 
            0x37E39371665A61AAULL, 0xDFB243FC14548854ULL, 0xC305603664F4DE97ULL, 0x6ABC0050B2001188ULL, 
            0x127B5B57C801207FULL, 0x1F94B7F9DA826493ULL, 0x36B80D51237DEC50ULL, 0x78646A5F569D7795ULL, 
            0xA6B361C2611A2A53ULL, 0x403EA17E1B37DCBAULL, 0xF6F9579946E2C290ULL, 0x7D038FEDCE6668A1ULL
        }
    },
    {
        {
            0xE17875E78ECA4D86ULL, 0xD0C2650920D5C554ULL, 0x682BE50066083DE4ULL, 0x16C8A30573301EB5ULL, 
            0xB122722EEA9DF770ULL, 0xDDD5999B0B0CE158ULL, 0x53EC4A25AA63E09FULL, 0xBD86D4722E72ACC1ULL, 
            0x7550E14977D11985ULL, 0x02854B6938658E89ULL, 0x3AAF5E75EBBF229BULL, 0x6F1CE16813592B8CULL, 
            0x8B534B4C393BE909ULL, 0x2FCCF35775D522A9ULL, 0x3019AC667ABAEDD7ULL, 0x90E235CFA452AB7CULL, 
            0x6BD01676988C4ABFULL, 0x927A33FB3F1AE175ULL, 0x802A9F1032956B3CULL, 0x062D64390136CD91ULL, 
            0xBE5AF4A66FA0A15CULL, 0xC01D7434DFAF90EBULL, 0xF06BF75FFCC9848CULL, 0x36F98CD0E4E9A0BCULL, 
            0xD4B82CC67990FE87ULL, 0xA0624B9D138291A5ULL, 0x434A1A6D93DAA7EAULL, 0xBD690CB70F9FE2EFULL, 
            0x13919A2846E7A400ULL, 0xF7CD16D96CF37C43ULL, 0xBA4B509A84C4310DULL, 0xD55C1300D7FD7A69ULL
        },
        {
            0xE880B48F8981412FULL, 0xCCFB5FF6E8C0CE7FULL, 0x15E81556A36D6D62ULL, 0x7D53B6530251DB96ULL, 
            0xC71E3E8BB5ED807CULL, 0x8A62761A631006E0ULL, 0x87AA5ABF5A451C87ULL, 0x761FE5600596265BULL, 
            0xC0F3ADC9EA5AA341ULL, 0x3442091B1EA0DBBAULL, 0xDE87C03283882126ULL, 0x1031E275F43ED7D5ULL, 
            0x65D38EA44DABCFF3ULL, 0xD3ECB2E12E9AC7F5ULL, 0x368F8DF39C325672ULL, 0x6E8B2CDA87BF27C8ULL, 
            0x94AEC8B8A0E28479ULL, 0xEA37B2BE12B2A4C2ULL, 0x33AC1FA0D0F67FBAULL, 0x2F0DB2BF3F9157C0ULL, 
            0x003ACAD34D2EAE3AULL, 0x730371090CEE5B98ULL, 0x948AB530FC258B2FULL, 0x837702FEC4C3AC6FULL, 
            0x3EC9DF498A25539EULL, 0x855979F114C44AF2ULL, 0x5654FF3B9C744058ULL, 0x18A6AC71481BCAAEULL, 
            0xB905960EBFAF252DULL, 0x55C7E5E0D3D1B723ULL, 0x694ABE5C88DBCA7CULL, 0xBD792E2518DD74C5ULL
        },
        {
            0x520FD9CB2E771A87ULL, 0xED0D63D09FFF99B0ULL, 0xDAE670732C477B56ULL, 0x852EDE6D7FC4DBD4ULL, 
            0x6E444E3163296FC2ULL, 0xE9FC3CBF758766CDULL, 0x002BD145F0840431ULL, 0x3E92146F8E4C8344ULL, 
            0x04046A6FFE6A8799ULL, 0x71122BD9023C716BULL, 0x345A174F9249FF39ULL, 0x9821CE94F2877203ULL, 
            0xB36E8560A9AA520EULL, 0x72382EE9C3B12BC6ULL, 0xF7A754E874AB0726ULL, 0xD59B4136E00CDA43ULL, 
            0x252B299D744F9640ULL, 0x24DC9071A13C9AB0ULL, 0x8DDEBD49EFE93BE6ULL, 0xE00526C9EED1E007ULL, 
            0xFAF68EA7B2AAB53DULL, 0xF89461532BCC5390ULL, 0x91B1C5A3E3ADE296ULL, 0x251016769EA4CE6FULL, 
            0x1DAE60C3064BE3A2ULL, 0xD9D67F3BCED0842CULL, 0xD9C2D0CCDB77BA05ULL, 0x35D15C7AD46BA2E0ULL, 
            0x922AAAD0498A5FF1ULL, 0x9C6CA4B9B018F8DCULL, 0x042EE59E8EEBE84CULL, 0x7D0E335696C9AE57ULL
        },
        {
            0x9BD19091E5BC92F1ULL, 0x297BFA9A5F9E66B4ULL, 0x2B28594F90AC8AA3ULL, 0x2C51411AB1E39967ULL, 
            0xBB86F987C1CC431EULL, 0x947024F27848E2B2ULL, 0x57F348596E3EBED6ULL, 0x32F78724F0809AC4ULL, 
            0x9AD2999714F3119AULL, 0xCCD3FAB4ED213352ULL, 0xCC62B585E0495B30ULL, 0x841C9A67DCE1E093ULL, 
            0x0CECDC31B005D249ULL, 0xFFB96A1EE0426C1EULL, 0x9BE7DF6EDCD2C981ULL, 0x8F955460088E0F0EULL, 
            0x05FCA38CE9D5580CULL, 0x480A8CE0FBC6BA0EULL, 0x550B6301F75B35AAULL, 0x11CF61DCF4177A98ULL, 
            0x92AC8815A7E58042ULL, 0xE5BFD7687A635E84ULL, 0x77E0A9A7D691F5B3ULL, 0xFE0857D0DE2449CCULL, 
            0x497E3248B3D80651ULL, 0x6B5F7CE7D799F4C2ULL, 0x3F8FF4D7596E98F0ULL, 0xD026D6B3294F4F6CULL, 
            0x6FE556BD875E0ACFULL, 0x878B656830A5F40AULL, 0xE844C758F9C36219ULL, 0xF8E3A7B989CD7BFEULL
        },
        {
            0x7CFC02DFDB6CE8F1ULL, 0x9C4EBCF48C5E5070ULL, 0x8A99858C73B9105AULL, 0x7F9F001C1C43FDBEULL, 
            0xFC2A5714DFA61588ULL, 0x01FF2FC4CFEE0D2EULL, 0xFF31406BCAFFE484ULL, 0xF9456AB4F4A3B276ULL, 
            0x3918E727B8273B84ULL, 0x8684546F66567283ULL, 0x9B2D96CB1C85DC6EULL, 0x8254D3497DFE3197ULL, 
            0xA6808F94757D1F33ULL, 0xDD09BB88B5F0431BULL, 0x913C46CADBAD2FCEULL, 0xAD77E0F5345C43E2ULL, 
            0x0AB9B7E180CE9848ULL, 0xB95F64CC301E55C3ULL, 0x6D473DB0719C01E7ULL, 0x75FBECEB6587FCC0ULL, 
            0x62788D5642C7E8ADULL, 0xB1E2B9D2A14D83ACULL, 0xE306A3B5BEE92D81ULL, 0xDB4CECF8D61A6E7FULL, 
            0xE6E9D4D30CB29C42ULL, 0x55DD3314333716A4ULL, 0x274738EDE99C305BULL, 0x694CD43262F4B82DULL, 
            0xEAE7DAAB1497F110ULL, 0xA2C7BE978DF28166ULL, 0x938C48C7CEF4B138ULL, 0x771B5DB4A19EDB8BULL
        },
        {
            0xBF95612C234E0FD8ULL, 0xDBFE23D48040FCA8ULL, 0x1781E46AFE639156ULL, 0x74AA786715BB9DCEULL, 
            0x61BDE40BF87C7FA0ULL, 0x050304228809D943ULL, 0x4F3B1848631BD24EULL, 0x3BA08A51F9BF37DEULL, 
            0x7EA0A4C8DEF8C278ULL, 0x059D6CB0634D1F92ULL, 0xC93B3F81C8566D71ULL, 0xAC0A7BA6CC9D7D97ULL, 
            0x3DB364A7C123737AULL, 0x84A48C4CA0B950CAULL, 0x9C2C657DE434E9CEULL, 0xA2B2CF5E8C81E876ULL, 
            0x727DDB0E21FFBF3EULL, 0x949C5824D174CB4CULL, 0x768E09408CDA8598ULL, 0x8BDE1EAC8056DB99ULL, 
            0x0926251F9032D697ULL, 0xD0E7763728AE2B58ULL, 0x0703AAFB6DD3F721ULL, 0x41E4A1FF01B1C957ULL, 
            0x0F3351E72B591136ULL, 0x237A7505B04E42CBULL, 0xB4BB9D02424E463EULL, 0x24FC66E393991AB4ULL, 
            0x8C7DD5385FFC5661ULL, 0x4A8F527BC54305C4ULL, 0xEF9C38BE2D215869ULL, 0x12D5F2EBC1515602ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Arcturus::kPhaseAConstants = {
    0xDD84A2DAD0E23F86ULL,
    0xF12DECA80CDA16E1ULL,
    0x945B06C998A1D5AEULL,
    0xDD84A2DAD0E23F86ULL,
    0xF12DECA80CDA16E1ULL,
    0x945B06C998A1D5AEULL,
    0x268F4B6D486755FAULL,
    0xFC13D6B6264C032CULL,
    0x34,
    0x36,
    0x86,
    0x2F,
    0xA3,
    0xE9,
    0x9E,
    0xD4
};

const TwistDomainSaltSet TwistExpander_Arcturus::kPhaseBSalts = {
    {
        {
            0xCA428BF58C3A597FULL, 0xD7F878A160D84AE4ULL, 0x46D50B972019254DULL, 0x58DB42C13F308594ULL, 
            0xB5F32762AE6CD5C9ULL, 0x4252BD33BD64F1E0ULL, 0x3C65317E2B2166C0ULL, 0x64D96CFBEA5263A2ULL, 
            0x9ED8CA7B45ECBC90ULL, 0xC7B307294DD1E9E2ULL, 0x8169B58DD3B45795ULL, 0x7EC53BA18225B342ULL, 
            0x1FB4C42DB59E4260ULL, 0xB8F3CD677711BA2DULL, 0x2792EFDCD250B2CBULL, 0x8D85555F4340421CULL, 
            0xF6F62B0B2C23A99FULL, 0xCA5E3D0D7CF57826ULL, 0xB47FF18E10EF0058ULL, 0x881CD246FCCB2E09ULL, 
            0xC2C4A50CC0DF8A29ULL, 0x848C9C166729CD1FULL, 0xB2A9ED4EEDF145A7ULL, 0x230A242A9E3BE7D9ULL, 
            0x584DE38AD3BE66EEULL, 0xEDFE38459696E41FULL, 0x1DB207DEA3A396FEULL, 0x9BEDD62C56CE6847ULL, 
            0xAF9BA8344E8102A5ULL, 0x809DD216A081D77DULL, 0x0819C4D212FD11F5ULL, 0x5C3E9165CFF15EB6ULL
        },
        {
            0x64D68E4DD72FEA02ULL, 0x1A239E38E01E140DULL, 0xE85DB52CC3E09828ULL, 0xE9970F77CBBB0B43ULL, 
            0xB6AF18C2BADE5668ULL, 0x65E1FBC91B4B2FAEULL, 0x27A8EC45142EE301ULL, 0xEE7691B2ADF4AC17ULL, 
            0x54A357F622E74377ULL, 0xA0F0EA3199550F17ULL, 0x9F19211DA4FDCE2EULL, 0x5D8997B8669C90F4ULL, 
            0xC6C54AB576B1F04DULL, 0x0791884A4BD76074ULL, 0xE9EF471BDC92FE45ULL, 0x25C1860A13840B17ULL, 
            0xF35C3951D6EDF6A0ULL, 0x3432EF9B8693742FULL, 0xF3EC865B7CB47D5AULL, 0x9C67D7AFE06971A7ULL, 
            0x14AB3B20D003D5EEULL, 0x9EA4340CD8E08A78ULL, 0x01C23D0A16DBC359ULL, 0x6209EC5EAD687EE0ULL, 
            0xF0CE5EF3899E05A4ULL, 0x05CD6C33DDFD352DULL, 0xEA9D600F057C1E00ULL, 0x961B8043D46629B7ULL, 
            0xA4D46FCE74AE3DF8ULL, 0xFD2150C10AFB5696ULL, 0x3BE347916A7501A9ULL, 0x46CC8DF172922A49ULL
        },
        {
            0x8E479550B05E097CULL, 0x5B3160190B6E7048ULL, 0xEC042C1EBBFA1189ULL, 0xB0F35EC23804AFFAULL, 
            0xFCA4A00D0D40DC8AULL, 0xB59E2C8313906A3EULL, 0x620578BF4CB71A28ULL, 0x6F53EAA75F1C7309ULL, 
            0xA185872CF88684CFULL, 0xA130675C5AD1FDA7ULL, 0xF3DE0A25D8A8F4E5ULL, 0x4B60A24CC7DBC724ULL, 
            0xA29109D18F7ADDC5ULL, 0x58D0718087783812ULL, 0x7A3E702DF79BDE26ULL, 0x0A7F072F93A2513EULL, 
            0x8BEB2DD54E2193DAULL, 0xAEF2F2AE19C69E8EULL, 0x5C9CC8319DF90F11ULL, 0x8AA8A869D617AC4FULL, 
            0x2D14866819F30766ULL, 0x9D86E4EB1DB89C10ULL, 0xDD8FB64B138F5BA1ULL, 0x008CC1F4B560A719ULL, 
            0xC419E7E2F8E4A95AULL, 0x1F26EAFEC21A479FULL, 0x502973FB1A9EC3F7ULL, 0x0C9F8CC39C4526BFULL, 
            0x69DA56862896A48EULL, 0x52FB82B83FF3F602ULL, 0x54889ED5E4754D52ULL, 0x000E0AFA07B87A92ULL
        },
        {
            0x149C9D89C771679CULL, 0xAD662ADD345D2B2EULL, 0xA308C7E8D7D07633ULL, 0x36E9A5D67AFB52E4ULL, 
            0x1AB357880F848AAFULL, 0xF92B980744F699D2ULL, 0x7ABE455159046B63ULL, 0xA10D3123D72FC03AULL, 
            0x9063098F6ECA3579ULL, 0x37517B85B0AAFA53ULL, 0x622435DADC9FDA9FULL, 0xA468A16C10A66271ULL, 
            0xCDA7FAB58227CF22ULL, 0xDAC2F9138418DE18ULL, 0xC085790F9B62C6F8ULL, 0xD1C2D41E4D347C77ULL, 
            0x0BCB39E548B5056EULL, 0x9272CDA74FB81578ULL, 0xF1A8D50FE031EED8ULL, 0xEA978ED77A2D9590ULL, 
            0xE8664BFA72489FA8ULL, 0xF08E650793B58071ULL, 0xDB6192A1AB4F3C40ULL, 0x91BB8166D796E412ULL, 
            0x36A9BE44AB009EF8ULL, 0x6A0920B9E009750AULL, 0x7259B28E756D5BF3ULL, 0x78A54C3212C274B6ULL, 
            0xC33F48C55D2009F2ULL, 0x917AC1E9F98199D4ULL, 0x270D2E60D14BD7C5ULL, 0x500AA343D7ADF7B1ULL
        },
        {
            0x23611CF4D15E0309ULL, 0x7919A3328712970CULL, 0xB00342FDB11401DCULL, 0xD85FB42853084279ULL, 
            0x7C0FA10A80E9DB96ULL, 0x0C37D22E6BD1BB98ULL, 0x44740C9BEC4ABE34ULL, 0x52628E2A415F4982ULL, 
            0xD9909D2A682BB778ULL, 0xA69F1806544B0538ULL, 0xB1FE5B214E79850DULL, 0x3706C4FCB1FFF2BDULL, 
            0xF374A3E1D0E177A9ULL, 0xB2813233606DE27CULL, 0x541A30FBB933B2FEULL, 0x9025AD388A37797DULL, 
            0xE2B02FBAC3B165DEULL, 0x55FA01754782801FULL, 0x35D1B4E92DB23985ULL, 0x24DFA2AC7A79EE17ULL, 
            0x323A29BB1166AEEDULL, 0xCBDCC5486F8D9A27ULL, 0xC03C3A9127568AF6ULL, 0xB22F60650EB05628ULL, 
            0xC374012690244380ULL, 0x48266A91A7329E9DULL, 0xED4D88D2DB754102ULL, 0xDFADF8AB770E1D5DULL, 
            0x6D38028A1792820BULL, 0xD006B67EA0565069ULL, 0x0A0E3D7D98291CFEULL, 0xDC7E20D0811095BCULL
        },
        {
            0x919BD5FA9B277EE9ULL, 0xE598BEA76AD35404ULL, 0xE5E408C0F49F2BCFULL, 0x5DC733FCBD0E2AA1ULL, 
            0x7448BE11F8314EDAULL, 0x6D54286C128E8B01ULL, 0x0EB8C1A9AFBB51AFULL, 0x5F470F337F382B33ULL, 
            0xA9AD767B5FE16962ULL, 0x8F861B61E28F508BULL, 0x4AFEEB11DE2BEEE0ULL, 0x706859A5C34001C1ULL, 
            0x80E03101DB95B5F2ULL, 0xD1E957EE4B3AE163ULL, 0x1B4D042E6D3A5797ULL, 0xB4C093052A7F7A3BULL, 
            0xCB3C3FFA477117AAULL, 0x319E8A4421066C71ULL, 0xAE059ACA71B0F714ULL, 0x2F52C0464D921311ULL, 
            0xB458BF7A25EAC92CULL, 0x105B77A6CF201DE9ULL, 0x3476B98A909DAF88ULL, 0x07CEF5A985DC03E0ULL, 
            0xA1B1BDB2CC1E0702ULL, 0x0943C674E40A04FAULL, 0xF088EBFEF8376AF1ULL, 0x83C07F1571C8466DULL, 
            0xEDCF9B82DA26CA7BULL, 0x810AE25A7C2DD123ULL, 0x5EDA134486478CBAULL, 0x9C62C0CD06C6C5FCULL
        }
    },
    {
        {
            0xD4D244CC85550FC9ULL, 0x97A9C14DA2810F97ULL, 0x8267C0B70F53FE1FULL, 0x5FDCE596A0FBC687ULL, 
            0x06470AD52B6FAD96ULL, 0xA66BC2C20B4A2EF3ULL, 0xFD3D961E424A06BEULL, 0xAAEA269BEC6CE6DEULL, 
            0x83891068DB4F7FDEULL, 0x0A310EE556E70A98ULL, 0x2FB4B1906F3F0A5AULL, 0x5EB6A5ECD97A00D4ULL, 
            0xEE6440BCB36BDEB4ULL, 0xD425C7A47282EF4BULL, 0x2A8CF83BCA6C5E46ULL, 0x9967EAF0E762102AULL, 
            0xD9DA606C571B95B4ULL, 0xB2AB6CCC56109A0FULL, 0x2B173A445BBDA46DULL, 0xCA1158CDC31337B7ULL, 
            0xE68F3E03C8006B85ULL, 0x3F1E4DD04E2F152FULL, 0x0EA30FB161BFC52CULL, 0x96CC11859DF02537ULL, 
            0x87573267A52458BBULL, 0xE020969C78977FF0ULL, 0x2BD7A5CF37A332D4ULL, 0x8F9F5EB10B7B15E1ULL, 
            0xC8D692E2C4668B40ULL, 0x64367B41CCB14528ULL, 0x6834A39203075A4BULL, 0x2898E3CF74FAAFD7ULL
        },
        {
            0xEA6E38E8D1FF2590ULL, 0x7326F8B32F45A32DULL, 0xBF3F572BE932656AULL, 0x1640D24A2E975BB6ULL, 
            0xB00102632AE03E87ULL, 0xACE5E8F59ABBA1BDULL, 0xCD66BC8EC3A87485ULL, 0x541A492069C196C2ULL, 
            0xD4DAD6A4253F1018ULL, 0x62F096672C987D69ULL, 0xA1AF25A5D2D61C19ULL, 0x298432165EFED16FULL, 
            0x6F5FB0355ADF72FFULL, 0x109CC5F81D07437AULL, 0x19ABAA28F1CDED1AULL, 0xDC66C4629B0C90FBULL, 
            0xE1534090B46B08A7ULL, 0xB2398C98DDD98FCEULL, 0x40B84F5DC08EF145ULL, 0x4AF72D9CC48D06D7ULL, 
            0x3D051D1257B088E6ULL, 0x06EED4DDE3583B88ULL, 0x32A772F707D5E8B6ULL, 0xF16C349EAC459739ULL, 
            0x8AE7F5B42D831614ULL, 0xDFF3B954037C7DB3ULL, 0x2A2B719FE3A741B9ULL, 0x3AB94BC09C3623A5ULL, 
            0xFF4ACAA7A3378584ULL, 0x77498EB84B014233ULL, 0xB2D55DC5DEAAA1A6ULL, 0x82581D5C48CE1D13ULL
        },
        {
            0x32850B6DE20EC354ULL, 0x4E125EF17240BD9FULL, 0x96281E6BB8B3D4CAULL, 0x266811458FA8078AULL, 
            0xF696FD9C7B7A0A88ULL, 0xE6F0AB5A3C563809ULL, 0xC9BB70A04F64E6D8ULL, 0x4BB68C2B2B584D85ULL, 
            0x9016C4DD96017383ULL, 0xAD944512B058253AULL, 0x1561443E5A18166FULL, 0x2273E228E3A3A617ULL, 
            0x0EC6107DA1766138ULL, 0x91759D33A2561E69ULL, 0x0BA03DF5E365162EULL, 0x4DD3FD39CB3AC006ULL, 
            0xEB2A42A7FD244616ULL, 0x517D9DEF7FAD8E9DULL, 0x249441CCF4E0CD08ULL, 0x4CDB9C7CC3F5488AULL, 
            0x3577D2B2EBA7C534ULL, 0x5EFA4A4B251EC521ULL, 0xB16337F3110741BCULL, 0x879B86EA19AFBCC1ULL, 
            0x5CE845CA59B58CBAULL, 0xD4701890DA3A8935ULL, 0x2C1FBA6109570BBFULL, 0xC8CE455A8DB914CCULL, 
            0x76EC1EE0F11892E1ULL, 0x5A2A162210171BE9ULL, 0x6C8797C24DF3E4A0ULL, 0xE09B705EB91DAC59ULL
        },
        {
            0x12C11548B3774978ULL, 0xE29B6CFBB8CA6A6EULL, 0xFDDD6A1F9E68D105ULL, 0xA81D78DB627C3794ULL, 
            0x56592EF885902636ULL, 0x7425D9435C05E8ADULL, 0xD6ED6D1E66D93653ULL, 0x5F0DCF7A297C8C26ULL, 
            0x83B9A46BF70F4A89ULL, 0x4FBBE0E6145C89FBULL, 0xE5D57B8FF1502732ULL, 0x6B631A72290929F9ULL, 
            0x09CCACDDE79DC45FULL, 0x78BBACA7AF66582FULL, 0x93B15DFC5C236D4EULL, 0xED3893C460F434CEULL, 
            0x9C56EFB39EB184FCULL, 0x86B1E2AAC7E372C9ULL, 0x0D65C36C815AD3ABULL, 0xE3694EFFBAAA276CULL, 
            0x33560D008B2F5090ULL, 0x693257C315C37FC7ULL, 0xA8DBED710B97F94BULL, 0x78B387A8173992FDULL, 
            0x668ED13AB238203BULL, 0x46306E114A76FD60ULL, 0xA826CF3278963B4BULL, 0xFE007A7AF3EB511DULL, 
            0xDE925748724F3DAEULL, 0xEB415F8B8B45598CULL, 0xC5B427BCF3CDC522ULL, 0x99531CC718EFA088ULL
        },
        {
            0xBE8049A2C7440F80ULL, 0x2C1DC1E70169715DULL, 0x98CC9F526CAEE3BAULL, 0xC50ACCEC6E601094ULL, 
            0x56E63F67E86517CBULL, 0xF22B030E1102BD79ULL, 0xD2A050579F877C1BULL, 0xC7BC75BAE1BD8BD5ULL, 
            0x968059188D29BAE2ULL, 0x1B3C085BFCAC0BA4ULL, 0x6BFECE66AE109ABAULL, 0x559A0C5DC71A4F53ULL, 
            0x3C82291AB7ACB0F2ULL, 0x0CA0CA679B1BF1D9ULL, 0x904604B89FD57DABULL, 0x7E3C64DABE79DC00ULL, 
            0xB148455A8C03897CULL, 0x269FECC0150F3537ULL, 0xB9F3EBCEF2056919ULL, 0x4A76753F9CFD2E09ULL, 
            0xB17FA4E223EAB1F3ULL, 0xC5D81DCC68102800ULL, 0x143C314829E86D10ULL, 0xF8EB062B5ED39A4BULL, 
            0xCB1795902461A027ULL, 0x0B09310879B9E678ULL, 0x5ED337B7FA6D874FULL, 0x443FB36642B16A7BULL, 
            0x2A2C93153E46991AULL, 0x0F459166549B5455ULL, 0x3717EC4DC03DD7FEULL, 0x3EB108917A71E65BULL
        },
        {
            0x32FF338C169C67D7ULL, 0x4DEBD8D397083FD9ULL, 0x830DAEF82B54F870ULL, 0x45B90FB2784CFEC4ULL, 
            0x4C52C2EC16D55B20ULL, 0x085EE9D39ADA0063ULL, 0x7F05FA241A1A8FF7ULL, 0x50F0ACCDAA111C77ULL, 
            0xBAF35206225FB739ULL, 0x3313F1CDD84DD1F5ULL, 0x8EDE9AB8B1BDF5D5ULL, 0x9E81ED47958317A1ULL, 
            0xDA892B614933530DULL, 0x1C8C37524EFA726FULL, 0xF7AF340B720509F9ULL, 0x0CF3A0EDA3ECA2F2ULL, 
            0xC6A1F38E2A06BB2AULL, 0x6B548BEA54E6A619ULL, 0x20AA8640C009A61FULL, 0x201E05B1A4D7B1DFULL, 
            0x1FA4640334447C97ULL, 0x9F07862FEF8DBFE1ULL, 0x53F3D9446AB9B977ULL, 0x6010A872E14C364AULL, 
            0x96D0462FF7405D78ULL, 0x139C0912952E3C03ULL, 0xEDB12D5EA9EEE154ULL, 0x35258174FEB8560FULL, 
            0x764EC21E9C4F5096ULL, 0x7B35639196657AC7ULL, 0x262EA983967BED00ULL, 0xEE290721241E8FB6ULL
        }
    },
    {
        {
            0x8E54B46C3D27F1CCULL, 0x44A2EAEA417DB207ULL, 0x3846DDAC90073B4EULL, 0x72E9EFE3D3400B5BULL, 
            0xE481072C0015369BULL, 0xFA1FDDC88B1546B2ULL, 0x63137A7BD4F9CA5AULL, 0xD6BEE468F07D6E1EULL, 
            0xBBC4E46D238FA03AULL, 0x692EB308C9561585ULL, 0x96B4C2FA79948539ULL, 0xE9CC138A9889EF9DULL, 
            0xB5423D7FB500E984ULL, 0xD490086E9F4794CBULL, 0x9FECF1003F2C49CFULL, 0xE5176F3FBA1A7082ULL, 
            0x0D1EA49294F95A4FULL, 0x457B25318A2F9430ULL, 0x04B64584A0C4D249ULL, 0x9DB81622D525A049ULL, 
            0x8EA3F1A6E08DB665ULL, 0x98D0C2A588DF15D3ULL, 0x5AD37B18BF45AD4AULL, 0x128377B8E96FD6F5ULL, 
            0x52F723F91A376419ULL, 0xA6932FF49D454409ULL, 0x9CD0CA9A4EE8FC06ULL, 0x1FCEFCE38571C6B2ULL, 
            0x9BF66CEA315BB15DULL, 0xB8E0FD3783A98A5EULL, 0xCA0CE3290BEF734DULL, 0x0EFC22E53EF126B0ULL
        },
        {
            0xCE5AC93645D44B9DULL, 0x088BBC598EFC620BULL, 0x4A40219AF040833AULL, 0x0A6F387C8F35B9C1ULL, 
            0xB269DACC6A4671BAULL, 0xA8A505ADAEF5A38CULL, 0x98F6572706ECD7DFULL, 0x0D8504F13161A739ULL, 
            0x9BA5C920269B5093ULL, 0xA28328F141D03751ULL, 0x8BCA3AD8C96B2D34ULL, 0x43EA705F0262C5FDULL, 
            0xD5DFA5135FB2784DULL, 0xDDBF4E30C04BFC8AULL, 0xCACAA243B2C82726ULL, 0x421034E60A9F15E5ULL, 
            0x8A0E96A3A600590DULL, 0x6A70F79C9A3A8FC8ULL, 0x056797AD804FDA28ULL, 0xAA4CAF738131F71AULL, 
            0x17B28835DB9BF849ULL, 0x3C51BB3264C41A60ULL, 0x867E46DC727EEEFAULL, 0x8E3E22F73E663311ULL, 
            0xB02315120CDCEFC1ULL, 0x94963AA62E88BF01ULL, 0xA90658FF43C1A7C0ULL, 0xAFB6E628286208F0ULL, 
            0x00083A52823C2EFCULL, 0xFA20B5C7B9F24BFCULL, 0xEE6312415B5530F2ULL, 0x2CB019480BE7D27FULL
        },
        {
            0xA53F3E52F0378516ULL, 0x177B0301F57BC8C3ULL, 0xE5AEDF9B032B4E0CULL, 0x651E3CAFD4E62340ULL, 
            0x2743541A35219EEAULL, 0xF6852AC69631F4C5ULL, 0xADA10068C1B277B6ULL, 0xA24FD5032EDC3514ULL, 
            0xD712557541475D05ULL, 0xE0C0B829F43C6D5AULL, 0xBA0D5E93FB3AF779ULL, 0x4D7081E08D804971ULL, 
            0xB2DB8218F4715529ULL, 0xDC352C38F94F155BULL, 0x12BF09F5971DF596ULL, 0xBABD44A7C8B1D7C8ULL, 
            0xA2679BF5EDF41175ULL, 0xE2C0244D1FCD0658ULL, 0xBC0A683B1C3DC51DULL, 0xFF28A0714E91AF21ULL, 
            0xB9D24BD608544DD9ULL, 0x29E3D82884CABF2DULL, 0x7E350DB84884CD68ULL, 0xF3A795B12975917DULL, 
            0xE3DAF13DDEBAFAFEULL, 0x3B182CEC0504F6BBULL, 0x391EC9F182979A22ULL, 0xFDFBB337B02D62F3ULL, 
            0x38E8679A2104B934ULL, 0x45E91DDB0A42C6C6ULL, 0x3C23401A80DAF33DULL, 0xA81AAC4DA6767560ULL
        },
        {
            0xF1E3C11556065FCDULL, 0x765CAD377A762431ULL, 0x47A287AFE3221EB4ULL, 0xA9D1F703E052A6E1ULL, 
            0x285275E9C44A8B27ULL, 0xFE35727B7FDDECF2ULL, 0x292B530F4195758EULL, 0x2CC5BF453440B265ULL, 
            0xE495887A7A599F70ULL, 0x490C57C733A59E85ULL, 0x05543A0FB1312E16ULL, 0x043E12BABCB7F643ULL, 
            0x32B665D155466253ULL, 0xE13800FCA71B28BDULL, 0x9150A66A7E518D17ULL, 0x25D09C1542FB7DD8ULL, 
            0x42B8FBDADF98FC19ULL, 0xDA1DE9B311291E38ULL, 0x8717EC6D4E65E449ULL, 0x73BC2E3B18DBEDA0ULL, 
            0x96B90ADBC012EB0FULL, 0x9367532712A89ACEULL, 0x960CEE5604F9262FULL, 0xFC1681AE41CD1807ULL, 
            0x22DC377B4EAAC3C7ULL, 0xCE16671B428F87DCULL, 0x978280379B435C38ULL, 0x46FB2B9D72822733ULL, 
            0x4ADF9A4E58DDC134ULL, 0xA2EC66F19F04DBD4ULL, 0xBE4B1DFC75A951BAULL, 0x83DCE7E60457E4A1ULL
        },
        {
            0x6E4296B080BBB16BULL, 0x55AD22767A4735ACULL, 0x61A067A20711F0A1ULL, 0xDF53BDB3788B572AULL, 
            0xA47CC8AA9CC679A7ULL, 0x9EB426497D219C82ULL, 0xCBC3D78E99214A87ULL, 0xAA9279CD929F62A6ULL, 
            0x44868757055BA9A1ULL, 0xE0625D750FD27E66ULL, 0x2BE7BA91EF4A567AULL, 0x8CBE75322356B2F6ULL, 
            0xEA682E9FF4AB7F66ULL, 0x0A5C136F6245D6EAULL, 0xF4342F9427C20C9AULL, 0x19D1189184F2491BULL, 
            0x93B79E3DE877FE73ULL, 0x326AE4459924B8FFULL, 0xD3FDEBDE754BD281ULL, 0x869E20272DC4E26BULL, 
            0x20C25F3A04C9594CULL, 0x718CC24974240BE5ULL, 0x31BA4C2A996C652EULL, 0x17DF160BC7D3A1A6ULL, 
            0x7268A05E39CD6601ULL, 0x6B6C117FAFE774DFULL, 0x7CD65DA32530EF30ULL, 0x290928B4D2830B11ULL, 
            0x9ECE17A5C0F1FA36ULL, 0x25F1393A5867C80AULL, 0xAA1B9A4320F8E824ULL, 0xAC33940B2D44DF7BULL
        },
        {
            0x790C1A7E7F671ACEULL, 0xD9C79FD3273C768AULL, 0xF7420CB25841A942ULL, 0xA42F524D76C40F8FULL, 
            0xB80BE5D63794E1F8ULL, 0x13930070EA17D042ULL, 0xEFAAA3BEFD57BF50ULL, 0x97CC56D078F61556ULL, 
            0x8F7BB7C815326F7EULL, 0x155BA9FD9DED1440ULL, 0xBB9FD7F07A15D4D4ULL, 0x6FB0BE3DCE44116EULL, 
            0x16594E679CC4F55CULL, 0x882AE0CBFA8B1832ULL, 0xF2644A412E756DF9ULL, 0x77F9AAD3A2C442E6ULL, 
            0x68399589254F4EDCULL, 0xE6B8FD52D4797C84ULL, 0x81568A31FAB919A7ULL, 0xED9DF343498B7799ULL, 
            0xD71DE80053F8A317ULL, 0xB66AFC5371562675ULL, 0x04979E71607DD43BULL, 0x554450447532AB04ULL, 
            0xE9AE4D2C4E333790ULL, 0xB28A5E47A79CCF91ULL, 0x2082227966F01832ULL, 0xF9A661C8EF8D4314ULL, 
            0x522A13C6E4BE116CULL, 0xA08786440F336FFFULL, 0x6B5D5BD534C90B54ULL, 0x32FE11747C23748AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Arcturus::kPhaseBConstants = {
    0x5459AFB4C47B99D4ULL,
    0x5285A70C6602AB8EULL,
    0x1F9416DF6FD16241ULL,
    0x5459AFB4C47B99D4ULL,
    0x5285A70C6602AB8EULL,
    0x1F9416DF6FD16241ULL,
    0xFAFAFA3297B88CC7ULL,
    0xDFE9261775CA47A5ULL,
    0x19,
    0xDD,
    0xA0,
    0x4E,
    0x57,
    0xF5,
    0x49,
    0xC6
};

const TwistDomainSaltSet TwistExpander_Arcturus::kPhaseCSalts = {
    {
        {
            0xE4939D485EE0D388ULL, 0xD059267931552BD8ULL, 0xEF943EDC25059D86ULL, 0x43F70A5D3AB22B93ULL, 
            0x018AFCF677856BCDULL, 0x6E22B8C369561E6FULL, 0x80D74D6D464922CBULL, 0x08310B59CF42962BULL, 
            0x376EFA82954292D4ULL, 0x0C973B12FC705899ULL, 0xC926324B396E4DD2ULL, 0xEA1E4B43EB2C822AULL, 
            0x9548F3584C39CEE7ULL, 0x0DA932C3E66A6765ULL, 0x200304AA77ADD5BBULL, 0x4579C58BC7F02143ULL, 
            0xAC7FDC8E731117D9ULL, 0x8906251D03D32BA4ULL, 0x5FFF691346991C0BULL, 0x96CAF47C563679C8ULL, 
            0x36B5A59084507BAFULL, 0x22B367B60348B058ULL, 0xD3BC39EF1F2D1693ULL, 0xB3E42EA58881ADAAULL, 
            0x7CB681B296F0D73BULL, 0xC17C7E0341DAE2B0ULL, 0x7325B44800EBCB06ULL, 0x14FD15D120D59DF8ULL, 
            0x2CCAEF54AD6EAFA7ULL, 0x4B185C2B6B479E44ULL, 0x890758AB8D88693DULL, 0x535C12D7A10EC9FCULL
        },
        {
            0xC70880B6CDEFCC52ULL, 0x70AEBA2678CBB15EULL, 0xD38011CAE6271D3CULL, 0xF8D36BBB7C7806F2ULL, 
            0xF4E43368CD95C465ULL, 0x93CAE3C67C36BA74ULL, 0x1B822E51CC7443BEULL, 0x50917AE6EDC0DC9FULL, 
            0xA1C2B4E871B7C3FBULL, 0xA48ADCDE08CD49D1ULL, 0xB51440F4D2116944ULL, 0x6C26E6AD4EEAA506ULL, 
            0xA70F81BE59800170ULL, 0xC2163E287818EDFEULL, 0xA72C6BACBE82584DULL, 0xF48E5EDB39049E3EULL, 
            0x0D4DE0227EF5C6C6ULL, 0x6B70B746E288271EULL, 0xD3F1FBA11CA13A65ULL, 0x842A08EDECECD654ULL, 
            0xEAF43EAEB6B29A22ULL, 0x9C7D8ACFE5585EB5ULL, 0x332556CA79DC30C5ULL, 0xC299982DF38E08EAULL, 
            0x85D0869C65D277B6ULL, 0x99B95F44252DF342ULL, 0x7C0C0DB252DF649AULL, 0x1BBCAD30776AE951ULL, 
            0x8B4226C2EC747907ULL, 0x84017D0C1933A188ULL, 0x45E65688C7CC9A46ULL, 0xF9B5269AD42EDFF2ULL
        },
        {
            0xBEFAFDBA5E29C1EAULL, 0x7C63DC2061DD3EF8ULL, 0xA14AAE0B7FBAD84FULL, 0x9045C82110E1A5EAULL, 
            0xF15016E9A22F08DEULL, 0xC59F2D717F659647ULL, 0x4FD629591FCAE878ULL, 0xFD3403CCAD02CED0ULL, 
            0x0C1A0B0CDCCF0DE1ULL, 0xB4128E70FFA255ECULL, 0xB46C55722BE73280ULL, 0xF38708E82E4B4891ULL, 
            0x9FE6569046DA59D0ULL, 0x64E7FA20C996EF6EULL, 0xA64C7E725DCA6749ULL, 0x1845C50BFD48EF1EULL, 
            0xFFC711B0E75E9DE8ULL, 0x83DEC2FB03C5A729ULL, 0xB767B4A69B44B6C8ULL, 0x0A4D507938C0A57BULL, 
            0x28E4C3E5D900A239ULL, 0x840CEF98974B343BULL, 0x5E2FB1FAEBD6D948ULL, 0xDD455118F3FA0558ULL, 
            0x8123549892464FF4ULL, 0x2D6E49367D4CC72CULL, 0xD636F1D682BD8273ULL, 0xDB6448CB927D3919ULL, 
            0x811AC221803D38FDULL, 0x05A57C2046C4C42DULL, 0x601125001E5710F8ULL, 0x7CCFAF2B7BBC5370ULL
        },
        {
            0xC3D979EFB5786BEFULL, 0x3B13094531BFA52FULL, 0x970B894E021F7245ULL, 0xFDAAA31D2320A67BULL, 
            0x85DD3877F7C4E6B1ULL, 0x0D26B7AD8DD9FDB3ULL, 0xA6190054A40B8E58ULL, 0x012C78CE8727EE0DULL, 
            0xBD84F3306ACFD3B8ULL, 0x9D0A0815D42C77E1ULL, 0x603A0AA4FE8397ECULL, 0x02265CEC86C1BD66ULL, 
            0xE131AE595A9BB9C3ULL, 0xAE691506EEFE167AULL, 0xDDEC89709AEE9222ULL, 0xBE787D7B48DE1296ULL, 
            0xFC8672AB9252C4ACULL, 0x5A088E6BAA064998ULL, 0xF0DD22818646E901ULL, 0x962FE5DE8F56F508ULL, 
            0x9594B9FFEB3716B0ULL, 0x626CD6BA685D6F9CULL, 0xA984B732DAF201DEULL, 0x9FC6F627A4105E22ULL, 
            0xE1C0372538AC8F2FULL, 0x5E588B2E93099382ULL, 0x2CD54CCED7F966B4ULL, 0x32DA1D55E2D7C5C5ULL, 
            0xD8A22B2092F6E678ULL, 0x1EF7D3AF6D49FA65ULL, 0x5430E54A3C0E33EBULL, 0x8299281189C0C476ULL
        },
        {
            0x19D189BF94E96E9BULL, 0x41795B2BAD327263ULL, 0xF8509C6D26DEBCF7ULL, 0x8DF109885FB0E90BULL, 
            0x72C4A07D589EB123ULL, 0x67AE553BE29F44E2ULL, 0xA8D9F8982C5D4B7CULL, 0x4DF3AFB4875EB4C2ULL, 
            0x1D444B7301F8FD06ULL, 0x14E355631AD052D8ULL, 0x8C558CEB4565986BULL, 0x28B430BE029D0D6EULL, 
            0xEAD3B590158CC818ULL, 0x9B46217BCC1AE22CULL, 0x7F69E941BE19B3F4ULL, 0xA3BA826AD3433669ULL, 
            0x8E8ECDFB484893CCULL, 0x250D078B484457CEULL, 0x0A2EE594BE64F455ULL, 0x2D69062459D4827AULL, 
            0xD16842370374D363ULL, 0xFB6EE0FD61663C93ULL, 0xE1FB4071232C881BULL, 0xC53D1551E191FB54ULL, 
            0x08B744C4D1317413ULL, 0xD9D98D9573DCF2FEULL, 0x13BDC643D2A5DA12ULL, 0xE37AB92609DC7ADFULL, 
            0x6B52A01130EE94D3ULL, 0xCE74752153DD9946ULL, 0x98ED170D7E0830E1ULL, 0xFF1CFDE863EDAA18ULL
        },
        {
            0xCAEFB4F26601F226ULL, 0x1A32FB1D59229AE6ULL, 0xCF97A7F53B67551DULL, 0xE6CB64AB30DBC6C9ULL, 
            0xD4730F92CEFF268EULL, 0x99287782DCCA25B5ULL, 0x09BA7AEA8158DF80ULL, 0x205C9E4183749E30ULL, 
            0x19F2E7FD0E4F0C3DULL, 0x4A34F5CB40343CAEULL, 0x72E53B8A0099D396ULL, 0xB4CDD05E64CB0F57ULL, 
            0x2570FBE3D96596BFULL, 0x507EF8F8DEBBFE78ULL, 0x0863B6DD44254B9EULL, 0xADEC7C436C02F31BULL, 
            0xEAF4CE4154669CF2ULL, 0x61607F8058FA6E43ULL, 0x7EFEB21D4EC21820ULL, 0xAAE91CEF038BC8C2ULL, 
            0xD18DFE58FF8E61E9ULL, 0xA1F639B2E1D7BD23ULL, 0x9593C56078B01677ULL, 0x6875FC2243AC326FULL, 
            0x0E495A44812507BDULL, 0x70CFC8254F8D664CULL, 0x72ABC7D728F379EEULL, 0x18BEFE40B852091FULL, 
            0xB7642CA04ADE3F34ULL, 0x746AF722080362C1ULL, 0x300ABC01655D5CF8ULL, 0xEEA4E14D881A106AULL
        }
    },
    {
        {
            0x39618AF04BBD4FDFULL, 0x153AF589999CBAFBULL, 0xBFCA87EAFBC29DBAULL, 0x2C0CAD02E5718DCFULL, 
            0xDEAAA9DA5C9182EBULL, 0xCFBA2E39A0D22965ULL, 0x539E979B9250C98EULL, 0x71535B63E0AAF8A4ULL, 
            0x59ECE5CD0493C8ADULL, 0x2EF923D3F258CCDEULL, 0x53D2ADFF83515EB7ULL, 0x2730649B8242237CULL, 
            0x8F3ED6B6A63C11BFULL, 0x5244DBBBAE6E08AFULL, 0x0AC4954A3FE3D773ULL, 0x402C6895887BACC1ULL, 
            0x58541CC25FEEB491ULL, 0x82158D0427A0DA8EULL, 0xAB522A910A2CBF12ULL, 0x0560C61286204432ULL, 
            0xFE50735C1DF9F7DEULL, 0xEB5341F9239ED897ULL, 0xB7C19B9185D293A5ULL, 0xA71F8AD70B60FCAEULL, 
            0x6BF7CBC6E4433126ULL, 0x232E2CE1922BDD68ULL, 0xAB3FD1B45B0925FFULL, 0xC4AF818121C3029AULL, 
            0x1C22C92C563A9252ULL, 0xF9CBE914C44AC17FULL, 0xD5831DCC56368511ULL, 0x70E596D777F8D6BEULL
        },
        {
            0x639C725B03289761ULL, 0x53730CBECAA9891FULL, 0xCF47DBE44C1951E1ULL, 0xC325154FA304558AULL, 
            0xDD3AB5DAFEA51B63ULL, 0x863A1850483B3AE7ULL, 0x1209822CAD80209CULL, 0x24EC058B46010596ULL, 
            0x1A1883F671C679FFULL, 0xCEF4D37872DB9B08ULL, 0xA44CC638189A553EULL, 0x43A649B09B756BBAULL, 
            0xACAAE06DE03D136BULL, 0xA4D2D68BEF416090ULL, 0x67C37C5003E4F48FULL, 0x6D62B6725481479CULL, 
            0x9507D3C11A4901EEULL, 0x552AABCDD9D26686ULL, 0x354BDF8EEF934992ULL, 0x88404DE3A0649054ULL, 
            0x418F928ACC5D1285ULL, 0xAFFBCC39AA97E184ULL, 0x471056658E743E2DULL, 0x574F1785566FFCD0ULL, 
            0x14CE5FCC9CCF2B27ULL, 0xC3419F5E84EBF63FULL, 0xF4C65E8044BC72D1ULL, 0x565E3AED6E92ECD6ULL, 
            0xBACAB922554102CFULL, 0x4C09B428CB1F352BULL, 0xC7EF11DC10FB49ADULL, 0x0121F44231BD59B0ULL
        },
        {
            0x0B20D35F95CD31A4ULL, 0x3C5CEE859206D7F0ULL, 0x29294971E79E4DDBULL, 0xB02292D800C6BB52ULL, 
            0xC11BBD41FF37B3E5ULL, 0xF842F6028EDE06CBULL, 0xF3362463430068F3ULL, 0xCD989E7104485D55ULL, 
            0xB0A8E65769F9D25EULL, 0x213BBD321668B624ULL, 0xC9AE3EF346B98A20ULL, 0xA2CC6B476C056B41ULL, 
            0x7820B264D2E37E18ULL, 0x8B617C6365B8FD30ULL, 0x779112B3C7634B50ULL, 0xADF599EAAFA1B2B4ULL, 
            0xF2C4FC2B70666506ULL, 0x9F7148FB732B66B3ULL, 0x6B00157FEC2A0C3EULL, 0xE3F6ED75A275D9C6ULL, 
            0xE71E3977D105A360ULL, 0xB64313B94468263CULL, 0x8376B48BA7A71798ULL, 0x79822584253F36D5ULL, 
            0x53EF0C127D89CA36ULL, 0x9D09095704083B79ULL, 0x91134E4810D54B2EULL, 0x8C7DDC3454ADC512ULL, 
            0xED092C855259BE99ULL, 0xF24A005F5C68A1F0ULL, 0x70D9CEF425EBB3B3ULL, 0x774F3C4AACFEECC0ULL
        },
        {
            0xAA3F169B868CC769ULL, 0x467C9AE0CFBCAC74ULL, 0x4D8493FE7CE08D90ULL, 0x69022ECF706F9F07ULL, 
            0x685E79833EE97CDEULL, 0xA17BE9BC0DDD9D01ULL, 0x1C0950AFD0AF701AULL, 0x999D6EB484D72945ULL, 
            0xD6386859FEE173E6ULL, 0x461422287F66EEF3ULL, 0x4E28CC6D1BEBD538ULL, 0xE710EC98601A1FF5ULL, 
            0xFC1E9DA0BB71823FULL, 0x8ED77DA53D310963ULL, 0xAEA0AE6A6CEC1F84ULL, 0x2DDED84CB8CE8747ULL, 
            0xD65D244A2DD22B3BULL, 0x3E940A642C1D2082ULL, 0xF505CAB6013F5583ULL, 0x6436D8B73F5F9D29ULL, 
            0x228EFA889D5BEBADULL, 0xFBF27C35358037BAULL, 0x7E7B05657710B44CULL, 0xD203138CA113539BULL, 
            0x8734F63ABBC4748FULL, 0x098424044AD508FDULL, 0x49E777EDF1BBE970ULL, 0x49E892CADCEC1BDCULL, 
            0xC2A9E30D66116AA8ULL, 0x5D9131CF5486E518ULL, 0x5E71E9255D14A3F6ULL, 0x5DA3A6265EC21518ULL
        },
        {
            0x32771B683EFE4954ULL, 0x27020BEAE821655BULL, 0x8861A150CF7F6917ULL, 0x9445891B4B8C79B6ULL, 
            0x45D09CC9DDDAF9D5ULL, 0x449452ACF949D338ULL, 0xA721897D9B2ABF63ULL, 0x01423F43E62585F6ULL, 
            0x0BDB2241FD4DBE10ULL, 0x18AA2F0DEEA0BB3DULL, 0xEB8E55B532052DB2ULL, 0x51CEC2AEB8369692ULL, 
            0x2BA9AF51237043CDULL, 0x5A1CE42B5C3AC493ULL, 0x445887FF0FCAF056ULL, 0x711EC575F0CDBDC4ULL, 
            0xC1D722A07FDE56EDULL, 0x59F325C92E21E5CEULL, 0x2EDACEF7D9D98D91ULL, 0x830E4CD2BD37D214ULL, 
            0x57DB42F830DB8E1DULL, 0xFA30C0D2EE124D72ULL, 0x4E437A31C9C24211ULL, 0x979BD61998ED72C9ULL, 
            0xCAF305109B43E357ULL, 0x6F3C9FFFDB1BDAA4ULL, 0x0410EC0C78E6E5D8ULL, 0xCB7B105A9707A8D2ULL, 
            0xC08D7106946D8546ULL, 0x9256B391527AA804ULL, 0x33AFC340A1CF76DDULL, 0x359E02EC821E77FEULL
        },
        {
            0xCACAD3AF9DF323E4ULL, 0xA084341BC4802D34ULL, 0x0DF6551A8C2F0035ULL, 0x9192088492A679F6ULL, 
            0xCB6A40E4EA4EDCA4ULL, 0xB1EBEAE6B957915EULL, 0xB14A7CDD94D4633FULL, 0x63BAC4D326B21D19ULL, 
            0xE065DC78C45C02D9ULL, 0x84E364C99E85A9F7ULL, 0x01D016A892D10FBAULL, 0xCDB8300ED708B89CULL, 
            0x463AC6585A888EDCULL, 0x0D4DD1D6CCAD188BULL, 0x8E7DF5148301F116ULL, 0x76574B9AC3BBAACCULL, 
            0x6B45346236E272ACULL, 0x2D8C34303EEB954BULL, 0x681C47279B04AC3AULL, 0x55BD48BCC0CCBCE5ULL, 
            0xC2EAE093C9B04159ULL, 0xABB04A88B14E1416ULL, 0xCEAAC51581F6F101ULL, 0x925661EC31EF6046ULL, 
            0x1A35140A26142527ULL, 0x804D85610DB1A60FULL, 0xACC912049F025C35ULL, 0xCA3EA6C64E721432ULL, 
            0x10096A3EA1086933ULL, 0x848B7462002BEFD9ULL, 0xDB678545A3926570ULL, 0x91D604F69A80F86AULL
        }
    },
    {
        {
            0x2FD17AAFDA524002ULL, 0x926710FF1E5444D3ULL, 0x88FDBFB95F27E70CULL, 0xEBECD12620D8BAC0ULL, 
            0xB501D9CD924DD4BDULL, 0xC91A69DB5730E123ULL, 0xA32935FE1D4A38D5ULL, 0xA436CAF5B97273D8ULL, 
            0x54F2570BCC236316ULL, 0x2A4EB24D8BAA20E0ULL, 0x285FD01E37D82FA5ULL, 0x0AD17F47DB7C31ECULL, 
            0x16E5D77CB63DDEDEULL, 0x896CEB32C8D99DB9ULL, 0xAB2D44F3B3A8C041ULL, 0x7985035962B7EAA2ULL, 
            0xEA52DC01C7B9E2D5ULL, 0x6877A74C82514AA9ULL, 0xD48A5FE348F9331EULL, 0xFD811943138E3B80ULL, 
            0x01E33742452869DDULL, 0xECC0F210249E82FCULL, 0xF9B40FFC27990563ULL, 0x82BFE2BA361BACA1ULL, 
            0x932E2906A4661977ULL, 0x9289F3D6A9A49F8CULL, 0xB9EBB93EA1B48CD2ULL, 0x7B5FC716341CF735ULL, 
            0x439FF50780E6D0A2ULL, 0x2ACAB284BA359CBBULL, 0x07A94DD79BE74269ULL, 0xB74CF4CB2D865C0EULL
        },
        {
            0x98C54F0BEF8F86BCULL, 0x865034B438B5D9F8ULL, 0x19DCCCDE53012528ULL, 0xF55AFD60610F1012ULL, 
            0xD4B4B1A445521781ULL, 0x5165BEA930D9F390ULL, 0xB68114B981D4BC74ULL, 0xF243E75DB995232AULL, 
            0x90441EDE2B270C54ULL, 0x093C4FEF59F37103ULL, 0xEC13E7FD80699E29ULL, 0x2F7250FF35F2D59AULL, 
            0xA4C218D1FFEC3967ULL, 0xD5F2BCE7AF5CB47EULL, 0x2D4B482D9E8C9060ULL, 0xAF44D4A2623326D8ULL, 
            0x4514F0E842CE56BFULL, 0x49305272B3D82A7CULL, 0x112766473AE3D3D5ULL, 0x6BA89B59C695BFBEULL, 
            0x58388D88641593EBULL, 0x6CEBEE377DB00914ULL, 0x8574BD3814FD5602ULL, 0x888520077AC99E75ULL, 
            0xB422333404DB656DULL, 0x62F640BA846BF84BULL, 0x7E7AE2F691E5A136ULL, 0xB41636BADEBF0BC9ULL, 
            0x8C7E0DCFB7C0CD9DULL, 0x0D984B9B583CA727ULL, 0x9FDC280724C34F7AULL, 0xD04999AC8232340EULL
        },
        {
            0x1F88AFB230DDA948ULL, 0x838D6C30E4CF25EFULL, 0x70C3A2F08266D3F1ULL, 0xC7B5F706FCF1FA1BULL, 
            0x44A979AFEE54E28BULL, 0x36BC2AAD9CDF4C84ULL, 0xE713FC9A01F3FB31ULL, 0x6838F438EFB2EC2EULL, 
            0xBDAB23608C7FC30CULL, 0xA3F36C19BEE2AFF3ULL, 0x74322B6A2A9CAAB6ULL, 0xB1C1A2F91CC97FF0ULL, 
            0x1BB311F856E8F92FULL, 0x5C6E51846FB6D058ULL, 0x3C278C9EDD9EB7A0ULL, 0x9F43634802021464ULL, 
            0x197E677B666E5AE8ULL, 0xDEC176136045D07AULL, 0xAEF509AC58EFD4DAULL, 0x38B13D1B22F3B3A8ULL, 
            0x3B5A4AD0D3CD5DB6ULL, 0xC7495141188124BCULL, 0x5A53541B7457D11EULL, 0x051AD76B9B672597ULL, 
            0x6E96D59C8B838145ULL, 0xE8DDB4013376CC86ULL, 0xC4D079ADD032A0D6ULL, 0xBEC6A6A0B9B2BABBULL, 
            0x98BEFC48B65A9913ULL, 0xA0C1BBDFB19CC40AULL, 0xAEBF896D050C5033ULL, 0x86FF7B6BE94B861FULL
        },
        {
            0x54CB09AB9284CF09ULL, 0x767041F788BC6407ULL, 0x6BE4366645D8CF82ULL, 0xF782F585A96FB2DAULL, 
            0xCF443ACF6FEB2AEAULL, 0x3CD9FAC6011889F9ULL, 0xA427B474D33DC48BULL, 0x2333FFAA318196D8ULL, 
            0x6EB4DD0A0088C95FULL, 0x6F885C0C1083802EULL, 0x67C4EE28C8EEA224ULL, 0x068378CE90B0381CULL, 
            0x9C40132565494014ULL, 0x644F2B68F22444C8ULL, 0xE34BD4DBA61BA709ULL, 0x020B1D003413097AULL, 
            0x9D054AE9E9DB4B4EULL, 0xD6F577C5043CDC3BULL, 0xE1BDE8405E51F950ULL, 0x31F0BD5321C8FC68ULL, 
            0x259A0E74C273B217ULL, 0xDFC014BA47D43273ULL, 0xB301D71C6535E08AULL, 0xEF3C70F802DE2EA0ULL, 
            0xD968D1D96781144CULL, 0x75888541669853CCULL, 0xB919BC7866125718ULL, 0xC7917A6A94A571CDULL, 
            0xE5607B7CD830EC97ULL, 0x2AE9CE0F4FF88636ULL, 0x80D44FAE2FC7B6B0ULL, 0x7367DCDFBCB6020BULL
        },
        {
            0xEB2EED0B1B9CF4CEULL, 0x4F1EA5481F079D87ULL, 0xF9D925C3B4290A7CULL, 0xEED899F504CCC620ULL, 
            0x72CCEB48BF874B19ULL, 0xE72079D85FCD1AF4ULL, 0xB00718E439439CC7ULL, 0xF2BFC9BC471ED882ULL, 
            0xA10AE9AFD04A1885ULL, 0x30BE8203066D1FB2ULL, 0x4E4BE296AB92C29CULL, 0x6DBF763FEA34AF98ULL, 
            0x87E170B4A7B6959FULL, 0xFCF8103B20698A9CULL, 0x49C10E240C284662ULL, 0xECDCF4788C5E0A8EULL, 
            0xB805025C730EC719ULL, 0xEACE61164B004826ULL, 0x1696DF2CF4DA9C8CULL, 0x8E1F8472EEA3D986ULL, 
            0x4D6DB6FF009210F8ULL, 0x1751CAC7EC9C5BCCULL, 0xE4CDDB628C3EEA7EULL, 0xFBAF53BAC92A8E3CULL, 
            0x5EF78E330D33FB0DULL, 0x2E9C0BEC7AD72ACDULL, 0xBBC6ACB778B7E471ULL, 0x6C86865082706D85ULL, 
            0x1EBDC3E19A6CC17DULL, 0x3FA02604C08E5417ULL, 0x284E1DBB3ADA404DULL, 0x629D814F89651DC2ULL
        },
        {
            0xAE6340AA2F81786DULL, 0x69C779579FFE3F7CULL, 0x0BF90F1ED6DCD3CDULL, 0x5460C0CA98F6BDF5ULL, 
            0xCD8BEF711F053A71ULL, 0xD4D16300C8DCC64AULL, 0x1C1BD3053B9DAF98ULL, 0xB0FB3CF101409546ULL, 
            0x3FBD4B8A2746B5FAULL, 0xF5129FDAEE2867B9ULL, 0xD1A36DF38F97A9E4ULL, 0xBFC57EDDF60FDECEULL, 
            0xB815F2413F76F744ULL, 0x236DFDA6217A3CA8ULL, 0xB93038F70B0D6121ULL, 0x2D75F1BA2D0B13ECULL, 
            0xE7B945243DA35B95ULL, 0x632B97FC77FC1E29ULL, 0x352199F8112FB7C2ULL, 0xBDECD3DD7988DF03ULL, 
            0xC40664365E2A66DBULL, 0x296EBF50D1A524D1ULL, 0x09AC8BCFC6C94627ULL, 0xC1477A76F83D0A1AULL, 
            0x980363849D45656EULL, 0xBD7DB98F0C544F6FULL, 0x583E2F0CCF12AE71ULL, 0x2F8B420BD6A5CC15ULL, 
            0xFE31A4EC071949C4ULL, 0xC778A85F4721E09CULL, 0xDB6156702152F861ULL, 0xD14585330281B14CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Arcturus::kPhaseCConstants = {
    0x2F4004CE57D1F6DCULL,
    0x0D2867BC0A7C0738ULL,
    0x7AB29673B1BEF51DULL,
    0x2F4004CE57D1F6DCULL,
    0x0D2867BC0A7C0738ULL,
    0x7AB29673B1BEF51DULL,
    0x7198075FC2A3BE16ULL,
    0xDA62712C59A367BBULL,
    0x55,
    0x8C,
    0xE4,
    0xED,
    0xB8,
    0x30,
    0x83,
    0x64
};

const TwistDomainSaltSet TwistExpander_Arcturus::kPhaseDSalts = {
    {
        {
            0x8B21C301E42FDB5EULL, 0x8986FCA7A2F89AF9ULL, 0xE67DD3BBCB7FE68AULL, 0x519503BAC146C481ULL, 
            0xCDCEA502F2476AC8ULL, 0x052559516886031DULL, 0xFA198E123CAE1B52ULL, 0x30DA196C9494251CULL, 
            0xEB85A25654500596ULL, 0x533FBC60A5CB2A05ULL, 0xC76E31CFE5E7D166ULL, 0xA3019ED580E4CE6AULL, 
            0x072419C67A4727AAULL, 0xF78068F86C32D743ULL, 0xC99413D4601FC247ULL, 0x14B65564C84D4604ULL, 
            0xB80721C047316724ULL, 0xBD0A655F9DED098FULL, 0x74AE91CBE2DABC5FULL, 0xA1CC0F05D8B335DFULL, 
            0x6282897D2357741BULL, 0x03F10644633E1137ULL, 0x36473C8EB9E985DAULL, 0x6F49CF9A61D163A8ULL, 
            0x8F292CF990449085ULL, 0x57C69F282097D37BULL, 0x74D58B13DA714C96ULL, 0x9D7766C5E038EA9CULL, 
            0x98E9984B8BF1026FULL, 0x12BC80D8DDB3EAB8ULL, 0x4034CDA7D97B69AEULL, 0xAB337E974D1DE456ULL
        },
        {
            0xE1093E89CF0D6156ULL, 0x4F4EDD319411F56CULL, 0x3476EDBF0314794AULL, 0xB64969F67F2AE792ULL, 
            0xE4051F843682F43BULL, 0x35A50830214D667AULL, 0x861B89C093BEA138ULL, 0x69D2653F5276F6E0ULL, 
            0x443B7878E20E840EULL, 0xED7A75072B566BDDULL, 0xDA8BCDD154D37990ULL, 0x9001E519331E942FULL, 
            0x577EAFCFDCB15C84ULL, 0xFD903D95ACC7CBE4ULL, 0x2062BD69A5EB35BDULL, 0x47C319BDD3BFA7D3ULL, 
            0x9C1EE708A1AA19EAULL, 0x8F77EE0C741637BEULL, 0xF32E072E0A92A957ULL, 0x29CACBE7FF0E2137ULL, 
            0xAAC134DEC6C1586DULL, 0xDEA9CC6BAFD5692AULL, 0x2A964ABDF9DB17D6ULL, 0xCF7BF7C0AA24BC99ULL, 
            0x4C3426BBE1ECF9F2ULL, 0x6234D3E0A151F4F5ULL, 0x9EC52764B6C7F8D8ULL, 0x959008CC6CD1788FULL, 
            0xF1B94309A20D4201ULL, 0x80B6732066459946ULL, 0x17B33BA3F5DC76DDULL, 0xDC8264ABE70891F7ULL
        },
        {
            0xE9430279ADF25119ULL, 0x903735E84646EE80ULL, 0xCFE9614687B5C562ULL, 0xCEF9F4BAC0515C1CULL, 
            0xF6E30A1A2CC60E21ULL, 0xFFA0FF7D1A1F68C6ULL, 0x016DCA5CBC7FEB4DULL, 0x9531C0B5EFF6A560ULL, 
            0x40F3A05C3AB640D2ULL, 0x9F32CFC2E3C03C81ULL, 0x44A24BE8F0B0CBAEULL, 0x232BC50FB9A40DA4ULL, 
            0xEC72759E0F41F53AULL, 0xDBFD51334EC1088DULL, 0xC5B2CA3B7FD42AABULL, 0xA9A191429703116CULL, 
            0x357491B3A93AC8BDULL, 0x7FD82AEA4549ED34ULL, 0x86C4F9B6B9B0F2FCULL, 0x424DC4AC654E3CCDULL, 
            0x7EDA80B43708990FULL, 0xCB2C5F9EBDC3B9D3ULL, 0x8BE4A23398F93CBDULL, 0xA9DC22593721AD91ULL, 
            0x05D46627093BF43EULL, 0xEC8A5B504B79F554ULL, 0xCC124A0404B36FC4ULL, 0xD0EFF38872E27902ULL, 
            0xE067DFDD4AF3DB36ULL, 0x3453AA3CD58B21D6ULL, 0x69B4E9E90C8C8425ULL, 0xFAAED13B065D3B3AULL
        },
        {
            0xA4BF2C65393462A3ULL, 0xEBE37D5C43E02EE1ULL, 0xB4983DFBE8FF4307ULL, 0xBED17E7EECC78111ULL, 
            0x82E59CE3BD041A87ULL, 0xA4FF9EFE84BF7C5BULL, 0xB18C6D99AC683E05ULL, 0x289B01FEF623EF56ULL, 
            0x4506A5550BF305F5ULL, 0x1CA9C753638E1950ULL, 0x5E185951F0B04385ULL, 0xE7A83C634F32319AULL, 
            0x8C0E8C947ACBFAD9ULL, 0x6FE29D22DAE1B9E7ULL, 0x1379A208A480C847ULL, 0x9984B0EA17A0388DULL, 
            0x764A416F487EA008ULL, 0x969C80D2F5C3990AULL, 0x801194A11FC15DD3ULL, 0x1F18EA31EC93EA96ULL, 
            0x388A22FA4AA23584ULL, 0x6CB980DE428B5729ULL, 0x021293B4B5E2FE28ULL, 0xB89DD7F674641333ULL, 
            0x99CC00A65A0B502CULL, 0xEA64E4D42F76430EULL, 0x67A2E5A0C48AFC0FULL, 0x4F8A367405F98170ULL, 
            0x02C0B11C29B9DE8DULL, 0xFDA6AF0ADEEAAE19ULL, 0x12DCCC857A746FFEULL, 0x7460A6D899A44D4FULL
        },
        {
            0x3DDB93418AE89238ULL, 0x4EEB2B7BAEC25F50ULL, 0x3737BDD7E01B4422ULL, 0x01FD9E0D32D6139CULL, 
            0xE50531F9E386C03EULL, 0x9082D27DA61C8F35ULL, 0x4399F6065FE6C1D5ULL, 0xA751E6239D85716DULL, 
            0xE144AC3779586FF7ULL, 0x2C198A9DC58A95F3ULL, 0xEA0EC08540A936C2ULL, 0x631D535D82640682ULL, 
            0xE882D488C8F62496ULL, 0x31E1360BB5B59C13ULL, 0x0CB3B1F905F2A4DEULL, 0xFC729321EA2EFD0BULL, 
            0x9F03848DC1951718ULL, 0xD3138E3C6E4C6D45ULL, 0x2872B2C90B53D5AFULL, 0xF44F3293B829964BULL, 
            0xD0C01524F0871318ULL, 0x73E5335346D3ACB4ULL, 0xE7D485857AEDA406ULL, 0x3D30A5F48870C97CULL, 
            0x8FA530CB04C50ABBULL, 0x70E5DE645224D10EULL, 0xA34731126FDC89C3ULL, 0x537E6A5FA2428514ULL, 
            0x9FD84B8212871AB9ULL, 0x9AE9CBB1C9B1D9D1ULL, 0x76AD3AD2B1D65346ULL, 0xBFCBD7C9C6BEABF2ULL
        },
        {
            0xC161F47247201D7DULL, 0x78A67AF4BC85E086ULL, 0x2CB20023FE0E609DULL, 0x739F7A48D02311D1ULL, 
            0x66494406F5E0097AULL, 0x100FF308A15A29D1ULL, 0x2D5D2AB2F27ECB61ULL, 0x172FE3A8A9FA1D60ULL, 
            0x8C9461353E97A435ULL, 0xD463917AF7EEAE7DULL, 0x7A374C704F14CA61ULL, 0x904B18CCA66DDBEDULL, 
            0x5F218E2813A4CEC0ULL, 0x39B428E70FDEA181ULL, 0x9500AD8099213A8DULL, 0x34D33AEDA356075DULL, 
            0x2ECB7811A64E3F5AULL, 0xEE7EF6EA833E1492ULL, 0x65D85DDC7819B8BBULL, 0xDB185DE7F9019B33ULL, 
            0x996156BF0FAD8989ULL, 0x08B006B6292A8277ULL, 0x0DA6D9232180185AULL, 0x0C2935082435AA78ULL, 
            0xA0D439945F0BC537ULL, 0x524DDA65F9635388ULL, 0x2EB5BD0D68CF4A92ULL, 0x4D7359FF62423098ULL, 
            0xD577D022651F34AAULL, 0xC6DA1A20CC149182ULL, 0xC7D1C0647AD50612ULL, 0xCB5F9BA07E6DC566ULL
        }
    },
    {
        {
            0x7FB1A02ED12C5CE5ULL, 0xE921B51DA61C5D33ULL, 0x9FEB79557F1858E8ULL, 0xDDD474173A63FAA1ULL, 
            0xA3B792FF4FDB49B9ULL, 0x4DF00DBF2B4A5730ULL, 0x12FAF895A7601DADULL, 0xFA75BE8286178EC9ULL, 
            0xB9D1CE15AE6C52E2ULL, 0xD9D1F1AA2DC83B79ULL, 0x7E57CF6CF7F2252BULL, 0x669F9EF70F9EBB26ULL, 
            0xFFAFEFA9C7743E3CULL, 0x8342CFF8283E28C3ULL, 0xF89A49C05E380B1DULL, 0xD4A81458BF3088B4ULL, 
            0xDFECAC421C2371CCULL, 0xE500E5F8951103C0ULL, 0x0E06EEAC6EA075EDULL, 0x03686220D589868EULL, 
            0x92BF0485A043E68BULL, 0x70663D584FC2D95DULL, 0x1246159833183024ULL, 0xA8061FFD2EE8CE3AULL, 
            0xEF276AFE318377E7ULL, 0xCEA886FD068E57ECULL, 0x43005BC84B65A42BULL, 0x95E0377A5F3DBF06ULL, 
            0xCB4ECE378A648E1DULL, 0xB010E78B7DF4E013ULL, 0x0A1B6E91DC1FFCBDULL, 0x63E3081DEE632609ULL
        },
        {
            0x0D8723C296AFA527ULL, 0x005F6B20FAE22F8FULL, 0x5AB20B14C9BD6B31ULL, 0xE116BC5769B57F77ULL, 
            0x7B9B0B7BA7859544ULL, 0xBC60F82440F82DB5ULL, 0x7B2E92EB7A09C442ULL, 0x68B169014BDAB788ULL, 
            0x1457D740A0E72844ULL, 0xE3B66F79C79BB58EULL, 0x4D972D5C13F085B1ULL, 0x13AC830F306B7D5AULL, 
            0xEC6BCDBC2AC7EDD0ULL, 0x90C71540939D38A1ULL, 0x56169E61C0DA3FECULL, 0x71A3094C45FB6C64ULL, 
            0xA33F520E9991EC74ULL, 0x9B1A2BD8D17C6530ULL, 0x5B46BFCE97C81CE7ULL, 0xF33A49D75CD0F060ULL, 
            0xC4A967132442F096ULL, 0x60B3B01F3332ED11ULL, 0xD24D8E225DCD219FULL, 0x8518D47645FA31E0ULL, 
            0xB1D3D8FDC861C473ULL, 0x418B0C72596D2895ULL, 0xACAFFDFEC4C679EFULL, 0xCDEC4999AE672A73ULL, 
            0xD4AED87E040D2598ULL, 0xB171886E8090573DULL, 0x5B0AAA3866696424ULL, 0x1191A263F9EED9D2ULL
        },
        {
            0x3ECB4A46DFD9E323ULL, 0xA8156BDAB113392AULL, 0x28C9263C4E9F9C88ULL, 0x93B21F800B8B0758ULL, 
            0x06A2CB795ECD400FULL, 0xB59331D648DDDC4BULL, 0x923A3EC2DC5A492CULL, 0x749920A7943878E3ULL, 
            0x0860D76E39B2FFC7ULL, 0x39BA1C76DCFE77E0ULL, 0xE5F495BD19D244EAULL, 0xA8952A78BD382F5DULL, 
            0x5A44DD395AC74FEBULL, 0x348802D4F51C9B9BULL, 0x094E35163CFBEEA4ULL, 0x82E6A6A90EBD111DULL, 
            0xCB26941E6BC7EFD6ULL, 0x50B38E522B1C1E92ULL, 0xAF8CC9C10215F188ULL, 0xEF5CDB3E461426E3ULL, 
            0xFA4D6E0CA7CBEEA0ULL, 0xEB029F08AA9B8051ULL, 0x25FA1B41CFEAA7BEULL, 0x54FB4D9FDC314469ULL, 
            0x8C806F642D908FC5ULL, 0x107F695B91DF48D0ULL, 0x9893198FC4B013E4ULL, 0xB76579429C980BEDULL, 
            0x2E2E9E6FD5D20B18ULL, 0xFE9E6B29B9A63048ULL, 0x6B0D27CA4D45109EULL, 0xAEBAF45C73A926FDULL
        },
        {
            0xE860EC84ED8490A8ULL, 0x9E21D59492BEEA0EULL, 0x17404D2358F32211ULL, 0x3DC5AACAC829BA70ULL, 
            0x53A6E7FAA8A6F5FAULL, 0xE65B4787625B9455ULL, 0xED0BFA2D8774DB49ULL, 0x4187B1323FD222C5ULL, 
            0x2D66EF9C4985D6DAULL, 0x068BABB3BAB9A761ULL, 0x896AF76861C50786ULL, 0x4C8A40F4872A6359ULL, 
            0xDD933E60CAD15139ULL, 0x63CCA0FF9634C27FULL, 0x7949C5343A38D646ULL, 0x298C202FA9F0B911ULL, 
            0xDDC5330A83ABE242ULL, 0x202FD8E94BADB6F9ULL, 0x6722FA25AB05482AULL, 0xCBEC29EB7C4DAC57ULL, 
            0x31CFFE0603C815D1ULL, 0x879648F6093879CBULL, 0x4331358A5890E4C5ULL, 0x692527DA3A7E201EULL, 
            0x984BA19ED50A9697ULL, 0xCCDC27F75EADB0EAULL, 0x1310097C6A59B0F4ULL, 0x2773441C6F11C621ULL, 
            0x66526EAB9C8BE3DFULL, 0x58BE78ADC39B68C4ULL, 0x0D52829D9B0B8DB0ULL, 0xF91DC4E10C844806ULL
        },
        {
            0xBBF53CFD5E8333FEULL, 0xDC8B42422C35D69EULL, 0x0F9A66D32AB6E1ABULL, 0x4787D1AFDE0B1450ULL, 
            0x90D0C7AD794C8C06ULL, 0xEE487D0BDF52EE57ULL, 0x20F2C0B4F0945511ULL, 0x4049BA4452BC36D1ULL, 
            0xD657F2B5C64F7A5DULL, 0x2B31D8DA5BFAC8D8ULL, 0xACF3ACC3EE6E3DA1ULL, 0x8A7610A9BF461E9EULL, 
            0xD0F61B10355A1B9AULL, 0xFBFEB17AC7C39D64ULL, 0x58877029D17423E0ULL, 0xA9DFFC534C1D3EABULL, 
            0xB0B22C9E363E4FF2ULL, 0xFC85C3B3897FE79FULL, 0xFCC8379BF518488AULL, 0xBED4189EC33C3AAEULL, 
            0x9B7A030F02967C7FULL, 0xC3A77B42AB9410F1ULL, 0x88AFD58F31143A6AULL, 0x68E5A9DE9CC39650ULL, 
            0x2CBA510AC7817761ULL, 0x6A260A5245733738ULL, 0xE76BC6F494055DF4ULL, 0x83DFFF90A48192D0ULL, 
            0x2A51E907013C8AF8ULL, 0xB1D022F3262A96C0ULL, 0x8DB347ED5D5BEB88ULL, 0x770ECA26C18B0F36ULL
        },
        {
            0xC2B9F9E72831C10BULL, 0xBCF35E28A40B50DAULL, 0xD7783CDD8766EF9FULL, 0xE08DA4317E11DB6EULL, 
            0x281EDEA97B6EA10EULL, 0x30489BB9F0055060ULL, 0x076AC48BBE3B9CBEULL, 0x2852CC452210272EULL, 
            0x38AE1F2CF1DDD2C2ULL, 0x6E4A66FD478E654FULL, 0xDF2BF9ABB24F6A02ULL, 0x8BAB04AFC73C294FULL, 
            0xB9201F072C351098ULL, 0x903F9CCDF1D39182ULL, 0x7FC774BEB8DE532CULL, 0xF14872807479FA78ULL, 
            0xDBDA0A3F7085DE54ULL, 0x79D970B89AA0C159ULL, 0xEFFF1E9A9493531AULL, 0x6E1AE1272BC84821ULL, 
            0xD4B183B0AE604A45ULL, 0xF1433F46E88D50BCULL, 0x67A237F64A312693ULL, 0x687C01DE1086B2B3ULL, 
            0x1658FBC63C307DB1ULL, 0xDE377FDD3C48D976ULL, 0x3217CDBB8E4DC222ULL, 0x8C6DA67C3F0FAA3BULL, 
            0x88EC3C6308D09F58ULL, 0xD0A55DE507ECB77DULL, 0x14DAEB927193D507ULL, 0x922DA2139584ABF3ULL
        }
    },
    {
        {
            0x9B1DF9B2C7409045ULL, 0xB39A877225367D0EULL, 0x535F1A8AC3F12C9AULL, 0x0F43C5BB5B37EA36ULL, 
            0x806CEB32E504B343ULL, 0xC521F15898243934ULL, 0xDDA42170840BA238ULL, 0xC9D04549FD277CDBULL, 
            0x74B313B9CB45AACAULL, 0x22A6705E5452743BULL, 0xAC4EB45CEE17311AULL, 0x265639A3FA2FEE14ULL, 
            0x6CBBE80A30BDECAEULL, 0x524548FA92C06C78ULL, 0x72653C8D1FA34017ULL, 0xAC491360376B5C3CULL, 
            0x9BC095720BB1A68EULL, 0xF37B44271D32C572ULL, 0x5C71360DCAE2EF33ULL, 0x698906DB227CE069ULL, 
            0x21DF5970B3E670D6ULL, 0x3D1B084E40AE1D4DULL, 0xE6FE7E0FD9CD9598ULL, 0xC239A66943C60275ULL, 
            0x8F6459C895E3FD79ULL, 0x20497B34E686B422ULL, 0xC35F2E2F805E77C2ULL, 0xDC57251170873228ULL, 
            0x3EF8E88E86AD48BEULL, 0x9F0E1FFE0B7DCCC9ULL, 0x6CB1D473696A6469ULL, 0x22840C9E3F55B1E9ULL
        },
        {
            0x04F5DC1969E4069BULL, 0xF072844EB8E25304ULL, 0xD648EB575D17A539ULL, 0x2A980706604166F8ULL, 
            0xC110DE3801C689BAULL, 0xC74193F2538F1C05ULL, 0xE46D0468CBC622C6ULL, 0x6C342F42082DE680ULL, 
            0x6E5A8D4D9BEC95FFULL, 0x308A3B99D6E906EFULL, 0x7B102F3D4908E33BULL, 0xD5604483F5A21E4BULL, 
            0xAD1435D53832B7B8ULL, 0xC1030943A46177BEULL, 0x5876C7147DC415C8ULL, 0xD618B065AB999565ULL, 
            0x13B6EA7876C7B772ULL, 0x43223BAD26D76670ULL, 0x99DFA1AE1D57DCCCULL, 0xB90FBC735FBC2166ULL, 
            0x18DA98625CA17D84ULL, 0x504E0BF4BFF527A1ULL, 0x9C74947CBF36B04AULL, 0xEDB3E7F155DAD869ULL, 
            0x7F739917C4741205ULL, 0x21B707321D056587ULL, 0xE9D205B14A4BF9F1ULL, 0x47809FF24D90FD71ULL, 
            0x1F1C0CF3D7EA663EULL, 0x32CA870AE52FE515ULL, 0x16C4A445DC9CA159ULL, 0x5AA8C4D431F4D4D9ULL
        },
        {
            0x8F18F24C946357B0ULL, 0xAFFD8DE5E5C14ED2ULL, 0x818E27EF75C0C28AULL, 0x3B0D4477BCE8F8D9ULL, 
            0xEA8B915DFB6203A6ULL, 0xEF42F2743178DEADULL, 0x3850D0D74563038AULL, 0xFAF48ED3816D9B59ULL, 
            0xE578DA711B34BBC2ULL, 0x793DE80CB16B42DFULL, 0x0152B4A07A23CF85ULL, 0x2B2C31AC13844102ULL, 
            0xA6F7B46043C8ABE3ULL, 0x0281FE984C52DCA6ULL, 0x089D52DCA5F247D4ULL, 0x7E40E7A38444E358ULL, 
            0x79C8875A7E76B7D9ULL, 0x2B7EB71746A54B4DULL, 0x7D64D74D70A603D9ULL, 0x7BBDFB8F86DFD5A7ULL, 
            0x812F62926BD96CA0ULL, 0xA250AC69D65C354BULL, 0x79A09FE2C2D97A84ULL, 0xF60F981FE03102B2ULL, 
            0x5F819A7D294FDF1DULL, 0xD01D9395388DA0AAULL, 0x324BE3EC9AA8B8B2ULL, 0x999A865025BEE429ULL, 
            0x9ECE774E0A633EF0ULL, 0x9E08E1D46DBF00F3ULL, 0xF2257A8A5F03CD44ULL, 0xAE3F1CB97967D65AULL
        },
        {
            0x40CA04136B75C511ULL, 0xA26A151DEF5907A2ULL, 0xA00255AA65D981CAULL, 0x8176AF5A78AE2622ULL, 
            0x4266094B7A728358ULL, 0xC1A41AE67C14D870ULL, 0x1981A62BC22FDD6EULL, 0xC8F2CE00D94F4372ULL, 
            0x81C9D861C742CF72ULL, 0x4AA9208F654D9BFDULL, 0x0AF22079FB2670BAULL, 0x4731FB0311676905ULL, 
            0xDEA66BC701B5D0D0ULL, 0xAF056A239CC904D4ULL, 0xCDCA39D83F0AA27CULL, 0x8DCAFF5A5A68E426ULL, 
            0x516B5D393509D39DULL, 0x6DEA65F6A4E301F6ULL, 0xFCC578C154C34B9CULL, 0x9504071CCFBAB75FULL, 
            0x8F66E967D1BE12E6ULL, 0xB38A2FAD45020869ULL, 0x07DF649317067A44ULL, 0xEE3A2C9648C2A606ULL, 
            0xBA731D3CC8090F8CULL, 0xAC8E61B5701841EBULL, 0x741C27129EB8947AULL, 0x055A88BC4323608FULL, 
            0x751DA93F8C89571EULL, 0x51F67C2C2916CE55ULL, 0xC79185E81E72DD0CULL, 0xE27E7C83FB6732F6ULL
        },
        {
            0x0484815659C87E86ULL, 0x71DBC7E08D2F855CULL, 0x554DF7899540F07FULL, 0xA9EEAB5AC79BA926ULL, 
            0xB859560AF6196551ULL, 0x369C1CC8E060AAC9ULL, 0x23A2C743E24B9280ULL, 0x9E5A7B4427971850ULL, 
            0x3F5E9FF10D316389ULL, 0xFCB735CD2006F2B3ULL, 0x678ACC3623D341BEULL, 0xE04262C9BE4BC325ULL, 
            0xD25CC28235B635D7ULL, 0xAFA119789A336215ULL, 0x84358A4726776D0EULL, 0x95123E5CDE57C885ULL, 
            0x04C6702535F71E28ULL, 0xEECC2CD1B41C6BF4ULL, 0x79F5FA328449CA41ULL, 0x5DEA8C3D1BB86F59ULL, 
            0x51BDFD9C8BD3F93BULL, 0xF37E4F4500527E0EULL, 0x387E5F255C297754ULL, 0x4921AA0024D33D0CULL, 
            0xAEB6A70B5641219BULL, 0xF6AABDCF057EB6E5ULL, 0xE1DA446F4D8F1EF4ULL, 0x30EBC82F6848EDDBULL, 
            0xE13123D6461143D3ULL, 0x1053A95E0CB4A918ULL, 0x0E00FADBA83FE0A9ULL, 0x2D2846664D01758AULL
        },
        {
            0x2005975240189761ULL, 0xF694D24456E45FB4ULL, 0x0DE4D9E065AA975DULL, 0x49E80A58CC50188FULL, 
            0x8CC9085781A5231BULL, 0x1252A93A4CF67173ULL, 0x9E3A99F3534C8141ULL, 0xE3676C9F4FB4F8EAULL, 
            0xC52011FCFE39329AULL, 0x80C4A444074F4991ULL, 0x96226BE588C63160ULL, 0x8AB2BB8657187767ULL, 
            0x6851B764135445C8ULL, 0x79D0709F841D789AULL, 0x56DF98E5F4C79FAAULL, 0x83C86C02941A4B1FULL, 
            0x3EC5A2CF60D44426ULL, 0x750B46F732B00DCBULL, 0xACA53554AECE084DULL, 0xAF33E1308EFD0033ULL, 
            0xA80169F0838F1282ULL, 0x5C19F1F40ED0D664ULL, 0xDAE0C697AF9469BCULL, 0x1F44890D616C9BEEULL, 
            0x986CE300A904506BULL, 0x2C1198F21B593136ULL, 0x3B7D69613A0DE01FULL, 0xDD5A0DD945B457CFULL, 
            0x4632BBC16520F670ULL, 0xDA13569AB0289430ULL, 0x84EA505905AF80A9ULL, 0x33965E6A08735238ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Arcturus::kPhaseDConstants = {
    0xFB79E39BC7EBEB33ULL,
    0xB3C0171F43127488ULL,
    0x8ADF4178F9D7109AULL,
    0xFB79E39BC7EBEB33ULL,
    0xB3C0171F43127488ULL,
    0x8ADF4178F9D7109AULL,
    0x60BE63BD5A3EADEFULL,
    0x054444EACD4E6C61ULL,
    0x7E,
    0x38,
    0xA5,
    0xFC,
    0x7A,
    0xAA,
    0x2D,
    0x2C
};

