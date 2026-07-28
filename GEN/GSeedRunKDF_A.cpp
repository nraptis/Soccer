

KDFStageConfigs aConfigs;
std::vector<Slot> aResidualsPool;

//
// KDF A — Stage A
//
const GPassFactory::SlotArray2 aPrimarySourcesA = {
    Slot::kSource, Slot::kParamSnow,
};
const GPassFactory::SlotArray2 aWarmUpLanesA = {
    Slot::kFireLaneA, Slot::kFireLaneB,
};
const GPassFactory::SlotArray4 aDestinationsA = {
    Slot::kEarthLaneA, Slot::kEarthLaneB,
    Slot::kEarthLaneC, Slot::kEarthLaneD,
};
const GPassFactory::SlotArray6 aExpectedDestinationsA =
    GPassFactory::Concat(aWarmUpLanesA, aDestinationsA);

pResidualBucket.Remove(GPassFactory::ToVector(aPrimarySourcesA));
pResidualBucket.Remove(GPassFactory::ToVector(aExpectedDestinationsA));

printf("at KDF A — Stage A, there were %zu residuals available\n",
       pResidualBucket.CountValidResiduals());

pResidualBucket.Withdraw("KDF A — Stage A", 0);

pResidualBucket.AddResiduals("KDF A — Stage A", {
    Slot::kFireLaneA, Slot::kFireLaneB,
});

//
// KDF A — Stage B
//
const GPassFactory::SlotArray4 aPrimarySourcesB = {
    Slot::kEarthLaneA, Slot::kEarthLaneB,
    Slot::kEarthLaneC, Slot::kEarthLaneD,
};
const GPassFactory::SlotArray2 aWarmUpLanesB = {
    Slot::kFireLaneC, Slot::kFireLaneD,
};
const GPassFactory::SlotArray4 aDestinationsB = {
    Slot::kWindLaneA, Slot::kWindLaneB,
    Slot::kWindLaneC, Slot::kWindLaneD,
};
const GPassFactory::SlotArray6 aExpectedDestinationsB =
    GPassFactory::Concat(aWarmUpLanesB, aDestinationsB);

pResidualBucket.Remove(GPassFactory::ToVector(aPrimarySourcesB));
pResidualBucket.Remove(GPassFactory::ToVector(aExpectedDestinationsB));

printf("at KDF A — Stage B, there were %zu residuals available\n",
       pResidualBucket.CountValidResiduals());

aResidualsPool = pResidualBucket.Withdraw("KDF A — Stage B", 2);

const GPassFactory::SlotArray4 aResidualsB = {
    Slot::kSource, Slot::kParamSnow,
    aResidualsPool[0], aResidualsPool[1],
};

pResidualBucket.AddResiduals("KDF A — Stage B", {
    Slot::kEarthLaneA, Slot::kEarthLaneB,
    Slot::kEarthLaneC, Slot::kEarthLaneD,
    Slot::kFireLaneC, Slot::kFireLaneD,
});

//
// KDF A — Stage C
//
const GPassFactory::SlotArray4 aPrimarySourcesC = {
    Slot::kWindLaneA, Slot::kWindLaneB,
    Slot::kWindLaneC, Slot::kWindLaneD,
};
const GPassFactory::SlotArray4 aDestinationsC = {
    Slot::kFuseLaneA, Slot::kFuseLaneB,
    Slot::kFuseLaneC, Slot::kFuseLaneD,
};

pResidualBucket.Remove(GPassFactory::ToVector(aPrimarySourcesC));
pResidualBucket.Remove(GPassFactory::ToVector(aDestinationsC));

printf("at KDF A — Stage C, there were %zu residuals available\n",
       pResidualBucket.CountValidResiduals());

aResidualsPool = pResidualBucket.Withdraw("KDF A — Stage C", 8);

const GPassFactory::SlotArray10 aResidualsC = {
    Slot::kSource, Slot::kParamSnow,
    aResidualsPool[0], aResidualsPool[1],
    aResidualsPool[2], aResidualsPool[3],
    aResidualsPool[4], aResidualsPool[5],
    aResidualsPool[6], aResidualsPool[7],
};

pResidualBucket.AddResiduals("KDF A — Stage C", {
    Slot::kWindLaneA, Slot::kWindLaneB,
    Slot::kWindLaneC, Slot::kWindLaneD,
});

/*
TwistDiffuse::DiffuseWithDomainWords(
                aFuseLaneA, aFuseLaneB, aFuseLaneC, aFuseLaneD,  // input lanes
                aWaterLaneA, aWaterLaneB, aWaterLaneC, aWaterLaneD, // output lanes
                aFireLaneC, aFireLaneD, aWindLaneC, aWindLaneD, // index shuffle seeds
                aWindLaneA, aWindLaneB); // operation seeds
*/

//
// KDF A — Stage D
//
const GPassFactory::SlotArray4 aPrimarySourcesD = {
    Slot::kWaterLaneA, Slot::kWaterLaneB,
    Slot::kWaterLaneC, Slot::kWaterLaneD,
};
const GPassFactory::SlotArray4 aDestinationsD = {
    Slot::kHeartLaneA, Slot::kHeartLaneB,
    Slot::kHeartLaneC, Slot::kHeartLaneD,
};

pResidualBucket.Remove(GPassFactory::ToVector(aPrimarySourcesD));
pResidualBucket.Remove(GPassFactory::ToVector(aDestinationsD));

printf("at KDF A — Stage D, there were %zu residuals available\n",
       pResidualBucket.CountValidResiduals());

aResidualsPool = pResidualBucket.Withdraw("KDF A — Stage D", 12);

const GPassFactory::SlotArray14 aResidualsD = {
    Slot::kSource, Slot::kParamSnow,
    aResidualsPool[0], aResidualsPool[1],
    aResidualsPool[2], aResidualsPool[3],
    aResidualsPool[4], aResidualsPool[5],
    aResidualsPool[6], aResidualsPool[7],
    aResidualsPool[8], aResidualsPool[9],
    aResidualsPool[10], aResidualsPool[11],
};

pResidualBucket.AddResiduals("KDF A — Stage D", {
    Slot::kWaterLaneA, Slot::kWaterLaneB,
    Slot::kWaterLaneC, Slot::kWaterLaneD,
});
