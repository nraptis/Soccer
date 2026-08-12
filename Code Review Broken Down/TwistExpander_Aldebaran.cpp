
void TwistExpander_Aldebaran::KDF_A_A() {

    TwistExpander_Aldebaran_Arx::KDF_A_A_A(PARAMS_KDF);

    TwistExpander_Aldebaran_Arx::KDF_A_B_A(PARAMS_KDF);

    TwistDiffuse::DiffuseWithDomainWords(
        aSpiritLaneA, aSpiritLaneB, aSpiritLaneC, aSpiritLaneD,  // input lanes
        aEarthLaneA, aEarthLaneB, aEarthLaneC, aEarthLaneD, // output lanes
        aWaterLaneA, aWaterLaneB, aWaterLaneC, aWaterLaneD); // entropy lanes
    
    TwistExpander_Aldebaran_Arx::KDF_A_C_A(PARAMS_KDF);

}

void TwistExpander_Aldebaran::KDF_B_A() {
    
    TwistExpander_Aldebaran_Arx::KDF_B_A_A(PARAMS_KDF);

    TwistExpander_Aldebaran_Arx::KDF_B_B_A(PARAMS_KDF);

    TwistDiffuse::DiffuseWithDomainWords(
        aLightningLaneA, aLightningLaneB, aLightningLaneC, aLightningLaneD,  // input lanes
        aWindLaneA, aWindLaneB, aWindLaneC, aWindLaneD, // output lanes
        aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, aCrystalLaneD); // entropy lanes

    TwistExpander_Aldebaran_Arx::KDF_B_C_A(PARAMS_KDF);

}

void TwistExpander_Aldebaran::KDF_C_A() {
    
    TwistExpander_Aldebaran_Arx::KDF_C_A_A(PARAMS_KDF);

    TwistExpander_Aldebaran_Arx::KDF_C_B_A(PARAMS_KDF);

    TwistDiffuse::DiffuseWithDomainWords(
        aAetherLaneA, aAetherLaneB, aAetherLaneC, aAetherLaneD,  // input lanes
        aShadowLaneA, aShadowLaneB, aShadowLaneC, aShadowLaneD, // output lanes
        aPlasmaLaneA, aPlasmaLaneB, aPlasmaLaneC, aPlasmaLaneD); // entropy lanes
    
    TwistExpander_Aldebaran_Arx::KDF_C_C_A(PARAMS_KDF);

}

