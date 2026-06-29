#include "TwistExpander_Karate.hpp"
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

TwistExpander_Karate::TwistExpander_Karate()
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

void TwistExpander_Karate::KDF_A(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0x94BF406BFA70FC26ULL; std::uint64_t aIngress = 0xE92338BB6D7AE916ULL; std::uint64_t aCarry = 0xBF13C125BC066657ULL;

    std::uint64_t aWandererA = 0xF7D52BF1FAE6CE93ULL; std::uint64_t aWandererB = 0xAF7A39E3B1170E84ULL; std::uint64_t aWandererC = 0x86CD79EAD3A408F5ULL; std::uint64_t aWandererD = 0xDAAF4A5BDFB8F679ULL;
    std::uint64_t aWandererE = 0xEE002EF696126722ULL; std::uint64_t aWandererF = 0xBC7603B894621E28ULL; std::uint64_t aWandererG = 0xF881490A8B035457ULL; std::uint64_t aWandererH = 0xF3E0030EA41FA134ULL;
    std::uint64_t aWandererI = 0xC756B0EF640C5330ULL; std::uint64_t aWandererJ = 0x99763DA5E8DF7877ULL; std::uint64_t aWandererK = 0xC088CCBC755D7906ULL;

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
        aPrevious = 10991220163489165830U;
        aCarry = 17938071850930597691U;
        aWandererA = 14172013916751194537U;
        aWandererB = 13600987327090943699U;
        aWandererC = 13543867846531863328U;
        aWandererD = 15638302989996503918U;
        aWandererE = 17263110354249366190U;
        aWandererF = 12103552294297944008U;
        aWandererG = 11701333275689497016U;
        aWandererH = 13324709517961639694U;
        aWandererI = 9969350913748296109U;
        aWandererJ = 14471915293387774575U;
        aWandererK = 15543986309115841650U;
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
    TwistExpander_Karate_Arx::KDF_A_A(pWorkSpace,
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
    TwistExpander_Karate_Arx::KDF_A_B(pWorkSpace,
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
    TwistExpander_Karate_Arx::KDF_A_C(pWorkSpace,
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
    TwistExpander_Karate_Arx::KDF_A_D(pWorkSpace,
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

void TwistExpander_Karate::KDF_B(std::uint64_t pNonce,
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
    std::uint64_t aPrevious = 0x92F7977074E05A16ULL; std::uint64_t aIngress = 0xF918E0E4BCBD818BULL; std::uint64_t aCarry = 0xC2FA9CC3CD7590E8ULL;

    std::uint64_t aWandererA = 0xD1232034AB39BE74ULL; std::uint64_t aWandererB = 0x93905D47B1FDAF02ULL; std::uint64_t aWandererC = 0x9269EE77FDBC4A52ULL; std::uint64_t aWandererD = 0x8AA72E2C4B9D5A2AULL;
    std::uint64_t aWandererE = 0x82609633CD441BE3ULL; std::uint64_t aWandererF = 0x8058F17A396EEF63ULL; std::uint64_t aWandererG = 0x8FA9F72A3A0D5782ULL; std::uint64_t aWandererH = 0xC06B454053F90206ULL;
    std::uint64_t aWandererI = 0xAE7DA1EE2FBDB292ULL; std::uint64_t aWandererJ = 0xC88652D9C7C1169FULL; std::uint64_t aWandererK = 0xFE3EF9DFFE664985ULL;

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
        aPrevious = 18332862983750193354U;
        aCarry = 18234522930338486667U;
        aWandererA = 15041023835569559814U;
        aWandererB = 16184691146714528547U;
        aWandererC = 17275175559138907713U;
        aWandererD = 16968567098654471624U;
        aWandererE = 12741048280968936619U;
        aWandererF = 10460210884701380326U;
        aWandererG = 13298046229597724822U;
        aWandererH = 16550263183308193839U;
        aWandererI = 15861486334499545428U;
        aWandererJ = 16137360556206438848U;
        aWandererK = 16162006422136162011U;
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
    TwistExpander_Karate_Arx::KDF_B_A(pWorkSpace,
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
    TwistExpander_Karate_Arx::KDF_B_B(pWorkSpace,
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
    TwistExpander_Karate_Arx::KDF_B_C(pWorkSpace,
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
    TwistExpander_Karate_Arx::KDF_B_D(pWorkSpace,
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

void TwistExpander_Karate::Seed(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0x94C026B6B37DFDF5ULL;
    std::uint64_t aIngress = 0xF7EDF3D738F2EFC8ULL;
    std::uint64_t aCarry = 0x87AB74AA063B7860ULL;

    std::uint64_t aWandererA = 0xE5AC59AA7022FC31ULL;
    std::uint64_t aWandererB = 0xA905F0FBD081AF46ULL;
    std::uint64_t aWandererC = 0x8551CDA2D29E3430ULL;
    std::uint64_t aWandererD = 0xC9677B61C688C587ULL;
    std::uint64_t aWandererE = 0xB94FB1D416C1E939ULL;
    std::uint64_t aWandererF = 0x960E2AE5C7E3B3E6ULL;
    std::uint64_t aWandererG = 0xF6685C86E8B72F07ULL;
    std::uint64_t aWandererH = 0x8B5A80031C59B09AULL;
    std::uint64_t aWandererI = 0xEF1EBE5E5FBD46C5ULL;
    std::uint64_t aWandererJ = 0xC9EE79FC545DCDD7ULL;
    std::uint64_t aWandererK = 0xF2C368DF56628C4DULL;

    // [seed]
        TwistSnow::Aria256Counter(mSource, aSnowLaneA);
        TwistSnow::Sha256Counter(mSource, aSnowLaneB);
        TwistSnow::AES256Counter(mSource, aSnowLaneC);
        TwistSnow::ChaCha20Counter(mSource, aSnowLaneD);
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneA, 0);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseASalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(mDomainBundleEphemeral.mPhaseAConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneD, aExpandLaneA, aExpandLaneB, aInvestLaneG);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneB, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase B
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneD, 1);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseBSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseBConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneD, aExpandLaneC, aExpandLaneA, aInvestLaneH);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA,
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
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseCConstants), &(mDomainBundleInbuilt.mPhaseCSalts), aSnowLaneC, 2);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseCConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseCConstants), &(mDomainBundleEphemeral.mPhaseCSalts), 2);
        TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneD, aExpandLaneC, aInvestLaneE);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseCConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase D
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseDConstants), &(mDomainBundleInbuilt.mPhaseDSalts), aSnowLaneB, 3);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(mDomainBundleEphemeral.mPhaseDConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseDConstants), &(mDomainBundleEphemeral.mPhaseDSalts), 3);
        TwistSquash::SquashB(aExpandLaneC, aExpandLaneA, aExpandLaneB, aExpandLaneD, aInvestLaneC);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA,
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
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseDConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase E
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseEConstants), &(mDomainBundleInbuilt.mPhaseESalts), aSnowLaneA, 4);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseEConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseEConstants), &(mDomainBundleEphemeral.mPhaseESalts), 4);
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseEConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase F
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseFConstants), &(mDomainBundleInbuilt.mPhaseFSalts), aSnowLaneD, 5);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(mDomainBundleEphemeral.mPhaseFConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseFConstants), &(mDomainBundleEphemeral.mPhaseFSalts), 5);
        TwistSquash::SquashA(aExpandLaneB, aExpandLaneD, aExpandLaneA, aExpandLaneC, aInvestLaneB);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneC, &(pWorkSpace->mDomainBundle.mPhaseFConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase G
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseGConstants), &(mDomainBundleInbuilt.mPhaseGSalts), aSnowLaneC, 6);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseGConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseGConstants), &(mDomainBundleEphemeral.mPhaseGSalts), 6);
        TwistSquash::SquashC(aExpandLaneB, aExpandLaneC, aExpandLaneD, aExpandLaneA, aInvestLaneD);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(pWorkSpace->mDomainBundle.mPhaseGConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase H
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseHConstants), &(mDomainBundleInbuilt.mPhaseHSalts), aSnowLaneB, 7);
    pFarmSalt->Derive(aExpandLaneC, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltA,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltB, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltC,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltD, mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltE,
                      mDomainBundleEphemeral.mPhaseHSalts.mWandererUpdate.mSaltF);
    TwistFarmConstants::Derive(aExpandLaneA, &(mDomainBundleEphemeral.mPhaseHConstants));
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseHConstants), &(mDomainBundleEphemeral.mPhaseHSalts), 7);
        TwistSquash::SquashC(aExpandLaneC, aExpandLaneD, aExpandLaneB, aExpandLaneA, aInvestLaneA);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF);
    pFarmSalt->Derive(aExpandLaneD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD, pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE,
                      pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltA,
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
    // temp storage: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d
    // ---------------------------------------------------
    // write to: fire_a, fire_b, fire_c, fire_d, work_a, work_b, work_c, work_d, expand_a, expand_b, expand_c, expand_d
    // ---------------------------------------------------
    //
    TwistExpander_Karate_Arx::Seed_A(pWorkSpace,
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
    TwistExpander_Karate_Arx::Seed_B(pWorkSpace,
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
    TwistExpander_Karate_Arx::Seed_C(pWorkSpace,
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
    TwistExpander_Karate_Arx::Seed_D(pWorkSpace,
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
    TwistExpander_Karate_Arx::Seed_E(pWorkSpace,
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
    TwistExpander_Karate_Arx::Seed_F(pWorkSpace,
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
    TwistExpander_Karate_Arx::Seed_G(pWorkSpace,
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
    TwistExpander_Karate_Arx::GROW_A(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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
    TwistExpander_Karate_Arx::GROW_B(pWorkSpace,
                 &aPrevious,
                 &aIngress,
                 &aCarry,
                 &aWandererA,
                 &aWandererB,
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

void TwistExpander_Karate::SquashInvestToKeyBoxes() {
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
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_a row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 40U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 56U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 16U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_a row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_a row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseB(aSquash));
        }
    }

    // key_box_b row 0
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 1
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 2
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 8U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 48U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 3
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 0U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 4
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 24U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 56U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 32U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 5
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 0U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 48U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 16U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }

    // key_box_b row 6
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 32U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 40U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 24U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 8U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseC(aSquash));
        }
    }

    // key_box_b row 7
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            std::uint64_t aSquash =
                (static_cast<std::uint64_t>(aFragmentA[aIndex]) << 0U) | (static_cast<std::uint64_t>(aFragmentB[aIndex]) << 56U) |
                (static_cast<std::uint64_t>(aFragmentC[aIndex]) << 40U) | (static_cast<std::uint64_t>(aFragmentD[aIndex]) << 32U) |
                (static_cast<std::uint64_t>(aFragmentE[aIndex]) << 8U) | (static_cast<std::uint64_t>(aFragmentF[aIndex]) << 48U) |
                (static_cast<std::uint64_t>(aFragmentG[aIndex]) << 16U) | (static_cast<std::uint64_t>(aFragmentH[aIndex]) << 24U);
            aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix64::DiffuseA(aSquash));
        }
    }
}

void TwistExpander_Karate::TwistBlock(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aPrevious = 0xCB88881FADE78A08ULL; std::uint64_t aIngress = 0xAEA4C692603CF928ULL; std::uint64_t aCarry = 0xD5DB05591C0CF24DULL;

    std::uint64_t aWandererA = 0xA7A1F2E1842C9A0CULL; std::uint64_t aWandererB = 0x880739890E562445ULL; std::uint64_t aWandererC = 0xEE408833699471FFULL; std::uint64_t aWandererD = 0x94EB92C07936A3A2ULL;
    std::uint64_t aWandererE = 0xD75AC779D29ACEA2ULL; std::uint64_t aWandererF = 0x9E3C004CA135C902ULL; std::uint64_t aWandererG = 0x821306DC9ACAC67DULL; std::uint64_t aWandererH = 0xD5E62212DCEB3A85ULL;
    std::uint64_t aWandererI = 0x852EDDEF6EA23921ULL; std::uint64_t aWandererJ = 0xDDEC2583C917577EULL; std::uint64_t aWandererK = 0xD4953C6BFEA044FAULL;

    // [seed]
    {
        aPrevious = 15150158486960586471U;
        aCarry = 18414994169177685012U;
        aWandererA = 14703312203709620297U;
        aWandererB = 12745554719803702333U;
        aWandererC = 11305103491948394383U;
        aWandererD = 18263603747517603553U;
        aWandererE = 18169036134599845399U;
        aWandererF = 17880282857149520667U;
        aWandererG = 13823434086727429977U;
        aWandererH = 17875688446403846674U;
        aWandererI = 14476244417936687379U;
        aWandererJ = 14753312364590232195U;
        aWandererK = 18412160494830112432U;
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
    TwistExpander_Karate_Arx::Twist_A(pWorkSpace,
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
    TwistExpander_Karate_Arx::Twist_B(pWorkSpace,
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
    TwistExpander_Karate_Arx::Twist_C(pWorkSpace,
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
        // ---------------------------------------------------
        // write to: expand_a, expand_b, expand_c, expand_d
        // ---------------------------------------------------
        //
        TwistExpander_Karate_Arx::GROW_A(pWorkSpace,
                     &aPrevious,
                     &aIngress,
                     &aCarry,
                     &aWandererA,
                     &aWandererB,
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
        TwistExpander_Karate_Arx::GROW_B(pWorkSpace,
                     &aPrevious,
                     &aIngress,
                     &aCarry,
                     &aWandererA,
                     &aWandererB,
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

void TwistExpander_Karate::GrowKeyA(TwistWorkSpace *pWorkSpace) {
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
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseC
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aIndex]) << 24U) | (static_cast<std::uint32_t>(aExpandLaneB[aIndex]) << 16U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aIndex]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneD[aIndex]) << 8U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 1, 2, 1, 0 with offsets 2032U, 5652U, 5713U, 7339U
        // byte shifts: 24U, 16U, 8U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2032U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5652U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5713U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7339U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 0, 0, 3, 2 with offsets 8117U, 845U, 2251U, 3093U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseA
        // write to: aWorkLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8117U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 845U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2251U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3093U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 2, 1, 0, 3 with offsets 1984U, 129U, 488U, 7512U
        // byte shifts: 24U, 8U, 16U, 0U; diffuse: DiffuseC
        // write to: aWorkLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1984U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 129U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 488U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7512U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aWorkLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA source quarters 3, 3, 2, 1 with offsets 716U, 6523U, 6420U, 3025U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseA
        // write to: aWorkLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 716U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6523U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6420U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3025U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 3, 0, 2, 1 with offsets 407U, 1260U, 1858U, 1563U
        // byte shifts: 16U, 8U, 24U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<W_KEY]
        const std::size_t aFoldBaseA = 3U * W_KEY;
        const std::size_t aFoldBaseB = 0U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 407U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1260U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1858U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1563U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneB fragments 2, 1, 3, 0 with offsets 259U, 1825U, 794U, 2036U
        // byte shifts: 24U, 8U, 0U, 16U; diffuse: DiffuseA
        // write to: aOperationLaneB [0..<W_KEY]
        const std::size_t aFoldBaseA = 2U * W_KEY;
        const std::size_t aFoldBaseB = 1U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 259U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1825U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 794U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2036U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneC fragments 1, 2, 3, 0 with offsets 556U, 163U, 1375U, 1438U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneC [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 556U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 163U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1375U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1438U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneD fragments 1, 2, 3, 0 with offsets 682U, 1963U, 337U, 294U
        // byte shifts: 8U, 24U, 16U, 0U; diffuse: DiffuseA
        // write to: aOperationLaneD [0..<W_KEY]
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 2U * W_KEY;
        const std::size_t aFoldBaseC = 3U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 682U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1963U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 337U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 294U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD [0..<W_KEY]
        // offsets: 1738U, 1153U, 1944U, 47U
        // byte shifts: 0U, 16U, 8U, 24U; diffuse: DiffuseC
        // write to: aKeyRowWriteA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 1738U) & W_KEY1;
            const std::size_t aFoldIndexB = (aIndex + 1153U) & W_KEY1;
            const std::size_t aFoldIndexC = (aIndex + 1944U) & W_KEY1;
            const std::size_t aFoldIndexD = (aIndex + 47U) & W_KEY1;
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneD[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldA grow_key_a_fold (end)
}

void TwistExpander_Karate::GrowKeyB(TwistWorkSpace *pWorkSpace) {
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 3, 1, 2, 0 with offsets 3407U, 2629U, 1264U, 5248U
        // byte shifts: 24U, 0U, 16U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneA [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 0U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3407U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2629U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1264U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5248U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 1, 2, 3, 3 with offsets 8075U, 5550U, 65U, 2136U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aExpandLaneB [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 3U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 8075U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5550U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 65U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2136U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aExpandLaneB[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 0, 3, 1, 2 with offsets 1072U, 2620U, 2526U, 2451U
        // byte shifts: 8U, 16U, 24U, 0U; diffuse: DiffuseB
        // write to: aExpandLaneC [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 3U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 1U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 2U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1072U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2620U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2526U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2451U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aExpandLaneC[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD source quarters 2, 0, 0, 1 with offsets 2216U, 3676U, 4712U, 508U
        // byte shifts: 8U, 24U, 0U, 16U; diffuse: DiffuseC
        // write to: aExpandLaneD [0..<(S_BLOCK >> 2U)]
        const std::size_t aFoldBaseA = 2U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseB = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseC = 0U * (S_BLOCK >> 2U);
        const std::size_t aFoldBaseD = 1U * (S_BLOCK >> 2U);
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2216U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3676U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4712U) & ((S_BLOCK >> 2U) - 1U));
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 508U) & ((S_BLOCK >> 2U) - 1U));
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aWorkLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWorkLaneD[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aExpandLaneD[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD [0..<(S_BLOCK >> 2U)]
        // offsets: 5586U, 6154U, 7224U, 6609U
        // byte shifts: 0U, 24U, 16U, 8U; diffuse: DiffuseA
        // write to: aOperationLaneA [0..<(S_BLOCK >> 2U)]
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK >> 2U); aIndex += 1U) {
            const std::size_t aFoldIndexA = (aIndex + 5586U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexB = (aIndex + 6154U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexC = (aIndex + 7224U) & ((S_BLOCK >> 2U) - 1U);
            const std::size_t aFoldIndexD = (aIndex + 6609U) & ((S_BLOCK >> 2U) - 1U);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aExpandLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aExpandLaneB[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aExpandLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aExpandLaneD[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aOperationLaneA[aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 1 with offsets 517U, 1408U, 911U, 302U
        // byte shifts: 24U, 16U, 0U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 3
        const std::size_t aReadBase = 1U * W_KEY;
        const std::size_t aWriteBase = 3U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 517U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1408U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 911U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 302U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 16U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 3 with offsets 1658U, 115U, 1261U, 631U
        // byte shifts: 16U, 0U, 24U, 8U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 0
        const std::size_t aReadBase = 3U * W_KEY;
        const std::size_t aWriteBase = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 1658U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 115U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1261U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 631U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 8U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 2 with offsets 199U, 439U, 1042U, 1335U
        // byte shifts: 16U, 8U, 0U, 24U; diffuse: DiffuseA
        // write to: aWorkLaneA fragment 2
        const std::size_t aReadBase = 2U * W_KEY;
        const std::size_t aWriteBase = 2U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 199U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 439U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1042U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1335U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 8U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 24U);
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aOperationLaneA fragment 0 with offsets 402U, 1117U, 1051U, 1176U
        // byte shifts: 16U, 24U, 8U, 0U; diffuse: DiffuseB
        // write to: aWorkLaneA fragment 1
        const std::size_t aReadBase = 0U * W_KEY;
        const std::size_t aWriteBase = 1U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aReadBase + ((aIndex + 402U) & W_KEY1);
            const std::size_t aFoldIndexB = aReadBase + ((aIndex + 1117U) & W_KEY1);
            const std::size_t aFoldIndexC = aReadBase + ((aIndex + 1051U) & W_KEY1);
            const std::size_t aFoldIndexD = aReadBase + ((aIndex + 1176U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexB]) << 24U) |
                (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aOperationLaneA[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aWorkLaneA[aWriteBase + aIndex] = aFoldWord;
        }
    }
    {
        // read from: aWorkLaneA fragments 1, 3, 2, 0 [0..<W_KEY]
        // offsets: 822U, 2001U, 561U, 847U
        // byte shifts: 8U, 0U, 24U, 16U; diffuse: DiffuseC
        // write to: aKeyRowWriteB
        const std::size_t aFoldBaseA = 1U * W_KEY;
        const std::size_t aFoldBaseB = 3U * W_KEY;
        const std::size_t aFoldBaseC = 2U * W_KEY;
        const std::size_t aFoldBaseD = 0U * W_KEY;
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 822U) & W_KEY1);
            const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2001U) & W_KEY1);
            const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 561U) & W_KEY1);
            const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 847U) & W_KEY1);
            std::uint32_t aFoldWord =
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexB]) << 0U) |
                (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWorkLaneA[aFoldIndexD]) << 16U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
    // GKeyFoldB grow_key_b_fold (end)
}

