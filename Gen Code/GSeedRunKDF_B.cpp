
GSeedRunStageConfig MakeKDF_B_AConfig() {

    std::vector<Slot> aInputs;
    aInputs = { Slot::kWorkLaneA, Slot::kWorkLaneB, Slot::kWorkLaneC, Slot::kWorkLaneD };

    std::vector<Slot> aResiduals;
    aResiduals = { Slot::kOperationLaneA, Slot::kOperationLaneB, Slot::kOperationLaneC, Slot::kOperationLaneD,
        Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD};

    std::vector<Slot> aOutputs;
    aOutputs = { Slot::kExpansionLaneA, Slot::kExpansionLaneB, Slot::kExpansionLaneC, Slot::kExpansionLaneD };
}

GSeedRunStageConfig MakeKDF_B_BConfig() {
    
    std::vector<Slot> aInputs;
    aInputs = { Slot::kExpansionLaneA, Slot::kExpansionLaneB, Slot::kExpansionLaneC, Slot::kExpansionLaneD };

    std::vector<Slot> aResiduals;
    aResiduals = { Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD,
                   Slot::kWorkLaneA, Slot::kWorkLaneB, Slot::kWorkLaneC, Slot::kWorkLaneD };

    std::vector<Slot> aOutputs;
    aOutputs = { Slot::kOperationLaneA, Slot::kOperationLaneB, Slot::kOperationLaneC, Slot::kOperationLaneD };

}

GSeedRunStageConfig MakeKDF_B_CConfig() {
    
    std::vector<Slot> aInputs;
    aInputs = { Slot::kOperationLaneA, Slot::kOperationLaneB, Slot::kOperationLaneC, Slot::kOperationLaneD };

    std::vector<Slot> aResiduals;
    aResiduals = { Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD,
                   Slot::kWorkLaneA, Slot::kWorkLaneB, Slot::kWorkLaneC, Slot::kWorkLaneD };

    std::vector<Slot> aOutputs;
    aOutputs = { Slot::kExpansionLaneA, Slot::kExpansionLaneB, Slot::kExpansionLaneC, Slot::kExpansionLaneD };

}

for (int i=0;i<4;i+=2) {
    GRunMatrixDiffusionConfig aDiffusionB;
    aDiffusionB.mInputA = aExpansionLanes[i];
    aDiffusionB.mInputB = aExpansionLanes[i + 1];
    aDiffusionB.mOutputA = aWorkLanes[i];
    aDiffusionB.mOutputB = aWorkLanes[i + 1];
}

GSeedRunStageConfig MakeKDF_B_DConfig() {
    
    std::vector<Slot> aInputs;
    aInputs = { Slot::kWorkLaneA, Slot::kWorkLaneB, Slot::kWorkLaneC, Slot::kWorkLaneD };

    std::vector<Slot> aResiduals;
    aResiduals = { Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD,
                   Slot::kOperationLaneA, Slot::kOperationLaneB, Slot::kOperationLaneC, Slot::kOperationLaneD };

    std::vector<Slot> aOutputs;
    aOutputs = { Slot::kExpansionLaneA, Slot::kExpansionLaneB, Slot::kExpansionLaneC, Slot::kExpansionLaneD };

}
