void TwistExpander_Aldebaran::KDF_A_A(TwistWorkSpace *pWorkSpace,
               std::uint64_t pNonce,
               TwistDomainConstants *pConstants,
               TwistDomainSaltSet *pDomainSaltSet,
               MUTABLE_PARAMS) {
    std::uint8_t *aSpiritLaneA = pWorkSpace->mSpiritLaneA;
    std::uint8_t *aSpiritLaneB = pWorkSpace->mSpiritLaneB;
    std::uint8_t *aSpiritLaneC = pWorkSpace->mSpiritLaneC;
    std::uint8_t *aSpiritLaneD = pWorkSpace->mSpiritLaneD;
    std::uint8_t *aWaterLaneA = pWorkSpace->mWaterLaneA;
    std::uint8_t *aWaterLaneB = pWorkSpace->mWaterLaneB;
    std::uint8_t *aWaterLaneC = pWorkSpace->mWaterLaneC;
    std::uint8_t *aWaterLaneD = pWorkSpace->mWaterLaneD;
    std::uint8_t *aEarthLaneA = pWorkSpace->mEarthLaneA;
    std::uint8_t *aEarthLaneB = pWorkSpace->mEarthLaneB;
    std::uint8_t *aEarthLaneC = pWorkSpace->mEarthLaneC;
    std::uint8_t *aEarthLaneD = pWorkSpace->mEarthLaneD;
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

    TwistExpander_Aldebaran_Arx::KDF_A_A_A(PARAMS_KDF);

    TwistExpander_Aldebaran_Arx::KDF_A_B_A(PARAMS_KDF);

    TwistDiffuse::DiffuseWithDomainWords(
        aSpiritLaneA, aSpiritLaneB, aSpiritLaneC, aSpiritLaneD,  // input lanes
        aEarthLaneA, aEarthLaneB, aEarthLaneC, aEarthLaneD, // output lanes
        aWaterLaneA, aWaterLaneB, aWaterLaneC, aWaterLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    TwistExpander_Aldebaran_Arx::KDF_A_C_A(PARAMS_KDF);

}

void TwistExpander_Aldebaran::KDF_B_A(TwistWorkSpace *pWorkSpace,
               std::uint64_t pNonce,
               TwistDomainConstants *pConstants,
               TwistDomainSaltSet *pDomainSaltSet,
               MUTABLE_PARAMS) {
    std::uint8_t *aWindLaneA = pWorkSpace->mWindLaneA;
    std::uint8_t *aWindLaneB = pWorkSpace->mWindLaneB;
    std::uint8_t *aWindLaneC = pWorkSpace->mWindLaneC;
    std::uint8_t *aWindLaneD = pWorkSpace->mWindLaneD;
    std::uint8_t *aLightningLaneA = pWorkSpace->mLightningLaneA;
    std::uint8_t *aLightningLaneB = pWorkSpace->mLightningLaneB;
    std::uint8_t *aLightningLaneC = pWorkSpace->mLightningLaneC;
    std::uint8_t *aLightningLaneD = pWorkSpace->mLightningLaneD;
    std::uint8_t *aCrystalLaneA = pWorkSpace->mCrystalLaneA;
    std::uint8_t *aCrystalLaneB = pWorkSpace->mCrystalLaneB;
    std::uint8_t *aCrystalLaneC = pWorkSpace->mCrystalLaneC;
    std::uint8_t *aCrystalLaneD = pWorkSpace->mCrystalLaneD;
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

    TwistExpander_Aldebaran_Arx::KDF_B_A_A(PARAMS_KDF);

    TwistExpander_Aldebaran_Arx::KDF_B_B_A(PARAMS_KDF);

    TwistDiffuse::DiffuseWithDomainWords(
        aLightningLaneA, aLightningLaneB, aLightningLaneC, aLightningLaneD,  // input lanes
        aWindLaneA, aWindLaneB, aWindLaneC, aWindLaneD, // output lanes
        aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, aCrystalLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    TwistExpander_Aldebaran_Arx::KDF_B_C_A(PARAMS_KDF);

}

void TwistExpander_Aldebaran::KDF_C_A(TwistWorkSpace *pWorkSpace,
               std::uint64_t pNonce,
               TwistDomainConstants *pConstants,
               TwistDomainSaltSet *pDomainSaltSet,
               MUTABLE_PARAMS) {
    std::uint8_t *aPlasmaLaneA = pWorkSpace->mPlasmaLaneA;
    std::uint8_t *aPlasmaLaneB = pWorkSpace->mPlasmaLaneB;
    std::uint8_t *aPlasmaLaneC = pWorkSpace->mPlasmaLaneC;
    std::uint8_t *aPlasmaLaneD = pWorkSpace->mPlasmaLaneD;
    std::uint8_t *aShadowLaneA = pWorkSpace->mShadowLaneA;
    std::uint8_t *aShadowLaneB = pWorkSpace->mShadowLaneB;
    std::uint8_t *aShadowLaneC = pWorkSpace->mShadowLaneC;
    std::uint8_t *aShadowLaneD = pWorkSpace->mShadowLaneD;
    std::uint8_t *aAetherLaneA = pWorkSpace->mAetherLaneA;
    std::uint8_t *aAetherLaneB = pWorkSpace->mAetherLaneB;
    std::uint8_t *aAetherLaneC = pWorkSpace->mAetherLaneC;
    std::uint8_t *aAetherLaneD = pWorkSpace->mAetherLaneD;
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

    TwistExpander_Aldebaran_Arx::KDF_C_A_A(PARAMS_KDF);

    TwistExpander_Aldebaran_Arx::KDF_C_B_A(PARAMS_KDF);

    TwistDiffuse::DiffuseWithDomainWords(
        aAetherLaneA, aAetherLaneB, aAetherLaneC, aAetherLaneD,  // input lanes
        aShadowLaneA, aShadowLaneB, aShadowLaneC, aShadowLaneD, // output lanes
        aPlasmaLaneA, aPlasmaLaneB, aPlasmaLaneC, aPlasmaLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    TwistExpander_Aldebaran_Arx::KDF_C_C_A(PARAMS_KDF);

}

void TwistExpander_Aldebaran::KDF_A_B(TwistWorkSpace *pWorkSpace,
               std::uint64_t pNonce,
               TwistDomainConstants *pConstants,
               TwistDomainSaltSet *pDomainSaltSet,
               MUTABLE_PARAMS) {
    std::uint8_t *aSpiritLaneA = pWorkSpace->mSpiritLaneA;
    std::uint8_t *aSpiritLaneB = pWorkSpace->mSpiritLaneB;
    std::uint8_t *aSpiritLaneC = pWorkSpace->mSpiritLaneC;
    std::uint8_t *aSpiritLaneD = pWorkSpace->mSpiritLaneD;
    std::uint8_t *aWaterLaneA = pWorkSpace->mWaterLaneA;
    std::uint8_t *aWaterLaneB = pWorkSpace->mWaterLaneB;
    std::uint8_t *aWaterLaneC = pWorkSpace->mWaterLaneC;
    std::uint8_t *aWaterLaneD = pWorkSpace->mWaterLaneD;
    std::uint8_t *aEarthLaneA = pWorkSpace->mEarthLaneA;
    std::uint8_t *aEarthLaneB = pWorkSpace->mEarthLaneB;
    std::uint8_t *aEarthLaneC = pWorkSpace->mEarthLaneC;
    std::uint8_t *aEarthLaneD = pWorkSpace->mEarthLaneD;
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

    TwistExpander_Aldebaran_Arx::KDF_A_A_B(PARAMS_KDF);

    TwistExpander_Aldebaran_Arx::KDF_A_B_B(PARAMS_KDF);

    TwistDiffuse::DiffuseWithDomainWords(
        aSpiritLaneA, aSpiritLaneB, aSpiritLaneC, aSpiritLaneD,  // input lanes
        aEarthLaneA, aEarthLaneB, aEarthLaneC, aEarthLaneD, // output lanes
        aWaterLaneA, aWaterLaneB, aWaterLaneC, aWaterLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    TwistExpander_Aldebaran_Arx::KDF_A_C_B(PARAMS_KDF);

}

void TwistExpander_Aldebaran::KDF_B_B(TwistWorkSpace *pWorkSpace,
               std::uint64_t pNonce,
               TwistDomainConstants *pConstants,
               TwistDomainSaltSet *pDomainSaltSet,
               MUTABLE_PARAMS) {
    std::uint8_t *aWindLaneA = pWorkSpace->mWindLaneA;
    std::uint8_t *aWindLaneB = pWorkSpace->mWindLaneB;
    std::uint8_t *aWindLaneC = pWorkSpace->mWindLaneC;
    std::uint8_t *aWindLaneD = pWorkSpace->mWindLaneD;
    std::uint8_t *aLightningLaneA = pWorkSpace->mLightningLaneA;
    std::uint8_t *aLightningLaneB = pWorkSpace->mLightningLaneB;
    std::uint8_t *aLightningLaneC = pWorkSpace->mLightningLaneC;
    std::uint8_t *aLightningLaneD = pWorkSpace->mLightningLaneD;
    std::uint8_t *aCrystalLaneA = pWorkSpace->mCrystalLaneA;
    std::uint8_t *aCrystalLaneB = pWorkSpace->mCrystalLaneB;
    std::uint8_t *aCrystalLaneC = pWorkSpace->mCrystalLaneC;
    std::uint8_t *aCrystalLaneD = pWorkSpace->mCrystalLaneD;
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

    TwistExpander_Aldebaran_Arx::KDF_B_A_B(PARAMS_KDF);

    TwistExpander_Aldebaran_Arx::KDF_B_B_B(PARAMS_KDF);

    TwistDiffuse::DiffuseWithDomainWords(
        aLightningLaneA, aLightningLaneB, aLightningLaneC, aLightningLaneD,  // input lanes
        aWindLaneA, aWindLaneB, aWindLaneC, aWindLaneD, // output lanes
        aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, aCrystalLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    TwistExpander_Aldebaran_Arx::KDF_B_C_B(PARAMS_KDF);

}

void TwistExpander_Aldebaran::KDF_C_B(TwistWorkSpace *pWorkSpace,
               std::uint64_t pNonce,
               TwistDomainConstants *pConstants,
               TwistDomainSaltSet *pDomainSaltSet,
               MUTABLE_PARAMS) {
    std::uint8_t *aPlasmaLaneA = pWorkSpace->mPlasmaLaneA;
    std::uint8_t *aPlasmaLaneB = pWorkSpace->mPlasmaLaneB;
    std::uint8_t *aPlasmaLaneC = pWorkSpace->mPlasmaLaneC;
    std::uint8_t *aPlasmaLaneD = pWorkSpace->mPlasmaLaneD;
    std::uint8_t *aShadowLaneA = pWorkSpace->mShadowLaneA;
    std::uint8_t *aShadowLaneB = pWorkSpace->mShadowLaneB;
    std::uint8_t *aShadowLaneC = pWorkSpace->mShadowLaneC;
    std::uint8_t *aShadowLaneD = pWorkSpace->mShadowLaneD;
    std::uint8_t *aAetherLaneA = pWorkSpace->mAetherLaneA;
    std::uint8_t *aAetherLaneB = pWorkSpace->mAetherLaneB;
    std::uint8_t *aAetherLaneC = pWorkSpace->mAetherLaneC;
    std::uint8_t *aAetherLaneD = pWorkSpace->mAetherLaneD;
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

    TwistExpander_Aldebaran_Arx::KDF_C_A_B(PARAMS_KDF);

    TwistExpander_Aldebaran_Arx::KDF_C_B_B(PARAMS_KDF);

    TwistDiffuse::DiffuseWithDomainWords(
        aAetherLaneA, aAetherLaneB, aAetherLaneC, aAetherLaneD,  // input lanes
        aShadowLaneA, aShadowLaneB, aShadowLaneC, aShadowLaneD, // output lanes
        aPlasmaLaneA, aPlasmaLaneB, aPlasmaLaneC, aPlasmaLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    TwistExpander_Aldebaran_Arx::KDF_C_C_B(PARAMS_KDF);

}

void TwistExpander_Aldebaran::KDF_A_C(TwistWorkSpace *pWorkSpace,
               std::uint64_t pNonce,
               TwistDomainConstants *pConstants,
               TwistDomainSaltSet *pDomainSaltSet,
               MUTABLE_PARAMS) {
    std::uint8_t *aSpiritLaneA = pWorkSpace->mSpiritLaneA;
    std::uint8_t *aSpiritLaneB = pWorkSpace->mSpiritLaneB;
    std::uint8_t *aSpiritLaneC = pWorkSpace->mSpiritLaneC;
    std::uint8_t *aSpiritLaneD = pWorkSpace->mSpiritLaneD;
    std::uint8_t *aWaterLaneA = pWorkSpace->mWaterLaneA;
    std::uint8_t *aWaterLaneB = pWorkSpace->mWaterLaneB;
    std::uint8_t *aWaterLaneC = pWorkSpace->mWaterLaneC;
    std::uint8_t *aWaterLaneD = pWorkSpace->mWaterLaneD;
    std::uint8_t *aEarthLaneA = pWorkSpace->mEarthLaneA;
    std::uint8_t *aEarthLaneB = pWorkSpace->mEarthLaneB;
    std::uint8_t *aEarthLaneC = pWorkSpace->mEarthLaneC;
    std::uint8_t *aEarthLaneD = pWorkSpace->mEarthLaneD;
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

    TwistExpander_Aldebaran_Arx::KDF_A_A_C(PARAMS_KDF);

    TwistExpander_Aldebaran_Arx::KDF_A_B_C(PARAMS_KDF);

    TwistDiffuse::DiffuseWithDomainWords(
        aSpiritLaneA, aSpiritLaneB, aSpiritLaneC, aSpiritLaneD,  // input lanes
        aEarthLaneA, aEarthLaneB, aEarthLaneC, aEarthLaneD, // output lanes
        aWaterLaneA, aWaterLaneB, aWaterLaneC, aWaterLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    TwistExpander_Aldebaran_Arx::KDF_A_C_C(PARAMS_KDF);

}

void TwistExpander_Aldebaran::KDF_B_C(TwistWorkSpace *pWorkSpace,
               std::uint64_t pNonce,
               TwistDomainConstants *pConstants,
               TwistDomainSaltSet *pDomainSaltSet,
               MUTABLE_PARAMS) {
    std::uint8_t *aWindLaneA = pWorkSpace->mWindLaneA;
    std::uint8_t *aWindLaneB = pWorkSpace->mWindLaneB;
    std::uint8_t *aWindLaneC = pWorkSpace->mWindLaneC;
    std::uint8_t *aWindLaneD = pWorkSpace->mWindLaneD;
    std::uint8_t *aLightningLaneA = pWorkSpace->mLightningLaneA;
    std::uint8_t *aLightningLaneB = pWorkSpace->mLightningLaneB;
    std::uint8_t *aLightningLaneC = pWorkSpace->mLightningLaneC;
    std::uint8_t *aLightningLaneD = pWorkSpace->mLightningLaneD;
    std::uint8_t *aCrystalLaneA = pWorkSpace->mCrystalLaneA;
    std::uint8_t *aCrystalLaneB = pWorkSpace->mCrystalLaneB;
    std::uint8_t *aCrystalLaneC = pWorkSpace->mCrystalLaneC;
    std::uint8_t *aCrystalLaneD = pWorkSpace->mCrystalLaneD;
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

    TwistExpander_Aldebaran_Arx::KDF_B_A_C(PARAMS_KDF);

    TwistExpander_Aldebaran_Arx::KDF_B_B_C(PARAMS_KDF);

    TwistDiffuse::DiffuseWithDomainWords(
        aLightningLaneA, aLightningLaneB, aLightningLaneC, aLightningLaneD,  // input lanes
        aWindLaneA, aWindLaneB, aWindLaneC, aWindLaneD, // output lanes
        aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, aCrystalLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    TwistExpander_Aldebaran_Arx::KDF_B_C_C(PARAMS_KDF);

}

void TwistExpander_Aldebaran::KDF_C_C(TwistWorkSpace *pWorkSpace,
               std::uint64_t pNonce,
               TwistDomainConstants *pConstants,
               TwistDomainSaltSet *pDomainSaltSet,
               MUTABLE_PARAMS) {
    std::uint8_t *aPlasmaLaneA = pWorkSpace->mPlasmaLaneA;
    std::uint8_t *aPlasmaLaneB = pWorkSpace->mPlasmaLaneB;
    std::uint8_t *aPlasmaLaneC = pWorkSpace->mPlasmaLaneC;
    std::uint8_t *aPlasmaLaneD = pWorkSpace->mPlasmaLaneD;
    std::uint8_t *aShadowLaneA = pWorkSpace->mShadowLaneA;
    std::uint8_t *aShadowLaneB = pWorkSpace->mShadowLaneB;
    std::uint8_t *aShadowLaneC = pWorkSpace->mShadowLaneC;
    std::uint8_t *aShadowLaneD = pWorkSpace->mShadowLaneD;
    std::uint8_t *aAetherLaneA = pWorkSpace->mAetherLaneA;
    std::uint8_t *aAetherLaneB = pWorkSpace->mAetherLaneB;
    std::uint8_t *aAetherLaneC = pWorkSpace->mAetherLaneC;
    std::uint8_t *aAetherLaneD = pWorkSpace->mAetherLaneD;
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

    TwistExpander_Aldebaran_Arx::KDF_C_A_C(PARAMS_KDF);

    TwistExpander_Aldebaran_Arx::KDF_C_B_C(PARAMS_KDF);

    TwistDiffuse::DiffuseWithDomainWords(
        aAetherLaneA, aAetherLaneB, aAetherLaneC, aAetherLaneD,  // input lanes
        aShadowLaneA, aShadowLaneB, aShadowLaneC, aShadowLaneD, // output lanes
        aPlasmaLaneA, aPlasmaLaneB, aPlasmaLaneC, aPlasmaLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    TwistExpander_Aldebaran_Arx::KDF_C_C_C(PARAMS_KDF);

}

void TwistExpander_Aldebaran::KDF_A_D(TwistWorkSpace *pWorkSpace,
               std::uint64_t pNonce,
               TwistDomainConstants *pConstants,
               TwistDomainSaltSet *pDomainSaltSet,
               MUTABLE_PARAMS) {
    std::uint8_t *aSpiritLaneA = pWorkSpace->mSpiritLaneA;
    std::uint8_t *aSpiritLaneB = pWorkSpace->mSpiritLaneB;
    std::uint8_t *aSpiritLaneC = pWorkSpace->mSpiritLaneC;
    std::uint8_t *aSpiritLaneD = pWorkSpace->mSpiritLaneD;
    std::uint8_t *aWaterLaneA = pWorkSpace->mWaterLaneA;
    std::uint8_t *aWaterLaneB = pWorkSpace->mWaterLaneB;
    std::uint8_t *aWaterLaneC = pWorkSpace->mWaterLaneC;
    std::uint8_t *aWaterLaneD = pWorkSpace->mWaterLaneD;
    std::uint8_t *aEarthLaneA = pWorkSpace->mEarthLaneA;
    std::uint8_t *aEarthLaneB = pWorkSpace->mEarthLaneB;
    std::uint8_t *aEarthLaneC = pWorkSpace->mEarthLaneC;
    std::uint8_t *aEarthLaneD = pWorkSpace->mEarthLaneD;
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

    TwistExpander_Aldebaran_Arx::KDF_A_A_D(PARAMS_KDF);

    TwistExpander_Aldebaran_Arx::KDF_A_B_D(PARAMS_KDF);

    TwistDiffuse::DiffuseWithDomainWords(
        aSpiritLaneA, aSpiritLaneB, aSpiritLaneC, aSpiritLaneD,  // input lanes
        aEarthLaneA, aEarthLaneB, aEarthLaneC, aEarthLaneD, // output lanes
        aWaterLaneA, aWaterLaneB, aWaterLaneC, aWaterLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    TwistExpander_Aldebaran_Arx::KDF_A_C_D(PARAMS_KDF);

}

void TwistExpander_Aldebaran::KDF_B_D(TwistWorkSpace *pWorkSpace,
               std::uint64_t pNonce,
               TwistDomainConstants *pConstants,
               TwistDomainSaltSet *pDomainSaltSet,
               MUTABLE_PARAMS) {
    std::uint8_t *aWindLaneA = pWorkSpace->mWindLaneA;
    std::uint8_t *aWindLaneB = pWorkSpace->mWindLaneB;
    std::uint8_t *aWindLaneC = pWorkSpace->mWindLaneC;
    std::uint8_t *aWindLaneD = pWorkSpace->mWindLaneD;
    std::uint8_t *aLightningLaneA = pWorkSpace->mLightningLaneA;
    std::uint8_t *aLightningLaneB = pWorkSpace->mLightningLaneB;
    std::uint8_t *aLightningLaneC = pWorkSpace->mLightningLaneC;
    std::uint8_t *aLightningLaneD = pWorkSpace->mLightningLaneD;
    std::uint8_t *aCrystalLaneA = pWorkSpace->mCrystalLaneA;
    std::uint8_t *aCrystalLaneB = pWorkSpace->mCrystalLaneB;
    std::uint8_t *aCrystalLaneC = pWorkSpace->mCrystalLaneC;
    std::uint8_t *aCrystalLaneD = pWorkSpace->mCrystalLaneD;
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

    TwistExpander_Aldebaran_Arx::KDF_B_A_D(PARAMS_KDF);

    TwistExpander_Aldebaran_Arx::KDF_B_B_D(PARAMS_KDF);

    TwistDiffuse::DiffuseWithDomainWords(
        aLightningLaneA, aLightningLaneB, aLightningLaneC, aLightningLaneD,  // input lanes
        aWindLaneA, aWindLaneB, aWindLaneC, aWindLaneD, // output lanes
        aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, aCrystalLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    TwistExpander_Aldebaran_Arx::KDF_B_C_D(PARAMS_KDF);

}

void TwistExpander_Aldebaran::KDF_C_D(TwistWorkSpace *pWorkSpace,
               std::uint64_t pNonce,
               TwistDomainConstants *pConstants,
               TwistDomainSaltSet *pDomainSaltSet,
               MUTABLE_PARAMS) {
    std::uint8_t *aPlasmaLaneA = pWorkSpace->mPlasmaLaneA;
    std::uint8_t *aPlasmaLaneB = pWorkSpace->mPlasmaLaneB;
    std::uint8_t *aPlasmaLaneC = pWorkSpace->mPlasmaLaneC;
    std::uint8_t *aPlasmaLaneD = pWorkSpace->mPlasmaLaneD;
    std::uint8_t *aShadowLaneA = pWorkSpace->mShadowLaneA;
    std::uint8_t *aShadowLaneB = pWorkSpace->mShadowLaneB;
    std::uint8_t *aShadowLaneC = pWorkSpace->mShadowLaneC;
    std::uint8_t *aShadowLaneD = pWorkSpace->mShadowLaneD;
    std::uint8_t *aAetherLaneA = pWorkSpace->mAetherLaneA;
    std::uint8_t *aAetherLaneB = pWorkSpace->mAetherLaneB;
    std::uint8_t *aAetherLaneC = pWorkSpace->mAetherLaneC;
    std::uint8_t *aAetherLaneD = pWorkSpace->mAetherLaneD;
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

    TwistExpander_Aldebaran_Arx::KDF_C_A_D(PARAMS_KDF);

    TwistExpander_Aldebaran_Arx::KDF_C_B_D(PARAMS_KDF);

    TwistDiffuse::DiffuseWithDomainWords(
        aAetherLaneA, aAetherLaneB, aAetherLaneC, aAetherLaneD,  // input lanes
        aShadowLaneA, aShadowLaneB, aShadowLaneC, aShadowLaneD, // output lanes
        aPlasmaLaneA, aPlasmaLaneB, aPlasmaLaneC, aPlasmaLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    TwistExpander_Aldebaran_Arx::KDF_C_C_D(PARAMS_KDF);

}

void TwistExpander_Aldebaran::KDF_A_E(TwistWorkSpace *pWorkSpace,
               std::uint64_t pNonce,
               TwistDomainConstants *pConstants,
               TwistDomainSaltSet *pDomainSaltSet,
               MUTABLE_PARAMS) {
    std::uint8_t *aSpiritLaneA = pWorkSpace->mSpiritLaneA;
    std::uint8_t *aSpiritLaneB = pWorkSpace->mSpiritLaneB;
    std::uint8_t *aSpiritLaneC = pWorkSpace->mSpiritLaneC;
    std::uint8_t *aSpiritLaneD = pWorkSpace->mSpiritLaneD;
    std::uint8_t *aWaterLaneA = pWorkSpace->mWaterLaneA;
    std::uint8_t *aWaterLaneB = pWorkSpace->mWaterLaneB;
    std::uint8_t *aWaterLaneC = pWorkSpace->mWaterLaneC;
    std::uint8_t *aWaterLaneD = pWorkSpace->mWaterLaneD;
    std::uint8_t *aEarthLaneA = pWorkSpace->mEarthLaneA;
    std::uint8_t *aEarthLaneB = pWorkSpace->mEarthLaneB;
    std::uint8_t *aEarthLaneC = pWorkSpace->mEarthLaneC;
    std::uint8_t *aEarthLaneD = pWorkSpace->mEarthLaneD;
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

    TwistExpander_Aldebaran_Arx::KDF_A_A_E(PARAMS_KDF);

    TwistExpander_Aldebaran_Arx::KDF_A_B_E(PARAMS_KDF);

    TwistDiffuse::DiffuseWithDomainWords(
        aSpiritLaneA, aSpiritLaneB, aSpiritLaneC, aSpiritLaneD,  // input lanes
        aEarthLaneA, aEarthLaneB, aEarthLaneC, aEarthLaneD, // output lanes
        aWaterLaneA, aWaterLaneB, aWaterLaneC, aWaterLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    TwistExpander_Aldebaran_Arx::KDF_A_C_E(PARAMS_KDF);

}

void TwistExpander_Aldebaran::KDF_B_E(TwistWorkSpace *pWorkSpace,
               std::uint64_t pNonce,
               TwistDomainConstants *pConstants,
               TwistDomainSaltSet *pDomainSaltSet,
               MUTABLE_PARAMS) {
    std::uint8_t *aWindLaneA = pWorkSpace->mWindLaneA;
    std::uint8_t *aWindLaneB = pWorkSpace->mWindLaneB;
    std::uint8_t *aWindLaneC = pWorkSpace->mWindLaneC;
    std::uint8_t *aWindLaneD = pWorkSpace->mWindLaneD;
    std::uint8_t *aLightningLaneA = pWorkSpace->mLightningLaneA;
    std::uint8_t *aLightningLaneB = pWorkSpace->mLightningLaneB;
    std::uint8_t *aLightningLaneC = pWorkSpace->mLightningLaneC;
    std::uint8_t *aLightningLaneD = pWorkSpace->mLightningLaneD;
    std::uint8_t *aCrystalLaneA = pWorkSpace->mCrystalLaneA;
    std::uint8_t *aCrystalLaneB = pWorkSpace->mCrystalLaneB;
    std::uint8_t *aCrystalLaneC = pWorkSpace->mCrystalLaneC;
    std::uint8_t *aCrystalLaneD = pWorkSpace->mCrystalLaneD;
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

    TwistExpander_Aldebaran_Arx::KDF_B_A_E(PARAMS_KDF);

    TwistExpander_Aldebaran_Arx::KDF_B_B_E(PARAMS_KDF);

    TwistDiffuse::DiffuseWithDomainWords(
        aLightningLaneA, aLightningLaneB, aLightningLaneC, aLightningLaneD,  // input lanes
        aWindLaneA, aWindLaneB, aWindLaneC, aWindLaneD, // output lanes
        aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, aCrystalLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    TwistExpander_Aldebaran_Arx::KDF_B_C_E(PARAMS_KDF);

}

void TwistExpander_Aldebaran::KDF_C_E(TwistWorkSpace *pWorkSpace,
               std::uint64_t pNonce,
               TwistDomainConstants *pConstants,
               TwistDomainSaltSet *pDomainSaltSet,
               MUTABLE_PARAMS) {
    std::uint8_t *aPlasmaLaneA = pWorkSpace->mPlasmaLaneA;
    std::uint8_t *aPlasmaLaneB = pWorkSpace->mPlasmaLaneB;
    std::uint8_t *aPlasmaLaneC = pWorkSpace->mPlasmaLaneC;
    std::uint8_t *aPlasmaLaneD = pWorkSpace->mPlasmaLaneD;
    std::uint8_t *aShadowLaneA = pWorkSpace->mShadowLaneA;
    std::uint8_t *aShadowLaneB = pWorkSpace->mShadowLaneB;
    std::uint8_t *aShadowLaneC = pWorkSpace->mShadowLaneC;
    std::uint8_t *aShadowLaneD = pWorkSpace->mShadowLaneD;
    std::uint8_t *aAetherLaneA = pWorkSpace->mAetherLaneA;
    std::uint8_t *aAetherLaneB = pWorkSpace->mAetherLaneB;
    std::uint8_t *aAetherLaneC = pWorkSpace->mAetherLaneC;
    std::uint8_t *aAetherLaneD = pWorkSpace->mAetherLaneD;
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

    TwistExpander_Aldebaran_Arx::KDF_C_A_E(PARAMS_KDF);

    TwistExpander_Aldebaran_Arx::KDF_C_B_E(PARAMS_KDF);

    TwistDiffuse::DiffuseWithDomainWords(
        aAetherLaneA, aAetherLaneB, aAetherLaneC, aAetherLaneD,  // input lanes
        aShadowLaneA, aShadowLaneB, aShadowLaneC, aShadowLaneD, // output lanes
        aPlasmaLaneA, aPlasmaLaneB, aPlasmaLaneC, aPlasmaLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    TwistExpander_Aldebaran_Arx::KDF_C_C_E(PARAMS_KDF);

}

void TwistExpander_Aldebaran::KDF_A_F(TwistWorkSpace *pWorkSpace,
               std::uint64_t pNonce,
               TwistDomainConstants *pConstants,
               TwistDomainSaltSet *pDomainSaltSet,
               MUTABLE_PARAMS) {
    std::uint8_t *aSpiritLaneA = pWorkSpace->mSpiritLaneA;
    std::uint8_t *aSpiritLaneB = pWorkSpace->mSpiritLaneB;
    std::uint8_t *aSpiritLaneC = pWorkSpace->mSpiritLaneC;
    std::uint8_t *aSpiritLaneD = pWorkSpace->mSpiritLaneD;
    std::uint8_t *aWaterLaneA = pWorkSpace->mWaterLaneA;
    std::uint8_t *aWaterLaneB = pWorkSpace->mWaterLaneB;
    std::uint8_t *aWaterLaneC = pWorkSpace->mWaterLaneC;
    std::uint8_t *aWaterLaneD = pWorkSpace->mWaterLaneD;
    std::uint8_t *aEarthLaneA = pWorkSpace->mEarthLaneA;
    std::uint8_t *aEarthLaneB = pWorkSpace->mEarthLaneB;
    std::uint8_t *aEarthLaneC = pWorkSpace->mEarthLaneC;
    std::uint8_t *aEarthLaneD = pWorkSpace->mEarthLaneD;
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

    TwistExpander_Aldebaran_Arx::KDF_A_A_F(PARAMS_KDF);

    TwistExpander_Aldebaran_Arx::KDF_A_B_F(PARAMS_KDF);

    TwistDiffuse::DiffuseWithDomainWords(
        aSpiritLaneA, aSpiritLaneB, aSpiritLaneC, aSpiritLaneD,  // input lanes
        aEarthLaneA, aEarthLaneB, aEarthLaneC, aEarthLaneD, // output lanes
        aWaterLaneA, aWaterLaneB, aWaterLaneC, aWaterLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    TwistExpander_Aldebaran_Arx::KDF_A_C_F(PARAMS_KDF);

}

void TwistExpander_Aldebaran::KDF_B_F(TwistWorkSpace *pWorkSpace,
               std::uint64_t pNonce,
               TwistDomainConstants *pConstants,
               TwistDomainSaltSet *pDomainSaltSet,
               MUTABLE_PARAMS) {
    std::uint8_t *aWindLaneA = pWorkSpace->mWindLaneA;
    std::uint8_t *aWindLaneB = pWorkSpace->mWindLaneB;
    std::uint8_t *aWindLaneC = pWorkSpace->mWindLaneC;
    std::uint8_t *aWindLaneD = pWorkSpace->mWindLaneD;
    std::uint8_t *aLightningLaneA = pWorkSpace->mLightningLaneA;
    std::uint8_t *aLightningLaneB = pWorkSpace->mLightningLaneB;
    std::uint8_t *aLightningLaneC = pWorkSpace->mLightningLaneC;
    std::uint8_t *aLightningLaneD = pWorkSpace->mLightningLaneD;
    std::uint8_t *aCrystalLaneA = pWorkSpace->mCrystalLaneA;
    std::uint8_t *aCrystalLaneB = pWorkSpace->mCrystalLaneB;
    std::uint8_t *aCrystalLaneC = pWorkSpace->mCrystalLaneC;
    std::uint8_t *aCrystalLaneD = pWorkSpace->mCrystalLaneD;
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

    TwistExpander_Aldebaran_Arx::KDF_B_A_F(PARAMS_KDF);

    TwistExpander_Aldebaran_Arx::KDF_B_B_F(PARAMS_KDF);

    TwistDiffuse::DiffuseWithDomainWords(
        aLightningLaneA, aLightningLaneB, aLightningLaneC, aLightningLaneD,  // input lanes
        aWindLaneA, aWindLaneB, aWindLaneC, aWindLaneD, // output lanes
        aCrystalLaneA, aCrystalLaneB, aCrystalLaneC, aCrystalLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    TwistExpander_Aldebaran_Arx::KDF_B_C_F(PARAMS_KDF);

}

void TwistExpander_Aldebaran::KDF_C_F(TwistWorkSpace *pWorkSpace,
               std::uint64_t pNonce,
               TwistDomainConstants *pConstants,
               TwistDomainSaltSet *pDomainSaltSet,
               MUTABLE_PARAMS) {
    std::uint8_t *aPlasmaLaneA = pWorkSpace->mPlasmaLaneA;
    std::uint8_t *aPlasmaLaneB = pWorkSpace->mPlasmaLaneB;
    std::uint8_t *aPlasmaLaneC = pWorkSpace->mPlasmaLaneC;
    std::uint8_t *aPlasmaLaneD = pWorkSpace->mPlasmaLaneD;
    std::uint8_t *aShadowLaneA = pWorkSpace->mShadowLaneA;
    std::uint8_t *aShadowLaneB = pWorkSpace->mShadowLaneB;
    std::uint8_t *aShadowLaneC = pWorkSpace->mShadowLaneC;
    std::uint8_t *aShadowLaneD = pWorkSpace->mShadowLaneD;
    std::uint8_t *aAetherLaneA = pWorkSpace->mAetherLaneA;
    std::uint8_t *aAetherLaneB = pWorkSpace->mAetherLaneB;
    std::uint8_t *aAetherLaneC = pWorkSpace->mAetherLaneC;
    std::uint8_t *aAetherLaneD = pWorkSpace->mAetherLaneD;
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

    TwistExpander_Aldebaran_Arx::KDF_C_A_F(PARAMS_KDF);

    TwistExpander_Aldebaran_Arx::KDF_C_B_F(PARAMS_KDF);

    TwistDiffuse::DiffuseWithDomainWords(
        aAetherLaneA, aAetherLaneB, aAetherLaneC, aAetherLaneD,  // input lanes
        aShadowLaneA, aShadowLaneB, aShadowLaneC, aShadowLaneD, // output lanes
        aPlasmaLaneA, aPlasmaLaneB, aPlasmaLaneC, aPlasmaLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    TwistExpander_Aldebaran_Arx::KDF_C_C_F(PARAMS_KDF);

}

void TwistExpander_Aldebaran::Seed(TwistWorkSpace *pWorkSpace,
                                 TwistFarmSalt *pFarmSalt,
                                 std::uint64_t pNonce,
                                 std::uint8_t *pPassword,
                                 std::size_t pPasswordByteLength,
                                 std::uint8_t *pDestination) {
    if ((pWorkSpace == nullptr) || (pFarmSalt == nullptr) ||
        (pDestination == nullptr)) { return; }

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
    std::uint8_t *aSpiritLaneA = pWorkSpace->mSpiritLaneA;
    std::uint8_t *aSpiritLaneB = pWorkSpace->mSpiritLaneB;
    std::uint8_t *aSpiritLaneC = pWorkSpace->mSpiritLaneC;
    std::uint8_t *aSpiritLaneD = pWorkSpace->mSpiritLaneD;
    std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    std::uint8_t *aWaterLaneA = pWorkSpace->mWaterLaneA;
    std::uint8_t *aWaterLaneB = pWorkSpace->mWaterLaneB;
    std::uint8_t *aWaterLaneC = pWorkSpace->mWaterLaneC;
    std::uint8_t *aWaterLaneD = pWorkSpace->mWaterLaneD;
    std::uint8_t *aHeartLaneA = pWorkSpace->mHeartLaneA;
    std::uint8_t *aHeartLaneB = pWorkSpace->mHeartLaneB;
    std::uint8_t *aHeartLaneC = pWorkSpace->mHeartLaneC;
    std::uint8_t *aHeartLaneD = pWorkSpace->mHeartLaneD;
    std::uint8_t *aWindLaneA = pWorkSpace->mWindLaneA;
    std::uint8_t *aWindLaneB = pWorkSpace->mWindLaneB;
    std::uint8_t *aWindLaneC = pWorkSpace->mWindLaneC;
    std::uint8_t *aWindLaneD = pWorkSpace->mWindLaneD;
    std::uint8_t *aFuseLaneA = pWorkSpace->mFuseLaneA;
    std::uint8_t *aFuseLaneB = pWorkSpace->mFuseLaneB;
    std::uint8_t *aFuseLaneC = pWorkSpace->mFuseLaneC;
    std::uint8_t *aLightningLaneA = pWorkSpace->mLightningLaneA;
    std::uint8_t *aLightningLaneB = pWorkSpace->mLightningLaneB;
    std::uint8_t *aLightningLaneC = pWorkSpace->mLightningLaneC;
    std::uint8_t *aLightningLaneD = pWorkSpace->mLightningLaneD;
    std::uint8_t *aPlasmaLaneA = pWorkSpace->mPlasmaLaneA;
    std::uint8_t *aPlasmaLaneB = pWorkSpace->mPlasmaLaneB;
    std::uint8_t *aPlasmaLaneC = pWorkSpace->mPlasmaLaneC;
    std::uint8_t *aPlasmaLaneD = pWorkSpace->mPlasmaLaneD;
    std::uint8_t *aShadowLaneA = pWorkSpace->mShadowLaneA;
    std::uint8_t *aShadowLaneB = pWorkSpace->mShadowLaneB;
    std::uint8_t *aShadowLaneC = pWorkSpace->mShadowLaneC;
    std::uint8_t *aShadowLaneD = pWorkSpace->mShadowLaneD;
    std::uint8_t *aAetherLaneA = pWorkSpace->mAetherLaneA;
    std::uint8_t *aAetherLaneB = pWorkSpace->mAetherLaneB;
    std::uint8_t *aAetherLaneC = pWorkSpace->mAetherLaneC;
    std::uint8_t *aAetherLaneD = pWorkSpace->mAetherLaneD;
    std::uint8_t *aCelestialLaneA = pWorkSpace->mCelestialLaneA;
    std::uint8_t *aCelestialLaneB = pWorkSpace->mCelestialLaneB;
    std::uint8_t *aCelestialLaneC = pWorkSpace->mCelestialLaneC;
    std::uint8_t *aCelestialLaneD = pWorkSpace->mCelestialLaneD;
    std::uint8_t *aVaporLaneA = pWorkSpace->mVaporLaneA;
    std::uint8_t *aVaporLaneB = pWorkSpace->mVaporLaneB;
    std::uint8_t *aVaporLaneC = pWorkSpace->mVaporLaneC;
    std::uint8_t *aVaporLaneD = pWorkSpace->mVaporLaneD;
    std::uint8_t *aKineticLaneA = pWorkSpace->mKineticLaneA;
    std::uint8_t *aKineticLaneB = pWorkSpace->mKineticLaneB;
    std::uint8_t *aKineticLaneC = pWorkSpace->mKineticLaneC;
    std::uint8_t *aKineticLaneD = pWorkSpace->mKineticLaneD;
    std::uint8_t *aSonicLaneA = pWorkSpace->mSonicLaneA;
    std::uint8_t *aSonicLaneB = pWorkSpace->mSonicLaneB;
    std::uint8_t *aSonicLaneC = pWorkSpace->mSonicLaneC;
    std::uint8_t *aSonicLaneD = pWorkSpace->mSonicLaneD;
    std::uint8_t *aPlanarLaneA = pWorkSpace->mPlanarLaneA;
    std::uint8_t *aPlanarLaneB = pWorkSpace->mPlanarLaneB;
    std::uint8_t *aPlanarLaneC = pWorkSpace->mPlanarLaneC;
    std::uint8_t *aPlanarLaneD = pWorkSpace->mPlanarLaneD;
    std::uint8_t *aFrostLaneA = pWorkSpace->mFrostLaneA;
    std::uint8_t *aFrostLaneB = pWorkSpace->mFrostLaneB;
    std::uint8_t *aFrostLaneC = pWorkSpace->mFrostLaneC;
    std::uint8_t *aFrostLaneD = pWorkSpace->mFrostLaneD;
    std::uint8_t *aArcaneLaneA = pWorkSpace->mArcaneLaneA;
    std::uint8_t *aArcaneLaneB = pWorkSpace->mArcaneLaneB;
    std::uint8_t *aArcaneLaneC = pWorkSpace->mArcaneLaneC;
    std::uint8_t *aArcaneLaneD = pWorkSpace->mArcaneLaneD;
    std::uint8_t *aLunarLaneA = pWorkSpace->mLunarLaneA;
    std::uint8_t *aLunarLaneB = pWorkSpace->mLunarLaneB;
    std::uint8_t *aLunarLaneC = pWorkSpace->mLunarLaneC;
    std::uint8_t *aLunarLaneD = pWorkSpace->mLunarLaneD;
    std::uint8_t *aRunicLaneA = pWorkSpace->mRunicLaneA;
    std::uint8_t *aRunicLaneB = pWorkSpace->mRunicLaneB;
    std::uint8_t *aRunicLaneC = pWorkSpace->mRunicLaneC;
    std::uint8_t *aRunicLaneD = pWorkSpace->mRunicLaneD;
    std::uint8_t *aGloomLaneA = pWorkSpace->mGloomLaneA;
    std::uint8_t *aGloomLaneB = pWorkSpace->mGloomLaneB;
    std::uint8_t *aGloomLaneC = pWorkSpace->mGloomLaneC;
    std::uint8_t *aGloomLaneD = pWorkSpace->mGloomLaneD;
    std::uint8_t *aAbjurationLaneA = pWorkSpace->mAbjurationLaneA;
    std::uint8_t *aAbjurationLaneB = pWorkSpace->mAbjurationLaneB;
    std::uint8_t *aAbjurationLaneC = pWorkSpace->mAbjurationLaneC;
    std::uint8_t *aAbjurationLaneD = pWorkSpace->mAbjurationLaneD;
    std::uint8_t *aDivinationLaneA = pWorkSpace->mDivinationLaneA;
    std::uint8_t *aDivinationLaneB = pWorkSpace->mDivinationLaneB;
    std::uint8_t *aDivinationLaneC = pWorkSpace->mDivinationLaneC;
    std::uint8_t *aDivinationLaneD = pWorkSpace->mDivinationLaneD;
    std::uint8_t *aEvocationLaneA = pWorkSpace->mEvocationLaneA;
    std::uint8_t *aEvocationLaneB = pWorkSpace->mEvocationLaneB;
    std::uint8_t *aEvocationLaneC = pWorkSpace->mEvocationLaneC;
    std::uint8_t *aEvocationLaneD = pWorkSpace->mEvocationLaneD;
    std::uint8_t *aStasisLaneA = pWorkSpace->mStasisLaneA;
    std::uint8_t *aStasisLaneB = pWorkSpace->mStasisLaneB;
    std::uint8_t *aStasisLaneC = pWorkSpace->mStasisLaneC;
    std::uint8_t *aStasisLaneD = pWorkSpace->mStasisLaneD;
    std::uint8_t *aMysticalLaneA = pWorkSpace->mMysticalLaneA;
    std::uint8_t *aMysticalLaneB = pWorkSpace->mMysticalLaneB;
    std::uint8_t *aMysticalLaneC = pWorkSpace->mMysticalLaneC;
    std::uint8_t *aMysticalLaneD = pWorkSpace->mMysticalLaneD;
    std::uint8_t *aCovenLaneA = pWorkSpace->mCovenLaneA;
    std::uint8_t *aCovenLaneB = pWorkSpace->mCovenLaneB;
    std::uint8_t *aCovenLaneC = pWorkSpace->mCovenLaneC;
    std::uint8_t *aCovenLaneD = pWorkSpace->mCovenLaneD;
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;
    std::size_t *aIndexList256A = pWorkSpace->mIndexList256A;
    std::size_t *aIndexList256B = pWorkSpace->mIndexList256B;
    std::size_t *aIndexList256C = pWorkSpace->mIndexList256C;
    std::size_t *aIndexList256D = pWorkSpace->mIndexList256D;

    std::uint64_t aIngress = 0xD53429564C5C308CULL;
    std::uint64_t aCarry = 0xB83A7ABED8AE353EULL;
    std::uint64_t aWandererA = 0xD3ED5A01A739CA11ULL;
    std::uint64_t aWandererB = 0xE468171140335C2DULL;
    std::uint64_t aWandererC = 0xDAB1BFE6B9089C86ULL;
    std::uint64_t aWandererD = 0xA04B1B370B072E76ULL;
    std::uint64_t aWandererE = 0xD50C14B43D3C865FULL;
    std::uint64_t aWandererF = 0xC732BCE22D64B7CEULL;
    std::uint64_t aWandererG = 0xBCCE67E6B46DA5C2ULL;
    std::uint64_t aWandererH = 0xD794D29F99F4C591ULL;
    std::uint64_t aWandererI = 0xC3D1A0B500102F8AULL;
    std::uint64_t aWandererJ = 0xF534DBE3E490F538ULL;
    std::uint64_t aWandererK = 0xBF1C506DA457D0BAULL;

    ////////////////////////////////////////////////////////
    //
    // Secret material derivation, across 6 domains.
    //
    // Domain 1 of 6, key a rotate:
    //
    KDF_A_A(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateAConstants), &(mDomainBundleInbuilt.mKeyRotateASalts), ARX_STATE_VARS);

    TwistFarm::Farm(pFarmSalt,
                    aIceLaneB, aIceLaneC, aIceLaneD, aIceLaneA, // farm lanes
                    aFuseLaneA, aFuseLaneB, aFuseLaneC, // temp/fold lanes
                    &mDomainBundleEphemeralA.mKeyRotateASalts,
                    &(mDomainBundleEphemeralA.mKeyRotateAConstants));

    KDF_B_A(pWorkSpace, pNonce, &(mDomainBundleEphemeralA.mKeyRotateAConstants), &(mDomainBundleEphemeralA.mKeyRotateASalts), ARX_STATE_VARS);

    TwistFarm::Farm(pFarmSalt,
                    aVaporLaneB, aVaporLaneC, aVaporLaneD, aVaporLaneA, // farm lanes
                    aFuseLaneA, aFuseLaneB, aFuseLaneC, // temp/fold lanes
                    &mDomainBundleEphemeralB.mKeyRotateASalts,
                    &(mDomainBundleEphemeralB.mKeyRotateAConstants));

    KDF_C_A(pWorkSpace, pNonce, &(mDomainBundleEphemeralB.mKeyRotateAConstants), &(mDomainBundleEphemeralB.mKeyRotateASalts), ARX_STATE_VARS);

    TwistFarm::Farm(pFarmSalt,
                    aCelestialLaneB, aCelestialLaneC, aCelestialLaneD, aCelestialLaneA, // farm lanes
                    aFuseLaneA, aFuseLaneB, aFuseLaneC, // temp/fold lanes
                    &pWorkSpace->mDomainBundle.mKeyRotateASalts,
                    &(pWorkSpace->mDomainBundle.mKeyRotateAConstants));
    //
    // Domain 2 of 6, key b rotate:
    //
    KDF_A_B(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeyRotateBConstants), &(mDomainBundleInbuilt.mKeyRotateBSalts), ARX_STATE_VARS);

    TwistFarm::Farm(pFarmSalt,
                    aIceLaneB, aIceLaneC, aIceLaneD, aIceLaneA, // farm lanes
                    aFuseLaneA, aFuseLaneB, aFuseLaneC, // temp/fold lanes
                    &mDomainBundleEphemeralA.mKeyRotateBSalts,
                    &(mDomainBundleEphemeralA.mKeyRotateBConstants));

    KDF_B_B(pWorkSpace, pNonce, &(mDomainBundleEphemeralA.mKeyRotateBConstants), &(mDomainBundleEphemeralA.mKeyRotateBSalts), ARX_STATE_VARS);

    TwistFarm::Farm(pFarmSalt,
                    aVaporLaneB, aVaporLaneC, aVaporLaneD, aVaporLaneA, // farm lanes
                    aFuseLaneA, aFuseLaneB, aFuseLaneC, // temp/fold lanes
                    &mDomainBundleEphemeralB.mKeyRotateBSalts,
                    &(mDomainBundleEphemeralB.mKeyRotateBConstants));

    KDF_C_B(pWorkSpace, pNonce, &(mDomainBundleEphemeralB.mKeyRotateBConstants), &(mDomainBundleEphemeralB.mKeyRotateBSalts), ARX_STATE_VARS);

    TwistFarm::Farm(pFarmSalt,
                    aCelestialLaneB, aCelestialLaneC, aCelestialLaneD, aCelestialLaneA, // farm lanes
                    aFuseLaneA, aFuseLaneB, aFuseLaneC, // temp/fold lanes
                    &pWorkSpace->mDomainBundle.mKeyRotateBSalts,
                    &(pWorkSpace->mDomainBundle.mKeyRotateBConstants));
    //
    // Domain 3 of 6, key a spawn:
    //
    KDF_A_C(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnAConstants), &(mDomainBundleInbuilt.mKeySpawnASalts), ARX_STATE_VARS);

    TwistFarm::Farm(pFarmSalt,
                    aIceLaneB, aIceLaneC, aIceLaneD, aIceLaneA, // farm lanes
                    aFuseLaneA, aFuseLaneB, aFuseLaneC, // temp/fold lanes
                    &mDomainBundleEphemeralA.mKeySpawnASalts,
                    &(mDomainBundleEphemeralA.mKeySpawnAConstants));

    KDF_B_C(pWorkSpace, pNonce, &(mDomainBundleEphemeralA.mKeySpawnAConstants), &(mDomainBundleEphemeralA.mKeySpawnASalts), ARX_STATE_VARS);

    TwistFarm::Farm(pFarmSalt,
                    aVaporLaneB, aVaporLaneC, aVaporLaneD, aVaporLaneA, // farm lanes
                    aFuseLaneA, aFuseLaneB, aFuseLaneC, // temp/fold lanes
                    &mDomainBundleEphemeralB.mKeySpawnASalts,
                    &(mDomainBundleEphemeralB.mKeySpawnAConstants));

    KDF_C_C(pWorkSpace, pNonce, &(mDomainBundleEphemeralB.mKeySpawnAConstants), &(mDomainBundleEphemeralB.mKeySpawnASalts), ARX_STATE_VARS);

    TwistFarm::Farm(pFarmSalt,
                    aCelestialLaneB, aCelestialLaneC, aCelestialLaneD, aCelestialLaneA, // farm lanes
                    aFuseLaneA, aFuseLaneB, aFuseLaneC, // temp/fold lanes
                    &pWorkSpace->mDomainBundle.mKeySpawnASalts,
                    &(pWorkSpace->mDomainBundle.mKeySpawnAConstants));
    //
    // Domain 4 of 6, key b spawn:
    //
    KDF_A_D(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mKeySpawnBConstants), &(mDomainBundleInbuilt.mKeySpawnBSalts), ARX_STATE_VARS);

    TwistFarm::Farm(pFarmSalt,
                    aIceLaneB, aIceLaneC, aIceLaneD, aIceLaneA, // farm lanes
                    aFuseLaneA, aFuseLaneB, aFuseLaneC, // temp/fold lanes
                    &mDomainBundleEphemeralA.mKeySpawnBSalts,
                    &(mDomainBundleEphemeralA.mKeySpawnBConstants));

    KDF_B_D(pWorkSpace, pNonce, &(mDomainBundleEphemeralA.mKeySpawnBConstants), &(mDomainBundleEphemeralA.mKeySpawnBSalts), ARX_STATE_VARS);

    TwistFarm::Farm(pFarmSalt,
                    aVaporLaneB, aVaporLaneC, aVaporLaneD, aVaporLaneA, // farm lanes
                    aFuseLaneA, aFuseLaneB, aFuseLaneC, // temp/fold lanes
                    &mDomainBundleEphemeralB.mKeySpawnBSalts,
                    &(mDomainBundleEphemeralB.mKeySpawnBConstants));

    KDF_C_D(pWorkSpace, pNonce, &(mDomainBundleEphemeralB.mKeySpawnBConstants), &(mDomainBundleEphemeralB.mKeySpawnBSalts), ARX_STATE_VARS);

    TwistFarm::Farm(pFarmSalt,
                    aCelestialLaneB, aCelestialLaneC, aCelestialLaneD, aCelestialLaneA, // farm lanes
                    aFuseLaneA, aFuseLaneB, aFuseLaneC, // temp/fold lanes
                    &pWorkSpace->mDomainBundle.mKeySpawnBSalts,
                    &(pWorkSpace->mDomainBundle.mKeySpawnBConstants));
    //
    // Domain 5 of 6, twist:
    //
    KDF_A_E(pWorkSpace, pNonce, &(mDomainBundleInbuilt.mTwistConstants), &(mDomainBundleInbuilt.mTwistSalts), ARX_STATE_VARS);

    TwistFarm::Farm(pFarmSalt,
                    aIceLaneB, aIceLaneC, aIceLaneD, aIceLaneA, // farm lanes
                    aFuseLaneA, aFuseLaneB, aFuseLaneC, // temp/fold lanes
                    &mDomainBundleEphemeralA.mTwistSalts,
                    &(mDomainBundleEphemeralA.mTwistConstants));

    KDF_B_E(pWorkSpace, pNonce, &(mDomainBundleEphemeralA.mTwistConstants), &(mDomainBundleEphemeralA.mTwistSalts), ARX_STATE_VARS);

    TwistFarm::Farm(pFarmSalt,
                    aVaporLaneB, aVaporLaneC, aVaporLaneD, aVaporLaneA, // farm lanes
                    aFuseLaneA, aFuseLaneB, aFuseLaneC, // temp/fold lanes
                    &mDomainBundleEphemeralB.mTwistSalts,
                    &(mDomainBundleEphemeralB.mTwistConstants));

    KDF_C_E(pWorkSpace, pNonce, &(mDomainBundleEphemeralB.mTwistConstants), &(mDomainBundleEphemeralB.mTwistSalts), ARX_STATE_VARS);

    TwistFarm::Farm(pFarmSalt,
                    aCelestialLaneB, aCelestialLaneC, aCelestialLaneD, aCelestialLaneA, // farm lanes
                    aFuseLaneA, aFuseLaneB, aFuseLaneC, // temp/fold lanes
                    &pWorkSpace->mDomainBundle.mTwistSalts,
                    &(pWorkSpace->mDomainBundle.mTwistConstants));
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
        aSpiritLaneA, aSpiritLaneB, aSpiritLaneC, aSpiritLaneD,  // input lanes
        aStasisLaneA, aStasisLaneB, aStasisLaneC, aStasisLaneD, // output lanes
        aWaterLaneA, aWaterLaneB, aWaterLaneC, aWaterLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    TwistExpander_Aldebaran_Arx::SEED_C(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::SEED_D(PARAMS_SEED);

    TwistDiffuse::DiffuseWithDomainWords(
        aWindLaneA, aWindLaneB, aWindLaneC, aWindLaneD,  // input lanes
        aVaporLaneA, aVaporLaneB, aVaporLaneC, aVaporLaneD, // output lanes
        aLightningLaneA, aLightningLaneB, aLightningLaneC, aLightningLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    TwistExpander_Aldebaran_Arx::SEED_E(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::SEED_F(PARAMS_SEED);

    TwistDiffuse::DiffuseWithDomainWords(
        aAetherLaneA, aAetherLaneB, aAetherLaneC, aAetherLaneD,  // input lanes
        aShadowLaneA, aShadowLaneB, aShadowLaneC, aShadowLaneD, // output lanes
        aPlasmaLaneA, aPlasmaLaneB, aPlasmaLaneC, aPlasmaLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    TwistExpander_Aldebaran_Arx::SEED_G(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::SEED_H(PARAMS_SEED);

    TwistDiffuse::DiffuseWithDomainWords(
        aKineticLaneA, aKineticLaneB, aKineticLaneC, aKineticLaneD,  // input lanes
        aSonicLaneA, aSonicLaneB, aSonicLaneC, aSonicLaneD, // output lanes
        aMysticalLaneA, aMysticalLaneB, aMysticalLaneC, aMysticalLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    TwistExpander_Aldebaran_Arx::SEED_I(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::SEED_J(PARAMS_SEED);

    TwistDiffuse::DiffuseWithDomainWords(
        aFrostLaneA, aFrostLaneB, aFrostLaneC, aFrostLaneD,  // input lanes
        aArcaneLaneA, aArcaneLaneB, aArcaneLaneC, aArcaneLaneD, // output lanes
        aPlanarLaneA, aPlanarLaneB, aPlanarLaneC, aPlanarLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    TwistExpander_Aldebaran_Arx::SEED_K(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::SEED_L(PARAMS_SEED);

    TwistDiffuse::DiffuseWithDomainWords(
        aRunicLaneA, aRunicLaneB, aRunicLaneC, aRunicLaneD,  // input lanes
        aGloomLaneA, aGloomLaneB, aGloomLaneC, aGloomLaneD, // output lanes
        aLunarLaneA, aLunarLaneB, aLunarLaneC, aLunarLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    TwistExpander_Aldebaran_Arx::SEED_M(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::SEED_N(PARAMS_SEED);

    TwistDiffuse::DiffuseWithDomainWords(
        aDivinationLaneA, aDivinationLaneB, aDivinationLaneC, aDivinationLaneD,  // input lanes
        aEvocationLaneA, aEvocationLaneB, aEvocationLaneC, aEvocationLaneD, // output lanes
        aAbjurationLaneA, aAbjurationLaneB, aAbjurationLaneC, aAbjurationLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    TwistExpander_Aldebaran_Arx::SEED_O(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::SEED_P(PARAMS_SEED);

    TwistDiffuse::DiffuseWithDomainWords(
        aCovenLaneA, aCovenLaneB, aCovenLaneC, aCovenLaneD,  // input lanes
        aHeartLaneA, aHeartLaneB, aHeartLaneC, aHeartLaneD, // output lanes
        aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    TwistExpander_Aldebaran_Arx::SEED_Q(PARAMS_SEED);
    //
    ////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////
    //
    // Independent key-row flows
    //
    // Key flow — A / A

    TwistExpander_Aldebaran_Arx::KEY_A_A_A(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::KEY_A_A_B(PARAMS_SEED);

    KeyDiffuse_A_A_A(pWorkSpace);

    TwistExpander_Aldebaran_Arx::KEY_A_A_C(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::KEY_A_A_D(PARAMS_SEED);

    KeyDiffuse_B_A_A(pWorkSpace);

    TwistExpander_Aldebaran_Arx::KEY_A_A_E(PARAMS_SEED);

    TwistSquash::SquashKeyA(ALDEBARAN_KEY_A_A_IceLaneA, ALDEBARAN_KEY_A_A_IceLaneB, ALDEBARAN_KEY_A_A_IceLaneC, ALDEBARAN_KEY_A_A_IceLaneD, &(pWorkSpace->mKeyBoxA[0U][0]));

    // Key flow — A / B

    TwistExpander_Aldebaran_Arx::KEY_A_B_A(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::KEY_A_B_B(PARAMS_SEED);

    KeyDiffuse_A_A_B(pWorkSpace);

    TwistExpander_Aldebaran_Arx::KEY_A_B_C(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::KEY_A_B_D(PARAMS_SEED);

    KeyDiffuse_B_A_B(pWorkSpace);

    TwistExpander_Aldebaran_Arx::KEY_A_B_E(PARAMS_SEED);

    TwistSquash::SquashKeyA(ALDEBARAN_KEY_A_B_IceLaneA, ALDEBARAN_KEY_A_B_IceLaneB, ALDEBARAN_KEY_A_B_IceLaneC, ALDEBARAN_KEY_A_B_IceLaneD, &(pWorkSpace->mKeyBoxA[1U][0]));

    // Key flow — A / C

    TwistExpander_Aldebaran_Arx::KEY_A_C_A(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::KEY_A_C_B(PARAMS_SEED);

    KeyDiffuse_A_A_C(pWorkSpace);

    TwistExpander_Aldebaran_Arx::KEY_A_C_C(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::KEY_A_C_D(PARAMS_SEED);

    KeyDiffuse_B_A_C(pWorkSpace);

    TwistExpander_Aldebaran_Arx::KEY_A_C_E(PARAMS_SEED);

    TwistSquash::SquashKeyA(ALDEBARAN_KEY_A_C_IceLaneA, ALDEBARAN_KEY_A_C_IceLaneB, ALDEBARAN_KEY_A_C_IceLaneC, ALDEBARAN_KEY_A_C_IceLaneD, &(pWorkSpace->mKeyBoxA[2U][0]));

    // Key flow — A / D

    TwistExpander_Aldebaran_Arx::KEY_A_D_A(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::KEY_A_D_B(PARAMS_SEED);

    KeyDiffuse_A_A_D(pWorkSpace);

    TwistExpander_Aldebaran_Arx::KEY_A_D_C(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::KEY_A_D_D(PARAMS_SEED);

    KeyDiffuse_B_A_D(pWorkSpace);

    TwistExpander_Aldebaran_Arx::KEY_A_D_E(PARAMS_SEED);

    TwistSquash::SquashKeyA(ALDEBARAN_KEY_A_D_IceLaneA, ALDEBARAN_KEY_A_D_IceLaneB, ALDEBARAN_KEY_A_D_IceLaneC, ALDEBARAN_KEY_A_D_IceLaneD, &(pWorkSpace->mKeyBoxA[3U][0]));

    // Key flow — A / E

    TwistExpander_Aldebaran_Arx::KEY_A_E_A(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::KEY_A_E_B(PARAMS_SEED);

    KeyDiffuse_A_A_E(pWorkSpace);

    TwistExpander_Aldebaran_Arx::KEY_A_E_C(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::KEY_A_E_D(PARAMS_SEED);

    KeyDiffuse_B_A_E(pWorkSpace);

    TwistExpander_Aldebaran_Arx::KEY_A_E_E(PARAMS_SEED);

    TwistSquash::SquashKeyA(ALDEBARAN_KEY_A_E_IceLaneA, ALDEBARAN_KEY_A_E_IceLaneB, ALDEBARAN_KEY_A_E_IceLaneC, ALDEBARAN_KEY_A_E_IceLaneD, &(pWorkSpace->mKeyBoxA[4U][0]));

    // Key flow — A / F

    TwistExpander_Aldebaran_Arx::KEY_A_F_A(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::KEY_A_F_B(PARAMS_SEED);

    KeyDiffuse_A_A_F(pWorkSpace);

    TwistExpander_Aldebaran_Arx::KEY_A_F_C(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::KEY_A_F_D(PARAMS_SEED);

    KeyDiffuse_B_A_F(pWorkSpace);

    TwistExpander_Aldebaran_Arx::KEY_A_F_E(PARAMS_SEED);

    TwistSquash::SquashKeyA(ALDEBARAN_KEY_A_F_IceLaneA, ALDEBARAN_KEY_A_F_IceLaneB, ALDEBARAN_KEY_A_F_IceLaneC, ALDEBARAN_KEY_A_F_IceLaneD, &(pWorkSpace->mKeyBoxA[5U][0]));

    // Key flow — A / G

    TwistExpander_Aldebaran_Arx::KEY_A_G_A(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::KEY_A_G_B(PARAMS_SEED);

    KeyDiffuse_A_A_G(pWorkSpace);

    TwistExpander_Aldebaran_Arx::KEY_A_G_C(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::KEY_A_G_D(PARAMS_SEED);

    KeyDiffuse_B_A_G(pWorkSpace);

    TwistExpander_Aldebaran_Arx::KEY_A_G_E(PARAMS_SEED);

    TwistSquash::SquashKeyA(ALDEBARAN_KEY_A_G_IceLaneA, ALDEBARAN_KEY_A_G_IceLaneB, ALDEBARAN_KEY_A_G_IceLaneC, ALDEBARAN_KEY_A_G_IceLaneD, &(pWorkSpace->mKeyBoxA[6U][0]));

    // Key flow — A / H

    TwistExpander_Aldebaran_Arx::KEY_A_H_A(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::KEY_A_H_B(PARAMS_SEED);

    KeyDiffuse_A_A_H(pWorkSpace);

    TwistExpander_Aldebaran_Arx::KEY_A_H_C(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::KEY_A_H_D(PARAMS_SEED);

    KeyDiffuse_B_A_H(pWorkSpace);

    TwistExpander_Aldebaran_Arx::KEY_A_H_E(PARAMS_SEED);

    TwistSquash::SquashKeyA(ALDEBARAN_KEY_A_H_IceLaneA, ALDEBARAN_KEY_A_H_IceLaneB, ALDEBARAN_KEY_A_H_IceLaneC, ALDEBARAN_KEY_A_H_IceLaneD, &(pWorkSpace->mKeyBoxA[7U][0]));

    // Key flow — B / A

    TwistExpander_Aldebaran_Arx::KEY_B_A_A(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::KEY_B_A_B(PARAMS_SEED);

    KeyDiffuse_A_B_A(pWorkSpace);

    TwistExpander_Aldebaran_Arx::KEY_B_A_C(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::KEY_B_A_D(PARAMS_SEED);

    KeyDiffuse_B_B_A(pWorkSpace);

    TwistExpander_Aldebaran_Arx::KEY_B_A_E(PARAMS_SEED);

    TwistSquash::SquashKeyA(ALDEBARAN_KEY_B_A_IceLaneA, ALDEBARAN_KEY_B_A_IceLaneB, ALDEBARAN_KEY_B_A_IceLaneC, ALDEBARAN_KEY_B_A_IceLaneD, &(pWorkSpace->mKeyBoxB[0U][0]));

    // Key flow — B / B

    TwistExpander_Aldebaran_Arx::KEY_B_B_A(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::KEY_B_B_B(PARAMS_SEED);

    KeyDiffuse_A_B_B(pWorkSpace);

    TwistExpander_Aldebaran_Arx::KEY_B_B_C(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::KEY_B_B_D(PARAMS_SEED);

    KeyDiffuse_B_B_B(pWorkSpace);

    TwistExpander_Aldebaran_Arx::KEY_B_B_E(PARAMS_SEED);

    TwistSquash::SquashKeyA(ALDEBARAN_KEY_B_B_IceLaneA, ALDEBARAN_KEY_B_B_IceLaneB, ALDEBARAN_KEY_B_B_IceLaneC, ALDEBARAN_KEY_B_B_IceLaneD, &(pWorkSpace->mKeyBoxB[1U][0]));

    // Key flow — B / C

    TwistExpander_Aldebaran_Arx::KEY_B_C_A(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::KEY_B_C_B(PARAMS_SEED);

    KeyDiffuse_A_B_C(pWorkSpace);

    TwistExpander_Aldebaran_Arx::KEY_B_C_C(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::KEY_B_C_D(PARAMS_SEED);

    KeyDiffuse_B_B_C(pWorkSpace);

    TwistExpander_Aldebaran_Arx::KEY_B_C_E(PARAMS_SEED);

    TwistSquash::SquashKeyA(ALDEBARAN_KEY_B_C_IceLaneA, ALDEBARAN_KEY_B_C_IceLaneB, ALDEBARAN_KEY_B_C_IceLaneC, ALDEBARAN_KEY_B_C_IceLaneD, &(pWorkSpace->mKeyBoxB[2U][0]));

    // Key flow — B / D

    TwistExpander_Aldebaran_Arx::KEY_B_D_A(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::KEY_B_D_B(PARAMS_SEED);

    KeyDiffuse_A_B_D(pWorkSpace);

    TwistExpander_Aldebaran_Arx::KEY_B_D_C(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::KEY_B_D_D(PARAMS_SEED);

    KeyDiffuse_B_B_D(pWorkSpace);

    TwistExpander_Aldebaran_Arx::KEY_B_D_E(PARAMS_SEED);

    TwistSquash::SquashKeyA(ALDEBARAN_KEY_B_D_IceLaneA, ALDEBARAN_KEY_B_D_IceLaneB, ALDEBARAN_KEY_B_D_IceLaneC, ALDEBARAN_KEY_B_D_IceLaneD, &(pWorkSpace->mKeyBoxB[3U][0]));

    // Key flow — B / E

    TwistExpander_Aldebaran_Arx::KEY_B_E_A(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::KEY_B_E_B(PARAMS_SEED);

    KeyDiffuse_A_B_E(pWorkSpace);

    TwistExpander_Aldebaran_Arx::KEY_B_E_C(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::KEY_B_E_D(PARAMS_SEED);

    KeyDiffuse_B_B_E(pWorkSpace);

    TwistExpander_Aldebaran_Arx::KEY_B_E_E(PARAMS_SEED);

    TwistSquash::SquashKeyA(ALDEBARAN_KEY_B_E_IceLaneA, ALDEBARAN_KEY_B_E_IceLaneB, ALDEBARAN_KEY_B_E_IceLaneC, ALDEBARAN_KEY_B_E_IceLaneD, &(pWorkSpace->mKeyBoxB[4U][0]));

    // Key flow — B / F

    TwistExpander_Aldebaran_Arx::KEY_B_F_A(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::KEY_B_F_B(PARAMS_SEED);

    KeyDiffuse_A_B_F(pWorkSpace);

    TwistExpander_Aldebaran_Arx::KEY_B_F_C(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::KEY_B_F_D(PARAMS_SEED);

    KeyDiffuse_B_B_F(pWorkSpace);

    TwistExpander_Aldebaran_Arx::KEY_B_F_E(PARAMS_SEED);

    TwistSquash::SquashKeyA(ALDEBARAN_KEY_B_F_IceLaneA, ALDEBARAN_KEY_B_F_IceLaneB, ALDEBARAN_KEY_B_F_IceLaneC, ALDEBARAN_KEY_B_F_IceLaneD, &(pWorkSpace->mKeyBoxB[5U][0]));

    // Key flow — B / G

    TwistExpander_Aldebaran_Arx::KEY_B_G_A(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::KEY_B_G_B(PARAMS_SEED);

    KeyDiffuse_A_B_G(pWorkSpace);

    TwistExpander_Aldebaran_Arx::KEY_B_G_C(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::KEY_B_G_D(PARAMS_SEED);

    KeyDiffuse_B_B_G(pWorkSpace);

    TwistExpander_Aldebaran_Arx::KEY_B_G_E(PARAMS_SEED);

    TwistSquash::SquashKeyA(ALDEBARAN_KEY_B_G_IceLaneA, ALDEBARAN_KEY_B_G_IceLaneB, ALDEBARAN_KEY_B_G_IceLaneC, ALDEBARAN_KEY_B_G_IceLaneD, &(pWorkSpace->mKeyBoxB[6U][0]));

    // Key flow — B / H

    TwistExpander_Aldebaran_Arx::KEY_B_H_A(PARAMS_SEED);

    TwistExpander_Aldebaran_Arx::KEY_B_H_B(PARAMS_SEED);

    KeyDiffuse_A_B_H(pWorkSpace);

    TwistExpander_Aldebaran_Arx::KEY_B_H_C(PARAMS_SEED);
    TwistExpander_Aldebaran_Arx::KEY_B_H_D(PARAMS_SEED);

    KeyDiffuse_B_B_H(pWorkSpace);

    TwistExpander_Aldebaran_Arx::KEY_B_H_E(PARAMS_SEED);

    TwistSquash::SquashKeyA(ALDEBARAN_KEY_B_H_IceLaneA, ALDEBARAN_KEY_B_H_IceLaneB, ALDEBARAN_KEY_B_H_IceLaneC, ALDEBARAN_KEY_B_H_IceLaneD, &(pWorkSpace->mKeyBoxB[7U][0]));

    //
    ////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////
    //
    // Folding main seed loops into destination
    //
    TwistSquash::SquashC(pWorkSpace->mAlchemyLaneA, pWorkSpace->mAlchemyLaneB, pWorkSpace->mAlchemyLaneC, pWorkSpace->mAlchemyLaneD, pDestination);
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
                                       bool pStifleKey) {
    if ((pWorkSpace == nullptr) || (pSource == nullptr) ||
        (pCrossLaneA == nullptr) || (pCrossLaneB == nullptr) ||
        (pCrossLaneC == nullptr) || (pCrossLaneD == nullptr) ||
        (pDestination == nullptr)) { return; }
    std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    std::uint8_t *aEarthLaneA = pWorkSpace->mEarthLaneA;
    std::uint8_t *aEarthLaneB = pWorkSpace->mEarthLaneB;
    std::uint8_t *aEarthLaneC = pWorkSpace->mEarthLaneC;
    std::uint8_t *aEarthLaneD = pWorkSpace->mEarthLaneD;
    std::uint8_t *aWindLaneA = pWorkSpace->mWindLaneA;
    std::uint8_t *aWindLaneB = pWorkSpace->mWindLaneB;
    std::uint8_t *aWindLaneC = pWorkSpace->mWindLaneC;
    std::uint8_t *aWindLaneD = pWorkSpace->mWindLaneD;
    std::size_t *aIndexList256A = pWorkSpace->mIndexList256A;
    std::size_t *aIndexList256B = pWorkSpace->mIndexList256B;
    std::size_t *aIndexList256C = pWorkSpace->mIndexList256C;
    std::size_t *aIndexList256D = pWorkSpace->mIndexList256D;
    std::uint64_t aIngress = 0U; std::uint64_t aCarry = 0U;

    std::uint64_t aWandererA = 0U; std::uint64_t aWandererB = 0U; std::uint64_t aWandererC = 0U; std::uint64_t aWandererD = 0U;
    std::uint64_t aWandererE = 0U; std::uint64_t aWandererF = 0U; std::uint64_t aWandererG = 0U; std::uint64_t aWandererH = 0U;
    std::uint64_t aWandererI = 0U; std::uint64_t aWandererJ = 0U; std::uint64_t aWandererK = 0U;

    aIngress = 0xDE88B396A7350B4AULL;
    aCarry = 0xB8C4CFC6A1A4A0EDULL;
    aWandererA = 0xECC13F516D5C6FA6ULL;
    aWandererB = 0xEB00BB20EAEEA78CULL;
    aWandererC = 0xCC71BED686E28401ULL;
    aWandererD = 0xBE8623EA0B95AB4FULL;
    aWandererE = 0x91CCD266957ACD02ULL;
    aWandererF = 0x82CABF629B73A8FBULL;
    aWandererG = 0x8CA570C83C4B5B24ULL;
    aWandererH = 0xFCACE98D412BA4F9ULL;
    aWandererI = 0xBC16C762A21DDC46ULL;
    aWandererJ = 0xE81F95DE21AA4B78ULL;
    aWandererK = 0xCD2AF4DBDBC9BAD3ULL;

    ////////////////////////////////////////////////////////
    //
    // Main twist loops
    //
    TwistExpander_Aldebaran_Arx::TWIST_A(PARAMS_TWIST);

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
        aFireLaneA, aFireLaneB, aFireLaneC, aFireLaneD,  // input lanes
        aWindLaneA, aWindLaneB, aWindLaneC, aWindLaneD, // output lanes
        aEarthLaneA, aEarthLaneB, aEarthLaneC, aEarthLaneD, // entropy lanes
        aIndexList256A, aIndexList256B, aIndexList256C, aIndexList256D, &mMatrix, aDomainWordMatrixSelectA, aDomainWordMatrixSelectB, aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB, aDomainWordMatrixArgA, aDomainWordMatrixArgB, aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    TwistExpander_Aldebaran_Arx::TWIST_C(PARAMS_TWIST);
    //
    ////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////
    //
    // Folding main twist loops into destination
    //
    TwistSquash::SquashA(pWorkSpace->mWaterLaneA, pWorkSpace->mWaterLaneB, pWorkSpace->mWaterLaneC, pWorkSpace->mWaterLaneD, pDestination);
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
        TwistForkKeyHalfA(pWorkSpace);
        TwistForkKeyHalfB(pWorkSpace);
        
        const std::uint64_t aGrowIngress = aIngress;
        const std::uint64_t aGrowCarry = aCarry;
        const std::uint64_t aGrowWandererA = aWandererA;
        const std::uint64_t aGrowWandererB = aWandererB;
        const std::uint64_t aGrowWandererC = aWandererC;
        const std::uint64_t aGrowWandererD = aWandererD;
        const std::uint64_t aGrowWandererE = aWandererE;
        const std::uint64_t aGrowWandererF = aWandererF;
        const std::uint64_t aGrowWandererG = aWandererG;
        const std::uint64_t aGrowWandererH = aWandererH;
        const std::uint64_t aGrowWandererI = aWandererI;
        const std::uint64_t aGrowWandererJ = aWandererJ;
        const std::uint64_t aGrowWandererK = aWandererK;
        
        GrowKeyA(pWorkSpace, pCrossLaneA, pCrossLaneC, ARX_STATE_VARS);
        
        aIngress = aGrowIngress;
        aCarry = aGrowCarry;
        aWandererA = aGrowWandererA;
        aWandererB = aGrowWandererB;
        aWandererC = aGrowWandererC;
        aWandererD = aGrowWandererD;
        aWandererE = aGrowWandererE;
        aWandererF = aGrowWandererF;
        aWandererG = aGrowWandererG;
        aWandererH = aGrowWandererH;
        aWandererI = aGrowWandererI;
        aWandererJ = aGrowWandererJ;
        aWandererK = aGrowWandererK;
        
        GrowKeyB(pWorkSpace, pCrossLaneB, pCrossLaneD, ARX_STATE_VARS);
        
    }
    //
    ////////////////////////////////////////////////////////
}

void TwistExpander_Aldebaran::GrowKeyA(TwistWorkSpace *pWorkSpace,
                  std::uint8_t *pCrossLaneA,
                  std::uint8_t *pCrossLaneB,
                  MUTABLE_PARAMS) {
    TwistExpander_Aldebaran_Arx::GROW_A_A(PARAMS_GROW);

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
        pWorkSpace->mWindLaneA,
        pWorkSpace->mWindLaneB,
        pWorkSpace->mWindLaneC,
        pWorkSpace->mWindLaneD,
        pWorkSpace->mWaterLaneA,
        pWorkSpace->mWaterLaneB,
        pWorkSpace->mWaterLaneC,
        pWorkSpace->mWaterLaneD,
        pWorkSpace->mFireLaneA,
        pWorkSpace->mFireLaneB,
        pWorkSpace->mFireLaneC,
        pWorkSpace->mFireLaneD,
        pWorkSpace->mIndexList256A, pWorkSpace->mIndexList256B,
        pWorkSpace->mIndexList256C, pWorkSpace->mIndexList256D,
        &mMatrix,
        aDomainWordMatrixSelectA, aDomainWordMatrixSelectB,
        aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB,
        aDomainWordMatrixArgA, aDomainWordMatrixArgB,
        aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    TwistExpander_Aldebaran_Arx::GROW_A_C(PARAMS_GROW);

    TwistExpander_Aldebaran_Arx::GROW_A_D(PARAMS_GROW);

    TwistDiffuse::KeyDiffuseWithDomainWordsA(
        pWorkSpace->mFrostLaneA,
        pWorkSpace->mFrostLaneB,
        pWorkSpace->mFrostLaneC,
        pWorkSpace->mFrostLaneD,
        pWorkSpace->mKineticLaneA,
        pWorkSpace->mKineticLaneB,
        pWorkSpace->mKineticLaneC,
        pWorkSpace->mKineticLaneD,
        pWorkSpace->mSonicLaneA,
        pWorkSpace->mSonicLaneB,
        pWorkSpace->mSonicLaneC,
        pWorkSpace->mSonicLaneD,
        pWorkSpace->mIndexList256A, pWorkSpace->mIndexList256B,
        pWorkSpace->mIndexList256C, pWorkSpace->mIndexList256D,
        &mMatrix,
        aDomainWordMatrixSelectA, aDomainWordMatrixSelectB,
        aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB,
        aDomainWordMatrixArgA, aDomainWordMatrixArgB,
        aDomainWordMatrixArgC, aDomainWordMatrixArgD);

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
    TwistExpander_Aldebaran_Arx::GROW_B_A(PARAMS_GROW);

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
        pWorkSpace->mWindLaneA,
        pWorkSpace->mWindLaneB,
        pWorkSpace->mWindLaneC,
        pWorkSpace->mWindLaneD,
        pWorkSpace->mWaterLaneA,
        pWorkSpace->mWaterLaneB,
        pWorkSpace->mWaterLaneC,
        pWorkSpace->mWaterLaneD,
        pWorkSpace->mFireLaneA,
        pWorkSpace->mFireLaneB,
        pWorkSpace->mFireLaneC,
        pWorkSpace->mFireLaneD,
        pWorkSpace->mIndexList256A, pWorkSpace->mIndexList256B,
        pWorkSpace->mIndexList256C, pWorkSpace->mIndexList256D,
        &mMatrix,
        aDomainWordMatrixSelectA, aDomainWordMatrixSelectB,
        aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB,
        aDomainWordMatrixArgA, aDomainWordMatrixArgB,
        aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    TwistExpander_Aldebaran_Arx::GROW_B_C(PARAMS_GROW);

    TwistExpander_Aldebaran_Arx::GROW_B_D(PARAMS_GROW);

    TwistDiffuse::KeyDiffuseWithDomainWordsB(
        pWorkSpace->mFrostLaneA,
        pWorkSpace->mFrostLaneB,
        pWorkSpace->mFrostLaneC,
        pWorkSpace->mFrostLaneD,
        pWorkSpace->mKineticLaneA,
        pWorkSpace->mKineticLaneB,
        pWorkSpace->mKineticLaneC,
        pWorkSpace->mKineticLaneD,
        pWorkSpace->mSonicLaneA,
        pWorkSpace->mSonicLaneB,
        pWorkSpace->mSonicLaneC,
        pWorkSpace->mSonicLaneD,
        pWorkSpace->mIndexList256A, pWorkSpace->mIndexList256B,
        pWorkSpace->mIndexList256C, pWorkSpace->mIndexList256D,
        &mMatrix,
        aDomainWordMatrixSelectA, aDomainWordMatrixSelectB,
        aDomainWordMatrixUnrollA, aDomainWordMatrixUnrollB,
        aDomainWordMatrixArgA, aDomainWordMatrixArgB,
        aDomainWordMatrixArgC, aDomainWordMatrixArgD);

    TwistExpander_Aldebaran_Arx::GROW_B_E(PARAMS_GROW);

    TwistShiftBox::ShiftKeyBoxB(pWorkSpace);
    TwistSquash::SquashKeyA(
        pWorkSpace->mIceLaneA + (W_KEY * 1U),
        pWorkSpace->mIceLaneB + (W_KEY * 1U),
        pWorkSpace->mIceLaneC + (W_KEY * 1U),
        pWorkSpace->mIceLaneD + (W_KEY * 1U),
        &(pWorkSpace->mKeyBoxB[0][0]));
}

void TwistExpander_Aldebaran::TwistForkKeyHalfA(TwistWorkSpace *pWorkSpace) {
    static_assert(S_BLOCK == 32768, "Twist fork source size changed.");
    static_assert(S_HALF == 16384, "Twist fork half size changed.");
    static_assert(W_KEY == 2048, "Twist fork key size changed.");

    std::uint8_t *aSourceLaneA = pWorkSpace->mWaterLaneA;
    std::uint8_t *aSourceLaneB = pWorkSpace->mWaterLaneB;
    std::uint8_t *aSourceLaneC = pWorkSpace->mWaterLaneC;
    std::uint8_t *aSourceLaneD = pWorkSpace->mWaterLaneD;

    std::uint8_t *aStageOneLaneA = pWorkSpace->mPlanarLaneA;
    std::uint8_t *aStageOneLaneB = pWorkSpace->mPlanarLaneB;
    std::uint8_t *aStageOneLaneC = pWorkSpace->mPlanarLaneC;
    std::uint8_t *aStageOneLaneD = pWorkSpace->mPlanarLaneD;

    std::uint8_t *aStageTwoLaneA = pWorkSpace->mArcaneLaneA;
    std::uint8_t *aStageTwoLaneB = pWorkSpace->mArcaneLaneB;
    std::uint8_t *aStageTwoLaneC = pWorkSpace->mArcaneLaneC;
    std::uint8_t *aStageTwoLaneD = pWorkSpace->mArcaneLaneD;

    // Fold Stage I — 4 x 16,384 bytes into 4 x 8,192 bytes.

    // Destination A, block 0: source A half 0 block 0 + source B half 0 block 3
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 0U * S_HALF + 0U * W_KEY + ((aIndex + 137U) & W_KEY1);
        const std::size_t aSourceIndexB = 0U * S_HALF + 3U * W_KEY + ((aIndex + 92U) & W_KEY1);
        const std::size_t aDestinationIndex = 0U * (S_HALF >> 1U) + 0U * W_KEY + aIndex;

        std::uint16_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneA[aSourceIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneB[aSourceIndexB]) << 8U;
        aFoldValue = TwistMix16::DiffuseA(aFoldValue);

        aStageOneLaneA[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 0U);
    }

    // Destination A, block 1: source B half 0 block 4 + source C half 1 block 6
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 0U * S_HALF + 4U * W_KEY + ((aIndex + 47U) & W_KEY1);
        const std::size_t aSourceIndexB = 1U * S_HALF + 6U * W_KEY + ((aIndex + 2U) & W_KEY1);
        const std::size_t aDestinationIndex = 0U * (S_HALF >> 1U) + 1U * W_KEY + aIndex;

        std::uint16_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneB[aSourceIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneC[aSourceIndexB]) << 8U;
        aFoldValue = TwistMix16::DiffuseA(aFoldValue);

        aStageOneLaneA[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 0U);
    }

    // Destination A, block 2: source C half 1 block 7 + source D half 1 block 1
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 1U * S_HALF + 7U * W_KEY + ((aIndex + 2005U) & W_KEY1);
        const std::size_t aSourceIndexB = 1U * S_HALF + 1U * W_KEY + ((aIndex + 1960U) & W_KEY1);
        const std::size_t aDestinationIndex = 0U * (S_HALF >> 1U) + 2U * W_KEY + aIndex;

        std::uint16_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneC[aSourceIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneD[aSourceIndexB]) << 8U;
        aFoldValue = TwistMix16::DiffuseA(aFoldValue);

        aStageOneLaneA[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 8U);
    }

    // Destination A, block 3: source D half 1 block 2 + source A half 0 block 1
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 1U * S_HALF + 2U * W_KEY + ((aIndex + 1915U) & W_KEY1);
        const std::size_t aSourceIndexB = 0U * S_HALF + 1U * W_KEY + ((aIndex + 1870U) & W_KEY1);
        const std::size_t aDestinationIndex = 0U * (S_HALF >> 1U) + 3U * W_KEY + aIndex;

        std::uint16_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneD[aSourceIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneA[aSourceIndexB]) << 8U;
        aFoldValue = TwistMix16::DiffuseA(aFoldValue);

        aStageOneLaneA[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 8U);
    }

    // Destination B, block 0: source D half 1 block 3 + source A half 0 block 2
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 1U * S_HALF + 3U * W_KEY + ((aIndex + 1825U) & W_KEY1);
        const std::size_t aSourceIndexB = 0U * S_HALF + 2U * W_KEY + ((aIndex + 1780U) & W_KEY1);
        const std::size_t aDestinationIndex = 0U * (S_HALF >> 1U) + 0U * W_KEY + aIndex;

        std::uint16_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneD[aSourceIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneA[aSourceIndexB]) << 8U;
        aFoldValue = TwistMix16::DiffuseA(aFoldValue);

        aStageOneLaneB[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 0U);
    }

    // Destination B, block 1: source C half 1 block 0 + source D half 1 block 4
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 1U * S_HALF + 0U * W_KEY + ((aIndex + 1735U) & W_KEY1);
        const std::size_t aSourceIndexB = 1U * S_HALF + 4U * W_KEY + ((aIndex + 1690U) & W_KEY1);
        const std::size_t aDestinationIndex = 0U * (S_HALF >> 1U) + 1U * W_KEY + aIndex;

        std::uint16_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneC[aSourceIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneD[aSourceIndexB]) << 8U;
        aFoldValue = TwistMix16::DiffuseA(aFoldValue);

        aStageOneLaneB[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 0U);
    }

    // Destination B, block 2: source B half 0 block 5 + source C half 1 block 1
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 0U * S_HALF + 5U * W_KEY + ((aIndex + 1645U) & W_KEY1);
        const std::size_t aSourceIndexB = 1U * S_HALF + 1U * W_KEY + ((aIndex + 1600U) & W_KEY1);
        const std::size_t aDestinationIndex = 0U * (S_HALF >> 1U) + 2U * W_KEY + aIndex;

        std::uint16_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneB[aSourceIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneC[aSourceIndexB]) << 8U;
        aFoldValue = TwistMix16::DiffuseA(aFoldValue);

        aStageOneLaneB[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 8U);
    }

    // Destination B, block 3: source A half 0 block 3 + source B half 0 block 6
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 0U * S_HALF + 3U * W_KEY + ((aIndex + 1555U) & W_KEY1);
        const std::size_t aSourceIndexB = 0U * S_HALF + 6U * W_KEY + ((aIndex + 1510U) & W_KEY1);
        const std::size_t aDestinationIndex = 0U * (S_HALF >> 1U) + 3U * W_KEY + aIndex;

        std::uint16_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneA[aSourceIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneB[aSourceIndexB]) << 8U;
        aFoldValue = TwistMix16::DiffuseA(aFoldValue);

        aStageOneLaneB[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 8U);
    }

    // Destination C, block 0: source A half 0 block 4 + source C half 1 block 2
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 0U * S_HALF + 4U * W_KEY + ((aIndex + 1465U) & W_KEY1);
        const std::size_t aSourceIndexB = 1U * S_HALF + 2U * W_KEY + ((aIndex + 1420U) & W_KEY1);
        const std::size_t aDestinationIndex = 0U * (S_HALF >> 1U) + 0U * W_KEY + aIndex;

        std::uint16_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneA[aSourceIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneC[aSourceIndexB]) << 8U;
        aFoldValue = TwistMix16::DiffuseA(aFoldValue);

        aStageOneLaneC[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 8U);
    }

    // Destination C, block 1: source C half 1 block 3 + source B half 0 block 7
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 1U * S_HALF + 3U * W_KEY + ((aIndex + 1375U) & W_KEY1);
        const std::size_t aSourceIndexB = 0U * S_HALF + 7U * W_KEY + ((aIndex + 1330U) & W_KEY1);
        const std::size_t aDestinationIndex = 0U * (S_HALF >> 1U) + 1U * W_KEY + aIndex;

        std::uint16_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneC[aSourceIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneB[aSourceIndexB]) << 8U;
        aFoldValue = TwistMix16::DiffuseA(aFoldValue);

        aStageOneLaneC[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 0U);
    }

    // Destination C, block 2: source B half 0 block 0 + source D half 1 block 5
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 0U * S_HALF + 0U * W_KEY + ((aIndex + 1285U) & W_KEY1);
        const std::size_t aSourceIndexB = 1U * S_HALF + 5U * W_KEY + ((aIndex + 1240U) & W_KEY1);
        const std::size_t aDestinationIndex = 0U * (S_HALF >> 1U) + 2U * W_KEY + aIndex;

        std::uint16_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneB[aSourceIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneD[aSourceIndexB]) << 8U;
        aFoldValue = TwistMix16::DiffuseA(aFoldValue);

        aStageOneLaneC[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 0U);
    }

    // Destination C, block 3: source D half 1 block 6 + source A half 0 block 5
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 1U * S_HALF + 6U * W_KEY + ((aIndex + 1195U) & W_KEY1);
        const std::size_t aSourceIndexB = 0U * S_HALF + 5U * W_KEY + ((aIndex + 1150U) & W_KEY1);
        const std::size_t aDestinationIndex = 0U * (S_HALF >> 1U) + 3U * W_KEY + aIndex;

        std::uint16_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneD[aSourceIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneA[aSourceIndexB]) << 8U;
        aFoldValue = TwistMix16::DiffuseA(aFoldValue);

        aStageOneLaneC[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 8U);
    }

    // Destination D, block 0: source A half 0 block 6 + source D half 1 block 7
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 0U * S_HALF + 6U * W_KEY + ((aIndex + 1105U) & W_KEY1);
        const std::size_t aSourceIndexB = 1U * S_HALF + 7U * W_KEY + ((aIndex + 1060U) & W_KEY1);
        const std::size_t aDestinationIndex = 0U * (S_HALF >> 1U) + 0U * W_KEY + aIndex;

        std::uint16_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneA[aSourceIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneD[aSourceIndexB]) << 8U;
        aFoldValue = TwistMix16::DiffuseA(aFoldValue);

        aStageOneLaneD[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 8U);
    }

    // Destination D, block 1: source C half 1 block 4 + source A half 0 block 7
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 1U * S_HALF + 4U * W_KEY + ((aIndex + 1015U) & W_KEY1);
        const std::size_t aSourceIndexB = 0U * S_HALF + 7U * W_KEY + ((aIndex + 970U) & W_KEY1);
        const std::size_t aDestinationIndex = 0U * (S_HALF >> 1U) + 1U * W_KEY + aIndex;

        std::uint16_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneC[aSourceIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneA[aSourceIndexB]) << 8U;
        aFoldValue = TwistMix16::DiffuseA(aFoldValue);

        aStageOneLaneD[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 0U);
    }

    // Destination D, block 2: source B half 0 block 1 + source C half 1 block 5
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 0U * S_HALF + 1U * W_KEY + ((aIndex + 925U) & W_KEY1);
        const std::size_t aSourceIndexB = 1U * S_HALF + 5U * W_KEY + ((aIndex + 880U) & W_KEY1);
        const std::size_t aDestinationIndex = 0U * (S_HALF >> 1U) + 2U * W_KEY + aIndex;

        std::uint16_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneB[aSourceIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneC[aSourceIndexB]) << 8U;
        aFoldValue = TwistMix16::DiffuseA(aFoldValue);

        aStageOneLaneD[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 8U);
    }

    // Destination D, block 3: source D half 1 block 0 + source B half 0 block 2
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 1U * S_HALF + 0U * W_KEY + ((aIndex + 835U) & W_KEY1);
        const std::size_t aSourceIndexB = 0U * S_HALF + 2U * W_KEY + ((aIndex + 790U) & W_KEY1);
        const std::size_t aDestinationIndex = 0U * (S_HALF >> 1U) + 3U * W_KEY + aIndex;

        std::uint16_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneD[aSourceIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneB[aSourceIndexB]) << 8U;
        aFoldValue = TwistMix16::DiffuseA(aFoldValue);

        aStageOneLaneD[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 0U);
    }

    // Fold Stage II — 4 x 8,192 bytes into 4 x W_KEY bytes.

    // Key piece A
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 0U * (S_HALF >> 1U) + 0U * W_KEY + ((aIndex + 911U) & W_KEY1);
        const std::size_t aSourceIndexB = 0U * (S_HALF >> 1U) + 0U * W_KEY + ((aIndex + 866U) & W_KEY1);
        const std::size_t aSourceIndexC = 0U * (S_HALF >> 1U) + 1U * W_KEY + ((aIndex + 821U) & W_KEY1);
        const std::size_t aSourceIndexD = 0U * (S_HALF >> 1U) + 2U * W_KEY + ((aIndex + 776U) & W_KEY1);
        const std::size_t aDestinationIndex = 0U * W_KEY + aIndex;

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aStageOneLaneA[aSourceIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aStageOneLaneB[aSourceIndexB]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aStageOneLaneC[aSourceIndexC]) << 16U;
        aFoldValue |= static_cast<std::uint32_t>(aStageOneLaneD[aSourceIndexD]) << 24U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);

        aStageTwoLaneA[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 0U);
    }

    // Key piece B
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 0U * (S_HALF >> 1U) + 1U * W_KEY + ((aIndex + 731U) & W_KEY1);
        const std::size_t aSourceIndexB = 0U * (S_HALF >> 1U) + 3U * W_KEY + ((aIndex + 686U) & W_KEY1);
        const std::size_t aSourceIndexC = 0U * (S_HALF >> 1U) + 3U * W_KEY + ((aIndex + 641U) & W_KEY1);
        const std::size_t aSourceIndexD = 0U * (S_HALF >> 1U) + 1U * W_KEY + ((aIndex + 596U) & W_KEY1);
        const std::size_t aDestinationIndex = 0U * W_KEY + aIndex;

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aStageOneLaneA[aSourceIndexA]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aStageOneLaneB[aSourceIndexB]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aStageOneLaneC[aSourceIndexC]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aStageOneLaneD[aSourceIndexD]) << 16U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);

        aStageTwoLaneB[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 8U);
    }

    // Key piece C
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 0U * (S_HALF >> 1U) + 2U * W_KEY + ((aIndex + 551U) & W_KEY1);
        const std::size_t aSourceIndexB = 0U * (S_HALF >> 1U) + 2U * W_KEY + ((aIndex + 506U) & W_KEY1);
        const std::size_t aSourceIndexC = 0U * (S_HALF >> 1U) + 0U * W_KEY + ((aIndex + 461U) & W_KEY1);
        const std::size_t aSourceIndexD = 0U * (S_HALF >> 1U) + 3U * W_KEY + ((aIndex + 416U) & W_KEY1);
        const std::size_t aDestinationIndex = 0U * W_KEY + aIndex;

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aStageOneLaneA[aSourceIndexA]) << 16U;
        aFoldValue |= static_cast<std::uint32_t>(aStageOneLaneB[aSourceIndexB]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aStageOneLaneC[aSourceIndexC]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aStageOneLaneD[aSourceIndexD]) << 24U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);

        aStageTwoLaneC[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 16U);
    }

    // Key piece D
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 0U * (S_HALF >> 1U) + 3U * W_KEY + ((aIndex + 371U) & W_KEY1);
        const std::size_t aSourceIndexB = 0U * (S_HALF >> 1U) + 1U * W_KEY + ((aIndex + 326U) & W_KEY1);
        const std::size_t aSourceIndexC = 0U * (S_HALF >> 1U) + 2U * W_KEY + ((aIndex + 281U) & W_KEY1);
        const std::size_t aSourceIndexD = 0U * (S_HALF >> 1U) + 0U * W_KEY + ((aIndex + 236U) & W_KEY1);
        const std::size_t aDestinationIndex = 0U * W_KEY + aIndex;

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aStageOneLaneA[aSourceIndexA]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aStageOneLaneB[aSourceIndexB]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aStageOneLaneC[aSourceIndexC]) << 16U;
        aFoldValue |= static_cast<std::uint32_t>(aStageOneLaneD[aSourceIndexD]) << 0U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);

        aStageTwoLaneD[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 24U);
    }
}

void TwistExpander_Aldebaran::TwistForkKeyHalfB(TwistWorkSpace *pWorkSpace) {
    static_assert(S_BLOCK == 32768, "Twist fork source size changed.");
    static_assert(S_HALF == 16384, "Twist fork half size changed.");
    static_assert(W_KEY == 2048, "Twist fork key size changed.");

    std::uint8_t *aSourceLaneA = pWorkSpace->mWaterLaneA;
    std::uint8_t *aSourceLaneB = pWorkSpace->mWaterLaneB;
    std::uint8_t *aSourceLaneC = pWorkSpace->mWaterLaneC;
    std::uint8_t *aSourceLaneD = pWorkSpace->mWaterLaneD;

    std::uint8_t *aStageOneLaneA = pWorkSpace->mPlanarLaneA;
    std::uint8_t *aStageOneLaneB = pWorkSpace->mPlanarLaneB;
    std::uint8_t *aStageOneLaneC = pWorkSpace->mPlanarLaneC;
    std::uint8_t *aStageOneLaneD = pWorkSpace->mPlanarLaneD;

    std::uint8_t *aStageTwoLaneA = pWorkSpace->mRunicLaneA;
    std::uint8_t *aStageTwoLaneB = pWorkSpace->mRunicLaneB;
    std::uint8_t *aStageTwoLaneC = pWorkSpace->mRunicLaneC;
    std::uint8_t *aStageTwoLaneD = pWorkSpace->mRunicLaneD;

    // Fold Stage I — 4 x 16,384 bytes into 4 x 8,192 bytes.

    // Destination A, block 0: source D half 0 block 2 + source B half 1 block 4
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 0U * S_HALF + 2U * W_KEY + ((aIndex + 745U) & W_KEY1);
        const std::size_t aSourceIndexB = 1U * S_HALF + 4U * W_KEY + ((aIndex + 700U) & W_KEY1);
        const std::size_t aDestinationIndex = 1U * (S_HALF >> 1U) + 0U * W_KEY + aIndex;

        std::uint16_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneD[aSourceIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneB[aSourceIndexB]) << 8U;
        aFoldValue = TwistMix16::DiffuseA(aFoldValue);

        aStageOneLaneA[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 8U);
    }

    // Destination A, block 1: source C half 0 block 7 + source D half 0 block 5
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 0U * S_HALF + 7U * W_KEY + ((aIndex + 655U) & W_KEY1);
        const std::size_t aSourceIndexB = 0U * S_HALF + 5U * W_KEY + ((aIndex + 610U) & W_KEY1);
        const std::size_t aDestinationIndex = 1U * (S_HALF >> 1U) + 1U * W_KEY + aIndex;

        std::uint16_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneC[aSourceIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneD[aSourceIndexB]) << 8U;
        aFoldValue = TwistMix16::DiffuseA(aFoldValue);

        aStageOneLaneA[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 0U);
    }

    // Destination A, block 2: source A half 1 block 1 + source C half 0 block 2
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 1U * S_HALF + 1U * W_KEY + ((aIndex + 565U) & W_KEY1);
        const std::size_t aSourceIndexB = 0U * S_HALF + 2U * W_KEY + ((aIndex + 520U) & W_KEY1);
        const std::size_t aDestinationIndex = 1U * (S_HALF >> 1U) + 2U * W_KEY + aIndex;

        std::uint16_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneA[aSourceIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneC[aSourceIndexB]) << 8U;
        aFoldValue = TwistMix16::DiffuseA(aFoldValue);

        aStageOneLaneA[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 8U);
    }

    // Destination A, block 3: source B half 1 block 7 + source A half 1 block 4
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 1U * S_HALF + 7U * W_KEY + ((aIndex + 475U) & W_KEY1);
        const std::size_t aSourceIndexB = 1U * S_HALF + 4U * W_KEY + ((aIndex + 430U) & W_KEY1);
        const std::size_t aDestinationIndex = 1U * (S_HALF >> 1U) + 3U * W_KEY + aIndex;

        std::uint16_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneB[aSourceIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneA[aSourceIndexB]) << 8U;
        aFoldValue = TwistMix16::DiffuseA(aFoldValue);

        aStageOneLaneA[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 0U);
    }

    // Destination B, block 0: source A half 1 block 7 + source B half 1 block 2
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 1U * S_HALF + 7U * W_KEY + ((aIndex + 385U) & W_KEY1);
        const std::size_t aSourceIndexB = 1U * S_HALF + 2U * W_KEY + ((aIndex + 340U) & W_KEY1);
        const std::size_t aDestinationIndex = 1U * (S_HALF >> 1U) + 0U * W_KEY + aIndex;

        std::uint16_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneA[aSourceIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneB[aSourceIndexB]) << 8U;
        aFoldValue = TwistMix16::DiffuseA(aFoldValue);

        aStageOneLaneB[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 8U);
    }

    // Destination B, block 1: source B half 1 block 5 + source C half 0 block 5
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 1U * S_HALF + 5U * W_KEY + ((aIndex + 295U) & W_KEY1);
        const std::size_t aSourceIndexB = 0U * S_HALF + 5U * W_KEY + ((aIndex + 250U) & W_KEY1);
        const std::size_t aDestinationIndex = 1U * (S_HALF >> 1U) + 1U * W_KEY + aIndex;

        std::uint16_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneB[aSourceIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneC[aSourceIndexB]) << 8U;
        aFoldValue = TwistMix16::DiffuseA(aFoldValue);

        aStageOneLaneB[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 0U);
    }

    // Destination B, block 2: source C half 0 block 0 + source D half 0 block 0
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 0U * S_HALF + 0U * W_KEY + ((aIndex + 205U) & W_KEY1);
        const std::size_t aSourceIndexB = 0U * S_HALF + 0U * W_KEY + ((aIndex + 160U) & W_KEY1);
        const std::size_t aDestinationIndex = 1U * (S_HALF >> 1U) + 2U * W_KEY + aIndex;

        std::uint16_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneC[aSourceIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneD[aSourceIndexB]) << 8U;
        aFoldValue = TwistMix16::DiffuseA(aFoldValue);

        aStageOneLaneB[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 0U);
    }

    // Destination B, block 3: source D half 0 block 3 + source A half 1 block 2
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 0U * S_HALF + 3U * W_KEY + ((aIndex + 115U) & W_KEY1);
        const std::size_t aSourceIndexB = 1U * S_HALF + 2U * W_KEY + ((aIndex + 70U) & W_KEY1);
        const std::size_t aDestinationIndex = 1U * (S_HALF >> 1U) + 3U * W_KEY + aIndex;

        std::uint16_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneD[aSourceIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneA[aSourceIndexB]) << 8U;
        aFoldValue = TwistMix16::DiffuseA(aFoldValue);

        aStageOneLaneB[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 8U);
    }

    // Destination C, block 0: source A half 1 block 5 + source C half 0 block 3
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 1U * S_HALF + 5U * W_KEY + ((aIndex + 25U) & W_KEY1);
        const std::size_t aSourceIndexB = 0U * S_HALF + 3U * W_KEY + ((aIndex + 2028U) & W_KEY1);
        const std::size_t aDestinationIndex = 1U * (S_HALF >> 1U) + 0U * W_KEY + aIndex;

        std::uint16_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneA[aSourceIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneC[aSourceIndexB]) << 8U;
        aFoldValue = TwistMix16::DiffuseA(aFoldValue);

        aStageOneLaneC[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 0U);
    }

    // Destination C, block 1: source D half 0 block 6 + source A half 1 block 0
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 0U * S_HALF + 6U * W_KEY + ((aIndex + 1983U) & W_KEY1);
        const std::size_t aSourceIndexB = 1U * S_HALF + 0U * W_KEY + ((aIndex + 1938U) & W_KEY1);
        const std::size_t aDestinationIndex = 1U * (S_HALF >> 1U) + 1U * W_KEY + aIndex;

        std::uint16_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneD[aSourceIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneA[aSourceIndexB]) << 8U;
        aFoldValue = TwistMix16::DiffuseA(aFoldValue);

        aStageOneLaneC[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 8U);
    }

    // Destination C, block 2: source B half 1 block 0 + source D half 0 block 1
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 1U * S_HALF + 0U * W_KEY + ((aIndex + 1893U) & W_KEY1);
        const std::size_t aSourceIndexB = 0U * S_HALF + 1U * W_KEY + ((aIndex + 1848U) & W_KEY1);
        const std::size_t aDestinationIndex = 1U * (S_HALF >> 1U) + 2U * W_KEY + aIndex;

        std::uint16_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneB[aSourceIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneD[aSourceIndexB]) << 8U;
        aFoldValue = TwistMix16::DiffuseA(aFoldValue);

        aStageOneLaneC[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 8U);
    }

    // Destination C, block 3: source C half 0 block 6 + source B half 1 block 3
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 0U * S_HALF + 6U * W_KEY + ((aIndex + 1803U) & W_KEY1);
        const std::size_t aSourceIndexB = 1U * S_HALF + 3U * W_KEY + ((aIndex + 1758U) & W_KEY1);
        const std::size_t aDestinationIndex = 1U * (S_HALF >> 1U) + 3U * W_KEY + aIndex;

        std::uint16_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneC[aSourceIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneB[aSourceIndexB]) << 8U;
        aFoldValue = TwistMix16::DiffuseA(aFoldValue);

        aStageOneLaneC[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 0U);
    }

    // Destination D, block 0: source A half 1 block 3 + source C half 0 block 1
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 1U * S_HALF + 3U * W_KEY + ((aIndex + 1713U) & W_KEY1);
        const std::size_t aSourceIndexB = 0U * S_HALF + 1U * W_KEY + ((aIndex + 1668U) & W_KEY1);
        const std::size_t aDestinationIndex = 1U * (S_HALF >> 1U) + 0U * W_KEY + aIndex;

        std::uint16_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneA[aSourceIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneC[aSourceIndexB]) << 8U;
        aFoldValue = TwistMix16::DiffuseA(aFoldValue);

        aStageOneLaneD[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 0U);
    }

    // Destination D, block 1: source C half 0 block 4 + source B half 1 block 6
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 0U * S_HALF + 4U * W_KEY + ((aIndex + 1623U) & W_KEY1);
        const std::size_t aSourceIndexB = 1U * S_HALF + 6U * W_KEY + ((aIndex + 1578U) & W_KEY1);
        const std::size_t aDestinationIndex = 1U * (S_HALF >> 1U) + 1U * W_KEY + aIndex;

        std::uint16_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneC[aSourceIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneB[aSourceIndexB]) << 8U;
        aFoldValue = TwistMix16::DiffuseA(aFoldValue);

        aStageOneLaneD[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 8U);
    }

    // Destination D, block 2: source B half 1 block 1 + source D half 0 block 4
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 1U * S_HALF + 1U * W_KEY + ((aIndex + 1533U) & W_KEY1);
        const std::size_t aSourceIndexB = 0U * S_HALF + 4U * W_KEY + ((aIndex + 1488U) & W_KEY1);
        const std::size_t aDestinationIndex = 1U * (S_HALF >> 1U) + 2U * W_KEY + aIndex;

        std::uint16_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneB[aSourceIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneD[aSourceIndexB]) << 8U;
        aFoldValue = TwistMix16::DiffuseA(aFoldValue);

        aStageOneLaneD[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 0U);
    }

    // Destination D, block 3: source D half 0 block 7 + source A half 1 block 6
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 0U * S_HALF + 7U * W_KEY + ((aIndex + 1443U) & W_KEY1);
        const std::size_t aSourceIndexB = 1U * S_HALF + 6U * W_KEY + ((aIndex + 1398U) & W_KEY1);
        const std::size_t aDestinationIndex = 1U * (S_HALF >> 1U) + 3U * W_KEY + aIndex;

        std::uint16_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneD[aSourceIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint16_t>(aSourceLaneA[aSourceIndexB]) << 8U;
        aFoldValue = TwistMix16::DiffuseA(aFoldValue);

        aStageOneLaneD[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 8U);
    }

    // Fold Stage II — 4 x 8,192 bytes into 4 x W_KEY bytes.

    // Key piece A
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 1U * (S_HALF >> 1U) + 1U * W_KEY + ((aIndex + 191U) & W_KEY1);
        const std::size_t aSourceIndexB = 1U * (S_HALF >> 1U) + 2U * W_KEY + ((aIndex + 146U) & W_KEY1);
        const std::size_t aSourceIndexC = 1U * (S_HALF >> 1U) + 2U * W_KEY + ((aIndex + 101U) & W_KEY1);
        const std::size_t aSourceIndexD = 1U * (S_HALF >> 1U) + 3U * W_KEY + ((aIndex + 56U) & W_KEY1);
        const std::size_t aDestinationIndex = 1U * W_KEY + aIndex;

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aStageOneLaneA[aSourceIndexA]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aStageOneLaneB[aSourceIndexB]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aStageOneLaneC[aSourceIndexC]) << 16U;
        aFoldValue |= static_cast<std::uint32_t>(aStageOneLaneD[aSourceIndexD]) << 0U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);

        aStageTwoLaneA[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 8U);
    }

    // Key piece B
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 1U * (S_HALF >> 1U) + 0U * W_KEY + ((aIndex + 11U) & W_KEY1);
        const std::size_t aSourceIndexB = 1U * (S_HALF >> 1U) + 0U * W_KEY + ((aIndex + 2014U) & W_KEY1);
        const std::size_t aSourceIndexC = 1U * (S_HALF >> 1U) + 3U * W_KEY + ((aIndex + 1969U) & W_KEY1);
        const std::size_t aSourceIndexD = 1U * (S_HALF >> 1U) + 2U * W_KEY + ((aIndex + 1924U) & W_KEY1);
        const std::size_t aDestinationIndex = 1U * W_KEY + aIndex;

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aStageOneLaneA[aSourceIndexA]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aStageOneLaneB[aSourceIndexB]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aStageOneLaneC[aSourceIndexC]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aStageOneLaneD[aSourceIndexD]) << 16U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);

        aStageTwoLaneB[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 24U);
    }

    // Key piece C
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 1U * (S_HALF >> 1U) + 3U * W_KEY + ((aIndex + 1879U) & W_KEY1);
        const std::size_t aSourceIndexB = 1U * (S_HALF >> 1U) + 1U * W_KEY + ((aIndex + 1834U) & W_KEY1);
        const std::size_t aSourceIndexC = 1U * (S_HALF >> 1U) + 1U * W_KEY + ((aIndex + 1789U) & W_KEY1);
        const std::size_t aSourceIndexD = 1U * (S_HALF >> 1U) + 0U * W_KEY + ((aIndex + 1744U) & W_KEY1);
        const std::size_t aDestinationIndex = 1U * W_KEY + aIndex;

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aStageOneLaneA[aSourceIndexA]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aStageOneLaneB[aSourceIndexB]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aStageOneLaneC[aSourceIndexC]) << 24U;
        aFoldValue |= static_cast<std::uint32_t>(aStageOneLaneD[aSourceIndexD]) << 16U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);

        aStageTwoLaneC[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 16U);
    }

    // Key piece D
    for (std::size_t aIndex = 0U; aIndex < W_KEY; ++aIndex) {
        const std::size_t aSourceIndexA = 1U * (S_HALF >> 1U) + 2U * W_KEY + ((aIndex + 1699U) & W_KEY1);
        const std::size_t aSourceIndexB = 1U * (S_HALF >> 1U) + 3U * W_KEY + ((aIndex + 1654U) & W_KEY1);
        const std::size_t aSourceIndexC = 1U * (S_HALF >> 1U) + 0U * W_KEY + ((aIndex + 1609U) & W_KEY1);
        const std::size_t aSourceIndexD = 1U * (S_HALF >> 1U) + 1U * W_KEY + ((aIndex + 1564U) & W_KEY1);
        const std::size_t aDestinationIndex = 1U * W_KEY + aIndex;

        std::uint32_t aFoldValue = 0U;
        aFoldValue |= static_cast<std::uint32_t>(aStageOneLaneA[aSourceIndexA]) << 8U;
        aFoldValue |= static_cast<std::uint32_t>(aStageOneLaneB[aSourceIndexB]) << 16U;
        aFoldValue |= static_cast<std::uint32_t>(aStageOneLaneC[aSourceIndexC]) << 0U;
        aFoldValue |= static_cast<std::uint32_t>(aStageOneLaneD[aSourceIndexD]) << 24U;
        aFoldValue = TwistMix32::DiffuseA(aFoldValue);

        aStageTwoLaneD[aDestinationIndex] = static_cast<std::uint8_t>(aFoldValue >> 0U);
    }
}

void TwistExpander_Aldebaran::KeyDiffuse_A_A_A(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_A_A_AuguryLaneA,
        ALDEBARAN_KEY_A_A_AuguryLaneB,
        ALDEBARAN_KEY_A_A_AuguryLaneC,
        ALDEBARAN_KEY_A_A_AuguryLaneD,
        ALDEBARAN_KEY_A_A_ProphecyLaneA,
        ALDEBARAN_KEY_A_A_ProphecyLaneB,
        ALDEBARAN_KEY_A_A_ProphecyLaneC,
        ALDEBARAN_KEY_A_A_ProphecyLaneD,
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
}

void TwistExpander_Aldebaran::KeyDiffuse_A_A_B(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_A_B_AuguryLaneA,
        ALDEBARAN_KEY_A_B_AuguryLaneB,
        ALDEBARAN_KEY_A_B_AuguryLaneC,
        ALDEBARAN_KEY_A_B_AuguryLaneD,
        ALDEBARAN_KEY_A_B_ProphecyLaneA,
        ALDEBARAN_KEY_A_B_ProphecyLaneB,
        ALDEBARAN_KEY_A_B_ProphecyLaneC,
        ALDEBARAN_KEY_A_B_ProphecyLaneD,
        ALDEBARAN_KEY_A_B_EarthLaneA,
        ALDEBARAN_KEY_A_B_EarthLaneB,
        ALDEBARAN_KEY_A_B_EarthLaneC,
        ALDEBARAN_KEY_A_B_EarthLaneD,
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

void TwistExpander_Aldebaran::KeyDiffuse_A_A_C(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_A_C_AuguryLaneA,
        ALDEBARAN_KEY_A_C_AuguryLaneB,
        ALDEBARAN_KEY_A_C_AuguryLaneC,
        ALDEBARAN_KEY_A_C_AuguryLaneD,
        ALDEBARAN_KEY_A_C_ProphecyLaneA,
        ALDEBARAN_KEY_A_C_ProphecyLaneB,
        ALDEBARAN_KEY_A_C_ProphecyLaneC,
        ALDEBARAN_KEY_A_C_ProphecyLaneD,
        ALDEBARAN_KEY_A_C_EarthLaneA,
        ALDEBARAN_KEY_A_C_EarthLaneB,
        ALDEBARAN_KEY_A_C_EarthLaneC,
        ALDEBARAN_KEY_A_C_EarthLaneD,
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

void TwistExpander_Aldebaran::KeyDiffuse_A_A_D(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_A_D_AuguryLaneA,
        ALDEBARAN_KEY_A_D_AuguryLaneB,
        ALDEBARAN_KEY_A_D_AuguryLaneC,
        ALDEBARAN_KEY_A_D_AuguryLaneD,
        ALDEBARAN_KEY_A_D_ProphecyLaneA,
        ALDEBARAN_KEY_A_D_ProphecyLaneB,
        ALDEBARAN_KEY_A_D_ProphecyLaneC,
        ALDEBARAN_KEY_A_D_ProphecyLaneD,
        ALDEBARAN_KEY_A_D_EarthLaneA,
        ALDEBARAN_KEY_A_D_EarthLaneB,
        ALDEBARAN_KEY_A_D_EarthLaneC,
        ALDEBARAN_KEY_A_D_EarthLaneD,
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

void TwistExpander_Aldebaran::KeyDiffuse_A_A_E(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_A_E_AuguryLaneA,
        ALDEBARAN_KEY_A_E_AuguryLaneB,
        ALDEBARAN_KEY_A_E_AuguryLaneC,
        ALDEBARAN_KEY_A_E_AuguryLaneD,
        ALDEBARAN_KEY_A_E_ProphecyLaneA,
        ALDEBARAN_KEY_A_E_ProphecyLaneB,
        ALDEBARAN_KEY_A_E_ProphecyLaneC,
        ALDEBARAN_KEY_A_E_ProphecyLaneD,
        ALDEBARAN_KEY_A_E_EarthLaneA,
        ALDEBARAN_KEY_A_E_EarthLaneB,
        ALDEBARAN_KEY_A_E_EarthLaneC,
        ALDEBARAN_KEY_A_E_EarthLaneD,
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

void TwistExpander_Aldebaran::KeyDiffuse_A_A_F(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_A_F_AuguryLaneA,
        ALDEBARAN_KEY_A_F_AuguryLaneB,
        ALDEBARAN_KEY_A_F_AuguryLaneC,
        ALDEBARAN_KEY_A_F_AuguryLaneD,
        ALDEBARAN_KEY_A_F_ProphecyLaneA,
        ALDEBARAN_KEY_A_F_ProphecyLaneB,
        ALDEBARAN_KEY_A_F_ProphecyLaneC,
        ALDEBARAN_KEY_A_F_ProphecyLaneD,
        ALDEBARAN_KEY_A_F_EarthLaneA,
        ALDEBARAN_KEY_A_F_EarthLaneB,
        ALDEBARAN_KEY_A_F_EarthLaneC,
        ALDEBARAN_KEY_A_F_EarthLaneD,
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

void TwistExpander_Aldebaran::KeyDiffuse_A_A_G(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_A_G_AuguryLaneA,
        ALDEBARAN_KEY_A_G_AuguryLaneB,
        ALDEBARAN_KEY_A_G_AuguryLaneC,
        ALDEBARAN_KEY_A_G_AuguryLaneD,
        ALDEBARAN_KEY_A_G_ProphecyLaneA,
        ALDEBARAN_KEY_A_G_ProphecyLaneB,
        ALDEBARAN_KEY_A_G_ProphecyLaneC,
        ALDEBARAN_KEY_A_G_ProphecyLaneD,
        ALDEBARAN_KEY_A_G_EarthLaneA,
        ALDEBARAN_KEY_A_G_EarthLaneB,
        ALDEBARAN_KEY_A_G_EarthLaneC,
        ALDEBARAN_KEY_A_G_EarthLaneD,
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

void TwistExpander_Aldebaran::KeyDiffuse_A_A_H(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_A_H_AuguryLaneA,
        ALDEBARAN_KEY_A_H_AuguryLaneB,
        ALDEBARAN_KEY_A_H_AuguryLaneC,
        ALDEBARAN_KEY_A_H_AuguryLaneD,
        ALDEBARAN_KEY_A_H_ProphecyLaneA,
        ALDEBARAN_KEY_A_H_ProphecyLaneB,
        ALDEBARAN_KEY_A_H_ProphecyLaneC,
        ALDEBARAN_KEY_A_H_ProphecyLaneD,
        ALDEBARAN_KEY_A_H_EarthLaneA,
        ALDEBARAN_KEY_A_H_EarthLaneB,
        ALDEBARAN_KEY_A_H_EarthLaneC,
        ALDEBARAN_KEY_A_H_EarthLaneD,
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

void TwistExpander_Aldebaran::KeyDiffuse_A_B_A(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_B_A_AuguryLaneA,
        ALDEBARAN_KEY_B_A_AuguryLaneB,
        ALDEBARAN_KEY_B_A_AuguryLaneC,
        ALDEBARAN_KEY_B_A_AuguryLaneD,
        ALDEBARAN_KEY_B_A_ProphecyLaneA,
        ALDEBARAN_KEY_B_A_ProphecyLaneB,
        ALDEBARAN_KEY_B_A_ProphecyLaneC,
        ALDEBARAN_KEY_B_A_ProphecyLaneD,
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

void TwistExpander_Aldebaran::KeyDiffuse_A_B_B(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_B_B_AuguryLaneA,
        ALDEBARAN_KEY_B_B_AuguryLaneB,
        ALDEBARAN_KEY_B_B_AuguryLaneC,
        ALDEBARAN_KEY_B_B_AuguryLaneD,
        ALDEBARAN_KEY_B_B_ProphecyLaneA,
        ALDEBARAN_KEY_B_B_ProphecyLaneB,
        ALDEBARAN_KEY_B_B_ProphecyLaneC,
        ALDEBARAN_KEY_B_B_ProphecyLaneD,
        ALDEBARAN_KEY_B_B_EarthLaneA,
        ALDEBARAN_KEY_B_B_EarthLaneB,
        ALDEBARAN_KEY_B_B_EarthLaneC,
        ALDEBARAN_KEY_B_B_EarthLaneD,
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

void TwistExpander_Aldebaran::KeyDiffuse_A_B_C(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_B_C_AuguryLaneA,
        ALDEBARAN_KEY_B_C_AuguryLaneB,
        ALDEBARAN_KEY_B_C_AuguryLaneC,
        ALDEBARAN_KEY_B_C_AuguryLaneD,
        ALDEBARAN_KEY_B_C_ProphecyLaneA,
        ALDEBARAN_KEY_B_C_ProphecyLaneB,
        ALDEBARAN_KEY_B_C_ProphecyLaneC,
        ALDEBARAN_KEY_B_C_ProphecyLaneD,
        ALDEBARAN_KEY_B_C_EarthLaneA,
        ALDEBARAN_KEY_B_C_EarthLaneB,
        ALDEBARAN_KEY_B_C_EarthLaneC,
        ALDEBARAN_KEY_B_C_EarthLaneD,
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

void TwistExpander_Aldebaran::KeyDiffuse_A_B_D(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_B_D_AuguryLaneA,
        ALDEBARAN_KEY_B_D_AuguryLaneB,
        ALDEBARAN_KEY_B_D_AuguryLaneC,
        ALDEBARAN_KEY_B_D_AuguryLaneD,
        ALDEBARAN_KEY_B_D_ProphecyLaneA,
        ALDEBARAN_KEY_B_D_ProphecyLaneB,
        ALDEBARAN_KEY_B_D_ProphecyLaneC,
        ALDEBARAN_KEY_B_D_ProphecyLaneD,
        ALDEBARAN_KEY_B_D_EarthLaneA,
        ALDEBARAN_KEY_B_D_EarthLaneB,
        ALDEBARAN_KEY_B_D_EarthLaneC,
        ALDEBARAN_KEY_B_D_EarthLaneD,
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

void TwistExpander_Aldebaran::KeyDiffuse_A_B_E(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_B_E_AuguryLaneA,
        ALDEBARAN_KEY_B_E_AuguryLaneB,
        ALDEBARAN_KEY_B_E_AuguryLaneC,
        ALDEBARAN_KEY_B_E_AuguryLaneD,
        ALDEBARAN_KEY_B_E_ProphecyLaneA,
        ALDEBARAN_KEY_B_E_ProphecyLaneB,
        ALDEBARAN_KEY_B_E_ProphecyLaneC,
        ALDEBARAN_KEY_B_E_ProphecyLaneD,
        ALDEBARAN_KEY_B_E_EarthLaneA,
        ALDEBARAN_KEY_B_E_EarthLaneB,
        ALDEBARAN_KEY_B_E_EarthLaneC,
        ALDEBARAN_KEY_B_E_EarthLaneD,
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

void TwistExpander_Aldebaran::KeyDiffuse_A_B_F(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_B_F_AuguryLaneA,
        ALDEBARAN_KEY_B_F_AuguryLaneB,
        ALDEBARAN_KEY_B_F_AuguryLaneC,
        ALDEBARAN_KEY_B_F_AuguryLaneD,
        ALDEBARAN_KEY_B_F_ProphecyLaneA,
        ALDEBARAN_KEY_B_F_ProphecyLaneB,
        ALDEBARAN_KEY_B_F_ProphecyLaneC,
        ALDEBARAN_KEY_B_F_ProphecyLaneD,
        ALDEBARAN_KEY_B_F_EarthLaneA,
        ALDEBARAN_KEY_B_F_EarthLaneB,
        ALDEBARAN_KEY_B_F_EarthLaneC,
        ALDEBARAN_KEY_B_F_EarthLaneD,
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

void TwistExpander_Aldebaran::KeyDiffuse_A_B_G(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_B_G_AuguryLaneA,
        ALDEBARAN_KEY_B_G_AuguryLaneB,
        ALDEBARAN_KEY_B_G_AuguryLaneC,
        ALDEBARAN_KEY_B_G_AuguryLaneD,
        ALDEBARAN_KEY_B_G_ProphecyLaneA,
        ALDEBARAN_KEY_B_G_ProphecyLaneB,
        ALDEBARAN_KEY_B_G_ProphecyLaneC,
        ALDEBARAN_KEY_B_G_ProphecyLaneD,
        ALDEBARAN_KEY_B_G_EarthLaneA,
        ALDEBARAN_KEY_B_G_EarthLaneB,
        ALDEBARAN_KEY_B_G_EarthLaneC,
        ALDEBARAN_KEY_B_G_EarthLaneD,
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

void TwistExpander_Aldebaran::KeyDiffuse_A_B_H(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_B_H_AuguryLaneA,
        ALDEBARAN_KEY_B_H_AuguryLaneB,
        ALDEBARAN_KEY_B_H_AuguryLaneC,
        ALDEBARAN_KEY_B_H_AuguryLaneD,
        ALDEBARAN_KEY_B_H_ProphecyLaneA,
        ALDEBARAN_KEY_B_H_ProphecyLaneB,
        ALDEBARAN_KEY_B_H_ProphecyLaneC,
        ALDEBARAN_KEY_B_H_ProphecyLaneD,
        ALDEBARAN_KEY_B_H_EarthLaneA,
        ALDEBARAN_KEY_B_H_EarthLaneB,
        ALDEBARAN_KEY_B_H_EarthLaneC,
        ALDEBARAN_KEY_B_H_EarthLaneD,
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

void TwistExpander_Aldebaran::KeyDiffuse_B_A_A(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_A_A_RestorationLaneA,
        ALDEBARAN_KEY_A_A_RestorationLaneB,
        ALDEBARAN_KEY_A_A_RestorationLaneC,
        ALDEBARAN_KEY_A_A_RestorationLaneD,
        ALDEBARAN_KEY_A_A_CelestialLaneA,
        ALDEBARAN_KEY_A_A_CelestialLaneB,
        ALDEBARAN_KEY_A_A_CelestialLaneC,
        ALDEBARAN_KEY_A_A_CelestialLaneD,
        ALDEBARAN_KEY_A_A_TransmutationLaneA,
        ALDEBARAN_KEY_A_A_TransmutationLaneB,
        ALDEBARAN_KEY_A_A_TransmutationLaneC,
        ALDEBARAN_KEY_A_A_TransmutationLaneD,
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

void TwistExpander_Aldebaran::KeyDiffuse_B_A_B(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_A_B_RestorationLaneA,
        ALDEBARAN_KEY_A_B_RestorationLaneB,
        ALDEBARAN_KEY_A_B_RestorationLaneC,
        ALDEBARAN_KEY_A_B_RestorationLaneD,
        ALDEBARAN_KEY_A_B_CelestialLaneA,
        ALDEBARAN_KEY_A_B_CelestialLaneB,
        ALDEBARAN_KEY_A_B_CelestialLaneC,
        ALDEBARAN_KEY_A_B_CelestialLaneD,
        ALDEBARAN_KEY_A_B_TransmutationLaneA,
        ALDEBARAN_KEY_A_B_TransmutationLaneB,
        ALDEBARAN_KEY_A_B_TransmutationLaneC,
        ALDEBARAN_KEY_A_B_TransmutationLaneD,
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

void TwistExpander_Aldebaran::KeyDiffuse_B_A_C(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_A_C_RestorationLaneA,
        ALDEBARAN_KEY_A_C_RestorationLaneB,
        ALDEBARAN_KEY_A_C_RestorationLaneC,
        ALDEBARAN_KEY_A_C_RestorationLaneD,
        ALDEBARAN_KEY_A_C_CelestialLaneA,
        ALDEBARAN_KEY_A_C_CelestialLaneB,
        ALDEBARAN_KEY_A_C_CelestialLaneC,
        ALDEBARAN_KEY_A_C_CelestialLaneD,
        ALDEBARAN_KEY_A_C_TransmutationLaneA,
        ALDEBARAN_KEY_A_C_TransmutationLaneB,
        ALDEBARAN_KEY_A_C_TransmutationLaneC,
        ALDEBARAN_KEY_A_C_TransmutationLaneD,
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

void TwistExpander_Aldebaran::KeyDiffuse_B_A_D(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_A_D_RestorationLaneA,
        ALDEBARAN_KEY_A_D_RestorationLaneB,
        ALDEBARAN_KEY_A_D_RestorationLaneC,
        ALDEBARAN_KEY_A_D_RestorationLaneD,
        ALDEBARAN_KEY_A_D_CelestialLaneA,
        ALDEBARAN_KEY_A_D_CelestialLaneB,
        ALDEBARAN_KEY_A_D_CelestialLaneC,
        ALDEBARAN_KEY_A_D_CelestialLaneD,
        ALDEBARAN_KEY_A_D_TransmutationLaneA,
        ALDEBARAN_KEY_A_D_TransmutationLaneB,
        ALDEBARAN_KEY_A_D_TransmutationLaneC,
        ALDEBARAN_KEY_A_D_TransmutationLaneD,
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

void TwistExpander_Aldebaran::KeyDiffuse_B_A_E(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_A_E_RestorationLaneA,
        ALDEBARAN_KEY_A_E_RestorationLaneB,
        ALDEBARAN_KEY_A_E_RestorationLaneC,
        ALDEBARAN_KEY_A_E_RestorationLaneD,
        ALDEBARAN_KEY_A_E_CelestialLaneA,
        ALDEBARAN_KEY_A_E_CelestialLaneB,
        ALDEBARAN_KEY_A_E_CelestialLaneC,
        ALDEBARAN_KEY_A_E_CelestialLaneD,
        ALDEBARAN_KEY_A_E_TransmutationLaneA,
        ALDEBARAN_KEY_A_E_TransmutationLaneB,
        ALDEBARAN_KEY_A_E_TransmutationLaneC,
        ALDEBARAN_KEY_A_E_TransmutationLaneD,
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

void TwistExpander_Aldebaran::KeyDiffuse_B_A_F(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_A_F_RestorationLaneA,
        ALDEBARAN_KEY_A_F_RestorationLaneB,
        ALDEBARAN_KEY_A_F_RestorationLaneC,
        ALDEBARAN_KEY_A_F_RestorationLaneD,
        ALDEBARAN_KEY_A_F_CelestialLaneA,
        ALDEBARAN_KEY_A_F_CelestialLaneB,
        ALDEBARAN_KEY_A_F_CelestialLaneC,
        ALDEBARAN_KEY_A_F_CelestialLaneD,
        ALDEBARAN_KEY_A_F_TransmutationLaneA,
        ALDEBARAN_KEY_A_F_TransmutationLaneB,
        ALDEBARAN_KEY_A_F_TransmutationLaneC,
        ALDEBARAN_KEY_A_F_TransmutationLaneD,
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

void TwistExpander_Aldebaran::KeyDiffuse_B_A_G(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_A_G_RestorationLaneA,
        ALDEBARAN_KEY_A_G_RestorationLaneB,
        ALDEBARAN_KEY_A_G_RestorationLaneC,
        ALDEBARAN_KEY_A_G_RestorationLaneD,
        ALDEBARAN_KEY_A_G_CelestialLaneA,
        ALDEBARAN_KEY_A_G_CelestialLaneB,
        ALDEBARAN_KEY_A_G_CelestialLaneC,
        ALDEBARAN_KEY_A_G_CelestialLaneD,
        ALDEBARAN_KEY_A_G_TransmutationLaneA,
        ALDEBARAN_KEY_A_G_TransmutationLaneB,
        ALDEBARAN_KEY_A_G_TransmutationLaneC,
        ALDEBARAN_KEY_A_G_TransmutationLaneD,
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

void TwistExpander_Aldebaran::KeyDiffuse_B_A_H(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_A_H_RestorationLaneA,
        ALDEBARAN_KEY_A_H_RestorationLaneB,
        ALDEBARAN_KEY_A_H_RestorationLaneC,
        ALDEBARAN_KEY_A_H_RestorationLaneD,
        ALDEBARAN_KEY_A_H_CelestialLaneA,
        ALDEBARAN_KEY_A_H_CelestialLaneB,
        ALDEBARAN_KEY_A_H_CelestialLaneC,
        ALDEBARAN_KEY_A_H_CelestialLaneD,
        ALDEBARAN_KEY_A_H_TransmutationLaneA,
        ALDEBARAN_KEY_A_H_TransmutationLaneB,
        ALDEBARAN_KEY_A_H_TransmutationLaneC,
        ALDEBARAN_KEY_A_H_TransmutationLaneD,
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

void TwistExpander_Aldebaran::KeyDiffuse_B_B_A(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_B_A_RestorationLaneA,
        ALDEBARAN_KEY_B_A_RestorationLaneB,
        ALDEBARAN_KEY_B_A_RestorationLaneC,
        ALDEBARAN_KEY_B_A_RestorationLaneD,
        ALDEBARAN_KEY_B_A_CelestialLaneA,
        ALDEBARAN_KEY_B_A_CelestialLaneB,
        ALDEBARAN_KEY_B_A_CelestialLaneC,
        ALDEBARAN_KEY_B_A_CelestialLaneD,
        ALDEBARAN_KEY_B_A_TransmutationLaneA,
        ALDEBARAN_KEY_B_A_TransmutationLaneB,
        ALDEBARAN_KEY_B_A_TransmutationLaneC,
        ALDEBARAN_KEY_B_A_TransmutationLaneD,
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

void TwistExpander_Aldebaran::KeyDiffuse_B_B_B(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_B_B_RestorationLaneA,
        ALDEBARAN_KEY_B_B_RestorationLaneB,
        ALDEBARAN_KEY_B_B_RestorationLaneC,
        ALDEBARAN_KEY_B_B_RestorationLaneD,
        ALDEBARAN_KEY_B_B_CelestialLaneA,
        ALDEBARAN_KEY_B_B_CelestialLaneB,
        ALDEBARAN_KEY_B_B_CelestialLaneC,
        ALDEBARAN_KEY_B_B_CelestialLaneD,
        ALDEBARAN_KEY_B_B_TransmutationLaneA,
        ALDEBARAN_KEY_B_B_TransmutationLaneB,
        ALDEBARAN_KEY_B_B_TransmutationLaneC,
        ALDEBARAN_KEY_B_B_TransmutationLaneD,
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

void TwistExpander_Aldebaran::KeyDiffuse_B_B_C(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_B_C_RestorationLaneA,
        ALDEBARAN_KEY_B_C_RestorationLaneB,
        ALDEBARAN_KEY_B_C_RestorationLaneC,
        ALDEBARAN_KEY_B_C_RestorationLaneD,
        ALDEBARAN_KEY_B_C_CelestialLaneA,
        ALDEBARAN_KEY_B_C_CelestialLaneB,
        ALDEBARAN_KEY_B_C_CelestialLaneC,
        ALDEBARAN_KEY_B_C_CelestialLaneD,
        ALDEBARAN_KEY_B_C_TransmutationLaneA,
        ALDEBARAN_KEY_B_C_TransmutationLaneB,
        ALDEBARAN_KEY_B_C_TransmutationLaneC,
        ALDEBARAN_KEY_B_C_TransmutationLaneD,
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

void TwistExpander_Aldebaran::KeyDiffuse_B_B_D(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_B_D_RestorationLaneA,
        ALDEBARAN_KEY_B_D_RestorationLaneB,
        ALDEBARAN_KEY_B_D_RestorationLaneC,
        ALDEBARAN_KEY_B_D_RestorationLaneD,
        ALDEBARAN_KEY_B_D_CelestialLaneA,
        ALDEBARAN_KEY_B_D_CelestialLaneB,
        ALDEBARAN_KEY_B_D_CelestialLaneC,
        ALDEBARAN_KEY_B_D_CelestialLaneD,
        ALDEBARAN_KEY_B_D_TransmutationLaneA,
        ALDEBARAN_KEY_B_D_TransmutationLaneB,
        ALDEBARAN_KEY_B_D_TransmutationLaneC,
        ALDEBARAN_KEY_B_D_TransmutationLaneD,
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

void TwistExpander_Aldebaran::KeyDiffuse_B_B_E(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_B_E_RestorationLaneA,
        ALDEBARAN_KEY_B_E_RestorationLaneB,
        ALDEBARAN_KEY_B_E_RestorationLaneC,
        ALDEBARAN_KEY_B_E_RestorationLaneD,
        ALDEBARAN_KEY_B_E_CelestialLaneA,
        ALDEBARAN_KEY_B_E_CelestialLaneB,
        ALDEBARAN_KEY_B_E_CelestialLaneC,
        ALDEBARAN_KEY_B_E_CelestialLaneD,
        ALDEBARAN_KEY_B_E_TransmutationLaneA,
        ALDEBARAN_KEY_B_E_TransmutationLaneB,
        ALDEBARAN_KEY_B_E_TransmutationLaneC,
        ALDEBARAN_KEY_B_E_TransmutationLaneD,
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

void TwistExpander_Aldebaran::KeyDiffuse_B_B_F(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_B_F_RestorationLaneA,
        ALDEBARAN_KEY_B_F_RestorationLaneB,
        ALDEBARAN_KEY_B_F_RestorationLaneC,
        ALDEBARAN_KEY_B_F_RestorationLaneD,
        ALDEBARAN_KEY_B_F_CelestialLaneA,
        ALDEBARAN_KEY_B_F_CelestialLaneB,
        ALDEBARAN_KEY_B_F_CelestialLaneC,
        ALDEBARAN_KEY_B_F_CelestialLaneD,
        ALDEBARAN_KEY_B_F_TransmutationLaneA,
        ALDEBARAN_KEY_B_F_TransmutationLaneB,
        ALDEBARAN_KEY_B_F_TransmutationLaneC,
        ALDEBARAN_KEY_B_F_TransmutationLaneD,
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

void TwistExpander_Aldebaran::KeyDiffuse_B_B_G(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_B_G_RestorationLaneA,
        ALDEBARAN_KEY_B_G_RestorationLaneB,
        ALDEBARAN_KEY_B_G_RestorationLaneC,
        ALDEBARAN_KEY_B_G_RestorationLaneD,
        ALDEBARAN_KEY_B_G_CelestialLaneA,
        ALDEBARAN_KEY_B_G_CelestialLaneB,
        ALDEBARAN_KEY_B_G_CelestialLaneC,
        ALDEBARAN_KEY_B_G_CelestialLaneD,
        ALDEBARAN_KEY_B_G_TransmutationLaneA,
        ALDEBARAN_KEY_B_G_TransmutationLaneB,
        ALDEBARAN_KEY_B_G_TransmutationLaneC,
        ALDEBARAN_KEY_B_G_TransmutationLaneD,
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

void TwistExpander_Aldebaran::KeyDiffuse_B_B_H(TwistWorkSpace *pWorkSpace) {
    TwistDiffuse::KeyDiffuseWithDomainWords(
        ALDEBARAN_KEY_B_H_RestorationLaneA,
        ALDEBARAN_KEY_B_H_RestorationLaneB,
        ALDEBARAN_KEY_B_H_RestorationLaneC,
        ALDEBARAN_KEY_B_H_RestorationLaneD,
        ALDEBARAN_KEY_B_H_CelestialLaneA,
        ALDEBARAN_KEY_B_H_CelestialLaneB,
        ALDEBARAN_KEY_B_H_CelestialLaneC,
        ALDEBARAN_KEY_B_H_CelestialLaneD,
        ALDEBARAN_KEY_B_H_TransmutationLaneA,
        ALDEBARAN_KEY_B_H_TransmutationLaneB,
        ALDEBARAN_KEY_B_H_TransmutationLaneC,
        ALDEBARAN_KEY_B_H_TransmutationLaneD,
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
