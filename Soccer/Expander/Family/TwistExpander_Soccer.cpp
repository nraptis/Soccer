#include "TwistExpander_Soccer.hpp"
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

TwistExpander_Soccer::TwistExpander_Soccer()
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
    std::memcpy(&mDomainBundleEphemeral, &mDomainBundleInbuilt, sizeof(mDomainBundleEphemeral));
}

void TwistExpander_Soccer::KDF_A(std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet,
                                  std::uint8_t *pSnow,
                                  int pIndexKDF) {
    TwistExpander::KDF_A(pNonce, pConstants, pDomainSaltSet, pSnow, pIndexKDF);
    TwistWorkSpace *pWorkSpace = mWorkspace;
    if ((pWorkSpace == nullptr) || (mSource == nullptr) ||
        (pConstants == nullptr) || (pDomainSaltSet == nullptr) || (pSnow == nullptr)) { return; }
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
    [[maybe_unused]] std::size_t *aIndexList256A = mIndexList256A;
    [[maybe_unused]] std::size_t *aIndexList256B = mIndexList256B;
    [[maybe_unused]] std::size_t *aIndexList256C = mIndexList256C;
    [[maybe_unused]] std::size_t *aIndexList256D = mIndexList256D;
    std::uint64_t aPrevious = 0xFA78BFFE33EFEE34ULL; std::uint64_t aIngress = 0xA6B786AA63E526D6ULL; std::uint64_t aCarry = 0x82833B8C06429BD5ULL;

    std::uint64_t aWandererA = 0xE57F4A1714D5DC0BULL; std::uint64_t aWandererB = 0xBC1E7050ED584CF5ULL; std::uint64_t aWandererC = 0xDE82EC4CF1E30C2EULL; std::uint64_t aWandererD = 0xCF006AA8460FF5F5ULL;
    std::uint64_t aWandererE = 0x8887299A228EB3A6ULL; std::uint64_t aWandererF = 0xB2CD08B77F3ECEE6ULL; std::uint64_t aWandererG = 0x8B2C0866E1A96297ULL; std::uint64_t aWandererH = 0xA102E8C6CA517BE1ULL;
    std::uint64_t aWandererI = 0xFA669738ABACDBC3ULL; std::uint64_t aWandererJ = 0xBAED73FBBA6ECD0DULL; std::uint64_t aWandererK = 0xD7BEB858BE9CEAE1ULL;

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
        aPrevious = 16440317494028584300U;
        aCarry = 11433606213275264250U;
        aWandererA = 10113837188947998351U;
        aWandererB = 18151157847085285905U;
        aWandererC = 15520581804178451794U;
        aWandererD = 14309726929646481056U;
        aWandererE = 12682655706085665545U;
        aWandererF = 11955350066669056288U;
        aWandererG = 14552596478491611477U;
        aWandererH = 13020898615416471077U;
        aWandererI = 10222595140770159374U;
        aWandererJ = 12656006047902017699U;
        aWandererK = 10083108451525287588U;
    }
    //
    // ---------------------------------------------------
    // KDF_A_A kdf_a_loop_a:
    // ---------------------------------------------------
    // read from: source, snow
    // temp storage: fire_a, fire_b
    // ---------------------------------------------------
    // write to: fire_a, fire_b, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::KDF_A_A(pWorkSpace,
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
    // read from: expand_a, expand_b, expand_c, expand_d
    // temp storage: fire_c, fire_d
    // ---------------------------------------------------
    // write to: fire_c, fire_d, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::KDF_A_B(pWorkSpace,
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
    // read from: operation_a, operation_b, operation_c, operation_d
    // temp storage: fire_a, fire_b, fire_c, fire_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::KDF_A_C(pWorkSpace,
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
        TwistDiffuse::DiffuseWithDomainWords(aWorkLaneA, aWorkLaneB,  // input lanes
                         aExpandLaneA, aExpandLaneB, // output lanes
                         aOperationLaneA, aOperationLaneB, // index shuffle seeds
                         aOperationLaneC, aOperationLaneD, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    }
    {
        TwistDiffuse::DiffuseWithDomainWords(aWorkLaneC, aWorkLaneD,  // input lanes
                         aExpandLaneC, aExpandLaneD, // output lanes
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
    // KDF_A_D kdf_a_loop_d:
    // ---------------------------------------------------
    // read from: expand_a, expand_b, expand_c, expand_d
    // temp storage: fire_a, fire_b, fire_c, fire_d, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Soccer::KDF_B(std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet,
                                  int pIndexKDF) {
    TwistExpander::KDF_B(pNonce, pConstants, pDomainSaltSet, pIndexKDF);
    TwistWorkSpace *pWorkSpace = mWorkspace;
    if ((pWorkSpace == nullptr) || (mSource == nullptr) ||
        (pConstants == nullptr) || (pDomainSaltSet == nullptr)) { return; }
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
    [[maybe_unused]] std::size_t *aIndexList256A = mIndexList256A;
    [[maybe_unused]] std::size_t *aIndexList256B = mIndexList256B;
    [[maybe_unused]] std::size_t *aIndexList256C = mIndexList256C;
    [[maybe_unused]] std::size_t *aIndexList256D = mIndexList256D;
    std::uint64_t aPrevious = 0xC60816B8DC61A941ULL; std::uint64_t aIngress = 0xA4FAB404A55F70F8ULL; std::uint64_t aCarry = 0xD22C79343858AF9BULL;

    std::uint64_t aWandererA = 0x9C64324F33A744CBULL; std::uint64_t aWandererB = 0xBA2971A7F6CB2520ULL; std::uint64_t aWandererC = 0x87A5CB31A48DA9F4ULL; std::uint64_t aWandererD = 0xEAD3738FB656662BULL;
    std::uint64_t aWandererE = 0xF4D743863B696B5AULL; std::uint64_t aWandererF = 0xC0B90B994BD4F8D2ULL; std::uint64_t aWandererG = 0xB55A6B0C3F82051FULL; std::uint64_t aWandererH = 0xEE1D9143FB5A6FE7ULL;
    std::uint64_t aWandererI = 0xBEA53871C52A56E7ULL; std::uint64_t aWandererJ = 0x90840268E91984EFULL; std::uint64_t aWandererK = 0xFDEC0731F3A3411FULL;

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
        aPrevious = 11242982421454410824U;
        aCarry = 10037732081750081062U;
        aWandererA = 14327364508281530622U;
        aWandererB = 12745838008596646422U;
        aWandererC = 16633145921671965810U;
        aWandererD = 15544543244934125504U;
        aWandererE = 16169027720109592885U;
        aWandererF = 14847110907830066717U;
        aWandererG = 11457921420328860212U;
        aWandererH = 17299885435642562802U;
        aWandererI = 10565061907655804694U;
        aWandererJ = 18145246612581406242U;
        aWandererK = 12431633307485202640U;
    }
    //
    // ---------------------------------------------------
    // KDF_B_A kdf_b_loop_a:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // temp storage: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    // write to: fire_a, fire_b, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::KDF_B_A(pWorkSpace,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::KDF_B_B(pWorkSpace,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::KDF_B_C(pWorkSpace,
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
        TwistDiffuse::DiffuseWithDomainWords(aExpandLaneA, aExpandLaneB,  // input lanes
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
        TwistDiffuse::DiffuseWithDomainWords(aExpandLaneC, aExpandLaneD,  // input lanes
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Soccer::Seed(TwistWorkSpace *pWorkSpace,
                                 TwistFarmSalt *pFarmSalt,
                                 std::uint64_t pNonce,
                                 std::uint8_t *pPassword,
                                 unsigned int pPasswordByteLength,
                                 std::uint8_t *pDestination) {
    TwistExpander::Seed(pWorkSpace, pFarmSalt, pNonce, pPassword, pPasswordByteLength, pDestination);
    if ((pWorkSpace == nullptr) || (pFarmSalt == nullptr)) { return; }
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
    std::uint64_t aPrevious = 0xC1C04ABE66B20679ULL;
    std::uint64_t aIngress = 0xA14FE64C24041873ULL;
    std::uint64_t aCarry = 0xB9B7B5BA04F28F4CULL;

    std::uint64_t aWandererA = 0xA3159B8BE6E1CFBBULL;
    std::uint64_t aWandererB = 0xA9764C074327A135ULL;
    std::uint64_t aWandererC = 0x873ECDD6E6D0430EULL;
    std::uint64_t aWandererD = 0x846282DCE0E017DCULL;
    std::uint64_t aWandererE = 0xC9DB3043858F8A2DULL;
    std::uint64_t aWandererF = 0xE9BCF84458A13DBCULL;
    std::uint64_t aWandererG = 0xB355D0EEB8320135ULL;
    std::uint64_t aWandererH = 0x9E4296684F9AB545ULL;
    std::uint64_t aWandererI = 0x953649EA8A98FD00ULL;
    std::uint64_t aWandererJ = 0xD5848845676AC242ULL;
    std::uint64_t aWandererK = 0x8847B7DD9F2D91E9ULL;

    // [seed]
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneA);
        TwistSnow::Aria256Counter(mSource, aSnowLaneB);
        TwistSnow::Sha256Counter(mSource, aSnowLaneC);
        TwistSnow::AES256Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneC, 0);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase B
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneA, 1);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase C
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneD, 2);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneC, aExpandLaneA, aExpandLaneD, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase D
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneB, 3);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneA, aExpandLaneC, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase E
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneC, 4);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase F
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneA, 5);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneB, aExpandLaneC, aExpandLaneA, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase G
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneD, 6);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase H
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneB, 7);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashC(aExpandLaneD, aExpandLaneC, aExpandLaneA, aExpandLaneB, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseHConstants));
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::Seed_A(pWorkSpace,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: invest_a, invest_b, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::Seed_B(pWorkSpace,
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
    // read from: operation_a, operation_b, operation_c, operation_d
    // temp storage: fire_a, fire_b, fire_c, fire_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::Seed_C(pWorkSpace,
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

    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseCConstants.mMatrixArgD;
    {
        TwistDiffuse::DiffuseWithDomainWords(aWorkLaneA, aWorkLaneB,  // input lanes
                         aExpandLaneA, aExpandLaneB, // output lanes
                         aOperationLaneC, aOperationLaneD, // index shuffle seeds
                         aOperationLaneA, aOperationLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    }
    {
        TwistDiffuse::DiffuseWithDomainWords(aWorkLaneC, aWorkLaneD,  // input lanes
                         aExpandLaneC, aExpandLaneD, // output lanes
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
    // GSeedRunSeed_D seed_loop_d:
    // ---------------------------------------------------
    // read from: expand_a, expand_b, expand_c, expand_d
    // temp storage: fire_a, fire_b, fire_c, fire_d, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    // write to: work_a, work_b, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::Seed_D(pWorkSpace,
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
    // GSeedRunSeed_E seed_loop_e:
    // ---------------------------------------------------
    // read from: invest_a, invest_b, invest_c, invest_d
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: snow_a, snow_b, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::Seed_E(pWorkSpace,
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
    // GSeedRunSeed_F seed_loop_f:
    // ---------------------------------------------------
    // read from: operation_a, operation_b, operation_c, operation_d
    // temp storage: fire_a, fire_b, fire_c, fire_d, invest_a, invest_b, invest_c, invest_d
    // ---------------------------------------------------
    // write to: snow_a, snow_b, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::Seed_F(pWorkSpace,
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

    aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixSelectA;
    aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixSelectB;
    aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixUnrollA;
    aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixUnrollB;
    aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixArgA;
    aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixArgB;
    aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixArgC;
    aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseGConstants.mMatrixArgD;
    //
    {
        TwistDiffuse::DiffuseWithDomainWords(aExpandLaneA, aExpandLaneB,  // input lanes
                         aSnowLaneA, aSnowLaneB, // output lanes
                         aOperationLaneC, aOperationLaneD, // index shuffle seeds
                         aOperationLaneA, aOperationLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix,
                         aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, // matrix select
                         aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, // matrix unroll
                         aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD); // matrix args
    }
    {
        TwistDiffuse::DiffuseWithDomainWords(aExpandLaneC, aExpandLaneD,  // input lanes
                         aSnowLaneC, aSnowLaneD, // output lanes
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
    // GSeedRunSeed_G seed_loop_h:
    // ---------------------------------------------------
    // read from: snow_a, snow_b, snow_c, snow_d
    // temp storage: fire_a, fire_b, fire_c, fire_d, operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    // write to: work_a, work_b, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::Seed_G(pWorkSpace,
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

        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, pDestination);
    //
    // ---------------------------------------------------
    // GROW_A grow_key_a:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::GROW_A(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::GROW_B(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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

void TwistExpander_Soccer::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }
}

void TwistExpander_Soccer::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xD5D7058775888278ULL; std::uint64_t aIngress = 0xC97E75FD5B71E5F8ULL; std::uint64_t aCarry = 0xDD49C2F6C6E2EBEEULL;

    std::uint64_t aWandererA = 0xEDC8463C9653AE46ULL; std::uint64_t aWandererB = 0xFC0F8FFA0B98B6B9ULL; std::uint64_t aWandererC = 0xEC0CB1D7E212741BULL; std::uint64_t aWandererD = 0xDA8741C1BAE39287ULL;
    std::uint64_t aWandererE = 0xB2CCDA20CA4B75EBULL; std::uint64_t aWandererF = 0xB75CDDC97757C594ULL; std::uint64_t aWandererG = 0xB1BD622785FF6E7AULL; std::uint64_t aWandererH = 0xEE4B4FFC61A54096ULL;
    std::uint64_t aWandererI = 0x94720E32E3DF6519ULL; std::uint64_t aWandererJ = 0xDCDDB3CBF195AEB7ULL; std::uint64_t aWandererK = 0x96DE42D44AA63342ULL;

    // [seed]
    {
        aPrevious = 18170633703018823089U;
        aCarry = 14712571496175414780U;
        aWandererA = 15662968043124605331U;
        aWandererB = 15361517222345306779U;
        aWandererC = 16211599201917444083U;
        aWandererD = 10521243529596490241U;
        aWandererE = 14062292791489135475U;
        aWandererF = 14229283543055436868U;
        aWandererG = 14526853992173309616U;
        aWandererH = 13692011696739513921U;
        aWandererI = 16322875020001651450U;
        aWandererJ = 18293374535372080857U;
        aWandererK = 17532549827703433213U;
    }
    //
    // ---------------------------------------------------
    // GTwistRunTwist_A twist_loop_a:
    // ---------------------------------------------------
    // read from: source, key_row_read_a, key_row_read_b
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::Twist_A(pWorkSpace,
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
    // read from: expand_a, expand_b, expand_c, expand_d
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::Twist_B(pWorkSpace,
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
    // read from: operation_a, operation_b, operation_c, operation_d
    // temp storage: fire_a, fire_b, fire_c, fire_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Soccer_Arx::Twist_C(pWorkSpace,
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
        TwistSquash::SquashA(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
    if ((pBlockCount - pBlockIndex) > static_cast<std::size_t>(H_KEY)) {
        //
        // ---------------------------------------------------
        // GROW_A grow_key_a:
        // ---------------------------------------------------
        // read from: work_a, work_b, work_c, work_d
        // ---------------------------------------------------
        // write to: expand_a, expand_b, expand_c, expand_d
        // ---------------------------------------------------
        //
        TwistExpander_Soccer_Arx::GROW_A(pWorkSpace,
                     &aPrevious,
                     &aIngress,
                     &aCarry,
                     &aWandererA,
                     &aWandererB,
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
        // ---------------------------------------------------
        // write to: work_a, work_b, work_c, work_d
        // ---------------------------------------------------
        //
        TwistExpander_Soccer_Arx::GROW_B(pWorkSpace,
                     &aPrevious,
                     &aIngress,
                     &aCarry,
                     &aWandererA,
                     &aWandererB,
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

void TwistExpander_Soccer::GrowKeyA(TwistWorkSpace *pWorkSpace) {
    TwistExpander::GrowKeyA(pWorkSpace);
    if (pWorkSpace == nullptr) { return; }
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
    [[maybe_unused]] std::uint8_t *aKeyRowWriteA = &(pWorkSpace->mKeyBoxA[0][0]);

    // [grow key a]
    // GKeyFoldA grow_key_a_fold (start)
    static_assert((S_BLOCK / W_KEY) == 16, "GKeyFoldA expects 16 key-row chunks.");
    TwistShiftBox::ShiftKeyBoxA(pWorkSpace);
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 2, 0, 3 with offsets 6133U, 6345U, 812U, 7717U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6133U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6345U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 812U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7717U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 2, 1 with offsets 3048U, 6164U, 8002U, 3295U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3048U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6164U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 8002U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3295U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 1, 1, 2 with offsets 3573U, 3808U, 6635U, 2406U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3573U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3808U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6635U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2406U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 0, 3, 0 with offsets 3377U, 4036U, 4714U, 233U
        // byte shifts: 0U, 24U, 8U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3377U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4036U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4714U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 233U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 2, 1, 0 with offsets 1908U, 104U, 818U, 321U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1908U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 104U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 818U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 321U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 1, 0, 2, 3 with offsets 1980U, 1782U, 1444U, 1009U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseB
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1980U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1782U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1444U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1009U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 1, 3, 0, 2 with offsets 1240U, 2023U, 755U, 256U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseB
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1240U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2023U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 755U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 256U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 0, 2, 1, 3 with offsets 641U, 2019U, 500U, 495U
        // byte shifts: 0U, 8U, 16U, 24U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 641U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2019U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 500U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 495U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1878U, 753U, 523U, 446U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseB
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1878U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 753U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 523U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 446U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Soccer::GrowKeyB(TwistWorkSpace *pWorkSpace) {
    TwistExpander::GrowKeyB(pWorkSpace);
    if (pWorkSpace == nullptr) { return; }
    [[maybe_unused]] std::uint8_t *aExpandLaneA = pWorkSpace->mExpansionLaneA;
    [[maybe_unused]] std::uint8_t *aExpandLaneB = pWorkSpace->mExpansionLaneB;
    [[maybe_unused]] std::uint8_t *aExpandLaneC = pWorkSpace->mExpansionLaneC;
    [[maybe_unused]] std::uint8_t *aExpandLaneD = pWorkSpace->mExpansionLaneD;
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    [[maybe_unused]] std::uint8_t *aWorkLaneC = pWorkSpace->mWorkLaneC;
    [[maybe_unused]] std::uint8_t *aWorkLaneD = pWorkSpace->mWorkLaneD;
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aKeyRowWriteB = &(pWorkSpace->mKeyBoxB[0][0]);

    // [grow key b]
    // GKeyFoldB grow_key_b_fold (start)
    static_assert((S_BLOCK / W_KEY) == 16, "GKeyFoldB expects 16 key-row chunks.");
    TwistShiftBox::ShiftKeyBoxB(pWorkSpace);
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 1, 3 with offsets 4012U, 5845U, 4902U, 3706U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4012U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5845U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4902U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3706U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 1, 3, 1 with offsets 7133U, 2481U, 4904U, 5128U
        // byte shifts: 0U, 16U, 24U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7133U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2481U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4904U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5128U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 0, 2 with offsets 976U, 5612U, 157U, 1557U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 976U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5612U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 157U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1557U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 3, 2, 0 with offsets 2970U, 7553U, 4137U, 2620U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2970U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7553U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4137U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2620U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 6528U, 708U, 4279U, 1514U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseB
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 6528U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 708U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 4279U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 1514U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1491U, 77U, 342U, 785U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1491U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 77U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 342U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 785U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 694U, 1417U, 468U, 550U
        // byte shifts: 24U, 0U, 8U, 16U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 694U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1417U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 468U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 550U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 152U, 161U, 1521U, 657U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 152U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 161U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1521U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 657U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 1668U, 149U, 1967U, 969U
        // byte shifts: 16U, 0U, 8U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1668U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 149U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1967U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 969U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 0, 1, 2 [0..<W_KEY]
        // offsets: 1303U, 516U, 487U, 1197U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1303U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 516U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 487U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1197U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseASalts = {
    {
        {
            0x68243816D66DF7A6ULL, 0xBC0117EAE2348854ULL, 0x88AABBE0B051207EULL, 0x17D43A5602467EA8ULL, 
            0x549C068B448277B5ULL, 0x04E4B45C115B0384ULL, 0x02617E54CF2B8261ULL, 0x2767E9318E695E7DULL, 
            0xCC296E99919BE78CULL, 0xAD3E8B249A535C70ULL, 0xEC33E4D36F1E5E9DULL, 0x443634D554ACC412ULL, 
            0xEBCE3F4A04D5741DULL, 0xF1965CE0AF03BDD1ULL, 0x6329C8253F1E048AULL, 0x18EBCB50EA6DF9AAULL, 
            0x3646E655ADFE2912ULL, 0x9D6B4C7BD5AFBDEBULL, 0x7B0F1DB67710F83BULL, 0xE468155EA3E230EFULL, 
            0x124BCD328A0C9685ULL, 0x40A4FBC711C97B28ULL, 0x020C201D4637521EULL, 0xFDB6D5312BC30AD0ULL, 
            0x6E0FF46C592FA3CFULL, 0xCB21158AD3E902BCULL, 0x70A7ACC71DCCEA11ULL, 0xE11AA8AA1EB364D4ULL, 
            0x5C5F1686F4D31E89ULL, 0x4606AE138523DBD9ULL, 0x32A72D9DB28BE60CULL, 0x11BE6A32A6286798ULL
        },
        {
            0xA4FA66529AF4540FULL, 0x50AE8C111360A868ULL, 0x9921737A057E672FULL, 0x315B96F8ACAF72B3ULL, 
            0x437FC809C09B6636ULL, 0x263EA2A793A5F707ULL, 0xA041AEBF615E3E30ULL, 0x5E8C944362FBC43FULL, 
            0xEB512E566B18242BULL, 0xC24AA7E259B7CBB9ULL, 0xEB53F0D5F5BE789FULL, 0x63432741195BF691ULL, 
            0xBD654B10BAC0F9B9ULL, 0x523AFBDC8B5B1921ULL, 0x6342F3DD5628A54AULL, 0x8F96551AB96BF1DDULL, 
            0xB248A60A517CC418ULL, 0xDEB277424B2AC2F5ULL, 0x27959BD5CD1B238AULL, 0x7CB598E41F1C69EAULL, 
            0xEFCA7874623EF02CULL, 0x4C35EE2CFF0A344AULL, 0xC9394C61C4934E4AULL, 0x503E63D98A331ACAULL, 
            0xD1DF72AD5E399D3EULL, 0xB975EE6EFFD0B83DULL, 0xF3D850ED38790F1CULL, 0xE2DFA1E563F142E6ULL, 
            0xCAA36E22025CA5D1ULL, 0x6AD827924CCE0707ULL, 0x88D04AF1A627A6AFULL, 0x5699F37F6B04060DULL
        },
        {
            0x9A80B5732D0C7166ULL, 0x4EA16F36C0BE1524ULL, 0xBB2F8197E2F44E8EULL, 0xDF776B696D69EED8ULL, 
            0xA93EE2B0B96196B2ULL, 0x72019A88AE2C36DCULL, 0x7D821A2EC7FD92FFULL, 0x9559405F450ED043ULL, 
            0x4A4ABF0C0191BDC1ULL, 0xD7737EED2744368CULL, 0x86AC3075AB6E4815ULL, 0xC3956EF22B05F9B6ULL, 
            0xE62C703364701289ULL, 0xEAF7A8F2CB375A2EULL, 0x570424B6CC4D89D2ULL, 0xA19C4436C54D2DC6ULL, 
            0xB45669C821253825ULL, 0xCE539143D43888CBULL, 0xF54D6EDCA0F35BDDULL, 0xBEB4B2FCEED2DB48ULL, 
            0x15080EF81E2ACE1DULL, 0xDF88C3CB5BD0E884ULL, 0x6C8575161C400A4CULL, 0x0343F5E3CA151699ULL, 
            0x56511489B030DEA5ULL, 0xE1BFEC22161818EBULL, 0x16C625B56382F80AULL, 0x6FCEB17D8A6DB7E9ULL, 
            0x82A61693A5EB58E4ULL, 0x574DD5578F87FE20ULL, 0xFE0FBFBC4D416181ULL, 0x650739372B263DC4ULL
        },
        {
            0x85AAFDEFC5AB0224ULL, 0x9751FFEEF0CC432CULL, 0xD234770D759A4737ULL, 0xF1BC856171AACF89ULL, 
            0x0DB3A53C7CE7A2F1ULL, 0x65540EC6ADB4EC3AULL, 0xB228A8787C8382A8ULL, 0x17DFDAFFA0838EDFULL, 
            0x4CD6FFD875113FECULL, 0x7C506C9F9B829CFDULL, 0x859CA7B387D1CD7FULL, 0xE4C9E6A1B8C512C2ULL, 
            0x305ECF13DB1AAA58ULL, 0xB0984BA7FDC9A96DULL, 0x991A84FE7FE50A90ULL, 0x226E438454FFD427ULL, 
            0x12B0572CFED9D6B0ULL, 0xFD029DA81C3621A8ULL, 0x69E31D4760C00198ULL, 0xDAC94FAACC128984ULL, 
            0x1BEB42075456328BULL, 0xF71DB9A24270A5CDULL, 0xAAB5D9C5D2A90859ULL, 0x1FD94A2E23850083ULL, 
            0x182983B8373EDD9FULL, 0x5820BFB9803C57D1ULL, 0xA9D001CF61E14F62ULL, 0xF55F4961E728A3F7ULL, 
            0xEF71871327EA7A21ULL, 0xE4E46F8BE1BC6AC1ULL, 0xC6872CEE6D5A471EULL, 0x329F32AFE18DAD44ULL
        },
        {
            0x9B9BB9CC2428003EULL, 0xA15285E28CD8B2F9ULL, 0x121B3D48D9B1D353ULL, 0x6AD490F918F536A7ULL, 
            0xECAEBC1487CBD573ULL, 0x0CEB07815B237349ULL, 0xC0F5936433D22AD4ULL, 0xBEAA9EE865B62CF2ULL, 
            0x79EFB36CDFE9483BULL, 0xA124D14D25AF550AULL, 0xE17E1B9691A115ABULL, 0xFB1E959F56B94AE3ULL, 
            0x1BDDABE382A7A237ULL, 0x397092140C3744E2ULL, 0xC25EF2C5D9EFF945ULL, 0x0FF757EB17C40270ULL, 
            0xD64CF1F5F3425D66ULL, 0x003363D0DEB21DC6ULL, 0x2148A9FF105014B5ULL, 0x98BE1BA4B500027DULL, 
            0x67002D02EDD56D7CULL, 0xD935D069B973B721ULL, 0xF8640E76230CAC47ULL, 0x4CF6CEE2696AA752ULL, 
            0xB72380790702A0DAULL, 0xD3B74320C53151E4ULL, 0x911924C799441645ULL, 0xD252ED36AC627F78ULL, 
            0x744C62E1BBF90CE8ULL, 0xEBCDC7920A92350EULL, 0x08E7C892B372CDB6ULL, 0x7FF45D093D6F51BEULL
        },
        {
            0x39A873D6FE0C70D8ULL, 0x2D36869588D9034FULL, 0xAF77C3E2B23477BAULL, 0x783B52DCD1B2F81FULL, 
            0x220A4B6F0CF67531ULL, 0xB8A8F42E1768596DULL, 0xB2CE0C6F648BE7A5ULL, 0x952F8F35736B686FULL, 
            0x3F546BDBAF5825DAULL, 0x0D8AEC21E857DCEFULL, 0xA4DE226E3C3E6A39ULL, 0x04A3584E34A7D566ULL, 
            0xE84935F7CF2EE657ULL, 0xE0F8065685CF3CB9ULL, 0xBBF29D4F8EC9BCA1ULL, 0xF7B6A8B37EBE2660ULL, 
            0x73A4F24ABFF807D0ULL, 0x5C65683F566D9BE1ULL, 0xA0A9C56FC0E1B015ULL, 0xD9D0FD3814F7055BULL, 
            0x8648AD56803577EFULL, 0x4CC0A43B9DDD7B56ULL, 0x0AD30D7C13B418B4ULL, 0x5B3E7212314C9627ULL, 
            0x930B8F3EECDD3262ULL, 0xEFBC01FBDFB2D679ULL, 0xA3966B408D5EAEA8ULL, 0x1A0C411293B87C7AULL, 
            0x4FEE1D74AE8A06A8ULL, 0xF1BD3C28A806DEF5ULL, 0x9E50E4C70A38C50BULL, 0x37C336267C740483ULL
        }
    },
    {
        {
            0x6AC3B050832F47D0ULL, 0x09F5C278E85C9138ULL, 0x9833F182805CA5DAULL, 0x130077C534066933ULL, 
            0x719D32895EAA4B35ULL, 0x5D31C6BEEBEA19ABULL, 0x5326F7B6D23A0849ULL, 0xB967825A710B8EF6ULL, 
            0xADA79526BFC31DE1ULL, 0xEAC54A358AAFC1C3ULL, 0xB7F02DA0F78B6E6EULL, 0x5971CE0D345BE3B1ULL, 
            0x008702757EC521B0ULL, 0x7F24252CD50052B3ULL, 0xF9112309B168CBDAULL, 0xCB181B7513E6DAF3ULL, 
            0xBBAEED140A9B8A6BULL, 0x72BEF75AEC27C530ULL, 0x1A4FA284A7C3D00AULL, 0xAEB1983B15B71489ULL, 
            0xA8A414019BA8BC84ULL, 0xD710D7597E8937DDULL, 0x7702D731B0BFD0A9ULL, 0xB105476D74A8DD24ULL, 
            0x747649BFE45BD7CFULL, 0x9097C3645EFBA159ULL, 0x45160F1A864AD732ULL, 0x1B737582ABFE52BEULL, 
            0x0A2C77D9C8698903ULL, 0xD8D4729A0A916AF9ULL, 0x9AAD611E896672DEULL, 0xE51C350EE8EFE1C7ULL
        },
        {
            0x87D227EE44C43411ULL, 0xDD9B80AD9905F108ULL, 0x330C28BBC86319F5ULL, 0x11834CBA5E5A3A57ULL, 
            0x6D3CB27A7DDBB27CULL, 0x5113D9134BFC6C02ULL, 0x9EBFD54EAC09CAABULL, 0x6C302278E34DA554ULL, 
            0x45D572A13E476FFBULL, 0xAD1D13640BD7A2E9ULL, 0x8C0694B23B08181FULL, 0x4BDD9B1B60E61980ULL, 
            0xDE7A988796C06E10ULL, 0xA93408ED3E52207EULL, 0xC7C053B17731BC78ULL, 0x7847621D80156193ULL, 
            0xB5EB639DFBFD3C78ULL, 0x8BB0EED47080086CULL, 0x67B434246C0C84C5ULL, 0xEF794261B0A608D8ULL, 
            0xA6FE17E961FA8277ULL, 0x84D956BCECF40CB0ULL, 0x9CA36A1E4E34D28FULL, 0xA0C0971B49B9D6A8ULL, 
            0x13AD3DCE2C0D7264ULL, 0xA570E42FA37256ADULL, 0x31B50E23A86AD12BULL, 0xFE2C9EC47A8288B2ULL, 
            0x1750A05B7AADC97FULL, 0x3BAB7D0847B078A9ULL, 0xE4D1FA99DFC6C9ACULL, 0x1FFAB94E8A354E6FULL
        },
        {
            0x39B2852024271695ULL, 0xC353EDC33AC8D8B3ULL, 0x862AFC6373C3E98BULL, 0x23C4894D736D4362ULL, 
            0x530B5C1CBB80921CULL, 0xCCD8EAE1B7466066ULL, 0xD5CB9C3F1DD7AE97ULL, 0xFA0544C3037E3B0FULL, 
            0xCD615FDCCCA0506AULL, 0x37F83D8C61DDFF1FULL, 0x5B046D06A89BD136ULL, 0xE0830042B1724525ULL, 
            0x6AD19B1C30BFF7F5ULL, 0xF4487FCA7F84FA9AULL, 0x51AA88C2D6EB23F6ULL, 0xD2EA0778A3E7E4F6ULL, 
            0x802B3BE9C39F0840ULL, 0x022A1FC2D5BB72FDULL, 0x9821B3B747151E92ULL, 0x5D54A77CF446EE5FULL, 
            0x04538B05F6BC07ACULL, 0x9E22F499CE4D241AULL, 0x9E397F5E4862979FULL, 0x266719829A322774ULL, 
            0x0722D07B743C7BD6ULL, 0x8A796893B9C4C810ULL, 0x53E1EC38F7FD3108ULL, 0x0AFEF014A20E8FF2ULL, 
            0x49D48E823D86213AULL, 0xDB7F5F778C13694DULL, 0xFD01BD881E355620ULL, 0xDB49E6C1EDA8154BULL
        },
        {
            0xD9249ECC74B547CDULL, 0x553F84E1766778FCULL, 0xEC3E6E0C36531925ULL, 0xA4E364F7C2CE477CULL, 
            0xC505E228AEF56949ULL, 0xD51BF0FAC565F713ULL, 0x7E34A9A9018082B7ULL, 0x1D0563B63F41EB0FULL, 
            0x3119281E4B7F2FB9ULL, 0x0B3E2E850B88E11DULL, 0x4CDD372EDA46B7FCULL, 0x64138DD8A3064D53ULL, 
            0xC775E2FDEE7148DCULL, 0x41FC99AF53DFCEAEULL, 0xADB93356DCDBF899ULL, 0x986CA817B361A5FDULL, 
            0x23FE4B95ED0F0CB9ULL, 0xADA96A628380E6C6ULL, 0x3053516EED71DE5AULL, 0x46D66F692A4D5F86ULL, 
            0xC0702593B2802962ULL, 0xA9A819B0346272DCULL, 0xAF14D1BC63C19D84ULL, 0x4749D361266413F6ULL, 
            0x2B26A9C37FA7678CULL, 0xEBB1D2B7D89F4F2AULL, 0x615FD88325572BF0ULL, 0x84BA1C2FCE846FC3ULL, 
            0x2D9807FE02FA2F7BULL, 0x404624C4EE0E599DULL, 0x0D2C1B876552F3B7ULL, 0x7B823D39833A1B40ULL
        },
        {
            0xDF3F7AEB97287614ULL, 0x5D2D1359B85CEBB1ULL, 0x96F844A25D3B41D1ULL, 0x3588B59C9E652638ULL, 
            0x296F4A3FF53733B4ULL, 0xE0DFBD1BE0CBD0B1ULL, 0x860C51844AA1F806ULL, 0x9BBA7B3D0252B1DCULL, 
            0x9FBE7C73CCC088DFULL, 0x817FA344591279E2ULL, 0x1D8B1C553D2BF2DFULL, 0x9609DB17F37C7D22ULL, 
            0xAA388E5C4AEBE5E7ULL, 0x26FDAE9208A5A0C6ULL, 0x1407A59E479D1677ULL, 0x55CC162178F89F63ULL, 
            0x47BA3A96A1FA18E9ULL, 0xEDC139ED7994ADA0ULL, 0x55F5C0068D0C0701ULL, 0xEF6C0193B7003584ULL, 
            0xCD30C50F9188BA14ULL, 0x0561CBCB0D92558FULL, 0x0D0D6043C300745AULL, 0x2B1FC32394DF7FE7ULL, 
            0x26B855D911227C0AULL, 0x14FA2605A53C592BULL, 0x719B5C42916F4263ULL, 0x20CE2ADC9B1AB5FDULL, 
            0x2DFD4D66A491ED12ULL, 0x13C37D73ED0BDA0FULL, 0xBBAA77981A05F25CULL, 0x67B42187F6460912ULL
        },
        {
            0x1C1FC774528461F8ULL, 0x8E0E71F82A8BD07FULL, 0xEAE85C483133D75AULL, 0xD9637F72CD63BA6EULL, 
            0x3AC0D298C907F43AULL, 0xF496696B96956994ULL, 0x3FA2941EB4768DA3ULL, 0xCD8A7900DDF9E7FEULL, 
            0x3FD58EB037AA5CA6ULL, 0x8936D34C73C00D16ULL, 0xA4C2A35E1082D3CCULL, 0x71CDE86A7CB875ACULL, 
            0x51437154AAD20049ULL, 0x5A7F2EC19CE74565ULL, 0x38DE275846EC5CF7ULL, 0x8883825132B9B80AULL, 
            0xC1934608E871C907ULL, 0x94CC5AA9636EC940ULL, 0xED615726A7EFF90EULL, 0x1A0EE3395399D3C4ULL, 
            0xC6AF248635556EDFULL, 0x4B7D1F56502BC37CULL, 0x5D47BCF9591BD891ULL, 0x87F688035437730BULL, 
            0x7E18327404447298ULL, 0x096D3D10FB8E1FBEULL, 0xC05224D4C721035CULL, 0xF20CC98B791F901BULL, 
            0xB949DAB67AAA6034ULL, 0xDD2A7E1243FAA4D8ULL, 0x4F771C1B82C2B66BULL, 0x3BA13B4CA450B6E5ULL
        }
    },
    {
        {
            0xCD0C6254F54D830BULL, 0xE4CE8C040D672520ULL, 0x17A66C45B7FE698BULL, 0x123F02B7AADCFC03ULL, 
            0x4E9F15AE4A703CB7ULL, 0x0F7727ED26D10523ULL, 0x79620C374F0828E3ULL, 0x88745B6EAC6E3C13ULL, 
            0x3FBE8D080481F84BULL, 0x9144580D43ED8156ULL, 0xFCD55962D02B0FFEULL, 0x16587015F227B202ULL, 
            0x06876565053E1D26ULL, 0x12F233D95089BFBDULL, 0x9E45284C275070FDULL, 0x0F6107D321C385FFULL, 
            0x94B71B9C9B442372ULL, 0x4CCCDCD4206EF46BULL, 0x1E260B4D13DE46ABULL, 0x518F1EC1BC234222ULL, 
            0x9C935A5C5ABC4882ULL, 0x7E6D0E7683502455ULL, 0x7E7686A12BB0E077ULL, 0x36AD55FD77B33879ULL, 
            0xA20410BBEC809083ULL, 0x8EDA466F7D222743ULL, 0x98EE7732A67F3C9AULL, 0xFB67426D604319B1ULL, 
            0x144CBDAAEC28CE5DULL, 0x9F4B16A57C3CB4F9ULL, 0x81B913E4CD43520DULL, 0x3EFCBCBD26F0A91CULL
        },
        {
            0x237AE05A572ADACFULL, 0x771847DC80A5DCE3ULL, 0xD1A5808248827A40ULL, 0xA9F3A108A459967BULL, 
            0xEE20F29AE13E5B35ULL, 0x72E851084ED33D6FULL, 0xE828611CBF3D7766ULL, 0x4DC718D6B33CA742ULL, 
            0x6BE30010DE1A0745ULL, 0x6719BC9FD3DCF17BULL, 0xBEEF59A3842FDA2CULL, 0xB391FE14A57DB8CAULL, 
            0x3F032F498F9FC2F0ULL, 0x720902B4F007F3ABULL, 0x2260C36F21A2A58BULL, 0x2F3FF2207AEC1BC1ULL, 
            0x0D84EE3E98E42DA3ULL, 0xFACBF33A3E895419ULL, 0xADA6258B459BF369ULL, 0x539DF9DEBF59194EULL, 
            0x9AB9F58BF806CECCULL, 0x48C94AA9158C2D72ULL, 0x9F0B68E8231D4964ULL, 0x4F7504A2F845F44DULL, 
            0xC35BD9B0843FD15EULL, 0xB1807EB790733C14ULL, 0x50130B55939A73E4ULL, 0xDB8B752F5E473FE3ULL, 
            0x90C394D24426DD35ULL, 0x1495DB9D78B2B805ULL, 0xA7E53CA53F89B9EAULL, 0xB2FFFAB5562D222CULL
        },
        {
            0x66297D5754F048C6ULL, 0x441E7C3BD0E7D9E7ULL, 0xC21ED856968044C7ULL, 0xB232664403EC4E8BULL, 
            0x7DC24F0CBC5D905CULL, 0x59887634CCE3AF5EULL, 0x431CE5AB0FBB0B53ULL, 0x013696E10054A2C7ULL, 
            0xFD661D017737DC18ULL, 0x72D4A96D80B9642FULL, 0xD5A3B1CEC802487BULL, 0xF82454450E750390ULL, 
            0xB2B0C19B4A467603ULL, 0xF127E23C3BF6F686ULL, 0x7E98138CE96A2C67ULL, 0xEF50D68935F49180ULL, 
            0xE0CF57EBD29E5B11ULL, 0xF72ED0BA3326DCE0ULL, 0x31603BFF1EDB495BULL, 0xAE625E755AC80D4AULL, 
            0xB94E100C9A794D63ULL, 0x2641506C3BF013E4ULL, 0x79A64C4B3A48127FULL, 0x59DD9D394A355A98ULL, 
            0x2AF1A5A2DF581C67ULL, 0xC0747C5DC50F462CULL, 0x5EB6AAA2A4495987ULL, 0x0C8214892272D798ULL, 
            0x7144751EF977D87AULL, 0x6742407B099F2379ULL, 0xD0DCDA74AF3CF8D6ULL, 0x14BD754C4C9055A9ULL
        },
        {
            0x9B3B6AE60F15A50DULL, 0x1A7A67B945E7E920ULL, 0x146489032E5C416DULL, 0xF8EAFCCF55A840AEULL, 
            0x437BBFD84F869DBCULL, 0xBE3638C18029E757ULL, 0xAE06BD9AD232D35EULL, 0xAA9F29918DDAC5E6ULL, 
            0x8C420AC59BA85611ULL, 0xC13E09E7623EED66ULL, 0x32CB3DD10CDC0266ULL, 0xE8E705D5402613CFULL, 
            0x97C6A93940C28805ULL, 0xBBA7B722B49F1287ULL, 0x4F419E2DE0CA58CDULL, 0x1F7D9D92F1A17FD4ULL, 
            0x393F96625FFE5052ULL, 0x98ECD61806FD035DULL, 0x9ADEF96DE23CBE92ULL, 0x31BA9EA25F82D535ULL, 
            0x8891BEA869A6DC50ULL, 0x1D7CA299C7A4DD92ULL, 0xA8AB8E3C85399F07ULL, 0x9FAF0DCFA1017F80ULL, 
            0xBB0BAD23D119782CULL, 0x1F0777D11F3AA3B1ULL, 0xEB3276DD5F0C82A1ULL, 0xFD0ECFE1BE9F9437ULL, 
            0xFDE8432D865915DAULL, 0x7F86B2F5703A2715ULL, 0x7821EA8E53400411ULL, 0x2F551111F1A6C4BBULL
        },
        {
            0xDF1D44C251B45185ULL, 0x071983795B7C5110ULL, 0x013B53319B6CC4CDULL, 0x7B4C6A61761F8154ULL, 
            0x05C0208803E2EA34ULL, 0x07890A89B6289589ULL, 0x5A7919AC094B3E94ULL, 0xBB540542BC358F7EULL, 
            0x7B3167A8835FE47CULL, 0xC138DAA1EE476175ULL, 0x6DD78B0EC7089AC1ULL, 0x4C1BCFB3B8538F9AULL, 
            0x62AC081921B4C2DEULL, 0xDDCAF048FA327597ULL, 0x8F81C25F1B465FD2ULL, 0x6CB6B0F416FB770FULL, 
            0xB92B78545889F727ULL, 0xCA797796653AA489ULL, 0x862CC01C903C5C9CULL, 0xDD40C4AD3CDD7B3BULL, 
            0x0636E7CBD122B6A5ULL, 0x04EDC089906A4677ULL, 0x1666652091C09107ULL, 0xE1AE072EE9181505ULL, 
            0xAE919CA57989DD40ULL, 0x452C3E44E3D52C6DULL, 0x5C4323FE0B14428EULL, 0x6EA8CAB3994F1B7DULL, 
            0xE561A85533C4A7A1ULL, 0x04075C243405E04AULL, 0x6F8D480AF0AE9D95ULL, 0xF8121172D91D38DDULL
        },
        {
            0x6E0530D7B455F4D8ULL, 0xB4C6DDF9310BC067ULL, 0x9A38BFCB1CCAD888ULL, 0x565A4F6350DEA067ULL, 
            0xCA5A14788E990054ULL, 0xA519DD4DBD828B5FULL, 0x7616E8B52C38DBA2ULL, 0xF384B63F87167B27ULL, 
            0x30CF9950CDC5C06DULL, 0x297A8DA54BB6B167ULL, 0x4CD36A78E2500588ULL, 0x3449EFCC3FE2418BULL, 
            0xE64B9845450CBACEULL, 0xA38AA8F1D554E692ULL, 0xA5F15D0593F1A5B1ULL, 0xCC2CF093A7D1ABD8ULL, 
            0x56F14767784F6D9EULL, 0x97149E0376B56E81ULL, 0x92237FDE9EB8CD08ULL, 0xFC760B649E338B6FULL, 
            0xF5F18A71325A22A1ULL, 0x453C177EC81EFB6DULL, 0xA9B142F18C53F2D3ULL, 0x58CB285DA9ED8888ULL, 
            0x38E5F22D013A2585ULL, 0x79E6BBBB48E60FE4ULL, 0x27B2E18C680A0069ULL, 0x2FC1114FB6218B19ULL, 
            0xB82435EFC3273BACULL, 0xA9570F443C5BA693ULL, 0xFCADC823364928A3ULL, 0x358C85579DE7F8C6ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseAConstants = {
    0xDE03CC85C591A0BCULL,
    0xE61CEFB52FA72CFDULL,
    0x7A3432892061924BULL,
    0xDE03CC85C591A0BCULL,
    0xE61CEFB52FA72CFDULL,
    0x7A3432892061924BULL,
    0xD56B3A0927B16F82ULL,
    0xA8A34E93607D6AFBULL,
    0x5D,
    0xE1,
    0xFB,
    0x20,
    0xDD,
    0x8D,
    0xF3,
    0xF6
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseBSalts = {
    {
        {
            0x839AEA6E7DE2C963ULL, 0x62CEC9C6E9A9B4F6ULL, 0x4170A06C0B76642AULL, 0xFBE24103EDBD8AEBULL, 
            0x08F597D9EDE51BC0ULL, 0xDB8D614D706C2768ULL, 0xAD7EA5CB03FD827BULL, 0x032C295EDDFC4B62ULL, 
            0x2F89608900BC54C4ULL, 0xD5EC672E10544811ULL, 0xEA69A96BC83CAA11ULL, 0xFA515D7AC313F14CULL, 
            0xEDA7955460967E92ULL, 0x24D152A4818FC440ULL, 0x008FCFD9C8C4293FULL, 0xF1164BBEC3C1EAEFULL, 
            0xD6952743983A6C60ULL, 0x71E85FE8BBE2D296ULL, 0x9C45AD5712C90825ULL, 0xAEF8397475CEAD35ULL, 
            0x5623087B26BBFDFEULL, 0x7126BEDA3B2E186CULL, 0x77E48679D5BB1F76ULL, 0xA53182B1BC470789ULL, 
            0xF783DD8A66A0F4E7ULL, 0x88509B3AC8650467ULL, 0xD523F6C359A91833ULL, 0x1C8B35550D44E5B6ULL, 
            0x169F986A24E22A5BULL, 0xEB57C35330D06D6EULL, 0xDA1EC8F5ABF2A162ULL, 0xF3897A26AD3376A2ULL
        },
        {
            0x79D64B55081126B5ULL, 0x36142B5C8D057C61ULL, 0x21EB41E9D77C1E3CULL, 0x25B4F724C4C6DBCCULL, 
            0x793DFC2F987A4DCFULL, 0x7E821BAD6D643C55ULL, 0xAD6789406170AEB0ULL, 0xAA291C505D77A8C9ULL, 
            0xA0ABC874D479D02CULL, 0x5F1653599A4AD956ULL, 0x34749B14020F6495ULL, 0x40BFACD8F85C37D3ULL, 
            0x5645B642C98D0A48ULL, 0xD5DE35A33F91BFBAULL, 0x76CE243B406A5BF6ULL, 0xA5AF4430D41667B7ULL, 
            0x0D33B3A4CDD91CA4ULL, 0xDAAB1DD3BC619E30ULL, 0xA42333FDD1B02581ULL, 0x4F410FD5262A4E81ULL, 
            0x635B4CB29BC7A0DCULL, 0xFAFDACC3196058DDULL, 0x8670A2A9DFF1166EULL, 0x5B9EE85C7F4B4CB8ULL, 
            0x7593E918BBCBE462ULL, 0xCE954DD3A9360A11ULL, 0xA7BD11C4B720F9FEULL, 0xFD52B4D9F9D441C1ULL, 
            0x6808390581F3096DULL, 0x996CBCB5F8ECC775ULL, 0x29A8C5F3E5D919E5ULL, 0x88DD0DC836AC9C50ULL
        },
        {
            0x2E3872D26EA3424DULL, 0xDC86262AF3606B6DULL, 0x48F83F5B9252FF9DULL, 0x1AF809A7238708C7ULL, 
            0x55FC9D87704B3A35ULL, 0x91A907E13784B2B6ULL, 0x52EB1E5E80733A32ULL, 0x26E608EA86CE9B87ULL, 
            0x8322B5C3EB2FC40AULL, 0x1CEFD9DDB2FA7732ULL, 0xD5355ADB0B721EF8ULL, 0xC3699059E6E41EF8ULL, 
            0xA5F45DD814B55894ULL, 0x3D5B67A04DDA546BULL, 0x7E0233F55DA04FC3ULL, 0xB96B24B80890C8D9ULL, 
            0xB514BEBE720E03DEULL, 0x3D2CC2853B1222E4ULL, 0x88A1117493ADEBDEULL, 0x168FEFFFABC07950ULL, 
            0x97095A057A7F67DDULL, 0x227699B5934568E1ULL, 0xC7B082790151FECCULL, 0xBB7BEE5B3CE966C4ULL, 
            0xD2B9F52F750933F4ULL, 0xC8FC093BF5CDC9C0ULL, 0x3B9291E98DE1DE71ULL, 0x9B4A8A0C674B19D1ULL, 
            0x3ACBB8E94A34A7C6ULL, 0x498684BEFE9476DBULL, 0xFA47A8DBE304AE7CULL, 0x78B5D221BFD27988ULL
        },
        {
            0xA73AF8640757BBB9ULL, 0x4993C053E38F6901ULL, 0x99B745C56E6FDA2DULL, 0x1C870D5FDA1A7368ULL, 
            0x23941149C93DDF91ULL, 0xD25C6D953C9A33C9ULL, 0xB036AE6104F32ADDULL, 0xDFCB2E0D90D455C5ULL, 
            0x357F05D1F3C2D6A8ULL, 0xA846F3EA1B08C088ULL, 0xBA7E4DF8B0CFA723ULL, 0x8413B98CFEC598D2ULL, 
            0xC59D70A89B3FF582ULL, 0x5451BA568DC11674ULL, 0xB75C1E52DEEBAA1FULL, 0xF525696123FAD66AULL, 
            0x3FF4FF54ECEEAF99ULL, 0x6F34D46F878BFD02ULL, 0xD282145B02DA69DBULL, 0x14CF408946D5611FULL, 
            0x2873B8A8573A1EBEULL, 0x6B84099E214D4D64ULL, 0x07887BC21DEAFA9AULL, 0x50B619167EE9C255ULL, 
            0xEAC370B2B44106F4ULL, 0x2EB706DC95C26927ULL, 0xBEC204810E9D98A9ULL, 0xD7E414AF5CF8277AULL, 
            0xD00EFE7278501153ULL, 0x37B104A806FB735CULL, 0xE9EC662EC4B47162ULL, 0x28D9222B657A3CD5ULL
        },
        {
            0xE4F73AFDFDA606BFULL, 0xA0578B73BACAB734ULL, 0x455309F0AA746265ULL, 0xE56E0CB2EDF65AE8ULL, 
            0x21B8ED6004B28334ULL, 0xA0EFC81AC2C9850AULL, 0xDE3C386FCECA0203ULL, 0x46D7E729D031C082ULL, 
            0x4EBCD6F4435DCB18ULL, 0xAF428C5B51E32F62ULL, 0x2A1017FF35AFAD90ULL, 0xEE061CE22A0E4743ULL, 
            0xF15493C8691F16BBULL, 0x00560EB41D31DB81ULL, 0x2EC149BCFD0F8D9CULL, 0xC75703B06D3EEBD6ULL, 
            0xF7047EDFB06E9F51ULL, 0x4DD3B515337682F4ULL, 0x0A100BB52752C83AULL, 0x8EFAD33734A37C1EULL, 
            0xE156AFDFEFDF775FULL, 0x58631DD864247312ULL, 0x4D75695C1D0D97DDULL, 0x4536830957E1D6BBULL, 
            0x7F562129C73B29BCULL, 0xEF5BEA76DAB67FCCULL, 0x5BF822F5AF6B9CB8ULL, 0x3F898A69D0FF2D57ULL, 
            0x8010B30F9C071E4EULL, 0x17024D95AA89D10FULL, 0x28A4B621B268034BULL, 0xD921EAEB80762666ULL
        },
        {
            0x5A59C87A5CD667DEULL, 0x85DE8F6AE0C0CECFULL, 0x862B300CD4AF0F20ULL, 0x5B1B744FFC1BAD1AULL, 
            0xABCEBBDECB64F03EULL, 0x315D6025CFD37C3EULL, 0xCA2230B9EF58108BULL, 0x4CDD89F0CAEE9702ULL, 
            0x191EADABABE05028ULL, 0x0C02583A715FC526ULL, 0x3828AC18A7516EA6ULL, 0xA7D1B4B6D1E8E26CULL, 
            0x43587AC35A2770C4ULL, 0xC81B662528F8F9B8ULL, 0xA9C1B514A6D02EF5ULL, 0x61D6D5AFCC8C184CULL, 
            0x459E1D506491DB12ULL, 0x2D04329D336EEAE9ULL, 0xCCCD20CC02AD99D6ULL, 0x606FFB2614E13CB8ULL, 
            0xF52FCBAE76961BDDULL, 0x513C4BF85CE49219ULL, 0xF6EF1130C3AE038BULL, 0xF3BBAD30014B9897ULL, 
            0xC79469620005BF4FULL, 0x68D466FA80FD17EAULL, 0xED901F7D0D834355ULL, 0x1B7FEF1E3485F03BULL, 
            0x0642008637BA78BEULL, 0x4DC9D61BFF070074ULL, 0xF2F53F9FA91C59E2ULL, 0xA83C20B9D0641B93ULL
        }
    },
    {
        {
            0x4E685510ACE2DD8FULL, 0x3BDCB15462DE0A1FULL, 0xF162061808809A5AULL, 0xC938034759E9EA85ULL, 
            0xF28EE72C3B0AE0EEULL, 0xE406A115BAD1E0C7ULL, 0xBA7D3D91C7C385FAULL, 0x763E2B1F313F8256ULL, 
            0x304776702021377DULL, 0xA4815841AAF6A6AEULL, 0xB848F14C4D5C77B8ULL, 0x70BE29EEDCA8EE8BULL, 
            0xB742B8A1740A6BDBULL, 0xF719D55EC1544E26ULL, 0x7ED4D38141A082A1ULL, 0x501E166A99B7A6A1ULL, 
            0xAE7A68AE52FC27D3ULL, 0xFC7D037F7B1CA3DAULL, 0xB6DF272D20C40ABCULL, 0xE3C3C2F60883ECC7ULL, 
            0x1401CD4C2FDEBEFFULL, 0xB6F7495DA6E1D2F9ULL, 0x77BDEED784888E32ULL, 0xCCA13F731A85D51FULL, 
            0xB81BF0E68517299FULL, 0xC16D8C8CF5120FF4ULL, 0x5FD01A33823300DCULL, 0x6E9001C4AC97E2E6ULL, 
            0xB4DD319CF8C60CBBULL, 0x2AA028E8E0E5A77AULL, 0xB6B82AEE8D3B550BULL, 0x2F428CDFE681FFC9ULL
        },
        {
            0xCEFD80C97452AEE8ULL, 0x2F7DF7A4745F6755ULL, 0x3EBD1EC86CC3E597ULL, 0x4CDDC35D5C1B5C43ULL, 
            0xA30D1E35F472630CULL, 0x19ECFDFC14D76276ULL, 0x26B7CF9E0A7E1799ULL, 0x1483BC1C253B36DEULL, 
            0x9FEB1875F40962B2ULL, 0x33B83559743FCA02ULL, 0xE47B64D9B70E7B31ULL, 0xB1A6FB1A76057090ULL, 
            0x03039D8A5255328DULL, 0xB2AFF019BAA2006DULL, 0xA72E08C74E1396D8ULL, 0xDC53066029EB4E69ULL, 
            0xFF460C23387CCADCULL, 0x545DD172451BC65CULL, 0xE392D69279BFD078ULL, 0x000B193CFE86D244ULL, 
            0xD69849B975C2B605ULL, 0x38C3DE36934A199BULL, 0xB969FA9CA84D80A5ULL, 0x9B9716ED6655A3BFULL, 
            0x978924C6F9A91985ULL, 0x96276132499BC5C8ULL, 0x845DC9A0DDE42193ULL, 0x4ACB117C50042823ULL, 
            0xA7C1B3F256DB2A89ULL, 0xAFCAD10A535C93C9ULL, 0x1C4BC0E11E1A8D00ULL, 0x4691ADA8EF4DAD00ULL
        },
        {
            0xB1677F468C08DBE8ULL, 0xBA9490E971169E24ULL, 0xD8ACBBAA1BA5FF40ULL, 0x1635A3CFA516113EULL, 
            0xB9B0AECBBFC6B4ECULL, 0xB82BC4C13BB531B1ULL, 0x3BB5F49B76D53A5CULL, 0x36DC2955418F5FBAULL, 
            0x7AE4FAF2F2E80D3FULL, 0x3962AA9113B20770ULL, 0x9263E63497A61369ULL, 0xB84B6D55BE11FD53ULL, 
            0x21BAA74C78F7E99DULL, 0x2780234CBAE900B5ULL, 0x96C1B6926AB18DE1ULL, 0xC6433B29F0F53212ULL, 
            0x83C40B14E5449EB0ULL, 0x494F5EFE70187F1BULL, 0xA13D4537B4EF1F13ULL, 0x86708F40A0646813ULL, 
            0x4313897499507D81ULL, 0xF488921D75C92477ULL, 0x59B91F3B925D9F84ULL, 0xBEC246BE4E56B028ULL, 
            0x4D62292BD7DE5F6FULL, 0x86F431C7C867DC91ULL, 0xFB7EA58D822DBBD5ULL, 0x793684B9CFCD83CFULL, 
            0x18E29127AC6A8B68ULL, 0xCBA87426C4A19405ULL, 0x3B0DA74B3C541600ULL, 0x74F16B528CA0B320ULL
        },
        {
            0x338218630EDAA813ULL, 0x3E484DAAA92ADB31ULL, 0x521664EFF608294AULL, 0x86EF745EC7AFBC9AULL, 
            0x6FD6F9580F6E441EULL, 0x2AD1B3F1C5E76935ULL, 0x9A83884F3FFB2EA1ULL, 0xE23A018FA65A0193ULL, 
            0x0392AA625B9FB75CULL, 0x3ED3B5A9B46D2FA9ULL, 0x43EA4B413851336EULL, 0xBF32C87520CC641BULL, 
            0xD56ADB7A2A4CADD0ULL, 0xA9BC5971BBD96C41ULL, 0xED735FFB8D44C1EAULL, 0x26CC2A49C674DD83ULL, 
            0xBF3D14EDFC480A00ULL, 0x994534DF7DC7AF51ULL, 0xE2B76392E7BBE1E3ULL, 0xB56B1A975EA185BDULL, 
            0xA0DB328413202CD9ULL, 0x7AD4AC401DEB0C30ULL, 0x9991825763EDAA54ULL, 0x5F56C580870999CDULL, 
            0x26E353E71E06B704ULL, 0xD0A573BA4FCCEC7DULL, 0x4187FCF3D6C5F47EULL, 0x2F80500D3CBAED78ULL, 
            0x99393EE4C439C461ULL, 0xBB00B67F31F3EF0CULL, 0x09657F8BCEFC6103ULL, 0xD6AB582520A70FF0ULL
        },
        {
            0x75C15AD0DA830DD0ULL, 0x5281FEA0396E951CULL, 0xD690784FE8B68C9BULL, 0x8FD3413C9EF80B7BULL, 
            0xD179F6F223016BE6ULL, 0xBAB1082F8F6FA721ULL, 0x4D34F2158D259A0CULL, 0x88152A81C8A9EBF8ULL, 
            0x1CCC8D3D250392F1ULL, 0xD362CE7EEC0C51EDULL, 0x67DA2A3A62F4FBDAULL, 0x3B07F1B2C5B4993CULL, 
            0x29058BF2EA979517ULL, 0xA872C27765F18CA7ULL, 0x1FA943CED22B2523ULL, 0x0F98DB194229785EULL, 
            0x17287A896A5045A7ULL, 0xAC6E68001C92AE7BULL, 0x27CD9817DA20A6CFULL, 0xEBA842F0DE1AAD72ULL, 
            0xA5C97BBFBAA36613ULL, 0x08345144378C6315ULL, 0x4AADDD757C6A2A71ULL, 0x041321832CBBE0F6ULL, 
            0x4DF4F94F0742832DULL, 0x98217323973D8932ULL, 0x85404AE4905772DFULL, 0x3EA8FA7C33CC13BDULL, 
            0xB59205D31F16A715ULL, 0xB23D589F69C1EAB2ULL, 0x9C04CE4EC09530FCULL, 0x2ACE699D09DA9218ULL
        },
        {
            0xE501968768F45524ULL, 0xDA9161BBDEF8F625ULL, 0x735C7B2DFBFD3913ULL, 0x9FC6B529B77457F6ULL, 
            0x1103AF157B94DC79ULL, 0x56666E130C037D3BULL, 0xB47C33FBA2933B2EULL, 0x55C9FEE7A4313604ULL, 
            0xCED30A54403ED0AEULL, 0x1DC9ABF7005ED951ULL, 0x3629FA0C87CD22BDULL, 0x0E0302CF7BACB382ULL, 
            0x12AEA7CF66F2CD19ULL, 0x58FF00E36A06EF54ULL, 0xE4970F509253E8CCULL, 0x34C704751381D4ABULL, 
            0x0CE59903AA97905FULL, 0xE3372D402BD0A696ULL, 0x1D7BC1F932E9A234ULL, 0xB8C8084E7679A73CULL, 
            0xD07A313AB22EB39FULL, 0xFA10467CEAF9D927ULL, 0xF88D45DA534D5004ULL, 0x1270BB71983E7EEFULL, 
            0x41C7432C8C3DB3BAULL, 0x5BC1CF642D0997B4ULL, 0xD3A9C5FCFFABAFDAULL, 0xCE1DDA34716758E8ULL, 
            0xFF0FFA711BC157D7ULL, 0xD25D03E9E58BB337ULL, 0xA9EA189E42CFCDF4ULL, 0x1074B372C4BFB460ULL
        }
    },
    {
        {
            0x282FACAA02888136ULL, 0x9C8F9FDA97251EE2ULL, 0x6F119B39CF57BC2CULL, 0xAEB06EA2E3DB58B3ULL, 
            0xF89C2F9C9BF7AD42ULL, 0xDEA72148EC04DD62ULL, 0x7E9B7145C050E545ULL, 0x3394604A14FEF3CDULL, 
            0xE99E3F09D0CDE3C2ULL, 0xDB14E460D30C475BULL, 0x299E74EC5114F397ULL, 0x37AC8C5C7CC38632ULL, 
            0x69B7C8175694565BULL, 0x0A320E75F51EF771ULL, 0xDBE8AD6ECF5D6CE9ULL, 0xE67A41D9D3912CE0ULL, 
            0x791FBC0DE4F93048ULL, 0xC2E78DD449C9DCB7ULL, 0x42D4747BA8B11BE7ULL, 0x7050712084E515B3ULL, 
            0x72FA47004FB1A5A6ULL, 0x57A5D01B7F073D82ULL, 0x6C6620B5C403295AULL, 0x1CE614B2F9633DF7ULL, 
            0x2A56393D9EBA1B92ULL, 0xDE14BD501307738EULL, 0x980F55C3B579B965ULL, 0x62BE25F858457258ULL, 
            0x576DA617913C83F9ULL, 0x9F6F7A41748A3B1DULL, 0xB11372F59DAEBC76ULL, 0x05E22CBA5E4EFEE6ULL
        },
        {
            0x8FBE3C2EA90E0F8EULL, 0xB5F461F353D6CB3CULL, 0xC84AEF584509AC2FULL, 0xA8E9F0FF108A2F83ULL, 
            0xAAA545960D4FB4DDULL, 0x0C36F842400779BDULL, 0x197135058C2CDDFCULL, 0xF2F9CC838FF109B2ULL, 
            0xBB1156AB36BF959BULL, 0x53A2F9D8EB4B5EBAULL, 0x6B090AD0478C71D4ULL, 0xDB6204F85BFD60E1ULL, 
            0xCB0AF78A29FC5F30ULL, 0x415555ACE4C55AEDULL, 0x887691829734D93EULL, 0x2E4E92D0642B674BULL, 
            0x4B4B8721F423E836ULL, 0xEDC1FC0C77B6B0D0ULL, 0x44DD6F27833FF711ULL, 0x9045D1712F587CF7ULL, 
            0x9B66BF2A5011C197ULL, 0x221E199E7FD8D973ULL, 0x18B98FEC9320657AULL, 0x4C989BDE68378F07ULL, 
            0x4EF57063F5B69E08ULL, 0xA5DE0670370722A5ULL, 0x0F7C3FC0EDD3437AULL, 0x78B28C98050AEEF8ULL, 
            0x29A029C51FA35FA7ULL, 0x607E1F635C4ED2EAULL, 0x40B4E142E1129A9DULL, 0xAE30BB5F774AC1CBULL
        },
        {
            0x26B82464B1D8EBE6ULL, 0xAB4DB232D7D5D25BULL, 0xEFD28E1D3E97A8CCULL, 0x5BEEF2822A71710AULL, 
            0x399DC226847372D0ULL, 0x8E6D81FE951C5119ULL, 0x4C48B8E1D4517A60ULL, 0x2AF717466B9B2E5BULL, 
            0x76EB26211BE88E9DULL, 0x50FF001FAA1DFC74ULL, 0xC014C2492603F5A5ULL, 0x31FE03B99DAFB227ULL, 
            0xBEFFF36FA8BE350DULL, 0x7AC8505930AA6663ULL, 0xD8739282BD6BA88AULL, 0x1338BE8F2A47D31BULL, 
            0x397221251C991DB7ULL, 0x99DE5A9C8D4EDF90ULL, 0x6CF9042382B124E0ULL, 0x501011EFE86BD0D8ULL, 
            0x54F7FF6B2AFE7B86ULL, 0xA07AA99EEBF0F5FEULL, 0x9F22AAE1504C98A2ULL, 0x23F90C124EA71130ULL, 
            0x452C1D40016B1CC2ULL, 0xCA7F72E6123483F7ULL, 0x85B742B9C0098F16ULL, 0x5E78FC395AB2FCEFULL, 
            0x96558E29F4CE7888ULL, 0x4F64D5A9765EFDFFULL, 0x757C9BF50C76E105ULL, 0xDBEDDF7F04243BD4ULL
        },
        {
            0xB1985AE56065B815ULL, 0x3F00557A05B5893BULL, 0x2ED53CAF7CCC0195ULL, 0x401355E1410E5137ULL, 
            0x1519BFEC11DC44B2ULL, 0x3D600AE375068BE3ULL, 0x11DC39494EE2A426ULL, 0x12AC5C8F2655AA01ULL, 
            0x0FA26EED5325A4B6ULL, 0x886912029DDBD9B8ULL, 0x45012F337E6BC536ULL, 0x28F973C97D1262D6ULL, 
            0x0A9B78E5BFF3F54CULL, 0xF2633D35D010C394ULL, 0xB31B71337A4E9946ULL, 0x10BA4872058BB63FULL, 
            0x3E0CD87A18497B2CULL, 0xC3C87F75C3D7DEA2ULL, 0x4D64487F3BFC8B97ULL, 0xAFDC6D394BD9571FULL, 
            0x087F02099D024E3EULL, 0xB99E2369A7225A7CULL, 0x8B9CC9C115EA75EDULL, 0x6982D9769316389EULL, 
            0x509A3001FE059BE4ULL, 0x091FA8761A5D1399ULL, 0xCFEEB121D6655FBEULL, 0x346D1CABAA1D2EA9ULL, 
            0x9270624174130A0FULL, 0xBED05480A85286BFULL, 0x8453B17ACF3917D8ULL, 0x1DE0A8BBFEE74614ULL
        },
        {
            0xB8A639D52C679EFAULL, 0x7E385A2F8BC86E84ULL, 0xD1A0F4A9B6F2D123ULL, 0x6A5311B4A1D86E1AULL, 
            0x4566A212195C7A9CULL, 0x2A00B2B6242C5FF3ULL, 0x56214110CF771C58ULL, 0x02E3373C15DEED88ULL, 
            0x9B2F688CB4C0B95CULL, 0x644EF53D204427A5ULL, 0xAD1B5C796A8599AAULL, 0x805ED30013079063ULL, 
            0x73C87A9B984FA461ULL, 0x44BBB6E9142C877AULL, 0x3520FAF3F6C9AF0CULL, 0x86F42E5FAED3B708ULL, 
            0x95D1D133B328C3AEULL, 0xBAE77ACF53BC7550ULL, 0xC5B0F2D78DDED18FULL, 0xC91DB6863E9DFCD5ULL, 
            0xC960CACEF0B401F9ULL, 0x3B0304D6102610A7ULL, 0x5B90B76C3571A97AULL, 0xE493CDF3FA673F9EULL, 
            0x6F945135CA4A640DULL, 0x4EA248B0C771BD4BULL, 0x9D23529010BD4AD5ULL, 0x2FD3F122A8AE3D2EULL, 
            0x938372121896FFB2ULL, 0x70B57C553D9DC21EULL, 0x44C4A98D52150C30ULL, 0xB54CDC0B588AC25AULL
        },
        {
            0x43D33FB8F0E4D63DULL, 0xA6CF31C1E6D0CB51ULL, 0xC63FBBE3B0F36BBEULL, 0xC1841B93A1983EE2ULL, 
            0xF657A5F48407048DULL, 0xFCBC03F400DF5510ULL, 0x5510B5ED2E21EAB2ULL, 0xF6250C858D69B529ULL, 
            0x7F9B669E0A4447A3ULL, 0xD22DE02152818FF5ULL, 0x8BDE121A05BD9E79ULL, 0x17EEDA2F715D64EAULL, 
            0x0E460A47D8292F42ULL, 0xE190FE8BBF79F508ULL, 0x223E3154FDCAC460ULL, 0x23D1E7E2BFE7F08EULL, 
            0x58EFDF332B062477ULL, 0x6A58B040552E28ECULL, 0x65B8F34CBF1EE902ULL, 0xB0C28E3E1EBE65FAULL, 
            0x7A687D3CB8515898ULL, 0x2C74C837E4749E9DULL, 0xD9C2506B5039F5C4ULL, 0x507CC21FBDD95239ULL, 
            0x56F3B97D8D89ECC5ULL, 0xA97C7EE3EC07B36FULL, 0x87A606AD0E2D209BULL, 0x7855F49F2F9335DFULL, 
            0x05E6893AB29F08B9ULL, 0x94778CB14B6EA43AULL, 0x42D4D236CF3C0F7AULL, 0xA92CE1C643CB02DEULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseBConstants = {
    0xA5FC4D17B477D6F8ULL,
    0x9BAE7562F39461D1ULL,
    0xDC2DD6E90CCFF866ULL,
    0xA5FC4D17B477D6F8ULL,
    0x9BAE7562F39461D1ULL,
    0xDC2DD6E90CCFF866ULL,
    0x18B3DFC2E317E05EULL,
    0xB08DF8D32370C3A2ULL,
    0x2A,
    0x69,
    0x6B,
    0xBF,
    0xC0,
    0xDE,
    0x75,
    0xAB
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseCSalts = {
    {
        {
            0x589187915302CEC6ULL, 0x7DAB17163DBFD2BBULL, 0x343454255D5AA5DFULL, 0xDDF8B6D52EEA94B8ULL, 
            0x8A6A42FE84C6E6B4ULL, 0x9C414DED92B37573ULL, 0x690D736E0C1FC06AULL, 0x526430A2B5F927CEULL, 
            0x27C03CDCAF61E038ULL, 0x83473C0B2C60EEFAULL, 0xA89E8F3D85824658ULL, 0xEDEE97A0CB287536ULL, 
            0x27C6581B1D2A1431ULL, 0x26DE948A902B749DULL, 0x32AD3FF169238A26ULL, 0xC070146AFEFF6DCFULL, 
            0x6D87D71A387BBA79ULL, 0x622C9574B666ED35ULL, 0x406635AFDB98C6ABULL, 0x426B46601859BE08ULL, 
            0x80004380A129E7BBULL, 0x27F2E2D9A201A340ULL, 0x968A3C10C904DB02ULL, 0x576158B0D8426D53ULL, 
            0xFE31CF86B3DF9276ULL, 0xBDAFF7FCEDD18BACULL, 0x974DE25541C2153EULL, 0xA3C181B16461A913ULL, 
            0xEE3497828C65444DULL, 0xD8C37CAB52C1FE4FULL, 0x9194FF6ED8717916ULL, 0x23BF3EA81A2E8A9EULL
        },
        {
            0x2D6EE690A753DE7AULL, 0xD21D08C50D0DF59BULL, 0xFE7E868ED1125D94ULL, 0xAD574FAA46739B3EULL, 
            0xF8C8D2186CEBB457ULL, 0xFE1A81952982D952ULL, 0x5107A0AC9DDB5486ULL, 0x7AC9A94FF5DEAA7AULL, 
            0x22B54A1F900E3777ULL, 0x9AD6B6CF170DCA78ULL, 0x6822E07F6E598645ULL, 0xA4A322D16D38D63AULL, 
            0x3A2FE8A18F02E1A9ULL, 0xCF10CC737FC90203ULL, 0xD1E7833803E79FCCULL, 0xD51B85FFAD1F2729ULL, 
            0xFD86C4EE89FDD349ULL, 0x87DAA379938405D3ULL, 0x8DDD9215C83DE3BDULL, 0xEDEABAEC7D802B8CULL, 
            0xED498ED86C414538ULL, 0x14B872531330D7F3ULL, 0x273D8B9B2F478480ULL, 0x2596E476E2E9F898ULL, 
            0xB8E3515B6251F086ULL, 0x51B10BFDF1F04F6AULL, 0x0AC68756C37160A8ULL, 0x78CA5B3B31DAAC43ULL, 
            0xFC7CA13F2EF029FCULL, 0xE72E3BF7D32B5838ULL, 0xEBEFC6A9F35B458AULL, 0x202D2FEB1F31881CULL
        },
        {
            0xB671FCAFEBF9EC4CULL, 0x768AB7C442064D11ULL, 0x59D35FCEF13AE359ULL, 0x10AE7A342CB53B6AULL, 
            0xB16B6CA69963B4A1ULL, 0x95441561AB43C1B3ULL, 0xF0BD356AC08EC8D7ULL, 0xC09053E463C7840DULL, 
            0xE65592020E7B023FULL, 0x675B62C52F46CD4FULL, 0xB2D92C829FA66B23ULL, 0x2F20CFEB799569AFULL, 
            0x1EBCA2501CA58249ULL, 0x19B58F910718240FULL, 0xBC2FF2D6AA6F9614ULL, 0xF3F7B900B1446007ULL, 
            0xA9D854E0944D7945ULL, 0x8F8D9482738EDBBBULL, 0x8316F648AE8CE8A5ULL, 0xE7465CBFFC13EB57ULL, 
            0xD55A6BF0B8CD3B7CULL, 0x27924D4AFD22B623ULL, 0x0F9BCBA0AA6042D9ULL, 0xADDF5C155146AD8EULL, 
            0x18C7DEA733E1FFD1ULL, 0x0AEC6DE414694EF0ULL, 0x5D39950C2C775ED7ULL, 0xCB54D8C2F9A96DC6ULL, 
            0xF5DDE7227EE994FDULL, 0xF08353BF9795EF39ULL, 0x8D080A884E6C6EAFULL, 0xD4C038D5F63FE81DULL
        },
        {
            0x28AF5D78C33AD2D5ULL, 0x7D0FEDACEFB37A50ULL, 0x58AC858CD2095CA8ULL, 0x124BE325A8F47CB6ULL, 
            0x39F30685AF7E9017ULL, 0x7D2773CAB4736A1FULL, 0x5E6FE724DC7AA584ULL, 0xB13DF1D29615BC23ULL, 
            0x094FC2517990A0D8ULL, 0xD59E220DF1B9B296ULL, 0x70198C86B96D71C6ULL, 0x774E2793970C7893ULL, 
            0x20ED9448756B0CBDULL, 0x3D403D89DDBEE99CULL, 0xEAD93205B4DEC78DULL, 0x0C9EB0C01C0CD378ULL, 
            0x642DAC758277C7E5ULL, 0x7C7712401039796BULL, 0xD3674175B3542976ULL, 0xB4C990D5A2AE2628ULL, 
            0xA5943AFBF33A50D8ULL, 0x3F177011A7D44434ULL, 0xB7C230B763A17CE8ULL, 0x5E2A83B10A9F3982ULL, 
            0x94A0D14C0DF4400AULL, 0xC851C472AE0C715DULL, 0x734BBBBD233004EDULL, 0x9507CE60EAB18315ULL, 
            0xB4B01888A8E37DAEULL, 0x7188274DE5BD8440ULL, 0xD7454417BCE1FB01ULL, 0x1377BEC0BE2AE06DULL
        },
        {
            0xC5D7517EC46FCAE5ULL, 0x47145405C7BDC81DULL, 0x3A7DE512B0163A83ULL, 0x3046C1399C2B124CULL, 
            0x0CEB34D33586736EULL, 0xC0C79A097E75A7D9ULL, 0xE67F4357E26D3696ULL, 0x8C13CFE94931A6CDULL, 
            0x5151A591B7F3505CULL, 0x561CC1DEEF250A99ULL, 0x7C189DF941C52DE4ULL, 0x8BB73393DBE28AB0ULL, 
            0x2D05734BF23C4431ULL, 0x10133C187FDBB3B2ULL, 0xB99B987B5972091DULL, 0xC74D2DAAC2EE8A59ULL, 
            0x1FCC3E3EC5627CC0ULL, 0x31E863858DE71E85ULL, 0x50A74DA18BC99AD9ULL, 0xD7252F083405B7F7ULL, 
            0x6F570195EBF84A4EULL, 0xB8D30646F9627D8AULL, 0x436762BE1CF53726ULL, 0x7DC50E282668DC83ULL, 
            0xE39A611A62BFFDE8ULL, 0x552082FBDE33B3AEULL, 0x9289313B1013CBDEULL, 0xD35AE09C2C2EDF27ULL, 
            0xD54CBC60C36BECF4ULL, 0xE409327F0CFBA0F0ULL, 0x8B34D315ED5310ECULL, 0xB12E19B3DDA07EA9ULL
        },
        {
            0x34E1BDD102D07E10ULL, 0xDA30985A9791D9D2ULL, 0x9EB86FDA5D7D49FEULL, 0x47FE59485E07E828ULL, 
            0xCEA29F0D8EAB6CA9ULL, 0xE819D8DD554112CEULL, 0x22EFA70453FD22B3ULL, 0xC29F1031D9D88224ULL, 
            0x802F0342185A74D7ULL, 0xE2F3CBB432C37BA4ULL, 0x27D51D3261FEA315ULL, 0x50F30C8547E2EA4DULL, 
            0x95628C5A3473BAC0ULL, 0x54523CA61E50DFE6ULL, 0xFA0351BB5ABC6E89ULL, 0x8F2C2847EB9B5F72ULL, 
            0x765FD6007B26CD5FULL, 0x7F3CF46E28FBACCDULL, 0xB30010AA5283074CULL, 0xFC24475F2407AAF9ULL, 
            0xB20CD9C09125DC73ULL, 0xAE7373C1BE4DD603ULL, 0x897CC64E81807985ULL, 0xE1F0FD66CE8311F2ULL, 
            0xE92F1E9B80DF51B6ULL, 0x9215A3A0E2C3CA3CULL, 0x40DBF74F2F836675ULL, 0xDC5A7896E6ECD119ULL, 
            0xD94FBF3097B42D3FULL, 0x96D3E3359CB44559ULL, 0x7240D0D74AE53A0AULL, 0x57EEC293800D6492ULL
        }
    },
    {
        {
            0xEC1E51F8A74CA2F3ULL, 0xFA188E5E5ADDFCABULL, 0xC648331B265E1224ULL, 0x6A0419EE2D0C9E52ULL, 
            0x549D5D5BCD63596CULL, 0xF18ED5B84F6783E7ULL, 0x1D7EF6D90131205EULL, 0xDC95A5378FB1D513ULL, 
            0x929D0676A4FE706CULL, 0x7E9061E841C2BEE4ULL, 0x3AD31E32CD4015C1ULL, 0x413C4896D7C82EFFULL, 
            0x568C244AC9744F84ULL, 0xEC2A53C71C5BDCA6ULL, 0x372A5EF2D7D62F10ULL, 0x6D8606CF2A06BFBAULL, 
            0x76E418A8462C1949ULL, 0xF07898965FED6D37ULL, 0x180A3B8E6C21BFADULL, 0x23D72FE64C61E996ULL, 
            0x9B956A8E20CDAFADULL, 0x9E4A505E9E66C2A5ULL, 0x50EFA206889DB807ULL, 0xFFFB2303E88C5EB0ULL, 
            0x29268A37840CC8C7ULL, 0xEB01A071E8B00C07ULL, 0x563E631123CF96BAULL, 0x911CB4B58F7CE8B0ULL, 
            0x426F20D7FEE02E85ULL, 0xC8EA9E92ABDDCF1AULL, 0x6DC5B9C3C57763C0ULL, 0xCADFBAF2A13D3D0CULL
        },
        {
            0x7BC3086C3E8EC207ULL, 0x6B6DF334997E9A20ULL, 0x0322A72A4E90CC8BULL, 0x462D83591498EDFDULL, 
            0x6B69CD95B6FC56B7ULL, 0xFA29F246A8E9FE30ULL, 0x86FADDF9655F0194ULL, 0x7BC8573ECBAB4183ULL, 
            0xD8265472A53868B1ULL, 0x0DB4E210A554905CULL, 0x63739DDB6F711908ULL, 0x5F775EF36A9EB0A3ULL, 
            0x48058231D96F23D6ULL, 0x8F8DD52983AEC4C7ULL, 0x2211C2F70B95165CULL, 0x48DE24AA233C47E7ULL, 
            0xA60A8DA07EA4E4C3ULL, 0x62B0037D7A05AEB2ULL, 0x0EF6D0F84BC13DECULL, 0x9DBF83E1CBC33862ULL, 
            0xE2447676951F737FULL, 0x05E30F8D7054B51CULL, 0xA93DA556D1784104ULL, 0xC7ADB6D4E1DA185FULL, 
            0x39AFB85B2D07034EULL, 0x9BBDC6ED869E1975ULL, 0xBEA8380D8EA7C0CCULL, 0xED53D54688E5C4A1ULL, 
            0x8BD6C2043D0D633FULL, 0xFB204F1C50ACD532ULL, 0xD640E1DEB4EE8C11ULL, 0xB7CE20CDA1616D49ULL
        },
        {
            0x35F35E50341F5C00ULL, 0x713AB0D644F4275CULL, 0x8A807B14025E63EEULL, 0x857AAA84DA195791ULL, 
            0x93F0CAF541785ADAULL, 0xA7D67B62F9ECC90CULL, 0x61BD873C960F4308ULL, 0xB2EC5EE9D848D48CULL, 
            0xB36CC64F022DD81FULL, 0xF45EF4D9C22DF7E8ULL, 0x199C25F9FFDE7637ULL, 0x3C8DB29D854155FCULL, 
            0x4CB726ECB6A21A3BULL, 0x279799948638AB0AULL, 0xCEE0041E4918E3ECULL, 0xC085A2DDD6415009ULL, 
            0x717EC692FF3E5942ULL, 0x2B528A2F4BC1B0AAULL, 0x57B1EDD3CF85C4B2ULL, 0x46CCD92CDD74C74DULL, 
            0x4A08C4DEE72B50C2ULL, 0xBE5965C262D81E99ULL, 0x13CEA942AE297AEFULL, 0x6B13B3EBCC78BB1AULL, 
            0x1100FD3F4184F394ULL, 0x24560CFF0184BFF3ULL, 0x44EB04250CC1F3A9ULL, 0xA8A9F6C41212E01DULL, 
            0xD9505AE073224FBFULL, 0xCDE460709921D0E6ULL, 0x8B92582D6B56BE5FULL, 0x7D5C898182DFF8F2ULL
        },
        {
            0x6F7658F42EB56F2AULL, 0xE6DCB2D59151F1BDULL, 0x99133FEF77AD3BDFULL, 0x0F43E8FFF78E6265ULL, 
            0xA64084FAC4F90305ULL, 0xEC6D4B62A401AB71ULL, 0x952E850398D97294ULL, 0x23E744E0564C56BFULL, 
            0x8BE7E358ECD8D69DULL, 0x06A3E6EBCBCCD7B8ULL, 0xADA214CE3657A12EULL, 0x8D99C3031D8B6E03ULL, 
            0xE27EA719DBDD7076ULL, 0x06D1C379D711FEF1ULL, 0xD0AF47DD61E983EDULL, 0x1C9E7E00FA0AA261ULL, 
            0x1A3CB3F3E92DA136ULL, 0x47E44924F8859510ULL, 0xD61E693806E0BFAAULL, 0xC3EADA1AA21047ABULL, 
            0x1F02CDA442D33C47ULL, 0x5202B963C68F4FCAULL, 0x4394BCDED21EF617ULL, 0xD210BB27C483D1D2ULL, 
            0x4F7214BC8E7A75B5ULL, 0x06916FE5C889313FULL, 0x3B5E4EE242D7BC7FULL, 0x9FF20D5146341712ULL, 
            0xAFDB7CA396EF2D28ULL, 0xF81E50BBC4DEAF3AULL, 0xD1355F82F041126CULL, 0xA526D211F013ECC7ULL
        },
        {
            0x54D102F617643B3BULL, 0x612CA3F86616098FULL, 0x089BDD951B7CFED3ULL, 0x45F8D8766ADED48AULL, 
            0xB27777735628E908ULL, 0xEB7DBDA0E782FF02ULL, 0x79FF9BE565336DA2ULL, 0x71F792104BB6225AULL, 
            0x10F0DB38E7D621D0ULL, 0xF8CB006658F14C2EULL, 0xC8710D20B71130C6ULL, 0x1678CAF9FB18B0F3ULL, 
            0xA9E07E83569C985FULL, 0xCAFAA9695455BEE7ULL, 0xD7C5CC7F945D9133ULL, 0x4AB751F76814CE09ULL, 
            0x0848AE72770072CEULL, 0xDEA0B2BBE44BD389ULL, 0x56CAF7D0E4ADE089ULL, 0xF13BC39B90AC7906ULL, 
            0xEE8C98EDC4A6AA98ULL, 0xDEF85E6B49B2DE0CULL, 0x4C195A7439A66712ULL, 0x619E28B93F4711D5ULL, 
            0x2ED6E8537DBD7651ULL, 0xA63794D6F1EB23E5ULL, 0xC7E1E4250EA784D0ULL, 0xD8773FB17C9EA13EULL, 
            0x9AFE7F170D14D76FULL, 0xB6976197B763251AULL, 0x2852783C7D653368ULL, 0x3976291698B6D529ULL
        },
        {
            0x3FF32161DDB82275ULL, 0xECA56D8A54F975EDULL, 0x4F6DEFB38937A0D9ULL, 0x96ACDC23DD384C22ULL, 
            0xCA3ACDE0EAE65996ULL, 0xFFFE841AFA6DF584ULL, 0x2374C3388DF9669FULL, 0x66A18E773662D3CBULL, 
            0xBEBBB4B1B18C0091ULL, 0x50DC6F20FCC0A281ULL, 0xCA920ACFED16E9BCULL, 0xA35AE09D686A0FEAULL, 
            0x8546B6796E4AC2BDULL, 0xE3C349D580ABEC09ULL, 0xF251BF9FFDD5704AULL, 0xAF19C099BBDDDE91ULL, 
            0xE0489B0E62BAE3FCULL, 0x9521AFF118FB03A3ULL, 0x3C43B0CF1197A166ULL, 0xE9EF81F35323BE72ULL, 
            0x60E0305AB81C3321ULL, 0x55E7BE821D93F595ULL, 0x011647703A28E382ULL, 0xC49AE26FEB60AE69ULL, 
            0x4BDFCDAF020C0981ULL, 0xBE0FCDF50A1CA900ULL, 0xFBA6D24191529ED5ULL, 0x5D2CF86FE8BC4519ULL, 
            0x3793C4CD74DF980AULL, 0x2DD91A49DDE7A733ULL, 0xA41C1AFA6674F64AULL, 0x6B647BFA69AC2EBEULL
        }
    },
    {
        {
            0x09FACA7CC9D84DA2ULL, 0x69B710E2F266CE57ULL, 0x92876DD505B31916ULL, 0x835FAB9F4E820D01ULL, 
            0x3D1EA5EAF6F8DB3AULL, 0xA089D7C4D3E9C23EULL, 0xEC30FF27BFE1D8A0ULL, 0x0B08C749F034112CULL, 
            0x149C030DCC4980F6ULL, 0x8C905961EA0FACEEULL, 0xFB16A9818A4F5CB8ULL, 0x887260685942FBA8ULL, 
            0xFF1548599F012680ULL, 0x3D498295D06AC192ULL, 0x110F771F4643623DULL, 0xE1B5F595DC50ACB1ULL, 
            0x339052FC8246F08BULL, 0xE8B594EC471D2135ULL, 0x4E6E0A8DD9DD7A45ULL, 0x4959E669A8C8F4D1ULL, 
            0x41BBFFD9CE252579ULL, 0x7B78B29C4E42B61AULL, 0x0E5FFF8B26C058CFULL, 0xEACA842D044FD61CULL, 
            0x314CDE9782748B67ULL, 0x7261900B3E16712BULL, 0xCFFB8C67F80B17A3ULL, 0x86E8668592DF447BULL, 
            0xBBF61D956AA237D9ULL, 0xE2A76B666C237B33ULL, 0xD35964B2A75EE97DULL, 0x6B905FBC241C38BEULL
        },
        {
            0x84AE37D770D5963AULL, 0x685258171B1E223DULL, 0x35B4EBD8586BDD64ULL, 0x9ACA32E6D2B9ACC8ULL, 
            0x129DAC20BD4FF562ULL, 0x09A4E36AA205DE8FULL, 0x9D4B4226D8F7DEBEULL, 0x5A24E7483F579869ULL, 
            0x6E4CF9E84A5B9A57ULL, 0xF7C617B5FFE1C962ULL, 0xE614D4FF7E5BB018ULL, 0x1A9FB16709DC19CDULL, 
            0x6627D3D1945D5265ULL, 0x0ACC442A45203DE3ULL, 0x21C56F4E15AB9F21ULL, 0x8C6131C3BE0197A4ULL, 
            0x11F614EED60FD699ULL, 0x7CBCF81AD31531DDULL, 0x9265300C4D93AF94ULL, 0x30FE81B69CB1DB72ULL, 
            0x57E57C4B440CA429ULL, 0x1AF2EAEDDD6DB889ULL, 0x71A41CBC169E2C58ULL, 0x1A0D4B5499E060C3ULL, 
            0xA5C8EAB3E8DE0F7BULL, 0x30ABB3E3A51FA4DFULL, 0xA184815B8B8D0AAFULL, 0xDF34EA553936ED3BULL, 
            0x8964B946ACE74563ULL, 0x75A1256BE8369DD8ULL, 0x2827028DA4C6175FULL, 0x72F5122CB2861338ULL
        },
        {
            0x13E8211D1AA8F099ULL, 0x3D17513B6CD050ACULL, 0xB3C25BD56C51C780ULL, 0x0FCE82E13519C83AULL, 
            0xD83E498E6B6926C8ULL, 0xCCF7D4F6862AB030ULL, 0x47A6E8CD994B7961ULL, 0xA5474729FC722BC8ULL, 
            0x33A3548A8397AA01ULL, 0x64FE5A2883B84C70ULL, 0x7709EE510C55EED0ULL, 0xA192ABE8692F5A01ULL, 
            0xE663FE28D95441E3ULL, 0x2FDEA35676EEA19CULL, 0x53816CDAE6485C04ULL, 0x46DE7618D78F5ED6ULL, 
            0xF0482D8F67488EACULL, 0x1A70544A4E1B52F8ULL, 0xA0C20251CE51EB9EULL, 0xAAAB0B95B453AE09ULL, 
            0xF2C6B2F7D0351A30ULL, 0xD75C7E2B147195F1ULL, 0x4247389F674D6984ULL, 0x54F097F10C36F000ULL, 
            0xF5049E0D4201786AULL, 0x4D2B7B0DE7ABF0EFULL, 0x092B83739631AD22ULL, 0x44DEF632EADA5CF7ULL, 
            0x1991675010599010ULL, 0xAE9B2CA3CB5C4B31ULL, 0x4CA4419188D23B71ULL, 0xAB130113FD6648FCULL
        },
        {
            0x6636D9C767B66008ULL, 0x5F97ADCFFE8EAB01ULL, 0xDCB8EF2004A1B9A5ULL, 0x091987BDE5F9FE9AULL, 
            0xB512F8528EE53156ULL, 0xD9444CDCF3C279CFULL, 0xF4A27CB13209C63DULL, 0xAC9D43A69F67AB78ULL, 
            0x89CA909C396507DFULL, 0xA5AC66399465387EULL, 0xAE7716D18E1638E6ULL, 0x2283E6BE1F87C28EULL, 
            0xA10E65DFC7AF8EE9ULL, 0xD4F5E27A575BA5CAULL, 0xE4A3C0CDC388056AULL, 0xC8B8117E281E1A69ULL, 
            0x7DA99D2C0B930179ULL, 0xC07F99822F7F491BULL, 0x39198CE2DE0387CCULL, 0x47B8C92E5E0A7E28ULL, 
            0x8EEAC2D3EBBAA0F5ULL, 0xEF6EB436535D7A7BULL, 0x814D99090B7D2DF9ULL, 0x826FA36205584F77ULL, 
            0x3AD6037DC4A9E666ULL, 0x1B507E0986E55E80ULL, 0x1E4617C73E564AE4ULL, 0xEA9BF28039DB994AULL, 
            0x440B0AF6FFCFF844ULL, 0xA6AEBFE9824B158BULL, 0xDF7A17525CB59D91ULL, 0x36BF30A354CFF807ULL
        },
        {
            0x053EF8678301F54FULL, 0x0372276B9D18F35CULL, 0x12F006728232B65EULL, 0x6C510C5EA6CEFADAULL, 
            0x73A8ECFE17A7DECDULL, 0xC2DD5F1E2FF3B86AULL, 0x046EA05FCD9A5E5CULL, 0xC6640302AF8BB90DULL, 
            0xCC15DCD9828D6BEEULL, 0xEA782927C93B7128ULL, 0x2B95A3E04436D569ULL, 0xE5CF1EA58DD9A81BULL, 
            0xC274EBDFCD061F4AULL, 0x1E87BFBB3FFE884AULL, 0xE3C35C725FE413D0ULL, 0x562F860EE685EEB4ULL, 
            0x91E7EAB5E5AC0314ULL, 0xCF82603E897AECCAULL, 0xF173B186D7AFADB3ULL, 0xFB48B0F30BF011A6ULL, 
            0xFA6C415CCC1FC1F2ULL, 0x754977EF06041354ULL, 0x8DE74D76B9DD7C97ULL, 0x1ABAFE10CDC12014ULL, 
            0x43AFA78CF99D7159ULL, 0xBF8EAB532B220B77ULL, 0x919548DF51C5356BULL, 0x339DC9858A60D111ULL, 
            0xC59A35C9ED8AD4C7ULL, 0x55BFEDA72C72755CULL, 0xC37D37037ACD3034ULL, 0x4A00B5EBB6A83599ULL
        },
        {
            0xEB24E8B8658C801AULL, 0xED4CDD4B722A3214ULL, 0xE54D44E9F06EC2DDULL, 0xEC027FB099F3AFF5ULL, 
            0xF3C7164070EA1E68ULL, 0x5BD8452DFE859478ULL, 0x92C736D737945092ULL, 0x38C696D650253BBEULL, 
            0xF367127F61796E56ULL, 0x2FFE8E525171B445ULL, 0x0E4BA6B314995CE0ULL, 0x21263A1EF0F1691AULL, 
            0xFA7C77EB5540C2D7ULL, 0xE1401B6CA2038069ULL, 0x7360C99A68A322E5ULL, 0x89240F2B69C8580DULL, 
            0xD7576587FEA0E891ULL, 0x590647599FF5F9F7ULL, 0xACF3216DE80DC7F7ULL, 0x21ECDCFBDA6577F4ULL, 
            0xC140C9B27580D4F7ULL, 0x7F4AE10B157B7586ULL, 0x8503B194DFB17242ULL, 0x9747CB7959EAA952ULL, 
            0xFB2DE3C970849D0DULL, 0x4B066ABC1063DB9DULL, 0x603DA898D9CA3886ULL, 0x2E91C54B3E8DA5AAULL, 
            0x21C58A3D45E5D020ULL, 0x1C93A68E72C7400CULL, 0x0975731E45788DEFULL, 0x4A73B38BB38FD2E8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseCConstants = {
    0x3460E8FF64C9B4DDULL,
    0xE1FC4CB4A5B54950ULL,
    0x26F142242D4F8A87ULL,
    0x3460E8FF64C9B4DDULL,
    0xE1FC4CB4A5B54950ULL,
    0x26F142242D4F8A87ULL,
    0x147D5ADDEFCC5283ULL,
    0x8ED09F00012BCAC4ULL,
    0x7F,
    0x05,
    0x10,
    0xFF,
    0x5E,
    0xD9,
    0x2A,
    0x92
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseDSalts = {
    {
        {
            0x18F0AED32CCAA29AULL, 0x58D259B023BA54ADULL, 0x5C6414DCD12C183BULL, 0x709300B47BD029EEULL, 
            0xFCEDF5816E899A1CULL, 0x38BF8CDEA33CCFFEULL, 0x27908F1ACB282C6FULL, 0xA1F05707108771D7ULL, 
            0xAA04E4F8078AC7B3ULL, 0xBD3A978AC85BE244ULL, 0x827FC13555435827ULL, 0xCD060BB7900E2999ULL, 
            0x52F4F69150B1B46AULL, 0x3559CD5895A796FCULL, 0xD79B9953160B0980ULL, 0x027E4AD73426DD1EULL, 
            0x8854F587AE525959ULL, 0x3C008F49BFF8AB3EULL, 0x7FA9CBA44EF4473CULL, 0x5DCE9B20FADA8F69ULL, 
            0x8E690E84909D79C2ULL, 0x6EDE19D33DFB7640ULL, 0x72953C93A5A74BD6ULL, 0xA4E098DFF68EE9CEULL, 
            0x80C88EB6A6D41E5AULL, 0x82997F98E117C9B5ULL, 0xC7D1F26EFCC39CEBULL, 0xFDB8057377B4438FULL, 
            0x8918721A58843FEDULL, 0x8411DC8ED9CFB539ULL, 0x6CE9E9AF2665D633ULL, 0x5681A524E2DFB636ULL
        },
        {
            0xF7C9DE8965578135ULL, 0xFB0D4ED5C14F479BULL, 0xAF6DF38A93321AD7ULL, 0xEA90169363E0F93DULL, 
            0x83FFF2C67191F14EULL, 0x02D9A63F05D88C5AULL, 0x44B2531B2942C5F0ULL, 0xB5AD322640116A00ULL, 
            0xEC32A0EA5A9FF64BULL, 0x30F38D73CC2D43CFULL, 0x21D22573281203AEULL, 0x88081DCFE1855FAAULL, 
            0x3642DE821CCC7368ULL, 0xD59FCA857A4E0CB8ULL, 0xB63268A8B41CAF0AULL, 0x9BD5AC956B499AAAULL, 
            0xA7E50DAC77CDD96DULL, 0x3A25E00E93967CE2ULL, 0x38265DDCFD4CEA80ULL, 0x63262688BAA85093ULL, 
            0x792F582E1E95C4D8ULL, 0x14D6F537B793C311ULL, 0x1B705E1B02E60143ULL, 0xB6A87085029D40F9ULL, 
            0xF2F977358B6C1358ULL, 0x9F0F5F7AE451590EULL, 0x2BD359215DC98F61ULL, 0x4B25C2F4FF26D555ULL, 
            0x871F90EF792687F6ULL, 0xF32C39D434A21296ULL, 0x4DA46A53B52636F2ULL, 0xD27DC833C918A05FULL
        },
        {
            0x92F5C9E2EC5F0D95ULL, 0xEDA7471C61FC5D09ULL, 0x4A3128A9865CB63DULL, 0x088162B169A4EF9AULL, 
            0xBFB434C8211EF8D7ULL, 0xC6217755DF2B9854ULL, 0x4FC216012ACF853EULL, 0xAD0258F89C891A03ULL, 
            0x884507D392CF6757ULL, 0xCCD2E6B9E8099EE6ULL, 0xAD9C00EF1F256026ULL, 0xD1FD2CE5FD40B0B3ULL, 
            0x51BE27B9A0D2F4CAULL, 0x05F5F892E0BA262CULL, 0xCA1A033B5785A5CEULL, 0x094A6BD3C413BE9FULL, 
            0x2FCB5F021EA63A86ULL, 0x57141A0954675913ULL, 0x9B3B11B1110F32F6ULL, 0x63E95A103824D2E8ULL, 
            0x2E7C273CDD04EC13ULL, 0x7D3DD67007BEF2BFULL, 0x8D3D994D6534C38BULL, 0x355608942FF232C1ULL, 
            0x69DE71D3B1DFEF18ULL, 0x0DC2EA9E9E5E6F5EULL, 0x3F3DC3575B12B2E9ULL, 0xCCF124C718CE20D0ULL, 
            0xE9162838B7F98914ULL, 0x39CCA7B89152D40CULL, 0xD20B43B67C484A70ULL, 0x710EDFA25BEB67AFULL
        },
        {
            0xEF52105FC138E9E5ULL, 0x7DC18EBD3898A56DULL, 0xD9698C188B3FBFB7ULL, 0x3A0DF765E95C85C5ULL, 
            0x1BB891069F011548ULL, 0xE9BD2C3A869F4B91ULL, 0x844D06434D07AA4FULL, 0x224AFC393A35605DULL, 
            0xBA4C5F6F490B4415ULL, 0x5210F2B82A03F8C6ULL, 0x183F682EEFBD879BULL, 0x1AFA1DD1450B04DEULL, 
            0xA11ECF922AB0DB5EULL, 0x921378D798EB9887ULL, 0x420268ABCD126A82ULL, 0x321E29FD4B4EEC16ULL, 
            0x8820DCC66A4BF856ULL, 0x3F7141A289EFAD48ULL, 0xB2E220B7EC0D033EULL, 0x452B5BB215A70348ULL, 
            0x2217EDC147636241ULL, 0xE5E3A2B608288D84ULL, 0x404F3749963778E4ULL, 0x8CB01A70483E3E61ULL, 
            0xC9F20FC682567D5BULL, 0xFEEEC8E31D45FF9CULL, 0x33B0BED235777176ULL, 0xFCD0296DFC12731CULL, 
            0xE93B9BB52AE78208ULL, 0x42166D0FB6ED130EULL, 0x8D42B26C37359E5AULL, 0xAE6571AF3FE5A262ULL
        },
        {
            0xEDA8A4C25DB2194CULL, 0xCFBE9A1FB0FE477CULL, 0xDE8342C794A43AE6ULL, 0xFB37CCF480410CC3ULL, 
            0x5B7EBE76C788F480ULL, 0xBC85EC02C4DC9FD4ULL, 0xB6A2E19FA3196662ULL, 0xE89BD2B44412253AULL, 
            0x618F6DDCA5642009ULL, 0x3DA79C198E96E215ULL, 0x1F52398D6F282E2DULL, 0x2E16AF0909581E0DULL, 
            0x8D3111C48430F863ULL, 0xE3B25D60E5BBE8BEULL, 0x879BDF39339CF658ULL, 0xE69CC773EBD4D1C5ULL, 
            0x54307F9CCC723CE1ULL, 0xB80D749D5B4D8A49ULL, 0x6972285B0E4D3BEEULL, 0x96CADD4B6C4153A8ULL, 
            0xD5E5896B94D6F621ULL, 0x9BAC79F931E80E5FULL, 0xB93273EBC2BDA5A7ULL, 0x834920F07C492F77ULL, 
            0xEFC83147C463F9ACULL, 0xDA7C6305DEEF3D39ULL, 0xC63558F9B927F17DULL, 0x37382099628D230EULL, 
            0x6B79B729AB3F5D5DULL, 0x96D969C3F8DFA532ULL, 0x999707D12CC15AF8ULL, 0xC4A9FEB18054F83AULL
        },
        {
            0x92CB5A394AFF146CULL, 0x964A38C648374B7AULL, 0x0785C02636560116ULL, 0x09B61119F68D4F40ULL, 
            0x1ED7F777E4E5734AULL, 0x5911C5308C3B16ECULL, 0x63492E9EA1D41DF2ULL, 0xB9DFEFB08ADAF63BULL, 
            0x3BA8AFD717335478ULL, 0xCBFBFAEDA98A0111ULL, 0x28F7F0F6D290AC7FULL, 0xFA96923D1314E229ULL, 
            0x0CE2A30D1D88863BULL, 0xD43593A60A3514E7ULL, 0xBE3806B48C908D59ULL, 0xE69594B997D4473CULL, 
            0x4F52637ED51145A9ULL, 0x1D497B8F98F1D96DULL, 0xD0F81B51F5A93F32ULL, 0xC15F696D07412349ULL, 
            0x0AB17F821A939DFCULL, 0x5F6E2FC2A2022A92ULL, 0xC8C1C6DF7EE8CFF4ULL, 0xA6DF82978BBCC23FULL, 
            0x6298EC157A018731ULL, 0x7082688BC7D6A7B3ULL, 0xD8A4AF005A19190CULL, 0x1779617241B0613EULL, 
            0xF806A5FAB302B7A1ULL, 0x4D87455331A6FEC0ULL, 0x082CB84643C954ADULL, 0x2A4FDF528BABFC7FULL
        }
    },
    {
        {
            0x7E13FFA53BCDB256ULL, 0x3053E7BF863A0B95ULL, 0x6DC8C64FF6C0A97BULL, 0xAFC940C676B9CFD1ULL, 
            0xBF67CD5E68A030D4ULL, 0xFE4066FD75B2A3FBULL, 0x77CCB7418447D32BULL, 0xEEA4FCD06527A269ULL, 
            0x9D98636957FAE7B1ULL, 0x4825DD5DE4962142ULL, 0x80849B323B034D38ULL, 0x3D513158092DEF52ULL, 
            0x58FD0273A3A451C5ULL, 0x814B29CD8028B329ULL, 0x485843B758919843ULL, 0x864D1992DDC5764FULL, 
            0x099B6D7638F4E0A4ULL, 0x72185BF262F8D761ULL, 0x83346AFBA7BA3EBAULL, 0xC19AA5418D7149D0ULL, 
            0x4DFD7F32606C2900ULL, 0x632516FF469904D8ULL, 0x2DCA8BCCD2571C20ULL, 0x2AB13ED603F50D8DULL, 
            0xC6ACB733ADD52A6AULL, 0xFAFD4A3029F68194ULL, 0x55634826CA414EB6ULL, 0x7CDE6BB60CAC14D4ULL, 
            0xC4C761693B6332CBULL, 0x87132012BA1C29A1ULL, 0x45A6A165748BC306ULL, 0xC702F8C317416F60ULL
        },
        {
            0xE254DBCD6B9446ABULL, 0xDBAE9EC5EF55C4C6ULL, 0xE8A729FE78FF2BB4ULL, 0x717A4E8668757D5CULL, 
            0x806C4D7890759AA1ULL, 0x89725541A9B2A491ULL, 0xC6FA8F29AAF63394ULL, 0x3495C1C90A3412C0ULL, 
            0x87B577B60FA89209ULL, 0xE67527E30559041DULL, 0xCC030419E538A627ULL, 0x204030D1B3F4425AULL, 
            0x90A4580BD683FE9AULL, 0xD7DF0935574236AFULL, 0xDCB68776A4ABABDCULL, 0xB299E16379B302F2ULL, 
            0xA8FB645942F90D42ULL, 0x292856F9276A49F1ULL, 0x964D275962735E1DULL, 0xBF1D13BD39A4A18EULL, 
            0x446EA68BAD582DE5ULL, 0x23EFD476B2502233ULL, 0x93A230ED8A878BB5ULL, 0xEB0BE351A2B5C1B4ULL, 
            0x66FCA32673A7F335ULL, 0xE2C0B14A4A0955A9ULL, 0x8270D39538CCA4A6ULL, 0x9CC6A146C8C3E610ULL, 
            0x99312004C8C3C96CULL, 0xF4F7CF2EEB3E3DA6ULL, 0x885040481D17467BULL, 0xB079A4D78982688AULL
        },
        {
            0xF64841FA516AA037ULL, 0xCD18B3222731D69BULL, 0x9B6CA8B6F5DC699CULL, 0x76DA92817E453E68ULL, 
            0x197490239BD8741EULL, 0x6929962E935DED7EULL, 0xB84A3009D6D0E304ULL, 0xFA6B12076323E0EDULL, 
            0x85CBC3668B2A6054ULL, 0xCEFE37D1DC95E4B7ULL, 0xD9108C4D0A5F1B8CULL, 0xD3A4E764C9AF2928ULL, 
            0xE4849950F078D1C5ULL, 0x4BC4BE78AB725AE4ULL, 0x8D016852D450E91FULL, 0xFD7CD43CDF230E1DULL, 
            0x5C01BB7793B9AEB9ULL, 0x5DD2DE0794E5554AULL, 0x27F88109A9DA9642ULL, 0x25693B3192A3918BULL, 
            0xBEF1589039749748ULL, 0x4520C19DD7F76EDCULL, 0x6F07CFA7820D0B62ULL, 0x572110129294EC13ULL, 
            0x9AA867375C5437D6ULL, 0xB068BBF7F402D704ULL, 0x32BA8FE10EA571F8ULL, 0xCB39238B694D5060ULL, 
            0x65C5061000F044DAULL, 0xC53817A702C977B7ULL, 0xD46F3BD5CD9512D1ULL, 0x90F88CCD89413821ULL
        },
        {
            0xA2E860BC36B0E119ULL, 0xD2C2426598EBC136ULL, 0x122E1C22BC84FF1EULL, 0xC4267AF8A65817CFULL, 
            0xE8622B43D373A44FULL, 0x3944E065C5E1C024ULL, 0xCDAD04DF7A58B18EULL, 0xD9C50E5D7401C5E4ULL, 
            0x727006C2F74C4A2AULL, 0xD72A894A24B0C4F7ULL, 0x80036EBD4BA1F943ULL, 0xB55F6B7C0E62711EULL, 
            0x5B9C123380FC82BBULL, 0x3B19E6BAE7D3F7B5ULL, 0xBCE300761A85F5D7ULL, 0xE2B3D4E4DE7AD945ULL, 
            0xD98441E0C1C43512ULL, 0xB0965EDA507CDEA0ULL, 0xE53DE996DAD8C91EULL, 0x6E472D69F580E1B2ULL, 
            0xAF33EFF3346B62BAULL, 0x32E1664F22CB1040ULL, 0xC6C2E910BEE5FAE8ULL, 0x2D9C6C83146774C5ULL, 
            0x52E048A1702D3539ULL, 0xC04A5CFEC8B6EA39ULL, 0xAE07D5DFAAF28D01ULL, 0x3C7B4ABC33B3BAC6ULL, 
            0x996F42979E3ED978ULL, 0x9CE76918DB0F1718ULL, 0xF09FBA7CD25CBB55ULL, 0x32A5EFBEC7716D1CULL
        },
        {
            0x58E41C4ABB4BA82CULL, 0xB81077C0291EC3F9ULL, 0x4154B2CC7378C4BFULL, 0xD541C63D5DD2289EULL, 
            0x6FAAEB87EA08455BULL, 0x60EFA5D5DCC9E45AULL, 0x4891934E0FE7B3B3ULL, 0xC28F07F2A3AAFDA5ULL, 
            0x755DF23DBC4F48B8ULL, 0x67A383538A26C742ULL, 0x83BF5D0F2A2E92AEULL, 0x314A69391701EE91ULL, 
            0xC986DE08F614AB86ULL, 0x151D99136D7B018CULL, 0x6E0BA24BCE840B60ULL, 0xA8C33E3982C78E18ULL, 
            0x2094D3C6D1B72556ULL, 0x3B074CD4283FA139ULL, 0x2EF42198D2F6EC89ULL, 0x2CE7710AF8155BB8ULL, 
            0xF90A1C5BD4B4AC8EULL, 0xC56E5DD532C47FD3ULL, 0x06D5DBA45CB160EEULL, 0x88976D44C231D4B4ULL, 
            0xA57C02FC5A9846F0ULL, 0xA466B27DB63E7923ULL, 0x0AEEE3C52DE521ACULL, 0xFE8A161AEC96695BULL, 
            0x1F440E08CD862346ULL, 0xA99C24C2F5BEAD96ULL, 0xC0D463CE22A95BAAULL, 0x7C1933FFC520B8A0ULL
        },
        {
            0x3047044C0859F472ULL, 0x55CB5C225C5F8436ULL, 0x8C04B51B597705ACULL, 0x7D6E9E102FD5F9ADULL, 
            0xF1439E790B1EDE42ULL, 0x32918659B1F225FFULL, 0xEEA945B77E69393CULL, 0xBE4DDEDDBA2FF16CULL, 
            0x0625EF683E80CBB1ULL, 0x01C20C02DECC360AULL, 0xB46EA57009E2DD6DULL, 0x76B8A96B50EB3E63ULL, 
            0xF3BC2A44B69546AFULL, 0x8A753A64589AFD79ULL, 0xD989306304352D65ULL, 0xA9F3BB58B821E389ULL, 
            0x3324EE5ECA6726F3ULL, 0x579E5CD8584BAE0CULL, 0x1F98AA5191703D84ULL, 0x804234E4E9578F01ULL, 
            0xAC7F43CB72C34293ULL, 0x6D2D7C306FDD2FDFULL, 0xC8E0CF45A89293AAULL, 0x9CF81360C362DDD8ULL, 
            0xD0DB2CB1025A3736ULL, 0x86F8C350B76C4DA5ULL, 0xEB99173790678549ULL, 0x3B8CE92D3325835FULL, 
            0x6D7486F2A5E9CB5FULL, 0x8E92F2E44AB96725ULL, 0x5AB4467D9F4CBBB0ULL, 0x39D040162231D98CULL
        }
    },
    {
        {
            0x7762DE1460C122E7ULL, 0x52814C1A8D4F333CULL, 0x5ABF9D1528385A4DULL, 0xAEDDDA608BE66CD5ULL, 
            0x79CDDCE708A47559ULL, 0x159CFE9DFB599E29ULL, 0x02F5DCAEC918FD6EULL, 0xE3A245CB16B2529AULL, 
            0x996E90F18323790CULL, 0xC7C582B322546AEDULL, 0xDD5A6CF1B3324A2EULL, 0x3D0B34C82DE4D4D9ULL, 
            0x1D75BB7865DD2AA2ULL, 0x24625E83E5D732F3ULL, 0x8182786195A7FA33ULL, 0xD7F0433E304569EAULL, 
            0x88CB8F55C39C52DBULL, 0xC5DE8FB5941544D4ULL, 0xA852321D50B07557ULL, 0x3C56B1E09BD1372CULL, 
            0xC4BC41140A315716ULL, 0xF2AC152CB711F0D3ULL, 0x9D9E3534AA29D1C9ULL, 0x3E76298474290B08ULL, 
            0x1407211E13A98701ULL, 0xCD8F717F2BA91505ULL, 0xF5E756EA005D782CULL, 0x363F7475DC4F8F35ULL, 
            0xF96F59750994B1A2ULL, 0xEFB2057680BED62CULL, 0x260CA95A5A64F52AULL, 0x9A5632B31FC25A2FULL
        },
        {
            0x78A2B8B404A3D7F6ULL, 0x7C12DAFA5DE37CB7ULL, 0x68A2D396DC7B7842ULL, 0x67F51AFE7AECEE09ULL, 
            0xB4B38B4B9D498C40ULL, 0xB75EBA78D573F4AFULL, 0x3DDCD28261E73C9FULL, 0x8A713EC91CB4F2A5ULL, 
            0x1BBDE1E1DFF19880ULL, 0xC381107E99843D8FULL, 0x88DDEC2A507B036FULL, 0xCC34FBEE112FC37AULL, 
            0x7B698A890A8F94A8ULL, 0x5D298314E4C4D485ULL, 0xB5D3EA3B37A0B997ULL, 0x4DDDCDF0B133E4DFULL, 
            0x70AF44C50431A48CULL, 0x3749535C59576130ULL, 0x7ACC7B1BA2969D47ULL, 0x87C62EB45F8AC465ULL, 
            0x6E6116DC72ADAA16ULL, 0x868CEFA379CDDC82ULL, 0xBF91CF346B9B47A5ULL, 0x36EDE7EC75F06442ULL, 
            0xA9E74EA54E6AE008ULL, 0x7F8B05067268D3A9ULL, 0xF1C88268C8755BAFULL, 0x99C61D6ECE3E87BDULL, 
            0x5D5EC392B5402ADBULL, 0x34646560A302BF15ULL, 0xBF9F88AAA6DA0B45ULL, 0x1473C4E5567A3180ULL
        },
        {
            0x344A5463FF64ACF0ULL, 0xBAB0EBA573EAF9D9ULL, 0xA9D0734055D793A0ULL, 0x2A166CAA3D8903AAULL, 
            0x90146F853BDDBAD6ULL, 0xCA90C6AB9ED4E414ULL, 0x13D2E20FA82411DAULL, 0x5E5C7AA72EE92B6DULL, 
            0xD13D34BC23232C21ULL, 0xB39123DF398EDC7BULL, 0x15AEDEAD9C2752E2ULL, 0xB90AADE78870AAC0ULL, 
            0xDE7BFF953D3060EBULL, 0x26CC7EF905861C3FULL, 0x71E3595716F04227ULL, 0xC4A225751FB6A644ULL, 
            0x248E16EB0BF800E4ULL, 0x60AA4CBA2F75C844ULL, 0xF05557675AD4E4ACULL, 0xC20B8A26F129AA24ULL, 
            0x1A2ECD172C326267ULL, 0xC06480A4D51421E1ULL, 0x5A955083B6DFBF82ULL, 0xFA6B061A25528E60ULL, 
            0xF1B21421AA24889AULL, 0x205CD5CB1E0E7752ULL, 0xEB3E5DDC1A160038ULL, 0xFE2EFC8E2DBE5ABEULL, 
            0xB1751C957512353DULL, 0xABD828EF798CE8CAULL, 0xC7B1132449322E75ULL, 0x91687B96F101E092ULL
        },
        {
            0x45660CFA61461362ULL, 0x446043704CFA272BULL, 0xE5D59FD3BCF2B0B5ULL, 0x936D2612820D3C08ULL, 
            0x7407CCAD73909E88ULL, 0x59C39D2BC3B3C5B2ULL, 0x9E701B96805B1234ULL, 0x7C6F1851E44BF73EULL, 
            0xE447BC58D8ABE769ULL, 0x239C7AC2D866AA74ULL, 0x3BAC86B82888B3A4ULL, 0x0F5D19A74D4A49C2ULL, 
            0x49CFD3AD35FA263EULL, 0xBD9F8B80F104BF37ULL, 0x90D1DD272FE08726ULL, 0x56241005FE718339ULL, 
            0x0E8275E2ED05C705ULL, 0xB2F67F3D453A7AB2ULL, 0x1E66D80E3DA6AEE4ULL, 0x985846880539ACD7ULL, 
            0xD6A65FC184188B66ULL, 0x760414E82DA55720ULL, 0x3033A21FDFAAFBFDULL, 0x9C9A5F55D911E62DULL, 
            0x11EFE06C741DCF58ULL, 0x9F9BB47A07948F74ULL, 0x704F615917546B0AULL, 0x06EF07A21AC355B3ULL, 
            0x691FB654535E8EC4ULL, 0xF34DC1865E9FF193ULL, 0x289DA28783FF562DULL, 0xD7421E1320D24CCAULL
        },
        {
            0x2883C2F3180FAA2CULL, 0x62D91F5273D9FF00ULL, 0x226E8EC097524C93ULL, 0xAD53EB7F187BF625ULL, 
            0xD181977A4D41A27EULL, 0xD4A2376E26C26D25ULL, 0x42993E23DF7CFA92ULL, 0xA161330D1D902F0FULL, 
            0x9C215E6A07055658ULL, 0xAF6A73F4982D1DDCULL, 0xFDDE955BBFAB3713ULL, 0xC5FA6A6EFF79CE7AULL, 
            0x5126893EE5ACA370ULL, 0xED5CA1267F5DC200ULL, 0x4514F87714A9932AULL, 0x344425A55145ABBDULL, 
            0xCC0B700C347497CAULL, 0xF6CDB3C049F948BDULL, 0x4691D436BFDB7F85ULL, 0xED02D535302EA14DULL, 
            0x246453D0FB13AF13ULL, 0x9F75220727587CB4ULL, 0x25666605B2F79E8AULL, 0x6016B30144D9B7EAULL, 
            0xAD1107974DA9684CULL, 0xFC4D80C4291F4C9AULL, 0x135295E3D5B2670FULL, 0x091DAE878DFAC96FULL, 
            0x160198DB8F67B781ULL, 0x93ECB55069EA8978ULL, 0x8C77CB23F225A451ULL, 0xC08EDD6C5C4AD64BULL
        },
        {
            0x0F6F1344786396D7ULL, 0x341847B42CAA6667ULL, 0x343982E013AEB043ULL, 0xAB338F295C1AF417ULL, 
            0x0449FC1DB66CDA12ULL, 0x1C9BF78D6AEB6282ULL, 0x2D148FFCB74A2DB5ULL, 0xFAC4F5E33BD6AF01ULL, 
            0x4261C0D6E6C30EF0ULL, 0x0EDA704F537E0277ULL, 0xEFA4F37010D798A8ULL, 0x5AF55636424E5543ULL, 
            0x91CAD24473DD9088ULL, 0xA6EDC13CE718FAA0ULL, 0xD434A48C62CEDF0BULL, 0xE35D68F61CB45555ULL, 
            0xCA5A235216F43CD5ULL, 0x857779140EB328C8ULL, 0xD90353D73EEEBAB9ULL, 0x80922CA84ECBB7BCULL, 
            0x68DC58EC90D166A3ULL, 0x528600976456E386ULL, 0x9395AD71005FD304ULL, 0x076C023F7BEEB390ULL, 
            0x92E68610F729598AULL, 0xA165604AB66781D9ULL, 0x8B2E54AF5F18BD81ULL, 0xEB434B55AAA86BD5ULL, 
            0x3E74B00035BE7E36ULL, 0xA12B183B9325EE0CULL, 0xCB253546A638B545ULL, 0x0632888644A5ABF8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseDConstants = {
    0xB320AD49231F6722ULL,
    0xA83E09496C8681F0ULL,
    0x0CF154E62B0EEB10ULL,
    0xB320AD49231F6722ULL,
    0xA83E09496C8681F0ULL,
    0x0CF154E62B0EEB10ULL,
    0x03CF8FC294E8C99EULL,
    0x727D38C908FB46B3ULL,
    0xE0,
    0x36,
    0x24,
    0xD4,
    0x96,
    0x0D,
    0x42,
    0x1A
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseESalts = {
    {
        {
            0x3B3D4C6EADC09A76ULL, 0x6691C18D4E2FAB0CULL, 0x3FAB4E553F790DCBULL, 0xA19ACCF38D15105DULL, 
            0xF000CAAB7D264992ULL, 0x915A5AB76FB121EBULL, 0x2DBC34B34CEF29C6ULL, 0xF51C6EB7B02ACC8CULL, 
            0xDDEB445CD8E8B916ULL, 0xFC011F8C80A26AE0ULL, 0x2B10854E372975E3ULL, 0x4381A77834B245ECULL, 
            0x8D719F0B6327011AULL, 0x2090210778DAD559ULL, 0xBFA6A1C9A05D2612ULL, 0x9DCE1481EC2767F0ULL, 
            0x44358DCC7EB0A77EULL, 0x2B94D94637286FF2ULL, 0x19D42047D69B5791ULL, 0xBFDE4DDC57838964ULL, 
            0xBF07C9FDB6EB4A2BULL, 0x5A8691DBA26CABCAULL, 0xC5681E49E03C36B0ULL, 0x92F385FF23D7F5E7ULL, 
            0xE13EB66A7EC5CB83ULL, 0xC25724AE83A80A3AULL, 0xB02AB1C6413394ABULL, 0xCA92C0AD211A7851ULL, 
            0x5CE6F991E6824FBDULL, 0x3EBEEFBDDB8F59A5ULL, 0xDD295495295EB702ULL, 0xFFA1483CB45165E3ULL
        },
        {
            0x1250DB493CC0F894ULL, 0xA1314597D0F824EEULL, 0x2867404A0A1B8650ULL, 0xD24F12D65BF9455DULL, 
            0xB0BE622EE698D241ULL, 0x6071D721136CC322ULL, 0x024FACA2C8F98F16ULL, 0x25E2CC1B35FD5619ULL, 
            0x21E9BBBE885FAF37ULL, 0x2F306C324A36E7B9ULL, 0x79CF17D0BC36E608ULL, 0x49F9781AD6E396E4ULL, 
            0x95C8AB68347ED2FEULL, 0x8AE9AFFF4807BCD2ULL, 0x4DA15B2395AD5C4DULL, 0x7390B6F8225A1B68ULL, 
            0x3C3C90D3986F906CULL, 0x779A50ABD448A1BBULL, 0xB1F98AD5CCA7DD96ULL, 0x7D7D993E88359C40ULL, 
            0x7B3B8212BF59A484ULL, 0x6D2A6430D23C6955ULL, 0x8B4177A57CD14102ULL, 0xC5C78366CED794F4ULL, 
            0x05C4A52E12A34924ULL, 0x0C81E71D4497F97EULL, 0xB076AAA698F319C0ULL, 0x36F12662582871D4ULL, 
            0xA3695A299DBB8D0BULL, 0x77F6A7051A33F3DBULL, 0xDA5A33405C120AD1ULL, 0xC8F6CC356EE3AB2AULL
        },
        {
            0x1C165AEDB1F5A040ULL, 0x169DB6012DD9000BULL, 0x8A3B842BEF8768E9ULL, 0x0031D0EF5FD582BAULL, 
            0x1DDDF0BEC2769243ULL, 0xD69D404BA9CF8D2FULL, 0xAAA1313AB675797BULL, 0xFE276EC3D8EDFEC9ULL, 
            0xD1F02C1E5AF4CD8CULL, 0xA05E24FAE56D0558ULL, 0xA74C1C6819E6A279ULL, 0xB022C0DD3B0E2EFEULL, 
            0xC5E618E1092D531FULL, 0xC2CEC3027EB73F16ULL, 0x93F733F863B71BFFULL, 0x2E059DA65C678503ULL, 
            0x5350186B79FD5938ULL, 0x2F295F3EE0FB1721ULL, 0x6DAAED34C08C7BA9ULL, 0x742FF3CEE79DACEDULL, 
            0x8D7C8B51A3AC5616ULL, 0x32F23AB620CC8AF5ULL, 0x42546C48C090AC10ULL, 0x0B94237A7C3FF0AEULL, 
            0x3C1EA481E1CEA0D2ULL, 0x9FE9A14FB7FD4911ULL, 0xD2186B13FABBD307ULL, 0x6F50C9B6EB2497E9ULL, 
            0xED26043A52AA95B5ULL, 0x09F5E623CC33724FULL, 0xF109418A0510A5B6ULL, 0x0FB307527F8AD83FULL
        },
        {
            0x7EC80D5B06BDAD2AULL, 0x849C32AC96CDEDF5ULL, 0x35AA1C1E284322BAULL, 0x1BF52403645EBED6ULL, 
            0x86B746F3314130B0ULL, 0xB01BD8E5EC8B1BDAULL, 0x9E368ABA9E5D465AULL, 0x1910E0090E9811FBULL, 
            0xEAC295FBD94D72CCULL, 0xF8A0404CA749080CULL, 0xA8C8093B61976F5EULL, 0x99369CFD73A6BEAAULL, 
            0xA30810FE92852379ULL, 0x32625DFD8616D32DULL, 0x6B62FD27DB711FAEULL, 0xA5653DD505314850ULL, 
            0x704C43425B581E3BULL, 0x9A508BA888A8E85FULL, 0x6256EF2D23EBD369ULL, 0x6C1716409DE31583ULL, 
            0xD22EE3FA6573E906ULL, 0x5D4A1B15DC90C4B3ULL, 0xBE9F0EE50EC9C4D5ULL, 0xAC134115A9FFCAF4ULL, 
            0xA42C3609C5049EFDULL, 0xB5325B391728B99FULL, 0xAD01D752A90E9C35ULL, 0x05EEFB9F3C73F515ULL, 
            0x48387A37D88E5D2BULL, 0x79D1E04DF3EF3CFDULL, 0x1F721D8B598BC848ULL, 0xBCA37670ED6497E8ULL
        },
        {
            0xB13AA3551B971EF0ULL, 0xEE6063694503AED4ULL, 0xB6AFCD83662D4EF1ULL, 0x207E65224D9C8BAAULL, 
            0x46A38E3ECE03117AULL, 0x185F0EA514682A89ULL, 0x16A89A6551045A13ULL, 0x3162AD0FCDBC6E16ULL, 
            0x178369857EF74E91ULL, 0xE832F93700A71B15ULL, 0x2CD9D3832AE9A523ULL, 0x133805BC8FA993C8ULL, 
            0xDCFA79907286C920ULL, 0x02FD2D570DC77951ULL, 0xB54124BCEAB88121ULL, 0xC3F61888A61D0052ULL, 
            0x768189E9EE41FADCULL, 0x27D844E268C56909ULL, 0xB38693E53C9D6ED2ULL, 0xE87B5A92EF62D661ULL, 
            0x667B96EB64276236ULL, 0xB7F7280D5973F896ULL, 0x2C6C4DE6F642FA9BULL, 0xE2F9F5C2C1DAB0F0ULL, 
            0x0722CC6D316803FAULL, 0x81D25E808156D31DULL, 0x680D07E84EC32C0DULL, 0x74BF63EA2884A19CULL, 
            0xAD3687DDCD58A8C5ULL, 0x83CCADD72626F517ULL, 0x0C64CDBE043A33A9ULL, 0x9E8F9A73FE14C22EULL
        },
        {
            0x4CAB5A676A689446ULL, 0x440236E040010223ULL, 0xAE9B62A79B511E3AULL, 0xC612A747292AA1B5ULL, 
            0x0E0D8974BA443FB9ULL, 0x67CF18332C5C02D6ULL, 0x1212D68C8B94F2FEULL, 0x2360BFAF053157A6ULL, 
            0x220165AC1D595557ULL, 0xBCEB84ED4CA79077ULL, 0xB9FE43BFEB50706BULL, 0x2836F2424951E692ULL, 
            0x69F426026B94AC89ULL, 0xB64B6DA28D9385E0ULL, 0x6F3CE407DAF1D51CULL, 0x77B5FBB9DFCBC4C7ULL, 
            0xE4B653F7ABEC3B27ULL, 0x255F2FB22C2BFB6CULL, 0xDEE96701EFFEE253ULL, 0x40148C58D1F1C418ULL, 
            0xB90310D16D5CB3DAULL, 0x4A848A4E2039E4C4ULL, 0x0EC508DEA52090D2ULL, 0x4680E69AE2590A21ULL, 
            0xE77993980E45F09FULL, 0x1B8E6885C43A7BF8ULL, 0x7AD4389D68E76254ULL, 0xB067F6AE921BD045ULL, 
            0x0E99E1B97C91537EULL, 0x1D2948324C57FE81ULL, 0xF65D71D7CA1DD6AEULL, 0xDC57407A2D8499EAULL
        }
    },
    {
        {
            0x89A85E32549D2F5EULL, 0x70579C9FC080F3D0ULL, 0xC2E647814BD171C4ULL, 0x14FC4F8D2608C6F9ULL, 
            0x203AE4D3044DA7BAULL, 0xB709FCDBFE2CF48FULL, 0x874D718C4F798339ULL, 0x875F2798EE27FE34ULL, 
            0x42F82A6DA50705F0ULL, 0xD5AC44DD5F77CBD6ULL, 0x09C0EC56FA92A738ULL, 0x295DE7BAE762CCD6ULL, 
            0x8C6E7ABF4B23C924ULL, 0x3800FA849B7B7809ULL, 0xCC73DFBD3A951975ULL, 0x5545749DF606C565ULL, 
            0x1EE238DD1BADCECCULL, 0x1B440926EA076208ULL, 0xF2591B791879045BULL, 0xF33FD7B5F86E5B95ULL, 
            0x3113293DC0235784ULL, 0x39BAA72091DE5701ULL, 0x9F2CADDDB65CAE3DULL, 0xD8DA8F12BD8003EDULL, 
            0x064EB23BC4929EEAULL, 0x5269C41D7F0D1D08ULL, 0x964EC9D6AFFCCF86ULL, 0x359ED486B1AC856CULL, 
            0x2A34A490BEB1F809ULL, 0xF06F1B1ABAC0DC50ULL, 0x475D629741C5C7ADULL, 0xD9C348170A0BC06EULL
        },
        {
            0x6E6D7FC349AFA23AULL, 0x34D46FA346C8F459ULL, 0x6146310F5F97AAEEULL, 0x14541A9FFF7624DFULL, 
            0x2B1091280E83FA0BULL, 0x7E504B3FFD3F5739ULL, 0x83C8DD1CC459A76EULL, 0xDD25396DD999C720ULL, 
            0x0FABAF7832154470ULL, 0x6E8E7368A4A68256ULL, 0x2486A8E76091FF93ULL, 0x88557559BF826A43ULL, 
            0x50CC15A21F4CF268ULL, 0x078C80C9BACC0EA7ULL, 0xB8F5BE29D221DF65ULL, 0x4098E3326B9BA2CFULL, 
            0x2074F1486BDCB2B0ULL, 0x215C3AD44081D59EULL, 0xA212A46EF5ACA7DEULL, 0xE4386A914DD7ACF4ULL, 
            0x35E950504CF6DC88ULL, 0xDDC9E5E75E676ED1ULL, 0xAE26DDCFF3B0F544ULL, 0x1FD019164BE0BA36ULL, 
            0xE66B979B53DB1030ULL, 0xB545C37A17002230ULL, 0x617F2C8A81381107ULL, 0x63A132C5A487F7FDULL, 
            0x73FFE2DC702B99E7ULL, 0xEAC146588B0E50F1ULL, 0x3920D92EEF52FECBULL, 0x708112F69500064AULL
        },
        {
            0x7C6403A975848F3BULL, 0xAA39F598F90D31A2ULL, 0xB867521B20702434ULL, 0xCA3F93F9D4D447C1ULL, 
            0xEE095D5A5D4BD164ULL, 0x4BF794FB473C0588ULL, 0xE4BD8DEF23133318ULL, 0xEC0326F7CAAA6D4CULL, 
            0xDB9277712FDB56B2ULL, 0xA32CDBB7DE259BDDULL, 0x67CA73BB84097779ULL, 0x762F3EFE4AD7C73BULL, 
            0x86F25A962FC5204DULL, 0x23912E43561AC103ULL, 0x6A41618600FCCAFCULL, 0xB8FDD2CE1BD7D965ULL, 
            0xBBCE0A0F9C0F6998ULL, 0x89DDC8B12E50E445ULL, 0x12A2868AEDD5E41BULL, 0x43601BA47CD0C26BULL, 
            0xDA2FE66648AF2F28ULL, 0xDEA4113DFFED3937ULL, 0x0AC54283ABEF67F6ULL, 0xEE8F480C87FAFBBEULL, 
            0x34BBA78A2B86E1A6ULL, 0x45B9EE694A15671EULL, 0xD64D59ACD000C415ULL, 0x9B061C13F792BD2EULL, 
            0x778206A709584447ULL, 0x4B1C7EEABBEA5F97ULL, 0xE399B48ABF3D35F9ULL, 0x17277144FFAC2959ULL
        },
        {
            0xDF891D885EF8F173ULL, 0x17FCEF21874EED6DULL, 0xA0D1A5C19901D452ULL, 0x3E6658420B2CA913ULL, 
            0x4FB8788B3A1331E3ULL, 0xF0A8AC50450871D2ULL, 0xEABDBB0C3AA24C95ULL, 0x543674A77C16B49FULL, 
            0x721964E04F6CD823ULL, 0x8140CA6338AE082EULL, 0xF5176249664038EFULL, 0x0B8109388C37074BULL, 
            0x2EEED5375AE38F4DULL, 0x141A25E6747D195CULL, 0x19B3340E10A7CA20ULL, 0x00C4688CAA34EA60ULL, 
            0x84C2EE027D497360ULL, 0x778C68469B8B24AAULL, 0x4C6973224BF686B2ULL, 0xE00DCEE440B228FDULL, 
            0x3317328039DE15C5ULL, 0xC09B84C0A03395ACULL, 0xBE43498DAB85D372ULL, 0x017D96C991CABA19ULL, 
            0x6DC8F809E6CB1F87ULL, 0xF4A9D7533BDAF212ULL, 0x33354816032B362DULL, 0x69617A9B74B4498EULL, 
            0x290395CDE8763B1DULL, 0x6A38EE72331919FFULL, 0x85131746BF95C70DULL, 0xAC422E6E7C7D235AULL
        },
        {
            0x83C6AB9A961E8439ULL, 0x2D2B4345CE6B5BE8ULL, 0xA58490EDC1C9F5B9ULL, 0xD48051986656187BULL, 
            0x94A381E657F61821ULL, 0xAA4CC6279DFA9D2CULL, 0x853DC030DF5BDF0AULL, 0x166D9CCC2FB62CEFULL, 
            0x81E9FAAC8EC89910ULL, 0xFC6DF265DA35D727ULL, 0x7376B45D6B1DFE24ULL, 0x9F402183EC0B4BABULL, 
            0x80F341DB0D7E83B4ULL, 0xECD12B3E3260D55BULL, 0xAA56D34574C933DDULL, 0x2A1505D322F9D728ULL, 
            0x93C60C7B02A1BE83ULL, 0xB3344651961C422FULL, 0x291FF20F1967516BULL, 0x0A8B971386645760ULL, 
            0x00BEABB6303D0F63ULL, 0xA73650DA0A21705BULL, 0x10DB4C3A1BC18066ULL, 0x070211D913DAE950ULL, 
            0xA3ECE08454596916ULL, 0xA0A8587BABD9F11AULL, 0x6C9C56F0EBE7DA2FULL, 0xD3BFBFF84A735DE4ULL, 
            0xAC6ECE706FE8A93FULL, 0xF776F40570DDB52EULL, 0xB96682F0F31D3433ULL, 0xDB1F9AB11D5B345CULL
        },
        {
            0xBD378FC58FFD8F41ULL, 0xD3EF6225DABF845EULL, 0xEFE5618620F821DCULL, 0x6FB187CA769EAA74ULL, 
            0x4034A1D656DA9927ULL, 0x525831F28659BA47ULL, 0x1533EBB825FF8149ULL, 0x442F377D10BC79BAULL, 
            0x485A0064265B4F4EULL, 0x06890D88A31D5D97ULL, 0xF4CB9B4484314980ULL, 0xB207655D3E5C585AULL, 
            0xFDA3AD4F9F9C129CULL, 0x5899708C72912723ULL, 0xF8901C5CDA3E971DULL, 0xCBB02409BC7B6EE1ULL, 
            0x44C886349DBBDB20ULL, 0x12168E6B149F2EE9ULL, 0xA0EEF041F0EE9866ULL, 0xC302E0E2D8A14D86ULL, 
            0xFFE382AD23D5D223ULL, 0xF80E0F6E48C93CD4ULL, 0x793A91908BB28132ULL, 0x5FFA00995A145399ULL, 
            0xAF8ADBFDE1D732EEULL, 0x4C3200419FC112DEULL, 0x62067BD1E580ACF4ULL, 0x3C1AA4B932333F82ULL, 
            0xBDFC1B84B27C0E15ULL, 0x7B3468F14EAAECBFULL, 0x69B9784DF0C0714BULL, 0x771BB3ECF6C8C6F4ULL
        }
    },
    {
        {
            0xA31E0409EB7F9244ULL, 0xFB17521405AFB8BBULL, 0xCAF0181D8DB99670ULL, 0xCA3D8DC921A29D8FULL, 
            0x60E35605803CFC2DULL, 0x10CE6FCC1D516C5DULL, 0xF818E12C538DB79CULL, 0xD65C44BB5D703BC9ULL, 
            0x504236B5B8DC1FCBULL, 0xDAF56E07B4E1C015ULL, 0xB098CCDD44E2425DULL, 0x8834641F2755B870ULL, 
            0x74CDC394A9BAB7A1ULL, 0x6B21BBB003D7416FULL, 0x5E82EC7B265FB622ULL, 0xFF3BE9FC6C66078FULL, 
            0xD6E053695F1B17E6ULL, 0x2F77582D0BD66A43ULL, 0x9C7BD04A9B8417C0ULL, 0x90464E1AAB1FC075ULL, 
            0x6D024015B24970B6ULL, 0xBED68FCB48F68779ULL, 0x3ABAD70E9F2784BAULL, 0x2DDA2A9F5BFFF9F9ULL, 
            0xFAD6A80E30B624A5ULL, 0xDBCA5E7548081406ULL, 0x939E81EA80DD875BULL, 0xD6C0054BF52A96E1ULL, 
            0x7BB9E74FA14D7085ULL, 0x2FCC5BAB935DD35CULL, 0x42E5B10BFC45797FULL, 0xACDF86A4B2EE5E7CULL
        },
        {
            0xCC51BDFDBF539750ULL, 0xA2AD5424FDB51184ULL, 0x045CE85899EDDCD3ULL, 0xB9BF9EF6344E16A5ULL, 
            0x702C10767ACFD86FULL, 0x96AB848A58CC4DC0ULL, 0x20DA6684E2A8997DULL, 0x9107849684A2DDBDULL, 
            0xCCA8D0A1D007B25BULL, 0xC068C82A7531BAA3ULL, 0x73FE21F8433E8772ULL, 0xAE96CFF3B3570C54ULL, 
            0x48D649747617AAE7ULL, 0x5287DAFB26472B92ULL, 0xA05FCDA3622144DBULL, 0x26E69A229D11DE6EULL, 
            0x13F3D4D801816C25ULL, 0xCC8C9962570EE0A7ULL, 0x8E6727562F5E0630ULL, 0xFA2CF1E415AAAE48ULL, 
            0x0F4AC15CCE8F813BULL, 0xBFC6B6913C3F552BULL, 0x6C8F29885245AAF5ULL, 0x44EA249517448C73ULL, 
            0x94B0A6FC5B3FB9DEULL, 0xC169097E72DB6234ULL, 0x1978E4D3867D2B69ULL, 0xDC2BF778D5AB63F0ULL, 
            0x8AA67B4FB580F3D6ULL, 0x1DBC6855931EACFEULL, 0x8D670C63B66C9739ULL, 0xEA422CFA741983AFULL
        },
        {
            0xFD156FB95F65DAD9ULL, 0x32C932457925245FULL, 0x409C839D279500C1ULL, 0x52E9194FE6773F5CULL, 
            0x58352954F49CEE98ULL, 0x4E32376D5A878322ULL, 0xFF21F1D543347A8BULL, 0x5FED963FA075D154ULL, 
            0xD63972D3689F4E5EULL, 0x2A16DC90430ED221ULL, 0x88542485B04130CEULL, 0x4F2FCE6BFB226629ULL, 
            0x6C42814AE5E7E009ULL, 0x01EDD763982D80EFULL, 0xC687B3C4984A1D9FULL, 0x7EB402CD76E74C40ULL, 
            0x66F33AD7416B673BULL, 0x0A7CD4DAB9F4A3CAULL, 0xABE0BCE868C2F9E2ULL, 0xCA6BBE7783C2EA69ULL, 
            0x3C3C4BB16921DC3FULL, 0x0C9A7C6E94719224ULL, 0x471AA4F41F34E26CULL, 0x1B377CE1ED5AEF1EULL, 
            0x347CD5C308B8A714ULL, 0x1E57C5E893E3F98FULL, 0xB3EF5C1DF501F8ADULL, 0x5436F7F2A187DDF2ULL, 
            0x4A79ADC3A8F2AD9BULL, 0x0E5722EF90C3421FULL, 0xCC9706C4DD3D4F70ULL, 0x35640894AF6175BAULL
        },
        {
            0xAA68DC641D3D61D5ULL, 0xD3D4E25FF2B18AEFULL, 0x8C89D574B825AC88ULL, 0x72717FCBC9415974ULL, 
            0xAEB236FC5B76EDFCULL, 0xF628EB5891F8B9B2ULL, 0x8EA83DAA9BBD8385ULL, 0x519A3BA85978F7B9ULL, 
            0x6564250B08313B12ULL, 0xF6EA1422BDC6924AULL, 0xB2DE4B79E2FAFF20ULL, 0x9CFBCE7B6C66BAF0ULL, 
            0x44C962DB52D77E79ULL, 0xB249850840294702ULL, 0xE8042B6EDB876FBFULL, 0x86453AED3F9D9895ULL, 
            0x65FAAB624B18DBC8ULL, 0x23B819A791AFD47EULL, 0x14C2343C5FC830A5ULL, 0x0094AA47C42D9892ULL, 
            0xA23B44CB65D9CF2FULL, 0x363335FD2B8B8878ULL, 0x10612167138759E3ULL, 0x457EAB4989019D09ULL, 
            0x352D95969C1D2F7EULL, 0xB320181F08CAAF8BULL, 0x363FA2412C00BA55ULL, 0x33953318EE5BCA01ULL, 
            0xD983FCE67DC1C359ULL, 0xF4A004A1A4C10389ULL, 0xF07DA56DCF96EA1BULL, 0xB589774EED04DF06ULL
        },
        {
            0xA1CAFB5BE5D200E1ULL, 0xB1C25C2E3CEBF138ULL, 0x39D107E6E946412FULL, 0xD9CFEB7C666F613EULL, 
            0xC8E56FA09E570890ULL, 0x7499C9725F245BABULL, 0x2E0E92170E8F7893ULL, 0xFEFE986BF7E36FC4ULL, 
            0xBC4B44858030673FULL, 0xB1B6410712ECF822ULL, 0x20F1FBEA29A1C512ULL, 0x4ACD4034E69D3ED5ULL, 
            0x820A36519867D2C4ULL, 0xE279F8AC8188C47FULL, 0xCF04D732982131C9ULL, 0x8661B2DA2DCBBD1DULL, 
            0x53FF22F0A62FD50FULL, 0xA616ECA3D8D7FD2FULL, 0x3D0366CED977D324ULL, 0xC637D0763CE74BFEULL, 
            0x934671C1A26FE63AULL, 0xBDFE1423E6AEBF0BULL, 0x3CCD4D9A28A22527ULL, 0x7D064209830E5FC4ULL, 
            0xE7BB9C6B412425A1ULL, 0x47DEC93DD160F427ULL, 0x8124D249F9647B6AULL, 0x10A9904C7767E394ULL, 
            0xED9CFBDEE7F1FE96ULL, 0xD43134A94089281DULL, 0x118C1289EEAFA7C5ULL, 0xB33299AB16269C3DULL
        },
        {
            0x83269D55089ADEDAULL, 0x1C3B3FB54E822167ULL, 0x868BDDE1FD6EB1ABULL, 0x759459ECE0DDBB15ULL, 
            0xE72656E338686BA2ULL, 0xDFE81B01561DEA3FULL, 0x83DE6A05040571A8ULL, 0xC204F7C132C8217AULL, 
            0xECBF81F5BC887B5FULL, 0x36AA32AAED23FE8BULL, 0xC8CE3DD53620906CULL, 0x75E5E803FC5EC2A9ULL, 
            0xEE171B60E8893E9DULL, 0xA431AD4E18E3963BULL, 0x802A602B8B67CA90ULL, 0x1BBE434525E1AF6EULL, 
            0xB109FE6204BAD770ULL, 0xF9962195CEBC31C2ULL, 0x019D58EB8AD84787ULL, 0x69021CB8D65267C5ULL, 
            0x491B0AAA93D5E0CFULL, 0x70304C935B68BDBCULL, 0xA2B25C66CABD52E5ULL, 0x451481668FC12EADULL, 
            0xC9BA7337CA439F06ULL, 0xCDF92008652E039CULL, 0xF450A8722D60F526ULL, 0xF4447A4A30648C80ULL, 
            0xDFD33D58FD9EE52FULL, 0xD3B6F02710E2EB0BULL, 0x812F4C87E60DCCB6ULL, 0xE34BF94C8FE6C8C4ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseEConstants = {
    0x226B48538C5008A8ULL,
    0xEC09991EBA743D3FULL,
    0xC316281FA34AE5C9ULL,
    0x226B48538C5008A8ULL,
    0xEC09991EBA743D3FULL,
    0xC316281FA34AE5C9ULL,
    0x7269A7F50EF6CA54ULL,
    0x72C5D5D1E831A97BULL,
    0xC0,
    0xA8,
    0x19,
    0xE3,
    0x77,
    0xD5,
    0x41,
    0x9C
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseFSalts = {
    {
        {
            0xCBC5C59E8A010AD5ULL, 0xAA117241995FCAC7ULL, 0x7F43647DD9063DD5ULL, 0xBD556AC38E86483FULL, 
            0xDEDBEEA3E3DD2BE4ULL, 0x02BC2CC06B0F2C70ULL, 0x3F30154253CB6E13ULL, 0xB1A14C8CBA915AD3ULL, 
            0x5BEF014539B4BDCEULL, 0x8B8A389AE4C92FE2ULL, 0x3D28275FCCC0ECB1ULL, 0xE35CF87525556433ULL, 
            0x59863595E4C55061ULL, 0x231ADF1C4A1483FAULL, 0xEE8226A138D65ED6ULL, 0xF5204268E1DBA779ULL, 
            0x3692D8F9861A9CE6ULL, 0x798D1913DD725EC6ULL, 0x90C551C2A6C9B482ULL, 0xB42A71DFBFF8999CULL, 
            0xB7A82B1DF6300039ULL, 0x949B1F38B7B76EA3ULL, 0xD2913166B3C23893ULL, 0xEB6B30E47E4F0615ULL, 
            0x93222EB9FA090C2CULL, 0x7F463B15D4B736FCULL, 0x88761F6A0ABC4A6BULL, 0xBD4472343E7ADAA1ULL, 
            0xFA983DE025285A76ULL, 0x0F5895FF42C9D6C5ULL, 0x6736DF9429FB7069ULL, 0xFFBAE0DEFCB45643ULL
        },
        {
            0x90AF5F0D5EC5DCD0ULL, 0x994E691BFEC23F37ULL, 0x62B6AE8EC2B0A90EULL, 0xD8959AABAA9BEB17ULL, 
            0xB31A4AD83DD51519ULL, 0x93274570358D9FABULL, 0xFE77F7D9AFE3D743ULL, 0xDED5874D3E84A071ULL, 
            0xFA0E5A5D2142AED7ULL, 0x2D6DE55402EF7B01ULL, 0x88E6F3A5AF4BA3F7ULL, 0xD2B576740C47BB5CULL, 
            0x106B6591FCA9A778ULL, 0x3497C0F111605168ULL, 0xA7782A09E9C15F28ULL, 0x9FB4A8F16B568782ULL, 
            0x35E4BFFB71DC3360ULL, 0xBBA81A347E684E6BULL, 0x593979AA89C419BEULL, 0xC89AF475BBAC5508ULL, 
            0x160B5D8422634E54ULL, 0xDE2E0E1C33CDC7F5ULL, 0x4BEE5431FD89B5A4ULL, 0x7569B8F6EF76CCA8ULL, 
            0xD5804EAA00149D80ULL, 0xE8648E7E7B6278B7ULL, 0x9DAE946CDADDCD3CULL, 0xFD69325454D90D83ULL, 
            0xF6918635A61D6413ULL, 0x115ECDDA75CFFBE4ULL, 0x9906CA71517D2E24ULL, 0xB6658B399A0B5AD6ULL
        },
        {
            0x890DF2737F294F81ULL, 0x1B66950FBF5B34A9ULL, 0x279E15AE63845CD9ULL, 0x35B31FF01C3AB346ULL, 
            0xC51B5502E3DB9DC4ULL, 0x625D4BE73FE85560ULL, 0xAD7633B932674322ULL, 0x88AD8FF64BB80864ULL, 
            0xEA01CB41556D34EEULL, 0xC3F68C3ACD837031ULL, 0xE7BF2906B2B17D63ULL, 0x8C2C39558D4F2DF1ULL, 
            0x7A3E52206EF2E615ULL, 0xD87D687027CD62CEULL, 0x01514C4412E34BBCULL, 0x60F9846C7EB9E175ULL, 
            0x08ADEEAA57265FD2ULL, 0xAE98899E2543C98BULL, 0x50C87AC1AC54A96DULL, 0x1B8C91AA1FC7C667ULL, 
            0x3928402CF34F6553ULL, 0xBA7F791F1DFFBCC1ULL, 0x9D42AEB6A1A6EE3CULL, 0x44B3D80DA0C18D5BULL, 
            0x0B6CB1D20F17FA17ULL, 0x31273CA5DDB5F21EULL, 0x2828F9D3EF2C10F1ULL, 0xD2B02646335CBDD0ULL, 
            0x2871106BBB5CE707ULL, 0x4380FC62F9EA833EULL, 0x7720F392CE5F8895ULL, 0x9560C2541C6461A1ULL
        },
        {
            0xD21A1F98B3C27135ULL, 0x169EA12BFFCF6D47ULL, 0xED949A9DD48FBEAFULL, 0x9546DDD03C92F01CULL, 
            0x133A7214267E81BAULL, 0x410ED309788ED8D7ULL, 0x49A347439069A67AULL, 0x37CCD85CA4F33E30ULL, 
            0x3EAE6526F0C9C150ULL, 0xB4E4E24983581E85ULL, 0x65EA91CD2F44DCEFULL, 0xB3A67DCFD209BF99ULL, 
            0x59709FC8401D7222ULL, 0xF8EBC1EE947396E8ULL, 0x0A3CC205AA7F4830ULL, 0x945452265A2B776FULL, 
            0x17D2807913763692ULL, 0x14609B701D9A166CULL, 0xF080059B4154440BULL, 0x6562E4A598B4EF6AULL, 
            0x69A6FA0CC777680AULL, 0x674BF4B8F71FEC53ULL, 0x0140537340895D55ULL, 0x68C21C3A006CA0B9ULL, 
            0xD3A463865D44EAF7ULL, 0x42BBE5C591F86D87ULL, 0x3C582CC9C6E213DEULL, 0xBC1677ED7C600EDBULL, 
            0x3917CCCBCEC14D80ULL, 0x071FBE4768C4CFBEULL, 0x3BF7CAA66AF74D16ULL, 0x342F6073E53DCCD7ULL
        },
        {
            0x3E432A3BDB8D618BULL, 0x0CDDAB989D7CDEA0ULL, 0x29142CEDA48AE00EULL, 0x5E498DF16B2EBBBCULL, 
            0xBC324F63F420FD2CULL, 0x3347C78748B00A6FULL, 0x8F01CD5FCA31BAA8ULL, 0xA2C2BBF6D1D0B5FDULL, 
            0x299A90A3D3D956B1ULL, 0x19F8E5EDEBA5A864ULL, 0xDC44B3BF2EA83B4DULL, 0xD06E8F767978DC86ULL, 
            0x52DAAFC312056B07ULL, 0xCB8737A6586C2807ULL, 0x412AE266679CDD57ULL, 0xE1A529FE4135AA1BULL, 
            0x2C00F50868A4EFF7ULL, 0xC14980F3ED25D019ULL, 0x11D7AE1CF85A8A79ULL, 0x8C9DF605C3CADB88ULL, 
            0x1ED20BC39E1F0436ULL, 0xFDD3D7573219EE14ULL, 0xF33CB2F1AA77FBABULL, 0xAD1E2D18F51730A6ULL, 
            0xB8DE40C7D1C40FF6ULL, 0x25C4215824A36A4AULL, 0xA177CB9372A74194ULL, 0xC5202758515706E4ULL, 
            0x70BBA5DF760E5BD3ULL, 0x7179F74E8595B6EEULL, 0xF74D75008F4696F5ULL, 0x55D07C4D9B67E89FULL
        },
        {
            0x048A74622838CE3DULL, 0x66E493E581ED9AECULL, 0x223BBD94DF63A773ULL, 0x83DDD75394DC4898ULL, 
            0xA6457BC692652CD5ULL, 0x238FCB5C5DC231E9ULL, 0x50A34D499F1C98F9ULL, 0x1B53A8D5D31E19BFULL, 
            0xCB28F96EFD8C9330ULL, 0xD319A8797BC58232ULL, 0x3522B86570BA78EBULL, 0x9BB16CD58590E616ULL, 
            0xC7A55477E4117949ULL, 0x8650A8D5632B0D84ULL, 0x07499CEC815660AEULL, 0x581ACE2659F6A57EULL, 
            0x189E9FF09918E9C5ULL, 0xC1BD90A3CD2C6AA2ULL, 0x10D574B894CDD756ULL, 0xCC6098AF3A9E7114ULL, 
            0xD24927C8CEF7B70EULL, 0xA41F4D1B9DC359C8ULL, 0x6BA53AC04A71A24FULL, 0x4848EFA562D1D341ULL, 
            0xCDABFF5B75527B83ULL, 0x75DCC451727474C3ULL, 0x16B586D58FC21A5EULL, 0x4ADB589B0062DAFAULL, 
            0xDD1359C9290878F9ULL, 0x02EA820D828A5C8AULL, 0x0302277BEE1EF917ULL, 0x66BA91B0FDBCC5DCULL
        }
    },
    {
        {
            0xD34FA926769EA3DAULL, 0x821C13B05039D33FULL, 0xD07E6D99A1D6A22AULL, 0xDF88AE06BBC96AB6ULL, 
            0xA62C7BC12B47DF1DULL, 0x92534683866F2B37ULL, 0x58D33E2A45565542ULL, 0x07F896BD9B8D7BC8ULL, 
            0x3330015E94B6B592ULL, 0x48E04CC1AA565561ULL, 0x570A266C44E890E1ULL, 0xDE63AEA8B793864BULL, 
            0x695DED38D5013558ULL, 0x744839F3DD459E51ULL, 0xFA4FEEF07E4895DAULL, 0x562151EB8553B091ULL, 
            0x2E52C6563E70AD51ULL, 0x4C56E48CB920379FULL, 0x17C21AD3C5C5F92AULL, 0x2F0E16B2D04B5C49ULL, 
            0x20C6D00A0B6FA157ULL, 0x924CBF9996E8076BULL, 0x5EEB086F79A279CDULL, 0xFBB2D48F705E28ACULL, 
            0x61E23E6668C0A74BULL, 0x8110E98CC04D2E02ULL, 0xC17FE6B9A54C3B31ULL, 0xFF72860683A2C07FULL, 
            0x2E625A1693BB66A2ULL, 0x4652EE0E45020B5DULL, 0xE36B5412373924ABULL, 0x025D8150600200CEULL
        },
        {
            0x552168683856258AULL, 0xBF87192954519694ULL, 0x43D13342B5385703ULL, 0xC1F4884C3F953CF5ULL, 
            0xFAA52C5AEC41FF86ULL, 0x87CC651EA2DBB799ULL, 0x4DBEA505B96B2D85ULL, 0x9792CAE654C122C3ULL, 
            0xF4F14B3E5916F16FULL, 0x947F643D72E4648CULL, 0xCF8BD54B547739B0ULL, 0xE1BCBDFDC34931C1ULL, 
            0x8F391DFD86B10D9CULL, 0x55C529F6383F2C27ULL, 0xDEA5D45AC47B5D77ULL, 0x21A6BA15CF19431BULL, 
            0xCE813DEDA0529D9FULL, 0xC2BF982C3D8054CDULL, 0x409F0FB18675CB81ULL, 0x5F17FDBDA431ABA3ULL, 
            0xA09D42612675921FULL, 0xA10052C296FF73A7ULL, 0xF02D3BBCC6978716ULL, 0x4456FD31F2F2AD5AULL, 
            0x1E82E01C13E08AEEULL, 0x19B2F986DC24862FULL, 0x4054520E063E910EULL, 0xE1560E120878410DULL, 
            0xF77A2462F8F8F17AULL, 0x1EE046B3F3A849D9ULL, 0x4585955EE791EF74ULL, 0x4F6CE5F1AEA58E71ULL
        },
        {
            0xC644CD3F6D409A93ULL, 0x802F5CDB480A29F9ULL, 0x5ECCF6037B09D00FULL, 0x75536F86405C8534ULL, 
            0xBEC93734234C5AF8ULL, 0xEF902C08EC28D7BBULL, 0xD6A0988859688FB4ULL, 0xACF57B6D06095862ULL, 
            0xCA5AFDCF340E39E4ULL, 0x03E2AC3A41073DA9ULL, 0x3E6E896F100B6CB5ULL, 0x238E3BF1757CAED1ULL, 
            0x03A006EEA64EABB8ULL, 0xA536BD9B4199851FULL, 0xA95253B4C80AFB61ULL, 0x6A4E5F80C1626CB9ULL, 
            0xB43D5638C421BB12ULL, 0xF7C10FE704F18C99ULL, 0x166134350DA99634ULL, 0x090E1C034C5D70EBULL, 
            0xFE3CD5F37258E9F0ULL, 0x374725876D2D5055ULL, 0x8F276DE1A2B43BA0ULL, 0x3286A3E2968935B8ULL, 
            0x9A03E0FA0129B561ULL, 0x984165B0A5D47CCFULL, 0x74492F6927C40790ULL, 0x485467349526CB20ULL, 
            0x4A74DFD69DB670A6ULL, 0xF6F030F0D05A0F32ULL, 0xA9C239E569701B89ULL, 0x67204DDE7D52AE65ULL
        },
        {
            0xD9A53DEB86621B70ULL, 0x9E0C4AEF7A97A2C1ULL, 0xE9E894808DB8AFF5ULL, 0xDBA80CC1D911D841ULL, 
            0x056CDF999063EAECULL, 0xB7A3BD05A954AFD5ULL, 0x51911BECFEA5231AULL, 0x809A7BD92EF7F400ULL, 
            0x9F3E352923FA897FULL, 0xAFFC1F0F3FB7A04AULL, 0x9976F7D9E8393E04ULL, 0xA9BE282DFC70627AULL, 
            0x82C3F638351309D1ULL, 0x86B360B0B11D48C5ULL, 0x8E3668582DF2CDE1ULL, 0x9BA5AC7F436CBE39ULL, 
            0xFADDDA8D20383D2EULL, 0xC177B2D0692A3A73ULL, 0x994A4DCC16D6974DULL, 0xE496712202336C34ULL, 
            0x615C031FC5190180ULL, 0x84ECD1DD4760820FULL, 0x59E2173F0800FE1BULL, 0x72CAFDFE54537321ULL, 
            0xEC313900CC65E780ULL, 0x64773F3EFB03DC79ULL, 0x19D1C0BF10B00B14ULL, 0x8BED20366C61C430ULL, 
            0x8D9C28587CBEB297ULL, 0x90F65FECF16DABF7ULL, 0x1896F641E070C07DULL, 0xFC7D8FB414DDEE1EULL
        },
        {
            0xE42880D4443C462DULL, 0xE483DBAA84DC25CAULL, 0x4B1ADB4E0BE3E63AULL, 0x4FEAD8BE6B63B0B7ULL, 
            0x8DE55F3117264DACULL, 0xFD29E3D3F9EEE6EAULL, 0xAFAD1D81C27D3CACULL, 0xD3347A8D84A08B29ULL, 
            0x4854ABA3080DFE74ULL, 0x380F777E1A1FDBB9ULL, 0x010BC21736FCB0C7ULL, 0xA110EF74A5E9A0D1ULL, 
            0x032E28B0C9E9D56FULL, 0xD7CEEA72EB36808CULL, 0x382C5E02AA5DB434ULL, 0xBBA83A06520B1CD2ULL, 
            0x2B28937759B03882ULL, 0x5740D619317C7624ULL, 0xE55D204B6AAF1013ULL, 0xB9D1D74CD8A97E2DULL, 
            0x433A2B5B80A12CE9ULL, 0xD15D87E13960E48EULL, 0xE9A67EADCD79D97FULL, 0x62CECEF32B4D2810ULL, 
            0x01D1BA63831B8F3DULL, 0xBC2D27FF21A67DDAULL, 0x605DB353ADA95C40ULL, 0x7F4F621266172858ULL, 
            0x6BCEAE41C0C6EF41ULL, 0x839D1FFC9DBD3921ULL, 0xAC523B3F387C046CULL, 0x72DA04D2674DD37FULL
        },
        {
            0x659B30DD5E49657BULL, 0x037D92CBB7D264D6ULL, 0x068F513BFE56E0AAULL, 0xD527274108A3EA46ULL, 
            0xEA93AFD67E81F99DULL, 0x8EF338385D921BE9ULL, 0x2A81955A379F24CFULL, 0x8B872F098754202BULL, 
            0x858DBADC5FF302A2ULL, 0x4CC3F740DDB89EDDULL, 0x67DA71F7619DB255ULL, 0x370D849223F7A6D0ULL, 
            0x8F1D5016B708442FULL, 0xC6F50E215D46331AULL, 0x562B2B23B2730C50ULL, 0x0A7E848A8C99B546ULL, 
            0x7D512EE785EC0602ULL, 0xB06A4567F66EDBFAULL, 0x93AAAB75F019BD7EULL, 0x2B83AAAC6BB626CEULL, 
            0xD64B6828411C6764ULL, 0xA366138216AFF8C5ULL, 0xD62188A1FBC41E7BULL, 0x407DB206A30E8A66ULL, 
            0x8E03BEA80B60EC8CULL, 0xA094C9593383C107ULL, 0x03D88747B65ECB16ULL, 0x73176F30BC89EAB7ULL, 
            0x5268704E4EA6BBBEULL, 0x8B9B786B2931DEE5ULL, 0x8BB0BC1212B46CD3ULL, 0xB89E70E383BBF704ULL
        }
    },
    {
        {
            0x31DC26B81576E97BULL, 0x2E40AB6287533900ULL, 0x1E104E171C268482ULL, 0x93F141E1CE21CD3FULL, 
            0x5BC6738264D55BEFULL, 0x11D1BB3B58856B80ULL, 0x8CB67D57C8ACA53CULL, 0x0C3448F1E6BF7A2CULL, 
            0xA842B2DD685E795FULL, 0x517E130F88A1381BULL, 0x36481A1AB050FE14ULL, 0x8D0F69912F32D5DFULL, 
            0x68B2B91C681C2ADEULL, 0xECD1BB1C81DE3213ULL, 0x829D3F628E6A9D38ULL, 0x740B66177D30AF81ULL, 
            0xC08B615B60495F19ULL, 0x12D44803E80367D3ULL, 0x1F76FE50BC188A00ULL, 0x3197F118784ED109ULL, 
            0x44D99358DB8218B2ULL, 0x820591073D7BD4D4ULL, 0xEF43514426E870D9ULL, 0xD71981C9B55BBCA8ULL, 
            0x03421B8061BDFA80ULL, 0xE26B6A44B11586B5ULL, 0x2D57703C60970088ULL, 0x1B1CE53F8427E250ULL, 
            0xE59A9CA230E38CBBULL, 0xCC20DD207333CF17ULL, 0x81B5175EF8895058ULL, 0x6AE00AE5167F5541ULL
        },
        {
            0x5F03AEC612012230ULL, 0x043FC524203F65E5ULL, 0xD55F28CEED59222FULL, 0x3D34A4F4D09502A2ULL, 
            0x51C87C69166331C9ULL, 0xB4B03F567E12F296ULL, 0x407332B329B10780ULL, 0x1D612E06545B53A9ULL, 
            0x886CE4D46F36CF19ULL, 0x4B6B3D5279C8A185ULL, 0x983D00091A12F7ABULL, 0xB6C7A14D344E51F8ULL, 
            0x117C0F55CD349CD7ULL, 0x1B789B6E50429890ULL, 0x0FB716C9D601F0D2ULL, 0x47F4BA94E3CC2550ULL, 
            0xBFD29592337B8342ULL, 0xF4ED092C6D71A71EULL, 0xA574E21BB79CF75AULL, 0x797AE53CC9252C88ULL, 
            0x52FFF8D5BC9C73C1ULL, 0x18C49567A893B16AULL, 0xEED041F8920EC1EBULL, 0x004E85748D034DEEULL, 
            0x042BA78C59891C99ULL, 0x0099F945AEB2F71CULL, 0x2C2A4A502CA898A7ULL, 0xEC81F51A091836A9ULL, 
            0x31DAF0EEF117605AULL, 0x42C6124ED613BC2BULL, 0xD673EEACA4F3A325ULL, 0x9BC2E05A3BFD4802ULL
        },
        {
            0x50743F2401B55A96ULL, 0x1C0CBDA1788D62B3ULL, 0xFF49593854ACD0D5ULL, 0xDA17AF0F21C14768ULL, 
            0x3096AC46E5B4DE57ULL, 0xB43622F87A4C9B5FULL, 0xE3B1D1B4AAD9C230ULL, 0x180FC0A2F351AB4DULL, 
            0xDCF4D7C758CD978FULL, 0x4DEA6A576DBABBB4ULL, 0xCDCE152D039C620DULL, 0xF83C9A1FDB193AE8ULL, 
            0xA62E179E5C8F1E1DULL, 0xB7976C014E6889BBULL, 0x68D6D1F93CCFFF48ULL, 0x20F9181758A5695FULL, 
            0x1FBBA7E413B074DDULL, 0x29F3736151D67DFCULL, 0x7A7C73B3A2EF7D21ULL, 0x8E67049CD93A27AAULL, 
            0x7D552D6AF8C03DAFULL, 0xD0C41145E49C99C7ULL, 0xF3DCEE4E4D9618EEULL, 0x6A3CFB9D8DF5EBF0ULL, 
            0x62462DF6FED3BA52ULL, 0x3976BB986BDC230EULL, 0x7D70BB3BD4CA1B25ULL, 0xC11460DCB18EF78EULL, 
            0x615B140A7A0D5FA6ULL, 0x243F21EE89C6E357ULL, 0x7DD6CEC9543D9F3DULL, 0x7D27DADA4702D728ULL
        },
        {
            0x8F4DC09B1D8C948EULL, 0x38045AFBF0A53251ULL, 0xA9391209444FF070ULL, 0x1D5889327D417F55ULL, 
            0x3124A849CA767456ULL, 0xDE9015CF11C12F2EULL, 0xD12014B8857904BEULL, 0x8182CF4D39B54999ULL, 
            0x55DE2092825AC7D9ULL, 0x0DA31F69D64F51E0ULL, 0x886F3AC87736FDB4ULL, 0x8CAAA1CA2C3C3031ULL, 
            0xA9B5DE1EFCAC9C64ULL, 0xCAE7189221719C4BULL, 0x442CB639EA435F72ULL, 0xC0402FE8A803021AULL, 
            0xAB8D3A26B640FC17ULL, 0x675770B3E05AFEA9ULL, 0x5F701C2C6CACF32EULL, 0xF3E3EBAC63AB1DB7ULL, 
            0xE9EC5F396791C463ULL, 0xD91F1D01A193F801ULL, 0xAFBC9E5635820B24ULL, 0x3AA245CB4E36BE6CULL, 
            0x2F27F1F540A057D7ULL, 0x9E20AE820698E5B8ULL, 0x146B22F63DE244ACULL, 0xFD91AE8B10740F7CULL, 
            0x685D1C18ECD2A4C7ULL, 0x083F6BBC7C3210AFULL, 0x31E6DA76C3B9CF31ULL, 0xCF74EC81F379B041ULL
        },
        {
            0xC3A5E3B9BD7B92EFULL, 0x36A7AB91F9BC0B35ULL, 0x0B9CA3F0996F846CULL, 0xA0095AC061202D97ULL, 
            0xD6DD30D45847DEBFULL, 0x4B6175202763CF98ULL, 0x2531A1243C096E01ULL, 0x387CF05538955DC9ULL, 
            0x789D5A52DDD0F12AULL, 0x09DC159D0ACF0C69ULL, 0x0F9119596CE9B6E2ULL, 0xAD19A8AE249D0867ULL, 
            0x9999989FF6BEA6BCULL, 0x6DE0D69F90B31926ULL, 0xA304F6B829BBF83CULL, 0x16F0A014E8E2548EULL, 
            0x3ED696892B5A4B58ULL, 0x4A25BD292064970FULL, 0x4E4A226C08F7D042ULL, 0x7D569DBD5FEE444BULL, 
            0x00991EBE2DA6CB5CULL, 0xEB27652EF0FD8F49ULL, 0xAEC414AB69B4478EULL, 0x4840025DFABD8818ULL, 
            0x927FE3822984AF5DULL, 0xDFF01A5223CD33BAULL, 0xE07A7A968F0CB3A4ULL, 0x928BD8B080A120E0ULL, 
            0x7965AA6A7627FDB1ULL, 0xE4B5A0CCDF5D9713ULL, 0xB82C3666E942C74EULL, 0x02E4D6C80219B3A8ULL
        },
        {
            0xB4FB02C985D225B9ULL, 0xE39C2732E6DB6B4CULL, 0x97965C14B91C48D5ULL, 0x73F239425C7B7211ULL, 
            0x18A4A4EECEB91C02ULL, 0x7B6E80B55A32ECB6ULL, 0xDF7FAF1CDE299AFEULL, 0xF617580AD907FBE6ULL, 
            0x1C3E7CD41E360ED5ULL, 0x2E5F6B1556ECA208ULL, 0xC9FD68BB10DC27CAULL, 0xEA36E24BF2989F82ULL, 
            0x133B1DC47FE1CC78ULL, 0x307F6BD1A3A729BBULL, 0xD39E4A1FDE8CDFBBULL, 0xBB595B84BA7025FBULL, 
            0x0B319C43A17FD47AULL, 0x4BA6413A931B5435ULL, 0xF14FCD77B9DF51D0ULL, 0xDA29A95D673CD8A4ULL, 
            0x119BDD49F4E2486EULL, 0x5FCB3D76B8195C0AULL, 0xE8EE4E55E8810EFBULL, 0xAAA37908C2CFCB8EULL, 
            0x8C35221E89770FC8ULL, 0x046F0F74CEF6E6EFULL, 0xFF4CC835C674B780ULL, 0x605208052B419D21ULL, 
            0x8FD7BD764B8C64F2ULL, 0xC5963BF92F91BF22ULL, 0xD358B3B94135B083ULL, 0x3FBEC335E6DED077ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseFConstants = {
    0x5797086FE6E9508AULL,
    0x70765CB6D45C0563ULL,
    0xBBC31EB2144461C2ULL,
    0x5797086FE6E9508AULL,
    0x70765CB6D45C0563ULL,
    0xBBC31EB2144461C2ULL,
    0xF0FECD93ED33D4F3ULL,
    0xCDFB7A6D00521F3DULL,
    0x17,
    0x45,
    0xA0,
    0xB8,
    0x70,
    0x56,
    0x8A,
    0xA0
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseGSalts = {
    {
        {
            0xEBDC95FD845694BFULL, 0xAEEC7D7CFE742642ULL, 0xC162922D7BFB8C70ULL, 0x95DA681D1E150E69ULL, 
            0x05EA469D64FC87E4ULL, 0x0338B312F91E0A7CULL, 0x1428B49E66D22CA5ULL, 0x947A2B5C253A7A30ULL, 
            0x1A0413EB93B429A8ULL, 0xFB743138D436A717ULL, 0xDEFE53694834F408ULL, 0x2AD993B9F7868269ULL, 
            0x10EB7738EFF8AB0FULL, 0xA482F9437E3F671FULL, 0xEF1E1F5ACEEAA40DULL, 0xC76CF6222F351442ULL, 
            0x9435E4E18A21B802ULL, 0x31C3113D5722D679ULL, 0xF00506FAF1B1AE43ULL, 0x5F8F2B8C230B491DULL, 
            0x123F22042E8E6EE6ULL, 0x1B5ADE17AE934BDFULL, 0x04116F23C3B93FBAULL, 0xD08D2EFFD7504B09ULL, 
            0xC5935F2FA254DC7DULL, 0x47BFA6FB41801C10ULL, 0xCBC6706D24897B6FULL, 0x1B04751F5EDD3595ULL, 
            0xC4F370616CE7B4D1ULL, 0xAF226BFCB1BA362FULL, 0x8D7B8FAD032809BCULL, 0xDD2BF797C59E6828ULL
        },
        {
            0x682DBD44F5918B8EULL, 0x91C517DC038624B4ULL, 0x0402ACB2D68AA86AULL, 0x10133432BAC05D2EULL, 
            0x3B78CFBA3DE693AFULL, 0x492223DED9C47D0AULL, 0x62425DE83AEB56A6ULL, 0xABDF38FD1CE4482FULL, 
            0xFEDB28D112822208ULL, 0x1E448AB581B7617EULL, 0x4A1D8B9600FB0728ULL, 0x3EED7B68D6F4138CULL, 
            0xFC5FD17D0C437555ULL, 0xC3ABEEC142A0B037ULL, 0x1CF33A4D3F33DFB0ULL, 0x6CF7F4242D39C2EDULL, 
            0x939BFE6DEFEB926CULL, 0x34A592918E7BBE8DULL, 0x6E8C88A515DD8E0EULL, 0x3915431B32A01DD4ULL, 
            0x3CD30B713F99872FULL, 0x9FFF97FECC80C2B6ULL, 0x00504E9ADF298517ULL, 0xE9C0E5D1BD06F1F9ULL, 
            0xB2C5E584F7103AF3ULL, 0x48DE8D0C884AA1D8ULL, 0xCB9DF3B5772BD78BULL, 0x1FD5247CFD3F2ADBULL, 
            0xD4AA32E65718D4A6ULL, 0xFA5392442317765DULL, 0x494227294549D08AULL, 0x05C2C88101C0CA70ULL
        },
        {
            0x1B4B8E46E6B3DE79ULL, 0xB0E7EA512542042CULL, 0x6221268F2A34D857ULL, 0x6F3D8D2B52A445C6ULL, 
            0x84FCF98DC023E092ULL, 0xF259F2CE7F63C693ULL, 0x2AB78787390CDDC6ULL, 0x8154DB58E2C20F09ULL, 
            0x9762F66ACCA36235ULL, 0xA85AD742CBC1B37AULL, 0xBF52D585D64435C0ULL, 0x6E780D2973F3D46FULL, 
            0xAFB14644A1E288C1ULL, 0xF9EA67FCA48848B0ULL, 0xD7AA8F0F60E2B191ULL, 0x70B7EDB5D0ED821AULL, 
            0x307951AF76D2EB77ULL, 0x0C373BC065CC76A7ULL, 0x78CB4AD557BA47BEULL, 0x17CAD614914BF47AULL, 
            0x271427DF897475BEULL, 0x189835135895C984ULL, 0x71C52F52D77445A1ULL, 0xC46ABB20E701BFD5ULL, 
            0xEC4406D378AC961FULL, 0xB9581604B4164C04ULL, 0x94FEC207AADB06EFULL, 0x843D9E4F2E2C561BULL, 
            0x330A4F202278B8F4ULL, 0xAD026BF4C6E593A5ULL, 0xEF1ED1610E2CFD19ULL, 0xED87546AA3D52983ULL
        },
        {
            0x615E2F6D969CAEBEULL, 0x0A8991564940162DULL, 0x4ED7388201DCB7C8ULL, 0xBA1400C5BF38607EULL, 
            0x390A3D7EF418B574ULL, 0xA22D23F447C8F1E8ULL, 0x8526D8CAD0D98EB0ULL, 0xCE565BCAD1764E58ULL, 
            0x475B9CAD33665A20ULL, 0x46C11FA35F602344ULL, 0x05328724498DC3FAULL, 0xAFB337A9351E11E6ULL, 
            0xA9D91342128896F3ULL, 0xAA3D97E9F2904859ULL, 0x739F5D9C73849166ULL, 0x62FF7CC42F3B8236ULL, 
            0xAF29B0D888BABEEEULL, 0x611D51B1AA912203ULL, 0x42ECD224EE1D745CULL, 0xCF89A1CECC605913ULL, 
            0xC9C78E4D5A6A6883ULL, 0xE2C4441CB2DDB61DULL, 0x622B017535700EADULL, 0x8CE9F53471BB8710ULL, 
            0x933570BDC4ADFB52ULL, 0xB1B62C8A04FF89E6ULL, 0x0446A6F035A18707ULL, 0x764D54364DD31889ULL, 
            0x28D0D2126D4910D5ULL, 0x1D678F325C77400BULL, 0xB877E143A708906DULL, 0x82EC9A4582F7A3EFULL
        },
        {
            0xA82E43EE879AD48BULL, 0x07B984CA58969032ULL, 0x7E6E35E3BC012080ULL, 0x55C8F175728ABF64ULL, 
            0x158568B3821D298CULL, 0x4EF4732F0BE1E3F5ULL, 0xA0FBEA584704B2DCULL, 0xBBB2B9577B693C4EULL, 
            0xE8F647954C659507ULL, 0x81BED802CC246164ULL, 0x09332F779FDE2643ULL, 0xCFF33AF3ED63D9F4ULL, 
            0xECF8BFB1E158870DULL, 0x5CDF00B55ACAD770ULL, 0xD74F67E354C05126ULL, 0x285B7FBE2ADC513BULL, 
            0xA15324B4B61347A0ULL, 0x312A065475138EFEULL, 0xD425788DC61FB1F2ULL, 0xD28BACE40630D361ULL, 
            0x5AD12F8599E6CF22ULL, 0x80DD52042159686DULL, 0x5B55D717D2E669C3ULL, 0x6BED9A007295B36DULL, 
            0xFD0B658100572E9BULL, 0x96582486A7B6E430ULL, 0xAFC648396D1B4934ULL, 0x5F8D889E27308E65ULL, 
            0x84CC871DE0B9F443ULL, 0xB13BFD49764C67B5ULL, 0x6845BFAD0F31FEE1ULL, 0x4E968261D80E02FBULL
        },
        {
            0x17CC1B1E71165E07ULL, 0x34760DD3DC9E6338ULL, 0x9D54E401CEAB8BD5ULL, 0x4008DC89BF4EE420ULL, 
            0x40782861DE541E4DULL, 0x137DE49F18DC9CF0ULL, 0x2972D5D88D8ABB87ULL, 0x30A657D1ECE33FF8ULL, 
            0x415A4327F864DDC8ULL, 0x9C875E0AF32C109EULL, 0xD597D16843F770A7ULL, 0x0283377DD938DB0FULL, 
            0xA7E91B5B10989320ULL, 0x0FF9D771B976498CULL, 0xBB2E76AECB4D12A5ULL, 0xA8982453C22F047EULL, 
            0xE7F5B5FAB5F3F41AULL, 0x84DDDA8E3B96CDD3ULL, 0xE7C0F41FAAF48A6BULL, 0xEB2E80F0D10D9781ULL, 
            0xEBEE06BE3B05910FULL, 0xC33DFCD0E8FA4425ULL, 0xD7E42C9567301A4EULL, 0x670A3FA651FD2C4CULL, 
            0x7E78B5C102CEF527ULL, 0x16837BEB9E459ABDULL, 0x436902A374F44238ULL, 0x80F110D814B35020ULL, 
            0x39F4728A077D50A2ULL, 0x285BBB5660C5B167ULL, 0x107D96E31D89AF35ULL, 0x756BCC9674017261ULL
        }
    },
    {
        {
            0xA1B9F66AB1E0C13EULL, 0xFF109B19C7993EE1ULL, 0x7378FBC2E0E66E68ULL, 0x98F676233F049462ULL, 
            0xC7C63C111B4A9601ULL, 0x465B4A0E140A5289ULL, 0xE8F528166A96FADEULL, 0xCC034D9952283EA0ULL, 
            0xA0E508F18C9C7FCAULL, 0x932F0D625FCC65FEULL, 0x5CB9CA944FB60144ULL, 0x93E8895434CC4947ULL, 
            0x90D7460654296ED8ULL, 0x795C86672FC7245BULL, 0xC3755BD90FC5BDB9ULL, 0x65F4393C34388F82ULL, 
            0x2083EC6AFE1BF85EULL, 0x2BEC246B167B35FEULL, 0xD691C6BC337C09DEULL, 0x8C25A47320C0129BULL, 
            0x42336A2719DAC505ULL, 0xD9436B96CF8F1386ULL, 0xB86457BCC2D93AA3ULL, 0x3D5E7B03E9A735E7ULL, 
            0xFFAB3BB1B032A550ULL, 0x2BCD3BDAF17B9754ULL, 0x1EFA20B6E26C8810ULL, 0x29A4A25CD7BC316CULL, 
            0x676113B93C561181ULL, 0x881943B351F434F3ULL, 0x1CC8A4A52819DBC4ULL, 0xEDB5ABC71EF85CEAULL
        },
        {
            0x0D6CB9FC8A30E91FULL, 0xDF0415FE79C346C5ULL, 0x9D0E1AAA18ACFE87ULL, 0xB39C627515FE984BULL, 
            0x0FB727F3402F975DULL, 0x821222455E4D09C4ULL, 0xE41BA0E963CB046AULL, 0xC9FE8DE3BBE918DFULL, 
            0xB339FAD77D6173FCULL, 0xF5D201B8F5EFED5FULL, 0x789172C0C8495F53ULL, 0x4E58778D132A991CULL, 
            0xCE2FB716FAD88F3CULL, 0xBED9772747A682C5ULL, 0xCCF2EE33795C0840ULL, 0x00FFDB77EE71C401ULL, 
            0xC07D17E770214457ULL, 0x7CBCD7CFE193AC34ULL, 0x50CC5CE04D1F420CULL, 0xBC7BB51CCD706444ULL, 
            0xD249A852BF7EFCB2ULL, 0x399345B460E99BF0ULL, 0x90E391A874CF2D4CULL, 0x6CE4750C6A0B813CULL, 
            0x04667063914A92D2ULL, 0x87913DCAF7E09D07ULL, 0x1886302D65332DCDULL, 0xDEF95F4B63C5265EULL, 
            0x1584E7BAB6F1DFC2ULL, 0xF4D5EF53D492A71CULL, 0x6BD67D2E56A12138ULL, 0xDE8CAF1F9127861DULL
        },
        {
            0x8B709F62037C9056ULL, 0x7ED8E6A01C3CCC8EULL, 0xB7AB77B042AEDC12ULL, 0x1A55D0F858E02A01ULL, 
            0x6BD528EC0CDDCF1FULL, 0x479D6188771A87DFULL, 0x2B542A7E11BFAD16ULL, 0x2E0DEAA655644278ULL, 
            0x0EABF572648D360BULL, 0x3EDB1568EF1687D3ULL, 0x577A71AB85A27714ULL, 0x93BCD54F4DBB828EULL, 
            0xD60A0CB7A3DAA849ULL, 0x9CB0B72BE6BB7B06ULL, 0xDBAC867AD1E8D846ULL, 0x2DEFED2AF5FCF761ULL, 
            0xAB28E7FADA567537ULL, 0xE1D869DF1EC52FD3ULL, 0xC7EA529D47846DCAULL, 0xD01FF9DF1A9CD7CEULL, 
            0xC80A480D968E18CFULL, 0x99D3E4929961B994ULL, 0x7862A536576C326EULL, 0xAB6CD0DEE3A81306ULL, 
            0x7632DA76634295CEULL, 0xC1688DB42BDE38A7ULL, 0x3EA8548D339556C0ULL, 0x29E6AF81C5A926F3ULL, 
            0xA4F9F76BB016955DULL, 0x2F30C6B420A1A400ULL, 0x83CC6605FDB61D04ULL, 0xE8BBD867EA75271AULL
        },
        {
            0x2DB7FDD8D3F6293BULL, 0x483FE47A2B4394E2ULL, 0x12F0FB0DEB231D46ULL, 0xF8C6127D4FCC37CFULL, 
            0x67C7CD847A53BCBEULL, 0x68B5DF24338361E7ULL, 0x59FD42812FD4B085ULL, 0x19B878181B8180A2ULL, 
            0xC41A3825B56F53A9ULL, 0x8B86DD4053F03C8EULL, 0x8BFCA5FFEDA8E947ULL, 0x8608DBCDCDBF2E39ULL, 
            0xA29882A215156461ULL, 0x98E4117742B8A796ULL, 0x81E1D82D468F4CBBULL, 0x69A99661D8B4F7A6ULL, 
            0x7ED75BD9FD766BB0ULL, 0x212061D97CFEDDB3ULL, 0xE92ABC0E9F1BC90FULL, 0x2AC487848AA78292ULL, 
            0xD333FDDD5C999214ULL, 0x1FE39ED4C156641EULL, 0x2AEC165B64E9C6E0ULL, 0xA68C66CDABE231D3ULL, 
            0x07F445346A83E26CULL, 0x6036EE779B2033ABULL, 0x1EF097E44B028586ULL, 0x96A0BA78F5EF2518ULL, 
            0x4EDD46619AF145EAULL, 0xD52EEEC841281DB1ULL, 0xD31C9D2279F2863CULL, 0x4EEBF0B515824ABCULL
        },
        {
            0x391B656FFE59E5C3ULL, 0xD9E9F1F9A6772DD0ULL, 0x29EBED364CD2CB2DULL, 0x61B65D7B922FFE77ULL, 
            0x9C1B27481E8C90B4ULL, 0x8FDF8D956EF6BE30ULL, 0xE97BF85F6FF96AAAULL, 0xB5246A1DD9C82227ULL, 
            0x790D3DCAEB32B028ULL, 0x80BC3517F7CB1F43ULL, 0xF419EFD2B1938754ULL, 0x2ABC9521AE2E4698ULL, 
            0x64ABEC84E6D5F1C1ULL, 0x9D86B64C5DD06461ULL, 0x62F70B48BE8C4B23ULL, 0x9507678B7D258E8BULL, 
            0xB698C7E476BB653DULL, 0x2A8B691AA68562F5ULL, 0xF6B0FC0F1BA35982ULL, 0x33C020DB9EA7BD0EULL, 
            0xFB537C1B6ECF1E75ULL, 0x36F9D918067D400CULL, 0x7C69B3E08FCC8057ULL, 0xF373758A4ADB2469ULL, 
            0x82E2600CC2D978B3ULL, 0xB813E94F69756795ULL, 0x71813E4D679B9E23ULL, 0x8D8BAD1756B638EAULL, 
            0x83FE8DE83F50362EULL, 0xBFBED591B424FCC0ULL, 0x93F07CA5DD2122BBULL, 0x8C2E07BD03C4638AULL
        },
        {
            0xEBCD26F30BFD26E7ULL, 0x317CFA139BEF645AULL, 0xA70C5239747DF396ULL, 0x3ECD527E35189875ULL, 
            0xDD6C9E3440255D80ULL, 0x1E73D8FB66B1A878ULL, 0xEC618CC42E90E00EULL, 0x025555E103919687ULL, 
            0x316344CC11552878ULL, 0x64E8BE7DB792FD5BULL, 0x088DF2ABBEC49B4FULL, 0x1337C8107CBCB3B4ULL, 
            0xDB8FFD2596B1155DULL, 0x1CC82DEEE682399CULL, 0x44F92AD7005E4D6AULL, 0x48328EB4E6F666DFULL, 
            0xD4325A52FEB007C7ULL, 0xD81F9CB7A9246DA9ULL, 0x7B24DB700089C270ULL, 0xB59DC04B907C2A17ULL, 
            0xE910348A5E8DD4E1ULL, 0x34B48D492880B87CULL, 0x0A2B2ABE8239E6FCULL, 0x49E49AA0C15006CAULL, 
            0xA6A3F7EFDF1DBE70ULL, 0x569DAB7C17FCCF9CULL, 0x254343292C46E8A1ULL, 0x18303384E1AE53A2ULL, 
            0x054EEE3437C9FEC9ULL, 0x2C4D56AEE11B78CBULL, 0x53109BF7AC9C0FD1ULL, 0xC5E81CC47D54042AULL
        }
    },
    {
        {
            0xCCB1D75AC030A211ULL, 0xFEBFF230A2214129ULL, 0xFDA07C630DA883E3ULL, 0x0047FE5C13C80B44ULL, 
            0x54D6CD70266363BAULL, 0xBC893CEA1CFC1597ULL, 0xDA772D8983496685ULL, 0x1B4F78268BAD2345ULL, 
            0xF437051CA3EED3B5ULL, 0x4E5E28CF5E480742ULL, 0xE832C6D4E07EB1B3ULL, 0x22637226E24D37BAULL, 
            0x10081C45D99F51FAULL, 0x4A282BADB946AF01ULL, 0x10ED7E4C58CBCC0AULL, 0x2BCB95A89A065A71ULL, 
            0x1E5BF88A23BB9C88ULL, 0x309F9B8E25B0A51AULL, 0x690FB6B456B29A4AULL, 0xB9D701417AD23B81ULL, 
            0x4D88C01B04F5818AULL, 0x89E4DDAE5A63743BULL, 0xBD54E87D9AF65DE7ULL, 0xF77F5D66FADB10D9ULL, 
            0x6F6F257AC7907756ULL, 0xD54186C13F333F8FULL, 0xAB81EEBECA490051ULL, 0x69417CE7BE99AFD2ULL, 
            0x005BBEB5F840FED5ULL, 0xEE84D5E4145E642BULL, 0x25375DB88975C11EULL, 0x01A8150BD2CDF9CEULL
        },
        {
            0x677ACCEF865A6FC8ULL, 0x02B0643D78FE30FDULL, 0x8864BC97BCF4CDFCULL, 0x0099F2D7C82ECBBCULL, 
            0x6D105DD735F0AFDFULL, 0x569C81B17DD9E856ULL, 0xBDFDED7B351EFF07ULL, 0x94A976DD1817E5BAULL, 
            0x7923041434028968ULL, 0x1AE7A39AC5DA5E0DULL, 0xD809E43C502DF757ULL, 0x9927CD06A311147EULL, 
            0x9C3AD9D13C0932B5ULL, 0x664B125C07557FC9ULL, 0x1BF5F8458627EE73ULL, 0xBC350DC273ADFC21ULL, 
            0x4539FB6F4B999468ULL, 0xD055F75255461E97ULL, 0xA91AD66C93EC10F0ULL, 0xA651718EB2DF6184ULL, 
            0x2A238EA5D859C25FULL, 0xEC6620488A09814BULL, 0x746E65A915F93E36ULL, 0x6D35C5CBB13025CFULL, 
            0x00DE93EB86F4D9DAULL, 0xF1A9F10652C6E5ECULL, 0xDFF48A2D21B3B428ULL, 0xB74B16E7C11FFE33ULL, 
            0xAAA2B67086AAAF56ULL, 0xC2583359A90D193FULL, 0x1EB95CE3669F9755ULL, 0xB1047CB3295B5766ULL
        },
        {
            0xBC61537EEBDB3792ULL, 0xD1BBF3F85E75F681ULL, 0xA85655D4A46CA33EULL, 0x4D20D4CA32CE1558ULL, 
            0xC70866C7784E31C6ULL, 0xC4F47F1BB4351290ULL, 0x8785A1595924EBC6ULL, 0x98BDA24202F81345ULL, 
            0xDC495ACFF756E4BDULL, 0x8C066DD9AEBECE23ULL, 0xEEEA2731B2A1A7F4ULL, 0x65C5DFBD013585A9ULL, 
            0x706C199A93F96C07ULL, 0xBA2C2CE11EF40B5BULL, 0x42136F5DE7310B53ULL, 0xFC8CC7B3F47E1454ULL, 
            0x4C922B4B8699C65FULL, 0xB83D9F08578E0E1FULL, 0xA0CD663EF4D7162EULL, 0x2EF6C49C7665B461ULL, 
            0x97AF065B09D42B7CULL, 0xE92F3078126AC871ULL, 0x3EAA3BB1170474F9ULL, 0xDDEDF7471DD814DDULL, 
            0x31A7496D916436D1ULL, 0x6726E08FB78F253EULL, 0xEF23C354AA1C3E55ULL, 0x08813F9DC17E00E0ULL, 
            0x5CE0BF1F7737BA69ULL, 0x7AA3173060331BBAULL, 0xD9DD138B9735655AULL, 0x7A5A13BEFED00D1BULL
        },
        {
            0xC3B96D381725CC71ULL, 0x14A92318DAF322E2ULL, 0x9B404164DF5E86E7ULL, 0x08BBD442DE58D00BULL, 
            0x3A6652289E815041ULL, 0xBF93A6162B03C0BDULL, 0xA12D25291BDCE7D2ULL, 0xD1CBF7A97791D583ULL, 
            0xC85EB99FA742FBA5ULL, 0xA130620CC40E0AF9ULL, 0x72F8A544D8F5BD66ULL, 0x1A97760A8E145958ULL, 
            0xDDA9B1F3AE7721FAULL, 0x0C034D2B90E9A0F5ULL, 0x5947A0B0089738BCULL, 0xD83DC4B7F876AE9BULL, 
            0x318B61CA89CE1A79ULL, 0x5F7A7E5B7B692F7AULL, 0xF4C759C192E7109FULL, 0x3C5346F8DA195D7EULL, 
            0x2D241E406832CBC6ULL, 0xF94F8E43BE3F569DULL, 0xDD7AC1B4163CF83EULL, 0xCDFDC855C8F91AAAULL, 
            0xA05691EF8E12EE1CULL, 0x6FE6182AFF0FFD55ULL, 0x16DC1B2D60044A27ULL, 0xCC3DB5CCAECF7D90ULL, 
            0x44671008244CDE41ULL, 0x0EDC6BCEC85D0BACULL, 0xB705C68262532E24ULL, 0x06D7BC97152644CDULL
        },
        {
            0x83DE581FFBB43691ULL, 0x56D72EFC12B31B71ULL, 0x852319697ADF4D01ULL, 0x64B00CFC27FED78AULL, 
            0x57E116D5945C6507ULL, 0xF63C3FCBA0EA51FDULL, 0x3FE7FD8E224242A5ULL, 0x960330675EAA9E6EULL, 
            0x3B3D8667380AF531ULL, 0x4924E4F238D1B17EULL, 0xF916B7FBC790A0E8ULL, 0x3051EF378950F9A9ULL, 
            0x594014ED016A4818ULL, 0x77E97F1E1E8E3439ULL, 0xA1AF034DE5A1F72FULL, 0x10DA7562533B1C8FULL, 
            0x64CD10A92313C9C0ULL, 0x64AAB3CF7890E2A2ULL, 0x4FF47D8626F08DB3ULL, 0xE74A55F5091D9506ULL, 
            0x1C95F6ED4D33101EULL, 0x3D693270FB300E19ULL, 0x8647D85F9C4586D2ULL, 0xF6E5C8D17BD291D5ULL, 
            0x95455ABE8F4697FCULL, 0xD5B2CB6B452C3D05ULL, 0x560B5BCECA390191ULL, 0xE6D13FBAB0654886ULL, 
            0x49157A137D414CEDULL, 0xA39AD046C7130501ULL, 0x18CFEFDB7D2DDCA3ULL, 0xD7B99ED053CD18DEULL
        },
        {
            0x341EEB173C759659ULL, 0x25599C517198A9FAULL, 0x6651F5EBE2764A1DULL, 0x183C1750D7CD349DULL, 
            0xE3ACA21E2C72A455ULL, 0xACD24B3729D9E1ACULL, 0x97FE4A31229FC7BAULL, 0x4B95D744020EFD55ULL, 
            0xF9714E95C0F40314ULL, 0xCA7BFB048A334EF7ULL, 0x987FC84893FB1E98ULL, 0xB7F397A0C88F3F0BULL, 
            0x85DF162E8DC87372ULL, 0x18C80305F3A34ADEULL, 0x1C9E5EE6A1A8719CULL, 0x4DE4BA979D2C2A50ULL, 
            0x048419C060B36F1CULL, 0x52ED46818DB5DDF9ULL, 0x8FFD42630F07D22CULL, 0x4018848CC8F97633ULL, 
            0x2ECD0D3CFD617E10ULL, 0xEB3D13DF03150384ULL, 0xF647F7E324D1A296ULL, 0xC29EADEEB3178E1AULL, 
            0x46475E2C9C8CCDF3ULL, 0x6199FE0816745269ULL, 0xC261ABDD1A819B86ULL, 0x6ED596E7F0C2F465ULL, 
            0x128D3DBFA3FFFA96ULL, 0xDD8DCD0AFA5F70A5ULL, 0xB033F050D47DC12AULL, 0x746F75E99D5B8339ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseGConstants = {
    0x2F46567D1007598FULL,
    0xAB58C924E5A271DDULL,
    0x0AF8386D571CDCAEULL,
    0x2F46567D1007598FULL,
    0xAB58C924E5A271DDULL,
    0x0AF8386D571CDCAEULL,
    0xC8916F3B412DA8BBULL,
    0x92FCB36A40FA8315ULL,
    0xC4,
    0xD2,
    0xC3,
    0xEA,
    0xA6,
    0x56,
    0x7B,
    0xBA
};

const TwistDomainSaltSet TwistExpander_Soccer::kPhaseHSalts = {
    {
        {
            0x61283650BA09D923ULL, 0x295F62A7C7B0B173ULL, 0xC066E9BA0ACCDD19ULL, 0xB99F617D19289BB0ULL, 
            0x5BE722464BCCB657ULL, 0xF46F201724C7D5C4ULL, 0x64133410AE6DFEFAULL, 0x747533CE8936AF82ULL, 
            0xDF8158D4426A0623ULL, 0xD1E15EA3379650EEULL, 0x11E9845485422560ULL, 0xEEB6300E01FCDEBAULL, 
            0xBCF3921B3256DE5AULL, 0x772B4B4EB7694641ULL, 0xDEF0A252681596C6ULL, 0x31BD502F48724799ULL, 
            0xC50A1290D074392BULL, 0x22D376D859D50A82ULL, 0xCD0BE803526701B0ULL, 0xEE2A7A2682828E1CULL, 
            0x1EA430D819FE1C1DULL, 0x2FCF4979B670688AULL, 0xDF9303D54B877B50ULL, 0x91DB45D913E73888ULL, 
            0xF09AB256E6E357DEULL, 0x0A15DBA81067C8B9ULL, 0x344D87B55A58A201ULL, 0x70AABFE2A9536C92ULL, 
            0xBBA7627FE4B4C80DULL, 0xEA2A8BAD4B7957C6ULL, 0x028B8C8E0B679DEFULL, 0xFD121831530945DBULL
        },
        {
            0x70CC08827FAC8852ULL, 0x3016B41D8C436982ULL, 0xC6582BDC1544B515ULL, 0x8E60CE07516913B0ULL, 
            0x4161AFF65D067B06ULL, 0xFA701AD90B93F3A8ULL, 0x431C88D1F7013119ULL, 0xA066B4094A6B963FULL, 
            0x5955FF08989425A0ULL, 0x01312A8EE476B018ULL, 0xA1135B2FA4B90472ULL, 0x4855E2E1C48404D0ULL, 
            0x9B31823550DE088BULL, 0xE6B28EED2CBF6BDAULL, 0x8F03D20D6A867E15ULL, 0xA5C884DB34E3CBCBULL, 
            0xB9845373346916CBULL, 0x0A6450F4F9F80763ULL, 0xAFA148FB7BFCA1C0ULL, 0x0FD401D510872860ULL, 
            0x512861F7825E993BULL, 0xEDD31425764D8B4CULL, 0x08886D88427CAEABULL, 0xEDF1799578F2F06BULL, 
            0xF6E03AFBCBCAC87BULL, 0x56BC7E78E5FF9639ULL, 0xC2D35C17E844358CULL, 0xAC198B871690CF0DULL, 
            0x7627DD6B071A88C9ULL, 0x1ADA76AC80B30E58ULL, 0xAACA9C2BD4617196ULL, 0x966176E551A96542ULL
        },
        {
            0x203DCED0BF5F868BULL, 0xE9362FDE308B97E2ULL, 0x3C34FEBEA2ACDEDAULL, 0xB47D7C972188E0E5ULL, 
            0xDA7D9137AB098020ULL, 0xCB840C3BCC272013ULL, 0xA753FF7D65FCE9A2ULL, 0x6CC3C72097BBD0D4ULL, 
            0xF2161DF125B9E022ULL, 0x3F1F639B7CA89F6FULL, 0x140E40034B271A39ULL, 0x5F65722BC8C5DEF8ULL, 
            0x48179B5B80F0A22EULL, 0x09CBF9022A7775C7ULL, 0x38BF6EB684384847ULL, 0x032CFF19C44F5351ULL, 
            0xD75BE140FE291D5CULL, 0xCB6BE4C1FE580FF0ULL, 0xB792959D992CDAB2ULL, 0x493524084C0C32FAULL, 
            0xF065CA5F8CB0333FULL, 0xC7816B99C8AFC640ULL, 0x72BDAC80A0DE5BD2ULL, 0x674E03645997EFD5ULL, 
            0xFCDDCAFE616EE8CDULL, 0xD47A2374755436C9ULL, 0xF05E34745E1DFFD9ULL, 0x7A7927759AE32838ULL, 
            0x84AA708F1FF3E725ULL, 0x7E7A4685020240B9ULL, 0x8916E9D22766039EULL, 0x2F2C55D47E30C273ULL
        },
        {
            0x829DAF9ACFA92B7DULL, 0x7DB5F8CD0EA7F0A4ULL, 0xA217554FC6B2E36FULL, 0x4C59D71D9778A4C9ULL, 
            0x2E877AACF9492415ULL, 0xD4BE175D231CBBFCULL, 0xFAB22EA6BF2E97F6ULL, 0xBEED1DFE10CBAAD1ULL, 
            0x6D424854D33CA721ULL, 0x863CD9336B5EB4BCULL, 0xEAE1A767CB8DD7B4ULL, 0x2D6790E43095C306ULL, 
            0x062AB87EF6659B2EULL, 0x99334EE13C23BED9ULL, 0xC2F4CB048135BC86ULL, 0x91DBAC0DD64FDDC7ULL, 
            0x980E9AC7844C5E15ULL, 0xFF42C2943C1DC16AULL, 0x4237B7988F0E443DULL, 0xEA6881E17B379262ULL, 
            0x7DE30B94A3370A6DULL, 0x1A4F202492D03A91ULL, 0x16E5470C141180BCULL, 0x0B4576263408EC6EULL, 
            0x098D71A4434E1FF8ULL, 0xD977B86FA4908878ULL, 0x529B81140FF6E515ULL, 0x6695F8C07F605784ULL, 
            0xF7349B14FF2E8103ULL, 0xFC999B3D2612FDC1ULL, 0x3AD9EC78C539620FULL, 0xD9B79DF9DBDBC7D9ULL
        },
        {
            0x798D971DAAB06B68ULL, 0x7AFD9C099F8699AEULL, 0xB571B4F5CA4E468EULL, 0x288CF84151645C3AULL, 
            0xA94AF21542E3D19BULL, 0x44D0FF14CB066A1EULL, 0x49A8D37C4153FEDEULL, 0x857849293AB22E84ULL, 
            0x5F80CD657180D2F9ULL, 0x8A3F071231DF0E56ULL, 0x5FE3A1AE98930514ULL, 0x44DCEF596C86A826ULL, 
            0x6294F6BB56912AA5ULL, 0xC60D8F1E523F14B4ULL, 0x11121C63603426CAULL, 0xC797011BB66DA479ULL, 
            0xDBD4362F68A8AD12ULL, 0x02A9914F02E323A0ULL, 0x4E3EB377A4A88BAFULL, 0xF0F8AF55A06DF357ULL, 
            0x2D6D3B0CE1456F03ULL, 0xFC23B5D1F02DCD5BULL, 0xB2E160674F29784DULL, 0x4A5D8470B98F61FAULL, 
            0x3CB0AD82581BFFCEULL, 0xBC5A3B2E757A4B7DULL, 0xF18F4CA1AC5AA2B3ULL, 0x1F454E86F656184DULL, 
            0x28E325A459DFBCE4ULL, 0x550D769206117BC6ULL, 0xCDD8FFE7B8D81A39ULL, 0x4F20287CDB62EB26ULL
        },
        {
            0xABB46C5DBADDED95ULL, 0x71AD2B3BF8F1E4F4ULL, 0xDDAB365F386433F0ULL, 0x3927D6B2E83B4778ULL, 
            0x0632B099269A87D9ULL, 0x2A075025095114F8ULL, 0x4BB8ACC492AE6483ULL, 0x3E0A91283DB68AC5ULL, 
            0x8A357BAABCE79B4EULL, 0x357BD4B9E1FCDF1FULL, 0xCD9A6047B3F200E9ULL, 0x746CF46381701E53ULL, 
            0x20F238FCA660AA64ULL, 0x34C31312B9464D83ULL, 0xF93072A9C46EB332ULL, 0x52159D0E1151BE61ULL, 
            0x350C674A9EB76985ULL, 0xD52C031BCA4DBC92ULL, 0x5C12A590294B3C5FULL, 0x564A58C79517E80BULL, 
            0xAAF5CB95EFCE9639ULL, 0xF0FF2CD1712627E6ULL, 0xBA4A07294F101B8CULL, 0xCA2F856989C1B47AULL, 
            0xE3D0EAD919279EFCULL, 0x53B685DA23D1127EULL, 0x14CAD2509BFF6C5FULL, 0x8A3EE4AC78018B2FULL, 
            0xAC0FF141415E0FB9ULL, 0x40D0DE14EB3061E2ULL, 0x62191C5AC3986B99ULL, 0x5B689B61DA8CCAE9ULL
        }
    },
    {
        {
            0x97F5C6C963C86CC9ULL, 0x9028A5EE0166074FULL, 0xCAACD4866556A30FULL, 0x59E81105878E2588ULL, 
            0x333997E7FDB1461EULL, 0xEA4B5B806DFC4D68ULL, 0xD023CC821B24742DULL, 0x5C7A03B81E6A8166ULL, 
            0x63FE4A407BF39AD0ULL, 0x5C659A694DBFCB50ULL, 0x2E0A63B10F820B3CULL, 0xA31E3DD959C7AA05ULL, 
            0x9E2DF727FA727602ULL, 0x990CD1794966A754ULL, 0xB7672E5FE4D929D7ULL, 0x75325498B8A4CE91ULL, 
            0x190DBE5F29A23AE5ULL, 0x7B2C243141E3DC5DULL, 0xAC7926EE595D7FB5ULL, 0x56D637F2D9B80CDAULL, 
            0x6734650C68E55328ULL, 0x8F06BCD53BFA19EDULL, 0x80157E67ED80D169ULL, 0xBC4EE153E098532EULL, 
            0x755FB82D9B1EF330ULL, 0x8429B473C4DE717CULL, 0xDBAF51AB0636644FULL, 0x0664ED59180E3FABULL, 
            0x9D32E534DE167D02ULL, 0x497798822FA792CCULL, 0xF313CD57009B8B03ULL, 0xA779851B45497AB4ULL
        },
        {
            0xCEB62DFB4701BB22ULL, 0xA26EA76AECECD95FULL, 0x5249B724EBAF190BULL, 0x3E22E92775057DD3ULL, 
            0x43CD4DFDABA39483ULL, 0x3F19733F84D9E48EULL, 0x37F5551F3A0803B8ULL, 0xA4B5BA2EDCACD535ULL, 
            0x33F2CDB6A9FD8C47ULL, 0xD83DCE14CE24371EULL, 0x1044F48762D23B6AULL, 0xD7C0002C7048E51DULL, 
            0xDD816FE8EFF644ECULL, 0x816867A7FDE3B60BULL, 0x805BC4913ED21456ULL, 0x8AC45249A4BBFB15ULL, 
            0x4A3422307E3D086DULL, 0xCFD7D0E9D61D7F00ULL, 0xCEE1FA86B862BFCFULL, 0xF549B08C09D7EF06ULL, 
            0x8CD44CFC940AE4FEULL, 0xBE875DAD937AE481ULL, 0x58BB44727B148FB2ULL, 0x16C32BCC80290CEEULL, 
            0xD063A86C404A8167ULL, 0x8A8485D219BDBC9EULL, 0x2E000776E4E30B3DULL, 0x21913074322BE87FULL, 
            0xF70990A44C4902E1ULL, 0x0C6A3D7257E65D00ULL, 0x1290D2C6C5681B5BULL, 0xA11E49BF459371AEULL
        },
        {
            0x4C20C385F3D3E82DULL, 0x1577FB8F58434B17ULL, 0x16C36CD428BAF53DULL, 0x81D4A716F5BAFEC6ULL, 
            0x9EB4E163A1A20335ULL, 0x83F99102AE801BDDULL, 0xC8333D4EA9E4E9DFULL, 0xD729BD898A779811ULL, 
            0x7F48C904ECBB7AA0ULL, 0xBB9EA0DA56929F80ULL, 0xDDAEAC87F7E40D0BULL, 0x5AD6DC344B15463EULL, 
            0x853280EDC9D37331ULL, 0xCE63B3AAF12B778BULL, 0x3B37D9157B0A622BULL, 0x599249E008A7CBFAULL, 
            0x79243ED484D9AE27ULL, 0x4CC21B95F5B24C5DULL, 0x2218DC1EFAEA5A4FULL, 0xD719861363FD7D19ULL, 
            0x2674B4AB05149FF7ULL, 0x117A2E64BB6BF98BULL, 0xFAF83F04E32DAAA2ULL, 0x026CD8A9BBD25CECULL, 
            0x815CCF8C28BE1CD2ULL, 0x15ACFAC2A27E62E5ULL, 0x50E112FA53FB13BFULL, 0x7B67414F480FC013ULL, 
            0x8D551541BB72A862ULL, 0xC70492DD96E91F28ULL, 0x1C8A5EFDC95D8507ULL, 0x53B60186BAE53AC9ULL
        },
        {
            0xD0C90484BFA99600ULL, 0xC50B2AC117D262F5ULL, 0xE3F857869CC510C8ULL, 0x668BA4FF6A5B0B7DULL, 
            0xD9933394FC98FD81ULL, 0x3C611A85A9D6CB4FULL, 0xBF9AA8C0B489B676ULL, 0x2A5C4BC33C4895EBULL, 
            0xA8F9F38228EBA03DULL, 0x8D4EEC8E6D54C61BULL, 0xFF1BC824618BFF54ULL, 0xFD0A0A37C2F4F48AULL, 
            0x043AC9DAE0E397D6ULL, 0xA749DC97264FEDD3ULL, 0x3AEE12D6652AC656ULL, 0x021739E2CD0CF31AULL, 
            0xAF6FBA32841BE5E3ULL, 0x532413A4B19D32E7ULL, 0x1C79B06277D3B307ULL, 0x2A11C5A92A59F7A4ULL, 
            0x8A9A9F4718BBC338ULL, 0xC33F2906C058E260ULL, 0x4EF53EB944B76306ULL, 0x3F966A4E3EF4F924ULL, 
            0x0F22289E2116300BULL, 0x52B2D6D80195D5D3ULL, 0x602E7D3D5BB09255ULL, 0xCBBD794715F15B35ULL, 
            0x54A4D2468B9759ECULL, 0xE8CEAF1F3151B68DULL, 0x5174CCA0CF47F761ULL, 0x5EA89A715C56241BULL
        },
        {
            0x33214C5D44D5329AULL, 0xDBB3F01380112F69ULL, 0x82508455DCB28D8CULL, 0x66EECDB92E3A3267ULL, 
            0x8DF24FD41AEA2D7FULL, 0xF8C40A5FE7FCA571ULL, 0xEABCA780B9D4D2BDULL, 0x2FD023B9CE5AF4CFULL, 
            0x3BC19288DC98479AULL, 0x1EA57ED7D59A7FE2ULL, 0xE4495511C051C72EULL, 0xA6B3ADF5AE1911F6ULL, 
            0x574DFAE6C20D8F58ULL, 0xE02D98FF5550A8DDULL, 0xDDDF50B3A746148BULL, 0x472F2D31D4B4645EULL, 
            0xB037E02B09E434D4ULL, 0xFAE2DEDC646EBD46ULL, 0xBE1A208F39B6A35EULL, 0x34FC78536D714EB8ULL, 
            0x3EDADF7B675DD88FULL, 0xDFAA890C7A926E9DULL, 0xB7B07DC5C21FD748ULL, 0x813BF0BF9C430B04ULL, 
            0xD89D203791C0F125ULL, 0xC829A625FE7440D7ULL, 0x01F0145CD4E61B11ULL, 0x4833A792DE479CF3ULL, 
            0xC20642C183D766C2ULL, 0xCAA5534E2EF8BE70ULL, 0x32A8A175DE04843BULL, 0x02E5A28C968913B7ULL
        },
        {
            0x05DFC521ADAD58B4ULL, 0x13DB7BC061CC6069ULL, 0xC8573FA1DB839B1FULL, 0xE96654D39FDCB385ULL, 
            0x3BB7E4124B1AF408ULL, 0x9F64998607E338E1ULL, 0xD8A1694EEA587CCEULL, 0x64984A2D9E5FF1BEULL, 
            0x43752AF3FE14C799ULL, 0x6221589E8A5767E8ULL, 0x57C1D31FC3919B53ULL, 0x17960CB789EDDC93ULL, 
            0x29CF37A71BC33E9FULL, 0x604011BC589F613AULL, 0x7865F52D6B12B1ECULL, 0x5A52634893DE074FULL, 
            0x3488A59A6793A797ULL, 0x0243BE6A47FBAD6EULL, 0xD2A382425F557663ULL, 0x8F3B5F5F4E286A4EULL, 
            0xAB970E60C53B2146ULL, 0x5BB618BB311FD19BULL, 0x4B9414248C4471EBULL, 0x1E0A6675F09BF4D9ULL, 
            0x775A09A2BB1A6203ULL, 0x22F7158D6A122DEDULL, 0xECE50C0556546E79ULL, 0xFEE48D5DFBBF5A48ULL, 
            0x87FFBB194C77D6D5ULL, 0x7051B39ADAEEB057ULL, 0x6576789D1A8F894AULL, 0xF2D8F5354E6DE671ULL
        }
    },
    {
        {
            0x7F82C165B486BB6CULL, 0x2CAEF6F0B68098F4ULL, 0x5287C94F500B5EE5ULL, 0x18AD5227DB8148C8ULL, 
            0xD0554CAD9F4DB560ULL, 0x5D031A2D5DC7230FULL, 0xD9CBD08A03488D45ULL, 0x2A92782AE1CD6CEDULL, 
            0xA906AD977DEB9B0BULL, 0x615A5F922E6A6A67ULL, 0x5B1D00ED7B4FC23CULL, 0x3164C3503919195BULL, 
            0x5AF64526A97BA30EULL, 0xBDC07D7F2C000D50ULL, 0xFF5420C70EAC17F1ULL, 0x576EDC7A9D405918ULL, 
            0xD2C3453AEBBA7B73ULL, 0x18B59BBF8F138A8FULL, 0xF4A1508EABE6C068ULL, 0xEE6F8743816DAA6FULL, 
            0x0FC4DDE6BD5287ACULL, 0x03621715C905D64BULL, 0xB6F10B7E10201A5DULL, 0xFF9E1B04FC59E6C3ULL, 
            0x0248ED8A0F0BC984ULL, 0x6D9E39D0D4F7080BULL, 0x5316F4467299C16BULL, 0x49CF9B5FE6F5D17AULL, 
            0xF12A375AEFD76030ULL, 0x5CA2F2754B0C3ED4ULL, 0xF9EC9DF6ADCA96BCULL, 0x7FB9B395978B12CBULL
        },
        {
            0x63FE4259748269FEULL, 0xB0FA5D44106932D2ULL, 0xF8F6D00F35188F80ULL, 0x79753052A70E8FD4ULL, 
            0x14B55F4E498E2F13ULL, 0x95498AF22E8EA6B2ULL, 0x28931888C02D432EULL, 0x671B2D763C0486E9ULL, 
            0x1197DDED3D6BCC74ULL, 0xAAE4DD304D8330EBULL, 0xF16C26E1A57B8669ULL, 0xA5CAFBA0ECA79B26ULL, 
            0xC70AA679558C25A4ULL, 0x98124A17932CF1FEULL, 0x0650BEBF9EE804A1ULL, 0x1F1927D158BD46ADULL, 
            0xE9FE78F4E5E4B8D8ULL, 0xA32F29A68446BDF1ULL, 0xEF18401F35AC8EEFULL, 0xED00268925ACA477ULL, 
            0xA724F12043755EE2ULL, 0xF34BAFD13F279C24ULL, 0x5395DEA9BF23530EULL, 0x6AD49D0440DB6226ULL, 
            0xF4EE9720282D00E9ULL, 0xE16735F215FD44AAULL, 0x0E65926C0D8501AAULL, 0xC9D73AB7CFA7B7FCULL, 
            0xF84A391A954C7930ULL, 0x4F8181D34EF42917ULL, 0x3E87B378E8230F61ULL, 0xDD9EBCAB215A86C3ULL
        },
        {
            0x5B6D373E897B1344ULL, 0x48FD7AFDCE4267E0ULL, 0xC1CEE490A9406148ULL, 0x2578463EE95C0386ULL, 
            0x12B81E0A4BF20AF4ULL, 0x4AD95E54C3C0D20CULL, 0x872142DFD80C6E81ULL, 0x1A6D8CEC73EC3D75ULL, 
            0x839724E93F23E210ULL, 0x1F7D56BA187AC610ULL, 0xE7C801DDC8F32080ULL, 0x70E6B90D843FBF92ULL, 
            0x6631AE6176AA9F47ULL, 0xA8310179AAF4C73EULL, 0x52D1C79A3EC97F2CULL, 0x8550FDE4EA4251E0ULL, 
            0x7F2B1E85D1DD0516ULL, 0xBF65E1D70D89BF74ULL, 0x249CE30E51BC61E4ULL, 0x70D35758C305ABEAULL, 
            0xB934E8B1B0A46C83ULL, 0xC1C16701AA338127ULL, 0x4FAFCBA80C44E19FULL, 0xC214D9153767FB14ULL, 
            0x46AEFEDCCD1A8106ULL, 0x62F99840BC8D0ACFULL, 0xD9A7DBDFCD0D3F54ULL, 0x81C064EEB6A715C7ULL, 
            0x1C015BBC74D59CACULL, 0x32BDFDF6F5D47CA0ULL, 0x86AC5F31463529DDULL, 0x83CAD2117C2DC36EULL
        },
        {
            0xBFF624A05582235AULL, 0x06D14D8C8F83E2E5ULL, 0xC9E4DF921C7D2427ULL, 0x42FFDDA8E1100E66ULL, 
            0x8B2C680C0CB9E1C0ULL, 0x16F6F000B4C418B6ULL, 0xE711EAD1D0E87BB0ULL, 0x71A14A53EF894D11ULL, 
            0xB04EE46A4F53C6D4ULL, 0xE06DEAD5D5C8DEEEULL, 0x74BE3BFAC36A74DAULL, 0x0B4D6E715F472C48ULL, 
            0x6BED867DDBDF7D7AULL, 0xFE3AABB1FC903349ULL, 0xDAC06358A1203688ULL, 0x99A88052ABD5855DULL, 
            0x5A7B973F8B11627BULL, 0x1BB9A97C8B67BC8CULL, 0x7946E9D0C89B32DCULL, 0x3D9CE6552BBEAFFAULL, 
            0x8769313B4CB8ED78ULL, 0x84AC3E86BD087A75ULL, 0x8C5F8ACF90506DEAULL, 0x3F1DFF2FBA067D62ULL, 
            0x2BF199BDC7562718ULL, 0xBE9578046E8EBC10ULL, 0x9DE6EF1751D9F6FBULL, 0x4F679E6B99EA9463ULL, 
            0x4137781F38C659D1ULL, 0x733ACE16AF78F81EULL, 0x6A7A40C9FDA63788ULL, 0x2A88336799670E23ULL
        },
        {
            0x1C87AFC72994F7D0ULL, 0xC9282162DC6E4815ULL, 0xE5C47A0DC956D000ULL, 0x6051134893CAAAC9ULL, 
            0x66EF25DFD71D87ABULL, 0xCE097D029028D69CULL, 0x1FE778D369314C5CULL, 0x451560302104A39FULL, 
            0x50093D15AF435957ULL, 0x799C384BC5B478E7ULL, 0x1FCBDC075F54DB3BULL, 0x0E25B086FDC69834ULL, 
            0xB941B9C8A78E3F81ULL, 0xA619DBAC807D8524ULL, 0x0508EA61C67BBEB6ULL, 0x60A41B30814D43BDULL, 
            0xEA8D27B3F3F8ADB7ULL, 0x898936CBFA203F20ULL, 0xE13FDEF7E231ED0EULL, 0x95D5B9139B608357ULL, 
            0xE0826C01D2058605ULL, 0xC2B9C06CC3E886BBULL, 0xEE28240E16408FB8ULL, 0xAF47A201436C6F67ULL, 
            0x2479902C3EEA7337ULL, 0x99CF5A3F39F0449BULL, 0x04C0A6CDC61E5F95ULL, 0x33869F2C80D31AF4ULL, 
            0xE0CEC274BA9259D9ULL, 0xFDE405EFF1143E7EULL, 0xCD909598EF028910ULL, 0x32012A18C1ADC435ULL
        },
        {
            0x6E26BB5D70E1D334ULL, 0x458A8C4E94BF6E5CULL, 0xD7F6FFCA731172A8ULL, 0xA4A2BBCCFAC27EB0ULL, 
            0x47A44EE35FE6DAAFULL, 0xE7226E278E65F1ECULL, 0x285A6CE2290A142EULL, 0x075C38EF5B7659CCULL, 
            0x2620FCC5C170E4FDULL, 0x19B3BA6C99AD706EULL, 0x323FBD03B053B80EULL, 0x498F0E79C7850C5FULL, 
            0xAE64CAF4F6808ECFULL, 0xFF927DEBEE667A31ULL, 0x05426CDD7B5F412CULL, 0xCB053462A6A52337ULL, 
            0xB23B7561625BBCF5ULL, 0x290E2C503E5E289CULL, 0x8F6C362E2CB3AFB7ULL, 0xBB2F68761DDDFAB7ULL, 
            0xBEB88B7C78134428ULL, 0x880EFFC18073179EULL, 0x90289A785FE0ED92ULL, 0x36F1893723F89CDDULL, 
            0x43C08B02198EFE9FULL, 0x568D9305A9CAC0DDULL, 0xB347B350522D15AEULL, 0xF27C2DF6DFAEBB3DULL, 
            0x72CD32D2C63F68AEULL, 0x332679F027BF35F3ULL, 0x9E5E21ADDC4F7DE0ULL, 0x8776F7A993BC664BULL
        }
    }
};

const TwistDomainConstants TwistExpander_Soccer::kPhaseHConstants = {
    0x3D7C7CDE27436C7BULL,
    0xAD2EA8DF8CB896A8ULL,
    0x5D43E6B95A01F666ULL,
    0x3D7C7CDE27436C7BULL,
    0xAD2EA8DF8CB896A8ULL,
    0x5D43E6B95A01F666ULL,
    0x43A0BCBA57660F06ULL,
    0x73AA13D797F7B21FULL,
    0x45,
    0x02,
    0x71,
    0x24,
    0x50,
    0xCF,
    0x01,
    0x83
};

