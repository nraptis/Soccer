#include "TwistExpander_Mebsuta.hpp"
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

TwistExpander_Mebsuta::TwistExpander_Mebsuta()
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

void TwistExpander_Mebsuta::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF0076D12BD4C194DULL; std::uint64_t aIngress = 0xAE81ECA4998EC76CULL; std::uint64_t aCarry = 0xA4A8F0FDCE8646DBULL;

    std::uint64_t aWandererA = 0x9D1491BCEC8F98A3ULL; std::uint64_t aWandererB = 0xED3C730FAFBB5A19ULL; std::uint64_t aWandererC = 0xB6A12F6D2909A29FULL; std::uint64_t aWandererD = 0xF36280915F7D85BEULL;
    std::uint64_t aWandererE = 0xF59C465DC33FEECAULL; std::uint64_t aWandererF = 0xCA11C73494064FCDULL; std::uint64_t aWandererG = 0xCFFAE47080B1BFF4ULL; std::uint64_t aWandererH = 0xC2FD7FB5A8678D0EULL;
    std::uint64_t aWandererI = 0xFAB7ED9E859ADB8FULL; std::uint64_t aWandererJ = 0xEBBE5152B7573B5DULL; std::uint64_t aWandererK = 0xC4F2BABFE9EAE5CEULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xF4FC74D3107E59BCULL;
        aCarry = 0x9CFA06D05B9A83CAULL;
        aWandererA = 0x8E1AEA8112A47E9AULL;
        aWandererB = 0xDC34FECBAB3D8594ULL;
        aWandererC = 0x9B7AF7CA3B6401D3ULL;
        aWandererD = 0x944633AC5883E8ADULL;
        aWandererE = 0xCE81802FD5B49079ULL;
        aWandererF = 0xAE176C361AA9D4C8ULL;
        aWandererG = 0xE1A72DB2580AFF4AULL;
        aWandererH = 0x8549876DED822BAEULL;
        aWandererI = 0xBF622242CABDB4A9ULL;
        aWandererJ = 0x82739274F09B1CFEULL;
        aWandererK = 0xF712759D9A3D3A37ULL;
    TwistExpander_Mebsuta_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Mebsuta::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF8FDE384E4BF9938ULL; std::uint64_t aIngress = 0x83E3395C9B37B44EULL; std::uint64_t aCarry = 0xFDB1221D5233542DULL;

    std::uint64_t aWandererA = 0xE839D95824730475ULL; std::uint64_t aWandererB = 0xBD97195973D60D3DULL; std::uint64_t aWandererC = 0x9E68DBBD6F5E5289ULL; std::uint64_t aWandererD = 0xA773F97F02D59F1CULL;
    std::uint64_t aWandererE = 0x8F7E9A89784E491CULL; std::uint64_t aWandererF = 0xA62898337A57D285ULL; std::uint64_t aWandererG = 0x8BF588C099BCAFE8ULL; std::uint64_t aWandererH = 0xB640458ED89A9EA2ULL;
    std::uint64_t aWandererI = 0xE250812D7C6EA512ULL; std::uint64_t aWandererJ = 0x85E842B7BA8CDF9DULL; std::uint64_t aWandererK = 0xCADF987316F10EB2ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xD43BA20FD536C802ULL;
        aCarry = 0xC74E75E6C1F88EB7ULL;
        aWandererA = 0xD53643EBE566EB37ULL;
        aWandererB = 0x9BC1A8CFD105C01BULL;
        aWandererC = 0xB0A0F461AC4A1B78ULL;
        aWandererD = 0xD05F71822F8BC011ULL;
        aWandererE = 0xDBF1574C30602819ULL;
        aWandererF = 0xCE72217C1FAE48FAULL;
        aWandererG = 0xC904A9CE09294E51ULL;
        aWandererH = 0xF17B07EFB432328DULL;
        aWandererI = 0xA7B24660E5120473ULL;
        aWandererJ = 0xB5306049DBAD991EULL;
        aWandererK = 0xFB1D218F469FBC10ULL;
    TwistExpander_Mebsuta_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Mebsuta::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB6080AF94029FB54ULL;
    std::uint64_t aIngress = 0x99D1B5C4D0434C6AULL;
    std::uint64_t aCarry = 0x9BD29F730A15AEE3ULL;

    std::uint64_t aWandererA = 0xAD350524EB36066FULL;
    std::uint64_t aWandererB = 0xCFA435114FFAAA76ULL;
    std::uint64_t aWandererC = 0xAA0EDE69378F39CBULL;
    std::uint64_t aWandererD = 0xF0548FF5457FEC28ULL;
    std::uint64_t aWandererE = 0xC76D2A5AD2D0E5EEULL;
    std::uint64_t aWandererF = 0xE9E0DD0FCDF957E8ULL;
    std::uint64_t aWandererG = 0xC52F84AF1AB4CD94ULL;
    std::uint64_t aWandererH = 0xA94F3163F425DDC3ULL;
    std::uint64_t aWandererI = 0x85E07E2E5CDB6FC7ULL;
    std::uint64_t aWandererJ = 0xC376C558DD8AE981ULL;
    std::uint64_t aWandererK = 0xD205C1C7FA0C11FFULL;

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
    TwistExpander_Mebsuta_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::Seed_H(pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::GROW_B(pWorkSpace,
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

// SmartSquash candidate 17 of 33
// Exploration cases: 100000000
// Nearest-family diversity: 929 / 1088 (85.39%)
// Total distance from earlier candidates: 15025
void TwistExpander_Mebsuta::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    static_assert((S_BLOCK / W_KEY) == 16, "SquashInvestToKeyBoxes expects 16 invest fragments.");
    static_assert(H_KEY == 8, "SquashInvestToKeyBoxes expects 8 key rows per box.");
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 3U), *aFragmentB = aIceLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 12U), *aFragmentD = aIceLaneD + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1073U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1989U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 723U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 297U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 10U), *aFragmentB = aIceLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 9U), *aFragmentD = aIceLaneD + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1835U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 527U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 21U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1411U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 15U), *aFragmentB = aIceLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 1U), *aFragmentD = aIceLaneD + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 901U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1803U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1018U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1080U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 4U), *aFragmentB = aIceLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 11U), *aFragmentD = aIceLaneD + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1202U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1831U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 848U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1231U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 2U), *aFragmentB = aIceLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 8U), *aFragmentD = aIceLaneD + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 545U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1679U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 608U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1383U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 5U), *aFragmentB = aIceLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 10U), *aFragmentD = aIceLaneD + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 990U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 207U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 509U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1967U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 8U), *aFragmentB = aIceLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 15U), *aFragmentD = aIceLaneD + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1472U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 539U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1270U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 793U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 13U), *aFragmentB = aIceLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 5U), *aFragmentD = aIceLaneD + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 81U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 163U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 87U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 234U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 1U), *aFragmentB = aIceLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 2U), *aFragmentD = aIceLaneD + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 412U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 133U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 2020U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1385U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 6U), *aFragmentB = aIceLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 3U), *aFragmentD = aIceLaneD + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 303U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 645U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 235U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 329U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 12U), *aFragmentB = aIceLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 0U), *aFragmentD = aIceLaneD + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 846U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 638U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 188U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1864U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 9U), *aFragmentB = aIceLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 7U), *aFragmentD = aIceLaneD + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 440U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1427U) & W_KEY1)]) << 16U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1839U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 391U) & W_KEY1)]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 7U), *aFragmentB = aIceLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 4U), *aFragmentD = aIceLaneD + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 947U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1175U) & W_KEY1)]) << 24U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 442U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1016U) & W_KEY1)]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 14U), *aFragmentB = aIceLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 14U), *aFragmentD = aIceLaneD + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 607U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 28U) & W_KEY1)]) << 0U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 355U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 94U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 0U), *aFragmentB = aIceLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 13U), *aFragmentD = aIceLaneD + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1961U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 26U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 501U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 722U) & W_KEY1)]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 11U), *aFragmentB = aIceLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 6U), *aFragmentD = aIceLaneD + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint32_t aSquash =
                (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1596U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 324U) & W_KEY1)]) << 8U) |
                (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1490U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1136U) & W_KEY1)]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
        }
    }
}

