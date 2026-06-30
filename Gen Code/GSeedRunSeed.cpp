/

GSeedRunStageConfig MakeSeed_AConfig(const bool pUseNonces) {

    aInputs = {Slot::kSource, Slot::kKeyRowReadA, Slot::kKeyRowReadB};

    aOutputs = { Slot::kWaterLaneA, Slot::kWaterLaneB,
                 Slot::kExpansionLaneA, Slot::kExpansionLaneB,
                 Slot::kExpansionLaneC, Slot::kExpansionLaneD };
}

GSeedRunStageConfig MakeSeed_BConfig(const bool pUseNonces) {

    aInputs = { Slot::kExpansionLaneA, Slot::kExpansionLaneB,
                Slot::kExpansionLaneC, Slot::kExpansionLaneD };

    std::vector<Slot> aResiduals;
    aResiduals = { Slot::kFireLaneA, Slot::kFireLaneB,
                   Slot::kFireLaneC, Slot::kFireLaneD,
                   Slot::kWorkLaneA, Slot::kWorkLaneB,
                   Slot::kWorkLaneC, Slot::kWorkLaneD };

    std::vector<Slot> aOutputs;
    aOutputs = { Slot::kInvestA, Slot::kInvestB,
                 Slot::kOperationLaneA, Slot::kOperationLaneB,
                 Slot::kOperationLaneC, Slot::kOperationLaneD };
    
    std::string aErrorMessage;
    if (!GSeedRunStageConfigValidator::ValidateMidstage(aConfig,
                                                        aInputs,
                                                        aResiduals,
                                                        aOutputs,
                                                        &aErrorMessage)) {
        printf("GSeedRunSeed_B was not valid with ValidateMidstage");
        printf("%s\n", aErrorMessage.c_str());
        exit(0);
    }
    
    
    return aConfig;
}

GSeedRunStageConfig MakeSeed_CConfig(const bool pUseNonces) {
    using Slot = TwistWorkSpaceSlot;
    
    GSeedRunStageConfig aConfig = BaseConfig("GSeedRunSeed_C",
                                             TwistDomain::kPhaseB,
                                             pUseNonces,
                                             GAXSFormat::kN9);
    
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
    aResiduals = { Slot::kFireLaneA, Slot::kFireLaneB,
                   Slot::kFireLaneC, Slot::kFireLaneD,
                   Slot::kExpansionLaneA, Slot::kExpansionLaneB,
                   Slot::kExpansionLaneC, Slot::kExpansionLaneD };

    std::vector<Slot> aOutputs;
    aOutputs = { Slot::kWorkLaneA, Slot::kWorkLaneB,
                 Slot::kWorkLaneC, Slot::kWorkLaneD };
    
    std::string aErrorMessage;
    if (!GSeedRunStageConfigValidator::ValidateMidstage(aConfig,
                                                        aInputs,
                                                        aResiduals,
                                                        aOutputs,
                                                        &aErrorMessage)) {
        printf("GSeedRunSeed_C was not valid with ValidateMidstage");
        printf("%s\n", aErrorMessage.c_str());
        exit(0);
    }
    
    return aConfig;
}

