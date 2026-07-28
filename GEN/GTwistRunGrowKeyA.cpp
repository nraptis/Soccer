
//
// Grow A — Stage A
//
const GPassFactory::SlotArray4 aInputsA = {
    Slot::kPoisonLaneA, Slot::kPoisonLaneB,
    Slot::kPoisonLaneC, Slot::kPoisonLaneD,
};
const GPassFactory::SlotArray4 aDestinationsA = {
    Slot::kShadowLaneA, Slot::kShadowLaneB,
    Slot::kShadowLaneC, Slot::kShadowLaneD,
};

pResidualBucket.Remove(GPassFactory::ToVector(aInputsA));
pResidualBucket.Remove(GPassFactory::ToVector(aDestinationsA));

aResidualsPool =
    pResidualBucket.Withdraw("Grow A — Stage A", 16); // plus two fixed key rows

const GPassFactory::SlotArray18 aResidualsA = {
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

pResidualBucket.AddResiduals("Grow A — Stage A", {
    Slot::kPoisonLaneA, Slot::kPoisonLaneB,
    Slot::kPoisonLaneC, Slot::kPoisonLaneD,
});

GSeedRunStageConfig aConfigA = BaseConfig("GROW_A_A",
                                          "grow_a_loop_a");
aConfigA.mFormat = GAXSFormat::kN9;
aConfigA.mSlices =
    GPassFactory::FourPassEighteenResidualSlices(aInputsA,
                                                 aResidualsA,
                                                 aDestinationsA);
aConfigA.mExpectedSkeletonCount =
    static_cast<int>(aDestinationsA.size());
aConfigA.mHotPackCount =
    static_cast<int>(aDestinationsA.size());

std::string aErrorMessageA;
if (!GSeedRunStageConfigValidator::ValidateMidstage(
        aConfigA,
        GPassFactory::ToVector(aInputsA),
        GPassFactory::ToVector(aResidualsA),
        GPassFactory::ToVector(aDestinationsA),
        &aErrorMessageA)) {
    printf("MakeGrowAConfig stage A was not valid with ValidateMidstage");
    printf("%s\n", aErrorMessageA.c_str());
    exit(0);
}
aConfigs[0] = aConfigA;

//
// Grow A — Stage B
//
const GPassFactory::SlotArray4 aInputsB = {
    Slot::kShadowLaneA, Slot::kShadowLaneB,
    Slot::kShadowLaneC, Slot::kShadowLaneD,
};
const GPassFactory::SlotArray4 aDestinationsB = {
    Slot::kWindLaneA, Slot::kWindLaneB,
    Slot::kWindLaneC, Slot::kWindLaneD,
};

pResidualBucket.Remove(GPassFactory::ToVector(aInputsB));
pResidualBucket.Remove(GPassFactory::ToVector(aDestinationsB));

aResidualsPool =
    pResidualBucket.Withdraw("Grow A — Stage B", 16); // plus two fixed key rows

const GPassFactory::SlotArray18 aResidualsB = {
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

pResidualBucket.AddResiduals("Grow A — Stage B", {
    Slot::kShadowLaneA, Slot::kShadowLaneB,
    Slot::kShadowLaneC, Slot::kShadowLaneD,
});

GSeedRunStageConfig aConfigB = BaseConfig("GROW_A_B",
                                          "grow_a_loop_b");
aConfigB.mFormat = GAXSFormat::kN11;
aConfigB.mSlices =
    GPassFactory::FourPassEighteenResidualSlices(aInputsB,
                                                 aResidualsB,
                                                 aDestinationsB);
aConfigB.mExpectedSkeletonCount =
    static_cast<int>(aDestinationsB.size());
aConfigB.mHotPackCount =
    static_cast<int>(aDestinationsB.size());

std::string aErrorMessageB;
if (!GSeedRunStageConfigValidator::ValidateMidstage(
        aConfigB,
        GPassFactory::ToVector(aInputsB),
        GPassFactory::ToVector(aResidualsB),
        GPassFactory::ToVector(aDestinationsB),
        &aErrorMessageB)) {
    printf("MakeGrowAConfig stage B was not valid with ValidateMidstage");
    printf("%s\n", aErrorMessageB.c_str());
    exit(0);
}
aConfigs[1] = aConfigB;

//
// Grow A — Stage C
//
const GPassFactory::SlotArray4 aInputsC = {
    Slot::kWindLaneA, Slot::kWindLaneB,
    Slot::kWindLaneC, Slot::kWindLaneD,
};
const GPassFactory::SlotArray4 aDestinationsC = {
    Slot::kFuseLaneA, Slot::kFuseLaneB,
    Slot::kFuseLaneC, Slot::kFuseLaneD,
};

pResidualBucket.Remove(GPassFactory::ToVector(aInputsC));
pResidualBucket.Remove(GPassFactory::ToVector(aDestinationsC));

aResidualsPool =
    pResidualBucket.Withdraw("Grow A — Stage C", 16); // plus two fixed key rows

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

pResidualBucket.AddResiduals("Grow A — Stage C", {
    Slot::kWindLaneA, Slot::kWindLaneB,
    Slot::kWindLaneC, Slot::kWindLaneD,
});

GSeedRunStageConfig aConfigC = BaseConfig("GROW_A_C",
                                          "grow_a_loop_c");
aConfigC.mFormat = GAXSFormat::kN7;
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
    printf("MakeGrowAConfig stage C was not valid with ValidateMidstage");
    printf("%s\n", aErrorMessageC.c_str());
    exit(0);
}
aConfigs[2] = aConfigC;

// Matrix diffusion:
//   Fuse A-D -> Vapor A-D
// Previous six:
//   Shadow C, Shadow D, Wind A-D

//
// Grow A — Stage D
//
const GPassFactory::SlotArray4 aInputsD = {
    Slot::kVaporLaneA, Slot::kVaporLaneB,
    Slot::kVaporLaneC, Slot::kVaporLaneD,
};
const GPassFactory::SlotArray4 aDestinationsD = {
    Slot::kAetherLaneA, Slot::kAetherLaneB,
    Slot::kAetherLaneC, Slot::kAetherLaneD,
};

pResidualBucket.Remove(GPassFactory::ToVector(aInputsD));
pResidualBucket.Remove(GPassFactory::ToVector(aDestinationsD));

aResidualsPool =
    pResidualBucket.Withdraw("Grow A — Stage D", 16); // plus two fixed key rows

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

pResidualBucket.AddResiduals("Grow A — Stage D", {
    Slot::kVaporLaneA, Slot::kVaporLaneB,
    Slot::kVaporLaneC, Slot::kVaporLaneD,
});

pResidualBucket.Print("Grow A — Final");