void TwistExpander_Mebsuta::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD2CB7B18F7E524F6ULL; std::uint64_t aIngress = 0x83C2A78604FD72A0ULL; std::uint64_t aCarry = 0xE07880AB1E2B7F19ULL;

    std::uint64_t aWandererA = 0xD617161B03F1BEA3ULL; std::uint64_t aWandererB = 0xB6C7A501D8A18926ULL; std::uint64_t aWandererC = 0x80DC555B0B8D2572ULL; std::uint64_t aWandererD = 0x950506E421E00235ULL;
    std::uint64_t aWandererE = 0x8F520AFCB947E321ULL; std::uint64_t aWandererF = 0x99BB82A4502BA4C5ULL; std::uint64_t aWandererG = 0xF10AFC36CB838C1AULL; std::uint64_t aWandererH = 0x9017CD35269957C0ULL;
    std::uint64_t aWandererI = 0xDEE42341F44E2BC3ULL; std::uint64_t aWandererJ = 0xB6340657CB4D6B56ULL; std::uint64_t aWandererK = 0xBD2116F2DEA0A6C9ULL;

    // [seed]
        aPrevious = 0x9512A722FAFB8980ULL;
        aCarry = 0xA72D03A5D18F0940ULL;
        aWandererA = 0xD8D2701DFB72ECD6ULL;
        aWandererB = 0xF1A52E772A104685ULL;
        aWandererC = 0xCE22FE6F8AF5D8A1ULL;
        aWandererD = 0x9EA6D6181B91D113ULL;
        aWandererE = 0xC13FC63EFC49658FULL;
        aWandererF = 0xC4A699776ED95C30ULL;
        aWandererG = 0xC4348387BB1CDFE8ULL;
        aWandererH = 0xFCC41F9CC4158D37ULL;
        aWandererI = 0xB93D33573FB4B618ULL;
        aWandererJ = 0xEB64016AA56A1209ULL;
        aWandererK = 0x8A50202C05EEE7E8ULL;
    TwistExpander_Mebsuta_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Mebsuta_Arx::Twist_E(pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::GROW_A(pWorkSpace,
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
    TwistExpander_Mebsuta_Arx::GROW_B(pWorkSpace,
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

// GrowA candidate 17 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 8729; nearest pair: 500 / 674
void TwistExpander_Mebsuta::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3504U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6253U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3360U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 340U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 538U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2518U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6906U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3471U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7363U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7797U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5861U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5073U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5894U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2054U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4605U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5252U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 763U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1290U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1858U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 265U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1744U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1820U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 681U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 510U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 909U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2042U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 928U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1556U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1550U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1536U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 64U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1892U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 598U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 687U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1701U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 83U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
}

// GrowB candidate 17 of 33
// Exploration cases: 100000000
// Total structural distance from earlier candidates: 8738; nearest pair: 486 / 674
void TwistExpander_Mebsuta::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4009U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6167U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4150U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2883U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6740U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2932U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1900U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWaterLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6663U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4840U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6366U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7263U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8005U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6484U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7233U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2188U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWaterLaneD[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1795U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1687U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 489U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 642U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneA[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 248U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1439U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1914U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 327U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aPoisonLaneB[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1540U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1532U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 461U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1445U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneC[aIndex] = aFoldWord;
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 266U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 90U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 647U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 628U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aPoisonLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 952U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 8U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 884U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 925U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
}

const TwistDomainSaltSet TwistExpander_Mebsuta::kPhaseASalts = {
    {
        {
            0xD60EA15023667620ULL, 0xE5B168E5A4C7CA96ULL, 0x2EA533C8E22A1FC5ULL, 0x0EFB11F36C93F8D5ULL, 
            0xF06DEC73308C8155ULL, 0xE6E020AE7C2CBA5BULL, 0xBF7673EE4AB8345CULL, 0xC7A7D30787FB2332ULL, 
            0x3FC4B7D5E7C81D95ULL, 0xA7D818C12FEB2E46ULL, 0xF59AA0B57EF3B15AULL, 0x36C8F345232390EAULL, 
            0xFAC53FBB139F4EFCULL, 0x73353E7849E8FA86ULL, 0x2E56A7884E18BD51ULL, 0x85F6E865339D7733ULL, 
            0xC2635150F2881BD1ULL, 0x5A5ACFA6CC9CC9B6ULL, 0x3BFBBDEA2927B9EEULL, 0xE2BDAFE62AB3713BULL, 
            0xF74C655F7EA99A85ULL, 0x3C6252C80A7C1222ULL, 0x8F473EC86C0C26B3ULL, 0x82E1B50F8F1FE8ADULL, 
            0x3AF91512ABB28FC8ULL, 0x1987078311A3BD90ULL, 0x26850792EB056B68ULL, 0xD27CC1B933B11CA2ULL, 
            0x7416F2799B3B2AFCULL, 0x3D4F9BB539CF5451ULL, 0x7FA8137B243C7B74ULL, 0x35AFEB6E89257053ULL
        },
        {
            0x18013A85C2977F89ULL, 0xB60D846C3A6D8309ULL, 0x612592458A123E8CULL, 0xC7864D30BCF39965ULL, 
            0x879D328DE92B6D61ULL, 0x6BB76800A16178BAULL, 0x181B828D18057654ULL, 0xF597CAA5EDE44B6AULL, 
            0xA5D62A68CA783EFFULL, 0x74C9C1CE16B8C4A8ULL, 0xE344409AF9FD3F09ULL, 0x5F9795B2608773EBULL, 
            0xAEBDC4A369209C7DULL, 0x12ED39F910201646ULL, 0x818407C64CB0F10AULL, 0x2B7CD69CCD012895ULL, 
            0x551E1B9C63B63386ULL, 0xD0A725C425E5E88AULL, 0x9A079F03C3350D71ULL, 0x4BDF2296137553C0ULL, 
            0x9AA2B22CB8C98203ULL, 0x9C2A4E7B74934178ULL, 0x806D46E8788EBDE5ULL, 0xE1539C479AA858D7ULL, 
            0xDAD95C8FACA806ABULL, 0x4AE0C267A69B9023ULL, 0x19718671ED33F69BULL, 0x13AF432A04929D23ULL, 
            0xEAAB26B3838B8FA6ULL, 0x29F9603A4E0E18B0ULL, 0x4905C47989D3E505ULL, 0x74A8E6107E65E8C8ULL
        },
        {
            0x823001340424721FULL, 0x665C8927A46BFA9AULL, 0x85B661A2BC0B9E04ULL, 0x0B0F34C106714AC5ULL, 
            0xBB658F5326199544ULL, 0x5C3A62CFFC78A3E9ULL, 0x6F27712BFBEAFC63ULL, 0x0B29F33F69E1B57DULL, 
            0x00C0380855C5AFC6ULL, 0x648B3817A3E818FFULL, 0xF581C127A358421BULL, 0x3EC8D927986A2DEBULL, 
            0xF304CB0D90A1FBB6ULL, 0x9B9FD66D828A2F71ULL, 0x64083B98D8372F5BULL, 0x3204A4F1B43928F8ULL, 
            0x236EA629E5196007ULL, 0xFC7BE6E98EF2B72BULL, 0x1272F58B0B675732ULL, 0x1542FB01406123FDULL, 
            0x673D884ABCBF96E7ULL, 0xFB622345E3436F22ULL, 0x13A561B94FF2D7B2ULL, 0x584C13CF98C34974ULL, 
            0xC9E157B757EEFCFBULL, 0xB7746EB3569DD475ULL, 0x023426BF6D4A73A8ULL, 0xD19C915F73238783ULL, 
            0xE84DB4FA82DBA2BBULL, 0x7B5FE929AABF6906ULL, 0x0F11E657DC497D96ULL, 0x5F3FC7CBE0E61B14ULL
        },
        {
            0xB4A0F70065CAA0B9ULL, 0x04647FA1AAE37EADULL, 0xDA8353CB18A6AF4DULL, 0xAB78448AC2FD42D6ULL, 
            0xA58BDC8C5DA26537ULL, 0xCBA66C9E3162CECFULL, 0x550717D40D669281ULL, 0x7E192FE0C50215C0ULL, 
            0xC9D207AB7CFC1D57ULL, 0xEBA3200043EE1376ULL, 0x98633EE90FA9F979ULL, 0x09027224232FF81BULL, 
            0xB9CF52A87B5598CAULL, 0xE16DD09638451A09ULL, 0x80F6B9889CE24440ULL, 0x4F437A83DA5F8480ULL, 
            0xDD47EA7C552509A0ULL, 0x2E463B75763738F6ULL, 0x46324E0918C6B1D6ULL, 0x1CCBDA02A5E61C1EULL, 
            0x5272BFCF5A62A55EULL, 0x75C5B315F0646A4CULL, 0x3F7DEF60FBC7DDBCULL, 0x1E6D8DB3B98E96D9ULL, 
            0x76F8350948CFE27AULL, 0x7EBE1F2AABE2AB0CULL, 0x282A90A0F92A8677ULL, 0xD3BA74B3BA83E341ULL, 
            0xF06F953D2DF9BDCBULL, 0x559057675E636925ULL, 0xF2B4DAAFD72B576AULL, 0x6681A1ABB5500E84ULL
        },
        {
            0x1C71F7558A285B9CULL, 0x86654F82E3D4CA00ULL, 0x004511BB483F7455ULL, 0xE0A891E1C5053695ULL, 
            0x09390EA02B4694C1ULL, 0x79ADDA2A8FDBCC49ULL, 0xE9F51C633F1C7140ULL, 0xEF7CDCAB4478E289ULL, 
            0xE0CB0DEAE0604475ULL, 0x5D9DB6D13106EC16ULL, 0x3B83EED681FBBDA9ULL, 0x3A4D9E2DA608989BULL, 
            0x0939846CB54DC10CULL, 0x529924107EB01D96ULL, 0x039CF792AAF396B7ULL, 0x6D9EE48F1CA39E40ULL, 
            0xEDBF6567B367B4E4ULL, 0x49B260AACF867B9CULL, 0x9D69FE5BA3A8F19AULL, 0xC5A9C06261A42B64ULL, 
            0xAE1A98D7A6356EDBULL, 0x24CEF1734D9745EDULL, 0x355295927B3B2AD7ULL, 0x138605D0E67A0920ULL, 
            0xAA71306A8B7B9AB9ULL, 0xC373D449ADD5BD1FULL, 0x8E35F76BB7A8E5EDULL, 0xD53328CFF1C1F0B1ULL, 
            0xC4EAB1952FB9B369ULL, 0xFFBEFBC5DDF311A1ULL, 0x373714C31410BB14ULL, 0x0B5CE39A48EB44E8ULL
        },
        {
            0x3E25C80FFC34D7F7ULL, 0x7B1397A6BAC6F87DULL, 0xE6040050536E0DD1ULL, 0x257664F7248D1A4DULL, 
            0x016524D0CF39E375ULL, 0x372096568AB0B29CULL, 0xBAD03966359D290AULL, 0x581E68FF3DBCBEDEULL, 
            0x7601038A512DD4DBULL, 0xAC01988F8B038AE6ULL, 0xF574ACEBC00ADC38ULL, 0xB8E2664E8BC91728ULL, 
            0x4B0D41E59DCD90ECULL, 0x7CE4E98DFEB9C8E5ULL, 0xC509193D0DE2F528ULL, 0x5831F89C60B548C1ULL, 
            0x2187F86E48D58CE6ULL, 0x150B121AF5E5FC3DULL, 0x3C0FA0B2436F8038ULL, 0x1F9285855111391CULL, 
            0x5EE35D3D5E1701D1ULL, 0x22CE3204868515DDULL, 0xBD29F8575555ACE6ULL, 0xA6125F23A7837969ULL, 
            0x0A65A500737DF792ULL, 0x4D32774603C6D7BBULL, 0x6194810CEBDF9C69ULL, 0x399620CEFC413D99ULL, 
            0xEABD862C5B90CD04ULL, 0x4F9B21CF4F1CD132ULL, 0x2504BB57BB2862EAULL, 0x2476E7BB9D36188EULL
        }
    },
    {
        {
            0x750E9ED30FE99723ULL, 0x3D42F836EF7117E9ULL, 0xCB13C06EE7B857C1ULL, 0x9C6654F9596B4FCBULL, 
            0x89F20ABF8BD5504AULL, 0xB8474D82256D1E62ULL, 0x52C6AC2D22389D16ULL, 0xB88462F0CCA85CFEULL, 
            0xF94B907B7C1A7E97ULL, 0x94C935DD7E9054D3ULL, 0xADC25C21C4AEBD23ULL, 0x458A237A018AFA97ULL, 
            0x567B7B899140E537ULL, 0x94107F1226F37B0CULL, 0xB42BADD67A887721ULL, 0xC092897BCDFA67A8ULL, 
            0xD0222201EFC9187FULL, 0x8312C7D947FC0FC8ULL, 0x49324C2560C24CC8ULL, 0xC7968FEFEB6D69C9ULL, 
            0xE1C2AD431285857DULL, 0x6C5C3B9C4F226649ULL, 0xF620954FF4C35408ULL, 0xFC276F79DB581FC3ULL, 
            0x350A45EE55B0447FULL, 0xDF99A827922F511FULL, 0x0BEFC687F08024BBULL, 0x802D2AA99CE97CE3ULL, 
            0x23FBD9EF9A3F8521ULL, 0x19C6CE7AEB4D6D05ULL, 0xC76B6B4C1BFFF506ULL, 0x5E19B3A68DEB37F8ULL
        },
        {
            0x6FC026EFC1C60613ULL, 0xF10FC460E9EBDB5EULL, 0x66252593F15402A9ULL, 0x6D98B874B724C692ULL, 
            0xCD60EBD0E3E98A90ULL, 0x7BA017D0F454C3C3ULL, 0xF0214BAEB34D4EF1ULL, 0x55A2D68E1287537DULL, 
            0xAC45A5C5B4FDD39DULL, 0xCBDC709DE54805C8ULL, 0xBA934B5008834280ULL, 0x026CA4C5E1F37E71ULL, 
            0x527C07929FA3E5F9ULL, 0x18F5DF87391208C4ULL, 0x7630CC63870EF4F9ULL, 0xFED99CB7DDFD7D29ULL, 
            0xAB2C82AF2863018DULL, 0x5FB57592B6A1C936ULL, 0x21D9EE245B549AC2ULL, 0x28EC3FB08903E8E3ULL, 
            0xE927D0800A01CA70ULL, 0x62556390CBBF87FCULL, 0x77196F1758C79CEAULL, 0x0EB6DC363E3F94A1ULL, 
            0x449E9C4C917EA359ULL, 0xCC21798447581720ULL, 0xAD2880D5B459BD10ULL, 0xB6E0412D0BF447D4ULL, 
            0x13A43C33EFB7A915ULL, 0x5F15F452825D2A30ULL, 0x272F9E20555E2368ULL, 0xDD4C6767A09B2B80ULL
        },
        {
            0x209C0CDC42E0F425ULL, 0xFE58600767B3FA09ULL, 0x2BB64C52D4878CB5ULL, 0x1AED787C88A7537BULL, 
            0x4B3442E7CBF35870ULL, 0x86C01F9882F80B9BULL, 0x0B943B012235E1D5ULL, 0x9138EC7CDDC63B4EULL, 
            0xDF01288711F79428ULL, 0x5DC8D86D399F73A8ULL, 0xFBED2AF82C4C360AULL, 0x7FDD677A6BE1BB9EULL, 
            0x27A593D7DF4F42F8ULL, 0xA9239119EFA44C91ULL, 0x015A034F6C4F1FFCULL, 0x0B554DAF36463937ULL, 
            0x6BAF6444CF78518BULL, 0x216267383608C04EULL, 0xC23CCA3892BED2A9ULL, 0x283900DDD5D689EBULL, 
            0xBAE4077391E36B8DULL, 0x63FE64F03491448DULL, 0xE466BF192E35C206ULL, 0x0AD0BB563DC44662ULL, 
            0x39E9DA5FC0911750ULL, 0xC002645C87AB0129ULL, 0xF89C54D8061A1248ULL, 0x4CF58A42847AB6F8ULL, 
            0x9767CF5A2DDC3DA9ULL, 0x45DAF4834C2CA530ULL, 0x358C9D018FB6C37BULL, 0x7C485920D2B54597ULL
        },
        {
            0xBD1E8AF0C80DF973ULL, 0xA90394CA5A3A5C08ULL, 0x44DD676828486F1AULL, 0x974C883B3EB87765ULL, 
            0xB0AA1F17EE587E61ULL, 0x2AC775FFBD19A3CCULL, 0x9763908AB4ECF88CULL, 0x41180B072ECC1A16ULL, 
            0xDD868E2CDA972BABULL, 0x474E684B0D4D8F3BULL, 0xD672557DE16E5D9BULL, 0x499E1AC5302740AFULL, 
            0x948D2B603C16BBAEULL, 0x31BB1ECAF66A4C93ULL, 0x99157B596C65399BULL, 0x72A5CEB7B826E497ULL, 
            0x6F185E785EAAF29BULL, 0x5207350DB365E8CEULL, 0x8B2E7BD13DB092D1ULL, 0xB537E9634E47B791ULL, 
            0x8328B28749869580ULL, 0x90FD8FA13A596659ULL, 0x0D857DBE48716D30ULL, 0x846566D411406600ULL, 
            0xAE16602E47B2624FULL, 0x9FA03771433B0D44ULL, 0x7267679AB0B01858ULL, 0x6874E31A3D9B3286ULL, 
            0x7BBD907F7DF5CF8BULL, 0x3A3918974CA52E50ULL, 0x302194DDC5D11C8EULL, 0x4E59DAC3C7681890ULL
        },
        {
            0xC0C6CF05D7980B4FULL, 0xB2CF0BBE989496DAULL, 0x02C62B326C9C56EDULL, 0x6AF3C831A9ECCAB5ULL, 
            0xF12D6FE621013D5EULL, 0xC24806DADB8F739FULL, 0xB3CD18069CF4E207ULL, 0x7C8FA1DCD7BFE92BULL, 
            0x938CCA64E9409485ULL, 0x6A39C403E726967EULL, 0x65169509155FF7D6ULL, 0x84D462F2746F7BA6ULL, 
            0x95E72AAAE372B4CCULL, 0x0DB774543F0A803CULL, 0x8AC66F07CCA925DBULL, 0x5C50C1CAFCF84822ULL, 
            0x9EBBAEEFE50F3AC8ULL, 0x18C3C65D43D510C4ULL, 0xC180E4F115DFB7BEULL, 0x596EFF7A569213F6ULL, 
            0x6384FDAD533C207BULL, 0x329E0CF9E6F68785ULL, 0x1AE0A8B895A00539ULL, 0xE67CB80DC5638F54ULL, 
            0x159BFB1FC40EED81ULL, 0x1DE48E2FA82CC5CCULL, 0xAE359259F12CB6EFULL, 0x8EAEFF674DF7FA82ULL, 
            0x7574D9B24C88676BULL, 0x2CD7679432E0D5FDULL, 0xDD9EC05BFCF4C867ULL, 0x3E590A726A219DD4ULL
        },
        {
            0x830E93F44457C87AULL, 0x59528EE34E9286C1ULL, 0x872685935A4932EAULL, 0xE0A41CCF16167FC1ULL, 
            0xA21B5D26F8AFEDC9ULL, 0x9A6A7B31E6F33403ULL, 0x78F3BC6B066108AFULL, 0x04E4CF1D703B4A4BULL, 
            0x57E27CB0A05E450DULL, 0x291F89D77F8A550AULL, 0x4B3C6CD469CD5FE8ULL, 0xE144487A1269A0D5ULL, 
            0x06624A05FAE590B4ULL, 0x9FC998ED7E681DFBULL, 0x99BEEF7B323C0DA6ULL, 0xE704F988FC96CA61ULL, 
            0x22B2068F733B095AULL, 0x2359F41DD5E1736AULL, 0x1D7DCAD9345017E3ULL, 0x82A79007ABFD9238ULL, 
            0x37188C5F9AD66160ULL, 0xD6E7AD598D57A8FCULL, 0x3920BD34D538EE80ULL, 0x4C8D5D050B3159C6ULL, 
            0x1716E2CAE6321552ULL, 0xDABD7B1C7590569DULL, 0x3B9F2AC7EAD8638FULL, 0xCE63C68CBDD60A9EULL, 
            0x3480E67A78BDAC53ULL, 0xDC7833AD0E2B2552ULL, 0x5CDB604826C59BEEULL, 0xF58BD8FD57C7FAFFULL
        }
    },
    {
        {
            0x5F01731A6C52E811ULL, 0x12B2F2A9885B0F86ULL, 0x42743F37054E8AABULL, 0x46D7140832926575ULL, 
            0x8C5C6C18E30DD1D7ULL, 0xD6850E38F3E66E44ULL, 0x3C4A06E1D5BB7075ULL, 0xA9BE590A6F1306EAULL, 
            0xC5F59DF6CAF5555BULL, 0x5A7461BEF1F1E886ULL, 0xC4A1C1A1B40F7FB1ULL, 0x9B6F0006C0C3B429ULL, 
            0x29FE6CF0C4FFFAD6ULL, 0xB2E8CE6D6F3A6C31ULL, 0x1F2BD27F674A4EEDULL, 0x0B400AECB8DDAE3CULL, 
            0xF67E6A74891C8DD8ULL, 0xD79BEA52C1E21080ULL, 0xB29046B4D55B25CBULL, 0x0DC14D75D6984B94ULL, 
            0xEA4B8E81E2347112ULL, 0x31DB2032BF321A4BULL, 0xB8E9F093D9425923ULL, 0xE5C5DD56A3E97C7CULL, 
            0x16C33060D5C077D1ULL, 0x223345EFD9B35818ULL, 0xE6F4DEAFE5FD3DA6ULL, 0xF29A9429432A1914ULL, 
            0xF7D8CF6EA09A7B49ULL, 0x91EE7C80116C1191ULL, 0x7FED658D91898594ULL, 0x7EE3E2C840E081E5ULL
        },
        {
            0x153E9A4F77EEAF5FULL, 0x734ECC8E31C80E9CULL, 0xFD3916185C5746CCULL, 0x6A67D8CB2BA7AE75ULL, 
            0x8A8FCA53D6DF7974ULL, 0xDAA645B51E998686ULL, 0xB4D82FA7F21C54E2ULL, 0x2514B34054CB84E2ULL, 
            0xB4A99AB7C67DD5C6ULL, 0x60D6B85DC3A01C4AULL, 0xD63E8E1B04FF25F8ULL, 0x6E948FD794369B80ULL, 
            0x5F950B742171A8ECULL, 0x58357BD255C559C3ULL, 0xB29F2533B16DED74ULL, 0xDD19386606932866ULL, 
            0xDFB6FC9D8CB22F4BULL, 0x93BEC56FAFA34AA8ULL, 0xE5D0349C2A9C197EULL, 0xB7250B0BA021035EULL, 
            0x80EFC1801BB139D7ULL, 0xCD72B3FBC4FB615AULL, 0xCA5F3B57E0262D48ULL, 0x93BD93CB942B7375ULL, 
            0x503A9D9479B54025ULL, 0x61FD55C2DB85DC4BULL, 0x51B4130E4EBF8D28ULL, 0x0B83FE0CA2AAE104ULL, 
            0xA225B46CEAEF364CULL, 0x7404FD7EECA089DCULL, 0xC2A2045DC35B8F16ULL, 0x20FACDC461926DE3ULL
        },
        {
            0xFCD64C774241965EULL, 0xA2F8709FA1202EA2ULL, 0x45B98ED8F347BD0FULL, 0xB889A58BF7350B27ULL, 
            0x6649AB88DA1F1352ULL, 0x666FF4A69160051EULL, 0xC507947B585A3A7CULL, 0xF1C535E807A766F5ULL, 
            0x767FE50DF72AC19FULL, 0x7EAA34632C76E4E4ULL, 0xC6B49AFC729727B4ULL, 0xF66DEFC70E17B126ULL, 
            0x3D5DF0CE613756FDULL, 0x73F02FB3B3CCBA75ULL, 0x420EEA307EDD4CBEULL, 0xFD9F5AA9335961B9ULL, 
            0x61DC4AF3A1DB5146ULL, 0x183565BE5F0BE6A0ULL, 0xC5802727AAC74D95ULL, 0x1DBB68FF9DE037DAULL, 
            0x9814113FE4B5991EULL, 0x287AE6AF913CBB11ULL, 0xAAE284672039E51DULL, 0x5B8BEA5F4F953321ULL, 
            0xD196462EE1B36290ULL, 0xC685A0BFE1579FFFULL, 0xD50EF3D7DE352BDFULL, 0x928B05A39C92F3E2ULL, 
            0x360518F23E6F483BULL, 0xE85169CAFF25A099ULL, 0xFA2C80AC8F2595D9ULL, 0x16AA0899E5CA504EULL
        },
        {
            0xACA322596DB73F82ULL, 0x99FF1701BBA90C10ULL, 0x5D1387B32913734CULL, 0x6536E374CB7EFDD5ULL, 
            0x9DCB97FF632F8F76ULL, 0x030E274270E4D2DBULL, 0xEF5F11A6D1B4B7EBULL, 0x84431CE426827DBFULL, 
            0xB002C8C5BB9C9C95ULL, 0xD6A4C0CC1F4DF3BFULL, 0x57041850834CB5EEULL, 0x40CDA7C4007CCD62ULL, 
            0xFB0EA54FD32117DFULL, 0xC26519BEB878A815ULL, 0xBE278450A7229C01ULL, 0x2AE6D55C6D40D8A2ULL, 
            0xAEF555FDFBA1C6F2ULL, 0x46BBF84B7DAAFCCAULL, 0x9EC20B8630E45564ULL, 0x28353F958AFE205BULL, 
            0x4AD19B9B509B847FULL, 0xA3327F9DDA0BFD36ULL, 0x293FA0E7AE54ED2BULL, 0xB1BD59837D671309ULL, 
            0x9261A0E581A2B176ULL, 0x81CA2F7EB9045497ULL, 0x0F9F55D0FEDAF798ULL, 0xC184681DC06016D8ULL, 
            0x883FDAD81045A003ULL, 0x0134BAB53205A8CEULL, 0x7F59072DBFE9979AULL, 0xF841B72DE71941BFULL
        },
        {
            0x612114A0ED558F18ULL, 0xDCFBD948D33791A6ULL, 0x20FECB61B4CD7F40ULL, 0xFE338B47CE93396DULL, 
            0xC3FD284BFC59A371ULL, 0x45921678282BF4A2ULL, 0x1021B6D6B4118BE1ULL, 0x3A7F4478D6C12D9FULL, 
            0xEEA45A1FCA9B43E7ULL, 0x7364CA0641C8B311ULL, 0x8F3A64216B88E0D7ULL, 0x834F03DB8C100FF8ULL, 
            0xB3B8EA9A23F778E9ULL, 0xDB8C5A108864E3F9ULL, 0x3C419824FCF3CEEAULL, 0x8A4EB7D6C074C932ULL, 
            0x2B62049C9A9F38EAULL, 0xE85033F43993F9CFULL, 0xC80515D0710B046DULL, 0x606CD6840ECB1778ULL, 
            0x82CDF8AF18DAE560ULL, 0x966518D2E92AB865ULL, 0x2E7637B04903D8F7ULL, 0xCDE6C5077FB4D26AULL, 
            0xF86D1C7E3B71F9E1ULL, 0x0C60843399FDA91BULL, 0x004F021474F14272ULL, 0xA881473B096EA1D0ULL, 
            0x7CD15C707944FB2EULL, 0xD1FE67989F407E50ULL, 0xE0E0BAEC9E66E09CULL, 0x27F254D54F033A1EULL
        },
        {
            0x8FA0EDF58CA2F8C3ULL, 0x9E0D12774DBAE239ULL, 0x1E3551AB83CE6309ULL, 0x9E0D2570F400C8BDULL, 
            0x562227AC0E928FEBULL, 0x842602196A5E0363ULL, 0x551CD29E81AFB56DULL, 0x8EC7F495CE80C69EULL, 
            0xA9BED772E5FA9CCFULL, 0x08A203B9D58147E6ULL, 0x7BC8AD5716FA94ADULL, 0xA86F1F01D916921BULL, 
            0xDFEB09FB7ABCBC49ULL, 0xFB7B6DE738C07859ULL, 0x719F0467143A109DULL, 0xBC06DFC4EF8E281FULL, 
            0xAD703AF99D098DAFULL, 0xBB7988190D8D4082ULL, 0x300DABCBE8C67E6DULL, 0xA947CCDEA824925EULL, 
            0xDA016D6F6DF464F5ULL, 0xC4D311BBFFDDF5A7ULL, 0x80B4183FA799E18EULL, 0x6C84F298A2A64549ULL, 
            0x756F1DF128226E89ULL, 0x791A58AFA77DFE2CULL, 0x022EF7327E1D37B1ULL, 0x69BBB597717AE998ULL, 
            0x94D9A7F9F7223553ULL, 0x906C8E31151E36A9ULL, 0x15F40A31609D4E20ULL, 0x3D365E396ED73D00ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mebsuta::kPhaseAConstants = {
    0x705EE58EE3663987ULL,
    0xBBA7CA26C3664E16ULL,
    0x0EFDD573DFD278F6ULL,
    0x705EE58EE3663987ULL,
    0xBBA7CA26C3664E16ULL,
    0x0EFDD573DFD278F6ULL,
    0x51F6CA48472599A3ULL,
    0xFB96C91FCE0131D0ULL,
    0x24,
    0x39,
    0x09,
    0x3F,
    0x26,
    0xC4,
    0xE3,
    0xC5
};

const TwistDomainSaltSet TwistExpander_Mebsuta::kPhaseBSalts = {
    {
        {
            0x673096F03C24BF5FULL, 0xEE27557929729FAEULL, 0x4BD20011C72B9767ULL, 0xB768D7F922A800C2ULL, 
            0x90DED4A538B0DDAAULL, 0xEF36597DCB816CDCULL, 0xE9E4BB0224BB8621ULL, 0xC086B72CDF9193EEULL, 
            0x7F5A127EDF746622ULL, 0x6D3EAEDC4F34E885ULL, 0x28BBF84709C62169ULL, 0x4CB52BEEFC57B7EFULL, 
            0x1199482E19E31488ULL, 0x211A696D91D00BF3ULL, 0xFB781B8A92FDBF67ULL, 0x74CF4C97B87647B4ULL, 
            0x8805F038523EBE4BULL, 0x359F47A6DACF9646ULL, 0x44E63BC814513A05ULL, 0x9EDF7DD700B45E2DULL, 
            0xFDC83199AAEF48F7ULL, 0xA5C79710440F495FULL, 0xF315A80E32E60911ULL, 0xB712CB42B10EA91CULL, 
            0x892D429F94A12486ULL, 0xA4A3197A7BA47446ULL, 0xF3A2636D511E413EULL, 0x237871C31648656AULL, 
            0x55B17EE480510AE5ULL, 0x7A5AB82636838D0FULL, 0x0C0425A6CAE54765ULL, 0x23F1B0D484B9D6A8ULL
        },
        {
            0xFA3C288DE74C0248ULL, 0xD8D6840564AA7A01ULL, 0x10FE1CEC78298293ULL, 0x22B149FEF6806598ULL, 
            0xA74E29C505613655ULL, 0xC9651C3D2E5D8F05ULL, 0x0A6C1DDEDD150A7DULL, 0x326CB5626FC956EBULL, 
            0xF0E7B29E24FD7BCBULL, 0xC8E7B541FFEF60C2ULL, 0x1D5AE32E77D32896ULL, 0xC7603CF4A1A7F344ULL, 
            0xB950EBB641585CBCULL, 0xCF120E549AFE0717ULL, 0x8C9C549D92604FA4ULL, 0x705A98FA96E6FC1FULL, 
            0xB26AF798BFC7F904ULL, 0xB725D3620AF16CEAULL, 0xD31E89B3D91DD9B6ULL, 0x9BB6B8DD817AA9AFULL, 
            0x816FA54A84682C97ULL, 0xBDD3B9CC6A3DB224ULL, 0x5D28CE8CD85B4EBCULL, 0x96820F5289322133ULL, 
            0xCB9DF96FD168BECCULL, 0x8A6A9A4738FF50A9ULL, 0x2B2AF53A945E3B5FULL, 0xE48FBDBF5E4ACF9BULL, 
            0x3B6B2C75A488DBC1ULL, 0x180C776BBAA29921ULL, 0x4CB5C9690AA34392ULL, 0xF004B8D9EACD16E5ULL
        },
        {
            0x6CEAFF1AE249C935ULL, 0x6C230D708023E794ULL, 0xE7C1D77915F46C72ULL, 0x2F0B798BD501B2B4ULL, 
            0x56B38213839AFD60ULL, 0x28587461AEE03FEFULL, 0x940F4686741CA828ULL, 0x7C70F51B4F2A0A01ULL, 
            0xB93457FA295D9530ULL, 0x97092198862D2F72ULL, 0x3FEB789D4DC0791AULL, 0x6C85700CD28F7F98ULL, 
            0x92C8224F81CC8867ULL, 0xF4DAFA6840F79C20ULL, 0xE60532A2DED1ED71ULL, 0xA6F846ECA95DC1A1ULL, 
            0x7BB34AFA66646C39ULL, 0x4492611FA234A307ULL, 0x49C1196308795E1AULL, 0xD54F8EBF6805F75DULL, 
            0xE28A8F28D9C2B174ULL, 0xC049A174A2D47C23ULL, 0x1D15B87AB9926EF9ULL, 0xE4375D746BFBC8AAULL, 
            0x1914B7EDE2A86124ULL, 0x4FFEFC03D38443DCULL, 0x0F76C03692FE3A32ULL, 0xC7CECBB7290F9835ULL, 
            0xAC78E2296C63A588ULL, 0xF16CCA4BDEC63BD9ULL, 0x28430B185D3AD899ULL, 0xFA26CE9F763A0127ULL
        },
        {
            0x66D6BA801D5E1848ULL, 0x84A03F54C609A0A5ULL, 0x225823A7746A1776ULL, 0xE2D6FF0EBAA8430CULL, 
            0xD0823146F28B487AULL, 0x08819556A7896D7EULL, 0x5FFB6770B21B14C9ULL, 0xA4F8901FAE8BD93FULL, 
            0x85D3C13C55481716ULL, 0x39721EAA18B0BB02ULL, 0xC034DF3130028B6EULL, 0xFE96CF1470AE37AFULL, 
            0x6D924CEBAF1FB2BBULL, 0xFBD9CF02D7AE5E2CULL, 0x04BD39D454726651ULL, 0xB113DC6374ABD268ULL, 
            0x1C4F339183623C5EULL, 0x369BF2F4FB49618AULL, 0x759ECA32545A4FE4ULL, 0xFCEA257D67C9D90DULL, 
            0xC565E6F238489EEBULL, 0x302F28587DA8C72AULL, 0x4E56434399614C6BULL, 0x69150D959C2FF0D0ULL, 
            0xD804D464DAE126D0ULL, 0xF012B38A5E224109ULL, 0x90F2887A7BA09871ULL, 0x471D48F7BD40E68DULL, 
            0x9DDAB875CD515892ULL, 0x3C39371E07ECFA8BULL, 0xF2CBFD905574DBEEULL, 0x06854D64A26B0A6EULL
        },
        {
            0x36B1FF328FA4CDFEULL, 0x19C13F63EFF70C1BULL, 0xEB8524A851328038ULL, 0x6DE770C9A93BA447ULL, 
            0xCA5C9CD842F39F71ULL, 0x074ABBCB6310866DULL, 0x29961D7920538F26ULL, 0xA3F7763F743C33D2ULL, 
            0x1DB73C2E5F32A906ULL, 0xBACF17CC0969AF6AULL, 0x803543A202F32105ULL, 0xD66D70B54B4780A4ULL, 
            0x8FE042A33AE351DAULL, 0xA5E8492DB6A486A5ULL, 0x01FB8DA2E6C89DB6ULL, 0x1BF881BE0A65F8E2ULL, 
            0xD711DC95EB9856BBULL, 0x5AC96847F01EFCADULL, 0x32649505E1CAB665ULL, 0xB14277488AEED56BULL, 
            0x6CE677CBE0CD4C7FULL, 0x0CDD623DCBC37AC3ULL, 0x3AA7373CA5F3A280ULL, 0xCEE1813BFA2DB467ULL, 
            0xFEB063814CA27F27ULL, 0x3CF33A27CF4024E6ULL, 0xD9AC0E12883C44D7ULL, 0x2BC280E389368507ULL, 
            0xE20690CBB811681AULL, 0xF1AC8AD86610E9CAULL, 0xFE5B166FE401F1F0ULL, 0xA317B7373DC3C51BULL
        },
        {
            0x711E12217A7C6D16ULL, 0x3F27962A62F46A4DULL, 0x856D3785635EA1C0ULL, 0x7A3976739208B575ULL, 
            0x98DEF2D146423A46ULL, 0x8C5C82ABDA0AA9AFULL, 0x3AE062B06836C438ULL, 0x9471C63239BE3914ULL, 
            0xF76F3955E550F30FULL, 0x617A5568A0DE0F4FULL, 0x22B8C26CBAEB96F8ULL, 0x1AA2EA594E531986ULL, 
            0x36CB60FB4A69CE44ULL, 0x6F1886CED28D0F41ULL, 0x44CC7B3ABFB47D24ULL, 0x6EB18C9374AD93D4ULL, 
            0x35DA0CD114493467ULL, 0x59E07B521AE4A60EULL, 0x51FEEC20FD37E084ULL, 0xA028FF1EE6FA1B9FULL, 
            0xFEFE95EF1AC61584ULL, 0x7C28AD4314204ABAULL, 0x369997DC5485B029ULL, 0xFEC709AC57146012ULL, 
            0xD1B22735495BD190ULL, 0x2ED36B1C6DE47018ULL, 0x4A16CE189C09D115ULL, 0x9152F7D96BCFA8EAULL, 
            0xCD8D905BAF19D870ULL, 0x07046DFA2C2A2F5DULL, 0x32FF303EDE39E980ULL, 0xE8DF4926B8DAA3C5ULL
        }
    },
    {
        {
            0x6C890FE1EF4B878EULL, 0x324A7B771DD71CF1ULL, 0x26ACB92DCB470EE8ULL, 0x337C673D7625D99DULL, 
            0xA07D0EB86BB0FB49ULL, 0xB4866FAE25B8AEA3ULL, 0xD5AB69315DA22273ULL, 0xAD648B86E52DCC5DULL, 
            0x10C76A2E5533B3A6ULL, 0x9CD286C33EC78E0BULL, 0x59C9F35A5E3AC5F5ULL, 0xC66A10BF405CBB68ULL, 
            0xA545D1EAA7AED1C5ULL, 0x67428FDA8D911D75ULL, 0x07F248EBA6CA6453ULL, 0xF6F171DD21C2F3DFULL, 
            0x4AAC44A6E1DFD73EULL, 0x8AFCFB62AE7D2245ULL, 0x02C5F9D2960812D9ULL, 0xBC4CDC7C59A1D17EULL, 
            0xC34E9F1CF34793ACULL, 0x462BDEF2219D9B02ULL, 0xCEB141A4BAF55BF4ULL, 0xEFBE2D05E42EA499ULL, 
            0x90BAB0A13511B987ULL, 0x36831EF87E50D6ADULL, 0x0A851086C26EB782ULL, 0x7082E2D710B0FC7FULL, 
            0x7237433FDFC9120DULL, 0x10F848B76F65188FULL, 0x0B1F2961ECD40B0CULL, 0x7EEA5F1B75F7C935ULL
        },
        {
            0x9864B2BF1797AD27ULL, 0x3425A311C6292CEDULL, 0xDB0B4624C14DDEA7ULL, 0x6C6B4C9DDEB3CAB6ULL, 
            0x6CF0E05A0CAD5B54ULL, 0xE7D12D9E0C4C109BULL, 0x4E9DBE85BEF37E16ULL, 0x22AD9D18C02944EAULL, 
            0x72E0FC4197A646DCULL, 0x80796963AB9571A3ULL, 0x53046E552A3A112BULL, 0x3D85786AFD83A0ACULL, 
            0x648AC22CEE087AEDULL, 0xC2BFECCCA17B8D7DULL, 0xFA8082B1935A1634ULL, 0x187F2ECD9153EF3FULL, 
            0xFF85AA422CF9FE62ULL, 0x065E0C42BBB1CD95ULL, 0xF178E46F6B377D2DULL, 0x00560488C99FF8E7ULL, 
            0x1D02CA8FAEB6422EULL, 0xBA208DBC023A3BD4ULL, 0xF2715204D739459DULL, 0x89632F3B165C2D39ULL, 
            0xBD5525608C81A612ULL, 0xDD2F34AE64D89DD4ULL, 0x7A3384A7B7096D9AULL, 0x639D6E3B5F6EF551ULL, 
            0xE5CA84E671AAE3F6ULL, 0x45A587238D482FDCULL, 0xEEAAFCE68B4B866AULL, 0x8DAC4AD1C538F025ULL
        },
        {
            0x42BE97D50CD1270FULL, 0xCB660C4F55994CFFULL, 0x58C38047F120E8BDULL, 0xED9A5F93AB5351BAULL, 
            0x30997AE1E8AC8B19ULL, 0x7722301D9899F9B3ULL, 0xF0C80F53089F3B80ULL, 0xF60A2C3B547E9331ULL, 
            0xEDB6E52B3CC1F9B0ULL, 0x9560948EBC162F09ULL, 0xDA10037760B7BE27ULL, 0x8F7C215CAED91C15ULL, 
            0xD38A307F2A2DA5D9ULL, 0x4A0F295B25A34D0FULL, 0x19208BB2952050E2ULL, 0xFB39392E63F9C848ULL, 
            0x90B10DFF4DEAC1FFULL, 0xF2E81C947EE95266ULL, 0xDA6989849B9BEC8EULL, 0x44A4DE25E7648F02ULL, 
            0x7D013E7A6C7EF2DBULL, 0x3D289661CA26EB5BULL, 0x40F0DBCC8C7CE7DAULL, 0xF234AA236A71ABE6ULL, 
            0xE584D69FD02F7AF4ULL, 0xB92414B4D7C06405ULL, 0x3D6145B1FC24DFC7ULL, 0xA298588CCB14A172ULL, 
            0x0563A9A03911C1D6ULL, 0x3DD89E57FA174500ULL, 0xE350EA411C40C283ULL, 0xD7721035FA9D0138ULL
        },
        {
            0xF5DFD553CC5B38B7ULL, 0xF198396EF606A186ULL, 0xE59DBCE02F88F923ULL, 0x854DFFD67D8ED2E2ULL, 
            0xEA9D0E4F534B7560ULL, 0x6F890DE180274B3AULL, 0x052437147DA13D49ULL, 0xCBDE1E24459A423DULL, 
            0x48B643DC685D3301ULL, 0xE84A4B411D1E654FULL, 0xB9FB611077EDCED9ULL, 0xBD35531CA4CA33E4ULL, 
            0x02C8B03ECCE02C74ULL, 0xCAC8AFE64EE98BD4ULL, 0x44AAA7A7CD3E8271ULL, 0xC08F0B419ACCF4CAULL, 
            0x5C60A0F8E7AAD2F0ULL, 0xC37633154D8FBB71ULL, 0xF6709541625352E8ULL, 0x4F21D8FBC9CAD0E3ULL, 
            0x1A6D3FE54184B776ULL, 0xEFBD80E193189F3EULL, 0x2F0610784F710626ULL, 0xFEC7ABBE537BF663ULL, 
            0x65BE8EB642399DECULL, 0x40691231F2CDFB41ULL, 0x3D1D8A8EB28CDAA3ULL, 0x966C614C16C666DEULL, 
            0x733B293023DBD330ULL, 0x3F6CE51C2EEC0D7CULL, 0x03410C76C3ACB607ULL, 0x1BEDDE1DDF58F6C5ULL
        },
        {
            0x5C108A7AEF6494E4ULL, 0x3FDCDB8C5A49DA5EULL, 0xC22D0520653D1B5FULL, 0xD3F838C5A9AFD407ULL, 
            0x31C21F2D9BB2EB93ULL, 0xB6BD39982A60E423ULL, 0x1F230E79C36DB37AULL, 0x8BF75E02DB009CE4ULL, 
            0x723E18736AF8299FULL, 0x33373DB41AF78C83ULL, 0xB2EC0F8C1A457882ULL, 0x6ED03E1F73236FB3ULL, 
            0x47EAFB01AD11CE61ULL, 0x9A6882AAF4570519ULL, 0x447479A11067CB05ULL, 0xA98A13D5844A049AULL, 
            0xEEF638F573B81131ULL, 0x8E39A3A0EDF1FB7FULL, 0x5DEE8D3F13E456C6ULL, 0x256B8D61D5A79A2EULL, 
            0x98C3D585C6176F4AULL, 0x96C4DDB8569BF2DBULL, 0x3A5CBAF847C1B4F5ULL, 0xF5CC66A6DCF0DF3FULL, 
            0xAA429373BB9FCC92ULL, 0xDE73D03F75EEA5C8ULL, 0x7F11105C471B1584ULL, 0x6BD68194FD5679B3ULL, 
            0x3726BF8447D38F97ULL, 0x7F85BAB1391BDA45ULL, 0x9B6CB2987D55FD60ULL, 0x6047D74AB979E985ULL
        },
        {
            0x1FAE83F1E7B16407ULL, 0x00D9B22C727E8727ULL, 0x9755CE9FC6883EB8ULL, 0x184D0830A0974FE0ULL, 
            0x014FFA1FD3ADB567ULL, 0x6E3C5ECDB8C613E3ULL, 0xC2B1B33FADC8E956ULL, 0xAB3CB5CC870BB65BULL, 
            0xDD792F2FEFE041FDULL, 0xBED396725E58305BULL, 0xA64D1B809C9EFC98ULL, 0x74F6E002C1E21FFBULL, 
            0x868CB4AA02ECE450ULL, 0x7E5AD5E67E164EF5ULL, 0x088336361D0659D8ULL, 0x00593FCB9B117279ULL, 
            0x0EF3B00716C3FC3FULL, 0xFA411CF1BE90D279ULL, 0xDDF6FC48EAE2A513ULL, 0x0CA5D86E3ACD1A50ULL, 
            0xAF4B00375B8AF60DULL, 0x7E6882286706A26BULL, 0xAEF151FCACAD381CULL, 0xA821BEAC0326DF6CULL, 
            0x077800C9B152FF34ULL, 0x7A4971444BBCC432ULL, 0x7E6450E04D5CD287ULL, 0x74BF8F2177BA88DDULL, 
            0x024AF45E0588B476ULL, 0x52EBDF090B14C270ULL, 0x42644BF88DB6CCBDULL, 0x73630AF786BE52A6ULL
        }
    },
    {
        {
            0x9BD51E9BF5809458ULL, 0x1438E9BDCA46BAE6ULL, 0xCF5686375580E036ULL, 0x5D00FB21AA2D0E59ULL, 
            0x0900EA2A4C8A1616ULL, 0x0CFB3AFFEAAE31CAULL, 0x3653C7D7517D1A97ULL, 0x8C2FAEF1E8C7FFD4ULL, 
            0xCC17C22693C542D4ULL, 0xF36C357FF7539C6CULL, 0x7156B5ADFCC9744EULL, 0x7CE900E7053A74E6ULL, 
            0x158599E89CBEA19FULL, 0x5FACD32415ADF710ULL, 0xE143E4E709286A40ULL, 0xB1F967DA91524AEAULL, 
            0xB1A6B7204EE0C9A4ULL, 0xD96DF985661840D3ULL, 0x06609931B8AA3773ULL, 0x69E1C4EB7DC6F94FULL, 
            0x4351C27F12F8A9C1ULL, 0x0A24847E8CD49C84ULL, 0x6AD209674C50E90FULL, 0x7B2AF602011DBDCEULL, 
            0xEB2DDECF46CB48C9ULL, 0x3CFA2241CA76A3E2ULL, 0xFA9DF8874AD4B3CDULL, 0xAC1E8CF2D26E5A70ULL, 
            0x2343EDC726ED54D6ULL, 0xA8647C41A6A7D743ULL, 0x9701EA5DD12F11BAULL, 0x6D15D36F2E08D82CULL
        },
        {
            0xA7136E0C950C4B7CULL, 0x8714A5B32F2C898BULL, 0x07A9DE67DC5A97F2ULL, 0x82C7E968C30B23E0ULL, 
            0x6E0A461ED03DBAC8ULL, 0xE5EAE99FE12F2F3FULL, 0xEC1ACB97DA91A5BAULL, 0x819D88CFB6FEB7C9ULL, 
            0x0B76CC09177BE5A0ULL, 0x374AF0262A55B763ULL, 0x9CBB682473928A05ULL, 0xCBF21F2AE694AF66ULL, 
            0x919549E62687C207ULL, 0x7CD1EB3E17877556ULL, 0xA048687EC5E05D9EULL, 0x45283705A92F9E94ULL, 
            0xCA369E8758C73F6EULL, 0xED981A4755DF4710ULL, 0x4F2500BA917BE97BULL, 0xD09F2A4B0F4E9567ULL, 
            0x936401DF4664AE77ULL, 0x8D91DA0111A19742ULL, 0xF6A830A265F77719ULL, 0xB9F83B9F1429C6CEULL, 
            0xC3ACEC47777E51F8ULL, 0x0FDBBBF66BF6EFCEULL, 0x2FAB0BC28544C17FULL, 0xC9CBAFA351A15969ULL, 
            0x939E25D600CEDA2FULL, 0x4E60E885D56C40D5ULL, 0x8203AD8FD9064EAFULL, 0x5D8453FF038032B6ULL
        },
        {
            0xFA4BA18AD3E9CDF0ULL, 0xD69C411203DA53E6ULL, 0x7B994C89775FB827ULL, 0xF5129CAC0C003C8CULL, 
            0xFF874E77B7737376ULL, 0xED82CD1B24F57B29ULL, 0xEDA01B872389BDCAULL, 0xC271EF9FC52CE45BULL, 
            0x0DAB4AC185CD1224ULL, 0xED1DE251421C68D3ULL, 0xD451813848FB8D19ULL, 0xB5F87FCFCC3CEB14ULL, 
            0x3044A5C5B874C207ULL, 0xA77D357A8F20387FULL, 0x94C51CB093DAEE1CULL, 0x2B53A8A7F95CE4DFULL, 
            0xE0FEE13CE6485586ULL, 0x4FBC92376D3993D0ULL, 0x3035AD5281E193EEULL, 0x80DD5E019AEF7C50ULL, 
            0xAE5A77BB28D30189ULL, 0xD73806D95C4FC2A0ULL, 0x965E4E16BF109856ULL, 0x3FF5FFCC91A77FDCULL, 
            0x54252253E67E92D0ULL, 0xC83D5C66090A6804ULL, 0x6E6C7272A4726C4EULL, 0x464792E9D13C8FF7ULL, 
            0x5F956FBA539ECBC6ULL, 0x027A18A3A02BBC76ULL, 0x71B51F68C6DF533CULL, 0x6B5837E33A946827ULL
        },
        {
            0xD5806AF4AD9E4E01ULL, 0xC9BD2C538CA8B381ULL, 0xE9159354D3ABD3B1ULL, 0x07681B1DD6CC4C97ULL, 
            0x4F239FABC9D56659ULL, 0x08DE8972D7CB59A4ULL, 0xD57FED2D655D64CAULL, 0x7B52A541A63C5708ULL, 
            0x2E93C01C7EC11BACULL, 0xFD500040726A81AFULL, 0xB77758F4B6FEB482ULL, 0xC057C3D3B28012ABULL, 
            0xFD9CE2C92B70C199ULL, 0xE1CEA2DBD6E9C1ADULL, 0xD08565FEE597929CULL, 0x1B50267385F919DDULL, 
            0x06367355213FBD5CULL, 0xE0D2942252B6930EULL, 0x4E555D8D4A4F4AEDULL, 0x291B77EC91850E33ULL, 
            0xF7EC48CF4F15D772ULL, 0xEEDFE9445A0D0C47ULL, 0xDA9B5C2B5D7D9C62ULL, 0xAE9CEB4753D56501ULL, 
            0xE987D616F4253B0BULL, 0x88EBE6CE61592134ULL, 0x8C5D9396326A800DULL, 0x7D12EF2E7D05A159ULL, 
            0x0FC9E3A03C7663CDULL, 0x29D3065B5BDD7B7EULL, 0xFE5312C5E7E3C625ULL, 0x8EAECCFE973C6D0AULL
        },
        {
            0x76639017A2215D36ULL, 0x50394E14ACB117E5ULL, 0x9EE86D922AE9CE19ULL, 0xC1877B391C178C28ULL, 
            0x140646821FD459CCULL, 0xC05EBB09E9093DC2ULL, 0xC9278803841244E9ULL, 0x4CB97CBB751625C5ULL, 
            0x8CFE0BA3DCF88096ULL, 0xCA84102B31ABC662ULL, 0x8ECD52E493B01584ULL, 0xC1D529E236256D12ULL, 
            0x947B87E33627311FULL, 0x3C59C71F5719AA3AULL, 0x60AD56B7B3F79BCFULL, 0x953CF2CA801380E6ULL, 
            0xC963790B0B99CB45ULL, 0x39F404362D7B3233ULL, 0x01283738CE76DA1BULL, 0x46D2BFAF247AAA48ULL, 
            0x2DA8C6946208606DULL, 0x5DC277FCBBCC6C48ULL, 0x0BDBBA0876C80A41ULL, 0x8ADD23BC1648041AULL, 
            0xB3875AC06DA09FE5ULL, 0xD2B998FFAADAD883ULL, 0x8CADD2E6260AFF31ULL, 0x498F1A1EF32FA10CULL, 
            0xBC90445324CFF2DAULL, 0xD3F192B9CACC0B0CULL, 0x0E8B87521D675845ULL, 0x947DB441194AD597ULL
        },
        {
            0x23DD0C19CE06A56AULL, 0x4853418F24C53703ULL, 0xB57A48CA152AAA7CULL, 0xED22D8FE3BC005FCULL, 
            0x34EB407D4B257FD1ULL, 0xFD09D87BAC8A5AD3ULL, 0x4EDCABC7C40FAE87ULL, 0x3A18C775C02B18E9ULL, 
            0x317E97D9648A3563ULL, 0xC56F78C23ECF5851ULL, 0x2609A7244C50BE04ULL, 0xDEFAD84A0493D483ULL, 
            0xCB9DA588C9929CB3ULL, 0xF9B22E49502017ACULL, 0x3B9E17335F15726FULL, 0xF735B56E386C943EULL, 
            0x09AB07D139D0C8E7ULL, 0xBBB8D882AD111D54ULL, 0xBAB195FE1D0ABBDAULL, 0x0B7028ED8012DD41ULL, 
            0xA3281074A46F48B7ULL, 0x81E7CD5D9C504457ULL, 0xA4B80DC26BFB66F1ULL, 0x256A2DBEB0BB6795ULL, 
            0xCEE53B0A39FF2413ULL, 0xC7A5240BA8AD5173ULL, 0x118D878B8F23D227ULL, 0x3E4F02CEF86D65F0ULL, 
            0xF75BACC16910A627ULL, 0x955F7BD737230902ULL, 0x481AC9EE51FEEAFFULL, 0xA6C6CA438E210AC3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mebsuta::kPhaseBConstants = {
    0x4E9870DDA10E8D75ULL,
    0x012854130903287DULL,
    0xD33F5A0F8FA9A3A6ULL,
    0x4E9870DDA10E8D75ULL,
    0x012854130903287DULL,
    0xD33F5A0F8FA9A3A6ULL,
    0x4FE5EAB72F150FF6ULL,
    0xBB158F3497293B59ULL,
    0xFA,
    0x37,
    0x2E,
    0xBC,
    0x5D,
    0x0B,
    0x9A,
    0xE5
};

const TwistDomainSaltSet TwistExpander_Mebsuta::kPhaseCSalts = {
    {
        {
            0xD023301998D1E5D0ULL, 0x7D6E44067A9C4000ULL, 0x034C52002D169B10ULL, 0x01B23CA25D7D2D94ULL, 
            0x334555043B894FA8ULL, 0xA983F6FC5804DEEBULL, 0x2FDA2B4A51A01A4BULL, 0xDA4A3D8BB65D578AULL, 
            0xB856BB8C00F2760BULL, 0xA515BD45F28F4EB6ULL, 0x656992E436F2D2F5ULL, 0x5216577B586BA43AULL, 
            0x11B59C6DFA97ED40ULL, 0x43A2A5591DBDA46DULL, 0xB5A4E3ED469C2A6AULL, 0x6DA18D284367D44EULL, 
            0x0E023D0183E749EBULL, 0x08523517A176B91BULL, 0xCB64B7D5A57404BEULL, 0x5A9C72927F9715E0ULL, 
            0x5D089F7EA597B00DULL, 0x92627A704B0FA2F8ULL, 0xF29F85147502DA35ULL, 0xB304053F5087A4A4ULL, 
            0x901FE96E4FB3D3F2ULL, 0x5D986135AE7E69B4ULL, 0x4D889F32580F0F66ULL, 0x18EC388B7F11108CULL, 
            0xC47780CDE9B325CFULL, 0x82B67808B5917257ULL, 0x7C723928FEE667CDULL, 0x3B67336D7D4459A1ULL
        },
        {
            0x774E1DDABE714337ULL, 0xE05804943D0C2688ULL, 0x86EF6697C6648267ULL, 0xCFD36552EAB564EBULL, 
            0xB2199BD6BE3A962CULL, 0xDC5EF06BAF11504CULL, 0x8169DA1CCA459F69ULL, 0x1C86A3CADF9FB80AULL, 
            0x397D76D01898FEFFULL, 0xCC636A8569896814ULL, 0x5B2B09C7F76FF0FDULL, 0x2A219340CB8F021AULL, 
            0x489AA9A2970D1821ULL, 0x6E4537760FF770A5ULL, 0x13CC40D2592CB889ULL, 0x32F6576F99C9A362ULL, 
            0xF9C1D42E8750D98DULL, 0x95B7FA14A920D4B5ULL, 0xFF4CC4FB1518B479ULL, 0x44A4ED2E4B52A494ULL, 
            0x057466DE03CA37EDULL, 0xA51638B29BA415C7ULL, 0x43D2B344306B75BBULL, 0xFED2FE81650521F5ULL, 
            0x648EAD39AFFF577FULL, 0x48E9491F054CD17FULL, 0x0307C9B1F5AA4E8DULL, 0xEE0F2364F42F606CULL, 
            0xB5AF7DB9509D5FF3ULL, 0x0CC50F0157F87BBAULL, 0xDF7F254D7F3C2287ULL, 0x1E3102513C190C2BULL
        },
        {
            0x030E48B9986E48D1ULL, 0xC0318081409D0471ULL, 0xF5E792D33162C227ULL, 0xBF39B27AB9A1FD24ULL, 
            0x6C380F3BBCAD5B69ULL, 0xA7D0924F09EF2911ULL, 0x69F4715F4BE7F76BULL, 0x095A914BA50F9980ULL, 
            0xC6695098452F25CCULL, 0xBB7E478824D20744ULL, 0x0EDD80F2CA0AC54FULL, 0xE28CCE6C020A3CE6ULL, 
            0xCD39517604F3190EULL, 0xB0D4503548A0BEEFULL, 0x6BAE898062F5BE81ULL, 0x913DF7F98D3ABA38ULL, 
            0x1081AD73586E8F87ULL, 0x9D3B11D4AA2243D8ULL, 0xAB359D17647F642BULL, 0xF59EDA9F0C8144CCULL, 
            0xA0252C78CD934715ULL, 0x930836CD34A32790ULL, 0x166C881A6C7CAC08ULL, 0x1FF0971D8F53BF92ULL, 
            0x3F3845980CD54463ULL, 0xEF49388EA93536D2ULL, 0xBC9D59E1964BFE4EULL, 0xA775FD60D1544C0CULL, 
            0x49144CC8571AFBF2ULL, 0x5CE16FAC64DF7825ULL, 0x608CBAEBB89E2CB4ULL, 0x20389B9F11F19294ULL
        },
        {
            0xD64F740832528B24ULL, 0xAA92A331586277EDULL, 0x16701A98510A2E6BULL, 0xBA8D96B4451E5E71ULL, 
            0xC5A01B367B4BFA65ULL, 0x78E7E9AC22793C86ULL, 0x334BE2598B81751EULL, 0x2EAE7DFDFD323FE7ULL, 
            0x50AB123860BDA703ULL, 0x69DF0F696A122D45ULL, 0x8600E96100F02B1CULL, 0x52D5057BBF7D8BCFULL, 
            0x3E7FB246B7AC0BE5ULL, 0x2BBDE98AC85958AAULL, 0x16C7875E1E249395ULL, 0x2A16B7EE19CFD78EULL, 
            0x9D9E3B242CB4D3B7ULL, 0x379B09FACF217D90ULL, 0x3BE54A28E7090550ULL, 0x06E4D51F86F186B1ULL, 
            0x69EC5ED22BD0E112ULL, 0x431CA8D86D21F896ULL, 0x69C1D48F8A4063F6ULL, 0x752C6BE8A4941A7FULL, 
            0x98F415FAD583A79BULL, 0xF5295A4E21B5C6C0ULL, 0xAFC8AD3887B309A1ULL, 0x7AD0E70523BEF007ULL, 
            0x1494827AF655CD06ULL, 0xB4883D993B7497F5ULL, 0xD141149DE2D4153BULL, 0x78ADA485EEED4225ULL
        },
        {
            0x6A06120FEDC4F79CULL, 0xDA61F4638ED1A0C0ULL, 0x3A481AA980CAD643ULL, 0x48F3203E80110E44ULL, 
            0x01BE2C65F64C5C96ULL, 0x246E1D8FDE7C3904ULL, 0xA4E178E386BA4AECULL, 0x04AB4113308FF2AAULL, 
            0x9545BCBB264E79CCULL, 0x3E84D09C5125EE0FULL, 0xEC51111C223F61C5ULL, 0x505CDA89D5121537ULL, 
            0x282ED83DD5E757E1ULL, 0xBC1B1D7DD04A081DULL, 0x452AA0B41C01065EULL, 0xC82587A8C4FFB99AULL, 
            0xCCAC01EB9E4332F6ULL, 0x9F2934A1289C3548ULL, 0xAD11B9EBD80ACA9DULL, 0x461153C0D4029A77ULL, 
            0x98EB1A6D1DB89957ULL, 0x43570768FA90F579ULL, 0x612242496F2740DFULL, 0x24E55AF659BCED28ULL, 
            0x134E69D0804B8A8CULL, 0xD3807A0371E5A4C8ULL, 0xF718841FE8C503E2ULL, 0xDE0DEAEF8E3FBB12ULL, 
            0xABE24E7213EB4073ULL, 0xEC25B1B99A3DADE6ULL, 0x0635414C72885A55ULL, 0xC15DB603B95D5C63ULL
        },
        {
            0x6B5EE791B3711D80ULL, 0x8AB6AE39C9CCB2BBULL, 0x57CF6D6961E7EC1FULL, 0x4610318851AA0609ULL, 
            0x9217E39B2D47D71BULL, 0x659964D62F669C16ULL, 0x2A3029B20204B265ULL, 0xAB962F3D2AF4DDA7ULL, 
            0x0EA43674C5C1894AULL, 0x9F34386C02105C51ULL, 0xD973910865636F1EULL, 0xCA0A2A904D530032ULL, 
            0x57F45C81585DF000ULL, 0x7D62B9AC983862EEULL, 0xE7949A4148973C76ULL, 0x36200D000305EEC4ULL, 
            0xECD86C10DC80BEDAULL, 0x544897F10A675C7BULL, 0xC75020D341C28720ULL, 0x585FD7EC95E846A7ULL, 
            0xBB1827C0E1D975E2ULL, 0x50B19640BA23F124ULL, 0xC08D75EB5652E9D4ULL, 0x84C99D7B2851845CULL, 
            0xF699BD8105A53D6CULL, 0xE9C4CAD7568671F5ULL, 0x86781AB905EEB498ULL, 0x08F1613DF0A91526ULL, 
            0x96DD6F8300E9B417ULL, 0x41BEC6EDF5A705BBULL, 0xF9A876EA45254497ULL, 0xB73C0B03D2CE4FAFULL
        }
    },
    {
        {
            0x65FE59B190C00657ULL, 0xD2CF8088F77D2352ULL, 0x0A0B1E298FD5A5C7ULL, 0x186AB862B8B7164CULL, 
            0xE9825E4620B5A80AULL, 0x15754031E868DBEEULL, 0x2D9C10CEBE28CBDDULL, 0xA5B1C480135D4B9EULL, 
            0xCF3FDF3EE9561345ULL, 0xCCB004908D3DD1ADULL, 0xB6BEA6AD9CE67717ULL, 0xFB1E1FB0B9355A30ULL, 
            0x4CD76289AC2C5F50ULL, 0x98E2E26A2B1FB1BCULL, 0x12EEA9909F231BF0ULL, 0x77CB76A977EB2588ULL, 
            0x8130571F2338C925ULL, 0xB176972F3AB6293FULL, 0xA3C24887AE4E649AULL, 0x339AE6BDEF1A1D04ULL, 
            0x640014795EA73074ULL, 0xFCE62EB3C12E0DAEULL, 0x95114C8CA940B46AULL, 0xC1670AD9D8E630DCULL, 
            0xF352B2DBD2005FC7ULL, 0xCF536F7E0ACFF2E2ULL, 0x53C089BEE5C1B292ULL, 0x8BF95DE3511072E4ULL, 
            0xB4B81232346166A6ULL, 0xC8A776ADB09D98C0ULL, 0x0C7CCBE62FDF18A6ULL, 0x4B91785E803C189CULL
        },
        {
            0x3421A1FC0367D6C2ULL, 0x7097985FD1FE2D71ULL, 0x4F6E7C935DA9E406ULL, 0xA24377F3F25C966DULL, 
            0xE20B46DA8AD6BA58ULL, 0xDDAA9F8EA729762EULL, 0xFB42C257C4A312CCULL, 0x54631AED7B967361ULL, 
            0xB2C29A341DEF5B86ULL, 0x09271155260AEF0DULL, 0x6BB06239C011C070ULL, 0x3012E453D3949E16ULL, 
            0xD02E6777319C061BULL, 0xC14EA16A746BC76DULL, 0x7423A7CF4A89D519ULL, 0xA5810A2FFB7F481EULL, 
            0x757B1EE71E61DDBFULL, 0x9B707BC9EAC53A1BULL, 0x8BB3AA3627F4F9DEULL, 0x70EDFF50E836AD59ULL, 
            0x4DF73776A03FB39FULL, 0x365C1EB1DFA377A9ULL, 0xF07D49A7A2BA4606ULL, 0x8FE3EFCBBD3832A6ULL, 
            0xE1473221BEC75DB7ULL, 0xE517C23062B453A3ULL, 0x4B477A16DA3CCE76ULL, 0xD557A2C7C6336058ULL, 
            0xF6DE31C8A60EFE85ULL, 0xE8D2A1AE704A7126ULL, 0x63451B864AA607A6ULL, 0x8FA0C1BBF57C8C81ULL
        },
        {
            0x69D80FC0ABEBA802ULL, 0x2F3483A805417EB2ULL, 0xE6C3EA0D049CD976ULL, 0x1DF9B28F6978599BULL, 
            0x6EEAEE5C7A11D534ULL, 0x8A598B2322ECFBA4ULL, 0x78716680388C212AULL, 0x83D811B676B07316ULL, 
            0x634EA954BF98E42AULL, 0xB37C0639AE895B71ULL, 0x1606969E439CC824ULL, 0xB1FD97009C1BCF07ULL, 
            0x393FB496A04D6858ULL, 0x76278D2FFAFEF3A9ULL, 0x39380B04297D7CA3ULL, 0x35B22563DE44C61FULL, 
            0x3AD2BCF9268C6A50ULL, 0x7954DF64F9995CD7ULL, 0xB3F35B1B34DF5695ULL, 0x619F48B2AE6D3DB3ULL, 
            0x2A03FF0C55F3B6B2ULL, 0x670224FF0400FCFAULL, 0xDA7E18C7D1C9B914ULL, 0x8C0FD717D10EC91BULL, 
            0x0D498E034C1008E4ULL, 0x3EDCBC0834D0E299ULL, 0xDD0491F4E002CCB2ULL, 0xD1BD3FC0536A0D4BULL, 
            0xB115361FDA987018ULL, 0x2BB2C2A7C37CD50DULL, 0xF4411747A9F35E84ULL, 0xB31A51590C23A9F2ULL
        },
        {
            0xB2804E5EA07C185BULL, 0x143D4943C9BD3BA0ULL, 0xB25098961442D744ULL, 0x5EB6D7769DCCAD84ULL, 
            0x1555C85D3E7A9DD7ULL, 0x84C3C118C77A5D3AULL, 0x927ABABA3D594153ULL, 0xA1D1BD0D20939C43ULL, 
            0x7AC2BDF45C04ACDDULL, 0xB7FFFB1E5031741CULL, 0x7527EE3C789B9A6AULL, 0x8457EDCB01BE6E7CULL, 
            0x9A2794FBFB17A822ULL, 0x1BD17CE345B4C462ULL, 0xBAEDA7DAF44DED3EULL, 0x5172E1D3FB193172ULL, 
            0x7F65A42252B82472ULL, 0x0F36554462597ED3ULL, 0xA87A94D6E7F85D90ULL, 0x546D3EB0B6283395ULL, 
            0x9E9CDB1656423DFFULL, 0x1ECF1361DF95E515ULL, 0xC276106F6C3EADAEULL, 0x256DFDEFFC757160ULL, 
            0x58F81324A6587507ULL, 0x3BA105CF896DE546ULL, 0x7035E1E7AB90B39DULL, 0x026278C723F8BC90ULL, 
            0xB6E0EB301A76F281ULL, 0x7E10058A391D6BDBULL, 0xC650C1A786846C55ULL, 0x3BE453F58150136CULL
        },
        {
            0xAC2558A69E0F2C32ULL, 0xC8A0B63997005419ULL, 0x38273CF9E21D7F99ULL, 0x646405DA03B013DEULL, 
            0x32310D02362968A0ULL, 0x47B5E7AFC834A11CULL, 0x7DADC25B6975D899ULL, 0x671F971D18B9B69BULL, 
            0x3F837CBEB35C6684ULL, 0xB3D05A6CE5631838ULL, 0xB7DF83EA0C130B70ULL, 0x7AC438428CA28B19ULL, 
            0xDF6F8B094C9D2C92ULL, 0x2A504A0260093F8DULL, 0x9C9C305A1B0DC6FFULL, 0xBE2310F33D4649CFULL, 
            0xDB8B5A70D1D43A63ULL, 0x041FD5737D3D5B5EULL, 0xE99621077A8F14EBULL, 0x3752D60F1FE5F1B5ULL, 
            0xA48A21C8564B2310ULL, 0xF7C8C481BC7C0F9CULL, 0xB534B61B63F7D665ULL, 0xDF1BE9DD8E43CCDCULL, 
            0x80D2DF483351D475ULL, 0x663BB865A1389E22ULL, 0x7147ADD2F522BEC0ULL, 0xB84A9B32BC58618EULL, 
            0x0EBC22DA7FCD3B7AULL, 0x179E58A4125B3EE7ULL, 0xBF2EECC52C3A29AFULL, 0xAEF4E524A345591EULL
        },
        {
            0xEFDE70DB259D319FULL, 0x56486B9BD36C5AE1ULL, 0x9C14547342AE57E4ULL, 0x4ED5FBAF7B7F2ACAULL, 
            0x99FEACE8973CBF9DULL, 0x36A5FFCEDB559347ULL, 0x0A771639856D1717ULL, 0x90C2958889DF13E3ULL, 
            0x83C5C2EA49A0A145ULL, 0x79D96502984922EFULL, 0x639F09F034D27901ULL, 0xB8634EC273EEA9DDULL, 
            0xBFAEE44DB7CEE847ULL, 0xD3DD415CA497CBA8ULL, 0xF88D668403D56C09ULL, 0x389E8584187AEC23ULL, 
            0x6A45E437D15E0427ULL, 0x8C7FF9E2218E3F83ULL, 0x53663832EE414EA5ULL, 0x497F4FF9CBBE394DULL, 
            0x19536C032963FB12ULL, 0xB9FE91B0D45B0558ULL, 0x1A43AE3662331602ULL, 0xAC51068AAFD16E77ULL, 
            0xD114BB1F544F2DACULL, 0xF9D99B441DC2EAEBULL, 0xE6EB3E4A7D1CDB2EULL, 0xAA57D94BE5DE0A0EULL, 
            0x762496D066C17A2BULL, 0x954D2AE561016ACBULL, 0xE807EAB304368D81ULL, 0xF59B5AC812816B2DULL
        }
    },
    {
        {
            0xB38146CAAB33C6BDULL, 0x0DA6DA71CC53F36AULL, 0x804EE13063A86B2FULL, 0xD51F0E6CA494C7E3ULL, 
            0x40823EC9051AED03ULL, 0x87F55CD1F38B55E8ULL, 0x99B9E6F3E7EF3DFEULL, 0x2B5F171605AC15B1ULL, 
            0xF012B5130AA44536ULL, 0xDDCB4BEC76513C2BULL, 0x6CCA308F9EF5CA23ULL, 0x4CF446857BD20483ULL, 
            0x9412729A02E9D355ULL, 0x3520B950DC455C14ULL, 0xABDA6A964C4216A6ULL, 0xA5663F72EA327965ULL, 
            0xCDF4246AEA0D46BFULL, 0x97CF84CCA90FF367ULL, 0x3DEE46F9E43852ABULL, 0x7C1447458422345DULL, 
            0xF085E093F86F7804ULL, 0xF8A1A984D9B1BF16ULL, 0x775CFCFF202125F1ULL, 0x70298181DEBDBF11ULL, 
            0xC445182238D7F863ULL, 0x6FAD28120D3BD143ULL, 0xD887685E0565CED2ULL, 0x20D3C00BCB088FF5ULL, 
            0x49664307E6B9CB1FULL, 0x79CCCFC789223AD6ULL, 0xDB4A4B91C3039CA9ULL, 0x0CC235F5D677E130ULL
        },
        {
            0x99B3E5F6128BD628ULL, 0x55072B8D14708BA4ULL, 0x867C8F8F20CD6DA1ULL, 0xEDE6D3FC5948E523ULL, 
            0x9C5C6C634153FE61ULL, 0xBEF3688CF20182B0ULL, 0x14F3DEB9B72C5457ULL, 0x28C6CB31C0693CD4ULL, 
            0xB62553A96E3D18D2ULL, 0x99D3E38D91860ADAULL, 0x9D49BAA67A252DC9ULL, 0xD02C175C1867A8FBULL, 
            0x4B90621DFCEBD3C9ULL, 0x3DB3571DA70DCB20ULL, 0xF8E37E2941A16EACULL, 0x39B546C01DD0A9C0ULL, 
            0x2B53FDD53C4E65ABULL, 0x7B8852CE415C1417ULL, 0x57AFA0B26EDD3943ULL, 0x910C231D69737061ULL, 
            0x1998D739EADAAE94ULL, 0x59392CD73AEFDF79ULL, 0x5EAA933832EDCACBULL, 0x5A93D59BEFFDD602ULL, 
            0x903FCBFFE0EEE678ULL, 0x20D883AE9AAE10FDULL, 0xE1973353835583B1ULL, 0x0ED0BF760E7C992AULL, 
            0xE0AC3F886DAF57FEULL, 0xE8EE37C2C00B8A59ULL, 0xF1AFEAE1675649E4ULL, 0x6A37F40B5ACCD510ULL
        },
        {
            0x0EDE0C31DBD64D44ULL, 0x16FA8B3D2F358A8AULL, 0x638FB431712B10EBULL, 0xC59921B2C4A4B944ULL, 
            0xB57E3603011663A4ULL, 0x3DC47F874FD5E270ULL, 0xFB8AEFF7E941EFA6ULL, 0x7031BFF55AACDC44ULL, 
            0x374F9B8AE5B5C39BULL, 0xF1E2AA80E6321137ULL, 0xE4BAA92F0990EB81ULL, 0xDA91D0E478E0162AULL, 
            0xCCA408EF18E2B1EFULL, 0x34FF5E0ACF82FF8DULL, 0x807A2DB6C47FBD84ULL, 0xEEC3A747E7D966B0ULL, 
            0x67DF1BDE92B7AFA9ULL, 0x8B27906EB94DD0B0ULL, 0x28E2466612029B01ULL, 0x2B2733F6E6875E8AULL, 
            0xEE6CD76947D7CFD2ULL, 0x7937FFBDE88DFBE2ULL, 0xE0C52A7B9AADE637ULL, 0x9290EDB0006DF7D1ULL, 
            0x7857C6133AFEAFC3ULL, 0x60946991077166B9ULL, 0x06774B9C18F99AF7ULL, 0x0379C07DBC96A0E0ULL, 
            0xEB0AC246EA24D0CFULL, 0xEFCB236C043558F6ULL, 0x402504A92758013AULL, 0x219A5CC83E51502AULL
        },
        {
            0xAA318D7439C1D6E4ULL, 0x29625401899D3F50ULL, 0x4B3C595BE827AA13ULL, 0xE9C62D57E333E748ULL, 
            0xCEAB16B7AD785287ULL, 0x9D8A72DCF1AAA061ULL, 0x001D9F50D2697736ULL, 0xE134302B2BC46A28ULL, 
            0x78FA0183929D960FULL, 0xB294D54B5B283BAAULL, 0x27362EFFB5F0F70FULL, 0xB35A7E229822F7C9ULL, 
            0xFFD8EC6EF3C10D74ULL, 0xB703FF7F48D528E3ULL, 0x30A36F75C25FB5A2ULL, 0xAE17AD064750DEF7ULL, 
            0xA04D998C18A2898FULL, 0x2AB4A5185EFE6B87ULL, 0x3C671F04BA9C8EFAULL, 0xA2C8369AD763FDF4ULL, 
            0x6D64E3C9319321D4ULL, 0x2C9DA036FDAAEF21ULL, 0xC4B19F525A11A720ULL, 0x85D385CB1D096216ULL, 
            0x14643882EC0BDEF3ULL, 0x77DA2D8FF0DA5F64ULL, 0x5B0BE0763D8E14BFULL, 0x5B9D1FB1BD0B146CULL, 
            0x06E7F4848AA9DDCAULL, 0x68FEDBA6AD383784ULL, 0x6293043A1D5A2EEAULL, 0xCE7E32B877913A52ULL
        },
        {
            0xFC476F9D2C2A489BULL, 0x8EFA93A23D45D083ULL, 0x024764F7E3814E34ULL, 0xF7637927ED965C5EULL, 
            0xEAAF062B332F9D70ULL, 0x022F60F60D46B515ULL, 0xC52840BC2C97DF62ULL, 0x4C97A48B0240A868ULL, 
            0x7C15F50A51241875ULL, 0xD94DDE91633F8D61ULL, 0x2FF199B599226E3FULL, 0xE6D9EEDB0C009F18ULL, 
            0x18B729D84BC235D4ULL, 0xA1AB405D0D6FCB5EULL, 0xA0AE8F344D8E64D0ULL, 0x96A3D9A8194511E7ULL, 
            0xD5FDACC5B357B622ULL, 0xC3091848B8B2D0E1ULL, 0x7693A7A98E8A3922ULL, 0xBECD53803869C6DBULL, 
            0xC834A568B6374FEAULL, 0x49C15A7244E62DC1ULL, 0x24420D709BAB3BD9ULL, 0xE57BC2FB2BF9C033ULL, 
            0x77B3B6E9E2A91E36ULL, 0xD361A4D59431A3B1ULL, 0xD5D823BD8E50736EULL, 0xA22B8F858D512EB6ULL, 
            0x14DA50BB9A99839BULL, 0xF812956F935761FAULL, 0x1E902B4D649B26FAULL, 0x9CEF2282B11E61AFULL
        },
        {
            0xCB32B96798423634ULL, 0xAA34F16E381E6532ULL, 0x277AFDD8644EDAA5ULL, 0x3489B88387081349ULL, 
            0x65803006821AC473ULL, 0x5A974E792E7132C9ULL, 0x23381CCB43C50E59ULL, 0xC2642E752AF25895ULL, 
            0x26A2972598214F16ULL, 0x1250D04DF04FD6F2ULL, 0x2CA602E847CB0230ULL, 0x9672123BAA9B6905ULL, 
            0x3C86299BD3584589ULL, 0x8FFB69CD92A4A42BULL, 0x991F3B3047D63602ULL, 0xA3AAA5C368F6B7B2ULL, 
            0x4AAFB3BFFBBAA4C0ULL, 0x5E2C4FB916B23C9DULL, 0xBE759084F6595E1EULL, 0xE267D143EE4DBC0CULL, 
            0x463F8FD191105FC1ULL, 0x6E5F5099E2C382B8ULL, 0x0B05AB981C76FA63ULL, 0xD9582F20DC7C52FAULL, 
            0x3EFCF6C29FB6F87CULL, 0xB15287B6546FB292ULL, 0xD0FA9160D4B93459ULL, 0xF2B5DC924446F1AEULL, 
            0x14A5DCA3C7D40F28ULL, 0x12082CC9FEE8A67AULL, 0x29FE93CA52E43D32ULL, 0xF360079EE5E4729FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mebsuta::kPhaseCConstants = {
    0xC8D8B09E41E7BEB3ULL,
    0xED7CA0B19ADC12F7ULL,
    0x6E1CD33BA6BDC5DCULL,
    0xC8D8B09E41E7BEB3ULL,
    0xED7CA0B19ADC12F7ULL,
    0x6E1CD33BA6BDC5DCULL,
    0xEB80D04F6700425DULL,
    0x40D228A3CC67B7DEULL,
    0xC3,
    0xDA,
    0xCC,
    0xE0,
    0x11,
    0x95,
    0xA3,
    0xA5
};

const TwistDomainSaltSet TwistExpander_Mebsuta::kPhaseDSalts = {
    {
        {
            0x07F05F2BEA29EDEDULL, 0x2C1C541E9F85FF33ULL, 0x88CB73EDC44F8CB9ULL, 0xB0E1A699A00F1DC1ULL, 
            0xDD5607F5E93C64EAULL, 0xCAAC0A81159CDEE2ULL, 0x12870A94981E98D2ULL, 0x33C611177A8AD661ULL, 
            0xA124CA7F295F5869ULL, 0xB4A60B05715927BEULL, 0x636215EEA90C97C4ULL, 0x90691D0197AA4D9DULL, 
            0x452DEFDBB58FB79EULL, 0xD24BFEA114E9C69AULL, 0x3D5F24A7E8446E82ULL, 0xAABC46F582CFEE02ULL, 
            0x0517F4E923EFF224ULL, 0x2ED2BA5D930985C7ULL, 0x0C77805BD4D45C4DULL, 0x09A5BEE2F5BBC937ULL, 
            0x05EEE192AF7AC55EULL, 0x952899F1BBB09218ULL, 0xFF04DA7B2D7ED3D7ULL, 0xEDF4EB6B37D70E54ULL, 
            0xA8EA42552E9C0673ULL, 0xC506A05B3E97F558ULL, 0x0E24D9D189E2A934ULL, 0x1A49FC175CAD734EULL, 
            0xB9D14FCF5649BF3FULL, 0x3DE879220033DECCULL, 0xADCF3863C210EFD1ULL, 0x6EF9DCC5C4F6F52CULL
        },
        {
            0x818093E15FF58A88ULL, 0x94524B65184CAE9DULL, 0x72E0B62F3935BE87ULL, 0xA76E0EE356E45770ULL, 
            0x0B75FB30EF90D3F8ULL, 0x0F39B00C4295C0A1ULL, 0x676D9927506CF02AULL, 0xD3BA28B4CE0CA951ULL, 
            0x1E44147A4AFF7B61ULL, 0xCF4C33188D47672CULL, 0x83E57CC6CEE8E8B5ULL, 0x60D59DD3AF6DC620ULL, 
            0xACE2786C5D1775B2ULL, 0xE0F4F26E86A32BCBULL, 0xDA5532FCD1CE10FDULL, 0x0E3D4B4F2419D498ULL, 
            0x682B6954E38F6F46ULL, 0x80562C889333FD6FULL, 0x23E1AC1FDCFEE7D3ULL, 0x8DC0B0CE6F3C87E7ULL, 
            0xCF8433A4FD97092FULL, 0xCAB0CB994A4E0CD5ULL, 0x20F9F0355214EE78ULL, 0x11DC7EB1615499D2ULL, 
            0x6F03A6D9F3603E6BULL, 0x90991C0BA549889BULL, 0xC13FBFE6847D2232ULL, 0x5DA571F3E4CAFA97ULL, 
            0x2F3EB610F99C6B2AULL, 0xCD35651DB62DE955ULL, 0x796CC0E4EAFCC436ULL, 0xA34087434D45ED09ULL
        },
        {
            0x695CA89D9FF9D564ULL, 0x1E380C2C0DD9537DULL, 0x2732EFCEC44F5616ULL, 0x0E780CD761672BDAULL, 
            0x75C420C0F22249D5ULL, 0x97D8206C47A3BEC6ULL, 0x00EA50FAF84B92AAULL, 0x558C82FEA8416438ULL, 
            0x9C1CA1525615C3D8ULL, 0xB27DC54A7D53CF62ULL, 0xE6850693AA77F506ULL, 0xAB32D446F473226FULL, 
            0x8CEA08D9B36CA093ULL, 0x195B6375FE34F620ULL, 0x60F30D3FAEC78986ULL, 0x788258F11FC82186ULL, 
            0xA02A41E5C4EC4056ULL, 0xBC27ABE602952E2EULL, 0xF5E1D08510AD591DULL, 0xB36835BD267E0A4EULL, 
            0x8D05F0173A5F99FCULL, 0x9167D0DFB3AD93D1ULL, 0x35EAFDEBD1BF64E2ULL, 0x30B485CF21E4B726ULL, 
            0x15998DC310F63E17ULL, 0xEF6CBC637ECC1EF1ULL, 0x717B6E29466585C4ULL, 0x5D6E8E772DD52F3CULL, 
            0x8CA0802DA8D8A5FDULL, 0xBDF53891D3E664A7ULL, 0x730D3CDFC9227467ULL, 0x4FAA95C5F7FB3E1AULL
        },
        {
            0xF428C01A92D70DDAULL, 0x63120D4AE2FC124AULL, 0xD6E5ADEE2A40BE72ULL, 0xB4C30E79147F8B20ULL, 
            0x51D8F41007EC4A69ULL, 0x8A91FBEE2DEC7EF7ULL, 0xBF30F8B0F5ACE893ULL, 0xFE1B095D4A263482ULL, 
            0x07E59DC5C71CDF44ULL, 0x93971CDDB9446311ULL, 0x74E0BA93CB4ED9DBULL, 0xF9A8800B1276441DULL, 
            0x1D1D23ED488506A4ULL, 0xD963B829641A59AEULL, 0xF017F0D1E6FDD4B7ULL, 0xE7873355A10AF33DULL, 
            0xDB96CEE01376D387ULL, 0x2079E2836370A13CULL, 0x829681E859D9DEA6ULL, 0x37770CDE54250A53ULL, 
            0x7F61B472E08722B5ULL, 0x755B4A569D67A4A2ULL, 0xD7D0F6160DAC1CBFULL, 0x64669A03A66C7ADAULL, 
            0xEE57D3FC0F34C734ULL, 0x15039C3D7DC32F8BULL, 0x6F9A21F700BB530AULL, 0x67EC4F4F635BDDE5ULL, 
            0x955DCB9620C3EBF5ULL, 0x37FB8FFC1C07517AULL, 0x2C39C676F3AB90D0ULL, 0xD4F40048E77579E4ULL
        },
        {
            0x18EDE0434F8555E5ULL, 0x00885CA201224562ULL, 0xD8300C215DF419ACULL, 0x5D680C5FE69FA7ADULL, 
            0xF559353B110A6CB2ULL, 0x516E0E92C810F30DULL, 0x603F90C8E3334EFEULL, 0x0589B7F9F1762968ULL, 
            0xBECA199551F7FF2CULL, 0x4322B457ECC65F94ULL, 0x7111E23739FEAE21ULL, 0x4E5C20E1E5DE3391ULL, 
            0x04AE323E22F57B3EULL, 0x8EC5B79F2E3F3914ULL, 0x460FFB3846F5ACDEULL, 0x05FB3A9CB9934C4BULL, 
            0x321777CB9F25526AULL, 0xA4B165E317EA5D20ULL, 0x8407971AF2D8DEA0ULL, 0x70B74C2197D3BFBAULL, 
            0x25FB83DB9BA45052ULL, 0x8AFF1FD7B4A6D2BFULL, 0xAA9BDF61E9B1182BULL, 0x146337A23C47D11BULL, 
            0x2FF2958926A9AD28ULL, 0x6510058479ACA72AULL, 0xBB1942F209DA412FULL, 0x9EB9D3573E4E308DULL, 
            0xA5A38D74DD7905D1ULL, 0x7A0966C54DC9947DULL, 0x95D84529DF31CAC3ULL, 0xE929C80E0A3B94A2ULL
        },
        {
            0x887887A08E0921ABULL, 0x3770731A2E15088DULL, 0x06AB7274F8BC4491ULL, 0x584B24AE68D9067CULL, 
            0x6F9BC45F73149C12ULL, 0x4E13544A3F527DB4ULL, 0x8D4320074292310EULL, 0x21EA9E5B24AB4A56ULL, 
            0xCFB620D55A4007D0ULL, 0xE6A72D199496548CULL, 0x54088BB676E0CB52ULL, 0xA65CC66F9F089DCEULL, 
            0xB2CB2348D4AD0FF5ULL, 0xAD98BBBC99C713BEULL, 0x2861060C8F6B93FAULL, 0x9C6E756282A7E367ULL, 
            0xECBDE4DA7FB46367ULL, 0x908924C10C2EA185ULL, 0xFB40637ECD441761ULL, 0x558E31A04D29D897ULL, 
            0x8A0E4EE60CC1B582ULL, 0x435AA286E16079C8ULL, 0x0EAF6E497C8E2FA7ULL, 0xAE8D80454ACCC406ULL, 
            0x8D65F2B74333901FULL, 0xA13FB3847918B9C9ULL, 0x518F74DB0812FA26ULL, 0x8DDD47338CC68950ULL, 
            0x15E111FABB4B2D6CULL, 0x0339DFA38469D35CULL, 0xA1F5A8AE9EDCBE8EULL, 0x89E62D76FCCC8500ULL
        }
    },
    {
        {
            0x81DFEA436B77B601ULL, 0x9066882B5D0B0041ULL, 0xEA878AA60DE5E099ULL, 0x42DBA26EBB43EB59ULL, 
            0x2DD80FBB2C9B9B2AULL, 0xF6EFAF8CE3D23DCAULL, 0xCC7DD833D85F4E79ULL, 0x0187E92B721DA6D6ULL, 
            0x6A1AE7C6A2F6E688ULL, 0x8E24C534A78367F2ULL, 0x3FA4B6DB6E8BCD67ULL, 0xC38ACD82E71F5738ULL, 
            0xDC3EC24B7A23A9A8ULL, 0xA963621B0460A3A4ULL, 0x260D43173A35237DULL, 0x36850FDD90C38E8DULL, 
            0x5A302F424A4B863FULL, 0x05234F4222ABB63DULL, 0xA9F612FA085662FBULL, 0x587A520C730138BAULL, 
            0xF2A924FFEC2D826FULL, 0x6850DE666EA575AFULL, 0x877ACA1A82A8D85DULL, 0xBE9E24C33EE881FDULL, 
            0x86C4152DCBE6269EULL, 0x0CDECC8EE2C0B13BULL, 0xE6343E91589CAD8FULL, 0x58EB8434EE042C96ULL, 
            0x1FBE2DF6C9F6C911ULL, 0x1442381278B32CEDULL, 0xFA837BDE169DAC61ULL, 0xF45060B7858CCF75ULL
        },
        {
            0x4F8F7F4FAD009ADEULL, 0x9E57AD8A9694920AULL, 0xB3765BD8C785CC1DULL, 0x1D2B7467D43C4A8CULL, 
            0x6C2845625EE34E87ULL, 0x822B0CBB01A3704DULL, 0xBEC371867E79D306ULL, 0x3D328882D0C77007ULL, 
            0x51AC8F0C077E39F2ULL, 0x0ADD483032EE4F37ULL, 0x49998CB116928845ULL, 0xE86A7405DCA5B081ULL, 
            0x28ECE3182465386CULL, 0xC3207DB2E7E5DBCEULL, 0x731F8E67B15E9B6AULL, 0x4C5C478C4551C669ULL, 
            0xE2F18E63F82B874EULL, 0x541D28A3BEDBA254ULL, 0x6382D8371445D4CFULL, 0xA9F304148118094EULL, 
            0xDCCD4ED663CCEFFBULL, 0xE6F14ECDF66C474AULL, 0x3EE2B0CE3C0BEF5CULL, 0xEBCCB7A8612C55D0ULL, 
            0xFB850F90A63EB03AULL, 0x67280EE2FC240D9EULL, 0x1FAC7E109DA9383FULL, 0x215BE82CB62D37E9ULL, 
            0xCFCBB2BFBDE73715ULL, 0x19E4E77EA3B43AF4ULL, 0x456E39E317D37B26ULL, 0x3F549E9C8710FAFFULL
        },
        {
            0x673244AC9ACE7D60ULL, 0x86AF02B581EF59C8ULL, 0x7C03D7D207121B51ULL, 0x6D65C904A2431854ULL, 
            0x239F8DF978CF8DF0ULL, 0x598145F7673A3ED3ULL, 0xF00D4F9B84A77011ULL, 0x7034435A817DDD09ULL, 
            0x65AFE83E8F1E2D6EULL, 0x23B3FE50D812F27EULL, 0x1233F6129172BAD5ULL, 0xEB0EBFAC2FE993D6ULL, 
            0x06C4C343330F78CDULL, 0xB0FE46D1CADB842CULL, 0xDD8F0EF5C907317AULL, 0xC5A0BDB84DDECD8CULL, 
            0x10D74FADA99EEEFEULL, 0x1F609924108C03AFULL, 0x9A30A17E55595BFFULL, 0x8B71376AA63801ACULL, 
            0xFD7F973F036F4B5EULL, 0x855C526B4E99603FULL, 0x72CB4106E8C5A574ULL, 0x66E2FAE8667DE9FEULL, 
            0x0BE624AD9911E5DCULL, 0x32507FB6F22E58D3ULL, 0xD050EE57A0287F7BULL, 0xAF9616B52CEDC48BULL, 
            0x68CD218257958EBAULL, 0x4571E735392CBE24ULL, 0x9A5BD5C7B83AF0EAULL, 0x504B388F2DE1EB1FULL
        },
        {
            0xBC2072F513649291ULL, 0x02109CA054E3B1D6ULL, 0xB71D796DB14B901BULL, 0xB7E50D4DA4DA650AULL, 
            0x28E056EA293628E5ULL, 0x3DDCA95111AC4516ULL, 0xF61F83CE5ADF320AULL, 0x71F4D6CE647DAF0BULL, 
            0x071487E08A78C408ULL, 0x3A460ACF60820B84ULL, 0x9FB0F560BB07395FULL, 0x4A18587A898151EDULL, 
            0xF20D2BEA377EABD0ULL, 0xE40689FC89B855A6ULL, 0xA17AADCAB1979C39ULL, 0x95AE24D79E5893DFULL, 
            0x6714619EDC799D7FULL, 0x17FE584BA3C0F207ULL, 0x7CA9CD030C626932ULL, 0xA121D06A639EE78CULL, 
            0x45CB023434A97B77ULL, 0x90BB8104B946E084ULL, 0x1C77EAEA3E9E833BULL, 0x8BC8AB42BF9D76E9ULL, 
            0x694954FBEA5A74FEULL, 0x6A2DEE681268C8F9ULL, 0x0B26B1159E1EA14EULL, 0x03503C9ACB48996AULL, 
            0x6081C5DFFFF863FAULL, 0x6E5A6CE90B81EF89ULL, 0x40FA3E848B13AE3CULL, 0x91C93883AAFA018EULL
        },
        {
            0xEC81FB0759E4F193ULL, 0x9F42F4679AB6B8BDULL, 0x3E3877569B075EE7ULL, 0x79B45114E5AB42F0ULL, 
            0x1FC7E4CF12E8207BULL, 0x1173FB7C825BCC07ULL, 0x374C4DCEC5337313ULL, 0xB5423440CDADE346ULL, 
            0xF5ED339900118191ULL, 0xF93876239720EB7DULL, 0x2311FB3325A8DEFAULL, 0x7F12CEBE9692C220ULL, 
            0x17129AD0D872CD37ULL, 0xAF780B2CD041868CULL, 0x0A7EDE2AA2867430ULL, 0x934F0758C5DE4242ULL, 
            0x56A84D832E2DE97DULL, 0x233E714511280202ULL, 0xC63BE3D17AF55FACULL, 0x23C18B30251BD9B9ULL, 
            0x416FEF723DDD661CULL, 0xAFF357BFF5DE6AC3ULL, 0x22C7F80F682DCB89ULL, 0x9857386060760D96ULL, 
            0xB8484A85A2ECB8DAULL, 0x50580C4E4C4921B9ULL, 0xF8F44C636A99D0CAULL, 0xE368264F4B4DB0F1ULL, 
            0xE86A46A26A2B2897ULL, 0xD8F9FD751DA66231ULL, 0x1A6B8C0163ABFEBCULL, 0x44263E420CF78B93ULL
        },
        {
            0x40753805E91FC826ULL, 0xD228BA8719A6024FULL, 0xAD688A43D4E5D86CULL, 0xB5356926BE596052ULL, 
            0xE78D048F23416E75ULL, 0x24A9289F3D7C82F0ULL, 0xEAFD5DAB832946DCULL, 0xACC12E32324BF17CULL, 
            0x54D3F6957BEEE174ULL, 0xA5EA44145B70E521ULL, 0x4D630BB5DA281F7BULL, 0x67F1DB95351B5966ULL, 
            0x31676395BC762C5FULL, 0x8762B326B5D309DFULL, 0xD777045397F20BB9ULL, 0x0492A09CCB31ED7FULL, 
            0xF56E467BAF207025ULL, 0x3E463569812C5E3CULL, 0x01E20407A40B040DULL, 0x76D7C593D880058EULL, 
            0x6BC68B0B4DE69E07ULL, 0x5CA553835D95F0A1ULL, 0x4AB25E3A38E13196ULL, 0x0351030BFB239978ULL, 
            0x1FF8B60DDBA56DA2ULL, 0x43CB6B587E3D186CULL, 0x4A65F13E9346FB2FULL, 0x76129B0298CFDC6EULL, 
            0x1F83ADC150A5D62DULL, 0xCE010497D1A9BAA8ULL, 0x03E57DF817DF4000ULL, 0x83E5EA63E6A69A1BULL
        }
    },
    {
        {
            0xA6425A0F602E02A0ULL, 0x9D7C47759AB0BFE1ULL, 0x149DC65156749560ULL, 0x1AF29308F4EC423BULL, 
            0xA51A7E2C06F1DD1FULL, 0x1EAD2B119A0BC202ULL, 0x946ED0B7AF57FB8CULL, 0x4F73D2669AA67ACBULL, 
            0xF415B70B552E97B5ULL, 0x87DB37D583DF592FULL, 0xDCACAB6712722375ULL, 0xA94A8124D72907FCULL, 
            0x534C347C297C2E2BULL, 0x2C889B214FEAB5F3ULL, 0x93C6F360B4B02CE8ULL, 0xD312DD2C25B09D00ULL, 
            0x54DB5B18FEFFD5E2ULL, 0x3451ED0AD7E76212ULL, 0x0A248427F7A7DB84ULL, 0x2AEAD457A82B0CCAULL, 
            0x0FE632E485B5443CULL, 0x3D856739CE12C3A7ULL, 0x3E61E369DD7B3C3EULL, 0x753F9BF4AE020882ULL, 
            0x4DB0379BF6B9A86AULL, 0x7AC6AD59B862B876ULL, 0x396927B2095C0647ULL, 0x9AA8CCDB5ACD2ED2ULL, 
            0xAB499178606C7667ULL, 0x87F2447DC26871A8ULL, 0xF2C60C5A9E86A339ULL, 0xE6CA8C3F81C4174FULL
        },
        {
            0x96657332B8CFA119ULL, 0xDAFC8EC61312A7AEULL, 0x23D141EEE1EFB1E9ULL, 0x6E9B7FFD821CDD85ULL, 
            0x5854E08CF070F509ULL, 0x73D94353E0C0AEF7ULL, 0xD9F4795555643262ULL, 0x4B178CFB5FE392F2ULL, 
            0xB5DD25D4E7FE99DDULL, 0x2982E6B2D38F10CAULL, 0xB459D4100D22B9BDULL, 0xD9FD8729A5162699ULL, 
            0x90EAB2129CDC5195ULL, 0xAAC6D1C52B86F711ULL, 0xF7A300FBFD54CD44ULL, 0x7EAF91D16891DAC7ULL, 
            0x9A49D6732991B5E4ULL, 0xF545B86EA00D6C97ULL, 0xBCFB861A94D91F03ULL, 0xFAE5F099E5F10D7CULL, 
            0x9BA6305FECF98467ULL, 0x5947484F00E66AB8ULL, 0x184614FEA5E80E82ULL, 0xAA4C5DEE3D114BF7ULL, 
            0x0639F57FDFD78C79ULL, 0xC6CAFAB9DCE7ED5AULL, 0x4985FEF103422C15ULL, 0x67401C41F0E2D233ULL, 
            0x1BAA0F8C38D0D169ULL, 0x8F518F87A13A2985ULL, 0x230E12537E294157ULL, 0xD084CE35C3EC3D68ULL
        },
        {
            0x84C1494F8DF7F9E4ULL, 0xEAE736A4D7AAFFE7ULL, 0x4D0C1F47F3231265ULL, 0xC01CFA6E2B321BD1ULL, 
            0xBE43F15326773B4AULL, 0xBF188B3712D6EB04ULL, 0x6062E49EB6D3679FULL, 0x612333E46B0FB1F9ULL, 
            0x39334F3DC29393D5ULL, 0xB749F4E80EF73B4DULL, 0xBA73C83AEC4BF926ULL, 0x025FDD57A001C9FBULL, 
            0x424985AB317A16BEULL, 0x154951359F91F32EULL, 0x5323E6746401BEA9ULL, 0xB19CB76A71E0BE96ULL, 
            0xA16E5C1B801F47E3ULL, 0x01624776C6DEE3FCULL, 0xA7DC219A544B0A59ULL, 0x6A39244286174FA3ULL, 
            0xBB5B3202DE199830ULL, 0x2C9B06A39B19C15CULL, 0x152E537BA5E3360BULL, 0x39371E08857CB44EULL, 
            0x39466BCFD101DAE8ULL, 0x0747EA410E6C8642ULL, 0xE783EB0E655A9B5CULL, 0x7366D338031A5703ULL, 
            0x2E3305D55B02E6D2ULL, 0x9DFAA251E9AD652EULL, 0x414D34A48654945CULL, 0x8FE4C3C1DBEA3C5BULL
        },
        {
            0x050AE0EF520514D2ULL, 0xCC0FE03CA4936013ULL, 0x8BCFFA43F47B2A34ULL, 0x39AC9080735DB6C8ULL, 
            0x525BA617A2AFB615ULL, 0x9CBBF70A254AD42CULL, 0xA4770D1476CD1895ULL, 0x7066BBF8228E5D2DULL, 
            0x2A33C5F191806BAFULL, 0xAE4AB906D411A368ULL, 0x8279558D22C6E5ABULL, 0xCC073E0C890C6AB3ULL, 
            0xF5F945186DB8D9B4ULL, 0xD7FC202555D43281ULL, 0x51F32AB6D45BD595ULL, 0xB825E828B6DE1A56ULL, 
            0xFE8A66144AE66791ULL, 0xF5D1034A1CDF5118ULL, 0x5ED8A6F0E4E3C878ULL, 0x56E4F2D7250B592CULL, 
            0x26BD095CDC28B83DULL, 0x77CDA2FFED69A9E4ULL, 0xCA5DF11669B6A71FULL, 0x3A0B0EF104B3F940ULL, 
            0x98BD60D0BC91DBEBULL, 0x9FF6F6E330C737D5ULL, 0xBF931A36A0A29B5BULL, 0xB690AF7BCA5A2FF0ULL, 
            0x80B75EFD1B0A0AAFULL, 0x6CF8716EC5B51DE6ULL, 0x3B565BA9A5FAF67DULL, 0x058E1A86C4689C40ULL
        },
        {
            0x4C9D0607276993AFULL, 0x8338BDE4BC51C69BULL, 0x3230AC01F0A17EE4ULL, 0xA29CB8969245D830ULL, 
            0xEA009E6EB77480DFULL, 0xEB9290BFF36D5AB0ULL, 0xB15713612E3F0853ULL, 0xA418647CCBC55DBBULL, 
            0x9AE1A646C71ACADFULL, 0x518AB1D5607E2A38ULL, 0x6A1C8DF53A545192ULL, 0x12E80F32EC6FA6F4ULL, 
            0x45BA649D61EA3EBFULL, 0x0452CB6FD1935FBDULL, 0xBF99D5DF040B7E01ULL, 0x0B1EEC3D4A3C6C5BULL, 
            0xB3F5FEDDADA09683ULL, 0x2B25155318CE745EULL, 0x53D7E0571FE2F3F5ULL, 0xAB20329926A6D0E0ULL, 
            0xA1B9F2929024F67BULL, 0x57DCADAE9E31B8FBULL, 0xDAA56671B8FA1D1FULL, 0x246B0F7C2C0151B6ULL, 
            0xE44BD427141EAFDAULL, 0x5DEBA97B5829EBC5ULL, 0x347C5A3F6BB71A12ULL, 0x902ABC9BAAC53112ULL, 
            0x9D162F66EC631CA7ULL, 0x9F72E730517DD1B5ULL, 0x3FF339471D628AFCULL, 0x368A7F42F0EE1739ULL
        },
        {
            0xCA1CEAE69D54AADEULL, 0xB63CE8D4E1BA761AULL, 0x6BE7D741F06CE793ULL, 0x30EE2197E506BA19ULL, 
            0x960597882F56C637ULL, 0xDFC7BC858759BC7AULL, 0xA61321CF8E40B312ULL, 0xC756F182A5C357C2ULL, 
            0x0B7198DB99555342ULL, 0x9AC35F43EF378FA3ULL, 0xA29F8098D39A2B78ULL, 0x084215E2442D5789ULL, 
            0xC3DCB77CA18D5590ULL, 0xD0293BC1F3499747ULL, 0xB2D42950913013C9ULL, 0xFABF1AC8E3C041B6ULL, 
            0x1732239AC1F13F6FULL, 0xDD72209D573E6EB0ULL, 0x433F57AA039EEE74ULL, 0xD46297E14436EFBBULL, 
            0xA1F2D8DA02269531ULL, 0xAE21F470CDC9BB14ULL, 0x8916852C4E9BC1DCULL, 0x7B598DAE095A9235ULL, 
            0x131A8815607F406DULL, 0xB64B40134C1419DEULL, 0xB13AB33FE4E3EC61ULL, 0x2D1048B8D6245E25ULL, 
            0xD4B823C76E6A8C55ULL, 0xC9FF2FF822E42CF4ULL, 0x324C9BAB2EEE04C4ULL, 0x41B8BE31A284BB57ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Mebsuta::kPhaseDConstants = {
    0x2C33667F7FBAA942ULL,
    0xCFA9BECD8DF076FDULL,
    0x723338DF1FAC5665ULL,
    0x2C33667F7FBAA942ULL,
    0xCFA9BECD8DF076FDULL,
    0x723338DF1FAC5665ULL,
    0xE0F82F3CC5BB5A57ULL,
    0x9C046B84E12D5B75ULL,
    0x1E,
    0x76,
    0x28,
    0xF0,
    0x24,
    0xA0,
    0x11,
    0xEB
};

