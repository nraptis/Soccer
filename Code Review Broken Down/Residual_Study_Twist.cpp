Twist_AConfig() {
    
    aPrimarySources = {
        Slot::kSource, Slot::kKeyRowReadA, Slot::kKeyRowReadB,
    };
    aWarmUpLanes = {
        Slot::kScrapLaneA, Slot::kScrapLaneB,
    };
    aDestinations = {
        Slot::kWindLaneA, Slot::kWindLaneB,
        Slot::kWindLaneC, Slot::kWindLaneD,
    };
}

Twist_BConfig() {
    
    aInputs = {
        Slot::kWindLaneA, Slot::kWindLaneB,
        Slot::kWindLaneC, Slot::kWindLaneD,
    };

    aResiduals = {
        Slot::kSource, Slot::kKeyRowReadA, Slot::kKeyRowReadB,
        Slot::kScrapLaneA, Slot::kScrapLaneB,
    };
    aWarmUpLanes = {
        Slot::kWorkLaneA, Slot::kWorkLaneB,
    };
    aDestinations = {
        Slot::kSnowLaneA, Slot::kSnowLaneB,
        Slot::kSnowLaneC, Slot::kSnowLaneD,
    };
}

Twist_CConfig() {
    
    aInputs = {
        Slot::kSnowLaneA, Slot::kSnowLaneB,
        Slot::kSnowLaneC, Slot::kSnowLaneD,
    };

    aResiduals = {
        Slot::kSource,
        
        Slot::kScrapLaneA, Slot::kScrapLaneB,
        Slot::kWorkLaneA, Slot::kWorkLaneB,
        
        Slot::kWindLaneA, Slot::kWindLaneB,
        Slot::kWindLaneC, Slot::kWindLaneD,
    };
    aWarmUpLanes = {
        Slot::kInvestA, Slot::kInvestB,
    };
    aDestinations = {
        Slot::kOperationLaneA, Slot::kOperationLaneB,
        Slot::kOperationLaneC, Slot::kOperationLaneD,
    };
}

Twist_DConfig() {
    
    aInputs = {
        Slot::kOperationLaneA, Slot::kOperationLaneB,
        Slot::kOperationLaneC, Slot::kOperationLaneD,
    };

    aResiduals = {
        Slot::kKeyRowReadA,
        
        Slot::kInvestA, Slot::kInvestB,
        
        Slot::kSnowLaneA, Slot::kSnowLaneB,
        Slot::kSnowLaneC, Slot::kSnowLaneD,
        
        Slot::kWindLaneA, Slot::kWindLaneB,
        Slot::kWindLaneC, Slot::kWindLaneD,
        
    };
    aWarmUpLanes = {
        Slot::kScrapLaneC, Slot::kScrapLaneD,
    };
    aDestinations = {
        Slot::kWaterLaneA, Slot::kWaterLaneB,
        Slot::kWaterLaneC, Slot::kWaterLaneD,
    };
}

Twist_EConfig() {
    
    aInputs = {
        Slot::kWaterLaneA, Slot::kWaterLaneB,
        Slot::kWaterLaneC, Slot::kWaterLaneD,
    };

    aResiduals = {
        Slot::kKeyRowReadB,
        
        Slot::kScrapLaneC, Slot::kScrapLaneD,
        
        Slot::kOperationLaneA, Slot::kOperationLaneB,
        Slot::kOperationLaneC, Slot::kOperationLaneD,
        
        Slot::kSnowLaneA, Slot::kSnowLaneB,
        Slot::kSnowLaneC, Slot::kSnowLaneD,
        
        Slot::kInvestA,
    };
    
    aWarmUpLanes = {
        Slot::kInvestC, Slot::kInvestD,
    };
    aDestinations = {
        Slot::kFuseLaneA, Slot::kFuseLaneB,
        Slot::kFuseLaneC, Slot::kFuseLaneD,
    };
}

// Here we diffuse [fuse] to [fire]

