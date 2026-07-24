#include "TwistExpander_Athebyne.hpp"
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

TwistExpander_Athebyne::TwistExpander_Athebyne()
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

void TwistExpander_Athebyne::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xDD92F1B573DED69EULL; std::uint64_t aIngress = 0x82EA15BB26B8E30CULL; std::uint64_t aCarry = 0xC91A3BD4F6F132ADULL;

    std::uint64_t aWandererA = 0x87FE1B687CEA3388ULL; std::uint64_t aWandererB = 0x8F1E0C14A5D93E36ULL; std::uint64_t aWandererC = 0xB0A819EA84809CE1ULL; std::uint64_t aWandererD = 0x939314F1A0143407ULL;
    std::uint64_t aWandererE = 0xAABC11240ABF5E2DULL; std::uint64_t aWandererF = 0xA5FA06D4E506373DULL; std::uint64_t aWandererG = 0xF7B5F994302D31EDULL; std::uint64_t aWandererH = 0xB5075B4A17E8FA54ULL;
    std::uint64_t aWandererI = 0xF8C47E3926228300ULL; std::uint64_t aWandererJ = 0xDFF45A31FDB06212ULL; std::uint64_t aWandererK = 0xFC40C91952966B86ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xD6BEECE6CC747435ULL;
        aCarry = 0xD1CD69F4B966F3EEULL;
        aWandererA = 0xD1E45F33FAE210F5ULL;
        aWandererB = 0xAC2F0B36A8F87C7FULL;
        aWandererC = 0xB537439EAAFD2016ULL;
        aWandererD = 0x9216C65A7ED33C43ULL;
        aWandererE = 0xCBF3F9F183E34C3DULL;
        aWandererF = 0xFBB8D6F726D02E66ULL;
        aWandererG = 0xAAA9BED495AC1627ULL;
        aWandererH = 0x95DED05F7A478289ULL;
        aWandererI = 0xD64A708598C15A92ULL;
        aWandererJ = 0xE6910357D27BEF5EULL;
        aWandererK = 0xD841E09636F93181ULL;
    TwistExpander_Athebyne_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Athebyne_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Athebyne::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB30EF324920465F3ULL; std::uint64_t aIngress = 0x95592FD9B20CBCF4ULL; std::uint64_t aCarry = 0xF6BA3314DC75A9CAULL;

    std::uint64_t aWandererA = 0x8916F13867196602ULL; std::uint64_t aWandererB = 0xF5A63D36DD9BD007ULL; std::uint64_t aWandererC = 0xA91774FD4D60DE35ULL; std::uint64_t aWandererD = 0xDCE66C02EBA0359AULL;
    std::uint64_t aWandererE = 0xB8ADD1EB52A24473ULL; std::uint64_t aWandererF = 0xD614BFA23A180FF0ULL; std::uint64_t aWandererG = 0xF7765F62E9E24913ULL; std::uint64_t aWandererH = 0xA840C41C3B8C780CULL;
    std::uint64_t aWandererI = 0xD39DC6FED220D1D1ULL; std::uint64_t aWandererJ = 0xBC88A9399C29BAE4ULL; std::uint64_t aWandererK = 0xD5E14A335038BCB3ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x9DF8CC72E0F160E3ULL;
        aCarry = 0x8A6B6E8E724A3324ULL;
        aWandererA = 0xE70225E545D131BAULL;
        aWandererB = 0xB1DA44A309462621ULL;
        aWandererC = 0xBE728C8A7D6FEFAFULL;
        aWandererD = 0x9A9FE37504EC162CULL;
        aWandererE = 0xE0D6653AFD99710EULL;
        aWandererF = 0xBD7D79188230305DULL;
        aWandererG = 0xFDACBEA90D3BCA03ULL;
        aWandererH = 0xFA0CDF147162A18CULL;
        aWandererI = 0xAF6D7140FB30CCF6ULL;
        aWandererJ = 0xB02850365E0C18D2ULL;
        aWandererK = 0xAE93AAC027CC0910ULL;
    TwistExpander_Athebyne_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Athebyne_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Athebyne::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x85439E040B29443DULL;
    std::uint64_t aIngress = 0x923A03143459766AULL;
    std::uint64_t aCarry = 0xB9B013914061EA90ULL;

    std::uint64_t aWandererA = 0xFBAD5E6B2E0BDEC5ULL;
    std::uint64_t aWandererB = 0x931926DB995A89D1ULL;
    std::uint64_t aWandererC = 0xD8AD4A6EAE7E4F3BULL;
    std::uint64_t aWandererD = 0xCD7DBC11C1421D01ULL;
    std::uint64_t aWandererE = 0xC4E9EBB01B55032EULL;
    std::uint64_t aWandererF = 0xB9D60E65E692C055ULL;
    std::uint64_t aWandererG = 0xD2581E95F1EE1FD3ULL;
    std::uint64_t aWandererH = 0xA1DF65C0725C28C9ULL;
    std::uint64_t aWandererI = 0xE063C583A1066DF3ULL;
    std::uint64_t aWandererJ = 0xD3D0AE66CB7950EAULL;
    std::uint64_t aWandererK = 0xAE8883D32DC75BB6ULL;

    // [seed]
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), pSnowLaneB, 0);
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
    TwistExpander_Athebyne_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Athebyne_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Athebyne_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Athebyne_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Athebyne_Arx::GROW_B(pWorkSpace,
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

// SmartSquash candidate 11 of 33
// Exploration cases: 100000000
// Nearest-family diversity: 943 / 1088 (86.67%)
// Total distance from earlier candidates: 9544
void TwistExpander_Athebyne::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    static_assert((S_BLOCK / W_KEY) == 16, "SquashInvestToKeyBoxes expects 16 invest fragments.");
    static_assert(H_KEY == 8, "SquashInvestToKeyBoxes expects 8 key rows per box.");
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 2U), *aFragmentB = aIceLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 14U), *aFragmentD = aIceLaneD + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1998U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 98U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1987U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 408U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 11U), *aFragmentB = aIceLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 10U), *aFragmentD = aIceLaneD + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1813U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1420U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1860U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 474U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 15U), *aFragmentB = aIceLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 9U), *aFragmentD = aIceLaneD + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1537U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1434U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1118U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 111U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 13U), *aFragmentB = aIceLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 13U), *aFragmentD = aIceLaneD + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1856U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1227U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 600U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1053U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 3U), *aFragmentB = aIceLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 15U), *aFragmentD = aIceLaneD + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 180U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1400U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1618U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1866U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 9U), *aFragmentB = aIceLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 3U), *aFragmentD = aIceLaneD + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 496U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1499U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1087U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 142U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 5U), *aFragmentB = aIceLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 5U), *aFragmentD = aIceLaneD + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 874U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1265U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 755U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 2043U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 4U), *aFragmentB = aIceLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 4U), *aFragmentD = aIceLaneD + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1905U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1334U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 790U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1130U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 7U), *aFragmentB = aIceLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 11U), *aFragmentD = aIceLaneD + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1637U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 868U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 923U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 409U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 14U), *aFragmentB = aIceLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 1U), *aFragmentD = aIceLaneD + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1782U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 747U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1532U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 896U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 1U), *aFragmentB = aIceLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 2U), *aFragmentD = aIceLaneD + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 396U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1486U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 20U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 173U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 6U), *aFragmentB = aIceLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 8U), *aFragmentD = aIceLaneD + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 964U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1466U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1556U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 8U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 8U), *aFragmentB = aIceLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 0U), *aFragmentD = aIceLaneD + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 499U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 29U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 96U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 124U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 10U), *aFragmentB = aIceLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 6U), *aFragmentD = aIceLaneD + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1328U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1199U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 819U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1992U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 12U), *aFragmentB = aIceLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 12U), *aFragmentD = aIceLaneD + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 668U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 382U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 2007U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1621U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 0U), *aFragmentB = aIceLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 7U), *aFragmentD = aIceLaneD + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 760U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 240U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 720U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 876U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Athebyne::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x963196903D92CAE0ULL; std::uint64_t aIngress = 0x915BCC654A28B48FULL; std::uint64_t aCarry = 0xA462A02C17CCF422ULL;

    std::uint64_t aWandererA = 0xD42D47DED36C7339ULL; std::uint64_t aWandererB = 0xD1B326CC03505DD4ULL; std::uint64_t aWandererC = 0xE431B6CC4052F8D7ULL; std::uint64_t aWandererD = 0x86C36A8091F1CD45ULL;
    std::uint64_t aWandererE = 0xB4930D7A8E39B4E4ULL; std::uint64_t aWandererF = 0xC3654203AB413786ULL; std::uint64_t aWandererG = 0xB7ADD89CA7C8A1E6ULL; std::uint64_t aWandererH = 0xE3161D5A569E996DULL;
    std::uint64_t aWandererI = 0xB4E54619F7EE7C92ULL; std::uint64_t aWandererJ = 0xE421BA0E2E0A3745ULL; std::uint64_t aWandererK = 0xC28A6DAE27C54BC5ULL;

    // [seed]
        aPrevious = 0xB22FF7AB7D23B0F2ULL;
        aCarry = 0xFB8E41A584A206F7ULL;
        aWandererA = 0xAF7F734640291681ULL;
        aWandererB = 0x90F91CA7901B4EC7ULL;
        aWandererC = 0xE4208D8A2633DE75ULL;
        aWandererD = 0xE9A4ED487740B843ULL;
        aWandererE = 0xB4E5E29480006985ULL;
        aWandererF = 0xB5C674D4FF864458ULL;
        aWandererG = 0xF65C04506C9567A6ULL;
        aWandererH = 0xA88ED5C573819C71ULL;
        aWandererI = 0xDD109DF0F5BDCEC9ULL;
        aWandererJ = 0xD66826A41D779C81ULL;
        aWandererK = 0xA2A87A0332B07DF1ULL;
    TwistExpander_Athebyne_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Athebyne_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Athebyne_Arx::Twist_E(pWorkSpace,
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
    TwistExpander_Athebyne_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Athebyne_Arx::GROW_B(pWorkSpace,
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

// GrowA candidate 11 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 5537; nearest pair: 501 / 674
void TwistExpander_Athebyne::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 840U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4757U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7669U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1530U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6236U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4082U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5208U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2238U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 0U);
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
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6406U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 635U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7635U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3341U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5088U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2769U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8116U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6352U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 10U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 690U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 562U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1757U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1999U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 21U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 186U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1974U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1417U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1055U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1783U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 12U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
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
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 106U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1742U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1340U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1498U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 96U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1297U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 910U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 56U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
}

// GrowB candidate 11 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 5518; nearest pair: 488 / 674
void TwistExpander_Athebyne::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7356U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2050U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4795U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 799U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1485U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5929U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7774U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2646U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7338U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 933U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5994U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1143U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4164U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4077U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1449U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7922U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1905U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1250U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1459U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1046U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1103U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 727U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 158U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1750U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 435U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 349U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 693U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1807U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1425U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1747U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2025U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 57U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 66U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1559U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 638U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 497U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
}

