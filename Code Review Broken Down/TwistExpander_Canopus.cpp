

void TwistExpander_Canopus::KDF_A() {
    
    
    TwistExpander_Canopus_Arx::KDF_A_A(pWorkSpace,
                                       pNonce,
                                       pConstants,
                                       pDomainSaltSet,
                                       pSnowLaneA);
    
    TwistExpander_Canopus_Arx::KDF_A_B(pWorkSpace,
                                       pNonce,
                                       pConstants,
                                       pDomainSaltSet,
                                       pSnowLaneA);
    
    TwistExpander_Canopus_Arx::KDF_A_C(pWorkSpace,
                                       pNonce,
                                       pConstants,
                                       pDomainSaltSet,
                                       pSnowLaneA);
    
    TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                                         aFuseLaneC, aFuseLaneD,  // input lanes
                                         aWaterLaneA, aWaterLaneB,
                                         aWaterLaneC, aWaterLaneD); // matrix args
    
    TwistExpander_Canopus_Arx::KDF_A_D(pWorkSpace,
                                       pNonce,
                                       pConstants,
                                       pDomainSaltSet,
                                       pSnowLaneA);
    
}

void TwistExpander_Canopus::KDF_B() {
    
    TwistExpander_Canopus_Arx::KDF_B_A(pWorkSpace,
                                       pNonce,
                                       pConstants,
                                       pDomainSaltSet,
                                       pSnowLaneA);
    
    TwistExpander_Canopus_Arx::KDF_B_B(pWorkSpace,
                                       pNonce,
                                       pConstants,
                                       pDomainSaltSet,
                                       pSnowLaneA);
    
    TwistExpander_Canopus_Arx::KDF_B_C(pWorkSpace,
                                       pNonce,
                                       pConstants,
                                       pDomainSaltSet,
                                       pSnowLaneA);
    
    TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                                         aFuseLaneC, aFuseLaneD,  // input lanes
                                         aIceLaneA, aIceLaneB,
                                         aIceLaneC, aIceLaneD); // matrix args
    
    TwistExpander_Canopus_Arx::KDF_B_D(pWorkSpace,
                                       pNonce,
                                       pConstants,
                                       pDomainSaltSet,
                                       pSnowLaneA);
    
}

void TwistExpander_Canopus::KDF_C() {

    TwistExpander_Canopus_Arx::KDF_C_A(pWorkSpace,
                                       pNonce,
                                       pConstants,
                                       pDomainSaltSet,
                                       pSnowLaneA);
    
    TwistExpander_Canopus_Arx::KDF_C_B(pWorkSpace,
                                       pNonce,
                                       pConstants,
                                       pDomainSaltSet,
                                       pSnowLaneA);
    
    TwistExpander_Canopus_Arx::KDF_C_C(pWorkSpace,
                                       pNonce,
                                       pConstants,
                                       pDomainSaltSet,
                                       pSnowLaneA);
    
    TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                                         aFuseLaneC, aFuseLaneD,  // input lanes
                                         aShadowLaneA, aShadowLaneB,
                                         aShadowLaneC, aShadowLaneD) // matrix args
    
    TwistExpander_Canopus_Arx::KDF_C_D(pWorkSpace,
                                       pNonce,
                                       pConstants,
                                       pDomainSaltSet,
                                       pSnowLaneA);
    
}

void TwistExpander_Canopus::KDF_D() {
    
    TwistExpander_Canopus_Arx::KDF_D_A(pWorkSpace,
                                       pNonce,
                                       pConstants,
                                       pDomainSaltSet,
                                       pSnowLaneA);
    
    TwistExpander_Canopus_Arx::KDF_D_B(pWorkSpace,
                                       pNonce,
                                       pConstants,
                                       pDomainSaltSet,
                                       pSnowLaneA);
    
    TwistExpander_Canopus_Arx::KDF_D_C(pWorkSpace,
                                       pNonce,
                                       pConstants,
                                       pDomainSaltSet,
                                       pSnowLaneA);
    
    TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                                         aFuseLaneC, aFuseLaneD,  // input lanes
                                         aVaporLaneA, aVaporLaneB,
                                         aVaporLaneC, aVaporLaneD); // matrix args
    
    TwistExpander_Canopus_Arx::KDF_D_D(pWorkSpace,
                                       pNonce,
                                       pConstants,
                                       pDomainSaltSet,
                                       pSnowLaneA);
    
}

