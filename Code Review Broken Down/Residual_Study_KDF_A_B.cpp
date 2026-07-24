
KDF_A_AConfig() {
    
    aPrimarySources = {
        Slot::kSource, Slot::kParamSnow,
    };
    aWarmUpLanes = {
        Slot::kPoisonLaneA, Slot::kPoisonLaneB,
    };
    aDestinations = {
        Slot::kEarthLaneA, Slot::kEarthLaneB, Slot::kEarthLaneC, Slot::kEarthLaneD,
    };
}

// [poi-a] x 0, [poi-b] x 0

KDF_A_BConfig() {
    
    aPrimarySources = {
        Slot::kEarthLaneA, Slot::kEarthLaneB, Slot::kEarthLaneC, Slot::kEarthLaneD,
    };
    aResidualSources = {
        Slot::kSource, Slot::kParamSnow,
        Slot::kPoisonLaneA, Slot::kPoisonLaneB,
    };
    aWarmUpLanes = {
        Slot::kPoisonLaneC, Slot::kPoisonLaneD,
    };
    aDestinations = {
        Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD,
    };
}

// [poi-a] x 1, [poi-b] x 1, [poi-c] x 0, [poi-d] x 0
// [ear-a] x 0, [ear-b] x 0, [ear-c] x 0, [ear-d] x 0

KDF_A_CConfig() {
    
    aPrimarySources = {
        Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD,
    };
    aResidualSources = {
        Slot::kSource, Slot::kParamSnow,
        Slot::kEarthLaneA, Slot::kEarthLaneB, Slot::kEarthLaneC, Slot::kEarthLaneD,
        Slot::kPoisonLaneA, Slot::kPoisonLaneB, Slot::kPoisonLaneC, Slot::kPoisonLaneD,
    };
    aDestinations = {
        Slot::kFuseLaneA, Slot::kFuseLaneB, Slot::kFuseLaneC, Slot::kFuseLaneD,
    };
}

// [poi-a] x 2, [poi-b] x 2, [poi-c] x 1, [poi-d] x 1
// [ear-a] x 1, [ear-b] x 1, [ear-c] x 1, [ear-d] x 1
// [fir-a] x 0, [fir-b] x 0, [fir-c] x 0, [fir-d] x 0

// Here we diffuse [fuse] through [fire] to [wind]

KDF_A_DConfig() {
    
    aPrimarySources = {
        Slot::kWindLaneA, Slot::kWindLaneB, Slot::kWindLaneC, Slot::kWindLaneD,
    };
    aResidualSources = {
        Slot::kSource, Slot::kParamSnow,
        Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD,
        Slot::kEarthLaneA, Slot::kEarthLaneB, Slot::kEarthLaneC, Slot::kEarthLaneD,
        Slot::kPoisonLaneA, Slot::kPoisonLaneB, Slot::kPoisonLaneC, Slot::kPoisonLaneD,
    };
    aDestinations = {
        Slot::kWaterLaneA, Slot::kWaterLaneB, Slot::kWaterLaneC, Slot::kWaterLaneD,
    };
}

// [poi-a] x 3, [poi-b] x 3, [poi-c] x 2, [poi-d] x 2
// [ear-a] x 2, [ear-b] x 2, [ear-c] x 2, [ear-d] x 2
// [fir-a] x 1, [fir-b] x 1, [fir-c] x 1, [fir-d] x 1
// [win-a] x 0, [win-b] x 0, [win-c] x 0, [win-d] x 0

KDF_B_AConfig() {
    
    aInputs = {
        Slot::kWaterLaneA, Slot::kWaterLaneB, Slot::kWaterLaneC, Slot::kWaterLaneD,
    };
    aResiduals = {
        Slot::kSource,
        
        Slot::kPoisonLaneA, Slot::kPoisonLaneB,
        Slot::kPoisonLaneC, Slot::kPoisonLaneD,
        Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD,
        Slot::kEarthLaneA, Slot::kEarthLaneB, Slot::kEarthLaneC, Slot::kEarthLaneD,
        
        Slot::kWindLaneA, Slot::kWindLaneB, Slot::kWindLaneC, Slot::kWindLaneD,
    };
    
    aOutputs = {
        Slot::kWoodLaneA, Slot::kWoodLaneB,
        Slot::kWoodLaneC, Slot::kWoodLaneD,
    };
}

