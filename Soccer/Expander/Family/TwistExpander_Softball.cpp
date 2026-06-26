#include "TwistExpander_Softball.hpp"
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

TwistExpander_Softball::TwistExpander_Softball()
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

void TwistExpander_Softball::KDF_A(std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet,
                                  std::uint8_t *pSnow) {
    TwistExpander::KDF_A(pNonce, pConstants, pDomainSaltSet, pSnow);
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
    std::uint64_t aPrevious = 0; std::uint64_t aIngress = 0; std::uint64_t aCarry = 0;

    std::uint64_t aWandererA = 0; std::uint64_t aWandererB = 0; std::uint64_t aWandererC = 0; std::uint64_t aWandererD = 0;
    std::uint64_t aWandererE = 0; std::uint64_t aWandererF = 0; std::uint64_t aWandererG = 0; std::uint64_t aWandererH = 0;
    std::uint64_t aWandererI = 0; std::uint64_t aWandererJ = 0; std::uint64_t aWandererK = 0;

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
        aPrevious = 18420854653960300539U;
        aCarry = 13618315392451585519U;
        aWandererA = 15636793684348369963U;
        aWandererB = 15474181057900666780U;
        aWandererC = 10374980084484992653U;
        aWandererD = 17371917338449747333U;
        aWandererE = 13771276900245699160U;
        aWandererF = 9224419679223296989U;
        aWandererG = 14732052403893793531U;
        aWandererH = 12229300286556690352U;
        aWandererI = 16821919424340285061U;
        aWandererJ = 10598331526071621935U;
        aWandererK = 14495987339823399175U;
    }
    //
    // ---------------------------------------------------
    // KDF_A_A kdf_a_loop_a:
    // ---------------------------------------------------
    // read from: source, snow
    // temp storage: work_a, work_b
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Softball_Arx aArx;
    aArx.KDF_A_A(pWorkSpace,
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
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Softball_Arx aKDF_A_BArx;
    aKDF_A_BArx.KDF_A_B(pWorkSpace,
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
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Softball_Arx aKDF_A_CArx;
    aKDF_A_CArx.KDF_A_C(pWorkSpace,
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
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Softball_Arx aKDF_A_DArx;
    aKDF_A_DArx.KDF_A_D(pWorkSpace,
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

void TwistExpander_Softball::KDF_B(std::uint64_t pNonce,
                                  TwistDomainConstants *pConstants,
                                  TwistDomainSaltSet *pDomainSaltSet) {
    TwistExpander::KDF_B(pNonce, pConstants, pDomainSaltSet);
    TwistWorkSpace *pWorkSpace = mWorkspace;
    if ((pWorkSpace == nullptr) || (mSource == nullptr) ||
        (pConstants == nullptr) || (pDomainSaltSet == nullptr)) { return; }
    std::uint64_t aPrevious = 0; std::uint64_t aIngress = 0; std::uint64_t aCarry = 0;

    std::uint64_t aWandererA = 0; std::uint64_t aWandererB = 0; std::uint64_t aWandererC = 0; std::uint64_t aWandererD = 0;
    std::uint64_t aWandererE = 0; std::uint64_t aWandererF = 0; std::uint64_t aWandererG = 0; std::uint64_t aWandererH = 0;
    std::uint64_t aWandererI = 0; std::uint64_t aWandererJ = 0; std::uint64_t aWandererK = 0;

    // [kdf-b]
    {
        aPrevious = 18237314546971991299U;
        aCarry = 13299402190022477675U;
        aWandererA = 15948793636497653934U;
        aWandererB = 11059190459946239626U;
        aWandererC = 12177143684840110661U;
        aWandererD = 9758129772234646257U;
        aWandererE = 11956625135069230060U;
        aWandererF = 9753169277855058243U;
        aWandererG = 12162370519011475730U;
        aWandererH = 10515554814363571936U;
        aWandererI = 18140860679025882515U;
        aWandererJ = 14683640798799327517U;
        aWandererK = 9744072574354446153U;
    }
    //
    // ---------------------------------------------------
    // KDF_B_A kdf_b_loop_a:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Softball_Arx aKDF_B_AArx;
    aKDF_B_AArx.KDF_B_A(pWorkSpace,
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
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Softball_Arx aKDF_B_BArx;
    aKDF_B_BArx.KDF_B_B(pWorkSpace,
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
    // temp storage: work_a, work_b
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Softball_Arx aKDF_B_CArx;
    aKDF_B_CArx.KDF_B_C(pWorkSpace,
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

void TwistExpander_Softball::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x939D292F4BA0E88CULL;
    std::uint64_t aIngress = 0;
    std::uint64_t aCarry = 0xE0BD8B81BEC12538ULL;

    std::uint64_t aWandererA = 0xEA64F11CB97E6CE7ULL;
    std::uint64_t aWandererB = 0xFBA7C90C99E0E8AAULL;
    std::uint64_t aWandererC = 0xBB2FEB9B40137A52ULL;
    std::uint64_t aWandererD = 0x805D8C8AF5907899ULL;
    std::uint64_t aWandererE = 0xF1CECFC60CC6251CULL;
    std::uint64_t aWandererF = 0xF04847BA5FACF022ULL;
    std::uint64_t aWandererG = 0xD2C24D5B87F9A095ULL;
    std::uint64_t aWandererH = 0x8EDB96720147FD5CULL;
    std::uint64_t aWandererI = 0xA1EC8F62B77E18BAULL;
    std::uint64_t aWandererJ = 0xB9D34BA8AD75CA5BULL;
    std::uint64_t aWandererK = 0xC9E7BEA25AF62DAEULL;

    // [seed]
        TwistSnow::Aria256Counter(mSource, aSnowLaneA);
        TwistSnow::Sha256Counter(mSource, aSnowLaneB);
        TwistSnow::AES256Counter(mSource, aSnowLaneC);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts));
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneD, aExpandLaneC, aExpandLaneB, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase B
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts));
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase C
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneC);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts));
        TwistSquash::SquashC(aExpandLaneA, aExpandLaneC, aExpandLaneB, aExpandLaneD, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseDSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts));
        TwistSquash::SquashA(aExpandLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneD);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts));
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneB, aExpandLaneA, aExpandLaneD, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase F
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneB);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts));
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneC);
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
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts));
        TwistSquash::SquashB(aExpandLaneB, aExpandLaneA, aExpandLaneC, aExpandLaneD, aInvestLaneD);
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneA);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts));
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneB, aExpandLaneD, aExpandLaneA, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseHConstants));
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
    // temp storage: work_a, work_b
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Softball_Arx aSeed_AArx;
    aSeed_AArx.Seed_A(pWorkSpace,
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
    // GSeedRunSeed_B seed_loop_b:
    // ---------------------------------------------------
    // read from: expand_a, expand_b, expand_c, expand_d
    // temp storage: work_a, work_b
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Softball_Arx aSeed_BArx;
    aSeed_BArx.Seed_B(pWorkSpace,
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
    // GSeedRunSeed_C seed_loop_c:
    // ---------------------------------------------------
    // read from: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Softball_Arx aSeed_CArx;
    aSeed_CArx.Seed_C(pWorkSpace,
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
    // temp storage: operation_a, operation_b
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Softball_Arx aSeed_DArx;
    aSeed_DArx.Seed_D(pWorkSpace,
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
    // read from: work_a, work_b, work_c, work_d
    // temp storage: expand_a, expand_b
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Softball_Arx aSeed_EArx;
    aSeed_EArx.Seed_E(pWorkSpace,
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
    // temp storage: work_a, work_b
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Softball_Arx aSeed_FArx;
    aSeed_FArx.Seed_F(pWorkSpace,
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

    aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mPhaseFConstants.mMatrixSelectA;
    aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mPhaseFConstants.mMatrixSelectB;
    aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mPhaseFConstants.mMatrixUnrollA;
    aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mPhaseFConstants.mMatrixUnrollB;
    aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mPhaseFConstants.mMatrixArgA;
    aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mPhaseFConstants.mMatrixArgB;
    aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mPhaseFConstants.mMatrixArgC;
    aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mPhaseFConstants.mMatrixArgD;
    //
    {
        TwistDiffuse::DiffuseWithDomainWords(aExpandLaneA, aExpandLaneB,  // input lanes
                         aWorkLaneA, aWorkLaneB, // output lanes
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
                         aWorkLaneC, aWorkLaneD, // output lanes
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
    // GSeedRunSeed_G seed_loop_g:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // temp storage: operation_a, operation_b
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Softball_Arx aSeed_GArx;
    aSeed_GArx.Seed_G(pWorkSpace,
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

        TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, pDestination);
    //
    // ---------------------------------------------------
    // GROW_A grow_key_a:
    // ---------------------------------------------------
    // read from: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Softball_Arx aGrow_AArx;
    aGrow_AArx.GROW_A(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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
    TwistExpander_Softball_Arx aGrow_BArx;
    aGrow_BArx.GROW_B(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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

void TwistExpander_Softball::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Softball::TwistBlock(TwistWorkSpace *pWorkSpace,
                                       std::uint64_t pNonce,
                                       std::uint8_t *pSourceInput,
                                       std::size_t pBlockIndex,
                                       std::size_t pBlockCount,
                                       std::uint8_t *pDestination) {
    TwistExpander::TwistBlock(pWorkSpace, pNonce, pSourceInput, pBlockIndex, pBlockCount, pDestination);
    if ((pWorkSpace == nullptr) || (pDestination == nullptr)) { return; }
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
    std::uint64_t aPrevious = 0; std::uint64_t aIngress = 0; std::uint64_t aCarry = 0;

    std::uint64_t aWandererA = 0; std::uint64_t aWandererB = 0; std::uint64_t aWandererC = 0; std::uint64_t aWandererD = 0;
    std::uint64_t aWandererE = 0; std::uint64_t aWandererF = 0; std::uint64_t aWandererG = 0; std::uint64_t aWandererH = 0;
    std::uint64_t aWandererI = 0; std::uint64_t aWandererJ = 0; std::uint64_t aWandererK = 0;

    // [seed]
    {
        aPrevious = 18144180222716730398U;
        aCarry = 16237194141821130176U;
        aWandererA = 17878421300764326404U;
        aWandererB = 11198762136862914684U;
        aWandererC = 9693472938639503855U;
        aWandererD = 11611211462090852553U;
        aWandererE = 13882700056732557156U;
        aWandererF = 10269652968160764898U;
        aWandererG = 14557884710326015684U;
        aWandererH = 15570195559933938928U;
        aWandererI = 9418626064547083236U;
        aWandererJ = 16007410093589134163U;
        aWandererK = 17597790096323223332U;
    }
    //
    // ---------------------------------------------------
    // GTwistRunTwist_A twist_loop_a:
    // ---------------------------------------------------
    // read from: source, key_row_read_a, key_row_read_b
    // ---------------------------------------------------
    // write to: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Softball_Arx aTwist_AArx;
    aTwist_AArx.Twist_A(pWorkSpace,
                 pSourceInput,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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
    // ---------------------------------------------------
    // write to: operation_a, operation_b, operation_c, operation_d
    // ---------------------------------------------------
    //
    TwistExpander_Softball_Arx aTwist_BArx;
    aTwist_BArx.Twist_B(pWorkSpace,
                 pSourceInput,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Softball_Arx aTwist_CArx;
    aTwist_CArx.Twist_C(pWorkSpace,
                 pSourceInput,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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
        TwistDiffuse::Diffuse(aWorkLaneA, aWorkLaneB,  // input lanes
                         aExpandLaneA, aExpandLaneB, // output lanes
                         aOperationLaneC, aOperationLaneD, // index shuffle seeds
                         aOperationLaneA, aOperationLaneB, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix);
    }
    {
        TwistDiffuse::Diffuse(aWorkLaneC, aWorkLaneD,  // input lanes
                         aExpandLaneC, aExpandLaneD, // output lanes
                         aOperationLaneA, aOperationLaneB, // index shuffle seeds
                         aOperationLaneC, aOperationLaneD, // operation seeds
                         aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
                         &mMatrix);
    }
    //
    // ---------------------------------------------------
    // GTwistRunTwist_D twist_loop_d:
    // ---------------------------------------------------
    // read from: expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    // write to: work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    //
    TwistExpander_Softball_Arx aTwist_DArx;
    aTwist_DArx.Twist_D(pWorkSpace,
                 pSourceInput,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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
        // ---------------------------------------------------
        // write to: expand_a, expand_b, expand_c, expand_d
        // ---------------------------------------------------
        //
        TwistExpander_Softball_Arx aGrow_AArx;
        aGrow_AArx.GROW_A(pWorkSpace,
                     &aPrevious,
                     &aIngress,
                     &aCarry,
                     &aWandererA,
                     &aWandererB,
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
        TwistExpander_Softball_Arx aGrow_BArx;
        aGrow_BArx.GROW_B(pWorkSpace,
                     &aPrevious,
                     &aIngress,
                     &aCarry,
                     &aWandererA,
                     &aWandererB,
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

void TwistExpander_Softball::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 8U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 0, 0, 1 with offsets 6591U, 4114U, 99U, 7198U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6591U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4114U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 99U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7198U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 3, 2, 0 with offsets 6613U, 4073U, 942U, 7646U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseB
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6613U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4073U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 942U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7646U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 2, 1, 3 with offsets 954U, 2095U, 3784U, 136U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 954U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2095U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3784U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 136U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 1, 3, 2 with offsets 7318U, 7573U, 4202U, 4415U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7318U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7573U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4202U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4415U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 0, 2, 1, 3 with offsets 574U, 1653U, 1850U, 1843U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 0U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 574U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1653U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1850U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1843U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 2, 3, 1, 0 with offsets 1617U, 1041U, 1343U, 601U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1617U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1041U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1343U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 601U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 2, 3, 1, 0 with offsets 1038U, 132U, 1721U, 835U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1038U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 132U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1721U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 835U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 3, 2, 0, 1 with offsets 407U, 1309U, 1781U, 538U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseC
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 0U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 407U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1309U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1781U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 538U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1668U, 1333U, 51U, 82U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1668U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1333U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 51U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 82U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Softball::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 0, 1, 3 with offsets 1520U, 1517U, 971U, 8125U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1520U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1517U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 971U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 8125U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 2, 3, 0 with offsets 6350U, 5697U, 4583U, 3637U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6350U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5697U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4583U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3637U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 0, 2 with offsets 3674U, 5378U, 7213U, 7054U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3674U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5378U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7213U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7054U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 2, 1 with offsets 6263U, 4357U, 2124U, 6463U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6263U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4357U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2124U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6463U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 3079U, 1422U, 5515U, 3437U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 3079U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 1422U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 5515U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 3437U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 181U, 969U, 159U, 102U
        // byte shifts: 8U, 0U, 16U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 181U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 969U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 159U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 102U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 971U, 1261U, 962U, 898U
        // byte shifts: 0U, 8U, 24U, 16U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 971U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1261U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 962U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 898U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 54U, 1963U, 139U, 1006U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 54U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1963U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 139U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1006U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1086U, 490U, 801U, 1230U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseC
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1086U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 490U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 801U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1230U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 2, 1, 0 [0..<W_KEY]
        // offsets: 554U, 1407U, 1083U, 1521U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseB
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 1U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 554U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1407U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1083U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1521U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Softball::kPhaseASalts = {
    {
        {
            0xEF39C08F2DD147ECULL, 0xDF5CCAD57B4D3091ULL, 0xDAD6CD3C3AC7381CULL, 0x75526EA85019ADB2ULL, 
            0xDFC05122E6732DEBULL, 0x384EBF6B5B07D24CULL, 0xDFF607D0FA510373ULL, 0x6912BA268A1C1A45ULL, 
            0xAB8891C88DC11EDBULL, 0x05BDF81D66FCD75EULL, 0xA5A4FD7649CCB3B3ULL, 0x114121DE22E0141EULL, 
            0x4E7E10C10688BC23ULL, 0x0F0D82DFF5868403ULL, 0xB10456E2FCEAE01FULL, 0x458AB95E4D69C3C7ULL, 
            0x1899F1487B424498ULL, 0x2C193B9D6CFEA664ULL, 0x2352D0B5E0F8818BULL, 0x8336AE4DB685D6F2ULL, 
            0x658E42F1CCC37F8AULL, 0x312204E0D0D3F47EULL, 0x6568873ABD8342FDULL, 0x84BAAACCEB153CC9ULL, 
            0x87719D1879D5FD9FULL, 0xF4DEC4C965082DACULL, 0x988E7E12915D50FFULL, 0xD4F26B3B5FF7A548ULL, 
            0x85C0AAD090E02861ULL, 0x4FCD8B9C90A8D3D6ULL, 0x4F6F678131486612ULL, 0xDF9F3C85C46BD9BEULL
        },
        {
            0xD374E02555C90F70ULL, 0x9A35FBBED221E19EULL, 0x1BD62F4939CC7347ULL, 0x669E14C36FA07F17ULL, 
            0x44E41BB24EEA73B1ULL, 0xBE4D40EB00217153ULL, 0xB25DCFA51F0825F4ULL, 0xED3AD3E2E0BAF58FULL, 
            0xC058DB2D73D5FA7FULL, 0xA0299B05D5CF59A9ULL, 0xFA2DC4E16792B68CULL, 0xF7547CC092B7F869ULL, 
            0x0DF6660C1F7C41A7ULL, 0xB841F3E6FB4BDF69ULL, 0x73F721A661F7F42DULL, 0x1D58F8D365F9930AULL, 
            0x1AB6B051F1406E8BULL, 0x7B892A3CA8ED8BD2ULL, 0xA7AF649755F13E99ULL, 0x79264BE96AD228DBULL, 
            0x0259A3D10B9E3763ULL, 0x98663CEDF66D3BC6ULL, 0x1ED5B38EA6E2FB2FULL, 0x9D335B86F28F2E82ULL, 
            0x24840DF70F0AE72EULL, 0x3DFCFB06919943BDULL, 0xDAFA2508631DE8F0ULL, 0xBD354789A7C4A753ULL, 
            0xE73D5A35A661664AULL, 0x9E1685B63E3716ADULL, 0x6B534BF747B4DC1CULL, 0xC6B9D89543F6C54CULL
        },
        {
            0x1CECEF34F3594294ULL, 0xAA6E7CEC12FDA254ULL, 0x111E52875E1D120CULL, 0xBE957A3AB45D890EULL, 
            0xE767E3EAF9B43C80ULL, 0xB71175CEE276199DULL, 0xCB454B9A05511D47ULL, 0x2F9A66D16B0233BCULL, 
            0x109C69D54CF423BAULL, 0x5D4A31B2B91FFA59ULL, 0xB923364D7EE21AB3ULL, 0x0099F8DB8AEBBF1AULL, 
            0xF9D2641BD0524285ULL, 0xC7D9A1A2A8CC9D4FULL, 0x778A2C49FEE382B9ULL, 0x35BB27DE76F9DFBAULL, 
            0xD3FF177B716BDA5BULL, 0x9045F0C9BE05C9D2ULL, 0xE5A3E15C91059950ULL, 0xF31F51036096A453ULL, 
            0x8AB58B7AF773C4A4ULL, 0xBFB93BBF79CFE231ULL, 0x12EC49A70836D8CEULL, 0x75B705142252175AULL, 
            0xEFFC86107B7D39D3ULL, 0x1A7E3DFCCBE92D81ULL, 0x82007CE7FAC1A857ULL, 0x0204F4B83E370392ULL, 
            0xB067326F1D68E714ULL, 0xA682D358C3FC59BEULL, 0x4AE530F2BEC5B66FULL, 0x589337DFDBCE1DC1ULL
        },
        {
            0xD43AE1074DAD447BULL, 0xCF1602AD11E369FAULL, 0xA711E32394694972ULL, 0x0FF7439BF5784BF7ULL, 
            0x80A9880D15FFAF57ULL, 0x8B2BA18BC06E3AE4ULL, 0x10C211D1212BA241ULL, 0xCBC1272DBC55FEC1ULL, 
            0xAAF19BE5123CA801ULL, 0x233E21EB5E9511E9ULL, 0x9F92CF7D973FE832ULL, 0xE0A3FA69B809F468ULL, 
            0x0E7C0A30FAC47D09ULL, 0xB62EFFE188176C90ULL, 0xE152F74C91B88FA4ULL, 0xFC616D46AE7707ADULL, 
            0x817B3DAAC6A24BB2ULL, 0x679078AAC755BCDBULL, 0x4A53B3BDDCB37499ULL, 0xF0C1FC2559E69CD0ULL, 
            0xDFE2826AEBBFB286ULL, 0x7856D17922CEAC71ULL, 0x54885FF8D563DECAULL, 0x88B13F443AA14BC0ULL, 
            0xD0F0504FA962B324ULL, 0x2EDF4D19FF1CAEB6ULL, 0xE132E60527262BF0ULL, 0x8923AA263FB42853ULL, 
            0x09D10AC7D779B294ULL, 0xDB2D43C1EC2CC82EULL, 0xA9213CA0BD527CB5ULL, 0xA7FA0C5E9BC72E18ULL
        },
        {
            0xF7A5E3D302A3D7ACULL, 0x0484B39D5B1A9D7FULL, 0x630A9E4582956C4DULL, 0x4A95F1AE67D8F872ULL, 
            0x5207B2666464D171ULL, 0xB26461F25A0E7F4AULL, 0xB63706EF46F48B73ULL, 0x0B43F04ABB7EC27EULL, 
            0x9D3BB83A90FFDEFCULL, 0x792640A8FFB0BC0BULL, 0xFBBA20104D9B3D15ULL, 0x17B1A1338699784FULL, 
            0x747F7B3D650068DAULL, 0xA985E7E297ADDC55ULL, 0x6B51DDD76C4F3B64ULL, 0x9C83BEBB699207F0ULL, 
            0xE1811EA0D2A90A2CULL, 0xDA7F32BC7A3C1C33ULL, 0x7BF968C7A099FBECULL, 0x130B920AC201DECDULL, 
            0x2905992A8333ADF9ULL, 0xCEA7D616DDC3860CULL, 0x41E71D01F6EAABF9ULL, 0xE2288940EED87720ULL, 
            0xCF8470CF5077ED5AULL, 0x451D00761E30A962ULL, 0x037DEF403E0473CDULL, 0x1350020BD94E6726ULL, 
            0x342BF056975FAAC3ULL, 0x396F82D9F4CFBC88ULL, 0x508C7E2BAB51724EULL, 0x0C36BCF59A3149CDULL
        },
        {
            0x86263B39AEAA596DULL, 0xFDCB9879C0798C40ULL, 0x3B7A427B84950B63ULL, 0x33C08A658C21ECA4ULL, 
            0x785E69794C2E9BC9ULL, 0x2A6571DAFF27355FULL, 0xD261DFB2D62187EBULL, 0xC0C2F68C201EEAAEULL, 
            0x52E97F4F5BC00CBDULL, 0x365AA4BBA1C4362AULL, 0x46623A60ED4A67FCULL, 0xC83111198C65D20AULL, 
            0xD69A3F257C944E65ULL, 0x3B39123D21F96143ULL, 0x11F005712B54DDDAULL, 0x6B6C4D82DE158ED4ULL, 
            0xF1BFEF9C7A17B344ULL, 0x1409CAC943A43524ULL, 0x3D2960B29AFA69DBULL, 0x2EF5F412D8BED12BULL, 
            0x141225151E837FA6ULL, 0xC41CFE72C0936DDCULL, 0x47B3E6211F66696FULL, 0x1F545D85334D65BCULL, 
            0x40C9EFFCC5C71F02ULL, 0x7158843C80D209D2ULL, 0x8438AE409A033075ULL, 0xB3EF10E1E307A24EULL, 
            0xB467764251203152ULL, 0x6AC933A6771B5AB1ULL, 0x83976FD54724598CULL, 0x25DFF8270DC4EF8CULL
        }
    },
    {
        {
            0x666E9D51D08466D0ULL, 0xDD498673C19CF8F7ULL, 0xF214C64F1DEFF406ULL, 0x54EA9746C6D5B78FULL, 
            0x5B53778EBBA258B0ULL, 0xC7CE9C5453B2FE25ULL, 0xA77993C5A9B28945ULL, 0x5BF75184BB70B9ECULL, 
            0x5E3B993D332CFC55ULL, 0x3690E421FC5C3722ULL, 0xBBBD6D0F16A3AB01ULL, 0x8068A33E36449D30ULL, 
            0x3D3C7B1AE3AC550CULL, 0x3A3C3E2EE34A99D5ULL, 0xEB8799F27F878DA9ULL, 0xEB706122EAFE1C0CULL, 
            0x1C5E3AD448452CBAULL, 0xE11D41AF6C207087ULL, 0x02E2060DA98EF222ULL, 0x5CA8D276E62CB5F9ULL, 
            0x381AD8C37900E91DULL, 0xF0F4BDFB6092E220ULL, 0x2B0A3D19E2A6CB5EULL, 0x3AFF9ABC08704400ULL, 
            0xCD229692B3DA8250ULL, 0xE50D9036259F91CFULL, 0xC67F5DA6541FB90CULL, 0xB55D979651ED0AE8ULL, 
            0xEA05C77A6436D0D8ULL, 0x91A5911D9981E174ULL, 0xA64D97F153CC056EULL, 0xB17EE9FDD4EF1EDCULL
        },
        {
            0x3FFC046279E798A1ULL, 0x740E51CE62144CEAULL, 0xA5417AD353917D55ULL, 0x9C1DFCDB78DE130EULL, 
            0x8D96CF0FFB19958AULL, 0x48A3D0A04E4E9C6BULL, 0x1D8477AC19CE44B4ULL, 0x0936E033882209ECULL, 
            0xE3915D541FB515A5ULL, 0xC65C5F6636868B94ULL, 0x8746AC3DA19BFD09ULL, 0xCC47BDA77234BCD2ULL, 
            0xD5B4E1942689A04DULL, 0xE8B2803DACC0CCE7ULL, 0xBAE39D3ACD077377ULL, 0x85DA8DB8A8D36503ULL, 
            0xB49DFC89207144BAULL, 0xDA5BBE9034F1BD4AULL, 0x0274624FD8EB1B3DULL, 0x46CE37DBC43B946BULL, 
            0x70C6BB118AF69DE2ULL, 0x8B647DAE1C22D98CULL, 0xD4A4D956BC9C9135ULL, 0x5526C42FC8D62E97ULL, 
            0xCF7E035024CBEA5BULL, 0xE90E4F5608968D70ULL, 0xE0CC202ACAB110E0ULL, 0x9B460206F0A3F532ULL, 
            0xB24426A2F0F78CC7ULL, 0x3B84DCA7F0D9C3A4ULL, 0x0B90B97B01E2669FULL, 0xA3E4705E55864CDBULL
        },
        {
            0x9DF75F3569151956ULL, 0xB7B4BCC279E80DDEULL, 0x08AB956A19576E6CULL, 0x0F4CB035BDECA257ULL, 
            0x6604489158D4614DULL, 0x080FAFB2DA56AEF7ULL, 0xB1011F06B3095046ULL, 0x6B35182F0EEB143CULL, 
            0x6422FD8DF70839D4ULL, 0xDCEC1B5D9FF77CB8ULL, 0x9330079758C9DB7AULL, 0x05D5C9601235CCB3ULL, 
            0x1EED6610862E029CULL, 0xC28CE8E10629DECDULL, 0xBEAABFCC78A29FF4ULL, 0xA7158A1974297CECULL, 
            0x8AFA773875E24FBDULL, 0x4E45D120309DA45DULL, 0x7F3737AD9765125BULL, 0xB0ECB4246F363012ULL, 
            0xC1642FFA57EFD44AULL, 0xE332B746CB3F05A2ULL, 0xA7E6F668A6669415ULL, 0x8EE93C2A6E4C09DAULL, 
            0xA9C96639CA87E1E6ULL, 0x82CB32F422A5B1AFULL, 0xD50FD8AEFB289E62ULL, 0x6A0F97A84144FAC0ULL, 
            0x64AA21F616E2A44AULL, 0x7E37407456BE7929ULL, 0xB569F5176E8994D4ULL, 0xCA5B3781D2780966ULL
        },
        {
            0x86BCE9FCF9575397ULL, 0x56909053A990B774ULL, 0x1E822641B22C5BE9ULL, 0x096D51C6A27A1B47ULL, 
            0xF0C4C9CAFF2A1541ULL, 0x144E305559B0BBBAULL, 0xD30386667E4DD7D7ULL, 0x2F44D72CDCA7CF79ULL, 
            0x4A2E38F03DC0F2EEULL, 0x0699255ACB6F4432ULL, 0x195DA7A2472D7A74ULL, 0x99FE50ED06A7062DULL, 
            0x8C4245DAC50FE2C7ULL, 0x503632B25DB622DEULL, 0x2E3C54E3F1A05F92ULL, 0xF12E83E3767E0335ULL, 
            0x5C08342AA6D14003ULL, 0x8CEE3DB0ADF55729ULL, 0xFE58198DEA59ABF7ULL, 0x5AE115AD1EE12D61ULL, 
            0x95E6308CBBE1AB7DULL, 0x9010C1C8BAF0A912ULL, 0x1848D773240FBBCCULL, 0x1A1267F46D1F4BB8ULL, 
            0x6BFAAB789C874BC9ULL, 0x68BC7E70EE727034ULL, 0x48FFF67EF0CB452EULL, 0x6D7C2E1F9C4F7A12ULL, 
            0x944996CF5A348EA1ULL, 0xABAFAB08DB4713F9ULL, 0xFC3C032526C412B5ULL, 0x7EE01ED5F7118FE1ULL
        },
        {
            0x07BCC77490512BAEULL, 0x781058493CA083BCULL, 0xD61E918F806B90D1ULL, 0xD3652BC33DFA0373ULL, 
            0x1F451568D20BC028ULL, 0x428CEDC264CE00E7ULL, 0x21E472E60034EEB2ULL, 0xDBD6E23FBF3625FDULL, 
            0xA79B468F62085E58ULL, 0x73CFDAFBB80587C4ULL, 0x64A8F4D4518E3C2CULL, 0x5A3967DA2323DA63ULL, 
            0x9BDE67080AD249ADULL, 0x3F929F5C81EF1963ULL, 0xC59308CD496C596EULL, 0x1B55DD7EF9B182F8ULL, 
            0xCE860A1373173550ULL, 0x93010AC1022BA9C2ULL, 0xFDDB8E467A42DF55ULL, 0xA37AA88F2383CB4EULL, 
            0x9753CD02F48BF9C1ULL, 0xEFCF270BBE25A431ULL, 0xAB04B0E0A0EB1245ULL, 0x11C0491C7920CF18ULL, 
            0xCF62FF9CEDF8AD00ULL, 0x2F2F8954A3C429E8ULL, 0xF44E6B70FA5C878CULL, 0x85D63F56E5A961D0ULL, 
            0xFF2C49726D18D476ULL, 0x14605394E72EC83FULL, 0xF622710556FC5463ULL, 0x64189956ADAC35D4ULL
        },
        {
            0xE9680CA49A180853ULL, 0xF4FC77177DDD6BC1ULL, 0x3E98AD5F1A050468ULL, 0x1BB806CB08F50647ULL, 
            0xD85C38A58EAD506AULL, 0xE2B078A0BCD75405ULL, 0x91681E963FE0CA7EULL, 0x0EF77B70E16139CCULL, 
            0xFA88A8B822E05DCAULL, 0xE2AA3F9A7B8A9B5FULL, 0xA126FF82B1DE1B81ULL, 0x3F53535090796994ULL, 
            0xE8B49B0828CC2AF7ULL, 0xB28743D1A09BDD04ULL, 0x2E39901C67BADF00ULL, 0xCEC323756F4508F7ULL, 
            0xF8B01822AA03A8F4ULL, 0x1120E22C1F3FC735ULL, 0x239680BB4FC0ECBDULL, 0x226D571BEADBE8EDULL, 
            0x64D248F9F50974C6ULL, 0x7521FA74C8E51D77ULL, 0xA69E19D46388069EULL, 0xF3F064707213443DULL, 
            0xFF8D7E478FD333ADULL, 0x434CBDF334DDBE2AULL, 0xBB005B17D1B0A7DBULL, 0x7884AA0C22D1EF18ULL, 
            0x82DC211FF70971A9ULL, 0x2719D9B9C097353CULL, 0xCA01CAEA99467986ULL, 0x08E1F4F5A3E10BDBULL
        }
    },
    {
        {
            0x991E31CC4ADBBCBBULL, 0x92141072E3F8818BULL, 0xC32028111CFC485AULL, 0xD5359F553AF1516BULL, 
            0xF19EB191CA55904EULL, 0xBA5844BD73443D10ULL, 0x249AEEF5CB531335ULL, 0xA6076B0924BF44D4ULL, 
            0xBB84CB170988F13BULL, 0x653379E7FFE3E248ULL, 0x4A067E1938D2FAFFULL, 0x056F0F383B7D1472ULL, 
            0x37006CE0BACA6A8CULL, 0x5B505EBA075BAAA6ULL, 0x38E92361B9B7B69DULL, 0x08B5B0765D929213ULL, 
            0x64A336D56DE9EE48ULL, 0x9256E580A05436BCULL, 0xEBCDFCF7C0869BBCULL, 0xCE2D19136C0A4603ULL, 
            0x745B6BBEF941174EULL, 0x31C34A95E2DAAFD5ULL, 0xCFB0730693FC36B7ULL, 0x3798208428CC2972ULL, 
            0x10B14077A56EA001ULL, 0x6A77898BB399613CULL, 0x6823933A5E1EB47FULL, 0x3F917ED73737E54EULL, 
            0xEE2E752AB3E961D9ULL, 0x5B13854E75A86AC1ULL, 0x18143B841B79FD67ULL, 0x5AD0D7CC3E16B07CULL
        },
        {
            0x8BF50B2435EB7F37ULL, 0xD40D3239E5CF2B03ULL, 0x86E29220CFE5A1A6ULL, 0xD4A25B36329B9FDEULL, 
            0x6AB4204E2BA7CA9BULL, 0x128B358623DB158AULL, 0x745D77177F9B6AF1ULL, 0xFFC7F5A12F86D413ULL, 
            0xD768F05D233EC311ULL, 0xBEB7301CCC1CA3C1ULL, 0x264E1312A48B3C99ULL, 0x125F1BBC296FF06AULL, 
            0x77F2F43FA466AAA9ULL, 0x5CC007D16259793DULL, 0x7A27D54EBB49FDBEULL, 0x1C6776718FB0AE2FULL, 
            0x0F86ABA8EFB98F69ULL, 0xA55547C3B2221204ULL, 0xC8284E6051B75001ULL, 0x39778006F2242BDAULL, 
            0x9877082FD0999349ULL, 0x82C049E798DE6AB2ULL, 0x40A222E5EF0A656AULL, 0x9A184E513D18D4A1ULL, 
            0xF78412D97958BFABULL, 0xBC81CFB0B83AC0D4ULL, 0xA34877F8A36BA26AULL, 0xB6BE6DB3C3464353ULL, 
            0x941D693B27A12265ULL, 0xCC67F232D13E8DC1ULL, 0x3F926F40CC907C11ULL, 0x61352359035BB265ULL
        },
        {
            0x75830EC3E42B9298ULL, 0x1FB4019FF5CBC698ULL, 0xD4B71C67AFFC95D2ULL, 0x206073F7CA47C49DULL, 
            0x3FB55DF4AE5F9CCCULL, 0x91B3B1F6FEF9C083ULL, 0x83694013CE5ADF4CULL, 0x05013A368CB82365ULL, 
            0xB55095F944D606BAULL, 0x802CF9C84CEA6777ULL, 0xD126AE7FFB485725ULL, 0xD64C2A98323BEFBBULL, 
            0x71D99656C779877BULL, 0x919B5792A212B4BDULL, 0x470715E267F9774BULL, 0xBB1349A085D44936ULL, 
            0x83DA71C827DF3CDFULL, 0x74E146EECD44BEE1ULL, 0xEE3E56495DEF4BD7ULL, 0x8DF78B163BE1AB95ULL, 
            0xA3C9817C51D80428ULL, 0x74E8A74C7594ABCEULL, 0x683ECA810D6FC5D5ULL, 0xD610FBBFBC1D7F5DULL, 
            0x2252D0EEA06C22B3ULL, 0x0F6D38752F2A96EEULL, 0x93D6ACC57832A4D5ULL, 0xEEE16C96092B8B0AULL, 
            0x609B8F495C738DCFULL, 0x0902364FA7CDD51EULL, 0x1F022244293F5983ULL, 0x5A834CC55C76602BULL
        },
        {
            0x61C49E91C7AA7EFAULL, 0x5D1F8105C713CCFDULL, 0x1067F733950FCDF2ULL, 0x28AD72DE7A430A0DULL, 
            0x4D57AAEB589DA283ULL, 0xFF9AE9243DDE7269ULL, 0xEE19ED56AB50F5EBULL, 0x6D4AB20A393425B0ULL, 
            0x2D4F724AFCB896F1ULL, 0xCDA433C0D23D6CF4ULL, 0xA35E5ED97B943B18ULL, 0xE9B93A205271D038ULL, 
            0x6864205D5801099DULL, 0xC0379984A07814D3ULL, 0xB70D6B847D92FB70ULL, 0xC9792175CE52FA32ULL, 
            0x9E15008F6EFEFABCULL, 0xBBFD169416A6AB90ULL, 0x4C53D635FD1FB19CULL, 0xA0A616B6C9FC32B8ULL, 
            0xA91F7217E1E96733ULL, 0x21B674EA2D9ABC75ULL, 0x10B29DB34691ED3AULL, 0xE62A56B7C3E61235ULL, 
            0x4CF88DDC4F681484ULL, 0xD23EC692248CF113ULL, 0x5862CF3A735EB1A0ULL, 0x310D371C08E9D0C9ULL, 
            0x607F33A304562F00ULL, 0x5C3AF7BF9BA718FFULL, 0x2A416F2C10EF33BCULL, 0xD6AD7294FFBA0744ULL
        },
        {
            0xEBDAFB8DCEC966E5ULL, 0x8C2931984997A7DAULL, 0xD382E2C4D5EC6313ULL, 0xB57FCD0B7668200EULL, 
            0x6BF2D53E5725B1D3ULL, 0x649A664D277DC9E8ULL, 0xF79BB76CFCDFEE45ULL, 0x1B6E314B6DA2B923ULL, 
            0x39877C8C2831436AULL, 0x350849892455D359ULL, 0x17A31B90D8EBD70BULL, 0x21A705552F30ADDEULL, 
            0xFFC0B98085C5580EULL, 0x48388F78D82F8F07ULL, 0x031B4832CF86BA03ULL, 0x41B1B5D2A26388ACULL, 
            0x1C74585BE6AFBEC4ULL, 0x24BA38B899D39A27ULL, 0xB897CE8F729E5A21ULL, 0x6BAA5DE8EE33AFFFULL, 
            0x88B065578BB5111DULL, 0xFE2D5CFCFC60BFEAULL, 0x8994AE3D98A2677EULL, 0xDDE9636E7157C25BULL, 
            0x23DFCE42CF301D98ULL, 0x01C49D8CD855BB03ULL, 0xB0681ADF8596A33AULL, 0xC66D87D0FBC804DFULL, 
            0x0E1EC39CD3797BE6ULL, 0xC5529B3F1B7209C3ULL, 0xE2A0BDBCE2FD066BULL, 0x5B24C60BD9190BC5ULL
        },
        {
            0xF7B18D894B3EA5A1ULL, 0x857F974E09DF1F2CULL, 0xEF26D093D0269C77ULL, 0x308BA15438233585ULL, 
            0x1BD2C8403239360BULL, 0x5AE705C0F1BE7A58ULL, 0x93044006FE1D207FULL, 0x7CCD2FE77923286BULL, 
            0x3A5D704747D3589CULL, 0x5E310A9BEB8DD484ULL, 0xE95A25C2E25C7E32ULL, 0x9A89F9C48307D5CCULL, 
            0xF4F91A4040658F65ULL, 0xF515F90C848C06B7ULL, 0xEE7BDCD2A6204E39ULL, 0xE3CBA4F2C8892B56ULL, 
            0x201111ADFFE327E0ULL, 0x7FF068C8603AC15CULL, 0x010D57E1AD10D17DULL, 0x0683FC57944C67E9ULL, 
            0xE3D061EB0C6B84F0ULL, 0xB53A0DF2353BCD90ULL, 0x692C6C009BB7C6FBULL, 0xEB0F2D70EAD23581ULL, 
            0xB298B398FA893D0CULL, 0x2095E1BA8CFE62C9ULL, 0x7ED21908F562BA39ULL, 0x3C3911049FC7146CULL, 
            0x7F86833C5DF5D717ULL, 0xFC93AC9334ABAB71ULL, 0x8044FCE8559D3C9BULL, 0xE7EDC20470928532ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Softball::kPhaseAConstants = {
    0x9EA820E19D3D05DDULL,
    0x6A26C0EF4583B37CULL,
    0x5F8BB79691130A33ULL,
    0x9EA820E19D3D05DDULL,
    0x6A26C0EF4583B37CULL,
    0x5F8BB79691130A33ULL,
    0xD89E1877F784F708ULL,
    0xCD4EA96C375D1A36ULL,
    0x3B,
    0xCB,
    0xC7,
    0x48,
    0x40,
    0x01,
    0xFF,
    0x90
};

const TwistDomainSaltSet TwistExpander_Softball::kPhaseBSalts = {
    {
        {
            0xCBB2259C9A500C0FULL, 0x135D47F76512691FULL, 0x7A5F7C442C1B3590ULL, 0x3DF793F7E44CDB1FULL, 
            0x9CDB8E57DA05C37AULL, 0x968FEBD15BC69B71ULL, 0x5AB00F8CA38DC82EULL, 0x729F534A17C10220ULL, 
            0xEE71C9EAB36F9362ULL, 0x473A30405020A83FULL, 0x248B7F964A740061ULL, 0x0C3DEBF81961D66AULL, 
            0xD3FCB6E90232493EULL, 0xE339F775809DAB75ULL, 0xF37A69C55948DA12ULL, 0x7110144D2F8042E4ULL, 
            0xE962D05585035D42ULL, 0x1ABB52D5D44199D2ULL, 0x6F6E9A47AF401624ULL, 0x9AAD8EED362212DFULL, 
            0xEB29444A3D67D407ULL, 0xC2FD770862AE1871ULL, 0xFA2980AB6715F4F9ULL, 0xE319906A22EDB23DULL, 
            0x798B59635A1E1CF9ULL, 0xFDFDBCF64FD17E39ULL, 0xDD4D0BFC3D8CD48EULL, 0x373D9EFF66A5D7E0ULL, 
            0x87984D6DF62DD6FAULL, 0x1F0A6E28A709B4C1ULL, 0x66E49D898ED795C2ULL, 0x64D747802A2EE382ULL
        },
        {
            0xB7D7CB3E2FA83341ULL, 0xDED89F7DD8E46ADCULL, 0x9A7C1D4663B77429ULL, 0x13B23CBF1B9B9EFFULL, 
            0xFE73B56B668AC475ULL, 0x5C23500EF45099CEULL, 0xFE0B333BB8D078F6ULL, 0xEA33317570886681ULL, 
            0x8B66A663AB3180D9ULL, 0x381A12A166FEC12EULL, 0xB9BBC11E3D3E936FULL, 0x13019FDDCDEBAC9AULL, 
            0xDED0C7C3305BCF6AULL, 0xF0595E755EE97E21ULL, 0x44379BC9B899F53DULL, 0xB443A6B38A78B099ULL, 
            0xDC4DCD35652F212BULL, 0x22F6E4C884C72C27ULL, 0x9742673F814F4D0EULL, 0x974613B8826BFDAFULL, 
            0x15362785423D4D22ULL, 0x47919214C58C5DB5ULL, 0xD659AEBE9DF3D167ULL, 0x54832415298AA409ULL, 
            0xF2744507E282E4D5ULL, 0x8127E4821DA6C570ULL, 0x6D17D1EE96D98A43ULL, 0x3E95509CF14A74DBULL, 
            0x97F8A03BA9C50344ULL, 0xB4DA313D4BDEDB46ULL, 0x34228686F8FDAD5BULL, 0xEE093A2013D99869ULL
        },
        {
            0x5B31D8602645432EULL, 0x3506443FEA63D86AULL, 0xB9AC0D8CF97662A0ULL, 0x650174919CB91A26ULL, 
            0x66C8DECD64F5D857ULL, 0xDAF096E9A9095E11ULL, 0x03F6B7380377A7D9ULL, 0x45F94E9A8A8C2863ULL, 
            0xE4024BBC6B0B0407ULL, 0x371FEBFC0DB7024AULL, 0x83CEED2841244564ULL, 0xA72345845D6C8F11ULL, 
            0x8F1136A650ADE8C9ULL, 0xC7BA5D5C4CC9B7C8ULL, 0x0F08B88D71C5CE15ULL, 0xAC14F95B3966E33FULL, 
            0x69DD3DD51ECD39A8ULL, 0xEAB5A9DE839D7457ULL, 0xBB120CB786156E6CULL, 0xED1173E3CE6C3F33ULL, 
            0xF9C6588D800EC63EULL, 0x591609D79FA3C785ULL, 0x6A1398EE6AC6B073ULL, 0xEE60CC58DA7C7858ULL, 
            0x883ACF7C6F1F4AD7ULL, 0x35CC109B12F45277ULL, 0xD191DF8BE343E578ULL, 0x521CFB0AE6450C93ULL, 
            0xA811872F78C2276DULL, 0xB06ADE5348FAC1B9ULL, 0x5A9C85B34B80E499ULL, 0x16960843CE7E1AA8ULL
        },
        {
            0x7F74490E82FCD67EULL, 0x84865D458BEF8051ULL, 0x892FED24FFC5C5B3ULL, 0x04B265ABF78851EBULL, 
            0x42A4640B3E68A004ULL, 0x19F4677DD4C49246ULL, 0x9452F48F51EC76C8ULL, 0x22355357F5A2312DULL, 
            0xB94428299314DC4BULL, 0x9768CFA53C1C8534ULL, 0xAC1D98AEAB744A83ULL, 0x22369055646FEB47ULL, 
            0xAEDBB7B27488277DULL, 0xF6066139155B7F09ULL, 0x0878D600F2EF80ACULL, 0x66838D2AF1F4BFBEULL, 
            0x81AC8140CA4122CEULL, 0x0650DA58CAF44B6CULL, 0x2F4D76ADCAF14BA9ULL, 0x9798A778A0087415ULL, 
            0x1032ABF02020AA98ULL, 0x66088BCBF944C24BULL, 0x1B0B77564ABB31C6ULL, 0x8CB76541E8D383DAULL, 
            0x6B6D0857620789A2ULL, 0x83BC59A94E14F68AULL, 0x8763295A5D5C3387ULL, 0xAF202243769BCC9AULL, 
            0x1BAE87B5C10CD69DULL, 0x0E3AF3E2D2084760ULL, 0xF5DC79C0482B5BCBULL, 0xF703C17C7950A9ADULL
        },
        {
            0x048CC65E2DBC76F0ULL, 0x79419EC187D3FCE1ULL, 0x709E62C2F73AD4F1ULL, 0x7C35B966FB427D15ULL, 
            0x90EFFC56461978CFULL, 0x1EE631D55367C50FULL, 0xF410B4D3F2B53B7CULL, 0xACCE72816F86A490ULL, 
            0x258778703636995CULL, 0x00FCFF1200C9C1FFULL, 0xD390E23E4C2A12B3ULL, 0xBBDEA1D1FFB6A5BCULL, 
            0x7E7FA7FAFEA2E3EDULL, 0xCC310E5D1F674ADFULL, 0x035EE8F1196C7D92ULL, 0xBB61C1884BD66048ULL, 
            0x67E119642AF19C72ULL, 0x5EFBA7E3F6E3A94AULL, 0x940490C79852DC1AULL, 0x65667A262726D086ULL, 
            0xBB7A60555A499C77ULL, 0xAB235426C3E5776FULL, 0xB7B488949A4E7EA4ULL, 0x7741EC0106A80C39ULL, 
            0xB145FC67BF9157D7ULL, 0x48C19C45A25E78F9ULL, 0x962ACE54DB84C718ULL, 0x7B2A18CD788C9CD5ULL, 
            0x6920BA409148BC8BULL, 0x4FD8721D112D7A11ULL, 0x124273EA595B3B2EULL, 0x89E7EB67348BD549ULL
        },
        {
            0xF360416FB8D9A55EULL, 0xFB5CEA63CE82C6D7ULL, 0xA407AAB03A7F1037ULL, 0xDBDDB2BF77D1730BULL, 
            0x67269DAA47B9EFC9ULL, 0xC72B1E38DA0B337AULL, 0x53B70ABCCE8C2DEFULL, 0x112D94634FE72639ULL, 
            0x37E63AB18E55B59CULL, 0xB6F9935543AE2023ULL, 0x82A4926D356FFE4DULL, 0xD4E2F166D269DA3CULL, 
            0x8535B3E1C498DCE1ULL, 0x46245B3488DBDA93ULL, 0xCF77E82858DD89B5ULL, 0x9E7ABFA7C972D7F0ULL, 
            0x09A6688E30C8F181ULL, 0x4F6951452FFD5370ULL, 0x69ADBC9413427890ULL, 0xF25AD2B2AA825C83ULL, 
            0x0E7BE79016D47457ULL, 0x9E7270972A01B4A8ULL, 0x5A6064C613E4AED4ULL, 0x4156EEDDEF17F3C3ULL, 
            0x89E5C9C10605936BULL, 0xC6ECCED34EE010A3ULL, 0x72D86ADD1B6C6742ULL, 0x504D847B4E57A3F3ULL, 
            0x8FEB7D7E2503CC6BULL, 0xC1D45AB758F36C14ULL, 0x695BEDDADCF9908BULL, 0x7E50DBA5159A5672ULL
        }
    },
    {
        {
            0x12CEEC73532A35C7ULL, 0x685827C8E38EAFA4ULL, 0xF5D29C6B339B83BAULL, 0xDE74216A18893417ULL, 
            0x7D8F0A80D19394C4ULL, 0x3B068BB74D45676EULL, 0x869B02896CF8D714ULL, 0x53CA31C21421761BULL, 
            0x4BB9B8F597E6247EULL, 0x7F954B5D0252A174ULL, 0xF2139B7C4FE1A83CULL, 0xAD145F1A2D0D7644ULL, 
            0xFC0D3A78860F93FFULL, 0xECC502221469CEF1ULL, 0xDEB15401FE7257F2ULL, 0x2472F026D975F56EULL, 
            0xD262BBF5C10C407BULL, 0xA3D6B9A234837CBBULL, 0x99C8724EDE0F6C4FULL, 0xDEE7040489950045ULL, 
            0xE11749DFEA329306ULL, 0x9C5879C2A1FEF768ULL, 0x511593946A7858D2ULL, 0xB613E3285F087B42ULL, 
            0x0E349F2F4B04E6E7ULL, 0xFF5F0C981D837021ULL, 0x00B10BA2A98FF120ULL, 0xFDB9EB62171CB5ECULL, 
            0x8CF2495E35A40017ULL, 0xDA521FE181735812ULL, 0x316425D833F54BA4ULL, 0xCCB42DA28ED796E4ULL
        },
        {
            0xFB1E705689E5D979ULL, 0xE0F9BEA4F8C43555ULL, 0x79B2337C0A46D016ULL, 0x5538E7CAE991BA7CULL, 
            0x83E346B61B4E5F4AULL, 0xEC43D921414867FDULL, 0x48F202A5196A835BULL, 0x5494EF49B8C4C7FEULL, 
            0x2A5CD63147EF3E4CULL, 0x0017092D05B8B324ULL, 0xCB6EB43B9EEC3AB2ULL, 0x76A673F20C24F864ULL, 
            0x0A9123CA1F2A3294ULL, 0x9DBA5EA1A86EF83EULL, 0x2E41C9B88DCAA922ULL, 0x9BAA4819880CD1B3ULL, 
            0xB8D26FB4690782F5ULL, 0x21ADFDF2802F7A81ULL, 0xC24BFDA57DC44E00ULL, 0xFDF9DA3AE0E91EF4ULL, 
            0xA7EFAADAF89A17ACULL, 0x06B16C0AB7D66DAEULL, 0xED4829A761104113ULL, 0x530DB1863BA3DA7AULL, 
            0xBD21036EA1E4F030ULL, 0xF4F316184E234994ULL, 0x8DCF1A47FF58F0F5ULL, 0x61916A23E2FC18E7ULL, 
            0x1AADB950DF68DCACULL, 0x1521005B2FC8C1C1ULL, 0xE223CFE1114219F1ULL, 0xAA0DA0484D6AA1C3ULL
        },
        {
            0x3733BDCB69D42DC6ULL, 0x1E6986960D6E7F0FULL, 0x78977F936F6D2ADEULL, 0x8664AF249EFC767BULL, 
            0xAC816318F9DD8409ULL, 0x0328A49BF36CCA14ULL, 0x8598BB0FFE8D358CULL, 0x08966C1992DD18CCULL, 
            0x04D897961C3A6E01ULL, 0xDA94460075CF25D0ULL, 0x6A02956218EE79CAULL, 0xEA971CE9CD421A6DULL, 
            0x469862BCF2D1E081ULL, 0xB1747B8903A89476ULL, 0x92BCC435DE3A7BC8ULL, 0x3BE0F3AB49EFEC7AULL, 
            0xA318763310529049ULL, 0x54A67CA6556AD330ULL, 0x91A7C877E05CECA2ULL, 0xC536643FF725E201ULL, 
            0x1CDC0BDAA1E7D9F6ULL, 0xF53A888BB8EB9345ULL, 0xED90C6AFB80F0668ULL, 0xB33656F71C8B0C9BULL, 
            0x9E1C72FC0F17DF49ULL, 0xA09CB9A7B35B37A8ULL, 0xC5F84A786550DA9DULL, 0xF586375A816CE6A4ULL, 
            0xA396F61E84B30308ULL, 0xF92DC01C011C7FDAULL, 0x91C6AB2F8C13AC48ULL, 0x24DF06C4F5FF1468ULL
        },
        {
            0x28FA7E7C03261464ULL, 0x7FD7FD309DE3BED3ULL, 0x9367E45B278EF939ULL, 0xDFFD0C6547AECF95ULL, 
            0xA68FC1FFA937802EULL, 0xF7A3703B44E005C1ULL, 0x305DBD2BA32A2574ULL, 0xB4739EF924019C26ULL, 
            0xF47BB45937984238ULL, 0x1881B7AB5A5C169DULL, 0x90BE4CCDCD4EE38BULL, 0xE360DC51E9172E0FULL, 
            0xB62F9D292C7BBA84ULL, 0x37F3DD2C4F1751A9ULL, 0x7B1C2DC0A6836E48ULL, 0x23D6BC9AEBDEDD60ULL, 
            0x50A9C2BEE2E9C823ULL, 0xCA4073A4C9CC60DFULL, 0x4AB6D4806D641F68ULL, 0x9A2C203463372A24ULL, 
            0x57AFD0E101D84589ULL, 0x75B95A16101E2F06ULL, 0x47BB2F39A9C41E2BULL, 0x8DA573504B569C70ULL, 
            0x245E00CF2BC8033AULL, 0x102D76758CFF1F8CULL, 0x010AA05E35DAF707ULL, 0xBD08E1A0ADD4E17DULL, 
            0xAC35485C0D63A9CDULL, 0x08D32EE56CECA264ULL, 0xB1882D50616D9271ULL, 0x95A975752F05B19CULL
        },
        {
            0x82992ABC604C94EBULL, 0x8D28C7B08D717A60ULL, 0xF5B7931553569879ULL, 0x9F913E9C6066793EULL, 
            0x5CE7CBFBE01DEF04ULL, 0x43C90A92BB593A6DULL, 0xC309B79CCB371B5AULL, 0x3695E9CC95A7B8C3ULL, 
            0x963B5A971BCF4BBEULL, 0x22602A8247BD4CA4ULL, 0x795F5272AF4E728AULL, 0x04D3F4CC5858A09EULL, 
            0x1FA27ECF2852E1C4ULL, 0x8277335638CE838FULL, 0xCB07643E1A8D5C1CULL, 0x3EE998459481DD80ULL, 
            0xA27E2FC7A82110C1ULL, 0xC4AF4A24215E00BCULL, 0xAB6FDBA6D9EFDA47ULL, 0x9A8B76F577BF1AB6ULL, 
            0xDE0DD74577CB2E59ULL, 0x3F6E1A1A29A81368ULL, 0x33405FCD7F1FB851ULL, 0x1F8347A7A7CF3E63ULL, 
            0x5ED85AA87D3AB7D2ULL, 0x7DE510759AA75570ULL, 0x0D40401DE9E3217DULL, 0x4E7F0167E7547C27ULL, 
            0x1304FD150D2DA276ULL, 0x6D10EBD4B175AAD5ULL, 0x1743F2D5E310635FULL, 0x60DC4794E32D456DULL
        },
        {
            0xF8B775AEB45A5B88ULL, 0x5E64E9A5E866E852ULL, 0xE11A6F1DA068AAA8ULL, 0x3733E8E8CABD9C35ULL, 
            0xCCF93C94AE1BD1FEULL, 0x8D77B42A15D4CBEBULL, 0xE744453373347D13ULL, 0x34F80C14A0AD8644ULL, 
            0xB9F915DB36E2EE63ULL, 0x75201E31BC0A41CDULL, 0x22440F5AD3D310F4ULL, 0xAF75D7D56A621D90ULL, 
            0x4A563B617830E506ULL, 0xBAFB3CF8A0752BE5ULL, 0x309B3C57BE02780FULL, 0xA471617F1F4A3DCDULL, 
            0xB9E2916C51F79AEEULL, 0x76D46BD3435420AFULL, 0x8E5657932C5B9CC3ULL, 0x6765B6E4FA71A379ULL, 
            0x7DA4B10F2F12DF65ULL, 0x2D74E468F0771D07ULL, 0x821DFCD70C03D752ULL, 0xEFB7E970EB529400ULL, 
            0xAB1E44C5F9EBAC45ULL, 0x09A853A5E69607EEULL, 0xA68FF121067DB433ULL, 0x15E86D86FB982E1BULL, 
            0x17CC107F5CBD4262ULL, 0xD84C965FA64C505DULL, 0xB5225AB574AE2AE8ULL, 0x1FBF2F38677E6D39ULL
        }
    },
    {
        {
            0x055EF198436EF009ULL, 0xB3E0FF82EFAE2849ULL, 0x76C8E11A3074166FULL, 0x00A3AD2A24F92844ULL, 
            0x504F66248A26A9CAULL, 0x9A60A5A81BE0DA57ULL, 0x93F592CFD23DF933ULL, 0x4F3FAE928E5EE03FULL, 
            0x67954E546678D8F1ULL, 0xE940B1D81129303FULL, 0x5E6CBC1EF46C2979ULL, 0x1F0C60C4D8C244D8ULL, 
            0xE9A72FC78C9969BCULL, 0x7C9D470E02ADD3AFULL, 0x989B6FD784E0D153ULL, 0x8717558751C7A61FULL, 
            0x53E1AA453393A0ABULL, 0xF8F3B46E8C69BEF0ULL, 0xDEF1C20D7BBC904EULL, 0xC0255111280AD32FULL, 
            0xE97150AA3266D608ULL, 0xFB0934A4EE8D8329ULL, 0x7BE7FC80B06D3F0BULL, 0xEEBBE2916DC54C73ULL, 
            0x40D70390A9EC3649ULL, 0x7FBA2FF824A76C18ULL, 0xA8FBC2E9B76A9C73ULL, 0xC1D5F5148043FA5EULL, 
            0x1E275AEADB301BE9ULL, 0xF41C8B53157CB3C1ULL, 0x0A19F9AEFF42BDA2ULL, 0x6C15F320B53ED046ULL
        },
        {
            0x9C18F25AF6CFF04EULL, 0x2986485FE4877543ULL, 0x6182E7920BA2F361ULL, 0x87F4E7DCB837D601ULL, 
            0xD8CEECA19BEDEDC7ULL, 0xB9289EF1793F6CDEULL, 0x055896CE5543EB24ULL, 0x42771AEA0B47C7D7ULL, 
            0x0005A23CBD5D5B4FULL, 0xAECA8ECA8E3B84A1ULL, 0x79705BC12F32070CULL, 0xE6A432C8F59B9FDCULL, 
            0x02F7B1D1A8495E6DULL, 0x907AABB5FE4D185DULL, 0x09902A5B46FEAEFEULL, 0x38F2357011ADF8CDULL, 
            0xDCAE5B3AEE170F0EULL, 0x7E18A0ED0995ECC2ULL, 0x1B11A6E399D371BAULL, 0xA0AA3617E71D9BD8ULL, 
            0x51FD366954467F93ULL, 0x26B3D4CC4E0B7D83ULL, 0x2DA56A48967F845AULL, 0xE87031D4B8B38EE6ULL, 
            0x04F6BFF3FCF8762FULL, 0xFFE829CD06D9B5FCULL, 0x44B45CFED0A94A59ULL, 0x47F4E30E8B3FDB3CULL, 
            0xA1A1980EF1DD52B2ULL, 0x4F8AA10BA1C770D4ULL, 0xF1BC1AC342F70FEEULL, 0x35A6E28463A4CB96ULL
        },
        {
            0x2ABF3EFC118E16C0ULL, 0x7D33B83BDD16CA65ULL, 0x859607658816428EULL, 0x31AD04AE2DFBB89FULL, 
            0x21B09A383F019A20ULL, 0x0A0A7C77CF5C66B8ULL, 0x84A6DC308BABC541ULL, 0x15F108BFDDE05FD0ULL, 
            0x73356E264BD474BBULL, 0x7B038B95F0528753ULL, 0x630629E8D28F07B6ULL, 0x3F1629EFF283CB65ULL, 
            0x943E749BE0907D55ULL, 0xED7602D4D8DED3A0ULL, 0xE5F788FD592ED232ULL, 0xAB17947EBBB3DEF5ULL, 
            0xB75643F538E75187ULL, 0x7FAACDFA68E70230ULL, 0xA749B462BB58A1E2ULL, 0xA5D56A311F0ED171ULL, 
            0x71B26F72C0ED576BULL, 0xBFED9B8923EAC251ULL, 0x5564CE4B3D5A8CC9ULL, 0x054AD541A2D07646ULL, 
            0xC698F8396AC98FE5ULL, 0x134E62D1B9027A53ULL, 0x897F9604D22794C2ULL, 0xDBEACEF2087829DFULL, 
            0x3753C28958CFCA0DULL, 0x1975DF611D01478CULL, 0x84363A5BAD4BCF8EULL, 0x47D2552629EFC60AULL
        },
        {
            0xA34D1AE210B3E459ULL, 0x59A33D6C6E266348ULL, 0xF59598A74CA10AF7ULL, 0x4B664AEB14809A5EULL, 
            0xDC05E5044FEEE61FULL, 0x38A5F02D2FDFBCC2ULL, 0x2C37316ECC12111AULL, 0xF5B707894D7542C6ULL, 
            0xB176B1621376B4F4ULL, 0x76B8A8F9320BF1C6ULL, 0x61C840F15E4B8996ULL, 0xA841E7E17AF6FF9EULL, 
            0xE8B188DEFE4B6D86ULL, 0xC4CD9841907FCF6AULL, 0xB145479B4DE886F9ULL, 0x569F3D3FE476298FULL, 
            0xB9DD31DED275C89AULL, 0x5EE0BF5CFAC76635ULL, 0xE9B152F46019D1FBULL, 0x0418A9E313F99576ULL, 
            0x900D8BF95C7309E9ULL, 0x9AA09D55C554E119ULL, 0x36B5E9C1606A5F07ULL, 0xB72F0DB52E57D199ULL, 
            0x6EA666DD07EE96D0ULL, 0x9D1457AFABB225B9ULL, 0x829E1169E8832E98ULL, 0x28570DA5D18546B2ULL, 
            0x98CD4E59F66E77FFULL, 0x7DD3CE228CF5AFD0ULL, 0xC16F162EEB1BD09FULL, 0xF9CC39328BEC6881ULL
        },
        {
            0x319730FD502635D3ULL, 0x25AF7231EC7179ADULL, 0x3663CA01CB0D9983ULL, 0xC323AF1B45379EC3ULL, 
            0x5F47E470C8A5ACB5ULL, 0x68B76B8DEFB3D831ULL, 0x3DE60FA38B56C558ULL, 0x0BAE98C87C24122EULL, 
            0x96E565797E721BA5ULL, 0x91E0FD4EF5D52CA4ULL, 0xFB17C476BE6B88D8ULL, 0xA4EF428FA7181119ULL, 
            0x63AA46C3CC55F9F5ULL, 0x18F0A58E1DC87730ULL, 0xC8E912C9F9AFC7E2ULL, 0x73FF1FF9C007D679ULL, 
            0xA055C75AB4CB9A70ULL, 0x2E6130E1394A984FULL, 0x8A332DD7BDCE29DFULL, 0x1FDDCAEBFEAF0FF3ULL, 
            0x50E324116B13E147ULL, 0xC999BFF07F34A113ULL, 0x88806DE81A677410ULL, 0x6CB1A215670EDDF5ULL, 
            0x346E6A2ABCFB5BB4ULL, 0x43A64568D08DE67BULL, 0xF940D7D74EFE8497ULL, 0x05F766752AAB55E9ULL, 
            0xEDECD4D6F9A88644ULL, 0x78A57D55190075D2ULL, 0x9CE7D5B970B6F54DULL, 0x3916250CBA3FF20AULL
        },
        {
            0xEF46B38B97E82BDFULL, 0xEEFAF27724AEAA69ULL, 0xF4312EBB0A0B4E35ULL, 0x5F3E3CA4DE625F12ULL, 
            0x74160CDC5F0FC5A7ULL, 0xC138D13A91529996ULL, 0xC1DD0BE921D6BDCDULL, 0x0E4D89D930B8C633ULL, 
            0x462984D023554028ULL, 0x7CA55564839D8C03ULL, 0x9E4C3779BCE97BAAULL, 0x7CBF63E461B093B5ULL, 
            0x1A46165FB5695D04ULL, 0xA9DC46D3D23E3B96ULL, 0x5A2A63ADAE3BEFDBULL, 0x32A01B54E7461A0FULL, 
            0x485CFF4D872D5E94ULL, 0xAD46E642DB234931ULL, 0xEA25D486EECD23CDULL, 0x369E1C5751B6BA06ULL, 
            0x7D7A6CF12A49A837ULL, 0xC1DCE4FFB3BB7F3DULL, 0x1E30C84A1F4806E6ULL, 0xF00CEBA7B609821FULL, 
            0xED3D1A60F0C6F28CULL, 0xC18C8C32C1E05D26ULL, 0xB2D47A6FED41AC72ULL, 0x5FA92FFADCEDC719ULL, 
            0x58B91BAEACEC7A46ULL, 0xD9F2DE9EBA06404EULL, 0x260B36865574C20FULL, 0x7E033D8323916109ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Softball::kPhaseBConstants = {
    0xBED8D04AAB300936ULL,
    0x7F1F7BA2B1DA621DULL,
    0x2DFCB5A3570073C1ULL,
    0xBED8D04AAB300936ULL,
    0x7F1F7BA2B1DA621DULL,
    0x2DFCB5A3570073C1ULL,
    0x033B1E4BA2B09FE1ULL,
    0xC67AD56BBCC7EBD3ULL,
    0xC7,
    0xBB,
    0x63,
    0xB8,
    0x43,
    0x3E,
    0x78,
    0xEB
};

const TwistDomainSaltSet TwistExpander_Softball::kPhaseCSalts = {
    {
        {
            0xA7F35F10603DABAFULL, 0x88C8C6EA5621EC67ULL, 0x4E1D30951D8D6FE5ULL, 0x2B61815544DE7055ULL, 
            0xA3909F55FBE633A7ULL, 0x2512193A0D42C1AEULL, 0x1C869C409FAFC167ULL, 0x668B5B3C21D22996ULL, 
            0xB892C77112851649ULL, 0x9C351EC048569C08ULL, 0x5C54810F3B2ED612ULL, 0x1362EEE6C4B51C7EULL, 
            0x9BAC29DE7DCF5D8DULL, 0xCEA6A1C0915FE795ULL, 0x1616AE2468BE631EULL, 0x7031CDC470AB9AF2ULL, 
            0x839BEAAAE9AA58E7ULL, 0x7B1575903DD4E8D8ULL, 0x1ADA683338E060C7ULL, 0xA03001398DBA2DC1ULL, 
            0xE4C45FF8E3B12000ULL, 0x5B91D979DA9A4E3AULL, 0x46DD30648620DF81ULL, 0x5FA99A450E062945ULL, 
            0x36CA6CD3D5FD0E36ULL, 0x370014B44DEFCAD9ULL, 0xACA0277D5ED83235ULL, 0x426ABC18875AB1F8ULL, 
            0x4BACDE866F284359ULL, 0x37ACD10841B3FD11ULL, 0x5A62EF4B35B79631ULL, 0xCF6C9404E1A58A40ULL
        },
        {
            0x0FC26188142805EEULL, 0x9DEA98EFC84E066EULL, 0xD01F5CDC56F35244ULL, 0xF0EF4F96A549346CULL, 
            0x56EAAE532038563FULL, 0x39E2482F06CE90A2ULL, 0xDFAA9A7C3726435CULL, 0x579905556654A89AULL, 
            0x23E8BB4E822E1D95ULL, 0xBBA7E1D5504977EBULL, 0xE3A179A0EE3BB3F2ULL, 0xD59A6D6EBC558B54ULL, 
            0xF15911397EEFD1CCULL, 0x86F820C93FC32245ULL, 0x76EDCE41681633E7ULL, 0x5592FE7197CAA5E9ULL, 
            0x1516F3E7279D74DCULL, 0x73AE8667AB0D8DF2ULL, 0x728EBA83712E24F5ULL, 0xB816DD81B1794270ULL, 
            0xA5EE31E785F121C4ULL, 0xDB6FEC5AAC4F0FB0ULL, 0xF87FD8F4B2E6CE0CULL, 0x4134A131C39DDE6DULL, 
            0x6C95CEE9E72D1A00ULL, 0x2D2B77767F8BC5F0ULL, 0xF49FE3EA1B981FA1ULL, 0xF5E8337C64211970ULL, 
            0x1B32AF5537B96711ULL, 0x9E5B5DABB1CCF046ULL, 0x4327A937B29E3D7FULL, 0xD0657AD2B937FC45ULL
        },
        {
            0xF87A23E6E5EADD40ULL, 0x9DE49E8E4E2D9438ULL, 0xAA934C7A20B24486ULL, 0x0C62321087FEDD0AULL, 
            0x0CDC211E3A738B8FULL, 0x3B32BE6F87991C4BULL, 0xF5D7B74F74609895ULL, 0xBAFC7ABE2A97DB7AULL, 
            0x08658A24849626F8ULL, 0x3D0EED3F78DD4D0BULL, 0xD1C41D3BC6C23246ULL, 0x3A9F804354C10E3BULL, 
            0xDD749818B1C3F2B4ULL, 0x6BDA731446D5AC46ULL, 0x762F7911F2FC79BBULL, 0xB664E57EBAB61039ULL, 
            0xAEE692EF19A117F9ULL, 0x91CB61F03E1485E0ULL, 0x3669C51D8235BACCULL, 0xCD88E67B135268D4ULL, 
            0x74BEF2FD51475250ULL, 0x66F9AC3DFF9479D0ULL, 0x84C636CF6568AB7CULL, 0xCAE87ADD669D2841ULL, 
            0x1B28DD98940834B5ULL, 0xFEE51A34CB519CFEULL, 0xD5038D5F08844DAFULL, 0xB740CECD46EBCBC5ULL, 
            0xF5D6403F9A1C86CAULL, 0x89F729F483FFC83CULL, 0x7220F6C5B18D7BBFULL, 0xBF2DCA749EAC0DDCULL
        },
        {
            0x56825B9A2053457AULL, 0xA6EE5E4F74BD734EULL, 0xB96078E85E340FCCULL, 0x5182EB42A2B3974AULL, 
            0x005B7B14C40A504FULL, 0xC3E13F908134711BULL, 0x2C8D81C42A6E3364ULL, 0xB95F6F456314D8A4ULL, 
            0x0E6D55A69F62D1B2ULL, 0x2D318CA75176D852ULL, 0x0775FD1F2E0A21E8ULL, 0x819B98D04F9C6381ULL, 
            0x9CA26BAE6DC117DFULL, 0x8D5D6EA78B0935CDULL, 0x12CF3E808F7AA59CULL, 0x389D237CDEE48FA7ULL, 
            0x046766475150D1F2ULL, 0x6E21A0A1D0BF87C2ULL, 0x11BF06179DE2932AULL, 0x02ACD0A60DAA7408ULL, 
            0x917BBDBCEFBEFDEDULL, 0xBA598E184981B5CAULL, 0x547EEBAFB882CC06ULL, 0x3EC72513CB72503DULL, 
            0xAE1BBD53F59629B6ULL, 0x61B6DF288A402B50ULL, 0x1772A87C718810B2ULL, 0x8BD3DCC2A736D86AULL, 
            0x96DE035E9C0DA751ULL, 0x254F72587B1BD3C9ULL, 0x8D06C1D9C4F02B64ULL, 0xCF00202AB36694D1ULL
        },
        {
            0x5AAEFF58D6CEC7B5ULL, 0x0A0E89CFB46003CCULL, 0x12FB04B1C375E9DFULL, 0x0EDA3EBBAAACFF28ULL, 
            0xDABF9EAD7D3AA197ULL, 0xF4C7D9007B6A153BULL, 0xFA749E2074D42A9EULL, 0x9C3B6FFA6CECAEB9ULL, 
            0x83C98AB3E98C683AULL, 0x813A2568F4A0A1ADULL, 0x9DF9DB681177FE9DULL, 0x8F62E21CE93AE837ULL, 
            0xD7D4525B882706E8ULL, 0x1EFA30176AD076CFULL, 0xDCCB9E7C4B09AECBULL, 0x2D020EF6E2A1419AULL, 
            0xD9F66AC90F3550FBULL, 0x70E52412F42CEF17ULL, 0x45877FB74506F437ULL, 0x37A67313C52FF54AULL, 
            0xBE79047608BD8284ULL, 0x9634A5D01537C285ULL, 0xDB026DE7E4127D9CULL, 0x06CD2F95EA6D9ECAULL, 
            0x6B4365C956CC641EULL, 0xFFEE92BBAC5806C2ULL, 0x9B46BEBFD5539328ULL, 0x1BB3F84EE73F9B13ULL, 
            0xAB1DC8AE680FD584ULL, 0xC501DBE1B196523BULL, 0x7474378836E9C0CAULL, 0x61739F5718A93B06ULL
        },
        {
            0x910DCC2D38C07A53ULL, 0xD848DFED44E3A8FEULL, 0xEA7B140EAF7E8160ULL, 0xF6B6EB89C2B71258ULL, 
            0xB53F83CB5BAF1768ULL, 0xEFC67DD30C472E5CULL, 0x62E760358024A0BCULL, 0x43D8D2D4889F3484ULL, 
            0x1F6C44E75C138404ULL, 0xE1E0E5A677083059ULL, 0x8540420A831B90D8ULL, 0x3B435185BBAE81D7ULL, 
            0xCFFD2FDA23E910BCULL, 0xAAAAAFD4D43AB3FCULL, 0xC0EA937583DCE790ULL, 0x946C5F628192314EULL, 
            0x9C5BDB80CE94657CULL, 0x43459824EF3BC2FFULL, 0xD58C26ABA69F6036ULL, 0xD4A470042C713143ULL, 
            0xF7B3AF1F89789E90ULL, 0x547AE00EF36B2DCFULL, 0x28256E466D87D2A3ULL, 0xD9DA52C1CBE1B749ULL, 
            0x4AE8AD1C5383D516ULL, 0x276D70B1CCDF220CULL, 0x100CB5B293A2EBC6ULL, 0x3B524452EA3FF02EULL, 
            0xB7B8BFDED45AC110ULL, 0xFF355E3B722ECC8FULL, 0x52E6F3899EF1BC88ULL, 0xEE7D0380ECB4B810ULL
        }
    },
    {
        {
            0xB5EC79A629ABC90FULL, 0x137D547C738F9A6EULL, 0x7BB430E7E01417CFULL, 0xE198BB327922311BULL, 
            0x36FF19C74CFC0E61ULL, 0x6EF3B6F67A8259E6ULL, 0x0C23ACF950147ECBULL, 0x06FE675B100D1D84ULL, 
            0x12FFE0DA206B7AEAULL, 0xDD86350A4D3A4405ULL, 0xE1816F15E4525DC1ULL, 0xA6F91696326E8BF3ULL, 
            0x31706E3166C906E6ULL, 0x7D06B0D680C9D219ULL, 0x8D80546052DFD7D9ULL, 0x7FDB15B9FA78CEB6ULL, 
            0x377F60174D46D2A9ULL, 0xF35FE22AB04E7265ULL, 0x006DF993CA3DE80DULL, 0x0EA17EB2703FF4EDULL, 
            0xFA4A78A2F6EB72C1ULL, 0x97E28ED3DF623846ULL, 0xCD39AB5FA79584A9ULL, 0xD4CC58A3CC3AB53BULL, 
            0xB7BF268CAD77F316ULL, 0x46E86D8776EFEE88ULL, 0xDD11D7040F5A6787ULL, 0x1404D63BA1876414ULL, 
            0x60917C40FE500E05ULL, 0x7D5BD6CDCF525882ULL, 0x7DA66AF85E3F5609ULL, 0x0BE1C86B8E577F8EULL
        },
        {
            0xD05343B9EF1F3AEAULL, 0xBF5A3AE380780D4AULL, 0x32B5C229A671689DULL, 0x3195D2F4C73A4BA4ULL, 
            0x14FB47D51E59F1B5ULL, 0x4176E61AF6AAB7BDULL, 0x85B3029D507B4B9DULL, 0xE584814804E4AA5FULL, 
            0x4C3A966C43089A6CULL, 0x1854A5A70328B68FULL, 0xF3A4CFDB1DB96C27ULL, 0x98B73A8760FFE07FULL, 
            0x5C6775DDFFFE91F2ULL, 0xF35695015034BC2AULL, 0x3CD81D47B289914EULL, 0x7E5B3A33A5ABA2DBULL, 
            0x007F3F98E64A4636ULL, 0x5631CB8B0946D5C3ULL, 0x0EA2072244CD0E64ULL, 0xE14A56BD11663A79ULL, 
            0x90B1FBE034C51D22ULL, 0xC6BDB34C77F15770ULL, 0x59DF460805D486ADULL, 0xA83117BD43B8DA2EULL, 
            0xA704B70B554F91C7ULL, 0x7EB4EF463FD28714ULL, 0x791CCB5D9818112BULL, 0xCA1BDB5377C3525CULL, 
            0x76704679E231D5E9ULL, 0x14A166B44F690B71ULL, 0x8EAFB51176ED3E75ULL, 0x6DBD50B80139808AULL
        },
        {
            0xB5B8BA83E2C335B0ULL, 0xA4DFD2EABFDCDB8FULL, 0xB9B6C294A08009DAULL, 0x257ED22B88C84AD6ULL, 
            0x66548A0C835FDFB9ULL, 0x6CB2CA960D688BB2ULL, 0x3DCD5E238844FC89ULL, 0x8ED87777087DE7ECULL, 
            0x4FF5CB5ADCF792A5ULL, 0x27074673D9515E08ULL, 0xEEACAC3BC615B9DDULL, 0x095E0ABB50DAE993ULL, 
            0x5A7A63DF56B31323ULL, 0xE9D0213D10E9D92FULL, 0x9855156680BC26ECULL, 0x2855C1EC6634B459ULL, 
            0x730C838EE6C6E07AULL, 0x8EAA7A745F3BA737ULL, 0x161EB08ABCC231F0ULL, 0x20B2F135CA7C5DFBULL, 
            0x1404AD63BD9BFDCFULL, 0x58B50E70B4BFA873ULL, 0x44AD0899DCE7CD7BULL, 0x5AC6FA9A72DEC68BULL, 
            0xB31CD2B632556E9CULL, 0x786F8E61653A3CBAULL, 0x0390DBEB049B61DDULL, 0x01A607E57A6B1138ULL, 
            0xC58213805B35F097ULL, 0x8F10D9C20BE0EB79ULL, 0x472E96F7DD71AA1EULL, 0xE5CF91B748866779ULL
        },
        {
            0x5D9E0B821C9E0DD7ULL, 0x3E9A1AECB2E1BF3BULL, 0xF33B0B93A3CD6754ULL, 0x47409C39DF5EEC98ULL, 
            0x4735445424F596B3ULL, 0xBDF1877F13410186ULL, 0xBAE05F5EB1E2C682ULL, 0x838FF60F5573C923ULL, 
            0xDF19A4C068AD671CULL, 0x977917FE373BE22BULL, 0xB5DBB26ACC6B8FE5ULL, 0x256DD16EB4AF3C6FULL, 
            0xB87EEEE489A6D87DULL, 0x47D1DF5790D57CA2ULL, 0x1E04900B80404C3FULL, 0x229A19243DC622ABULL, 
            0x512F903509CEF12FULL, 0x379513FAAB5D840EULL, 0xA728AB81C69ABD50ULL, 0xB678845720384439ULL, 
            0xD017450D0CAD5140ULL, 0x6CBF78FC1AE51D91ULL, 0x2A64097222DE37EDULL, 0x298AFD1AD04EE7CFULL, 
            0xD6C3673F0EEC9D20ULL, 0xBC5C7A1F9DAFAC53ULL, 0xAE62394FDA4A956FULL, 0x38D16E922787BFA1ULL, 
            0x6C27E86B3A97020AULL, 0x1003C34B5883CB3CULL, 0xEE30763B3939A5A4ULL, 0xA3A168DBBCB23309ULL
        },
        {
            0xB45993FCE5E0F4F3ULL, 0x2905BEAB2F82D08FULL, 0xE5C563428D9D4E2AULL, 0xF16583D7B57A41F0ULL, 
            0x95945868C2E3D14EULL, 0x4C7F3724757096AAULL, 0x22B140391B34EC87ULL, 0x74D72976BD92E2D8ULL, 
            0xC39F7DAD5057D8E7ULL, 0x7FC90358D633470FULL, 0x7DA3502A87A24277ULL, 0xDB5D7813513E6C45ULL, 
            0x76DAD7FE96F1C508ULL, 0x1E32DEFDD9AC6645ULL, 0xAB198F8C033AC828ULL, 0xABAB574CDDAD925CULL, 
            0x5330C85B226BC615ULL, 0x5C183DA1CEBCCA76ULL, 0xF21F5AEA24C787C4ULL, 0x34E27AEDF3209D9EULL, 
            0x652F57E1EA523DB2ULL, 0x12102F4C7AA45143ULL, 0x7769B34E0135B287ULL, 0x46D1A7AA6D2D9394ULL, 
            0xBD03B6DF8DD65DA8ULL, 0x4259274D8AD7593BULL, 0x9841E5C4713489B3ULL, 0x001B97041C3120A1ULL, 
            0x4814BA93475D3EE9ULL, 0x544DDD65BA93CE9CULL, 0xCCA1A9615760C53CULL, 0xDC1F42C9B36D70E8ULL
        },
        {
            0xEE69B664B76F6C05ULL, 0x60F7A07AE922F306ULL, 0x65D097FCBB1F9C62ULL, 0xBBDA53A3A05B079BULL, 
            0xD8BD810D33F2EDD7ULL, 0x1CB6A316536EEC94ULL, 0xF2803400761DED1EULL, 0x14AE5D4920127F2FULL, 
            0x698346442D5FBA7FULL, 0x6DEE3F8B0602C4DFULL, 0x12344C2A25D6BD91ULL, 0xEB9A748936FF91BCULL, 
            0x68B0290C4CB8AFE4ULL, 0x17DADA981E1BBB81ULL, 0x24A212B49BA35DB9ULL, 0x64D184988216F88AULL, 
            0x8E71C572DD56F888ULL, 0x74B404F2A2A07E09ULL, 0xB994532E0BE81090ULL, 0x7632D0CD8DFC7CBAULL, 
            0x46B24B1E9EA8BCF2ULL, 0x9364192D69DFCBFAULL, 0x281F7A45FE6BBE86ULL, 0xDC038F3E22A7DCA4ULL, 
            0x3E8DC27083FBAC68ULL, 0xE282C5FCA60FA11EULL, 0x4E032DAB371DDA86ULL, 0x5F50A7B8153E3FE7ULL, 
            0xE5A643682E2CF9B3ULL, 0x75E4708CBCAF7473ULL, 0xF34A8AD74EB46164ULL, 0x4D8C9D8DB44002A1ULL
        }
    },
    {
        {
            0x1CC9168FD4BA0226ULL, 0x43A5A71162AFAB48ULL, 0x1FF6F2306A7EEADAULL, 0x2006A7A26FD7690EULL, 
            0x60A3B51492B1B8F1ULL, 0xD9658C9E887496BBULL, 0x139F83D09DDC9853ULL, 0xC92C57BE2E8272C6ULL, 
            0x7AA7DB1E6B23D6B5ULL, 0x1686A5AB0D02DAD7ULL, 0xBEF0217784CE6759ULL, 0x055A566B2EFD0959ULL, 
            0xD230B008B7D2EA0FULL, 0x6D382B0AEEFD149DULL, 0xADB06A71C2C49E9CULL, 0x4DA6AFD0E69C7E36ULL, 
            0x1E7E5869AFC78D80ULL, 0x5BB3370335D34A61ULL, 0x211D3CE4A9BBFB13ULL, 0x88F45270047770CEULL, 
            0x89649510CD687F0BULL, 0xD1C8171BFD763A8BULL, 0x8B28B74B24B8EA98ULL, 0x624B7664CDE023E8ULL, 
            0xE6C13A1F8C4CE0BAULL, 0xB59ADCE1487C65C9ULL, 0xEC2926FD769CF181ULL, 0x4138A30F9C642AE1ULL, 
            0x274AB3B72F0081F3ULL, 0x8DCDC663DAD3D104ULL, 0xB3E7BFCCB0BF2AD6ULL, 0xF571201DD26601EFULL
        },
        {
            0x7DFFEFCC8A7013EEULL, 0x7B555B912BE55DE5ULL, 0x163D22FC843354F4ULL, 0xE4DD6BA32F9D32E8ULL, 
            0x2A85130A315C3EEFULL, 0x37710B374FC0FF14ULL, 0x03FF6326C3D4DB57ULL, 0xC7F6DAE69ECFED94ULL, 
            0x81CC06F645F33E57ULL, 0x8110AB60C9036CE6ULL, 0x42521C45DFF95A1BULL, 0x8534C1140F6D65F3ULL, 
            0xC2DD07899880ED73ULL, 0xC0BCBE6C8F0DEF0EULL, 0x2DB42C41190C2337ULL, 0x434E69D51B1B2005ULL, 
            0x57EFAB422196280AULL, 0x1254C2D9292E1FBDULL, 0xA4E1E1079217B14FULL, 0xA03A59BBE9FC406FULL, 
            0x33B09FF07CF37BBBULL, 0x90695500A5366DF0ULL, 0xFD3B0DABF5CD2889ULL, 0xC4C46DDB536E8403ULL, 
            0x8AFECB45167382D4ULL, 0x371105E0D9C4E2E3ULL, 0xFF7167E3BC3D7A92ULL, 0x5F21C33265D94435ULL, 
            0xE420466850FA6297ULL, 0xEE53A50E0CA04FC8ULL, 0xD2C68491E0D3CF49ULL, 0x2205496262CA74FEULL
        },
        {
            0x1E949310BBD4879CULL, 0x3CB3B13F3048B6BFULL, 0x4C40001ED4D57B9FULL, 0x65B6070177041829ULL, 
            0xCFD85865A70ACAD2ULL, 0x4BC7531C178F3092ULL, 0x96FD93C56C1FA166ULL, 0xADB78621D3B7A833ULL, 
            0xEB0BD81091C4B569ULL, 0x454383264D54A387ULL, 0x6E4F5B8ABFEAB6BCULL, 0xBC2DAB24659F54E4ULL, 
            0x82EF9702F515C14AULL, 0x32DE419B68BADF86ULL, 0x02D53A0C0B9DE28EULL, 0x31F7596C5B3E71D7ULL, 
            0x7AE00DD71F00562DULL, 0x4711BCD89EE96196ULL, 0x85A6C4CED3388E2CULL, 0xF6039D107B5F3CD4ULL, 
            0x5A77B5F95F4AFD84ULL, 0x99078AE85ECE132AULL, 0x1F31FDCC818DE960ULL, 0x8589A7B6142E11A2ULL, 
            0x3FE2A73F4848912BULL, 0xB600E655C12C05FAULL, 0xDEADEC8F9B52E628ULL, 0x7E3D2A52977CEF39ULL, 
            0x8D2941F89722EE04ULL, 0x30B091219F082451ULL, 0x02E5978C005893A3ULL, 0x546101BC9607FC1AULL
        },
        {
            0x94CEC3A4E5B4387BULL, 0xD5D7B15D90AC2AA8ULL, 0x6B10E3AC86A4D04FULL, 0xEF640E772C3CDB63ULL, 
            0xE686F187810C1676ULL, 0xE2EE8596CF2B6959ULL, 0x332F5CCCEC69A7B8ULL, 0x0D31C29A7508A9AFULL, 
            0x14A7DDC78DF3BB71ULL, 0x1B3DFAFB59CD0BF0ULL, 0x7C1D2A24A8666B75ULL, 0x207CE9E23623B639ULL, 
            0x5F68E7493BF13597ULL, 0xF834779147980BF4ULL, 0x9DE2FAA002EA384AULL, 0xBF0980FF6377848BULL, 
            0x36AE8D33C72B3321ULL, 0x673848D6E8D87F2BULL, 0x379A373AAD82DDEEULL, 0x5314FEF62701B1E6ULL, 
            0xF8B0018BD1BED073ULL, 0x42DC60BDB9201AC4ULL, 0x05B9AF2C502DC352ULL, 0xAC92B557DECA4790ULL, 
            0x74D3E39FC307B00FULL, 0x94667AB79A05CF64ULL, 0x46879046F80DDC3BULL, 0xC77244AB48FC7587ULL, 
            0x413F3876CBFD5934ULL, 0x2FDD68125AAA0369ULL, 0x686F81FE79CC5899ULL, 0xDC6F6D1F7BAB897CULL
        },
        {
            0xF3500BC3EB19A134ULL, 0x491F94C3AA79485AULL, 0x668D4E83339086E6ULL, 0xD1ADA82506FA5F57ULL, 
            0xF1AA7554B9B9C3CFULL, 0xC7BE65D708A520EFULL, 0xA0FF00B4C212B3A8ULL, 0xD69285670368D5FFULL, 
            0x282784EA34284C17ULL, 0xB25E35361DA0CCF9ULL, 0x34AE44B501A5F7A5ULL, 0xA97B4CDA5978824AULL, 
            0x7C4C2DBD63B0ED60ULL, 0xB1A0EFE3B741F026ULL, 0x851CACCB09BD5393ULL, 0xBF31DF7E83433499ULL, 
            0x179FC11A21852040ULL, 0x4E27787775722F08ULL, 0x24C26E2B58D67E69ULL, 0x4A51A4C7E8F9D92AULL, 
            0x9B1DF3A89E7D712FULL, 0xD0A0CCB39077949BULL, 0x7142698990317455ULL, 0x8D25018C6005CF38ULL, 
            0x1B0A08FE57DDAE64ULL, 0x397257B14D8558F8ULL, 0x44DEB1442D106FA1ULL, 0xB6EDCE49B1DAF238ULL, 
            0x799F4428F26BDB8BULL, 0xF27CF49263F8DA7AULL, 0xEE66ABB07158459FULL, 0x2EAB0D9EBA4C90F5ULL
        },
        {
            0xB421E51ADC9B61CCULL, 0x4A594069CCFAB52DULL, 0x302C86103761BB06ULL, 0xFF32DE718E3BD3D7ULL, 
            0x6DAD0939A1730F4FULL, 0xBBBBEC9D0BEDCD82ULL, 0x9FA8469D3A6FEB66ULL, 0xC647AAA169D27BD3ULL, 
            0xF57C26159D0D53D0ULL, 0xFA2F01928051346AULL, 0x5EBB024129FA4BE5ULL, 0x9F804164C44A5177ULL, 
            0x0A98113C1C6868FBULL, 0x773D7A413B5DC328ULL, 0x0B666C1069BFB9D4ULL, 0x50E00099AC911DBFULL, 
            0x5AF56E2594C34552ULL, 0x98FBB8DDD09B302EULL, 0x72B15D56588166F6ULL, 0x2CF4381AC6C95891ULL, 
            0x2A03B46B608C9382ULL, 0xE8FFC72A7483CE21ULL, 0x605D679569E18DA4ULL, 0xB0E65538C08FCA82ULL, 
            0x2AE79D3BF3BB7DEDULL, 0x51501D8492DB9248ULL, 0xA21F5C7400A4CF22ULL, 0x8E6096F5A05BF62CULL, 
            0x7A77D790CF609FCAULL, 0xE58A95DFF34B2BEFULL, 0x9E8CA5D19182A253ULL, 0x2C40444449B21B93ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Softball::kPhaseCConstants = {
    0xD72181CD975B72B0ULL,
    0x5F9126D5DD0B6C24ULL,
    0x7A2D73868ED8E281ULL,
    0xD72181CD975B72B0ULL,
    0x5F9126D5DD0B6C24ULL,
    0x7A2D73868ED8E281ULL,
    0xCBCBDEDEFD22E3D7ULL,
    0x53653733E860FC52ULL,
    0x50,
    0xDF,
    0xAE,
    0x05,
    0xD5,
    0x78,
    0x10,
    0x3B
};

const TwistDomainSaltSet TwistExpander_Softball::kPhaseDSalts = {
    {
        {
            0xD001B0494490C0ABULL, 0xF5FF171123302437ULL, 0x1417DE281DC32DB9ULL, 0x5257D4829D5AB7E1ULL, 
            0x303739D722D1DCBBULL, 0x0CB632EC84F97F8FULL, 0x0B2B44D679320517ULL, 0x06BCC790221B1F6DULL, 
            0x90431BFF7BB3F285ULL, 0xD363F227FD6E6555ULL, 0x32CC0919D697910CULL, 0x37C66695AAFB13A0ULL, 
            0x49617581A2801080ULL, 0xBAF105EDD66D917BULL, 0xD3E66E86371CDE96ULL, 0xBEF3CB77C94D8B41ULL, 
            0x6C2547EB32E034B4ULL, 0x845A60128A58FF6EULL, 0xE9B0A8DE514CDA63ULL, 0x90B9D302F6F0619DULL, 
            0x063F3AE4C25710B3ULL, 0xD517E51836BE2685ULL, 0x5E77F6C72CC19CD1ULL, 0x874DCA4466191C32ULL, 
            0x0E968E6D06C7FC7CULL, 0x8E8B4624DA3223ABULL, 0xC6BEBE3C8BF0DEECULL, 0xF4B4144BB454946BULL, 
            0x7F4BF01EAFC6B95BULL, 0xC017F3718B02E18EULL, 0x1CB3F9D92240E4A8ULL, 0x1CAA00F91B54F2CDULL
        },
        {
            0xB4BA21D54592C9BCULL, 0x401350105293BEDDULL, 0xF6BA21F08BB7E768ULL, 0x77E7154750DC9B03ULL, 
            0xD7899DEADC20EC8DULL, 0xB0F45016044CB316ULL, 0x9AB974889C5E84A8ULL, 0x9E775599E7C5C18EULL, 
            0x848DA7267231D983ULL, 0xED41C99324AA8FE8ULL, 0xFF6DE49F642D7155ULL, 0xF8B78F696BEEA948ULL, 
            0x85CDB64C58C6AEB2ULL, 0xE98BD47981A78441ULL, 0x99C6D9A3609A68E5ULL, 0x27DCA873844D9C3BULL, 
            0xF77A05C8E60C1EB1ULL, 0xF65167B26A24415AULL, 0x46DA7490293EDE18ULL, 0x535E0F4896C7606BULL, 
            0x72AEA6DE5A9AE3D0ULL, 0x70D42A13B1CEA9C0ULL, 0xB313933E1A5EF9EAULL, 0x05FE3AA7A557F774ULL, 
            0x8646E2C95B4AD1F0ULL, 0x6CDC87C1EA6C5509ULL, 0x09D3CE0F7F98DEBDULL, 0x3F4AF87363A43DB6ULL, 
            0x6A6E61CD0A22BFB3ULL, 0x9A7DA1C2D37368EBULL, 0x1E2BBB72D9624E72ULL, 0x7D4F74DF53C8B4EAULL
        },
        {
            0x6B72BF68DDE1C038ULL, 0x02C0EE58C11CBF62ULL, 0x19061291BA30DC17ULL, 0xE5C27C4F540783C1ULL, 
            0x495660E768BC9394ULL, 0x59F33231DC493008ULL, 0x071AFDC0A1D4D7C5ULL, 0x97C1D84D41C66DD8ULL, 
            0x49D0CA688467D98FULL, 0xF8CDE74250C03F48ULL, 0xC8CD0A6570783AEEULL, 0x48BE18A8A2F47899ULL, 
            0x8D7561CC3E75F1C8ULL, 0xD012BABF49C60889ULL, 0x0BF6FE7146A09EA4ULL, 0x4782DD0FDD55A8BBULL, 
            0xF23E259B02A7103EULL, 0x7C639AD85589C788ULL, 0x67C643A6BED190FEULL, 0x6086BBA1D7364AE8ULL, 
            0xB7130A5A789C4214ULL, 0x8720DB052E489D1EULL, 0x9BA195496321AD1CULL, 0x2E0829D5DFB76ABEULL, 
            0xDD28EF0CB945373EULL, 0xA69457CFF05D8738ULL, 0x86020581686F898AULL, 0xA0135CB43DE55D20ULL, 
            0x622B6462DA23ED58ULL, 0xD1A40EB66AB9A658ULL, 0x9BD79923E95285C8ULL, 0x303CD29AA7940667ULL
        },
        {
            0xB57890B00D0FDB11ULL, 0x9A98D62AD448C66AULL, 0xED791C5284A3C4C5ULL, 0x8A6B76312AFD1A60ULL, 
            0xEC5F9DCB52BBD318ULL, 0x6601AECD3641BE8CULL, 0x50C7618D8B64BBF0ULL, 0x704252C9DB7D2497ULL, 
            0x17D3937B86387C5DULL, 0x87E6C76022B3A982ULL, 0xE7EE3A36A4E88A48ULL, 0x378E983C28CA0FD8ULL, 
            0xEE738EB336E77EC8ULL, 0x5D1903EA906571C6ULL, 0x8A60E6E0AE80CFE2ULL, 0x0B2B5C42DF6F3AEEULL, 
            0xDB12337C035BFE9EULL, 0x5D17FC06B8C6BFF4ULL, 0x27B47E9E46F33605ULL, 0x3010A3013B3CAB5AULL, 
            0x517C76A2964CD354ULL, 0xAE14A303E8A05B4FULL, 0x4E7267DF20236A97ULL, 0xC8E6AF9D5BC2E923ULL, 
            0x993C5A611289C54CULL, 0x15DF9E7A7481BBB0ULL, 0xE2BF438E99CA1066ULL, 0xFD5B5F0FC42B13A3ULL, 
            0xC54689741C11E9B1ULL, 0x600DD127986F6CF8ULL, 0x2CF31E9A4C7F217DULL, 0xF70B99D58A30FE36ULL
        },
        {
            0x4EB2F495419C9E6FULL, 0x7BC57D64A5C1A184ULL, 0x003BE93F794FA40CULL, 0x8D6467D3E7FA2D3DULL, 
            0x3ECAEBAB54428AAEULL, 0xD3E8B7BE046E3925ULL, 0x5D10DE36F43D86B2ULL, 0x8BE01773F7390B51ULL, 
            0x0030E33D65C47580ULL, 0xA503FC32A167CB56ULL, 0x524E08F7EF7C2C85ULL, 0xA25387D91F600D57ULL, 
            0x2A8626046AC31296ULL, 0x96C0B237C102CA64ULL, 0xE56D2BA12009E301ULL, 0x29EDBD97C1448A60ULL, 
            0x93E3582B0725D188ULL, 0xA022B9DBF28BC6E0ULL, 0xF1794008028237B7ULL, 0x1FA0C391F2653E00ULL, 
            0x5D5CFE2FE8F19567ULL, 0xBACFECDC46CAFD4BULL, 0xCF6E58D04E44FB6CULL, 0x4CF6782ACFF99737ULL, 
            0x0F37E19371284601ULL, 0x3D8355D284196904ULL, 0xD92FC4603E65BA2FULL, 0x241A8E61DAAEC68FULL, 
            0xB66E065B43A63CC9ULL, 0x3916FD4EF28AB047ULL, 0x871281A242D2C210ULL, 0x4C8E27841AED109EULL
        },
        {
            0x8E0A0FD686F6878BULL, 0x30A089F9DB0883DFULL, 0x337A9CDB2908501FULL, 0x0F64100ADE4E89ABULL, 
            0xA2040AEBD1942FB7ULL, 0x2C6EADB84B74A74CULL, 0xD04DE17E14C373EDULL, 0x37FF5DEF665B4E6DULL, 
            0x58B10AD046E1CD7FULL, 0x3AD0C5827E543F80ULL, 0x6A1BA930774928AAULL, 0xCD2A0E88170F45F4ULL, 
            0xF35F24B5BFCAD6E1ULL, 0x56DDAD24012096DAULL, 0xFFFB61E27E8CA347ULL, 0x532254F59AFF00FFULL, 
            0x43C22446551D1889ULL, 0x05079027E45A7882ULL, 0xEEFF5D93B48E3E1DULL, 0xB740676D67A09B6AULL, 
            0x4859E10547000B80ULL, 0x805CC37825D3A012ULL, 0xCBC12848C2595003ULL, 0xB42654E8FDA34384ULL, 
            0x2EEB67E5B9D7625FULL, 0x2E913FE8211205E6ULL, 0xE70EB05FB0343438ULL, 0x6FE85C4001E81AB8ULL, 
            0xAFA19D7B1229514CULL, 0x8EF9F6A41CF054AAULL, 0x6225ADC6B68F0291ULL, 0xE62177DCDF6112ACULL
        }
    },
    {
        {
            0x9F3773AD6969B316ULL, 0xE6482C7B5808900AULL, 0xC7F0331AB5C65096ULL, 0xF4686ADF15A20845ULL, 
            0x136CB7A214D2DE4CULL, 0x04D682D4B5A48158ULL, 0x79FDF721DE445C2AULL, 0x662DD95B6C13D738ULL, 
            0x6CF2E899F3068984ULL, 0xF3CEA124BA64357FULL, 0xAB728B0F6736FA79ULL, 0x2DA31B9DD41BB048ULL, 
            0xEC0927CCA3697503ULL, 0x89EDA9C17FBACBA0ULL, 0xE9294BAC9F5B75F3ULL, 0xED85A1BCFF8F6843ULL, 
            0x19EC7E43806B0712ULL, 0x6F53F17199A0BA35ULL, 0x25E5B2FF375E3DB8ULL, 0x1C2E54687688E3CBULL, 
            0x9C7DEA9908112E8EULL, 0x4FA7F0B8D3795C22ULL, 0x2FD50B6C5365F1B6ULL, 0x0F9FB1424DEB1D13ULL, 
            0x4CA9BFD8E1941D12ULL, 0xE5F526902726A727ULL, 0xE3F50CB57495E79FULL, 0xF20DEAECDD52A201ULL, 
            0xC188B9ABC6CA976AULL, 0x6D9034BCEE7B13D2ULL, 0x642BEAE41BA79227ULL, 0xD2DF0A9D6056D0EBULL
        },
        {
            0xAD2C3CD447CF82E8ULL, 0x0589302B6309FED6ULL, 0xB2F27FB10E56BB49ULL, 0xD1CB7C50E7BA5F18ULL, 
            0x063456BC46624D37ULL, 0x63D3FBC546B2CF34ULL, 0x2A150888FF0E420CULL, 0x25F79E8D19864C82ULL, 
            0x4241D475BE0CCF5DULL, 0x92467C90BB8DA9B7ULL, 0xA9E0A16EDEC0890BULL, 0x45768A005AEE7B38ULL, 
            0xE8F2C7F287307B0BULL, 0xB1186CA418B923C9ULL, 0x36F5E4470F23232AULL, 0xBD2B381C8EED8A8BULL, 
            0xD691392551EBF6E7ULL, 0x4763ED2BBCAD7C90ULL, 0xE09C5C553D046E22ULL, 0xA1DF1A3E2B56F126ULL, 
            0xC45821307FA446D6ULL, 0x44B9EA3ABE90EE8FULL, 0xF427D277E12771EFULL, 0xB6E01A0905777FA5ULL, 
            0xA760CF087070DCDDULL, 0xD8C8927B64525609ULL, 0x89665E6BFD37D31AULL, 0x5FBB4DDB9947ACD5ULL, 
            0xC7F38E9005208152ULL, 0x0823143594A4AEF6ULL, 0x372D83538F0CE3B8ULL, 0x149205BBB4C19E66ULL
        },
        {
            0x2411E53BE9160FA8ULL, 0xD022265A67F4DD72ULL, 0xE1B5EE047B30E6B1ULL, 0x88CB7E16403B47FCULL, 
            0x75C667E16F0366F1ULL, 0xF60D33413623F03CULL, 0x80EA9B868936A0C4ULL, 0xFCD91EB6A4B2FD99ULL, 
            0x5E2209D9D4311D05ULL, 0x8DA08DC3E24A2637ULL, 0x2A8747BE7ACDF942ULL, 0x4C8B987FC4DF10D2ULL, 
            0xF6CAB2B01DECFF08ULL, 0x0B50B61D83BC9C21ULL, 0xAE1724EE61E1F742ULL, 0x360A607E2DE9B112ULL, 
            0x218B8969CF7C399CULL, 0x4763B5790C4457A5ULL, 0xB7FA55520C48E35BULL, 0xD139874EFB6E459BULL, 
            0x3AA6D008E73E507EULL, 0x02BAB5D8299BF56CULL, 0x9FB0275B77819FA3ULL, 0x29C1422E2FFD05B9ULL, 
            0x68D71DED45FEF013ULL, 0x0FFF1F47EAC79635ULL, 0xD0BCB019B94F8CB5ULL, 0x59341156F8678944ULL, 
            0x0BAC49791DADDBDCULL, 0xDBBDD6CFA8C65AD8ULL, 0x738B19AB0B6EDCF2ULL, 0x14F31F05135A24D9ULL
        },
        {
            0x23F5AED32A3B81B6ULL, 0xDF8479C30B400032ULL, 0xCA99D11541B49933ULL, 0x412D23E5183F9A67ULL, 
            0xA52516BE556848E6ULL, 0xC2593031964D1F27ULL, 0x51763C58B2916018ULL, 0x0EF76EDAE8E649ADULL, 
            0x34E104B3F92AB03AULL, 0x326FA6485FF4C803ULL, 0x5C3B02063437E5F5ULL, 0x6BABF51EBC522D44ULL, 
            0xD6E8ABA69D1BD4DDULL, 0xB21C2E98FC8BAF68ULL, 0xD518D7C7323CC238ULL, 0x9AC17D1D60C9B0BDULL, 
            0xB9925FD07944EA87ULL, 0xB6F73A834AD9A0C3ULL, 0xB127FA2F22379F8AULL, 0x75D0050638AB6241ULL, 
            0x33C12C2213BBAB12ULL, 0x2D5B0989C995A529ULL, 0xD1339B8B89534F20ULL, 0xA7F423A86B29EDBFULL, 
            0x794A565A714F13FAULL, 0x999A3C47CC57FFBEULL, 0x663FF71A12E897A5ULL, 0x47BA1E82BDA4B6E7ULL, 
            0xD955548B2025F4B7ULL, 0xD712F631464335C2ULL, 0x3FB321623958E444ULL, 0x1056DD8AD73ACD9CULL
        },
        {
            0xEC4CC0470F96CC98ULL, 0x7F4D53385B5D6FE3ULL, 0x571AF17FDDE80675ULL, 0x87AB541261866367ULL, 
            0x6A971C36A3AAFBB0ULL, 0x8776E2660F9BBC39ULL, 0x54FCF8EB4F428D63ULL, 0x74DA70F116240FE7ULL, 
            0xBD814E7ED38F1F4FULL, 0x9D02DE2415E90968ULL, 0xF2B67F475F9A5DE6ULL, 0xE3C461AA01431212ULL, 
            0x5304529ECBA0B22FULL, 0x89F7BEBB6684DE0BULL, 0x773DA9241F767C6BULL, 0x1167C2FAC70F2219ULL, 
            0x3D0DEAE77561512BULL, 0xC83CD10C6B97C820ULL, 0x5855A911B3F56C02ULL, 0x405E52B3D0ECA266ULL, 
            0xE70D3B44CBD87E5DULL, 0x756120C923144596ULL, 0x821B1C57B638122EULL, 0xB7B9EAB6B08E97FCULL, 
            0xF63292853511A83DULL, 0x7287051C8A26A061ULL, 0x6CB9BAE285709285ULL, 0x94722D129A932B0BULL, 
            0xBE17D83EEA2F3D7BULL, 0xD97580F62C3A3A20ULL, 0xC108884E0F126A04ULL, 0xCDE8ED8FE9CE9632ULL
        },
        {
            0x15DCAFF3C6166646ULL, 0x64C62A4F031382ADULL, 0xB2B888C81AAD1CA2ULL, 0x47B7330C2DE62431ULL, 
            0xEC5BB026FFDAB429ULL, 0x8595FD952EB86E89ULL, 0x1994CF60DA46328BULL, 0x5070B29F73DEE907ULL, 
            0x06B5CB11B244B1ADULL, 0xEEF1054163516DEBULL, 0x616591E9B8D8E649ULL, 0x2ED61706F4A8E1BAULL, 
            0x058ACF5471680485ULL, 0x97F4F20DFEC3A28FULL, 0x1BD4A56E44DD251BULL, 0x4C5297D5E36969FEULL, 
            0x6370823AE804D0ABULL, 0xBC8D1429F49CD982ULL, 0xDE9673ACEBB67B1AULL, 0xE387C0AB03EADF8DULL, 
            0xC40ED8B60644100EULL, 0x38560DB2D4651505ULL, 0x3B7585864B966C52ULL, 0x52B2090BA1190467ULL, 
            0x275FDDC07EF95700ULL, 0x783FAD7FF9F5075EULL, 0x5501E80085766B8CULL, 0x47AF54233C45D25BULL, 
            0xCFDA95600EE58ED1ULL, 0xD6A455E3D7D9EE8CULL, 0x9E71DE06A0D8AEA5ULL, 0x4E85D57B871A6262ULL
        }
    },
    {
        {
            0x97678944E864039EULL, 0xBE1C9418C1F97C2EULL, 0xAF920B3BED7C4484ULL, 0x52B615B71B6D3A6BULL, 
            0x3AA93125E3DC0558ULL, 0xF4C2FF06ED94E20DULL, 0x8381E5B097F65467ULL, 0xD6DC17A69A88383DULL, 
            0x17D5EF2C8854769AULL, 0xF26BFAD5070C7E6EULL, 0xEADB50C1A8154F6EULL, 0x70CC826FA1C559B4ULL, 
            0xFDC4F1B03AB05911ULL, 0x2AB8EDE6CE1F040EULL, 0x54E5584D2702B34AULL, 0x41F24BF5C083080FULL, 
            0x095E3DC70AF8A141ULL, 0xAC0C466434B3EA44ULL, 0x815A55739D1F6627ULL, 0xB506845690BC9504ULL, 
            0x1879DFDE3125826EULL, 0x4F2DECFD4946D312ULL, 0x6C9445BC629D0E47ULL, 0x6CAC8D5A9EC0307BULL, 
            0xE9A3C1E359FCD65DULL, 0x2195BCBEF715C872ULL, 0x0922616742CCA7FDULL, 0x89659C2F8F267F50ULL, 
            0xA3995FF0FF39D0A3ULL, 0x7509BF6F6FC48559ULL, 0x9648EB3B51AAB473ULL, 0x622C357D28E6FC06ULL
        },
        {
            0x6EDE1E03C39AC076ULL, 0x2CA32D8148CCD02EULL, 0x692991D9E77FC2B6ULL, 0x966CBCBBC9AD1294ULL, 
            0xC894534E057D30D7ULL, 0x90D3E86442FD1AFBULL, 0x8362BA94757ABDE1ULL, 0x2A7C188811D6D918ULL, 
            0x8E11197517BA9627ULL, 0x54F8592A1D18A60FULL, 0x6232FC4BEC7A9497ULL, 0xDE019302BBFA34A9ULL, 
            0x0E41626818475258ULL, 0x770F055E9EF16743ULL, 0x084A712D50E25D44ULL, 0x4FB930AAF017C8E0ULL, 
            0x3B11AA6F94415415ULL, 0x4043E2C6E24189C8ULL, 0x335FDBD1497B26D4ULL, 0x1009D6D88A7AB879ULL, 
            0xEDB3BAC73A7881C7ULL, 0xA547D09F1A74C0E1ULL, 0xEABA60F6D9112538ULL, 0x487F3256F8836609ULL, 
            0x52BCE100B60C08A1ULL, 0x297815BAE2BCD3E6ULL, 0x4380D8EBCE73B64BULL, 0x8F36AED48196E14AULL, 
            0x77AFDCC6735ED35EULL, 0x58A58581653DCD57ULL, 0x0AEE0D984EEF1B5AULL, 0x4E1DDBB17E82C44AULL
        },
        {
            0xE3A867A06DDF8327ULL, 0x257C324593EF6EAEULL, 0xF44B72788BBF0198ULL, 0x71FC81E78BDEFD66ULL, 
            0x9986568A37C9D109ULL, 0x8ED8C9343ABCA6D1ULL, 0xD25EF496C9FBA438ULL, 0xEFE433E1475DE4CFULL, 
            0xF73279444F49AFD6ULL, 0x61BB98D972264220ULL, 0x0113E5A56DA2144FULL, 0xCBD6E46091CCBD42ULL, 
            0xF89119FCFC78BEF1ULL, 0x573619C1F8CFEA60ULL, 0xFA7191A2502430A6ULL, 0x63047A6D52347F4DULL, 
            0xA298B7575F556DB9ULL, 0xA5FB5E4E6BEFA982ULL, 0xD6DD0AEDB57C3D83ULL, 0x49B3BBBBA9301124ULL, 
            0x021D0AA47E11CDA9ULL, 0xA5084BBE7DF63C6FULL, 0xCA3C2A566E68ACA0ULL, 0x12F23D4FBFEC328CULL, 
            0xDE7F7425C371CCCBULL, 0x846F9991F9FF885CULL, 0x43DE29EF9F401CABULL, 0x90E15C661EB31816ULL, 
            0x59F9948720CBCB68ULL, 0x9DAD8FD037056834ULL, 0x5F1DB38D2D6BB984ULL, 0x55FB6D4CED7BFC50ULL
        },
        {
            0x639357D195C882B7ULL, 0xC40DD43E130BCFB9ULL, 0xC44C691128AF05B2ULL, 0x0A9E97CABC12AE63ULL, 
            0x736DDDC78E9F7A43ULL, 0xF950153CF0264384ULL, 0x1100A708A49FEC77ULL, 0x5556B7043530AE5CULL, 
            0x2D09F544EB72C5EFULL, 0x9888951C35F54B44ULL, 0x9DEFD24458EA5D28ULL, 0xE2D999479914174EULL, 
            0x37BF1C418CD554FBULL, 0x21933AB343CEBA4CULL, 0x6748355F4D33553AULL, 0x67DE6778FC003791ULL, 
            0xE802A0A597D90871ULL, 0xF40EF71955870C8CULL, 0x837CEFF41B35DDECULL, 0xCF98B0FB608B4484ULL, 
            0x242A0798D4C8428AULL, 0x7D7A6D26F83B9092ULL, 0xBFC71941D80FD3F1ULL, 0x2A6092B1C5020E34ULL, 
            0x6B065F0B047FBE19ULL, 0xB4EAF9970B8F3376ULL, 0x5A9C809E871433CBULL, 0x5C43EE23846C0C8AULL, 
            0x29761262F566AF7CULL, 0xE4D795F5952EC47AULL, 0x73C8E97087A62770ULL, 0xD392BA12369E085EULL
        },
        {
            0xBE95CD6A4AD10068ULL, 0xD9F4BF162F909F1BULL, 0x5A6DC06AFAFE9015ULL, 0xDD6A58169F6C59B1ULL, 
            0x482664228EE5783CULL, 0x6174225893B48F68ULL, 0x8FA94C7732868666ULL, 0x0D4FFC0FAF164197ULL, 
            0x89E6BDC764943B9FULL, 0xCDFE180A567D4FF8ULL, 0x00C272A91BEAAC08ULL, 0xC241A6F426EE9242ULL, 
            0x3D312FB12C3180A9ULL, 0x5EE1B910A7D810A6ULL, 0x6D84502AADBD8DDAULL, 0x8D142B73F926F98CULL, 
            0xEF8507967FB6144EULL, 0x19C1E88B141FE3C4ULL, 0x8985D1AE85C7BF73ULL, 0xC4702657E561002AULL, 
            0xEE4591C447EED106ULL, 0x604A904B37962F86ULL, 0xAAE88119EADF1AD3ULL, 0x1CD3E8506ABF3228ULL, 
            0xCA5D905D18BB7FE7ULL, 0x723E77A153E8F0AFULL, 0xFCC0EB6D6713EB0EULL, 0x4814256CABA4A6FDULL, 
            0xABC85ED37AD20889ULL, 0xCD3A09FEF7EFE03CULL, 0xAE689718C14A9244ULL, 0x5E9AA89858CAA431ULL
        },
        {
            0x13EEFD9F44EF89F8ULL, 0xB9C11F93F52F375EULL, 0x8388AF35B9315056ULL, 0xD4CDAEE041B8182EULL, 
            0x8F67D506757616FBULL, 0x6F738D82BCACF56FULL, 0x0699318C49F91345ULL, 0xA7731D61A46A70D3ULL, 
            0x044CED4E6668B5B8ULL, 0x045A9BDCD744D978ULL, 0xE8245B9A5D3EAF28ULL, 0xECB5191D0F020BE9ULL, 
            0xFD74AEB33F1C8F0AULL, 0xE7EC9DE180FB136AULL, 0xBA0C330639E301DCULL, 0xA65BB7803688F670ULL, 
            0xA554846CDDAFCA67ULL, 0xAB0EC8507DD45274ULL, 0x826A2CBF04A1E971ULL, 0x4475527AF18D2A14ULL, 
            0x16FA504FB4B01D37ULL, 0xC261F7747D6F4C7DULL, 0x03D42C6B4E8E0262ULL, 0xBE465D40851399F7ULL, 
            0x87C1D8F3CC3E35FCULL, 0x8F33B9FF04D8E5DFULL, 0xB5ACD35850528FFDULL, 0xD0A778DB6A96B95FULL, 
            0xB854A272A01CCBD6ULL, 0xA8BC6BFD53A33BA0ULL, 0xC3FF75500ED45F34ULL, 0xA40F762234D9AB12ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Softball::kPhaseDConstants = {
    0x29BF293045711B4DULL,
    0xF38016A03F39B6BDULL,
    0x83FC1F0CC0F0B949ULL,
    0x29BF293045711B4DULL,
    0xF38016A03F39B6BDULL,
    0x83FC1F0CC0F0B949ULL,
    0xBB61BC78D862CF70ULL,
    0xB4C0476ABE5F6E92ULL,
    0x82,
    0xA4,
    0x9D,
    0xFF,
    0xD7,
    0x68,
    0x7C,
    0x05
};

const TwistDomainSaltSet TwistExpander_Softball::kPhaseESalts = {
    {
        {
            0xC8B128786877F552ULL, 0x5A2880B82B249E6FULL, 0x5D88544BA66A2471ULL, 0x65043D871B26EE2EULL, 
            0x3A5FF567EAE3E647ULL, 0xB88FD878A9828CBAULL, 0x0C148E1F39A64C20ULL, 0x214B0676740888B8ULL, 
            0x68D9FFF6D64EF8CDULL, 0x767F1DEA8797F03FULL, 0x5FA556AD517BD6B7ULL, 0xC6EE525FDA16FD8EULL, 
            0x228B175AAF42FA97ULL, 0xF6E0DD1BE92ED5F0ULL, 0x2358DCE30BDD0C62ULL, 0x8D3F08C1F4B96FB3ULL, 
            0x076CD885F159F1EFULL, 0x04C3A91E9660A08AULL, 0x7AD6715C7F48D489ULL, 0x3044BCC94EA50BD6ULL, 
            0x46BCFB809135D9B1ULL, 0x2D3909DB0C41F729ULL, 0x0B894EFFE723C563ULL, 0x534AE00FA8510DFBULL, 
            0x3E11841B3CB398B2ULL, 0x50378208F9C2965CULL, 0x255981F9761729A4ULL, 0x3AAB46B2F9FA6161ULL, 
            0x9256EE76B3248105ULL, 0xA3BA669F0FE8C1D8ULL, 0x3EDA635BF93F4A45ULL, 0x7A807ED258E16282ULL
        },
        {
            0x95602D64D1F05A1BULL, 0x84AB5391FFC7D217ULL, 0xF47F216D5732996CULL, 0x2352F43F76B5F31EULL, 
            0x867F3B1574B9F446ULL, 0x553CBD83A4180947ULL, 0x1BCE51EB3D6E1646ULL, 0x705E88C3E33BF467ULL, 
            0x3F9AB176ABBEE8E3ULL, 0xC026D9527D227FD9ULL, 0x9D4FCA8EB7B85CEEULL, 0x642E96E98BFD5342ULL, 
            0xA70A75EF13999070ULL, 0xA2CA7F88728FEABAULL, 0xCBA7FDF9EF9B358AULL, 0x7DF6E60E749EAC6CULL, 
            0xBCC9DB819B5B845FULL, 0x56D48DBC6C697F92ULL, 0x39DAFA4A9DD367F3ULL, 0xFBF39599FECC4EEBULL, 
            0x7A76D46A1FDC9C26ULL, 0xD064E2A4A18527C5ULL, 0xA7FAA43A658153C5ULL, 0x74D3F5017D252FC7ULL, 
            0xF4242F67159020F8ULL, 0xC2FD7FD8C8CFC87EULL, 0xB22AA4C954E66056ULL, 0xC6C73618EC6FA1AAULL, 
            0x61090A9BB77369AEULL, 0x30ADEB9939E434B1ULL, 0xA2099E730F8E2D5BULL, 0x40E4B99163023CBEULL
        },
        {
            0x3FB5844704C65BA6ULL, 0x8C600A7232E47499ULL, 0x72609C54BCDB7D44ULL, 0x3DC15C264D9097D5ULL, 
            0x4D129DEC0B69F63EULL, 0x7540A89CE9FD7FB0ULL, 0x46059284EBE23E09ULL, 0xA52F20CA3112839FULL, 
            0xD3B0C294DB670874ULL, 0xEFC51A636DB4A4FEULL, 0xADF2AFC9A6592DCCULL, 0x051C94D5530ABBB0ULL, 
            0x1AA206104179B033ULL, 0xE0D77897EFA2630EULL, 0xD62889D6DD3BE43BULL, 0x3473A8153C21FD03ULL, 
            0x93F30C60E543A660ULL, 0xBE7321AEC7CD74BEULL, 0xB1742FF42AC099ADULL, 0xDC9D1F770DACF472ULL, 
            0xBE2F1D8319FA6B91ULL, 0xD29C239AF5081A86ULL, 0xFB93C503045E81ACULL, 0x266B252234B473A5ULL, 
            0xE30E0A38581A3F25ULL, 0xB1981EBFDFEED47DULL, 0x87F0889089C2B1A9ULL, 0x860AE87CB3927C10ULL, 
            0x40928EA8845A2176ULL, 0xBE53E29832137C0BULL, 0xDACCC8E24F1554B4ULL, 0x04E666ECEE4AAB11ULL
        },
        {
            0x82C389CC93E9848BULL, 0xE7E8D4EA87729986ULL, 0x3D151707976E09C0ULL, 0xE63A6789E0BD8166ULL, 
            0x5E74D075A14F1C57ULL, 0x3448F67DDB092DF9ULL, 0x4DA74D29E6FBB343ULL, 0x2981CA5357A86BAAULL, 
            0x30A942011780FF8EULL, 0x4BF841A87884CFD5ULL, 0xA9745178B73AD5FBULL, 0x0CA86E0FBFD42F67ULL, 
            0xC12655FD4B8B2CF3ULL, 0x512B146FAFC97701ULL, 0xA2B8FD9AECD40740ULL, 0x3B81BA746ED3057DULL, 
            0x39191CF833653FD4ULL, 0x926778728E856EB0ULL, 0xE6126CFFE9692B49ULL, 0xA93C373C2D0EBFA5ULL, 
            0x9399F24393E3622BULL, 0xCD1B0C0A008050D6ULL, 0xDFF86FB6D5502885ULL, 0xAD10540AE16B09F5ULL, 
            0x3FB60612662D152BULL, 0x153645EE3406548DULL, 0x85841430B1C99D09ULL, 0x61F89AAB53C54480ULL, 
            0x6156D33DA3FB8C02ULL, 0x15ACFEEAC04BEDA3ULL, 0xCD5048D4DCED173DULL, 0x428B8981BF57AE6FULL
        },
        {
            0xD261A839E5353D14ULL, 0xB090211A4A9F6190ULL, 0xA254AC0FC3E2EBC2ULL, 0xD7A8C4E27C8D4F81ULL, 
            0x4008CCB6317D8630ULL, 0x49CD1FF64AD3BF42ULL, 0x0DC44E50F7742A12ULL, 0x915D5A2486885E42ULL, 
            0x5729E5F240F2C139ULL, 0xC4606637FA88B197ULL, 0x926C5A395657E996ULL, 0xB398501E39630CE9ULL, 
            0x89D601F52139D539ULL, 0x00B730CF55166D5DULL, 0x1865D3902DE0DC84ULL, 0x500AC342C1640293ULL, 
            0x184A84F06B16225CULL, 0xF288D958966AD151ULL, 0x1154605CCF0DE158ULL, 0xF74310F22A717013ULL, 
            0x42470BA04C96F327ULL, 0x99851F514DCFCF0CULL, 0x9D7F99CAD81AA4EFULL, 0x281355DDCD2346BBULL, 
            0x89B471ED62AD4537ULL, 0xCECE3BAE44BD5570ULL, 0x1917D5EDF27BC25FULL, 0xAD451B33598DB7F0ULL, 
            0x42B8F08410ED9AD0ULL, 0x61B4EE777FDE556DULL, 0x89B38BD48C531BC0ULL, 0xB2051B001CECB42AULL
        },
        {
            0x8EA16B763EBE5D80ULL, 0x141E17180CA10376ULL, 0x65768DA6A3FE2F79ULL, 0xCADEFBFFDB719002ULL, 
            0x737DCAE3BECD24D0ULL, 0x4C6B216F8ACC1E5CULL, 0xBEFDA6BB94B82A1DULL, 0xD45F31A3C6270465ULL, 
            0xDF40F2C98351A72CULL, 0x07E4F83D325F8D52ULL, 0xDB7F3E1D4955F13AULL, 0x6C7D172822D050D7ULL, 
            0xC6D00359818933DFULL, 0x0B7972B5D855FCD2ULL, 0xC84F7233DD38C201ULL, 0x515DD2F07F053252ULL, 
            0xC0BDAF40B74AE9CDULL, 0x9D96A815E21C2694ULL, 0xB2A510AF1017CC99ULL, 0x828B90D7D0195FCDULL, 
            0x1AD87F95AFEE2DDFULL, 0xFC5AA167DDC5B974ULL, 0xFC6B9D614448A02BULL, 0x118EB589EDFC825AULL, 
            0xAA5D7266679E256EULL, 0xBD1E44215A2F5B33ULL, 0xB998FE6B6B7C62BFULL, 0x2CE262D005099E81ULL, 
            0x053BA265F4130BE8ULL, 0x22784727B3E3CDAEULL, 0xA0E446EE4D1ABD40ULL, 0x7E5451672A9E90B0ULL
        }
    },
    {
        {
            0x7CC0A4EE8CDF0847ULL, 0x11D83958129B276BULL, 0x9437748D970971D7ULL, 0x6B54D3DF0703EECEULL, 
            0x6CB57ECC75B87E0BULL, 0xD956B1220DA03188ULL, 0xBAD6052D77A9E703ULL, 0x9E3FD24CBCC68454ULL, 
            0x8F157CF2B57D57B4ULL, 0xC4776C3B44A853A0ULL, 0x74BCDBE783A3D265ULL, 0x93A65042DA69759EULL, 
            0x34B01B12AED39065ULL, 0xE447F164B8782475ULL, 0x27CCE76EAC9D7ED8ULL, 0xFDA01C0FDC59F3A3ULL, 
            0xDA4848DF542ECA3CULL, 0xC2954714E4AF053BULL, 0x556FAF72F05E6D98ULL, 0x0CB2A2E6A9EDF59AULL, 
            0xA4BCD08C9EA9190EULL, 0x6824037175184936ULL, 0x21E79FBD1D72C376ULL, 0xE10772B86CD8B869ULL, 
            0xBFC0F95E42A3A55FULL, 0x2AB71CDD21D720A9ULL, 0xD76516FBAC7A5FA8ULL, 0xAE0C76ABE61D72C5ULL, 
            0x929BEA357F89487CULL, 0x879CE98C40264EE1ULL, 0x233BA80D32F1D44CULL, 0xE85F3A066E83163EULL
        },
        {
            0xF37F5753EC7E5447ULL, 0xD2C5F487B3C24B6EULL, 0x4AD501583EAA5085ULL, 0x648481AD3218CB19ULL, 
            0x91540AEC0577A3DFULL, 0xF80DC13D246EBF4FULL, 0x7D75110B7178A427ULL, 0xB0ABB7F9A99714E7ULL, 
            0xDC815ED25CB1A848ULL, 0x1D5BF0AD73A78D09ULL, 0x2BDB2F1CC94C7F60ULL, 0x0DB84195D3C80126ULL, 
            0x4C42D45C2A5A4829ULL, 0x6E77BA831584DC63ULL, 0x41091243EB6B4260ULL, 0xC0981952DB18FE8FULL, 
            0xB1599E006661C346ULL, 0x645A3D7FB07C6F41ULL, 0xECB300CCAD280448ULL, 0x5DF94911EF059422ULL, 
            0xC082B6A60135DA7CULL, 0x63F0B446A3B24F2BULL, 0x14A1087F49F43814ULL, 0xA36AE30E34B2161FULL, 
            0x5CD218C0E1AAFFD2ULL, 0x05097ECFE0179A2AULL, 0xDEF4303E0D0BD2DEULL, 0x2BEA2C28600860DDULL, 
            0x784EEA31B931F9F3ULL, 0x488D0A821A79E4FCULL, 0x6032219F8834F9B9ULL, 0x46CDEE08F2F549BEULL
        },
        {
            0xA75C26FD28C22E9CULL, 0xE8B40ED36629D5C7ULL, 0x1600E180CBC26F39ULL, 0xCB3CA7B7C78976F4ULL, 
            0x0F933F50AFFEABFFULL, 0xADA9D03DD8B00717ULL, 0x8A579A9977B6E4B9ULL, 0xE7DD71EDCEC11F8DULL, 
            0x530991830E91F475ULL, 0x2F4B38B409C2EE8DULL, 0x926D7238A2F4C2DCULL, 0x3B697DD71CD6E227ULL, 
            0xE8686D5ACE7D6D98ULL, 0xA8A494A2D5DF2F5CULL, 0x66F2E8286FD17EBDULL, 0x8470A9DA201A8D61ULL, 
            0x48025983C02FC7F7ULL, 0x2CFCB0AF0070BDDFULL, 0xC3137BF712F7A1B9ULL, 0xD72F4BFF10226F47ULL, 
            0x56C18FC462ABA100ULL, 0x7B4CCA8885B443C7ULL, 0xBCEFC908A7603196ULL, 0xD17D8F2A76919931ULL, 
            0xE884267246C3AB50ULL, 0x7DAD4265B8AFE76FULL, 0x53900AFED694A235ULL, 0xD54DDBE3BE72E6E6ULL, 
            0x819BA69F6824F6CFULL, 0x0C2B569E4D9DCA0CULL, 0xE3DC206B287B85FAULL, 0xA44E47A9154C2883ULL
        },
        {
            0x718D64173F8054CEULL, 0x604E7F70E1DA183AULL, 0xD65EB7D235D61F94ULL, 0xC944202E5E059DEEULL, 
            0x7D8A03C0A515CAD2ULL, 0xB02424C5AD2E93F7ULL, 0x36057C289CCD199BULL, 0xC2890D86AE06797BULL, 
            0x4E9E49821AC7983CULL, 0x7C55996430B76075ULL, 0x36DCC770635E5CFAULL, 0x6F580530BE926616ULL, 
            0xDB6AA315947BE9DBULL, 0xC7094C9AE184FE89ULL, 0x799E200286EB1AFBULL, 0x46FB076DAB7AF8E5ULL, 
            0xF6738FFEF93905B9ULL, 0x525E7E59A4754E9EULL, 0xDC19B02D82BBA328ULL, 0x43563BCB639E9967ULL, 
            0xF013CEA263D17593ULL, 0x84732F3212DCC638ULL, 0x99B9B55ACE875C65ULL, 0x111AB284DBE53828ULL, 
            0xD8563B25D992E154ULL, 0x766811947718460AULL, 0xEBE87C4F699AECD3ULL, 0xE5A8899A57E375C5ULL, 
            0xCA15BF8CDB946E96ULL, 0x1367546D0BADC1D2ULL, 0xDAABE8950E9AB5F4ULL, 0xD7841387272C9135ULL
        },
        {
            0x8945A019604CEED2ULL, 0xEF337105EC8DCFC4ULL, 0x50A400A31924ED73ULL, 0x7EEE0B2F888E1E8FULL, 
            0x6BEE5225F1141750ULL, 0x3C3BA0611F3424FDULL, 0xA9CA72CC0E6741B6ULL, 0x1112465166AA802EULL, 
            0xB2FFBE19FCFFF1D1ULL, 0x0B7E28F9B3740931ULL, 0x58D7DAE08381D274ULL, 0x517BC963CA04C917ULL, 
            0x1192FDCC6A86CA7DULL, 0x2AA0042E8BF7E5CCULL, 0xA635BBDBD8BBE79DULL, 0xE692C00A4AE0E7D4ULL, 
            0x2F2EFE54F90CF174ULL, 0xBB5B46C5D5B2DAA6ULL, 0xB74E48CBCC0E3C7CULL, 0x95518259CFD4B811ULL, 
            0x9C05741A153C4040ULL, 0xAC5299746C735F89ULL, 0x8C95EDD1D007FB9BULL, 0x1A5FC1F9AEB4456FULL, 
            0xF199DEBA21094BC4ULL, 0xDF4B766D08C96030ULL, 0xF17A5C5BBA456129ULL, 0x03CC82251DB24DDAULL, 
            0x770CD823C8DB6D8FULL, 0xF3434FA97264426AULL, 0xCA56BEE924089E0FULL, 0x2B9D86458ACA7CE7ULL
        },
        {
            0x19DD078B7C618B82ULL, 0xC93B4F9A29397B77ULL, 0xA27658D2A34669F7ULL, 0x86EDFFFB8D418243ULL, 
            0x0E7F46FC01DED191ULL, 0xF6280739F377E786ULL, 0x86DF4598353B0373ULL, 0x02434D06B2C21332ULL, 
            0x5D0632B9E1819ED2ULL, 0x23CA045BAF9C26CDULL, 0xF698BE9BB745A59AULL, 0xBC30D1B8A92BEA64ULL, 
            0x99C4152091FF68FFULL, 0x9CB498FA37F13DCAULL, 0xD1394F082E8CEBE3ULL, 0xA5468FA26B4B063FULL, 
            0xFF57A48F5C00C1CBULL, 0x4D517331558B1950ULL, 0xC40994ADC3C9FF2EULL, 0xADB1405EBC1C2E5EULL, 
            0xB9F1715F54057A67ULL, 0x4AF019E9326B4DEFULL, 0x437BCCA7D058515AULL, 0xB4B72D732C6821F2ULL, 
            0xA010709A4E317A02ULL, 0x2D86B8A0776805D0ULL, 0x54ED9205D8241BD9ULL, 0x30D031F40023913EULL, 
            0x29B58AC9184A95DDULL, 0x7C38D665C02C18C1ULL, 0x6806528FAA7D6A16ULL, 0x0734EAA390CD377CULL
        }
    },
    {
        {
            0xF0BC913428027836ULL, 0xA9F1823AFC13298EULL, 0xA3F13FA322172EFFULL, 0x10733D32DD6E50F0ULL, 
            0x646E410D686D6CA4ULL, 0x2DF395080A37C06AULL, 0x8226F65E3EBBD84EULL, 0xEA47A0E3E6F405FCULL, 
            0xD0D38318847C93E1ULL, 0x1A853665B92EBE65ULL, 0x0BD965BF43F1A110ULL, 0x7F91D472FAFC1C2DULL, 
            0x759143586DF39EC7ULL, 0xC26B3AB17C902056ULL, 0x518C8204DF526A7CULL, 0x007C62B3B599CB9CULL, 
            0x6384A80D389E4128ULL, 0xCE05D99A32A94A5CULL, 0xA75F71FD5D70A796ULL, 0x914E8065C4F882DEULL, 
            0xB38D3B42A70FE134ULL, 0x6437A2B8BC949758ULL, 0x1B1A2898294E0EB8ULL, 0xC671FCF0ECC757D3ULL, 
            0xAA8B7B7013679B63ULL, 0xCE4E3357081074D9ULL, 0xB5C2A548B7DB226EULL, 0x5C6AED2E77D9E1DBULL, 
            0xB922B44913A8F2E4ULL, 0x4B721DC93EEACCEAULL, 0xBEC0112861B5CC8EULL, 0x5348996834BB4FA8ULL
        },
        {
            0x8431BCC40D8D09F9ULL, 0xF1EC3DD975ABE812ULL, 0x9D0FEBF46E6CC275ULL, 0x6F1B829D84E6BE48ULL, 
            0x57B7FDDDB9EECAACULL, 0xF07B4128B688BDCAULL, 0x7F34CA76C2C1129BULL, 0xA3720926A572224CULL, 
            0x04901D83D8A5FB1CULL, 0xDA141E5C31420CC7ULL, 0x7DE06EB8E44EBABAULL, 0x4EEB81D8EEE80ACAULL, 
            0x3A613ABACCE687BFULL, 0xD23757909438C554ULL, 0x6F656AD21022B5B1ULL, 0x052349EBB451E75CULL, 
            0x5BF1A93AF215165AULL, 0xF120E94F758E97A9ULL, 0x7BFAE08E0FD01FCFULL, 0x53F81FFBF463508CULL, 
            0x0075E93F58798123ULL, 0xBA4BE35AE10FB8E0ULL, 0xAE576B5FEC0556A9ULL, 0x08F67B5682B07FE8ULL, 
            0x28E508D0FE2204CCULL, 0x85809A7BD4DE08DEULL, 0xE66293468C6DBA44ULL, 0xF62BC0CBA1C41EDEULL, 
            0x28D4C84D037BC861ULL, 0xCD18D5A90852A135ULL, 0xE4A7E21C9BEFE9C1ULL, 0x556BF212C5C5EBD7ULL
        },
        {
            0x6C237CCA388B75B6ULL, 0x641894B98F176B12ULL, 0x78732AAF7D2125B1ULL, 0x629129608977022EULL, 
            0xA595ABD330D5F8E9ULL, 0x1867F0B7C671C9F6ULL, 0x10E50D54A3EC5D8FULL, 0x5700391C6E1AE8DFULL, 
            0xEADCA830D485EC42ULL, 0xDDD501B5C6854088ULL, 0x32F5BA4F52011422ULL, 0x630247932DD9C31FULL, 
            0x9B7D1FE686F6938BULL, 0x4898C3AE750E44A6ULL, 0x4C2B6BC7DF0EB64CULL, 0x67EE8822E89D7F1DULL, 
            0xB99C3645F489857BULL, 0x3F2BD1A9E0CC1BD9ULL, 0x834066C30FF50E3BULL, 0x19D5BA23F0485638ULL, 
            0x7A81CDA5ACD847CAULL, 0x0989ED919323F68AULL, 0x8D496835B363D87FULL, 0xDEE3B757FC4237A4ULL, 
            0x62960F65703673D0ULL, 0xD68C8666C30AA140ULL, 0x15721EED484C6FF5ULL, 0xC713D1B7024CD37FULL, 
            0x2259E72E0A942477ULL, 0x53E87E4A98D24C07ULL, 0x29B2DACDAC7DABC7ULL, 0x098B2C1CFB42B08EULL
        },
        {
            0xEC3F39887EB323E7ULL, 0x7CDB47F6D2BABC15ULL, 0xC52C73C211F069E4ULL, 0xE07157CA7D458331ULL, 
            0x6370BEDD60411C9BULL, 0x830FAEDF5CE2B386ULL, 0xF9F6C748CD2AA6CCULL, 0x1D9C2B4BF26D1B5EULL, 
            0xB5BB819C7092E4AAULL, 0x6F102E2915BD95E7ULL, 0x1E6FF2A95C4057DDULL, 0xAC4B41F80B91E514ULL, 
            0xCB8890E884318460ULL, 0x3CD8C7981769CF7DULL, 0x26D32FBF3D344F20ULL, 0x7C453E7D03EDA82AULL, 
            0x91B86F1AB6784D9BULL, 0x864BECE34AC86641ULL, 0xCDCCEBEC3DC8ECC7ULL, 0x6B52F6E05BF8F96AULL, 
            0x2376458694071B03ULL, 0x0385CCA5A6386D39ULL, 0xB57CE5E33640DF80ULL, 0x3E59DCC802392BDFULL, 
            0xE57AABB87842DA41ULL, 0x56C96ED12C15B8A9ULL, 0x1877D9905B0720EBULL, 0xA60577383014029CULL, 
            0xE06AAF8FB1626D41ULL, 0x29F0019DD41B1189ULL, 0x06062429F650230FULL, 0xE9B0C35BF331A153ULL
        },
        {
            0x5FE3A04525D8F70BULL, 0x51C97020EE17774CULL, 0xB46497668FEE8AD9ULL, 0x738329ED12DF8607ULL, 
            0xA1601185C20E6435ULL, 0x43B810D23E57EF17ULL, 0x590592CE1D7970A3ULL, 0x3313CEADA8ED4862ULL, 
            0x8C3262D17CFE4233ULL, 0xDAA4911B1AFDF106ULL, 0xA5152AABD5770800ULL, 0x682331A7E9A67893ULL, 
            0xDD46371A442FE3E5ULL, 0x7C880F19FA0AF3BFULL, 0x09D65331B00FAE56ULL, 0x3DAC933396A11252ULL, 
            0x9F9637BF0B9000A1ULL, 0x937EFE59D6F005ACULL, 0x8033BC23A203DBC3ULL, 0x5F874CE1C67A06EFULL, 
            0x2592952BC4A3B905ULL, 0xD9CACC4A23F78BD6ULL, 0x9A40F0F16375CAFDULL, 0xE14E38615BF58909ULL, 
            0xEE799D0A8E5BB838ULL, 0x27FE77CBA745D63FULL, 0xA05668E77C5A85BFULL, 0xF62499007D7A134BULL, 
            0x79FDC30513C0E67CULL, 0x80E001B55D598083ULL, 0xC86CAA8E92E5DCFFULL, 0xCE3DC2603D859E7CULL
        },
        {
            0x08D843141FBB1827ULL, 0x14299DBFCC4541B5ULL, 0x429119BD212BB3A1ULL, 0x24775A659F5F7D98ULL, 
            0x9050D647C39EC587ULL, 0xFF739156AE464941ULL, 0x5DDBE47AC1ED3536ULL, 0x9A2FDF99FB7FD407ULL, 
            0x7D284FDD71812F61ULL, 0xD9FD35D02AB89DF2ULL, 0xB6F0B5520EC7FFABULL, 0x093C2F504DBC3090ULL, 
            0xF1E16680489BA737ULL, 0x455DC8B1823611DDULL, 0x5B4B215A2FCF6943ULL, 0x64EF701F8E786539ULL, 
            0x9AC8E47456700C5CULL, 0xE16DD0486617699BULL, 0x929A754DC5420840ULL, 0xC666306A1FE1551EULL, 
            0xD39D248E0A51213CULL, 0x38914A267124F0BCULL, 0x23EBA34766E24AFEULL, 0xFFA8AB1A7D89D4A2ULL, 
            0x632E52C8088455A1ULL, 0x8AF8106E81B725F1ULL, 0x56EB2DD40E4BAC7DULL, 0x9307808ED4FCEBE9ULL, 
            0x46911D1D3E341FFCULL, 0x5555AB8DB81E02B8ULL, 0x40BC460E99F3DA1BULL, 0x4513A3D41DCDF837ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Softball::kPhaseEConstants = {
    0x8A9194FA727EA1EAULL,
    0xDF1B35B5CC0BB438ULL,
    0xBA937CC97EA2E8A8ULL,
    0x8A9194FA727EA1EAULL,
    0xDF1B35B5CC0BB438ULL,
    0xBA937CC97EA2E8A8ULL,
    0x1EDE63B7CA7A51A6ULL,
    0x5ECF110B66504B3FULL,
    0x3D,
    0x0C,
    0xF8,
    0x66,
    0xB4,
    0x0D,
    0xAA,
    0xB4
};

const TwistDomainSaltSet TwistExpander_Softball::kPhaseFSalts = {
    {
        {
            0x5237FD965F413BBDULL, 0x958730954C6E46AAULL, 0x97B1F64F01442F5FULL, 0xF059BC87B32BFE41ULL, 
            0x3AECAA10F9896BC7ULL, 0x66EF459681E383DBULL, 0xEB3275E55DFC17A7ULL, 0xB1523689028CB48BULL, 
            0xCB721C1E457604FCULL, 0xAE65A424396CDF43ULL, 0x0583D6E212C42C55ULL, 0x4C9DBC7133E08BB6ULL, 
            0xF258CBD1519388F2ULL, 0x207C0FEE02B02E04ULL, 0x7B5D40CEE2168990ULL, 0x09A47D060458D892ULL, 
            0x20B8BE97A2D1FD1FULL, 0xBE9AA60CC16A2F1EULL, 0x21F17E431B8E3DFEULL, 0x7F6AA70C57F1BACCULL, 
            0xC9AD27A1A2AF8C27ULL, 0xED7D5EA76DB09588ULL, 0x56ECFD3C8A2A575BULL, 0x6D34FE3E6C2FD28EULL, 
            0xFAA53581AD71EF06ULL, 0x3D4991C956A39F0CULL, 0xC0674FAFCEE6A3FEULL, 0x838E4C07A3ACA975ULL, 
            0x5B23DD5A37B38391ULL, 0xF2171818294FEF9EULL, 0xB8187F23DB29096FULL, 0x700317C567A2EDEBULL
        },
        {
            0xF044CAA6DD59E3BDULL, 0x229BDEE2A8997B64ULL, 0x03C43CF77E08E29BULL, 0x8719CFF0F650786EULL, 
            0x4145448788DFBE84ULL, 0xA2AE72CB320899EFULL, 0x465870A915B334F5ULL, 0xD6B3CA1A2E95F763ULL, 
            0x8C1AC522D9E7C486ULL, 0xEC5BBCF583E00934ULL, 0x12933CE30C517CF2ULL, 0xB6F9C79C01059BD5ULL, 
            0x54035B44583AE027ULL, 0xB678F96AA89A1BE9ULL, 0xE81C3D3D24D6633CULL, 0xC0A362FFFFBDD567ULL, 
            0xE6D8059FD4A94063ULL, 0xA96A29976130C898ULL, 0xA780DB20AB51BB05ULL, 0x9B0971273664DAECULL, 
            0x33DB21520CFFA1ADULL, 0x0675C4BCE22587C8ULL, 0xAB44C3A39393E62CULL, 0x3910F5A191B89E7EULL, 
            0x2D7F4E131B43783CULL, 0x688960F1C3D08BCFULL, 0xD6E9469BCFD0B1A3ULL, 0x14239A35B4AE00A0ULL, 
            0x6DADFFD776AD5117ULL, 0x2404623FE87413BCULL, 0x86DB799C7102EAA1ULL, 0xBE9BA54DC1819192ULL
        },
        {
            0x4E99DD4AFA07D48BULL, 0x0449FD9F7AEB629EULL, 0x466765BB3FA14A68ULL, 0x8F79372D03E9310AULL, 
            0x71672D207FCC9BC4ULL, 0xD49FB6288AADA38DULL, 0x74C77D181ABC7D53ULL, 0xF56D004348F827DAULL, 
            0xFAD85F8BD948FC67ULL, 0x1AEC386E00E992C6ULL, 0x3DF7B411115B4EF1ULL, 0x7D5E3FC4A6E90AB3ULL, 
            0x7C5909DC079CBA1AULL, 0xA03BB713DCB6A93BULL, 0xC8099E9FC0409888ULL, 0x19528C730B77A4C1ULL, 
            0xD3C45832D20B9B76ULL, 0x4A36D46F76BE7DC4ULL, 0xB10584679C5A6946ULL, 0x44948D88550797F6ULL, 
            0x7FA9BAE8A3568A08ULL, 0x512FC88A31F9132AULL, 0x57FF9B37C358074CULL, 0x2347D70947822A15ULL, 
            0xB3DF7E3A4877D9ABULL, 0x2C6EFD063220A209ULL, 0x32FED2340742F41FULL, 0x42852F419FB1A1C4ULL, 
            0x900FB49DA6DA7797ULL, 0x8918BD03EF582C76ULL, 0x4C1854F24851A5BEULL, 0x312A6BBD615D0947ULL
        },
        {
            0x45776341DE88659FULL, 0x76F0DD47486C0AF8ULL, 0x9287A0A909A9183CULL, 0xE1BAC563E2CC355CULL, 
            0xD5102304AC6C4239ULL, 0x68E1058FC66F4B7AULL, 0xE91BFC00ECB20500ULL, 0xE005DF1D70FBD0E7ULL, 
            0xA3AFF7649D13A407ULL, 0x768E814186328751ULL, 0xA8BB11C10DB6C527ULL, 0x7AFED6232FA2FCFEULL, 
            0x185A321B6A66AEF6ULL, 0x8CF075EA167F9ECAULL, 0x354E4BCBD5D2BFC4ULL, 0x4DC338CB5CFABE54ULL, 
            0x29D93CBAD75E13E8ULL, 0x8E0D5213B73556D9ULL, 0x10F9D054D531D161ULL, 0x5024E376A6AB3C35ULL, 
            0x77EDE466DF9BD256ULL, 0xB7E91D881A5CEE17ULL, 0xAF3C914D1AA25179ULL, 0x387EB4AE41E36BD4ULL, 
            0x894D6B5BE0B727E3ULL, 0xC6D8D91CA55D9E97ULL, 0x699344A06C18B89EULL, 0xFC3DF4C478B0D868ULL, 
            0xBC61AFAF436CC2C3ULL, 0xCD1785023C825CE4ULL, 0x691FD9D170C4B4EFULL, 0xA8D4DAF4B03A15ACULL
        },
        {
            0x868568CB050CBB1CULL, 0xB562C9B71C931924ULL, 0xD1BC2363359D8D6DULL, 0x2BA4B6972887DC9AULL, 
            0x2A23FECB2137C925ULL, 0x7EBF090A7037FF5BULL, 0x97DF4CAB543B68D1ULL, 0x1587FDDCB299FC5EULL, 
            0x832F054104CF2773ULL, 0xA4255BB0D6D37EE8ULL, 0xE80EA8F293EDBA8EULL, 0x22E9EBA4205B7252ULL, 
            0xEB60D294DD07E1BCULL, 0xF4128B46F57A947DULL, 0xC4592341C9C295EBULL, 0x6A1150478CB520EEULL, 
            0xA5273278139C0000ULL, 0xB2CE11588A9CD56BULL, 0x53AAC2D91D6D9DCBULL, 0xAFAEC2A0308D059CULL, 
            0x2207A67D25E26ECCULL, 0xA5F30153FB363ECEULL, 0xE9526314266051ACULL, 0xC77B8183CF05C84DULL, 
            0xEC13080A8A07E4D2ULL, 0x20EFFF04F0E3C951ULL, 0x0A54CB7F778BF444ULL, 0x3359D6293D73CE61ULL, 
            0xA9FC8F65648E92E6ULL, 0x8C14F56F25171B26ULL, 0xD6165360F5A35404ULL, 0xF93EE2215E272441ULL
        },
        {
            0x8E5A0CE72D30E7A4ULL, 0x76FA386A87CC4582ULL, 0x19A64F98024AB88DULL, 0xD963ECA1BFCF7341ULL, 
            0xD54976ECC2ACD281ULL, 0xF9C55E6A16695632ULL, 0x1AFDB0F7E811D8DDULL, 0x5F6E6D489DEC92EDULL, 
            0x46E44847DEC8FDA2ULL, 0x8AF1E307CF54B4E0ULL, 0x4D70F3999D51DA7CULL, 0xBDF131D674B5BFE6ULL, 
            0xCB5E06ECC6499F56ULL, 0xD8A59A32A0A5B09AULL, 0xCF5F2C514C63B602ULL, 0x65D5B648BB455920ULL, 
            0xA7412AA5F5520ACDULL, 0xDA52995408E9EC92ULL, 0x15FD5E7E74A92AC3ULL, 0x6565471B841B4E91ULL, 
            0xFB934255ADBAD4D3ULL, 0xDB6F64DEB5EEA1BAULL, 0x850EAB63557937C9ULL, 0x279E069A5B942E4EULL, 
            0x9FAB76F47C875709ULL, 0x8237AE903067DC41ULL, 0x9F2E3E48A32326DEULL, 0xE36C6A9AA58BE00AULL, 
            0x702B81A00F9AA28CULL, 0x4F8FE0479C97A6D2ULL, 0x2F5E0F3A6B429549ULL, 0xB5AE1E538CC8D84FULL
        }
    },
    {
        {
            0x131ED98D7EB0CA8FULL, 0x55DF1A99764401BCULL, 0x269EA4A5B8D987C0ULL, 0x32ABF75B3AB16C84ULL, 
            0x2C60E6C88638B8D3ULL, 0xCD9757E8EF410886ULL, 0xF59A237332D348C1ULL, 0xBF1459C62B79F3DAULL, 
            0xCE12FD223D6F8069ULL, 0x218F174F1B644E6DULL, 0xE878051C772C5DEFULL, 0x7015CBF7A30A92B2ULL, 
            0x52841CF001730935ULL, 0x68A5D938A735D199ULL, 0xD98B1F35DE2DE29FULL, 0xAA06A23D5FAB1716ULL, 
            0x28573A6F557B5CC9ULL, 0x5C42E8AA2461D32BULL, 0xC31D922C98113063ULL, 0x95BDE77DEFCFF7E2ULL, 
            0x1F348AA625722DC3ULL, 0x6D1646D8E4C45561ULL, 0xC427E89D2A0B8F1FULL, 0xD4D9CF49FE8263A9ULL, 
            0x0E9C950907E4D063ULL, 0x7C9115B3F8B0F6A6ULL, 0xAC0BF350A2C96E5EULL, 0x8EE510E7553B3748ULL, 
            0xDA87EA7283937152ULL, 0x946663A8B470FB58ULL, 0x3495A58ED81BA760ULL, 0x4DA200CDB47D013AULL
        },
        {
            0x12BBB61300AD65B2ULL, 0xD5268452860D0F85ULL, 0x30D51B4B2121F557ULL, 0xD08506DEF8D13AC1ULL, 
            0x9C33D79D0B054363ULL, 0xD493CAA470390BC9ULL, 0x9DC6CF99D26BC933ULL, 0x5C85236F502A766DULL, 
            0x2C269D5D8EB260D4ULL, 0xCF7131C90169423CULL, 0xE69D18A778651558ULL, 0xEBA8EF8666CF0816ULL, 
            0x7F2BE7F21D6EB382ULL, 0x3C18A5A8553D9873ULL, 0xC21BA3453F0915AEULL, 0x8AF169C5CC9868F3ULL, 
            0x1DF4784791132861ULL, 0xE3D2EB2336C69D82ULL, 0x124B19D2390F6782ULL, 0x4C42F32DF4749166ULL, 
            0x637E3BE423B82C6DULL, 0x1294BB80893EB258ULL, 0xF2245E5ED023BED1ULL, 0xCD80DE571AC88469ULL, 
            0xDC49533C0AE8F738ULL, 0x6D4FBCC654C71479ULL, 0xD8B5D4CB79D2F714ULL, 0xF8A3995454C86738ULL, 
            0x4A571A485D06BE01ULL, 0x4F8526D47894154CULL, 0xC2FF2A42AB1D99E7ULL, 0xCB9B91A29193FDF6ULL
        },
        {
            0xED79BD68A28157EEULL, 0x4FD9CD9EB18F2DBCULL, 0x752E4C451B4E444EULL, 0x68F217847850483EULL, 
            0x4A579CD0E288A35BULL, 0x751B484B35C67692ULL, 0xBB7B488D41258C00ULL, 0x7E61273D2458A532ULL, 
            0xB29210325AA6CAD1ULL, 0x59CE1CA30C70F2F3ULL, 0xB4F6F914BA4E8E49ULL, 0xAD72CE1DEC1AE110ULL, 
            0xB113058AB75252D6ULL, 0x295B191CB373B38CULL, 0x9DE6998D8C76A0BDULL, 0xB794CB1040876D4AULL, 
            0x5FCDBE8F5566697CULL, 0xC72372445C4428EDULL, 0x1BAF094B9C2CCD8EULL, 0x52EFAFFD3E6ECEE9ULL, 
            0x3D5E2EBDB96ED080ULL, 0x45C1DF1B72DB0504ULL, 0x8C3F6108720ECF95ULL, 0x172A144B33F48C07ULL, 
            0xF70E4DC36F51B3F2ULL, 0x284BC7932B876D71ULL, 0x19A7F499F6045E02ULL, 0x9B5E6A4E65809FE6ULL, 
            0x8909BB4E8A35DD17ULL, 0x244CD251FF1C5867ULL, 0x0CDBB458527F0BF0ULL, 0xBD8DDFC7F044176CULL
        },
        {
            0x6DC3381D27403CF8ULL, 0xD248A6E4DAA88E94ULL, 0x2A942C001A9EB229ULL, 0x77BBFE7811A55FD1ULL, 
            0xE917B0C1F2A2E0AFULL, 0x69F1190A479D5DABULL, 0xEAF4200551465A25ULL, 0x1D39C63486543BA5ULL, 
            0xE517B8F021EC67E4ULL, 0xBD88E718B0F8422EULL, 0x83AEDE3058A9266FULL, 0xEC254447E11D0F0FULL, 
            0x88F272315C25605DULL, 0x21A061D41DBCE539ULL, 0xE3EBC8149531DDCEULL, 0x4B88A4CDB88B87CAULL, 
            0xD1B71B06F1CF97DFULL, 0x7014AE0B0B33BE5FULL, 0x70095BAD1361FADBULL, 0x556DB75333E5C51BULL, 
            0xB6D190B0E977188EULL, 0x57FE53515BB51088ULL, 0xCD5CF1EAA3F46AD7ULL, 0x6D2E564EB695E1EDULL, 
            0x2FDB8E5B67366389ULL, 0x719B4EAB0C2523BEULL, 0x557D34A9FAE9CC96ULL, 0x804CC1251B47EFBAULL, 
            0x3C5F82B8B74BA578ULL, 0xBBB06B27BCE59C96ULL, 0xA6EC89886FEFA745ULL, 0x29E89595A2D34624ULL
        },
        {
            0x57C754F1D55E4E61ULL, 0x669C71721C9B8F75ULL, 0xD35113DA4440A7B1ULL, 0x5AA490F95E3034FFULL, 
            0x903A56BD97B30575ULL, 0x169E6B0B54935CF6ULL, 0x4E5F0763FD72277CULL, 0xBBD7D488FCE5E33BULL, 
            0xA74CA5F054203923ULL, 0xCD1247BFDC3D5156ULL, 0xEBA5C520B7608523ULL, 0x74BD8C2E21F8CF7FULL, 
            0xA0B63366F1BCA45EULL, 0x9D69F14D5EF83F73ULL, 0x38944146853DF64FULL, 0xD81A3C76A3EE33E1ULL, 
            0xA3E6AA20823928EBULL, 0x9E2BB2C0DDC6436AULL, 0xEF9AF70F83CB5C5DULL, 0x0B9C11D5920A28EDULL, 
            0x66CBB59764FB087BULL, 0x9D00D259E1B86824ULL, 0xD6CE13F5FE87B83FULL, 0x2DF42BA7BFA5AE99ULL, 
            0xBBE091665520B36EULL, 0x62BCD46FB65F89B8ULL, 0x8C0F362A8849C88AULL, 0x96EF4BFA397A40D9ULL, 
            0x3CCA2712EC9ACC68ULL, 0x0E499D0E10F3E044ULL, 0x8D2EF26AEA4EC94FULL, 0x55D5D68A05FDD58AULL
        },
        {
            0xD81B0C32D36DADDCULL, 0x0E70D5EC9D9E87E5ULL, 0x179E20E9C8752285ULL, 0xF56EB97ED97A7668ULL, 
            0xB145A78CD3B18D3AULL, 0x164B65C77306D0E0ULL, 0x394C1A8C778E17CCULL, 0xCB64300388072AB7ULL, 
            0x58275B26636C987FULL, 0x6A834AEB6AABAF92ULL, 0x6492232A54A7D87EULL, 0x513ABE16AA79EF85ULL, 
            0x88DF6A5F89EE1C59ULL, 0xCA5AEFD234679EADULL, 0x27BAA1222F173848ULL, 0xCE254DB6FBDEE80AULL, 
            0xA90A6C84D704F0CDULL, 0x5EF78CB9BF0E4512ULL, 0x1B7898D255F5AF2AULL, 0x5503D3D9CF700274ULL, 
            0xD1A50DD740A15BD5ULL, 0x95987D198539A8A4ULL, 0xDA99C1AA883E4EC2ULL, 0xF0EB441ED82FEFD2ULL, 
            0xE2D8828C2C3B3F40ULL, 0xBF9603894F27946BULL, 0xD0F0699187117F2EULL, 0x409100AF1CECEFADULL, 
            0x6B694E82BC1A8A33ULL, 0x1D5AC614BAAB3A02ULL, 0x2986FAD606B039ADULL, 0x4A5EBC89B5FD64A4ULL
        }
    },
    {
        {
            0x44DFB1D35214C5A3ULL, 0xB324345245362006ULL, 0xE55899C3EDBB77BBULL, 0x1A321C7ED45A1CF9ULL, 
            0x484D1120359AA852ULL, 0xC0A7442169C35BD0ULL, 0x8837A9CABF2BBD90ULL, 0xC851EB8144A8241EULL, 
            0x70AE67CD418B0F2EULL, 0x9B66A7B30A1F159AULL, 0xAAF314819F345F15ULL, 0xE4EC242777FE9F98ULL, 
            0xAAD82ADA9799EC9DULL, 0xC6A67D3E91338185ULL, 0x85EDB6DB5E08457CULL, 0xFB87CAE53E6804F9ULL, 
            0x7E4D9E6D43B2201BULL, 0xF3229759F3F9844EULL, 0xFC06C4472A0AF728ULL, 0x2D774C2EAB058BBCULL, 
            0x289463149633CA6EULL, 0x5FB18C6F480961DCULL, 0x2D641C3D0841C805ULL, 0x242ACFB5E05B7AA6ULL, 
            0xA511A4FB78458004ULL, 0xEF93D22BC452C602ULL, 0x5CF9D6E5880D1197ULL, 0x9AA0C0C4CEBD1744ULL, 
            0x0EE3B5455BDF4BB8ULL, 0xB39B3E592BAB7597ULL, 0xEEEC5C37A5BBA65CULL, 0x7C89200F72CBBE2CULL
        },
        {
            0x4DE59F6511E51168ULL, 0x881D7BE221D552CEULL, 0x659D82BCB447DAD9ULL, 0x5553CB4A3F0F8C28ULL, 
            0xE34DA72ED5B0BA65ULL, 0x06ADA89B3F01FD91ULL, 0xCF0F2F98C361C824ULL, 0x9446F44AE945C929ULL, 
            0xAE0F775174143889ULL, 0xBF2AF0BF3C16C9EEULL, 0x0682A6C7DE5D686AULL, 0x0FA0288596A7FCCEULL, 
            0x19B6D677CAC002DFULL, 0xC78936DDFD6FC893ULL, 0xFAF68B24E67704B4ULL, 0xAF51DA1F4DE0CF15ULL, 
            0x565EFAC767BE14EEULL, 0xA18BE6E2C60E2504ULL, 0x7EC7752591B87071ULL, 0x52448DAD592F26E4ULL, 
            0xF5A9B5A2E25624CEULL, 0x00C5B98E621B0FF1ULL, 0x49FAB15301D23925ULL, 0xC59997E490F9D781ULL, 
            0x7C34FD7FF00351CFULL, 0x3543B8F58AEE3BDAULL, 0x0581EE13CE438558ULL, 0xED0E837BAC222A12ULL, 
            0x0C7A5A132EDD5E80ULL, 0xFA2B916E142BA45AULL, 0x8C5347F5B621B68CULL, 0x7B42E36708D335ECULL
        },
        {
            0xE1007A73C09C974FULL, 0xE976C7E9DF2C7808ULL, 0x900F5E0051F6292CULL, 0x9EE3006B6D5CC614ULL, 
            0xCA49C9B9AB10950AULL, 0xD197645D910BA87DULL, 0x42045ACB24DABC76ULL, 0xE10263EE7C1BE495ULL, 
            0xA584783472431AFAULL, 0x63887B45C4A3E0E2ULL, 0x79F875A83C7850EBULL, 0x273ACCF7CA7D28F9ULL, 
            0x1AE67B560B1DEF95ULL, 0xFA2B8291B0801E79ULL, 0x1AEAA271B7F8ECE5ULL, 0x9C593F6B7F664B60ULL, 
            0xDC653BCBAFC54AD4ULL, 0x92E71A2E278D30C2ULL, 0xE7E58D21765B7D6AULL, 0xF2C8A7672444A636ULL, 
            0x866D0F71EBDAB1C5ULL, 0xB79ECF44DA6B8767ULL, 0xD2AEBFD830F540B7ULL, 0xCA67D4B2A51013EDULL, 
            0xF40F1FD61A5A1B26ULL, 0xB874329E685D6C42ULL, 0xCA2A940A792B1E4FULL, 0x2977090E8064D85BULL, 
            0x15262AD4568EFEFBULL, 0x96E305BB4E5427CEULL, 0xD2584655320139DDULL, 0x030F3DA58E02BB34ULL
        },
        {
            0x93C1B58126C89327ULL, 0x531F2C852EA34DBBULL, 0x6BD7F88226F77AB3ULL, 0x42413B9E87CE8A4CULL, 
            0x745C32FE1AD556CBULL, 0xBB2BDF3634A1E032ULL, 0xEFA9D5583F84EB22ULL, 0xC1861BB94EB11310ULL, 
            0x20E4CA625B41D3DFULL, 0x5C8CE471FA4E31BEULL, 0x51D12844FF5C2BC5ULL, 0xFDB09967688AB10EULL, 
            0x63A8A28D58E94458ULL, 0xE32B83D46EB14B98ULL, 0xCACF0D2E0F4F510EULL, 0x11D73841210FA83BULL, 
            0x901C61F284F619A8ULL, 0x89A0E9EE28A1B89DULL, 0x8F7C903E6CA2EDB1ULL, 0x1791A55B3DD0680CULL, 
            0xBC97B7FF00A1806EULL, 0x10EB72C8DFA53727ULL, 0x3F5C0BD334652C01ULL, 0xB9C2E8B6A9F1C411ULL, 
            0x441BBE5FF23B4B71ULL, 0xBAB6D0A3951DCE08ULL, 0x48E253290B0637CCULL, 0x57A5FF147E93B497ULL, 
            0x4EBEAAF89D8A806EULL, 0x698D7A16AEB929C6ULL, 0x9613403EA75FF1BEULL, 0x69CD7C1F9170EF04ULL
        },
        {
            0x6A60D6C6D2FC9107ULL, 0xF6B807058D42D689ULL, 0x07F2FE37A7C51C02ULL, 0x98B9F61C1F30EAF3ULL, 
            0x7B9DBC2612B48250ULL, 0xB5657394F22BC6BEULL, 0x0E2F07069FF8BAFBULL, 0x0684CD6E1ADC65EBULL, 
            0x86478E926B619567ULL, 0x6472EFE16FD183F6ULL, 0xD726E61FE9D505CCULL, 0x6DEBAD075D0C84B9ULL, 
            0x564024B93E38C073ULL, 0x9AE0BA307F4596F9ULL, 0x828BDC43AA6B3364ULL, 0x8F84810CFA1617C4ULL, 
            0x146F6EC824991730ULL, 0x8B88011D67BB4C53ULL, 0xC73187D200FFEF32ULL, 0x1E051A5EFCF12DC5ULL, 
            0xEA160CB248AA4D51ULL, 0xC5E0F803F144996FULL, 0x80653DD20E6E3A68ULL, 0x2AEBA00CADC3B4BAULL, 
            0x27B8B941748A788CULL, 0x65482A49884F50BDULL, 0x616D3D80F27C50EAULL, 0x8092B17A206C384CULL, 
            0x9362E3F6A2BBC8D6ULL, 0xC83C5E48B45E269BULL, 0xB4BD3B8AF194E145ULL, 0x5FBEDDFDF83E7438ULL
        },
        {
            0xA510CCEEB0D64F03ULL, 0x16D00DC3F84E4A43ULL, 0x1008DCAF418A0003ULL, 0x9E0EA172994984CCULL, 
            0x8CA6FD386D031690ULL, 0xBABF18F9FBCB0B21ULL, 0xAB11CE4513734D61ULL, 0xFBA23C93A9E3E399ULL, 
            0x504C57ABFA6E776FULL, 0x9A6C69C8628FC53EULL, 0xEA4681145E9CAC11ULL, 0x97EA56D125F6D3E1ULL, 
            0x2B3CFF35ECFCA963ULL, 0xECAD603D31176DA2ULL, 0xBEB51758650A3C39ULL, 0x3DB7FE02FF1678CDULL, 
            0x077ED41225720F08ULL, 0x923F8B93E3E3CFB4ULL, 0x617D482C5B3A7AE5ULL, 0x79547D474920980CULL, 
            0x2F10E677870A22A6ULL, 0xC65D23E013C99661ULL, 0x046E600DFCE4AA27ULL, 0x25849D513F6F64E8ULL, 
            0x38767A383B0443E3ULL, 0xC23137986AB67663ULL, 0x0BBBDF3C97E5F5C3ULL, 0xE1F1463969463502ULL, 
            0xFC65C20BA2FE7BA5ULL, 0x8BB79A13E259B942ULL, 0xE37C090067FEAF5AULL, 0xB52C11E9E02B3811ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Softball::kPhaseFConstants = {
    0xF80356102AF19B28ULL,
    0xA542E431C0B059ABULL,
    0x715D8BF77A8C555BULL,
    0xF80356102AF19B28ULL,
    0xA542E431C0B059ABULL,
    0x715D8BF77A8C555BULL,
    0x011635BD700D371FULL,
    0x9EF6D61483E887D2ULL,
    0xC4,
    0x66,
    0x29,
    0xCE,
    0x33,
    0xC5,
    0x58,
    0x77
};

const TwistDomainSaltSet TwistExpander_Softball::kPhaseGSalts = {
    {
        {
            0x146897CE38AB2BB8ULL, 0x7D39EDAD3C33A83FULL, 0x3140B8AF1F53334CULL, 0xE36CCDB8166A606AULL, 
            0x657759937E3ADC73ULL, 0x7BD2C8B628BDED38ULL, 0x92E685FFF2164458ULL, 0xFBD25136AAC39639ULL, 
            0x62188F75336EFF54ULL, 0xD8FFAF39559DCE57ULL, 0x43680CA10AA6ED1AULL, 0x95A7879494E3FD24ULL, 
            0x0D332A43AA6D52A6ULL, 0x1F2793E5CF7270FCULL, 0x6E8536B9167ABDBFULL, 0x19FB263D1E6D339AULL, 
            0x5C72F084A213A087ULL, 0xD2DA86787FE30EF6ULL, 0x40F54BECC9431515ULL, 0x9FF53F9AA0A4AF0CULL, 
            0x124A44D19C003EF7ULL, 0x46D82A16AB5C290EULL, 0x25669988F81FA337ULL, 0x2DD5F36CB8BCE7E0ULL, 
            0x8CBFBE630EB0C0BAULL, 0x810223D0A1B2BDB4ULL, 0x88E9E52B4FA8C49EULL, 0x0146CCF52AF75A62ULL, 
            0x49D3FF38B682624CULL, 0x3BAAB694CD755AB1ULL, 0x4DBADBF9C880C5B3ULL, 0x25E744D18444C6DCULL
        },
        {
            0x601A8E7608B60642ULL, 0xEE647CFC5FD49F6CULL, 0x35FD48FF62EEC82EULL, 0x6115934C7E73E3C0ULL, 
            0xCCC96CD0D98DD68AULL, 0x165A43CF942486DBULL, 0x08EB7EED6F54ED6AULL, 0x2B08ACD4A08F8FE6ULL, 
            0xD20AAC468B89C2F0ULL, 0x2E4097C5C66B3B81ULL, 0x0BCD1B38EF4CE525ULL, 0x2A386B0A27871B24ULL, 
            0x3F12AACE3F60E556ULL, 0x56E9F492BAFB3AC4ULL, 0x33B540FA070E9460ULL, 0xFAEBF2F028239FD1ULL, 
            0xDCF582BE4C8947BEULL, 0xE18241B8B1BF60F2ULL, 0x2EE3B3E0CDE33FCEULL, 0xAF5A09BB9BA95C5AULL, 
            0xAE43525194B08B85ULL, 0xD66F1415CD3704DAULL, 0x2400069FD82C705EULL, 0x95F21A424085432AULL, 
            0xA259448ED4BEA2B7ULL, 0xEBCBF0AEDAC1015DULL, 0x27C63AB6A3C14830ULL, 0x9CA7A3A3D58D3F9EULL, 
            0xEFA521A3D722D24EULL, 0x0D1480492BDD2F42ULL, 0x7F127CE7819E9B4CULL, 0xABB7A990E7979A09ULL
        },
        {
            0x4D77ADA1DE78D0CFULL, 0x844B16DB5CD4FF55ULL, 0x10C2CBD433E5802BULL, 0x4D5024363E869047ULL, 
            0x48EE52EE4D4BA676ULL, 0x82C6AD6375B80A4AULL, 0x0A14BF7C4D91DC75ULL, 0xC7D168EC0EE59D87ULL, 
            0x78364F23CC9659F2ULL, 0x2FAF88F545B9B7B4ULL, 0x1BC5BD2CD3E942F1ULL, 0x42469D0564BAA4CDULL, 
            0xEFF97E33D897E388ULL, 0x1EB9A84C68A3E347ULL, 0xD9E5AD733A6FFE4EULL, 0x9FA78D362E0A1304ULL, 
            0x8F339607C41C5FB1ULL, 0xC68FCD52350DE736ULL, 0x20BBE405C7650E25ULL, 0x0624617B09FDAEDDULL, 
            0x5462D9A65E5646EFULL, 0x78672D4521D50B16ULL, 0xC1C95FB0F3C94033ULL, 0x39492221983E05F4ULL, 
            0xBC885DD1414D4236ULL, 0x9711B12D0505F80EULL, 0x74C2C44A59122C8CULL, 0xAE250171BB384664ULL, 
            0x87663F4219237888ULL, 0x273E68167591DEA3ULL, 0x63D5F495A2B9076FULL, 0x2E858F61DD206C58ULL
        },
        {
            0x488CFD43DA3A1B86ULL, 0x878D82DE64815C0EULL, 0x26CD6743935E5009ULL, 0x6F6579CB3CE82139ULL, 
            0x16ABC2F46C81439EULL, 0xBA7E61E6B16AB28FULL, 0xE05F3E5816A13AFFULL, 0x374AA3C1B233448BULL, 
            0x82F3B67B411FAE1BULL, 0x6CE5B0D2EBBCC335ULL, 0xDFD3DD97EC8BDABFULL, 0x0D0F056FA8EB2B9AULL, 
            0xAF19CB24EA72C4F5ULL, 0x8532DE50AFBFD9FBULL, 0xFBB1C15E6A193D35ULL, 0xA6BBF9D89216A723ULL, 
            0x0105DA7C81A3D0B1ULL, 0x35D90A2ED0BE73F1ULL, 0x9F94C6C838250340ULL, 0xE99CC57CE6E1982BULL, 
            0x94E7EBAF20861CBFULL, 0xD96A0041F64F5F8CULL, 0xEB8FB97F0A07B1C6ULL, 0x76E141CA4E21673CULL, 
            0x41D2155A612497A2ULL, 0x602EC63199ADEE5BULL, 0xF593A9F0EFE7F4DEULL, 0xE7E62BA523B3B86AULL, 
            0xBF45CB22FFADE210ULL, 0x7A5E9DF70A8994AEULL, 0x1B53BE2CFFBDB0E0ULL, 0x938E172AFFB08471ULL
        },
        {
            0xA04522E202E7D6FFULL, 0x56A5B88CACB4A153ULL, 0xF0BFD20161C5E6B5ULL, 0x9378AB9B4400D59FULL, 
            0x68F463AA28A33D34ULL, 0xD0BDFE06ABACB664ULL, 0x619D707F85392576ULL, 0x2FF0CB734C305D8DULL, 
            0xECD5368254F5CD38ULL, 0x6C439B305FB63A1FULL, 0xEE5B2CDEA2CD9155ULL, 0x3DB61A00C50256BCULL, 
            0x1543279114E452B9ULL, 0x01B7A027A213283EULL, 0xA8F822B40BF54804ULL, 0xCB0A981CC7D5B7DAULL, 
            0xD27DABEBCF585E97ULL, 0x6FCFB28D20C5377BULL, 0xC770263A55A96CD0ULL, 0x3D0BE4E29C878203ULL, 
            0x46CBCF308EA28E9DULL, 0xA90AE301E10DD0E1ULL, 0x3BFC089FF40A5C5DULL, 0x7C5E3BA4C32E5636ULL, 
            0x583A61F7B5D49C85ULL, 0xACDB200CA11CE647ULL, 0xE7347791F3600320ULL, 0xB91E7A3D04AC5E8AULL, 
            0x836DC9D31A055410ULL, 0xE2EBB4E657A13B73ULL, 0x8E581A287099487BULL, 0x038E6D954C7767B2ULL
        },
        {
            0x8770779E6EE57708ULL, 0x692E4EEAC736D187ULL, 0x7EC4C6D09C624611ULL, 0xD1FC1807D791844FULL, 
            0x6FA1E7A43039FD59ULL, 0x8C3804DA5DC6BD41ULL, 0x50C55E7D6A27A0AAULL, 0xA8BAAB2D781CE4D4ULL, 
            0xCC034F4782FA6CBCULL, 0xC764A252605DBE5AULL, 0xA0935905CD8337A7ULL, 0x1AE3EDEDE5B2B5F4ULL, 
            0x7C97D686BE8DEAB9ULL, 0x2EAE5A855D99695DULL, 0x5CAB5D63AC9B5C51ULL, 0x0CD6A9156CE34FDEULL, 
            0x9E9CBC039A7DE234ULL, 0x63FF2078270D376FULL, 0xB710A18AF7F84739ULL, 0x9669A86808890FCDULL, 
            0x8C7C8A246CD9DC55ULL, 0x41FF98E02DD09244ULL, 0x0E232566B44FD087ULL, 0xC08BC596B151B14AULL, 
            0x44D2D8DCAFF0306EULL, 0x71538EC58CCFD01DULL, 0xFA05F08C66B39393ULL, 0x9C2F457FA367A4ABULL, 
            0xD0A0E9447D08369FULL, 0x65646F5B91DC973AULL, 0xAED88D9325B99FF4ULL, 0x6FE9D5D5AAB5438FULL
        }
    },
    {
        {
            0x6D5BFB886565B337ULL, 0x22C6863CFDD93485ULL, 0xA2B46B151E596430ULL, 0x0E60102CB1E077ACULL, 
            0xBC75CC7D35F9E123ULL, 0xA80DA2F8E5DD8D0EULL, 0x72316A18D558AC69ULL, 0x88AC8A9ACEA985B1ULL, 
            0x033C511260B70E89ULL, 0xBAB224158DB456EAULL, 0x53E86D788F2B05BEULL, 0x021046C9F472DCD2ULL, 
            0x561C7D7F655381EFULL, 0x012603E348684514ULL, 0x17FF878EA9B38E12ULL, 0xC4005B8E97D1E2F7ULL, 
            0xDC680CC89E765FA4ULL, 0x78361D79670355D4ULL, 0x4C30DF29125384EBULL, 0xD7E616A0EAD7AE56ULL, 
            0xDB75BD2796841A16ULL, 0x84C8F500E28ABA25ULL, 0x58731E73B4FF321CULL, 0x22B38B72E37836A1ULL, 
            0xD72B7177E30B6F64ULL, 0xE82CC7E2A1A84963ULL, 0xBF8028A4EA2353BAULL, 0x55C5836F0D25EF40ULL, 
            0x353075D5177BCABFULL, 0x5B108E05FD5B45E6ULL, 0x5EA1441EBDA75A14ULL, 0xCF30483E8CAEF72BULL
        },
        {
            0x648FD04FDCAD0D9BULL, 0x2C155735FD6A75E8ULL, 0xDC030D4592861626ULL, 0x60FB1C8A42404276ULL, 
            0xC425DF42D2904B1BULL, 0x31FA14903F8A86A1ULL, 0xE718FB4950FD0A2FULL, 0xB2D41B911DBFE689ULL, 
            0xB6085999B0A26661ULL, 0xCAB372A122F6C79CULL, 0xF1C6B49888D04F7AULL, 0xA597B1EDBE4A516AULL, 
            0x57A8E0651D879542ULL, 0x162B7EF479E7B9AFULL, 0xAB94C3C5FEBCE594ULL, 0x33BC2D6F477382FBULL, 
            0xBB2CEB11E39EDB64ULL, 0x3F618487BFC3ED7AULL, 0xFD5E2820EFBC3488ULL, 0x475ADBB1E1C62C3FULL, 
            0x598D9307BE20DFE4ULL, 0xEC9ACF19B8983672ULL, 0xC20BF02A359BA512ULL, 0xC98FB9AB963A7069ULL, 
            0xA8C0DB6FFA6CA463ULL, 0xFD5B324DD3A8D8EEULL, 0x25020E68A5AA5A58ULL, 0xDD2786E01B9EDDE4ULL, 
            0xCC080B5CFC9AF011ULL, 0xA4F5248A23EAAED3ULL, 0x5540EBC8E0A89302ULL, 0xB44BEE8181B24949ULL
        },
        {
            0x4EFF49B2CDE0927EULL, 0x627ED48036D5CE44ULL, 0xA136C7866F0FBAB1ULL, 0xAD8989F411F47227ULL, 
            0xE3745A0A2BD21E68ULL, 0x53CD190A4E4EF759ULL, 0xEA7CD0AC5ECC72BCULL, 0x18E65217EDF19668ULL, 
            0x1301DFAD395B79CCULL, 0xB7A311B02D44CBB9ULL, 0x5B1FD6963891977EULL, 0xAC692C06CBF4914CULL, 
            0x4129D6D1E9C919F7ULL, 0x1DD51C91BBE9CE2FULL, 0x987CA5B1FAFFD6C1ULL, 0x14863F8AAEB966C9ULL, 
            0xBF9C40980D3698F7ULL, 0x6015647014C56D25ULL, 0xF185C4F4096968AAULL, 0x772D0AC046EFCD98ULL, 
            0xA2DBBB2867DC4A71ULL, 0x1E06DA02C15B987EULL, 0xF729623178173D93ULL, 0x98F073096943AA36ULL, 
            0x36052381BA81A52EULL, 0x709AFD2C787CAF9AULL, 0xB0804A61902B5F0EULL, 0xBB1D1EDEF81774A7ULL, 
            0xB4E8E31DB2281943ULL, 0x804DFCAF8E67F3F5ULL, 0x5CE0EA89E2E9F9BDULL, 0x8F3CA6A608755387ULL
        },
        {
            0x1D017043437668FBULL, 0x0E7E11B598345E9DULL, 0x3D49ED107F3451CBULL, 0x97495EF4651CA29CULL, 
            0xAE7DF8BEE91A1AB7ULL, 0x779AC52ADFF22FC4ULL, 0x6A17C4AD299AB1FDULL, 0x8033F5EF6C180FE7ULL, 
            0xB61F9A7A092D7FD1ULL, 0xBD62451DFD42EDABULL, 0x4F933D2878AD368FULL, 0xF9BCE02EDF996DB8ULL, 
            0x28A526205DE4927DULL, 0x7D674C8D99C09744ULL, 0xCD291A0BDDCD6C8CULL, 0x814295A7A3BEB427ULL, 
            0xB7305E62449F4056ULL, 0x54B5DA3C638F6DB9ULL, 0xAC3C989D1F2664DBULL, 0x79B91E57B364F432ULL, 
            0x6D0CCF0E21502FFDULL, 0x2167A206225BB3DAULL, 0x397D86C2951BD9CFULL, 0x47A2114F7EC293E5ULL, 
            0x5B2F001FF6D32B47ULL, 0x8976BC64F233DC82ULL, 0x535A5D91F18FEB80ULL, 0x29A627D9DBF22699ULL, 
            0x3AE378AB26B66EFCULL, 0x3415B41B2C6C1D62ULL, 0xE9A6A68D15636F48ULL, 0x1EC26D853A077B1CULL
        },
        {
            0xCF49F0F58CC3A4DCULL, 0xBB4F3695A04500ACULL, 0x6BF7F0A4F791BF4DULL, 0x027DE2355BB79C07ULL, 
            0xCB28B59CCD763DD0ULL, 0x70523E8884F7130BULL, 0xED6E62348896CBA6ULL, 0x009E0DFD66A12890ULL, 
            0x86C36F1B59482089ULL, 0x322402901AD85ADAULL, 0x8BDDE4F8B57A2B61ULL, 0xB580857531F72093ULL, 
            0x8336DA2FDAE01169ULL, 0x1DF0038799ECDB94ULL, 0x797276BB28BD2C13ULL, 0xF9062B70E41A198AULL, 
            0xA0AC316CF3CE57CCULL, 0xA7AD17319FA36612ULL, 0xE3E1B4FAF709CB60ULL, 0xB5B1B617C3E0B921ULL, 
            0x43990E2E75A0EF31ULL, 0x8410A7A94FD0921EULL, 0x2E7D6ADB28E47606ULL, 0x39DD17661AC93271ULL, 
            0x92D604DBE743B62FULL, 0x8EB80F828525C57CULL, 0xEEC0D87547F3222CULL, 0x0FDEFB2F3EA8C516ULL, 
            0x195FF087716AAF0FULL, 0x4D9132FEC3CD7683ULL, 0x165F24506DEC5C57ULL, 0xA42849F5CC2C2699ULL
        },
        {
            0x5F162778FA6716A8ULL, 0xC8481924BE054124ULL, 0x4CD66C846A07692DULL, 0x12E8CE5187A011E5ULL, 
            0x79D190238F1041F9ULL, 0x5932B8716255B044ULL, 0xFD05710C9A1ABD7AULL, 0xB7AF286D0B8C22F8ULL, 
            0xAD5B31A925DC01BEULL, 0xFAD977D637C4710CULL, 0x89C400FF8CABE740ULL, 0x12BF5B2CA461AF65ULL, 
            0xA4826097E372AE43ULL, 0x21C9E58F7486C646ULL, 0xA6B3DFFDBD09B1B4ULL, 0x251F05F06D9EB126ULL, 
            0x245B075A209096E9ULL, 0x4091DC092C82BA4AULL, 0x9CBA5339238A9147ULL, 0xB17C66AFC11EA51AULL, 
            0x0641E0BBD7E276CEULL, 0x79BC41387CA2A1E7ULL, 0x79BAE20F4CC823A9ULL, 0xE40242E355F32EBDULL, 
            0xB45FEB053B2CD22DULL, 0x9326E932DCEFE1F0ULL, 0xBE25CF7EC4917F00ULL, 0xDC5FED8C9F0F152BULL, 
            0x5249CE951FCA2876ULL, 0x607AD33A289C51E3ULL, 0xD6DA178106F8E8D6ULL, 0xADD174412724CAD3ULL
        }
    },
    {
        {
            0x4F3FD1D66E13E749ULL, 0x019F8FC52CA891FFULL, 0x003CD17A20DDED11ULL, 0xC9ABE4F7257FCF86ULL, 
            0x13980ED42DC64C6EULL, 0x23D85A3B9CA7FC89ULL, 0x1AF72B25617BF9D0ULL, 0x9AC8C952CDC7CB9EULL, 
            0x1C201118F5580C4AULL, 0x2063346937D4FC1CULL, 0x35471D066AF9680DULL, 0x90C8BD114462B348ULL, 
            0xD5531E565AB8234CULL, 0xA1D45C24D24DA7BAULL, 0x9892927F40283E4FULL, 0x02CDCA20D26B3D7BULL, 
            0x93520B9EEA28B19DULL, 0x7E81B287871CB3C8ULL, 0x46F7923CCC5BE426ULL, 0xA91DCFAF344482A7ULL, 
            0x84C47B8D422478ABULL, 0xE7DABA183E1F5EC9ULL, 0x18B69EF4130C3B68ULL, 0xAC7A7D6BB7147CAAULL, 
            0xBA8B76485F189342ULL, 0xC8D4B1724DB050EEULL, 0x9A611C6C523BB4CBULL, 0xB37088E904ACA432ULL, 
            0x13277AB8909A5F08ULL, 0x9695C09D09DFED11ULL, 0xFA6EA4092A90F9F7ULL, 0x3F5F3EA87F0B6DB6ULL
        },
        {
            0x667AF85B5CA3A1DEULL, 0x48FF0E2CF064115AULL, 0xC5892DA7B51D5968ULL, 0xCE7CAA644617263CULL, 
            0x402D19E02668B25DULL, 0xB140036290464B8BULL, 0x31AFBDC796F0AAD0ULL, 0xEC7E852B644EFF3DULL, 
            0x29364970B210EF09ULL, 0xB9DE8E8027885B6CULL, 0x69A97ACD0D628145ULL, 0xB49716F05D51F7C4ULL, 
            0xD34C061395D4CB7AULL, 0x0C92D42D3E6D2FBAULL, 0xDD41E274EDB3E580ULL, 0x2108E31935FB1F7FULL, 
            0x6A76E22343C8812EULL, 0xBD8BE18B2C6948E4ULL, 0x4A054A2DEDB8CB94ULL, 0x4B0B20EB225D0078ULL, 
            0x3ED735BD192B1D8AULL, 0xF573A28B31904BD4ULL, 0xF3FEE544FED4DC3CULL, 0x4408294B5D1B750BULL, 
            0x4270EA2C76B69026ULL, 0x81E9B3706CDE180EULL, 0xBF59865140E5B003ULL, 0xD7B15BAE7C38FB8AULL, 
            0x1E654B8722E3E414ULL, 0x27FE9EF92FBB0310ULL, 0x92BF42D7BDC5D889ULL, 0x36B8C71971BA616DULL
        },
        {
            0xD1355701B0C769E4ULL, 0x8DCA6F28E6241B0CULL, 0x845DA05B089ABAFDULL, 0xC702B820E3E0B4C3ULL, 
            0xA94540322D5E7441ULL, 0xD39D1405174BD279ULL, 0x5E031893E60CBA85ULL, 0x944770A8E4F80F34ULL, 
            0x5EFC9A2FE7B8DC88ULL, 0xA1FA5B672C713927ULL, 0x8ECD63641D5F6E7CULL, 0x32C2FD0ED28A379AULL, 
            0x4631627C8FFAC6B5ULL, 0xE542EAC08B14847CULL, 0xADD6ED68A25EBCA5ULL, 0x6A105A8275B19EAEULL, 
            0x46A7EC736A9B46E2ULL, 0xF5328DDB228F3B1CULL, 0xF054251086F83822ULL, 0x91DC8FBF011B7BD4ULL, 
            0x88993E8CF0D353E1ULL, 0xFDD2B2DB7AA8F4AAULL, 0x84B3E4EF88E25319ULL, 0x4476E3D22BB777BBULL, 
            0xC1C43C15D1D9DA65ULL, 0xF6DE3C72DD5AE8FCULL, 0xD64BAE29AE8C576BULL, 0x1FE14DEA307D69BFULL, 
            0xC304C66B6949A6B6ULL, 0x8850E4A39234BDBFULL, 0x9E6F7D680ECB5984ULL, 0x0002318237F7E756ULL
        },
        {
            0xBEEC177D69CF5658ULL, 0xA627ED0F7E53C06DULL, 0x6EF64DAB8476FEC2ULL, 0xF57D4D344686575CULL, 
            0xA3102B24114C2E14ULL, 0x446537F60BEE60B8ULL, 0x2D473B621CE01B68ULL, 0x5CDDF6C5505AB434ULL, 
            0xE2D40939520E9D84ULL, 0x59FFD84F1EA89CF3ULL, 0x3B17B36152BAA8EDULL, 0x4D1F8F54C8599D6EULL, 
            0x87285D68D76D7851ULL, 0x475F78D75A29C5F2ULL, 0xF8F17B07310A244EULL, 0xF5FCE9D436414DB0ULL, 
            0x2046D97BEE32B011ULL, 0x4D09C05CA338139BULL, 0xB19BFB5C307545B2ULL, 0xAB2D57564397DE56ULL, 
            0x820F9DB37CD6FB70ULL, 0x135ECE977681263FULL, 0x385470218CA228E2ULL, 0x1F0B8E31BADA4215ULL, 
            0x411D8BF22D816609ULL, 0x18908773417B7BC5ULL, 0x65202D396E022EC9ULL, 0x60A5EA830B9B8A9FULL, 
            0x757BD5948B04FF84ULL, 0x675E41490CD2184FULL, 0x7A664F287A9F7383ULL, 0xFBF39D0808DCEC16ULL
        },
        {
            0x581BED0915512B5EULL, 0xB8828D002674C3D5ULL, 0x0F7855871D6E1FE2ULL, 0xAC2FAC31E186B251ULL, 
            0xB02B77A19C4A2481ULL, 0x8C44B5E4D6AB5C4BULL, 0x83B8DC51717604F5ULL, 0x8BF3212FAF3CBEB4ULL, 
            0xEED0EB41B14E453EULL, 0xF89F4C6A508EADD4ULL, 0x97958509E4357ED9ULL, 0x5A52C87A9E315507ULL, 
            0xD55EE41A8A37849BULL, 0x39F4A937B848D27FULL, 0x1FDEFF19A6E1722AULL, 0xFA2BF32DB7B80231ULL, 
            0xA1DCD905DD44278EULL, 0x5B5FA6E17655CC2FULL, 0x46505D833066E76CULL, 0x629AA5516DB79E25ULL, 
            0xB33E7E9DF23E96B1ULL, 0x4F02D3867FB6CC0EULL, 0x347498646B9134E3ULL, 0x53E0FCC83AE19152ULL, 
            0xA31868F66E858B34ULL, 0x3ACE234BED614AC4ULL, 0x89DFAB717B66185AULL, 0x3E4B7BB34B322853ULL, 
            0xE24F544850601F12ULL, 0x2B21B5924D4FCF2EULL, 0x44EF22CC806B5895ULL, 0xF95AC068512F2721ULL
        },
        {
            0x2D94B4A73E5D1F0BULL, 0x840E11F342BC3900ULL, 0x063FC4BFC92B3860ULL, 0x76939E478C6A58E6ULL, 
            0x454C4965852167C1ULL, 0x903693F7C32F2242ULL, 0xCDCF2823764274ACULL, 0x24E1B08E03DEEFA2ULL, 
            0xBFCD586B232AED59ULL, 0x9C9336725B4D2D99ULL, 0x95A0CC2C9B8BF689ULL, 0xBAFBC548810EF9F6ULL, 
            0xA6316EED8DF0F520ULL, 0x18707567A4D966D1ULL, 0xE544510F3AE80047ULL, 0x5A13FEE0C55556C9ULL, 
            0xFB8099E0D91E6D5AULL, 0x4F72045C7C5FA760ULL, 0x9B0C9FBD56094995ULL, 0xCA654925673A4057ULL, 
            0xD41ED3DD8FE67E7AULL, 0x686DEB5CCE910941ULL, 0xC42CFC0485538F6BULL, 0xDC5D813914AFB187ULL, 
            0xDA07CF9AD00B3E55ULL, 0x44EB02C629334E9CULL, 0x3F032326BF2C7EACULL, 0xEA199E42AA94DB7BULL, 
            0xDC36086669DB2F2BULL, 0xB66A6C76CB1461C2ULL, 0x9E5C9B53C99AA77AULL, 0xDA4E1A9122B491C3ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Softball::kPhaseGConstants = {
    0xE74E1C245BA8EB23ULL,
    0xBE5EE6138A432B73ULL,
    0x2D02D425F96728A5ULL,
    0xE74E1C245BA8EB23ULL,
    0xBE5EE6138A432B73ULL,
    0x2D02D425F96728A5ULL,
    0x9364E07816E402FFULL,
    0x915EB749CA627BA4ULL,
    0xE1,
    0x0C,
    0xA6,
    0x10,
    0x8F,
    0xDC,
    0x53,
    0x6C
};

const TwistDomainSaltSet TwistExpander_Softball::kPhaseHSalts = {
    {
        {
            0xC724D70EF7C086D8ULL, 0xD12426E9696AB4E5ULL, 0x71221640B5612209ULL, 0xA772E24E0CB6C003ULL, 
            0x486CFF75AFDC0AD3ULL, 0x97042220816E231AULL, 0x3F657CE127624E2DULL, 0x645175A2C5C13B3FULL, 
            0x896679A5A1618AE6ULL, 0x49D35FF609B47234ULL, 0x5EDB0C92BD8A24C8ULL, 0x3A9A71711E573E83ULL, 
            0x43BCE5DD34812C67ULL, 0x433B005494160782ULL, 0x9EEA34C1910454DDULL, 0xF4204BED49ECE036ULL, 
            0x8771DA1282A0D2F1ULL, 0x7FA46710C09AF1FCULL, 0x975CF2FF91F331C0ULL, 0x0DCEE0B1B0331D4CULL, 
            0xDEE0BDB52EAFBA57ULL, 0x94931B81DA78920EULL, 0x0E14D9FB04C37CB2ULL, 0x498717D69CBDF677ULL, 
            0x07B85EBCA65274F3ULL, 0xAEA1811E45B145F8ULL, 0x15F1420C97E61588ULL, 0xA78E5EDD5E62606CULL, 
            0x82B5352EAD27DD41ULL, 0xFA4FD830CF1C1190ULL, 0xA1533DA4C6DEA5E0ULL, 0xE271D3748CF0B43FULL
        },
        {
            0x819BCEB03CA0DD34ULL, 0x840B9507E2BBE298ULL, 0xCB143138A1C15783ULL, 0xD1DD69A1DD4CD86FULL, 
            0xCC1871AB5C294D07ULL, 0x5AEB364257FFFE9EULL, 0xFB548E4D3FFC9509ULL, 0x23B188495009038DULL, 
            0x20B4D7DB99ED5027ULL, 0x7EF5EF270B0E3086ULL, 0xCC45EC0301A6EEA8ULL, 0xFA7039CB28D7D4E2ULL, 
            0x0B1A82C5E9C048AAULL, 0x65139B57B24EA8A3ULL, 0xD42378610D48D9B9ULL, 0x22E62F41949C924DULL, 
            0x3CA51F569978A2A9ULL, 0x44643F1F68B27774ULL, 0xDC05987BC5D42E13ULL, 0x7CBC9E58843F58CDULL, 
            0x2C8276D98094A1F7ULL, 0x053A03066177DF36ULL, 0xEAA9A50F2940BB5DULL, 0x79B59641A2298589ULL, 
            0x6543CFEA3BBD98FAULL, 0x163A6F0F371C25B7ULL, 0xA5BFA4BA037E9130ULL, 0x349DBE8EB0B0E50EULL, 
            0xB358251A4C462813ULL, 0x14F19F7C7807E1A7ULL, 0x119E76D94B2C64E7ULL, 0x74A2D849DFE03E1BULL
        },
        {
            0x03BB73424F2A7B06ULL, 0xB2E73E9FD4DDEC6AULL, 0x302B34FA75545577ULL, 0x4B02F88CB85A942BULL, 
            0x79BD91B021DDE225ULL, 0x970351C03B43BA40ULL, 0xDD9EC8A5468CDD11ULL, 0xAEC3A9E4F71F5E3DULL, 
            0xF44779ED3696695CULL, 0x7F85F9D77779C8DAULL, 0xE58C5C10789AA7E0ULL, 0x3DE56DF5EC6BEB7AULL, 
            0xE631161069173426ULL, 0x5E6F617C59FA6BBAULL, 0x1A18809E09F0D295ULL, 0x44B0697984812E50ULL, 
            0x27F7B494553952DBULL, 0x2046B3E2EE147F52ULL, 0x687DD456F4ADC90CULL, 0x7107A942F22B3491ULL, 
            0x5793C9F1076E4090ULL, 0xDBD70B0AA65A382CULL, 0x9D5242F076055682ULL, 0x7D9594E87D709443ULL, 
            0xB893ACD0B9F64794ULL, 0xB94C0C369DBAF77CULL, 0xD5E35A39DC60BA9EULL, 0xF6C1FCC13E7E1DD2ULL, 
            0xC0F1CA84F0DE393EULL, 0x0A03001D147F3F66ULL, 0x8886AAEBAFF7CA0BULL, 0x5944139E7149ADE6ULL
        },
        {
            0x1C4DFC47656AFA9DULL, 0xEF09CE902CFF1235ULL, 0x40B6898C490555F7ULL, 0x7263AEDE49DFA4A9ULL, 
            0x9DA4CD35085E9C32ULL, 0xEC146B5E18E118E8ULL, 0x4955802D6D7651EDULL, 0x1A40F25FF7BA150EULL, 
            0xBA21D5F843CB5DC7ULL, 0x5388AAE0FDEEB938ULL, 0x6362587C2D4323FCULL, 0x59CA51C5B2AF8D80ULL, 
            0xC48DD8641B4A449CULL, 0xB2429086F0587EE3ULL, 0x3D13601792383970ULL, 0x2DB3F34AB9438731ULL, 
            0x3F3FFC5A7B9FEF88ULL, 0x6AE8B4EE261AD3A2ULL, 0xBE3DB08977A6CF1DULL, 0x04C0275D0D460AA6ULL, 
            0xB0CFC9328D83E60CULL, 0x048B97F62EFF53AEULL, 0x39DAD26F47303BD3ULL, 0x76E629DF10BFBCC0ULL, 
            0x7B1187E93AA33E2AULL, 0x9B5760FBB94AE300ULL, 0xD7242A8836E817D9ULL, 0x9D1B974E92ECCFC9ULL, 
            0x774D73CF6F2DC690ULL, 0x6FE0CB8188FA32F4ULL, 0x9697FA4C1AB3D4DDULL, 0xFE13582F46727944ULL
        },
        {
            0xBCEAE75F876FFB9BULL, 0x05699B3D49BF2CDAULL, 0xDFDEC14DD73A192BULL, 0xE9311A5A6F9A3DB6ULL, 
            0x6E3E3758DEA3A177ULL, 0x0DDFC238D5FEA7BBULL, 0x5272EE4E1BB92283ULL, 0xC3A99C14EC51E8FBULL, 
            0x840DE4615DA2F047ULL, 0x9BF3243F4B4C13A8ULL, 0x32402623D0979B82ULL, 0x077BEF5895A0910AULL, 
            0x61C2D0E4F5AAA9A5ULL, 0xEA192251FB01CB30ULL, 0xFE50DBDB6348DF03ULL, 0xC639A850FA73F153ULL, 
            0xF7E712C4F6FDF37EULL, 0x1E12CA99513F7946ULL, 0xF4D80D5D5036DF41ULL, 0x6128E2F15FC2FF82ULL, 
            0x9E5B8FD4ED18EBCCULL, 0xEDA518B8E44F6818ULL, 0xB4CF82256BC05E53ULL, 0xA51ED6D3C7A6EF03ULL, 
            0x11A9BFA121B2E7B6ULL, 0xD42FBC157F2D2326ULL, 0x00C57C4F275FFF80ULL, 0xE47D66F264FFC4F3ULL, 
            0x941FEDE9EABB7CB7ULL, 0x27FD4C2216E7CC38ULL, 0xF2D385F6D15DEFEEULL, 0xF18151D0A7FD39C2ULL
        },
        {
            0xF62E14E5A34B2F23ULL, 0x3B0E396B0EFA97FDULL, 0x85E40EF856DC90B4ULL, 0xD6C51CA6F1856FBAULL, 
            0x7339351604987DE5ULL, 0x4B52989A33364E5DULL, 0x74E1D2AC1E84F594ULL, 0x9DAECB472FC19436ULL, 
            0x4DAA4C26C836FC97ULL, 0x97A8366C48BDA552ULL, 0x34FC6F4ADADAD2BCULL, 0xEBA1ABBA60C9900FULL, 
            0x99E5C5F8D1CCED1DULL, 0xF21DDBADB5083635ULL, 0x8FA6DDBCB58EB768ULL, 0xFEF4F20BDF86811FULL, 
            0x2EF11BCE0D8CFE1EULL, 0xB32B8539C157B1C7ULL, 0xB18EC9BB16ECE570ULL, 0xD0EC0F7B130378C0ULL, 
            0x8A60E002915D9F36ULL, 0xCCE9BFF3D5795A1BULL, 0x5166E196B1E01FC4ULL, 0xF894DC18D3CE6291ULL, 
            0x0AD499984143069DULL, 0xECDA91568C54D898ULL, 0x39D02F8A7951F80DULL, 0xFBDC5C34EDFE9191ULL, 
            0xD371A73CB6812B2BULL, 0xA77B6BAA085691DCULL, 0x679664A267DB9E74ULL, 0xF5F22D1012581EC4ULL
        }
    },
    {
        {
            0xF5183F8C4FE49EA2ULL, 0xD1C33A433E2D738DULL, 0x1A3485972A73548CULL, 0xB21E929303256D4EULL, 
            0x4F62354C7BF9D1D6ULL, 0x3D5F9A47B0EA760BULL, 0xF181BF021FD82D43ULL, 0x7ACA436F29BDAA18ULL, 
            0x4E5F26E014855196ULL, 0xF44768D56C225C37ULL, 0xC8A481BEF06ED4D6ULL, 0x3FB48660DB930F76ULL, 
            0xB613B6F8710AD775ULL, 0xBD5033993604A234ULL, 0x240B291F7A4507BEULL, 0xC6617C024F0B5D27ULL, 
            0x50BE2654334C18E2ULL, 0x37BB9550ACE529D5ULL, 0x0111D4796DEBF978ULL, 0x81455189FE2A2CCEULL, 
            0xFFC0A00507307DA1ULL, 0x522AC315BAB4D348ULL, 0xF98ABC812EB61C6AULL, 0x0AF61B5C74ACF074ULL, 
            0xF380732EB3A51494ULL, 0x7632B4D99D7A9DBDULL, 0x9FFF2DDA6B46FC93ULL, 0xA39EF97B46333F0FULL, 
            0x75858ACAB6A9B960ULL, 0x3384CAC1E2DB5D87ULL, 0x1CE4B33D429CF658ULL, 0x542D6215B0EE3BF2ULL
        },
        {
            0x19EC8D24A6045150ULL, 0x619B52EDC13FA04CULL, 0xCF13F9B97CBCDBC0ULL, 0x62514C6CEA4B44A4ULL, 
            0xB0FE0D16891D11ACULL, 0xFC6FB729D17097F8ULL, 0x6B7011A9E8F470C8ULL, 0xBA6AE508966C45A0ULL, 
            0xCD7276DB096F43B8ULL, 0x61F74CA169528B82ULL, 0x79B6AF4D2DF3CF81ULL, 0x0B5B7080AA3ACDF3ULL, 
            0x607ED7F4CA78EB49ULL, 0xF1135B7520FEB56FULL, 0x974DF233468A7C9AULL, 0xAAB7799484D9882CULL, 
            0x42E30C1B463A9110ULL, 0x9543FD94E4BD2A6CULL, 0x08480670F5F46FFAULL, 0x073F6C8C72DB140BULL, 
            0x46685271B0C92FDDULL, 0x372C5484921B6199ULL, 0x81024D290DB71772ULL, 0xA88E766D866A01DFULL, 
            0x32EB5DF9D85AB7BBULL, 0xC81DF35D841CC873ULL, 0xC730FCCAB4A50679ULL, 0x3567503987EEAED0ULL, 
            0x3A6773C1671FE2D2ULL, 0x33B6909AAED80AB3ULL, 0x3D2469E50B11ADA0ULL, 0xC98C334F543BFAA4ULL
        },
        {
            0x7DF88FF0F34B4D19ULL, 0xE1E072264AD27DEEULL, 0x06E7835CE00F909EULL, 0x0F982EE655C83237ULL, 
            0x683594352678DAB5ULL, 0x8F866EFB6BFA34DDULL, 0xC318939E5033129AULL, 0x8F565F2B79AA0F9AULL, 
            0xA840A2B5FE03D744ULL, 0xCF4B2701CA1F1A61ULL, 0x104AC658FF228177ULL, 0xED0DE454C719B031ULL, 
            0x6550CC6546147DA3ULL, 0x651DA19AB7AD57D9ULL, 0x7A03D0C019DB8CE2ULL, 0x31EE003D99CC7E11ULL, 
            0x5CD8A41C80A766E7ULL, 0x16F20D4122238BB0ULL, 0x025A6E4423C99C50ULL, 0x55CC64D3CE2732DBULL, 
            0x96EEC1F32292B3FEULL, 0x79DA3651DF6D8252ULL, 0x15B4AF499FEA3879ULL, 0x20A68A4C5D747658ULL, 
            0x65CF1DE7FF33C405ULL, 0x667C54B5B164D4E7ULL, 0xCA6CCCD30B8737BCULL, 0xA39497FBEBE297D7ULL, 
            0xC267AD076264E2DAULL, 0x5F74E758E1269240ULL, 0xCBDE92A819F8345FULL, 0xE4F98FE8CEE18E4BULL
        },
        {
            0x06F0905D99BCAD92ULL, 0x176C22C8CAA753D6ULL, 0x8E94A1272E9731E7ULL, 0x1A6CC4AD69AB34ADULL, 
            0x42FC4F8E64694D2DULL, 0xD96B5B08C4EE607DULL, 0xA3FD960153523D64ULL, 0xB874528DC9D8986AULL, 
            0xDE3711A813D2FA6AULL, 0x0615162FAD2FB7D1ULL, 0xEA2DCC6308B361AEULL, 0xEA7D92ACD1393031ULL, 
            0xE6B6FD19809EEAD2ULL, 0x125ECFECFE9BB54EULL, 0x7FF8CD00CB0A0468ULL, 0x861946B4DD639518ULL, 
            0x50EF497590889E79ULL, 0xC7E7C05330E7CC9CULL, 0xE5186DE35CAA10BFULL, 0xDF06EA475EA710AEULL, 
            0x3E228A70BFC6E668ULL, 0x9B15E45AADF1A274ULL, 0x178982D619811484ULL, 0x84C517BB72E13C7FULL, 
            0x1FF44D8591B864DFULL, 0xCFE7CCD2C8664603ULL, 0x0A97CA2A93E1BA61ULL, 0x994B47ABF9CFD194ULL, 
            0x33F6652404D32155ULL, 0xC1725EDB4C37C516ULL, 0xB1F54CB7477B962AULL, 0x408CC556CF1D211FULL
        },
        {
            0xB72538C55EBD77C8ULL, 0xD813959F07692469ULL, 0xBA6E73F961459850ULL, 0xDE01DD832FC58087ULL, 
            0x77681A3957FB8C60ULL, 0x21FE41509833A87EULL, 0xA579C36EDCE0488BULL, 0xE4C61AAAD16C4471ULL, 
            0x9CEE28AFEC19B0BFULL, 0x6F55FFCAFCE023BBULL, 0x27D702B581062D63ULL, 0x9BCBBE43C2683E01ULL, 
            0xEAA946482524AE2AULL, 0x98F25AE13863CA24ULL, 0x1B0A45580F6E142EULL, 0xC734ACFB27F47E03ULL, 
            0x7BD7B4DE8AF5DD6DULL, 0x0A3015A1279A0D7CULL, 0xDFB40B12CB716651ULL, 0x9038B5D8C8D7F2C9ULL, 
            0x459A21659A43FCF7ULL, 0x11BD8E2A732AB28EULL, 0xE1B2C77C2EC8D288ULL, 0x837A7A7492FE9DC3ULL, 
            0x5FFECE25F557BF69ULL, 0xA676193EA71CFDC4ULL, 0xA897FE172B8E112BULL, 0xDB512596212FC710ULL, 
            0x509A4D1C28A13F8EULL, 0x743901EEFCB0C248ULL, 0xC6BB897FD4B1B58BULL, 0xD88D12D5641F3C71ULL
        },
        {
            0xEE43711D35EE50B9ULL, 0x7BD1D6277C345B88ULL, 0x0D7228F192F23007ULL, 0x28F38879E39A15A2ULL, 
            0xC9D97DD9ADD4A909ULL, 0xAB89330B3CE1E9B8ULL, 0xD860CD061FCB025BULL, 0xF45525A5F8DBEE6FULL, 
            0xB25286C2DD40E22CULL, 0xAA8473A999A21FD4ULL, 0x9B8F782E492D7BE6ULL, 0xE7531A8B689E7822ULL, 
            0x5A2849CD29B839DAULL, 0x40912DF407A11DFBULL, 0xD4C11347616C939EULL, 0x28893C9F52D37818ULL, 
            0x7F77F8ECC19162C9ULL, 0x422023D5AB415515ULL, 0x73A235C88F398005ULL, 0xC9B3C0EE55258F31ULL, 
            0xC30742C4F178277BULL, 0x20585060069FCB72ULL, 0x75813104F47690E7ULL, 0x7F5D0FE926637EBDULL, 
            0xD6FE830DC537B839ULL, 0xC5B4F64E9BDEF74AULL, 0xCF00C730F140D9ECULL, 0x26C50976A41CDDF8ULL, 
            0x1C1D89F5E37B1D14ULL, 0x690451069C78ABB5ULL, 0x06B5E719FEE7B236ULL, 0xFF9BC5F4120332A5ULL
        }
    },
    {
        {
            0xD32CCDB2907D470FULL, 0x05B77EA976066EEDULL, 0xF3417B4A395CFD4FULL, 0xEF070C65A0C30FBCULL, 
            0x1733F4160319DF98ULL, 0xA3068793AE3EB1CEULL, 0xC956E6D46D702030ULL, 0x082C758940543F49ULL, 
            0x737EB330DAFD5483ULL, 0xDE220AB395DBB4D5ULL, 0x8C0F07A73C4D7D85ULL, 0x3AEFAD07B4CDAC45ULL, 
            0x7D1F62B9F2FB0C5CULL, 0x389A80AF3A1BF5E3ULL, 0xD8F4C4C074BCFB8BULL, 0x344D2F5754BE15FAULL, 
            0x91FDE4BCE2B8822BULL, 0x2C319360E8E5B599ULL, 0x7260C9E6AE4E4288ULL, 0xF463FD7701C43DB2ULL, 
            0x8CFE2B5A903B9EA9ULL, 0xA4E74E04E6C4E238ULL, 0x107CF9ED51EE0C4EULL, 0x83351DFFF20ACBBDULL, 
            0x3CE1BD34CE4EE7FDULL, 0x0EF262FA8A17B3A0ULL, 0x90BAB386B0F69B66ULL, 0x0C3DC2396584C6B8ULL, 
            0x36E26AC871330CCDULL, 0x40F9296FC3456584ULL, 0xBF111B7D6BEA2A20ULL, 0xBD96466CAD69A519ULL
        },
        {
            0x9A7DC73428398FD3ULL, 0x03B4D2844FC62884ULL, 0xD74429C5F589BB57ULL, 0xFC6D5BCE9AA5BDB6ULL, 
            0x05E48B99B3204FD5ULL, 0x0CEC6F49FD856803ULL, 0x7E90EC32F9B3503AULL, 0xB56B7C8169A51519ULL, 
            0x8B531E71616EA554ULL, 0x475B62A4FC71B3F4ULL, 0xDB2F20B1BEAC3CC3ULL, 0xC303EDEC50A22604ULL, 
            0x0416768BD441CB45ULL, 0x2C14CCE95E0D8738ULL, 0xE1BF29752CE19CDFULL, 0x93947FCB61DB53F4ULL, 
            0xFA96D26A61321398ULL, 0xAF0B2336376540B1ULL, 0xDB5191049A75C56AULL, 0x01F467BBA7B1BDF7ULL, 
            0x606E5EB8F5F0F927ULL, 0x976214E2A9A93E7AULL, 0x3C78AC049768A478ULL, 0x5099C8C892A75E42ULL, 
            0x3C4466123A50BF9CULL, 0xD81D5640E9BAC306ULL, 0x6084A75BCCB53A78ULL, 0x8038CC62ABD851D2ULL, 
            0x129AD9DBD15BE2B4ULL, 0xA356BE4B33136F1BULL, 0x35BFC5951540F36FULL, 0x34D3D904FD9C6B2AULL
        },
        {
            0xEEC148D3DB6C5B27ULL, 0xC96FF004DF4E1B01ULL, 0x964F508CEE053FE2ULL, 0x12710346259EA253ULL, 
            0x97ED678A779A3210ULL, 0xE0F1779B1F6B8CDEULL, 0xD2D3A1F18F089C75ULL, 0xC955D44EE4AFEEF6ULL, 
            0xC2ACC2FD0997166EULL, 0x802BF8590130DAF3ULL, 0x72AD704AB45D1388ULL, 0x96BC61FA73ABB0E9ULL, 
            0x6E4F058D764C710AULL, 0x245CA72574D7649BULL, 0x5EABE7E3BB60A5DDULL, 0x259788CD1ECC1180ULL, 
            0x3457AC09DD21B514ULL, 0x1B0261DA00134034ULL, 0x52849E1F342623E8ULL, 0xC2DB63A600F2F43CULL, 
            0x725DB4087F963336ULL, 0xDF3F455B3157BA2FULL, 0x6321A8EC2DE45691ULL, 0xE02935C8F1FB9A87ULL, 
            0xBC223429C7BF86C0ULL, 0x4A6FA50AABE2EADAULL, 0x8E1C378995F6E2C9ULL, 0x065EB1AAECB88486ULL, 
            0xDD92F59AD6C7978BULL, 0x7235267E7AC6C827ULL, 0xD9BC4D10C0D9D0AEULL, 0x04C0279E44E7B9CBULL
        },
        {
            0x80913C0680262934ULL, 0xAD8550C04EF6271DULL, 0x6BA4B77C0FD17C27ULL, 0x9DDED4A4922AA88BULL, 
            0x6B615DE9D8E82253ULL, 0xDF95122E406B4F5FULL, 0x3BC7717039F9103BULL, 0x7F2FBEF9527B7F6CULL, 
            0xA0C0B35702067EF5ULL, 0x368C08484B3159EEULL, 0x04A31F75514FF50FULL, 0xDBD3EBEA66E308C4ULL, 
            0x557A88343EF75E08ULL, 0x84847D6FD5C46F83ULL, 0xD416C1FF42EB1801ULL, 0x9D87D9F583433DD2ULL, 
            0x4A6E3C502A603C9CULL, 0x1E23F5CFA9BB8427ULL, 0x50881DDE070E31D5ULL, 0x8C40E75D3EB1AE49ULL, 
            0xE8061B7FDFE29C47ULL, 0xDCDACE55158BEA51ULL, 0x6864D9FD66CE4B96ULL, 0x4E477C61FB5A4312ULL, 
            0x85C6C2AB7AFFCC0BULL, 0x99F24DE184855AA9ULL, 0x88DA4E672945872DULL, 0x458B2F8B60CBF161ULL, 
            0x00CD1445672A0A74ULL, 0x732CD06BF8304AB7ULL, 0x57B147B0AB53BB69ULL, 0xE12F846D88B056C2ULL
        },
        {
            0x5E27D063446ED9CBULL, 0x728CBCB11FA063D4ULL, 0x8751F9FDB064B26BULL, 0x1B14E19ADF142DEAULL, 
            0xAD46B9395B7C0E5FULL, 0xD80C266A23ABFE4AULL, 0xE2588DEEBBB6A659ULL, 0xA218DE48764F2BB8ULL, 
            0x8E4E2B2EF6FC83EFULL, 0xB1CD0A2177734554ULL, 0xB70354E2CA0E0D40ULL, 0xA57382BB4E2D7839ULL, 
            0xEFB4F30439BF3503ULL, 0x959D117F516F912AULL, 0xF20E435A76FA4A60ULL, 0x2815592676C1302FULL, 
            0x73DCC3CF7E631CA7ULL, 0x0A5F7A9BC9AC2B5CULL, 0x7468DCFC50903834ULL, 0x6B3CC3E07F25A6F5ULL, 
            0x430CF1678B576A8EULL, 0xC3C962916E30A782ULL, 0x337DEE9CE55C3BB8ULL, 0x066F70F0E2360C21ULL, 
            0xC3E5E98B5697C24DULL, 0xF54DA4A6B4F04839ULL, 0xCA5B71CF3ECF2467ULL, 0x8A7C7DCC98E1F943ULL, 
            0x7F54F81E4C9D83CEULL, 0x0A38560617BF4049ULL, 0x42AF4F0AA684CC6EULL, 0xFFC08236242923C4ULL
        },
        {
            0x5CD57E1B07CE9A86ULL, 0xCC34807A26B5BC6CULL, 0x2BF8ECF065D0D8AEULL, 0xE8707A00C13D1394ULL, 
            0x9C7B46B378AB7443ULL, 0x77FF200322199A38ULL, 0xA40973A4EF9C5DCFULL, 0x7EF21B8404E0E7D9ULL, 
            0x68FF8E0B40352B77ULL, 0xB0289B37D1153961ULL, 0xAE5BBDC74E01F151ULL, 0x20450615195D2264ULL, 
            0x67C83E31D5BE5101ULL, 0x843923678705E9C5ULL, 0xFAE82F52BCD8D500ULL, 0x8E2CEDB9B188FDD4ULL, 
            0xA862214D6D46825CULL, 0xF2D88713FF59A1C6ULL, 0x7A45D96C143392C8ULL, 0x5EA9D115EDC8CFEEULL, 
            0xDE5AFBA65F1D77F4ULL, 0xE059710D385D0957ULL, 0x6EC0E187E8E380B9ULL, 0x68B56685A79C8CBBULL, 
            0x5E355BBB916C95A3ULL, 0xDE66A0C4079F7EC0ULL, 0x90E967332BC9CC5FULL, 0x249635505766D839ULL, 
            0x5ADD1FC9BF36BBC6ULL, 0x39A1EB2E7C3E5614ULL, 0x0409C5A2E3BB8230ULL, 0x38A5546D723371B9ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Softball::kPhaseHConstants = {
    0x55DFC04BE20DDAB1ULL,
    0x413756A61BB69385ULL,
    0x964355B3EB29B327ULL,
    0x55DFC04BE20DDAB1ULL,
    0x413756A61BB69385ULL,
    0x964355B3EB29B327ULL,
    0xCEAC6F4BF513010BULL,
    0xCCCCEB08FFD01ACDULL,
    0xDB,
    0x6B,
    0xB1,
    0xAA,
    0xB9,
    0x8D,
    0x9A,
    0x0D
};

