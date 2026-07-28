

std::vector<Slot> aRandomSnowA = {
    Slot::kSnowLaneA, Slot::kSnowLaneB,
    Slot::kSnowLaneC, Slot::kSnowLaneD,
};
Random::Shuffle(&aRandomSnowA);

std::vector<Slot> aRandomSnowB = {
    Slot::kSnowLaneA, Slot::kSnowLaneB,
    Slot::kSnowLaneC, Slot::kSnowLaneD,
};
Random::Shuffle(&aRandomSnowB);

//
// Seed — Stage A
//
const GPassFactory::SlotArray1 aPrimarySourcesA = {
    Slot::kSource,
};
const GPassFactory::SlotArray2 aWarmUpLanesA = {
    Slot::kPlasmaLaneA, Slot::kPlasmaLaneB,
};
const GPassFactory::SlotArray4 aDestinationsA = {
    Slot::kWaterLaneA, Slot::kWaterLaneB,
    Slot::kWaterLaneC, Slot::kWaterLaneD,
};
const GPassFactory::SlotArray6 aExpectedDestinationsA =
    GPassFactory::Concat(aWarmUpLanesA,
                         aDestinationsA);

pResidualBucket.Remove(GPassFactory::ToVector(aPrimarySourcesA));
pResidualBucket.Remove(GPassFactory::ToVector(aExpectedDestinationsA));

aResidualsPool =
    pResidualBucket.Withdraw("Seed — Stage A", 4 - 4);

const GPassFactory::SlotArray4 aResidualsA = {
    Slot::kSnowLaneA, Slot::kSnowLaneB,
    Slot::kSnowLaneC, Slot::kSnowLaneD,
};

pResidualBucket.AddResiduals("Seed — Stage A", {
    Slot::kPlasmaLaneA, Slot::kPlasmaLaneB,
});

//
// Seed — Stage B
//
const GPassFactory::SlotArray4 aPrimarySourcesB = {
    Slot::kWaterLaneA, Slot::kWaterLaneB,
    Slot::kWaterLaneC, Slot::kWaterLaneD,
};
const GPassFactory::SlotArray2 aWarmUpLanesB = {
    Slot::kPlasmaLaneC, Slot::kPlasmaLaneD,
};
const GPassFactory::SlotArray4 aDestinationsB = {
    Slot::kMagmaLaneA, Slot::kMagmaLaneB,
    Slot::kMagmaLaneC, Slot::kMagmaLaneD,
};
const GPassFactory::SlotArray6 aExpectedDestinationsB =
    GPassFactory::Concat(aWarmUpLanesB,
                         aDestinationsB);

pResidualBucket.Remove(GPassFactory::ToVector(aPrimarySourcesB));
pResidualBucket.Remove(GPassFactory::ToVector(aExpectedDestinationsB));

aResidualsPool =
    pResidualBucket.Withdraw("Seed — Stage B", 7 - 5);

const GPassFactory::SlotArray7 aResidualsB = {
    Slot::kSource,
    Slot::kSnowLaneA, Slot::kSnowLaneB,
    Slot::kSnowLaneC, Slot::kSnowLaneD,
    aResidualsPool[0], aResidualsPool[1],
};

pResidualBucket.AddResiduals("Seed — Stage B", {
    Slot::kWaterLaneA, Slot::kWaterLaneB,
    Slot::kWaterLaneC, Slot::kWaterLaneD,
    Slot::kPlasmaLaneC, Slot::kPlasmaLaneD,
});

//
// Seed — Stage C
//
const GPassFactory::SlotArray4 aPrimarySourcesC = {
    Slot::kMagmaLaneA, Slot::kMagmaLaneB,
    Slot::kMagmaLaneC, Slot::kMagmaLaneD,
};
const GPassFactory::SlotArray4 aDestinationsC = {
    Slot::kFuseLaneA, Slot::kFuseLaneB,
    Slot::kFuseLaneC, Slot::kFuseLaneD,
};

pResidualBucket.Remove(GPassFactory::ToVector(aPrimarySourcesC));
pResidualBucket.Remove(GPassFactory::ToVector(aDestinationsC));

