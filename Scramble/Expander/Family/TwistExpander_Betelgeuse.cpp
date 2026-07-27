#include "TwistExpander_Betelgeuse.hpp"
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

TwistExpander_Betelgeuse::TwistExpander_Betelgeuse()
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

void TwistExpander_Betelgeuse::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA8BF3EE8D5D46ED3ULL; std::uint64_t aIngress = 0xBC3E50F11AB9F0CEULL; std::uint64_t aCarry = 0xA8926509DC5EFCF6ULL;

    std::uint64_t aWandererA = 0xD414E762646B4125ULL; std::uint64_t aWandererB = 0xE64E7348D1E9943BULL; std::uint64_t aWandererC = 0xA5A88FE298B38CE5ULL; std::uint64_t aWandererD = 0xE7C495ED5A0778F2ULL;
    std::uint64_t aWandererE = 0xEE2FD916A78D083DULL; std::uint64_t aWandererF = 0xF13131FFA3C76245ULL; std::uint64_t aWandererG = 0xDD0EED90EF460A7EULL; std::uint64_t aWandererH = 0xF009FF7D949CFB87ULL;
    std::uint64_t aWandererI = 0x99079F7408E9D82EULL; std::uint64_t aWandererJ = 0xF8C44BB2BD938A40ULL; std::uint64_t aWandererK = 0xE0B05B4F9F970725ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xDB9A4BAA09B4FC7FULL;
        aCarry = 0x9136CE219FD1EE52ULL;
        aWandererA = 0xF00975D1288CAFC8ULL;
        aWandererB = 0xC6783F005C902080ULL;
        aWandererC = 0x98C7DFD425523232ULL;
        aWandererD = 0x87C6D42EF486C0D9ULL;
        aWandererE = 0xC7247A4D8F264F4DULL;
        aWandererF = 0xFB76F3169EFC52DBULL;
        aWandererG = 0xB73C4ADFF4370B48ULL;
        aWandererH = 0xDA8F46F84B9B50AFULL;
        aWandererI = 0xC6192517F3F7C79BULL;
        aWandererJ = 0xCFC30D4A0F736AF7ULL;
        aWandererK = 0x9156602F193CEB84ULL;
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
    std::uint64_t aPrevious = 0xC4B52499EB5754DDULL; std::uint64_t aIngress = 0xD7FDA88F271F3E7DULL; std::uint64_t aCarry = 0xEDDAF62F21FA308CULL;

    std::uint64_t aWandererA = 0xD887B4D9AEBD6BFFULL; std::uint64_t aWandererB = 0xEB0A1B0FD3408471ULL; std::uint64_t aWandererC = 0x8B3077EDB66612CFULL; std::uint64_t aWandererD = 0xCD1B5475F53E6322ULL;
    std::uint64_t aWandererE = 0x9CB1201570031B3CULL; std::uint64_t aWandererF = 0xD49CBD2FA3D15CBDULL; std::uint64_t aWandererG = 0xE26214BDFE8A95D7ULL; std::uint64_t aWandererH = 0xCEE7E0D84599F91FULL;
    std::uint64_t aWandererI = 0xE49F72905C0DA71EULL; std::uint64_t aWandererJ = 0xDF6D9858B08AD99FULL; std::uint64_t aWandererK = 0xED2999424A88958AULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xF636A666493E7D89ULL;
        aCarry = 0xA3722008583D6538ULL;
        aWandererA = 0xB37EC1B409DF404AULL;
        aWandererB = 0xA8DBE4904B22B3CCULL;
        aWandererC = 0xA9846DFD6B8E1B7DULL;
        aWandererD = 0x930F27DE03FE9D88ULL;
        aWandererE = 0xE66A9007FA0C48DCULL;
        aWandererF = 0xE7ED21263B578DA7ULL;
        aWandererG = 0x99821FBBD74B5346ULL;
        aWandererH = 0xFB3A46EFD0F16480ULL;
        aWandererI = 0xCAF92B50E54EED67ULL;
        aWandererJ = 0xF1D56F2C92A879EDULL;
        aWandererK = 0xFAFEF78125299416ULL;
    TwistExpander_Betelgeuse_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Betelgeuse::KDF_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xE3C03E28D6497C03ULL; std::uint64_t aIngress = 0xFEAEDD421DB6A434ULL; std::uint64_t aCarry = 0x97107FDA7B3F83A2ULL;

    std::uint64_t aWandererA = 0xBB5B1FC8D30105ADULL; std::uint64_t aWandererB = 0xC40835776F9C3B30ULL; std::uint64_t aWandererC = 0xE720C90E2FF8CA43ULL; std::uint64_t aWandererD = 0x9EE9F3A604C6CDA7ULL;
    std::uint64_t aWandererE = 0x865D96CF74610DFAULL; std::uint64_t aWandererF = 0xBE38FDDB65EBEC1DULL; std::uint64_t aWandererG = 0xFE9E80D4E5161CA7ULL; std::uint64_t aWandererH = 0xF741123ED0669E84ULL;
    std::uint64_t aWandererI = 0x9D6ECABCCC977620ULL; std::uint64_t aWandererJ = 0xA99AC6A6EA20D185ULL; std::uint64_t aWandererK = 0xFC370D696BBB7126ULL;

    // [kdf-c]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x81F306049EC9A43FULL;
        aCarry = 0x89F745A1A4C55868ULL;
        aWandererA = 0x91C7880DB6F25FDEULL;
        aWandererB = 0xEFC6545F816BFDFEULL;
        aWandererC = 0xE86D4FC474C1B74DULL;
        aWandererD = 0xD665C38164F5A80DULL;
        aWandererE = 0xE1413F7D59193CE0ULL;
        aWandererF = 0xCD322E7DE8FFD911ULL;
        aWandererG = 0xDD43448502BB7E01ULL;
        aWandererH = 0xAE4C17B3F7B595D7ULL;
        aWandererI = 0xE7AC921F0B76BD15ULL;
        aWandererJ = 0xA506536CF2FF0ABEULL;
        aWandererK = 0x847A51B9E7FDAF77ULL;
    TwistExpander_Betelgeuse_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Betelgeuse::KDF_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xFBA35B0C612DF267ULL; std::uint64_t aIngress = 0xC7010CA680F2372EULL; std::uint64_t aCarry = 0x902C7FCB12629DE8ULL;

    std::uint64_t aWandererA = 0xF2E375C3612EB97CULL; std::uint64_t aWandererB = 0x9873531D7249276DULL; std::uint64_t aWandererC = 0xE7383E53B661B1FCULL; std::uint64_t aWandererD = 0xBF950FDF16F60CC0ULL;
    std::uint64_t aWandererE = 0xE21DC74A62A9B185ULL; std::uint64_t aWandererF = 0xD43A26EBC128DFA8ULL; std::uint64_t aWandererG = 0xDAA20E41ED503897ULL; std::uint64_t aWandererH = 0xB332358B8DE2B8DEULL;
    std::uint64_t aWandererI = 0xD73EC006D97C78D5ULL; std::uint64_t aWandererJ = 0x992FD186C36CB60DULL; std::uint64_t aWandererK = 0xF4373FA5A8E76404ULL;

    // [kdf-d]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xAD2450CC82219321ULL;
        aCarry = 0x81BB88C4CB6D8694ULL;
        aWandererA = 0x8574DBEEE619B08BULL;
        aWandererB = 0x912FD7969D9213EFULL;
        aWandererC = 0xA54F0E7F4641EEA9ULL;
        aWandererD = 0xD278AD27AD350781ULL;
        aWandererE = 0xD07911DB9FEE459EULL;
        aWandererF = 0xC7C8E43ED4DFAD55ULL;
        aWandererG = 0x9EBF6387F922CD6AULL;
        aWandererH = 0xC91C4D90836BB971ULL;
        aWandererI = 0xC1C3161FBEC3ED7FULL;
        aWandererJ = 0xC247CC9CF863388EULL;
        aWandererK = 0xDF70F11EA9DA5416ULL;
    TwistExpander_Betelgeuse_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::KDF_D_D(pWorkSpace,
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
    std::uint64_t aPrevious = 0xB143FFC9C8E61D1DULL;
    std::uint64_t aIngress = 0xC419F7E1406CF897ULL;
    std::uint64_t aCarry = 0xF7B507685631AB61ULL;

    std::uint64_t aWandererA = 0xA52A8BBAD2E270B5ULL;
    std::uint64_t aWandererB = 0xC0EC991C47CBAFDAULL;
    std::uint64_t aWandererC = 0xCA5277CCA2CF5932ULL;
    std::uint64_t aWandererD = 0xFDEEA6E5A891CEB6ULL;
    std::uint64_t aWandererE = 0x8FF139C9E9930E2DULL;
    std::uint64_t aWandererF = 0x9CC0DE0AE9D18BA0ULL;
    std::uint64_t aWandererG = 0x81B03B81192820E6ULL;
    std::uint64_t aWandererH = 0x8F01EB88ED1AFA99ULL;
    std::uint64_t aWandererI = 0xDCFF5B07BAA4FC94ULL;
    std::uint64_t aWandererJ = 0x8C3CE648F6A03BD6ULL;
    std::uint64_t aWandererK = 0xA15AA83B610EC6C4ULL;

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
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnConstants), &(mDomainBundleInbuilt.mKeySpawnSalts), pSnowLaneC);
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
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnConstants), &(mDomainBundleEphemeral.mKeySpawnSalts), pSnowLaneC);
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
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnConstants), &(mDomainBundleEphemeral.mKeySpawnSalts), pSnowLaneC);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnConstants), &(mDomainBundleEphemeral.mKeySpawnSalts), pSnowLaneC);
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
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneD);
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
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneD);
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
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneD);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneD);
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
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneA);
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
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneA);
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
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneA);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneA);
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

    TwistExpander_Betelgeuse_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::Seed_J(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::Seed_K(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::Seed_L(pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::Seed_M(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::Seed_N(pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::KEY(pWorkSpace,
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

void TwistExpander_Betelgeuse::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x84DA92712200A1BFULL; std::uint64_t aIngress = 0xA6161C2415C1C6EFULL; std::uint64_t aCarry = 0xE99F28ED7716B6C2ULL;

    std::uint64_t aWandererA = 0xEE777B1DC43335FCULL; std::uint64_t aWandererB = 0x8F59A48C6BBD7740ULL; std::uint64_t aWandererC = 0xE2C91A98CADCEB75ULL; std::uint64_t aWandererD = 0xE4DCFB0BC4CBEA61ULL;
    std::uint64_t aWandererE = 0xFF08683E56367BA6ULL; std::uint64_t aWandererF = 0xBCC30850BF046E53ULL; std::uint64_t aWandererG = 0xD5AAD44C50FC59C2ULL; std::uint64_t aWandererH = 0x9E91A95B95AA6B04ULL;
    std::uint64_t aWandererI = 0xC5D61C46AB6D027BULL; std::uint64_t aWandererJ = 0xB7EB6F0D723541ECULL; std::uint64_t aWandererK = 0xD012A8C414E1FAF6ULL;

    // [twist]
        aPrevious = 0x9C36EF2726074864ULL;
        aCarry = 0xE87A08EE7ED02C4EULL;
        aWandererA = 0x9A10DFE76CCB0DEEULL;
        aWandererB = 0x97D34E49A8F12885ULL;
        aWandererC = 0xC2E0C7755E2902C1ULL;
        aWandererD = 0xCC9BF18965B4C6DDULL;
        aWandererE = 0xC5C4FA988D368294ULL;
        aWandererF = 0x856052D8690E8EEAULL;
        aWandererG = 0xD2E203141996EF52ULL;
        aWandererH = 0x95676DD25E7C2BA8ULL;
        aWandererI = 0xB50891BED1BEE1DEULL;
        aWandererJ = 0xF6D27E674AA593F5ULL;
        aWandererK = 0x952A0F119B172E00ULL;
    TwistExpander_Betelgeuse_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::Twist_E(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::Twist_F(pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::Twist_G(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::Twist_H(pWorkSpace,
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

void TwistExpander_Betelgeuse::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Betelgeuse::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Betelgeuse_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Betelgeuse_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Betelgeuse::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 13 of 33
    // Exploration cases: 0
    // Structural maximin 524 / 674; family total 6471
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
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4008U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 47U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3648U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3828U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1465U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1330U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1870U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1735U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1510U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 47U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1555U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 2005U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1780U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 13 of 33
    // Exploration cases: 0
    // Structural maximin 524 / 674; family total 6452
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
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7159U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3288U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3198U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7339U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 430U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 745U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 610U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1060U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 520U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 925U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1015U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 700U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 475U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 655U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldSeedControl candidate 13 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1067 / 1248; total 13018
void TwistExpander_Betelgeuse::FoldSeed(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 858U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1488U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 93U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1916U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1938U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1443U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 633U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1691U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1083U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 813U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 408U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1646U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 768U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 543U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1128U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2028U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1623U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1533U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 903U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1308U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1758U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 295U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 70U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 678U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 115U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 588U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2006U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1218U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1803U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 723U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1353U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 228U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneH[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 948U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1893U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1781U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1263U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 993U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 138U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 498U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 250U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
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
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 385U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 160U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1848U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1398U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneK[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1578U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1038U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 340U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1713U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1668U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 48U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 453U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 318U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1961U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1871U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 183U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneN[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 363U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1983U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 205U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 273U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1736U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1173U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 25U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1826U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldTwistControl candidate 13 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1067 / 1248; total 12965
void TwistExpander_Betelgeuse::FoldTwist(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 836U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 859U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 341U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 71U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1286U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1556U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 746U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1084U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1466U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 431U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 386U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1511U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1399U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 116U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 476U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1714U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1984U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1241U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1061U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1151U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1354U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1759U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 881U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 521U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1106U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1016U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1849U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 161U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneG[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1579U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 611U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1444U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1939U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneH[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 791U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 206U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 814U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 566U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 26U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1376U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1894U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1331U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneJ[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1669U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1534U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1309U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 949U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneK[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1601U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1489U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 296U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1624U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 971U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 926U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1039U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1174U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1264U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 701U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 251U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1219U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneN[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1196U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1804U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 994U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1129U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1421U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 656U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 904U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2029U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Betelgeuse::kKeyRotateSalts = {
    {
        {
            0x618E94D6229D0C29ULL, 0xF40117D9BCAC8A0FULL, 0x8C04B7F32C9D02F7ULL, 0x71F5BF93813DCED8ULL, 
            0xBDA76875AD1B3708ULL, 0x6CA012BFFF0381B9ULL, 0x917A0C0476825960ULL, 0xF4A8482F74D95092ULL, 
            0x82DEB48DDE2E4862ULL, 0xEB516FFCB0E6979EULL, 0x0F78C67AC36ADA4EULL, 0xC24C22C7758A7B22ULL, 
            0xD7E79EC8B374AB4DULL, 0xD4BB558666C1FF73ULL, 0x2ED8CF9D249B9621ULL, 0x61B75D4B3AA8F227ULL, 
            0x2C852F9E7D6357E5ULL, 0xB420682BC0A822ECULL, 0x5E32F780993908A2ULL, 0xFD14E64E97285310ULL, 
            0x98CD3B9296C24414ULL, 0xE09490F7DD79CCB1ULL, 0x4CAD815C3904883EULL, 0x12DFCF05642FF366ULL, 
            0x876D96B959407665ULL, 0xD1CBA43C42C39E4DULL, 0x22B0C93F5AACD848ULL, 0xE2984B3E273A2254ULL, 
            0x0CCBCE1BA6A6B0A4ULL, 0xC2552FCE503C0F49ULL, 0xBB09AC2D4FC1BCDBULL, 0xA89EFB4CF86F4E6BULL
        },
        {
            0x2948CFF65026D7DEULL, 0x669E578E7A650258ULL, 0x54502731175230D5ULL, 0x13298DAF892AFA4FULL, 
            0x8C2A9B457E9D2491ULL, 0xDF24C0CFA001668AULL, 0xB5F1BF8D5C169CBFULL, 0x8419FF3DD14351A7ULL, 
            0x434852BEBD6C0046ULL, 0x57030BFB81B1242AULL, 0xB1900EEBFC790661ULL, 0xFFCF86E9DA0C2A14ULL, 
            0xEF640E65CAA7F090ULL, 0xD595193F1356C8B0ULL, 0x4EEB57D402B9AEC3ULL, 0x2303ED1AFA0BA42FULL, 
            0x88E9C48E51DDF33EULL, 0xC06EA46ECA4BC3AAULL, 0xBD16442489B1CBE9ULL, 0x5A5B953909E52ABFULL, 
            0xDED79054CD57C8F3ULL, 0xA23B96EFDC8EA6B3ULL, 0x5B6E109B06986C0AULL, 0x081731CB544C977EULL, 
            0x7413C51C301D608EULL, 0xC5CDEBFC41C28C17ULL, 0xF67C53C9F52C9518ULL, 0x43A260FCB20E461FULL, 
            0x681A50D2FB86CE97ULL, 0x44509E4542BB01B0ULL, 0xEBD2855E3223F6B0ULL, 0x76980DAA7F141880ULL
        },
        {
            0x53DBB9EF7A8CF502ULL, 0xA9BF38EFDE1F225BULL, 0x393930F73731C45EULL, 0x02B19CE342FA6A88ULL, 
            0xAC0DF5084089B4D2ULL, 0x8895600138052701ULL, 0xF94C925017209AEDULL, 0x7BFC214AA0BF7878ULL, 
            0x4791A3D11A3A1555ULL, 0xCEA28FB718DD1C6CULL, 0xAE2B50AEFF2EA794ULL, 0xA97FEA5ED0E14462ULL, 
            0x61D28EA226DC4E43ULL, 0xB30C1F0E0B049A97ULL, 0x8FE1AE360C27C550ULL, 0xEA6A7D983347C2F6ULL, 
            0xDEEE7CA7211510A1ULL, 0x75795355E47FE2B9ULL, 0x9C23B7B46F4D016EULL, 0x418703221110C4F5ULL, 
            0x1093204E45B36391ULL, 0xB933ACC17B2C3836ULL, 0x104BC124F7299B6BULL, 0x45346070E4806BBEULL, 
            0x83C0C4A5652A43F7ULL, 0x24C11F199536D6BBULL, 0x8CD12A0550CEB1B9ULL, 0x54FECD605CF971E2ULL, 
            0xA00295F5A6106CB3ULL, 0x085B7F8181195EFFULL, 0xA2743D30C16929EEULL, 0x0E536D80CBABA015ULL
        },
        {
            0xE9DDF1D06B632DE3ULL, 0x43C9F017E4554E69ULL, 0x4A013AF12D9C25F1ULL, 0xEAD20113120B0D50ULL, 
            0x1BB2250D090B2EB4ULL, 0x6EB0E8747BD159AAULL, 0x57107F5920C43B05ULL, 0x74325F835B5CB363ULL, 
            0x6E5D3E0F837B857DULL, 0x46A0C11A15E6815CULL, 0x53B013AF5A227C6AULL, 0x0B69984F3A2A0407ULL, 
            0xD8F672A83396D93DULL, 0xE2ED897EBB0A8E36ULL, 0xD7D5702B3A7EB366ULL, 0xAA677651F19E949DULL, 
            0x00F2A79D6C577809ULL, 0x55C9204EF08DAC35ULL, 0x1C09C0E09E35EFE2ULL, 0x992DE0FD913B44B8ULL, 
            0x4907BAD18A3A1E02ULL, 0xC6867336FA78F63BULL, 0x8199CAE27857924DULL, 0x67865982E530AE79ULL, 
            0x42884C77AFC2741DULL, 0x073D85A076EE3ACEULL, 0xDD6E58BD8077E4E4ULL, 0xB6D4C94F7FF8B28EULL, 
            0x045F93DAF26DF552ULL, 0x2FEF5D8B9DBDD5DCULL, 0xDD1BD3AC406064C8ULL, 0x408C1B6F9E747F6BULL
        },
        {
            0xF3DD6FF072E26364ULL, 0x8829E40FF28EFF9CULL, 0xE4369310DFEF6554ULL, 0xFA308B10557381E0ULL, 
            0xCE42143B29CDC415ULL, 0x021E422EBB1EEB74ULL, 0x4C69007687208DEDULL, 0x57F39D71E57C8D0BULL, 
            0x72E5A539E0891D66ULL, 0x4DFD8992B5271CE8ULL, 0x4C5D753D0A07B166ULL, 0xADBD5AE4F93FE79EULL, 
            0xFE99B6ABF81E5F23ULL, 0x58B5F6622668B90CULL, 0x73A6CB9E127329BFULL, 0xBBA75CB5934852A3ULL, 
            0xC7D9F17D553994FBULL, 0x3E3F738DAE7C2076ULL, 0xFDAE01945D7C435DULL, 0xC4632BCBFEA786AAULL, 
            0x07992D29FA89FE8AULL, 0x93116B8AC39F4F65ULL, 0x4025FE38E7FFB736ULL, 0x8231663E01139909ULL, 
            0xC4B97CE7114440CDULL, 0x718075CE1CE8BE1FULL, 0xBD4BCF2191F906DCULL, 0xDE97F51CE24F94DFULL, 
            0xDE0498C77B99C747ULL, 0x9E69904A4E96CF1CULL, 0x05E694A1D91B03B4ULL, 0x0E172CD748D15C92ULL
        },
        {
            0xAB9937C16C6A2065ULL, 0xEEE0D2B70B0EC181ULL, 0x4D2B46E1A73F20DEULL, 0xD0B1C383410C6517ULL, 
            0xA2F0857DC7940C90ULL, 0xBD1350DD2CF00BE0ULL, 0xFF9A04D198F450B6ULL, 0x89D49CE3CE07085DULL, 
            0x5F436A3F2188EAE5ULL, 0x9DDB3FD1A364E12AULL, 0x65DEBA0193AFB981ULL, 0x5A80D294AB1B1C9BULL, 
            0x4FD99CA989DF403FULL, 0x19E8F39B96966A6BULL, 0x111AD30A6FFB5A72ULL, 0xB23210F66B726364ULL, 
            0x7DF6F3C7EEF7496FULL, 0x41720DE02C683AC6ULL, 0xF87DBC8D866E99D3ULL, 0x13E3553241284FBAULL, 
            0x51705891C4AC10A3ULL, 0xB846F7A12CB9BF33ULL, 0xD432D76B093012E1ULL, 0x95277497DC52A719ULL, 
            0x7211D5D633262131ULL, 0x50BBC46FA68506B3ULL, 0x9CE6628656421631ULL, 0x87AB4F4C7BE6E6D1ULL, 
            0x99D69475B8D462E0ULL, 0xDED5984D26806373ULL, 0x6D190361AF373E73ULL, 0xEBA86458948707B3ULL
        }
    },
    {
        {
            0x92703B3C93DC7711ULL, 0x1C8B8682462D36EFULL, 0x9C91869AE1F75831ULL, 0x87B9ED27F832A782ULL, 
            0xD3F3A70D86340760ULL, 0x6C8D8EEF7FF1337EULL, 0xE8F64C831E6508A4ULL, 0x9B84E8E0EC90C125ULL, 
            0xD8C169392E136D94ULL, 0xD81F8E56B3C58105ULL, 0xF3F311FACD4852E8ULL, 0x0108657D734A00DEULL, 
            0x9A045D10A7AEB122ULL, 0x797C2FF95B0E8DC2ULL, 0xF51051BAFFDB1FF6ULL, 0x40D8F0A246081EDBULL, 
            0x3796DEF11CE2A739ULL, 0x857B5C1DD9863797ULL, 0x3E59AEA4379E4F76ULL, 0x65A8129C45719906ULL, 
            0xF7DC5AF6B609EFA7ULL, 0x0BC0450B6AB76BE1ULL, 0x4DD6AF38FD5666DAULL, 0x0E82E446C58EA962ULL, 
            0x9DF75D87DE8AF3D8ULL, 0xD41B5A86627FA54BULL, 0xD9152A0919731571ULL, 0x48B8884CD02C70B6ULL, 
            0x4F8E43DD09C932BDULL, 0x1C5CCF78EBE1D8D1ULL, 0x73C55D0A95FE000FULL, 0x7BD82E3518643EE1ULL
        },
        {
            0xAC2F553BF5778E5CULL, 0x8EA30BBD5AFE4634ULL, 0x134629B8F78BF3F2ULL, 0x3954F49DD77F6B15ULL, 
            0x1C1A6AEF5282D755ULL, 0x35E2824F371F98E7ULL, 0x8F5A98EB7E84BD80ULL, 0x6E6292B3CC525ECBULL, 
            0x5498AA9B5054AF31ULL, 0x8EE0F66664AA1ACDULL, 0xDFAF9600FA746DD4ULL, 0x512CFF5B4BE79B80ULL, 
            0x010E05CB3DB1E7E0ULL, 0xD4EFCFB81B398278ULL, 0xF7332A4D8412A2FDULL, 0xA1227B6AF6932AB9ULL, 
            0x4823CDAB2ABEFA48ULL, 0x6506B51F091C1E45ULL, 0x0C00FCFE834D8468ULL, 0xBF09A4095AC3A570ULL, 
            0x1AA6BB9FFE643543ULL, 0x3375C0E52F499F16ULL, 0xB54CF058B912F716ULL, 0x57D8025FBA9F828DULL, 
            0x62BA3E82EEA3F987ULL, 0x7733E577B33A53FDULL, 0xE016F145D93C17CFULL, 0xCAE802140EA19BF4ULL, 
            0xA8D33C4E16DCD5F0ULL, 0xCA826EEB87C1E5E5ULL, 0xCAE6DFB17BB95E58ULL, 0x4A57881E2304FCEEULL
        },
        {
            0x6AA07B8771E60FA2ULL, 0xE1268ABB1E2AAB34ULL, 0x6B536949F29A28D9ULL, 0xDFF05A062799616AULL, 
            0x6BF1A5386F224180ULL, 0x860852D39AC19C9FULL, 0x0BECD91ACEC078B9ULL, 0x3A129B13AFFE162BULL, 
            0xAF674E9AA80BF9BDULL, 0xB06B2210D4FD9EA8ULL, 0x3E52366A1C76E62BULL, 0xE07D9941F26C8FCEULL, 
            0x9C2FDD6C5D2C1554ULL, 0x1ED6E9AC27AF8055ULL, 0xC5E9B057EBF57172ULL, 0xF10811FBC60EC065ULL, 
            0xC9176D64D08B6FE5ULL, 0x0BA265C70920CB79ULL, 0x357DCDE29509F21CULL, 0x96181856DAEC1647ULL, 
            0xFAE582B80B5CFF97ULL, 0xACA303DDD72A0367ULL, 0x4E40FD79D241107AULL, 0xB6937E12084323F0ULL, 
            0x09F25707F3276D4BULL, 0x6D29505FED652C84ULL, 0xD74C6ED01D979243ULL, 0x14241B30611215B3ULL, 
            0x223355026F2AE1C0ULL, 0x819C0C5FC0999BB4ULL, 0x1299BCEC8487AC71ULL, 0x22B809606D65578DULL
        },
        {
            0x9FEEE811DE094B3FULL, 0x2CE9E187378F4F45ULL, 0xC84EB16E66C8C751ULL, 0x85AA86DFC10A93FBULL, 
            0x1CF4EE0ECBA2B8F6ULL, 0xE730A2D3699A8074ULL, 0xF87813E147B04543ULL, 0xF915F3306ED9B982ULL, 
            0x512D35E9A57C0D79ULL, 0x05EA1635710FB0EAULL, 0x92FB301500556464ULL, 0x6907EC14E80FC3A0ULL, 
            0x1F4E323EDFC39C52ULL, 0xB06091FD5E08890BULL, 0xC6E077BDA6B12151ULL, 0xA14A3C29ED912D22ULL, 
            0x5C96968EF6D90496ULL, 0xD6585D6479BAFA65ULL, 0x470E38A6C0FD7D0AULL, 0x72A4CB0844D8158DULL, 
            0x557783B33A4D4001ULL, 0x084DF72C579A5179ULL, 0x53275199508F7E2DULL, 0x8F02356512D78EBDULL, 
            0xAAB84CF660336D7DULL, 0x3CD997E4130E7BA9ULL, 0x207AFBF117F67306ULL, 0xA9465595DFFD633AULL, 
            0x4AD9CD22DD7C9CEFULL, 0x89920599F41CF056ULL, 0x2BEA8B27791AA1DBULL, 0x0BD5630FDE659798ULL
        },
        {
            0x8C12EE9643363FB3ULL, 0xA85BF9D02BB6D1F7ULL, 0x08C350A2199972FDULL, 0x875BC1D863B9EE43ULL, 
            0xE1B6AAE21266309FULL, 0x7A6399FA48E40431ULL, 0x41DBDB730991B5DFULL, 0xC3D29D6644CECF8CULL, 
            0x9916B195114B51B9ULL, 0x605BD2EA7BBDE3FFULL, 0x5F653BB6CD94E205ULL, 0x90F8092E41030844ULL, 
            0x8619C04B7703FFD3ULL, 0x84F87513A4A1FE06ULL, 0xA69625357EC09376ULL, 0x20C5974B6D73109EULL, 
            0xD4608C33951476A8ULL, 0x2B6D70E9209290D4ULL, 0xBC17666313B70EC1ULL, 0x60678B238CC56052ULL, 
            0xD8ED7D9C946D572AULL, 0x4E75C107B0285A90ULL, 0xABAA89CD91287C52ULL, 0xDBC3FAF4D8BC0130ULL, 
            0xF525C5CDEE4C9B53ULL, 0x98DB5BC3F06B803AULL, 0x7F2F9EE71AFFD31CULL, 0x8489BC908E5021D6ULL, 
            0xF499B63231C89F85ULL, 0xE7D5C48598B36872ULL, 0x835DE0F3496AA770ULL, 0x30D785DECEA7FAA7ULL
        },
        {
            0x8821FAB53F64B8FBULL, 0x8389C360628F67B2ULL, 0xDFEEE03F4D709A51ULL, 0x98BF2BEE27647235ULL, 
            0xB622E93B7EC462CBULL, 0x4BB65A15C43003ABULL, 0x0584FF9F5B7A7B62ULL, 0x34760628CDCCD965ULL, 
            0xEFF5A6E7AF743348ULL, 0x52FA7DF4E0533A63ULL, 0x8051EC507284A570ULL, 0x22472ED12CA2976EULL, 
            0x9C6CE4E93D798071ULL, 0x8CDFECDA44F80CAFULL, 0xD6C0D622384D3097ULL, 0xFB8DE1CEAA50E8CFULL, 
            0x7E1E97C0F5AF843EULL, 0x8A04D1AB559C9BF3ULL, 0x440B54968B34CDB5ULL, 0xA9868C6F1309E6AFULL, 
            0x9F0C339A19D09C22ULL, 0xCF9A781BB191237DULL, 0xB3E0FD06092C68FEULL, 0xF13D68A5D8CABDCFULL, 
            0x5F5AB3480C7E9D88ULL, 0x430113874F453ECCULL, 0x6A871E490EFEC352ULL, 0x4C204062837519E3ULL, 
            0x0B59D9103905126CULL, 0x219BB77213146174ULL, 0x80453D5DD10641B3ULL, 0x77EE105CACC82E56ULL
        }
    },
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
            0x3B855B8CB129F18AULL, 0x24B7774D4167D39EULL, 0x56401FD9E9528931ULL, 0x901B664068348B33ULL, 
            0x1A0CC0B22E4BEC00ULL, 0xE1701A5153E1CD0FULL, 0x2979E1D4168FCE9CULL, 0x606129DB74568BCDULL, 
            0xBDB64E5C390763EEULL, 0x8BA76D886DC3F58DULL, 0x2367AC5F9B8E8BC7ULL, 0x62E8C8FBF885F22DULL, 
            0x638479EBDC18F8B6ULL, 0x75322DA60617FF62ULL, 0x63D417516359616EULL, 0x2A1A9380F0E7BF2DULL, 
            0xFF889D0A40B76F26ULL, 0x4A77B4B269D92839ULL, 0x1512C1C358C6A5ACULL, 0xDE27773338263AEDULL, 
            0xF5DB68A1424F0D75ULL, 0x84B7DB671E45348CULL, 0xD3C25B16555457B6ULL, 0x75ECFF42454F7AF3ULL, 
            0x90C329CF0A15BFD5ULL, 0xECFCB2D2A2D496CDULL, 0x30AC6F97B85040B3ULL, 0x6A987C35B89FC9B5ULL, 
            0x2BA8C3FE86C6DA95ULL, 0x133D83ED14BC2557ULL, 0xCF9C40F5A42BEA33ULL, 0xC48728A70E369034ULL
        },
        {
            0x74A8C1C4CA9CF8C6ULL, 0x20B03E7CB33CD12FULL, 0x6D051CFBC6CD5494ULL, 0x9EBBC1BFA0C269A1ULL, 
            0x0EA01B0EAAA9F737ULL, 0x5272AB181F9D7F63ULL, 0x45903C1D0C8CA2E6ULL, 0x090B0C2757CA8156ULL, 
            0x30033DC6B7A84557ULL, 0x077B622ED4034117ULL, 0x01D498DC975627AAULL, 0x020CC7C966E3111FULL, 
            0x3F00D818A35D4EF1ULL, 0x756B6E96CFA7185FULL, 0x79BEC925576AC966ULL, 0x53D7E9C261D132FDULL, 
            0x48BC4F5481643CBBULL, 0xA3D54973E71F34DCULL, 0x7C6A08F61778AE12ULL, 0xD7681AC36ADABD76ULL, 
            0x768501399254679BULL, 0x2A9817394B06D223ULL, 0xC9048D1C28B85B4BULL, 0xB051FCC68C527C22ULL, 
            0x6844ABD3BF21C09CULL, 0x54379951D5B94A92ULL, 0xDE84B0D77F966A9FULL, 0x1A685700708222BCULL, 
            0x3B3B76D6ED413238ULL, 0xABAB528800822C18ULL, 0x2AF9089DB72D45F5ULL, 0xF60740536643F373ULL
        },
        {
            0xD1F334CAEA0D98D6ULL, 0xAF6953FA5390668AULL, 0xC63BECDFA11FC7EFULL, 0x35B49707AA707170ULL, 
            0xF778D1ABF1AD1DBFULL, 0xD972BBF834793F4EULL, 0x3703E7B177C22521ULL, 0x5BC0E2C41B65CA4CULL, 
            0x8D50C5C92B55E07AULL, 0x1E77A824790724ACULL, 0x949B1103D533D7D4ULL, 0x915BBFE609CDFDAAULL, 
            0xA0B3A438C5D17651ULL, 0x23DC9232257FDBD6ULL, 0x21297D4D2DBAB89CULL, 0xFCEB58E46DD7BCA4ULL, 
            0x55B69E86E743FEC1ULL, 0xB1CE66077B68904CULL, 0x029948584FDE0086ULL, 0x031984AD68E5DC24ULL, 
            0xA38FA4F9F9606CC5ULL, 0xD1151F82D3BEF02AULL, 0xA0A133CB8DE351CBULL, 0x53C79C8DE22A64E0ULL, 
            0xCCC4FB5610916D40ULL, 0x2AA5606BEE9B4A5BULL, 0xB6B8150E3C308385ULL, 0x166FBFACE5D5D81DULL, 
            0xC6F71BC32573C9E3ULL, 0xC660B2273DD2048CULL, 0x8A6062B74FB6071BULL, 0x67580DFA7AD8F975ULL
        },
        {
            0x199489FF15337BA0ULL, 0xE1903A75D4B56236ULL, 0xC040DCAEF07601FAULL, 0xA85BDD8A3EDBEF6CULL, 
            0xE7607A6EEE29E4A0ULL, 0x975C1925B6C31714ULL, 0x5D5DEDB8D8E81B86ULL, 0x329E146FD5D695A9ULL, 
            0x42763CC322DD7CCCULL, 0x04AD9D8598262264ULL, 0xC6335051DAC085D0ULL, 0xF9904B8EDAFF6264ULL, 
            0xBC2D3E6B684B099BULL, 0x9CC3262A32D751A2ULL, 0x339AEE5F321A4CEEULL, 0x749F13DAA38AA47EULL, 
            0x0A9D334CC40383F3ULL, 0x9D362857E73CFC81ULL, 0x915E8AAF9D6B840DULL, 0xC75EF350883FCF38ULL, 
            0xCB5235285F3B351EULL, 0x6A0DCA5EC2B97E82ULL, 0xCB6FDA7B367C42BCULL, 0x6F3D58D18B756560ULL, 
            0x87DD3CEBCC170FB7ULL, 0xD45FC07D6C2DB959ULL, 0x93D5210BAD9641C9ULL, 0xD2B4CD7AEADB07FBULL, 
            0x9ED452FC6FA0A60CULL, 0x7921BA3062854684ULL, 0x25F4F40A4B628E6AULL, 0xFB43DE8EB52A5B2AULL
        },
        {
            0xBBD15FF054FB2DC6ULL, 0x8F09B439515F972AULL, 0x4D905A8682DA085AULL, 0xBAE13FF6A5EE273EULL, 
            0x9168AC381BFE7C6FULL, 0x0BE9E56A18E8A7BDULL, 0xCA1EA8D546B94A46ULL, 0x92EF1F3C81C7E030ULL, 
            0x72504D279C5DE2E2ULL, 0xCC189D42171486FDULL, 0xFE371188659D4B79ULL, 0x8B01D62B8A5FC226ULL, 
            0x1F8743D0AA20FB51ULL, 0x622FF885FE68700FULL, 0x3A3D41F39F3798BCULL, 0x5C00B12EDC13799DULL, 
            0xE4BFC4EB7BEF4863ULL, 0xCC70F35794E7F6B3ULL, 0x7F924485F2DBC1E4ULL, 0xBFACEDF66CBEF173ULL, 
            0xFF969C70C7108E42ULL, 0xAEF15682EFE2C76AULL, 0x7D3738296A003B19ULL, 0x97433855620721C3ULL, 
            0xAA6D274CD71F4F6DULL, 0x4950A3A7FAE54003ULL, 0x507830D92C3A1C47ULL, 0x8BDEDFFBADF9C405ULL, 
            0x362A9FD6D2C4BE54ULL, 0x2A0C2A804E2D7482ULL, 0xEFAEB45A00326FDCULL, 0x228A7B4708F65FB1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Betelgeuse::kKeyRotateConstants = {
    0x493801AED40846D0ULL,
    0x1AD1DB2108E738DDULL,
    0xD56390926B81498CULL,
    0x493801AED40846D0ULL,
    0x1AD1DB2108E738DDULL,
    0xD56390926B81498CULL,
    0x7C90A206D1D5A2BBULL,
    0xE3018FE1AA6BB43AULL,
    0xF1,
    0x2A,
    0x42,
    0xF4,
    0xAC,
    0xD6,
    0xD1,
    0xBD
};

const TwistDomainSaltSet TwistExpander_Betelgeuse::kKeySpawnSalts = {
    {
        {
            0x834C0707F79EDC74ULL, 0x4799C088C2F547B5ULL, 0x5ECEDB7D4D3D8A68ULL, 0x480B42DE5D8950D4ULL, 
            0x8A12F2A825347EBAULL, 0xAA7C91CA864FC8ABULL, 0x42440CE7EC01AA89ULL, 0x519F83E2654C8FEDULL, 
            0xEBE3C0D7DFB35C3DULL, 0x3E444C8D220FB1ACULL, 0xC9FDA51A51EB49A2ULL, 0x1351AB244F44B9F7ULL, 
            0x5C685C552B053FE3ULL, 0x7F591634A9020A06ULL, 0x3AF2E0CCD5220B28ULL, 0x94FBFC6380376BB0ULL, 
            0xFA19159FEB1B5948ULL, 0x26241CED3B1230CAULL, 0x0FF104217095C83DULL, 0x2B0448452A88A262ULL, 
            0x847A207913C2099CULL, 0xACF591D40BD07B4CULL, 0xDE41CAAFE7AEB7EFULL, 0x4CDE48B443CE92F8ULL, 
            0x21C919AC433F5189ULL, 0xA380F5CDA7B5310FULL, 0x55C5E277D75B0C0EULL, 0x434A0DEFCA1193E6ULL, 
            0xD378A695BAB6CCB0ULL, 0x50AD32626AD74A0AULL, 0x6917D6542D80E35AULL, 0x8EE16754E675BF7AULL
        },
        {
            0x789B3F0005D4283FULL, 0xC830B613ECA0041BULL, 0x5388F41119D676EEULL, 0x34BAD7EF9623109AULL, 
            0xE9445B1264EE3718ULL, 0x38AAF0BD9EF7DB30ULL, 0xBDCD54CAFA719F4DULL, 0x35993673F7A1332FULL, 
            0xF30D094C44E824DAULL, 0x36FD538EB4C9C0CDULL, 0x8D57EEACE6E223C9ULL, 0x6F5E4C7DB27D31B0ULL, 
            0x5780FD59D85C518CULL, 0xCD3EB070CB32CB0CULL, 0x69A77B3F1CC34065ULL, 0x1723F3E9DFAAB963ULL, 
            0x5B80AEE5E894F76CULL, 0x6E758BDEC4A5F1AFULL, 0xEE4B41707F39E27EULL, 0x8D402055826C0794ULL, 
            0x15053A994543A219ULL, 0xE75B50D0AEAF7EFDULL, 0x572D8B8E3B221C6BULL, 0xEFE50AC535AE5CA5ULL, 
            0x52A4C83557F99D52ULL, 0x4265272FF504B265ULL, 0x07FC9A30F701FED7ULL, 0xD0BA53960BBBF238ULL, 
            0x18023041181D0FF3ULL, 0x1D5D04B9333FEA84ULL, 0x920B3006E3B28054ULL, 0x997D1134FB06D575ULL
        },
        {
            0x69FE71CDD1E3BEF2ULL, 0x12457DD04A37376FULL, 0xB3E21FDACD85C507ULL, 0xEDC465C668BDF640ULL, 
            0xA77B886E5848D40CULL, 0x3993762A5591DBF0ULL, 0x72476A4AC6CF94B5ULL, 0xEA6EB9A6B7847A73ULL, 
            0x3CDD908DE7C0676EULL, 0x83A0DF72FFDF5AC4ULL, 0xD560C4686BBBF876ULL, 0x57949E8EA9301D68ULL, 
            0xBAF5E09ABFAD2E02ULL, 0xBB8BF99379B3C5EFULL, 0x7C944F1BAC59F9EDULL, 0xB261C4FE3EF25691ULL, 
            0xF57B8BD37A2DC3BDULL, 0x394F721E7366FECEULL, 0xB11CB2C4A5397FB7ULL, 0x142CF56776CFBE98ULL, 
            0x482642CF25E1DFF0ULL, 0x8EC266165D6EC9E3ULL, 0xE685C86AEF9776C2ULL, 0x9212D8DCB7960E08ULL, 
            0xFE8C3F2B334C96FAULL, 0x9C192505E47FA9B9ULL, 0x8E1297EAF1E966BCULL, 0x3FA730BC4BC36BAAULL, 
            0x53D1E8BF58A52360ULL, 0x0E538D6D981E451FULL, 0x27F56C4215342068ULL, 0xC0A9A615534B7162ULL
        },
        {
            0xA8853ED77AF96609ULL, 0xF96D8C24D8C3D3A1ULL, 0x4F3B7307EEF9838AULL, 0x123D424D589404D2ULL, 
            0x768F0FB9209B4CEFULL, 0x078D9B08E84AA586ULL, 0x2AE1EF11CCE017D4ULL, 0xD8BAFA08CF22083CULL, 
            0xF2FE94E790233898ULL, 0x44EC72E34E75E7FFULL, 0xABAE6C38A4DB0495ULL, 0x3105856B6A0EDC56ULL, 
            0xD3CD811180FB638BULL, 0x38B78098ACE4D80FULL, 0xE0569DA3E99FC665ULL, 0x6792B713CB638409ULL, 
            0xC87E3A916E567F10ULL, 0x2B581254E6FAAAC6ULL, 0x77C5D6FA6DB1C058ULL, 0x0D5057097D4ADEB7ULL, 
            0x3AC95054BAD06054ULL, 0x0EDB7E574F80509CULL, 0x2CDFDAD5A40D69C6ULL, 0xB936B5FB18CE1103ULL, 
            0x2133F1DB0E7395B5ULL, 0x0BFC3E35A069D6B0ULL, 0xDFB1D723A1576B29ULL, 0x6646A7DE05F49075ULL, 
            0x7765730527BB52BCULL, 0x1F92182CF52F9515ULL, 0xE390B9EFDD617703ULL, 0x37AD427EAAB06B42ULL
        },
        {
            0x11965DE98F6897CBULL, 0x217C9D8DAB6918BFULL, 0x37644EB635F81E85ULL, 0x107AC180170E21F9ULL, 
            0x92B1D33F4AB869C2ULL, 0x3C0D4F7ECBFE7BEDULL, 0x9C00B2BD8637559FULL, 0xD47A548C6BD8A375ULL, 
            0xC79DA36BBEBB0EFDULL, 0xCFC77F2FF3C4148DULL, 0xDB4A35A4E0779A39ULL, 0x1FAB292FBEF46379ULL, 
            0xCB6D2F5E7E28FC10ULL, 0x332AC5413D155951ULL, 0x71DB86BD7424AD02ULL, 0xCFF89CCBD0168445ULL, 
            0x39546DC44D9AE5A6ULL, 0xBC37AD1BC2A947EFULL, 0xE3D736BB82D10079ULL, 0x46CA52D2396E0026ULL, 
            0xD18072CA1FB1A905ULL, 0x6CBBAB7F1762DFB6ULL, 0x9D97972859D147A1ULL, 0x63D999CE549D103EULL, 
            0x398DE4FCEE16E9FEULL, 0xD7B4622C7336E8C7ULL, 0x5ADB4DB8D6BEEB8DULL, 0x70B74DCA75DD9528ULL, 
            0xF570ED8A8F20100FULL, 0x47FAD33A08E760A9ULL, 0x3C35143681F1F0D2ULL, 0x07161411DC25A55BULL
        },
        {
            0xAAEAD8C59051D01BULL, 0xC1B3E505CDAED43DULL, 0xDBF6486429A78010ULL, 0x1A3B3505C1EBAB2BULL, 
            0x5BA63CAE9A1AE481ULL, 0x02689D108708F52BULL, 0x8E44D1BF4A255A80ULL, 0xEB06C11573ADEDA6ULL, 
            0x4E3E8813BD236613ULL, 0x5F251D572A921DCAULL, 0x91F417B195346A94ULL, 0xA36C099A0AF976E4ULL, 
            0xDD3A6776C25D25B2ULL, 0xAF1A03AD26C4582FULL, 0xBE1762281D6C70D4ULL, 0x924420A6A33F44C1ULL, 
            0x290A21C4329BA3FBULL, 0x333DAA69F67E1A57ULL, 0xA3058DC209E4C11EULL, 0xD2E4907DE747EE67ULL, 
            0xC06FC373E26B64F9ULL, 0xA259A2117876EDC9ULL, 0xCBF71C7C74B598DBULL, 0x847F08AE7FE0186BULL, 
            0xDFE3B59375011805ULL, 0x8C0DA6BA5E8E8E84ULL, 0x20F0EF8CEC3E597DULL, 0x470CB7DDA156A55FULL, 
            0x3DED5106049A87E5ULL, 0x905D22DC5216EF9AULL, 0x9463A24B8EE6CF32ULL, 0x22B436E5AC869912ULL
        }
    },
    {
        {
            0x85793ED2D7EB703FULL, 0xF2F3D6743B92B0B5ULL, 0x191F75C60C0AB923ULL, 0x9B4650037E44A85CULL, 
            0x2AF157B4D94B5F25ULL, 0x99EC8304C8C00A40ULL, 0xDDA3798A5358ECDDULL, 0x6FD0884E517702F0ULL, 
            0x5FF04F144E36C710ULL, 0x184666F976D2592EULL, 0xC75D4726FDD7BEADULL, 0x29A872BDCC6D118BULL, 
            0x65A39EBCFA43DAA2ULL, 0xA485CE530DFAE547ULL, 0xBD1D7854D9B43574ULL, 0xDA43D5AD673295ACULL, 
            0x61A55AEE5FD73B4BULL, 0xD751832E8E6232E1ULL, 0x0FEE270E1F5566DDULL, 0x3E86B07E7F51E679ULL, 
            0xBCEB288B7899E3CCULL, 0x7AE32D202B5EB211ULL, 0xE5AA8F6979D534C3ULL, 0x729CEF09565842C3ULL, 
            0x77106B143A48B338ULL, 0x60E49E997DA4487BULL, 0x2588317E8AE85225ULL, 0x9E59689F0BC75178ULL, 
            0x8B02A21ABB0D21E8ULL, 0x6FEB60FC6A31D431ULL, 0x5565D81D105E7B13ULL, 0x2826B0E3FCB6C041ULL
        },
        {
            0xF20A6087A2E27DA6ULL, 0x1C832FE1475DB012ULL, 0x19C37DA64E5E5504ULL, 0x03C11735ACD93D4CULL, 
            0xC285FE89197FFA79ULL, 0x80B36E22F267FF68ULL, 0xC70E46513D13DF43ULL, 0x44F47F61516E15DFULL, 
            0x14CEAB5EDA6B95D4ULL, 0x5A10C34CF8ED4940ULL, 0x8BB8F731B5B6DDDBULL, 0xC69AFFB161864DADULL, 
            0xACE18DC6B405DEB6ULL, 0xAD1BC8CD4DCBC3C5ULL, 0x41AFF3D2C3B2A04EULL, 0xE968F3482BA991BCULL, 
            0x66A272A0005573BDULL, 0x017C57EEB02F2258ULL, 0xC2D9367951FA1147ULL, 0xA742BEC7CB200BD0ULL, 
            0x356C6FF009A58C27ULL, 0x7B374F18F7C015F6ULL, 0x1BA8C890069F55BFULL, 0x3D6F9CECF0198AF5ULL, 
            0x0C5DFE13949663C0ULL, 0xB64F6CAE719AB8A2ULL, 0x61A63505B5C75E0BULL, 0xA0FC80C5DCE55A50ULL, 
            0x8668FCAAF8F4BE50ULL, 0x0FF2F1AB9A94CA9EULL, 0x72EF77FDCCA019EEULL, 0xB5078E3C4275C931ULL
        },
        {
            0xDD476281FA978C7EULL, 0x0BADD2F948666A85ULL, 0x89251B61CF7BC269ULL, 0xFBA1DA4792BBE408ULL, 
            0xB3B1DD0E41527158ULL, 0x14FB1BE98855D5FEULL, 0x7A0B80B31DBAB68AULL, 0x0801321B74CFBFD9ULL, 
            0x95619FD201E918A5ULL, 0xD03BDD75168BD19DULL, 0xDF3B71AC0C46BD57ULL, 0x9206A3A3081BF25BULL, 
            0x276C64814291A9D4ULL, 0x890AA89391C2AECEULL, 0x2DE66BE48C92A8B3ULL, 0x1006F33EA96093C6ULL, 
            0x6BA687C722D9182EULL, 0xF094F40CA67388F3ULL, 0xB4175406BB296302ULL, 0x3B44C7F43C633511ULL, 
            0x630C5ECF871D34F4ULL, 0xB3FEB741851C9845ULL, 0xDA745E4C013CCDA9ULL, 0xCBD8DE00AABDEB56ULL, 
            0x977BBB9460C4DB4FULL, 0xF6AABEBEA698305EULL, 0xB2283A4CD0A6056CULL, 0xCF2D7C999F4765B5ULL, 
            0xD1497CFA9D5BECDBULL, 0x460D38D2C4869E88ULL, 0xB75102D851B10BA9ULL, 0x729E33A622A8713EULL
        },
        {
            0x61D74160AF38FCC6ULL, 0xC7F22E9013B05892ULL, 0xE2200F1A15F03732ULL, 0xA5AB0950B1CAFBFCULL, 
            0x26C1C4C437B035DDULL, 0xD56B00DDB413BD50ULL, 0x0B722009D9583333ULL, 0x2BD088DEE975984FULL, 
            0xBBDF2144D5B2E4E2ULL, 0xE105BD9FF363FCECULL, 0x7493D104F085CBE2ULL, 0x76260B92F90FC683ULL, 
            0x70682D501D78AF02ULL, 0xB16566FBA048566BULL, 0xA89F718062BDFA9CULL, 0x8A997C160FAF9989ULL, 
            0x1A323E8C910C8B3FULL, 0xE4EE51C1084E5178ULL, 0x728A740964074EF4ULL, 0x5B84F22FFFDBE15FULL, 
            0x07B77C8A135B615CULL, 0x8A21876D839A3127ULL, 0x5C8C62F70816CFB3ULL, 0x12D5FE3B075E1232ULL, 
            0x2AB3A8E63A446586ULL, 0x4BFE7BAAB20F0777ULL, 0x8BFE6C4679D7F1EBULL, 0xF23A7EB69AFC3C8DULL, 
            0xAB3A54579282F514ULL, 0x5214167F867E1D8CULL, 0x50E8081E1DC1DBE1ULL, 0x6FD2F0986A6FF2BDULL
        },
        {
            0xC79E27346E1EF169ULL, 0x86181FA11B9F58E7ULL, 0xD9D836B4FC850366ULL, 0xBA12D12C7FCF5523ULL, 
            0x9CA2053156691D3FULL, 0x858BA02C715E5557ULL, 0x6F3A02AB8A8F6E78ULL, 0xF40347E03E165C70ULL, 
            0xFB2842FB34D87936ULL, 0x1813562A72A48B74ULL, 0x9CA0DAA6241D594AULL, 0xA65993330A18E93AULL, 
            0xC02CE805A9065C01ULL, 0x575BE513C8B33E87ULL, 0x9496F612D750768DULL, 0xB72E840B1991D960ULL, 
            0x6EBE938B32F83F31ULL, 0xDE047DFEC143174CULL, 0x02F1EEB1601271DAULL, 0xE04DCE3FC3D79A96ULL, 
            0x464BF86D01551290ULL, 0x54FC965CE830F1D4ULL, 0x3E49BA496097BFFBULL, 0xF0936E7E02A63DDDULL, 
            0x5F65AA7BF4C49F79ULL, 0x1191793F759559C5ULL, 0x3418E3AA83B0DED4ULL, 0x6DC3E78D4F589058ULL, 
            0x25FEAD7309F254D0ULL, 0xEE8AF2E3DDF4F5C6ULL, 0x8D6D5B908DF20F97ULL, 0xE5769A5369870F56ULL
        },
        {
            0xF14849FC87A3BDFBULL, 0xB4B1F88F31EEA0BCULL, 0xB5CCF70F69984BA0ULL, 0x98F8D2550B76DC1CULL, 
            0x887EA6C9F83D7333ULL, 0x716A026BA844353DULL, 0xE1D114CEED06210BULL, 0x86E6DF9B136C3377ULL, 
            0x76B951A38EAD3A54ULL, 0x3FFD823EE78CB917ULL, 0xF35E8A190140D7B0ULL, 0x347C5BC2493A1000ULL, 
            0xBD6A8D4645506DC6ULL, 0x54B8143086B63949ULL, 0x48EAE8FFCBC1EB82ULL, 0x93587863F2000FC6ULL, 
            0xB7DF21B47F1C0283ULL, 0xFC1E9811E5ADB98AULL, 0x43E911F89CF80B8EULL, 0x8DB1E201FECA34E1ULL, 
            0xDBB9E1586C7F2A49ULL, 0x090F63E126F00F0DULL, 0x344BA19A5AB5625FULL, 0xAA52C6F80701DAB9ULL, 
            0x483CDD6C4D9D225CULL, 0x66709CD8798974CAULL, 0x401AA7E45E34E67BULL, 0x66ABBF2B38D1B79CULL, 
            0x601674744509F98FULL, 0x66FC263AAC2CA862ULL, 0x1AD7532D77C96D8FULL, 0x9FFF1D55CC830B32ULL
        }
    },
    {
        {
            0xD5DC65BF94C3B003ULL, 0xEF14789886817EFEULL, 0x87C90BFB3129B849ULL, 0x932C319FEB79CD77ULL, 
            0x94275312FE048FA5ULL, 0x50E353DAEDEBBEABULL, 0xE561D4F596C881ABULL, 0x63821B94572AB78BULL, 
            0xD30115E415691F56ULL, 0xFFBB4E0E7E131728ULL, 0xA09881AFA70C217DULL, 0xED5CD5F460031CB7ULL, 
            0x5B4C743FF35079ABULL, 0x80FCD67C60413EC9ULL, 0x42E27F1BFED03A35ULL, 0x75BF1815D961BE6AULL, 
            0x6941B5DE56871289ULL, 0x3BCD25D0DD1B57E5ULL, 0xC5BD2D2428521E32ULL, 0xA56C082CEF6ACFF4ULL, 
            0x1795BD526E93A745ULL, 0x647A69E6AAE809F2ULL, 0x60C326C81360A3B9ULL, 0x0BA96F1B39BB588FULL, 
            0x4A19607CCCDBAE31ULL, 0xDC8E033197701A84ULL, 0xC2E999F590FF9E92ULL, 0xF355FEE096FECC11ULL, 
            0x1A3A1B104A660533ULL, 0x8B5B9AB310E5C3F9ULL, 0x07023FB191ED90C8ULL, 0x4FA39F60A4EBAFBDULL
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
        },
        {
            0x08DADB6C0D47E0F0ULL, 0x0E402251ACB57CBAULL, 0x226B7CC182426F13ULL, 0x0CF24D5E4E0B7AC1ULL, 
            0x31E350955F090E84ULL, 0xD4B053561C348808ULL, 0xF2614FCE7440247DULL, 0x890E0821FD2F1228ULL, 
            0xF995F9446BCEAD50ULL, 0x6718609CBFA0D8B4ULL, 0x5656A17250B283D2ULL, 0xE0D0582186676221ULL, 
            0x6EA371E0C55AA2A1ULL, 0xB3E01E1F2075B622ULL, 0x91A7119C9E71FFA9ULL, 0x0CA44EA0A1F8AE7DULL, 
            0x4176F44266776413ULL, 0x7D10F5DB7EB035AEULL, 0xF81EB20B123EBF3BULL, 0x3BCDB3A75E13B7FBULL, 
            0x2865DD3816011CF2ULL, 0x9178C3491586B6A0ULL, 0x68D59A802AD5C6D9ULL, 0x020ABBBA3A2F82E4ULL, 
            0xA4E7F3A26862DE86ULL, 0x7849F7D1A18A5226ULL, 0x5284DB9B6108EA99ULL, 0x8A0EC769302DE097ULL, 
            0x7580B8E216F0336DULL, 0xC404E34188193BF6ULL, 0x0D8ACDA6A3536BD2ULL, 0xE8C7FD8A8FF21D82ULL
        },
        {
            0x1F9BDDA9B64AAB82ULL, 0x107627C0318A41CDULL, 0xDDB4D687341F9CBAULL, 0x72BFE36E122BC604ULL, 
            0x8FA69804F42FE95DULL, 0x74527CA5233797A6ULL, 0xF9AD5F5970A02135ULL, 0x508DD86A3D2E7DCDULL, 
            0xD78A80EBFA3D91F2ULL, 0xBAF181C7CB9C7F0DULL, 0xD852EB5F66EA0B32ULL, 0xA71BAD7EB9595416ULL, 
            0x87A9982A55A6D7BDULL, 0x8F5F7C467E20F446ULL, 0x5162210A31231310ULL, 0x33231609482F0442ULL, 
            0x96FDBA08656C6D5CULL, 0x642E391C5E14A7EBULL, 0x1A773D8E3336F550ULL, 0x337CF39BF4E853DEULL, 
            0xBC32F3828CFD170DULL, 0xFDDAD085A3EC636DULL, 0xD5248353B02BBA91ULL, 0xDD54CF33DA64BE5FULL, 
            0xFC0CFAAE64CE57F2ULL, 0x4046BABD3EDFCC29ULL, 0xBA309F8457B27E15ULL, 0x56CAF2966E0CC7EEULL, 
            0xE625FE50D76D7EF6ULL, 0xC24E81B71E56BD9AULL, 0x26509FF929D29729ULL, 0xB7895E4E9441F5A9ULL
        },
        {
            0x9101C61910F95471ULL, 0xCA6EBF4FA1B8D85FULL, 0xBB8705452CE2FDF8ULL, 0x9EF5EC0FE0F0D51DULL, 
            0xED53AA724ACE0707ULL, 0x121F479FAEB22104ULL, 0xE851E8609305DB8CULL, 0xEE29CE84FECCB6F7ULL, 
            0xD0A78991787E6973ULL, 0x2DDC24BFBA77DEE0ULL, 0xA84723515EDF2497ULL, 0x93F298B4DC3D05CEULL, 
            0x56DD4CE879BA4DDFULL, 0x14A2F12834B7C3E6ULL, 0x7933ECA93FC27566ULL, 0x9174DADCBC461FE8ULL, 
            0x2B0DFBDDFD90D6C4ULL, 0xA23ABA1D36960DE9ULL, 0x3A9DF281BC50378BULL, 0xC4448C9C393852F5ULL, 
            0x887EED97074C49C2ULL, 0x4F057AAEA8700A56ULL, 0x79D34AD37F538303ULL, 0x0CE233784B4473D6ULL, 
            0xE9C3D5E4604093DBULL, 0x28121C0B03CE2DC2ULL, 0xF80A201AD6803754ULL, 0x392C47558D2C0CB1ULL, 
            0x1A43C83264D29164ULL, 0xAD44C8B3DBD31D0BULL, 0xF305992D571B6CDFULL, 0xCF27966C973BB84AULL
        },
        {
            0x8A0F39F6822A813BULL, 0x59ADC023E316F088ULL, 0x84C538B490C596C3ULL, 0x0568DD549D7F44FEULL, 
            0xEA2A9D171E750487ULL, 0xC046A0B83C66A0FAULL, 0x33A294C8094A01E2ULL, 0xB7B65C9AD7913CD6ULL, 
            0x7C2EFB2FD3E47A66ULL, 0x287CCAE506BD384CULL, 0x43B0C849F6E80E67ULL, 0x68BD821A43CCAAA5ULL, 
            0xD5BFE95BDC4D56A0ULL, 0xB920F84A5323D586ULL, 0xB69F5729B7C3213AULL, 0x4659E0D8F9BEA034ULL, 
            0x0767FDC6E30630C3ULL, 0xA8021436717D69BEULL, 0xCC55B1A2F4B93B15ULL, 0x2C4E56B37F2FD8ECULL, 
            0x85C68521D5FBB748ULL, 0xAB1394061C76A864ULL, 0x4DBB5633980AD4BDULL, 0x3C90ABDE5650D62CULL, 
            0x36F508AB99C53419ULL, 0x5FC5DAA11B96B196ULL, 0x529C572FC7F65AEAULL, 0xA75D40ECB9F7358CULL, 
            0x87225C379D956582ULL, 0x0E03870DC1814BFEULL, 0x35075E8E13A0B9ADULL, 0x89FEF4A442AF6892ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Betelgeuse::kKeySpawnConstants = {
    0x1B1861164840F3F6ULL,
    0xF5A6F328D75AAEC9ULL,
    0x746EA51D48025266ULL,
    0x1B1861164840F3F6ULL,
    0xF5A6F328D75AAEC9ULL,
    0x746EA51D48025266ULL,
    0x10A78A79E5979317ULL,
    0x062D5B19F6EF184BULL,
    0x79,
    0x22,
    0x69,
    0xD8,
    0x44,
    0xE8,
    0xF5,
    0x91
};

const TwistDomainSaltSet TwistExpander_Betelgeuse::kSeedSalts = {
    {
        {
            0x981069ECE069CBD8ULL, 0x23B6A944B902F908ULL, 0x4A4F527F252AA0D0ULL, 0x94FAA0436D5F2470ULL, 
            0x61F1B345CE2A9BD2ULL, 0x12327FDE7C038A43ULL, 0x9EF0B9B20A693F8EULL, 0x1EFBBFC88C142C95ULL, 
            0xD647DAC719A04D4CULL, 0xBFA5F9F0F2570D35ULL, 0x45D550A5972E1840ULL, 0x4B48173A4968DFACULL, 
            0xBFDF18BAD4129F83ULL, 0x7DDCF4C523E4EB67ULL, 0x6EFEEA98B59D9016ULL, 0x26E5D92349C91A82ULL, 
            0x4730716A642566A4ULL, 0x9F667D7649088DB6ULL, 0x6185C6C7737F77F7ULL, 0xCF393A6CA9167FE3ULL, 
            0xCA9AD627316E63B9ULL, 0xFB60F768F4971ADDULL, 0x115495E4FDA1343DULL, 0xFE5C9C56C55757DEULL, 
            0xE9538B4601B8DDA8ULL, 0x19B4B08FDC010566ULL, 0xFF2A208D33CBCCFBULL, 0xA6F115BE54B6971EULL, 
            0x6D69869F8BE002BAULL, 0xB3E24C755ADEC692ULL, 0x54AACF5F635B5BD8ULL, 0x29F41A8B100B6F2FULL
        },
        {
            0x4792534B35E535E3ULL, 0xB503594E6A7C233FULL, 0x627C7F161BA63F46ULL, 0xBCA78FEE4D21037BULL, 
            0x7988FA0EFF65B8A9ULL, 0x51457B6945F69E99ULL, 0x4660C4F6E4513729ULL, 0xAA383E4E6BA7A327ULL, 
            0xE5023595D15174F7ULL, 0xB2D622238A4436E6ULL, 0x4D9F91E567BEACD4ULL, 0x3A87000D56357D04ULL, 
            0x5030EB0DD5E9A97BULL, 0x5F953C42E5E63151ULL, 0x175115380C8B2142ULL, 0xF6170E3612643E15ULL, 
            0xE7E5F1DE458F30A4ULL, 0xDEE516D3EF3FCF71ULL, 0xE674EA1FA1E0A56BULL, 0x5389C8AE6A363231ULL, 
            0x007A06FD1757E948ULL, 0x25AE9B5BE365521DULL, 0xBBC401316A64DF78ULL, 0x3D6B161C9E30ABFCULL, 
            0x9AADB20EDEE95616ULL, 0x2CADFB3F1CC73035ULL, 0x6EC69729F602C8B3ULL, 0xD7FD806D1043E128ULL, 
            0x35F7A968AC5C61BCULL, 0x7598B1BE51CF5050ULL, 0x7604524FF0B3C689ULL, 0xB15ACBDCD60AB11EULL
        },
        {
            0xC61DBAA0E99D4163ULL, 0x75A4FF97FA3424EEULL, 0xBF1BBAF059130468ULL, 0x5655DD5E9B691789ULL, 
            0xD029853A72AB7AB6ULL, 0xD17383AC4EDFABBAULL, 0xC80ACE305BE8E066ULL, 0x24ED41B167082F7CULL, 
            0xD33CF9701A765993ULL, 0x58D4A506A99396DCULL, 0x90C54F9565FBF21AULL, 0x3E7A69DA42E54E1BULL, 
            0xA1321A7C973BFD8AULL, 0x93FDB779FE77C687ULL, 0x34C39A92FACD443AULL, 0x6CAAA7C88A5F0975ULL, 
            0xF5D6A252F8D97C82ULL, 0x55F430F60A29C07BULL, 0xCD6DFD53D0107F33ULL, 0xB443DFAC5C4EE796ULL, 
            0x47766BAE71E71E3DULL, 0xA5248B49C5E7EAA4ULL, 0x1EEA1DA19CD2D212ULL, 0xFDE260A0E4AA50DAULL, 
            0x225B40BFF3836966ULL, 0x2AC9F3FB94A67FE4ULL, 0x528E6E7F97ECCE28ULL, 0xAC62EB43060374E6ULL, 
            0x8240263588C06071ULL, 0xBD10E1D0361F2D9CULL, 0x08299C27AFFBD61BULL, 0x69BAAEE0F02D3EC6ULL
        },
        {
            0x22D483C917B6A5EAULL, 0x8A14E0300CEFFAAEULL, 0xE65AAB6CAE7EA6EEULL, 0xEF0E8EDB45C6233BULL, 
            0xA3438F6D023EA15CULL, 0x2360A0BEB0311A4EULL, 0xD88C93687FD0C963ULL, 0xF1AF9EAEF9888166ULL, 
            0x106219C408AD16D3ULL, 0x4D4BF6DFD128B29EULL, 0xC2C45CA259C2BB0DULL, 0x95C01A9238B48627ULL, 
            0x893038A0550D612CULL, 0xD7DEAA849B8AA7ABULL, 0xF83A3E8C8474D1DBULL, 0x382140EC7B0ED873ULL, 
            0xBB42745FB8F86EE8ULL, 0x1F8AD9852EF21466ULL, 0x3EDBC3391816B6B7ULL, 0xDC156AD07AECED47ULL, 
            0xCB0D8A27C827416AULL, 0x921A09DCA50527ADULL, 0xF9AAE2D1EC48771EULL, 0x60CACEB75EEFD323ULL, 
            0x6A64C7287D4C0D2FULL, 0xE33AA1886724494EULL, 0x61023551D4C9BBADULL, 0x67C05CC2BBF491A4ULL, 
            0xA95BD4553DF32C60ULL, 0x22DB35B08D997DC2ULL, 0xE780752E686E4B46ULL, 0xD2D856968B4C7823ULL
        },
        {
            0xF7C6683E00032A6CULL, 0x6791506C37835BDAULL, 0xDB050F46B348D948ULL, 0xF1525D0F9D79B843ULL, 
            0x134EE00A690DACA0ULL, 0x68C5F45C795824A5ULL, 0x7630D6DD902A6AA4ULL, 0x1FC86BA6BE1B9B5CULL, 
            0x164DD7960364B87DULL, 0x80C87F791656234AULL, 0xDF5A4DEF792C0FA1ULL, 0x373C1CE0C7BB4EC8ULL, 
            0x9B0E329559CDA358ULL, 0xF91918B8205EB0A8ULL, 0x464121B118C3BCC7ULL, 0x703680EF2E997628ULL, 
            0x3E47817732798070ULL, 0x637DB1AFFD6AB223ULL, 0x9DE7027789029A8BULL, 0xE56E5125B7BEA77EULL, 
            0x98084440598100F4ULL, 0x8CA7824DE4304A20ULL, 0xAE1E9DCBDEE5053DULL, 0xE3FE2795760713D0ULL, 
            0xDFDB319455EBAB82ULL, 0xE7692119D8555986ULL, 0x624E59479BC0433DULL, 0x41F93E81E4968F70ULL, 
            0x5C1029E1A7F7778CULL, 0x2E9602C15BD71322ULL, 0x5F9F2BF4697D9275ULL, 0x71C966C508DB7A82ULL
        },
        {
            0x359E7113426BBE93ULL, 0xF0EA2B1A10211474ULL, 0x0CB092415363B807ULL, 0xE4E02A75A734EB37ULL, 
            0x65E1A1F34D8013ADULL, 0x04162ACEC28ACDE3ULL, 0x6A0102B64EB8E455ULL, 0xF1FC8F32313FAF4EULL, 
            0x269D6947B5A5BE35ULL, 0x6D85EC1B213C7CD5ULL, 0xB09E7BB0C8E71215ULL, 0x73554F28AB442FA2ULL, 
            0xCD57304A974A0E59ULL, 0x6265F0CD03659270ULL, 0x9898247E2BBB4933ULL, 0x2296EE94E65EC767ULL, 
            0xC9F53C7601E23E17ULL, 0xFB38C4B1F7CF8BCBULL, 0x95821B1DFB9CD18CULL, 0xBFED84AA12079EB1ULL, 
            0x3BF3630855F977DAULL, 0xDB2766E0B7CAEFDBULL, 0xC996E6F0C5BC0FE3ULL, 0x6F951156D2EC4D7BULL, 
            0x47AABC91D82289B0ULL, 0x3776F16C7A9E11B4ULL, 0xD71A2C455B3092A2ULL, 0xE4AD868A8F0616CAULL, 
            0x1A818CEC93AD9E9AULL, 0xA098768716268B12ULL, 0xC24EFB5A0B5C250BULL, 0xDE6A19B04E3122AAULL
        }
    },
    {
        {
            0x62090B74838F2FD3ULL, 0x7DA85ADDBB6118FDULL, 0x638F57279E6E3046ULL, 0x41FB0878D3826E3BULL, 
            0xE8B69160DC370896ULL, 0xF1D1D59598A7CFE8ULL, 0x4AE3F7608FA74AACULL, 0x91C7F35F38988334ULL, 
            0x543C1DAEF4F83FE7ULL, 0x58B0DE3D2AE360A5ULL, 0xB3D49F621B9A6C39ULL, 0x5C1766D8004F3BB3ULL, 
            0x7DF1F34954F7FEF7ULL, 0x349DAFF6A9EC6DD9ULL, 0x53A14B7F62DAE24EULL, 0x34CA27EE55771E2EULL, 
            0x1E12777BCE29C1C3ULL, 0x9E216ADBC2BD0040ULL, 0xF887FEC0C71DE11DULL, 0xBF93DAE4F994C692ULL, 
            0x54B9A1CDB0E90C0EULL, 0x650FDFB41239A38DULL, 0xC0B14D9F720A336FULL, 0x31BBD3803B3791C4ULL, 
            0x70B7B1FA629A4F67ULL, 0xFE0B51756D3E33E6ULL, 0x2623C4CB9C33BEB9ULL, 0x686E2C51A0A8561FULL, 
            0xBCD509CD157E7FEEULL, 0xF40D51720A544E38ULL, 0x1900FC4C29D4BCDAULL, 0x2A096D911F67F16BULL
        },
        {
            0x38E02FF3BBE86CA6ULL, 0x27395559559A7ED2ULL, 0x93A4721053478186ULL, 0x3E7B6A2928E215C0ULL, 
            0x95CCB72E35FB75EAULL, 0xDD479B4A6D585DD0ULL, 0x2E05120CBE3FD20EULL, 0x7F521D3CEA8EFB7BULL, 
            0xD5E21EF191325EA2ULL, 0x9B63F13A0FDF9EA8ULL, 0xDD464E765D1A5EE5ULL, 0x596EA99D5F73C215ULL, 
            0x5261844A5555A432ULL, 0x82418CEB2BB55C6FULL, 0xA125531BE86EE3E2ULL, 0xD2ED01CC08FDF881ULL, 
            0xA634CE11AC776CE2ULL, 0xF6F2DB99B8A3344AULL, 0xC03B8E65BF7D7C6FULL, 0xD629AB05E06EA85BULL, 
            0x8DF349741B00386BULL, 0xBB7A9C42D8247EF9ULL, 0x6D2D474165E44827ULL, 0xF7BB7ED903129588ULL, 
            0xE8B99706CE14980AULL, 0xC682F4B46AA19DE5ULL, 0x2AB23EF9B6699A43ULL, 0x65762FFC73F67FD5ULL, 
            0xE88C0BC204CBA3A0ULL, 0x8C801EAEFDFF79F8ULL, 0x2D16FFA14D930EFEULL, 0x7B4D43E5FAC87B05ULL
        },
        {
            0x1E1A759369313A5CULL, 0xBD3D47BCA546D0B5ULL, 0xFFD561B7AF297F01ULL, 0x140ADC42F2F2B1BDULL, 
            0xE25E592BBF4D545BULL, 0xC17DA3899DDB9C28ULL, 0x653C68B2B4818C0EULL, 0xDDD71ACF64BE55FAULL, 
            0x3131827EC1C0C156ULL, 0x94FE459192A01C37ULL, 0x23DDE8CDD232A519ULL, 0xB41A4D3214E57665ULL, 
            0x8306630639D89038ULL, 0xCF26901660910171ULL, 0x1A9CCD8B61F23C4DULL, 0xE5F7D8DEB778ACA8ULL, 
            0x28A9AF1DDE294C70ULL, 0x12D5A365B4063B48ULL, 0x9F8204CF8C28975EULL, 0x7CD1A8E8B49A7177ULL, 
            0x45E94FA9F94DFB33ULL, 0x671847E165377BB3ULL, 0x392EF61E06B398FDULL, 0x4570C06E30510FB0ULL, 
            0x78FE935DA46906FFULL, 0xFCAB1C8FE5A01E70ULL, 0xF552C881045BCA4AULL, 0x1663305780394B68ULL, 
            0xC0E5C605093D1215ULL, 0x27EACF2D29D530BCULL, 0x544560BDC7A3C80AULL, 0xC275F83815D52C33ULL
        },
        {
            0x1C956E71C7A0FCF8ULL, 0x4881CA2586391420ULL, 0xF93F371AE78BEEF8ULL, 0xFB80EFE68095BA2AULL, 
            0xB115E45B22B53DAEULL, 0x8F1CEDDEC5B8A654ULL, 0x4CBA105300332EA8ULL, 0x57617C4A02C4D1B3ULL, 
            0xB2020B0DC7565B7BULL, 0x9C8F9E7B63DA435AULL, 0x2B1AE54C26D69155ULL, 0xB3D38983AE30D03FULL, 
            0xB66C0379C3034EBDULL, 0xFDB8028520CD3A03ULL, 0x7729CD56A8850F1FULL, 0x64DA579D1BFAE654ULL, 
            0x23FD2F179D254448ULL, 0x6365948E69CD0B64ULL, 0x3CAD8451FD996F18ULL, 0xB286B42A3EA45943ULL, 
            0xB3EBCA04B80EF86CULL, 0xEC2B65E446977EA4ULL, 0x70A5033E23B889CFULL, 0x530F12633E1C2827ULL, 
            0x6E20B93BC4AEF0F4ULL, 0x6407B2930D77E307ULL, 0x01E8A6F4AF2464E6ULL, 0x4687F0B49AD5B25CULL, 
            0xBDA1E5C1426D46ECULL, 0x6F9BA035BEE427B9ULL, 0x4B311CBD5DB3529DULL, 0x68CE950493B37490ULL
        },
        {
            0xF66F788D7D30CE50ULL, 0x2F9128B8FF3B79CCULL, 0x65C68FC36107D85CULL, 0xA02AAB62232F302FULL, 
            0x0FC8A03CF4266BBFULL, 0x8596537A544B0CEEULL, 0x65362FA62176CC42ULL, 0x1AF5A4DF2F5AB2C7ULL, 
            0x5BA5EB3CC3DCEA84ULL, 0x728A0B3961A47175ULL, 0x1F92A0539213614AULL, 0x1F09D98948464E4EULL, 
            0x0D1ECA9E5627EB59ULL, 0xDC0283EBC132BDB1ULL, 0x4C577E85A07F41ABULL, 0xB187290AE072D839ULL, 
            0x643EEBE0B0C2755DULL, 0xDC16F7EF23DD1102ULL, 0xB7F78048CC8D2FBEULL, 0x97ED188E36BD3789ULL, 
            0xF538A203BEF33CCFULL, 0x5A59CC93A2B51A78ULL, 0xD154C3FF93B2B825ULL, 0x9F234B31A301CB56ULL, 
            0x244042FC77EBB4BFULL, 0x885EE9ABB4573558ULL, 0xD8F3EB54EDA9D455ULL, 0x3C51875F9034671FULL, 
            0xEDADC3960959361DULL, 0x5AC1BF1DCE3379C1ULL, 0xA447639058E2E471ULL, 0xFDC9859C6B110D16ULL
        },
        {
            0x94EC58632A3C2263ULL, 0x66D70D543191ED03ULL, 0xD5A59A73A4A31BD3ULL, 0x12B8E4A69D720877ULL, 
            0x5C3C837DEED95FDFULL, 0x381E14D5414A551BULL, 0x1EDE4D552D895B85ULL, 0xE5FBACA9916670B1ULL, 
            0x7DC502D5222A5F34ULL, 0x6FDF865C6492BB41ULL, 0xB56F283A63CAF640ULL, 0x337D5570AAD1FE1AULL, 
            0x61952A1F87A77413ULL, 0xC132E897D6ED2E07ULL, 0x4F60604A094154BDULL, 0xB56A9CC8547F1A6DULL, 
            0x4D2BF939BB462A92ULL, 0x17E3608102BA5118ULL, 0x299E0988D8EA828FULL, 0xDBAF0A6A6E5D0F14ULL, 
            0x7BA178E10EB25375ULL, 0x10797CAD36658190ULL, 0x3F59CC2D23AA6093ULL, 0x673BCC36A07603EBULL, 
            0x2D63564F8F052134ULL, 0x0F1758B1228F270FULL, 0x8F141C6F21670456ULL, 0xA8508657CD39AF1AULL, 
            0xB7D3BB7EF723280CULL, 0x9A2B7F21598C1220ULL, 0x705B3DA4C06F597EULL, 0x529B4491CF9F9AE0ULL
        }
    },
    {
        {
            0x392C855F238B40EDULL, 0x00516B2D7B3AAA48ULL, 0x366B28DFB149D80CULL, 0xB4A022729F4BB004ULL, 
            0x41D35297623E90B6ULL, 0x957DE1A2ED05C653ULL, 0x0E0796F01668A34BULL, 0x0655F89F50F31EC7ULL, 
            0x379426771BA8D7FAULL, 0xE00394E18A90B3A0ULL, 0x7F664DBD7F62CB73ULL, 0xA3CA38DDABE7CE3AULL, 
            0x160AC0ADAE8868C0ULL, 0x8AF5FD4D71BAB13CULL, 0xE21CE11925457E15ULL, 0xF6D173A7EE723164ULL, 
            0x48D5D450BCAA5893ULL, 0xCF71503BFE9D4920ULL, 0x23AACCD4DCDE8974ULL, 0x02A179E3AB91F94AULL, 
            0x7A79F942FA276EE4ULL, 0xFB6C0F78CB33B882ULL, 0x15922C838C3548B7ULL, 0xD4B4083399680654ULL, 
            0xA4455A7F52166392ULL, 0xBA1C2B38AC31E1ACULL, 0x20888E9A08800F1BULL, 0xF9F5F3D3A4520AA7ULL, 
            0xFCA97B63DA115430ULL, 0x4D4B303B6B2673D5ULL, 0x4036FE90FF135DABULL, 0xB238E6EDC2295297ULL
        },
        {
            0x213BD810B7D65CCAULL, 0x44799379025797F7ULL, 0xF82B9833AB6CA437ULL, 0x32AA7CFB7EAFAEA9ULL, 
            0xAEF3C063663EC0AAULL, 0xCC9B0507F837C212ULL, 0xD501EF992D13F9F0ULL, 0xBAD699999782613EULL, 
            0x9FE43B8EFBF2E638ULL, 0xF55086D7E4C9FCBCULL, 0xAD6BB0738EA40EDDULL, 0x4027C7BE7C486D34ULL, 
            0x159BE1CFE9641B8CULL, 0x5E4173E1F13CF498ULL, 0x1AEBE8DD3DA107D0ULL, 0xC4439EC37E2EB629ULL, 
            0xD4772A8CC78ABB93ULL, 0x692EDABCB03BBB83ULL, 0xE90975EEBE73F60EULL, 0x570ED8D0BCF52172ULL, 
            0xD09E5827E2D1D0B0ULL, 0xD5E1970BE6CDF55DULL, 0x087CF97DE42BE9D1ULL, 0x061A80EBA879856AULL, 
            0xF443BBB7B8C086D5ULL, 0x9E0348F6ED440B04ULL, 0x1F266C4BE9369ED6ULL, 0xEEF5D1067A74D9C2ULL, 
            0xFC27AB399A6EBA98ULL, 0x8E00F53DA385CF35ULL, 0xED1DD6781168864DULL, 0x776C1873B61C9EE0ULL
        },
        {
            0x5CBA5EAA1A8DF113ULL, 0xEA1BF8FA9F62BE3BULL, 0xDF01B8F846E0AF84ULL, 0xB5AD7FCFD17775FFULL, 
            0x3364BFCCFC36A3FFULL, 0xDBCBAC8D3B16979FULL, 0x569FB7BB7CD993C6ULL, 0x58DDBE2406807956ULL, 
            0xE6CF34BEDD2AAE67ULL, 0xFBBEEADA0B1CA2F4ULL, 0x10FD04FC53F9014DULL, 0x33F1A8BE516775E1ULL, 
            0x4F83B0737A7D9531ULL, 0x96031B092B333E54ULL, 0x8E31F5E7B8B09F85ULL, 0x02F29609785C4DA8ULL, 
            0x7EA99315BB54170CULL, 0x6D6B0727586E91F4ULL, 0xE487255E90943E55ULL, 0xDD52553B2B83B051ULL, 
            0xD3CA683269F9BF2EULL, 0x60FF2CE49E444803ULL, 0xF651C836BFAC7F3CULL, 0x68A28D0C27EC4D59ULL, 
            0x3AF6C90E947294D3ULL, 0x17FF24A517169D97ULL, 0x958DBAD61A43D479ULL, 0xDEFDFECBEB22B277ULL, 
            0xCC1FDDAB8D996C49ULL, 0x59655CE74B91A73CULL, 0xEAAE768665AB3BBFULL, 0xAB622E3AB2402EEDULL
        },
        {
            0x33113A45160A97EFULL, 0x8AD765B5F049CFFCULL, 0x20AB099D76EDEAFBULL, 0xCD5989C74FACB652ULL, 
            0x8EF5F79D3D13C98EULL, 0x2649DEB1AD0EEFACULL, 0xBAD87CF984FCDFEDULL, 0xB575439DC9AC98E0ULL, 
            0xC6CC1AC909B94CE8ULL, 0x4A96A1038E901229ULL, 0xEC7FCD25B08FF9D9ULL, 0x1B52DA36E15694C6ULL, 
            0xD165CC317E5C06F7ULL, 0x302E2F184D9B9BD2ULL, 0x7D759569F75F6DCEULL, 0xECB678A2293D0FC9ULL, 
            0xA2EE226C24B37618ULL, 0x26F7276624AD81A9ULL, 0xD04305DF27EF755DULL, 0x1C65FAD04AE62C0DULL, 
            0x8776E206F9383BABULL, 0x645A899FAB0556B9ULL, 0x2049486AF11D6155ULL, 0x142A8BC4FFFF571BULL, 
            0x225872DA45540744ULL, 0xDE0D08DF35B795A7ULL, 0x83CE9E504C02B77FULL, 0xCFE7FE8F8A17DF46ULL, 
            0xECC071B62F6B6CA3ULL, 0xE34EBDE7196C25F3ULL, 0x8EFCE879C8161884ULL, 0x3C814E42363327C2ULL
        },
        {
            0xD2B07CC76CFC58C2ULL, 0x35C745D3CC358FCDULL, 0x2575CC1C35561238ULL, 0x378234BFCA766EFFULL, 
            0x4A38469566E8806CULL, 0x9AD3A410DFB9EFC9ULL, 0xAB59FA5FF539F0C2ULL, 0x43B0E55AA7F8234EULL, 
            0x0D8EC5A4C2AED5ACULL, 0xE1BD8C1445947BE9ULL, 0x5E7B79CC4ED7B80EULL, 0x67ED8D593D4D689FULL, 
            0xE04AE966D0A96F08ULL, 0xF73C66FB2C30116FULL, 0x73221C57663F4F0BULL, 0xFD63BE46D97D8352ULL, 
            0xFC6B36E931DDA2E2ULL, 0x9086561E13D5F613ULL, 0x04B9619026C62066ULL, 0x967669BA38E0088DULL, 
            0x12C68FB50BAE1493ULL, 0x43B5F6451E6C21C6ULL, 0x327C94AC3713FB3EULL, 0xCD7A3C71AB6F679EULL, 
            0x6D4F81D61CE33E25ULL, 0x85E76213E6B8BBC9ULL, 0x6753D84A78DE2D5EULL, 0xE2F49D4B13D67C54ULL, 
            0x823D86FB42F27911ULL, 0x7EE1D5FC5DB75D42ULL, 0xBA7FEE825B11CC77ULL, 0x565C374E75350EBCULL
        },
        {
            0xC2BE8D11CF42D87BULL, 0x3F3F454CE0FCF141ULL, 0x84D212CA2FD00B0FULL, 0xEF37572E49A2A3D7ULL, 
            0xFC335215FE4A6319ULL, 0xB48540A11F807A63ULL, 0xA24289B414DE52D6ULL, 0xFBBB4F3D9E62A560ULL, 
            0xD3013AEEF5EEB4CAULL, 0xAD682940FE0B5F1FULL, 0x47CA868043DA1619ULL, 0x5B842A2A64970615ULL, 
            0x192532659B4DCB7FULL, 0xAC0EFAD6382A0286ULL, 0xCB8F0D5474C97F76ULL, 0xE97B9D54E90A591FULL, 
            0x12D9B2CCDA1733BFULL, 0x4AD97FEC5C7AC9CBULL, 0x7D7EBFB5E88E36BDULL, 0x474907A0CD4BA8E2ULL, 
            0x0AD9BD1EC0937633ULL, 0x612F39CB03AA2921ULL, 0xB0992F35EF6F4913ULL, 0x2479E44A79A369ACULL, 
            0x42DDA0E87134647EULL, 0x6CF772814BAEF600ULL, 0x54DFD8B24816D217ULL, 0x4387924B67F4E1A3ULL, 
            0x47F75003AD79D8BCULL, 0x366A08DB29B56868ULL, 0x997E4CD2419939F1ULL, 0x632E096F4282D6DAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Betelgeuse::kSeedConstants = {
    0x2169363BA7CE9808ULL,
    0xFAEA3DDE3C34DB10ULL,
    0x16BA65DEC309CA97ULL,
    0x2169363BA7CE9808ULL,
    0xFAEA3DDE3C34DB10ULL,
    0x16BA65DEC309CA97ULL,
    0x2DBC239E9E6D9C42ULL,
    0x50559A1126199A8BULL,
    0x5B,
    0xAF,
    0xC9,
    0xF6,
    0x8D,
    0xF8,
    0x73,
    0xAA
};

const TwistDomainSaltSet TwistExpander_Betelgeuse::kTwistSalts = {
    {
        {
            0x751498D428AA6100ULL, 0xCA4C8F0CA990A91BULL, 0x146C649BDD4085FBULL, 0xA4743028692DBCC5ULL, 
            0x28011B70803BB6BFULL, 0xCD6FC9E5D40B6F13ULL, 0x7CBC09758B53E971ULL, 0x98556AAE043CA8CCULL, 
            0xEF59520A52E25C3FULL, 0xE5DD4FA0E8FA5B18ULL, 0x9F8D16D6CF9F8D84ULL, 0x298B073D151614CEULL, 
            0x25B6BC0013C01AE4ULL, 0x3A4D916C63065BCEULL, 0x9A5D0A52D4FD01D6ULL, 0x73AA51FCDEB8C48CULL, 
            0x0C621568097BC74CULL, 0x654EE6E782D26552ULL, 0x235A0A165EAA7E2CULL, 0x2C155BBA80BE33B4ULL, 
            0x3E333F71E27D9FE7ULL, 0x8B0D5E71564C7CCEULL, 0xFC045661B27839F6ULL, 0xFE4B440F85D98A15ULL, 
            0xA1AF4BD7037AE2BCULL, 0xD38917D1A0054600ULL, 0x3186C6C61F8A28B3ULL, 0x4BDAA33FA2556C7AULL, 
            0xE5865A7924C77B23ULL, 0x6632172F66474AAAULL, 0xB8FB98A3BE2B556DULL, 0x7081E54DD1BE197BULL
        },
        {
            0xAFC608CC51E9CC4BULL, 0x7226D4F2ED9184DBULL, 0x687B1565C2E0914EULL, 0x0CE94ECB6940A18BULL, 
            0x81086E654BD3C393ULL, 0xCC09D8407C0BDFC5ULL, 0x6E16E96151E4D2B0ULL, 0x0CEBFAD98FDDE065ULL, 
            0x9EF4E5C43FEFB843ULL, 0xE9A4AB882607EBA4ULL, 0xA424C1CF03AC6B4BULL, 0xC4D029C6B10D8B38ULL, 
            0x2C3F4C1B17E5F140ULL, 0x0B0E7912E0C3CB25ULL, 0x89280F5CDE880E4DULL, 0xF6A5D90812C79F9EULL, 
            0x67662BCD79640610ULL, 0xE2CAD3CD41593559ULL, 0x6F3E456B5A5FCA56ULL, 0x3825D2853B171891ULL, 
            0x13D21E331FBF036AULL, 0x19AB52D7CF67E69CULL, 0x3C9C34A584DE0695ULL, 0xA3DCCF3FF402D531ULL, 
            0xA9335DC05B18CA5EULL, 0x6C99A896FBCE5C13ULL, 0x8EE43524F157C9DAULL, 0xF31861EE1AD063FBULL, 
            0x6A5CBE9FEBFDBC1DULL, 0x2B37DE450B596DFEULL, 0x7AFC700877EDFC40ULL, 0x89320C445ACEA2ACULL
        },
        {
            0x9DBC27C2246AFADAULL, 0xF3150A63C26B35C7ULL, 0x7DDDA01296B11A51ULL, 0x6B4DF1C82A643AC4ULL, 
            0x339302B9C92D3759ULL, 0x3761AE0C8B655032ULL, 0x69F831E690405DE3ULL, 0x5DD87951980A888AULL, 
            0x21EF3BAD1590400FULL, 0xC974FCCBE74F4B7AULL, 0xBB815430A7E81BD3ULL, 0x1C5770B72EEA01F0ULL, 
            0xE5C9E4C9D218A2B5ULL, 0xCD5368109A4AD409ULL, 0x338877EAE1817099ULL, 0xED66731DF490E455ULL, 
            0x3090954AB8B8E636ULL, 0x877F1E504B7D93BDULL, 0x6B26102783B9D93BULL, 0xEA533EC8594F10AAULL, 
            0x053AA5DF91A46783ULL, 0x5BE68597105A8883ULL, 0x3B556E88D0552B5FULL, 0xC4B233A12D52A42AULL, 
            0x723FBF473F2EEF81ULL, 0x78B5C225286C52CEULL, 0x057AAEA71F3E6B49ULL, 0x8AA8132B64423411ULL, 
            0x2DA31E2377C73328ULL, 0x002406165ABD3C56ULL, 0x6ACDE4B5C9CF8649ULL, 0xAD03CAB10A40F936ULL
        },
        {
            0xABF6057F3207C0DCULL, 0xF5942673C820FBCAULL, 0x2F82E747402C2DB0ULL, 0x6A2BE24A54672607ULL, 
            0x3D8ADD16C43EEADFULL, 0x817B5247750FFDD3ULL, 0x95B1DDBCD34611EDULL, 0x767ACB50529EB0E7ULL, 
            0x573EC029A2C32530ULL, 0x378AB3DD0521F2D9ULL, 0xEF257BD527A15791ULL, 0x3FD00E7F8EDD4358ULL, 
            0x5DF88DDEF45C2CCEULL, 0x99D3DBCF50A71003ULL, 0xA3676B747FCE940AULL, 0x0C89FDE6CDC8679AULL, 
            0x572BE5A3699DF0E3ULL, 0x830CDD557808FF4EULL, 0x382967D49DD2C535ULL, 0x4ECD558ED40F0EF5ULL, 
            0x6E072626BAD640DBULL, 0xE69B8EFFD518756EULL, 0x9573B390E5C74E3AULL, 0x761920EF5D9BDF32ULL, 
            0xCE5F128315B694FBULL, 0xAC2A904567542CF3ULL, 0xDB9AA604DADB8CA5ULL, 0xA7FD8A83E3385690ULL, 
            0x0897BFD15CF9CD3EULL, 0xDA308DEDDAB3ED0BULL, 0xA2ACB89E9B7091C8ULL, 0xB47352ED346C4B21ULL
        },
        {
            0x1C12030C450AFA78ULL, 0xC1D3E46CC95CB578ULL, 0x1328BE4F0F84FCEBULL, 0xE3AED7DB30F127B3ULL, 
            0x1DA2F552E1E7F09BULL, 0xFE8EE4E6181ABDDFULL, 0xA55CBACE99B34393ULL, 0x491103BCAE040488ULL, 
            0x26DA3C28AAE43374ULL, 0x18B36F820B699F67ULL, 0xAE0FE9ED96E1705EULL, 0xF4A4D54AE81D27E8ULL, 
            0xF001B647280E3DB8ULL, 0xAE6C12182ED72360ULL, 0x814B672EEBAF9274ULL, 0x72D615E6F765C6BBULL, 
            0x28CD8CA82F21558EULL, 0x385F4A7F6F6F619BULL, 0xC71C6BCFF47EFC6AULL, 0x2580F5907A2B69BCULL, 
            0xD83D97B1CF6E357EULL, 0x952EA5794A1BF6CEULL, 0x13FD471D1BF92CF9ULL, 0x3FECA3E9364B6132ULL, 
            0x6CFBDCA027574214ULL, 0x89D6431F6D4A9E2CULL, 0x8846D88D65C5AB48ULL, 0x78376BEB3197C8ACULL, 
            0x318921D1E29477F1ULL, 0x79CA266A7E24A3EAULL, 0x2FC2C25C22F6F895ULL, 0xCD191E8773186CB2ULL
        },
        {
            0x72A1E76FD1AB82D4ULL, 0x1455C215E2B4B11FULL, 0xCA8A5752478542E7ULL, 0x82C81C7E73DF687AULL, 
            0x04B143F2539B643BULL, 0x88C2514221534F61ULL, 0xD7527CFBA3952383ULL, 0xF33DFBF9956EBE75ULL, 
            0x66BD465E91AAE44AULL, 0x5DF8FAE1540E223EULL, 0x914070A65F211FE8ULL, 0x6B6CCF95B6393B83ULL, 
            0xA484A59B2D9C4749ULL, 0x54F1423EC7EDACA5ULL, 0x96B3457B9AC21C52ULL, 0x34A57F9241FCA205ULL, 
            0x304AEE31C3A811FBULL, 0xD50155D47A0C4CC8ULL, 0xA5D3440CD12A1278ULL, 0x00F2F8F0ED695BEBULL, 
            0xE649C86C89E086A2ULL, 0x92BEC6D9CC142DB6ULL, 0xCC1C42EFE8D51A7FULL, 0x94FAAE3AE1F82132ULL, 
            0x4E13531DCBB31837ULL, 0x587925E03A54EB06ULL, 0x8377B632426B7D6DULL, 0x5660706EC7F19C0CULL, 
            0xBC321CF6683FAAADULL, 0xFEFCB4ED208477F4ULL, 0x3AC6A78F2F22AD6FULL, 0xAEDE12001AC4DB29ULL
        }
    },
    {
        {
            0x9174A3C7BDE2E53CULL, 0xA09650C29FECFA59ULL, 0x7E07100FBEBEF305ULL, 0xCD66860DFC345978ULL, 
            0x9DA40486724693D9ULL, 0x16A4B10B5FE5FF27ULL, 0x9E874722FEC2A947ULL, 0xC78FCE2125DAB42DULL, 
            0xA91893E5E164EF18ULL, 0x43552313B4E639BAULL, 0x58506499AAFCC418ULL, 0x722D5BB9BC5597B9ULL, 
            0x711903A28E95B29BULL, 0x3E13419662B0ABD5ULL, 0x36849797D6C0AABDULL, 0xAF4DABD6ABF93A61ULL, 
            0x177B756AC21BFE5FULL, 0xAFC958E5B5D37273ULL, 0x447B6EA06B5CC50BULL, 0xBB6DE8705726B4DBULL, 
            0x33C7BA21ED4A98D8ULL, 0x1B5B0971A5555D06ULL, 0x5ABA5D2AD909E20EULL, 0x86E8FBA389A3A0EEULL, 
            0x7BCA6BEFD33A2BD5ULL, 0x21139F2C93CDD589ULL, 0x1C15510243E3758AULL, 0x2297A36B987C48AFULL, 
            0x23046E711A1F28E8ULL, 0x5433010B4D0137B1ULL, 0x7E4B3B18C723DF76ULL, 0xCF0CC75DAF1CE74DULL
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
            0x580D931DCCBA8EC2ULL, 0xF7B35F65A656A64BULL, 0x605ADEEADA1CE55BULL, 0xF2C6079ADB1BB99EULL, 
            0xFCB3CB4FE2A5A4BEULL, 0xF8E8683368FC90B2ULL, 0xD199056661850076ULL, 0x4D327E604B9B1B9CULL, 
            0x54F543A868E7D796ULL, 0x4DD7A4B97F130453ULL, 0xB2FE4F274427387EULL, 0xD9CF535EAD1B32D6ULL, 
            0x94A0A4DD7DC86A3CULL, 0x87CACF93E8002DD2ULL, 0x26EF8D4EDA0C1438ULL, 0xA512AF786F2B90B7ULL, 
            0xDA28DAD0B1C1F94CULL, 0xB222AAFA9A2CA1C4ULL, 0x5988D11506D5DA7DULL, 0x78EA11B9C9B05B56ULL, 
            0x128CB4A0F52A8303ULL, 0x570AD6A3E397F223ULL, 0x4AE367E1EAD0F5D1ULL, 0x7E49DBD281E8F9E9ULL, 
            0xC98B535AAFF699FCULL, 0x52A51678DECF6F3FULL, 0x25DBF9DB6454AFCEULL, 0xFC4BD0DDA09F5E1CULL, 
            0x9546F37DA450B357ULL, 0xE9435A8D3E284EE8ULL, 0x9478C654E4E325C6ULL, 0x9719B9B8E6B97AB9ULL
        },
        {
            0xD03B21422F85F7E5ULL, 0x53BD67A7CF5A74E9ULL, 0x10713C6B5C004C8BULL, 0xCB4C7324215B17DEULL, 
            0xC43ECC60C0964CBDULL, 0x5B50C0BEDDD1B4E1ULL, 0x3345B06F6FACADADULL, 0x7B9E80D95099C863ULL, 
            0xF1C6A1767CB6F136ULL, 0xE6AF035833036BCEULL, 0xF1C7DD001BB1A84EULL, 0x86013EE99C32EFF8ULL, 
            0x08A6960A86F5BBEBULL, 0xC3E4634E2B918C10ULL, 0x71109C7110253FF2ULL, 0xDC3641724603C106ULL, 
            0xD994940DF8D12492ULL, 0x0C5767CC90856718ULL, 0x7C05069DC1F73FFCULL, 0xA8325CA3C3531A98ULL, 
            0xCBC68202B8229E5FULL, 0x5BD8645CC446D5EBULL, 0x0B33A76F95CC6668ULL, 0x68264AB2055AE6B0ULL, 
            0xB69051F9DBAEA759ULL, 0x9AB8C77DCBCC99BBULL, 0xE4C3DEBE21BB3B84ULL, 0x759344E62FA4F767ULL, 
            0x68FA16EAE6AB0652ULL, 0xCCA5594EFF74C396ULL, 0x364B6285BBDEA7D0ULL, 0x1FB944081CA48E2CULL
        },
        {
            0x3147F552BF3C2316ULL, 0xBD1D0DF02190D6D7ULL, 0xC4FEB48B97DF524FULL, 0xE51642E31F472CE2ULL, 
            0xFD6217491607101CULL, 0xC53D0A62E15F3A78ULL, 0x77F466B59D4B05D4ULL, 0xF04D8C3FCF878BD5ULL, 
            0xC4FFDEDB44825090ULL, 0x8114881E46EDE31EULL, 0x24637F69DC0C5A5DULL, 0x4885B4A0F78A1CDEULL, 
            0x1B693B6615464005ULL, 0xB91D29F72C383A64ULL, 0x39D17B98576DC9ECULL, 0x80F9ABA7FAF769A1ULL, 
            0x5FEC3BBF34479926ULL, 0xD122D18BCFEB2BA4ULL, 0xCFEE637618DEDC10ULL, 0x48FBD4EA4600A3A7ULL, 
            0xD07DBE8C6D03A1CDULL, 0x30FFBACD67398241ULL, 0x629323F58D34535EULL, 0x394BF48725195D1FULL, 
            0x227FAFE2CDE2ECEDULL, 0xF90B4C6C1C1F3139ULL, 0xE5ADC1A3690B4688ULL, 0x1A3E03FA17ADC6F8ULL, 
            0x99F5915BE8758F11ULL, 0x8C755BC600A690EFULL, 0xE4A9224CCDE65625ULL, 0x8F9532AABA86DAC0ULL
        },
        {
            0x22E1FAA0805A14A2ULL, 0xBBD69A9D08D89CF6ULL, 0xF90914777EBA48A1ULL, 0xA94B4B6051770731ULL, 
            0x1ADD7222399D1CFFULL, 0xBA8355A455954516ULL, 0x4A8F77AED8496DFFULL, 0x859349548B56EDCCULL, 
            0xE43E8440ED014704ULL, 0x59E0EDC240F9F8B5ULL, 0x1A941E12E115CD49ULL, 0xAF077DA002D0140FULL, 
            0x2239AEB29DF8940EULL, 0x0599C5BA5A54F8F4ULL, 0x51EF3C265592675AULL, 0xCCBF1C8C730229ACULL, 
            0x35C9B19ADDACD037ULL, 0x87CA095736A8896FULL, 0x94FB3421979B100EULL, 0x98CE0B5A3C32C2DBULL, 
            0xE2BC2D579F9A0D42ULL, 0xCD97B68BE8A94B33ULL, 0x7913DD30B5F27D5EULL, 0x669B847DCD4F6FA1ULL, 
            0x3511CCA25DF375C5ULL, 0x51A81DA8664778F6ULL, 0x5649116864BF3710ULL, 0x688567DFDB097424ULL, 
            0x22600F94237B6FE5ULL, 0x7D1573A4E6E3311DULL, 0x796A8F3D657B018CULL, 0xA5E7433F7C2B129BULL
        }
    },
    {
        {
            0x5E85712ED029788AULL, 0xE1E1C11D0057A2A6ULL, 0xDA49E58456A4A078ULL, 0xE71D33FE7684EB51ULL, 
            0x2BFA80ADC41DF19AULL, 0xD4398630DDDEE774ULL, 0xC7BEA279022B96C5ULL, 0x5A6242EA365DBA66ULL, 
            0xE0463AB065F10846ULL, 0xDE10869E11D6D8E5ULL, 0x42D58FB51AF1F313ULL, 0x06F12DECC3773CE0ULL, 
            0xABCEA7D87BA2C0B1ULL, 0xD50779A57F2BB76AULL, 0x2004AA2D6FC3DC7EULL, 0x0B4E36A520302944ULL, 
            0xF4C4E6163E6FC9B7ULL, 0xEFD25947033B31F4ULL, 0x5895C081E2B9F177ULL, 0x8C3B4774309C543DULL, 
            0xB8DF662956132642ULL, 0x1E435C0D3C0974D2ULL, 0xA5AA5A32E5E7EB22ULL, 0xF29CA2FBCC2C1F06ULL, 
            0x3DC1914F0A454B59ULL, 0x1588E4BB75511B29ULL, 0x628D6035FB616F03ULL, 0x207CC438E08D3FCDULL, 
            0x8645E1D80AB71B7AULL, 0xB5336690ECDFFC5CULL, 0x9A1C388D7A27A34FULL, 0x5E87B38421619811ULL
        },
        {
            0x0F058442F10E18CCULL, 0xC32691CE3C66E630ULL, 0xDCA3524DDC61ACFAULL, 0x65D428AFC990FAD1ULL, 
            0x431D0C00B206C4DBULL, 0x15E7BBF54F5ADF74ULL, 0x61A15EB5D1005025ULL, 0x3BD7C792BC19D8B3ULL, 
            0x824FDEEFA49FB8FDULL, 0x822DC94917697BCAULL, 0xB70C7943D501DE57ULL, 0x6AC0F8871B8C4548ULL, 
            0x78C0BE341D89CBD4ULL, 0xCFAC59A2D7FA19ECULL, 0x5F6D8C2D8D170A7DULL, 0x091D8B1E4249E236ULL, 
            0xA1B2948C463A9E73ULL, 0x45FF6E53C7A8A721ULL, 0xE6B15650BBD6C070ULL, 0xBB96ED12247003B7ULL, 
            0xAC7FC5E78410F22DULL, 0x175251E8C73C54DAULL, 0x623C50A1B44DC71AULL, 0xDEF334650B2182EDULL, 
            0x705B2F3C14C37512ULL, 0x77234F88E388BAA4ULL, 0x1C4E23E2CD1D944DULL, 0x2B56D66466B3993FULL, 
            0xEC5FADF21A6A6549ULL, 0xD28462DFDA75C23AULL, 0x8C599E7D298EA1D2ULL, 0x09A31D504D76DB6BULL
        },
        {
            0xEEE472EC4777D82FULL, 0x7689EF17A0E2B5AEULL, 0x2FCF43A2DD4390B1ULL, 0xAC6E80BB0F6BFA2FULL, 
            0x54D935939ADAD9ACULL, 0x94A57D1B6C2DCEDAULL, 0x044DA8238A6F8970ULL, 0x88F6F0D11A7CC05FULL, 
            0x79366E8DB665B011ULL, 0x73BEA9CE9F5B0B0DULL, 0x3E2688CF8B2292ACULL, 0xE44E4EBBDF77FDAEULL, 
            0x96C9F867DD56354DULL, 0x5F439275B339259BULL, 0xA5649844179C8B7EULL, 0x41CB026365E8B9A9ULL, 
            0x59E659F9665AE40AULL, 0x39526FC51FF27FB5ULL, 0x59CE2278B609D96FULL, 0x841D2AED722BEB80ULL, 
            0x66F859D9663D3597ULL, 0x6DC31F9265DE33D7ULL, 0x66CCA9E45E8AE569ULL, 0xD1765675BAA01C3EULL, 
            0x14F04ECE16A30237ULL, 0x402A506F4C084DA8ULL, 0x26AEB427826819EEULL, 0x9B3BC81331E26395ULL, 
            0x78CE0945136154F6ULL, 0xF0472D2A7C9AD780ULL, 0xF8F1971EA983A820ULL, 0x164CD3967CD8DA7AULL
        },
        {
            0x26618EBF44CC3154ULL, 0x8E89E6BCE036D141ULL, 0xD5EF2CFA85646785ULL, 0x07EBE943332E365DULL, 
            0x6D9A5F7976A0CAAEULL, 0x84A0BAE03EF4374DULL, 0x1F88EE711557E8E6ULL, 0x91FF054F68EC8E21ULL, 
            0x8FB8DBE975B59638ULL, 0x1B9806A796166C82ULL, 0x387B56CF0CD42C52ULL, 0xD71A2B2FD453ACD8ULL, 
            0x26F26F85EDAFDEB6ULL, 0x0A04D5F936A0801EULL, 0xDE82EBD7748D9E0EULL, 0x30183030FC9F8137ULL, 
            0x90B1D05A14339245ULL, 0xA5E54AA2913D9914ULL, 0xCBFC54F4947D320CULL, 0x553730DCF058C15BULL, 
            0xC6F0D7B6952CB957ULL, 0x42E8C5FE7FB853B8ULL, 0xE2E92A45C078139BULL, 0xC4C4AE9E792517E5ULL, 
            0x7F4052B44997E809ULL, 0x836A1C697F0C0EABULL, 0xB171E3B9855DA472ULL, 0x8F01F011DFDCD363ULL, 
            0x7D42DB6FBFCD9906ULL, 0xAEEAD56B19483197ULL, 0xCBFBE9677297A8EEULL, 0xE9037DFD7658384CULL
        },
        {
            0x4B8453060F4FD7F9ULL, 0xD5CD1E1712DD073FULL, 0x66C3F7DDB2D81722ULL, 0x7DDB70B80C582FF0ULL, 
            0x3A20C5DA38104945ULL, 0x09070C88ADBCEECCULL, 0x11349F2272FEE4E9ULL, 0x872686AF8EA314D4ULL, 
            0xEFAA1F0C0069FCAEULL, 0x0F5FA04AAA329DCDULL, 0x7DAF3A5CC48899D3ULL, 0xEB92EF95637B9748ULL, 
            0x04B9E1F6FC543899ULL, 0x7CE014354C7892ADULL, 0x7ABC521BB6E7886BULL, 0xB76767C9EB19887AULL, 
            0x670D40A30FA5C560ULL, 0xD7AE7705121D7EC4ULL, 0x52B2B70E0D39BEC6ULL, 0x72F8F5B753C70399ULL, 
            0x06B388F147972B28ULL, 0x1645E98DDCF5955AULL, 0xD11DFB17758BB754ULL, 0xBC6164580BDF832AULL, 
            0xE35DBFF1BCC846E6ULL, 0xFE5F1564F9FCDB58ULL, 0x5E29540E1E81D180ULL, 0xBC11E121F94B05D2ULL, 
            0x8EDC2E25318115F5ULL, 0x9B27A4F0FB74F988ULL, 0x6E7FB3290FDB3F1FULL, 0x7DE96E8921EDF51FULL
        },
        {
            0x34D162E0D8618C43ULL, 0xC1A62C8FFBAB7643ULL, 0xDC7BB7428838E50FULL, 0x95360FC48A574356ULL, 
            0x114AAB590464AB22ULL, 0x37142E70732799E0ULL, 0x2C3882214FE0053DULL, 0xC42447867551C5CFULL, 
            0x6F43A5489AE9C2C9ULL, 0x5FE60162FD07322AULL, 0xE045BC7D81B50025ULL, 0x9C8AB6ACAC634677ULL, 
            0xD73C925E41095A64ULL, 0xDA14900B1B30B154ULL, 0xDC67F8DE18E58E31ULL, 0x5AB6F640CF8725C1ULL, 
            0x35F83C0894629095ULL, 0xBB8F3032A2BAA76AULL, 0xF30045397DF0E106ULL, 0x301D91CBDF35C985ULL, 
            0x7E2D5CFD13674060ULL, 0xF8AF9EE3D4ED3287ULL, 0x4733A784E7FC51F3ULL, 0xEA5C54EA6F2EBB82ULL, 
            0x1FC0872F10FB2E34ULL, 0x0A5D1D98531896EAULL, 0x6ECB571DA6131C1EULL, 0x948531D165C7A8E4ULL, 
            0xA5B8887575BA298FULL, 0x6C10DB1386B8005BULL, 0xECB740958DB5B0CEULL, 0xCBBBF6DD5E68CCA2ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Betelgeuse::kTwistConstants = {
    0xE7EA38192256D736ULL,
    0x2A74D412E5700BB7ULL,
    0x62C45BBA3B945884ULL,
    0xE7EA38192256D736ULL,
    0x2A74D412E5700BB7ULL,
    0x62C45BBA3B945884ULL,
    0x8F430249D1B68A71ULL,
    0x4B1058BDD45CB390ULL,
    0xC9,
    0x91,
    0x72,
    0x25,
    0x40,
    0x5A,
    0xB5,
    0x34
};

