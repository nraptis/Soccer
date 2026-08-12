
GrowStageConfigs MakeGrowAConfig(ResidualBucket &pResidualBucket,
                                 const std::size_t pCandidateIndex) {
    using Slot = TwistWorkSpaceSlot;

    GrowStageConfigs aConfigs;
    std::vector<Slot> aResidualsPool;

    // Lane Plan

    //
    // Grow A — Stage A
    //
    const GPassFactoryMidstage::SlotArray4 aInputsA = {
        Slot::kCrystalLaneA, Slot::kCrystalLaneB,
        Slot::kCrystalLaneC, Slot::kCrystalLaneD,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsA = {
        Slot::kLightningLaneA, Slot::kLightningLaneB,
        Slot::kLightningLaneC, Slot::kLightningLaneD,
    };

    pResidualBucket.Remove(GPassFactoryMidstage::ToVector(aInputsA));
    pResidualBucket.Remove(GPassFactoryMidstage::ToVector(aDestinationsA));

    aResidualsPool =
        pResidualBucket.Withdraw("Grow A — Stage A", 10);

    const GPassFactoryMidstage::SlotArray11 aResidualsA = {
        Slot::kKeyRowReadB,
        aResidualsPool[0], aResidualsPool[1],
        aResidualsPool[2], aResidualsPool[3],
        aResidualsPool[4], aResidualsPool[5],
        aResidualsPool[6], aResidualsPool[7],
        aResidualsPool[8], aResidualsPool[9],
    };

    pResidualBucket.AddResiduals("Grow A — Stage A", {
        Slot::kCrystalLaneA, Slot::kCrystalLaneB,
        Slot::kCrystalLaneC, Slot::kCrystalLaneD,
    });

    // Matrix diffusion:
    //   Lightning A-D -> Wind A-D
    // Entropy:
    //   Ice A-D, retained from Twist's second diffusion.

    //
    // Grow A — Stage B
    //
    const GPassFactoryMidstage::SlotArray4 aInputsB = {
        Slot::kWindLaneA, Slot::kWindLaneB,
        Slot::kWindLaneC, Slot::kWindLaneD,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsB = {
        Slot::kVaporLaneA, Slot::kVaporLaneB,
        Slot::kVaporLaneC, Slot::kVaporLaneD,
    };

    pResidualBucket.Remove(GPassFactoryMidstage::ToVector(aInputsB));
    pResidualBucket.Remove(GPassFactoryMidstage::ToVector(aDestinationsB));

    aResidualsPool =
        pResidualBucket.Withdraw("Grow A — Stage B", 12);

    const GPassFactoryMidstage::SlotArray13 aResidualsB = {
        Slot::kKeyRowReadB,
        aResidualsPool[0], aResidualsPool[1],
        aResidualsPool[2], aResidualsPool[3],
        aResidualsPool[4], aResidualsPool[5],
        aResidualsPool[6], aResidualsPool[7],
        aResidualsPool[8], aResidualsPool[9],
        aResidualsPool[10], aResidualsPool[11],
    };

    pResidualBucket.AddResiduals("Grow A — Stage B", {
        Slot::kWindLaneA, Slot::kWindLaneB,
        Slot::kWindLaneC, Slot::kWindLaneD,
    });

    pResidualBucket.Print("Grow A — Final");
    
}

