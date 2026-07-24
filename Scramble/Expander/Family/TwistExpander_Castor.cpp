#include "TwistExpander_Castor.hpp"
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

TwistExpander_Castor::TwistExpander_Castor()
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

void TwistExpander_Castor::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF1DD744BB8E50013ULL; std::uint64_t aIngress = 0x8D706B23F1BE7192ULL; std::uint64_t aCarry = 0xEAD6394AF9CEC7D4ULL;

    std::uint64_t aWandererA = 0xF3F4EF31DECA7320ULL; std::uint64_t aWandererB = 0xDA1FC1E4B9DFDABDULL; std::uint64_t aWandererC = 0xB77BBB2BE597F1EEULL; std::uint64_t aWandererD = 0xE280D1899FBB3FADULL;
    std::uint64_t aWandererE = 0x9B65EE59715878D7ULL; std::uint64_t aWandererF = 0xD49F6492FBB989EEULL; std::uint64_t aWandererG = 0x9687C975A685361DULL; std::uint64_t aWandererH = 0xAB7753906F035B28ULL;
    std::uint64_t aWandererI = 0xB1E19E3E898637CFULL; std::uint64_t aWandererJ = 0xBE63D4AC00A6FAB2ULL; std::uint64_t aWandererK = 0xBB579F0BD27E503CULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xFA64C847546B99BAULL;
        aCarry = 0xACBCB71CB46BCFF1ULL;
        aWandererA = 0x92D2ACDD9971F230ULL;
        aWandererB = 0xDAABFD0089763C77ULL;
        aWandererC = 0xD9A88F047EBF348CULL;
        aWandererD = 0xC894E7C733E15A9FULL;
        aWandererE = 0xC89B6C5C047C4065ULL;
        aWandererF = 0x9551E05EBDA0CF9AULL;
        aWandererG = 0x837222D1B4316CF4ULL;
        aWandererH = 0xED9428766EF54CA6ULL;
        aWandererI = 0xED64C7448AAC19DDULL;
        aWandererJ = 0xB8DB3E06453A26D9ULL;
        aWandererK = 0x838C26A88C75ED60ULL;
    TwistExpander_Castor_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Castor_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Castor_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Castor_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Castor::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x9DD94F368E41F755ULL; std::uint64_t aIngress = 0x882EC2E2E8E4EC7AULL; std::uint64_t aCarry = 0x835E1DB207255A55ULL;

    std::uint64_t aWandererA = 0xE1D589C338E6543DULL; std::uint64_t aWandererB = 0xB7156498CE170814ULL; std::uint64_t aWandererC = 0xBAB729D972D87F03ULL; std::uint64_t aWandererD = 0x85103F6F94CB63E0ULL;
    std::uint64_t aWandererE = 0x99D9B092B6A5E30FULL; std::uint64_t aWandererF = 0xF8B514182779094FULL; std::uint64_t aWandererG = 0xC951B41396A32C54ULL; std::uint64_t aWandererH = 0x86BF91C24E66195BULL;
    std::uint64_t aWandererI = 0x84F695C39BB163ABULL; std::uint64_t aWandererJ = 0xD1AB5694371DD4A8ULL; std::uint64_t aWandererK = 0xD6BD72E2D989715AULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xC3208E9B4A3E062DULL;
        aCarry = 0xF5568AA137C5A560ULL;
        aWandererA = 0x85D9DCBD270EDB72ULL;
        aWandererB = 0x844B26C63AF409AAULL;
        aWandererC = 0xF3D6EDFA6A54BD82ULL;
        aWandererD = 0xA84D08162971DD7DULL;
        aWandererE = 0xEC2FD864A5E82D75ULL;
        aWandererF = 0xE42A895F7AB7058CULL;
        aWandererG = 0xC3F92FEBE388A52BULL;
        aWandererH = 0xDD8AEAFEA24E640AULL;
        aWandererI = 0x86613F537ED68F3EULL;
        aWandererJ = 0xE58FC8B7E6005085ULL;
        aWandererK = 0x8B01E9FA62F242F3ULL;
    TwistExpander_Castor_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Castor_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Castor_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Castor_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Castor::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x99E4957538FD19E6ULL;
    std::uint64_t aIngress = 0xCA5B7B880E96EF64ULL;
    std::uint64_t aCarry = 0xF6AB19A260EA6E56ULL;

    std::uint64_t aWandererA = 0xACEC5A6C16EB3A6FULL;
    std::uint64_t aWandererB = 0x852A6C6870F81D52ULL;
    std::uint64_t aWandererC = 0xFCB4A179E3741A6BULL;
    std::uint64_t aWandererD = 0xBF90C5F83EC8A49BULL;
    std::uint64_t aWandererE = 0xEEF115545FF68263ULL;
    std::uint64_t aWandererF = 0x961131986F8E941FULL;
    std::uint64_t aWandererG = 0xF6E339370539EFB6ULL;
    std::uint64_t aWandererH = 0xBD1BF4F2F4045CD8ULL;
    std::uint64_t aWandererI = 0xB96631F4EAE7CB1BULL;
    std::uint64_t aWandererJ = 0xEBCAEE79C3537E4EULL;
    std::uint64_t aWandererK = 0xADDBCB3B7F4CBAC2ULL;

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
    TwistExpander_Castor_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Castor_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Castor_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Castor_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Castor_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Castor_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Castor_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Castor_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Castor_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Castor_Arx::GROW_B(pWorkSpace,
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

// SmartSquash candidate 16 of 33
// Exploration cases: 100000000
// Nearest-family diversity: 938 / 1088 (86.21%)
// Total distance from earlier candidates: 14174
void TwistExpander_Castor::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    static_assert((S_BLOCK / W_KEY) == 16, "SquashInvestToKeyBoxes expects 16 invest fragments.");
    static_assert(H_KEY == 8, "SquashInvestToKeyBoxes expects 8 key rows per box.");
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 8U), *aFragmentB = aIceLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 6U), *aFragmentD = aIceLaneD + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1566U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 68U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 85U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1263U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 0U), *aFragmentB = aIceLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 13U), *aFragmentD = aIceLaneD + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1086U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 42U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1294U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1653U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 5U), *aFragmentB = aIceLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 10U), *aFragmentD = aIceLaneD + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 200U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 142U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1057U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1868U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 12U), *aFragmentB = aIceLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 5U), *aFragmentD = aIceLaneD + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1194U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1956U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 2015U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1248U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 10U), *aFragmentB = aIceLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 11U), *aFragmentD = aIceLaneD + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 756U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 71U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 385U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 712U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 15U), *aFragmentB = aIceLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 2U), *aFragmentD = aIceLaneD + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1341U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 267U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1119U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1887U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 13U), *aFragmentB = aIceLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 7U), *aFragmentD = aIceLaneD + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1740U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1764U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 176U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1095U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 14U), *aFragmentB = aIceLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 15U), *aFragmentD = aIceLaneD + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1534U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1079U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1264U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 2019U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 1U), *aFragmentB = aIceLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 12U), *aFragmentD = aIceLaneD + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1291U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 987U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 821U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 925U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 3U), *aFragmentB = aIceLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 0U), *aFragmentD = aIceLaneD + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 10U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 663U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 293U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1980U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 6U), *aFragmentB = aIceLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 8U), *aFragmentD = aIceLaneD + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 173U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 684U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 564U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1501U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 9U), *aFragmentB = aIceLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 3U), *aFragmentD = aIceLaneD + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1845U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 869U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1720U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 842U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 4U), *aFragmentB = aIceLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 9U), *aFragmentD = aIceLaneD + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 705U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 990U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 133U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1259U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 7U), *aFragmentB = aIceLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 1U), *aFragmentD = aIceLaneD + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1589U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 617U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 318U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1594U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 11U), *aFragmentB = aIceLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 14U), *aFragmentD = aIceLaneD + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1863U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 489U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1913U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 902U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 2U), *aFragmentB = aIceLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 4U), *aFragmentD = aIceLaneD + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 769U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1138U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1483U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1390U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Castor::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD47EAA22CC106320ULL; std::uint64_t aIngress = 0xD0CF06FD6C0E24F0ULL; std::uint64_t aCarry = 0xBDE00FB58F43E885ULL;

    std::uint64_t aWandererA = 0x9193C2FFFE90414FULL; std::uint64_t aWandererB = 0xC982F268ECBB8141ULL; std::uint64_t aWandererC = 0x83630C58AEAE5E88ULL; std::uint64_t aWandererD = 0xF2390065F12110E2ULL;
    std::uint64_t aWandererE = 0xE94CE2A18323BDC7ULL; std::uint64_t aWandererF = 0x80E09E68C2EE5CCFULL; std::uint64_t aWandererG = 0x961F761B9D258340ULL; std::uint64_t aWandererH = 0xC0D1A9CE1AC74ED2ULL;
    std::uint64_t aWandererI = 0xEB0738F024E45309ULL; std::uint64_t aWandererJ = 0x9A615A9792F7095EULL; std::uint64_t aWandererK = 0x9F99D09DED57930EULL;

    // [seed]
        aPrevious = 0xA83A85C16AC7315DULL;
        aCarry = 0xA88FC3A68EDFA3C1ULL;
        aWandererA = 0xBECEBBC1432A4898ULL;
        aWandererB = 0xF32DF408B8B3612EULL;
        aWandererC = 0x83E8AC8FFE5691D4ULL;
        aWandererD = 0x8A4F7C1103D99E9FULL;
        aWandererE = 0x982D59DDB7E10AABULL;
        aWandererF = 0xCF1B6D671418353FULL;
        aWandererG = 0xCA65293600B6F6BCULL;
        aWandererH = 0xBAEB89B60B2C01E3ULL;
        aWandererI = 0x80C8BF32E530E89FULL;
        aWandererJ = 0xF572551940085D5DULL;
        aWandererK = 0xF4DAB255BF11236FULL;
    TwistExpander_Castor_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Castor_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Castor_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Castor_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Castor_Arx::Twist_E(pWorkSpace,
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
    TwistExpander_Castor_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Castor_Arx::GROW_B(pWorkSpace,
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

// GrowA candidate 16 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 8216; nearest pair: 508 / 674
void TwistExpander_Castor::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6508U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1820U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4919U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 749U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5699U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6881U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5421U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 602U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7798U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5252U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5770U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6007U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2274U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2569U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6490U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1111U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1486U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1978U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1755U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 306U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1833U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 18U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1937U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1461U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 799U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1989U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1189U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 727U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1532U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 918U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 208U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 180U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1377U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1159U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1574U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1541U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
}

// GrowB candidate 16 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 8219; nearest pair: 498 / 674
void TwistExpander_Castor::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7614U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1802U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5527U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5778U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 747U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4993U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4443U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5764U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7625U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7068U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7762U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6560U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2280U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5414U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6225U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8105U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1416U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 451U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 624U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1798U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1629U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 740U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1933U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1100U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1179U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1078U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 969U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1164U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 36U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 535U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 954U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1106U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1591U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 796U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 835U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 586U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
}

