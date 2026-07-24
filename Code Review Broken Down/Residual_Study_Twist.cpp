

Twist_AConfig() {
    aPrimarySources = {
        Slot::kSource, Slot::kKeyRowReadA, Slot::kKeyRowReadB,
    };
    aWarmUpLanes = {
        Slot::kPoisonLaneA, Slot::kPoisonLaneB,
    };
    aDestinations = {
        Slot::kEarthLaneA, Slot::kEarthLaneB,
        Slot::kEarthLaneC, Slot::kEarthLaneD,
    };
}

// [poi-a] x 0, [poi-b] x 0

Twist_BConfig() {
    
    aInputs = {
        Slot::kEarthLaneA, Slot::kEarthLaneB,
        Slot::kEarthLaneC, Slot::kEarthLaneD,
    };

    aResiduals = {
        Slot::kSource, Slot::kKeyRowReadA, Slot::kKeyRowReadB,
        Slot::kPoisonLaneA, Slot::kPoisonLaneB,
    };
    aWarmUpLanes = {
        Slot::kPoisonLaneC, Slot::kPoisonLaneD,
    };
    aDestinations = {
        Slot::kFireLaneA, Slot::kFireLaneB,
        Slot::kFireLaneC, Slot::kFireLaneD,
    };
}

// [poi-a] x 1, [poi-b] x 1, [poi-c] x 0, [poi-d] x 0
// [ear-a] x 0, [ear-b] x 0, [ear-c] x 0, [ear-d] x 0

Twist_CConfig() {
    
    aInputs = {
        Slot::kFireLaneA, Slot::kFireLaneB,
        Slot::kFireLaneC, Slot::kFireLaneD,
    };
    aResiduals = {
        Slot::kSource, Slot::kKeyRowReadA, Slot::kKeyRowReadB,
        
        Slot::kEarthLaneA, Slot::kEarthLaneB,
        Slot::kEarthLaneC, Slot::kEarthLaneD,
        
        Slot::kPoisonLaneA, Slot::kPoisonLaneB,
        Slot::kPoisonLaneC, Slot::kPoisonLaneD,
    };
    aWarmUpLanes = {
        Slot::kWoodLaneA, Slot::kWoodLaneB,
    };
    aDestinations = {
        Slot::kFuseLaneA, Slot::kFuseLaneB,
        Slot::kFuseLaneC, Slot::kFuseLaneD,
    };
}

// [poi-a] x 2, [poi-b] x 2, [poi-c] x 1, [poi-d] x 1
// [ear-a] x 1, [ear-b] x 1, [ear-c] x 1, [ear-d] x 1
// [fir-a] x 0, [fir-b] x 0, [fir-c] x 0, [fir-d] x 0

// Here we diffuse [fuse] through [fire] to [wind]

Twist_DConfig() {
    
    aInputs = {
        Slot::kWindLaneA, Slot::kWindLaneB,
        Slot::kWindLaneC, Slot::kWindLaneD,
    };

    aResiduals = {
        Slot::kSource, Slot::kKeyRowReadA, Slot::kKeyRowReadB,
        
        Slot::kEarthLaneA, Slot::kEarthLaneB,
        Slot::kEarthLaneC, Slot::kEarthLaneD,
        
        Slot::kPoisonLaneA, Slot::kPoisonLaneB,
        Slot::kPoisonLaneC, Slot::kPoisonLaneD,
        
        Slot::kFireLaneA, Slot::kFireLaneB,
        Slot::kFireLaneC, Slot::kFireLaneD,
        
        Slot::kWoodLaneA, Slot::kWoodLaneB,
    };
    aWarmUpLanes = {
        Slot::kSpiritLaneA, Slot::kSpiritLaneB,
    };
    aDestinations = {
        Slot::kWaterLaneA, Slot::kWaterLaneB,
        Slot::kWaterLaneC, Slot::kWaterLaneD,
    };
}

// [poi-a] x 3, [poi-b] x 3, [poi-c] x 2, [poi-d] x 2
// [ear-a] x 2, [ear-b] x 2, [ear-c] x 2, [ear-d] x 2
// [fir-a] x 1, [fir-b] x 1, [fir-c] x 1, [fir-d] x 1
// [win-a] x 0, [win-b] x 0, [win-c] x 0, [win-d] x 0
// [spi-a] x 0, [spi-b] x 0, [spi-c] x 0, [spi-d] x 0

Twist_EConfig() {
    
    aInputs = {
        Slot::kWaterLaneA, Slot::kWaterLaneB,
        Slot::kWaterLaneC, Slot::kWaterLaneD,
    };

    aResiduals = {
        Slot::kSource, Slot::kKeyRowReadA, Slot::kKeyRowReadB,
        
        Slot::kWindLaneA, Slot::kWindLaneB,
        Slot::kWindLaneC, Slot::kWindLaneD,
        
        Slot::kEarthLaneA, Slot::kEarthLaneB,
        Slot::kEarthLaneC, Slot::kEarthLaneD,
        
        Slot::kWoodLaneA, Slot::kWoodLaneB,
        Slot::kPoisonLaneC, Slot::kPoisonLaneD,
        
        Slot::kFireLaneA, Slot::kFireLaneB,
        Slot::kFireLaneC, Slot::kFireLaneD,
    };
    aWarmUpLanes = {
        Slot::kFuseLaneA, Slot::kFuseLaneB,
    };
    aDestinations = {
        Slot::kHeartLaneA, Slot::kHeartLaneB,
        Slot::kHeartLaneC, Slot::kHeartLaneD,
    };
}

GrowAConfig() {
    
    aInputs = {
        Slot::kHeartLaneA, Slot::kHeartLaneB,
        Slot::kHeartLaneC, Slot::kHeartLaneD,
    };
    
    aResiduals = {
        Slot::kWindLaneA, Slot::kWindLaneB,
        Slot::kWaterLaneA, Slot::kWaterLaneB,
        Slot::kFireLaneC, Slot::kFireLaneD,
        Slot::kPoisonLaneA, Slot::kPoisonLaneB,
        Slot::kEarthLaneC,Slot::kEarthLaneD,
        Slot::kPoisonLaneC, Slot::kPoisonLaneD,
        Slot::kSpiritLaneA, Slot::kSpiritLaneB,
        Slot::kSpiritLaneC, Slot::kSpiritLaneD,
    };
    
    aDestinations = {
        Slot::kIceLaneA, Slot::kIceLaneB,
        Slot::kIceLaneC, Slot::kIceLaneD,
    };
}

GrowBConfig() {
    
    aInputs = {
        Slot::kIceLaneA, Slot::kIceLaneB,
        Slot::kIceLaneC, Slot::kIceLaneD,
    };
    
    aResiduals = {
        Slot::kKeyRowReadA, Slot::kKeyRowReadB,
        Slot::kWindLaneC, Slot::kWindLaneD,
        Slot::kEarthLaneA,Slot::kEarthLaneB,
        Slot::kWaterLaneC, Slot::kWaterLaneD,
        Slot::kFireLaneA, Slot::kFireLaneB,
        Slot::kHeartLaneA, Slot::kHeartLaneB,
        Slot::kHeartLaneC, Slot::kHeartLaneD,
        Slot::kWoodLaneA, Slot::kWoodLaneB,
    };
    
    aDestinations = {
        Slot::kSpiritLaneA, Slot::kSpiritLaneB,
        Slot::kSpiritLaneC, Slot::kSpiritLaneD,
    };
}