const TwistDomainSaltSet TwistExpander_Karate::kPhaseASalts = {
    {
        {
            0x89A5097AD0ADF77DULL, 0xEF7FE76657E0909AULL, 0xDF80BADD3EF8B8E9ULL, 0x333DEB78022755F6ULL, 
            0xADCEC37E369E1684ULL, 0xF0890DDA8AA64596ULL, 0xA0A084212072C5AAULL, 0xA498AE32CCC8AAE8ULL, 
            0x8B3E858ACE5E65C6ULL, 0xBFE6C79E7D018277ULL, 0xDE60B727F940729FULL, 0x7CFBAF2AAA7991E1ULL, 
            0x3E6D6B86449EDE72ULL, 0xEAE60D416BFBB99BULL, 0x87E254EC9CBC43F9ULL, 0x3BF67C5C2F6B93D2ULL, 
            0xADEACC1FC0C09D89ULL, 0x69FEA1C161A6F2CFULL, 0xF01E0B974EFFC86EULL, 0x3F51BAB1BA324B6FULL, 
            0x17A8AAEEF115291AULL, 0xB782C7CDB68446EBULL, 0xEE1A5018B58CBDFCULL, 0x4D862234AACACAB9ULL, 
            0x02320CA8011683D4ULL, 0xA04AF4D807E488DAULL, 0x04C5F15AD2134E41ULL, 0x43D02B68A5A1E315ULL, 
            0x34F53004D6574557ULL, 0xD89E68A511D5D811ULL, 0xE9456889D29BAFA3ULL, 0x6FB757B6DB0ED2B8ULL
        },
        {
            0xB8AE5BAC6736199FULL, 0x0E9171B5155BF6D3ULL, 0x97505A133B187336ULL, 0x577F889E3A547789ULL, 
            0x0CE3E50C6F0FD76BULL, 0xBC15397CD5E8FE46ULL, 0x5493D744AC2F4B21ULL, 0x306D7BBC1C5AB08AULL, 
            0x068A13223B22F82AULL, 0x254A66FCE10DB358ULL, 0x9E993D65A30ECFE2ULL, 0xF23D4A2859C5F25EULL, 
            0xE9AE09D9C4C67A03ULL, 0x80B4479B625C7F29ULL, 0xE6EC3FD35B3A2B76ULL, 0xB6E0C4C632963B7BULL, 
            0xC5090665D2169CB9ULL, 0x10CB463ABA57E082ULL, 0x99BDDD0A4402A4F7ULL, 0x1D9B1721C23CD678ULL, 
            0xA9B77FB40E89966AULL, 0x94A9DA8F55E312DDULL, 0x86B20711B8E8F0FDULL, 0x76FC84A4F4980B35ULL, 
            0x9B98D539BF287888ULL, 0x733DBBE6A187E429ULL, 0x252D66C36A2E67D7ULL, 0xB283BDC11C6E4459ULL, 
            0x5770A4E807E658A8ULL, 0x20B57AAF7950ECD9ULL, 0x2E81AE4DC3B31F19ULL, 0x2CD4E8364E068E9DULL
        },
        {
            0x9BC348E2BF954921ULL, 0x95BE0668AE960606ULL, 0xC28A9C81E867F8E4ULL, 0x958C6362450FC9ADULL, 
            0xFCB59C777D7EFC94ULL, 0xDECDFDEC94D71ABBULL, 0x38ECFF7D3C4DDB2EULL, 0xDCECC3699221C999ULL, 
            0x6AD55B1A0C500ACCULL, 0x68161475CF58AC81ULL, 0xE8C264BF2BB2FCE4ULL, 0x14C92CB2A489F752ULL, 
            0x49349ACFCE825C59ULL, 0x4B766DC71464884EULL, 0x93C8BFDC377DE232ULL, 0x258F4F602F54BD6BULL, 
            0xC7096DEA85568571ULL, 0xAEF34BD095315EE9ULL, 0x2F3987A3D7302B5BULL, 0xFD68B3D455C6CBC1ULL, 
            0x47880B4CC5BE14EFULL, 0x10082F3EE439E917ULL, 0x6B8A261A0362B10BULL, 0x38DEE9AD754D0C21ULL, 
            0x1B050A0A0D4E03BEULL, 0x22184B807F996EB5ULL, 0x1A8D93886C8689B7ULL, 0x8B093C49C5EE4866ULL, 
            0xB0DCB2CAE7C2DE3AULL, 0x8A0454BF8276828AULL, 0xD0B0D1C8D696F3DBULL, 0x968D3EB3824D84C4ULL
        },
        {
            0x045848176EB5EFF5ULL, 0x1CCD4C32D02FEA54ULL, 0x5DD9838B5D79EF56ULL, 0xBD243C9704745BA5ULL, 
            0xED669D731EFF12E6ULL, 0x5F704395BD2208A1ULL, 0x3BC56BAA8C7649C9ULL, 0x8729F2D9CE9910EFULL, 
            0x1578865FBAF585BCULL, 0xE29E2E07B887C3FEULL, 0x7535F5D85637F38AULL, 0x8AAC678A7EE68351ULL, 
            0x8A07EADF2AE6EE91ULL, 0x31A6C6089461D5C2ULL, 0xE06BC907D1012226ULL, 0x58A6992340FB485EULL, 
            0x6D29ECA0B87A9233ULL, 0xC550D6F2FB262932ULL, 0x6DEA6F4190EA4586ULL, 0x32298D794764406EULL, 
            0x4255E3FFE93FB427ULL, 0xFD15595D870752AFULL, 0x5A74360CFE6FCFE4ULL, 0x00950F836DEC5E2EULL, 
            0x57EC707FE16E1710ULL, 0xC250000FA920970BULL, 0x654D94B2281B9A54ULL, 0xD04294CC4DDE1FDAULL, 
            0x636F92ED3F5DF263ULL, 0x87EDDDAA2605AF51ULL, 0x3B39FDBE1075826FULL, 0x22409F75F051D97CULL
        },
        {
            0x17B041D91B4B8C4CULL, 0x592C7FFE29796364ULL, 0x69D235BF3932201BULL, 0x7EC713267F75ABFDULL, 
            0xE68F31E84A8D7465ULL, 0x67FE91975986C94BULL, 0x5CEF9609F43D9D65ULL, 0x00D618184A4ACE7EULL, 
            0x65628538553C92E4ULL, 0x38A1D6F23A4C91CFULL, 0xA4BA0039D53363E7ULL, 0x68DC809180123C1FULL, 
            0x910CE7DE8A1E0D10ULL, 0x637543BBBD9C3E63ULL, 0x52D4C9E18118C802ULL, 0x70A6622651362317ULL, 
            0xE71AF04E8275063FULL, 0x350386F4742D769CULL, 0x4FEEF9A0B5E1BEC0ULL, 0x5D8F83720C13BA22ULL, 
            0xDFA2CEC72C595181ULL, 0xF5772CFC4BF6A43FULL, 0xAF14043DA623D796ULL, 0x1812A0F33339A814ULL, 
            0x664AE1055C2F25C3ULL, 0x0C153A9106B61E48ULL, 0x8DB6293D27005BE6ULL, 0x0B1B00800EBC3B2EULL, 
            0x28CD94E45940410FULL, 0xDA75F5A458824499ULL, 0x11A920D127CB6043ULL, 0x5494276C8CA4A3D8ULL
        },
        {
            0x886F807A23128E75ULL, 0x8EFFD06E902C2F06ULL, 0x49ED55DE52441EF3ULL, 0x4DE729C0056528D0ULL, 
            0xFFF331F32FFE3F0FULL, 0x4D67C842308E67D1ULL, 0x0476380AA408B13BULL, 0x2057948244C7D5E6ULL, 
            0xFEE7B25C9741F9EAULL, 0xBC3363F33E67FF38ULL, 0x8CE8DEEE31B92762ULL, 0x8A770CD6B595A28DULL, 
            0x23D0405AADF1560FULL, 0xE13BD3370A281442ULL, 0xACDB2D1D7675AFB6ULL, 0xAD6AE5A59FDDD107ULL, 
            0x7EF9C1CCF843B25FULL, 0x4CF87D61E420CF6FULL, 0x877755B53C39E72DULL, 0xF1A6DA15FD96437EULL, 
            0x648ABFDF2F051944ULL, 0xFD6B7B410A65A94BULL, 0x2A3AB2AFE3B8E295ULL, 0x073FCE091668468EULL, 
            0x2EB8D26CB17C031CULL, 0x1A2F6C0BB8A4DBEEULL, 0xBA56306F6B6D7135ULL, 0xC7F0281AD67E9619ULL, 
            0x49E1BCBC8D69B76BULL, 0x26C9E7B7CB7BFF8BULL, 0x16494332BAA430C1ULL, 0x134520632809DB32ULL
        }
    },
    {
        {
            0x7F63D27904B1B43CULL, 0xDEBEFFBD029D322DULL, 0xCDA8847D8CEEFD35ULL, 0x05AEE1ECEB1DECF4ULL, 
            0x5F2FF220B9DE4CE9ULL, 0x28E643A9C4B756AAULL, 0xCC2593EC22C75B84ULL, 0x7C6AA9D5A4268927ULL, 
            0x703BD7C93199A12BULL, 0x475F4BAAB6BC2645ULL, 0x491D25C8DE167EFEULL, 0x8A0450BC44675A82ULL, 
            0x1C5E6D41A35B9E75ULL, 0x9C0B13F6DB563C91ULL, 0xBE7D2CE3DB3B50B2ULL, 0x8CF10045238D96A6ULL, 
            0xF94D653AB1BF9EDFULL, 0x312040739760CE18ULL, 0x0FC8AD9D319F46E6ULL, 0x5872D355186BC0C3ULL, 
            0x567658FD0080B6CDULL, 0x6950AB82294CCE44ULL, 0xE9863A2264849AF4ULL, 0x5A97FD898DDCA9CCULL, 
            0x5F525342B0831331ULL, 0x5726F30E6F7EC3F7ULL, 0xABA05C3C4FA66DC0ULL, 0x6A858DFBE19730D4ULL, 
            0x66B0218815B20B36ULL, 0xB319DD76E2F5CE88ULL, 0x9A2570A37B29521AULL, 0xF7C476785469679DULL
        },
        {
            0xAC7D522492092EADULL, 0xEA6773D42528BF8EULL, 0x648706447C647047ULL, 0x5A21A84E156EF2E3ULL, 
            0xD9D19E9AB8122643ULL, 0x2587040ADA3FA391ULL, 0x1DEE8384D89CB325ULL, 0x71F16C7D86309A54ULL, 
            0x4BD86F6EC1DE1486ULL, 0x20EA6189193CEB7AULL, 0x776E9605AE3316FCULL, 0xBD2534647EE60765ULL, 
            0x94EC9D5285DB030DULL, 0xDACF828563DD722DULL, 0x2A2C593343B6FAB5ULL, 0x39146CE9531B1D47ULL, 
            0x0786DDD991DB5943ULL, 0xCEF240614445AC33ULL, 0x86D2396BC519A1B9ULL, 0xBEC792AFD6E089D7ULL, 
            0xC7FD6E166A5F473BULL, 0xB2A325779BB1EE66ULL, 0x3AAE9868D427F803ULL, 0x019C625836868818ULL, 
            0x6A42117EC529EC04ULL, 0x108C4A85AFC75480ULL, 0xF46DC8587134321FULL, 0xC3604EC8E32156C6ULL, 
            0x0231DAC668C01F6CULL, 0x9E4C81CFF734C061ULL, 0x24F67A683D2E22A4ULL, 0x6F3F5AE30D636F4CULL
        },
        {
            0x3482C708C5FCB182ULL, 0xFC0EA3BA8810EE56ULL, 0x660410E2B2221AAAULL, 0xF37F22539E71A1E9ULL, 
            0xAD55E302FF3941F0ULL, 0x504A737D6DDF0772ULL, 0x36F266A0DFA4DF5BULL, 0xFD2C927732487EF2ULL, 
            0x05A223E7F26C8E44ULL, 0x78945586A1AB3C42ULL, 0xBA2C2FBEAFA6E0D8ULL, 0x855CCBEAB615B871ULL, 
            0xF133F8F4DDC23808ULL, 0x931DCAF71C299C31ULL, 0x921686D93C0504FFULL, 0xB1765121A1722C74ULL, 
            0xFD7503E76F6C65E3ULL, 0x3DBF5F72440B363BULL, 0x5AE7FE105C82F185ULL, 0x7C8E2E3B5BC69A4BULL, 
            0x3D5415CB0A88BDCAULL, 0x538F1278DB331193ULL, 0x371F3D9044F982D5ULL, 0xD6E0C3A271FA8755ULL, 
            0x21F35975D5387D69ULL, 0xC658BD6E7AEDFBF5ULL, 0x2772CB078EB5FAE5ULL, 0xC6CFCB3265EFC76EULL, 
            0x11DD0BEF7EB0BABDULL, 0x9F60879E462522ACULL, 0x9CDA12161B6BEADFULL, 0x6777E447E1271895ULL
        },
        {
            0x0F9E129B43169B8EULL, 0x0E621C94B2F6E425ULL, 0x64404D2BC9DA9200ULL, 0xE975610D6E60A6EBULL, 
            0x3316621FCC4D9736ULL, 0x33EBE6D69D160E73ULL, 0xBABA9094DBF65B6DULL, 0xC9B53610056A059DULL, 
            0x1AA5818F3840583AULL, 0x93E527D8B81DE375ULL, 0x5189C2820EE62A7CULL, 0x57AE8A89D8241354ULL, 
            0xBE1EBA05A0F1B996ULL, 0xEDA9E49073BBC991ULL, 0x34770C8DD1EDD30DULL, 0xEFA2447F99710F09ULL, 
            0x2BDEE10187C0A4ABULL, 0x239A35485C001F34ULL, 0xC38B3449325EF9D0ULL, 0x4C92B3D9D74072D6ULL, 
            0x143F3C97F867FB1AULL, 0x7A6BFE55FBC3C966ULL, 0xE758AD5E5E69C6E2ULL, 0xBB2EBAC483DFAED9ULL, 
            0x3BE21393F1728C72ULL, 0xE9B82B680A4E1777ULL, 0xF1A3E3EE12595B9DULL, 0xACF720BEB9EF708FULL, 
            0x7A937F44178B2EF2ULL, 0xC7A256C61EF02293ULL, 0xEFBB708201ADC169ULL, 0x4500C4FC0D2D36F3ULL
        },
        {
            0xB36241121B1BFF00ULL, 0x5F414F9ED865FD7BULL, 0xCFCAA82B00FA1C74ULL, 0xBC83EFB774DE8E39ULL, 
            0x47A0A59C4FFB2155ULL, 0xE13AA4309504F383ULL, 0xBCF035FDD8C735E5ULL, 0xCA20683B85CBC2B9ULL, 
            0x6CCCFFB4FE37BC26ULL, 0xFE1C57BD4B9AB450ULL, 0xAB4213B461993792ULL, 0x8A0B07B465A52BD2ULL, 
            0xF63922291A2BE416ULL, 0xC6D1DCCA0ADB9A16ULL, 0x4DE72176E80B8DCCULL, 0xDB98256478D316C3ULL, 
            0x94750049824EAFD2ULL, 0xAB4501E1A4A2F6B4ULL, 0xC951C060A65BB80DULL, 0x18CFE889255C8AF5ULL, 
            0xB25E654B8FE59144ULL, 0xC5C4142F2470CE97ULL, 0x72E61B9960CEEBF3ULL, 0x9B3B8B28E3CC7751ULL, 
            0x1FD3C6FD3B15B9B0ULL, 0xF71DACC79B21D716ULL, 0xA87E99A0264AD504ULL, 0x5E318D1DAA3EE216ULL, 
            0x1F2664CF66BB5CB9ULL, 0x92834A00AA316025ULL, 0x98108AD10EE8BE14ULL, 0xC7383CF387054B81ULL
        },
        {
            0x71DF374FE4BCF1B2ULL, 0x2538DAED817FC662ULL, 0xC202CA7C0E2FC261ULL, 0x3D045C5FD8F64026ULL, 
            0xBDD0A8A20201E923ULL, 0xF86806A3BCB041E3ULL, 0x16203EB857996564ULL, 0x2C11AC84B7566F15ULL, 
            0xFDCB8C4172DE64FEULL, 0xF0AA41F225782D0FULL, 0x79EDC76F0D1DDD92ULL, 0xCE29154407CDBAEEULL, 
            0x44A92134235C1F0EULL, 0x9E6A02D7EC8D0BBFULL, 0xFA45FFBFA3D44BEFULL, 0x164DEE972D2225B5ULL, 
            0xA11C7FB54645B891ULL, 0x8459E25E6380854AULL, 0xF59B99CECD02B3B6ULL, 0x23A6BEE390A657BAULL, 
            0x7E071C855A7AF5DFULL, 0x91BFA453CCFD7D6CULL, 0xDFAB46171A55F623ULL, 0x7D07134BA4AF3E61ULL, 
            0xC68393127AA47FBBULL, 0x34CA2C254E2D7F06ULL, 0x2CD76061AF0FE9B4ULL, 0x23EAC274ED417B9EULL, 
            0xBDBDD8703F6A77DAULL, 0xB1049C5C300892DFULL, 0x02F58B87CF9771AEULL, 0xCAA1644B43F0F793ULL
        }
    },
    {
        {
            0x19AE7E56151EB848ULL, 0xECB43D5E489C3E3BULL, 0x2B744EA8150089B5ULL, 0x7F7281CAEC0C5B7DULL, 
            0x9293E851231DE5ADULL, 0xD5057E252C48925DULL, 0xB1DB2351E22775B4ULL, 0x7CA894A5AEE3DA48ULL, 
            0x9A064350FA5A0193ULL, 0x4638E5D2F6242347ULL, 0xF3A8C3FCC2213142ULL, 0x3725F8027B074B56ULL, 
            0x937311E9069E01C3ULL, 0xCEB82E9E180335BAULL, 0xC1A7B9FA7A913D26ULL, 0xC3447E3E12922230ULL, 
            0x96A6C753072FF496ULL, 0x1F1C3C2E04D82A99ULL, 0x00E3ECDDF27ACCBEULL, 0xC5243C3583A87C19ULL, 
            0xF100FF164F3692E5ULL, 0x06B711A2E960BE0BULL, 0xDF8548D7D159E6F3ULL, 0x19D2D233E2BAD5CFULL, 
            0x17721CC61D943569ULL, 0xAAE4B492C011CD3CULL, 0x96E003C17F8441A8ULL, 0xF3E60B594B52EBF4ULL, 
            0xC14CFB2759D74EE3ULL, 0x2E668D56A2BBE7C5ULL, 0x8658F05F0EA87C62ULL, 0x826030266F603C6BULL
        },
        {
            0x881FCCD4145F6E72ULL, 0xFC43CC74F0D10866ULL, 0x873862A6685B80FEULL, 0xE8F1089ED501F20FULL, 
            0xA8652A6F327CABE1ULL, 0x48A7C1219AA1FC42ULL, 0x7C4C4566C48DFA3DULL, 0xEEB5EE40937425A8ULL, 
            0x01B13FC04FAC531BULL, 0x876E0F71A3A0202DULL, 0x02B100A08B07D38EULL, 0x5DD95712AE9ED2D9ULL, 
            0x3D67831C031C4B51ULL, 0xF67351FAAD855EA6ULL, 0x87D2F41E0E97E821ULL, 0x5F2B9CDE48A8F40BULL, 
            0xB445C084EA550F90ULL, 0xC474F34A9239B258ULL, 0x95100AD2123CBDFCULL, 0x8A4C963AF6F1821AULL, 
            0x4030520E1055BECEULL, 0x59708CFBF76E5FDBULL, 0x46D464691336319CULL, 0xBFF60049D26A0E63ULL, 
            0x5DDB2D4386D3D0A0ULL, 0x55C6D4DC200FD248ULL, 0xC3820D696AEDE9A3ULL, 0x9C2F5358A633B9A7ULL, 
            0x3074508DB5C67BCFULL, 0xC78958CFE8251F7FULL, 0xAED4FED86976930CULL, 0xD117A2FA36449260ULL
        },
        {
            0xCCCF6EDD9AD866E4ULL, 0x87078656CE79141DULL, 0x8B99170FEAC31F6FULL, 0xAB53F39C031579AEULL, 
            0x5184FD90E5183835ULL, 0x061157C816DAE2A3ULL, 0xF49B59FE381D7A6FULL, 0xE244F0C6FD52CF6FULL, 
            0x43F94A699C4ACBE4ULL, 0x871861645318715BULL, 0xE04777999BDED599ULL, 0x17B29C6158D1C7DAULL, 
            0x21268A0822E71114ULL, 0x7FDAC4F4F65D11C1ULL, 0x48B49543B74C34DDULL, 0x093C1C6811B79E96ULL, 
            0x9BCB7C8032D7129AULL, 0x0925D9519AFAB408ULL, 0x81022B58C92444AEULL, 0x894F250E30DCCC0AULL, 
            0x3B8FA2248E38A100ULL, 0x7C4053474B873C2AULL, 0x61EB00118A88BE3DULL, 0x5492A95EF68A7B99ULL, 
            0x5899316D281ABC31ULL, 0xDCE08CB5F161B691ULL, 0x0B809C5506FFE2E8ULL, 0xAA38839800CF0672ULL, 
            0x6C06505A9D20B281ULL, 0x9CBE508873219EB7ULL, 0x04826F510A64C76DULL, 0x2F651FBACF7533F2ULL
        },
        {
            0x9A83EC0800C9A2A2ULL, 0x932E9790C028D170ULL, 0xFE0FC60FA08C55B3ULL, 0x02B0835398F64DC0ULL, 
            0xF10AFEF292259519ULL, 0x6F9928BE1AD1C90EULL, 0xA7A94625BB7F73CFULL, 0x8BAEAE3D2D839D34ULL, 
            0x2E2A54186F7CEF76ULL, 0x84381DB530AC30E8ULL, 0x95F2FCE5DC99B00EULL, 0x7D0327337C1B0B48ULL, 
            0xC379FFAA62F02466ULL, 0x173C76AAC6389ACBULL, 0x452D724C01FE8764ULL, 0x0FF2E031D0C9FE1AULL, 
            0x52D7F410F2E4E9D7ULL, 0xF3CA9AE8B76710CEULL, 0x1C1B58A9D2C52AB1ULL, 0x25FE956C70B9BB87ULL, 
            0xEBC82B735562375FULL, 0x2C3ACAF3CC9F3141ULL, 0x058C05BA4C3F05C1ULL, 0x532E15DBA55C1F40ULL, 
            0xEF2E130038627640ULL, 0xEC3928E50C307C86ULL, 0x9C4134C69BDAB39EULL, 0x56A6952B3AF26775ULL, 
            0xE6128C97A4DA61A2ULL, 0x6C11B6B54D4539ADULL, 0x0AE1552B0AD3BE5BULL, 0xC841BC5CA5035868ULL
        },
        {
            0xA464442C2C79810CULL, 0xF926A27E656CB8BEULL, 0x7ECB05D94AF2DFCFULL, 0xB843C307B1F639B1ULL, 
            0x55E27470FABB6E5BULL, 0x2FC752B4FC8BE37AULL, 0x82A1D01D01080A70ULL, 0x52D17910B1A56AA9ULL, 
            0xC099849EEE393C68ULL, 0x7C066BC21252E662ULL, 0xA6E73AB92D777387ULL, 0xF3B233DFD9D6B548ULL, 
            0x69B36804C581F451ULL, 0x6B00D2AA77110FF0ULL, 0xBD0E0E19E3E961EEULL, 0x7D5262563FD86614ULL, 
            0xE45D20FA94DBE268ULL, 0x8524CCB51F55D1F3ULL, 0xCF829CF79C739583ULL, 0x3132B90267C6F30EULL, 
            0x369123DFEC10AF33ULL, 0x9CF7A99CEEF2162FULL, 0x00703DB9731D71EEULL, 0xA8DCBFC02F387394ULL, 
            0xF7D43A05A81B7968ULL, 0x50CC9294995BE9F8ULL, 0x2DFB1B4B6A8F7C4FULL, 0x66FF0B2C448929D4ULL, 
            0xCEBB9766AF329D0BULL, 0x6BB4A05BA1C656E1ULL, 0x3FB58A8FC0F148C2ULL, 0x2F874C1EB8D79C34ULL
        },
        {
            0x317346FBE28DD380ULL, 0xFFBBAE533BA22362ULL, 0x1CAFDDB8F8B0C6A4ULL, 0x100998AA89F8A40BULL, 
            0xC5176DA21E4D73A9ULL, 0x04B43CDEF7560303ULL, 0x876ECC83F0DA1208ULL, 0x19F6FBF759B14999ULL, 
            0xC88136D1CCB547C6ULL, 0xAA143EC268F785C0ULL, 0xE28EDA952294613FULL, 0x7203F9A4DA90072FULL, 
            0xCAC980C05544ACD4ULL, 0x10CA1DA1BCAE7808ULL, 0x08781E3F8F33DE77ULL, 0xBC369CB48079EB0BULL, 
            0x6BFF6FC90B89C946ULL, 0xA855B100E4E49176ULL, 0xC5A3C6D2217B1A82ULL, 0x393FFB6C59328250ULL, 
            0xBDD2FC19D906B504ULL, 0x7737CBC6C3217035ULL, 0xB153175C82DFF201ULL, 0x172AFF5EDDC3FD95ULL, 
            0xF74DB7EC05AC40E8ULL, 0x68C308FD8675C1B5ULL, 0xE3802C6A7D18B670ULL, 0x3F907B536A96C00BULL, 
            0x33E8EEA08497CF1FULL, 0x80565931FD3E5B51ULL, 0xAD9DA5288C76E064ULL, 0x1C03F31E282C3D92ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseAConstants = {
    0xE80FDEF72B35E7C0ULL,
    0x03AE7408DE5BADA3ULL,
    0x2E4EA7550E275CF1ULL,
    0xE80FDEF72B35E7C0ULL,
    0x03AE7408DE5BADA3ULL,
    0x2E4EA7550E275CF1ULL,
    0x4ADC3F15EBE8ACF1ULL,
    0x338600335566E263ULL,
    0xBF,
    0x73,
    0x67,
    0x73,
    0x25,
    0x36,
    0xDC,
    0xCC
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseBSalts = {
    {
        {
            0x0C26AA1239790132ULL, 0x3A9197477EB378F6ULL, 0xBE4F1CD865F84111ULL, 0x8871182602C29B0AULL, 
            0xF55452047FED96DDULL, 0x8C81938B12C10545ULL, 0x2594BBCC9A92D282ULL, 0xDAB36F0EA394A485ULL, 
            0xA5DDC41B264AA931ULL, 0x7DCED261B06F053BULL, 0x22FC86BE52341CF7ULL, 0xCA8BB62313777145ULL, 
            0x4398F9DCC4D540FDULL, 0xD634659DFDAEDF7CULL, 0xFC543ECECBC99E68ULL, 0xEE4BAE5C2A78784EULL, 
            0x9A52E022EE0BD97CULL, 0x69058F3C9ECD6023ULL, 0xB4695F063CA573E1ULL, 0x9F47D59709C8E0BCULL, 
            0x2DC5D91B43BFDDACULL, 0xE3B58704C8933E97ULL, 0x86E3F059F1DB0C15ULL, 0x18FBE8BFCFFEDDEBULL, 
            0x8A8FD20B2053256FULL, 0xFF7F6E89CF995ECAULL, 0xADB66D689BD4CC06ULL, 0x08352C7C3A5761BCULL, 
            0xD8C301499FA07805ULL, 0x77A8A26134B8D4B1ULL, 0x54BD83911B8EEF01ULL, 0x126E5635D45F0300ULL
        },
        {
            0x0E19E2844404F64FULL, 0x1991AB281679274AULL, 0xA7CFAB0D96E53FABULL, 0xDE0BD7976273ECA9ULL, 
            0x5F7200FBC6EE7D3BULL, 0x2E93B30FD83F1818ULL, 0xD296AA6F15C4D965ULL, 0x8CF3686BD56663D4ULL, 
            0x435B693E70807795ULL, 0x4018CBCD9D76BBD6ULL, 0xF0D7EE49F83DC0D3ULL, 0x5C68DEFEECFF14BFULL, 
            0x941568616D867925ULL, 0xC81661FC9CBA8376ULL, 0x60F8924741D88570ULL, 0x9F6FCD27AA7E5D00ULL, 
            0x805316160A6AF6D5ULL, 0x9DE31B0EB9DE825FULL, 0x1B62D3B146DAF9C0ULL, 0x3D28DCE693459348ULL, 
            0xF6C2C1901CDEB102ULL, 0x16E2DAFD153D89ACULL, 0x80FB56A13C576EDEULL, 0xDEB7F29640FD046EULL, 
            0xAC8F53D5AD3AD2BEULL, 0x48E9EA12B4E3456FULL, 0x89BB907E8B85FC75ULL, 0x0AF8E76524DAD559ULL, 
            0x8F33A2B671C9C981ULL, 0x768F9A73579F9BA6ULL, 0x4B54890C6777241CULL, 0xFEA81258A7B7FAA1ULL
        },
        {
            0x5B899739E1F0674CULL, 0xA7DABC999803FAEBULL, 0x1C53C7E5907D2574ULL, 0xCAE2CF70EAA29588ULL, 
            0x830F0B53EC819C25ULL, 0x2DB0560C6311CC42ULL, 0x4D1A2C5592DC9629ULL, 0xE3CE28DD28F98043ULL, 
            0x343564433F4BC6C3ULL, 0xB29D99DD1FEE866BULL, 0x0991C5F7E32EC684ULL, 0x684045EACE659ECCULL, 
            0x0D1CFAB3EF458DAAULL, 0x0203600FCE36596BULL, 0xAA16132224F073B8ULL, 0xBB5C03A1118A35D8ULL, 
            0x5EEB3918B2AC4AA2ULL, 0x8FFC5F327F36AC90ULL, 0xE077389CB7EBFDF8ULL, 0x8F492D20BF33D7CCULL, 
            0xAB01B2D9EED3D363ULL, 0x97A15D5F22F1B021ULL, 0x9A051EC1478C6A01ULL, 0xA91490DDD82F9DBDULL, 
            0xCD2BCB530EF8288BULL, 0x246DF591839821A0ULL, 0x50A5B36E003347CEULL, 0xC626693604AAFDACULL, 
            0xA386BF03DE4609D6ULL, 0xDC492B82485AD84CULL, 0xC0BF6FCAA1D28EA9ULL, 0x9F16C001B4FE7845ULL
        },
        {
            0xBC8C85EF980EE1A6ULL, 0xA734E8C9C3BFA7F8ULL, 0xF94B4891297404FCULL, 0xB23C93D82490D849ULL, 
            0x732A3EB48763ADFFULL, 0x479F5AD046F64900ULL, 0x111A1E92C3C35CB7ULL, 0x1006759C39E89E4BULL, 
            0x78F79945597EBCDAULL, 0x23764C6A718E77E1ULL, 0xC9FC75CFF3FEFDE0ULL, 0xAA3C010AA0D0B865ULL, 
            0x02D4F1C3F189185EULL, 0xA8C8C30C6C30D359ULL, 0x13F87D3F830A195BULL, 0xE1578202668AC544ULL, 
            0xFF2EEBC002F10442ULL, 0x4D08AE13F186FC36ULL, 0x07DDE194EC827D87ULL, 0x12C1231C24E9678FULL, 
            0x6C710BCB5E99B148ULL, 0x3EF5A454607F7354ULL, 0xA7F21E074D3257B2ULL, 0x06F3FFC6A85BD651ULL, 
            0x9FF27346B77FADBAULL, 0x523F8DDF9B90A631ULL, 0x00818A02676FA707ULL, 0x073BA526D66911EAULL, 
            0x73452CF8B17F16E1ULL, 0x2776C3581A868A86ULL, 0x5ABD9A7B4A0A24CAULL, 0x53797821FF46DD02ULL
        },
        {
            0xEF7817D215D20A5AULL, 0xD81D249948BAA12DULL, 0xF560061CA2D5348DULL, 0x72470555661FC65FULL, 
            0x7C513F2BA383F456ULL, 0xDA4DA6104EB4AEADULL, 0x00F770ECBC2E327FULL, 0x33A61136809BEDEEULL, 
            0xD7F8A9A2F8DBF290ULL, 0xAAE153DD46C5E890ULL, 0xA933E290AB391576ULL, 0xA014C917BC3696E0ULL, 
            0x351F928AF086C4F6ULL, 0xF7F816B7B80BAFF1ULL, 0x55BD1C402D42879CULL, 0x012180BB19F14784ULL, 
            0x029B20945BC8B671ULL, 0x5BA8446064790521ULL, 0xE96387887DC1D7E7ULL, 0x592C90A47156CE40ULL, 
            0xAB7EC1ABE04FBF03ULL, 0x6554730A6025E8D9ULL, 0x19E6F3E03A81FA9DULL, 0x294D8150241066B1ULL, 
            0x6EE4CEA4F4E45B6FULL, 0x750E50EAF6286CC2ULL, 0xF25658E49971A464ULL, 0xC406561FF732F899ULL, 
            0x6DA6757234BB419EULL, 0xBE73B9CFA17AB510ULL, 0x0682628F91B3BEF4ULL, 0xED0BD8E83E10C94FULL
        },
        {
            0x45C22DDEB27239A3ULL, 0x335461B81AFC0A18ULL, 0xC18F4F06DB8797E8ULL, 0x8A9F29367DF8F38DULL, 
            0x334046A7CDE73849ULL, 0x90B47855363F0BFBULL, 0x1EDC9701FEE20E29ULL, 0xD644021FD6D001ADULL, 
            0x319C2F80FFDF013EULL, 0xFD8F42A73D545A3FULL, 0x249C42BB226A78A0ULL, 0x56FCDE5D4B2878CFULL, 
            0x8B77BC3162178580ULL, 0x383EE9830E291F34ULL, 0x2D9AB3A672DACCBDULL, 0x981780F5CC1E798DULL, 
            0xE2926B5634BC9473ULL, 0x4CA42A016D015E2EULL, 0x7E79BD0D1DAB42FCULL, 0x40E20045DE77B79EULL, 
            0x5517AF8D64E851AEULL, 0x7118A7F1D2890EC6ULL, 0x88F0FA030EA0B9FBULL, 0x5FF5B124C0C5FB52ULL, 
            0x53B637DCD902C937ULL, 0x33550A94B7B43139ULL, 0x10F5B082DBD61AF3ULL, 0x44621094B025CD63ULL, 
            0xEE517225D8B55FE2ULL, 0x1BE4C4FFC354BE33ULL, 0xE16223DBB54754B5ULL, 0x71742D26FD96C712ULL
        }
    },
    {
        {
            0xDB3BBBA497592875ULL, 0x4C63DBD4E4F81AF2ULL, 0x771CC9ED66DACCDDULL, 0x546F84C08ADBD3BAULL, 
            0x18AFE48AE4118D9CULL, 0x047ECD93474756B3ULL, 0x4810103BEC4E2A0CULL, 0x3940B8DE8475BDD7ULL, 
            0x6163A5D178EEE1A6ULL, 0x50C866A46E975C8BULL, 0xCAA19CE09760E9B0ULL, 0xF5D2EDA3456DBDC4ULL, 
            0x3FF5E45BFAADF8EEULL, 0x2ADD2AF2570EB563ULL, 0xED209E6CE1FDA51AULL, 0x608BCE7FB2C56B85ULL, 
            0x8A22BB26580B568FULL, 0x973D501F6D1D7869ULL, 0x6A57027933954FBEULL, 0x4C528DE885FDA64EULL, 
            0xB982944729998EEBULL, 0x8041C8A3A5A238CDULL, 0x5706C99A05835AF8ULL, 0x044ABDDB74048334ULL, 
            0x93B9D22CA6126364ULL, 0xBE83C053BDD43949ULL, 0x60817EC88A18CE00ULL, 0x96CDA40E884A3983ULL, 
            0x2C44F9A3CF42332AULL, 0xF405E5A778C0758BULL, 0x966C64CED16A0ABBULL, 0xEBDB7A6B2F6D03FAULL
        },
        {
            0x9DFD9662B5E79ECBULL, 0xC50BF0147725A757ULL, 0x3373D8A0B3434121ULL, 0xE9DDC245121B5050ULL, 
            0x8F0498855A97A464ULL, 0xA8CFB05421F46668ULL, 0x15DFBF007B4AD2F4ULL, 0xA725850BE87AAD20ULL, 
            0x8EB416B7928ABB03ULL, 0x4A348B8B46EE2F9EULL, 0x5E58D5A0F38C21AEULL, 0xCDF648C4349F20A9ULL, 
            0x8B2A20384F0C0187ULL, 0x01CB4EAA6E38065EULL, 0x074EE06ABDF15EF0ULL, 0xF21C32EF758D3BADULL, 
            0x8696E7B2A4379BDAULL, 0xE2B30D60F699EC77ULL, 0x86074A256F210897ULL, 0x803A98874273F6FEULL, 
            0x0567689AE4688706ULL, 0xBF2AECADD6A3FAB7ULL, 0xD059F8FD62B96891ULL, 0x0AAD4888B7B3EF16ULL, 
            0x523334B5BD0181AEULL, 0x464A708630189540ULL, 0x703035577A90F879ULL, 0x38875235D3C1F803ULL, 
            0xC59AD1DF042CB861ULL, 0x5F1D7EE3124949D6ULL, 0x645FD6184DA96BB3ULL, 0x9417572ADB70F6C3ULL
        },
        {
            0xF5140B826DF6CAE4ULL, 0xA2235EE3379D253EULL, 0x9BC57FC4D25E7C9BULL, 0x0CA1AAFA0C294EFAULL, 
            0x627692DEB261894AULL, 0x209719C306B03181ULL, 0x1F0C6E9430C25D58ULL, 0x8DEF73EA5C99939EULL, 
            0xFB938E305B652DA4ULL, 0x7A5450DCF1802BB6ULL, 0x602EE7B8E11CCF99ULL, 0x3E23AFBA188A2BFFULL, 
            0xFA941522B8FB4D2BULL, 0xC9E641FAC263570FULL, 0xDFEB86561548E1A8ULL, 0x0E04FE67EE438261ULL, 
            0x11578D2631D08410ULL, 0xC24A3C90F3446702ULL, 0x1EC68C1605BCBBA3ULL, 0xF6468C3AD3C59FC7ULL, 
            0x70ABE4F427662477ULL, 0x97F66A941B6A7D1AULL, 0xD801259C14AD6D3FULL, 0xDCD516127A37190AULL, 
            0x780DA1C7C7F4DA68ULL, 0x14FC9D45D0D11CF4ULL, 0xB10FFD4DDDEFFF37ULL, 0x5CEC3B9FB2504AE8ULL, 
            0x191335A045D92EC5ULL, 0x270D40B923EEC668ULL, 0xF5E32C255BE2F304ULL, 0xDF3FEAD549EB31DBULL
        },
        {
            0x4CA4C005940795CFULL, 0x1619081FF796689EULL, 0x23F05108B2ACAB35ULL, 0x1F3305063949EAEEULL, 
            0x889C7C2A0A342226ULL, 0x2D9E2380FF7B16D2ULL, 0xE099DDBF524C10BAULL, 0x6F24BEA7EEE0D0CDULL, 
            0x4F42E6393161FCF9ULL, 0x96EA1090FB25CC20ULL, 0x1DE4A6E5482E9562ULL, 0xEEE55DE6CE00FAF9ULL, 
            0x0E1980B03C98944FULL, 0xC4DC86A253DC6F66ULL, 0x7F5821E6EC07D127ULL, 0x83C08D43655D98E8ULL, 
            0x9159F9902C631DD8ULL, 0x509181D2701D3669ULL, 0xB6D9CB4F5CE21A02ULL, 0x14CF45A7ACCA693FULL, 
            0xD3ED12E61866CB84ULL, 0xAFA54A287BE557D6ULL, 0x84D210B70EFB221FULL, 0x546E925569F40A6BULL, 
            0xB33754945B2763A1ULL, 0x5E07C6FAC7354D67ULL, 0x54962BEAA4607BEAULL, 0x47BB4BD84FEE27D0ULL, 
            0xD926BA24F380E248ULL, 0x5FD7A4D174321633ULL, 0x8B563EF08934F089ULL, 0xDD0A6CA7F38C2DC3ULL
        },
        {
            0xD7F60BA5CC1324A6ULL, 0x3FB22975540C2016ULL, 0x3751E6B5B7FB42A5ULL, 0xF66347CB9638F073ULL, 
            0x176B7B6472B9854BULL, 0xCEB23072853A2867ULL, 0x496CF2F00C45202EULL, 0x0F2A66D7E324A530ULL, 
            0x99CBDA4C6715E65DULL, 0xD5ABFB00A996BAD0ULL, 0x8C1D8A55BA4B241BULL, 0xC8CD5571F51DB61CULL, 
            0x0C5400E3BB276C4AULL, 0xDCB6E77CCC7A7E29ULL, 0xD29F8986D1B00C85ULL, 0x8DCBD6FE89FE014BULL, 
            0xDD01030E2E285860ULL, 0x02DC24BDA10D5DE7ULL, 0x2684C7AD7407F70AULL, 0x86A519A32152D18CULL, 
            0x4EB56DA20A6E2CE3ULL, 0x923D30F25E800416ULL, 0x0D28BAF907652F05ULL, 0x6FABCC0AACF85695ULL, 
            0x6A78A284B8BEF683ULL, 0xF80475FD8A81BF12ULL, 0x7B718E8EAF193600ULL, 0x4C9E2AA489F42061ULL, 
            0xAB7C1335F2F7104BULL, 0x82A59A60B96320A5ULL, 0xE137982AD43C95A2ULL, 0x8FA4D2735B4CD34AULL
        },
        {
            0x9992669446B64E68ULL, 0x554734B71293B686ULL, 0x37D19E33D5ECC898ULL, 0x0F90DD604A2766D4ULL, 
            0xB7D71322B6F77598ULL, 0xF345F6BB61F5598EULL, 0xC27E2F9DA9C4CA7FULL, 0x53AAAB70407D33BFULL, 
            0x3F525EE42B7DBEEEULL, 0xDB14C0E0C39432DFULL, 0xCAAD293A7E380117ULL, 0x8E46AF1289AA9F7FULL, 
            0x61724F8AD02FB90AULL, 0xD70AC5E31CAC7F45ULL, 0xEE1D906C583A57FFULL, 0x6003A0D1C15530F3ULL, 
            0x3B8CE8EE7118D155ULL, 0x1F77F29DD171E5E5ULL, 0x71F4FADE896DD1CEULL, 0xD8157751DB45A8B3ULL, 
            0x587AABC67A3ADED3ULL, 0xF882230630888996ULL, 0xA6A67C1B8D0B3E53ULL, 0xBA51E5656E97FEECULL, 
            0xE469748B36B054B7ULL, 0xB0D75B49133C633EULL, 0xDA3E38C371EF2DDAULL, 0x924FA05845F3F1E2ULL, 
            0x98207EA557DF0331ULL, 0x000A1904610D7FFAULL, 0xD7C613B05274DBF3ULL, 0x8ABB3A061DDC34C9ULL
        }
    },
    {
        {
            0xB1BAB23838D8E767ULL, 0x42AA430F148FC297ULL, 0xCAD29F36AF743A39ULL, 0xF0A8F0AF4DF83FABULL, 
            0x9F8B2B8DCF14CFB8ULL, 0xB7F37D649E9BCF89ULL, 0x23931ACCCD297BA8ULL, 0x79246EFE3FFD6649ULL, 
            0x4D835ACAA150625FULL, 0x4333045907C5A349ULL, 0x22B155FA1EB0ECD6ULL, 0xD7F5239F361F3FA3ULL, 
            0xF62432729065E51AULL, 0x61F7A02838E2D3DEULL, 0x16C16FF346556AC2ULL, 0xC12DF8F0BC7BC8D4ULL, 
            0x9EF33411CD8A255DULL, 0x61FB17B023BC622AULL, 0xFA56BB751C5DA81FULL, 0x5C7BD72DA1253354ULL, 
            0xE944CA684A292551ULL, 0xF0E0FF1D9EEA16C5ULL, 0x7EC138A4476473CCULL, 0xA4E3140445699D85ULL, 
            0x67AE9BA8C0F99A4BULL, 0x733F4949401E112EULL, 0x484D16D4A62EDA1FULL, 0x05016D66E930403CULL, 
            0x4B82919573405721ULL, 0x3593DA0CC37B1694ULL, 0xB6D0A13587AE625EULL, 0x1DD33814623219E5ULL
        },
        {
            0xAA50508C2763210BULL, 0xC32DA7BBE6BD3590ULL, 0x62D3CCC04EA4BB28ULL, 0xBCFA4FEE6D6A233EULL, 
            0x12B1258E5A9E8B72ULL, 0x12B371C05F8DA235ULL, 0x90F87B7D9067E5A4ULL, 0xAA737CD01172B28BULL, 
            0x022012C2C54BD303ULL, 0x51011AA273770227ULL, 0x6F1E947CF39FFB7FULL, 0x0D84EB689349419DULL, 
            0x6BFB43DE9615DDA6ULL, 0xEA7D7194DB8AEE3BULL, 0x6E7E937D3200E611ULL, 0xA2EAE3AFC40581E4ULL, 
            0x6F3CBB0C8054DE6CULL, 0x9C424DB564FB8EACULL, 0x5C5EF9268A059F0FULL, 0x9C22C85B85FB936BULL, 
            0x3A00D9C6304A8D62ULL, 0x5A6CE687D0C84E7EULL, 0xE3B01063C4E600ABULL, 0x88CCF0AAA4630375ULL, 
            0x84B60CD34DFE29CCULL, 0x0DD489671FDFC857ULL, 0xE713353800C4DF8AULL, 0x6066B9ABE2197633ULL, 
            0x41E2BEE5B82D0F6AULL, 0x211B4D48C3A7044FULL, 0x3A34CC083CE254BDULL, 0x4DE2CDFCEDB7D488ULL
        },
        {
            0x1D5EB7AE4A88C39EULL, 0x9F955587ED551383ULL, 0x9F67E0B5FD809C78ULL, 0xF2F8FED2026B1688ULL, 
            0xB88FACA4118BCD49ULL, 0xECF2B75109C3AD8BULL, 0xAE3F08233E44A779ULL, 0x6CFA2B38A8450D05ULL, 
            0x6910733D97D8B982ULL, 0x980DA6D47BA7E6B1ULL, 0xEF34AEC45A5B236CULL, 0x6D83CDAE927C2A31ULL, 
            0xD4C5DB00BA31223FULL, 0xC9631E1BD31BCD1BULL, 0x8ED9DE894CEFE880ULL, 0x387771C7251DFBBBULL, 
            0x8CFDB7DABB1B8A80ULL, 0xCC212749177EC386ULL, 0x6F9A6881277274BBULL, 0xB8E3CB3324829B60ULL, 
            0x49A3625591F41B31ULL, 0xB675CA4E1B2A8C21ULL, 0x7E24C0E640D43EF6ULL, 0x25EBF4D856A41D84ULL, 
            0x4430327F5911C6ADULL, 0x9511DA89DD05A90EULL, 0x4B18CAF7F28BA71CULL, 0xAE6F4ACA00D8006EULL, 
            0x3E0ED5E6C80E86B3ULL, 0x805FF5AECEED07A2ULL, 0x58E4B4457B824E75ULL, 0x5F18425B879D95D8ULL
        },
        {
            0x162ACFAF3FCF496BULL, 0x6CC42351DAFED408ULL, 0x6AC2824339537B3FULL, 0x29F329347A34063AULL, 
            0x9EE61783D0EE13ABULL, 0xE04B21966680F068ULL, 0x7493DF20E4DF7E1CULL, 0xF2CC2A6D47C22A88ULL, 
            0x78213646DAF4566AULL, 0xFB85D50FD0FA2172ULL, 0x8FC5E45DB8BCE86AULL, 0xD7B9DA4EBDB03796ULL, 
            0xDFB67C8C14E59283ULL, 0x020F101B75764F5BULL, 0x3D769C2A25D8F8AAULL, 0x64FD9774D4367257ULL, 
            0xAC4E9E90F481D6C7ULL, 0x996BEA63556F9C95ULL, 0x9C45B269EDF74940ULL, 0x3596735C9202BA85ULL, 
            0x9BC753F2A96D1499ULL, 0xB8755B0E4F21562EULL, 0xE5F97CCC021994ABULL, 0x3B9E4AF0596D7C0BULL, 
            0x3ED455352FF751F4ULL, 0x8E18E0711584417BULL, 0xBCE4C5BC9A43DB81ULL, 0xCC3E895D02DF1F1DULL, 
            0x7F9EC96B01A89B1AULL, 0x80AEFD9771AA4B11ULL, 0x5E9BE6DE1386BA62ULL, 0x6276F821B70F781BULL
        },
        {
            0x07BDB0EEE186C124ULL, 0xAE500D427A0D61D0ULL, 0x3B99BA0E1BC20FE8ULL, 0x1C55CD14CDDB10CCULL, 
            0x9089607A03E20352ULL, 0xBAD656AA70E61930ULL, 0x116F752D7C050619ULL, 0xB1BB5D7D6DAAD4ABULL, 
            0xE132C73309EC0E7EULL, 0x2C80172EFE34BB73ULL, 0xD9884F913207B2DAULL, 0x93E206B506DE2FFAULL, 
            0x9C6008FE52FB79AEULL, 0x07EECE57513F2482ULL, 0x864E704EB84F2F78ULL, 0x39ABEB2765AB4CDFULL, 
            0x015520D5EE08CABCULL, 0x4F3E0B7FA4EFB56FULL, 0xC0E0718E6D957984ULL, 0xB1769AFF31B2104AULL, 
            0xF287F27DB9CC195FULL, 0x56C6A140260AA45AULL, 0x5F2E3FEF866A6FE2ULL, 0x1D2B61EC25885DF0ULL, 
            0x329EDE12E19C7B17ULL, 0xC99182AD147A357AULL, 0xF8EFABC9304086A5ULL, 0x4EB27ED3098FBADBULL, 
            0x480A99A79BFD8BE4ULL, 0x083739DA1A141851ULL, 0x1B26E07B9D60AA83ULL, 0xF886C6AB13FFA641ULL
        },
        {
            0xF7A3D8D21994BFDCULL, 0x3901F54475171FCAULL, 0x783C9A7E66A00B7FULL, 0x06D1E83EC194F4BCULL, 
            0xF075BBF7FDA2347EULL, 0x0824C6BAAB16AA5CULL, 0xF803673FBDF5F875ULL, 0xEDD483E79369B0FDULL, 
            0x816F7F24D1A2C323ULL, 0x4BFF2FC8372C5A19ULL, 0xC41A0CA2B07351B1ULL, 0x3F1AAE6E3E209783ULL, 
            0x8B9538A43C18BDA1ULL, 0x70C840D00EAA398FULL, 0xAC43643B78DA4EEBULL, 0x7DC28CFD80AC339EULL, 
            0x244F399FDE9F32AFULL, 0x46E387B0F0D5C248ULL, 0x65AB9DF2BBB9A5D4ULL, 0x3C4FB9006B5FA1BFULL, 
            0xC982D8B54ECEEE22ULL, 0x0503E233B9DF6751ULL, 0xA1F9890A5363FB72ULL, 0x3A948537F64DC869ULL, 
            0x300FB9DBF4F012F9ULL, 0x72A5B883BA3BC2BFULL, 0x1C9595DE0FEAE0CDULL, 0x6E8128B955A03DB6ULL, 
            0xE90A3D2FEF323D08ULL, 0xC36D09A029DF7F87ULL, 0x9E77F01FC0FE71C2ULL, 0x75F34F1F5F6CBBB4ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseBConstants = {
    0xD2682222B0CC5152ULL,
    0x3C5F4544F286FCE1ULL,
    0x1E61BF29889AD61FULL,
    0xD2682222B0CC5152ULL,
    0x3C5F4544F286FCE1ULL,
    0x1E61BF29889AD61FULL,
    0x4CF51B40A7D7261EULL,
    0xD3F2972D90E430C1ULL,
    0x13,
    0x6E,
    0x66,
    0x79,
    0xB6,
    0x10,
    0x7E,
    0x80
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseCSalts = {
    {
        {
            0x0E018309A34A0D7FULL, 0x898EA7D44F868C22ULL, 0xC41D14F59D2D95F4ULL, 0xC87031AD9BCEE2D5ULL, 
            0x941B66413E17E130ULL, 0x9EC7E4C018DE9E98ULL, 0x8ED730A50ED03B60ULL, 0x3B5571AED3804945ULL, 
            0xFD7D7C39E026FBA2ULL, 0x821F7B8E6E628376ULL, 0xFFEF9933B4D84A71ULL, 0x49E249F3A0F6F3FEULL, 
            0x5D98B8116235250EULL, 0x22E5D3C7DFBB7BBAULL, 0x73DA4B0D31212938ULL, 0xBB244AE5D4B490A2ULL, 
            0xE3CD0BBBC3051CA6ULL, 0x49867E98BD13B0BFULL, 0x997CB68CC497F76AULL, 0x473A469F4D87E933ULL, 
            0x3A95EBCC4B5FD848ULL, 0xCE031D063F618762ULL, 0x7310E88C30E40AAFULL, 0x3C2A62B0A5F0D95EULL, 
            0x410BFFF07EDFCDE8ULL, 0x5A2DA60752042975ULL, 0x31E7D1B717B115BCULL, 0x74768284886D2246ULL, 
            0x52DCEEDD001E37B6ULL, 0x365DC999AD41724FULL, 0x3A2CB9064203878FULL, 0xC5915B424B4D8929ULL
        },
        {
            0x56745CA22440D4F9ULL, 0x3F3749F888641852ULL, 0xE3BE603A3B4F883EULL, 0x7A4076FBEBFDF497ULL, 
            0xBD391EA4762FAB06ULL, 0x63AB325EAAD706CEULL, 0x58A0AD763B937A26ULL, 0x7686A3B65D01FAB5ULL, 
            0x2561E486CEBD0AA3ULL, 0x0C4A8BEEBB125B61ULL, 0xD8C9E4969BE72309ULL, 0x8347484FA2A45182ULL, 
            0xCF5108EAF1F511B9ULL, 0x760985D2161F2EC1ULL, 0xDD7D4A6AF92BEB99ULL, 0x224A4C9CF5AD4627ULL, 
            0x588FBF9A79BCEC3AULL, 0x6E9644CE59651B8FULL, 0x94C0473518FC0AD5ULL, 0xA15CEE82C978A36EULL, 
            0x0FCCF274298CBD9FULL, 0xEBD552CC35E1EB58ULL, 0x36369E8BBF5387D7ULL, 0xB013E390397C4AA2ULL, 
            0x0A1220870C13EFB3ULL, 0x4EEA3EFBD75BCC51ULL, 0x715600C2DA0A14B8ULL, 0x7CF8EBA5B61D4857ULL, 
            0x6A8D582FF66CB4A6ULL, 0xDCDA1FDD5C9C77D7ULL, 0x334386C2606848B3ULL, 0x08B63AF81027CCB3ULL
        },
        {
            0x5453A72E676A3951ULL, 0xF6AE040D1F067C88ULL, 0x85A10326312241D7ULL, 0xAF075E64DF15B5E1ULL, 
            0xB362EDC0D78DD4ADULL, 0x4953070496E34F31ULL, 0x87521142540BC1B6ULL, 0x264FB23C98026D4DULL, 
            0x611AEFCCAC455947ULL, 0x256AB124CAEAAE4FULL, 0x9E448BEAA3CA6AEEULL, 0x7029C5D4CA71A4EFULL, 
            0xA8371D7926F2BEC7ULL, 0x9AE3FA090AF7AD62ULL, 0x93945EFD987454DFULL, 0x916C537772EFF813ULL, 
            0x8864D1D0FF776A80ULL, 0xF7DF252997E14477ULL, 0xF4D68B08221FA255ULL, 0x4F1FA9B7155583DEULL, 
            0xE591D747E352BBBBULL, 0x00B0663D2B9C1F35ULL, 0xC9FC6A79B3784BEDULL, 0xF86C99BB45499ACEULL, 
            0xF858B13756960FE3ULL, 0x4C25E727321F7154ULL, 0xDB9C4DE2C5566F0CULL, 0x19E5D50D8BD17B01ULL, 
            0xEDE186D8EFF76DA8ULL, 0x155C521A982DAF1AULL, 0x2869246750782484ULL, 0x0F31049E3E1F6037ULL
        },
        {
            0x9B99C171481CB2F5ULL, 0x4761BC620429002CULL, 0xA81AB7E00352FBF5ULL, 0xC9D39CE1957DFB2DULL, 
            0xA76B6C70E364D1D0ULL, 0x4171C2FBFFC195F3ULL, 0x284976C99205B26CULL, 0xC6DC2DDD8009DA34ULL, 
            0x7E7B4FED4A4CB527ULL, 0x7041110D24597812ULL, 0x410CDFF2F30B157EULL, 0x5750D0A9171B3175ULL, 
            0xB5077BEB35E63DAAULL, 0xA16B1FA27E6717ABULL, 0xDA26F7E9890F4515ULL, 0xBE9B60CC55C7F1D0ULL, 
            0x104EE4308E4E4B4DULL, 0x6A6782663F863EC8ULL, 0x67A5C3390BD57176ULL, 0x07BDD0CD38E44BA9ULL, 
            0x59FCFA8EB624E489ULL, 0x41379C6BF2EF298FULL, 0x919CDEB35E1F44B5ULL, 0x8D1F94FDE6C69E44ULL, 
            0x7D6F908FBB9AA321ULL, 0xB0DDCDFA49408FF3ULL, 0x68E37CA2B2E508DEULL, 0x2A308112CEC695FEULL, 
            0xC65374C5CDF008ABULL, 0xA52028E839DF3DC3ULL, 0xDD03E97032AC8B5CULL, 0x0DF4E78EDE758E5AULL
        },
        {
            0x821D6AE522A3C6EEULL, 0x67F4D778FB7E899AULL, 0x2B7F370E52D17E20ULL, 0xBBD7A214BD30737FULL, 
            0xF5B0BAC14D38CB1BULL, 0x90498AA85E4C4AD8ULL, 0xE376CFE5D167FF4CULL, 0xD95FAB4FAC7E687BULL, 
            0x8B8E9AF1754A7C25ULL, 0x17EC43AD4809A837ULL, 0x1CB4DCC24357B013ULL, 0x3898ABA2C6B8B54CULL, 
            0xF72B016639CEE686ULL, 0xB3BAABB65CD03467ULL, 0x834376FF5B75C399ULL, 0x380D38B66BEB198BULL, 
            0xBAA430A0A673BB98ULL, 0x13A5328645227DB3ULL, 0x1B33EB51937AF7B4ULL, 0x6EB1E4996935AA29ULL, 
            0x1276576DFC069CD4ULL, 0x052B471CAA8D3952ULL, 0x01FDD37FE9F25905ULL, 0x9A61353F1D066ACBULL, 
            0x1F3E9156D4892F42ULL, 0xF888CF7B9161C5D5ULL, 0x204BF9043453713BULL, 0x2AE8025DBB4000CBULL, 
            0x41E920F846471FF2ULL, 0x67B11BCF89953C58ULL, 0x2C7A085AC5244744ULL, 0xAD8F10C4D424F454ULL
        },
        {
            0x89590E4E0CFC90C1ULL, 0x311E3733E9298736ULL, 0xC240E9C41347CE98ULL, 0x96EEE8DC778E93FCULL, 
            0x8882085AC0B56B96ULL, 0x4A8FD717DE99679DULL, 0xECC7EBAA18D29992ULL, 0x70352E60504D34AAULL, 
            0xC1EF594D5609F22BULL, 0x375F6032B1EE8E36ULL, 0xF9656D4F43101A9CULL, 0x8976108AF6509108ULL, 
            0x9B549E98BDD741BBULL, 0x5C5F442255A7FC35ULL, 0x4A52791CE6AA10F8ULL, 0x5AE671A3744877C7ULL, 
            0x154FC895B3BCE4FBULL, 0xFC141764B6A8CCA5ULL, 0xF9B432AF52EE1B1AULL, 0x1FD9BCDAD1184459ULL, 
            0x621AFB65ACC27C0BULL, 0x9FA1502E8CBA8C03ULL, 0xE16B5A3E5EB994BAULL, 0x287AAEEA9460E49CULL, 
            0xCA17C474FA992456ULL, 0xA2E9EC70C93E51DCULL, 0xC67EFEAD127D9189ULL, 0x10BF0F4B3A030894ULL, 
            0x649C071D4E264251ULL, 0xFE08D1A33489C427ULL, 0x9AAFA4A15EF6C51AULL, 0x0BDD4189A644A588ULL
        }
    },
    {
        {
            0xEC7D93A687ADE012ULL, 0xC5950C47073DB58AULL, 0xA6F2F02A5B08D762ULL, 0x29FAB5FADF903453ULL, 
            0x1BD4CB6B755AACB7ULL, 0xC43949A7531AF40BULL, 0x6CE35EE22B03927BULL, 0x29A7BA9D46DA2291ULL, 
            0xCD4F4E3B449E7088ULL, 0xF32A660BE75B9411ULL, 0x0D43404D1F4817A9ULL, 0x208771389EDCFF6EULL, 
            0x8B5E490D7D459A1AULL, 0xDFFDD5247EB598A7ULL, 0xBD7321C42E746A0CULL, 0x17B8A38AB53C9935ULL, 
            0x0EDBC87DDC5FEE77ULL, 0xC0442AA8D794C7C5ULL, 0xBE70B8FC83B03E60ULL, 0xA891409A51A4957FULL, 
            0x30AA5FB9E5C0316AULL, 0x93FBF94F70F07972ULL, 0x92CFE482A155365BULL, 0x26E48F9664D227B1ULL, 
            0x5790668F8EF87B90ULL, 0x71CF10C378069F2FULL, 0xE61E15B7F1B77D32ULL, 0xC7DA938CC969AFD1ULL, 
            0x837EDCB21405B3D5ULL, 0x699994EDF9CC84DDULL, 0x98D8115511BD1D6DULL, 0xA231B23D45C70D85ULL
        },
        {
            0x22DAA73EAB253B6FULL, 0xC92CAF5A3B2515CDULL, 0x0618018897958F3AULL, 0x861347E3EC6E4FCCULL, 
            0x711890EF363BCC73ULL, 0x720B7431570AEC30ULL, 0x5D9CA91DCB8816A5ULL, 0x336024CCD56F44D0ULL, 
            0xC4267D6BADD9B06EULL, 0xEC3AF7567F3D7D90ULL, 0x74D352DC3EEF1894ULL, 0x7E984E632BCE0E36ULL, 
            0x0A7B905CB3C0B49BULL, 0xD363CF9BC78789E5ULL, 0xFB1F5DB52CB7032AULL, 0xCE275558B17B627AULL, 
            0x24453BFC0C5435A9ULL, 0xA930FE6BCED3197AULL, 0xF63CB1E94C59AE44ULL, 0x4D7E6287372A59B9ULL, 
            0xB85AE2AB2E9D19ADULL, 0x6E3686701AE4740EULL, 0x4C57EA0921FFA45AULL, 0xACD67FE70A3C56FAULL, 
            0x3DD7FB38C2C944A3ULL, 0xDB28954E3478B163ULL, 0xEDCD73F440D69C8FULL, 0x2E1DA9B665A7C7DEULL, 
            0x6449E1985CD2F03EULL, 0xF9996855E291A675ULL, 0xB3E6C72286AB2508ULL, 0xAFF1F0CFA55A9674ULL
        },
        {
            0x4BBF4B3EE17E3D9FULL, 0xEEDBFB8D5F5EBF66ULL, 0x4526576ED90DD710ULL, 0xD1395B476501D254ULL, 
            0x0218615C1AC6B3C1ULL, 0x121D513D3B7FA123ULL, 0x3B911D163C646EB9ULL, 0x16527BF4116DC507ULL, 
            0x6F5F113CD0016F04ULL, 0x25C4AF80946CBCEEULL, 0x447954822939A809ULL, 0x11796A999FE6C7A1ULL, 
            0x21E09DF7EBDE67BAULL, 0x4DF570AAC85BDF7EULL, 0x9C44BFCA0FE8D5ABULL, 0x9DD1E68F206BF025ULL, 
            0x88056D3DFE953B35ULL, 0xF3BC4D462FC8B893ULL, 0x3BF7B22B380185B2ULL, 0x3A0FDD72C6829635ULL, 
            0x6FD202050F3F75FDULL, 0x4F68EFB2C4E8F4E9ULL, 0x6219A76EFD4399A8ULL, 0xF9CDBFCBE383CE36ULL, 
            0x75BE9CDD8079A76EULL, 0x8F99CB4B99E51DCFULL, 0x114BA3B157EC6E04ULL, 0x5AA8260107F990AEULL, 
            0xD9BF535C7E0F5239ULL, 0x70644CF79BEACDD5ULL, 0x80B7103564D30402ULL, 0x96556A130ACD93BAULL
        },
        {
            0x6867CCD0886C558BULL, 0xA7144839F99D4410ULL, 0x2E68EA7597DB6E84ULL, 0x97D0F7D7C50203EDULL, 
            0x6A76DA02C80ABADAULL, 0xAC0FD2D4BE033D16ULL, 0x003970908AB8EC83ULL, 0x528436822B9BE508ULL, 
            0xB28A08A37D10CDBFULL, 0x9A3163349C646B0EULL, 0x827797932F418372ULL, 0x479495861DA9FE56ULL, 
            0xB9B15D1CED222FE3ULL, 0xE6946F5794416E0FULL, 0xD7007A7086A336ADULL, 0xBC50B403FE5E7A24ULL, 
            0x500030F2C5FB1D68ULL, 0x8CD24DF070EBCA24ULL, 0xF4B997E12504880AULL, 0x1DE706EEE48C0461ULL, 
            0x8F5FB24BFC3EA9EAULL, 0x26DC100E95930806ULL, 0x393E7C61BA1EC6C0ULL, 0x5C0208406A58E075ULL, 
            0x1BDFCAF1D6D0A9DAULL, 0xD3D64E2B47994159ULL, 0xD37EE7AEFA530315ULL, 0xD261C6A64B7DA91DULL, 
            0xCD980873928699DAULL, 0x3B0FEA675C765AECULL, 0xC69ECFAE42737BC6ULL, 0x8DE94814338DC0F6ULL
        },
        {
            0x2011BC5898000739ULL, 0xE87B263D4479D60EULL, 0xA102E7CD6433B8B0ULL, 0xA008CCE10D4C498DULL, 
            0xA5888FC157D8BCA9ULL, 0xDCA74216B3230CE0ULL, 0x068702090638DBBDULL, 0xE8857FE0DFEE7863ULL, 
            0x8D55D5687CCDDA0CULL, 0xAB20315435D00D01ULL, 0x4DDD3F734A8A2488ULL, 0xCCF7DFF4EF6A035CULL, 
            0xA16FB6F0E62160FFULL, 0x22A43D98264A4B92ULL, 0x9A3F0C12C14EF8F1ULL, 0xEE1DD90BADC027EAULL, 
            0x87EB94E4FC14D143ULL, 0x27360584714DABBEULL, 0xC9BCEA9D6221C56BULL, 0xF15316EC8321D2C7ULL, 
            0x8DF6CB0773EB9878ULL, 0x70A81991B8ADFDCDULL, 0xDA6B7864DA4A61CAULL, 0xB1FFB96FF0F20208ULL, 
            0xB892A1C09345ABA2ULL, 0x5613084A204C732AULL, 0x2013FC3C9B561494ULL, 0x436726A749CE4040ULL, 
            0xCDF0A4750C0C5AD3ULL, 0x272219312F45B088ULL, 0x99A24AEA97D72017ULL, 0xE6D0C2ACB8370782ULL
        },
        {
            0x922806061A221D1DULL, 0xB072F66384D3F182ULL, 0x81F3B88E67016685ULL, 0xA91401F6355F63AEULL, 
            0x6346B90E6C3971E7ULL, 0x1B71C0227009FAB7ULL, 0xEAA83C15F8EC9831ULL, 0x6B103A3A76AA80E5ULL, 
            0xB572C6BBB0B31BA0ULL, 0xDCE73F69F9D4C6ABULL, 0x411FC49DAB8BD607ULL, 0x7A89336154B4C87CULL, 
            0xD8D44A88AC88F227ULL, 0x07DFA338E33297F1ULL, 0x9D60B0143BBD72ECULL, 0x6FD46158D5A0CF85ULL, 
            0x33639A97F0911AC3ULL, 0x8CFC352E64C896E3ULL, 0xA34B9D4D617003F2ULL, 0x30FD2A0599F6574FULL, 
            0x44997F516ADFE155ULL, 0x29B68D4E8CA21B6BULL, 0x5078D468DD95C2C0ULL, 0xA858966E2B2F6032ULL, 
            0x66E807254F745EAAULL, 0x3468A9EFC359F95AULL, 0xB164FA2A607A8000ULL, 0x242F9079CBCB5D59ULL, 
            0x0361D0241278825FULL, 0x6BDDF088E801192DULL, 0x6596883257EC02FFULL, 0x075DBFA9123A7659ULL
        }
    },
    {
        {
            0x0FAAF284E8473591ULL, 0xCA241F328164A23CULL, 0x4E35CAB70D571735ULL, 0x91B662E050A6584EULL, 
            0xBF8FCE8BA7482B4EULL, 0x4FD28216823840FBULL, 0x83A0E25ABD25B77BULL, 0x1634D048E7CA4799ULL, 
            0x5115312BECE33DCFULL, 0x8455F02D0E5B4DEAULL, 0x1E7611A96E58D574ULL, 0x73CE897B5D5A04D7ULL, 
            0x847A0B63F1C8444AULL, 0x48740934D04CDEAFULL, 0x37DE19A8444B3C82ULL, 0x48E2EEBF636CE9FEULL, 
            0x4E597F693121EEB8ULL, 0x6D2F09398E06B798ULL, 0xE9F09AC1FD95788DULL, 0x942583E6D5E48797ULL, 
            0xAC15695819AFE4CBULL, 0x6899B216DF974903ULL, 0x0F09DE854A41D578ULL, 0x63C4452DEE7ECCEBULL, 
            0x7E24BF34D9C1A87BULL, 0x182DADEEDE0D9A09ULL, 0x9F3E826937E302F6ULL, 0xB6E8045C9F148E11ULL, 
            0x145C0E8B3A79D4A9ULL, 0x43FB8FE5E997B6C3ULL, 0x2C188042A3039E2CULL, 0xCECED0D8BCC34074ULL
        },
        {
            0xA27583D210574EFBULL, 0xB24BBC7FB2504A83ULL, 0xD4178FE5C7CD7528ULL, 0xBE232613E93F0E69ULL, 
            0x018DB2CD27C14E10ULL, 0x359A8724E0445D2CULL, 0xD952EDB4B9E5903DULL, 0x99DA6A3B86463258ULL, 
            0x7BDA86051E5F86ECULL, 0x4EEA244DFBE2B320ULL, 0x65D4480A589F6272ULL, 0x7ECF17B37A5A71FDULL, 
            0x796BBE707E21A65EULL, 0x76709863BEB04FC3ULL, 0xF4D5C14305015652ULL, 0x9812453BF0AD3A57ULL, 
            0x4C6492A838EEFFEEULL, 0x137053B9B7639A67ULL, 0xE8B0DFE3F2DD9750ULL, 0x27D7D40B6ED2A9AAULL, 
            0xE9A3643E6CBA7614ULL, 0xDB2F9B1AC439369CULL, 0x10823815FC1D1012ULL, 0x0CD5E412E287E628ULL, 
            0x90539828455FC29DULL, 0x216DB08B84929003ULL, 0x762E9F181B7947AFULL, 0x71433103DE45A10AULL, 
            0xD3377675EB8B8F4FULL, 0x1DDBBE55192CA46BULL, 0xC0E75818F6F1FB2DULL, 0x7B9712642A690F1BULL
        },
        {
            0xA50F8AC1EAE8F5EDULL, 0xB9D459CD6652E7E3ULL, 0x23C6D2F6F845630CULL, 0x33BB3F30C9BD12BFULL, 
            0x0D4BFB19E0B68DA2ULL, 0xE753A75319D1B2D4ULL, 0x938D3EDB44F4BBBAULL, 0xDE778F57382C700FULL, 
            0x9511F51BA366DA18ULL, 0x7A2E257BA5672935ULL, 0x8F23654BEB270A13ULL, 0xC374E371FFB3EF4AULL, 
            0xD5DA20E78E0BE668ULL, 0x415FB98B4683AEE5ULL, 0x9BA7AD8FBA56E7D5ULL, 0xAD3C5B253C639A01ULL, 
            0x72B3D5FB7760F087ULL, 0x27EA689CC49843A4ULL, 0x62B13F27FC140CF5ULL, 0x552DFBB9209A496DULL, 
            0xD332BF3C331A8BBEULL, 0x44882DC50534302AULL, 0xD090E5576CD83B2FULL, 0x647B444DD81CA029ULL, 
            0x6FD49048EF036E68ULL, 0x073EAED193F209B6ULL, 0x7DFE6B4C9EE4DB4AULL, 0xB8DC43CFF6137409ULL, 
            0x2A8F20CD086F319BULL, 0x739E20D40DC26944ULL, 0xB144BDC0AA204510ULL, 0xAD2F9B98CC5C4A0AULL
        },
        {
            0xFBC6B99EEF3BE5D9ULL, 0x6E9420C62BD68CDDULL, 0xD1A3BB1248451F86ULL, 0x6A1A16A7E3CFF1EDULL, 
            0xE9CB702AD2FDF895ULL, 0x8E5B47659005F49CULL, 0xCE01084DA7836BC4ULL, 0x1A61D729921205DDULL, 
            0xEB83BCC859CEB643ULL, 0x3D887D98621570C2ULL, 0x414E361C07A3A3EAULL, 0xF702247B8471EDB2ULL, 
            0x078C7ACD1BDBF42AULL, 0xD9E9CA4988737B70ULL, 0xAD6B7177846ECB01ULL, 0x7531E1EEC33EA984ULL, 
            0x638E84482A1BCEBCULL, 0xF57039C886328CA1ULL, 0x4D98A93763F7BF59ULL, 0xC80D747D364685ECULL, 
            0x687964CDFF2C1D96ULL, 0x35808DA8CD698765ULL, 0x8698A80489151833ULL, 0xC5777835F205323FULL, 
            0x288C2BAF34A362EDULL, 0x83AFF7D4C9A3DBEEULL, 0xE68B503BDEB91913ULL, 0xA41A1994DE1362E7ULL, 
            0x42EA1DE75AE8BCC1ULL, 0x78C2FF599C9B2B4FULL, 0x9FA01B532A0D293EULL, 0x240D8D9B293E4A36ULL
        },
        {
            0xBEBF3C573A8E6D2DULL, 0xB8B303E74F35BD83ULL, 0x4B36FCC816ED5C22ULL, 0xC23C05DCE5D37A6AULL, 
            0xBAD62A3CCA04AF50ULL, 0x207000BD02924C7DULL, 0x194C6EF5371832F5ULL, 0xCE7F3ED912FCF429ULL, 
            0x812CBBE687E94FE5ULL, 0x408B8D2F907CE65AULL, 0x2812F859750A0A35ULL, 0x8B986FA834151758ULL, 
            0x9E5E0B73E96F113EULL, 0x44C5F994E1F74562ULL, 0x07ABEB61F16DA52EULL, 0xDC47CD1C956F77CEULL, 
            0x02433DD205B5B132ULL, 0x569A4B05CE3982B6ULL, 0xB2CF6B6D48B32778ULL, 0x88107948321A12D4ULL, 
            0xB2980B6BF67633BFULL, 0x909B536DF13E3D7DULL, 0x3B09E8925AB8A047ULL, 0x4BC45C4EE0A36AABULL, 
            0xFB9046090DC02EEBULL, 0x17FBDB9E9168D63EULL, 0xA5A13FBCCA31DFE9ULL, 0x3E430E4B02FC575CULL, 
            0x31F0A9E53FAEE602ULL, 0x0E54604E691CA472ULL, 0xE0E131DC07823AC5ULL, 0x9C4060169C4B9C08ULL
        },
        {
            0x2A549FC4A18BC6F4ULL, 0x540C7B53AD104933ULL, 0x868E0578E6636A66ULL, 0x0C0AB8283A42A8E0ULL, 
            0x51988E7103F4ABF3ULL, 0xA21F985EFC350C41ULL, 0x830B87AE63BFCB9AULL, 0x0E079DDCEF1A6B2EULL, 
            0xD2052B77A1FE159AULL, 0x6D038E6DAD984685ULL, 0xFCC10B37891B6031ULL, 0x7B34A3F821339E41ULL, 
            0xBA210FE5ADE85BA1ULL, 0xB7E15747836D541DULL, 0x25E32DE37D628A86ULL, 0x387172982C9317A7ULL, 
            0x2F9DFA815DCE5619ULL, 0xAFDB84D36A85798DULL, 0x5426E07D7078FEA7ULL, 0xC55D20D6D56B49D6ULL, 
            0xD70031BC5956C8B3ULL, 0x66D3AEE028A52C40ULL, 0x03FAE94896AC391DULL, 0xE65A7FDDB285713FULL, 
            0xE5D599D53F1D44A8ULL, 0x74659B43E77787B1ULL, 0x6945D5C143553335ULL, 0x7806595792F13CF1ULL, 
            0x530E4B8D155FF8DDULL, 0x17549CE62DC8F709ULL, 0xA7AC479C4DD849A6ULL, 0x0441BB02948A914CULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseCConstants = {
    0x2F114D4D0ED23661ULL,
    0xD62537D2567F4913ULL,
    0xE967B407D4EF9B28ULL,
    0x2F114D4D0ED23661ULL,
    0xD62537D2567F4913ULL,
    0xE967B407D4EF9B28ULL,
    0xB09DD40F308E7915ULL,
    0xC0FC430DDC8FE9EAULL,
    0xF7,
    0x23,
    0x20,
    0xE5,
    0x81,
    0x96,
    0x0A,
    0x0F
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseDSalts = {
    {
        {
            0x0E617DE1442676C1ULL, 0x2578613D5CA8FFD1ULL, 0xC46C1894CA7B4288ULL, 0xE37243EF803BBE18ULL, 
            0x7782DF07D2A1B03BULL, 0x5ECA345275978E12ULL, 0x1DF36E9DEB613D46ULL, 0xA21BA430C00285A1ULL, 
            0x2CC674F1DAD391F8ULL, 0x8A89C745D9B0D080ULL, 0x753862706722CA76ULL, 0x3B595B80AA07FFBCULL, 
            0x4C797C7B1F07BCB9ULL, 0xBD0300D4B75757EDULL, 0x25F59E3A5FED1CCFULL, 0x6D04FB6A467B8DB5ULL, 
            0x2B608B37E4081F7FULL, 0x584496A752D7FAB1ULL, 0xE32FF6303D8393B4ULL, 0x120675A5A2D1DA14ULL, 
            0x6E581FD93EE69C14ULL, 0x00C5698A7B316AC9ULL, 0x76373498E927F3B2ULL, 0x85E121C9EBAF3A65ULL, 
            0x97B666B0C2C8D890ULL, 0xDBDEDEE1D8DEAE25ULL, 0x4BEDD41EC7BEA736ULL, 0xDAB379FCA760E091ULL, 
            0x431613F4F0F5BCF3ULL, 0xFBCE594436C28964ULL, 0xA40187E0253D61CAULL, 0x1453214686131AFDULL
        },
        {
            0x0232992638726F06ULL, 0x5279130CDEE286A5ULL, 0x8EC9E4719FECEEF3ULL, 0x4011871B46128E8AULL, 
            0x2D9B540DEB479D24ULL, 0x4DBAF189583653A0ULL, 0x39B35B611DB6C241ULL, 0x6EBCB47F47606FEDULL, 
            0xF1773FA2CA1E901CULL, 0x8C69E550674BA3ABULL, 0x011DD5F5EB13B1B5ULL, 0xCD4DA94DF607346EULL, 
            0xCA538F7EA8CBF096ULL, 0xCA9A30896429AFFBULL, 0xCC812FA21F951DACULL, 0xE5F9E045F763C95DULL, 
            0x2971F5FB50CBB200ULL, 0x228ADBCBDC788617ULL, 0xBC4D58DFE20C0E70ULL, 0x7871A46ED35CB7AAULL, 
            0x24B2E419E2DA1BC7ULL, 0x8BC78B9C58ED500BULL, 0xAE2946D7CA2FF4C9ULL, 0x3F70D29BAEFEE984ULL, 
            0xF8CB6EA43373C433ULL, 0x64D2EE538400E5D9ULL, 0x33E1272EDC9B41DFULL, 0xBEAD75E9A0C5B35BULL, 
            0x788CE86A4C495917ULL, 0x8A7A9721C3E43FDCULL, 0xC89748E7E801C561ULL, 0xB5A3BF3911FF9152ULL
        },
        {
            0xC6EE2799CEBCD6DBULL, 0x1C7EF5C387A7C89FULL, 0xDDB418586FF9595CULL, 0xD4D0FAD865EDBEF4ULL, 
            0x4A3F324BAFBB4D64ULL, 0x9439A80E9D6AEA29ULL, 0x4A0A64CF79DD277EULL, 0xC9BAF2089D5B92F6ULL, 
            0xB2213677C80104BBULL, 0xE2D86A8B50AFBA83ULL, 0xF28D2585FC488ADCULL, 0x88F668F22A6C961DULL, 
            0xF6FD7D7D7F394B60ULL, 0x2ACC37819F2DF70EULL, 0x8530F8574332A1D1ULL, 0xED13D033B6990847ULL, 
            0x233B7E2CE19AC3B1ULL, 0x4A5248D4CD9EE15DULL, 0x096D39794493607AULL, 0x2ED5702B7A5204B9ULL, 
            0xD970448B3E4B7BFDULL, 0xA2907BDC8EF109FFULL, 0xF9E4D765B2B9B158ULL, 0xB54D41FCE529989CULL, 
            0x85F9D8E7EFA6DECBULL, 0x0E74E76C30EAF04EULL, 0xDDCD805E4BF1DA94ULL, 0x28617DAF6F5AC026ULL, 
            0xE9F4E3AAFFC8042AULL, 0x700D42A1A2DAAA1AULL, 0x7F0F5575D3D12C5DULL, 0xAD53AB2D65A51D25ULL
        },
        {
            0x3F20755C30A3204AULL, 0xD0AF3588BC7B854FULL, 0xD6463DF822325721ULL, 0x11F6317593BA16ACULL, 
            0x9D63F410EA3FD660ULL, 0x1C28F5B1ABF93821ULL, 0x1572E5A23325DA93ULL, 0x8E1DCC38B5A414FEULL, 
            0x145D0112E04E897FULL, 0x9276FFBBCB7BB49BULL, 0x74B3610DB0E93538ULL, 0x84B5CC0DAA1A80D0ULL, 
            0x756732A9BB67B581ULL, 0x02FAAA793C4C6D1DULL, 0xFEFE3CF94AC90D47ULL, 0x648A3CD21326AA3EULL, 
            0x73F71AE8A660A4CFULL, 0xC9CF15779188CA2EULL, 0xBFB9C9366A260A99ULL, 0x007D230661092B40ULL, 
            0xDEB467B35169D006ULL, 0xACCB2E2C0C07D98FULL, 0x363D3935E1AF7F2CULL, 0x3F6CFA3967DCA565ULL, 
            0x659ACEECE7CECCCDULL, 0x14A120BBF8BF2A8FULL, 0x9A3BA305D2E86742ULL, 0x02D74F899EAF9B63ULL, 
            0x7402DE726476FB51ULL, 0x4A9816590147D5C5ULL, 0x85848BBD86A92CE6ULL, 0x58488DFAAEB40004ULL
        },
        {
            0x38560EF9EB608733ULL, 0xD7BB3C50A2C6D8FEULL, 0xF21B9F2F2769CBB3ULL, 0xF05EDA4D2DE56AC4ULL, 
            0xD11FBCA2ADD45EC7ULL, 0x95541BD994E6A9E6ULL, 0xBBFAFBD27B433EEAULL, 0x0AFC0550703BAAF8ULL, 
            0x078A9C09B12F7F4DULL, 0xA00A788CE8E823D3ULL, 0x0CB2D731CE0EB4B1ULL, 0x2AFA70CFF1F86C19ULL, 
            0x04BC94DBFEE403C3ULL, 0x70BEA540C6B33002ULL, 0x86320C29153A5619ULL, 0x04C04BFFB7CF04FCULL, 
            0xA8B7269A2B22AFB9ULL, 0x100A5F9FB24D98A3ULL, 0xBE01942E2E4B3F70ULL, 0x5CDC1ECBE5850574ULL, 
            0xFD4755D6D48240D0ULL, 0x7B9767547CADB864ULL, 0xBCD7DA25A5E21D28ULL, 0xDEC6DC3510188375ULL, 
            0xC27D7B009A099F05ULL, 0x3F194A5BCEA7A35CULL, 0xCA40F80B71814476ULL, 0x662BEE51D80C5995ULL, 
            0xB42D75A72EA553BDULL, 0xAA02E04AFFD0AF25ULL, 0x269DB531568836CDULL, 0x9D8F93C7D9EA9435ULL
        },
        {
            0xA12D9CEE793A5990ULL, 0x47AFAFCB2E9E55FDULL, 0xFDF0F0CF7655B42AULL, 0x1B23663EC2F12ED4ULL, 
            0x398C9A5DF3388F78ULL, 0x0D159B62C4F52026ULL, 0x1A66C82A9BDC29F5ULL, 0xE28959387D918486ULL, 
            0x39B523BF776BE692ULL, 0x6C40D6D7A2B310C3ULL, 0x73C1D2F6D5B5E77FULL, 0xCE8A966F4B05A113ULL, 
            0xE5258D0A8ACAAD71ULL, 0x0BE5DA15D8337E8CULL, 0xFC40075A79BD5DB0ULL, 0x18E4009E2087D1E0ULL, 
            0xF73CB1BCC0176DA7ULL, 0x0B3F513314E5FB1FULL, 0x18E3B325E662E7A4ULL, 0x45490BE6322BFFFCULL, 
            0xEC878409C2D6CBE9ULL, 0x8DE083F1A6AE93E2ULL, 0x33984A8A3C673F60ULL, 0x5A1FFC9AC3BBC2A1ULL, 
            0x6E619B2ADBBD3DFEULL, 0xBE54E5402EFA36C4ULL, 0x88E6FB8E4DB43A1FULL, 0xFF5FAA1041FC3290ULL, 
            0x73F8E567ADAF84F0ULL, 0x0BE6DFFB98D38F09ULL, 0x4C6E50C3E3ACE0FEULL, 0x0B3714D7D9DC5FD7ULL
        }
    },
    {
        {
            0xC71F3BBFE30B88FFULL, 0x2D5A2770BC8F0BA5ULL, 0x362D0BB03FCB452BULL, 0xCCAE0DD814B4A76EULL, 
            0x7A2B9A157B37BA02ULL, 0x2A969164E1E0CF6DULL, 0xDF24129B66CD2BE9ULL, 0x0969498A54A6040FULL, 
            0xC0340179EB4855E4ULL, 0x073AFFD355C4C0B9ULL, 0xDF91C48F4A60F781ULL, 0xA3F1F5231EE39BA3ULL, 
            0xE285B294332FF150ULL, 0xCBDDEE3B9EBDB3AEULL, 0x3E2A6088480E90D8ULL, 0x71AED4D85F33B1D2ULL, 
            0x8844384FF6BA56D8ULL, 0x10FC3022C157FD33ULL, 0x8CE49135895BB68CULL, 0x37C936ECF275BC25ULL, 
            0xB08D84A155AFE055ULL, 0x4538C1EFAE76CC5DULL, 0xE6F6F37AA6196EC1ULL, 0x0748C93C3913199FULL, 
            0x89CEB4E9189DE2E4ULL, 0xD5A7617DB6AA5836ULL, 0x526C06A1C93935BCULL, 0xC579AF237669A065ULL, 
            0x182D598F13DB5A9EULL, 0xF35EAE5EFC58C184ULL, 0x46D36FFFB5DDA6BBULL, 0x9C6E790FBD4CE536ULL
        },
        {
            0xEEFC175D131395E1ULL, 0xD76060EF935F194CULL, 0xEF541DFBD30C781DULL, 0xABA3EFD6E56FF14AULL, 
            0x0B43BE0E6A2B995CULL, 0x0058C6D098FE1578ULL, 0x7BBD29778A8F3BBCULL, 0x0436112B4DD25C4BULL, 
            0xBB2C24640D036FC7ULL, 0xD7C02E0819EC1E82ULL, 0xD9DD7EE689E85BDDULL, 0xB96DF00705C758A4ULL, 
            0x8EDB9BBA7C2D55F5ULL, 0xA6BEE16FE652458AULL, 0x7FB80AF5C4D6AD16ULL, 0x0154E550A755BBFBULL, 
            0xC5F0F865D8D5C937ULL, 0x5B406EF4BB7F4EB2ULL, 0x454DC0F4F5CF6549ULL, 0x20C0BC406938AE2CULL, 
            0x3B82EEDFAD67F43CULL, 0x873D6617CB46479AULL, 0x1A86052458E8AC45ULL, 0xF167A2039FEFE80FULL, 
            0xA6A22D0A4108FC36ULL, 0x481A84E1A4CA0D9BULL, 0x45B9744EE60D9CDEULL, 0x194951FF92C20025ULL, 
            0x3F05AF3D88AD2F11ULL, 0x23FBF74242682644ULL, 0x492AB582D0BEA422ULL, 0x7AFDBEDD801C4407ULL
        },
        {
            0xA36E1399BDBFBEEEULL, 0x26CBAE316C4279B3ULL, 0x1BF7F4065B79BA2BULL, 0x3718A88AA5684781ULL, 
            0x00A4D5DDC82CE77FULL, 0x773278A50A4617CDULL, 0x9CE1B7D8AAF9D521ULL, 0xB5F35D8D3BAB43EEULL, 
            0x573745A1982DD572ULL, 0x7543225B028920A8ULL, 0xB61C9C56DE4E5C1DULL, 0x1A60F66F20A45257ULL, 
            0x35072ADC4A01C97EULL, 0x08083901BFD11104ULL, 0x73A1E1F365BE6989ULL, 0xEBFD645184D78C4BULL, 
            0x56307E559C6BD799ULL, 0x51AFF4FE37687ACBULL, 0xE92D4029BB2CF3F6ULL, 0xD2CBEF3A3771BE96ULL, 
            0xE296ABD0EA41C769ULL, 0x1CD4269C998EE347ULL, 0x24DC91CE896EDBD5ULL, 0xB58EAC44F59CEA7FULL, 
            0x6E5C3D56DE02D702ULL, 0x7A3E026B78B31F75ULL, 0xA4FEFAB17F4DA923ULL, 0x29CE86C03E3B071EULL, 
            0x8AF4548B2E526E32ULL, 0x225715172186AB5EULL, 0xD90D601DBEAE0F7AULL, 0x073B6A7E29B0F503ULL
        },
        {
            0xBD359B0105A147D2ULL, 0x7A9CE89017DF8BD1ULL, 0x716856EB089C7732ULL, 0x06FB5AF44E8EC638ULL, 
            0xB4E384B4DB47688DULL, 0x2DEC08C1E5DE3F86ULL, 0xDA2E8078B92D3C00ULL, 0x22DE2342292FB2C7ULL, 
            0xB7C1B6A863E5F1C3ULL, 0x3CF3DCE797394794ULL, 0xCD7F81B442A1D88CULL, 0xC360089B0BD7A0A7ULL, 
            0xFF52BEBADD01B6BDULL, 0x47EEB4CA0F76A1ADULL, 0x87EA22C1566C6852ULL, 0x2E5B18885504227DULL, 
            0xE951EB670254BFABULL, 0xBE36D4C33FF36743ULL, 0x004BE7994597AD68ULL, 0x3042ED9926147C6DULL, 
            0x321D98C23FABB267ULL, 0xD852C301FC8ECA73ULL, 0x69095970C2E19EEEULL, 0xA4012286D6EEB8A4ULL, 
            0x39CF1B33EC61EE35ULL, 0x05A6EF556BF61216ULL, 0xBDCD0CDBB926D2C5ULL, 0x1328244CC0538F7AULL, 
            0xBFC9F5FB208A89A0ULL, 0x350CC6D355D9EA9AULL, 0xE778B542918A45E7ULL, 0xB531CA9F688AE237ULL
        },
        {
            0x221020BE2984B2DBULL, 0xC153F340654B4B12ULL, 0x7A747CCCB1A9A475ULL, 0x0FF907241E69E07FULL, 
            0x3F966C41E9526374ULL, 0xB7685B09736B47C1ULL, 0x815BA21C3345CC85ULL, 0x1C233234B719CEFBULL, 
            0x990BC550C27C4ED4ULL, 0x63C2783AB003BC20ULL, 0x916AB7050CBC20A1ULL, 0x205E27C9E786CFCBULL, 
            0x87353F9E058E4B35ULL, 0x30A9E2255E29E5D1ULL, 0xB96175692705ED0BULL, 0x9929A6F22753B543ULL, 
            0x29C4D54DF9177E5BULL, 0x31B07034E43640FFULL, 0xD382588D77A7DFAAULL, 0x8CC090B88D3FD867ULL, 
            0x6567ACFD8DA3E24BULL, 0xA9CCF692361CFFD6ULL, 0xBAEA49BDFEF7A08BULL, 0x22CFA131F72066A7ULL, 
            0x5A14998520640A5EULL, 0xAF4ECC638568DB9FULL, 0xC4DA40B49D832F7EULL, 0x05A735E76457720BULL, 
            0xBFA2A8CD46823DAEULL, 0x49A40FF9C4D4ADB1ULL, 0x86861D3B59386250ULL, 0xF168FBA76C848342ULL
        },
        {
            0xF83ACE124836AEC7ULL, 0xBE02B99F5A57653FULL, 0xE01F7774BC5D6F36ULL, 0x4EB15ECA6B8B1E43ULL, 
            0x8665F0730D561D15ULL, 0x839E328AA77CB013ULL, 0xFF4327117438D889ULL, 0x34326B612BECCCA7ULL, 
            0x5B98F11607CB3BA3ULL, 0x65983A96E2D7289DULL, 0x70A32094681DF5ECULL, 0x13EDA6F916980390ULL, 
            0x3316A44F26537021ULL, 0xB204907635687A0CULL, 0x4B390F41372D5DE2ULL, 0x02F7478E0842E7D1ULL, 
            0x217555EC5B778902ULL, 0x53D8C2837486F340ULL, 0x009D43A279B6C09FULL, 0x495BD526073B8B73ULL, 
            0x7752460A91E743B9ULL, 0x79966424BAD6F351ULL, 0x2E982E35B551635AULL, 0xF1EAA708444F8651ULL, 
            0x9B64D56E87626774ULL, 0x32403F5A1D0B98A4ULL, 0x519FF507CCC1B1CDULL, 0x520E6EE09B029C33ULL, 
            0x8D58AE66C6A630FCULL, 0xE78EEC94C0538D02ULL, 0x9B18255C14B7FE65ULL, 0x3B7A67739AF41255ULL
        }
    },
    {
        {
            0x5DFC376F576B866DULL, 0x56BC0912294A80E2ULL, 0x8A34E22E2A4665DBULL, 0x365FEB9C5BDF96FCULL, 
            0xC866AF2421F2FCDEULL, 0xD7172F9E34F32A65ULL, 0x37B6A28406209279ULL, 0x301F0AE773523541ULL, 
            0x54E36E513828E736ULL, 0x91E5B73C3FEFE30BULL, 0x95556204CB7E4868ULL, 0xBE816EFA39A30225ULL, 
            0x3BD71DD77D15DE4AULL, 0x64CAFF6120245B7DULL, 0x0909D8878EFF0878ULL, 0x3EEA03F7112E82A1ULL, 
            0xD35F641CE16C3556ULL, 0xAECDA43E2A3B9EE0ULL, 0x8112A84BCB97512BULL, 0x3F4C52972B1A21EDULL, 
            0x7471C5CDFA181B73ULL, 0xE5D79C7E9898508AULL, 0xE293A27FA9CD1654ULL, 0x3964A14DFCAB4716ULL, 
            0x61B514D6099CC1C4ULL, 0x54BAB0725F859A3CULL, 0xFE2EE62C12FC4E79ULL, 0x70C84B9DB7F9391CULL, 
            0x4A15F4541CA8BB2FULL, 0xD547D2640BBBE64FULL, 0xC0D178A478B2E8DEULL, 0x94FD43025F56AC97ULL
        },
        {
            0x40075F309169888EULL, 0xCE5DA15710469245ULL, 0x26A39E28FD64357CULL, 0x67E75A6389544FE7ULL, 
            0xEDD3767815A59655ULL, 0xC0683F5424DAB8B1ULL, 0xB94A55B241235662ULL, 0x6C94482A7DEE2180ULL, 
            0x771900C6ACE84032ULL, 0x9D7D34A172B59E36ULL, 0xA10A882DEE62ECF1ULL, 0xCAC8826C083E6715ULL, 
            0x097AD66F877168EBULL, 0x94602BB15CCCE928ULL, 0x46D130C05773DE6FULL, 0x5807D2C4281B121EULL, 
            0x6301DCC24D2B1A84ULL, 0x04AC7EDDD2EBF1CEULL, 0x90D514DC5268A048ULL, 0xE3512E383492D3DFULL, 
            0xF693A3F338034B12ULL, 0xE98FB627565F47A8ULL, 0xB3D9858A9AD2B9E7ULL, 0xB0A87D7E25BE9267ULL, 
            0x8F552DB9BA714D25ULL, 0x580FC366758EB7C9ULL, 0xD70F53D26CCCC7FEULL, 0x8F4E33021FD7A18AULL, 
            0xD798718B41C00E4DULL, 0xBA3A2416BDB32B04ULL, 0xCED86B58EE39DCBDULL, 0x6CA9E1A6A53A924DULL
        },
        {
            0x1A2A0CE7CBD46A7DULL, 0x08DFCF383EECBF9BULL, 0x2836C37DF81121AEULL, 0x63ABD5812AF55AA2ULL, 
            0xA4F85006C9780353ULL, 0xB44C5FEA2B295C69ULL, 0x1B5BA8EA8CEAC15AULL, 0xE4D6D6212E6D07D0ULL, 
            0xF18D8B862FCD97A2ULL, 0x8D24C1F4215D0445ULL, 0x4B20D616550C51B4ULL, 0x793CD2F75846DF4BULL, 
            0x1E841122A8B2DD89ULL, 0x975ACBDF8404E730ULL, 0x5D9CD7A69A1DF420ULL, 0x0718C311B5CFAED7ULL, 
            0xF176EF59C1D642FFULL, 0x3612E5969F74359CULL, 0xA6B0E4F0F5678F87ULL, 0xA4BC5C406AFE8D78ULL, 
            0x692902D724CB25F1ULL, 0x9D4B068FFBA13BF6ULL, 0x3A65618E156E85B3ULL, 0x7A26A7E35B5F415AULL, 
            0x6C3023035EBC516CULL, 0xE6C2A8853E86A668ULL, 0x2274791BB8189C7FULL, 0x583D31EFADE4C763ULL, 
            0xB0AB2C823748DD2CULL, 0xE2CA17F8F574B19DULL, 0xDD4814438A0C6833ULL, 0x0AB245DF1EEE2E1AULL
        },
        {
            0x3F3665049F4F16A0ULL, 0x78C102DEF8EE731AULL, 0xBECDB84015D5C947ULL, 0x47DA5B5E954EDFF6ULL, 
            0x4BDE611BC87CB0EEULL, 0x38283024000DAA39ULL, 0xB8F9759A5507DD15ULL, 0x5C2BA7EE6BC45E92ULL, 
            0xDBBE5184F8A76B53ULL, 0x9BAE62EB0E04FA81ULL, 0x0A5CBCC7EC7AC13DULL, 0x1D7C179D4C2EA6A5ULL, 
            0x27F34E57315B39BBULL, 0x460CAB5473103024ULL, 0x01F5F9BDF16AC4E3ULL, 0x6B7CC72434C72594ULL, 
            0x0424F3C4B51C3ECEULL, 0x668E091AE8BD155CULL, 0x6651CEDD2767B673ULL, 0x283C2E18DA43C296ULL, 
            0xB66E398E5B9313D8ULL, 0x39CD5EC97B6C75AFULL, 0x77B35E0FB13717A5ULL, 0xE0A65C166E6EAF09ULL, 
            0x83ED2EA8074D7D9FULL, 0x72144931AB7C5FE1ULL, 0xFFE9450A34889058ULL, 0x22F2A45BFE0FFE64ULL, 
            0x606DD54DDBB7076AULL, 0x9BB85E58689E3203ULL, 0x4513652DEBB9F37EULL, 0xD8EC2E3E5F0CF2A1ULL
        },
        {
            0xCA1851A2ACDAD12FULL, 0xAF2ABF5E8F1E8A8BULL, 0xF1B5BD442B6D0B8BULL, 0x7F73A4DEFEB99E35ULL, 
            0x547ABA1866F99664ULL, 0xE5C295E2570ECD8CULL, 0x55BBF8CE06FAC4A0ULL, 0xBDB954F4D2B6F586ULL, 
            0x52A2300D02CDF995ULL, 0x9F103C50685D53A3ULL, 0x398DCDB6E3296132ULL, 0x742D56F36EA16F19ULL, 
            0xE0C67A0645B88EF0ULL, 0xDA2040118E8B9D45ULL, 0x01A47828FFF5C847ULL, 0xC36EDB2614EA8C3CULL, 
            0x0A5DBB744A8D2AE6ULL, 0xC7089A32B42917ABULL, 0xBE5DA626C2889047ULL, 0x244B813BE8BED44CULL, 
            0xBA4593F0AD3816E6ULL, 0x8F4A6651CCF50C84ULL, 0x89E41B6F750131FBULL, 0xD9A1BB6EEABA1FA8ULL, 
            0xA586024F23813BABULL, 0x28234EB590E2CEFBULL, 0xCC4F7C4BF4166E80ULL, 0xACBFB20168A716FDULL, 
            0xC360271CECDA1653ULL, 0x9E8832F1C07A6B64ULL, 0x3657443FEE5120B6ULL, 0xA43E7B4047B8F9A0ULL
        },
        {
            0xF3B4B8F412866C7BULL, 0x464D1A4AD9F0E46AULL, 0x7ED853BE773D4983ULL, 0x3B393139CCA68F4AULL, 
            0x29F1327FDA60C778ULL, 0x381CC880A9A530B2ULL, 0xB25A472BF4B1FE23ULL, 0x8EC4337CB5AE130DULL, 
            0x5FBDBBA8457197B7ULL, 0x23CB1D9890C63D36ULL, 0x852863F793BF7F32ULL, 0x9477DF4F02A2F9B1ULL, 
            0xDFE3B82B40F22C82ULL, 0xDE689FC1B03F698AULL, 0x760FE35100B11654ULL, 0xAAFE56F7B152F673ULL, 
            0x2024F3937FB66EEAULL, 0x98597ADDB6589D21ULL, 0xBC1CA4184C649702ULL, 0x7C71B131231AF508ULL, 
            0xAC283F903B0E44B0ULL, 0x2083F3BCB4563E2EULL, 0xBDFCC964AC807FD0ULL, 0x53B3FC463A47FF84ULL, 
            0xECB1024F4B1F112AULL, 0x53BBC226FD7FA381ULL, 0x23ABC676954AC906ULL, 0x25CEDB7ACBD9C249ULL, 
            0xE7C013D5A5488B27ULL, 0xA4EFCBF531E22B49ULL, 0x09C0A743F2D160D4ULL, 0x9132A14B7FDE08CDULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseDConstants = {
    0xE76DBD187102B5CEULL,
    0xB421C6A5312238F7ULL,
    0x990F1BDA06D584DEULL,
    0xE76DBD187102B5CEULL,
    0xB421C6A5312238F7ULL,
    0x990F1BDA06D584DEULL,
    0x993FB04DDFEC0342ULL,
    0x8C044F0B84DFEFE9ULL,
    0xE0,
    0xD7,
    0x26,
    0x31,
    0xF2,
    0x99,
    0x58,
    0xEE
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseESalts = {
    {
        {
            0x72DC000E9D957CF0ULL, 0xCCF09834A79F7F8CULL, 0x956A2D8CD4B0D22DULL, 0x7F7B54D8B28D5CEEULL, 
            0xB12683C0CBC51D8BULL, 0x0B71CA44CFE89D53ULL, 0xF57199830AEF82D3ULL, 0x0BDEF424694BD18CULL, 
            0x7C2037EA306AB144ULL, 0x99D5953DD1C7ABA6ULL, 0x7BCE52F021C49F3BULL, 0xC12F3219FDFEC225ULL, 
            0xD9707C38D9981BEAULL, 0x2FC86D4AE38E51D8ULL, 0x573CA8982161EF0DULL, 0x855B19A0EA5188EBULL, 
            0x977273ACCDF1AC47ULL, 0xDDDFF9F86F3C7923ULL, 0x465FB7C9404F9B45ULL, 0xF16660B6814288ACULL, 
            0xC07A9FD69A638805ULL, 0xDC23E9B775488E56ULL, 0x136F008B842D7291ULL, 0xCE0C427955B7AAE9ULL, 
            0x6B93FAA003CB4DEDULL, 0x5D7138AFC4E20FC6ULL, 0x8024568E09BABEB5ULL, 0x82B6F65BF5CCC1CCULL, 
            0xA3F17B8654B94DC2ULL, 0x0B2EEE6884B2CA91ULL, 0x45BC6EC3069FD80EULL, 0xBE8606E718F2170BULL
        },
        {
            0x223F1D42CC88802BULL, 0x7852397972C77A6CULL, 0x15301DB655C14D78ULL, 0x7AD9C3BED6BAC176ULL, 
            0xF733665359E79849ULL, 0x069394CF974440C0ULL, 0x12845EE5EA4802DAULL, 0x4CB28A81044C70F7ULL, 
            0x773CFA2643058991ULL, 0x25950F2BC275A62FULL, 0xD251292179969601ULL, 0x68FAD255528C5D10ULL, 
            0x6071C1981D4E88A9ULL, 0xAFC345021BBECD05ULL, 0x5A1F20B5F1DF0C17ULL, 0x40B839B51A502276ULL, 
            0x5FC171577D2647FCULL, 0x26320DE2F2512D6EULL, 0xD209888B1A94C641ULL, 0x4B3D4C29F52955E1ULL, 
            0x27A5BACC3F06DFA6ULL, 0x94C907956073FF28ULL, 0x7EFDCF534E7254E4ULL, 0x0FA09BECA45C3D22ULL, 
            0x6BADCA71DBFFF091ULL, 0xADD53F8998975D09ULL, 0x0595364EC3C6C760ULL, 0x7D80323862BF4625ULL, 
            0xBFD494F2598991D3ULL, 0x6EDF5AAC50FE8DFBULL, 0x2A7DD22A4240257FULL, 0x05543DE2FD38F5BDULL
        },
        {
            0x8915BEE67240BE07ULL, 0x2008BDB0F1FF0314ULL, 0x30AB4DA1E35368D7ULL, 0x6AA88E6626E3A09DULL, 
            0x153C6D17717A1150ULL, 0xF22409BDDF6C4790ULL, 0xBE4A934AE94F92F8ULL, 0xD430E6B151535F3CULL, 
            0xCCC71BF25C081559ULL, 0xC776AA4C8D107A5BULL, 0xD6C7AAE98E57D174ULL, 0x43BE8B403748FF81ULL, 
            0xB75199BFAD37BE80ULL, 0xE0DC9BC40EF8F400ULL, 0xC723DA5ABBDF007BULL, 0x7EB8E9865DC053CBULL, 
            0x77FE06B381FE72F9ULL, 0x55F94FCDA865A261ULL, 0xD5FB859283FBA0B8ULL, 0x04CECF652BD92D77ULL, 
            0x1115BD38C5F4EBF9ULL, 0x99F1BB5F340E42FFULL, 0x02C47F70B00945EAULL, 0xB959FA5D0B2782D5ULL, 
            0x5EF48978EEAE260CULL, 0x0B255F8B6BC7C54FULL, 0x33B09B8F2C402993ULL, 0xAAFDFD2250B00CC5ULL, 
            0xF15B588898BE3A44ULL, 0xF15ABA45F9DA7B3AULL, 0xB4DE3A9C98DC445CULL, 0x786F3A6D70467E7BULL
        },
        {
            0x2586EC33AADDDED7ULL, 0x4AB387E64B5293F6ULL, 0xF6FAF76D64C1605DULL, 0xE2F43BBE513915EAULL, 
            0x9B752EE0D5FAAFF2ULL, 0xBFE8FBA146B019B1ULL, 0x55E572F8059C6AFFULL, 0x076B5FF4D6A67AC1ULL, 
            0xA4E86BCD270016DEULL, 0x15D8AA10C065CDDEULL, 0x83EB0705B7B5986DULL, 0x58F3F98D09288FEAULL, 
            0xFB0BA2F1A9280915ULL, 0x99CD823D58F92C83ULL, 0x5B5DCD7E100C232FULL, 0x400474DA5A646B51ULL, 
            0xCFBBF29055FD3939ULL, 0x06C86EB4204319D3ULL, 0x9D980128C56B5818ULL, 0x56223F0BA25A3DD1ULL, 
            0x1DAE7DB3E7D28324ULL, 0x7E96D68CDE8C420AULL, 0x5E1A43326381B624ULL, 0xCC7B4069C46069FDULL, 
            0x7FABF23FA3E5591AULL, 0xCD81B85CFEF43A41ULL, 0x54486D4A2BD6DA7BULL, 0xC82039BE85FD68DBULL, 
            0x9D940216D8522873ULL, 0x1E1362543A3280FDULL, 0x3A101441FBC66890ULL, 0x9FEA0A599238FA6CULL
        },
        {
            0xD513AB9EED633A59ULL, 0x6B28A7AF253F5D9FULL, 0x2F445B95C74EB44EULL, 0x5297C50A3369ED5AULL, 
            0x1D3E82F866CF98A5ULL, 0x8836FD7487DA41CCULL, 0xD05B1A58F7C1526DULL, 0x46AB4D630E20D3F0ULL, 
            0x2E3A036A5D7B07DBULL, 0xDD0910C4E946A835ULL, 0xC1B4D8DB08FB7D65ULL, 0x29EB5613D56D61E9ULL, 
            0x318E3902CDF4FD67ULL, 0x2110A607AB29F08BULL, 0x5837A0D98C32E413ULL, 0xC1F1DEC468A7A22DULL, 
            0xDBF84F2852B57544ULL, 0xBD2BE20813866640ULL, 0xF640767AD13136C8ULL, 0x3DA7C50B924A50BEULL, 
            0x4C6D086A0881A97FULL, 0xD1DE2D93B3112D43ULL, 0x70B1F903F95FF922ULL, 0xCDF95C07814CAD04ULL, 
            0x2655742C49FA6C13ULL, 0xA4B4E6F029D2D7BDULL, 0x21553277E283D512ULL, 0x197C0DBF6AEF27A5ULL, 
            0xACE9CDC010B84F11ULL, 0x121E3D03B24C9BA4ULL, 0x3C0D37C0283B60FCULL, 0xFF6201222DF1A005ULL
        },
        {
            0x445A49F209E1EB5BULL, 0x2ACB0BCE02D66A7CULL, 0xBA4EA403F9F7808EULL, 0x20C05A912EDED6B4ULL, 
            0x86213C46D49CBE91ULL, 0x3107D01A44827988ULL, 0xF7D08926AFB7461CULL, 0x36BC5D9998EFA25FULL, 
            0xA86808F1D94B440CULL, 0x6399EF0502D76E95ULL, 0x5CD30B6DC0ECE626ULL, 0x5122D9D0FE89C409ULL, 
            0xDEDEEBFD6FD8DF6EULL, 0xE10C203A55852C8EULL, 0x6CFC41D8ECF860D1ULL, 0x937170CC43AA8E04ULL, 
            0x6BC37370AF3B542DULL, 0x5DC0DF4032F4AA8AULL, 0xBC8955D7581BEE8BULL, 0x302FFAC370B4438DULL, 
            0xD2E5317F912FA5E2ULL, 0xA9D8CE9EAEB01BD4ULL, 0x41535A0A1FF48A5DULL, 0x3E3F38031FF8CBBDULL, 
            0xBA978940340AC33CULL, 0xAA58C6598CD8A91BULL, 0x66348F5CBF8A824DULL, 0x14956E7C01A4BCAAULL, 
            0xA83CE28572C60B9AULL, 0x6BA122DB385E5B6BULL, 0xBE85C5CFFBA5B7F9ULL, 0x250A9640A1C5695DULL
        }
    },
    {
        {
            0x1D8EA27D1AF079B9ULL, 0xB6796E06D46A9103ULL, 0x3B29BB691A0438FEULL, 0xCCF78E0CFAE3E22EULL, 
            0xF86E3D61ECA90F30ULL, 0x6890D3EC307ECB91ULL, 0x79DC1DC88A8BB030ULL, 0x9A1569382D3EA69AULL, 
            0x852A5BCC9A25C34BULL, 0x1D0053483FB38795ULL, 0xD27E2C39853055B4ULL, 0xB146CB7AD34B4525ULL, 
            0x0EEAB007701AF868ULL, 0xD3A9C4E5626CFD45ULL, 0xE15D1961F9512B26ULL, 0x167F17ED56C7CB65ULL, 
            0xBE3FF9A06977E0CCULL, 0x6FFC8A57A699C024ULL, 0xD1C72E2CA4141E46ULL, 0x6AA40EE1B70AF88CULL, 
            0x249A0699069D6292ULL, 0x0C8184D661427974ULL, 0x41FD67BB4F2EE2F2ULL, 0x7229F42621E7F432ULL, 
            0x661E2810B9639221ULL, 0xF97DD0B94C427568ULL, 0x0512AD29E503AD5FULL, 0xE7CF9BA7B50B74CDULL, 
            0x227421026C13C277ULL, 0x491C6753EE43501EULL, 0xE8C90B06D5C566A0ULL, 0x8F92DFCC3E21EDB0ULL
        },
        {
            0x702D18113D1FBCB3ULL, 0xF5D14ADEE174FEC9ULL, 0xBFB95D6FEA676881ULL, 0xD2D47C0B160BFBBAULL, 
            0xAE9AE370B4E4EF78ULL, 0xE392344FCA820C19ULL, 0x67C3E1216A1BF65CULL, 0xD60333DB4E86E61FULL, 
            0xF08ED7A394D04180ULL, 0xE87BF3445E0F8DFCULL, 0xBEA8F5332BAC27C2ULL, 0xF4C4A9C4296D8E7BULL, 
            0xEAF3244C03C6342DULL, 0xA6E9DB5C222FDD13ULL, 0x7BD3D9886D1E33AAULL, 0x9A2B92A350EC2366ULL, 
            0x96006DF34A2611B2ULL, 0xD95F7EA76DCC05B2ULL, 0x15F28F91061867D6ULL, 0xBCDA1394E46BE4CCULL, 
            0xFA40B81189A2FFECULL, 0x825C9C5580C3A9D1ULL, 0xCDEF59098869BAE7ULL, 0xCABA8D2A28F1D30BULL, 
            0xEA1B818C15B69D14ULL, 0x06CD9A7081BBBF80ULL, 0x2766E5B8F701DD17ULL, 0xB226228B3A68F614ULL, 
            0x44C75BB88AE2D3CAULL, 0xFA4D853544CBE754ULL, 0x9F140709E4BF0EA9ULL, 0x005A591E886194CEULL
        },
        {
            0x307D7A950851D26FULL, 0xEC6DA5FEBE928DBDULL, 0x1435F33A8CC46ED0ULL, 0x4FD271A8F252FC0EULL, 
            0xACFEED74A776AF97ULL, 0x17811914882F6C9FULL, 0x8E90A4CC1417C7F2ULL, 0x45E7F509A23AA0DCULL, 
            0xF1EAB1430C2AABA5ULL, 0x1734C2A79D7B5DB9ULL, 0xE625F68D7FA83BE7ULL, 0x8189BA809A4DEA6BULL, 
            0x0A0230B196B7E564ULL, 0xAE11759497D9D2A0ULL, 0x6AD82E8ECDA8D3CDULL, 0x0B942AEF8ABCD2ECULL, 
            0xADF07465F61F3BCDULL, 0xFAE6A81DF4399C0CULL, 0xC2BAD07E94630AA4ULL, 0xE2951B2A469D8E96ULL, 
            0x1081887C150C2C73ULL, 0x1432457DA5D8C740ULL, 0x39A378F090DD42F7ULL, 0xC18E36C65950A1E9ULL, 
            0xB457098BD2427E50ULL, 0x60423221EF57F68AULL, 0x97734C809A1E1B0CULL, 0xAFAC047743FDDC7CULL, 
            0x1EC1E5950C92B3C1ULL, 0x40FF92F83FB52DE5ULL, 0x703D32C446E01EE0ULL, 0x482192A03752C2C6ULL
        },
        {
            0x36DD4355AA4E04FEULL, 0x3C96FEEF02807A2AULL, 0x1FC14347C19D6DCFULL, 0xDDD12A6146821AC5ULL, 
            0x130DC9027801E24CULL, 0xB81EDA73CBCDF128ULL, 0xB49B24D2D56649C6ULL, 0xAFC5C1FB4E6E84C5ULL, 
            0x83A17D4EA75670B2ULL, 0x70761ADED01C74D1ULL, 0x37025C367A218C0CULL, 0xC739D9E058014259ULL, 
            0x912A14F5D7E8BDF8ULL, 0x4F80341442EA245BULL, 0x980F5F2FF3AD0CF4ULL, 0x13811F01F3A952BBULL, 
            0xA975B338EFE8DF0EULL, 0xE1263A7B1BAB49A9ULL, 0x2ABEEDAC70A5EB6FULL, 0x83B888C86D4A18FAULL, 
            0xA8E980F18A4339D4ULL, 0x8C686D76416DE4EFULL, 0x3F7AF0B1D52BFA75ULL, 0x85A3781F071FBBF2ULL, 
            0x015CD0738EA5DBFCULL, 0xA8F8FBD796A36B6FULL, 0x0F548FED4E7E4180ULL, 0x133AA76308739867ULL, 
            0x16C74458E83B4857ULL, 0x7C48501E2F052792ULL, 0x8405C9A3765E0A0AULL, 0xE4533A3392B35D54ULL
        },
        {
            0x56B320C931C3273FULL, 0xD1E06E344F7C9CFCULL, 0x07B79C56FBD3A4ACULL, 0xE1054105539DC25EULL, 
            0xD023302F3B7A6206ULL, 0xB417378CAB28BADFULL, 0x687ED05D50390BEBULL, 0xF2B5C1DB2F7F9367ULL, 
            0x5FECD459DF2E4DD1ULL, 0xDF0E8CA947594F7AULL, 0x9C7E08689B8ECA32ULL, 0xECD762DB0041E72EULL, 
            0xFDD3DA2EC9F04550ULL, 0x67B9C4D49691C101ULL, 0xC87203FDC4F1E701ULL, 0xBDE7EF241E4EF2B0ULL, 
            0x074AF93C78F90F95ULL, 0xD010FAA83A707AE3ULL, 0x2AD9F81A84E0D1BDULL, 0xBE2A62563A3B4DB7ULL, 
            0x6521E8A5C447E4BBULL, 0x2F7F479961E7B6F1ULL, 0xAFEEF93E02ABB674ULL, 0xF68201C68949C626ULL, 
            0xF88265031BD75CAAULL, 0x5885007E3A4DF342ULL, 0xC3AE20313159E891ULL, 0x07870AE703725859ULL, 
            0x47167DF484AD41ADULL, 0x4D3B0F16DD6AB290ULL, 0xF9AF1524270D5DBBULL, 0x84C3FED25308C390ULL
        },
        {
            0x4056E6D9D6A1036EULL, 0x675AD06BD10E43ADULL, 0x55F66E43E72BBF83ULL, 0xB4C093CC7522B227ULL, 
            0x22E4C17217096B01ULL, 0xD8D0818710E4B9DAULL, 0x24B177127200A40AULL, 0xEAFD8878585963B8ULL, 
            0x34C35C59AD00D125ULL, 0xF6DD0042BD7DD607ULL, 0x57DE9CACEEFF5ABAULL, 0x3F5605FDF91DD36CULL, 
            0x2BF84FF3933F871CULL, 0x4D5456C31975D186ULL, 0xC2206F1DBD078872ULL, 0x31E76D7C76C7CD68ULL, 
            0xC268A760C56A1CD1ULL, 0xDE494815B09B2A72ULL, 0xC1FD980E59BFB42AULL, 0xB33232B44EF60E77ULL, 
            0x50AC5C007D86AF02ULL, 0x2EBD8773F7021135ULL, 0x4DBEDB479438D739ULL, 0xDA4D5CD2C1C09C52ULL, 
            0x02FB0BDE32C171F7ULL, 0x389C7AE9378E542EULL, 0x85E9E80CD67B69B7ULL, 0x3518E0329804E939ULL, 
            0x4BE53E2DA3BBAB92ULL, 0xE82A0652C09651F4ULL, 0xD4EB66A8C43D6A9DULL, 0xE220F8CF918AA1A4ULL
        }
    },
    {
        {
            0x06BA7F7107842314ULL, 0x58B7D36C78076EB0ULL, 0x8E5FD804F5698E3DULL, 0x301C0EE4531E0A39ULL, 
            0x38772B640609D269ULL, 0x4DA3D9752D98417EULL, 0x1219B776CB169814ULL, 0x108D2632A2FA7995ULL, 
            0x3D6AF96D2AA1A102ULL, 0x29B22736B9B259C5ULL, 0x98A0AF33CDB9C3C9ULL, 0xDE03F4252CB6AFCAULL, 
            0x17E25537FD5EE78BULL, 0x232D5EE6189FFBFFULL, 0x85215297E99D1D31ULL, 0x88715A62020809A6ULL, 
            0xFF2BC6376939F1E8ULL, 0xE98207C1395BD229ULL, 0xC306100200045C20ULL, 0x642AF045C9F96B5AULL, 
            0x5EDA321C1C80C1B7ULL, 0x02638F3D38FB6922ULL, 0x0C39327F701CCFACULL, 0x90A9AC993899FDCAULL, 
            0xD3395EBD40B5710EULL, 0x1804A23D557A9ADEULL, 0x88B2CA18FC17DCA8ULL, 0xDC128B90054808E9ULL, 
            0x8D7B35CA1160E471ULL, 0x1CC74FF823CE8295ULL, 0x9099636B6E50E4F9ULL, 0x2F9667F44CB18C21ULL
        },
        {
            0x5C9FF5773D26D42CULL, 0x4AC96C7B6DD7F4F1ULL, 0xC736162C4F065E96ULL, 0xFFA588FC7416CECFULL, 
            0xD65E4E695EFD648EULL, 0x0D30855E536C0737ULL, 0x086C172445F015A6ULL, 0x440E167D996363ABULL, 
            0xB16BEEC03D8923C8ULL, 0x6599A71983659716ULL, 0xBB1BB342567AF6B1ULL, 0x5F8D2DB1FE99D350ULL, 
            0x633CBA7321C63805ULL, 0x3315EBBD7EE1A178ULL, 0x82BE29D5266567D2ULL, 0x48C2FF4365CBBA1FULL, 
            0x1BF3F34DC0B510BCULL, 0x4362E3D650C033E7ULL, 0x53DCA2BA6D7BBE76ULL, 0xEB40AE472D458456ULL, 
            0x30C7E215D925AE8DULL, 0xD7A116D8F1C7E198ULL, 0x65A9035BCFAA34E5ULL, 0x6A458E1A601EBB22ULL, 
            0x008BEB6B7A78780EULL, 0x7AFB99CDECBE3E4AULL, 0x92D02CB26B46DA46ULL, 0x721BC6A646481DE7ULL, 
            0x13CFD788C1279AC5ULL, 0xBCB6470AF287349CULL, 0x0F1536F5213B14F4ULL, 0xB1593C99DDDED4B5ULL
        },
        {
            0xE6537970D4CD47DBULL, 0x0A85A73D26B4BA03ULL, 0x722A087A1EFD9D8DULL, 0xF571F990064F359CULL, 
            0x54D653E740A7AFE8ULL, 0x804EA0174E141DBBULL, 0x245E56292039F558ULL, 0x9C56255962C56954ULL, 
            0x9C1D23092D18D91BULL, 0x7A8C2998E7A50813ULL, 0x5818D5FFFC0BDBA9ULL, 0xE3A23C7361CFAA91ULL, 
            0xDD87DE07620E7434ULL, 0x0454D1930CF61E23ULL, 0x3643B812440FEC62ULL, 0xB2915D61242C11EBULL, 
            0xB7E028C8835DFA7BULL, 0xACEC0706587F11C0ULL, 0x25840996B4630F57ULL, 0xD7BBF450CC53F6D0ULL, 
            0xFD92193ECC937477ULL, 0x5BC4A6D3A2312F29ULL, 0x14B7553DA66369A3ULL, 0xA7425C50A17BEEEDULL, 
            0xD643A20C7C0CBD78ULL, 0xA600527C8EAA7162ULL, 0x770C87516578E926ULL, 0x88DAC3DD8AEA926CULL, 
            0xACFB1B32A3DDBF7EULL, 0x921452176D9D2E0DULL, 0x76BED27B416AAD70ULL, 0x0C63F5A20CCBE033ULL
        },
        {
            0x01EB132EAA420758ULL, 0x54DC3DEBE2528352ULL, 0xAF703306A3F633B1ULL, 0x63D8D782B6FC7E45ULL, 
            0x0716986AE6D6F296ULL, 0x81E9A182FB66C862ULL, 0x0CC348730D64D892ULL, 0xB67164E876FF78F0ULL, 
            0x16321B3AB02BDD53ULL, 0x66D70F7C357094A6ULL, 0xD0CEE1B785EB6108ULL, 0x31E96F233A3A5646ULL, 
            0xDCCC033020B6E163ULL, 0xDA9C69B331F6E576ULL, 0x2B3D2999CFFFF713ULL, 0xFFE7652F35881623ULL, 
            0x0C767307EC3A0ACFULL, 0x5F1B51866F251C45ULL, 0x3419CB3D932C8EFFULL, 0x2D9F998428DA1AEBULL, 
            0xA4FE9157BF903203ULL, 0x5D39FFB8CE1D84B9ULL, 0x45E23E7A07BA93FFULL, 0xE6CE4ED923FAD076ULL, 
            0x543711F8E4881472ULL, 0xDFEE0312D24F1840ULL, 0xF2F7DFA20ECA5057ULL, 0x2AD8C93A35E6651AULL, 
            0x634E90A32C32A872ULL, 0xC421E821FA348DD4ULL, 0x7D4B823D86298C02ULL, 0x4E3434124D35F1CAULL
        },
        {
            0x588A33D0604E0385ULL, 0xFA9F9E319DC74B5FULL, 0xFB2F055F26D33BCAULL, 0x9073C0C51414E081ULL, 
            0x2F2112A47FC6EE3DULL, 0xAD3DD71CB7A08B62ULL, 0x9A513A02B24F8C92ULL, 0x150DAD3DB3700B55ULL, 
            0x354F7A83C8EDCB26ULL, 0xB385E90C8E236CA1ULL, 0x5842001F42828BF0ULL, 0x94C9275A57D82B70ULL, 
            0x39A3B58298797A59ULL, 0xE8AE68C5FBBD8AC7ULL, 0x14EFC216C510B00EULL, 0x4D39C3260B373666ULL, 
            0xA50D517245BE4390ULL, 0xDD8B1C1F31A90008ULL, 0xCAE5039283164B57ULL, 0x915B63794762E228ULL, 
            0x73802C95132DF896ULL, 0x30EB9F7378191588ULL, 0x30AE1249ACBE32A9ULL, 0x93108DD8FD17F7E9ULL, 
            0x26F8259EBCFA7B67ULL, 0xF00B439FE8237F21ULL, 0xB74BEBC6B325B62CULL, 0x06837CCD3709A28AULL, 
            0xE47F7AAEE2945F44ULL, 0x0AA05152063A0D53ULL, 0x9862B073423AB859ULL, 0xE76BED04CC269492ULL
        },
        {
            0x448E264C6CA05113ULL, 0x875323E2F80FA1DCULL, 0xCD2EC2F4DFA95C9EULL, 0x6280AED797AB715EULL, 
            0x574E67E6C1A944D2ULL, 0x9EFD48BAA670B509ULL, 0xFAC01638B24509F5ULL, 0x5CA82E29006AFC68ULL, 
            0x1A0848677907F440ULL, 0x82F8F935E3F18D23ULL, 0xA0CF3133BBFCD612ULL, 0x7D8407FB1A67D493ULL, 
            0x66292D6C64CD19B1ULL, 0x18F550FE2CA8B7D3ULL, 0xACF54581EC6ED22CULL, 0xB8FC2312FE1841E9ULL, 
            0x6270C77D804CDD8CULL, 0x2C0D1BC6533A68C0ULL, 0x7AFD20C3BAF74018ULL, 0x016D9DC4E9081CE1ULL, 
            0x5C55106E5A0E6DC5ULL, 0x2456CCE004623F7FULL, 0x5B899E05DB8670AEULL, 0xA6058E48B566DF34ULL, 
            0xEA8741CABBBE33CEULL, 0xFEF0608813B226DDULL, 0xD37F10C9CDCC1241ULL, 0x9EFF56009077125FULL, 
            0x183A7B7293356E62ULL, 0xE7982BE89E32F03AULL, 0x4D6F53CA2E762561ULL, 0xAD3740879602C4D8ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseEConstants = {
    0x5586749B8828F035ULL,
    0x4159B8D2606237DFULL,
    0xE71084B96616C2F0ULL,
    0x5586749B8828F035ULL,
    0x4159B8D2606237DFULL,
    0xE71084B96616C2F0ULL,
    0xF65CDC3C2ADC8074ULL,
    0x5FC712E3DA89B628ULL,
    0xD5,
    0x93,
    0xB9,
    0xF3,
    0x9E,
    0x28,
    0x18,
    0x2F
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseFSalts = {
    {
        {
            0x41810933D7F64CF9ULL, 0x8AE5F9A72B17590CULL, 0xA9A004F1C4AA29C2ULL, 0xBD7C10B3BB60E285ULL, 
            0xA8F14672304356C2ULL, 0x9E62F49827C00B08ULL, 0x9CA2D526C59AFB80ULL, 0xF71DDAD44E2EFAA6ULL, 
            0xAEACCB586AC0DE1DULL, 0x4C803F37F6150615ULL, 0xB77107A18497386EULL, 0x203FD971966E527BULL, 
            0x388F58053EE2265DULL, 0x152948A14C589230ULL, 0xEFAD3303C6D03B5FULL, 0x6D793E1EEAE22D11ULL, 
            0xC9F32E51F1BB8348ULL, 0xEB62C18CD6616156ULL, 0xBDEC1B67F286F99FULL, 0xFBE9F8BC4C107253ULL, 
            0x480D4C15B21F5CCAULL, 0x0CD11A34BDC785CAULL, 0x4421F0772E1EBE7CULL, 0xE7601DB28B0113F6ULL, 
            0xC72525A80847566EULL, 0x62866378BEE05AF9ULL, 0x063338E0974B6CE6ULL, 0x30DDBE0AB40DAD81ULL, 
            0x554312A783272503ULL, 0x5530F04F9FC286C5ULL, 0x07B3341369DBE00BULL, 0xAF87F15287910CEFULL
        },
        {
            0xE88572632E95F7A7ULL, 0xD49D9E75440E6F12ULL, 0x4935A7B4D1084FBAULL, 0x628709EB2B1DBCA4ULL, 
            0x1B733CA37973E4C5ULL, 0x91FD7DF09EB30755ULL, 0x7F138F1DE346EAC6ULL, 0x6B2ACCDD06C0343DULL, 
            0x3EEB5AF30359D289ULL, 0x7A1785EEC20461F6ULL, 0x2C21F1EB8EC34B6DULL, 0x3608DCEEB7316465ULL, 
            0xC42C7883FC2FD4C6ULL, 0x7E4BD75A51FCBA68ULL, 0xB5D8E78F87ACFD50ULL, 0x0156159BDC0B3593ULL, 
            0xFFC7ECA00B255F6AULL, 0x22DC669705B106A3ULL, 0x88BA02B78EA2539EULL, 0x4DC482EB5A219806ULL, 
            0x725A98E9EEC5002AULL, 0x0F2865568460E552ULL, 0x06C8262C5C6EADC6ULL, 0x0E8AD0664FD91ED4ULL, 
            0x866E77B1F35BE0BBULL, 0x9C7F6FC4CAD19D23ULL, 0x7416FBC0101D04B7ULL, 0x0D4C8D4BC34338B3ULL, 
            0xA6C30B109557DBFFULL, 0x548E1EA375C419B4ULL, 0x04CDFCBB1367CD6EULL, 0x1FE3AB6B7A4C0D67ULL
        },
        {
            0xE1255BA1416DEFE5ULL, 0x62AD74AE721EEF5CULL, 0x3B449EBE4D88D30CULL, 0x4699265174400F1DULL, 
            0xF6CB5EE5BEDD9980ULL, 0xA7838B39415BE0E7ULL, 0x7555053CF95A1357ULL, 0x0DC8A06B398AB575ULL, 
            0x9D88FA836BC58EB8ULL, 0xCEB45B4678E179BDULL, 0x63B622E2F63A0880ULL, 0xB1A0822BBA865635ULL, 
            0xC1D6D70ED1D2EE98ULL, 0x73A01EF432FCACC5ULL, 0x97E8692CF9BA89A3ULL, 0x5EE0F074BD30E984ULL, 
            0x3DC621CAD5702AC5ULL, 0x1D25F95E4857C340ULL, 0x1B1E8C5580848B92ULL, 0x2CE752108DE6BD34ULL, 
            0x498DE14551BBE493ULL, 0x4332DC8E25E2C1E5ULL, 0xFA7AFC3AF1E69556ULL, 0x592AD44BB73D47FDULL, 
            0x49E8162B1D016DBBULL, 0xED67C42BE5577D49ULL, 0xE0EA90D29AD99E0BULL, 0x8680A39C8BEA7BB6ULL, 
            0xACADC3336AC13161ULL, 0xE743752E12363BB0ULL, 0x6682902D7BA5BE54ULL, 0xAFEA2A200052026BULL
        },
        {
            0x67B463A2529B315DULL, 0x3DC12E84B08E7543ULL, 0x0B8A183ED0BD163EULL, 0x79B857C359F39B85ULL, 
            0x3AFA40FAB31AAF82ULL, 0xDEE6FDC5FE203354ULL, 0x670DAC1E559D1821ULL, 0xD3C7BBFFC7F1A4E3ULL, 
            0xBA26857043138098ULL, 0x02BCF631577755F0ULL, 0x13CD1B99212A2749ULL, 0x27271DD8362F20A4ULL, 
            0x17CD40A4074A0DC6ULL, 0xB5B465A52C6AC6B2ULL, 0x23CF69E6A03BD2B0ULL, 0x5A738B4930E9EB7AULL, 
            0x88D5441888BBB17CULL, 0x234C5D98B305EF47ULL, 0x6DD1ABAE7666CDBDULL, 0xC9003D3FE2E3C4C6ULL, 
            0xDD82B40DC406CF8BULL, 0x0215E617983C48D2ULL, 0xC03AFDF8A48CDFA3ULL, 0x1B28255A5C34FBB9ULL, 
            0x6ADC9E2959615071ULL, 0xFB0EABE67384C578ULL, 0x502B51E8456EE872ULL, 0x7C0D7AB86891DF13ULL, 
            0x867AA747FF2E9EA5ULL, 0x4C71E6B9D71441EBULL, 0x6B126DAC68A67EB3ULL, 0xCC48140A35062233ULL
        },
        {
            0x865CA9F8F55588F6ULL, 0xF126D798AB793F5DULL, 0x5AAEF32C51B8478FULL, 0x52FB1A3D1B99B3AFULL, 
            0xCE12AEA20D16719AULL, 0x1C5343650EA70CF0ULL, 0xE7C33E28EA09DA92ULL, 0xA406CC6D24B7F8DDULL, 
            0x22B2939204450773ULL, 0x9B7E28FD538F24F5ULL, 0x5F025D1774823469ULL, 0xF422DE1BA78BC408ULL, 
            0xFAF12A50C7FFB1D8ULL, 0xBC5A733A1394D662ULL, 0x23418C16D55F2A36ULL, 0xDD1A03A512E2D942ULL, 
            0x297C7935522E7F72ULL, 0xEEC04B3CB4A22D0EULL, 0x7E4F3CC90EC017B6ULL, 0x9F428549D3C07005ULL, 
            0x2F2E2D4C6FACC924ULL, 0x618FC326D3050DA8ULL, 0xB13F2D1773B7B9A4ULL, 0xD2902881E0623BCBULL, 
            0xFCCC972EB9F17B3AULL, 0xF9236D2466D45044ULL, 0x01EF3E1D1A42F762ULL, 0x888BC3AA14DBB906ULL, 
            0x9865140336362370ULL, 0x7AC03C0D749ECAD2ULL, 0xD0F99F4B558DCE53ULL, 0x32996DC5A6E3A707ULL
        },
        {
            0xA58F37E371BEF441ULL, 0x17566B8E1DA6F627ULL, 0x6A964019D7D69920ULL, 0xB9B826B3790CC1C5ULL, 
            0x63CE26BF4A258D09ULL, 0xB4F9956AE3D645FFULL, 0xBC24C10CD562927DULL, 0x7423419D2114035FULL, 
            0x8823C1046FE8C331ULL, 0x2F7E5814E5124DFAULL, 0xADA36FAFFE3593B6ULL, 0x048FDD7A664D6040ULL, 
            0xE11167206697F017ULL, 0xC5F2B1A5BCE3D87AULL, 0xAAD212A51E8E623EULL, 0x610720F02B09C9B0ULL, 
            0x63D02C88B0EA8444ULL, 0xD1F19DF920B44AEAULL, 0xDECC5E5470EF360BULL, 0x09D5FE62B73BFEC4ULL, 
            0x6ED37C0D7F161CC7ULL, 0xE65E9B93DDF2F406ULL, 0xF6EBAE3D6C78CB31ULL, 0x4B06821D96B4C5DDULL, 
            0x3008B70178DB8D4DULL, 0x4D086CB337C17D4FULL, 0xA89218542240301AULL, 0x1B358068178E23D5ULL, 
            0x630054FE4EBF9456ULL, 0x22AC3BC41428CA85ULL, 0x0666D479ED6BD74BULL, 0xA9BB151D92A37A42ULL
        }
    },
    {
        {
            0x2BF6ED322309B85EULL, 0x96D836CC7EC67F44ULL, 0xC0D97E588B75BC22ULL, 0x46A1173B8DF14D10ULL, 
            0x58A4127332D77E50ULL, 0x4C4F28B1FB6B7243ULL, 0x0B26FA661C5FB9B4ULL, 0x44E88BCAB9C7538FULL, 
            0x93012A0E4D04AE68ULL, 0x60958E6C83041381ULL, 0x08AD5391F38C694EULL, 0xED9EB1A82DB35DFFULL, 
            0x23AB55303CF245ACULL, 0x410671E441083DFAULL, 0x240A86AAB3CC5826ULL, 0x289D74A71F5C383CULL, 
            0x43D9FDB7BED768E9ULL, 0xB0BF254063390DFAULL, 0x5CA51CFB3E13EEFEULL, 0x79EB3355B18A70C0ULL, 
            0xBE0F2A6F52E32C75ULL, 0x9C7C09BA46FBFCD6ULL, 0x1A8414CD8B47491EULL, 0xD54D5B864EA80F67ULL, 
            0x145F45CC9257B24CULL, 0x25602CC07EC5B1A6ULL, 0xBA6F123C6B1D4FB3ULL, 0x9389ECF229B1742EULL, 
            0xD8C934A72606E7BDULL, 0xF6E3DE3855AD5D1BULL, 0x8A32F860FF15164FULL, 0x8BCFBCCCE9D91083ULL
        },
        {
            0x40ED6E0ACBBC989BULL, 0x503FA1F6A1E9B542ULL, 0xE39EE9C3966A39B8ULL, 0xFD5289DCAC3CF7C8ULL, 
            0xCE53174AC4E0D78FULL, 0x6C1729B69DF6DED6ULL, 0xA188E5E1F625D361ULL, 0xAED816CF9514F682ULL, 
            0x06A1B8EE458BC542ULL, 0xB027C3B7123FA122ULL, 0xEC6C34974363588AULL, 0x4BC3B449B1F325C6ULL, 
            0x2336E81994D81D41ULL, 0xBA2A35E5C8B6C378ULL, 0x8EC79616624B9D0AULL, 0xAB6F476225777AA9ULL, 
            0x1101DBA5DC405B03ULL, 0x54A02B987EE4E9BAULL, 0xD0AF9E18C49FFC83ULL, 0x254518CC769472CCULL, 
            0xBF28B0837F4D6C9DULL, 0xBD9AE90A33EA8633ULL, 0xD213BCFE87B8E6C3ULL, 0x0AC7A1AF1C19416EULL, 
            0xD43EBF2190997F63ULL, 0x89605BD036970B89ULL, 0xC3D3A1B184B85E01ULL, 0xE2C547D8307DC322ULL, 
            0x381FEE24B66415C0ULL, 0xED4E8203CCCDEB60ULL, 0x6ABA2B2BA7819C17ULL, 0xFC402DC0E4C5FDBEULL
        },
        {
            0x0A64180B9B9DF697ULL, 0xA039F908CE5BD799ULL, 0xA49BC1F3465EF051ULL, 0xE45C3C1823A0B373ULL, 
            0xE69F68A31C7D5561ULL, 0xDE13527935CB96ADULL, 0x1650E2963E9CA476ULL, 0x684BF50D91112EC1ULL, 
            0x40C387A92B626072ULL, 0xACB382311FA4B58FULL, 0xCFB3F372074A9368ULL, 0xD262285148EE1B81ULL, 
            0xBFEA456ABAFC78EEULL, 0x94DD9A8CC9DB198CULL, 0xBD82E109488A1867ULL, 0xD19D90F8750118F9ULL, 
            0xB707AC907AAC2A8FULL, 0x62135C81215A16B1ULL, 0x367FDA30A511EE5FULL, 0xBB96D93E9E5D038EULL, 
            0x689E18FF046BE4E8ULL, 0x795A27B58F7F6380ULL, 0xE313C6E7CF863074ULL, 0xCBBD3A3FAED083D0ULL, 
            0x16D3C7593FAB0D30ULL, 0x58D1B19ACEE28F78ULL, 0x228E1BED2FF8A110ULL, 0x3FCBCA1EF9ED273FULL, 
            0xFC4A4F43F1A19E25ULL, 0x9E26B9EA422F37E8ULL, 0x94AD39BAF1BE5026ULL, 0xFBCDBE70D550D5A2ULL
        },
        {
            0x289F120D3EC63192ULL, 0x72768EC0BCD7CF5DULL, 0xB02AE022174150CAULL, 0x31BD14D6B5947D02ULL, 
            0xAD6C4B3EF23D2E5EULL, 0x699453B2E9D99AFAULL, 0x65EE318B32DEB457ULL, 0x813F6EC8B330A872ULL, 
            0x51C75C181A40A899ULL, 0xFCF4D05A700D5952ULL, 0xA8DD988BB7569C20ULL, 0x01E53B4B6E476EBDULL, 
            0xC442C838B0EBECD5ULL, 0x67DCE8E07036BCCDULL, 0x09626464DC728AAAULL, 0xE6F8F59A6378DE53ULL, 
            0x4F34760459D3512FULL, 0x77F6E64A571DED35ULL, 0xCA86014D1EFAE525ULL, 0x6107D8D3363E9597ULL, 
            0x0E22B9F3FD9E9969ULL, 0x186B1F37B79CF818ULL, 0x5E45203A2B109BF1ULL, 0xE502EEEF15867243ULL, 
            0xE4A37CD291B2CFB5ULL, 0x97FA292C465E398EULL, 0x8930D5FD24C18B47ULL, 0x8A00BC33A3DC5F42ULL, 
            0x176DD713246E565CULL, 0x2276C6126DC91D57ULL, 0x67508F76591628B8ULL, 0xDD60786A3D5BF8ECULL
        },
        {
            0x8B57D0C4AED30943ULL, 0x6A2EC9BAFCA4AFE4ULL, 0xE5E33D9A80E2B3C2ULL, 0x8960E0AB83DA8450ULL, 
            0xE56AFD152B1DA760ULL, 0x0827B66D9BADB24AULL, 0xDFB665D026F4DD0CULL, 0x6C12D60DE8C5A7FBULL, 
            0x77049FE2D5BB4A44ULL, 0x1EEF30D8AB7C7F48ULL, 0xFECFD5C8963375E9ULL, 0x4F805332C0F90713ULL, 
            0xBA746AA610ABDBCFULL, 0x1A61087F4F7A40D3ULL, 0x165B797F504C935CULL, 0xEC993B977579A987ULL, 
            0xE2309DCF6F2CCA5FULL, 0x5B1FDC97241CE2D2ULL, 0x012AF2E43CE0E346ULL, 0x5BDD1B3C311D2C6BULL, 
            0x3F0213FCB67132A1ULL, 0xC9732B904EB4894CULL, 0x2E2016803AECDE35ULL, 0x5F9DFC1DE0E558E7ULL, 
            0x4670A89768F4405BULL, 0x1A4392321473E57AULL, 0xA888347372622018ULL, 0x9661A47FA604A8D2ULL, 
            0x8BE689FFEA580E39ULL, 0x4602C0DECAEB263CULL, 0x80BB18D421B2F438ULL, 0xCA734F6DFDBECB81ULL
        },
        {
            0xF9434E58B2E76478ULL, 0x8DE947643AD22108ULL, 0xD565A508C43D5174ULL, 0xDFB8185C09E75C94ULL, 
            0xFEBE99119DFEE130ULL, 0x0AE799BC6360BF6DULL, 0x0E7C3708A4B13797ULL, 0x7822964119418E9AULL, 
            0x9EF0665D3ED454C9ULL, 0x6A0233C692972EDAULL, 0xD32D19C8C446BF54ULL, 0x5BC1305E6A185616ULL, 
            0xDDC4ADFC18494D03ULL, 0x1C49B52C00C1CEEAULL, 0x358ADD81D5839B5DULL, 0x966C37394ADE1920ULL, 
            0xA242AB4E6E1B02DFULL, 0x3F97E1031398282EULL, 0xA17C9D826A6BD688ULL, 0x8717A2BB76D3A24BULL, 
            0x3A552DB6F6646E78ULL, 0x5EF5A461D97331D2ULL, 0x85A80A98CE3876F7ULL, 0x1F65AEF84F041DB8ULL, 
            0x85632DA464BE7D9FULL, 0x4E2E0893A4C849F7ULL, 0x849D8AD5EEDED833ULL, 0x6513B6F5A8BDA2B2ULL, 
            0xBF523712B8F3454EULL, 0x07908FFD1AF7FE5AULL, 0xBA63D43B2A38A635ULL, 0x47924A4830715D61ULL
        }
    },
    {
        {
            0xEAA565612B55CE34ULL, 0xBC6E48FF05A58833ULL, 0xC4BD67BA5CF8282BULL, 0x6E43266D6E486DA9ULL, 
            0xB7665EB0540B101DULL, 0x804EDF137264495DULL, 0x2D0DEBC080643D84ULL, 0x07F7D6E92ACCB0D2ULL, 
            0x026B8C9B79D29A25ULL, 0x7714B21D67144AD7ULL, 0x925F970D157D4CDFULL, 0xB21E65AFF5366433ULL, 
            0x137EEB24D4D7B9E2ULL, 0x5E978B9AE486E3CDULL, 0xFDAB81E462791BD8ULL, 0x49C2A7742B52BD6FULL, 
            0x91BFAE77AED8F51BULL, 0x2F17293B73DB35E7ULL, 0x88B0DADCF97B6D2FULL, 0xE4F681EEF77AA639ULL, 
            0xC484BB38BD0FB488ULL, 0x3CF480DC1B6C097EULL, 0xBCCC64BBEAF69227ULL, 0x7AE777FB1B3C57ECULL, 
            0xBB71CE23A26D056EULL, 0x976AFB817FDBDECBULL, 0xD33EB092F4756A3DULL, 0x4AA4B2D36005FCF6ULL, 
            0x1189E634A0801454ULL, 0x4C21AEFDC944992EULL, 0x0556AB23A444AB05ULL, 0xE01A59AEB8353107ULL
        },
        {
            0x9DD2F31868870B1EULL, 0xA6EC340067284967ULL, 0x7DD161E80E36D8EAULL, 0xE3B8363968555C66ULL, 
            0x82D89C0C3DC6AECBULL, 0x0A585CE26ECD7EAAULL, 0x56B7309B49F60E46ULL, 0x5F63A482A7AA8D9EULL, 
            0xD14B4D9CB614BBD7ULL, 0xB3D19ED675AFD0D7ULL, 0x072CA644FBDE1E50ULL, 0x9B4580C34822125BULL, 
            0x6C20B0C14A1FC651ULL, 0x2551DB76BFB844A5ULL, 0xF7F5910F90F17ECFULL, 0x610297970F8D9D5AULL, 
            0x81C85485DFBE5563ULL, 0x040A914FD20C3DF9ULL, 0x01130C0210D1A277ULL, 0xE1B510B82564071BULL, 
            0x32FC43188A9151F5ULL, 0xAF09760AB443D117ULL, 0xF076397C9C03BF88ULL, 0x3A73AAE05A4DAE23ULL, 
            0xFDE93A12AC81F556ULL, 0xA91CC112B7365F93ULL, 0xB7AB3DED6373440FULL, 0x61B077DA03BEDF58ULL, 
            0x705F3989F6E68BD6ULL, 0xBB051B56A6F97912ULL, 0xED4647180306E146ULL, 0xEEE131454F9B0F72ULL
        },
        {
            0x29AC183FD5E8A4D8ULL, 0xCBBC24EB0F09DDEAULL, 0x85E4C94A5D2022DCULL, 0x92ACA811A15B2C43ULL, 
            0xEB1617B3C4F114FEULL, 0xC15C42103DAB18A1ULL, 0x0FD09914ED30B723ULL, 0x0EC1FB5177C5AEACULL, 
            0xCA61114090EB72DDULL, 0x1230B21F6650A60AULL, 0xE05C3C4A452AFA30ULL, 0xD2AD26AA94340962ULL, 
            0xAE28E5B995FEEEECULL, 0x3B38A68D0A1D07C2ULL, 0x1F672C36B5B8F03DULL, 0xAA900E1BC939AE1BULL, 
            0x838F8F8D09ABDC40ULL, 0x151A2A58842CE3B3ULL, 0x291F0432B7B965B0ULL, 0x1316440F753CFFB1ULL, 
            0x85FB3472AE59DC5DULL, 0x11451534AC647237ULL, 0x496C3378415CD153ULL, 0x787311DFD54B6B86ULL, 
            0x48861702FEA9D949ULL, 0xF82F0AD49D3B21C7ULL, 0x148562552E4334BAULL, 0xB762D1DEE62A5C3BULL, 
            0x98387065C1747A87ULL, 0xBF0668ECCA5446D5ULL, 0xF4F8DE5738D3FEFAULL, 0xDDC5008246357B3AULL
        },
        {
            0xB5717472E9DCF02FULL, 0xBD9B88258A962D72ULL, 0xB14857BB4D73E7ABULL, 0x6981B832F051D50FULL, 
            0xC1E8754376C4455DULL, 0xCC1C13C0BF443DDAULL, 0x3F5C1603BBF49601ULL, 0xE131A8B8FC2C92E1ULL, 
            0x410DB6269FF40F2BULL, 0xC50C2C08D2535878ULL, 0xEC10667BCFA32100ULL, 0xC7F010632EE4C19AULL, 
            0x990F4C69DC8A3C81ULL, 0xBB81726938000B6BULL, 0xB48CEB7AF9108638ULL, 0xF165EB9C8F3CBD08ULL, 
            0x711B648E71978CDEULL, 0x0916F89A53BF30A3ULL, 0x2D2987F18535A068ULL, 0x939D1DDA3C170317ULL, 
            0x1FDB5D8A04DEB9E0ULL, 0x2EBD9CCA80425FC5ULL, 0xEED0EC02192E579DULL, 0x6E94618286D92FBDULL, 
            0x6E06BCDEB8A84B0CULL, 0xEA287EA99B9ECD55ULL, 0x1468178C06A44865ULL, 0x69A80508A77A667BULL, 
            0xFE5982E921639876ULL, 0x43625ED7F09416A3ULL, 0x6EE74862A64E7700ULL, 0xC0984A5F27FE3DD4ULL
        },
        {
            0x70B633C935CB9DD9ULL, 0xC20F233FCCD3AA76ULL, 0xA27E502803B7C639ULL, 0x490AAFAB5D2AAE4CULL, 
            0x2465663F50CC0894ULL, 0xB0EE9677977101FBULL, 0x18D89CE48BF803FAULL, 0xE26CD3934A90873BULL, 
            0xDF863AE5A1324E4BULL, 0xF7EA64244AA40D42ULL, 0x41AF4A5F9271E803ULL, 0xC5E2A49560F6995AULL, 
            0xEC8E55E0784F6246ULL, 0xD0DE09ED8F923B85ULL, 0x0EB066DB619B4D4CULL, 0x5E2F4F1DF6EC9996ULL, 
            0xFCC197DBE92FD3EEULL, 0x3A6FA5D12B6A5068ULL, 0x2CE670740286A273ULL, 0xF7C8B02A2AED96E9ULL, 
            0xEB19158776A3DDE4ULL, 0x08F6D741A3CCC972ULL, 0x930BE51134A8F930ULL, 0x666383C04B7787A8ULL, 
            0xC618BAB47E4B8485ULL, 0x845E92B02EC6AAE5ULL, 0xD87DCF423ABA971EULL, 0xC538BDBA5ECEBBD4ULL, 
            0x406659AC1B414CADULL, 0x86EEFAE337951639ULL, 0x9E3E7942303AFDFDULL, 0xD908E9944AE501BEULL
        },
        {
            0xE9DA0D0A534FE9D7ULL, 0x4871C87A520A3599ULL, 0xF7DD245120BACAEBULL, 0xDCB54ACA155C4C17ULL, 
            0xF11A50845DF0B192ULL, 0x690D3B72D68019E7ULL, 0x2AC3338A7B222F9FULL, 0xA54638ADAB101251ULL, 
            0x27A064B285BEAF9FULL, 0x93BEC0E56F628900ULL, 0x69FE02A2BDD05A99ULL, 0x96BCDC1EF0599069ULL, 
            0x18C2045BD8C7BC7BULL, 0xE00284115D49488BULL, 0x8EF186EA8939FC38ULL, 0xCE44A1BDCE46B399ULL, 
            0xF60C90116C3C1614ULL, 0xF1B686C7B8BA8681ULL, 0x0E789B5A611CFDBEULL, 0xA5AF359DE958AFB3ULL, 
            0x05912B93C3F40B13ULL, 0x2761BAAE88EAD92AULL, 0xBEEA7F633C39BDC3ULL, 0x8F216CDD5A4F8B6FULL, 
            0xCFBDA465E1FC8BD4ULL, 0xAA3DA4524D5B9267ULL, 0x1BCD8D23EE4F903EULL, 0x9FEA3C12DC5FF482ULL, 
            0xD6FC3FE1E4B8BE3AULL, 0x684B3E133579229CULL, 0x2FB326CCA019E4EEULL, 0xA893AAE0860B9890ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseFConstants = {
    0x8D89C1E058008AA8ULL,
    0xE22C73AA9D0042E1ULL,
    0x5BB11795780D5665ULL,
    0x8D89C1E058008AA8ULL,
    0xE22C73AA9D0042E1ULL,
    0x5BB11795780D5665ULL,
    0xB29C0DDAA8E272C0ULL,
    0x1038E1CB3582A9A9ULL,
    0xF2,
    0x63,
    0x55,
    0x7E,
    0xE3,
    0x74,
    0x01,
    0xBA
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseGSalts = {
    {
        {
            0xBD240332F3B4D079ULL, 0x33BE0D4577B30F6DULL, 0x93AF6A9F77C145F9ULL, 0x5D8944A30469F0A5ULL, 
            0x27FB26B6809B1E16ULL, 0xAEB6E6F92C19FB20ULL, 0x39221A687A8A6B57ULL, 0x92C2B8E4083CE3D6ULL, 
            0x8E486D7F2316DA9EULL, 0xA6311AFB4D05F399ULL, 0xA7DF75291EF68B59ULL, 0x9E584DDA7BEB23F0ULL, 
            0x8CAF5A2494AA1CA5ULL, 0x71031B6D21825F50ULL, 0x5464E56B2A9F933EULL, 0xE77562146EEF67D2ULL, 
            0x9288CDC6032240F4ULL, 0xF2094C9AC46CB7F8ULL, 0x75A72A47412F340BULL, 0x737910FA3FAEB666ULL, 
            0xA339D997309AA40BULL, 0x45FA38B8E33AF8B2ULL, 0x24E6FA9675C591DDULL, 0x9C20BFE1EF3634D8ULL, 
            0xE21A435E54631359ULL, 0x19C3341E748D4850ULL, 0x3A71E2D7C88D3EDDULL, 0xEAF3A5A23712E5B4ULL, 
            0x825509BCAC6A028BULL, 0x60587E43BEE304E3ULL, 0x5D15C492EF96868AULL, 0xB54891DB4A562A4FULL
        },
        {
            0x75CC3A01C7C0ACFFULL, 0x226581E49F354481ULL, 0x6263CCAA2433AFB1ULL, 0x377CFB686AEA0A66ULL, 
            0xF580E0B35735A501ULL, 0x4C4FBB57A41DD67AULL, 0x3DB40F138F3419C9ULL, 0x936DD340C8E6056AULL, 
            0x9FB8C6B6454444F1ULL, 0xECBFFE703CFA2943ULL, 0x849E47A9A420A3A1ULL, 0xF36D62A7C8D69C4CULL, 
            0xAED0574F311B2D99ULL, 0x9F37B25068BDAC44ULL, 0xCC2B5236F21424CBULL, 0x45B14EEB736FEC32ULL, 
            0xD6947F0089E95000ULL, 0x4DB0D94B4AA813EAULL, 0xE9F0356F21C6AC9CULL, 0x7333B410A2809591ULL, 
            0x941D7185FE2F05BBULL, 0x244ED37C6BBE1389ULL, 0xB14CD8C0635F3B70ULL, 0x64AFADCF22390E26ULL, 
            0xF777222DFAFDF8DDULL, 0xDCFC17F4464CD409ULL, 0x20102A8934BCE658ULL, 0x6691783737415365ULL, 
            0x92AB0E69892AD264ULL, 0xA0535FFF7F6B5080ULL, 0x219B2054BB760E52ULL, 0xCB616C33B93F4DC6ULL
        },
        {
            0x31CDACEDB1CEEE6DULL, 0x21721B558EC68E98ULL, 0x8E46094934E5BC27ULL, 0x23CD0F57491F67A5ULL, 
            0x4E2B34752012B954ULL, 0x12F43267855392DEULL, 0x8F2AA512A5BE665BULL, 0x9C508575CF1E6717ULL, 
            0xD036917B43194E92ULL, 0x18E5692B16076AA6ULL, 0x8CD3DCEC92CD0914ULL, 0x31D36AD32B50032EULL, 
            0x91DBF20F2030A950ULL, 0x0B82D5A105F97B0DULL, 0x5F4669082204A102ULL, 0x97BAF6F06EE5CA96ULL, 
            0xB29D7E53869597D3ULL, 0x5EB25D3178F04502ULL, 0x43A3FF093E85A84FULL, 0x8BB46E28D9A2EF37ULL, 
            0xDBDAAA2A4FDFFD4DULL, 0x38C3068F98CA472AULL, 0x429877E78A5DD14BULL, 0x757AB6AD8F3A7A95ULL, 
            0x9E9242ED11ECC0B6ULL, 0x7396EBDAA7DC9E59ULL, 0xA0E183A7FD74489BULL, 0x76644CDA4183EAA5ULL, 
            0xDA6DB4148C912E1FULL, 0x83F1ED23BF5CE1D6ULL, 0x5A97899511717B40ULL, 0xF5D8F9C3A1A76EE9ULL
        },
        {
            0xC31DBA46E8C9117BULL, 0xCC1157C941540948ULL, 0x4CAFB6FC835F43A5ULL, 0x39E9D2EBC7C767D3ULL, 
            0x820A968E9EFDED1CULL, 0x07BDAA624048F5E7ULL, 0x52E7C56FF7796335ULL, 0xB119DB49F2E3D90FULL, 
            0x7061BD3BC9F95E7CULL, 0x14D202DF476E3556ULL, 0x1C3E2EC30BFF11F3ULL, 0xF08C16D97431231EULL, 
            0x20758FDC5537A2B7ULL, 0x6B39512523734AC5ULL, 0xF96C8537FE47D60DULL, 0x965A3420E1EBAFD1ULL, 
            0x34D0DC09F49A62FDULL, 0x50D76FD3D95797BDULL, 0x863C5EE78ED957CDULL, 0x1D4BDF6F7C1D84A8ULL, 
            0xBC1AD45618A13DE5ULL, 0x117060B4BF0F3BC2ULL, 0xD28B648DF6B572C5ULL, 0x4CF7A371E34E68D7ULL, 
            0x79A3682507E9365FULL, 0x1F973739A8F1E523ULL, 0xC5B1E3FE97D50841ULL, 0xD3C013AC71BF6EA1ULL, 
            0x9AFE3E0437D0F687ULL, 0xB17922CD79234D9CULL, 0xFC84D252AA9C525EULL, 0x2D1D939E3E935B88ULL
        },
        {
            0x3BA0D5164E424D79ULL, 0xA78F8E7B3B026385ULL, 0x6F62FE20BB8EC267ULL, 0x4440E6103C3E253EULL, 
            0x0A1BCE379CFCB80BULL, 0x07FE01171F6DECA9ULL, 0xCD8965D050356360ULL, 0x23199C648A4BBBD1ULL, 
            0x3B08D8605EAAE169ULL, 0x12E24A4FB4A9A333ULL, 0xAD4238042F7189A6ULL, 0xCFD513F1B2F6F85EULL, 
            0x32F2E9B25698A3AFULL, 0xAEA2DFC0142F4D67ULL, 0xBD3B74AF1E6A2711ULL, 0xEFD5ADD7BA86749EULL, 
            0xB42A7CC3CEA60666ULL, 0x121A808E83F2C36BULL, 0x9C0034B39774758DULL, 0x6ACF284014A76A91ULL, 
            0xBEFD89CD488C9A86ULL, 0x6E1E07F2A27C7D0BULL, 0x2DCEAF67F2F22C47ULL, 0x35FD06BD971CBC54ULL, 
            0x47798D3A97951411ULL, 0x886009DEE4F6E9AEULL, 0x36E32FF0515F28D2ULL, 0x201C2ED2B358D01DULL, 
            0xF0CF5712A5AD5DD6ULL, 0x830E1870E8B89250ULL, 0xCAD2A5A7528D972DULL, 0xAF29097F47032795ULL
        },
        {
            0x5E9C9623BC2B7618ULL, 0xEE4ECE7C2B14A81DULL, 0xE0229AAE583B127AULL, 0x6C321DDE6D078184ULL, 
            0x73EC9EA0A8993976ULL, 0x113F1BDFDE467C7CULL, 0xE902B97CEAEC136FULL, 0x903B9C149653F430ULL, 
            0xE893BC4B0D2E2518ULL, 0xBB7DDDE0B7F1E43BULL, 0xEBFC9B36CA8B8590ULL, 0x759E4E652B3995C0ULL, 
            0xABF4EC4DCD2DB312ULL, 0x27CFE1178FF6C88BULL, 0xFB3FA08ACC41775CULL, 0x1E899898874785D6ULL, 
            0x82EDE828B7329683ULL, 0xA4CD8B6F377E097FULL, 0xF7211A0741FE95B3ULL, 0xBF58D22FCCB6CAC7ULL, 
            0x6CB90EE39C131BCBULL, 0x06D52241DC4FF224ULL, 0xAFD80A61B7E8FCD9ULL, 0xAC4914FC39A2C379ULL, 
            0xDA2D6BCD94E57FFAULL, 0x54AA7BA06F0A91B9ULL, 0x3EA03D6F7A1D495AULL, 0x3FAC3E01E45A1683ULL, 
            0x0A68670CDDDEA2ECULL, 0x53C80DE5BBE8BF49ULL, 0x3C92614154EDF0AFULL, 0x2C59E1C615D622E5ULL
        }
    },
    {
        {
            0xB4B565622B270DA5ULL, 0xF5BBFA64F863D794ULL, 0x880A0AF7CC731B1AULL, 0xCE8F0AE30D6A071AULL, 
            0x3E4CDF9DEFAF8367ULL, 0x7A26A8EB0BD3D365ULL, 0x2BDA9AB919DB2401ULL, 0xC62A73F8FBE17B18ULL, 
            0x4B731013F88D99CCULL, 0x709B03C70A7ED245ULL, 0xAA2F83837EC29DCFULL, 0x39208D8261F9DCA2ULL, 
            0x3CFFFDDAB0B76E20ULL, 0xDCF975478664620BULL, 0xD00EEF3A5A3AAD68ULL, 0x9447DC49B0B19889ULL, 
            0xF9863381FB3E6811ULL, 0xDC72FBFC6AFE0507ULL, 0xF3B789D25AA50BA4ULL, 0x42F1D55CDAD7CECCULL, 
            0x2259429D0EA02EA5ULL, 0x1702A6807324C318ULL, 0x8356357FDC220B31ULL, 0x00F8DE544B396A3CULL, 
            0xD3314D6C663B52D4ULL, 0x8FC3393C9A8DE0E5ULL, 0xA5F543160D5A8C3EULL, 0x24965C2D2CE173CBULL, 
            0x659020FA8A044C19ULL, 0x48353053EA599051ULL, 0x86F44EA883152FF7ULL, 0x2C9D005D94796167ULL
        },
        {
            0xC3ABD91F283E2647ULL, 0xA422EACD3F6E9681ULL, 0xCA6EAB5F0D75E41BULL, 0x0BD548144114B20CULL, 
            0x7150CC109BD677E6ULL, 0xBA2B244267815CDEULL, 0x9D106E5D1500DF9DULL, 0x9D64AE15A5714821ULL, 
            0x793BA1915763FE31ULL, 0xED93F0C1DAFB9D70ULL, 0xF426204CED2C68B0ULL, 0x5D9F8BE2B1E6AA66ULL, 
            0x6C02A8EAB5ABE5D4ULL, 0x0F4B0C24E658C9DEULL, 0xC4D7666C990FE16DULL, 0x01E6C7C9DD094270ULL, 
            0xA61C59B3A7983E98ULL, 0xE32B7290EB3350D3ULL, 0x0DC94F074B55D0DCULL, 0xA0CB245938848317ULL, 
            0x110002B7A49E49AEULL, 0xE834FC5EEC0AE98DULL, 0x66E34FCCB44274CEULL, 0x0A44CA82665F33D3ULL, 
            0x58F2108479CFCD2CULL, 0x98129F77343BA330ULL, 0xA523C4A61DE86C91ULL, 0x66FCD89817960310ULL, 
            0x22F4616FCD2A7988ULL, 0x8F5693A1E3CC50F6ULL, 0x36DFFE3990E2A135ULL, 0x87F77C9000C7049FULL
        },
        {
            0x988FDC6CB10FE19FULL, 0xADE9CAA47E381E20ULL, 0x17AC2BC27A8F5EE8ULL, 0x6BEC7FBB3DB40531ULL, 
            0x75E3E909F2291F40ULL, 0x0CDD63B0488CA2F1ULL, 0xFEF44E8D8A9DD401ULL, 0xA99A3FC9C2C3ECC9ULL, 
            0x97323D81A2F79302ULL, 0xA8C487522484CD9BULL, 0xA5248FB3241E1C78ULL, 0x41C8645F641FBB12ULL, 
            0x242038CC9977A4FAULL, 0x27B70CAD67F431E7ULL, 0x41E64ED4EE064B4AULL, 0xC0A96D15287DC829ULL, 
            0x0F2D933E981DDE33ULL, 0xF84D9F9162A83016ULL, 0xFF560C8FB9B64632ULL, 0xD1B4881B624F4A43ULL, 
            0xA2F9E33D504926DBULL, 0x6E74C0D16B35104AULL, 0x545557E311715BCFULL, 0xCD3B0E19AFEBD680ULL, 
            0xA51D9D068B177056ULL, 0xE2404DCEB5206CA4ULL, 0xD1249C0FA2112590ULL, 0xB4624719D9C45C91ULL, 
            0x8C0E5D07FD4C7536ULL, 0x631B68E9A648580FULL, 0xEBEC949766BDDC3CULL, 0xD5D33CE47509784EULL
        },
        {
            0x320F80FCC24A12E8ULL, 0x6796C4CAA443C56BULL, 0xB3C67C71172088EAULL, 0x4D573D239CFCD661ULL, 
            0x1DB49185F26F6B88ULL, 0x2F0153A8EBBBE5AFULL, 0x66CAD1BAC2C2AAEFULL, 0xE5A857F4D72DEB0EULL, 
            0xFAF9895FD0DC5827ULL, 0x45725CCFF1011AA8ULL, 0x866391111F39EEBCULL, 0x3D33DE9450D7AB8FULL, 
            0x6F96D775A211E85BULL, 0xCFAEB0457AE1C357ULL, 0x5B388DD64CC9C489ULL, 0xCACA963116251C29ULL, 
            0xCB71F65DA3322DB4ULL, 0x44D2310315375BF2ULL, 0x7A0A7B1902C9F34FULL, 0x0E0754051098545AULL, 
            0xE4806D3CBB154B13ULL, 0x4F564842EFBC7871ULL, 0x1E63B94BBB9F77D8ULL, 0x031020ABF11B53F3ULL, 
            0xD0ABB1B3AB6EA0F1ULL, 0x975E658F045DE889ULL, 0x92934C9C6BEB9B78ULL, 0x89EF793212AD1FDBULL, 
            0x555AC3451DBB8D53ULL, 0x9C5A44FBB50F18FEULL, 0x2F0F9193AAF2A35FULL, 0x4190A4D68C26D9D0ULL
        },
        {
            0x0819191D9F45CCF2ULL, 0xDDBA76A886D5B19EULL, 0x3F26091412A75AD6ULL, 0x836B5A8FD0156369ULL, 
            0x39423E2CB6963478ULL, 0xE52201C5AC832441ULL, 0xAE6A0B4AEE8609EEULL, 0xC3D585E00825A6AAULL, 
            0xE39E19B15644724DULL, 0xE2593888D4E69CD3ULL, 0x67305ED871AEC83AULL, 0x2CE7E60957ED4818ULL, 
            0x62163A39609C8AD0ULL, 0xC5126892D01E0CF0ULL, 0x94C50ED4B6AD7919ULL, 0xDFF56A28F8C68694ULL, 
            0xFD3687D5EF089399ULL, 0xAB85E55EB4448E4EULL, 0x9C5043AEFF557F22ULL, 0xCB70DCD573839E64ULL, 
            0x11891F56EA3998F2ULL, 0xF9BBABAA64A1C96AULL, 0xBC3E57F76146A5A3ULL, 0x0FAD3E48AA9202A6ULL, 
            0x9228E083262E8F73ULL, 0x7417E7E6DF364B52ULL, 0xC65C4FD21A83E8B0ULL, 0x42896A833F0E22CEULL, 
            0x24CE3BEF747B7C88ULL, 0x4096E3A56E56D5F5ULL, 0xB20F6142C5F5488FULL, 0x9628CC7A31EB2451ULL
        },
        {
            0x25C4A246FB450C69ULL, 0x7204F3DDB37D014EULL, 0x563E1258B2924D55ULL, 0x8EEE40CB2B9497A8ULL, 
            0x1DC6777F9E1277CEULL, 0xCFBB816F206C9838ULL, 0x0A56D452F3174347ULL, 0xDFA7B584F3F51CF7ULL, 
            0x447983568AA58A6CULL, 0xCC00EE932B8A6FE1ULL, 0xF3859E621E780F66ULL, 0x27F0FCFF75185BEDULL, 
            0x6B876E267EC5BC48ULL, 0x5E9EF9C92764B52AULL, 0xE614C1BD0B4D9921ULL, 0x431317BF360C1F67ULL, 
            0xF1DF4CEBF4741170ULL, 0xE753F10555FED678ULL, 0xF88E54D67C236556ULL, 0xEEDAEA7EFE33C5D0ULL, 
            0xD24AA6283A6A593CULL, 0x404CA948C9652276ULL, 0x5F901A594EA42773ULL, 0x29C577C335BCC96CULL, 
            0xA71761F86478F7E7ULL, 0xFC6192A634C459D0ULL, 0x4076E76F4FFC1D06ULL, 0xA1DE26D97BAEF9D3ULL, 
            0x99F217C0AA8593BFULL, 0x87BB9BE6D9035783ULL, 0x950E5187D2A58678ULL, 0x016FC49F629D5058ULL
        }
    },
    {
        {
            0x76E438AC2CD59E18ULL, 0x20B1694A493B1E1EULL, 0xFA44864018278A06ULL, 0x7E85C44FD26A3DE6ULL, 
            0xA1212318AE9A128FULL, 0xD7CF01D70B8ED5F2ULL, 0x2073095F5BCAC5F8ULL, 0x13F04FCF76C80E7BULL, 
            0xD901A4CAA0507AB9ULL, 0x6E60AD59A74E25BEULL, 0xDAAF7D8264B6EFD1ULL, 0x9A8ACC9945387703ULL, 
            0x19E115865DDC983DULL, 0xBF66FB8BA00A5F62ULL, 0x37C6AA229CAED79AULL, 0xA8A4B6D7E8E86B42ULL, 
            0x7E1B39D91D29CF27ULL, 0x2123F257E61A6E38ULL, 0xDDFE522793B12CF6ULL, 0xD398B7823E75B29FULL, 
            0x1AA9AD99B0108307ULL, 0xB1ADB0FF78EC5E55ULL, 0xF7B43C576168824BULL, 0xBC3C9E7F2B158EFFULL, 
            0xC090E67965C05B6AULL, 0xBB7DECCE4C4CF122ULL, 0x24F7EEB6BDACA50EULL, 0x4E41F78AB27371AAULL, 
            0xF8639451B554E3E4ULL, 0xA73C0110240E2C13ULL, 0x3622FAD3673F2C1AULL, 0xC3AEBD25673F73ADULL
        },
        {
            0x58F30E6B28683C00ULL, 0xFFE1634DADE347A2ULL, 0x3187737FB2BB52C2ULL, 0x2C1BE46D867C91BBULL, 
            0x1BD435E9A0B14536ULL, 0xFAEA56B5788A232BULL, 0xCE06483F6951131CULL, 0x8A1C07661099094BULL, 
            0xFC2C57DC94712AFEULL, 0x3CEC98AD4CA4258EULL, 0xE57781CCAFD41F84ULL, 0xE4D6BD05C7DE523FULL, 
            0x2D28C43AF8AF6C2FULL, 0x19617C691B2175C1ULL, 0x3786EFCE9E75A685ULL, 0x641B887B2C74B26BULL, 
            0xB588AAC8FE7BB175ULL, 0x76D50AFBD31E6B5FULL, 0x750F99C9C45D3CA6ULL, 0x91329A6C19EEF3F8ULL, 
            0xA61D8246006BB2C3ULL, 0xFB4E1220BFFE3B21ULL, 0x968909D1E48D42DBULL, 0xD846575CB5714CF9ULL, 
            0xF007555D02240CA4ULL, 0xD0A3A755CC30B6EBULL, 0xBEE1B5AA8E86A132ULL, 0xD45060FB5C3EEE2BULL, 
            0x771B55D3654E2E9DULL, 0xA503A9EB511D5386ULL, 0xAA02036574C62153ULL, 0x33AA957B0EC6BC2EULL
        },
        {
            0x08CC7B169AE72691ULL, 0x7408C30AC5B6DE48ULL, 0x6B6BE5686DB15706ULL, 0xCA946CE965A0B514ULL, 
            0x1EDE6B0BB9269C66ULL, 0x586561B6D3061CDBULL, 0x371F0AB4F1384926ULL, 0x67CE6A8865AE3091ULL, 
            0x26EBC4864AA5562EULL, 0x1262BE598B8AAA5FULL, 0x2CC20ACBDBC3865EULL, 0x26FA18021EAF9704ULL, 
            0xFBCF7662CBB2F96EULL, 0x9E984452BD168BD2ULL, 0x390D1DAFB1C4D6DAULL, 0xBA60543E657D5952ULL, 
            0x693A77B33609779DULL, 0x24D59C11D7C53FA3ULL, 0xE8241218A7626887ULL, 0x6D0C7AE8111FC52CULL, 
            0x2F8489CF06E1913FULL, 0xC706029E7C829731ULL, 0x883B67F90F429299ULL, 0x4D9950D273B034CDULL, 
            0x04A8DF8BC2C652A3ULL, 0x6EC80D8CCC8137B7ULL, 0xE2330227BE4AE9BCULL, 0xF5ECD4A2BF938E5AULL, 
            0xCD44548CF65A5A1AULL, 0x989A6338AB2E64E3ULL, 0x36931E898769D2ABULL, 0x4D43D3FA58F2F9A9ULL
        },
        {
            0x952D2612D226D571ULL, 0x025A30C6E1549096ULL, 0x1C70F8B5317E7ED7ULL, 0xB03CD86F9A8E9E6DULL, 
            0x245E0B00863CE0C8ULL, 0x98EB4BA6B20B608EULL, 0x71514812E558A954ULL, 0x050A7B57944B5749ULL, 
            0x6CDD97FEE80EDED1ULL, 0x7C0AD559897E9A36ULL, 0x87DED51E24A53D4AULL, 0x76637B494D1EFD60ULL, 
            0x347B34D49379E655ULL, 0x264F4267920BB4C0ULL, 0x859D9B6B6631F654ULL, 0x7135C17C0F9495B1ULL, 
            0x63A731FB0B76BF03ULL, 0xC679944E5F316605ULL, 0x827E71CF9EC10739ULL, 0xBA135989F0BFF1BFULL, 
            0xF79A7E4C990A1295ULL, 0x24F3E101DD255B19ULL, 0x6C43F8DE05C9F9ACULL, 0xDBDD6066A7686500ULL, 
            0xD4FEA0F3C8A33F4EULL, 0x10AEC6E86A926023ULL, 0x91F5DEC1551EE710ULL, 0x4FCD8674C54748E1ULL, 
            0xBEF391AC374A19D3ULL, 0x1C5FB0BB74F6BAC9ULL, 0xDF42AD0E6D5711CBULL, 0xD52BCBE2977B2C96ULL
        },
        {
            0x8EE0CC3F41023819ULL, 0x595223997A41B06DULL, 0x659F2A676CF2462DULL, 0x4776176644ED1E35ULL, 
            0x651F360A4446E7B1ULL, 0x20192F15DD43450AULL, 0x8B4A568E9CE4BC75ULL, 0x48F95F0D1F8BCA91ULL, 
            0xFB7077430D7CE273ULL, 0x25B1A35CED96ED49ULL, 0x8A70494E96B928C7ULL, 0xE871C183C4FB7228ULL, 
            0xE97724AD6500C068ULL, 0xA22162FE927A7133ULL, 0x2370A114B1CC1F23ULL, 0xBF7346C1D1032B1FULL, 
            0x39A06204E3A423A9ULL, 0x580C82F20757841FULL, 0xB9E98670186E4B64ULL, 0xF6B029A7174850DAULL, 
            0x4F137B26026DBD83ULL, 0x8B3CFC7EAF42B9B9ULL, 0x47137D9E1098E5F0ULL, 0x3E2C389D46702F34ULL, 
            0xB75C34FE60B84937ULL, 0x94B10D8357EA8247ULL, 0x5B11F84D54767395ULL, 0xDFF59FA6C1F5059CULL, 
            0x8A2E4971866A115CULL, 0x0EBDF6E13401FFC0ULL, 0xF6DA3CD3BBB225B0ULL, 0x4A2ACF22867FDDD6ULL
        },
        {
            0x63DDE3E29EE2B2ECULL, 0x8C1EC348FFF0EF2CULL, 0x84EF79D91D342A06ULL, 0x1F48E933CA8CF50DULL, 
            0xB8EDCEDD63213EAAULL, 0x5E988C263FE72A05ULL, 0x81C84CEC8931DF3CULL, 0x01E80B4AAAB4056FULL, 
            0x7088CDCFBD44FFC4ULL, 0xC0A62A996BEFEB9BULL, 0x4C475F5A457539BDULL, 0x97A41276E72635D2ULL, 
            0x06754A0565F423EEULL, 0xB2AC3EF2AFF89FCCULL, 0xD9EC0E1ECA5B8CCDULL, 0xABD78C07613EC81DULL, 
            0x62D802FACA738523ULL, 0xE15C2133B7B7B4EBULL, 0xC22F00DB8210B363ULL, 0x627306FBE05DBBECULL, 
            0x9166367A3B9BC267ULL, 0xEE5DE3A80AE033E5ULL, 0x3A47862C23CB3F8FULL, 0x15C4D02671059610ULL, 
            0xAB17AD347654CF00ULL, 0x8728BC99BE9A8EDFULL, 0xAFDC416621E79BA1ULL, 0x398E358C47004449ULL, 
            0x319739E0276A424BULL, 0x05BA69237B53EA09ULL, 0x74101745F01C71A4ULL, 0x4B0C24E3C079A489ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseGConstants = {
    0xC0B4ECD3D096DFAEULL,
    0xF00B8C82337A88ECULL,
    0xCCFEC43D6DE05B9CULL,
    0xC0B4ECD3D096DFAEULL,
    0xF00B8C82337A88ECULL,
    0xCCFEC43D6DE05B9CULL,
    0xACAB696556133AB4ULL,
    0xAE464E4D4165A550ULL,
    0x28,
    0x13,
    0x40,
    0xF4,
    0xAF,
    0xD8,
    0xF4,
    0xD0
};

const TwistDomainSaltSet TwistExpander_Karate::kPhaseHSalts = {
    {
        {
            0x14155CC83FD9C8E7ULL, 0x48BB5A5DB1A08F92ULL, 0xB9F2417C1E034152ULL, 0x3D622A994D210AA5ULL, 
            0x21FCF612FC89AB06ULL, 0xA7DB2CCE9DB2F169ULL, 0x4C06F4E484F0DBF4ULL, 0x8EFF2EF5ECCBB2A8ULL, 
            0x54B36D3013C71DF5ULL, 0xA36A64DE8A418A3AULL, 0xEDFDFA8561B58DE8ULL, 0x115863954E9580C8ULL, 
            0xB9F537991F0CCE57ULL, 0x31BC7D8FCDED3BC8ULL, 0xCD41DC1E5DA9CD6AULL, 0xFA1D31DAF6209758ULL, 
            0x31B4CAB7A376D0C3ULL, 0x40B6D3D2E645EFD0ULL, 0xF22C71A7CCF3FE13ULL, 0x371EB544B12FF2CAULL, 
            0x87352B6E0A35DC95ULL, 0x553946914226DB69ULL, 0x534D99C4C61132B7ULL, 0xC9959836D8330F82ULL, 
            0x5318FA3209C5B6D9ULL, 0xBA23EB68D578961AULL, 0xE84ECC2A7CDA4084ULL, 0x885135295088BE94ULL, 
            0x46CAA2ED33B8C083ULL, 0xF7D7BBEA59089AE2ULL, 0x1726A97298B2E4C0ULL, 0xFE1F08DE7E1A6134ULL
        },
        {
            0x72A9B92C20B47991ULL, 0xA6DA0C55D57889E7ULL, 0xF4508595EE59C3A8ULL, 0x1D70ACB069ECB35FULL, 
            0x584158DF90FB29D6ULL, 0xC9ED198F8A880C85ULL, 0xAAFF7E3079982A75ULL, 0xABA132CFA0DD7DA9ULL, 
            0x78EE1822926B2D99ULL, 0xBBFD7B0D3D687093ULL, 0xF7AE5BBABCE6F004ULL, 0xCA13812AA9AB9441ULL, 
            0x1FA29DC1C8AAF764ULL, 0x7B99C61990BD0262ULL, 0x9120988DD3B9B30AULL, 0x4A3870D3A2619C9DULL, 
            0x3C8CD9019E52ED34ULL, 0xD715F240CC908E32ULL, 0x1F5A8CAA106D157CULL, 0x9AD7427EEE86F671ULL, 
            0x92E45D2976958322ULL, 0x3EC80F15A4553075ULL, 0xD8F49FDB0A47C1D2ULL, 0xEFEA4F39AE780F8DULL, 
            0xAD0115EB5FF9883AULL, 0x161CB9BA56A8F0C4ULL, 0x13C5EF7104D2C217ULL, 0x3EEBA5B9686EEDFAULL, 
            0x7C393F3F410B035AULL, 0x2EC892E7AFE84927ULL, 0x2165BEF73D4F8719ULL, 0xB8C920FE767EF5DEULL
        },
        {
            0xE3843EDF74FD0BDFULL, 0xD3D24CFBE62B5B5EULL, 0x74CC3F3DDDD4037CULL, 0x6A8E5E91C9C48C29ULL, 
            0x26698D391FF0D308ULL, 0xAAFE6EAE31A38540ULL, 0xAA2BC27F7BE53327ULL, 0xEF5002CD82285A6FULL, 
            0x6FA8DD85115F3C91ULL, 0xD2272C6924B55779ULL, 0xC91669854CFC0303ULL, 0xE61587022DD41D86ULL, 
            0x5A303D31B5DDD3A8ULL, 0xDDD32F1E715DFB69ULL, 0xCFF151787E5D0F5DULL, 0x90911671EFA6C267ULL, 
            0x8E89ED71290EDDA7ULL, 0x800D08D361890C1FULL, 0x106984654A2AE4CFULL, 0x8DCA8F1F61A30CB0ULL, 
            0xF7481312BF484BAEULL, 0x74BD1DBDF51708FFULL, 0xA08EDAE57F9BD94CULL, 0x4DC85115E9390F57ULL, 
            0xD1FFDC9EA0EAF38AULL, 0x2B9BB0314F331012ULL, 0xEC9D2D62898AD87EULL, 0x8408BA820962F9C1ULL, 
            0x03ED8068765281D5ULL, 0xCB375FE2EF196E77ULL, 0xBFB4CF97B323C754ULL, 0xFA4E749C8CE1211CULL
        },
        {
            0x916EAE300654955FULL, 0xFB9E27D42C2D3CE4ULL, 0x47E3100E22790D3FULL, 0x6D90FFB9DAB5B1BDULL, 
            0x6930ACC458A42DC4ULL, 0x95CE8FB07220CD98ULL, 0xA0D1C93917C4A739ULL, 0x1DD0D665DC64D410ULL, 
            0xD126F2E149402E34ULL, 0x00B508E509B1CAE0ULL, 0x53E9AD8FE636A942ULL, 0xDD1800C9D7A0C051ULL, 
            0xF73EDD0B0250F9A8ULL, 0x338031140099AD45ULL, 0x8A6452D2731004B5ULL, 0xBFBF1E31040C39D1ULL, 
            0xECC4A987ECC4C462ULL, 0xDE290BC3450B11C4ULL, 0xD66B0F6B6C0603C6ULL, 0x1C2849D915CCC816ULL, 
            0x7322650CB95FCA21ULL, 0x6AA3A5FE0386396AULL, 0xF94E023AE03A722CULL, 0x43ACAB1E4C690937ULL, 
            0x4B0017FBA20BDF22ULL, 0xEDB5E8B065AFC8E3ULL, 0x626687AD84554D87ULL, 0x1EBE644B7A77EE67ULL, 
            0x732FC9DAF1A07A0BULL, 0x9AB44910EF6AD617ULL, 0xC078E00CA2BAA7C9ULL, 0xD94CBAFB134D5236ULL
        },
        {
            0x3D3B9A53C3189B91ULL, 0x3C443B0F8562746DULL, 0x9F2801F53DD7A2EBULL, 0x4F8BB77BEDFB1C9FULL, 
            0x583F3DE31EEDFB88ULL, 0x28B08D33C5404EB8ULL, 0xC8F074FEEDCA5263ULL, 0x825F3F6E9715106CULL, 
            0x23975976D25345E6ULL, 0xEF71FA654546DC56ULL, 0x6754793B0E8DBE5CULL, 0xF29F519421CDF282ULL, 
            0x4130D098C4BD3759ULL, 0x36D38752CBAC0765ULL, 0xA187FF72249E99B6ULL, 0xB2EA45AC9C048699ULL, 
            0x9B0BC0B4F9283A84ULL, 0x7D4999894EE37809ULL, 0xE107682292398422ULL, 0xCACE8E5CCFE1F55DULL, 
            0xCDB796536E4A74C6ULL, 0xE5F373D96AD889CDULL, 0xEF87FDC4296B1A57ULL, 0xE6E569A4162261DDULL, 
            0xD917E79AACBB9D2BULL, 0xF57F3EB151422F15ULL, 0x9FBAD6CA21574045ULL, 0xC9DFAC51474345B7ULL, 
            0x935D97EC62317797ULL, 0x808927B918608B8EULL, 0x7CE6495FC8AB62ACULL, 0x1D8D94EF940359CDULL
        },
        {
            0x56E07BCECC2417C1ULL, 0x107D88D78D27ADA3ULL, 0x72D7CDD3249E0168ULL, 0xA76A620D9FF05A33ULL, 
            0xB6951D14DAA648B8ULL, 0xDB605E846847B7B6ULL, 0xD6B1C7A38D0333DCULL, 0x211692EAB54B7B0CULL, 
            0xAAE24ED6492898FBULL, 0x0321CDCB77C2D27AULL, 0xB8EFAB11D270CC47ULL, 0xDAE48D8A46E51340ULL, 
            0xA8A15B1F2F5071D9ULL, 0x1CBC6B85089255B9ULL, 0x47F8B01E0BEFB18EULL, 0xD7BC72AE084D6FC5ULL, 
            0xF03C057FFD50BAA9ULL, 0x00854F1A2ACF979DULL, 0x4F54D4B463C6854BULL, 0x05BED17494DA153FULL, 
            0xD928B90A8A432270ULL, 0x42C476E8849457CFULL, 0xC8BBED9A7401B309ULL, 0xA2AD23E7E699DF2BULL, 
            0x0E8429E37715334CULL, 0xBD81D56DF0F8670CULL, 0x5B5031E2EA341CA9ULL, 0xF2E19612670E499FULL, 
            0x88177F9B74281CCAULL, 0xD838642FD96ED9CFULL, 0xE458FEC904EC96BEULL, 0xB09C76C455DB186CULL
        }
    },
    {
        {
            0x013B890DEF139394ULL, 0x005C96AEE39F3E37ULL, 0x2F15C54199831A29ULL, 0x4BBAE29CDA3C1392ULL, 
            0xB15983268A21E626ULL, 0xCA6113DA98E0E08EULL, 0xED5B547CDDD071A2ULL, 0x9C2B2F3552DF0764ULL, 
            0x285B0100A0D93444ULL, 0x249A2960B73F2728ULL, 0xD080038AE4CFADF2ULL, 0x82842693122CC32CULL, 
            0xA05F476E6CED1AF6ULL, 0xC15AA01F1006D7DEULL, 0x7C73F6B3296735A5ULL, 0x66E3B7B58A546CF0ULL, 
            0x9AE1BE0D8642F7B7ULL, 0x1C27AB9E776DD786ULL, 0x42CB56F3F1F6CD25ULL, 0xBE522022294DF1B9ULL, 
            0x00AF883D09213596ULL, 0x85C9FAF81D8488E9ULL, 0x5A6D0C17AD1B2B89ULL, 0xEFA32855A2DB3209ULL, 
            0x9500F610CE361EB3ULL, 0xC10B7970D1029684ULL, 0x1EAF3D96169C10F3ULL, 0x795EF3F81BDE69F5ULL, 
            0x6EB671B25BEF325EULL, 0x6546F212B3CFDA99ULL, 0x10608A6CAED19E7FULL, 0x4C6B7F7318FA6FE7ULL
        },
        {
            0x51D1F4EB9C8DEFD5ULL, 0x610A0DD2317E7986ULL, 0x066B77C1CA19E4D9ULL, 0x2FD98782E709F855ULL, 
            0x2E3444707963D78DULL, 0x7886F56122E4EA32ULL, 0x588BB5577FD1108AULL, 0x0281A4AE9BC224E1ULL, 
            0x39063C2853151766ULL, 0xBD9451E6513B4A94ULL, 0xDE1A91B9B8799EE9ULL, 0xC6865D48C19D3D08ULL, 
            0xF00C4006885ED65DULL, 0xFF1E9EC85697ABF8ULL, 0x31B96B61116DA4D7ULL, 0x9024AB4104E47509ULL, 
            0xD043E9A13093BAB6ULL, 0xD154E0D3236F963BULL, 0x937F885F10CF3C76ULL, 0x23C5DE2908BE3B0BULL, 
            0xE22C1C1423933BD6ULL, 0x208C02C438A1E733ULL, 0xE79F9C53D644A697ULL, 0x2B18FBB99D449D3AULL, 
            0xDE9EE4AA2F5E4B38ULL, 0xFFB2121553D23C85ULL, 0xCB8D9A5427080F10ULL, 0xE55FA4136DE557BEULL, 
            0x855BAE6263426481ULL, 0x07B3BC0D49A7134DULL, 0x9BC9AACB0146040DULL, 0xFBF5008125D228DAULL
        },
        {
            0x2B7BF0EB9FC3F26EULL, 0x9CD6632FF580DD42ULL, 0x3B1F3D8F0013068CULL, 0x0E230C29A06FC683ULL, 
            0xD28291EC6C549F6FULL, 0xD6DACE30047D9A1EULL, 0xE5F24B02D3589899ULL, 0x71A3E5933F7E21D9ULL, 
            0x9B300B66AE67792DULL, 0x94A2193C5A71A3B0ULL, 0x6A17E471671F75EEULL, 0x86B7E2BC60C7EE79ULL, 
            0x880788EEF5411480ULL, 0xBADEB673F50C31E2ULL, 0xB7DE1018BE4EE261ULL, 0xB58BFFAC1394B870ULL, 
            0x7FDFFDA188C2B989ULL, 0x938BEEE9CC37DC61ULL, 0x6F3C099C66A38387ULL, 0xC3C235AB0E66B232ULL, 
            0xFD9229D2F6446D10ULL, 0x23F099DB6FCDE544ULL, 0x783F844408A4B49EULL, 0xEF9F3E5D1B5D29E9ULL, 
            0x1D66082A4DA65B35ULL, 0xC5B54778E08B7EEEULL, 0x4BC87CD1AC6621FEULL, 0x76FF2817C807D309ULL, 
            0x2C76B44C52E6A9D0ULL, 0x8CC8A82FB93F4F32ULL, 0xEB5FD36FD524453EULL, 0x0016AB0B86ED0DCCULL
        },
        {
            0x24FC2A40EAD81358ULL, 0x49EB7BD9801E67CFULL, 0x801498FDB7847253ULL, 0x32F4B11C9B60671DULL, 
            0x433FD59B42BC1CF0ULL, 0x473CB489E4E3246CULL, 0xABA8C5767E6BDDCAULL, 0xF0BFF57D9C1E8F96ULL, 
            0x8C27CEEAC70F9DFFULL, 0x06D00EC31750E922ULL, 0xB21E387B59ED799DULL, 0x327F7E5CC443DBA4ULL, 
            0x0CB05D3196B445E1ULL, 0x26424299F8150FF9ULL, 0x7CBD28920386CE8BULL, 0xC8C64E7A211E8528ULL, 
            0xA18236A2311FDD70ULL, 0x2F13362BBAB8DA69ULL, 0x01D1305252775DF9ULL, 0x9EB53C9CD1AC4D5BULL, 
            0x5B0A0E4442F0A62CULL, 0x31B9F1A219DF9DF8ULL, 0x01F2651A548055CBULL, 0xAB2C255C9B1AA5D1ULL, 
            0xA8F6E045B54DC370ULL, 0x712786EAD54E7AE6ULL, 0x72953397940CA36EULL, 0xFC3B46002A233322ULL, 
            0xEEA27E2B6C294BB4ULL, 0x8177AD3B318D3890ULL, 0x9CB439B3A2B28BE2ULL, 0x86E8A3222781F33BULL
        },
        {
            0x7C3738000BA160F2ULL, 0xE23E38FE006CF199ULL, 0x53B3E88562E59F7FULL, 0x990704BF59DF52EFULL, 
            0x5DEB9D319907E7C5ULL, 0x178CC14DAAF2764AULL, 0x140A3FF192F7646EULL, 0x332A6CC478E144A6ULL, 
            0x2675DBFD71E9DDB4ULL, 0x5589726A3184FC44ULL, 0x91E3E1EE56861386ULL, 0x79B6CC2782FE948EULL, 
            0xACB358CDF2DFBC14ULL, 0x72BA424C193D6426ULL, 0xDBEF549094657370ULL, 0x9139AA088ECAA1D3ULL, 
            0xFAFD4230E5707F0FULL, 0xCD80ED0004AAC7D5ULL, 0x684C7E3071F809B0ULL, 0xDCB3A68E663C840AULL, 
            0x9663ABA3047F58C5ULL, 0x4255F52B0F3384BDULL, 0xC2C43601475376A9ULL, 0x9E0678BA58434BFBULL, 
            0xA0611377AA522A53ULL, 0x6C7A0D574329D088ULL, 0x7189EEEBD15E1055ULL, 0xAC98FEB79C6D9A84ULL, 
            0x2544502460B1F0B0ULL, 0x8F4AFD3A582FE97AULL, 0x987D6ADE0DED0DCCULL, 0x91A2553FC4086304ULL
        },
        {
            0xB7EDD534394A4646ULL, 0xA79A403840FDDDB5ULL, 0xEA15ADA7FB16C5A4ULL, 0xB5C7CD4347C75DDBULL, 
            0x98473C21645E5C8EULL, 0x906A128AE23738CDULL, 0xCB47E15302845189ULL, 0x15A22F49E7EB747DULL, 
            0xEB52F0F88D37C6FFULL, 0xC4E2EC8F3ED93D99ULL, 0x4EB9FA59F1FAB295ULL, 0xB04B8345B0182656ULL, 
            0xB693567420A1DA3AULL, 0xDC6DECD60FB98005ULL, 0x3E82DC97748AEAEAULL, 0x31F18029B339630CULL, 
            0xD117FE89BAA34638ULL, 0x850688112DD0BEF0ULL, 0xB2F3FFAF25DFE62EULL, 0xC276A238EE0F683BULL, 
            0xBD1198B0C35F1453ULL, 0x50F3EC9FB1717E76ULL, 0x9E26ED13F69DD727ULL, 0xB65E4638ED7CA72EULL, 
            0xA38B96733A3F7357ULL, 0x78405BEDC0B08DF4ULL, 0x809DAB199111658DULL, 0xCA0A3B31D3426A38ULL, 
            0x4B1338E776F27779ULL, 0x6BC2ABAB45BC3D46ULL, 0x280F2A05E8EC94DBULL, 0x6D6DB8E53D1209CFULL
        }
    },
    {
        {
            0xA4F602B66BC64ED0ULL, 0xAD60AB8A2FC3E5E1ULL, 0x5666408D4497D85CULL, 0x509E0AC496B651A5ULL, 
            0x026D6246D21D4B75ULL, 0x4E3949AE6AF6A0D3ULL, 0x9AADF264AF3918DAULL, 0x8B9AE89E78F7354EULL, 
            0x8A30F3CB523E3010ULL, 0xBA1FEE269A8EFB15ULL, 0xA31AB709D00481E4ULL, 0x2EF4B5F56C9D270BULL, 
            0xBBE91DC2ACCD1041ULL, 0xA2E89AD7E32C7458ULL, 0xB01E7DC884AD4221ULL, 0x3F9B69792AA16271ULL, 
            0x57475351C09D1145ULL, 0xDE04F76044E3B4DDULL, 0x8B4A5A4391E95D11ULL, 0x02861E3642319348ULL, 
            0x3C8388370C09740BULL, 0xD2FDED21ED734E27ULL, 0xF0E25E94A2A19C1BULL, 0xB1BEB24AC9F935DEULL, 
            0x44EBBD96E9B15686ULL, 0xE3824D150DF7EA15ULL, 0x9CB2789A215D10D8ULL, 0x23D2F022665C07C7ULL, 
            0xAE04FECF601BF5C1ULL, 0x3D0E78DE1F12BFDAULL, 0x3531D1F3B521FA59ULL, 0x596351B81716E3E7ULL
        },
        {
            0xC217996EDDA7452BULL, 0xBE678502DE66FED0ULL, 0x29B3F550E1F3EC5AULL, 0x94AB1AFFBAC14D92ULL, 
            0x34B167BBA21661C5ULL, 0x0FD4EA47F04BDF09ULL, 0x4E7C6A48930A93D1ULL, 0xECA8097F5081A969ULL, 
            0xA3259DB3E22979CEULL, 0xA31B8ACD3E181D04ULL, 0xFC8AD0B891D3C23EULL, 0x66DEF66228297B63ULL, 
            0x8734C803121C6F33ULL, 0x9F1E34D7E081AA33ULL, 0xB7087E7D3EC9786AULL, 0x0448F675E3E6ACBEULL, 
            0xD0EAF7FE39E9E128ULL, 0x4776FBDE6A9EC4F4ULL, 0xB8EA2642CF65E366ULL, 0xD16BB1AA3BACDD83ULL, 
            0x6D95CC0FEDE5A1C7ULL, 0x3BBEE1A68DE37D50ULL, 0xEDB469855BC7D5E4ULL, 0x56FBB1624E8127AEULL, 
            0x64AF7125F3070C86ULL, 0xFEE0776C809BCE6CULL, 0x3127E8800E1DF4FBULL, 0x8B8B0BB218BB28A9ULL, 
            0xC4412E8552EC189BULL, 0x5041F568DD18622CULL, 0x723CA64872CCD2B8ULL, 0x887F53C3029487A7ULL
        },
        {
            0x9252B6FFB7E73115ULL, 0x1348D25F14C5DEDEULL, 0x9BE9ECF179CCC4E9ULL, 0x14EA1D51B0323E99ULL, 
            0x8C95B46D3E7632BDULL, 0x94FCB5041D656640ULL, 0xDB7C349B8EEDF2E6ULL, 0x62D303E2996F5A7BULL, 
            0x8150DF6E81FF4047ULL, 0x064DD19CEE3D522AULL, 0x2D794D901944B8DFULL, 0x40A4838014131249ULL, 
            0xD06A2577C6B34F9DULL, 0x76D1746E6A0457ABULL, 0x8D8E949DC7C9985FULL, 0x1D819511F6F871EEULL, 
            0x25C03454EFD0BA26ULL, 0xFC3C8072E5C17AB4ULL, 0xAB1B9A1E296F1919ULL, 0x9A2550607C3AA2DEULL, 
            0xD5D446BA9FCC4177ULL, 0xAF0E1D5EA41ED952ULL, 0xE1ED3DF3D11BCEB8ULL, 0x5697417113CD3180ULL, 
            0x04E19A6139813CE6ULL, 0xBBDCDE240AB89703ULL, 0xCE82AC7C0AE1431DULL, 0x9286D441F878B8E4ULL, 
            0x025AD6FD50B053EAULL, 0x823F2930942C79A6ULL, 0x8657EEA961ECE80BULL, 0x8ED9CBC1B079D14EULL
        },
        {
            0xADE3AB59AED61641ULL, 0xFAB9E1DADB349EE9ULL, 0x9FAEDCBBC6B59CE0ULL, 0xB8AC3E1036732E0DULL, 
            0x52F5C00F427491EFULL, 0x9B26F8806CEE63F9ULL, 0xA784D9B9713F032AULL, 0x627EB4B4AFB48AB0ULL, 
            0xDC9711655B7D13A9ULL, 0x724178DAF7392E7EULL, 0xC3E57F38989B5D7FULL, 0x64F8F541BCAFC367ULL, 
            0x15CDBA90BC000F12ULL, 0xC62D480540EF59F4ULL, 0xDC5ECDA3D5E3C681ULL, 0x82F90E053D1BE08DULL, 
            0xDCC6999B5EB664EBULL, 0xEBC87BC33AD5AFFCULL, 0x2F2FF35D95BDA8AEULL, 0x7D5C93C23CCA7036ULL, 
            0xE56814F7B1910892ULL, 0x2F2D294E79D54BC8ULL, 0x37FB87A49E1E76C9ULL, 0x9541FFD873CA978FULL, 
            0xBCCD335DBBC329E7ULL, 0xF82307B4DB21B263ULL, 0x5E89CAF16789491EULL, 0x8120CD4C63DF42E3ULL, 
            0x9AE0D3CF6116643EULL, 0xCC7E259CA27960D1ULL, 0xFF92196A032B1632ULL, 0x6078C222A27798DCULL
        },
        {
            0x2EE0B6478B9205D5ULL, 0x586F1D6B7762105AULL, 0x2A1C6F7C4AD088EAULL, 0x15BC9CEBE3F3F138ULL, 
            0xE2DFF409C0B7910DULL, 0x589841E71F00A00DULL, 0x4E59844E4988C44FULL, 0xADD151F7C80EE70FULL, 
            0x0914CF28C74878D5ULL, 0xB9828667889DBCE5ULL, 0xB5130FD9B0973F6EULL, 0x59A299D692C78610ULL, 
            0x7C0856550F47BF31ULL, 0x0A2748E7B84E0891ULL, 0xF85C72A27C70D7B1ULL, 0x7C7BD095F4048EF4ULL, 
            0x978C40393C98B5C3ULL, 0xF41E222A51DD6A50ULL, 0x722D4B481B13088AULL, 0x79345B6D2B27274AULL, 
            0x6E8E7A114A8B5C51ULL, 0x862B9EE9298A2E63ULL, 0x9428D7D8E4CE35B1ULL, 0x6A32FA83687727F1ULL, 
            0x5C026C05102D4845ULL, 0xBC1BED08B9C4DFA4ULL, 0x73D28A18887C8968ULL, 0xC84C225CE544E002ULL, 
            0xC19180AEC7545298ULL, 0x01F1DBA3033732AAULL, 0x967CC06A71061DF8ULL, 0x5C12838217A6A4B2ULL
        },
        {
            0x46ACB1D2F87B4F78ULL, 0x4C25950B2990AB59ULL, 0xA26F05547FF3FBCBULL, 0x409E7DDD65E1DBCCULL, 
            0x16A05FE10575DA17ULL, 0x00DE0F47EF1C24DFULL, 0x563A5A3F36AE4F44ULL, 0x3839208B47A3AB46ULL, 
            0xF8390D483FC7A02CULL, 0x457BA12FA577B571ULL, 0x82C92576EE7800EBULL, 0x074C9F9E7B33D891ULL, 
            0x3139B9D58B9FF161ULL, 0x18A7420C9FBC482CULL, 0x151F1BEC77199B45ULL, 0xAB6F45FE4C33B70AULL, 
            0x3129F841A787048FULL, 0x465C9D113DBE613EULL, 0xA2C2E8A811C8773FULL, 0xB648D3158E29BBE0ULL, 
            0xB4479B4A22BD0B2DULL, 0xFCC0F269096A91DDULL, 0x93E17524CA96C329ULL, 0x57A5C30540152F71ULL, 
            0xE3366C0AB1EBC783ULL, 0x26C4C59103A646BBULL, 0xC758D4C7254D71E4ULL, 0x78BE616B28628F67ULL, 
            0xB72E841646F73D61ULL, 0xCB38CBFB4BCAEDA3ULL, 0x37681ABD4BC3C208ULL, 0x5EEF137C26244019ULL
        }
    }
};

const TwistDomainConstants TwistExpander_Karate::kPhaseHConstants = {
    0x67FE8E2DCD08B76FULL,
    0x3B1A2F6A10A2626FULL,
    0x20077DA5DA3F73DBULL,
    0x67FE8E2DCD08B76FULL,
    0x3B1A2F6A10A2626FULL,
    0x20077DA5DA3F73DBULL,
    0x31D215FDF223AA4BULL,
    0x8A69FAE3845EA5ACULL,
    0xF3,
    0x63,
    0x22,
    0x10,
    0x0C,
    0xA9,
    0x67,
    0x4E
};