const TwistDomainSaltSet TwistExpander_Castor::kPhaseASalts = {
    {
        {
            0x9A6BA22F22B7E461ULL, 0x74951F8706F9E27DULL, 0xFDECD46A73BAD242ULL, 0xA107B219AA4EBA09ULL, 
            0xE8711131F00E47F7ULL, 0xABAC7A90A21FDDF0ULL, 0x4873DEFF831E8CAFULL, 0xDAEA82427FEBDE0EULL, 
            0xD6783FD2B226DB94ULL, 0x59051826EF983905ULL, 0x7BF7E4F8ED209BC2ULL, 0xCB7A62E0945BA8EFULL, 
            0x947448C10D456568ULL, 0xA8AFCD2347971EEDULL, 0x9507E5CC7945545CULL, 0x040AE7550DD6A4D5ULL, 
            0x3A0C3C78F80F52C4ULL, 0xDF9E01450D446F61ULL, 0x753ED941E5EC9F73ULL, 0x1F1325962637D983ULL, 
            0x74D2DB404AD8F231ULL, 0x5EC0EB48B60E82F8ULL, 0x55BD77FEEE24F546ULL, 0x5F7D1A6BB002CA28ULL, 
            0x1CF96DDC567B9B28ULL, 0x4EC0D80E3227542FULL, 0xC61B993114609D5CULL, 0xFD6949041FA21114ULL, 
            0x2D0D6B9E0CADD759ULL, 0x0F552FBE7110C55EULL, 0x4DB6163E79587D56ULL, 0x02630D96420F275EULL
        },
        {
            0x71704CD76477C06AULL, 0x48600EF8E5AB4ACBULL, 0x7123C367240E6425ULL, 0xDB8CEB3032B9BE8DULL, 
            0x16550F937F5C0B84ULL, 0xE64D98D9ADD836E9ULL, 0xC0D7A1EEFA01C02EULL, 0xB72F9AB6D5735446ULL, 
            0x73A02178C9F6C3EAULL, 0x9897FFE190F3C8E4ULL, 0x9D9B10025C6B2EA1ULL, 0x93B91C25AC8BEE65ULL, 
            0x6BEBC067B38FC258ULL, 0x789F388438232E8FULL, 0x2B069A1A2E9BA8EBULL, 0x94C7CA3066332A69ULL, 
            0x49D1744F882DA045ULL, 0x6ADC609571C47D8CULL, 0x1AEA993EAE5CFEBCULL, 0x85F42188D46B3372ULL, 
            0xEF5700DF5FA2E83BULL, 0x3D3F71DCDECC9874ULL, 0xA25C5B344A8A4F46ULL, 0x6B2F46FD33B476F7ULL, 
            0x33E5B1E8B4591037ULL, 0x1798FADDB7752382ULL, 0xECE9D77190BC7578ULL, 0x6B0AD8F0B76809B8ULL, 
            0x387F4D05DBFB705DULL, 0x4616061CD33959D0ULL, 0x79D5A9A3C3F1BD87ULL, 0x5EA662500E2AE59BULL
        },
        {
            0x19FE7ACFA2AEAD08ULL, 0x4A6553CA82C2310DULL, 0xB8C7DC483D5B9B7BULL, 0x689AF3EC65B1C744ULL, 
            0xF8B242C052CBF468ULL, 0x939D5DFB89588F01ULL, 0x10619C794F0D72ECULL, 0x17C1D3FE5BE59875ULL, 
            0x6C2657CE7B9A18FBULL, 0x7660A66F2EB6F81EULL, 0x77CDB6A71E206E27ULL, 0x61B0A729FB3C86EEULL, 
            0x52314442BC0F507CULL, 0xC0379740A181D979ULL, 0xBF70F9FFEB98279FULL, 0x0516EB4073EE9F86ULL, 
            0xF714B3D1D20CA692ULL, 0x920DF897B833267FULL, 0x652F0C75AC52B82CULL, 0x6EAD313CFB0F9345ULL, 
            0x698BA5E2FE113CB1ULL, 0x79874A44BD3D5AA7ULL, 0xA0FFDCD9CB6C775FULL, 0x8B54BA05ECF70D28ULL, 
            0xDB627B4DAE2A278DULL, 0x579BF5D1A319B4CFULL, 0x50FC81AC9DB6A269ULL, 0x7E82778E355E4C58ULL, 
            0x656922B648B95051ULL, 0xDA3E73C5109BEFF5ULL, 0x6E526E74B0B712E3ULL, 0xD0189B5313B197DAULL
        },
        {
            0xD1B639EA96EB37F2ULL, 0x1C0AE141F5F7599BULL, 0x9F776F003C09376CULL, 0x757FB42D01598D9DULL, 
            0xA86AAF510C978124ULL, 0xC3461BDAC6B7A37CULL, 0x56E2490844E89D87ULL, 0xF64498B9A0D819F2ULL, 
            0xDCD5AE719204E05FULL, 0x5A0083CB0E77ED0EULL, 0xDACFA22365C259DEULL, 0xCDBCB38A78E65956ULL, 
            0x8DFAF0398396075CULL, 0xF157EAAB32A56192ULL, 0x8A5B2005F67B694CULL, 0xFA54D838B75B2384ULL, 
            0x058E61B54DCF2D51ULL, 0x062A2A6C2EE32C78ULL, 0x9DD294B41727C44DULL, 0x7B1CF831226F1D81ULL, 
            0xD72EC17ECDB9061FULL, 0x30DDEA0D811A163DULL, 0xB630F23642198160ULL, 0x5FDC754D235FADF0ULL, 
            0xB29F6861AD770504ULL, 0x591218065FBDFAB2ULL, 0x1A8B9036011750A7ULL, 0xB007E74421474448ULL, 
            0xC75637CB3FFF32DAULL, 0x48BDFB91B32656D8ULL, 0x3903BA4C673C55E3ULL, 0xDB3E83DD290F49DCULL
        },
        {
            0x2EC03E8AE888888EULL, 0x3A1BB4A9BEF139D7ULL, 0x815BF6BA28A6D50CULL, 0x4C2AE659D10269FDULL, 
            0xA777BAD4DDC0246FULL, 0x9A9A6B143621CD1BULL, 0xDCA7515739A68B64ULL, 0xE1B91E801D07A0B3ULL, 
            0xBD2635E44B8911A7ULL, 0x7A486E70E24053E4ULL, 0x7F60BE3E7FBBDD4CULL, 0x44945C721086A9EAULL, 
            0x67ABFA9C4E61BD12ULL, 0x03CC499D9B08C7B3ULL, 0x1C5E84A19093EF69ULL, 0x88226F757A03DD54ULL, 
            0x7CC46E6DD9FAF866ULL, 0x13C9F1270EDD4241ULL, 0x106CE1578CD15963ULL, 0x2F48F93B209AA3BDULL, 
            0x89B50DFBD576B573ULL, 0x2FCC514C0D02C0A8ULL, 0x48E14153CA466D67ULL, 0x1F62AB61C5A7FE63ULL, 
            0x1A233656240EE7FAULL, 0x0CB193CE37975387ULL, 0x2C403C9B3A16EC59ULL, 0x5DB5F22742BBE271ULL, 
            0x581521777AC76092ULL, 0x13146C504D11CE30ULL, 0x07842E409ED1BB4FULL, 0xE9C048A1EA9257B7ULL
        },
        {
            0x4044F327F859EEF0ULL, 0x22312B4ADD91CAB5ULL, 0x6602815C444C2669ULL, 0x8F51C23956C225A4ULL, 
            0xC3C375A2A91DDAA8ULL, 0xA684316CAA5648ECULL, 0xC639FC8672B53D24ULL, 0x85ADC1C6BB6DA96AULL, 
            0x0A6F34339236F935ULL, 0xCFF9551ACEDE22B9ULL, 0x9AEA352DD7ACCF32ULL, 0x2E26BB927BDA7AE4ULL, 
            0xE2BFE4D7443EDB33ULL, 0xF4C303D30E4FBF8AULL, 0xF7E7EC73C2BD2CF5ULL, 0x52CCA01814B3EE47ULL, 
            0x614FE580851C2BAFULL, 0xA38A45FF9F2249BFULL, 0x036655C1BEF5E4D3ULL, 0xD38C6ED382C5983CULL, 
            0x53A566B8462C556CULL, 0xA89E3EEE68995035ULL, 0x2628BEEF634AF433ULL, 0x7C3E615EA9360978ULL, 
            0x73817E46A321CC75ULL, 0x12D4D90D4AFB80E7ULL, 0xD2337E70DD44B15EULL, 0x4F157124C77DCBD0ULL, 
            0x828D34F1F890B421ULL, 0xAAA765815867C1A6ULL, 0xE538717C474E17AAULL, 0xF6D013CCE4D0B4ABULL
        }
    },
    {
        {
            0x6EBCDC54F819F858ULL, 0xB035360405B8BDA8ULL, 0x09B271FEF21A45B5ULL, 0x74F5FB6485938B46ULL, 
            0x29F5EED7A1525D2EULL, 0x0DB3ACA2FE1AF8A9ULL, 0x6AB5D53C2A673A69ULL, 0x5F1FBDBD6B734D7EULL, 
            0x176C1F9515C0B3B5ULL, 0x0DD4466C2B0CB700ULL, 0x70DE9AB51758621FULL, 0xCA11DAE97C080703ULL, 
            0x17945DA2E82BBB49ULL, 0x0DF95AB262EF57D6ULL, 0xE6EED19CDDC4E99BULL, 0x505F7F2F83D2BD91ULL, 
            0xB398C7C272DF3914ULL, 0xDE646C0A103B9592ULL, 0x7F570614E1CD314DULL, 0x378E38AC09034C88ULL, 
            0x98993A8215727FD1ULL, 0x791FA734B14A40CAULL, 0x1FAA1C715214D244ULL, 0x2DFA2F608C25FCF2ULL, 
            0xCA00BA12397D048EULL, 0xB2F3EAD9A50BD9CCULL, 0xDD4163A1B6984CCEULL, 0x48120FC67CE40970ULL, 
            0xD41234CDBDEA29ABULL, 0x4D40A715B93E6586ULL, 0xBAB5903E6F591E6AULL, 0x888BA8EE277A8CC5ULL
        },
        {
            0x5FDA97DF2A6EE829ULL, 0x123A61E4375C409CULL, 0xAA563E9312AEBCF2ULL, 0x76C82A41FBEEEBE5ULL, 
            0xF69CD565858990E5ULL, 0x540D843816BE19ECULL, 0x56A8A16E59363DF8ULL, 0x75B698133D6EFE39ULL, 
            0x9DEC9CB31B166351ULL, 0x298287BE65D1F10AULL, 0x9F91ED99C6BCA8FEULL, 0x540BFD62F56DDD89ULL, 
            0x9C80644771F02D6EULL, 0xF4EB0ECCBDAE1926ULL, 0xF945979EA6A08BA7ULL, 0x20C20FBF125CA5A2ULL, 
            0x3A1FCAFCC0EA866EULL, 0xA3FCAD592F0CB6D7ULL, 0x1FCA51947DCB9004ULL, 0x9477B477820961B1ULL, 
            0xBA02E7BC59B6CA60ULL, 0x4C6AFF90B0D4A641ULL, 0xC5AFADA64B459130ULL, 0xD5250855DA5392E3ULL, 
            0x460E9572B30F46D7ULL, 0xFC3AE8DC1B513953ULL, 0x3B6613C9D7194C70ULL, 0x590342F0E92C7BF0ULL, 
            0x050713ABA89FA3A5ULL, 0x1B21ED6D9CE7B2FCULL, 0xFDB5824977C58DCBULL, 0x9AFB6AA78A38068BULL
        },
        {
            0x8C8C1088EF6A427AULL, 0xBC70F1010FF8076FULL, 0x26862E86AFA4D070ULL, 0xAAA3BA9FEF6EA95EULL, 
            0x9EA1FADE3537C431ULL, 0x049A8C2E079A2D84ULL, 0xF7246E1E3038D8D4ULL, 0xDB3842836EEB9F94ULL, 
            0x19E2495B11EF7248ULL, 0xA8203933FCF082B4ULL, 0x307E1C6CA6744036ULL, 0xA2997E8D8B344697ULL, 
            0x897F4B235D97D774ULL, 0x921D4A8CE6EB35ECULL, 0x77FEE0CF73F2A586ULL, 0xA7A3707A3D392B6EULL, 
            0xC8A42569D9C1054CULL, 0x38A0341FD9DC5124ULL, 0x00A9C1CD4DDA9E5CULL, 0xA00904A41E13BBADULL, 
            0x37D99846714F4AACULL, 0x9A27E0481840EEBCULL, 0x3BA4ACFF666C7F80ULL, 0x3EF93B52F9B35EDFULL, 
            0xB1A1B5130EAD558FULL, 0xD36FD7F1F58D95B1ULL, 0x98B88E1CCF2D87FFULL, 0x3D6B683AAC73222CULL, 
            0xA12D12A91D4E3E21ULL, 0x872D5A4F5A2A5459ULL, 0x5BE9033B63A31EBDULL, 0xEDAE9EEE3ECDF585ULL
        },
        {
            0x467969A3B9CC436CULL, 0xFA326E0A2EF17FDDULL, 0xE3667301EA78349AULL, 0xD801F5ED5D5CC729ULL, 
            0x2018D5547B9C438CULL, 0x72FCAEA23B1D5623ULL, 0x9850F95151F1961BULL, 0xC5701DD991105E02ULL, 
            0x9C8052DB44FA863CULL, 0xE10DF941A437805EULL, 0x0C0E57EBA735AE18ULL, 0xF7FAA4B80642FAB8ULL, 
            0xB41CEAD8C6842D57ULL, 0x764BE9D9E8E07B0FULL, 0x7E26A22EE247D76AULL, 0x649C665BF2FED4B0ULL, 
            0xB14ADD3FBF136AC7ULL, 0xBF4450BBAC92CD53ULL, 0x8B7A138C546FEAE4ULL, 0xFDF0C47A72A772D7ULL, 
            0x7CB5F679393A2E14ULL, 0xF814A4E54EDF0FDBULL, 0x4AD725F5A532E86BULL, 0x35954B8CF197A1A6ULL, 
            0x510F33895B23FFDFULL, 0x56AD6824871141A2ULL, 0x66CC507A6E9A9512ULL, 0x86D1E4647FB3AA81ULL, 
            0x8F5ED24E892E08B2ULL, 0xC82A8BB4FD2EA4E3ULL, 0x716970D2F371D40CULL, 0xC44D1D8F5D45B7F6ULL
        },
        {
            0x6782DDC7C5D6DAE0ULL, 0xB7B0EBFEA378D2B7ULL, 0x0EDED9F8380B1E46ULL, 0xAC70CE83D32F5CBDULL, 
            0x07F8235FEA07379DULL, 0x78235876A5173741ULL, 0xA524BF106A8AAFF7ULL, 0x1FF2D249E41C1DDAULL, 
            0xE676E04FAE639F11ULL, 0xCF5040C2157BC466ULL, 0x583A9125C2488784ULL, 0x6472F29D335F2680ULL, 
            0xF29309D9094FE13AULL, 0x612B17605CBC2781ULL, 0x5C14D20D0EE94DECULL, 0x4ADBEE1513010F52ULL, 
            0xEDD794107E3179ECULL, 0x54FA6014A021F5B9ULL, 0x411797EC9BB8B645ULL, 0x7D572820E773324EULL, 
            0x3DEEFA6B4F61BAFCULL, 0x9C35C1556CBCC60CULL, 0xAD048123CCDCFD4EULL, 0x1CAC822DA42CF0FCULL, 
            0x5A2CAB3949485AE0ULL, 0xFC20D95CB70B4705ULL, 0x768B8FF72CA4DA26ULL, 0xCEB16CEEF0F8E655ULL, 
            0xCE5AE97D2D8B31ACULL, 0x05251D9D31DA5CB5ULL, 0x102B25E9EF776CFCULL, 0x3CD9EC27ACDC86DDULL
        },
        {
            0x7CDD5D4085BBC4AFULL, 0x632CE70542B6A186ULL, 0x13FD28576C62A5FBULL, 0x5C897473141171D3ULL, 
            0x06696C812E1CF7B7ULL, 0x95407BE8A5B4333FULL, 0x9E0AD266D0707E71ULL, 0x4FC81D853C20D9D4ULL, 
            0x39BE5F469356705BULL, 0x3BA7716BE8826323ULL, 0x3EBF438E9327DC58ULL, 0xF1B84B537EF4426EULL, 
            0x7F272A2C2E4E4B49ULL, 0x2FAA9ABAD72821B5ULL, 0x678F0BD47A4511FAULL, 0x7E149A7666F9F258ULL, 
            0xA33C5DCEFC78CEB3ULL, 0xF6EC0C2FC7EE22E5ULL, 0x6DFAC8C81671B3A1ULL, 0xAEC765613ABD26AAULL, 
            0x28880D9741DDAED8ULL, 0xEA38661136BEE0CDULL, 0x75C596A0D24BA539ULL, 0xE2A6BC52BD310DD4ULL, 
            0x1759F056EF238047ULL, 0xDDEA74814C5DA527ULL, 0xE27B769ECB0DC07BULL, 0xFBCCEED6CA9D0DA3ULL, 
            0xD6F7E0F9DD46EDB2ULL, 0xBF9A41FED6B9AD81ULL, 0x8A429BAC99673DF6ULL, 0x42E4DB13088F554CULL
        }
    },
    {
        {
            0x2DC93965AB76381DULL, 0xB3EC546FC5E09F8BULL, 0x9C7B3AB66DA0343BULL, 0xBFC64326D1FD12A9ULL, 
            0x505B4F8A4340F7C9ULL, 0xF861BC1A707BBBBEULL, 0x43ACC025A47B2979ULL, 0x632A89B942877544ULL, 
            0x0D00A8BACB71615BULL, 0xE04C33D279C776FEULL, 0x0DDF4594BBD5E5BEULL, 0x667E69941EFD9BCAULL, 
            0x799AE8A474C6074BULL, 0x69D88614C65F546CULL, 0xEF8A397EEBFC2E33ULL, 0xD5F0979574A2C19BULL, 
            0x1D8C99CA39CEC09BULL, 0xF1568B467535451CULL, 0x1DCD6381C16FBA6DULL, 0xA72031DDAD44E8F7ULL, 
            0x937298284685833BULL, 0x46D6188E11DA7F6DULL, 0xB4A070E9AE0F976CULL, 0x0360AF0F173D260AULL, 
            0xED8F4FDC06D02BABULL, 0x1C2D8CD80224FB17ULL, 0xD47B825BE41F8E5EULL, 0x9C38947C2A094039ULL, 
            0x4651E8F6FDA50778ULL, 0xADF5D7132CAB5EE7ULL, 0x83FD63D7100D7FF3ULL, 0xE0EB83AF63939313ULL
        },
        {
            0xF89B58D7A858405BULL, 0x21FBACBC6BD638E5ULL, 0x4A5DA879AFA4813AULL, 0x832D356D464C4DBAULL, 
            0x69C5ECCC8D95D566ULL, 0x639661FC02E21001ULL, 0x6FCC69B33F4A1316ULL, 0x0869EC0F2A9EF6C4ULL, 
            0xF197096CC0E85984ULL, 0xCD57A6D60DE5E6A2ULL, 0x82D3F4D718F1F9EBULL, 0xC4246E572E597E09ULL, 
            0xD6F5B46853DBE2D7ULL, 0xD5BC89333E0E4625ULL, 0xCFE662D73B792845ULL, 0xA9B87EEF91190481ULL, 
            0xADD4044D74C276B5ULL, 0xFF6B5F7039C7E904ULL, 0xE7329E507B6EFEB8ULL, 0x71640AB5EFEA13D2ULL, 
            0x441F53C3547C3D30ULL, 0x1B0BAE672DABEEEDULL, 0x6B81438B67E5237BULL, 0xEF59D8345850E9D4ULL, 
            0xB1970D6A7A18F513ULL, 0x32BABF17412E07E5ULL, 0x9A2B6FDF04B29DEDULL, 0x4E77F20487DAC86FULL, 
            0x9F65457629B6D6EBULL, 0x0D303D682398C298ULL, 0xC1102FFEE01C1EAFULL, 0x10AB992D66B38A62ULL
        },
        {
            0x2837397514F8ADB8ULL, 0x361C82ADA9B13393ULL, 0x0303EC67FD8C4851ULL, 0xA7B0FCD73BEA7272ULL, 
            0x84A910A3619865B3ULL, 0x4D269129B3F4ECA7ULL, 0x5A0ACE3A789A2440ULL, 0xAA32A1C04D90C83AULL, 
            0x9E0BB4E0785D67E3ULL, 0x67B3061F6905548AULL, 0xA2EB527C7BE65E62ULL, 0x5C7BD3E5AB8C8B2AULL, 
            0x3DE3EA98EB6A2326ULL, 0xE018A486DAA75FA9ULL, 0x3961FE929F7D2CBDULL, 0xFA47D0A78A4FC9B6ULL, 
            0xB243720DF4358616ULL, 0x57638D5D689612C6ULL, 0x648B4EF4C2A47D64ULL, 0xBF415980E2155EB0ULL, 
            0xDE5204214481D199ULL, 0x44DFD16DC493F4C4ULL, 0xDC7147F617B3E6D3ULL, 0x634343FF037699A9ULL, 
            0xE285AD293575EB2EULL, 0x57E071816A5C8281ULL, 0x9CB5D674CCE0F1F2ULL, 0x2CCC4C1785788376ULL, 
            0x3DC49710398DF3B3ULL, 0x0B12EE69044D06EDULL, 0x903297D5BAFCBADBULL, 0xD6F458152684394BULL
        },
        {
            0x701BE4878AB82994ULL, 0x882E3294E98D3274ULL, 0xEE7E1A37B1219052ULL, 0xFC6ECE9E7808E4EEULL, 
            0x69BBBA96025B38C5ULL, 0x23C11500880D7D74ULL, 0xCF6E224C93796C25ULL, 0xF28F297522076A66ULL, 
            0xE996F10D3ACFDB43ULL, 0xBBBD552D2F6108E1ULL, 0x2E136EEB8F027D3FULL, 0xBE6EE0F410297C3BULL, 
            0xED49AC1A4E381231ULL, 0xC58D65CBA1C9D000ULL, 0xF9657101BF668E8AULL, 0x89348F19728300EEULL, 
            0x7E298E3D38ACDD67ULL, 0xC84A33E4F4286EA8ULL, 0xB9BDF99C54995E2CULL, 0xB137B737A77354DCULL, 
            0xEA0E75FC007691DAULL, 0xBB762D742883E1B6ULL, 0x856856B3BE0435B8ULL, 0x78141EF5150BDA01ULL, 
            0x8ADC35527F46CF16ULL, 0xA1B7AB5A02371B6AULL, 0x8E99DAED70612F07ULL, 0x38C5C3D78EB35039ULL, 
            0xDB8D9BD44D786EC6ULL, 0x4D6AA845307CE483ULL, 0x9DB12F1114F84286ULL, 0x8620DD136FF41EEEULL
        },
        {
            0x59D30B21931A2AE8ULL, 0xD23C1A1EDDBB2952ULL, 0x144C7E121DA87152ULL, 0x72645F3E843A5827ULL, 
            0x98C8B3581E1163E4ULL, 0x4E029B2033BBCEBEULL, 0x6D5099070BC9D8DEULL, 0xD64A6C43F4A034D9ULL, 
            0xBA76C29D7C5DE697ULL, 0x75D3D53F50FE9DC3ULL, 0xAF9A4A4AC99C9B56ULL, 0x334905D419E97C72ULL, 
            0xC18140143CADD7DDULL, 0x6AE87C5F38D5A896ULL, 0xF94C614109EC03E1ULL, 0x9FB539EEA5E38B3BULL, 
            0x550D992472D34855ULL, 0x4273CC6989788E83ULL, 0xF9B2C21FF6A6F163ULL, 0xD58009821652DD29ULL, 
            0x3E585AAFDDEE6A89ULL, 0x3693FD2AAC252F13ULL, 0x52503446C43E64C6ULL, 0xA7AF742E30E1F32CULL, 
            0x63F0615F6833657DULL, 0xD89B69CDE63F4D05ULL, 0x814142E0BDB1133FULL, 0x09992F1BD109673FULL, 
            0x235447C1FEAF2E75ULL, 0xB54576D91A91D951ULL, 0x578D99434450E752ULL, 0x65A1B86AC97B0EA0ULL
        },
        {
            0x35C9F36070A4FDB4ULL, 0x81D1D9A5A8553883ULL, 0xF62076CA6C694BD0ULL, 0x65B1DE708CC065E6ULL, 
            0x32F984EBF39A50BAULL, 0x87E8105C9A45E6BEULL, 0xE689EF266BE8D467ULL, 0x5E67822FC6C36C7BULL, 
            0xA930E6B969CEF7ABULL, 0x91A33341C9FDF204ULL, 0x6EE54345700B6FB5ULL, 0x2415F9DE3636633FULL, 
            0x2D2B4444E8062419ULL, 0xC5ED87B584DCF971ULL, 0x92DDBB7EA4FDB411ULL, 0x0F218ABBECA811F5ULL, 
            0x6A6CE231E0F4ED5EULL, 0x85AB53DB8E492095ULL, 0xC5751C1527C3E617ULL, 0x2382718B2FBC3B01ULL, 
            0x1E5C45397444E424ULL, 0xDFBF9F4ADB10414EULL, 0x86FA1C86B09E7917ULL, 0x22EED57D03D7FD4CULL, 
            0x36028B96E8DC47B9ULL, 0x09B4AA9FD3E09748ULL, 0x3FE061A847CE339EULL, 0x32A6CE9F4AB1DBC7ULL, 
            0x004B0996F1D7D5EDULL, 0x3ACBED467F91498AULL, 0xACF2C083FE0C83EFULL, 0x96235AFC363D4E84ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Castor::kPhaseAConstants = {
    0x8AA5A4EE237E872CULL,
    0x8BD188C3E84D3B0CULL,
    0x3E63F8C8A081756AULL,
    0x8AA5A4EE237E872CULL,
    0x8BD188C3E84D3B0CULL,
    0x3E63F8C8A081756AULL,
    0xF430A26AAC016902ULL,
    0x2AAF4EC3F980DCAEULL,
    0xFE,
    0xDC,
    0x30,
    0xE4,
    0x6A,
    0x4E,
    0x1E,
    0x4A
};

const TwistDomainSaltSet TwistExpander_Castor::kPhaseBSalts = {
    {
        {
            0x27DE8FCB873195EFULL, 0x04F3FE22890B729AULL, 0xB4906A3039B0B91FULL, 0x047088A484A0822FULL, 
            0xE56336BCF2738650ULL, 0xAF11D1006DC26B31ULL, 0xB359757012084DEBULL, 0xAC0B08122FD4F1B6ULL, 
            0x85DA893C047A7903ULL, 0xE2EF4738312E85FAULL, 0x52A8AF01D500C1B6ULL, 0x186FDC8A4A992AB3ULL, 
            0x1BF3A33097214B1EULL, 0x5E066AB4B228E6EAULL, 0x01516CD6B8D96EABULL, 0x5A8A7A0E31AA9D5AULL, 
            0x474D5E697D0E7BCBULL, 0x97F3AA4EC54A5B6EULL, 0x13040C3CCA2FCAA5ULL, 0x627845504BA7E7A7ULL, 
            0xD23EE8AE9AECA2CCULL, 0xE8C85ECA6B390BA7ULL, 0x4C08055F320AB11FULL, 0xED943B2F8F874307ULL, 
            0xDD051DE22C3B8EE7ULL, 0xCB0AD974B70B6619ULL, 0xDC958C8509C8EE58ULL, 0x0BED0CE93BF2BE3BULL, 
            0xDFA8BA8BAE4E80DEULL, 0xA04AE35147E1852DULL, 0x2A922C8D15466BE5ULL, 0xE4B6A0B10A8CDCA2ULL
        },
        {
            0x36B7809AFC137EC7ULL, 0xDAF7CF02594C022AULL, 0xFD336BC6F67EDDC5ULL, 0x070E204CBB6DDCACULL, 
            0x6D7E012D310D7EF6ULL, 0x872CE8A3C4DAA5A1ULL, 0x44AA4095700A213BULL, 0xA97B7CB156C610F1ULL, 
            0xBA76B8EF5CF62AA1ULL, 0x0C0BF46DF5CEC492ULL, 0x97B3DC80EC72658BULL, 0xE0FD0BD1286E7695ULL, 
            0x8F6301F5EFA1EDD9ULL, 0x03C7087B5DAC94E4ULL, 0xF6C509FD33344AD5ULL, 0x24A0979330B0F258ULL, 
            0xDADDC843080C3C08ULL, 0x774B9F6996A59E69ULL, 0x87F9D7CA0483E7AFULL, 0x5DC9088256C38E4CULL, 
            0x0FCFB3E69EFAD813ULL, 0x1FD6C9E1CBE73592ULL, 0x811E62E603D383FEULL, 0x1D1BAF648E13DF7EULL, 
            0x8350B1EBF8E0D6B6ULL, 0x96F87EA657306CF5ULL, 0x8F753006C9D909B4ULL, 0x45E0238DDEFB3D31ULL, 
            0x5A9DFDC0044FAC70ULL, 0x5E7BA305386B9137ULL, 0x69B97A940933FEAEULL, 0x2F36BAA68CE72758ULL
        },
        {
            0xFF8DDD3B23F25C53ULL, 0x58495B5AA7CBAEFFULL, 0x932655907E4B3692ULL, 0x9EF6244DEDC1B3A7ULL, 
            0x5B53FAE20309E8D3ULL, 0x0BD7AF28F81355D8ULL, 0x06306CEEE262B8E2ULL, 0x8EBEA5F9307546D0ULL, 
            0x3B5120F35B3AACB7ULL, 0xB8D2C4E494EC02EAULL, 0x892C9BDE0D134357ULL, 0xB91A8BB5F8058805ULL, 
            0x48EDB40201EEB676ULL, 0x93F8E3F151535621ULL, 0x34EFD5F0F3FBA0F3ULL, 0x8ED321FBDB96B6A6ULL, 
            0xB523CAA87C0D1859ULL, 0x8E2251D848B36800ULL, 0xA2DB1AD9F4023C4EULL, 0x49D250AE8D7D2DA9ULL, 
            0xE350CF03D503D302ULL, 0x0AE6120DB4A4E6CAULL, 0x99F532467181D0B5ULL, 0xC7FE88C49C74C3FBULL, 
            0x39D959D473F31132ULL, 0xCED79E646FA786F2ULL, 0x369F7184A58E7C2FULL, 0x17769CEE0EFA438AULL, 
            0x416EF8A26666B39DULL, 0xFCEB25BF56734D01ULL, 0x6492BD20F91B58F9ULL, 0xC8A16544D9D53C9CULL
        },
        {
            0x031AB75B0BF4503DULL, 0x36A87DCF5956A105ULL, 0x4941094C6F9798A4ULL, 0xEFC4E0B47FF1F20AULL, 
            0x6A9F006DE0795E9FULL, 0x0ABD9FBEFE08930FULL, 0x907C20FAB172B171ULL, 0x7BFFFB78DAF74954ULL, 
            0x594796D7F39CE94EULL, 0x1CB671AA5012A676ULL, 0xF6641391493BB17AULL, 0x7AABA3D00751443BULL, 
            0x966EEB7B27B22DBAULL, 0xB6B63B775CC8D2D1ULL, 0x1B2257A1B77298DFULL, 0x8D0898D274D60616ULL, 
            0x7B206789C55E865DULL, 0x64902DFF39D3EB56ULL, 0x4CA4BD4BB27A370FULL, 0x6D3617322FA289DFULL, 
            0x6F3E1FDAAF8AA40CULL, 0x27DE79963A4EAF99ULL, 0x399728C999978993ULL, 0x5B489A308FA42933ULL, 
            0x5329677C4BB00462ULL, 0x7CDD553FC91D709AULL, 0x2146105FD94602A5ULL, 0x63A8AD1ADEF71F54ULL, 
            0x56BD02DD6F9EC23BULL, 0x8497A94183C86F6AULL, 0x8E9006E1B9D9A27DULL, 0x8B2D9F615A031FB8ULL
        },
        {
            0x4FF319B6F32879E6ULL, 0x3F7F48E2DB6D966AULL, 0xE8869A55FD688A30ULL, 0x73CC9202A392C5F6ULL, 
            0x3A324F9522A0A04BULL, 0xD203D96547350E45ULL, 0x8A9B44ADE16F33CBULL, 0xE95ADE86FD651C04ULL, 
            0x5C98580F40DCE87FULL, 0x12FDD673C7074CFAULL, 0xECAB8FDA54DC01E3ULL, 0x823CA159D03BC78FULL, 
            0x8ABA19FBADF35AD6ULL, 0xAC6BB7323799E2AEULL, 0xB0F5DAD91A3585FCULL, 0x4CF6C228B26BBCDCULL, 
            0x952A57FC449FDA0FULL, 0xBDC98C0CD0DC9372ULL, 0xAC1703E6597EC360ULL, 0x0B02D2D139D124BEULL, 
            0x60B620F3A32CD853ULL, 0x579DF585EFCAEA12ULL, 0x8BB98BE5276A30E5ULL, 0x9F2887D167E806ACULL, 
            0x3097D56E460AD29DULL, 0x7F98C11FB11F2E90ULL, 0x1E865B964AABEAA4ULL, 0x6C55F0D6E9D8D82FULL, 
            0x18AE186DE4077B72ULL, 0xF8D770C2F1652AF8ULL, 0x7BC02ECE5FD58E03ULL, 0xBAABBCDBCFD557C5ULL
        },
        {
            0x2AE25A77527D0660ULL, 0x5557066764043805ULL, 0xC2BC7AAD8409C16CULL, 0x67A0D09B17B341C8ULL, 
            0xEA2E048610A295E0ULL, 0x82936180BDCF4B38ULL, 0xD922D7F70CE8D50CULL, 0x015BE687FC05D78FULL, 
            0x9A8A9983F39BDBFFULL, 0xBE5F01C1D1D8EDE0ULL, 0xF04BA93D4CA3E5ABULL, 0xD6369C4E211D106BULL, 
            0x7D762F7B732BBB49ULL, 0xB294587CB0E5D81AULL, 0x6E4A541F3BC3A613ULL, 0xBE0555AA79FD5DE4ULL, 
            0xCD3D6BFEE9B78867ULL, 0x56561DC77555ADE7ULL, 0x1F5D94E330A0F7F4ULL, 0x871A3493371BBB17ULL, 
            0xAF98F8E88D90AE38ULL, 0xF009E4E5F1F33676ULL, 0x89595D4D03CDE3D3ULL, 0x9291A4CFEACE9286ULL, 
            0xCF16C86ED87555B2ULL, 0xF3F5FA6B9506CF6BULL, 0xB6B61949E785FCEBULL, 0x9A83D8D00DA3BCE0ULL, 
            0x7F2035F981BFFAF2ULL, 0x1593CEAEF9959A1AULL, 0x4A80AD90BDF747CAULL, 0x3628FA6CD629C3CAULL
        }
    },
    {
        {
            0x65FC534E518EB29AULL, 0x6EC04C470308734BULL, 0xAC47F5F0251067FEULL, 0xA0EF3A0AE5035AB8ULL, 
            0x6996BAA14F120C9CULL, 0x43174EDC10ABBFE3ULL, 0xD9159A96956580E2ULL, 0xB3A2EB41C7D843BFULL, 
            0xEE834F671E615096ULL, 0x233D6DCB688BE60AULL, 0xD5EF644E68E3B70EULL, 0x4F7AA210D711EA0EULL, 
            0xD58D4BBA1DA582EAULL, 0xDA42272613CED1FAULL, 0x6E2C321D91EDF634ULL, 0x3353A7B61646597AULL, 
            0xDF3C583DA387F206ULL, 0x4A6006B1022F47C2ULL, 0x8F4761FE29B5C99BULL, 0x524B71E3E9DF1991ULL, 
            0x88FFA9E15FECF6A3ULL, 0x734E64081B1EE8B4ULL, 0x5D2D5ABA3D4538A9ULL, 0x4FA0037B47CBD7F0ULL, 
            0x6399A2298F0C3B26ULL, 0x2B074710B9E5D5C0ULL, 0xBDC44366780538ACULL, 0x90B4DF3A99717833ULL, 
            0xF4AEB82835E78D59ULL, 0x23FD9903D99FBFFBULL, 0x81FDF8B1A020E5ECULL, 0x1965ECC92C6617A0ULL
        },
        {
            0xE131108922B6B541ULL, 0x1FA03C7DFC6C0DBAULL, 0x80B33CE5642B734BULL, 0x678FD79B79AD7D3EULL, 
            0x2B81B4E5FAF88D1AULL, 0x8EE97C6C377B6C04ULL, 0xC32AF4E0406E5A64ULL, 0xCBACF23DFD91EA25ULL, 
            0x584BD14BE5B679F6ULL, 0xEBBB78BFD69410B3ULL, 0x8C714F348656BE83ULL, 0xB4C1C38407939482ULL, 
            0x5AB4309796B89038ULL, 0x1937A2D412754BF7ULL, 0xA2E8D794A5DBE5A8ULL, 0xFAE7EE1064B0E191ULL, 
            0xF1ADCDDA74CB125FULL, 0xB49F9B4A801FA7C3ULL, 0x06ECB3BED595C9B6ULL, 0x48B351D891A03F32ULL, 
            0xB29AA0510C081013ULL, 0xC23C7C2C184AFB0AULL, 0x4001079A8BC11926ULL, 0xD6E0C96CFC818D58ULL, 
            0xA45DC289CB27ADDBULL, 0x6189943CC69B62A2ULL, 0xD4C99E96DBF01DC5ULL, 0xFC64B13393BDED81ULL, 
            0x3E49F40949D786A6ULL, 0x1B5C63BBAB086C83ULL, 0x2952A53E01F61DD4ULL, 0x7B6F96E802C1DF83ULL
        },
        {
            0x7B03868407000B01ULL, 0xAA289D750776879AULL, 0xD17FC53071945BECULL, 0x4B920504BF6E9171ULL, 
            0x266FD3ECAD129692ULL, 0xEA64CA45CB4AA067ULL, 0x7D18B63AFB3CB7A8ULL, 0xD5744FB694D626E8ULL, 
            0xC0796342C918D988ULL, 0x21986DACE327AB23ULL, 0x1BB43CAE68758CF1ULL, 0xD61E415CABCDCF93ULL, 
            0x9BF5CC9980142FC2ULL, 0x099F8E24CD2FCC00ULL, 0x1DD896C950496FDBULL, 0xA848FF47A6F65DB5ULL, 
            0x30E64720BB2A2D24ULL, 0x61BBFD6D7935549EULL, 0x6A191AD82E17B4A0ULL, 0xD49995BB90BE8C0BULL, 
            0x44F6F3433E7FE933ULL, 0xC047030F3D7D4EE4ULL, 0x40F04DCBA83DC500ULL, 0xA3DDFCB019832A6CULL, 
            0x6A6AA298E3D58EBEULL, 0x06D05297669B7F6BULL, 0x530ED828910B9EA3ULL, 0xA5D9559D85DC5E86ULL, 
            0x208921A1A1D9A449ULL, 0xBFDCE7135180CF58ULL, 0x63E3F73AF8296944ULL, 0x779C5A1F9498C03FULL
        },
        {
            0xF71096A3673BA742ULL, 0xEDAEE95EEAFD111DULL, 0xF371AF8EFC32F43EULL, 0xED8DAAEAF41C80E1ULL, 
            0x3CA5373AA027E8F3ULL, 0x635B28AAE8D4C314ULL, 0xCE1919712A7BD8BCULL, 0xAEF178269308FAF7ULL, 
            0x92AF21966ADF8BA5ULL, 0x2CF9283ADF30D2C3ULL, 0x5DC0D7E657E4736EULL, 0xBECE648C06B9B6CDULL, 
            0x59297E0D29C19615ULL, 0xCBE62C0E487409BDULL, 0xD10972DB9A2881F1ULL, 0xB741053217F3590DULL, 
            0x351BD5BCC6314F3DULL, 0x234F332D1DDDA2BAULL, 0xCDCD59A3BE35BEDBULL, 0x92F10B552D98BA19ULL, 
            0x1FD3F8939F70FF89ULL, 0xC96D066F7CC5EC74ULL, 0xA06B72F8A700DB2FULL, 0x82260186390CEB85ULL, 
            0x2742B67116BC92E0ULL, 0x9F37F865ECD5AA57ULL, 0xD3A1DA1DB8E41946ULL, 0x2D1D3D085F503D3BULL, 
            0xFECA391C3ED8E207ULL, 0xBF5E48E7C6C57C39ULL, 0x7B4A0890C5772897ULL, 0xF19A75D443A85BA8ULL
        },
        {
            0x353F968866EB9912ULL, 0xD059A4B6C796D512ULL, 0x230A1BC52066B4F6ULL, 0xC02D2708674495D6ULL, 
            0xCD0FFDD6435EA31BULL, 0xB200F0269E81E9FDULL, 0xB715E94D3F5F21F5ULL, 0xBF24170A8F51A9E3ULL, 
            0x875E69B0D1F3833DULL, 0x6DFF9F16621AC6E5ULL, 0x9F59EC8A21706D21ULL, 0xA208BE2935258F5CULL, 
            0x3103ACBF32EDDA24ULL, 0xBC3301BA86CB5860ULL, 0xE9B02B0F1731FA27ULL, 0xE914A83AB90D2A60ULL, 
            0x7D04AE9911F47AC7ULL, 0xF44FBCE0D6C59D3DULL, 0x4C3F5AFD3F630180ULL, 0x13DD2CC40579FFB7ULL, 
            0x879A8905A1C1B94FULL, 0x452193C9FCDA276FULL, 0xB75CB428A7A7EC8BULL, 0xD7267AC2CE735AFBULL, 
            0x7AD019746A1F02C9ULL, 0x211C982BBB8239D9ULL, 0x84E60BD7030F3018ULL, 0x1F46F452D225B6B8ULL, 
            0x48803C3F14EFF70EULL, 0xB5FD394A50BE90DAULL, 0x321C581B98BFE87EULL, 0x323D68E017CB0C47ULL
        },
        {
            0xA08B046974268507ULL, 0x182CAEB6CB7516D1ULL, 0x87506D254DBAFBA8ULL, 0xF31C998D1F86F20FULL, 
            0x34253CE02D819E46ULL, 0x0875590FE94B2061ULL, 0x7B498AA959764415ULL, 0x217865A9E9C5D6FBULL, 
            0x4C7A9CEBFA420FF2ULL, 0x088A482D9DF510D0ULL, 0x8E97461642251E3BULL, 0xA9E003356E15809DULL, 
            0x6E4F2AE31713FB9DULL, 0xB361A30D89609E19ULL, 0xF4EBBBF997CD6128ULL, 0xC7CE5C2216D5065FULL, 
            0xB3731715870CABF1ULL, 0x0E1481BB20EC2BD5ULL, 0xDC57D5B6E638B4F0ULL, 0x17EBAAA2DBBF8FEBULL, 
            0x9AF176BDA6F1BB9CULL, 0x92E0403BE77786A6ULL, 0xDFDFB33FC878BA52ULL, 0x4CACB68CA81C44F3ULL, 
            0xD3A387C19F50795EULL, 0x6E3303595FAA2801ULL, 0xB489780A6BDF86D9ULL, 0x99CC0273EF57BF21ULL, 
            0x8532E7AF58490411ULL, 0x5C757643D66D9FE0ULL, 0x6C06E45435DE55A1ULL, 0x43B9C9786EE21C2AULL
        }
    },
    {
        {
            0x10107AEEB0AD9EC3ULL, 0xFC53F12012A4CCD1ULL, 0xECD83FED66C65319ULL, 0x27BE7F8C0282F932ULL, 
            0x12BC89DC089E4255ULL, 0x055C3027CCEADD24ULL, 0x35FC3D2259C5511AULL, 0xAD64DD6547D0DF3CULL, 
            0x3B58B76243CEFBE9ULL, 0x6C755BA42D97C260ULL, 0xA72E0DEB3673A43DULL, 0x63A36E8C159178EBULL, 
            0x50C1E0CA2B0CF9F7ULL, 0x5708F098D36F9058ULL, 0x94DB1F03523E887CULL, 0x2B78860DA2C15086ULL, 
            0x2321F95A7C3555FDULL, 0x2541B09408746412ULL, 0x17134D0FF1D7B8CAULL, 0xDB7EF45A8D4800F8ULL, 
            0x17AAA98835D259F3ULL, 0x2F0205ACDB4C435CULL, 0x8881340E28F0CCE4ULL, 0x19F30C2F9DA273D8ULL, 
            0xE4DEE22515FA8BE8ULL, 0xBB8FD9A5B7BEE11BULL, 0x541451EE6A915B5DULL, 0x2F8B3D4EFF5B5ECAULL, 
            0x8EE9CCCF082FEB33ULL, 0xA28D72D5893F3C88ULL, 0x6F17F7751C49A631ULL, 0xEF33172851C2E5ECULL
        },
        {
            0xD26CE16CA6140651ULL, 0xEB75F9ED9410DB98ULL, 0x0E19CD5DFBD8F4FFULL, 0x41D44706611E1264ULL, 
            0x74EDF6DFB3A633F7ULL, 0xE143DBA318A81611ULL, 0x77E7E9E1D0832698ULL, 0x03DF06306C2327AEULL, 
            0xD5D5789E56958937ULL, 0x750757D7D986C956ULL, 0x6DB7AC1FB4F64588ULL, 0x1FAA8312ECAC87F3ULL, 
            0x89F0240E12AB877EULL, 0x127545C4A237866EULL, 0xE25183C6D777308FULL, 0x77DE7291D2A4F9D7ULL, 
            0x739022AD9EAE0F5EULL, 0x227B38FB9146BCEBULL, 0x5FBD1D170757131DULL, 0xB849842170291115ULL, 
            0xCB52815F5DF8D112ULL, 0xC10811C1BF088DC7ULL, 0xDA1E623052231F39ULL, 0xA4B892A9A61FDB3CULL, 
            0xE8E05F332375710EULL, 0xDB868836B1EEEE7EULL, 0x3531629C375DEF46ULL, 0x43F5D04297196D7FULL, 
            0xA2495E70D6DF354AULL, 0x558E5248A9039A8DULL, 0xE06E2DD3930B55A7ULL, 0x92D081B6928077F9ULL
        },
        {
            0x3CEE1C3EEF35AD97ULL, 0x5D06AC714A7B331BULL, 0xB59DD43FCA1846AEULL, 0x9D0EDF31DACC8838ULL, 
            0xDE5185F61030D750ULL, 0x9E35F9F82E0344E0ULL, 0x83A76454F7ED8816ULL, 0xA2CEF16CB040ACBCULL, 
            0x1A8EC7145E3D040AULL, 0x8D5CD0EC5E0EC1BDULL, 0x36F1A1CD0AD463EBULL, 0x99324573F36A23A5ULL, 
            0x40E9BC3A47082173ULL, 0xA6E0FB6F2055DBD4ULL, 0x263870862D39AB82ULL, 0x170EB6E49D369FB5ULL, 
            0x9981615F24B418ABULL, 0x72C489982ACBDE72ULL, 0x3ECE12A376969458ULL, 0x618A35F263BB02B6ULL, 
            0xC0D1E06D955FC788ULL, 0xD7AC193C3BF5B6BCULL, 0xE56416D42BEE49A5ULL, 0x5AFD38F41A078CFEULL, 
            0x6C3F429E738455F6ULL, 0x92AA2C5FAFC4E305ULL, 0xF51FA1A00F1CCBBAULL, 0x0A3D341CE0DFCCF4ULL, 
            0x3532C15A67DCFBFCULL, 0xDDCD1D8ACE3AFB71ULL, 0xA03B21ECAB9FBDA3ULL, 0x243A791718638A02ULL
        },
        {
            0xF606D2C1BB6911FCULL, 0xEB92F0152BBA78C8ULL, 0x46CBC42E128593ACULL, 0x103653ADFCF3852AULL, 
            0xEA946EAC53E7D820ULL, 0x1C2574B5BD4F21CDULL, 0x2ADB6A15FA66C1BBULL, 0x1C7F94E1B9EB4089ULL, 
            0xE7F53F7E67BE0B92ULL, 0x114FBE8ADA95BA2AULL, 0x17AAA62F0192CA34ULL, 0xCE59704A3ED48D20ULL, 
            0xD64C6192B85193E9ULL, 0x183F8F8F6F4886CAULL, 0xCD4E001499460FB4ULL, 0x09EFDC747B7C731BULL, 
            0x30767A4EA58E8A0BULL, 0xD7829873F0CFB95AULL, 0xB4B2D5E814F65792ULL, 0x1CB0ECE58355B97FULL, 
            0x1A2CEC8BE8D29891ULL, 0x77EE822C8EE96E0BULL, 0x09BC6883E6833A8DULL, 0x54F2423461D8D1A2ULL, 
            0x2DD804AA79FBABF5ULL, 0x99EF364811979A5DULL, 0xEDA5E465DC26B82AULL, 0xD46996106A85FFABULL, 
            0xF6A4FEAEC476905CULL, 0xA61EB612879CB458ULL, 0xC250EC0523FD2590ULL, 0x5136295F3113A47CULL
        },
        {
            0xEA415635BC757C02ULL, 0xCA5BC104AFDD77CAULL, 0xE2094815588639DDULL, 0x5FA1F9331E6D973EULL, 
            0x5E5222E1492B793BULL, 0xB70DEDC020D05DD6ULL, 0x02567E25A5BE5C3DULL, 0x5ABDDAEB2D24DA12ULL, 
            0x1667EEDF64D6AD1FULL, 0xCD06302722F7C7B8ULL, 0x7BE94040F5F599E7ULL, 0x89342F40651570F3ULL, 
            0x74C3D9EC05387526ULL, 0xFF838EDA50A40BD6ULL, 0xE17778487A5DC35CULL, 0x5593635F546FC910ULL, 
            0xE42343483DBF72D7ULL, 0x44AC3635F604EFF1ULL, 0x69B2112D2C7AE8CDULL, 0x38AC08CC5BE0A3D3ULL, 
            0x512CECE8D238FDC9ULL, 0x9DF69E5AF5ACB930ULL, 0xDD1F1DF32E6F38B1ULL, 0xA102B5C5CB2B3E60ULL, 
            0x0E23557BA443312EULL, 0xA2D76D45410C4230ULL, 0xA07CF6216DD69BB2ULL, 0x24F4C99BACEF33C0ULL, 
            0x761AE0B6A58A4236ULL, 0x94397DF0F55C9144ULL, 0xBA8ADF6C4AC89EF7ULL, 0x4650255D5DF6D2BFULL
        },
        {
            0x5361745242D6C501ULL, 0xD4F4FC5D54145778ULL, 0x850D6AE0E3C7CD4AULL, 0xB36C4535F7AF7D7AULL, 
            0x0D1B0CD742AD15DDULL, 0x33807CE890F5E6DCULL, 0xEE93439F594B8724ULL, 0x82C6AF90C62E84BFULL, 
            0x642CAC9A80FB87F3ULL, 0x5F68488F0B7ABE50ULL, 0x4F3DFD27D4373D09ULL, 0xC3E751C63592E085ULL, 
            0x20FFF4C9379F6722ULL, 0x04F395F88BAD2097ULL, 0x6EA2FC7AA337AA1BULL, 0xDAF236C253F0A080ULL, 
            0x6F4C1F80EBC31B94ULL, 0x616F6A5227959058ULL, 0x0BC53AF5ED6C6E3FULL, 0xB6FE5ACFD62CCD6EULL, 
            0x34F1A38A64E1A499ULL, 0x654786F149C3F5EFULL, 0xF6ED9DB007E9F1D0ULL, 0x168FA2EA2CF7E430ULL, 
            0x0261EE5DFFC1FFE9ULL, 0x55D4C61A895FA06EULL, 0xBA95AC49A804227FULL, 0xD4FF9810374D8E22ULL, 
            0xA911570FD01EBEFCULL, 0x7A52E7058D06516DULL, 0x4E0231FD8FB69902ULL, 0xA94094193606E147ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Castor::kPhaseBConstants = {
    0x4507629AD89A4186ULL,
    0xF6D173A7EE723164ULL,
    0x86ED8E6BA53F6935ULL,
    0x4507629AD89A4186ULL,
    0xF6D173A7EE723164ULL,
    0x86ED8E6BA53F6935ULL,
    0xE16B18F532DD436EULL,
    0x014E82A8D1D3999AULL,
    0x83,
    0xA5,
    0x6F,
    0x8B,
    0x75,
    0xEF,
    0xA7,
    0xD9
};

const TwistDomainSaltSet TwistExpander_Castor::kPhaseCSalts = {
    {
        {
            0xE15907342CACFF5EULL, 0x9C7F78BDEB606A1EULL, 0xB011622352118B71ULL, 0x34DB62554F973A62ULL, 
            0x009D8BD5853481E4ULL, 0xCCF98E6A8E62D9D3ULL, 0x58676BBB64ABE87FULL, 0xD32A94439CF1C968ULL, 
            0xDFA62EE7A933F274ULL, 0xCD74202B06AA97EEULL, 0x6D113684E87D0EBDULL, 0x8EE201BB3008CA2FULL, 
            0x78CC80884EC4123DULL, 0x674CED046094C8A6ULL, 0xDC1C7A4C15CD7666ULL, 0x527B94151BC41E11ULL, 
            0xE0501892D2667628ULL, 0x987A01F832DEE3BDULL, 0x96D37E7A5FB75B12ULL, 0x2EC332BB64FE36F7ULL, 
            0x21B580F7ADAC386CULL, 0x08389A30F897D9BAULL, 0x07EFC23A38A745C6ULL, 0xB220627EEEB69744ULL, 
            0x64731DE647348585ULL, 0x9A8902B2F12609D7ULL, 0x868CDC6D51E19A8DULL, 0x79ADB8164326317DULL, 
            0xD1C91372D9C4CDA7ULL, 0x9F1553D0300E65B5ULL, 0x3012FB1B8D953C17ULL, 0xF567BA3EAF31A9C6ULL
        },
        {
            0x87001296A8BB7EF6ULL, 0x6B6B03DBE572A710ULL, 0x2D7CB59BDEBAE815ULL, 0x2196B7738C3D4096ULL, 
            0xEC7D5678FDDACC44ULL, 0x0833146F8EB00043ULL, 0x50D546D411D8E5CEULL, 0x693B23FE5BCB6BDCULL, 
            0x673ADEB700692631ULL, 0x07BBAA4A1A991770ULL, 0xAD7984489FF22116ULL, 0xEA92C752D490612FULL, 
            0xE4C92F444669EAA4ULL, 0x6DCB93B41579D7CDULL, 0x8A5ED05297CF6211ULL, 0xCD19D6EFBAE7E2FDULL, 
            0x50806E1D63103B77ULL, 0x80BACBC6042FCDEDULL, 0xBA41C3E99F7ADA22ULL, 0x8C655231618E13F0ULL, 
            0xEFABE02614A94999ULL, 0xD69F462ADEF05B23ULL, 0xDA028F2EF484249AULL, 0xFF5ABCA6EB68DC52ULL, 
            0xF6791E94E3F93EEEULL, 0x235E93F5B60D0CD7ULL, 0x86817A985C685722ULL, 0x4C614A2DFF1B8286ULL, 
            0xA5CDF95BA77146FBULL, 0x39D8F4BFD0178D65ULL, 0x02E58A7AC5A60429ULL, 0xC2AEA004FF509AB1ULL
        },
        {
            0x63471AD94D92B52BULL, 0x61B7A52952CFA044ULL, 0x08F8AB44BECC6961ULL, 0x3B3D785984710EC0ULL, 
            0x4B59D447B3A5CD2CULL, 0xD7F12D948EAD1C84ULL, 0x4ECD7F3B568E5FCEULL, 0xB70C2EF1253DF8E7ULL, 
            0x93899A42D24C4BF4ULL, 0x70C31FC8CD9860F1ULL, 0xF178523E81D7FCB6ULL, 0x8376BA700925C076ULL, 
            0x654FD124E7B129A1ULL, 0xB657663E1FA323D7ULL, 0x8B47B781812A9873ULL, 0xFB57DC0D01C5B7E5ULL, 
            0x2952A4D30ACE409CULL, 0x911E2541DF8B39C0ULL, 0xAEFCB9F18DDD26B4ULL, 0xBFBB6E48F735F26EULL, 
            0x47BEDE48AEA10CD5ULL, 0xDF99C4E3B34FFCB6ULL, 0x87731E6A69F297BEULL, 0x23E915E2DBE100BAULL, 
            0xD0DB26055F8A235CULL, 0xD740848D84FECEE3ULL, 0xD16A1C8CD1B49BA2ULL, 0x8892603721D3511DULL, 
            0xDE3DC6386D11DA9DULL, 0x8EE3A6C82D57EAB6ULL, 0xDDF5E97263821732ULL, 0x56D4C742B81A156BULL
        },
        {
            0x49D1204572B3BB0AULL, 0x188925A8FB58B3B8ULL, 0x5E016EFB073CF69AULL, 0xBC65C2970D20A1BAULL, 
            0x9AC95ACE51294519ULL, 0xCD34443861A6F841ULL, 0xE8B8D45C6D2B0765ULL, 0x268C1E1C2DA914BCULL, 
            0xF453FF37957AE0CBULL, 0x90BFC3A466026BC6ULL, 0x053B130EC48A6318ULL, 0x40395C3623B5A621ULL, 
            0x36405C536F827CF6ULL, 0xA106E51A651942CEULL, 0x8B5AF262E7210F7EULL, 0x245761243AB3F2D4ULL, 
            0x1A66B3149ADEB046ULL, 0xC816208C4A432FFEULL, 0xF9BF01F036A2A6DCULL, 0x6D2D5E5900C28F0FULL, 
            0x8AFD2801873FE7E6ULL, 0x2FFF84D790CEAF78ULL, 0x2037053F3334E320ULL, 0x6E66BB7072B1F608ULL, 
            0x3A14D859E898A54AULL, 0x197F54F28D7F9DA2ULL, 0x9AFABFBF19255746ULL, 0xE49EE15D133024DCULL, 
            0x0A03539A93E7C112ULL, 0x1324D5C9B5BD9759ULL, 0x342DD133B191C74AULL, 0xDB70F24647C381B3ULL
        },
        {
            0x805DAF289CF085C0ULL, 0xA3059F0F7E07456EULL, 0xA36AD090268B60BFULL, 0xBEDA24C00AAB7CCCULL, 
            0x2D81242A42116F07ULL, 0xDC30F51F1712A061ULL, 0xDCCA5A863768DFADULL, 0x3AFB7100309A9B32ULL, 
            0xEA53326FDDF31022ULL, 0x50C18A7C0E6370C2ULL, 0x1883BFE6FF18EC18ULL, 0x24DE152C811D89EFULL, 
            0x592C3A74D8AD0FB7ULL, 0xBFA0E38843382135ULL, 0xE3868F1948F7052DULL, 0xA184F363DC7D4F2FULL, 
            0xB17375250473E101ULL, 0x5B312F0247BC6C2AULL, 0xE16226390E3608ACULL, 0xB636E4739345BA33ULL, 
            0xF7065754CFAEEC64ULL, 0x96CBA7FAD65DCF7FULL, 0x376D7B38816D191CULL, 0xD25DD9319C590DC9ULL, 
            0x182DACA65FF56BCCULL, 0xBB83D3C644141FCEULL, 0x79BAC6A3FB69C387ULL, 0x2DB1485FC4937C46ULL, 
            0x580F8E9F97B157A0ULL, 0x84AA971D73A00F6FULL, 0xAA7FAAC109418155ULL, 0x61508C7FE7BC37DAULL
        },
        {
            0x89E3F0BAAE727044ULL, 0xAB961FDB19562C67ULL, 0xFEB3102C41B765A8ULL, 0xB08B0315707013CDULL, 
            0x6F030365D8043A81ULL, 0xACE5CE0764190288ULL, 0x3497115803A22E10ULL, 0xE85BDEBD9D6CAFDCULL, 
            0x542AC7B4E664EB0BULL, 0xC30183835192C7FDULL, 0x60072C5C6EBA789AULL, 0x2C4FC529D81F12C8ULL, 
            0x0ADDBE24DF34D92BULL, 0xEF4EBC7394216A64ULL, 0xAD49D96E4A10D8B0ULL, 0x03846B0EB8008052ULL, 
            0x3214A1E17C27D4C2ULL, 0x256343C622DB79CCULL, 0x07A1CBF6B3A36D10ULL, 0xC73FAD320C359DE7ULL, 
            0x7347BDC9CDC41468ULL, 0x1B025FB060B87808ULL, 0x51A45D4F256AFF84ULL, 0x2047F79C39A10F77ULL, 
            0xE51C870F62E94092ULL, 0x45388998060D574CULL, 0x73DEDDB94F46044CULL, 0xD6EF0AD773A8FA60ULL, 
            0x9ED7AAE79439AF39ULL, 0x1FD1E0F8464F2C60ULL, 0x7E703177D6D629C2ULL, 0x0EA02E58B55BB1C3ULL
        }
    },
    {
        {
            0x35DED465C0D69B49ULL, 0x4566FC12AB5E76F7ULL, 0x06A4822B5F1A573FULL, 0x3359CC9C49276DB1ULL, 
            0x680B834E1C277977ULL, 0x46FF517C41DA832AULL, 0x8AD15EB2B788B006ULL, 0xB33975EFC59298B2ULL, 
            0xB54A5053230813F2ULL, 0xE89D997883512E19ULL, 0x0D42972EE7682809ULL, 0x003C48A8A42336C8ULL, 
            0x9108F47982C715D5ULL, 0x0F0A4BBEFCDE1D9BULL, 0x11AE3E29793EA568ULL, 0x5ECD65FB2CF7017CULL, 
            0x8DB81F5682727F1EULL, 0x86ED4CDF7AC25A26ULL, 0x11BD519DC4B5279CULL, 0x2A868A3496A5904CULL, 
            0x05F46E35B8E1A7F0ULL, 0x003FFCB81E685DF4ULL, 0x871A99B45E37CBBEULL, 0xBF9C03937E8C86EBULL, 
            0xDFC2B25E254882FDULL, 0xA0881B13FDE706CAULL, 0xA07268CF42FB2F1EULL, 0xF52C540CDA8043C5ULL, 
            0xE3E4D2E8B24977C7ULL, 0x9A3469DBAB974809ULL, 0x64A926795BBD9C32ULL, 0x147EC8EBA18D21C5ULL
        },
        {
            0xB0E8297BD8062E97ULL, 0x3BDA0A95F89B4B17ULL, 0x3A7FEAF489C75B8DULL, 0x6A631EFF238B37CFULL, 
            0x7E183676C8C2AF24ULL, 0x4866EC5D606BEDA7ULL, 0x91FED7D1387A1053ULL, 0xA2B5C7FFCF43B5F9ULL, 
            0x7F434554AF4ED9BEULL, 0x0DB23E8D6C7C9036ULL, 0xCEBA1882D62D3510ULL, 0xD8D86E495784CF5CULL, 
            0xB82A97BD1797C0B0ULL, 0x8BC426438C19673CULL, 0x46364E848D298282ULL, 0xFB9EB7CBE15CC849ULL, 
            0x2177B7D85F7D6D5EULL, 0x44776A9C531156EEULL, 0xBA3AE4560ECDFB88ULL, 0x7C9F5F4951219FC8ULL, 
            0xE25C39438750D222ULL, 0x7C61AA670859CA18ULL, 0xA7DF3B3A123B0178ULL, 0x1B5B352119569A8AULL, 
            0x252760A974A6C5ADULL, 0xB38F6F452421A9A5ULL, 0x79F75219599AE65FULL, 0x4AC34619F795700AULL, 
            0x31C3D67EFDE0E936ULL, 0xD9727D0FE1C3F1D3ULL, 0xA15ADC4F2EB64ABDULL, 0x09700096C383BFF1ULL
        },
        {
            0x04A9AF73A3AA23C2ULL, 0x7D52CA236B26195EULL, 0x7D967818D637AB25ULL, 0x0654CB99699C741CULL, 
            0x6490E853103A0F19ULL, 0x297D9E8D1F8C8725ULL, 0x92BD8AA6A158A987ULL, 0xC68247A32CA1ED6BULL, 
            0x94B82D68B6D30E53ULL, 0x4BAF2E0BE6C960D8ULL, 0x73C1FAC91DDC58E8ULL, 0xFCF7801926F0CE52ULL, 
            0x481289065431168BULL, 0x09D92864D39C1DB3ULL, 0xA3005EF495565503ULL, 0x4D5CBCCE0D5A7FBCULL, 
            0xEC208A960B0CE533ULL, 0x63500DDC45AAA342ULL, 0x4CF4E559A98BD810ULL, 0x79502212FFBFF8BCULL, 
            0xF394F7C4181E98E0ULL, 0x97521061C03BD6E8ULL, 0x61D6627946C867C3ULL, 0xBC1165AA77D3417CULL, 
            0xA082C959DEEAD599ULL, 0x0438B2CCCF24D2D3ULL, 0x7FD0EB6C0D81FFEFULL, 0x6DC50BE89D60387DULL, 
            0xFEFF9EE086E060E7ULL, 0x0FF109BB2BD216BDULL, 0xEE323518B9B9B206ULL, 0xCEAE4B50D0EB4922ULL
        },
        {
            0x97E4043DFA98E74FULL, 0xEE8B36BB1D1E86D1ULL, 0x2AF45E3A967CCCDFULL, 0xE8790F0B9BCB780CULL, 
            0x01A0782296DDE170ULL, 0x64E61F4DEA15AD69ULL, 0xB5CF6851171ADE5AULL, 0xB2D627D1E404ADFBULL, 
            0xD2B06B9D060FD1B8ULL, 0x69D5CACA3C34C6D2ULL, 0xB12E58586BD0FD5AULL, 0xC42DD014FB297DE5ULL, 
            0xCEE04D9DA37ED95EULL, 0x3DF2D2C8653A3C01ULL, 0xFD999D1868648A47ULL, 0xA72DC491CEFA4F9BULL, 
            0x992D941EB0E8F30EULL, 0x2BB695F79378F103ULL, 0xEE548E3C48E837B1ULL, 0x1ED3CA37953C195DULL, 
            0x94ECC81A3AF92906ULL, 0xEFFB2E25718CD501ULL, 0x4103F56BDB179588ULL, 0xE3BF1391421FE10CULL, 
            0x94FB19F16E9EF6FBULL, 0xC2AE86B0EDDE822FULL, 0xE97F6606F2A47128ULL, 0xC65B97A4DFDCD480ULL, 
            0xDF83A60696560505ULL, 0x76AA866A3AF3758BULL, 0xE08DC20641AB52B6ULL, 0xE6A3BBB24A431F75ULL
        },
        {
            0xB2CA3C67203F0A77ULL, 0x19084A9A6D6D4FBCULL, 0x277A2B890B0A5B7DULL, 0xBF68AC9B6EBDCEC1ULL, 
            0x2BF2E8F6EEC71023ULL, 0xFFE7CDFA15D2CFB5ULL, 0xEF0D2D1CC0837FDAULL, 0x604C93C3E0EB412DULL, 
            0xEA14FFA5D2D66163ULL, 0x1B3DAEA94A9631AFULL, 0xBCB59D258266A7B9ULL, 0x50C1530BB6ED6262ULL, 
            0x40D08BE155227626ULL, 0xB2C5A5B6549DA709ULL, 0x91CDCBEA85E7B239ULL, 0xBA23BC893EB36D34ULL, 
            0xEB1B9DA295D455D6ULL, 0x03099DF98CFEBCB2ULL, 0x1CECB8AC2A24D9FCULL, 0xE873C0C1C2921822ULL, 
            0x69A92CF61EC4E850ULL, 0xCF99282D579C3F85ULL, 0xEAD7ED58D310E0D3ULL, 0xB1B274B767218240ULL, 
            0x84B260091E386075ULL, 0x34694CD24048BDBAULL, 0xD858EDCEB59913EBULL, 0xB527237CE565E1A7ULL, 
            0xD4DD63A04C929202ULL, 0xED8C8ED576EE980DULL, 0xF838DDB4CD45B89AULL, 0xE200150C32E97C4AULL
        },
        {
            0x0D29DA85F6F66780ULL, 0x457C3D8C8489C9C7ULL, 0x860CF2001D610468ULL, 0xA1D73F68CA63138BULL, 
            0xBF6A9383188BF5F9ULL, 0x2C224DC88BDD9D37ULL, 0xBD195FCC2797A3DAULL, 0x82DDB24DA5CE8004ULL, 
            0x8CBA554B8C117140ULL, 0x7A88695763E6E642ULL, 0xEDE9B336F1DADFB6ULL, 0x875596E0E2A223DEULL, 
            0x8CF7533A23A168F2ULL, 0x2165E9D9726FCD64ULL, 0x0564551AEA3870E5ULL, 0xE1A83D3A308A0467ULL, 
            0x8657390A642ED334ULL, 0x8DD095B8E4FA1BD3ULL, 0xC3AC20EDA93594C2ULL, 0x7B68320BE8009EF3ULL, 
            0x720ECB561B5F1D94ULL, 0x7377325A17BD92CDULL, 0xA649CC5F4A81989AULL, 0xF919B9CCFC748400ULL, 
            0xF6C38FEF01759D15ULL, 0xDD9D9460637839F9ULL, 0x3186DF6487A41E9BULL, 0x5FFEF692354996FCULL, 
            0x5254DEC2BD8EDA14ULL, 0x559FE8414AA8E7A5ULL, 0x96E062117C9E04A1ULL, 0x905FDFC170ADBB86ULL
        }
    },
    {
        {
            0x11423B9789785BE5ULL, 0x52F39C51F077BEFAULL, 0x0DFF2F84363A2BC2ULL, 0xD4478981E8462324ULL, 
            0xA193485C9F204BF1ULL, 0x84E5D0FC04CD5164ULL, 0x738FEF3B7D0F657CULL, 0xA5058ABF0D8DE374ULL, 
            0x6E54E85F8703A5AEULL, 0xE00D165D4119034BULL, 0x7CF831902C9391B9ULL, 0x4DE14A4D7A5364DAULL, 
            0xC67F7F50AB3F4328ULL, 0x5A7ED2477932E15CULL, 0x4C2964CBA144F941ULL, 0xD8D1094495FEA847ULL, 
            0x381966F56690B453ULL, 0xA11D0C057C78BDA3ULL, 0xF3A628D34D029095ULL, 0x13E16EEBA57A04E9ULL, 
            0xF5F8AF6B2B522B66ULL, 0xD4C163DE6AFAC2A0ULL, 0xD9D55FFAEC3877E4ULL, 0xD350EC7B6EB0E6D7ULL, 
            0x930AA7C372F24CB0ULL, 0xA35CE5DD61D0CA79ULL, 0xCA67C8540478A512ULL, 0xDA12294B7CCFCBAAULL, 
            0xF321847CB0CA7699ULL, 0x523BDA73CA681E06ULL, 0x008350DE11A175DCULL, 0x6BCD671077F5EC9DULL
        },
        {
            0x7E016D54701AEE43ULL, 0xB642E41438B8A321ULL, 0xB7A9D83527D9D5ABULL, 0x6FAB80520CCEDFC0ULL, 
            0x3EBC3508232BB183ULL, 0x90D2B7FAA6344ECBULL, 0x21F69411AAD47EA1ULL, 0xA7092093D6B832DEULL, 
            0x37247769C4FAD9C4ULL, 0xDAC9C4BDE75D147AULL, 0x43BFB5E28D00D771ULL, 0x6970D9167FC5CAF2ULL, 
            0xBE20DFB2A71C7BF4ULL, 0x31EE897544A8DB85ULL, 0x82D7A9A5E15877FDULL, 0xAE7E2E8623C5FEE6ULL, 
            0xFD2292D95E37A33FULL, 0xDD3672CAF64EAAB7ULL, 0x0567A8B899AB9257ULL, 0x51756F70E5964578ULL, 
            0x2C875474F23B7B8BULL, 0xF055A01DBDE318D0ULL, 0xFAF4905751600714ULL, 0x0F5C2824B6DD68ACULL, 
            0x43AB9BD5CDB9F8A4ULL, 0xCDEBE51A61841D7FULL, 0x1555CE9DAF694AF0ULL, 0xCAE0A022027CA1A7ULL, 
            0x5111CD76829B3DBDULL, 0xCA4F55BAE577A769ULL, 0x265ED6CE1C56E2D8ULL, 0x7168D1D76C328679ULL
        },
        {
            0xC47E228F755753EAULL, 0x340D10A93E9D24C2ULL, 0x1985163549F84AAEULL, 0x9853FBB8CCA7FF8DULL, 
            0xFAC31D55656E72E4ULL, 0xE120A831DE0ED4BBULL, 0xEC3251B20AAD4F68ULL, 0xCF23A0F89B183BF8ULL, 
            0xE46FDD47C827352CULL, 0xC36D8F91904F0FDDULL, 0x1B1C0CAB7D22A65FULL, 0x97AF9D82988D227DULL, 
            0x10B923B5153996B8ULL, 0x7BB63C14320AA7C2ULL, 0x455D8764B8AD8AEDULL, 0x6E092DDBA50EB47EULL, 
            0x6681738EB8188716ULL, 0x0B951CF27021A81EULL, 0x22448AB7D7D7485BULL, 0xC0AE733D9398A7C4ULL, 
            0xC85EFB8B92071F98ULL, 0xC375980B26076685ULL, 0x8ED1382C33CAA980ULL, 0x69607ACE599983E7ULL, 
            0xE5BC90B40E829A15ULL, 0xA1C990E0B72B5E84ULL, 0x4CB4B474B3D09126ULL, 0xE88580E22AFE6443ULL, 
            0x72B3F46B789337C9ULL, 0xF53732898A6783C7ULL, 0xAB525DE92EC925B4ULL, 0x4F8084F97FE19732ULL
        },
        {
            0x4752947BEAFCF19EULL, 0xB59174BB405FE619ULL, 0x14384265F604A465ULL, 0x148161FB4626A092ULL, 
            0xFF0DD83C322A17AFULL, 0x43A92DE2E044290EULL, 0xA4CE48119731F7B8ULL, 0xD6220BB56F2B8E79ULL, 
            0x5BB541F4F381252FULL, 0xD4A653A308CDF9A0ULL, 0x2C18FE604399CD62ULL, 0x718287735F104D31ULL, 
            0xD44248C5788BF04CULL, 0x63C4C32C6CD1E230ULL, 0x9F552D25F2319B10ULL, 0x779EA4690EDF82A5ULL, 
            0x8096E826EA69A562ULL, 0x15B218A35662F52EULL, 0xD93BE2755B1DE78CULL, 0x07BF28FF229A56C4ULL, 
            0xACAEE09CE3186F89ULL, 0xDACA97DC1B3B5D7FULL, 0x7CA736C9D806D370ULL, 0x6F54EB81C846D39BULL, 
            0x9EB32402D82E11D7ULL, 0x208734260493736CULL, 0x5ADEC638C9DF266FULL, 0xB5F908F0D4AB37CBULL, 
            0x55112B8590D69297ULL, 0x6EBA8184922037AEULL, 0x95508672EBD47A0DULL, 0x75575FC778103902ULL
        },
        {
            0x15AD2B5B0939E815ULL, 0x0EF5A78EF920844CULL, 0xA6E7C88D9080EB8DULL, 0x2A82480FA2E97B05ULL, 
            0xB6AEA402044EB4C8ULL, 0xD298A32BA2B7FBC6ULL, 0xE4350DB0CEE68A88ULL, 0x1C5D66FFDFF34FC2ULL, 
            0x1F3093DEF2B9D55BULL, 0x4568FA19788E7B4BULL, 0x052C5CECADC4736AULL, 0xB04E01FC10B7E15BULL, 
            0x62C4A28E5117F28FULL, 0x15765E05DCF14931ULL, 0x3A1010E83050FA6CULL, 0x11741CA6489948ECULL, 
            0x400EF933025FC0AEULL, 0xAC90D67854885167ULL, 0x81282E83527DBF84ULL, 0xA7BBD7A9F40E06B4ULL, 
            0xE0E77CBAC7430000ULL, 0xA8352DD2EEC12942ULL, 0x610FCF0D0CF60F69ULL, 0xDE933F493290AB25ULL, 
            0x942DFF96E6876C45ULL, 0xD9ED8EF3A24B9D05ULL, 0xD2E5338C23427E38ULL, 0x42D638902D9BBA3BULL, 
            0x0A2B93811DFA0043ULL, 0x1D74E6CA244838BBULL, 0x8801F46A2AD39C3CULL, 0x28A83B597DBFB731ULL
        },
        {
            0xD00E0299D79A1077ULL, 0x70BAA4C9FA9FBAD7ULL, 0x9B409D50C11AF831ULL, 0x6A4CACABBA9E214FULL, 
            0x3F17A03BD0D93973ULL, 0x99B9587D6A479515ULL, 0x19C64D08102D2948ULL, 0x5CCE2A79AD7A2321ULL, 
            0x0EFC42D43B8ABD20ULL, 0x5A35B3F217BD859CULL, 0xDB2258A368F2D321ULL, 0x4AC2102C9405774BULL, 
            0x93A110DC2EE14793ULL, 0xF539268915956D79ULL, 0x2476637E433FF448ULL, 0xE6DF5BE5DF1B021DULL, 
            0x474068C75727254FULL, 0xB166FE8A9310CA65ULL, 0x2D058EB683E3577AULL, 0x47D6366230F23B6AULL, 
            0x3F3A3D454AD338F8ULL, 0x592B5A7FCCA0CF20ULL, 0x10EB97130DB28C49ULL, 0x99B04EC1BC10E236ULL, 
            0xB12A3DAF1D1407ACULL, 0xD9A064CE1E9F7973ULL, 0xE73E10058A3A7836ULL, 0x0E2FA8B5C4B2B44EULL, 
            0x745C736B3558A4ACULL, 0x8EA5486D39E7E8E8ULL, 0x14AC17A194C19E4EULL, 0xC8DF2A3484E104DDULL
        }
    }
};

const TwistDomainConstants TwistExpander_Castor::kPhaseCConstants = {
    0x352384325DF30DB9ULL,
    0x6ADF79DD236BFE6FULL,
    0x3FBB1C91F24AB067ULL,
    0x352384325DF30DB9ULL,
    0x6ADF79DD236BFE6FULL,
    0x3FBB1C91F24AB067ULL,
    0x11C6EB69B3775446ULL,
    0xC5370D1EEC25820BULL,
    0x1B,
    0x6B,
    0xD7,
    0xFA,
    0xF6,
    0x84,
    0x05,
    0x77
};

const TwistDomainSaltSet TwistExpander_Castor::kPhaseDSalts = {
    {
        {
            0xDFEBC644A6F23E24ULL, 0xB050CC0BB84919C0ULL, 0x199DF3C29C31FAF4ULL, 0xD8B696A700AE3818ULL, 
            0xD307B5852596D0CEULL, 0x07BEEFAC09CFF975ULL, 0xAC024EB4597EEFC6ULL, 0x34958E451B8BB8FDULL, 
            0x089441B4AB8802F9ULL, 0xD59E6C54EA33322EULL, 0xC063B16358D2749FULL, 0x8593958F247CCF8DULL, 
            0x1D14B6C86B9CBC53ULL, 0xFA860DBC856D3A15ULL, 0xBE1B7F57D6A67CB2ULL, 0xC1849477E63524A4ULL, 
            0x21A689CF831C590BULL, 0xF36A610C217E244CULL, 0xA1E3A34E304F4A23ULL, 0xDFB273B43C28AA13ULL, 
            0xEE5CC404348ED4F7ULL, 0x259456BF8DB5E577ULL, 0xC73E5ADEBF88DCFDULL, 0x0B0213B57D6EDF4EULL, 
            0x66EC330C1986BE80ULL, 0xA255757B19684ECDULL, 0x2A5A9BDAFE2666F0ULL, 0x44AE9913314CE580ULL, 
            0xA6FFEBE9ADFD48FBULL, 0x058DF21580CFD632ULL, 0xC81D795A1EFD5C9FULL, 0xBEFB4F2B26536B75ULL
        },
        {
            0x1DBDB0D0B30696FDULL, 0xFDC0DD8BE9C3AC8CULL, 0xD59BC06BF4FB3BD2ULL, 0x787B484365563958ULL, 
            0x9510E159E14714A7ULL, 0x5E2ECCC173643208ULL, 0x48CD11D5DF8522B2ULL, 0xA176CCBEDC8D9116ULL, 
            0x492249CD43217DF8ULL, 0xBC027963F9FC62CEULL, 0x5AED5E0AAE814187ULL, 0xB99F3EB0C431FAB1ULL, 
            0x3CC21510603CFD3EULL, 0x500D4A96BE3A4E84ULL, 0x00DD8C0F752D808DULL, 0xBCE072214E12890BULL, 
            0x33F187E10418B6CDULL, 0x9AA0D932675BDE0CULL, 0x6BC969F31E2A1161ULL, 0x1910F289E2A0A87CULL, 
            0xEC14E3F2048DCE3AULL, 0x5D409F1201832FC8ULL, 0x430F1C58E5DDAF7AULL, 0xF62EFE69275F590DULL, 
            0xE6822EA8ECDF5AC2ULL, 0x89C30F07677EAEF1ULL, 0x9D2723585DD6A681ULL, 0xADFC52771E481EDDULL, 
            0x0B9D61460CF11092ULL, 0x50CDD4A5602FABB7ULL, 0xAF785BCB9263B97CULL, 0xAD33B8B77A4B39A8ULL
        },
        {
            0x94895D9B048C14C9ULL, 0xC5324925D4AA1E00ULL, 0xA4918045A6FE3BFFULL, 0x8B168F90691DE2F6ULL, 
            0x2035B3F45262A220ULL, 0x626D54C451876D5CULL, 0x247B7E0C264885BAULL, 0x8866AD523205008CULL, 
            0xF0959C6F8BCC1CE3ULL, 0x0FF789D1A3B56569ULL, 0xDB095EAA64B9BEE0ULL, 0x1965080A7675079EULL, 
            0x542598240FECA45EULL, 0x735D0C76BD221677ULL, 0xB980342F8D0D8212ULL, 0x52CB6B84F34C438FULL, 
            0x1307D82B0906982DULL, 0xAC62FC318960568FULL, 0x36937A2F3FEE65B0ULL, 0x0B76B42256369B5EULL, 
            0x37577C7006B43899ULL, 0x147E84E003C78BD8ULL, 0x1D2DBBBB6AFF6B49ULL, 0xDA841F0204BECB4BULL, 
            0x5B0E8A213C61F6D9ULL, 0x2184E8F72A5B672DULL, 0x7D991BE611505534ULL, 0xC33E42779973F72AULL, 
            0x24F7D68957D3A340ULL, 0xA3FBC34C90470333ULL, 0x21B6FBEE0020B4DDULL, 0x4469054BD16722C1ULL
        },
        {
            0xD9B44DC69772A047ULL, 0xD1AC79699FB00AD2ULL, 0x36C3317F231313F7ULL, 0xE8F5868DDBE826DFULL, 
            0x77040310F03B7F40ULL, 0xA30EBBF84FD4D571ULL, 0x732AF5BB757316F2ULL, 0x73D4FDAC189881BBULL, 
            0x753C2F908286091EULL, 0x0789208CD4566681ULL, 0x0E0ECD5284AB8871ULL, 0x91094509B3AC95E5ULL, 
            0xC4781E34C1195D84ULL, 0x3153885BB5BC596DULL, 0xFEC4BFE3983A550BULL, 0x635D19D314425799ULL, 
            0x43843596C10FD4F0ULL, 0x910D6990B400FDB2ULL, 0xC25EB409618D2791ULL, 0x8473452126C4AA4EULL, 
            0xDBA7DB923C2319A6ULL, 0x71E74157239A46C5ULL, 0xB4640AF6FC81EF84ULL, 0xA2BEB966341EA558ULL, 
            0x3AAA11EE9A822134ULL, 0x961BE6BACA1E1770ULL, 0xB386F44F4B76E966ULL, 0x7CFF30D99C3F933DULL, 
            0xC8059369E895A694ULL, 0x8C99D65AE60C1CF8ULL, 0x1440D4AF30036C6EULL, 0xFEB35C730A8EE86DULL
        },
        {
            0xB269EF401C25E510ULL, 0xC53C794318162C0AULL, 0x4E949A5288A3E02AULL, 0x787D132CFA94D30CULL, 
            0x42D1844192C393A2ULL, 0x54663917B2F39AEEULL, 0x2C831B36D76A8F02ULL, 0x1F97DCB33AACEDF0ULL, 
            0x726EFF5166434E40ULL, 0xCC24237B285769DCULL, 0xF478E08361EB09F4ULL, 0x6BED4B23797CA5A3ULL, 
            0x0581F85B97538182ULL, 0x72E4339D5D20409FULL, 0xBD657EBC3A2A4DF9ULL, 0x45DA730047A6B3CBULL, 
            0xE46AB757B61E1DEFULL, 0xC77FD0A6B36E8859ULL, 0x5006E76B93F5F6BBULL, 0x14F0C8E676D1AE37ULL, 
            0xBCB4A2C612C148A9ULL, 0xC41BCF0AC6A28AB5ULL, 0xB9B9BA23B2E6641EULL, 0xEC220DEE8D70F002ULL, 
            0x7515609C0FBDE4FEULL, 0xBF261961DBCE479EULL, 0xC50DEB02A0363B26ULL, 0x92357DB9B979CB30ULL, 
            0x1E27062151BE012EULL, 0x8C9BF8EA3B65349AULL, 0x07BE8C74BA479895ULL, 0xD3B4CB22D6EF3AC5ULL
        },
        {
            0xE18750E3A0F0E964ULL, 0x5CA103D35ED3C0E4ULL, 0x90FE7BBFEE48560DULL, 0x70EA284FAF9FBDDDULL, 
            0xB9D34C9A4C072D0DULL, 0x87A59686B372513CULL, 0x4F998C876ABF3420ULL, 0x9B6F39A88986F8F9ULL, 
            0x35E47B6B98E1860FULL, 0xBB504F22227A2327ULL, 0x8F69590896A9064EULL, 0xEC1CEB446BB434F8ULL, 
            0x99A9B279C9EC8BF3ULL, 0xB883AD3A3B124663ULL, 0xF3AB9630F8029584ULL, 0xA4124FF69BA08A40ULL, 
            0x6235F1E746277B5EULL, 0x906EB855B7B9B839ULL, 0xD379D9A745D85580ULL, 0xE81CA0121029EAF9ULL, 
            0x504FCA0745A5105BULL, 0xC1CA37721ACE567DULL, 0x3F025A99905C0D5EULL, 0x1EEBCD2D4C36D5AFULL, 
            0x59DF9719F8F82DE2ULL, 0x6280BB611B94BEEFULL, 0x4249C9473EB3B237ULL, 0xBF0A0C58CEDAA21EULL, 
            0x1B49252E04CEE3A7ULL, 0x4704DFBD18E1B67EULL, 0x2A99D594AB6490E0ULL, 0xE04F52D6C187461DULL
        }
    },
    {
        {
            0xF9E2F10C0F39B2EAULL, 0x529ABCAFA9F48D50ULL, 0x317FD1DB375545C7ULL, 0xE12DD2A667C77812ULL, 
            0x5543F4566F550410ULL, 0x94529E31559C839FULL, 0xBB6D6453DFF9ECF6ULL, 0x2B33C18666934146ULL, 
            0x31898AA24F7010E8ULL, 0x1E83CAE9D0F861F4ULL, 0x704D7B71234CCF6DULL, 0x1E5F24D0EEAB4B05ULL, 
            0x47E4D6B514DED5DEULL, 0x9C85FB55D5453268ULL, 0xD3FE89A5752BA9F8ULL, 0xE734B81676058A03ULL, 
            0xD2EF9881C45C37C6ULL, 0x26909678D4C00E69ULL, 0xC2E2C2378E14DC4DULL, 0xB964D60419286220ULL, 
            0xF354BEABB391D73DULL, 0xDD0FC752E47DE5A7ULL, 0xB398245ED2466F8FULL, 0xE7B91260A3F0D0F2ULL, 
            0x97472D6BE7580601ULL, 0x8CE8E28B1E74A415ULL, 0xD297CD1782875383ULL, 0x26C47928FC178E7BULL, 
            0xF379BA190D9E57B9ULL, 0x0E401784ABCD948CULL, 0x12EDD1B87F8D39FEULL, 0xFDFB39B0703FE085ULL
        },
        {
            0xAB8292ADBC7A7920ULL, 0xC7CA4390966932C6ULL, 0x19870ABBDC809507ULL, 0x9BF07D4725BA4FD2ULL, 
            0xC5DC559046B120BBULL, 0xE20B1A1F0750FBAFULL, 0xC9FA71FDB7DA0C7FULL, 0x3B7ACA4790FE164EULL, 
            0xCC5087C05AFF1D24ULL, 0x8F29771423E799C0ULL, 0x39A00B9D7BD91652ULL, 0x0E65870FEE1E1CB2ULL, 
            0x438DC3E1A7EE5112ULL, 0x1492608AC3FECDD4ULL, 0xA16E5F3E67BF068EULL, 0xA0BF6E73D8C45435ULL, 
            0xED5764E319DA3BCAULL, 0x6035CF2D416F11C0ULL, 0xBA7BA3D1B482AB2AULL, 0x74A51A2752CD2E9AULL, 
            0x11CCE023ED1BC03AULL, 0x7999497484AD78B6ULL, 0xE93A0A9BD2C100AAULL, 0xF818CA0274B5C2DAULL, 
            0xF566AA027446891EULL, 0xF99A84DBED590070ULL, 0x9F305591DE67BBEEULL, 0x76B3C3144AC5A3C0ULL, 
            0xEA2B8BAE2FE87139ULL, 0xAEDD9DA2DDC28A31ULL, 0xFC45AC4AAC02081CULL, 0x7D05F95D06A19747ULL
        },
        {
            0xDA85216C712ADEB3ULL, 0xA9D097603F35E06EULL, 0x07BD896AAD76204CULL, 0x92E9B6E6859B07D4ULL, 
            0xB6C58152BC0EBDD4ULL, 0xD07862F71A704347ULL, 0xC6ADFD93B7D0A985ULL, 0x66135BAFDD57BFFBULL, 
            0x5B633B295B7025FCULL, 0xFF4F6DFEE01904CBULL, 0xD20BF6304BBEFF69ULL, 0x1EE53B082376C212ULL, 
            0x4748A8BDB3874FD6ULL, 0xDC605E70E81E0F5DULL, 0x7D9FB10D2CF7E902ULL, 0x66AFA75604823A44ULL, 
            0x640CE6B20F250CC5ULL, 0xC5C89FE0283275B3ULL, 0xC341748A1B08ECE1ULL, 0x77AA88EC83F18879ULL, 
            0xB41D0C9522AD6336ULL, 0x823BFC1B10D33F03ULL, 0xA983EBE230BDD071ULL, 0x98107F5E9E3041C2ULL, 
            0xBD9B9A1587FC62C4ULL, 0xC0D3892D020EE4ECULL, 0x06A752900DD383EDULL, 0xDC2C8F3F1806868CULL, 
            0x4020EF97264BED45ULL, 0x63D82AA1C1EC1648ULL, 0xA3A490515183E5AAULL, 0xCF6B84183D36AFCAULL
        },
        {
            0x9AF64C1BB5A3C1FDULL, 0x61BEE4FB5C5051CFULL, 0x5EFAEF7AE3FD2680ULL, 0xEC8CA42FACB21875ULL, 
            0x64C713003034769CULL, 0x6BCBE792183F5387ULL, 0x416587D716946380ULL, 0x79AA66996FA9AD1DULL, 
            0xB967E1AE455A7FE7ULL, 0x813593385A423A8EULL, 0xB4FE1BDFD3B7533FULL, 0x2225B90519313E67ULL, 
            0xE89D432500AF2EEEULL, 0x67E1351FE501E22FULL, 0x5F84D02E35EE3D8BULL, 0xE5AA716ABA575553ULL, 
            0xC81C5F7CCF46A6E6ULL, 0x3FE46816930DB0BDULL, 0x8453397A207795B4ULL, 0xBF4764377AF9F7D4ULL, 
            0xFEADAE3961BB8652ULL, 0x23AFF0B28C638520ULL, 0x6F4857E64D99A665ULL, 0x4E60A8B5904C728CULL, 
            0xD892EB9A588ECE2FULL, 0xC54A38774B77CB52ULL, 0x119F229BC9DB86E4ULL, 0x5D8E55D5E77E5522ULL, 
            0xB3B305107F1F2E08ULL, 0x15D83914E822004EULL, 0x5A29A43A2D33F49EULL, 0x71A8A1684D35684EULL
        },
        {
            0x80E73F0C7D08085DULL, 0xE31AAF02D1E36E44ULL, 0x9D65CC28805FC168ULL, 0x36A10C95DFC0B6EDULL, 
            0x1CFD709EAB5561E0ULL, 0x0D4C26000544CD0EULL, 0x35325BCF841332B0ULL, 0x7CAA54BF28F9D458ULL, 
            0x07061EA84C448936ULL, 0x6D9669280323FB2CULL, 0xF37829CCF4B371D5ULL, 0xD8BB83B1A40B451CULL, 
            0x1A113D2F43A3B8E0ULL, 0xCAEC4017BE80D33AULL, 0x75690D637FD29BF9ULL, 0x14E22B579C025B13ULL, 
            0xCA67A622C7989D04ULL, 0x0303C08EBC721BDAULL, 0xA6664324553B538CULL, 0xF31AE8B4C95ED35EULL, 
            0x67F91B4B322D1C93ULL, 0xF3CDAA834B8A8A06ULL, 0x3433FB577A527C35ULL, 0x38B6D003AA4E0B28ULL, 
            0x7806B51CA152DFAFULL, 0xD7F37A07B267D37CULL, 0x357FB152FCFADB0DULL, 0x928C778836C30EC4ULL, 
            0x1A43138591844B8EULL, 0x2142F52A130A8F62ULL, 0x3BA65F322EB4751AULL, 0xA5D7A9052704EEE6ULL
        },
        {
            0xC6477B94F6019EDFULL, 0x1613910ACA1DC47BULL, 0xBF3B73A3E4B8E34DULL, 0xF7A8F6D29D19C2ECULL, 
            0xA5823D373D583641ULL, 0xD986F9E003AA9581ULL, 0x944D105FEE263EA7ULL, 0xC93B77384B14C15EULL, 
            0x6EF4E085D1EEFE82ULL, 0x12BAFC60ADC0A301ULL, 0x2438CB92BA80D97DULL, 0x67FA0DC60DF68FCEULL, 
            0x7B1714974BC3736CULL, 0x1952D725DA1900EEULL, 0x6DBBC9C7E3CEBF4CULL, 0x455EC3F9351914A6ULL, 
            0x38E90796D2EF7AFDULL, 0x2B9A90B1143F2555ULL, 0xBFDB52CE87F2C282ULL, 0xEB46AC7E1C1C8CBCULL, 
            0x3AA7CD019C590BC7ULL, 0xA7E078500BB1EBB1ULL, 0x1E42EDDA1C67DB8CULL, 0x2F59EEDECF4BFF4FULL, 
            0x31523EE223674993ULL, 0x89BA2927671A2BD3ULL, 0xE9BF7950898D4C2AULL, 0x6E21814E12BE2F91ULL, 
            0x35FFFF12914D8ECCULL, 0x7B636598F0A17436ULL, 0xF9CB7F4F1890DE05ULL, 0x6E7B79E31C120C07ULL
        }
    },
    {
        {
            0x25C23D025CDF1582ULL, 0x3D773756D23948A3ULL, 0x331414C2679FBD69ULL, 0xF4FB3AA1B1D68E56ULL, 
            0x2BD25FE2CF7BD175ULL, 0xBE1963E4B637C694ULL, 0x1E62960E5D1FC9AFULL, 0x824167FC4C65FE67ULL, 
            0x7C6293ECCF609309ULL, 0x1A07F3946F4B3C53ULL, 0xADD9A232ABC74492ULL, 0x5D7186F71ABC09EBULL, 
            0x393DF4FDADE7D2C1ULL, 0xEF95FDC5C605EBB1ULL, 0xD74D0E834B131A0AULL, 0x1D41E28C85E0CBD8ULL, 
            0x5DFD9299F4A39C14ULL, 0x5DD740452C194FDEULL, 0xB3AB5EFE0561902DULL, 0x670E6F3D9B390033ULL, 
            0x85F3D71DE892B12EULL, 0x5EB666BBE252FA56ULL, 0x44C2ECF3A9BAD33AULL, 0xC6E0C1D9E73F455FULL, 
            0x1B7ECD73CA971F0FULL, 0xA63125D6225E0AEFULL, 0x86936C0215CC37ABULL, 0x8AA8474E792AA42DULL, 
            0xF1FC99E4983EE0ABULL, 0xAB0A9872BF0D619AULL, 0x78DBB3E3FF292052ULL, 0x6ABD119BC4B5A3B8ULL
        },
        {
            0x1A398CFA0B77D99FULL, 0x585C34305F32FB44ULL, 0x385AB736DC59BA8FULL, 0x2A7A17C96FBA3EEDULL, 
            0x7BA1EE700348B61FULL, 0x61800654D879A9E8ULL, 0xF474EE690753C5A1ULL, 0xEFDA56E71D4F5239ULL, 
            0xA057EBB046A1AA69ULL, 0x745427EC829B1C98ULL, 0x761DCA8473824F89ULL, 0x2C7CC33322DA65A7ULL, 
            0x818D6D3B3702517FULL, 0x03F36125E5C9F277ULL, 0xD7484B4FA8F02BEBULL, 0x43556909CAA86689ULL, 
            0x38B698F940FDD8FDULL, 0xB27A653EDED172DFULL, 0x013710F7BFDD78DEULL, 0x5D968CBB17A5EDC1ULL, 
            0x20B42819B7425ED7ULL, 0x4306A41DAA506D57ULL, 0xEADA70F9144129E2ULL, 0x3A90C41EB6A6E9C4ULL, 
            0xCD34292AB5B748B3ULL, 0xF5D9D1678272ED0EULL, 0x11088296661C0716ULL, 0x58277D284663BE57ULL, 
            0x0E84313BD5230558ULL, 0xF3793674AA27CEFCULL, 0x408D24836B3F4C25ULL, 0xF5389BE4102EC255ULL
        },
        {
            0xF6341195C39DFA77ULL, 0xBB65D2DCF639AA10ULL, 0x9CEEDEC43752193DULL, 0xF20287AC70C1FA99ULL, 
            0x0DE4F5CF8D06117CULL, 0xED69626D9FAF51ACULL, 0x7057F3C0EFC18C69ULL, 0x2272D641E38C135DULL, 
            0x10B84A3D99CCA697ULL, 0xE447A2632A70F8A6ULL, 0x1D495D43D561003CULL, 0x7FA594AEF596F213ULL, 
            0x626672E0DF784A5AULL, 0xB5654137B629AFFEULL, 0x0A4BB2BD193E7DC0ULL, 0x96A7E1912A7A2AA8ULL, 
            0x0C2853CA6C2AA547ULL, 0x9ACA4CBF9617AD93ULL, 0x9FB05ECD8D0DC26BULL, 0xC4474EB98D6A647FULL, 
            0xF94B2E808D35076AULL, 0xF650AC05DB5E8C52ULL, 0x17C13F0C1E27BE4EULL, 0x567FD66EF929B218ULL, 
            0xFCCF28F0EF11AB02ULL, 0x929C5447C4B8F042ULL, 0x16E24FE61BF091E6ULL, 0xB4EEDBB2F7393248ULL, 
            0x2741D773E421D113ULL, 0x94BD3BC4EE57A6A9ULL, 0xB2A1A71960F8FE99ULL, 0xECED54653073E0D5ULL
        },
        {
            0x2B504B76053A5194ULL, 0x5D360205DBB5766CULL, 0xE8291D8F60A40AB4ULL, 0xC08187F8450914EBULL, 
            0xDF905B86F22A223BULL, 0x915D102A78C25596ULL, 0x975E454BBA3F5F66ULL, 0x9675E1CCEA1D3BC0ULL, 
            0xE164A5D3ED14D750ULL, 0x811C8C6D0CF4B10AULL, 0x8AA7BF0003EA4D9BULL, 0x9403CF1A13F699F1ULL, 
            0x6A7B2B8F61D36C5BULL, 0x58F54003C1092EACULL, 0x7F4220C36BB51255ULL, 0x5B8B4DD80F0B90AAULL, 
            0x9799A55D18CB05B2ULL, 0x7AF4F23AD3A6AD9AULL, 0x7B08F222F855E2D3ULL, 0x667775AB2CFDE572ULL, 
            0x71AB278E1A8E3588ULL, 0xE0FAFCFE0C4113E5ULL, 0x14CC85D6164F1B05ULL, 0xD020F4C7776C7443ULL, 
            0x2830DAD2C4501F23ULL, 0x92956B972A709000ULL, 0x57BA083C27D596F5ULL, 0xE5A21FC8F7CADD7AULL, 
            0x3AD50B895C0B226BULL, 0xD7FA80101C70129AULL, 0xB328CB67E64E41EEULL, 0x6AE9F5C4BF9D1242ULL
        },
        {
            0x64370DA872D144CDULL, 0x457631058E6CF3E2ULL, 0xCBF6469CAFA79A7DULL, 0xFB5B35BDC4F67431ULL, 
            0x08F2BFCBD2711A68ULL, 0x09358089C69F349DULL, 0x3333BE8BF1E1044EULL, 0x8A87A888398922F0ULL, 
            0x5DA11456A8857398ULL, 0xAC2B8AAE17008362ULL, 0x7D44D8A74E7CF918ULL, 0x79B9C9B03ECCFED7ULL, 
            0xDCE5230333A00E13ULL, 0xAEDEF3A56331327FULL, 0x1CF4A0D1574DAB22ULL, 0xA218AD6A690F6874ULL, 
            0xCACB744C226DF84EULL, 0xEAB050DAEB38E670ULL, 0xE16F866B51E03827ULL, 0x54B6620227194429ULL, 
            0xAC5DEEE1704AD070ULL, 0x4236C1E58175068CULL, 0x4D412078945E4C62ULL, 0x0053007B515DB068ULL, 
            0x3E9EE8A927E691B2ULL, 0xF0DF6462B661836EULL, 0x29F3B66AC1A14D6CULL, 0x5CEFAA09CC645150ULL, 
            0x0D5AA4D3B29E85E9ULL, 0x3FFB66840B04ECFBULL, 0xF5A351D7377089BCULL, 0xE43048963D19527EULL
        },
        {
            0xB5E2E34D0342F443ULL, 0x38DAE256AB67703FULL, 0x96E089B6D917ED82ULL, 0xEC8F3B03662A5370ULL, 
            0xDAF074F87B121544ULL, 0x1DD7120D623F6A11ULL, 0xAB508E472232A559ULL, 0x2601D65B7417BF52ULL, 
            0x05A5D7F254124A86ULL, 0xF9A3DC8962EAC349ULL, 0xDFC28F99A07AC2D7ULL, 0xB17278858CFD4267ULL, 
            0x028379C7192D6CFEULL, 0xAF4E20E6CB0D4D2DULL, 0x6C71108012590410ULL, 0xC218ED90DC3E16FDULL, 
            0x1F01A616A7ECCF29ULL, 0xC39434B6FE25CF5AULL, 0xA9633F465A17404DULL, 0x0EB23F3C572105BDULL, 
            0x72CED1E87F93C9F4ULL, 0x5E111737F8FAA1CDULL, 0x0DECFB4797750F86ULL, 0xD9914ADC5A63CCA6ULL, 
            0x80E724BD7D140E6AULL, 0xB692B44D39E25CE3ULL, 0x4DC77B6497B7F609ULL, 0x5A38EE884ED8363FULL, 
            0x0F4B6EB4BAACE570ULL, 0x7040561730211216ULL, 0xD0E411241A558806ULL, 0xD72E92CB4019D6F2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Castor::kPhaseDConstants = {
    0x25DE4BB55BC9720EULL,
    0xF545343DFB04B3E1ULL,
    0x94C17149F9C78851ULL,
    0x25DE4BB55BC9720EULL,
    0xF545343DFB04B3E1ULL,
    0x94C17149F9C78851ULL,
    0x523020E5E8767510ULL,
    0x07860A45E0C22EF0ULL,
    0xCD,
    0x18,
    0xB9,
    0x4A,
    0xA1,
    0x15,
    0xC6,
    0xA1
};

