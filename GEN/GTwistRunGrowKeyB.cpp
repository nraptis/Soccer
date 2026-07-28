

//
// Grow B — Stage A
//
const GPassFactory::SlotArray4 aInputsA = {
    Slot::kAetherLaneA, Slot::kAetherLaneB,
    Slot::kAetherLaneC, Slot::kAetherLaneD,
};
const GPassFactory::SlotArray2 aWarmUpLanesA = {
    Slot::kKineticLaneA, Slot::kKineticLaneB,
};
const GPassFactory::SlotArray4 aDestinationsA = {
    Slot::kSpiritLaneA, Slot::kSpiritLaneB,
    Slot::kSpiritLaneC, Slot::kSpiritLaneD,
};
const GPassFactory::SlotArray6 aExpectedDestinationsA =
    GPassFactory::Concat(aWarmUpLanesA,
                         aDestinationsA);

pResidualBucket.Remove(GPassFactory::ToVector(aInputsA));
pResidualBucket.Remove(
    GPassFactory::ToVector(aExpectedDestinationsA));

aResidualsPool =
    pResidualBucket.Withdraw("Grow B — Stage A", 24 - 2);

const GPassFactory::SlotArray24 aResidualsA = {
    Slot::kKeyRowReadA, Slot::kKeyRowReadB,
    aResidualsPool[0], aResidualsPool[1],
    aResidualsPool[2], aResidualsPool[3],
    aResidualsPool[4], aResidualsPool[5],
    aResidualsPool[6], aResidualsPool[7],
    aResidualsPool[8], aResidualsPool[9],
    aResidualsPool[10], aResidualsPool[11],
    aResidualsPool[12], aResidualsPool[13],
    aResidualsPool[14], aResidualsPool[15],
    aResidualsPool[16], aResidualsPool[17],
    aResidualsPool[18], aResidualsPool[19],
    aResidualsPool[20], aResidualsPool[21],
};

pResidualBucket.AddResiduals("Grow B — Stage A", {
    Slot::kAetherLaneA, Slot::kAetherLaneB,
    Slot::kAetherLaneC, Slot::kAetherLaneD,
    Slot::kKineticLaneA, Slot::kKineticLaneB,
});

GSeedRunStageConfig aConfigA = BaseConfig("GROW_B_A",
                                          "grow_b_loop_a");
aConfigA.mFormat = GAXSFormat::kN7;
aConfigA.mSlices =
    GPassFactory::SixPassTwentyFourResidualSlices(
        aInputsA,
        aResidualsA,
        aExpectedDestinationsA);
aConfigA.mExpectedSkeletonCount =
    static_cast<int>(aExpectedDestinationsA.size());
aConfigA.mHotPackCount =
    static_cast<int>(aExpectedDestinationsA.size());

std::string aErrorMessageA;
if (!GSeedRunStageConfigValidator::ValidateMidstage(
        aConfigA,
        GPassFactory::ToVector(aInputsA),
        GPassFactory::ToVector(aResidualsA),
        GPassFactory::ToVector(aExpectedDestinationsA),
        &aErrorMessageA)) {
    printf("MakeGrowBConfig stage A was not valid with ValidateMidstage");
    printf("%s\n", aErrorMessageA.c_str());
    exit(0);
}
aConfigs[0] = aConfigA;

//
// Grow B — Stage B
//
const GPassFactory::SlotArray4 aInputsB = {
    Slot::kSpiritLaneA, Slot::kSpiritLaneB,
    Slot::kSpiritLaneC, Slot::kSpiritLaneD,
};
const GPassFactory::SlotArray2 aWarmUpLanesB = {
    Slot::kKineticLaneC, Slot::kKineticLaneD,
};
const GPassFactory::SlotArray4 aDestinationsB = {
    Slot::kCelestialLaneA, Slot::kCelestialLaneB,
    Slot::kCelestialLaneC, Slot::kCelestialLaneD,
};
const GPassFactory::SlotArray6 aExpectedDestinationsB =
    GPassFactory::Concat(aWarmUpLanesB,
                         aDestinationsB);

pResidualBucket.Remove(GPassFactory::ToVector(aInputsB));
pResidualBucket.Remove(
    GPassFactory::ToVector(aExpectedDestinationsB));

aResidualsPool =
    pResidualBucket.Withdraw("Grow B — Stage B", 24 - 2);

const GPassFactory::SlotArray24 aResidualsB = {
    Slot::kKeyRowReadA, Slot::kKeyRowReadB,
    aResidualsPool[0], aResidualsPool[1],
    aResidualsPool[2], aResidualsPool[3],
    aResidualsPool[4], aResidualsPool[5],
    aResidualsPool[6], aResidualsPool[7],
    aResidualsPool[8], aResidualsPool[9],
    aResidualsPool[10], aResidualsPool[11],
    aResidualsPool[12], aResidualsPool[13],
    aResidualsPool[14], aResidualsPool[15],
    aResidualsPool[16], aResidualsPool[17],
    aResidualsPool[18], aResidualsPool[19],
    aResidualsPool[20], aResidualsPool[21],
};

pResidualBucket.AddResiduals("Grow B — Stage B", {
    Slot::kSpiritLaneA, Slot::kSpiritLaneB,
    Slot::kSpiritLaneC, Slot::kSpiritLaneD,
    Slot::kKineticLaneC, Slot::kKineticLaneD,
});

