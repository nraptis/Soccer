Seed_AConfig(()) {
    
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

Seed_BConfig(()) {
    
    aPrimarySources = {
        Slot::kEarthLaneA, Slot::kEarthLaneB,
        Slot::kEarthLaneC, Slot::kEarthLaneD,
    };
    aResidualSources = {
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

Seed_CConfig(()) {
    
    aPrimarySources = {
        Slot::kFireLaneA, Slot::kFireLaneB,
        Slot::kFireLaneC, Slot::kFireLaneD,
    };
    aResidualSources = {
        Slot::kSource, Slot::kKeyRowReadA, Slot::kKeyRowReadB,
        
        Slot::kEarthLaneA, Slot::kEarthLaneB,
        Slot::kEarthLaneC, Slot::kEarthLaneD,
        
        Slot::kPoisonLaneA, Slot::kPoisonLaneB,
        Slot::kPoisonLaneC, Slot::kPoisonLaneD,
    };
    aPrefixDestinations = {
        Slot::kHeartLaneA, Slot::kHeartLaneB,
    };
    aBodyDestinations = {
        Slot::kFuseLaneA, Slot::kFuseLaneB,
        Slot::kFuseLaneC, Slot::kFuseLaneD,
    };
}

// [poi-a] x 2, [poi-b] x 2, [poi-c] x 1, [poi-d] x 1
// [ear-a] x 1, [ear-b] x 1, [ear-c] x 1, [ear-d] x 1
// [fir-a] x 0, [fir-b] x 0, [fir-c] x 0, [fir-d] x 0
// [ice-a] x 0, [ice-b] x 0, [ice-c] x 0, [ice-d] x 0

// Here we diffuse [fuse] through [fire] to [wind]

Seed_DConfig(()) {
    
    aPrimarySources = {
        Slot::kWindLaneA, Slot::kWindLaneB,
        Slot::kWindLaneC, Slot::kWindLaneD,
    };
    aResidualSources = {
        Slot::kSource, Slot::kKeyRowReadA, Slot::kKeyRowReadB,
        
        Slot::kEarthLaneA, Slot::kEarthLaneB,
        Slot::kEarthLaneC, Slot::kEarthLaneD,
        
        Slot::kPoisonLaneA, Slot::kPoisonLaneB,
        Slot::kPoisonLaneC, Slot::kPoisonLaneD,
        
        Slot::kFireLaneA, Slot::kFireLaneB,
        Slot::kFireLaneC, Slot::kFireLaneD,
        
        Slot::kHeartLaneA, Slot::kHeartLaneB,
    };
    aPrefixDestinations = {
        Slot::kHeartLaneC, Slot::kHeartLaneD,
    };
    aBodyDestinations = {
        Slot::kWaterLaneA, Slot::kWaterLaneB,
        Slot::kWaterLaneC, Slot::kWaterLaneD,
    };
}

// [poi-a] x 3, [poi-b] x 3, [poi-c] x 2, [poi-d] x 2
// [ear-a] x 2, [ear-b] x 2, [ear-c] x 2, [ear-d] x 2
// [fir-a] x 1, [fir-b] x 1, [fir-c] x 1, [fir-d] x 1
// [ice-a] x 1, [ice-b] x 1, [ice-c] x 0, [ice-d] x 0
// [win-a] x 0, [win-b] x 0, [win-c] x 0, [win-d] x 0

Seed_EConfig(()) {
    
    aPrimarySources = {
        Slot::kWaterLaneA, Slot::kWaterLaneB,
        Slot::kWaterLaneC, Slot::kWaterLaneD,
    };
    aResidualSources = {
        Slot::kSource, Slot::kKeyRowReadA, Slot::kKeyRowReadB,
        
        Slot::kWindLaneA, Slot::kWindLaneB,
        Slot::kWindLaneC, Slot::kWindLaneD,
        
        Slot::kEarthLaneA, Slot::kEarthLaneB,
        Slot::kEarthLaneC, Slot::kEarthLaneD,
        
        Slot::kPoisonLaneA, Slot::kPoisonLaneB,
        Slot::kPoisonLaneC, Slot::kPoisonLaneD,
        
        Slot::kFireLaneA, Slot::kFireLaneB,
        Slot::kFireLaneC, Slot::kFireLaneD,
        
        Slot::kHeartLaneA, Slot::kHeartLaneB,
        Slot::kHeartLaneC, Slot::kHeartLaneD,
    };
    aPrefixDestinations = {
        Slot::kWoodLaneA, Slot::kWoodLaneB,
    };
    aBodyDestinations = {
        Slot::kIceLaneA, Slot::kIceLaneB,
        Slot::kIceLaneC, Slot::kIceLaneD,
    };
}

// [poi-a] x 4, [poi-b] x 4, [poi-c] x 3, [poi-d] x 3
// [ear-a] x 3, [ear-b] x 3, [ear-c] x 3, [ear-d] x 3
// [fir-a] x 2, [fir-b] x 2, [fir-c] x 2, [fir-d] x 2
// [ice-a] x 2, [ice-b] x 2, [ice-c] x 1, [ice-d] x 1
// [win-a] x 1, [win-b] x 1, [win-c] x 1, [win-d] x 1
// [wat-a] x 0, [wat-b] x 0, [wat-c] x 0, [wat-d] x 0
// [wod-a] x 0, [wod-b] x 0

Seed_FConfig(()) {
    
    aPrimarySources = {
        Slot::kIceLaneA, Slot::kIceLaneB,
        Slot::kIceLaneC, Slot::kIceLaneD,
    };
    aResidualSources = {
        Slot::kSource, Slot::kKeyRowReadA, Slot::kKeyRowReadB,
        Slot::kEarthLaneB, Slot::kEarthLaneC, Slot::kEarthLaneD,
        
        Slot::kWindLaneA, Slot::kWindLaneB,
        Slot::kWindLaneC, Slot::kWindLaneD,
        
        Slot::kFireLaneA, Slot::kFireLaneB,
        Slot::kFireLaneC, Slot::kFireLaneD,
        Slot::kHeartLaneA, Slot::kHeartLaneB,
        Slot::kHeartLaneC, Slot::kHeartLaneD,
        
        Slot::kWaterLaneA, Slot::kWaterLaneB,
        Slot::kWaterLaneC, Slot::kWaterLaneD,
        
        Slot::kWoodLaneA, Slot::kWoodLaneB,
    };
    
    aPrefixDestinations = {
        Slot::kWoodLaneC, Slot::kWoodLaneD,
    };
    aBodyDestinations = {
        Slot::kFuseLaneA, Slot::kFuseLaneB,
        Slot::kFuseLaneC, Slot::kFuseLaneD,
    };
}

// [ear-a] x 3, [ear-b] x 4, [ear-c] x 4, [ear-d] x 4
// [fir-a] x 3, [fir-b] x 3, [fir-c] x 3, [fir-d] x 3
// [ice-a] x 3, [ice-b] x 3, [ice-c] x 2, [ice-d] x 2
// [win-a] x 2, [win-b] x 2, [win-c] x 2, [win-d] x 2
// [wat-a] x 1, [wat-b] x 1, [wat-c] x 1, [wat-d] x 1
// [wod-a] x 1, [wod-b] x 1, [wod-c] x 0, [wod-d] x 0
// [hrt-a] x 0, [hrt-b] x 0, [hrt-c] x 0, [hrt-d] x 0,

// Here we diffuse [fuse] through [heart] to [spirit]

Seed_GConfig(()) {
    
    aPrimarySources = {
        Slot::kSpiritLaneA, Slot::kSpiritLaneB,
        Slot::kSpiritLaneC, Slot::kSpiritLaneD,
    };
    aResidualSources = {
        Slot::kSource, Slot::kKeyRowReadA, Slot::kKeyRowReadB,
        Slot::kEarthLaneA,
        
        Slot::kWindLaneA, Slot::kWindLaneB,
        Slot::kWindLaneC, Slot::kWindLaneD,
        
        Slot::kHeartLaneA, Slot::kHeartLaneB,
        Slot::kHeartLaneC, Slot::kHeartLaneD,
        
        Slot::kIceLaneA, Slot::kIceLaneB,
        Slot::kIceLaneC, Slot::kIceLaneD,
        
        Slot::kWaterLaneA, Slot::kWaterLaneB,
        Slot::kWaterLaneC, Slot::kWaterLaneD,
        
        Slot::kWoodLaneA, Slot::kWoodLaneB,
        Slot::kWoodLaneC, Slot::kWoodLaneD,
    };
    
    aPrefixDestinations = {
        Slot::kEarthLaneC, Slot::kEarthLaneD,
    };
    aBodyDestinations = {
        Slot::kFireLaneA, Slot::kFireLaneB,
        Slot::kFireLaneC, Slot::kFireLaneD,
    };
}

// [poi-a] x 4, [poi-b] x 4, [poi-c] x 3, [poi-d] x 3
// [ear-a] x 4, [ear-b] x 4, [ear-c] x 0, [ear-d] x 0
// [fir-a] x 0, [fir-b] x 0, [fir-c] x 0, [fir-d] x 0
// [ice-a] x 4, [ice-b] x 4, [ice-c] x 3, [ice-d] x 3
// [win-a] x 3, [win-b] x 3, [win-c] x 3, [win-d] x 3
// [wat-a] x 2, [wat-b] x 2, [wat-c] x 2, [wat-d] x 2
// [wod-a] x 2, [wod-b] x 2, [wod-c] x 1, [wod-d] x 1
// [hrt-a] x 1, [hrt-b] x 1, [hrt-c] x 1, [hrt-d] x 1
// [spi-a] x 0, [spi-b] x 0, [spi-c] x 0, [spi-d] x 0

Seed_HConfig(()) {
    aPrimarySources = {
        Slot::kFireLaneA, Slot::kFireLaneB,
        Slot::kFireLaneC, Slot::kFireLaneD,
    };
    aResidualSources = {
        Slot::kKeyRowReadA, Slot::kKeyRowReadB,
        Slot::kPoisonLaneC, Slot::kPoisonLaneD,
        
        Slot::kWindLaneA, Slot::kWindLaneB,
        Slot::kWindLaneC, Slot::kWindLaneD,
        
        Slot::kIceLaneA, Slot::kIceLaneB,
        Slot::kIceLaneC, Slot::kIceLaneD,
        Slot::kWaterLaneA, Slot::kWaterLaneB,
        Slot::kWaterLaneC, Slot::kWaterLaneD,
        
        Slot::kWoodLaneA, Slot::kWoodLaneB,
        Slot::kWoodLaneC, Slot::kWoodLaneD,
        Slot::kSpiritLaneA, Slot::kSpiritLaneB,
        Slot::kSpiritLaneC, Slot::kSpiritLaneD,
    };
    aPrefixDestinations = {
        Slot::kEarthLaneC, Slot::kEarthLaneD,
    };
    aBodyDestinations = {
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