aResidualsPool =
    pResidualBucket.Withdraw("Seed — Stage C", 13 - 5);

const GPassFactory::SlotArray13 aResidualsC = {
    Slot::kSource,
    Slot::kSnowLaneA, Slot::kSnowLaneB,
    Slot::kSnowLaneC, Slot::kSnowLaneD,
    aResidualsPool[0], aResidualsPool[1],
    aResidualsPool[2], aResidualsPool[3],
    aResidualsPool[4], aResidualsPool[5],
    aResidualsPool[6], aResidualsPool[7],
};

pResidualBucket.AddResiduals("Seed — Stage C", {
    Slot::kMagmaLaneA, Slot::kMagmaLaneB,
    Slot::kMagmaLaneC, Slot::kMagmaLaneD,
});

/*
TwistDiffuse::DiffuseWithDomainWords(
            aFuseLaneA, aFuseLaneB, aFuseLaneC, aFuseLaneD,  // input lanes
            aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, // output lanes
            aPlasmaLaneC, aPlasmaLaneD, aMagmaLaneC, aMagmaLaneD, // index shuffle seeds
            aMagmaLaneA, aMagmaLaneB); // operation seeds
*/
                                       
//
// Seed — Stage D
//
const GPassFactory::SlotArray4 aPrimarySourcesD = {
    Slot::kHeartLaneA, Slot::kHeartLaneB,
    Slot::kHeartLaneC, Slot::kHeartLaneD,
};
const GPassFactory::SlotArray2 aWarmUpLanesD = {
    Slot::kCrystalLaneA, Slot::kCrystalLaneB,
};
const GPassFactory::SlotArray4 aDestinationsD = {
    Slot::kShadowLaneA, Slot::kShadowLaneB,
    Slot::kShadowLaneC, Slot::kShadowLaneD,
};
const GPassFactory::SlotArray6 aExpectedDestinationsD =
    GPassFactory::Concat(aWarmUpLanesD,
                         aDestinationsD);

pResidualBucket.Remove(GPassFactory::ToVector(aPrimarySourcesD));
pResidualBucket.Remove(GPassFactory::ToVector(aExpectedDestinationsD));

aResidualsPool =
    pResidualBucket.Withdraw("Seed — Stage D", 17 - 5);

const GPassFactory::SlotArray17 aResidualsD = {
    Slot::kSource,
    Slot::kSnowLaneA, Slot::kSnowLaneB,
    Slot::kSnowLaneC, Slot::kSnowLaneD,
    aResidualsPool[0], aResidualsPool[1],
    aResidualsPool[2], aResidualsPool[3],
    aResidualsPool[4], aResidualsPool[5],
    aResidualsPool[6], aResidualsPool[7],
    aResidualsPool[8], aResidualsPool[9],
    aResidualsPool[10], aResidualsPool[11],
};

pResidualBucket.AddResiduals("Seed — Stage D", {
    Slot::kHeartLaneA, Slot::kHeartLaneB,
    Slot::kHeartLaneC, Slot::kHeartLaneD,
    Slot::kCrystalLaneA, Slot::kCrystalLaneB,
});

//
// Seed — Stage E
//
const GPassFactory::SlotArray4 aPrimarySourcesE = {
    Slot::kShadowLaneA, Slot::kShadowLaneB,
    Slot::kShadowLaneC, Slot::kShadowLaneD,
};
const GPassFactory::SlotArray2 aWarmUpLanesE = {
    Slot::kCrystalLaneC, Slot::kCrystalLaneD,
};
const GPassFactory::SlotArray4 aDestinationsE = {
    Slot::kEarthLaneA, Slot::kEarthLaneB,
    Slot::kEarthLaneC, Slot::kEarthLaneD,
};
const GPassFactory::SlotArray6 aExpectedDestinationsE =
    GPassFactory::Concat(aWarmUpLanesE,
                         aDestinationsE);

pResidualBucket.Remove(GPassFactory::ToVector(aPrimarySourcesE));
pResidualBucket.Remove(GPassFactory::ToVector(aExpectedDestinationsE));