GSeedRunStageConfig MakeSeed_DConfig(const bool pUseNonces) {
    using Slot = TwistWorkSpaceSlot;
    
    GSeedRunStageConfig aConfig = BaseConfig("GSeedRunSeed_D",
                                             TwistDomain::kPhaseB,
                                             pUseNonces,
                                             GAXSFormat::kN7);
    aConfig.mSlices = SixPassSlices({Slot::kExpansionLaneA, Slot::kExpansionLaneB,
                                     Slot::kExpansionLaneC, Slot::kExpansionLaneD},
                                    {Slot::kFireLaneA, Slot::kFireLaneB,
                                     Slot::kFireLaneC, Slot::kFireLaneD,
                                     Slot::kOperationLaneA, Slot::kOperationLaneB,
                                     Slot::kOperationLaneC, Slot::kOperationLaneD},
                                    {Slot::kWorkLaneA, Slot::kWorkLaneB,
                                     Slot::kInvestA, Slot::kInvestB,
                                     Slot::kInvestC, Slot::kInvestD});
    aConfig.mExpectedSkeletonCount = 6;
    
    
    std::vector<Slot> aInputs;
    aInputs = { Slot::kExpansionLaneA, Slot::kExpansionLaneB,
                Slot::kExpansionLaneC, Slot::kExpansionLaneD };

    std::vector<Slot> aResiduals;
    aResiduals = { Slot::kFireLaneA, Slot::kFireLaneB,
                   Slot::kFireLaneC, Slot::kFireLaneD,
                   Slot::kOperationLaneA, Slot::kOperationLaneB,
                   Slot::kOperationLaneC, Slot::kOperationLaneD };

    std::vector<Slot> aOutputs;
    aOutputs = { Slot::kWorkLaneA, Slot::kWorkLaneB,
                 Slot::kInvestA, Slot::kInvestB,
                 Slot::kInvestC, Slot::kInvestD };
    
    std::string aErrorMessage;
    if (!GSeedRunStageConfigValidator::ValidateMidstage(aConfig,
                                                        aInputs,
                                                        aResiduals,
                                                        aOutputs,
                                                        &aErrorMessage)) {
        printf("GSeedRunSeed_D was not valid with ValidateMidstage");
        printf("%s\n", aErrorMessage.c_str());
        exit(0);
    }
    
    
    return aConfig;
}

/*
for (int i=0;i<4;i+=2) {
     aDiffusionA.mInputA = kFuseLaneA[i];
     aDiffusionA.mInputB = kFuseLaneB[i + 1];
     aDiffusionA.mOutputA = aFireLanes[i];
     aDiffusionA.mOutputB =  aFireLanes[i + 1];
 }
*/

GSeedRunStageConfig MakeSeed_EConfig(const bool pUseNonces) {
    using Slot = TwistWorkSpaceSlot;

    GSeedRunStageConfig aConfig = BaseConfig("GSeedRunSeed_E",
                                             TwistDomain::kPhaseC,
                                             pUseNonces,
                                             GAXSFormat::kN11);
    aConfig.mSlices = SixPassSlices({Slot::kInvestA, Slot::kInvestB,
                                     Slot::kInvestC, Slot::kInvestD},
                                    {Slot::kFireLaneA, Slot::kFireLaneB,
                                     Slot::kFireLaneC, Slot::kFireLaneD,
                                     Slot::kWorkLaneA, Slot::kWorkLaneB,
                                     Slot::kWorkLaneC, Slot::kWorkLaneD},
                                    {Slot::kSnowLaneA, Slot::kSnowLaneB,
                                     Slot::kOperationLaneA, Slot::kOperationLaneB,
                                     Slot::kOperationLaneC, Slot::kOperationLaneD});
    aConfig.mExpectedSkeletonCount = 6;
    
    
    std::vector<Slot> aInputs;
    aInputs = { Slot::kInvestA, Slot::kInvestB,
                Slot::kInvestC, Slot::kInvestD };

    std::vector<Slot> aResiduals;
    aResiduals = { Slot::kFireLaneA, Slot::kFireLaneB,
                   Slot::kFireLaneC, Slot::kFireLaneD,
                   Slot::kWorkLaneA, Slot::kWorkLaneB,
                   Slot::kWorkLaneC, Slot::kWorkLaneD };
    
    std::vector<Slot> aOutputs;
    aOutputs = { Slot::kSnowLaneA, Slot::kSnowLaneB,
                 Slot::kOperationLaneA, Slot::kOperationLaneB,
                 Slot::kOperationLaneC, Slot::kOperationLaneD };
    
    std::string aErrorMessage;
    if (!GSeedRunStageConfigValidator::ValidateMidstage(aConfig,
                                                        aInputs,
                                                        aResiduals,
                                                        aOutputs,
                                                        &aErrorMessage)) {
        printf("GSeedRunSeed_E was not valid with ValidateMidstage");
        printf("%s\n", aErrorMessage.c_str());
        exit(0);
    }
    
    return aConfig;
}


