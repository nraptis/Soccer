
GSeedRunStageConfig MakeKDF_A_AConfig() {
    
    std::vector<Slot> aInputs;
    aInputs = {Slot::kSource, Slot::kParamSnow};

    std::vector<Slot> aOutputs;
    aOutputs = {
        Slot::kWorkLaneA, Slot::kWorkLaneB,
        Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD};

}

GSeedRunStageConfig MakeKDF_A_BConfig() {
    
    std::vector<Slot> aInputs;
    aInputs = { Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD };

    std::vector<Slot> aResiduals;

    std::vector<Slot> aOutputs;
    aOutputs = {Slot::kOperationLaneA, Slot::kOperationLaneB, Slot::kOperationLaneC, Slot::kOperationLaneD};

}

GSeedRunStageConfig MakeKDF_A_CConfig() {
    
    std::vector<Slot> aInputs;
    aInputs = { Slot::kOperationLaneA, Slot::kOperationLaneB, Slot::kOperationLaneC, Slot::kOperationLaneD };
    
    std::vector<Slot> aResiduals;
    aResiduals = { Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD };
    
    std::vector<Slot> aOutputs;
    aOutputs = { Slot::kWorkLaneA, Slot::kWorkLaneB, Slot::kWorkLaneC, Slot::kWorkLaneD};
    
}

for (int i=0;i<4;i+=2) {
    GRunMatrixDiffusionConfig aDiffusionA;
    aDiffusionA.mInputA = aWorkLanes[i];
    aDiffusionA.mInputB = aWorkLanes[i + 1];
    aDiffusionA.mOutputA = aExpansionLanes[i];
    aDiffusionA.mOutputB =  aExpansionLanes[i + 1];
}

GSeedRunStageConfig MakeKDF_A_DConfig() {
    
    std::vector<Slot> aInputs;
    aInputs = { Slot::kExpansionLaneA, Slot::kExpansionLaneB, Slot::kExpansionLaneC, Slot::kExpansionLaneD };

    std::vector<Slot> aResiduals;
    aResiduals = { Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD,
        Slot::kOperationLaneA, Slot::kOperationLaneB, Slot::kOperationLaneC, Slot::kOperationLaneD};

    std::vector<Slot> aOutputs;
    aOutputs = { Slot::kWorkLaneA, Slot::kWorkLaneB, Slot::kWorkLaneC, Slot::kWorkLaneD};
    
}
