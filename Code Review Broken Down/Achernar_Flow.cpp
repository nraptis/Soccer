
void TwistExpander_Achernar::KDF_A() {
    
    TwistExpander_Achernar_Arx::KDF_A_A();
    
    TwistExpander_Achernar_Arx::KDF_A_B();
    
    TwistExpander_Achernar_Arx::KDF_A_C();
    
    TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,  // input lanes
                                         aWindLaneA, aWindLaneB, // output lanes
                                         aFireLaneA, aFireLaneB, // index shuffle seeds
                                         aFireLaneC, aFireLaneD) // operation seeds
    
    TwistDiffuse::DiffuseWithDomainWords(aFuseLaneC, aFuseLaneD,  // input lanes
                                         aWindLaneC, aWindLaneD, // output lanes
                                         aFireLaneC, aFireLaneD, // index shuffle seeds
                                         aFireLaneA, aFireLaneB) // operation seeds
    
    TwistExpander_Achernar_Arx::KDF_A_D();
    
}

void TwistExpander_Achernar::KDF_B() {
    
    TwistExpander_Achernar_Arx::KDF_B_A();
    
    TwistExpander_Achernar_Arx::KDF_B_B();
    
    TwistExpander_Achernar_Arx::KDF_B_C();
    
    TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,  // input lanes
                                         aPoisonLaneA, aPoisonLaneB, // output lanes
                                         aSpiritLaneA, aSpiritLaneB, // index shuffle seeds
                                         aSpiritLaneC, aSpiritLaneD); // operation seeds
    
    TwistDiffuse::DiffuseWithDomainWords(aFuseLaneC, aFuseLaneD,  // input lanes
                                         aPoisonLaneC, aPoisonLaneD, // output lanes
                                         aSpiritLaneC, aSpiritLaneD, // index shuffle seeds
                                         aSpiritLaneA, aSpiritLaneB); // operation seeds
    
    TwistExpander_Achernar_Arx::KDF_B_D();
    
}

void TwistExpander_Achernar::Seed() {
    
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), pSnowLaneC, 0);
    ////////
    pFarmSalt->Derive(aWaterLaneA);
    pFarmSalt->Derive(aWaterLaneB);
    pFarmSalt->Derive(aWaterLaneC);
    ////////
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseAConstants));
    ////////
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
    ////////
    TwistSquash::SquashA(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, aIceLaneA);
    ////////
    pFarmSalt->Derive(aHeartLaneA);
    pFarmSalt->Derive(aHeartLaneB);
    pFarmSalt->Derive(aHeartLaneC);
    ////////
    TwistFarmConstants::Derive(aHeartLaneD, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase B
    ////////
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), pSnowLaneA, 1);
    ////////
    pFarmSalt->Derive(aWaterLaneA);
    pFarmSalt->Derive(aWaterLaneB);
    pFarmSalt->Derive(aWaterLaneC);
    ////////
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseBConstants));
    ////////
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
    ////////
    TwistSquash::SquashC(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, aIceLaneB);
    ////////
    pFarmSalt->Derive(aHeartLaneA);
    pFarmSalt->Derive(aHeartLaneB);
    pFarmSalt->Derive(aHeartLaneC);
    ////////
    TwistFarmConstants::Derive(aHeartLaneD, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    ////////
    ////////
    
    SquashInvestToKeyBoxes(pWorkSpace);
    
    //
    TwistExpander_Achernar_Arx::Seed_A();
    
    TwistExpander_Achernar_Arx::Seed_B();
    
    TwistExpander_Achernar_Arx::Seed_C();

    TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,  // input lanes
                                         aWindLaneA, aWindLaneB, // output lanes
                                         aFireLaneC, aFireLaneD, // index shuffle seeds
                                         aFireLaneA, aFireLaneB); // operation seeds
    
    TwistDiffuse::DiffuseWithDomainWords(aFuseLaneC, aFuseLaneD,  // input lanes
                                         aWindLaneC, aWindLaneD, // output lanes
                                         aFireLaneA, aFireLaneB, // index shuffle seeds
                                         aFireLaneC, aFireLaneD); // operation seeds
    
    TwistExpander_Achernar_Arx::Seed_D();
    
    TwistExpander_Achernar_Arx::Seed_E();
    
    TwistExpander_Achernar_Arx::Seed_F();
    
    TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,  // input lanes
                                         aSpiritLaneA, aSpiritLaneB, // output lanes
                                         aHeartLaneC, aHeartLaneD, // index shuffle seeds
                                         aHeartLaneA, aHeartLaneB); // operation seeds
    
    TwistDiffuse::DiffuseWithDomainWords(aFuseLaneC, aFuseLaneD,  // input lanes
                                         aSpiritLaneC, aSpiritLaneD, // output lanes
                                         aHeartLaneA, aHeartLaneB, // index shuffle seeds
                                         aHeartLaneC, aHeartLaneD); // operation seeds
    
    TwistExpander_Achernar_Arx::Seed_G();
    
    TwistExpander_Achernar_Arx::Seed_H();
    
    TwistSquash::SquashB(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, pDestination);
    //
    //
    TwistExpander_Achernar_Arx::GROW_A();
    
    GrowKeyA(pWorkSpace);
    
    TwistExpander_Achernar_Arx::GROW_B();
    
    GrowKeyB(pWorkSpace);
    
    pWorkSpace->Zero_PostSeed();
    
    Zero_PostSeed();
}

void TwistExpander_Achernar::TwistBlock() {
    
    TwistExpander_Achernar_Arx::Twist_A();
    
    TwistExpander_Achernar_Arx::Twist_B();
    
    TwistExpander_Achernar_Arx::Twist_C();
    
    TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,  // input lanes
                                         aWindLaneA, aWindLaneB, // output lanes
                                         aFireLaneC, aFireLaneD, // index shuffle seeds
                                         aFireLaneA, aFireLaneB); // operation seeds
    
    TwistDiffuse::DiffuseWithDomainWords(aFuseLaneC, aFuseLaneD,  // input lanes
                                         aWindLaneC, aWindLaneD, // output lanes
                                         aFireLaneA, aFireLaneB, // index shuffle seeds
                                         aFireLaneC, aFireLaneD); // operation seeds
    
    TwistExpander_Achernar_Arx::Twist_D();
    
    TwistExpander_Achernar_Arx::Twist_E();
    
    TwistSquash::SquashB(aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, pDestination);
    
    TwistExpander_Achernar_Arx::GROW_A();
    
    GrowKeyA(pWorkSpace);
    
    TwistExpander_Achernar_Arx::GROW_B();
    
    GrowKeyB(pWorkSpace);
}
