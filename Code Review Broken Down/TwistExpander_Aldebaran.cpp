
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
        aDivinationLaneA, aDivinationLaneB, aDivinationLaneC, aDivinationLaneD, // output lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D,
        &mMatrix,
        aDomainWordMatrixSelectA, aDomainWordMatrixSelectB,
        aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB,
        aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

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
    TwistExpander_Aldebaran_Arx::KDF_C_C_A(PARAMS_KDF);

}

void TwistExpander_Aldebaran::Seed(TwistWorkSpace *pWorkSpace,
                                 TwistFarmSalt *pFarmSalt,
                                 std::uint64_t pNonce,
                                 std::uint8_t *pPassword,
                                 std::size_t pPasswordByteLength,
                                 std::uint8_t *pDestination,
                                 MUTABLE_PARAMS) {
    if ((pWorkSpace == nullptr) || (pFarmSalt == nullptr) ||
        (pDestination == nullptr) || MUTABLE_PARAMS_ARE_NULL) { return; }

    UnrollPassword(pWorkSpace->mSourceLane, pPassword, pPasswordByteLength);
    UnrollNonce(pWorkSpace->mNonceLane, pNonce);
    mDomainBundleInbuilt.mKeyRotateASalts = kKeyRotateASalts;
    mDomainBundleInbuilt.mKeyRotateAConstants = kKeyRotateAConstants;
    mDomainBundleInbuilt.mKeyRotateBSalts = kKeyRotateBSalts;
    mDomainBundleInbuilt.mKeyRotateBConstants = kKeyRotateBConstants;
    mDomainBundleInbuilt.mKeySpawnASalts = kKeySpawnASalts;
    mDomainBundleInbuilt.mKeySpawnAConstants = kKeySpawnAConstants;
    mDomainBundleInbuilt.mKeySpawnBSalts = kKeySpawnBSalts;
    mDomainBundleInbuilt.mKeySpawnBConstants = kKeySpawnBConstants;
    mDomainBundleInbuilt.mSeedSalts = kSeedSalts;
    mDomainBundleInbuilt.mSeedConstants = kSeedConstants;
    mDomainBundleInbuilt.mTwistSalts = kTwistSalts;
    mDomainBundleInbuilt.mTwistConstants = kTwistConstants;
    mDomainBundleEphemeralA.Zero();
    mDomainBundleEphemeralB.Zero();
    pWorkSpace->mDomainBundle.Zero();
    
    std::uint64_t aIngress = *pIngress + 0x6278A02D0FBE5D64ULL;
    std::uint64_t aCarry = *pCarry + 0x7E0F6FA207027CDEULL;
    std::uint64_t aWandererA = *pWandererA + 0xA8977CD24D567F50ULL;
    std::uint64_t aWandererB = *pWandererB + 0xC45CF33D3D818AC6ULL;
    std::uint64_t aWandererC = *pWandererC + 0xAC6DD18CC6BA0278ULL;
    std::uint64_t aWandererD = *pWandererD + 0x3B4D8EEE5D18557BULL;
    std::uint64_t aWandererE = *pWandererE + 0x20AD0C6928DA06E8ULL;
    std::uint64_t aWandererF = *pWandererF + 0xA366627E9ED4C707ULL;
    std::uint64_t aWandererG = *pWandererG + 0xD849D2F392E4072FULL;
    std::uint64_t aWandererH = *pWandererH + 0x122A461B2DE75A62ULL;
    std::uint64_t aWandererI = *pWandererI + 0x3AA96EDF35C43107ULL;
    std::uint64_t aWandererJ = *pWandererJ + 0x80FE118B47D63019ULL;
    std::uint64_t aWandererK = *pWandererK + 0x4F1E59779205D1EAULL;

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
    // src: [$abjuration]
    // dst: [$aether]
    //
    KDF_C_B(pWorkSpace, pNonce, &(mDomainBundleEphemeralB.mKeyRotateBConstants), &(mDomainBundleEphemeralB.mKeyRotateBSalts), ARX_STATE_VARS);

    TwistFarm::Farm(pFarmSalt,
                    aCrystalLaneB, aCrystalLaneC, aCrystalLaneD, aCrystalLaneA, // farm lanes
                    aStasisLaneA, aStasisLaneB, aStasisLaneC, // temp/fold lanes
                    &pWorkSpace->mDomainBundle.mKeyRotateBSalts,
                    &(pWorkSpace->mDomainBundle.mKeyRotateBConstants));
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

    pWorkSpace->Zero_PostSeed();

    Zero_PostSeed();
}

void TwistExpander_Aldebaran::TwistBlock() {
    
    std::uint64_t aIngress = *pIngress + 0x09BDB5B86B41E95DULL;
    std::uint64_t aCarry = *pCarry + 0xB2DCB57BB2C12D7BULL;
    std::uint64_t aWandererA = *pWandererA + 0xD8320828E2C8AB84ULL;
    std::uint64_t aWandererB = *pWandererB + 0x97D09A813CDC2F8EULL;
    std::uint64_t aWandererC = *pWandererC + 0x3BEBE53B8B15F351ULL;
    std::uint64_t aWandererD = *pWandererD + 0x3A46FC2746D2CA77ULL;
    std::uint64_t aWandererE = *pWandererE + 0xB074B4921B984CC9ULL;
    std::uint64_t aWandererF = *pWandererF + 0xA265A5CC7F25BDF2ULL;
    std::uint64_t aWandererG = *pWandererG + 0x85D6255D21F4AEB0ULL;
    std::uint64_t aWandererH = *pWandererH + 0xDD4225F2FC7EB204ULL;
    std::uint64_t aWandererI = *pWandererI + 0x63D9677B3EED9D9DULL;
    std::uint64_t aWandererJ = *pWandererJ + 0x79F30E7883C7AFB2ULL;
    std::uint64_t aWandererK = *pWandererK + 0x7B735540EB8434F9ULL;

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

void TwistExpander_Aldebaran::GrowKeyA() {
    //
    // src: [$spirit, cross_a, cross_b]
    // dst: [$arcane]
    //
    TwistExpander_Aldebaran_Arx::GROW_A_A(PARAMS_GROW_CROSS);

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
    TwistExpander_Aldebaran_Arx::GROW_B_A(PARAMS_GROW_CROSS);

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
