//
//  GSeedRunKDF_A.cpp
//  MeanMachine
//

#include "GSeedRunKDF_A.hpp"
#include "GQuick.hpp"
#include "GSeedRunStageConfigValidator.hpp"
#include "Random.hpp"

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

std::vector<TwistWorkSpaceSlot> ParamOrbiterAssignSalts() {
    using Slot = TwistWorkSpaceSlot;
    return {
        Slot::kParamDomainSaltOrbiterAssignA,
        Slot::kParamDomainSaltOrbiterAssignB,
        Slot::kParamDomainSaltOrbiterAssignC,
        Slot::kParamDomainSaltOrbiterAssignD,
        Slot::kParamDomainSaltOrbiterAssignE,
        Slot::kParamDomainSaltOrbiterAssignF,
    };
}

std::vector<TwistWorkSpaceSlot> ParamOrbiterUpdateSalts() {
    using Slot = TwistWorkSpaceSlot;
    return {
        Slot::kParamDomainSaltOrbiterUpdateA,
        Slot::kParamDomainSaltOrbiterUpdateB,
        Slot::kParamDomainSaltOrbiterUpdateC,
        Slot::kParamDomainSaltOrbiterUpdateD,
        Slot::kParamDomainSaltOrbiterUpdateE,
        Slot::kParamDomainSaltOrbiterUpdateF,
    };
}

std::vector<TwistWorkSpaceSlot> ParamWandererUpdateSalts() {
    using Slot = TwistWorkSpaceSlot;
    return {
        Slot::kParamDomainSaltWandererUpdateA,
        Slot::kParamDomainSaltWandererUpdateB,
        Slot::kParamDomainSaltWandererUpdateC,
        Slot::kParamDomainSaltWandererUpdateD,
        Slot::kParamDomainSaltWandererUpdateE,
        Slot::kParamDomainSaltWandererUpdateF,
    };
}

GSeedRunStageConfig BaseConfig(const std::string &pStageName,
                               const std::string &pBatchName,
                               GAXSFormat pFormat) {
    GSeedRunStageConfig aConfig;
    aConfig.mStageName = pStageName;
    aConfig.mBatchName = pBatchName;
    aConfig.mStartLine = "// " + pStageName + " " + pBatchName + " (start)";
    aConfig.mEndLine = "// " + pStageName + " " + pBatchName + " (end)";
    aConfig.mFormat = pFormat;
    aConfig.mIgnoreNonces = false;
    aConfig.mHasDomainMix = true;
    aConfig.mDomain = TwistDomain::kInvalid;
    aConfig.mIsNonKDF = false;
    aConfig.mExpectedSkeletonCount = 6;
    aConfig.mLoopCeiling = S_BLOCK;
    aConfig.mLoopEndText = "S_BLOCK";
    aConfig.mHotPackCount = 12;
    aConfig.mSaltsOrbiterAssign = ParamOrbiterAssignSalts();
    aConfig.mSaltsOrbiterUpdate = ParamOrbiterUpdateSalts();
    aConfig.mSaltsWandererUpdate = ParamWandererUpdateSalts();
    return aConfig;
}

std::vector<GSeedRunStageSliceSpec> FourPassNoResidualSlices(const std::vector<TwistWorkSpaceSlot> &pPrimary,
                                                             const std::vector<TwistWorkSpaceSlot> &pDestinations) {
    return {
        {{pPrimary[0], pPrimary[1]},
         {pPrimary[2], pPrimary[3]},
         pDestinations[0],
         false},

        {{pDestinations[0], pPrimary[1], pPrimary[2]},
         {pPrimary[0], pPrimary[3]},
         pDestinations[1],
         true},

        {{pDestinations[1], pPrimary[3], pPrimary[0]},
         {pDestinations[0], pPrimary[1], pPrimary[2]},
         pDestinations[2],
         false},

        {{pDestinations[2], pPrimary[2], pDestinations[0]},
         {pDestinations[1], pPrimary[3], pPrimary[0]},
         pDestinations[3],
         true},
    };
}