GSeedRunStageConfig MakeSeed_FConfig(const bool pUseNonces) {
    using Slot = TwistWorkSpaceSlot;

    GSeedRunStageConfig aConfig = BaseConfig("GSeedRunSeed_F",
                                             TwistDomain::kPhaseC,
                                             pUseNonces,
                                             GAXSFormat::kN9);
    aConfig.mSlices = SixPassSlices({Slot::kOperationLaneA, Slot::kOperationLaneB,
                                     Slot::kOperationLaneC, Slot::kOperationLaneD},
                                    {Slot::kFireLaneA, Slot::kFireLaneB,
                                     Slot::kFireLaneC, Slot::kFireLaneD,
                                     Slot::kInvestA, Slot::kInvestB,
                                     Slot::kInvestC, Slot::kInvestD},
                                    {Slot::kSnowLaneA, Slot::kSnowLaneB,
                                     Slot::kExpansionLaneA, Slot::kExpansionLaneB,
                                     Slot::kExpansionLaneC, Slot::kExpansionLaneD});
    aConfig.mExpectedSkeletonCount = 6;
    
    
    std::vector<Slot> aInputs;
    aInputs = { Slot::kOperationLaneA, Slot::kOperationLaneB,
                Slot::kOperationLaneC, Slot::kOperationLaneD };

    std::vector<Slot> aResiduals;
    aResiduals = { Slot::kFireLaneA, Slot::kFireLaneB,
                   Slot::kFireLaneC, Slot::kFireLaneD,
                   Slot::kInvestA, Slot::kInvestB,
                   Slot::kInvestC, Slot::kInvestD };

    std::vector<Slot> aOutputs;
    aOutputs = { Slot::kSnowLaneA, Slot::kSnowLaneB,
                 Slot::kExpansionLaneA, Slot::kExpansionLaneB,
                 Slot::kExpansionLaneC, Slot::kExpansionLaneD };
    
    std::string aErrorMessage;
    if (!GSeedRunStageConfigValidator::ValidateMidstage(aConfig,
                                                        aInputs,
                                                        aResiduals,
                                                        aOutputs,
                                                        &aErrorMessage)) {
        printf("GSeedRunSeed_F was not valid with ValidateMidstage");
        printf("%s\n", aErrorMessage.c_str());
        exit(0);
    }
    
    return aConfig;
}

GSeedRunStageConfig MakeSeed_GConfig(const bool pUseNonces) {
    using Slot = TwistWorkSpaceSlot;

    GSeedRunStageConfig aConfig = BaseConfig("GSeedRunSeed_G",
                                             TwistDomain::kPhaseD,
                                             pUseNonces,
                                             GAXSFormat::kN7);
    aConfig.mSlices = SixPassSlices({Slot::kSnowLaneA, Slot::kSnowLaneB,
                                     Slot::kSnowLaneC, Slot::kSnowLaneD},
                                    {Slot::kFireLaneA, Slot::kFireLaneB,
                                     Slot::kFireLaneC, Slot::kFireLaneD,
                                     Slot::kOperationLaneA, Slot::kOperationLaneB,
                                     Slot::kOperationLaneC, Slot::kOperationLaneD},
                                    {Slot::kWorkLaneA, Slot::kWorkLaneB,
                                     Slot::kExpansionLaneA, Slot::kExpansionLaneB,
                                     Slot::kExpansionLaneC, Slot::kExpansionLaneD});
    aConfig.mExpectedSkeletonCount = 6;
    
    
    
    std::vector<Slot> aInputs;
    aInputs = { Slot::kSnowLaneA, Slot::kSnowLaneB,
                Slot::kSnowLaneC, Slot::kSnowLaneD };
        
    std::vector<Slot> aResiduals;
    aResiduals = { Slot::kFireLaneA, Slot::kFireLaneB,
                   Slot::kFireLaneC, Slot::kFireLaneD,
                   Slot::kOperationLaneA, Slot::kOperationLaneB,
                   Slot::kOperationLaneC, Slot::kOperationLaneD };

    std::vector<Slot> aOutputs;
    aOutputs = { Slot::kWorkLaneA, Slot::kWorkLaneB,
                 Slot::kExpansionLaneA, Slot::kExpansionLaneB,
                 Slot::kExpansionLaneC, Slot::kExpansionLaneD };
    
    std::string aErrorMessage;
    if (!GSeedRunStageConfigValidator::ValidateMidstage(aConfig,
                                                        aInputs,
                                                        aResiduals,
                                                        aOutputs,
                                                        &aErrorMessage)) {
        printf("GSeedRunSeed_G was not valid with ValidateMidstage");
        printf("%s\n", aErrorMessage.c_str());
        exit(0);
    }
    
    return aConfig;
}

