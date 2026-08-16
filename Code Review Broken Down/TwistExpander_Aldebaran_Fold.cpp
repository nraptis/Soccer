
void TwistExpander_Aldebaran::TwistForkKeyHalfA(TwistWorkSpace *pWorkSpace) {
    static_assert(S_BLOCK == 32768, "Twist fork source size changed.");
    static_assert(S_BLOCK / 64U == 512U, "Twist fork block size changed.");
    static_assert(W_KEY == 2048, "Twist fork key size changed.");

    std::uint8_t *aEarthLaneA = pWorkSpace->mEarthLaneA;
    std::uint8_t *aEarthLaneB = pWorkSpace->mEarthLaneB;
    std::uint8_t *aEarthLaneC = pWorkSpace->mEarthLaneC;
    std::uint8_t *aEarthLaneD = pWorkSpace->mEarthLaneD;
    std::uint8_t *aCrystalLaneA = pWorkSpace->mCrystalLaneA;
    std::uint8_t *aCrystalLaneB = pWorkSpace->mCrystalLaneB;
    std::uint8_t *aCrystalLaneC = pWorkSpace->mCrystalLaneC;
    std::uint8_t *aCrystalLaneD = pWorkSpace->mCrystalLaneD;

    std::uint8_t *aMuLaneA = pWorkSpace->mCelestialLaneA;
    std::uint8_t *aLelLaneA = pWorkSpace->mAlchemyLaneA;
    std::uint8_t *aGozLaneA = pWorkSpace->mAuguryLaneA;
    std::uint8_t *aMuLaneB = pWorkSpace->mCelestialLaneB;
    std::uint8_t *aLelLaneB = pWorkSpace->mAlchemyLaneB;
    std::uint8_t *aGozLaneB = pWorkSpace->mAuguryLaneB;
    std::uint8_t *aMuLaneC = pWorkSpace->mCelestialLaneC;
    std::uint8_t *aLelLaneC = pWorkSpace->mAlchemyLaneC;
    std::uint8_t *aGozLaneC = pWorkSpace->mAuguryLaneC;
    std::uint8_t *aMuLaneD = pWorkSpace->mCelestialLaneD;
    std::uint8_t *aLelLaneD = pWorkSpace->mAlchemyLaneD;
    std::uint8_t *aGozLaneD = pWorkSpace->mAuguryLaneD;

    std::uint8_t *aFinalLaneA = pWorkSpace->mSpiritLaneA;
    std::uint8_t *aFinalLaneB = pWorkSpace->mSpiritLaneB;
    std::uint8_t *aFinalLaneC = pWorkSpace->mSpiritLaneC;
    std::uint8_t *aFinalLaneD = pWorkSpace->mSpiritLaneD;

    // Grow input A — balanced 512-byte fold graph.

    // Mu — eight 512-byte blocks per lane.

    // Mu A[0]: aCrystalLaneA[21] + aCrystalLaneC[51].
    KEY_FOLD_BLOCK(aCrystalLaneA, 21U, aCrystalLaneC, 51U, aMuLaneA, 0U);

    // Mu A[1]: aCrystalLaneA[5] + aEarthLaneA[19].
    KEY_FOLD_BLOCK(aCrystalLaneA, 5U, aEarthLaneA, 19U, aMuLaneA, 1U);

    // Mu A[2]: aCrystalLaneC[59] + aCrystalLaneB[12].
    KEY_FOLD_BLOCK(aCrystalLaneC, 59U, aCrystalLaneB, 12U, aMuLaneA, 2U);

    // Mu A[3]: aEarthLaneA[27] + aCrystalLaneB[8].
    KEY_FOLD_BLOCK(aEarthLaneA, 27U, aCrystalLaneB, 8U, aMuLaneA, 3U);

    // Mu A[4]: aEarthLaneD[36] + aCrystalLaneD[30].
    KEY_FOLD_BLOCK(aEarthLaneD, 36U, aCrystalLaneD, 30U, aMuLaneA, 4U);

    // Mu A[5]: aEarthLaneB[32] + aEarthLaneC[29].
    KEY_FOLD_BLOCK(aEarthLaneB, 32U, aEarthLaneC, 29U, aMuLaneA, 5U);

    // Mu A[6]: aCrystalLaneD[28] + aEarthLaneD[32].
    KEY_FOLD_BLOCK(aCrystalLaneD, 28U, aEarthLaneD, 32U, aMuLaneA, 6U);

    // Mu A[7]: aEarthLaneB[52] + aEarthLaneC[23].
    KEY_FOLD_BLOCK(aEarthLaneB, 52U, aEarthLaneC, 23U, aMuLaneA, 7U);

    // Mu B[0]: aEarthLaneA[1] + aEarthLaneB[50].
    KEY_FOLD_BLOCK(aEarthLaneA, 1U, aEarthLaneB, 50U, aMuLaneB, 0U);

    // Mu B[1]: aCrystalLaneC[25] + aEarthLaneA[63].
    KEY_FOLD_BLOCK(aCrystalLaneC, 25U, aEarthLaneA, 63U, aMuLaneB, 1U);

    // Mu B[2]: aCrystalLaneC[31] + aEarthLaneC[9].
    KEY_FOLD_BLOCK(aCrystalLaneC, 31U, aEarthLaneC, 9U, aMuLaneB, 2U);

    // Mu B[3]: aEarthLaneD[8] + aCrystalLaneB[2].
    KEY_FOLD_BLOCK(aEarthLaneD, 8U, aCrystalLaneB, 2U, aMuLaneB, 3U);

    // Mu B[4]: aCrystalLaneD[62] + aEarthLaneD[14].
    KEY_FOLD_BLOCK(aCrystalLaneD, 62U, aEarthLaneD, 14U, aMuLaneB, 4U);

    // Mu B[5]: aEarthLaneB[12] + aEarthLaneC[51].
    KEY_FOLD_BLOCK(aEarthLaneB, 12U, aEarthLaneC, 51U, aMuLaneB, 5U);

    // Mu B[6]: aCrystalLaneD[0] + aCrystalLaneA[27].
    KEY_FOLD_BLOCK(aCrystalLaneD, 0U, aCrystalLaneA, 27U, aMuLaneB, 6U);

    // Mu B[7]: aCrystalLaneB[34] + aCrystalLaneA[63].
    KEY_FOLD_BLOCK(aCrystalLaneB, 34U, aCrystalLaneA, 63U, aMuLaneB, 7U);

    // Mu C[0]: aCrystalLaneB[40] + aEarthLaneD[42].
    KEY_FOLD_BLOCK(aCrystalLaneB, 40U, aEarthLaneD, 42U, aMuLaneC, 0U);

    // Mu C[1]: aCrystalLaneB[32] + aCrystalLaneC[61].
    KEY_FOLD_BLOCK(aCrystalLaneB, 32U, aCrystalLaneC, 61U, aMuLaneC, 1U);

    // Mu C[2]: aCrystalLaneA[39] + aEarthLaneC[39].
    KEY_FOLD_BLOCK(aCrystalLaneA, 39U, aEarthLaneC, 39U, aMuLaneC, 2U);

    // Mu C[3]: aEarthLaneA[43] + aEarthLaneB[28].
    KEY_FOLD_BLOCK(aEarthLaneA, 43U, aEarthLaneB, 28U, aMuLaneC, 3U);

    // Mu C[4]: aEarthLaneC[19] + aCrystalLaneA[47].
    KEY_FOLD_BLOCK(aEarthLaneC, 19U, aCrystalLaneA, 47U, aMuLaneC, 4U);

    // Mu C[5]: aCrystalLaneC[49] + aCrystalLaneD[36].
    KEY_FOLD_BLOCK(aCrystalLaneC, 49U, aCrystalLaneD, 36U, aMuLaneC, 5U);

    // Mu C[6]: aEarthLaneD[44] + aCrystalLaneD[10].
    KEY_FOLD_BLOCK(aEarthLaneD, 44U, aCrystalLaneD, 10U, aMuLaneC, 6U);

    // Mu C[7]: aEarthLaneA[39] + aEarthLaneB[22].
    KEY_FOLD_BLOCK(aEarthLaneA, 39U, aEarthLaneB, 22U, aMuLaneC, 7U);

    // Mu D[0]: aEarthLaneB[60] + aEarthLaneC[57].
    KEY_FOLD_BLOCK(aEarthLaneB, 60U, aEarthLaneC, 57U, aMuLaneD, 0U);

    // Mu D[1]: aCrystalLaneC[19] + aEarthLaneA[9].
    KEY_FOLD_BLOCK(aCrystalLaneC, 19U, aEarthLaneA, 9U, aMuLaneD, 1U);

    // Mu D[2]: aEarthLaneD[4] + aCrystalLaneD[56].
    KEY_FOLD_BLOCK(aEarthLaneD, 4U, aCrystalLaneD, 56U, aMuLaneD, 2U);

    // Mu D[3]: aCrystalLaneB[44] + aCrystalLaneA[7].
    KEY_FOLD_BLOCK(aCrystalLaneB, 44U, aCrystalLaneA, 7U, aMuLaneD, 3U);

    // Mu D[4]: aCrystalLaneC[23] + aEarthLaneA[61].
    KEY_FOLD_BLOCK(aCrystalLaneC, 23U, aEarthLaneA, 61U, aMuLaneD, 4U);

    // Mu D[5]: aCrystalLaneB[10] + aEarthLaneB[24].
    KEY_FOLD_BLOCK(aCrystalLaneB, 10U, aEarthLaneB, 24U, aMuLaneD, 5U);

    // Mu D[6]: aEarthLaneC[59] + aCrystalLaneD[32].
    KEY_FOLD_BLOCK(aEarthLaneC, 59U, aCrystalLaneD, 32U, aMuLaneD, 6U);

    // Mu D[7]: aCrystalLaneA[59] + aEarthLaneD[10].
    KEY_FOLD_BLOCK(aCrystalLaneA, 59U, aEarthLaneD, 10U, aMuLaneD, 7U);

    // Lel — four 512-byte blocks per lane.

    // Lel A[0]: aMuLaneD[7] + aMuLaneC[5].
    KEY_FOLD_BLOCK(aMuLaneD, 7U, aMuLaneC, 5U, aLelLaneA, 0U);

    // Lel A[1]: aMuLaneA[2] + aMuLaneB[0].
    KEY_FOLD_BLOCK(aMuLaneA, 2U, aMuLaneB, 0U, aLelLaneA, 1U);

    // Lel A[2]: aMuLaneA[7] + aMuLaneD[1].
    KEY_FOLD_BLOCK(aMuLaneA, 7U, aMuLaneD, 1U, aLelLaneA, 2U);

    // Lel A[3]: aMuLaneB[6] + aMuLaneC[0].
    KEY_FOLD_BLOCK(aMuLaneB, 6U, aMuLaneC, 0U, aLelLaneA, 3U);

    // Lel B[0]: aMuLaneA[5] + aMuLaneD[4].
    KEY_FOLD_BLOCK(aMuLaneA, 5U, aMuLaneD, 4U, aLelLaneB, 0U);

    // Lel B[1]: aMuLaneC[2] + aMuLaneD[2].
    KEY_FOLD_BLOCK(aMuLaneC, 2U, aMuLaneD, 2U, aLelLaneB, 1U);

    // Lel B[2]: aMuLaneA[0] + aMuLaneB[3].
    KEY_FOLD_BLOCK(aMuLaneA, 0U, aMuLaneB, 3U, aLelLaneB, 2U);

    // Lel B[3]: aMuLaneC[7] + aMuLaneB[2].
    KEY_FOLD_BLOCK(aMuLaneC, 7U, aMuLaneB, 2U, aLelLaneB, 3U);

    // Lel C[0]: aMuLaneB[1] + aMuLaneC[4].
    KEY_FOLD_BLOCK(aMuLaneB, 1U, aMuLaneC, 4U, aLelLaneC, 0U);

    // Lel C[1]: aMuLaneD[3] + aMuLaneA[6].
    KEY_FOLD_BLOCK(aMuLaneD, 3U, aMuLaneA, 6U, aLelLaneC, 1U);

    // Lel C[2]: aMuLaneA[3] + aMuLaneB[5].
    KEY_FOLD_BLOCK(aMuLaneA, 3U, aMuLaneB, 5U, aLelLaneC, 2U);

    // Lel C[3]: aMuLaneC[1] + aMuLaneD[0].
    KEY_FOLD_BLOCK(aMuLaneC, 1U, aMuLaneD, 0U, aLelLaneC, 3U);

    // Lel D[0]: aMuLaneA[4] + aMuLaneD[5].
    KEY_FOLD_BLOCK(aMuLaneA, 4U, aMuLaneD, 5U, aLelLaneD, 0U);

    // Lel D[1]: aMuLaneB[4] + aMuLaneA[1].
    KEY_FOLD_BLOCK(aMuLaneB, 4U, aMuLaneA, 1U, aLelLaneD, 1U);

    // Lel D[2]: aMuLaneD[6] + aMuLaneC[3].
    KEY_FOLD_BLOCK(aMuLaneD, 6U, aMuLaneC, 3U, aLelLaneD, 2U);

    // Lel D[3]: aMuLaneC[6] + aMuLaneB[7].
    KEY_FOLD_BLOCK(aMuLaneC, 6U, aMuLaneB, 7U, aLelLaneD, 3U);

    // Goz — two 512-byte blocks per lane.

    // Goz A[0]: aLelLaneA[0] + aLelLaneC[2].
    KEY_FOLD_BLOCK(aLelLaneA, 0U, aLelLaneC, 2U, aGozLaneA, 0U);

    // Goz A[1]: aLelLaneB[2] + aLelLaneD[2].
    KEY_FOLD_BLOCK(aLelLaneB, 2U, aLelLaneD, 2U, aGozLaneA, 1U);

    // Goz B[0]: aLelLaneA[3] + aLelLaneB[0].
    KEY_FOLD_BLOCK(aLelLaneA, 3U, aLelLaneB, 0U, aGozLaneB, 0U);

    // Goz B[1]: aLelLaneD[0] + aLelLaneC[0].
    KEY_FOLD_BLOCK(aLelLaneD, 0U, aLelLaneC, 0U, aGozLaneB, 1U);

    // Goz C[0]: aLelLaneC[1] + aLelLaneB[3].
    KEY_FOLD_BLOCK(aLelLaneC, 1U, aLelLaneB, 3U, aGozLaneC, 0U);

    // Goz C[1]: aLelLaneD[3] + aLelLaneA[2].
    KEY_FOLD_BLOCK(aLelLaneD, 3U, aLelLaneA, 2U, aGozLaneC, 1U);

    // Goz D[0]: aLelLaneA[1] + aLelLaneB[1].
    KEY_FOLD_BLOCK(aLelLaneA, 1U, aLelLaneB, 1U, aGozLaneD, 0U);

    // Goz D[1]: aLelLaneC[3] + aLelLaneD[1].
    KEY_FOLD_BLOCK(aLelLaneC, 3U, aLelLaneD, 1U, aGozLaneD, 1U);

    // Key source memberships.
    // Block 0: Earth={A:2, B:2, C:2, D:2} Crystal={A:2, B:2, C:2, D:2}.
    // Quarters: Earth={A:1/3, B:0/2, C:3/1, D:0/2} Crystal={A:3/1, B:0/2, C:3/1, D:2/0}.
    // Block 1: Earth={A:2, B:2, C:2, D:2} Crystal={A:2, B:2, C:2, D:2}.
    // Quarters: Earth={A:2/0, B:1/3, C:0/2, D:2/0} Crystal={A:0/2, B:2/0, C:1/3, D:1/3}.
    // Block 2: Earth={A:2, B:2, C:2, D:2} Crystal={A:2, B:2, C:2, D:2}.
    // Quarters: Earth={A:2/0, B:1/3, C:3/1, D:0/2} Crystal={A:1/3, B:0/2, C:3/1, D:2/0}.
    // Block 3: Earth={A:2, B:2, C:2, D:2} Crystal={A:2, B:2, C:2, D:2}.
    // Quarters: Earth={A:3/1, B:1/3, C:1/3, D:2/0} Crystal={A:2/0, B:0/2, C:1/3, D:1/3}.

    // Key — fixed two-input Goz fold.

    KEY_FOLD_BLOCK(aGozLaneA, 0U, aGozLaneB, 0U, aFinalLaneA, 0U);

    KEY_FOLD_BLOCK(aGozLaneC, 0U, aGozLaneD, 0U, aFinalLaneA, 1U);

    KEY_FOLD_BLOCK(aGozLaneA, 1U, aGozLaneC, 1U, aFinalLaneA, 2U);

    KEY_FOLD_BLOCK(aGozLaneB, 1U, aGozLaneD, 1U, aFinalLaneA, 3U);


    // Grow input B — balanced 512-byte fold graph.

    // Mu — eight 512-byte blocks per lane.

    // Mu A[0]: aCrystalLaneC[35] + aEarthLaneD[26].
    KEY_FOLD_BLOCK(aCrystalLaneC, 35U, aEarthLaneD, 26U, aMuLaneA, 0U);

    // Mu A[1]: aCrystalLaneD[20] + aEarthLaneC[21].
    KEY_FOLD_BLOCK(aCrystalLaneD, 20U, aEarthLaneC, 21U, aMuLaneA, 1U);

    // Mu A[2]: aCrystalLaneA[13] + aCrystalLaneC[1].
    KEY_FOLD_BLOCK(aCrystalLaneA, 13U, aCrystalLaneC, 1U, aMuLaneA, 2U);

    // Mu A[3]: aCrystalLaneB[26] + aCrystalLaneA[41].
    KEY_FOLD_BLOCK(aCrystalLaneB, 26U, aCrystalLaneA, 41U, aMuLaneA, 3U);

    // Mu A[4]: aCrystalLaneD[50] + aEarthLaneC[5].
    KEY_FOLD_BLOCK(aCrystalLaneD, 50U, aEarthLaneC, 5U, aMuLaneA, 4U);

    // Mu A[5]: aCrystalLaneB[0] + aEarthLaneD[46].
    KEY_FOLD_BLOCK(aCrystalLaneB, 0U, aEarthLaneD, 46U, aMuLaneA, 5U);

    // Mu A[6]: aEarthLaneA[33] + aEarthLaneB[26].
    KEY_FOLD_BLOCK(aEarthLaneA, 33U, aEarthLaneB, 26U, aMuLaneA, 6U);

    // Mu A[7]: aEarthLaneB[10] + aEarthLaneA[5].
    KEY_FOLD_BLOCK(aEarthLaneB, 10U, aEarthLaneA, 5U, aMuLaneA, 7U);

    // Mu B[0]: aEarthLaneC[61] + aCrystalLaneA[1].
    KEY_FOLD_BLOCK(aEarthLaneC, 61U, aCrystalLaneA, 1U, aMuLaneB, 0U);

    // Mu B[1]: aCrystalLaneB[48] + aCrystalLaneD[14].
    KEY_FOLD_BLOCK(aCrystalLaneB, 48U, aCrystalLaneD, 14U, aMuLaneB, 1U);

    // Mu B[2]: aCrystalLaneC[13] + aCrystalLaneA[37].
    KEY_FOLD_BLOCK(aCrystalLaneC, 13U, aCrystalLaneA, 37U, aMuLaneB, 2U);

    // Mu B[3]: aEarthLaneB[30] + aCrystalLaneB[36].
    KEY_FOLD_BLOCK(aEarthLaneB, 30U, aCrystalLaneB, 36U, aMuLaneB, 3U);

    // Mu B[4]: aEarthLaneB[40] + aEarthLaneD[16].
    KEY_FOLD_BLOCK(aEarthLaneB, 40U, aEarthLaneD, 16U, aMuLaneB, 4U);

    // Mu B[5]: aCrystalLaneC[37] + aEarthLaneA[25].
    KEY_FOLD_BLOCK(aCrystalLaneC, 37U, aEarthLaneA, 25U, aMuLaneB, 5U);

    // Mu B[6]: aEarthLaneA[55] + aEarthLaneD[18].
    KEY_FOLD_BLOCK(aEarthLaneA, 55U, aEarthLaneD, 18U, aMuLaneB, 6U);

    // Mu B[7]: aCrystalLaneD[18] + aEarthLaneC[35].
    KEY_FOLD_BLOCK(aCrystalLaneD, 18U, aEarthLaneC, 35U, aMuLaneB, 7U);

    // Mu C[0]: aEarthLaneD[52] + aEarthLaneC[55].
    KEY_FOLD_BLOCK(aEarthLaneD, 52U, aEarthLaneC, 55U, aMuLaneC, 0U);

    // Mu C[1]: aEarthLaneB[54] + aEarthLaneA[29].
    KEY_FOLD_BLOCK(aEarthLaneB, 54U, aEarthLaneA, 29U, aMuLaneC, 1U);

    // Mu C[2]: aCrystalLaneC[5] + aCrystalLaneA[23].
    KEY_FOLD_BLOCK(aCrystalLaneC, 5U, aCrystalLaneA, 23U, aMuLaneC, 2U);

    // Mu C[3]: aCrystalLaneA[35] + aCrystalLaneB[22].
    KEY_FOLD_BLOCK(aCrystalLaneA, 35U, aCrystalLaneB, 22U, aMuLaneC, 3U);

    // Mu C[4]: aEarthLaneB[56] + aEarthLaneA[13].
    KEY_FOLD_BLOCK(aEarthLaneB, 56U, aEarthLaneA, 13U, aMuLaneC, 4U);

    // Mu C[5]: aCrystalLaneC[55] + aCrystalLaneD[58].
    KEY_FOLD_BLOCK(aCrystalLaneC, 55U, aCrystalLaneD, 58U, aMuLaneC, 5U);

    // Mu C[6]: aCrystalLaneD[38] + aEarthLaneD[54].
    KEY_FOLD_BLOCK(aCrystalLaneD, 38U, aEarthLaneD, 54U, aMuLaneC, 6U);

    // Mu C[7]: aEarthLaneC[27] + aCrystalLaneB[50].
    KEY_FOLD_BLOCK(aEarthLaneC, 27U, aCrystalLaneB, 50U, aMuLaneC, 7U);

    // Mu D[0]: aCrystalLaneC[45] + aCrystalLaneA[61].
    KEY_FOLD_BLOCK(aCrystalLaneC, 45U, aCrystalLaneA, 61U, aMuLaneD, 0U);

    // Mu D[1]: aEarthLaneA[35] + aCrystalLaneC[29].
    KEY_FOLD_BLOCK(aEarthLaneA, 35U, aCrystalLaneC, 29U, aMuLaneD, 1U);

    // Mu D[2]: aCrystalLaneD[16] + aEarthLaneB[20].
    KEY_FOLD_BLOCK(aCrystalLaneD, 16U, aEarthLaneB, 20U, aMuLaneD, 2U);

    // Mu D[3]: aEarthLaneD[6] + aEarthLaneA[49].
    KEY_FOLD_BLOCK(aEarthLaneD, 6U, aEarthLaneA, 49U, aMuLaneD, 3U);

    // Mu D[4]: aEarthLaneC[15] + aCrystalLaneA[3].
    KEY_FOLD_BLOCK(aEarthLaneC, 15U, aCrystalLaneA, 3U, aMuLaneD, 4U);

    // Mu D[5]: aCrystalLaneB[28] + aEarthLaneC[43].
    KEY_FOLD_BLOCK(aCrystalLaneB, 28U, aEarthLaneC, 43U, aMuLaneD, 5U);

    // Mu D[6]: aEarthLaneB[58] + aCrystalLaneD[60].
    KEY_FOLD_BLOCK(aEarthLaneB, 58U, aCrystalLaneD, 60U, aMuLaneD, 6U);

    // Mu D[7]: aEarthLaneD[60] + aCrystalLaneB[52].
    KEY_FOLD_BLOCK(aEarthLaneD, 60U, aCrystalLaneB, 52U, aMuLaneD, 7U);

    // Lel — four 512-byte blocks per lane.

    // Lel A[0]: aMuLaneA[3] + aMuLaneB[5].
    KEY_FOLD_BLOCK(aMuLaneA, 3U, aMuLaneB, 5U, aLelLaneA, 0U);

    // Lel A[1]: aMuLaneC[1] + aMuLaneD[0].
    KEY_FOLD_BLOCK(aMuLaneC, 1U, aMuLaneD, 0U, aLelLaneA, 1U);

    // Lel A[2]: aMuLaneC[7] + aMuLaneD[6].
    KEY_FOLD_BLOCK(aMuLaneC, 7U, aMuLaneD, 6U, aLelLaneA, 2U);

    // Lel A[3]: aMuLaneA[7] + aMuLaneB[0].
    KEY_FOLD_BLOCK(aMuLaneA, 7U, aMuLaneB, 0U, aLelLaneA, 3U);

    // Lel B[0]: aMuLaneC[4] + aMuLaneA[0].
    KEY_FOLD_BLOCK(aMuLaneC, 4U, aMuLaneA, 0U, aLelLaneB, 0U);

    // Lel B[1]: aMuLaneD[3] + aMuLaneB[3].
    KEY_FOLD_BLOCK(aMuLaneD, 3U, aMuLaneB, 3U, aLelLaneB, 1U);

    // Lel B[2]: aMuLaneB[7] + aMuLaneA[5].
    KEY_FOLD_BLOCK(aMuLaneB, 7U, aMuLaneA, 5U, aLelLaneB, 2U);

    // Lel B[3]: aMuLaneD[2] + aMuLaneC[0].
    KEY_FOLD_BLOCK(aMuLaneD, 2U, aMuLaneC, 0U, aLelLaneB, 3U);

    // Lel C[0]: aMuLaneB[4] + aMuLaneC[3].
    KEY_FOLD_BLOCK(aMuLaneB, 4U, aMuLaneC, 3U, aLelLaneC, 0U);

    // Lel C[1]: aMuLaneA[6] + aMuLaneD[5].
    KEY_FOLD_BLOCK(aMuLaneA, 6U, aMuLaneD, 5U, aLelLaneC, 1U);

    // Lel C[2]: aMuLaneB[1] + aMuLaneD[4].
    KEY_FOLD_BLOCK(aMuLaneB, 1U, aMuLaneD, 4U, aLelLaneC, 2U);

    // Lel C[3]: aMuLaneC[2] + aMuLaneA[4].
    KEY_FOLD_BLOCK(aMuLaneC, 2U, aMuLaneA, 4U, aLelLaneC, 3U);

    // Lel D[0]: aMuLaneD[7] + aMuLaneC[5].
    KEY_FOLD_BLOCK(aMuLaneD, 7U, aMuLaneC, 5U, aLelLaneD, 0U);

    // Lel D[1]: aMuLaneA[2] + aMuLaneB[6].
    KEY_FOLD_BLOCK(aMuLaneA, 2U, aMuLaneB, 6U, aLelLaneD, 1U);

    // Lel D[2]: aMuLaneB[2] + aMuLaneC[6].
    KEY_FOLD_BLOCK(aMuLaneB, 2U, aMuLaneC, 6U, aLelLaneD, 2U);

    // Lel D[3]: aMuLaneA[1] + aMuLaneD[1].
    KEY_FOLD_BLOCK(aMuLaneA, 1U, aMuLaneD, 1U, aLelLaneD, 3U);

    // Goz — two 512-byte blocks per lane.

    // Goz A[0]: aLelLaneD[0] + aLelLaneA[3].
    KEY_FOLD_BLOCK(aLelLaneD, 0U, aLelLaneA, 3U, aGozLaneA, 0U);

    // Goz A[1]: aLelLaneC[2] + aLelLaneB[0].
    KEY_FOLD_BLOCK(aLelLaneC, 2U, aLelLaneB, 0U, aGozLaneA, 1U);

    // Goz B[0]: aLelLaneD[3] + aLelLaneC[0].
    KEY_FOLD_BLOCK(aLelLaneD, 3U, aLelLaneC, 0U, aGozLaneB, 0U);

    // Goz B[1]: aLelLaneB[3] + aLelLaneA[0].
    KEY_FOLD_BLOCK(aLelLaneB, 3U, aLelLaneA, 0U, aGozLaneB, 1U);

    // Goz C[0]: aLelLaneA[1] + aLelLaneB[2].
    KEY_FOLD_BLOCK(aLelLaneA, 1U, aLelLaneB, 2U, aGozLaneC, 0U);

    // Goz C[1]: aLelLaneD[2] + aLelLaneC[1].
    KEY_FOLD_BLOCK(aLelLaneD, 2U, aLelLaneC, 1U, aGozLaneC, 1U);

    // Goz D[0]: aLelLaneC[3] + aLelLaneB[1].
    KEY_FOLD_BLOCK(aLelLaneC, 3U, aLelLaneB, 1U, aGozLaneD, 0U);

    // Goz D[1]: aLelLaneA[2] + aLelLaneD[1].
    KEY_FOLD_BLOCK(aLelLaneA, 2U, aLelLaneD, 1U, aGozLaneD, 1U);

    // Key source memberships.
    // Block 0: Earth={A:2, B:2, C:2, D:2} Crystal={A:2, B:2, C:2, D:2}.
    // Quarters: Earth={A:0/2, B:0/2, C:3/1, D:3/1} Crystal={A:0/2, B:3/1, C:3/1, D:3/1}.
    // Block 1: Earth={A:2, B:2, C:2, D:2} Crystal={A:2, B:2, C:2, D:2}.
    // Quarters: Earth={A:1/3, B:3/1, C:2/0, D:2/0} Crystal={A:3/1, B:0/2, C:2/0, D:1/3}.
    // Block 2: Earth={A:2, B:2, C:2, D:2} Crystal={A:2, B:2, C:2, D:2}.
    // Quarters: Earth={A:0/2, B:3/1, C:0/2, D:1/3} Crystal={A:0/2, B:3/1, C:2/0, D:0/2}.
    // Block 3: Earth={A:2, B:2, C:2, D:2} Crystal={A:2, B:2, C:2, D:2}.
    // Quarters: Earth={A:1/3, B:1/3, C:3/1, D:3/1} Crystal={A:2/0, B:1/3, C:2/0, D:1/3}.

    // Key — fixed two-input Goz fold.

    KEY_FOLD_BLOCK(aGozLaneA, 0U, aGozLaneB, 0U, aFinalLaneB, 0U);

    KEY_FOLD_BLOCK(aGozLaneC, 0U, aGozLaneD, 0U, aFinalLaneB, 1U);

    KEY_FOLD_BLOCK(aGozLaneA, 1U, aGozLaneC, 1U, aFinalLaneB, 2U);

    KEY_FOLD_BLOCK(aGozLaneB, 1U, aGozLaneD, 1U, aFinalLaneB, 3U);


    // Grow input C — balanced 512-byte fold graph.

    // Mu — eight 512-byte blocks per lane.

    // Mu A[0]: aEarthLaneA[51] + aEarthLaneB[4].
    KEY_FOLD_BLOCK(aEarthLaneA, 51U, aEarthLaneB, 4U, aMuLaneA, 0U);

    // Mu A[1]: aCrystalLaneD[46] + aCrystalLaneC[11].
    KEY_FOLD_BLOCK(aCrystalLaneD, 46U, aCrystalLaneC, 11U, aMuLaneA, 1U);

    // Mu A[2]: aCrystalLaneA[17] + aEarthLaneC[33].
    KEY_FOLD_BLOCK(aCrystalLaneA, 17U, aEarthLaneC, 33U, aMuLaneA, 2U);

    // Mu A[3]: aEarthLaneB[48] + aEarthLaneA[21].
    KEY_FOLD_BLOCK(aEarthLaneB, 48U, aEarthLaneA, 21U, aMuLaneA, 3U);

    // Mu A[4]: aEarthLaneD[20] + aCrystalLaneC[43].
    KEY_FOLD_BLOCK(aEarthLaneD, 20U, aCrystalLaneC, 43U, aMuLaneA, 4U);

    // Mu A[5]: aCrystalLaneB[14] + aEarthLaneD[58].
    KEY_FOLD_BLOCK(aCrystalLaneB, 14U, aEarthLaneD, 58U, aMuLaneA, 5U);

    // Mu A[6]: aEarthLaneC[31] + aCrystalLaneB[42].
    KEY_FOLD_BLOCK(aEarthLaneC, 31U, aCrystalLaneB, 42U, aMuLaneA, 6U);

    // Mu A[7]: aCrystalLaneD[24] + aCrystalLaneA[29].
    KEY_FOLD_BLOCK(aCrystalLaneD, 24U, aCrystalLaneA, 29U, aMuLaneA, 7U);

    // Mu B[0]: aCrystalLaneD[26] + aCrystalLaneB[24].
    KEY_FOLD_BLOCK(aCrystalLaneD, 26U, aCrystalLaneB, 24U, aMuLaneB, 0U);

    // Mu B[1]: aEarthLaneB[34] + aCrystalLaneA[51].
    KEY_FOLD_BLOCK(aEarthLaneB, 34U, aCrystalLaneA, 51U, aMuLaneB, 1U);

    // Mu B[2]: aCrystalLaneB[56] + aCrystalLaneC[57].
    KEY_FOLD_BLOCK(aCrystalLaneB, 56U, aCrystalLaneC, 57U, aMuLaneB, 2U);

    // Mu B[3]: aCrystalLaneA[25] + aEarthLaneD[22].
    KEY_FOLD_BLOCK(aCrystalLaneA, 25U, aEarthLaneD, 22U, aMuLaneB, 3U);

    // Mu B[4]: aEarthLaneC[25] + aCrystalLaneD[2].
    KEY_FOLD_BLOCK(aEarthLaneC, 25U, aCrystalLaneD, 2U, aMuLaneB, 4U);

    // Mu B[5]: aEarthLaneB[46] + aEarthLaneA[41].
    KEY_FOLD_BLOCK(aEarthLaneB, 46U, aEarthLaneA, 41U, aMuLaneB, 5U);

    // Mu B[6]: aEarthLaneD[0] + aCrystalLaneC[47].
    KEY_FOLD_BLOCK(aEarthLaneD, 0U, aCrystalLaneC, 47U, aMuLaneB, 6U);

    // Mu B[7]: aEarthLaneA[11] + aEarthLaneC[49].
    KEY_FOLD_BLOCK(aEarthLaneA, 11U, aEarthLaneC, 49U, aMuLaneB, 7U);

    // Mu C[0]: aCrystalLaneB[20] + aCrystalLaneD[6].
    KEY_FOLD_BLOCK(aCrystalLaneB, 20U, aCrystalLaneD, 6U, aMuLaneC, 0U);

    // Mu C[1]: aCrystalLaneC[3] + aEarthLaneD[34].
    KEY_FOLD_BLOCK(aCrystalLaneC, 3U, aEarthLaneD, 34U, aMuLaneC, 1U);

    // Mu C[2]: aEarthLaneB[8] + aEarthLaneA[3].
    KEY_FOLD_BLOCK(aEarthLaneB, 8U, aEarthLaneA, 3U, aMuLaneC, 2U);

    // Mu C[3]: aEarthLaneD[48] + aEarthLaneC[17].
    KEY_FOLD_BLOCK(aEarthLaneD, 48U, aEarthLaneC, 17U, aMuLaneC, 3U);

    // Mu C[4]: aCrystalLaneA[57] + aEarthLaneC[3].
    KEY_FOLD_BLOCK(aCrystalLaneA, 57U, aEarthLaneC, 3U, aMuLaneC, 4U);

    // Mu C[5]: aEarthLaneA[17] + aEarthLaneB[44].
    KEY_FOLD_BLOCK(aEarthLaneA, 17U, aEarthLaneB, 44U, aMuLaneC, 5U);

    // Mu C[6]: aCrystalLaneA[49] + aCrystalLaneC[41].
    KEY_FOLD_BLOCK(aCrystalLaneA, 49U, aCrystalLaneC, 41U, aMuLaneC, 6U);

    // Mu C[7]: aCrystalLaneD[34] + aCrystalLaneB[38].
    KEY_FOLD_BLOCK(aCrystalLaneD, 34U, aCrystalLaneB, 38U, aMuLaneC, 7U);

    // Mu D[0]: aEarthLaneC[63] + aCrystalLaneC[7].
    KEY_FOLD_BLOCK(aEarthLaneC, 63U, aCrystalLaneC, 7U, aMuLaneD, 0U);

    // Mu D[1]: aCrystalLaneB[4] + aEarthLaneC[53].
    KEY_FOLD_BLOCK(aCrystalLaneB, 4U, aEarthLaneC, 53U, aMuLaneD, 1U);

    // Mu D[2]: aCrystalLaneA[43] + aCrystalLaneB[62].
    KEY_FOLD_BLOCK(aCrystalLaneA, 43U, aCrystalLaneB, 62U, aMuLaneD, 2U);

    // Mu D[3]: aEarthLaneD[50] + aCrystalLaneD[52].
    KEY_FOLD_BLOCK(aEarthLaneD, 50U, aCrystalLaneD, 52U, aMuLaneD, 3U);

    // Mu D[4]: aEarthLaneA[53] + aEarthLaneB[18].
    KEY_FOLD_BLOCK(aEarthLaneA, 53U, aEarthLaneB, 18U, aMuLaneD, 4U);

    // Mu D[5]: aCrystalLaneD[48] + aEarthLaneA[47].
    KEY_FOLD_BLOCK(aCrystalLaneD, 48U, aEarthLaneA, 47U, aMuLaneD, 5U);

    // Mu D[6]: aEarthLaneB[6] + aCrystalLaneA[15].
    KEY_FOLD_BLOCK(aEarthLaneB, 6U, aCrystalLaneA, 15U, aMuLaneD, 6U);

    // Mu D[7]: aCrystalLaneC[27] + aEarthLaneD[30].
    KEY_FOLD_BLOCK(aCrystalLaneC, 27U, aEarthLaneD, 30U, aMuLaneD, 7U);

    // Lel — four 512-byte blocks per lane.

    // Lel A[0]: aMuLaneD[4] + aMuLaneA[5].
    KEY_FOLD_BLOCK(aMuLaneD, 4U, aMuLaneA, 5U, aLelLaneA, 0U);

    // Lel A[1]: aMuLaneA[0] + aMuLaneC[4].
    KEY_FOLD_BLOCK(aMuLaneA, 0U, aMuLaneC, 4U, aLelLaneA, 1U);

    // Lel A[2]: aMuLaneD[0] + aMuLaneB[3].
    KEY_FOLD_BLOCK(aMuLaneD, 0U, aMuLaneB, 3U, aLelLaneA, 2U);

    // Lel A[3]: aMuLaneC[0] + aMuLaneB[7].
    KEY_FOLD_BLOCK(aMuLaneC, 0U, aMuLaneB, 7U, aLelLaneA, 3U);

    // Lel B[0]: aMuLaneD[7] + aMuLaneB[0].
    KEY_FOLD_BLOCK(aMuLaneD, 7U, aMuLaneB, 0U, aLelLaneB, 0U);

    // Lel B[1]: aMuLaneD[2] + aMuLaneB[5].
    KEY_FOLD_BLOCK(aMuLaneD, 2U, aMuLaneB, 5U, aLelLaneB, 1U);

    // Lel B[2]: aMuLaneA[3] + aMuLaneC[7].
    KEY_FOLD_BLOCK(aMuLaneA, 3U, aMuLaneC, 7U, aLelLaneB, 2U);

    // Lel B[3]: aMuLaneC[2] + aMuLaneA[7].
    KEY_FOLD_BLOCK(aMuLaneC, 2U, aMuLaneA, 7U, aLelLaneB, 3U);

    // Lel C[0]: aMuLaneD[1] + aMuLaneB[6].
    KEY_FOLD_BLOCK(aMuLaneD, 1U, aMuLaneB, 6U, aLelLaneC, 0U);

    // Lel C[1]: aMuLaneA[1] + aMuLaneC[3].
    KEY_FOLD_BLOCK(aMuLaneA, 1U, aMuLaneC, 3U, aLelLaneC, 1U);

    // Lel C[2]: aMuLaneB[1] + aMuLaneD[5].
    KEY_FOLD_BLOCK(aMuLaneB, 1U, aMuLaneD, 5U, aLelLaneC, 2U);

    // Lel C[3]: aMuLaneA[2] + aMuLaneC[5].
    KEY_FOLD_BLOCK(aMuLaneA, 2U, aMuLaneC, 5U, aLelLaneC, 3U);

    // Lel D[0]: aMuLaneA[6] + aMuLaneC[1].
    KEY_FOLD_BLOCK(aMuLaneA, 6U, aMuLaneC, 1U, aLelLaneD, 0U);

    // Lel D[1]: aMuLaneD[3] + aMuLaneB[2].
    KEY_FOLD_BLOCK(aMuLaneD, 3U, aMuLaneB, 2U, aLelLaneD, 1U);

    // Lel D[2]: aMuLaneC[6] + aMuLaneB[4].
    KEY_FOLD_BLOCK(aMuLaneC, 6U, aMuLaneB, 4U, aLelLaneD, 2U);

    // Lel D[3]: aMuLaneA[4] + aMuLaneD[6].
    KEY_FOLD_BLOCK(aMuLaneA, 4U, aMuLaneD, 6U, aLelLaneD, 3U);

    // Goz — two 512-byte blocks per lane.

    // Goz A[0]: aLelLaneD[0] + aLelLaneC[2].
    KEY_FOLD_BLOCK(aLelLaneD, 0U, aLelLaneC, 2U, aGozLaneA, 0U);

    // Goz A[1]: aLelLaneA[1] + aLelLaneB[0].
    KEY_FOLD_BLOCK(aLelLaneA, 1U, aLelLaneB, 0U, aGozLaneA, 1U);

    // Goz B[0]: aLelLaneB[3] + aLelLaneC[0].
    KEY_FOLD_BLOCK(aLelLaneB, 3U, aLelLaneC, 0U, aGozLaneB, 0U);

    // Goz B[1]: aLelLaneA[3] + aLelLaneD[3].
    KEY_FOLD_BLOCK(aLelLaneA, 3U, aLelLaneD, 3U, aGozLaneB, 1U);

    // Goz C[0]: aLelLaneB[2] + aLelLaneA[2].
    KEY_FOLD_BLOCK(aLelLaneB, 2U, aLelLaneA, 2U, aGozLaneC, 0U);

    // Goz C[1]: aLelLaneD[1] + aLelLaneC[3].
    KEY_FOLD_BLOCK(aLelLaneD, 1U, aLelLaneC, 3U, aGozLaneC, 1U);

    // Goz D[0]: aLelLaneA[0] + aLelLaneD[2].
    KEY_FOLD_BLOCK(aLelLaneA, 0U, aLelLaneD, 2U, aGozLaneD, 0U);

    // Goz D[1]: aLelLaneC[1] + aLelLaneB[1].
    KEY_FOLD_BLOCK(aLelLaneC, 1U, aLelLaneB, 1U, aGozLaneD, 1U);

    // Key source memberships.
    // Block 0: Earth={A:2, B:2, C:2, D:2} Crystal={A:2, B:2, C:2, D:2}.
    // Quarters: Earth={A:2/0, B:2/0, C:1/3, D:2/0} Crystal={A:3/1, B:2/0, C:0/2, D:3/1}.
    // Block 1: Earth={A:2, B:2, C:2, D:2} Crystal={A:2, B:2, C:2, D:2}.
    // Quarters: Earth={A:1/3, B:3/1, C:3/1, D:1/3} Crystal={A:1/3, B:2/0, C:0/2, D:2/0}.
    // Block 2: Earth={A:2, B:2, C:2, D:2} Crystal={A:2, B:2, C:2, D:2}.
    // Quarters: Earth={A:3/1, B:0/2, C:0/2, D:1/3} Crystal={A:3/1, B:1/3, C:1/3, D:1/3}.
    // Block 3: Earth={A:2, B:2, C:2, D:2} Crystal={A:2, B:2, C:2, D:2}.
    // Quarters: Earth={A:0/2, B:0/2, C:3/1, D:1/3} Crystal={A:0/2, B:1/3, C:2/0, D:0/2}.

    // Key — fixed two-input Goz fold.

    KEY_FOLD_BLOCK(aGozLaneA, 0U, aGozLaneB, 0U, aFinalLaneC, 0U);

    KEY_FOLD_BLOCK(aGozLaneC, 0U, aGozLaneD, 0U, aFinalLaneC, 1U);

    KEY_FOLD_BLOCK(aGozLaneA, 1U, aGozLaneC, 1U, aFinalLaneC, 2U);

    KEY_FOLD_BLOCK(aGozLaneB, 1U, aGozLaneD, 1U, aFinalLaneC, 3U);


    // Grow input D — balanced 512-byte fold graph.

    // Mu — eight 512-byte blocks per lane.

    // Mu A[0]: aEarthLaneA[23] + aCrystalLaneA[45].
    KEY_FOLD_BLOCK(aEarthLaneA, 23U, aCrystalLaneA, 45U, aMuLaneA, 0U);

    // Mu A[1]: aCrystalLaneD[54] + aCrystalLaneB[60].
    KEY_FOLD_BLOCK(aCrystalLaneD, 54U, aCrystalLaneB, 60U, aMuLaneA, 1U);

    // Mu A[2]: aEarthLaneC[1] + aEarthLaneA[57].
    KEY_FOLD_BLOCK(aEarthLaneC, 1U, aEarthLaneA, 57U, aMuLaneA, 2U);

    // Mu A[3]: aEarthLaneD[12] + aCrystalLaneC[53].
    KEY_FOLD_BLOCK(aEarthLaneD, 12U, aCrystalLaneC, 53U, aMuLaneA, 3U);

    // Mu A[4]: aCrystalLaneD[8] + aCrystalLaneB[58].
    KEY_FOLD_BLOCK(aCrystalLaneD, 8U, aCrystalLaneB, 58U, aMuLaneA, 4U);

    // Mu A[5]: aEarthLaneC[11] + aEarthLaneB[38].
    KEY_FOLD_BLOCK(aEarthLaneC, 11U, aEarthLaneB, 38U, aMuLaneA, 5U);

    // Mu A[6]: aEarthLaneD[62] + aCrystalLaneA[55].
    KEY_FOLD_BLOCK(aEarthLaneD, 62U, aCrystalLaneA, 55U, aMuLaneA, 6U);

    // Mu A[7]: aEarthLaneB[16] + aCrystalLaneC[21].
    KEY_FOLD_BLOCK(aEarthLaneB, 16U, aCrystalLaneC, 21U, aMuLaneA, 7U);

    // Mu B[0]: aEarthLaneD[38] + aCrystalLaneD[40].
    KEY_FOLD_BLOCK(aEarthLaneD, 38U, aCrystalLaneD, 40U, aMuLaneB, 0U);

    // Mu B[1]: aCrystalLaneA[11] + aEarthLaneB[62].
    KEY_FOLD_BLOCK(aCrystalLaneA, 11U, aEarthLaneB, 62U, aMuLaneB, 1U);

    // Mu B[2]: aEarthLaneD[56] + aEarthLaneC[45].
    KEY_FOLD_BLOCK(aEarthLaneD, 56U, aEarthLaneC, 45U, aMuLaneB, 2U);

    // Mu B[3]: aEarthLaneA[15] + aEarthLaneB[36].
    KEY_FOLD_BLOCK(aEarthLaneA, 15U, aEarthLaneB, 36U, aMuLaneB, 3U);

    // Mu B[4]: aEarthLaneA[7] + aCrystalLaneC[15].
    KEY_FOLD_BLOCK(aEarthLaneA, 7U, aCrystalLaneC, 15U, aMuLaneB, 4U);

    // Mu B[5]: aCrystalLaneB[30] + aCrystalLaneC[33].
    KEY_FOLD_BLOCK(aCrystalLaneB, 30U, aCrystalLaneC, 33U, aMuLaneB, 5U);

    // Mu B[6]: aCrystalLaneB[6] + aCrystalLaneD[4].
    KEY_FOLD_BLOCK(aCrystalLaneB, 6U, aCrystalLaneD, 4U, aMuLaneB, 6U);

    // Mu B[7]: aCrystalLaneA[53] + aEarthLaneC[47].
    KEY_FOLD_BLOCK(aCrystalLaneA, 53U, aEarthLaneC, 47U, aMuLaneB, 7U);

    // Mu C[0]: aEarthLaneB[0] + aCrystalLaneC[9].
    KEY_FOLD_BLOCK(aEarthLaneB, 0U, aCrystalLaneC, 9U, aMuLaneC, 0U);

    // Mu C[1]: aEarthLaneC[37] + aCrystalLaneB[46].
    KEY_FOLD_BLOCK(aEarthLaneC, 37U, aCrystalLaneB, 46U, aMuLaneC, 1U);

    // Mu C[2]: aCrystalLaneC[17] + aEarthLaneB[2].
    KEY_FOLD_BLOCK(aCrystalLaneC, 17U, aEarthLaneB, 2U, aMuLaneC, 2U);

    // Mu C[3]: aCrystalLaneA[33] + aCrystalLaneD[22].
    KEY_FOLD_BLOCK(aCrystalLaneA, 33U, aCrystalLaneD, 22U, aMuLaneC, 3U);

    // Mu C[4]: aEarthLaneD[28] + aEarthLaneA[45].
    KEY_FOLD_BLOCK(aEarthLaneD, 28U, aEarthLaneA, 45U, aMuLaneC, 4U);

    // Mu C[5]: aCrystalLaneD[42] + aCrystalLaneA[19].
    KEY_FOLD_BLOCK(aCrystalLaneD, 42U, aCrystalLaneA, 19U, aMuLaneC, 5U);

    // Mu C[6]: aEarthLaneC[41] + aCrystalLaneB[54].
    KEY_FOLD_BLOCK(aEarthLaneC, 41U, aCrystalLaneB, 54U, aMuLaneC, 6U);

    // Mu C[7]: aEarthLaneA[59] + aEarthLaneD[24].
    KEY_FOLD_BLOCK(aEarthLaneA, 59U, aEarthLaneD, 24U, aMuLaneC, 7U);

    // Mu D[0]: aEarthLaneB[42] + aCrystalLaneC[39].
    KEY_FOLD_BLOCK(aEarthLaneB, 42U, aCrystalLaneC, 39U, aMuLaneD, 0U);

    // Mu D[1]: aEarthLaneA[31] + aCrystalLaneB[18].
    KEY_FOLD_BLOCK(aEarthLaneA, 31U, aCrystalLaneB, 18U, aMuLaneD, 1U);

    // Mu D[2]: aCrystalLaneB[16] + aEarthLaneC[7].
    KEY_FOLD_BLOCK(aCrystalLaneB, 16U, aEarthLaneC, 7U, aMuLaneD, 2U);

    // Mu D[3]: aCrystalLaneA[9] + aEarthLaneD[2].
    KEY_FOLD_BLOCK(aCrystalLaneA, 9U, aEarthLaneD, 2U, aMuLaneD, 3U);

    // Mu D[4]: aEarthLaneA[37] + aEarthLaneD[40].
    KEY_FOLD_BLOCK(aEarthLaneA, 37U, aEarthLaneD, 40U, aMuLaneD, 4U);

    // Mu D[5]: aCrystalLaneD[12] + aCrystalLaneA[31].
    KEY_FOLD_BLOCK(aCrystalLaneD, 12U, aCrystalLaneA, 31U, aMuLaneD, 5U);

    // Mu D[6]: aEarthLaneC[13] + aCrystalLaneC[63].
    KEY_FOLD_BLOCK(aEarthLaneC, 13U, aCrystalLaneC, 63U, aMuLaneD, 6U);

    // Mu D[7]: aCrystalLaneD[44] + aEarthLaneB[14].
    KEY_FOLD_BLOCK(aCrystalLaneD, 44U, aEarthLaneB, 14U, aMuLaneD, 7U);

    // Lel — four 512-byte blocks per lane.

    // Lel A[0]: aMuLaneC[3] + aMuLaneA[7].
    KEY_FOLD_BLOCK(aMuLaneC, 3U, aMuLaneA, 7U, aLelLaneA, 0U);

    // Lel A[1]: aMuLaneD[5] + aMuLaneB[5].
    KEY_FOLD_BLOCK(aMuLaneD, 5U, aMuLaneB, 5U, aLelLaneA, 1U);

    // Lel A[2]: aMuLaneC[7] + aMuLaneA[1].
    KEY_FOLD_BLOCK(aMuLaneC, 7U, aMuLaneA, 1U, aLelLaneA, 2U);

    // Lel A[3]: aMuLaneB[0] + aMuLaneD[0].
    KEY_FOLD_BLOCK(aMuLaneB, 0U, aMuLaneD, 0U, aLelLaneA, 3U);

    // Lel B[0]: aMuLaneD[3] + aMuLaneC[0].
    KEY_FOLD_BLOCK(aMuLaneD, 3U, aMuLaneC, 0U, aLelLaneB, 0U);

    // Lel B[1]: aMuLaneB[3] + aMuLaneC[5].
    KEY_FOLD_BLOCK(aMuLaneB, 3U, aMuLaneC, 5U, aLelLaneB, 1U);

    // Lel B[2]: aMuLaneA[4] + aMuLaneB[7].
    KEY_FOLD_BLOCK(aMuLaneA, 4U, aMuLaneB, 7U, aLelLaneB, 2U);

    // Lel B[3]: aMuLaneA[6] + aMuLaneD[7].
    KEY_FOLD_BLOCK(aMuLaneA, 6U, aMuLaneD, 7U, aLelLaneB, 3U);

    // Lel C[0]: aMuLaneD[4] + aMuLaneC[2].
    KEY_FOLD_BLOCK(aMuLaneD, 4U, aMuLaneC, 2U, aLelLaneC, 0U);

    // Lel C[1]: aMuLaneB[6] + aMuLaneA[2].
    KEY_FOLD_BLOCK(aMuLaneB, 6U, aMuLaneA, 2U, aLelLaneC, 1U);

    // Lel C[2]: aMuLaneA[3] + aMuLaneD[2].
    KEY_FOLD_BLOCK(aMuLaneA, 3U, aMuLaneD, 2U, aLelLaneC, 2U);

    // Lel C[3]: aMuLaneC[6] + aMuLaneB[4].
    KEY_FOLD_BLOCK(aMuLaneC, 6U, aMuLaneB, 4U, aLelLaneC, 3U);

    // Lel D[0]: aMuLaneB[2] + aMuLaneD[1].
    KEY_FOLD_BLOCK(aMuLaneB, 2U, aMuLaneD, 1U, aLelLaneD, 0U);

    // Lel D[1]: aMuLaneA[0] + aMuLaneC[1].
    KEY_FOLD_BLOCK(aMuLaneA, 0U, aMuLaneC, 1U, aLelLaneD, 1U);

    // Lel D[2]: aMuLaneA[5] + aMuLaneC[4].
    KEY_FOLD_BLOCK(aMuLaneA, 5U, aMuLaneC, 4U, aLelLaneD, 2U);

    // Lel D[3]: aMuLaneD[6] + aMuLaneB[1].
    KEY_FOLD_BLOCK(aMuLaneD, 6U, aMuLaneB, 1U, aLelLaneD, 3U);

    // Goz — two 512-byte blocks per lane.

    // Goz A[0]: aLelLaneD[3] + aLelLaneA[2].
    KEY_FOLD_BLOCK(aLelLaneD, 3U, aLelLaneA, 2U, aGozLaneA, 0U);

    // Goz A[1]: aLelLaneC[1] + aLelLaneB[0].
    KEY_FOLD_BLOCK(aLelLaneC, 1U, aLelLaneB, 0U, aGozLaneA, 1U);

    // Goz B[0]: aLelLaneA[0] + aLelLaneD[0].
    KEY_FOLD_BLOCK(aLelLaneA, 0U, aLelLaneD, 0U, aGozLaneB, 0U);

    // Goz B[1]: aLelLaneB[3] + aLelLaneC[3].
    KEY_FOLD_BLOCK(aLelLaneB, 3U, aLelLaneC, 3U, aGozLaneB, 1U);

    // Goz C[0]: aLelLaneC[2] + aLelLaneB[1].
    KEY_FOLD_BLOCK(aLelLaneC, 2U, aLelLaneB, 1U, aGozLaneC, 0U);

    // Goz C[1]: aLelLaneA[3] + aLelLaneD[1].
    KEY_FOLD_BLOCK(aLelLaneA, 3U, aLelLaneD, 1U, aGozLaneC, 1U);

    // Goz D[0]: aLelLaneC[0] + aLelLaneB[2].
    KEY_FOLD_BLOCK(aLelLaneC, 0U, aLelLaneB, 2U, aGozLaneD, 0U);

    // Goz D[1]: aLelLaneD[2] + aLelLaneA[1].
    KEY_FOLD_BLOCK(aLelLaneD, 2U, aLelLaneA, 1U, aGozLaneD, 1U);

    // Key source memberships.
    // Block 0: Earth={A:2, B:2, C:2, D:2} Crystal={A:2, B:2, C:2, D:2}.
    // Quarters: Earth={A:3/1, B:3/1, C:0/2, D:1/3} Crystal={A:0/2, B:3/1, C:3/1, D:3/1}.
    // Block 1: Earth={A:2, B:2, C:2, D:2} Crystal={A:2, B:2, C:2, D:2}.
    // Quarters: Earth={A:0/2, B:2/0, C:0/2, D:0/2} Crystal={A:1/3, B:1/3, C:3/1, D:2/0}.
    // Block 2: Earth={A:2, B:2, C:2, D:2} Crystal={A:2, B:2, C:2, D:2}.
    // Quarters: Earth={A:3/1, B:0/2, C:0/2, D:0/2} Crystal={A:0/2, B:0/2, C:0/2, D:0/2}.
    // Block 3: Earth={A:2, B:2, C:2, D:2} Crystal={A:2, B:2, C:2, D:2}.
    // Quarters: Earth={A:0/2, B:0/2, C:2/0, D:3/1} Crystal={A:3/1, B:3/1, C:0/2, D:2/0}.

    // Key — fixed two-input Goz fold.

    KEY_FOLD_BLOCK(aGozLaneA, 0U, aGozLaneB, 0U, aFinalLaneD, 0U);

    KEY_FOLD_BLOCK(aGozLaneC, 0U, aGozLaneD, 0U, aFinalLaneD, 1U);

    KEY_FOLD_BLOCK(aGozLaneA, 1U, aGozLaneC, 1U, aFinalLaneD, 2U);

    KEY_FOLD_BLOCK(aGozLaneB, 1U, aGozLaneD, 1U, aFinalLaneD, 3U);

}

