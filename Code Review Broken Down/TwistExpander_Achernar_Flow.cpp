

void TwistExpander_Achernar::KDF_A() {
    
    TwistExpander_Achernar_Arx::KDF_A_A();
    
    TwistExpander_Achernar_Arx::KDF_A_B();
    
    TwistExpander_Achernar_Arx::KDF_A_C();
    
    TwistDiffuse::DiffuseWithDomainWords(
         aFuseLaneA, aFuseLaneB, aFuseLaneC, aFuseLaneD,  // input lanes
         aWaterLaneA, aWaterLaneB, aWaterLaneC, aWaterLaneD, // output lanes
         aFireLaneC, aFireLaneD, aWindLaneC, aWindLaneD, // index shuffle seeds
         aWindLaneA, aWindLaneB); // operation seeds
    
    TwistExpander_Achernar_Arx::KDF_A_D();
}

void TwistExpander_Achernar::KDF_B() {
    
    TwistExpander_Achernar_Arx::KDF_B_A();
    
    TwistExpander_Achernar_Arx::KDF_B_B();
    
    TwistExpander_Achernar_Arx::KDF_B_C();
    
    TwistDiffuse::DiffuseWithDomainWords(
         aFuseLaneA, aFuseLaneB, aFuseLaneC, aFuseLaneD,  // input lanes
         aIceLaneA, aIceLaneB, aIceLaneC, aIceLaneD, // output lanes
         aSoilLaneC, aSoilLaneD, aLightningLaneC, aLightningLaneD, // index shuffle seeds
         aLightningLaneA, aLightningLaneB); // operation seeds
    
    TwistExpander_Achernar_Arx::KDF_B_D();
    
}

void TwistExpander_Achernar::KDF_C() {
    
    TwistExpander_Achernar_Arx::KDF_C_A();
    
    TwistExpander_Achernar_Arx::KDF_C_B();
    
    TwistExpander_Achernar_Arx::KDF_C_C();
    
    TwistDiffuse::DiffuseWithDomainWords(
         aFuseLaneA, aFuseLaneB, aFuseLaneC, aFuseLaneD,  // input lanes
         aShadowLaneA, aShadowLaneB, aShadowLaneC, aShadowLaneD, // output lanes
         aMagmaLaneC, aMagmaLaneD, aPlasmaLaneC, aPlasmaLaneD, // index shuffle seeds
         aPlasmaLaneA, aPlasmaLaneB); // operation seeds
    
    TwistExpander_Achernar_Arx::KDF_C_D();
    
}

void TwistExpander_Achernar::KDF_D() {
    
    TwistExpander_Achernar_Arx::KDF_D_A();
    
    TwistExpander_Achernar_Arx::KDF_D_B();
    
    TwistExpander_Achernar_Arx::KDF_D_C();
    
    TwistDiffuse::DiffuseWithDomainWords(
         aFuseLaneA, aFuseLaneB, aFuseLaneC, aFuseLaneD,  // input lanes
         aVaporLaneA, aVaporLaneB, aVaporLaneC, aVaporLaneD, // output lanes
         aAetherLaneC, aAetherLaneD, aCelestialLaneC, aCelestialLaneD, // index shuffle seeds
         aCelestialLaneA, aCelestialLaneB); // operation seeds
    
    TwistExpander_Achernar_Arx::KDF_D_D();
    
}

