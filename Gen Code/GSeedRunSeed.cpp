
GSeedRunStageConfig MakeSeed_AConfig(const bool pUseNonces) {
    std::vector<Slot> aInputs;
    aInputs = {Slot::kKeyRowReadA, Slot::kKeyRowReadB, Slot::kSource};
    
    std::vector<Slot> aOutputs;
    aOutputs = {
        Slot::kWorkLaneA, Slot::kWorkLaneB, Slot::kWorkLaneC, Slot::kWorkLaneD,
        Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD,
        Slot::kExpansionLaneA, Slot::kExpansionLaneB, Slot::kExpansionLaneC, Slot::kExpansionLaneD};
}

GSeedRunStageConfig MakeSeed_BConfig(const bool pUseNonces) {
    
    
    std::vector<Slot> aInputs;
    aInputs = { Slot::kExpansionLaneA, Slot::kExpansionLaneB, Slot::kExpansionLaneC, Slot::kExpansionLaneD };
    
    std::vector<Slot> aResiduals;
    aResiduals = { Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD };
    
    std::vector<Slot> aOutputs;
    aOutputs = { Slot::kInvestA, Slot::kInvestB, Slot::kOperationLaneA, Slot::kOperationLaneB, Slot::kOperationLaneC, Slot::kOperationLaneD };
    
}

GSeedRunStageConfig MakeSeed_CConfig(const bool pUseNonces) {
    
    std::vector<Slot> aInputs;
    aInputs = { Slot::kOperationLaneA, Slot::kOperationLaneB, Slot::kOperationLaneC, Slot::kOperationLaneD };
    
    std::vector<Slot> aResiduals;
    aResiduals = { Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD,
        Slot::kExpansionLaneA, Slot::kExpansionLaneB, Slot::kExpansionLaneC, Slot::kExpansionLaneD};
    
    std::vector<Slot> aOutputs;
    aOutputs = { Slot::kInvestC, Slot::kInvestD, Slot::kWorkLaneA, Slot::kWorkLaneB, Slot::kWorkLaneC, Slot::kWorkLaneD };
    
}

for (int i=0;i<4;i+=2) {
    
    GRunMatrixDiffusionConfig aDiffusionA;
    aDiffusionA.mInputA = aWorkLanes[i];
    aDiffusionA.mInputB = aWorkLanes[i + 1];
    aDiffusionA.mOutputA = aExpansionLanes[i];
    aDiffusionA.mOutputB =  aExpansionLanes[i + 1];
    
}

GSeedRunStageConfig MakeSeed_DConfig(const bool pUseNonces) {
    
    
    std::vector<Slot> aInputs;
    aInputs = { Slot::kExpansionLaneA, Slot::kExpansionLaneB, Slot::kExpansionLaneC, Slot::kExpansionLaneD };

    std::vector<Slot> aResiduals;
    aResiduals = {
        Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD,
        Slot::kInvestA, Slot::kInvestB, Slot::kInvestC, Slot::kInvestD
    };

    std::vector<Slot> aOutputs;
    aOutputs = {Slot::kSnowLaneA, Slot::kSnowLaneB, Slot::kInvestA, Slot::kInvestB, Slot::kInvestC, Slot::kInvestD };
    
}

GSeedRunStageConfig MakeSeed_EConfig(const bool pUseNonces) {
    
    std::vector<Slot> aInputs;
    aInputs = { Slot::kInvestA, Slot::kInvestB, Slot::kInvestC, Slot::kInvestD };

    std::vector<Slot> aResiduals;
    aResiduals = { Slot::kWorkLaneA, Slot::kWorkLaneB, Slot::kWorkLaneC, Slot::kWorkLaneD,
                    Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD };

    std::vector<Slot> aOutputs;
    aOutputs = {Slot::kFireLaneA, Slot::kFireLaneB, Slot::kOperationLaneA, Slot::kOperationLaneB, Slot::kOperationLaneC, Slot::kOperationLaneD };
    
}

GSeedRunStageConfig MakeSeed_FConfig(const bool pUseNonces) {
   
    std::vector<Slot> aInputs;
    aInputs = { Slot::kOperationLaneA, Slot::kOperationLaneB, Slot::kOperationLaneC, Slot::kOperationLaneD };

    std::vector<Slot> aResiduals;
    aResiduals = {
        Slot::kSnowLaneA, Slot::kSnowLaneB, Slot::kWorkLaneC, Slot::kWorkLaneD,
        Slot::kInvestA, Slot::kInvestB, Slot::kInvestC, Slot::kInvestD,
    };

    std::vector<Slot> aOutputs;
    aOutputs = {Slot::kSnowLaneC, Slot::kSnowLaneD, Slot::kExpansionLaneA, Slot::kExpansionLaneB, Slot::kExpansionLaneC, Slot::kExpansionLaneD };
    
}

for (int i=0;i<4;i+=2) {
    GRunMatrixDiffusionConfig aDiffusionA;
    aDiffusionA.mInputA = aExpansionLanes[i];
    aDiffusionA.mInputB = aExpansionLanes[i + 1];
    aDiffusionA.mOutputA = aSnowLanes[i];
    aDiffusionA.mOutputB =  aSnowLanes[i + 1];
}

GSeedRunStageConfig MakeSeed_GConfig(const bool pUseNonces) {
    
    std::vector<Slot> aInputs;
    aInputs = { Slot::kSnowLaneA, Slot::kSnowLaneB, Slot::kSnowLaneC, Slot::kSnowLaneD };
        
    std::vector<Slot> aResiduals;
    aResiduals = {
        Slot::kInvestA, Slot::kInvestB, Slot::kInvestC, Slot::kInvestD,
        Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD
    };

    std::vector<Slot> aOutputs;
    aOutputs = { Slot::kWorkLaneA, Slot::kWorkLaneB, Slot::kExpansionLaneA, Slot::kExpansionLaneB, Slot::kExpansionLaneC, Slot::kExpansionLaneD };

}

