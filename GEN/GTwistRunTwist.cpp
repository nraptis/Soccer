
std::vector<Slot> aRandomSnow = {
    Slot::kSnowLaneA, Slot::kSnowLaneB,
    Slot::kSnowLaneC, Slot::kSnowLaneD,
};
Random::Shuffle(&aRandomSnow);

TwistStageConfigs aConfigs;

//
// Twist — Stage A
//
const GPassFactory::SlotArray3 aPrimarySourcesA = {
    Slot::kSource, Slot::kKeyRowReadA, Slot::kKeyRowReadB,
};
const GPassFactory::SlotArray2 aWarmUpLanesA = {
    Slot::kFireLaneA, Slot::kFireLaneB,
};
const GPassFactory::SlotArray4 aDestinationsA = {
    Slot::kEarthLaneA, Slot::kEarthLaneB,
    Slot::kEarthLaneC, Slot::kEarthLaneD,
};
const GPassFactory::SlotArray6 aExpectedDestinationsA =
    GPassFactory::Concat(aWarmUpLanesA,
                         aDestinationsA);

pResidualBucket.Remove(GPassFactory::ToVector(aPrimarySourcesA));
pResidualBucket.Remove(GPassFactory::ToVector(aExpectedDestinationsA));

aResidualsPool = pResidualBucket.Withdraw("Twist — Stage A", 0);

const GPassFactory::SlotArray4 aResidualsA = {
    Slot::kSnowLaneA, Slot::kSnowLaneB,
    Slot::kSnowLaneC, Slot::kSnowLaneD,
};

pResidualBucket.AddResiduals("Twist — Stage A", {
    Slot::kFireLaneA, Slot::kFireLaneB,
});

//
// Twist — Stage B
//
const GPassFactory::SlotArray4 aInputsB = {
    Slot::kEarthLaneA, Slot::kEarthLaneB,
    Slot::kEarthLaneC, Slot::kEarthLaneD,
};
const GPassFactory::SlotArray6 aDestinationsB = {
    Slot::kFireLaneC, Slot::kFireLaneD,
    Slot::kWaterLaneA, Slot::kWaterLaneB,
    Slot::kWaterLaneC, Slot::kWaterLaneD,
};
pResidualBucket.Remove(GPassFactory::ToVector(aInputsB));
pResidualBucket.Remove(GPassFactory::ToVector(aDestinationsB));

aResidualsPool = pResidualBucket.Withdraw("Twist — Stage B", 9 - 7); // we are using 7 fixed ones.

const GPassFactory::SlotArray9 aResidualsB = {
    Slot::kSnowLaneA, Slot::kSnowLaneB,
    Slot::kSnowLaneC, Slot::kSnowLaneD,
    Slot::kKeyRowReadA, Slot::kKeyRowReadB, Slot::kSource,
    aResidualsPool[0], aResidualsPool[1],
};

pResidualBucket.AddResiduals("Twist — Stage B", {
    Slot::kEarthLaneA, Slot::kEarthLaneB,
    Slot::kEarthLaneC, Slot::kEarthLaneD,
    Slot::kFireLaneC, Slot::kFireLaneD,
});

//
// Twist — Stage C
//
const GPassFactory::SlotArray4 aInputsC = {
    Slot::kWaterLaneA, Slot::kWaterLaneB,
    Slot::kWaterLaneC, Slot::kWaterLaneD,
};
const GPassFactory::SlotArray4 aDestinationsC = {
    Slot::kFuseLaneA, Slot::kFuseLaneB,
    Slot::kFuseLaneC, Slot::kFuseLaneD,
};
pResidualBucket.Remove(GPassFactory::ToVector(aInputsC));
pResidualBucket.Remove(GPassFactory::ToVector(aDestinationsC));

aResidualsPool = pResidualBucket.Withdraw("Twist — Stage C", 14 - 6); // we are using 6 fixed ones.

const GPassFactory::SlotArray14 aResidualsC = {
    Slot::kSnowLaneA, Slot::kSnowLaneB,
    Slot::kSnowLaneC, Slot::kSnowLaneD,
    Slot::kKeyRowReadA, Slot::kSource,
    aResidualsPool[0], aResidualsPool[1],
    aResidualsPool[2], aResidualsPool[3],
    aResidualsPool[4], aResidualsPool[5],
    aResidualsPool[6], aResidualsPool[7],
};

