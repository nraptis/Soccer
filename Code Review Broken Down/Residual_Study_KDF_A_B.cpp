KDF_A_AConfig() {
    
    aPrimarySources = {
        Slot::kSource, Slot::kParamSnow,
    };
    aWarmUpLanes = {
        Slot::kScrapLaneA, Slot::kScrapLaneB,
    };
    aDestinations = {
        Slot::kEarthLaneA, Slot::kEarthLaneB, Slot::kEarthLaneC, Slot::kEarthLaneD,
    };
}

KDF_A_BConfig() {
    
    aPrimarySources = {
        Slot::kEarthLaneA, Slot::kEarthLaneB, Slot::kEarthLaneC, Slot::kEarthLaneD,
    };
    aResidualSources = {
        Slot::kSource, Slot::kParamSnow,
        Slot::kScrapLaneA, Slot::kScrapLaneB,
    };
    aDestinations = {
        Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD,
    };
}

KDF_A_CConfig() {
    
    aPrimarySources = {
        Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD,
    };
    aResidualSources = {
        Slot::kSource, Slot::kParamSnow,
        Slot::kEarthLaneA, Slot::kEarthLaneB, Slot::kEarthLaneC, Slot::kEarthLaneD,
        Slot::kScrapLaneA, Slot::kScrapLaneB,
    };
    aDestinations = {
        Slot::kOperationLaneA, Slot::kOperationLaneB, Slot::kOperationLaneC, Slot::kOperationLaneD,
    };
}

KDF_A_DConfig() {
    
    aPrimarySources = {
        Slot::kOperationLaneA, Slot::kOperationLaneB, Slot::kOperationLaneC, Slot::kOperationLaneD,
    };
    aResidualSources = {
        Slot::kSource, Slot::kParamSnow,
        Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD,
        Slot::kEarthLaneA, Slot::kEarthLaneB, Slot::kEarthLaneC, Slot::kEarthLaneD,
        Slot::kScrapLaneA, Slot::kScrapLaneB,
    };
    aDestinations = {
        Slot::kFuseLaneA, Slot::kFuseLaneB, Slot::kFuseLaneC, Slot::kFuseLaneD,
    };
}

// Here we diffuse [fuse] to [wind]

KDF_A_EConfig() {
    
    aPrimarySources = {
        Slot::kWindLaneA, Slot::kWindLaneB, Slot::kWindLaneC, Slot::kWindLaneD,
    };
    aResidualSources = {
        Slot::kSource, Slot::kParamSnow,
        Slot::kEarthLaneA, Slot::kEarthLaneB,
        Slot::kEarthLaneC, Slot::kEarthLaneD,
        Slot::kFireLaneA, Slot::kFireLaneB,
        Slot::kFireLaneC, Slot::kFireLaneD,
        Slot::kOperationLaneA, Slot::kOperationLaneB,
        Slot::kOperationLaneC, Slot::kOperationLaneD,
    };
    aDestinations = {
        Slot::kWaterLaneA, Slot::kWaterLaneB, Slot::kWaterLaneC, Slot::kWaterLaneD,
    };
}



KDF_B_AConfig() {
    
    aInputs = {
        Slot::kWaterLaneA, Slot::kWaterLaneB,
        Slot::kWaterLaneC, Slot::kWaterLaneD,
    };
    aResiduals = {
        Slot::kSource,
        Slot::kWindLaneA, Slot::kWindLaneB,
        Slot::kWindLaneC, Slot::kWindLaneD,
        
        Slot::kFireLaneB,
        Slot::kFireLaneC, Slot::kFireLaneD,
        
        Slot::kOperationLaneA, Slot::kOperationLaneB,
        Slot::kOperationLaneC, Slot::kOperationLaneD,
    };
    
    aOutputs = {
        Slot::kScrapLaneA, Slot::kScrapLaneB,
        Slot::kScrapLaneC, Slot::kScrapLaneD,
    };
}

KDF_B_BConfig() {
    
    aInputs = {
        Slot::kScrapLaneA, Slot::kScrapLaneB,
        Slot::kScrapLaneC, Slot::kScrapLaneD,
    };
    aResiduals = {
        Slot::kSource,
        Slot::kWaterLaneA, Slot::kWaterLaneB,
        Slot::kWaterLaneC, Slot::kWaterLaneD,
        Slot::kWindLaneA, Slot::kWindLaneB,
        Slot::kWindLaneC, Slot::kWindLaneD,
        Slot::kFireLaneA,
        
        Slot::kEarthLaneA, Slot::kEarthLaneB,
        Slot::kEarthLaneC, Slot::kEarthLaneD,
    };
    
    aOutputs = {
        Slot::kOperationLaneA, Slot::kOperationLaneB,
        Slot::kOperationLaneC, Slot::kOperationLaneD,
    };
}

KDF_B_CConfig() {
    
    aInputs = {
        Slot::kOperationLaneA, Slot::kOperationLaneB,
        Slot::kOperationLaneC, Slot::kOperationLaneD,
    };
    aResiduals = {
        Slot::kScrapLaneA, Slot::kScrapLaneB,
        Slot::kScrapLaneC, Slot::kScrapLaneD,
        Slot::kWaterLaneA, Slot::kWaterLaneB,
        Slot::kWaterLaneC, Slot::kWaterLaneD,
        Slot::kWindLaneA, Slot::kWindLaneB,
        Slot::kWindLaneC, Slot::kWindLaneD,
        
        Slot::kFireLaneA, Slot::kFireLaneB,
        Slot::kFireLaneC, Slot::kFireLaneD,
    };
    
    aOutputs = {
        Slot::kFuseLaneA, Slot::kFuseLaneB,
        Slot::kFuseLaneC, Slot::kFuseLaneD,
    };
}

// Here we diffuse [fuse] to [worker]

KDF_B_DConfig() {
    
    aInputs = {
        Slot::kWorkLaneA, Slot::kWorkLaneB,
        Slot::kWorkLaneC, Slot::kWorkLaneD,
    };
    aResiduals = {
        Slot::kSource,
        
        Slot::kOperationLaneA, Slot::kOperationLaneB,
        Slot::kOperationLaneC, Slot::kOperationLaneD,
        
        Slot::kScrapLaneA, Slot::kScrapLaneB,
        Slot::kScrapLaneC, Slot::kScrapLaneD,
        
        Slot::kWaterLaneA, Slot::kWaterLaneB,
        Slot::kWaterLaneC, Slot::kWaterLaneD,
        
        Slot::kWindLaneB, Slot::kWindLaneC,
        Slot::kWindLaneD,
    };
    
    aOutputs = {
        Slot::kExpansionLaneA, Slot::kExpansionLaneB,
        Slot::kExpansionLaneC, Slot::kExpansionLaneD,
    };
}


