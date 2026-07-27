#include "TwistExpander_Capella.hpp"
#include "TwistDiffuse.hpp"
#include "TwistFunctional.hpp"
#include "TwistIndexShuffle.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"
#include "TwistFarmSalt.hpp"
#include "TwistFarmConstants.hpp"
#include "TwistSquash.hpp"
#include "TwistShiftBox.hpp"

#include <cstdint>
#include <cstring>

TwistExpander_Capella::TwistExpander_Capella()
: TwistExpander() {
    mDomainBundleInbuilt.mKeyRotateSalts = kKeyRotateSalts;
    mDomainBundleInbuilt.mKeyRotateConstants = kKeyRotateConstants;
    mDomainBundleInbuilt.mKeySpawnSalts = kKeySpawnSalts;
    mDomainBundleInbuilt.mKeySpawnConstants = kKeySpawnConstants;
    mDomainBundleInbuilt.mSeedSalts = kSeedSalts;
    mDomainBundleInbuilt.mSeedConstants = kSeedConstants;
    mDomainBundleInbuilt.mTwistSalts = kTwistSalts;
    mDomainBundleInbuilt.mTwistConstants = kTwistConstants;
    mDomainBundleEphemeral.Zero();
}

void TwistExpander_Capella::KDF_A(TwistWorkSpace *pWorkSpace,
                                  std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet,
                                  std::uint8_t *pSnow) {
    TwistExpander::KDF_A(pWorkSpace, pNonce, pConstants, pDomainSaltSet, pSnow);
    if ((pWorkSpace == nullptr) || (pConstants == nullptr) ||
        (pDomainSaltSet == nullptr) || (pSnow == nullptr)) { return; }
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
    std::size_t *aIndexList256A = mIndexList256A;
    std::size_t *aIndexList256B = mIndexList256B;
    std::size_t *aIndexList256C = mIndexList256C;
    std::size_t *aIndexList256D = mIndexList256D;
    std::uint64_t aPrevious = 0x8AB5754DF7108656ULL; std::uint64_t aIngress = 0x90FBB65873AB1F67ULL; std::uint64_t aCarry = 0xA2278B6D97353353ULL;

    std::uint64_t aWandererA = 0xA85ECFCAB4EF8199ULL; std::uint64_t aWandererB = 0xE9A5006CCFEC258DULL; std::uint64_t aWandererC = 0xA5BB1246CE8EB0FFULL; std::uint64_t aWandererD = 0xF72DD5AB92E3B200ULL;
    std::uint64_t aWandererE = 0xCB0C0A54120A2253ULL; std::uint64_t aWandererF = 0xF8E608558D3F71B6ULL; std::uint64_t aWandererG = 0xBEF85EDD82C5FB3CULL; std::uint64_t aWandererH = 0x978F0481F6AA000DULL;
    std::uint64_t aWandererI = 0xBCC40BAF19BA322BULL; std::uint64_t aWandererJ = 0xC697C25E80296B9DULL; std::uint64_t aWandererK = 0x9CF0FCF534C43149ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xBB33AD03C4014B61ULL;
        aCarry = 0x999616490A64D2A3ULL;
        aWandererA = 0xDAC67BF5876EA6B5ULL;
        aWandererB = 0xE6C6F249C378ACECULL;
        aWandererC = 0xA98F901905CEBEF1ULL;
        aWandererD = 0x8E2B3D2C389C5282ULL;
        aWandererE = 0xD3A590BAD1BB0229ULL;
        aWandererF = 0xDEDFB6F2737E0743ULL;
        aWandererG = 0x8FD769C34FF411B0ULL;
        aWandererH = 0xE1D308C502697348ULL;
        aWandererI = 0xDDFFADEB53E82E0AULL;
        aWandererJ = 0x819144BC642BC7D0ULL;
        aWandererK = 0xAD7659D17284F371ULL;
    TwistExpander_Capella_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Capella_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Capella_Arx::KDF_A_C(pWorkSpace,
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

        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                         aFuseLaneC, aFuseLaneD,  // input lanes
                         aWaterLaneA, aWaterLaneB,
                         aWaterLaneC, aWaterLaneD, // output lanes
                         aFireLaneC, aFireLaneD, aWindLaneC, aWindLaneD, // index shuffle seeds
                         aWindLaneA, aWindLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    TwistExpander_Capella_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Capella::KDF_B(TwistWorkSpace *pWorkSpace,
                                  std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet,
                                  std::uint8_t *pSnow) {
    TwistExpander::KDF_B(pWorkSpace, pNonce, pConstants, pDomainSaltSet, pSnow);
    if ((pWorkSpace == nullptr) || (pConstants == nullptr) ||
        (pDomainSaltSet == nullptr) || (pSnow == nullptr)) { return; }
    std::uint8_t *aFuseLaneA = pWorkSpace->mFuseLaneA;
    std::uint8_t *aFuseLaneB = pWorkSpace->mFuseLaneB;
    std::uint8_t *aFuseLaneC = pWorkSpace->mFuseLaneC;
    std::uint8_t *aFuseLaneD = pWorkSpace->mFuseLaneD;
    std::uint8_t *aLightningLaneA = pWorkSpace->mLightningLaneA;
    std::uint8_t *aLightningLaneB = pWorkSpace->mLightningLaneB;
    std::uint8_t *aLightningLaneC = pWorkSpace->mLightningLaneC;
    std::uint8_t *aLightningLaneD = pWorkSpace->mLightningLaneD;
    std::uint8_t *aSoilLaneC = pWorkSpace->mSoilLaneC;
    std::uint8_t *aSoilLaneD = pWorkSpace->mSoilLaneD;
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;
    std::size_t *aIndexList256A = mIndexList256A;
    std::size_t *aIndexList256B = mIndexList256B;
    std::size_t *aIndexList256C = mIndexList256C;
    std::size_t *aIndexList256D = mIndexList256D;
    std::uint64_t aPrevious = 0xF3ED3765C9C5ADA3ULL; std::uint64_t aIngress = 0xAEA624A3F1DE638CULL; std::uint64_t aCarry = 0x9BCB5251C2D60E76ULL;

    std::uint64_t aWandererA = 0xB00A180150582490ULL; std::uint64_t aWandererB = 0xD7144A72B84F683EULL; std::uint64_t aWandererC = 0xBD231D07A61F1C5CULL; std::uint64_t aWandererD = 0xA8EBF3E9F832CA67ULL;
    std::uint64_t aWandererE = 0x805187573A872412ULL; std::uint64_t aWandererF = 0xF0375ED2DA7187E9ULL; std::uint64_t aWandererG = 0xB0C4D77DE32D14BDULL; std::uint64_t aWandererH = 0x9EAB849D5B8E0CF3ULL;
    std::uint64_t aWandererI = 0xF1EF0B4617C264F5ULL; std::uint64_t aWandererJ = 0x9C3F54EE5C29E790ULL; std::uint64_t aWandererK = 0x9AFD79EDBA0DF7B1ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xED3BF732AE60EEDDULL;
        aCarry = 0xD9DFEEDF1C36DCE3ULL;
        aWandererA = 0xA5166877205722E2ULL;
        aWandererB = 0x99EB95F2CAE9E29FULL;
        aWandererC = 0xAE6EF1B93DB01FBCULL;
        aWandererD = 0xDDF3F0480B468AF8ULL;
        aWandererE = 0x86A3ADD0CFC1D061ULL;
        aWandererF = 0xBC534F27B8D06119ULL;
        aWandererG = 0xA099B62F2D02A74DULL;
        aWandererH = 0xF44BD9280A7A1D12ULL;
        aWandererI = 0xA297D818466DBB95ULL;
        aWandererJ = 0xEF85D7C10C0DC989ULL;
        aWandererK = 0xB8C38DD3BACCDC70ULL;
    TwistExpander_Capella_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Capella_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Capella_Arx::KDF_B_C(pWorkSpace,
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

        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                         aFuseLaneC, aFuseLaneD,  // input lanes
                         aIceLaneA, aIceLaneB,
                         aIceLaneC, aIceLaneD, // output lanes
                         aSoilLaneC, aSoilLaneD, aLightningLaneC, aLightningLaneD, // index shuffle seeds
                         aLightningLaneA, aLightningLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    TwistExpander_Capella_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Capella::KDF_C(TwistWorkSpace *pWorkSpace,
                                  std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet,
                                  std::uint8_t *pSnow) {
    TwistExpander::KDF_C(pWorkSpace, pNonce, pConstants, pDomainSaltSet, pSnow);
    if ((pWorkSpace == nullptr) || (pConstants == nullptr) ||
        (pDomainSaltSet == nullptr) || (pSnow == nullptr)) { return; }
    std::uint8_t *aFuseLaneA = pWorkSpace->mFuseLaneA;
    std::uint8_t *aFuseLaneB = pWorkSpace->mFuseLaneB;
    std::uint8_t *aFuseLaneC = pWorkSpace->mFuseLaneC;
    std::uint8_t *aFuseLaneD = pWorkSpace->mFuseLaneD;
    std::uint8_t *aMagmaLaneC = pWorkSpace->mMagmaLaneC;
    std::uint8_t *aMagmaLaneD = pWorkSpace->mMagmaLaneD;
    std::uint8_t *aPlasmaLaneA = pWorkSpace->mPlasmaLaneA;
    std::uint8_t *aPlasmaLaneB = pWorkSpace->mPlasmaLaneB;
    std::uint8_t *aPlasmaLaneC = pWorkSpace->mPlasmaLaneC;
    std::uint8_t *aPlasmaLaneD = pWorkSpace->mPlasmaLaneD;
    std::uint8_t *aShadowLaneA = pWorkSpace->mShadowLaneA;
    std::uint8_t *aShadowLaneB = pWorkSpace->mShadowLaneB;
    std::uint8_t *aShadowLaneC = pWorkSpace->mShadowLaneC;
    std::uint8_t *aShadowLaneD = pWorkSpace->mShadowLaneD;
    std::size_t *aIndexList256A = mIndexList256A;
    std::size_t *aIndexList256B = mIndexList256B;
    std::size_t *aIndexList256C = mIndexList256C;
    std::size_t *aIndexList256D = mIndexList256D;
    std::uint64_t aPrevious = 0xFE3A228A022755CDULL; std::uint64_t aIngress = 0x9C586650F49668BCULL; std::uint64_t aCarry = 0xD27A3861BDB3EC5DULL;

    std::uint64_t aWandererA = 0xE5DF94E1D3E160B3ULL; std::uint64_t aWandererB = 0xC91AF126DBAFAE7AULL; std::uint64_t aWandererC = 0xF4C373D26E56D20CULL; std::uint64_t aWandererD = 0xD6738979167487F7ULL;
    std::uint64_t aWandererE = 0x9B75ED524BB6CB60ULL; std::uint64_t aWandererF = 0xEB6C8F16758C5BE8ULL; std::uint64_t aWandererG = 0xE6F0211954C6F976ULL; std::uint64_t aWandererH = 0xCC2B5F4572133844ULL;
    std::uint64_t aWandererI = 0xF6AE430CCF831E69ULL; std::uint64_t aWandererJ = 0x9FD5B392C931B456ULL; std::uint64_t aWandererK = 0x93D984905DD89D74ULL;

    // [kdf-c]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xF8798D02400D2549ULL;
        aCarry = 0xAF294AA2EAD5E5F5ULL;
        aWandererA = 0xA7C0A2B229B834C8ULL;
        aWandererB = 0xCACBC896C87F48DEULL;
        aWandererC = 0xE8FAB2D416863166ULL;
        aWandererD = 0xA1C2F4F93DF6D562ULL;
        aWandererE = 0xB9609E02D3F036EDULL;
        aWandererF = 0xFD3495F477A225A8ULL;
        aWandererG = 0x9B1274646B20CADDULL;
        aWandererH = 0x8E6D03029C8A1814ULL;
        aWandererI = 0xBB0C4EB4A5A6531AULL;
        aWandererJ = 0xBFFBA7D2E5AEC082ULL;
        aWandererK = 0x924E3EEE5CCFF2D9ULL;
    TwistExpander_Capella_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Capella_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Capella_Arx::KDF_C_C(pWorkSpace,
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

        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                         aFuseLaneC, aFuseLaneD,  // input lanes
                         aShadowLaneA, aShadowLaneB,
                         aShadowLaneC, aShadowLaneD, // output lanes
                         aMagmaLaneC, aMagmaLaneD, aPlasmaLaneC, aPlasmaLaneD, // index shuffle seeds
                         aPlasmaLaneA, aPlasmaLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    TwistExpander_Capella_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Capella::KDF_D(TwistWorkSpace *pWorkSpace,
                                  std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet,
                                  std::uint8_t *pSnow) {
    TwistExpander::KDF_D(pWorkSpace, pNonce, pConstants, pDomainSaltSet, pSnow);
    if ((pWorkSpace == nullptr) || (pConstants == nullptr) ||
        (pDomainSaltSet == nullptr) || (pSnow == nullptr)) { return; }
    std::uint8_t *aFuseLaneA = pWorkSpace->mFuseLaneA;
    std::uint8_t *aFuseLaneB = pWorkSpace->mFuseLaneB;
    std::uint8_t *aFuseLaneC = pWorkSpace->mFuseLaneC;
    std::uint8_t *aFuseLaneD = pWorkSpace->mFuseLaneD;
    std::uint8_t *aAetherLaneC = pWorkSpace->mAetherLaneC;
    std::uint8_t *aAetherLaneD = pWorkSpace->mAetherLaneD;
    std::uint8_t *aCelestialLaneA = pWorkSpace->mCelestialLaneA;
    std::uint8_t *aCelestialLaneB = pWorkSpace->mCelestialLaneB;
    std::uint8_t *aCelestialLaneC = pWorkSpace->mCelestialLaneC;
    std::uint8_t *aCelestialLaneD = pWorkSpace->mCelestialLaneD;
    std::uint8_t *aVaporLaneA = pWorkSpace->mVaporLaneA;
    std::uint8_t *aVaporLaneB = pWorkSpace->mVaporLaneB;
    std::uint8_t *aVaporLaneC = pWorkSpace->mVaporLaneC;
    std::uint8_t *aVaporLaneD = pWorkSpace->mVaporLaneD;
    std::size_t *aIndexList256A = mIndexList256A;
    std::size_t *aIndexList256B = mIndexList256B;
    std::size_t *aIndexList256C = mIndexList256C;
    std::size_t *aIndexList256D = mIndexList256D;
    std::uint64_t aPrevious = 0xD806AEC1D506F2ACULL; std::uint64_t aIngress = 0x9EFA505C048A8ADCULL; std::uint64_t aCarry = 0xB36D5E61000ACC0CULL;

    std::uint64_t aWandererA = 0xE0B55156EF30DB24ULL; std::uint64_t aWandererB = 0x82D5C96B90BCCC1CULL; std::uint64_t aWandererC = 0xDE826A9F7FA81430ULL; std::uint64_t aWandererD = 0x8E6404E274BD6945ULL;
    std::uint64_t aWandererE = 0xBAAF5FC6B6F00D82ULL; std::uint64_t aWandererF = 0xFA4D45AC567A097AULL; std::uint64_t aWandererG = 0x9F3860CF9BA7E8B0ULL; std::uint64_t aWandererH = 0xE8656E4B08B34B39ULL;
    std::uint64_t aWandererI = 0x81FCF75BBF0B7DD9ULL; std::uint64_t aWandererJ = 0xFACF0D9139724078ULL; std::uint64_t aWandererK = 0xE71E2BBA75930947ULL;

    // [kdf-d]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xF75EDF8B2D1F193EULL;
        aCarry = 0xAA7B63676C084803ULL;
        aWandererA = 0xC6787E8D98BEDCBFULL;
        aWandererB = 0xCF8E37861EBA28D4ULL;
        aWandererC = 0x9D3B07CC466349C3ULL;
        aWandererD = 0xBCF3EC67E0D93FC5ULL;
        aWandererE = 0xB05C1A6057F6504AULL;
        aWandererF = 0xCA186CF4FAFD961AULL;
        aWandererG = 0xEDD155F3AACCC555ULL;
        aWandererH = 0x960F761E00D514DFULL;
        aWandererI = 0xDA42A64DDC8EADB2ULL;
        aWandererJ = 0xFD4F31B2276F1E7DULL;
        aWandererK = 0x80B77A9AB6507137ULL;
    TwistExpander_Capella_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Capella_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Capella_Arx::KDF_D_C(pWorkSpace,
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

        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                         aFuseLaneC, aFuseLaneD,  // input lanes
                         aVaporLaneA, aVaporLaneB,
                         aVaporLaneC, aVaporLaneD, // output lanes
                         aAetherLaneC, aAetherLaneD, aCelestialLaneC, aCelestialLaneD, // index shuffle seeds
                         aCelestialLaneA, aCelestialLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    TwistExpander_Capella_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Capella::Seed(TwistWorkSpace *pWorkSpace,
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
    mDomainBundleInbuilt.mKeyRotateSalts = kKeyRotateSalts;
    mDomainBundleInbuilt.mKeyRotateConstants = kKeyRotateConstants;
    mDomainBundleInbuilt.mKeySpawnSalts = kKeySpawnSalts;
    mDomainBundleInbuilt.mKeySpawnConstants = kKeySpawnConstants;
    mDomainBundleInbuilt.mSeedSalts = kSeedSalts;
    mDomainBundleInbuilt.mSeedConstants = kSeedConstants;
    mDomainBundleInbuilt.mTwistSalts = kTwistSalts;
    mDomainBundleInbuilt.mTwistConstants = kTwistConstants;
    mDomainBundleEphemeral.Zero();
    pWorkSpace->mDomainBundle.Zero();
    std::uint8_t *aHeartLaneA = pWorkSpace->mHeartLaneA;
    std::uint8_t *aHeartLaneB = pWorkSpace->mHeartLaneB;
    std::uint8_t *aHeartLaneC = pWorkSpace->mHeartLaneC;
    std::uint8_t *aHeartLaneD = pWorkSpace->mHeartLaneD;
    std::uint8_t *aPoisonLaneA = pWorkSpace->mPoisonLaneA;
    std::uint8_t *aPoisonLaneB = pWorkSpace->mPoisonLaneB;
    std::uint8_t *aPoisonLaneC = pWorkSpace->mPoisonLaneC;
    std::uint8_t *aPoisonLaneD = pWorkSpace->mPoisonLaneD;
    std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    std::uint8_t *aEarthLaneA = pWorkSpace->mEarthLaneA;
    std::uint8_t *aEarthLaneB = pWorkSpace->mEarthLaneB;
    std::uint8_t *aEarthLaneC = pWorkSpace->mEarthLaneC;
    std::uint8_t *aEarthLaneD = pWorkSpace->mEarthLaneD;
    std::uint8_t *aWindLaneA = pWorkSpace->mWindLaneA;
    std::uint8_t *aWindLaneB = pWorkSpace->mWindLaneB;
    std::uint8_t *aWindLaneC = pWorkSpace->mWindLaneC;
    std::uint8_t *aWindLaneD = pWorkSpace->mWindLaneD;
    std::uint8_t *aFuseLaneA = pWorkSpace->mFuseLaneA;
    std::uint8_t *aFuseLaneB = pWorkSpace->mFuseLaneB;
    std::uint8_t *aFuseLaneC = pWorkSpace->mFuseLaneC;
    std::uint8_t *aFuseLaneD = pWorkSpace->mFuseLaneD;
    std::uint8_t *aWoodLaneA = pWorkSpace->mWoodLaneA;
    std::uint8_t *aWoodLaneB = pWorkSpace->mWoodLaneB;
    std::uint8_t *aWoodLaneC = pWorkSpace->mWoodLaneC;
    std::uint8_t *aWoodLaneD = pWorkSpace->mWoodLaneD;
    std::uint8_t *aLightningLaneC = pWorkSpace->mLightningLaneC;
    std::uint8_t *aLightningLaneD = pWorkSpace->mLightningLaneD;
    std::uint8_t *aMagmaLaneA = pWorkSpace->mMagmaLaneA;
    std::uint8_t *aMagmaLaneB = pWorkSpace->mMagmaLaneB;
    std::uint8_t *aMagmaLaneC = pWorkSpace->mMagmaLaneC;
    std::uint8_t *aMagmaLaneD = pWorkSpace->mMagmaLaneD;
    std::uint8_t *aPlasmaLaneC = pWorkSpace->mPlasmaLaneC;
    std::uint8_t *aPlasmaLaneD = pWorkSpace->mPlasmaLaneD;
    std::uint8_t *aCrystalLaneA = pWorkSpace->mCrystalLaneA;
    std::uint8_t *aCrystalLaneB = pWorkSpace->mCrystalLaneB;
    std::uint8_t *aCrystalLaneC = pWorkSpace->mCrystalLaneC;
    std::uint8_t *aCrystalLaneD = pWorkSpace->mCrystalLaneD;
    std::uint8_t *aAetherLaneC = pWorkSpace->mAetherLaneC;
    std::uint8_t *aAetherLaneD = pWorkSpace->mAetherLaneD;
    std::uint8_t *aCelestialLaneA = pWorkSpace->mCelestialLaneA;
    std::uint8_t *aCelestialLaneB = pWorkSpace->mCelestialLaneB;
    std::uint8_t *aCelestialLaneC = pWorkSpace->mCelestialLaneC;
    std::uint8_t *aCelestialLaneD = pWorkSpace->mCelestialLaneD;
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;
    std::size_t *aIndexList256A = mIndexList256A;
    std::size_t *aIndexList256B = mIndexList256B;
    std::size_t *aIndexList256C = mIndexList256C;
    std::size_t *aIndexList256D = mIndexList256D;
    std::uint64_t aPrevious = 0xC7E5B97A5302AA0BULL;
    std::uint64_t aIngress = 0xBCE1EB830B78C30CULL;
    std::uint64_t aCarry = 0xB4FF6BC0C2790120ULL;

    std::uint64_t aWandererA = 0xCFA42BD840006F3EULL;
    std::uint64_t aWandererB = 0xA8D64039215C0F16ULL;
    std::uint64_t aWandererC = 0x944BD4B2A7797339ULL;
    std::uint64_t aWandererD = 0xB53CDFFC735FD373ULL;
    std::uint64_t aWandererE = 0xE9EFA12BB516C664ULL;
    std::uint64_t aWandererF = 0xAAC9A667D1F5CC72ULL;
    std::uint64_t aWandererG = 0xFC339AEB0BFE99CAULL;
    std::uint64_t aWandererH = 0xB98F9FFA73CC0351ULL;
    std::uint64_t aWandererI = 0xA9813A784379BEAAULL;
    std::uint64_t aWandererJ = 0x94954A074DD60494ULL;
    std::uint64_t aWandererK = 0xFED19D6CC3156DD9ULL;

    // [seed]
    ////////////////////////////////////////////////////////
    ////////        KeyRotate
    ////////
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateConstants), &(mDomainBundleInbuilt.mKeyRotateSalts), pSnowLaneB);
    ////////
    pFarmSalt->Derive(aHeartLaneA, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aHeartLaneB, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aHeartLaneC, mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltF);
    ////////
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeyRotateConstants));
    ////////
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateConstants), &(mDomainBundleEphemeral.mKeyRotateSalts), pSnowLaneB);
    ////////
    // wood lanes to pWorkSpace->mDomainBundle
    pFarmSalt->Derive(aWoodLaneA, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWoodLaneB, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWoodLaneC, pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeyRotateConstants));
    ////////
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateConstants), &(mDomainBundleEphemeral.mKeyRotateSalts), pSnowLaneB);
    ////////
    // crystal lanes to mDomainBundleEphemeral
    pFarmSalt->Derive(aCrystalLaneA, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aCrystalLaneB, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeyRotateSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aCrystalLaneC, mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeyRotateSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeyRotateConstants));
    ////////
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateConstants), &(mDomainBundleEphemeral.mKeyRotateSalts), pSnowLaneB);
    ////////
    // poison lanes to pWorkSpace->mDomainBundle
    pFarmSalt->Derive(aPoisonLaneA, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aPoisonLaneB, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aPoisonLaneC, pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeyRotateSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aPoisonLaneD, &(pWorkSpace->mDomainBundle.mKeyRotateConstants));
    ////////
    TwistSquash::SquashC(aPoisonLaneA, aPoisonLaneB, aPoisonLaneC, aPoisonLaneD, pWorkSpace->mDomainLaneKeyRotate);
    ////////
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        KeySpawn
    ////////
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnConstants), &(mDomainBundleInbuilt.mKeySpawnSalts), pSnowLaneD);
    ////////
    pFarmSalt->Derive(aHeartLaneA, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aHeartLaneB, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aHeartLaneC, mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltF);
    ////////
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mKeySpawnConstants));
    ////////
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnConstants), &(mDomainBundleEphemeral.mKeySpawnSalts), pSnowLaneD);
    ////////
    // wood lanes to pWorkSpace->mDomainBundle
    pFarmSalt->Derive(aWoodLaneA, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWoodLaneB, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWoodLaneC, pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnConstants));
    ////////
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnConstants), &(mDomainBundleEphemeral.mKeySpawnSalts), pSnowLaneD);
    ////////
    // crystal lanes to mDomainBundleEphemeral
    pFarmSalt->Derive(aCrystalLaneA, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aCrystalLaneB, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeySpawnSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aCrystalLaneC, mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mKeySpawnSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mKeySpawnConstants));
    ////////
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnConstants), &(mDomainBundleEphemeral.mKeySpawnSalts), pSnowLaneD);
    ////////
    // poison lanes to pWorkSpace->mDomainBundle
    pFarmSalt->Derive(aPoisonLaneA, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aPoisonLaneB, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aPoisonLaneC, pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mKeySpawnSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aPoisonLaneD, &(pWorkSpace->mDomainBundle.mKeySpawnConstants));
    ////////
    TwistSquash::SquashB(aPoisonLaneA, aPoisonLaneB, aPoisonLaneC, aPoisonLaneD, pWorkSpace->mDomainLaneKeySpawn);
    ////////
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Seed
    ////////
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneA);
    ////////
    pFarmSalt->Derive(aHeartLaneA, mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aHeartLaneB, mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aHeartLaneC, mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltF);
    ////////
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    ////////
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneA);
    ////////
    // wood lanes to pWorkSpace->mDomainBundle
    pFarmSalt->Derive(aWoodLaneA, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWoodLaneB, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWoodLaneC, pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mSeedConstants));
    ////////
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneA);
    ////////
    // crystal lanes to mDomainBundleEphemeral
    pFarmSalt->Derive(aCrystalLaneA, mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aCrystalLaneB, mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mSeedSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aCrystalLaneC, mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mSeedSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mSeedConstants));
    ////////
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneA);
    ////////
    // poison lanes to pWorkSpace->mDomainBundle
    pFarmSalt->Derive(aPoisonLaneA, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aPoisonLaneB, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mSeedSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aPoisonLaneC, pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mSeedSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aPoisonLaneD, &(pWorkSpace->mDomainBundle.mSeedConstants));
    ////////
    TwistSquash::SquashC(aPoisonLaneA, aPoisonLaneB, aPoisonLaneC, aPoisonLaneD, pWorkSpace->mDomainLaneSeed);
    ////////
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Twist
    ////////
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneC);
    ////////
    pFarmSalt->Derive(aHeartLaneA, mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aHeartLaneB, mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aHeartLaneC, mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltF);
    ////////
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    ////////
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneC);
    ////////
    // wood lanes to pWorkSpace->mDomainBundle
    pFarmSalt->Derive(aWoodLaneA, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWoodLaneB, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWoodLaneC, pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mTwistConstants));
    ////////
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneC);
    ////////
    // crystal lanes to mDomainBundleEphemeral
    pFarmSalt->Derive(aCrystalLaneA, mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aCrystalLaneB, mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aCrystalLaneC, mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    ////////
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneC);
    ////////
    // poison lanes to pWorkSpace->mDomainBundle
    pFarmSalt->Derive(aPoisonLaneA, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aPoisonLaneB, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aPoisonLaneC, pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aPoisonLaneD, &(pWorkSpace->mDomainBundle.mTwistConstants));
    ////////
    TwistSquash::SquashA(aPoisonLaneA, aPoisonLaneB, aPoisonLaneC, aPoisonLaneD, pWorkSpace->mDomainLaneTwist);
    ////////
    ////////
    ////////
    ////////////////////////////////////////////////////////
    TwistExpander_Capella_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Capella_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Capella_Arx::Seed_C(pWorkSpace,
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
    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mSeedConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mSeedConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mSeedConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mSeedConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mSeedConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mSeedConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mSeedConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mSeedConstants.mMatrixArgD;
    //
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                         aFuseLaneC, aFuseLaneD,  // input lanes
                         aHeartLaneA, aHeartLaneB,
                         aHeartLaneC, aHeartLaneD, // output lanes
                         aPlasmaLaneC, aPlasmaLaneD, aMagmaLaneC, aMagmaLaneD, // index shuffle seeds
                         aMagmaLaneA, aMagmaLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    TwistExpander_Capella_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Capella_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Capella_Arx::Seed_F(pWorkSpace,
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
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                         aFuseLaneC, aFuseLaneD,  // input lanes
                         aWindLaneA, aWindLaneB,
                         aWindLaneC, aWindLaneD, // output lanes
                         aCrystalLaneC, aCrystalLaneD, aEarthLaneC, aEarthLaneD, // index shuffle seeds
                         aEarthLaneA, aEarthLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    TwistExpander_Capella_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Capella_Arx::Seed_H(pWorkSpace,
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

    TwistExpander_Capella_Arx::Seed_I(pWorkSpace,
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
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                         aFuseLaneC, aFuseLaneD,  // input lanes
                         aCelestialLaneA, aCelestialLaneB,
                         aCelestialLaneC, aCelestialLaneD, // output lanes
                         aAetherLaneC, aAetherLaneD, aFireLaneC, aFireLaneD, // index shuffle seeds
                         aFireLaneA, aFireLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    TwistExpander_Capella_Arx::Seed_J(pWorkSpace,
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

    TwistExpander_Capella_Arx::Seed_K(pWorkSpace,
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

    TwistExpander_Capella_Arx::Seed_L(pWorkSpace,
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
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                         aFuseLaneC, aFuseLaneD,  // input lanes
                         aWoodLaneA, aWoodLaneB,
                         aWoodLaneC, aWoodLaneD, // output lanes
                         aLightningLaneC, aLightningLaneD, aIceLaneC, aIceLaneD, // index shuffle seeds
                         aIceLaneA, aIceLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    TwistExpander_Capella_Arx::Seed_M(pWorkSpace,
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

    TwistExpander_Capella_Arx::Seed_N(pWorkSpace,
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
    // [KEY — sixteen key rows, lane splits A-P]
    //
    TwistExpander_Capella_Arx::KEY(pWorkSpace,
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

    FoldSeed(pWorkSpace, pDestination);
    GrowKeyA(pWorkSpace,
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
    GrowKeyB(pWorkSpace,
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
    FoldKeyRows(pWorkSpace);
    pWorkSpace->Zero_PostSeed();
    Zero_PostSeed();
}

void TwistExpander_Capella::TwistBlock(TwistWorkSpace *pWorkSpace,
                                       std::uint8_t *pSource,
                                       std::uint8_t *pSnowLaneA,
                                       std::uint8_t *pSnowLaneB,
                                       std::uint8_t *pSnowLaneC,
                                       std::uint8_t *pSnowLaneD,
                                       std::uint8_t *pDestination) {
    TwistExpander::TwistBlock(pWorkSpace,
                              pSource,
                              pSnowLaneA,
                              pSnowLaneB,
                              pSnowLaneC,
                              pSnowLaneD,
                              pDestination);
    if ((pWorkSpace == nullptr) || (pSource == nullptr) ||
        (pSnowLaneA == nullptr) || (pSnowLaneB == nullptr) ||
        (pSnowLaneC == nullptr) || (pSnowLaneD == nullptr) ||
        (pDestination == nullptr)) { return; }
    std::uint8_t *aHeartLaneA = pWorkSpace->mHeartLaneA;
    std::uint8_t *aHeartLaneB = pWorkSpace->mHeartLaneB;
    std::uint8_t *aHeartLaneC = pWorkSpace->mHeartLaneC;
    std::uint8_t *aHeartLaneD = pWorkSpace->mHeartLaneD;
    std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    std::uint8_t *aWaterLaneA = pWorkSpace->mWaterLaneA;
    std::uint8_t *aWaterLaneB = pWorkSpace->mWaterLaneB;
    std::uint8_t *aWaterLaneC = pWorkSpace->mWaterLaneC;
    std::uint8_t *aWaterLaneD = pWorkSpace->mWaterLaneD;
    std::uint8_t *aFuseLaneA = pWorkSpace->mFuseLaneA;
    std::uint8_t *aFuseLaneB = pWorkSpace->mFuseLaneB;
    std::uint8_t *aFuseLaneC = pWorkSpace->mFuseLaneC;
    std::uint8_t *aFuseLaneD = pWorkSpace->mFuseLaneD;
    std::uint8_t *aWoodLaneA = pWorkSpace->mWoodLaneA;
    std::uint8_t *aWoodLaneB = pWorkSpace->mWoodLaneB;
    std::uint8_t *aWoodLaneC = pWorkSpace->mWoodLaneC;
    std::uint8_t *aWoodLaneD = pWorkSpace->mWoodLaneD;
    std::uint8_t *aLightningLaneC = pWorkSpace->mLightningLaneC;
    std::uint8_t *aLightningLaneD = pWorkSpace->mLightningLaneD;
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;
    std::size_t *aIndexList256A = mIndexList256A;
    std::size_t *aIndexList256B = mIndexList256B;
    std::size_t *aIndexList256C = mIndexList256C;
    std::size_t *aIndexList256D = mIndexList256D;
    std::uint64_t aPrevious = 0x8EDF13358180AB83ULL; std::uint64_t aIngress = 0xAE031D068E13F397ULL; std::uint64_t aCarry = 0xCB88542DBB5F7ADDULL;

    std::uint64_t aWandererA = 0x91413B041C6525ECULL; std::uint64_t aWandererB = 0xF8B33E0C4FEFCEF1ULL; std::uint64_t aWandererC = 0x80FE1486D1035CF3ULL; std::uint64_t aWandererD = 0xDB341592A72ED110ULL;
    std::uint64_t aWandererE = 0xA39F9E7AFDD5AFC6ULL; std::uint64_t aWandererF = 0x876CE47195F7B736ULL; std::uint64_t aWandererG = 0xBB91B67DA960647AULL; std::uint64_t aWandererH = 0xF29F98C3AA49FEB6ULL;
    std::uint64_t aWandererI = 0xE3D33C8FAEFB4FCCULL; std::uint64_t aWandererJ = 0xF4E570C1B81FD13AULL; std::uint64_t aWandererK = 0xAD4C1581D5A177E0ULL;

    // [twist]
        aPrevious = 0x8169BE8EBBF27724ULL;
        aCarry = 0xB1D74C20474ECF79ULL;
        aWandererA = 0xCA3B6A90E37F61F0ULL;
        aWandererB = 0xC56E12917EBA36D0ULL;
        aWandererC = 0xA27479BE3F5B5E4DULL;
        aWandererD = 0xA104491296EE4CE9ULL;
        aWandererE = 0xF9BE429F04ECF639ULL;
        aWandererF = 0xC7C42C01E79F1888ULL;
        aWandererG = 0xE816637782499233ULL;
        aWandererH = 0x98B68CE5E7F1C3BCULL;
        aWandererI = 0xF22B15A7ECCF482EULL;
        aWandererJ = 0xE92A5CA95F76725FULL;
        aWandererK = 0x89D7BC631A0EDA2FULL;
    TwistExpander_Capella_Arx::Twist_A(pWorkSpace,
                 pSource,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
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

    TwistExpander_Capella_Arx::Twist_B(pWorkSpace,
                 pSource,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
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

    TwistExpander_Capella_Arx::Twist_C(pWorkSpace,
                 pSource,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
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
    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mTwistConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mTwistConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mTwistConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mTwistConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mTwistConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mTwistConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mTwistConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mTwistConstants.mMatrixArgD;
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                         aFuseLaneC, aFuseLaneD,  // input lanes
                         aHeartLaneA, aHeartLaneB,
                         aHeartLaneC, aHeartLaneD, // output lanes
                         aFireLaneC, aFireLaneD, aWaterLaneC, aWaterLaneD, // index shuffle seeds
                         aWaterLaneA, aWaterLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    //
    TwistExpander_Capella_Arx::Twist_D(pWorkSpace,
                 pSource,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
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

    TwistExpander_Capella_Arx::Twist_E(pWorkSpace,
                 pSource,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
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

    TwistExpander_Capella_Arx::Twist_F(pWorkSpace,
                 pSource,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
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
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                         aFuseLaneC, aFuseLaneD,  // input lanes
                         aWoodLaneA, aWoodLaneB,
                         aWoodLaneC, aWoodLaneD, // output lanes
                         aLightningLaneC, aLightningLaneD, aIceLaneC, aIceLaneD, // index shuffle seeds
                         aIceLaneA, aIceLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    //
    TwistExpander_Capella_Arx::Twist_G(pWorkSpace,
                 pSource,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
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

    TwistExpander_Capella_Arx::Twist_H(pWorkSpace,
                 pSource,
                 pSnowLaneA,
                 pSnowLaneB,
                 pSnowLaneC,
                 pSnowLaneD,
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

    FoldTwist(pWorkSpace, pDestination);
    GrowKeyA(pWorkSpace,
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
    GrowKeyB(pWorkSpace,
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
    FoldKeyRows(pWorkSpace);
}

void TwistExpander_Capella::GrowKeyA(TwistWorkSpace *pWorkSpace,
                  std::uint64_t *pPrevious,
                  std::uint64_t *pIngress,
                  std::uint64_t *pCarry,
                  std::uint64_t *pWandererA,
                  std::uint64_t *pWandererB,
                  std::uint64_t *pWandererC,
                  std::uint64_t *pWandererD,
                  std::uint64_t *pWandererE,
                  std::uint64_t *pWandererF,
                  std::uint64_t *pWandererG,
                  std::uint64_t *pWandererH,
                  std::uint64_t *pWandererI,
                  std::uint64_t *pWandererJ,
                  std::uint64_t *pWandererK) {
    TwistExpander::GrowKeyA(pWorkSpace,
             pPrevious,
             pIngress,
             pCarry,
             pWandererA,
             pWandererB,
             pWandererC,
             pWandererD,
             pWandererE,
             pWandererF,
             pWandererG,
             pWandererH,
             pWandererI,
             pWandererJ,
             pWandererK);
    if ((pWorkSpace == nullptr) || (pPrevious == nullptr) ||
        (pIngress == nullptr) || (pCarry == nullptr) ||
        (pWandererA == nullptr) || (pWandererB == nullptr) ||
        (pWandererC == nullptr) || (pWandererD == nullptr) ||
        (pWandererE == nullptr) || (pWandererF == nullptr) ||
        (pWandererG == nullptr) || (pWandererH == nullptr) ||
        (pWandererI == nullptr) || (pWandererJ == nullptr) ||
        (pWandererK == nullptr)) { return; }
    std::uint8_t *aWindLaneA = pWorkSpace->mWindLaneA;
    std::uint8_t *aWindLaneB = pWorkSpace->mWindLaneB;
    std::uint8_t *aWindLaneC = pWorkSpace->mWindLaneC;
    std::uint8_t *aWindLaneD = pWorkSpace->mWindLaneD;
    std::uint8_t *aFuseLaneA = pWorkSpace->mFuseLaneA;
    std::uint8_t *aFuseLaneB = pWorkSpace->mFuseLaneB;
    std::uint8_t *aFuseLaneC = pWorkSpace->mFuseLaneC;
    std::uint8_t *aFuseLaneD = pWorkSpace->mFuseLaneD;
    std::uint8_t *aShadowLaneC = pWorkSpace->mShadowLaneC;
    std::uint8_t *aShadowLaneD = pWorkSpace->mShadowLaneD;
    std::uint8_t *aVaporLaneA = pWorkSpace->mVaporLaneA;
    std::uint8_t *aVaporLaneB = pWorkSpace->mVaporLaneB;
    std::uint8_t *aVaporLaneC = pWorkSpace->mVaporLaneC;
    std::uint8_t *aVaporLaneD = pWorkSpace->mVaporLaneD;
    std::size_t *aIndexList256A = mIndexList256A;
    std::size_t *aIndexList256B = mIndexList256B;
    std::size_t *aIndexList256C = mIndexList256C;
    std::size_t *aIndexList256D = mIndexList256D;

    // [grow key a]
    TwistExpander_Capella_Arx::GROW_A_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Capella_Arx::GROW_A_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Capella_Arx::GROW_A_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    //
    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mKeyRotateConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mKeyRotateConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mKeyRotateConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mKeyRotateConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mKeyRotateConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mKeyRotateConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mKeyRotateConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mKeyRotateConstants.mMatrixArgD;
    //
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                         aFuseLaneC, aFuseLaneD,  // input lanes
                         aVaporLaneA, aVaporLaneB,
                         aVaporLaneC, aVaporLaneD, // output lanes
                         aShadowLaneC, aShadowLaneD, aWindLaneC, aWindLaneD, // index shuffle seeds
                         aWindLaneA, aWindLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    //
    TwistExpander_Capella_Arx::GROW_A_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

}

void TwistExpander_Capella::GrowKeyB(TwistWorkSpace *pWorkSpace,
                  std::uint64_t *pPrevious,
                  std::uint64_t *pIngress,
                  std::uint64_t *pCarry,
                  std::uint64_t *pWandererA,
                  std::uint64_t *pWandererB,
                  std::uint64_t *pWandererC,
                  std::uint64_t *pWandererD,
                  std::uint64_t *pWandererE,
                  std::uint64_t *pWandererF,
                  std::uint64_t *pWandererG,
                  std::uint64_t *pWandererH,
                  std::uint64_t *pWandererI,
                  std::uint64_t *pWandererJ,
                  std::uint64_t *pWandererK) {
    TwistExpander::GrowKeyB(pWorkSpace,
             pPrevious,
             pIngress,
             pCarry,
             pWandererA,
             pWandererB,
             pWandererC,
             pWandererD,
             pWandererE,
             pWandererF,
             pWandererG,
             pWandererH,
             pWandererI,
             pWandererJ,
             pWandererK);
    if ((pWorkSpace == nullptr) || (pPrevious == nullptr) ||
        (pIngress == nullptr) || (pCarry == nullptr) ||
        (pWandererA == nullptr) || (pWandererB == nullptr) ||
        (pWandererC == nullptr) || (pWandererD == nullptr) ||
        (pWandererE == nullptr) || (pWandererF == nullptr) ||
        (pWandererG == nullptr) || (pWandererH == nullptr) ||
        (pWandererI == nullptr) || (pWandererJ == nullptr) ||
        (pWandererK == nullptr)) { return; }
    std::uint8_t *aFuseLaneA = pWorkSpace->mFuseLaneA;
    std::uint8_t *aFuseLaneB = pWorkSpace->mFuseLaneB;
    std::uint8_t *aFuseLaneC = pWorkSpace->mFuseLaneC;
    std::uint8_t *aFuseLaneD = pWorkSpace->mFuseLaneD;
    std::uint8_t *aCelestialLaneA = pWorkSpace->mCelestialLaneA;
    std::uint8_t *aCelestialLaneB = pWorkSpace->mCelestialLaneB;
    std::uint8_t *aCelestialLaneC = pWorkSpace->mCelestialLaneC;
    std::uint8_t *aCelestialLaneD = pWorkSpace->mCelestialLaneD;
    std::uint8_t *aKineticLaneC = pWorkSpace->mKineticLaneC;
    std::uint8_t *aKineticLaneD = pWorkSpace->mKineticLaneD;
    std::uint8_t *aChanceLaneA = pWorkSpace->mChanceLaneA;
    std::uint8_t *aChanceLaneB = pWorkSpace->mChanceLaneB;
    std::uint8_t *aChanceLaneC = pWorkSpace->mChanceLaneC;
    std::uint8_t *aChanceLaneD = pWorkSpace->mChanceLaneD;
    std::size_t *aIndexList256A = mIndexList256A;
    std::size_t *aIndexList256B = mIndexList256B;
    std::size_t *aIndexList256C = mIndexList256C;
    std::size_t *aIndexList256D = mIndexList256D;

    // [grow key b]
    TwistExpander_Capella_Arx::GROW_B_A(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Capella_Arx::GROW_B_B(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    TwistExpander_Capella_Arx::GROW_B_C(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

    //
    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mKeySpawnConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mKeySpawnConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mKeySpawnConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mKeySpawnConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mKeySpawnConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mKeySpawnConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mKeySpawnConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mKeySpawnConstants.mMatrixArgD;
    //
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                         aFuseLaneC, aFuseLaneD,  // input lanes
                         aChanceLaneA, aChanceLaneB,
                         aChanceLaneC, aChanceLaneD, // output lanes
                         aKineticLaneC, aKineticLaneD, aCelestialLaneC, aCelestialLaneD, // index shuffle seeds
                         aCelestialLaneA, aCelestialLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    //
    TwistExpander_Capella_Arx::GROW_B_D(pWorkSpace,
                 pPrevious,
                 pIngress,
                 pCarry,
                 pWandererA,
                 pWandererB,
                 pWandererC,
                 pWandererD,
                 pWandererE,
                 pWandererF,
                 pWandererG,
                 pWandererH,
                 pWandererI,
                 pWandererJ,
                 pWandererK);

}

void TwistExpander_Capella::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 15 of 33
    // Exploration cases: 0
    // Structural maximin 524 / 674; family total 7506
    std::uint8_t *aGrowAAetherLaneA = pWorkSpace->mAetherLaneA;
    std::uint8_t *aGrowAAetherLaneB = pWorkSpace->mAetherLaneB;
    std::uint8_t *aGrowAAetherLaneC = pWorkSpace->mAetherLaneC;
    std::uint8_t *aGrowAAetherLaneD = pWorkSpace->mAetherLaneD;
    std::uint8_t *aGrowAVaporLaneA = pWorkSpace->mVaporLaneA;
    std::uint8_t *aGrowAVaporLaneB = pWorkSpace->mVaporLaneB;
    std::uint8_t *aGrowAVaporLaneC = pWorkSpace->mVaporLaneC;
    std::uint8_t *aGrowAVaporLaneD = pWorkSpace->mVaporLaneD;
    std::uint8_t *aGrowAShadowLaneA = pWorkSpace->mShadowLaneA;
    std::uint8_t *aGrowAShadowLaneB = pWorkSpace->mShadowLaneB;
    std::uint8_t *aGrowAShadowLaneC = pWorkSpace->mShadowLaneC;
    std::uint8_t *aGrowAShadowLaneD = pWorkSpace->mShadowLaneD;
    std::uint8_t *aGrowAKeyRowWrite = &(pWorkSpace->mKeyBoxA[0][0]);
    static_assert((S_BLOCK / S_QUARTER) == 4, "GrowKeyA expects four expansion-lane quarters.");
    static_assert((S_QUARTER / W_KEY) == 4, "GrowKeyA expects four key chunks per quarter.");
    TwistShiftBox::ShiftKeyBoxA(pWorkSpace);
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8149U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7969U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3918U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4008U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1690U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 92U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1645U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1420U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1870U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 47U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1375U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 15 of 33
    // Exploration cases: 0
    // Structural maximin 520 / 674; family total 7521
    std::uint8_t *aGrowBCrystalLaneA = pWorkSpace->mCrystalLaneA;
    std::uint8_t *aGrowBCrystalLaneB = pWorkSpace->mCrystalLaneB;
    std::uint8_t *aGrowBCrystalLaneC = pWorkSpace->mCrystalLaneC;
    std::uint8_t *aGrowBCrystalLaneD = pWorkSpace->mCrystalLaneD;
    std::uint8_t *aGrowBVaporLaneA = pWorkSpace->mVaporLaneA;
    std::uint8_t *aGrowBVaporLaneB = pWorkSpace->mVaporLaneB;
    std::uint8_t *aGrowBVaporLaneC = pWorkSpace->mVaporLaneC;
    std::uint8_t *aGrowBVaporLaneD = pWorkSpace->mVaporLaneD;
    std::uint8_t *aGrowBShadowLaneA = pWorkSpace->mShadowLaneA;
    std::uint8_t *aGrowBShadowLaneB = pWorkSpace->mShadowLaneB;
    std::uint8_t *aGrowBShadowLaneC = pWorkSpace->mShadowLaneC;
    std::uint8_t *aGrowBShadowLaneD = pWorkSpace->mShadowLaneD;
    std::uint8_t *aGrowBKeyRowWrite = &(pWorkSpace->mKeyBoxB[0][0]);
    static_assert((S_BLOCK / S_QUARTER) == 4, "GrowKeyB expects four operation-lane quarters.");
    static_assert((S_QUARTER / W_KEY) == 4, "GrowKeyB expects four key chunks per quarter.");
    TwistShiftBox::ShiftKeyBoxB(pWorkSpace);
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7249U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3378U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7429U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3468U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 745U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 430U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 655U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 610U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 520U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 925U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 835U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1195U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 565U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldSeedControl candidate 15 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1060 / 1248; total 15111
void TwistExpander_Capella::FoldSeed(TwistWorkSpace *pWorkSpace,
                                      std::uint8_t *pDestination) {
    if ((pWorkSpace == nullptr) || (pDestination == nullptr)) { return; }

    std::uint8_t *aPoisonLaneA = pWorkSpace->mPoisonLaneA;
    std::uint8_t *aPoisonLaneB = pWorkSpace->mPoisonLaneB;
    std::uint8_t *aPoisonLaneC = pWorkSpace->mPoisonLaneC;
    std::uint8_t *aPoisonLaneD = pWorkSpace->mPoisonLaneD;

    std::uint8_t *aDestinationLaneA = pDestination + (0U * W_KEY);
    std::uint8_t *aDestinationLaneB = pDestination + (1U * W_KEY);
    std::uint8_t *aDestinationLaneC = pDestination + (2U * W_KEY);
    std::uint8_t *aDestinationLaneD = pDestination + (3U * W_KEY);
    std::uint8_t *aDestinationLaneE = pDestination + (4U * W_KEY);
    std::uint8_t *aDestinationLaneF = pDestination + (5U * W_KEY);
    std::uint8_t *aDestinationLaneG = pDestination + (6U * W_KEY);
    std::uint8_t *aDestinationLaneH = pDestination + (7U * W_KEY);
    std::uint8_t *aDestinationLaneI = pDestination + (8U * W_KEY);
    std::uint8_t *aDestinationLaneJ = pDestination + (9U * W_KEY);
    std::uint8_t *aDestinationLaneK = pDestination + (10U * W_KEY);
    std::uint8_t *aDestinationLaneL = pDestination + (11U * W_KEY);
    std::uint8_t *aDestinationLaneM = pDestination + (12U * W_KEY);
    std::uint8_t *aDestinationLaneN = pDestination + (13U * W_KEY);
    std::uint8_t *aDestinationLaneO = pDestination + (14U * W_KEY);
    std::uint8_t *aDestinationLaneP = pDestination + (15U * W_KEY);

    static_assert((S_BLOCK / W_KEY) == 16,
                  "FoldSeed expects sixteen key-width chunks per lane.");

    //
    // FoldSeed — Chunk A
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 205U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2028U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1308U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1961U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 273U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1781U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 993U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 340U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 498U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1128U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1826U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 250U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 948U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1893U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 633U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1848U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1871U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1713U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1578U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 408U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1263U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1646U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1691U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 588U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 295U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 70U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 903U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1916U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneG[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 183U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 115U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1533U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 93U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneH[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 160U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1353U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1736U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 318U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1443U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 48U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1173U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1083U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneJ[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1488U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1803U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 813U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 678U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneK[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 138U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1038U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1983U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 858U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 363U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 453U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2006U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 768U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 228U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1398U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1938U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1758U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneN[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 723U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1623U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1218U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 385U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1668U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 25U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 543U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldTwistControl candidate 15 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1061 / 1248; total 15198
void TwistExpander_Capella::FoldTwist(TwistWorkSpace *pWorkSpace,
                                      std::uint8_t *pDestination) {
    if ((pWorkSpace == nullptr) || (pDestination == nullptr)) { return; }

    std::uint8_t *aPoisonLaneA = pWorkSpace->mPoisonLaneA;
    std::uint8_t *aPoisonLaneB = pWorkSpace->mPoisonLaneB;
    std::uint8_t *aPoisonLaneC = pWorkSpace->mPoisonLaneC;
    std::uint8_t *aPoisonLaneD = pWorkSpace->mPoisonLaneD;

    std::uint8_t *aDestinationLaneA = pDestination + (0U * W_KEY);
    std::uint8_t *aDestinationLaneB = pDestination + (1U * W_KEY);
    std::uint8_t *aDestinationLaneC = pDestination + (2U * W_KEY);
    std::uint8_t *aDestinationLaneD = pDestination + (3U * W_KEY);
    std::uint8_t *aDestinationLaneE = pDestination + (4U * W_KEY);
    std::uint8_t *aDestinationLaneF = pDestination + (5U * W_KEY);
    std::uint8_t *aDestinationLaneG = pDestination + (6U * W_KEY);
    std::uint8_t *aDestinationLaneH = pDestination + (7U * W_KEY);
    std::uint8_t *aDestinationLaneI = pDestination + (8U * W_KEY);
    std::uint8_t *aDestinationLaneJ = pDestination + (9U * W_KEY);
    std::uint8_t *aDestinationLaneK = pDestination + (10U * W_KEY);
    std::uint8_t *aDestinationLaneL = pDestination + (11U * W_KEY);
    std::uint8_t *aDestinationLaneM = pDestination + (12U * W_KEY);
    std::uint8_t *aDestinationLaneN = pDestination + (13U * W_KEY);
    std::uint8_t *aDestinationLaneO = pDestination + (14U * W_KEY);
    std::uint8_t *aDestinationLaneP = pDestination + (15U * W_KEY);

    static_assert((S_BLOCK / W_KEY) == 16,
                  "FoldTwist expects sixteen key-width chunks per lane.");

    //
    // FoldTwist — Chunk A
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1534U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 836U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1309U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1624U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1444U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1804U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1556U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1759U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1939U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 161U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 656U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1016U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1264U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 949U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1489U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1399U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 566U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 611U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1196U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1331U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1601U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1511U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 116U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 791U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 71U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2029U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 386U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1984U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneG[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1151U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 431U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1286U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 971U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneH[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1084U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1669U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 904U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 926U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 206U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1174U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 476U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 859U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneJ[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1241U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1466U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 341U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1354U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneK[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1849U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1129U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 251U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1421U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 746U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 994U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 296U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1219U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 881U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1579U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1039U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1894U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneN[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 521U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1714U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 26U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1376U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1061U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1106U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 814U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 701U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Capella::kKeyRotateSalts = {
    {
        {
            0xF27187ABF14FAEFFULL, 0xD88604E2B337646AULL, 0xDC9904F9C4A260CBULL, 0x95B4CDA5AFF8A7CBULL, 
            0xABF6DEA933C4F448ULL, 0x8778CCA0FAFD7444ULL, 0x91CAE628603004C8ULL, 0xD384B563D127A291ULL, 
            0x4AEEB29AB82A1E84ULL, 0x737639949A8F7D05ULL, 0xC4B20D58A3B0902AULL, 0x79A9B67CBB4869ADULL, 
            0xAD63717AF8C43563ULL, 0x4F41B09A5D8EFA46ULL, 0x424F0FCA0B4ECE31ULL, 0xFA835EBF3064E1DEULL, 
            0xD27D7927DA286B0AULL, 0xF0C918A97D096447ULL, 0x3AAB21294EB02F24ULL, 0x5EA545F98478C886ULL, 
            0xE596AA8C93B1FD2DULL, 0x624BB6B850741D85ULL, 0x0C9166020FA2FAE6ULL, 0x3D461D501EC16C5CULL, 
            0x4861255BAB965AE3ULL, 0xD9D0990438E2E8E2ULL, 0x97E46EF7D454E6A7ULL, 0x6B1DA78241DDB260ULL, 
            0x1FE43341C54D9E3DULL, 0xC8878A15561ED5BBULL, 0x624975228EB287E0ULL, 0x6320826CBE4E72BFULL
        },
        {
            0x03E17F2CBD94E1FEULL, 0x724B70274A9C24ACULL, 0xE3C211B238CCB4B6ULL, 0x7E22AFE9C2D56E41ULL, 
            0xAC38655BD24DB167ULL, 0xDB05F48617019669ULL, 0xD25911FE9DD438C8ULL, 0x47AEEC0C76AB004AULL, 
            0xBB81488C0BF33918ULL, 0x6AE78D13D45DD14FULL, 0x9923B06AEE3C9159ULL, 0x3AEBB3A4DBFCE123ULL, 
            0x6B9DFB7C32457751ULL, 0x88C12D6328079545ULL, 0x66E0095AFE910148ULL, 0xA451A363A69C6723ULL, 
            0xE44F631769F9E40EULL, 0x8D4985848DB4D857ULL, 0x7E11F7AAE296F145ULL, 0x932EF9C68ED5BA48ULL, 
            0x682E57D23462ACF5ULL, 0x5E0DFEE5974BE214ULL, 0x3BFA2064C9BE6B35ULL, 0x4A40CA4ED2C787DDULL, 
            0x63F33F4D88F6566FULL, 0x4FC4946421812326ULL, 0x295D6978A93ECAA2ULL, 0xED7B1FDD5D021248ULL, 
            0x8B028197E437B4CAULL, 0xC7FE3E59E6009F52ULL, 0x0004A47DD174425AULL, 0x24F8E8CD7BDECB91ULL
        },
        {
            0xF8614B4DBCB25F3DULL, 0x16FDBAA1570961D6ULL, 0x445B0E25EF44F164ULL, 0x2A1B09A1A9C36FD8ULL, 
            0x09E4092D6CA5638CULL, 0x9B148C461ABA4571ULL, 0xB93ECF40EEB5DFF5ULL, 0x5FCD899EC6329585ULL, 
            0x7F5E5C729A0158D1ULL, 0x8454C950FD37B899ULL, 0x4D492123BDA2268BULL, 0xAC33BED2AD190EDCULL, 
            0xA2C17C45B23CC63FULL, 0x4C79FE720BE7FD6DULL, 0xE288586DAAB6FE40ULL, 0x0DB5DCE6E408B0FEULL, 
            0x0F1F7E2E0C0EB55AULL, 0xDA83D0AFDE582285ULL, 0xC938EA7F892FFC87ULL, 0x2B6B1482BC3B394FULL, 
            0x08105C8AB79811A4ULL, 0xA361882C38200142ULL, 0x2DF8B4F638ADF735ULL, 0x811F8324B74A3A8DULL, 
            0x78613B230F1BE975ULL, 0x312716906304559CULL, 0xE7EF1E61DB13A814ULL, 0x82C94DFD4C7C4F03ULL, 
            0x6C0674D158E12268ULL, 0x320AAF66F94AF7C1ULL, 0xB0944D8FF5F916B1ULL, 0xC5A9A5B155B95786ULL
        },
        {
            0xD6186BF59967F284ULL, 0x5337B471B5647D17ULL, 0x4CF89243B39DF114ULL, 0xA36F0A98062154ACULL, 
            0x4FDDD8BB5BC759CFULL, 0x01D60EAEA5A079C7ULL, 0x1D755043FF6713C6ULL, 0xCCF3BFF87B690AA9ULL, 
            0x43CA079AFD5445F5ULL, 0xE2C987317B96800CULL, 0x4DB399261E61CDD1ULL, 0x5373DD9D6A674A9FULL, 
            0xA06D8B749A5354FCULL, 0x1E70B34BEEB1C28BULL, 0x80B87F14CEF1F830ULL, 0x063EE14CFD83DEEDULL, 
            0xCDFD6ADE811C9218ULL, 0xE9E7FDCC7E862799ULL, 0x59448448F42BAE1EULL, 0x905B65C0DF67CA03ULL, 
            0xD851929E1BA7AB88ULL, 0x472069450374CF66ULL, 0x27BD6072AFE8E22AULL, 0x8C21217CB21C5E6EULL, 
            0x20F9A7F4D053EB8FULL, 0x0209432FE597054AULL, 0x354128B85F9EFD5BULL, 0x41830812AAE63B27ULL, 
            0x6BC534C41863F814ULL, 0xC57DCC2F7CE604BFULL, 0x6D0CA0742B21BC11ULL, 0x5AA298CF8CC25510ULL
        },
        {
            0xCC3196173220BA9AULL, 0x55D9A83FE408C2D7ULL, 0xFAFA9AA70479E574ULL, 0xB131481EE0BC3FE2ULL, 
            0x6304533E12E86E64ULL, 0x596306EFA64E23F9ULL, 0x5FE7C6991A4C143FULL, 0xCE210D1C7EEAFD17ULL, 
            0x98B8EF4F4232A237ULL, 0x0F76EB0A28BBB5CBULL, 0x9D68B3F8B17E4F73ULL, 0x7005AEC710A5BA82ULL, 
            0xF8DE42F432513D78ULL, 0xED9045676A2F4710ULL, 0xBECA48BA4AEB60FDULL, 0xA93DA4C7D67BB9E3ULL, 
            0xFCF8EB1E13B3CD4DULL, 0x877C351011B2E124ULL, 0xCF4A65D4D81B86CEULL, 0x1033AFFCFBA57E83ULL, 
            0x36D2EA3C4FFCB024ULL, 0x3CB1E9145106C608ULL, 0x659589248DDC2E85ULL, 0xF428FE88460EE418ULL, 
            0xE71B1E5176B1DFA5ULL, 0xA59E2890C0B522C4ULL, 0x635C249B016815B1ULL, 0x053D4BD894C37BDBULL, 
            0xDFD28203DFB5E29BULL, 0x51F221D3F151C537ULL, 0xA683D26B403D4087ULL, 0xDC2C831C2485CFE7ULL
        },
        {
            0x7B5C11808584F763ULL, 0xD0A4BBA32290FA96ULL, 0x6D2827BB2D37B7A7ULL, 0x523BF285BAC37DCEULL, 
            0x2DE4A87256A49125ULL, 0x228C84B47CF73A09ULL, 0xDDD51610C1365F38ULL, 0x922D939BBEE94B3DULL, 
            0xD20B3D162CC1E05CULL, 0x1BEE70CCEE95867AULL, 0x9A970CE16705E4A3ULL, 0xC311928448160C0EULL, 
            0x05B35369451C80B6ULL, 0x2F578740F56C57AEULL, 0xD2C499A68A285808ULL, 0xCFEACCED0F4A21D8ULL, 
            0x65D2AC0294B18A74ULL, 0xE3CE0B9FDC0A79FCULL, 0x35BD96BF8E9DD39DULL, 0x476BB88A7E722765ULL, 
            0xD0CE2CFAD769A8AEULL, 0xF2FBD7D995CD2D68ULL, 0xA8AA9AE68EC83E7CULL, 0xE3CB02245CD5D447ULL, 
            0x93A060D78D0C49C1ULL, 0xFC916DF8C3CA526DULL, 0x8B5FE1DE0F434D29ULL, 0x45204C0070D6E8CFULL, 
            0xD77DBE0B6ECF79F9ULL, 0x1B0251D271EBBDB8ULL, 0x22E447124C0DCC2BULL, 0x8938C24EB7B1EC3CULL
        }
    },
    {
        {
            0xE29C3C232F6D9D00ULL, 0x69CCA03F0042E067ULL, 0x18DE034DD43DA421ULL, 0x25A6A4ADF8A89163ULL, 
            0xBA61476FBBAA9EF7ULL, 0x14067817133D776CULL, 0x7802FCAA675BCC88ULL, 0x2E64753776C4E5C7ULL, 
            0x8AD6FDCC727E04BDULL, 0x9760E5954F0CC8E7ULL, 0x00AE3E85D55766ADULL, 0xB99D1DF6355A3DB7ULL, 
            0x43C33D11823F2592ULL, 0xCFF9D408889B099AULL, 0xA48CD203B97E5FFBULL, 0x551344057BA9031DULL, 
            0xA51FD28BD89366EDULL, 0x8E68B8F0CDD5EAD6ULL, 0x45FF476CE6549FD0ULL, 0x1464C5AE68EA9431ULL, 
            0x2B5529A1D97CC1C3ULL, 0xC563EC89A57C7FBFULL, 0xDA0B09DFB9A5475DULL, 0x3DD22AF57824E20EULL, 
            0x13E58B209A541A41ULL, 0x478D3E9E2F34A9E6ULL, 0x30F9E6F5227EB05CULL, 0x2A2AF908CE319556ULL, 
            0xCBE26D7CA26C75B3ULL, 0x5AE3398F5BDEF862ULL, 0x2D057A71B43C0B1DULL, 0xDFF86278218413B5ULL
        },
        {
            0x88C9D8789DB47B41ULL, 0x5EBE8BC2F2EDF19CULL, 0x143FD62796EFA578ULL, 0x36A2BF47692665B6ULL, 
            0x14D43D570631E880ULL, 0x8705ED40B4D9C4A2ULL, 0x409D89124F270E5EULL, 0xA8D9AF3E8D6A2D5BULL, 
            0xC4CCA6DFC4F13A76ULL, 0xB5D1ED36E4BBC302ULL, 0x96EE04F2E95BAB99ULL, 0x0714554DB97F91C1ULL, 
            0x0857CB5C9BF4993BULL, 0xE4F9EA73EC35523BULL, 0xB1FE4B4EDE98C404ULL, 0x7DE9C1B168BE5445ULL, 
            0x2ADF0B453CA1D500ULL, 0x3DF25792B11B5C2EULL, 0x8B2F365987CADA94ULL, 0x057100A748A966D7ULL, 
            0x09CC3B717CD6EC1BULL, 0xC8120D57DA77CB0DULL, 0x5BA60CDA3D792F10ULL, 0x0BAE939FD333D95BULL, 
            0x3C63B05EC613C848ULL, 0xA1A3730C1D9FA46DULL, 0x3F49BFE0198EB6ACULL, 0xDAF6DAE16C114493ULL, 
            0xC44FB1783687E72CULL, 0x2D05D689B3421794ULL, 0x25307B149BACB178ULL, 0xD2EEC32E453ED80BULL
        },
        {
            0xBD722561A1EBB700ULL, 0x00C0D9F9468D9651ULL, 0x44535533BCC6DC00ULL, 0xB3616F979F9FBD93ULL, 
            0x5CD71F7D50AF79EEULL, 0x124CD5BA469DE898ULL, 0x538A0C262AB59C6EULL, 0x89431E19F9DD0E53ULL, 
            0xD285C840EF80E3E5ULL, 0x9D7604EA1FAB0EE0ULL, 0x1B59A19CCE1594C0ULL, 0x860BC953AE01B260ULL, 
            0xAD7B950E6E0C3D1BULL, 0xD36F958C72DA0067ULL, 0xC5C17B4E8DCBC521ULL, 0x8766B497789F5752ULL, 
            0x6779DB556CCF32E7ULL, 0xD75693E04D319C30ULL, 0x5548610332BD3230ULL, 0xA6EC7D3B584A3F35ULL, 
            0x37642065B17FD8CFULL, 0x73DD67D30DAB90E8ULL, 0x1C1C745790E2B4C2ULL, 0x8CB9658588AEFC0FULL, 
            0xE1837CB5BA6BA60EULL, 0xF09C5B2749BDC9FEULL, 0xF888A77FC774D5D3ULL, 0xB8C21DD4BFF6C355ULL, 
            0xB832A2275FF03C82ULL, 0xF748DCA0EED7430BULL, 0x2A715E1B57A1A86AULL, 0xE6C98F0EBB595B17ULL
        },
        {
            0xE9FCEADDA484623CULL, 0xE06CD5E3026C05CEULL, 0xE020AEAD413135D6ULL, 0x4152984DF708CC26ULL, 
            0x7819057B08C43968ULL, 0x2BA90CB32E5BC0D0ULL, 0x2C408432ECA44259ULL, 0xB4E4A83BD75B6C0BULL, 
            0x98253F3ADCA1AF4AULL, 0xF3E4155887740BD5ULL, 0x4CC9175FFEF0F974ULL, 0x6CAB60040B0D4F07ULL, 
            0x8650AE09D4DB7A85ULL, 0x445F627FA26A0370ULL, 0x0E7EAA91D10F48A6ULL, 0xBE787967B2F940F4ULL, 
            0x90230DC8036FB25BULL, 0xD9C1E12811B4BFFCULL, 0x85B6261EDA5EE46CULL, 0x794EF21918424CF8ULL, 
            0xFBAF6F86E761F713ULL, 0xE5AECD5A90E83A01ULL, 0xA5888C6366AB5D4FULL, 0x9D2EAD2FDFD3898FULL, 
            0x3AC1037A8EA0D509ULL, 0x42D1E0F7AF0B234EULL, 0x4A606E1B08EEACB3ULL, 0x3394157BD25621F2ULL, 
            0xB6B2007856988747ULL, 0x0D62E268DA1FA1C0ULL, 0x60A80F93BDBFB7D7ULL, 0xF82DC28E89F77BDDULL
        },
        {
            0x7BEFB668399CF07EULL, 0x6B6FF5FA84248FA6ULL, 0xA67D7CA30FEAD316ULL, 0x8EF564C7747F4685ULL, 
            0x5CDFF0395ABF6B40ULL, 0x6CB67E6372FB9513ULL, 0xA5414076493D98C0ULL, 0xC39A0888FE4ABC21ULL, 
            0xF203E2EC50D1AA02ULL, 0x4075D1B486ACEC14ULL, 0xBBA5A7EA8561AB04ULL, 0xEBD563642D9DCC6FULL, 
            0x010938E435AE2285ULL, 0x7AB766834730E3E0ULL, 0x4BBC4F95FC369BE6ULL, 0x18762F261C9406A2ULL, 
            0xB85BD1A9C6B2F495ULL, 0x70DEE4A5BEF91597ULL, 0x3A72398F94C5376AULL, 0x73B785D076391DEDULL, 
            0x106FD8FACD133D5BULL, 0xFA3A35AEE77B5F04ULL, 0x8BD6481ADF4AAEAEULL, 0x5262969C26058EADULL, 
            0xD7E4552A21854C32ULL, 0x8438B8AB3A5E3321ULL, 0x347DB655661D4C82ULL, 0xDF31FF08EFF20CC5ULL, 
            0xBEAE3492F623F187ULL, 0x064C4743A16A05ABULL, 0x47CC8B7E0990FC4CULL, 0x5B020DDA10D17A16ULL
        },
        {
            0xA6BEF6F51E80A4A9ULL, 0x4B2000DCA9B31B5AULL, 0xE1F1F2E73BC6FE84ULL, 0xFF9F327BE754DFE8ULL, 
            0xD849365D956B5EACULL, 0xD2EB76D203B4571CULL, 0x02E9B5224A5D39F3ULL, 0xFF4D557AFB9610BDULL, 
            0x18298A41ACB0AEB0ULL, 0x6107EABB269CE016ULL, 0x6234BB6EC5022568ULL, 0xAF3A464392F60123ULL, 
            0x615CCCF924F3EC73ULL, 0x082DE9AC9C27D1CCULL, 0x30EB4BA62062D208ULL, 0x9D729746A5459C47ULL, 
            0xA1D368B10A6EE4F4ULL, 0x167F80316019A3A0ULL, 0x14D45CA528E8B5C3ULL, 0xF5BFD8BF2344406AULL, 
            0x3555CF7BD91BA8C0ULL, 0xE59A2B1A8A04166DULL, 0xDF113621DFE01E29ULL, 0xEE3AA2EBFC58770AULL, 
            0x1EA94EE08F0929AAULL, 0x0A5FD55631ADFC89ULL, 0x2CBECD5C746FDC8FULL, 0x1840D068F6B011B2ULL, 
            0x4F1C0E0A1D614CA1ULL, 0xA0A71400B7E58EA4ULL, 0x362C44D65D8E4C14ULL, 0x61C622E1D565C795ULL
        }
    },
    {
        {
            0x0A0AD6B496EB7CC4ULL, 0x805D1EBBFED0335AULL, 0x90FBEB5A3B9F38EDULL, 0xAC6AA1B39D73C3D2ULL, 
            0x8CD81B4AE328878AULL, 0x1015FED516F2F81DULL, 0xFB0849D4E27967FDULL, 0x334D5564D6489613ULL, 
            0x7B5E9B68745709EBULL, 0x8C97BEA44F4C5E07ULL, 0xB471BD8132AC3156ULL, 0xA7204FD7DCD5BAC6ULL, 
            0xB86C7434B6F291C2ULL, 0x54A797780C22CDAAULL, 0xC1FA95BA42B22033ULL, 0x310FAAE6FB093442ULL, 
            0xC0EEBB3936179F21ULL, 0x77E157A233E9D4E2ULL, 0xD05E4E4AF67D5D45ULL, 0x3FDB716EE35CADE4ULL, 
            0xEBD8126876DAF6A3ULL, 0xAB00DA0208916D39ULL, 0x50D0E156A3AFED8EULL, 0xA90F5FE2D4B35061ULL, 
            0xB7EE156DB7568FFCULL, 0x58DB99510E25DC0AULL, 0x5E6A931B29989FD9ULL, 0xC59A4A6A24CE8AA8ULL, 
            0xF77284D5609F0DD2ULL, 0x28B661E99217BABDULL, 0x41C6E357021CFF96ULL, 0x83ADC6E73C2607BDULL
        },
        {
            0xEF16DA50B357B04EULL, 0xEE128F5929F67547ULL, 0x4B968117A8EBA27DULL, 0xFC6F25598C6722BEULL, 
            0x192E9CD7812A6DCEULL, 0x34156401E9F70066ULL, 0x19C1C744B91880B4ULL, 0xD386416836DAE45AULL, 
            0xA10A5867677B0885ULL, 0xA3F58B016D89C2AAULL, 0x2E76AB0DA97DB46AULL, 0x99AA93984226A8DBULL, 
            0xF773FC8E201B2F20ULL, 0x40F1DA698429A95FULL, 0xC8FB0F3EB6BF61C7ULL, 0x6C50CB9EDC5D2306ULL, 
            0x154B84443A326E87ULL, 0xCDD6135EC2A04CDFULL, 0x6DEC521C0B4233A5ULL, 0x06435FED29609259ULL, 
            0xE45CAB82255EBC39ULL, 0x52BFC91F9E6CC1CEULL, 0xD45185BC7E574086ULL, 0x35ECD2AEAC94DBE2ULL, 
            0x00D2587C351902BAULL, 0x5E58A9403446D5D9ULL, 0x2A32135B2ACD443BULL, 0xE680F01F84F3B05EULL, 
            0x51D9F4A39AC18BD0ULL, 0x66A48556DFE73ABFULL, 0x3EAF0F95E39C02B6ULL, 0xACA162E9798435C4ULL
        },
        {
            0x7855D32E2D269C26ULL, 0xA372220217DF59D1ULL, 0xF24F64DBD322223CULL, 0x607A88F2CC7DFC3FULL, 
            0xD36EE96D7F9437F8ULL, 0xD83D63B4C9C18D66ULL, 0x91B871261FFE5E30ULL, 0x2EA6B196F9273AAEULL, 
            0xB7454901C833A070ULL, 0x2CEDC90B8B44325FULL, 0xAA8D9C0FF089F841ULL, 0x7F7B349862D25E8CULL, 
            0xAEF3F01BAC91A21DULL, 0x5A1495AA8079E162ULL, 0x59E5A49991B5ECECULL, 0xBD985F3133A69153ULL, 
            0xF04FBF2A4D1722D4ULL, 0x38B9FEE2712321C2ULL, 0xDEC9825AC702003FULL, 0x62F53A989CB55F95ULL, 
            0x709C420D34682C01ULL, 0xD31948E5B75F058BULL, 0x650F71CDA796F6DEULL, 0x3B1FF8E2FF87D9CBULL, 
            0x85D5A3EF1C590E8BULL, 0xA1F205000EEDBB78ULL, 0x5E7A72AC498A81EAULL, 0xB6571AEABA22DB5BULL, 
            0x6EF3AD0B5AF11DF0ULL, 0x5D9151BDE6A41EABULL, 0x8241B15F0787BB78ULL, 0x212834CDA3CCE5E3ULL
        },
        {
            0x5590ACB1116A5464ULL, 0xAFF272A26793800EULL, 0x960CD4CE8E9F96E3ULL, 0xE629B6B1F0B9D7D7ULL, 
            0xBC87431A01F0AEA3ULL, 0xA0DCD7A7E8AFFA44ULL, 0x4C38437FA5C34384ULL, 0x3A21DBC66783906AULL, 
            0x93C28A28528D999EULL, 0x2E1F36C47A7079FDULL, 0xEC0CB393F2DB8790ULL, 0x8E922180DCC9D436ULL, 
            0x8C1268E7FC017431ULL, 0x73F62A5B9AFAE922ULL, 0xA02B2CF3ABC2BE74ULL, 0xE5C4FE19C0586DEEULL, 
            0xBBD089130B9A9C02ULL, 0x0FD7E266ACA1D38BULL, 0x8702D9E22C3870D3ULL, 0xC967277F61EFE9C8ULL, 
            0x6F265737EB80B59EULL, 0x9B96AD8944A061E4ULL, 0x368401F149BE721DULL, 0x7E537AE6E1C8E06BULL, 
            0x9696FE84C02A0BB6ULL, 0x17B0B7B7E3BE5A8CULL, 0xFF1919D38B87F1F8ULL, 0xD1645D7706C94DDEULL, 
            0x38861EAC4CEBD4EBULL, 0x2FF257DAF988B818ULL, 0x3BEBDF22D9FCAF44ULL, 0x99E59421EC80D6E7ULL
        },
        {
            0x49B0D933696DC190ULL, 0xD66BEAAF5521300CULL, 0x7B9B31F9FE74ECB0ULL, 0x6C9BD02D621B68E1ULL, 
            0x3C77F653B7381CF4ULL, 0x94E1AAA2B46FB265ULL, 0xEBA5F901DE34E0A7ULL, 0x602EFD056494D334ULL, 
            0x71A9738B1CFF7782ULL, 0xF9E911A705EFF6A9ULL, 0x4FB32FFBA18B9897ULL, 0x6F51ECE543A4BEEEULL, 
            0x54ED69807ECB5864ULL, 0xAEC48755D9D63F38ULL, 0x153D8D1F889A4001ULL, 0x026E8482387D445EULL, 
            0x5B6EC29311DF4C1FULL, 0xC78F8922E8A17768ULL, 0xA31B1F15886E1738ULL, 0x5EA18B2A8ED2BE16ULL, 
            0xD2965CA1C8E37C48ULL, 0x6910832402642129ULL, 0x91D920F21B0173EDULL, 0xCF8A6510ABA476DCULL, 
            0x6E8ED411F09C85A7ULL, 0x9AA822A42F206FF8ULL, 0x5124425561168429ULL, 0x83FE0A5A1F9A9607ULL, 
            0xD76534E5C03A87DAULL, 0xF0E62955F2922EFDULL, 0xE0DD06293C218D14ULL, 0x75FA185B4112AC3DULL
        },
        {
            0x9702B3F593970FCAULL, 0x11A8C43CA07EA56AULL, 0x0B9F131BD2154EF0ULL, 0x8817B1D83CCD532DULL, 
            0x5CAA3543DA70C6A0ULL, 0x06C099EECEC9323BULL, 0xB40BCC9B1A7B106EULL, 0x6996289B190BBAAEULL, 
            0x65FB5C473A2327DAULL, 0x322D71BB2C708263ULL, 0x2F543B4F958C2EE0ULL, 0x039854F0717E9411ULL, 
            0x3CDCA140549001C7ULL, 0x3261991493AD0EEAULL, 0x78BEF504E213A4D2ULL, 0x49E5A809F5A3BBBDULL, 
            0xFBC1493511515DB8ULL, 0x6E38747D6208B575ULL, 0xE468532DCBC0C66DULL, 0xDCEE81130A1A3B7DULL, 
            0x4FC17A8018228285ULL, 0x5D81C0E8DD2CB9B9ULL, 0x61198E8621255069ULL, 0x3E813A9C141C6E70ULL, 
            0x0FA1D60C17C1713CULL, 0xD686AC232FFCC79DULL, 0xF8E357CE38FBB6F3ULL, 0x6BFF857A257A8299ULL, 
            0x9154CA593884130EULL, 0x447368FE5A88A25DULL, 0x48ACF1E0DC5FEC6FULL, 0x94BB37DF79E6BBABULL
        }
    }
};

const TwistDomainConstants TwistExpander_Capella::kKeyRotateConstants = {
    0x2FA22A28A334498CULL,
    0xB48B8217AB360F70ULL,
    0x7FE51B0335CAF34FULL,
    0x2FA22A28A334498CULL,
    0xB48B8217AB360F70ULL,
    0x7FE51B0335CAF34FULL,
    0x8CB0EA803897CEB3ULL,
    0x5B23357D3206A3BDULL,
    0x9D,
    0xE7,
    0xE1,
    0x49,
    0xA6,
    0xE2,
    0x80,
    0xC8
};

const TwistDomainSaltSet TwistExpander_Capella::kKeySpawnSalts = {
    {
        {
            0x90D4005A22083312ULL, 0xEF19928E9A7535BBULL, 0x2E21C474F56960C1ULL, 0x365180E914B079C6ULL, 
            0xF6EEA257D14F2955ULL, 0x644CD3786D927AA3ULL, 0xF41C70D6EBB69AB5ULL, 0x87082F13878E1D5DULL, 
            0x2DAE32A8265A569AULL, 0xEAF8AC03AA14C4AAULL, 0xE4387019759B34BDULL, 0xB0EECCA518E8BE8AULL, 
            0xFDC36BCB2F5BE2AAULL, 0x1A250829B7D8B804ULL, 0xED2BE88C3AA2886EULL, 0xE43E84F06328AB96ULL, 
            0xED174997CAE51C34ULL, 0xD70A1C3E32C404F6ULL, 0x4592B76BEB7A3ACFULL, 0x6B6D72E87DB7011EULL, 
            0xD489BF561A0B42C2ULL, 0xCECB9AA066D269FEULL, 0xBC799C56C2A668C8ULL, 0x8752A65687D0CF1BULL, 
            0x43AC058029173F62ULL, 0x5B16A17491E7A74CULL, 0x1AF8F54BAD817314ULL, 0x089CE249EBAC1678ULL, 
            0x2AAF7AFDCC2FD2D2ULL, 0xF6F3DCC9C21D7C02ULL, 0x266AF896154517BAULL, 0x34C730B44AC1DD02ULL
        },
        {
            0x70CB1BAE40A9A8DAULL, 0x882FDA3C3E73A598ULL, 0xE30369E457355F87ULL, 0x06FC28EF2474AB30ULL, 
            0x188CEFDEE17CC958ULL, 0xC3123775FAA4E2A9ULL, 0x7DBB1A5DCF047030ULL, 0x364F3E98107A83FEULL, 
            0x2BB8678EECA46D24ULL, 0xD9CC4A3B00EA4762ULL, 0x844909E11FAD64D2ULL, 0xBE695FAE7DDD06AFULL, 
            0x1F98C5E94A4786ADULL, 0xC782BB2A473D0848ULL, 0x5200803D6BFC236DULL, 0x112F2387BDE9FC83ULL, 
            0x1EE8EBFB0CA4B9C5ULL, 0xC574CA7BB393B919ULL, 0x30A2B79CAEA16AF6ULL, 0x662AE53A8CDD836EULL, 
            0xC79F3BC5486112A6ULL, 0xAD7D5B19DD6D7D72ULL, 0xE73CD415CF7FCAC0ULL, 0x722C6561F254C9A6ULL, 
            0x7D412102D085D827ULL, 0xBBA81333C26F79D4ULL, 0x23C4A26326147116ULL, 0xCEAEC56A98702D45ULL, 
            0x4C90BD8E51EDFDA3ULL, 0x22FCFC9E6D7E37B3ULL, 0x00BD16A456C6DB67ULL, 0x666BEEC30CDDB2BAULL
        },
        {
            0x2D46C154C0A1762BULL, 0x15644F8815BE6DCEULL, 0x6243523637C54EDDULL, 0x55AB4DB0495322DCULL, 
            0x01F79562AFD36F89ULL, 0x8B3E97FFC2D01E0AULL, 0x401BB4AA7981DD09ULL, 0xD7DCE968E59C5F71ULL, 
            0x8D173CBBE5181029ULL, 0x4A02F0C201849472ULL, 0xED0561F2C3B4CB43ULL, 0x7CCD1A1F8E3CA75CULL, 
            0xCE1857A841DCD726ULL, 0xF8F32123D8344B14ULL, 0x62BDDCC832E49F9AULL, 0x9536A03561CA4FB1ULL, 
            0x69E54B3CC6E5B0A1ULL, 0xAF23495DCDC6B706ULL, 0x051CB1C54F00A4CAULL, 0x327953FEE53B2957ULL, 
            0xE83CD469166224E9ULL, 0xBABFA64633E681B0ULL, 0x5E0D891817BDA3D9ULL, 0xF6559AF4DA9E9C42ULL, 
            0x9638800445002D1DULL, 0x36D42885216C55C7ULL, 0xF4C7CF3D157BBDA4ULL, 0xBAD8903DA02845FFULL, 
            0x78E9AD379ACC8C60ULL, 0x6B8A6C31CB9E1896ULL, 0x0BD81E6696DB2DF6ULL, 0xDD99C1AF6A380FBEULL
        },
        {
            0xCFE36685AB4EAA17ULL, 0xE47B07418B5E7A13ULL, 0x5756FA6E45801743ULL, 0x8CF1748A2CEE3E20ULL, 
            0x894C43B3B066FFB2ULL, 0x70358D550AF6C932ULL, 0x42905294FFFB167FULL, 0x9F5E920365995F98ULL, 
            0x54528C6B58D7440BULL, 0x3A02B8710708F199ULL, 0x3C316A123864E159ULL, 0xC5A74C021DFA5189ULL, 
            0x1A8B18DAA55DE9B4ULL, 0x04DBBBB0475915CAULL, 0x4104CAF9622A7414ULL, 0xD2E14444EB604A7DULL, 
            0x152E174913AAF2AAULL, 0x12560DC2D22A609BULL, 0x253CF9E8C9763D76ULL, 0xEEEE7C97D9D0F66EULL, 
            0xA4F1B88EC39F9B5DULL, 0xB9C843BCF30CDC32ULL, 0xDE0797F37FD99B0EULL, 0x4FF67C3127D44F65ULL, 
            0x7A7E594AF1B122BAULL, 0x62D0C4825F50E5B0ULL, 0xD8081147858AF4F5ULL, 0x3CCE80E7668137D9ULL, 
            0x296B3EEEC6AFC94FULL, 0x0092AC38CA547C40ULL, 0x4911F624A01428CAULL, 0x29DB55CC9BCFDCE2ULL
        },
        {
            0x5450E7BEF1B13684ULL, 0x573192C83FF5D7EDULL, 0x7E2DD8FA265EE4E2ULL, 0xF9E24E645C72EE74ULL, 
            0x8A4D9A82F6DCC2E2ULL, 0xD70FED033744DB9CULL, 0xF62A3EFC45FCE930ULL, 0x95E896433024A6C5ULL, 
            0x1662ACCB477777FCULL, 0x0EDF3DFA4D971D10ULL, 0x50284187E30C6865ULL, 0xDD22B8B7A82D37EBULL, 
            0xF47CCEB153BFBEC6ULL, 0x4C95C8C310595435ULL, 0x862BC21C029B3403ULL, 0x126FCA8B1472B0DAULL, 
            0xB6940C25E426A7D0ULL, 0x496933FFBADA4D7FULL, 0xE758E5294536C75DULL, 0xD69DB770DBA61A40ULL, 
            0xD45FD3F848CAA648ULL, 0xE3E102124F6F26D9ULL, 0xF32ACA2FF6040A8EULL, 0x6E0B65560763A300ULL, 
            0x04C2A5BAF2509450ULL, 0x9B18FD944054D739ULL, 0xEBAEDA1D65D89321ULL, 0x23EC4E471279D4E7ULL, 
            0x32D4EF5914950765ULL, 0x5B1701BE74851792ULL, 0xD417D6295D111693ULL, 0x3C91D5E63A5B3803ULL
        },
        {
            0xE5FEACF8FA5543ECULL, 0xEF1D29EA7CFE204BULL, 0x525A523895F08C39ULL, 0x934924ADC373BDC3ULL, 
            0x51D3ACE0CB345FE7ULL, 0xC9ED8DF62EBBE995ULL, 0x0759BB46532FDC82ULL, 0xBC86284EE8134E26ULL, 
            0xF8C59EBEC17889A0ULL, 0x66125A584F2DFCE5ULL, 0x0D794A702D06A177ULL, 0xC69AC55B41B34A11ULL, 
            0x2DD7DADE582B11A2ULL, 0xF7712FB9BB2170F6ULL, 0x8E726736C23137D2ULL, 0x689EB62904133BA7ULL, 
            0x5A97451E76B05AD2ULL, 0xB1E719F53A0D7E9CULL, 0x741BD0BC76294773ULL, 0xE418E782DEBF1276ULL, 
            0x5E9400BA21961123ULL, 0x06787B086FE6EE28ULL, 0x6B33B8BB176C221DULL, 0xF8D6AF9D6B5EB5C5ULL, 
            0x43FFD3C3AAF36852ULL, 0x5B574AD3CC6211FEULL, 0x0AEE10545FA11F3AULL, 0x5FBEA411E023F1AEULL, 
            0x945F354B89912AC6ULL, 0x3BE77C4279E18DB8ULL, 0x86C46CFF8C96C67EULL, 0xBBB3E070092BD0B8ULL
        }
    },
    {
        {
            0x151D3BB9A6D14F87ULL, 0xE8B271FB782800FFULL, 0x1AB794AC33D46F09ULL, 0x7932BB9F08A09EA3ULL, 
            0xA4CC5435FF0236E7ULL, 0xCDCD8F317FBD4CE3ULL, 0x06935C85E7F2BF72ULL, 0xF7BE3D84F29EA84EULL, 
            0xF15AC832C7E4FA78ULL, 0xEFCB133D898DE19CULL, 0x96E6B6800FE9F6FBULL, 0x60F9366B7C910B80ULL, 
            0x634C521D936F944AULL, 0xBA061AB2EAC5AE2FULL, 0x7435CED7288B686FULL, 0x7DBF14CC8087217AULL, 
            0x5557331F6AB253FAULL, 0xEEA9EEEC3BC8FBFDULL, 0x3C3948EABBA91340ULL, 0xB38D7A0A02B23F10ULL, 
            0x1A322BB8E0749919ULL, 0x64E1199B11399595ULL, 0x199B32319D8E81D0ULL, 0xD3A1355AFCA04D3DULL, 
            0xABBCF56BD25A8018ULL, 0x153898DFEC1225FFULL, 0xC349A5268062AB52ULL, 0xD1CE46D3B7D37B21ULL, 
            0xBE2E3C4B16F5A608ULL, 0x79C72A265A90D329ULL, 0x387F941E48BAA213ULL, 0x928967BC9ECA0FDAULL
        },
        {
            0x827562C19F3201BAULL, 0x73928F93BA604AF8ULL, 0x017B69D529BFA543ULL, 0xB021A30933DA8A0CULL, 
            0x649A85EC74882589ULL, 0x5FC7471B48E22E7BULL, 0x1AD7BEA2810D3E96ULL, 0x576E92B5CB794BD8ULL, 
            0x38A6FEEEEC047831ULL, 0x78E8921973195A25ULL, 0x0C2F8F9AEB36F08DULL, 0x3EF00E7DA0F327C9ULL, 
            0x62EF7283AF3E5423ULL, 0x2B660D7B33541AFDULL, 0xD92CC796017D29DAULL, 0x93C6E3E476D6841BULL, 
            0x570E70BC47900CA6ULL, 0x23EDF753DF1EC6B4ULL, 0x05286816674BE836ULL, 0x55488F052D3194CCULL, 
            0xB863D6E1C6057D35ULL, 0x9A2F66D7254373CAULL, 0x665682DC23FF78AFULL, 0xDD023C20578C88B7ULL, 
            0x2CCCF092650ECB07ULL, 0xF04F1EA115CC1C44ULL, 0x5A5E0679A8F185A6ULL, 0xB518A351AE7271E2ULL, 
            0xE39F6AE8FE54A6CEULL, 0x5C1ADCD3BCA99831ULL, 0x2D00C55FCA592FBDULL, 0x6F04AD7075E22CC3ULL
        },
        {
            0xF492A5202BDB4459ULL, 0x51D1BEEDE59D5056ULL, 0xEDCC4F42BACC44E8ULL, 0x9C984DB04103DC62ULL, 
            0xFA250FD34A83DC91ULL, 0x155D6A50BCF238ECULL, 0xF0C1C702E578C563ULL, 0xB3D254FDC9ED771FULL, 
            0xF3DDEB88BEDAC435ULL, 0x923D2D4C26FC21CEULL, 0xD9D8C9AB31E31E19ULL, 0xBAD8E24312D0BB77ULL, 
            0x519BB6BC8A147D07ULL, 0x17C758D56196AA02ULL, 0xE1E74E738446C215ULL, 0x3E314954063A1B0DULL, 
            0xEC5F58C2C8B664E2ULL, 0xD42B41452E539B49ULL, 0x3F845D0EB50CD00DULL, 0x6083FAC1D641C1CDULL, 
            0xC4630479D62793E3ULL, 0xBA264BE3328C6620ULL, 0x16ACC10172A23CC5ULL, 0x299A65441765961CULL, 
            0xCC3BC18151F2EA2FULL, 0x85B0DF1803569C72ULL, 0x614ADC023FF067DFULL, 0x3FB970062FF9D7F5ULL, 
            0x3803243ACF53C429ULL, 0x8D00E09DC3CF1F2FULL, 0x351272E14E428BF5ULL, 0xFA8785009126A94EULL
        },
        {
            0xDAF390EEFDA2D695ULL, 0x70126451CD4196EEULL, 0x6B39B52B4DF74AF3ULL, 0x475B30215FAB9D59ULL, 
            0x839F6C06FAE5CE2DULL, 0x373567F776DC37F3ULL, 0x4ABD10358335605CULL, 0xA3A1549E9F93919CULL, 
            0x89496B80C6A2295AULL, 0x53C10F6BD9431F91ULL, 0x7A582243A695CC4AULL, 0xDCF81F178198A2EFULL, 
            0x483D288AE69A4EBDULL, 0xEAC4B91C0A4E8D23ULL, 0xF5D811DB2C01608EULL, 0x06AE737B67EB30C9ULL, 
            0x756B8D19DEC12183ULL, 0xFBC55AA71A55AC84ULL, 0x235EA52FE4CBFF25ULL, 0x9E3B3919EA101C15ULL, 
            0x1531F2F027E1B77DULL, 0xF9F1B4071F549EB1ULL, 0xF3A7356250687EAAULL, 0xB6AD4211AC878F15ULL, 
            0x9C0B1D06A2120BC8ULL, 0x273D78F41AA7EFECULL, 0xBC3027D5A1D74A3BULL, 0xBA1CCBB43530679EULL, 
            0x8BCE10CB911BEDE8ULL, 0x8ED1DA0EEBA7E574ULL, 0x58A176AE5C97F799ULL, 0x6B880C957838827AULL
        },
        {
            0x75A7089A1F56669BULL, 0x70648E253CDD0B5AULL, 0x58E61B8920FCD8DCULL, 0x307CD3DF22F1338BULL, 
            0x5D1FAF51087D01E7ULL, 0xB56E51FAE2C6D48CULL, 0x69500DD970761F70ULL, 0x059BE63A647B6E71ULL, 
            0x45AC443EE85435B5ULL, 0x91172DE2876ACD48ULL, 0x3D563ACD9635F71EULL, 0xCD6F4FF863931785ULL, 
            0x9C71064CA6FB5A9CULL, 0xEE4C8F8E531B9C61ULL, 0xDC994D1F930909D0ULL, 0x6A1B80A88C7D86E6ULL, 
            0x2792A8C8BF1E29FDULL, 0xA26B474E9F0EE6D2ULL, 0xA05836B9027737F5ULL, 0x866F456FD9ECE3FDULL, 
            0x32F2C5CFE04ACE8BULL, 0xE1C6FFC3F10745DDULL, 0xCBDC31530921011FULL, 0x8924DE199F74BC40ULL, 
            0xB5DFD7CEA3BE7022ULL, 0x7A6AD2797D34EB85ULL, 0xCC68C5EFD0675B7FULL, 0xCC98A6CB603EDFE4ULL, 
            0xE6C1C9B6652F87F5ULL, 0xC1BF1A714D9BAC85ULL, 0xFD42929F5E45BBF9ULL, 0xAC4B43EEE6F7AF54ULL
        },
        {
            0x873A22F817DCE8A7ULL, 0x001D0AA4BF4B47E0ULL, 0xB802A36634B2035BULL, 0x6CCD09E586F0B54AULL, 
            0x4E0CB09E89784E04ULL, 0xF5D1AB9E7C7F75ACULL, 0xFCC864E11DB04934ULL, 0xB257B6584F6702F2ULL, 
            0x959CE73F8CC86A8BULL, 0x7E94A20C2B29047EULL, 0xAFE9E3B6F214C52EULL, 0xAA48A47F7D368EF7ULL, 
            0xBA907F381153C09FULL, 0x587E182ECF6E1560ULL, 0x5BB708E6AA0ED605ULL, 0x25566B452230A679ULL, 
            0x864624FF5935AB98ULL, 0xF7968516BA82D1F6ULL, 0x3B554E313C5E81D9ULL, 0x6FE7D98BFC9966DFULL, 
            0xC2AD9ADD5CCA2711ULL, 0x01740ED977DCC37EULL, 0x3565E54438874AA9ULL, 0x229F15ECB4D20E3AULL, 
            0x43DA221F09DEF9FAULL, 0x5159A6AE0F4EB3D1ULL, 0xAEB016E088201744ULL, 0x910A82D16DA18D9FULL, 
            0x4052D8F34481873CULL, 0xB837C3963D0D7F46ULL, 0x4FDA91F5313C1D2BULL, 0x203989C74CD1A82AULL
        }
    },
    {
        {
            0xF7DA2B995394847FULL, 0x5F4573FBEC8E046FULL, 0x2EC2C3FE7F8E5B41ULL, 0x80F7198AC6DFCACBULL, 
            0xAA746109974E5EA6ULL, 0xA88CC84AE08C50AAULL, 0x63D4D09AD1E5F6DAULL, 0xE2B8446E16968A86ULL, 
            0xE5E9DCEC45701272ULL, 0xC1AF8630F63F8FCFULL, 0xEA3CEE4C90537EEEULL, 0x73BDAF88FDBD8CE7ULL, 
            0x2B3C92C224983825ULL, 0xDE7D16D54A9B7E42ULL, 0x8785F3748374B8C1ULL, 0xC7EB754124B68227ULL, 
            0xC63572A69694625EULL, 0x5E8C0B5F8F6D0E16ULL, 0x52AE0B2CC3B75D4EULL, 0x48DC4100891EB6B0ULL, 
            0x674DBA6B132D1AF2ULL, 0x9D96E60A99C3F7AFULL, 0x57D92F258C567C2FULL, 0x85B675C173B405A8ULL, 
            0xD18088BBFF116633ULL, 0x121C22A5A87146AFULL, 0xAB5ED8B75C5DA5D2ULL, 0x482428130A77AFA6ULL, 
            0x89874ED5A89ED919ULL, 0x5B62780B76F26707ULL, 0xA66111A05A32A8FBULL, 0xFB608F3B01E729B0ULL
        },
        {
            0xFD4471E68BC825BCULL, 0xF507105801EDE661ULL, 0xE0F9F679E9F82500ULL, 0xA4C0BE6DC7132259ULL, 
            0x25FD5CBEBFD8DDE2ULL, 0xFA973596411D11CCULL, 0x25EC01B0E2E0C521ULL, 0xE570663615394DA5ULL, 
            0xB4D125199F363F1EULL, 0x4A8BCA12D84FEAE3ULL, 0xB37EAA87675E6C0DULL, 0x3F7FC39A367263A2ULL, 
            0x3C03DD53A8188B22ULL, 0x4CC7D276CE9D3B34ULL, 0x56EBFE16C5A93FE7ULL, 0x112D420A04986052ULL, 
            0x5FC71FB5EEFFFA9AULL, 0xD7A5C97EBAAA031FULL, 0x1ACCA2965FACE726ULL, 0xD3BDBEECB1D80999ULL, 
            0x2DA6D8DF3E0A3CB2ULL, 0xE3AC63F0B2129F1AULL, 0xADDD484AB8521EF6ULL, 0x524386798331CCFDULL, 
            0xAA53B4511EDDC796ULL, 0x944B5D3A83762CB1ULL, 0x3A9106186A5ACF13ULL, 0xF07E248E4AB967C2ULL, 
            0x9B346287311D4F1AULL, 0xB666B4E5FE9907A1ULL, 0xF4C9011017027E50ULL, 0x4DB4855E4FBCDD21ULL
        },
        {
            0xA9D6B8BE9D1EA065ULL, 0x6357583CDD856A0EULL, 0x1F651F8BFEE96258ULL, 0xAF47FA680BD0FF0AULL, 
            0x27D4FD8C2FF36EF5ULL, 0x87CDC9B81A026DE8ULL, 0xC4C46E49A0756512ULL, 0xABCAB42E8E23FB5BULL, 
            0xD7078C01B385A0E6ULL, 0xABAD0BB10AA2253FULL, 0x464C9AFEB10E2262ULL, 0xA6CEEF4EA0FAE99AULL, 
            0xB7F27F834D287DDDULL, 0xEAB997F9E4584A0AULL, 0x8151CE374D97EEB7ULL, 0x424037CEC549B7DAULL, 
            0x5C2905AD6E0F7F96ULL, 0x09044367DC6B5346ULL, 0x953D6E432D870454ULL, 0xFE7616CFD8E7294BULL, 
            0xB5488A2514F0289CULL, 0x9B5A4EAA602F2590ULL, 0xB849099A0F9D1822ULL, 0xC449B915B19A61E5ULL, 
            0xCA15EBC33810B886ULL, 0x4A8B47955916607FULL, 0xE3C1BDFE914AE8F3ULL, 0x0A9AAEE2DA4ABA66ULL, 
            0x9763F03FB934809DULL, 0xCA310801BFF1A8E3ULL, 0x9E9667C3F7A09383ULL, 0x1204B81DF7324DD7ULL
        },
        {
            0xC917D33B2E863516ULL, 0x8C9B108CE16C43CAULL, 0x8B7BC6D3CED0D72CULL, 0x9E280A55AC5BD88CULL, 
            0x5164C1AD8E96C651ULL, 0x356A0C55C1DE0081ULL, 0x8A80A9ECECA80969ULL, 0x669581BBC9573B87ULL, 
            0xD5A7C7520772B775ULL, 0x169AD9DCEFE5D8A3ULL, 0x998863CB4E04A07CULL, 0x201A2BAA8DF88D0FULL, 
            0xFB2091FEA549DFA2ULL, 0x26F1C61A8EF3DE83ULL, 0x7D78D25A26CD2CFAULL, 0x95070C685C1DC77CULL, 
            0xD30A803FE5034BCAULL, 0x6EDFA9DB976ACED6ULL, 0x299766D0CC8ED410ULL, 0xD5D454984251DFE9ULL, 
            0xD3BAE1C42B45562CULL, 0xB7466C372DF2BE83ULL, 0x5E2BAA5E772FE7C8ULL, 0x63ED8022E688AD6FULL, 
            0x7D3B3F65BA6BCDC1ULL, 0xE873AD84BA267BABULL, 0x51E7D6B02E5CD04BULL, 0xBF071EC33EF31843ULL, 
            0x1F4D62DE61DA8D4BULL, 0x0F84189A04A2B9E3ULL, 0xA26B7FFD3BB8A359ULL, 0x28EB17A5DAF9F944ULL
        },
        {
            0x1CA2024F66D801FCULL, 0x826DBFC71D374AC0ULL, 0xCA1C63D2EC36909EULL, 0x1A292C4D7C4D78D8ULL, 
            0xD76FA1BFDC8526EDULL, 0x26EB2904A0A4DB40ULL, 0x75F96011F0363687ULL, 0x07977C278804645AULL, 
            0x5B01D8D78C23A306ULL, 0x48E88952E430EB64ULL, 0x7F2C4A5B47E30B7AULL, 0x9E2BF2BFADFA8649ULL, 
            0xAF61D6166B67E4EDULL, 0x705CCA1E174AEE35ULL, 0x3732E6FA77979651ULL, 0x42363296E3A0D0AFULL, 
            0x7B0F3D0DD6BF0E41ULL, 0x96DBA74457A3AC09ULL, 0xE43BD652381C4FF8ULL, 0xE4CBC622153560ABULL, 
            0x0F465C2A956E32F7ULL, 0x241B853B9F9CC423ULL, 0xF9692352C2DD8F28ULL, 0x5AEF55243FFE970BULL, 
            0x2B713AA1F6DDADCFULL, 0x1992DD7D3C435F90ULL, 0xCECEA5C818588DA0ULL, 0x6CC7DF6FAD9E7F12ULL, 
            0x8C76A13529455235ULL, 0xC148B0CE54C0B7F4ULL, 0x1C4C1209907C2B31ULL, 0x535491556CFBE932ULL
        },
        {
            0xC212C1AF60A2489CULL, 0x262E05F076981BFDULL, 0x314DD8031E70F6D6ULL, 0x9DEAA1263E8E8937ULL, 
            0x22DC57C38BC75BE4ULL, 0x3939EE57E8A8CF08ULL, 0x09CBF557AB6C4CE6ULL, 0x723BBAE54A0E203BULL, 
            0x78B5EF56946A1DE6ULL, 0x3DC6F274B55B1E94ULL, 0xFEBDDC55C04BB1A4ULL, 0xECF949C40BF4D3F6ULL, 
            0x5C81C01E5CBCBEC6ULL, 0x3F2C7B8B8DCE8D1AULL, 0x3437D15694677340ULL, 0x9F8DE9504D52091EULL, 
            0xF7616E8A9CA3BB08ULL, 0x5D75FC1B2063CB7FULL, 0xBB301EFB5A2E61BEULL, 0x2FF8BB5D020502E7ULL, 
            0x8D043C0BCA19F448ULL, 0x865A9809D7623DFEULL, 0x2A3476096FF7471FULL, 0xF7C450D3B41BC021ULL, 
            0x45050D4A95706325ULL, 0xA2D1E426881D6B53ULL, 0xC540684954E41D57ULL, 0x9C51FC70FD998311ULL, 
            0xF34F835A5AC37417ULL, 0x566CCC9B20769B41ULL, 0x345564436114FCA0ULL, 0xA1C189FB283B244CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Capella::kKeySpawnConstants = {
    0x1E6DDEC7139CF091ULL,
    0xF02D133756849F16ULL,
    0x12B87E81598C2EB3ULL,
    0x1E6DDEC7139CF091ULL,
    0xF02D133756849F16ULL,
    0x12B87E81598C2EB3ULL,
    0xF0C6652BECD1874BULL,
    0xDA436E9A57D7BFE0ULL,
    0x25,
    0x30,
    0x76,
    0x99,
    0xD8,
    0x71,
    0x2F,
    0xC5
};

const TwistDomainSaltSet TwistExpander_Capella::kSeedSalts = {
    {
        {
            0xABAE55A67370253BULL, 0x7F777849E9C5F66DULL, 0x28BB9216009B098FULL, 0x46699308FEDAA96DULL, 
            0xF24DE7884E19955EULL, 0x0306FE9EBCD9B6E5ULL, 0xB68541CCFC1EF378ULL, 0xC4AA84B86BE094D1ULL, 
            0xFA7CB861899804F5ULL, 0xD5DA34D0BC71C553ULL, 0x66189FE1333A5564ULL, 0xE2314B960D220570ULL, 
            0x7CB8C0A33E7906BBULL, 0xE835EBB5B5E6F544ULL, 0x007AF7646DC67AFAULL, 0x94AD40F97E3BD313ULL, 
            0x1DC164F2061C1634ULL, 0x9D274B537073FF19ULL, 0xCDF23229CF9191FAULL, 0xAD5A46F4B5A5336EULL, 
            0x2644388A6DCD6270ULL, 0xBE572499A7A28D28ULL, 0x61A686CA117A04DAULL, 0xD0A17204105CD9E3ULL, 
            0x644713048249F9B4ULL, 0xEA24F70B12E931CFULL, 0x87FAA85265248CC5ULL, 0x8075B1DA3A2BB163ULL, 
            0xD89494DA6CAF378EULL, 0x387C3FB1344102D1ULL, 0x4A533C0B87947E6DULL, 0xC6B1B434CBECA05AULL
        },
        {
            0x1E97266785AE1792ULL, 0x71AF6C88277D76A7ULL, 0x4B52E6C25C22FD5AULL, 0xF26FABFB289A9EACULL, 
            0x25E4A5F5DB400F72ULL, 0xC240ADDB8A556B49ULL, 0xB85DCA03168C0581ULL, 0xD4AB0E797C4C6D52ULL, 
            0xC870F115ABD2DD47ULL, 0x828CE47FBEBE0D65ULL, 0x285E003CAB92F2EEULL, 0x17E5A74F2F5ECF1CULL, 
            0x9AB7726DDB279096ULL, 0x1A809ECCF3CEBC9CULL, 0x2EAF85F59EB7569CULL, 0xAB21D444135B7B31ULL, 
            0x227500A890618699ULL, 0x8B7B82654AC2E3AAULL, 0xCCEBF332AAD1AC6EULL, 0x84A619A1D6E0C0E9ULL, 
            0xDC3ADFD6A15FA21AULL, 0x546289DDF45B070DULL, 0x93222E894FA87552ULL, 0x0EAAF1EA53A05D67ULL, 
            0x02542FC3A1D88A41ULL, 0xC5BD51FD3B546B1CULL, 0xB5DA956E8E184C91ULL, 0x424D64811CC20B70ULL, 
            0xA5FEDDD62173C7B9ULL, 0x58C4AA9FC41F85FFULL, 0x58881949CCB20BECULL, 0x3568801E38E78DA9ULL
        },
        {
            0x33F72A5A478EC6FBULL, 0xAEAB1E20AB16AC1FULL, 0x7EBCEE0B602FE9E8ULL, 0xB2AB5E539FEC1914ULL, 
            0x57A42CC875AAF130ULL, 0xA08CC0ECAEC6DE12ULL, 0x57784DF7E08DC8ACULL, 0x8E6E0673AEFDBB14ULL, 
            0x83C3BBA5C3FD6CA1ULL, 0x831A8CBE4E294515ULL, 0xC32E6AEA426D6832ULL, 0x9C7AD592B7919624ULL, 
            0xC1258B7B66D73B62ULL, 0x47E3D4731ED64FF7ULL, 0x615ADC7AEF0751D5ULL, 0x821E9B92AAA700ECULL, 
            0x316C6407F9BD0354ULL, 0x6A46DA1C26D61615ULL, 0xBA90E9AF40A2E183ULL, 0xFD34656E5B1D12A3ULL, 
            0xB3DCB5B93AC8F43EULL, 0x26B9D71AC5D7CA1DULL, 0x3B49F9619FDBDB49ULL, 0xA57965D5F4190597ULL, 
            0x44CA66EFCEBAF96BULL, 0x7B352BC4C771488BULL, 0xDDD2CE7082498F84ULL, 0x171EB77007B44A35ULL, 
            0x6CCDB6AF6F16DE3DULL, 0xEB72B8B6467C22C7ULL, 0xF45FCAB0C6D9CD88ULL, 0x50C6C859B535A45BULL
        },
        {
            0xE1179CB144E76489ULL, 0xFF8C29CC26BDAE5BULL, 0xE22E6D8874DA948FULL, 0x292A5BCEAF01DA69ULL, 
            0xBDD87BC3E05BC485ULL, 0x2C2286F5613B10DEULL, 0xD8BD877DE0F04D71ULL, 0x1BD9D9563F3769C7ULL, 
            0x16FCEF26C2DA1F99ULL, 0x4D4256521DEAC944ULL, 0x2E1156D88E722AAAULL, 0xF8CA2A4BE608F8A9ULL, 
            0x24007E282134D47AULL, 0xBF23A4363AE5B791ULL, 0x7E00E2A59B89813EULL, 0xD7A3BDF01D259B2DULL, 
            0x7D7D56136F326FA2ULL, 0x43D69644B221CE1EULL, 0xD7D7C831A82BFA08ULL, 0x7545E752D1C18EE9ULL, 
            0x0822729860E91650ULL, 0x7B2333629DF9766AULL, 0xDC148379E332F9FDULL, 0xF1439D750109C64EULL, 
            0x69356C8CC6FA7BB1ULL, 0x6B53D57F60CE90F3ULL, 0x0F7B76E8F284E60BULL, 0x95E75602FD8027DBULL, 
            0xF831C0871A845E6BULL, 0xD3295A031FD76DE8ULL, 0xDA3A8D071644D988ULL, 0x6703E654BE2E23FDULL
        },
        {
            0xAFFA902460EB84CFULL, 0xBE63795738A01F5AULL, 0xDDD79F88A9A95FFEULL, 0x20770362DE4356C1ULL, 
            0x8937B64B901218E8ULL, 0x35289D083316DAA0ULL, 0xB7D0FA9D0E692A6EULL, 0xA0EA10C16CD5E984ULL, 
            0xF6809A6D671513A9ULL, 0x7424973B8B672E34ULL, 0x51571EED6B06D994ULL, 0xDB8F2683209158C5ULL, 
            0x5DBCCAA6AE5F17EDULL, 0xCBE5090970D3D132ULL, 0x26AE7F26116039DAULL, 0x87CB258F3E0E7DF5ULL, 
            0x3217067A7917788DULL, 0xD9D9AED5CCEA3FC7ULL, 0xA3AA0045FFDC2EB7ULL, 0xD5321F5B73D5961BULL, 
            0x755ABF95260ECC71ULL, 0xA7A0BD14011A755BULL, 0x35ED1263C90C1FAFULL, 0xEF2E98AFFECA5B8AULL, 
            0x15AF87668200D324ULL, 0x39CDF7CF735E96C6ULL, 0x0147A96D012BF13FULL, 0x72E4564F201257A9ULL, 
            0x592EE98C21EE2691ULL, 0xF2F748DFF25F5197ULL, 0xB4B03EA7F546A1EEULL, 0x417E76FA85DE9A7DULL
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
    },
    {
        {
            0x528AFE10E9FCE0A4ULL, 0x101173F01BE75D6CULL, 0xA172DA4B5CBD77AFULL, 0x219F75338C60D9EDULL, 
            0x1DE59F16EA6F65AEULL, 0x18484C80176F3734ULL, 0x49A6C44850ED94DDULL, 0xC42F1EC2C7E74BC7ULL, 
            0x1A7470B1050323C0ULL, 0x2B841E9BF803CD4FULL, 0x4905B5026476C535ULL, 0x634BAD49F308B006ULL, 
            0x7DD9A0B60101770CULL, 0xB8F691828636F107ULL, 0x1FD2F51D953204DDULL, 0xD5898D058CE78163ULL, 
            0xBF40C28A4168E182ULL, 0x831BCFB4233E69E1ULL, 0x28B9652CF3690801ULL, 0xB8E1FA7E5BF7D52EULL, 
            0x59021D970686C99AULL, 0xA6FBBCEC134E0001ULL, 0x48727BEE78759F2EULL, 0x56565A1E93E8127DULL, 
            0xBE97640093A8CC65ULL, 0x731D7DCC021D80F0ULL, 0xF1E66BFC8B1D6E63ULL, 0xF07CE369F48420A4ULL, 
            0x0FD709B60FD274C0ULL, 0x243A0E6335A14D02ULL, 0x6EF93AD06C034A65ULL, 0x38037D0129522F06ULL
        },
        {
            0x4BB7048564804A3CULL, 0x602822A4A5F28286ULL, 0xE5840FECB99ACC8DULL, 0xCB7CEFF179201382ULL, 
            0x84E7E681F14671E3ULL, 0x91B266A6E985DC8EULL, 0xA89E02DCC6864A08ULL, 0xDD00C6D7CB69EC3BULL, 
            0x3E6542AFDE1B8277ULL, 0x4C9339BABD0A1683ULL, 0x6B8C6BF74E0F75FEULL, 0x11B53AD36A0E67C9ULL, 
            0xB843356E23536FD5ULL, 0x507252C67F66CD73ULL, 0xF87DC7DA4DAAE74AULL, 0x88D9F7B53699EBDEULL, 
            0x71D16BA1D434FE23ULL, 0x68034FF18CC6204AULL, 0x75FF388DDD0D7B4AULL, 0x6626808C78FE98D3ULL, 
            0xFD0C89ABAFF7B5E9ULL, 0xD3DA1D0D9C9D80B8ULL, 0xA5557BBB40848C5EULL, 0xDF384E45675B6434ULL, 
            0x9C0E1AF1F3CA8B7BULL, 0x30F2747916599067ULL, 0xF1E711E94C1A5CF0ULL, 0x54FDBA7B40B8CE35ULL, 
            0x0956DD5397369847ULL, 0x4D5D76529332F942ULL, 0x6E712F295AC6DF83ULL, 0xF276217E445BD806ULL
        },
        {
            0x3F26C9931D0B7CCBULL, 0xEF615FB78EC984D1ULL, 0xD4A0F4F276CFE487ULL, 0xA187AB3939090060ULL, 
            0x6514E6EE550A16F8ULL, 0x06D1025E1C8C6A1FULL, 0x6DE20ABA2E778749ULL, 0x4A4474038FD03536ULL, 
            0x059864E82A0CF425ULL, 0xFFB8670A3F5FCAB5ULL, 0x7BB0EF6902D9E1BBULL, 0x4F3924C412B7423FULL, 
            0xD43FAB8F415047FCULL, 0x7DC23DBE03712F1CULL, 0x81D8E5FE77D1459CULL, 0xE75B92A349DE364CULL, 
            0x9EE193BB48E804DAULL, 0xB8445A60E0AD190AULL, 0xF403F14E22413DA4ULL, 0xB248BDAB037D2F0EULL, 
            0x59AD000965CAB065ULL, 0xA8247DBB765A3CFEULL, 0x38197869C57F3967ULL, 0x48AC8A0937DC4C35ULL, 
            0x5561B18D3FA1166CULL, 0x0236E72218DE97A6ULL, 0x1E43F391B02B6BD5ULL, 0xB37F29A5327F1E83ULL, 
            0x7BACB6D1619411BAULL, 0x630FE34B17AB236BULL, 0xC221DE70D5121F55ULL, 0x6189A9BE28A16B26ULL
        },
        {
            0x74D7C65B70A3EB78ULL, 0xCDB12F29003E3223ULL, 0xDB0EB6F7C61167D3ULL, 0xAD394FF33C3B1383ULL, 
            0x30B74DDE7B2C344EULL, 0x2444F68265F8FC86ULL, 0x3D9ADA2557E2CCB9ULL, 0x1780ABE87A750B06ULL, 
            0xA30CD61C28AA2F99ULL, 0xB59FC311806E6D5BULL, 0x12BBB6456F17B63EULL, 0x108AA3568D764E8FULL, 
            0x46A9E1A7A6095A6CULL, 0x757BE5DB6CA00A4AULL, 0x9459157CF60ED890ULL, 0x202D23543686CCD9ULL, 
            0xDAF77AB17A5471DFULL, 0x822CB39BED57A222ULL, 0x1DF1353F25F047FBULL, 0x6BF8227D356FBD32ULL, 
            0x008CA6572FA58E1EULL, 0x11618E9E551B3EC4ULL, 0x437FBA2C067DFFD6ULL, 0x80C93B8D71CE42C8ULL, 
            0x6B2249779A806F94ULL, 0x4994E4C699448246ULL, 0xFB4D54DA5161C4D8ULL, 0xC6184A0041A2143EULL, 
            0x8862515E5B4C895CULL, 0xD04671861848BDB0ULL, 0xEE2A28E2CA1739C6ULL, 0x14209FA4A0AA637CULL
        },
        {
            0xA6E50622ADB868F6ULL, 0xB568407D9F7875CEULL, 0x58874F04E0A37AE8ULL, 0xB8703CEDADD463C3ULL, 
            0x6CCD426B0D1C3DBBULL, 0xAD0E01C6F5B16C89ULL, 0x99F325432DBA7E87ULL, 0xBAABC1F62DF6CE3DULL, 
            0xAA4DC90BB7A1381CULL, 0xBA308A7065F5D3AEULL, 0x056076F0608A768DULL, 0x88DAE44C4BD5A989ULL, 
            0xEF70DBEC649EE023ULL, 0xD01D451B705E19C7ULL, 0xAF695D5353080610ULL, 0x4147B5CCF8FF394AULL, 
            0x52846058D546CF64ULL, 0x82A4C5315733C6C3ULL, 0x680E72EAD3EFD5B1ULL, 0x89B5B7B544890886ULL, 
            0xB349EB381A754B1DULL, 0x00A420CA46DF719EULL, 0x99F6087EDD78F375ULL, 0xC3E83D7AD1FDB6A9ULL, 
            0xF2DC3530FE910730ULL, 0x011633E4B89289ADULL, 0xBC3A813D09FB6036ULL, 0x2994F1BC684B689DULL, 
            0x1A9D744F7CEB918BULL, 0x772CAF946A88E6BFULL, 0x5F71CD76CEEBCA01ULL, 0xEED0C6C6D5966CD4ULL
        },
        {
            0xC73FAA772EF69DDCULL, 0x81A321102A5B810FULL, 0x5E4456CAFA575BD0ULL, 0x0933C52F65AD72A2ULL, 
            0x36163748465C73CEULL, 0xA69FC7E2F7D9DB44ULL, 0x7A7FD1140491656DULL, 0x4AC752E9F1A0B3CCULL, 
            0xE3DDF10BB9A9BAD1ULL, 0x462A99BB34D7FD94ULL, 0x2034118FDBCA9C44ULL, 0x1427944B39BAC36DULL, 
            0x3B66D41D65EA4AF8ULL, 0x2A52788091116824ULL, 0x2BE74831BBBD7D1FULL, 0xDFD17DE8CFA88588ULL, 
            0x09CEB536A70C9644ULL, 0xD313C698515ABC4EULL, 0x96334A5259CDE6DDULL, 0x619352499E39EAB3ULL, 
            0x30E4845B79DCB3CDULL, 0xB91FFE931F7FEFE0ULL, 0x83A0A0C4E0F5E18CULL, 0x656DD2296A589492ULL, 
            0x987958299CB1E42EULL, 0x4E5590BF895162B8ULL, 0x95969FC7C4C81982ULL, 0xF701B773EC7A1D18ULL, 
            0xE1CB3B4368350ABEULL, 0x5551FB9EF6532B2DULL, 0xB2647FBA82FCB906ULL, 0xB58CCCCF3C392642ULL
        }
    },
    {
        {
            0xA193CE96F260C15FULL, 0x30E2F319BDB4A419ULL, 0xD2DD430334C763E7ULL, 0xCAA808016D90D9EAULL, 
            0x78F6E0E63B0C007EULL, 0x176C1829000281F0ULL, 0xD1E993CFE0C0FDBFULL, 0xEAE7F52498FFB970ULL, 
            0x95DB5C282E8EAC0AULL, 0x909A1F246FD8FFA5ULL, 0x0D41AF506120AD56ULL, 0xF1096FD0146978E1ULL, 
            0x92E90A974B5741A7ULL, 0x41B800A322FAE921ULL, 0x1A75EF797CDD9504ULL, 0xBFE62B08FDA746F6ULL, 
            0x64BE0DE48FA86D9FULL, 0xE4BA2661E6B1C0D4ULL, 0xEFB690AEDF8A0F06ULL, 0x2D6703BCFD885E58ULL, 
            0x0146A4A714300912ULL, 0x2FD65311C0000866ULL, 0x2ECCE6CAB23178B1ULL, 0x6E3D7E8733F9A1F2ULL, 
            0xAE6A07307BF720F9ULL, 0xD9ACD47B6D8C21F7ULL, 0x9C078F79A123717BULL, 0x12985EF522C0A757ULL, 
            0x0F18C0BB8F06D8DFULL, 0x66B1BD0058356A7AULL, 0x026270414CF6C838ULL, 0x04AE252817084888ULL
        },
        {
            0xDCA3DB550E26AE17ULL, 0xF021ED7E860CD12FULL, 0x97A11B1F3D1B92F8ULL, 0xD60F0CE74D41D409ULL, 
            0xE81E8625B45F9F0AULL, 0x673E509F43368F91ULL, 0x575D0DAA8DB05540ULL, 0x1E10A3FCCBF0C4F4ULL, 
            0xB51022F97A97ABF4ULL, 0x8B808E216D3C3EDFULL, 0x90F8BD18D9D63021ULL, 0x741CE79CB4F25777ULL, 
            0x2AB0516914F3BE56ULL, 0x1B743C854F63B933ULL, 0x21FD935C1BBDDE51ULL, 0x4DA8629844B52CFBULL, 
            0x059F4A8CB6193863ULL, 0xFE5538ED6EB088F6ULL, 0x40E744FCB406EE8CULL, 0xFBC852075C2B3BD1ULL, 
            0x2912BBFE1746336FULL, 0x90695F925B051216ULL, 0x746512C22CF2004DULL, 0x5CFDDC68BFDB5244ULL, 
            0x93AE45DD4851A067ULL, 0xF2C328F3E3879F31ULL, 0x3D6174DA028BE0C2ULL, 0x70A785CEF74B86BAULL, 
            0xCC028E35B2D93833ULL, 0xECF81D1F4998E174ULL, 0x03B1801DA45FDD32ULL, 0xC0BA85426A052EB4ULL
        },
        {
            0xC616AB98CEE81E62ULL, 0xC8E8B25D9BC1DF3CULL, 0x36A0F9F969EDB5CCULL, 0x9635D61798D95A85ULL, 
            0x77B3604495DC40B7ULL, 0x145ED1ADF1CCA84CULL, 0xED34E08F48579F9DULL, 0x833498592279CD05ULL, 
            0x957CAE7FF5CD72EEULL, 0x951BD666A8C10B23ULL, 0x47FFFA983E1A0648ULL, 0x02D62D12F3F5F969ULL, 
            0x3FB7DF2D5858628BULL, 0x59A7C0DAD5373EE9ULL, 0x27DD88C6767B7452ULL, 0x524A1EFA9AC16C60ULL, 
            0xBD59B0493EB1A1F8ULL, 0xA94FE0C6B32B0983ULL, 0x4D8AFAE728FD51A6ULL, 0xCF647DA5C4D30C46ULL, 
            0xDFEF3C641DCFCEE9ULL, 0x9C2B137E13F2C036ULL, 0x32E54797DCF063BEULL, 0x90399828A332074CULL, 
            0x36763B546EE53FC8ULL, 0xE9D7E414C918D509ULL, 0x7DF03E918A21F81DULL, 0x1A0D1D1E47074D0BULL, 
            0xD77520CB36338561ULL, 0x97CF8AE0192EF89EULL, 0x16F1FE422736B6CCULL, 0x8AFA95270AD9C805ULL
        },
        {
            0xF049E5F7618341B5ULL, 0xB51566F3FA9D076DULL, 0xB89DFAE33853D27AULL, 0x436D593925E44B68ULL, 
            0x24A5317D4A87A17AULL, 0xF8F73E1FA6418DA0ULL, 0x97DEBF69FCA250C9ULL, 0x72775286AB34998EULL, 
            0xD7A2C4A75F35BDD2ULL, 0xAB0487F696787368ULL, 0x316F77A8A09AAB67ULL, 0x2743C1547D7708F3ULL, 
            0xF0E6E9A18CAA93D6ULL, 0xAB576E013096D526ULL, 0xD1CD3760B554CC7FULL, 0xBF38C68584FB5959ULL, 
            0x103C1AE93873F215ULL, 0xAF272DA1E09EDBD7ULL, 0xBA25F0475B99670EULL, 0xDDAFC6A08805CD75ULL, 
            0x79263C2C02B26ECBULL, 0x6C9EC7506D7FC958ULL, 0xD1C63415C7DFA807ULL, 0x486F11B2980D034EULL, 
            0xE331FA699FCE24AEULL, 0x515836FFE5357864ULL, 0xD99071E21DBB1CD4ULL, 0xF696B47CF31890D6ULL, 
            0xEB6A7F7F5203B53EULL, 0xC8C575DAAF311A91ULL, 0x0A8F5240F0751B7AULL, 0xF088D51810A4DEB6ULL
        },
        {
            0xFB047003CE38A688ULL, 0x6A8846EB461821BCULL, 0xA012A50B96145B61ULL, 0x6E98865EFACED6DFULL, 
            0x30FED7258B0B74C1ULL, 0x87D8AA72B7876912ULL, 0x9B111594371B4BA4ULL, 0xBC2FA7E19BE29916ULL, 
            0x9D79DB91E812DD4DULL, 0x81E447363B0D7E19ULL, 0x90EA012B6296DCC7ULL, 0x4A5BDE8E0A7A3240ULL, 
            0xDB4D168A8F69792EULL, 0x0386D85BB0FF1634ULL, 0x27E9C61AB1480C73ULL, 0xFE2257C7C1536A56ULL, 
            0x8C296BA5C003E808ULL, 0xEDE7D4BE7E631F62ULL, 0x150935D6FCEC4954ULL, 0x98D9670A7BD0F470ULL, 
            0xB0A3AA18CA6A155BULL, 0xCBF0D58A79337845ULL, 0xCB551E919F986072ULL, 0x8EC7268BAC21A2DCULL, 
            0xF2CF90E0E2F53BA0ULL, 0xE989216AE3A157D0ULL, 0x05B848D9E6113BA3ULL, 0x5A6694354685668CULL, 
            0xC17E584554D71C16ULL, 0xC47DA0B7477AE433ULL, 0xA1C5DCB71A8A378DULL, 0xE220BD2B2EBCF023ULL
        },
        {
            0x6159AD673E7541B0ULL, 0x023722F57090D12BULL, 0xC3C37C5BA9E7C5B7ULL, 0x04DC64B4D713B558ULL, 
            0xBC21FAA987796634ULL, 0x2A3E641F734C2318ULL, 0x73A531611188F0DEULL, 0x3E9A0D0CB11C5950ULL, 
            0xDD36CF536A67ACA0ULL, 0x4047DF52E8E255C8ULL, 0xAE8BE12CD17C2F34ULL, 0xCB1B999FC4D5C759ULL, 
            0xD4ED7369C10C45F7ULL, 0x701278B54F19B086ULL, 0xF6D66B3E13CD4D2EULL, 0x7446211660479740ULL, 
            0x9D347DECBC736896ULL, 0xEC397F7824667F3BULL, 0xEA854CD86E24D27AULL, 0x10EFFCCFF53619F0ULL, 
            0xD995BB0280905CB8ULL, 0xB9EE5FECAE8D6016ULL, 0xBC52B577D9E61F33ULL, 0xD93217BBFA9BE996ULL, 
            0xAA8E1EC0C4E6746AULL, 0x5EA8190B25EAAD96ULL, 0xF87FEC30BB0FF7D2ULL, 0x34C809743440966FULL, 
            0xCBB0D091B7BC7926ULL, 0xE126FBA095BE71D4ULL, 0xC31AEAA2775510AAULL, 0xA6B4AFF08D74084EULL
        }
    }
};

const TwistDomainConstants TwistExpander_Capella::kSeedConstants = {
    0x301829FC547E0968ULL,
    0xEFA3C891757CFAEBULL,
    0x5526A38FEE366600ULL,
    0x301829FC547E0968ULL,
    0xEFA3C891757CFAEBULL,
    0x5526A38FEE366600ULL,
    0xDDE6346EAAD9EC88ULL,
    0xCFC162C6DD1D3572ULL,
    0xE1,
    0x56,
    0x45,
    0x67,
    0x97,
    0xCE,
    0xBF,
    0xB6
};

const TwistDomainSaltSet TwistExpander_Capella::kTwistSalts = {
    {
        {
            0xD0DAE6616BBD620AULL, 0x10458F1F2FE3AA03ULL, 0xF4B29028213E6E0CULL, 0x1E1D16B9DA49B8BAULL, 
            0x8253DA3F1014BDB4ULL, 0x3A3580BC56CC5EFEULL, 0x85EE516B7DC432B9ULL, 0x371FE5AF86B97EBCULL, 
            0xADF384A9B29B5D66ULL, 0x232DDF0BDE1A8332ULL, 0xF783A630992674A0ULL, 0xF4F4B963E57D5802ULL, 
            0xCB9EACB3C60F977EULL, 0x321BFF445F1A7A00ULL, 0xD3073FC6BC27B412ULL, 0x5331430E32ECEA99ULL, 
            0x45B0B1521A458A40ULL, 0xA9E4657518F008E9ULL, 0x053A466E2CFA396FULL, 0x26EDC7D2EA9D971EULL, 
            0xCC0EE9A8B9AE77E5ULL, 0x1F9FF59B01A80A1BULL, 0x16CC101D408821BFULL, 0xBE9211DE5B626DDAULL, 
            0x51CA8199154B0AC5ULL, 0x281AC7F0DF78A619ULL, 0xBB6FAA844020649DULL, 0x08FF201BE33DB6AAULL, 
            0xDA45B44B90B6BAFBULL, 0xF38671E31AAA58D6ULL, 0x46B879F9C0D33547ULL, 0x98DEA0CCF6B33ED3ULL
        },
        {
            0x295C0230D402E574ULL, 0xE6AA811AF104EF54ULL, 0xD450B4EF661405EDULL, 0x67CF03916DF972E2ULL, 
            0x1A8F8DE380315C74ULL, 0x0C8B33C1E11BB468ULL, 0x30054F5E9298553AULL, 0x22702F0E17E05AD4ULL, 
            0xE306166B3E65B003ULL, 0xDEBA26C39B6F8768ULL, 0xA3FEB71F10781054ULL, 0x6CAD7DADF92E7811ULL, 
            0x4B07450AE5D25AFBULL, 0x48D731A339BB77B8ULL, 0x9B693C9201BEFD13ULL, 0x69240D545F741100ULL, 
            0x419BE735C11EC092ULL, 0x7DEE6C3AC628616EULL, 0x2B25759F39F572B7ULL, 0x15708AB4BDD70B6FULL, 
            0xF9C06B8649EBE7D8ULL, 0x549DBFF2B7F06C9FULL, 0xBFBFA998D3A99555ULL, 0xF02BAE20222A5F3BULL, 
            0x559F67CF3B3D758EULL, 0x44C6496E178E5393ULL, 0xD29C49283600AAE1ULL, 0xE27BC1F88EC86A16ULL, 
            0x03BF71FCAC62908EULL, 0xEB7A7C56CB0C8B7CULL, 0x0CD9C5DC77EFD6D8ULL, 0x819319E504AA415CULL
        },
        {
            0x9A8D32FC6E8A55E7ULL, 0xA1C6ACE97C2D7F90ULL, 0x66CA046A8A96A93CULL, 0xBB996D97FAC84E2BULL, 
            0x9A6A992F67284579ULL, 0x0F0B7288ACC48A94ULL, 0x7474E51CBC8773B8ULL, 0x8C1C89D96FD35AB7ULL, 
            0xF5C0F24D351C43E9ULL, 0xA7C69A54A39773DEULL, 0x238102DEF558A8F9ULL, 0x6516447421DC7FA0ULL, 
            0xEBCF9E9BF56AEDE4ULL, 0x00BF7726B19AA50DULL, 0xC93AC017A97B6065ULL, 0x1F61AC2C263D9CC4ULL, 
            0x1BB4CE9120C14C52ULL, 0xD766FC0F08368112ULL, 0xCB2C33AB666B16A1ULL, 0xA0252A1C54D06264ULL, 
            0x6C3BAC7B8F284423ULL, 0x98C66A7DB6A42FC2ULL, 0x538B357463E8EE28ULL, 0xF6223278A7EC302EULL, 
            0x110FAFDE276B649DULL, 0x84DC9526A739DC65ULL, 0x2DED8DBCF478AE58ULL, 0x88835D4E62D0C99EULL, 
            0x9835B31B6DCF66CDULL, 0xFD7EF88B818AF662ULL, 0x57B039DDAC6317AEULL, 0x6D121D0AD541B118ULL
        },
        {
            0x7DD16C04EAC9EA24ULL, 0x747A8B298201B673ULL, 0x3197728769EBF49BULL, 0xB0AC6A67CDFEBFD6ULL, 
            0x5644F6E5313D25DAULL, 0x04E3BF8A62BF221BULL, 0xDB8602D8C485BCD8ULL, 0xEA224DEDC4D07105ULL, 
            0xD2F95F1ED8DFC5A7ULL, 0xCDCA0DA58F868589ULL, 0xCC909F5436FE7C44ULL, 0x67E25D34B17AB4EEULL, 
            0x40F0070C98B4E5B2ULL, 0x44F9EF0DC744F5DCULL, 0x434BC5EE0E3FF5ACULL, 0xACAD8A7F49A1E0BEULL, 
            0xD30C5466F55B7C05ULL, 0x4DBEFA899B5F7469ULL, 0x02AA6DAF38912B93ULL, 0xE3A082CA8DC13E17ULL, 
            0xC28D50C27FF24863ULL, 0x1ED8D7CAA9257218ULL, 0xE94F2EA40885AA1AULL, 0x044B522A50646D56ULL, 
            0x0DDCE926E34F2817ULL, 0x4C6A6F9EAB61A756ULL, 0x94842B7E4E4F692FULL, 0xFCF699B8020DF358ULL, 
            0x27EBF0FD94CAC15CULL, 0x4C9441A10D059C51ULL, 0xCD475056EDB99766ULL, 0x7DFB2BD3FB76E367ULL
        },
        {
            0xD13D446529D8FFC7ULL, 0xACA97E3146FAF517ULL, 0x9DE68324BD1B563EULL, 0xBE5B835C44D3F096ULL, 
            0x4B5CED390F3C2B63ULL, 0x85B6C7A31256AB1EULL, 0x6C522039C962E6BFULL, 0xCEB32BDE92812CC0ULL, 
            0x65FE3D6085AE3CB7ULL, 0x17E09E7434DA3F6BULL, 0xCC677DDA9CE9971DULL, 0x687BE6C03D8DDB9EULL, 
            0xCE3E28B1DE03793BULL, 0xCF160BD51803C4B2ULL, 0xDD56BDFCA922E1B7ULL, 0x43B890FB5B4D35C6ULL, 
            0xA191A32B2E2FD452ULL, 0xB0AC48AD3A54B375ULL, 0xF208B0286C0B8892ULL, 0x05767F51CCC6978AULL, 
            0x6FA587F95D6F6798ULL, 0x7FE45D190D8D87B5ULL, 0xE1F06632BB6785B0ULL, 0x68181A9F1C5A3945ULL, 
            0x89F2F0D150381A24ULL, 0xA110894BFAC72D8FULL, 0xADF536BFC292713CULL, 0x23AC1632D394B311ULL, 
            0x1AAEA55F5D5DC154ULL, 0x1C4B40005B5F0F0EULL, 0x9C24784E89A27A67ULL, 0xDE7FA28C3DFCF30FULL
        },
        {
            0x42B2C2F99B98B8A6ULL, 0xBD8532F1E0351D9AULL, 0xCA046276E1C295D5ULL, 0xD1E19D7747154B97ULL, 
            0xEFDC3230CDBDC325ULL, 0x483125A8C86029C7ULL, 0xB2B0418B5B8FB1FDULL, 0x350719C5E587987EULL, 
            0xDC71A2EF50EA997FULL, 0x4141E38D01DDECADULL, 0x8DE53B3FC2B4CC08ULL, 0x52F5B0686AAECC9BULL, 
            0x42B0D95BEB236391ULL, 0x2FE149D0E525C377ULL, 0x0AD21D9EC534C09FULL, 0xA995C3FD42B7FBF8ULL, 
            0x39961DAC5ED005ACULL, 0x1ECDB6F8F1BB6537ULL, 0x2E5ED0115D9895E1ULL, 0xD2DF9D9D9FAAC329ULL, 
            0xCB2C275236B9F26FULL, 0xBA053432F0210B82ULL, 0x31A3C20E297B856BULL, 0x304392824DFDC2A2ULL, 
            0x9621B29885D57BEFULL, 0x378AE355DAF4534AULL, 0x442FADA0D301F1B1ULL, 0x02BFD554017C0234ULL, 
            0x724534E63F7EDE6AULL, 0x1C7EFABCA937602DULL, 0xF10C420BAA6865BAULL, 0x8E6A8E46D39D0A63ULL
        }
    },
    {
        {
            0x505263F18804AA2EULL, 0xF83716A875D488E7ULL, 0x76E64327B899C7F3ULL, 0xE11B76C72E5CAFCCULL, 
            0xBAFFBC263C033C0AULL, 0x2155D055177C2953ULL, 0xFD7A26B08D2D32C7ULL, 0xAEAC0FE7EE0BA32FULL, 
            0x82569BC698B5B0A2ULL, 0x7B2EC442BAD5CD0BULL, 0x034E6F3FEC66565FULL, 0xC75D1E68E0834B3DULL, 
            0xF8A4C408798B8BECULL, 0x3777AD1C18D1A134ULL, 0x76D00598CBF3F598ULL, 0xBECF90D065B2F85CULL, 
            0x111B56C01D8B9EFCULL, 0x5410530D051A73A3ULL, 0xA80862A3DA1AD6E7ULL, 0xF7878F3FE7B56392ULL, 
            0x6C40787558559ADFULL, 0x2F8E8D9656A6D5E4ULL, 0xE39AA8713D9B4DCBULL, 0xE5265F1313BC2B86ULL, 
            0xE6147BDF1CDBC2A8ULL, 0xA7A72E100B7C354CULL, 0xFCF87C679ED0B9E2ULL, 0xA24706F945ABC663ULL, 
            0x0CF6DED4AAE20CEFULL, 0xAA5315A43BF065DDULL, 0x9E16DD5E968CA985ULL, 0x10F92842F39ACA44ULL
        },
        {
            0x0D6BF6AC1E7B1EFAULL, 0xC773BBE3B6BD6F5CULL, 0xC8B2BB25C1C71CA4ULL, 0x604733666D4D037FULL, 
            0xDF31F8F80BA64C54ULL, 0x496939E923672C5CULL, 0xC523BFECAD8903BDULL, 0x396C6D342348F0C6ULL, 
            0xAF789D0043D57107ULL, 0x597E960D0F6E243DULL, 0x3AD3DCCFDDD1364AULL, 0xCE8E7CE4A04B98F4ULL, 
            0x7504FFBAEC896FFEULL, 0x83A591DF51F311AAULL, 0x37B59F247C0C1F93ULL, 0xA947CCBB0845F616ULL, 
            0xFF40A605E9B26E41ULL, 0x9955519C91CB43E7ULL, 0x8B41C5965F3CDC78ULL, 0x06B1E7C90E3F807DULL, 
            0x699E84F08C2C4C0BULL, 0x53442AF4342AAE06ULL, 0x4229ABF8A4905309ULL, 0x990003133694962EULL, 
            0x8ADD18B70DF0DB0EULL, 0x42FF933D07A00D23ULL, 0x3067A90872C70155ULL, 0x2F7B980A56CBF07FULL, 
            0x880D326D91C50603ULL, 0xBF75E12C223F96D8ULL, 0x8F69B739B5C75D2AULL, 0x78EAF412BFEF7E87ULL
        },
        {
            0xF24F451BCE1653DDULL, 0x58EBD941F6C79DAFULL, 0x7322F23DCA852D12ULL, 0xBC82B6FDD6F3BEB5ULL, 
            0x242488B37C1CC64DULL, 0x226A1A94E611BFA0ULL, 0x65935E5B17D583E4ULL, 0x4BFBD8CDDA8C694BULL, 
            0xA6FE417C0E099971ULL, 0xBBA0BA830F68BDC4ULL, 0x69FCAF8B4AEA8437ULL, 0x6FC27AC230069BA6ULL, 
            0x3627D42F87E23335ULL, 0x59D8AA33513020EDULL, 0x24C88B25CD4EC916ULL, 0x78A7DA58A3885D07ULL, 
            0xC19B8793721082F9ULL, 0xFC23AE71256AA5E7ULL, 0xF0FD6665ADF3C3C8ULL, 0x3915076ABE4CEEF3ULL, 
            0x01BE3DB1801112FCULL, 0x6C9059CC19F5DD1EULL, 0x530FF70ED57E70F8ULL, 0xB085A31BE8FC6333ULL, 
            0x6028413C82197140ULL, 0x295E5206BD4810DDULL, 0xFBA736ED21DAE00BULL, 0x47AEB5E71405A793ULL, 
            0xB28B20B71BDA3701ULL, 0x2D3D69458C5DC5ACULL, 0xBDE518F712953A9DULL, 0x2A50C510CF3647ECULL
        },
        {
            0x0B00ECCC39C29CD8ULL, 0x9405BDC1D6CD771EULL, 0xE37B3EB59CE0B106ULL, 0x954FBF0E6830707CULL, 
            0x544747C1A0F6A9C3ULL, 0x63E2BF63E3438154ULL, 0x578A511E0CDDFA5EULL, 0x26A3E0C928A29C07ULL, 
            0x41B0063CE3D922FEULL, 0x7B6D1BE65F627862ULL, 0xC5D3942670857D8FULL, 0x925039AEEC767FF9ULL, 
            0xE7DDC8E5679BC845ULL, 0x4DEC0EED306BEC9CULL, 0x6D5F790B15A47457ULL, 0xA6E08592133B8EE4ULL, 
            0xB9322C64F2D6B62DULL, 0xA68F35BCF05054C0ULL, 0x637002BC747A9597ULL, 0x82D00174ADD697F0ULL, 
            0x3151EFEEC8F6FDADULL, 0x073F8E1F6B9A3AA8ULL, 0xE4EE1E6F39FD6AF3ULL, 0x98DDE82DD72CD637ULL, 
            0x29E582543AFD356FULL, 0x08BF109ED289E454ULL, 0x73ACF09E663064E2ULL, 0x892189577105C09AULL, 
            0x5F31F9C34A964CE5ULL, 0x81ABB4B0D7372CFFULL, 0xE0AC03A40F67732CULL, 0xACEAD4D48C66589FULL
        },
        {
            0xEA727028E5030713ULL, 0xE070D29C06541178ULL, 0x99BEBF61A4DE7D25ULL, 0x88D4E5018D774A9FULL, 
            0x408E1A746443696DULL, 0x3793625B0857AA5CULL, 0x57D99F8EDBE6DBFAULL, 0x718C4DE4ECABB233ULL, 
            0x115FF4BAFDF8C800ULL, 0x4CC775A2C5294613ULL, 0x535EFCAA0F3CC1EEULL, 0x3AF1B002847B973BULL, 
            0x2A95915432389D45ULL, 0xEEC114AC2F4CAD12ULL, 0xAE4DA776C64856F0ULL, 0x3A080206F874DCDBULL, 
            0xC3B8EBFCE75656D9ULL, 0x6267F7C11633CA8DULL, 0xA5276F30D5DA4D3CULL, 0x464237287CD436DBULL, 
            0x95926DC143E6C7CAULL, 0xE881D7F5D0D72650ULL, 0x167B08DD27659578ULL, 0xFABD6D20549A491BULL, 
            0x92D8346D2583B28EULL, 0xA190A56790BE81E2ULL, 0x94F4B37CEEC58938ULL, 0xD94787E4746211C8ULL, 
            0x6B2C8C8FC6FFA173ULL, 0xB0E35336F1B22038ULL, 0xE3EFCAAF04A34F0BULL, 0x0520595F11B99CF9ULL
        },
        {
            0x749AEF75D6CAF7D6ULL, 0xA7A932DEA9556183ULL, 0xEED08611A9C21BABULL, 0x2733A88670F788C0ULL, 
            0x184FE871B427ED7FULL, 0xEC1B425423B88FBCULL, 0x101642AA1A8C0C6BULL, 0x26C8F5A79EC85540ULL, 
            0xE691D2AB319BE264ULL, 0xEF1A7EA76D24738CULL, 0xC639839B9505D431ULL, 0x1397CA741080B31FULL, 
            0x1E512DDA5C90169AULL, 0x31C454B228B87D09ULL, 0xE0354C70B5AB2CBEULL, 0xC27FEAFCBF00F171ULL, 
            0xFD7EA8CE8CE3DD84ULL, 0x669F49A418E6FC97ULL, 0x134619436C06EBA9ULL, 0xFB740E9FF5D3DE37ULL, 
            0x4476C27F73A6B37CULL, 0x7B011613312D1EF3ULL, 0x4F0DA60BC2F46266ULL, 0x5B78FC8878A143EBULL, 
            0x880268D70A1D8B4AULL, 0x2652CF00F58B2BC0ULL, 0x8C4176F234684270ULL, 0x2A329E551202DC8EULL, 
            0x2C4A9A83BDF71822ULL, 0x19F57439FAC7F415ULL, 0xC2BC4EEA328164C3ULL, 0xCC7DDCBE049A1D68ULL
        }
    },
    {
        {
            0xEF9375D64189A07EULL, 0xA711E8DEA65AF7A2ULL, 0xF5026D1FD9ADFF5BULL, 0x915D70BA83AB0341ULL, 
            0x91DC67DAA1EAA1F0ULL, 0x8046A9B08732A388ULL, 0x45F713377EC4CCB3ULL, 0x6B8A06C5C0FBADACULL, 
            0x1B04E64A7328018AULL, 0xFB9E982E8E92A40EULL, 0xAA1AEA84EEBA7FBFULL, 0xF6EBCAD9C43A1884ULL, 
            0x88CE1ADC8C4F9D59ULL, 0xDA63BF12CAB92E47ULL, 0x4601C1C357D4C317ULL, 0x12C260FDC7F2BC15ULL, 
            0x0899324F0D662C75ULL, 0x989AFC01E219A656ULL, 0x2072357A24EC6B14ULL, 0x4ABA80F5C4BDB329ULL, 
            0x1B9EC7606B0E25C2ULL, 0xC4E747609728BC0EULL, 0x096D4249AF6634EFULL, 0xED3486D669512EFDULL, 
            0xA2FAE034211CA1EDULL, 0x3824B277E4FA61E0ULL, 0x6152108814CCF674ULL, 0x62DEE452D73EE082ULL, 
            0x3595880604175A3BULL, 0x4E10B2F1E6B18134ULL, 0xA38F896001136823ULL, 0x3977E113E235446EULL
        },
        {
            0x6F5977E4938AB514ULL, 0x910D6762CE09FEE2ULL, 0x7882B7ABA041E2D7ULL, 0x58D15045A888D42DULL, 
            0x5C483692EC4D32DEULL, 0x799D89AD4C6F172AULL, 0x4E977638E9813891ULL, 0x1B87593049CE2E37ULL, 
            0x27DDA6739D82FEA8ULL, 0xD29FA4540A748F9CULL, 0x66282551CDAFD583ULL, 0xC3256B00FCE6DE93ULL, 
            0x167AA0451C25C370ULL, 0x39A0C0BC497CBBCBULL, 0x69826065E183C8E7ULL, 0x273508840D13B379ULL, 
            0xEAA9694419D228BEULL, 0x9CDE8519E49E2AE1ULL, 0xF1AB684E854BB3A2ULL, 0x48B744165E2B0867ULL, 
            0x28D18C2A3D7A0718ULL, 0x93805206DA9DC224ULL, 0xD0BD9AE4B18EB0C7ULL, 0x23E9AB1E68B7285AULL, 
            0xF14650F1D0CAFD73ULL, 0x6224BDD40FB872FFULL, 0x540044D5532AC55BULL, 0x4749E1B0FA29BF1CULL, 
            0x8EDF8EF2CB747FF8ULL, 0x960CC9043D6E0635ULL, 0x3D797074560F2CB5ULL, 0x13A9A89691A42FA5ULL
        },
        {
            0xDF374F3FE7919FCAULL, 0x6F5D4B402B47F56BULL, 0xB1F9BCED602AD4CAULL, 0x91E87B944487D40EULL, 
            0xDA5328B251CFA035ULL, 0xD0933AC618ABC00EULL, 0x0FAEC79A238FCE6FULL, 0x5224F5BB2681514AULL, 
            0xFA2BC98F533662D4ULL, 0xDB7FD0872ACCA4EEULL, 0x3193A28D687FFC90ULL, 0x45931895D2F5BF83ULL, 
            0x0FF3034C1C3C74ECULL, 0x8CBBE58D49DFCEAEULL, 0x6B922DC56EF6A32DULL, 0xAE9D35C956B06667ULL, 
            0x13499FF6538B343CULL, 0xD89C7846F9CC03C7ULL, 0x0C22342ECEC6FE91ULL, 0x811C7B9EF954205BULL, 
            0xE07FF645DA9D609BULL, 0x47E2AD8E0888E371ULL, 0x6066495ACDAF9202ULL, 0x5A6F5F4077D4B45FULL, 
            0x1D02D972223A54BBULL, 0x5F6DFD9F90D62E31ULL, 0x4C767EE121956A89ULL, 0x35676BA57C9BCD15ULL, 
            0x26DE72303EF244B3ULL, 0x1CF4C6F8997F3A75ULL, 0xB6CE3567C87CDA43ULL, 0x00AAEFFBCD114577ULL
        },
        {
            0x25833B32FDDA5839ULL, 0xA65DD9FE50B8FE8FULL, 0x58CCBCE2D2029C0FULL, 0xC2C4255B39E5B82CULL, 
            0x1F38E13408A0D999ULL, 0x88B95BB29F5EB957ULL, 0x543589829E912119ULL, 0xE49F2FB2B899C91AULL, 
            0x4491AB6753FAC599ULL, 0x1BEA6EF03040B95EULL, 0xFEBEAC3D965555ECULL, 0xC7548BDFC93FB795ULL, 
            0xF8AF48C3A3B7445FULL, 0x9FC48A7475220DF1ULL, 0xB94470D84BBFC1C0ULL, 0x0F09AEDD1303A9B7ULL, 
            0x1542A244BE12753DULL, 0xA8E90484CBE3DDF0ULL, 0x1AB17460B91BB904ULL, 0xBA7C3B68A1CA8124ULL, 
            0x770E774D0AF4BB7EULL, 0xC708EA3E5EC4248FULL, 0x92AA7CEF66987681ULL, 0x13817174201157B0ULL, 
            0xE7B7DD7A489A6E73ULL, 0x2429176E9612B171ULL, 0xDE885DCBA102E00AULL, 0x2525C34BF49FE539ULL, 
            0x64E07CD8E825C97AULL, 0x82425A0EEEF5654BULL, 0x2B108B94C49E16D8ULL, 0x358F5F9B3C2B8AFEULL
        },
        {
            0x6A01450053FAB79AULL, 0x61090EB0C6B2C032ULL, 0xFE4403EA40E423EAULL, 0xF5ACA5D6231F091DULL, 
            0xB12C295B64757FEAULL, 0x575BA4F69618DBE2ULL, 0xE46B5CB54122CC20ULL, 0xD36676CE9BC0F4FFULL, 
            0xCC495CA5AF04AF17ULL, 0x15B8ADD55E32C823ULL, 0x3175E51D1873668AULL, 0x5E7A694BAE293E4EULL, 
            0xF142AEAFF33525B0ULL, 0x75B89E7BB8DEFB15ULL, 0xD69BCF46FC1BE919ULL, 0xE3667608AAEF2323ULL, 
            0x4D2A29605BD029ABULL, 0x0DD0221E687518F6ULL, 0xAF62FAC561C122ECULL, 0x1821A3D5796ACA3FULL, 
            0x506F20ADC6056FE2ULL, 0x4041E9C27CFD2811ULL, 0x555DEFDA26BB8FBBULL, 0xDD01E0C82D23FBF0ULL, 
            0x32EF14BD1227161FULL, 0xAE5E340D1FB81CE6ULL, 0x97E05007D1DF3580ULL, 0x6E300A240FD730C1ULL, 
            0x6D975BBC8CA8E2B4ULL, 0x891BD640F892B32FULL, 0x4295A3013D60B11CULL, 0x40F8410DF2C5CA19ULL
        },
        {
            0x9A2E89B193F84A0CULL, 0x1AE40796EFE8EBA5ULL, 0x683FFE8917DFD7B7ULL, 0x0633F39CE08149FDULL, 
            0x2421CF561D8C50A4ULL, 0x7F0AC37E400FE2D0ULL, 0x68B9B128B677E1FBULL, 0x1DF8C9208153D471ULL, 
            0x3F09C2AF1B0FAA15ULL, 0x2C727388463D48F5ULL, 0x09ABE1578332291FULL, 0x6A95CCF84DA2C39DULL, 
            0xBABD6085A6CA97F3ULL, 0x5C7B3BEC55EE72C3ULL, 0x338A4CAEFA9A63B0ULL, 0xEBA99C32D1DE01F4ULL, 
            0x9AF14D4CEB597DD8ULL, 0x6CC96D2EDFC43D0EULL, 0x10CCCE11476E7F80ULL, 0xADB9152873BA114EULL, 
            0xD7D4386DD1B57B19ULL, 0xE16B1BA50FB22584ULL, 0xFC5EDA5967583098ULL, 0x7955235F66D5CD4CULL, 
            0xF678C50F53C4A4DDULL, 0xC8571D31B8542B5CULL, 0x0E334818D323F39DULL, 0x61C9CAEEF34A0253ULL, 
            0x71E103608B469572ULL, 0x973F4AEEA12D4175ULL, 0x5CE9AAB89CD0EF55ULL, 0x821E5464ACB7E539ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Capella::kTwistConstants = {
    0x72427306D0DC0918ULL,
    0x8F0D2E77B8CE2CFFULL,
    0x1A4A02C50C295C01ULL,
    0x72427306D0DC0918ULL,
    0x8F0D2E77B8CE2CFFULL,
    0x1A4A02C50C295C01ULL,
    0xE9FA8669906D8E1BULL,
    0x87164A34E4581C52ULL,
    0xD5,
    0xE0,
    0xE9,
    0x56,
    0x31,
    0xF1,
    0x43,
    0x8B
};