void TwistExpander_Achernar::Seed() {
    
    //
    // KeyRotate A
    //
    aIngress = 0xD25857BCB91A0455ULL;
    aCarry = 0x8670F91270A66137ULL;
    aWandererA = 0xE4120F409E35BE67ULL;
    aWandererB = 0xE2E6E0EC7958C9F8ULL;
    aWandererC = 0xC54F436F09B43B8BULL;
    aWandererD = 0x9E0218618EB27F11ULL;
    aWandererE = 0xC0612F8EF94DB733ULL;
    aWandererF = 0xCE23FB57E780B2CCULL;
    aWandererG = 0xAC5058B74F0E8612ULL;
    aWandererH = 0xEDDF24BA3AA0E670ULL;
    aWandererI = 0xEDC52F6E47AAEFBCULL;
    aWandererJ = 0xF6EE6FD644EA1904ULL;
    aWandererK = 0xD5BEDF16AFC00E99ULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, aFuseLaneA, aFuseLaneB, aFuseLaneC, &(mDomainBundleEphemeral.mKeyRotateAConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, aFuseLaneA, aFuseLaneB, aFuseLaneC, &(pWorkSpace->mDomainBundle.mKeyRotateAConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateAConstants), &(pWorkSpace->mDomainBundle.mKeyRotateASalts), ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, aFuseLaneA, aFuseLaneB, aFuseLaneC, &(mDomainBundleEphemeral.mKeyRotateAConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateAConstants), &(mDomainBundleEphemeral.mKeyRotateASalts), ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aPoisonLaneA, aPoisonLaneB, aPoisonLaneC, &pWorkSpace->mDomainBundle.mKeyRotateASalts);
    //
    TwistFarmConstants::Derive(aPoisonLaneD, aFuseLaneA, aFuseLaneB, aFuseLaneC, &(pWorkSpace->mDomainBundle.mKeyRotateAConstants));
    //
    //
    ////////////////////////////////////////////////////////
    //
    // KeyRotate B
    //
    aIngress = 0xF636AA50AFD6235EULL;
    aCarry = 0x8B81B40F7FBAA681ULL;
    aWandererA = 0x8DE7F14D6A0C6079ULL;
    aWandererB = 0xDB5D11B6730A8C29ULL;
    aWandererC = 0x8A0C45EB246DA45FULL;
    aWandererD = 0xB0BE774010579A4DULL;
    aWandererE = 0xBAFD85F203CEFECCULL;
    aWandererF = 0xA545AE34D0395CB1ULL;
    aWandererG = 0x8402246770A31C0FULL;
    aWandererH = 0xF65EDB616BF73A26ULL;
    aWandererI = 0xA4C5CB2920DCA88FULL;
    aWandererJ = 0xC38870AE8C04D5C9ULL;
    aWandererK = 0x9804CA3B8D91C13CULL;
    //
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aHeartLaneA, aHeartLaneB, aHeartLaneC, &mDomainBundleEphemeral.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aHeartLaneD, aFuseLaneA, aFuseLaneB, aFuseLaneC, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    //
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aWoodLaneA, aWoodLaneB, aWoodLaneC, &pWorkSpace->mDomainBundle.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aWoodLaneD, aFuseLaneA, aFuseLaneB, aFuseLaneC, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants));
    //
    KDF_C(pWorkSpace, pNonce, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants), &(pWorkSpace->mDomainBundle.mKeyRotateBSalts), ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, &mDomainBundleEphemeral.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aCrystalLaneD, aFuseLaneA, aFuseLaneB, aFuseLaneC, &(mDomainBundleEphemeral.mKeyRotateBConstants));
    //
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mKeyRotateBConstants), &(mDomainBundleEphemeral.mKeyRotateBSalts), ARX_STATE_VARS);
    //
    pFarmSalt->DeriveThree(aPoisonLaneA, aPoisonLaneB, aPoisonLaneC, &pWorkSpace->mDomainBundle.mKeyRotateBSalts);
    //
    TwistFarmConstants::Derive(aPoisonLaneD, aFuseLaneA, aFuseLaneB, aFuseLaneC, &(pWorkSpace->mDomainBundle.mKeyRotateBConstants));
    //
    //
    ////////////////////////////////////////////////////////
    
    aIngress = 0xE6684B20D5A78A4CULL;
    aCarry = 0xD601A6181DD50914ULL;
    aWandererA = 0xB962A968BD9C326CULL;
    aWandererB = 0x8CDD9A1CC58ADE67ULL;
    aWandererC = 0x848C9E2D9D72BEB3ULL;
    aWandererD = 0xF6914F2AAAB24D0EULL;
    aWandererE = 0xE37E289651694ABCULL;
    aWandererF = 0xC144759A6ED41AB7ULL;
    aWandererG = 0xC943F6A56C9BF9BEULL;
    aWandererH = 0xC9FFB71B18AFC984ULL;
    aWandererI = 0x8AEC485294524820ULL;
    aWandererJ = 0xCC6F4E95E4D7F853ULL;
    aWandererK = 0xE4FB6D52DC10A88FULL;
    //
    TwistExpander_Achernar_Arx::SEED_A();
    
    TwistExpander_Achernar_Arx::SEED_B();
    
    TwistExpander_Achernar_Arx::SEED_C();
    
    TwistDiffuse::DiffuseWithDomainWords(
         aFuseLaneA, aFuseLaneB, aFuseLaneC, aFuseLaneD,  // input lanes
         aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, // output lanes
         aPlasmaLaneC, aPlasmaLaneD, aMagmaLaneC, aMagmaLaneD, // index shuffle seeds
         aMagmaLaneA, aMagmaLaneB); // operation seeds
    
    TwistExpander_Achernar_Arx::SEED_D();
    
    TwistExpander_Achernar_Arx::SEED_E();
    
    TwistExpander_Achernar_Arx::SEED_F();
    
    TwistDiffuse::DiffuseWithDomainWords(
         aFuseLaneA, aFuseLaneB, aFuseLaneC, aFuseLaneD,  // input lanes
         aWindLaneA, aWindLaneB, aWindLaneC, aWindLaneD, // output lanes
         aCrystalLaneC, aCrystalLaneD, aEarthLaneC, aEarthLaneD, // index shuffle seeds
         aEarthLaneA, aEarthLaneB); // operation seeds
    
    TwistExpander_Achernar_Arx::SEED_G();
    
    TwistExpander_Achernar_Arx::SEED_H();
    
    TwistExpander_Achernar_Arx::SEED_I();
    
    TwistDiffuse::DiffuseWithDomainWords(
         aFuseLaneA, aFuseLaneB, aFuseLaneC, aFuseLaneD,  // input lanes
         aCelestialLaneA, aCelestialLaneB, aCelestialLaneC, aCelestialLaneD, // output lanes
         aAetherLaneC, aAetherLaneD, aFireLaneC, aFireLaneD, // index shuffle seeds
         aFireLaneA, aFireLaneB); // operation seeds
    
    TwistExpander_Achernar_Arx::SEED_J();
    
    TwistExpander_Achernar_Arx::SEED_K();
    
    TwistExpander_Achernar_Arx::SEED_L();
    
    TwistDiffuse::DiffuseWithDomainWords(
         aFuseLaneA, aFuseLaneB, aFuseLaneC, aFuseLaneD,  // input lanes
         aWoodLaneA, aWoodLaneB, aWoodLaneC, aWoodLaneD, // output lanes
         aLightningLaneC, aLightningLaneD, aIceLaneC, aIceLaneD, // index shuffle seeds
         aIceLaneA, aIceLaneB); // operation seeds
    
    TwistExpander_Achernar_Arx::SEED_M();
    
    TwistExpander_Achernar_Arx::SEED_N();
    
    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Achernar_Arx::KEY_A_A();
    TwistExpander_Achernar_Arx::KEY_A_B();
    TwistExpander_Achernar_Arx::KEY_A_C();
    TwistExpander_Achernar_Arx::KEY_A_D();
    TwistExpander_Achernar_Arx::KEY_A_E();
    TwistExpander_Achernar_Arx::KEY_A_F();
    TwistExpander_Achernar_Arx::KEY_A_G();
    TwistExpander_Achernar_Arx::KEY_A_H();
    
    TwistExpander_Achernar_Arx::KEY_B_A();
    TwistExpander_Achernar_Arx::KEY_B_B();
    TwistExpander_Achernar_Arx::KEY_B_C();
    TwistExpander_Achernar_Arx::KEY_B_D();
    TwistExpander_Achernar_Arx::KEY_B_E();
    TwistExpander_Achernar_Arx::KEY_B_F();
    TwistExpander_Achernar_Arx::KEY_B_G();
    TwistExpander_Achernar_Arx::KEY_B_H();
    
    TwistSquash::SquashB(pWorkSpace->mPoisonLaneA, pWorkSpace->mPoisonLaneB, pWorkSpace->mPoisonLaneC, pWorkSpace->mPoisonLaneD, pDestination);
    
    GrowKeyA();
    
    GrowKeyB();
    
    FoldKeyRows(pWorkSpace);
    
    pWorkSpace->Zero_PostSeed();
    
    Zero_PostSeed();
}