void TwistExpander_Aldebaran::Seed() {


    ////////////////////////////////////////////////////////
    //
    // Secret material derivation, across 6 domains.
    //
    // Domain 6 of 6, seed:
    //
    KDF_A_F(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mSeedConstants), &(mDomainBundleInbuilt.mSeedSalts), ARX_STATE_VARS);

    TwistFarm::Farm(pFarmSalt,
                    aIceLaneB, aIceLaneC, aIceLaneD, aIceLaneA, // farm lanes
                    aFuseLaneA, aFuseLaneB, aFuseLaneC, // temp/fold lanes
                    &mDomainBundleEphemeralA.mSeedSalts,
                    &(mDomainBundleEphemeralA.mSeedConstants));

    KDF_B_F(pWorkSpace, pNonce, &(mDomainBundleEphemeralA.mSeedConstants), &(mDomainBundleEphemeralA.mSeedSalts), ARX_STATE_VARS);

    TwistFarm::Farm(pFarmSalt,
                    aVaporLaneB, aVaporLaneC, aVaporLaneD, aVaporLaneA, // farm lanes
                    aFuseLaneA, aFuseLaneB, aFuseLaneC, // temp/fold lanes
                    &mDomainBundleEphemeralB.mSeedSalts,
                    &(mDomainBundleEphemeralB.mSeedConstants));

    KDF_C_F(pWorkSpace, pNonce, &(mDomainBundleEphemeralB.mSeedConstants), &(mDomainBundleEphemeralB.mSeedSalts), ARX_STATE_VARS);

    TwistFarm::Farm(pFarmSalt,
                    aCelestialLaneB, aCelestialLaneC, aCelestialLaneD, aCelestialLaneA, // farm lanes
                    aFuseLaneA, aFuseLaneB, aFuseLaneC, // temp/fold lanes
                    &pWorkSpace->mDomainBundle.mSeedSalts,
                    &(pWorkSpace->mDomainBundle.mSeedConstants));
    //
    ////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////
    //
    // Main seed loops
    //
    TwistExpander_Aldebaran_Arx::SEED_A(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::SEED_B(PARAMS_SEED);

    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mSeedConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mSeedConstants.mMatrixSelectB;

    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mSeedConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mSeedConstants.mMatrixUnrollB;

    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mSeedConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mSeedConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mSeedConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mSeedConstants.mMatrixArgD;

    TwistDiffuse::DiffuseWithDomainWords(
        aEarthLaneA, aEarthLaneB, aEarthLaneC, aEarthLaneD,  // input lanes
        aIceLaneA, aIceLaneB, aIceLaneC, aIceLaneD, // output lanes
        aWaterLaneA, aWaterLaneB, aWaterLaneC, aWaterLaneD); // entropy lanes

    TwistExpander_Aldebaran_Arx::SEED_C(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::SEED_D(PARAMS_SEED);

    TwistDiffuse::DiffuseWithDomainWords(
        aWindLaneA, aWindLaneB, aWindLaneC, aWindLaneD,  // input lanes
        aVaporLaneA, aVaporLaneB, aVaporLaneC, aVaporLaneD, // output lanes
        aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, aCrystalLaneD); // entropy lanes
    
    TwistExpander_Aldebaran_Arx::SEED_E(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::SEED_F(PARAMS_SEED);

    TwistDiffuse::DiffuseWithDomainWords(
        aShadowLaneA, aShadowLaneB, aShadowLaneC, aShadowLaneD,  // input lanes
        aCelestialLaneA, aCelestialLaneB, aCelestialLaneC, aCelestialLaneD, // output lanes
        aPlasmaLaneA, aPlasmaLaneB, aPlasmaLaneC, aPlasmaLaneD); // entropy lanes
    
    TwistExpander_Aldebaran_Arx::SEED_G(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::SEED_H(PARAMS_SEED);

    TwistDiffuse::DiffuseWithDomainWords(
        aWaterLaneA, aWaterLaneB, aWaterLaneC, aWaterLaneD,  // input lanes
        aSpiritLaneA, aSpiritLaneB, aSpiritLaneC, aSpiritLaneD, // output lanes
        aLightningLaneA, aLightningLaneB, aLightningLaneC, aLightningLaneD); // entropy lanes

    TwistExpander_Aldebaran_Arx::SEED_I(PARAMS_SEED);

    TwistDiffuse::DiffuseWithDomainWords(
        aEarthLaneA, aEarthLaneB, aEarthLaneC, aEarthLaneD,  // input lanes
        aIceLaneA, aIceLaneB, aIceLaneC, aIceLaneD, // output lanes

    TwistExpander_Aldebaran_Arx::SEED_J(PARAMS_SEED);

    for (std::size_t aIndex = 0U; aIndex < S_BLOCK; aIndex += 1U) {
        pWorkSpace->mFireLaneA[aIndex] = pWorkSpace->mIceLaneA[S_BLOCK1 - aIndex];
        pWorkSpace->mFireLaneB[aIndex] = pWorkSpace->mIceLaneB[S_BLOCK1 - aIndex];
        pWorkSpace->mFireLaneC[aIndex] = pWorkSpace->mIceLaneC[S_BLOCK1 - aIndex];
        pWorkSpace->mFireLaneD[aIndex] = pWorkSpace->mIceLaneD[S_BLOCK1 - aIndex];
    }

    //
    ////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////
    //
    // Key entropy loops
    //
    TwistExpander_Aldebaran_Arx::KEY_A_A_A(PARAMS_SEED);

    // Key diffusion-source loops

    TwistExpander_Aldebaran_Arx::KEY_A_A_B(PARAMS_SEED);

    // Key mini-diffusion

    KeyDiffuse(pWorkSpace);

    // Final key-lane loops

    TwistExpander_Aldebaran_Arx::KEY_A_A_C(PARAMS_SEED);

    TwistSquash::SquashKeyA(ALDEBARAN_KEY_A_A_AetherLaneA,
                            ALDEBARAN_KEY_A_A_AetherLaneB,
                            ALDEBARAN_KEY_A_A_AetherLaneC,
                            ALDEBARAN_KEY_A_A_AetherLaneD,
                            &(pWorkSpace->mKeyBoxA[0U][0]));
                                         
    TwistExpander_Aldebaran_Arx::KEY_A_B_C(PARAMS_SEED);

    //
    ////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////
    //
    // Folding main seed loops into destination
    //
    TwistSquash::SquashA(pWorkSpace->mCrystalLanes, pDestination);
    //
    ////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////
    //
    // Key box management
    //
    GrowKeyA(pWorkSpace, ARX_STATE_VARS);

    TwistShiftBox::ShiftKeyBoxA(pWorkSpace);

    FoldKeyRowA(pWorkSpace);

    GrowKeyB(pWorkSpace, ARX_STATE_VARS);

    TwistShiftBox::ShiftKeyBoxB(pWorkSpace);

    FoldKeyRowB(pWorkSpace);
    //
    ////////////////////////////////////////////////////////

    pWorkSpace->Zero_PostSeed();

    Zero_PostSeed();
}

void TwistExpander_Aldebaran::TwistBlock() {

    ////////////////////////////////////////////////////////
    //
    // Main twist loops
    //
    TwistExpander_Aldebaran_Arx::TWIST_A(PARAMS_TWIST);

    TwistDiffuse::DiffuseWithDomainWords(
        aWaterLaneA, aWaterLaneB, aWaterLaneC, aWaterLaneD,  // input lanes
        aSpiritLaneA, aSpiritLaneB, aSpiritLaneC, aSpiritLaneD, // output lanes
        pCrossLaneA, pCrossLaneB, pCrossLaneC, pCrossLaneD); // entropy lanes

    TwistExpander_Aldebaran_Arx::TWIST_B(PARAMS_TWIST);

    TwistDiffuse::DiffuseWithDomainWords(
        aEarthLaneA, aEarthLaneB, aEarthLaneC, aEarthLaneD,  // input lanes
        aIceLaneA, aIceLaneB, aIceLaneC, aIceLaneD, // output lanes
        aSpiritLaneA, aSpiritLaneB, aSpiritLaneC, aSpiritLaneD); // entropy lanes

    TwistExpander_Aldebaran_Arx::TWIST_C(PARAMS_TWIST);
    //
    ////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////
    //
    // Folding main twist loops into destination
    //
    TwistSquash::SquashC(pWorkSpace->mCrystalLanes, pDestination);
    //
    ////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////
    //
    // Key box management
    //
    if (pStifleKey == true) {
        TwistShiftBox::ShiftKeyBoxA(pWorkSpace);
        TwistShiftBox::ShiftKeyBoxB(pWorkSpace);
    } else {
        for (std::size_t aIndex = 0U; aIndex < S_BLOCK; aIndex += 1U) {
            pWorkSpace->mFireLaneA[aIndex] = pWorkSpace->mIceLaneA[S_BLOCK1 - aIndex];
            pWorkSpace->mFireLaneB[aIndex] = pWorkSpace->mIceLaneB[S_BLOCK1 - aIndex];
            pWorkSpace->mFireLaneC[aIndex] = pWorkSpace->mIceLaneC[S_BLOCK1 - aIndex];
            pWorkSpace->mFireLaneD[aIndex] = pWorkSpace->mIceLaneD[S_BLOCK1 - aIndex];
        }
        
        GrowKeyA(pWorkSpace, ARX_STATE_VARS);
        TwistShiftBox::ShiftKeyBoxA(pWorkSpace);
        FoldKeyRowA(pWorkSpace);
        
        GrowKeyB(pWorkSpace, ARX_STATE_VARS);
        TwistShiftBox::ShiftKeyBoxB(pWorkSpace);
        FoldKeyRowB(pWorkSpace);
    }
    //
    ////////////////////////////////////////////////////////
}

void TwistExpander_Aldebaran::GrowKeyA() {

    TwistExpander_Aldebaran_Arx::GROW_A_A(PARAMS_GROW);

    TwistDiffuse::DiffuseWithDomainWords(
        aLightningLaneA, aLightningLaneB, aLightningLaneC, aLightningLaneD,  // input lanes
        aWindLaneA, aWindLaneB, aWindLaneC, aWindLaneD, // output lanes
        aIceLaneA, aIceLaneB, aIceLaneC, aIceLaneD); // entropy lanes
    
    TwistExpander_Aldebaran_Arx::GROW_A_B(PARAMS_GROW);

}

void TwistExpander_Aldebaran::GrowKeyB() {
    
    TwistExpander_Aldebaran_Arx::GROW_B_A(PARAMS_GROW);
    
    TwistDiffuse::DiffuseWithDomainWords(
        aPlasmaLaneA, aPlasmaLaneB, aPlasmaLaneC, aPlasmaLaneD,  // input lanes
        aAetherLaneA, aAetherLaneB, aAetherLaneC, aAetherLaneD, // output lanes
        aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD); // entropy lanes
    
    TwistExpander_Aldebaran_Arx::GROW_B_B(PARAMS_GROW);

}

void TwistExpander_Aldebaran::KeyDiffuse(TwistWorkSpace *pWorkSpace) {
    
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_A_A_AetherLaneA,
        ALDEBARAN_KEY_A_A_AetherLaneB,
        ALDEBARAN_KEY_A_A_AetherLaneC,
        ALDEBARAN_KEY_A_A_AetherLaneD,
        ALDEBARAN_KEY_A_A_CelestialLaneA,
        ALDEBARAN_KEY_A_A_CelestialLaneB,
        ALDEBARAN_KEY_A_A_CelestialLaneC,
        ALDEBARAN_KEY_A_A_CelestialLaneD,
        ALDEBARAN_KEY_A_A_EarthLaneA,
        ALDEBARAN_KEY_A_A_EarthLaneB,
        ALDEBARAN_KEY_A_A_EarthLaneC,
        ALDEBARAN_KEY_A_A_EarthLaneD,
        pWorkSpace->mIndexList256A, pWorkSpace->mIndexList256B,
        pWorkSpace->mIndexList256C, pWorkSpace->mIndexList256D,
        &mMatrix,
        pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixSelectA,
        pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixSelectB,
        pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixUnrollA,
        pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixUnrollB,
        pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixArgA,
        pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixArgB,
        pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixArgC,
        pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixArgD);
    
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_B_A_AetherLaneA,
        ALDEBARAN_KEY_B_A_AetherLaneB,
        ALDEBARAN_KEY_B_A_AetherLaneC,
        ALDEBARAN_KEY_B_A_AetherLaneD,
        ALDEBARAN_KEY_B_A_CelestialLaneA,
        ALDEBARAN_KEY_B_A_CelestialLaneB,
        ALDEBARAN_KEY_B_A_CelestialLaneC,
        ALDEBARAN_KEY_B_A_CelestialLaneD,
        ALDEBARAN_KEY_B_A_EarthLaneA,
        ALDEBARAN_KEY_B_A_EarthLaneB,
        ALDEBARAN_KEY_B_A_EarthLaneC,
        ALDEBARAN_KEY_B_A_EarthLaneD,
        pWorkSpace->mIndexList256A, pWorkSpace->mIndexList256B,
        pWorkSpace->mIndexList256C, pWorkSpace->mIndexList256D,
        &mMatrix,
        pWorkSpace->mDomainBundle.mKeySpawnBConstants.mMatrixSelectA,
        pWorkSpace->mDomainBundle.mKeySpawnBConstants.mMatrixSelectB,
        pWorkSpace->mDomainBundle.mKeySpawnBConstants.mMatrixUnrollA,
        pWorkSpace->mDomainBundle.mKeySpawnBConstants.mMatrixUnrollB,
        pWorkSpace->mDomainBundle.mKeySpawnBConstants.mMatrixArgA,
        pWorkSpace->mDomainBundle.mKeySpawnBConstants.mMatrixArgB,
        pWorkSpace->mDomainBundle.mKeySpawnBConstants.mMatrixArgC,
        pWorkSpace->mDomainBundle.mKeySpawnBConstants.mMatrixArgD);
    
}

void TwistExpander_Aldebaran::FoldKeyRowA(TwistWorkSpace *pWorkSpace) {
    // GrowAControl candidate 1 of 17
    // Exploration cases: 0
    // Structural distance: baseline candidate
    std::uint8_t *aSourceLaneA = pWorkSpace->mVaporLaneA;
    std::uint8_t *aSourceLaneB = pWorkSpace->mVaporLaneB;
    std::uint8_t *aSourceLaneC = pWorkSpace->mVaporLaneC;
    std::uint8_t *aSourceLaneD = pWorkSpace->mVaporLaneD;

    std::uint8_t *aFoldLaneA = pWorkSpace->mSpiritLaneA;
    std::uint8_t *aFoldLaneB = pWorkSpace->mSpiritLaneB;
    std::uint8_t *aFoldLaneC = pWorkSpace->mSpiritLaneC;
    std::uint8_t *aFoldLaneD = pWorkSpace->mSpiritLaneD;

    std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);

    static_assert(S_BLOCK == 32768, "Key folding requires 32,768-byte lanes.");
    static_assert(W_KEY == 2048, "Key folding requires 2,048-byte key rows.");

    // Fold Stage I

    std::uint8_t *aFoldA = aFoldLaneA + (0U * W_KEY);
    std::uint8_t *aFoldB = aFoldLaneA + (1U * W_KEY);
    std::uint8_t *aFoldC = aFoldLaneA + (2U * W_KEY);
    std::uint8_t *aFoldD = aFoldLaneA + (3U * W_KEY);
    std::uint8_t *aFoldE = aFoldLaneB + (0U * W_KEY);
    std::uint8_t *aFoldF = aFoldLaneB + (1U * W_KEY);
    std::uint8_t *aFoldG = aFoldLaneB + (2U * W_KEY);
    std::uint8_t *aFoldH = aFoldLaneB + (3U * W_KEY);
    std::uint8_t *aFoldI = aFoldLaneC + (0U * W_KEY);
    std::uint8_t *aFoldJ = aFoldLaneC + (1U * W_KEY);
    std::uint8_t *aFoldK = aFoldLaneC + (2U * W_KEY);
    std::uint8_t *aFoldL = aFoldLaneC + (3U * W_KEY);
    std::uint8_t *aFoldM = aFoldLaneD + (0U * W_KEY);
    std::uint8_t *aFoldN = aFoldLaneD + (1U * W_KEY);
    std::uint8_t *aFoldO = aFoldLaneD + (2U * W_KEY);
    std::uint8_t *aFoldP = aFoldLaneD + (3U * W_KEY);

    // Chunks: 15, 8, 6, 10
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (15U * W_KEY) + ((aIndex + 880U) & W_KEY1);
        const std::size_t aIndexB = (8U * W_KEY) + ((aIndex + 1893U) & W_KEY1);
        const std::size_t aIndexC = (6U * W_KEY) + ((aIndex + 47U) & W_KEY1);
        const std::size_t aIndexD = (10U * W_KEY) + ((aIndex + 1915U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneA[aIndexA]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneB[aIndexB]) << 16U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneC[aIndexC]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneD[aIndexD]) << 0U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aFoldA[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Chunks: 13, 6, 8, 4
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (13U * W_KEY) + ((aIndex + 1465U) & W_KEY1);
        const std::size_t aIndexB = (6U * W_KEY) + ((aIndex + 1195U) & W_KEY1);
        const std::size_t aIndexC = (8U * W_KEY) + ((aIndex + 1060U) & W_KEY1);
        const std::size_t aIndexD = (4U * W_KEY) + ((aIndex + 565U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneA[aIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneB[aIndexB]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneC[aIndexC]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneD[aIndexD]) << 16U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aFoldB[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Chunks: 0, 3, 15, 9
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (0U * W_KEY) + ((aIndex + 835U) & W_KEY1);
        const std::size_t aIndexB = (3U * W_KEY) + ((aIndex + 1758U) & W_KEY1);
        const std::size_t aIndexC = (15U * W_KEY) + ((aIndex + 1983U) & W_KEY1);
        const std::size_t aIndexD = (9U * W_KEY) + ((aIndex + 115U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneA[aIndexA]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneB[aIndexB]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneC[aIndexC]) << 16U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneD[aIndexD]) << 24U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aFoldC[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Chunks: 8, 11, 12, 6
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (8U * W_KEY) + ((aIndex + 205U) & W_KEY1);
        const std::size_t aIndexB = (11U * W_KEY) + ((aIndex + 1735U) & W_KEY1);
        const std::size_t aIndexC = (12U * W_KEY) + ((aIndex + 790U) & W_KEY1);
        const std::size_t aIndexD = (6U * W_KEY) + ((aIndex + 520U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneA[aIndexA]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneB[aIndexB]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneC[aIndexC]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneD[aIndexD]) << 16U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aFoldD[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Chunks: 1, 7, 10, 3
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (1U * W_KEY) + ((aIndex + 250U) & W_KEY1);
        const std::size_t aIndexB = (7U * W_KEY) + ((aIndex + 655U) & W_KEY1);
        const std::size_t aIndexC = (10U * W_KEY) + ((aIndex + 25U) & W_KEY1);
        const std::size_t aIndexD = (3U * W_KEY) + ((aIndex + 1510U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneA[aIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneB[aIndexB]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneC[aIndexC]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneD[aIndexD]) << 16U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aFoldE[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Chunks: 2, 1, 3, 7
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (2U * W_KEY) + ((aIndex + 1533U) & W_KEY1);
        const std::size_t aIndexB = (1U * W_KEY) + ((aIndex + 1623U) & W_KEY1);
        const std::size_t aIndexC = (3U * W_KEY) + ((aIndex + 1870U) & W_KEY1);
        const std::size_t aIndexD = (7U * W_KEY) + ((aIndex + 1600U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneA[aIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneB[aIndexB]) << 16U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneC[aIndexC]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneD[aIndexD]) << 8U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aFoldF[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Chunks: 9, 14, 4, 11
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (9U * W_KEY) + ((aIndex + 70U) & W_KEY1);
        const std::size_t aIndexB = (14U * W_KEY) + ((aIndex + 1713U) & W_KEY1);
        const std::size_t aIndexC = (4U * W_KEY) + ((aIndex + 1105U) & W_KEY1);
        const std::size_t aIndexD = (11U * W_KEY) + ((aIndex + 385U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneA[aIndexA]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneB[aIndexB]) << 16U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneC[aIndexC]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneD[aIndexD]) << 0U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aFoldG[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Chunks: 10, 0, 2, 1
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (10U * W_KEY) + ((aIndex + 2U) & W_KEY1);
        const std::size_t aIndexB = (0U * W_KEY) + ((aIndex + 1285U) & W_KEY1);
        const std::size_t aIndexC = (2U * W_KEY) + ((aIndex + 1668U) & W_KEY1);
        const std::size_t aIndexD = (1U * W_KEY) + ((aIndex + 1150U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneA[aIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneB[aIndexB]) << 16U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneC[aIndexC]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneD[aIndexD]) << 8U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aFoldH[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Chunks: 5, 2, 14, 12
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (5U * W_KEY) + ((aIndex + 1803U) & W_KEY1);
        const std::size_t aIndexB = (2U * W_KEY) + ((aIndex + 2005U) & W_KEY1);
        const std::size_t aIndexC = (14U * W_KEY) + ((aIndex + 92U) & W_KEY1);
        const std::size_t aIndexD = (12U * W_KEY) + ((aIndex + 475U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneA[aIndexA]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneB[aIndexB]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneC[aIndexC]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneD[aIndexD]) << 16U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aFoldI[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Chunks: 14, 13, 9, 8
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (14U * W_KEY) + ((aIndex + 1645U) & W_KEY1);
        const std::size_t aIndexB = (13U * W_KEY) + ((aIndex + 700U) & W_KEY1);
        const std::size_t aIndexC = (9U * W_KEY) + ((aIndex + 970U) & W_KEY1);
        const std::size_t aIndexD = (8U * W_KEY) + ((aIndex + 1555U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneA[aIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneB[aIndexB]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneC[aIndexC]) << 16U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneD[aIndexD]) << 8U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aFoldJ[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Chunks: 3, 5, 13, 14
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (3U * W_KEY) + ((aIndex + 1825U) & W_KEY1);
        const std::size_t aIndexB = (5U * W_KEY) + ((aIndex + 1690U) & W_KEY1);
        const std::size_t aIndexC = (13U * W_KEY) + ((aIndex + 1420U) & W_KEY1);
        const std::size_t aIndexD = (14U * W_KEY) + ((aIndex + 1848U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneA[aIndexA]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneB[aIndexB]) << 16U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneC[aIndexC]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneD[aIndexD]) << 8U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aFoldK[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Chunks: 7, 9, 1, 13
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (7U * W_KEY) + ((aIndex + 1578U) & W_KEY1);
        const std::size_t aIndexB = (9U * W_KEY) + ((aIndex + 1443U) & W_KEY1);
        const std::size_t aIndexC = (1U * W_KEY) + ((aIndex + 1780U) & W_KEY1);
        const std::size_t aIndexD = (13U * W_KEY) + ((aIndex + 1938U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneA[aIndexA]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneB[aIndexB]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneC[aIndexC]) << 16U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneD[aIndexD]) << 24U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aFoldL[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Chunks: 4, 12, 0, 5
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (4U * W_KEY) + ((aIndex + 1375U) & W_KEY1);
        const std::size_t aIndexB = (12U * W_KEY) + ((aIndex + 1960U) & W_KEY1);
        const std::size_t aIndexC = (0U * W_KEY) + ((aIndex + 137U) & W_KEY1);
        const std::size_t aIndexD = (5U * W_KEY) + ((aIndex + 1488U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneA[aIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneB[aIndexB]) << 16U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneC[aIndexC]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneD[aIndexD]) << 24U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aFoldM[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Chunks: 11, 10, 7, 0
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (11U * W_KEY) + ((aIndex + 1398U) & W_KEY1);
        const std::size_t aIndexB = (10U * W_KEY) + ((aIndex + 1015U) & W_KEY1);
        const std::size_t aIndexC = (7U * W_KEY) + ((aIndex + 1240U) & W_KEY1);
        const std::size_t aIndexD = (0U * W_KEY) + ((aIndex + 925U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneA[aIndexA]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneB[aIndexB]) << 16U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneC[aIndexC]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneD[aIndexD]) << 8U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aFoldN[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Chunks: 6, 4, 11, 15
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (6U * W_KEY) + ((aIndex + 1330U) & W_KEY1);
        const std::size_t aIndexB = (4U * W_KEY) + ((aIndex + 340U) & W_KEY1);
        const std::size_t aIndexC = (11U * W_KEY) + ((aIndex + 160U) & W_KEY1);
        const std::size_t aIndexD = (15U * W_KEY) + ((aIndex + 745U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneA[aIndexA]) << 16U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneB[aIndexB]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneC[aIndexC]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneD[aIndexD]) << 0U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aFoldO[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Chunks: 12, 15, 5, 2
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (12U * W_KEY) + ((aIndex + 295U) & W_KEY1);
        const std::size_t aIndexB = (15U * W_KEY) + ((aIndex + 2028U) & W_KEY1);
        const std::size_t aIndexC = (5U * W_KEY) + ((aIndex + 610U) & W_KEY1);
        const std::size_t aIndexD = (2U * W_KEY) + ((aIndex + 430U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneA[aIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneB[aIndexB]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneC[aIndexC]) << 16U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneD[aIndexD]) << 24U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aFoldP[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Fold Stage II

    // Quarters A-D, chunks: 1, 2, 3, 0
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (1U * W_KEY) + ((aIndex + 47U) & W_KEY1);
        const std::size_t aIndexB = (2U * W_KEY) + ((aIndex + 1510U) & W_KEY1);
        const std::size_t aIndexC = (3U * W_KEY) + ((aIndex + 1690U) & W_KEY1);
        const std::size_t aIndexD = (0U * W_KEY) + ((aIndex + 1825U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aFoldLaneA[aIndexA]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aFoldLaneB[aIndexB]) << 16U;
        aFoldValue |= static_cast<std::uint32_t>(aFoldLaneC[aIndexC]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aFoldLaneD[aIndexD]) << 0U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aSourceLaneA[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Quarters A-D, chunks: 2, 3, 1, 3
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (2U * W_KEY) + ((aIndex + 1915U) & W_KEY1);
        const std::size_t aIndexB = (3U * W_KEY) + ((aIndex + 137U) & W_KEY1);
        const std::size_t aIndexC = (1U * W_KEY) + ((aIndex + 2005U) & W_KEY1);
        const std::size_t aIndexD = (3U * W_KEY) + ((aIndex + 1870U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aFoldLaneA[aIndexA]) << 16U;
        aFoldValue |= static_cast<std::uint32_t>(aFoldLaneB[aIndexB]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aFoldLaneC[aIndexC]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aFoldLaneD[aIndexD]) << 24U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aSourceLaneB[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Quarters A-D, chunks: 3, 0, 0, 2
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (3U * W_KEY) + ((aIndex + 92U) & W_KEY1);
        const std::size_t aIndexB = (0U * W_KEY) + ((aIndex + 1555U) & W_KEY1);
        const std::size_t aIndexC = (0U * W_KEY) + ((aIndex + 2U) & W_KEY1);
        const std::size_t aIndexD = (2U * W_KEY) + ((aIndex + 1600U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aFoldLaneA[aIndexA]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aFoldLaneB[aIndexB]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aFoldLaneC[aIndexC]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aFoldLaneD[aIndexD]) << 16U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aSourceLaneC[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Quarters A-D, chunks: 0, 1, 2, 1
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (0U * W_KEY) + ((aIndex + 1645U) & W_KEY1);
        const std::size_t aIndexB = (1U * W_KEY) + ((aIndex + 1960U) & W_KEY1);
        const std::size_t aIndexC = (2U * W_KEY) + ((aIndex + 1780U) & W_KEY1);
        const std::size_t aIndexD = (1U * W_KEY) + ((aIndex + 1735U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aFoldLaneA[aIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aFoldLaneB[aIndexB]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aFoldLaneC[aIndexC]) << 16U;
        aFoldValue |= static_cast<std::uint32_t>(aFoldLaneD[aIndexD]) << 8U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aSourceLaneD[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Fold Stage III

    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        std::uint32_t aValue = 0U;
        aValue |= static_cast<std::uint32_t>(aSourceLaneA[aIndex]) << 0U;
        aValue |= static_cast<std::uint32_t>(aSourceLaneB[aIndex]) << 8U;
        aValue |= static_cast<std::uint32_t>(aSourceLaneC[aIndex]) << 16U;
        aValue |= static_cast<std::uint32_t>(aSourceLaneD[aIndex]) << 24U;
        aValue = TwistMix32::DiffuseA(aValue);
        aKeyRow[aIndex] = static_cast<std::uint8_t>(aValue);
    }
}

void TwistExpander_Aldebaran::FoldKeyRowB(TwistWorkSpace *pWorkSpace) {
    // GrowBControl candidate 1 of 17
    // Exploration cases: 0
    // Structural distance: baseline candidate
    std::uint8_t *aSourceLaneA = pWorkSpace->mShadowLaneA;
    std::uint8_t *aSourceLaneB = pWorkSpace->mShadowLaneB;
    std::uint8_t *aSourceLaneC = pWorkSpace->mShadowLaneC;
    std::uint8_t *aSourceLaneD = pWorkSpace->mShadowLaneD;

    std::uint8_t *aFoldLaneA = pWorkSpace->mSpiritLaneA;
    std::uint8_t *aFoldLaneB = pWorkSpace->mSpiritLaneB;
    std::uint8_t *aFoldLaneC = pWorkSpace->mSpiritLaneC;
    std::uint8_t *aFoldLaneD = pWorkSpace->mSpiritLaneD;

    std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);

    static_assert(S_BLOCK == 32768, "Key folding requires 32,768-byte lanes.");
    static_assert(W_KEY == 2048, "Key folding requires 2,048-byte key rows.");

    // Fold Stage I

    std::uint8_t *aFoldA = aFoldLaneA + (0U * W_KEY);
    std::uint8_t *aFoldB = aFoldLaneA + (1U * W_KEY);
    std::uint8_t *aFoldC = aFoldLaneA + (2U * W_KEY);
    std::uint8_t *aFoldD = aFoldLaneA + (3U * W_KEY);
    std::uint8_t *aFoldE = aFoldLaneB + (0U * W_KEY);
    std::uint8_t *aFoldF = aFoldLaneB + (1U * W_KEY);
    std::uint8_t *aFoldG = aFoldLaneB + (2U * W_KEY);
    std::uint8_t *aFoldH = aFoldLaneB + (3U * W_KEY);
    std::uint8_t *aFoldI = aFoldLaneC + (0U * W_KEY);
    std::uint8_t *aFoldJ = aFoldLaneC + (1U * W_KEY);
    std::uint8_t *aFoldK = aFoldLaneC + (2U * W_KEY);
    std::uint8_t *aFoldL = aFoldLaneC + (3U * W_KEY);
    std::uint8_t *aFoldM = aFoldLaneD + (0U * W_KEY);
    std::uint8_t *aFoldN = aFoldLaneD + (1U * W_KEY);
    std::uint8_t *aFoldO = aFoldLaneD + (2U * W_KEY);
    std::uint8_t *aFoldP = aFoldLaneD + (3U * W_KEY);

    // Chunks: 6, 14, 8, 10
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (6U * W_KEY) + ((aIndex + 836U) & W_KEY1);
        const std::size_t aIndexB = (14U * W_KEY) + ((aIndex + 1061U) & W_KEY1);
        const std::size_t aIndexC = (8U * W_KEY) + ((aIndex + 1353U) & W_KEY1);
        const std::size_t aIndexD = (10U * W_KEY) + ((aIndex + 2006U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneA[aIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneB[aIndexB]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneC[aIndexC]) << 16U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneD[aIndexD]) << 8U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aFoldA[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Chunks: 12, 10, 14, 8
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (12U * W_KEY) + ((aIndex + 1826U) & W_KEY1);
        const std::size_t aIndexB = (10U * W_KEY) + ((aIndex + 1083U) & W_KEY1);
        const std::size_t aIndexC = (14U * W_KEY) + ((aIndex + 903U) & W_KEY1);
        const std::size_t aIndexD = (8U * W_KEY) + ((aIndex + 858U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneA[aIndexA]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneB[aIndexB]) << 16U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneC[aIndexC]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneD[aIndexD]) << 24U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aFoldB[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Chunks: 14, 2, 3, 9
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (14U * W_KEY) + ((aIndex + 813U) & W_KEY1);
        const std::size_t aIndexB = (2U * W_KEY) + ((aIndex + 611U) & W_KEY1);
        const std::size_t aIndexC = (3U * W_KEY) + ((aIndex + 453U) & W_KEY1);
        const std::size_t aIndexD = (9U * W_KEY) + ((aIndex + 138U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneA[aIndexA]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneB[aIndexB]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneC[aIndexC]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneD[aIndexD]) << 16U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aFoldC[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Chunks: 5, 8, 9, 6
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (5U * W_KEY) + ((aIndex + 1601U) & W_KEY1);
        const std::size_t aIndexB = (8U * W_KEY) + ((aIndex + 1646U) & W_KEY1);
        const std::size_t aIndexC = (9U * W_KEY) + ((aIndex + 633U) & W_KEY1);
        const std::size_t aIndexD = (6U * W_KEY) + ((aIndex + 318U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneA[aIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneB[aIndexB]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneC[aIndexC]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneD[aIndexD]) << 16U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aFoldD[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Chunks: 0, 9, 6, 5
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (0U * W_KEY) + ((aIndex + 791U) & W_KEY1);
        const std::size_t aIndexB = (9U * W_KEY) + ((aIndex + 183U) & W_KEY1);
        const std::size_t aIndexC = (6U * W_KEY) + ((aIndex + 926U) & W_KEY1);
        const std::size_t aIndexD = (5U * W_KEY) + ((aIndex + 408U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneA[aIndexA]) << 16U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneB[aIndexB]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneC[aIndexC]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneD[aIndexD]) << 24U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aFoldE[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Chunks: 8, 6, 1, 15
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (8U * W_KEY) + ((aIndex + 1241U) & W_KEY1);
        const std::size_t aIndexB = (6U * W_KEY) + ((aIndex + 1376U) & W_KEY1);
        const std::size_t aIndexC = (1U * W_KEY) + ((aIndex + 746U) & W_KEY1);
        const std::size_t aIndexD = (15U * W_KEY) + ((aIndex + 1736U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneA[aIndexA]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneB[aIndexB]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneC[aIndexC]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneD[aIndexD]) << 16U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aFoldF[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Chunks: 2, 11, 12, 4
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (2U * W_KEY) + ((aIndex + 1691U) & W_KEY1);
        const std::size_t aIndexB = (11U * W_KEY) + ((aIndex + 498U) & W_KEY1);
        const std::size_t aIndexC = (12U * W_KEY) + ((aIndex + 1466U) & W_KEY1);
        const std::size_t aIndexD = (4U * W_KEY) + ((aIndex + 971U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneA[aIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneB[aIndexB]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneC[aIndexC]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneD[aIndexD]) << 16U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aFoldG[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Chunks: 11, 0, 2, 7
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (11U * W_KEY) + ((aIndex + 701U) & W_KEY1);
        const std::size_t aIndexB = (0U * W_KEY) + ((aIndex + 1961U) & W_KEY1);
        const std::size_t aIndexC = (2U * W_KEY) + ((aIndex + 93U) & W_KEY1);
        const std::size_t aIndexD = (7U * W_KEY) + ((aIndex + 1173U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneA[aIndexA]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneB[aIndexB]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneC[aIndexC]) << 16U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneD[aIndexD]) << 0U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aFoldH[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Chunks: 4, 5, 13, 12
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (4U * W_KEY) + ((aIndex + 678U) & W_KEY1);
        const std::size_t aIndexB = (5U * W_KEY) + ((aIndex + 1781U) & W_KEY1);
        const std::size_t aIndexC = (13U * W_KEY) + ((aIndex + 656U) & W_KEY1);
        const std::size_t aIndexD = (12U * W_KEY) + ((aIndex + 1128U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneA[aIndexA]) << 16U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneB[aIndexB]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneC[aIndexC]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneD[aIndexD]) << 8U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aFoldI[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Chunks: 7, 3, 15, 11
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (7U * W_KEY) + ((aIndex + 881U) & W_KEY1);
        const std::size_t aIndexB = (3U * W_KEY) + ((aIndex + 1196U) & W_KEY1);
        const std::size_t aIndexC = (15U * W_KEY) + ((aIndex + 48U) & W_KEY1);
        const std::size_t aIndexD = (11U * W_KEY) + ((aIndex + 363U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneA[aIndexA]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneB[aIndexB]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneC[aIndexC]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneD[aIndexD]) << 16U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aFoldJ[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Chunks: 13, 12, 5, 3
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (13U * W_KEY) + ((aIndex + 1218U) & W_KEY1);
        const std::size_t aIndexB = (12U * W_KEY) + ((aIndex + 3U) & W_KEY1);
        const std::size_t aIndexC = (5U * W_KEY) + ((aIndex + 1916U) & W_KEY1);
        const std::size_t aIndexD = (3U * W_KEY) + ((aIndex + 228U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneA[aIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneB[aIndexB]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneC[aIndexC]) << 16U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneD[aIndexD]) << 24U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aFoldK[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Chunks: 10, 1, 7, 14
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (10U * W_KEY) + ((aIndex + 543U) & W_KEY1);
        const std::size_t aIndexB = (1U * W_KEY) + ((aIndex + 566U) & W_KEY1);
        const std::size_t aIndexC = (7U * W_KEY) + ((aIndex + 993U) & W_KEY1);
        const std::size_t aIndexD = (14U * W_KEY) + ((aIndex + 1106U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneA[aIndexA]) << 16U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneB[aIndexB]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneC[aIndexC]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneD[aIndexD]) << 0U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aFoldL[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Chunks: 3, 4, 11, 13
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (3U * W_KEY) + ((aIndex + 588U) & W_KEY1);
        const std::size_t aIndexB = (4U * W_KEY) + ((aIndex + 273U) & W_KEY1);
        const std::size_t aIndexC = (11U * W_KEY) + ((aIndex + 948U) & W_KEY1);
        const std::size_t aIndexD = (13U * W_KEY) + ((aIndex + 1038U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneA[aIndexA]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneB[aIndexB]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneC[aIndexC]) << 16U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneD[aIndexD]) << 24U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aFoldM[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Chunks: 1, 7, 4, 2
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (1U * W_KEY) + ((aIndex + 1331U) & W_KEY1);
        const std::size_t aIndexB = (7U * W_KEY) + ((aIndex + 1511U) & W_KEY1);
        const std::size_t aIndexC = (4U * W_KEY) + ((aIndex + 1421U) & W_KEY1);
        const std::size_t aIndexD = (2U * W_KEY) + ((aIndex + 723U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneA[aIndexA]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneB[aIndexB]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneC[aIndexC]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneD[aIndexD]) << 16U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aFoldN[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Chunks: 15, 13, 0, 1
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (15U * W_KEY) + ((aIndex + 1263U) & W_KEY1);
        const std::size_t aIndexB = (13U * W_KEY) + ((aIndex + 1871U) & W_KEY1);
        const std::size_t aIndexC = (0U * W_KEY) + ((aIndex + 1556U) & W_KEY1);
        const std::size_t aIndexD = (1U * W_KEY) + ((aIndex + 1308U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneA[aIndexA]) << 16U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneB[aIndexB]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneC[aIndexC]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneD[aIndexD]) << 8U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aFoldO[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Chunks: 9, 15, 10, 0
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (9U * W_KEY) + ((aIndex + 768U) & W_KEY1);
        const std::size_t aIndexB = (15U * W_KEY) + ((aIndex + 1151U) & W_KEY1);
        const std::size_t aIndexC = (10U * W_KEY) + ((aIndex + 1016U) & W_KEY1);
        const std::size_t aIndexD = (0U * W_KEY) + ((aIndex + 1286U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneA[aIndexA]) << 16U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneB[aIndexB]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneC[aIndexC]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aSourceLaneD[aIndexD]) << 0U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aFoldP[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Fold Stage II

    // Quarters A-D, chunks: 0, 0, 3, 2
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (0U * W_KEY) + ((aIndex + 1015U) & W_KEY1);
        const std::size_t aIndexB = (0U * W_KEY) + ((aIndex + 1465U) & W_KEY1);
        const std::size_t aIndexC = (3U * W_KEY) + ((aIndex + 1060U) & W_KEY1);
        const std::size_t aIndexD = (2U * W_KEY) + ((aIndex + 790U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aFoldLaneA[aIndexA]) << 16U;
        aFoldValue |= static_cast<std::uint32_t>(aFoldLaneB[aIndexB]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aFoldLaneC[aIndexC]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aFoldLaneD[aIndexD]) << 8U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aSourceLaneA[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Quarters A-D, chunks: 1, 3, 2, 0
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (1U * W_KEY) + ((aIndex + 1330U) & W_KEY1);
        const std::size_t aIndexB = (3U * W_KEY) + ((aIndex + 970U) & W_KEY1);
        const std::size_t aIndexC = (2U * W_KEY) + ((aIndex + 1375U) & W_KEY1);
        const std::size_t aIndexD = (0U * W_KEY) + ((aIndex + 1195U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aFoldLaneA[aIndexA]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aFoldLaneB[aIndexB]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aFoldLaneC[aIndexC]) << 16U;
        aFoldValue |= static_cast<std::uint32_t>(aFoldLaneD[aIndexD]) << 0U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aSourceLaneB[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Quarters A-D, chunks: 2, 1, 0, 1
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (2U * W_KEY) + ((aIndex + 925U) & W_KEY1);
        const std::size_t aIndexB = (1U * W_KEY) + ((aIndex + 1420U) & W_KEY1);
        const std::size_t aIndexC = (0U * W_KEY) + ((aIndex + 1105U) & W_KEY1);
        const std::size_t aIndexD = (1U * W_KEY) + ((aIndex + 1285U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aFoldLaneA[aIndexA]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aFoldLaneB[aIndexB]) << 16U;
        aFoldValue |= static_cast<std::uint32_t>(aFoldLaneC[aIndexC]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aFoldLaneD[aIndexD]) << 8U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aSourceLaneC[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Quarters A-D, chunks: 3, 2, 1, 3
    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        const std::size_t aIndexA = (3U * W_KEY) + ((aIndex + 880U) & W_KEY1);
        const std::size_t aIndexB = (2U * W_KEY) + ((aIndex + 835U) & W_KEY1);
        const std::size_t aIndexC = (1U * W_KEY) + ((aIndex + 1240U) & W_KEY1);
        const std::size_t aIndexD = (3U * W_KEY) + ((aIndex + 1150U) & W_KEY1);

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aFoldLaneA[aIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aFoldLaneB[aIndexB]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aFoldLaneC[aIndexC]) << 16U;
        aFoldValue |= static_cast<std::uint32_t>(aFoldLaneD[aIndexD]) << 24U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);
        aSourceLaneD[aIndex] = static_cast<std::uint8_t>(aFoldValue);
    }

    // Fold Stage III

    for (std::size_t aIndex = 0U; aIndex < W_KEY; aIndex += 1U) {
        std::uint32_t aValue = 0U;
        aValue |= static_cast<std::uint32_t>(aSourceLaneA[aIndex]) << 0U;
        aValue |= static_cast<std::uint32_t>(aSourceLaneB[aIndex]) << 8U;
        aValue |= static_cast<std::uint32_t>(aSourceLaneC[aIndex]) << 16U;
        aValue |= static_cast<std::uint32_t>(aSourceLaneD[aIndex]) << 24U;
        aValue = TwistMix32::DiffuseA(aValue);
        aKeyRow[aIndex] = static_cast<std::uint8_t>(aValue);
    }
}
