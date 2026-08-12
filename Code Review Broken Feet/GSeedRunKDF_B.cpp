
KDFStageConfigs MakeKDF_BConfig(ResidualBucket &pResidualBucket,
                                const std::size_t pCandidateIndex) {
    using Slot = TwistWorkSpaceSlot;

    KDFStageConfigs aConfigs;
    std::vector<Slot> aResidualsPool;

    // Lane Plan

    //
    // KDF B — Stage A
    //
    const GPassFactoryMidstage::SlotArray4 aPrimarySourcesA = {
        Slot::kIceLaneA, Slot::kIceLaneB,
        Slot::kIceLaneC, Slot::kIceLaneD,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsA = {
        Slot::kCrystalLaneA, Slot::kCrystalLaneB,
        Slot::kCrystalLaneC, Slot::kCrystalLaneD,
    };

    pResidualBucket.Remove(GPassFactoryMidstage::ToVector(aPrimarySourcesA));
    pResidualBucket.Remove(GPassFactoryMidstage::ToVector(aDestinationsA));

    aResidualsPool = pResidualBucket.Withdraw("KDF B — Stage A", 12);

    const GPassFactoryMidstage::SlotArray13 aResidualsA = {
        Slot::kSourceLane,
        aResidualsPool[0], aResidualsPool[1],
        aResidualsPool[2], aResidualsPool[3],
        aResidualsPool[4], aResidualsPool[5],
        aResidualsPool[6], aResidualsPool[7],
        aResidualsPool[8], aResidualsPool[9],
        aResidualsPool[10], aResidualsPool[11],
    };

    pResidualBucket.AddResiduals("KDF B — Stage A", {
        Slot::kIceLaneA, Slot::kIceLaneB,
        Slot::kIceLaneC, Slot::kIceLaneD,
    });

    //
    // KDF B — Stage B
    //
    const GPassFactoryMidstage::SlotArray4 aPrimarySourcesB = {
        Slot::kCrystalLaneA, Slot::kCrystalLaneB,
        Slot::kCrystalLaneC, Slot::kCrystalLaneD,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsB = {
        Slot::kLightningLaneA,
        Slot::kLightningLaneB,
        Slot::kLightningLaneC,
        Slot::kLightningLaneD,
    };

    pResidualBucket.Remove(GPassFactoryMidstage::ToVector(aPrimarySourcesB));
    pResidualBucket.Remove(GPassFactoryMidstage::ToVector(aDestinationsB));

    aResidualsPool = pResidualBucket.Withdraw("KDF B — Stage B", 15);

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

    pResidualBucket.AddResiduals("KDF B — Stage B", {
        Slot::kCrystalLaneA, Slot::kCrystalLaneB,
        Slot::kCrystalLaneC, Slot::kCrystalLaneD,
    });

    //
    // Matrix diffusion: Lightning lanes -> Wind lanes.
    // Entropy: Crystal lanes.
    //
    pResidualBucket.AddResiduals("KDF B — After diffusion", {
        Slot::kLightningLaneA, Slot::kLightningLaneB,
        Slot::kLightningLaneC, Slot::kLightningLaneD,
    });

    //
    // KDF B — Stage C
    //
    const GPassFactoryMidstage::SlotArray4 aPrimarySourcesC = {
        Slot::kWindLaneA, Slot::kWindLaneB,
        Slot::kWindLaneC, Slot::kWindLaneD,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsC = {
        Slot::kVaporLaneA, Slot::kVaporLaneB,
        Slot::kVaporLaneC, Slot::kVaporLaneD,
    };

    pResidualBucket.Remove(GPassFactoryMidstage::ToVector(aPrimarySourcesC));
    pResidualBucket.Remove(GPassFactoryMidstage::ToVector(aDestinationsC));

    aResidualsPool = pResidualBucket.Withdraw("KDF B — Stage C", 15);

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

    pResidualBucket.AddResiduals("KDF B — Stage C", {
        Slot::kWindLaneA, Slot::kWindLaneB,
        Slot::kWindLaneC, Slot::kWindLaneD,
    });

}

} // namespace GSeedRunKDF_BConfig
