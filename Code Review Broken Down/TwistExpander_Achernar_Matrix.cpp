
void TwistExpander_Achernar::KDF_A() {
    
    TwistDiffuse::DiffuseWithDomainWords(
         aFuseLaneA, aFuseLaneB, aFuseLaneC, aFuseLaneD,  // input lanes
         aWaterLaneA, aWaterLaneB, aWaterLaneC, aWaterLaneD, // output lanes
         aFireLaneC, aFireLaneD, aWindLaneC, aWindLaneD, // index shuffle seeds
         aWindLaneA, aWindLaneB); // operation seeds
}

void TwistExpander_Achernar::KDF_B() {
    
    TwistDiffuse::DiffuseWithDomainWords(
         aFuseLaneA, aFuseLaneB, aFuseLaneC, aFuseLaneD,  // input lanes
         aIceLaneA, aIceLaneB, aIceLaneC, aIceLaneD, // output lanes
         aSoilLaneC, aSoilLaneD, aLightningLaneC, aLightningLaneD, // index shuffle seeds
         aLightningLaneA, aLightningLaneB); // operation seeds
    
}

void TwistExpander_Achernar::KDF_C() {
    
    TwistDiffuse::DiffuseWithDomainWords(
         aFuseLaneA, aFuseLaneB, aFuseLaneC, aFuseLaneD,  // input lanes
         aShadowLaneA, aShadowLaneB, aShadowLaneC, aShadowLaneD, // output lanes
         aMagmaLaneC, aMagmaLaneD, aPlasmaLaneC, aPlasmaLaneD, // index shuffle seeds
         aPlasmaLaneA, aPlasmaLaneB); // operation seeds
    
}

void TwistExpander_Achernar::KDF_D() {
    
    TwistDiffuse::DiffuseWithDomainWords(
         aFuseLaneA, aFuseLaneB, aFuseLaneC, aFuseLaneD,  // input lanes
         aVaporLaneA, aVaporLaneB, aVaporLaneC, aVaporLaneD, // output lanes
         aAetherLaneC, aAetherLaneD, aCelestialLaneC, aCelestialLaneD, // index shuffle seeds
         aCelestialLaneA, aCelestialLaneB); // operation seeds
    
}

void TwistExpander_Achernar::Seed() {
    
    TwistDiffuse::DiffuseWithDomainWords(
         aFuseLaneA, aFuseLaneB, aFuseLaneC, aFuseLaneD,  // input lanes
         aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, // output lanes
         aPlasmaLaneC, aPlasmaLaneD, aMagmaLaneC, aMagmaLaneD, // index shuffle seeds
         aMagmaLaneA, aMagmaLaneB); // operation seeds

    TwistDiffuse::DiffuseWithDomainWords(
         aFuseLaneA, aFuseLaneB, aFuseLaneC, aFuseLaneD,  // input lanes
         aWindLaneA, aWindLaneB, aWindLaneC, aWindLaneD, // output lanes
         aCrystalLaneC, aCrystalLaneD, aEarthLaneC, aEarthLaneD, // index shuffle seeds
         aEarthLaneA, aEarthLaneB); // operation seeds

    TwistDiffuse::DiffuseWithDomainWords(
         aFuseLaneA, aFuseLaneB, aFuseLaneC, aFuseLaneD,  // input lanes
         aCelestialLaneA, aCelestialLaneB, aCelestialLaneC, aCelestialLaneD, // output lanes
         aAetherLaneC, aAetherLaneD, aFireLaneC, aFireLaneD, // index shuffle seeds
         aFireLaneA, aFireLaneB); // operation seeds

    TwistDiffuse::DiffuseWithDomainWords(
         aFuseLaneA, aFuseLaneB, aFuseLaneC, aFuseLaneD,  // input lanes
         aWoodLaneA, aWoodLaneB, aWoodLaneC, aWoodLaneD, // output lanes
         aLightningLaneC, aLightningLaneD, aIceLaneC, aIceLaneD, // index shuffle seeds
         aIceLaneA, aIceLaneB); // operation seeds

}

void TwistExpander_Achernar::TwistBlock() {
    
    TwistDiffuse::DiffuseWithDomainWords(
         aFuseLaneA, aFuseLaneB, aFuseLaneC, aFuseLaneD,  // input lanes
         aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, // output lanes
         aFireLaneC, aFireLaneD, aWaterLaneC, aWaterLaneD, // index shuffle seeds
         aWaterLaneA, aWaterLaneB); // operation seeds
    
    TwistDiffuse::DiffuseWithDomainWords(
         aFuseLaneA, aFuseLaneB, aFuseLaneC, aFuseLaneD,  // input lanes
         aWoodLaneA, aWoodLaneB, aWoodLaneC, aWoodLaneD, // output lanes
         aLightningLaneC, aLightningLaneD, aIceLaneC, aIceLaneD, // index shuffle seeds
         aIceLaneA, aIceLaneB); // operation seeds
    
}

void TwistExpander_Achernar::GrowKeyA() {

    TwistDiffuse::DiffuseWithDomainWords(
         aFuseLaneA, aFuseLaneB, aFuseLaneC, aFuseLaneD,  // input lanes
         aVaporLaneA, aVaporLaneB, aVaporLaneC, aVaporLaneD, // output lanes
         aShadowLaneC, aShadowLaneD, aWindLaneC, aWindLaneD, // index shuffle seeds
         aWindLaneA, aWindLaneB); // operation seeds
    
}

void TwistExpander_Achernar::GrowKeyB() {
    
    TwistDiffuse::DiffuseWithDomainWords(
         aFuseLaneA, aFuseLaneB, aFuseLaneC, aFuseLaneD,  // input lanes
         aChanceLaneA, aChanceLaneB, aChanceLaneC, aChanceLaneD, // output lanes
         aKineticLaneC, aKineticLaneD, aCelestialLaneC, aCelestialLaneD, // index shuffle seeds
         aCelestialLaneA, aCelestialLaneB); // operation seeds
    
}
