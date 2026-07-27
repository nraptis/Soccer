#include "TwistExpander_Bellatrix.hpp"
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

TwistExpander_Bellatrix::TwistExpander_Bellatrix()
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

void TwistExpander_Bellatrix::KDF_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xEAA52BED9B68EE4BULL; std::uint64_t aIngress = 0xDFDE55F8110A5174ULL; std::uint64_t aCarry = 0xB47188CB879FB9D3ULL;

    std::uint64_t aWandererA = 0xF3FD18EFA88A16ABULL; std::uint64_t aWandererB = 0xAF1F7037F00D3BA5ULL; std::uint64_t aWandererC = 0xDE690A0D46D0D203ULL; std::uint64_t aWandererD = 0x9D57FA6FC6D243B0ULL;
    std::uint64_t aWandererE = 0xE82DE0D6C7B85AA4ULL; std::uint64_t aWandererF = 0xDDB8A8A243F5A0B9ULL; std::uint64_t aWandererG = 0x990154841A0C602EULL; std::uint64_t aWandererH = 0xE014D0DB156A582BULL;
    std::uint64_t aWandererI = 0x85D44D3ED31363C5ULL; std::uint64_t aWandererJ = 0x9F7BF29E18C5135CULL; std::uint64_t aWandererK = 0xBFA449B00B237244ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xB43B2D7D7D630ED0ULL;
        aCarry = 0x8F019E21693C8D55ULL;
        aWandererA = 0xEDDD98135B55DC23ULL;
        aWandererB = 0xB860511356521E3CULL;
        aWandererC = 0xBD08BFB2CA2B9311ULL;
        aWandererD = 0xCD9D5875C1A7F502ULL;
        aWandererE = 0xD0D9CA2659EF2383ULL;
        aWandererF = 0xFCA1B7D259F2F3A6ULL;
        aWandererG = 0xF5C16133936FA1FAULL;
        aWandererH = 0xB77545C6406D323AULL;
        aWandererI = 0xFEF0FA92A71F1595ULL;
        aWandererJ = 0xF6313A8892E70F82ULL;
        aWandererK = 0xAB5727AF5CBF870AULL;
    TwistExpander_Bellatrix_Arx::KDF_A_A(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::KDF_A_B(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Bellatrix::KDF_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xA733D9FFD57F429AULL; std::uint64_t aIngress = 0xA544AEAA5CB531D3ULL; std::uint64_t aCarry = 0xCBC7FCAAF0A6F133ULL;

    std::uint64_t aWandererA = 0xB6C53320EF230ED3ULL; std::uint64_t aWandererB = 0xA90F355FFA686A54ULL; std::uint64_t aWandererC = 0xF88EA398D1D97122ULL; std::uint64_t aWandererD = 0x867A6B7ED7834A4BULL;
    std::uint64_t aWandererE = 0xED7235EE81AC456AULL; std::uint64_t aWandererF = 0xBA9E485352BCAF13ULL; std::uint64_t aWandererG = 0xC80DD116242162DDULL; std::uint64_t aWandererH = 0xEDBDE12908CD14F7ULL;
    std::uint64_t aWandererI = 0xD753E4CF3F2BB90AULL; std::uint64_t aWandererJ = 0x9E880BBB63301FDEULL; std::uint64_t aWandererK = 0xAC2F0E95A951AF77ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0x804659C9B05B6ABEULL;
        aCarry = 0xE5AB413EBEB3061DULL;
        aWandererA = 0xE2C0AE9F1D12562AULL;
        aWandererB = 0xA058F1D643C3A984ULL;
        aWandererC = 0xC87F9A478FD688A3ULL;
        aWandererD = 0xA869FD550FB463DBULL;
        aWandererE = 0xE1C7819E0046B59FULL;
        aWandererF = 0xB111A22F163E6E39ULL;
        aWandererG = 0xA351B86EC909C8E6ULL;
        aWandererH = 0xCEF4C37420017230ULL;
        aWandererI = 0x89F6A2B5A7A5EC98ULL;
        aWandererJ = 0x8A078AFCF4918B1CULL;
        aWandererK = 0xFF4642393380E4D7ULL;
    TwistExpander_Bellatrix_Arx::KDF_B_A(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::KDF_B_B(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Bellatrix::KDF_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB1F7F3C09DFE9EA2ULL; std::uint64_t aIngress = 0xB436DC7B10EE47F1ULL; std::uint64_t aCarry = 0x91B4CD61DBC4B824ULL;

    std::uint64_t aWandererA = 0xB3647CE21C9260D8ULL; std::uint64_t aWandererB = 0xDCABFB8A2F54BB10ULL; std::uint64_t aWandererC = 0xDE7CE303794B77DCULL; std::uint64_t aWandererD = 0xF2C922234B7F6484ULL;
    std::uint64_t aWandererE = 0xC6DF948936DDCE6AULL; std::uint64_t aWandererF = 0xF38894490496E501ULL; std::uint64_t aWandererG = 0xDC914A5F4E6D03FAULL; std::uint64_t aWandererH = 0xE7BC62BCDC00FB93ULL;
    std::uint64_t aWandererI = 0x9BBE3149865244EDULL; std::uint64_t aWandererJ = 0xD0B2DBF706D265D6ULL; std::uint64_t aWandererK = 0x9FAFFFE3A7D48488ULL;

    // [kdf-c]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xB8C3246DFCA280DFULL;
        aCarry = 0xFEB85FA3E65723F4ULL;
        aWandererA = 0xB96AD5BC8E4DB6BEULL;
        aWandererB = 0xD71732E3308F09A2ULL;
        aWandererC = 0x9462D61CF3ED5ED4ULL;
        aWandererD = 0xA4057C498D5CE6FCULL;
        aWandererE = 0xD97062F54DB9CB2EULL;
        aWandererF = 0x8D52180A7D68ABE0ULL;
        aWandererG = 0xF05970AA3AAC02FAULL;
        aWandererH = 0xEAB9429CBCA1256CULL;
        aWandererI = 0xBAF1910C227DAC72ULL;
        aWandererJ = 0xE623965DDF0BC700ULL;
        aWandererK = 0xFD87003665C25C1DULL;
    TwistExpander_Bellatrix_Arx::KDF_C_A(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::KDF_C_B(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::KDF_C_C(pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::KDF_C_D(pWorkSpace,
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

void TwistExpander_Bellatrix::KDF_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xEE6A37E62A748D03ULL; std::uint64_t aIngress = 0x9BD23143BD39E32DULL; std::uint64_t aCarry = 0x8758A6D4620FB6EEULL;

    std::uint64_t aWandererA = 0xA96E011173A66467ULL; std::uint64_t aWandererB = 0xE6D07F47306349DCULL; std::uint64_t aWandererC = 0xB31A33AEA6A48B46ULL; std::uint64_t aWandererD = 0xC12669E3F3137084ULL;
    std::uint64_t aWandererE = 0xCB73352C020460DEULL; std::uint64_t aWandererF = 0xE546E85C5A10D094ULL; std::uint64_t aWandererG = 0x82F5BD508D7E6ABFULL; std::uint64_t aWandererH = 0xFA344A19D3967928ULL;
    std::uint64_t aWandererI = 0xE3408E585C9A9F10ULL; std::uint64_t aWandererJ = 0x99557DBE3D6D3D8FULL; std::uint64_t aWandererK = 0xC4C55F0529CFFFE0ULL;

    // [kdf-d]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
        aPrevious = 0xEE522F72E3238E23ULL;
        aCarry = 0xEF6DB051EA972452ULL;
        aWandererA = 0x90ADC049534170DAULL;
        aWandererB = 0x9F9266AAA6BEF2E5ULL;
        aWandererC = 0xF1BFF6FFBC5B7210ULL;
        aWandererD = 0x93E93A41C3263096ULL;
        aWandererE = 0x9C0A6697F9D814BFULL;
        aWandererF = 0xA3CBCC79AAE6433CULL;
        aWandererG = 0x9D2A86D43CF90B84ULL;
        aWandererH = 0xD7AD02AA705C8191ULL;
        aWandererI = 0xC3F1B11563E83F4BULL;
        aWandererJ = 0xC0F6717A9C1CF5A2ULL;
        aWandererK = 0xB3269857294080C0ULL;
    TwistExpander_Bellatrix_Arx::KDF_D_A(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::KDF_D_B(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::KDF_D_C(pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::KDF_D_D(pWorkSpace,
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

void TwistExpander_Bellatrix::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xB84C4D3D13DAAC6CULL;
    std::uint64_t aIngress = 0xDA9159C2F7B33CFEULL;
    std::uint64_t aCarry = 0xAA9E33A74597E6CBULL;

    std::uint64_t aWandererA = 0xCF818300ED158064ULL;
    std::uint64_t aWandererB = 0xADA0EE9A6430B4B9ULL;
    std::uint64_t aWandererC = 0xFB50F9478C90935FULL;
    std::uint64_t aWandererD = 0x84AF66F36EC14008ULL;
    std::uint64_t aWandererE = 0xD336110F90105755ULL;
    std::uint64_t aWandererF = 0xA2B87D752EB889C4ULL;
    std::uint64_t aWandererG = 0x83FD9C4E6493D234ULL;
    std::uint64_t aWandererH = 0x913921B5B069ABD5ULL;
    std::uint64_t aWandererI = 0xD9E4D1385E0CDDCBULL;
    std::uint64_t aWandererJ = 0x97207C8C81C04C39ULL;
    std::uint64_t aWandererK = 0x8D6A011CB9FFE979ULL;

    // [seed]
    ////////////////////////////////////////////////////////
    ////////        KeyRotate
    ////////
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateConstants), &(mDomainBundleInbuilt.mKeyRotateSalts), pSnowLaneD);
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
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateConstants), &(mDomainBundleEphemeral.mKeyRotateSalts), pSnowLaneD);
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
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateConstants), &(mDomainBundleEphemeral.mKeyRotateSalts), pSnowLaneD);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateConstants), &(mDomainBundleEphemeral.mKeyRotateSalts), pSnowLaneD);
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
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneB);
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
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneB);
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
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneB);
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
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneB);
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
    TwistExpander_Bellatrix_Arx::Seed_A(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::Seed_B(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::Seed_D(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::Seed_E(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::Seed_G(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::Seed_H(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::Seed_I(pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::Seed_J(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::Seed_K(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::Seed_L(pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::Seed_M(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::Seed_N(pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::KEY(pWorkSpace,
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

void TwistExpander_Bellatrix::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xF0427FFF02A66C28ULL; std::uint64_t aIngress = 0x90B65E717A6A963AULL; std::uint64_t aCarry = 0xFF3FA146D57AC787ULL;

    std::uint64_t aWandererA = 0x92BCD0F382C2E41EULL; std::uint64_t aWandererB = 0xE7A108619775A656ULL; std::uint64_t aWandererC = 0xCBC44988056E2555ULL; std::uint64_t aWandererD = 0xB24EFB992DD24B9EULL;
    std::uint64_t aWandererE = 0xEB02A5F8184C1ABEULL; std::uint64_t aWandererF = 0xD609BC75C987F5EAULL; std::uint64_t aWandererG = 0xC99C06F227687225ULL; std::uint64_t aWandererH = 0xA32CC8C816EE6633ULL;
    std::uint64_t aWandererI = 0xA03E054D52EC310AULL; std::uint64_t aWandererJ = 0x9BEF535C49167591ULL; std::uint64_t aWandererK = 0xD91DBA9450BCA1B0ULL;

    // [twist]
        aPrevious = 0xB6749944289A6CA7ULL;
        aCarry = 0x932FE52733E93501ULL;
        aWandererA = 0x935B97F21193F619ULL;
        aWandererB = 0xA3AC0B66E7122F03ULL;
        aWandererC = 0xF0C69D070E550D38ULL;
        aWandererD = 0x94A977B237506F87ULL;
        aWandererE = 0xE5D6515BD92E088DULL;
        aWandererF = 0xA9FC7068BCEE5C2FULL;
        aWandererG = 0xDCDF78B40192A139ULL;
        aWandererH = 0x9024C2A51D1618D4ULL;
        aWandererI = 0xE01D8A33AAB00599ULL;
        aWandererJ = 0x8E296A7D14EA923CULL;
        aWandererK = 0x99585EE31856EDA2ULL;
    TwistExpander_Bellatrix_Arx::Twist_A(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::Twist_B(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::Twist_C(pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::Twist_D(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::Twist_E(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::Twist_F(pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::Twist_G(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::Twist_H(pWorkSpace,
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

void TwistExpander_Bellatrix::GrowKeyA(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::GROW_A_A(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::GROW_A_B(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::GROW_A_C(pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::GROW_A_D(pWorkSpace,
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

void TwistExpander_Bellatrix::GrowKeyB(TwistWorkSpace *pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::GROW_B_A(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::GROW_B_B(pWorkSpace,
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

    TwistExpander_Bellatrix_Arx::GROW_B_C(pWorkSpace,
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
    TwistExpander_Bellatrix_Arx::GROW_B_D(pWorkSpace,
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

void TwistExpander_Bellatrix::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 12 of 33
    // Exploration cases: 0
    // Structural maximin 524 / 674; family total 5939
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
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3918U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3828U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7699U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8149U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8059U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4188U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3558U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 47U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3738U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4008U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7879U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7789U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7969U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3648U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 137U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1780U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2005U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 137U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1465U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1690U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1420U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1870U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1915U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 47U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1555U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1600U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1510U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1960U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 92U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 2U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1645U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1330U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1735U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    //
    // GrowBControl candidate 12 of 33
    // Exploration cases: 0
    // Structural maximin 524 / 674; family total 5938
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
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2838U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7249U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3198U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3108U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6979U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3378U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7339U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7069U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7609U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2928U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7519U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7159U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3018U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7429U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3468U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 835U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 880U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 970U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 520U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 700U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 655U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 925U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1150U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 745U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1105U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 430U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1240U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1195U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1015U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 565U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 790U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
    {
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 610U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 475U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1285U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1060U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldSeedControl candidate 12 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1066 / 1248; total 11984
void TwistExpander_Bellatrix::FoldSeed(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 250U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 678U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 723U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1646U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
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
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 228U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 588U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 498U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 183U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
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
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 48U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 93U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 138U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1848U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 115U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1781U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 633U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1128U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 813U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 340U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1871U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1983U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1578U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1691U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 318U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 768U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 858U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1961U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1713U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneG[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1758U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 363U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1038U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1353U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneH[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1263U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1308U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 160U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1443U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1668U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1488U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 205U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 295U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
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
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 273U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2028U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 948U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 70U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneK[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1083U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1533U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1623U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1218U) & W_KEY1);
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
    // FoldSeed — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1938U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 543U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 453U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1916U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneM[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk N
    //
    {
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1398U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 993U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 903U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1173U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneN[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldSeed — Chunk O
    //
    {
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 25U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 408U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1736U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1803U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 385U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1893U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1826U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2006U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aDestinationLaneP[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }
}

// FoldTwistControl candidate 12 of 33
// Exploration cases: persisted candidate
// Structural distance from earlier candidates: nearest 1068 / 1248; total 11910
void TwistExpander_Bellatrix::FoldTwist(TwistWorkSpace *pWorkSpace,
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
        const std::size_t aFoldBaseA = 5U * W_KEY;
        const std::size_t aFoldBaseB = 13U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 5U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1286U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 971U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1444U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 476U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 10U * W_KEY;
        const std::size_t aFoldBaseB = 4U * W_KEY;
        const std::size_t aFoldBaseC = 15U * W_KEY;
        const std::size_t aFoldBaseD = 13U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 386U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1174U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 904U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2029U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneB[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk C
    //
    {
        const std::size_t aFoldBaseA = 6U * W_KEY;
        const std::size_t aFoldBaseB = 9U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 7U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 116U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1399U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1331U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 836U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneC[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk D
    //
    {
        const std::size_t aFoldBaseA = 11U * W_KEY;
        const std::size_t aFoldBaseB = 6U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 14U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 814U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1309U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1264U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 859U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneD[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk E
    //
    {
        const std::size_t aFoldBaseA = 12U * W_KEY;
        const std::size_t aFoldBaseB = 7U * W_KEY;
        const std::size_t aFoldBaseC = 9U * W_KEY;
        const std::size_t aFoldBaseD = 8U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 341U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1624U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 994U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 206U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneE[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk F
    //
    {
        const std::size_t aFoldBaseA = 15U * W_KEY;
        const std::size_t aFoldBaseB = 15U * W_KEY;
        const std::size_t aFoldBaseC = 7U * W_KEY;
        const std::size_t aFoldBaseD = 15U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 926U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1376U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1489U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 566U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneF[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk G
    //
    {
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 6U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 161U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1984U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1421U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1804U) & W_KEY1);
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
    // FoldTwist — Chunk H
    //
    {
        const std::size_t aFoldBaseA = 14U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 12U * W_KEY;
        const std::size_t aFoldBaseD = 10U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 431U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1894U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1669U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 881U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneH[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk I
    //
    {
        const std::size_t aFoldBaseA = 8U * W_KEY;
        const std::size_t aFoldBaseB = 8U * W_KEY;
        const std::size_t aFoldBaseC = 8U * W_KEY;
        const std::size_t aFoldBaseD = 4U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 746U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 521U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1714U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1196U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aDestinationLaneI[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk J
    //
    {
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 71U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1129U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 611U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1241U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 9U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 14U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1511U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 701U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1084U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1601U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneK[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk L
    //
    {
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 5U * W_KEY;
        const std::size_t aFoldBaseC = 13U * W_KEY;
        const std::size_t aFoldBaseD = 11U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1849U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1151U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 251U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1466U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aDestinationLaneL[aIndex] =
                static_cast<std::uint8_t>(aFoldWord);
        }
    }

    //
    // FoldTwist — Chunk M
    //
    {
        const std::size_t aFoldBaseA = 13U * W_KEY;
        const std::size_t aFoldBaseB = 11U * W_KEY;
        const std::size_t aFoldBaseC = 4U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1106U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1016U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1061U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 656U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 8U) |
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
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 12U * W_KEY;
        const std::size_t aFoldBaseC = 11U * W_KEY;
        const std::size_t aFoldBaseD = 9U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1534U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1219U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 26U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1579U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 0U) |
                (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) |
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
        const std::size_t aFoldBaseA = 7U * W_KEY;
        const std::size_t aFoldBaseB = 14U * W_KEY;
        const std::size_t aFoldBaseC = 10U * W_KEY;
        const std::size_t aFoldBaseD = 12U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 296U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1556U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1354U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 791U) & W_KEY1);
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
        const std::size_t aFoldBaseA = 4U * W_KEY;
        const std::size_t aFoldBaseB = 10U * W_KEY;
        const std::size_t aFoldBaseC = 5U * W_KEY;
        const std::size_t aFoldBaseD = 6U * W_KEY;
        for (std::size_t aIndex = 0U;
             aIndex < static_cast<std::size_t>(W_KEY);
             aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1939U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1759U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1039U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 949U) & W_KEY1);
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

const TwistDomainSaltSet TwistExpander_Bellatrix::kKeyRotateSalts = {
    {
        {
            0x0FEB53AF4B80D2E0ULL, 0xD70D5F4FF7D0DFC2ULL, 0x973C686DE89A39ECULL, 0x6CBAB89887B22BCCULL, 
            0xF1B4DFD82E84431FULL, 0x19FBD8D33B49BD39ULL, 0x9A7B2BB91FEFE41AULL, 0x19C89C52788F9AD8ULL, 
            0x63AA17CA92AF3F73ULL, 0xB44A106509D9247CULL, 0x7DF6120C3DA43070ULL, 0x999C558C4331817CULL, 
            0x7E5D98658C98EFF2ULL, 0x598ED697C9B0F0A3ULL, 0x9F365D908422D282ULL, 0x9C3B93EFB8059DF1ULL, 
            0xAD329468BBCDFBE0ULL, 0x1FC94DE5D3BA3694ULL, 0xF14DD9DECD9C3C0DULL, 0xB9E154905C26C411ULL, 
            0x2BA052FB8F47786DULL, 0xE9413E070050607AULL, 0xCF083ED8FF7EE619ULL, 0x5BC7056B581CBC7AULL, 
            0x6280CA639524C317ULL, 0x6FE6C94F11CB6A8DULL, 0x13C489551E3A7A2FULL, 0xF1133C0393C59BEEULL, 
            0xC9A42CF563BE9B52ULL, 0x3216C77340E904DBULL, 0x14D8D47EF13A5282ULL, 0x6E717A48A8FCE245ULL
        },
        {
            0x01C53A970BA56E26ULL, 0x3803D7A7F567DF0DULL, 0x4016BCD4D04B8A93ULL, 0xB78D2D0201EBECF6ULL, 
            0x9D20D96FE064A6E7ULL, 0xA0D3A6A251CB1697ULL, 0x539E63160DC38109ULL, 0x60A5C436D1C06302ULL, 
            0x0967FF50B75094EAULL, 0x8F82A4E81C44EA88ULL, 0xE101222737FB24ABULL, 0x72FAFEDE8D30E987ULL, 
            0x7060A4C23A2BDA92ULL, 0x4FCBECD28CA60224ULL, 0xB24708322624EE98ULL, 0x920E8395F03F5BEDULL, 
            0xB831AFA5CFDDA9BFULL, 0xFB44631CDC671AB0ULL, 0x8987BC463656CC16ULL, 0xBFECF08CC8A39877ULL, 
            0x7D2795602C2009D6ULL, 0xFA5B78EA820B464FULL, 0x7C973A051944F13DULL, 0x5A3A056B5F054C16ULL, 
            0x2A5BA86E51D0FB05ULL, 0x9ECF703E90431965ULL, 0x8B9861948FC5BF53ULL, 0xFA0CEBD6848D6637ULL, 
            0x2874318022DA2B99ULL, 0x23FD16DEF4F03B91ULL, 0x502AD65FBD5BEE19ULL, 0xF380CEEC25B3643DULL
        },
        {
            0x7BBD62B9E744DF84ULL, 0x19BD70FD48CDCCE4ULL, 0x8F29071AA7D5B32CULL, 0x0067456D162CADBAULL, 
            0x86E3E356ECBF3C13ULL, 0xBE6D6B7B4E9537FCULL, 0xEE1DDB6DF6A388CAULL, 0x4D088005CEF24BCEULL, 
            0x93F43FADBE21ED05ULL, 0x7081253B1BD39E16ULL, 0xD949B9FC7A4BDD69ULL, 0x87B3E2FBC2D74D15ULL, 
            0x2B26648791CCA05CULL, 0xE21C8705AB738F5AULL, 0x69660671E51FAA94ULL, 0xCE64394E241D8125ULL, 
            0x1D333FC38F25A9E0ULL, 0xD3D161854B6A29D1ULL, 0x4D753EDD734EE0A6ULL, 0x672A85715EDDB824ULL, 
            0x19FDB8185C53E1F4ULL, 0x82467C6AACD7CB42ULL, 0x256C2CF2F2FB7482ULL, 0x6F996FD7068DFDD3ULL, 
            0xF187118BB1E1BE9EULL, 0xDFBA1B3770CD17C1ULL, 0x357729FCC10A07BDULL, 0x18C5B9E4C8AFC0CCULL, 
            0xF1A8F3B4F931CB61ULL, 0xB3D1CF8BBCE533B8ULL, 0x61AC316B64F348C4ULL, 0x6DADD6087D10B582ULL
        },
        {
            0x3E7829B8CE635D31ULL, 0x831F5050D7664B08ULL, 0xCF4D34201102B11EULL, 0x6E09B7117DF7BC4BULL, 
            0x459A3A161B02B35EULL, 0x3EC8D1D567DBC7F8ULL, 0x428A977197DB2972ULL, 0xBC23B35E7CDE65AEULL, 
            0x88FFCF055124F80DULL, 0xAA7ED053C4CB68EFULL, 0xE7EED8305662E693ULL, 0xCBF1FF85829E932FULL, 
            0x082664617B9577D3ULL, 0x6C9C68F9B5964CA4ULL, 0x82B9B7DCBCD93AA3ULL, 0xEB9C3172869988CBULL, 
            0x81680A0C441F7812ULL, 0xA8B357B906C6B59FULL, 0x256E60249021964AULL, 0xD97AE2E9EF640393ULL, 
            0x531FD4C8F96CC0BAULL, 0x25CB4447346C8539ULL, 0x256487F39A7AB2C1ULL, 0x7BFCC6EE1FDE39F1ULL, 
            0x003BA344DB44FFE9ULL, 0x2BEB917ED6272924ULL, 0x1E84611B830A3B43ULL, 0xF5BE3DC326E7BA65ULL, 
            0x3E4411C772420341ULL, 0xE90D4A24F8398505ULL, 0x1B23557D89C4E5A0ULL, 0x46D85D8A9A5865ACULL
        },
        {
            0xED788777295B9B63ULL, 0x69CE4D33B79D66A8ULL, 0xB9AC35F0CD3E35D2ULL, 0x75BAC78AFE63436DULL, 
            0xFE03CFA0A6DD31E2ULL, 0x1F4E37EDD817385FULL, 0x0B9E2620FC09FA46ULL, 0x5C45C7FE59320569ULL, 
            0x3D33729CC6A4A038ULL, 0x63102D166E2373DFULL, 0xDF825D7087AD2604ULL, 0xFC0CF6775FB9437DULL, 
            0x9EF5C16859DD78F0ULL, 0xE8760C2B841E3EFAULL, 0xD3AB9BF3EA5C18A7ULL, 0x591C470C24E15D4EULL, 
            0xB38293B875EFFA38ULL, 0x747832698E8F5596ULL, 0xD52B632476A837DCULL, 0xFFAEAA081B66E28BULL, 
            0xDD6BC782F2C63383ULL, 0x92E762F0A32AD9EAULL, 0x174D60B9564074D2ULL, 0xC8320D7E9EBF4942ULL, 
            0xBEDB19863753CBDCULL, 0x38E4ED2741F5ECCBULL, 0xE5C637992109A59EULL, 0x9A45F990F9833C11ULL, 
            0x68BF00745D90A79DULL, 0x1A66AB91A6019A0AULL, 0x7366E10B3E175ADDULL, 0x66F08F7448BD2561ULL
        },
        {
            0x40D1DD4AF39E2E9BULL, 0x1DC9BACC26B88F1DULL, 0x862424DC5A1DED17ULL, 0x24545C42CEA1BB1DULL, 
            0xE49EBE5F513AD662ULL, 0xC2F354BDAEB3611CULL, 0x3C09292BBD7A0464ULL, 0x018B148E4EC9609EULL, 
            0x07F543C9389FDA7EULL, 0xE8B02891C015DC57ULL, 0x6CAC5B58F4B08A6EULL, 0xD952931C67272376ULL, 
            0xD3DA05523CEA48D0ULL, 0x3D625F69AA46FFD4ULL, 0xB8BA6D0D59BE0758ULL, 0x9CDFCD79496B50CDULL, 
            0x5EDB09EDCF1C574DULL, 0xD666C82064D6BD1FULL, 0xD5CF9578489FC8E4ULL, 0x5F8B10CF38EB74AEULL, 
            0x7BC87B1BC6B3232FULL, 0x19B1AA5E16E6994FULL, 0xF9678C2D9A86872DULL, 0x2B769874DDD094CCULL, 
            0x60B7EDF721EA33D0ULL, 0x1F2495A5C7966918ULL, 0xB43CC1D8623B69B8ULL, 0x738AD86FFF6214A4ULL, 
            0xEE654428468632DBULL, 0xE0BAAE03479CAC80ULL, 0x95267BC92F603C46ULL, 0xDB39B7DF8BAD5764ULL
        }
    },
    {
        {
            0x3A6599EDFE52D921ULL, 0x3427F33BD9E62072ULL, 0x7D9783E60744E965ULL, 0x8963E3051A70F830ULL, 
            0x0AC8BA939A5DEE37ULL, 0x2FA33A9BDDB5DF60ULL, 0xED4AFACB5753A912ULL, 0x26836C3200086F8BULL, 
            0xB0AF1F7D6DF1582DULL, 0xFA9B065B519009B9ULL, 0x99A2DD08FC7829A2ULL, 0xB286D9D7A9273B1AULL, 
            0x0737C356C483DEEBULL, 0x4565BA75F4355AC4ULL, 0x8E49F7EAE7C01831ULL, 0x1B6AC8C98348EE4DULL, 
            0xA36884488A60E136ULL, 0x3D2FB9A439200FE7ULL, 0xC186CCCF2D022974ULL, 0xDFCE5BBE06B59966ULL, 
            0x46B000A0466E345AULL, 0x355266F1F8BF5657ULL, 0xFAA0B7E5EFE18CD7ULL, 0xE108CB0C863BD9C4ULL, 
            0x546B4BCB10459CCFULL, 0x7E79CC473953A865ULL, 0xCE1068748344A4F9ULL, 0x8F21115DFFC7F28BULL, 
            0xFCA8E7E45C29188FULL, 0xBF2213823FB5B62CULL, 0x2AADC7E4DF0DA945ULL, 0x95D52C512A364FA7ULL
        },
        {
            0xE94420C0624F5CC2ULL, 0x6BA64C09F42C8B19ULL, 0xCC2F69543929B5BBULL, 0x06E2B32B3C54FE60ULL, 
            0xCBDBBF1E3A093702ULL, 0xBA92BA0A596F2662ULL, 0xD8FEEF80521807B5ULL, 0x429EFE4666997AF8ULL, 
            0x1807A5A2DA754F96ULL, 0xF9BFE912BA45BE4AULL, 0xE99A3114BF389F9DULL, 0xA71A42ACBCAA49E2ULL, 
            0x0CCDE290526353C6ULL, 0x70184C39AEEA838AULL, 0x3719BF8881F2F079ULL, 0x5278299B220DC6F0ULL, 
            0x20985FC63BF618E8ULL, 0xF973F6A87816101AULL, 0x33AA6B5DEE6E9766ULL, 0xAB182C05A22948C4ULL, 
            0xA4A77B2E166D6C5FULL, 0xB54D39C605C6CE32ULL, 0xD6F2BED5DF73694BULL, 0xD0AC80F4132B4E2DULL, 
            0x1A60FDD567832565ULL, 0x99F9313493CCB06EULL, 0xE2500386B0724070ULL, 0xF5D2E739FBD17E34ULL, 
            0x0D9B688BB8A8B1A5ULL, 0x272A0B6348840400ULL, 0x83E50B1CB9E0918DULL, 0xBE7FC37C0557852BULL
        },
        {
            0x9E10B3AE2F57F928ULL, 0x14F681C4D59E2BADULL, 0xE8DB59FF1566F5D3ULL, 0x4C505D5965BE6FE5ULL, 
            0xE3DEDCC2E516DAB4ULL, 0x6CB910627810F058ULL, 0xBCBAD83360B9251DULL, 0x077D0249014B90D7ULL, 
            0xB12B6C9D15314A83ULL, 0x0B30A27574E2B3EEULL, 0xA7A8BC47606E640CULL, 0x68A6D07CBD858729ULL, 
            0x8DADC16C901AABF6ULL, 0x82341DDF4E92FBB5ULL, 0xE51CE70C52DE1B25ULL, 0x7D6D68CAAEC66D46ULL, 
            0xCF3C6FDC98D04F50ULL, 0x8502313C41D5DE8CULL, 0x7AB32893C920D63BULL, 0x0034FE503A604FC5ULL, 
            0xA9B3635EB8537960ULL, 0x3EC9B8B359FA6083ULL, 0x729512CB790069ADULL, 0x6933C7FE324172CBULL, 
            0x58B37549E6D88D4CULL, 0xA847F3309B46D18FULL, 0xE599BC2DDB4C435FULL, 0x1025AD6177FAC961ULL, 
            0x4CD4CF22E487E335ULL, 0xB96CCA37E324B7EDULL, 0x7A424CE193AFB5BAULL, 0xD7E5A4F5DAC07D49ULL
        },
        {
            0x30E2D5E521672ACEULL, 0x3D2CB4A74253645BULL, 0x60BAF51DC62A7F08ULL, 0x0B6B7AF6F64BD075ULL, 
            0xB5E25312278361AEULL, 0xCCD16DB3F97DCA18ULL, 0xDDC9F538898F0232ULL, 0xCAFEFE653EC7929DULL, 
            0xF3EBE5AAD96B5E8AULL, 0xB7DA3254FC7C879FULL, 0xB522D83FF001DCE3ULL, 0x06AD444185982B61ULL, 
            0xEA25325EB7A0CD4DULL, 0xB66B726168EF8CE3ULL, 0xF9EE72308D3979D5ULL, 0xD50AB2F6A9654967ULL, 
            0x5FA40DECE9F56EE8ULL, 0x1A49DA84BEED616EULL, 0x9BDA65CE77D93C05ULL, 0xFDCBA456F077CBF5ULL, 
            0x71452E1B8EF9BE79ULL, 0x2968CC58A5865779ULL, 0x8A232E56E65C3301ULL, 0x2402154BE1E35D85ULL, 
            0x34AD40CB85FA4286ULL, 0x0595E441561DA8BBULL, 0x64E1EB65A4660296ULL, 0x8BEB4D92E2710BDAULL, 
            0x4CA39FC6FEB959C9ULL, 0x68FDA44D789E05E6ULL, 0x249B2FF2FEA509B7ULL, 0x26340690596736E0ULL
        },
        {
            0xA519FE8AA984DE96ULL, 0x2F635244C491D967ULL, 0xA09D9D2C5AF889B8ULL, 0x80BA293444C092A4ULL, 
            0x557D1EA98CEB64F2ULL, 0xABA444B2D8D26A10ULL, 0x7738D7F91A69F92EULL, 0xAE3E5111ED886C6AULL, 
            0x9F8689F620BB1916ULL, 0x15E0700A1F182F4FULL, 0xE66708B634A9426BULL, 0xD7F2D2F5D0185D42ULL, 
            0xE152BDC8473E9370ULL, 0x598B080951820CEEULL, 0x49989B42AC377A23ULL, 0x8A4EBA7F2262E84CULL, 
            0x948FF22F10DB8A9BULL, 0xC228A4DD09EB1463ULL, 0x458212982DC54044ULL, 0x99A0A57642195C30ULL, 
            0x4DC0A0BE5232610EULL, 0x9AAEB5789359E813ULL, 0xDCBE0719AB672461ULL, 0xE85C4A7379806F33ULL, 
            0xA3BE7AB96C1544DEULL, 0x27AC3CEBBFB3E5E5ULL, 0x2982222380C3238BULL, 0x0510079652F57E26ULL, 
            0x7567464BE9C95BEAULL, 0x36B18FF61E7D5F8BULL, 0xBDB1346FA629F44FULL, 0x77E5656B1B5F807EULL
        },
        {
            0x99B0B0F8505F298CULL, 0x7B5515EB5A819A6EULL, 0xB26804ADC8D63646ULL, 0xD51C1FFFB2599F7AULL, 
            0x970E16E83C6C3D9CULL, 0xF368B1746E2E7299ULL, 0x40AE30AD9AEBD92FULL, 0x92E94A9924B079D9ULL, 
            0x3C6C00CD5A496CD7ULL, 0xE451BD01AA019828ULL, 0xD8B7F4B5814911B8ULL, 0x19B17D80BF2FD842ULL, 
            0xCAEA2213299B22CFULL, 0x89520274264086F5ULL, 0x0C6565DE84FDB3C5ULL, 0xA23C552D6887334DULL, 
            0x047312EEA509FCD4ULL, 0x7612C4AAE4A34B8CULL, 0x4D4507EEB78256E4ULL, 0x9A572ECE170E2576ULL, 
            0x44BC17929AB2170AULL, 0x0670493ABEDB84AEULL, 0x54CA03B54C8ED6E5ULL, 0xB5E29134D074904DULL, 
            0xF649D8B02095462DULL, 0xBE9AD2EAE4F99980ULL, 0xD0AFD78F57E48EEFULL, 0xB9F9BFD264AB832BULL, 
            0x5D2D905AA79B305AULL, 0x8AE5E7B44BFDFC5BULL, 0x2AA824D3B0C9E928ULL, 0xC5E8D6C51A2FDE7DULL
        }
    },
    {
        {
            0x4BA94CDA35105ED8ULL, 0x1E0D7B77DF52FAE5ULL, 0xB19E8EB3F7BE2904ULL, 0x43F8A3801E142217ULL, 
            0xB0FB30470D23368CULL, 0xD7ED11D8A8516367ULL, 0x2F3906DF9C08FD1AULL, 0x00A1F8BDE58588B2ULL, 
            0x76B145521073515BULL, 0xCF422E02697E3AE7ULL, 0x03441B57EB81BE2BULL, 0x4CC345E147C72DF7ULL, 
            0x615DA290CC5EEED9ULL, 0x0E68CB6F7C54959DULL, 0xC7D4293E7E21B777ULL, 0x01AFD32DF78F9E50ULL, 
            0x845330B6320F8796ULL, 0xEE8E799790025191ULL, 0x9D40CB50412388B7ULL, 0x6AA134526583A73CULL, 
            0x3D1E05389DB0A7D8ULL, 0x14D7BAA7639EF2F5ULL, 0xFECB7450A1F49711ULL, 0x4847F069633D6B49ULL, 
            0xBD7A6DDF78DD6243ULL, 0x2B436F4A3527088AULL, 0xF1CB7A6ED3EBAD08ULL, 0x2A5A3856A94D17CBULL, 
            0xD32F3E465CE58013ULL, 0x58D3DF8AC95B5AA2ULL, 0xB988A636ED0F42AFULL, 0xCFC4BFA8917F76D9ULL
        },
        {
            0x834AACBFD9FD2218ULL, 0x7EB4F27EBE01756CULL, 0xEFDE51383ECEDC88ULL, 0x58ACD05141D95AB2ULL, 
            0x04CCF570508FA40AULL, 0x2C89582CFD5EF0A6ULL, 0x07AC8BD9B4950F5CULL, 0xD84B3FB5E44B6103ULL, 
            0x6D8EE7DC09DA1F54ULL, 0x0EE7E3B73F44242DULL, 0x9512643DBDA5FA3FULL, 0x0E17F2FF5DBC1E98ULL, 
            0x87AF58266D0F318DULL, 0xCE5C4E562976F62CULL, 0x3B03A15921305290ULL, 0x530F0DCFCBF5EB34ULL, 
            0xE10B3CE985AC87B5ULL, 0x66681E92580883C5ULL, 0x96ACC9567F6A8600ULL, 0xA7F9DB7765FEA380ULL, 
            0x76FB4B2AF480CEC0ULL, 0x9A5DAEF31AF5BC85ULL, 0xDA1816CD3015ED6AULL, 0x3D01F3EFFE88CD8AULL, 
            0x721B297CB1B89EFCULL, 0x381B74007228097DULL, 0xF6EA99EADEC2DCB2ULL, 0xA5342395E3C90FC1ULL, 
            0x1B84A767820A4909ULL, 0xD3DB6A37E501439DULL, 0x66ADD2E2695D1818ULL, 0x9CE49D5328FCF0E7ULL
        },
        {
            0xD01DD9738E9CBAC7ULL, 0x5B5FCF558995F6ABULL, 0xA473160F4D326805ULL, 0x8E3F79FC15C2E816ULL, 
            0x4E5CB0DF0C94DBFAULL, 0xB6E6633E2F90878EULL, 0xA90880E668BD74A5ULL, 0xEE8DE2DA60A987ABULL, 
            0xCB89A152C03D5EEEULL, 0x27FE7BA2AA616434ULL, 0x20C3612D53DBAED6ULL, 0xE6988CCCE22A245BULL, 
            0x657BDEB1DA5EC46DULL, 0xFB42AF4D629D6E9DULL, 0x9272CFFB0CB266B7ULL, 0x51BA638938BD1DDBULL, 
            0x466BFCEC61FF990CULL, 0x536BB8449543BA6AULL, 0x711343CDD169352CULL, 0x6EC9D8EC45E2E41BULL, 
            0x4AAC97EC0F34AD96ULL, 0xAFBA284A00A8F137ULL, 0x8A1C41AB5CB3225CULL, 0xB2D06F48D6DD2A99ULL, 
            0x2A002312884125A2ULL, 0xEFADEA23E449BE67ULL, 0x88CE334AF67E0ECAULL, 0xDB9B80CF83F19D09ULL, 
            0xC41823FEC9D37CC2ULL, 0x5FDE365D53A67FBCULL, 0x1029A57F825D271AULL, 0xFDFF8E4E4380B9FBULL
        },
        {
            0x91B813EDE8B5E07AULL, 0x8E1AEF71836BBFDEULL, 0x6D6B49A268E39980ULL, 0x0A4A80744481430FULL, 
            0xB0E38193F917A910ULL, 0x30F8E185898C9FE9ULL, 0x705F8EB41761B499ULL, 0x35E8E9907824ABB6ULL, 
            0x7D5934A9C6641CCEULL, 0x5D84AD1BEC18212DULL, 0x4431E6F594481FBCULL, 0x543ABE03ACEF21F5ULL, 
            0x7F12F7B7A1B8BC1AULL, 0x5A4F5EA5C5A72434ULL, 0x77CEC05F5BF890CAULL, 0x0386EC75ADED9D6EULL, 
            0x90C65792C3FEEE7AULL, 0xC97A61EBF75D84DBULL, 0x87CC8ED49742ED6CULL, 0xF6EA21EB68968E2DULL, 
            0x452FDAAC07F4B561ULL, 0xD01FF67C35A5E400ULL, 0x61703C19886E8FEEULL, 0xD739DBF82B87FABAULL, 
            0x1545FCCF0878C670ULL, 0x4F489CABC6E142EEULL, 0x46AFB171A7264771ULL, 0x4415C4BAF81B9CA5ULL, 
            0x08D0EAD2E453D4F6ULL, 0x25D5433DF727B92CULL, 0x41140DA1D0D2BB89ULL, 0x280E8432F0CCDC1BULL
        },
        {
            0x3ABB474A31A43827ULL, 0x66977E16E35C37BEULL, 0xC786CF233F36F004ULL, 0xD573FE8B55A2EDBFULL, 
            0x565FAF86A61A0200ULL, 0xA67153A5B61376FAULL, 0x45D897CA310540EDULL, 0x5EEF7CBA877D4376ULL, 
            0xB615C1858D604A11ULL, 0xD7B1CF799209EF5BULL, 0x835517DACA656B1DULL, 0x78BE1318E9EAD51AULL, 
            0x2F725A538025F886ULL, 0xAAC3F8F37C26EA80ULL, 0xBF7F8547C3BBE645ULL, 0xA447B56F8E807E60ULL, 
            0xCFAF82BE6B856FBAULL, 0x5A88D52C44126975ULL, 0x9897382DD66DB539ULL, 0x16424265389611B4ULL, 
            0x9010D8C7AACD83DAULL, 0x54BBD4C667D5282FULL, 0x15A184F0729A8D11ULL, 0xB3832ACC9EBF7E18ULL, 
            0xFB191CC5AB133D03ULL, 0x6600C9D9E4BDBDFAULL, 0xC2B8B275249ECEAAULL, 0xFB6B465021279F19ULL, 
            0xF61E286D7BABA399ULL, 0x9BEFDD4C9D2AEDCEULL, 0xB03A8DBE5933B9CEULL, 0x019295A52A3DC2A0ULL
        },
        {
            0x967B175C233289D6ULL, 0x43AA599C899B0298ULL, 0x46526A74FBDA83C0ULL, 0x0E79D4D8DF796B5FULL, 
            0x283B2B63A7489B79ULL, 0xA849A005BEBE78A1ULL, 0x92A0EAA6735000BCULL, 0x3CBDCE2EDF72CE53ULL, 
            0x5261F726397F743DULL, 0xB03A12B45432608EULL, 0x6C84517270AE4434ULL, 0xE93FE022B8AF79D5ULL, 
            0x8C2D61F251FE243FULL, 0x8DF607B8D24BA168ULL, 0x21FE47981DEF2598ULL, 0x752C9EED5B9D7FBCULL, 
            0x0E6C119B28F5E4ECULL, 0xD141506418936D1DULL, 0x2B2208D5877FCBE1ULL, 0x7A1BBFF8E54487C6ULL, 
            0x7A0F5AE3484E225EULL, 0xC15ADA13AC0A3B61ULL, 0x17A947BF0A2547C6ULL, 0x18F7AC61A063EEBEULL, 
            0xD554AC58D4271069ULL, 0x066EEBF58C1FE82BULL, 0x7817305F46B6A2DDULL, 0xCA678FE1408320A5ULL, 
            0xAFA009161B93D1EFULL, 0x5C75907A5D289E4DULL, 0x7AB3D13E88456A03ULL, 0xE20103D35F5C23C9ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bellatrix::kKeyRotateConstants = {
    0xC2D9C9E7E47BA7C2ULL,
    0xE55EEEA12D7333CFULL,
    0xDDC786782ADFDD3EULL,
    0xC2D9C9E7E47BA7C2ULL,
    0xE55EEEA12D7333CFULL,
    0xDDC786782ADFDD3EULL,
    0x4130F4F0037ED14BULL,
    0xFA89E7A73E25189FULL,
    0x2A,
    0x61,
    0x68,
    0xFB,
    0x67,
    0x26,
    0x46,
    0xCE
};

const TwistDomainSaltSet TwistExpander_Bellatrix::kKeySpawnSalts = {
    {
        {
            0xA58969120FFB173BULL, 0xB574052DC14036E4ULL, 0x842CA7ECE3A954AAULL, 0x8F15105C73807706ULL, 
            0x283A5A6FF0DA311BULL, 0xCB3ED08A5F5B79AAULL, 0xF1118CA8B5C82186ULL, 0xF5FFACAA91CDCE58ULL, 
            0x27E9F0F94E44FDF0ULL, 0xE79E2411501AA2CEULL, 0x3F3DDF2B9BC27D31ULL, 0xD24D5463C08BACF3ULL, 
            0xC83303088157D6C2ULL, 0x145BDA60E0403076ULL, 0x77FB4C4DE79F507BULL, 0xBF98B0873FD87859ULL, 
            0xE30240EE72546528ULL, 0xB8CCBBF2E1F5DDF3ULL, 0x2A95E9240A609E2FULL, 0x64B783174052BA9AULL, 
            0x2563C11B0888C36FULL, 0x69E5655D1C8A7CADULL, 0x7F62546859FB323CULL, 0xE6725C05A72D2FDBULL, 
            0x46A7FFC664C67127ULL, 0x0A5E78769471E48CULL, 0xB14D033F554CF0B8ULL, 0x6844A2833181BE13ULL, 
            0x174A1A626A77F92FULL, 0x5D94662C7C8C01F6ULL, 0x27513C0EF3116E14ULL, 0x112C8902CC93A1FDULL
        },
        {
            0xDA285FCB3AE554F9ULL, 0xD12777E78EE08B1BULL, 0x6B798AB428D29E19ULL, 0x94A39EE79D001541ULL, 
            0xDC41E27E2FF90317ULL, 0x1D469D3E9CA6AB41ULL, 0x5D7CAFA5C63849CDULL, 0x1ABA206834F16A88ULL, 
            0x72DA8015EC1891BEULL, 0x650650BC260C83A2ULL, 0x55129F258B327A9CULL, 0xEEA735E68E7BDBB3ULL, 
            0xFF435B19501FB079ULL, 0x041E0A35384E148BULL, 0x53D11AEA9A6C288EULL, 0x29CD4F5D6A94D4A3ULL, 
            0xD9F07B4B2114C49FULL, 0x9B33F1B149DBD38EULL, 0xF5A57868D301AEFAULL, 0x122CC615069BACDBULL, 
            0xD81E408653BABB1AULL, 0x4B9C7A5B90017E99ULL, 0x1A49B827ADCCB4FDULL, 0xC12D42042E129C5EULL, 
            0x4FA8736A979C4DDEULL, 0x312DB128F3F09C99ULL, 0xAAEF276DD4776D40ULL, 0x93C3C2E53753D11DULL, 
            0x5FC1C21DFD13BB08ULL, 0x079AD1E2577291D1ULL, 0x85CD68AAED5ABA8FULL, 0xC3C70F6B74BA3298ULL
        },
        {
            0xB0BF3FE31C72C5B2ULL, 0x46610F1FDDF91FF8ULL, 0x5E9A8B1E24537ACBULL, 0xD874902989C1BDE9ULL, 
            0xF88620D1B2FA4946ULL, 0xB664B045B06196EBULL, 0xD91AB2D07CC9F2AFULL, 0x73891652F456C11AULL, 
            0x0C7922DD2DD9B8CAULL, 0x6153673C63FF361CULL, 0x583D50E870A60810ULL, 0x71E12C6FDF46BBBFULL, 
            0x88C587FF1EE2131EULL, 0x5CADE348EFF32BBBULL, 0x2BA36C7487871F2CULL, 0x5A6B41B32F4F5EE6ULL, 
            0x5ECD7A8BC74C139EULL, 0x494E05BE8177BD03ULL, 0x9741D419AB4B470BULL, 0x04043C82CFE0054DULL, 
            0x4EF4257BBCCEC32CULL, 0x4A3063A68987B108ULL, 0x984296403F107A82ULL, 0x30A3610B3F3C231AULL, 
            0xD2E8A921730DE644ULL, 0xEC67E5A906BF5903ULL, 0x36CF779DDCDFF44BULL, 0xC0311F495C7A1206ULL, 
            0x103D110D697BC774ULL, 0x2B86BD9C599E4736ULL, 0x5530628421F8538EULL, 0x546368CAAF12547AULL
        },
        {
            0x3D96CC29384CC087ULL, 0x3EC756F6072286D7ULL, 0xBBAB5004520C0F7CULL, 0x6ECFA943AFA62961ULL, 
            0x55FD9724F0FD29F6ULL, 0x8557617F00191911ULL, 0x31F12DBB1FA8A3ECULL, 0xCE15D48392730E88ULL, 
            0xDEECC50D8D73C569ULL, 0xC80A45DAE7987312ULL, 0xBCB2B124E1E43BC5ULL, 0x40A3C9752A6C5F8CULL, 
            0x5C394AFAC630A30AULL, 0x3E60525FEC6064E3ULL, 0x9CDAB474E28B09F1ULL, 0x641269E7B606EF78ULL, 
            0x9ACD85F8776420FDULL, 0xB452E1D164889A3FULL, 0xA61DFECB226B574DULL, 0x4E012CA8C76B8335ULL, 
            0x29BE7023F91C75C7ULL, 0x309725064D91A4C2ULL, 0xA9D0F967A8C8630DULL, 0x178146B6255B9FC6ULL, 
            0x7EE23953BE5BF722ULL, 0x5B497EC537CBE151ULL, 0x0CE12C3020A0A931ULL, 0x2F6E0EB956278418ULL, 
            0x64D98ED60A994989ULL, 0xFEAE9F5318508DDEULL, 0x4A53861FA61A3A90ULL, 0x852DA5E471BCB308ULL
        },
        {
            0x2C75DBBF7EDAE28EULL, 0x5ED079150BAFEB8BULL, 0x74A9FD6A19D9044BULL, 0x22A1A9AB93BCD081ULL, 
            0xAA8EDAD1B0967253ULL, 0xF549358BAE646676ULL, 0xAFEF9B8313EB1E8FULL, 0x9A57899ABECEB7F7ULL, 
            0x5E996F51BFC2480FULL, 0xE6A6A34BC9D3131CULL, 0x2B4B264375DA9274ULL, 0x20684BA5B2B11A96ULL, 
            0x4000CDE43B047967ULL, 0x9B7B9B3D8171AE41ULL, 0x51FED3A522B225B1ULL, 0x40B4C65B4FDEBC7EULL, 
            0x83AFAB1BF1A8A229ULL, 0xC801B5A36B278188ULL, 0x0A3583AA34F0752BULL, 0xFFE8236C2E0003C8ULL, 
            0x73AC64BC22A85D6EULL, 0x2A2651B26CAD70D6ULL, 0x8E93EBBFE016786FULL, 0x64FDDD8F0CA5CA39ULL, 
            0x78574865C16CCFF0ULL, 0xA98F6B587393DC8CULL, 0xBA2987F068770A4EULL, 0xC40119BEE9A24E86ULL, 
            0xE86B9D570C26F403ULL, 0x69904E6A9965AC55ULL, 0x47CE3E8C8A304343ULL, 0xF6382A54B167BBCFULL
        },
        {
            0x96FCECAE703EAD75ULL, 0xB57DFE10EB71D752ULL, 0x23D608B8DC62C418ULL, 0x9ABF486E6FA90B77ULL, 
            0xFE401FCFB8C6AF7CULL, 0xD24DE4489159B117ULL, 0x94F9BC104ACC712DULL, 0xBDB13B2C09E35011ULL, 
            0x7BBF19C0AB94860CULL, 0xDE0853C4E5C8D37EULL, 0x5A3BD6609DD771C1ULL, 0x7D257EF3C59C06ECULL, 
            0xB5EA0B3976222ABAULL, 0xAA84B95E81864462ULL, 0x63D28515213085C1ULL, 0xC2700F8DE17E1996ULL, 
            0xBD556AE17038006FULL, 0x7C7523806180C98AULL, 0x4D4779A483A972DAULL, 0x5D61DD6B6BC1F9E7ULL, 
            0x656ACC0EB251DE83ULL, 0x73E4CFF8CB9D7750ULL, 0x0DBB4D20DE36DFCCULL, 0x5CE22861F62C7E85ULL, 
            0x974629F87274D174ULL, 0x2365AC85852AAD2DULL, 0xB6C660AC5D387FB9ULL, 0x4DA0E7C4E2084C58ULL, 
            0x89DA196F967B7DE0ULL, 0x905F99239CCB0732ULL, 0xE501DA30FDC0FAB2ULL, 0x385BDAB4F7A673ACULL
        }
    },
    {
        {
            0x7A8BB943AFE73952ULL, 0xE67F540A0B127F61ULL, 0xBF0C4A39C2BCF93DULL, 0xEEEE6AF9345CF8BAULL, 
            0x8DE751B5FDCF0E53ULL, 0xE656E6022EE769A6ULL, 0xB4B3E597BDA0EF5BULL, 0x431BC367284D89DDULL, 
            0x294D4483E55F17A9ULL, 0x16DF3943305AF9EDULL, 0x7550AAF3FAC06AFFULL, 0xA11EDDA8CE0ABAF6ULL, 
            0x2E537C5BC715288AULL, 0x755106B3E952DD47ULL, 0x4495AF92D4D57701ULL, 0x806334A97321FF7BULL, 
            0x3F12DD00EF3781BBULL, 0xBD8EEF8EB871B25EULL, 0xEAD4C38D0B224418ULL, 0xFACBC8B1EF42CF2EULL, 
            0x3E09102660C74DB1ULL, 0x0FF71DB31BADBCF4ULL, 0xC36586C01B1F454DULL, 0x235F0A7A5A5892C3ULL, 
            0xA6F56E63780D2C1FULL, 0xD88ED8BBA69757C5ULL, 0x592134686C2F8801ULL, 0xA8B10B18D0768C81ULL, 
            0xBBC8C93E4DB83CDAULL, 0x52338D2817E7F06DULL, 0xD920ED2957B81692ULL, 0x49A392FF791BA70BULL
        },
        {
            0x248CF794AC66B43EULL, 0xB11A5F63BE506ED7ULL, 0xABB4C1A2EF8F66AAULL, 0x2550DE62500C51A8ULL, 
            0xD67BE4EA43FDE574ULL, 0xF7393C7CD74D342FULL, 0x981AE0CDFB2AFF36ULL, 0xD9F9656CA88AAAAFULL, 
            0x487B540393927BCDULL, 0xC8AAF74F3D1117D7ULL, 0x2AED9B37E5C9C701ULL, 0xC43A29F4D78105A7ULL, 
            0x69719A6C4EBA27B8ULL, 0x2589AF62BCEED6E3ULL, 0x5C10C22C1C7B4D96ULL, 0x8CA677258C927393ULL, 
            0xDE2FD838F80F319DULL, 0x31E0665FE2D48CE0ULL, 0xEBB93926A8192E33ULL, 0x4DB2D34A21C16916ULL, 
            0xD15EEC9EDB30C812ULL, 0x87C924676B6B7CAAULL, 0x18015AFF0B53A147ULL, 0xBF19AFA20D48A8B7ULL, 
            0xD742152D5A9D3551ULL, 0x62E196846586D30DULL, 0x241AD4099D18B7CDULL, 0x3DDA13F8F4B383D8ULL, 
            0xBAF811AA7E338ADFULL, 0xCC48CD6006735FBAULL, 0xA77D5F6CD011ED20ULL, 0x2B4A330FA55788CDULL
        },
        {
            0x9CA41A0447C7C511ULL, 0xAC413F8776F5322EULL, 0xC318573478972C07ULL, 0xFAC996C14CF6C479ULL, 
            0xE9772A88A66C2B49ULL, 0xC56736FCD7EDB11DULL, 0x2C0E091B49DF3776ULL, 0xFC0AE48FA2EEA0EBULL, 
            0x9832DBECCB945C34ULL, 0xEA7C1C8B8EB6BDB1ULL, 0x258620698EFBB687ULL, 0x3F2215AEF38E0671ULL, 
            0xF2CC708A509BFFA3ULL, 0x97EBED80200451C1ULL, 0x072548D080788D2AULL, 0x36192E98474479EDULL, 
            0x8F2E70481D731E64ULL, 0xB0F6CE3E31372634ULL, 0xB428C524F5EC1956ULL, 0xFFC0A3FD59624138ULL, 
            0xF674CA0A415D70B4ULL, 0xE762252026E269C6ULL, 0x0F4CB74733AF7046ULL, 0xC637789F5091B8CEULL, 
            0xFF8D150575463004ULL, 0x2E3409DE03448B14ULL, 0x4BB48FA848E4F47AULL, 0xA67EEA5917310EC7ULL, 
            0x74EA8EA58950E706ULL, 0xB0AA394DB740E9A2ULL, 0x65022E72A02072C0ULL, 0xE090F50B105BC051ULL
        },
        {
            0xE027D9DE58418AC2ULL, 0x17FA1FF25DB5D52EULL, 0x0D244E310A43725DULL, 0x12BE6B98B478E3D9ULL, 
            0x9428C7AE25FD1D27ULL, 0xA4AD74251E436CF5ULL, 0x55207D4B869F5628ULL, 0x1188EA55CBDE91C1ULL, 
            0x644D5D2BE02DBF9BULL, 0x33A755DE6E5B1646ULL, 0xFAB664B4F020B69CULL, 0xB65E2273519ADB99ULL, 
            0x13984A9232FC55AAULL, 0x5D70D71C7A44AF1BULL, 0xC5602030713C215FULL, 0xD1405BC17AA93A46ULL, 
            0x12DE8201558CB178ULL, 0xA2DAE869523D3B4EULL, 0xEF1FD8DD135097D4ULL, 0xE239641E1B047C72ULL, 
            0xBE124015E892BD35ULL, 0x87AAF85B100488E4ULL, 0x371CB04426915086ULL, 0x9B42E57707F9D400ULL, 
            0x61163EF7FD510EF6ULL, 0x9F7FFC0AB3E2E227ULL, 0xE7FC0B7BAC143BCDULL, 0xBF6A00350F8DE092ULL, 
            0x94DB44E3E3A1B45CULL, 0x28A5BFA30CBD56C1ULL, 0x216EF2FF34336222ULL, 0x6560EA161C9E11D0ULL
        },
        {
            0xAFD2B9336C7745F4ULL, 0x77557F871175ADB4ULL, 0x3FED31B15E1C0154ULL, 0x8DD0870FB4A9D137ULL, 
            0x8781295548C03CB6ULL, 0x5938D2F99ADEFE35ULL, 0x6CF0053C4D1FF079ULL, 0xCA6AADB4744D3C12ULL, 
            0x031FE50510527828ULL, 0x1B374651C61AFEEDULL, 0x1B1D8686EEBC8890ULL, 0x323E1C2034AAFEF0ULL, 
            0x1FFC318573DA634EULL, 0x122BA7553AD44FF8ULL, 0x5068F99E79F1F3B2ULL, 0xA6B61E7C7B7B0603ULL, 
            0x3475259D76B1C342ULL, 0xED711BD32A636550ULL, 0xB36C31E07B72D983ULL, 0x55421E8216377ACCULL, 
            0x3E44A580FAD51912ULL, 0xEB0B7C3F2FF909E9ULL, 0x6F82ABB2A64B2486ULL, 0x4F3AA5FFCFAA4F0BULL, 
            0xFD9E74FE427FF525ULL, 0x6224D2AADC7410E8ULL, 0x167CD011E31B111BULL, 0x78200A3BE6D65F1EULL, 
            0x6CB4A7971091D23AULL, 0x3545CFA6496B9D9EULL, 0x2152367406EB580BULL, 0xCB9CB855D22FA8A0ULL
        },
        {
            0x2591719CC6C9BEBFULL, 0x006B1180EAC6B41FULL, 0x66D65ADB1BB6512EULL, 0x98285348EE78C9BCULL, 
            0x5EB2208333DF7717ULL, 0xB46FAD0DB8834AD2ULL, 0x4960700851E83557ULL, 0x5E7D562E2DE092DBULL, 
            0x168DC8EF35BA701BULL, 0xCD4F0FAD37D67902ULL, 0xF460FD9EA7FC1BCCULL, 0xC0D2B7BD7C38568BULL, 
            0xC66532483C01860DULL, 0x46129FB517507843ULL, 0x2AC4899B1BC754FDULL, 0xBA61C218C2885C43ULL, 
            0xB0EE6C56F2344D14ULL, 0x7DE121CAE2F18955ULL, 0x8BEC5E4BD67EF94BULL, 0xAF38D5D75409396DULL, 
            0x58F05C413B31FA85ULL, 0xA3B269CB5BE9CBE9ULL, 0xB58617DED6E47200ULL, 0xECFAFFC5B8E00AB0ULL, 
            0x847FC4F07EBFA3F5ULL, 0x34F137D2BBDF662FULL, 0x6C86B012D1AA1B3FULL, 0xDE4510A4185D173AULL, 
            0xB6925B2070874A14ULL, 0x4780B03576175F5FULL, 0x6283F4FF5F3267B4ULL, 0x3CAA535276065989ULL
        }
    },
    {
        {
            0xEE92841E68796794ULL, 0x637EA49A529E1EC3ULL, 0x656B0FCCFC468229ULL, 0xE5582052FBDA3558ULL, 
            0x828FC51C535DE69DULL, 0x03E93CCE267B2C6DULL, 0xDD8A2597F5ABA0A7ULL, 0xAF6BEAA4C6DCE35AULL, 
            0xD8FD96E4CB1ADD4EULL, 0x2A4CDEEF2F39ACC0ULL, 0xF21C416BF73C4E6FULL, 0x085925086FC8709BULL, 
            0xBE9B76C8ACB1119CULL, 0x48212D029B395B6EULL, 0x1D0F44F3E25B5EF4ULL, 0x54590C33C3FBA837ULL, 
            0xE64C39DEA6F5BC84ULL, 0x87BD223E546FB076ULL, 0x8054F872B353A32EULL, 0x7BE7367D9F717DABULL, 
            0x87EB2ED49CDD8E47ULL, 0x7677E38D4322F9C6ULL, 0xE1D5BAA7E0E45B03ULL, 0xEAD224DEE7E54794ULL, 
            0xEE4AB7B23BFFF13EULL, 0xC557FA08B7F30B45ULL, 0x1A06CF04D3ACD7F9ULL, 0x8A274E245F874FB4ULL, 
            0xF1743380B490D4F9ULL, 0x3673937DC7FD120BULL, 0x0FC8DD5180F45922ULL, 0xF56A5A32F87B8953ULL
        },
        {
            0xC7E42BA86700A080ULL, 0x508CE3DE0A5D6CBFULL, 0x854F7B656D31B461ULL, 0x5AEE5CFCF0443147ULL, 
            0xD8F582A4BF2C348CULL, 0x6FA0295D7BBA22FBULL, 0x1736D23967FCE0EDULL, 0x45BB08FEC816EE50ULL, 
            0x79EBA281E25AB378ULL, 0x89A3F525D8CF3A1FULL, 0xDF73420997674021ULL, 0x462F1AB781A53498ULL, 
            0x049BF0D0BFFF1AA3ULL, 0xDF0678D55CEBF2C4ULL, 0x7B4D7F7EA2A7D16EULL, 0x584ADD8F3B484120ULL, 
            0x83DDE19FB5396CC0ULL, 0x0348B6DBA4D50081ULL, 0x8C09824234893AC7ULL, 0xDD7A183CCC9939ABULL, 
            0x901171B4B4368031ULL, 0xA86A115DBB299A23ULL, 0x07867EBC2D0BE599ULL, 0x0625BF3F85702D70ULL, 
            0x0B808139B6C9917FULL, 0xB3071E6AC3EC4B52ULL, 0x150B35AA539A799BULL, 0xE0D97C0B67817C76ULL, 
            0xB7C74892AB1666E7ULL, 0xB84FA8D02DC93BA4ULL, 0x577648BB1566F996ULL, 0xBF21B76C0263A337ULL
        },
        {
            0xFD4F7411CA0C6EA0ULL, 0x3AA53AF8A8874B46ULL, 0xDD6C84D1A707E233ULL, 0xDCA7449AD3DAE504ULL, 
            0xBBB09EEBF1C92FE9ULL, 0x15C90A31EB05C05FULL, 0x8588801A3726C228ULL, 0x60D483F2EFB09312ULL, 
            0x71B11BACB2EEB9B5ULL, 0xF4B989E3EDE00204ULL, 0x1F5A72C7D659CBE7ULL, 0x050303DEC14904F3ULL, 
            0x8869BD7DEF8AAD19ULL, 0x0AAB51536D85BE7BULL, 0xBC7014E92E03F6D5ULL, 0xDFD97E3B81EC759FULL, 
            0x805EEE2464A44291ULL, 0xF87417E51C16E641ULL, 0xD7F01D9EAD8A1C57ULL, 0xFDE8ED188FA49E22ULL, 
            0xE864BCE7FD5CBC26ULL, 0xF28FA8A30E336823ULL, 0x23FD40EF0DDD0311ULL, 0x585CD193F616FBCFULL, 
            0xD686611FE804D44BULL, 0x5C0D2A9057987D8FULL, 0x6B4F738C403BBE8AULL, 0xCA0A1C89B4F7528DULL, 
            0x5980462792270FADULL, 0x463469563421928DULL, 0xE585B2484F651076ULL, 0x8E97E6817806E57AULL
        },
        {
            0x094BCB53D8F572BBULL, 0xA66A50C6E0FB88D0ULL, 0x49CDD6CEBBF60125ULL, 0xAA11043AFAE0FBD5ULL, 
            0x9D7F06C3BC5F920BULL, 0xBA1ADF55CEE50EA2ULL, 0x7DDF4B0C9BC29DE8ULL, 0xA09242BCD5F284C7ULL, 
            0x42FB0569F96DBFD0ULL, 0x5541B2DC7FBEE143ULL, 0x821B331107667876ULL, 0x014E477CB84F7759ULL, 
            0xCAA534BBFA444615ULL, 0x44E18CD53ABFACEFULL, 0x9522DA46531A711BULL, 0xABF5E1F2C8996672ULL, 
            0xB3F50A7388A45887ULL, 0xB1A0ED71043D59E6ULL, 0xE9EC2863E8DA9E8DULL, 0xA55319D43D5E1E3DULL, 
            0xCFC6C01BF6DBCE08ULL, 0x917A44ACF29954F3ULL, 0xA82C1EDEE7C23658ULL, 0x63A920B67B63C270ULL, 
            0xAA2D55F8531AD651ULL, 0xA46A3D97E72B3540ULL, 0xEE6D5D562D8E75A4ULL, 0xC1BE9FDE46FB0F83ULL, 
            0x473C04D270A42ABAULL, 0xE384F49F6ED55D0AULL, 0x7011B8B46DC6F9D4ULL, 0x24DCC51D837F00D8ULL
        },
        {
            0x80548BAC968A7834ULL, 0x8A0BEADD27EEF67BULL, 0x108BD9A5114BBCDDULL, 0xFC37A21100969149ULL, 
            0xEA0F0CB518E82377ULL, 0x3C366D3706898586ULL, 0xC9495C5F95CA7A51ULL, 0x5FF469EF747146CDULL, 
            0x85324A3459C85953ULL, 0xD3F99740A878BDFAULL, 0x1556879954A73D6CULL, 0x202A5E20963CE569ULL, 
            0xA38C13926DAD69FCULL, 0x2444D79DD8267121ULL, 0x3C3C9204764AE084ULL, 0x65BD37C1087BCFBEULL, 
            0x8049C6A75892150AULL, 0x9ED0FE78DCAADC44ULL, 0xC04C915B2593DE37ULL, 0x3ABD68F66AF57F57ULL, 
            0x221B6BCFCEF5697FULL, 0xEC616969D4D9C9BBULL, 0x7FE9991D6E448DD5ULL, 0x270BFE8FF789D43BULL, 
            0xB13E2D74EAC6D48AULL, 0x3E3C835C2FA62565ULL, 0x5F8F6847BC885332ULL, 0xFE1171CEF78F064EULL, 
            0x23E824A7ACCCC68EULL, 0xCC39EED2883EF96FULL, 0xAE80CE4536653698ULL, 0x202D3B62F72B087BULL
        },
        {
            0xB34F9ED2D389BCE0ULL, 0x7C61387D978940BCULL, 0x36B50E8EC6CE4882ULL, 0xDD4C687479055DE0ULL, 
            0x9805C46F9FFFB2EBULL, 0x3FBB665B033E04B8ULL, 0xDF4557E1B48C1A9EULL, 0xCFA0B58DD4145311ULL, 
            0xCD0CE4B62CB1272EULL, 0x562301981891300BULL, 0xCB41A6D9F2B93942ULL, 0x950A494102F760B3ULL, 
            0xE376BDE58D601D0FULL, 0x6EB0408D77FEE14BULL, 0x1318E79093513CD9ULL, 0x87DF7E732BB0B01FULL, 
            0xF6E5F8152A473A7BULL, 0x1A83644E50A09648ULL, 0x3B7DC7FEB60875BBULL, 0x66DCE348A11868C9ULL, 
            0xAF97C7659D21C8B3ULL, 0x22500F528295558AULL, 0x2148263543D08F98ULL, 0x36F96FF8EC1B1991ULL, 
            0x530128A24C60056FULL, 0xA6F6EBB5B5D71DC1ULL, 0x3EAA103F1B2924EDULL, 0x77B5821829E3B614ULL, 
            0x1BDFF4DB420418BCULL, 0xEBC324396B6AA64AULL, 0xF55F042BA0D6E554ULL, 0xCA82CDA58D82D2A9ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bellatrix::kKeySpawnConstants = {
    0xDD71B70ABC138540ULL,
    0xB48789B0489EE33EULL,
    0x2C1F625245A7DAE5ULL,
    0xDD71B70ABC138540ULL,
    0xB48789B0489EE33EULL,
    0x2C1F625245A7DAE5ULL,
    0x73F37151F64B7687ULL,
    0x1564201E7950887FULL,
    0x58,
    0xA9,
    0x9C,
    0xEB,
    0x22,
    0xC8,
    0x7F,
    0x87
};

const TwistDomainSaltSet TwistExpander_Bellatrix::kSeedSalts = {
    {
        {
            0xDA82018925FF4E7BULL, 0xDDE0FDAA1A09AA05ULL, 0x1E9AC027326D6AABULL, 0x1BB241F7D1598020ULL, 
            0xF0C1BAD845A00EBAULL, 0xCAD9DC8032AC3EFBULL, 0x592231AEE1ED4BB4ULL, 0xDF8561CC030FEAFDULL, 
            0x0C6EDF84662AA0DEULL, 0xCB402D17F02DACE3ULL, 0x9F0E928CBE360084ULL, 0x45FEC7C1D2AB0383ULL, 
            0x2615E9EEF6EBC5ADULL, 0xCB1AE15539618DD4ULL, 0x3DF0FD93174BEA82ULL, 0x03192E6964A65F57ULL, 
            0xA56016C5F5B772A5ULL, 0x1589FA7D0B814C1DULL, 0x59E924837DFDFAE2ULL, 0xEE8CE0A8734CFA15ULL, 
            0x6AEAA8BCBD34278EULL, 0x0C4729CCFF3BC7C2ULL, 0x49A9AC1638A61D1DULL, 0xA6D276239BAB604AULL, 
            0x2ADA2D6B456D9E46ULL, 0xB59194F27C29C12AULL, 0x0AA16A13B89BBD63ULL, 0x752614437064386AULL, 
            0x90966A02E3B3C198ULL, 0x0213363AF41A988EULL, 0xBB51FBE8DBD96623ULL, 0x4DEB4A1869F70DBBULL
        },
        {
            0x918767CBC00C7D9EULL, 0xD97231EB20975B9BULL, 0x9745C82510618E43ULL, 0x037F36148E706944ULL, 
            0x5995C2FC845C18EEULL, 0xF51490115620679EULL, 0x6E6EA401C4643AEEULL, 0xECC014DCFB6B536FULL, 
            0x3AACB3F9A3A5EA57ULL, 0xD18F3BA4846A3CA4ULL, 0xB25DB7294C4742E0ULL, 0x65BFA73A02B2A95FULL, 
            0x22EA6ED611F2197EULL, 0x9A8A9ADD56EF8576ULL, 0xBCC1269E831CDC69ULL, 0x4DECDB4F3870442CULL, 
            0x7FE3A7EA1A396C5EULL, 0xEDEC5212B7CE4734ULL, 0x7D66B70F307106A5ULL, 0xDBAA6590510D2A04ULL, 
            0x95322E32E659B3F8ULL, 0x547953468B139614ULL, 0xD92826FC4BB0BE7BULL, 0x41EDC44B0CFE71E0ULL, 
            0x6DA4CB047F2D7D6AULL, 0xB2CE1B63C7F9AAA8ULL, 0x79A123E09ED25DE5ULL, 0xEF1559E09B1D14A9ULL, 
            0x9C363207495E1FC9ULL, 0x06262A7CD3B2720FULL, 0x50294119EE2A3C4EULL, 0x9A82AEEC0578304CULL
        },
        {
            0x1A34986FD40AD064ULL, 0x8175D9C403C41D31ULL, 0x7F9017491826D91AULL, 0x7074FC3F8101D419ULL, 
            0x011CF47D7C0FD0D5ULL, 0x666AF856FC2DA628ULL, 0xA106F3017FD40C7EULL, 0x5E9137DAC5F5FF1AULL, 
            0x889E1231DF0B4339ULL, 0x60C1EA0365A1D68FULL, 0x3B85BABFD23C69B4ULL, 0x4520F958665D4DA4ULL, 
            0xA4E953E7B2EE07DCULL, 0x9A3D80254988968EULL, 0x4868A1A13B2F221DULL, 0xBCF311AE040E1FE6ULL, 
            0xC0BBE135911CCE0EULL, 0x593130EBB00DEB74ULL, 0x5434F889433FAAC0ULL, 0x6AC3566967E8C77FULL, 
            0x3D8C138315B1AEABULL, 0xA240DE3990CE6F02ULL, 0x4C827CFED3C0EE97ULL, 0x22B44E64180AAE2AULL, 
            0xB90F0BD580A75CBAULL, 0x5204958677C2FF9EULL, 0x799C72BAFBB973B8ULL, 0x2F0055B6AE957176ULL, 
            0x0D9CF8F0FE9AD341ULL, 0xA49811FF9F69209FULL, 0xD15B16523E3CA35EULL, 0x6203B76B431EE0C2ULL
        },
        {
            0xB28454385991D1A6ULL, 0x4BDE0BC0814625AAULL, 0x886BBFFB5C9B6953ULL, 0x96A8C90E09BECE09ULL, 
            0x9AAD1A6A2FF12B6DULL, 0xA57538E530376A26ULL, 0xC55651AA369F42F7ULL, 0x078733423230C896ULL, 
            0x248CE21DCD73E183ULL, 0x475F06E28B96AEE3ULL, 0xAA2CE813F8ABA32AULL, 0x0D93A3E59D9D71C4ULL, 
            0x3090F5C14D546D51ULL, 0x3F258125200732A4ULL, 0x05D0FC6DA4518132ULL, 0x3745CAB6A058AE34ULL, 
            0xB7147E2E0986DB97ULL, 0x362CFA4CE14B43E9ULL, 0xF61EFA9F186370B9ULL, 0x3E0263BD49CCF75AULL, 
            0xC87C519037BA225BULL, 0xF60EE70EE07BB964ULL, 0x7ACA21DE4688E7BDULL, 0xA9F47B159218592CULL, 
            0xB640507844E2037CULL, 0x3F36A1BDC3D35B65ULL, 0xC0E50F26D7CF5AD4ULL, 0xB19AF36490104048ULL, 
            0xA588F36D028D1D41ULL, 0x136D1680C747FC28ULL, 0xFEC994EF4DC93D28ULL, 0xFEA81D1C97E09D48ULL
        },
        {
            0xB09B75A6BF6A24ECULL, 0x5B171653E2A18CC7ULL, 0x75DE0C4A694243FAULL, 0xB462D016734CDB7EULL, 
            0x7B2E8DAD26158821ULL, 0x4E51FF35EB8937DEULL, 0x3BA46F156A51D526ULL, 0x5A78582F241CD6E4ULL, 
            0xEC48803CBCCAB98EULL, 0x3833059343FAFA2DULL, 0x77937AD9F9736995ULL, 0x337E8C50EE4D30D5ULL, 
            0x20355365985AC925ULL, 0x40D57F1A68B3D4AFULL, 0x6EE85BF9C0F05614ULL, 0x298C7068D6F40E6FULL, 
            0x8724F875DA737FF8ULL, 0x787028BEA6AB9A67ULL, 0x26D7A3630864BAA4ULL, 0x9B37DC52FB85019FULL, 
            0xF5E5C6BD57DE5204ULL, 0x2C818EB8222291F6ULL, 0x7AFE08A57106B1A7ULL, 0x596D691E439619F1ULL, 
            0x1ABD8FC1BA205C49ULL, 0x55990AFFEDCEFA49ULL, 0x7179643462A70EE9ULL, 0x16F3349F4C414A6CULL, 
            0x12DCCECBE7C6C236ULL, 0x6827A8ABE48B1508ULL, 0xE2B32A2C723AA915ULL, 0xF62B66FEAFE86AC7ULL
        },
        {
            0xC30A981B7A4E5C58ULL, 0x1D6254211643DC26ULL, 0x44D6851006211059ULL, 0x9028512C87B05284ULL, 
            0xD7EABFC23C290CB5ULL, 0x22FE119C0602DA0EULL, 0xD963CF7C3EB33FF1ULL, 0xE065B1D1EF36554DULL, 
            0x6F9EC0C62E2B0059ULL, 0xEAACC89E4F6330F2ULL, 0xB42E885DB80FB91AULL, 0x80CA85FBDC0ABAAAULL, 
            0x7E2B6DD24FFF6AA7ULL, 0xC201C26D2A2FB29DULL, 0x6CE18E11BFBBEF8BULL, 0x2232E078A0846511ULL, 
            0x4D19370CD486C4E9ULL, 0x1DBDC425A8A963EDULL, 0x6FA4C12F1F7813C7ULL, 0x88774806B908B38CULL, 
            0xED3A16080AA603F7ULL, 0xCDB38BFD929B1238ULL, 0x750136B01DB013DCULL, 0x607D8F4797E78D33ULL, 
            0x48FF99EEE96828A3ULL, 0x469EC780E5F025C4ULL, 0x9FAFBE7D644A2C2CULL, 0x7DA3C36706F2F6CDULL, 
            0xF7256B2657200325ULL, 0xA10A9F52CE40A45FULL, 0x29F7D43B1DB251EEULL, 0x1C0CF19B78EB99AEULL
        }
    },
    {
        {
            0xF02D55ED4EC6840BULL, 0x4AA309E3771D057EULL, 0x7FD438B53DF7A655ULL, 0x6A2C326B3D7D6BD2ULL, 
            0x53C71F1F096F9B02ULL, 0x855505C9C04B9C1EULL, 0x0E536269E6900917ULL, 0x0CF522D249E42B0CULL, 
            0x66F12CBB303C3112ULL, 0x9B4D6575600D2564ULL, 0xA16337ABB79DC13CULL, 0xA2E44008085DDBE8ULL, 
            0xCC6572B3D667F34CULL, 0xF6E8E45440686282ULL, 0xEA920AA92827767DULL, 0xC988B07C41CE9D8EULL, 
            0xD0DCE4629E775ECCULL, 0x88B44307DF2EB359ULL, 0xFA5C47E10576FCC6ULL, 0xD8B1D309D2117B28ULL, 
            0x3AD30C9532CEF835ULL, 0xC17567E42284E8ADULL, 0xCA75017BF4DFF7F4ULL, 0x4AA6FAA52061ECF5ULL, 
            0x8CB9B14395525944ULL, 0x7753B0FCAA6C59B7ULL, 0x7561AB4ECE860502ULL, 0xD23887525651F934ULL, 
            0xBEDC78CF7B9FEF44ULL, 0xA262629E187D9AE2ULL, 0x347F05B4324F7BD4ULL, 0xEDB684781FBF3DB7ULL
        },
        {
            0xAA33AF05AED965C2ULL, 0xE2715E2A4944E00BULL, 0x3A6839136B8B89B5ULL, 0x0FE9F33BCA10E89DULL, 
            0xC0F6D354ADD0E97EULL, 0xF46E490266145F5DULL, 0xFDB07FDDEB6F862AULL, 0xFD2D9FA107C23A87ULL, 
            0x1E34F9D3E0BDCFDBULL, 0x96884F81B294AF1EULL, 0xDCB24FBBA167B190ULL, 0x096743CED5C45E94ULL, 
            0x683910C54AEE3FD8ULL, 0xEE71CE00766F4289ULL, 0x4EA481D594FAA244ULL, 0xD997B89B59BE5A7BULL, 
            0x114FD11504356C37ULL, 0x1DC9A75DA0628675ULL, 0x7DDB6095CC4305D7ULL, 0x49C4B79E756C591BULL, 
            0xE659A875FFCF1611ULL, 0x15F0C5CDBA327784ULL, 0x1EE7F22AD8D76A35ULL, 0x19EA9716C983F9D6ULL, 
            0x69B76D615DF58A9CULL, 0xE5976E1137422624ULL, 0xD5A285A772CD2D0BULL, 0x5B2186082967C6C8ULL, 
            0x02A2CAEF3D5C5873ULL, 0xD03949F94816DA7DULL, 0xD030C3E4F4F11374ULL, 0x0AA2A85E219428DFULL
        },
        {
            0xF1BE5C7442BE052FULL, 0x86FC93ABC12CC6CFULL, 0x08FF1BB5A0C4613DULL, 0xC3A238F426662777ULL, 
            0xCFABC5459EC63CEDULL, 0x110A11659BF1788FULL, 0x89E7744A0B07EC4CULL, 0x80F4810AE76AC6BEULL, 
            0xADECFE32F070D795ULL, 0x3C6A05A326B49EEFULL, 0xCA6332A44BDFEC9EULL, 0x4E09B99DAA5C5B0FULL, 
            0x7BEB0CECB4B5DA10ULL, 0xDAD9F55FB5B83339ULL, 0xA7539503CF15A516ULL, 0x7441B1CDFAF0C66FULL, 
            0x599D6B2FD2FF15DEULL, 0x567A82C957F4832BULL, 0x7F3559949F7B4089ULL, 0x1B4322805B53F6D1ULL, 
            0x979CFFC9177421A1ULL, 0xCBF252369757EBB7ULL, 0xCD24E8F04DE05B6BULL, 0x5FD272E467BEE97CULL, 
            0x445820CBBD35788BULL, 0x2810C3755911222BULL, 0xAD4EEAB326406ADCULL, 0x4DFEDAEC8F2AE9A7ULL, 
            0x8EFC2AEE2B9C778FULL, 0xFF7BF106D43EF71CULL, 0xD851E7CC7FCACB6CULL, 0x4A8C7F822EBDF85FULL
        },
        {
            0x0A2D0C6C00B3EDD3ULL, 0xDAB0ADC3435A4EE0ULL, 0xCCA37C3A04C22C30ULL, 0x3E1F7FEF3A0B83FAULL, 
            0xB71B9820AA1B2A67ULL, 0x78305FB2F8E5DCEEULL, 0x958F4CBA8D361032ULL, 0x7E3AE8DE369724EFULL, 
            0xE9D168B628788F92ULL, 0xD8F21642CADAD271ULL, 0x7A45C92DF4F2A1FFULL, 0xBD862C4C4BFF37BEULL, 
            0xCDB83C31AA777C9CULL, 0x6C2A42109DEF4282ULL, 0xDFCAF862090214EDULL, 0xA3B1958AF27898F7ULL, 
            0x99D0B31C427FF7C9ULL, 0xFD740B30F455CFD0ULL, 0xE4AF48E1D5E9BC6FULL, 0xB185FAAD277AE824ULL, 
            0x6DBE87F9AFB676D0ULL, 0xC0064DD75119B773ULL, 0xAF769BF37BDF8DD8ULL, 0xC4E5BB63F355C88CULL, 
            0x343C75227C1C98BEULL, 0x2C4DC705192FE95FULL, 0xBB4D458968968BB7ULL, 0xB9CB381F3D370E9EULL, 
            0x654890ABA1B4B15CULL, 0x3FCBAA569AB7430BULL, 0xA8E5B416C8A5BA0FULL, 0x63C46D78D5E6DC22ULL
        },
        {
            0xA53FD28D10EC27A5ULL, 0xCF2FB28A5F80D75DULL, 0xED3B2121AEF94692ULL, 0x0640DA4F675DF4D9ULL, 
            0x7BCA047E9ED61A98ULL, 0xA005D196AC5C4A55ULL, 0x84B7630A12FFB992ULL, 0x0A79A2EC0510B92CULL, 
            0x7B79B4B58A811DCBULL, 0x9E696674849514A3ULL, 0x5CF0A82B9F4AB220ULL, 0xC0A363D82D4968A7ULL, 
            0x392D74A2D7890471ULL, 0x98863522286E9098ULL, 0xCE5969C3E45F16BAULL, 0x6F66036F1B5ACDBEULL, 
            0xE463B625849479F1ULL, 0x11EE09CF0BE9C994ULL, 0x53BA2CB4C4DCECB0ULL, 0x4A99A21BCF66EC83ULL, 
            0xC7239D4C9CD7CE00ULL, 0xE62DED785ED8BEE6ULL, 0x545388E5B3637F5AULL, 0x638748AD0FA32365ULL, 
            0xEE0F8C0FD23CC8F5ULL, 0x35F87FBF657CF35EULL, 0x92621B08D11AAC09ULL, 0xC9A38A260653AC55ULL, 
            0x0173005B24307FF3ULL, 0xEC2D7AE978DEB277ULL, 0xFF16E8BB962C8D95ULL, 0xDEF4492FCFD36E64ULL
        },
        {
            0x4C02E46D27AFA83DULL, 0x3E6CDED17E8696EAULL, 0xC51A6DC25280BD71ULL, 0x3DCE90AC45660C8FULL, 
            0x629C7B0580BF2163ULL, 0x8C48D7914D4EF8E5ULL, 0x66579B48AEE21E20ULL, 0xCEEE805A5692AE65ULL, 
            0x8D95EC7645E10017ULL, 0x2434507001B146C6ULL, 0xACCAF945FBFB3730ULL, 0x091744651CBA974CULL, 
            0xE9ED62766EB52A9BULL, 0xBDF9EC836AD128C7ULL, 0x5C736F16FA87A3F4ULL, 0x34AC99B1DB5DF8C1ULL, 
            0x655AC8C3F1CC47EDULL, 0x51724B9D99300559ULL, 0x04066FCF557F5A4CULL, 0x52C5E7D457C199DEULL, 
            0x7DFD4C78C468E21DULL, 0xDA5838C9FB62BC5BULL, 0x486174EA985466B2ULL, 0x191D90F882CEE5B0ULL, 
            0x60A09DF287B780B9ULL, 0x8840C7D79C88416FULL, 0x68A6EDF57B1CEED5ULL, 0x3B0E5A0777B1351DULL, 
            0x35E89ADA79026241ULL, 0x27DD2203BF2782F2ULL, 0xE14D088D5FC28BA2ULL, 0xB87C34EFC1681A43ULL
        }
    },
    {
        {
            0x541D1A1FED413AA6ULL, 0xC339BABA5E393F16ULL, 0xDB9665C996117FD9ULL, 0xF621DAFBC32255CAULL, 
            0x72BC63ACDD6A3309ULL, 0x33056ACD8CB840E4ULL, 0xA6A3CAAF0945E5E8ULL, 0xF019EC89727F3793ULL, 
            0x40A9F6F8823E0693ULL, 0xDF91329DD11D6970ULL, 0xF44E671241297B46ULL, 0x5D4E5DC359F9630FULL, 
            0x74F96B8D4972D443ULL, 0x66FFCC99E6F7ED5AULL, 0x0015FB7BC11BC61EULL, 0x81549A88CC0131F9ULL, 
            0xD49E5DB95C8B9F78ULL, 0xBCD2C2F4E5B6174DULL, 0x9FBE775DC45D551DULL, 0x2BE4B15A2EEF1D47ULL, 
            0xA8B2DC86FC22A703ULL, 0x59FD1E5C5774D9EAULL, 0x5F9F8F096A894011ULL, 0x71C9D2194E7F4B3DULL, 
            0x05EE0751B0D3ACCBULL, 0xB292524DF72EE678ULL, 0x6DE8A85D2831BC6AULL, 0x4769DB3970653C16ULL, 
            0xFA381B96EA898F7FULL, 0x2A4BADDFE44FC773ULL, 0x11B853B79ED869CFULL, 0xDC51A24216E9F6E8ULL
        },
        {
            0x4E0BA72DE66BB0BFULL, 0x8FCDC0FB5FDC135CULL, 0xDFD8DBC2D8D9F021ULL, 0x75BD00329A6DBFE2ULL, 
            0x940D69EF7C7F64E0ULL, 0x0EC90E567919D42BULL, 0x52A657B1AEC64BEEULL, 0x10538E781303CE2CULL, 
            0xF2C1967045F09A5FULL, 0xE8CA58C0BCA0FD1EULL, 0xC3E39CD768E41353ULL, 0x0BCFBA569B3AEFC0ULL, 
            0x6B5E44C3941BA402ULL, 0xD5D1F5C132792D26ULL, 0xB72A8F0D05D83054ULL, 0x74AACF5422DF84B4ULL, 
            0x746B6865A095E6F6ULL, 0x45FC4AFCA4F0AB18ULL, 0xF12DE41906C2B0E9ULL, 0x2D7CEEAD49296B33ULL, 
            0x0E235BB9934D0245ULL, 0x32694910DAB17206ULL, 0xD846B6C78E613BB1ULL, 0x724A6D02974A056DULL, 
            0xF48B592B7F8BC1B5ULL, 0xC3163FE074F12173ULL, 0x77855AD9776AB683ULL, 0x844B8BFF71B42FA3ULL, 
            0xA1E201F74702027DULL, 0x1D536E68009028A8ULL, 0x564E843CA48C7FFEULL, 0x243A2E7C1C290378ULL
        },
        {
            0x05CDD38411EEF581ULL, 0x48F01BC21AE6A266ULL, 0x7A1E9954F41D8D7DULL, 0x725EDCF4D33EF555ULL, 
            0xBCA44B02D38593FCULL, 0xC0BC24005B460530ULL, 0xD1235F51A581204DULL, 0x9757355C95067006ULL, 
            0x567BBAA94555ACA6ULL, 0xAEFC3B300B8FD325ULL, 0xEA4BD1F41E727D29ULL, 0x282C6F1966E3CF80ULL, 
            0x2043722456972ABCULL, 0xF223FB65F9FD886BULL, 0x5189987BB69A497EULL, 0xF5F634C3648C9F07ULL, 
            0x16517A4815A709C7ULL, 0xDCC23EC7F02FF79DULL, 0x89A433E699E486A0ULL, 0xF8F1EBB9D7C303E0ULL, 
            0x700ABFB833528D75ULL, 0xA2572E7927C74C71ULL, 0x18BF253A437D715FULL, 0x66A0A620E51EC173ULL, 
            0x1754B432EFA8FAC7ULL, 0x84E74C5AB1548B73ULL, 0xCFAA4849551FB450ULL, 0x57E0FEAF8885D6C3ULL, 
            0x65D1DA2581D13E62ULL, 0x02576686471EE551ULL, 0x6E5EBB260303F2BAULL, 0xB4BF67138159E101ULL
        },
        {
            0xC39DBD913CA6715BULL, 0x91B539DDF37F724AULL, 0x28FC4201F4064FACULL, 0xF7FE159AC0F12D2EULL, 
            0x50A2CBE018524814ULL, 0x19CB495DE0617FB8ULL, 0xFF279793A1EF90FFULL, 0x9CC8309F7A3A2982ULL, 
            0x517BA1968A91BC8CULL, 0x6EEED7055818F836ULL, 0x1D80CC0BBB2836C3ULL, 0xC4E976544F8B7849ULL, 
            0x54426AE43E338B5FULL, 0xF53458901F16B3E6ULL, 0xBB74E33DE83AE34EULL, 0x6D7ADC2721ADFAB1ULL, 
            0x27BF04340B338C0CULL, 0x7666EEF3A4998A04ULL, 0xE11EB809C29A0298ULL, 0x2CB8A9B31AD12624ULL, 
            0x9C526512E4EBA7E6ULL, 0x03BB66E7D6F6F6DDULL, 0xC62B2A463692287AULL, 0x8366FF893F9C37A5ULL, 
            0x8F50AB5E088F514CULL, 0x46A3F9FFDD43756BULL, 0x028F9303FA7EC576ULL, 0xA70766BE87A30139ULL, 
            0xCC5B4CCCE7D8476BULL, 0xEE2E3B00145ACA92ULL, 0x15ABCE44D753E6A4ULL, 0x25C7A84BB0B7F2E8ULL
        },
        {
            0xC5C76E6CE693EBD7ULL, 0x3410C1EEC7EF9B0CULL, 0x24D660492DF37FB6ULL, 0x973FA488DFBCC88AULL, 
            0xC8C5696FC90E95EEULL, 0x90AA188A95824810ULL, 0x586E15E27E6DDF81ULL, 0x269370FA91FF4629ULL, 
            0x28727ED3D9D3C96BULL, 0xE78BE27ADC5CA200ULL, 0x13EEA72B51F6D28CULL, 0xE62729678584E9BAULL, 
            0x43DCE19AC7A34404ULL, 0x2917D22170BC57CAULL, 0x574544D5854BFA15ULL, 0x9A20C1C49A5521B7ULL, 
            0xE666F6539C681280ULL, 0xC263FD64FC4C9002ULL, 0x4B45843C610BE56BULL, 0x48C4F3462FC1D4C8ULL, 
            0x0F9BA7ADBBCF489EULL, 0xD9B91669D4E6A699ULL, 0xD68A72A0D5EFC600ULL, 0x9E282C2388E41E5DULL, 
            0xB6B4A6F522B16247ULL, 0x880E7104DF0D5ACBULL, 0x305F15ACCD310F6BULL, 0x3B5E259CB8D99209ULL, 
            0x53289FC442FC97FAULL, 0x5F5105EE3DFC8189ULL, 0xBEFA8D558365A6EFULL, 0x82CCEA089103400DULL
        },
        {
            0xF51ACDCF6731F93CULL, 0xBCCA14946DD2D3C3ULL, 0x9081520D3CE5696CULL, 0x0A49E33D1392E64DULL, 
            0x1062CB705AEAED85ULL, 0x889E005A953BDD88ULL, 0x1F8C8540DBA5DBCCULL, 0x2770B73731E7DD9BULL, 
            0x04B66DF083A25CDEULL, 0xB714EE28C0DF27A0ULL, 0x622CA4CD180B6763ULL, 0xF9224FB448F8D248ULL, 
            0xEEAD58E19537C82AULL, 0xB60B19413BED0912ULL, 0x1D08C30240AB180FULL, 0xE942F4021D63A29FULL, 
            0xDFD3461C46298F54ULL, 0x6BF4A83BDEE61F0DULL, 0x8244C8D3A2D6B052ULL, 0x50C8C78C80B280EBULL, 
            0xD26583BF7D3514A3ULL, 0x691D3190C5250EACULL, 0x063CA1BE0A8EB2ABULL, 0xCF24F0E9E33449FEULL, 
            0x2B38044E61A5E218ULL, 0x6D0457A4D7DF4E3AULL, 0x0CEB173216E2A5BFULL, 0x7ED6DC69D1E42B52ULL, 
            0x88AB72DB6E06CEE5ULL, 0x5D478278AFBC8FF0ULL, 0x1686374C29F7D12EULL, 0x01916A3E49A4CEBAULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bellatrix::kSeedConstants = {
    0x716AFE47ADDC7351ULL,
    0x889E6A3698EE83ECULL,
    0x7604FF12DA7195CDULL,
    0x716AFE47ADDC7351ULL,
    0x889E6A3698EE83ECULL,
    0x7604FF12DA7195CDULL,
    0x176ED8D66AE01C85ULL,
    0x048AB1580437C07DULL,
    0x3D,
    0x43,
    0xF0,
    0x1A,
    0x09,
    0xCF,
    0x45,
    0x60
};

const TwistDomainSaltSet TwistExpander_Bellatrix::kTwistSalts = {
    {
        {
            0x4B1F2A3272E843BCULL, 0x47F574AB6EA4AEEAULL, 0x5901B3FF4AA9DB35ULL, 0xDB6BC4A3D880647FULL, 
            0x75EE3535FC0C6F1DULL, 0xC0D11F0DEAAE949FULL, 0xB9AA317CD65C13F8ULL, 0xB65E635579B89F21ULL, 
            0x4DD4B52A0C275BBFULL, 0xFF1DA00E63E5BF2CULL, 0x20826F95E4E1FB4EULL, 0x8AD50C851F7B24DAULL, 
            0xDE259E38FD6969F6ULL, 0x309F8B3FF3D9373EULL, 0x060263A2438505DCULL, 0x3280160B9AF4CBCBULL, 
            0x7EF0FB0A27DA4AE7ULL, 0xC62AC6BAABCDBEF9ULL, 0x3073187B705346EBULL, 0xF172DFAB73A6BEB2ULL, 
            0xFDC3ACEC630C7F22ULL, 0xD2D5A665B07FDCBDULL, 0xA755EF91DF481B6DULL, 0x6640F13A58D5849CULL, 
            0xBF098DADB3E1ECF4ULL, 0x35F21775E2287B9BULL, 0x456C618A0BF060DDULL, 0x6927AF672DDB571BULL, 
            0x85C2BC64A8D83320ULL, 0xB647C61690564875ULL, 0x6C5E99A6E27A9CDCULL, 0xCBAB99AC56B63316ULL
        },
        {
            0xD6138CE0E475ECD1ULL, 0x2F94DA70CEBEC0A1ULL, 0xFBDF996232D1B565ULL, 0x06D32ECC0CBF5ED8ULL, 
            0xAB440163A0DB9F17ULL, 0x253871000A7A4202ULL, 0x2EF411BF7BBF2AD6ULL, 0xFA0038954842F893ULL, 
            0x9CE3CBB3DC52F6A1ULL, 0x9B06344A2C7DC126ULL, 0x55B8CEEAA6F75EE1ULL, 0x3B601DF208744255ULL, 
            0x80EAC91B2505BDC0ULL, 0xF968FE482804E918ULL, 0x0AB32606A2B49FD3ULL, 0xE5AE4F47CE8AD2C2ULL, 
            0xD42CD2A0D5EEBFA6ULL, 0xFBE250E05E0D5856ULL, 0x5784314B7930D3C9ULL, 0x73698118E8B5E4CDULL, 
            0xA08C07035E725FC7ULL, 0x0A3C2DC572DF70DFULL, 0x10023846C18D024EULL, 0xA6B1AE882E18C021ULL, 
            0xE95DE452021E1F6FULL, 0xDDBFA05A133F42E6ULL, 0x5CE56ED1503E47E2ULL, 0xA14818B9570FC331ULL, 
            0xE12DA1C35D1AA9A9ULL, 0x7EE35440A824B2A0ULL, 0x2F34FC9EEE2B0B09ULL, 0x457060AFF0F98266ULL
        },
        {
            0x666989EE140C557EULL, 0xB4294B928CE14BB9ULL, 0x0702E4FB9FCB007AULL, 0xD8D38A04FCCAC406ULL, 
            0x91B0332E1E80D69BULL, 0xE8766C0505429398ULL, 0x44702B502D7FEC99ULL, 0x5F698FC9B52ACA5DULL, 
            0x0A75A336733C454EULL, 0xED99B897BF4DCC92ULL, 0x6298BD4F9443CEFAULL, 0xB1900740E3B152D3ULL, 
            0x1AA83F331B7D9AD4ULL, 0xC5011D5523C8B533ULL, 0x5DFED7F47E483A81ULL, 0x8F43C2AD6FC1B879ULL, 
            0x012A105D030BD8DAULL, 0xE54EF155F907F96DULL, 0x9ACDDEC7024A66C5ULL, 0x92992DA1F713FC26ULL, 
            0x0BDB4F3DFE8F22E4ULL, 0x9EA9D2949C7DDABFULL, 0xD6242A8F8E63E95AULL, 0x95C69B2EDE1A25E3ULL, 
            0x3C6B1D59794985B1ULL, 0x1B6FC98FBE94CBB8ULL, 0x64B6398C451CD06CULL, 0x3E301834D57ADC3FULL, 
            0x613875BD637E2510ULL, 0x553D3D32B9AAA6C4ULL, 0xD6C2635A9905F706ULL, 0x24186BB746458F1EULL
        },
        {
            0x4A027F5DA7B10079ULL, 0x957707872DED7878ULL, 0xB5BAAA6E4E928D09ULL, 0x73931E41ABEB72D6ULL, 
            0xC8F324EA58CB7F41ULL, 0xC69900807C5A4432ULL, 0x57D155FFB9F2BEDBULL, 0x6AF42304979A1C3FULL, 
            0xF183C84E42D1C562ULL, 0xCF940F4A1D4CC4D9ULL, 0x8F89347FADBDF2C1ULL, 0x556D2543418A845DULL, 
            0x7217150FE7F85E7BULL, 0x43FC586A8C912F9CULL, 0x66102D55757CC7FAULL, 0xB5F65079A1CFEA75ULL, 
            0xF250886D8C4A773FULL, 0x03975950A92B0F40ULL, 0x7AEE471A9C5E2FCAULL, 0x5754623B16106708ULL, 
            0x25F8A67D4DE0EE2DULL, 0x0B57F9293CF5E1B8ULL, 0x7CB332B16E29AD53ULL, 0x7D1DB0D5321B330FULL, 
            0x9ACBCA16788CC807ULL, 0x9C60EF7CA5514B95ULL, 0xB4AB9BC3D7CC9B5AULL, 0x6C0EA6022EBF34A9ULL, 
            0xDE01DBF6B5A506ECULL, 0xFF22130467F3774EULL, 0x1B0A8F4F7EB7B843ULL, 0xCF1688884DA52395ULL
        },
        {
            0xCDA9296799F88B69ULL, 0x11349188E5AD92C8ULL, 0x90E965387B77198AULL, 0x8D22D3D8C27EF1EBULL, 
            0xFF9400F6E6651A97ULL, 0x815198EB45B8F050ULL, 0x99B74D7B6B56F283ULL, 0x7C385721E5A39589ULL, 
            0x15E8C84156C43BA5ULL, 0x5D4E90701EBC8F22ULL, 0x5C83874ADD96F439ULL, 0xCC4037E41061D596ULL, 
            0x39FF41E704FD2ABDULL, 0x899C6059DCD8736DULL, 0xF6854126B7A5AD08ULL, 0xE09DBE7D321FD398ULL, 
            0xB8442E475C75B392ULL, 0x9B0136276BE44609ULL, 0x7FC9AA1F72264DBAULL, 0x4B2FDA591AE778A1ULL, 
            0x2BC601CFDF9415BAULL, 0xA2EBEFD1D192C8CCULL, 0xCCF9753F33320815ULL, 0x4548290B485ED400ULL, 
            0x929B201A70131AEBULL, 0x50392A59DF2F8A96ULL, 0x5F84142A0339685FULL, 0x89EFDF04F551B5C5ULL, 
            0x56D0CC5711AABA3BULL, 0x1DF4408314BEC307ULL, 0xA8DE74FA87D1FE93ULL, 0xB6539E18E77C60CBULL
        },
        {
            0xE6EE903BEF3633CAULL, 0xC213AE8781BAEED4ULL, 0xF52216307EFDD0C5ULL, 0x4739A024505D9912ULL, 
            0x8C2682BB2B471B91ULL, 0x00286D26E759466CULL, 0xE45F3B5D7F63ACD2ULL, 0x239C16E55AAAA847ULL, 
            0x66FE024E4F91DA74ULL, 0x7C74C96610CD1827ULL, 0xC6AD35DCC81443CBULL, 0xE9001B5AF437B9BEULL, 
            0xE12F154A37006DB1ULL, 0xBBB803E7BFFB0F28ULL, 0xB6912D9142884F1DULL, 0x3A79FD0216E46E88ULL, 
            0xAB0659213D80225DULL, 0x6AB59980724A3B36ULL, 0x39F8D7B37D75E67FULL, 0x63805BF52DBCE45EULL, 
            0xD0E3860945BC7C73ULL, 0x510139C57A3439E4ULL, 0x774664EBE980574DULL, 0xD286349332D033F4ULL, 
            0xC7595464B7C048F3ULL, 0x7E841FF53BE246E7ULL, 0xAF28E3CE360F2A97ULL, 0x894DB03893CD0D9CULL, 
            0xD1688397A9FF6A40ULL, 0x75870FC0A31A5E67ULL, 0xDD9CDFE9DA116A2EULL, 0x03950E6F7660D919ULL
        }
    },
    {
        {
            0x0572838785B1EAB8ULL, 0x57B217A821569A98ULL, 0x051544FB7C7B19E7ULL, 0x30471E4FDE4555B0ULL, 
            0x598EFB8C33562BB8ULL, 0x653EA645146DD332ULL, 0xCD9A54D2B964E274ULL, 0x0EC07A5510D3D189ULL, 
            0xB8602E33CBC8563AULL, 0x582F23311A435D33ULL, 0x129027D4930EAA2FULL, 0xF1E580ED5EFFD8DDULL, 
            0x7A3553248044885FULL, 0x5E66321F62C5A175ULL, 0xAF969C29E3FAE8AFULL, 0xD18853A94F375A5EULL, 
            0x766D05EBC7378344ULL, 0x42A4A7694C5E06D0ULL, 0xA322983DA8BA7600ULL, 0xEFEBE85769BE8F24ULL, 
            0x0DA8B38C1E70234AULL, 0x614BA228A2A308AEULL, 0x399C20F9C6136E5FULL, 0x0086F33D51818563ULL, 
            0x68F3538965E3A4E1ULL, 0xD21ADB23A6F2E150ULL, 0x35B8DCDE7CE64DB8ULL, 0x5A5B1CDB351CD940ULL, 
            0x57526C110FEC205BULL, 0x81B9515FF86E4BDFULL, 0x8305FA6D70AC6AD4ULL, 0x710A5EA0DC81D9AEULL
        },
        {
            0xE5F7E1FC9C754EFFULL, 0xF00E78234FB9934BULL, 0xC3771EA4B38EB2C7ULL, 0x689E7C1FFF3E5647ULL, 
            0x1B633B23BEB36725ULL, 0x2A15AC4058177BE8ULL, 0xD64EF307F2249A0AULL, 0xC6B0788E72D75554ULL, 
            0xC57D86AC18343A31ULL, 0xFA4B2A0D1C2C3D5BULL, 0x2FBC1A15F1A9EF91ULL, 0x347D4328E73CBA4BULL, 
            0x4EF3AF95F1984511ULL, 0xC6DC04A932A4BC2AULL, 0xE7D510BD22531270ULL, 0xC6D22C5985ABFBEDULL, 
            0x694C81D5E683BF7FULL, 0x9C679F73EB2D3727ULL, 0xCD1698649EACD69DULL, 0xDFDD0EAB41C8C7CBULL, 
            0xC70C34BDF5BEBC01ULL, 0x7A1B953434D4F05BULL, 0x39FFBDB9705C8404ULL, 0xE11A8C4D43D5A30AULL, 
            0x511803BEF7536D46ULL, 0x9B2A9DA355CCB8CEULL, 0xB971D889351058E2ULL, 0x1CA9A657A2B977D6ULL, 
            0xA811BB5287F7ADFBULL, 0x673C7A86EE9AB350ULL, 0x920F91FD8E4ADB59ULL, 0xBE5B3769D915DBEFULL
        },
        {
            0x564E5460ADC0E99DULL, 0x73DD90782FA0A9DCULL, 0xE7E8E15B9290A453ULL, 0xE419F8F2978ED16DULL, 
            0x05FDA9904727FBEFULL, 0x3F65570858B0E44BULL, 0xAAEB37446DB721CAULL, 0x188CB9F5BC51A9C2ULL, 
            0xD9BF78029932F588ULL, 0x89428E34359418EBULL, 0x1DDFCA3E626E7F82ULL, 0x7C9ACEFB8DF97460ULL, 
            0x10B1A68B9D59558FULL, 0x98EF5BD02ED0D44DULL, 0x15251B7160EE814FULL, 0xC070A6A54E50EDEAULL, 
            0x216880DA864997DDULL, 0x7E8A26AB9FF8AC21ULL, 0x2BBBEE593F7C1997ULL, 0x7DD722E1AEDC0F6FULL, 
            0x18C2C2759848324EULL, 0x6616347CDF9FAB57ULL, 0xE2B95B2CDD758792ULL, 0xDBAFC63B101C65E5ULL, 
            0x863BBD14691BD4CDULL, 0x7628F6570D74E99BULL, 0x52EA0A6D7E85C83AULL, 0xFE718868ED98B9C0ULL, 
            0x58BDEE12068D46CDULL, 0x5CC62803EB067EDBULL, 0x7DD7F6837AA8C93BULL, 0xF9CC86FB958F70C1ULL
        },
        {
            0xC60FFD42096507FDULL, 0x51101676823C35D0ULL, 0x502192EF88BFBEF4ULL, 0xE5D789199D908BC7ULL, 
            0x10C6A54BF535FAC1ULL, 0xFFCCD83AB34C7540ULL, 0x31A86905E7D6C71BULL, 0x8D610DDE95CDC227ULL, 
            0xFD412E2C8308B727ULL, 0x0C39050DEF47D1B6ULL, 0xA567A05C57082877ULL, 0x618BE9650A2880E8ULL, 
            0xC88ECA7DCC2202A4ULL, 0xEBFE48BABA86EE27ULL, 0x3447C728E9BB7793ULL, 0xE2B35E01FE22DD97ULL, 
            0xD642DC03ED5F69AEULL, 0x439799B5E9A7E073ULL, 0xD460C76946783281ULL, 0x5D9A47E7A5F61711ULL, 
            0x424A8F632C0D156FULL, 0xB37A3CD5677E6AD8ULL, 0xA347088374D34B3EULL, 0x52E565F9DBC1293CULL, 
            0x8551A15530919C98ULL, 0x610C4FFE6ADB5DE2ULL, 0xB2718CD932300270ULL, 0xD92EF47A89AB5834ULL, 
            0x18E0F5EC06C2C964ULL, 0xB2715E2A93AD264CULL, 0x5A7379F6CEBE62DCULL, 0xCB67B7CEA02ED0DBULL
        },
        {
            0x756FDC34748242ECULL, 0xABBF55529965B0F1ULL, 0x84A54B9052D30B3EULL, 0x73DA54C27DEEFC5CULL, 
            0x0F0AECB8658FECF1ULL, 0xA09614443BEBFED7ULL, 0x4C58F0F7BD666F97ULL, 0xAD0D0C65C7102991ULL, 
            0x982702E7A6540C91ULL, 0x76F58A23CA0EBCA7ULL, 0x61D76A653BA1B0FBULL, 0xF00D4CB9EE050B46ULL, 
            0xF33D19B17231B96EULL, 0x451FF8E8612E5F31ULL, 0x047CB26DC97BBEF1ULL, 0xCEC46BB02630CF18ULL, 
            0x54B8321A96DEA591ULL, 0xB75DD726C6A9AC18ULL, 0x6E24A505BA6FA09CULL, 0x38F9D877C5E6EE07ULL, 
            0x1C690EE1C0E3ED48ULL, 0x608A85D14D220858ULL, 0x7CDF2E62A5F30BAFULL, 0xB29C59B5EF2FC776ULL, 
            0x3885004C8CA6F06AULL, 0xAB885432AC8664E1ULL, 0x8F6DE02B0723E75CULL, 0xF0481EB87DEF71F5ULL, 
            0xC70DC79E8DDCCDC4ULL, 0xD5B61D106154EB3CULL, 0x8963C8207BF75E3BULL, 0x0E25F2D23A137D56ULL
        },
        {
            0xF9DC876FD49DEEE9ULL, 0xC99FA5C7D3E04F2EULL, 0x60856A7927ABEBD9ULL, 0x81143CFF858C3689ULL, 
            0x333A14225CBA12B2ULL, 0x3AA38A0D1442DB58ULL, 0x90B64B270A7FC761ULL, 0x81324E1CAF72E44EULL, 
            0xA7605AF47CD041C8ULL, 0xE5B55C2CEC4214F0ULL, 0xFA8F4509D7B5705EULL, 0x6335B3AAC1297D96ULL, 
            0x40516D4FA7D4CE1AULL, 0xA4C5A6F2412F4A78ULL, 0x712FAFDB58C66F56ULL, 0xBCD6B0CE106AA9A0ULL, 
            0x760AB57C088E1ED7ULL, 0x18D0F172A8EC0CF3ULL, 0x557089A608279A61ULL, 0x9DBD8230CCCFE9A1ULL, 
            0x911C6E810A3806B8ULL, 0x515E1EF5907ABC48ULL, 0xC6FB77BE873743A9ULL, 0x2A78D7C329D5C2CFULL, 
            0x6D05AEDDCC237101ULL, 0x00C3939F9CAA0D90ULL, 0xF5843431B6793DBDULL, 0x8383D07E32050AD9ULL, 
            0x9A27A55EED330D66ULL, 0x82EEA9B8EF7CCA70ULL, 0x9CD4AE4840445743ULL, 0x319F5CF9B45404BAULL
        }
    },
    {
        {
            0x279D3ED8C92108E2ULL, 0xF0DDB65D718D6AC2ULL, 0x69B2F84270319E5DULL, 0xE370129174FD9300ULL, 
            0xE066699295ACF948ULL, 0xA669AE94D5B33A40ULL, 0xC3F6EA3244B7C269ULL, 0xCD4BF414B2E7617BULL, 
            0x04A8340AE692BCE4ULL, 0xDCF2B1277BDC00A4ULL, 0x856C6CD3A26DF8D2ULL, 0xD87C01D63F3F2AB1ULL, 
            0xFE8C26E852B6A254ULL, 0xAD4B4BCC726B7AA1ULL, 0x3FC8A9F96830C8A0ULL, 0x94E18A8427D68CDFULL, 
            0x831B7776A61E3401ULL, 0x92569017F6FCA073ULL, 0x75F39EC0009146DCULL, 0xB9C1A3B5BE3E7A58ULL, 
            0xFF3BAD1522739ADEULL, 0x131915A600E33C64ULL, 0x4F3410954F705B57ULL, 0x0A73AA95AAF4E8F7ULL, 
            0x2C3E6EE970C50ACCULL, 0xD8D0838A9289F17AULL, 0xEC89E80767CA5B43ULL, 0x74B194D5A92251F7ULL, 
            0x22FA0732A08B9E02ULL, 0x5E13D4A6B562A036ULL, 0xC5D0D117255E99B3ULL, 0x0E51C0D01D82932FULL
        },
        {
            0xB188DEE6287C545DULL, 0xBED612C9A38A45C1ULL, 0x5EF903460573F349ULL, 0xEC1FC416BB2C47F2ULL, 
            0xDCFA9920A72491DFULL, 0xD7CC7DDC1781BDF5ULL, 0x0FBF5E389A36057DULL, 0x35324CF5618921FCULL, 
            0x8BFADAA4238EE9D5ULL, 0xEC57E83A2FA9D8E9ULL, 0xC5B12409972B9CDCULL, 0x4E2745C9C8B96779ULL, 
            0x3656146F28BA5896ULL, 0xFD9F8EE01E903F23ULL, 0x915F9F08BD84B296ULL, 0x72A2F3337811502EULL, 
            0x493F8D0CC57790D4ULL, 0x84B5ABF40FD11DA1ULL, 0x62A6717C4B8F6AF6ULL, 0x4EAF0D01631BB185ULL, 
            0xE8A5B332820745EEULL, 0x4FCD86781A7B1A11ULL, 0xCF846A168B88A0B3ULL, 0x86CE6FCFA4E5694CULL, 
            0x1E2D6F41BC01608DULL, 0xE34A25C9FF79A7F4ULL, 0x17F159EB5EBD0CFBULL, 0xAD090B541A723D57ULL, 
            0xF0F44E5C23FACCEFULL, 0x4C51FCF6FF428099ULL, 0x2F693514797A94DFULL, 0xE4F0237CFE65341CULL
        },
        {
            0x859A7F21FCF8101CULL, 0xEC821901F3FE2E4FULL, 0x6AB3FD430E77E66DULL, 0x3A0877CFE95CED24ULL, 
            0x3C2D2AC95F6B4A9CULL, 0x3E4E330628D3FD3DULL, 0xC1A76F682D0BD53FULL, 0x9F74DB428F814A12ULL, 
            0x1A95247128A909F1ULL, 0xE16E564315F41D64ULL, 0x0B404E77B3626F40ULL, 0xA23EC15F1A95B9B2ULL, 
            0xB1E4CD0A3936A374ULL, 0xB6EF0589FDD29684ULL, 0x6FD0E90F0DE281D9ULL, 0x7A85C14B975C89FBULL, 
            0x3216D89403544DA7ULL, 0x8599ECD5E6442E8FULL, 0xF275E7867E2C98A3ULL, 0x939E92E361262B57ULL, 
            0x05EEC4F5A3D2C279ULL, 0x9393C0A54A8135D0ULL, 0xE0AB281F5D0270E0ULL, 0xFDF566874C789B69ULL, 
            0xAB935695FFF98993ULL, 0xF2D0F66D77A36443ULL, 0x60C63ADC25031B9AULL, 0x651929545A0BDDFBULL, 
            0x0335BD84D6EA2682ULL, 0x142305226B6BBE95ULL, 0xD7A5FC1766B3524AULL, 0x7C1B9760AB5D36F2ULL
        },
        {
            0x066430CF4C66E2D3ULL, 0xF8D804695E36035DULL, 0x17ECEC520BEDC03DULL, 0xB5DBB38B0C43B4A9ULL, 
            0xAF525E61D9006773ULL, 0x767534BCABF09DD5ULL, 0x223D2D6F8322F65DULL, 0x61574015D37799C9ULL, 
            0x55F0B356499C7BE8ULL, 0x4BF79444F0337109ULL, 0x3BA2A7524BE43D24ULL, 0x404C39BCDBD3142BULL, 
            0xAAB539BBC7A1274EULL, 0x28F7198101C33A34ULL, 0xAA11DFD043D2A783ULL, 0xA6E4A81991189BC7ULL, 
            0x1BF39476953D60C5ULL, 0x6A676B306A3D2849ULL, 0xF557E4A3E7C2138EULL, 0x873CD6A03BDD98F2ULL, 
            0x0C37817C04734476ULL, 0x451FD803DA709319ULL, 0x9A0E07EA07AC195CULL, 0xF0FDBC9BC3B82364ULL, 
            0x352663A7D0711E7EULL, 0x9483FA025F3A7924ULL, 0x96E37FAC9F8992F8ULL, 0x624CD9017ACDD0E6ULL, 
            0xF46D9CC9D17D0D02ULL, 0xE52FA9961E37FE65ULL, 0xD7AA83A5D6A7FE94ULL, 0xE9ABA953769B58B9ULL
        },
        {
            0x0117C15F12975007ULL, 0xD87ABA6ACA3D3365ULL, 0xB4AC79931E94A7F7ULL, 0xB80D1EF4EDB4887BULL, 
            0xEC867E9DD477E5B4ULL, 0x1B1A9AFF17410C10ULL, 0x54272C6D90D34F1AULL, 0xE9DB4E6CC5BE4207ULL, 
            0xDD982DBF2C7264F5ULL, 0x90974B23ED0AE20FULL, 0x78A3CCFA8A209848ULL, 0x1FEFC267B3F5847EULL, 
            0xC703FFB92F921EFFULL, 0x5AF01B4694FC29A7ULL, 0xA8AC9EE658EAC348ULL, 0xE016CC1247CED57AULL, 
            0x047487D9173654D7ULL, 0xCA6F70B9C0EF11ADULL, 0xBDD39E6B7AA34AE8ULL, 0x650C9EB794F36597ULL, 
            0xBD91329BFF6AA19FULL, 0x802F5F42189914EDULL, 0x623E40F6DAFDEACFULL, 0x54E2EE9AB0C1B64DULL, 
            0x6ADFCAEED8756498ULL, 0xBF2F4E3E073102E6ULL, 0x7BBB2EDBB94F01C8ULL, 0x59A579E757366BBBULL, 
            0xC83020B244B9FDDBULL, 0x4AEB8DE12C4D8F28ULL, 0x825A01878113D02DULL, 0x9891B76E69BA9377ULL
        },
        {
            0xD569834378DAA5B8ULL, 0x90B7406D43F9D6CDULL, 0x25EAE248C9DA8A21ULL, 0x46196A70C3C7A048ULL, 
            0x29C62210BD4C606AULL, 0xD3539E480D0A3D00ULL, 0x361D6922ABEC35C8ULL, 0xE30F361A56178794ULL, 
            0xA763A2C6BA608A16ULL, 0x5018BB9E5E94D202ULL, 0xD66D68043F92F2DBULL, 0x2AACEE7FA38B5987ULL, 
            0x63CEBD591955390CULL, 0x3328AD1ED96ED4CAULL, 0xB0C83FCE90951C9AULL, 0xFE84FD735B5C2647ULL, 
            0xB02038938E8889BAULL, 0xC15D810736B0ED92ULL, 0x0C0097C50CAF6967ULL, 0xFB46F34ECED4DF2EULL, 
            0xBCAE9B98373C4459ULL, 0xA1B6D93FC09E0308ULL, 0x95C46BF2024514E4ULL, 0x35A56979143BAC3DULL, 
            0x596C69B1A26A05C8ULL, 0x15EB4B3F5CB592ECULL, 0x3A5F460970DD3BE7ULL, 0x843C2ADE26DED295ULL, 
            0xCB8968305E29CC65ULL, 0x129DE510B5D785FBULL, 0xA8CCF7CF2C804809ULL, 0xF3A79D59639928ADULL
        }
    }
};

const TwistDomainConstants TwistExpander_Bellatrix::kTwistConstants = {
    0x3809C8A32D592A25ULL,
    0x8FE9BD0D0E739475ULL,
    0x513E06C53710305DULL,
    0x3809C8A32D592A25ULL,
    0x8FE9BD0D0E739475ULL,
    0x513E06C53710305DULL,
    0xC0B9F1F317DB6528ULL,
    0x6C37EA90CA44EB58ULL,
    0x57,
    0x96,
    0x12,
    0xFD,
    0xC2,
    0x51,
    0x81,
    0xC9
};

