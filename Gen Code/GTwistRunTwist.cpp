
GSeedRunStageConfig MakeTwist_AConfig() {
    
    std::vector<Slot> aInputs;
    aInputs = {Slot::kKeyRowReadA, Slot::kKeyRowReadB, Slot::kSource};

    std::vector<Slot> aOutputs;
    aOutputs = {
        Slot::kWorkLaneA, Slot::kWorkLaneB, Slot::kInvestA, Slot::kInvestB,
        Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD,
        Slot::kExpansionLaneA, Slot::kExpansionLaneB, Slot::kExpansionLaneC, Slot::kExpansionLaneD};
    
}

GSeedRunStageConfig MakeTwist_BConfig() {
    
    std::vector<Slot> aInputs;
    aInputs = { Slot::kExpansionLaneA, Slot::kExpansionLaneB, Slot::kExpansionLaneC, Slot::kExpansionLaneD };

    std::vector<Slot> aResiduals;
    aResiduals = { Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD };

    std::vector<Slot> aOutputs;
    aOutputs = { Slot::kInvestC, Slot::kInvestD, Slot::kOperationLaneA, Slot::kOperationLaneB, Slot::kOperationLaneC, Slot::kOperationLaneD};
    
}

GSeedRunStageConfig MakeTwist_CConfig() {
    
    std::vector<Slot> aInputs;
    aInputs = {Slot::kOperationLaneA, Slot::kOperationLaneB, Slot::kOperationLaneC, Slot::kOperationLaneD};

    std::vector<Slot> aResiduals;
    aResiduals = {Slot::kInvestA, Slot::kInvestB, Slot::kInvestC, Slot::kInvestD,
        Slot::kExpansionLaneA, Slot::kExpansionLaneB, Slot::kExpansionLaneC, Slot::kExpansionLaneD};

    std::vector<Slot> aOutputs;
    aOutputs = { Slot::kSnowLaneA, Slot::kSnowLaneB, Slot::kWorkLaneA, Slot::kWorkLaneB, Slot::kWorkLaneC, Slot::kWorkLaneD};
    
}
