#include "TwistExpander_Tennis.hpp"
#include "TwistDiffuse.hpp"
#include "TwistFunctional.hpp"
#include "TwistIndexShuffle.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"
#include "TwistFarmSalt.hpp"
#include "TwistFarmConstants.hpp"
#include "TwistMemory.hpp"
#include "TwistShiftBox.hpp"
#include "TwistSnow.hpp"
#include "TwistSquash.hpp"

#include <cstdint>
#include <cstring>

TwistExpander_Tennis::TwistExpander_Tennis()
: TwistExpander() {
    mDomainBundleInbuilt.mPhaseASalts = kPhaseASalts;
    mDomainBundleInbuilt.mPhaseAConstants = kPhaseAConstants;
    mDomainBundleInbuilt.mPhaseBSalts = kPhaseBSalts;
    mDomainBundleInbuilt.mPhaseBConstants = kPhaseBConstants;
    mDomainBundleInbuilt.mPhaseCSalts = kPhaseCSalts;
    mDomainBundleInbuilt.mPhaseCConstants = kPhaseCConstants;
    mDomainBundleInbuilt.mPhaseDSalts = kPhaseDSalts;
    mDomainBundleInbuilt.mPhaseDConstants = kPhaseDConstants;
    mDomainBundleInbuilt.mPhaseESalts = kPhaseESalts;
    mDomainBundleInbuilt.mPhaseEConstants = kPhaseEConstants;
    mDomainBundleInbuilt.mPhaseFSalts = kPhaseFSalts;
    mDomainBundleInbuilt.mPhaseFConstants = kPhaseFConstants;
    mDomainBundleInbuilt.mPhaseGSalts = kPhaseGSalts;
    mDomainBundleInbuilt.mPhaseGConstants = kPhaseGConstants;
    mDomainBundleInbuilt.mPhaseHSalts = kPhaseHSalts;
    mDomainBundleInbuilt.mPhaseHConstants = kPhaseHConstants;
    mDomainBundleEphemeral.Zero();
}

