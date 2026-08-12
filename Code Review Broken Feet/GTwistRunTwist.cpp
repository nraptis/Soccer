
TwistStageConfigs MakeTwistConfig(ResidualBucket &pResidualBucket,
                                  const std::size_t pCandidateIndex) {
    using Slot = TwistWorkSpaceSlot;

    TwistStageConfigs aConfigs;
    std::vector<Slot> aResidualsPool;

    // Lane Plan

    //
    // Twist — Stage A
    // Source and key rows become Water A-D.
    //
    const GPassFactoryMidstage::SlotArray3 aPrimarySourcesA = {
        Slot::kSourceLane, Slot::kKeyRowReadA, Slot::kKeyRowReadB,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsA = {
        Slot::kWaterLaneA, Slot::kWaterLaneB,
        Slot::kWaterLaneC, Slot::kWaterLaneD,
    };
    const GPassFactoryMidstage::SlotArray4 aResidualsA = {
        Slot::kParamCrossA, Slot::kParamCrossB,
        Slot::kParamCrossC, Slot::kParamCrossD,
    };

    pResidualBucket.Remove(
        GPassFactoryMidstage::ToVector(aPrimarySourcesA));
    pResidualBucket.Remove(
        GPassFactoryMidstage::ToVector(aDestinationsA));

    //
    // Matrix diffusion: Water A-D -> Spirit A-D.
    // Entropy: Cross A-D.
    //

    pResidualBucket.AddResiduals("Twist — Stage A", {
        Slot::kWaterLaneA, Slot::kWaterLaneB,
        Slot::kWaterLaneC, Slot::kWaterLaneD,
        Slot::kSourceLane,
        Slot::kKeyRowReadA, Slot::kKeyRowReadB,
    });

    //
    // Twist — Stage B
    //
    const GPassFactoryMidstage::SlotArray4 aPrimarySourcesB = {
        Slot::kSpiritLaneA, Slot::kSpiritLaneB,
        Slot::kSpiritLaneC, Slot::kSpiritLaneD,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsB = {
        Slot::kEarthLaneA, Slot::kEarthLaneB,
        Slot::kEarthLaneC, Slot::kEarthLaneD,
    };

    pResidualBucket.Remove(
        GPassFactoryMidstage::ToVector(aPrimarySourcesB));
    pResidualBucket.Remove(
        GPassFactoryMidstage::ToVector(aDestinationsB));

    aResidualsPool =
        pResidualBucket.Withdraw("Twist — Stage B", 7);
    const GPassFactoryMidstage::SlotArray7 aResidualsB = {
        aResidualsPool[0], aResidualsPool[1],
        aResidualsPool[2], aResidualsPool[3],
        aResidualsPool[4], aResidualsPool[5],
        aResidualsPool[6],
    };

    pResidualBucket.AddResiduals("Twist — Stage B", {
        Slot::kSpiritLaneA, Slot::kSpiritLaneB,
        Slot::kSpiritLaneC, Slot::kSpiritLaneD,
    });

    //
    // Matrix diffusion: Earth A-D -> Ice A-D.
    // Entropy: Spirit A-D.
    //

    pResidualBucket.AddResiduals("Twist — After second diffusion", {
        Slot::kEarthLaneA, Slot::kEarthLaneB,
        Slot::kEarthLaneC, Slot::kEarthLaneD,
    });

    //
    // Twist — Stage C
    //
    const GPassFactoryMidstage::SlotArray4 aPrimarySourcesC = {
        Slot::kIceLaneA, Slot::kIceLaneB,
        Slot::kIceLaneC, Slot::kIceLaneD,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsC = {
        Slot::kCrystalLaneA, Slot::kCrystalLaneB,
        Slot::kCrystalLaneC, Slot::kCrystalLaneD,
    };

    pResidualBucket.Remove(
        GPassFactoryMidstage::ToVector(aPrimarySourcesC));
    pResidualBucket.Remove(
        GPassFactoryMidstage::ToVector(aDestinationsC));

    aResidualsPool =
        pResidualBucket.Withdraw("Twist — Stage C", 15);
    const GPassFactoryMidstage::SlotArray15 aResidualsC = {
        aResidualsPool[0], aResidualsPool[1],
        aResidualsPool[2], aResidualsPool[3],
        aResidualsPool[4], aResidualsPool[5],
        aResidualsPool[6], aResidualsPool[7],
        aResidualsPool[8], aResidualsPool[9],
        aResidualsPool[10], aResidualsPool[11],
        aResidualsPool[12], aResidualsPool[13],
        aResidualsPool[14],
    };

    pResidualBucket.AddResiduals("Twist — Stage C", {
        Slot::kIceLaneA, Slot::kIceLaneB,
        Slot::kIceLaneC, Slot::kIceLaneD,
    });
    pResidualBucket.Print("Twist — Final");
    
}