void TwistExpander_Canopus::Seed() {
    
    KDF_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), pSnowLaneA, pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    ////////
    pFarmSalt->Derive(aHeartLaneA, mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltA);
    pFarmSalt->Derive(aHeartLaneB, mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltA);
    pFarmSalt->Derive(aHeartLaneC, mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltA);
    ////////
    TwistFarmConstants::Derive(aHeartLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    ////////
    KDF_B(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneA, pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    ////////
    // wood lanes to pWorkSpace->mDomainBundle
    pFarmSalt->Derive(aWoodLaneA, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltA);
    pFarmSalt->Derive(aWoodLaneB, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltA);
    pFarmSalt->Derive(aWoodLaneC, pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltA);
    TwistFarmConstants::Derive(aWoodLaneD, &(pWorkSpace->mDomainBundle.mTwistConstants));
    ////////
    KDF_C(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneA, pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    ////////
    // crystal lanes to mDomainBundleEphemeral
    pFarmSalt->Derive(aCrystalLaneA, mDomainBundleEphemeral.mTwistSalts.mOrbiterAssign.mSaltA);
    pFarmSalt->Derive(aCrystalLaneB, mDomainBundleEphemeral.mTwistSalts.mOrbiterUpdate.mSaltA);
    pFarmSalt->Derive(aCrystalLaneC, mDomainBundleEphemeral.mTwistSalts.mWandererUpdate.mSaltA);
    TwistFarmConstants::Derive(aCrystalLaneD, &(mDomainBundleEphemeral.mTwistConstants));
    ////////
    KDF_D(pWorkSpace, pNonce, &(mDomainBundleEphemeral.mTwistConstants), &(mDomainBundleEphemeral.mTwistSalts), pSnowLaneA, pSnowLaneB, pSnowLaneC, ARX_STATE_VARS);
    ////////
    // poison lanes to pWorkSpace->mDomainBundle
    pFarmSalt->Derive(aPoisonLaneA, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltA);
    pFarmSalt->Derive(aPoisonLaneB, pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltA);
    pFarmSalt->Derive(aPoisonLaneC, pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltA);
    TwistFarmConstants::Derive(aPoisonLaneD, &(pWorkSpace->mDomainBundle.mTwistConstants));
    ////////
    ////////
    ////////
    ////////////////////////////////////////////////////////
    
    TwistExpander_Canopus_Arx::SEED_A();
    
    TwistExpander_Canopus_Arx::SEED_B();
    
    TwistExpander_Canopus_Arx::SEED_C();
    
    TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                                         aFuseLaneC, aFuseLaneD,  // input lanes
                                         aHeartLaneA, aHeartLaneB,
                                         aHeartLaneC, aHeartLaneD); // matrix args
    
    TwistExpander_Canopus_Arx::SEED_D();
    
    TwistExpander_Canopus_Arx::SEED_E();
    
    TwistExpander_Canopus_Arx::SEED_F();
    
    //
    TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                                         aFuseLaneC, aFuseLaneD,  // input lanes
                                         aWindLaneA, aWindLaneB,
                                         aWindLaneC, aWindLaneD); // matrix args
    
    TwistExpander_Canopus_Arx::SEED_G();
    
    TwistExpander_Canopus_Arx::SEED_H();
    
    TwistExpander_Canopus_Arx::SEED_I();
    
    //
    TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                                         aFuseLaneC, aFuseLaneD,  // input lanes
                                         aCelestialLaneA, aCelestialLaneB,
                                         aCelestialLaneC, aCelestialLaneD); // matrix args
    
    TwistExpander_Canopus_Arx::SEED_J();
    
    TwistExpander_Canopus_Arx::SEED_K();
    
    TwistExpander_Canopus_Arx::SEED_L();
    
    //
    TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                                         aFuseLaneC, aFuseLaneD,  // input lanes
                                         aWoodLaneA, aWoodLaneB,
                                         aWoodLaneC, aWoodLaneD); // matrix args
    
    TwistExpander_Canopus_Arx::SEED_M();
    
    TwistExpander_Canopus_Arx::SEED_N();
    
    //
    // [KEY — sixteen key-row functions, lane splits A-P]
    //
    TwistExpander_Canopus_Arx::KEY_A_A();
    
    TwistExpander_Canopus_Arx::KEY_A_B();
    
    TwistExpander_Canopus_Arx::KEY_A_C();
    
    TwistExpander_Canopus_Arx::KEY_A_D();
    
    TwistExpander_Canopus_Arx::KEY_A_E();
    
    TwistExpander_Canopus_Arx::KEY_A_F();
    
    TwistExpander_Canopus_Arx::KEY_A_G();
    
    TwistExpander_Canopus_Arx::KEY_A_H();
    
    TwistExpander_Canopus_Arx::KEY_B_A();
    
    TwistExpander_Canopus_Arx::KEY_B_B();
    
    TwistExpander_Canopus_Arx::KEY_B_C();
    
    TwistExpander_Canopus_Arx::KEY_B_D();
    
    TwistExpander_Canopus_Arx::KEY_B_E();
    
    TwistExpander_Canopus_Arx::KEY_B_F();
    
    TwistExpander_Canopus_Arx::KEY_B_G();
    
    TwistExpander_Canopus_Arx::KEY_B_H();
    
    TwistSquash::SquashA(pWorkSpace->mPoisonLaneA, pWorkSpace->mPoisonLaneB, pWorkSpace->mPoisonLaneC, pWorkSpace->mPoisonLaneD, pDestination);
    
    GrowKeyA(pWorkSpace,
             ARX_STATE_VARS);
    
    GrowKeyB(pWorkSpace,
             ARX_STATE_VARS);
    
    FoldKeyRows(pWorkSpace);
    
    pWorkSpace->Zero_PostSeed();
    
    Zero_PostSeed();
}