std::vector<GSeedRunStageSliceSpec> FourPassFourResidualSlices(const std::vector<TwistWorkSpaceSlot> &pPrimary,
                                                               const std::vector<TwistWorkSpaceSlot> &pResiduals,
                                                               const std::vector<TwistWorkSpaceSlot> &pDestinations) {
    std::vector<TwistWorkSpaceSlot> aResiduals = pResiduals;
    Random::Shuffle(&aResiduals);

    return {
        {{pPrimary[0], pPrimary[1], aResiduals[0]},
         {pPrimary[2], pPrimary[3]},
         pDestinations[0],
         false},

        {{pDestinations[0], pPrimary[2], aResiduals[1]},
         {pPrimary[0], pPrimary[3], pPrimary[1]},
         pDestinations[1],
         true},

        {{pDestinations[1], pPrimary[3], aResiduals[2]},
         {pDestinations[0], pPrimary[1], pPrimary[2]},
         pDestinations[2],
         false},

        {{pDestinations[2], pDestinations[0], aResiduals[3]},
         {pDestinations[1], pPrimary[2], pPrimary[3], pPrimary[0]},
         pDestinations[3],
         true},
    };
}

std::vector<GSeedRunStageSliceSpec> FourPassEightResidualSlices(const std::vector<TwistWorkSpaceSlot> &pPrimary,
                                                                const std::vector<TwistWorkSpaceSlot> &pResiduals,
                                                                const std::vector<TwistWorkSpaceSlot> &pDestinations) {
    std::vector<TwistWorkSpaceSlot> aResiduals = pResiduals;
    Random::Shuffle(&aResiduals);

    return {
        {{pPrimary[0], pPrimary[1], aResiduals[0]},
         {pPrimary[2], pPrimary[3], aResiduals[1]},
         pDestinations[0],
         false},

        {{pDestinations[0], pPrimary[2], aResiduals[2]},
         {pPrimary[0], pPrimary[3], aResiduals[3]},
         pDestinations[1],
         true},

        {{pDestinations[1], pPrimary[3], aResiduals[4]},
         {pDestinations[0], pPrimary[1], aResiduals[5]},
         pDestinations[2],
         false},

        {{pDestinations[2], pDestinations[0], aResiduals[6]},
         {pDestinations[1], pPrimary[2], aResiduals[7]},
         pDestinations[3],
         true},
    };
}

std::vector<GSeedRunStageSliceSpec> FourPassTerminalEightResidualSlices(const std::vector<TwistWorkSpaceSlot> &pPrimary,
                                                                        const std::vector<TwistWorkSpaceSlot> &pResiduals,
                                                                        const std::vector<TwistWorkSpaceSlot> &pDestinations) {
    std::vector<TwistWorkSpaceSlot> aResiduals = pResiduals;
    Random::Shuffle(&aResiduals);

    return {
        {{pPrimary[0], pPrimary[1], aResiduals[0]},
         {pPrimary[2], pPrimary[3], aResiduals[1]},
         pDestinations[0],
         false},

        {{pPrimary[1], pPrimary[2], aResiduals[2]},
         {pPrimary[3], pPrimary[0], aResiduals[3]},
         pDestinations[1],
         true},

        {{pPrimary[2], pPrimary[3], aResiduals[4]},
         {pPrimary[0], pPrimary[1], aResiduals[5]},
         pDestinations[2],
         false},

        {{pPrimary[3], pPrimary[0], aResiduals[6]},
         {pPrimary[1], pPrimary[2], aResiduals[7]},
         pDestinations[3],
         true},
    };
}

