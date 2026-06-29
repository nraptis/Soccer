
GSeedRunStageConfig MakeGrowAConfig() {

    std::vector<Slot> aInputs;
    aInputs = { Slot::kWorkLaneA, Slot::kWorkLaneB, Slot::kWorkLaneC, Slot::kWorkLaneD };

    std::vector<Slot> aResiduals;
    aResiduals = { Slot::kInvestA, Slot::kInvestB, Slot::kInvestC, Slot::kInvestD,
        Slot::kOperationLaneA, Slot::kOperationLaneB, Slot::kOperationLaneC, Slot::kOperationLaneD,
    };

    std::vector<Slot> aOutputs;
    aOutputs = { Slot::kExpansionLaneA, Slot::kExpansionLaneB, Slot::kExpansionLaneC, Slot::kExpansionLaneD };
    
}

GSeedRunStageConfig MakeGrowBConfig() {
    
    std::vector<Slot> aInputs;
    aInputs = { Slot::kExpansionLaneA, Slot::kExpansionLaneB, Slot::kExpansionLaneC, Slot::kExpansionLaneD };

    std::vector<Slot> aResiduals;
    aResiduals = { Slot::kInvestA, Slot::kInvestB, Slot::kInvestC, Slot::kInvestD,
        Slot::kOperationLaneA, Slot::kOperationLaneB, Slot::kOperationLaneC, Slot::kOperationLaneD,
    };

    std::vector<Slot> aOutputs;
    aOutputs = { Slot::kWorkLaneA, Slot::kWorkLaneB, Slot::kWorkLaneC, Slot::kWorkLaneD };
    
}
