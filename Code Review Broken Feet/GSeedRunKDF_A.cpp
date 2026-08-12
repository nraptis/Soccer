
KDFStageConfigs MakeKDF_AConfig(ResidualBucket &pResidualBucket,
                                const std::size_t pCandidateIndex) {
    using Slot = TwistWorkSpaceSlot;
    KDFStageConfigs aConfigs;
    std::vector<Slot> aResidualsPool;
    
    // Lane Plan
    
    //
    // KDF A — Stage A
    //
    const GPassFactoryStarter::SlotArray2 aPrimarySourcesA = {
        Slot::kSourceLane,
        Slot::kNonceLane,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsA = {
        Slot::kWaterLaneA, Slot::kWaterLaneB,
        Slot::kWaterLaneC, Slot::kWaterLaneD,
    };
    
    pResidualBucket.Remove(GPassFactoryMidstage::ToVector(aPrimarySourcesA));
    pResidualBucket.Remove(GPassFactoryMidstage::ToVector(aDestinationsA));
    
    //
    // KDF A — Stage B
    //
    const GPassFactoryMidstage::SlotArray4 aPrimarySourcesB = {
        Slot::kWaterLaneA, Slot::kWaterLaneB,
        Slot::kWaterLaneC, Slot::kWaterLaneD,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsB = {
        Slot::kSpiritLaneA, Slot::kSpiritLaneB,
        Slot::kSpiritLaneC, Slot::kSpiritLaneD,
    };
    
    pResidualBucket.Remove(GPassFactoryMidstage::ToVector(aPrimarySourcesB));
    pResidualBucket.Remove(GPassFactoryMidstage::ToVector(aDestinationsB));
    
    const GPassFactoryMidstage::SlotArray2 aResidualsB = {
        Slot::kSourceLane,
        Slot::kNonceLane,
    };
    
    pResidualBucket.AddResiduals("KDF A — Stage B", {
        Slot::kWaterLaneA, Slot::kWaterLaneB,
        Slot::kWaterLaneC, Slot::kWaterLaneD,
    });
    
    //
    // Matrix diffusion: Spirit lanes -> Earth lanes.
    // Entropy: Water lanes.
    //
    pResidualBucket.AddResiduals("KDF A — After diffusion", {
        Slot::kSpiritLaneA, Slot::kSpiritLaneB,
        Slot::kSpiritLaneC, Slot::kSpiritLaneD,
    });
    
    //
    // KDF A — Stage C
    //
    const GPassFactoryMidstage::SlotArray4 aPrimarySourcesC = {
        Slot::kEarthLaneA, Slot::kEarthLaneB,
        Slot::kEarthLaneC, Slot::kEarthLaneD,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsC = {
        Slot::kIceLaneA, Slot::kIceLaneB,
        Slot::kIceLaneC, Slot::kIceLaneD,
    };
    
    pResidualBucket.Remove(GPassFactoryMidstage::ToVector(aPrimarySourcesC));
    pResidualBucket.Remove(GPassFactoryMidstage::ToVector(aDestinationsC));
    
    aResidualsPool = pResidualBucket.Withdraw("KDF A — Stage C", 8);
    
    const GPassFactoryMidstage::SlotArray10 aResidualsC = {
        Slot::kSourceLane,
        Slot::kNonceLane,
        aResidualsPool[0], aResidualsPool[1],
        aResidualsPool[2], aResidualsPool[3],
        aResidualsPool[4], aResidualsPool[5],
        aResidualsPool[6], aResidualsPool[7],
    };
    
    pResidualBucket.AddResiduals("KDF A — Stage C", {
        Slot::kEarthLaneA, Slot::kEarthLaneB,
        Slot::kEarthLaneC, Slot::kEarthLaneD,
    });
    
}
