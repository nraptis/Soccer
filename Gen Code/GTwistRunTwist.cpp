//
//  GTwistRunTwist.cpp
//  MeanMachine
//

#include "GTwistRunTwist.hpp"
#include "GQuick.hpp"
#include "Random.hpp"
#include "GSeedRunStageConfigValidator.hpp"

#include <array>

namespace {

const std::array<TwistVariable, 13> kInitialRandomVariables = {
    TwistVariable::kPrevious,
    TwistVariable::kCarry,
    TwistVariable::kWandererA,
    TwistVariable::kWandererB,
    TwistVariable::kWandererC,
    TwistVariable::kWandererD,
    TwistVariable::kWandererE,
    TwistVariable::kWandererF,
    TwistVariable::kWandererG,
    TwistVariable::kWandererH,
    TwistVariable::kWandererI,
    TwistVariable::kWandererJ,
    TwistVariable::kWandererK,
};

int PhaseIndex(const TwistDomain pDomain) {
    switch (pDomain) {
        case TwistDomain::kPhaseB: return 1;
        case TwistDomain::kPhaseC: return 2;
        case TwistDomain::kPhaseD: return 3;
        case TwistDomain::kPhaseE: return 4;
        case TwistDomain::kPhaseF: return 5;
        case TwistDomain::kPhaseG: return 6;
        case TwistDomain::kPhaseH: return 7;
        case TwistDomain::kPhaseA:
        default:
            return 0;
    }
}

std::vector<TwistWorkSpaceSlot> PhaseSalts(const TwistDomain pDomain,
                                           const TwistWorkSpaceSlot pBaseSlot,
                                           const int pLaneCount) {
    const int aBase = static_cast<int>(pBaseSlot);
    const int aOffset = PhaseIndex(pDomain) * 18;
    
    std::vector<TwistWorkSpaceSlot> aResult;
    aResult.reserve(static_cast<std::size_t>(pLaneCount));
    for (int i = 0; i < pLaneCount; ++i) {
        aResult.push_back(static_cast<TwistWorkSpaceSlot>(aBase + aOffset + i));
    }
    return aResult;
}

GSeedRunStageConfig BaseConfig(const std::string &pStageName,
                               const std::string &pLoopName,
                               const TwistDomain pDomain,
                               const GAXSFormat pFormat) {
    using Slot = TwistWorkSpaceSlot;
    
    GSeedRunStageConfig aConfig;
    aConfig.mStageName = pStageName;
    aConfig.mBatchName = pLoopName;
    aConfig.mStartLine = "// " + pStageName + " " + pLoopName + " (start)";
    aConfig.mEndLine = "// " + pStageName + " " + pLoopName + " (end)";
    aConfig.mFormat = pFormat;
    aConfig.mIgnoreNonces = true;
    aConfig.mHasDomainMix = false;
    aConfig.mDomain = pDomain;
    aConfig.mIsNonKDF = true;
    aConfig.mSaltsOrbiterAssign = PhaseSalts(pDomain, Slot::kPhaseASaltOrbiterAssignA, 6);
    aConfig.mSaltsOrbiterUpdate = PhaseSalts(pDomain, Slot::kPhaseASaltOrbiterUpdateA, 6);
    aConfig.mSaltsWandererUpdate = PhaseSalts(pDomain, Slot::kPhaseASaltWandererUpdateA, 6);
    return aConfig;
}

std::vector<GSeedRunStageSliceSpec> SixPassDiverseSlices(const std::vector<TwistWorkSpaceSlot> &pPrimary,
                                                         const std::vector<TwistWorkSpaceSlot> &pResiduals,
                                                         const std::vector<TwistWorkSpaceSlot> &pDestinations) {
    std::vector<TwistWorkSpaceSlot> aResiduals = pResiduals;
    Random::Shuffle(&aResiduals);

    return {
        {{pPrimary[0], pPrimary[1], aResiduals[0]},
         {pPrimary[2], pPrimary[3], aResiduals[1]},
         pDestinations[0],
         false},

        {{pDestinations[0], pPrimary[2], pPrimary[3], aResiduals[2]},
         {pPrimary[0], pPrimary[1], aResiduals[3]},
         pDestinations[1],
         true},

        {{pDestinations[1], pPrimary[0], aResiduals[4]},
         {pDestinations[0], pPrimary[2]},
         pDestinations[2],
         false},

        {{pDestinations[2], pDestinations[0], aResiduals[5]},
         {pDestinations[1], pPrimary[3]},
         pDestinations[3],
         true},

        {{pDestinations[3], pDestinations[1], aResiduals[6]},
         {pDestinations[2], pDestinations[0]},
         pDestinations[4],
         false},

        {{pDestinations[4], pDestinations[2], aResiduals[7]},
         {pDestinations[3], pPrimary[1]},
         pDestinations[5],
         true},
    };
}

std::vector<GSeedRunStageSliceSpec> SixPassTerminalDiverseSlices(const std::vector<TwistWorkSpaceSlot> &pPrimary,
                                                                 const std::vector<TwistWorkSpaceSlot> &pResiduals,
                                                                 const std::vector<TwistWorkSpaceSlot> &pDestinations) {
    std::vector<TwistWorkSpaceSlot> aResiduals = pResiduals;
    Random::Shuffle(&aResiduals);

    return {
        {{pPrimary[0], aResiduals[0]},
         {pPrimary[1], aResiduals[1]},
         pDestinations[0],
         false},

        {{pPrimary[2], aResiduals[2]},
         {pPrimary[3], aResiduals[3]},
         pDestinations[1],
         true},

        {{pPrimary[1], aResiduals[4]},
         {pPrimary[0], pPrimary[2]},
         pDestinations[2],
         false},

        {{pPrimary[3], aResiduals[5]},
         {pPrimary[1], pPrimary[0]},
         pDestinations[3],
         true},

        {{pPrimary[0], aResiduals[6]},
         {pPrimary[2], pPrimary[3]},
         pDestinations[4],
         false},

        {{pPrimary[2], aResiduals[7]},
         {pPrimary[3], pPrimary[1]},
         pDestinations[5],
         true},
    };
}

std::vector<GSeedRunStageSliceSpec> FourPassSlices(const std::vector<TwistWorkSpaceSlot> &pPrimary,
                                                     const std::vector<TwistWorkSpaceSlot> &pResiduals,
                                                     const std::vector<TwistWorkSpaceSlot> &pDestinations) {
    return {
        {{pPrimary[0], pPrimary[1], pResiduals[0]},
         {pPrimary[2], pPrimary[3], pResiduals[1]},
         pDestinations[0],
         false},

        {{pDestinations[0], pPrimary[2], pPrimary[3], pResiduals[2]},
         {pPrimary[0], pPrimary[1], pResiduals[3]},
         pDestinations[1],
         true},

        {{pDestinations[1], pPrimary[0], pPrimary[1], pResiduals[4]},
         {pDestinations[0], pPrimary[2], pResiduals[5]},
         pDestinations[2],
         false},

        {{pDestinations[2], pDestinations[0], pPrimary[3], pResiduals[6]},
         {pDestinations[1], pPrimary[1], pResiduals[7]},
         pDestinations[3],
         true},
    };
}

std::vector<GSeedRunStageSliceSpec> StarterKeySourceSlices(TwistWorkSpaceSlot pSource,
                                                           TwistWorkSpaceSlot pKeyA,
                                                           TwistWorkSpaceSlot pKeyB,
                                                           TwistWorkSpaceSlot pWarmUpLaneA,
                                                           TwistWorkSpaceSlot pWarmUpLaneB,
                                                           TwistWorkSpaceSlot pDestLaneA,
                                                           TwistWorkSpaceSlot pDestLaneB,
                                                           TwistWorkSpaceSlot pDestLaneC,
                                                           TwistWorkSpaceSlot pDestLaneD) {
    return {
        GSeedRunStageSliceSpec({pSource, pKeyA},
                               true,
                               {pSource, pKeyB},
                               true,
                               pWarmUpLaneA,
                               false),

        GSeedRunStageSliceSpec({pWarmUpLaneA, pKeyB},
                               true,
                               {pSource, pKeyA},
                               true,
                               pWarmUpLaneB,
                               true),

        GSeedRunStageSliceSpec({pWarmUpLaneB, pSource, pKeyB},
                               true,
                               {pKeyA, pWarmUpLaneA},
                               false,
                               pDestLaneA,
                               false),

        {{pDestLaneA, pWarmUpLaneA},
         {pWarmUpLaneB, pKeyB},
         pDestLaneB,
         true},

        {{pDestLaneB, pWarmUpLaneB},
         {pDestLaneA, pKeyA},
         pDestLaneC,
         false},

        {{pDestLaneC, pDestLaneA},
         {pDestLaneB, pWarmUpLaneB},
         pDestLaneD,
         true},
    };
}

GSeedRunStageConfig MakeTwist_AConfig() {
    using Slot = TwistWorkSpaceSlot;
    
    GSeedRunStageConfig aConfig = BaseConfig("GTwistRunTwist_A",
                                             "twist_loop_a",
                                             TwistDomain::kPhaseD,
                                             GAXSFormat::kN9);
    aConfig.mMaxContextSourceCount = 4;
    aConfig.mMaxBoundSourceCount = 8;
    aConfig.mWarmupDestinationCount = 2;
    aConfig.mBindDuplicateSourceSlots = false;
    aConfig.mSliceDomains = {
        TwistDomain::kPhaseA, TwistDomain::kPhaseB,
        TwistDomain::kPhaseC, TwistDomain::kPhaseD,
        TwistDomain::kPhaseE, TwistDomain::kPhaseF,
    };
    aConfig.mSlices = StarterKeySourceSlices(Slot::kSource,
                                             Slot::kKeyRowReadA,
                                             Slot::kKeyRowReadB,
                                             Slot::kWaterLaneA,
                                             Slot::kWaterLaneB,
                                             Slot::kExpansionLaneA,
                                             Slot::kExpansionLaneB,
                                             Slot::kExpansionLaneC,
                                             Slot::kExpansionLaneD);
    aConfig.mExpectedSkeletonCount = 6;
    
    std::vector<Slot> aInputs;
    aInputs = {Slot::kSource, Slot::kKeyRowReadA, Slot::kKeyRowReadB};

    std::vector<Slot> aOutputs;
    aOutputs = { Slot::kWaterLaneA, Slot::kWaterLaneB,
                 Slot::kExpansionLaneA, Slot::kExpansionLaneB,
                 Slot::kExpansionLaneC, Slot::kExpansionLaneD };
    
    std::string aErrorMessage;
    if (!GSeedRunStageConfigValidator::ValidateStarter(aConfig,
                                                       aInputs, // primary inputs
                                                       aOutputs,
                                                       false,
                                                       &aErrorMessage)) {
        printf("MakeTwist_AConfig was not valid with ValidateStarter");
        printf("%s\n", aErrorMessage.c_str());
        exit(0);
    }
    
    return aConfig;
}

GSeedRunStageConfig MakeTwist_BConfig() {
    using Slot = TwistWorkSpaceSlot;
    
    GSeedRunStageConfig aConfig = BaseConfig("GTwistRunTwist_B",
                                             "twist_loop_b",
                                             TwistDomain::kPhaseE,
                                             GAXSFormat::kN7);
    aConfig.mSlices = FourPassSlices({Slot::kExpansionLaneA, Slot::kExpansionLaneB,
                                       Slot::kExpansionLaneC, Slot::kExpansionLaneD},
                                      {Slot::kFireLaneA, Slot::kFireLaneB,
                                       Slot::kFireLaneC, Slot::kFireLaneD,
                                       Slot::kWorkLaneA, Slot::kWorkLaneB,
                                       Slot::kWorkLaneC, Slot::kWorkLaneD},
                                      {Slot::kOperationLaneA, Slot::kOperationLaneB,
                                       Slot::kOperationLaneC, Slot::kOperationLaneD});
    aConfig.mExpectedSkeletonCount = 4;
    
    std::vector<Slot> aInputs;
    aInputs = { Slot::kExpansionLaneA, Slot::kExpansionLaneB,
                Slot::kExpansionLaneC, Slot::kExpansionLaneD };

    std::vector<Slot> aResiduals;
    aResiduals = { Slot::kFireLaneA, Slot::kFireLaneB,
                   Slot::kFireLaneC, Slot::kFireLaneD,
                   Slot::kWorkLaneA, Slot::kWorkLaneB,
                   Slot::kWorkLaneC, Slot::kWorkLaneD };

    std::vector<Slot> aOutputs;
    aOutputs = { Slot::kOperationLaneA, Slot::kOperationLaneB,
                 Slot::kOperationLaneC, Slot::kOperationLaneD };
    
    std::string aErrorMessage;
    if (!GSeedRunStageConfigValidator::ValidateMidstage(aConfig,
                                                        aInputs,
                                                        aResiduals,
                                                        aOutputs,
                                                        &aErrorMessage)) {
        printf("MakeTwist_BConfig was not valid with ValidateMidstage");
        printf("%s\n", aErrorMessage.c_str());
        exit(0);
    }
    
    return aConfig;
}

GSeedRunStageConfig MakeTwist_CConfig() {
    using Slot = TwistWorkSpaceSlot;
    
    GSeedRunStageConfig aConfig = BaseConfig("GTwistRunTwist_C",
                                             "twist_loop_c",
                                             TwistDomain::kPhaseF,
                                             GAXSFormat::kN11);
    aConfig.mSlices = FourPassSlices({Slot::kOperationLaneA, Slot::kOperationLaneB,
                                       Slot::kOperationLaneC, Slot::kOperationLaneD},
                                      {Slot::kFireLaneA, Slot::kFireLaneB,
                                       Slot::kFireLaneC, Slot::kFireLaneD,
                                       Slot::kExpansionLaneA, Slot::kExpansionLaneB,
                                       Slot::kExpansionLaneC, Slot::kExpansionLaneD},
                                      {Slot::kWorkLaneA, Slot::kWorkLaneB,
                                       Slot::kWorkLaneC, Slot::kWorkLaneD});
    
    aConfig.mExpectedSkeletonCount = 4;
    
    std::vector<Slot> aInputs;
    aInputs = { Slot::kOperationLaneA, Slot::kOperationLaneB,
                Slot::kOperationLaneC, Slot::kOperationLaneD };

    std::vector<Slot> aResiduals;
    aResiduals = {
        Slot::kFireLaneA, Slot::kFireLaneB,
        Slot::kFireLaneC, Slot::kFireLaneD,
        Slot::kExpansionLaneA, Slot::kExpansionLaneB,
        Slot::kExpansionLaneC, Slot::kExpansionLaneD
    };

    std::vector<Slot> aOutputs;
    aOutputs = { Slot::kWorkLaneA, Slot::kWorkLaneB,
                 Slot::kWorkLaneC, Slot::kWorkLaneD };
    
    std::string aErrorMessage;
    if (!GSeedRunStageConfigValidator::ValidateMidstage(aConfig,
                                                        aInputs,
                                                        aResiduals,
                                                        aOutputs,
                                                        &aErrorMessage)) {
        printf("MakeTwist_CConfig was not valid with ValidateMidstage");
        printf("%s\n", aErrorMessage.c_str());
        exit(0);
    }
    
    return aConfig;
}

GSeedRunStageConfig MakeTwist_DConfig() {
    using Slot = TwistWorkSpaceSlot;
    
    GSeedRunStageConfig aConfig = BaseConfig("GTwistRunTwist_D",
                                             "twist_loop_d",
                                             TwistDomain::kPhaseG,
                                             GAXSFormat::kN7);
    aConfig.mSlices = SixPassTerminalDiverseSlices({Slot::kOperationLaneA, Slot::kOperationLaneB, Slot::kOperationLaneC, Slot::kOperationLaneD},
                                                   {Slot::kWorkLaneA, Slot::kWorkLaneB, Slot::kWorkLaneC, Slot::kWorkLaneD,
                                                    Slot::kEarthLaneA, Slot::kEarthLaneB,
                                                    Slot::kKeyRowReadA, Slot::kKeyRowReadB},
                                                   {Slot::kSnowLaneA, Slot::kSnowLaneB,
                                                    Slot::kFuseLaneA, Slot::kFuseLaneB, Slot::kFuseLaneC, Slot::kFuseLaneD});
    aConfig.mExpectedSkeletonCount = 6;
    
    std::vector<Slot> aInputs;
    aInputs = { Slot::kOperationLaneA, Slot::kOperationLaneB,
                Slot::kOperationLaneC, Slot::kOperationLaneD };

    std::vector<Slot> aResiduals;
    aResiduals = { Slot::kWorkLaneA, Slot::kWorkLaneB,
                   Slot::kWorkLaneC, Slot::kWorkLaneD,
                   Slot::kEarthLaneA, Slot::kEarthLaneB,
                   Slot::kKeyRowReadA, Slot::kKeyRowReadB };

    std::vector<Slot> aOutputs;
    aOutputs = { Slot::kSnowLaneA, Slot::kSnowLaneB, Slot::kFuseLaneA, Slot::kFuseLaneB, Slot::kFuseLaneC, Slot::kFuseLaneD };
    
    std::string aErrorMessage;
    if (!GSeedRunStageConfigValidator::ValidateTerminalMidstage(aConfig,
                                                                aInputs,
                                                                aResiduals,
                                                                aOutputs,
                                                                &aErrorMessage)) {
        printf("MakeTwist_DConfig was not valid with ValidateTerminalMidstage");
        printf("%s\n", aErrorMessage.c_str());
        exit(0);
    }
    
    return aConfig;
}

GSeedRunStageConfig MakeTwist_EConfig() {
    using Slot = TwistWorkSpaceSlot;
    
    GSeedRunStageConfig aConfig = BaseConfig("GTwistRunTwist_E",
                                             "twist_loop_e",
                                             TwistDomain::kPhaseH,
                                             GAXSFormat::kN7);
    aConfig.mSlices = SixPassDiverseSlices({Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD},
                                           {Slot::kSnowLaneA, Slot::kSnowLaneB,
                                            Slot::kEarthLaneC, Slot::kEarthLaneD,
                                            Slot::kExpansionLaneC, Slot::kExpansionLaneD,
                                            Slot::kWaterLaneA, Slot::kWaterLaneB},
                                           {Slot::kSnowLaneC, Slot::kSnowLaneD,
                                            Slot::kWorkLaneA, Slot::kWorkLaneB, Slot::kWorkLaneC, Slot::kWorkLaneD});
    aConfig.mExpectedSkeletonCount = 6;
    
    std::vector<Slot> aInputs;
    aInputs = { Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD };

    std::vector<Slot> aResiduals;
    aResiduals = { Slot::kSnowLaneA, Slot::kSnowLaneB,
                   Slot::kEarthLaneC, Slot::kEarthLaneD,
                   Slot::kExpansionLaneC, Slot::kExpansionLaneD,
                   Slot::kWaterLaneA, Slot::kWaterLaneB };

    std::vector<Slot> aOutputs;
    aOutputs = { Slot::kSnowLaneC, Slot::kSnowLaneD, Slot::kWorkLaneA, Slot::kWorkLaneB, Slot::kWorkLaneC, Slot::kWorkLaneD };
    
    std::string aErrorMessage;
    if (!GSeedRunStageConfigValidator::ValidateMidstage(aConfig,
                                                        aInputs,
                                                        aResiduals,
                                                        aOutputs,
                                                        &aErrorMessage)) {
        printf("MakeTwist_EConfig was not valid with ValidateMidstage");
        printf("%s\n", aErrorMessage.c_str());
        exit(0);
    }
    
    return aConfig;
}

void AddTwistPrologue(TwistProgramBranch &pBranch) {
    GBatch aInitBatch;
    aInitBatch.mName = "init varz";
    
    std::vector<GStatement> aInitStatements;
    for (TwistVariable aVariable : kInitialRandomVariables) {
        aInitStatements.push_back(
                                  GQuick::MakeAssignVariableStatement(GSymbol::Var(aVariable),
                                                                      GExpr::Const(Random::Get64High())));
    }
    aInitBatch.CommitStatements(&aInitStatements);
    pBranch.AddBatch(aInitBatch);
}

} // namespace


