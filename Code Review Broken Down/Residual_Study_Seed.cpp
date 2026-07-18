Seed_AConfig() {
    
    aPrimarySources = {
        Slot::kSource, Slot::kKeyRowReadA, Slot::kKeyRowReadB,
    };
    aWarmUpLanes = {
        Slot::kWorkLaneA, Slot::kWorkLaneB,
    };
    aDestinations = {
        Slot::kExpansionLaneA, Slot::kExpansionLaneB,
        Slot::kExpansionLaneC, Slot::kExpansionLaneD,
    };
}

Seed_BConfig() {
    
    aPrimarySources = {
        Slot::kExpansionLaneA, Slot::kExpansionLaneB,
        Slot::kExpansionLaneC, Slot::kExpansionLaneD,
    };
    aResidualSources = {
        Slot::kSource, Slot::kKeyRowReadA, Slot::kKeyRowReadB,
        Slot::kWorkLaneA, Slot::kWorkLaneB,
    };
    aWarmUpLanes = {
        Slot::kWorkLaneC, Slot::kWorkLaneD,
    };
    aDestinations = {
        Slot::kEarthLaneA, Slot::kEarthLaneB,
        Slot::kEarthLaneC, Slot::kEarthLaneD,
    };
}

Seed_CConfig() {
    
    aPrimarySources = {
        Slot::kEarthLaneA, Slot::kEarthLaneB,
        Slot::kEarthLaneC, Slot::kEarthLaneD,
    };
    aResidualSources = {
        Slot::kSource,
        Slot::kWorkLaneA, Slot::kWorkLaneB,
        Slot::kWorkLaneC, Slot::kWorkLaneD,
        Slot::kExpansionLaneA, Slot::kExpansionLaneB,
        Slot::kExpansionLaneC, Slot::kExpansionLaneD,
    };
    aPrefixDestinations = {
        Slot::kScrapLaneA, Slot::kScrapLaneB,
    };
    aBodyDestinations = {
        Slot::kOperationLaneA, Slot::kOperationLaneB,
        Slot::kOperationLaneC, Slot::kOperationLaneD,
    };
}

Seed_DConfig() {
    
    aPrimarySources = {
        Slot::kOperationLaneA, Slot::kOperationLaneB,
        Slot::kOperationLaneC, Slot::kOperationLaneD,
    };
    aResidualSources = {
        Slot::kKeyRowReadA,
        
        Slot::kWorkLaneD,
        Slot::kScrapLaneA, Slot::kScrapLaneB,
        
        Slot::kExpansionLaneA, Slot::kExpansionLaneB,
        Slot::kExpansionLaneC, Slot::kExpansionLaneD,
        
        Slot::kEarthLaneA, Slot::kEarthLaneB,
        Slot::kEarthLaneC, Slot::kEarthLaneD,
        
    };
    aPrefixDestinations = {
        Slot::kScrapLaneC, Slot::kScrapLaneD,
    };
    aBodyDestinations = {
        Slot::kFuseLaneA, Slot::kFuseLaneB,
        Slot::kFuseLaneC, Slot::kFuseLaneD,
    };
}

// Here we diffuse [fuse] to [fire]

Seed_EConfig() {
    
    aPrimarySources = {
        Slot::kFireLaneA, Slot::kFireLaneB,
        Slot::kFireLaneC, Slot::kFireLaneD,
    };
    aResidualSources = {
        Slot::kKeyRowReadB,
        
        Slot::kOperationLaneA, Slot::kOperationLaneB,
        Slot::kOperationLaneC, Slot::kOperationLaneD,
        
        Slot::kEarthLaneA, Slot::kEarthLaneB,
        Slot::kEarthLaneC, Slot::kEarthLaneD,
        
        Slot::kScrapLaneA, Slot::kScrapLaneB,
        Slot::kScrapLaneC, Slot::kScrapLaneD,
        
        Slot::kWorkLaneC,
    };
    aPrefixDestinations = {
        Slot::kWaterLaneC, Slot::kWaterLaneD,
    };
    aBodyDestinations = {
        Slot::kInvestA, Slot::kInvestB,
        Slot::kInvestC, Slot::kInvestD,
    };
}

