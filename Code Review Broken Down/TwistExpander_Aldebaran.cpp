
void TwistExpander_Aldebaran::KDF_A_A(TwistWorkSpace *pWorkSpace,
               std::uint64_t pNonce,
               TwistDomainConstants *pConstants,
               TwistDomainSaltSet *pDomainSaltSet,
               MUTABLE_PARAMS) {
    std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    std::uint8_t *aShadowLaneA = pWorkSpace->mShadowLaneA;
    std::uint8_t *aShadowLaneB = pWorkSpace->mShadowLaneB;
    std::uint8_t *aShadowLaneC = pWorkSpace->mShadowLaneC;
    std::uint8_t *aShadowLaneD = pWorkSpace->mShadowLaneD;
    std::uint8_t *aVaporLaneA = pWorkSpace->mVaporLaneA;
    std::uint8_t *aVaporLaneB = pWorkSpace->mVaporLaneB;
    std::uint8_t *aVaporLaneC = pWorkSpace->mVaporLaneC;
    std::uint8_t *aVaporLaneD = pWorkSpace->mVaporLaneD;
    std::size_t *aIndexList256A = pWorkSpace->mIndexList256A;
    std::size_t *aIndexList256B = pWorkSpace->mIndexList256B;
    std::size_t *aIndexList256C = pWorkSpace->mIndexList256C;
    std::size_t *aIndexList256D = pWorkSpace->mIndexList256D;

    std::uint64_t aDomainWordMatrixSelectA = pConstants->mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pConstants->mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pConstants->mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pConstants->mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pConstants->mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pConstants->mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pConstants->mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pConstants->mMatrixArgD;

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
        aShadowLaneA, aShadowLaneB, aShadowLaneC, aShadowLaneD, // entropy lanes
        aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD,  // input lanes
        aVaporLaneA, aVaporLaneB, aVaporLaneC, aVaporLaneD, // output lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
        &mMatrix,
        aDomainWordMatrixSelectA, aDomainWordMatrixSelectB,
        aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB,
        aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    //
    // src: [$vapor]
    // dst: [$kinetic]
    //
    TwistExpander_Aldebaran_Arx::KDF_A_C_A(PARAMS_KDF);

}

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
        aEvocationLaneA, aEvocationLaneB, aEvocationLaneC, aEvocationLaneD, // entropy lanes
        aRunicLaneA, aRunicLaneB, aRunicLaneC, aRunicLaneD,  // input lanes
        aDivinationLaneA, aDivinationLaneB, aDivinationLaneC, aDivinationLaneD); // output lanes


    //
    // src: [$divination]
    // dst: [$abjuration]
    //
    TwistExpander_Aldebaran_Arx::KDF_B_C_A(PARAMS_KDF);

}

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
        aAetherLaneA, aAetherLaneB, aAetherLaneC, aAetherLaneD, // entropy lanes
        aLunarLaneA, aLunarLaneB, aLunarLaneC, aLunarLaneD,  // input lanes
        aEarthLaneA, aEarthLaneB, aEarthLaneC, aEarthLaneD); // output lanes

    //
    // src: [$earth]
    // dst: [$crystal]
    //
    TwistExpander_Aldebaran_Arx::KDF_C_C_A(PARAMS_KDF);

}