void TwistExpander_Canopus::TwistBlock() {
    
    TwistExpander_Canopus_Arx::TWIST_A(pWorkSpace,
                                       pSource,
                                       pSnowLaneA,
                                       pSnowLaneB,
                                       pSnowLaneC,
                                       pSnowLaneD,
                                       ARX_STATE_VARS);
    
    TwistExpander_Canopus_Arx::TWIST_B(pWorkSpace,
                                       pSource,
                                       pSnowLaneA,
                                       pSnowLaneB,
                                       pSnowLaneC,
                                       pSnowLaneD,
                                       ARX_STATE_VARS);
    
    TwistExpander_Canopus_Arx::TWIST_C(pWorkSpace,
                                       pSource,
                                       pSnowLaneA,
                                       pSnowLaneB,
                                       pSnowLaneC,
                                       pSnowLaneD,
                                       ARX_STATE_VARS);
    
    TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                                         aFuseLaneC, aFuseLaneD,  // input lanes
                                         aHeartLaneA, aHeartLaneB,
                                         aHeartLaneC, aHeartLaneD); // matrix args
    //
    TwistExpander_Canopus_Arx::TWIST_D(pWorkSpace,
                                       pSource,
                                       pSnowLaneA,
                                       pSnowLaneB,
                                       pSnowLaneC,
                                       pSnowLaneD,
                                       ARX_STATE_VARS);
    
    TwistExpander_Canopus_Arx::TWIST_E(pWorkSpace,
                                       pSource,
                                       pSnowLaneA,
                                       pSnowLaneB,
                                       pSnowLaneC,
                                       pSnowLaneD,
                                       ARX_STATE_VARS);
    
    TwistExpander_Canopus_Arx::TWIST_F(pWorkSpace,
                                       pSource,
                                       pSnowLaneA,
                                       pSnowLaneB,
                                       pSnowLaneC,
                                       pSnowLaneD,
                                       ARX_STATE_VARS);
    
    //
    TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                                         aFuseLaneC, aFuseLaneD,  // input lanes
                                         aWoodLaneA, aWoodLaneB,
                                         aWoodLaneC, aWoodLaneD); // matrix args
    //
    TwistExpander_Canopus_Arx::TWIST_G(pWorkSpace,
                                       pSource,
                                       pSnowLaneA,
                                       pSnowLaneB,
                                       pSnowLaneC,
                                       pSnowLaneD,
                                       ARX_STATE_VARS);
    
    TwistExpander_Canopus_Arx::TWIST_H(pWorkSpace,
                                       pSource,
                                       pSnowLaneA,
                                       pSnowLaneB,
                                       pSnowLaneC,
                                       pSnowLaneD,
                                       ARX_STATE_VARS);
    
    TwistSquash::SquashB(pWorkSpace->mPoisonLaneA, pWorkSpace->mPoisonLaneB, pWorkSpace->mPoisonLaneC, pWorkSpace->mPoisonLaneD, pDestination);
    
    GrowKeyA(pWorkSpace,
             ARX_STATE_VARS);
    
    GrowKeyB(pWorkSpace,
             ARX_STATE_VARS);
    
    FoldKeyRows(pWorkSpace);
}

void TwistExpander_Canopus::GrowKeyA() {
    
    TwistExpander_Canopus_Arx::GROW_A_A(pWorkSpace);
    
    TwistExpander_Canopus_Arx::GROW_A_B(pWorkSpace);
    
    TwistExpander_Canopus_Arx::GROW_A_C(pWorkSpace);
    
    TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                                         aFuseLaneC, aFuseLaneD,  // input lanes
                                         aVaporLaneA, aVaporLaneB,
                                         aVaporLaneC, aVaporLaneD); // matrix args
    //
    TwistExpander_Canopus_Arx::GROW_A_D(pWorkSpace);
    
}

void TwistExpander_Canopus::GrowKeyB() {

    TwistExpander_Canopus_Arx::GROW_B_A(pWorkSpace);
    
    TwistExpander_Canopus_Arx::GROW_B_B(pWorkSpace);
    
    TwistExpander_Canopus_Arx::GROW_B_C(pWorkSpace);
    
    TwistDiffuse::DiffuseWithDomainWords(aFuseLaneA, aFuseLaneB,
                                         aFuseLaneC, aFuseLaneD,  // input lanes
                                         aChanceLaneA, aChanceLaneB,
                                         aChanceLaneC, aChanceLaneD); // matrix args
    //
    TwistExpander_Canopus_Arx::GROW_B_D(pWorkSpace);
    
}
