
void TwistExpander_Aldebaran::TwistForkKeyHalfA(TwistWorkSpace *pWorkSpace) {
    static_assert(S_BLOCK == 32768, "Twist fork source size changed.");
    static_assert(S_HALF == 16384, "Twist fork half size changed.");
    static_assert(W_KEY == 2048, "Twist fork key size changed.");

    std::uint8_t *aSourceLaneA = pWorkSpace->mCrystalLaneA;
    std::uint8_t *aSourceLaneB = pWorkSpace->mCrystalLaneB;
    std::uint8_t *aSourceLaneC = pWorkSpace->mCrystalLaneC;
    std::uint8_t *aSourceLaneD = pWorkSpace->mCrystalLaneD;

    std::uint8_t *aStageOneLaneA = pWorkSpace->mCelestialLaneA;
    std::uint8_t *aStageOneLaneB = pWorkSpace->mCelestialLaneB;
    std::uint8_t *aStageOneLaneC = pWorkSpace->mCelestialLaneC;
    std::uint8_t *aStageOneLaneD = pWorkSpace->mCelestialLaneD;

    std::uint8_t *aStageTwoLaneA = pWorkSpace->mSpiritLaneA;
    std::uint8_t *aStageTwoLaneB = pWorkSpace->mSpiritLaneB;
    std::uint8_t *aStageTwoLaneC = pWorkSpace->mSpiritLaneC;
    std::uint8_t *aStageTwoLaneD = pWorkSpace->mSpiritLaneD;

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

    std::uint8_t *aSourceLaneA = pWorkSpace->mCrystalLaneA;
    std::uint8_t *aSourceLaneB = pWorkSpace->mCrystalLaneB;
    std::uint8_t *aSourceLaneC = pWorkSpace->mCrystalLaneC;
    std::uint8_t *aSourceLaneD = pWorkSpace->mCrystalLaneD;

    std::uint8_t *aStageOneLaneA = pWorkSpace->mCelestialLaneA;
    std::uint8_t *aStageOneLaneB = pWorkSpace->mCelestialLaneB;
    std::uint8_t *aStageOneLaneC = pWorkSpace->mCelestialLaneC;
    std::uint8_t *aStageOneLaneD = pWorkSpace->mCelestialLaneD;

    std::uint8_t *aStageTwoLaneA = pWorkSpace->mDivinationLaneA;
    std::uint8_t *aStageTwoLaneB = pWorkSpace->mDivinationLaneB;
    std::uint8_t *aStageTwoLaneC = pWorkSpace->mDivinationLaneC;
    std::uint8_t *aStageTwoLaneD = pWorkSpace->mDivinationLaneD;

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