aResidualsPool =
    pResidualBucket.Withdraw("Seed — Stage E", 21 - 3);

const GPassFactory::SlotArray21 aResidualsE = {
    Slot::kSource, Slot::kSnowLaneA, Slot::kSnowLaneB,
    aResidualsPool[0], aResidualsPool[1],
    aResidualsPool[2], aResidualsPool[3],
    aResidualsPool[4], aResidualsPool[5],
    aResidualsPool[6], aResidualsPool[7],
    aResidualsPool[8], aResidualsPool[9],
    aResidualsPool[10], aResidualsPool[11],
    aResidualsPool[12], aResidualsPool[13],
    aResidualsPool[14], aResidualsPool[15],
    aResidualsPool[16], aResidualsPool[17],
};

pResidualBucket.AddResiduals("Seed — Stage E", {
    Slot::kShadowLaneA, Slot::kShadowLaneB,
    Slot::kShadowLaneC, Slot::kShadowLaneD,
    Slot::kCrystalLaneC, Slot::kCrystalLaneD,
});

//
// Seed — Stage F
//
const GPassFactory::SlotArray4 aPrimarySourcesF = {
    Slot::kEarthLaneA, Slot::kEarthLaneB,
    Slot::kEarthLaneC, Slot::kEarthLaneD,
};
const GPassFactory::SlotArray4 aDestinationsF = {
    Slot::kFuseLaneA, Slot::kFuseLaneB,
    Slot::kFuseLaneC, Slot::kFuseLaneD,
};

pResidualBucket.Remove(GPassFactory::ToVector(aPrimarySourcesF));
pResidualBucket.Remove(GPassFactory::ToVector(aDestinationsF));

aResidualsPool =
    pResidualBucket.Withdraw("Seed — Stage F", 16 - 3);

const GPassFactory::SlotArray16 aResidualsF = {
    Slot::kSource, Slot::kSnowLaneC, Slot::kSnowLaneD,
    aResidualsPool[0], aResidualsPool[1],
    aResidualsPool[2], aResidualsPool[3],
    aResidualsPool[4], aResidualsPool[5],
    aResidualsPool[6], aResidualsPool[7],
    aResidualsPool[8], aResidualsPool[9],
    aResidualsPool[10], aResidualsPool[11],
    aResidualsPool[12],
};

pResidualBucket.AddResiduals("Seed — Stage F", {
    Slot::kEarthLaneA, Slot::kEarthLaneB,
    Slot::kEarthLaneC, Slot::kEarthLaneD,
});

/*
TwistDiffuse::DiffuseWithDomainWords(
        aFuseLaneA, aFuseLaneB, aFuseLaneC, aFuseLaneD,  // input lanes
        aWindLaneA, aWindLaneB, aWindLaneC, aWindLaneD, // output lanes
        aCrystalLaneC, aCrystalLaneD, aEarthLaneC, aEarthLaneD, // index shuffle seeds
        aEarthLaneA, aEarthLaneB); // operation seeds
*/

//
// Seed — Stage G
//
const GPassFactory::SlotArray4 aPrimarySourcesG = {
    Slot::kWindLaneA, Slot::kWindLaneB,
    Slot::kWindLaneC, Slot::kWindLaneD,
};
const GPassFactory::SlotArray2 aWarmUpLanesG = {
    Slot::kAetherLaneA, Slot::kAetherLaneB,
};
const GPassFactory::SlotArray4 aDestinationsG = {
    Slot::kVaporLaneA, Slot::kVaporLaneB,
    Slot::kVaporLaneC, Slot::kVaporLaneD,
};
const GPassFactory::SlotArray6 aExpectedDestinationsG =
    GPassFactory::Concat(aWarmUpLanesG,
                         aDestinationsG);

pResidualBucket.Remove(GPassFactory::ToVector(aPrimarySourcesG));
pResidualBucket.Remove(GPassFactory::ToVector(aExpectedDestinationsG));

aResidualsPool =
    pResidualBucket.Withdraw("Seed — Stage G", 24 - 2);