void TwistExpander_Aldebaran::Seed(TwistWorkSpace *pWorkSpace,
                                 TwistFarmSalt *pFarmSalt,
                                 std::uint64_t pNonce,
                                 std::uint8_t *pPassword,
                                 std::size_t pPasswordByteLength,
                                 std::uint8_t *pDestination,
                                 MUTABLE_PARAMS) {
    
    std::uint64_t aIngress = *pIngress + 0xEDBBF8A99E501354ULL;
    std::uint64_t aCarry = *pCarry + 0x7119307BD2710827ULL;
    std::uint64_t aWandererA = *pWandererA + 0x2F99236D65F85FA0ULL;
    std::uint64_t aWandererB = *pWandererB + 0x87D4A07BE8160282ULL;
    std::uint64_t aWandererC = *pWandererC + 0xB267A1B890FE5A14ULL;
    std::uint64_t aWandererD = *pWandererD + 0xC2B1A1572AA7AF89ULL;
    std::uint64_t aWandererE = *pWandererE + 0x2CCA1D49997B728CULL;
    std::uint64_t aWandererF = *pWandererF + 0xF12FC7DF4251D512ULL;
    std::uint64_t aWandererG = *pWandererG + 0x277EAFE42216794FULL;
    std::uint64_t aWandererH = *pWandererH + 0x47D91C37F46A80CULL;
    std::uint64_t aWandererI = *pWandererI + 0x7AA854D7E7B09E57ULL;
    std::uint64_t aWandererJ = *pWandererJ + 0x2D6827D768F23865ULL;
    std::uint64_t aWandererK = *pWandererK + 0x9A550466920B3A69ULL;

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
    // Domain 2 of 6, key b rotate:
    //
    // src: [source, nonce]
    // dst: [$shadow]
    //
    KDF_A_B(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), ARX_STATE_VARS);

    TwistFarm::Farm(pFarmSalt,
                    aKineticLaneB, aKineticLaneC, aKineticLaneD, aKineticLaneA, // farm lanes
                    aStasisLaneA, aStasisLaneB, aStasisLaneC, // temp/fold lanes
                    &mDomainBundleEphemeralA.mKeyRotateBSalts,
                    &(mDomainBundleEphemeralA.mKeyRotateBConstants));

    //
    // src: [$kinetic]
    // dst: [$evocation]
    //
    KDF_B_B(pWorkSpace, pNonce, &(mDomainBundleEphemeralA.mKeyRotateBConstants), &(mDomainBundleEphemeralA.mKeyRotateBSalts), ARX_STATE_VARS);

    TwistFarm::Farm(pFarmSalt,
                    aAbjurationLaneB, aAbjurationLaneC, aAbjurationLaneD, aAbjurationLaneA, // farm lanes
                    aStasisLaneA, aStasisLaneB, aStasisLaneC, // temp/fold lanes
                    &mDomainBundleEphemeralB.mKeyRotateBSalts,
                    &(mDomainBundleEphemeralB.mKeyRotateBConstants));
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

    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mSeedConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mSeedConstants.mMatrixSelectB;

    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mSeedConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mSeedConstants.mMatrixUnrollB;

    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mSeedConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mSeedConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mSeedConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mSeedConstants.mMatrixArgD;

    TwistDiffuse::DiffuseWithDomainWords(
        aIceLaneA, aIceLaneB, aIceLaneC, aIceLaneD, // entropy lanes
        aRainbowLaneA, aRainbowLaneB, aRainbowLaneC, aRainbowLaneD,  // input lanes
        aAlchemyLaneA, aAlchemyLaneB, aAlchemyLaneC, aAlchemyLaneD, // output lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
        &mMatrix,
        aDomainWordMatrixSelectA, aDomainWordMatrixSelectB,
        aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB,
        aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

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

    TwistDiffuse::DiffuseWithDomainWords(
        aAuguryLaneA, aAuguryLaneB, aAuguryLaneC, aAuguryLaneD, // entropy lanes
        aSpiritLaneA, aSpiritLaneB, aSpiritLaneC, aSpiritLaneD,  // input lanes
        aDivinationLaneA, aDivinationLaneB, aDivinationLaneC, aDivinationLaneD, // output lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
        &mMatrix,
        aDomainWordMatrixSelectA, aDomainWordMatrixSelectB,
        aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB,
        aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

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

    TwistDiffuse::DiffuseWithDomainWords(
        aPsychicLaneA, aPsychicLaneB, aPsychicLaneC, aPsychicLaneD, // entropy lanes
        aVoodooLaneA, aVoodooLaneB, aVoodooLaneC, aVoodooLaneD,  // input lanes
        aVaporLaneA, aVaporLaneB, aVaporLaneC, aVaporLaneD, // output lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
        &mMatrix,
        aDomainWordMatrixSelectA, aDomainWordMatrixSelectB,
        aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB,
        aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    //
    // src: [$vapor]
    // dst: [$sonic]
    //
    TwistExpander_Aldebaran_Arx::SEED_G(PARAMS_SEED);

    //
    // src: [$sonic]
    // dst: [$planar]
    //
    TwistExpander_Aldebaran_Arx::SEED_H(PARAMS_SEED);

    TwistDiffuse::DiffuseWithDomainWords(
        aSonicLaneA, aSonicLaneB, aSonicLaneC, aSonicLaneD, // entropy lanes
        aPlanarLaneA, aPlanarLaneB, aPlanarLaneC, aPlanarLaneD,  // input lanes
        aFrostLaneA, aFrostLaneB, aFrostLaneC, aFrostLaneD, // output lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
        &mMatrix,
        aDomainWordMatrixSelectA, aDomainWordMatrixSelectB,
        aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB,
        aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    //
    // src: [$frost]
    // dst: [$gloom]
    //
    TwistExpander_Aldebaran_Arx::SEED_I(PARAMS_SEED);

    //
    // src: [$gloom]
    // dst: [$lightning]
    //
    TwistExpander_Aldebaran_Arx::SEED_J(PARAMS_SEED);

    TwistDiffuse::DiffuseWithDomainWords(
        aGloomLaneA, aGloomLaneB, aGloomLaneC, aGloomLaneD, // entropy lanes
        aLightningLaneA, aLightningLaneB, aLightningLaneC, aLightningLaneD,  // input lanes
        aWindLaneA, aWindLaneB, aWindLaneC, aWindLaneD, // output lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
        &mMatrix,
        aDomainWordMatrixSelectA, aDomainWordMatrixSelectB,
        aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB,
        aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

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

    TwistDiffuse::DiffuseWithDomainWords(
        aShadowLaneA, aShadowLaneB, aShadowLaneC, aShadowLaneD, // entropy lanes
        aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD,  // input lanes
        aKineticLaneA, aKineticLaneB, aKineticLaneC, aKineticLaneD, // output lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
        &mMatrix,
        aDomainWordMatrixSelectA, aDomainWordMatrixSelectB,
        aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB,
        aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

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

    TwistDiffuse::DiffuseWithDomainWords(
        aEvocationLaneA, aEvocationLaneB, aEvocationLaneC, aEvocationLaneD, // entropy lanes
        aRunicLaneA, aRunicLaneB, aRunicLaneC, aRunicLaneD,  // input lanes
        aAbjurationLaneA, aAbjurationLaneB, aAbjurationLaneC, aAbjurationLaneD, // output lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
        &mMatrix,
        aDomainWordMatrixSelectA, aDomainWordMatrixSelectB,
        aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB,
        aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

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

    TwistDiffuse::DiffuseWithDomainWords(
        aAetherLaneA, aAetherLaneB, aAetherLaneC, aAetherLaneD, // entropy lanes
        aLunarLaneA, aLunarLaneB, aLunarLaneC, aLunarLaneD,  // input lanes
        aEarthLaneA, aEarthLaneB, aEarthLaneC, aEarthLaneD, // output lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
        &mMatrix,
        aDomainWordMatrixSelectA, aDomainWordMatrixSelectB,
        aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB,
        aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

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
    TwistSquash::SquashA(pWorkSpace->mCrystalLaneA, pWorkSpace->mCrystalLaneB, pWorkSpace->mCrystalLaneC, pWorkSpace->mCrystalLaneD, pDestination);
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

    ...
    ...

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

void TwistExpander_Aldebaran::TwistBlock(TwistWorkSpace *pWorkSpace,
                                       std::uint8_t *pSource,
                                       std::uint8_t *pCrossLaneA,
                                       std::uint8_t *pCrossLaneB,
                                       std::uint8_t *pCrossLaneC,
                                       std::uint8_t *pCrossLaneD,
                                       std::uint8_t *pDestination,
                                       bool pStifleKey,
                                       MUTABLE_PARAMS) {
    if ((pWorkSpace == nullptr) || (pSource == nullptr) ||
        (pCrossLaneA == nullptr) || (pCrossLaneB == nullptr) ||
        (pCrossLaneC == nullptr) || (pCrossLaneD == nullptr) ||
        (pDestination == nullptr) || MUTABLE_PARAMS_ARE_NULL) { return; }
    std::uint8_t *aEarthLaneA = pWorkSpace->mEarthLaneA;
    std::uint8_t *aEarthLaneB = pWorkSpace->mEarthLaneB;
    std::uint8_t *aEarthLaneC = pWorkSpace->mEarthLaneC;
    std::uint8_t *aEarthLaneD = pWorkSpace->mEarthLaneD;
    std::uint8_t *aAetherLaneA = pWorkSpace->mAetherLaneA;
    std::uint8_t *aAetherLaneB = pWorkSpace->mAetherLaneB;
    std::uint8_t *aAetherLaneC = pWorkSpace->mAetherLaneC;
    std::uint8_t *aAetherLaneD = pWorkSpace->mAetherLaneD;
    std::uint8_t *aLunarLaneA = pWorkSpace->mLunarLaneA;
    std::uint8_t *aLunarLaneB = pWorkSpace->mLunarLaneB;
    std::uint8_t *aLunarLaneC = pWorkSpace->mLunarLaneC;
    std::uint8_t *aLunarLaneD = pWorkSpace->mLunarLaneD;
    std::size_t *aIndexList256A = pWorkSpace->mIndexList256A;
    std::size_t *aIndexList256B = pWorkSpace->mIndexList256B;
    std::size_t *aIndexList256C = pWorkSpace->mIndexList256C;
    std::size_t *aIndexList256D = pWorkSpace->mIndexList256D;

    std::uint64_t aIngress = *pIngress + 0xF459E9EDD2E96098ULL;
    std::uint64_t aCarry = *pCarry + 0xDCD6BED954525357ULL;
    std::uint64_t aWandererA = *pWandererA + 0x5B546BA4497DCA7DULL;
    std::uint64_t aWandererB = *pWandererB + 0x3F80AD0E5F01C5B1ULL;
    std::uint64_t aWandererC = *pWandererC + 0xB3D63F9B2AAEBC0DULL;
    std::uint64_t aWandererD = *pWandererD + 0x4E88BAA1729C15AAULL;
    std::uint64_t aWandererE = *pWandererE + 0x7788C3442248CA42ULL;
    std::uint64_t aWandererF = *pWandererF + 0x23616574A785B65BULL;
    std::uint64_t aWandererG = *pWandererG + 0x17C8D2688354781EULL;
    std::uint64_t aWandererH = *pWandererH + 0xAA5E58A22F290CABULL;
    std::uint64_t aWandererI = *pWandererI + 0x5FB9CF3072696145ULL;
    std::uint64_t aWandererJ = *pWandererJ + 0xE4044C50AC250CCDULL;
    std::uint64_t aWandererK = *pWandererK + 0xEFD749887F6B68E4ULL;

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

    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mTwistConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mTwistConstants.mMatrixSelectB;

    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mTwistConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mTwistConstants.mMatrixUnrollB;

    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mTwistConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mTwistConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mTwistConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mTwistConstants.mMatrixArgD;

    TwistDiffuse::DiffuseWithDomainWords(
        aAetherLaneA, aAetherLaneB, aAetherLaneC, aAetherLaneD, // entropy lanes
        aLunarLaneA, aLunarLaneB, aLunarLaneC, aLunarLaneD,  // input lanes
        aEarthLaneA, aEarthLaneB, aEarthLaneC, aEarthLaneD, // output lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
        &mMatrix,
        aDomainWordMatrixSelectA, aDomainWordMatrixSelectB,
        aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB,
        aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

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
    TwistSquash::SquashB(pWorkSpace->mCrystalLaneA, pWorkSpace->mCrystalLaneB, pWorkSpace->mCrystalLaneC, pWorkSpace->mCrystalLaneD, pDestination);
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

    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mKeyRotateAConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mKeyRotateAConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mKeyRotateAConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mKeyRotateAConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mKeyRotateAConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mKeyRotateAConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mKeyRotateAConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mKeyRotateAConstants.mMatrixArgD;

    TwistDiffuse::KeyDiffuseWithDomainWordsA(
        pWorkSpace->mArcaneLaneA, pWorkSpace->mArcaneLaneB, // entropy lanes
        pWorkSpace->mArcaneLaneC, pWorkSpace->mArcaneLaneD, // entropy lanes
        pWorkSpace->mPlasmaLaneA, pWorkSpace->mPlasmaLaneB, // input lanes
        pWorkSpace->mPlasmaLaneC, pWorkSpace->mPlasmaLaneD, // input lanes
        pWorkSpace->mRainbowLaneA, pWorkSpace->mRainbowLaneB, // output lanes
        pWorkSpace->mRainbowLaneC, pWorkSpace->mRainbowLaneD, // output lanes
        pWorkSpace->mIndexList256A, pWorkSpace->mIndexList256B, pWorkSpace->mIndexList256C, pWorkSpace->mIndexList256D,
        &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB,
        aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB,
        aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

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

    TwistDiffuse::KeyDiffuseWithDomainWordsA(
        pWorkSpace->mWaterLaneA, pWorkSpace->mWaterLaneB, // entropy lanes
        pWorkSpace->mWaterLaneC, pWorkSpace->mWaterLaneD, // entropy lanes
        pWorkSpace->mVaporLaneA, pWorkSpace->mVaporLaneB, // input lanes
        pWorkSpace->mVaporLaneC, pWorkSpace->mVaporLaneD, // input lanes
        pWorkSpace->mFrostLaneA, pWorkSpace->mFrostLaneB, // output lanes
        pWorkSpace->mFrostLaneC, pWorkSpace->mFrostLaneD, // output lanes
        pWorkSpace->mIndexList256A, pWorkSpace->mIndexList256B, pWorkSpace->mIndexList256C, pWorkSpace->mIndexList256D,
        &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB,
        aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB,
        aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

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

    std::uint64_t aDomainWordMatrixSelectA = pWorkSpace->mDomainBundle.mKeyRotateBConstants.mMatrixSelectA;
    std::uint64_t aDomainWordMatrixSelectB = pWorkSpace->mDomainBundle.mKeyRotateBConstants.mMatrixSelectB;
    std::uint8_t aDomainWordMatrixUnrollA = pWorkSpace->mDomainBundle.mKeyRotateBConstants.mMatrixUnrollA;
    std::uint8_t aDomainWordMatrixUnrollB = pWorkSpace->mDomainBundle.mKeyRotateBConstants.mMatrixUnrollB;
    std::uint8_t aDomainWordMatrixArgA = pWorkSpace->mDomainBundle.mKeyRotateBConstants.mMatrixArgA;
    std::uint8_t aDomainWordMatrixArgB = pWorkSpace->mDomainBundle.mKeyRotateBConstants.mMatrixArgB;
    std::uint8_t aDomainWordMatrixArgC = pWorkSpace->mDomainBundle.mKeyRotateBConstants.mMatrixArgC;
    std::uint8_t aDomainWordMatrixArgD = pWorkSpace->mDomainBundle.mKeyRotateBConstants.mMatrixArgD;

    TwistDiffuse::KeyDiffuseWithDomainWordsB(
        pWorkSpace->mArcaneLaneA, pWorkSpace->mArcaneLaneB, // entropy lanes
        pWorkSpace->mArcaneLaneC, pWorkSpace->mArcaneLaneD, // entropy lanes
        pWorkSpace->mPlasmaLaneA, pWorkSpace->mPlasmaLaneB, // input lanes
        pWorkSpace->mPlasmaLaneC, pWorkSpace->mPlasmaLaneD, // input lanes
        pWorkSpace->mRainbowLaneA, pWorkSpace->mRainbowLaneB, // output lanes
        pWorkSpace->mRainbowLaneC, pWorkSpace->mRainbowLaneD, // output lanes
        pWorkSpace->mIndexList256A, pWorkSpace->mIndexList256B, pWorkSpace->mIndexList256C, pWorkSpace->mIndexList256D,
        &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB,
        aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB,
        aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

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

    TwistDiffuse::KeyDiffuseWithDomainWordsB(
        pWorkSpace->mWaterLaneA, pWorkSpace->mWaterLaneB, // entropy lanes
        pWorkSpace->mWaterLaneC, pWorkSpace->mWaterLaneD, // entropy lanes
        pWorkSpace->mVaporLaneA, pWorkSpace->mVaporLaneB, // input lanes
        pWorkSpace->mVaporLaneC, pWorkSpace->mVaporLaneD, // input lanes
        pWorkSpace->mFrostLaneA, pWorkSpace->mFrostLaneB, // output lanes
        pWorkSpace->mFrostLaneC, pWorkSpace->mFrostLaneD, // output lanes
        pWorkSpace->mIndexList256A, pWorkSpace->mIndexList256B, pWorkSpace->mIndexList256C, pWorkSpace->mIndexList256D,
        &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB,
        aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB,
        aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

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

void TwistExpander_Aldebaran::KeyDiffuse_A_A_A(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_A_A_ArcaneLaneA, ALDEBARAN_KEY_A_A_ArcaneLaneB, // entropy lanes
        ALDEBARAN_KEY_A_A_ArcaneLaneC, ALDEBARAN_KEY_A_A_ArcaneLaneD, // entropy lanes
        ALDEBARAN_KEY_A_A_PlasmaLaneA, ALDEBARAN_KEY_A_A_PlasmaLaneB, // input lanes
        ALDEBARAN_KEY_A_A_PlasmaLaneC, ALDEBARAN_KEY_A_A_PlasmaLaneD, // input lanes
        ALDEBARAN_KEY_A_A_RainbowLaneA, ALDEBARAN_KEY_A_A_RainbowLaneB, // output lanes
        ALDEBARAN_KEY_A_A_RainbowLaneC, ALDEBARAN_KEY_A_A_RainbowLaneD, // output lanes
        pWorkSpace->mIndexList256A, pWorkSpace->mIndexList256B, pWorkSpace->mIndexList256C, pWorkSpace->mIndexList256D,
        &mMatrix, pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixSelectA, pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixSelectB,
        pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixUnrollA, pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixUnrollB,
        pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixArgA, pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixArgB, pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixArgC, pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixArgD);
}

void TwistExpander_Aldebaran::KeyDiffuse_A_A_B(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_A_B_ArcaneLaneA, ALDEBARAN_KEY_A_B_ArcaneLaneB, // entropy lanes
        ALDEBARAN_KEY_A_B_ArcaneLaneC, ALDEBARAN_KEY_A_B_ArcaneLaneD, // entropy lanes
        ALDEBARAN_KEY_A_B_PlasmaLaneA, ALDEBARAN_KEY_A_B_PlasmaLaneB, // input lanes
        ALDEBARAN_KEY_A_B_PlasmaLaneC, ALDEBARAN_KEY_A_B_PlasmaLaneD, // input lanes
        ALDEBARAN_KEY_A_B_RainbowLaneA, ALDEBARAN_KEY_A_B_RainbowLaneB, // output lanes
        ALDEBARAN_KEY_A_B_RainbowLaneC, ALDEBARAN_KEY_A_B_RainbowLaneD, // output lanes
        pWorkSpace->mIndexList256A, pWorkSpace->mIndexList256B, pWorkSpace->mIndexList256C, pWorkSpace->mIndexList256D,
        &mMatrix, pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixSelectA, pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixSelectB,
        pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixUnrollA, pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixUnrollB,
        pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixArgA, pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixArgB, pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixArgC, pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixArgD);
}

void TwistExpander_Aldebaran::KeyDiffuse_B_A_A(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_A_A_WaterLaneA, ALDEBARAN_KEY_A_A_WaterLaneB, // entropy lanes
        ALDEBARAN_KEY_A_A_WaterLaneC, ALDEBARAN_KEY_A_A_WaterLaneD, // entropy lanes
        ALDEBARAN_KEY_A_A_VaporLaneA, ALDEBARAN_KEY_A_A_VaporLaneB, // input lanes
        ALDEBARAN_KEY_A_A_VaporLaneC, ALDEBARAN_KEY_A_A_VaporLaneD, // input lanes
        ALDEBARAN_KEY_A_A_FrostLaneA, ALDEBARAN_KEY_A_A_FrostLaneB, // output lanes
        ALDEBARAN_KEY_A_A_FrostLaneC, ALDEBARAN_KEY_A_A_FrostLaneD, // output lanes
        pWorkSpace->mIndexList256A, pWorkSpace->mIndexList256B, pWorkSpace->mIndexList256C, pWorkSpace->mIndexList256D,
        &mMatrix, pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixSelectA, pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixSelectB,
        pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixUnrollA, pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixUnrollB,
        pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixArgA, pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixArgB, pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixArgC, pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixArgD);
}

void TwistExpander_Aldebaran::KeyDiffuse_B_A_B(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_A_B_WaterLaneA, ALDEBARAN_KEY_A_B_WaterLaneB, // entropy lanes
        ALDEBARAN_KEY_A_B_WaterLaneC, ALDEBARAN_KEY_A_B_WaterLaneD, // entropy lanes
        ALDEBARAN_KEY_A_B_VaporLaneA, ALDEBARAN_KEY_A_B_VaporLaneB, // input lanes
        ALDEBARAN_KEY_A_B_VaporLaneC, ALDEBARAN_KEY_A_B_VaporLaneD, // input lanes
        ALDEBARAN_KEY_A_B_FrostLaneA, ALDEBARAN_KEY_A_B_FrostLaneB, // output lanes
        ALDEBARAN_KEY_A_B_FrostLaneC, ALDEBARAN_KEY_A_B_FrostLaneD, // output lanes
        pWorkSpace->mIndexList256A, pWorkSpace->mIndexList256B, pWorkSpace->mIndexList256C, pWorkSpace->mIndexList256D,
        &mMatrix, pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixSelectA, pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixSelectB,
        pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixUnrollA, pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixUnrollB,
        pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixArgA, pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixArgB, pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixArgC, pWorkSpace->mDomainBundle.mKeySpawnAConstants.mMatrixArgD);
}