void AddKDF_APrologue(TwistProgramBranch &pBranch) {
    pBranch.AddLine("// [kdf-a]");
    pBranch.AddLine("std::uint64_t aDomainWordIngress = pConstants->mIngress;");
    pBranch.AddLine("std::uint64_t aDomainWordScatter = pConstants->mScatter;");
    pBranch.AddLine("std::uint64_t aDomainWordCross = pConstants->mCross;");
    pBranch.AddLine("std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;");
    pBranch.AddLine("std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;");
    pBranch.AddLine("std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;");

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

GSeedRunStageConfig MakeKDF_A_AConfig() {
    using Slot = TwistWorkSpaceSlot;
    GSeedRunStageConfig aConfig = BaseConfig("GSeedRunKDF_A_A",
                                             "kdf_a_loop_a",
                                             GAXSFormat::kN11);
    aConfig.mWarmupDestinationCount = 2;
    aConfig.mSlices = {
        // 2-source graph: ingress [source, snow], cross [snow, source].
        GSeedRunStageSliceSpec({Slot::kSource, Slot::kParamSnow},
                               true,
                               {Slot::kParamSnow, Slot::kSource},
                               true,
                               Slot::kWaterLaneA,
                               false),

        // 3-source graph: previous write is the shared source.
        GSeedRunStageSliceSpec({Slot::kWaterLaneA, Slot::kSource},
                               true,
                               {Slot::kWaterLaneA, Slot::kParamSnow},
                               true,
                               Slot::kWaterLaneB,
                               true),

        // 4-source graph and onward: no duplicate lane reads in a slice.
        {{Slot::kWaterLaneB, Slot::kSource},
         {Slot::kParamSnow, Slot::kWaterLaneA},
         Slot::kEarthLaneA,
         false},

        {{Slot::kEarthLaneA, Slot::kWaterLaneB},
         {Slot::kWaterLaneA, Slot::kSource},
         Slot::kEarthLaneB,
         true},

        {{Slot::kEarthLaneB, Slot::kWaterLaneB},
         {Slot::kEarthLaneA, Slot::kParamSnow},
         Slot::kEarthLaneC,
         false},

        {{Slot::kEarthLaneC, Slot::kEarthLaneA},
         {Slot::kEarthLaneB, Slot::kWaterLaneA},
         Slot::kEarthLaneD,
         true},
    };
    aConfig.mExpectedSkeletonCount = 6;
    
    
    std::vector<Slot> aInputs;
    aInputs = {Slot::kSource, Slot::kParamSnow};

    std::vector<Slot> aOutputs;
    aOutputs = {
        Slot::kWaterLaneA, Slot::kWaterLaneB,
        Slot::kEarthLaneA, Slot::kEarthLaneB, Slot::kEarthLaneC, Slot::kEarthLaneD,
    };
    
    std::string aErrorMessage;
    if (!GSeedRunStageConfigValidator::ValidateStarter(aConfig,
                                                       aInputs, // primary inputs
                                                       aOutputs,
                                                       false,
                                                       &aErrorMessage)) {
        printf("MakeKDF_A_AConfig was not valid with ValidateStarter");
        printf("%s\n", aErrorMessage.c_str());
        exit(0);
    }
    
    
    return aConfig;
}

GSeedRunStageConfig MakeKDF_A_BConfig() {
    using Slot = TwistWorkSpaceSlot;
    GSeedRunStageConfig aConfig = BaseConfig("GSeedRunKDF_A_B",
                                             "kdf_a_loop_b",
                                             GAXSFormat::kN9);

    
    aConfig.mSlices = FourPassNoResidualSlices({Slot::kEarthLaneA, Slot::kEarthLaneB, Slot::kEarthLaneC, Slot::kEarthLaneD},
                                               {Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD});
    aConfig.mExpectedSkeletonCount = 4;
    
    {
        std::vector<Slot> aInputs;
        aInputs = { Slot::kEarthLaneA, Slot::kEarthLaneB, Slot::kEarthLaneC, Slot::kEarthLaneD };

        std::vector<Slot> aResiduals;

        std::vector<Slot> aOutputs;
        aOutputs = { Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD };
        
        std::string aErrorMessage;
        if (!GSeedRunStageConfigValidator::ValidateMidstage(aConfig,
                                                            aInputs,
                                                            aResiduals,
                                                            aOutputs,
                                                            &aErrorMessage)) {
            printf("MakeKDF_A_BConfig was not valid with ValidateMidstage");
            printf("%s\n", aErrorMessage.c_str());
            exit(0);
        }
    }
    
    return aConfig;
}

GSeedRunStageConfig MakeKDF_A_CConfig() {
    using Slot = TwistWorkSpaceSlot;
    GSeedRunStageConfig aConfig = BaseConfig("GSeedRunKDF_A_C",
                                             "kdf_a_loop_c",
                                             GAXSFormat::kN5);
    
    aConfig.mSlices = FourPassFourResidualSlices({Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD},
                                                 {Slot::kEarthLaneA, Slot::kEarthLaneB, Slot::kEarthLaneC, Slot::kEarthLaneD},
                                                 {Slot::kOperationLaneA, Slot::kOperationLaneB, Slot::kOperationLaneC, Slot::kOperationLaneD});
    aConfig.mExpectedSkeletonCount = 4;
    
    
    std::vector<Slot> aInputs;
    aInputs = { Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD };
    
    std::vector<Slot> aResiduals;
    aResiduals = { Slot::kEarthLaneA, Slot::kEarthLaneB, Slot::kEarthLaneC, Slot::kEarthLaneD };
    
    std::vector<Slot> aOutputs;
    aOutputs = { Slot::kOperationLaneA, Slot::kOperationLaneB, Slot::kOperationLaneC, Slot::kOperationLaneD };
    
    std::string aErrorMessage;
    if (!GSeedRunStageConfigValidator::ValidateMidstage(aConfig,
                                                        aInputs,
                                                        aResiduals,
                                                        aOutputs,
                                                        &aErrorMessage)) {
        printf("MakeKDF_A_CConfig was not valid with ValidateMidstage");
        printf("%s\n", aErrorMessage.c_str());
        exit(0);
    }
    
    return aConfig;
}

GSeedRunStageConfig MakeKDF_A_DConfig() {
    using Slot = TwistWorkSpaceSlot;
    GSeedRunStageConfig aConfig = BaseConfig("GSeedRunKDF_A_D",
                                             "kdf_a_loop_d",
                                             GAXSFormat::kN7);
    
    aConfig.mSlices = FourPassTerminalEightResidualSlices({Slot::kOperationLaneA, Slot::kOperationLaneB, Slot::kOperationLaneC, Slot::kOperationLaneD},
                                                          {Slot::kEarthLaneB, Slot::kEarthLaneC, Slot::kEarthLaneD, Slot::kSource,
                                                           Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD},
                                                          {Slot::kFuseLaneA, Slot::kFuseLaneB, Slot::kFuseLaneC, Slot::kFuseLaneD});
    aConfig.mExpectedSkeletonCount = 4;
    
    
    std::vector<Slot> aInputs;
    aInputs = {     Slot::kOperationLaneA, Slot::kOperationLaneB, Slot::kOperationLaneC, Slot::kOperationLaneD};

    std::vector<Slot> aResiduals;
    aResiduals = {  Slot::kEarthLaneB, Slot::kEarthLaneC, Slot::kEarthLaneD, Slot::kSource,
                    Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD
    };
    
    std::vector<Slot> aOutputs;
    aOutputs = {    Slot::kFuseLaneA, Slot::kFuseLaneB, Slot::kFuseLaneC, Slot::kFuseLaneD };
    
    
    
    std::string aErrorMessage;
    if (!GSeedRunStageConfigValidator::ValidateTerminalMidstage(aConfig,
                                                                aInputs,
                                                                aResiduals,
                                                                aOutputs,
                                                                &aErrorMessage)) {
        printf("MakeKDF_A_DConfig was not valid with ValidateTerminalMidstage");
        printf("%s\n", aErrorMessage.c_str());
        exit(0);
    }
    
    
    return aConfig;
}

// Here we diffuse [fuse] to [wind]

GSeedRunStageConfig MakeKDF_A_EConfig() {
    using Slot = TwistWorkSpaceSlot;
    GSeedRunStageConfig aConfig = BaseConfig("GSeedRunKDF_A_E",
                                             "kdf_a_loop_e",
                                             GAXSFormat::kN9);
    
    aConfig.mSlices = FourPassEightResidualSlices({Slot::kWindLaneA, Slot::kWindLaneB, Slot::kWindLaneC, Slot::kWindLaneD},
                                                  {Slot::kEarthLaneA, Slot::kEarthLaneB, Slot::kEarthLaneC, Slot::kEarthLaneD,
                                                   Slot::kSource, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD},
                                                  {Slot::kWaterLaneA, Slot::kWaterLaneB, Slot::kWaterLaneC, Slot::kWaterLaneD});
    aConfig.mExpectedSkeletonCount = 4;
    
    std::vector<Slot> aInputs;
    aInputs = {     Slot::kWindLaneA, Slot::kWindLaneB, Slot::kWindLaneC, Slot::kWindLaneD };
    
    std::vector<Slot> aResiduals;
    aResiduals = {
        Slot::kEarthLaneA, Slot::kEarthLaneB, Slot::kEarthLaneC, Slot::kEarthLaneD,
        Slot::kSource, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD,
    };
    
    std::vector<Slot> aOutputs;
    aOutputs = {    Slot::kWaterLaneA, Slot::kWaterLaneB, Slot::kWaterLaneC, Slot::kWaterLaneD };
    
    std::string aErrorMessage;
    if (!GSeedRunStageConfigValidator::ValidateMidstage(aConfig,
                                                        aInputs,
                                                        aResiduals,
                                                        aOutputs,
                                                        &aErrorMessage)) {
        printf("MakeKDF_A_EConfig was not valid with ValidateMidstage");
        printf("%s\n", aErrorMessage.c_str());
        exit(0);
    }
    
    return aConfig;
}

} // namespace

