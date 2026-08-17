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
    KEY_FOLD_BLOCK(aCrystalLaneA, 21U, 153U, aCrystalLaneC, 51U, 124U, aMuLaneA, 0U);

    // Mu A[1]: aCrystalLaneA[5] + aEarthLaneA[19].
    KEY_FOLD_BLOCK(aCrystalLaneA, 5U, 248U, aEarthLaneA, 19U, 215U, aMuLaneA, 1U);

    // Mu A[2]: aCrystalLaneC[59] + aCrystalLaneB[12].
    KEY_FOLD_BLOCK(aCrystalLaneC, 59U, 66U, aCrystalLaneB, 12U, 419U, aMuLaneA, 2U);

    // Mu A[3]: aEarthLaneA[27] + aCrystalLaneB[8].
    KEY_FOLD_BLOCK(aEarthLaneA, 27U, 294U, aCrystalLaneB, 8U, 39U, aMuLaneA, 3U);

    // Mu A[4]: aEarthLaneD[36] + aCrystalLaneD[30].
    KEY_FOLD_BLOCK(aEarthLaneD, 36U, 60U, aCrystalLaneD, 30U, 80U, aMuLaneA, 4U);

    // Mu A[5]: aEarthLaneB[32] + aEarthLaneC[29].
    KEY_FOLD_BLOCK(aEarthLaneB, 32U, 63U, aEarthLaneC, 29U, 390U, aMuLaneA, 5U);

    // Mu A[6]: aCrystalLaneD[28] + aEarthLaneD[32].
    KEY_FOLD_BLOCK(aCrystalLaneD, 28U, 6U, aEarthLaneD, 32U, 236U, aMuLaneA, 6U);

    // Mu A[7]: aEarthLaneB[52] + aEarthLaneC[23].
    KEY_FOLD_BLOCK(aEarthLaneB, 52U, 158U, aEarthLaneC, 23U, 120U, aMuLaneA, 7U);

    // Mu B[0]: aEarthLaneA[1] + aEarthLaneB[50].
    KEY_FOLD_BLOCK(aEarthLaneA, 1U, 91U, aEarthLaneB, 50U, 20U, aMuLaneB, 0U);

    // Mu B[1]: aCrystalLaneC[25] + aEarthLaneA[63].
    KEY_FOLD_BLOCK(aCrystalLaneC, 25U, 492U, aEarthLaneA, 63U, 339U, aMuLaneB, 1U);

    // Mu B[2]: aCrystalLaneC[31] + aEarthLaneC[9].
    KEY_FOLD_BLOCK(aCrystalLaneC, 31U, 11U, aEarthLaneC, 9U, 85U, aMuLaneB, 2U);

    // Mu B[3]: aEarthLaneD[8] + aCrystalLaneB[2].
    KEY_FOLD_BLOCK(aEarthLaneD, 8U, 262U, aCrystalLaneB, 2U, 333U, aMuLaneB, 3U);

    // Mu B[4]: aCrystalLaneD[62] + aEarthLaneD[14].
    KEY_FOLD_BLOCK(aCrystalLaneD, 62U, 452U, aEarthLaneD, 14U, 454U, aMuLaneB, 4U);

    // Mu B[5]: aEarthLaneB[12] + aEarthLaneC[51].
    KEY_FOLD_BLOCK(aEarthLaneB, 12U, 19U, aEarthLaneC, 51U, 160U, aMuLaneB, 5U);

    // Mu B[6]: aCrystalLaneD[0] + aCrystalLaneA[27].
    KEY_FOLD_BLOCK(aCrystalLaneD, 0U, 313U, aCrystalLaneA, 27U, 46U, aMuLaneB, 6U);

    // Mu B[7]: aCrystalLaneB[34] + aCrystalLaneA[63].
    KEY_FOLD_BLOCK(aCrystalLaneB, 34U, 62U, aCrystalLaneA, 63U, 29U, aMuLaneB, 7U);

    // Mu C[0]: aCrystalLaneB[40] + aEarthLaneD[42].
    KEY_FOLD_BLOCK(aCrystalLaneB, 40U, 498U, aEarthLaneD, 42U, 44U, aMuLaneC, 0U);

    // Mu C[1]: aCrystalLaneB[32] + aCrystalLaneC[61].
    KEY_FOLD_BLOCK(aCrystalLaneB, 32U, 172U, aCrystalLaneC, 61U, 472U, aMuLaneC, 1U);

    // Mu C[2]: aCrystalLaneA[39] + aEarthLaneC[39].
    KEY_FOLD_BLOCK(aCrystalLaneA, 39U, 419U, aEarthLaneC, 39U, 350U, aMuLaneC, 2U);

    // Mu C[3]: aEarthLaneA[43] + aEarthLaneB[28].
    KEY_FOLD_BLOCK(aEarthLaneA, 43U, 236U, aEarthLaneB, 28U, 216U, aMuLaneC, 3U);

    // Mu C[4]: aEarthLaneC[19] + aCrystalLaneA[47].
    KEY_FOLD_BLOCK(aEarthLaneC, 19U, 412U, aCrystalLaneA, 47U, 157U, aMuLaneC, 4U);

    // Mu C[5]: aCrystalLaneC[49] + aCrystalLaneD[36].
    KEY_FOLD_BLOCK(aCrystalLaneC, 49U, 399U, aCrystalLaneD, 36U, 459U, aMuLaneC, 5U);

    // Mu C[6]: aEarthLaneD[44] + aCrystalLaneD[10].
    KEY_FOLD_BLOCK(aEarthLaneD, 44U, 37U, aCrystalLaneD, 10U, 180U, aMuLaneC, 6U);

    // Mu C[7]: aEarthLaneA[39] + aEarthLaneB[22].
    KEY_FOLD_BLOCK(aEarthLaneA, 39U, 209U, aEarthLaneB, 22U, 311U, aMuLaneC, 7U);

    // Mu D[0]: aEarthLaneB[60] + aEarthLaneC[57].
    KEY_FOLD_BLOCK(aEarthLaneB, 60U, 193U, aEarthLaneC, 57U, 203U, aMuLaneD, 0U);

    // Mu D[1]: aCrystalLaneC[19] + aEarthLaneA[9].
    KEY_FOLD_BLOCK(aCrystalLaneC, 19U, 234U, aEarthLaneA, 9U, 380U, aMuLaneD, 1U);

    // Mu D[2]: aEarthLaneD[4] + aCrystalLaneD[56].
    KEY_FOLD_BLOCK(aEarthLaneD, 4U, 318U, aCrystalLaneD, 56U, 83U, aMuLaneD, 2U);

    // Mu D[3]: aCrystalLaneB[44] + aCrystalLaneA[7].
    KEY_FOLD_BLOCK(aCrystalLaneB, 44U, 309U, aCrystalLaneA, 7U, 482U, aMuLaneD, 3U);

    // Mu D[4]: aCrystalLaneC[23] + aEarthLaneA[61].
    KEY_FOLD_BLOCK(aCrystalLaneC, 23U, 23U, aEarthLaneA, 61U, 337U, aMuLaneD, 4U);

    // Mu D[5]: aCrystalLaneB[10] + aEarthLaneB[24].
    KEY_FOLD_BLOCK(aCrystalLaneB, 10U, 93U, aEarthLaneB, 24U, 268U, aMuLaneD, 5U);

    // Mu D[6]: aEarthLaneC[59] + aCrystalLaneD[32].
    KEY_FOLD_BLOCK(aEarthLaneC, 59U, 279U, aCrystalLaneD, 32U, 192U, aMuLaneD, 6U);

    // Mu D[7]: aCrystalLaneA[59] + aEarthLaneD[10].
    KEY_FOLD_BLOCK(aCrystalLaneA, 59U, 165U, aEarthLaneD, 10U, 498U, aMuLaneD, 7U);

    // Lel — four 512-byte blocks per lane.

    // Lel A[0]: aMuLaneD[7] + aMuLaneC[5].
    KEY_FOLD_BLOCK(aMuLaneD, 7U, 312U, aMuLaneC, 5U, 391U, aLelLaneA, 0U);

    // Lel A[1]: aMuLaneA[2] + aMuLaneB[0].
    KEY_FOLD_BLOCK(aMuLaneA, 2U, 256U, aMuLaneB, 0U, 308U, aLelLaneA, 1U);

    // Lel A[2]: aMuLaneA[7] + aMuLaneD[1].
    KEY_FOLD_BLOCK(aMuLaneA, 7U, 70U, aMuLaneD, 1U, 127U, aLelLaneA, 2U);

    // Lel A[3]: aMuLaneB[6] + aMuLaneC[0].
    KEY_FOLD_BLOCK(aMuLaneB, 6U, 72U, aMuLaneC, 0U, 230U, aLelLaneA, 3U);

    // Lel B[0]: aMuLaneA[5] + aMuLaneD[4].
    KEY_FOLD_BLOCK(aMuLaneA, 5U, 422U, aMuLaneD, 4U, 325U, aLelLaneB, 0U);

    // Lel B[1]: aMuLaneC[2] + aMuLaneD[2].
    KEY_FOLD_BLOCK(aMuLaneC, 2U, 318U, aMuLaneD, 2U, 457U, aLelLaneB, 1U);

    // Lel B[2]: aMuLaneA[0] + aMuLaneB[3].
    KEY_FOLD_BLOCK(aMuLaneA, 0U, 262U, aMuLaneB, 3U, 78U, aLelLaneB, 2U);

    // Lel B[3]: aMuLaneC[7] + aMuLaneB[2].
    KEY_FOLD_BLOCK(aMuLaneC, 7U, 394U, aMuLaneB, 2U, 196U, aLelLaneB, 3U);

    // Lel C[0]: aMuLaneB[1] + aMuLaneC[4].
    KEY_FOLD_BLOCK(aMuLaneB, 1U, 387U, aMuLaneC, 4U, 125U, aLelLaneC, 0U);

    // Lel C[1]: aMuLaneD[3] + aMuLaneA[6].
    KEY_FOLD_BLOCK(aMuLaneD, 3U, 64U, aMuLaneA, 6U, 319U, aLelLaneC, 1U);

    // Lel C[2]: aMuLaneA[3] + aMuLaneB[5].
    KEY_FOLD_BLOCK(aMuLaneA, 3U, 294U, aMuLaneB, 5U, 67U, aLelLaneC, 2U);

    // Lel C[3]: aMuLaneC[1] + aMuLaneD[0].
    KEY_FOLD_BLOCK(aMuLaneC, 1U, 62U, aMuLaneD, 0U, 359U, aLelLaneC, 3U);

    // Lel D[0]: aMuLaneA[4] + aMuLaneD[5].
    KEY_FOLD_BLOCK(aMuLaneA, 4U, 76U, aMuLaneD, 5U, 297U, aLelLaneD, 0U);

    // Lel D[1]: aMuLaneB[4] + aMuLaneA[1].
    KEY_FOLD_BLOCK(aMuLaneB, 4U, 419U, aMuLaneA, 1U, 501U, aLelLaneD, 1U);

    // Lel D[2]: aMuLaneD[6] + aMuLaneC[3].
    KEY_FOLD_BLOCK(aMuLaneD, 6U, 383U, aMuLaneC, 3U, 38U, aLelLaneD, 2U);

    // Lel D[3]: aMuLaneC[6] + aMuLaneB[7].
    KEY_FOLD_BLOCK(aMuLaneC, 6U, 274U, aMuLaneB, 7U, 303U, aLelLaneD, 3U);

    // Goz — two 512-byte blocks per lane.

    // Goz A[0]: aLelLaneA[0] + aLelLaneC[2].
    KEY_FOLD_BLOCK(aLelLaneA, 0U, 241U, aLelLaneC, 2U, 187U, aGozLaneA, 0U);

    // Goz A[1]: aLelLaneB[2] + aLelLaneD[2].
    KEY_FOLD_BLOCK(aLelLaneB, 2U, 340U, aLelLaneD, 2U, 419U, aGozLaneA, 1U);

    // Goz B[0]: aLelLaneA[3] + aLelLaneB[0].
    KEY_FOLD_BLOCK(aLelLaneA, 3U, 69U, aLelLaneB, 0U, 32U, aGozLaneB, 0U);

    // Goz B[1]: aLelLaneD[0] + aLelLaneC[0].
    KEY_FOLD_BLOCK(aLelLaneD, 0U, 387U, aLelLaneC, 0U, 188U, aGozLaneB, 1U);

    // Goz C[0]: aLelLaneC[1] + aLelLaneB[3].
    KEY_FOLD_BLOCK(aLelLaneC, 1U, 430U, aLelLaneB, 3U, 309U, aGozLaneC, 0U);

    // Goz C[1]: aLelLaneD[3] + aLelLaneA[2].
    KEY_FOLD_BLOCK(aLelLaneD, 3U, 93U, aLelLaneA, 2U, 303U, aGozLaneC, 1U);

    // Goz D[0]: aLelLaneA[1] + aLelLaneB[1].
    KEY_FOLD_BLOCK(aLelLaneA, 1U, 215U, aLelLaneB, 1U, 507U, aGozLaneD, 0U);

    // Goz D[1]: aLelLaneC[3] + aLelLaneD[1].
    KEY_FOLD_BLOCK(aLelLaneC, 3U, 342U, aLelLaneD, 1U, 447U, aGozLaneD, 1U);

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

    KEY_FOLD_BLOCK(aGozLaneA, 0U, 166U, aGozLaneB, 0U, 58U, aFinalLaneA, 0U);

    KEY_FOLD_BLOCK(aGozLaneC, 0U, 208U, aGozLaneD, 0U, 25U, aFinalLaneA, 1U);

    KEY_FOLD_BLOCK(aGozLaneA, 1U, 484U, aGozLaneC, 1U, 254U, aFinalLaneA, 2U);

    KEY_FOLD_BLOCK(aGozLaneB, 1U, 235U, aGozLaneD, 1U, 8U, aFinalLaneA, 3U);


    // Grow input B — balanced 512-byte fold graph.

    // Mu — eight 512-byte blocks per lane.

    // Mu A[0]: aCrystalLaneC[35] + aEarthLaneD[26].
    KEY_FOLD_BLOCK(aCrystalLaneC, 35U, 79U, aEarthLaneD, 26U, 144U, aMuLaneA, 0U);

    // Mu A[1]: aCrystalLaneD[20] + aEarthLaneC[21].
    KEY_FOLD_BLOCK(aCrystalLaneD, 20U, 490U, aEarthLaneC, 21U, 315U, aMuLaneA, 1U);

    // Mu A[2]: aCrystalLaneA[13] + aCrystalLaneC[1].
    KEY_FOLD_BLOCK(aCrystalLaneA, 13U, 174U, aCrystalLaneC, 1U, 244U, aMuLaneA, 2U);

    // Mu A[3]: aCrystalLaneB[26] + aCrystalLaneA[41].
    KEY_FOLD_BLOCK(aCrystalLaneB, 26U, 449U, aCrystalLaneA, 41U, 253U, aMuLaneA, 3U);

    // Mu A[4]: aCrystalLaneD[50] + aEarthLaneC[5].
    KEY_FOLD_BLOCK(aCrystalLaneD, 50U, 433U, aEarthLaneC, 5U, 231U, aMuLaneA, 4U);

    // Mu A[5]: aCrystalLaneB[0] + aEarthLaneD[46].
    KEY_FOLD_BLOCK(aCrystalLaneB, 0U, 232U, aEarthLaneD, 46U, 436U, aMuLaneA, 5U);

    // Mu A[6]: aEarthLaneA[33] + aEarthLaneB[26].
    KEY_FOLD_BLOCK(aEarthLaneA, 33U, 182U, aEarthLaneB, 26U, 341U, aMuLaneA, 6U);

    // Mu A[7]: aEarthLaneB[10] + aEarthLaneA[5].
    KEY_FOLD_BLOCK(aEarthLaneB, 10U, 133U, aEarthLaneA, 5U, 386U, aMuLaneA, 7U);

    // Mu B[0]: aEarthLaneC[61] + aCrystalLaneA[1].
    KEY_FOLD_BLOCK(aEarthLaneC, 61U, 447U, aCrystalLaneA, 1U, 5U, aMuLaneB, 0U);

    // Mu B[1]: aCrystalLaneB[48] + aCrystalLaneD[14].
    KEY_FOLD_BLOCK(aCrystalLaneB, 48U, 14U, aCrystalLaneD, 14U, 418U, aMuLaneB, 1U);

    // Mu B[2]: aCrystalLaneC[13] + aCrystalLaneA[37].
    KEY_FOLD_BLOCK(aCrystalLaneC, 13U, 273U, aCrystalLaneA, 37U, 245U, aMuLaneB, 2U);

    // Mu B[3]: aEarthLaneB[30] + aCrystalLaneB[36].
    KEY_FOLD_BLOCK(aEarthLaneB, 30U, 380U, aCrystalLaneB, 36U, 407U, aMuLaneB, 3U);

    // Mu B[4]: aEarthLaneB[40] + aEarthLaneD[16].
    KEY_FOLD_BLOCK(aEarthLaneB, 40U, 98U, aEarthLaneD, 16U, 224U, aMuLaneB, 4U);

    // Mu B[5]: aCrystalLaneC[37] + aEarthLaneA[25].
    KEY_FOLD_BLOCK(aCrystalLaneC, 37U, 454U, aEarthLaneA, 25U, 262U, aMuLaneB, 5U);

    // Mu B[6]: aEarthLaneA[55] + aEarthLaneD[18].
    KEY_FOLD_BLOCK(aEarthLaneA, 55U, 464U, aEarthLaneD, 18U, 257U, aMuLaneB, 6U);

    // Mu B[7]: aCrystalLaneD[18] + aEarthLaneC[35].
    KEY_FOLD_BLOCK(aCrystalLaneD, 18U, 42U, aEarthLaneC, 35U, 482U, aMuLaneB, 7U);

    // Mu C[0]: aEarthLaneD[52] + aEarthLaneC[55].
    KEY_FOLD_BLOCK(aEarthLaneD, 52U, 116U, aEarthLaneC, 55U, 23U, aMuLaneC, 0U);

    // Mu C[1]: aEarthLaneB[54] + aEarthLaneA[29].
    KEY_FOLD_BLOCK(aEarthLaneB, 54U, 149U, aEarthLaneA, 29U, 313U, aMuLaneC, 1U);

    // Mu C[2]: aCrystalLaneC[5] + aCrystalLaneA[23].
    KEY_FOLD_BLOCK(aCrystalLaneC, 5U, 494U, aCrystalLaneA, 23U, 371U, aMuLaneC, 2U);

    // Mu C[3]: aCrystalLaneA[35] + aCrystalLaneB[22].
    KEY_FOLD_BLOCK(aCrystalLaneA, 35U, 353U, aCrystalLaneB, 22U, 510U, aMuLaneC, 3U);

    // Mu C[4]: aEarthLaneB[56] + aEarthLaneA[13].
    KEY_FOLD_BLOCK(aEarthLaneB, 56U, 102U, aEarthLaneA, 13U, 25U, aMuLaneC, 4U);

    // Mu C[5]: aCrystalLaneC[55] + aCrystalLaneD[58].
    KEY_FOLD_BLOCK(aCrystalLaneC, 55U, 259U, aCrystalLaneD, 58U, 74U, aMuLaneC, 5U);

    // Mu C[6]: aCrystalLaneD[38] + aEarthLaneD[54].
    KEY_FOLD_BLOCK(aCrystalLaneD, 38U, 29U, aEarthLaneD, 54U, 474U, aMuLaneC, 6U);

    // Mu C[7]: aEarthLaneC[27] + aCrystalLaneB[50].
    KEY_FOLD_BLOCK(aEarthLaneC, 27U, 187U, aCrystalLaneB, 50U, 457U, aMuLaneC, 7U);

    // Mu D[0]: aCrystalLaneC[45] + aCrystalLaneA[61].
    KEY_FOLD_BLOCK(aCrystalLaneC, 45U, 505U, aCrystalLaneA, 61U, 371U, aMuLaneD, 0U);

    // Mu D[1]: aEarthLaneA[35] + aCrystalLaneC[29].
    KEY_FOLD_BLOCK(aEarthLaneA, 35U, 23U, aCrystalLaneC, 29U, 47U, aMuLaneD, 1U);

    // Mu D[2]: aCrystalLaneD[16] + aEarthLaneB[20].
    KEY_FOLD_BLOCK(aCrystalLaneD, 16U, 477U, aEarthLaneB, 20U, 220U, aMuLaneD, 2U);

    // Mu D[3]: aEarthLaneD[6] + aEarthLaneA[49].
    KEY_FOLD_BLOCK(aEarthLaneD, 6U, 67U, aEarthLaneA, 49U, 209U, aMuLaneD, 3U);

    // Mu D[4]: aEarthLaneC[15] + aCrystalLaneA[3].
    KEY_FOLD_BLOCK(aEarthLaneC, 15U, 85U, aCrystalLaneA, 3U, 173U, aMuLaneD, 4U);

    // Mu D[5]: aCrystalLaneB[28] + aEarthLaneC[43].
    KEY_FOLD_BLOCK(aCrystalLaneB, 28U, 491U, aEarthLaneC, 43U, 306U, aMuLaneD, 5U);

    // Mu D[6]: aEarthLaneB[58] + aCrystalLaneD[60].
    KEY_FOLD_BLOCK(aEarthLaneB, 58U, 409U, aCrystalLaneD, 60U, 496U, aMuLaneD, 6U);

    // Mu D[7]: aEarthLaneD[60] + aCrystalLaneB[52].
    KEY_FOLD_BLOCK(aEarthLaneD, 60U, 470U, aCrystalLaneB, 52U, 248U, aMuLaneD, 7U);

    // Lel — four 512-byte blocks per lane.

    // Lel A[0]: aMuLaneA[3] + aMuLaneB[5].
    KEY_FOLD_BLOCK(aMuLaneA, 3U, 312U, aMuLaneB, 5U, 364U, aLelLaneA, 0U);

    // Lel A[1]: aMuLaneC[1] + aMuLaneD[0].
    KEY_FOLD_BLOCK(aMuLaneC, 1U, 200U, aMuLaneD, 0U, 208U, aLelLaneA, 1U);

    // Lel A[2]: aMuLaneC[7] + aMuLaneD[6].
    KEY_FOLD_BLOCK(aMuLaneC, 7U, 303U, aMuLaneD, 6U, 305U, aLelLaneA, 2U);

    // Lel A[3]: aMuLaneA[7] + aMuLaneB[0].
    KEY_FOLD_BLOCK(aMuLaneA, 7U, 84U, aMuLaneB, 0U, 440U, aLelLaneA, 3U);

    // Lel B[0]: aMuLaneC[4] + aMuLaneA[0].
    KEY_FOLD_BLOCK(aMuLaneC, 4U, 343U, aMuLaneA, 0U, 482U, aLelLaneB, 0U);

    // Lel B[1]: aMuLaneD[3] + aMuLaneB[3].
    KEY_FOLD_BLOCK(aMuLaneD, 3U, 389U, aMuLaneB, 3U, 362U, aLelLaneB, 1U);

    // Lel B[2]: aMuLaneB[7] + aMuLaneA[5].
    KEY_FOLD_BLOCK(aMuLaneB, 7U, 252U, aMuLaneA, 5U, 252U, aLelLaneB, 2U);

    // Lel B[3]: aMuLaneD[2] + aMuLaneC[0].
    KEY_FOLD_BLOCK(aMuLaneD, 2U, 326U, aMuLaneC, 0U, 209U, aLelLaneB, 3U);

    // Lel C[0]: aMuLaneB[4] + aMuLaneC[3].
    KEY_FOLD_BLOCK(aMuLaneB, 4U, 510U, aMuLaneC, 3U, 318U, aLelLaneC, 0U);

    // Lel C[1]: aMuLaneA[6] + aMuLaneD[5].
    KEY_FOLD_BLOCK(aMuLaneA, 6U, 64U, aMuLaneD, 5U, 237U, aLelLaneC, 1U);

    // Lel C[2]: aMuLaneB[1] + aMuLaneD[4].
    KEY_FOLD_BLOCK(aMuLaneB, 1U, 146U, aMuLaneD, 4U, 501U, aLelLaneC, 2U);

    // Lel C[3]: aMuLaneC[2] + aMuLaneA[4].
    KEY_FOLD_BLOCK(aMuLaneC, 2U, 485U, aMuLaneA, 4U, 7U, aLelLaneC, 3U);

    // Lel D[0]: aMuLaneD[7] + aMuLaneC[5].
    KEY_FOLD_BLOCK(aMuLaneD, 7U, 242U, aMuLaneC, 5U, 104U, aLelLaneD, 0U);

    // Lel D[1]: aMuLaneA[2] + aMuLaneB[6].
    KEY_FOLD_BLOCK(aMuLaneA, 2U, 98U, aMuLaneB, 6U, 131U, aLelLaneD, 1U);

    // Lel D[2]: aMuLaneB[2] + aMuLaneC[6].
    KEY_FOLD_BLOCK(aMuLaneB, 2U, 94U, aMuLaneC, 6U, 224U, aLelLaneD, 2U);

    // Lel D[3]: aMuLaneA[1] + aMuLaneD[1].
    KEY_FOLD_BLOCK(aMuLaneA, 1U, 278U, aMuLaneD, 1U, 106U, aLelLaneD, 3U);

    // Goz — two 512-byte blocks per lane.

    // Goz A[0]: aLelLaneD[0] + aLelLaneA[3].
    KEY_FOLD_BLOCK(aLelLaneD, 0U, 300U, aLelLaneA, 3U, 405U, aGozLaneA, 0U);

    // Goz A[1]: aLelLaneC[2] + aLelLaneB[0].
    KEY_FOLD_BLOCK(aLelLaneC, 2U, 174U, aLelLaneB, 0U, 104U, aGozLaneA, 1U);

    // Goz B[0]: aLelLaneD[3] + aLelLaneC[0].
    KEY_FOLD_BLOCK(aLelLaneD, 3U, 372U, aLelLaneC, 0U, 382U, aGozLaneB, 0U);

    // Goz B[1]: aLelLaneB[3] + aLelLaneA[0].
    KEY_FOLD_BLOCK(aLelLaneB, 3U, 377U, aLelLaneA, 0U, 5U, aGozLaneB, 1U);

    // Goz C[0]: aLelLaneA[1] + aLelLaneB[2].
    KEY_FOLD_BLOCK(aLelLaneA, 1U, 299U, aLelLaneB, 2U, 153U, aGozLaneC, 0U);

    // Goz C[1]: aLelLaneD[2] + aLelLaneC[1].
    KEY_FOLD_BLOCK(aLelLaneD, 2U, 468U, aLelLaneC, 1U, 335U, aGozLaneC, 1U);

    // Goz D[0]: aLelLaneC[3] + aLelLaneB[1].
    KEY_FOLD_BLOCK(aLelLaneC, 3U, 481U, aLelLaneB, 1U, 237U, aGozLaneD, 0U);

    // Goz D[1]: aLelLaneA[2] + aLelLaneD[1].
    KEY_FOLD_BLOCK(aLelLaneA, 2U, 386U, aLelLaneD, 1U, 212U, aGozLaneD, 1U);

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

    KEY_FOLD_BLOCK(aGozLaneA, 0U, 335U, aGozLaneB, 0U, 407U, aFinalLaneB, 0U);

    KEY_FOLD_BLOCK(aGozLaneC, 0U, 420U, aGozLaneD, 0U, 476U, aFinalLaneB, 1U);

    KEY_FOLD_BLOCK(aGozLaneA, 1U, 120U, aGozLaneC, 1U, 483U, aFinalLaneB, 2U);

    KEY_FOLD_BLOCK(aGozLaneB, 1U, 362U, aGozLaneD, 1U, 97U, aFinalLaneB, 3U);


    // Grow input C — balanced 512-byte fold graph.

    // Mu — eight 512-byte blocks per lane.

    // Mu A[0]: aEarthLaneA[51] + aEarthLaneB[4].
    KEY_FOLD_BLOCK(aEarthLaneA, 51U, 461U, aEarthLaneB, 4U, 344U, aMuLaneA, 0U);

    // Mu A[1]: aCrystalLaneD[46] + aCrystalLaneC[11].
    KEY_FOLD_BLOCK(aCrystalLaneD, 46U, 119U, aCrystalLaneC, 11U, 324U, aMuLaneA, 1U);

    // Mu A[2]: aCrystalLaneA[17] + aEarthLaneC[33].
    KEY_FOLD_BLOCK(aCrystalLaneA, 17U, 142U, aEarthLaneC, 33U, 195U, aMuLaneA, 2U);

    // Mu A[3]: aEarthLaneB[48] + aEarthLaneA[21].
    KEY_FOLD_BLOCK(aEarthLaneB, 48U, 477U, aEarthLaneA, 21U, 300U, aMuLaneA, 3U);

    // Mu A[4]: aEarthLaneD[20] + aCrystalLaneC[43].
    KEY_FOLD_BLOCK(aEarthLaneD, 20U, 388U, aCrystalLaneC, 43U, 53U, aMuLaneA, 4U);

    // Mu A[5]: aCrystalLaneB[14] + aEarthLaneD[58].
    KEY_FOLD_BLOCK(aCrystalLaneB, 14U, 362U, aEarthLaneD, 58U, 147U, aMuLaneA, 5U);

    // Mu A[6]: aEarthLaneC[31] + aCrystalLaneB[42].
    KEY_FOLD_BLOCK(aEarthLaneC, 31U, 353U, aCrystalLaneB, 42U, 261U, aMuLaneA, 6U);

    // Mu A[7]: aCrystalLaneD[24] + aCrystalLaneA[29].
    KEY_FOLD_BLOCK(aCrystalLaneD, 24U, 75U, aCrystalLaneA, 29U, 303U, aMuLaneA, 7U);

    // Mu B[0]: aCrystalLaneD[26] + aCrystalLaneB[24].
    KEY_FOLD_BLOCK(aCrystalLaneD, 26U, 62U, aCrystalLaneB, 24U, 166U, aMuLaneB, 0U);

    // Mu B[1]: aEarthLaneB[34] + aCrystalLaneA[51].
    KEY_FOLD_BLOCK(aEarthLaneB, 34U, 384U, aCrystalLaneA, 51U, 443U, aMuLaneB, 1U);

    // Mu B[2]: aCrystalLaneB[56] + aCrystalLaneC[57].
    KEY_FOLD_BLOCK(aCrystalLaneB, 56U, 113U, aCrystalLaneC, 57U, 143U, aMuLaneB, 2U);

    // Mu B[3]: aCrystalLaneA[25] + aEarthLaneD[22].
    KEY_FOLD_BLOCK(aCrystalLaneA, 25U, 363U, aEarthLaneD, 22U, 245U, aMuLaneB, 3U);

    // Mu B[4]: aEarthLaneC[25] + aCrystalLaneD[2].
    KEY_FOLD_BLOCK(aEarthLaneC, 25U, 39U, aCrystalLaneD, 2U, 447U, aMuLaneB, 4U);

    // Mu B[5]: aEarthLaneB[46] + aEarthLaneA[41].
    KEY_FOLD_BLOCK(aEarthLaneB, 46U, 465U, aEarthLaneA, 41U, 161U, aMuLaneB, 5U);

    // Mu B[6]: aEarthLaneD[0] + aCrystalLaneC[47].
    KEY_FOLD_BLOCK(aEarthLaneD, 0U, 148U, aCrystalLaneC, 47U, 107U, aMuLaneB, 6U);

    // Mu B[7]: aEarthLaneA[11] + aEarthLaneC[49].
    KEY_FOLD_BLOCK(aEarthLaneA, 11U, 264U, aEarthLaneC, 49U, 135U, aMuLaneB, 7U);

    // Mu C[0]: aCrystalLaneB[20] + aCrystalLaneD[6].
    KEY_FOLD_BLOCK(aCrystalLaneB, 20U, 504U, aCrystalLaneD, 6U, 178U, aMuLaneC, 0U);

    // Mu C[1]: aCrystalLaneC[3] + aEarthLaneD[34].
    KEY_FOLD_BLOCK(aCrystalLaneC, 3U, 306U, aEarthLaneD, 34U, 409U, aMuLaneC, 1U);

    // Mu C[2]: aEarthLaneB[8] + aEarthLaneA[3].
    KEY_FOLD_BLOCK(aEarthLaneB, 8U, 242U, aEarthLaneA, 3U, 256U, aMuLaneC, 2U);

    // Mu C[3]: aEarthLaneD[48] + aEarthLaneC[17].
    KEY_FOLD_BLOCK(aEarthLaneD, 48U, 33U, aEarthLaneC, 17U, 184U, aMuLaneC, 3U);

    // Mu C[4]: aCrystalLaneA[57] + aEarthLaneC[3].
    KEY_FOLD_BLOCK(aCrystalLaneA, 57U, 193U, aEarthLaneC, 3U, 434U, aMuLaneC, 4U);

    // Mu C[5]: aEarthLaneA[17] + aEarthLaneB[44].
    KEY_FOLD_BLOCK(aEarthLaneA, 17U, 119U, aEarthLaneB, 44U, 216U, aMuLaneC, 5U);

    // Mu C[6]: aCrystalLaneA[49] + aCrystalLaneC[41].
    KEY_FOLD_BLOCK(aCrystalLaneA, 49U, 477U, aCrystalLaneC, 41U, 71U, aMuLaneC, 6U);

    // Mu C[7]: aCrystalLaneD[34] + aCrystalLaneB[38].
    KEY_FOLD_BLOCK(aCrystalLaneD, 34U, 213U, aCrystalLaneB, 38U, 158U, aMuLaneC, 7U);

    // Mu D[0]: aEarthLaneC[63] + aCrystalLaneC[7].
    KEY_FOLD_BLOCK(aEarthLaneC, 63U, 375U, aCrystalLaneC, 7U, 411U, aMuLaneD, 0U);

    // Mu D[1]: aCrystalLaneB[4] + aEarthLaneC[53].
    KEY_FOLD_BLOCK(aCrystalLaneB, 4U, 226U, aEarthLaneC, 53U, 35U, aMuLaneD, 1U);

    // Mu D[2]: aCrystalLaneA[43] + aCrystalLaneB[62].
    KEY_FOLD_BLOCK(aCrystalLaneA, 43U, 505U, aCrystalLaneB, 62U, 41U, aMuLaneD, 2U);

    // Mu D[3]: aEarthLaneD[50] + aCrystalLaneD[52].
    KEY_FOLD_BLOCK(aEarthLaneD, 50U, 460U, aCrystalLaneD, 52U, 358U, aMuLaneD, 3U);

    // Mu D[4]: aEarthLaneA[53] + aEarthLaneB[18].
    KEY_FOLD_BLOCK(aEarthLaneA, 53U, 189U, aEarthLaneB, 18U, 373U, aMuLaneD, 4U);

    // Mu D[5]: aCrystalLaneD[48] + aEarthLaneA[47].
    KEY_FOLD_BLOCK(aCrystalLaneD, 48U, 341U, aEarthLaneA, 47U, 244U, aMuLaneD, 5U);

    // Mu D[6]: aEarthLaneB[6] + aCrystalLaneA[15].
    KEY_FOLD_BLOCK(aEarthLaneB, 6U, 284U, aCrystalLaneA, 15U, 193U, aMuLaneD, 6U);

    // Mu D[7]: aCrystalLaneC[27] + aEarthLaneD[30].
    KEY_FOLD_BLOCK(aCrystalLaneC, 27U, 15U, aEarthLaneD, 30U, 224U, aMuLaneD, 7U);

    // Lel — four 512-byte blocks per lane.

    // Lel A[0]: aMuLaneD[4] + aMuLaneA[5].
    KEY_FOLD_BLOCK(aMuLaneD, 4U, 212U, aMuLaneA, 5U, 259U, aLelLaneA, 0U);

    // Lel A[1]: aMuLaneA[0] + aMuLaneC[4].
    KEY_FOLD_BLOCK(aMuLaneA, 0U, 485U, aMuLaneC, 4U, 203U, aLelLaneA, 1U);

    // Lel A[2]: aMuLaneD[0] + aMuLaneB[3].
    KEY_FOLD_BLOCK(aMuLaneD, 0U, 488U, aMuLaneB, 3U, 329U, aLelLaneA, 2U);

    // Lel A[3]: aMuLaneC[0] + aMuLaneB[7].
    KEY_FOLD_BLOCK(aMuLaneC, 0U, 282U, aMuLaneB, 7U, 49U, aLelLaneA, 3U);

    // Lel B[0]: aMuLaneD[7] + aMuLaneB[0].
    KEY_FOLD_BLOCK(aMuLaneD, 7U, 155U, aMuLaneB, 0U, 493U, aLelLaneB, 0U);

    // Lel B[1]: aMuLaneD[2] + aMuLaneB[5].
    KEY_FOLD_BLOCK(aMuLaneD, 2U, 236U, aMuLaneB, 5U, 123U, aLelLaneB, 1U);

    // Lel B[2]: aMuLaneA[3] + aMuLaneC[7].
    KEY_FOLD_BLOCK(aMuLaneA, 3U, 499U, aMuLaneC, 7U, 290U, aLelLaneB, 2U);

    // Lel B[3]: aMuLaneC[2] + aMuLaneA[7].
    KEY_FOLD_BLOCK(aMuLaneC, 2U, 483U, aMuLaneA, 7U, 175U, aLelLaneB, 3U);

    // Lel C[0]: aMuLaneD[1] + aMuLaneB[6].
    KEY_FOLD_BLOCK(aMuLaneD, 1U, 387U, aMuLaneB, 6U, 45U, aLelLaneC, 0U);

    // Lel C[1]: aMuLaneA[1] + aMuLaneC[3].
    KEY_FOLD_BLOCK(aMuLaneA, 1U, 18U, aMuLaneC, 3U, 97U, aLelLaneC, 1U);

    // Lel C[2]: aMuLaneB[1] + aMuLaneD[5].
    KEY_FOLD_BLOCK(aMuLaneB, 1U, 102U, aMuLaneD, 5U, 187U, aLelLaneC, 2U);

    // Lel C[3]: aMuLaneA[2] + aMuLaneC[5].
    KEY_FOLD_BLOCK(aMuLaneA, 2U, 251U, aMuLaneC, 5U, 197U, aLelLaneC, 3U);

    // Lel D[0]: aMuLaneA[6] + aMuLaneC[1].
    KEY_FOLD_BLOCK(aMuLaneA, 6U, 252U, aMuLaneC, 1U, 27U, aLelLaneD, 0U);

    // Lel D[1]: aMuLaneD[3] + aMuLaneB[2].
    KEY_FOLD_BLOCK(aMuLaneD, 3U, 3U, aMuLaneB, 2U, 5U, aLelLaneD, 1U);

    // Lel D[2]: aMuLaneC[6] + aMuLaneB[4].
    KEY_FOLD_BLOCK(aMuLaneC, 6U, 336U, aMuLaneB, 4U, 104U, aLelLaneD, 2U);

    // Lel D[3]: aMuLaneA[4] + aMuLaneD[6].
    KEY_FOLD_BLOCK(aMuLaneA, 4U, 364U, aMuLaneD, 6U, 381U, aLelLaneD, 3U);

    // Goz — two 512-byte blocks per lane.

    // Goz A[0]: aLelLaneD[0] + aLelLaneC[2].
    KEY_FOLD_BLOCK(aLelLaneD, 0U, 31U, aLelLaneC, 2U, 210U, aGozLaneA, 0U);

    // Goz A[1]: aLelLaneA[1] + aLelLaneB[0].
    KEY_FOLD_BLOCK(aLelLaneA, 1U, 281U, aLelLaneB, 0U, 255U, aGozLaneA, 1U);

    // Goz B[0]: aLelLaneB[3] + aLelLaneC[0].
    KEY_FOLD_BLOCK(aLelLaneB, 3U, 249U, aLelLaneC, 0U, 387U, aGozLaneB, 0U);

    // Goz B[1]: aLelLaneA[3] + aLelLaneD[3].
    KEY_FOLD_BLOCK(aLelLaneA, 3U, 379U, aLelLaneD, 3U, 323U, aGozLaneB, 1U);

    // Goz C[0]: aLelLaneB[2] + aLelLaneA[2].
    KEY_FOLD_BLOCK(aLelLaneB, 2U, 112U, aLelLaneA, 2U, 68U, aGozLaneC, 0U);

    // Goz C[1]: aLelLaneD[1] + aLelLaneC[3].
    KEY_FOLD_BLOCK(aLelLaneD, 1U, 111U, aLelLaneC, 3U, 271U, aGozLaneC, 1U);

    // Goz D[0]: aLelLaneA[0] + aLelLaneD[2].
    KEY_FOLD_BLOCK(aLelLaneA, 0U, 211U, aLelLaneD, 2U, 245U, aGozLaneD, 0U);

    // Goz D[1]: aLelLaneC[1] + aLelLaneB[1].
    KEY_FOLD_BLOCK(aLelLaneC, 1U, 352U, aLelLaneB, 1U, 136U, aGozLaneD, 1U);

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

    KEY_FOLD_BLOCK(aGozLaneA, 0U, 266U, aGozLaneB, 0U, 215U, aFinalLaneC, 0U);

    KEY_FOLD_BLOCK(aGozLaneC, 0U, 67U, aGozLaneD, 0U, 464U, aFinalLaneC, 1U);

    KEY_FOLD_BLOCK(aGozLaneA, 1U, 302U, aGozLaneC, 1U, 341U, aFinalLaneC, 2U);

    KEY_FOLD_BLOCK(aGozLaneB, 1U, 491U, aGozLaneD, 1U, 169U, aFinalLaneC, 3U);


    // Grow input D — balanced 512-byte fold graph.

    // Mu — eight 512-byte blocks per lane.

    // Mu A[0]: aEarthLaneA[23] + aCrystalLaneA[45].
    KEY_FOLD_BLOCK(aEarthLaneA, 23U, 276U, aCrystalLaneA, 45U, 390U, aMuLaneA, 0U);

    // Mu A[1]: aCrystalLaneD[54] + aCrystalLaneB[60].
    KEY_FOLD_BLOCK(aCrystalLaneD, 54U, 23U, aCrystalLaneB, 60U, 139U, aMuLaneA, 1U);

    // Mu A[2]: aEarthLaneC[1] + aEarthLaneA[57].
    KEY_FOLD_BLOCK(aEarthLaneC, 1U, 58U, aEarthLaneA, 57U, 390U, aMuLaneA, 2U);

    // Mu A[3]: aEarthLaneD[12] + aCrystalLaneC[53].
    KEY_FOLD_BLOCK(aEarthLaneD, 12U, 342U, aCrystalLaneC, 53U, 212U, aMuLaneA, 3U);

    // Mu A[4]: aCrystalLaneD[8] + aCrystalLaneB[58].
    KEY_FOLD_BLOCK(aCrystalLaneD, 8U, 459U, aCrystalLaneB, 58U, 401U, aMuLaneA, 4U);

    // Mu A[5]: aEarthLaneC[11] + aEarthLaneB[38].
    KEY_FOLD_BLOCK(aEarthLaneC, 11U, 395U, aEarthLaneB, 38U, 237U, aMuLaneA, 5U);

    // Mu A[6]: aEarthLaneD[62] + aCrystalLaneA[55].
    KEY_FOLD_BLOCK(aEarthLaneD, 62U, 272U, aCrystalLaneA, 55U, 312U, aMuLaneA, 6U);

    // Mu A[7]: aEarthLaneB[16] + aCrystalLaneC[21].
    KEY_FOLD_BLOCK(aEarthLaneB, 16U, 304U, aCrystalLaneC, 21U, 34U, aMuLaneA, 7U);

    // Mu B[0]: aEarthLaneD[38] + aCrystalLaneD[40].
    KEY_FOLD_BLOCK(aEarthLaneD, 38U, 110U, aCrystalLaneD, 40U, 252U, aMuLaneB, 0U);

    // Mu B[1]: aCrystalLaneA[11] + aEarthLaneB[62].
    KEY_FOLD_BLOCK(aCrystalLaneA, 11U, 430U, aEarthLaneB, 62U, 468U, aMuLaneB, 1U);

    // Mu B[2]: aEarthLaneD[56] + aEarthLaneC[45].
    KEY_FOLD_BLOCK(aEarthLaneD, 56U, 475U, aEarthLaneC, 45U, 228U, aMuLaneB, 2U);

    // Mu B[3]: aEarthLaneA[15] + aEarthLaneB[36].
    KEY_FOLD_BLOCK(aEarthLaneA, 15U, 420U, aEarthLaneB, 36U, 350U, aMuLaneB, 3U);

    // Mu B[4]: aEarthLaneA[7] + aCrystalLaneC[15].
    KEY_FOLD_BLOCK(aEarthLaneA, 7U, 428U, aCrystalLaneC, 15U, 497U, aMuLaneB, 4U);

    // Mu B[5]: aCrystalLaneB[30] + aCrystalLaneC[33].
    KEY_FOLD_BLOCK(aCrystalLaneB, 30U, 150U, aCrystalLaneC, 33U, 40U, aMuLaneB, 5U);

    // Mu B[6]: aCrystalLaneB[6] + aCrystalLaneD[4].
    KEY_FOLD_BLOCK(aCrystalLaneB, 6U, 317U, aCrystalLaneD, 4U, 301U, aMuLaneB, 6U);

    // Mu B[7]: aCrystalLaneA[53] + aEarthLaneC[47].
    KEY_FOLD_BLOCK(aCrystalLaneA, 53U, 434U, aEarthLaneC, 47U, 77U, aMuLaneB, 7U);

    // Mu C[0]: aEarthLaneB[0] + aCrystalLaneC[9].
    KEY_FOLD_BLOCK(aEarthLaneB, 0U, 214U, aCrystalLaneC, 9U, 447U, aMuLaneC, 0U);

    // Mu C[1]: aEarthLaneC[37] + aCrystalLaneB[46].
    KEY_FOLD_BLOCK(aEarthLaneC, 37U, 30U, aCrystalLaneB, 46U, 117U, aMuLaneC, 1U);

    // Mu C[2]: aCrystalLaneC[17] + aEarthLaneB[2].
    KEY_FOLD_BLOCK(aCrystalLaneC, 17U, 203U, aEarthLaneB, 2U, 212U, aMuLaneC, 2U);

    // Mu C[3]: aCrystalLaneA[33] + aCrystalLaneD[22].
    KEY_FOLD_BLOCK(aCrystalLaneA, 33U, 348U, aCrystalLaneD, 22U, 353U, aMuLaneC, 3U);

    // Mu C[4]: aEarthLaneD[28] + aEarthLaneA[45].
    KEY_FOLD_BLOCK(aEarthLaneD, 28U, 358U, aEarthLaneA, 45U, 78U, aMuLaneC, 4U);

    // Mu C[5]: aCrystalLaneD[42] + aCrystalLaneA[19].
    KEY_FOLD_BLOCK(aCrystalLaneD, 42U, 176U, aCrystalLaneA, 19U, 33U, aMuLaneC, 5U);

    // Mu C[6]: aEarthLaneC[41] + aCrystalLaneB[54].
    KEY_FOLD_BLOCK(aEarthLaneC, 41U, 265U, aCrystalLaneB, 54U, 213U, aMuLaneC, 6U);

    // Mu C[7]: aEarthLaneA[59] + aEarthLaneD[24].
    KEY_FOLD_BLOCK(aEarthLaneA, 59U, 128U, aEarthLaneD, 24U, 418U, aMuLaneC, 7U);

    // Mu D[0]: aEarthLaneB[42] + aCrystalLaneC[39].
    KEY_FOLD_BLOCK(aEarthLaneB, 42U, 242U, aCrystalLaneC, 39U, 14U, aMuLaneD, 0U);

    // Mu D[1]: aEarthLaneA[31] + aCrystalLaneB[18].
    KEY_FOLD_BLOCK(aEarthLaneA, 31U, 235U, aCrystalLaneB, 18U, 28U, aMuLaneD, 1U);

    // Mu D[2]: aCrystalLaneB[16] + aEarthLaneC[7].
    KEY_FOLD_BLOCK(aCrystalLaneB, 16U, 283U, aEarthLaneC, 7U, 102U, aMuLaneD, 2U);

    // Mu D[3]: aCrystalLaneA[9] + aEarthLaneD[2].
    KEY_FOLD_BLOCK(aCrystalLaneA, 9U, 361U, aEarthLaneD, 2U, 57U, aMuLaneD, 3U);

    // Mu D[4]: aEarthLaneA[37] + aEarthLaneD[40].
    KEY_FOLD_BLOCK(aEarthLaneA, 37U, 423U, aEarthLaneD, 40U, 425U, aMuLaneD, 4U);

    // Mu D[5]: aCrystalLaneD[12] + aCrystalLaneA[31].
    KEY_FOLD_BLOCK(aCrystalLaneD, 12U, 1U, aCrystalLaneA, 31U, 389U, aMuLaneD, 5U);

    // Mu D[6]: aEarthLaneC[13] + aCrystalLaneC[63].
    KEY_FOLD_BLOCK(aEarthLaneC, 13U, 39U, aCrystalLaneC, 63U, 287U, aMuLaneD, 6U);

    // Mu D[7]: aCrystalLaneD[44] + aEarthLaneB[14].
    KEY_FOLD_BLOCK(aCrystalLaneD, 44U, 486U, aEarthLaneB, 14U, 36U, aMuLaneD, 7U);

    // Lel — four 512-byte blocks per lane.

    // Lel A[0]: aMuLaneC[3] + aMuLaneA[7].
    KEY_FOLD_BLOCK(aMuLaneC, 3U, 402U, aMuLaneA, 7U, 273U, aLelLaneA, 0U);

    // Lel A[1]: aMuLaneD[5] + aMuLaneB[5].
    KEY_FOLD_BLOCK(aMuLaneD, 5U, 416U, aMuLaneB, 5U, 347U, aLelLaneA, 1U);

    // Lel A[2]: aMuLaneC[7] + aMuLaneA[1].
    KEY_FOLD_BLOCK(aMuLaneC, 7U, 182U, aMuLaneA, 1U, 88U, aLelLaneA, 2U);

    // Lel A[3]: aMuLaneB[0] + aMuLaneD[0].
    KEY_FOLD_BLOCK(aMuLaneB, 0U, 177U, aMuLaneD, 0U, 482U, aLelLaneA, 3U);

    // Lel B[0]: aMuLaneD[3] + aMuLaneC[0].
    KEY_FOLD_BLOCK(aMuLaneD, 3U, 44U, aMuLaneC, 0U, 349U, aLelLaneB, 0U);

    // Lel B[1]: aMuLaneB[3] + aMuLaneC[5].
    KEY_FOLD_BLOCK(aMuLaneB, 3U, 310U, aMuLaneC, 5U, 300U, aLelLaneB, 1U);

    // Lel B[2]: aMuLaneA[4] + aMuLaneB[7].
    KEY_FOLD_BLOCK(aMuLaneA, 4U, 131U, aMuLaneB, 7U, 482U, aLelLaneB, 2U);

    // Lel B[3]: aMuLaneA[6] + aMuLaneD[7].
    KEY_FOLD_BLOCK(aMuLaneA, 6U, 56U, aMuLaneD, 7U, 182U, aLelLaneB, 3U);

    // Lel C[0]: aMuLaneD[4] + aMuLaneC[2].
    KEY_FOLD_BLOCK(aMuLaneD, 4U, 39U, aMuLaneC, 2U, 334U, aLelLaneC, 0U);

    // Lel C[1]: aMuLaneB[6] + aMuLaneA[2].
    KEY_FOLD_BLOCK(aMuLaneB, 6U, 101U, aMuLaneA, 2U, 192U, aLelLaneC, 1U);

    // Lel C[2]: aMuLaneA[3] + aMuLaneD[2].
    KEY_FOLD_BLOCK(aMuLaneA, 3U, 199U, aMuLaneD, 2U, 418U, aLelLaneC, 2U);

    // Lel C[3]: aMuLaneC[6] + aMuLaneB[4].
    KEY_FOLD_BLOCK(aMuLaneC, 6U, 126U, aMuLaneB, 4U, 337U, aLelLaneC, 3U);

    // Lel D[0]: aMuLaneB[2] + aMuLaneD[1].
    KEY_FOLD_BLOCK(aMuLaneB, 2U, 106U, aMuLaneD, 1U, 463U, aLelLaneD, 0U);

    // Lel D[1]: aMuLaneA[0] + aMuLaneC[1].
    KEY_FOLD_BLOCK(aMuLaneA, 0U, 149U, aMuLaneC, 1U, 327U, aLelLaneD, 1U);

    // Lel D[2]: aMuLaneA[5] + aMuLaneC[4].
    KEY_FOLD_BLOCK(aMuLaneA, 5U, 35U, aMuLaneC, 4U, 465U, aLelLaneD, 2U);

    // Lel D[3]: aMuLaneD[6] + aMuLaneB[1].
    KEY_FOLD_BLOCK(aMuLaneD, 6U, 434U, aMuLaneB, 1U, 56U, aLelLaneD, 3U);

    // Goz — two 512-byte blocks per lane.

    // Goz A[0]: aLelLaneD[3] + aLelLaneA[2].
    KEY_FOLD_BLOCK(aLelLaneD, 3U, 389U, aLelLaneA, 2U, 234U, aGozLaneA, 0U);

    // Goz A[1]: aLelLaneC[1] + aLelLaneB[0].
    KEY_FOLD_BLOCK(aLelLaneC, 1U, 439U, aLelLaneB, 0U, 235U, aGozLaneA, 1U);

    // Goz B[0]: aLelLaneA[0] + aLelLaneD[0].
    KEY_FOLD_BLOCK(aLelLaneA, 0U, 70U, aLelLaneD, 0U, 170U, aGozLaneB, 0U);

    // Goz B[1]: aLelLaneB[3] + aLelLaneC[3].
    KEY_FOLD_BLOCK(aLelLaneB, 3U, 403U, aLelLaneC, 3U, 398U, aGozLaneB, 1U);

    // Goz C[0]: aLelLaneC[2] + aLelLaneB[1].
    KEY_FOLD_BLOCK(aLelLaneC, 2U, 128U, aLelLaneB, 1U, 195U, aGozLaneC, 0U);

    // Goz C[1]: aLelLaneA[3] + aLelLaneD[1].
    KEY_FOLD_BLOCK(aLelLaneA, 3U, 490U, aLelLaneD, 1U, 68U, aGozLaneC, 1U);

    // Goz D[0]: aLelLaneC[0] + aLelLaneB[2].
    KEY_FOLD_BLOCK(aLelLaneC, 0U, 26U, aLelLaneB, 2U, 5U, aGozLaneD, 0U);

    // Goz D[1]: aLelLaneD[2] + aLelLaneA[1].
    KEY_FOLD_BLOCK(aLelLaneD, 2U, 508U, aLelLaneA, 1U, 467U, aGozLaneD, 1U);

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

    KEY_FOLD_BLOCK(aGozLaneA, 0U, 75U, aGozLaneB, 0U, 354U, aFinalLaneD, 0U);

    KEY_FOLD_BLOCK(aGozLaneC, 0U, 142U, aGozLaneD, 0U, 356U, aFinalLaneD, 1U);

    KEY_FOLD_BLOCK(aGozLaneA, 1U, 71U, aGozLaneC, 1U, 110U, aFinalLaneD, 2U);

    KEY_FOLD_BLOCK(aGozLaneB, 1U, 247U, aGozLaneD, 1U, 411U, aFinalLaneD, 3U);

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
    KEY_FOLD_BLOCK(aEarthLaneD, 53U, 458U, aEarthLaneC, 34U, 115U, aMuLaneA, 0U);

    // Mu A[1]: aCrystalLaneD[59] + aEarthLaneD[31].
    KEY_FOLD_BLOCK(aCrystalLaneD, 59U, 459U, aEarthLaneD, 31U, 261U, aMuLaneA, 1U);

    // Mu A[2]: aEarthLaneB[9] + aEarthLaneA[22].
    KEY_FOLD_BLOCK(aEarthLaneB, 9U, 503U, aEarthLaneA, 22U, 80U, aMuLaneA, 2U);

    // Mu A[3]: aCrystalLaneB[9] + aCrystalLaneC[8].
    KEY_FOLD_BLOCK(aCrystalLaneB, 9U, 197U, aCrystalLaneC, 8U, 61U, aMuLaneA, 3U);

    // Mu A[4]: aEarthLaneB[63] + aEarthLaneC[16].
    KEY_FOLD_BLOCK(aEarthLaneB, 63U, 425U, aEarthLaneC, 16U, 156U, aMuLaneA, 4U);

    // Mu A[5]: aCrystalLaneD[29] + aCrystalLaneC[52].
    KEY_FOLD_BLOCK(aCrystalLaneD, 29U, 58U, aCrystalLaneC, 52U, 372U, aMuLaneA, 5U);

    // Mu A[6]: aCrystalLaneA[8] + aEarthLaneA[30].
    KEY_FOLD_BLOCK(aCrystalLaneA, 8U, 216U, aEarthLaneA, 30U, 133U, aMuLaneA, 6U);

    // Mu A[7]: aCrystalLaneB[39] + aCrystalLaneA[50].
    KEY_FOLD_BLOCK(aCrystalLaneB, 39U, 456U, aCrystalLaneA, 50U, 235U, aMuLaneA, 7U);

    // Mu B[0]: aCrystalLaneD[1] + aEarthLaneA[62].
    KEY_FOLD_BLOCK(aCrystalLaneD, 1U, 234U, aEarthLaneA, 62U, 306U, aMuLaneB, 0U);

    // Mu B[1]: aCrystalLaneC[38] + aEarthLaneA[24].
    KEY_FOLD_BLOCK(aCrystalLaneC, 38U, 39U, aEarthLaneA, 24U, 347U, aMuLaneB, 1U);

    // Mu B[2]: aCrystalLaneC[30] + aCrystalLaneB[47].
    KEY_FOLD_BLOCK(aCrystalLaneC, 30U, 277U, aCrystalLaneB, 47U, 283U, aMuLaneB, 2U);

    // Mu B[3]: aEarthLaneC[54] + aEarthLaneD[61].
    KEY_FOLD_BLOCK(aEarthLaneC, 54U, 14U, aEarthLaneD, 61U, 273U, aMuLaneB, 3U);

    // Mu B[4]: aEarthLaneB[27] + aEarthLaneC[58].
    KEY_FOLD_BLOCK(aEarthLaneB, 27U, 176U, aEarthLaneC, 58U, 436U, aMuLaneB, 4U);

    // Mu B[5]: aCrystalLaneD[19] + aCrystalLaneB[3].
    KEY_FOLD_BLOCK(aCrystalLaneD, 19U, 348U, aCrystalLaneB, 3U, 199U, aMuLaneB, 5U);

    // Mu B[6]: aEarthLaneB[45] + aCrystalLaneA[16].
    KEY_FOLD_BLOCK(aEarthLaneB, 45U, 472U, aCrystalLaneA, 16U, 242U, aMuLaneB, 6U);

    // Mu B[7]: aCrystalLaneA[30] + aEarthLaneD[41].
    KEY_FOLD_BLOCK(aCrystalLaneA, 30U, 331U, aEarthLaneD, 41U, 256U, aMuLaneB, 7U);

    // Mu C[0]: aEarthLaneB[43] + aCrystalLaneB[5].
    KEY_FOLD_BLOCK(aEarthLaneB, 43U, 341U, aCrystalLaneB, 5U, 88U, aMuLaneC, 0U);

    // Mu C[1]: aCrystalLaneB[19] + aCrystalLaneC[42].
    KEY_FOLD_BLOCK(aCrystalLaneB, 19U, 288U, aCrystalLaneC, 42U, 292U, aMuLaneC, 1U);

    // Mu C[2]: aCrystalLaneA[44] + aEarthLaneD[51].
    KEY_FOLD_BLOCK(aCrystalLaneA, 44U, 341U, aEarthLaneD, 51U, 397U, aMuLaneC, 2U);

    // Mu C[3]: aEarthLaneA[56] + aCrystalLaneC[0].
    KEY_FOLD_BLOCK(aEarthLaneA, 56U, 378U, aCrystalLaneC, 0U, 175U, aMuLaneC, 3U);

    // Mu C[4]: aCrystalLaneA[54] + aEarthLaneD[23].
    KEY_FOLD_BLOCK(aCrystalLaneA, 54U, 36U, aEarthLaneD, 23U, 153U, aMuLaneC, 4U);

    // Mu C[5]: aEarthLaneA[4] + aEarthLaneB[13].
    KEY_FOLD_BLOCK(aEarthLaneA, 4U, 42U, aEarthLaneB, 13U, 327U, aMuLaneC, 5U);

    // Mu C[6]: aEarthLaneC[36] + aCrystalLaneD[37].
    KEY_FOLD_BLOCK(aEarthLaneC, 36U, 265U, aCrystalLaneD, 37U, 439U, aMuLaneC, 6U);

    // Mu C[7]: aEarthLaneC[6] + aCrystalLaneD[13].
    KEY_FOLD_BLOCK(aEarthLaneC, 6U, 441U, aCrystalLaneD, 13U, 466U, aMuLaneC, 7U);

    // Mu D[0]: aEarthLaneA[48] + aEarthLaneB[53].
    KEY_FOLD_BLOCK(aEarthLaneA, 48U, 417U, aEarthLaneB, 53U, 254U, aMuLaneD, 0U);

    // Mu D[1]: aEarthLaneB[23] + aEarthLaneD[13].
    KEY_FOLD_BLOCK(aEarthLaneB, 23U, 427U, aEarthLaneD, 13U, 277U, aMuLaneD, 1U);

    // Mu D[2]: aEarthLaneA[34] + aCrystalLaneA[6].
    KEY_FOLD_BLOCK(aEarthLaneA, 34U, 50U, aCrystalLaneA, 6U, 315U, aMuLaneD, 2U);

    // Mu D[3]: aCrystalLaneB[33] + aCrystalLaneD[49].
    KEY_FOLD_BLOCK(aCrystalLaneB, 33U, 369U, aCrystalLaneD, 49U, 138U, aMuLaneD, 3U);

    // Mu D[4]: aEarthLaneD[17] + aCrystalLaneD[33].
    KEY_FOLD_BLOCK(aEarthLaneD, 17U, 390U, aCrystalLaneD, 33U, 421U, aMuLaneD, 4U);

    // Mu D[5]: aCrystalLaneC[44] + aEarthLaneC[0].
    KEY_FOLD_BLOCK(aCrystalLaneC, 44U, 64U, aEarthLaneC, 0U, 210U, aMuLaneD, 5U);

    // Mu D[6]: aEarthLaneC[22] + aCrystalLaneA[38].
    KEY_FOLD_BLOCK(aEarthLaneC, 22U, 319U, aCrystalLaneA, 38U, 405U, aMuLaneD, 6U);

    // Mu D[7]: aCrystalLaneC[12] + aCrystalLaneB[49].
    KEY_FOLD_BLOCK(aCrystalLaneC, 12U, 166U, aCrystalLaneB, 49U, 55U, aMuLaneD, 7U);

    // Lel — four 512-byte blocks per lane.

    // Lel A[0]: aMuLaneA[7] + aMuLaneC[6].
    KEY_FOLD_BLOCK(aMuLaneA, 7U, 416U, aMuLaneC, 6U, 324U, aLelLaneA, 0U);

    // Lel A[1]: aMuLaneA[1] + aMuLaneD[6].
    KEY_FOLD_BLOCK(aMuLaneA, 1U, 264U, aMuLaneD, 6U, 149U, aLelLaneA, 1U);

    // Lel A[2]: aMuLaneB[3] + aMuLaneC[0].
    KEY_FOLD_BLOCK(aMuLaneB, 3U, 236U, aMuLaneC, 0U, 444U, aLelLaneA, 2U);

    // Lel A[3]: aMuLaneB[7] + aMuLaneD[0].
    KEY_FOLD_BLOCK(aMuLaneB, 7U, 52U, aMuLaneD, 0U, 305U, aLelLaneA, 3U);

    // Lel B[0]: aMuLaneB[0] + aMuLaneA[4].
    KEY_FOLD_BLOCK(aMuLaneB, 0U, 481U, aMuLaneA, 4U, 417U, aLelLaneB, 0U);

    // Lel B[1]: aMuLaneD[3] + aMuLaneC[3].
    KEY_FOLD_BLOCK(aMuLaneD, 3U, 163U, aMuLaneC, 3U, 2U, aLelLaneB, 1U);

    // Lel B[2]: aMuLaneA[6] + aMuLaneD[4].
    KEY_FOLD_BLOCK(aMuLaneA, 6U, 41U, aMuLaneD, 4U, 420U, aLelLaneB, 2U);

    // Lel B[3]: aMuLaneC[4] + aMuLaneB[5].
    KEY_FOLD_BLOCK(aMuLaneC, 4U, 482U, aMuLaneB, 5U, 312U, aLelLaneB, 3U);

    // Lel C[0]: aMuLaneD[1] + aMuLaneB[1].
    KEY_FOLD_BLOCK(aMuLaneD, 1U, 400U, aMuLaneB, 1U, 398U, aLelLaneC, 0U);

    // Lel C[1]: aMuLaneB[2] + aMuLaneC[5].
    KEY_FOLD_BLOCK(aMuLaneB, 2U, 422U, aMuLaneC, 5U, 81U, aLelLaneC, 1U);

    // Lel C[2]: aMuLaneA[3] + aMuLaneC[7].
    KEY_FOLD_BLOCK(aMuLaneA, 3U, 363U, aMuLaneC, 7U, 323U, aLelLaneC, 2U);

    // Lel C[3]: aMuLaneA[5] + aMuLaneD[2].
    KEY_FOLD_BLOCK(aMuLaneA, 5U, 199U, aMuLaneD, 2U, 417U, aLelLaneC, 3U);

    // Lel D[0]: aMuLaneB[6] + aMuLaneA[0].
    KEY_FOLD_BLOCK(aMuLaneB, 6U, 27U, aMuLaneA, 0U, 458U, aLelLaneD, 0U);

    // Lel D[1]: aMuLaneD[7] + aMuLaneC[2].
    KEY_FOLD_BLOCK(aMuLaneD, 7U, 378U, aMuLaneC, 2U, 173U, aLelLaneD, 1U);

    // Lel D[2]: aMuLaneC[1] + aMuLaneB[4].
    KEY_FOLD_BLOCK(aMuLaneC, 1U, 359U, aMuLaneB, 4U, 224U, aLelLaneD, 2U);

    // Lel D[3]: aMuLaneD[5] + aMuLaneA[2].
    KEY_FOLD_BLOCK(aMuLaneD, 5U, 240U, aMuLaneA, 2U, 211U, aLelLaneD, 3U);

    // Goz — two 512-byte blocks per lane.

    // Goz A[0]: aLelLaneB[1] + aLelLaneD[0].
    KEY_FOLD_BLOCK(aLelLaneB, 1U, 50U, aLelLaneD, 0U, 139U, aGozLaneA, 0U);

    // Goz A[1]: aLelLaneA[2] + aLelLaneC[3].
    KEY_FOLD_BLOCK(aLelLaneA, 2U, 274U, aLelLaneC, 3U, 425U, aGozLaneA, 1U);

    // Goz B[0]: aLelLaneD[3] + aLelLaneB[3].
    KEY_FOLD_BLOCK(aLelLaneD, 3U, 323U, aLelLaneB, 3U, 166U, aGozLaneB, 0U);

    // Goz B[1]: aLelLaneC[0] + aLelLaneA[0].
    KEY_FOLD_BLOCK(aLelLaneC, 0U, 405U, aLelLaneA, 0U, 243U, aGozLaneB, 1U);

    // Goz C[0]: aLelLaneB[2] + aLelLaneD[2].
    KEY_FOLD_BLOCK(aLelLaneB, 2U, 384U, aLelLaneD, 2U, 188U, aGozLaneC, 0U);

    // Goz C[1]: aLelLaneC[1] + aLelLaneA[1].
    KEY_FOLD_BLOCK(aLelLaneC, 1U, 252U, aLelLaneA, 1U, 425U, aGozLaneC, 1U);

    // Goz D[0]: aLelLaneD[1] + aLelLaneB[0].
    KEY_FOLD_BLOCK(aLelLaneD, 1U, 42U, aLelLaneB, 0U, 75U, aGozLaneD, 0U);

    // Goz D[1]: aLelLaneA[3] + aLelLaneC[2].
    KEY_FOLD_BLOCK(aLelLaneA, 3U, 473U, aLelLaneC, 2U, 133U, aGozLaneD, 1U);

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

    KEY_FOLD_BLOCK(aGozLaneA, 0U, 73U, aGozLaneB, 0U, 48U, aFinalLaneA + W_KEY, 0U);

    KEY_FOLD_BLOCK(aGozLaneC, 0U, 507U, aGozLaneD, 0U, 20U, aFinalLaneA + W_KEY, 1U);

    KEY_FOLD_BLOCK(aGozLaneA, 1U, 203U, aGozLaneC, 1U, 149U, aFinalLaneA + W_KEY, 2U);

    KEY_FOLD_BLOCK(aGozLaneB, 1U, 471U, aGozLaneD, 1U, 171U, aFinalLaneA + W_KEY, 3U);


    // Grow input B — balanced 512-byte fold graph.

    // Mu — eight 512-byte blocks per lane.

    // Mu A[0]: aCrystalLaneC[32] + aEarthLaneB[39].
    KEY_FOLD_BLOCK(aCrystalLaneC, 32U, 251U, aEarthLaneB, 39U, 481U, aMuLaneA, 0U);

    // Mu A[1]: aCrystalLaneD[11] + aEarthLaneD[55].
    KEY_FOLD_BLOCK(aCrystalLaneD, 11U, 506U, aEarthLaneD, 55U, 219U, aMuLaneA, 1U);

    // Mu A[2]: aCrystalLaneA[18] + aEarthLaneD[63].
    KEY_FOLD_BLOCK(aCrystalLaneA, 18U, 388U, aEarthLaneD, 63U, 148U, aMuLaneA, 2U);

    // Mu A[3]: aCrystalLaneD[39] + aCrystalLaneB[27].
    KEY_FOLD_BLOCK(aCrystalLaneD, 39U, 303U, aCrystalLaneB, 27U, 123U, aMuLaneA, 3U);

    // Mu A[4]: aEarthLaneC[56] + aEarthLaneB[35].
    KEY_FOLD_BLOCK(aEarthLaneC, 56U, 358U, aEarthLaneB, 35U, 133U, aMuLaneA, 4U);

    // Mu A[5]: aEarthLaneA[10] + aEarthLaneC[46].
    KEY_FOLD_BLOCK(aEarthLaneA, 10U, 372U, aEarthLaneC, 46U, 362U, aMuLaneA, 5U);

    // Mu A[6]: aCrystalLaneC[22] + aCrystalLaneA[60].
    KEY_FOLD_BLOCK(aCrystalLaneC, 22U, 237U, aCrystalLaneA, 60U, 77U, aMuLaneA, 6U);

    // Mu A[7]: aCrystalLaneB[51] + aEarthLaneA[26].
    KEY_FOLD_BLOCK(aCrystalLaneB, 51U, 410U, aEarthLaneA, 26U, 258U, aMuLaneA, 7U);

    // Mu B[0]: aEarthLaneC[4] + aEarthLaneB[51].
    KEY_FOLD_BLOCK(aEarthLaneC, 4U, 76U, aEarthLaneB, 51U, 277U, aMuLaneB, 0U);

    // Mu B[1]: aCrystalLaneA[20] + aCrystalLaneB[37].
    KEY_FOLD_BLOCK(aCrystalLaneA, 20U, 104U, aCrystalLaneB, 37U, 209U, aMuLaneB, 1U);

    // Mu B[2]: aEarthLaneC[26] + aEarthLaneD[19].
    KEY_FOLD_BLOCK(aEarthLaneC, 26U, 391U, aEarthLaneD, 19U, 427U, aMuLaneB, 2U);

    // Mu B[3]: aEarthLaneA[36] + aEarthLaneD[7].
    KEY_FOLD_BLOCK(aEarthLaneA, 36U, 132U, aEarthLaneD, 7U, 320U, aMuLaneB, 3U);

    // Mu B[4]: aCrystalLaneD[5] + aCrystalLaneB[43].
    KEY_FOLD_BLOCK(aCrystalLaneD, 5U, 185U, aCrystalLaneB, 43U, 94U, aMuLaneB, 4U);

    // Mu B[5]: aCrystalLaneC[18] + aCrystalLaneD[9].
    KEY_FOLD_BLOCK(aCrystalLaneC, 18U, 186U, aCrystalLaneD, 9U, 234U, aMuLaneB, 5U);

    // Mu B[6]: aCrystalLaneC[2] + aCrystalLaneA[36].
    KEY_FOLD_BLOCK(aCrystalLaneC, 2U, 468U, aCrystalLaneA, 36U, 369U, aMuLaneB, 6U);

    // Mu B[7]: aEarthLaneB[5] + aEarthLaneA[32].
    KEY_FOLD_BLOCK(aEarthLaneB, 5U, 330U, aEarthLaneA, 32U, 267U, aMuLaneB, 7U);

    // Mu C[0]: aEarthLaneC[8] + aCrystalLaneA[12].
    KEY_FOLD_BLOCK(aEarthLaneC, 8U, 77U, aCrystalLaneA, 12U, 58U, aMuLaneC, 0U);

    // Mu C[1]: aEarthLaneD[5] + aEarthLaneC[40].
    KEY_FOLD_BLOCK(aEarthLaneD, 5U, 97U, aEarthLaneC, 40U, 480U, aMuLaneC, 1U);

    // Mu C[2]: aCrystalLaneB[15] + aCrystalLaneA[52].
    KEY_FOLD_BLOCK(aCrystalLaneB, 15U, 454U, aCrystalLaneA, 52U, 15U, aMuLaneC, 2U);

    // Mu C[3]: aCrystalLaneD[55] + aCrystalLaneB[7].
    KEY_FOLD_BLOCK(aCrystalLaneD, 55U, 231U, aCrystalLaneB, 7U, 28U, aMuLaneC, 3U);

    // Mu C[4]: aCrystalLaneC[60] + aEarthLaneD[39].
    KEY_FOLD_BLOCK(aCrystalLaneC, 60U, 372U, aEarthLaneD, 39U, 297U, aMuLaneC, 4U);

    // Mu C[5]: aCrystalLaneD[45] + aCrystalLaneC[28].
    KEY_FOLD_BLOCK(aCrystalLaneD, 45U, 248U, aCrystalLaneC, 28U, 174U, aMuLaneC, 5U);

    // Mu C[6]: aEarthLaneA[52] + aEarthLaneB[59].
    KEY_FOLD_BLOCK(aEarthLaneA, 52U, 35U, aEarthLaneB, 59U, 21U, aMuLaneC, 6U);

    // Mu C[7]: aEarthLaneA[18] + aEarthLaneB[25].
    KEY_FOLD_BLOCK(aEarthLaneA, 18U, 413U, aEarthLaneB, 25U, 63U, aMuLaneC, 7U);

    // Mu D[0]: aEarthLaneA[50] + aCrystalLaneA[32].
    KEY_FOLD_BLOCK(aEarthLaneA, 50U, 504U, aCrystalLaneA, 32U, 257U, aMuLaneD, 0U);

    // Mu D[1]: aCrystalLaneC[50] + aEarthLaneC[28].
    KEY_FOLD_BLOCK(aCrystalLaneC, 50U, 455U, aEarthLaneC, 28U, 213U, aMuLaneD, 1U);

    // Mu D[2]: aEarthLaneA[2] + aEarthLaneD[27].
    KEY_FOLD_BLOCK(aEarthLaneA, 2U, 493U, aEarthLaneD, 27U, 256U, aMuLaneD, 2U);

    // Mu D[3]: aCrystalLaneA[14] + aEarthLaneB[31].
    KEY_FOLD_BLOCK(aCrystalLaneA, 14U, 315U, aEarthLaneB, 31U, 340U, aMuLaneD, 3U);

    // Mu D[4]: aCrystalLaneB[41] + aCrystalLaneD[21].
    KEY_FOLD_BLOCK(aCrystalLaneB, 41U, 89U, aCrystalLaneD, 21U, 39U, aMuLaneD, 4U);

    // Mu D[5]: aEarthLaneC[62] + aCrystalLaneC[54].
    KEY_FOLD_BLOCK(aEarthLaneC, 62U, 299U, aCrystalLaneC, 54U, 207U, aMuLaneD, 5U);

    // Mu D[6]: aEarthLaneB[11] + aEarthLaneD[45].
    KEY_FOLD_BLOCK(aEarthLaneB, 11U, 321U, aEarthLaneD, 45U, 352U, aMuLaneD, 6U);

    // Mu D[7]: aCrystalLaneB[11] + aCrystalLaneD[43].
    KEY_FOLD_BLOCK(aCrystalLaneB, 11U, 341U, aCrystalLaneD, 43U, 62U, aMuLaneD, 7U);

    // Lel — four 512-byte blocks per lane.

    // Lel A[0]: aMuLaneB[5] + aMuLaneD[3].
    KEY_FOLD_BLOCK(aMuLaneB, 5U, 444U, aMuLaneD, 3U, 160U, aLelLaneA, 0U);

    // Lel A[1]: aMuLaneC[4] + aMuLaneB[0].
    KEY_FOLD_BLOCK(aMuLaneC, 4U, 353U, aMuLaneB, 0U, 261U, aLelLaneA, 1U);

    // Lel A[2]: aMuLaneA[6] + aMuLaneD[7].
    KEY_FOLD_BLOCK(aMuLaneA, 6U, 200U, aMuLaneD, 7U, 137U, aLelLaneA, 2U);

    // Lel A[3]: aMuLaneC[0] + aMuLaneA[0].
    KEY_FOLD_BLOCK(aMuLaneC, 0U, 45U, aMuLaneA, 0U, 197U, aLelLaneA, 3U);

    // Lel B[0]: aMuLaneB[2] + aMuLaneC[7].
    KEY_FOLD_BLOCK(aMuLaneB, 2U, 186U, aMuLaneC, 7U, 447U, aLelLaneB, 0U);

    // Lel B[1]: aMuLaneD[0] + aMuLaneA[3].
    KEY_FOLD_BLOCK(aMuLaneD, 0U, 392U, aMuLaneA, 3U, 478U, aLelLaneB, 1U);

    // Lel B[2]: aMuLaneB[7] + aMuLaneC[2].
    KEY_FOLD_BLOCK(aMuLaneB, 7U, 84U, aMuLaneC, 2U, 472U, aLelLaneB, 2U);

    // Lel B[3]: aMuLaneA[2] + aMuLaneD[5].
    KEY_FOLD_BLOCK(aMuLaneA, 2U, 128U, aMuLaneD, 5U, 170U, aLelLaneB, 3U);

    // Lel C[0]: aMuLaneC[5] + aMuLaneD[2].
    KEY_FOLD_BLOCK(aMuLaneC, 5U, 123U, aMuLaneD, 2U, 469U, aLelLaneC, 0U);

    // Lel C[1]: aMuLaneA[5] + aMuLaneB[6].
    KEY_FOLD_BLOCK(aMuLaneA, 5U, 158U, aMuLaneB, 6U, 249U, aLelLaneC, 1U);

    // Lel C[2]: aMuLaneC[1] + aMuLaneA[7].
    KEY_FOLD_BLOCK(aMuLaneC, 1U, 329U, aMuLaneA, 7U, 6U, aLelLaneC, 2U);

    // Lel C[3]: aMuLaneD[4] + aMuLaneB[3].
    KEY_FOLD_BLOCK(aMuLaneD, 4U, 390U, aMuLaneB, 3U, 306U, aLelLaneC, 3U);

    // Lel D[0]: aMuLaneC[6] + aMuLaneB[4].
    KEY_FOLD_BLOCK(aMuLaneC, 6U, 94U, aMuLaneB, 4U, 273U, aLelLaneD, 0U);

    // Lel D[1]: aMuLaneD[1] + aMuLaneA[1].
    KEY_FOLD_BLOCK(aMuLaneD, 1U, 359U, aMuLaneA, 1U, 15U, aLelLaneD, 1U);

    // Lel D[2]: aMuLaneD[6] + aMuLaneC[3].
    KEY_FOLD_BLOCK(aMuLaneD, 6U, 384U, aMuLaneC, 3U, 52U, aLelLaneD, 2U);

    // Lel D[3]: aMuLaneA[4] + aMuLaneB[1].
    KEY_FOLD_BLOCK(aMuLaneA, 4U, 427U, aMuLaneB, 1U, 299U, aLelLaneD, 3U);

    // Goz — two 512-byte blocks per lane.

    // Goz A[0]: aLelLaneC[1] + aLelLaneD[2].
    KEY_FOLD_BLOCK(aLelLaneC, 1U, 178U, aLelLaneD, 2U, 30U, aGozLaneA, 0U);

    // Goz A[1]: aLelLaneB[1] + aLelLaneA[1].
    KEY_FOLD_BLOCK(aLelLaneB, 1U, 99U, aLelLaneA, 1U, 245U, aGozLaneA, 1U);

    // Goz B[0]: aLelLaneC[3] + aLelLaneA[3].
    KEY_FOLD_BLOCK(aLelLaneC, 3U, 131U, aLelLaneA, 3U, 298U, aGozLaneB, 0U);

    // Goz B[1]: aLelLaneB[3] + aLelLaneD[0].
    KEY_FOLD_BLOCK(aLelLaneB, 3U, 171U, aLelLaneD, 0U, 400U, aGozLaneB, 1U);

    // Goz C[0]: aLelLaneB[2] + aLelLaneD[1].
    KEY_FOLD_BLOCK(aLelLaneB, 2U, 492U, aLelLaneD, 1U, 465U, aGozLaneC, 0U);

    // Goz C[1]: aLelLaneC[2] + aLelLaneA[0].
    KEY_FOLD_BLOCK(aLelLaneC, 2U, 403U, aLelLaneA, 0U, 126U, aGozLaneC, 1U);

    // Goz D[0]: aLelLaneC[0] + aLelLaneD[3].
    KEY_FOLD_BLOCK(aLelLaneC, 0U, 156U, aLelLaneD, 3U, 43U, aGozLaneD, 0U);

    // Goz D[1]: aLelLaneB[0] + aLelLaneA[2].
    KEY_FOLD_BLOCK(aLelLaneB, 0U, 304U, aLelLaneA, 2U, 162U, aGozLaneD, 1U);

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

    KEY_FOLD_BLOCK(aGozLaneA, 0U, 347U, aGozLaneB, 0U, 510U, aFinalLaneB + W_KEY, 0U);

    KEY_FOLD_BLOCK(aGozLaneC, 0U, 311U, aGozLaneD, 0U, 289U, aFinalLaneB + W_KEY, 1U);

    KEY_FOLD_BLOCK(aGozLaneA, 1U, 477U, aGozLaneC, 1U, 307U, aFinalLaneB + W_KEY, 2U);

    KEY_FOLD_BLOCK(aGozLaneB, 1U, 279U, aGozLaneD, 1U, 385U, aFinalLaneB + W_KEY, 3U);


    // Grow input C — balanced 512-byte fold graph.

    // Mu — eight 512-byte blocks per lane.

    // Mu A[0]: aCrystalLaneC[58] + aCrystalLaneA[2].
    KEY_FOLD_BLOCK(aCrystalLaneC, 58U, 379U, aCrystalLaneA, 2U, 126U, aMuLaneA, 0U);

    // Mu A[1]: aCrystalLaneD[23] + aEarthLaneA[12].
    KEY_FOLD_BLOCK(aCrystalLaneD, 23U, 107U, aEarthLaneA, 12U, 7U, aMuLaneA, 1U);

    // Mu A[2]: aEarthLaneC[32] + aEarthLaneD[57].
    KEY_FOLD_BLOCK(aEarthLaneC, 32U, 295U, aEarthLaneD, 57U, 30U, aMuLaneA, 2U);

    // Mu A[3]: aEarthLaneC[12] + aCrystalLaneC[10].
    KEY_FOLD_BLOCK(aEarthLaneC, 12U, 29U, aCrystalLaneC, 10U, 485U, aMuLaneA, 3U);

    // Mu A[4]: aEarthLaneB[41] + aCrystalLaneB[57].
    KEY_FOLD_BLOCK(aEarthLaneB, 41U, 218U, aCrystalLaneB, 57U, 68U, aMuLaneA, 4U);

    // Mu A[5]: aCrystalLaneD[3] + aCrystalLaneA[28].
    KEY_FOLD_BLOCK(aCrystalLaneD, 3U, 393U, aCrystalLaneA, 28U, 479U, aMuLaneA, 5U);

    // Mu A[6]: aEarthLaneD[21] + aEarthLaneB[61].
    KEY_FOLD_BLOCK(aEarthLaneD, 21U, 249U, aEarthLaneB, 61U, 385U, aMuLaneA, 6U);

    // Mu A[7]: aEarthLaneA[54] + aCrystalLaneB[13].
    KEY_FOLD_BLOCK(aEarthLaneA, 54U, 72U, aCrystalLaneB, 13U, 500U, aMuLaneA, 7U);

    // Mu B[0]: aCrystalLaneC[14] + aEarthLaneD[47].
    KEY_FOLD_BLOCK(aCrystalLaneC, 14U, 420U, aEarthLaneD, 47U, 423U, aMuLaneB, 0U);

    // Mu B[1]: aEarthLaneA[42] + aEarthLaneB[21].
    KEY_FOLD_BLOCK(aEarthLaneA, 42U, 216U, aEarthLaneB, 21U, 264U, aMuLaneB, 1U);

    // Mu B[2]: aEarthLaneC[44] + aCrystalLaneA[42].
    KEY_FOLD_BLOCK(aEarthLaneC, 44U, 5U, aCrystalLaneA, 42U, 450U, aMuLaneB, 2U);

    // Mu B[3]: aEarthLaneB[55] + aEarthLaneD[49].
    KEY_FOLD_BLOCK(aEarthLaneB, 55U, 242U, aEarthLaneD, 49U, 336U, aMuLaneB, 3U);

    // Mu B[4]: aEarthLaneA[8] + aEarthLaneC[10].
    KEY_FOLD_BLOCK(aEarthLaneA, 8U, 310U, aEarthLaneC, 10U, 464U, aMuLaneB, 4U);

    // Mu B[5]: aCrystalLaneA[40] + aCrystalLaneD[27].
    KEY_FOLD_BLOCK(aCrystalLaneA, 40U, 281U, aCrystalLaneD, 27U, 33U, aMuLaneB, 5U);

    // Mu B[6]: aCrystalLaneB[29] + aCrystalLaneC[40].
    KEY_FOLD_BLOCK(aCrystalLaneB, 29U, 231U, aCrystalLaneC, 40U, 473U, aMuLaneB, 6U);

    // Mu B[7]: aCrystalLaneB[23] + aCrystalLaneD[51].
    KEY_FOLD_BLOCK(aCrystalLaneB, 23U, 47U, aCrystalLaneD, 51U, 432U, aMuLaneB, 7U);

    // Mu C[0]: aCrystalLaneC[36] + aCrystalLaneD[61].
    KEY_FOLD_BLOCK(aCrystalLaneC, 36U, 177U, aCrystalLaneD, 61U, 383U, aMuLaneC, 0U);

    // Mu C[1]: aEarthLaneA[20] + aEarthLaneB[19].
    KEY_FOLD_BLOCK(aEarthLaneA, 20U, 331U, aEarthLaneB, 19U, 398U, aMuLaneC, 1U);

    // Mu C[2]: aCrystalLaneA[24] + aCrystalLaneB[21].
    KEY_FOLD_BLOCK(aCrystalLaneA, 24U, 400U, aCrystalLaneB, 21U, 464U, aMuLaneC, 2U);

    // Mu C[3]: aEarthLaneD[9] + aEarthLaneC[38].
    KEY_FOLD_BLOCK(aEarthLaneD, 9U, 337U, aEarthLaneC, 38U, 275U, aMuLaneC, 3U);

    // Mu C[4]: aCrystalLaneB[55] + aEarthLaneB[47].
    KEY_FOLD_BLOCK(aCrystalLaneB, 55U, 305U, aEarthLaneB, 47U, 121U, aMuLaneC, 4U);

    // Mu C[5]: aCrystalLaneC[48] + aCrystalLaneD[63].
    KEY_FOLD_BLOCK(aCrystalLaneC, 48U, 389U, aCrystalLaneD, 63U, 511U, aMuLaneC, 5U);

    // Mu C[6]: aCrystalLaneA[48] + aEarthLaneA[14].
    KEY_FOLD_BLOCK(aCrystalLaneA, 48U, 119U, aEarthLaneA, 14U, 182U, aMuLaneC, 6U);

    // Mu C[7]: aEarthLaneD[29] + aEarthLaneC[14].
    KEY_FOLD_BLOCK(aEarthLaneD, 29U, 203U, aEarthLaneC, 14U, 229U, aMuLaneC, 7U);

    // Mu D[0]: aEarthLaneD[25] + aCrystalLaneB[35].
    KEY_FOLD_BLOCK(aEarthLaneD, 25U, 118U, aCrystalLaneB, 35U, 224U, aMuLaneD, 0U);

    // Mu D[1]: aEarthLaneC[2] + aCrystalLaneD[35].
    KEY_FOLD_BLOCK(aEarthLaneC, 2U, 193U, aCrystalLaneD, 35U, 351U, aMuLaneD, 1U);

    // Mu D[2]: aEarthLaneC[42] + aCrystalLaneA[10].
    KEY_FOLD_BLOCK(aEarthLaneC, 42U, 435U, aCrystalLaneA, 10U, 234U, aMuLaneD, 2U);

    // Mu D[3]: aEarthLaneD[59] + aCrystalLaneC[20].
    KEY_FOLD_BLOCK(aEarthLaneD, 59U, 221U, aCrystalLaneC, 20U, 495U, aMuLaneD, 3U);

    // Mu D[4]: aCrystalLaneC[16] + aCrystalLaneD[25].
    KEY_FOLD_BLOCK(aCrystalLaneC, 16U, 207U, aCrystalLaneD, 25U, 495U, aMuLaneD, 4U);

    // Mu D[5]: aEarthLaneA[40] + aEarthLaneB[7].
    KEY_FOLD_BLOCK(aEarthLaneA, 40U, 353U, aEarthLaneB, 7U, 232U, aMuLaneD, 5U);

    // Mu D[6]: aEarthLaneA[46] + aEarthLaneB[15].
    KEY_FOLD_BLOCK(aEarthLaneA, 46U, 258U, aEarthLaneB, 15U, 414U, aMuLaneD, 6U);

    // Mu D[7]: aCrystalLaneA[56] + aCrystalLaneB[61].
    KEY_FOLD_BLOCK(aCrystalLaneA, 56U, 450U, aCrystalLaneB, 61U, 144U, aMuLaneD, 7U);

    // Lel — four 512-byte blocks per lane.

    // Lel A[0]: aMuLaneC[7] + aMuLaneB[7].
    KEY_FOLD_BLOCK(aMuLaneC, 7U, 187U, aMuLaneB, 7U, 462U, aLelLaneA, 0U);

    // Lel A[1]: aMuLaneD[0] + aMuLaneA[3].
    KEY_FOLD_BLOCK(aMuLaneD, 0U, 278U, aMuLaneA, 3U, 107U, aLelLaneA, 1U);

    // Lel A[2]: aMuLaneD[7] + aMuLaneB[1].
    KEY_FOLD_BLOCK(aMuLaneD, 7U, 55U, aMuLaneB, 1U, 336U, aLelLaneA, 2U);

    // Lel A[3]: aMuLaneC[0] + aMuLaneA[7].
    KEY_FOLD_BLOCK(aMuLaneC, 0U, 161U, aMuLaneA, 7U, 29U, aLelLaneA, 3U);

    // Lel B[0]: aMuLaneC[4] + aMuLaneD[3].
    KEY_FOLD_BLOCK(aMuLaneC, 4U, 508U, aMuLaneD, 3U, 282U, aLelLaneB, 0U);

    // Lel B[1]: aMuLaneB[4] + aMuLaneC[2].
    KEY_FOLD_BLOCK(aMuLaneB, 4U, 143U, aMuLaneC, 2U, 161U, aLelLaneB, 1U);

    // Lel B[2]: aMuLaneD[5] + aMuLaneA[0].
    KEY_FOLD_BLOCK(aMuLaneD, 5U, 315U, aMuLaneA, 0U, 144U, aLelLaneB, 2U);

    // Lel B[3]: aMuLaneA[5] + aMuLaneB[6].
    KEY_FOLD_BLOCK(aMuLaneA, 5U, 107U, aMuLaneB, 6U, 150U, aLelLaneB, 3U);

    // Lel C[0]: aMuLaneB[3] + aMuLaneD[2].
    KEY_FOLD_BLOCK(aMuLaneB, 3U, 193U, aMuLaneD, 2U, 425U, aLelLaneC, 0U);

    // Lel C[1]: aMuLaneA[2] + aMuLaneC[5].
    KEY_FOLD_BLOCK(aMuLaneA, 2U, 128U, aMuLaneC, 5U, 348U, aLelLaneC, 1U);

    // Lel C[2]: aMuLaneB[0] + aMuLaneC[6].
    KEY_FOLD_BLOCK(aMuLaneB, 0U, 338U, aMuLaneC, 6U, 317U, aLelLaneC, 2U);

    // Lel C[3]: aMuLaneA[6] + aMuLaneD[4].
    KEY_FOLD_BLOCK(aMuLaneA, 6U, 471U, aMuLaneD, 4U, 457U, aLelLaneC, 3U);

    // Lel D[0]: aMuLaneC[1] + aMuLaneB[5].
    KEY_FOLD_BLOCK(aMuLaneC, 1U, 178U, aMuLaneB, 5U, 17U, aLelLaneD, 0U);

    // Lel D[1]: aMuLaneA[4] + aMuLaneD[1].
    KEY_FOLD_BLOCK(aMuLaneA, 4U, 244U, aMuLaneD, 1U, 338U, aLelLaneD, 1U);

    // Lel D[2]: aMuLaneB[2] + aMuLaneA[1].
    KEY_FOLD_BLOCK(aMuLaneB, 2U, 38U, aMuLaneA, 1U, 288U, aLelLaneD, 2U);

    // Lel D[3]: aMuLaneD[6] + aMuLaneC[3].
    KEY_FOLD_BLOCK(aMuLaneD, 6U, 409U, aMuLaneC, 3U, 349U, aLelLaneD, 3U);

    // Goz — two 512-byte blocks per lane.

    // Goz A[0]: aLelLaneA[1] + aLelLaneD[0].
    KEY_FOLD_BLOCK(aLelLaneA, 1U, 155U, aLelLaneD, 0U, 439U, aGozLaneA, 0U);

    // Goz A[1]: aLelLaneB[1] + aLelLaneC[3].
    KEY_FOLD_BLOCK(aLelLaneB, 1U, 42U, aLelLaneC, 3U, 224U, aGozLaneA, 1U);

    // Goz B[0]: aLelLaneA[3] + aLelLaneC[0].
    KEY_FOLD_BLOCK(aLelLaneA, 3U, 108U, aLelLaneC, 0U, 309U, aGozLaneB, 0U);

    // Goz B[1]: aLelLaneB[3] + aLelLaneD[3].
    KEY_FOLD_BLOCK(aLelLaneB, 3U, 217U, aLelLaneD, 3U, 214U, aGozLaneB, 1U);

    // Goz C[0]: aLelLaneD[2] + aLelLaneB[0].
    KEY_FOLD_BLOCK(aLelLaneD, 2U, 429U, aLelLaneB, 0U, 396U, aGozLaneC, 0U);

    // Goz C[1]: aLelLaneA[2] + aLelLaneC[1].
    KEY_FOLD_BLOCK(aLelLaneA, 2U, 169U, aLelLaneC, 1U, 355U, aGozLaneC, 1U);

    // Goz D[0]: aLelLaneA[0] + aLelLaneB[2].
    KEY_FOLD_BLOCK(aLelLaneA, 0U, 510U, aLelLaneB, 2U, 195U, aGozLaneD, 0U);

    // Goz D[1]: aLelLaneD[1] + aLelLaneC[2].
    KEY_FOLD_BLOCK(aLelLaneD, 1U, 206U, aLelLaneC, 2U, 286U, aGozLaneD, 1U);

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

    KEY_FOLD_BLOCK(aGozLaneA, 0U, 76U, aGozLaneB, 0U, 159U, aFinalLaneC + W_KEY, 0U);

    KEY_FOLD_BLOCK(aGozLaneC, 0U, 441U, aGozLaneD, 0U, 200U, aFinalLaneC + W_KEY, 1U);

    KEY_FOLD_BLOCK(aGozLaneA, 1U, 73U, aGozLaneC, 1U, 292U, aFinalLaneC + W_KEY, 2U);

    KEY_FOLD_BLOCK(aGozLaneB, 1U, 273U, aGozLaneD, 1U, 492U, aFinalLaneC + W_KEY, 3U);


    // Grow input D — balanced 512-byte fold graph.

    // Mu — eight 512-byte blocks per lane.

    // Mu A[0]: aEarthLaneD[43] + aEarthLaneC[18].
    KEY_FOLD_BLOCK(aEarthLaneD, 43U, 38U, aEarthLaneC, 18U, 249U, aMuLaneA, 0U);

    // Mu A[1]: aEarthLaneC[52] + aCrystalLaneA[22].
    KEY_FOLD_BLOCK(aEarthLaneC, 52U, 118U, aCrystalLaneA, 22U, 321U, aMuLaneA, 1U);

    // Mu A[2]: aCrystalLaneD[31] + aEarthLaneB[3].
    KEY_FOLD_BLOCK(aCrystalLaneD, 31U, 455U, aEarthLaneB, 3U, 201U, aMuLaneA, 2U);

    // Mu A[3]: aEarthLaneD[35] + aCrystalLaneC[6].
    KEY_FOLD_BLOCK(aEarthLaneD, 35U, 151U, aCrystalLaneC, 6U, 83U, aMuLaneA, 3U);

    // Mu A[4]: aCrystalLaneC[46] + aCrystalLaneA[46].
    KEY_FOLD_BLOCK(aCrystalLaneC, 46U, 347U, aCrystalLaneA, 46U, 221U, aMuLaneA, 4U);

    // Mu A[5]: aEarthLaneB[37] + aEarthLaneA[28].
    KEY_FOLD_BLOCK(aEarthLaneB, 37U, 433U, aEarthLaneA, 28U, 418U, aMuLaneA, 5U);

    // Mu A[6]: aCrystalLaneD[7] + aCrystalLaneB[45].
    KEY_FOLD_BLOCK(aCrystalLaneD, 7U, 88U, aCrystalLaneB, 45U, 354U, aMuLaneA, 6U);

    // Mu A[7]: aCrystalLaneB[63] + aEarthLaneA[6].
    KEY_FOLD_BLOCK(aCrystalLaneB, 63U, 307U, aEarthLaneA, 6U, 186U, aMuLaneA, 7U);

    // Mu B[0]: aEarthLaneC[20] + aEarthLaneA[44].
    KEY_FOLD_BLOCK(aEarthLaneC, 20U, 395U, aEarthLaneA, 44U, 470U, aMuLaneB, 0U);

    // Mu B[1]: aCrystalLaneA[26] + aEarthLaneD[33].
    KEY_FOLD_BLOCK(aCrystalLaneA, 26U, 454U, aEarthLaneD, 33U, 222U, aMuLaneB, 1U);

    // Mu B[2]: aEarthLaneC[30] + aEarthLaneB[1].
    KEY_FOLD_BLOCK(aEarthLaneC, 30U, 303U, aEarthLaneB, 1U, 307U, aMuLaneB, 2U);

    // Mu B[3]: aCrystalLaneC[4] + aCrystalLaneD[15].
    KEY_FOLD_BLOCK(aCrystalLaneC, 4U, 76U, aCrystalLaneD, 15U, 432U, aMuLaneB, 3U);

    // Mu B[4]: aCrystalLaneA[58] + aCrystalLaneB[31].
    KEY_FOLD_BLOCK(aCrystalLaneA, 58U, 426U, aCrystalLaneB, 31U, 494U, aMuLaneB, 4U);

    // Mu B[5]: aCrystalLaneD[17] + aCrystalLaneC[24].
    KEY_FOLD_BLOCK(aCrystalLaneD, 17U, 437U, aCrystalLaneC, 24U, 216U, aMuLaneB, 5U);

    // Mu B[6]: aCrystalLaneB[1] + aEarthLaneB[29].
    KEY_FOLD_BLOCK(aCrystalLaneB, 1U, 119U, aEarthLaneB, 29U, 396U, aMuLaneB, 6U);

    // Mu B[7]: aEarthLaneD[15] + aEarthLaneA[0].
    KEY_FOLD_BLOCK(aEarthLaneD, 15U, 382U, aEarthLaneA, 0U, 245U, aMuLaneB, 7U);

    // Mu C[0]: aEarthLaneD[1] + aCrystalLaneB[53].
    KEY_FOLD_BLOCK(aEarthLaneD, 1U, 65U, aCrystalLaneB, 53U, 134U, aMuLaneC, 0U);

    // Mu C[1]: aCrystalLaneA[62] + aCrystalLaneC[62].
    KEY_FOLD_BLOCK(aCrystalLaneA, 62U, 126U, aCrystalLaneC, 62U, 333U, aMuLaneC, 1U);

    // Mu C[2]: aCrystalLaneB[59] + aEarthLaneC[50].
    KEY_FOLD_BLOCK(aCrystalLaneB, 59U, 500U, aEarthLaneC, 50U, 84U, aMuLaneC, 2U);

    // Mu C[3]: aCrystalLaneC[56] + aCrystalLaneD[57].
    KEY_FOLD_BLOCK(aCrystalLaneC, 56U, 466U, aCrystalLaneD, 57U, 490U, aMuLaneC, 3U);

    // Mu C[4]: aCrystalLaneD[53] + aEarthLaneB[33].
    KEY_FOLD_BLOCK(aCrystalLaneD, 53U, 110U, aEarthLaneB, 33U, 454U, aMuLaneC, 4U);

    // Mu C[5]: aCrystalLaneA[34] + aEarthLaneB[57].
    KEY_FOLD_BLOCK(aCrystalLaneA, 34U, 306U, aEarthLaneB, 57U, 256U, aMuLaneC, 5U);

    // Mu C[6]: aEarthLaneA[38] + aEarthLaneC[24].
    KEY_FOLD_BLOCK(aEarthLaneA, 38U, 464U, aEarthLaneC, 24U, 353U, aMuLaneC, 6U);

    // Mu C[7]: aEarthLaneD[37] + aEarthLaneA[60].
    KEY_FOLD_BLOCK(aEarthLaneD, 37U, 510U, aEarthLaneA, 60U, 20U, aMuLaneC, 7U);

    // Mu D[0]: aEarthLaneC[48] + aCrystalLaneC[34].
    KEY_FOLD_BLOCK(aEarthLaneC, 48U, 396U, aCrystalLaneC, 34U, 194U, aMuLaneD, 0U);

    // Mu D[1]: aEarthLaneB[17] + aEarthLaneA[16].
    KEY_FOLD_BLOCK(aEarthLaneB, 17U, 344U, aEarthLaneA, 16U, 387U, aMuLaneD, 1U);

    // Mu D[2]: aCrystalLaneB[17] + aEarthLaneD[3].
    KEY_FOLD_BLOCK(aCrystalLaneB, 17U, 317U, aEarthLaneD, 3U, 226U, aMuLaneD, 2U);

    // Mu D[3]: aCrystalLaneC[26] + aEarthLaneC[60].
    KEY_FOLD_BLOCK(aCrystalLaneC, 26U, 12U, aEarthLaneC, 60U, 325U, aMuLaneD, 3U);

    // Mu D[4]: aCrystalLaneD[41] + aCrystalLaneA[0].
    KEY_FOLD_BLOCK(aCrystalLaneD, 41U, 203U, aCrystalLaneA, 0U, 48U, aMuLaneD, 4U);

    // Mu D[5]: aEarthLaneA[58] + aEarthLaneB[49].
    KEY_FOLD_BLOCK(aEarthLaneA, 58U, 332U, aEarthLaneB, 49U, 85U, aMuLaneD, 5U);

    // Mu D[6]: aCrystalLaneB[25] + aCrystalLaneD[47].
    KEY_FOLD_BLOCK(aCrystalLaneB, 25U, 132U, aCrystalLaneD, 47U, 199U, aMuLaneD, 6U);

    // Mu D[7]: aCrystalLaneA[4] + aEarthLaneD[11].
    KEY_FOLD_BLOCK(aCrystalLaneA, 4U, 47U, aEarthLaneD, 11U, 316U, aMuLaneD, 7U);

    // Lel — four 512-byte blocks per lane.

    // Lel A[0]: aMuLaneD[6] + aMuLaneC[7].
    KEY_FOLD_BLOCK(aMuLaneD, 6U, 477U, aMuLaneC, 7U, 478U, aLelLaneA, 0U);

    // Lel A[1]: aMuLaneA[2] + aMuLaneC[1].
    KEY_FOLD_BLOCK(aMuLaneA, 2U, 358U, aMuLaneC, 1U, 269U, aLelLaneA, 1U);

    // Lel A[2]: aMuLaneB[1] + aMuLaneA[7].
    KEY_FOLD_BLOCK(aMuLaneB, 1U, 188U, aMuLaneA, 7U, 489U, aLelLaneA, 2U);

    // Lel A[3]: aMuLaneB[7] + aMuLaneD[0].
    KEY_FOLD_BLOCK(aMuLaneB, 7U, 443U, aMuLaneD, 0U, 175U, aLelLaneA, 3U);

    // Lel B[0]: aMuLaneB[4] + aMuLaneA[0].
    KEY_FOLD_BLOCK(aMuLaneB, 4U, 96U, aMuLaneA, 0U, 181U, aLelLaneB, 0U);

    // Lel B[1]: aMuLaneD[3] + aMuLaneC[4].
    KEY_FOLD_BLOCK(aMuLaneD, 3U, 118U, aMuLaneC, 4U, 462U, aLelLaneB, 1U);

    // Lel B[2]: aMuLaneB[0] + aMuLaneD[2].
    KEY_FOLD_BLOCK(aMuLaneB, 0U, 207U, aMuLaneD, 2U, 223U, aLelLaneB, 2U);

    // Lel B[3]: aMuLaneA[5] + aMuLaneC[2].
    KEY_FOLD_BLOCK(aMuLaneA, 5U, 173U, aMuLaneC, 2U, 68U, aLelLaneB, 3U);

    // Lel C[0]: aMuLaneB[2] + aMuLaneA[4].
    KEY_FOLD_BLOCK(aMuLaneB, 2U, 249U, aMuLaneA, 4U, 34U, aLelLaneC, 0U);

    // Lel C[1]: aMuLaneC[6] + aMuLaneD[4].
    KEY_FOLD_BLOCK(aMuLaneC, 6U, 230U, aMuLaneD, 4U, 93U, aLelLaneC, 1U);

    // Lel C[2]: aMuLaneB[3] + aMuLaneD[7].
    KEY_FOLD_BLOCK(aMuLaneB, 3U, 237U, aMuLaneD, 7U, 202U, aLelLaneC, 2U);

    // Lel C[3]: aMuLaneA[1] + aMuLaneC[0].
    KEY_FOLD_BLOCK(aMuLaneA, 1U, 275U, aMuLaneC, 0U, 155U, aLelLaneC, 3U);

    // Lel D[0]: aMuLaneC[3] + aMuLaneD[5].
    KEY_FOLD_BLOCK(aMuLaneC, 3U, 122U, aMuLaneD, 5U, 479U, aLelLaneD, 0U);

    // Lel D[1]: aMuLaneB[5] + aMuLaneD[1].
    KEY_FOLD_BLOCK(aMuLaneB, 5U, 14U, aMuLaneD, 1U, 36U, aLelLaneD, 1U);

    // Lel D[2]: aMuLaneC[5] + aMuLaneA[6].
    KEY_FOLD_BLOCK(aMuLaneC, 5U, 67U, aMuLaneA, 6U, 215U, aLelLaneD, 2U);

    // Lel D[3]: aMuLaneA[3] + aMuLaneB[6].
    KEY_FOLD_BLOCK(aMuLaneA, 3U, 89U, aMuLaneB, 6U, 14U, aLelLaneD, 3U);

    // Goz — two 512-byte blocks per lane.

    // Goz A[0]: aLelLaneB[3] + aLelLaneC[2].
    KEY_FOLD_BLOCK(aLelLaneB, 3U, 497U, aLelLaneC, 2U, 406U, aGozLaneA, 0U);

    // Goz A[1]: aLelLaneA[3] + aLelLaneD[2].
    KEY_FOLD_BLOCK(aLelLaneA, 3U, 18U, aLelLaneD, 2U, 55U, aGozLaneA, 1U);

    // Goz B[0]: aLelLaneC[0] + aLelLaneA[0].
    KEY_FOLD_BLOCK(aLelLaneC, 0U, 324U, aLelLaneA, 0U, 397U, aGozLaneB, 0U);

    // Goz B[1]: aLelLaneB[0] + aLelLaneD[0].
    KEY_FOLD_BLOCK(aLelLaneB, 0U, 241U, aLelLaneD, 0U, 510U, aGozLaneB, 1U);

    // Goz C[0]: aLelLaneA[1] + aLelLaneB[2].
    KEY_FOLD_BLOCK(aLelLaneA, 1U, 448U, aLelLaneB, 2U, 192U, aGozLaneC, 0U);

    // Goz C[1]: aLelLaneD[3] + aLelLaneC[1].
    KEY_FOLD_BLOCK(aLelLaneD, 3U, 297U, aLelLaneC, 1U, 353U, aGozLaneC, 1U);

    // Goz D[0]: aLelLaneA[2] + aLelLaneB[1].
    KEY_FOLD_BLOCK(aLelLaneA, 2U, 32U, aLelLaneB, 1U, 172U, aGozLaneD, 0U);

    // Goz D[1]: aLelLaneD[1] + aLelLaneC[3].
    KEY_FOLD_BLOCK(aLelLaneD, 1U, 446U, aLelLaneC, 3U, 486U, aGozLaneD, 1U);

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

    KEY_FOLD_BLOCK(aGozLaneA, 0U, 304U, aGozLaneB, 0U, 108U, aFinalLaneD + W_KEY, 0U);

    KEY_FOLD_BLOCK(aGozLaneC, 0U, 51U, aGozLaneD, 0U, 3U, aFinalLaneD + W_KEY, 1U);

    KEY_FOLD_BLOCK(aGozLaneA, 1U, 212U, aGozLaneC, 1U, 438U, aFinalLaneD + W_KEY, 2U);

    KEY_FOLD_BLOCK(aGozLaneB, 1U, 382U, aGozLaneD, 1U, 55U, aFinalLaneD + W_KEY, 3U);

}
