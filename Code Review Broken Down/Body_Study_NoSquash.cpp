
void TwistExpander_Arcturus::KDF_A() {
    
    TwistExpander_Arcturus_Arx::KDF_A_A();
    
    TwistExpander_Arcturus_Arx::KDF_A_B();
    
    TwistExpander_Arcturus_Arx::KDF_A_C();
    
    TwistExpander_Arcturus_Arx::KDF_A_D();
    
    
    TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,  // input lanes
                                         aWindLaneA, aWindLaneB); // output lanes
    
    
    TwistDiffuse::DiffuseWithDomainWords(aFuseLaneC, aFuseLaneD,  // input lanes
                                         aWindLaneC, aWindLaneD); // output lanes
    
    TwistExpander_Arcturus_Arx::KDF_A_E();
    
}

void TwistExpander_Arcturus::KDF_B() {
    
    TwistExpander_Arcturus_Arx::KDF_B_A();
    
    TwistExpander_Arcturus_Arx::KDF_B_B();
    
    TwistExpander_Arcturus_Arx::KDF_B_C();
    
    TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,  // input lanes
                                         aWorkLaneA, aWorkLaneB); // output lanes
    
    
    TwistDiffuse::DiffuseWithDomainWords(aFuseLaneC, aFuseLaneD,  // input lanes
                                         aWorkLaneC, aWorkLaneD); // output lanes
    
    TwistExpander_Arcturus_Arx::KDF_B_D();
}

void TwistExpander_Arcturus::Seed() {
    
    TwistSnow::AES256Counter(aSource, aSnowLaneA);
    TwistSnow::Sha256Counter(aSource, aSnowLaneB);
    TwistSnow::Aria256Counter(aSource, aSnowLaneC);
    TwistSnow::ChaCha20Counter(aSource, aSnowLaneD);
    
    ////////////////////////////////////////////////////////
    ////////        Phase A
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseAConstants), &(mDomainBundleInbuilt.mPhaseASalts), aSnowLaneD, 0);
    
    pFarmSalt->Derive(aWaterLaneA, mDomainBundleEphemeral.mPhaseASalts);
    pFarmSalt->Derive(aWaterLaneB, mDomainBundleEphemeral.mPhaseASalts);
    pFarmSalt->Derive(aWaterLaneC, mDomainBundleEphemeral.mPhaseASalts);
    
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseAConstants));
    
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseAConstants), &(mDomainBundleEphemeral.mPhaseASalts), 0);
    
    TwistSquash::SquashB(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneA);
    
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseASalts);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseASalts);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseASalts);
    
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseAConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////
    ////////        Phase B
    ////////
    KDF_A(pNonce, &(mDomainBundleInbuilt.mPhaseBConstants), &(mDomainBundleInbuilt.mPhaseBSalts), aSnowLaneA, 1);
    
    pFarmSalt->Derive(aWaterLaneA, mDomainBundleEphemeral.mPhaseBSalts);
    pFarmSalt->Derive(aWaterLaneB, mDomainBundleEphemeral.mPhaseBSalts);
    pFarmSalt->Derive(aWaterLaneC, mDomainBundleEphemeral.mPhaseBSalts);
    
    TwistFarmConstants::Derive(aWaterLaneD, &(mDomainBundleEphemeral.mPhaseBConstants));
    
    KDF_B(pNonce, &(mDomainBundleEphemeral.mPhaseBConstants), &(mDomainBundleEphemeral.mPhaseBSalts), 1);
    
    TwistSquash::SquashA(aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneB);
    
    pFarmSalt->Derive(aExpandLaneA, pWorkSpace->mDomainBundle.mPhaseBSalts);
    pFarmSalt->Derive(aExpandLaneB, pWorkSpace->mDomainBundle.mPhaseBSalts);
    pFarmSalt->Derive(aExpandLaneC, pWorkSpace->mDomainBundle.mPhaseBSalts);
    
    TwistFarmConstants::Derive(aExpandLaneD, &(pWorkSpace->mDomainBundle.mPhaseBConstants));
    ////////
    ////////
    ////////////////////////////////////////////////////////
    
    
    SquashInvestToKeyBoxes();
    
    TwistExpander_Arcturus_Arx::Seed_A();
    
    TwistExpander_Arcturus_Arx::Seed_B();
    
    TwistExpander_Arcturus_Arx::Seed_C();
    
    TwistExpander_Arcturus_Arx::Seed_D();
    
    TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,  // input lanes
                                         aFireLaneA, aFireLaneB); // output lanes
    
    TwistDiffuse::DiffuseWithDomainWords(aFuseLaneC, aFuseLaneD,  // input lanes
                                         aFireLaneC, aFireLaneD); // output lanes
    
    TwistExpander_Arcturus_Arx::Seed_E();
    
    TwistExpander_Arcturus_Arx::Seed_F();
    
    TwistExpander_Arcturus_Arx::Seed_G();
    
    TwistExpander_Arcturus_Arx::Seed_H();
    
    TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,  // input lanes
                                         aInvestLaneE, aInvestLaneF); // output lanes
    
    TwistDiffuse::DiffuseWithDomainWords(aFuseLaneC, aFuseLaneD,  // input lanes
                                         aInvestLaneG, aInvestLaneH); // output lanes
    
    TwistExpander_Arcturus_Arx::Seed_I();
    
    TwistSquash::SquashB(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
    
    TwistExpander_Arcturus_Arx::GROW_A();
    
    GrowKeyA(pWorkSpace);
    
    TwistExpander_Arcturus_Arx::GROW_B();
    
    GrowKeyB(pWorkSpace);
    
    Zero_PostSeed();
}

void TwistExpander_Arcturus::TwistBlock() {
    
    TwistExpander_Arcturus_Arx::Twist_A();
    
    TwistExpander_Arcturus_Arx::Twist_B();
    
    TwistExpander_Arcturus_Arx::Twist_C();
    
    TwistExpander_Arcturus_Arx::Twist_D();
    
    TwistExpander_Arcturus_Arx::Twist_E();
    
    TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,  // input lanes
                                         aFireLaneA, aFireLaneB); // output lanes
    
    TwistDiffuse::DiffuseWithDomainWords(aFuseLaneC, aFuseLaneD,  // input lanes
                                         aFireLaneC, aFireLaneD); // output lanes
    
    TwistExpander_Arcturus_Arx::Twist_F();
    
    TwistExpander_Arcturus_Arx::Twist_G();
    
    TwistSquash::SquashA(aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD, pDestination);
    
    TwistExpander_Arcturus_Arx::GROW_A();
    
    GrowKeyA(pWorkSpace);
    
    TwistExpander_Arcturus_Arx::GROW_B();
    
    GrowKeyB(pWorkSpace);
}
