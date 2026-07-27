#include "TwistExpander_Regulus.hpp"
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

TwistExpander_Regulus::TwistExpander_Regulus()
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

void TwistExpander_Regulus::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x936B5E813C7308DEULL; std::uint64_t aIngress = 0xE0550CE816C71642ULL; std::uint64_t aCarry = 0xB114E3A3673B5E63ULL;

    std::uint64_t aWandererA = 0xCB8A7DEF50A61AA7ULL; std::uint64_t aWandererB = 0xAB45F0BA0C6C37FEULL; std::uint64_t aWandererC = 0xFB54A8A5B110536FULL; std::uint64_t aWandererD = 0x8A2A91B589D83710ULL;
    std::uint64_t aWandererE = 0xEBAA047FD1F4AEB9ULL; std::uint64_t aWandererF = 0xA3AE836EAF3D6B6FULL; std::uint64_t aWandererG = 0xF24BA5465FEE6825ULL; std::uint64_t aWandererH = 0x9C9D3D3983AE84ADULL;
    std::uint64_t aWandererI = 0xD7C1A21C286F5FEBULL; std::uint64_t aWandererJ = 0xE8EC2C1BE2987D46ULL; std::uint64_t aWandererK = 0xA3748EC69CEAD043ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xDC0A0C2C7C283C2DULL;
        aCarry = 0xD64DD9BD7C3EDE8DULL;
        aWandererA = 0xC9162E085339B7FFULL;
        aWandererB = 0xD170457454057669ULL;
        aWandererC = 0xAD79B492CAFD5B24ULL;
        aWandererD = 0xA36E99454A59CFABULL;
        aWandererE = 0xAA132C589009DCFDULL;
        aWandererF = 0xB0EF921EED48678FULL;
        aWandererG = 0x8B524878C350DCCDULL;
        aWandererH = 0xF153AE24496B273AULL;
        aWandererI = 0x8FA0FA9E71ED748EULL;
        aWandererJ = 0xD436229580125160ULL;
        aWandererK = 0xE47EB0C50196EDB8ULL;
    TwistExpander_Regulus_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Regulus_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Regulus_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Regulus_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Regulus::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xC1C954143AA419C9ULL; std::uint64_t aIngress = 0x85E6BB86C5EC6D87ULL; std::uint64_t aCarry = 0xB906BC86EDCCE279ULL;

    std::uint64_t aWandererA = 0xF9FD008F8AD8DC8BULL; std::uint64_t aWandererB = 0x9E09FD37B907F7A4ULL; std::uint64_t aWandererC = 0xF3715718336EC1EFULL; std::uint64_t aWandererD = 0xDA3038F14C8FD79EULL;
    std::uint64_t aWandererE = 0xB4965BD075907D89ULL; std::uint64_t aWandererF = 0x8F3F0B9BAD181B04ULL; std::uint64_t aWandererG = 0xF0C1593FE2FC511BULL; std::uint64_t aWandererH = 0xAA9B195769BE2C3DULL;
    std::uint64_t aWandererI = 0x8AD331D489F37130ULL; std::uint64_t aWandererJ = 0xB439628C39834AF9ULL; std::uint64_t aWandererK = 0xD0DB902759749A18ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x899C6E0CABE4DF7EULL;
        aCarry = 0x9F5C3D2893BBC5FFULL;
        aWandererA = 0xB94D96E66B0639ECULL;
        aWandererB = 0x90E33C86378250D7ULL;
        aWandererC = 0xB8142741214A8D60ULL;
        aWandererD = 0xE8F70ED03A804E07ULL;
        aWandererE = 0x896A533A654D4E95ULL;
        aWandererF = 0xCC8710D5DFC27925ULL;
        aWandererG = 0xA30DCD007E67EFFBULL;
        aWandererH = 0xEBF1FA037D13B67AULL;
        aWandererI = 0x8EAF66FF952056EFULL;
        aWandererJ = 0x9AC643B3B922A166ULL;
        aWandererK = 0xED021A4C774714B3ULL;
    TwistExpander_Regulus_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Regulus_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Regulus_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Regulus_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Regulus::KDF_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xC9C67DFB11215CBBULL; std::uint64_t aIngress = 0xD643D6FF9AB6AB3AULL; std::uint64_t aCarry = 0x9C488BC35F2CE068ULL;

    std::uint64_t aWandererA = 0xAD9B19BE031F3FF2ULL; std::uint64_t aWandererB = 0x9196FCB3F501C9A8ULL; std::uint64_t aWandererC = 0xBB709BAF50C40C0DULL; std::uint64_t aWandererD = 0xA9B0E9AD6F9E0CDFULL;
    std::uint64_t aWandererE = 0x9CE73DAD964680EDULL; std::uint64_t aWandererF = 0xDB8569702E7AFF38ULL; std::uint64_t aWandererG = 0xB6F4BE4BEB596696ULL; std::uint64_t aWandererH = 0xA39D80A8C7646159ULL;
    std::uint64_t aWandererI = 0xCFD63E11CCC142D2ULL; std::uint64_t aWandererJ = 0x806DFC7C9301F951ULL; std::uint64_t aWandererK = 0xC1259BAD532357B5ULL;

    // [kdf-c]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xDDDF14F4E63B1F16ULL;
        aCarry = 0x93D26BC6D751F9ABULL;
        aWandererA = 0xE8D7AEA53F0D2DFFULL;
        aWandererB = 0xBCE2BD0EF2F9DFA1ULL;
        aWandererC = 0x896413E71036D146ULL;
        aWandererD = 0xCDD7688970B35E98ULL;
        aWandererE = 0x94B129CFD402129CULL;
        aWandererF = 0xEEE84929559731FAULL;
        aWandererG = 0xBCA1E315C776515CULL;
        aWandererH = 0xD9FA5CA2F3DA9205ULL;
        aWandererI = 0xA6DCDE688F97F581ULL;
        aWandererJ = 0xCBE5FE24F0EC80D8ULL;
        aWandererK = 0x964CD12B75D3D984ULL;
    TwistExpander_Regulus_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Regulus_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Regulus_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Regulus_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Regulus::KDF_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x8DFEF059939FB787ULL; std::uint64_t aIngress = 0xB6F00911ED13CA17ULL; std::uint64_t aCarry = 0xD19E8D10BFB68F6FULL;

    std::uint64_t aWandererA = 0xFEA8A93A813B699AULL; std::uint64_t aWandererB = 0x88991145939E06B9ULL; std::uint64_t aWandererC = 0xD52B73CA6D55515EULL; std::uint64_t aWandererD = 0xA396A70940C5F8BAULL;
    std::uint64_t aWandererE = 0xAB4C31C7BB85AA7BULL; std::uint64_t aWandererF = 0xF93B2E09F02A3CDAULL; std::uint64_t aWandererG = 0xAC0D19833E686A43ULL; std::uint64_t aWandererH = 0x80076720DE975013ULL;
    std::uint64_t aWandererI = 0x8C58836AE18C2964ULL; std::uint64_t aWandererJ = 0xFC2E83B730FFF5E6ULL; std::uint64_t aWandererK = 0xE18D0E0F4EBEC87CULL;

    // [kdf-d]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xA911178FC4FC0EE1ULL;
        aCarry = 0xD2FC4224CD764AAAULL;
        aWandererA = 0xE92F6708ECBD595DULL;
        aWandererB = 0xD518FB790E550702ULL;
        aWandererC = 0xF04EE63BE39F033DULL;
        aWandererD = 0x9A2F65CF9E393FBAULL;
        aWandererE = 0x9A152566BCDD4FD3ULL;
        aWandererF = 0xEBD065220F7F928AULL;
        aWandererG = 0xC97162ABDA8E356EULL;
        aWandererH = 0xC5339B1F43FF9861ULL;
        aWandererI = 0x823F0C9CE7A3996FULL;
        aWandererJ = 0xA3AC52D86E45BC4FULL;
        aWandererK = 0xE7FB9C4877BA0571ULL;
    TwistExpander_Regulus_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Regulus_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Regulus_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Regulus_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Regulus::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xADFFC6BE9CF05E09ULL;
    std::uint64_t aIngress = 0xB0601B4190157B0FULL;
    std::uint64_t aCarry = 0xA18891F39F64C8F1ULL;

    std::uint64_t aWandererA = 0xA6B4459905D9DB5CULL;
    std::uint64_t aWandererB = 0x97D26E202200E23FULL;
    std::uint64_t aWandererC = 0xB993123A2A8AC4ACULL;
    std::uint64_t aWandererD = 0xB1379C853D48DA60ULL;
    std::uint64_t aWandererE = 0xDD720572CE0BA720ULL;
    std::uint64_t aWandererF = 0xA81FEF2080A127CDULL;
    std::uint64_t aWandererG = 0xD63A24E694B5B4C5ULL;
    std::uint64_t aWandererH = 0x9F7D89A4E83490E4ULL;
    std::uint64_t aWandererI = 0xC16E39E7A3EAA44BULL;
    std::uint64_t aWandererJ = 0x8898D07756E80751ULL;
    std::uint64_t aWandererK = 0xCEB33635D010BF6DULL;

    // [seed]
    ////////////////////////////////////////////////////////
    ////////        KeyRotate
    ////////
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateConstants), &(mDomainBundleInbuilt.mKeyRotateSalts), pSnowLaneA);
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
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateConstants), &(mDomainBundleEphemeral.mKeyRotateSalts), pSnowLaneA);
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
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateConstants), &(mDomainBundleEphemeral.mKeyRotateSalts), pSnowLaneA);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateConstants), &(mDomainBundleEphemeral.mKeyRotateSalts), pSnowLaneA);
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
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnConstants), &(mDomainBundleInbuilt.mKeySpawnSalts), pSnowLaneB);
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
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnConstants), &(mDomainBundleEphemeral.mKeySpawnSalts), pSnowLaneB);
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
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnConstants), &(mDomainBundleEphemeral.mKeySpawnSalts), pSnowLaneB);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeySpawnConstants), &(mDomainBundleEphemeral.mKeySpawnSalts), pSnowLaneB);
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
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), pSnowLaneC);
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
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneC);
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
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneC);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mSeedConstants), &(mDomainBundleEphemeral.mSeedSalts), pSnowLaneC);
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
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneD);
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
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneD);
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
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneD);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneD);
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
    TwistExpander_Regulus_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Regulus_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Regulus_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Regulus_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Regulus_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Regulus_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Regulus_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Regulus_Arx::Seed_H(pWorkSpace,
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

    TwistExpander_Regulus_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Regulus_Arx::Seed_J(pWorkSpace,
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

    TwistExpander_Regulus_Arx::Seed_K(pWorkSpace,
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

    TwistExpander_Regulus_Arx::Seed_L(pWorkSpace,
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
    TwistExpander_Regulus_Arx::Seed_M(pWorkSpace,
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

    TwistExpander_Regulus_Arx::Seed_N(pWorkSpace,
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
    TwistExpander_Regulus_Arx::KEY(pWorkSpace,
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

void TwistExpander_Regulus::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB86D568119AB6238ULL; std::uint64_t aIngress = 0xDB49A727467B9003ULL; std::uint64_t aCarry = 0xE6D9E80F104398E9ULL;

    std::uint64_t aWandererA = 0xE19FF17C056454F2ULL; std::uint64_t aWandererB = 0xD2E8EFF083B45AACULL; std::uint64_t aWandererC = 0xE7C49877C897D1EFULL; std::uint64_t aWandererD = 0xD2736A129FFEA3CEULL;
    std::uint64_t aWandererE = 0xCB618EC6ACEBF4BDULL; std::uint64_t aWandererF = 0xFA84F7C934AFC5EDULL; std::uint64_t aWandererG = 0xB9330095E3809BE5ULL; std::uint64_t aWandererH = 0xCBF90A9173009388ULL;
    std::uint64_t aWandererI = 0xCE93CDB66F868235ULL; std::uint64_t aWandererJ = 0x87F97A97E989303CULL; std::uint64_t aWandererK = 0xDB414DF0A46BEE0FULL;

    // [twist]
        aPrevious = 0xDDAECB77D1BB227CULL;
        aCarry = 0xD55E134B02088084ULL;
        aWandererA = 0xA4A7F685328F53A7ULL;
        aWandererB = 0xB441C72BEE886C4AULL;
        aWandererC = 0x8326C44B1F6714F7ULL;
        aWandererD = 0xAD7FF8AEAE0593DDULL;
        aWandererE = 0xE381BA0E7B67991FULL;
        aWandererF = 0xEE3D96C8F51FB239ULL;
        aWandererG = 0xBC2863C705A86326ULL;
        aWandererH = 0xE26D6AC46BF4E70BULL;
        aWandererI = 0x879449FEF39B7C55ULL;
        aWandererJ = 0xDBEA948E69584657ULL;
        aWandererK = 0xC57DBFDFCA868C7EULL;
    TwistExpander_Regulus_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Regulus_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Regulus_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Regulus_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Regulus_Arx::Twist_E(pWorkSpace,
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

    TwistExpander_Regulus_Arx::Twist_F(pWorkSpace,
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
    TwistExpander_Regulus_Arx::Twist_G(pWorkSpace,
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

    TwistExpander_Regulus_Arx::Twist_H(pWorkSpace,
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

void TwistExpander_Regulus::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Regulus_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Regulus_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Regulus_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Regulus_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Regulus::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Regulus_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Regulus_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Regulus_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Regulus_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Regulus::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 27 of 33
    // Exploration cases: 0
    // Structural maximin 510 / 674; family total 13799
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
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7969U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4008U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3738U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7699U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1330U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1645U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1465U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1960U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 92U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1510U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1735U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1915U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1420U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 27 of 33
    // Exploration cases: 0
    // Structural maximin 506 / 674; family total 13834
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
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7339U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7159U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7249U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3468U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7609U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3288U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 610U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1060U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 790U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 475U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 970U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1015U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 655U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 835U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 520U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1285U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldSeedControl candidate 27 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1047 / 1248; total 28056
void TwistExpander_Regulus::FoldSeed(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1488U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 228U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1578U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1353U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1533U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1623U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1263U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 948U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1443U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1713U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1803U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1308U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1983U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1826U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1083U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 273U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 993U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1128U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 408U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 25U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1781U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 678U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 543U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 138U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1758U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 295U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 340U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
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
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2028U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 205U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1938U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 453U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneH[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 318U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 588U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 385U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1218U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 183U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1871U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 813U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1038U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneJ[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 498U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 903U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 633U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1646U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneK[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 160U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2006U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 723U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 250U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 93U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 115U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 858U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1893U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1668U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1691U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 768U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 363U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneN[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 70U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1848U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1961U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1916U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1173U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1398U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 48U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1736U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldTwistControl candidate 27 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1044 / 1248; total 27973
void TwistExpander_Regulus::FoldTwist(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1129U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 116U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 566U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 881U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 71U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1444U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1376U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1489U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1174U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 26U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 476U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1601U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1151U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 701U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1894U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 251U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1579U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2029U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 521U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1669U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1714U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 296U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1061U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 926U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1534U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1399U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 904U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 656U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneG[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 386U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1196U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 746U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1354U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
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
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1016U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1286U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1511U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1331U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1241U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 431U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 859U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 836U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneJ[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 814U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1039U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1466U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 994U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
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
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1759U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1084U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1939U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 611U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1421U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1309U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1106U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 971U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1984U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1804U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 791U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1624U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneN[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1219U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 161U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 206U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 341U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneO[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk P
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1849U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 949U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1264U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1556U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Regulus::kKeyRotateSalts = {
    {
        {
            0xD00E0299D79A1077ULL, 0x70BAA4C9FA9FBAD7ULL, 0x9B409D50C11AF831ULL, 0x6A4CACABBA9E214FULL, 
            0x3F17A03BD0D93973ULL, 0x99B9587D6A479515ULL, 0x19C64D08102D2948ULL, 0x5CCE2A79AD7A2321ULL, 
            0x0EFC42D43B8ABD20ULL, 0x5A35B3F217BD859CULL, 0xDB2258A368F2D321ULL, 0x4AC2102C9405774BULL, 
            0x93A110DC2EE14793ULL, 0xF539268915956D79ULL, 0x2476637E433FF448ULL, 0xE6DF5BE5DF1B021DULL, 
            0x474068C75727254FULL, 0xB166FE8A9310CA65ULL, 0x2D058EB683E3577AULL, 0x47D6366230F23B6AULL, 
            0x3F3A3D454AD338F8ULL, 0x592B5A7FCCA0CF20ULL, 0x10EB97130DB28C49ULL, 0x99B04EC1BC10E236ULL, 
            0xB12A3DAF1D1407ACULL, 0xD9A064CE1E9F7973ULL, 0xE73E10058A3A7836ULL, 0x0E2FA8B5C4B2B44EULL, 
            0x745C736B3558A4ACULL, 0x8EA5486D39E7E8E8ULL, 0x14AC17A194C19E4EULL, 0xC8DF2A3484E104DDULL
        },
        {
            0xA57114F1E0AF6798ULL, 0x13A9730A70FF8EB0ULL, 0xABC3722C8DE440CCULL, 0x8F6FC1A400275F99ULL, 
            0x1988210761901A99ULL, 0x0B8BB44BC6BAE2B9ULL, 0x69E1B86D4EBC6A7AULL, 0x3134469B404AE197ULL, 
            0xF70F74BB0FCD35ADULL, 0x1918573F42301596ULL, 0x31EE55BEA74E21BCULL, 0x55F88C289A90B1E9ULL, 
            0xC7754835A7F28048ULL, 0xAEE939973EEADB8CULL, 0x1C1B96DC0A709C88ULL, 0x411A1596F33D46AAULL, 
            0x1EF579C1F8879161ULL, 0xEBCB4BAD8D9CA94DULL, 0x63FD7788C8999B1FULL, 0x5CF1294DFFAF4970ULL, 
            0x7DBBDBC63E1370F6ULL, 0xC4F280022C728203ULL, 0xCF81634D991863F1ULL, 0xB7BB7BA3C7FD6BBDULL, 
            0x9FE3EED61950D2D1ULL, 0x18A3020F80B7A031ULL, 0x4E64B3BF62CE80E8ULL, 0xFF46D89629338CF2ULL, 
            0x5A67A5CF708F9BB2ULL, 0x4EF0ED3424319E9CULL, 0xBD49C76159BE8A89ULL, 0xF0C79EE7B08E9CE5ULL
        },
        {
            0xA9A39D00910ABDF8ULL, 0xDD250E6F564B419FULL, 0xBE7AFEFE4427C4FCULL, 0x2870A1951AFCD710ULL, 
            0xB1EBF32B08C67C37ULL, 0xCBB7FD42A58FA660ULL, 0x748456301245CED1ULL, 0x5E9A7F2EECF3D08DULL, 
            0xFA137612C32D2E5DULL, 0x510A316B54F00B9BULL, 0x9A3D32D1066EE3EFULL, 0x493CE9CC16958210ULL, 
            0xA8EAC4060BC48930ULL, 0x1F2E29571E7B1740ULL, 0xBDA837A265B5DB3DULL, 0x19EFC3E006C8F2E2ULL, 
            0xE52A2F0EB6EB02E7ULL, 0x012D7B3DE5F2A6C3ULL, 0x4D994D0796A0ACF6ULL, 0x8A3B2AFCD8FDCA91ULL, 
            0x208BBB0F0CDB1610ULL, 0x97E6CFABE6092B7CULL, 0x6A1F5C25B4CB6FDAULL, 0x61AEB24A973333A4ULL, 
            0x4C8414AC3C356684ULL, 0x9B5353ED7262A9C7ULL, 0x95C56612F0DD9959ULL, 0xC6E7DE06E72448F5ULL, 
            0x6E8942C372FD034FULL, 0x87DF5661867C24E1ULL, 0x5D0737B3A3A70E5BULL, 0x47C64AF0943D4501ULL
        },
        {
            0x3C1B2758498BD8A5ULL, 0x0C325FE966B711BCULL, 0x69EC3A4CD111D767ULL, 0x3B46BD9BF911B835ULL, 
            0xD3B078D6A74E5D75ULL, 0xFBE9CEF5489EEC00ULL, 0x3366F0F5FA35F297ULL, 0x4B48DF03D2722410ULL, 
            0x486C4D32C065318BULL, 0xFA020336D14693A6ULL, 0x93AF5749DA2EA557ULL, 0xE8AAB5DBA3512F18ULL, 
            0xC2949E7231DF7AA0ULL, 0xF7AF209948188505ULL, 0xEC816E556B825B0EULL, 0xE81C33A93306DA34ULL, 
            0xB62B37FC261DE905ULL, 0x02EC60D42EA069A1ULL, 0x499688E9BF27DBDCULL, 0x475A69ED933654ACULL, 
            0xFD0827BB70971111ULL, 0xC0F2C8B2E90FB1C6ULL, 0xE266CB082F1DDA77ULL, 0xB2463E26174315D4ULL, 
            0x75AB7D4D62098265ULL, 0xA6B8C936F9D8639DULL, 0x5128C437D5129D6AULL, 0x6259CF3D228A1084ULL, 
            0x61A547855A75418AULL, 0x3695E9BD486DE2F4ULL, 0xE8A5A0AE563A1F0EULL, 0xEB5F42E9A036379BULL
        },
        {
            0x4E00A4D3E65CA2BEULL, 0xCCDAA2761C9A9A71ULL, 0x7CA06F34B895F656ULL, 0xAAD43F06D63DEE7BULL, 
            0x73D50611DD2191C7ULL, 0x7EE396B582766B7BULL, 0xDD9F3BD59C3691CDULL, 0x4F2DDB9A4BECEF94ULL, 
            0x63FAD1FEA54C8C8FULL, 0x357CAAD116CB3861ULL, 0x487FDC6964DE4A6CULL, 0x5448611B931E71C8ULL, 
            0xEF498056FBE61C84ULL, 0xE2DE3905B4D71B4BULL, 0x358035CC7023D5FDULL, 0x198080D1B6A3ACFEULL, 
            0x61716B98EFD200CCULL, 0x59F50DB97A55B595ULL, 0x0D9674A69848BB85ULL, 0x124BDD2755F93BFDULL, 
            0x8614594EB42C65ADULL, 0x93515768BB61CD41ULL, 0x79E0483FC1653609ULL, 0x139CAB94A68E219EULL, 
            0xB83587792CB14E99ULL, 0x5DE6A65DA27D6973ULL, 0x20A3C0425AC707F2ULL, 0xE16499B3E7C6B6EBULL, 
            0x0685954018923578ULL, 0x07D9A787AF76C19DULL, 0xC574DC0DBB6E8416ULL, 0xDCFCE87FDBA40B75ULL
        },
        {
            0x8DEA855F1F5976C6ULL, 0x700535CA67BCD4D6ULL, 0x2F2A4A452A4584D1ULL, 0xF32A191AF7FE985EULL, 
            0xF9EE316BC47016EDULL, 0x2BB7CCA95B86D474ULL, 0x9CE07C28E16BD5B5ULL, 0xEACAF2A9E1C7B574ULL, 
            0x1EACE0E420C34B87ULL, 0x955104DEAAF85F19ULL, 0xCE6078DA044FD00CULL, 0x8255D68DC17A2C29ULL, 
            0x134E817497703FF5ULL, 0x40B5D0BFFBB23080ULL, 0x77BDA0376E46656CULL, 0xEA4043ECFB372B30ULL, 
            0xE27F627214D25F9EULL, 0x7A07839AC00B050BULL, 0x3D509B2D0ABAB2ACULL, 0x821BD10499AA0F3DULL, 
            0x5E013AFA33BF76AEULL, 0x82BE393F1A214C51ULL, 0x9AB3D7BE5B1A5DE8ULL, 0xC4FABB506A855F86ULL, 
            0x9D72312BE65EC6F5ULL, 0xE6DF21F319D3B3DCULL, 0xBDB6BD124F4789CDULL, 0x1766E3377A236A1BULL, 
            0x2064C73EB8E70AADULL, 0x9BFE43E0C1C60DBFULL, 0x150DF1D430DCC546ULL, 0xDA01546969579BECULL
        }
    },
    {
        {
            0xFA756BB8EB4364ABULL, 0xC0286BE9C2FBDD92ULL, 0xCB8DC9677ADDB19DULL, 0x371992AFAD00EF73ULL, 
            0x5D66AE7BE9C7BE32ULL, 0xF1B8328FC06176A2ULL, 0x859FDCF3C18FDBD0ULL, 0x414BDF781C9C02AAULL, 
            0xFBD25DCECC0E19B8ULL, 0xEFCDA07E61487CB8ULL, 0x4B8D91B4AAD61081ULL, 0x603EE0A67EB0ED6AULL, 
            0xA40568268FAC1AE7ULL, 0x08BEF03DC1109547ULL, 0xB483D7CDF22C15EEULL, 0x4AE6657AA4C978B0ULL, 
            0x0EC64DDA3C8C02E5ULL, 0x720F04ED7F96695BULL, 0x6E0BA65BA27966B0ULL, 0xE5B2BE66ECDF3514ULL, 
            0xB75FDA26A30E4F8BULL, 0x84F1697BE25F5EF1ULL, 0xFFC9B8A0606B3147ULL, 0xEFE2EE1E6F62864DULL, 
            0xBD2898D798DDA27EULL, 0x7BC3998C575C293DULL, 0x8B22B1728DAD8C6BULL, 0xBDB68B8361C5533CULL, 
            0x2D686ACA47AB2021ULL, 0xA6F689D1DB373F6AULL, 0xC837B8645C3BDABEULL, 0x66552991EFE8192BULL
        },
        {
            0x2D48A6300796F967ULL, 0xEA5F80D3D8E06543ULL, 0xF14B46DD734BB86FULL, 0xE9AEC6E690310927ULL, 
            0x17CFE12718F63A8FULL, 0xEB544F833210EA67ULL, 0x6A6B8E30E8E6802EULL, 0x6E62F1D263322384ULL, 
            0xD6B5024501BF00C7ULL, 0xA271B0E1056419BAULL, 0x931EA5A71DAD9593ULL, 0xDF38DCF95364B259ULL, 
            0x8B5A7BFD6E642364ULL, 0xBED511B2B9DD3CFFULL, 0xAA327E0836B73B0FULL, 0xDD8A73B1E2BAD4DFULL, 
            0x2E096BCC072EC3D6ULL, 0x38AAF937674D6D9AULL, 0x1ECD2BD3A2C1E5C1ULL, 0x9EF68CFFA99E988CULL, 
            0x56C3997FA030D305ULL, 0x70824E5B7DD4A55AULL, 0x09142D77DFF5CFC4ULL, 0xCCF29F19B83E911DULL, 
            0x547C3EBE40CBFB9CULL, 0xCE418A5D6A973C7AULL, 0x72EC070D7AB29A05ULL, 0x83F6A3188F09D0A2ULL, 
            0xA2B09AFD02F45DBDULL, 0xAB24AFEA1F9BF003ULL, 0x5A484C322D760D28ULL, 0x8501099523940E67ULL
        },
        {
            0xDD8F19A22A36EF1AULL, 0xA44F0A59DD78409BULL, 0x6332F98F6BE915BEULL, 0x0B9F38076D45A561ULL, 
            0xCB4ED50050CBA527ULL, 0x682808A55658F74DULL, 0x0B2C96CA2A352E27ULL, 0x472096011B1BAAFCULL, 
            0xB5E52C6C5D759993ULL, 0x7FBE155C0B704F3FULL, 0xA6A5BF8B6A47601BULL, 0x98DB3DDB9D82A83DULL, 
            0x94F1DFC63EA0379EULL, 0x8E5EBF1C88434477ULL, 0xFD77B43A62A8E48CULL, 0xD406FCD0025904D3ULL, 
            0xD4165C8E6BF1487EULL, 0x057D636BA12D4566ULL, 0xFC9FB10175689436ULL, 0x3DEA4CD8F39FF614ULL, 
            0xE2FCB337B7C0B012ULL, 0x03F2F54EE9C73B3CULL, 0xA72AD19924FC2EC4ULL, 0x724E04E46DDE6A2FULL, 
            0x585842522155E4F2ULL, 0x5837F4BB3F305342ULL, 0x7AD47F32743C085EULL, 0x3017E3E3B68C8093ULL, 
            0x10744D693471F904ULL, 0x31E1F855912DAFA9ULL, 0x6CA662BCD15D0493ULL, 0x74CEC28EC2B9BC92ULL
        },
        {
            0x275BCA94ABA8C3EBULL, 0x876A821431986865ULL, 0x3E52AF72B351631EULL, 0xA25667CB687BAA0EULL, 
            0xCCF1780781DC3B21ULL, 0x350B97EA29B92DDBULL, 0x00506F2F939C37F0ULL, 0x6A269F566877C186ULL, 
            0xE6FF94D6057FF512ULL, 0x2CE23E5DDA27F326ULL, 0x5ED7CEE43C9464B1ULL, 0xF33A64204BF16836ULL, 
            0xF8471322AE5688B2ULL, 0xEECFB1A314A5F020ULL, 0x35B08ECA83B20705ULL, 0x67896FDD370235EAULL, 
            0xCA521AEDD9163EB0ULL, 0x9DB3BE098C228930ULL, 0x09CF0DEC3AE8A025ULL, 0xFCD6FC9DA5414EACULL, 
            0xAA1A13D9E898CDE5ULL, 0x5DF98239E066537AULL, 0x3063E0476B5CD808ULL, 0xB504BCC0E759C263ULL, 
            0x179098198899D814ULL, 0x79670D92471E007FULL, 0x982038EB887A0C51ULL, 0xE0CE79D26A9A8693ULL, 
            0x20910D550986B8CEULL, 0x332028FA667F7373ULL, 0x9DEBD8B6D4DF6788ULL, 0xEE1BFA1AF882272CULL
        },
        {
            0x031E9828D3A5926FULL, 0x85BD20F9B03F4C33ULL, 0x5BD1981D048CF848ULL, 0xE0B6FD802B075E63ULL, 
            0x4BBE8758BE48F5C7ULL, 0x793117514B990DCEULL, 0xF810B2CB980AA7B0ULL, 0x7283B178BFC2979EULL, 
            0x33D314CBBBC828FDULL, 0xABFBF94836B7A07CULL, 0x1DC398CCB0DC9F93ULL, 0x42EE3B3BE8555746ULL, 
            0xF2A88479CDCD6A15ULL, 0x75694C70D2895357ULL, 0x627CDAFCC163A802ULL, 0x4CD99058C742C53FULL, 
            0x6DDD2948F54B1E45ULL, 0xB8AFE6081A7D5F06ULL, 0xAD1CF993ECDA522DULL, 0x97C18A8501503191ULL, 
            0x76EA9E0DF2BD0493ULL, 0x86280C441D885608ULL, 0xAF691022D04FBCFFULL, 0x1AF4420821268187ULL, 
            0xE131DE755A8D67B2ULL, 0x574A3FCA9540B590ULL, 0x0F7ED526CA53AA79ULL, 0x4E56D8D3BBA266D2ULL, 
            0x6358FF8960F5AB46ULL, 0xEF5B3BC99013A6B7ULL, 0x5A8FF05AD4CA75EBULL, 0x5A070C84F3F60F99ULL
        },
        {
            0x0EF3FEB06FDAA50EULL, 0x73D2A539D7113C26ULL, 0x89A5965D2EA8D000ULL, 0x5A77A786456B9E67ULL, 
            0xDD2F2D1CA2D423DBULL, 0x7A51037ECF2885D4ULL, 0x3E7D437CC50C0860ULL, 0x7DFA3AB44BE1DFC3ULL, 
            0x2961A2A4519055D5ULL, 0x79D430EE5DD3A804ULL, 0x217555D969594D7CULL, 0xDB859F653199BF7DULL, 
            0x1A50F94726E54A83ULL, 0x40E0CF3B5550DAA7ULL, 0x60D7110667AFBCA4ULL, 0x08E6BE63159DF7F8ULL, 
            0xFCB94A223DBB423AULL, 0xA191917036B946E4ULL, 0xCEE9FFF14B73B2DFULL, 0x75911C677FD75537ULL, 
            0x32F62D42261DD56AULL, 0x136953347058ADA5ULL, 0xDDA8CC002EEA7C63ULL, 0xA056B28B0EB42053ULL, 
            0x7C12BB9CD8F88556ULL, 0x0E672FFFC5AA9D72ULL, 0x61E3254421010F2CULL, 0x5C55B19660113CBBULL, 
            0x8DC26E45A842B221ULL, 0x8AA8EB370984E44BULL, 0xC2BA612586C62AA6ULL, 0x97C44C08ADB5621AULL
        }
    },
    {
        {
            0x3CDE624FFEEB1240ULL, 0xF4007A392BD4CA01ULL, 0x8A22BEDCABD4D671ULL, 0x691061CD9567387DULL, 
            0x32136F46B055D031ULL, 0x5BBFC614934C9CF2ULL, 0x6CBD9DB3BB18D832ULL, 0x2F8B23589DCBABF6ULL, 
            0xD7AB6933B146755AULL, 0x19350597AE0BD718ULL, 0xFBADAC5E19A4CD88ULL, 0x9C50D238FF961516ULL, 
            0x3BC21803CAC6BE72ULL, 0x26782A31302E15A2ULL, 0x72C7EE7139551A85ULL, 0x85D3B04EE9141B64ULL, 
            0x8844FC809806FEF0ULL, 0x33938CD2A4E20A46ULL, 0xD3B381C8958F5459ULL, 0x32081F7E22D0BBB6ULL, 
            0x4F3223191EA14BB5ULL, 0x1E9F0B7B75432DF3ULL, 0x0B69E36319E53029ULL, 0xD5BB65B49CDA5751ULL, 
            0xF3EA871914FEF48EULL, 0xC9CC7584F024085CULL, 0xBD4E4E895E75675BULL, 0xB394B25104D1BF89ULL, 
            0x17647D2DFBC416F6ULL, 0xC304DF9BE95C38E3ULL, 0x9C2D782A798C13C6ULL, 0xDDBCFC33DCBE259AULL
        },
        {
            0x7A762CF4D45A01A6ULL, 0xCE697851E16D579EULL, 0x2A32132362DC8F8BULL, 0x85D2CDFA9EA7854AULL, 
            0x78DEE5E4B1DC4088ULL, 0xBFE6F2B7922693AAULL, 0xAF74424A69336F29ULL, 0x3F9482BB50908754ULL, 
            0x3B6D6883EE23D1F1ULL, 0x52F5F08E8FD991A4ULL, 0x3FE48542CE4B0CC5ULL, 0x2AEC0B8F305EFD7BULL, 
            0xD1CE19AB40EF490FULL, 0x87AFBDEBF49BC400ULL, 0x4F338D415AC55991ULL, 0x86BE426826950E7FULL, 
            0x643113B102A779D7ULL, 0x4CCBB4D22BC5407DULL, 0xDAFCAC347C9B61ECULL, 0x04C86D960D4227ABULL, 
            0xB49FB435BD125601ULL, 0x32555107B431D1CEULL, 0x44EE0675DD7BFE00ULL, 0x2E56ECA2C00FA0ABULL, 
            0x018311335530B15AULL, 0xDFBE65DF1EF03920ULL, 0x17DA888CB661E09CULL, 0x2AF60C91F53B7E47ULL, 
            0xB28401D0A528065CULL, 0x13A01140825DE99FULL, 0x89B649E2DC8F2F03ULL, 0xBDA90D3C6E83D1D5ULL
        },
        {
            0xB20CF0B69E7E057CULL, 0x64E87990BFC48703ULL, 0x423C4F4E63322EC2ULL, 0x55DE697007E1957FULL, 
            0x51E6A33BB375A9CAULL, 0xF8B93FC879DBCE52ULL, 0xF3A6EC6563244529ULL, 0xC265E6382E15A7BAULL, 
            0x3642A94284B5B79EULL, 0x9261281960BCB8CCULL, 0xB3CFFD8BED29EEF5ULL, 0x7DF2454ECD9DDF42ULL, 
            0xD9F8D43EF7D8EDCBULL, 0x5F4332BA69D2829CULL, 0x2600E610BECF82CCULL, 0xAFF4606839B113A6ULL, 
            0xA2502CC8628A27E3ULL, 0x4F244D0AF956A2A4ULL, 0x9A840ACAD825C9F5ULL, 0x9C4358281C40FA13ULL, 
            0x67D94251A08B0328ULL, 0xDAA84A2775392248ULL, 0x7F43C4AF1F55107DULL, 0xA94CCF1F0A4D3F70ULL, 
            0x5685C80DD0DB344CULL, 0x29A3ECF6B40CAB95ULL, 0x42DDE005962F6BEFULL, 0xB3F03E9A39E6FC5AULL, 
            0xCB4190700E82B52FULL, 0x74A69CD0DB359C5EULL, 0x6923AC5A0FF94F8EULL, 0xDE5F71B91438D55FULL
        },
        {
            0x63E79090D853E144ULL, 0xD7D4D2F39C890669ULL, 0xB970E2CEFB3CBAFEULL, 0x562E8E98C34A0029ULL, 
            0x995D6B11B3C9CC97ULL, 0x9444C5CE31AF3FC1ULL, 0xA3BC003A9CB413F1ULL, 0xDC5BDA9613DD399AULL, 
            0x2EEF405A8E5CCF52ULL, 0x7749103525E23A9EULL, 0x152104A7BBAEEF9BULL, 0x7917C0EDD660DEB4ULL, 
            0x39CE40BB7A273715ULL, 0xE3468D03827CA0EAULL, 0x7FDC3B663669EAE2ULL, 0x473F897AD3FE6833ULL, 
            0x204648E7CE39E2B7ULL, 0xE8473459FA192018ULL, 0x60B7B2A621642CD8ULL, 0x1B528E4A9AED99FBULL, 
            0x01689E88F2CEE429ULL, 0x14D1BC1CC4E78423ULL, 0xD3D744B41CD2AC4EULL, 0x6316B7BE94261650ULL, 
            0x37A3EA29452F6CDBULL, 0xD6796E62EBA07F2CULL, 0x09CBFEECDC0561FBULL, 0xA0BEA5A3336CA4B1ULL, 
            0x7162BE9C52CA6247ULL, 0x2081170E9992A0C4ULL, 0x105A0C9EB2D50327ULL, 0xA06B5EFCEEDC90B5ULL
        },
        {
            0x5CE7365EA9BCBB73ULL, 0xFC5FCDB6E506477FULL, 0x5BB5B5D025C6D36FULL, 0x4644985DB7A386AEULL, 
            0x3A536B47DBD959E0ULL, 0x7CCFEE5D6C050535ULL, 0x518A8968D7316D87ULL, 0xBF09B6CD8DEBD306ULL, 
            0x75BCE35BB767ABB9ULL, 0xD5D497EB938A72E0ULL, 0x1C629A46AE0401BBULL, 0x5E2F81D1E01704A4ULL, 
            0x8D42B2DF5FCD8BE1ULL, 0xFCE82F83591F2551ULL, 0x1EBF88709B78063DULL, 0x6822A1D7EE11713BULL, 
            0x13CE13F7127FF7AFULL, 0x0F84170161CED205ULL, 0x713D6E5FA563569AULL, 0x7148A19482C16DEAULL, 
            0xC44ED5B093C45637ULL, 0x8CB6D6458FE38BBCULL, 0xD967BCFAF3A7D5A4ULL, 0x65A43F2C8BE7B339ULL, 
            0x936D58A0DFBC9038ULL, 0xB7C4822D7AC9BE5FULL, 0xEFD7EB2637503453ULL, 0xD00611C8CEB59D76ULL, 
            0x7EA9DA87CBDD1E71ULL, 0x951F5F0B1060329CULL, 0x878A4E0ADA8AAE3DULL, 0x32F24BA9E0F96AC9ULL
        },
        {
            0x5C678A4C14B464E1ULL, 0x31B872E5414C2714ULL, 0x94DD6A639FAE0C82ULL, 0xC8BD203CBD694D6AULL, 
            0x513C9AE6C1E59EC9ULL, 0x8ECE1B86D886C194ULL, 0xE976339666C21A8FULL, 0x4EC8D2A5770121A4ULL, 
            0xA6BD6F38C33DA77CULL, 0x83C63F634ABBC00DULL, 0xA4C489A56AD99092ULL, 0x2093B5383976D347ULL, 
            0x07608429AA711A71ULL, 0xFCC047CF4A3EC48DULL, 0x60B34C100C02660AULL, 0xFAE7A740A68E437DULL, 
            0xDCF0364353010B87ULL, 0xAEEF4B7CF2552C69ULL, 0xA1AC68EB1915FF8EULL, 0xFD52382EDB4BDFB5ULL, 
            0xD13283B1D8588C16ULL, 0x979A72031783E08BULL, 0x1FB06D8A1A65DAE3ULL, 0x5E5364C2485116BAULL, 
            0x19907DDD6C5AF430ULL, 0x827796F8B3CE5648ULL, 0x6308362BAE350DBBULL, 0xE32F955BED307C02ULL, 
            0xAE042B83CE9D7427ULL, 0x0FBF27A7BE721301ULL, 0xF759B1CD7E910DB2ULL, 0xEBEC04A81FD10C94ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Regulus::kKeyRotateConstants = {
    0x496051307F8874BCULL,
    0x140DC2EAC036AB19ULL,
    0xCE522458CFF7B597ULL,
    0x496051307F8874BCULL,
    0x140DC2EAC036AB19ULL,
    0xCE522458CFF7B597ULL,
    0xA75E998E37F7B532ULL,
    0x731B7EA29047D8D1ULL,
    0x3E,
    0x08,
    0xB2,
    0x60,
    0x29,
    0x37,
    0xE6,
    0xD4
};

const TwistDomainSaltSet TwistExpander_Regulus::kKeySpawnSalts = {
    {
        {
            0x71A35E2A456BC95AULL, 0x4A0A2262087098D8ULL, 0xE7FDEE4508708945ULL, 0x3561EF4C770BE985ULL, 
            0x1F975B86896BB879ULL, 0x5EF119AD1153AFB3ULL, 0x587DC765C55CE201ULL, 0x9C7A9A2915544A30ULL, 
            0x4F59584D815C8B69ULL, 0x5CA477B50FE4210AULL, 0xEEF28EB109EDA87AULL, 0x375DC071BC36621FULL, 
            0x00B4844D2AB2DCBEULL, 0x38B2C5C9DB1B0F56ULL, 0x84BB1F71EE62BD37ULL, 0xF6A3B02F0F07751AULL, 
            0x591EB0CFA012143CULL, 0x357306A5734FB958ULL, 0x882ED080AF9E75E9ULL, 0xFEF187036865F123ULL, 
            0x101FAD7BC14D34F1ULL, 0x48640FB6D41A5AE5ULL, 0xC6A81F748B565EB9ULL, 0x61F5C64E632AB9BFULL, 
            0x1134E249E21CE62FULL, 0xE71A9FC6511A6F83ULL, 0xDE23833A491C1388ULL, 0x54A3945222F9492EULL, 
            0x82F294FDFD27C8A7ULL, 0x2C1B1642CD84262DULL, 0x0FC1FCCE3464EB0CULL, 0x331DB849730BA2F4ULL
        },
        {
            0xAE4822098FA79F29ULL, 0x9B5202CBE91211A6ULL, 0xE5A21B0AEE99BEC2ULL, 0xBFA5A1DB8DEB1A9FULL, 
            0xBBD5C0EC8E995E43ULL, 0x47C9CD88ECB41C26ULL, 0xAE28D977A33221C4ULL, 0x6580925336A9A117ULL, 
            0xF61137B8DE10A8A0ULL, 0xA6490A4BE7079710ULL, 0xC6B58A681459DA75ULL, 0x2DD5887ACF8DBF68ULL, 
            0x06C16FDB09669DEBULL, 0x974F028564450D6FULL, 0x8B9667C0A30F2645ULL, 0x36135701B14FA65FULL, 
            0x2F23A37949C8453BULL, 0x13D9CB20102E53FFULL, 0xC0125009AA257E97ULL, 0xBB654C45312B61AEULL, 
            0x8876C2E0CF493C34ULL, 0x5B507DBFB019CE95ULL, 0x178A8AF598FA5757ULL, 0x9D9E1D5292A268A9ULL, 
            0xFF3788F838F1FFFCULL, 0xE33251A591A6165FULL, 0x2027C6E27C7C85DEULL, 0x7C58FBE600A38E3CULL, 
            0xD2C17485515D8413ULL, 0x75329DD5316CEFF5ULL, 0xB85A858FD44CC759ULL, 0x7623F5404FC0DC50ULL
        },
        {
            0xB6A5D746F303D6C8ULL, 0xF62784CAD916FFC8ULL, 0x595288E1004DAD74ULL, 0x3DF947778B949A8AULL, 
            0xF0EC7BD8EEA74F66ULL, 0xB7DED0551C4F2A7DULL, 0x0AA8C5BE6E446971ULL, 0xD7B75D893F146F2DULL, 
            0x01E32DC8904210F9ULL, 0x6E9633C7C31C1B87ULL, 0xFA6B2755C0944970ULL, 0x1344B70C559631EAULL, 
            0x1D8909671EAC7D59ULL, 0x9226D4182E6663C3ULL, 0x3F7D7FCFA9139B97ULL, 0x505028B7C553174EULL, 
            0xCCF74D2409B60A10ULL, 0xB30A7C4BEB166BF8ULL, 0x632A901B7B6B7335ULL, 0x9497A43322D96C6DULL, 
            0xBDA78B8A0B2EEA97ULL, 0xC4465372B6B8EB35ULL, 0xBDA094BBBE3987A7ULL, 0x07DFDDE7D78486C2ULL, 
            0x0E66B099B03264BDULL, 0x42A5AB6FA3AC6514ULL, 0xE986CDE062F46FAFULL, 0x8581C809BFBE574AULL, 
            0xDE3F4CBBAD573AB0ULL, 0x65D728E3C7BB30E6ULL, 0x52535F4CC1DED537ULL, 0x3BDE509761D4D046ULL
        },
        {
            0x5EFDA516BBDCBDCFULL, 0x35588BBBF2481F16ULL, 0x03F60ED0CA68E758ULL, 0xEB691B732A02C9AAULL, 
            0xFADD02C7F39D5EBAULL, 0xEB98B984ED142187ULL, 0xA5390F5858AF7E6CULL, 0xC7B9663A908F331FULL, 
            0x6AC129337337A226ULL, 0x0E5EBFDFDE912761ULL, 0xDDD1CD77E7201018ULL, 0x37E85C6A77806F54ULL, 
            0x06238977997790FBULL, 0x64D3A4E2885CD185ULL, 0xF3CF4CFFE56F0C7CULL, 0x0ADD561DFF9F4CC1ULL, 
            0x6EF34A90185F9D4BULL, 0x1A4BE09C1DA842B0ULL, 0xC150AA374EBA1C54ULL, 0xAEFF0A801F16A24DULL, 
            0x4652BD949D45180EULL, 0x862F9668FEAA3C8EULL, 0x21954E1FBDCED67CULL, 0x52A1482DBADC66B4ULL, 
            0x0BDA8C0F439A68C8ULL, 0x114B6D68AA067290ULL, 0x2EFCA93532385DD6ULL, 0xC75FD12F4FB1B4E7ULL, 
            0x86A4DD49068E21D5ULL, 0xF7E60110A2FE50C2ULL, 0xDFDB35A4438F319CULL, 0x4337868E5B8BA1E1ULL
        },
        {
            0xB8E38FA604ABA627ULL, 0xEDA720BEAC2CEFF7ULL, 0x745FA091A1921E6CULL, 0x4AFC2BF65D9160A2ULL, 
            0x9C51522005764F78ULL, 0x7CAA291780198C25ULL, 0x5BF143283D0F6FF6ULL, 0xB54D62F97DE5E43DULL, 
            0x7E78293A737AE332ULL, 0xFA53FB351181368DULL, 0x4B144C7249B4536BULL, 0xC7AE3ED9D731B659ULL, 
            0x4632613F61FB0063ULL, 0x41D662D69F6CD046ULL, 0x0BDFBD7300017930ULL, 0x4A16DB56B723E4D7ULL, 
            0xF83ECC0D8A50C5FCULL, 0x3D8369B2BF16AE72ULL, 0x29E975F4B072F11BULL, 0x08F2E91D47FE0609ULL, 
            0x356A756322FB5742ULL, 0x565860B70D0EF027ULL, 0xC8F26B9C3EB1D943ULL, 0x7FF5D2A0E4F5DC58ULL, 
            0xA5CC078BBD086934ULL, 0x6DB320C0F34096A4ULL, 0x74F555B41D9F6F16ULL, 0xD9370956F88C6B41ULL, 
            0x5F3AC961B5F9BAECULL, 0xD0B1333DCAE9C727ULL, 0x8A970EF46280A6B5ULL, 0x3BE1B07E6D1BC662ULL
        },
        {
            0x4543904A2088780EULL, 0x0511BFBB2DD18ED0ULL, 0x17F7FBA30411962EULL, 0x0DDC19672D80352AULL, 
            0xEAF7388108342510ULL, 0x47D9BCBDEC95EF6CULL, 0x73180B734842A687ULL, 0x8A27C2C22D70972DULL, 
            0xBFDC32FBA0B7E47AULL, 0xC18AA938618371BEULL, 0xB4808A193C99938AULL, 0x400D06324FF527CEULL, 
            0x264D6183135ED743ULL, 0x12165D66D497DD2BULL, 0x2557EDB8EA8A010EULL, 0x096F6C0B454D17D4ULL, 
            0x82435D115AFC60FBULL, 0x93D869FEDEDFFBFFULL, 0x976E7FD8406145ECULL, 0x86398AB47845187BULL, 
            0xA420BA653060350AULL, 0x73F5232741A6BE72ULL, 0xF25BA18331DADC10ULL, 0xE9580E6F872653EBULL, 
            0xB0EF93EF08C37A61ULL, 0x2600EBF22A612842ULL, 0xFA4753AC534860B0ULL, 0x2299570C92655CE0ULL, 
            0x5C9CA1A070796215ULL, 0xB6503666A0A9D120ULL, 0x9D23BE2CDD5C6781ULL, 0x9AF68F8ACE4FE884ULL
        }
    },
    {
        {
            0x10E048D436C705BDULL, 0xA2FABC7288C2A374ULL, 0xE906C8738C489501ULL, 0xBC0B884EA11048E4ULL, 
            0x789D70DE72DE95CBULL, 0xC8ED1BACEAFA7140ULL, 0x7D2D6728D413F2A5ULL, 0x6B93A3F5D465B30EULL, 
            0x65ECC939056E06C5ULL, 0xCA179A2EBFF06FDFULL, 0xF69FBE5AC6E34119ULL, 0x03E4D4576843C46CULL, 
            0x8201845C6D4DFA4BULL, 0x2EFFF900DE596648ULL, 0x956637BBAA6D026DULL, 0x5F5286928F8C3C02ULL, 
            0xDEE185B3F445311CULL, 0x7F6057A99224317AULL, 0x32A1F63FD7438CA6ULL, 0xE1350B2E6F13A086ULL, 
            0x7422A624FBD5DFA4ULL, 0x2FC7EA83D83B47EEULL, 0xDBE46222C489AD03ULL, 0x8FA15C9BC3495190ULL, 
            0xDFCEA490D7DBD20AULL, 0x8E1878A099FC9287ULL, 0xBD28D869227E7704ULL, 0x5EF20FA817F54C11ULL, 
            0xAA1A5C6C352C0296ULL, 0xFB5C6020FE6B3EC5ULL, 0x8AD1E18C7DC849F9ULL, 0x2761AB85E7791F71ULL
        },
        {
            0x66E2E8564FE35388ULL, 0xAEA482E03CCA30ACULL, 0x5D0A7DE973AEB96BULL, 0xDA38F17D575976CEULL, 
            0xB87124B9312CFCA3ULL, 0x263BE7BB537207DEULL, 0x5F26069561DD4698ULL, 0x1F634736D3CF4A97ULL, 
            0x12929D40D15AE5EEULL, 0x76A57CD450F7AFD7ULL, 0x3D3D604F8560C6AFULL, 0x3D36C4D8A242C407ULL, 
            0x5564C9A60CC6F3C0ULL, 0xF8D018DCA4117583ULL, 0xAF1444024BF3B718ULL, 0xF9867DDAC623F9D9ULL, 
            0x862DD8F6DCD8F169ULL, 0xA5149EB8AD9425B2ULL, 0x1896101A2456FBAEULL, 0x98C8A429C8039074ULL, 
            0x0FC26484988AF6D4ULL, 0x13A946E877D62EA1ULL, 0x915D3DE1313562CDULL, 0xF60698736918EA59ULL, 
            0x4DA2F43327514D1DULL, 0x950AB763E8DE6732ULL, 0xF8C139855CB460D0ULL, 0xA79956DF5F4A93B9ULL, 
            0x3F087B7C906DE553ULL, 0x10B74EC769AF9491ULL, 0xB07E06EC54BF59B6ULL, 0xB97E5E367040DC14ULL
        },
        {
            0x7EFA6F47C84C3ABAULL, 0x8FBBAA1E9729F5C8ULL, 0x3110D793943CA84EULL, 0xA5277B8ED5341FFBULL, 
            0x4BFD49809F31FEC6ULL, 0x5CDDB82BFFC70B23ULL, 0xE26570AC0F69DF5FULL, 0xBFEA8C579CB4DEADULL, 
            0xE8E6AF6792C551D6ULL, 0x1696FC7E3325336CULL, 0x80C80B25771CDB0BULL, 0xB4B18FFD6D16E3C0ULL, 
            0x6598A39B6933EE3EULL, 0x71BB10D355F7AFBAULL, 0x3F2932355B79F3B2ULL, 0x993F2476B9583047ULL, 
            0x9ACE788B2BA16488ULL, 0x06926685ECFBFD37ULL, 0x922D013549132000ULL, 0xEA36C71D16A24F44ULL, 
            0xC84638A31D270C24ULL, 0x879362E75AB187B1ULL, 0x241DC9B1E330C083ULL, 0x894D0E8002D64070ULL, 
            0x172B8488BF1DF4E8ULL, 0x0735A5CABFA016DBULL, 0x6039A5B04E0E978DULL, 0xB9B8077140AEDA53ULL, 
            0x35B9F0FB29A42922ULL, 0x5E20F3132D913D00ULL, 0xFD1391C6C1FFFDC1ULL, 0x059D2E6B105C3529ULL
        },
        {
            0x7F94333EDBA080DCULL, 0xCBE576060A50129CULL, 0x4C585F39F65C7F45ULL, 0x37A8DAD563064022ULL, 
            0x309A35EA21E6972FULL, 0xF9FBAC1E3A5EEE78ULL, 0x1C59BEEFE106580BULL, 0xC14B1C3E4BEFF31DULL, 
            0x127998E662684F12ULL, 0x2A51432194620CEAULL, 0xC83735FCD9EFD4BCULL, 0x28E7DE10C9ABE2C0ULL, 
            0x2F6CF845703356E1ULL, 0x0430284E2CAD07CAULL, 0x2D3C336D156C325FULL, 0x4378BA1C8A8503D4ULL, 
            0x748582F8F131A861ULL, 0xAB4D2BEAC6C7311BULL, 0x170477CF429AFB87ULL, 0x1C10419189D1482DULL, 
            0xF431C9CE6A5E408FULL, 0xCD3C5C3F964FF0E1ULL, 0x68A0DE9CC6CF6D47ULL, 0x05DD3C3FBFF5B59CULL, 
            0xA55B1026C74763B0ULL, 0xA6D9E4B606C57124ULL, 0x7E7FF6002502074DULL, 0x00B5BDA20ECD5E93ULL, 
            0x0A2E91FFF8029BAEULL, 0xD1CEFD2A659D249DULL, 0x62E8C952C3F1D850ULL, 0x6D875A1245DABE96ULL
        },
        {
            0x3DC4F10379EED7AEULL, 0x7D92F5E22F4C3CCFULL, 0x6A3EA7A1AF97E638ULL, 0xE72E922AC41D95E7ULL, 
            0x4F289CA3B84EEA58ULL, 0x4BD94B1072239468ULL, 0xBC24A93AD75C01AFULL, 0x50D83E8D022281D6ULL, 
            0x092C9C1D61643E85ULL, 0x99948B365744A024ULL, 0x28092A4DBCC6D205ULL, 0xA2C21E2961136D7DULL, 
            0xD348444DCA5B3EE4ULL, 0x9C58A5CEB6394A38ULL, 0xFF6F96427D970E78ULL, 0x8DF36A933D68AA0FULL, 
            0x8F9EAFF57B286EACULL, 0xFDD67112E47683C7ULL, 0x2A3C826D62FE4593ULL, 0xF11E4762E3BEEF3BULL, 
            0xB66EC845889807BDULL, 0x4F5453AB2246F1DBULL, 0xD62F9EDF6B0B70CDULL, 0x0284A500984F4D6AULL, 
            0x05EC24B3AD33DFDEULL, 0xB7FBCE307923CAC0ULL, 0x60299F979AB3068AULL, 0xEF5725580DD68CF3ULL, 
            0x5667A6BE68506B06ULL, 0xEE07A9FD08356E1EULL, 0x6E631F4C71032AB2ULL, 0x1A901D064A038D34ULL
        },
        {
            0x3264233C9F56E34CULL, 0x1E4CA6FD46EE418EULL, 0xA109850388B0E950ULL, 0x89CDBC5F07C0BD35ULL, 
            0xD0B43AB0A33ECE59ULL, 0x6DAE4571D9835B5BULL, 0x110F30DA74E6862FULL, 0x951137712182B188ULL, 
            0x609120501B4FC132ULL, 0xD5553B806CD03FD8ULL, 0xEE156C9B4C8F187DULL, 0xEFDDBBCA1A29D634ULL, 
            0x68868F988DFF994EULL, 0x4BAD1732CAC45E04ULL, 0xAFDA0963DF6CC65AULL, 0x9AB443897556DA1FULL, 
            0xE93BA738DF643F46ULL, 0x44B2821A79332D78ULL, 0xC60B24136AB6E2ABULL, 0x95571C429D7A9010ULL, 
            0x177C11349C359591ULL, 0x4FC3D30F6CE1600BULL, 0xEC21486B1EB6382CULL, 0xAEBADD3579409BBDULL, 
            0x55FA960F82B5C3F5ULL, 0xDA131B23021B5E4BULL, 0x2AF8F8C20F60F448ULL, 0xB34BE7811060559BULL, 
            0x946E764F0DCB0853ULL, 0x4837DD42E04A1CBBULL, 0x11B2DE52A86B34B5ULL, 0x3C8603732F51CE51ULL
        }
    },
    {
        {
            0xDB45C6A0F0B1A2F1ULL, 0x866B07202F836B53ULL, 0x35FEE5EE70086B10ULL, 0x9B229F6172D51586ULL, 
            0xBB89F0D8E6533CDBULL, 0x186753D7A9D8C206ULL, 0xD3A215CDA041E56EULL, 0xA48B6D4F8EE65286ULL, 
            0xCFC6B4DB2065CDABULL, 0xC8A50FBB34C8E54CULL, 0xC82FD8E42BF9924FULL, 0xDE64C2A980FEE0ABULL, 
            0x64915DD4EF411788ULL, 0x0D2E063C3554CB6AULL, 0xD3185CC31E14E6C6ULL, 0x8C820A17741FB30BULL, 
            0x63FE022014C580D7ULL, 0xE53E129B38C06BD5ULL, 0x5B8A89D75C2068E4ULL, 0xB56072B4C39F7346ULL, 
            0xD68EC126DA53E492ULL, 0x241635628421006CULL, 0xE0CEB54C1C0BC452ULL, 0x9FA1FC7AC1E59479ULL, 
            0x9576E99BEC8FA727ULL, 0xD991AF31FF471048ULL, 0x5B5836CCCBE1AA7EULL, 0xECA5A6D3B35460B0ULL, 
            0x1CA36DF210A7803EULL, 0xF1326754DB34379DULL, 0x8891E7645119AC56ULL, 0x678F75E214182FD1ULL
        },
        {
            0xFA0509E8BE0C2E6AULL, 0xF7C89A67D6FEF9C0ULL, 0x783126840213B399ULL, 0x885C3545CB5CE1FEULL, 
            0xB2487F44B35DF8D8ULL, 0x5D8BBB612FBBC74BULL, 0x2504A7A5EDFE687DULL, 0xF57CB3DF707E6866ULL, 
            0xA83DE02ECCF1B355ULL, 0xF1595DF485045D57ULL, 0xC0029131034FA5FCULL, 0x26106694BFF219DAULL, 
            0xADE4D759F913CFDEULL, 0x006D1F794A11CF65ULL, 0x0F82DF89BD456F57ULL, 0x58FDE6CA5B467E1EULL, 
            0x7C1B2B0489F81435ULL, 0x6F7E0089FD49D761ULL, 0x6A4176D33C75DB7CULL, 0x021EABFC5322F295ULL, 
            0x25FA2FA6638DF687ULL, 0x0DCD572A66E33F1AULL, 0xA3B3929B3D992855ULL, 0x70E3EB7C806BF236ULL, 
            0xA37C9B78DDD8511CULL, 0x54A780DB2F5B1DA2ULL, 0xA872B769901FC17FULL, 0xA44C374FB36D47B5ULL, 
            0x731398E685F21D0EULL, 0x77124BBB36833383ULL, 0xDCA265B139FA6FF0ULL, 0xEE78BA85367CCB36ULL
        },
        {
            0xED8AB5E1CF7D14CDULL, 0x41C03F96475F9D77ULL, 0xCB635FCE268FDECAULL, 0x648BFE853C4E1EE1ULL, 
            0x6EE623EC766E3A85ULL, 0x2BB0F14EB85B8ADCULL, 0xEA1E142CFF161E32ULL, 0xB0D02A527EDB911AULL, 
            0x842DECF82CC9A44CULL, 0xC75A445EF61C314AULL, 0x85C7E03CA7EE0687ULL, 0x890462C9450DDD6AULL, 
            0x4D44FD635F800DD8ULL, 0xD0CFBDB39CB05307ULL, 0x605442BB65009902ULL, 0xC5DCDAFC9713A5E7ULL, 
            0xD9469E696EB59588ULL, 0xE1C8DA824F5E18AAULL, 0x6AA5753B8A88DE31ULL, 0x759AD65830F142CFULL, 
            0xCB2DC45D25443182ULL, 0xFFD6670BFDC4526CULL, 0x276AE574F9C81C3AULL, 0xFF7697471133625AULL, 
            0x9445F9C6A7F03049ULL, 0x3940F81161374A13ULL, 0x1913D1D9004F0A2FULL, 0xD01AB4D5D17ECF72ULL, 
            0x401FFB10785C5412ULL, 0x4CD63ACF1B5A4E23ULL, 0x79C348BA94AD0364ULL, 0xC3245C7F90006007ULL
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
        },
        {
            0xFC5C330F509194E0ULL, 0xDADA011AF3FF0F90ULL, 0x0DE9FD9FB17C2158ULL, 0x75B4A744F9D6148EULL, 
            0x781CC194DBCA6D71ULL, 0x886B2D7C63C355C9ULL, 0xCD3E004EEA278BCFULL, 0xD233F0D1C487D32DULL, 
            0xB51C114A684D3239ULL, 0xA00C8A14DBCD94FBULL, 0xE753163BB433DBE9ULL, 0xB0CB14D76B23AD4AULL, 
            0x406E41528D5AF6EAULL, 0x2E5E4EE61EEBC189ULL, 0x1D86CCF27A4BA3ECULL, 0x9C81AAE8E0134D5BULL, 
            0x72718D2EF6051242ULL, 0x978A8476B3399CB1ULL, 0x462F5F255059268CULL, 0x272D5052C585CE5CULL, 
            0xB74B8E662CD8813AULL, 0x871A5BB67AF8708DULL, 0xE9A46B325F7B2F38ULL, 0x6F3C86053E72067CULL, 
            0xC02BF0C834F5A5B5ULL, 0x078E213B5A45B4A8ULL, 0x70D97BAA3B55BA52ULL, 0x725C4C8FA2D0A319ULL, 
            0xBE96BF3FBAC25EDAULL, 0xA273B69C398DCD99ULL, 0x3A01BE9CDA008EA6ULL, 0x105CAB3DB2664623ULL
        },
        {
            0xC2F470FD48063103ULL, 0x257BDFBDEC635A84ULL, 0x2C89A155C7782E0FULL, 0x77EE8644B9832D7FULL, 
            0xBE86A390135BC922ULL, 0xB6AD8DBCA096FA23ULL, 0x7BC5014555A7E882ULL, 0xEF39FAD54F2005E3ULL, 
            0x5D61870B0EBEC6FBULL, 0xB29BC849D9D2FAE4ULL, 0x89CB955686404CA1ULL, 0x1C5BE3C092D6C3ECULL, 
            0x46DE1ADBB4F07FB3ULL, 0xBCDB8B5E44A9C8C2ULL, 0x71C49A9C382BA053ULL, 0x8A65014524A735FEULL, 
            0x817EB45B28CA3BAAULL, 0x68CAF2EC18415958ULL, 0x388B04528544F2C4ULL, 0x10B3991C65A40774ULL, 
            0x9E12BFD60F4C5D38ULL, 0xCB476D91F471A988ULL, 0x57292E221C340C90ULL, 0x85143B1F7EF8B8C9ULL, 
            0x24EAAE7E9A1FA39DULL, 0x137605F6BB8B9522ULL, 0xF7C5AFB12F5D61CBULL, 0x1C3ADF9426FD8CBDULL, 
            0xF83720DC93D2C0DFULL, 0x04262A6DC937DCE0ULL, 0x14E86B277F1F1A44ULL, 0x5AB65DBF4B4DF8D3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Regulus::kKeySpawnConstants = {
    0xF09B675B1AAEF29AULL,
    0x82E8FD86BF087DBBULL,
    0x3815B3CCAC7CF4D5ULL,
    0xF09B675B1AAEF29AULL,
    0x82E8FD86BF087DBBULL,
    0x3815B3CCAC7CF4D5ULL,
    0x2F361621DC5277DCULL,
    0x30D006DDF0142B5FULL,
    0x05,
    0xE6,
    0x8E,
    0xDA,
    0x22,
    0x19,
    0xC2,
    0x56
};

const TwistDomainSaltSet TwistExpander_Regulus::kSeedSalts = {
    {
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
            0x9394B46B5AA077F1ULL, 0xD4E1C859A3D0CE3FULL, 0xD860F839C3002532ULL, 0x9121A67B7228E595ULL, 
            0x4F5DA61EB8EFE837ULL, 0xD038631DA37B8A3FULL, 0xA06602DA7365770CULL, 0x21B69E84E6B7FEB9ULL, 
            0x14D343B30E6FF22CULL, 0xCB4AB5D6691A1A5DULL, 0x48A48C0684D7C89DULL, 0xB9C762E52C01C8F7ULL, 
            0x1BD1FEECDE37BD0FULL, 0x411D1FC676611E82ULL, 0x19D353CC154030A7ULL, 0xB466D2800F763E09ULL, 
            0xD759ABD4B38A30AAULL, 0xA1BC5E309CE02021ULL, 0x3DE523FC5B63F1CFULL, 0xDD0715CDCF312724ULL, 
            0xD406FFC9B1412AD9ULL, 0x48B9E350240586EDULL, 0x719C50AC1D045738ULL, 0x6CEF92C7351CB507ULL, 
            0x9E8A1E55C379A623ULL, 0x19C79145DBFAD37BULL, 0xD376FF706147A675ULL, 0xEE985A7CB7BA2382ULL, 
            0x998DAB1E203966C1ULL, 0x1DA546BD5B98FD98ULL, 0x559ADBC3C6E05FC5ULL, 0x377AAF6FD07B2646ULL
        },
        {
            0xE035A6F72DF3B90BULL, 0x45D1911F9009045DULL, 0x0DC5D30B73EC4254ULL, 0xFFCE92BD5A0D20F3ULL, 
            0xE0D59A9EC7C02323ULL, 0x504D7B6971AEE160ULL, 0xBAE40C8DC429BB43ULL, 0x0DCC15129FD39A29ULL, 
            0x6586733D59FCDE6CULL, 0xA28DA3729854A745ULL, 0x4A2AAD3886A23C18ULL, 0x10C1DA8B4A66C788ULL, 
            0x11BB596BC1E546F9ULL, 0x78019BE230F83D02ULL, 0xE5AEC03035402633ULL, 0x3F6F2FD2B6201992ULL, 
            0x650E0468AEB0E41FULL, 0x76EC89795D6E1E7FULL, 0xB9F28FF6B031734CULL, 0x4B4E24F95AD372DEULL, 
            0x03CE2865C74C7415ULL, 0xAC9F2A3888B702C0ULL, 0x7EF4AA6EF33829C0ULL, 0xE4359246E7859833ULL, 
            0xBCD0799D5511CE38ULL, 0x1EC1D72FCCC5C008ULL, 0x085EEE426118E590ULL, 0xFE1E39DB643ABCAFULL, 
            0x794BC3D3FDB9B238ULL, 0x64C6BC9D55DAA91FULL, 0x00880BD065C9E2E1ULL, 0x3B6D6A13174ED02AULL
        },
        {
            0xA0F446FC207F6CFAULL, 0xDA45588C48449216ULL, 0xAFD4883843F9C524ULL, 0xA091D4C7CD4AA7F6ULL, 
            0xFCEDD845DE2117F8ULL, 0x6F3F69541EFE7C7EULL, 0x31CF3BDB9B626B51ULL, 0x46B92A92E53F5922ULL, 
            0xCAA05E51C93821B7ULL, 0xD60D9686504796FBULL, 0xF455C5443B0C0626ULL, 0xEDEB6D16E172B1E6ULL, 
            0x538E38A47BB2DF65ULL, 0x4ACF75DDE3A0A1BBULL, 0xCD001DB00B5AA691ULL, 0xFB5E93A93C870DC7ULL, 
            0x92A78B2485B81C91ULL, 0x672306C15F871F5FULL, 0xD061641E48453673ULL, 0x336797A8E74B1B78ULL, 
            0xB2475C24A22E4E7CULL, 0xD5B5A0020DCE0E45ULL, 0x9C9A938F989DEADBULL, 0x849FEDE76730A222ULL, 
            0x8931587689F5D9FAULL, 0x15EC4FDFE8CC41B3ULL, 0xBB27BBBB3E3D2A36ULL, 0xE5A1D411AC028A47ULL, 
            0x8D32C99FAADEEDC3ULL, 0xD7A4B6EAB995BB95ULL, 0x9A288C43C9DA813AULL, 0x389996A4C32A41BBULL
        },
        {
            0xD8C6032777934ECBULL, 0x6F0A332AC2C8BB0FULL, 0xFF9169BAF29705F7ULL, 0xEEF6B87FB9C8AF2BULL, 
            0x2EF60101FE3F0DE7ULL, 0xEBBC1C4525F82533ULL, 0xF4BACF630B593C9BULL, 0x502B58ECB6F4F918ULL, 
            0xE35F295251C81164ULL, 0x24A0C6140BD16363ULL, 0x650899C46AA2F085ULL, 0xBA2B14BB3646C0D0ULL, 
            0xB8822A2B7D989A79ULL, 0x2146233BCE43DADEULL, 0x0567A125EE1FFA72ULL, 0x6521A7B9B48CF054ULL, 
            0xF457EAECA5A8C840ULL, 0xCCBA954309EE5249ULL, 0x387DE59AF1DA4B74ULL, 0x6D7F37D2CCE0937CULL, 
            0x94E1FE098E61A2A4ULL, 0x9CC31B2661742D89ULL, 0x08B4766B1B060598ULL, 0xBDA4709C2F23F902ULL, 
            0xA4DE9F5C709B8E32ULL, 0x183E4A35CEC71824ULL, 0x781EB80FB2EE6041ULL, 0x720EB280C543F0DFULL, 
            0xBF3C65A7F0CB1CEBULL, 0xE0AC472AF00FD845ULL, 0x3CA69D62C15A2812ULL, 0xEC36FDBFEBF0454CULL
        },
        {
            0x5357C8B1A68AA582ULL, 0x31880649457DF28BULL, 0x6F3589150FB0EBA0ULL, 0xA2CFB0BCDC42E7BFULL, 
            0xC2554562E755D0DDULL, 0x9726544C242F415DULL, 0x17F83E9B295585BAULL, 0xD98D5DA808892327ULL, 
            0x27955CADF4FA00DCULL, 0x5200FF2988EC19DDULL, 0xC4D3381DAA02C14EULL, 0x7142E4249E53F81DULL, 
            0x5F645FE55B8B4D94ULL, 0x3BB5A6DECD505A82ULL, 0xF0A57AFFCC14FFF5ULL, 0x65053BE968CE6CEFULL, 
            0x8514323DFA503FAFULL, 0x42E1A9FDC66E1929ULL, 0x55AA0B4707BFE715ULL, 0x80B7621962DD8702ULL, 
            0xE416816C0BF4A2E1ULL, 0x2042A16994A76DF7ULL, 0x4F2F2A1A9453E03DULL, 0xDECEE84C04A0203DULL, 
            0xC967A2156C7F4DD4ULL, 0x1DB5526289E2A86BULL, 0x50728882B024478AULL, 0x1AF6607AC6DD97C2ULL, 
            0x233F6CEB0B0B033AULL, 0xED267744876122A9ULL, 0x68432536F3EBCBE8ULL, 0x4928A0BE02052F3DULL
        }
    },
    {
        {
            0x79BA1A90F9E9A3D3ULL, 0x581C2B7E307429D3ULL, 0x7230B55C9C21AFDAULL, 0x10788327E66384FFULL, 
            0xEB8D4AC49F878021ULL, 0x86EBAC293FA53E17ULL, 0xA7F4B6E906D7B965ULL, 0xB57A2DA6D555242AULL, 
            0xAAA634732F2D6DA4ULL, 0x9E35452DA7A4A3DEULL, 0xE2DCC023D2E2A55DULL, 0x1ED24DCA135DD040ULL, 
            0xB30A84CB5A284017ULL, 0xB985922B8EFA74F2ULL, 0x7E2C6CBF2863C319ULL, 0xFCFD0F3ECEB71626ULL, 
            0xDF82E602450C3CB9ULL, 0xB1B4EBA99DFDF95BULL, 0x9E2108F8FF67A6CAULL, 0x685FB18E3874F8A1ULL, 
            0xA72A7FEB2BC314DFULL, 0xF7882B2B1BFE000DULL, 0xC311A9564C7A09D0ULL, 0x33D185BD9BB2EA6BULL, 
            0xC5A9AD1C13CC04A7ULL, 0x38F0A64A55CD1071ULL, 0x87DB9FF833B4000AULL, 0x1C925DAC79593F73ULL, 
            0x7AB38D5AC9914C5BULL, 0xEFAD1CBD6338F031ULL, 0xD0D5D610742CAFBAULL, 0xB2B9E83F18845722ULL
        },
        {
            0x6C08355FA5C98232ULL, 0xF92D547748488C14ULL, 0x363E2C68DFA85844ULL, 0x678C3173452A3515ULL, 
            0x5C12FCE6D3BB4FEAULL, 0x1327B61EE376E943ULL, 0xF505B5D2A945A01FULL, 0x403F95A1160EF30BULL, 
            0x8BE6BBC3E3CD983AULL, 0x92AC0F8557394491ULL, 0x24EC6F3550A63C3CULL, 0x8A15AA775E79C856ULL, 
            0x080CAB2A09F687E3ULL, 0x5D866399D20B37D2ULL, 0xD274BB1647991ADCULL, 0xF5440B36BBB22BBCULL, 
            0xA9EE0FDD6F8F37B4ULL, 0x92D8CEC162CFB5BDULL, 0x0062832F8E052B66ULL, 0x65A8C3E4D5389E49ULL, 
            0x61DB43A398E2498CULL, 0x59C16C94B7F4BFA2ULL, 0xE492CE3ACAE4F1BAULL, 0x87AA0A0BC38F66E1ULL, 
            0xCC7B392ACF1F865BULL, 0x7442929CB7460857ULL, 0x95B1916C170D0799ULL, 0xEBDEA7A9F7E76479ULL, 
            0x73BAFAE0C92598FBULL, 0x5E5BEE51F5800423ULL, 0xCA3657FEF28C651CULL, 0xACBF8D3C4173469AULL
        },
        {
            0xE0869600C38EF02DULL, 0xE2F4B0E8411BDF22ULL, 0xF75185EBE957FD20ULL, 0x4278FF3C5BC6DCEAULL, 
            0x9FCE46BC3C84ABD6ULL, 0xE0CA42A025098E90ULL, 0x6A9BEB845EFCA8A8ULL, 0x5839036357E96261ULL, 
            0xABC11F547E8B1D9EULL, 0xCBE4830D1B25F93CULL, 0x0163B02F61377634ULL, 0x4F39247202DD1B2EULL, 
            0xB6D22C7C0B4D9701ULL, 0x332E25CC8F02C996ULL, 0xED2163C28E3EE143ULL, 0x17DE9AFF7D1D857CULL, 
            0xA9EA3D1960087EBEULL, 0xCC6C6CC90AF250F5ULL, 0x849C34711FDA0813ULL, 0x4FFAAB1161A3604DULL, 
            0x41EB5F35DFDB5FD3ULL, 0xA47F67A77E211225ULL, 0x3CAFD4C0339C0601ULL, 0xE9DBBA8BB7A134E0ULL, 
            0x66EA34CAE78075DEULL, 0xC999CD67780FBDDDULL, 0x164F4BD399F611EDULL, 0xA49A329730A71C4EULL, 
            0xC1C85FA2B1F4467CULL, 0xFA14F13586842B63ULL, 0x2154F43284E1DC4AULL, 0xCD28E8BFF0611ED6ULL
        },
        {
            0x4BF4DC23BFF5CF72ULL, 0x7C3008CD389FD9D7ULL, 0xA03CBC39A970CDA0ULL, 0x172CA01A5D7811A7ULL, 
            0x2FEE94F5EE2D4FABULL, 0x1E50BE67B6B19EF0ULL, 0x35632AB71F293019ULL, 0x0D0A2D03CDB0AFEFULL, 
            0xA6C61BE475E33B7CULL, 0x36B7A0C75EAD6EDDULL, 0x90C2E074433B957FULL, 0xD4D0034F2831F564ULL, 
            0x3D11A8716DDA0BE2ULL, 0x32E1748DEAA7A94AULL, 0xF2626AE6752B118FULL, 0x25A64DF365507CCDULL, 
            0x0697B24D03AACFA3ULL, 0x6CD9B65B1D956EA1ULL, 0x23115DF801C0E5A0ULL, 0x958757004D8E1BB8ULL, 
            0x38A9644D16A6AF6BULL, 0x32BD3AF1FB6F8663ULL, 0x4A33BE9F227344EBULL, 0x7D77C20B3F0D96D3ULL, 
            0x97F4C0E705E7A43FULL, 0x1397AB1917E19221ULL, 0x3AF05A25CEC96EF4ULL, 0x338BBE1756C9A3FBULL, 
            0xBB451C3B7A60F6CAULL, 0x9D79A9F3FE9BB4B0ULL, 0xC01D9240943154ABULL, 0xBD01F5264B2EB688ULL
        },
        {
            0xD5A722FA97EE7E5BULL, 0xBDE62C7C012AE796ULL, 0x55F04327C4F946FFULL, 0xF411A34D0072B1B8ULL, 
            0x2BA668AE0B691185ULL, 0x1B2EC8EFBBB5CBFCULL, 0x3FEF16FFE39F731DULL, 0x8D1FF849A90140D3ULL, 
            0x77349CBD7065FA23ULL, 0x739DFD3F4F70B89CULL, 0xB3E06FCFDC570BEEULL, 0x54008857C1B37985ULL, 
            0xA38774FB6BA833D3ULL, 0x134E0434C3B986BCULL, 0xB04DDC216BB0EA09ULL, 0xE13D55F4ECB56623ULL, 
            0x3CFB072C1E5F6713ULL, 0x5453D7ACE1F7CA65ULL, 0x3FEFCBCF1915F0FBULL, 0xCD7E2DE671EC7472ULL, 
            0x8E1C502256018625ULL, 0x9AD4970C13614A8CULL, 0x2568E799602849A4ULL, 0x8887444153B182FCULL, 
            0xDE977AEED27D43CAULL, 0x317E5AA21019BFFEULL, 0x8A3D220219CBA4F5ULL, 0x87DB103E3988B190ULL, 
            0xD367A300FAFB6165ULL, 0xD1C3937787B60922ULL, 0xA75BFA04F49332E9ULL, 0x950B3C23A9180CC4ULL
        },
        {
            0xD608555C05752F3AULL, 0x4EC5E5ABFCB03020ULL, 0xD4F68412D7CB52FBULL, 0x25647B624B279636ULL, 
            0x3BB7F32E84DDDE26ULL, 0x9E676237634328DAULL, 0x1F05F08404607069ULL, 0x1F3DAA59323FC159ULL, 
            0x46F3F0292E6AE147ULL, 0xA063FEDDAB63AD91ULL, 0x80D4B126B7778E46ULL, 0xB70D425F5F25E334ULL, 
            0x6E2672270E8FF064ULL, 0x80103FAF3C231F34ULL, 0x9DC6F24EF5E86140ULL, 0xAF43C71BFDA766BDULL, 
            0xC9768149EFAA3D1EULL, 0x0D030B4C07A5DE07ULL, 0x8AA63BE52C4537B7ULL, 0xD406EF1043A7B83DULL, 
            0xA5ACB2200F9A0B80ULL, 0x1AB9770256BFC79DULL, 0xAC86A9995C4D2A53ULL, 0x74EA948802CAAC31ULL, 
            0x46B27E4DC3C3DB56ULL, 0xF6F478FF22250108ULL, 0xD981C844E9EFA44AULL, 0xA75CE6C97CB34AD8ULL, 
            0x3CAEA4F3A7A21B00ULL, 0x2F8A7D05CD4F5237ULL, 0x37AEFFFB5178B391ULL, 0x99371CF92B189865ULL
        }
    },
    {
        {
            0x4077E0E1D8928BD0ULL, 0xB8EB675315FBF83AULL, 0xEF5203C9BDDD2FE6ULL, 0x1B918249CC74A6D2ULL, 
            0x30817C3AF46C10BAULL, 0x4A19F34EDA03693BULL, 0x7FD2D296CE31941CULL, 0xEC62FD505037CDDEULL, 
            0x7FC05D69327957BCULL, 0x891CD59A73D37E2AULL, 0x8039AB52EAFE9D65ULL, 0x99D15C1FABEBF96FULL, 
            0x562DC417FE12C6E1ULL, 0x5968335E9844B0C4ULL, 0x53A3B407D5AE5D05ULL, 0xC156734A53FABA4BULL, 
            0xAEF9CD7101AEF4FEULL, 0x029DE37B087A5566ULL, 0xB223208EDC08B597ULL, 0x1C08BF3D7F122B15ULL, 
            0xFF6A1C4C9E36CCC0ULL, 0x2E68126883D88AD7ULL, 0x508F8F5A3A367ECEULL, 0xDF22621E9E587112ULL, 
            0x350EEDD4D7BE771EULL, 0xFB607025DC7B4E31ULL, 0xE80C9F47C4D3CFCBULL, 0x491EBDB264642FB5ULL, 
            0x193A9B52AD3C723FULL, 0x6086F9EF65220470ULL, 0x96EAEFC7D669BA0DULL, 0x29CBE34C890005A0ULL
        },
        {
            0x2574FEE13B4352A1ULL, 0xBC06A5974F01F563ULL, 0x446867F228A26052ULL, 0x2910EE0841B7C8BAULL, 
            0xE5E5129CFA613E15ULL, 0x30F1DBCC9B87E48FULL, 0x7CE6F74B9AD66F24ULL, 0x718E6B3A16171763ULL, 
            0x330975B43C35E128ULL, 0xE285517A45E1E2F0ULL, 0x5A842C7BF285CC15ULL, 0x6B9E83F6F8DF2AA9ULL, 
            0x69BAA7DF826FCFFDULL, 0x9795D0EFC1B978D5ULL, 0xE739A70D72114500ULL, 0x974CDB2C760E73AEULL, 
            0xB4A56939DC77E438ULL, 0x8300738CE6608209ULL, 0xFE521555D27E6482ULL, 0x4F6303CE1C1E3912ULL, 
            0xB13F705F36405D07ULL, 0x53B3E57D7D125C5BULL, 0x0F2E325809E2D3BBULL, 0x2A73B28E6AC2EF7CULL, 
            0x06D31A318DF0EE9AULL, 0x259754C394E52E37ULL, 0xA1D3EFF01DA39B8EULL, 0x22386E26664306E6ULL, 
            0xD964923F15CF412BULL, 0xBF5B0B8E419275B0ULL, 0xBF3E4A4439964ED8ULL, 0x4AFB1A569DA5E8F4ULL
        },
        {
            0x727CCD126E0D56BAULL, 0x81A3725F0E490BCFULL, 0x26846883DF15545AULL, 0x6EFF8B02C3052C21ULL, 
            0xC693DD71BB799B6EULL, 0x1F7157CC07C61885ULL, 0xA798D31A65A36EDFULL, 0xB5629FF0D211A7DEULL, 
            0xB08F11A76A7CFF65ULL, 0xECA0581AFE0024C1ULL, 0x01A27C1422AE9FF3ULL, 0x28BBD1C49F61404FULL, 
            0xD3DF92773083124EULL, 0x84A844B69430FB60ULL, 0x813B93702882933DULL, 0x27A1679AE9786973ULL, 
            0xDB0B61A14101ECB7ULL, 0xE07C6A3659C45CADULL, 0xCEBE4C903DCCE695ULL, 0x8B07C9A6174969E0ULL, 
            0xD171BDF775B11A09ULL, 0x4C4B3D531CF84504ULL, 0x6E1E61EC8550F499ULL, 0x95708BE517482CC0ULL, 
            0xB174BB3924F2D7F9ULL, 0xBD85EE1FEBB00807ULL, 0x128CB15EAAC46AF6ULL, 0xCF21130046246000ULL, 
            0xB6AF7200E990B0BDULL, 0x3C090DAF99224CA0ULL, 0x00F08194C37BCF73ULL, 0x06777668303A8BB6ULL
        },
        {
            0x28477EDF54A5FE33ULL, 0x437F0D0887C4F21CULL, 0x93CAFBEB246E5270ULL, 0x8FD357D7F45A2E9FULL, 
            0x197D8DC28221BC21ULL, 0xF1DFE23083847E12ULL, 0x832A7FAF658C08F6ULL, 0xBC00234404D5D4FBULL, 
            0x809ABCC02B8E065FULL, 0x02DFDD0256F6828FULL, 0x7749CCE10CC9CA8EULL, 0x3C7E0517F02F94E1ULL, 
            0x0A79F9A330F571ABULL, 0xBDD036255A17D352ULL, 0x6E8472024F0312CAULL, 0xF78A450DCFBDFE46ULL, 
            0xD3FDF3B6AB086CD4ULL, 0x7E5BD6670FC1F75DULL, 0xFD2DD742004D8BCCULL, 0x31F0E0E9E3E82D48ULL, 
            0xEC8ADDD20A7BCB2AULL, 0x5E75E8DD725DC4EDULL, 0x4D8C023AD08FB07EULL, 0x918030477D226970ULL, 
            0xD9A61CB42EF571FBULL, 0x8053C7DEEF4CC877ULL, 0x709C07401CED4278ULL, 0xBF6880E51EBC8DF3ULL, 
            0x4969B5230981CD9FULL, 0xB99A006CFE7B6262ULL, 0xCB0758F29C03855BULL, 0xA372D0AF74C091A5ULL
        },
        {
            0x482F8985AB55E40CULL, 0x7245107BAAEFCD16ULL, 0x74715D8F5962B7D2ULL, 0x0EF630480FEDE943ULL, 
            0x868820B934C4AFDEULL, 0x88EAA4B2829A2BDBULL, 0xEDDE2693818093DFULL, 0x9454E7BB656A03BFULL, 
            0xFE22D189B412EC92ULL, 0xF8AAEE2BDF300D55ULL, 0x55B7CC1F0FB03F78ULL, 0xEB80A11FFD4E39BBULL, 
            0x2275D8BE78606CD5ULL, 0xFED5BFDCCBCB63ADULL, 0x66258DC288662107ULL, 0x2933FE8C588141DAULL, 
            0x692B3B30AA5568EBULL, 0xBBC288426C48BAE1ULL, 0x5E62E6B9024F733CULL, 0xE5C52E3D6C9D1674ULL, 
            0x184881F0B53468D7ULL, 0x0F46E02EE7844EB9ULL, 0xFF2F6982FA8B4CE5ULL, 0xD9B2F912FCA5F2CBULL, 
            0x2FB3219716979F52ULL, 0x813D9B95A1CB2BEAULL, 0xF32F065B321C776DULL, 0xA9A710534D90FB0BULL, 
            0x42165F73C8AA74F8ULL, 0x33DCA33943EBE750ULL, 0xBB120DBD0503BFD4ULL, 0x5220B632E2E7F378ULL
        },
        {
            0xF8259D8404B06630ULL, 0x473BBB2F928E1638ULL, 0x5E2D68014EFE870DULL, 0xD91AE8E2415D194EULL, 
            0x1FD16D3D87C72AC7ULL, 0x7331690E49EFA26BULL, 0x72B34479946D3586ULL, 0xDB2619175652BA8CULL, 
            0x64F01890ED64D7BEULL, 0x66D5C64DCA7F88E6ULL, 0x15F3BD4389350AC8ULL, 0x56838E3CEE412900ULL, 
            0xB0833539E9F14E71ULL, 0x47A19F0AD57DCF9CULL, 0x9E4DD7447404816AULL, 0x766387D2B2C677C4ULL, 
            0x2525A55B4BCA8EB5ULL, 0xCB35907FA3F714FAULL, 0x0E277E801C46D5CBULL, 0xD41325323315F350ULL, 
            0x7262D22AB9A6C470ULL, 0x4A82C45916308623ULL, 0xAD243FEB00B1A115ULL, 0x5D387D9823B9752DULL, 
            0xDC63E8561F2AB313ULL, 0x9531252EFC3CB6ECULL, 0x73E288537C5B52D0ULL, 0x7D8A6B716EC9A780ULL, 
            0xE14AD29ADF22660DULL, 0x029C31644A8E1434ULL, 0xDDC3580FCD4DA785ULL, 0x26EF2DF80A7A00BAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Regulus::kSeedConstants = {
    0x1DC7AC59065DAB46ULL,
    0x108879A1F76014CCULL,
    0x067AABEB0CC1DA10ULL,
    0x1DC7AC59065DAB46ULL,
    0x108879A1F76014CCULL,
    0x067AABEB0CC1DA10ULL,
    0xF8AF97E83BF4A314ULL,
    0xE20C3CAB813B9D73ULL,
    0xFE,
    0xE8,
    0x9C,
    0x27,
    0xD2,
    0x65,
    0x98,
    0xA0
};

const TwistDomainSaltSet TwistExpander_Regulus::kTwistSalts = {
    {
        {
            0xE8A5A1B69AAF0939ULL, 0x671EA41C03398BF3ULL, 0xB3A70792578EE9FAULL, 0xC04AB2A173052521ULL, 
            0x42E2F249B02E7875ULL, 0x716AC0369078F1FFULL, 0xF488CE4B29627B71ULL, 0x627E812C7EA9F11BULL, 
            0x0B6AACD2B61F93FDULL, 0xFB2B5D42FA62090FULL, 0x691829D41D638661ULL, 0x4018233A6BE88640ULL, 
            0x5511190ADE7A0023ULL, 0x4C093DC80ED64E6FULL, 0xBA037A2D95363DE1ULL, 0x550E4E9A234AF7D2ULL, 
            0x70E8D0EC34F60C86ULL, 0x1DA12372ACE47028ULL, 0xA7861AEB56A1FA5DULL, 0x94A6B9FE7326BAACULL, 
            0xB02414028299B10DULL, 0x6720C42A8F0ED27DULL, 0x04AED2497FBC0454ULL, 0x897A2971B3FE6ACBULL, 
            0x7930A885A564FEFDULL, 0x7A90F5785012E8D6ULL, 0x3EA7A377D742153DULL, 0x935E12D5C30B2716ULL, 
            0x0565D8F8CB3AE10DULL, 0x92C9069F7A0E69F4ULL, 0x8277C188B00C53CDULL, 0xA7E8C9D1C0DEB9B1ULL
        },
        {
            0xEDC4D04A2D0F0E95ULL, 0xAB69D1F9D4321E27ULL, 0xA025043D6E36147AULL, 0xEFBF25F52E976A05ULL, 
            0xDD73DD30CBAE1F6FULL, 0x95951AFFD18FF1D3ULL, 0x8EACAC5D63468A74ULL, 0xCC92F7C3FC7CB0B4ULL, 
            0xB26C8EA37E1CC785ULL, 0x68C802A418B26389ULL, 0x8543C9F4215F8FDAULL, 0xA2504AF9A187180CULL, 
            0x4606185A5A7C934DULL, 0xA8570630D7185BFAULL, 0x739EF32273AEA3C6ULL, 0x739AED5BC99A0466ULL, 
            0xB120CA5DD098A152ULL, 0x818044C9B5DDAED1ULL, 0xDAE49E2B3D1E08C6ULL, 0xBF6B53A489A5F1D6ULL, 
            0x2C65019AB24C0D3DULL, 0x207D9D287F2880E2ULL, 0x8AF272641B93FAFAULL, 0x556130B0EE46A9DBULL, 
            0x19215940AA2321EBULL, 0x2072049C9729B45FULL, 0xE8C55C143FDF9C55ULL, 0x1AF7C366F1A8F537ULL, 
            0x5F32667A4EAA1CBDULL, 0xCD6D674AFF3873FAULL, 0xA906E80146F3EEAAULL, 0x0780DAE78884B7A3ULL
        },
        {
            0x9ED380EFFDA6D63EULL, 0x5D19B6E5F01B4686ULL, 0xF2895F01A4388AE5ULL, 0x4B17DE063E229C7EULL, 
            0x2BFF9C953231F464ULL, 0x6BE15DDA96A800D7ULL, 0xF00DB411613EAEF6ULL, 0xBEC18D36FAA615A9ULL, 
            0xFC3C25706F386682ULL, 0xDCEB4D76CC5D0FCCULL, 0xE4985EC4AFA4CF6AULL, 0xDCFB2A6BB43BE3EFULL, 
            0x19DF024B11CF70B2ULL, 0x45E461D3F75762ECULL, 0x2DC38712B837D7F9ULL, 0x3C9CA695BB96BBC2ULL, 
            0x3713CF1E44C0CC6EULL, 0x3AE927C721140D94ULL, 0x260A8DF7A4C3B5DFULL, 0x50FCB63F3410F07CULL, 
            0x5585148521292E42ULL, 0x04ED4695BAA10F98ULL, 0xAC2AF6328C44B9A7ULL, 0x07998E7EFF390691ULL, 
            0x1813B52F92BC6678ULL, 0x2ADA9E4A3A661D8EULL, 0xAEE55A4FEB0C44EAULL, 0x55C00CBAA4B2FF46ULL, 
            0xED0C7749EC4EDA19ULL, 0x145AB9656CCB8CCEULL, 0x0427F9E8C95DEAADULL, 0x9ED0AEB2320F8DE8ULL
        },
        {
            0xF5FA1658DF6FD51DULL, 0xEDB9B0DA117FF170ULL, 0x9D6F10965031BF47ULL, 0x70726219F3E5C822ULL, 
            0x4BD4D1512B0787BBULL, 0xD053C1C7F7EB206AULL, 0x6A80B69491C7200FULL, 0x7B83AEDF0FE41705ULL, 
            0x6E8A66F4505A310CULL, 0x3D34BF2CFA9F1E84ULL, 0x35E64AAA7C3E6F58ULL, 0x3C0E5C0136FDB7BEULL, 
            0xBAE955EA8368CB50ULL, 0x1181703F6715D0C0ULL, 0xA98D45BD90E88399ULL, 0x38BAD0802F74821BULL, 
            0x2B6B6E779F0E2C21ULL, 0xD734544B9E1DB321ULL, 0xF063796ABA9FC8E0ULL, 0x1978BC61925D6B3AULL, 
            0xC9FE1B06578421EBULL, 0x35F173898132062CULL, 0x898944AC55268DBFULL, 0x5E241A351341C45BULL, 
            0x474B650A1FDCB916ULL, 0xA096FB782234AF00ULL, 0x5E29D6CA8AE9381BULL, 0x04E93332050987F2ULL, 
            0x3AC1A6140141BC3AULL, 0x67BC26C993FE8D0DULL, 0x9BC72FC660887BC9ULL, 0x5D36F4855FA4C3C5ULL
        },
        {
            0xDBD21AD85989C776ULL, 0x9EF9B9B9ED1AB0BEULL, 0x67126450694A650BULL, 0xD50769E305703F77ULL, 
            0xDF8B9DC42E7A585DULL, 0xB39356D4DF32CF05ULL, 0x896FBC3AE6FC0C68ULL, 0x78557239C5F73C49ULL, 
            0x5BD036ABF6220EB8ULL, 0xEE8C0FAC712AA9D4ULL, 0xEDC0ABFE59464F16ULL, 0x8EDEF65F9E70B2EFULL, 
            0x3B3FAF533A443E66ULL, 0xE793271EB35B4BBAULL, 0x9D15FC75D17AEACCULL, 0x586C0EB17CEF873AULL, 
            0x3D9D2454E55A7C00ULL, 0x8CDF600440444DD2ULL, 0x3957496A4B6D7424ULL, 0x27659BCAC7767C71ULL, 
            0x325A19CF162F6A17ULL, 0x90334AF4DBA0A1ACULL, 0xE3D698186065EBDCULL, 0xBFE961E45C678E26ULL, 
            0x96CB43A4F09A64C2ULL, 0x50E52CE844630C07ULL, 0x706F1D634F992D3AULL, 0x05A14FF929C2026EULL, 
            0x91A13D44135DD1E6ULL, 0x0B5B0ACFC562C279ULL, 0x76DC4AA9E8321300ULL, 0xBED8A61BE686C32CULL
        },
        {
            0xD58F167F25D6D100ULL, 0x9E9348938F1370E2ULL, 0x7B0849A6D49998A8ULL, 0x2C525E7CEF622AEAULL, 
            0x71AAD0E2F04845F7ULL, 0x8EAA24687A8ECB52ULL, 0x5F47752E3446B3CAULL, 0x840D22E470DD0933ULL, 
            0xE542855343A2BAD2ULL, 0x0F529830F1468293ULL, 0x9459A998F62C7F5DULL, 0x6E64A6A8AC6E0B6CULL, 
            0xBEAE0748162E539FULL, 0x4A101AE8E2C2E437ULL, 0x5D8AD60625F04043ULL, 0x851BE4C210089464ULL, 
            0xF891B5E54315467CULL, 0xAD0B50DEE2A0C656ULL, 0x70B1683F0B638957ULL, 0x95BDCD396A866ACFULL, 
            0xDA5D70157C32517BULL, 0x786F8CB82D62147BULL, 0x7B05F7D860C1460DULL, 0xC19DA5FB3EC719F2ULL, 
            0xBD8CB9FA92E4FA80ULL, 0xF6A6F5D62D2A8B83ULL, 0xAD1254BC61770898ULL, 0xFF9B12F31A7CC457ULL, 
            0xE3A21BAC08344166ULL, 0xC92934225A32E9E1ULL, 0x00DEC0926BD04650ULL, 0x9D83ECFCD7BB8247ULL
        }
    },
    {
        {
            0x4441F749E53C637DULL, 0xCCC76A409D277D22ULL, 0x219E7E2154B4D0D5ULL, 0x3F12E4E2C0160CC1ULL, 
            0x9FBB5160A0FEFE31ULL, 0xF45A3BFA7EB5B9FFULL, 0xA6FBD9EA2FD6C454ULL, 0xB4495068C077AF5CULL, 
            0xB595D7D80F1328F2ULL, 0x604B6F526F575233ULL, 0x07D32A3372CD8800ULL, 0x849828535D938FB5ULL, 
            0xC8D772551EA3F8DFULL, 0x1EECD7EAEAB6F25FULL, 0x59568A0508645D9FULL, 0xAE273834FFBC69C5ULL, 
            0x0910588CCDC2ED94ULL, 0xB2DE162C256AEFA0ULL, 0x9824CADB5ED39A44ULL, 0x6583F56F290DEBC1ULL, 
            0x8995453B0A3B75DFULL, 0x7B43725013D9A485ULL, 0x4D18BA8ABDA3296BULL, 0x7DBCA0FFAFEF8852ULL, 
            0x9E11E65173B16605ULL, 0xDD6FB052C075023CULL, 0xDDDF480D230C36E4ULL, 0x6E04BFD63FF49FAEULL, 
            0x0A680D0CDF60A892ULL, 0x101EB5C78E48849EULL, 0x703D1D2EC96B18A1ULL, 0x858700A126EEB81CULL
        },
        {
            0x896E40FC022B3666ULL, 0x8C6268F2059CD2A1ULL, 0x5100B4B30F8DEB74ULL, 0xD46860A561C33F92ULL, 
            0xDC72D87778AD0D17ULL, 0x38097FC2F3D2C007ULL, 0x62E7EA09546F157FULL, 0xF7B8DE6F0D60D8F1ULL, 
            0xF02952B2D49DE0C2ULL, 0x45B7D598E4AE83A5ULL, 0xCE93ACBC4B73254EULL, 0xDA92ADBE232BD388ULL, 
            0xD125E1078C6E8CCEULL, 0x7C73B9F4A25F4B17ULL, 0x8BB0909442CC22A0ULL, 0x404EF6FF6D544E8FULL, 
            0xC9244D89D931D0E7ULL, 0x4223577979ABE6BCULL, 0x9D97A29776F60755ULL, 0x30E3FE139EA52CECULL, 
            0x1396155311C1EA15ULL, 0x397E6428B3198309ULL, 0x35A77F5EC95213E4ULL, 0x4106C43E6AE917C7ULL, 
            0x04165D7F02455973ULL, 0xDB145FD6F96F5FB0ULL, 0xDAE1F841B6A3AD49ULL, 0xBCD2EAFFE9EFD2BAULL, 
            0x82C6314364E534E3ULL, 0x856521180CFC074AULL, 0xB43516C79551617AULL, 0x544CC439ADE8AFAEULL
        },
        {
            0xEF57D5A27F101EC8ULL, 0x4DD5951B719F465BULL, 0x9F74E523D97F9565ULL, 0xB23602DA463B9C62ULL, 
            0x848F0C65848AE8B5ULL, 0x49AA37718A116EE7ULL, 0xB156F68C262A47A1ULL, 0x0EE02F24A772D61FULL, 
            0xA8816D258371D19EULL, 0x657A9C56C3C2FD5CULL, 0x2A80C80ADF23903FULL, 0xC06F3C96302C7F7BULL, 
            0x3171F8F209D50D21ULL, 0x60D98C4F3BFB3022ULL, 0x42F267628A214D8BULL, 0xAFEC6627FA7EC9FAULL, 
            0x9E6E6393253DF2D6ULL, 0xD49F7CD1E34DBFCBULL, 0x9050FBCCE84E5D5CULL, 0x098DC7CEB59920F9ULL, 
            0x23CF08A34CAA8AEEULL, 0x31AF63E42FBAC726ULL, 0x0C08A63F5E56D52DULL, 0x7E97D9536EAD4145ULL, 
            0x7D7ADC92A594E81AULL, 0x85081DD2650136B4ULL, 0xE02CA1546E9C2983ULL, 0x743833CEEADEA5D8ULL, 
            0x1A91B18F833DF0F0ULL, 0xB2F6F58D5FDADA75ULL, 0xFD5D14057A115289ULL, 0xC685FC4F11BF19E5ULL
        },
        {
            0xF600E8754DA86A9AULL, 0x87883195C81652F6ULL, 0x0ABAF7A8CB48A736ULL, 0xA5F67F9DE3C8E1CBULL, 
            0xBC7ED6ADBB1EF1F5ULL, 0xBE8FA9CFE5726110ULL, 0xC8851849124EC8B3ULL, 0x83ADE56E302A04C6ULL, 
            0xF165689F9E88A38EULL, 0x8435B53D8B145623ULL, 0xEE602A585379BC65ULL, 0xE196C0595D2DA0C4ULL, 
            0xD7DF2DD3B49FBB74ULL, 0xE9591DE7700722B7ULL, 0x35246C322DB914B8ULL, 0xDABB998FE3E065A2ULL, 
            0x3F6BDEC600CCC16DULL, 0xF3E2C5008ABE719EULL, 0xC062116E126CEA94ULL, 0x37911C1E3FAD31FBULL, 
            0x6B4A14CB98360EA8ULL, 0xC274CF80DE243C05ULL, 0xDF0D8B74C31DF48BULL, 0x5E956FAB439E2EEDULL, 
            0xC18BE1207EB5E1F3ULL, 0xA08080B391A362F0ULL, 0x3BC021A95275CBC3ULL, 0x35264300EF741D33ULL, 
            0x58B2DA27DD980C11ULL, 0x9BF3AB0074972029ULL, 0xB58F7EC0C872F290ULL, 0xF2192C81CF921204ULL
        },
        {
            0x4571830479E965BBULL, 0xFA259498AC214FDDULL, 0x34DAF4F53C7FC3F7ULL, 0xF45D147C6B17DBF4ULL, 
            0xBA4A692FD4C824F8ULL, 0x200117B9BFBFE674ULL, 0xB28BA7ED9BF8DB97ULL, 0xA3B3F1C1BAFD2670ULL, 
            0x547B590E4DBAFCECULL, 0xEDBE65A1A8F99A20ULL, 0x4F4494832D83428DULL, 0xA72A13FEDD0899A2ULL, 
            0xBDE3AE2F96C77D69ULL, 0x280ED062B8828916ULL, 0x87A5BD5D184196A8ULL, 0xB4D882A38733024DULL, 
            0x42BF9DF27858CA8EULL, 0x40F281F41248F9C6ULL, 0xF773B84A5DE82E0BULL, 0x4C214C17871AF186ULL, 
            0x6A38B64B28A9595BULL, 0xB53FF6AAB5033E3EULL, 0x000233F9FB09B547ULL, 0x1FA5C2267A59368DULL, 
            0xED20B6930A9F745DULL, 0x6F3D24031A215FF7ULL, 0xFB23A6F00008B3C0ULL, 0xFE77987C0D10E87BULL, 
            0x8ACB6A8FA10A32C5ULL, 0x2AF7A34F202F5113ULL, 0x945A507F91E8456DULL, 0x3002974CF833616FULL
        },
        {
            0xEEE87C044A53BF89ULL, 0x8F594019BCAE62CAULL, 0xE25061B1955BC41AULL, 0xE222E636847F404DULL, 
            0x700CF23F5F789F89ULL, 0x822A376F69E40130ULL, 0x3027F2C99D9A36C5ULL, 0xB223C39D75FFC25CULL, 
            0x19C6DE668F980148ULL, 0xF73DD9E00F00C61CULL, 0x5725F05541FE65EDULL, 0xB5168098532D9FDCULL, 
            0x712FE9735F8589EDULL, 0xBB92FE8EF80DF4D1ULL, 0x200AC95E843A8D2AULL, 0x1CFFDCA7798F33EEULL, 
            0xDDBD0AF09670BAB8ULL, 0x80E93ABBBC0F25D8ULL, 0x712296B722B6DCD5ULL, 0x3F95CE4668E354D3ULL, 
            0x3D6AD04CF43D577EULL, 0x5153BC81B2A533E7ULL, 0x1CDE3ED355F1ED1EULL, 0x255B06DB1639FA45ULL, 
            0xE01F14EF088B6EE6ULL, 0x74FD9730DEE6FA7DULL, 0xF367B8959B172BDDULL, 0x9AD722640FC038A1ULL, 
            0xCB0537B1D9BE2195ULL, 0x3931C75E33FB14B3ULL, 0xE6D2E0E74AD705D6ULL, 0xFC3E18C1F94D108BULL
        }
    },
    {
        {
            0x2F9ED342CE5887BAULL, 0x7B62E9CF67604AB0ULL, 0x27EE47E5AFE1111AULL, 0x4E53037624D81104ULL, 
            0x735AD196EB98BC36ULL, 0x907A652AD84B131BULL, 0xA6AB4DDA3F5A3452ULL, 0xF7A657947C00ABECULL, 
            0xC9F542AE293B1960ULL, 0x537457FC86820222ULL, 0x87B7E7ED25FFDB42ULL, 0xA448D55282F51763ULL, 
            0xEA4B646BA6D99D3DULL, 0xAC2ED70246CA82DBULL, 0x6D2FD87BEC0BBE9FULL, 0x2926DD1D8A5827E2ULL, 
            0x002A202FCB58100BULL, 0x324BE8F2E94CB078ULL, 0xC9744184E417C737ULL, 0xFB70E7398CC57DCEULL, 
            0x58A386D752D29A4DULL, 0xD4BBB4A2CB30A114ULL, 0x6C0542515EEBCF06ULL, 0x7964EE7AE49E5AF7ULL, 
            0x3D80F496D214F87FULL, 0x8C8EB9ACDCF4AD15ULL, 0x61CB6370E678461AULL, 0xDA30263EE0E98447ULL, 
            0x79A5BDFF5AB913A3ULL, 0x03A50F1829558E25ULL, 0xC10697E3F0B40B9FULL, 0x780D0957D3E610C6ULL
        },
        {
            0x1188B5E2944F3E63ULL, 0xE70A479459D6F036ULL, 0x70BE953C876EBF33ULL, 0xD475EF82CE96C705ULL, 
            0xB1B6083C184484E7ULL, 0x3AF7C20C62DBB2CEULL, 0xBE0D36D0426B9F47ULL, 0x86144E0CAE86DA3BULL, 
            0x4808B9EAB9C83B4CULL, 0xB867D0C4C4D01271ULL, 0xAF0CF51F5C542C8EULL, 0xE7C409F1F797E9B9ULL, 
            0xC38EA8C6FB360C51ULL, 0xB6079798E078B866ULL, 0x5BE4E094C6DE1BB8ULL, 0x0A385A6652DA1916ULL, 
            0xEA49759F03CF46F9ULL, 0x03180E63D1B65272ULL, 0x05C65AAE7E726303ULL, 0xFEADCB30C52BC720ULL, 
            0xD611584C991D876DULL, 0x0BDAD1CF428857ECULL, 0x63B6F9B7A28C4BEDULL, 0x1A69DB2BE1CFF155ULL, 
            0x7AE79EFD6C334B30ULL, 0x2D9F8D215C588996ULL, 0xD1B90A03D1D12F9AULL, 0xDDD6B92CB61EF06EULL, 
            0x49AE8C3DF60DF1C5ULL, 0xA7D65447CDD6F450ULL, 0x5AA91125F839ED14ULL, 0x16189AA4A2D91113ULL
        },
        {
            0x17399A5862BD679CULL, 0xF768754149678131ULL, 0xDE567E00678ACC54ULL, 0x712384B0B3143824ULL, 
            0x57783CBDE5F5C703ULL, 0x28C0A798D9EC99CDULL, 0xE246BF523192AF7BULL, 0xDBA68C0859D56BACULL, 
            0x55061086C184D73BULL, 0xD087510320316CDCULL, 0x44A86578273BE0A2ULL, 0x25BAC94142AE72F7ULL, 
            0x3BA9495AE01F6D84ULL, 0xE1D6A536E44EF99CULL, 0x742A138237D5DB4BULL, 0x68BE1907EA175BAFULL, 
            0xFC8E70665C59DD85ULL, 0xC00B58E24B11E4A2ULL, 0x51C25F1C3BCCA29AULL, 0xDFD9EE63E0140A84ULL, 
            0x365CA2360394F6F7ULL, 0x83EABE70660C6233ULL, 0x8500601864556E90ULL, 0x6DC352FF4404953EULL, 
            0x6A5B612A859224D5ULL, 0x46855D66D80EC37AULL, 0x45D41F96C871B622ULL, 0xC255D939A3B0452CULL, 
            0x82EDC35BFA8B6B67ULL, 0x49CD3D6B931A40CAULL, 0x8E69DDFFD8E43253ULL, 0x437D865DF4A335A8ULL
        },
        {
            0xE5E66576FA33F9C9ULL, 0xBE83A747E1215A90ULL, 0x2735812FADD3CF4AULL, 0x545E7566AFFEDB0AULL, 
            0xAC4DF76EBD481A4AULL, 0x931DE7B0F76C3958ULL, 0xF8F74E3585D1CD7FULL, 0x57D97E3D450A945AULL, 
            0x6441E72F11F0DA6CULL, 0x5E3E9FC3EE3AD4AFULL, 0x7E36E39C5E71A98CULL, 0xE214886E90B1E3E6ULL, 
            0x591438540D6C78D1ULL, 0xF2EC5DB70E9D395EULL, 0xDCDAB9E3A744A51AULL, 0x1F9D67DF4CBACD0CULL, 
            0xA3680BDF485D1307ULL, 0xA86C93C8F38A9E18ULL, 0x89C2DC8CD7EC8239ULL, 0x812F9926759B553CULL, 
            0xAC6D02BEBB26EDE8ULL, 0xAC6835B247C6502BULL, 0x247E8039A2AE226CULL, 0xCD8A7309F1693761ULL, 
            0x13A71F64BD899A91ULL, 0xD4AC8125579C3494ULL, 0x817AFA1DD7B8C1D9ULL, 0x3A33AC53ED5C56C0ULL, 
            0xF1BBD28A8697AF2DULL, 0x95716D22462B8CD4ULL, 0xCF090ADD7C1D7DC5ULL, 0xE5018BBB2D853B8AULL
        },
        {
            0xF6D4B493D500F4ABULL, 0x47DD1CDFA3A47DD8ULL, 0x355F92C1C7D1719AULL, 0x80FABA7CAF81616AULL, 
            0x9D0142DF08F566ABULL, 0x13B615AF21F484BCULL, 0x786FE67E52C9460EULL, 0xE565E857FAD8E499ULL, 
            0x113B1992AC4B81C2ULL, 0xE0B0B0C9DD62908CULL, 0xFCC7A4BAC93CC14CULL, 0x812B067B63550725ULL, 
            0x567945A1BC1E12FBULL, 0x4FEBE1649C7A84EDULL, 0x8D25E488A33B1A45ULL, 0x6CD4D5B793A15B75ULL, 
            0x1409652D19B6E526ULL, 0x62BB5E2646A57523ULL, 0x404E3EAC3AC73DF4ULL, 0x37B492108ABD6297ULL, 
            0xC779685E0277937BULL, 0x8AB9DB4CCE73A722ULL, 0xB194D668AD8B64EBULL, 0x3B2DB58B7EC43A4AULL, 
            0xFF501552570E7A08ULL, 0xEE438011022AA990ULL, 0x3F70D36D2B7CF387ULL, 0x51F88444C51523F7ULL, 
            0xEAF65073A3878E5AULL, 0x106EB7E5B1EC8FB5ULL, 0x53BEB4BE2E9B201BULL, 0xD24F05C681C14177ULL
        },
        {
            0xB7091A68208CFA20ULL, 0x8F63EAFB33926D87ULL, 0x27628B3BC7B88269ULL, 0x4A7AB7445E7B4DE9ULL, 
            0xFC75B3567C3F2B91ULL, 0xF2FFA93B49574E72ULL, 0x73B9F6B10596E0DFULL, 0xA01658909F8C1276ULL, 
            0x6D528A88AC803FE3ULL, 0x2C6B6BCCBED0E7C3ULL, 0x77C6850976510F5FULL, 0xDA83C2F702B73634ULL, 
            0x02D2A8EEA80FC73EULL, 0x2F20BDBD7288BC55ULL, 0xF1E373282DF04DF4ULL, 0xFB908ABC782854A1ULL, 
            0xD149026CB498AF9EULL, 0xD7FCA2B2B558CEECULL, 0xB394F0E8B81D903AULL, 0x5B35CFDC9310257BULL, 
            0xB8E8091668678321ULL, 0xA535F514712F997DULL, 0x358A624008CDD0B2ULL, 0xD8F6ABF7A7FE6B9CULL, 
            0x391AFC00B95A0255ULL, 0xADFBE5C3620B1C46ULL, 0x5A92052FEE5FF74EULL, 0xDE6FA5D2F911151EULL, 
            0xE4FE8CBACE7D9139ULL, 0x1F3FE9FB475435CDULL, 0xF01EDB6342218B30ULL, 0x59951AC0CE9DA8B0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Regulus::kTwistConstants = {
    0xDC630FC1682CCEC3ULL,
    0xB2F6EC65249B24ECULL,
    0xD6D1EE8FD0E1D812ULL,
    0xDC630FC1682CCEC3ULL,
    0xB2F6EC65249B24ECULL,
    0xD6D1EE8FD0E1D812ULL,
    0x76BB46F2FAE3F118ULL,
    0xB4BC55B9608F6A02ULL,
    0x21,
    0xBB,
    0x9B,
    0x95,
    0xC8,
    0xD1,
    0x33,
    0xFC
};