Twist_FConfig() {
    
    aInputs = {
        Slot::kFireLaneA, Slot::kFireLaneB,
        Slot::kFireLaneC, Slot::kFireLaneD,
    };

    aResiduals = {
        Slot::kSource,
        Slot::kWaterLaneA, Slot::kWaterLaneB,
        Slot::kWaterLaneC, Slot::kWaterLaneD,
        Slot::kInvestC, Slot::kInvestD,
        Slot::kInvestB,
        Slot::kSnowLaneA, Slot::kSnowLaneB,
        Slot::kOperationLaneA, Slot::kOperationLaneB,
        Slot::kOperationLaneC, Slot::kOperationLaneD,
        Slot::kScrapLaneC, Slot::kScrapLaneD,
        Slot::kScrapLaneA, Slot::kScrapLaneB,
    };
    
    aWarmUpLanes = {
        Slot::kInvestE, Slot::kInvestF,
    };
    aDestinations = {
        Slot::kEarthLaneA, Slot::kEarthLaneB,
        Slot::kEarthLaneC, Slot::kEarthLaneD,
    };
}

Twist_GConfig() {
    
    aInputs = {
        Slot::kEarthLaneA, Slot::kEarthLaneB,
        Slot::kEarthLaneC, Slot::kEarthLaneD,
    };
    aResiduals = {
        Slot::kKeyRowReadA, Slot::kKeyRowReadB,
        
        Slot::kFireLaneA, Slot::kFireLaneB,
        Slot::kFireLaneC, Slot::kFireLaneD,
        
        Slot::kWaterLaneA, Slot::kWaterLaneB,
        Slot::kWaterLaneC, Slot::kWaterLaneD,
        
        Slot::kSnowLaneC, Slot::kSnowLaneD,
        
        Slot::kInvestA, Slot::kInvestB,
        Slot::kInvestC, Slot::kInvestD,
        Slot::kInvestE, Slot::kInvestF,
    };
    aWarmUpLanes = {
        Slot::kInvestG, Slot::kInvestH,
    };
    aDestinations = {
        Slot::kWorkLaneA, Slot::kWorkLaneB,
        Slot::kWorkLaneC, Slot::kWorkLaneD,
    };
}

GrowAConfig() {
    aInputs = {
        Slot::kWorkLaneA, Slot::kWorkLaneB,
        Slot::kWorkLaneC, Slot::kWorkLaneD,
    };
    aResiduals = {
        Slot::kWaterLaneA, Slot::kWaterLaneC,
        Slot::kEarthLaneB,Slot::kEarthLaneD,
        Slot::kInvestA, Slot::kInvestB,
        Slot::kInvestE, Slot::kInvestF,
        
        Slot::kScrapLaneA, Slot::kScrapLaneB,
        Slot::kScrapLaneC, Slot::kScrapLaneD,
        Slot::kFireLaneB, Slot::kFireLaneD,
        Slot::kSnowLaneB, Slot::kSnowLaneD,
        
        Slot::kOperationLaneA, Slot::kOperationLaneC,
    };
    aWarmUpLanes = {
        Slot::kOperationLaneB, Slot::kOperationLaneD,
    };
    aDestinations = {
        Slot::kExpansionLaneA, Slot::kExpansionLaneB,
        Slot::kExpansionLaneC, Slot::kExpansionLaneD,
    };
}

GrowBConfig() {
    
    aInputs = {
        Slot::kExpansionLaneA, Slot::kExpansionLaneB,
        Slot::kExpansionLaneC, Slot::kExpansionLaneD,
    };
    aResiduals = {
        
        Slot::kWaterLaneB, Slot::kWaterLaneD,
        Slot::kEarthLaneA,Slot::kEarthLaneC,
        Slot::kWindLaneA, Slot::kWindLaneB,
        Slot::kWindLaneC, Slot::kWindLaneD,
        
        Slot::kInvestC, Slot::kInvestD,
        Slot::kInvestG, Slot::kInvestH,
        Slot::kFireLaneA, Slot::kFireLaneC,
        Slot::kSnowLaneA, Slot::kSnowLaneC,
        
        Slot::kOperationLaneB, Slot::kOperationLaneD,
    };
    aWarmUpLanes = {
        Slot::kFuseLaneC, Slot::kFuseLaneD,
    };
    aDestinations = {
        Slot::kWorkLaneA, Slot::kWorkLaneB,
        Slot::kWorkLaneC, Slot::kWorkLaneD,
    };
}