void TwistExpander_Tennis::KDF_A(std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet,
                                  std::uint8_t *pSnow,
                                  int pIndexKDF) {
    TwistExpander::KDF_A(pNonce, pConstants, pDomainSaltSet, pSnow, pIndexKDF);
    TwistWorkSpace *pWorkSpace = mWorkspace;
    if ((pWorkSpace == nullptr) || (mSource == nullptr) ||
        (pConstants == nullptr) || (pDomainSaltSet == nullptr) || (pSnow == nullptr)) { return; }
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint8_t *aWindLaneA = pWorkSpace->mWindLaneA;
    [[maybe_unused]] std::uint8_t *aWindLaneB = pWorkSpace->mWindLaneB;
    [[maybe_unused]] std::uint8_t *aWindLaneC = pWorkSpace->mWindLaneC;
    [[maybe_unused]] std::uint8_t *aWindLaneD = pWorkSpace->mWindLaneD;
    [[maybe_unused]] std::uint8_t *aFuseLaneA = pWorkSpace->mFuseLaneA;
    [[maybe_unused]] std::uint8_t *aFuseLaneB = pWorkSpace->mFuseLaneB;
    [[maybe_unused]] std::uint8_t *aFuseLaneC = pWorkSpace->mFuseLaneC;
    [[maybe_unused]] std::uint8_t *aFuseLaneD = pWorkSpace->mFuseLaneD;
    [[maybe_unused]] std::size_t *aIndexList256A = mIndexList256A;
    [[maybe_unused]] std::size_t *aIndexList256B = mIndexList256B;
    [[maybe_unused]] std::size_t *aIndexList256C = mIndexList256C;
    [[maybe_unused]] std::size_t *aIndexList256D = mIndexList256D;
    std::uint64_t aPrevious = 0xDD43F11334F56346ULL; std::uint64_t aIngress = 0xFA838B049C94A95BULL; std::uint64_t aCarry = 0xB7FF1ACD7677E742ULL;

    std::uint64_t aWandererA = 0xE2731F5D0118B9ACULL; std::uint64_t aWandererB = 0xBA151BBF6B987783ULL; std::uint64_t aWandererC = 0xCDC575246A2307B8ULL; std::uint64_t aWandererD = 0xEC3CEB710DC6B74DULL;
    std::uint64_t aWandererE = 0xDDC5F295B8E63026ULL; std::uint64_t aWandererF = 0x9718C8C2732EBC61ULL; std::uint64_t aWandererG = 0xF47B466CF3678AB1ULL; std::uint64_t aWandererH = 0xA95801A2B591C54BULL;
    std::uint64_t aWandererI = 0xE7622A225551D2BBULL; std::uint64_t aWandererJ = 0xBD4DAE6DD0285ADDULL; std::uint64_t aWandererK = 0xBDB3357A7EC84880ULL;

    // [kdf-a]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
    {
        aPrevious = 10972321480946310804U;
        aCarry = 17104511605510971307U;
        aWandererA = 11744782616324429678U;
        aWandererB = 14420101819649739057U;
        aWandererC = 10463132771499574511U;
        aWandererD = 18179326237248361689U;
        aWandererE = 9264072479081395905U;
        aWandererF = 16588510098772175877U;
        aWandererG = 16742639715118653147U;
        aWandererH = 10628469087959036764U;
        aWandererI = 10823832762729437637U;
        aWandererJ = 17106242751864586764U;
        aWandererK = 9541256354264979179U;
    }
    //
    // ---------------------------------------------------
    // KDF_A_A kdf_a_loop_a:
    // ---------------------------------------------------
    // read from: source, snow
    // temp storage: scrap_a, scrap_b
    // ---------------------------------------------------
    // write to: scrap_a, scrap_b, earth_a, earth_b, earth_c, earth_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::KDF_A_A(pWorkSpace,
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

    //
    // ---------------------------------------------------
    // KDF_A_B kdf_a_loop_b:
    // ---------------------------------------------------
    // read from: earth_a, earth_b, earth_c, earth_d
    // ---------------------------------------------------
    // write to: fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::KDF_A_B(pWorkSpace,
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

    //
    // ---------------------------------------------------
    // KDF_A_C kdf_a_loop_c:
    // ---------------------------------------------------
    // read from: fire_a, fire_b, fire_c, fire_d
    // temp storage: earth_a, earth_b, earth_c, earth_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::KDF_A_C(pWorkSpace,
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

    //
    // ---------------------------------------------------
    // KDF_A_D kdf_a_loop_d:
    // ---------------------------------------------------
    // read from: operation_a, operation_b, operation_c, operation_d
    // temp storage: earth_b, earth_c, earth_d, source, fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: fuse_a, fuse_b, fuse_c, fuse_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::KDF_A_D(pWorkSpace,
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

    {
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,  // input lanes
                         aWindLaneA, aWindLaneB, // output lanes
                         aOperationLaneA, aOperationLaneB, // index shuffle seeds
                         aOperationLaneC, aOperationLaneD, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    }
    {
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneC, aFuseLaneD,  // input lanes
                         aWindLaneC, aWindLaneD, // output lanes
                         aOperationLaneC, aOperationLaneD, // index shuffle seeds
                         aOperationLaneA, aOperationLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    }
    //
    // ---------------------------------------------------
    // KDF_A_E kdf_a_loop_e:
    // ---------------------------------------------------
    // read from: wind_a, wind_b, wind_c, wind_d
    // temp storage: earth_a, earth_b, earth_c, earth_d, source, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: water_a, water_b, water_c, water_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::KDF_A_E(pWorkSpace,
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

void TwistExpander_Tennis::KDF_B(std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet,
                                  int pIndexKDF) {
    TwistExpander::KDF_B(pNonce, pConstants, pDomainSaltSet, pIndexKDF);
    TwistWorkSpace *pWorkSpace = mWorkspace;
    if ((pWorkSpace == nullptr) || (mSource == nullptr) ||
        (pConstants == nullptr) || (pDomainSaltSet == nullptr)) { return; }
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint8_t *aFuseLaneA = pWorkSpace->mFuseLaneA;
    [[maybe_unused]] std::uint8_t *aFuseLaneB = pWorkSpace->mFuseLaneB;
    [[maybe_unused]] std::uint8_t *aFuseLaneC = pWorkSpace->mFuseLaneC;
    [[maybe_unused]] std::uint8_t *aFuseLaneD = pWorkSpace->mFuseLaneD;
    [[maybe_unused]] std::size_t *aIndexList256A = mIndexList256A;
    [[maybe_unused]] std::size_t *aIndexList256B = mIndexList256B;
    [[maybe_unused]] std::size_t *aIndexList256C = mIndexList256C;
    [[maybe_unused]] std::size_t *aIndexList256D = mIndexList256D;
    std::uint64_t aPrevious = 0xCD6F0EF2D871E985ULL; std::uint64_t aIngress = 0x983F1D67AFE3CDA2ULL; std::uint64_t aCarry = 0xF6CDD3A6820A9533ULL;

    std::uint64_t aWandererA = 0x8E6466DD5DD38B7FULL; std::uint64_t aWandererB = 0xA7452314347EB452ULL; std::uint64_t aWandererC = 0xD6AEAE078D614BC0ULL; std::uint64_t aWandererD = 0x8B389B47D188CF53ULL;
    std::uint64_t aWandererE = 0xB5AC1390953024FEULL; std::uint64_t aWandererF = 0xA6F86B29C889E34EULL; std::uint64_t aWandererG = 0xA57E196C2086E9A6ULL; std::uint64_t aWandererH = 0xE0EDCFF972D22F2DULL;
    std::uint64_t aWandererI = 0xDA527DF989B538FFULL; std::uint64_t aWandererJ = 0xCCF4A668FD815A3FULL; std::uint64_t aWandererK = 0xB1FA79E77FB0FB08ULL;

    // [kdf-b]
    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;
    {
        aPrevious = 15975270772927952393U;
        aCarry = 12255578702437121503U;
        aWandererA = 17004685293700290335U;
        aWandererB = 11959561148300372849U;
        aWandererC = 16290589501616462593U;
        aWandererD = 13216337282744372938U;
        aWandererE = 14855017520166725028U;
        aWandererF = 17471100419932506603U;
        aWandererG = 14097874029868117020U;
        aWandererH = 17442090803737571840U;
        aWandererI = 13158509697738278661U;
        aWandererJ = 14915864265866507370U;
        aWandererK = 11526675597434854596U;
    }
    //
    // ---------------------------------------------------
    // KDF_B_A kdf_b_loop_a:
    // ---------------------------------------------------
    // read from: water_a, water_b, water_c, water_d
    // temp storage: wind_a, wind_b, wind_c, wind_d, fire_a, fire_b, fire_c, source
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::KDF_B_A(pWorkSpace,
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

    //
    // ---------------------------------------------------
    // KDF_B_B kdf_b_loop_b:
    // ---------------------------------------------------
    // read from: expand_a, expand_b, expand_c, expand_d
    // temp storage: water_a, water_b, water_c, water_d, source, wind_a, wind_b, wind_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::KDF_B_B(pWorkSpace,
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

    //
    // ---------------------------------------------------
    // KDF_B_C kdf_b_loop_c:
    // ---------------------------------------------------
    // read from: operation_a, operation_b, operation_c, operation_d
    // temp storage: expand_a, expand_b, expand_c, expand_d, earth_d, fire_d, water_d, source
    // ---------------------------------------------------
    // write to: fuse_a, fuse_b, fuse_c, fuse_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::KDF_B_C(pWorkSpace,
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

    {
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,  // input lanes
                         aWorkLaneA, aWorkLaneB, // output lanes
                         aOperationLaneA, aOperationLaneB, // index shuffle seeds
                         aOperationLaneC, aOperationLaneD, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    }
    {
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneC, aFuseLaneD,  // input lanes
                         aWorkLaneC, aWorkLaneD, // output lanes
                         aOperationLaneC, aOperationLaneD, // index shuffle seeds
                         aOperationLaneA, aOperationLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    }
    //
    // ---------------------------------------------------
    // KDF_B_D kdf_b_loop_d:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // temp storage: water_a, water_b, water_c, water_d, fire_a, fire_b, fire_c, wind_c
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Tennis::Seed(TwistWorkSpace *pWorkSpace,
                                 TwistFarmSalt *pFarmSalt,
                                 std::uint64_t pNonce,
                                 std::uint8_t *pPassword,
                                 unsigned int pPasswordByteLength,
                                 std::uint8_t *pDestination) {
    TwistExpander::Seed(pWorkSpace, pFarmSalt, pNonce, pPassword, pPasswordByteLength, pDestination);
    if ((pWorkSpace == nullptr) || (pFarmSalt == nullptr)) { return; }
    std::uint8_t *aSource = pWorkSpace->mSource;
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    [[maybe_unused]] std::uint8_t *aSnowLaneA = pWorkSpace->mSnowLaneA;
    [[maybe_unused]] std::uint8_t *aSnowLaneB = pWorkSpace->mSnowLaneB;
    [[maybe_unused]] std::uint8_t *aSnowLaneC = pWorkSpace->mSnowLaneC;
    [[maybe_unused]] std::uint8_t *aSnowLaneD = pWorkSpace->mSnowLaneD;
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    [[maybe_unused]] std::uint8_t *aWaterLaneA = pWorkSpace->mWaterLaneA;
    [[maybe_unused]] std::uint8_t *aWaterLaneB = pWorkSpace->mWaterLaneB;
    [[maybe_unused]] std::uint8_t *aWaterLaneC = pWorkSpace->mWaterLaneC;
    [[maybe_unused]] std::uint8_t *aWaterLaneD = pWorkSpace->mWaterLaneD;
    [[maybe_unused]] std::uint8_t *aEarthLaneA = pWorkSpace->mEarthLaneA;
    [[maybe_unused]] std::uint8_t *aEarthLaneB = pWorkSpace->mEarthLaneB;
    [[maybe_unused]] std::uint8_t *aEarthLaneC = pWorkSpace->mEarthLaneC;
    [[maybe_unused]] std::uint8_t *aEarthLaneD = pWorkSpace->mEarthLaneD;
    [[maybe_unused]] std::uint8_t *aFuseLaneA = pWorkSpace->mFuseLaneA;
    [[maybe_unused]] std::uint8_t *aFuseLaneB = pWorkSpace->mFuseLaneB;
    [[maybe_unused]] std::uint8_t *aFuseLaneC = pWorkSpace->mFuseLaneC;
    [[maybe_unused]] std::uint8_t *aFuseLaneD = pWorkSpace->mFuseLaneD;
    [[maybe_unused]] std::uint8_t *aInvestLaneA = pWorkSpace->mInvestLaneA;
    [[maybe_unused]] std::uint8_t *aInvestLaneB = pWorkSpace->mInvestLaneB;
    [[maybe_unused]] std::uint8_t *aInvestLaneC = pWorkSpace->mInvestLaneC;
    [[maybe_unused]] std::uint8_t *aInvestLaneD = pWorkSpace->mInvestLaneD;
    [[maybe_unused]] std::uint8_t *aInvestLaneE = pWorkSpace->mInvestLaneE;
    [[maybe_unused]] std::uint8_t *aInvestLaneF = pWorkSpace->mInvestLaneF;
    [[maybe_unused]] std::uint8_t *aInvestLaneG = pWorkSpace->mInvestLaneG;
    [[maybe_unused]] std::uint8_t *aInvestLaneH = pWorkSpace->mInvestLaneH;
    [[maybe_unused]] std::size_t *aIndexList256A = mIndexList256A;
    [[maybe_unused]] std::size_t *aIndexList256B = mIndexList256B;
    [[maybe_unused]] std::size_t *aIndexList256C = mIndexList256C;
    [[maybe_unused]] std::size_t *aIndexList256D = mIndexList256D;
    std::uint64_t aPrevious = 0x988E0D457719CCA2ULL;
    std::uint64_t aIngress = 0xBEA7E7303999622AULL;
    std::uint64_t aCarry = 0xF891E1F2C2AFC6B0ULL;

    std::uint64_t aWandererA = 0xD924A3DEA1D706CDULL;
    std::uint64_t aWandererB = 0x8C8329A286029F80ULL;
    std::uint64_t aWandererC = 0xB9A3A4838377BA2BULL;
    std::uint64_t aWandererD = 0xD0DE6035313BA45DULL;
    std::uint64_t aWandererE = 0x87CAB5CCFBC140B8ULL;
    std::uint64_t aWandererF = 0xF781E45558E0598AULL;
    std::uint64_t aWandererG = 0x85727F9A7E3E4C4BULL;
    std::uint64_t aWandererH = 0xCDA0B5D2D4F2089BULL;
    std::uint64_t aWandererI = 0x998E39DDF9944D6BULL;
    std::uint64_t aWandererJ = 0xD43D54A4DDAE2C8DULL;
    std::uint64_t aWandererK = 0xDFB8EFC0A31901EFULL;

    // [seed]
        TwistSnow::Aria256Counter(aSource, aSnowLaneA);
        TwistSnow::ChaCha20Counter(aSource, aSnowLaneB);
        TwistSnow::Sha256Counter(aSource, aSnowLaneC);
        TwistSnow::AES256Counter(aSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneD, 0);
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
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneC);
    pFarmSalt->Derive(aEarthLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aEarthLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aEarthLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aEarthLaneD, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase B
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneB, 1);
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
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneB);
    pFarmSalt->Derive(aEarthLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aEarthLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aEarthLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aEarthLaneD, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase C
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneA, 2);
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
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneE);
    pFarmSalt->Derive(aEarthLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aEarthLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aEarthLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aEarthLaneD, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase D
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneC, 3);
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
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneH);
    pFarmSalt->Derive(aEarthLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aEarthLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aEarthLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aEarthLaneD, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase E
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneD, 4);
    pFarmSalt->Derive(aWaterLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWaterLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWaterLaneC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneD);
    pFarmSalt->Derive(aEarthLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aEarthLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aEarthLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aEarthLaneD, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase F
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneB, 5);
    pFarmSalt->Derive(aWaterLaneA, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWaterLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWaterLaneC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneF);
    pFarmSalt->Derive(aEarthLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aEarthLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aEarthLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aEarthLaneD, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase G
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneA, 6);
    pFarmSalt->Derive(aWaterLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWaterLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWaterLaneC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneG);
    pFarmSalt->Derive(aEarthLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aEarthLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aEarthLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aEarthLaneD, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase H
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneC, 7);
    pFarmSalt->Derive(aWaterLaneA, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aWaterLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aWaterLaneC, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneA);
    pFarmSalt->Derive(aEarthLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aEarthLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aEarthLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aEarthLaneD, &(pWorkSpace->mDomainBundle.mPhaseHConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    // GSquashInvestToKeyBoxes (start)
    SquashInvestToKeyBoxes();
    // GSquashInvestToKeyBoxes (end)
    //
    //
    // ---------------------------------------------------
    // GSeedRunSeed_A seed_loop_a:
    // ---------------------------------------------------
    // read from: source, key_row_read_a, key_row_read_b
    // temp storage: water_a, water_b
    // ---------------------------------------------------
    // write to: water_a, water_b, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::Seed_A(pWorkSpace,
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
    // ---------------------------------------------------
    // GSeedRunSeed_B seed_loop_a:
    // ---------------------------------------------------
    // read from: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d, earth_a, earth_b
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::Seed_B(pWorkSpace,
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
    // ---------------------------------------------------
    // GSeedRunSeed_C seed_loop_b:
    // ---------------------------------------------------
    // read from: work_c, work_d, earth_a, earth_b
    // temp storage: work_a, work_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: earth_c, earth_d, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::Seed_C(pWorkSpace,
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
    // ---------------------------------------------------
    // GSeedRunSeed_D seed_loop_b:
    // ---------------------------------------------------
    // read from: operation_a, operation_b, operation_c, operation_d
    // temp storage: work_a, work_b, work_c, work_d, earth_a, earth_b, expand_a, expand_b
    // ---------------------------------------------------
    // write to: snow_a, snow_b, fuse_a, fuse_b, fuse_c, fuse_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::Seed_D(pWorkSpace,
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

    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseBConstants.mMatrixArgD;
    {
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,  // input lanes
                         aFireLaneA, aFireLaneB, // output lanes
                         aOperationLaneC, aOperationLaneD, // index shuffle seeds
                         aOperationLaneA, aOperationLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    }
    {
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneC, aFuseLaneD,  // input lanes
                         aFireLaneC, aFireLaneD, // output lanes
                         aOperationLaneA, aOperationLaneB, // index shuffle seeds
                         aOperationLaneC, aOperationLaneD, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    }
    //
    // ---------------------------------------------------
    // GSeedRunSeed_E seed_loop_c:
    // ---------------------------------------------------
    // read from: fire_a, fire_b, fire_c, fire_d
    // temp storage: key_row_read_a, key_row_read_b, snow_a, snow_b, expand_a, expand_b, expand_c, expand_d, earth_a, earth_b, earth_c, earth_d
    // ---------------------------------------------------
    // write to: water_c, water_d, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::Seed_E(pWorkSpace,
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
    // ---------------------------------------------------
    // GSeedRunSeed_F seed_loop_c:
    // ---------------------------------------------------
    // read from: invest_a, invest_b, invest_c, invest_d
    // temp storage: snow_a, snow_b, water_c, water_d, earth_a, earth_b, earth_c, earth_d, fire_a, fire_b, source, key_row_read_a
    // ---------------------------------------------------
    // write to: snow_c, snow_d, wind_a, wind_b, wind_c, wind_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::Seed_F(pWorkSpace,
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
    // ---------------------------------------------------
    // GSeedRunSeed_G seed_loop_d:
    // ---------------------------------------------------
    // read from: wind_a, wind_b, wind_c, wind_d
    // temp storage: snow_c, snow_d, source, key_row_read_b, invest_a, invest_b, invest_c, invest_d, snow_a, snow_b, water_c, water_d
    // ---------------------------------------------------
    // write to: water_a, water_b, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::Seed_G(pWorkSpace,
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
    // ---------------------------------------------------
    // GSeedRunSeed_H seed_loop_e:
    // ---------------------------------------------------
    // read from: operation_a, operation_b, operation_c, operation_d
    // temp storage: fire_c, fire_d, source, key_row_read_a, snow_c, snow_d, expand_c, expand_d, wind_a, wind_b, wind_c, wind_d
    // ---------------------------------------------------
    // write to: fire_a, fire_b, fuse_a, fuse_b, fuse_c, fuse_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::Seed_H(pWorkSpace,
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

    aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseEConstants.mMatrixSelectA;
    aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseEConstants.mMatrixSelectB;
    aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseEConstants.mMatrixUnrollA;
    aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseEConstants.mMatrixUnrollB;
    aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseEConstants.mMatrixArgA;
    aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseEConstants.mMatrixArgB;
    aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseEConstants.mMatrixArgC;
    aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseEConstants.mMatrixArgD;
    //
    {
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,  // input lanes
                         aInvestLaneE, aInvestLaneF, // output lanes
                         aOperationLaneC, aOperationLaneD, // index shuffle seeds
                         aOperationLaneA, aOperationLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    }
    {
        TwistDiffuse::DiffuseWithDomainWords(aFuseLaneC, aFuseLaneD,  // input lanes
                         aInvestLaneG, aInvestLaneH, // output lanes
                         aOperationLaneA, aOperationLaneB, // index shuffle seeds
                         aOperationLaneC, aOperationLaneD, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    }
    //
    // ---------------------------------------------------
    // GSeedRunSeed_I seed_loop_f:
    // ---------------------------------------------------
    // read from: invest_e, invest_f, invest_g, invest_h
    // temp storage: key_row_read_a, key_row_read_b, fire_a, fire_b, expand_a, expand_b, snow_a, snow_b, water_a, water_b, water_c, water_d
    // ---------------------------------------------------
    // write to: fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::Seed_I(pWorkSpace,
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

        TwistSquash::SquashB(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
    //
    // ---------------------------------------------------
    // GROW_A grow_key_a:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // temp storage: scrap_a, scrap_b, water_a, water_b, water_c, water_d, operation_a, operation_b, operation_c, operation_d, fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: scrap_a, scrap_b, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::GROW_A(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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
    //
    // ---------------------------------------------------
    // GROW_B grow_key_b:
    // ---------------------------------------------------
    // read from: expand_a, expand_b, expand_c, expand_d
    // temp storage: scrap_c, scrap_d, water_a, water_b, water_c, water_d, operation_a, operation_b, operation_c, operation_d, fire_a, fire_b, fire_c, fire_d
    // ---------------------------------------------------
    // write to: scrap_c, scrap_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::GROW_B(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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
    Zero_PostSeed();
}

void TwistExpander_Tennis::SquashInvestToKeyBoxes() {
    TwistWorkSpace *pWorkSpace = mWorkspace;
    if (pWorkSpace == nullptr) { return; }
    [[maybe_unused]] std::uint8_t *aInvestLaneA = pWorkSpace->mInvestLaneA;
    [[maybe_unused]] std::uint8_t *aInvestLaneB = pWorkSpace->mInvestLaneB;
    [[maybe_unused]] std::uint8_t *aInvestLaneC = pWorkSpace->mInvestLaneC;
    [[maybe_unused]] std::uint8_t *aInvestLaneD = pWorkSpace->mInvestLaneD;
    [[maybe_unused]] std::uint8_t *aInvestLaneE = pWorkSpace->mInvestLaneE;
    [[maybe_unused]] std::uint8_t *aInvestLaneF = pWorkSpace->mInvestLaneF;
    [[maybe_unused]] std::uint8_t *aInvestLaneG = pWorkSpace->mInvestLaneG;
    [[maybe_unused]] std::uint8_t *aInvestLaneH = pWorkSpace->mInvestLaneH;

    // key_box_a row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Tennis::TwistBlock(TwistWorkSpace *pWorkSpace,
                                       std::uint64_t pNonce,
                                       std::uint8_t *pSource,
                                       std::size_t pBlockIndex,
                                       std::size_t pBlockCount,
                                       std::uint8_t *pDestination) {
    TwistExpander::TwistBlock(pWorkSpace, pNonce, pSource, pBlockIndex, pBlockCount, pDestination);
    if ((pWorkSpace == nullptr) || (pDestination == nullptr)) { return; }
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    std::uint64_t aPrevious = 0x9E1ECFEE2EB6226CULL; std::uint64_t aIngress = 0xD1A566E8B30B81BEULL; std::uint64_t aCarry = 0xAF4EB36CA4E04DB1ULL;

    std::uint64_t aWandererA = 0xDA4E4A675D2F73F7ULL; std::uint64_t aWandererB = 0xE0C16145EE09BD4AULL; std::uint64_t aWandererC = 0xACA96F696124900FULL; std::uint64_t aWandererD = 0xB54F2670157DD933ULL;
    std::uint64_t aWandererE = 0x84998CADF1EA48A0ULL; std::uint64_t aWandererF = 0xC4DC03EFF16FC6BFULL; std::uint64_t aWandererG = 0xEEBF941BFB4A15EFULL; std::uint64_t aWandererH = 0x92C4DD63806C6414ULL;
    std::uint64_t aWandererI = 0x8C898149E2DFDE76ULL; std::uint64_t aWandererJ = 0xF2CD5D4AA533D15FULL; std::uint64_t aWandererK = 0xF8B25940FFC8A909ULL;

    // [seed]
    {
        aPrevious = 9717847667257880838U;
        aCarry = 14205100819329626593U;
        aWandererA = 11086439692936868862U;
        aWandererB = 10309189404687975857U;
        aWandererC = 15244040113743095625U;
        aWandererD = 16126681177133529978U;
        aWandererE = 13398430027763401081U;
        aWandererF = 17376718316315153351U;
        aWandererG = 12095582138478035650U;
        aWandererH = 17043300532058801609U;
        aWandererI = 16304625394809124067U;
        aWandererJ = 17718716126213429582U;
        aWandererK = 9568205854431175448U;
    }
    //
    // ---------------------------------------------------
    // GTwistRunTwist_A twist_loop_a:
    // ---------------------------------------------------
    // read from: source, key_row_read_a, key_row_read_b
    // temp storage: scrap_a, scrap_b
    // ---------------------------------------------------
    // write to: scrap_a, scrap_b, wind_a, wind_b, wind_c, wind_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::Twist_A(pWorkSpace,
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
    // ---------------------------------------------------
    // GTwistRunTwist_B twist_loop_b:
    // ---------------------------------------------------
    // read from: wind_a, wind_b, wind_c, wind_d
    // temp storage: scrap_a, scrap_b
    // ---------------------------------------------------
    // write to: water_c, water_d, snow_a, snow_b, snow_c, snow_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::Twist_B(pWorkSpace,
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
    // ---------------------------------------------------
    // GTwistRunTwist_C twist_loop_c:
    // ---------------------------------------------------
    // read from: snow_a, snow_b, snow_c, snow_d
    // temp storage: wind_a, wind_b, wind_c, wind_d
    // ---------------------------------------------------
    // write to: water_a, water_b, earth_a, earth_b, earth_c, earth_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::Twist_C(pWorkSpace,
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
    // ---------------------------------------------------
    // GTwistRunTwist_D twist_loop_d:
    // ---------------------------------------------------
    // read from: water_a, water_b, water_c, water_d
    // temp storage: wind_a, wind_b, wind_c, wind_d, snow_a, snow_b, snow_c, snow_d
    // ---------------------------------------------------
    // write to: invest_a, invest_b, invest_c, invest_d, earth_a, earth_b, earth_c, earth_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::Twist_D(pWorkSpace,
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
    // ---------------------------------------------------
    // GTwistRunTwist_E twist_loop_e:
    // ---------------------------------------------------
    // read from: earth_a, earth_b, earth_c, earth_d
    // temp storage: invest_a, invest_b, invest_c, invest_d, water_a, water_b, water_c, water_d, snow_a, snow_b, snow_c, snow_d
    // ---------------------------------------------------
    // write to: invest_e, invest_f, invest_g, invest_h, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Tennis_Arx::Twist_E(pWorkSpace,
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
        TwistSquash::SquashB(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
    if ((pBlockCount - pBlockIndex) > static_cast<std::size_t>(H_KEY)) {
        //
        // ---------------------------------------------------
        // GROW_A grow_key_a:
        // ---------------------------------------------------
        // read from: work_a, work_b, work_c, work_d
        // temp storage: scrap_a, scrap_b, water_a, water_b, water_c, water_d, operation_a, operation_b, operation_c, operation_d, fire_a, fire_b, fire_c, fire_d
        // ---------------------------------------------------
        // write to: scrap_a, scrap_b, expand_a, expand_b, expand_c, expand_d
        // ---------------------------------------------------
        //
        TwistExpander_Tennis_Arx::GROW_A(pWorkSpace,
                     &aPrevious,
                     &aIngress,
                     &aCarry,
                     &aWandererA,
                     &aWandererB,
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
    } else {
        TwistShiftBox::ShiftKeyBoxA(pWorkSpace);
    }
    if ((pBlockCount - pBlockIndex) > static_cast<std::size_t>(H_KEY)) {
        //
        // ---------------------------------------------------
        // GROW_B grow_key_b:
        // ---------------------------------------------------
        // read from: expand_a, expand_b, expand_c, expand_d
        // temp storage: scrap_c, scrap_d, water_a, water_b, water_c, water_d, operation_a, operation_b, operation_c, operation_d, fire_a, fire_b, fire_c, fire_d
        // ---------------------------------------------------
        // write to: scrap_c, scrap_d, work_a, work_b, work_c, work_d
        // ---------------------------------------------------
        //
        TwistExpander_Tennis_Arx::GROW_B(pWorkSpace,
                     &aPrevious,
                     &aIngress,
                     &aCarry,
                     &aWandererA,
                     &aWandererB,
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
    } else {
        TwistShiftBox::ShiftKeyBoxB(pWorkSpace);
    }
}

void TwistExpander_Tennis::GrowKeyA(TwistWorkSpace *pWorkSpace) {
    TwistExpander::GrowKeyA(pWorkSpace);
    if (pWorkSpace == nullptr) { return; }
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aScrapLaneA = pWorkSpace->mScrapLaneA;
    [[maybe_unused]] std::uint8_t *aScrapLaneB = pWorkSpace->mScrapLaneB;
    [[maybe_unused]] std::uint8_t *aScrapLaneC = pWorkSpace->mScrapLaneC;
    [[maybe_unused]] std::uint8_t *aScrapLaneD = pWorkSpace->mScrapLaneD;
    [[maybe_unused]] std::uint8_t *aMergeLaneA = pWorkSpace->mMergeLaneA;
    [[maybe_unused]] std::uint8_t *aMergeLaneB = pWorkSpace->mMergeLaneB;
    [[maybe_unused]] std::uint8_t *aMergeLaneC = pWorkSpace->mMergeLaneC;
    [[maybe_unused]] std::uint8_t *aMergeLaneD = pWorkSpace->mMergeLaneD;
    [[maybe_unused]] std::uint8_t *aKeyRowWriteA = &(pWorkSpace->mKeyBoxA[0][0]);

    // [grow key a]
    // GKeyFoldA grow_key_a_fold (start)
    static_assert((S_BLOCK / W_KEY) == 16, "GKeyFoldA expects 16 key-row chunks.");
    TwistShiftBox::ShiftKeyBoxA(pWorkSpace);
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aScrapLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 0, 2, 0, 3 with offsets 5232U, 4098U, 4301U, 806U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseB
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5232U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4098U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4301U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 806U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 2, 3, 1, 1 with offsets 7637U, 6806U, 4011U, 5378U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseC
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7637U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6806U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4011U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5378U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 3, 0, 2, 2 with offsets 2730U, 7065U, 6718U, 1990U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseC
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2730U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7065U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6718U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1990U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA source quarters 1, 1, 3, 0 with offsets 1578U, 5639U, 3358U, 21U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseB
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1578U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5639U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3358U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 21U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA fragments 1, 0, 2, 3 with offsets 506U, 489U, 1826U, 428U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aScrapLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 506U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 489U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1826U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 428U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneB fragments 2, 3, 0, 1 with offsets 1494U, 1073U, 1613U, 1216U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseB
        // write to: aScrapLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1494U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1073U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1613U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1216U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneC fragments 0, 2, 3, 1 with offsets 1752U, 450U, 1639U, 1228U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseC
        // write to: aScrapLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1752U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 450U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1639U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1228U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneD fragments 0, 3, 2, 1 with offsets 824U, 352U, 1781U, 123U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseA
        // write to: aScrapLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 824U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 352U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1781U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 123U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA, aScrapLaneB, aScrapLaneC, aScrapLaneD [0..<W_KEY]
        // offsets: 405U, 49U, 390U, 1616U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 405U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 49U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 390U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 1616U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Tennis::GrowKeyB(TwistWorkSpace *pWorkSpace) {
    TwistExpander::GrowKeyB(pWorkSpace);
    if (pWorkSpace == nullptr) { return; }
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aScrapLaneA = pWorkSpace->mScrapLaneA;
    [[maybe_unused]] std::uint8_t *aScrapLaneB = pWorkSpace->mScrapLaneB;
    [[maybe_unused]] std::uint8_t *aMergeLaneA = pWorkSpace->mMergeLaneA;
    [[maybe_unused]] std::uint8_t *aMergeLaneB = pWorkSpace->mMergeLaneB;
    [[maybe_unused]] std::uint8_t *aMergeLaneC = pWorkSpace->mMergeLaneC;
    [[maybe_unused]] std::uint8_t *aMergeLaneD = pWorkSpace->mMergeLaneD;
    [[maybe_unused]] std::uint8_t *aKeyRowWriteB = &(pWorkSpace->mKeyBoxB[0][0]);

    // [grow key b]
    // GKeyFoldB grow_key_b_fold (start)
    static_assert((S_BLOCK / W_KEY) == 16, "GKeyFoldB expects 16 key-row chunks.");
    TwistShiftBox::ShiftKeyBoxB(pWorkSpace);
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 2, 0, 2 with offsets 7141U, 8046U, 1504U, 355U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aMergeLaneA [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 3U * S_QUARTER;
        const std::size_t aFoldBaseB = 2U * S_QUARTER;
        const std::size_t aFoldBaseC = 0U * S_QUARTER;
        const std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7141U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8046U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1504U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 355U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 3, 2, 0 with offsets 6916U, 5910U, 3094U, 5740U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aMergeLaneB [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 2U * S_QUARTER;
        const std::size_t aFoldBaseB = 3U * S_QUARTER;
        const std::size_t aFoldBaseC = 2U * S_QUARTER;
        const std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6916U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5910U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3094U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5740U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 0, 1, 3 with offsets 299U, 3073U, 1261U, 1088U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aMergeLaneC [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 1U * S_QUARTER;
        const std::size_t aFoldBaseB = 0U * S_QUARTER;
        const std::size_t aFoldBaseC = 1U * S_QUARTER;
        const std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 299U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3073U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1261U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1088U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 3, 1 with offsets 3288U, 368U, 331U, 5167U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aMergeLaneD [0..<S_QUARTER]
        const std::size_t aFoldBaseA = 0U * S_QUARTER;
        const std::size_t aFoldBaseB = 1U * S_QUARTER;
        const std::size_t aFoldBaseC = 3U * S_QUARTER;
        const std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3288U) & S_QUARTER1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 368U) & S_QUARTER1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 331U) & S_QUARTER1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5167U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aMergeLaneA, aMergeLaneB, aMergeLaneC, aMergeLaneD [0..<S_QUARTER]
        // offsets: 4854U, 4610U, 6577U, 1557U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aScrapLaneA [0..<S_QUARTER]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 4854U) & S_QUARTER1;
            const std::size_t aFoldIndexB = (aIndex + 4610U) & S_QUARTER1;
            const std::size_t aFoldIndexC = (aIndex + 6577U) & S_QUARTER1;
            const std::size_t aFoldIndexD = (aIndex + 1557U) & S_QUARTER1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aMergeLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aMergeLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aMergeLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aMergeLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 0 with offsets 1844U, 1860U, 1061U, 1207U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseC
        // write to: aScrapLaneB fragment 0
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1844U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1860U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1061U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1207U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 2 with offsets 505U, 820U, 1786U, 359U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aScrapLaneB fragment 2
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 505U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 820U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1786U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 359U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 3 with offsets 153U, 1275U, 86U, 558U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseA
        // write to: aScrapLaneB fragment 3
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 153U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1275U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 86U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 558U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneA fragment 1 with offsets 1000U, 620U, 1845U, 287U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aScrapLaneB fragment 1
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1000U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 620U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1845U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 287U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneB[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aScrapLaneB fragments 3, 2, 1, 0 [0..<W_KEY]
        // offsets: 336U, 205U, 1157U, 14U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 336U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 205U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1157U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 14U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aScrapLaneB[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseASalts = {
    {
        {
            0xD59CB1B8004A5478ULL, 0x606AC2DBC9CBEF8AULL, 0xEA76E50DEF78F8B0ULL, 0x4AB6CFC8BE131371ULL, 
            0x630E74DDF0183BEDULL, 0xE6B6C583538FC8C0ULL, 0x038F267938F5A7A9ULL, 0x6B3C706C4C271093ULL, 
            0xD7BD2E304E1FE60CULL, 0xE337C754E96B71B6ULL, 0x94E2A40C543A6A34ULL, 0xB60D57B53346F34EULL, 
            0xB9F67FBAE49FB0CCULL, 0x14A2A7AD752F726CULL, 0x714BBD882F23DC00ULL, 0x0B35C579710AA5C2ULL, 
            0x9D419CB2D1402454ULL, 0x6D0846EB1A922AF6ULL, 0xC4B2DDCF4404BF52ULL, 0x20CFDF94125C8FCEULL, 
            0x6E4F3F1FE6CBCC59ULL, 0x57579E9F8914BA35ULL, 0x98A2B3A9FF276266ULL, 0xD715FC82190C3BAAULL, 
            0x99FE00F297C367D5ULL, 0x9C1DDFE6E3A1994FULL, 0xB80BD9DC9418D07DULL, 0x5AEAFDDC3D90AA70ULL, 
            0x69249B28C4118C16ULL, 0xEB62F9B97EA61495ULL, 0x75C1E9682ECD44E9ULL, 0xF323E522279393C3ULL
        },
        {
            0x47279FFB0830D24DULL, 0x340F7C96EF1E9993ULL, 0x147B5DE07735F181ULL, 0x3AFBDAB5AEE286CAULL, 
            0x0CD3D4C466397E1EULL, 0x0A5D9AC0A425F576ULL, 0xFE7E54A7DF5B269EULL, 0xB86CB35C816EAF29ULL, 
            0xC1F39DA46CCB2110ULL, 0xECE849C12956D6E3ULL, 0x56E5B4223F635FBAULL, 0x5501C374275B9B39ULL, 
            0xF71A5ED194172BDBULL, 0xD0DCDB04B1685A7AULL, 0xBD72A17F513D0073ULL, 0xB8DB0D0DF2EB82FEULL, 
            0x297E49E5A4AD37D2ULL, 0x1802189DC37F05C5ULL, 0x268E9467EE92B896ULL, 0xC34B7B5FAA057D6AULL, 
            0xD3DA91C44D5C8FF3ULL, 0x390DBDCC5F0B3A82ULL, 0x6E6BA745B77D8E68ULL, 0x195B5A3429EDDAA8ULL, 
            0x69EF0200FBC3B402ULL, 0x957C5C935A823D48ULL, 0x1ADBF5951C747EFDULL, 0xA921CAF15B20CFD5ULL, 
            0x1445959B7E30F474ULL, 0x79870E45DB8DE43FULL, 0xA0E82770F6AE6ECEULL, 0xAF4FD661DFF8BBC8ULL
        },
        {
            0x06531FD88A2917F9ULL, 0x71A8EC8F67C1B3A0ULL, 0xBE3E9EB65E72E85BULL, 0x670BC9087CE556CAULL, 
            0x953CBD71B0A8EBCDULL, 0x3C37E40626046735ULL, 0x8F0A2C558E2B1CA3ULL, 0x9C9C2F886AE0C65DULL, 
            0xA8459E07070D6602ULL, 0x83988AE6F80BBABAULL, 0x7AE34C5FABD70E26ULL, 0x12CAA3607D1F068BULL, 
            0xD19EEC1255A94435ULL, 0xBB8BDAF93CF89190ULL, 0xA0A669BEA0F5B334ULL, 0x58011C974E97F840ULL, 
            0xD10465B27864ECDBULL, 0x05E623E918488575ULL, 0x44D259526E875CB0ULL, 0xD8EBE1095B28DFFAULL, 
            0x03C5B2C9B06B8C9DULL, 0x591B12FD5140AF21ULL, 0xD347042D9497BEDEULL, 0x183B63441518EA96ULL, 
            0x077BA7B8CFC80269ULL, 0x59D4B85F51C60855ULL, 0x3DD551642E3F5D2FULL, 0x91F20908B12AD7F1ULL, 
            0x4905BE14DA16ABF8ULL, 0xA45515EA2A4AFFE6ULL, 0x1261FD6297BCA2D9ULL, 0x10AAA81AA8DB2C79ULL
        },
        {
            0x318A9464213453D7ULL, 0xE3584E868D9FA0A2ULL, 0x103FA1F274DF4110ULL, 0x032E5AC74465B158ULL, 
            0xC856420B32C2CB38ULL, 0x1E65D5A48F750127ULL, 0x3B9D709BAC6ABFD0ULL, 0x44EE7A68E4E3E5CFULL, 
            0x66C55F7502CEBABEULL, 0xBB48F962CD3ADF87ULL, 0x087B91A184AF39F0ULL, 0x230FD52F755017D0ULL, 
            0xEF3F2C2F348C909BULL, 0x2F5AB33680F22C96ULL, 0x55ED9B6034F267EBULL, 0x2C431AB2BC3B3627ULL, 
            0xCC304A0BD8D7955DULL, 0x03CF1F491CA3B6F0ULL, 0x1774E0AB033E1ED0ULL, 0x4EB07B52FEA19FBAULL, 
            0x858E497EA09E55EEULL, 0x34E8BC2D6D83F756ULL, 0x72437C5D94EAFF81ULL, 0xE330618696A5E67FULL, 
            0x49A89DEC621EABD6ULL, 0xF2C7758BCDA354DFULL, 0x7ABBDA77B2C37B60ULL, 0x38F0EE6E8D8C4EDEULL, 
            0xCF3031786AA47C72ULL, 0xAF36E5CC542F4915ULL, 0x928860EA763C92DBULL, 0x9793E0773785F9DBULL
        },
        {
            0xE2E87F2E867B4CA5ULL, 0xBBC098FFD1D3DC72ULL, 0x482248849A91B1E3ULL, 0x4B28116636174B31ULL, 
            0x3FDC656D39472F33ULL, 0x5CC9E8C35B7648B0ULL, 0x527FECBDF5186ABAULL, 0x2CA84B5835C2DBD2ULL, 
            0xBACE548ED1E1697BULL, 0x981C75271D820DF6ULL, 0xD9B56A6F78E0889DULL, 0x2C3EE2E7FB24B380ULL, 
            0x675F9E75CE863CE1ULL, 0x38CD9175E5B38C4DULL, 0xCA3F3211F1B80B6AULL, 0xE863C65B8DFF421FULL, 
            0xF2FFE2B8F1ED26EFULL, 0x6D3B4A8E5FED0F06ULL, 0xFAA2C6D5484F87BBULL, 0x101B20A2F3681A50ULL, 
            0x34B942D5D8AF1EB8ULL, 0xBB42835669A6F0D5ULL, 0x81BC30C748C2C131ULL, 0x305E16DCCD9B85A7ULL, 
            0x7423CE57B219F2DDULL, 0x35388428E86F4F03ULL, 0x8F79F144C9953424ULL, 0x451624685ABDC598ULL, 
            0xDE70C25797CCEAC4ULL, 0x450B44029A73102EULL, 0xEDCEA17EBF6BDBA1ULL, 0xBB395CE042407695ULL
        },
        {
            0xDCFE2EA172358D91ULL, 0xA03B20AD3548E08DULL, 0xF033335F8941AEBCULL, 0x02A48554DDA755C6ULL, 
            0x7A29142EBBF65C2FULL, 0x8E26534D9F77AD6EULL, 0x0F6CEE78604D1180ULL, 0x2DD714DB8C11F9E4ULL, 
            0x51F20005E00D814AULL, 0xD732183D62B8ADE6ULL, 0x2C7BC81BC8FC679CULL, 0xE96BC4E2952F6F0AULL, 
            0x3CEEFA5C94F547BFULL, 0x49461CB0D8332B75ULL, 0xA21198B758F42087ULL, 0x56D6363BEBE44D4CULL, 
            0x5687231663BE7802ULL, 0xE3F2460FABB94B04ULL, 0x4B7036298C073D8EULL, 0x12E6644F5D7B064BULL, 
            0xB7312BFB1EF2073CULL, 0x6903382CC4B844B0ULL, 0x6B7870259D8BBD9CULL, 0xCD8C5175288AC5FEULL, 
            0x74477651B8D06C69ULL, 0xAB358DF3E18A06C5ULL, 0xCE1D4C49A75FF8D5ULL, 0x47FD87982F228B36ULL, 
            0x276AF4D58122798EULL, 0x68EC889ED167D1AAULL, 0xACBBB3638E19D7C0ULL, 0xF6C6AF9436AC4AD3ULL
        }
    },
    {
        {
            0x4FBF8C2D4B3693F9ULL, 0x248DF7667DF9643FULL, 0x5DCF96B81B6D4297ULL, 0x97B3391603BE1066ULL, 
            0xAEA0642DC55A9AA1ULL, 0xB9E0607354D94A51ULL, 0x8DE8486778C4750DULL, 0x9E967CA84C99D722ULL, 
            0xC462EA1AADD69F0BULL, 0xA8D8B3AB5BF338B0ULL, 0xF529E3D42772D4CAULL, 0x9C8AC4DDAB6DED6DULL, 
            0x840467D374EEF96EULL, 0xF479F85FEA367101ULL, 0x9B20C08E3E4DAD4BULL, 0x7463B59080FA32F2ULL, 
            0x4CB57D7D77FD88DFULL, 0x27B066A89F420D0CULL, 0x37844C0453510821ULL, 0xEC834F041D4F3DFAULL, 
            0x50D4CB79C5E72B2BULL, 0xC0BDBD45D4461B69ULL, 0x5262C48676683B9BULL, 0x9B37B1EE2223A434ULL, 
            0xB19F3A885DD3C855ULL, 0x839948D13E5E1BDBULL, 0x8DFDEBE88AF7E0C6ULL, 0x1D6AAEC079A66A4EULL, 
            0x26BBD78D301D34C0ULL, 0xE94F335B5B06BCE7ULL, 0x9EABC315D854B3F3ULL, 0x56C13A1F81237761ULL
        },
        {
            0x2710499FB036B12DULL, 0x289222C1FE13E987ULL, 0xF8010DD84E9B57D6ULL, 0x03C324BC17F843C0ULL, 
            0x5149E239FA16DBE6ULL, 0x1316C3A8A6476CC4ULL, 0x8146532DFDEE43D0ULL, 0x70F3EAB0A9D3CE00ULL, 
            0x74A539613B9B2834ULL, 0x4712881F4AE5DCE2ULL, 0xE9B8484AE4EF3A98ULL, 0x2E69D28D4C01F299ULL, 
            0x697402D61CA66AB1ULL, 0x03600E35E8BC76D2ULL, 0x374B7D6F6B69F99FULL, 0x778057E61D6E3237ULL, 
            0x70D6747BBC4C8234ULL, 0xBB9CDDB46B63DD92ULL, 0x34B375A3C7D17453ULL, 0x7A73016451F7B891ULL, 
            0x346825D670160D0BULL, 0xD57A908CC8661245ULL, 0x9C2F58A34E5DB476ULL, 0x53CBEB4500FDD65DULL, 
            0xD477BD626E0DE1D8ULL, 0x9B28EA72B15C6CFDULL, 0xF57B37D6F993329FULL, 0xFE8BDB21553424EFULL, 
            0x3F2424E21DDA21BBULL, 0x5B66CD15FE4B0241ULL, 0xFCB26B3664CD9FF3ULL, 0xFF9EBDBA9848AFA6ULL
        },
        {
            0xE25F33A63F90063CULL, 0x3772AC8FEC9F8839ULL, 0xCEF73C19F10E82B8ULL, 0xD302604BC2DFA115ULL, 
            0xEE90F80420A5C4D5ULL, 0x8046EE99CE1AFC45ULL, 0x30928495ADBC53E5ULL, 0xCAA1E14F8CAF1F44ULL, 
            0xF888A78329D80631ULL, 0xF7F84082F88B0F3AULL, 0xAB2047171D56DA1FULL, 0x02F4C994BE61C84AULL, 
            0x9571D05A08B69902ULL, 0x22B7AA593C41B105ULL, 0x104D96CB25CBAC65ULL, 0x09B1523E4F48D03FULL, 
            0x250A27A9759460C8ULL, 0xF406B1876432647CULL, 0xBF5F748C0202E078ULL, 0xBE389CAE33C5145AULL, 
            0xFFA79A6FD5AF8D33ULL, 0x28EB3FE5B42E0A3BULL, 0x5A36267FBF88842EULL, 0x85B218B910B23F4BULL, 
            0x565BB8BA21943570ULL, 0xE2434FDCDE9E8A1DULL, 0xE8201ABDAB59BEF2ULL, 0x27161B301A301D4CULL, 
            0x83B675562FE116F5ULL, 0xF3493B8798DF641DULL, 0x73C6D0493053CC4AULL, 0xD39D70F8E95F7AB7ULL
        },
        {
            0x7ABA84340B037885ULL, 0x7A3604151ED7FED3ULL, 0x84FD932F61B9E8FBULL, 0xA2C4FC6E32A02C59ULL, 
            0xAAB510988CA0E154ULL, 0x3B3DB5BA21EA87EEULL, 0xE6B7138CC6E26F39ULL, 0x7A12452081F94A46ULL, 
            0xA36B30F45D13510AULL, 0x6BCB49AC9E141D5DULL, 0xA0CC1D45E9D5F921ULL, 0x8FAB3B1B5FB0A85FULL, 
            0xB46CAAAD0F26340EULL, 0x59AB7EB6F8642728ULL, 0x2AF232C57EFD4295ULL, 0xD7F0E94CA8B03F0FULL, 
            0x0C406D3FCF0D71DFULL, 0x0D146979D0A83F1EULL, 0xEF1E096393359953ULL, 0x53A8548875EEBDB7ULL, 
            0x0070AA1682384011ULL, 0xE28ABF7FEEBE39B8ULL, 0xDB463A26E0110BE4ULL, 0xC9AA59EF13CE4F58ULL, 
            0x1F62678EC5206032ULL, 0x6961ED839F59FAB1ULL, 0x23338F6DADB7195AULL, 0xEDE5CF1FBB013143ULL, 
            0xDE4D91026A151209ULL, 0xF4E3B4F276533FB9ULL, 0x4AAEFF23622BE547ULL, 0x821EB784B37A30B8ULL
        },
        {
            0xF5392E3C389784C8ULL, 0x594735922C507BDBULL, 0x46298C354E8F4CAAULL, 0x5E04A9BB7E877C2AULL, 
            0x45A1A5C9087FA2DDULL, 0xFD4E88BA4B64A4CAULL, 0x4E41FF2062CDBD66ULL, 0xA7EA0B387DC5AE80ULL, 
            0x794DF4340EB15C22ULL, 0xCBB5080E40FC8726ULL, 0xFB430B05A7A6B162ULL, 0x0B4878C8EF0F9670ULL, 
            0x438C7273905172D8ULL, 0x1803EA7B86B90EF9ULL, 0x920102B514B86CC2ULL, 0x7AC428A8D0492F9DULL, 
            0x9E96E412E8466D87ULL, 0x0647F31CA67C932EULL, 0xCAA769B4B37FD95EULL, 0xBAAC387D29C6730BULL, 
            0xD7F7BA5AB70A68BDULL, 0x9A6E60D62EE22217ULL, 0xD51B33FD55EA9960ULL, 0x8ADD3091A2983B8DULL, 
            0x3FFE78C7CD701155ULL, 0x1E1B71B2C896800BULL, 0xF69C9296AFE54065ULL, 0x499DD43DAB2DCD0CULL, 
            0x44CF41A707B6657BULL, 0x06B7672503A20696ULL, 0x20DB5A588CBF21F6ULL, 0x9E4D933A774244A3ULL
        },
        {
            0x6870C4FB73C5DAC4ULL, 0x216FDA399B18D871ULL, 0x4A17F415DB927C92ULL, 0xB09E11B74934B9A3ULL, 
            0x0CA1D9711864D8ECULL, 0xFE12021846B96BAFULL, 0x6BAD5C1553B215D2ULL, 0x1D2261884FDA1511ULL, 
            0x882D82896385EBBDULL, 0x9116D2D5045DE88DULL, 0xA6DFA9D2A71E9EB6ULL, 0x08776ECE8FFA8FC0ULL, 
            0xBFB7C5F2DB30AEEBULL, 0xEE1BBC68F6E74766ULL, 0x991162206C72BD9AULL, 0xFB60898EEBAD6F31ULL, 
            0x1B8DDE7AB5CFEAEDULL, 0xA7B7A65630797CCEULL, 0x1F8302486EACDF48ULL, 0x5DF863D025DF7C77ULL, 
            0xE8DEA1C4531F87C2ULL, 0x5DDE5B64A15BA8A2ULL, 0xC76FFF41032D74FAULL, 0x019D41177F893780ULL, 
            0x56FA5D7E844C51F6ULL, 0x792C05917AE7EBC9ULL, 0x2A4F439BF286E52BULL, 0x9EB211AECC8C7825ULL, 
            0x0B506D885BD478FDULL, 0x7187FC3AF302B2CCULL, 0x2EEE5C560D3388E3ULL, 0xFC2D98498B140787ULL
        }
    },
    {
        {
            0x91C22BEF69DDC7FAULL, 0xECDBCFAFC337D6C4ULL, 0x10C98ABF9B4D3771ULL, 0xFE933E60BB5E6214ULL, 
            0x6ECC99678B32FC9EULL, 0xB6E46A5D8BA0CAE8ULL, 0x2AC2FC566DEA4D70ULL, 0x6DBBB82305E2E740ULL, 
            0x5A6D1F6D48B8437BULL, 0xE8621E1FEDB62D8CULL, 0x35701ED703C48603ULL, 0x951A071B47A5F07AULL, 
            0x369D564B2C9E7DABULL, 0x22F7CCE837027238ULL, 0xF0301B28FDC57E19ULL, 0xEBAEEFDE7A2186A0ULL, 
            0xBF7E87DD1FEB2B33ULL, 0x51B4CDCA214BDDB1ULL, 0x57C17EC468236E09ULL, 0xB683E5EDD0F8F3CCULL, 
            0xC8C62FB47A7273C0ULL, 0x084DF4D6872610A9ULL, 0x0AF68E6BD0E6E656ULL, 0xF6C569F34C759C64ULL, 
            0x045A733B79D65820ULL, 0x8D34EF28D1AFEC79ULL, 0x9A3C9A21C1DE4C74ULL, 0xA94546870C79578DULL, 
            0x6CB9C777BC4E6648ULL, 0x3F287846990102E9ULL, 0xA053F4C17A6157B8ULL, 0x5340FE3EF5E0FFEEULL
        },
        {
            0x50F2FFAF19418EA9ULL, 0x7C3075B28BE021D2ULL, 0xB84D74F0F5206B69ULL, 0x469E9CA678462386ULL, 
            0x475694A135550EE7ULL, 0xD3559507561E894EULL, 0xF3E082CA09423ADCULL, 0x2301EE5BD5620033ULL, 
            0x2717ABE9B2264D82ULL, 0xD8E9D8E33218DAFBULL, 0x477D78475EBD5A98ULL, 0x712E58B58722F814ULL, 
            0x3D50708E4CD8C3BEULL, 0xDACB25FE906712ECULL, 0x2B47F2F97F1D9FC3ULL, 0xB40C42E7424ED852ULL, 
            0xC87F22F37CA4FB05ULL, 0x5A43B71A2AE88E46ULL, 0xC47086F30D0DF3A1ULL, 0x829B45E846BB1E0DULL, 
            0x4089A57A3FC77D05ULL, 0x00D5DF1B7C6FAB8DULL, 0xF34F177270520C90ULL, 0x45660D85779A8C75ULL, 
            0x7A05F6725C35573EULL, 0xF0727D332981C1F7ULL, 0xAFFE4118694890BAULL, 0x7B0631591904C8FCULL, 
            0x0802E25EB55E0B30ULL, 0x633F43FD2C302F51ULL, 0x251FEF213DEF06FFULL, 0xC7613A23CBA8CA38ULL
        },
        {
            0x80B320C70E68F410ULL, 0xEF75C91732153629ULL, 0x9C01E20277270EB3ULL, 0x6A8BD05A1CFFD2D6ULL, 
            0xDF01560C7CC31BABULL, 0x7027A3DD4B42EFB1ULL, 0x1FB7C45505A892CDULL, 0x4733C7AD1D460EC3ULL, 
            0x8C32BF96DDD65867ULL, 0x14C237814D150CF2ULL, 0x023D57556EEE2B14ULL, 0x7F3929127AA844FDULL, 
            0x6D404B0864EAE44EULL, 0xC1D179457841027EULL, 0x0ADC71CF1E51F5AEULL, 0x94CF5545CF0A2B3EULL, 
            0x3E56EAAC4AA4B9C4ULL, 0x37B0AFA0259A7DDAULL, 0xD65FBBEF71112A10ULL, 0xD13F328601A526BCULL, 
            0x6BF56291E602F649ULL, 0x9B72CC35ACCF2F99ULL, 0xAF3E3FA9F61A3304ULL, 0xEF07B157D203CF09ULL, 
            0xD4BEF2AD1D9F441DULL, 0x91ED3E1073F9E5BAULL, 0x92E48C28A2159C24ULL, 0xCFCB485782DDF137ULL, 
            0xEB204ACF5494F1FAULL, 0xA1A7CCB15A5418C5ULL, 0x73C8C3B0EB499A4DULL, 0x7F029591B3684583ULL
        },
        {
            0x60CC07F2B6D0A3F4ULL, 0x0993B45E727AB39FULL, 0x3B8F942B98A58907ULL, 0x9740C5F35BC4F38FULL, 
            0xC94CD3425533DCADULL, 0x12185823BDC77226ULL, 0xB51C808EE99411AEULL, 0xE45B5C95B8216976ULL, 
            0x2B7664F8A54E5366ULL, 0xC1FB535481C26FF7ULL, 0x67A800CEDB6D1B9FULL, 0x4C1AAA165887A0C4ULL, 
            0xADD8A29221DA2643ULL, 0xEB36605FE1509656ULL, 0x8457E503AF6E4347ULL, 0x27525E4C973A8B03ULL, 
            0x8364FAF9E45DEA94ULL, 0x5D8BA953B8D46263ULL, 0x6C7414AE03C50466ULL, 0x24D9B992B48D0348ULL, 
            0x26D922A256E2CD2BULL, 0x99904CFBCD1C5340ULL, 0x3947012BB918FDAFULL, 0xFAE7F514F11378CDULL, 
            0xCD2C312CBD4C04D0ULL, 0x6AF63AC06803F115ULL, 0x6B21E2ED67416AA0ULL, 0x2B65E3B46E0BD1CDULL, 
            0x3AA5E769E34DD430ULL, 0xBCEB4E9EAC950100ULL, 0xD2CD89B336D5E1AAULL, 0xE72070569F2822C0ULL
        },
        {
            0x04CE311E060E70B2ULL, 0x64B60ED399B4568EULL, 0x2D5E9027C82E253CULL, 0xA6E3D25EA875CC2AULL, 
            0x05F0BFC835062326ULL, 0xF9813D2A7F4617F0ULL, 0x1E0526FBCC66A05EULL, 0x427CD232A03B8AF5ULL, 
            0xF824DDE8C7A7BBF8ULL, 0x5099DB9461AD6128ULL, 0xE0F197C1845748F5ULL, 0xDE64E4975B7B74A0ULL, 
            0x31FE193853A3535FULL, 0x2CF91E99EA67E64CULL, 0xA319072D913CAA80ULL, 0x94D7761B83DAAD74ULL, 
            0x39DB7A7742F243C9ULL, 0x6CE742044235A17FULL, 0x89B576A20D3B7C9AULL, 0x0BDE78F0A0EEEFCFULL, 
            0x243B9DD147A71F8EULL, 0x9918C3291037466FULL, 0x05841B13F9B16456ULL, 0x20E82C89156B1AFBULL, 
            0x21ADF79EC379180AULL, 0x1577F52F8E692F02ULL, 0x4C890C98F3342397ULL, 0xE699126E999C31D5ULL, 
            0x2F3B02CD09C02252ULL, 0x22DD619F3E9B4699ULL, 0x442CA796C4C1D02CULL, 0x133D6EE12A3A7B9FULL
        },
        {
            0x34760322D747DB0FULL, 0xF500407B03C841FFULL, 0x36357E68AAD06AF6ULL, 0x2EB0982CC68053A4ULL, 
            0xF22FE59DA2C3169BULL, 0x4C664824AC44ECDBULL, 0x7A92AA007C57CBEFULL, 0x917A7DB333D5F6E0ULL, 
            0xE8E35D85F7B7C3BFULL, 0xD0D652F5E9CC5886ULL, 0x956DED8439FEE9ECULL, 0xBB8C64485E658124ULL, 
            0xF012FBA580686EADULL, 0x0A85F4B0A5B3FC03ULL, 0xB478E69B961C6572ULL, 0x40DC3C0BB0C0F93FULL, 
            0x990D0055AFDE4D15ULL, 0x9B8DFE52B62AA3E7ULL, 0xE61352AF9EC9451FULL, 0x05CBCEA00D5CC48DULL, 
            0x38B64193AFA5BB3CULL, 0x03B4753B9335E0F2ULL, 0x694F78CA5C1C2463ULL, 0x7796971284AB4392ULL, 
            0x3FB26E21535C5AACULL, 0x1D10B01041959560ULL, 0x95A5EE183F87AB63ULL, 0x331D3EF3C7F61930ULL, 
            0x33BC42EA40D2C458ULL, 0x91F30316AFD672C2ULL, 0x32D0A1C730D2B03CULL, 0xD9A1A5D5211ED15AULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseAConstants = {
    0x3F624BA4F6ACB6FCULL,
    0x7323D3F74986A5E8ULL,
    0xDDE4C81BCDE55200ULL,
    0x3F624BA4F6ACB6FCULL,
    0x7323D3F74986A5E8ULL,
    0xDDE4C81BCDE55200ULL,
    0xC3B2339694134648ULL,
    0xE7E6D3253C4AC4F3ULL,
    0x49,
    0x66,
    0xFF,
    0x81,
    0x4E,
    0x31,
    0xE9,
    0x5A
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseBSalts = {
    {
        {
            0xA3002C19EE436402ULL, 0x25326A89D9A2BFC8ULL, 0x86BB8A3F147D4513ULL, 0x0D7D1ABF9CE13E9EULL, 
            0x9DED0ACDA5D6DBE2ULL, 0x53F55FDA3C29CC4CULL, 0x49C110594B73F520ULL, 0x1E910E4E8C435261ULL, 
            0xFFD85EBF96E816CAULL, 0x58A7EAA682AE62FCULL, 0xCFC68574D675BC95ULL, 0x638D12E533BB344AULL, 
            0x0E4D219EE12565D8ULL, 0x22E6402C49B99776ULL, 0xA4B80B806493A815ULL, 0x75DB5FE21444681AULL, 
            0x466D9EEAC9B5CA82ULL, 0x9D78A0AE3EB99C0FULL, 0x7F79BF0B51DEB1CEULL, 0x3631C70BA1859191ULL, 
            0x330A0C0BD977DE62ULL, 0x149CE7B6AB60F0F0ULL, 0x3D0F0908395EB3B2ULL, 0x0E067875DE3EEB07ULL, 
            0xF46728F41041259AULL, 0x1AFCE0C0FE2C30FCULL, 0x7DF8B064CA270291ULL, 0x04B0C738357DB365ULL, 
            0x4D0B4CFF37B4ECF1ULL, 0xA0772F78583D4E96ULL, 0xBED3AC4FF9A3E0FFULL, 0xAA4FDB7C508202CCULL
        },
        {
            0x13B03A037F17034EULL, 0x2B948C7368FDD6CDULL, 0x9773CEFD166343C6ULL, 0xD3187D694A496F7BULL, 
            0x112837B23769E77AULL, 0xC10C75623D027956ULL, 0x8B0C9685FFFF0615ULL, 0xE5FC22965F553DE7ULL, 
            0x370FC927BCF3D2A3ULL, 0x3410432779F9E123ULL, 0x6034F61A911C1FB9ULL, 0x5E9D60FDADFB07CAULL, 
            0xCFD675957D10B5BFULL, 0x9814A47891338D81ULL, 0x1C07C59539EAD3E3ULL, 0xAE7CB1003781C503ULL, 
            0x3D8CFF4A35853C61ULL, 0xBC738CD3E604ECC1ULL, 0xF692C180336339C1ULL, 0xF6F958CA37C4BB1FULL, 
            0xF4F4C6654BB2D468ULL, 0x5B7CDC50C30BD098ULL, 0x1903EA26B41B51DEULL, 0xBA0588B940BDAAF5ULL, 
            0xEC0F432E670CA1A1ULL, 0x8A2816D6B789FB02ULL, 0xEC64CBE9453936C8ULL, 0xFD11E6FD2E6A02F9ULL, 
            0x70C1D87E57C16E59ULL, 0xD1B661A9AF4F6237ULL, 0x38D506FCA1A41246ULL, 0x88B208D154FBD648ULL
        },
        {
            0xB2D3C4D3AB4C21FDULL, 0x97D3FED03E717D9BULL, 0xAAB350E813A7C927ULL, 0x4E4E0EFF6F9E7F19ULL, 
            0xF6BE19EAACF18593ULL, 0xC63E1EE44E371791ULL, 0x53DF8563F3202A5DULL, 0x6770640EA1047372ULL, 
            0x630BC119931D81CDULL, 0x499023C483EA47EEULL, 0x56CE61D93D0DB61FULL, 0xB85612AD39E2234FULL, 
            0x495722B80A2C9A10ULL, 0x0E1A38DAE11BC96AULL, 0x4271D00AE3005330ULL, 0xFE734FA2A4DBB51DULL, 
            0xE6A44ED2FA32C98BULL, 0x57BE2270301132D4ULL, 0xEDF9F42D53D6F0EAULL, 0xD3E099C0E15EA2D3ULL, 
            0xB4C023ABC9EF4329ULL, 0x029E0DC81A50E1EDULL, 0x5C4B1F7874F67264ULL, 0x0B4AE10CB47D6FF2ULL, 
            0xA052EC978C2F53ADULL, 0x58496DCD0CA0ADB2ULL, 0xAC1FD2093A9211FEULL, 0x0870A2185502115BULL, 
            0x9A3D63D0DC49C958ULL, 0x29A79E480EF7403DULL, 0x12C6D68F0A3B9C35ULL, 0x680FB805C9E90538ULL
        },
        {
            0xE85B1BCCE2994844ULL, 0x855F5951AD354524ULL, 0xE87DCE27E0F45D5DULL, 0xA995CD1231388708ULL, 
            0x36D68E4BBFE934C3ULL, 0x86026DDE68CDE7C0ULL, 0x2374BF569076BA3DULL, 0x20E81867600DB070ULL, 
            0xA434401C04DFD1F7ULL, 0xDD7E5142EEFA88C4ULL, 0xED16CCAA2167F8F1ULL, 0x019C9ED5BF9CA0CAULL, 
            0x63ECFE11B1C4D7EDULL, 0x74BDD1A2D9FD8126ULL, 0xA0B75CE4C269C35CULL, 0x37662C76E269A91DULL, 
            0x0AB28248E59B047EULL, 0xD277C2DFFFF921CCULL, 0x6D783DC601C5D34CULL, 0x714AD8187C8C8787ULL, 
            0xFA1685C451FDDFA2ULL, 0x4CA4F7D63569E16FULL, 0xCC906B66633F75A2ULL, 0xA2AA03C37013B473ULL, 
            0x9B7FB47A6CD0C7E2ULL, 0x18C57C071E50EBCBULL, 0x404A56D3834F3E7CULL, 0x5D58B2E7CB3C7876ULL, 
            0x78A6A71729128797ULL, 0x5AA86A4ED3E08C22ULL, 0x2251F03EAA163E3CULL, 0x3249D7616771F723ULL
        },
        {
            0x3A04F523E0E220EFULL, 0xFD35A06E7337F104ULL, 0x9AE69904E3189DAFULL, 0x173488550CE8294AULL, 
            0xCF382AD88A7E8D4BULL, 0x5B3E0886927BC700ULL, 0x72DEE14332BBFC73ULL, 0x4A03824E98350A46ULL, 
            0x9FC087F14B142C91ULL, 0xC5E534FCD64D6E1CULL, 0x148E93C174C4928EULL, 0xEDB4B35A14BAC14CULL, 
            0x0773C127EBE0056FULL, 0x0F4BD85450FDC016ULL, 0xFDBCB35A361C03F6ULL, 0xF5AAE09D24D7D974ULL, 
            0x7E9428765826A378ULL, 0x32C9DD3EA1361375ULL, 0x5DFE6876B5E7BCFEULL, 0x2B583F3F4020E060ULL, 
            0x2731A296C3961B5EULL, 0x179A0908BD07DABFULL, 0x5B05F7E39BE100D8ULL, 0x166CF80CACA7E383ULL, 
            0x7B971BAE22BFA386ULL, 0x340EEFF1B8585D60ULL, 0x30F574E72361268BULL, 0x64F1DE3452918F10ULL, 
            0xACCE45313495BF30ULL, 0xA2DF811751A6A880ULL, 0x042E50E637E57938ULL, 0xB329B776337C4CF6ULL
        },
        {
            0xE97909CD6A131C7FULL, 0xFEF7464BB69C53DEULL, 0x9E760FE88EE800AFULL, 0x783E4AF07BED32C8ULL, 
            0x64C9E15A2E8A0B8BULL, 0xF330BC686592917DULL, 0xE76B08D4B77734C9ULL, 0x3A95EE3D3630824DULL, 
            0xC9C5DE5A3D92C8FDULL, 0x3DB8016C81204AFFULL, 0xD37247BE01AF733DULL, 0xD3849299F90E12CBULL, 
            0xF75102ADF0AB10F1ULL, 0x26DF0C3F3BF0156AULL, 0x321880B1A083ED12ULL, 0xED48E1BB489558BDULL, 
            0xD33F420032885A80ULL, 0xB162A4A1C5359456ULL, 0x123BB924EE357309ULL, 0x864FF3FE8C282EA9ULL, 
            0x3912E259BDFDC715ULL, 0x7C2CAA54BBE586ABULL, 0x0514C5A6B9E4D244ULL, 0xD067486F028496D8ULL, 
            0xB0F8B20C147A8072ULL, 0x352087879439753BULL, 0x1270A65F809E4376ULL, 0x8C9D6D180F0A67DEULL, 
            0x78C72C27360A7903ULL, 0x983304BFC53764ADULL, 0xDE58CC950519106DULL, 0x4D859DAAC03ABC4EULL
        }
    },
    {
        {
            0x4D31C57A3DDD9248ULL, 0x7AB648F8FC1CB7E6ULL, 0x5F71AFC27DCDDAB6ULL, 0x61BAC7AED3974C5DULL, 
            0x6978ED6E386E628FULL, 0x4E913EC2281A5C2AULL, 0xF98A059052834E88ULL, 0xD824E317F08E2011ULL, 
            0xE30DFCD784461D14ULL, 0xF239611F7ABC32E8ULL, 0x03510BAFC1B2B8AFULL, 0xF0DE6726D0C4B5E8ULL, 
            0x803E54400FC4F7C6ULL, 0xA743A187ACC81BCFULL, 0x8026EF1C1F75C4F3ULL, 0xF9C0EF0C5020AD23ULL, 
            0x930FC9295A338D83ULL, 0xDED9FA224733700EULL, 0x9B9CF8AF9D9BDE3BULL, 0x5DFCCF5E24F4538EULL, 
            0xBF59193EBF8C41F1ULL, 0xFA0925ED6ADBF9C2ULL, 0xBABC93600D171430ULL, 0x44EDEDCD9AD41EC3ULL, 
            0xCDDC9BE83626C94EULL, 0xB1D37687ADFDE3C4ULL, 0xE069361B453A198AULL, 0xD0FCF55111372A0EULL, 
            0x46643DCBA378BAA7ULL, 0x18D8008B04051439ULL, 0x75BC1EAD5B9C5D60ULL, 0x4178672EEEAF8505ULL
        },
        {
            0x745B6B3757196DE2ULL, 0x10C21FE307391221ULL, 0x98D8010122CC84D9ULL, 0x060E357854A57918ULL, 
            0x0B00BB0DEEEA3780ULL, 0xB5FCC7CBDB64E36DULL, 0x96ABD62EF10F78D5ULL, 0x160E267CDA2D9926ULL, 
            0xF27165118D77BE23ULL, 0x575D0C31402D8DC0ULL, 0xBE3ECB986786CEE5ULL, 0x137A488DB01939ACULL, 
            0xD725C212A83618B3ULL, 0x742A1C251E6AA47CULL, 0x6AC69F928C4FDF1DULL, 0x7FBFA185F894D15FULL, 
            0xD72A5A0487F47902ULL, 0x4D95EFFA6A51F6EBULL, 0x693901379A8A759DULL, 0x78EBEC9942D0286DULL, 
            0x8B420D2F3EDBFB03ULL, 0x6E3871AF943C6824ULL, 0xEEB9528581F2A02FULL, 0xD310B605B7B0865AULL, 
            0x0F88F0B1DA53BF26ULL, 0x074002AC40FFE12EULL, 0x0C4AC908BA1AD201ULL, 0x73DFB67D733D7CA4ULL, 
            0xA8E8572EB0DD70E5ULL, 0x2797CB61B112B3ABULL, 0x0AEBAD62DE13FF5EULL, 0x8D4BFDE21B4988CCULL
        },
        {
            0x47B8AFB09F42C8E1ULL, 0xD9AAEC52EB638470ULL, 0x02211526F1D6DECBULL, 0xDD26477AB3062716ULL, 
            0xD3BF2C5669F52C35ULL, 0xDA21AED764E37EFCULL, 0x5AA16FBA543E9275ULL, 0x4F1A5EF4B0D75B3DULL, 
            0x424A67308FCBF83BULL, 0x99D7D37CE74E4810ULL, 0xB23D82D6534E3FC4ULL, 0xC5BED872CAE5728CULL, 
            0xF06AF20242D8D53CULL, 0x4B4E331132ACB6F7ULL, 0xEBADE92CE14A66CCULL, 0x1B38D21BD238DCDDULL, 
            0xC0F32E02FA6ACA4FULL, 0xF1E27D8E065331BAULL, 0xCD2743C37FDCE879ULL, 0x274DF370D084D5EDULL, 
            0xBA2ADEA2096F9271ULL, 0x9C8FA0A7866FC61AULL, 0x2B6CB7956B8A490EULL, 0x7FAEBC68FF154763ULL, 
            0xE1EA5010B3B836C9ULL, 0x2208A1C2F57BBBE4ULL, 0x3B171F78E44A132DULL, 0x3D77E60FE6D28BB9ULL, 
            0x0418315FD98A3DE6ULL, 0x8B54F3E7E26DB106ULL, 0xCB0C4A8C49BBF758ULL, 0xACC11D9AE2C1D12EULL
        },
        {
            0xBF718CFDC3F77486ULL, 0x32271870C7180D65ULL, 0x96A9485DA574347FULL, 0x1674E449CA45ADC8ULL, 
            0x43E56970F57FF120ULL, 0x25EB95B8E624ABBDULL, 0x09BC2A1D0FFEB392ULL, 0x6E3D3A645486A99FULL, 
            0x6F9FCD8215AB481CULL, 0xCACDDC8C1FF7612EULL, 0xE5C29380F96081F7ULL, 0x3EE0D9E351787DE8ULL, 
            0x2D3AB29B0962C286ULL, 0x62635DC2B7456C72ULL, 0xB7DC04A6F906346EULL, 0x1248170ACEB4A481ULL, 
            0x8EFA8D11A669E8D9ULL, 0x753CAF383E92EEE7ULL, 0xE23E4AF093E63882ULL, 0x63A2DD49B970FD19ULL, 
            0x27E13996F51BDA20ULL, 0xEE0F2ECA59CE4940ULL, 0xD2B702C69E45DE62ULL, 0xB53CC5F44398CFCDULL, 
            0xA8BD5DAF71CCD0D8ULL, 0xC6AB01F806D3E804ULL, 0xA5A450980EFB4CC7ULL, 0xD61ED91D136100EDULL, 
            0x6ECAD7BF85F2F918ULL, 0x921662CE6B3ECFCBULL, 0x25E7B3C4A9CD1011ULL, 0x0E8445DC29611FAEULL
        },
        {
            0xCB8B843B0154B7ADULL, 0xD5272A0BDAEA0498ULL, 0x016741AFE9E921CEULL, 0x8B1392D7C02AA686ULL, 
            0x1ECB484DF8C72699ULL, 0x9CF517817F9189E3ULL, 0xF55C458D81CB4589ULL, 0x164874BD15ECA2E2ULL, 
            0x552FBF1466EAD418ULL, 0x0959317D5DAFE209ULL, 0x1649FA74DC07C888ULL, 0x94ACA00AD831C812ULL, 
            0x4063A1EEECE383C6ULL, 0x341C1B9EC3FD80DDULL, 0x5EAB896263EA1F09ULL, 0x54168D15DA56F8ABULL, 
            0xB0EBF746B92188D5ULL, 0x7E50A98A3BA9F459ULL, 0xDA3725BBCEFFC14DULL, 0x8A849DF488DDD84EULL, 
            0x06A31EE6EEB941A2ULL, 0xC65F73418902E853ULL, 0x61B0D4A85C9E1904ULL, 0x3E6EA941D2AD4A2AULL, 
            0x637F73A552A0EA65ULL, 0xC168AA3F870C9FDFULL, 0xC1728A8BFC3B9279ULL, 0x619E8F2D91103B7CULL, 
            0xAF97415E191F97AEULL, 0x215D5295B314E5C4ULL, 0x20D8D12B511A12E6ULL, 0xF2D0C22DDA71FCDEULL
        },
        {
            0xB25339B7D9C9C0C3ULL, 0x87EE3C6811AC684EULL, 0xA1D49DE5FE469607ULL, 0x7317AF4262654D85ULL, 
            0xBD079B038DCD7DA6ULL, 0xB38379DEA46743B3ULL, 0xEABD47E99330C459ULL, 0x87D76B1A83A91FEBULL, 
            0x0D51BA6DC9E7DE6FULL, 0x21B7805582B3A12CULL, 0x36F8FBA5F3F6274CULL, 0xAD583905D1B952C1ULL, 
            0x4015E150A03E5826ULL, 0x01B83FCA061C68C3ULL, 0x4771990699FE4D97ULL, 0x0AE1B749BD74B420ULL, 
            0xE0769CB347C10C13ULL, 0x14EB5BBF9E647C69ULL, 0x7DD8E0BFA20D12E8ULL, 0x798E769A14FD6E00ULL, 
            0xC907D30FD4DA5269ULL, 0xDB1F9BE6F4366E12ULL, 0x2FD4A82BCD814346ULL, 0xEA8492563A0F6CCAULL, 
            0xA0EE4690CEFA4189ULL, 0x478B3D7EB388DB92ULL, 0x4A97A6C20B42B2A0ULL, 0xD3E7183DF091B07BULL, 
            0xDD14B2538B481DEDULL, 0x368D0493DFB54D5BULL, 0x6BE30396FB4F2C50ULL, 0xA4E3FBB378D137D5ULL
        }
    },
    {
        {
            0x745E67F598A75D4AULL, 0x5AFD39D8F7FA31E4ULL, 0xDF83D0067AA868BEULL, 0x4E8E839F40891B47ULL, 
            0x19BB7A5627A4D9A8ULL, 0x6308237472C2A826ULL, 0x2ED871FE313C6D55ULL, 0xDCC98BD11EBDD1ACULL, 
            0x9B1ED08A1BE43692ULL, 0xA2B7888E3BFF6246ULL, 0xF425406E7E010082ULL, 0xCA4B37792528FBCCULL, 
            0x88520FEACF33113FULL, 0xF10B28CA8EFB5331ULL, 0xA08F770B5297710CULL, 0x6E0549583C3523F9ULL, 
            0xAC514D2301CDA296ULL, 0x9D16373FCC68997AULL, 0x491A0800F77FEBBDULL, 0xD0058834E19990BFULL, 
            0x8A75F0F9BD613830ULL, 0x0FA30AABBF52CEB7ULL, 0xAA910598E6D4D2F5ULL, 0x05C6442561087D1EULL, 
            0xFE071881D3ABC97DULL, 0x8088321A06BD0256ULL, 0xAA1F86A68D169D9BULL, 0xF3B21C9B73FF3838ULL, 
            0x8DD705030EE2853CULL, 0x947B35CAF3A0F052ULL, 0x929CE4EE943C2201ULL, 0x811BE4CEFFBE5F5BULL
        },
        {
            0xC9321B5C028F0900ULL, 0x3DE2D3591556F9F6ULL, 0x229F1FAD4B76C616ULL, 0x9630DC668AD8B807ULL, 
            0xA54A28B3D4868A98ULL, 0x71222E16EDDA14AAULL, 0x6F0735FA968203AFULL, 0x264DB4A9562DA55DULL, 
            0x75531FA1A552EEF9ULL, 0x81638373BDEA2817ULL, 0xCEDB0ECFBF49F323ULL, 0xE9224B5C74CBD5AAULL, 
            0xD9017D353136292EULL, 0x11076D0540477C43ULL, 0x25C3189DC6981CC9ULL, 0xDC069168AB264629ULL, 
            0x5224492E2DD0F8EAULL, 0x847EC5D115F68E89ULL, 0x59C899ED1D383380ULL, 0x90FDFD36C5CC976CULL, 
            0xB6FBF20615FB29F2ULL, 0x86C9F08C1722EA41ULL, 0x72D16A783DC8AA78ULL, 0x9327F49936052646ULL, 
            0xE9445F20B9248597ULL, 0x34A6D7DCBA8B23B7ULL, 0xACF7337A9BD35020ULL, 0xD5D0CF3B3DEF3083ULL, 
            0x2BE3B137860F87F4ULL, 0xBDF8F328C21A42A8ULL, 0xE1691C83C086BAE2ULL, 0x1085E96C8C245D6CULL
        },
        {
            0x6A8FA8103DD78518ULL, 0x6A44BDC5AEAA5E3EULL, 0x37E2B4A2B2D782F0ULL, 0x3B6064B72E043E3DULL, 
            0x8AD96488CE031E40ULL, 0x554D1051C03C3727ULL, 0x25020C8B910E5C0DULL, 0xB977061D7F3B7759ULL, 
            0x1F578026B182A4B9ULL, 0x798CA0979B551CAEULL, 0xBEC56347BB36E640ULL, 0x6A88F972BC506B51ULL, 
            0x9DE175D2243E7594ULL, 0xAC0371AE1A7886F2ULL, 0x2595BE5560B0A050ULL, 0x34F79664AE3E1D0DULL, 
            0xEF804E325A3ED752ULL, 0x63346B6258B2B6FBULL, 0x698402C3C5FA771AULL, 0x67870D3ADB05473AULL, 
            0xB4D2DA9DEFDBF764ULL, 0xF07118F608E46613ULL, 0xE944352DC237966DULL, 0xE30FDFED48415BBAULL, 
            0x03DF4DAFD18BBBA8ULL, 0x20E1ACA4E73C6794ULL, 0xC2163058CF3BC0C8ULL, 0xDF860B920EE24D58ULL, 
            0x5381CB099F937EBCULL, 0x5D427C95E21F197BULL, 0xE6FFA94B6B9A4447ULL, 0x71FD30784EE4730AULL
        },
        {
            0xBEC9C3B80676068EULL, 0x946AA975DAC160EEULL, 0x1E1DB835B9FF2D12ULL, 0x7D8448A5D46193DDULL, 
            0xF660A63647901992ULL, 0xEBAED85742A1D4A3ULL, 0x196F1D3F6BA956D1ULL, 0x5F66DC0A250F866DULL, 
            0x55682FF78A71EE75ULL, 0xBBBA9F8A37007CD0ULL, 0x02F13AF3F6EB7CF1ULL, 0x1AEC558B3C9C31AFULL, 
            0xCAF60AB564FAB599ULL, 0xC8100553F0270EB3ULL, 0x4B9B2C3F3FAEF0F2ULL, 0xB0C64EACBE8BC72EULL, 
            0xC83D4899CD163E90ULL, 0xDC263543C5FA868AULL, 0x5E05EB790388AF30ULL, 0x2D22952094693FC6ULL, 
            0x10CA1CCC16E6D44FULL, 0x130E383208F0BA3BULL, 0x6989A6AC2D506F4BULL, 0xE3DA9EF9EDF114B4ULL, 
            0xD94F3076C2CE32E1ULL, 0x132982526DE1F098ULL, 0x1D2EAF035690EC2FULL, 0x9E6B5475A2991CB9ULL, 
            0x80315DFF5F2EF554ULL, 0x1FBF5FCB0EBD2537ULL, 0x3E5C088398A2996CULL, 0x43647231A5E4D420ULL
        },
        {
            0x40F098C1243A08E4ULL, 0x69914B834CC25E34ULL, 0x0EE3707F36298007ULL, 0x7DE8487287FA28E8ULL, 
            0xB4CB6C006911628DULL, 0x0B3F074B916C8200ULL, 0x2197A860F1F7A4A7ULL, 0xACD7B958F4350E3EULL, 
            0x0943E0DB2439E716ULL, 0x5DAC48FB4A10343FULL, 0x157B4768034D9B20ULL, 0x58115530BF40DB81ULL, 
            0x1F3C00389689BFB0ULL, 0x84E1B90B867C05C8ULL, 0x9CD7AD6C39C8F38BULL, 0x83BDEE4B6D9CCD67ULL, 
            0x2AF2FF70AEC85318ULL, 0xD0E31DA70D47812FULL, 0x9D94132517FDA6C2ULL, 0xE21D373E152827F1ULL, 
            0x485C53D682B89316ULL, 0x75BD81978A6FB6A7ULL, 0xDF0CC83F7AEF1DDFULL, 0x32426C779FCBF641ULL, 
            0x92C5F635FBEB6EE0ULL, 0x9B0C6CD01587129EULL, 0x6F5752C604157269ULL, 0x11F557E6592D8457ULL, 
            0xDAE08621798A6613ULL, 0xBC852B574CF2AFE0ULL, 0xF7923678FB8CAEB3ULL, 0xF4D195FBE1FC4FF8ULL
        },
        {
            0x1A0075E7B03A6F69ULL, 0xA6D73358D20F28CAULL, 0x3A65BF753B69CD47ULL, 0x44D5D0BBFB79A11DULL, 
            0x753C946E11517AA0ULL, 0x758101BD51363878ULL, 0x26112E680E2B84FEULL, 0xC9F7301A317275BCULL, 
            0x674A5FC07DFF1FD7ULL, 0x1B647ACE5F841AD4ULL, 0x0227ADCDCFB0C81EULL, 0x947348490357CEE7ULL, 
            0xB30D7FF8B787D426ULL, 0xF31E0F04F45C7C9BULL, 0xB747159F883A1E93ULL, 0x13A7211762C87932ULL, 
            0x90AF6762E7080A9BULL, 0x6A87F634F00DD680ULL, 0x836716D07652E97FULL, 0xEEF25EC4B94F241FULL, 
            0x943A467376E2D074ULL, 0x26387BAB2CDA63D1ULL, 0x3DC9069F8F44B74EULL, 0xA834A81D0571B238ULL, 
            0x8E14BC9F5D82A628ULL, 0x2693BF3A4F134B3FULL, 0x07C48788578078A9ULL, 0x586F93381A3A7D77ULL, 
            0x0F1D8856EFBB0C54ULL, 0x37B11C6DB2AF8710ULL, 0xB3F32268BADDBDBFULL, 0x4C778C434FAE402FULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseBConstants = {
    0x5F3FCC17F3DE26CFULL,
    0x8332491D82AB6DE8ULL,
    0x20053585158992B8ULL,
    0x5F3FCC17F3DE26CFULL,
    0x8332491D82AB6DE8ULL,
    0x20053585158992B8ULL,
    0xCC104903B71BE1EAULL,
    0x1B9592416F7195E0ULL,
    0xC7,
    0xF8,
    0xD2,
    0xC2,
    0x4D,
    0xA1,
    0x9C,
    0x16
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseCSalts = {
    {
        {
            0xF4E43C6B78741987ULL, 0x1C7CC5CD25AEC738ULL, 0x5068D9BD75B73799ULL, 0xC9E1565A9F8D9104ULL, 
            0x1FEC239335A9A8F9ULL, 0x1DC8C3A2228090FEULL, 0x939E6A7BD56E3177ULL, 0x15D667F6CECF2687ULL, 
            0x9C9CAE9BEE013EF7ULL, 0x613C62D83B5E43A9ULL, 0x053B97D07FF4C594ULL, 0x24CB0071E8F96EB8ULL, 
            0x5AFE8420A76E7C1DULL, 0xD7876BEE9E3ADD81ULL, 0x25AABA76469A1B35ULL, 0x05551D67D2CAAB6EULL, 
            0xEFE5FD53BDE0383AULL, 0xB3D3600CEE798423ULL, 0xF8F91D380812BB32ULL, 0x5DE79A747772B05CULL, 
            0xC5EF9BDCB4C03C4BULL, 0xFE47D420196BDE16ULL, 0xC65060D9B1EF8719ULL, 0x49F40B53F1813D87ULL, 
            0xE9DC60013812EF66ULL, 0x0BF24D58AF830A0DULL, 0xB4DF2878EC0F0FA3ULL, 0x56C06726AFF12128ULL, 
            0x1804AFF73041EFBAULL, 0x7898BCE078B8C71CULL, 0x713766F0625653ACULL, 0x3EE4D7A8A2980964ULL
        },
        {
            0x31FABC460F02C072ULL, 0x67828D07D959E906ULL, 0x730BEE3927043D80ULL, 0xD29004D08CE8458EULL, 
            0x79B7F32C45F1240CULL, 0x68D08963B4186724ULL, 0xE741B03CF21083FAULL, 0x122AB4A8E4D82D1DULL, 
            0xBD0BD0288CDA5944ULL, 0x4285796F84B4EAD4ULL, 0xDDA4C5343A96E4A1ULL, 0x10D619D717D76322ULL, 
            0x21FA6600A1709E8AULL, 0x345CDB9BCC1A7AAEULL, 0x17B406BC9F119BFDULL, 0xD5F40D600B8A690CULL, 
            0x4EA42A0DE9C936E3ULL, 0x1969C2858E102B70ULL, 0xBD9B1375CB28C2A0ULL, 0xDF51DF0572274454ULL, 
            0xA071D50FB4E71F7DULL, 0x2BE1127123C8E1E2ULL, 0xEF9B9001889BB103ULL, 0x4F4BA32C700BF6C7ULL, 
            0xE03E86163D17347EULL, 0xC75A6CD2A294B8AFULL, 0x9BD2BB4B550F16F7ULL, 0x35FAA4B082DFD18DULL, 
            0x9446EA0FCBF170C7ULL, 0xA8995D05A621542FULL, 0xE6FBC48EE5654328ULL, 0xB7579C6F7E06CAE5ULL
        },
        {
            0x87ADF873DDD3B7B0ULL, 0x7A9B179889ECC39DULL, 0x96811D9F3806C530ULL, 0x1A5753074AE0C921ULL, 
            0x5C53AA9DC1E5C6B5ULL, 0xCA6BC6DAA5B9A175ULL, 0xB7732E91D253CCB5ULL, 0xDE4AB76A73FF424CULL, 
            0x3EA58CCBF02694B4ULL, 0xAA3BD94544A99AE1ULL, 0xE5AB26441772BFD5ULL, 0xA8492A9FF3A2E027ULL, 
            0x246ECD61F16C62DFULL, 0x783466BC11B7EA4AULL, 0xAD935B416850E2E6ULL, 0x7A8FC77A138589D9ULL, 
            0x2C9B523266DA6878ULL, 0xCAFEA7B39D780330ULL, 0xA110C5750CD58228ULL, 0x7B975FC0F0D4991FULL, 
            0x25EFDEA0F7DFDE5EULL, 0x438DCE8EAF66D06AULL, 0x14F64F152AAC2847ULL, 0xEB1CAC4BFA599942ULL, 
            0xC2584FE81947CF18ULL, 0x3A0E14A73FF415C9ULL, 0x595E27224758B723ULL, 0x054C9CB79B97224FULL, 
            0xA3F20186AFD91927ULL, 0x5E9E590DC0166B39ULL, 0xF97C7FDB9C81FEFFULL, 0x4F018032E7079A80ULL
        },
        {
            0x6821859D91A120B8ULL, 0xB177640EC0487D24ULL, 0xCEC4946EF3013A34ULL, 0x43DDF96884528C8FULL, 
            0x41F54ECF261AD021ULL, 0xE7519A79564D971BULL, 0xC4B9CA47362BD4D8ULL, 0x70C3832DAA90494BULL, 
            0x560A0994C1CA6791ULL, 0xC64CCC178FBB9407ULL, 0x72BB5D8D39590989ULL, 0x289DC9B65D49314DULL, 
            0x2BD041833FD137A1ULL, 0x061E32C0C1030505ULL, 0x7E51E1FCD026D131ULL, 0x19E93411A5BD8B67ULL, 
            0xC057B7F1CA67D609ULL, 0x5ADEB90FDADBCDA1ULL, 0xEB51C2B0881CBEFDULL, 0xF94FEB2DA9A6245EULL, 
            0xF116FC4AF134E8FCULL, 0x5C3E9677B630C9E8ULL, 0xE8585F06698BAFB4ULL, 0x1E04A20496023698ULL, 
            0x655DE23EB48E730DULL, 0x0E13758D485A2568ULL, 0xDF573F06D5ECAAB6ULL, 0xF950EBF4CD1F25F0ULL, 
            0x7547BD798D60D72BULL, 0x8A079FE224E5294DULL, 0x736DB3D8B5A75957ULL, 0xA7FCC3E6A582056EULL
        },
        {
            0xD651BC55C9D8DB22ULL, 0xAFAFBFC15EE51816ULL, 0x0C01C14D5CA3AD8FULL, 0x53D295893FC96DEBULL, 
            0x2D790EA6237F8BABULL, 0x8D844076B3BB7837ULL, 0x4DDA6554CDEFA284ULL, 0x2929DEDAFB08FFB6ULL, 
            0xAEB8F1B3F2043287ULL, 0x60B202EC2EA42F8BULL, 0x570EA507566C8100ULL, 0x578BCEEF836B1B7CULL, 
            0xE777C6E5EBB4FF05ULL, 0x50A260E205307581ULL, 0x76F6DAC420976B9FULL, 0xDCC08C5040FC2A4CULL, 
            0x75C1A5033D9333C4ULL, 0x291CD05FE8129A2AULL, 0xBF063DE67CF160B3ULL, 0xBC26314D39103B55ULL, 
            0xE4E229CB3315BE40ULL, 0xA253CA386B7B1C89ULL, 0x3F2287F4D6864C78ULL, 0x9631C684481D2FCCULL, 
            0xE444E109746A72E6ULL, 0x2E2F5265606B6D10ULL, 0x8E5C20BC68C08C9BULL, 0x22F1D1769BB772B1ULL, 
            0x5F6DF6A8E359BA7BULL, 0xBE3EA0CC401650BCULL, 0xEBD5332B8027BC1AULL, 0xB30381410D77D1C2ULL
        },
        {
            0xE9954651FE29E7A5ULL, 0xE4014B70AAF4CA46ULL, 0xD82E1C475B7D7156ULL, 0x89A29D81F846A740ULL, 
            0x46517BC2A202B1ABULL, 0xB175B59B2C3CD647ULL, 0x2665FA6ABD517173ULL, 0xE48751C559319FEFULL, 
            0xE2440AAEDBA3EF45ULL, 0xB8B1007CB2175DF0ULL, 0x537779F2C7072260ULL, 0xE1E0E36181F9823BULL, 
            0x2924A2987A8ABD06ULL, 0x5DFF9D14CBDFEB9CULL, 0x429B3C791BDA8471ULL, 0x2CC0FC5252902C10ULL, 
            0xA17ABB00057E4B3EULL, 0xF844A3BB31A1ADC0ULL, 0x01C0080C0E80AE7EULL, 0xB956389A06D7740DULL, 
            0x08B4FDB73C6E181FULL, 0xEEBA43029CA6844CULL, 0xB9F86A2E10C91F26ULL, 0xA8A7135D45FFB7D6ULL, 
            0xDC7F14BD25907CE7ULL, 0xFCCC373D501D8007ULL, 0xC1D728D0E3FE07B2ULL, 0xB00E26D4E316C233ULL, 
            0x03CE026B8B81CDC6ULL, 0x18DE10DC82D1D040ULL, 0x4EFCF5AEED7ACC14ULL, 0x21D26643A47B5515ULL
        }
    },
    {
        {
            0xE3E9A3D93555DE19ULL, 0xC16B6C0780641061ULL, 0x439EF5E2FF718CB2ULL, 0x373156B66460D7C3ULL, 
            0xD3C52888934443B2ULL, 0xEBAC70109459955BULL, 0x73F0C2FFD9CCE2A3ULL, 0x9FCE06FC4CE0E3DEULL, 
            0xAAC3D41572708207ULL, 0xC28610852C669C31ULL, 0xCE48E25DEFBDB7A7ULL, 0xC65973751ACB6143ULL, 
            0x952532DEC4E6D374ULL, 0x18524A1CE25094B3ULL, 0xDE3F3950506405A1ULL, 0x049F577E562892BAULL, 
            0x8E955CE7671A3EDAULL, 0x7431E2A54292052CULL, 0xF0F396B01B9A920BULL, 0x8B1AAFFBB3179589ULL, 
            0x086A65262D18FFF8ULL, 0xEF448EB03B8C5224ULL, 0x427AF8571EB0A667ULL, 0x416C0F668184DD39ULL, 
            0xEB8E9E4424F000DBULL, 0x67A1979ABF36049AULL, 0xBB7455961F02D693ULL, 0xD544D4BF4D48D810ULL, 
            0xA5481886E0DFC34AULL, 0x60407A64E8EEE30AULL, 0x031BE2FCE39147CEULL, 0x39784BE0C092F433ULL
        },
        {
            0xB7B2FA476B439CA5ULL, 0x6BC5BA6E0AFA6A42ULL, 0x6B515DA7C972393CULL, 0x5231625580135ED0ULL, 
            0x7F490F04915DD902ULL, 0x559AB915AD0C8550ULL, 0x157A43EF3755A928ULL, 0xFC1C26BFA12F6DD4ULL, 
            0x3C47074011056C45ULL, 0xD14D2B30055969F6ULL, 0x5E91A4477632C8D7ULL, 0xE9EB03017FF9F6F9ULL, 
            0x648CF54BB5A55AD3ULL, 0x7715C17733D825ADULL, 0x828309DDD349CC1FULL, 0x9E16EED96FBE728BULL, 
            0x9E95E70FE5DEAA50ULL, 0xB091D44BFC06ECF4ULL, 0x217371EF884A0AB6ULL, 0x94818C4C12A0B37EULL, 
            0x8A8179C47C17C47AULL, 0x6B912AD872B8D044ULL, 0xA52290F992639A25ULL, 0x193FE894A05E3C92ULL, 
            0x2198E323D5AFC82FULL, 0xCF58A23B769C7148ULL, 0x03593B2B18E95AB3ULL, 0x9489AA3F3C718CDCULL, 
            0x26E3D279AE92173AULL, 0xEA5E0E3F24A57F77ULL, 0xCBEB47BFCB09967FULL, 0x9D6E788DFAC21453ULL
        },
        {
            0xFFD38F09A8540A84ULL, 0xC9F4810F18D2679FULL, 0x866DC9434F9E7139ULL, 0xF026325DBD3BA124ULL, 
            0x61BBBEFB65B7238DULL, 0xBC0549025148F269ULL, 0x954C2B43399C773AULL, 0xDB5E611D464DCE29ULL, 
            0xAFD6CC050DBD0710ULL, 0xD2BE64D498E8746BULL, 0xADBA73C7A62FF619ULL, 0x269719F6F12F97F7ULL, 
            0x0830EC219E78DAA3ULL, 0xD1AA117DEAF75F7EULL, 0xF634F65EC71B4FE2ULL, 0x7D6077132DA9EA74ULL, 
            0xCB4F69BE41CE9E61ULL, 0xE23D5FFD3EDE57F2ULL, 0x195E00EB6838B21FULL, 0x50A8608597F89897ULL, 
            0xBAE5620D9735C109ULL, 0x3F8B8CEC2FD66BD0ULL, 0xB9A9165E1A316D17ULL, 0xA100DE577B660133ULL, 
            0x262911D7028B0C3DULL, 0x26BA2D6E1EDFF322ULL, 0xD1E994FB72481C1DULL, 0x2EB659AD9CEEC163ULL, 
            0x1C100F0C6DF8475DULL, 0xEF0AEBDC00706521ULL, 0x2A5248FA4D2AA7BCULL, 0x3D97ACCD881D2511ULL
        },
        {
            0x62F089DFC2155A79ULL, 0xDBF9C9BA7FF02EB9ULL, 0x96781303C013641AULL, 0x8B4F8A0BABE0B1BDULL, 
            0x4FDE992D721B1A20ULL, 0x7C875336D4F34968ULL, 0xF60B8A650CC2E965ULL, 0x9E4042B90BE95CE6ULL, 
            0x4CAEC38E62C3B58AULL, 0xC69E22C15317B3B3ULL, 0xCE192DB923445CC9ULL, 0x43C5A080DBD08991ULL, 
            0xA55F50DF14CA63D2ULL, 0xCD05C1A3FB07F102ULL, 0x144C04528FC9F6F9ULL, 0xCFB2C077D8FB139BULL, 
            0xAC0C59C51252A2B1ULL, 0x9023915C3502A55EULL, 0x6D140EA57C50DA1BULL, 0x7FF7AF2B1C477B2CULL, 
            0x617DA6EFDC63D35BULL, 0x98FA684CBAB6760AULL, 0x3E751AFCDF60D228ULL, 0xE850F42378EADF7FULL, 
            0x0D12279C6A3307AFULL, 0x0EBE6F83A71814E9ULL, 0x9196E8EB258D6D31ULL, 0x247968C332252F9BULL, 
            0x8D0DB31AA5897211ULL, 0x38D1EB1AD4EB25A5ULL, 0x9FEAE846D036C826ULL, 0x36A671220D8AF2C7ULL
        },
        {
            0x8AD898E14A26DCDCULL, 0x14DB7681BFAD39EAULL, 0xEFC1A8BAB614D5EBULL, 0x65DE5C850CDC5463ULL, 
            0xA741FC4E88BF0490ULL, 0xA5101F0B8CC0AB5FULL, 0x567B201602267B3AULL, 0xB634EA37AAAE4315ULL, 
            0x0626887C799B966AULL, 0x153CE86509CEDCB3ULL, 0xD4D63D499178E004ULL, 0x3713721991694888ULL, 
            0x2384375B2E10AB94ULL, 0xEA09FBEDADC528D0ULL, 0x6AAFBC13257457C1ULL, 0x821B430E86D6756FULL, 
            0xDCEBEE171688C0F1ULL, 0x84C58E600F355194ULL, 0xA8AC01B1896F1D5EULL, 0x74B7B0228A93B84EULL, 
            0x0A5F405035B4C761ULL, 0x22991E153BBA98CDULL, 0x2BCD45C00DD51C6FULL, 0x5C5DDECE3618F724ULL, 
            0x17724E2E402865D5ULL, 0x78BE6C3011D93866ULL, 0xBBCEDBBAB1783FF0ULL, 0xA93D4280A79E22E4ULL, 
            0x273E4F260CE2725FULL, 0xB2AC453E60E85BA9ULL, 0xA8F344CA887BBEF2ULL, 0xB5B7392C96328259ULL
        },
        {
            0x777034A31821F50CULL, 0x5BAAC8D58A73830BULL, 0x8E90724D2E3DCE7DULL, 0xD2697611DDB2567EULL, 
            0x5939ED430512B57FULL, 0x1DF3D45594AFECB6ULL, 0x6E568BA948B9067FULL, 0xE05409EE9EEC56D9ULL, 
            0x22A49EFCBCB2208BULL, 0x6E4EE88C7345D5ECULL, 0x37404642B026E210ULL, 0xCFC4E5769CB55D09ULL, 
            0xF8A74AD679DD4C41ULL, 0x7EDE83E91E37F111ULL, 0xFC8ED485788A7A2DULL, 0x9F41BCBEF7AAA71CULL, 
            0x65596E1D2E54AA3AULL, 0xF7C67E499DE4BFDEULL, 0xCB98E3B919B7BB05ULL, 0xAA3D5259988FDBAEULL, 
            0x27671CCB0BF8A712ULL, 0xB6DAE59C55812FAEULL, 0x8DC3F4149AF9382FULL, 0x3DDEE95E3C0AA844ULL, 
            0xB30D8930AE817C2EULL, 0xCC76BFF7C396462FULL, 0x9BEEDF0746BAF21CULL, 0x585A432D013AC8CEULL, 
            0x5F19CA27768F00CEULL, 0x8168537544BE42A8ULL, 0x5195AEE4796EE166ULL, 0x1F02AD107EB0CA72ULL
        }
    },
    {
        {
            0xB25051D68513EC35ULL, 0xE9830C2347F3CAECULL, 0x5810B4E5A999DABFULL, 0x36985CDD4AA18001ULL, 
            0x87D023A9BCE32B83ULL, 0x327D3032ECA62FA9ULL, 0xD90C61A16C969CF7ULL, 0xF21E4D0BFF040D7EULL, 
            0xEE87AD5BBBA48D48ULL, 0x8B5DE89E5C9F52D9ULL, 0xAB73DECC5967F92EULL, 0xA65F89C6E6BF128CULL, 
            0xADB73518FEA46CE2ULL, 0x8FDFD81B4DF52AF7ULL, 0xD2280265A5EBB9A1ULL, 0xEFCE83EF4C2C9244ULL, 
            0x40B4D06FAA6A861FULL, 0x5EFC82421C31B8F5ULL, 0x37EDA691B6CEBF09ULL, 0x0EAA33E10B488C3EULL, 
            0x88E6FE5B3F6FA6D5ULL, 0x5B44982339534535ULL, 0x54FC642EEECC018EULL, 0x34EDF9040443C5BCULL, 
            0xAE06ED7D4FB858BBULL, 0xF6FDF45B67987F96ULL, 0xF75C19D35F603757ULL, 0x19C3093FC08C00A3ULL, 
            0x038CB4B76A2A2422ULL, 0x8B6F58F03B88B7BCULL, 0x779E3728E21D2832ULL, 0xB0F1AB79775F703CULL
        },
        {
            0x45646862EB363C5BULL, 0xD6E54253AED07596ULL, 0x8307C4ED385A32D3ULL, 0x00EB74A5F8AE6E59ULL, 
            0x38E8E4031FB2E796ULL, 0xF01F2EA3BE2ACDA9ULL, 0x9B3E5D709265A157ULL, 0x9F416B6D42E90861ULL, 
            0x32F3716EB4FE6AA5ULL, 0x7EEF3D626422BFA5ULL, 0x7AD9D43036038F66ULL, 0xA4BEF3FDBF5C1A56ULL, 
            0x308B38DD1F403BD2ULL, 0xD314D051F58502A9ULL, 0x8C2ADF5B04D9B9FDULL, 0x4FAFC79A6F3662C8ULL, 
            0xD32FBE49B36570ECULL, 0x5459E4C64A134920ULL, 0x4855374AFB515853ULL, 0x3C076BF9B325E522ULL, 
            0x2D97C86C9AEE5601ULL, 0x9B8D625D09EFBA74ULL, 0x77D79705FCC0BDF3ULL, 0x4FC267E036DBA4D4ULL, 
            0xDEC519C0EBBEB977ULL, 0xC480B7C6EF90DB18ULL, 0x659144F17E025005ULL, 0x39D40B996F80E83FULL, 
            0x94C73890E444B9E5ULL, 0x5B8F2E71E6630ED4ULL, 0x0C8A122A2E41A25FULL, 0x610CB4E8D077545EULL
        },
        {
            0x24CCE244237A8118ULL, 0x704C75DB41624804ULL, 0xD110023F0D18AB0CULL, 0x01F51EE23684D8C8ULL, 
            0x846311CAF1DB5E30ULL, 0x6480C8E9EDE94EA8ULL, 0xFB772F69EF5B68CDULL, 0x078F2BA21918E928ULL, 
            0x225EC9BE4A7C8759ULL, 0xC8A53709C7B7B09DULL, 0xCD9E012F4C0BCE0EULL, 0x0154EE5BC4D4BB8CULL, 
            0x05042B00B8DF7B84ULL, 0xFB5B4DC26F1E1353ULL, 0x03D997D607F15F54ULL, 0x0E374F16373340BFULL, 
            0xEEC6ED81E7C94E15ULL, 0x5916CCA75BD4B74BULL, 0xE810F7901F94DD8DULL, 0xA0B27E7BF7E238CCULL, 
            0xE1596710ED82C11FULL, 0xD9FA20D0D6C5F6B0ULL, 0x56EE5D3575BA5DCCULL, 0xF40C5DCA18FE8097ULL, 
            0xAA888D7EDF6BF98EULL, 0x917810CC219E3AF1ULL, 0xE3ED70CABDF370FAULL, 0x924D7386CE92F45AULL, 
            0x9CA7D7023E0F849BULL, 0x04B0089E7A50D25CULL, 0xEBAB7EA4E691F4B7ULL, 0xAD383DE14E7F75D1ULL
        },
        {
            0x8F7BFE4693C66148ULL, 0x9F188BE2CFB2E1B8ULL, 0x6C0D990BF4498350ULL, 0x247D7CFD9415D4EEULL, 
            0xD5BA5ED1C893A1C8ULL, 0xE7064ABADDC969C8ULL, 0xB72F0E7F7EA3C39DULL, 0x7686E79B63B57943ULL, 
            0xA1EDF2A3875B3669ULL, 0x92426B062450CD72ULL, 0x429DB14D0DE58853ULL, 0xB490BD8926407DE5ULL, 
            0xB7041DE3CF97886EULL, 0xFC63E0504B615CCDULL, 0xB0344AD96DE7BA02ULL, 0x7A3BDD2C9F0FC122ULL, 
            0x5524E445AD050CDCULL, 0x93DA325A4C53D995ULL, 0x4BAA633BC50692E9ULL, 0x0E09B069C384F062ULL, 
            0x45B20D42A3E1B7D6ULL, 0xEE78A43D16EDAAB8ULL, 0x52840E46001CA6B6ULL, 0x3447C62DB3A3DFC7ULL, 
            0xE214126A54DC7EA8ULL, 0xCE42A3276BDD04FBULL, 0x9F37C9897B000C87ULL, 0x59CC6A7259A712E2ULL, 
            0x8989B9A0687A0A48ULL, 0xC844423ABE261545ULL, 0xC2DCFB462DB4244CULL, 0x34D95FDA22B3BF7CULL
        },
        {
            0x7BA381405FA8D280ULL, 0x6D63C6757900FD16ULL, 0x28ED12F4448CE88EULL, 0xC35F617DA56AB43BULL, 
            0x293092385DA253D7ULL, 0xAA3BB11FD46D2502ULL, 0x0094578B7F352A30ULL, 0x0EDBCC044A5BEF6AULL, 
            0xCB17112F4C7CD539ULL, 0x0E39D89311E05E3FULL, 0xA8E59A4CA1037E26ULL, 0xF97CFDCC4FCAC6FCULL, 
            0xEDB014FB8A6C4865ULL, 0x57451339330AF1D2ULL, 0x5435C071AEDDF0D6ULL, 0xA521809280109616ULL, 
            0xF317C6672EAE0648ULL, 0xD66707FC9C7F0F25ULL, 0x5AA27D0D4D15E3AAULL, 0x70FF1A62B3C986E2ULL, 
            0xE10F8714A1C01A7AULL, 0x0B34067DE64814CDULL, 0x30BFDB43A052B265ULL, 0x5EAB42CE081392CAULL, 
            0x2B196B2125775040ULL, 0x341F02076918548AULL, 0xD9A23CDCC97C722EULL, 0x68829E04554FDD7FULL, 
            0x49D7C98D490ABB2EULL, 0x20058D697795FB2EULL, 0x5F48FFE9A01D8714ULL, 0x0C37DABEAEE95A05ULL
        },
        {
            0xC2EF5BDDEA743025ULL, 0x9C174C19E6847E3DULL, 0xF7B3CCE4F034FEE6ULL, 0xA88D63B068C736EEULL, 
            0x7762E0C8A393D6F8ULL, 0x0C90CC6594EF3A3FULL, 0x06C796D1C0001AAFULL, 0x2289B9D95ECD3CD4ULL, 
            0x07A6C68358285831ULL, 0x8D07264596251445ULL, 0x5DDEC00C0DB05B78ULL, 0x95F975D4713AE9C8ULL, 
            0x841A44DCCF128B42ULL, 0x2D6F6EB80E2A482EULL, 0xE39E1A262BEC8A83ULL, 0xDE5D8B0EBBD18446ULL, 
            0x57C6105868FEC3D4ULL, 0x500A6C38617E62BAULL, 0x7A88C4DE9C929B7EULL, 0xC5585CCB45993C7BULL, 
            0x2DB04982B732DF0DULL, 0x5607D451DAAC664CULL, 0x7017810F34941D14ULL, 0x0FA6F93A87BCAF90ULL, 
            0x388B2AB69FAE6259ULL, 0x0571B9FEA2DFA8D2ULL, 0x28B1457E48615854ULL, 0xF376E2E2FBB44938ULL, 
            0x5E4115F8852F6E9DULL, 0x89EDDBEF1AA7763CULL, 0x044F8DE9B668151DULL, 0x8BFC675A0595B8B8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseCConstants = {
    0xED8EB328C65F7189ULL,
    0xC1614403671176BAULL,
    0xC462661B243C2955ULL,
    0xED8EB328C65F7189ULL,
    0xC1614403671176BAULL,
    0xC462661B243C2955ULL,
    0x0D666F0FB70BB409ULL,
    0x96A07165E5DBCF52ULL,
    0x77,
    0x8C,
    0xCB,
    0x51,
    0x35,
    0xDA,
    0xC9,
    0x34
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseDSalts = {
    {
        {
            0x3E834B777CE3593CULL, 0x88EEF7AAB456E2DCULL, 0xC6AD84D9F0CBBB0EULL, 0x09BA70D70527557BULL, 
            0xD9B6CB628670D25CULL, 0x8ED1EAECEEDC27ADULL, 0x3DA21C8686FCB3A3ULL, 0xC9623ACA7D6E2AE4ULL, 
            0xC728DFEAC5E90FCAULL, 0xC95BB95D5404E067ULL, 0xB2D50E4F9E5374B3ULL, 0x4F602A571E70BD5DULL, 
            0xB6DA88AC3A1F1C1AULL, 0x7E7C2800B395BC75ULL, 0x91B803170A17F3E6ULL, 0x5D621098EFC86919ULL, 
            0x89D443BD0A453865ULL, 0x52834BBFDC7FD2DBULL, 0x3D79929C1C94D848ULL, 0xD4B424C40BC612EEULL, 
            0x1C7C8D39B9FE83A8ULL, 0x26B5E62A9D9C8357ULL, 0xFEDADB31107F2F8BULL, 0x11D4FDA6E3F02E68ULL, 
            0x947C333CE9E982F2ULL, 0xE6CC80D048E3A0A0ULL, 0xB92946AC37B69BF7ULL, 0x34CBF4CDE57354B3ULL, 
            0xA5EBB385BD9C768CULL, 0xC3CC9B2C72999170ULL, 0xA95EEFA7C942F5A1ULL, 0xB46389C40FF9E5C7ULL
        },
        {
            0x5768A2E18C90C50AULL, 0x58DCF311A0AEBAB6ULL, 0x8FBE266625AD095AULL, 0x32090DA70952742EULL, 
            0x3045BC0866A71FFCULL, 0xF530EDE578D4EF9EULL, 0x7CC2B753B39A0B6AULL, 0x9C0B8D804A2E2225ULL, 
            0xB1C8762D3438FFFCULL, 0x2D73EABEE9F2F7FCULL, 0x3E7707325DF49C24ULL, 0xA7F891AFACB554B1ULL, 
            0x0C95291594F4B38AULL, 0x2665420EB7C446A3ULL, 0x2F25F275356AAD90ULL, 0x9544D5A72596EC3CULL, 
            0xCCD0091233DD1960ULL, 0xA641C24D306F16A4ULL, 0x53BAB6D9DF44F07DULL, 0xCDA029D2FFD260E2ULL, 
            0x613CFD96952EAC8DULL, 0x4B75E785D353281FULL, 0x7881A70C44A125DCULL, 0xA5455DE43AFE11C9ULL, 
            0x13E10DBDF98C3426ULL, 0x04A88363A9E6F16CULL, 0xEBC1464C53A0074EULL, 0x66FB1D9D7990FF66ULL, 
            0xA79ED6226D70FCB8ULL, 0x495E7048C8D5A9E9ULL, 0x0D3DF506C3D0DBC7ULL, 0x04E239E5F313F7D5ULL
        },
        {
            0x14FA88B89A941FA3ULL, 0x29E3BEB4032A51E5ULL, 0x819FDF9057566184ULL, 0x3F9B424EF13E4FA1ULL, 
            0x95C1F4D0046DDB93ULL, 0xD45D108B8670AA40ULL, 0xF919D71616972696ULL, 0x333776C5ACB3C886ULL, 
            0x39842A6E005C13B8ULL, 0xAEA2432B1EA1C71FULL, 0xBDFF98C27E925F9EULL, 0x5F680A8F62DF7C9AULL, 
            0xF055D2DC37E0B4C6ULL, 0x2769506259800431ULL, 0xA0E9EDF2DA9F46C5ULL, 0x2ED5F88F129086A9ULL, 
            0xB1C6EA584D0A9B72ULL, 0x9EFC83B345DC70A9ULL, 0x44CAFFF28AEB5EF7ULL, 0x970D97E39EC90F2AULL, 
            0x57AE1A3DE0542434ULL, 0x4FED6CE159C7A8F2ULL, 0x5E9BFAB8828A9A6DULL, 0x781BB01471220EEDULL, 
            0x3D1852A84D63E8A7ULL, 0x818AF6F37F16E1BFULL, 0x22DB5878A34C3534ULL, 0x92D8AD35408D4667ULL, 
            0xD7A7D142E1C4D928ULL, 0xDA408E29E6DCD923ULL, 0xBB7AF6226DCC7852ULL, 0x31D01A071BA14577ULL
        },
        {
            0x33CECAFD61F29CF7ULL, 0x1DA809CD3732223EULL, 0xC3EE267CB95EF4B5ULL, 0xC375433BF125F196ULL, 
            0xBDAC74377BC610E9ULL, 0xA1F381532D1F5C6BULL, 0x6C6E69B503EFFFFFULL, 0x174AEFD951177D45ULL, 
            0x37E109D33814AACDULL, 0x8EA4460D71B024CAULL, 0xF46B157D0BBF313EULL, 0xE2B873C9979D4D38ULL, 
            0xC11FA33EDAC3272CULL, 0x65D7B74F86635665ULL, 0x8128AB14444CD0E3ULL, 0x56F6138F0E5C8862ULL, 
            0xF0D6AAB335D87584ULL, 0x89DA35E4E2ACB7DEULL, 0x86CDFD0353876A85ULL, 0xA5FFB2E4A148C940ULL, 
            0x1DF8191F9C3B0CC8ULL, 0xA7D6BBF5187DBBC1ULL, 0xD842903D79BD9F2CULL, 0x7A16E5F14DE6561CULL, 
            0x1A3F7229A3820F15ULL, 0x8DA0C42B80F179AAULL, 0x4F98675CB68E6F26ULL, 0x555FD0C24CA3174BULL, 
            0x65E5CFB6F961051BULL, 0xA33DC1E64E0B1AEFULL, 0x14F92B689FB08059ULL, 0xFAA25050619A97FCULL
        },
        {
            0x2E6E550EBFBE7C07ULL, 0x7FE0447179B46C83ULL, 0x96F7AC03D4952AB2ULL, 0xF0D6A6A97A986EDAULL, 
            0x41C1E20C771F4CA4ULL, 0x34E785299DDACE13ULL, 0x2EF2E3618A0ADA82ULL, 0xE28CF928C17E5AD2ULL, 
            0xCAC91F8204BC9485ULL, 0x658B91ABAF4C938CULL, 0x27A6806C9992DEB7ULL, 0xD6A65E6D0AD70B44ULL, 
            0x2954CE59931FD7EAULL, 0xA31BC60DCFB060BCULL, 0xBDE35B91F5835A81ULL, 0xF127BC91872243BCULL, 
            0xD9AAB78029EEC87DULL, 0x285077BA4C36883AULL, 0x7F91CAE7F599ED31ULL, 0x25ED8E3677BECF97ULL, 
            0x074E579B0879A412ULL, 0x473A6F2F3B954F7BULL, 0x2DBBA3E6C84E04EAULL, 0xE5AA15C3E6ADAC16ULL, 
            0xCB13EE25EEDE9110ULL, 0x19F3851F129CF6E1ULL, 0x84A6B8FA9D4C41AAULL, 0x7EAE429787EAC8FAULL, 
            0x8FD72A7C7F8A96F3ULL, 0xA18E6CDA432886DFULL, 0x94353EDFFBD1C9E8ULL, 0x83865C9697ECA1AEULL
        },
        {
            0xD5E4F4A9BF8C9768ULL, 0x6E1CCB9AF41272C1ULL, 0x2FE473E96E9B6B8AULL, 0x97F0ED537735EB5FULL, 
            0x521FE548B620360CULL, 0xC7BDEC632576AFB6ULL, 0x05EA16544AFA682EULL, 0x6EF7CB397085E846ULL, 
            0xA44DF1EF4FB2CCABULL, 0xC86CE37AA70FACFFULL, 0xDB0706BB4E2E86EEULL, 0xB12EEF0075319D95ULL, 
            0x8D28741035A86FFDULL, 0x1C5FA70CF8B91AB3ULL, 0x18837FD1173500C3ULL, 0x0EF421367B9DC77AULL, 
            0xEE0E2FB67490571BULL, 0x8B3B731BA2A642C0ULL, 0xA0A18E7DF333DAD6ULL, 0x0E97E7CD307E965EULL, 
            0x84D81C4CDB75E3E5ULL, 0xE1C9C3503BC7D5F9ULL, 0x7024D0322B977B03ULL, 0x93FA85880F9A2AFEULL, 
            0x537F32E2BAEA7193ULL, 0xDC0D014939D5609BULL, 0x78CD4E30D5A78593ULL, 0xB09B769EAFCEE748ULL, 
            0x9AD23438882A52F2ULL, 0x82C8996E4F356A83ULL, 0xB7BBD0E61288DF05ULL, 0x2FBBBB78C79E425DULL
        }
    },
    {
        {
            0x17BD77B2EEDB0E9CULL, 0xB61781484A25D6B7ULL, 0x84AD35067FB1D5A0ULL, 0x4247727DE65F5F2AULL, 
            0xA99C851167BD3593ULL, 0x702E576E44CFC307ULL, 0x6A7C04C2DA2D4CF1ULL, 0x74944B28000A42D6ULL, 
            0xD37121D1D2C461ECULL, 0x69A2440311E22A9BULL, 0x54B82FEB8F3E6474ULL, 0x77409FC021984170ULL, 
            0xA338CE9AC318E255ULL, 0x3FF1BA213E71FFBBULL, 0xF767390B72614E27ULL, 0x2DFF42AE4D932FDFULL, 
            0xAD8722C03A6FB1AFULL, 0xAD165096647D3C11ULL, 0xD4E2F6B1A10140D8ULL, 0x77F57C0D95E3D404ULL, 
            0x729113DA16E0CBAAULL, 0xBA46FAF8B99BFE14ULL, 0x85A6C35116E6038AULL, 0xFA5EB57B8F4E772BULL, 
            0xD442861AF0944D24ULL, 0x1C3720DE5EB8FF51ULL, 0xCFDB5F0BACFA240EULL, 0xB6ECDDE2759D2BE4ULL, 
            0xCC5948E2B9352FEBULL, 0xD33C0BE0460ACA06ULL, 0x58840FAF065DCAE9ULL, 0x94AE147EC4AE04A8ULL
        },
        {
            0xB57A8748AD38584FULL, 0xC656D4BE5E5A05AAULL, 0x1331BB3C7083EA06ULL, 0x0653FC8DE847D532ULL, 
            0xA62B31D831E94C56ULL, 0x45F0523F60CCA09CULL, 0x01DBBE9C4C36D041ULL, 0x5C54295440461333ULL, 
            0x4F3A137CEBC33AC8ULL, 0x5070CFD1C192C5C2ULL, 0xC3802D975D3F019EULL, 0xB612150DD52AC613ULL, 
            0x3CC08BB4E55A49E5ULL, 0x5622DDA6FDD738C3ULL, 0x4F34697633004213ULL, 0xA2E88E6DE9D04311ULL, 
            0x7CBFCCFE46456182ULL, 0x941830D38A1EF85CULL, 0xC4572073A161FD64ULL, 0x8A6D10F7BD108A2DULL, 
            0x606CA9044EB92D41ULL, 0x30F01D0F5E7F2E4CULL, 0x27F00F1E788EBC2AULL, 0x613920A25DEE4106ULL, 
            0xBFC8EC43806D9DEBULL, 0x48F49A32EB6DA6F5ULL, 0x24EB067DD2F773B3ULL, 0x198AD09A9EFC4EE5ULL, 
            0xE01BAF686E148E2FULL, 0xF639EAE5A8CD4368ULL, 0xCB8CE0AF6BC2D90BULL, 0x386AD2B2048C46D6ULL
        },
        {
            0xA31B361AEC615FF1ULL, 0x6038741408511FB6ULL, 0xC0FB7B29B13900A7ULL, 0x137BCCCE1B2ACFBDULL, 
            0xA1CA765A86746357ULL, 0xF27865808ED688B3ULL, 0x62545BC2BEFE0110ULL, 0x50D931E4B4CE7077ULL, 
            0x83D29522A7DD6F2CULL, 0x7C91034BCD9E2E10ULL, 0x5E6C181AB9C6CF1DULL, 0x715040ECE4CFFFA4ULL, 
            0xEF6FF8BAC1D64802ULL, 0x6CE783F48AD418BEULL, 0xCF0BECCCFAD38713ULL, 0xD05162010670BFD5ULL, 
            0x7BC10FB7DAEAB45AULL, 0xC98A7D91C2AB9A40ULL, 0x1783037B765354DDULL, 0xF6E0BEB8774AD13FULL, 
            0xBB77A1FB2CADFB13ULL, 0xCFFB7226B22B024CULL, 0xC3397C4235FAC8A0ULL, 0x1E86BC92074C91D8ULL, 
            0x853C297F0D424DCBULL, 0xBD75656519B8F942ULL, 0x86BBFCD6719A4DACULL, 0xB86580F6F2A06705ULL, 
            0xFAC38F27201FB67BULL, 0xC90871155B65D925ULL, 0x0CEE23A32853C962ULL, 0x47214E317CED694EULL
        },
        {
            0xC05220D6B05878B2ULL, 0x01355904CEE3E740ULL, 0xE45823E5ADCE86F0ULL, 0xCCB85A53FB0490EFULL, 
            0x1B7DC407C71743D1ULL, 0x53FEC5510732F2FAULL, 0x263871925DDC5790ULL, 0x57BFE401FB8A138AULL, 
            0xF02255C91ACDD819ULL, 0x0BE4DF78EB0F4318ULL, 0x5C69BB0F5A8E1349ULL, 0xFB5D214244F214D8ULL, 
            0x3AC70E99A9D46563ULL, 0x9BF9F7EDF5E5B00CULL, 0x24B4670EEA45991CULL, 0x8E9F3BEE04223BC9ULL, 
            0x9609E370FB59F68CULL, 0xB4E25B9494E37008ULL, 0x1020F9150D33164AULL, 0x5D70C02C8ADDAB47ULL, 
            0x30A99880A2DC3214ULL, 0xA8194CFDB8B22A37ULL, 0xEFA9466BE88ABD12ULL, 0xC4456F7749691424ULL, 
            0xC55164D69B8D7CE8ULL, 0x21EB2B03A2282768ULL, 0x3DB967C413756256ULL, 0xEEA851AA7B395DF4ULL, 
            0xFBC55FF0F8A9AC1AULL, 0xA277677EC14C999CULL, 0x979F5564190C505EULL, 0x564FDD02C7809B84ULL
        },
        {
            0x9062857F15A68006ULL, 0x432EF7E44973DCBBULL, 0x0911AF8025F43302ULL, 0x2F432CB996033F0CULL, 
            0xED553FBA25E23635ULL, 0xC96E3A2C3C51D8CBULL, 0x6FD2531804033036ULL, 0x0C2BC911A8C6DB0BULL, 
            0xD306F69075C472EFULL, 0x2735FA25AD79EF9CULL, 0xA4A182AB2043C947ULL, 0x95A9384BC1C4BED7ULL, 
            0xDF626C35C858BD0AULL, 0x9A374757E1E08596ULL, 0xC0854A6C27437238ULL, 0xF8C7ACBD54AF1662ULL, 
            0xEF6214DEBFF07111ULL, 0xD2037A306D34D6E1ULL, 0x078F20618166055EULL, 0x503C98719867ECA4ULL, 
            0xBA25C17BF5A807E7ULL, 0x97F798A841FF2FFDULL, 0x41E0DDEEFD3CAF1AULL, 0x172C2695DA152A47ULL, 
            0xDFDA1E370842E1B8ULL, 0xAFA309144CB1AD8CULL, 0x52DE34CA9B34EECDULL, 0xF213F049693C39A2ULL, 
            0xD7D30EA58C47D54FULL, 0x2C804898D015595BULL, 0xB05A0B00E6E23008ULL, 0x5E73BF3B4B841BB5ULL
        },
        {
            0xFBCF47A4841D6FE6ULL, 0xC24C1DA42E74C872ULL, 0x92E92A7839BCAADEULL, 0xD37E7B1560DDB266ULL, 
            0xFA316E7B8FD3894CULL, 0xDFA6590266AE709FULL, 0x8BA029A1A8A1F4DAULL, 0xC177F411171060E8ULL, 
            0x7713B776E97DDF7CULL, 0x194850B2463AE2C4ULL, 0xC2164248DCA8EE7DULL, 0xCDBCD4CB5C7B265BULL, 
            0x27CE4C451B7DDAC7ULL, 0x1D578303D8706248ULL, 0xB35FD8044003A3EBULL, 0x05B84BF2BF2BF44EULL, 
            0x990F11F916E8BD32ULL, 0xEB4C4705D3AC0840ULL, 0xCE2DA65859A2A9DCULL, 0xC1AE0B5571812E10ULL, 
            0x802D30EB6300D473ULL, 0xE64DD630046DE045ULL, 0x5A8F8B5CFAE9B46BULL, 0xFC382E11A148A689ULL, 
            0xE3A036381F42C28BULL, 0xFB88150DC0414160ULL, 0x8503D810EF8052F9ULL, 0x58CDB42DFBDD7C74ULL, 
            0xDE6AC7EE7079CD2DULL, 0x9E4F50D52F3F9DCCULL, 0xD95B8F3E0D4D6846ULL, 0x2EF50A859DF47A09ULL
        }
    },
    {
        {
            0x4F158054B4C72B2AULL, 0x53134D177E45C9D9ULL, 0x28367D4C040018D5ULL, 0xE6FF0A0F208AF92DULL, 
            0x14662DBFAC870D79ULL, 0xD34DC42190DCC683ULL, 0x6C3E8E9DBAA5F2F0ULL, 0xF837079E2C7F892FULL, 
            0xF5DE74A380790A6DULL, 0x60B31D53CAA29039ULL, 0x9156063FE80FC828ULL, 0xD1593FBA82C56A17ULL, 
            0xF5757AFFD4BC6695ULL, 0x192677DA39AF426DULL, 0x4FFC7F8D8A187D84ULL, 0x3E66E81A4FF04646ULL, 
            0x4F8B5DCD53B68794ULL, 0x2EF06BA9923A8F48ULL, 0xF17B04908B3C8871ULL, 0xDB17C5046240F233ULL, 
            0xDF37937B80E73386ULL, 0xA8C0F2289CD43399ULL, 0x8633834D4903FC0CULL, 0x55F3C669865B162DULL, 
            0xC6A9C804F169876EULL, 0xF03C10A08541E310ULL, 0x8CABECF09FAB18E1ULL, 0xD57073F9DA9209F9ULL, 
            0xB0E58FCD21F9A86BULL, 0xBB2E7C48EE5BE2D6ULL, 0x0505D4A517DA20FCULL, 0x6B1BB803EE36B10FULL
        },
        {
            0x837B119F63A046EFULL, 0x5EC84C6ED2FF4AD7ULL, 0x2615816515B88939ULL, 0xD2162F95D582A0A3ULL, 
            0x9A028FC382644235ULL, 0x92AA9A47D3103527ULL, 0xF743484A147F98ECULL, 0xC6BCC6C8121FA11DULL, 
            0x3E302CB2A8EAB781ULL, 0x1E13A4A15FD0B0F1ULL, 0x896FCEF121E83436ULL, 0xC5CB8BE9EFE83DE4ULL, 
            0x91A55C4A3F1C9A5AULL, 0x1EA32F91C517E4BFULL, 0xEF36F3B78759B444ULL, 0x3C216E63608E15B0ULL, 
            0xAEFA53292E56C5CAULL, 0xACB158C907A9BA22ULL, 0x3B247E5C86FDB9DEULL, 0x9855A9BC4EF21AA6ULL, 
            0x6E63A91CEDA14B0AULL, 0x450D15004F48BB96ULL, 0x0C62EFBFC422C064ULL, 0x083D0C4E951E9C34ULL, 
            0xBF93563C3352A999ULL, 0x433BF4691F9BA103ULL, 0x2A1DEDEB01D11140ULL, 0x2680C83B6EA3A52AULL, 
            0x1935E78734558785ULL, 0xCCEEFE34D7362340ULL, 0x2A42DE6E9C9D97E4ULL, 0x9165C72E654F1DC9ULL
        },
        {
            0x68EA78FC7402DEBEULL, 0x9D7CE54A7B6D210AULL, 0x252B5133C58383C4ULL, 0xDA5290B8AA19EF19ULL, 
            0x316D83F7542311DAULL, 0x9FA5D846234CD6F6ULL, 0xCEAEF2336249523AULL, 0x6EA73CE2B410DCD4ULL, 
            0x5A4141ECD7545A83ULL, 0xDDDF2BAB17C73249ULL, 0x08309C24EA8E663CULL, 0x5CF7314F18139881ULL, 
            0xB561FD7DDFA71A91ULL, 0x763DF8C717907376ULL, 0x8CD47AB9C73BE69EULL, 0x1ADDFC2709BA8A03ULL, 
            0x0A02879A9B0E92EFULL, 0xDC9D7D7C1564F615ULL, 0x160480FF9720FE3DULL, 0x61B904372D4DB494ULL, 
            0x3BB6F9EC98525162ULL, 0xBC57F51A3436792BULL, 0xC28605ECF10E9233ULL, 0xEC7DCC6B434A78A6ULL, 
            0x38AFE9C8ED0BA011ULL, 0x3BAB3463D2204C4AULL, 0x9A12C513E2D12E23ULL, 0x91F0C0D935013840ULL, 
            0xCACADDEC7E728013ULL, 0x6B7835BCECCA498BULL, 0x4A3282E549C7161AULL, 0x63DC7A3208534AAAULL
        },
        {
            0x5CAADA46B64F434BULL, 0x08C2C9B5BC01D918ULL, 0x3A1EE648293AF4BEULL, 0xC181B8F2B5357A7BULL, 
            0xECE4BA6CA0BC640DULL, 0x8BF52E43D70DA9FFULL, 0xC00DF9D71810C2B5ULL, 0x4AE3F270E64964DBULL, 
            0xEAB545FAF1142B3FULL, 0xC8732F21B2B99BBEULL, 0x0EC821615DE1B9F0ULL, 0x98E2FC7D47DCB289ULL, 
            0x6F8B26F1C9589668ULL, 0xEFC4EC6F77770277ULL, 0x03DE29DEDAD56048ULL, 0x85C2DAB7CD1CB345ULL, 
            0x7125C8AA2F906463ULL, 0x1F5BD460CB987FCBULL, 0x0D9BA42D4CB88C9CULL, 0xEEDBF0E8578F5995ULL, 
            0xA64A2CE4B9E60271ULL, 0x857154414210C897ULL, 0xCA985C50D29603D9ULL, 0xEE614B287651B4CDULL, 
            0xE59A01EBF4043C05ULL, 0x2236BF4C6E2D8380ULL, 0xCBD4F3908E3902E4ULL, 0xA78FE301FC8A878CULL, 
            0xDB42D242546674C4ULL, 0x17B471AB347326A7ULL, 0xA1978823ABA4CEA4ULL, 0xDD88F6D1C9A1A63FULL
        },
        {
            0x665143C6C6F2AC61ULL, 0xBE6322C7D76F702FULL, 0x36981E7413D6347BULL, 0x0748AECB01BD4CC8ULL, 
            0x761C8C9E1B50A0B3ULL, 0x4C7BB5A00EA9D45DULL, 0xB5E1342F47485CABULL, 0xCA8823EB0A4F34A1ULL, 
            0x109365E4FBEE59FCULL, 0x03B9623B32A3E3EBULL, 0x8040DA91ADD97940ULL, 0xA2A2902A9F558A6EULL, 
            0xD7E0A0EA8A3D5F57ULL, 0x5464D704F256DDE9ULL, 0x2E5D3D7D48B4F2F7ULL, 0x99CC22BC7B85B4B2ULL, 
            0xDD670A5E6AD93529ULL, 0x0DB8F336135E49A4ULL, 0x2C417F1383D84F90ULL, 0x8B68CC57C395459AULL, 
            0x7E8DAD5A3F481D21ULL, 0x98D74E516DE869B8ULL, 0x65CA7B1FD7C009D5ULL, 0xDD70EC95E44C975BULL, 
            0xB282C929A36AEDC1ULL, 0x33749A054A8A51C2ULL, 0x99740A06B29E6026ULL, 0xD51B80EB32C650CAULL, 
            0xCC5CF27A62FCAA4EULL, 0x2F293E2A75757B5FULL, 0xDA244115E1D0CEBAULL, 0xC31E1CCE621EBA9AULL
        },
        {
            0x676D0FBB23756F5BULL, 0xC618DFFF482B55A7ULL, 0xD33CABC4512996A9ULL, 0xF47E8DE00B890E3FULL, 
            0x7E2FC84A71A4659FULL, 0x39CD6C062FDDCAC5ULL, 0x70107E844629A27BULL, 0x7917B2D85AFD76CEULL, 
            0xFA5464D773ADAE2DULL, 0xB702E8858F1E60B9ULL, 0x7E76EEB1CA824ACCULL, 0x53EE20361CFC6932ULL, 
            0x9E38EA72CF38AA35ULL, 0x1E88895BB25279DCULL, 0x28A56C3C237F4E2CULL, 0x41006210A926C659ULL, 
            0x794F9286C00D159BULL, 0x62D5355E8DA1A1AAULL, 0x55112EB79BD484CCULL, 0xD16F9B6255E65A85ULL, 
            0xC716EBEE0AFED63EULL, 0x31008FC8F49C7AD6ULL, 0x5FC4585C262863ECULL, 0xC4958230D36A0C9EULL, 
            0x7BAB337DA3A356DAULL, 0x53E4769C7C35FA72ULL, 0xE74DFE55FC9F8C36ULL, 0xBF11C17BB41687AFULL, 
            0x7DE4E8201035A76CULL, 0x323D561CAABB6AEFULL, 0x109AA8596FEB4AFDULL, 0x949976A39243FF1BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseDConstants = {
    0xDD93F84393DE605BULL,
    0xBFFD5C9CEA057812ULL,
    0xA8EF3200125B0030ULL,
    0xDD93F84393DE605BULL,
    0xBFFD5C9CEA057812ULL,
    0xA8EF3200125B0030ULL,
    0x9BFD87794F12A8CFULL,
    0xD83A087301A646C8ULL,
    0x1D,
    0xB7,
    0x38,
    0x08,
    0x40,
    0x8D,
    0x57,
    0x09
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseESalts = {
    {
        {
            0x8AAE9A5F9C83226BULL, 0x02573F5FE83CF832ULL, 0x9FC691CB73B26642ULL, 0x7CBC21B3040DF819ULL, 
            0x711B04E4FC3CF20CULL, 0x435A7691D3F062C1ULL, 0x40260AD5B9305A85ULL, 0x0B071B00113F6AC9ULL, 
            0xE4A2168D00D81034ULL, 0x24A1466109796B3BULL, 0xA82E7F92FCA4922FULL, 0xC22B855D089D8489ULL, 
            0xC692EE2F47EC4AC4ULL, 0x333D76966652EDA7ULL, 0xDDC9086744218140ULL, 0x3CFC31445B3E28BAULL, 
            0x12F164DB226B6661ULL, 0xAA9A0E15B9623853ULL, 0xFBB7A1896D5B717BULL, 0x2DC5BA229E8A1E70ULL, 
            0x25040E4BD1DC9DF7ULL, 0xB2C3EDF80358DA1AULL, 0x6AD95CB3C853B44FULL, 0x6A723AFED47FDBCEULL, 
            0xF7459D0225C775D7ULL, 0xD0D14D94D6E63F51ULL, 0x7D1279A3B7137092ULL, 0xB1FA20AC01DAB19FULL, 
            0x65776DFDA9330210ULL, 0x94B742592AC2C893ULL, 0x3478EB499EDE8BF5ULL, 0xE90C88B283F87339ULL
        },
        {
            0x1F59F703A139B0ECULL, 0xDE8FFABCE5BBED67ULL, 0xBFCD7B7B5832FA0AULL, 0x9DBD04920D53499FULL, 
            0x407C685E1D25B79BULL, 0x271E9226D1AEDF25ULL, 0x8A3793B73B483DC6ULL, 0xF0C8A22BFA6EC363ULL, 
            0xABEBBCB577A1BC50ULL, 0x88534EC24BAFFF18ULL, 0x5DAC7D72ECD9C6A3ULL, 0xB16F397E439627A0ULL, 
            0x3EC0AE567F225508ULL, 0x9C5BDBFF2BC0520BULL, 0x53A6E94D53BD5F74ULL, 0xA33380DA74ECBCADULL, 
            0x217A9CA523AB83B9ULL, 0xF4884444688B9065ULL, 0x8AB056EEC79DD66DULL, 0xBE30025D40849A60ULL, 
            0xD6B2AC3430CD6224ULL, 0x8ABC98964F187338ULL, 0xC79E50AF392FBB7BULL, 0x9B8D7F6C2DD63568ULL, 
            0xAE795F08EF1F97CCULL, 0x1ABF271CF09AAE1AULL, 0x86AABD9F81747245ULL, 0x982E145FA863F1B5ULL, 
            0x82438019E82940DAULL, 0xA15E18FC9CBAD74DULL, 0x1AF04034938954BBULL, 0x3C633B60F510A645ULL
        },
        {
            0xD6E354EECF66021BULL, 0x7DEA3C6C2AAB1B31ULL, 0x35C74C3084FECC18ULL, 0x1FF29089242E3E60ULL, 
            0x2BBE5A291A4A6F02ULL, 0x75052AB7C92A1764ULL, 0x35DCB44649C0DBD8ULL, 0x1651FA5289D06FAAULL, 
            0x38DADF812126429AULL, 0x2079136A0DB40D3FULL, 0xC3473106C9D44397ULL, 0x134728517ACE52F3ULL, 
            0xEEA27E504E086737ULL, 0x7CE8C75C4B7230BEULL, 0xE270E52F3B013B28ULL, 0x668B90C2A2BFED4AULL, 
            0x195135EAFBF36F9AULL, 0x85A470291AA23AD1ULL, 0x6FAC8EF6666ABD87ULL, 0x1C4B969753970171ULL, 
            0x6C105DA73D8BC143ULL, 0x1358415756F52FF8ULL, 0xE1EEDAB56C7A8B51ULL, 0x558F4CBEBC2D5982ULL, 
            0x0CFA5CB86EF2D79EULL, 0xF656B2AD4E85EBE5ULL, 0xCF0912B1E9CE71DAULL, 0xC2BA5AEEB6AA2B68ULL, 
            0xDFEB4278F96BE0E2ULL, 0x7E594FB1DAF3909AULL, 0x45F2793675334919ULL, 0xD551154C3E31396DULL
        },
        {
            0xF8B3416179ECF7B3ULL, 0x89699B840214E92FULL, 0xA6F9226AF2E7C043ULL, 0xA096B5D9DF6E77C6ULL, 
            0x0F3326EF36D6CA9DULL, 0x8AC94ACE3E1C19F1ULL, 0xE2A70BBCE06AFE75ULL, 0x0001110394B2AD30ULL, 
            0x137353D5060FC004ULL, 0x447499D135775C30ULL, 0xF3882CA3C8D89B27ULL, 0xE5AFB7D1517A7AE2ULL, 
            0x775B877444683E6DULL, 0x33E526C83CEAC9A8ULL, 0x3902A05A92FAC6F9ULL, 0xC5F8C93B8B289B7DULL, 
            0x73F48D76E49AF733ULL, 0x413440D9A492B921ULL, 0xC0E1B713A2037ABAULL, 0x1F5477BBF63ED136ULL, 
            0x9E4BED900DB45626ULL, 0x003C18B32D9985C2ULL, 0xEF77017DB72D6DF1ULL, 0x60CE801CF52428A0ULL, 
            0x52399C0034AFBE84ULL, 0xC7C46C117DDDC747ULL, 0x049453A3AE23B702ULL, 0x0B2CCA27DD1C4727ULL, 
            0x8670838EA064B812ULL, 0x0EF8F534A75961C6ULL, 0xC8A703CC094F6A71ULL, 0x796C8AEBC6C24BC8ULL
        },
        {
            0x91CB90512E9E9ACFULL, 0xFAEEDD60D3944FB1ULL, 0x1382E83063F4C4F3ULL, 0x6068FC779FCB2B9EULL, 
            0x6923809654778F8CULL, 0x37C38AEF82EBAD3EULL, 0xC0C512FEE999354DULL, 0xD02BCA005FFCC67BULL, 
            0x2B29A56956891F85ULL, 0x86C03D57C8B72AF2ULL, 0x955FED1827B6942AULL, 0x4BA3B6B3EF271B20ULL, 
            0xA4BF797AAA6DA7F3ULL, 0xEAED92B73290CAE6ULL, 0x658F90932B30EF59ULL, 0xF1021AF95DB6C621ULL, 
            0x8C96CD72CE19B872ULL, 0xE45953233EEA59DAULL, 0x1F208445A60010A1ULL, 0xBAE7536E460F88F8ULL, 
            0xF5889C89A370C899ULL, 0x1F1AEA101F2BB483ULL, 0x141E7E302FD1B57DULL, 0x447C661908F3BC8CULL, 
            0x6E466C698703501AULL, 0xFACE7E474D752DC6ULL, 0xCC91CF87710A0A3EULL, 0xD4956517A07A052EULL, 
            0x4F5F269D15409CE5ULL, 0x26EBE1153722AD39ULL, 0x308722079EC23835ULL, 0xD9E4817A0494AA7AULL
        },
        {
            0x6EF1B9D8C2F77356ULL, 0x357B6469B61B2627ULL, 0x377A4E3643571889ULL, 0xA6809E2C09912AE2ULL, 
            0xCF4DA57DAB9C2E0FULL, 0xE9F420D77E4C8043ULL, 0xD98216EF8481C587ULL, 0xD64A0EB3EEC0E0B6ULL, 
            0x55995832951AF2B4ULL, 0x0908A85A5DD95455ULL, 0x18F93C7DC4FD3998ULL, 0x3F9A3FE799A160DBULL, 
            0xCC4AF03E4BD6F445ULL, 0x54751433A5E0DFCFULL, 0xF0B0A482CE6CA795ULL, 0xFCDB79B6FDC9DAC6ULL, 
            0xE3CF5857D9D53F13ULL, 0xEF71D7D1BB26FCEFULL, 0xAD7432242A46880BULL, 0x4960E35A601ECA2CULL, 
            0x2308DDD2F6220B36ULL, 0x43F4E2BDE1F8CABBULL, 0xC4041C875F3CE52EULL, 0x468F289BB4872618ULL, 
            0xFF827201F4359A3AULL, 0x240EBA053BDD0598ULL, 0x718F328F86E02CCFULL, 0x03E9301FCC974D8FULL, 
            0x37378C5F2658BADFULL, 0xA84EBF61CDCBF760ULL, 0x2DB8E7DFFD1BC567ULL, 0xA03672B9A140A970ULL
        }
    },
    {
        {
            0x2706079C6F78270BULL, 0xCB82B8890036AC20ULL, 0x81301847DCEBB6FFULL, 0xF8559C094E924B2AULL, 
            0xE198B249EC18D4DEULL, 0xC7EBBB0AA6A6BDA5ULL, 0x3099A342D43B99DCULL, 0x519AA6AB8350A8ECULL, 
            0xC7161FFE54E45F9AULL, 0xC014FE50CAD37A1AULL, 0x63586CBDC1E3CF64ULL, 0x86437A96A12AC308ULL, 
            0x9A87B9457E4C4DBFULL, 0xB467D91D7BBE02B7ULL, 0x5CDEBFCC91FA10FEULL, 0x29B0AF33A3C8BC9DULL, 
            0x33077B84A2D03FFEULL, 0x7E6E0810E172F379ULL, 0xA486C6E81C14CEF7ULL, 0x9AA481587BEF44D5ULL, 
            0x324FF8C4B236FF57ULL, 0x36970D05963188ADULL, 0xA42B267178BD2186ULL, 0x23AEB26EC4A6BFF2ULL, 
            0x4F3542AC1F0D7342ULL, 0x0ABEFA812DBB04FCULL, 0x99F34E1631F1A940ULL, 0xF67C7394CD8EA805ULL, 
            0x565930BEC226CB4BULL, 0x4EC06546DD33A3D0ULL, 0xE274C289CE7A26B5ULL, 0x4748D17B77E283EEULL
        },
        {
            0x5F7780EBAABE0C9FULL, 0x0F7A7C4678CE4B6CULL, 0x761D99C31E24045FULL, 0xB51D8514B0816F98ULL, 
            0x2DC0A80D13C5D823ULL, 0x4235D267290FC9D6ULL, 0x2F8E10940023B05CULL, 0x6BF2A356C1394D95ULL, 
            0x6DA767F5A72D28FDULL, 0x8FCB18A9AA28F438ULL, 0xE21662DF8DAF52AFULL, 0x63ACA1B6108151D7ULL, 
            0x2C83CF4A749677CEULL, 0xC7CEFBD954299316ULL, 0x0E02D9DF8B93A8F2ULL, 0x38FFFB19EE029E8BULL, 
            0x7A8EDF2C9A7EAF5AULL, 0x1B49EFE3D8CD7F91ULL, 0x1BB37E63F514CC4DULL, 0x11F92F428C70084AULL, 
            0xEA78E1229DFEBBDEULL, 0xF7979E2D2311936EULL, 0x682B50A8A77AA576ULL, 0xAB050BB88F9398C8ULL, 
            0xE294437C19E9A021ULL, 0x5ABED79897A762C9ULL, 0xDDD9F7DAF7AF9137ULL, 0xE8EB2759F2E67D69ULL, 
            0xD3EA34CC87BD3C3FULL, 0x6A0D1145522ECD73ULL, 0xA3403E275F76E674ULL, 0x46E86128FBE38E4EULL
        },
        {
            0xF0BAFD2E0B35AF76ULL, 0x72A9A4D71AD189B7ULL, 0xEF2A5A9A1CCBCAA7ULL, 0x5B966E1E3999F1FBULL, 
            0x2E2998A7FBE2BD4BULL, 0xBF8D82EEFD03ED93ULL, 0x4B12E3B25285B16FULL, 0xAAF8311AC6A52FAFULL, 
            0x4194D7D92309C323ULL, 0x89580348902A0888ULL, 0xC5EE3E4B5431C33EULL, 0x05FC5841FF7D9717ULL, 
            0x44A56D654E03C459ULL, 0xB745876C5C351DCBULL, 0xF55D89FC02011280ULL, 0xE3713F8AEC6B7394ULL, 
            0x1983CECBAAD0A169ULL, 0x2D663F8E1308A699ULL, 0xD799342287DD8BC0ULL, 0xB265BBA416B6BFE2ULL, 
            0x886CF8A846DD8FD0ULL, 0x8A3661C7A0490F87ULL, 0x06ABF1BEC1DAE8B8ULL, 0xECA1DCC3727F4816ULL, 
            0xF689D15E045712CCULL, 0x5C00FE5B4997850DULL, 0x95A979883A888496ULL, 0x461AED01B4FCB863ULL, 
            0x11EBBB847E10DBA7ULL, 0xE2A5507FA0561991ULL, 0x87E2BEA821605B7EULL, 0x8049E48D9B5B7740ULL
        },
        {
            0x17883B0987CC9724ULL, 0x705417F6B0D92BF1ULL, 0x53F9AAFAB9BDCBB2ULL, 0xA8CDBEC7AA5F0DE1ULL, 
            0xA872F3275A568112ULL, 0xFF699BEF30561C11ULL, 0xEB18F4743F43FCF7ULL, 0xA89424304F66D6CDULL, 
            0xAA18A32DFA228F24ULL, 0x71586A32F2DEDBE1ULL, 0x6ABCA52770D10697ULL, 0x25A2D60AE913099BULL, 
            0xE72E0784B088894EULL, 0xECF146B893857F8FULL, 0xC3D94A152675C92DULL, 0x48D375BBF293BD11ULL, 
            0xFBD54018E3F902E7ULL, 0x9AF66347356804B0ULL, 0x09AF3E9A128F4583ULL, 0xECD3ADAEE4BFF160ULL, 
            0x5570670218F3F7E0ULL, 0x2B08BC7E7FE7845EULL, 0x75AEA6F87B585138ULL, 0x2DB037E8AFB961F1ULL, 
            0xA8D6D98EAA1D4457ULL, 0x4DD7FC054274097FULL, 0x828F52E2E69E0B56ULL, 0x8979F101D7B2B968ULL, 
            0xCDF36D1568012C5CULL, 0x0FD21DCD512F42AFULL, 0xA5D0C8C5D8A00229ULL, 0xC228D8F7A71DFA2DULL
        },
        {
            0x49104A78ABD441CEULL, 0x77C4B1A0836D3AABULL, 0x0A0DCD32216632B5ULL, 0x104113BE11BC3AA3ULL, 
            0xC59D55A679BCBFA5ULL, 0x67EA1092789348EBULL, 0xCF620AE61E14B406ULL, 0xBA57985D54B1B566ULL, 
            0x2229E638EFB6373DULL, 0x1A8168BE63408CCBULL, 0xA38FCA23D8819C25ULL, 0x7DA9AE38F488EECEULL, 
            0xC5B56A340C8FF785ULL, 0x22E12ACF7A437BCEULL, 0x030A3780239B54C9ULL, 0xA6358C0ACA632D88ULL, 
            0x48CFA1B72CA15EF8ULL, 0xCF25DFC291B7034CULL, 0xC4D3162F28926490ULL, 0x9BD4133C67FF3538ULL, 
            0xFC585EF92443E147ULL, 0x7F893ED9CEDEE9B4ULL, 0x6B6DA297C0AEC413ULL, 0xDA1D635018501B75ULL, 
            0x2C7AE28AC98FBC9CULL, 0xF940176B616C205FULL, 0x3F242AED3CEBD85FULL, 0xEE51CA37CBDDF4ECULL, 
            0xBF4E74C6C0A03AABULL, 0x6C65CAA2FED29F1FULL, 0x589CAB0F31A659FEULL, 0xBA45208AF2F1E47BULL
        },
        {
            0xE544C96CCFFEE38BULL, 0xB5D998A93B446E0BULL, 0xE2A3A2EF05B19826ULL, 0xB2FA22D36CCC4939ULL, 
            0x78F551241EE7F04BULL, 0xD455975CA3AF8511ULL, 0xC9BA0605C2685BB1ULL, 0x8D6955DA3472696BULL, 
            0x5567837B12DAB87DULL, 0xC9C605C069461B65ULL, 0xEE21A20DD2241336ULL, 0x48FD1BC2E0DCBF52ULL, 
            0x142E40CC78B987DDULL, 0x99D876CA3D1A7D13ULL, 0x8410FC1A73B2D0A4ULL, 0xE2B99D95ED57B22BULL, 
            0x3DE0DDA6C6EC39F3ULL, 0x0AF9B70F8E18BEFDULL, 0xA153802FB15FFD0DULL, 0x32BDD55DCF8BC1E4ULL, 
            0x4B196097AE450C83ULL, 0x0C800FA30FD33399ULL, 0xD063CF164E00C752ULL, 0xB65E2DD702D7DD2EULL, 
            0x5A78019D710230AAULL, 0xE2095583D79C73F6ULL, 0xAFD257539641E549ULL, 0xF2B2094CDC8A111CULL, 
            0x7C220676AE25AF03ULL, 0x686BB363D5974477ULL, 0xCC9844422676E30EULL, 0x5F910521E066CA3DULL
        }
    },
    {
        {
            0x156578ED5CCC2739ULL, 0xFD0E87C29459684BULL, 0x365DB14A7BFF6329ULL, 0xF200049ABE61ACA8ULL, 
            0x8A91CF6C5F6DCD14ULL, 0x530333AFF4F4F19FULL, 0xD239D8000F129698ULL, 0x2A79C9AB2B29674DULL, 
            0x82E8C7AA8EB8EB64ULL, 0x582CA92C56731E75ULL, 0x41081B3BEA9C08FEULL, 0xE4DA1C3014936292ULL, 
            0x1C86089B4602D4C0ULL, 0xBEE4A7BE7368F482ULL, 0xD8091D0DFFAC5EF8ULL, 0xFBC84CB4E50C1C67ULL, 
            0x9F80C801FC7B275FULL, 0xB654DD0E751E5EDAULL, 0x335D8001D23753D3ULL, 0x1D8032F63D0C0AB4ULL, 
            0x92D30E0311DEC93AULL, 0xEEBCD8E5C57AFCBCULL, 0x51AC30A83C0A24DDULL, 0x9F2733ABC93613C6ULL, 
            0x01391543408A33A1ULL, 0xA0857E18678F02E4ULL, 0x67429BC664CF7A4BULL, 0x9F78E0AE4CE37A7BULL, 
            0xB741C3A5DDE43A8CULL, 0x42DF66AC5D1AAA35ULL, 0xF2E7A4852EA9B339ULL, 0x75F5746DBA7F0E55ULL
        },
        {
            0x408AC52884DC32FBULL, 0x230BD7FAABEBD95EULL, 0xE78BCA72FF24FE89ULL, 0x41414BD662613DD2ULL, 
            0x064B66D1C7354C37ULL, 0x8B6D205E02942E8AULL, 0x0ABADF212AD2628BULL, 0xFD4B4A8040A9BC8EULL, 
            0xE189350268A841AEULL, 0x9C4A84502CEAC25EULL, 0x65D2C7465648BBF2ULL, 0x8214DF7FB763A406ULL, 
            0x68F5E8584BD11C8AULL, 0xBA799311A9392A09ULL, 0xE4408344BD6A1FB8ULL, 0x7EF96330E4A44F24ULL, 
            0xF67C1CCC9848339CULL, 0xD1494A4250B76862ULL, 0x378AE9E0F0927551ULL, 0x8B922FB1BB081852ULL, 
            0x636F3D473C074A8EULL, 0x0FAC9398362CB5C1ULL, 0xF1DE9762E992CA80ULL, 0x73B52EBDF5F4B892ULL, 
            0x7FBBFFA54DDB6CDDULL, 0x8D5037AEB790E059ULL, 0x451F4F6D096E602BULL, 0x6DBF01791C167B72ULL, 
            0x798628D5F53E9A58ULL, 0x0E2824ACD25892A3ULL, 0x6505C53B4687A7CCULL, 0x7CCA110344344EE3ULL
        },
        {
            0x7E6F1E0AD8839AA4ULL, 0x255FB82C8B23DDA4ULL, 0xFA24FC0CAD1C3AABULL, 0x8AA93C2B8815842AULL, 
            0x606D4A3A40190088ULL, 0xF15E4CA5C6AAB348ULL, 0xF22D99C4B2501BB8ULL, 0x00B1D7AD177C090DULL, 
            0xCECB6B4204B44827ULL, 0x4910C32D02A4F0E7ULL, 0x6AEAA91BE48695BAULL, 0x54A02523D59ACFEEULL, 
            0x46AC9F11D1022875ULL, 0x8A54999E3E5DEE74ULL, 0xD89D59ED8506DEE6ULL, 0x5079274DB6833777ULL, 
            0xC32CAD41DF3B809EULL, 0xC7CF26046C8DFE2FULL, 0x6C5CA81608DF83BCULL, 0xAE6D16CFFA784A74ULL, 
            0x057CE410E7B0A2FFULL, 0xE5F89C0B1D856F1CULL, 0x8B96DD30B167BE87ULL, 0xDC003EA765C79EFDULL, 
            0xD848B29CE79D1A1AULL, 0xCD80BC9528C24DFCULL, 0xEC119271D9ADC746ULL, 0x9108D760D76D8E57ULL, 
            0x35076F07B2E4DEF2ULL, 0x5212EDB65CA32F4AULL, 0x88119E26A324DFB5ULL, 0x1308CC2EBCDB992AULL
        },
        {
            0x7AE9DE86F9471C14ULL, 0x9BBB1ED2D992854CULL, 0xB7AD7F8549A43665ULL, 0x51FFF3E7301DE8D8ULL, 
            0x524488A043B8836EULL, 0xF23552DAB037D238ULL, 0xF196279033F3F9A4ULL, 0xDEF857CE6F3C08B0ULL, 
            0x2AC78A7B63A004BEULL, 0xD537DEAA20A050B7ULL, 0xDCCCE98889D199EAULL, 0xA27EDE0D4DE7A511ULL, 
            0xEBADBE2122BF18EDULL, 0x6E819010D91668FEULL, 0xFC8A300DBE48F20CULL, 0x9FA16B3D7DBB2FD1ULL, 
            0x37FCBA9591DD0A9AULL, 0x1B619EA0CD622B63ULL, 0xFEE09DA1B9E62A6EULL, 0x08AE4F57D3F3050CULL, 
            0x3A6ABA7711C725EBULL, 0xB71F5DE55A908B0CULL, 0x6CFE6421AD6E4FA8ULL, 0x46329E8C78BA4F35ULL, 
            0xB980088DFB019BB4ULL, 0x45815FD415812DE3ULL, 0x757762507A223F04ULL, 0x0DD6532A80EB9A9FULL, 
            0x6DCB29EDF5F3793CULL, 0x218E19A680BB858EULL, 0xAE58480FC260EAFDULL, 0xEDE754F98241453BULL
        },
        {
            0x63A9E2E3BEA4495FULL, 0x4D7D9C4FC2FAE4FBULL, 0x2F568C278A8A4E89ULL, 0x501928A5FEB0C2E4ULL, 
            0x731D4CBC244852CFULL, 0x8FF2C73DC0EE54EFULL, 0xC95209437A00DB7CULL, 0x9C0630AFEAD58AA9ULL, 
            0x3E72C687D852E474ULL, 0x53F9A3A0CA4B1E86ULL, 0x1D73A208F61508EDULL, 0x7B36C34B03C094AEULL, 
            0x8B45B30083C8D774ULL, 0x263B06112A083212ULL, 0x2466F7BB9B181B67ULL, 0xC53FE80F08604B6FULL, 
            0xE154565210179D86ULL, 0x2B6184FCBCFF52FEULL, 0x6A39A7DA03E029E9ULL, 0x5B89725398254FCAULL, 
            0xF88A19C91F90947DULL, 0xEEFC79348D472300ULL, 0xE1EE14F87ADB2AFCULL, 0xEB177F582D8534E4ULL, 
            0x831B6E8DBC404DBFULL, 0x5D20A2553D58DA13ULL, 0xFB99F554F5C87BA1ULL, 0xFB9A5015AB6CB8C1ULL, 
            0x2DF0996435B18477ULL, 0xEB36F2938244436EULL, 0xC783077C2CC70FB2ULL, 0xDB752551B0B4D6C4ULL
        },
        {
            0x33A79767594514C3ULL, 0xF1D550A23246818BULL, 0xD4700812D2C64A90ULL, 0x16F8ACA8BABCB2D5ULL, 
            0x2170907CF5364A61ULL, 0xDE5F3CE382871CF5ULL, 0xD1B42EA21AA2644BULL, 0x8D6FE9206A2C0D0DULL, 
            0x6F9A3201AE8210D2ULL, 0x9C48735CFF3DC406ULL, 0x51CED3096C926FEDULL, 0xE3CE611830781FC0ULL, 
            0x07245B75B9A8803CULL, 0xB3F560EA513565E0ULL, 0x33C50F8B3C7BA2D7ULL, 0x2F15D155C00071CBULL, 
            0xA8BAFBD24B44966DULL, 0xF85A29466345DF91ULL, 0x816C05D3B1671C61ULL, 0xFF91E82557479490ULL, 
            0x41350751613D664EULL, 0xEFE0282156D727A7ULL, 0x7C146415B65A7CD9ULL, 0x4C3DB520ABACDE3CULL, 
            0xDC2E302466F8F72CULL, 0x6B61FF1BDCB3B55EULL, 0x2164A78C2EE7AE33ULL, 0xD4FFB6566A064966ULL, 
            0x0377338FD7157034ULL, 0x6756ABF2229070D0ULL, 0xC22FCF4EF7152E33ULL, 0x42DDCE6C5E5FE3A1ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseEConstants = {
    0xEAAA3C25E136B655ULL,
    0x7474E8210BEDBDC8ULL,
    0xAC130CB91078413EULL,
    0xEAAA3C25E136B655ULL,
    0x7474E8210BEDBDC8ULL,
    0xAC130CB91078413EULL,
    0x9B0792C5B81A34ECULL,
    0x52A025286AE1A099ULL,
    0x7A,
    0x97,
    0x76,
    0xF6,
    0x9A,
    0x37,
    0x62,
    0x8A
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseFSalts = {
    {
        {
            0xC2BD905149F126E3ULL, 0xB2CE72C33DD8C6A9ULL, 0xE21D079639B07743ULL, 0xE19795F03D4A7BBEULL, 
            0x19B556447463CD8EULL, 0x0ABA140EC28DCB5DULL, 0xAB847D9C68636A39ULL, 0xA1C01ABF0405F9A7ULL, 
            0xC4186370B84DF8EAULL, 0xFFF18F468D4870CDULL, 0xC3860D080B0C9FD3ULL, 0x5C53499F6611EC23ULL, 
            0xDDAFC240B7C67276ULL, 0xDD9D22743585B38BULL, 0xF13B017EAE9B9BBFULL, 0xFDFCD853884AEB5CULL, 
            0xB86577A69699CB99ULL, 0x9FBF5C3E9AF4677CULL, 0x97BC9973450AB5BAULL, 0x252816FA0D305A22ULL, 
            0xCAA5F697B7FC7B20ULL, 0xCE9F47E607B11795ULL, 0xE3EED1FCDFAA4071ULL, 0xC66AADF5CF870499ULL, 
            0x3969BE40B0FA5A70ULL, 0xADD34526DA2731B6ULL, 0x81F42AADBF40BB3BULL, 0xEADA037C773DBB9CULL, 
            0x3DB208AFDBB2BFD8ULL, 0x153110B08845BC9BULL, 0xDD550049D80C2D53ULL, 0xCD398D2380C01275ULL
        },
        {
            0x583D9DFB2C43E65CULL, 0xA9302E75C55B694AULL, 0x31D5105B2BDD0A2AULL, 0xA79F0E16A677E795ULL, 
            0xE150DE55BE004FD7ULL, 0xF1F790EAC6778E33ULL, 0x2D546C1C055DFCF4ULL, 0xB72736C6B21474FFULL, 
            0xAA286D2B09DF3580ULL, 0xF8A6047C1B6D0C04ULL, 0x43FF373BE5D7E858ULL, 0x2584B6CC3E327B78ULL, 
            0x6E6B036F330B9869ULL, 0x685C7811E411417DULL, 0x7998933665494FE6ULL, 0xA958BBF420F71DD7ULL, 
            0x70D760CBBFA98670ULL, 0x12C254862A9FB8FBULL, 0x477A0D4A46AA4BB9ULL, 0x72542ACC29E6E7D1ULL, 
            0x9809A7969BB5E9F5ULL, 0x6CDB0E06C8701A2CULL, 0x06BE42A90ABFE881ULL, 0x0D4620B66F496AE9ULL, 
            0x2751C8871F8631D5ULL, 0xB41BE476287AFACFULL, 0x5286CB005E8CB74EULL, 0x80668B908B7D0DC1ULL, 
            0xF0EF00D05B1761B5ULL, 0x47706B61D8329957ULL, 0x8F1C13B8E3B17917ULL, 0x6A3E1B50A6A7E237ULL
        },
        {
            0xCF8CF24B8BD3F562ULL, 0x9D30CB6578561D5FULL, 0xFD2181EB7E432EDAULL, 0x04583DAA111F37DDULL, 
            0x7A964394BBE83755ULL, 0x5C0A324212C7FE06ULL, 0xE7CEA2E4B8B00EA9ULL, 0x5A952F608656279FULL, 
            0xF833B27E177684D8ULL, 0x9D4559C24A528343ULL, 0x0B6875F7D6A3432CULL, 0x13AC523A1C251455ULL, 
            0xF4C4AF399DBF06AEULL, 0xC95D45D116FC9112ULL, 0x0E242B8709B7322CULL, 0xD17351F449A71976ULL, 
            0xEBA407C0BE4F8C84ULL, 0x54F8CB48DF276EFCULL, 0xE001DC88452E8FD6ULL, 0x9F1637BC14C764D5ULL, 
            0x88F86123CFD03F24ULL, 0x8C83DD9DC23762A1ULL, 0x03EA3623C77B4AA2ULL, 0x7D223993A5C2A010ULL, 
            0x5118613B11633751ULL, 0xEBF34ED7ABE9B73FULL, 0x05D39292C7DB34CFULL, 0x9E8E5D53C5281934ULL, 
            0x5A31698F7785E366ULL, 0x37E6343B24D9A999ULL, 0x642B8A9AD0885196ULL, 0xF9016B6424BF1012ULL
        },
        {
            0x4037A43E784E02DAULL, 0xDD1A0FAA8D16C6E7ULL, 0xEA83283B32CD1296ULL, 0x93249848B51AC08BULL, 
            0xC1B8EB9752C204DFULL, 0xF898731D8F926B37ULL, 0x7EB931536569D30AULL, 0xA81BFEE04C9AC6C5ULL, 
            0x8C55BEED690B4F5EULL, 0x50E41C92B65602E3ULL, 0xA7A9A4810A31A126ULL, 0x5EDE69C99E8C93C7ULL, 
            0x4E7EB07BD530F4F0ULL, 0xD5B57F006EAD912EULL, 0x2BE3457D2B5FA7E4ULL, 0x52212D8FD0C62A48ULL, 
            0xA136C5D558CC3319ULL, 0xA7732429F9DD06DAULL, 0xEAAF0B28D23FF7AEULL, 0x1A51A583D78973E1ULL, 
            0x3444B65E1769A4B8ULL, 0x8F9B4BB96EFF3DA0ULL, 0xECF555B827B5FF9FULL, 0xC5E3B6B51489F99BULL, 
            0x7EC4FCF9529E3B31ULL, 0x433AAAF524D56A58ULL, 0x1FD242CE2A91C73DULL, 0x3C21384362FB4BEDULL, 
            0x242C1FB337BA0968ULL, 0x4356BAC7553DCE3AULL, 0xD1D33472C20A0529ULL, 0x00B7B7CA1B02ED18ULL
        },
        {
            0x337B8FF9B04E7E28ULL, 0xA00E51021B721951ULL, 0x8DBC806DC7D310D8ULL, 0x7B3F63A541AC321BULL, 
            0x3D0E0243FF2BBDF1ULL, 0xDCA4289B2D4B0E25ULL, 0xE18CBE68D0123577ULL, 0x4C69446B260588CAULL, 
            0x7174643AA2C3A33CULL, 0xEBEF907548B7FA71ULL, 0xB4E3D8234DBC0676ULL, 0xC618DBD2A9142199ULL, 
            0x9679DAC6BB3F19EEULL, 0x1002D64588EFEC94ULL, 0x00EDCE5739CCF6E0ULL, 0x85006710172CDE26ULL, 
            0x775311F57F2868B7ULL, 0xD20441A4CEE90E2FULL, 0x6E547B17CBE89B51ULL, 0xF8F2C126E1FD8259ULL, 
            0xEE1DC8B5D5C9E26BULL, 0x012D065D6FB11801ULL, 0xFB26D78F3D2F258FULL, 0xD8A381FF467737C9ULL, 
            0xD5AD20FA8A4A94D8ULL, 0x0779B7AE81623A6AULL, 0x2785C5CB3CF7407BULL, 0x94D66C477FD1A87EULL, 
            0xC586CFE35E9457F5ULL, 0x33AC3878CE6B5D23ULL, 0xF07CF6A190B4898BULL, 0x23073A484194264DULL
        },
        {
            0x84696AD1BB2B3386ULL, 0x15464CA36B0BA30DULL, 0x8054CCAF209DA843ULL, 0x3192A96161AAF154ULL, 
            0x76B420DF492A17B4ULL, 0xB2E4FD9C22C5914EULL, 0x9BD04253DA918F92ULL, 0xAE04CCE0C9DCF950ULL, 
            0x7C62720347D447CBULL, 0xD435ADF49753F1DFULL, 0x48FA3D405980552DULL, 0xCEB667427CFDCD22ULL, 
            0x9EB68F1D108A8204ULL, 0xD13395712A4FDB85ULL, 0xBF57123050E1D86FULL, 0xD9A679C5D985B93AULL, 
            0x22EEAD5ADAC180A2ULL, 0xEFBDAF38B7C4CF49ULL, 0xC7501FBD4DEB0887ULL, 0xEECACB45B3487949ULL, 
            0x57068D490384D5A2ULL, 0xFA57E1480794D19AULL, 0x7741C3E9EBB4BD3EULL, 0xD81AC7DAD56E4DF5ULL, 
            0x09AC4B18AF1296CDULL, 0x180CB6B04CDFC51DULL, 0x30C01F5948BFC611ULL, 0xA09B7BE7EC2E9ECDULL, 
            0xBA9D108E56506DC5ULL, 0xD452EFCE4A3341D8ULL, 0x00A1BB7DB93C4238ULL, 0x12F966E3D010A713ULL
        }
    },
    {
        {
            0x790F8D8BA007E749ULL, 0x5FF5D36E4AC67084ULL, 0x68A2E669C338F221ULL, 0x1F938F79D537517BULL, 
            0x7EC5E2D45ED34342ULL, 0x5E5854E0B516B3E4ULL, 0x9295737A9BD700B7ULL, 0x74ABE0C455B01776ULL, 
            0x28D1F8F0266C11EBULL, 0x74B66CE5C73F992CULL, 0xD1495CAF95FA925CULL, 0xE01556BA92E628EBULL, 
            0x35E921B1BE06F2E8ULL, 0xF661E4C0C694C59FULL, 0xA8EEA6369F7C0E0BULL, 0x9EFF6A725E80F383ULL, 
            0x726C6FB6DDE107ECULL, 0x5995D57D1EB5713CULL, 0xDE1694526F6E0324ULL, 0x7E87FC95BC187AABULL, 
            0xE7579C6D85525711ULL, 0xDFF6E80CEE330346ULL, 0xAFF3C14012CF8521ULL, 0x5FDE901A24BF7DCFULL, 
            0x80F7AB43E639CCD4ULL, 0x0EEA5F95D05C73CEULL, 0xFB60A41D6FB5B675ULL, 0x079F7748FFE0CC77ULL, 
            0xBF030A3425DE4606ULL, 0x4DB33834B5F4FD9BULL, 0x0F6332BD31857134ULL, 0xB0194F046669630DULL
        },
        {
            0xB013A57FC22D7F67ULL, 0xC45E0C73602688C9ULL, 0x2665FD6E57901FECULL, 0x2BCC6BDE1615D009ULL, 
            0xC631BA3CB4B24B13ULL, 0x1E3922C3CB222D4BULL, 0x3E8208B049E23DC5ULL, 0x0CC8A6C5360B1DEFULL, 
            0xF92E40D4CDE153E7ULL, 0x30D71ACF83BBB38DULL, 0xADB70A815A3CC2ADULL, 0x7D789327ED5C48C0ULL, 
            0xD06CAF44590C87D7ULL, 0x6F24A143DF05434EULL, 0x516984B72A117672ULL, 0x8A84AEC36334090FULL, 
            0xEB408D4FC5657EF6ULL, 0xD4AB796FF2EF9265ULL, 0xF4E20884A4EE5E8BULL, 0x49DFF431E2E68E1EULL, 
            0x5095A09C4733B9D1ULL, 0xCC09FFC1DA2F2F76ULL, 0xA21DB9B5BB54AD43ULL, 0x8DCBFC246ABFA459ULL, 
            0xC0AD74B257C057EFULL, 0x487C400C9E3E19F2ULL, 0xC3C1004C3222D275ULL, 0x82CE78F548E1CE0BULL, 
            0xFAA344003D27B5A4ULL, 0xE94441051BBDD81FULL, 0xB03FD143BCDDDEE9ULL, 0x0702A789AD3B918BULL
        },
        {
            0xB1769ECE3F8A4BCCULL, 0x5D1B20BF848BF59EULL, 0xF0639976166A230AULL, 0xDEA8D27176CDB2CCULL, 
            0x6059EBE9E231BA6EULL, 0x8586D2CF00B1AE30ULL, 0x9E48720E6680E90BULL, 0x705067250F93CAF7ULL, 
            0x27152C0700E7C2FAULL, 0x31EAE64A59B99F0CULL, 0x5A7D4BDC7EF1DB00ULL, 0x4A10E258F8F06BFCULL, 
            0x738634491F42B3CEULL, 0x4E5C66A04063EA02ULL, 0x0F92A46B48797802ULL, 0x58D6C67B566801D4ULL, 
            0x9E5EE204BC5587DAULL, 0xA2AC9C3B63A4670DULL, 0xA3647267C629EA42ULL, 0x8BC3B225255BF77AULL, 
            0xA91D8C0DAAD0BCC9ULL, 0x1F7B9A3778B97808ULL, 0x39C19DCDED31A2E8ULL, 0xD045C41BB229BD7DULL, 
            0x67E72782138FBF26ULL, 0x6924ED7A189380E7ULL, 0x6D3657B04BC02015ULL, 0xBB281430EE012EB0ULL, 
            0xD3140CBA78907110ULL, 0xC2C5CB3512CEB9B0ULL, 0x50460BBAEA624471ULL, 0xC4E14EFC03AD41E7ULL
        },
        {
            0x04B46A833AB656B4ULL, 0x65733F6873C31059ULL, 0x5FAE7E2B6753E68DULL, 0xAA74A79877276B7DULL, 
            0xB03E4CEABB502E91ULL, 0xC207902D3C49D29AULL, 0x1EA8074D399661FCULL, 0xF7CAF934F90151DAULL, 
            0xD9497813AF0BD3D9ULL, 0x3B65F812945CF536ULL, 0xABAB2E84CA1CEABAULL, 0x5DFA2834670E8ECFULL, 
            0x61A99070A0E48F53ULL, 0x61C05B59F560E453ULL, 0x2346F2848C5D8D68ULL, 0x203580B9C114F8C8ULL, 
            0x9501A84A2DAC9A2AULL, 0x6E411CC79C9F9F28ULL, 0xC61500D7B42C278FULL, 0x3386C82ED3F5010FULL, 
            0x3A889BB62FA87917ULL, 0x48EB9617EF3EDCB3ULL, 0x4448C27BD4C71AC4ULL, 0x5358C52C4CB5BD96ULL, 
            0x6711C7B16AB29FC6ULL, 0x6A1D5B42D1710B17ULL, 0x188BA33EC602372BULL, 0xF8E9B8796340C047ULL, 
            0x78827EEC1C00991FULL, 0x7E5C1D3FD3F19BFAULL, 0x47AD7196D34F2902ULL, 0x601B181CE2C6CCBBULL
        },
        {
            0x88CC7D9293EEB243ULL, 0x6F4B913880DEF62CULL, 0x747251FD3AA37BACULL, 0x4D04FA4136D499F9ULL, 
            0x6DC7AF095BD14688ULL, 0x38A038917BB1EB1AULL, 0xD3D2340923083EADULL, 0x1C3E8EB7AAB4B5EAULL, 
            0x16807C647521175EULL, 0x5D424183424C60E1ULL, 0x03A210AF6EF22099ULL, 0x4FD673AD3957B931ULL, 
            0x7912E201BAA87889ULL, 0xAB9BFC159C4B01F5ULL, 0x27E24C81E9059B19ULL, 0x96679641E1B1B386ULL, 
            0xB76CE5419647DC20ULL, 0xF345B88EC69EE449ULL, 0x5C26A57401124A13ULL, 0xB1DF1C9979BEFC9FULL, 
            0x50FF42158D48352CULL, 0xA3F011B299C53299ULL, 0xF5A87B18D0D5C9E8ULL, 0x3292F77D807C0CD9ULL, 
            0xF6DE755159D87D67ULL, 0x7182DA31C5C6F156ULL, 0x1C8A58F5DE1196F7ULL, 0xD33208B08824E01BULL, 
            0x76639F1093FA5EA7ULL, 0x88C851BF2B1BB33FULL, 0x4D3AAFAF78CC7327ULL, 0x60C9D17EA4ED5E80ULL
        },
        {
            0xC5381DC2A931E54FULL, 0x763DEE09FD5615F7ULL, 0x311FF0CBD4F3426CULL, 0xC9BCCB3E23E6887AULL, 
            0x277C9CBA5E11C908ULL, 0x794A4F4D62407289ULL, 0xD89209AA203CA496ULL, 0xD58043628C23B229ULL, 
            0xC578076CD0400D9EULL, 0x143E531BB6C7B5CEULL, 0x84E1140F098BA618ULL, 0xDF5DDD763A2513C0ULL, 
            0x7AEA72109CAA641DULL, 0xD178F8BA0A06479BULL, 0x9B37FCDA5EB46AC6ULL, 0xC93A143E73E660CAULL, 
            0x7F17A1E6B00545A1ULL, 0x29BCD7DEEC6189D3ULL, 0x36602061BDF74C2AULL, 0xD76611D316DA7608ULL, 
            0x492188A464072E3DULL, 0xCD99F623CE440E4AULL, 0x73A0CA25EAD9CE4EULL, 0xA130A78644591971ULL, 
            0x27BD7A9B3D61FDD5ULL, 0x89EE9EBBDAF359B7ULL, 0x52AFE456D5AC6473ULL, 0x456A24D0112841B3ULL, 
            0xDC94E9D7F731198CULL, 0xC1D867E7CA836A37ULL, 0x11E9FBD1267CD3FBULL, 0xB79ABE8F4A8DD84EULL
        }
    },
    {
        {
            0x4E6C1963D73B7BE3ULL, 0x37E1F0F2D32176FBULL, 0x9CF818BE660D41FCULL, 0x3FE276FF22CB22DEULL, 
            0x770985B1543121B3ULL, 0x4563FEE6CA84AF50ULL, 0xDE7092FD271E8871ULL, 0xDB6691977630572DULL, 
            0xB4D59EE192C58E7DULL, 0x5A1B7064E07609F6ULL, 0x9510399899058076ULL, 0x78C82A74762D2AE2ULL, 
            0x653B5B121473754EULL, 0x4A60D7E5A8BDA6FEULL, 0x9E952C56B910A378ULL, 0xD4910D386C7288E3ULL, 
            0x9366D958FD931A4AULL, 0x00164B83F7E8EFC3ULL, 0xAD8D7FA0AC2F00EEULL, 0xFA171E9822807F25ULL, 
            0x90AE9EE26FF3157AULL, 0xB4F27F30E720443CULL, 0x68BA367069E2FC86ULL, 0x7E74154A811967D3ULL, 
            0x5E896D97B4EDA13FULL, 0x103BE89FFF7E6C75ULL, 0x8485A834BC583693ULL, 0x091AFEC89508C0A1ULL, 
            0x5227D47DA5FD5B3EULL, 0xBF0AFF339EA97CADULL, 0x278DE535F47CCA69ULL, 0xAF3031603C3E3DA0ULL
        },
        {
            0xB3F1C3C10F2583DAULL, 0x50A7D8645A12A5E4ULL, 0xE4296A3EE2997D80ULL, 0x07C3CDFB63090322ULL, 
            0x7F3D5C956E79FB53ULL, 0xA7EEC78DFD1B0507ULL, 0x8F682466D5B784C8ULL, 0xDBE21F178CBDF77EULL, 
            0x5CEB7C5F438A7B8FULL, 0x2CC129EF2EC193BDULL, 0xEE33C99980874A19ULL, 0x12593212318BDC85ULL, 
            0xC4B8F68B066E76B9ULL, 0x32F71339CD7E84E7ULL, 0x142C06E873041506ULL, 0xF099DA01B51C843FULL, 
            0xF6C75528981690E2ULL, 0x218FC5F6B9304AF5ULL, 0x8F261D13CD6BF361ULL, 0xBDDE84EA7960B758ULL, 
            0x62082B64F58617AEULL, 0x898E8B5FD1FC4048ULL, 0xCE39C750F71ACFCAULL, 0x56A85548B04905C2ULL, 
            0xC5F2BDCB5CF5E77CULL, 0xB9FDE8D0B15F334CULL, 0x58A4D597F54230CEULL, 0x321F09413FF3418DULL, 
            0xD6C29F77E547967EULL, 0x8F374A5F396EF76FULL, 0x755B3C2473611E72ULL, 0x7BC7181941EA9E0BULL
        },
        {
            0xEA8BE06049E0AF94ULL, 0x88CD4CF05252F974ULL, 0x937D0A6192E54AABULL, 0x345666D110488F62ULL, 
            0x63ACC006C80DAC0DULL, 0x93C884E83BA3C86AULL, 0x59BF9B97853D2680ULL, 0xAE32F8DBA7A37459ULL, 
            0x264564810A6E4F14ULL, 0xC9D8BDAE729DFB9DULL, 0xA2923982F5BECD50ULL, 0x281077625CE5BB4DULL, 
            0xB7B83A03BE91F0B1ULL, 0xF3F6CF72C988BC6FULL, 0xECECDE3A3788B500ULL, 0x6FE98EE0BCBB9074ULL, 
            0xB6A572495ACE3F8FULL, 0xCADB427ED71CB88EULL, 0x95D41B057F89F115ULL, 0xD3259AA12EBA3303ULL, 
            0xCD0C82A2E4277A85ULL, 0x13D2861104A328BDULL, 0x17FCBEA28CC3966BULL, 0x01983EC1B7B2C6B1ULL, 
            0x7A06E05C5127DBC7ULL, 0xB3FB45E4DF9684ABULL, 0x96A91C75A38D9834ULL, 0xEF4C1B0170B6063CULL, 
            0x7D55022F03FE05ACULL, 0xC76AF459297F1F8AULL, 0xA4ECAFAEADA9D08FULL, 0x6E590EA53DF106D1ULL
        },
        {
            0x40D176E5720FF200ULL, 0xE9F6BF0F46E81A15ULL, 0x8632A55070812D19ULL, 0xFBBD320841E74CF0ULL, 
            0xB415C29B1BD8CD5BULL, 0x6AC0336B4F7F5F25ULL, 0xF8F945DF4AC8BA4AULL, 0x9735B4FA20F8526EULL, 
            0xB37CCD75B8507FC2ULL, 0x3181F451B6F52BABULL, 0x48BEA191E6FA88C0ULL, 0x34F20E7889261F3CULL, 
            0x440FC15FE7E0FB53ULL, 0x8A6C8DF8B91E62B5ULL, 0xBF81C1037C21575FULL, 0xA722E9213E9A2267ULL, 
            0xB67EDCCAF1C65D94ULL, 0x44EC70A6218FA1A1ULL, 0xCA33DB7C8B2A88C7ULL, 0xC0FE151864E2AC27ULL, 
            0x8D9EDF7D8615D179ULL, 0x6A1A6BECA8F62967ULL, 0x84E7E1F9F5A96E9CULL, 0x2441B8A02E743117ULL, 
            0x45F7ADA763CD2253ULL, 0xD07DB3D28F8DE825ULL, 0xD832B6604BE84036ULL, 0xC926BACD631838FDULL, 
            0x90C9C9BE05F822D8ULL, 0xD5B9309B9A3A16BBULL, 0x3324FE423AE3ACC3ULL, 0x9B58D7B178006132ULL
        },
        {
            0x3068CEEB4C68FB89ULL, 0x75CEA9B98BA38CABULL, 0x6CC62AF8C25828C0ULL, 0x41537560C2184225ULL, 
            0x000B6975140E02A5ULL, 0x52B7D6CAA278B06AULL, 0xAE9CD4EC5CE0E210ULL, 0x41B2D9CF13E8E9CEULL, 
            0x626164B6DD74F65DULL, 0x8FE225659B7EE15CULL, 0xEE8BECB869923A43ULL, 0x8DC3734337517ACBULL, 
            0xE54F4E24FC3E9C16ULL, 0x7A5C4952B8DEFC04ULL, 0x1233F5CAC14D8069ULL, 0x35BAEB6C8FF48456ULL, 
            0x70E88A48A422AC97ULL, 0x4D5239014494B514ULL, 0x65A5A9F9065B39A5ULL, 0x28247064E68A8D46ULL, 
            0x94F2B5DF144F5D15ULL, 0x9DF555E84CAED86DULL, 0x3881827A29B11061ULL, 0xB039D33B4C46FA0BULL, 
            0xDF0A83F888FF98FBULL, 0x49CD4A375D4A015EULL, 0x4B1866C2B29DA056ULL, 0x0E4B4067671DA53AULL, 
            0x0AB4681100B5CDFCULL, 0xCA4CCDEC5D85470EULL, 0x6FEC4C1DCC036088ULL, 0xCF57EC3A629B82C9ULL
        },
        {
            0xC600ACB424CD52A5ULL, 0xE3EE56EFCCB81956ULL, 0xB67E8BFB9B411E54ULL, 0xB95EB73971B40081ULL, 
            0xBC452B4A91FFAA6EULL, 0x8301A4E4717A183CULL, 0xEA011E4E1C37CCE5ULL, 0x58DD348AA1690CF4ULL, 
            0x53D636573EF807EBULL, 0xF0205DB517153477ULL, 0xE0CABA91ED982708ULL, 0x09B36A01C14332BFULL, 
            0x1FEEBFBFEBE6C13AULL, 0x28AE7A56B9648882ULL, 0x280B3DAE22B905F4ULL, 0x68171C71082A7941ULL, 
            0x2FE6A77BA8D3AEBEULL, 0xDCF3FE1087849EA7ULL, 0x4126779CEF96EE52ULL, 0x34A0A66FBD5ADC71ULL, 
            0xB40E697D7E72DE57ULL, 0x6DEACCCCDBD0A523ULL, 0x910C9C1ED5A88E1BULL, 0xF2A34460E87ABAAAULL, 
            0x90E4921648B15876ULL, 0xC7383F6B7CE57EA2ULL, 0x36DF3E6586FD857BULL, 0xB58658EFC9A5A65EULL, 
            0x1F31FAE16A33036AULL, 0x048F58E92FA4B674ULL, 0xED488EE986876A45ULL, 0x06BFEA82BF662DE3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseFConstants = {
    0x82DD4C29CD3DA0E4ULL,
    0x04E36BA13AF6196CULL,
    0xABF06108DB89A55EULL,
    0x82DD4C29CD3DA0E4ULL,
    0x04E36BA13AF6196CULL,
    0xABF06108DB89A55EULL,
    0x3A16D92DD1EC75AEULL,
    0x9DF1FD7A44681EEFULL,
    0x45,
    0x10,
    0x9F,
    0x23,
    0xF5,
    0x4E,
    0x2F,
    0xBF
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseGSalts = {
    {
        {
            0x344C2A2B4D706D67ULL, 0xB18D9B476C08D71FULL, 0xD417BA2435DA7427ULL, 0x39245BFD7B3BD703ULL, 
            0xD679E0AD7543D348ULL, 0x35693F42DFC681ECULL, 0x34B57CDF3CB5DCDCULL, 0x1B4B406E8D34A495ULL, 
            0xD8D957591F66F09BULL, 0x6C38F6E1DBAA5856ULL, 0x378715D5C190F94CULL, 0x51DA36B11BD449FCULL, 
            0x4AD52D40C7666331ULL, 0xBACBFE8329E269F6ULL, 0xF4A4D50C508D4851ULL, 0x1A37F84343394930ULL, 
            0xC7BA1531A7CFF544ULL, 0x4E0AF6C1646083B7ULL, 0x2C466EB621108B45ULL, 0x075F3926D042679BULL, 
            0x05F89E2E7B8245F3ULL, 0xE4F45C8DF4CFCAE9ULL, 0xC18A4412606CE5D9ULL, 0xA489CB7251AFD1EAULL, 
            0x2374C89F19CE9E4CULL, 0x4CC35F4495983B84ULL, 0x4FA5E5EB6DF26E11ULL, 0xD7F1038AD6136C82ULL, 
            0xFEA15065092C77C6ULL, 0x9DE774F68FF279AEULL, 0x62AE941D6E8D8B18ULL, 0x531C954D88449A1CULL
        },
        {
            0x503D00CDBED6CD57ULL, 0x966D3B98B7CEBEA6ULL, 0xA7C8EEB78028DE09ULL, 0xD0F5440F5B14C790ULL, 
            0x64CB0B48D94534E8ULL, 0x85CB205ACF15CAC2ULL, 0xF69EB496292C7B23ULL, 0x7EF2A287A3E01270ULL, 
            0x158C608D85CE4928ULL, 0xAF015D4661CEA578ULL, 0x66152BA9079000C6ULL, 0x915A0A14162141F3ULL, 
            0x3887BE4901361697ULL, 0x1663E02EB6292872ULL, 0x1A465C25160318CBULL, 0x2D5B81CFC306AC9CULL, 
            0x95616C5DC22D8324ULL, 0xA9609F0594CA5879ULL, 0xD09790D56BA4C1C0ULL, 0x5CDB23A93D646A17ULL, 
            0xD3CE5E814BA4EAA3ULL, 0xB2A73B7A8B4D5014ULL, 0xD462A87CE32E2942ULL, 0x0EC0047120FBD7C1ULL, 
            0xDF68ABC496846BB1ULL, 0x1352D773A6E2A495ULL, 0xB9500E75DA616E2FULL, 0x28E073948F79F132ULL, 
            0x043654334D02ACC3ULL, 0x7C9A215814648591ULL, 0x67FE2FE2C89E0092ULL, 0x0AD06130AEC0BE8DULL
        },
        {
            0x29DA9EE1E3973E93ULL, 0x6E569C693DC435CBULL, 0x393320AB0CB97CD5ULL, 0xA80B6CB1DB4D4CB3ULL, 
            0x143270710D1A27DCULL, 0x69CA322666C85E1AULL, 0x46128C5219970F43ULL, 0x664352690467E732ULL, 
            0x0268B3D7D7CB6102ULL, 0xC349D4B0E15DA951ULL, 0x4435488E8CE76262ULL, 0xE0B65E929AEE7295ULL, 
            0x01090DDD887DDF6BULL, 0x21A9D26A6A941C92ULL, 0x4D5B7DF9854977B5ULL, 0xA544B52186AD2953ULL, 
            0x77FACF17B891530BULL, 0x4FA26BA9DDEDEF0EULL, 0x42DF893EAF8BA38CULL, 0xBF1F725008DB3679ULL, 
            0x77A9534DDFB923D8ULL, 0x2E290B1A3535F87CULL, 0x0BAC3508B7D5BB98ULL, 0x075DCC116C0EE790ULL, 
            0x2159819524F9FF00ULL, 0xDDEC36CF05CB3D6AULL, 0xFA8D4AE2CD482081ULL, 0xCF5C13710DB99846ULL, 
            0xE715A4BBDA984E9DULL, 0xE2585ED3108ED569ULL, 0xD89AF9398FE298B0ULL, 0x3BA6ECC44200D3F8ULL
        },
        {
            0x9872C2A9E9A042B4ULL, 0xB29F50CA2DF32FB0ULL, 0x0668E136E161322CULL, 0xD2521B5E36250A51ULL, 
            0xEFB3F8C00796EAD5ULL, 0x09C5E7ADD4EC54FFULL, 0xAFA352B87076E71DULL, 0x2A717D67B5294420ULL, 
            0xD313C9C95B7E7F97ULL, 0x1AA93985F71081E8ULL, 0x05777FDA5EBC6613ULL, 0xB2BE3B420C8D6185ULL, 
            0x21040DE02B7D8131ULL, 0xBE0629F15E01CA33ULL, 0xAE3D3E525C4DF44FULL, 0x5A547C083914B8A4ULL, 
            0x95119173DAF7A9A7ULL, 0x52FD51CE5568EB20ULL, 0xB5F3BF0F9C7AF849ULL, 0x5F9B5DD6B938E8E8ULL, 
            0x5CA390610E81BBA1ULL, 0xB23DA9E76136414FULL, 0xA88C5EB0534705DBULL, 0xF1DEAE03B5A4FE42ULL, 
            0xE899857E2DDDE80EULL, 0xA6B4550934417514ULL, 0xA19F0D6A97D13306ULL, 0xA4EDF7479930FACCULL, 
            0x384025AEE605BC55ULL, 0x224F954F7DBE9D74ULL, 0x2AB90A57508E0C7BULL, 0xD2EB79EC202883A3ULL
        },
        {
            0xEEC06570012EC3F6ULL, 0x7786455F6E60145CULL, 0x4E7C6A7771E7AF5FULL, 0x1608BAA9672EB34AULL, 
            0xE5B1DC507FC14D15ULL, 0x8E5E8DDC8CD72549ULL, 0x0CDA23A903AD32B6ULL, 0x6FE58FCBED0C67EEULL, 
            0x56653EA47C797D84ULL, 0xC5F1DEB4767280F0ULL, 0x203066DFBA099A15ULL, 0x6819EB8896AC7054ULL, 
            0x3AEC7AE5B839744CULL, 0xF9D2DDF552E18E44ULL, 0x0B3CE91A93D96DBFULL, 0x3D89E8CF3D15ABE6ULL, 
            0xD8E75F7E4A49C7BDULL, 0x4397033794CE5EF5ULL, 0x4B1AF62D22D3BBF7ULL, 0x050B15AACFF11813ULL, 
            0x20B16F949FAC3361ULL, 0x3329195210B566ADULL, 0xA5ABE2EA267CEB2DULL, 0x7A6A586ABCE7FD72ULL, 
            0x1C6A396E62EF0EABULL, 0xC034FAE651AF61D7ULL, 0xA0F7BDFB8A0F1601ULL, 0x5114622A2FDC8FEBULL, 
            0xEDF9ED84171F6B4CULL, 0x13779400E075A608ULL, 0x3EA438561D9045D5ULL, 0xDF85FE92C17D90FAULL
        },
        {
            0x219446139222E0CFULL, 0x0F26664327E391E3ULL, 0xD3558374211F700FULL, 0x55B738D4C589E45CULL, 
            0x03C21BDCB8E3124DULL, 0x823FE123EFA48C48ULL, 0xCB3180A669EFECD3ULL, 0x5EBA7EE6BF8BC0F5ULL, 
            0x62DC3EEDD6E1E2B9ULL, 0x57295C4144334010ULL, 0x23C605A458B57AC1ULL, 0x7009DBDCC7B3A114ULL, 
            0xCE70DA661D9986AAULL, 0x3D19EA2978E8D6EBULL, 0xC3BD29E914993C51ULL, 0x3014AF6110277EEBULL, 
            0xA3554F520A958C9FULL, 0x7F4D91287EBAB050ULL, 0x07E50C4A98A28F12ULL, 0xD23FEC48F3F1C30EULL, 
            0x0B8D8CE89C31EA88ULL, 0xA072F865F795DB36ULL, 0x81C5C71E6D7A7157ULL, 0x0D93FCEB450ADE46ULL, 
            0xCF0E8265B1D23359ULL, 0x0B0194B8F2057C6FULL, 0x5297DFAD164F41A8ULL, 0xC14690C85A64ECC5ULL, 
            0x523891588EA60CA8ULL, 0x50CB713BFD29FD90ULL, 0x3201BBD98ACC7080ULL, 0x72087690514C6C16ULL
        }
    },
    {
        {
            0xC315F6D0AB6697DEULL, 0x6470769FA6D4C045ULL, 0x9FA1084CE81F6492ULL, 0xA0A6778A20A04C86ULL, 
            0x90E49CC271B4E498ULL, 0x1477ADD79DC228F9ULL, 0x78B51AE506A0887BULL, 0x76F782CAC3B3E2DCULL, 
            0xFB83BCD20932EFBCULL, 0x0657E27B5150A779ULL, 0x2A3CE41ED436E1BFULL, 0x0F8996A9FB9026D1ULL, 
            0xBAB6533C8FA60537ULL, 0x1D4DF311CEF58CA1ULL, 0xED049A714AC2B4B4ULL, 0x9AA41F617C828ED0ULL, 
            0xBEA499F083D7414AULL, 0x937DBB20EB868D0DULL, 0xB3F825AC33A95375ULL, 0x74B933C0CEB25056ULL, 
            0xD69DD20A9BF57106ULL, 0xE44AB68387B987F7ULL, 0x631B14FA871A454EULL, 0xDFE68814F83B276CULL, 
            0x5BC64763ED5CEBF5ULL, 0xEA55CAAE1A382B52ULL, 0xE4C1E7301332AA76ULL, 0x363E6F9B4EB7C801ULL, 
            0xB651E2C316677571ULL, 0xB806737FCDEC4656ULL, 0x166CF0B54C853E6AULL, 0xAA123BCF11138DC1ULL
        },
        {
            0x0AB139C0979756D2ULL, 0x2A436B9C1DEDF702ULL, 0x7141C0CF5D1A8FEBULL, 0x3577B27A0CB9E81AULL, 
            0xB8321A903F6E11ABULL, 0xFD3B37B63FF0EADBULL, 0x95874C2262AE4738ULL, 0xA383CC8F086BE03BULL, 
            0xA45034EDE2370A7AULL, 0x385CB9E69A282C4CULL, 0x77DBBF7F9D1199ABULL, 0xD4A59E4C10834FEFULL, 
            0x2BB26156700BBBABULL, 0x03755EE101492F12ULL, 0xBDF9FA5730CA5848ULL, 0x6F706F18999B26B6ULL, 
            0x7E74F466571CB50AULL, 0x98CFEA180635A516ULL, 0x9332EDCC29B17920ULL, 0xD281A7BA98514EE6ULL, 
            0xB753756605F76B9FULL, 0xCCE976BD040FFF17ULL, 0x1ECF73C7EBC017F9ULL, 0x3A824CEC5A12073CULL, 
            0xD8151627AD49D642ULL, 0x9EE2B3D32D5BD186ULL, 0xE439F65CCF16D708ULL, 0xDEB26A840036B896ULL, 
            0xB1403D438C650580ULL, 0xA2C1D0D19994BDF6ULL, 0x2DE6135DAC3D1A9DULL, 0x84FBD0FEB3B459D1ULL
        },
        {
            0x3BE2AA9BDFAF495BULL, 0xB014640F2BE64610ULL, 0xAD65B52D6A85E8FBULL, 0x20EB744E8CA75FD3ULL, 
            0xB867BF46F79C44BEULL, 0x319C4DB4E8B742CEULL, 0x2D932FE8879A78D5ULL, 0x5EB9159844C76AF8ULL, 
            0x63BB98B79CD3EA98ULL, 0x6B5061589A685FCFULL, 0xD4865085833854FDULL, 0xA9F1757373128E0FULL, 
            0x3290FF5F472A513EULL, 0x9B0E658206DD4163ULL, 0x4F1348F2896B72D3ULL, 0x80B91405B29031E7ULL, 
            0xE61E239D8D00320CULL, 0x74C4AE884ECF58C1ULL, 0x0EB110BAB6B8C845ULL, 0xDB749763A2B3BC10ULL, 
            0x0D95A4DC601A22BEULL, 0xDF0A4B1E6448D703ULL, 0x2C9BE1BEF99D14E7ULL, 0xC590A64EE18F304BULL, 
            0x6C7592DF21A8E44EULL, 0x15802FFE7770ECB3ULL, 0xAB10EFED0BE99789ULL, 0xAA39C325225A1347ULL, 
            0x9B9491B1A41156C8ULL, 0x38A6947FB1ADBEACULL, 0xC73BDFDAF185C24BULL, 0xC002997FEFA233BDULL
        },
        {
            0x542B2EFBFA9CFF4EULL, 0x589E3FFE660D414EULL, 0xDB8A6F7E0705782FULL, 0xD01A4D3946D73C93ULL, 
            0x2C2B78E9C1989F25ULL, 0x832746F91C00024EULL, 0x7DA28B639B4D2C86ULL, 0x55158436E1DF9604ULL, 
            0x50CB904882F67CD9ULL, 0xE756FAFACC8148FCULL, 0x59B31B7E616B02D5ULL, 0x4348ED16D205698AULL, 
            0x3788933CDAEC4152ULL, 0x2FD0410EED6784DCULL, 0x35913A3E5FE7D152ULL, 0xACCAF6C3D62151EAULL, 
            0x7EE3A7F143ABA516ULL, 0x79846588F4EF1270ULL, 0x30C9DF5BD5D7E977ULL, 0x7669289431F9C4E8ULL, 
            0xFF0D8E0F6E7A632EULL, 0xEDD0530A25185DC1ULL, 0xC503F0E0B3BEB2BEULL, 0x8BE6870A032170D0ULL, 
            0x9EE888FAA66C2440ULL, 0x723D8C6A5053B940ULL, 0x51CC8EBD35D5BAF8ULL, 0x0AAB9AC32E7F1674ULL, 
            0x09DC4D89B9A350B4ULL, 0x9230C02BB964DE16ULL, 0xBF2547A23EC7C0DFULL, 0xF330CC1849DD7F8AULL
        },
        {
            0x5E4923344DC4EF96ULL, 0xD7CDABF1BF1E4771ULL, 0xB415086C87A15811ULL, 0x3A0E6EF2606F671BULL, 
            0x6812BA3134DD0945ULL, 0x74F6629F4942B5A1ULL, 0x826F3091529D929DULL, 0xDA84EFD00F824357ULL, 
            0xC8EB1856B4A536CAULL, 0xA4A28EEC7C69954BULL, 0xF28F03351B7C58CFULL, 0x38B8AD6AAC11F7C6ULL, 
            0x6F26F501234BAC0DULL, 0x621CACC7FF6807CBULL, 0x06BF061B56A9E2B8ULL, 0xBDC2A6666B36E679ULL, 
            0x9F697A16A5BFDC62ULL, 0x918F090D16D8E312ULL, 0xA7B9B1251BD5F2BDULL, 0x62168152480F5E8EULL, 
            0xCB8689608793B4A2ULL, 0x5124901CA992F72CULL, 0x1A0445ACE8A85D84ULL, 0x08F6960A5621BDD3ULL, 
            0x7AB32538C1D682D8ULL, 0xB3BEDD0949994426ULL, 0xE398E40D4879FBF7ULL, 0x40E0CB1ED7A58C67ULL, 
            0xD9FC8C8D5CC29E61ULL, 0xDABB4A0A718C1944ULL, 0x56AC0E013FD79449ULL, 0x88B43353BA164970ULL
        },
        {
            0x55AD275298B03799ULL, 0x125F06C0ECD4A7BEULL, 0xB6F97E2699C25DE7ULL, 0x189ACC51A6E7DBCBULL, 
            0x48000B67C6BF8AEFULL, 0x80DD15C80633CC6DULL, 0x01B6A2EF30B789A5ULL, 0x87D8987AA619477BULL, 
            0xFC5530382731D15DULL, 0x4A8D67889BD56165ULL, 0xA1CF8DD8054CF51EULL, 0xE5A7FD1A8930A428ULL, 
            0x8304F30107ABF93EULL, 0x7F0B930DECD99653ULL, 0x06C2ED4648C2670AULL, 0x903720D4619B5093ULL, 
            0x43148DEAE81B2BB1ULL, 0x5AA0D29FB6E09598ULL, 0xD79F7E305DA7DCDDULL, 0xC6796B45F6699119ULL, 
            0x4F34BE6C1FB4245CULL, 0xE15E00638EBA72BEULL, 0xF027A945266E8A40ULL, 0x26AB7A71A7E43DE5ULL, 
            0xBBC513440D58EDDAULL, 0x020DC194D48FC68DULL, 0x514E7B169FF8700FULL, 0x234E92B245D68C42ULL, 
            0x0E302897D55D41EFULL, 0xEC66BA2DEE665910ULL, 0xD10EAA2A991D04A7ULL, 0x53D06598D7FEFC0AULL
        }
    },
    {
        {
            0xA9E76F67F8A73B06ULL, 0xE9A23E213C7E5BBDULL, 0xE2CE82644A1AEA6EULL, 0x0A4AAE789627F827ULL, 
            0x00E96317852B975DULL, 0xE9FF2D6D5DD4B6BDULL, 0xCF889C9BA8E84EA5ULL, 0xA187B31B9728FCB1ULL, 
            0xBBA0ABCE122B4DEBULL, 0x4B9F84226839AA7DULL, 0xBEDBBE07766924A9ULL, 0xF1A9EDCAB7BD40E8ULL, 
            0x881308F20740E006ULL, 0x2DF97EDAC4A5E297ULL, 0xC7DC00AE49BF96B5ULL, 0x8B58FCF72974C709ULL, 
            0xDE14FA63BA3C5039ULL, 0x8F989EA664FA1D10ULL, 0xB9BF79A15FDABBB1ULL, 0x4EAE2E0D95F640F5ULL, 
            0x8CC431C0B2E2F088ULL, 0xD4FE36999FE64BE0ULL, 0x76D0B1341D0DA5B3ULL, 0x859304E20D5A6FC4ULL, 
            0x3AD67A6F683AA5E4ULL, 0x663856AADAB10DF6ULL, 0x4D7D680E8C2C3A52ULL, 0xB2D2CEB82B921D65ULL, 
            0x0AF6EFE447B53B64ULL, 0xF340808BEE3A8A86ULL, 0x4C0ABCB795C2FC66ULL, 0xDBF3F596A7AA6C4EULL
        },
        {
            0xE7F31EF0160E828CULL, 0xB2CE71EDB3B8CA23ULL, 0x843C7B19AE7F5FCCULL, 0xFC120764BE64473EULL, 
            0x1D134A9F0D6E2DC4ULL, 0xD98A876FC2975AD0ULL, 0x4FA865A8C6C916FAULL, 0x69B5FB227EC55A84ULL, 
            0x00E2A95987E10994ULL, 0x1BF49CAB23F9E865ULL, 0x4FEF99C56D3D69A5ULL, 0xD06488F876C72CA8ULL, 
            0x50DC6567C7C65218ULL, 0xE5E1CEC3DA7F4849ULL, 0xCD2B25F9995F038AULL, 0x9B098B8F220B6C35ULL, 
            0xD921612C1AF4B021ULL, 0xBF6784AE45FCEB53ULL, 0x6A8F28101BF8E817ULL, 0x08385E268F51FC3CULL, 
            0x126EEB694A1C7C7BULL, 0x2DD71A2275EC9FCEULL, 0xCB0C3D2882F00F33ULL, 0xDEB934F4F16250FDULL, 
            0x4E9D6DE9589913AAULL, 0x82E72B4270867947ULL, 0xBB3178A572048254ULL, 0x1E3DC8CA6D7C708BULL, 
            0x77FCA2AFF3CE0FF6ULL, 0xD3D0C67A824434C1ULL, 0xA126CC332F348159ULL, 0xE86074CA29D81058ULL
        },
        {
            0x41C0BB604AA701A9ULL, 0xDD610EB79EE3F336ULL, 0x4BF850197F9C58F2ULL, 0x8347A2EA6A0677DDULL, 
            0x496B9F9BC4E7C3E9ULL, 0xEF48627806DDA160ULL, 0xFF351CE7C5695019ULL, 0x2A1E5E79889EFDEEULL, 
            0x58516CFE2CBE5788ULL, 0x0B66EF8BB1650140ULL, 0x598D8D85BE11B159ULL, 0xB9FE0FB80A6EBDEDULL, 
            0x4038BCDF475A4EC3ULL, 0x3DA9B3DC391DFE94ULL, 0xCAF83450FF522C53ULL, 0x32F9D5AD50992268ULL, 
            0xE024A602CA02925DULL, 0x1A8BEBF1DED17C21ULL, 0x7EC19BF170F88BB7ULL, 0x2354BBE38F4942CAULL, 
            0xD04779EECD7077C9ULL, 0x01F312D09B0B01AEULL, 0x54B212D1DECEFA10ULL, 0x863540FC5BC82A84ULL, 
            0x4C0B49C29672A8CAULL, 0x506929616D061CE5ULL, 0xF114BA0362798D81ULL, 0xFC35522095316B49ULL, 
            0xB9EEE937C3A934C4ULL, 0xD1D1B0DF48CAD1C5ULL, 0xC5FC33F79762425CULL, 0x8CE458568088CFCCULL
        },
        {
            0xD6C911BAC224809BULL, 0x5E7076F92F6A1B73ULL, 0x8D748146E19BC470ULL, 0x18A73C371740417CULL, 
            0x976AF4A6B94CE227ULL, 0x1340A3309651F765ULL, 0x82A3E9654C9A5E54ULL, 0xF73A50F1546C9198ULL, 
            0x68628E6656863B9AULL, 0xB10A71A7C7DB1ED8ULL, 0xD163621913D0DBBAULL, 0x336775FA77A22A4CULL, 
            0x6D45CE1985F2FB8CULL, 0xC99EB82CAB1725D2ULL, 0xE7787622EE0C5665ULL, 0x75C9BB031ACD0146ULL, 
            0x9F6B7663551FEAA1ULL, 0xF790D16C6A031A56ULL, 0xBC07F55F19A6A7C8ULL, 0x790FBBC44C51F86FULL, 
            0xBD137943882FD5B2ULL, 0x1BAF3D79F3B6A262ULL, 0x5CD38B57A97FEB98ULL, 0x7F0E27A62E14EE24ULL, 
            0x295A8C0A03FF01A7ULL, 0xE36A6082FE955642ULL, 0xE5357D285410CF18ULL, 0x43CE18885229A00EULL, 
            0xCC0EFEAAFC434E10ULL, 0x40E85607CA718D4DULL, 0xB64509283924FC7EULL, 0xD183A57AEFA3F05DULL
        },
        {
            0x6C6565503DB2AC99ULL, 0x834EB23044018A64ULL, 0xD8E515FA08A0840EULL, 0x1663CF79BFD39005ULL, 
            0xA879E683910F6A36ULL, 0x3DF89DEEE885C657ULL, 0x20E45C8EAEDBBEAFULL, 0xDC9E82BEB1761BE1ULL, 
            0xE1DDA92EF0DB8C32ULL, 0x98A0E4A080195B90ULL, 0x1870ADF079A77A51ULL, 0xB85B212AEDC028EEULL, 
            0xA2C9290056B14740ULL, 0x38497EED5D4F0CDBULL, 0xAAECDBCA7C067138ULL, 0xB4C92C2C3C81CF3CULL, 
            0x0D209246B9D167D9ULL, 0xE22B58E502B8F029ULL, 0x9CD93859CE13C7D9ULL, 0x5CDAABC77DF62D58ULL, 
            0xBBEC43F07F33286FULL, 0xE1F43D60B4F96BE9ULL, 0x51495881E1196606ULL, 0x6DC0F5341E769BFBULL, 
            0x8E48F492C8DEC026ULL, 0xD49CE823FF4333D8ULL, 0x84C0705F59CD92EDULL, 0x8D16C3EECD6E2730ULL, 
            0x3C432789C1C6EAF9ULL, 0x91EA18A253007C91ULL, 0xB51CCEDA9B9B9513ULL, 0x6B9A8607EBD46AA2ULL
        },
        {
            0x5BDEE509571B25B2ULL, 0x979463FB17BF6657ULL, 0xE8D3EEA03ADA7DDEULL, 0x0BD9B780EB6BA9E6ULL, 
            0x1B82BF222C865C1CULL, 0x8DA3201F3F96939AULL, 0xCDE139A013F69DEDULL, 0x76D37C93E76D01C7ULL, 
            0x641891A6B52EC20CULL, 0x3D626372AC02FF60ULL, 0x4759A5F0457FB848ULL, 0x5DCBDD27FEC9D336ULL, 
            0x980D749B47E8C665ULL, 0xFA0E725DEAC1A2D4ULL, 0xC8F4F9727EAE56C4ULL, 0x6831F189019EFD97ULL, 
            0xEA6C5AA2EAE27C3CULL, 0x737F49FBFAA8A3C3ULL, 0xF1D4CD330732BC39ULL, 0x0D048917CB6F2779ULL, 
            0xA42E478AEB754EFAULL, 0xCB06070BE2C7B96CULL, 0x80A7A975D0D2B609ULL, 0x74B8362FF0552A60ULL, 
            0x4ECFDCE036A26B8EULL, 0xA9B70DBCA25D0F0DULL, 0x680E220CD52A8722ULL, 0xE4A15CD26F136B60ULL, 
            0xFE332AF609168470ULL, 0x54BADA72AE172ED8ULL, 0xD74C88E862DE7365ULL, 0x3C3C11613CA2F269ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseGConstants = {
    0xCDE3772DB43ED21FULL,
    0x0AD518EF632C9C14ULL,
    0x14DD69E668362542ULL,
    0xCDE3772DB43ED21FULL,
    0x0AD518EF632C9C14ULL,
    0x14DD69E668362542ULL,
    0xC304507F90B24A71ULL,
    0x54097CF4FF758511ULL,
    0xE3,
    0x24,
    0xFB,
    0x4F,
    0x6F,
    0x18,
    0x78,
    0x57
};

const TwistDomainSaltSet TwistExpander_Tennis::kPhaseHSalts = {
    {
        {
            0xE290DD217C17F3D1ULL, 0x5E30ECF95A11B8C0ULL, 0xD4D9A77BA70E0A27ULL, 0x110C773BE7E3F58CULL, 
            0x0D91BE4018E67CD4ULL, 0xDC7E7315CC527AC1ULL, 0x6C935F399CFA7CCAULL, 0x58BA44663ECD40F6ULL, 
            0x3D76E70610A00BF0ULL, 0x18266E3820218AD8ULL, 0xB37E16AAF78A25BEULL, 0x91B4C1E2DB99F8D5ULL, 
            0xEBF85B7860C9A477ULL, 0xF2A94FAC5F42B65AULL, 0xAF8D2C2FA6445210ULL, 0xDEAD9D7894F6E276ULL, 
            0xB27CCA5F05A7E4CAULL, 0x674952959DBDE977ULL, 0xFE77A03F9FC66E04ULL, 0x39CEB385D8734102ULL, 
            0x23BA732261B867AAULL, 0x3C832990A005F762ULL, 0x14C83C68ACDD86F6ULL, 0xFF5E04BEB5866407ULL, 
            0x7F9BE8AFF4AB12F1ULL, 0xE9B2B52469DDA718ULL, 0x29CB5874CAEB4793ULL, 0x8ABA62CAC16C28DDULL, 
            0xF99AD519749EAC2CULL, 0xB7AB379484F57F13ULL, 0x6307F2B353E56C10ULL, 0x9FB20456A2EA6B89ULL
        },
        {
            0xB57D635C640A1624ULL, 0x158E453B5B945F6FULL, 0x9FA86430CEA744AFULL, 0xB46A98522EAC5659ULL, 
            0x607FF88C1D991D87ULL, 0x655203325D8587DCULL, 0x8F4BC57D3797D8ECULL, 0x4FFBC8D18023E2C2ULL, 
            0x4418C5101B682C23ULL, 0xB38FFDE6D5D8F5AAULL, 0x07753B350315B868ULL, 0x0618E7E20FE6A8C2ULL, 
            0x6E26B45D52055E0FULL, 0xB843D4CE5444A01DULL, 0x36E8BA7A2F151A35ULL, 0x0913BE7237021F2EULL, 
            0xDE9941005977B45FULL, 0x2A7AE81FEBF3B2E7ULL, 0xB82B6F2351095C71ULL, 0xA62C602E50EB7D46ULL, 
            0xEC8831B5F8F89FA6ULL, 0x68E9DAE0875FD769ULL, 0x7B30FF32333B7553ULL, 0x42561ADDD45CDC79ULL, 
            0x564CDEC256172D73ULL, 0x7CC4DC8914B34EB0ULL, 0x023026230832D9BBULL, 0xE083F41F21CF17F1ULL, 
            0x428E46C586D437C5ULL, 0x80565A1DCC2308B7ULL, 0x479A8949A29E8A23ULL, 0x5640AA7711B0FDC0ULL
        },
        {
            0x46607036AA07F587ULL, 0x3F6B1209B67E36A8ULL, 0xCAF20AE5ACE63B0FULL, 0xE24F5C10734947F2ULL, 
            0x1D7A1A47F1F7DE7FULL, 0x9B5944B4F09DB52BULL, 0xE44D23B9786DE557ULL, 0x4DBCB4035800880AULL, 
            0x5B833BEC59BB6B2EULL, 0xC45E761AB58C8732ULL, 0x8D4ACE2D0BE8E964ULL, 0xCED00579C3746132ULL, 
            0x8FF60062A9DFBA8BULL, 0x0D9280B5F344596DULL, 0xB782D8F51C0195BAULL, 0x02A191F946DF4534ULL, 
            0x15F773F6C08D8087ULL, 0x5CDE363234C430E1ULL, 0x5793DDB95F29130BULL, 0x844CC7E2455B562EULL, 
            0x884E079CEF002BE7ULL, 0xB4984E48825F747DULL, 0xEFB1B43DDFFD24A7ULL, 0x3BC4636FD8391C9BULL, 
            0x25CC3B903519A540ULL, 0xDADB521ED17CC0E8ULL, 0xB0B1D44EC64FF8FCULL, 0x55F5DA3EBAF0CC10ULL, 
            0x580C5E6FFD445470ULL, 0x713776DF941A0CCBULL, 0x04925565030CAD67ULL, 0x5D3B55E35904230AULL
        },
        {
            0x59C520F05FC9CDE4ULL, 0x5B8AD02A4172C858ULL, 0xBD5D443D71A1FD50ULL, 0x2260B73E9102D6E8ULL, 
            0x21A36810C5D3ABC2ULL, 0x5A371DC608BC1D27ULL, 0x50BC432D028D8772ULL, 0x9477D7E136941E1CULL, 
            0xEB860B89F4E739A5ULL, 0x57BAE84BCE8884C4ULL, 0xE701FD5630C8CFC4ULL, 0xACFFCA8691CDA8FCULL, 
            0x8CB87C0B3B2E060FULL, 0x40C0D0E33CDF0AFAULL, 0x5BDD7BC828371A99ULL, 0xAF4105A284BF34A6ULL, 
            0x364626A6BCF5D45BULL, 0x58940692FEBD333DULL, 0x0438DA5AFF2CB37AULL, 0xEACD6EAFFA6F1D99ULL, 
            0x11A912F5BA4676FDULL, 0xD5F1531D17B8AF70ULL, 0x272524DF7FC18398ULL, 0x52D3D99260CD4B97ULL, 
            0xEB3352CDDF3C10BEULL, 0xFCC14EB4DD85FC39ULL, 0xF7A5E4CC549C30D0ULL, 0x3FC4EC62185089F9ULL, 
            0x9C3764A020D60802ULL, 0x114100FD38FFDD12ULL, 0x5892C1E22DC3C8C3ULL, 0xFE8A28D40AAF1A13ULL
        },
        {
            0xF111B677BA525F47ULL, 0x8AD153893F356298ULL, 0x625F312945B871DEULL, 0xC56F2D015C6EC421ULL, 
            0x4220FAACFA13E4D0ULL, 0x3A04CF1D72E9CE39ULL, 0x20A9260DF1F011B2ULL, 0x0371C4224E5BB894ULL, 
            0x621C7B50E211D5EBULL, 0xFCBB0805D30E1829ULL, 0x8381D550E9F74578ULL, 0x192CB8F4D9BB3A2DULL, 
            0x0415E0E40ECD17A5ULL, 0xD31149605591584BULL, 0xF65B396976B48167ULL, 0x50EE3693BE19387CULL, 
            0x01B6FBFDF0C3F605ULL, 0x5B36CB534193FF11ULL, 0x5F0F9EA36666B9ECULL, 0x187283E20615410BULL, 
            0xFEBEBF986902AD3EULL, 0x8D9455754D7BD53DULL, 0x61F44A9881078297ULL, 0x9F4C26F593B3A1D3ULL, 
            0x96F357174CA49887ULL, 0x8B47A48CA37F7140ULL, 0xDB3B5D8E0377A2A6ULL, 0x45CE412B285CBEE7ULL, 
            0x7BDE818875B5E614ULL, 0x738D18F72685A496ULL, 0x584CD3838A3AF2DEULL, 0x4D0EEB60AED17ACFULL
        },
        {
            0xD32E6A71A3AC1DFAULL, 0x1BBDA45DD70E607BULL, 0x30027F4C35E3C8A8ULL, 0x586D782B77B7FD60ULL, 
            0x2C6D5C57ADF9B681ULL, 0xC8A58BB849592191ULL, 0xE9BC2D737BBAEF7EULL, 0x3258EA35437D5D09ULL, 
            0x0D75CE93D936C9D5ULL, 0xD89F1DA993359B6CULL, 0x157A25E60434FD8AULL, 0x48FF6AA0C3F115AEULL, 
            0x1497FAAAE894433FULL, 0xD2429934EF5F9A4BULL, 0x86F4801B152ECFFBULL, 0xFC98AC8DF44E22DDULL, 
            0xF06FB8E5B72C5173ULL, 0x7702DB4B1CE2B2B9ULL, 0x319C48B39A008F54ULL, 0xBB122C9B9E630CFFULL, 
            0x7494D6156876EA26ULL, 0xA0B55E33030C8149ULL, 0xC365792442554C13ULL, 0xB20658A72EC37AD6ULL, 
            0xB4EF17304945502CULL, 0x4D4277A81983B1E0ULL, 0x1E2FC6C7A5E15D07ULL, 0x3E83B4C1E9FED0FBULL, 
            0x086C8B353F5718A8ULL, 0xACCCB70C65FE5DA9ULL, 0x49E31A532B5EC493ULL, 0xCAD88FE536644908ULL
        }
    },
    {
        {
            0x3451EE520771AAC6ULL, 0x0A4C630AB6653BBCULL, 0x93A7C8BA117955C3ULL, 0x8A3C0CC6702F2D20ULL, 
            0x0FD80C739CC01EB4ULL, 0x1B2EAB45C0EA9FD0ULL, 0x82A2B1DA44A16E31ULL, 0xFC4AE9255EC0C970ULL, 
            0x7FA2181CFD420FCCULL, 0xA4F4DFD0F0D5E3C6ULL, 0xCA398454A83F1EA9ULL, 0x0DC5997E7BEB68A5ULL, 
            0x05E4C29B05E5494CULL, 0x95D348FFFAC1C9B3ULL, 0x290C0B12960B85D5ULL, 0xFD69D88857896499ULL, 
            0x2C69AFB7A9531EA8ULL, 0xFD3E056C8883BE8DULL, 0x0DD64CB40EF81345ULL, 0x6CC521582EB1A731ULL, 
            0x59AA7530F52390FFULL, 0xAD171243E44DA3E4ULL, 0xD97FA1C643B2B74AULL, 0x3CD7AA3584582C16ULL, 
            0x357731101F80A809ULL, 0xB8DAD635381A0329ULL, 0x38FF3C8C8C08F741ULL, 0x1C75E614522967B2ULL, 
            0x38E42B2A5D7FDCC2ULL, 0x21CD15042C65C657ULL, 0xC49F891C764A6594ULL, 0x9733419366D27390ULL
        },
        {
            0x2C3EB8C5AF4F599CULL, 0x7EB7EA3BABE99801ULL, 0x4EB21D7949438E2BULL, 0x0C81A41ECA344980ULL, 
            0xA3BC2092CC078026ULL, 0x77CB18697F74D80CULL, 0x062AD8BF1BDD6D08ULL, 0x68B74E04FAA485B2ULL, 
            0x7612C0DB5734D8C8ULL, 0xBCD1A54AD2F14385ULL, 0x2058C6F542B8F362ULL, 0xB2A0FB128CF4158DULL, 
            0x0320C446965ED8A0ULL, 0x1CCDD32EB7AE6074ULL, 0x67C1C4980E995747ULL, 0x18E9B41C83DF328FULL, 
            0x22D67E0A160FEE4BULL, 0xC59899DAA4546509ULL, 0x69A249A1FD3752C6ULL, 0x7FEF0A9A2A91865FULL, 
            0xD693795F7CB30FCCULL, 0xE519C039138FA241ULL, 0x8277644C3F4CC770ULL, 0xF080E0E518AA5476ULL, 
            0xBBBD8050A5EE2832ULL, 0xE8B4FD48999B0B7DULL, 0x66B88BFB9B908F38ULL, 0x9A94507EAE2292F4ULL, 
            0xF3BD2B423890A7FFULL, 0x0C7F7CA18616D231ULL, 0xD7D9FE9016DE239CULL, 0x37F5FBAEEC989DDAULL
        },
        {
            0x146F9B48D271AC43ULL, 0x8E35E461257AA664ULL, 0xC0080BB9ED4AA7CAULL, 0x05E27F9F0EB80E22ULL, 
            0xB9B7AB3276944A55ULL, 0x68F47316A834764DULL, 0x079298EE7116C95DULL, 0xC524FA9DC93BF06DULL, 
            0x35D9C63B3C7DFC71ULL, 0xD364CF74D479C283ULL, 0x5B4A5CB8AE47C9C4ULL, 0x95833446E161F1D5ULL, 
            0x529812018BB8C821ULL, 0x60A17AD180E47ACEULL, 0x8F1D32B10CACEA28ULL, 0x99340565B40F4591ULL, 
            0xD0C89DCC6F705BC4ULL, 0xD462533F3D452319ULL, 0xBE0DBD537846FB15ULL, 0x327B55C433FACDEFULL, 
            0xAB7658C8E6010710ULL, 0xE5734211F3FB9811ULL, 0x38651F362A23F820ULL, 0x089EFE3DE27F29D6ULL, 
            0xA8E5012CD9D4C3E2ULL, 0x70D7493DFD4EA284ULL, 0x9960EA14CA9C924CULL, 0xADBE8AB655965B87ULL, 
            0xE718802CD2DB7728ULL, 0x21EDD16A2805892CULL, 0xE69579BDC0912B55ULL, 0x5D47126D4760F697ULL
        },
        {
            0x637AFE3605A5025FULL, 0xB2629DCFBEA86BAFULL, 0x050E9FD28EE1AF94ULL, 0x6E063B5FC6DD6453ULL, 
            0x49CAC0CF24433188ULL, 0x51727057FEFD0603ULL, 0x35CF36DD2AB33520ULL, 0x34A0BD6B30E722B9ULL, 
            0xEFB84431C94215DDULL, 0xA5FB070DC210E1B8ULL, 0x2C431152DB756AD1ULL, 0x1878E751FE180F9DULL, 
            0x1C71EDA99ECCDE77ULL, 0xB83A462E1284A0EBULL, 0x571B9B21E29F9EE9ULL, 0xB0A1D143DF30816CULL, 
            0xA82E54F213A3FA36ULL, 0x16EA62882ACB7747ULL, 0x4627E16B83EADB3CULL, 0xDCE16AE2DDE748D7ULL, 
            0x6773822EA8B78778ULL, 0x8244628A700CA7BDULL, 0x134C4688B3A28946ULL, 0x85928C36AF7BAE24ULL, 
            0x93BA37A7C3903438ULL, 0x682DF635535C3678ULL, 0x59EFE18D53E341BDULL, 0x2C2C8F5A20866FEFULL, 
            0x31265B022FCCB2C4ULL, 0x246283D320E686C3ULL, 0xFA8F353013BE223FULL, 0x32D2B265A6629087ULL
        },
        {
            0x9FC3ABE4E7BFDBD9ULL, 0x3F44F6BBD15E5171ULL, 0x69319EBEB166CC47ULL, 0x8013C6C2BAC82F85ULL, 
            0x0A4E641FC26808EEULL, 0x5AD01D54519F3B28ULL, 0xAC447E7F4001145BULL, 0x46BF203D48B5A4E7ULL, 
            0x647E55DE683FE01AULL, 0x04443E2F41AE07BAULL, 0x9095C420D333074FULL, 0x1C06C5CBA1B2B395ULL, 
            0x9779DA45DDDE4D1DULL, 0x40AC839600CF61DFULL, 0x8BD0588E8C5C4CD4ULL, 0xF668459B1704B614ULL, 
            0x0A7F0D55EE3E9A71ULL, 0x95265D47CE420E02ULL, 0x76378C57DC3CC6DAULL, 0xF6F41372CDFF2FF3ULL, 
            0xA2FBE1DC48980CF0ULL, 0xA1157EE9FB4C0571ULL, 0xD0F500B9EFA5EF3DULL, 0x08DA015C096A5F67ULL, 
            0xA623F3546E159ACCULL, 0x61F68C3639A2F98FULL, 0x6D41C2216C594DA9ULL, 0xBDA165DE2A35E9F7ULL, 
            0x56F419EB06E18B6DULL, 0x7F9D4B30E572AE97ULL, 0xA62F0341C59B0413ULL, 0xFA030C0F2D5D7E6FULL
        },
        {
            0x5B4835AFB665DAB7ULL, 0xE67E3B0D99884788ULL, 0x8B1A77C4028AE933ULL, 0xE422DB790E6BAA85ULL, 
            0xE38E8098E939175AULL, 0xA8976C9D0A0821B2ULL, 0x4DA6E071356AF04CULL, 0x104F64AB056D75C9ULL, 
            0x9FC0FB30AB3F70C3ULL, 0x179310824089B339ULL, 0x869844463DD643B4ULL, 0x60A0FEF06F3B8EE8ULL, 
            0x97C20F805C1740EDULL, 0x37A2E334BD5B8ADDULL, 0x887825095EB7BB04ULL, 0x5D5FAFD6E5DBDC76ULL, 
            0x56D3B07F601E7381ULL, 0x3A3D885AFE2FEB36ULL, 0xA1A8D7743E00DF5EULL, 0x1D794AD956B78DBBULL, 
            0x55B1469B53888221ULL, 0x4A8B1FB42EBA3DC8ULL, 0x59A1F9B4D28C5E56ULL, 0xFD55AE48B76B76B3ULL, 
            0x431EDAC3BB688B05ULL, 0xB82833A8CAFE6560ULL, 0x43F7912F5E5BE58BULL, 0x0FFEB0445F71F393ULL, 
            0x4376F603637A64C2ULL, 0xC8BD92FCECBE9E02ULL, 0xE646A8F7AFD999DEULL, 0x4F6010704D9750BEULL
        }
    },
    {
        {
            0x187F09872EA82BEFULL, 0x907B33D7E739C38BULL, 0x1FF2C66EF7CCD95FULL, 0x3FCF86D6E57C0AD6ULL, 
            0x64D7D03D5CA0B2C0ULL, 0x1ECFD3A09CD4979FULL, 0x565061CE08038F95ULL, 0xBF0E01C84FDE222BULL, 
            0x24ACF0230B05681EULL, 0x0163F17F87EBD875ULL, 0xA03EB8A9CEEE11A9ULL, 0xC5838B5EA6C732C0ULL, 
            0x7CFEEE8568182ADFULL, 0xB2055AB849609A98ULL, 0x9CECE3A0BAD8260AULL, 0xC6102E1F744FC25CULL, 
            0x55349B6D5D2B863EULL, 0xA479E7E4F8E20F14ULL, 0xA3B2199A9665940EULL, 0x6C12CC8792F0401AULL, 
            0xB13240130B5279EBULL, 0x25BED45BD2B4124DULL, 0x979B8AF9D23FAFCBULL, 0x4EB75CA82ADDBB78ULL, 
            0x068EA19E23F79FA8ULL, 0x80151C34041F4365ULL, 0x6153311C0070ACCAULL, 0x880C0CA308F52930ULL, 
            0x2E5E745F4F513D2BULL, 0x9E02AC6696A5CA12ULL, 0x0D24C8CAE8A3BFD3ULL, 0xCA840935D824585EULL
        },
        {
            0x971E7097E4C322A6ULL, 0xD9BA5ED7A5C55D05ULL, 0xBFCACF4A7D171C7FULL, 0x1741453C59AA1F63ULL, 
            0x6A672F69581B4B54ULL, 0xD25610C2FCF81DF0ULL, 0xA8A9AFD85CC5C5DCULL, 0xB9357405D141F759ULL, 
            0x1A10C4EDCF41DEC1ULL, 0x411667350C5AC3A2ULL, 0x9E53B78F933DD006ULL, 0xCFABCA58E601F084ULL, 
            0xC717858AB916D547ULL, 0x4987AAA064E939CBULL, 0xADF60F37778134C1ULL, 0xE455F5E8EE2059A0ULL, 
            0x5CEFAD6F36E8BB6BULL, 0x46C3DED48306EFCFULL, 0x99797B56E4B886D6ULL, 0x8DDD6487EF1169EAULL, 
            0x05235573B026DCFAULL, 0x551F8C42C486E4EDULL, 0x8D293186023EB09DULL, 0x16C14A3357B27AE2ULL, 
            0xC8B9179A1BDF6E02ULL, 0x378847E64362401BULL, 0xFCFFD10413F6B606ULL, 0x54A79B5BE817724BULL, 
            0x38152E9729D0C8CBULL, 0xA1FE6EC254CBFC5CULL, 0x178E45DECF5FAB16ULL, 0xBC463AA446D9E703ULL
        },
        {
            0x36E9499BC0B3F0BEULL, 0xC4214DA1C836A724ULL, 0x1E7E78A0FA2197E6ULL, 0xC4F8CB91173A6A5EULL, 
            0x0E390CE837A7C0B9ULL, 0xDE939AB1AA65FD12ULL, 0x259C7CD79787858AULL, 0xC9A4AA7B8D743648ULL, 
            0x7A295846A9070E7EULL, 0xB4A54B45B06D056CULL, 0x9625B26D5645D80DULL, 0xFC93B59EB903E1BFULL, 
            0x5999DB2F74FCB980ULL, 0x16064E43AEB73464ULL, 0xEDE22BF9940EEFF0ULL, 0xE840D2833339660FULL, 
            0x61E22E176B23FD8CULL, 0x587A5B0675D00879ULL, 0x9DA2F2B3088E287AULL, 0xDB9B357875D66631ULL, 
            0x417A1A3A9F60D908ULL, 0x080B44D85C9557B2ULL, 0xA815B2988D7B50FFULL, 0x368B6E8361A168C9ULL, 
            0x3E1E4026CF7A0BD7ULL, 0xCF7FEC812D54B29AULL, 0xB3A86BF06ED339A6ULL, 0x6E22419421F8391CULL, 
            0xAEEEA3A044A315D5ULL, 0x612A4B0F96F5FA18ULL, 0xA11B79BB303C9563ULL, 0xE62AB336905B6AC8ULL
        },
        {
            0xFB82B3D805CB0DE6ULL, 0xA019CFB6BF9CE5E5ULL, 0x7F1F36595773B8CAULL, 0x973276742389C43CULL, 
            0x88667627B1911E4AULL, 0x51D5AE5A95A6F515ULL, 0x935047EFA0BB0D11ULL, 0xFE34C5B72A4B04AAULL, 
            0x72A9C4D984F2CEB1ULL, 0x9C175485F35E1C61ULL, 0xD9F2E0E3A448398DULL, 0xB423EAD283F20CC3ULL, 
            0xFF1CDBCFF1893576ULL, 0x184140E7AD5A189DULL, 0x3E95D3EEC01F1235ULL, 0x29FD525361BDA1EAULL, 
            0x5F636C96104B8727ULL, 0x20D7AFE1C9D1E62FULL, 0x261FD880ED4D7AB6ULL, 0x2E5C0EDB25A530E4ULL, 
            0xE0B52032F784888AULL, 0xED98663F0375B3BEULL, 0xC692FF1CCEE2EE96ULL, 0xDDFB0E59AAA2A5DDULL, 
            0x73A0B04C2B30ABA5ULL, 0x965E7276894D0133ULL, 0xBBFBA28446C4C400ULL, 0xA14193E72212ED04ULL, 
            0x47402015CFC96688ULL, 0x5620EF7F68C31700ULL, 0xE4929E1AB64E087DULL, 0x5E29BF93FE9314EAULL
        },
        {
            0x75A968668983DF67ULL, 0xAAFDB444C9D5B8DDULL, 0xAB048198710922E1ULL, 0x58BFC4FFACFD70A3ULL, 
            0xC1FC69AC46DF0BE0ULL, 0xDBCEE504276EDFCAULL, 0x0E5F36E65459293DULL, 0xA4BCFE3AAA24A51DULL, 
            0x707011A142F7BAEFULL, 0xF5A6924DB57C7390ULL, 0xD655799489CAF737ULL, 0xCEFDAD3D65B573E8ULL, 
            0x969C03210F07C454ULL, 0x04C05DB91EBDAC57ULL, 0x8246F78FA7BA9503ULL, 0x413EB00EED4F93F6ULL, 
            0x4269A93AB41B47A7ULL, 0xEBA51EFEBAE7E03AULL, 0x4AB7C4E49E934DECULL, 0xE5890754ADEC6DD6ULL, 
            0x09F2E8073088FC78ULL, 0x3C66CB9D8583AFE4ULL, 0xC9AD9E1BF4C2E80AULL, 0xF5E1DCA63A57307AULL, 
            0xADDB3DF5FA3B6CC5ULL, 0x91DBA32F86E24EECULL, 0x8EBCF3D48E5B5FC4ULL, 0xE20FC9CD12075167ULL, 
            0x8F240035BE345847ULL, 0xEC5D06D1334DC740ULL, 0x7EA8875E9DC5C704ULL, 0x5A461E75D3E3A215ULL
        },
        {
            0x504AFBD03EB37440ULL, 0x4430516E3B80E24BULL, 0xF44710A1809F6177ULL, 0x73B3A27730301B84ULL, 
            0x400646AF4D01AC7DULL, 0x2F6791938EE6868DULL, 0xDAA3C8C712438800ULL, 0x69E26E3578454073ULL, 
            0xC3D4D9D31C324999ULL, 0x4F607808E2A37DE0ULL, 0xECD3D46BE2B75EB0ULL, 0xCEDE5293EEF4EBCBULL, 
            0xDFEF67C0E5007CA4ULL, 0x98EE2158CC0D70DCULL, 0x2DA7B48C43939802ULL, 0xEB561F24282121E2ULL, 
            0xDABF05CE9D02D6CDULL, 0x559C93478C8EDDF2ULL, 0xA499850BD6D48B28ULL, 0x37B0893F09B1312CULL, 
            0x02ED8F1457F59069ULL, 0xD55DBF21BA1B4696ULL, 0xC2B70294BAD6DEBFULL, 0x9A6041EAC8B45689ULL, 
            0x8E2B0228D39F9924ULL, 0x7B99BA23EA4FCBCDULL, 0xFE877F70946FA442ULL, 0x72391612CF931687ULL, 
            0x2CF0371C617BBCF2ULL, 0x58173C925794BE19ULL, 0x57712227C0B8D1B7ULL, 0x4C5B097B0D3D81E0ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Tennis::kPhaseHConstants = {
    0xA7A5AB2ED9B40067ULL,
    0x66B48176B5696982ULL,
    0x67FCE2CD8DBD5922ULL,
    0xA7A5AB2ED9B40067ULL,
    0x66B48176B5696982ULL,
    0x67FCE2CD8DBD5922ULL,
    0x310748D0D5B9765BULL,
    0x3798B1C01B379192ULL,
    0x05,
    0xB4,
    0x97,
    0xF5,
    0x34,
    0xEF,
    0x7F,
    0x96
};