void TwistExpander_Achernar::TwistBlock() {
    
    TwistExpander_Achernar_Arx::TWIST_A();
    
    TwistExpander_Achernar_Arx::TWIST_B();
    
    TwistExpander_Achernar_Arx::TWIST_C();
    
    TwistDiffuse::DiffuseWithDomainWords(
         aFuseLaneA, aFuseLaneB, aFuseLaneC, aFuseLaneD,  // input lanes
         aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, // output lanes
         aFireLaneC, aFireLaneD, aWaterLaneC, aWaterLaneD, // index shuffle seeds
         aWaterLaneA, aWaterLaneB); // operation seeds
    
    TwistExpander_Achernar_Arx::TWIST_D();
    
    TwistExpander_Achernar_Arx::TWIST_E();
    
    TwistExpander_Achernar_Arx::TWIST_F();
    
    TwistDiffuse::DiffuseWithDomainWords(
         aFuseLaneA, aFuseLaneB, aFuseLaneC, aFuseLaneD,  // input lanes
         aWoodLaneA, aWoodLaneB, aWoodLaneC, aWoodLaneD, // output lanes
         aLightningLaneC, aLightningLaneD, aIceLaneC, aIceLaneD, // index shuffle seeds
         aIceLaneA, aIceLaneB); // operation seeds
    
    TwistExpander_Achernar_Arx::TWIST_G();
    
    TwistExpander_Achernar_Arx::TWIST_H();
    
    TwistSquash::SquashA(pWorkSpace->mPoisonLaneA, pWorkSpace->mPoisonLaneB, pWorkSpace->mPoisonLaneC, pWorkSpace->mPoisonLaneD, pDestination);
    
    GrowKeyA();
    
    GrowKeyB();
    
    FoldKeyRows(pWorkSpace);
}