GSeedRunStageConfig MakeSeed_HConfig(const bool pUseNonces) {
    using Slot = TwistWorkSpaceSlot;

    GSeedRunStageConfig aConfig = BaseConfig("GSeedRunSeed_H",
                                             TwistDomain::kPhaseE,
                                             pUseNonces,
                                             GAXSFormat::kN7);
    aConfig.mSlices = SixPassTerminalDiverseSlices({Slot::kOperationLaneA, Slot::kOperationLaneB, Slot::kOperationLaneC, Slot::kOperationLaneD},
                                                   {Slot::kExpansionLaneA, Slot::kExpansionLaneB, Slot::kExpansionLaneC, Slot::kExpansionLaneD,
                                                    Slot::kInvestC, Slot::kInvestD,
                                                    Slot::kKeyRowReadA, Slot::kKeyRowReadB},
                                                   {Slot::kWaterLaneA, Slot::kWaterLaneB,
                                                    Slot::kFuseLaneA, Slot::kFuseLaneB, Slot::kFuseLaneC, Slot::kFuseLaneD});
    aConfig.mExpectedSkeletonCount = 6;
    
    std::vector<Slot> aInputs;
    aInputs = { Slot::kOperationLaneA, Slot::kOperationLaneB,
                Slot::kOperationLaneC, Slot::kOperationLaneD };
        
    std::vector<Slot> aResiduals;
    aResiduals = { Slot::kExpansionLaneA, Slot::kExpansionLaneB,
                   Slot::kExpansionLaneC, Slot::kExpansionLaneD,
                   Slot::kInvestC, Slot::kInvestD,
                   Slot::kKeyRowReadA, Slot::kKeyRowReadB };

    std::vector<Slot> aOutputs;
    aOutputs = { Slot::kWaterLaneA, Slot::kWaterLaneB,
                 Slot::kFuseLaneA, Slot::kFuseLaneB,
                 Slot::kFuseLaneC, Slot::kFuseLaneD };
    
    std::string aErrorMessage;
    if (!GSeedRunStageConfigValidator::ValidateTerminalMidstage(aConfig,
                                                                aInputs,
                                                                aResiduals,
                                                                aOutputs,
                                                                &aErrorMessage)) {
        printf("GSeedRunSeed_H was not valid with ValidateTerminalMidstage");
        printf("%s\n", aErrorMessage.c_str());
        exit(0);
    }
    
    return aConfig;
}

// Here we diffuse [fuse] to [snow]

GSeedRunStageConfig MakeSeed_IConfig(const bool pUseNonces) {
    using Slot = TwistWorkSpaceSlot;

    GSeedRunStageConfig aConfig = BaseConfig("GSeedRunSeed_I",
                                             TwistDomain::kPhaseF,
                                             pUseNonces,
                                             GAXSFormat::kN7);
    aConfig.mSlices = SixPassDiverseSlices({    Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD},
                                           {    Slot::kInvestA, Slot::kInvestB, Slot::kInvestC, Slot::kInvestD,
                                                Slot::kEarthLaneA, Slot::kEarthLaneB, Slot::kEarthLaneC, Slot::kEarthLaneD},
                                           {    Slot::kSnowLaneC, Slot::kSnowLaneD,
                                                Slot::kWorkLaneA, Slot::kWorkLaneB, Slot::kWorkLaneC, Slot::kWorkLaneD});
    aConfig.mExpectedSkeletonCount = 6;
    
    std::vector<Slot> aInputs;
    aInputs = { Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD };
        
    std::vector<Slot> aResiduals;
    aResiduals = { Slot::kInvestA, Slot::kInvestB,
                   Slot::kInvestC, Slot::kInvestD,
                   Slot::kEarthLaneA, Slot::kEarthLaneB,
                   Slot::kEarthLaneC, Slot::kEarthLaneD };

    std::vector<Slot> aOutputs;
    aOutputs = { Slot::kSnowLaneC, Slot::kSnowLaneD,
                 Slot::kWorkLaneA, Slot::kWorkLaneB,
                 Slot::kWorkLaneC, Slot::kWorkLaneD };
    
    std::string aErrorMessage;
    if (!GSeedRunStageConfigValidator::ValidateMidstage(aConfig,
                                                        aInputs,
                                                        aResiduals,
                                                        aOutputs,
                                                        &aErrorMessage)) {
        printf("GSeedRunSeed_I was not valid with ValidateMidstage");
        printf("%s\n", aErrorMessage.c_str());
        exit(0);
    }
    
    return aConfig;
}

} // namespace