GTwistRunTwist_A::GTwistRunTwist_A()
: mStage(MakeTwist_AConfig()) {
}

GTwistRunTwist_A::~GTwistRunTwist_A() {
}

void GTwistRunTwist_A::Reset() {
    mStage.Reset();
}

bool GTwistRunTwist_A::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GTwistRunTwist_A::Build(TwistProgramBranch &pBranch,
                             std::string *pErrorMessage) {
    AddTwistPrologue(pBranch);
    return mStage.Build(pBranch, pErrorMessage);
}

GTwistRunTwist_B::GTwistRunTwist_B()
: mStage(MakeTwist_BConfig()) {
}

GTwistRunTwist_B::~GTwistRunTwist_B() {
}

void GTwistRunTwist_B::Reset() {
    mStage.Reset();
}

bool GTwistRunTwist_B::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GTwistRunTwist_B::Build(TwistProgramBranch &pBranch,
                             std::string *pErrorMessage) {
    return mStage.Build(pBranch, pErrorMessage);
}

GTwistRunTwist_C::GTwistRunTwist_C()
: mStage(MakeTwist_CConfig()) {
}

GTwistRunTwist_C::~GTwistRunTwist_C() {
}

void GTwistRunTwist_C::Reset() {
    mStage.Reset();
}

bool GTwistRunTwist_C::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GTwistRunTwist_C::Build(TwistProgramBranch &pBranch,
                             std::string *pErrorMessage) {
    return mStage.Build(pBranch, pErrorMessage);
}

GTwistRunTwist_D::GTwistRunTwist_D()
: mStage(MakeTwist_DConfig()) {
}

GTwistRunTwist_D::~GTwistRunTwist_D() {
}

void GTwistRunTwist_D::Reset() {
    mStage.Reset();
}

bool GTwistRunTwist_D::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GTwistRunTwist_D::Build(TwistProgramBranch &pBranch,
                             std::string *pErrorMessage) {
    return mStage.Build(pBranch, pErrorMessage);
}

GTwistRunTwist_E::GTwistRunTwist_E()
: mStage(MakeTwist_EConfig()) {
}

GTwistRunTwist_E::~GTwistRunTwist_E() {
}

void GTwistRunTwist_E::Reset() {
    mStage.Reset();
}

bool GTwistRunTwist_E::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GTwistRunTwist_E::Build(TwistProgramBranch &pBranch,
                             std::string *pErrorMessage) {
    return mStage.Build(pBranch, pErrorMessage);
}