GSeedRunKDF_A_A::GSeedRunKDF_A_A()
: mStage(MakeKDF_A_AConfig()) {
}

GSeedRunKDF_A_A::~GSeedRunKDF_A_A() {
}

void GSeedRunKDF_A_A::Reset() {
    mStage.Reset();
}

bool GSeedRunKDF_A_A::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GSeedRunKDF_A_A::Build(TwistProgramBranch &pBranch,
                            std::string *pErrorMessage) {
    AddKDF_APrologue(pBranch);
    return mStage.Build(pBranch, pErrorMessage);
}

GSeedRunKDF_A_B::GSeedRunKDF_A_B()
: mStage(MakeKDF_A_BConfig()) {
}

GSeedRunKDF_A_B::~GSeedRunKDF_A_B() {
}

void GSeedRunKDF_A_B::Reset() {
    mStage.Reset();
}

bool GSeedRunKDF_A_B::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GSeedRunKDF_A_B::Build(TwistProgramBranch &pBranch,
                            std::string *pErrorMessage) {
    return mStage.Build(pBranch, pErrorMessage);
}

GSeedRunKDF_A_C::GSeedRunKDF_A_C()
: mStage(MakeKDF_A_CConfig()) {
}

GSeedRunKDF_A_C::~GSeedRunKDF_A_C() {
}