// [poi-a] x 3, [poi-b] x 3, [poi-c] x 3, [poi-d] x 3
// [ear-a] x 3, [ear-b] x 3, [ear-c] x 3, [ear-d] x 3
// [fir-a] x 2, [fir-b] x 2, [fir-c] x 2, [fir-d] x 2
// [win-a] x 1, [win-b] x 1, [win-c] x 1, [win-d] x 1
// [wat-a] x 0, [wat-b] x 0, [wat-c] x 0, [wat-d] x 0

KDF_B_BConfig() {
    
    aInputs = {
        Slot::kWoodLaneA, Slot::kWoodLaneB,
        Slot::kWoodLaneC, Slot::kWoodLaneD,
    };
    aResiduals = {
        Slot::kSource, Slot::kEarthLaneA, Slot::kEarthLaneB, Slot::kEarthLaneC,
        
        Slot::kFireLaneA, Slot::kFireLaneB, Slot::kFireLaneC, Slot::kFireLaneD,
        
        Slot::kWindLaneA, Slot::kWindLaneB, Slot::kWindLaneC, Slot::kWindLaneD,
        Slot::kWaterLaneA, Slot::kWaterLaneB, Slot::kWaterLaneC, Slot::kWaterLaneD,
    };
    
    aOutputs = {
        Slot::kSpiritLaneA, Slot::kSpiritLaneB,
        Slot::kSpiritLaneC, Slot::kSpiritLaneD,
    };
}

// [poi-a] x 3, [poi-b] x 3, [poi-c] x 3, [poi-d] x 3
// [ear-a] x 4, [ear-b] x 4, [ear-c] x 4, [ear-d] x 3
// [fir-a] x 3, [fir-b] x 3, [fir-c] x 3, [fir-d] x 3
// [win-a] x 2, [win-b] x 2, [win-c] x 2, [win-d] x 2
// [wat-a] x 1, [wat-b] x 1, [wat-c] x 1, [wat-d] x 1
// [woo-a] x 0, [woo-b] x 0, [woo-c] x 0, [woo-d] x 0

KDF_B_CConfig() {
    
    aInputs = {
        Slot::kSpiritLaneA, Slot::kSpiritLaneB,
        Slot::kSpiritLaneC, Slot::kSpiritLaneD,
    };
    aResiduals = {
        Slot::kSource, Slot::kEarthLaneD, Slot::kFireLaneC, Slot::kFireLaneD,
        
        Slot::kWindLaneA, Slot::kWindLaneB, Slot::kWindLaneC, Slot::kWindLaneD,
        Slot::kWaterLaneA, Slot::kWaterLaneB, Slot::kWaterLaneC, Slot::kWaterLaneD,
        
        Slot::kWoodLaneA, Slot::kWoodLaneB, Slot::kWoodLaneC, Slot::kWoodLaneD,
    };
    
    aOutputs = {
        Slot::kFuseLaneA, Slot::kFuseLaneB,
        Slot::kFuseLaneC, Slot::kFuseLaneD,
    };
}

// [poi-a] x 3, [poi-b] x 3, [poi-c] x 3, [poi-d] x 3
// [ear-a] x 4, [ear-b] x 4, [ear-c] x 4, [ear-d] x 4
// [fir-a] x 3, [fir-b] x 3, [fir-c] x 4, [fir-d] x 4
// [win-a] x 3, [win-b] x 3, [win-c] x 3, [win-d] x 3
// [wat-a] x 2, [wat-b] x 2, [wat-c] x 2, [wat-d] x 2
// [woo-a] x 1, [woo-b] x 1, [woo-c] x 1, [woo-d] x 1
// [spi-a] x 0, [spi-b] x 0, [spi-c] x 0, [spi-d] x 0

// Here we diffuse [fuse] through [spirit] to [poison]

KDF_B_DConfig() {
    
    aInputs = {
        Slot::kPoisonLaneA, Slot::kPoisonLaneB,
        Slot::kPoisonLaneC, Slot::kPoisonLaneD,
    };
    aResiduals = {
        Slot::kFireLaneA, Slot::kFireLaneB, Slot::kWindLaneC, Slot::kWindLaneD,
        Slot::kWaterLaneA, Slot::kWaterLaneB, Slot::kWaterLaneC, Slot::kWaterLaneD,
        Slot::kWoodLaneA, Slot::kWoodLaneB, Slot::kWoodLaneC, Slot::kWoodLaneD,
        Slot::kSpiritLaneA, Slot::kSpiritLaneB, Slot::kSpiritLaneC, Slot::kSpiritLaneD,
    };
    
    aOutputs = {
        Slot::kHeartLaneA, Slot::kHeartLaneB,
        Slot::kHeartLaneC, Slot::kHeartLaneD,
    };
}