Seed_FConfig() {
    
    aPrimarySources = {
        Slot::kInvestA, Slot::kInvestB,
        Slot::kInvestC, Slot::kInvestD,
    };
    aResidualSources = {
        Slot::kSource,
        
        Slot::kWaterLaneC, Slot::kWaterLaneD,
        
        Slot::kFireLaneA, Slot::kFireLaneB,
        Slot::kFireLaneC, Slot::kFireLaneD,
        
        Slot::kOperationLaneA, Slot::kOperationLaneB,
        Slot::kOperationLaneC, Slot::kOperationLaneD,
        
        Slot::kScrapLaneA, Slot::kScrapLaneB,
        Slot::kScrapLaneC, Slot::kScrapLaneD,
        
        Slot::kEarthLaneD
    };
    
    aPrefixDestinations = {
        Slot::kSnowLaneC, Slot::kSnowLaneD,
    };
    aBodyDestinations = {
        Slot::kWindLaneA, Slot::kWindLaneB,
        Slot::kWindLaneC, Slot::kWindLaneD,
    };
}

Seed_GConfig() {
    
    aPrimarySources = {
        Slot::kWindLaneA, Slot::kWindLaneB,
        Slot::kWindLaneC, Slot::kWindLaneD,
    };
    aResidualSources = {
        Slot::kKeyRowReadA,
        
        Slot::kEarthLaneA, Slot::kEarthLaneB, Slot::kEarthLaneC,
        
        Slot::kWaterLaneC, Slot::kWaterLaneD,
        Slot::kScrapLaneC, Slot::kScrapLaneD,
        Slot::kSnowLaneC, Slot::kSnowLaneD,
        
        Slot::kInvestA, Slot::kInvestB,
        Slot::kInvestC, Slot::kInvestD,
        Slot::kFireLaneA, Slot::kFireLaneB,
        Slot::kFireLaneC, Slot::kFireLaneD,
    };
    
    aPrefixDestinations = {
        Slot::kWaterLaneA, Slot::kWaterLaneB,
    };
    aBodyDestinations = {
        Slot::kOperationLaneA, Slot::kOperationLaneB,
        Slot::kOperationLaneC, Slot::kOperationLaneD,
    };
}

Seed_HConfig() {
    
    aPrimarySources = {
        Slot::kOperationLaneA, Slot::kOperationLaneB,
        Slot::kOperationLaneC, Slot::kOperationLaneD,
    };
    aResidualSources = {
        Slot::kKeyRowReadB,
        Slot::kExpansionLaneD,
        Slot::kWaterLaneA, Slot::kWaterLaneB,
        Slot::kWindLaneA, Slot::kWindLaneB,
        Slot::kWindLaneC, Slot::kWindLaneD,
        Slot::kSnowLaneC, Slot::kSnowLaneD,
        Slot::kInvestA, Slot::kInvestB,
        Slot::kInvestC, Slot::kInvestD,
        Slot::kFireLaneA, Slot::kFireLaneB,
    };
    
    aPrefixDestinations = {
        Slot::kSnowLaneA, Slot::kSnowLaneB,
    };
    aBodyDestinations = {
        Slot::kFuseLaneA, Slot::kFuseLaneB,
        Slot::kFuseLaneC, Slot::kFuseLaneD,
    };
}

// Here we diffuse [fuse] to [invest_efgh]

Seed_IConfig() {
    
    aPrimarySources = {
        Slot::kInvestE, Slot::kInvestF,
        Slot::kInvestG, Slot::kInvestH,
    };
    aResidualSources = {
        Slot::kSnowLaneA, Slot::kSnowLaneB,
        Slot::kOperationLaneA, Slot::kOperationLaneB,
        Slot::kOperationLaneC, Slot::kOperationLaneD,
        Slot::kWindLaneA, Slot::kWindLaneB,
        Slot::kWindLaneC, Slot::kWindLaneD,
        Slot::kWaterLaneA, Slot::kWaterLaneB,
        Slot::kExpansionLaneA, Slot::kExpansionLaneB,
        Slot::kFireLaneC, Slot::kFireLaneD,
    };
    aPrefixDestinations = {
        Slot::kSnowLaneC, Slot::kSnowLaneD,
    };
    aBodyDestinations = {
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