void GSeedRunKDF_A_C::Reset() {
    mStage.Reset();
}

bool GSeedRunKDF_A_C::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GSeedRunKDF_A_C::Build(TwistProgramBranch &pBranch,
                            std::string *pErrorMessage) {
    return mStage.Build(pBranch, pErrorMessage);
}

GSeedRunKDF_A_D::GSeedRunKDF_A_D()
: mStage(MakeKDF_A_DConfig()) {
}

GSeedRunKDF_A_D::~GSeedRunKDF_A_D() {
}

void GSeedRunKDF_A_D::Reset() {
    mStage.Reset();
}

bool GSeedRunKDF_A_D::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GSeedRunKDF_A_D::Build(TwistProgramBranch &pBranch,
                            std::string *pErrorMessage) {
    return mStage.Build(pBranch, pErrorMessage);
}

GSeedRunKDF_A_E::GSeedRunKDF_A_E()
: mStage(MakeKDF_A_EConfig()) {
}

GSeedRunKDF_A_E::~GSeedRunKDF_A_E() {
}

void GSeedRunKDF_A_E::Reset() {
    mStage.Reset();
}

bool GSeedRunKDF_A_E::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GSeedRunKDF_A_E::Build(TwistProgramBranch &pBranch,
                            std::string *pErrorMessage) {
    return mStage.Build(pBranch, pErrorMessage);
}