void TwistExpander_Achernar::GrowKeyA() {
    
    TwistExpander_Achernar_Arx::GROW_A_A();
    
    TwistExpander_Achernar_Arx::GROW_A_B();
    
    TwistExpander_Achernar_Arx::GROW_A_C();
    
    TwistDiffuse::DiffuseWithDomainWords(
         aFuseLaneA, aFuseLaneB, aFuseLaneC, aFuseLaneD,  // input lanes
         aVaporLaneA, aVaporLaneB, aVaporLaneC, aVaporLaneD, // output lanes
         aShadowLaneC, aShadowLaneD, aWindLaneC, aWindLaneD, // index shuffle seeds
         aWindLaneA, aWindLaneB); // operation seeds
    
    TwistExpander_Achernar_Arx::GROW_A_D();
}

void TwistExpander_Achernar::GrowKeyB() {
    
    TwistExpander_Achernar_Arx::GROW_B_A();
    
    TwistExpander_Achernar_Arx::GROW_B_B();
    
    TwistExpander_Achernar_Arx::GROW_B_C();
    
    TwistDiffuse::DiffuseWithDomainWords(
         aFuseLaneA, aFuseLaneB, aFuseLaneC, aFuseLaneD,  // input lanes
         aChanceLaneA, aChanceLaneB, aChanceLaneC, aChanceLaneD, // output lanes
         aKineticLaneC, aKineticLaneD, aCelestialLaneC, aCelestialLaneD, // index shuffle seeds
         aCelestialLaneA, aCelestialLaneB); // operation seeds
    
    TwistExpander_Achernar_Arx::GROW_B_D();
    
}
