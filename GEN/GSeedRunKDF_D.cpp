
//
// KDF D — Stage A
//
const GPassFactory::SlotArray4 aPrimarySourcesA = {
    Slot::kCrystalLaneA,
    Slot::kCrystalLaneB,
    Slot::kCrystalLaneC,
    Slot::kCrystalLaneD,
};
const GPassFactory::SlotArray4 aDestinationsA = {
    Slot::kAetherLaneA,
    Slot::kAetherLaneB,
    Slot::kAetherLaneC,
    Slot::kAetherLaneD,
};

pResidualBucket.Remove(GPassFactory::ToVector(aPrimarySourcesA));
pResidualBucket.Remove(GPassFactory::ToVector(aDestinationsA));

printf("at KDF D — Stage A, there were %zu residuals available\n",
       pResidualBucket.CountValidResiduals());

aResidualsPool = pResidualBucket.Withdraw("KDF D — Stage A", 14);

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

pResidualBucket.AddResiduals("KDF D — Stage A", {
    Slot::kCrystalLaneA,
    Slot::kCrystalLaneB,
    Slot::kCrystalLaneC,
    Slot::kCrystalLaneD,
});

//
// KDF D — Stage B
//
const GPassFactory::SlotArray4 aPrimarySourcesB = {
    Slot::kAetherLaneA,
    Slot::kAetherLaneB,
    Slot::kAetherLaneC,
    Slot::kAetherLaneD,
};
const GPassFactory::SlotArray4 aDestinationsB = {
    Slot::kCelestialLaneA,
    Slot::kCelestialLaneB,
    Slot::kCelestialLaneC,
    Slot::kCelestialLaneD,
};

pResidualBucket.Remove(GPassFactory::ToVector(aPrimarySourcesB));
pResidualBucket.Remove(GPassFactory::ToVector(aDestinationsB));

printf("at KDF D — Stage B, there were %zu residuals available\n",
       pResidualBucket.CountValidResiduals());

aResidualsPool = pResidualBucket.Withdraw("KDF D — Stage B", 14);

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

pResidualBucket.AddResiduals("KDF D — Stage B", {
    Slot::kAetherLaneA,
    Slot::kAetherLaneB,
    Slot::kAetherLaneC,
    Slot::kAetherLaneD,
});

//
// KDF D — Stage C
//
const GPassFactory::SlotArray4 aPrimarySourcesC = {
    Slot::kCelestialLaneA,
    Slot::kCelestialLaneB,
    Slot::kCelestialLaneC,
    Slot::kCelestialLaneD,
};
const GPassFactory::SlotArray4 aDestinationsC = {
    Slot::kFuseLaneA,
    Slot::kFuseLaneB,
    Slot::kFuseLaneC,
    Slot::kFuseLaneD,
};

pResidualBucket.Remove(GPassFactory::ToVector(aPrimarySourcesC));
pResidualBucket.Remove(GPassFactory::ToVector(aDestinationsC));

printf("at KDF D — Stage C, there were %zu residuals available\n",
       pResidualBucket.CountValidResiduals());

aResidualsPool = pResidualBucket.Withdraw("KDF D — Stage C", 14);

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

pResidualBucket.AddResiduals("KDF D — Stage C", {
    Slot::kCelestialLaneA,
    Slot::kCelestialLaneB,
    Slot::kCelestialLaneC,
    Slot::kCelestialLaneD,
});

/*
TwistDiffuse::DiffuseWithDomainWords(
            aFuseLaneA, aFuseLaneB, aFuseLaneC, aFuseLaneD,  // input lanes
            aVaporLaneA, aVaporLaneB, aVaporLaneC, aVaporLaneD, // output lanes
            aAetherLaneC, aAetherLaneD, aCelestialLaneC, aCelestialLaneD, // index shuffle seeds
            aCelestialLaneA, aCelestialLaneB); // operation seeds
*/

//
// KDF D — Stage D
//
const GPassFactory::SlotArray4 aPrimarySourcesD = {
    Slot::kVaporLaneA,
    Slot::kVaporLaneB,
    Slot::kVaporLaneC,
    Slot::kVaporLaneD,
};
const GPassFactory::SlotArray4 aDestinationsD = {
    Slot::kPoisonLaneA,
    Slot::kPoisonLaneB,
    Slot::kPoisonLaneC,
    Slot::kPoisonLaneD,
};

pResidualBucket.Remove(GPassFactory::ToVector(aPrimarySourcesD));
pResidualBucket.Remove(GPassFactory::ToVector(aDestinationsD));

printf("at KDF D — Stage D, there were %zu residuals available\n",
       pResidualBucket.CountValidResiduals());

aResidualsPool = pResidualBucket.Withdraw("KDF D — Stage D", 14);

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

pResidualBucket.AddResiduals("KDF D — Stage D", {
    Slot::kVaporLaneA,
    Slot::kVaporLaneB,
    Slot::kVaporLaneC,
    Slot::kVaporLaneD,
});

