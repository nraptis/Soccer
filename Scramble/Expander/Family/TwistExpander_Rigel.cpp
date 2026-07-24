#include "TwistExpander_Rigel.hpp"
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

TwistExpander_Rigel::TwistExpander_Rigel()
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

void TwistExpander_Rigel::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF95E69DF058C5B02ULL; std::uint64_t aIngress = 0x9206B027297C7744ULL; std::uint64_t aCarry = 0xFA4936DEF6EB1BDAULL;

    std::uint64_t aWandererA = 0xEF1859ABB2F0115FULL; std::uint64_t aWandererB = 0xDD9CB04FA3BA2616ULL; std::uint64_t aWandererC = 0xFD2F180035AEC910ULL; std::uint64_t aWandererD = 0xB948398A16D3BEBAULL;
    std::uint64_t aWandererE = 0xB587E401F06EFAADULL; std::uint64_t aWandererF = 0xDEA89A704D5118A0ULL; std::uint64_t aWandererG = 0x8E7130BBB0CB002BULL; std::uint64_t aWandererH = 0xDA74625FBF0ED5BCULL;
    std::uint64_t aWandererI = 0xB8BC4F285AA06873ULL; std::uint64_t aWandererJ = 0x80F079433C0186FDULL; std::uint64_t aWandererK = 0xBFEDFA3582DE68A4ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xF438BBE18DFF981EULL;
        aCarry = 0xCD039C63058F1647ULL;
        aWandererA = 0xBA6A9D0B1628E64FULL;
        aWandererB = 0x9D3DCCB89CCA1526ULL;
        aWandererC = 0x8CD30117881964C7ULL;
        aWandererD = 0x875A4FAB7DC3F264ULL;
        aWandererE = 0xFF461C2C1090D781ULL;
        aWandererF = 0xF5CC3F04B6B4120DULL;
        aWandererG = 0xF4D3B431751606FDULL;
        aWandererH = 0xFDB4437FB0C9A6C1ULL;
        aWandererI = 0x975D6E4E3D9DFE57ULL;
        aWandererJ = 0xFCB37C362DAFBDEEULL;
        aWandererK = 0xC29F621D8733FA9FULL;
    TwistExpander_Rigel_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Rigel_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Rigel_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Rigel_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Rigel::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x9718044899A78C76ULL; std::uint64_t aIngress = 0xA13F602C8F1BDC19ULL; std::uint64_t aCarry = 0xC89870A3DA2DB8B2ULL;

    std::uint64_t aWandererA = 0x9942B1B0C92C0FD7ULL; std::uint64_t aWandererB = 0x81C6BB99859C25E6ULL; std::uint64_t aWandererC = 0xD14DD57EB96FB4CFULL; std::uint64_t aWandererD = 0xAA9E5F3A9252DC2EULL;
    std::uint64_t aWandererE = 0xF95D5C84340DCBF7ULL; std::uint64_t aWandererF = 0xE2B616FBA612282FULL; std::uint64_t aWandererG = 0xF26D0DAF993FE940ULL; std::uint64_t aWandererH = 0xF65B7D104A39D0F1ULL;
    std::uint64_t aWandererI = 0xF58B050C3EDD85FAULL; std::uint64_t aWandererJ = 0xA220A3EBCDF38DD6ULL; std::uint64_t aWandererK = 0x86F75942BFD12EC4ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xC1D2E50F2C64BACEULL;
        aCarry = 0xE763426039DD32BCULL;
        aWandererA = 0xF4183C9DA1EA25DAULL;
        aWandererB = 0xD6D0BFE00CEDEA33ULL;
        aWandererC = 0xAD34C3D71012D31BULL;
        aWandererD = 0xF1D30E7B2868F349ULL;
        aWandererE = 0xB34F5AFA80065076ULL;
        aWandererF = 0xB3E37ED09D2F6CAEULL;
        aWandererG = 0xBE42367038256A52ULL;
        aWandererH = 0xD5FAB9C095CB867EULL;
        aWandererI = 0xA090EB7F65ED9C22ULL;
        aWandererJ = 0x86DC5C32D02DB0D4ULL;
        aWandererK = 0xEE072DE8C8FF7DBEULL;
    TwistExpander_Rigel_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Rigel_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Rigel_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Rigel_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Rigel::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xCE87DB636D99CD17ULL;
    std::uint64_t aIngress = 0xAB76DC791FD3D829ULL;
    std::uint64_t aCarry = 0xC3E58CB99FF5541FULL;

    std::uint64_t aWandererA = 0xEA0475C4CB724258ULL;
    std::uint64_t aWandererB = 0xA1FB09C0445897B4ULL;
    std::uint64_t aWandererC = 0xE90244AC43F67A56ULL;
    std::uint64_t aWandererD = 0x9EA732BFD4D2F7B4ULL;
    std::uint64_t aWandererE = 0x8EC3A7630BE1C360ULL;
    std::uint64_t aWandererF = 0xA53F46E82CC8DC86ULL;
    std::uint64_t aWandererG = 0x85D74FC2F913FC64ULL;
    std::uint64_t aWandererH = 0xAF2E380CB66D199CULL;
    std::uint64_t aWandererI = 0xF2F372730192CEE7ULL;
    std::uint64_t aWandererJ = 0xA05375A319A9B8CAULL;
    std::uint64_t aWandererK = 0xBDCC1075FB5073DCULL;

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
    TwistExpander_Rigel_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Rigel_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Rigel_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Rigel_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Rigel_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Rigel_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Rigel_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Rigel_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Rigel_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Rigel_Arx::GROW_B(pWorkSpace,
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

// SmartSquash candidate 29 of 33
// Exploration cases: 100000000
// Nearest-family diversity: 914 / 1088 (84.01%)
// Total distance from earlier candidates: 26206
void TwistExpander_Rigel::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    static_assert((S_BLOCK / W_KEY) == 16, "SquashInvestToKeyBoxes expects 16 invest fragments.");
    static_assert(H_KEY == 8, "SquashInvestToKeyBoxes expects 8 key rows per box.");
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 2U), *aFragmentB = aIceLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 9U), *aFragmentD = aIceLaneD + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1242U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1244U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1494U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1557U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 9U), *aFragmentB = aIceLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 5U), *aFragmentD = aIceLaneD + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1502U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1049U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1535U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 648U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 10U), *aFragmentB = aIceLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 3U), *aFragmentD = aIceLaneD + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1671U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1301U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 543U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1420U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 5U), *aFragmentB = aIceLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 7U), *aFragmentD = aIceLaneD + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1998U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 520U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 844U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 32U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 14U), *aFragmentB = aIceLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 14U), *aFragmentD = aIceLaneD + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 896U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1851U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 565U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1412U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 15U), *aFragmentB = aIceLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 0U), *aFragmentD = aIceLaneD + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 2024U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 453U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1396U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1424U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 11U), *aFragmentB = aIceLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 2U), *aFragmentD = aIceLaneD + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 582U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1083U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 60U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 241U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 12U), *aFragmentB = aIceLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 10U), *aFragmentD = aIceLaneD + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1527U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1627U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1727U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1346U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 7U), *aFragmentB = aIceLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 6U), *aFragmentD = aIceLaneD + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1284U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1770U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1200U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1318U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 0U), *aFragmentB = aIceLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 4U), *aFragmentD = aIceLaneD + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1981U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 2035U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1920U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 619U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 13U), *aFragmentB = aIceLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 11U), *aFragmentD = aIceLaneD + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1936U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 682U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 613U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 735U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 1U), *aFragmentB = aIceLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 1U), *aFragmentD = aIceLaneD + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 145U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 387U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1942U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 399U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 3U), *aFragmentB = aIceLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 12U), *aFragmentD = aIceLaneD + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1514U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1210U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 726U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 861U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 6U), *aFragmentB = aIceLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 15U), *aFragmentD = aIceLaneD + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 298U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 210U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1167U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 147U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 8U), *aFragmentB = aIceLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 13U), *aFragmentD = aIceLaneD + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1654U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 494U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 750U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1417U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 4U), *aFragmentB = aIceLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 8U), *aFragmentD = aIceLaneD + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1931U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1089U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 474U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 450U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Rigel::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xC5C3D6251E0DFEDCULL; std::uint64_t aIngress = 0xB93BF5D7D9788041ULL; std::uint64_t aCarry = 0xA771F2B5669E9804ULL;

    std::uint64_t aWandererA = 0xE69C3CEAAEB3C230ULL; std::uint64_t aWandererB = 0xEB4456CD3D827C41ULL; std::uint64_t aWandererC = 0x8567C0C11D4BA19CULL; std::uint64_t aWandererD = 0xF13BDAB342870CEAULL;
    std::uint64_t aWandererE = 0xCD9AE478F7F56B38ULL; std::uint64_t aWandererF = 0xF4905B6B35E6AC39ULL; std::uint64_t aWandererG = 0xBD20EAE39FD941AAULL; std::uint64_t aWandererH = 0xB2863731292C9A53ULL;
    std::uint64_t aWandererI = 0xD0ED277CB0B6586CULL; std::uint64_t aWandererJ = 0xBDE6D213D951550CULL; std::uint64_t aWandererK = 0xEDDB0D5A8E33C8D3ULL;

    // [seed]
        aPrevious = 0xAA3CB353EB0556F5ULL;
        aCarry = 0x8FC29AE5ACF0107CULL;
        aWandererA = 0xAC9B94ADDDBB4967ULL;
        aWandererB = 0xC6845F211B36CA12ULL;
        aWandererC = 0x99EECB5938D9C435ULL;
        aWandererD = 0xA0E3E4F45C53DB3CULL;
        aWandererE = 0xE66F1E065B5E0B68ULL;
        aWandererF = 0xF001C385EE2D5C28ULL;
        aWandererG = 0x94B963ED17C37459ULL;
        aWandererH = 0xE2879656241088B1ULL;
        aWandererI = 0xF5F5575F1D8F00DAULL;
        aWandererJ = 0x82EB839C10EE54ABULL;
        aWandererK = 0x8099D60F27AFD714ULL;
    TwistExpander_Rigel_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Rigel_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Rigel_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Rigel_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Rigel_Arx::Twist_E(pWorkSpace,
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
    TwistExpander_Rigel_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Rigel_Arx::GROW_B(pWorkSpace,
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

// GrowA candidate 29 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 15145; nearest pair: 477 / 674
void TwistExpander_Rigel::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6236U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1791U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3260U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3490U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6458U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7846U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4772U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3831U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7557U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4452U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2003U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7378U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6122U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 971U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4191U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7112U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 174U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 230U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 25U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1948U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1801U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 337U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1901U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 970U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1352U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 184U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1493U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1617U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1259U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1156U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 981U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 136U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 217U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 949U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1784U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1044U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
}

// GrowB candidate 29 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 15165; nearest pair: 481 / 674
void TwistExpander_Rigel::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4445U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8053U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7865U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7806U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 207U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2175U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6901U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4201U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1240U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 286U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6588U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 247U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5934U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3494U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7953U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4543U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 718U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1143U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2041U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 231U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 237U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1865U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1593U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 680U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 228U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 397U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1922U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 915U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1498U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 190U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1733U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1872U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 641U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1421U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1451U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
}