GSeedRunSeed_A::GSeedRunSeed_A(const bool pUseNonces,
                               const bool pEmitNoncePrologue)
: mStage(MakeSeed_AConfig(pUseNonces)),
  mUseNonces(pUseNonces),
  mEmitNoncePrologue(pEmitNoncePrologue) {
}

GSeedRunSeed_A::~GSeedRunSeed_A() {
}

void GSeedRunSeed_A::Reset() {
    mStage.Reset();
}

bool GSeedRunSeed_A::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GSeedRunSeed_A::Build(TwistProgramBranch &pBranch,
                           std::string *pErrorMessage) {
    if (mUseNonces && mEmitNoncePrologue) {
        AddSeedNoncePrologue(pBranch);
    }
    return mStage.Build(pBranch, pErrorMessage);
}

GSeedRunSeed_B::GSeedRunSeed_B(const bool pUseNonces,
                               const bool pEmitNoncePrologue)
: mStage(MakeSeed_BConfig(pUseNonces)),
  mUseNonces(pUseNonces),
  mEmitNoncePrologue(pEmitNoncePrologue) {
}

GSeedRunSeed_B::~GSeedRunSeed_B() {
}

void GSeedRunSeed_B::Reset() {
    mStage.Reset();
}

bool GSeedRunSeed_B::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GSeedRunSeed_B::Build(TwistProgramBranch &pBranch,
                           std::string *pErrorMessage) {
    if (mUseNonces && mEmitNoncePrologue) {
        AddSeedNoncePrologue(pBranch);
    }
    return mStage.Build(pBranch, pErrorMessage);
}

GSeedRunSeed_C::GSeedRunSeed_C(const bool pUseNonces,
                               const bool pEmitNoncePrologue)
: mStage(MakeSeed_CConfig(pUseNonces)),
  mUseNonces(pUseNonces),
  mEmitNoncePrologue(pEmitNoncePrologue) {
}

GSeedRunSeed_C::~GSeedRunSeed_C() {
}

void GSeedRunSeed_C::Reset() {
    mStage.Reset();
}

bool GSeedRunSeed_C::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GSeedRunSeed_C::Build(TwistProgramBranch &pBranch,
                           std::string *pErrorMessage) {
    if (mUseNonces && mEmitNoncePrologue) {
        AddSeedNoncePrologue(pBranch);
    }
    return mStage.Build(pBranch, pErrorMessage);
}

GSeedRunSeed_D::GSeedRunSeed_D(const bool pUseNonces,
                               const bool pEmitNoncePrologue)
: mStage(MakeSeed_DConfig(pUseNonces)),
  mUseNonces(pUseNonces),
  mEmitNoncePrologue(pEmitNoncePrologue) {
}

GSeedRunSeed_D::~GSeedRunSeed_D() {
}

void GSeedRunSeed_D::Reset() {
    mStage.Reset();
}

bool GSeedRunSeed_D::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GSeedRunSeed_D::Build(TwistProgramBranch &pBranch,
                           std::string *pErrorMessage) {
    if (mUseNonces && mEmitNoncePrologue) {
        AddSeedNoncePrologue(pBranch);
    }
    return mStage.Build(pBranch, pErrorMessage);
}