const TwistDomainSaltSet TwistExpander_Athebyne::kPhaseASalts = {
    {
        {
            0x502BD375377D65C9ULL, 0xFF6D68415BC9E888ULL, 0xD73E8A25D9408386ULL, 0xDFCFCA52B4495703ULL, 
            0x6CEA043F463B2C1BULL, 0x314072A743D71F7BULL, 0xE4A071CAE49B10E7ULL, 0x530B89B2D711A303ULL, 
            0x2EDCF7FE5A192FEEULL, 0x7FC43CF09B8B5715ULL, 0xC385C05F957E6660ULL, 0xE7CE0845F9B00327ULL, 
            0xCF8E870C30E12E2DULL, 0x623941D262AEA686ULL, 0x35B96D12E186F3A6ULL, 0xD52C5E6A610468D6ULL, 
            0xD7004E5D31DD0475ULL, 0x66D62BAEB4C28167ULL, 0xB68718D681D22ED1ULL, 0xC36C156344994F6AULL, 
            0xB44A077F5EE83CACULL, 0x99E36413897B0332ULL, 0x9F4B6FAA150B623BULL, 0x9907C5B59961E096ULL, 
            0x4515BDFCB97A1136ULL, 0xFA4C642FEB44AB33ULL, 0x4BB4D91008F481BDULL, 0xE0157923CCA17D68ULL, 
            0x18DDE58E42988EA5ULL, 0x56E4AD83F5C56C99ULL, 0xCE96C6DB78298E68ULL, 0x69C7DFF07384DD92ULL
        },
        {
            0x494D37C513A9213FULL, 0xB372A6E232CF6942ULL, 0xD399B62199863AA4ULL, 0xBDD99B6B3B4C7AC3ULL, 
            0xB845755CB7A4AB30ULL, 0xC0718F66C654B23FULL, 0x524D73EDCC35C1BBULL, 0x35BE351F3A922FD1ULL, 
            0x86454C5CBE46794FULL, 0x4B83411958EEE687ULL, 0xBB1EAAC76443AC8AULL, 0xF319B7F692455289ULL, 
            0xD6C9C636A015FC92ULL, 0x454199487ED10618ULL, 0x2255F3796F72DF71ULL, 0x033A25C8E23A195DULL, 
            0xCCD0FFFD341859B6ULL, 0x853CF7D7C4CB82A7ULL, 0xC551A6C66DFA5085ULL, 0x03CB7419DE7B7683ULL, 
            0x2AB8BB75E7FCCD0AULL, 0xF9AD466EACD15033ULL, 0xF530AE7E69461387ULL, 0xDAD091DABB19274CULL, 
            0xEEAAF62A43BD2436ULL, 0x807DAF7BBB457A84ULL, 0xAC6E15579E71F0B5ULL, 0xE2DEBEFB112B267BULL, 
            0x64FD5AAB1DAD2242ULL, 0x68AD5F1F9997F4CEULL, 0x3C0B708D088D6799ULL, 0xA818FEF0D267A2CEULL
        },
        {
            0xB559667921F38616ULL, 0xCB123CD38ADAAB6DULL, 0x9A4DA75483D17065ULL, 0x32CC52AC2323BCDFULL, 
            0x7E4D89DBD839292DULL, 0x8C126E183E109E5AULL, 0xE102B2D4787EA7ABULL, 0x9B606A957D5509F1ULL, 
            0xA0C25E9DE20E943AULL, 0x63C97058A0EA70C6ULL, 0xE3B2339E7F1C35D9ULL, 0xFEB5478A1ABDB894ULL, 
            0x1CB1F01BDADBB7CEULL, 0x92052B23AE38DE7BULL, 0x2F3992B7737548B3ULL, 0xAA3DD01C858F3776ULL, 
            0x179054105B02D772ULL, 0x38DF265B06CEA569ULL, 0xE3FEF49F490BD707ULL, 0x4334FCEACCF776CDULL, 
            0x706F9FA825A6DB7EULL, 0xD030EF68F821181AULL, 0xDC80A1746A71067CULL, 0xE4FB97E2982E69CEULL, 
            0xCB65EFB1B879C44AULL, 0x13C468FE767EAEC5ULL, 0xEE861B90389427F8ULL, 0x7D2CEC14596E8C30ULL, 
            0x51FCFCB1A5996C48ULL, 0xE4DE81CCC5BDC05AULL, 0x66D171FFEEDB7AEDULL, 0x735A8F1F7B7AFC79ULL
        },
        {
            0xE1560196D4D2117BULL, 0xF0DB9375D7DF0980ULL, 0x5197121758B3184DULL, 0x9EE23532104527B9ULL, 
            0xCD72B087CF02B404ULL, 0x3FF60B8FE8409F9AULL, 0xC460B5747BBEB8EBULL, 0xED81CAA257F0D2C7ULL, 
            0x4B88AEFE2571553BULL, 0x826B70F400597ACDULL, 0x60CFE84FF0E6F98CULL, 0x9B448DFD33A1F4C6ULL, 
            0x1D5EC8CA6E1DA729ULL, 0xE40B7E32B8CE572EULL, 0xC64791E4833423DAULL, 0x9BCD7AB42B1334FCULL, 
            0xC0DE8759872840D5ULL, 0x2724CDECAA7C9733ULL, 0x205D0C4A10CF94E4ULL, 0x2CA9527708A1371EULL, 
            0x01499F268C2C772FULL, 0x3BCFE8E74F1DEA25ULL, 0x1CFB8EF146849517ULL, 0x6164190B2D2F0C8CULL, 
            0xF0EAD88B899EE563ULL, 0xEA3409219AF91DB9ULL, 0x63611A3A32161732ULL, 0xCA8BF1DA7EF264CEULL, 
            0x11638616C200B497ULL, 0xEEB557F6E9667ADBULL, 0x69593B1F65780582ULL, 0x682B7B6B201D853AULL
        },
        {
            0x47DCB32413D05580ULL, 0x43E45FBA222E81E6ULL, 0x5D691166496E964BULL, 0x4DDFC0120880E732ULL, 
            0xEBC42B52038448E8ULL, 0x3D71BB8CF41E4855ULL, 0x25ADD469AA8ED6F8ULL, 0xF18488167F4B185AULL, 
            0xE11F156FB11F5654ULL, 0xDE7E64BFA2C5558CULL, 0xD6793753FD9E022FULL, 0xA4AA5AF59B05D298ULL, 
            0x7B2B17645410ED76ULL, 0x46403F2AA435C813ULL, 0x30935B30839241C3ULL, 0xE7D45C7FFBF82EEBULL, 
            0xCA584644E74E1C3DULL, 0x94B03B135ADF7C4FULL, 0xE3DF23619644F006ULL, 0x4148839F7F60C303ULL, 
            0x2E9424ADF5BE3F16ULL, 0x8C51CF01B22ED61DULL, 0xFB45981E0CD144A6ULL, 0xC2C768B12412F5A1ULL, 
            0x27E314EC77A0A020ULL, 0xDC54EF4C3E74979FULL, 0x9DAA15761F09E639ULL, 0x10D33C8F63ABA1EEULL, 
            0x91DC300E0437B946ULL, 0x64E782B5F00F7199ULL, 0xF696A75B2A012C09ULL, 0x52DC3F37F0D1CE6EULL
        },
        {
            0x2D25EB5EC542309CULL, 0x9AACE47219C98FC7ULL, 0xF5B4B7C09C446B4DULL, 0x3E4D4A09F4C072D3ULL, 
            0x70395C2BF5531276ULL, 0x9DAA878C3640DB9AULL, 0xE3FB307DCEB0F5FAULL, 0x791A8B618E1398B0ULL, 
            0x857C335A49D2B3DEULL, 0x6B5B72C59F4B529EULL, 0xBD833B0496E898EEULL, 0x5AD1A90B1F306C19ULL, 
            0x9F786FC806BF08ADULL, 0x746234E8967E1184ULL, 0xEE8AE668C9FE8C8EULL, 0x33267ABC8CF14A45ULL, 
            0x198949E5DAB83D99ULL, 0x8F6422F03BC45698ULL, 0x9BEE4474D3F6EA8AULL, 0x09CA93599003C4C7ULL, 
            0x5092FE22BAFC94D4ULL, 0x0E999788E38760FBULL, 0x14608E31ADD32D1CULL, 0xEC013F760329EC29ULL, 
            0x39C5C6414E2E9682ULL, 0xCA7D8BA223A83578ULL, 0x27437037D27C2EECULL, 0x58457931432BCC7DULL, 
            0xBCD0F1EA54B2F2E8ULL, 0x81EDA40B6AA917DDULL, 0xBB5CC3EDC4AD1823ULL, 0x32DB8D05BBAA781BULL
        }
    },
    {
        {
            0xA8E86AB43C54F728ULL, 0xD4DE1CE6D948C0F7ULL, 0x99B71751D43BD4B3ULL, 0x6BFB3C58C10BED57ULL, 
            0x948370D0B7C6DF53ULL, 0xCAFD8F9F334FAC4FULL, 0x3798E2C113499EF1ULL, 0x63E2F23521283F06ULL, 
            0xEAA888E1FD2A87E9ULL, 0x4D2CF099219A92AEULL, 0xB788ABEF48F9F3C1ULL, 0x6D02034FF240D08EULL, 
            0xD1A2ED529F44D96CULL, 0xCB3AED9EB89DC275ULL, 0xCC170EB84D8F8657ULL, 0x0EB6D016A0AB57BBULL, 
            0xE2AA4D538AC59FCDULL, 0xEC7F063BC1C4BBCBULL, 0x0FED7B88142CA598ULL, 0xB418DD3E22C4A29AULL, 
            0x7DD2CAEE38FEF298ULL, 0x9552CAFB58A40BE9ULL, 0x17BEAE118F47929DULL, 0x61FD8B7C2CEF69DBULL, 
            0x4C7345F87EDA9062ULL, 0x8C202072386CDB28ULL, 0xEAB062CE274C0643ULL, 0x77193E41F7229158ULL, 
            0x144007192619C859ULL, 0x85D06671548C8DAAULL, 0x240EF6E43A167058ULL, 0x03FE14BC2B77862CULL
        },
        {
            0xAA2AEBE6D5EB93D2ULL, 0xDCAA9D3CA68A7192ULL, 0x07182E9E5B31FA28ULL, 0x6D14035486F082ECULL, 
            0xB3647497CF223F7BULL, 0x5FB545401FFC3EBFULL, 0x049D7AA02389AD4FULL, 0x994BD7F10255A0BFULL, 
            0x60844DA5B8324AE2ULL, 0x7B07BE8940D85F44ULL, 0xD30BA9E8A9CAB44EULL, 0xD078C67504E15D30ULL, 
            0xDDCFE493555A1B4DULL, 0xA28A0A9ADAED4ED9ULL, 0x6AFE1F1F66B90450ULL, 0x11331A29C2558791ULL, 
            0x92AB50DB3936D09DULL, 0x4F92C2A199EF0AE8ULL, 0x9806D97F0465D2E8ULL, 0x04AFA87E08437075ULL, 
            0xAFF7C79E4CAC4DC5ULL, 0xFE96BD6C37325CB1ULL, 0x82498C21E313406BULL, 0x84376918C02B3590ULL, 
            0x8D849BB4B6C4B00CULL, 0x7FD25607D74EE5D0ULL, 0x92D0CE805D2413ECULL, 0x243E8CAA2941DCD0ULL, 
            0x0E38A7045E722F12ULL, 0x556C24FED0D8501AULL, 0x211E1D02DC8733A8ULL, 0x9A2C166BB1046419ULL
        },
        {
            0xED4D4E917BA95D17ULL, 0x729FD5433925F272ULL, 0x9C385062195B65F5ULL, 0x812DD92F7528209CULL, 
            0xF847A58EEB51C7D7ULL, 0x3D8A8A639DB2CEADULL, 0x986B43100570DAE5ULL, 0x0516EB48617972F1ULL, 
            0xFC1A54230A8CE774ULL, 0x33F948F2626CE3CAULL, 0x412312955A876869ULL, 0x59E3A9DED34CFFF8ULL, 
            0x6362EEEC09612906ULL, 0xBF50E841A67375ADULL, 0x7246718B1B48F894ULL, 0x8D8F43C1C5195ADDULL, 
            0x506A0CCFCBC98F74ULL, 0x977012322021318BULL, 0x8171AFC1C4F8CDA6ULL, 0x3C6C104812962219ULL, 
            0x27D0F7AC37B1A41CULL, 0x1D40292DE6B0879CULL, 0xABCD82CB1D350BAEULL, 0x6312000BD2656542ULL, 
            0xFAA7268FF8026CA7ULL, 0x7E8583B7E133E157ULL, 0x61F591EEAF33FF8AULL, 0xC72B0349B7A4D339ULL, 
            0x735C650C78711DEBULL, 0x5AADE9323CF366C3ULL, 0xA380C3B3CF89D321ULL, 0xB20D7E1815692BF8ULL
        },
        {
            0xECAD8E3FBBD5AC25ULL, 0x24323C5997FAAA44ULL, 0xEF18E951FBE54F5FULL, 0xD52AC73485F7AA51ULL, 
            0x2E979FB8179480E7ULL, 0x0EF4E32184C4DA9EULL, 0x74CD194DBB1890ABULL, 0x73257D97D15D13CEULL, 
            0x08B3A848D55D76A9ULL, 0x2F82E28D67F5CBBFULL, 0x73A6E33968D775D0ULL, 0x5860095CE4132EE3ULL, 
            0x45C8D55D1E6ACD2AULL, 0x7E714170A01EEF98ULL, 0xFAB2C758935666D2ULL, 0xFC624CF9B70AE1B5ULL, 
            0x735D5B67B6356B05ULL, 0x608C672ECF5B60EFULL, 0xACD3D9688517801BULL, 0x0B17933F0A4D1EB3ULL, 
            0x017AD7372F445DA3ULL, 0x20A160D9C7AA6B03ULL, 0x460421422D33B29CULL, 0xA94CE2382C6FF542ULL, 
            0x0BD9F68421009C13ULL, 0x6DB08303CE1EA8B2ULL, 0xEA730A1E03F9A475ULL, 0xBF608DE8A3DD6601ULL, 
            0x8C8EF4F2B53D6D51ULL, 0x9A67929718971437ULL, 0x503943525A97F10EULL, 0x7D2320A4DFA08A44ULL
        },
        {
            0x0123EC468479C93FULL, 0x87C866AE1B729EB6ULL, 0xB076A63841FABFC3ULL, 0x35162A926E10E2EBULL, 
            0x3459CC042B557CA3ULL, 0xCC20D01285083D19ULL, 0xC20437B2FE5DDE03ULL, 0x348755892A15FC80ULL, 
            0x76ABAFA7DBC4FF46ULL, 0x06D4D7878A14A0F4ULL, 0xD85F76E0CB344CF5ULL, 0xDF3F626B5FC69FDFULL, 
            0x84AAD11B05B5D9ECULL, 0xD7BE51D4E6866637ULL, 0x29AED3C15B96D740ULL, 0xF26FF9B39015FBBBULL, 
            0x4D04F0098AE5F3CEULL, 0xEAAC2D1626DBA721ULL, 0x85019ECFE143ECD8ULL, 0xA0EE457EA1594145ULL, 
            0xD879FD9B109D4020ULL, 0x894461D32ED4D55DULL, 0x33BCF11289DBCDC1ULL, 0xFEBE2137DB5E38CAULL, 
            0xBE3F848B5708B728ULL, 0x06277789EF6A4AA4ULL, 0x8808C9EA21F716C4ULL, 0xA16C1E0B8895CF47ULL, 
            0xA9E509A5E6A5B240ULL, 0x1DC0B850073535D7ULL, 0xE381C74D66F5C374ULL, 0x0732C9813ECE1231ULL
        },
        {
            0x8B313D46254A4B5BULL, 0x976DD5A752318AABULL, 0x98EB4555B04BC105ULL, 0x439FF143E452E653ULL, 
            0xE3C3680E603CD9D1ULL, 0xAA81F38394977E12ULL, 0xE662A8D562C99A3EULL, 0xD3EA96D2753F7FD4ULL, 
            0xAD45536867109E89ULL, 0x7B2B6C3B82D3ECA1ULL, 0x3C4921563D2F7990ULL, 0xEDEF44D0B64402CEULL, 
            0x6697BAE45AC43E6BULL, 0xBDBFA61A9850A881ULL, 0xB73EED24E95D5E50ULL, 0xEB422C88E38B8AAEULL, 
            0xC20AEF4CB338EB36ULL, 0xD2853F2BCFC8C6E2ULL, 0x148234F6166B6CBBULL, 0xF09FFA7CB9DF32A4ULL, 
            0x5ECBDED2C7F70D8CULL, 0x40834A169AF97613ULL, 0x92CC47720B91F527ULL, 0xAFBC1876FD0F5C8BULL, 
            0xC55F2111A3ADA323ULL, 0x08138BA514A9D9E9ULL, 0xDB8B6D9DE4635902ULL, 0x4C7CAF8A28777DD6ULL, 
            0x2D5B49E86FAABA7EULL, 0xB66143561897132FULL, 0x4031870456E8488EULL, 0xF52B6AB090004B95ULL
        }
    },
    {
        {
            0x8312ADFCD46CAD38ULL, 0x9F5B244762635E54ULL, 0x67B0B68AA6DA7EC6ULL, 0x2F025453FD2CAC90ULL, 
            0x8DAF3C104EB66F17ULL, 0x95DAFBFB5C7D39DAULL, 0xCDC5FCDB3B565D9DULL, 0x000123452B443B00ULL, 
            0x04CE3AF52C27C444ULL, 0x19F1713B4D40F6EEULL, 0x0612C5A6C06985A7ULL, 0xD47C2BEB147677CCULL, 
            0xBECFF4274E8238AFULL, 0x3ADFCC6840B2DECCULL, 0x0CEAECCCDC05C43CULL, 0x422A8CB1546A1657ULL, 
            0x422CDC21744D724CULL, 0x06051AF1631970EDULL, 0xA9BB51942166EE98ULL, 0xE8B263F76D3DCFB7ULL, 
            0x215EF2E7E1C896A9ULL, 0xD6AF7B108EDD4DE6ULL, 0x0F83F17AECAE2D23ULL, 0xA9F4750C87385ED3ULL, 
            0x406EEDC5CB069945ULL, 0xA69D83BC9582D71BULL, 0xFDAA8B50FC219947ULL, 0x0FBE74550E360271ULL, 
            0x66D7C45141B532A4ULL, 0xFE0A9E109237B97CULL, 0x4AED671DB43731B9ULL, 0xA2396E97DFDDA667ULL
        },
        {
            0xF2ADB69F12521188ULL, 0xE82502FB3D689F29ULL, 0x080F1D023DCADF65ULL, 0x2F59DE9C28DF970BULL, 
            0x1735625D019C5BCEULL, 0xD644F97DB0D71C5FULL, 0xB4322294431AC847ULL, 0x1C83C15AADB5BA9FULL, 
            0xEA7136B438584800ULL, 0x5F436369AFC15FDAULL, 0xD6DAB7FCBA8D9A7CULL, 0x4EFA625875EF8BEDULL, 
            0x7E687F34D010BF59ULL, 0xA92479E5528065C7ULL, 0xF5FAE3AF48841110ULL, 0xE38BA5FE5464F4D8ULL, 
            0xD224FB1FF7E3D1F2ULL, 0xDD04B27260A0BC7AULL, 0x53219E7CA1877A5EULL, 0x842B8788CE691945ULL, 
            0xA410C822917CC451ULL, 0x09ED73964A2D7326ULL, 0x2156E8C295C20B04ULL, 0x420C60E15B4DD04FULL, 
            0xD03A71B4DD860DBAULL, 0xB32CE04352608E8CULL, 0xF56682EB99FDDA34ULL, 0xDAB585D3F4232E0DULL, 
            0x60424E18389E7B91ULL, 0xC7CF2340FA91E1BEULL, 0xBBB521F878764D15ULL, 0x542242596AF93886ULL
        },
        {
            0x56D9A6B1CFB736EDULL, 0x9894BE4EF6F08E39ULL, 0xF2E045CF291E0FACULL, 0x8E748CCEF5ED5CB6ULL, 
            0x53FF2CA7C72E18AAULL, 0xA0902065AA2195C8ULL, 0xB897115F3E6340BCULL, 0xC7A0BD33DE65BC2DULL, 
            0x749D78BC3C0B3221ULL, 0x85C14AB5C0BC1407ULL, 0xE2A34B7304F8BBC7ULL, 0xC586EB3656692FF0ULL, 
            0x7C3902452B1222ABULL, 0xCA1A0038EFE11478ULL, 0xE8378324F892D1EBULL, 0xE71BC36E5B331389ULL, 
            0x786385A586B41735ULL, 0xD43E9A94B18637E6ULL, 0xB1511C79DB0D607AULL, 0x8CF9EC51B4F23A74ULL, 
            0x3B9E9EE240659E23ULL, 0x851DF26FED5DB24AULL, 0xA563898348E7C46CULL, 0xC25C8138B42A3951ULL, 
            0x70386B694986D8C6ULL, 0x00C69B863CE61220ULL, 0x95697D7493D2C8E2ULL, 0xA50ADCC407F0BEBFULL, 
            0xD7B44F1A1BBA02F0ULL, 0x553A70DF7CC8169CULL, 0x22000A6E7E158DC0ULL, 0x25EF567EAB5C0BD6ULL
        },
        {
            0x478EFD3C1AA3E1ACULL, 0x6C651A0E5C08703DULL, 0xC12ADF4E5A29A296ULL, 0x49A5040DC29DE832ULL, 
            0x49D40AF59D10FCF4ULL, 0xC52A17CF2964E0BCULL, 0x54800C70EA0EC4CCULL, 0x05FE17C046DC0E08ULL, 
            0xCB588952ADB6CE23ULL, 0xED92462690999267ULL, 0x778B261FAC775BF4ULL, 0xE6047F1D64D60182ULL, 
            0x6766BEE875DD6C37ULL, 0x932CAFC3CF3F02C1ULL, 0xD6C322518A190287ULL, 0x73FD29295DE1690AULL, 
            0xEE2449ED66752C3BULL, 0x1B7FDD49E469EAA2ULL, 0xE604B36A0EA1DC99ULL, 0x4A3D7FE2A0E6EC1BULL, 
            0x5A45903EEFFE9726ULL, 0x0564A517D293E42AULL, 0xA0B487BF33675659ULL, 0xCD7349378A55FC40ULL, 
            0x211B8EA40EE56D7DULL, 0x053FFA8DFA355675ULL, 0xA313FD87D7AF2E52ULL, 0x5084A578693FDE31ULL, 
            0x1D954F340AD4393DULL, 0x69A1C7DB56F47D3BULL, 0xED62E1F009DB7CE9ULL, 0xFC98E3894FC43F30ULL
        },
        {
            0xBA050A5C3375288CULL, 0x30D0AC289C97BD9EULL, 0xF9488EF03A3D5D67ULL, 0xDD3607D1D843A98AULL, 
            0xDF4754D00C107459ULL, 0x38C0727E07B53C21ULL, 0x659F8CA42DB33C87ULL, 0x9B5DABF802702FB6ULL, 
            0x98F70FA5E0E74DE3ULL, 0x31E65DC831D1FB61ULL, 0x32ACD48323C4434FULL, 0x5CD1C122A017515FULL, 
            0x7D2F6097CA603360ULL, 0x5A19EE86225A13ECULL, 0xED926CB4C0F458DFULL, 0x60C6A8AAA1F33AFBULL, 
            0xE7B4E3EE71077AA2ULL, 0x1F6BEE2AA813FCA0ULL, 0x131FED1AB30773F2ULL, 0xAAB0BCA17D04917DULL, 
            0x23A10A503263B824ULL, 0xAB11BA1BA3F04365ULL, 0x54509D6BDAD66C4EULL, 0x3711AAC5383002E4ULL, 
            0x6A7C98905A314CA2ULL, 0x40CAB1B969D7B989ULL, 0x66EBBFC4122DE46BULL, 0xF5ACB8B975754E4FULL, 
            0xF0910C4DAF9A1190ULL, 0x003BD9D074991CA9ULL, 0x2E946B3D26344750ULL, 0x65952319F4471B84ULL
        },
        {
            0xABCAB61599AF3A17ULL, 0x1ACA72EB00012D39ULL, 0xDC5D22826F8DB7F0ULL, 0x25ED09CF1B2D8B8BULL, 
            0x56F99988A9B9B04BULL, 0x270816F9D41D44CEULL, 0x282D460F6B904FEFULL, 0x3C6A1E0CC6F2E5E0ULL, 
            0x2D6030202455A4E0ULL, 0x63007EBEEAA554E9ULL, 0xE7187D8B80FFA257ULL, 0xC6EA31F5FF4209ACULL, 
            0x7EF90DB146ED8234ULL, 0x1D9DE23EB817668BULL, 0x5079DAF275BFD7E7ULL, 0x79C8175326226F49ULL, 
            0x450C1E8FE2CA0565ULL, 0x76CBA08E2C73DF66ULL, 0xCA6B68BF433CA610ULL, 0xB1EA0E653D02FDFFULL, 
            0x6FC5072D0B88D468ULL, 0xF025E572A4192973ULL, 0xD2EEFE2318AD2C53ULL, 0x569A187727F12C68ULL, 
            0x85C71C2ED880A6E9ULL, 0x4D3F7411583DD55FULL, 0x756EBBB845D8F4C6ULL, 0x788694A1CF9D23EFULL, 
            0x982E29E2EB93D1D0ULL, 0xC2746A3421445BE0ULL, 0xAC22DED954E7923CULL, 0xFE0C9033A5CB54C0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Athebyne::kPhaseAConstants = {
    0x26D93D0A46D00371ULL,
    0x862129A73F7E9BC5ULL,
    0x4F2D23A7BDA937EDULL,
    0x26D93D0A46D00371ULL,
    0x862129A73F7E9BC5ULL,
    0x4F2D23A7BDA937EDULL,
    0x977D39F94DC3C77AULL,
    0xC2FF0CF4DC0B134EULL,
    0xAA,
    0xAA,
    0x04,
    0xF2,
    0x06,
    0x68,
    0x54,
    0x20
};

const TwistDomainSaltSet TwistExpander_Athebyne::kPhaseBSalts = {
    {
        {
            0x547734E054E6E3C4ULL, 0x8682D3B094653FFDULL, 0xC9B1AB2F43864F2FULL, 0xE76BFC38B5B60514ULL, 
            0xCC71D93DD0666CA8ULL, 0xE412F625812C2F31ULL, 0xA8FEEA7280F954ABULL, 0xC4B72BA4BF56D188ULL, 
            0x130B6E0DD049995FULL, 0x3CC0534E5B42BD55ULL, 0xAEBD397B0AD76ADFULL, 0x0D2D41B816282E7AULL, 
            0xAB57475A2E3F6740ULL, 0x70C07018D9950C95ULL, 0x4D5E4C5D19C54D04ULL, 0xDECD75D2CC7E1314ULL, 
            0xDAFE4683A908CAA2ULL, 0xD067DCCD38626CC6ULL, 0xA2958C7E6B917430ULL, 0x8B4A98FAAA9C1484ULL, 
            0x8CFBC738FF465789ULL, 0x59BCB93FED752662ULL, 0x7758A660A82452B3ULL, 0x7AFB36E44B6F4B24ULL, 
            0x6104D69E590674CBULL, 0xD89B261461CADD8EULL, 0x8F8A6755CBE4608BULL, 0x8DB5E1608CA7A53FULL, 
            0x3C58FA4D83AACA62ULL, 0x8CA58525C2B0458FULL, 0x06AE6EB56642836CULL, 0x54D840E8EF519C04ULL
        },
        {
            0x1FF9207A69ACF78BULL, 0x8E62FA0D88CFA671ULL, 0xA8E89BD45564C3FAULL, 0x984C9831B429D519ULL, 
            0x9A723EF4443976FAULL, 0x2118DA5F72F793FDULL, 0x48BC5C947EFC6B71ULL, 0x565B1298AC66A2B2ULL, 
            0x2F598F4F7E1EA296ULL, 0x577AA74D0A416F65ULL, 0x03A77B62057CAFF0ULL, 0x67D15E0AFAD1E86FULL, 
            0x69280439F72BB85BULL, 0x59CC0D486343E8DFULL, 0x0D6ADE70387ABD10ULL, 0x18187C37D148351DULL, 
            0xF21F4042334100E5ULL, 0x8F5AA2E6C14F6E6BULL, 0x192D46743022EEF4ULL, 0xEF4F77C63E34B87AULL, 
            0x29438ED96B607416ULL, 0xAA3B4C3CC25E6368ULL, 0x876FF69F934D8911ULL, 0x7966CD1A5C5711B3ULL, 
            0xE2599B48FCA86D14ULL, 0x1D2A71553E04885FULL, 0x9711C55DF8B104DAULL, 0x9D9D5598B08E7855ULL, 
            0xC71FF1B55C8AA1D0ULL, 0x1CEC25D3A8A0D674ULL, 0x66957EF5E9B98F6FULL, 0xA88C01E5C44E0AC6ULL
        },
        {
            0xC57CF3CC3AF89FADULL, 0x8A21FBF39DB385D1ULL, 0xA93B462B9147477DULL, 0x15CA826ECA2575C8ULL, 
            0xD94CCE916E6D4866ULL, 0x5A1187E5BB032408ULL, 0x5941C21937F76DAAULL, 0x10A91A41C5843BA3ULL, 
            0xEF0BFB1D875FAC9DULL, 0xE955DEBB364BE710ULL, 0xF463C93A6AC0BDCBULL, 0xD22883120C465AE7ULL, 
            0x70B8291026D1EE63ULL, 0x56908326F3307A23ULL, 0x258324A4DB84CDA2ULL, 0x0E42CBCF5D6DBCBFULL, 
            0xEEBB8920E43A40EAULL, 0x6C06C1854CB3B273ULL, 0xF9BF759280F7DA56ULL, 0x056442345C2605DFULL, 
            0x961B9EA1CACD125CULL, 0x503CE4BE227E6C2AULL, 0xE4C42C75CCB466EDULL, 0x3B620E44AF402299ULL, 
            0x90AC9C1C700DC135ULL, 0x60302379A443AD93ULL, 0x845A89C44B6E0BE0ULL, 0x019F820C04CF2F06ULL, 
            0xE28F61673EF34382ULL, 0x8BE3678C5C81ED33ULL, 0xAA7CB8D72DFD290CULL, 0x2BC7FEECC29C2219ULL
        },
        {
            0x2C6F4C0908945557ULL, 0x000A014763E09BDEULL, 0x1245E2740450BE39ULL, 0x2DD8A55FEBFDD3FEULL, 
            0xAEE80171B954D13EULL, 0xCBCC480D440BC977ULL, 0x7665569C0BD11429ULL, 0xE11D51AF3CD1E326ULL, 
            0x1359DFA27121E203ULL, 0x8A988F1D0E2A5EA1ULL, 0x19E18E5B8FF8447AULL, 0x23CD2C45DBA93CE3ULL, 
            0x760E23A8AA47E2C2ULL, 0x8156E2D1F7F19186ULL, 0x297633AC2B2E6107ULL, 0x550FD98B27906074ULL, 
            0xECC62CBBA5BDB646ULL, 0x83008AAE7316AD0CULL, 0xA05064A26A7FD5B7ULL, 0x74711027676F297DULL, 
            0x603E62EED758D949ULL, 0x2D74C8EA19E7118EULL, 0x039F37671E08636EULL, 0x0C7E44732F5B795BULL, 
            0x5A05ECE64877F900ULL, 0x93925D92D34B9204ULL, 0xE0DF198731E250D5ULL, 0x2C8E4CC1728E8311ULL, 
            0x6676E18F5B4AA240ULL, 0x4DC4D811747EE50FULL, 0x7F0B14CA2E2256ACULL, 0x5A168A7B582172DAULL
        },
        {
            0xD410D2446ABFE091ULL, 0x6C6339628CA7D35DULL, 0x876D5FFA6C9CD01EULL, 0x6E708981F66C957BULL, 
            0x17596531D585C757ULL, 0x893D56366BE005D8ULL, 0x8E69602E55E429F5ULL, 0xCF40A77C81398E78ULL, 
            0x126117880D394088ULL, 0x5D1C02800BBB45C4ULL, 0x68DEA42471A87B3EULL, 0x003864E7CBD74D71ULL, 
            0xA10D4822922A294EULL, 0xF17C61627BE103F9ULL, 0xB8E7FC2E1783A6D4ULL, 0x2414EF65575EB928ULL, 
            0xD4239295DF440117ULL, 0xF1EC7045B5AECDF4ULL, 0x1AB731064CF56E4FULL, 0xC4AF1A5949B9C4B2ULL, 
            0x5AB6228A308AE15AULL, 0x05167490E731EDE4ULL, 0x045E8DEAEE595B75ULL, 0x54E68FBFEBEE1E0AULL, 
            0x677615153E56F8D3ULL, 0xD793186E3C7C40B0ULL, 0x1A035FABCF585AA9ULL, 0xC16DD351448F1BF8ULL, 
            0x13ABBA8729CED999ULL, 0x8B7F3C25F2C1C08DULL, 0x3F41EBD5C2EC3D8CULL, 0xB2A49107281515C5ULL
        },
        {
            0x8E911357D65DC2E1ULL, 0x5DE8CF54410FE188ULL, 0x00826A4192F8CAEEULL, 0xC06D851C91F74A10ULL, 
            0xE83FAE9BAB561D0CULL, 0x151E7B8EC103251FULL, 0x96C6596C571E8024ULL, 0x1E4F2B1874FE3A55ULL, 
            0x218F385874DC518CULL, 0x75E71A861E2F2D80ULL, 0x2EA6087C48BB2197ULL, 0x6EBB9BC275BDD604ULL, 
            0x34020F52000FC4A5ULL, 0x66950A5A5E0F7685ULL, 0x5846801DAD37CCE6ULL, 0x725663DB2F88D236ULL, 
            0xC70E05E022D0C2A2ULL, 0x1E4C4A6BEB35AD73ULL, 0x2AB7EECDB6CB45BAULL, 0x5629FA63FF7511AEULL, 
            0x27791A0D7D584648ULL, 0xBB7AAE64F48B0B24ULL, 0x11405663D3B66FE7ULL, 0x4B4BDEE0B9AB3350ULL, 
            0x52263F0AEA684D99ULL, 0x386285481DEBDCE5ULL, 0x69265DFDC2056853ULL, 0x6511FD9D55B8E049ULL, 
            0x89AA83AABFC6E3D5ULL, 0x5E1AECB956F741DAULL, 0x8C40C22B04016AFCULL, 0xA8F7923C3D1D855DULL
        }
    },
    {
        {
            0x765442465710573FULL, 0x4B416DBD49EABAE9ULL, 0xF572D74EE0863A96ULL, 0x3B7A5FDB49A41866ULL, 
            0xFEE83C8AC9F81741ULL, 0x9EE0F49C91F683CFULL, 0xBA27EC147BCB6618ULL, 0x43C6EC2C685118BEULL, 
            0x7423675794A34935ULL, 0x613A32F888831268ULL, 0x8173A7E59496124AULL, 0xBEE5BB6D2EE080B2ULL, 
            0xCBD77A41C88AAA4CULL, 0x837446788AA0BE8DULL, 0xF332447832DD73E0ULL, 0x62B656C2BB8DEC20ULL, 
            0xCD9D2426D03B9C6CULL, 0xB8DD3B0E542CA233ULL, 0x8A82B08CEC38CA25ULL, 0xC1FFDF8D94997B50ULL, 
            0xC0FDB3F1C5C42BE6ULL, 0x9BC9B941F5FD47D1ULL, 0xCACE711ED8859AB2ULL, 0xF0A072E7BC2A8107ULL, 
            0x972F01CCB4A36C73ULL, 0x54B21ACE8CFB46DEULL, 0x3AE6C0EC5F56733DULL, 0x4BF99266B2D02039ULL, 
            0x6DAAD50F91C21F2EULL, 0x978DAEEF9B03A0F5ULL, 0x6B239EA57EB8030CULL, 0x1DA2500D3FC593E0ULL
        },
        {
            0x4F99CCEEC5653870ULL, 0x4AA68195028DEB04ULL, 0xBBF9F89643E7B911ULL, 0x420A2BC339D9E761ULL, 
            0xA851EDA1B30921B9ULL, 0xD56CFE1C7AFAA890ULL, 0x9F74A5D13413FB63ULL, 0x32B0D3B9EE9C683DULL, 
            0x4A8B91546D1CBBAFULL, 0x4DDD7A426BBE3C77ULL, 0xDCF0CD541BF50624ULL, 0x357EFFA1B9FFCD82ULL, 
            0x65BCC6680FAF5690ULL, 0xEEFB8AC588C8697CULL, 0xDAD6B036D97001E8ULL, 0xE4F5951055DA1D5FULL, 
            0x37B6F2F84E43BF62ULL, 0xE04FD89437CB5A1DULL, 0x6288939ADC0273D6ULL, 0x68DAFD758C4C2F4CULL, 
            0x9EC83E07885C0180ULL, 0x280CB5993825471FULL, 0xC7ECE69140DD6152ULL, 0x8D79B92FED56920AULL, 
            0xA4756FEA10AF6814ULL, 0x4C48921031522260ULL, 0x650D93B777D71113ULL, 0x1096D68FE95CADFCULL, 
            0x1AFEC0E1A85F38CBULL, 0xC8D9295FA595461FULL, 0xD7063854BCC3682AULL, 0xC4609922C7F67B8AULL
        },
        {
            0x3C98405D52556052ULL, 0x988806F112D4E27BULL, 0xA7EA86975C351CB5ULL, 0x2087401DAE42B906ULL, 
            0x82E9EDB4D0A5294BULL, 0xD9BCE0D412949AC3ULL, 0xBEA086D8582D73E9ULL, 0x680AB91BACAD71E5ULL, 
            0xC0137C122F3D4918ULL, 0x07C186986100E2BDULL, 0x33D4A5661C870547ULL, 0x3E92CA6EC7D13E78ULL, 
            0xE5DB59E8C342689CULL, 0x00A6770C31C229ADULL, 0x21CBF290B416A6E5ULL, 0xAB713046EB23B33EULL, 
            0x47CDF51668F09415ULL, 0xD92A92C9B0653F8CULL, 0x9E2D7E104D49097DULL, 0x9CB8A6CF2EDA0046ULL, 
            0x365F2D2BFF801FCBULL, 0x25E19FDA5129A365ULL, 0xD6A303F7C5A9BE70ULL, 0xB0EEBD083A4906D2ULL, 
            0x9D685715F890E060ULL, 0x8C067393DB550864ULL, 0x1F41647ACBB38CA4ULL, 0xB15F50F9A14373D7ULL, 
            0xE5D0C24A6CA2481FULL, 0x80D41566554BAC5EULL, 0x073470F66166DB15ULL, 0xE0585AFF266DD434ULL
        },
        {
            0xE90880102D0D6F00ULL, 0x16551A6B438CBCCCULL, 0x7974A0912DD1E14EULL, 0x96CF57718A626CF9ULL, 
            0x60748B3A90A036E4ULL, 0x85C55D497FB16E6DULL, 0xE0798500E754D32FULL, 0x4F658107192D7E41ULL, 
            0x32B5D48D99246FC2ULL, 0x03B1E558B831AD39ULL, 0x4E5A63818F4E8C6EULL, 0xC0B4504FCD47EF72ULL, 
            0x3129518E9FE76880ULL, 0x4D4A19EAEE3DAEB5ULL, 0xA3EBD14166A9BC51ULL, 0x1A9E678ACDE0470FULL, 
            0x7CAD4294C0F47FF7ULL, 0xD75B895E1797703AULL, 0x6FD555ADC42BDEE8ULL, 0x2ADC16F68F4D380AULL, 
            0x009BCB07BFC9AC0FULL, 0xE8C243BFBE559775ULL, 0x3C418E1778908D39ULL, 0xFDD7E044ADB6B03CULL, 
            0xF01E8DE4D19F166DULL, 0xA4A5B104B4C7CC7CULL, 0x8A44D1FD53692543ULL, 0xE2E9F94C40C7CB10ULL, 
            0x4AE1AE62AED78609ULL, 0x2A59C278D62D6089ULL, 0xB571E3CE11ED3C94ULL, 0xC84A02C038112BFFULL
        },
        {
            0x496CAC518D9CFAB9ULL, 0x316729CA8B15DF22ULL, 0x4BD12B5BE5700331ULL, 0xCF426771C06C4381ULL, 
            0xBCCBE0FC7DBB64E5ULL, 0x2483678C61AA533FULL, 0xEB6D028F04D414B5ULL, 0x6B990CD73FEAF468ULL, 
            0x0078C0431DCA62C5ULL, 0xA51DB4D507132C87ULL, 0xCBADE3039EC4337BULL, 0xE3FD5C4F8CB24D96ULL, 
            0xC6D79DCFB5FFF7D5ULL, 0xED1F2C627E950E52ULL, 0xDB99694B423C7330ULL, 0xB5342CFEB81574FAULL, 
            0x92DD7EE4B37A5A18ULL, 0x3C94E2A70E3E8873ULL, 0x479C1B01838B8C90ULL, 0xE0A316B902BCBCB2ULL, 
            0xF3EE1CB1A71C4167ULL, 0x705F8C15331387FDULL, 0x899863931348F572ULL, 0x56933C619A7C929CULL, 
            0xF7D9776A5BED664FULL, 0xDF92FE9ED296600BULL, 0x21C0D956BE99ABBBULL, 0x41BFB8609796E7EDULL, 
            0x85655251A3B9FB15ULL, 0x6838098607C47C74ULL, 0xBC3F68C3EAA36CACULL, 0xC910CF9472E8EA2EULL
        },
        {
            0x11C3E1FE2055E3EBULL, 0x5BBD27E5AF2AAA10ULL, 0xBA9F2EFB889BC623ULL, 0x4B128A49DB3A97E6ULL, 
            0xE568E942DB2FEEA0ULL, 0x7696BE3E00D324F6ULL, 0x464912B18F70501EULL, 0x3BCF73066C4602C0ULL, 
            0xC6BB57CA93866534ULL, 0xF8F44D89FE3248DEULL, 0x539F4514A89D6354ULL, 0x32F155C9A579D95FULL, 
            0xDE48F511A7FDDDBAULL, 0x855F9059F0D94B1EULL, 0x550324A63F44C0B7ULL, 0xBC5A35C95E60EFFFULL, 
            0x623F55C845A796FBULL, 0xA5D62A85A2D681EAULL, 0x214CBBC62BCA0637ULL, 0xFF4DFC017059B14AULL, 
            0x28F5EFB69032F0FEULL, 0xCE005DE5D4DD8169ULL, 0xCDC9B0588DBE57EDULL, 0xFD05FA2C0011A502ULL, 
            0xB728766C3E4B5476ULL, 0x7A4C99E996B76282ULL, 0xA251DBE3CB96338BULL, 0xB0E89DEC378361E8ULL, 
            0x49FFB5ADEFC7E840ULL, 0xD3605F016E9E2EB1ULL, 0x5850B34A7AE12982ULL, 0xCEA65607A59175FBULL
        }
    },
    {
        {
            0x24CCD5E1481DEBE6ULL, 0x186E8A5D8BB17920ULL, 0x44E90AAEE661809CULL, 0x00D8964DE3D70EDFULL, 
            0x86647A8AAD41DE1AULL, 0x9CABC9DBCAD94B23ULL, 0x3EE0F59CFAC5AA25ULL, 0x24227477AE56A007ULL, 
            0xFB5ACC95D35FC283ULL, 0xDD0D6B30F63FD700ULL, 0x5B108B9C77C0AF1CULL, 0xFB938C2851034D29ULL, 
            0x747C075E09BCF9FCULL, 0xACD560A29E8B9D10ULL, 0xD942E3DD5E6D3888ULL, 0xB1BD96734225F520ULL, 
            0xB7371946BD3FE32CULL, 0x28D1548CD51C1AAEULL, 0x404FAD884B59CF3FULL, 0x6026C4A94E22BDADULL, 
            0x9A8DDEA697EE127AULL, 0xE24EE5AC765522BEULL, 0x2B3DBAE61D62CF46ULL, 0x7829DDB5A7A55D97ULL, 
            0xD5A7F58D30149057ULL, 0x6C0CC4F20F91CC77ULL, 0x0D42E0A03C4767A8ULL, 0xD4B6BC72BC149E7AULL, 
            0x1FC06B0CDABBEBA8ULL, 0x58749E779A945649ULL, 0xD082614220F6E204ULL, 0xAF546D5B1D11A5ABULL
        },
        {
            0x2B59DA072B7A6D9BULL, 0x408CBCC5F9C27ACCULL, 0x2CDBC1FE3C581E1AULL, 0x9E1AA4FE869D231AULL, 
            0x4067E9DA34919C76ULL, 0xB6626AB672489E0DULL, 0x71C7EC2C250C05BBULL, 0x6FC373DF7AFED273ULL, 
            0xEF178B3DC20CBFD3ULL, 0xFBBC388837B6B027ULL, 0xE9F85DCD56FAAA06ULL, 0xD86B1C252C5BDEC6ULL, 
            0x854CC076377F6E6CULL, 0xC9F2F650D414CB22ULL, 0x1FA407AFE38F73C0ULL, 0x35C4EF4E0366218BULL, 
            0xD8FC728F0F1CB443ULL, 0x178D9D9808D2B53DULL, 0xE2CDF8F1F404871FULL, 0x27C71307337C9395ULL, 
            0x5904AE86CD511C73ULL, 0xAE47ED3B3A8D9EEBULL, 0x18C69E2A9C56A06DULL, 0x88192E14EC460411ULL, 
            0xA88A86B75D5780EAULL, 0x8499B77AF769546FULL, 0x4C7FE3BC36BEB0C3ULL, 0xB9CDF15E33DE3DC5ULL, 
            0xAC8A1FF08FC607BEULL, 0xEA8CCC65687BEEF8ULL, 0xE0DF01B3530FBB47ULL, 0x7760479C02F33F66ULL
        },
        {
            0x66F677E2D6204FC3ULL, 0xC9760F7551168F36ULL, 0x4A5939FF8AC363A9ULL, 0xF2BFE31B556A9EA0ULL, 
            0x00C1C3A0670D07DEULL, 0x1CB3AE2A46E543B6ULL, 0xDF31714FE54D5EF0ULL, 0x0EDD02FBD76164F8ULL, 
            0x55CBEC75912697BEULL, 0xAC254715DFEA39DAULL, 0xE59F57C004C88E1FULL, 0x4F3B197C2A555952ULL, 
            0x8CB748C58BBF5FDEULL, 0x103D3310BDB3A1CEULL, 0xBF561DFBA52C0648ULL, 0x69C888ABBA0EFF33ULL, 
            0x77446BBA2057EADAULL, 0xF08A4652BA94E486ULL, 0x64ABEB6B9DC298B8ULL, 0x1E593FEA5745F211ULL, 
            0x09744B340AD402E0ULL, 0x2B4CA84138E20BACULL, 0x39513906177DE8E7ULL, 0xDF03FCAB9DD39192ULL, 
            0x01CC6A0C772BBF21ULL, 0x6CB888612533AE5AULL, 0x7DA154E06DDE98FCULL, 0x5CA756FEF05E7723ULL, 
            0x4E2B6FAB91824370ULL, 0x1DB517A37989BFA9ULL, 0xB1DB1C98B324AB17ULL, 0x697D18819C22FEFAULL
        },
        {
            0x90218EE2193051C1ULL, 0x76280CFD64ECC401ULL, 0x8C809745B1CB1261ULL, 0xB0106CE208E7C193ULL, 
            0x55225D650F4878A6ULL, 0x1BE04348985A178FULL, 0xD8AFE68595ABB15CULL, 0xEF1D3E0440086DE5ULL, 
            0xC2C7D0B4CCDB9736ULL, 0x6DF49B3BC4987AC8ULL, 0x6BECF72811153CFBULL, 0x1DF5DEB97B291D32ULL, 
            0x8891B0C588DCF598ULL, 0xABE9DB4DECB66E7EULL, 0x04B98F88865F1F6CULL, 0x3BE80088B29BFFEFULL, 
            0x5275CCB4CE7CC47BULL, 0x7DCE2AE37DBF48EFULL, 0xBED3E4AC2C7D1D9CULL, 0x168EBEDAECD9A438ULL, 
            0x7C33934DA5A74F99ULL, 0x70F7516F9E1E5D08ULL, 0x33451EC0CF40876AULL, 0x15709D1370ECE62AULL, 
            0xDCC17D0ECB058DEFULL, 0x75A9FD422DB7EA7FULL, 0x5767D06CF2DE1046ULL, 0x81B443EE04447B05ULL, 
            0xC869D45FF3048A2CULL, 0x3679D0932DFA6BD9ULL, 0x1EC8A2F4AD63512CULL, 0x272984AC7181F6D2ULL
        },
        {
            0x5D14504875849758ULL, 0x28F641E02B42D0B8ULL, 0xA3CBE17FBDBAB794ULL, 0x2BEFAB2004D449F1ULL, 
            0x8628082826B78E7AULL, 0xD9458D8B02B56AEDULL, 0xFFB0A2C0B1FFBB25ULL, 0x8C7BAE82A432729DULL, 
            0x0F6CCA679CE73D08ULL, 0x447229B31DEF91B3ULL, 0xDC01DD66F69EF276ULL, 0xEC47E978FF2B5149ULL, 
            0x48E2725FB6A351E8ULL, 0xAD342284BD6BFB92ULL, 0x1C1ABE596FE3CB30ULL, 0xE0C3F88574D7B24BULL, 
            0xB125D496910AE3ECULL, 0x81EB51515855DDFEULL, 0x4AFF2FCA4B3017EBULL, 0xD24DA67456DF6971ULL, 
            0x6DA0509887863245ULL, 0xED82F724CB0CCC1AULL, 0xC7BA008B010EAB7CULL, 0xC265E0B69345772CULL, 
            0x03D620A8B459F639ULL, 0x892568E0662679E6ULL, 0x082BB15FAEF268E3ULL, 0x9C69F33D361E3738ULL, 
            0xA9F57C20B356703BULL, 0x6F77FEF39DDCAE1FULL, 0x47EA97640E8134B6ULL, 0xF84CFE33AFB6ECB0ULL
        },
        {
            0xB23E217B1E67146AULL, 0xF47AE8F2E8C46EDFULL, 0xDAFAE2C1A8187D64ULL, 0x080A3603D05039E0ULL, 
            0x59AD2BC43C455160ULL, 0xC7A49064C4911CBEULL, 0x33113878F80029D3ULL, 0x952359997BE8F4C3ULL, 
            0xD00CB1D21122A97CULL, 0xD074E1D370AD8A0EULL, 0xA25802D198EB4256ULL, 0x56CA7A2677F0E193ULL, 
            0x0DCA1970E2B0E980ULL, 0x2BA479A91445E1FBULL, 0xE0AE236B29A91073ULL, 0x8B7B7A81E97867B0ULL, 
            0x2522D94D247B7F30ULL, 0x3BF1F9759D7F14BDULL, 0x82F90236737EA956ULL, 0x6C6D67BAFFC44E12ULL, 
            0x718E4955129798E5ULL, 0xD9D8D8E942AC4EA9ULL, 0x482B1BC721C9BE9BULL, 0x0938EEC4E4812AB3ULL, 
            0x79846FC0CB895649ULL, 0x35434F2CBE861DF6ULL, 0x45AF289C861CFC73ULL, 0x292F44C3BEFA471EULL, 
            0xAD46069014B28ED2ULL, 0x8C32CAAF2586EC3BULL, 0x441D53B1D0A2CB36ULL, 0x55978EC3C30806E1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Athebyne::kPhaseBConstants = {
    0xE12C2F6F43141A86ULL,
    0x1B429B342575FC7CULL,
    0xCF3F55C62A357B3AULL,
    0xE12C2F6F43141A86ULL,
    0x1B429B342575FC7CULL,
    0xCF3F55C62A357B3AULL,
    0xAA4476C34619CADDULL,
    0xE2A88640DC96164BULL,
    0x53,
    0x2B,
    0x13,
    0x55,
    0x6C,
    0x3A,
    0xA8,
    0x55
};

const TwistDomainSaltSet TwistExpander_Athebyne::kPhaseCSalts = {
    {
        {
            0x261C770B46DE6D37ULL, 0xA0A112D1432E8314ULL, 0x5DE0764E58E8008EULL, 0xD035D8D6577CE763ULL, 
            0xEFA4CF31404B192DULL, 0x97864BFE6D96D06DULL, 0xF838AB7BD6F321F7ULL, 0x7F599AC5CA17A21BULL, 
            0x194CEF97D55480F2ULL, 0x44B026645FEC3449ULL, 0xE26E38E321868231ULL, 0x36BFC539F26C7265ULL, 
            0x7C8A978D29177965ULL, 0x3F743CE0180219FFULL, 0x49D741D67E883735ULL, 0xDF44572E45D9BFADULL, 
            0x4E76363A6D8D14CBULL, 0x8C3013F5B9023460ULL, 0x075C281644C03201ULL, 0x4468D655F8A39A01ULL, 
            0x2ACCF7B9AC8C7F53ULL, 0x52C66E019DC17301ULL, 0x00648A41E955A998ULL, 0xD75C6C96ADFE0A6FULL, 
            0x74C6880C7273084EULL, 0x621751D5D9D5CC11ULL, 0x2CDF213DB166AB28ULL, 0xFADA2DDF63A80D85ULL, 
            0x10622F72D48F3495ULL, 0x063B260FFC76B24FULL, 0x33B335349BBE1E80ULL, 0xDAAFFB620BBBE86AULL
        },
        {
            0xB5AC2FB0CE0D83E9ULL, 0x417284122176A47FULL, 0x560CC76383B6AF0CULL, 0xED4D13131E5E9F9BULL, 
            0x8BBEDFF9126B6E15ULL, 0x246F3B8BB3EBB5A2ULL, 0x7E77060C5DBD4F60ULL, 0xE190390DDD4AF765ULL, 
            0x2C2A5B9C733C34CFULL, 0xC243E70CEC196E7FULL, 0x254544ADA68692A3ULL, 0x48D0760A4162BE32ULL, 
            0xBF1B4CF77277E6B9ULL, 0xF4F9F39E88A8D644ULL, 0xD839DEDB88CF418EULL, 0x181C2241E808CBA8ULL, 
            0xEA5E00BF1B97691BULL, 0xA76275448CED0A05ULL, 0x6A880967985D0FB1ULL, 0xA5E148DCD3ADF0FCULL, 
            0x627DAA5B42EF0F4EULL, 0x51D12E142CB4EA4CULL, 0x7C5B82E66DB10022ULL, 0xA11C7FD4183B3C9FULL, 
            0xB3EED1F99A27A4D7ULL, 0x25AFE81945F9E638ULL, 0xCE00E3EE6E7B218BULL, 0xDFD506EFEE465907ULL, 
            0x10843EDD300A1A1FULL, 0xEB09AE5671D74594ULL, 0x106683155923FEB9ULL, 0x2ABFEFF950A467C0ULL
        },
        {
            0x7A36E9916E6B8A7DULL, 0x29937F98AB6B364AULL, 0xA2C7013F9A4B9CB0ULL, 0x8341EB4D16321DA7ULL, 
            0x0CF4E3F630065750ULL, 0xBB05F20AE45DAACAULL, 0x010DC584F325754EULL, 0x11FA60A4070DB638ULL, 
            0xEF736C583929E656ULL, 0xC9B77087733AA4CDULL, 0x8DC78203A2162EDFULL, 0x0A49FCDF88296F50ULL, 
            0x4B81612F7A85EE23ULL, 0xDAF41DAF62850459ULL, 0x988E5AA8F3DAA2CEULL, 0xB07FA04F451292F4ULL, 
            0x99AF48CA24275CFFULL, 0xB0250A16D221D835ULL, 0x1411D06CCB2DD1CCULL, 0x01A20D1ECED1917DULL, 
            0xEB5092481DD92013ULL, 0x19B5D1A70A6C6DD6ULL, 0x51AA12C968DF79ABULL, 0xB8C448E13BDAA27CULL, 
            0x09F6E4DCE9690364ULL, 0xA09C02BE06F6396EULL, 0x2EC89E35EE3CB29CULL, 0xFF264D8F5BF3B5C2ULL, 
            0x2653C4A648CB199BULL, 0xDED4C4B6547D6574ULL, 0x42056EBFE8CC9519ULL, 0x3D429255B6C4D3C8ULL
        },
        {
            0xB249E5C192EA4D9BULL, 0x7BEF75FE05BFF797ULL, 0x6D5B58EB9BEB884CULL, 0x616CCCAD2B1D75A6ULL, 
            0xFFD717D97E49D116ULL, 0x3F7A945D71795F8BULL, 0x412DF8D80871B614ULL, 0x5D55AFAF12273F13ULL, 
            0xC7DE8F01AA7E712EULL, 0x39C857F6CF7BF132ULL, 0x80223946FD067687ULL, 0x4F2DD6546406A078ULL, 
            0xA64142A54588AA8FULL, 0xF6E48F5DEC9BF3E3ULL, 0xA373FA38F1A1955DULL, 0x5F3D02E67373D995ULL, 
            0x6F5FB898D38BC7A1ULL, 0x9D8DE89F10B6D181ULL, 0xF0073059446AAC6EULL, 0x137C9E6D05AF06AAULL, 
            0xC03A8C0416176479ULL, 0x33FD41992A6740C5ULL, 0x3EFBBD676A756E8EULL, 0x539BAC0CF872EC19ULL, 
            0xD449A4EBDF1C1BE9ULL, 0x2F6281D0FE43390CULL, 0x6AD56DF22A5EA94CULL, 0x260538DF69AA8610ULL, 
            0x1A1986C45E985CFDULL, 0x60844EE444CBC37EULL, 0x2EEDE7C8FFF04940ULL, 0x618EDE0D6EFCE0D3ULL
        },
        {
            0xACDD8FB60BC30245ULL, 0xC3FD7C3517013B17ULL, 0x3F452FFDACF632BDULL, 0x64575E56AC64E05BULL, 
            0x16C60DD0CA39E45FULL, 0xBE8439ACA118C237ULL, 0xC4457CA677FB8020ULL, 0x0F30EFAC93BFE9C3ULL, 
            0x5BE0191F25485738ULL, 0xAE2FF3F985E63F14ULL, 0x23706EC13710AAD5ULL, 0xA4AA5A0BD74A969FULL, 
            0x1D725C73D4A4D08FULL, 0xD2B296F67F4C6A71ULL, 0xA92C57541CBB51FDULL, 0xFA324BC547C8F49EULL, 
            0xFD6C9B93458F525CULL, 0xD0A144AA596354B8ULL, 0x9F3ECC3E637A0CAEULL, 0x7E1266E987175F57ULL, 
            0x5F40692F6FB6BFB9ULL, 0x5FF4234108D6F2E7ULL, 0xA4D60CF51F88D4B7ULL, 0x2810174D002D9CCAULL, 
            0x9FC404F35B4BF742ULL, 0x89F154DCC46139A3ULL, 0xF4D2C6853A58D490ULL, 0x9D2DE0A6E518DE0EULL, 
            0x5FBA650484CBD3BCULL, 0x3A57894BBBA8A52CULL, 0x292DAD23A0A3A1C4ULL, 0x2623B52D1C33A341ULL
        },
        {
            0xF8EC9BB9EE46DFC9ULL, 0x65A48F266074C1D7ULL, 0x057C5FC40AD14F1CULL, 0xDD4C10DB42170026ULL, 
            0x8BBD5F8E414CCA81ULL, 0x74CBC512A3B89022ULL, 0x1FA4D6FBC9BA9DA2ULL, 0xE7F6A113769C83BFULL, 
            0x473BD02E33086538ULL, 0x08C58E180CEB1177ULL, 0x136F5F5DCDCD6D51ULL, 0xF6AAB99DCBF37750ULL, 
            0x12DEE0A2CE0D8ECEULL, 0x36FD54D7B2DB204FULL, 0x74299B1C7619AE26ULL, 0x976D57916A7E227AULL, 
            0x1A2A4078F7DD72F7ULL, 0xB361C919259F0887ULL, 0x055295F06FBF8546ULL, 0x58EFEE28B93C6737ULL, 
            0x39506BC2A5237989ULL, 0x599E55D1BB7F1A72ULL, 0x00E32B12A87A9C79ULL, 0x7F14BD2C7C6DEC10ULL, 
            0xC72D2FA0A02AB3D0ULL, 0x8279A54C1C07140EULL, 0xD965DA0DB9CAAFC1ULL, 0x454E63B87A28E22AULL, 
            0xEB518DC51CB547F3ULL, 0xB777FCF0B6151487ULL, 0xA331B98F5B769DEBULL, 0x9B145BF8597FE724ULL
        }
    },
    {
        {
            0xAA754BD74F727C9EULL, 0xC6E202F71F8133C9ULL, 0x47D83C0EA4A6B6F8ULL, 0x4B35A1A84A24B72AULL, 
            0x5FE1A34B75117C33ULL, 0xEA05CCDA8E8615B0ULL, 0x1F4B00534798A94CULL, 0x4642EAFE475253E3ULL, 
            0x7CBDE9638D5C40E7ULL, 0xA0D33275430203DAULL, 0x2E3EC9DF8A1E60DEULL, 0xFE25C2258413F4C0ULL, 
            0x5C41A4F8BE3DD49DULL, 0x3CB9FB63D2AC6228ULL, 0x81CA5E3E181F770EULL, 0x2E54A708FF8D81F6ULL, 
            0x413F6E32DD90B8D0ULL, 0xA3CBB8F8186E8077ULL, 0xCFEC0D67167292FAULL, 0xCD6639296A9855F6ULL, 
            0x2F4F26B3CAF6809DULL, 0x5B2A6D2F2D6841FEULL, 0x7DFE2BECF61E455EULL, 0x64381417656A60BBULL, 
            0xFF01AEE01CDBF8D9ULL, 0xCAF02BC12B2321CAULL, 0x90291245E3B47DF5ULL, 0xC159A99064579C12ULL, 
            0xBD249A72D82CE633ULL, 0x6A412B6C01C249D2ULL, 0x3E209020B3CC0739ULL, 0x33E10E75AD6B7615ULL
        },
        {
            0x103EC4AD582F924EULL, 0x803C24FB3D655A87ULL, 0xE82738FE0CF821CCULL, 0x6E5EC000F11EFB6BULL, 
            0x41A04C4B5963C0A8ULL, 0x89F82BF0BE15A6B4ULL, 0x1523CFEC2F9EC7C0ULL, 0xE8DEC7A2A45EEFFAULL, 
            0xA95C307D9825BC89ULL, 0x88F79EE4BF071E4BULL, 0x7455D038577B3D22ULL, 0x2F784393A699872BULL, 
            0x58F6AF73439AF153ULL, 0x55098334D94E6454ULL, 0x279C216231E53BE7ULL, 0xD4B347891D57012EULL, 
            0x80B6CD52C262DAA4ULL, 0x02BE83E85FD255B9ULL, 0x29B670B334582F0CULL, 0x450743D07B99D4E8ULL, 
            0xCDA0C8583683C949ULL, 0xA675277188A1B4BDULL, 0xFFC678FDD2779933ULL, 0x36619ED6750855F6ULL, 
            0x576EC6D38EDD4508ULL, 0x3D7737D2F3A739FCULL, 0xBB03073D5549DEEAULL, 0x7A4E2C27318E37E5ULL, 
            0x87A07BDA088AD21DULL, 0x706E6F0E85E3A675ULL, 0x2D816A51360A7872ULL, 0x66C7866BB2F6A2CCULL
        },
        {
            0xF860033639F99E4BULL, 0x46C0174F6082339AULL, 0x684B20D71DFE14E4ULL, 0x11C0A9CCC4EBC642ULL, 
            0xDAC87FEA710FC7DEULL, 0xECFCD4B1BE8038D0ULL, 0xA1480DBDD4FCBE9BULL, 0xEC73D2B09E824260ULL, 
            0xF8546682674D3F74ULL, 0x81BFCE681019AF38ULL, 0x1039B1823F366FB5ULL, 0x8F8734DB50A013A6ULL, 
            0x0AAE2DC2B62A5056ULL, 0x8777EDEB05A5A46AULL, 0x833649A49180CFCFULL, 0x7E57666153254B0EULL, 
            0xA07A2FB9D95445D0ULL, 0x3ED40EC77216B3D2ULL, 0xD3F4AC8195B0A487ULL, 0x51609371F032002FULL, 
            0x6ABA39E03F5D573FULL, 0x5AD1E3E37E04E034ULL, 0x9948A846385B16BFULL, 0x29B61624DD703F69ULL, 
            0x590A63C6BF7B2A10ULL, 0x41CC2BA2EBACA7C9ULL, 0xF8F13202420A1B58ULL, 0x0A242677B5182379ULL, 
            0x8613EDA7A16D8C30ULL, 0xFF2E513BA9EA0011ULL, 0xD8557CFBE6BBE0C7ULL, 0xFE20975718ADAF95ULL
        },
        {
            0x36BE28EE011C120EULL, 0x6F8F5731325CCA6BULL, 0x8FFC237F97DF5323ULL, 0x34B16DE9BFB3AD2EULL, 
            0x4B5C7CA87CD9553EULL, 0x141F143C88101BA6ULL, 0x466EC568F868CE8BULL, 0xAC0E9FADD43F5B45ULL, 
            0xBF47F7C6B3D0E475ULL, 0x17544C7FD4E47ED6ULL, 0xE3F4FF8E6EA122C4ULL, 0x6B28A983FD014AFEULL, 
            0x5E6F6B67782088ADULL, 0x9BF528AA936133CEULL, 0xBB12D6D7853BED38ULL, 0xFC801566275156BEULL, 
            0x001624AA6E0CF18CULL, 0x78CA4746A12E2CCBULL, 0xD95E3721817FA0F9ULL, 0xD49898C53F599C20ULL, 
            0x8E1A4EC6133324DDULL, 0x9CCD824C924F957EULL, 0x0B7DEA156786638AULL, 0xC217A3419018A8CAULL, 
            0x6CEE6D1D14702FCFULL, 0x1CBE63A484984707ULL, 0x05B1FBA2C082CCC5ULL, 0x98D519772CE6F74FULL, 
            0x83F13C8E94E7CB7FULL, 0x0F56E4B1CA246915ULL, 0xC88A34E5EAD0CAF9ULL, 0xCA264D7D5C4F8BE2ULL
        },
        {
            0x99D3C2F052C7A278ULL, 0xDB24716722DA296EULL, 0xAF81E48B13645AD5ULL, 0xE5127411D9722707ULL, 
            0xF1E7E2189D512431ULL, 0xC0BDAF972A475EB7ULL, 0x9361CB59BBC1E46FULL, 0x082DE218B998D0C8ULL, 
            0x974A3A0BEFEE0005ULL, 0x9231A15D6EB63162ULL, 0x2D12D8DED25E1AFBULL, 0x22C93262A7640FCDULL, 
            0x5D16260476DF856EULL, 0xEA00B6D9F10A3B48ULL, 0x774070C11B15D80CULL, 0xE9BC533386060855ULL, 
            0x7E985BD96245C5CFULL, 0xA625519E9B926075ULL, 0xFF2DCA5C3469D4E2ULL, 0xF90CAB67C825076AULL, 
            0xD78D8FD28854E53BULL, 0x7E003918608E0703ULL, 0xA5B2A35FCF5FA6BCULL, 0x6A3C4185E045E71DULL, 
            0x05DC40BA4224583BULL, 0x74FB9CE612E55CCDULL, 0x7470C4D33D02005AULL, 0x02BCDCD2A8976CDFULL, 
            0xD2B18FF01BDF130FULL, 0xF506D038CC7BC0FBULL, 0xBF9A7D6ED8CEF36FULL, 0x9D3C52234FC2048FULL
        },
        {
            0xCE0DBAAC2D233174ULL, 0x30041992268B3530ULL, 0xA4D69DF588CBF1BEULL, 0x4805DEA7E968CEB5ULL, 
            0x2244D97163F01FF4ULL, 0x229F066DC0ADF846ULL, 0xCC639460EBE0EC1BULL, 0xF8F63CB5D4EA9EE4ULL, 
            0xA9C34374A36DEB36ULL, 0x19E9B761A31DE436ULL, 0x92305020F1D8E9F4ULL, 0xE741E3C344162FB3ULL, 
            0xF3D096698330AE5DULL, 0x1328C2A61AD42F45ULL, 0x153F567F76743342ULL, 0x578B0CC448734749ULL, 
            0x528D4BAB58212DCFULL, 0x4FF03F7DA9705A63ULL, 0x1E237A7FA39499D8ULL, 0x3C2DFB1FC1F78256ULL, 
            0x3D2EDBB0EEFFC95AULL, 0x5419C7AED6AFA95EULL, 0xDE159A21BCCE0A3CULL, 0xB2BDAE334212947AULL, 
            0x32FBC7BCD82F7FA8ULL, 0x334F25BA25B5CA30ULL, 0xDBEB93F6018E7096ULL, 0xE2EF4328A8A16492ULL, 
            0x1191A2CB5724107DULL, 0x310303BE6EACB1F5ULL, 0x85D112A14FBF2340ULL, 0x971CFC4A10CB88E2ULL
        }
    },
    {
        {
            0x058FD4CC1860E5A1ULL, 0xFDFB645310F4680DULL, 0xBA0096033A358AC2ULL, 0x101A4C17062939A1ULL, 
            0xDF489AC580E0BE14ULL, 0xF1FA447B0597AFBCULL, 0xB0E40AC9C04D7C76ULL, 0x47C5EA6D5C680FAAULL, 
            0xF44A8192037A7524ULL, 0x68E0B0AD889760A0ULL, 0x530C989898545184ULL, 0x204E394F443EC0E6ULL, 
            0xB658C05DD21ED0B3ULL, 0xCCE0AD71148B3E75ULL, 0x03EC3EEDC37B49E8ULL, 0xCE38454895536975ULL, 
            0x78888B70BE5933B9ULL, 0x9A7F4E88326C0B89ULL, 0x014F71BC9B7ADD26ULL, 0xBA25AEC749B8E4A9ULL, 
            0xD11FB1DC920B238FULL, 0x498F501A984D6C8AULL, 0x16BEB494F8A564D0ULL, 0xB550597A40BDE79AULL, 
            0x1419FAC603223CF7ULL, 0x9D19AA2D45A2AD96ULL, 0x9389594BB4731673ULL, 0x96318F40E6617241ULL, 
            0x3DDA59DA2DA6F62DULL, 0x734A9795E7CA30FAULL, 0xDF5194D511E46BC5ULL, 0xBD794CF258CB676CULL
        },
        {
            0xD9B3C9C7F9AEA04BULL, 0xE446D5C3F06250D1ULL, 0x6355E65AD99881F6ULL, 0x72CEC4E7307891EAULL, 
            0xEA09100EE6B46042ULL, 0x84A6E40A4D0000F1ULL, 0x6E7D389A1E8CBA41ULL, 0x22FA6EF268E364ABULL, 
            0xBD8D8ED6AD705984ULL, 0xADE2323EE4D8EDEBULL, 0x2C1204DF13720699ULL, 0xA676D7B76A8CA837ULL, 
            0x9AC7A6BFF0A1EA2BULL, 0x15684C32A4D5B95FULL, 0x3D904F488E72E8D6ULL, 0xCE5273CA2A8688C0ULL, 
            0x95D0B2204898D224ULL, 0x0B50F789967F3A3CULL, 0x3D7E534A49BC67D0ULL, 0x87681826B9BA0B08ULL, 
            0xDDB1DD05B9015909ULL, 0x3928D7FF8B3CE484ULL, 0xE9630BE2E9F054A3ULL, 0x292DF501303B6E30ULL, 
            0x703BC03A39EDAE83ULL, 0xB2D724194B762839ULL, 0x5A869DA1894C9E68ULL, 0xCF9FF53A2F739635ULL, 
            0xE27DED7F7FB3D159ULL, 0x70CF135C604A2D34ULL, 0x2086AD4F4E60784FULL, 0x65B8EF300E6C688CULL
        },
        {
            0x00EB88E6534AE49AULL, 0x6CA6295102B05EB4ULL, 0xE76084EF00D8516FULL, 0xFF1C10D6D2D6880AULL, 
            0x686EFED3ABA28CB2ULL, 0xD838CA0E6DF0A000ULL, 0x774FDCBB065DE546ULL, 0xB7825417B651C03CULL, 
            0x1EB0CB583414D676ULL, 0x8B8984BD440B876DULL, 0xBDD955C23CA09686ULL, 0x9BBF38DC35194A64ULL, 
            0x0481A638AA9C10C8ULL, 0x7D53A51D7B5D39C3ULL, 0x74CE9BE78BC7F029ULL, 0x770B5D3624A7165DULL, 
            0x8EDB54AA369D3B2AULL, 0x346E38312567EFD6ULL, 0x4B19B8D2478B687AULL, 0xE9274B562A05891EULL, 
            0x4DCC6D8DA6FAC062ULL, 0x7A898F53053E60AAULL, 0x7347E9E0E3DF2397ULL, 0x3FE54A9908FA1BB6ULL, 
            0x4752ED08D5B06556ULL, 0x18EBC8BCE687BC92ULL, 0x18EE97BAF1486FE4ULL, 0xD01BF6FF8FACD314ULL, 
            0xA609C636BB049EBFULL, 0x71507E0DC4E3EA98ULL, 0x68AEC7921D7AC31DULL, 0x54D86F38291FB08DULL
        },
        {
            0x4E6FB5DC4FE547CFULL, 0xC2E5BE905BAD6DFDULL, 0x4690969C407E8658ULL, 0x0EF13FA2B6A6730CULL, 
            0x94FE8AE50A92CED5ULL, 0x25883E07C0D35A73ULL, 0x93D427AAF9163731ULL, 0xF783B37E206DA72EULL, 
            0x8321301F3AC45C52ULL, 0x94A7B3659AD0E4A4ULL, 0x028B5FDA0316A857ULL, 0x9D234A6BEAE0C541ULL, 
            0xBF28C72D6DFBA9FFULL, 0x8FCBEA1137F45DD0ULL, 0xC0EFAD5D7E0FDCB7ULL, 0xBF54CC231C0912F3ULL, 
            0xA5755EE67E917A32ULL, 0x369DABFD277B17A9ULL, 0x487862781E7DFED4ULL, 0x83C9293774A493ADULL, 
            0x1FFD36AC024011ECULL, 0x7FF121050712D7A2ULL, 0x584319099AA9B317ULL, 0xACC258E88193EE83ULL, 
            0x48F4A22E73A84C1EULL, 0x935CB6A3E243FBDBULL, 0xD47ED3E7B3739B7FULL, 0x92F5B62E06619FA8ULL, 
            0x290FBF407CA4FD91ULL, 0x9DCEE25C81A28D1FULL, 0x5F15CE25E2BABCFAULL, 0x50459F6FFB6DF68DULL
        },
        {
            0x408F395FF3F345C4ULL, 0xC178D750933511B7ULL, 0x65A1B2AA8B5ACBFEULL, 0x5E33B5F8CEEC747EULL, 
            0xB43EBF2E49104F16ULL, 0xF9A22935490A3936ULL, 0x962FFAA76D48C662ULL, 0x67CE8D5739372346ULL, 
            0xD2F9CAEF10B3E341ULL, 0xF7B4848DB255A0CDULL, 0x7FAE3C84E48A5C19ULL, 0x42D7797BD6EEE24BULL, 
            0x8A0AD77E618CEB01ULL, 0x70744241FB5A399DULL, 0x9B0D354A168F5D75ULL, 0xA680F6EB364DFCA7ULL, 
            0xFFAE51ED4F1E935AULL, 0xC8FE492762A407EDULL, 0x797E6953058E558DULL, 0x6058196C4F4FB5D7ULL, 
            0xDFF3EB489A9C8641ULL, 0x3284181DE9017D1AULL, 0xFEBD71182B528FA6ULL, 0xACB7E0CABB4DD0D2ULL, 
            0x1EECBEFED6173123ULL, 0x30A9BB75C63307C1ULL, 0xCD03F0C318F2FE11ULL, 0xD01A20872AAAED26ULL, 
            0xE9098ADBCCF78481ULL, 0xD3FBC19BCFD73392ULL, 0x485499C00EAA15F3ULL, 0xE3BC7503C09A6CA9ULL
        },
        {
            0x70488924F81C580DULL, 0x30F0E86ACCCAD161ULL, 0x567FA060CB4636ADULL, 0xACD8293AD407068BULL, 
            0x8DA2256E87294D4CULL, 0x440B0CDA8313EB9BULL, 0xC7914EECF2DC8E85ULL, 0x19D2792A8A28FBFDULL, 
            0xCCEA583412463C0FULL, 0x46D45C7E8EC4BD90ULL, 0x07A2100F6F4E11A6ULL, 0x917F335F1FE56B45ULL, 
            0x07944D0D014E48A5ULL, 0x44FEF232B2F239B5ULL, 0xEE1F882D25AA7993ULL, 0x502EC455E3702B07ULL, 
            0x4E53AB6B29D460A2ULL, 0x24BC9B05840321C5ULL, 0xC13BA2321F4B85AFULL, 0x0AFDCE5DD69F4A7BULL, 
            0x72E7F33FBCCD4FC0ULL, 0xB270FFD8435B5E90ULL, 0x1323CDE6123D0B99ULL, 0xA74CC80CD5A494D0ULL, 
            0x2BBA01EFCB4E1E1EULL, 0xF4AF1E7A67601359ULL, 0xEBF790DB06AB1792ULL, 0x92158CD3395DF950ULL, 
            0xA8C43817B337997BULL, 0x36D393BC85F2C9C1ULL, 0x74B728C24065B59EULL, 0xFFD147B4A0CB2A9CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Athebyne::kPhaseCConstants = {
    0x0F0E42757433A5CCULL,
    0xC654EEF7AF52ABF5ULL,
    0x5DD536462FB82176ULL,
    0x0F0E42757433A5CCULL,
    0xC654EEF7AF52ABF5ULL,
    0x5DD536462FB82176ULL,
    0x7C11308217C907E8ULL,
    0x7C7C7D7A11C5FD82ULL,
    0xE6,
    0x54,
    0xBF,
    0xF7,
    0x8D,
    0x7B,
    0x14,
    0xFB
};

const TwistDomainSaltSet TwistExpander_Athebyne::kPhaseDSalts = {
    {
        {
            0x9785A87FFE587447ULL, 0xC8667281A6500F07ULL, 0x56259209DC0AA794ULL, 0x71FFF2C1A3FBAC1DULL, 
            0xC113E7D9FC7F8FA9ULL, 0x944F3BADBA14F314ULL, 0x308447C61CC84CEAULL, 0x8ABEBCCDEF27515AULL, 
            0x332CF071378B9FEBULL, 0xEAD0F3AB004A5E92ULL, 0xEA4B2690745FF3BDULL, 0x263F453DD5149199ULL, 
            0xF552BF84BAE72573ULL, 0xF818E9E4EF23E31CULL, 0xDAC40B16831E5462ULL, 0x52F8CD8901E77CB6ULL, 
            0x00ED80F385A2CEF9ULL, 0xA5DF7AF8AF117510ULL, 0xF1A9E3EBB5A57E84ULL, 0xE47862D9F763A983ULL, 
            0x86FDB1FEDE9E3EFBULL, 0xD448D691AF251679ULL, 0x53E167C0EABB027AULL, 0x5AA2B411777EDA81ULL, 
            0x0F14C2E8D0431AD6ULL, 0x35AB60C45C8F8517ULL, 0xD4D25624A01ADB80ULL, 0xDA71E537267608C9ULL, 
            0xAA0EE51367350C07ULL, 0x6F57E8870322FD92ULL, 0x3DF1E04A62B33B66ULL, 0x91F067827D5FEADBULL
        },
        {
            0x9F3F1AD6D675CDBBULL, 0xDCE4EC6D09496CBAULL, 0xEE51F53CF406E0B2ULL, 0x482920CADD4A101DULL, 
            0xD78AEC06E67E061CULL, 0x51F33AEB81760440ULL, 0xA95E3631D97872A8ULL, 0x978B53903CC3CBD0ULL, 
            0x9E91F3F355DE618FULL, 0x3A0E38EF7CF230E0ULL, 0xA222E0B1BC34F7BDULL, 0xDE9B53B47ECC46B1ULL, 
            0x9DCE83F2A9B54CD3ULL, 0xA69F1BE71210358DULL, 0x385BB59809A3C7B1ULL, 0xCE1A65A36A6154FDULL, 
            0xAC69654C0D06353EULL, 0x76FAA5A2EF423874ULL, 0x09C3AF3B759C2761ULL, 0xB039F8FA0C47DC92ULL, 
            0xAAE92F926F095881ULL, 0xCE27DF0AA8CBBCFFULL, 0x9F6B19D280CB2A73ULL, 0xE02E459783C830DFULL, 
            0x702EDA8A77164672ULL, 0xF2151ACC5680FA11ULL, 0x4DD62F91EEB18306ULL, 0xA865D956C3EF48CEULL, 
            0xD998EBBB774E4AD3ULL, 0x95E17ACD6A2E5ECEULL, 0xA3B197AA6C4EDB5FULL, 0xC4430E70F7209724ULL
        },
        {
            0x8879B56A37E2E1B9ULL, 0xC0D9ABD4E8DD3A43ULL, 0x4734637FE3CFB9DBULL, 0x6426967B7ADBF981ULL, 
            0xAF60427F19A65921ULL, 0x634446C3950832B9ULL, 0xE85319B2D935B381ULL, 0xADAFB1E371C28307ULL, 
            0xDFB460E236AA263EULL, 0x855B7BAD3A6156B9ULL, 0xD85C9C07E0FD220FULL, 0x1DF4E4043F3AFF31ULL, 
            0xEBB4336254C4B982ULL, 0x338DC44B154742D0ULL, 0x8848B12228528C8AULL, 0x1D78BC163CDC11C4ULL, 
            0xB4EE2B44E7F4848FULL, 0x356F5D2E7F95A796ULL, 0x1A698A179F870389ULL, 0x21EEA7CFA5031EF3ULL, 
            0x635F9BEE84CEBB69ULL, 0xEC219C38B8BCD749ULL, 0x8C5731C81D2F8888ULL, 0x08F0B6EA0EA627ECULL, 
            0xE7F589A9ED5B30C0ULL, 0x03819F5AE6A2400BULL, 0x9914252B9939F82CULL, 0xBE34E8448B00B44BULL, 
            0xC973A9858799B38EULL, 0xFB0547B7192D6686ULL, 0x92E2BA8B8DAB02AEULL, 0x9B1D53923076B4C9ULL
        },
        {
            0x456C7BB097B93EFEULL, 0xEE72B5A79AEB8800ULL, 0xABFC3842821875E4ULL, 0x9FDDC8D22E02FD96ULL, 
            0xDDE994CCAF1DA96AULL, 0x351031206CCC67ABULL, 0x3B7960B5217B6E0EULL, 0x061897ACC8DC2EF2ULL, 
            0x0229C3169AFE26CAULL, 0xD75768544A02D6FFULL, 0xE8B4E638C0785093ULL, 0x6E77F8FA7ABB24E6ULL, 
            0x7EC2405E33306FADULL, 0x5C4C695A774C8206ULL, 0x95A786C270D4BDF4ULL, 0x609A194F32DCC1EDULL, 
            0xAD1B187C3E19D9EEULL, 0x5EBA39FA640369C5ULL, 0x78E088D4342D141FULL, 0x1DC635BA79B3C4EDULL, 
            0x8EB3B3C72968BC70ULL, 0x0B05AFB810549C9BULL, 0x154FBCC17309FC32ULL, 0xCEB6D5F0619CB092ULL, 
            0x616B4A1C06F9C756ULL, 0xFE8ABC45AFDDD6A6ULL, 0xF233649E09812ED0ULL, 0x099E8F0D9741EEBBULL, 
            0x160465F9C0ED74FFULL, 0xA5A00444FC00FFEAULL, 0x7469E1A11DD949A2ULL, 0x38007065864B810CULL
        },
        {
            0xD3F566B9393BF9CDULL, 0x00A5BAF200FF4326ULL, 0x47EA92C6D10FC5A6ULL, 0x8D15BFBBAC11F562ULL, 
            0x2C6AA52BE161A254ULL, 0x33516D213C16FB7DULL, 0xFE44F7A61E54A0F5ULL, 0x0502A2110083927CULL, 
            0xC4B84270B5E78E9CULL, 0xC1DE00614E3FA19FULL, 0x02F58417FE5FC9F4ULL, 0x1B1292414D5E2E53ULL, 
            0xFBB3470481E6FA75ULL, 0x2B1E0377C939B2DFULL, 0x6AB749D39A206025ULL, 0x0EDDC8E04E859E97ULL, 
            0x2D33ABBF98EDCE76ULL, 0x95719B508D6B9CF1ULL, 0x46DD9B75715ED1F8ULL, 0xB330EEBADE52AD8CULL, 
            0x3F6363C23813B20EULL, 0x8DC1A1193773F99CULL, 0x7431F1F2CDE497C7ULL, 0xD157DD00536F343AULL, 
            0x00EFAA8DCB16307DULL, 0xC87F9F2EAE039B99ULL, 0xBFE5C1014E664546ULL, 0x60DAA13C136C910BULL, 
            0xA738BC8DAAE201FFULL, 0xB354E17C79F4698AULL, 0x812626041C31AAFDULL, 0x95F03D1771E9346FULL
        },
        {
            0x3E308956C3ECE61BULL, 0xAABF31CF1289D086ULL, 0xDE95D06976EDE354ULL, 0xF5B1A9A49DC2D63BULL, 
            0x2B411C4E26B55F8AULL, 0x6CD0478E475BD475ULL, 0x4715A5F34AC2FBABULL, 0xC08403F26C8AB5E4ULL, 
            0xF1E36157221048C4ULL, 0x0AAD8B705F74A951ULL, 0x341FE3E6DCC3E196ULL, 0x181EF7E1CBF28BF3ULL, 
            0x24A3C6E366B81C5BULL, 0x665D0682967999C0ULL, 0xF36634C8BD6DF5BCULL, 0xB1B313F2ABC1812CULL, 
            0xCAE9CB9D4413116DULL, 0xB40BF7F827633FF4ULL, 0xFE57782C1CA162E1ULL, 0x94EA3B98DD06CEC4ULL, 
            0xAFB2F84373B6A5C6ULL, 0x5D3080CEF8A93A62ULL, 0x4750530F6830844BULL, 0xE64ECB147DD449D5ULL, 
            0xFBB8CC6289F6E6B2ULL, 0xB597BB5D715539D8ULL, 0x886C2C219227AEFAULL, 0x5673A302C1C7A365ULL, 
            0x13BA7C150FC6A863ULL, 0xA7250FD271D7A833ULL, 0xEAB3CA4695B9945BULL, 0xBEAAE527BF20F514ULL
        }
    },
    {
        {
            0x1E0716748AD5FF5FULL, 0xA95C0783D2D4E7C2ULL, 0x7DEDD6A24FCD6545ULL, 0x069AD652B7D33369ULL, 
            0x5E04A7ACB7B3A713ULL, 0xF042B4955D847CF1ULL, 0xE554BEEE33B52660ULL, 0x8E3EEEE0A337B9DDULL, 
            0x1E9A30798CEB6F9AULL, 0x04BB8DB156E1D6C8ULL, 0xA0FCEE3EC14E5FE5ULL, 0x8207A8171AC7C538ULL, 
            0x5B2944BD1905659EULL, 0xABAEC4CD0982D2C7ULL, 0x70D3E03CA4E35379ULL, 0x09C61D21A7B1B41EULL, 
            0x14C1434A2F10B5A7ULL, 0x7D3F77BD8D1E3C90ULL, 0xD4E6EC4430B01E34ULL, 0xC59F65A6DA8F129DULL, 
            0x5F9B428C4FD3C88FULL, 0xB97B2CB534037D43ULL, 0x4A057C3D3C14AEB7ULL, 0xD89B3DBE26C4DE13ULL, 
            0xB859AAB4BABA4909ULL, 0x39312EC981FCFEACULL, 0xF2E186A028B80201ULL, 0xACDB7C90F1B22839ULL, 
            0x65BE1C11F88E1F1CULL, 0x1E49DE416D08F4F1ULL, 0x26790084EF1A0A1FULL, 0xCC49028EFFE20EC3ULL
        },
        {
            0x031F88CB40CD81B9ULL, 0x692CCA6BBFA733A1ULL, 0xC7791F13FAFB18E2ULL, 0xE9A29CA1905FE3B6ULL, 
            0xE2D384CFB6EEF0A4ULL, 0x89CED3BBFCF69FADULL, 0x0A0B482F5EA84612ULL, 0xA88C31A3C8428613ULL, 
            0xACD692AD3CE1C1A5ULL, 0x7DFD34A64E6AC86DULL, 0xBE57D6BD60B02E02ULL, 0x25968695BA05BFA1ULL, 
            0xB755E01AFDC83DF3ULL, 0xACA904811CE3F476ULL, 0xE0FA314B7CB56B89ULL, 0xB259A5272E4F970BULL, 
            0xA5881CE098174177ULL, 0xDC4626BF76D9D4D4ULL, 0x4E8EF1BD8A6B249FULL, 0xB66B035FF8A4E185ULL, 
            0x6C1827C5BB188641ULL, 0xBABE34E28CB95CC6ULL, 0x969CB273E04730F3ULL, 0xBE3E91C8CD6AB0B8ULL, 
            0x7EE299CD1085E3B5ULL, 0x7C29B77838338129ULL, 0x83F71A5600B0E0BCULL, 0x270617F5F260631BULL, 
            0x804BDF20E1EA6EF0ULL, 0x04E030BE1EC073BCULL, 0xA417033B609245C6ULL, 0x32637889375F5064ULL
        },
        {
            0x6F4559E5A957AB65ULL, 0xE7D64F1CC019B570ULL, 0x01F61719F1CFB238ULL, 0x33697A861E9CA890ULL, 
            0xA4A7A7AF29AF9790ULL, 0x395487E4462F5BBBULL, 0x08191915D682D32DULL, 0xF0B17BC18B02BE00ULL, 
            0xFB2331E676E461C6ULL, 0x3E8A6DFDF0C82442ULL, 0x88C833EA91D15016ULL, 0xD125AF03AE0D8ACAULL, 
            0x4B1058BDD45CB390ULL, 0xABCCCE54CF5F95B1ULL, 0xFE1DB1B1DFEE6DE5ULL, 0x6E49EC383061D95CULL, 
            0x333985D6167446DCULL, 0x694BDF3865155B27ULL, 0x2CAC9E363D605554ULL, 0x7DC7A3696431F75DULL, 
            0x948502098F8DB95CULL, 0xE1D6FA67D468EA14ULL, 0xF1378B429CB14586ULL, 0xB6094296E5245956ULL, 
            0x6F8C485E3253E6A5ULL, 0x27770D72D2C53D0CULL, 0x28C5B805E9403AF1ULL, 0xC612982D62CA35D5ULL, 
            0xD0ABD6662B901C8BULL, 0x97832107F03E81F6ULL, 0x284A8EC20FD9A8D8ULL, 0xB1AFAA186A190FC1ULL
        },
        {
            0x0F2A840BCA5891EDULL, 0x0608B95E755489E2ULL, 0x5CD8E3450483C2B7ULL, 0x1626D02872BBD3C6ULL, 
            0x75D889B9C79B4712ULL, 0xA41E95A2E1ECE12BULL, 0xAB085F89CBC40DFAULL, 0xA8E34B9AAEBE0134ULL, 
            0x514F36058D5F03D9ULL, 0x6FCAD37CD3DBFA72ULL, 0x817F6C3E0ED8DA2CULL, 0xF39C75140E2A3DF0ULL, 
            0xDA8A55CCEC769979ULL, 0xEE50997A8015B7A2ULL, 0x8F4104B20D4785CFULL, 0x6BF63DA110BC6B5BULL, 
            0x9EF8950FA661B515ULL, 0x455B7301D71660B8ULL, 0x8533E567D5EF5719ULL, 0x5017B986E997507CULL, 
            0x4D1C6CBFE5AA4E0CULL, 0x789583CA7DAAAF93ULL, 0x058B41C7BC7290CDULL, 0xD54AE3752F4837E9ULL, 
            0x2E1E622798311846ULL, 0xC4AF775D814CC882ULL, 0x799C8AC1B40DD52AULL, 0x52E23F6C72D9FA5AULL, 
            0xF15BF49623F09518ULL, 0xF47AC42A0DEDBEB8ULL, 0xC4F94D6D351C899DULL, 0x6D9CA600BC6DCB2BULL
        },
        {
            0xB65EB45E2EF0C2E3ULL, 0x2168A3F89CBF10BDULL, 0x41DBCAD4649111B6ULL, 0xF19EBD38CF9DE357ULL, 
            0x635A3A7A3D06159FULL, 0xBEDBE69A0440A1CEULL, 0x17115894E088D970ULL, 0xF3AF3A4CF0EB914FULL, 
            0xA5BE916C3CA0AF9BULL, 0xA5F774B96B8EC7E6ULL, 0xD3DE3B185CFD4B05ULL, 0x578D9E904DEC3764ULL, 
            0x9DC8E9D0F34EDBF8ULL, 0xABC797B77C1DE7D1ULL, 0x53DF1614DA07967AULL, 0x08D0D9E4ACE82DBBULL, 
            0xCE06FBB21C797252ULL, 0x2BA1AB3D450F4A54ULL, 0xD21E62A40CC05ED4ULL, 0x8CE3A2FC45278BC5ULL, 
            0x966AF3BDDD5ABA29ULL, 0x6CE00CF71A4291CCULL, 0x19F616E2C60C5A0DULL, 0xEEA3CA85F078190AULL, 
            0x08C286AA183EEED6ULL, 0x61C2C91BCA4F310DULL, 0xC68DD46C74F3429EULL, 0x19EF6BB02613A744ULL, 
            0xF07C24849433E561ULL, 0xEDC37A683F3A2FE7ULL, 0x843F97172177475AULL, 0x7748AAC11EAA647DULL
        },
        {
            0xB5129AA043E6C802ULL, 0x2E5DAD40835082C1ULL, 0xA769CDBB31CEE369ULL, 0x9521D3B46D1ED0A4ULL, 
            0x508BA08F864E9511ULL, 0x037A7D106B349DCEULL, 0xA52A3DD27C4B415DULL, 0xEE0948B1C4D0E3EDULL, 
            0x759EC76977A005C3ULL, 0x031512D3B02A38C4ULL, 0x1F4C03D0DCD6181CULL, 0x8193AB122027345EULL, 
            0xCA289094E4C5B125ULL, 0xD530B01481777EE0ULL, 0x4993040739E7D694ULL, 0x993A08A6941F3ABEULL, 
            0x67C292A16B90F2D2ULL, 0xB15CF7830160E748ULL, 0x740421D03FD5EBF3ULL, 0x5B90E1475F355CDDULL, 
            0xBD51F4B276326AC1ULL, 0x8FC5305053093CF9ULL, 0xACCACF144593566AULL, 0x291D89AC62E9D19AULL, 
            0xAEB9DE702B2F316BULL, 0xEDD6E36FA24EF5DAULL, 0x5B90E71EB01E9719ULL, 0x6CC5CBDAAE161475ULL, 
            0x14EB2B151BEA70E5ULL, 0x782C8107B66943B7ULL, 0x10F35E189AA79CE3ULL, 0x4F587AFA5B6FD3DDULL
        }
    },
    {
        {
            0x15603321E9B366C8ULL, 0x6E519424E8BCA6C1ULL, 0xBFD0460B8C0DEBFBULL, 0x122FCFAA4ADD46B3ULL, 
            0x6ABFD7C6FC65976CULL, 0xAFE2BE492A3E94FAULL, 0xD47F179033B7F003ULL, 0xAA1BCAD8C878B352ULL, 
            0xFD3535111E499353ULL, 0x0255998E9F31812DULL, 0x347580CEE6F1E0C8ULL, 0xE5B5786EC92F9505ULL, 
            0xE81B97977D4B7F3CULL, 0x597C99164244A466ULL, 0x651D794D79536B6FULL, 0x5EADA2E5AD99BE31ULL, 
            0x50F1400DAEBC2689ULL, 0xDBCAB3BC7FAC3032ULL, 0x2A3FD4DB0E5BBBC8ULL, 0x5924E7AA1211A223ULL, 
            0xCEAACE12DFC6455AULL, 0xF01593CAE1351CD9ULL, 0x5B613E43747964A6ULL, 0x8C769700D668B341ULL, 
            0x7A341C4386F46BEBULL, 0x87A18292B1D00517ULL, 0x15D9A4E311A3F9B3ULL, 0xAAEE3337025165E2ULL, 
            0xDBEF509E2EAE0BF5ULL, 0xB1612185D7DE5E2AULL, 0xE8812DFAF0B4A832ULL, 0x4670E76B9AEE268DULL
        },
        {
            0xBF4DA5045DED8083ULL, 0x35B2882712E3D8A7ULL, 0xE58BEED05CED5CD9ULL, 0x3335AE79852CA557ULL, 
            0xC352991DD31DEA4BULL, 0xC9E8F6BFF0DC0F2DULL, 0xBCC25CBECE668E21ULL, 0x96B6CE3F4749AE73ULL, 
            0x4641BF88B7300F49ULL, 0xF7BC28F0F568C623ULL, 0xA418243E479A0755ULL, 0x0BC9BFADF777A560ULL, 
            0xA1362251792E9EE2ULL, 0xDBC6953DD3FAF86AULL, 0xAA467C15D5F460B1ULL, 0x9DD2676FFF5215BDULL, 
            0x2B2449717B9305F1ULL, 0xA07D3C9B2F3645C7ULL, 0x38A6C0264358792CULL, 0xDC3E025988467348ULL, 
            0x1DA08ED3F881429CULL, 0x1390D8E53758ECF7ULL, 0x733DE7CA48A255F6ULL, 0xB0CC63EB38BBCF7FULL, 
            0xA274B74ECF9E09F9ULL, 0xB969D0823E162AC3ULL, 0xCE119FE46CF14B4CULL, 0x23AA126A5EF83095ULL, 
            0x2DFED9A7674C552FULL, 0x5FE1BB4EC1C192B1ULL, 0x0661DD352DCA04AFULL, 0xBCCC456E1CB2B6CAULL
        },
        {
            0xD091A37BC700D330ULL, 0x6B1BF7E19329550BULL, 0x83A5AE981C20E4CAULL, 0xA07C30EC8F8779BCULL, 
            0xA731FE26EB65B598ULL, 0xD53190A40C7B8003ULL, 0xD103706C0C283D3BULL, 0x70AAA093748DBC81ULL, 
            0xF923EB2F567217DAULL, 0xA3F31ED7D8D50A35ULL, 0xC9EDFFD681606BF7ULL, 0x451583ECD2203172ULL, 
            0xDAAA9FB522CFC5CDULL, 0x4A682222C90D8B60ULL, 0x25D60F99D5E7D385ULL, 0xCC38599C847A701DULL, 
            0x77722E4EB5CD40B0ULL, 0x45377A2323257809ULL, 0xDFAAD006568AE6B2ULL, 0xB438D732658A5471ULL, 
            0x65024E00935370C5ULL, 0x66B85B4479B1267CULL, 0xC501A43DB3970F89ULL, 0xCF4F01BE3A5EF00FULL, 
            0x8CA0DD7F4745FB8DULL, 0x12AB3D059395C246ULL, 0x28B91CF8092B977FULL, 0xCBA52A0BCB8FEFD1ULL, 
            0x840487A5218DFE44ULL, 0xE4A232E5E376EEE7ULL, 0x5B725B9F6D2C5869ULL, 0x56BBAEF91F860DB1ULL
        },
        {
            0xC1B00C4492B46F38ULL, 0x82DD7EF2ACAAF988ULL, 0x93E313519ADE1607ULL, 0x7755387BE8DC7B3CULL, 
            0xE8D7530961EB6531ULL, 0xDF26DD402F743AC9ULL, 0x41E18DA5765BDC56ULL, 0x65E9943F29C4A966ULL, 
            0xE85F356E8B490816ULL, 0xDA662803EE36387FULL, 0x59AF2A079226D254ULL, 0x5F7867F9481A3F53ULL, 
            0xC3991F80AA9D3C86ULL, 0x2DF24E35E9C6B0D3ULL, 0x9BFD903AB77CDBA5ULL, 0x4A5A99906AB1A61CULL, 
            0xEC9F67D5B9ED44F9ULL, 0x7B0121410B52A36AULL, 0xC07AB4AA244ACF5EULL, 0x65AFF44B6379AEEFULL, 
            0x31344339AC92C429ULL, 0x29C84064267D5825ULL, 0x73F3F36CCFEDF01CULL, 0xF900DEB1526C5707ULL, 
            0x42B35D43704AE0F4ULL, 0x458B02632A8835F8ULL, 0x9740506F53125F0FULL, 0x9D54939193C26D07ULL, 
            0xBFDF83B3A74A89D7ULL, 0x9E32F5D19FCF9437ULL, 0xE2D0BF2CE801847CULL, 0xCC1DAF2E495FED56ULL
        },
        {
            0xC901A68D95EC7F24ULL, 0x6DC49E6FAEEBD897ULL, 0xF188CD7F582745B0ULL, 0x0C8F2AD00C0276A3ULL, 
            0x8D7B670D6D59365BULL, 0x35A4DBE4F883CB65ULL, 0xDAF79AD75135D4DBULL, 0xED5C381DA9CCDB58ULL, 
            0x31C2872331906861ULL, 0xC3D0A07DFC9353ADULL, 0x675DAF4AAB203C65ULL, 0xC756E4FEA0A992ABULL, 
            0x2712741C3D828CEFULL, 0x7B3B4EF7DF1181BEULL, 0x7489CDBBA52EBD5DULL, 0x86B15C4DD5AA6FAEULL, 
            0xAEEB1180334F37D9ULL, 0x8DB2F65B285CAA54ULL, 0x643307A91AE97B9AULL, 0x874294D05BC29415ULL, 
            0x31E46E5C4DD31971ULL, 0x332BC7B90612E5CFULL, 0xC6FEAED56AB58F1CULL, 0x79589039456B3855ULL, 
            0xDB31367E8EB1E115ULL, 0xB217153F34288C1AULL, 0xCBFC637D0AFE3AA0ULL, 0x0C0AAC83F4174DDCULL, 
            0x943F0E551F596A14ULL, 0x830C8DEA80B0CA91ULL, 0x9896BC5A90C01607ULL, 0x5E8874276E1A58D9ULL
        },
        {
            0x9F1134862064C001ULL, 0x2618478DAE69E4B6ULL, 0x6FC915074A7C8DB2ULL, 0x3860801EB6FC6288ULL, 
            0xDAED074A8594FF54ULL, 0x6FF63A7F32C6D1FAULL, 0x73234CD759E64EA8ULL, 0xECCDF9FE235EEEE9ULL, 
            0x3B9B486C4C2C5D38ULL, 0x88CD971DAA2E5DB8ULL, 0x54392AF4F4A6859CULL, 0x481F3FAE3875674CULL, 
            0x7957D023732C3586ULL, 0xE8520111EB075402ULL, 0x654EEED25390B09EULL, 0xABEB4191EA0F957EULL, 
            0x531CEE96A4B21150ULL, 0xF5F3E0EE9A5EACC4ULL, 0xC5ED05AD82A6AF4AULL, 0x4768459D7869F798ULL, 
            0xE30D3888555B05A3ULL, 0x3B9E2D647545FEBBULL, 0x404CF762813D0F84ULL, 0x1E1AF19C1D1A3772ULL, 
            0x8EE244EABC0A2E49ULL, 0x51C0ABD8769B44E9ULL, 0xB78D32F7E91EC6FFULL, 0x64097BD85DF03BBDULL, 
            0x878BF6C4BCD13C8FULL, 0x18133CAD02A3B198ULL, 0xB59AD42CDB6EC24AULL, 0x9B7C164AED20FC7AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Athebyne::kPhaseDConstants = {
    0x8309B18253128313ULL,
    0x032488B635E4D560ULL,
    0xBB4372B3468ACC59ULL,
    0x8309B18253128313ULL,
    0x032488B635E4D560ULL,
    0xBB4372B3468ACC59ULL,
    0xC9C1D5E15D779E5BULL,
    0x4802E73A47A5238DULL,
    0xA5,
    0x5D,
    0x83,
    0x36,
    0xE8,
    0xA8,
    0x5F,
    0x39
};