GSeedRunStageConfig aConfigB = BaseConfig("GROW_B_B",
                                          "grow_b_loop_b");
aConfigB.mFormat = GAXSFormat::kN9;
aConfigB.mSlices =
    GPassFactory::SixPassTwentyFourResidualSlices(
        aInputsB,
        aResidualsB,
        aExpectedDestinationsB);
aConfigB.mExpectedSkeletonCount =
    static_cast<int>(aExpectedDestinationsB.size());
aConfigB.mHotPackCount =
    static_cast<int>(aExpectedDestinationsB.size());

std::string aErrorMessageB;
if (!GSeedRunStageConfigValidator::ValidateMidstage(
        aConfigB,
        GPassFactory::ToVector(aInputsB),
        GPassFactory::ToVector(aResidualsB),
        GPassFactory::ToVector(aExpectedDestinationsB),
        &aErrorMessageB)) {
    printf("MakeGrowBConfig stage B was not valid with ValidateMidstage");
    printf("%s\n", aErrorMessageB.c_str());
    exit(0);
}
aConfigs[1] = aConfigB;

//
// Grow B — Stage C
//
const GPassFactory::SlotArray4 aInputsC = {
    Slot::kCelestialLaneA, Slot::kCelestialLaneB,
    Slot::kCelestialLaneC, Slot::kCelestialLaneD,
};
const GPassFactory::SlotArray4 aDestinationsC = {
    Slot::kFuseLaneA, Slot::kFuseLaneB,
    Slot::kFuseLaneC, Slot::kFuseLaneD,
};

pResidualBucket.Remove(GPassFactory::ToVector(aInputsC));
pResidualBucket.Remove(GPassFactory::ToVector(aDestinationsC));

aResidualsPool =
    pResidualBucket.Withdraw("Grow B — Stage C", 16);

const GPassFactory::SlotArray18 aResidualsC = {
    Slot::kKeyRowReadA, Slot::kKeyRowReadB,
    aResidualsPool[0], aResidualsPool[1],
    aResidualsPool[2], aResidualsPool[3],
    aResidualsPool[4], aResidualsPool[5],
    aResidualsPool[6], aResidualsPool[7],
    aResidualsPool[8], aResidualsPool[9],
    aResidualsPool[10], aResidualsPool[11],
    aResidualsPool[12], aResidualsPool[13],
    aResidualsPool[14], aResidualsPool[15],
};

pResidualBucket.AddResiduals("Grow B — Stage C", {
    Slot::kCelestialLaneA, Slot::kCelestialLaneB,
    Slot::kCelestialLaneC, Slot::kCelestialLaneD,
});

GSeedRunStageConfig aConfigC = BaseConfig("GROW_B_C",
                                          "grow_b_loop_c");
aConfigC.mFormat = GAXSFormat::kN11;
aConfigC.mSlices =
    GPassFactory::FourPassEighteenResidualSlices(aInputsC,
                                                 aResidualsC,
                                                 aDestinationsC);
aConfigC.mExpectedSkeletonCount =
    static_cast<int>(aDestinationsC.size());
aConfigC.mHotPackCount =
    static_cast<int>(aDestinationsC.size());

std::string aErrorMessageC;
if (!GSeedRunStageConfigValidator::ValidateMidstage(
        aConfigC,
        GPassFactory::ToVector(aInputsC),
        GPassFactory::ToVector(aResidualsC),
        GPassFactory::ToVector(aDestinationsC),
        &aErrorMessageC)) {
    printf("MakeGrowBConfig stage C was not valid with ValidateMidstage");
    printf("%s\n", aErrorMessageC.c_str());
    exit(0);
}
aConfigs[2] = aConfigC;

// Matrix diffusion:
//   Fuse A-D -> Chance A-D
// Previous six:
//   Kinetic C, Kinetic D, Celestial A-D

//
// Grow B — Stage D
//
const GPassFactory::SlotArray4 aInputsD = {
    Slot::kChanceLaneA, Slot::kChanceLaneB,
    Slot::kChanceLaneC, Slot::kChanceLaneD,
};
const GPassFactory::SlotArray4 aDestinationsD = {
    Slot::kCrystalLaneA, Slot::kCrystalLaneB,
    Slot::kCrystalLaneC, Slot::kCrystalLaneD,
};

pResidualBucket.Remove(GPassFactory::ToVector(aInputsD));
pResidualBucket.Remove(GPassFactory::ToVector(aDestinationsD));

aResidualsPool =
    pResidualBucket.Withdraw("Grow B — Stage D", 16);

const GPassFactory::SlotArray18 aResidualsD = {
    Slot::kKeyRowReadA, Slot::kKeyRowReadB,
    aResidualsPool[0], aResidualsPool[1],
    aResidualsPool[2], aResidualsPool[3],
    aResidualsPool[4], aResidualsPool[5],
    aResidualsPool[6], aResidualsPool[7],
    aResidualsPool[8], aResidualsPool[9],
    aResidualsPool[10], aResidualsPool[11],
    aResidualsPool[12], aResidualsPool[13],
    aResidualsPool[14], aResidualsPool[15],
};

pResidualBucket.AddResiduals("Grow B — Stage D", {
    Slot::kChanceLaneA, Slot::kChanceLaneB,
    Slot::kChanceLaneC, Slot::kChanceLaneD,
});

pResidualBucket.Print("Grow B — Final");