pResidualBucket.AddResiduals("Twist — Stage C", {
    Slot::kWaterLaneA, Slot::kWaterLaneB,
    Slot::kWaterLaneC, Slot::kWaterLaneD,
});

/*
TwistDiffuse::DiffuseWithDomainWords(
            aFuseLaneA, aFuseLaneB, aFuseLaneC, aFuseLaneD,  // input lanes
            aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, // output lanes
            aFireLaneC, aFireLaneD, aWaterLaneC, aWaterLaneD, // index shuffle seeds
            aWaterLaneA, aWaterLaneB); // operation seeds
*/

//
// Twist — Stage D
//
const GPassFactory::SlotArray4 aInputsD = {
    Slot::kHeartLaneA, Slot::kHeartLaneB,
    Slot::kHeartLaneC, Slot::kHeartLaneD,
};
const GPassFactory::SlotArray6 aDestinationsD = {
    Slot::kLightningLaneA, Slot::kLightningLaneB,
    Slot::kSoilLaneA, Slot::kSoilLaneB,
    Slot::kSoilLaneC, Slot::kSoilLaneD,
};
pResidualBucket.Remove(GPassFactory::ToVector(aInputsD));
pResidualBucket.Remove(GPassFactory::ToVector(aDestinationsD));

aResidualsPool = pResidualBucket.Withdraw("Twist — Stage D", 16 - 6); // we are using 6 fixed ones.

const GPassFactory::SlotArray16 aResidualsD = {
    Slot::kSnowLaneA, Slot::kSnowLaneB,
    Slot::kSnowLaneC, Slot::kSnowLaneD,
    Slot::kKeyRowReadB, Slot::kSource,
    aResidualsPool[0], aResidualsPool[1],
    aResidualsPool[2], aResidualsPool[3],
    aResidualsPool[4], aResidualsPool[5],
    aResidualsPool[6], aResidualsPool[7],
    aResidualsPool[8], aResidualsPool[9],
};



pResidualBucket.AddResiduals("Twist — Stage D", {
    Slot::kHeartLaneA, Slot::kHeartLaneB,
    Slot::kHeartLaneC, Slot::kHeartLaneD,
    Slot::kLightningLaneA, Slot::kLightningLaneB,
});

//
// Twist — Stage E
//
const GPassFactory::SlotArray4 aInputsE = {
    Slot::kSoilLaneA, Slot::kSoilLaneB,
    Slot::kSoilLaneC, Slot::kSoilLaneD,
};
const GPassFactory::SlotArray6 aDestinationsE = {
    Slot::kLightningLaneC, Slot::kLightningLaneD,
    Slot::kIceLaneA, Slot::kIceLaneB,
    Slot::kIceLaneC, Slot::kIceLaneD,
};
pResidualBucket.Remove(GPassFactory::ToVector(aInputsE));
pResidualBucket.Remove(GPassFactory::ToVector(aDestinationsE));

aResidualsPool = pResidualBucket.Withdraw("Twist — Stage E", 16 - 3); // we are using 3 fixed ones.

const GPassFactory::SlotArray16 aResidualsE = {
    aRandomSnow[0], Slot::kKeyRowReadA, Slot::kSource,
    aResidualsPool[0], aResidualsPool[1], aResidualsPool[2],
    aResidualsPool[3], aResidualsPool[4], aResidualsPool[5],
    aResidualsPool[6], aResidualsPool[7], aResidualsPool[8],
    aResidualsPool[9], aResidualsPool[10], aResidualsPool[11],
    aResidualsPool[12],
};

pResidualBucket.AddResiduals("Twist — Stage E", {
    Slot::kSoilLaneA, Slot::kSoilLaneB,
    Slot::kSoilLaneC, Slot::kSoilLaneD,
    Slot::kLightningLaneC, Slot::kLightningLaneD,
});

//
// Twist — Stage F
//

const GPassFactory::SlotArray4 aPrimarySourcesF = {
    Slot::kIceLaneA, Slot::kIceLaneB,
    Slot::kIceLaneC, Slot::kIceLaneD,
};
const GPassFactory::SlotArray4 aDestinationsF = {
    Slot::kFuseLaneA, Slot::kFuseLaneB,
    Slot::kFuseLaneC, Slot::kFuseLaneD,
};
pResidualBucket.Remove(GPassFactory::ToVector(aPrimarySourcesF));
pResidualBucket.Remove(GPassFactory::ToVector(aDestinationsF));

aResidualsPool = pResidualBucket.Withdraw("Twist — Stage F", 16 - 3); // we are using 3 fixed ones.