void TwistExpander_Aldebaran::TwistForkKeyHalfB(TwistWorkSpace *pWorkSpace) {
    static_assert(S_BLOCK == 32768, "Twist fork source size changed.");
    static_assert(S_BLOCK / 64U == 512U, "Twist fork block size changed.");
    static_assert(W_KEY == 2048, "Twist fork key size changed.");

    std::uint8_t *aEarthLaneA = pWorkSpace->mEarthLaneA;
    std::uint8_t *aEarthLaneB = pWorkSpace->mEarthLaneB;
    std::uint8_t *aEarthLaneC = pWorkSpace->mEarthLaneC;
    std::uint8_t *aEarthLaneD = pWorkSpace->mEarthLaneD;
    std::uint8_t *aCrystalLaneA = pWorkSpace->mCrystalLaneA;
    std::uint8_t *aCrystalLaneB = pWorkSpace->mCrystalLaneB;
    std::uint8_t *aCrystalLaneC = pWorkSpace->mCrystalLaneC;
    std::uint8_t *aCrystalLaneD = pWorkSpace->mCrystalLaneD;

    std::uint8_t *aMuLaneA = pWorkSpace->mCelestialLaneA;
    std::uint8_t *aLelLaneA = pWorkSpace->mAlchemyLaneA;
    std::uint8_t *aGozLaneA = pWorkSpace->mAuguryLaneA;
    std::uint8_t *aMuLaneB = pWorkSpace->mCelestialLaneB;
    std::uint8_t *aLelLaneB = pWorkSpace->mAlchemyLaneB;
    std::uint8_t *aGozLaneB = pWorkSpace->mAuguryLaneB;
    std::uint8_t *aMuLaneC = pWorkSpace->mCelestialLaneC;
    std::uint8_t *aLelLaneC = pWorkSpace->mAlchemyLaneC;
    std::uint8_t *aGozLaneC = pWorkSpace->mAuguryLaneC;
    std::uint8_t *aMuLaneD = pWorkSpace->mCelestialLaneD;
    std::uint8_t *aLelLaneD = pWorkSpace->mAlchemyLaneD;
    std::uint8_t *aGozLaneD = pWorkSpace->mAuguryLaneD;

    std::uint8_t *aFinalLaneA = pWorkSpace->mDivinationLaneA;
    std::uint8_t *aFinalLaneB = pWorkSpace->mDivinationLaneB;
    std::uint8_t *aFinalLaneC = pWorkSpace->mDivinationLaneC;
    std::uint8_t *aFinalLaneD = pWorkSpace->mDivinationLaneD;

    // Grow input A — balanced 512-byte fold graph.

    // Mu — eight 512-byte blocks per lane.

    // Mu A[0]: aEarthLaneD[53] + aEarthLaneC[34].
    KEY_FOLD_BLOCK(aEarthLaneD, 53U, aEarthLaneC, 34U, aMuLaneA, 0U);

    // Mu A[1]: aCrystalLaneD[59] + aEarthLaneD[31].
    KEY_FOLD_BLOCK(aCrystalLaneD, 59U, aEarthLaneD, 31U, aMuLaneA, 1U);

    // Mu A[2]: aEarthLaneB[9] + aEarthLaneA[22].
    KEY_FOLD_BLOCK(aEarthLaneB, 9U, aEarthLaneA, 22U, aMuLaneA, 2U);

    // Mu A[3]: aCrystalLaneB[9] + aCrystalLaneC[8].
    KEY_FOLD_BLOCK(aCrystalLaneB, 9U, aCrystalLaneC, 8U, aMuLaneA, 3U);

    // Mu A[4]: aEarthLaneB[63] + aEarthLaneC[16].
    KEY_FOLD_BLOCK(aEarthLaneB, 63U, aEarthLaneC, 16U, aMuLaneA, 4U);

    // Mu A[5]: aCrystalLaneD[29] + aCrystalLaneC[52].
    KEY_FOLD_BLOCK(aCrystalLaneD, 29U, aCrystalLaneC, 52U, aMuLaneA, 5U);

    // Mu A[6]: aCrystalLaneA[8] + aEarthLaneA[30].
    KEY_FOLD_BLOCK(aCrystalLaneA, 8U, aEarthLaneA, 30U, aMuLaneA, 6U);

    // Mu A[7]: aCrystalLaneB[39] + aCrystalLaneA[50].
    KEY_FOLD_BLOCK(aCrystalLaneB, 39U, aCrystalLaneA, 50U, aMuLaneA, 7U);

    // Mu B[0]: aCrystalLaneD[1] + aEarthLaneA[62].
    KEY_FOLD_BLOCK(aCrystalLaneD, 1U, aEarthLaneA, 62U, aMuLaneB, 0U);

    // Mu B[1]: aCrystalLaneC[38] + aEarthLaneA[24].
    KEY_FOLD_BLOCK(aCrystalLaneC, 38U, aEarthLaneA, 24U, aMuLaneB, 1U);

    // Mu B[2]: aCrystalLaneC[30] + aCrystalLaneB[47].
    KEY_FOLD_BLOCK(aCrystalLaneC, 30U, aCrystalLaneB, 47U, aMuLaneB, 2U);

    // Mu B[3]: aEarthLaneC[54] + aEarthLaneD[61].
    KEY_FOLD_BLOCK(aEarthLaneC, 54U, aEarthLaneD, 61U, aMuLaneB, 3U);

    // Mu B[4]: aEarthLaneB[27] + aEarthLaneC[58].
    KEY_FOLD_BLOCK(aEarthLaneB, 27U, aEarthLaneC, 58U, aMuLaneB, 4U);

    // Mu B[5]: aCrystalLaneD[19] + aCrystalLaneB[3].
    KEY_FOLD_BLOCK(aCrystalLaneD, 19U, aCrystalLaneB, 3U, aMuLaneB, 5U);

    // Mu B[6]: aEarthLaneB[45] + aCrystalLaneA[16].
    KEY_FOLD_BLOCK(aEarthLaneB, 45U, aCrystalLaneA, 16U, aMuLaneB, 6U);

    // Mu B[7]: aCrystalLaneA[30] + aEarthLaneD[41].
    KEY_FOLD_BLOCK(aCrystalLaneA, 30U, aEarthLaneD, 41U, aMuLaneB, 7U);

    // Mu C[0]: aEarthLaneB[43] + aCrystalLaneB[5].
    KEY_FOLD_BLOCK(aEarthLaneB, 43U, aCrystalLaneB, 5U, aMuLaneC, 0U);

    // Mu C[1]: aCrystalLaneB[19] + aCrystalLaneC[42].
    KEY_FOLD_BLOCK(aCrystalLaneB, 19U, aCrystalLaneC, 42U, aMuLaneC, 1U);

    // Mu C[2]: aCrystalLaneA[44] + aEarthLaneD[51].
    KEY_FOLD_BLOCK(aCrystalLaneA, 44U, aEarthLaneD, 51U, aMuLaneC, 2U);

    // Mu C[3]: aEarthLaneA[56] + aCrystalLaneC[0].
    KEY_FOLD_BLOCK(aEarthLaneA, 56U, aCrystalLaneC, 0U, aMuLaneC, 3U);

    // Mu C[4]: aCrystalLaneA[54] + aEarthLaneD[23].
    KEY_FOLD_BLOCK(aCrystalLaneA, 54U, aEarthLaneD, 23U, aMuLaneC, 4U);

    // Mu C[5]: aEarthLaneA[4] + aEarthLaneB[13].
    KEY_FOLD_BLOCK(aEarthLaneA, 4U, aEarthLaneB, 13U, aMuLaneC, 5U);

    // Mu C[6]: aEarthLaneC[36] + aCrystalLaneD[37].
    KEY_FOLD_BLOCK(aEarthLaneC, 36U, aCrystalLaneD, 37U, aMuLaneC, 6U);

    // Mu C[7]: aEarthLaneC[6] + aCrystalLaneD[13].
    KEY_FOLD_BLOCK(aEarthLaneC, 6U, aCrystalLaneD, 13U, aMuLaneC, 7U);

    // Mu D[0]: aEarthLaneA[48] + aEarthLaneB[53].
    KEY_FOLD_BLOCK(aEarthLaneA, 48U, aEarthLaneB, 53U, aMuLaneD, 0U);

    // Mu D[1]: aEarthLaneB[23] + aEarthLaneD[13].
    KEY_FOLD_BLOCK(aEarthLaneB, 23U, aEarthLaneD, 13U, aMuLaneD, 1U);

    // Mu D[2]: aEarthLaneA[34] + aCrystalLaneA[6].
    KEY_FOLD_BLOCK(aEarthLaneA, 34U, aCrystalLaneA, 6U, aMuLaneD, 2U);

    // Mu D[3]: aCrystalLaneB[33] + aCrystalLaneD[49].
    KEY_FOLD_BLOCK(aCrystalLaneB, 33U, aCrystalLaneD, 49U, aMuLaneD, 3U);

    // Mu D[4]: aEarthLaneD[17] + aCrystalLaneD[33].
    KEY_FOLD_BLOCK(aEarthLaneD, 17U, aCrystalLaneD, 33U, aMuLaneD, 4U);

    // Mu D[5]: aCrystalLaneC[44] + aEarthLaneC[0].
    KEY_FOLD_BLOCK(aCrystalLaneC, 44U, aEarthLaneC, 0U, aMuLaneD, 5U);

    // Mu D[6]: aEarthLaneC[22] + aCrystalLaneA[38].
    KEY_FOLD_BLOCK(aEarthLaneC, 22U, aCrystalLaneA, 38U, aMuLaneD, 6U);

    // Mu D[7]: aCrystalLaneC[12] + aCrystalLaneB[49].
    KEY_FOLD_BLOCK(aCrystalLaneC, 12U, aCrystalLaneB, 49U, aMuLaneD, 7U);

    // Lel — four 512-byte blocks per lane.

    // Lel A[0]: aMuLaneA[7] + aMuLaneC[6].
    KEY_FOLD_BLOCK(aMuLaneA, 7U, aMuLaneC, 6U, aLelLaneA, 0U);

    // Lel A[1]: aMuLaneA[1] + aMuLaneD[6].
    KEY_FOLD_BLOCK(aMuLaneA, 1U, aMuLaneD, 6U, aLelLaneA, 1U);

    // Lel A[2]: aMuLaneB[3] + aMuLaneC[0].
    KEY_FOLD_BLOCK(aMuLaneB, 3U, aMuLaneC, 0U, aLelLaneA, 2U);

    // Lel A[3]: aMuLaneB[7] + aMuLaneD[0].
    KEY_FOLD_BLOCK(aMuLaneB, 7U, aMuLaneD, 0U, aLelLaneA, 3U);

    // Lel B[0]: aMuLaneB[0] + aMuLaneA[4].
    KEY_FOLD_BLOCK(aMuLaneB, 0U, aMuLaneA, 4U, aLelLaneB, 0U);

    // Lel B[1]: aMuLaneD[3] + aMuLaneC[3].
    KEY_FOLD_BLOCK(aMuLaneD, 3U, aMuLaneC, 3U, aLelLaneB, 1U);

    // Lel B[2]: aMuLaneA[6] + aMuLaneD[4].
    KEY_FOLD_BLOCK(aMuLaneA, 6U, aMuLaneD, 4U, aLelLaneB, 2U);

    // Lel B[3]: aMuLaneC[4] + aMuLaneB[5].
    KEY_FOLD_BLOCK(aMuLaneC, 4U, aMuLaneB, 5U, aLelLaneB, 3U);

    // Lel C[0]: aMuLaneD[1] + aMuLaneB[1].
    KEY_FOLD_BLOCK(aMuLaneD, 1U, aMuLaneB, 1U, aLelLaneC, 0U);

    // Lel C[1]: aMuLaneB[2] + aMuLaneC[5].
    KEY_FOLD_BLOCK(aMuLaneB, 2U, aMuLaneC, 5U, aLelLaneC, 1U);

    // Lel C[2]: aMuLaneA[3] + aMuLaneC[7].
    KEY_FOLD_BLOCK(aMuLaneA, 3U, aMuLaneC, 7U, aLelLaneC, 2U);

    // Lel C[3]: aMuLaneA[5] + aMuLaneD[2].
    KEY_FOLD_BLOCK(aMuLaneA, 5U, aMuLaneD, 2U, aLelLaneC, 3U);

    // Lel D[0]: aMuLaneB[6] + aMuLaneA[0].
    KEY_FOLD_BLOCK(aMuLaneB, 6U, aMuLaneA, 0U, aLelLaneD, 0U);

    // Lel D[1]: aMuLaneD[7] + aMuLaneC[2].
    KEY_FOLD_BLOCK(aMuLaneD, 7U, aMuLaneC, 2U, aLelLaneD, 1U);

    // Lel D[2]: aMuLaneC[1] + aMuLaneB[4].
    KEY_FOLD_BLOCK(aMuLaneC, 1U, aMuLaneB, 4U, aLelLaneD, 2U);

    // Lel D[3]: aMuLaneD[5] + aMuLaneA[2].
    KEY_FOLD_BLOCK(aMuLaneD, 5U, aMuLaneA, 2U, aLelLaneD, 3U);

    // Goz — two 512-byte blocks per lane.

    // Goz A[0]: aLelLaneB[1] + aLelLaneD[0].
    KEY_FOLD_BLOCK(aLelLaneB, 1U, aLelLaneD, 0U, aGozLaneA, 0U);

    // Goz A[1]: aLelLaneA[2] + aLelLaneC[3].
    KEY_FOLD_BLOCK(aLelLaneA, 2U, aLelLaneC, 3U, aGozLaneA, 1U);

    // Goz B[0]: aLelLaneD[3] + aLelLaneB[3].
    KEY_FOLD_BLOCK(aLelLaneD, 3U, aLelLaneB, 3U, aGozLaneB, 0U);

    // Goz B[1]: aLelLaneC[0] + aLelLaneA[0].
    KEY_FOLD_BLOCK(aLelLaneC, 0U, aLelLaneA, 0U, aGozLaneB, 1U);

    // Goz C[0]: aLelLaneB[2] + aLelLaneD[2].
    KEY_FOLD_BLOCK(aLelLaneB, 2U, aLelLaneD, 2U, aGozLaneC, 0U);

    // Goz C[1]: aLelLaneC[1] + aLelLaneA[1].
    KEY_FOLD_BLOCK(aLelLaneC, 1U, aLelLaneA, 1U, aGozLaneC, 1U);

    // Goz D[0]: aLelLaneD[1] + aLelLaneB[0].
    KEY_FOLD_BLOCK(aLelLaneD, 1U, aLelLaneB, 0U, aGozLaneD, 0U);

    // Goz D[1]: aLelLaneA[3] + aLelLaneC[2].
    KEY_FOLD_BLOCK(aLelLaneA, 3U, aLelLaneC, 2U, aGozLaneD, 1U);

    // Key source memberships.
    // Block 0: Earth={A:2, B:2, C:2, D:2} Crystal={A:2, B:2, C:2, D:2}.
    // Quarters: Earth={A:3/1, B:2/0, C:2/0, D:3/1} Crystal={A:1/3, B:2/0, C:0/2, D:3/1}.
    // Block 1: Earth={A:2, B:2, C:2, D:2} Crystal={A:2, B:2, C:2, D:2}.
    // Quarters: Earth={A:1/3, B:1/3, C:3/1, D:1/3} Crystal={A:0/2, B:1/3, C:2/0, D:2/0}.
    // Block 2: Earth={A:2, B:2, C:2, D:2} Crystal={A:2, B:2, C:2, D:2}.
    // Quarters: Earth={A:2/0, B:2/0, C:3/1, D:3/1} Crystal={A:0/2, B:0/2, C:3/1, D:1/3}.
    // Block 3: Earth={A:2, B:2, C:2, D:2} Crystal={A:2, B:2, C:2, D:2}.
    // Quarters: Earth={A:1/3, B:1/3, C:2/0, D:0/2} Crystal={A:3/1, B:2/0, C:2/0, D:2/0}.

    // Key — fixed two-input Goz fold.

    KEY_FOLD_BLOCK(aGozLaneA, 0U, aGozLaneB, 0U, aFinalLaneA + W_KEY, 0U);

    KEY_FOLD_BLOCK(aGozLaneC, 0U, aGozLaneD, 0U, aFinalLaneA + W_KEY, 1U);

    KEY_FOLD_BLOCK(aGozLaneA, 1U, aGozLaneC, 1U, aFinalLaneA + W_KEY, 2U);

    KEY_FOLD_BLOCK(aGozLaneB, 1U, aGozLaneD, 1U, aFinalLaneA + W_KEY, 3U);


    // Grow input B — balanced 512-byte fold graph.

    // Mu — eight 512-byte blocks per lane.

    // Mu A[0]: aCrystalLaneC[32] + aEarthLaneB[39].
    KEY_FOLD_BLOCK(aCrystalLaneC, 32U, aEarthLaneB, 39U, aMuLaneA, 0U);

    // Mu A[1]: aCrystalLaneD[11] + aEarthLaneD[55].
    KEY_FOLD_BLOCK(aCrystalLaneD, 11U, aEarthLaneD, 55U, aMuLaneA, 1U);

    // Mu A[2]: aCrystalLaneA[18] + aEarthLaneD[63].
    KEY_FOLD_BLOCK(aCrystalLaneA, 18U, aEarthLaneD, 63U, aMuLaneA, 2U);

    // Mu A[3]: aCrystalLaneD[39] + aCrystalLaneB[27].
    KEY_FOLD_BLOCK(aCrystalLaneD, 39U, aCrystalLaneB, 27U, aMuLaneA, 3U);

    // Mu A[4]: aEarthLaneC[56] + aEarthLaneB[35].
    KEY_FOLD_BLOCK(aEarthLaneC, 56U, aEarthLaneB, 35U, aMuLaneA, 4U);

    // Mu A[5]: aEarthLaneA[10] + aEarthLaneC[46].
    KEY_FOLD_BLOCK(aEarthLaneA, 10U, aEarthLaneC, 46U, aMuLaneA, 5U);

    // Mu A[6]: aCrystalLaneC[22] + aCrystalLaneA[60].
    KEY_FOLD_BLOCK(aCrystalLaneC, 22U, aCrystalLaneA, 60U, aMuLaneA, 6U);

    // Mu A[7]: aCrystalLaneB[51] + aEarthLaneA[26].
    KEY_FOLD_BLOCK(aCrystalLaneB, 51U, aEarthLaneA, 26U, aMuLaneA, 7U);

    // Mu B[0]: aEarthLaneC[4] + aEarthLaneB[51].
    KEY_FOLD_BLOCK(aEarthLaneC, 4U, aEarthLaneB, 51U, aMuLaneB, 0U);

    // Mu B[1]: aCrystalLaneA[20] + aCrystalLaneB[37].
    KEY_FOLD_BLOCK(aCrystalLaneA, 20U, aCrystalLaneB, 37U, aMuLaneB, 1U);

    // Mu B[2]: aEarthLaneC[26] + aEarthLaneD[19].
    KEY_FOLD_BLOCK(aEarthLaneC, 26U, aEarthLaneD, 19U, aMuLaneB, 2U);

    // Mu B[3]: aEarthLaneA[36] + aEarthLaneD[7].
    KEY_FOLD_BLOCK(aEarthLaneA, 36U, aEarthLaneD, 7U, aMuLaneB, 3U);

    // Mu B[4]: aCrystalLaneD[5] + aCrystalLaneB[43].
    KEY_FOLD_BLOCK(aCrystalLaneD, 5U, aCrystalLaneB, 43U, aMuLaneB, 4U);

    // Mu B[5]: aCrystalLaneC[18] + aCrystalLaneD[9].
    KEY_FOLD_BLOCK(aCrystalLaneC, 18U, aCrystalLaneD, 9U, aMuLaneB, 5U);

    // Mu B[6]: aCrystalLaneC[2] + aCrystalLaneA[36].
    KEY_FOLD_BLOCK(aCrystalLaneC, 2U, aCrystalLaneA, 36U, aMuLaneB, 6U);

    // Mu B[7]: aEarthLaneB[5] + aEarthLaneA[32].
    KEY_FOLD_BLOCK(aEarthLaneB, 5U, aEarthLaneA, 32U, aMuLaneB, 7U);

    // Mu C[0]: aEarthLaneC[8] + aCrystalLaneA[12].
    KEY_FOLD_BLOCK(aEarthLaneC, 8U, aCrystalLaneA, 12U, aMuLaneC, 0U);

    // Mu C[1]: aEarthLaneD[5] + aEarthLaneC[40].
    KEY_FOLD_BLOCK(aEarthLaneD, 5U, aEarthLaneC, 40U, aMuLaneC, 1U);

    // Mu C[2]: aCrystalLaneB[15] + aCrystalLaneA[52].
    KEY_FOLD_BLOCK(aCrystalLaneB, 15U, aCrystalLaneA, 52U, aMuLaneC, 2U);

    // Mu C[3]: aCrystalLaneD[55] + aCrystalLaneB[7].
    KEY_FOLD_BLOCK(aCrystalLaneD, 55U, aCrystalLaneB, 7U, aMuLaneC, 3U);

    // Mu C[4]: aCrystalLaneC[60] + aEarthLaneD[39].
    KEY_FOLD_BLOCK(aCrystalLaneC, 60U, aEarthLaneD, 39U, aMuLaneC, 4U);

    // Mu C[5]: aCrystalLaneD[45] + aCrystalLaneC[28].
    KEY_FOLD_BLOCK(aCrystalLaneD, 45U, aCrystalLaneC, 28U, aMuLaneC, 5U);

    // Mu C[6]: aEarthLaneA[52] + aEarthLaneB[59].
    KEY_FOLD_BLOCK(aEarthLaneA, 52U, aEarthLaneB, 59U, aMuLaneC, 6U);

    // Mu C[7]: aEarthLaneA[18] + aEarthLaneB[25].
    KEY_FOLD_BLOCK(aEarthLaneA, 18U, aEarthLaneB, 25U, aMuLaneC, 7U);

    // Mu D[0]: aEarthLaneA[50] + aCrystalLaneA[32].
    KEY_FOLD_BLOCK(aEarthLaneA, 50U, aCrystalLaneA, 32U, aMuLaneD, 0U);

    // Mu D[1]: aCrystalLaneC[50] + aEarthLaneC[28].
    KEY_FOLD_BLOCK(aCrystalLaneC, 50U, aEarthLaneC, 28U, aMuLaneD, 1U);

    // Mu D[2]: aEarthLaneA[2] + aEarthLaneD[27].
    KEY_FOLD_BLOCK(aEarthLaneA, 2U, aEarthLaneD, 27U, aMuLaneD, 2U);

    // Mu D[3]: aCrystalLaneA[14] + aEarthLaneB[31].
    KEY_FOLD_BLOCK(aCrystalLaneA, 14U, aEarthLaneB, 31U, aMuLaneD, 3U);

    // Mu D[4]: aCrystalLaneB[41] + aCrystalLaneD[21].
    KEY_FOLD_BLOCK(aCrystalLaneB, 41U, aCrystalLaneD, 21U, aMuLaneD, 4U);

    // Mu D[5]: aEarthLaneC[62] + aCrystalLaneC[54].
    KEY_FOLD_BLOCK(aEarthLaneC, 62U, aCrystalLaneC, 54U, aMuLaneD, 5U);

    // Mu D[6]: aEarthLaneB[11] + aEarthLaneD[45].
    KEY_FOLD_BLOCK(aEarthLaneB, 11U, aEarthLaneD, 45U, aMuLaneD, 6U);

    // Mu D[7]: aCrystalLaneB[11] + aCrystalLaneD[43].
    KEY_FOLD_BLOCK(aCrystalLaneB, 11U, aCrystalLaneD, 43U, aMuLaneD, 7U);

    // Lel — four 512-byte blocks per lane.

    // Lel A[0]: aMuLaneB[5] + aMuLaneD[3].
    KEY_FOLD_BLOCK(aMuLaneB, 5U, aMuLaneD, 3U, aLelLaneA, 0U);

    // Lel A[1]: aMuLaneC[4] + aMuLaneB[0].
    KEY_FOLD_BLOCK(aMuLaneC, 4U, aMuLaneB, 0U, aLelLaneA, 1U);

    // Lel A[2]: aMuLaneA[6] + aMuLaneD[7].
    KEY_FOLD_BLOCK(aMuLaneA, 6U, aMuLaneD, 7U, aLelLaneA, 2U);

    // Lel A[3]: aMuLaneC[0] + aMuLaneA[0].
    KEY_FOLD_BLOCK(aMuLaneC, 0U, aMuLaneA, 0U, aLelLaneA, 3U);

    // Lel B[0]: aMuLaneB[2] + aMuLaneC[7].
    KEY_FOLD_BLOCK(aMuLaneB, 2U, aMuLaneC, 7U, aLelLaneB, 0U);

    // Lel B[1]: aMuLaneD[0] + aMuLaneA[3].
    KEY_FOLD_BLOCK(aMuLaneD, 0U, aMuLaneA, 3U, aLelLaneB, 1U);

    // Lel B[2]: aMuLaneB[7] + aMuLaneC[2].
    KEY_FOLD_BLOCK(aMuLaneB, 7U, aMuLaneC, 2U, aLelLaneB, 2U);

    // Lel B[3]: aMuLaneA[2] + aMuLaneD[5].
    KEY_FOLD_BLOCK(aMuLaneA, 2U, aMuLaneD, 5U, aLelLaneB, 3U);

    // Lel C[0]: aMuLaneC[5] + aMuLaneD[2].
    KEY_FOLD_BLOCK(aMuLaneC, 5U, aMuLaneD, 2U, aLelLaneC, 0U);

    // Lel C[1]: aMuLaneA[5] + aMuLaneB[6].
    KEY_FOLD_BLOCK(aMuLaneA, 5U, aMuLaneB, 6U, aLelLaneC, 1U);

    // Lel C[2]: aMuLaneC[1] + aMuLaneA[7].
    KEY_FOLD_BLOCK(aMuLaneC, 1U, aMuLaneA, 7U, aLelLaneC, 2U);

    // Lel C[3]: aMuLaneD[4] + aMuLaneB[3].
    KEY_FOLD_BLOCK(aMuLaneD, 4U, aMuLaneB, 3U, aLelLaneC, 3U);

    // Lel D[0]: aMuLaneC[6] + aMuLaneB[4].
    KEY_FOLD_BLOCK(aMuLaneC, 6U, aMuLaneB, 4U, aLelLaneD, 0U);

    // Lel D[1]: aMuLaneD[1] + aMuLaneA[1].
    KEY_FOLD_BLOCK(aMuLaneD, 1U, aMuLaneA, 1U, aLelLaneD, 1U);

    // Lel D[2]: aMuLaneD[6] + aMuLaneC[3].
    KEY_FOLD_BLOCK(aMuLaneD, 6U, aMuLaneC, 3U, aLelLaneD, 2U);

    // Lel D[3]: aMuLaneA[4] + aMuLaneB[1].
    KEY_FOLD_BLOCK(aMuLaneA, 4U, aMuLaneB, 1U, aLelLaneD, 3U);

    // Goz — two 512-byte blocks per lane.

    // Goz A[0]: aLelLaneC[1] + aLelLaneD[2].
    KEY_FOLD_BLOCK(aLelLaneC, 1U, aLelLaneD, 2U, aGozLaneA, 0U);

    // Goz A[1]: aLelLaneB[1] + aLelLaneA[1].
    KEY_FOLD_BLOCK(aLelLaneB, 1U, aLelLaneA, 1U, aGozLaneA, 1U);

    // Goz B[0]: aLelLaneC[3] + aLelLaneA[3].
    KEY_FOLD_BLOCK(aLelLaneC, 3U, aLelLaneA, 3U, aGozLaneB, 0U);

    // Goz B[1]: aLelLaneB[3] + aLelLaneD[0].
    KEY_FOLD_BLOCK(aLelLaneB, 3U, aLelLaneD, 0U, aGozLaneB, 1U);

    // Goz C[0]: aLelLaneB[2] + aLelLaneD[1].
    KEY_FOLD_BLOCK(aLelLaneB, 2U, aLelLaneD, 1U, aGozLaneC, 0U);

    // Goz C[1]: aLelLaneC[2] + aLelLaneA[0].
    KEY_FOLD_BLOCK(aLelLaneC, 2U, aLelLaneA, 0U, aGozLaneC, 1U);

    // Goz D[0]: aLelLaneC[0] + aLelLaneD[3].
    KEY_FOLD_BLOCK(aLelLaneC, 0U, aLelLaneD, 3U, aGozLaneD, 0U);

    // Goz D[1]: aLelLaneB[0] + aLelLaneA[2].
    KEY_FOLD_BLOCK(aLelLaneB, 0U, aLelLaneA, 2U, aGozLaneD, 1U);

    // Key source memberships.
    // Block 0: Earth={A:2, B:2, C:2, D:2} Crystal={A:2, B:2, C:2, D:2}.
    // Quarters: Earth={A:0/2, B:0/2, C:2/0, D:2/0} Crystal={A:2/0, B:0/2, C:0/2, D:3/1}.
    // Block 1: Earth={A:2, B:2, C:2, D:2} Crystal={A:2, B:2, C:2, D:2}.
    // Quarters: Earth={A:2/0, B:0/2, C:1/3, D:3/1} Crystal={A:3/1, B:0/2, C:3/1, D:0/2}.
    // Block 2: Earth={A:2, B:2, C:2, D:2} Crystal={A:2, B:2, C:2, D:2}.
    // Quarters: Earth={A:3/1, B:3/1, C:0/2, D:2/0} Crystal={A:2/0, B:1/3, C:3/1, D:2/0}.
    // Block 3: Earth={A:2, B:2, C:2, D:2} Crystal={A:2, B:2, C:2, D:2}.
    // Quarters: Earth={A:3/1, B:3/1, C:3/1, D:3/1} Crystal={A:1/3, B:2/0, C:3/1, D:0/2}.

    // Key — fixed two-input Goz fold.

    KEY_FOLD_BLOCK(aGozLaneA, 0U, aGozLaneB, 0U, aFinalLaneB + W_KEY, 0U);

    KEY_FOLD_BLOCK(aGozLaneC, 0U, aGozLaneD, 0U, aFinalLaneB + W_KEY, 1U);

    KEY_FOLD_BLOCK(aGozLaneA, 1U, aGozLaneC, 1U, aFinalLaneB + W_KEY, 2U);

    KEY_FOLD_BLOCK(aGozLaneB, 1U, aGozLaneD, 1U, aFinalLaneB + W_KEY, 3U);


    // Grow input C — balanced 512-byte fold graph.

    // Mu — eight 512-byte blocks per lane.

    // Mu A[0]: aCrystalLaneC[58] + aCrystalLaneA[2].
    KEY_FOLD_BLOCK(aCrystalLaneC, 58U, aCrystalLaneA, 2U, aMuLaneA, 0U);

    // Mu A[1]: aCrystalLaneD[23] + aEarthLaneA[12].
    KEY_FOLD_BLOCK(aCrystalLaneD, 23U, aEarthLaneA, 12U, aMuLaneA, 1U);

    // Mu A[2]: aEarthLaneC[32] + aEarthLaneD[57].
    KEY_FOLD_BLOCK(aEarthLaneC, 32U, aEarthLaneD, 57U, aMuLaneA, 2U);

    // Mu A[3]: aEarthLaneC[12] + aCrystalLaneC[10].
    KEY_FOLD_BLOCK(aEarthLaneC, 12U, aCrystalLaneC, 10U, aMuLaneA, 3U);

    // Mu A[4]: aEarthLaneB[41] + aCrystalLaneB[57].
    KEY_FOLD_BLOCK(aEarthLaneB, 41U, aCrystalLaneB, 57U, aMuLaneA, 4U);

    // Mu A[5]: aCrystalLaneD[3] + aCrystalLaneA[28].
    KEY_FOLD_BLOCK(aCrystalLaneD, 3U, aCrystalLaneA, 28U, aMuLaneA, 5U);

    // Mu A[6]: aEarthLaneD[21] + aEarthLaneB[61].
    KEY_FOLD_BLOCK(aEarthLaneD, 21U, aEarthLaneB, 61U, aMuLaneA, 6U);

    // Mu A[7]: aEarthLaneA[54] + aCrystalLaneB[13].
    KEY_FOLD_BLOCK(aEarthLaneA, 54U, aCrystalLaneB, 13U, aMuLaneA, 7U);

    // Mu B[0]: aCrystalLaneC[14] + aEarthLaneD[47].
    KEY_FOLD_BLOCK(aCrystalLaneC, 14U, aEarthLaneD, 47U, aMuLaneB, 0U);

    // Mu B[1]: aEarthLaneA[42] + aEarthLaneB[21].
    KEY_FOLD_BLOCK(aEarthLaneA, 42U, aEarthLaneB, 21U, aMuLaneB, 1U);

    // Mu B[2]: aEarthLaneC[44] + aCrystalLaneA[42].
    KEY_FOLD_BLOCK(aEarthLaneC, 44U, aCrystalLaneA, 42U, aMuLaneB, 2U);

    // Mu B[3]: aEarthLaneB[55] + aEarthLaneD[49].
    KEY_FOLD_BLOCK(aEarthLaneB, 55U, aEarthLaneD, 49U, aMuLaneB, 3U);

    // Mu B[4]: aEarthLaneA[8] + aEarthLaneC[10].
    KEY_FOLD_BLOCK(aEarthLaneA, 8U, aEarthLaneC, 10U, aMuLaneB, 4U);

    // Mu B[5]: aCrystalLaneA[40] + aCrystalLaneD[27].
    KEY_FOLD_BLOCK(aCrystalLaneA, 40U, aCrystalLaneD, 27U, aMuLaneB, 5U);

    // Mu B[6]: aCrystalLaneB[29] + aCrystalLaneC[40].
    KEY_FOLD_BLOCK(aCrystalLaneB, 29U, aCrystalLaneC, 40U, aMuLaneB, 6U);

    // Mu B[7]: aCrystalLaneB[23] + aCrystalLaneD[51].
    KEY_FOLD_BLOCK(aCrystalLaneB, 23U, aCrystalLaneD, 51U, aMuLaneB, 7U);

    // Mu C[0]: aCrystalLaneC[36] + aCrystalLaneD[61].
    KEY_FOLD_BLOCK(aCrystalLaneC, 36U, aCrystalLaneD, 61U, aMuLaneC, 0U);

    // Mu C[1]: aEarthLaneA[20] + aEarthLaneB[19].
    KEY_FOLD_BLOCK(aEarthLaneA, 20U, aEarthLaneB, 19U, aMuLaneC, 1U);

    // Mu C[2]: aCrystalLaneA[24] + aCrystalLaneB[21].
    KEY_FOLD_BLOCK(aCrystalLaneA, 24U, aCrystalLaneB, 21U, aMuLaneC, 2U);

    // Mu C[3]: aEarthLaneD[9] + aEarthLaneC[38].
    KEY_FOLD_BLOCK(aEarthLaneD, 9U, aEarthLaneC, 38U, aMuLaneC, 3U);

    // Mu C[4]: aCrystalLaneB[55] + aEarthLaneB[47].
    KEY_FOLD_BLOCK(aCrystalLaneB, 55U, aEarthLaneB, 47U, aMuLaneC, 4U);

    // Mu C[5]: aCrystalLaneC[48] + aCrystalLaneD[63].
    KEY_FOLD_BLOCK(aCrystalLaneC, 48U, aCrystalLaneD, 63U, aMuLaneC, 5U);

    // Mu C[6]: aCrystalLaneA[48] + aEarthLaneA[14].
    KEY_FOLD_BLOCK(aCrystalLaneA, 48U, aEarthLaneA, 14U, aMuLaneC, 6U);

    // Mu C[7]: aEarthLaneD[29] + aEarthLaneC[14].
    KEY_FOLD_BLOCK(aEarthLaneD, 29U, aEarthLaneC, 14U, aMuLaneC, 7U);

    // Mu D[0]: aEarthLaneD[25] + aCrystalLaneB[35].
    KEY_FOLD_BLOCK(aEarthLaneD, 25U, aCrystalLaneB, 35U, aMuLaneD, 0U);

    // Mu D[1]: aEarthLaneC[2] + aCrystalLaneD[35].
    KEY_FOLD_BLOCK(aEarthLaneC, 2U, aCrystalLaneD, 35U, aMuLaneD, 1U);

    // Mu D[2]: aEarthLaneC[42] + aCrystalLaneA[10].
    KEY_FOLD_BLOCK(aEarthLaneC, 42U, aCrystalLaneA, 10U, aMuLaneD, 2U);

    // Mu D[3]: aEarthLaneD[59] + aCrystalLaneC[20].
    KEY_FOLD_BLOCK(aEarthLaneD, 59U, aCrystalLaneC, 20U, aMuLaneD, 3U);

    // Mu D[4]: aCrystalLaneC[16] + aCrystalLaneD[25].
    KEY_FOLD_BLOCK(aCrystalLaneC, 16U, aCrystalLaneD, 25U, aMuLaneD, 4U);

    // Mu D[5]: aEarthLaneA[40] + aEarthLaneB[7].
    KEY_FOLD_BLOCK(aEarthLaneA, 40U, aEarthLaneB, 7U, aMuLaneD, 5U);

    // Mu D[6]: aEarthLaneA[46] + aEarthLaneB[15].
    KEY_FOLD_BLOCK(aEarthLaneA, 46U, aEarthLaneB, 15U, aMuLaneD, 6U);

    // Mu D[7]: aCrystalLaneA[56] + aCrystalLaneB[61].
    KEY_FOLD_BLOCK(aCrystalLaneA, 56U, aCrystalLaneB, 61U, aMuLaneD, 7U);

    // Lel — four 512-byte blocks per lane.

    // Lel A[0]: aMuLaneC[7] + aMuLaneB[7].
    KEY_FOLD_BLOCK(aMuLaneC, 7U, aMuLaneB, 7U, aLelLaneA, 0U);

    // Lel A[1]: aMuLaneD[0] + aMuLaneA[3].
    KEY_FOLD_BLOCK(aMuLaneD, 0U, aMuLaneA, 3U, aLelLaneA, 1U);

    // Lel A[2]: aMuLaneD[7] + aMuLaneB[1].
    KEY_FOLD_BLOCK(aMuLaneD, 7U, aMuLaneB, 1U, aLelLaneA, 2U);

    // Lel A[3]: aMuLaneC[0] + aMuLaneA[7].
    KEY_FOLD_BLOCK(aMuLaneC, 0U, aMuLaneA, 7U, aLelLaneA, 3U);

    // Lel B[0]: aMuLaneC[4] + aMuLaneD[3].
    KEY_FOLD_BLOCK(aMuLaneC, 4U, aMuLaneD, 3U, aLelLaneB, 0U);

    // Lel B[1]: aMuLaneB[4] + aMuLaneC[2].
    KEY_FOLD_BLOCK(aMuLaneB, 4U, aMuLaneC, 2U, aLelLaneB, 1U);

    // Lel B[2]: aMuLaneD[5] + aMuLaneA[0].
    KEY_FOLD_BLOCK(aMuLaneD, 5U, aMuLaneA, 0U, aLelLaneB, 2U);

    // Lel B[3]: aMuLaneA[5] + aMuLaneB[6].
    KEY_FOLD_BLOCK(aMuLaneA, 5U, aMuLaneB, 6U, aLelLaneB, 3U);

    // Lel C[0]: aMuLaneB[3] + aMuLaneD[2].
    KEY_FOLD_BLOCK(aMuLaneB, 3U, aMuLaneD, 2U, aLelLaneC, 0U);

    // Lel C[1]: aMuLaneA[2] + aMuLaneC[5].
    KEY_FOLD_BLOCK(aMuLaneA, 2U, aMuLaneC, 5U, aLelLaneC, 1U);

    // Lel C[2]: aMuLaneB[0] + aMuLaneC[6].
    KEY_FOLD_BLOCK(aMuLaneB, 0U, aMuLaneC, 6U, aLelLaneC, 2U);

    // Lel C[3]: aMuLaneA[6] + aMuLaneD[4].
    KEY_FOLD_BLOCK(aMuLaneA, 6U, aMuLaneD, 4U, aLelLaneC, 3U);

    // Lel D[0]: aMuLaneC[1] + aMuLaneB[5].
    KEY_FOLD_BLOCK(aMuLaneC, 1U, aMuLaneB, 5U, aLelLaneD, 0U);

    // Lel D[1]: aMuLaneA[4] + aMuLaneD[1].
    KEY_FOLD_BLOCK(aMuLaneA, 4U, aMuLaneD, 1U, aLelLaneD, 1U);

    // Lel D[2]: aMuLaneB[2] + aMuLaneA[1].
    KEY_FOLD_BLOCK(aMuLaneB, 2U, aMuLaneA, 1U, aLelLaneD, 2U);

    // Lel D[3]: aMuLaneD[6] + aMuLaneC[3].
    KEY_FOLD_BLOCK(aMuLaneD, 6U, aMuLaneC, 3U, aLelLaneD, 3U);

    // Goz — two 512-byte blocks per lane.

    // Goz A[0]: aLelLaneA[1] + aLelLaneD[0].
    KEY_FOLD_BLOCK(aLelLaneA, 1U, aLelLaneD, 0U, aGozLaneA, 0U);

    // Goz A[1]: aLelLaneB[1] + aLelLaneC[3].
    KEY_FOLD_BLOCK(aLelLaneB, 1U, aLelLaneC, 3U, aGozLaneA, 1U);

    // Goz B[0]: aLelLaneA[3] + aLelLaneC[0].
    KEY_FOLD_BLOCK(aLelLaneA, 3U, aLelLaneC, 0U, aGozLaneB, 0U);

    // Goz B[1]: aLelLaneB[3] + aLelLaneD[3].
    KEY_FOLD_BLOCK(aLelLaneB, 3U, aLelLaneD, 3U, aGozLaneB, 1U);

    // Goz C[0]: aLelLaneD[2] + aLelLaneB[0].
    KEY_FOLD_BLOCK(aLelLaneD, 2U, aLelLaneB, 0U, aGozLaneC, 0U);

    // Goz C[1]: aLelLaneA[2] + aLelLaneC[1].
    KEY_FOLD_BLOCK(aLelLaneA, 2U, aLelLaneC, 1U, aGozLaneC, 1U);

    // Goz D[0]: aLelLaneA[0] + aLelLaneB[2].
    KEY_FOLD_BLOCK(aLelLaneA, 0U, aLelLaneB, 2U, aGozLaneD, 0U);

    // Goz D[1]: aLelLaneD[1] + aLelLaneC[2].
    KEY_FOLD_BLOCK(aLelLaneD, 1U, aLelLaneC, 2U, aGozLaneD, 1U);

    // Key source memberships.
    // Block 0: Earth={A:2, B:2, C:2, D:2} Crystal={A:2, B:2, C:2, D:2}.
    // Quarters: Earth={A:1/3, B:1/3, C:0/2, D:1/3} Crystal={A:2/0, B:2/0, C:0/2, D:1/3}.
    // Block 1: Earth={A:2, B:2, C:2, D:2} Crystal={A:2, B:2, C:2, D:2}.
    // Quarters: Earth={A:0/2, B:2/0, C:2/0, D:3/1} Crystal={A:2/0, B:3/1, C:1/3, D:1/3}.
    // Block 2: Earth={A:2, B:2, C:2, D:2} Crystal={A:2, B:2, C:2, D:2}.
    // Quarters: Earth={A:0/2, B:3/1, C:0/2, D:1/3} Crystal={A:1/3, B:1/3, C:1/3, D:1/3}.
    // Block 3: Earth={A:2, B:2, C:2, D:2} Crystal={A:2, B:2, C:2, D:2}.
    // Quarters: Earth={A:2/0, B:0/2, C:2/0, D:0/2} Crystal={A:1/3, B:1/3, C:2/0, D:0/2}.

    // Key — fixed two-input Goz fold.

    KEY_FOLD_BLOCK(aGozLaneA, 0U, aGozLaneB, 0U, aFinalLaneC + W_KEY, 0U);

    KEY_FOLD_BLOCK(aGozLaneC, 0U, aGozLaneD, 0U, aFinalLaneC + W_KEY, 1U);

    KEY_FOLD_BLOCK(aGozLaneA, 1U, aGozLaneC, 1U, aFinalLaneC + W_KEY, 2U);

    KEY_FOLD_BLOCK(aGozLaneB, 1U, aGozLaneD, 1U, aFinalLaneC + W_KEY, 3U);


    // Grow input D — balanced 512-byte fold graph.

    // Mu — eight 512-byte blocks per lane.

    // Mu A[0]: aEarthLaneD[43] + aEarthLaneC[18].
    KEY_FOLD_BLOCK(aEarthLaneD, 43U, aEarthLaneC, 18U, aMuLaneA, 0U);

    // Mu A[1]: aEarthLaneC[52] + aCrystalLaneA[22].
    KEY_FOLD_BLOCK(aEarthLaneC, 52U, aCrystalLaneA, 22U, aMuLaneA, 1U);

    // Mu A[2]: aCrystalLaneD[31] + aEarthLaneB[3].
    KEY_FOLD_BLOCK(aCrystalLaneD, 31U, aEarthLaneB, 3U, aMuLaneA, 2U);

    // Mu A[3]: aEarthLaneD[35] + aCrystalLaneC[6].
    KEY_FOLD_BLOCK(aEarthLaneD, 35U, aCrystalLaneC, 6U, aMuLaneA, 3U);

    // Mu A[4]: aCrystalLaneC[46] + aCrystalLaneA[46].
    KEY_FOLD_BLOCK(aCrystalLaneC, 46U, aCrystalLaneA, 46U, aMuLaneA, 4U);

    // Mu A[5]: aEarthLaneB[37] + aEarthLaneA[28].
    KEY_FOLD_BLOCK(aEarthLaneB, 37U, aEarthLaneA, 28U, aMuLaneA, 5U);

    // Mu A[6]: aCrystalLaneD[7] + aCrystalLaneB[45].
    KEY_FOLD_BLOCK(aCrystalLaneD, 7U, aCrystalLaneB, 45U, aMuLaneA, 6U);

    // Mu A[7]: aCrystalLaneB[63] + aEarthLaneA[6].
    KEY_FOLD_BLOCK(aCrystalLaneB, 63U, aEarthLaneA, 6U, aMuLaneA, 7U);

    // Mu B[0]: aEarthLaneC[20] + aEarthLaneA[44].
    KEY_FOLD_BLOCK(aEarthLaneC, 20U, aEarthLaneA, 44U, aMuLaneB, 0U);

    // Mu B[1]: aCrystalLaneA[26] + aEarthLaneD[33].
    KEY_FOLD_BLOCK(aCrystalLaneA, 26U, aEarthLaneD, 33U, aMuLaneB, 1U);

    // Mu B[2]: aEarthLaneC[30] + aEarthLaneB[1].
    KEY_FOLD_BLOCK(aEarthLaneC, 30U, aEarthLaneB, 1U, aMuLaneB, 2U);

    // Mu B[3]: aCrystalLaneC[4] + aCrystalLaneD[15].
    KEY_FOLD_BLOCK(aCrystalLaneC, 4U, aCrystalLaneD, 15U, aMuLaneB, 3U);

    // Mu B[4]: aCrystalLaneA[58] + aCrystalLaneB[31].
    KEY_FOLD_BLOCK(aCrystalLaneA, 58U, aCrystalLaneB, 31U, aMuLaneB, 4U);

    // Mu B[5]: aCrystalLaneD[17] + aCrystalLaneC[24].
    KEY_FOLD_BLOCK(aCrystalLaneD, 17U, aCrystalLaneC, 24U, aMuLaneB, 5U);

    // Mu B[6]: aCrystalLaneB[1] + aEarthLaneB[29].
    KEY_FOLD_BLOCK(aCrystalLaneB, 1U, aEarthLaneB, 29U, aMuLaneB, 6U);

    // Mu B[7]: aEarthLaneD[15] + aEarthLaneA[0].
    KEY_FOLD_BLOCK(aEarthLaneD, 15U, aEarthLaneA, 0U, aMuLaneB, 7U);

    // Mu C[0]: aEarthLaneD[1] + aCrystalLaneB[53].
    KEY_FOLD_BLOCK(aEarthLaneD, 1U, aCrystalLaneB, 53U, aMuLaneC, 0U);

    // Mu C[1]: aCrystalLaneA[62] + aCrystalLaneC[62].
    KEY_FOLD_BLOCK(aCrystalLaneA, 62U, aCrystalLaneC, 62U, aMuLaneC, 1U);

    // Mu C[2]: aCrystalLaneB[59] + aEarthLaneC[50].
    KEY_FOLD_BLOCK(aCrystalLaneB, 59U, aEarthLaneC, 50U, aMuLaneC, 2U);

    // Mu C[3]: aCrystalLaneC[56] + aCrystalLaneD[57].
    KEY_FOLD_BLOCK(aCrystalLaneC, 56U, aCrystalLaneD, 57U, aMuLaneC, 3U);

    // Mu C[4]: aCrystalLaneD[53] + aEarthLaneB[33].
    KEY_FOLD_BLOCK(aCrystalLaneD, 53U, aEarthLaneB, 33U, aMuLaneC, 4U);

    // Mu C[5]: aCrystalLaneA[34] + aEarthLaneB[57].
    KEY_FOLD_BLOCK(aCrystalLaneA, 34U, aEarthLaneB, 57U, aMuLaneC, 5U);

    // Mu C[6]: aEarthLaneA[38] + aEarthLaneC[24].
    KEY_FOLD_BLOCK(aEarthLaneA, 38U, aEarthLaneC, 24U, aMuLaneC, 6U);

    // Mu C[7]: aEarthLaneD[37] + aEarthLaneA[60].
    KEY_FOLD_BLOCK(aEarthLaneD, 37U, aEarthLaneA, 60U, aMuLaneC, 7U);

    // Mu D[0]: aEarthLaneC[48] + aCrystalLaneC[34].
    KEY_FOLD_BLOCK(aEarthLaneC, 48U, aCrystalLaneC, 34U, aMuLaneD, 0U);

    // Mu D[1]: aEarthLaneB[17] + aEarthLaneA[16].
    KEY_FOLD_BLOCK(aEarthLaneB, 17U, aEarthLaneA, 16U, aMuLaneD, 1U);

    // Mu D[2]: aCrystalLaneB[17] + aEarthLaneD[3].
    KEY_FOLD_BLOCK(aCrystalLaneB, 17U, aEarthLaneD, 3U, aMuLaneD, 2U);

    // Mu D[3]: aCrystalLaneC[26] + aEarthLaneC[60].
    KEY_FOLD_BLOCK(aCrystalLaneC, 26U, aEarthLaneC, 60U, aMuLaneD, 3U);

    // Mu D[4]: aCrystalLaneD[41] + aCrystalLaneA[0].
    KEY_FOLD_BLOCK(aCrystalLaneD, 41U, aCrystalLaneA, 0U, aMuLaneD, 4U);

    // Mu D[5]: aEarthLaneA[58] + aEarthLaneB[49].
    KEY_FOLD_BLOCK(aEarthLaneA, 58U, aEarthLaneB, 49U, aMuLaneD, 5U);

    // Mu D[6]: aCrystalLaneB[25] + aCrystalLaneD[47].
    KEY_FOLD_BLOCK(aCrystalLaneB, 25U, aCrystalLaneD, 47U, aMuLaneD, 6U);

    // Mu D[7]: aCrystalLaneA[4] + aEarthLaneD[11].
    KEY_FOLD_BLOCK(aCrystalLaneA, 4U, aEarthLaneD, 11U, aMuLaneD, 7U);

    // Lel — four 512-byte blocks per lane.

    // Lel A[0]: aMuLaneD[6] + aMuLaneC[7].
    KEY_FOLD_BLOCK(aMuLaneD, 6U, aMuLaneC, 7U, aLelLaneA, 0U);

    // Lel A[1]: aMuLaneA[2] + aMuLaneC[1].
    KEY_FOLD_BLOCK(aMuLaneA, 2U, aMuLaneC, 1U, aLelLaneA, 1U);

    // Lel A[2]: aMuLaneB[1] + aMuLaneA[7].
    KEY_FOLD_BLOCK(aMuLaneB, 1U, aMuLaneA, 7U, aLelLaneA, 2U);

    // Lel A[3]: aMuLaneB[7] + aMuLaneD[0].
    KEY_FOLD_BLOCK(aMuLaneB, 7U, aMuLaneD, 0U, aLelLaneA, 3U);

    // Lel B[0]: aMuLaneB[4] + aMuLaneA[0].
    KEY_FOLD_BLOCK(aMuLaneB, 4U, aMuLaneA, 0U, aLelLaneB, 0U);

    // Lel B[1]: aMuLaneD[3] + aMuLaneC[4].
    KEY_FOLD_BLOCK(aMuLaneD, 3U, aMuLaneC, 4U, aLelLaneB, 1U);

    // Lel B[2]: aMuLaneB[0] + aMuLaneD[2].
    KEY_FOLD_BLOCK(aMuLaneB, 0U, aMuLaneD, 2U, aLelLaneB, 2U);

    // Lel B[3]: aMuLaneA[5] + aMuLaneC[2].
    KEY_FOLD_BLOCK(aMuLaneA, 5U, aMuLaneC, 2U, aLelLaneB, 3U);

    // Lel C[0]: aMuLaneB[2] + aMuLaneA[4].
    KEY_FOLD_BLOCK(aMuLaneB, 2U, aMuLaneA, 4U, aLelLaneC, 0U);

    // Lel C[1]: aMuLaneC[6] + aMuLaneD[4].
    KEY_FOLD_BLOCK(aMuLaneC, 6U, aMuLaneD, 4U, aLelLaneC, 1U);

    // Lel C[2]: aMuLaneB[3] + aMuLaneD[7].
    KEY_FOLD_BLOCK(aMuLaneB, 3U, aMuLaneD, 7U, aLelLaneC, 2U);

    // Lel C[3]: aMuLaneA[1] + aMuLaneC[0].
    KEY_FOLD_BLOCK(aMuLaneA, 1U, aMuLaneC, 0U, aLelLaneC, 3U);

    // Lel D[0]: aMuLaneC[3] + aMuLaneD[5].
    KEY_FOLD_BLOCK(aMuLaneC, 3U, aMuLaneD, 5U, aLelLaneD, 0U);

    // Lel D[1]: aMuLaneB[5] + aMuLaneD[1].
    KEY_FOLD_BLOCK(aMuLaneB, 5U, aMuLaneD, 1U, aLelLaneD, 1U);

    // Lel D[2]: aMuLaneC[5] + aMuLaneA[6].
    KEY_FOLD_BLOCK(aMuLaneC, 5U, aMuLaneA, 6U, aLelLaneD, 2U);

    // Lel D[3]: aMuLaneA[3] + aMuLaneB[6].
    KEY_FOLD_BLOCK(aMuLaneA, 3U, aMuLaneB, 6U, aLelLaneD, 3U);

    // Goz — two 512-byte blocks per lane.

    // Goz A[0]: aLelLaneB[3] + aLelLaneC[2].
    KEY_FOLD_BLOCK(aLelLaneB, 3U, aLelLaneC, 2U, aGozLaneA, 0U);

    // Goz A[1]: aLelLaneA[3] + aLelLaneD[2].
    KEY_FOLD_BLOCK(aLelLaneA, 3U, aLelLaneD, 2U, aGozLaneA, 1U);

    // Goz B[0]: aLelLaneC[0] + aLelLaneA[0].
    KEY_FOLD_BLOCK(aLelLaneC, 0U, aLelLaneA, 0U, aGozLaneB, 0U);

    // Goz B[1]: aLelLaneB[0] + aLelLaneD[0].
    KEY_FOLD_BLOCK(aLelLaneB, 0U, aLelLaneD, 0U, aGozLaneB, 1U);

    // Goz C[0]: aLelLaneA[1] + aLelLaneB[2].
    KEY_FOLD_BLOCK(aLelLaneA, 1U, aLelLaneB, 2U, aGozLaneC, 0U);

    // Goz C[1]: aLelLaneD[3] + aLelLaneC[1].
    KEY_FOLD_BLOCK(aLelLaneD, 3U, aLelLaneC, 1U, aGozLaneC, 1U);

    // Goz D[0]: aLelLaneA[2] + aLelLaneB[1].
    KEY_FOLD_BLOCK(aLelLaneA, 2U, aLelLaneB, 1U, aGozLaneD, 0U);

    // Goz D[1]: aLelLaneD[1] + aLelLaneC[3].
    KEY_FOLD_BLOCK(aLelLaneD, 1U, aLelLaneC, 3U, aGozLaneD, 1U);

    // Key source memberships.
    // Block 0: Earth={A:2, B:2, C:2, D:2} Crystal={A:2, B:2, C:2, D:2}.
    // Quarters: Earth={A:1/3, B:2/0, C:3/1, D:0/2} Crystal={A:0/2, B:3/1, C:0/2, D:0/2}.
    // Block 1: Earth={A:2, B:2, C:2, D:2} Crystal={A:2, B:2, C:2, D:2}.
    // Quarters: Earth={A:2/0, B:0/2, C:1/3, D:0/2} Crystal={A:3/1, B:1/3, C:3/1, D:1/3}.
    // Block 2: Earth={A:2, B:2, C:2, D:2} Crystal={A:2, B:2, C:2, D:2}.
    // Quarters: Earth={A:0/2, B:3/1, C:3/1, D:0/2} Crystal={A:2/0, B:2/0, C:2/0, D:0/2}.
    // Block 3: Earth={A:2, B:2, C:2, D:2} Crystal={A:2, B:2, C:2, D:2}.
    // Quarters: Earth={A:3/1, B:3/1, C:1/3, D:2/0} Crystal={A:3/1, B:1/3, C:3/1, D:3/1}.

    // Key — fixed two-input Goz fold.

    KEY_FOLD_BLOCK(aGozLaneA, 0U, aGozLaneB, 0U, aFinalLaneD + W_KEY, 0U);

    KEY_FOLD_BLOCK(aGozLaneC, 0U, aGozLaneD, 0U, aFinalLaneD + W_KEY, 1U);

    KEY_FOLD_BLOCK(aGozLaneA, 1U, aGozLaneC, 1U, aFinalLaneD + W_KEY, 2U);

    KEY_FOLD_BLOCK(aGozLaneB, 1U, aGozLaneD, 1U, aFinalLaneD + W_KEY, 3U);

}
