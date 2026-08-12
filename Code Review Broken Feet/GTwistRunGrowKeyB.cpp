
GrowStageConfigs MakeGrowBConfig(ResidualBucket &pResidualBucket,
                                 const std::size_t pCandidateIndex) {
    using Slot = TwistWorkSpaceSlot;

    GrowStageConfigs aConfigs;
    std::vector<Slot> aResidualsPool;

    // Lane Plan

    //
    // Grow B — Stage A
    //
    const GPassFactoryMidstage::SlotArray4 aInputsA = {
        Slot::kCrystalLaneA, Slot::kCrystalLaneB,
        Slot::kCrystalLaneC, Slot::kCrystalLaneD,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsA = {
        Slot::kPlasmaLaneA, Slot::kPlasmaLaneB,
        Slot::kPlasmaLaneC, Slot::kPlasmaLaneD,
    };

    pResidualBucket.Remove(GPassFactoryMidstage::ToVector(aInputsA));
    pResidualBucket.Remove(GPassFactoryMidstage::ToVector(aDestinationsA));

    aResidualsPool =
        pResidualBucket.Withdraw("Grow B — Stage A", 10);

    const GPassFactoryMidstage::SlotArray11 aResidualsA = {
        Slot::kKeyRowReadA,
        aResidualsPool[0], aResidualsPool[1],
        aResidualsPool[2], aResidualsPool[3],
        aResidualsPool[4], aResidualsPool[5],
        aResidualsPool[6], aResidualsPool[7],
        aResidualsPool[8], aResidualsPool[9],
    };

    pResidualBucket.AddResiduals("Grow B — Stage A", {
        Slot::kCrystalLaneA, Slot::kCrystalLaneB,
        Slot::kCrystalLaneC, Slot::kCrystalLaneD,
    });

    // Matrix diffusion:
    //   Plasma A-D -> Aether A-D
    // Entropy:
    //   Fire A-D, containing reversed copies of Twist's Ice A-D.

    //
    // Grow B — Stage B
    //
    const GPassFactoryMidstage::SlotArray4 aInputsB = {
        Slot::kAetherLaneA, Slot::kAetherLaneB,
        Slot::kAetherLaneC, Slot::kAetherLaneD,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsB = {
        Slot::kShadowLaneA, Slot::kShadowLaneB,
        Slot::kShadowLaneC, Slot::kShadowLaneD,
    };

    pResidualBucket.Remove(GPassFactoryMidstage::ToVector(aInputsB));
    pResidualBucket.Remove(GPassFactoryMidstage::ToVector(aDestinationsB));

    aResidualsPool =
        pResidualBucket.Withdraw("Grow B — Stage B", 12);

    const GPassFactoryMidstage::SlotArray13 aResidualsB = {
        Slot::kKeyRowReadA,
        aResidualsPool[0], aResidualsPool[1],
        aResidualsPool[2], aResidualsPool[3],
        aResidualsPool[4], aResidualsPool[5],
        aResidualsPool[6], aResidualsPool[7],
        aResidualsPool[8], aResidualsPool[9],
        aResidualsPool[10], aResidualsPool[11],
    };

    pResidualBucket.AddResiduals("Grow B — Stage B", {
        Slot::kAetherLaneA, Slot::kAetherLaneB,
        Slot::kAetherLaneC, Slot::kAetherLaneD,
    });

    pResidualBucket.Print("Grow B — Final");

}