const GPassFactory::SlotArray24 aResidualsG = {
    aRandomSnowA[0], aRandomSnowA[1],
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

pResidualBucket.AddResiduals("Seed — Stage G", {
    Slot::kWindLaneA, Slot::kWindLaneB,
    Slot::kWindLaneC, Slot::kWindLaneD,
    Slot::kAetherLaneA, Slot::kAetherLaneB,
});

//
// Seed — Stage H
//
const GPassFactory::SlotArray4 aPrimarySourcesH = {
    Slot::kVaporLaneA, Slot::kVaporLaneB,
    Slot::kVaporLaneC, Slot::kVaporLaneD,
};
const GPassFactory::SlotArray2 aWarmUpLanesH = {
    Slot::kAetherLaneC, Slot::kAetherLaneD,
};
const GPassFactory::SlotArray4 aDestinationsH = {
    Slot::kFireLaneA, Slot::kFireLaneB,
    Slot::kFireLaneC, Slot::kFireLaneD,
};
const GPassFactory::SlotArray6 aExpectedDestinationsH =
    GPassFactory::Concat(aWarmUpLanesH,
                         aDestinationsH);

pResidualBucket.Remove(GPassFactory::ToVector(aPrimarySourcesH));
pResidualBucket.Remove(GPassFactory::ToVector(aExpectedDestinationsH));

aResidualsPool =
    pResidualBucket.Withdraw("Seed — Stage H", 24 - 2);

const GPassFactory::SlotArray24 aResidualsH = {
    aRandomSnowA[2], aRandomSnowA[3],
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

pResidualBucket.AddResiduals("Seed — Stage H", {
    Slot::kVaporLaneA, Slot::kVaporLaneB,
    Slot::kVaporLaneC, Slot::kVaporLaneD,
    Slot::kAetherLaneC, Slot::kAetherLaneD,
});

//
// Seed — Stage I
//
const GPassFactory::SlotArray4 aPrimarySourcesI = {
    Slot::kFireLaneA, Slot::kFireLaneB,
    Slot::kFireLaneC, Slot::kFireLaneD,
};
const GPassFactory::SlotArray4 aDestinationsI = {
    Slot::kFuseLaneA, Slot::kFuseLaneB,
    Slot::kFuseLaneC, Slot::kFuseLaneD,
};

pResidualBucket.Remove(GPassFactory::ToVector(aPrimarySourcesI));
pResidualBucket.Remove(GPassFactory::ToVector(aDestinationsI));

aResidualsPool =
    pResidualBucket.Withdraw("Seed — Stage I", 16 - 2);

const GPassFactory::SlotArray16 aResidualsI = {
    Slot::kSource, aRandomSnowB[0],
    aResidualsPool[0], aResidualsPool[1],
    aResidualsPool[2], aResidualsPool[3],
    aResidualsPool[4], aResidualsPool[5],
    aResidualsPool[6], aResidualsPool[7],
    aResidualsPool[8], aResidualsPool[9],
    aResidualsPool[10], aResidualsPool[11],
    aResidualsPool[12], aResidualsPool[13],
};

pResidualBucket.AddResiduals("Seed — Stage I", {
    Slot::kFireLaneA, Slot::kFireLaneB,
    Slot::kFireLaneC, Slot::kFireLaneD,
});

/*
TwistDiffuse::DiffuseWithDomainWords(
        aFuseLaneA, aFuseLaneB, aFuseLaneC, aFuseLaneD,  // input lanes
        aCelestialLaneA, aCelestialLaneB, aCelestialLaneC, aCelestialLaneD, // output lanes
        aAetherLaneC, aAetherLaneD, aFireLaneC, aFireLaneD, // index shuffle seeds
        aFireLaneA, aFireLaneB); // operation seeds
*/

//
// Seed — Stage J
//
const GPassFactory::SlotArray4 aPrimarySourcesJ = {
    Slot::kCelestialLaneA, Slot::kCelestialLaneB,
    Slot::kCelestialLaneC, Slot::kCelestialLaneD,
};
const GPassFactory::SlotArray2 aWarmUpLanesJ = {
    Slot::kLightningLaneA, Slot::kLightningLaneB,
};
const GPassFactory::SlotArray4 aDestinationsJ = {
    Slot::kSoilLaneA, Slot::kSoilLaneB,
    Slot::kSoilLaneC, Slot::kSoilLaneD,
};
const GPassFactory::SlotArray6 aExpectedDestinationsJ =
    GPassFactory::Concat(aWarmUpLanesJ,
                         aDestinationsJ);

pResidualBucket.Remove(GPassFactory::ToVector(aPrimarySourcesJ));
pResidualBucket.Remove(GPassFactory::ToVector(aExpectedDestinationsJ));

aResidualsPool =
    pResidualBucket.Withdraw("Seed — Stage J", 24 - 2);

const GPassFactory::SlotArray24 aResidualsJ = {
    Slot::kSource, aRandomSnowB[1],
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

pResidualBucket.AddResiduals("Seed — Stage J", {
    Slot::kCelestialLaneA, Slot::kCelestialLaneB,
    Slot::kCelestialLaneC, Slot::kCelestialLaneD,
    Slot::kLightningLaneA, Slot::kLightningLaneB,
});

//
// Seed — Stage K
//
const GPassFactory::SlotArray4 aPrimarySourcesK = {
    Slot::kSoilLaneA, Slot::kSoilLaneB,
    Slot::kSoilLaneC, Slot::kSoilLaneD,
};
const GPassFactory::SlotArray2 aWarmUpLanesK = {
    Slot::kLightningLaneC, Slot::kLightningLaneD,
};
const GPassFactory::SlotArray4 aDestinationsK = {
    Slot::kIceLaneA, Slot::kIceLaneB,
    Slot::kIceLaneC, Slot::kIceLaneD,
};
const GPassFactory::SlotArray6 aExpectedDestinationsK =
    GPassFactory::Concat(aWarmUpLanesK,
                         aDestinationsK);

pResidualBucket.Remove(GPassFactory::ToVector(aPrimarySourcesK));
pResidualBucket.Remove(GPassFactory::ToVector(aExpectedDestinationsK));

aResidualsPool =
    pResidualBucket.Withdraw("Seed — Stage K", 24 - 2);

const GPassFactory::SlotArray24 aResidualsK = {
    Slot::kSource, aRandomSnowB[2],
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

pResidualBucket.AddResiduals("Seed — Stage K", {
    Slot::kSoilLaneA, Slot::kSoilLaneB,
    Slot::kSoilLaneC, Slot::kSoilLaneD,
    Slot::kLightningLaneC, Slot::kLightningLaneD,
});

//
// Seed — Stage L
//
const GPassFactory::SlotArray4 aPrimarySourcesL = {
    Slot::kIceLaneA, Slot::kIceLaneB,
    Slot::kIceLaneC, Slot::kIceLaneD,
};
const GPassFactory::SlotArray4 aDestinationsL = {
    Slot::kFuseLaneA, Slot::kFuseLaneB,
    Slot::kFuseLaneC, Slot::kFuseLaneD,
};

pResidualBucket.Remove(GPassFactory::ToVector(aPrimarySourcesL));
pResidualBucket.Remove(GPassFactory::ToVector(aDestinationsL));

aResidualsPool =
    pResidualBucket.Withdraw("Seed — Stage L", 16 - 2);

const GPassFactory::SlotArray16 aResidualsL = {
    Slot::kSource, aRandomSnowB[3],
    aResidualsPool[0], aResidualsPool[1],
    aResidualsPool[2], aResidualsPool[3],
    aResidualsPool[4], aResidualsPool[5],
    aResidualsPool[6], aResidualsPool[7],
    aResidualsPool[8], aResidualsPool[9],
    aResidualsPool[10], aResidualsPool[11],
    aResidualsPool[12], aResidualsPool[13],
};

pResidualBucket.AddResiduals("Seed — Stage L", {
    Slot::kIceLaneA, Slot::kIceLaneB,
    Slot::kIceLaneC, Slot::kIceLaneD,
});

/*
TwistDiffuse::DiffuseWithDomainWords(
            aFuseLaneA, aFuseLaneB, aFuseLaneC, aFuseLaneD,  // input lanes
            aWoodLaneA, aWoodLaneB, aWoodLaneC, aWoodLaneD, // output lanes
            aLightningLaneC, aLightningLaneD, aIceLaneC, aIceLaneD, // index shuffle seeds
            aIceLaneA, aIceLaneB); // operation seeds
*/

//
// Seed — Stage M
//
const GPassFactory::SlotArray4 aPrimarySourcesM = {
    Slot::kWoodLaneA, Slot::kWoodLaneB,
    Slot::kWoodLaneC, Slot::kWoodLaneD,
};
const GPassFactory::SlotArray2 aWarmUpLanesM = {
    Slot::kPlasmaLaneA, Slot::kPlasmaLaneB,
};
const GPassFactory::SlotArray4 aDestinationsM = {
    Slot::kMagmaLaneA, Slot::kMagmaLaneB,
    Slot::kMagmaLaneC, Slot::kMagmaLaneD,
};
const GPassFactory::SlotArray6 aExpectedDestinationsM =
    GPassFactory::Concat(aWarmUpLanesM,
                         aDestinationsM);

pResidualBucket.Remove(GPassFactory::ToVector(aPrimarySourcesM));
pResidualBucket.Remove(GPassFactory::ToVector(aExpectedDestinationsM));

aResidualsPool =
    pResidualBucket.Withdraw("Seed — Stage M", 24 - 1);

const GPassFactory::SlotArray24 aResidualsM = {
    Slot::kSource,
    aResidualsPool[0], aResidualsPool[1],
    aResidualsPool[2], aResidualsPool[3],
    aResidualsPool[4], aResidualsPool[5],
    aResidualsPool[6], aResidualsPool[7],
    aResidualsPool[8], aResidualsPool[9],
    aResidualsPool[10], aResidualsPool[11],
    aResidualsPool[12], aResidualsPool[13],
    aResidualsPool[14],
    aResidualsPool[15], aResidualsPool[16],
    aResidualsPool[17], aResidualsPool[18],
    aResidualsPool[19], aResidualsPool[20],
    aResidualsPool[21], aResidualsPool[22],
};

pResidualBucket.AddResiduals("Seed — Stage M", {
    Slot::kWoodLaneA, Slot::kWoodLaneB,
    Slot::kWoodLaneC, Slot::kWoodLaneD,
    Slot::kPlasmaLaneA, Slot::kPlasmaLaneB,
});

//
// Seed — Stage N
//
const GPassFactory::SlotArray4 aPrimarySourcesN = {
    Slot::kMagmaLaneA, Slot::kMagmaLaneB,
    Slot::kMagmaLaneC, Slot::kMagmaLaneD,
};
const GPassFactory::SlotArray2 aWarmUpLanesN = {
    Slot::kPlasmaLaneC, Slot::kPlasmaLaneD,
};
const GPassFactory::SlotArray4 aDestinationsN = {
    Slot::kPoisonLaneA, Slot::kPoisonLaneB,
    Slot::kPoisonLaneC, Slot::kPoisonLaneD,
};
const GPassFactory::SlotArray6 aExpectedDestinationsN =
    GPassFactory::Concat(aWarmUpLanesN,
                         aDestinationsN);

pResidualBucket.Remove(GPassFactory::ToVector(aPrimarySourcesN));
pResidualBucket.Remove(GPassFactory::ToVector(aExpectedDestinationsN));

aResidualsPool =
    pResidualBucket.Withdraw("Seed — Stage N", 24);

const GPassFactory::SlotArray24 aResidualsN = {
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
    aResidualsPool[22], aResidualsPool[23],
};

// Poison is the GrowA starting family, so it deliberately stays out of
// the residual bucket.
pResidualBucket.AddResiduals("Seed — Stage N", {
    Slot::kMagmaLaneA, Slot::kMagmaLaneB,
    Slot::kMagmaLaneC, Slot::kMagmaLaneD,
    Slot::kPlasmaLaneC, Slot::kPlasmaLaneD,
});

pResidualBucket.Print("Seed — Final");