const GPassFactory::SlotArray16 aResidualsF = {
    aRandomSnow[1], Slot::kKeyRowReadB, Slot::kSource,
    aResidualsPool[0], aResidualsPool[1], aResidualsPool[2], aResidualsPool[3],
    aResidualsPool[4], aResidualsPool[5], aResidualsPool[6], aResidualsPool[7],
    aResidualsPool[8], aResidualsPool[9], aResidualsPool[10], aResidualsPool[11],
    aResidualsPool[12],
};

pResidualBucket.AddResiduals("Twist — Stage F", {
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
// Twist — Stage G
//
const GPassFactory::SlotArray4 aPrimarySourcesG = {
    Slot::kWoodLaneA, Slot::kWoodLaneB,
    Slot::kWoodLaneC, Slot::kWoodLaneD,
};
const GPassFactory::SlotArray2 aWarmUpLanesG = {
    Slot::kPlasmaLaneA, Slot::kPlasmaLaneB,
};
const GPassFactory::SlotArray4 aDestinationsG = {
    Slot::kMagmaLaneA, Slot::kMagmaLaneB,
    Slot::kMagmaLaneC, Slot::kMagmaLaneD,
};
const GPassFactory::SlotArray6 aExpectedDestinationsG =
    GPassFactory::Concat(aWarmUpLanesG,
                         aDestinationsG);
pResidualBucket.Remove(GPassFactory::ToVector(aPrimarySourcesG));
pResidualBucket.Remove(GPassFactory::ToVector(aExpectedDestinationsG));

aResidualsPool = pResidualBucket.Withdraw("Twist — Stage G", 16 - 3); // we are using 3 fixed ones.

const GPassFactory::SlotArray16 aResidualsG = {
    aRandomSnow[2], Slot::kKeyRowReadA, Slot::kKeyRowReadB,
    aResidualsPool[0], aResidualsPool[1], aResidualsPool[2],
    aResidualsPool[3], aResidualsPool[4], aResidualsPool[5],
    aResidualsPool[6], aResidualsPool[7], aResidualsPool[8],
    aResidualsPool[9], aResidualsPool[10], aResidualsPool[11],
    aResidualsPool[12],
};



pResidualBucket.AddResiduals("Twist — Stage G", {
    Slot::kWoodLaneA, Slot::kWoodLaneB,
    Slot::kWoodLaneC, Slot::kWoodLaneD,
    Slot::kPlasmaLaneA, Slot::kPlasmaLaneB,
});

//
// Twist — Stage H
//
const GPassFactory::SlotArray4 aPrimarySourcesH = {
    Slot::kMagmaLaneA, Slot::kMagmaLaneB,
    Slot::kMagmaLaneC, Slot::kMagmaLaneD,
};
const GPassFactory::SlotArray2 aWarmUpLanesH = {
    Slot::kPlasmaLaneC, Slot::kPlasmaLaneD,
};
const GPassFactory::SlotArray4 aDestinationsH = {
    Slot::kPoisonLaneA, Slot::kPoisonLaneB,
    Slot::kPoisonLaneC, Slot::kPoisonLaneD,
};
const GPassFactory::SlotArray6 aExpectedDestinationsH =
    GPassFactory::Concat(aWarmUpLanesH,
                         aDestinationsH);
pResidualBucket.Remove(GPassFactory::ToVector(aPrimarySourcesH));
pResidualBucket.Remove(GPassFactory::ToVector(aExpectedDestinationsH));

aResidualsPool = pResidualBucket.Withdraw("Twist — Stage H", 16 - 1); // we are using 1 fixed one.

const GPassFactory::SlotArray16 aResidualsH = {
    aRandomSnow[3],
    aResidualsPool[0], aResidualsPool[1], aResidualsPool[2],
    aResidualsPool[3], aResidualsPool[4], aResidualsPool[5],
    aResidualsPool[6], aResidualsPool[7], aResidualsPool[8],
    aResidualsPool[9], aResidualsPool[10], aResidualsPool[11],
    aResidualsPool[12], aResidualsPool[13], aResidualsPool[14],
};

pResidualBucket.AddResiduals("Twist — Stage H", {
    Slot::kMagmaLaneA, Slot::kMagmaLaneB,
    Slot::kMagmaLaneC, Slot::kMagmaLaneD,
    Slot::kPlasmaLaneC, Slot::kPlasmaLaneD,
});

pResidualBucket.Print("Twist — Final");

