
// keep
void TwistExpander_Aldebaran::KDF_A_A() {

    //
    // src: [source, nonce]
    // dst: [$shadow]
    //
    TwistExpander_Aldebaran_Arx::KDF_A_A_A(PARAMS_KDF);

    //
    // src: [$shadow]
    // dst: [$fire]
    //
    TwistExpander_Aldebaran_Arx::KDF_A_B_A(PARAMS_KDF);

    TwistDiffuse::DiffuseWithDomainWords(
        aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD,  // input lanes
        aVaporLaneA, aVaporLaneB, aVaporLaneC, aVaporLaneD, // output lanes
        aShadowLaneA, aShadowLaneB, aShadowLaneC, aShadowLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    //
    // src: [$vapor]
    // dst: [$kinetic]
    //
    TwistExpander_Aldebaran_Arx::KDF_A_C_A(PARAMS_KDF);

}

// keep
void TwistExpander_Aldebaran::KDF_B_A() {

    //
    // src: [$kinetic]
    // dst: [$evocation]
    //
    TwistExpander_Aldebaran_Arx::KDF_B_A_A(PARAMS_KDF);

    //
    // src: [$evocation]
    // dst: [$runic]
    //
    TwistExpander_Aldebaran_Arx::KDF_B_B_A(PARAMS_KDF);

    TwistDiffuse::DiffuseWithDomainWords(
        aRunicLaneA, aRunicLaneB, aRunicLaneC, aRunicLaneD,  // input lanes
        aDivinationLaneA, aDivinationLaneB, aDivinationLaneC, aDivinationLaneD, // output lanes
        aEvocationLaneA, aEvocationLaneB, aEvocationLaneC, aEvocationLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    //
    // src: [$divination]
    // dst: [$abjuration]
    //
    TwistExpander_Aldebaran_Arx::KDF_B_C_A(PARAMS_KDF);

}

// keep
void TwistExpander_Aldebaran::KDF_C_A() {

    //
    // src: [$abjuration]
    // dst: [$aether]
    //
    TwistExpander_Aldebaran_Arx::KDF_C_A_A(PARAMS_KDF);

    //
    // src: [$aether]
    // dst: [$lunar]
    //
    TwistExpander_Aldebaran_Arx::KDF_C_B_A(PARAMS_KDF);

    TwistDiffuse::DiffuseWithDomainWords(
        aLunarLaneA, aLunarLaneB, aLunarLaneC, aLunarLaneD,  // input lanes
        aEarthLaneA, aEarthLaneB, aEarthLaneC, aEarthLaneD, // output lanes
        aAetherLaneA, aAetherLaneB, aAetherLaneC, aAetherLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    //
    // src: [$earth]
    // dst: [$crystal]
    //
    TwistExpander_Aldebaran_Arx::KDF_C_C_A(PARAMS_KDF);

}

void TwistExpander_Aldebaran::Seed() {
    
    ////////////////////////////////////////////////////////
    //
    // Secret material derivation, across 6 domains.
    //
    // Domain 1 of 6, key a rotate:
    //
    // src: [source, nonce]
    // dst: [$shadow]
    //
    KDF_A_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), ARX_STATE_VARS);

    TwistFarm::Farm(pFarmSalt,
                    aKineticLaneB, aKineticLaneC, aKineticLaneD, aKineticLaneA, // farm lanes
                    aStasisLaneA, aStasisLaneB, aStasisLaneC, // temp/fold lanes
                    &mDomainBundleEphemeralA.mKeyRotateASalts,
                    &(mDomainBundleEphemeralA.mKeyRotateAConstants));

    //
    // src: [$kinetic]
    // dst: [$evocation]
    //
    KDF_B_A(pWorkSpace, pNonce, &(mDomainBundleEphemeralA.mKeyRotateAConstants), &(mDomainBundleEphemeralA.mKeyRotateASalts), ARX_STATE_VARS);

    TwistFarm::Farm(pFarmSalt,
                    aAbjurationLaneB, aAbjurationLaneC, aAbjurationLaneD, aAbjurationLaneA, // farm lanes
                    aStasisLaneA, aStasisLaneB, aStasisLaneC, // temp/fold lanes
                    &mDomainBundleEphemeralB.mKeyRotateASalts,
                    &(mDomainBundleEphemeralB.mKeyRotateAConstants));

    //
    // src: [$abjuration]
    // dst: [$aether]
    //
    KDF_C_A(pWorkSpace, pNonce, &(mDomainBundleEphemeralB.mKeyRotateAConstants), &(mDomainBundleEphemeralB.mKeyRotateASalts), ARX_STATE_VARS);

    TwistFarm::Farm(pFarmSalt,
                    aCrystalLaneB, aCrystalLaneC, aCrystalLaneD, aCrystalLaneA, // farm lanes
                    aStasisLaneA, aStasisLaneB, aStasisLaneC, // temp/fold lanes
                    &pWorkSpace->mDomainBundle.mKeyRotateASalts,
                    &(pWorkSpace->mDomainBundle.mKeyRotateAConstants));
    //
    ////////////////////////////////////////////////////////


    ////////////////////////////////////////////////////////
    //
    // Main seed loops
    //
    // src: [source, nonce]
    // dst: [$ice]
    //
    TwistExpander_Aldebaran_Arx::SEED_A(PARAMS_SEED);

    //
    // src: [$ice]
    // dst: [$rainbow]
    //
    TwistExpander_Aldebaran_Arx::SEED_B(PARAMS_SEED);

    //
    //
    TwistDiffuse::DiffuseWithDomainWords(
        aRainbowLaneA, aRainbowLaneB, aRainbowLaneC, aRainbowLaneD,  // input lanes
        aAlchemyLaneA, aAlchemyLaneB, aAlchemyLaneC, aAlchemyLaneD, // output lanes
        aIceLaneA, aIceLaneB, aIceLaneC, aIceLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    //
    // src: [$alchemy]
    // dst: [$augury]
    //
    TwistExpander_Aldebaran_Arx::SEED_C(PARAMS_SEED);

    //
    // src: [$augury]
    // dst: [$spirit]
    //
    TwistExpander_Aldebaran_Arx::SEED_D(PARAMS_SEED);

    //
    //
    TwistDiffuse::DiffuseWithDomainWords(
        aSpiritLaneA, aSpiritLaneB, aSpiritLaneC, aSpiritLaneD,  // input lanes
        aDivinationLaneA, aDivinationLaneB, aDivinationLaneC, aDivinationLaneD, // output lanes
        aAuguryLaneA, aAuguryLaneB, aAuguryLaneC, aAuguryLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    //
    // src: [$divination]
    // dst: [$psychic]
    //
    TwistExpander_Aldebaran_Arx::SEED_E(PARAMS_SEED);

    //
    // src: [$psychic]
    // dst: [$voodoo]
    //
    TwistExpander_Aldebaran_Arx::SEED_F(PARAMS_SEED);

    //
    //
    TwistDiffuse::DiffuseWithDomainWords(
        aVoodooLaneA, aVoodooLaneB, aVoodooLaneC, aVoodooLaneD,  // input lanes
        aSpiritLaneA, aSpiritLaneB, aSpiritLaneC, aSpiritLaneD, // output lanes
        aPsychicLaneA, aPsychicLaneB, aPsychicLaneC, aPsychicLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    //
    // src: [$spirit]
    // dst: [$sonic]
    //
    TwistExpander_Aldebaran_Arx::SEED_G(PARAMS_SEED);

    //
    // src: [$sonic]
    // dst: [$planar]
    //
    TwistExpander_Aldebaran_Arx::SEED_H(PARAMS_SEED);

    //
    //
    TwistDiffuse::DiffuseWithDomainWords(
        aPlanarLaneA, aPlanarLaneB, aPlanarLaneC, aPlanarLaneD,  // input lanes
        aDivinationLaneA, aDivinationLaneB, aDivinationLaneC, aDivinationLaneD, // output lanes
        aSonicLaneA, aSonicLaneB, aSonicLaneC, aSonicLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    //
    // src: [$divination]
    // dst: [$gloom]
    //
    TwistExpander_Aldebaran_Arx::SEED_I(PARAMS_SEED);

    //
    // src: [$gloom]
    // dst: [$lightning]
    //
    TwistExpander_Aldebaran_Arx::SEED_J(PARAMS_SEED);

    //
    //
    TwistDiffuse::DiffuseWithDomainWords(
        aLightningLaneA, aLightningLaneB, aLightningLaneC, aLightningLaneD,  // input lanes
        aWindLaneA, aWindLaneB, aWindLaneC, aWindLaneD, // output lanes
        aGloomLaneA, aGloomLaneB, aGloomLaneC, aGloomLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    //
    // src: [$wind]
    // dst: [$shadow]
    //
    TwistExpander_Aldebaran_Arx::SEED_K(PARAMS_SEED);

    //
    // src: [$shadow]
    // dst: [$fire]
    //
    TwistExpander_Aldebaran_Arx::SEED_L(PARAMS_SEED);

    //
    //
    TwistDiffuse::DiffuseWithDomainWords(
        aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD,  // input lanes
        aKineticLaneA, aKineticLaneB, aKineticLaneC, aKineticLaneD, // output lanes
        aShadowLaneA, aShadowLaneB, aShadowLaneC, aShadowLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    //
    // src: [$kinetic]
    // dst: [$evocation]
    //
    TwistExpander_Aldebaran_Arx::SEED_M(PARAMS_SEED);

    //
    // src: [$evocation]
    // dst: [$runic]
    //
    TwistExpander_Aldebaran_Arx::SEED_N(PARAMS_SEED);

    //
    //
    TwistDiffuse::DiffuseWithDomainWords(
        aRunicLaneA, aRunicLaneB, aRunicLaneC, aRunicLaneD,  // input lanes
        aAbjurationLaneA, aAbjurationLaneB, aAbjurationLaneC, aAbjurationLaneD, // output lanes
        aEvocationLaneA, aEvocationLaneB, aEvocationLaneC, aEvocationLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    //
    // src: [$abjuration]
    // dst: [$aether]
    //
    TwistExpander_Aldebaran_Arx::SEED_O(PARAMS_SEED);

    //
    // src: [$aether]
    // dst: [$lunar]
    //
    TwistExpander_Aldebaran_Arx::SEED_P(PARAMS_SEED);

    //
    //
    TwistDiffuse::DiffuseWithDomainWords(
        aLunarLaneA, aLunarLaneB, aLunarLaneC, aLunarLaneD,  // input lanes
        aEarthLaneA, aEarthLaneB, aEarthLaneC, aEarthLaneD, // output lanes
        aAetherLaneA, aAetherLaneB, aAetherLaneC, aAetherLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    //
    // src: [$earth]
    // dst: [$crystal]
    //
    TwistExpander_Aldebaran_Arx::SEED_Q(PARAMS_SEED);
    //
    ////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////
    //
    // Folding main seed loops into destination
    //
    TwistSquash::SquashC(pWorkSpace->mCrystalLaneA, pWorkSpace->mCrystalLaneB, pWorkSpace->mCrystalLaneC, pWorkSpace->mCrystalLaneD, pDestination);
    //
    ////////////////////////////////////////////////////////

    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    ...

    ////////////////////////////////////////////////////////
    //
    // Independent key-row flows
    //
    // Key flow — A / A

    //
    // src: [$earth, $crystal]
    // dst: [$arcane]
    //
    TwistExpander_Aldebaran_Arx::KEY_A_A_A(PARAMS_SEED);

    //
    // src: [$arcane]
    // dst: [$plasma]
    //
    TwistExpander_Aldebaran_Arx::KEY_A_A_B(PARAMS_SEED);

    KeyDiffuse_A_A_A(pWorkSpace);

    //
    // src: [$rainbow]
    // dst: [$water]
    //
    TwistExpander_Aldebaran_Arx::KEY_A_A_C(PARAMS_SEED);

    //
    // src: [$water]
    // dst: [$vapor]
    //
    TwistExpander_Aldebaran_Arx::KEY_A_A_D(PARAMS_SEED);

    KeyDiffuse_B_A_A(pWorkSpace);

    //
    // src: [$frost]
    // dst: [$ice]
    //
    TwistExpander_Aldebaran_Arx::KEY_A_A_E(PARAMS_SEED);

    TwistSquash::SquashKeyA(ALDEBARAN_KEY_A_A_IceLaneA, ALDEBARAN_KEY_A_A_IceLaneB, ALDEBARAN_KEY_A_A_IceLaneC, ALDEBARAN_KEY_A_A_IceLaneD, &(pWorkSpace->mKeyBoxA[0U][0]));

    
    

    //
    // src: [$frost]
    // dst: [$ice]
    //
    TwistExpander_Aldebaran_Arx::KEY_A_H_E(PARAMS_SEED);

    TwistSquash::SquashKeyA(ALDEBARAN_KEY_A_H_IceLaneA, ALDEBARAN_KEY_A_H_IceLaneB, ALDEBARAN_KEY_A_H_IceLaneC, ALDEBARAN_KEY_A_H_IceLaneD, &(pWorkSpace->mKeyBoxA[7U][0]));

    aIngress = *pIngress;
    aCarry = *pCarry;
    aWandererA = *pWandererA;
    ...

    // Key flow — B / A

    //
    // src: [$earth, $crystal]
    // dst: [$arcane]
    //
    TwistExpander_Aldebaran_Arx::KEY_B_A_A(PARAMS_SEED);

    //
    // src: [$arcane]
    // dst: [$plasma]
    //
    TwistExpander_Aldebaran_Arx::KEY_B_A_B(PARAMS_SEED);

    KeyDiffuse_A_B_A(pWorkSpace);

    //
    // src: [$rainbow]
    // dst: [$water]
    //
    TwistExpander_Aldebaran_Arx::KEY_B_A_C(PARAMS_SEED);

    //
    // src: [$water]
    // dst: [$vapor]
    //
    TwistExpander_Aldebaran_Arx::KEY_B_A_D(PARAMS_SEED);

    KeyDiffuse_B_B_A(pWorkSpace);

    //
    // src: [$frost]
    // dst: [$ice]
    //
    TwistExpander_Aldebaran_Arx::KEY_B_A_E(PARAMS_SEED);

    TwistSquash::SquashKeyA(ALDEBARAN_KEY_B_A_IceLaneA, ALDEBARAN_KEY_B_A_IceLaneB, ALDEBARAN_KEY_B_A_IceLaneC, ALDEBARAN_KEY_B_A_IceLaneD, &(pWorkSpace->mKeyBoxB[0U][0]));
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
    // src: [source, key_read_a, key_read_b]
    // dst: [$aether]
    //
    TwistExpander_Aldebaran_Arx::TWIST_A(PARAMS_TWIST);

    //
    // src: [$aether]
    // dst: [$lunar]
    //
    TwistExpander_Aldebaran_Arx::TWIST_B(PARAMS_TWIST);
    
    //
    //
    //
    TwistDiffuse::DiffuseWithDomainWords(
        aLunarLaneA, aLunarLaneB, aLunarLaneC, aLunarLaneD,  // input lanes
        aEarthLaneA, aEarthLaneB, aEarthLaneC, aEarthLaneD, // output lanes
        aAetherLaneA, aAetherLaneB, aAetherLaneC, aAetherLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    //
    // src: [$earth]
    // dst: [$crystal]
    //
    TwistExpander_Aldebaran_Arx::TWIST_C(PARAMS_TWIST);
    //
    ////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////
    //
    // Folding main twist loops into destination
    //
    TwistSquash::SquashC(pWorkSpace->mCrystalLaneA, pWorkSpace->mCrystalLaneB, pWorkSpace->mCrystalLaneC, pWorkSpace->mCrystalLaneD, pDestination);
    //
    ////////////////////////////////////////////////////////

    *pIngress = aIngress;
    *pCarry = aCarry;
    *pWandererA = aWandererA;
    *pWandererB = aWandererB;
    *pWandererC = aWandererC;
    *pWandererD = aWandererD;
    *pWandererE = aWandererE;
    *pWandererF = aWandererF;
    *pWandererG = aWandererG;
    *pWandererH = aWandererH;
    *pWandererI = aWandererI;
    *pWandererJ = aWandererJ;
    *pWandererK = aWandererK;

    ////////////////////////////////////////////////////////
    //
    // Key box management
    //
    if (pStifleKey == true) {
        TwistShiftBox::ShiftKeyBoxA(pWorkSpace);
        TwistShiftBox::ShiftKeyBoxB(pWorkSpace);
    } else {
        TwistForkKeyHalfA(pWorkSpace);
        TwistForkKeyHalfB(pWorkSpace);
        
        GrowKeyA(pWorkSpace, pCrossLaneA, pCrossLaneC, ARX_STATE_VARS);
        
        aIngress = *pIngress;
        aCarry = *pCarry;
        aWandererA = *pWandererA;
        aWandererB = *pWandererB;
        aWandererC = *pWandererC;
        aWandererD = *pWandererD;
        aWandererE = *pWandererE;
        aWandererF = *pWandererF;
        aWandererG = *pWandererG;
        aWandererH = *pWandererH;
        aWandererI = *pWandererI;
        aWandererJ = *pWandererJ;
        aWandererK = *pWandererK;
        
        GrowKeyB(pWorkSpace, pCrossLaneB, pCrossLaneD, ARX_STATE_VARS);
        
    }
    //
    ////////////////////////////////////////////////////////
}

void TwistExpander_Aldebaran::GrowKeyA(TwistWorkSpace *pWorkSpace,
                  std::uint8_t *pCrossLaneA,
                  std::uint8_t *pCrossLaneB,
                  MUTABLE_PARAMS) {
    //
    // src: [$spirit, cross_a, cross_b]
    // dst: [$arcane]
    //
    TwistExpander_Aldebaran_Arx::GROW_A_A(PARAMS_GROW);

    //
    // src: [$arcane]
    // dst: [$plasma]
    //
    TwistExpander_Aldebaran_Arx::GROW_A_B(PARAMS_GROW);

    //
    //
    TwistDiffuse::KeyDiffuseWithDomainWordsA(
        pWorkSpace->mPlasmaLaneA,
        pWorkSpace->mPlasmaLaneB,
        pWorkSpace->mPlasmaLaneC,
        pWorkSpace->mPlasmaLaneD,
        pWorkSpace->mRainbowLaneA,
        pWorkSpace->mRainbowLaneB,
        pWorkSpace->mRainbowLaneC,
        pWorkSpace->mRainbowLaneD,
        pWorkSpace->mArcaneLaneA,
        pWorkSpace->mArcaneLaneB,
        pWorkSpace->mArcaneLaneC,
        pWorkSpace->mArcaneLaneD,
        pWorkSpace->mIndexList256A, pWorkSpace->mIndexList256B,
        pWorkSpace->mIndexList256C, pWorkSpace->mIndexList256D,
        &mMatrix,
        aDomainWordMatrixSelectA, aDomainWordMatrixSelectB,
        aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB,
        aDomainWordMatrixArgA, aDomainWordMatrixArgB,
        aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    //
    // src: [$rainbow]
    // dst: [$water]
    //
    TwistExpander_Aldebaran_Arx::GROW_A_C(PARAMS_GROW);

    //
    // src: [$water]
    // dst: [$vapor]
    //
    TwistExpander_Aldebaran_Arx::GROW_A_D(PARAMS_GROW);

    //
    //
    TwistDiffuse::KeyDiffuseWithDomainWordsA(
        pWorkSpace->mVaporLaneA,
        pWorkSpace->mVaporLaneB,
        pWorkSpace->mVaporLaneC,
        pWorkSpace->mVaporLaneD,
        pWorkSpace->mFrostLaneA,
        pWorkSpace->mFrostLaneB,
        pWorkSpace->mFrostLaneC,
        pWorkSpace->mFrostLaneD,
        pWorkSpace->mWaterLaneA,
        pWorkSpace->mWaterLaneB,
        pWorkSpace->mWaterLaneC,
        pWorkSpace->mWaterLaneD,
        pWorkSpace->mIndexList256A, pWorkSpace->mIndexList256B,
        pWorkSpace->mIndexList256C, pWorkSpace->mIndexList256D,
        &mMatrix,
        aDomainWordMatrixSelectA, aDomainWordMatrixSelectB,
        aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB,
        aDomainWordMatrixArgA, aDomainWordMatrixArgB,
        aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    //
    // src: [$frost]
    // dst: [$ice]
    //
    TwistExpander_Aldebaran_Arx::GROW_A_E(PARAMS_GROW);

    TwistShiftBox::ShiftKeyBoxA(pWorkSpace);
    TwistSquash::SquashKeyA(
        pWorkSpace->mIceLaneA,
        pWorkSpace->mIceLaneB,
        pWorkSpace->mIceLaneC,
        pWorkSpace->mIceLaneD,
        &(pWorkSpace->mKeyBoxA[0][0]));
}

void TwistExpander_Aldebaran::GrowKeyB(TwistWorkSpace *pWorkSpace,
                  std::uint8_t *pCrossLaneA,
                  std::uint8_t *pCrossLaneB,
                  MUTABLE_PARAMS) {
    //
    // src: [$divination, cross_a, cross_b]
    // dst: [$arcane]
    //
    TwistExpander_Aldebaran_Arx::GROW_B_A(PARAMS_GROW);

    //
    // src: [$arcane]
    // dst: [$plasma]
    //
    TwistExpander_Aldebaran_Arx::GROW_B_B(PARAMS_GROW);

    //
    //
    TwistDiffuse::KeyDiffuseWithDomainWordsB(
        pWorkSpace->mPlasmaLaneA,
        pWorkSpace->mPlasmaLaneB,
        pWorkSpace->mPlasmaLaneC,
        pWorkSpace->mPlasmaLaneD,
        pWorkSpace->mRainbowLaneA,
        pWorkSpace->mRainbowLaneB,
        pWorkSpace->mRainbowLaneC,
        pWorkSpace->mRainbowLaneD,
        pWorkSpace->mArcaneLaneA,
        pWorkSpace->mArcaneLaneB,
        pWorkSpace->mArcaneLaneC,
        pWorkSpace->mArcaneLaneD,
        pWorkSpace->mIndexList256A, pWorkSpace->mIndexList256B,
        pWorkSpace->mIndexList256C, pWorkSpace->mIndexList256D,
        &mMatrix,
        aDomainWordMatrixSelectA, aDomainWordMatrixSelectB,
        aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB,
        aDomainWordMatrixArgA, aDomainWordMatrixArgB,
        aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    //
    // src: [$rainbow]
    // dst: [$water]
    //
    TwistExpander_Aldebaran_Arx::GROW_B_C(PARAMS_GROW);

    //
    // src: [$water]
    // dst: [$vapor]
    //
    TwistExpander_Aldebaran_Arx::GROW_B_D(PARAMS_GROW);

    //
    //
    TwistDiffuse::KeyDiffuseWithDomainWordsB(
        pWorkSpace->mVaporLaneA,
        pWorkSpace->mVaporLaneB,
        pWorkSpace->mVaporLaneC,
        pWorkSpace->mVaporLaneD,
        pWorkSpace->mFrostLaneA,
        pWorkSpace->mFrostLaneB,
        pWorkSpace->mFrostLaneC,
        pWorkSpace->mFrostLaneD,
        pWorkSpace->mWaterLaneA,
        pWorkSpace->mWaterLaneB,
        pWorkSpace->mWaterLaneC,
        pWorkSpace->mWaterLaneD,
        pWorkSpace->mIndexList256A, pWorkSpace->mIndexList256B,
        pWorkSpace->mIndexList256C, pWorkSpace->mIndexList256D,
        &mMatrix,
        aDomainWordMatrixSelectA, aDomainWordMatrixSelectB,
        aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB,
        aDomainWordMatrixArgA, aDomainWordMatrixArgB,
        aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    //
    // src: [$frost]
    // dst: [$ice]
    //
    TwistExpander_Aldebaran_Arx::GROW_B_E(PARAMS_GROW);

    TwistShiftBox::ShiftKeyBoxB(pWorkSpace);
    TwistSquash::SquashKeyA(
        pWorkSpace->mIceLaneA + (W_KEY * 1U),
        pWorkSpace->mIceLaneB + (W_KEY * 1U),
        pWorkSpace->mIceLaneC + (W_KEY * 1U),
        pWorkSpace->mIceLaneD + (W_KEY * 1U),
        &(pWorkSpace->mKeyBoxB[0][0]));
}

// keep
void TwistExpander_Aldebaran::KeyDiffuse_A_A_A(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_A_A_PlasmaLaneA,
        ALDEBARAN_KEY_A_A_PlasmaLaneB,
        ALDEBARAN_KEY_A_A_PlasmaLaneC,
        ALDEBARAN_KEY_A_A_PlasmaLaneD,
        ALDEBARAN_KEY_A_A_RainbowLaneA,
        ALDEBARAN_KEY_A_A_RainbowLaneB,
        ALDEBARAN_KEY_A_A_RainbowLaneC,
        ALDEBARAN_KEY_A_A_RainbowLaneD,
        ALDEBARAN_KEY_A_A_ArcaneLaneA,
        ALDEBARAN_KEY_A_A_ArcaneLaneB,
        ALDEBARAN_KEY_A_A_ArcaneLaneC,
        ALDEBARAN_KEY_A_A_ArcaneLaneD,
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
}

// keep
void TwistExpander_Aldebaran::KeyDiffuse_A_B_A(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_B_A_PlasmaLaneA,
        ALDEBARAN_KEY_B_A_PlasmaLaneB,
        ALDEBARAN_KEY_B_A_PlasmaLaneC,
        ALDEBARAN_KEY_B_A_PlasmaLaneD,
        ALDEBARAN_KEY_B_A_RainbowLaneA,
        ALDEBARAN_KEY_B_A_RainbowLaneB,
        ALDEBARAN_KEY_B_A_RainbowLaneC,
        ALDEBARAN_KEY_B_A_RainbowLaneD,
        ALDEBARAN_KEY_B_A_ArcaneLaneA,
        ALDEBARAN_KEY_B_A_ArcaneLaneB,
        ALDEBARAN_KEY_B_A_ArcaneLaneC,
        ALDEBARAN_KEY_B_A_ArcaneLaneD,
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

// keep
void TwistExpander_Aldebaran::KeyDiffuse_B_A_A(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_A_A_VaporLaneA,
        ALDEBARAN_KEY_A_A_VaporLaneB,
        ALDEBARAN_KEY_A_A_VaporLaneC,
        ALDEBARAN_KEY_A_A_VaporLaneD,
        ALDEBARAN_KEY_A_A_FrostLaneA,
        ALDEBARAN_KEY_A_A_FrostLaneB,
        ALDEBARAN_KEY_A_A_FrostLaneC,
        ALDEBARAN_KEY_A_A_FrostLaneD,
        ALDEBARAN_KEY_A_A_WaterLaneA,
        ALDEBARAN_KEY_A_A_WaterLaneB,
        ALDEBARAN_KEY_A_A_WaterLaneC,
        ALDEBARAN_KEY_A_A_WaterLaneD,
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
}

//keep
void TwistExpander_Aldebaran::KeyDiffuse_B_B_A(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_B_A_VaporLaneA,
        ALDEBARAN_KEY_B_A_VaporLaneB,
        ALDEBARAN_KEY_B_A_VaporLaneC,
        ALDEBARAN_KEY_B_A_VaporLaneD,
        ALDEBARAN_KEY_B_A_FrostLaneA,
        ALDEBARAN_KEY_B_A_FrostLaneB,
        ALDEBARAN_KEY_B_A_FrostLaneC,
        ALDEBARAN_KEY_B_A_FrostLaneD,
        ALDEBARAN_KEY_B_A_WaterLaneA,
        ALDEBARAN_KEY_B_A_WaterLaneB,
        ALDEBARAN_KEY_B_A_WaterLaneC,
        ALDEBARAN_KEY_B_A_WaterLaneD,
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