GSeedRunSeed_E::GSeedRunSeed_E(const bool pUseNonces,
                               const bool pEmitNoncePrologue)
: mStage(MakeSeed_EConfig(pUseNonces)),
  mUseNonces(pUseNonces),
  mEmitNoncePrologue(pEmitNoncePrologue) {
}

GSeedRunSeed_E::~GSeedRunSeed_E() {
}

void GSeedRunSeed_E::Reset() {
    mStage.Reset();
}

bool GSeedRunSeed_E::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GSeedRunSeed_E::Build(TwistProgramBranch &pBranch,
                           std::string *pErrorMessage) {
    if (mUseNonces && mEmitNoncePrologue) {
        AddSeedNoncePrologue(pBranch);
    }
    return mStage.Build(pBranch, pErrorMessage);
}

GSeedRunSeed_F::GSeedRunSeed_F(const bool pUseNonces,
                               const bool pEmitNoncePrologue)
: mStage(MakeSeed_FConfig(pUseNonces)),
  mUseNonces(pUseNonces),
  mEmitNoncePrologue(pEmitNoncePrologue) {
}

GSeedRunSeed_F::~GSeedRunSeed_F() {
}

void GSeedRunSeed_F::Reset() {
    mStage.Reset();
}

bool GSeedRunSeed_F::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GSeedRunSeed_F::Build(TwistProgramBranch &pBranch,
                           std::string *pErrorMessage) {
    if (mUseNonces && mEmitNoncePrologue) {
        AddSeedNoncePrologue(pBranch);
    }
    return mStage.Build(pBranch, pErrorMessage);
}

GSeedRunSeed_G::GSeedRunSeed_G(const bool pUseNonces,
                               const bool pEmitNoncePrologue)
: mStage(MakeSeed_GConfig(pUseNonces)),
  mUseNonces(pUseNonces),
  mEmitNoncePrologue(pEmitNoncePrologue) {
}

GSeedRunSeed_G::~GSeedRunSeed_G() {
}

void GSeedRunSeed_G::Reset() {
    mStage.Reset();
}

bool GSeedRunSeed_G::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GSeedRunSeed_G::Build(TwistProgramBranch &pBranch,
                           std::string *pErrorMessage) {
    if (mUseNonces && mEmitNoncePrologue) {
        AddSeedNoncePrologue(pBranch);
    }
    return mStage.Build(pBranch, pErrorMessage);
}

GSeedRunSeed_H::GSeedRunSeed_H(const bool pUseNonces,
                               const bool pEmitNoncePrologue)
: mStage(MakeSeed_HConfig(pUseNonces)),
  mUseNonces(pUseNonces),
  mEmitNoncePrologue(pEmitNoncePrologue) {
}

GSeedRunSeed_H::~GSeedRunSeed_H() {
}

void GSeedRunSeed_H::Reset() {
    mStage.Reset();
}

bool GSeedRunSeed_H::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GSeedRunSeed_H::Build(TwistProgramBranch &pBranch,
                           std::string *pErrorMessage) {
    if (mUseNonces && mEmitNoncePrologue) {
        AddSeedNoncePrologue(pBranch);
    }
    return mStage.Build(pBranch, pErrorMessage);
}

GSeedRunSeed_I::GSeedRunSeed_I(const bool pUseNonces,
                               const bool pEmitNoncePrologue)
: mStage(MakeSeed_IConfig(pUseNonces)),
  mUseNonces(pUseNonces),
  mEmitNoncePrologue(pEmitNoncePrologue) {
}

GSeedRunSeed_I::~GSeedRunSeed_I() {
}

void GSeedRunSeed_I::Reset() {
    mStage.Reset();
}

bool GSeedRunSeed_I::Plan(std::string *pErrorMessage) {
    return mStage.Plan(pErrorMessage);
}

bool GSeedRunSeed_I::Build(TwistProgramBranch &pBranch,
                           std::string *pErrorMessage) {
    if (mUseNonces && mEmitNoncePrologue) {
        AddSeedNoncePrologue(pBranch);
    }
    return mStage.Build(pBranch, pErrorMessage);
}
