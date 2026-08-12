
SeedStageConfigs MakeSeedConfig(const bool pUseNonces,
                                ResidualBucket &pResidualBucket,
                                const std::size_t pCandidateIndex) {
    SeedStageConfigs aConfigs;

    // Lane Plan

    //
    // Seed — Stage A
    // Source + Nonce -> Water A-B + Spirit A-D.
    //
    const GPassFactoryStarter::SlotArray2 aPrimarySourcesA = {
        Slot::kSourceLane, Slot::kNonceLane,
    };
    const GPassFactoryMidstage::SlotArray2 aWarmUpLanesA = {
        Slot::kWaterLaneA, Slot::kWaterLaneB,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsA = {
        Slot::kSpiritLaneA, Slot::kSpiritLaneB,
        Slot::kSpiritLaneC, Slot::kSpiritLaneD,
    };
    const GPassFactoryMidstage::SlotArray6 aExpectedDestinationsA =
        GPassFactoryMidstage::Concat(aWarmUpLanesA, aDestinationsA);

    pResidualBucket.Remove(
        GPassFactoryMidstage::ToVector(aPrimarySourcesA));
    pResidualBucket.Remove(
        GPassFactoryMidstage::ToVector(aExpectedDestinationsA));
    pResidualBucket.Withdraw("Seed — Stage A", 0);
    pResidualBucket.AddResiduals("Seed — Stage A", {
        Slot::kSourceLane, Slot::kNonceLane,
        Slot::kWaterLaneA, Slot::kWaterLaneB,
    });

    //
    // Seed — Stage B
    // Spirit A-D -> Water C-D + Earth A-D.
    //
    const GPassFactoryMidstage::SlotArray4 aPrimarySourcesB = {
        Slot::kSpiritLaneA, Slot::kSpiritLaneB,
        Slot::kSpiritLaneC, Slot::kSpiritLaneD,
    };
    const GPassFactoryMidstage::SlotArray2 aWarmUpLanesB = {
        Slot::kWaterLaneC, Slot::kWaterLaneD,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsB = {
        Slot::kEarthLaneA, Slot::kEarthLaneB,
        Slot::kEarthLaneC, Slot::kEarthLaneD,
    };
    const GPassFactoryMidstage::SlotArray6 aExpectedDestinationsB =
        GPassFactoryMidstage::Concat(aWarmUpLanesB, aDestinationsB);

    pResidualBucket.Remove(
        GPassFactoryMidstage::ToVector(aPrimarySourcesB));
    pResidualBucket.Remove(
        GPassFactoryMidstage::ToVector(aExpectedDestinationsB));
    const GPassFactoryMidstage::SlotArray24 aResidualsB =
        WithdrawResiduals<24U>(pResidualBucket, "Seed — Stage B");
    pResidualBucket.AddResiduals("Seed — Stage B", {
        Slot::kSpiritLaneA, Slot::kSpiritLaneB,
        Slot::kSpiritLaneC, Slot::kSpiritLaneD,
        Slot::kWaterLaneC, Slot::kWaterLaneD,
        Slot::kEarthLaneA, Slot::kEarthLaneB,
        Slot::kEarthLaneC, Slot::kEarthLaneD,
    });

    // Matrix diffusion: Earth A-D -> Ice A-D.
    // Entropy: Water A-D.

    //
    // Seed — Stage C
    // Ice A-D -> Crystal A-B + Lightning A-D.
    //
    const GPassFactoryMidstage::SlotArray4 aPrimarySourcesC = {
        Slot::kIceLaneA, Slot::kIceLaneB,
        Slot::kIceLaneC, Slot::kIceLaneD,
    };
    const GPassFactoryMidstage::SlotArray2 aWarmUpLanesC = {
        Slot::kCrystalLaneA, Slot::kCrystalLaneB,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsC = {
        Slot::kLightningLaneA, Slot::kLightningLaneB,
        Slot::kLightningLaneC, Slot::kLightningLaneD,
    };
    const GPassFactoryMidstage::SlotArray6 aExpectedDestinationsC =
        GPassFactoryMidstage::Concat(aWarmUpLanesC, aDestinationsC);

    pResidualBucket.Remove(
        GPassFactoryMidstage::ToVector(aPrimarySourcesC));
    pResidualBucket.Remove(
        GPassFactoryMidstage::ToVector(aExpectedDestinationsC));
    const GPassFactoryMidstage::SlotArray24 aResidualsC =
        WithdrawResiduals<24U>(pResidualBucket, "Seed — Stage C");
    pResidualBucket.AddResiduals("Seed — Stage C", {
        Slot::kIceLaneA, Slot::kIceLaneB,
        Slot::kIceLaneC, Slot::kIceLaneD,
        Slot::kCrystalLaneA, Slot::kCrystalLaneB,
    });

    //
    // Seed — Stage D
    // Lightning A-D -> Crystal C-D + Wind A-D.
    //
    const GPassFactoryMidstage::SlotArray4 aPrimarySourcesD = {
        Slot::kLightningLaneA, Slot::kLightningLaneB,
        Slot::kLightningLaneC, Slot::kLightningLaneD,
    };
    const GPassFactoryMidstage::SlotArray2 aWarmUpLanesD = {
        Slot::kCrystalLaneC, Slot::kCrystalLaneD,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsD = {
        Slot::kWindLaneA, Slot::kWindLaneB,
        Slot::kWindLaneC, Slot::kWindLaneD,
    };
    const GPassFactoryMidstage::SlotArray6 aExpectedDestinationsD =
        GPassFactoryMidstage::Concat(aWarmUpLanesD, aDestinationsD);

    pResidualBucket.Remove(
        GPassFactoryMidstage::ToVector(aPrimarySourcesD));
    pResidualBucket.Remove(
        GPassFactoryMidstage::ToVector(aExpectedDestinationsD));
    const GPassFactoryMidstage::SlotArray24 aResidualsD =
        WithdrawResiduals<24U>(pResidualBucket, "Seed — Stage D");
    pResidualBucket.AddResiduals("Seed — Stage D", {
        Slot::kLightningLaneA, Slot::kLightningLaneB,
        Slot::kLightningLaneC, Slot::kLightningLaneD,
        Slot::kCrystalLaneC, Slot::kCrystalLaneD,
        Slot::kWindLaneA, Slot::kWindLaneB,
        Slot::kWindLaneC, Slot::kWindLaneD,
    });

    // Matrix diffusion: Wind A-D -> Vapor A-D.
    // Entropy: Crystal A-D.

    //
    // Seed — Stage E
    // Vapor A-D -> Plasma A-B + Aether A-D.
    //
    const GPassFactoryMidstage::SlotArray4 aPrimarySourcesE = {
        Slot::kVaporLaneA, Slot::kVaporLaneB,
        Slot::kVaporLaneC, Slot::kVaporLaneD,
    };
    const GPassFactoryMidstage::SlotArray2 aWarmUpLanesE = {
        Slot::kPlasmaLaneA, Slot::kPlasmaLaneB,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsE = {
        Slot::kAetherLaneA, Slot::kAetherLaneB,
        Slot::kAetherLaneC, Slot::kAetherLaneD,
    };
    const GPassFactoryMidstage::SlotArray6 aExpectedDestinationsE =
        GPassFactoryMidstage::Concat(aWarmUpLanesE, aDestinationsE);

    pResidualBucket.Remove(
        GPassFactoryMidstage::ToVector(aPrimarySourcesE));
    pResidualBucket.Remove(
        GPassFactoryMidstage::ToVector(aExpectedDestinationsE));
    const GPassFactoryMidstage::SlotArray24 aResidualsE =
        WithdrawResiduals<24U>(pResidualBucket, "Seed — Stage E");
    pResidualBucket.AddResiduals("Seed — Stage E", {
        Slot::kVaporLaneA, Slot::kVaporLaneB,
        Slot::kVaporLaneC, Slot::kVaporLaneD,
        Slot::kPlasmaLaneA, Slot::kPlasmaLaneB,
    });

    //
    // Seed — Stage F
    // Aether A-D -> Plasma C-D + Shadow A-D.
    //
    const GPassFactoryMidstage::SlotArray4 aPrimarySourcesF = {
        Slot::kAetherLaneA, Slot::kAetherLaneB,
        Slot::kAetherLaneC, Slot::kAetherLaneD,
    };
    const GPassFactoryMidstage::SlotArray2 aWarmUpLanesF = {
        Slot::kPlasmaLaneC, Slot::kPlasmaLaneD,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsF = {
        Slot::kShadowLaneA, Slot::kShadowLaneB,
        Slot::kShadowLaneC, Slot::kShadowLaneD,
    };
    const GPassFactoryMidstage::SlotArray6 aExpectedDestinationsF =
        GPassFactoryMidstage::Concat(aWarmUpLanesF, aDestinationsF);

    pResidualBucket.Remove(
        GPassFactoryMidstage::ToVector(aPrimarySourcesF));
    pResidualBucket.Remove(
        GPassFactoryMidstage::ToVector(aExpectedDestinationsF));
    const GPassFactoryMidstage::SlotArray24 aResidualsF =
        WithdrawResiduals<24U>(pResidualBucket, "Seed — Stage F");
    pResidualBucket.AddResiduals("Seed — Stage F", {
        Slot::kAetherLaneA, Slot::kAetherLaneB,
        Slot::kAetherLaneC, Slot::kAetherLaneD,
        Slot::kPlasmaLaneC, Slot::kPlasmaLaneD,
        Slot::kShadowLaneA, Slot::kShadowLaneB,
        Slot::kShadowLaneC, Slot::kShadowLaneD,
    });

    // Matrix diffusion: Shadow A-D -> Celestial A-D.
    // Entropy: Plasma A-D.

    //
    // Seed — Stage G
    // Celestial A-D -> Lightning A-D.
    //
    const GPassFactoryMidstage::SlotArray4 aPrimarySourcesG = {
        Slot::kCelestialLaneA, Slot::kCelestialLaneB,
        Slot::kCelestialLaneC, Slot::kCelestialLaneD,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsG = {
        Slot::kLightningLaneA, Slot::kLightningLaneB,
        Slot::kLightningLaneC, Slot::kLightningLaneD,
    };

    pResidualBucket.Remove(
        GPassFactoryMidstage::ToVector(aPrimarySourcesG));
    pResidualBucket.Remove(
        GPassFactoryMidstage::ToVector(aDestinationsG));
    const GPassFactoryMidstage::SlotArray16 aResidualsG =
        WithdrawResiduals<16U>(pResidualBucket, "Seed — Stage G");
    pResidualBucket.AddResiduals("Seed — Stage G", {
        Slot::kCelestialLaneA, Slot::kCelestialLaneB,
        Slot::kCelestialLaneC, Slot::kCelestialLaneD,
    });

    //
    // Seed — Stage H
    // Lightning A-D -> Water A-D.
    //
    const GPassFactoryMidstage::SlotArray4 aPrimarySourcesH = {
        Slot::kLightningLaneA, Slot::kLightningLaneB,
        Slot::kLightningLaneC, Slot::kLightningLaneD,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsH = {
        Slot::kWaterLaneA, Slot::kWaterLaneB,
        Slot::kWaterLaneC, Slot::kWaterLaneD,
    };

    pResidualBucket.Remove(
        GPassFactoryMidstage::ToVector(aPrimarySourcesH));
    pResidualBucket.Remove(
        GPassFactoryMidstage::ToVector(aDestinationsH));
    const GPassFactoryMidstage::SlotArray16 aResidualsH =
        WithdrawResiduals<16U>(pResidualBucket, "Seed — Stage H");
    pResidualBucket.AddResiduals("Seed — Stage H", {
        Slot::kLightningLaneA, Slot::kLightningLaneB,
        Slot::kLightningLaneC, Slot::kLightningLaneD,
        Slot::kWaterLaneA, Slot::kWaterLaneB,
        Slot::kWaterLaneC, Slot::kWaterLaneD,
    });

    // Matrix diffusion: Water A-D -> Spirit A-D.
    // Entropy: Lightning A-D.

    //
    // Seed — Stage I
    // Spirit A-D -> Earth A-D.
    //
    const GPassFactoryMidstage::SlotArray4 aPrimarySourcesI = {
        Slot::kSpiritLaneA, Slot::kSpiritLaneB,
        Slot::kSpiritLaneC, Slot::kSpiritLaneD,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsI = {
        Slot::kEarthLaneA, Slot::kEarthLaneB,
        Slot::kEarthLaneC, Slot::kEarthLaneD,
    };

    pResidualBucket.Remove(
        GPassFactoryMidstage::ToVector(aPrimarySourcesI));
    pResidualBucket.Remove(
        GPassFactoryMidstage::ToVector(aDestinationsI));
    const GPassFactoryMidstage::SlotArray16 aResidualsI =
        WithdrawResiduals<16U>(pResidualBucket, "Seed — Stage I");
    pResidualBucket.AddResiduals("Seed — Stage I", {
        Slot::kSpiritLaneA, Slot::kSpiritLaneB,
        Slot::kSpiritLaneC, Slot::kSpiritLaneD,
        Slot::kEarthLaneA, Slot::kEarthLaneB,
        Slot::kEarthLaneC, Slot::kEarthLaneD,
    });

    // Matrix diffusion: Earth A-D -> Ice A-D.
    // Entropy: Spirit A-D.

    //
    // Seed — Stage J
    // Ice A-D -> Crystal A-D.
    //
    const GPassFactoryMidstage::SlotArray4 aPrimarySourcesJ = {
        Slot::kIceLaneA, Slot::kIceLaneB,
        Slot::kIceLaneC, Slot::kIceLaneD,
    };
    const GPassFactoryMidstage::SlotArray4 aDestinationsJ = {
        Slot::kCrystalLaneA, Slot::kCrystalLaneB,
        Slot::kCrystalLaneC, Slot::kCrystalLaneD,
    };

    pResidualBucket.Remove(
        GPassFactoryMidstage::ToVector(aPrimarySourcesJ));
    pResidualBucket.Remove(
        GPassFactoryMidstage::ToVector(aDestinationsJ));
    const GPassFactoryMidstage::SlotArray16 aResidualsJ =
        WithdrawResiduals<16U>(pResidualBucket, "Seed — Stage J");
    pResidualBucket.AddResiduals("Seed — Stage J", {
        Slot::kIceLaneA, Slot::kIceLaneB,
        Slot::kIceLaneC, Slot::kIceLaneD,
        Slot::kCrystalLaneA, Slot::kCrystalLaneB,
        Slot::kCrystalLaneC, Slot::kCrystalLaneD,
    });

    pResidualBucket.Print("Seed — Final");

}
