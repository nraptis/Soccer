
//
// KDF C — Stage A
//
const GPassFactory::SlotArray4 aPrimarySourcesA = {
    Slot::kWoodLaneA,
    Slot::kWoodLaneB,
    Slot::kWoodLaneC,
    Slot::kWoodLaneD,
};
const GPassFactory::SlotArray4 aDestinationsA = {
    Slot::kMagmaLaneA,
    Slot::kMagmaLaneB,
    Slot::kMagmaLaneC,
    Slot::kMagmaLaneD,
};

pResidualBucket.Remove(GPassFactory::ToVector(aPrimarySourcesA));
pResidualBucket.Remove(GPassFactory::ToVector(aDestinationsA));

printf("at KDF C — Stage A, there were %zu residuals available\n",
       pResidualBucket.CountValidResiduals());

aResidualsPool = pResidualBucket.Withdraw("KDF C — Stage A", 14);

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

pResidualBucket.AddResiduals("KDF C — Stage A", {
    Slot::kWoodLaneA,
    Slot::kWoodLaneB,
    Slot::kWoodLaneC,
    Slot::kWoodLaneD,
});

//
// KDF C — Stage B
//
const GPassFactory::SlotArray4 aPrimarySourcesB = {
    Slot::kMagmaLaneA,
    Slot::kMagmaLaneB,
    Slot::kMagmaLaneC,
    Slot::kMagmaLaneD,
};
const GPassFactory::SlotArray4 aDestinationsB = {
    Slot::kPlasmaLaneA,
    Slot::kPlasmaLaneB,
    Slot::kPlasmaLaneC,
    Slot::kPlasmaLaneD,
};

pResidualBucket.Remove(GPassFactory::ToVector(aPrimarySourcesB));
pResidualBucket.Remove(GPassFactory::ToVector(aDestinationsB));

printf("at KDF C — Stage B, there were %zu residuals available\n",
       pResidualBucket.CountValidResiduals());

aResidualsPool = pResidualBucket.Withdraw("KDF C — Stage B", 14);

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

pResidualBucket.AddResiduals("KDF C — Stage B", {
    Slot::kMagmaLaneA,
    Slot::kMagmaLaneB,
    Slot::kMagmaLaneC,
    Slot::kMagmaLaneD,
});

//
// KDF C — Stage C
//
const GPassFactory::SlotArray4 aPrimarySourcesC = {
    Slot::kPlasmaLaneA,
    Slot::kPlasmaLaneB,
    Slot::kPlasmaLaneC,
    Slot::kPlasmaLaneD,
};
const GPassFactory::SlotArray4 aDestinationsC = {
    Slot::kFuseLaneA,
    Slot::kFuseLaneB,
    Slot::kFuseLaneC,
    Slot::kFuseLaneD,
};

pResidualBucket.Remove(GPassFactory::ToVector(aPrimarySourcesC));
pResidualBucket.Remove(GPassFactory::ToVector(aDestinationsC));

printf("at KDF C — Stage C, there were %zu residuals available\n",
       pResidualBucket.CountValidResiduals());

aResidualsPool = pResidualBucket.Withdraw("KDF C — Stage C", 14);

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

pResidualBucket.AddResiduals("KDF C — Stage C", {
    Slot::kPlasmaLaneA,
    Slot::kPlasmaLaneB,
    Slot::kPlasmaLaneC,
    Slot::kPlasmaLaneD,
});

/*
TwistDiffuse::DiffuseWithDomainWords(
                aFuseLaneA, aFuseLaneB, aFuseLaneC, aFuseLaneD,  // input lanes
                aShadowLaneA, aShadowLaneB, aShadowLaneC, aShadowLaneD, // output lanes
                aMagmaLaneC, aMagmaLaneD, aPlasmaLaneC, aPlasmaLaneD, // index shuffle seeds
                aPlasmaLaneA, aPlasmaLaneB);  // operation seeds
*/

//
// KDF C — Stage D
//
const GPassFactory::SlotArray4 aPrimarySourcesD = {
    Slot::kShadowLaneA,
    Slot::kShadowLaneB,
    Slot::kShadowLaneC,
    Slot::kShadowLaneD,
};
const GPassFactory::SlotArray4 aDestinationsD = {
    Slot::kCrystalLaneA,
    Slot::kCrystalLaneB,
    Slot::kCrystalLaneC,
    Slot::kCrystalLaneD,
};

pResidualBucket.Remove(GPassFactory::ToVector(aPrimarySourcesD));
pResidualBucket.Remove(GPassFactory::ToVector(aDestinationsD));

printf("at KDF C — Stage D, there were %zu residuals available\n",
       pResidualBucket.CountValidResiduals());

aResidualsPool = pResidualBucket.Withdraw("KDF C — Stage D", 14);

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

pResidualBucket.AddResiduals("KDF C — Stage D", {
    Slot::kShadowLaneA,
    Slot::kShadowLaneB,
    Slot::kShadowLaneC,
    Slot::kShadowLaneD,
});

