

KDFStageConfigs aConfigs;
std::vector<Slot> aResidualsPool;

//
// KDF B — Stage A
//
const GPassFactory::SlotArray4 aPrimarySourcesA = {
    Slot::kHeartLaneA,
    Slot::kHeartLaneB,
    Slot::kHeartLaneC,
    Slot::kHeartLaneD,
};
const GPassFactory::SlotArray4 aDestinationsA = {
    Slot::kSoilLaneA,
    Slot::kSoilLaneB,
    Slot::kSoilLaneC,
    Slot::kSoilLaneD,
};

pResidualBucket.Remove(GPassFactory::ToVector(aPrimarySourcesA));
pResidualBucket.Remove(GPassFactory::ToVector(aDestinationsA));

printf("at KDF B — Stage A, there were %zu residuals available\n",
       pResidualBucket.CountValidResiduals());

aResidualsPool = pResidualBucket.Withdraw("KDF B — Stage A", 14);

const GPassFactory::SlotArray16 aResidualsA = {
    Slot::kSource, Slot::kParamSnow,
    aResidualsPool[0], aResidualsPool[1],
    aResidualsPool[2], aResidualsPool[3],
    aResidualsPool[4], aResidualsPool[5],
    aResidualsPool[6], aResidualsPool[7],
    aResidualsPool[8], aResidualsPool[9],
    aResidualsPool[10], aResidualsPool[11],
    aResidualsPool[12], aResidualsPool[13],
};

pResidualBucket.AddResiduals("KDF B — Stage A", {
    Slot::kHeartLaneA,
    Slot::kHeartLaneB,
    Slot::kHeartLaneC,
    Slot::kHeartLaneD,
});

//
// KDF B — Stage B
//
const GPassFactory::SlotArray4 aPrimarySourcesB = {
    Slot::kSoilLaneA,
    Slot::kSoilLaneB,
    Slot::kSoilLaneC,
    Slot::kSoilLaneD,
};
const GPassFactory::SlotArray4 aDestinationsB = {
    Slot::kLightningLaneA,
    Slot::kLightningLaneB,
    Slot::kLightningLaneC,
    Slot::kLightningLaneD,
};

pResidualBucket.Remove(GPassFactory::ToVector(aPrimarySourcesB));
pResidualBucket.Remove(GPassFactory::ToVector(aDestinationsB));

printf("at KDF B — Stage B, there were %zu residuals available\n",
       pResidualBucket.CountValidResiduals());

aResidualsPool = pResidualBucket.Withdraw("KDF B — Stage B", 14);

const GPassFactory::SlotArray16 aResidualsB = {
    Slot::kSource, Slot::kParamSnow,
    aResidualsPool[0], aResidualsPool[1],
    aResidualsPool[2], aResidualsPool[3],
    aResidualsPool[4], aResidualsPool[5],
    aResidualsPool[6], aResidualsPool[7],
    aResidualsPool[8], aResidualsPool[9],
    aResidualsPool[10], aResidualsPool[11],
    aResidualsPool[12], aResidualsPool[13],
};

pResidualBucket.AddResiduals("KDF B — Stage B", {
    Slot::kSoilLaneA,
    Slot::kSoilLaneB,
    Slot::kSoilLaneC,
    Slot::kSoilLaneD,
});

//
// KDF B — Stage C
//
const GPassFactory::SlotArray4 aPrimarySourcesC = {
    Slot::kLightningLaneA,
    Slot::kLightningLaneB,
    Slot::kLightningLaneC,
    Slot::kLightningLaneD,
};
const GPassFactory::SlotArray4 aDestinationsC = {
    Slot::kFuseLaneA,
    Slot::kFuseLaneB,
    Slot::kFuseLaneC,
    Slot::kFuseLaneD,
};

pResidualBucket.Remove(GPassFactory::ToVector(aPrimarySourcesC));
pResidualBucket.Remove(GPassFactory::ToVector(aDestinationsC));

printf("at KDF B — Stage C, there were %zu residuals available\n",
       pResidualBucket.CountValidResiduals());

aResidualsPool = pResidualBucket.Withdraw("KDF B — Stage C", 14);

const GPassFactory::SlotArray16 aResidualsC = {
    Slot::kSource, Slot::kParamSnow,
    aResidualsPool[0], aResidualsPool[1],
    aResidualsPool[2], aResidualsPool[3],
    aResidualsPool[4], aResidualsPool[5],
    aResidualsPool[6], aResidualsPool[7],
    aResidualsPool[8], aResidualsPool[9],
    aResidualsPool[10], aResidualsPool[11],
    aResidualsPool[12], aResidualsPool[13],
};

pResidualBucket.AddResiduals("KDF B — Stage C", {
    Slot::kLightningLaneA,
    Slot::kLightningLaneB,
    Slot::kLightningLaneC,
    Slot::kLightningLaneD,
});

//
// Matrix diffusion: Fuse lanes -> Ice lanes
//

//
// KDF B — Stage D
//
const GPassFactory::SlotArray4 aPrimarySourcesD = {
    Slot::kIceLaneA,
    Slot::kIceLaneB,
    Slot::kIceLaneC,
    Slot::kIceLaneD,
};
const GPassFactory::SlotArray4 aDestinationsD = {
    Slot::kWoodLaneA,
    Slot::kWoodLaneB,
    Slot::kWoodLaneC,
    Slot::kWoodLaneD,
};

pResidualBucket.Remove(GPassFactory::ToVector(aPrimarySourcesD));
pResidualBucket.Remove(GPassFactory::ToVector(aDestinationsD));

printf("at KDF B — Stage D, there were %zu residuals available\n",
       pResidualBucket.CountValidResiduals());

aResidualsPool = pResidualBucket.Withdraw("KDF B — Stage D", 14);

const GPassFactory::SlotArray16 aResidualsD = {
    Slot::kSource, Slot::kParamSnow,
    aResidualsPool[0], aResidualsPool[1],
    aResidualsPool[2], aResidualsPool[3],
    aResidualsPool[4], aResidualsPool[5],
    aResidualsPool[6], aResidualsPool[7],
    aResidualsPool[8], aResidualsPool[9],
    aResidualsPool[10], aResidualsPool[11],
    aResidualsPool[12], aResidualsPool[13],
};

pResidualBucket.AddResiduals("KDF B — Stage D", {
    Slot::kIceLaneA,
    Slot::kIceLaneB,
    Slot::kIceLaneC,
    Slot::kIceLaneD,
});
