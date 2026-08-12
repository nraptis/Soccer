

KDFStageConfigs MakeKDF_CConfig(ResidualBucket &pResidualBucket,
                                const std::size_t pCandidateIndex) {
    using Slot = TwistWorkSpaceSlot;

    KDFStageConfigs aConfigs;
    std::vector<Slot> aResidualsPool;

    // Lane Plan

    //
    // KDF C — Stage A
    //
    const GPassFactoryMidstage::SlotArray4 aPrimarySourcesA = {
        Slot::kVaporLaneA, Slot::kVaporLaneB,
        Slot::kVaporLaneC, Slot::kVaporLaneD,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsA = {
        Slot::kPlasmaLaneA, Slot::kPlasmaLaneB,
        Slot::kPlasmaLaneC, Slot::kPlasmaLaneD,
    };

    pResidualBucket.Remove(GPassFactoryMidstage::ToVector(aPrimarySourcesA));
    pResidualBucket.Remove(GPassFactoryMidstage::ToVector(aDestinationsA));

    aResidualsPool = pResidualBucket.Withdraw("KDF C — Stage A", 15);

    const GPassFactoryMidstage::SlotArray16 aResidualsA = {
        Slot::kSourceLane,
        aResidualsPool[0], aResidualsPool[1],
        aResidualsPool[2], aResidualsPool[3],
        aResidualsPool[4], aResidualsPool[5],
        aResidualsPool[6], aResidualsPool[7],
        aResidualsPool[8], aResidualsPool[9],
        aResidualsPool[10], aResidualsPool[11],
        aResidualsPool[12], aResidualsPool[13],
        aResidualsPool[14],
    };

    pResidualBucket.AddResiduals("KDF C — Stage A", {
        Slot::kVaporLaneA, Slot::kVaporLaneB,
        Slot::kVaporLaneC, Slot::kVaporLaneD,
    });

    //
    // KDF C — Stage B
    //
    const GPassFactoryMidstage::SlotArray4 aPrimarySourcesB = {
        Slot::kPlasmaLaneA, Slot::kPlasmaLaneB,
        Slot::kPlasmaLaneC, Slot::kPlasmaLaneD,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsB = {
        Slot::kAetherLaneA, Slot::kAetherLaneB,
        Slot::kAetherLaneC, Slot::kAetherLaneD,
    };

    pResidualBucket.Remove(GPassFactoryMidstage::ToVector(aPrimarySourcesB));
    pResidualBucket.Remove(GPassFactoryMidstage::ToVector(aDestinationsB));

    aResidualsPool = pResidualBucket.Withdraw("KDF C — Stage B", 15);

    const GPassFactoryMidstage::SlotArray16 aResidualsB = {
        Slot::kSourceLane,
        aResidualsPool[0], aResidualsPool[1],
        aResidualsPool[2], aResidualsPool[3],
        aResidualsPool[4], aResidualsPool[5],
        aResidualsPool[6], aResidualsPool[7],
        aResidualsPool[8], aResidualsPool[9],
        aResidualsPool[10], aResidualsPool[11],
        aResidualsPool[12], aResidualsPool[13],
        aResidualsPool[14],
    };

    pResidualBucket.AddResiduals("KDF C — Stage B", {
        Slot::kPlasmaLaneA, Slot::kPlasmaLaneB,
        Slot::kPlasmaLaneC, Slot::kPlasmaLaneD,
    });

    //
    // Matrix diffusion: Aether lanes -> Shadow lanes.
    // Entropy: Plasma lanes.
    //
    pResidualBucket.AddResiduals("KDF C — After diffusion", {
        Slot::kAetherLaneA, Slot::kAetherLaneB,
        Slot::kAetherLaneC, Slot::kAetherLaneD,
    });

    //
    // KDF C — Stage C
    //
    const GPassFactoryMidstage::SlotArray4 aPrimarySourcesC = {
        Slot::kShadowLaneA, Slot::kShadowLaneB,
        Slot::kShadowLaneC, Slot::kShadowLaneD,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsC = {
        Slot::kCelestialLaneA, Slot::kCelestialLaneB,
        Slot::kCelestialLaneC, Slot::kCelestialLaneD,
    };

    pResidualBucket.Remove(GPassFactoryMidstage::ToVector(aPrimarySourcesC));
    pResidualBucket.Remove(GPassFactoryMidstage::ToVector(aDestinationsC));

    aResidualsPool = pResidualBucket.Withdraw("KDF C — Stage C", 15);

    const GPassFactoryMidstage::SlotArray16 aResidualsC = {
        Slot::kSourceLane,
        aResidualsPool[0], aResidualsPool[1],
        aResidualsPool[2], aResidualsPool[3],
        aResidualsPool[4], aResidualsPool[5],
        aResidualsPool[6], aResidualsPool[7],
        aResidualsPool[8], aResidualsPool[9],
        aResidualsPool[10], aResidualsPool[11],
        aResidualsPool[12], aResidualsPool[13],
        aResidualsPool[14],
    };

    pResidualBucket.AddResiduals("KDF C — Stage C", {
        Slot::kShadowLaneA,
        Slot::kShadowLaneB,
        Slot::kShadowLaneC,
        Slot::kShadowLaneD,
    });

}