const TwistDomainSaltSet TwistExpander_Rigel::kPhaseASalts = {
    {
        {
            0x9EA9455A9F316BA0ULL, 0x00BC366DC309E9B7ULL, 0xF1FB1B33B3B6EAA9ULL, 0xF3E00DE9D7F2636DULL, 
            0x79E8F05848C9A3EBULL, 0xCDC6BC47537940B9ULL, 0x17A4342DEE37EFB4ULL, 0x620E242D53A1A12FULL, 
            0x4FE1FB518D7D6186ULL, 0x90529C744AAA6A63ULL, 0xC251E8D0ABD8BE06ULL, 0xAD6ED62623F074D7ULL, 
            0x54EEAA4B0A9290FFULL, 0x8FA187986CB978D0ULL, 0xDC511EF5D93AC116ULL, 0x84C305FE9CCECFFBULL, 
            0x5905F8EC237766F5ULL, 0xFD9FBA596A917C7FULL, 0x48AEA872EEA8F59DULL, 0x4BCCD3724E014763ULL, 
            0x3E1E7518B9067072ULL, 0x0206B5F378F800C9ULL, 0xF9E5A75EDEEADFCBULL, 0xE22BF130942FCC60ULL, 
            0xA6AF2B0FE965FA2DULL, 0xEE235167E35E8DB6ULL, 0x7BBC9AC513EA8E83ULL, 0xDBF39D535934694DULL, 
            0x1C8DCA34C97BF0ECULL, 0x58EA08901F8F10D1ULL, 0x13266D9982FBDE95ULL, 0xF40F81ED474FB0EFULL
        },
        {
            0x9BCD70A1320B5BD6ULL, 0xAD6C70D2E0E1F01EULL, 0x26BD21C9D99F4C52ULL, 0x26272B46314DAF15ULL, 
            0x2EB3E42AB19E0AC0ULL, 0x4F4E3FC8E6F996ECULL, 0xE55EF0139E0530BFULL, 0x3E545F96F60889B9ULL, 
            0xC4F764950BD65701ULL, 0xC3BFD8932EAB5526ULL, 0x70795E40EA03C759ULL, 0x0459FCD62A786836ULL, 
            0x4DE902AAF984A092ULL, 0x334FC1A844D7E254ULL, 0x02279A0231A50424ULL, 0x3DD5381C90969266ULL, 
            0x657BDFA811A1D1CFULL, 0x5496360401A8642EULL, 0x0961CEE2B3996E5EULL, 0x42070F761FDA0614ULL, 
            0x96CFD14BB0F46287ULL, 0xF7CF11B634240AF8ULL, 0x81C36CED989F79A5ULL, 0xE79118ACE890D8AEULL, 
            0x1A366659019584A2ULL, 0x2B2B134371586C82ULL, 0xD489D8E682F363ADULL, 0xA2A6D926770A15E3ULL, 
            0xF07F545CB51C0DACULL, 0xF8D04331E74F0DEFULL, 0x7B344BE40A0F0557ULL, 0x3DE9BA24B3970487ULL
        },
        {
            0x0CEB3D354599FA00ULL, 0xC73117E089B128B7ULL, 0xE4CF603E456F4882ULL, 0x994B09044882FE06ULL, 
            0x8A5214EC31A71EE4ULL, 0xCC77B9A4FF06AA6CULL, 0xDA254A0872ED5239ULL, 0x842D60DA6CA6582AULL, 
            0x7D9E2CA69879135CULL, 0x4CD7D2B1C78805E2ULL, 0xE6DBECF0CCA10163ULL, 0xC6828625CBFF231FULL, 
            0xCD78935422E480B8ULL, 0x25DAEFB525E30EB9ULL, 0xE88E704A2B396932ULL, 0xF414735709CFCF17ULL, 
            0xAC15DAFB1D277583ULL, 0x4B26AB2747182337ULL, 0x1483435093F733FEULL, 0xB7AED370441DE4C6ULL, 
            0x7F5C9929A385D3F1ULL, 0xEF4080F40719E286ULL, 0xBA3604C22D4FF21AULL, 0xD0817AD40C940AB2ULL, 
            0xC6704B7434A342ABULL, 0xA356E8FD1CB974ACULL, 0xED05F63E80DDEA5EULL, 0x2E2FF3E86FEC7B02ULL, 
            0x7134793CFCBA0EACULL, 0x4C2D027E73CA6FBAULL, 0xE0401FF46EEA06EDULL, 0xCB45713678DFBD16ULL
        },
        {
            0x2E58E43EE48DF2F5ULL, 0x0840DB0621D4E9D9ULL, 0xCE4C590DDA87296BULL, 0xA26A44018D81CDB1ULL, 
            0x28B6AD690EFC5D61ULL, 0xFE086E415BCC8AF0ULL, 0x7B44F21697D006D5ULL, 0xA3973F95539F670FULL, 
            0xA3502EFB179C2FF4ULL, 0x2B2E1663924E4E76ULL, 0xED8AC226D337EF63ULL, 0x02692EC675E4A275ULL, 
            0x4954839FD899C9F1ULL, 0x08FF938ADFB88399ULL, 0xA2AF5B7B62992D3BULL, 0xF6F40E07DEBEBE4BULL, 
            0x26A012CAC2A0A868ULL, 0xA22BF147EB2004CFULL, 0xCE0BAE1FEF6A1A6CULL, 0x8921F261EF9C3B0BULL, 
            0xA77FAD5D060FAC77ULL, 0x12617D4A8EE81426ULL, 0xDDDE0FBB5540065CULL, 0x7215E8E0F73EAA83ULL, 
            0x5BB7E1586CF97419ULL, 0xED3101AF345D30C3ULL, 0x4B529EB7FFB63469ULL, 0x19AFF96560BA5F01ULL, 
            0x273EB864EE44977BULL, 0xDB031A0182A36512ULL, 0xE976F2FBC3FAD5F4ULL, 0x7599DE0CB6FBDDE4ULL
        },
        {
            0x7BF669D2C593F554ULL, 0xDAE57C48B4E4F44DULL, 0x8140CD04AFB704EEULL, 0xAC100B871DCB2552ULL, 
            0x5696D38B5A4A537EULL, 0x0A7AB03E22037783ULL, 0xDAE57BDEFCE17A02ULL, 0xD912832FAD8820B5ULL, 
            0xEC7E5F8A00B76CA9ULL, 0x8EC14C69683BFF6CULL, 0xD6F81ADE39B38217ULL, 0x3B185416339D8194ULL, 
            0xEAAC13B1051A3A8CULL, 0x27D722129CC4DF1CULL, 0x85DBE75FDA07A0F6ULL, 0x02E77A7284D96A50ULL, 
            0x12AECD87ACFC6078ULL, 0xCFD763F3AF02178DULL, 0x8CA2381119D3AD2AULL, 0xC565B6E75706E0AAULL, 
            0xBBCE03DBFC6C7863ULL, 0x15E9AFCFCBBF2005ULL, 0x6C23EEA19EB427CBULL, 0x1DB3CE323CB3714CULL, 
            0xB2CE99AA5B09FC54ULL, 0xD8923301FD495620ULL, 0x68190A6A3C781F06ULL, 0xD8400FF0E0E57EFDULL, 
            0x5E2CCE50F7CA030DULL, 0x40FF4D5A9FD0A428ULL, 0xAFE856075F6A9550ULL, 0x27252AB0939A473CULL
        },
        {
            0xF900A1BCBEE7906DULL, 0xBBB033A0745C8BC3ULL, 0xD6D28989B8872261ULL, 0x66B33BB39ED48782ULL, 
            0x1E64AAE0A51E21A8ULL, 0xAEE033034A82317BULL, 0xE331839E91C25454ULL, 0xB67D854F6428AC9BULL, 
            0x6DBF4DB606A71BD7ULL, 0x0522046911A9E771ULL, 0x4EC7EE027E779DB2ULL, 0xBEF3ADD80D82535CULL, 
            0x3E5BAA9D92081AD1ULL, 0x76BA114125CCF8FEULL, 0xC051ACA968C81425ULL, 0xC4B8851BB35162F4ULL, 
            0xA723A589016BF0EEULL, 0x93F5D8CB1AF0B5B5ULL, 0x24847A40C9900D11ULL, 0x6B57244D88E92AEAULL, 
            0x8209F072DD0C1D7CULL, 0x03B52733E5527ADFULL, 0xFA420BD6178E8AD0ULL, 0xD6F162A7777C9E39ULL, 
            0x7CBD0125101F1314ULL, 0x75C7EEF5A4BBE040ULL, 0x88158AB9317EB210ULL, 0x0A1311FF4998131DULL, 
            0x4015BD3B11690B40ULL, 0x6FB14EDD9906B75BULL, 0xB64E7988577F64B1ULL, 0x10B2041A4C4EF40BULL
        }
    },
    {
        {
            0x26A03DE1A963641CULL, 0x4E43CCFF633F39CBULL, 0xCCF5ACDF2FD91832ULL, 0x52B8799204FC52CAULL, 
            0xC786A68194AE83D7ULL, 0x5F5B5123F112549CULL, 0x263085269139CF28ULL, 0xF3356D667515DA30ULL, 
            0x397B00D46B4139E1ULL, 0x27491FC32FDC93E8ULL, 0xFFDBF0951D921165ULL, 0x4E06B1964B463DA1ULL, 
            0xB6C22E06ADA9207FULL, 0xE86FF2001A163102ULL, 0x0F56ABD68F2FDC9FULL, 0xB17298C204DE8774ULL, 
            0xDE78FD0035E12F73ULL, 0x7EFFA4284595E04EULL, 0xE43F2417EFD05960ULL, 0x4D691C4821E022D3ULL, 
            0xE0CA4CD43484A2ADULL, 0x51779B8CF5021EE7ULL, 0xECA288240617F4B9ULL, 0x1A1A37F18D11B59AULL, 
            0x5E62A07206C0F0CCULL, 0x0C9F684069351D6BULL, 0x8D645CB3106EF3EEULL, 0x502DDFF79B627E66ULL, 
            0xD4F113544B38A726ULL, 0xB7797F5FF4A06A11ULL, 0x33B5AA3AA053E26EULL, 0xC87A00370F5FA70FULL
        },
        {
            0xC50C6DF718F13D45ULL, 0x7B7042D5C090969CULL, 0x8BC8773800068EECULL, 0x2DFF06AFF10EBBE0ULL, 
            0x95BA8331DDAC5C96ULL, 0x71A99D67D9052DABULL, 0x3D756DF6988AE250ULL, 0xA059D35E1F2FC849ULL, 
            0x6FE666DD5690788BULL, 0x382A59E45A2253BEULL, 0x8AC97A34134E705FULL, 0xEE488B89DDC8AD5FULL, 
            0x2DC3A1DF5DF61A30ULL, 0x1F750F157964D511ULL, 0x586A87143368BDB9ULL, 0xFC9E380D400A0357ULL, 
            0x9F985317C707C880ULL, 0x164BD6CE7038C97EULL, 0x64BC89D2878FF0D4ULL, 0x57EF214B06C00CA8ULL, 
            0x143E22DED15F2D60ULL, 0x62339393307D73E0ULL, 0x837721A627667ED7ULL, 0xA184CE2C877CC6D9ULL, 
            0xAF8076334952B34CULL, 0x9E043CF00DD2F3CAULL, 0xD2759652416009A1ULL, 0x72B52CA3DE9AC4EEULL, 
            0xF7B4A99B5B2DE5A9ULL, 0x54726A67D36825F8ULL, 0x41528EBE22B43726ULL, 0xB17F638290DB008EULL
        },
        {
            0x3683E2119B70ACD5ULL, 0x5DBFD61F0A9CC318ULL, 0x74225595315A4CD5ULL, 0xA2AD5CBDFF8A8E41ULL, 
            0x89A12705652BDDC4ULL, 0xFE97BC6F90F667DBULL, 0x90CEC69E3368A592ULL, 0x53C7090C61FEDD9BULL, 
            0x4DC5D2702C0256B1ULL, 0xF5C3DA4FBCFB3FC2ULL, 0x029D67DC8211D79DULL, 0x447DA89727C69D32ULL, 
            0x9EB617E59FB47E6BULL, 0x90B37D362C626C16ULL, 0x3A5D6B28BB459C27ULL, 0xF2046E6EE27D3F21ULL, 
            0x2A235B8E59DAB44EULL, 0x8839C09AE5CEF389ULL, 0x4F18F5FB824E77B4ULL, 0x50CCE97DB510615AULL, 
            0xB57FB83A272CC263ULL, 0x0EB25167192AF191ULL, 0x2AD7FAD2A7E9E19BULL, 0xB0BB02E3769066C4ULL, 
            0x8F982B711A1186A8ULL, 0x543753EA41CD243FULL, 0xE9A4A9EE66D3033EULL, 0x80AFAE02BF5BC07FULL, 
            0x4617E437842AF6CFULL, 0x481943C47362B7A0ULL, 0x45458699A8E35F64ULL, 0x0621AF80AE8943C4ULL
        },
        {
            0xFD0230D20AB6338EULL, 0x509B6513F82EC408ULL, 0x3BAC4B3C7A14201EULL, 0x49E3622BEA3E9FACULL, 
            0xDB90EB8D30D4979BULL, 0x2C8C2D7E203FA2E6ULL, 0x374FDED34C4B0E77ULL, 0xB8278E06AF0AB965ULL, 
            0x4867A3418A15BE1AULL, 0xCA5168CB526FC22FULL, 0x1645A88252E55ECAULL, 0x7EB37833EB09B76CULL, 
            0xDA6AB7F497DA2E47ULL, 0x5C8850AACED32969ULL, 0x39F60A86C11DA8BEULL, 0xBCC042D0A61FDF47ULL, 
            0xC17601E6E1BC4C2FULL, 0x1E08DDCD1CE462D3ULL, 0x5E03728384D712F6ULL, 0xD759A7DE1C419B64ULL, 
            0x59904D6121823AF8ULL, 0xF0E195D47B135B7EULL, 0x0E5CD770730F19DDULL, 0x20DBF4F3E8F95222ULL, 
            0x2CBEC986C89AF9B1ULL, 0xD5BA1F72B13E83D1ULL, 0x5CBBA1D1BE353FB8ULL, 0xF42252C531C5C80AULL, 
            0x76D8E5A770B34A9FULL, 0xDC00EE51BE065B1CULL, 0xD09A72D19598DDCFULL, 0x6378414717620848ULL
        },
        {
            0xB89A7B971B53458CULL, 0xD2FEDC03D0ACB461ULL, 0x4FCCA41EAD84C19EULL, 0x79310B273923B8D4ULL, 
            0xDBC0C65CDEE49B42ULL, 0x64231EA3351AA6E5ULL, 0x8E5956BDAF91A6ACULL, 0xF3DBE908663A1B0DULL, 
            0x6F500CA14BD1D0EFULL, 0x1FFA14791615B879ULL, 0x7B707CD55FFE0D6CULL, 0xC8F946F597E1E0BEULL, 
            0x5642A1354AD4DD6BULL, 0xA4EEBD46A46B5D6AULL, 0xBAD0334E68A12296ULL, 0xAC83984C5FCDA3E4ULL, 
            0x50F8360E2BDF14FAULL, 0x08E0FDAA067F28B6ULL, 0xA581279EFA455C2CULL, 0x5CB2FF34D4F36CBCULL, 
            0xF9F95A001CAEC631ULL, 0xBA848E304FDEB114ULL, 0x066697155FB28331ULL, 0x89F60D34EE375678ULL, 
            0xD3A8DD335A345D38ULL, 0x0CEECD237F797A09ULL, 0x5F30EA09E60E2F9DULL, 0xD4A87DE73788EBA6ULL, 
            0xA59D3CEAD7DB45B0ULL, 0xD44D875575130AB5ULL, 0x814D8D374AE7532EULL, 0xC3D1A45E6142D73EULL
        },
        {
            0x2CA9AEF5D79EFB10ULL, 0x340217BE81D1BDE1ULL, 0xAC5B170C10C04DDEULL, 0xB135ED5EC91CE204ULL, 
            0xAF54CC41F70607AAULL, 0x22D5FB39B18A9F43ULL, 0xE55C84A926E86754ULL, 0x701DF00A58599BEFULL, 
            0xDB5266DC64D02AF5ULL, 0xE9C2F44849A969F6ULL, 0x1228F801A86BA260ULL, 0x2C32BE3891B65B38ULL, 
            0x4EA1FF0EA44CF610ULL, 0x6E3AC4F814F7601AULL, 0xA59D14063B3D9C54ULL, 0xE938BCA6EA9A3D9DULL, 
            0x868086D9B6B2E4D6ULL, 0xBBA02711FBDDEB31ULL, 0x0B108839A6123BEDULL, 0x8EEEFD98035BA5FFULL, 
            0xB2FC8349B0C6F538ULL, 0x79971B2C88DDD44FULL, 0xC60E6DF31390C395ULL, 0x311997162B831650ULL, 
            0x8C5E5608D1EDE126ULL, 0x21A576B66EA892DFULL, 0x4605E8C76F306B87ULL, 0xD2B86D9BD244BB0DULL, 
            0x12A72EC51F3F6BB3ULL, 0x5DEE8EBB909D784FULL, 0xCC537156C59934BAULL, 0x7113310A4A913C63ULL
        }
    },
    {
        {
            0x4D5BDAD3F61106C6ULL, 0x9318A76BE666FE30ULL, 0xD15E470B25371248ULL, 0x6536F27FDE34DE30ULL, 
            0xD6CED7DE80A3D365ULL, 0x2BA8D85DE46B8E94ULL, 0xB3533F91E3E19A8FULL, 0x66E8254FD2731411ULL, 
            0xAEC8865EA232794EULL, 0xC2E2B810E4F907FFULL, 0x2978EB512E36240AULL, 0x2CC740981A41EAB2ULL, 
            0xF869F75C49A7DCDFULL, 0xF3A09F273E26EEF0ULL, 0x3798B081A581A8FFULL, 0x2336E520239CC33CULL, 
            0xC58EEEC7B8CE77E9ULL, 0x2FF030DD993B47C5ULL, 0xD24F44E7D30DA1EFULL, 0xFEFBB3A763CBCCA8ULL, 
            0x86BD9AE8B7E5063FULL, 0xCBCD2A30D9D81A45ULL, 0xAB2F250389AEF2CBULL, 0x07A8D8AD4CEAB183ULL, 
            0x6ECAB81C96772672ULL, 0x50F9664BF8C49B35ULL, 0x8868C17456B5C623ULL, 0x2B5BD854FAE3C73BULL, 
            0x4DB68890D7CA199BULL, 0x156214417013B593ULL, 0x7F376CFB7B6E9641ULL, 0xC19E75782D69417DULL
        },
        {
            0x7754FD55D4E8BBBBULL, 0x93279E90B4814637ULL, 0x8DF51185AA0E76F8ULL, 0xCBB2AC012470C004ULL, 
            0x91E64F393614C40CULL, 0x12F0A880ECB54764ULL, 0x928B20C2D1E30150ULL, 0x887DDC30AC6213A5ULL, 
            0x47AA0F79B57D88D9ULL, 0x9DB34ED950A70C2DULL, 0xBE8B59F8F7745D49ULL, 0xFD7D1E554321F78FULL, 
            0x706BEA78A31EED5DULL, 0x87E92AC204593DBAULL, 0x0784F6E4D7C191B4ULL, 0x151A5AECF9326CF3ULL, 
            0x7C0DA8787A35A165ULL, 0x7B2B389D32646C3CULL, 0xA1233F91967DE558ULL, 0x732C817DBB08BA62ULL, 
            0x35F06FE318BB69F6ULL, 0x42BD049266DA75BDULL, 0x50226D7273E938D7ULL, 0xBF21C3F6E89B633AULL, 
            0x62E10AC52CF47FACULL, 0x4ECBC293EB2D38F1ULL, 0x4334DE4EC0743091ULL, 0x673A11D9FE9F000BULL, 
            0x9932DEAAA43420F0ULL, 0x2EEEB594A29DE1F4ULL, 0xDC9C3F20923D94C0ULL, 0x38EDB4C034189337ULL
        },
        {
            0xAB257CF7ABF642CEULL, 0x6F653DECBBC49650ULL, 0x9DC703A376043CB6ULL, 0x59754FF15B289409ULL, 
            0xE41BFE5E1F01E621ULL, 0xB7112CFB6D45CF1DULL, 0xF38D21D98A1E4099ULL, 0x6D880B51B0A27D20ULL, 
            0x98CF24515BD2BC1FULL, 0x8A0F39C827490763ULL, 0x0AAF90CD9A04ED6FULL, 0x0595CCC7A99CF663ULL, 
            0xC5EDDEB0B50743DFULL, 0x024B7BF51008AE30ULL, 0xAD560B0C5E91CD56ULL, 0xFD5F1C5F855326B5ULL, 
            0xE8F82B7115A8C061ULL, 0x36753F1C486501E4ULL, 0x2484669246C40B7BULL, 0xBFEB3FEB7929BA5DULL, 
            0x798732B3EE4E7D5BULL, 0xE3FFBFBEBCA40ACBULL, 0x370BE69CD067F043ULL, 0x89306279959AFD51ULL, 
            0xCB3813AD3EE5884BULL, 0xB05CC19F7B3FFE64ULL, 0xE022518CD9C3B20CULL, 0x47874EC07E7D259BULL, 
            0x0663F8E4F34237CAULL, 0xF3E8AF2AD0FBE94EULL, 0xBD019C2F4EF5E26CULL, 0x4D0D3A0CF393FAAAULL
        },
        {
            0xB0ECAD9EA25AC76DULL, 0x50D8571E8B7AEEB8ULL, 0xC9F392BFFEC583B1ULL, 0x87176023CDDE86A3ULL, 
            0xDFCB2CAED0FC732EULL, 0xFEABD5EF1B00362CULL, 0xAB2BFA4380C4AB27ULL, 0x3F14ACDC55BE4074ULL, 
            0x7A88EB8465E29A06ULL, 0xBBBE398B3FA2F472ULL, 0x9DC04249BB4D8047ULL, 0x1BF6547BC7E2AF8FULL, 
            0xCC2A020B4C4C4C7EULL, 0xD3E07ACCEA7FAF53ULL, 0x0E82C53C4C0B39E1ULL, 0xCC534CF4656EDB16ULL, 
            0x9ABA763A1D16C214ULL, 0x3991C3331EB1B02DULL, 0xF5B59224E555B8C4ULL, 0x77AD60C1E4A50732ULL, 
            0x8B81D061AC17C6E9ULL, 0xB999B7B12A0054A7ULL, 0xD0B0E01A3C79ACA6ULL, 0xBC13BF305F8C35ECULL, 
            0x9A90064F673F76D7ULL, 0x4E7103F80DFBBEB0ULL, 0xDDEBF7AE4C682A97ULL, 0xDD0AD8C399F4F10DULL, 
            0xD904C5F69EC0F5CCULL, 0x49014F6C431F9B94ULL, 0x78CB9839AFFD50A1ULL, 0x3BE363868ED14768ULL
        },
        {
            0xC5E7C1B85D1A51DEULL, 0xC160D3445163E7F8ULL, 0xDD5BDFDCEF1AE413ULL, 0x4FA8DD98BD951B1EULL, 
            0x3378FBEE1ECC5305ULL, 0xBE498D07E28681EEULL, 0x97581286BBB51A68ULL, 0x001A4F94BB270BDAULL, 
            0xA2747830B4AD6900ULL, 0x37AE037C5EA6CDB2ULL, 0x8FF2A99995BBE931ULL, 0xEFB5FF0516BC1840ULL, 
            0x3F5E9C0EEA8C90B8ULL, 0xA8427B1611B473DBULL, 0xC45E5A52377EC5E4ULL, 0xFAF370F769318DA4ULL, 
            0x0C7B94ED236C23AEULL, 0xF7106124B928656BULL, 0x8088777C765BA14FULL, 0x3C4488F8D9C11796ULL, 
            0x682BB124C1483A73ULL, 0xF34632C508C4FAB2ULL, 0x51295CFAEFA95983ULL, 0xB087B6895C54D7BEULL, 
            0x2D549268655522E2ULL, 0xB142190869EF69A3ULL, 0x8F46D0118F05A229ULL, 0x4F6921ACB7E0085CULL, 
            0x5CD6E3EE18F0E62AULL, 0x553742B02ACB91E5ULL, 0x0197F5F617774523ULL, 0x1EB15BCEA33F8CB0ULL
        },
        {
            0xB3BB1FBF9BE70E3BULL, 0xC5FED737995441CEULL, 0x5D8DC03CE35BE75AULL, 0x794562F54889E2E1ULL, 
            0x6560A2BFBCECAF0AULL, 0x6D9B3DE24998341AULL, 0xB32F178223D7A59EULL, 0x9AAB73F0A11CA146ULL, 
            0x3C834C0BFE3E9293ULL, 0x109126826E086BB4ULL, 0xDB8C43264DA553B3ULL, 0xCD84EC2693A26346ULL, 
            0x413492DCE2668423ULL, 0xDD3FEEAA4441B830ULL, 0xC42BA6E34E30AF28ULL, 0xBDD4038305E12B8AULL, 
            0x0123E96052EF3E92ULL, 0xDB966BF2C8EC27CEULL, 0xCF41C6971FC81B29ULL, 0x3C0AA1E5F71A3271ULL, 
            0xCB8B894DA8D44C6EULL, 0xB8E9C78C0100409EULL, 0x00D339B776F85AACULL, 0x399CF737770660CAULL, 
            0x9970CCED8C95614FULL, 0x7B1A0D8C9020C01DULL, 0x31FC910B3848E138ULL, 0x5BDDA5B5F54CA8DDULL, 
            0x5E15727DECF7ECECULL, 0xC5A71A9090510915ULL, 0xEBC3728F3799D04DULL, 0x776D15A2CAC4571CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rigel::kPhaseAConstants = {
    0xF4D15FB9322D353BULL,
    0x32A5A2AC2840D725ULL,
    0x9D80EFB808B921EDULL,
    0xF4D15FB9322D353BULL,
    0x32A5A2AC2840D725ULL,
    0x9D80EFB808B921EDULL,
    0x7D7213E2F8AB300BULL,
    0x1C110D321DB4E4D5ULL,
    0x6B,
    0x77,
    0x33,
    0x26,
    0x1E,
    0xA5,
    0x81,
    0x01
};

const TwistDomainSaltSet TwistExpander_Rigel::kPhaseBSalts = {
    {
        {
            0xA59C6BEF216EA5A8ULL, 0x9AA245C6D97D7D2AULL, 0x1C29AA7DEAC77FC8ULL, 0x68C8A3DC233E70E9ULL, 
            0xB9E63FD26CBBDD3CULL, 0xC4E0B087A4DBC244ULL, 0xED58A9F5EDE486E2ULL, 0xB652D2E99770C761ULL, 
            0x645AC840AC48D439ULL, 0x967C8A84ACA020BEULL, 0xFD128129114A7633ULL, 0x430D6D39FFD5552FULL, 
            0x8D114E4C10974B58ULL, 0xF724C0A9E335F260ULL, 0x6CD7571A691DB43DULL, 0x28DE4610F7D97E7DULL, 
            0xE939F484C2748CFBULL, 0xAC9939212625B9B2ULL, 0xAAF370336DDB2EB7ULL, 0x528407D782E316D6ULL, 
            0x3845760F5F5BBE86ULL, 0x067ACCA86362E30CULL, 0x9FA6B7633D63640DULL, 0x896A956AF03AE35FULL, 
            0x214327EFD6BA8C95ULL, 0x1821CBD692DE5EF5ULL, 0x32A970B4D33B754EULL, 0xD5CE4F10534F80D5ULL, 
            0x5C519C2F37F58CB0ULL, 0xAD28D1D6BFC36F01ULL, 0xA48F1747C54FE68EULL, 0x2D4DD55453B9608CULL
        },
        {
            0x0A02A517C9D75ACDULL, 0xBA6F92961A333D6BULL, 0xEBC963165CD9BBCFULL, 0x0DF588FD6E2459FFULL, 
            0x17993E46A56D231CULL, 0x54D113F8D89DDE9EULL, 0x8F37E14539219BB6ULL, 0xFD8F57526B6DB8A0ULL, 
            0x1660F90CEAFFDC70ULL, 0xB1FBBADDA1E9AE89ULL, 0x3B672BF81544CC96ULL, 0x47B31A0D19F28883ULL, 
            0xD9CEF73D7482CD63ULL, 0xD942F883799F0C15ULL, 0x1D478AC3891D6AA5ULL, 0x528DE448E5D23C18ULL, 
            0xBD0DBC0D8A3A8FD6ULL, 0xEC771C0E5720EE1EULL, 0xA185B6015300F76AULL, 0x42BDF5773C256688ULL, 
            0xB7F06CE5FC2227B1ULL, 0xDEC2434BEE5BCD69ULL, 0x38DE7C2D4B3C08DFULL, 0x38079F41C6C59880ULL, 
            0x8B2945AFD5BA8E69ULL, 0xE35FBCE79A1A37ECULL, 0x4837F53783A8D5CDULL, 0x238B76F6CA6A1470ULL, 
            0x3BF69FE945034A24ULL, 0xE99BA7B11050D727ULL, 0xF799878426D1928CULL, 0x27DC72F722F1F1D2ULL
        },
        {
            0x6347D4287B8DDF6AULL, 0x43424F6CA42FBE87ULL, 0x82B910CC0D114E07ULL, 0x264ECE6660C470CDULL, 
            0x6BF94A03504A2316ULL, 0xDD1FD887ED9F1A9CULL, 0x59D0475DC38C267FULL, 0x98D4BE0B719F497EULL, 
            0xEB21DE4C5DF6C725ULL, 0x148400BE1813F628ULL, 0x07777A5B1CE5978DULL, 0x1E7244A29C683465ULL, 
            0x7129EDCA9C32414FULL, 0x64B6240AD4A1C51EULL, 0x5108F7740653CD89ULL, 0x010F7B96C77F49A7ULL, 
            0xC043670A3E99A5E2ULL, 0x66D14E85C83D8554ULL, 0xEC15FA62EFD54B6BULL, 0xB4A502E6650DB02BULL, 
            0x798F6E2FB927EA25ULL, 0xDDCEE7DCA89C87B9ULL, 0xCF96432CF9AFBCA5ULL, 0xD95F84B4EAF3FCC6ULL, 
            0x8E9D31ED90DDB6FDULL, 0x14B6BBAB4839E98DULL, 0x8710E0AD575DBB3FULL, 0xAADF1178855FE427ULL, 
            0x22A5596B6D7A328AULL, 0xE02ABECED995C8DFULL, 0x646E0B8AAF8C871AULL, 0xF2650D6752B673A0ULL
        },
        {
            0xA8A4C31F9BBBA307ULL, 0x9E05C79F1798A736ULL, 0x263247F77A92F64FULL, 0xF86405C000874B22ULL, 
            0x704C514B61EA3965ULL, 0x6DB16F5E03174B2BULL, 0x88CE35D50F3EA0D9ULL, 0x38F69C2DB9D5AD5BULL, 
            0xEAECD8FBA42D6A89ULL, 0xC4C13AAD996B9C67ULL, 0x6F9390EAD05789C6ULL, 0x72426CB05518CB06ULL, 
            0x21D9B7C7D4B03CFAULL, 0xA92FBC94EA7B3D2FULL, 0x299FF627F870723DULL, 0x8635A869FAB75B96ULL, 
            0xDBD7DC2733E879F5ULL, 0x710A1D04F4732E10ULL, 0x3B88235EFB657665ULL, 0x2D745CB9DBD9F978ULL, 
            0xF71EF74CD36D00ECULL, 0x7DFDFAF0A9A78624ULL, 0xCFE5DCBCECDBFA9DULL, 0x2AECBC172B34E40EULL, 
            0x3465D9D68EA3609CULL, 0xB31C3E8FCF1403E8ULL, 0xDF1938402296882AULL, 0x71EA9A423FD0685EULL, 
            0x9394ADFD12386B63ULL, 0x6CBBFC98858EBE4CULL, 0xC39A3D7292D0D133ULL, 0xE27A4D93BDFC4E41ULL
        },
        {
            0xBA04A908DA39D827ULL, 0xDB86D8A99BF01C78ULL, 0x7B2F4C591F72AD5EULL, 0x322B8BE82E1527F6ULL, 
            0xC4E7018656AA60B4ULL, 0x7C9A4E6ABF281DB3ULL, 0xFD5E18632E6BAFBDULL, 0x674BC0843FE9130CULL, 
            0x8304B13637A1B5E2ULL, 0x7E11E56E81EBC9AEULL, 0xD884ACD7D141E7B1ULL, 0xFDB28E0C644B38F7ULL, 
            0xD78644D03A81D0F6ULL, 0xFD2D49C594D7FFAFULL, 0x4D9D70C59E240242ULL, 0xE4B2BEB254A87F35ULL, 
            0x060497CF318A3A42ULL, 0xE121ED801D51ED51ULL, 0xF67E649D5AABA39EULL, 0xCF060F32EC1CA3FDULL, 
            0x3479B6BCBEB1241EULL, 0x04735E07D852BB3EULL, 0x6DB5B473EF645D06ULL, 0xAB5DE527BDF6453DULL, 
            0xE423DF0D310B54F3ULL, 0x7CB237C0E3483BFAULL, 0x3A50A85CFB6A28FBULL, 0x2BDD2C28B7DA0B24ULL, 
            0x02E856E6AFC2B6C8ULL, 0x5D109F9BA86E04DFULL, 0xBE0B62B97EB9EB41ULL, 0xCD1812CC7C8BE5E2ULL
        },
        {
            0xEE119370E3D3E48AULL, 0x2C40510B652FD5DAULL, 0xC327035A62655397ULL, 0x905F823288BAB464ULL, 
            0x0E992E90A3D84BFAULL, 0x02CD0DC894D1EA19ULL, 0xE7F6CE037BF60BBBULL, 0x63311F7FEEBA912BULL, 
            0x89845A47AD0AB0EDULL, 0xE6C8C3795F81BC05ULL, 0xBB337F2CDB004B8CULL, 0xF7823A29F0A39E25ULL, 
            0xC7F2482F22FAC45BULL, 0x1F5E672268538CACULL, 0x6E502CB0BD72C671ULL, 0x3A17267506D3E9F1ULL, 
            0xD1993945B1333526ULL, 0xDA750C6CFFA5A93CULL, 0xEE967243F08CACF6ULL, 0xB305FF6574D1E35AULL, 
            0x51F4538DDB56FC71ULL, 0x4CBD10454F09E779ULL, 0x73944AC561F4CAD6ULL, 0xDA64FA422766B0A2ULL, 
            0xFCD5276F4643183CULL, 0x2E7FD0A4D2994951ULL, 0x0ADB9D3AD52B37F3ULL, 0x1E36451D61F5E1AAULL, 
            0x45F340D0DB0CFD72ULL, 0x3D4305BE461B029AULL, 0x55229EBD65AF8C02ULL, 0xFA6061D2CBA3773FULL
        }
    },
    {
        {
            0x6D427D1993DAF378ULL, 0x489CBED9794F6F9EULL, 0x6067A322C64E3A30ULL, 0xA0538C66A9C95EACULL, 
            0x3E612D73E9ECA8B4ULL, 0xE3018FE1AA6BB43AULL, 0xEDBD197B5E39C929ULL, 0x9FF4C4EFE934DF14ULL, 
            0x89FC7BDF4AA07C06ULL, 0x20C1DE8859B6F252ULL, 0xDAEA7655C04F1684ULL, 0xC51A4475AD4F77BEULL, 
            0x2F0182F3327D303FULL, 0x66D7ABB5EA106644ULL, 0x9BBFAD5EE4A5F331ULL, 0xF25C89EF18B4CEC8ULL, 
            0xAF7B6C21827BFD9CULL, 0xF8A7185F99F2697AULL, 0xA72860F5D4AF7F3DULL, 0xE0E8B539A40C253FULL, 
            0xF20B4322F078E4C6ULL, 0x6FEC8EE00B5E3FB8ULL, 0x0F03C53D32E3050AULL, 0x707557CDB272DBE0ULL, 
            0xDF3D1F6AEBD44544ULL, 0x02D1137FFC12B492ULL, 0xE8761F8CD3F53ABDULL, 0x8AEC507CE754C264ULL, 
            0xE653B043206119D3ULL, 0x95FE9113CE25ED8FULL, 0xF662394829C92600ULL, 0xD08BF383B3CCA9D2ULL
        },
        {
            0x46BADE1B2D7D6AA8ULL, 0xA3C806014C8C34E4ULL, 0xF9215FAF59E209FEULL, 0x740736E659C19671ULL, 
            0x27C0D6DFD3B5968EULL, 0x44C555D20BAF870CULL, 0x6002362A5C8DFF9AULL, 0xAC1A291E0E35F7A3ULL, 
            0x00BDB59EF61B6388ULL, 0xD29E15B36F12CF60ULL, 0x4DD9EC947F25B96CULL, 0x9DDF3EE4AAA0979AULL, 
            0x98D663CE28CDE1C5ULL, 0x831511F7CB6A313CULL, 0x5FEE95A685F80250ULL, 0x9649F866DF27193BULL, 
            0xA2DCB036456F571FULL, 0x20383DAEB94CC1F7ULL, 0xC33619CC3D0C6598ULL, 0xA8148D9CE0FE1412ULL, 
            0xB129EDD034683B09ULL, 0x7AE292AEB0665065ULL, 0x9CC85EB2CB58C943ULL, 0x613A1E1228C644CBULL, 
            0x3AF0891AD1D9EF5FULL, 0x9D181498381634CBULL, 0xA96E19FE179B9E14ULL, 0x66910115EEE6092DULL, 
            0x30999ED07C4C7172ULL, 0x3A9BD8ABBCC8917DULL, 0x96C5913BC98A8DC5ULL, 0x30085882E788B021ULL
        },
        {
            0x143E0805D0A15FEAULL, 0x8564918C17A5EB40ULL, 0x0B454520B03532B2ULL, 0x23B0DFD0C10D6444ULL, 
            0xECB03732E840A7BBULL, 0x25B7121D40FEC79FULL, 0xD33A160E3F3A6DEEULL, 0x367D8B8021AF598CULL, 
            0x739E5EC8D6E2A05EULL, 0x37B198245689E28FULL, 0x4694D7DFDB084FA2ULL, 0xF45A2C133ABAED80ULL, 
            0xD156FF9F980C7E79ULL, 0x6A0F220599265135ULL, 0x38F066FC05EE0E62ULL, 0x883337355095DA7BULL, 
            0x4C43CC9D199118E9ULL, 0xE685CDA1AC421E5AULL, 0x970D24017FFCB829ULL, 0xD23BB51517DC3E46ULL, 
            0x7EA994B8E20D8C0DULL, 0x980CA0BE56AC50B9ULL, 0x326BB7C3E8BAEB93ULL, 0x54ED4C8101B940FEULL, 
            0xEEE5133AA5C08004ULL, 0xE815F3E0365F16A8ULL, 0x8E141AAA56F82277ULL, 0xC00AD5040672841CULL, 
            0x8A101E9B94637042ULL, 0xF0CED8B9015B6312ULL, 0xFE4C3ED20DD2DCF6ULL, 0xA4CE818987EC2E2DULL
        },
        {
            0xB99313BA5A5F6426ULL, 0x4FCA7A8A7E2DD27AULL, 0xD895780F99163EA9ULL, 0x1252F272E014C877ULL, 
            0xDF7DE3CAD10A3D35ULL, 0xDA9CADCD6F1C583BULL, 0x23F2F10DF6444972ULL, 0x730D3BB26EF9FDEFULL, 
            0x2482316B3BB09580ULL, 0xA05518E957B61D33ULL, 0x2C6AED61F3A8F993ULL, 0x04999C5FD8A3A70CULL, 
            0x954ABF9733000DCFULL, 0x242597A6533D0422ULL, 0xF4C585E734920F68ULL, 0x37B11D52EF737D47ULL, 
            0x29757BD067FC6E88ULL, 0xE5884DD0D47CB1DAULL, 0x1F4847639EC49C4DULL, 0x74DB63C13BFF73A3ULL, 
            0xDCA1BDB617BD0F01ULL, 0x27C3E2D5BE0E78CBULL, 0x487D0B30D3BCAA89ULL, 0xC83CD33230562949ULL, 
            0x2E986CDE9AAD6A6AULL, 0xA21AB33AADC0C7D2ULL, 0x14A7D8A477C98CA3ULL, 0xA99603B5CEA9F5C3ULL, 
            0x67F95C3E56CBACF8ULL, 0x02EB60E782B30EAEULL, 0xBCFE83796998004DULL, 0x8ED521E03213C941ULL
        },
        {
            0x590AA81A4C5F152DULL, 0x9CDE76B24486C969ULL, 0x313591815DDF95B1ULL, 0xA32A06CFBC2C6365ULL, 
            0x65815C60E32C098CULL, 0x886A1FA37ECD0805ULL, 0x2CD050174E04D1D6ULL, 0x3E036EBF61991CBAULL, 
            0x999FB90F1AB809D8ULL, 0x43F3A8ADCD3F84B9ULL, 0x89133DEE190DF616ULL, 0x03C15904323FCFADULL, 
            0x8A14DFB3C8068885ULL, 0x83602A5D9ADF23F4ULL, 0xEDAFA9BDA1518ADFULL, 0x110F091B2DD26BFCULL, 
            0x6D5BC638AAEDFF74ULL, 0x9829CDB00EA43B99ULL, 0x4E4AA493E0C5CB24ULL, 0xF9F2E8338C22B472ULL, 
            0xC969D19A6F4EE017ULL, 0x457CCEA3FB36D637ULL, 0x1860776CAF57F126ULL, 0xACE54E96A2B52CBFULL, 
            0x23360F541DF2C196ULL, 0xDE0DAE94981172D6ULL, 0x90AEDCEDC62D3F91ULL, 0x959402E27663D9D2ULL, 
            0x13EEB8CA037A52E8ULL, 0xED9B1A72B8D5BDB8ULL, 0x77B6649F14D7448EULL, 0x443BB0AF70C3FFB1ULL
        },
        {
            0x3E80DD030E4EFE74ULL, 0x33C42D590720FE39ULL, 0xC04F54EDE7278D4EULL, 0xD6BD65F08B4DFC49ULL, 
            0x3619C8B0DC447FA0ULL, 0xDD060FF3C9B5EE2AULL, 0x1AD25431035336C9ULL, 0x7FBF2C9957D8791DULL, 
            0xEE1F27D78D558F11ULL, 0x56BD3D23A5997FE7ULL, 0x24B52E81999C71E1ULL, 0x22DDCFCF8526A4E1ULL, 
            0xEB52F9A68E7237B3ULL, 0xD21EE0FCF3544844ULL, 0xE575A8393064F8F8ULL, 0xA2083B54B287BEA4ULL, 
            0x9F3B163E04E4395BULL, 0xE868293A7BEB9E03ULL, 0xE92D17F3DF57BE67ULL, 0x321924CC01FF2806ULL, 
            0x362223CDFB96D90AULL, 0x629A86A7B7EF215FULL, 0x0F3BF11C35DFC0ECULL, 0x3ECA620F8048CF03ULL, 
            0xDB69E4A1728BF739ULL, 0x7F5708F4C765AC93ULL, 0xDE4ABB4232DC736FULL, 0xF421E47429C49F0BULL, 
            0xC3A97A0F988EE33EULL, 0x7C9C09C9AFE20673ULL, 0xF2C6C96A2F699DDAULL, 0x031BB7DF5613D340ULL
        }
    },
    {
        {
            0x710C2C3764B64BB9ULL, 0xD13EA24AF556460DULL, 0x394F9195247949D6ULL, 0x76803CE0F5F519D9ULL, 
            0xD36D89580491F2FFULL, 0x7A105374BD8A67A1ULL, 0x76970F2DFF6D62C3ULL, 0x333BE0C4B4D6CEFCULL, 
            0xF6D49563575F3B3CULL, 0x8116286B3ACF31EDULL, 0x38AAA284C68870A6ULL, 0x5E0F0903B27BF360ULL, 
            0x245CEA41781668A9ULL, 0xAB1894884C5A4C5AULL, 0xE499723CD0B6D162ULL, 0xB85AF50E914E80BAULL, 
            0xEC266D8C85603DC5ULL, 0xEC8E803E15E506D5ULL, 0x706E6A5C8AE0E47AULL, 0x2BA83BB41F13BE0BULL, 
            0x2F9F43CFF7C327EEULL, 0x06CFE0C53FCBE7C8ULL, 0x969B32DE278AD3A4ULL, 0x6EDC7A4C2412FA7BULL, 
            0x2232ACD26FA8C2DDULL, 0x99CF29B9C6489CACULL, 0x2F29C7001484658BULL, 0x55BFF315E5F4584FULL, 
            0x0043156D152931BEULL, 0x3FDF4B6AE279099CULL, 0x191AB511E76DE6C4ULL, 0x76DE0FC62FFF7283ULL
        },
        {
            0xA8F8ADEAA35A8277ULL, 0x5CBCF5C1A5DB80D3ULL, 0xF2FA849076DE03C6ULL, 0xCF4041F023A01AB9ULL, 
            0xC7EC2CAF6592EB7EULL, 0xB3FE17AA7425B4AAULL, 0xAAC3031A508CF266ULL, 0x8114E45F03FBA3F2ULL, 
            0x11B905C00ED6BD10ULL, 0xF5128BE03BC4D800ULL, 0x2259FA7EFA6F3D53ULL, 0x6861E07D92E344F4ULL, 
            0x1A4D8CF6896E5689ULL, 0x266C21A603B6B3C0ULL, 0x6DC55C45426661B8ULL, 0xA3F425C463562C70ULL, 
            0x4064A937A3AE9983ULL, 0xAB027EB98CBC306DULL, 0xE9BE4E6E964BBF5EULL, 0x8A350DCAB17B42C2ULL, 
            0x268F34ED7C712C8CULL, 0x35D12365D4E339D6ULL, 0xF00E25CED2F2A4F4ULL, 0xD8E096D8C112896FULL, 
            0xF362F83B62261C2EULL, 0x16B5E141AB56BA34ULL, 0x70A39560D8D37718ULL, 0xEBE6A84DCAC9BFFFULL, 
            0x04789E3BD690D877ULL, 0xE747338FDACA2DB3ULL, 0x42F9B218BE373E80ULL, 0x1F5725010B9DA039ULL
        },
        {
            0xF24A2555F8C28587ULL, 0x091BB54677BA4452ULL, 0x1E5FF45D7DFABDDAULL, 0x289A71919F4E2328ULL, 
            0x1442155996A4F8EAULL, 0x738E9E8FCDAAC498ULL, 0xF53ECFD3B3AF43B2ULL, 0x7EE596DDC9D2731EULL, 
            0x84469EEE74EF7432ULL, 0x1A531DEE7CAE14B8ULL, 0x909EE6805BCE7078ULL, 0x67989E2A026462FEULL, 
            0xCD9ACD2D27CC1D86ULL, 0x41B18D7F8B167DA6ULL, 0x42057C8D0D649A8DULL, 0x30F6363C168AC4F7ULL, 
            0xF24831D635AFFB8CULL, 0x95D2DF67210A6A69ULL, 0xDD39284E17ACEDA9ULL, 0x307A3DD0213E4E04ULL, 
            0x874B4617E8607B26ULL, 0xA3BA8EEF3334CC90ULL, 0x734CE89D62E41422ULL, 0xC1CD4EDA40D9EDEDULL, 
            0xC675C5A3ACDFBEE0ULL, 0xCFF4D47859798CB2ULL, 0x1D470058E32C5C00ULL, 0xC310589B622EBCC5ULL, 
            0xF9D49D3EC9503145ULL, 0x70343FDA2E1E50DEULL, 0xC1E09D04E17850CCULL, 0x44D34736AA13FE16ULL
        },
        {
            0x1CF5C08179F9F847ULL, 0x37E37553514633C4ULL, 0x383BBE57EF591BD9ULL, 0x6DA2AFAA56E4BB12ULL, 
            0x11BC85E0C34DE319ULL, 0xF9340878ED16DCA6ULL, 0x0A8A99F0B08480AFULL, 0x2414EB11139DBA92ULL, 
            0xBB2DC53AB1944F4EULL, 0xB448B7802DE85818ULL, 0x32A7E03AF1F7E032ULL, 0xBAC7D6BD1C305F0BULL, 
            0xCA52FE9ED192666EULL, 0x84C611FCEC3172E0ULL, 0x3555F6147AD48225ULL, 0x56FC456219180100ULL, 
            0xD6FD9C13A44C8FC2ULL, 0x39F345C01FEE976FULL, 0x3B47F47EAADA29B6ULL, 0x5874AE1B9FCD3614ULL, 
            0x5EBA558AABB815A4ULL, 0xA17B6FFD57BF58F5ULL, 0xF43E4D0FC9AF7998ULL, 0xDBA69FE1D5A031E6ULL, 
            0x7696A72C5C7C0DEBULL, 0x85A987519BB1F57BULL, 0x8F001C7880877951ULL, 0x2AA3294830AD8C62ULL, 
            0x05187DEA13E5E695ULL, 0x4C39FF935A7A2341ULL, 0x5F21828F391661AFULL, 0x6A901E1B6F5A6A91ULL
        },
        {
            0xCC44017A682C2666ULL, 0x6716D0FF03916C21ULL, 0xFE377347C34788B3ULL, 0x527FD504759FFF20ULL, 
            0xA22038443FA17879ULL, 0x64F05941D9AC2A22ULL, 0xCC9AFB4C77A216F7ULL, 0xC722E733ED2C8799ULL, 
            0xEDC70C64CDD33F6EULL, 0x1673E9327ECD47F9ULL, 0xBBAE2BB65D2A736FULL, 0xC0DEFBCB3D876E47ULL, 
            0x157B02DEEF7DCDDCULL, 0xF18D68C70D52E6B8ULL, 0x19D0D308926BCF47ULL, 0xF030B8F4979664C1ULL, 
            0x7FC36F087BB24385ULL, 0xB9E0D557E9A512A1ULL, 0xC30D54AF408643E3ULL, 0x5500F89C81C89ADFULL, 
            0xF6A3F5246EA72FA2ULL, 0x6234829678B4E154ULL, 0x72DA4F21C756A6F2ULL, 0x9DBA194C4841D459ULL, 
            0xBF36909B2DA068E0ULL, 0x3207E32085F45EC9ULL, 0x290722C45792545EULL, 0x4D1859D47CC45FF4ULL, 
            0xDBEB35C7A8200E2EULL, 0x8365D516CD53871CULL, 0x8EC89A0EB8277DF8ULL, 0xA4D73F92A6102DF7ULL
        },
        {
            0xFAE77C0F5479F748ULL, 0x6419D2D6D0683DE4ULL, 0x17D9677C24835D20ULL, 0xE9657902ECD6C353ULL, 
            0x0F9B34ED8B40C8C4ULL, 0x83B868FFD8C3FFF5ULL, 0xCD6933DA4755959EULL, 0x07BA0F0A87F2DF0EULL, 
            0x21E373D69B49CBB2ULL, 0x7D8A86ED21F0C705ULL, 0xFA1CD686DFECDE14ULL, 0x99BBED79BAC5B490ULL, 
            0xAA2486EA31464E62ULL, 0xA297E409D116EC43ULL, 0x2A8C7C94C53C702AULL, 0x524176C8B18172AFULL, 
            0x5C52ABAED58C5C14ULL, 0x8CC69D94A540B364ULL, 0xA09274E7A94D80BBULL, 0x4E2E45BF97FAC310ULL, 
            0xA8E99F3918A247B0ULL, 0xAA97B45B925DD1CDULL, 0x4A09B77EEFA8A47DULL, 0x0FCE56E985214F20ULL, 
            0xF21D1D76C9FE7374ULL, 0xB5A4D5A43FD8EA5FULL, 0xDF9B2F4F3D6FACB8ULL, 0x88BD901AF1DA3D97ULL, 
            0xB12AE6C601EEB49BULL, 0xB99A8EA5707AD19DULL, 0xDE346805D72AE331ULL, 0xDE5AC8AF91823555ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rigel::kPhaseBConstants = {
    0xEF721F5988BA1C50ULL,
    0xC23AD342ECCBED1FULL,
    0x7BAEAEE40B6A18DEULL,
    0xEF721F5988BA1C50ULL,
    0xC23AD342ECCBED1FULL,
    0x7BAEAEE40B6A18DEULL,
    0xDE429726B1FFB14BULL,
    0x7E11F7AAE296F145ULL,
    0x81,
    0x3E,
    0x8B,
    0x3F,
    0x76,
    0x50,
    0x1E,
    0xB1
};

const TwistDomainSaltSet TwistExpander_Rigel::kPhaseCSalts = {
    {
        {
            0x72563253443DB78CULL, 0xE1FC2967DC5585C4ULL, 0x696272CE9B5C3D61ULL, 0xFC3EF1FB2F98492AULL, 
            0x83A9DAF1E0363E09ULL, 0x946D375ED69AD8E9ULL, 0x92EC7738E36AC3B5ULL, 0x9CEB9359017141EEULL, 
            0x934D238F6F779538ULL, 0x5660DDC7160BBF79ULL, 0xB7118EF7BBF881DBULL, 0x3D3C73DEC8D64368ULL, 
            0x35E6F7506704E23FULL, 0x44FCCF885FE43648ULL, 0x2EB7E92D1BC44248ULL, 0x74693DFC329754EBULL, 
            0xC39828034C206C17ULL, 0x647A2EB1983DA312ULL, 0x6983C4FF8357D576ULL, 0xE63009D5E2379424ULL, 
            0x0EC023E876729B0AULL, 0x7908B55B5E5E4334ULL, 0x4E0E25E285812298ULL, 0x69FDCDF18FF91B5BULL, 
            0xE3A07834BA13E8A8ULL, 0x1FF417DCA474255EULL, 0x0E6B58E9ACC466B2ULL, 0x106136505B489716ULL, 
            0x182F3AD17B1890ACULL, 0xCCA5143970A617A1ULL, 0x54AF4A169F9B204FULL, 0x11D329107151330EULL
        },
        {
            0x1AFD9E36664CEBD5ULL, 0xD88C42995D56B21BULL, 0x7478A6CE0EFB484BULL, 0xBCA7A567DE0DAC62ULL, 
            0xE9F94086B63B87D4ULL, 0x6FE5A40A6E5FF575ULL, 0x6A1FEA68530CDEECULL, 0x09460F5DA72202F5ULL, 
            0x7B5E78484D3C7CE8ULL, 0x5EA30B0F4A4F0017ULL, 0xDEB7D3B79E7171B2ULL, 0x506338ED88314383ULL, 
            0x573FFE242BD86B03ULL, 0x74A26FEA8F844ECAULL, 0x475568D37DC38420ULL, 0x565783AB27443342ULL, 
            0x2DC031EB671B2DFAULL, 0x42ECC3F06D6CF343ULL, 0x3E3D92C1A8E42268ULL, 0x1E1949377DDA8C17ULL, 
            0x47E3F02E3E7656E8ULL, 0xE3DE9946FD8146C4ULL, 0xD23CA881BFA49467ULL, 0xD9651224AFE7755CULL, 
            0x0AC232E5D6498ECCULL, 0xDC181F8A2F751AAEULL, 0xB673D15C2B08F84BULL, 0x0BDB51368CF1C812ULL, 
            0x5F00D145D432C2EDULL, 0xAF27D59CD42EF386ULL, 0x993058C7B0758A08ULL, 0xDC66531A164CC5B7ULL
        },
        {
            0xB3E88B8FB102049DULL, 0x1D4CB13CCD08F400ULL, 0x7F2AA6EDB61E2026ULL, 0x3968BE0783B052C8ULL, 
            0x7B372398C5FBC97EULL, 0x63137696CE9AB523ULL, 0xDFE6A29C7D5301ACULL, 0xE4FE56727D4FB350ULL, 
            0xB9F6CAC1ECB37A4AULL, 0xF1BCCCEC3F9E5B1FULL, 0xF3AED36292EDBA98ULL, 0xE5247964B6846768ULL, 
            0x9DA4763D61AB18D3ULL, 0x7AA876B055C5743FULL, 0x2D99C6536B2D53D7ULL, 0xE05702435F9DCB88ULL, 
            0x98A61E251FB257F5ULL, 0x07AF28093CF05EF1ULL, 0x44F4BAC652E11C85ULL, 0xC0B06846C86D7A18ULL, 
            0x0B04A24C7902FB76ULL, 0xE67026AE06497EB6ULL, 0x33950A7AC7B1C03CULL, 0x7B9B9CD1110D5352ULL, 
            0xB38CDBDF91EC0DCEULL, 0xECED3848B84AF922ULL, 0xE77E543A852FC9F5ULL, 0xE1D51F574B91999EULL, 
            0xFA031736147A04B7ULL, 0xDE0F7F36667BED88ULL, 0xFC36588AF265F249ULL, 0x0660505898E5EA2CULL
        },
        {
            0xB1B6A0699F14F615ULL, 0x204D3B077D267D72ULL, 0xC7A7312452003C77ULL, 0x0B326F4C54327171ULL, 
            0xBD8EE1C12EE0ADB2ULL, 0x65057E85333DC5BBULL, 0x59EA888EBF01B01AULL, 0x9D96AE071E8D332BULL, 
            0x6E645D37AE26A109ULL, 0xF7E19B025155ABB3ULL, 0xC8BD291180BC2BB1ULL, 0x699F4BFBD73DEEC3ULL, 
            0x95DAAC33B7EBDC62ULL, 0x3CF40C2050B9A060ULL, 0xBE56157E14E1A45BULL, 0xB659FC989053A955ULL, 
            0xA1E431A0FC47188FULL, 0x7D08F87CBFB1D293ULL, 0x638567556EEA431CULL, 0x968D0973AC1F393CULL, 
            0x0B2C8B10DBFDD6EAULL, 0xDEB47B0005AC5E98ULL, 0x643A053E9B61EF6FULL, 0xD7FA85807670C12AULL, 
            0x8559E279A92ACC05ULL, 0x878CDC187849A8CAULL, 0x8FB2B2B6FCDCDDD0ULL, 0x16D066E2B49D798CULL, 
            0x37591BA54BB4A95DULL, 0x509B9B1585EF2089ULL, 0x91D0BDA7177A5FADULL, 0xB96A8CECCB14D786ULL
        },
        {
            0x86F16CF977AF8F71ULL, 0xC950EF03F9921BA8ULL, 0xF3E47C59ED82FECBULL, 0xE5AEE30AF5417985ULL, 
            0xFC0D85B03E947984ULL, 0x8FF6CB4EDC926F4CULL, 0x9EC09D650B2A53EFULL, 0xD0E647CA1C12AE23ULL, 
            0x6C7EC978ED51C781ULL, 0x646DF26B313284E2ULL, 0xFB8493A89019CDAAULL, 0xDD927DA28FF7BBE6ULL, 
            0xB476A9C98B92A994ULL, 0x4711360D8DE871FEULL, 0x80C74378511A76FCULL, 0x136ABD250AD4E3C7ULL, 
            0x735666446EC176DBULL, 0xC92371DF54D5A2DCULL, 0x931DEBD23B1D6098ULL, 0x804A8836107C9FA7ULL, 
            0x1EA347928882E19AULL, 0xBD918108AA3D59D8ULL, 0x0813183344CBE2E0ULL, 0x827887625C43D59EULL, 
            0x76154CBFB80F32A2ULL, 0x699FA7A88DB78D6EULL, 0x3BA0199305FDD8C8ULL, 0xAEAEEBCB68163386ULL, 
            0x30DBF2FDA566833CULL, 0xD6B330A810CF9075ULL, 0xA3E0D6A88FD06A2BULL, 0x6A9D0E15D57D9318ULL
        },
        {
            0x54FF338E52371B14ULL, 0x644582C91505CD54ULL, 0x3DE835864CB651F0ULL, 0xB8014F3C96408EB6ULL, 
            0x9770AAE96DC3AAC1ULL, 0xCCF4FE7C1537EAC4ULL, 0xB592BCC1835EFE42ULL, 0xBF41446BEF0D24A6ULL, 
            0x0D9CA2031DDEC131ULL, 0x3AD0A96A4AE01E09ULL, 0xE14310C26058AD03ULL, 0x63485AA83D7EB0B0ULL, 
            0xFCF62F1F00C1A3BFULL, 0x54672FD8BC8CED86ULL, 0xB99630F3CD58000DULL, 0x46B58CB6FBD84133ULL, 
            0x42651D5FCF76B2D0ULL, 0x8F0AFD07BC67B700ULL, 0x8CEDF1EBB77E5EA8ULL, 0x3E62A0EBB7D87ABAULL, 
            0xEE0FD2EB023D12F8ULL, 0x0FB412B4C4FC6B75ULL, 0x4CB3FD68FBE2B785ULL, 0xAB9C7A5D158FF97EULL, 
            0xFE0257B6CB261DBBULL, 0x7695244D0B564206ULL, 0xF0749B2633D2FAB9ULL, 0xB92CCC26D3450421ULL, 
            0xE5A15B8A255CB273ULL, 0x07765809BE09E54FULL, 0x77CCF1565A265463ULL, 0x2FD612EAA495D678ULL
        }
    },
    {
        {
            0x62E4C32999B54AE4ULL, 0x7BF20CB24BBC5DCBULL, 0xD74BDC0A15D08A41ULL, 0x0AD25DD5F4E25D90ULL, 
            0x8777AC098D4C6063ULL, 0x8F93AD7903ED937CULL, 0x1D5F81973146F3ECULL, 0x43D170FD99DD16C8ULL, 
            0x8D6E87F2DFFA9FD9ULL, 0xC6980EDF10DAF310ULL, 0x0063E0B3FB6742B4ULL, 0x057A9C0CC705AD4AULL, 
            0x87E74E8A98AC9D06ULL, 0xDD9A50DD7BD433A2ULL, 0xC9C3309BEB71A790ULL, 0x7EB90144E3EFBCE4ULL, 
            0x98966F26F0DF1DEBULL, 0x4607FF55C105C990ULL, 0x27B6960FD0FEDC0CULL, 0x33AFA8948659C925ULL, 
            0x5A88FC3ABAD078C9ULL, 0x33F557FDC62AF6BBULL, 0x25ACD129F81F145CULL, 0xC1DC4F032900BED7ULL, 
            0x9FB3D71109DE7AF8ULL, 0x4099EF794774874EULL, 0x9EAD3AD8BA89C7A0ULL, 0x31D1366DA74EA71FULL, 
            0xC89EF06AA8820BA6ULL, 0x488FD4004A884ACBULL, 0x087CBD9CE3ECB4C5ULL, 0xAEE368374B01F24BULL
        },
        {
            0x26D3787333F4FF51ULL, 0x10CB5FFB0611B780ULL, 0xFA680EE673CB778FULL, 0x52C3B4BAA0837D3CULL, 
            0x1622CC77EDA12777ULL, 0x4A6AF23534B5EC1BULL, 0xE6BEE9DAB544A210ULL, 0xE569D6D9E36CE00BULL, 
            0xEF138A81AC914F43ULL, 0xDB5B6FD1CAB7D248ULL, 0x3B7BF117F0F8132EULL, 0x5827A9730E3E12A6ULL, 
            0x8221A37AFE02C9D0ULL, 0x13BF33B182FBDFDFULL, 0xD94C8FFA69151DF1ULL, 0xD0D48E6C76C27046ULL, 
            0x17C24BA8E39B35D2ULL, 0xBFEBF8F91586B9F5ULL, 0x4ACB9F73CF6E28EAULL, 0xE950284A8F80F627ULL, 
            0xC04ECF9F814B9A7BULL, 0x2E11C6F90C92B824ULL, 0xAA422497C22388CEULL, 0x26A683BB90994132ULL, 
            0x2FEBAC039328C928ULL, 0x207C2978184BE6F0ULL, 0xA65075C150CE47F3ULL, 0x07E49DAD130C6CCBULL, 
            0xA726F0DEEC000806ULL, 0x6C7CC79C5C2085B6ULL, 0xE05549DFDC243A39ULL, 0x5F54A8A80B5F22F9ULL
        },
        {
            0x55A613E295184A0EULL, 0xAF8F1313E7576491ULL, 0xAF23028360CF647EULL, 0x1B8F1547D700D840ULL, 
            0x5F08CDDE885189C7ULL, 0xFBBE7B036400D69CULL, 0xB2415F6ED365AA8AULL, 0xF2361D8DF0CF83ACULL, 
            0x388D64EB0EC198C9ULL, 0x5A7D16BA867EF302ULL, 0x3A9DE982FBB07BB4ULL, 0xD2FD9B9EF36019D1ULL, 
            0xEB98F485FFE29468ULL, 0x03D3D1970547DB6CULL, 0x6065416575A8F07AULL, 0xC3DB32917A39D548ULL, 
            0x071EDDDF1BE4A55DULL, 0x0FFB4C182B22F8FEULL, 0x0D1BA56E1882EBC3ULL, 0x7E21D858662CEF9BULL, 
            0x1328F5C3C20B6FB0ULL, 0x854272DAFC69919DULL, 0x3C4AE188D9D7F1BAULL, 0x64DB7D88478A871BULL, 
            0x08B84BAAC067146DULL, 0x688885610B0E0AE4ULL, 0xED946D6642A134B3ULL, 0x08C35230537E5DFCULL, 
            0x6810EEC76655A897ULL, 0x7AD562795027DF64ULL, 0xCFEFCB2CC94AF181ULL, 0x4CF151CF43EEADE8ULL
        },
        {
            0x9EB2522B1EB46D02ULL, 0x623C2CEFC312974EULL, 0x40215F7502D9390AULL, 0xFB8E53441E798BFAULL, 
            0x7DEFDA6C17D25784ULL, 0x9805FA502E4DA2BEULL, 0xC90C5A671D08ED5EULL, 0xC2BCA638C3779D46ULL, 
            0x3BFA438F7CD401D4ULL, 0xEFAD18ACC6C8ED0EULL, 0xBC4BC97860909DF6ULL, 0x19A88A709C968FD0ULL, 
            0x1FC86B5E092973F2ULL, 0x0A594A8D07F77A3EULL, 0x0B1AFA4947603DA3ULL, 0xC2CAC5534A03525EULL, 
            0x9BD5F9F816DEB516ULL, 0x0AE169A4344FA029ULL, 0xC44513582577876AULL, 0xB2E7A7CCF2AF47A8ULL, 
            0xC2381F5D529A6F61ULL, 0x2013667053D608F1ULL, 0xE1994BAEA986F403ULL, 0x606DFC6489CCCA5EULL, 
            0x92343F2363CFC852ULL, 0x70CA90B3F5733EA4ULL, 0x101FDB9561085B9CULL, 0x335554A75576C7E3ULL, 
            0x8BFD76E415F8AC00ULL, 0x8096EC4AC4A4EF87ULL, 0x41E23140ED063FEFULL, 0xA6BBCCDD22F91E2DULL
        },
        {
            0x6D0CAFB3D2958EEAULL, 0x9950F2D2630EADE6ULL, 0x4CD9ED596C0282F5ULL, 0xD78BD95EE2D44574ULL, 
            0xA1E6E43C5ECF595CULL, 0x9EB32A6B1E7BD87CULL, 0xC7C348BE6C78EA81ULL, 0xD0571D6171C49C06ULL, 
            0x268AA557BB525EB5ULL, 0x5BD1FE939FD56683ULL, 0x472F1491D5F813D5ULL, 0x1F4D04093B06F742ULL, 
            0x768D8C0A71B3F6E1ULL, 0x31F26688D2D19EDBULL, 0x88B18D627BA97885ULL, 0xE1F3C590847B5D3DULL, 
            0x046A6F6C1BE5E06AULL, 0x5C8C74E601061FCDULL, 0xC8C98C494D2F0ECEULL, 0x312B364E7039F910ULL, 
            0x2BA7CA4C3482C07FULL, 0xFF8B2E292D84B3C1ULL, 0xC9D922DB4D5BE67EULL, 0x06A7698B50517F4FULL, 
            0x6B11B6DC2990A588ULL, 0xA192D9E5CCB9536DULL, 0x978B112155D7B59BULL, 0x7018C648385A23E0ULL, 
            0xCEB809FEBFF5054CULL, 0x0DB50E12A26FC635ULL, 0x2E58C4E6F7E714E6ULL, 0x295CCA021A955FB3ULL
        },
        {
            0x0151646EC08369A2ULL, 0xDAEEB073574A35E8ULL, 0x952D9CD4171CD690ULL, 0xA52FDB143865AF3BULL, 
            0xDFF901AC4DB92DC4ULL, 0x2769DAE1D9380171ULL, 0x0D26EA4421F9FEBAULL, 0xC33395897273369FULL, 
            0x8EC360593B14A175ULL, 0x7E5B3A045320FA85ULL, 0x9F20C2A0E9BFA4BEULL, 0x9D2BA96DE24A96D7ULL, 
            0x1BB4DA29E90E3FD8ULL, 0x33673F0CEE5390E8ULL, 0x497095E4A7E34205ULL, 0x969DCA39E827CD12ULL, 
            0xFD82D57C4577245CULL, 0xCB7F635B401E942AULL, 0x60531BDC653461A2ULL, 0x7C6F6F940E69FCADULL, 
            0x3EAC7E45DB74D2DEULL, 0xC3E9732E43A8776AULL, 0xB2CE0F7985D60316ULL, 0x5A76DD92F2166307ULL, 
            0x0EF15AF45251B58DULL, 0xA3C5893FF5E7BB71ULL, 0xE432460FF40E8A17ULL, 0xD0C79E67D9BA439DULL, 
            0xA37E23B7E3E9E823ULL, 0xD992AF26CF2FE93CULL, 0xADADE3206633D4C3ULL, 0x99F6015EEC14134EULL
        }
    },
    {
        {
            0x5A835CB52E90043CULL, 0x7410B5C036B97BA0ULL, 0xC6D97C8EC7DF9CD9ULL, 0xC1D53845876CD705ULL, 
            0x3E0FC7F3677544BCULL, 0x5F7DD47DB2A14F11ULL, 0x83B3D191E4CF893BULL, 0x8D63E1FC85958E80ULL, 
            0xA982AC59E02F9FB8ULL, 0xA1603B862193755AULL, 0xC046B2CBEACC7834ULL, 0x643CF81CD8360FC0ULL, 
            0xFCADF6561D4AA7ACULL, 0xFF2A12160191CECBULL, 0x5B5A4A56BE08CF7CULL, 0x8DFAD9D19C5DCD84ULL, 
            0xE57A96AF4ED15757ULL, 0xC4A560657835BBCFULL, 0xA43BCAA745F5BE52ULL, 0x5FD18D1CB336017FULL, 
            0xFF13F18DCD40D13AULL, 0x6CE3B2B90F89C452ULL, 0x5C5F886AACDE1634ULL, 0x88860F7E25A1BDABULL, 
            0x96DBD10CFBBEFC54ULL, 0x5A04F66DAFB48E11ULL, 0xEBACAE97D62B37D6ULL, 0x8AFCA7B69AE4E14DULL, 
            0xD79E76F4A48339E0ULL, 0x02370E7CA068F081ULL, 0xC8971899837E4468ULL, 0x7252A78481E70A1AULL
        },
        {
            0x069EDBD5590EDBF7ULL, 0xF9E8FFB833094931ULL, 0xE676F54AD1554E32ULL, 0x8FEF2FA6538AF6D9ULL, 
            0x240E7A3BC2F64F27ULL, 0xC55DC1F48FADF23AULL, 0x142092F90B5D50B0ULL, 0x8008798DD02B4FE6ULL, 
            0x03CA94DD0769427FULL, 0x98C519CC469C9BD3ULL, 0x81966EE7F3653786ULL, 0x1CEC2A38E74A7BC3ULL, 
            0x2AF139FA09FA8D0EULL, 0x4A2BAD53FE107B91ULL, 0x1E153D6EF6837285ULL, 0x1BC181A3FAF54D29ULL, 
            0x96D0E1B6AD4041C3ULL, 0x2720481B9E0C6103ULL, 0x7BA6CABAB1532F04ULL, 0x963C9DC0CFB1292CULL, 
            0xD66AF9A0A8C7723EULL, 0x092D417D93B3307EULL, 0xB102A26864F1A21AULL, 0xD6EAA750B60DD95BULL, 
            0xA8C07AB03659B116ULL, 0xE02B7561FC9008DBULL, 0x7A6123DDBCB040E0ULL, 0x3809C40DD87296FDULL, 
            0x7FBEEBB928A4B101ULL, 0x650F1D0C55AA60DDULL, 0xFD24C8833BB48251ULL, 0xA26CD7FEAA64E356ULL
        },
        {
            0xD4409CEA3E7562A7ULL, 0xFC263D581B4AE829ULL, 0xFE19F202678FB45CULL, 0x88739C2D2F750801ULL, 
            0x4A042AA4B5CED561ULL, 0xA98C6A35E61CCBA6ULL, 0x7DE31ED72FB6829BULL, 0xDE3AEC74948D0A10ULL, 
            0xAE6875E7EB3F8546ULL, 0xB63FDA0B02FB9319ULL, 0x70742FB582A2926DULL, 0x8D1ADF17DEBC02B9ULL, 
            0x1075A3CEFF313A50ULL, 0x974CC36D2B1449F5ULL, 0x7BD58C0732B8508DULL, 0xEFC59B580AD18D72ULL, 
            0xF34C37F0FA7282E3ULL, 0x02EA5527FB3B34D0ULL, 0x9827B3728D3DBE74ULL, 0x54A21CD3F90039A9ULL, 
            0xC8CD3D05A1E0CCE9ULL, 0xC51D4B4210D4E344ULL, 0x6DFFEC2B91744F80ULL, 0x7727C861ACEA0B28ULL, 
            0x23CEF92A4F897FB9ULL, 0x207BDBD4E289FBA3ULL, 0xB05EFDB88DC58155ULL, 0x054B72CFB08E0984ULL, 
            0x2891D31E196554FEULL, 0x6CBC0C9C339FF5F3ULL, 0xC626E2861D0638C4ULL, 0xBE36179B0D6B0D22ULL
        },
        {
            0xD9775895742D2C4FULL, 0x404D42065036EBA4ULL, 0x5ED65AACB4207119ULL, 0xA2A7CB55F0A996E4ULL, 
            0xBE213B12C6AEE154ULL, 0x169536D837B20071ULL, 0x569D8FC852300E76ULL, 0xBACE17F1EC60A507ULL, 
            0xC922763D38502986ULL, 0xB1D58451C7BA392AULL, 0xBD98E0E32F050B8EULL, 0xC2DB343F46A66C85ULL, 
            0x47AE21C4C5DB6DAEULL, 0x6B5000BAA77AD4C8ULL, 0xACA14E040BD39B6FULL, 0x0EB529D45613CA04ULL, 
            0x46261966CB28DE54ULL, 0x86627E64B4BC6585ULL, 0xDA1AFFC12F14BB00ULL, 0xF9E4A2BCEED121E0ULL, 
            0x4568EE43CFAAF424ULL, 0x84FE512CBBB49256ULL, 0x19C3464F53872AB1ULL, 0x0D4A48386F08C297ULL, 
            0xB177440F2F62267EULL, 0x370E2317CC52DCA2ULL, 0x870374DC43B058F1ULL, 0xCBD25D9E4CA0F9E9ULL, 
            0x5E1D45F84FB60FEEULL, 0x72C110BD0690B3C8ULL, 0xEEB004BA390A448BULL, 0xDB2DC75C35088494ULL
        },
        {
            0x2D4DE95A23DE1CC7ULL, 0x5E43BF9A23C7FBB4ULL, 0x25F3689761B73F7BULL, 0xBA28C22D22B6A4BCULL, 
            0xF85D6549029E1867ULL, 0xC134ADF067C8AA5EULL, 0x5CA8886B8C4A0B69ULL, 0xBB99DA6B7D8FDF2EULL, 
            0x81D023B446EE21D9ULL, 0xC0DD29CDF3281803ULL, 0x3A588D977FE83736ULL, 0xAA55B5F6EA1B00B6ULL, 
            0x1D24F26522F59932ULL, 0x8B166E6241DF6BFFULL, 0x960F61972B0D6CFCULL, 0x8417EFC139B45ACDULL, 
            0xA98B36778E29DBC1ULL, 0x9783522D50DA0CB7ULL, 0x42062335717A7DCBULL, 0x54B127ACDBC715FBULL, 
            0x53A6571ECC3FAC93ULL, 0x705236FDE4F1E4EEULL, 0x18AA7F040718D461ULL, 0xB923CC55AA934551ULL, 
            0x16AA6624FC149886ULL, 0x1E97A6C8E0E99C4AULL, 0x3710464BC730585FULL, 0xB01BBFB3D00E5102ULL, 
            0x20D8878C6871ACB9ULL, 0x6C48E878AD50822AULL, 0x768BF13C579122D7ULL, 0x10510DE7A894A48FULL
        },
        {
            0xE595D4945CB71651ULL, 0x6045756DB8B25E59ULL, 0x6134EF2AC159E9DAULL, 0x13349B4B5A68D02EULL, 
            0x0B68776CC3D0DE92ULL, 0x014E30EEC2A697E9ULL, 0x419CCE3159E072B5ULL, 0x9F32E28B4EA5064AULL, 
            0x96629D740379011DULL, 0x4ABAD508C0444E55ULL, 0x1637F1CC9B2B742AULL, 0xFCD1DFCD8C1E51C8ULL, 
            0xB5E9428149A43C5DULL, 0xF58A5CDD89ABAC9DULL, 0x4265BFA585B6F745ULL, 0xB858D13B9A0DC2D2ULL, 
            0xEE67FEFB03182992ULL, 0xC9162983C6B54346ULL, 0x4C5C5087BFB03CB9ULL, 0x1F899DA8FC94829FULL, 
            0x7C27C4B3925CDE92ULL, 0x67FD61E42EB97FB8ULL, 0x55C35E08A968B9CAULL, 0xB2A5A8AC7F9F7389ULL, 
            0x6591A8696E83082EULL, 0xA2C0964E700693D5ULL, 0xA2556227A85F087AULL, 0x558FBD4831F673B8ULL, 
            0x033B871EC35C90B9ULL, 0x0AEE2B816A69B467ULL, 0xB4D7377426C26A03ULL, 0x5B1D265FB11DBE21ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rigel::kPhaseCConstants = {
    0x4CDE5FE485FED2D7ULL,
    0xD7A1E554B6FE30BEULL,
    0x1DBFCB4BAE26447CULL,
    0x4CDE5FE485FED2D7ULL,
    0xD7A1E554B6FE30BEULL,
    0x1DBFCB4BAE26447CULL,
    0xA7F33526C55A2916ULL,
    0x94589AE1B5CF57B3ULL,
    0xA5,
    0xFC,
    0xFD,
    0x8B,
    0x41,
    0xFE,
    0x60,
    0x0D
};

const TwistDomainSaltSet TwistExpander_Rigel::kPhaseDSalts = {
    {
        {
            0x7671AD6C2BEB9A6AULL, 0x3DA18BB1A08EB8D3ULL, 0xEBD93D196B5660FCULL, 0x40C8937D9A394FADULL, 
            0xD3D91C9FA40481D4ULL, 0xAF8AAFD05C656408ULL, 0x6165BDA2D887CDD9ULL, 0x8A9C47AEE19BAC3DULL, 
            0xE36FF577BDD979F9ULL, 0x5684B41FCF54DDD8ULL, 0xA097121F62D45ADBULL, 0x1B16AC3739020FB4ULL, 
            0x83E0C50F3DCA7E08ULL, 0x883FD054F84455B6ULL, 0x4D59E3C8675844F3ULL, 0x51AF2595DA64A44AULL, 
            0x2AAF30178A101867ULL, 0x48990EE49C33B86AULL, 0x4B53925F2B475488ULL, 0x04ACDA71848CB928ULL, 
            0x2327CFF922D03ABDULL, 0xF33E17DD692ADAD6ULL, 0xAEAAF4AFFA12B340ULL, 0x065CCE27F2B45A42ULL, 
            0x434EE5D10BCB3406ULL, 0x624EC6B02A8C2B1FULL, 0xEA4EFFC8D5CEDB88ULL, 0x0EEE3562823BF7A5ULL, 
            0x4529010988AF9261ULL, 0xE7AF07D64F762E42ULL, 0xDF756713CC1AA659ULL, 0x7868FA0AF0F96EEBULL
        },
        {
            0xE852E5BDDFA0AAA9ULL, 0xE65681C3CD401A78ULL, 0x03F2387E0C2DAAC4ULL, 0xE5D2685EE2D37F00ULL, 
            0x2F44BA3F9B5C487FULL, 0xEAA0A5483F01F32BULL, 0x44326807BE0352CDULL, 0xE11E5E88ECC31131ULL, 
            0xDF3BC25FBE6941DFULL, 0x10D7F3EF7290C9F0ULL, 0x4590DD14F03C9469ULL, 0x7C9857EC64F61624ULL, 
            0x3F81973BBD804A0FULL, 0x24B40FFD3C4D907BULL, 0x3D3A3907F3CD91C7ULL, 0xA61E38B62221A3AFULL, 
            0x96D36FDBB9E82C66ULL, 0x593EDADAA978F8FCULL, 0x695EFDA9DBC689BEULL, 0xCA09FF83E3CC0403ULL, 
            0x5DED639A0181CCFCULL, 0xDF58BD6631A58C84ULL, 0x0935E7B23AC29EF8ULL, 0xA33659DFBA14FA7CULL, 
            0x4FDD12AD6A2C3F71ULL, 0x51B5D56AEBA353AAULL, 0x473007FFB4C539A8ULL, 0xD3B53E511268F19BULL, 
            0x10DF52AAA877D963ULL, 0xEC5E62F34BCA6408ULL, 0xC5CF8339CAB385F0ULL, 0xE77D664C1BD8F74CULL
        },
        {
            0xB60543E8057FD5F2ULL, 0x986442EA289FA957ULL, 0x0838C7EADB135F30ULL, 0x2B3CCD0F3E03EB7DULL, 
            0x55CD1F113AF9E7C8ULL, 0x3C244D5DE5720349ULL, 0xB25EF5006EDC3431ULL, 0xCCF9BF5D6B734D18ULL, 
            0x29730CD2075E314EULL, 0x8F8A704C2C6A332AULL, 0x73363863278C58B5ULL, 0x62E6D7A38200D1DBULL, 
            0x829D5B6B83E7965EULL, 0xF38A2967228099FAULL, 0x9E65F27BD8760D4BULL, 0xE43FA68F447BA497ULL, 
            0xD9200B45041081DEULL, 0xD944DD3BEA933F8CULL, 0x9A2E69B7A03BD82FULL, 0xE0965260DFA8E92BULL, 
            0x647A55151629DF88ULL, 0xF9BCF1E188D2E67CULL, 0x84A12A394F236FA2ULL, 0xD699DFF02DA15122ULL, 
            0x8BF9C9CA524CF15FULL, 0xC33E3B902CB485E3ULL, 0xF434147E356AE59BULL, 0xE60CEDF8DE97743CULL, 
            0x8865D54EA154B920ULL, 0xE9AA5484C7E25806ULL, 0x8CB0EC5FB61D3958ULL, 0x6C00C94CA7429134ULL
        },
        {
            0xAF0AE9F611AF6F03ULL, 0x90EA3B9467989969ULL, 0x84B38C4A5B37C5B0ULL, 0x3B25AB3BF1D6BA66ULL, 
            0x1971BF40306FB76AULL, 0x7CA0D85C51AFDA37ULL, 0x7ACB7E253660F4FBULL, 0x29F8931E0A936DEAULL, 
            0xB528A0DDAB7DB0B4ULL, 0x785E84EA4B52F2C4ULL, 0xF0A5C5F3E8273528ULL, 0xDBF2ABCB549CED0CULL, 
            0x00346CE51CB24951ULL, 0x91744F5F736209CBULL, 0xBE55F327BFC2F3A6ULL, 0xD33CBEB7418CDA86ULL, 
            0x09A52EBAA9AA532BULL, 0xF043A8EC8AD9C5E9ULL, 0xA70AA6AEF91A4780ULL, 0xF9B3CD16A6896800ULL, 
            0x311D15E3861DA38BULL, 0x9D12A408C8B3EA09ULL, 0xD02823CBB920E7CAULL, 0x6BB8250B568F2545ULL, 
            0x2481FF693BF598C2ULL, 0x2507AC7F1846CE8CULL, 0xACE31364DCFC3705ULL, 0x468987993C8F5D5DULL, 
            0x3E68460D6A21A2B4ULL, 0xAA06D03C4A00B5C6ULL, 0x8F325DCE5EB34441ULL, 0x2E3B3935C9380350ULL
        },
        {
            0x7FBE642ED9E34357ULL, 0xAE3E3D57D5069E6EULL, 0x41A30CA0C5D8F572ULL, 0x41E9CBC2E6710C7BULL, 
            0x5C1292791C439B39ULL, 0x13E32FE03C4C9E47ULL, 0x95BDADFCA21515B6ULL, 0xECC3D57FE95DE878ULL, 
            0xF715E8F5FE369BBAULL, 0xE6792DA5CB79C9CAULL, 0x4273B0456CE69833ULL, 0x62B98A89582B7AFFULL, 
            0xF96FF5FCF93A1623ULL, 0x7A7536C09A52B4E7ULL, 0x5EB586127E80324EULL, 0x47D7B797A86DBA62ULL, 
            0xBB37532F44268A67ULL, 0x6DCB5BC1B2C3C4B1ULL, 0xDFC37A95BAFA097DULL, 0x13586F22D267907BULL, 
            0x85055BE55B7DF351ULL, 0xC230B0FEF7620848ULL, 0x35BA936CEB6D0A1BULL, 0x542E779A419EEC68ULL, 
            0x1F1C03CB32FC65E2ULL, 0x08B658277A824A63ULL, 0xCF60ACA51ED56CE7ULL, 0xD9B2584B8136306EULL, 
            0x42CB90E78D24C217ULL, 0x11536275F440E7D6ULL, 0x4FDC2F2D3A31649CULL, 0x41CB93BF685ED15DULL
        },
        {
            0x745585C8DA6BAC40ULL, 0x26563D2EE05892E4ULL, 0x7F7EE3F177E6A816ULL, 0x3809EFB00B112254ULL, 
            0xB12E751F75948BBCULL, 0xF99612A053CE450FULL, 0x7D44F8AFCD8BF69BULL, 0x4DE818269B80022EULL, 
            0xB0054F7F3EBEDE9DULL, 0xDD466A96E15123E7ULL, 0x7F355189D59156CFULL, 0x6BF21545BD843585ULL, 
            0x8C392B48CF9B1C2CULL, 0xD9152A363C12E31EULL, 0x0DA9C556AE912E30ULL, 0x1475AC3E5CC23536ULL, 
            0xCF8BD36EBA5D7372ULL, 0x0B718A360B77A9D0ULL, 0x9ECA81B52BD98808ULL, 0x138288742877C6F0ULL, 
            0xFD9A3BE54873ED91ULL, 0x22923749CDF6559EULL, 0x850624DE0090A525ULL, 0x1B85DDC6634E2664ULL, 
            0xE82FCA9E71051480ULL, 0xFF3918A2A9D2B10AULL, 0x6E78C4F275EAEA20ULL, 0x0AC6391EFBC2C03BULL, 
            0xFEFD4AD28038252DULL, 0x29E3104AD187F6E4ULL, 0xD1FEB6939F350CFDULL, 0x0532365683644003ULL
        }
    },
    {
        {
            0x020EE735EDF96C00ULL, 0xF2AA357BCD7330B4ULL, 0xFE6A58139C09898FULL, 0x2BB5B2E563AE3082ULL, 
            0x07416535FF912002ULL, 0x12FD049056F802C2ULL, 0xECFE76F3DF6F9DB3ULL, 0x27723191AE45FD29ULL, 
            0xC604B52D1DEC8CE9ULL, 0x61AE61A6D285C10FULL, 0x3A17F04067F1114CULL, 0xFDD373F3951C2E71ULL, 
            0xDAF6ADA5D06907E9ULL, 0x9988F7CB7E8052EDULL, 0x4AB983FDACAF5F60ULL, 0x35DE02343BDAA951ULL, 
            0x2CD5E31F374DC5A9ULL, 0x7F5BC570CF113C4FULL, 0x2F1AFC45AF4C4958ULL, 0xE72E0F31365CC321ULL, 
            0x3D8B5452E883AAF9ULL, 0xA9BCB90DE7B75D10ULL, 0x65542DF698050C2FULL, 0x9D973DA7CE3892CEULL, 
            0x61324B85987C30D3ULL, 0x2FCF890AFBDCCA33ULL, 0x212E1C94C9E5D061ULL, 0xB7DA556CA84E9CE3ULL, 
            0xF83DBA45C9755D11ULL, 0xE60FF98DFFEADE53ULL, 0xAB1F398E5AB45BDAULL, 0xDCDCDAFFF27D71FDULL
        },
        {
            0xCBC91165FD9B0CE3ULL, 0x2371A5211ACBD9AAULL, 0x5F7844E2993325B4ULL, 0x9BFD76C4A641B3E8ULL, 
            0xC54EA17E105C8E30ULL, 0xF765E03C9F20DDD1ULL, 0x11EE93F240096B3AULL, 0xCAB4A64BAFF6EF45ULL, 
            0xEA765CB0B2DC1885ULL, 0xC40DF4BA43167ED8ULL, 0x0CE61476684AB965ULL, 0x616FEF2748D0A319ULL, 
            0x46B661262C309378ULL, 0x6286AD617693A08EULL, 0x2CAA8767E0438596ULL, 0x635662F8107438BDULL, 
            0x5CCCF23DB55BA828ULL, 0xAB0B141700978C9DULL, 0xD9FBDE4E7DAFF11CULL, 0x805FD69C40BA82D6ULL, 
            0x6FB98CDF1A4FC385ULL, 0x9E39E8A20A83D3CEULL, 0x3DB495113C08F601ULL, 0xF9F0CEBEA2B5987CULL, 
            0xA27D7112C335E032ULL, 0x321D8ECB925DB3FDULL, 0xF54B0CF7068E76A2ULL, 0x643B7DB94AF6F4FBULL, 
            0xCCF43319164DD2CBULL, 0x1923863FDC1FD9F4ULL, 0x908BD6FC52117ECEULL, 0x1096E746C439B671ULL
        },
        {
            0x0AC72483269E5566ULL, 0x3CD9FB8C030271FEULL, 0xE7C9F3F8515E385DULL, 0x567F9C236407A811ULL, 
            0xD2EB2E9B6C6AEAFDULL, 0x6B85A451DFB83224ULL, 0xC2E38482CAA94AD8ULL, 0x49B43381E3FAF4D1ULL, 
            0x75561D41C36BA279ULL, 0x309EE2F5D6C52E83ULL, 0x6C88E6AD4F746E14ULL, 0xAF2366EF65DA5906ULL, 
            0x2F7E6497CC587879ULL, 0x8A68EAE437CCE13FULL, 0x9CD22EDECBD21758ULL, 0x11F3C14C722C7810ULL, 
            0xA435A62D1478C79CULL, 0x3983EA01A30CC4DEULL, 0xEA4121D176B7B4A2ULL, 0x39593EB535802AA2ULL, 
            0xC5DC009ACDD79290ULL, 0x5167AA9AD8197632ULL, 0x71DD38B05ADA3461ULL, 0xBB36D4ED38594B57ULL, 
            0x47EA80EF00ED0201ULL, 0x99E636ADB52DBF7CULL, 0xACF9EA6740E02012ULL, 0x676306B7370DA91EULL, 
            0x700E69D2B60E8692ULL, 0x291BAB07DE9A5C3BULL, 0xBF7F5211D6172E5CULL, 0x132109DC7B291043ULL
        },
        {
            0x2C6506B7E912801AULL, 0x638A75B2F0747AE4ULL, 0x042240DFE7659481ULL, 0x29B727F3CA213014ULL, 
            0x6E81EE920F4B2C7FULL, 0x53D6D9787989EFD4ULL, 0x08C1DEEB17D7FFE7ULL, 0x93B7F2242E9AE050ULL, 
            0x3A2844308476BB0DULL, 0xAAA2281BFE20877DULL, 0x17C0E2555664ED54ULL, 0x13D7B3999260FA25ULL, 
            0x6032E34AA9B3D7A1ULL, 0x53E360B9F58F4D26ULL, 0xEF43679C92C16C56ULL, 0x0FB608F512C613ECULL, 
            0xF2FA49F3C4C99712ULL, 0x7CA135E44CA10378ULL, 0x4B5FD7C2D282F3E0ULL, 0xB18421D101F2CB39ULL, 
            0x91A16236D3F218BDULL, 0x168F35613B126CF6ULL, 0xC794B777AEE1993DULL, 0x0EAD76F49B6DDCC8ULL, 
            0x987376B81C7F3204ULL, 0x02F274C6BE206EE1ULL, 0xDEECE91A42284DD5ULL, 0x11D4F3AF40677DB2ULL, 
            0x33E105DCD9719AB7ULL, 0x5FD9E1B6DBD82E32ULL, 0x5B9998026FEFE755ULL, 0x51982FE92E74224CULL
        },
        {
            0xBC2F54F24F9F802DULL, 0x7915CCB7F9A33641ULL, 0xF66F672C58C1D7FEULL, 0x71343BA36DF47878ULL, 
            0x8C5034B64DD72416ULL, 0x0675325C0EB181F0ULL, 0x83D84D6FDB79742AULL, 0xF569C2CB0C5D84B8ULL, 
            0xA890A9B2E59281E9ULL, 0x0A63FE79BCFF537DULL, 0x4796563866E9F8D8ULL, 0x046AD4CC64056698ULL, 
            0x308D14296A50DE89ULL, 0x1445BACD25396126ULL, 0xAED4A1D31E7C46CDULL, 0x379A3C4C198F7E6FULL, 
            0xA7D84866C420140FULL, 0xC32BF9F0ECDC4515ULL, 0xD6CA8F7B68A100A7ULL, 0x45336E9F9C669521ULL, 
            0xFED3377B10E80FDDULL, 0x2668DFD8E79DA494ULL, 0xC1CC17FA5CA8EA07ULL, 0xE749A9E65E805E88ULL, 
            0x762FC7E28F9A6D46ULL, 0xE33BB6AD2DF87D01ULL, 0x5E263948E8CA195EULL, 0xFABF015F07DF00F4ULL, 
            0xC03199B5F973E21BULL, 0xC245393D07A9964BULL, 0xD8C435D476062229ULL, 0xB070443F71D8D4B5ULL
        },
        {
            0xCF2C2973768CFA6BULL, 0x651C7CA838D0B516ULL, 0xD38FB12B46D81BD8ULL, 0x72F8AF9D70103B03ULL, 
            0xB88B3986F2537ED5ULL, 0xF83C27F247E062EDULL, 0x80C26AC6FE9BD457ULL, 0x7AC99517D9D9E557ULL, 
            0x983A3C124BD98311ULL, 0xA67B7E278420D1BDULL, 0xC6BAE128C8E62A94ULL, 0x0AD796066DF861A5ULL, 
            0x8F4F23578770BBA4ULL, 0x25342EF053639742ULL, 0x62FA1BBE7AB0D4EEULL, 0x4BB17B9D02C5A354ULL, 
            0x39B8F7670DE6FB31ULL, 0x2E615BE94C0C667DULL, 0xC8171593746055F5ULL, 0x8396B4A8EDE61458ULL, 
            0x40E85CFDFB4998B3ULL, 0x33EA8243827635B4ULL, 0xFE314FB0EBBF6280ULL, 0xFA544771E0A05499ULL, 
            0x28072E60365DBF33ULL, 0x6E181D53A7583EFDULL, 0x039CA48DD5F97D48ULL, 0x91505E1858382662ULL, 
            0x4F696786F2E47999ULL, 0x1408D1596D8AD7F7ULL, 0xF2CA0571CDCEE49EULL, 0x0599F2DCE5075D78ULL
        }
    },
    {
        {
            0xC8926880E6640F59ULL, 0x8935187579E4C05DULL, 0x4F051E428B39AD97ULL, 0xE23B8FE508CF2F62ULL, 
            0x165CD8960DAE5351ULL, 0xEE2007C2CD8DD1CBULL, 0xE54069A0744A0CC1ULL, 0xC000B110051BDDBFULL, 
            0xD28EAD34A0E2D89AULL, 0xFD0DBEC5ABDE5B5AULL, 0x5F5702CC3E331F0AULL, 0xB51EC390F4E3CEC8ULL, 
            0x9F4F2E23798A94C9ULL, 0x7143E6757AFF8517ULL, 0xA6EF11B9F6CC63EBULL, 0x2739767DA1D11B1DULL, 
            0xCE8749F4165BCDC7ULL, 0x307289C69206328FULL, 0x226A70C79922B0B7ULL, 0x9DDA21383C40322DULL, 
            0xE6C3CE8090E6D951ULL, 0x429B9CFCC1585023ULL, 0x82DC58F26FE1A9D7ULL, 0x9B73915A69245A27ULL, 
            0x378A9F3FCB0A1A32ULL, 0x5DA636DB2CDE5749ULL, 0xE5F433D55D241615ULL, 0xB329ECF73405AAF0ULL, 
            0x171AAAC06F0C6008ULL, 0x10D4057DFAC623EEULL, 0x051A73766259CBA1ULL, 0x0DAE8E3B5C1F67E7ULL
        },
        {
            0x62AE260EBBB66E0DULL, 0xF9A2C6E2F3DBBB4FULL, 0xA06C3F4A44975A8DULL, 0xCE39D059BFA348CBULL, 
            0x286EAC95AE573E0CULL, 0xCED05A991DB16CF9ULL, 0x992A4B2BA2E1DE51ULL, 0x6317DF724E16A844ULL, 
            0x6B47910D2CBACE10ULL, 0xE56A981FA0E41ECFULL, 0xCE350AC447504134ULL, 0x9E3330571E655484ULL, 
            0x82C2B8F0E30CFCC0ULL, 0xBC5859CF93E40FD0ULL, 0x52726DC2A728956CULL, 0xB4BE5E361C5E30F5ULL, 
            0xE0EBCC8DCF59FB2EULL, 0x8ACB2CEC6926E742ULL, 0x933CFC002FDF8396ULL, 0xDC1F9F129463C527ULL, 
            0x6C7BBB5A0A5D48C3ULL, 0x8A6735847A39AA30ULL, 0x6A2BFF0B212A5ED5ULL, 0x16AA440B6471D220ULL, 
            0x7321D8BDFAE314D2ULL, 0x8EBFD423943DD334ULL, 0x17EF52A32E9D2530ULL, 0x6F8135BA6E928202ULL, 
            0x35162C3D34506444ULL, 0xD76E30AB09EA2D68ULL, 0x99A65B1B66371BADULL, 0xCBAD923BF837708BULL
        },
        {
            0x51B4A507C72F137CULL, 0xEBC2B7D892688BC6ULL, 0x40CF56DF464AE915ULL, 0xA80F28129D3D51FEULL, 
            0xDE8EBA6115A9B157ULL, 0x026A72DAA7A633C6ULL, 0xA170C5B6F237EA7DULL, 0x4F7E647E8142FD2FULL, 
            0xE236B17989C16C40ULL, 0xD961C10BB0242B93ULL, 0xBE360806A0F67818ULL, 0x93A8B1E22DF60945ULL, 
            0xF4012E512D76E8C8ULL, 0x76139FE6A8E2F6BEULL, 0x962C9DFC6A90FF93ULL, 0xA3CF3F079BE674C2ULL, 
            0x1E58C33D647A9170ULL, 0xB64C0DA13110FACFULL, 0x2BAA575B0E1DDD64ULL, 0xCEC62B35D45742D1ULL, 
            0xF426D2DD7CBFE3A2ULL, 0xF13EE42F2BCCC772ULL, 0x95344DEFD4C2D6AAULL, 0x73E800206A195D00ULL, 
            0x814579A605A9DF03ULL, 0xC43800D7946847DCULL, 0xE648CEEF0E1BBB5BULL, 0xB9DABCE0F8AC2732ULL, 
            0x7924F94EE489EC37ULL, 0x924B88413D54D2EAULL, 0x12C586DF2E6950DAULL, 0x219ACB9BC533E770ULL
        },
        {
            0xD6E024B4D30250CAULL, 0xDFE19D4E8A775BAFULL, 0x80E4465051AA64F9ULL, 0xE6D4218FD3486E99ULL, 
            0x74F40A0E7D4D7C7DULL, 0x4C5C1065C5637BD5ULL, 0x49684D8CAF6655B5ULL, 0xC708354961E88748ULL, 
            0xF936279B05FF0311ULL, 0xE20B711AC929048BULL, 0x579D8DF288F4C23BULL, 0xCB7C5F0D1EC8C69DULL, 
            0x9B7FA86CF0B529FEULL, 0xD50421E522EDA601ULL, 0xB0389ACDB6742A7EULL, 0x1FB216DBBE69398CULL, 
            0x037BE42749E44876ULL, 0x8450F5404A9E4337ULL, 0xF6144122F4F39D1FULL, 0xBE4C8444E1E11DF2ULL, 
            0xA84A605222F2E179ULL, 0x306726060324005EULL, 0xC9B7127594B21A42ULL, 0x250D4C5EEDE28DDEULL, 
            0x924FE03548C4AED8ULL, 0x8B54A6C890A834AFULL, 0x2FCC7EA13A23C4E5ULL, 0x93A57164DF8D463DULL, 
            0x05C7A1267F5D1C77ULL, 0x5260C5E45279AC4DULL, 0xFC46407A55B7A685ULL, 0x186A3E4F347094BAULL
        },
        {
            0xD4B9DE32584C28FCULL, 0x4F96FC165A0304FEULL, 0xD3F6E5D5C393E2CEULL, 0xB644D806CD570A63ULL, 
            0x979C15C3DC4ACB8BULL, 0xF97A8B03D7C6DC4EULL, 0xCBDF3784128A4057ULL, 0x1CD2911383D3E10DULL, 
            0xA83538B8D29F78D4ULL, 0x71850A0AF85D99F4ULL, 0xEF39112919DC3A31ULL, 0xC93F7EF762C3B273ULL, 
            0xC43ECFA3E6C664B2ULL, 0x09E6A80F315DD08DULL, 0x187A8FA1D68428E9ULL, 0x3F56550F14607EA5ULL, 
            0x19A374CC6512B0FEULL, 0x65777F0A99BE19FAULL, 0x9CA6C2D32D703167ULL, 0x0428DD543E31DC14ULL, 
            0xA3EC99B98745A3F7ULL, 0x0A2C41E4670A4384ULL, 0xEFE52B54960634C3ULL, 0x79CF10521CB35E8EULL, 
            0xFA66882407B8E747ULL, 0x90231FD7592CE537ULL, 0x9A006FB93B85BF71ULL, 0x4E3301C017B09D5EULL, 
            0x13403AB196A58F9FULL, 0xB6A1C06D167290E0ULL, 0xC370B5E77F79279BULL, 0xD46B5D98C7752F16ULL
        },
        {
            0x9C5E7D800AA0B46BULL, 0x2564E932F8889300ULL, 0xB4D65FBEBC7066C1ULL, 0xE3BE09D4F173F4F0ULL, 
            0xE0E146C66299103FULL, 0xFF9974DE2F400246ULL, 0x134CBF8243DB2DD1ULL, 0x2A55B2D001C07567ULL, 
            0x4F8CACED460243FEULL, 0x10B49B5A1A0B0946ULL, 0x5868291A7FEC92D2ULL, 0xA8A597FAD2411228ULL, 
            0xCADAF509DAD75BF3ULL, 0xFB500049389D399DULL, 0x22761C67E696784BULL, 0x6164D5C218245BE5ULL, 
            0x0C96ECF77542888BULL, 0xAF81E79A5F40FC29ULL, 0x530162E3933B8ED0ULL, 0xFC31179EE1F1B78CULL, 
            0xF8D43E54AABCA387ULL, 0x2EF5965214B1B608ULL, 0x74EDC3B9CEA9FE9AULL, 0x341CAB3707481E9FULL, 
            0xB1E9AB9D0430BC12ULL, 0x5FC99758B6E8896BULL, 0x9D7AD097B01D2302ULL, 0x19ABC9D7FB1E6983ULL, 
            0xA0EBE54F0A8778F9ULL, 0x0AA8FC2A2F276688ULL, 0xB4EE10F596632F40ULL, 0xDF16E1204631EEE8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Rigel::kPhaseDConstants = {
    0x2DC9BA39CB415021ULL,
    0x1FD705390C01C841ULL,
    0x4061278B947EBB69ULL,
    0x2DC9BA39CB415021ULL,
    0x1FD705390C01C841ULL,
    0x4061278B947EBB69ULL,
    0xC31E4A7D354778F2ULL,
    0x77F03FC2313EEB59ULL,
    0x99,
    0xF3,
    0x0C,
    0x5D,
    0x70,
    0xBB,
    0xFF,
    0xE5
};

