#include "TwistExpander_Pollux.hpp"
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

TwistExpander_Pollux::TwistExpander_Pollux()
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

void TwistExpander_Pollux::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF098973BE6660AD0ULL; std::uint64_t aIngress = 0xAF2144D0D85092A4ULL; std::uint64_t aCarry = 0xEB6A99F2554E17A2ULL;

    std::uint64_t aWandererA = 0xEB35B96131AFB3EDULL; std::uint64_t aWandererB = 0x9C2F7001D7A93C06ULL; std::uint64_t aWandererC = 0xB1BC061E0CA0374AULL; std::uint64_t aWandererD = 0xB8C329758DA5AA32ULL;
    std::uint64_t aWandererE = 0xB6F0D09FAFAD8C24ULL; std::uint64_t aWandererF = 0x99134C4BCD199DA7ULL; std::uint64_t aWandererG = 0xC55209879875CB1DULL; std::uint64_t aWandererH = 0xED0589D6C4FF93C9ULL;
    std::uint64_t aWandererI = 0xBF0B033765DF645CULL; std::uint64_t aWandererJ = 0x9618F8EC27482E89ULL; std::uint64_t aWandererK = 0xA7352A52E4B472B4ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xA2A98AB26A64F948ULL;
        aCarry = 0xE88983A901C31863ULL;
        aWandererA = 0xCDE0C026E1BC2A8DULL;
        aWandererB = 0xE6E2A1BC2289146CULL;
        aWandererC = 0x8A6137D11FA27518ULL;
        aWandererD = 0x83EAD8DF818A8615ULL;
        aWandererE = 0x907E1BDD34DE429AULL;
        aWandererF = 0xC7606514B86F4389ULL;
        aWandererG = 0x816736EB9E03F9BAULL;
        aWandererH = 0xB80A2545548936F3ULL;
        aWandererI = 0xC5D98F679700CF6AULL;
        aWandererJ = 0xB7AF769FA317F50DULL;
        aWandererK = 0x912C5D9ECD5BB49FULL;
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
    std::uint64_t aPrevious = 0xFBDB7F256DB8BD8BULL; std::uint64_t aIngress = 0x8373ACA20B0BA926ULL; std::uint64_t aCarry = 0xF2B608423AFD7FFAULL;

    std::uint64_t aWandererA = 0xB0C73A51C5785747ULL; std::uint64_t aWandererB = 0xB190E3096A5A3614ULL; std::uint64_t aWandererC = 0xDABDE62A08837857ULL; std::uint64_t aWandererD = 0xBC16CEB78620E2EEULL;
    std::uint64_t aWandererE = 0xB4774A0601B165CFULL; std::uint64_t aWandererF = 0xC17B4B1E387FB6B4ULL; std::uint64_t aWandererG = 0x8A716390D490C5E1ULL; std::uint64_t aWandererH = 0xAEBA59A3CE5B636BULL;
    std::uint64_t aWandererI = 0x81E7A72AB8B7DA95ULL; std::uint64_t aWandererJ = 0x817BDD3467E68577ULL; std::uint64_t aWandererK = 0xABE9D2D24CD91512ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xCBC9AC6C8D556050ULL;
        aCarry = 0x9482DA29F453E062ULL;
        aWandererA = 0xFF0B5617ADF2F75AULL;
        aWandererB = 0xA9C311A7F448BEC6ULL;
        aWandererC = 0xE6F35BBE53E88E26ULL;
        aWandererD = 0xA881A18F46936FA2ULL;
        aWandererE = 0xE0F930A11D98863AULL;
        aWandererF = 0x905AB2F78DAB8A99ULL;
        aWandererG = 0xAA7FABAEE2F10D69ULL;
        aWandererH = 0x85DE479A06F320C2ULL;
        aWandererI = 0x8F32185A8EC8CC74ULL;
        aWandererJ = 0xD640E8ED7366C043ULL;
        aWandererK = 0xAEE8705A9C6DE796ULL;
    TwistExpander_Pollux_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Pollux_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Pollux_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Pollux_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Pollux::KDF_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x815B2E7A0A9504B1ULL; std::uint64_t aIngress = 0x8A94CF48F27FFB62ULL; std::uint64_t aCarry = 0x8BCDC0F27E2BEF94ULL;

    std::uint64_t aWandererA = 0xCB63B2D6F29EB9BDULL; std::uint64_t aWandererB = 0xD6B106509E4983EFULL; std::uint64_t aWandererC = 0xE948ABFF5212C875ULL; std::uint64_t aWandererD = 0xCD130A40B8E1F849ULL;
    std::uint64_t aWandererE = 0xE383F206F528FCD3ULL; std::uint64_t aWandererF = 0xA19A3BE90D52F396ULL; std::uint64_t aWandererG = 0xEF2DE846F731F604ULL; std::uint64_t aWandererH = 0x9C3DD675A29910F4ULL;
    std::uint64_t aWandererI = 0xF35823170618A00BULL; std::uint64_t aWandererJ = 0xB34B3B37D8A6191EULL; std::uint64_t aWandererK = 0x989AF2270F1F9495ULL;

    // [kdf-c]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x837F00C19E2C2F51ULL;
        aCarry = 0xF36BF9BA67987F4EULL;
        aWandererA = 0xA076324440596D72ULL;
        aWandererB = 0xAB7DB6647D3016CAULL;
        aWandererC = 0xBA98D76FA2E69143ULL;
        aWandererD = 0xA2F69E6549A6D111ULL;
        aWandererE = 0xFCA3A3F3E7683477ULL;
        aWandererF = 0xEF698BE9E6BFDA25ULL;
        aWandererG = 0xF5DB7E3064B1F0A9ULL;
        aWandererH = 0xFE2111631AFB4D29ULL;
        aWandererI = 0xB7866A28B0E8FA13ULL;
        aWandererJ = 0xB268748E13097447ULL;
        aWandererK = 0xB16C353FE3B49947ULL;
    TwistExpander_Pollux_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Pollux_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Pollux_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Pollux_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Pollux::KDF_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x85800EED29C38238ULL; std::uint64_t aIngress = 0xD31D7800FF6C42F6ULL; std::uint64_t aCarry = 0xFE648584585F7C21ULL;

    std::uint64_t aWandererA = 0x808EBD562E03B37BULL; std::uint64_t aWandererB = 0xC18CE1FBDACBE601ULL; std::uint64_t aWandererC = 0xDC599DBD7EB1FC76ULL; std::uint64_t aWandererD = 0xC01695F9FD5D3A1BULL;
    std::uint64_t aWandererE = 0xCED4A3AD94F75F25ULL; std::uint64_t aWandererF = 0xBA8F2C9685158B62ULL; std::uint64_t aWandererG = 0x98113AF114FB7C8DULL; std::uint64_t aWandererH = 0xDA7DE4B97D558649ULL;
    std::uint64_t aWandererI = 0xFD6EACA0D202168FULL; std::uint64_t aWandererJ = 0x9217C185ABAEAFD9ULL; std::uint64_t aWandererK = 0x97050C432DC614B3ULL;

    // [kdf-d]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x903B45DF55934308ULL;
        aCarry = 0xD1B857C34B0D12E8ULL;
        aWandererA = 0xDD86916C854A4549ULL;
        aWandererB = 0xF4D7BAE5F1BF6B8FULL;
        aWandererC = 0xC75A800F521665DCULL;
        aWandererD = 0xA64711DF31CE1CBAULL;
        aWandererE = 0xF32513C6593B3B5FULL;
        aWandererF = 0x8D5C696F847E2808ULL;
        aWandererG = 0xAB19DA611E9672BAULL;
        aWandererH = 0xF7E0F360E431DCA2ULL;
        aWandererI = 0xCC6A3E36DC1E3339ULL;
        aWandererJ = 0xAF709DFF45F21FDFULL;
        aWandererK = 0x98537FD0C9DFF046ULL;
    TwistExpander_Pollux_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Pollux_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Pollux_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Pollux_Arx::KDF_D_D(pWorkSpace,
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
    std::uint64_t aPrevious = 0xBA949B55B7AD66C8ULL;
    std::uint64_t aIngress = 0xA68EFB941F7EFE21ULL;
    std::uint64_t aCarry = 0xA0BD46E1A564A30FULL;

    std::uint64_t aWandererA = 0x88F2C5F159A04853ULL;
    std::uint64_t aWandererB = 0xE9E9048D0D31B72BULL;
    std::uint64_t aWandererC = 0x8B869437EC205074ULL;
    std::uint64_t aWandererD = 0x8077E2FDDC8E3644ULL;
    std::uint64_t aWandererE = 0xF06970116B5F87A5ULL;
    std::uint64_t aWandererF = 0xC0989CC0AC224347ULL;
    std::uint64_t aWandererG = 0xF8427D23AB327F14ULL;
    std::uint64_t aWandererH = 0xF5FF5B81960F437EULL;
    std::uint64_t aWandererI = 0xEAEBEA3F695E4C6DULL;
    std::uint64_t aWandererJ = 0xB1D43931F12CB627ULL;
    std::uint64_t aWandererK = 0xD246FDF2E60B93D4ULL;

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

    TwistExpander_Pollux_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Pollux_Arx::Seed_J(pWorkSpace,
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

    TwistExpander_Pollux_Arx::Seed_K(pWorkSpace,
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

    TwistExpander_Pollux_Arx::Seed_L(pWorkSpace,
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
    TwistExpander_Pollux_Arx::Seed_M(pWorkSpace,
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

    TwistExpander_Pollux_Arx::Seed_N(pWorkSpace,
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
    TwistExpander_Pollux_Arx::KEY(pWorkSpace,
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

void TwistExpander_Pollux::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xEF2D2B60AD5C9ED1ULL; std::uint64_t aIngress = 0xC9948B000347CF63ULL; std::uint64_t aCarry = 0x8F7F304BE1CA10CDULL;

    std::uint64_t aWandererA = 0xDD82BC01F7F15292ULL; std::uint64_t aWandererB = 0xCF3FCD36D34BD9DBULL; std::uint64_t aWandererC = 0x8F6A59899A7C1BADULL; std::uint64_t aWandererD = 0xF6384D86DF06C22CULL;
    std::uint64_t aWandererE = 0xBD424E489EE69843ULL; std::uint64_t aWandererF = 0xF6F93FA2893A705FULL; std::uint64_t aWandererG = 0xA918B17F72BD1B33ULL; std::uint64_t aWandererH = 0xEA579CA8B81684F0ULL;
    std::uint64_t aWandererI = 0xD9830B04AF6C23D1ULL; std::uint64_t aWandererJ = 0xA1F834F5E9F8A2BFULL; std::uint64_t aWandererK = 0xBECBE5FA29D96A34ULL;

    // [twist]
        aPrevious = 0x91FE36BD624E80F7ULL;
        aCarry = 0x98E498A5D3B2E81CULL;
        aWandererA = 0xC4A172AF1006E0BEULL;
        aWandererB = 0x88E843C799AB5096ULL;
        aWandererC = 0x839DD8EDD82735F7ULL;
        aWandererD = 0xACE2B607DECC56A7ULL;
        aWandererE = 0xF7607DE54859283CULL;
        aWandererF = 0xAE949B75AFF615BDULL;
        aWandererG = 0x877ABDFC4E6DDDB7ULL;
        aWandererH = 0x8BC29EF72689A928ULL;
        aWandererI = 0x950952828D54913CULL;
        aWandererJ = 0xC8CE08C4D0921E3BULL;
        aWandererK = 0xEBDD71EFA0D3C6E3ULL;
    TwistExpander_Pollux_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Pollux_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Pollux_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Pollux_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Pollux_Arx::Twist_E(pWorkSpace,
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

    TwistExpander_Pollux_Arx::Twist_F(pWorkSpace,
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
    TwistExpander_Pollux_Arx::Twist_G(pWorkSpace,
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

    TwistExpander_Pollux_Arx::Twist_H(pWorkSpace,
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

void TwistExpander_Pollux::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Pollux_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Pollux_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Pollux_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Pollux_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Pollux::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Pollux_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Pollux_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Pollux_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Pollux_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Pollux::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 25 of 33
    // Exploration cases: 0
    // Structural maximin 506 / 674; family total 12677
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
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7879U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3648U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8149U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3828U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 137U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3558U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4008U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3738U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1375U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1915U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1870U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1600U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1465U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 92U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1645U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1330U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1825U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1555U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1690U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1735U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 25 of 33
    // Exploration cases: 0
    // Structural maximin 506 / 674; family total 12817
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
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7069U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3468U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2838U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3108U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7159U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7249U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1150U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1285U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 475U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 790U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 610U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 565U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 520U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 925U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1105U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1195U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1060U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 745U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldSeedControl candidate 25 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1048 / 1248; total 25863
void TwistExpander_Pollux::FoldSeed(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1916U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 588U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 768U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1826U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
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
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1871U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 160U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1173U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 633U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1646U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1398U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1623U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 318U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1353U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1668U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 948U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 363U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1263U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2006U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1218U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1938U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 678U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 295U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1533U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
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
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 205U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1038U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1308U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1443U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneG[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 70U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 340U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1848U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 903U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
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
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 543U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1691U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 723U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1128U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 183U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 93U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1961U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 48U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneJ[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1781U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 453U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1713U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1578U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneK[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 273U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 115U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 250U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 858U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 408U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 813U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1083U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 385U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2028U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1758U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 25U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1893U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneN[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1736U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1803U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 228U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 498U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 993U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1488U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 138U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1983U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldTwistControl candidate 25 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1052 / 1248; total 25869
void TwistExpander_Pollux::FoldTwist(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 521U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1714U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1849U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1151U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneA[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk B
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 611U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 949U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 71U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1354U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 566U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 116U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1669U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 161U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1039U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1061U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 386U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1444U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1421U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1286U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1511U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1084U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1106U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 701U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 994U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1129U) & W_KEY1);
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
    // FoldTwist — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 926U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 296U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1534U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 904U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneG[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1489U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1894U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 859U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1264U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 476U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1556U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1376U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 431U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 746U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1196U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1624U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1399U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneJ[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk K
    //
    {
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1241U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 656U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 881U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1309U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 814U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1219U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 341U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 26U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1601U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 251U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 836U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 971U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1174U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1016U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1579U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2029U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneN[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1759U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 791U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1466U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 206U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
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
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1939U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1984U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1804U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1331U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

const TwistDomainSaltSet TwistExpander_Pollux::kKeyRotateSalts = {
    {
        {
            0x6FA51BCCCD49D41AULL, 0x42416F94DF1BBFADULL, 0x3E02C766790CE0B9ULL, 0x0C8F013607C78D2DULL, 
            0xF4A2E6B5DBE7D600ULL, 0x079F12892BCF34EAULL, 0x1FEDA5731F5AA3C6ULL, 0x31AE68D6380D2B7CULL, 
            0xDEC8F3F8766FDFAEULL, 0x8BA2C8F3F29CA7C8ULL, 0x855DAEB6691F16EFULL, 0xB9606CBC088F3CA1ULL, 
            0x2651ACFDBBC7FFB4ULL, 0x5B271D221998E35BULL, 0x49C452E15FA66416ULL, 0x06E109F947DA4A2CULL, 
            0x9E486A5C8EE352DEULL, 0x75A96264FA31C270ULL, 0x4C1B8586C1235D28ULL, 0x6A9F2C2B6DEB50EDULL, 
            0x21B5FEC0CF069221ULL, 0x894ABDFAD1AC3C79ULL, 0xA60F193C9DBF39E9ULL, 0x31339515442800BAULL, 
            0x6A380483CA0A540CULL, 0xBCB25EEF25F31A65ULL, 0x8D6F6EC48594581FULL, 0x7B25ED805192A78EULL, 
            0x1A5A0909E6778742ULL, 0xA1D7556DBB967F70ULL, 0xE89862E09267F868ULL, 0xEF2A2282ACC56199ULL
        },
        {
            0xBC3CD61071ABD722ULL, 0xF1C2AD3BC5A56ECEULL, 0x213EE4F0307B46B1ULL, 0x4F18568D15B6092CULL, 
            0x3B355336049AC821ULL, 0xAD43483CBEACB186ULL, 0x2F39C854CB75C5EFULL, 0x6804ED964B016D4AULL, 
            0x92499CE4D13BDFEDULL, 0x266BB1DF842DD7BBULL, 0x24D4009E82F34992ULL, 0x0F317F5B7F19899AULL, 
            0xA6E55B16C846DC45ULL, 0x923BA5CBBD9FE69DULL, 0x7DFEDE0EC1961E6BULL, 0x28DEA06F26DEEDBBULL, 
            0x0F559E8C6B7F2FBEULL, 0x0A375BDFC017CC62ULL, 0xA0942B3354D22DFFULL, 0x6FB0BD4930BE58BAULL, 
            0xA2118B3EE8D690CDULL, 0xC08297B28371CB94ULL, 0x1EA206AE6AE69E8EULL, 0x730D46C317F58864ULL, 
            0x2302F97D5D7F6D04ULL, 0xE33CEF999B2467F3ULL, 0x6288F849485A5735ULL, 0xCCCC08CC6351BA1DULL, 
            0x770F5E78B9D55255ULL, 0x92DA5A13665A0FFAULL, 0x8C7B47B2CBDE36E2ULL, 0xBD6553B3C27C4BBFULL
        },
        {
            0x1C7B2EC753492D0AULL, 0x8B1EF5D3F3BDE378ULL, 0xEF59AC11A1E0A543ULL, 0x16B57010A4F63158ULL, 
            0x3FCC14ED90B2BEEEULL, 0x1319DA95D92C7313ULL, 0xD97B3746EF433637ULL, 0x38517F79895FBD39ULL, 
            0x615FA9BB42581987ULL, 0xBB60FBBD079A8748ULL, 0x0AEA775606AFDD9DULL, 0xAFCF9563E5652C73ULL, 
            0x21A0FC0BF0B4B571ULL, 0xCC6923E62CCC315CULL, 0x43BC577E01621B61ULL, 0xCFA94E1B6CB2D4CFULL, 
            0xAA17BCFD03F82736ULL, 0xBDF3B58E912C49DBULL, 0x661302783177B2B7ULL, 0x0C48154717EC271BULL, 
            0x546FA3E4A29BB06DULL, 0xE0764ED7BDAC6F9EULL, 0x4B0B63DB2ED27379ULL, 0x00FE0840E30A10FEULL, 
            0xC311BBE5F59992A4ULL, 0x5BD9CD03D6F3A058ULL, 0xCE8A8DCD0488684FULL, 0x2F0EEB82F4D44BA4ULL, 
            0x17C0705AE8B69290ULL, 0x6E34D19D2453B36BULL, 0x3B9A94048189F444ULL, 0x5D4E200400B937D9ULL
        },
        {
            0xAD41F5ECFCF176E0ULL, 0x7252C2E1A982F724ULL, 0x2594C8BB76F9BF52ULL, 0xE0565EADE6866F1DULL, 
            0xFA70D661E3BB05AEULL, 0xC9E1BED833B2A92BULL, 0x74A3C0A5D49E6804ULL, 0x534C0989FB576AF8ULL, 
            0xF32840E8A0911D23ULL, 0x791FB3D9C65EE10FULL, 0x206782716152ADABULL, 0x6D6142188635A20BULL, 
            0x1FF563F23811BA7BULL, 0xF7CF2E47BEDD4E2EULL, 0x7877836613AAB208ULL, 0xEF3843F4B43B9DD4ULL, 
            0xEB27BD11D5BF37ADULL, 0x0238AFFB4CD4CD5BULL, 0x79C4BBC2B206B9C2ULL, 0x4F4E4B1542B4FB44ULL, 
            0x3FD090D759F6E240ULL, 0x63033E2B0AB7A300ULL, 0x9CFB5F4AB4419F7AULL, 0x5B0577CE106BBFE7ULL, 
            0x1194DAB0CF3BEFE8ULL, 0x1E901716A01F3D22ULL, 0x8FED642B1B00B4C7ULL, 0x6367B437DDFDDCE8ULL, 
            0x8A3B473BA84EE2EFULL, 0x071D4BBAB855B14DULL, 0xB7009150BC73EA53ULL, 0xBACE046C7525BADBULL
        },
        {
            0x4D9F2DDCB6A5526EULL, 0xA353676B06B00810ULL, 0x4948CEEBCAC828E5ULL, 0x20BB9164F0AF56DBULL, 
            0xEC47725AEBBEFBF4ULL, 0x9AD540CD8A099EECULL, 0x19F67EFA83EECC7EULL, 0xFF897A63FBE24124ULL, 
            0xBBFC47C276E94C9EULL, 0x750FC60CA17F8975ULL, 0xFF76BA2F26EE9423ULL, 0x8DA3D6A8927B0F75ULL, 
            0xF7BADA96BF6E92C6ULL, 0x43A911CADD918F7AULL, 0xA471CB5C1F9CE7F4ULL, 0x1A544390F004971FULL, 
            0x96A1CFE220286B2CULL, 0x9B6E0A959C385FB8ULL, 0x025CDC53D6A6703EULL, 0xCF1C1F5DC377270BULL, 
            0x3B50E953E27639AAULL, 0x904EA37A17B9EB16ULL, 0xB7411FAF468BF150ULL, 0x1201DD42EA58077FULL, 
            0x9489F119D672734CULL, 0xB9E2639A51E71662ULL, 0xC89D326276ACAC07ULL, 0x39E7C823186B2620ULL, 
            0x3DEC8624D1BE2CE7ULL, 0x4F8F1ACF1AF3CFCAULL, 0x167D8A3320A584EAULL, 0x40ECB1D9C95236E9ULL
        },
        {
            0x00F7CC800BFBD7D1ULL, 0xE73F93C890D1B2A3ULL, 0xBD457CA598230F15ULL, 0xF92D14087412A7E3ULL, 
            0xB31AE251E5496FE2ULL, 0x6F9D47CA7F286531ULL, 0x7E644164E1E2DDDFULL, 0xC884FB93D70E499EULL, 
            0x4BCEB5C21D0CD64CULL, 0xD83D9D8679D571E2ULL, 0x432E985675F79A57ULL, 0x05E0B02861CA6982ULL, 
            0xEDD2BF6CD69746B4ULL, 0x9869390396E50A78ULL, 0xEE2A58315A1EB470ULL, 0x7EA468BE11A7D56BULL, 
            0x9FE2FAB5CB595907ULL, 0x2ED804049A014381ULL, 0xF3750D3837FFA0CCULL, 0x1E52A0F8744A6E4DULL, 
            0xF3C22E93DB1DD17FULL, 0xFB037BBD6F8B389DULL, 0x9D413117AEB19F86ULL, 0x432F4C51AD4FA17DULL, 
            0x55A4A470152A5A27ULL, 0x02C7F61C8223D39AULL, 0x6BE2735F98F59FB8ULL, 0x1A5DC6C6F659087CULL, 
            0x37A72B807D68CDBDULL, 0x5BB260E6BDE6A62BULL, 0xCA15401227CEF85AULL, 0x966872B07591438EULL
        }
    },
    {
        {
            0xC99EB0BECB58B97BULL, 0xBA0A093B5F742F71ULL, 0xF8E2C566924E8352ULL, 0x446C96C2986B07CDULL, 
            0xB164A3653150353FULL, 0x5195A274CFAE6B5FULL, 0x1DD28E8B324C365BULL, 0x5C2F01A13AC12E6AULL, 
            0x86BF1A5894ECB222ULL, 0xEAC3790877A923FFULL, 0x81331BD0E6D44CE4ULL, 0x31BE32A4A0CB7CB2ULL, 
            0xF83F854FACA85492ULL, 0xE7134769C01679A6ULL, 0x51388E2B2973EBA3ULL, 0x4F70D9064890D21FULL, 
            0x9A6DA5C55C110060ULL, 0x8D6F50ADB89A7AE0ULL, 0xB60083C556FD8737ULL, 0xA74D26FB50C99502ULL, 
            0x722DD71913869889ULL, 0x5A2353E8C2E78733ULL, 0xC98084AE58682A59ULL, 0x3D3790440C9CACB2ULL, 
            0x15618858BEFF0B01ULL, 0x78B1A9C39033F344ULL, 0x9D5285378854B15AULL, 0xC67B2F4AFFC1D724ULL, 
            0x63F4F7E8B639E5D9ULL, 0x0A89D773350B6B8CULL, 0x5BA9D53EB4B653B6ULL, 0x7F0BCCD70C98130FULL
        },
        {
            0x62B77A8AC61E7AC4ULL, 0x679EA9EBCE7E62E6ULL, 0xB153481C2C497615ULL, 0xD478537920E41AEEULL, 
            0x6833F65FD30CE87CULL, 0x06651298C3B07B83ULL, 0x3246F919D17B807EULL, 0x37268706963BFA84ULL, 
            0xD78283CD641E0E96ULL, 0xB84F7AF93B34B479ULL, 0x4BACCB1E0DDBE25CULL, 0xA8D491C96517845CULL, 
            0x710F22153A4C4446ULL, 0x68628290766882D2ULL, 0x34D6A3077EE1F852ULL, 0x3D2D81E4CA9A63AAULL, 
            0xFB170D9094348F66ULL, 0x9D399619B21D9C4FULL, 0x2489092202443539ULL, 0x3AE88A6D3E66C236ULL, 
            0x933E3767485AAB42ULL, 0xB9BDD7633144E2BDULL, 0x2B0AF2B89225534AULL, 0x409F5BC68DF67D3DULL, 
            0x4103357CFF47DC1DULL, 0xC89F6487C1BBCA2BULL, 0x7552A187CFE0FAE1ULL, 0xC9E93B6C48B77713ULL, 
            0xD9B0911BCF6BAD5BULL, 0xFC5C2BB7EA1A6514ULL, 0x51EDC0601C3DD905ULL, 0xFC9CDC3ABA1FF8B1ULL
        },
        {
            0x5700E758E8F3476BULL, 0x4DCA81D1A8F32152ULL, 0x533ABDC886D0C062ULL, 0x0733EFEB46AFF804ULL, 
            0x65CB7551DF6F5658ULL, 0x73584EA0CBB8F77CULL, 0x2A86D382C678E014ULL, 0xBB8E24DD665E9DFEULL, 
            0x6C56658E8E8FC790ULL, 0x107075A58ED89A77ULL, 0x0B15C526F9A58089ULL, 0x8DA159D296156293ULL, 
            0x88667399FB2F6732ULL, 0xB7A4F3C15AE08C66ULL, 0x5F1BDBBE1E67B8E1ULL, 0x9F173B97265331CDULL, 
            0x5315DA4161BB745EULL, 0xA6E4E6369A4F40CEULL, 0x43D583DE7275BEEFULL, 0x071716F3228544D4ULL, 
            0xCCB90351A0E8B33BULL, 0x3E8819F15FFC89B9ULL, 0x506BEA349DD2D4A9ULL, 0xC8B757077F0CD0CCULL, 
            0xD8709D5898DCCF52ULL, 0x00FBEC77815AE956ULL, 0xF89674F375BC7C1FULL, 0xC27BB155975F5A57ULL, 
            0x2469AD763A34B48FULL, 0xCCE055C736369EBFULL, 0x30C7C940CBC8E580ULL, 0x1AF063EA651BEE5BULL
        },
        {
            0x64346E266C9B6CF5ULL, 0x51665D196803A7B4ULL, 0x1559FE457AAA216AULL, 0x5561DDD16019386BULL, 
            0x26145127CBC8161AULL, 0x64645E3F4745D0E9ULL, 0xA97652068CC627CAULL, 0x374DB7D1EFE5C5C2ULL, 
            0x361BE863AD85C14CULL, 0xF483BF2A1CF5F48AULL, 0x3AACB0755010ADE3ULL, 0x4E598391A406A9F8ULL, 
            0xCE27E12DCC78E9D5ULL, 0x68093A97496D3FB2ULL, 0x763D12C9428E79D6ULL, 0xCA2C47E01D20AEE7ULL, 
            0xB4C518CFFF9DFC60ULL, 0xABC00168E10947EBULL, 0x2160579C006B8C00ULL, 0x774A1B1F6D4C2BBBULL, 
            0x07C22C1F14F64F42ULL, 0xEF158714F33CAF89ULL, 0x293502F0F7467DD1ULL, 0x45854018F78B5D54ULL, 
            0xF62C01AE3B3514C0ULL, 0xB027B1198B249744ULL, 0x4EA3FF511743479DULL, 0xE99A3694A2E3375AULL, 
            0xDD0F9F4033512B4FULL, 0x58BDE45F4587ABC7ULL, 0xF3D7BAD72ECBDB74ULL, 0x59421FF5F7DC7943ULL
        },
        {
            0xB85CDA79047E2694ULL, 0x7D8EEE28F3FB6F0FULL, 0xDFB49E22310E5FF1ULL, 0xA4EC2BE7D8D68F2FULL, 
            0x637D1113348B214CULL, 0x83804BFF6F120865ULL, 0x3E9D4B85A9E10E64ULL, 0xC87837740549CA59ULL, 
            0x749CE7B514107928ULL, 0x658267B089396D04ULL, 0x0F68C32D025E23FBULL, 0x7A8430FBE732EA8CULL, 
            0x8CDBC229BB015A43ULL, 0xA0DDDBCD434D6440ULL, 0x8402E4B5E79FF5B5ULL, 0x287E84E1835096AEULL, 
            0x910F9BB6C653BF7DULL, 0x2E24B189FD4F997FULL, 0x3DB2E8765B33335FULL, 0xBB1B4C8219565892ULL, 
            0xCFD359FB1A93365FULL, 0x0F3F667986FBC38BULL, 0x10975806346A9F48ULL, 0x0AA10FB1B39B2E8EULL, 
            0x22796DA1AB638954ULL, 0xF140A523A934E81FULL, 0xE20946A68213692FULL, 0xB25645AC0AA516F1ULL, 
            0x43B8AA5E79DDC963ULL, 0x53BC45D519ADB55BULL, 0x53A7B95830267EEBULL, 0x422D2AF6E6719DBAULL
        },
        {
            0xE873C3643DC02037ULL, 0x2BB6948FED1E13C6ULL, 0x177493AB1DFC1D77ULL, 0x96E79FFF69864074ULL, 
            0xD607BEEF7614933AULL, 0x01F90EF054428852ULL, 0x85831AFFBBCEF58CULL, 0x5798987E5A55A5B7ULL, 
            0xE8A55A513F2C05CBULL, 0xD01F27899784E543ULL, 0x524A168E31AA5B72ULL, 0x0B3BC66252965499ULL, 
            0x0759E08312F0B8C5ULL, 0x3521BD5ADC3842BFULL, 0x175AA4F0A4EF2FCDULL, 0xBF98FD0C2D0DCF79ULL, 
            0xB8E0884B1D8265C7ULL, 0xE5D640D69C6006FAULL, 0x5D3EEE327D0BDFFDULL, 0x6EC95A6427291140ULL, 
            0xCF8580C6ADFB8DC1ULL, 0x72860387BC69DD62ULL, 0x59BBB2F062A85EA8ULL, 0x9F5DDF60E13D295FULL, 
            0x573CC98524954540ULL, 0x30FD3EB02226BC1EULL, 0x9023855CA1F93E0EULL, 0xD1F3D03BD20F19BFULL, 
            0x88D51627C9869087ULL, 0xD3A09CE7F7111281ULL, 0x7686D8F3B8F9FA8CULL, 0x1D12410B8A6A5ED4ULL
        }
    },
    {
        {
            0x2A79ACB3BAF553BDULL, 0x6D03B5FA73C6BB48ULL, 0x9C26CC0CE628D4F6ULL, 0x29ECB81B826EF6F9ULL, 
            0xCA45C34269B11ED3ULL, 0x43833626F3AF4686ULL, 0x8BCC1BF9AD95D340ULL, 0xDE4CC98390B052C1ULL, 
            0x2735FBF4806D95D9ULL, 0xA2AF8F1A62F5CD8BULL, 0x4D9F257CC1EEC980ULL, 0x4445092FD2DAEB9FULL, 
            0x48D52CA16228ABDCULL, 0x178B5A72D9E419C6ULL, 0x81FFD796A17FEACBULL, 0x8B8D7FC4B6E1C7BEULL, 
            0xEABD1CEE9A1F89FDULL, 0x4C0565A60D49F921ULL, 0x25CCC876DCBDC801ULL, 0xA739F10C9A897372ULL, 
            0xD93CFEFCB4AEBE0EULL, 0x20A05358698AA254ULL, 0x01D27CF9762C3569ULL, 0xA3367B396F69D2BEULL, 
            0x750BE1E7753F884AULL, 0xA0C05F45A5E48C37ULL, 0x1AF7D6E59DB4476CULL, 0xD46CA5961F30E020ULL, 
            0x364C2C9B4AECA17CULL, 0xFF645DB8F6FE74B1ULL, 0x03EC91505B85F289ULL, 0xDE6715D096BCA097ULL
        },
        {
            0x1F38E792D4856DC9ULL, 0x7F4EF3EC04E2EBD9ULL, 0x8992E85DF1162047ULL, 0xE15E7F0B3AC25CA9ULL, 
            0x5F5C459C57E4EECDULL, 0xDED42EAF6E1A0538ULL, 0x834DCD8699B1EDECULL, 0x8536C4EC9100B255ULL, 
            0xF198D1BB71D8C84CULL, 0x6EBF3A1C18CA20ADULL, 0xC8E70AD58533EA51ULL, 0xC6CBF3D9E8D4D349ULL, 
            0xDC431BE93B3749EFULL, 0x57F42858E8076F94ULL, 0xAA747C43A5119AA3ULL, 0xABB74CA8A53F5E05ULL, 
            0xEE1ACA44D691B9FAULL, 0x6EA18886F384DF15ULL, 0xA44243C3D363654FULL, 0x01478F7642612223ULL, 
            0x342E8C30E0E699D4ULL, 0x75951E7BD0ECC6AFULL, 0xA440768C56C40D9DULL, 0x9172B9E9188095A2ULL, 
            0xF837606A0447C91AULL, 0x0982E53C001EC7ABULL, 0x0877D3CAFAAE3F40ULL, 0x404FF736DE9060F9ULL, 
            0x8ED5F65DC8023796ULL, 0x44B9220D9EDC3156ULL, 0xC483A3C4E713D884ULL, 0x7210EC6476AD7811ULL
        },
        {
            0x1453F5CE7F32EDECULL, 0x971C69049CB4B3B9ULL, 0x1ECC00DA4C2CC2F3ULL, 0x7AFA7AF5DDCB7F74ULL, 
            0x45B0B6127914F3ACULL, 0x5F0F177BE87D3084ULL, 0xED4717F67B146DDEULL, 0xA0F5B92808598DDCULL, 
            0x5094712A7125E311ULL, 0x76B7F5389360D657ULL, 0xBF2A1EDEA9A9A9E0ULL, 0x7E52DA4214150EBFULL, 
            0x24CB29DCEE67D970ULL, 0x6614A6E8F48791BAULL, 0x195ACE5294FC3D0DULL, 0x29CBA84730FF6487ULL, 
            0x0840BEC9A8916099ULL, 0x19E0FA979E473097ULL, 0x746421F673FC87BAULL, 0xB5E2DADE927C67A4ULL, 
            0xF4299D7092291E3CULL, 0xD7D7DDD4DE696CCBULL, 0x6868601C023A1419ULL, 0xE992126525C97200ULL, 
            0xECB561426691F4C5ULL, 0x8FA581958574C957ULL, 0x7D3BAAB53943D23FULL, 0x26FE5C14D6EE6EC4ULL, 
            0x8B109150B893EB76ULL, 0x430DC705DE92102EULL, 0x73E1C75D51A1B2A3ULL, 0x2ECD6329BAE2D266ULL
        },
        {
            0x7DC091E8C478931EULL, 0x871F6F4B2FD0B780ULL, 0xFE094889AEA26F3CULL, 0x70AFFC0021A22C82ULL, 
            0x4600818EE6CA2AF5ULL, 0x8AD9930E9F2DBBA7ULL, 0x935CF9FA1EAC52C4ULL, 0x17048F5B97996E16ULL, 
            0xB0543470CDD0025BULL, 0x84A38F143E23FFCAULL, 0x6F929156D7970412ULL, 0xB23F9B94AFF0BFE8ULL, 
            0x2401652D2FBC8200ULL, 0x7B0150DD3F7DDC31ULL, 0x080887E2C218CBA7ULL, 0x0D56ACB44525D305ULL, 
            0xE24B910CB0882334ULL, 0x9ECBF86D21BDF657ULL, 0xE3EB3918AC798014ULL, 0x3D3A314537BD9541ULL, 
            0x5654D826649BFAAFULL, 0x0AF9BCF1DAF11A04ULL, 0xAE68E0EBF418A8C3ULL, 0x5E6C7EA40A00FED7ULL, 
            0xAD0846F5D2C75554ULL, 0xC2EA094A16095DFCULL, 0xB5DB0C25D586BB55ULL, 0x0A9B4CF8AE77A159ULL, 
            0x891B29F75D54D56AULL, 0x273A508187AF299FULL, 0x5352655FE30E2A85ULL, 0x61B77BE2EFBBE6A7ULL
        },
        {
            0x9F8CF8179F067626ULL, 0xBAEF3DCFB085E719ULL, 0x759BC1A74040993FULL, 0x9E45DFDC4D436202ULL, 
            0x547461B76F1253C4ULL, 0x2499FF2D9F9EE01DULL, 0x3A6768AF1D254473ULL, 0x72C37B156DFB1053ULL, 
            0x620E0CF5DB641B00ULL, 0xD4466B1B61E64B96ULL, 0x41E34DB1D4BDB75BULL, 0x6EA7F499BBF1D456ULL, 
            0xAD089673FE6F24C9ULL, 0x1856CFE519F15351ULL, 0x965AD7F57826F449ULL, 0x9627B0FA0BD1BB07ULL, 
            0x975E08B602E9D5BDULL, 0xF5FE9F866EEE623AULL, 0xD72D58991658A9ECULL, 0x6AA81020C08E63ABULL, 
            0x2030EB446FDB3868ULL, 0xA2828FF916CD636AULL, 0xABBCA502E5A706A8ULL, 0x261C33D96D337C47ULL, 
            0x257C14C6ABFA73C8ULL, 0x16AD4C4CE617E0FFULL, 0xE13D090BCE1A18B7ULL, 0x751A67D9798DAE08ULL, 
            0x155F2EC90A0870FEULL, 0x655069725E2ABFE8ULL, 0xD6E5C288E292CC76ULL, 0xFCA5E53B6E61A1D9ULL
        },
        {
            0x356377E42213AA2BULL, 0x41ACFEE3954019C7ULL, 0x7AC5EBF4465FC17DULL, 0xECBE8C5A2EB05430ULL, 
            0xA113B0AB8ED5A63DULL, 0x25BA6BE75DF6785BULL, 0x08D639BAA20C5815ULL, 0x952A5A20CA8396DEULL, 
            0x4A39FFB7F41FA272ULL, 0x2BDC3E3C7DE89995ULL, 0x15C22AEF50CE90E7ULL, 0xC21D91071FAAF08DULL, 
            0x9C86D0FBCFD08DEDULL, 0xF46AF1A0EA3F2BE8ULL, 0xAA5CC4F029EC3200ULL, 0x2A46A801C8345FEAULL, 
            0xB18AAA462890E5ADULL, 0x216CED04A1352872ULL, 0x67AC7571EA17FDB9ULL, 0x3343A65FA3D4539EULL, 
            0xCC862F2CD6779E4AULL, 0xDF0DC8A92B4ADF65ULL, 0x89DD8D9568E4984CULL, 0x88B714BB7F12BE30ULL, 
            0xCBF674642B5DD462ULL, 0xC09058C504E997CAULL, 0xCABB819BC373532BULL, 0x98DCC37FE9B0AF11ULL, 
            0x2D432EB12E620D6AULL, 0x01FD7FDD5B335EFEULL, 0x0FD0D43D0B569767ULL, 0xDE858627397A2CC6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Pollux::kKeyRotateConstants = {
    0x27835D1001EEC19FULL,
    0xF86D9BFF898C18CEULL,
    0xB0BBC84048AE8C07ULL,
    0x27835D1001EEC19FULL,
    0xF86D9BFF898C18CEULL,
    0xB0BBC84048AE8C07ULL,
    0x230AF81FB8CB1277ULL,
    0x0AF68C25C60EC2A7ULL,
    0x4E,
    0x15,
    0x0C,
    0xC4,
    0x24,
    0x0D,
    0xB4,
    0x91
};

const TwistDomainSaltSet TwistExpander_Pollux::kKeySpawnSalts = {
    {
        {
            0x9217CA79763772B7ULL, 0x8A0260986B769516ULL, 0x4331391E90A0D5C4ULL, 0x90EDA2F444AE7B7FULL, 
            0x018C2D3A23C7A82FULL, 0x1DA066B300481028ULL, 0x0A6FA9617121B58DULL, 0xF14BF75DCEEF73B8ULL, 
            0xC2DB92738B24E088ULL, 0x9B114C0410C73282ULL, 0x684C227DBB202D2CULL, 0x496A92F46B7C9FCDULL, 
            0x82556848594099D8ULL, 0xC7551DAEA8A99FC7ULL, 0x072EF96A1C77CE24ULL, 0x5056DED36EFFF55CULL, 
            0xD8FD9B278B574DB2ULL, 0x5CDBD4285B90823FULL, 0x4F521CC525CB54CAULL, 0xE6F99090B77805C5ULL, 
            0x8716A9FB1FC22220ULL, 0x941FE8FC7F28BECDULL, 0x39170A996C912389ULL, 0xDE56B517E30A6346ULL, 
            0xC8FD1A24B61DB3E9ULL, 0x64990B1082C46B79ULL, 0x08FA1DE16DF0B75CULL, 0x894B1FA2D2DEC8EFULL, 
            0x496DDB2E5EAD2AE4ULL, 0x1C00CA9138E58212ULL, 0xE68F211DB88F5739ULL, 0x69ECF94624376364ULL
        },
        {
            0xFF75BB1704016351ULL, 0xF627835DBAD59DC4ULL, 0xC62657A5DB27F235ULL, 0x54A89F82E5CAA497ULL, 
            0xEFAF2B0217D32C80ULL, 0x339D8B5BB5C8572BULL, 0xF775B5E855A59FAFULL, 0x2416D9E26ED766C4ULL, 
            0x7C0F76E170B596A7ULL, 0xCF11536F633E8A19ULL, 0x9C9526DD53B3E125ULL, 0x508B75F480C54919ULL, 
            0x5DF8D246B03B6D54ULL, 0x292CD1AC43C314F5ULL, 0xD6462B115B49B5F3ULL, 0xA9487D51C35A6358ULL, 
            0x263EFE1668AEE28EULL, 0x1A0A4421FC8362F3ULL, 0x21322A1D54CA3840ULL, 0x883F1485494DD6E1ULL, 
            0xFBD8CA855CB65F79ULL, 0x2753DC9E6E33DFAFULL, 0x06A9BF8AD8B3930CULL, 0xD13C5141C8FB12FEULL, 
            0xD16E5005AC01CA20ULL, 0x9D11B201C3C32144ULL, 0x5892BCCC4EBC8D58ULL, 0x16194FAAEE143A6EULL, 
            0x94B8B0DE549D8872ULL, 0x1E90C4B1A5D07D51ULL, 0xE4C074BB2A8BEF29ULL, 0xBD5325AA419B7E5BULL
        },
        {
            0x4CD274B5A8F78F18ULL, 0x603F1F1ABDDA3D14ULL, 0x4855BA2358D5F7ACULL, 0x40D4B6759468ACBDULL, 
            0x04F19F1110A339F1ULL, 0x44C9E288C47EC4BAULL, 0xE40912D2BFE27FCAULL, 0xAAA9B6ABDC887373ULL, 
            0xD8790DF5E6C16E8EULL, 0xC20CFFF0FE9B5A87ULL, 0x8F6E78E47FCC62C6ULL, 0xC59E99ADCCE1E7EDULL, 
            0xAF17BAB1B97CC4F6ULL, 0x91A9AA1F4DCA37A0ULL, 0xED1EB817A3F0CA71ULL, 0xB6CB558F04F2D61FULL, 
            0x0D15FFBB2331033AULL, 0x4C475C4A431F259BULL, 0xFA1AF7D2C194F8A3ULL, 0xA4A9158F6E7B12AFULL, 
            0xAA731089951187A0ULL, 0x399F4BF3FA4EB035ULL, 0x02F230E548B24D8CULL, 0x47925793B9858634ULL, 
            0xA362829C221D71DEULL, 0xFE4ECC25A3409012ULL, 0xB0D52FDD5F8A9D27ULL, 0x8B1A1F240EF65E74ULL, 
            0xE92B46725879D2EFULL, 0x24188F6354CB370BULL, 0xF88ED931441F0531ULL, 0x1ACBA737FD00C900ULL
        },
        {
            0x7DE66C589C31CA44ULL, 0x1A26ABB78AEB85AEULL, 0xD345F1BDEEB402F7ULL, 0xDEEC869F988195CBULL, 
            0xE5630452A9EABBC5ULL, 0xD3E12F45FE3C3B5FULL, 0x3C9B942027BB0D1AULL, 0x8DE37CBB82B46E0CULL, 
            0x0135D041047BA1E1ULL, 0x9C6F6E2D7C9800EBULL, 0x44DC2EF33A8DDDCAULL, 0xEEE3D330B306F9B2ULL, 
            0xBCF11601576D7E48ULL, 0xD009BB0F16B0D130ULL, 0x63C803DA664008F4ULL, 0xC91944EDE2551ABDULL, 
            0xBA57EAE473D7AC2CULL, 0x6FE588ED50F3AA80ULL, 0xC3BF332F6014D998ULL, 0x75591F0FFB8A8260ULL, 
            0xB3CE833B8AD68E66ULL, 0xB0EDCFA1937B3ACCULL, 0x4C4C107B2191E3EAULL, 0x06B3D2A5611C7E89ULL, 
            0x8031D8688BABFA94ULL, 0x2F344D6E1EB842FAULL, 0x7F4E4D0B449E4166ULL, 0xCACCEE06F3A36B66ULL, 
            0xE2D72869F86AE6D6ULL, 0x51AA7D7B725E0856ULL, 0x91681B533F010587ULL, 0xEF96A706F0D74196ULL
        },
        {
            0x526A2D4CE38178C6ULL, 0xBCD2CF8D78362C3BULL, 0x1F016C3538F0147AULL, 0xA9560C2516F4BA57ULL, 
            0xD1E4D3751950D8C1ULL, 0x8B226BCC658D53DFULL, 0x9D04216A44071376ULL, 0xAABB859496A57994ULL, 
            0x962BBFE0C1A49974ULL, 0xB617095B9AB03EE1ULL, 0x1BB81F9541364C38ULL, 0x2CD2516B003844AAULL, 
            0xDD8A057B39D60D4FULL, 0x081974526036C84EULL, 0x21CCA1793D713502ULL, 0x7B8B8A4DD5991216ULL, 
            0x5528F3565A01837BULL, 0x9CDC3E8FA11FA6C5ULL, 0xB78956626DE9C875ULL, 0x5D6A18034A33A0BCULL, 
            0x5EE5C82BC71CD27EULL, 0x96EF96822AFB2386ULL, 0x3903F8EF1CE9C8D2ULL, 0x121920147BEE9C13ULL, 
            0x9DBD2CB7BC007238ULL, 0x01B7AA76B8BB3B13ULL, 0x4BA0A832AF5AD63BULL, 0x0E7887E0605A0657ULL, 
            0xEF0C623BC3908AC1ULL, 0x8377EDB97E15A003ULL, 0xA6574296DD5AAF99ULL, 0x72BDE93C6FC712A1ULL
        },
        {
            0x3F8E7A4C7C264E8FULL, 0xC4697889F5E1FAAAULL, 0xEF6A52E49B5134C4ULL, 0xC7D3A4BDF243F64FULL, 
            0x99B9F7CD6D4D7C5AULL, 0x8468DE7AA50D105CULL, 0x943D5791A9B9086DULL, 0x9EFD1970A9D38D6EULL, 
            0x2479E833BBFF4350ULL, 0x080A94524152A78FULL, 0x48FAA11695ADF306ULL, 0x702025D15957E2FAULL, 
            0xEBC4C9092E420632ULL, 0x03EDFC19BDB0FC95ULL, 0x0DBB7D9005F9F8BBULL, 0x68ADE60A73754AB1ULL, 
            0xD2324A22D5784094ULL, 0x5196F31162DEA73DULL, 0x6D3536E52933D583ULL, 0x7E8FF63E15EC841EULL, 
            0x0A04D1AF473DEC9BULL, 0xA6896DDF3E2535A4ULL, 0x8CCAC11A29975ACCULL, 0x4978BDEDCDD61617ULL, 
            0x5715C9D47E59F0EFULL, 0xD6A5838DA5BE44F9ULL, 0x5938D27F70F993E2ULL, 0xACA574B9A5360889ULL, 
            0xEEC60ED7AB779675ULL, 0x1F9550209AA26886ULL, 0x57A0B9E9F58EB0AAULL, 0x60BA8CC92B31829FULL
        }
    },
    {
        {
            0xE47413197C394830ULL, 0x383D46CE8D095E05ULL, 0x6633F37830E39C48ULL, 0x9361570FE114D2C1ULL, 
            0x9FFE1151E4B27143ULL, 0xD92211F2C205B63DULL, 0xA92FE053560A516FULL, 0xB7714E430C9BBBDAULL, 
            0xC9D38FD3DF5226A2ULL, 0xB372263FEFB08D34ULL, 0xC00BD0DFB7166693ULL, 0x6827118FA8BEC512ULL, 
            0xC4F997ADCD2AE628ULL, 0x6D2360ECF806AE67ULL, 0xDA405EFD0222B065ULL, 0x33D5A52465874EACULL, 
            0x634F03C3FA18D11AULL, 0x4EED9FEF6E6B6FFDULL, 0x9A8857CB543C1EF3ULL, 0x3D83CA23DC0853FEULL, 
            0x0CE00F5983A17559ULL, 0x6F8278CB0B874232ULL, 0x8544BF133B96B840ULL, 0x088487284994D2E4ULL, 
            0x2128EEFF50F380E2ULL, 0xBE103303A00FD826ULL, 0x13730226AD7ABA65ULL, 0xD4BC40B6C2677881ULL, 
            0x0E92FB06FEA45C03ULL, 0xCC4869C5AAFA3B48ULL, 0xC977B0117100A76BULL, 0x305DC0FE6CAF422EULL
        },
        {
            0x1439846605EAFC98ULL, 0x4CE8E1FA1964D614ULL, 0x46CC948A0D60B12EULL, 0x5A27D9385F88B0CBULL, 
            0xD4AC2E509082B020ULL, 0xE8ED1C5028E48522ULL, 0xD4281A620FD8C9F3ULL, 0x035C464F14B95A5BULL, 
            0x120ADCCB7E9FF6AFULL, 0x004451E513FF1D6FULL, 0x8E3A750C2860954AULL, 0x87B320B3E3BA40A9ULL, 
            0xD7CE35273AE09AC2ULL, 0xF73C03D5ED5467FBULL, 0xA105C428BA6F1E37ULL, 0xEB956E3A1B5D65E7ULL, 
            0x76B21592A26652FEULL, 0x92B6B6467EF56548ULL, 0x4F37E323A5B8DBE5ULL, 0x8B4986B5D2DC5803ULL, 
            0xE3663AA70FC74843ULL, 0xC20824671D86728BULL, 0x7320F3FC6FCEED0EULL, 0xEF056192592AAB80ULL, 
            0x8DAD43F36C756DD8ULL, 0xF433D1FABC395728ULL, 0x0495DB3B24187DB0ULL, 0xAFFCACCE2BD55CD6ULL, 
            0x3663F6DE9CAF37F6ULL, 0xECBA46AB61FD4A6DULL, 0x4687D6A2C06809E5ULL, 0x1F8777F50BD9A2D6ULL
        },
        {
            0x8006E5B9B4332F63ULL, 0x380D42903E757429ULL, 0xB054B978C36C5D7CULL, 0xD30F788CF644654EULL, 
            0xDCA32C9CB1B8241EULL, 0xADD2BB5243381368ULL, 0x0B636313CB54EC8BULL, 0xF06F3BF5B7C411F1ULL, 
            0xFC854EEF65789A2DULL, 0x775411A10E0721D2ULL, 0xF19C9722C0884F0FULL, 0xC8BEF1AC18749928ULL, 
            0x8B00A6A9A48833A9ULL, 0xBD24A201D9E41B51ULL, 0xBE16430886318ADFULL, 0xBD50E6DA6C48F8E9ULL, 
            0x8A207C2E33CF0339ULL, 0x2B7A3532D0816F0BULL, 0x634F1BDE9627E767ULL, 0xABE76622FA53366DULL, 
            0x16639C05BE74B336ULL, 0x168BDA3CE109F61CULL, 0x746A3920CCDC4B93ULL, 0x7ECA2730FE53DDC2ULL, 
            0xCEA66252A329C6A1ULL, 0x2429C69B563027D8ULL, 0x885D0AF5E9F20C8FULL, 0x76D2BEE8F85069B5ULL, 
            0x286A3CD94BC9F49CULL, 0x84F7860504E1686DULL, 0x69B2928CE5BA0D8BULL, 0x4A56806C31AD49B7ULL
        },
        {
            0xB4B807AC59D7BB36ULL, 0xADB4416CA59D5309ULL, 0x86C72E96631D3A12ULL, 0x264F77951B67AE11ULL, 
            0xC95AE61573CA73D6ULL, 0x867B78D83E8E1ED8ULL, 0x3D61619B058204CAULL, 0xE55E95841454E60AULL, 
            0x3DB7664944172049ULL, 0xABDC1719C2FFEF4EULL, 0x6928F89F30B20587ULL, 0xB51D9238F92AD172ULL, 
            0x4A115A738E4AE022ULL, 0xA5E8C1BEFD663E35ULL, 0x1DAF2B4D9E0C6159ULL, 0x8E3C052E65468587ULL, 
            0x79FC4B684FF9BABBULL, 0xD34E5C10D91B9657ULL, 0x4DAB86A0F1980A4DULL, 0xA833FE3A4347F6B5ULL, 
            0x1FA7135F9CFC27DBULL, 0x56CC52828DD4B8D0ULL, 0x0872A51979CBF92DULL, 0x55D5B601F28D0661ULL, 
            0x866E5D4BB56F45ACULL, 0x8084D79417238F24ULL, 0x2326A683315D0A41ULL, 0x28280240C54EA925ULL, 
            0xECC443F9334D6AC8ULL, 0x83FF4744738C1E07ULL, 0x5682A0A865A990A3ULL, 0x9B2C1158A3B16D30ULL
        },
        {
            0xDBB9AEFF09C241F8ULL, 0x636F89412BE68978ULL, 0x34BFFE4B96B75D74ULL, 0xF988151A9B8669E6ULL, 
            0xC6FA607B3AA21305ULL, 0x18A4DB5146B82959ULL, 0xD693A2A6655B2990ULL, 0xD65684474FE9B84CULL, 
            0x365C336243931DB2ULL, 0x9C9FD9D828BF9727ULL, 0xBB4D5E4414BC45DAULL, 0x9610FB52EA0BE586ULL, 
            0x88F680B82D1A6579ULL, 0x5FA3363977DEDF92ULL, 0xC4185BD5C0BFCE0CULL, 0xC8E6F4985931E6BEULL, 
            0xFAEBDE89E4E2CB33ULL, 0x9D64591B24CF13B6ULL, 0x1350C6AA3DB6FD84ULL, 0x75CC474175D9C838ULL, 
            0xBB63576B4C2F8E08ULL, 0xD18636AE9E78F0F1ULL, 0xD48B6EFB8220D8AAULL, 0x2EE827493AE4453CULL, 
            0x30718634D7E73D53ULL, 0x907A361F97F09043ULL, 0xF9F75BAF2494678AULL, 0x73AA0E2D51B746E0ULL, 
            0x5C79BF6DF0B56C8BULL, 0x8FDACDC03900C66BULL, 0x1E249E2FA5B34D95ULL, 0x4A6297BB2B347326ULL
        },
        {
            0xFA93D345A5797F2EULL, 0xA7756F2146C3C3DAULL, 0xF1B7892DF0654B9CULL, 0xA82C5E0286B456A0ULL, 
            0xD244DA7095E2B97BULL, 0xA7032690D022D066ULL, 0x0B07728E82E2DD4AULL, 0xE970AFD787CE73C8ULL, 
            0x090969FE91BE41B5ULL, 0x1F49FFD5E4B441A5ULL, 0x1BC598EC67CF64C3ULL, 0x97C708D7CF8CAEF4ULL, 
            0xD7415983B9908866ULL, 0xB1DEC504650738D5ULL, 0x92D8BFCD520BAA9FULL, 0xB15F84E23B0A3921ULL, 
            0x492D403DD95B1E31ULL, 0x0C7F99137C3601DEULL, 0x8A4D6708D4715026ULL, 0xB807A67EDA19E8E8ULL, 
            0x8C0CBDB1E93A92C1ULL, 0x81422B193FC00D43ULL, 0x4B0D5E6CF550A338ULL, 0x6F2D12D1AF43A4E8ULL, 
            0x470D1F4F17786857ULL, 0x22D5EC5F586B3A21ULL, 0x798B335824E0298DULL, 0xD0275ABB5F522B23ULL, 
            0x06EC765F3A478AF0ULL, 0x18CD16BAF365E92DULL, 0x3E67460139083D72ULL, 0xB2308B2144474C8EULL
        }
    },
    {
        {
            0xD87CFB1864B450E0ULL, 0xD08A0E64F9AE08B4ULL, 0x95618B61C7E36B22ULL, 0x1EE37628768C4222ULL, 
            0x339C81CC182D831DULL, 0x6B304E5FA8D2B569ULL, 0xCA26CF7795980E63ULL, 0x9227FA2675F687E9ULL, 
            0x4FEC77EA6E61E977ULL, 0xF4D2F2B4F464F8DAULL, 0x20CD2844F40802B6ULL, 0xCAA83605C5C1CC4BULL, 
            0x58B71E32F56CBAB8ULL, 0x61A43A4A4B6F70B9ULL, 0x7C048FA5390D3D3CULL, 0x29DC1EA4490EB209ULL, 
            0x3D450E1FCE52FF99ULL, 0x85AC42AE95AF2C12ULL, 0xEFF3A06A33411556ULL, 0x3B04030966791190ULL, 
            0x48FA99D6986C70B1ULL, 0x93C85E493C848851ULL, 0x8A6DDBB9A0F0357AULL, 0x6448E85381B4BD8CULL, 
            0x17704981C553A0CAULL, 0xC523AA09DB21E645ULL, 0xC0E60AD4BBB7C506ULL, 0xD642CE38037DEDF2ULL, 
            0x2E8E0A2CE3D7DE04ULL, 0xDDD8BF254874DDD5ULL, 0xC73430D2F1D697E1ULL, 0x1A65F38937526FB1ULL
        },
        {
            0x83CB5BBBCC217D0FULL, 0x0889AC49950D3C6DULL, 0xE7BAC8E92AB21B05ULL, 0x9DBF5F36B9A7B160ULL, 
            0x07C46EB63C453241ULL, 0x69EE9428A59F0A36ULL, 0x9A67009E27877DFCULL, 0xBA2574D62FB65A8BULL, 
            0x90486815E15DA89EULL, 0x44B6CC9508D61C3EULL, 0x2341315C74B12547ULL, 0x52559CDBAFAD333EULL, 
            0x665F2F7A8317A8D6ULL, 0x7764B1C1387BA506ULL, 0xC3F0CD56786FC62DULL, 0x9FA76B331608AAF0ULL, 
            0xFB2FF45625CC5106ULL, 0x592F57B58EECB94DULL, 0x9200D66E4D5685DCULL, 0x574745CFF726513AULL, 
            0x3438FDE61D7CACCBULL, 0xEE3F1CF9F4B8C7E4ULL, 0x42FBBC72289CA283ULL, 0x4257D2D7BEA7E251ULL, 
            0x66291133CF4CEB78ULL, 0xF3723C620EA8563BULL, 0xE0D8188F6C3D4D72ULL, 0xC942C7FAB1208596ULL, 
            0x101612082FD8B011ULL, 0x9348E0D09742EBC8ULL, 0xDB3557202662DF20ULL, 0xF99B7385DFCF14EDULL
        },
        {
            0x0BDA6CFFBB1DC522ULL, 0xFFD936AEC323869EULL, 0x2A4256DC48BB8C74ULL, 0x8331AEF273C0EF99ULL, 
            0xFCAF7A8E1F112A34ULL, 0xAAEB27097BB46581ULL, 0x91588D5EA56BF57EULL, 0x940A2D76D482AA1FULL, 
            0x5BB3AD56A321039BULL, 0xE9F8211819508526ULL, 0xBBBABAAD137A7997ULL, 0xD2105067E21FF183ULL, 
            0x03CB6E4FDC202F3AULL, 0x8A6705FE3771FEF7ULL, 0x3D715F50E82EA2FAULL, 0x898EF11B8E01D840ULL, 
            0x8081BFC098A41A0FULL, 0xB1D40AD1BCF69939ULL, 0x4B10D46A3011AAFAULL, 0xB052461D75042076ULL, 
            0xA234085CDB09301CULL, 0xFBC4F87E494A0770ULL, 0xB0BCC19316E0F270ULL, 0xB494466F57B46079ULL, 
            0xAEB7C27701CDB3F7ULL, 0x615F4D1435DB2039ULL, 0x8EB028FD8A56FFE4ULL, 0xDFB9F49AC7AE9829ULL, 
            0xFD07E8409B6DB2ECULL, 0xF4A94F41C393254AULL, 0x0FAC11A9D347E660ULL, 0x057B80A48823C82EULL
        },
        {
            0x7405604A1F176F83ULL, 0xBAB99F7A24C157C0ULL, 0x0F937B00460C992DULL, 0x715F7047EA69BE15ULL, 
            0x8C335CE933563D64ULL, 0x3EC7B4568FB74C8BULL, 0x78ED0B32AB58C373ULL, 0xE32ACD625E9A7070ULL, 
            0x4B43C9F6D93FB017ULL, 0x151EAC8FC7E381DAULL, 0xA992C7C730C0C83CULL, 0xACB396FDBAEEC891ULL, 
            0x07CE711CB589C966ULL, 0x69F7D910E967690EULL, 0x2D0803B65F449401ULL, 0xD03F91CBF227281DULL, 
            0xC8AC938A22AEE456ULL, 0xA92A95CCDAB461E1ULL, 0x0758AE666600D9C4ULL, 0x6FC4AE864E132A09ULL, 
            0xA49128B4345DAA6FULL, 0xE617B05E963606B2ULL, 0xD1CA57C33BFC8BA2ULL, 0x392A1AA6A4A66C08ULL, 
            0x04D8E50087D50718ULL, 0xD2052919E26AC699ULL, 0xC41C2997CE34136CULL, 0x2A4E1EAC4A0AF334ULL, 
            0x7F7EDAAF754B006AULL, 0xFB38F9CCDA1BC750ULL, 0xBC7F9652C844033AULL, 0x3FF4C57F4962D512ULL
        },
        {
            0xF37DCA19B233FDE0ULL, 0x42458B6905E15ABAULL, 0x92E9A21EA7DC2E7CULL, 0xC238E865A3E27140ULL, 
            0x095E576F685FA9EDULL, 0xCA27C989AF6ECDB8ULL, 0x009E936AB9AFF17AULL, 0x022D8CFD47CBE6FAULL, 
            0xACFFE528D25BD9E1ULL, 0x7A219CEF9D1B5F02ULL, 0x55A5CD0DDA98ADDBULL, 0xDD9AD0973A5A0AE6ULL, 
            0x5FB1D015F0A34CCCULL, 0x4C3BC8106993CE59ULL, 0x4DA153B7966D6CB8ULL, 0x9C1189B82DB4EBD9ULL, 
            0x606C10A3651A8FFAULL, 0x1D7F28033188B577ULL, 0x0A8F087634913155ULL, 0x157639E984565EEEULL, 
            0x483155D2B6E29F3FULL, 0xE755872D81121C74ULL, 0xC2296235EEA5916AULL, 0x0835787ECF5E3F98ULL, 
            0x9015A3B2A4B6C83FULL, 0xD136BC5CDEEE870CULL, 0x0087E53B863B2681ULL, 0x2151BBFBAB17609EULL, 
            0xA4114EFA6A919B84ULL, 0x0CF1F4C84E074B3FULL, 0x8872D7F05479B347ULL, 0xB7520397E7BC9CE8ULL
        },
        {
            0xA2BEC33D2051C993ULL, 0x7BF552F7F240CCDDULL, 0x37E799E311D9CD61ULL, 0x1329FE20B80460E2ULL, 
            0x3EA4B48B32F565D0ULL, 0x72BC56F256BF4C01ULL, 0xBFDDA1F01EB9012CULL, 0x627CC5023B19BEEFULL, 
            0xE74D2F95A1F97417ULL, 0x20CE2E33DEA99D7EULL, 0xAC29AA59A3BC71C5ULL, 0xD7C6580BAC46AE7FULL, 
            0x45DE66C28D7BEE5CULL, 0xFABC3C6FCD0CC7D1ULL, 0xD8B589F4127EB2C0ULL, 0x3C58E12E1ABCCAADULL, 
            0x9D1E7DD9FBDB48EBULL, 0x0B29ECAE5C663B9CULL, 0x65BCD2334E7D5C52ULL, 0x9C3CBD1A2598D5A6ULL, 
            0xED1FC2364D1FDE2BULL, 0x98937F8CEB313F52ULL, 0xB28F5072ABF8A6DDULL, 0xD7EFA704A05454FCULL, 
            0xCC1EF98F8ACAECD7ULL, 0xD5DA4363BBD0F291ULL, 0x7A9BFA6EC187AC9DULL, 0x2C5F0E206D4F9ECEULL, 
            0xDF1C17A9470196D4ULL, 0xCE3E02659FD6920DULL, 0xF250CD723275C9D6ULL, 0xEB38C492082C35D0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Pollux::kKeySpawnConstants = {
    0xAC3F3C12A5857460ULL,
    0x694D1694A28FE750ULL,
    0xECA7304009C6D7C2ULL,
    0xAC3F3C12A5857460ULL,
    0x694D1694A28FE750ULL,
    0xECA7304009C6D7C2ULL,
    0xD0DFD396572AF378ULL,
    0xB54C00AC7E162CF2ULL,
    0x9C,
    0x39,
    0x83,
    0xFC,
    0x27,
    0x7D,
    0x6C,
    0xC1
};

const TwistDomainSaltSet TwistExpander_Pollux::kSeedSalts = {
    {
        {
            0x95CC5C52884D70ACULL, 0xC370D9DF75AE8C6EULL, 0x4EC68202F7445700ULL, 0xBC5CAB7C16027EF6ULL, 
            0x7BAF72E1CDC1031BULL, 0x12EED32D59B11E27ULL, 0x16E171657AAC75C8ULL, 0x4A3FA8369F248694ULL, 
            0xD65282D0780EF897ULL, 0x2DF7AE9DAE0A987BULL, 0xF2FC3DB4AF03C81BULL, 0x4C4B1733C65E3A73ULL, 
            0x2FCB49D71576EE6BULL, 0xEAF911B3E96F5A6CULL, 0x9201300520716592ULL, 0xD649661C0813250AULL, 
            0x1CFAF112B5B56D74ULL, 0x2FDCC9A49C462B85ULL, 0x376DE5A87AA4C8C5ULL, 0xE64206F9FC2867D6ULL, 
            0x914AA0295CA52757ULL, 0xEC9C817D6FA55E4DULL, 0xAD4A515E49D3EC13ULL, 0xDB7DE9900C214E9CULL, 
            0x71A30C4FC44AB238ULL, 0x064CA50E4F69E30EULL, 0xC61F615AD7D8B182ULL, 0x618B02DB022491EAULL, 
            0x307BA11150F5A6FEULL, 0xF93464BEB6C87B8DULL, 0xE7CAE898BE5A72C9ULL, 0xD5D13A3618E84026ULL
        },
        {
            0x621A3C41F568D37AULL, 0x846F97DFE8156FE5ULL, 0x6849F1B69A1510B0ULL, 0xDBE027DF01BE8DB9ULL, 
            0x42DF07F85EC6630EULL, 0x99B6E886D55A4D4EULL, 0x283624C461D2DBACULL, 0x60F5C909EBFCCB88ULL, 
            0x8118B32B284DF69CULL, 0xD55F3299DD648B39ULL, 0xDA07FD9B5C286ACBULL, 0xDD49A0BAA1F04513ULL, 
            0x75A4DF11A04F1706ULL, 0xBB26DCF6D33C37B9ULL, 0x4DA5189B986D94CBULL, 0xDC1391D22B963BFBULL, 
            0x7253618976168A97ULL, 0x5CAF7FDE6AB3B47CULL, 0xC8F1FDFBAFC35342ULL, 0x98F3699A636EAB59ULL, 
            0x1B13308E6AA7BDD2ULL, 0xA463866ECF461D94ULL, 0x643B033A6FED5BCFULL, 0x1A0CAAE9D9DDC2B1ULL, 
            0x4DE61BA09ACE923EULL, 0xA64C6274BF79DF79ULL, 0x927B1FC0061CA235ULL, 0x78ED742FE62C5032ULL, 
            0xF063752922C386C8ULL, 0x6CBB656370FCA7EBULL, 0x921D0842C22E6441ULL, 0x943CCE1EB48B1538ULL
        },
        {
            0x7893B90ED722D52CULL, 0x58A88918F2188CE3ULL, 0x344F285A3530A443ULL, 0xBD57CC98EEA17F84ULL, 
            0xAA310278F322515EULL, 0x8F1F46F4EF6A04C3ULL, 0x770E3631B232D279ULL, 0xC87DE4EF48108545ULL, 
            0xD95CE7D125BA12A0ULL, 0x2B26628E91E6F3F3ULL, 0x08F8D01D6B0A0638ULL, 0xC36B14CD7A8F2086ULL, 
            0x0172CD3D3CFA4C4AULL, 0xEC41BE12ABFF2C1AULL, 0x8BDE4258735F2E65ULL, 0x3E4C8FEA8F6B40F9ULL, 
            0xBE76DB3237FE2E68ULL, 0x20E3ECF0684888C6ULL, 0x05D000BF4518924FULL, 0xF810A9A2114B6F11ULL, 
            0xC326787CA6F637C5ULL, 0x5FB9BFA3640E790EULL, 0x0B293BA9CF977B05ULL, 0x8FA47351DDE3BFDEULL, 
            0x8A8865F5C2B627BAULL, 0x6BC90460B5BDBA22ULL, 0x300FE6FED4F4AE0FULL, 0xF602E68D43BC94A7ULL, 
            0xC1F4C62835353165ULL, 0x02A64399A28B8276ULL, 0xD00C45B75424F51BULL, 0x0A056DE86C07ECDFULL
        },
        {
            0x4B144A25FC8A04B6ULL, 0x83A828E0780BB43FULL, 0x614D11F4DB5F53AFULL, 0x509DE8020534AF1FULL, 
            0xDD4A0EF877B4AAE9ULL, 0xF292A25BE4B53D67ULL, 0x5447EA46123A4E3BULL, 0x1EE13D7EDB4D50A4ULL, 
            0xFDC9A23B9462223BULL, 0x835EA9F76C90859CULL, 0x1F41A592D2B47E4CULL, 0x46E7AAB47098CEE5ULL, 
            0xEDFD69E7872AA66DULL, 0xB1D54624D7550AC8ULL, 0xFFF24CD2E06B3364ULL, 0x55B8C976EDBF4A65ULL, 
            0x61CC8209E68B3BC4ULL, 0x53710DDF63B7E7BAULL, 0x8E151D6DC808E645ULL, 0x0F811EF66DF0863CULL, 
            0x3F942D178E72B633ULL, 0x96251CE5DD9EBCECULL, 0x630E740C9626F2F6ULL, 0x83F721966F8D289DULL, 
            0x4193A20ADA8090E9ULL, 0xE18C1995A1C45047ULL, 0x5D0B904878871608ULL, 0x7DF3C55A053C1069ULL, 
            0x210AEAD09EBCFEA5ULL, 0x683B435E1B8214EEULL, 0x939CFE4A454F1D09ULL, 0x4FC03A0CAC3C5359ULL
        },
        {
            0x132ABF8DCEDB3B6BULL, 0x2F4CD89A093190A7ULL, 0xED72C93BA0C3920CULL, 0x5E5794C0408CE159ULL, 
            0xC421B777B95B36DAULL, 0x25C884EAAA132C73ULL, 0x291BF286C613FC7CULL, 0x672580717CD173E6ULL, 
            0x0D9EF8C51F5F2A76ULL, 0x9B3EA715A8B57C51ULL, 0xE18FDDF86B25FC1EULL, 0x5C0984D0EAAEF653ULL, 
            0x8FCB84C1952ACBECULL, 0x601CB41C25221D35ULL, 0x5EBE489360F3BE77ULL, 0xC75969B2891F9F19ULL, 
            0xA102E9828946DE26ULL, 0x6B45115377D2A680ULL, 0x6D95BBF691BDC40BULL, 0xEF9B1DE8B4B23CA7ULL, 
            0x8B3ECED2711F57E1ULL, 0xAC5F9A4BE7BB89C6ULL, 0x202EDE27FE7BBC9DULL, 0x2764932CA1FC3DBAULL, 
            0x4DAA95999DAFD549ULL, 0x6D965481624E6BA7ULL, 0x6374C2601D9D1E23ULL, 0x860968297C476517ULL, 
            0x40D0611BCCC6CF2BULL, 0xFE933CB4818CC37FULL, 0x3BF13242F66A990DULL, 0x74BCED7A7373D4A2ULL
        },
        {
            0x88F9471F94D088E2ULL, 0xE201DA5AAD49D7B5ULL, 0x6CF30DBE2C9E5850ULL, 0x1E1EA5B896C68739ULL, 
            0x64DCE3331FD438E5ULL, 0x8E01F947A40D428BULL, 0xA8746B3A77E38672ULL, 0x1B0DBDAF5E1824D8ULL, 
            0x9D2FA1FE9AE60E59ULL, 0xF4068290D33E450EULL, 0x81184EF42DE6C5CCULL, 0x4133718EC60E7A1AULL, 
            0xB06B907353E3CF75ULL, 0x3ECF204D3CDE4C45ULL, 0x9EE9E6509116A136ULL, 0x5588A74475207FDBULL, 
            0xCF7D71C9D9729AB8ULL, 0xE4A681B6CB09C238ULL, 0xB365F81F8990B30CULL, 0x1F341332B8DE1961ULL, 
            0xA1E85C8F47FE1DB0ULL, 0x3C7123DE1E10BBC0ULL, 0xAFEFD0EBFAA0083EULL, 0x727219273F3C3F8DULL, 
            0xC11A9D7C2B507F48ULL, 0x4A8337F00DA9EECEULL, 0x71FBCBF2DAF479ADULL, 0x23609CF8CDA82C9CULL, 
            0xA4C32A25CC8E2098ULL, 0xF9ECEFB864729545ULL, 0x09838B23082B9F8AULL, 0x827C13C694D2A2BEULL
        }
    },
    {
        {
            0xCA47DEB357C5B269ULL, 0xE8BEA448E18D30F7ULL, 0x44D493A760E5D41AULL, 0x7FD7FB373EE76DDEULL, 
            0x109352D239F72545ULL, 0xD9C7C7ECBC752DADULL, 0xA562C0EB7950819EULL, 0xD4B00B664B60BB1BULL, 
            0x35A30E0FD6EF57B0ULL, 0x9365B9B2EFF33C51ULL, 0x5F2C8BAE7A40402EULL, 0x6533BCD9FB26A3EEULL, 
            0x1A04D1830341B229ULL, 0x510F960108FDC54EULL, 0xB1D8583C89CDC01EULL, 0xB8A823801D931C8CULL, 
            0xEE1D4BFAB213F869ULL, 0xE6AD221B792C68AFULL, 0xAEBA50CD64B7E739ULL, 0xF830F984530A1D45ULL, 
            0xDBC4DAE1DCB77DE9ULL, 0xE19A7D866A6ED5F0ULL, 0x9B98AB9921C0B0FAULL, 0x9084DDC88D5535E8ULL, 
            0x7B02673815D8A43CULL, 0x4DDF85ADC6DF80DBULL, 0xBA29D5C08B2B821CULL, 0xCBCC4425E66EA7CAULL, 
            0x2478CE4E10CBAEBEULL, 0x702CF621EE99AA07ULL, 0xA854C3A069316FEEULL, 0x3E6D88DCD6151687ULL
        },
        {
            0x186DDC5E8091BFC5ULL, 0x58F77268EA17EBC0ULL, 0x3D8348BF115A2900ULL, 0xCA1533BE590CB111ULL, 
            0x1429246BD419731BULL, 0x64F75F32307B2A1EULL, 0xC63130A753E1D986ULL, 0x3BAA4EA3EC5F8CEAULL, 
            0xE0CE2FAAFC2046ABULL, 0x00DE78F881D62A01ULL, 0x82D0E1E094E2F603ULL, 0x8D8B5A6C5183B748ULL, 
            0xC7B68CE9D1486764ULL, 0xEAFA4694926FF324ULL, 0x3595D59BA30724AEULL, 0xD07BBFC4A20FD9E4ULL, 
            0xF430AE408B828F40ULL, 0x8C43DFA6ACB78177ULL, 0x854A2C5239A13C66ULL, 0x21941ADB78BA4F59ULL, 
            0xA473ECDB18950E87ULL, 0x0B45F6B5DD03DCB5ULL, 0xABF4C6AD44E837A1ULL, 0xB05C9301440EF43BULL, 
            0x53941472281CBB5AULL, 0xBC53EA279752A818ULL, 0x0EC52EA7456ED41FULL, 0xA8FAC7416B4E7D06ULL, 
            0xDD66160F341912F0ULL, 0x0069E429D0745FB0ULL, 0x25EB1DC6C397ADF3ULL, 0x4D713008660B59F2ULL
        },
        {
            0xE3DB9DFB2FFB1D43ULL, 0xB4576FDED782AF27ULL, 0x9C986886A0B11DF8ULL, 0xE8CB711AB4FAE943ULL, 
            0xCAA594479DC57241ULL, 0x405B9C6844450E26ULL, 0x579E0DD9CFEDA444ULL, 0x7958CEE641B25FFFULL, 
            0x99DF26A1DF23D828ULL, 0x09BAFBB7711F58DEULL, 0xF459FEBD8D978CD9ULL, 0x0690CD8924F252CCULL, 
            0xE9B831FB6CE33193ULL, 0x3B19DABACECFB0ACULL, 0x716B2E6E3A9DBB33ULL, 0x707DBFE7E4FCCA81ULL, 
            0x3E97CF7358347E57ULL, 0x4036A1C8D6DD531BULL, 0xBE435387441B6A3DULL, 0x55BC6A0366324051ULL, 
            0x1A5D4DE3CDF46CA0ULL, 0xE7430AAAC6AA2741ULL, 0x62AB4FF643C68AC6ULL, 0xFAEE236348B1C469ULL, 
            0xEF759A9A8BABA9CAULL, 0x9E0363231490FEB8ULL, 0xD6514EC4A0527778ULL, 0x22B67C211384C94CULL, 
            0xD41A60C58ED5D143ULL, 0x87D0742B4590F4F7ULL, 0x5C20886DE74DB3A3ULL, 0x1AB0027D4C209D91ULL
        },
        {
            0x318823E35CAA01F3ULL, 0x67D5840F163D6D6BULL, 0x4673B5A5549C9584ULL, 0x191E419DDD3EEE7BULL, 
            0xDAE13B3434DA30A9ULL, 0x77287F933653D6D6ULL, 0xEF6F007518A2A3A0ULL, 0xCC7EA4BE745D9C97ULL, 
            0xD3A9BC248C5F041EULL, 0xA5E9EAB23C73D2A6ULL, 0x42970B4D4E943B42ULL, 0x660DB7F44E6DED8EULL, 
            0xCAD69BF23D2E17C0ULL, 0xAF4613EDD2B5D61CULL, 0x6F42451EBF48CF26ULL, 0x3FFE767EE67308FDULL, 
            0x06CEB40014FE69DBULL, 0x9BB613A7197E497AULL, 0xF266C5757B503560ULL, 0xA2A2FD8F63BB2D47ULL, 
            0x89E98D52C9167F9FULL, 0x49D7BB6F64A1C660ULL, 0x4C91EBDC34FEF30CULL, 0x61B49BACAAE26B64ULL, 
            0xE97B9D0266866817ULL, 0x23946AD39D1964B6ULL, 0x739C891BBEBDCAFDULL, 0xF30FF963358A4F80ULL, 
            0xE81105EBB61A4A87ULL, 0x32B15F4E8DAA9643ULL, 0xFF248FC2A8B77B71ULL, 0x9DA3FD1EB6EF3F17ULL
        },
        {
            0xE947C4A63AC0D41FULL, 0x5235E3994B1E87C2ULL, 0x0AA2066A60DA9B04ULL, 0x557636FA558383AAULL, 
            0x8162814A7216FEBFULL, 0x5D887DAE52B65BA5ULL, 0xE422D77F67920C9BULL, 0x84B4FABF15BDE4CDULL, 
            0x65E5BD3D4C13AC16ULL, 0x3BE388F4044D64D7ULL, 0xA8766D92C0F47C67ULL, 0x684B11FAA6278984ULL, 
            0x1E729548BC398176ULL, 0x7201D928CF211C3AULL, 0x229B995884F71425ULL, 0x8164DCA447E75C5EULL, 
            0x9A51316C3B9E07F7ULL, 0x63365478F3B3FB1CULL, 0xE9594369E51BAB1BULL, 0xC7FC2FA2888FB30BULL, 
            0x6B9978CB864831B1ULL, 0xD0B5B79882E8B6C0ULL, 0x9E9BC5D05C9D8DCAULL, 0xF87A1F3F896896D8ULL, 
            0x71018C5C9AD16B04ULL, 0xA44C52EB1345D09CULL, 0x3E40CFE4951D645CULL, 0xBDC334205FA8AF90ULL, 
            0x1D5944948F0B18B3ULL, 0x771D790041DB5804ULL, 0x3DD5530452935EE8ULL, 0x0468D75FFE15425FULL
        },
        {
            0x5C78F6D723D3EBBDULL, 0xF778EA75C1BF1837ULL, 0x6FB368F0B26184D8ULL, 0xB55C535B7CDA698BULL, 
            0x22EC5C9E92308E71ULL, 0xAD60565ED457E925ULL, 0xD0A1E758B45B47C9ULL, 0x4EC7CCBF860C97FBULL, 
            0xA3BD12DC6DC21C79ULL, 0x8EFA456817496A64ULL, 0xC48BD579E8005633ULL, 0xA9962BE9C87E783EULL, 
            0x8059C13A953595BAULL, 0x95E6412856E2B99DULL, 0xADBA59B67A81FD2FULL, 0x28037ACDD2615898ULL, 
            0xD2C34439B7D822E8ULL, 0x5B50A7B9B2C491B2ULL, 0xDB5C996F604B25BFULL, 0x74B087F1307A6075ULL, 
            0x114204BFCD9368ACULL, 0x55D78B4DAE4F95C6ULL, 0x701600C47896BD02ULL, 0x4B6B0717ABD0774DULL, 
            0x033DCAF5FE265F60ULL, 0x504271272A05827DULL, 0xDA007C3D8CE34B2DULL, 0xB2BDC24AD3D05D99ULL, 
            0x4770F8FABBF00FB0ULL, 0x81D8538F980B7139ULL, 0x0DF7CD8C909E01A3ULL, 0x2C6FF865F178558FULL
        }
    },
    {
        {
            0x0DB8A1B2354B848FULL, 0x1D925C062E95F448ULL, 0xF3C53971CC8DCEBBULL, 0x017569ABEDAFB65DULL, 
            0x68C4E6E77E2BEA49ULL, 0xA9D5A1EB5B1F223CULL, 0x1876CED05E2ED9F2ULL, 0x3EFAFC7910CADCEEULL, 
            0x68E0A240804F6FA5ULL, 0x937CCA7022327A03ULL, 0xFE7873E2A581F4E9ULL, 0x0EA76340221A5676ULL, 
            0x1D267530781A3F7BULL, 0xD59C71677849274FULL, 0xFB0FEC1F83F63C04ULL, 0x8A51C4C05826FDD0ULL, 
            0x9881FB83712A363FULL, 0x1713718838C987D7ULL, 0xE83D7A8B28EDF606ULL, 0x4E9094B084C8230CULL, 
            0x659C9995B51F13A6ULL, 0xCC58604FCB0F37A7ULL, 0xAE4D8C9F84E2D925ULL, 0x45454E5E20A58A6BULL, 
            0x6A100B60CF5BA50EULL, 0x8BDF3101D62988CBULL, 0xE42E8543BD2865FAULL, 0xA335A0A47B1B5AC0ULL, 
            0xA444E7A440E5D0EDULL, 0x30127AC17D6AB3EBULL, 0xF90972F44864EF1EULL, 0xF9352079311D4749ULL
        },
        {
            0xAF794E6F61AA8BADULL, 0xA2955C5D16120D4FULL, 0xFD360C064DCAFFFFULL, 0x9CE4F87F362F9B2CULL, 
            0xAE51A8D29A8B6C22ULL, 0x0D8B18B0B9CFE4A3ULL, 0x4D8948FC034FD243ULL, 0xF7D8B6383F02C94BULL, 
            0x9871309DD12D18CAULL, 0xC03E32B76833CF4AULL, 0x9B004FB28CD1B1D0ULL, 0x563E70245629F397ULL, 
            0x31DD182B47B43E48ULL, 0xCA92ADB3676F923AULL, 0x814228370CD38689ULL, 0x4A0F64002082B276ULL, 
            0xCA80665163C4496FULL, 0x0E8750EA7F7A8967ULL, 0xB73891DDEFBB57E1ULL, 0xF0DCFFFD10942328ULL, 
            0x1925F71F14004E66ULL, 0x79C306D9CD8BE935ULL, 0xC0EAAE949F48ED93ULL, 0xD0D5E879E4B50408ULL, 
            0x252B59A7410930C9ULL, 0xBCB07A11149B26B1ULL, 0xF5BB00B870A11A41ULL, 0xC0CE1E98A013530AULL, 
            0x6DA50E411D0E46D2ULL, 0x1D5055B8F1B342B7ULL, 0x6C11A1A3CBEE2D40ULL, 0x1868AF155463504DULL
        },
        {
            0x36135D5962BAF6B4ULL, 0x6AA08EC1A76D6708ULL, 0xD6432170CA81BB25ULL, 0xBE4DE476A30DC810ULL, 
            0xB5CD8B5317932325ULL, 0x5589C9CD60028508ULL, 0xB2D270B80AA0A01EULL, 0x8FE4DC4E3CD69805ULL, 
            0x02C1E75BB39B1610ULL, 0xD44DAB7457C561A9ULL, 0x2BC79912F772DDF3ULL, 0xD56D2C98BC55304AULL, 
            0x4F6AF3A21BF85B61ULL, 0x04F0FD14639F6455ULL, 0x350A1692FEADB649ULL, 0xD911FCE3D7B7E766ULL, 
            0x56E763D189BBA729ULL, 0x2B216666BE3BBEE2ULL, 0x084E131639487FF5ULL, 0x1C5BB235B24DAC8AULL, 
            0x4EC0F1A8F081C226ULL, 0x265507868BF3EA91ULL, 0x8EC197D6579FEFFEULL, 0x590B965609EA3481ULL, 
            0x8DDB47DD72DEC184ULL, 0x984C728A40B5C69CULL, 0xDF173311582B44BCULL, 0x79A0046C14D8D400ULL, 
            0x353133A980CEE0FAULL, 0x4DA32A61E0D6104BULL, 0x5FBC52C7466FB700ULL, 0xC6A7FA48E873FAFFULL
        },
        {
            0x27DDB42990DCDF0EULL, 0xE52E57F5C42D86DAULL, 0x56DD86E0E46F14C2ULL, 0x94ED6EDA8C1C03B2ULL, 
            0xD0F08AA01D8C2756ULL, 0x10D1F0601D0487C5ULL, 0xFC58E0DE3FF60B6CULL, 0x231C4A772A713568ULL, 
            0x93398B053FA2F17FULL, 0xE91CD9E98B7FBDE6ULL, 0x84A5D639986D1780ULL, 0xCC15A8A3806A8375ULL, 
            0x79B3DCB527C8242FULL, 0xCED34CCBFD2DC9C9ULL, 0x66584FA5E5660B8FULL, 0x0C113B5A20FF8E0CULL, 
            0x5174493B7BCE52F4ULL, 0x9D56C7B614C5D059ULL, 0x6FCF73677EA1D207ULL, 0x649FB9AE10855727ULL, 
            0x43C2760913D0273DULL, 0xA3A9AA4576999EF9ULL, 0xC4F8A5A2ADA43C20ULL, 0x7D444BD8348EE9DDULL, 
            0x7081393BBB876905ULL, 0x41AF8EC89FA9DEC4ULL, 0xFFB1569098FAEEFDULL, 0x650426790E17C96FULL, 
            0xB2C24544DCE327CCULL, 0x39765DF144B2A2CAULL, 0xDED19F239E36E0D5ULL, 0xDFB49CECAB255ACFULL
        },
        {
            0xFBBBEB98ABA578FFULL, 0x964867FFFA6A67C4ULL, 0x6D4662084ECC76E5ULL, 0x6DFFFA97B00F2B94ULL, 
            0x476E7419DAF66BF7ULL, 0x34901228745D863DULL, 0x4A5E8D2E6FAA8E17ULL, 0x7F2A187996C67593ULL, 
            0x2133A893E5E01874ULL, 0x2BF18655D4F46D14ULL, 0x99A2173864C0D6C8ULL, 0xA6C67CD0F2B989A7ULL, 
            0x54B483B98126E52DULL, 0xC3B90CC5139FC232ULL, 0xE0D5972C88B5E626ULL, 0x732511898B5D6754ULL, 
            0x78F12A6F143A633EULL, 0x17E9A7DF7BEFBBD0ULL, 0x985AC31133CC2B67ULL, 0x4077BAF77B9B8763ULL, 
            0xCA295EE1BDCAFFB8ULL, 0x6505379C165D1363ULL, 0xA43EFCA7632991D5ULL, 0x174B4ABDCB77C325ULL, 
            0xCC170255FCFEDAF3ULL, 0xD4B7944E8DCA0892ULL, 0x2127BAE35B8CFF5AULL, 0xDB7526790F6A5771ULL, 
            0xB1DB4411DBBFA23EULL, 0x857C8B490E2D0AC2ULL, 0x0CD28D03909B5ED0ULL, 0x7D4348F1B0496F4EULL
        },
        {
            0xD86AD3813A6B3B0BULL, 0xCB3A9962D8123FE0ULL, 0x28BF6136630AE5A3ULL, 0xF9D3F4FD3B26E500ULL, 
            0x6ED7458C4211661CULL, 0x07E0B7DEB7F6E051ULL, 0x24195483256E41B3ULL, 0xDAA0D68B78E31C0AULL, 
            0xC1C4856537EECBFDULL, 0x76D9DF239C66ED75ULL, 0x2598150F2D9F5987ULL, 0xE96006B329A7BF22ULL, 
            0x7903FC6E08833040ULL, 0x4C46D149E7832388ULL, 0x2009A5D5A964B5E3ULL, 0xE197B516B7BF5303ULL, 
            0xA21ADFB452CA0F4EULL, 0x4C831DD3C157843CULL, 0xA324611F99FA30F1ULL, 0x8F23D754E03B383CULL, 
            0x5B1A87B080F2D848ULL, 0x8C0092176602D7DBULL, 0x259E29908D7F4904ULL, 0x3978029CEDFBA480ULL, 
            0x4126814FCF375035ULL, 0x08CFB52D4750CE7BULL, 0x7E147FE8556D7385ULL, 0x6519960AD0554A0BULL, 
            0x38D4EC82650DADB7ULL, 0x9CC1227F6F53C814ULL, 0x412BACE726191D9DULL, 0x805080DA72AE1D79ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Pollux::kSeedConstants = {
    0x7CA516DA3EA92ADAULL,
    0x1F5F518739F3FB00ULL,
    0xED619150FB7E22A0ULL,
    0x7CA516DA3EA92ADAULL,
    0x1F5F518739F3FB00ULL,
    0xED619150FB7E22A0ULL,
    0xF72AE3F14F429092ULL,
    0x3B37DD8D32A9530BULL,
    0x25,
    0x0E,
    0x60,
    0xEA,
    0x38,
    0xC8,
    0xE4,
    0xC4
};

const TwistDomainSaltSet TwistExpander_Pollux::kTwistSalts = {
    {
        {
            0x2EB8FA4D48CE4CE3ULL, 0xABF352622C331CABULL, 0x374776EEADF36E09ULL, 0xAC054D4119B74D14ULL, 
            0x47BFB604F4714BB8ULL, 0x422A673D4868B731ULL, 0xDD27C9D6B69B9C46ULL, 0x0C9B4A6883207CBFULL, 
            0xBDFF2B30A7D85C71ULL, 0x7B60CD811DDCAAABULL, 0xD3805E444ACBCE37ULL, 0xEF85DA5AF4595233ULL, 
            0x556C1198F36BD722ULL, 0x2607CF79783788F2ULL, 0x440FF9BE9CD30841ULL, 0x46B93CC12FA1E61FULL, 
            0x82B01CF9A2EC2874ULL, 0x9D18F43260E15FABULL, 0x6BF7380D6A6B2B8FULL, 0x88B1C384E039DD1CULL, 
            0x6E9A166C3145D844ULL, 0x159F945992F9E616ULL, 0x2AE4EE3C4C882F7BULL, 0xEAE8576E96905C64ULL, 
            0x553F5B94E5D60363ULL, 0x4BFB4E19A53A8AA7ULL, 0x48FC17CB04ADC373ULL, 0xD816B9CB98E6CDC6ULL, 
            0x48B70EB503A54E4DULL, 0xAB7EEEF6551C8573ULL, 0xA462C565B1DA805DULL, 0x4FE0DF26590BC58FULL
        },
        {
            0xACE10DEF57A285D1ULL, 0xA97256E4A4B17FC0ULL, 0x1DEB1396EB094DB7ULL, 0x251B5BFD769C13F8ULL, 
            0x96548A2A702D1A86ULL, 0x36D9DDA8D0443D96ULL, 0x5A82109F1C5D1497ULL, 0x7FDA79F62FEC76E4ULL, 
            0xE9FED6AA19D0F6C6ULL, 0x4FA5504D66FFF9DEULL, 0x18974C60201F189EULL, 0xDA1F0424140085F3ULL, 
            0xDB4810E24730C7AEULL, 0x29EDC5A1E2F8E307ULL, 0x6D7229AD83AA31A6ULL, 0x3FB6AC3DB1429835ULL, 
            0x8B5491D65458F1DDULL, 0xC4F509D2006EF022ULL, 0x348F0F54C84899E6ULL, 0xEAD662E6129F739CULL, 
            0x92D269991B951473ULL, 0xBD96F14C5E74837DULL, 0xC7C28B3394870A85ULL, 0xAAB8E52421D6196FULL, 
            0x8B752DE37DDB6362ULL, 0x455319AAEA5F3392ULL, 0x7E26FFFB3A3DC015ULL, 0xEE6D3F243D47B989ULL, 
            0x1AE7837EF987BF37ULL, 0x23CE675DEF63FED2ULL, 0xFCF2195C25B35DCCULL, 0x1F372ED24FD0E952ULL
        },
        {
            0x59744EF3FB3CA8EEULL, 0xE6E3BDE4EA298706ULL, 0x8E1D27994606C40FULL, 0x032724A5C430999EULL, 
            0x2A67DF999107C493ULL, 0x72ACF5F675CBF6ACULL, 0x6C90902FAED43557ULL, 0x9FE70168C3ABA9F8ULL, 
            0x7F96754D5AA876F1ULL, 0x0EB9868A260EF583ULL, 0xA53AA2C62F83A4C2ULL, 0x06DBA60B0F53099BULL, 
            0x6F967746AB385520ULL, 0x8C039DE59068E762ULL, 0x8265B295AE9764D2ULL, 0x1A317D04842E020BULL, 
            0x84E4F8A1C9CEB6EDULL, 0x806126AC9AEB9916ULL, 0xD539CD57B3EE2014ULL, 0x1A7FF9C1BC026AF4ULL, 
            0x6A3EF9E5C3F0AD26ULL, 0x179CE15E38175159ULL, 0xC8AC532C8161CD97ULL, 0x5AE203D6DBCB2A15ULL, 
            0xC30E8EF0EDCB1AA1ULL, 0x7E7D079D62B5239AULL, 0x594EA40E9EA5B601ULL, 0x57042DD13FF1ABC0ULL, 
            0x41B509D5E89A4E0EULL, 0xF8C7E9828371A5E1ULL, 0x1C82BD44AD03B370ULL, 0x8422E73A93AFB912ULL
        },
        {
            0x287951C784C259EEULL, 0xBA6CD412DAEFAAB4ULL, 0xB94993AD28BA1E4AULL, 0x16072DA661CB6D0CULL, 
            0x95E07BF3A084DB27ULL, 0x9314B14EAF7CC251ULL, 0xD90632656582B340ULL, 0x44834418692EA1F0ULL, 
            0xBAAF99A02DC005DDULL, 0xD2F7309417D581DFULL, 0xC9A0D34F8DC48658ULL, 0xE937269AD02571DCULL, 
            0xFCE12476AA5B4795ULL, 0x3445F89EC90E0B4AULL, 0xCB6B0C7ECD617FCFULL, 0xD8CAF9D8590E87C1ULL, 
            0xAEFD5840F3B2211BULL, 0x7FD7A05FBF44B7C5ULL, 0xCDA9E0AB8FDDD4F7ULL, 0x624B5227FA3A12B7ULL, 
            0x760881EE3F5601AEULL, 0xEB5231032CC8FF51ULL, 0xBFF8CBD6CECDEDD4ULL, 0xF45EC33BDE0AECDEULL, 
            0x684367FF1AE56EE6ULL, 0x9161B3F96FD1A92BULL, 0xF8A0F34EADB217D6ULL, 0x0626F0DFF8A278B3ULL, 
            0x58360DE501B1C037ULL, 0xC5F57C918E350432ULL, 0x7758ECDEFBB3AE07ULL, 0x3D07587201D562B3ULL
        },
        {
            0x0A638395E3EEDA47ULL, 0xAF1316613676C609ULL, 0xCB2B55CB06CDFD85ULL, 0x456ADF79F879AD68ULL, 
            0xCA54412351287229ULL, 0x98C1186E20B1D03DULL, 0xE0C37ADD4ADA3D40ULL, 0xDC66D010472E6349ULL, 
            0x9F7CD08B74EB77AEULL, 0x6F63E9AECB7EF108ULL, 0x3F3200DFE85A331EULL, 0x68D555F4AA3DD06AULL, 
            0xE81BCACBA14A075AULL, 0xF499B898FA45D1FDULL, 0x80E2D0090F1E87BEULL, 0x029A788B0B8E3880ULL, 
            0x041AD11E7857DFAEULL, 0xEF4D9AA09E35A535ULL, 0xAF4D9CE7FBC5D854ULL, 0x712C87B2DD5EA8F8ULL, 
            0xDC83248634D09C61ULL, 0xD6386B69D70483A0ULL, 0x515DC2831EC8FAB1ULL, 0xC55BB1538EA2F677ULL, 
            0x9E856F569DBB0A24ULL, 0x6B242C64398F284DULL, 0x382547B8CE093483ULL, 0xC2EBD93671800E86ULL, 
            0x9CBA1A0ADC318693ULL, 0xECEA86BD27B3E22DULL, 0x5A533F4489769CB4ULL, 0xDB1C4315371A1E23ULL
        },
        {
            0x7565B79ECFA60E8AULL, 0x4664E22E5510F0CEULL, 0x6069E2A94CA16964ULL, 0x24845A21E347FCE4ULL, 
            0xC9E0E6F0730C7ABCULL, 0xA02C9BCEE26CC9A7ULL, 0xA4BFFEDDBB07A9F4ULL, 0x0C4E7CACB5836F03ULL, 
            0x63CA3C1F9CCC793FULL, 0x0CA1DE5BD8009C29ULL, 0xF296B87F637E5473ULL, 0x305226F6E0180A76ULL, 
            0x96FF8F5DE828EB8BULL, 0xFF6D2E4B848B2270ULL, 0x50BD6158FE81BB07ULL, 0xA339B62D0DE0436DULL, 
            0x50127CCFAFB7DB35ULL, 0x07EED91D015C5EE3ULL, 0x60CD086E4C6796B0ULL, 0xF628688149D84427ULL, 
            0x629F642742F43DADULL, 0xD8C3E2EEA45C9004ULL, 0x4F4CA4ED35DAFD9EULL, 0x84E276E9C4705D1DULL, 
            0x917BDBF07D8EF714ULL, 0x15BB3E7EB91245A0ULL, 0x6661C63B4C37B57CULL, 0xB8ADF4D0339F291AULL, 
            0xA0022AE36AC333AFULL, 0xB2C4AE819787B585ULL, 0x68963D2C1777F9ACULL, 0x1AB98BA4FEDDC3B7ULL
        }
    },
    {
        {
            0xF73526D21032B35AULL, 0x42081BD7353182CEULL, 0x93E7C2752E7D2A1FULL, 0x7E8DA6860604D6C6ULL, 
            0xFEDE68B700136420ULL, 0x2C941533A7D8D07CULL, 0xA03D11F6C715D410ULL, 0x6BE0D4D340D8C45DULL, 
            0xD12B959D99131C23ULL, 0xC178E4F0C27C0903ULL, 0x00A35BD089BE5980ULL, 0x72F83976882DC7D8ULL, 
            0xA16CDBBA6A736734ULL, 0x8E1874F72B032324ULL, 0x6C4D00F03AEC9AA5ULL, 0x37ED9FB3300DFA44ULL, 
            0x9A544B66A25AD57CULL, 0xA0589D0EAB168946ULL, 0x857C09D6865B9F05ULL, 0x4AD7A457849909F5ULL, 
            0x144230FE50A8C3A7ULL, 0x22FC124A72BB46A3ULL, 0xBC16D500E3E8E40AULL, 0x665EBA4804A92934ULL, 
            0x81B249551E9B1E39ULL, 0x08030C369EA88629ULL, 0x19ADEFB7E91928ECULL, 0x4DB6F50CC4774223ULL, 
            0x51E05ED4ABE2DB43ULL, 0xEB038DC10CE1DAD8ULL, 0x48D38068C13C9EA4ULL, 0x00B9C319761BC2E0ULL
        },
        {
            0xC0669B1E97C51A35ULL, 0xAF4D94D1C394E081ULL, 0x95119B6E5B8F0083ULL, 0x87CE71AC2D6B0731ULL, 
            0x9925643022293A3AULL, 0x771BF8AB9599B738ULL, 0xFE4136864736D605ULL, 0x90D0768806233E92ULL, 
            0x9B8A8918974F7739ULL, 0x209877354ABAAD1BULL, 0xADE2E3E85761E436ULL, 0xB6C2B3E91189E804ULL, 
            0x167FF4E7D05CCDCAULL, 0x817AE536D0DD1A23ULL, 0x8999DE8847481AB5ULL, 0x203C205C7591B8B9ULL, 
            0x405ABA1B84291132ULL, 0xB7531651787335C7ULL, 0x8B371B329ED058FDULL, 0x43ED7FD41E96F8D0ULL, 
            0xDE692AE9D7978353ULL, 0xC6FF569BC5A333C7ULL, 0xC830921FFA8B03E5ULL, 0x7200AF21528C3BAEULL, 
            0x0C9B8AB38FC877C3ULL, 0x195A6647F8E0F752ULL, 0xDC4D087BF0CB1550ULL, 0xD373E34BFBD37E60ULL, 
            0xAA7F24F4D730E96BULL, 0x6CF90EAD2A8D0FBDULL, 0xC11E89BD4C39C05DULL, 0xEAFB7CC89787D4F3ULL
        },
        {
            0x5E8B181AAFE10617ULL, 0x4F16D28347873F54ULL, 0xB179BCE0A758C767ULL, 0xF4717F6D6D9F01F0ULL, 
            0x7D379600FA945D87ULL, 0x8099D1B5CE59D613ULL, 0x956DF209DD27AF2AULL, 0xC9DC2DA76F477D92ULL, 
            0x84FC94C5C4C16321ULL, 0xF6893A4E2BFA7A7BULL, 0x7A2FBFEF06A426DAULL, 0x5DEE1F1AAA7A04B8ULL, 
            0xB569B683956C10DCULL, 0x777D8F55284B21A7ULL, 0x0776DAEC2B05DABEULL, 0x6C7D738F4B2C82F6ULL, 
            0x84E5302B6DD1CE38ULL, 0xD74A52B3686594BDULL, 0xBEDCB1F382429C36ULL, 0x93E4D94C4C61B2C1ULL, 
            0x7EEED51BC9DA041AULL, 0x2673E86F2ED435E5ULL, 0xBAA0C7CCC84E0909ULL, 0xAB05C0404FC3EB63ULL, 
            0xEC1CAF9FED3B55D8ULL, 0xEA2C2FB57C2E1BA1ULL, 0x6EEE6063945F3D12ULL, 0x09FBFE22C81461CEULL, 
            0x2C5B0FE7762F7D21ULL, 0x9025832770358227ULL, 0x31A8DA0D51037AA9ULL, 0x68F3217F2842C8F8ULL
        },
        {
            0x4B9944F384AD0A92ULL, 0x7276CF7D5092E8FFULL, 0x525C373665427095ULL, 0xEFB5BC811B386260ULL, 
            0x335ACC205FCE8F04ULL, 0x2E19DB256FCE3DF8ULL, 0x24E335D181BC5AB2ULL, 0x53816CB3C23AC814ULL, 
            0x146FA48C649813D4ULL, 0x162D8AC873BDBFE2ULL, 0x37202967269334D6ULL, 0x3E434E27533AA866ULL, 
            0x6D69BA341686D353ULL, 0x9DB460E0FCC6CFA6ULL, 0x0F3CEC843AAF71EBULL, 0xD04011B583453696ULL, 
            0xE2194B4D104E74D1ULL, 0x79E4FADC86DA24CAULL, 0x0EE312E5A9D95464ULL, 0xA8D3BEFBBE3705E6ULL, 
            0xBC8D8292539BF2CEULL, 0x06FDAD03962C3073ULL, 0x1AAC9B952919D583ULL, 0x783977CA9471EBD5ULL, 
            0xC355719FF693114EULL, 0x1AE8DE89FEAD6119ULL, 0xE7E34E685518FC5BULL, 0x5515B987422EF5CBULL, 
            0xC6607F373C232563ULL, 0x656100807E1AFB95ULL, 0x597A222EA4F9DF38ULL, 0x407E5A17B715F49AULL
        },
        {
            0x104F357E5A25976BULL, 0xAA682143C28C7255ULL, 0x94DFDB12D3E778CDULL, 0x5FB6221044B24476ULL, 
            0xA7ADF2C00AA13FB1ULL, 0x1C23D1DC8F1908E6ULL, 0xD0B30E89532A1C73ULL, 0x60BDF70F5718F926ULL, 
            0x72EB92B2F9493030ULL, 0xBD0B5E3ED07212BFULL, 0x63F7D5BFDD7EC46FULL, 0xEFF3A0BBAD6CC885ULL, 
            0x8CA29C90F4D56E82ULL, 0x58955BA8CB26FBAAULL, 0xF525AD0D93E95DC4ULL, 0x50DD99A93187C8A8ULL, 
            0xC9909CFB487E2F5FULL, 0x4D88CF659E4840C1ULL, 0xADFB6BD1D57F0410ULL, 0x54B18B59E0AF86B0ULL, 
            0x526F9F2803DBF0FDULL, 0x4C330872C8F6D38BULL, 0xB1B373595DF635EAULL, 0x98BBD7570F8BCE4CULL, 
            0x11875767F9A61289ULL, 0x9EA2E778E826C31DULL, 0xE9A31359BBF72B60ULL, 0xCB6BEF81DBCD4468ULL, 
            0x225CFAFA1EDED3B8ULL, 0xACEBBAB19B8F70B5ULL, 0x52F76D088FD5467AULL, 0x8A135FDC70D49CBBULL
        },
        {
            0x72F0B38741A39984ULL, 0xCA2A3DFE618B8E4BULL, 0x25C3018B7A90FF24ULL, 0x7461D3E938FBF749ULL, 
            0x6B662A82673EB7F6ULL, 0x2B92310FA72DD742ULL, 0x2D9F8FCF070F1B70ULL, 0x5D89281DDF64EADAULL, 
            0x1912FC725CBE1256ULL, 0x59866A59B879CBD3ULL, 0x9BE1AB8E796466CFULL, 0xD300AD156400103AULL, 
            0x7222ED24F875CAD5ULL, 0x6BEC93214D07D622ULL, 0x62347AFCEDED43AAULL, 0x1C5C6C9072E47829ULL, 
            0x32AC23078DC8EBE9ULL, 0x28423E2C98D23784ULL, 0xFD62451057F38CBDULL, 0x82B4C1B801D1C071ULL, 
            0xA58A8EBF3D693D58ULL, 0x1B8A2F678B1D685AULL, 0x4C1E51DB60C5D1BEULL, 0x15901479F145EFFAULL, 
            0xE6E1C4462F1F0E16ULL, 0xB75F356A1B7AB8AFULL, 0x01EB1043AC5B8F9FULL, 0xDD2894B41D8A452EULL, 
            0xDE0DFCB6D0BBC962ULL, 0x7FD6EF800E79EA02ULL, 0xFE68E311C8F99A1EULL, 0x220635297AC49368ULL
        }
    },
    {
        {
            0x75A0A04DFD49C6E8ULL, 0x6D31BC7045076719ULL, 0x21A9817DE3058AC9ULL, 0x5AC980783745EC84ULL, 
            0x7B3B144A64D1D1E0ULL, 0x3598C405D09E60A9ULL, 0x116949DD86E7EBADULL, 0x9445DBD7FB97BD3EULL, 
            0x40525741D272D102ULL, 0xADD1BAC40E18D6C0ULL, 0x869B2B48CBD5A717ULL, 0xF02B329F50363589ULL, 
            0xFDE0FEB7D8BA7B80ULL, 0x1C28243F69D6F36FULL, 0xE9D2437449B8BBDEULL, 0xF03E8B46DFBE1D76ULL, 
            0x2E36CE90F8038D0AULL, 0xDE82579A4825211FULL, 0xA259EB0D3F79FE61ULL, 0xCA7803EEA7DB0601ULL, 
            0x79E9204528C76DA1ULL, 0xEDDCF9FAA11F4AA2ULL, 0xA1C06FE319F4444AULL, 0xB6F04BC92E1D1025ULL, 
            0xB4189ED34B00CFCDULL, 0xAB966B7630A79338ULL, 0x0BD5D2F2A0A1304EULL, 0xF0B2242870FF7F67ULL, 
            0xB99E814F45DBB282ULL, 0xE8BDAACF1596223BULL, 0x488EF69901C19593ULL, 0xB3A8BE723470CC6DULL
        },
        {
            0xEA97FAA7A1DD1FF2ULL, 0x9573364AE49E548FULL, 0xD0BCCDCC5432C5B3ULL, 0xEAAE2B20177A02E9ULL, 
            0xE2FC00AF3D977E25ULL, 0x6EF93120400830A4ULL, 0x6AAFBA118D111ED4ULL, 0xEB5B2947DD856373ULL, 
            0x931D7B6C98BB1135ULL, 0xBE1339653EBF49EFULL, 0xC5788F3522355F51ULL, 0x79FEB3FB8673C855ULL, 
            0x47FF872B486C848CULL, 0xF85DD22FF7EBD334ULL, 0x947D9B12E849F6FFULL, 0xF39EB93B38F9B39BULL, 
            0x31C39FA9A57535C1ULL, 0xA7EE7BFDE04B3B9EULL, 0x1BD46D041734DACFULL, 0xC8F88440804A31C2ULL, 
            0x06C5FF37147F68B3ULL, 0xAD6334A5CB281F60ULL, 0xED69ED302020D9FEULL, 0x95E8D3C2DF556688ULL, 
            0x9E203E5109D5B01CULL, 0xD62B73E19CBAE5E4ULL, 0x9519A799C3B9C8B1ULL, 0xF83528BB31CB8466ULL, 
            0xFA3B969D0D792B44ULL, 0xA88624C4B525A575ULL, 0xAC95A8E76497EB96ULL, 0xCA0C60219C6DEDA7ULL
        },
        {
            0x97972ED52113D16CULL, 0x17298AE8F7BBB8ADULL, 0xCA8FEC3DC3F9E189ULL, 0x2CB85C4E89F08004ULL, 
            0x7852B0E68C29A4E2ULL, 0xE76DB9C41C8D422AULL, 0x0B3DC5AFA60F9E78ULL, 0xD2AF392506C73D7DULL, 
            0x62F8B9FD19A988ABULL, 0xF12ABEB6F9905275ULL, 0x9C35F0E47C27D3EAULL, 0x16B160D7FDE90088ULL, 
            0x73DCE07D8D305757ULL, 0x1CAF209E08B48DE2ULL, 0xEEB5755DD0A66C5BULL, 0xDDA5D2D1AC4DF4BEULL, 
            0x62A9F0402488F655ULL, 0x1D7B3839D672982DULL, 0xCC14E2175BED5CEFULL, 0x54A6A67BBB69D3DCULL, 
            0x951B1A016E95F9E9ULL, 0x5E4B3BCB73A8AAF4ULL, 0x53EFBEC7F727E0EAULL, 0xDED5EFC0AA4EA112ULL, 
            0xD9FF250561042675ULL, 0x7061E81760BCE60BULL, 0x3C19F2331302C5DFULL, 0xADA85305250E6E6AULL, 
            0x95C42BFBC9A0EECDULL, 0x14442D15096590EDULL, 0x85FA43C596326B77ULL, 0x61A358764B1BD390ULL
        },
        {
            0x7351A4B3A9375DEBULL, 0xC88816F52AB96DE0ULL, 0xA5837AADB63BE954ULL, 0x18575EA7E17E21FAULL, 
            0x7E1DEAFF99170BD9ULL, 0x06BD1DBE4ADEB7A0ULL, 0x267B1809FB4850B8ULL, 0xD2FD9BF1EE98E156ULL, 
            0xC464D7D88AF88754ULL, 0x090A3DFCB6323367ULL, 0x6A0A25AED43C593AULL, 0x9E3DF46BAE78F04BULL, 
            0x3CF686AD94E470EEULL, 0x688D9AA3678B6DA3ULL, 0x6829D3D5D7E1FC57ULL, 0x06A77BA90F4F376AULL, 
            0xE5305B373CA31581ULL, 0x38AF5BA607E1279DULL, 0x1663BA1BA0F3C334ULL, 0xE7B1EF4242DC432BULL, 
            0xE6F8F1A29F18EA44ULL, 0x574CB31869FF290AULL, 0xF8BFFA76665C01E2ULL, 0xC4A08E1CF2E4215FULL, 
            0x6A0196D3EBA327B8ULL, 0x79872CD40B953378ULL, 0xA2D06B1CAEE079FDULL, 0x358A738D80C338ACULL, 
            0x37778CEF20742A0AULL, 0x4F19A7B6EFF14906ULL, 0x108A320079B2C2F4ULL, 0x60768E60F79EAF21ULL
        },
        {
            0xDCD321E3FDC15E8BULL, 0x3BDF08FB138C92D2ULL, 0x7CDC47714E308EA3ULL, 0x515BE09E223DBA4DULL, 
            0xA36342CC023AAED6ULL, 0x2629BB85A31540E2ULL, 0x7B695FCF1A42C536ULL, 0x65403E53EB203D58ULL, 
            0xCF5C3F1172D3C94FULL, 0xA0DE54E2798905D3ULL, 0xD60C6C63514D1336ULL, 0xC3C7802F7753157CULL, 
            0xA9256ED77D0BC5DBULL, 0xE42B61E737B84306ULL, 0x9A14F3CF170A2A0BULL, 0xAF33C2373494EA66ULL, 
            0xD849742EAB7A1D4AULL, 0x599BBF4B93645ADAULL, 0x624FEBC0D131B70BULL, 0xE66441E2A8498141ULL, 
            0x7EC4B13C41643E78ULL, 0x61986D490A0851B6ULL, 0x5F187796309B32EFULL, 0x5155595AE91C7B17ULL, 
            0xA093A96B30BAD8AAULL, 0x8A2C332D2BF224A8ULL, 0x0DE09E7B1D9B28F5ULL, 0xF438D8B4A8C3B81BULL, 
            0xE9D2468581083F10ULL, 0x86F1C1E7529CBCE6ULL, 0x88C80BEEFE77B259ULL, 0x27C4B0C2A49DEAF2ULL
        },
        {
            0xCF220A686C2C9B93ULL, 0xC959307D27531BFAULL, 0x4028691F4CE4B5BEULL, 0x81878D3BF59CF1BFULL, 
            0x308D389193E3C22CULL, 0x6A79792E212F8102ULL, 0x2139F695CA6365F6ULL, 0x7B1D08995FB9BB5EULL, 
            0x52E16E0E6668C4BAULL, 0x875E5917F61808F2ULL, 0x851400CB392D40FCULL, 0xDA1E2F7D89C6EEB0ULL, 
            0xAA3F71F6BB14F997ULL, 0x961A2408F39302A9ULL, 0xA842B9823D11BEC8ULL, 0x6DAF8DFCCE034B32ULL, 
            0xF6B4A4B201B21332ULL, 0x83B449F7C1B76B03ULL, 0xF706FEF0CABEBAB7ULL, 0xB741370F11B04C52ULL, 
            0x34682C7DF72C429AULL, 0xAFDD9EF2E8467819ULL, 0xC6E206B16D8618CBULL, 0x5EC67E61EBB134AFULL, 
            0xB84940FFFCB80F3BULL, 0x7259A56F2C8AA0F7ULL, 0x0BA400344C134CE7ULL, 0x13B41D9BBB838D95ULL, 
            0x5CE4E9748365C26BULL, 0x2B28A78E7DC39647ULL, 0x6B1919595036DF74ULL, 0xCC196E14B13AE327ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Pollux::kTwistConstants = {
    0xF345D150705D0EB0ULL,
    0xB6A2E800BE559DC6ULL,
    0xD029C60E4AF2EC7FULL,
    0xF345D150705D0EB0ULL,
    0xB6A2E800BE559DC6ULL,
    0xD029C60E4AF2EC7FULL,
    0xF33BE2E5F27F0713ULL,
    0xDB51DF2AAD07FE71ULL,
    0x2D,
    0x26,
    0x08,
    0xEB,
    0x8A,
    0x23,
    0x01,
    0xCC
};

