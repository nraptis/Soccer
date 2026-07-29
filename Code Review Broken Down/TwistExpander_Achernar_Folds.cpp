void TwistExpander_Achernar::FoldKeyRows(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    // GrowAControl candidate 1 of 33
    // Exploration cases: 0
    // Structural distance: baseline candidate
    std::uint8_t *aGrowAAetherLaneA = pWorkSpace->mAetherLaneA;
    std::uint8_t *aGrowAAetherLaneB = pWorkSpace->mAetherLaneB;
    std::uint8_t *aGrowAAetherLaneC = pWorkSpace->mAetherLaneC;
    std::uint8_t *aGrowAAetherLaneD = pWorkSpace->mAetherLaneD;
    std::uint8_t *aGrowAVaporLaneA = pWorkSpace->mVaporLaneA;
    std::uint8_t *aGrowAVaporLaneB = pWorkSpace->mVaporLaneB;
    std::uint8_t *aGrowAVaporLaneC = pWorkSpace->mVaporLaneC;
    std::uint8_t *aGrowAVaporLaneD = pWorkSpace->mVaporLaneD;
    std::uint8_t *aGrowAShadowLaneA = pWorkSpace->mShadowLaneA;
    std::uint8_t *aGrowAShadowLaneB = pWorkSpace->mShadowLaneB;
    std::uint8_t *aGrowAShadowLaneC = pWorkSpace->mShadowLaneC;
    std::uint8_t *aGrowAShadowLaneD = pWorkSpace->mShadowLaneD;
    std::uint8_t *aGrowAKeyRowWrite = &(pWorkSpace->mKeyBoxA[0][0]);
    
    static_assert((S_BLOCK / S_QUARTER) == 4, "GrowKeyA expects four expansion-lane quarters.");
    static_assert((S_QUARTER / W_KEY) == 4, "GrowKeyA expects four key chunks per quarter.");
    TwistShiftBox::ShiftKeyBoxA(pWorkSpace);
    
    const std::size_t aFoldBaseA = 3U * S_QUARTER;
    const std::size_t aFoldBaseB = 0U * S_QUARTER;
    const std::size_t aFoldBaseC = 2U * S_QUARTER;
    const std::size_t aFoldBaseD = 3U * S_QUARTER;
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
        const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7879U) & S_QUARTER1);
        const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 137U) & S_QUARTER1);
        const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3828U) & S_QUARTER1);
        const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4008U) & S_QUARTER1);
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
        (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 8U);
        aFoldWord = TwistMix32::DiffuseC(aFoldWord);
        aGrowAVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
    }
    
    const std::size_t aFoldBaseA = 0U * S_QUARTER;
    const std::size_t aFoldBaseB = 1U * S_QUARTER;
    const std::size_t aFoldBaseC = 1U * S_QUARTER;
    const std::size_t aFoldBaseD = 2U * S_QUARTER;
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
        const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3738U) & S_QUARTER1);
        const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7789U) & S_QUARTER1);
        const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 4188U) & S_QUARTER1);
        const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3558U) & S_QUARTER1);
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 16U) |
        (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
        aFoldWord = TwistMix32::DiffuseC(aFoldWord);
        aGrowAVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
    }
    
    const std::size_t aFoldBaseA = 1U * S_QUARTER;
    const std::size_t aFoldBaseB = 2U * S_QUARTER;
    const std::size_t aFoldBaseC = 3U * S_QUARTER;
    const std::size_t aFoldBaseD = 1U * S_QUARTER;
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
        const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7969U) & S_QUARTER1);
        const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8149U) & S_QUARTER1);
        const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7699U) & S_QUARTER1);
        const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 4098U) & S_QUARTER1);
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
        (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 16U);
        aFoldWord = TwistMix32::DiffuseC(aFoldWord);
        aGrowAVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
    }
    
    const std::size_t aFoldBaseA = 2U * S_QUARTER;
    const std::size_t aFoldBaseB = 3U * S_QUARTER;
    const std::size_t aFoldBaseC = 0U * S_QUARTER;
    const std::size_t aFoldBaseD = 0U * S_QUARTER;
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
        const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3648U) & S_QUARTER1);
        const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8059U) & S_QUARTER1);
        const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 47U) & S_QUARTER1);
        const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3918U) & S_QUARTER1);
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aGrowAAetherLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAAetherLaneB[aFoldIndexB]) << 0U) |
        (static_cast<std::uint32_t>(aGrowAAetherLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowAAetherLaneD[aFoldIndexD]) << 24U);
        aFoldWord = TwistMix32::DiffuseC(aFoldWord);
        aGrowAVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
    }
    
    const std::size_t aFoldBaseA = 1U * W_KEY;
    const std::size_t aFoldBaseB = 3U * W_KEY;
    const std::size_t aFoldBaseC = 1U * W_KEY;
    const std::size_t aFoldBaseD = 2U * W_KEY;
    for (;;/*W_KEY*/) {
        const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1375U) & W_KEY1);
        const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1825U) & W_KEY1);
        const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1960U) & W_KEY1);
        const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1915U) & W_KEY1);
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
        (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 8U);
        aFoldWord = TwistMix32::DiffuseB(aFoldWord);
        aGrowAShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
    }
    
    const std::size_t aFoldBaseA = 0U * W_KEY;
    const std::size_t aFoldBaseB = 1U * W_KEY;
    const std::size_t aFoldBaseC = 0U * W_KEY;
    const std::size_t aFoldBaseD = 3U * W_KEY;
    for (;;/*W_KEY*/) {
        const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2005U) & W_KEY1);
        const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1870U) & W_KEY1);
        const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1465U) & W_KEY1);
        const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1780U) & W_KEY1);
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
        (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
        aFoldWord = TwistMix32::DiffuseA(aFoldWord);
        aGrowAShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
    }
    
    const std::size_t aFoldBaseA = 3U * W_KEY;
    const std::size_t aFoldBaseB = 2U * W_KEY;
    const std::size_t aFoldBaseC = 2U * W_KEY;
    const std::size_t aFoldBaseD = 1U * W_KEY;
    for (;;/*W_KEY*/) {
        const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 92U) & W_KEY1);
        const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1510U) & W_KEY1);
        const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1420U) & W_KEY1);
        const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1330U) & W_KEY1);
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 8U) |
        (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 0U);
        aFoldWord = TwistMix32::DiffuseC(aFoldWord);
        aGrowAShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
    }
    
    const std::size_t aFoldBaseA = 2U * W_KEY;
    const std::size_t aFoldBaseB = 0U * W_KEY;
    const std::size_t aFoldBaseC = 3U * W_KEY;
    const std::size_t aFoldBaseD = 0U * W_KEY;
    for (;;/*W_KEY*/) {
        const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2U) & W_KEY1);
        const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1555U) & W_KEY1);
        const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1600U) & W_KEY1);
        const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1735U) & W_KEY1);
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aGrowAVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowAVaporLaneB[aFoldIndexB]) << 0U) |
        (static_cast<std::uint32_t>(aGrowAVaporLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowAVaporLaneD[aFoldIndexD]) << 24U);
        aFoldWord = TwistMix32::DiffuseB(aFoldWord);
        aGrowAShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
    }
    
    for (;;/*W_KEY*/) {
        const std::size_t aFoldIndexA = (aIndex + 1690U) & W_KEY1;
        const std::size_t aFoldIndexB = (aIndex + 1645U) & W_KEY1;
        const std::size_t aFoldIndexC = (aIndex + 47U) & W_KEY1;
        const std::size_t aFoldIndexD = (aIndex + 137U) & W_KEY1;
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aGrowAShadowLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowAShadowLaneB[aFoldIndexB]) << 24U) |
        (static_cast<std::uint32_t>(aGrowAShadowLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowAShadowLaneD[aFoldIndexD]) << 16U);
        aFoldWord = TwistMix32::DiffuseC(aFoldWord);
        aGrowAKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
    }
    
    
    //
    // GrowBControl candidate 1 of 33
    // Exploration cases: 0
    // Structural distance: baseline candidate
    std::uint8_t *aGrowBCrystalLaneA = pWorkSpace->mCrystalLaneA;
    std::uint8_t *aGrowBCrystalLaneB = pWorkSpace->mCrystalLaneB;
    std::uint8_t *aGrowBCrystalLaneC = pWorkSpace->mCrystalLaneC;
    std::uint8_t *aGrowBCrystalLaneD = pWorkSpace->mCrystalLaneD;
    std::uint8_t *aGrowBVaporLaneA = pWorkSpace->mVaporLaneA;
    std::uint8_t *aGrowBVaporLaneB = pWorkSpace->mVaporLaneB;
    std::uint8_t *aGrowBVaporLaneC = pWorkSpace->mVaporLaneC;
    std::uint8_t *aGrowBVaporLaneD = pWorkSpace->mVaporLaneD;
    std::uint8_t *aGrowBShadowLaneA = pWorkSpace->mShadowLaneA;
    std::uint8_t *aGrowBShadowLaneB = pWorkSpace->mShadowLaneB;
    std::uint8_t *aGrowBShadowLaneC = pWorkSpace->mShadowLaneC;
    std::uint8_t *aGrowBShadowLaneD = pWorkSpace->mShadowLaneD;
    std::uint8_t *aGrowBKeyRowWrite = &(pWorkSpace->mKeyBoxB[0][0]);
    static_assert((S_BLOCK / S_QUARTER) == 4, "GrowKeyB expects four operation-lane quarters.");
    static_assert((S_QUARTER / W_KEY) == 4, "GrowKeyB expects four key chunks per quarter.");
    TwistShiftBox::ShiftKeyBoxB(pWorkSpace);
    
    const std::size_t aFoldBaseA = 3U * S_QUARTER;
    const std::size_t aFoldBaseB = 0U * S_QUARTER;
    const std::size_t aFoldBaseC = 2U * S_QUARTER;
    const std::size_t aFoldBaseD = 3U * S_QUARTER;
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
        const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7249U) & S_QUARTER1);
        const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2928U) & S_QUARTER1);
        const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3198U) & S_QUARTER1);
        const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3018U) & S_QUARTER1);
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 24U) |
        (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 8U);
        aFoldWord = TwistMix32::DiffuseB(aFoldWord);
        aGrowBVaporLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
    }
    
    const std::size_t aFoldBaseA = 2U * S_QUARTER;
    const std::size_t aFoldBaseB = 3U * S_QUARTER;
    const std::size_t aFoldBaseC = 3U * S_QUARTER;
    const std::size_t aFoldBaseD = 1U * S_QUARTER;
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
        const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7609U) & S_QUARTER1);
        const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7159U) & S_QUARTER1);
        const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3288U) & S_QUARTER1);
        const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7429U) & S_QUARTER1);
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 16U) |
        (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 0U);
        aFoldWord = TwistMix32::DiffuseC(aFoldWord);
        aGrowBVaporLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
    }
    
    const std::size_t aFoldBaseA = 1U * S_QUARTER;
    const std::size_t aFoldBaseB = 2U * S_QUARTER;
    const std::size_t aFoldBaseC = 0U * S_QUARTER;
    const std::size_t aFoldBaseD = 0U * S_QUARTER;
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
        const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3108U) & S_QUARTER1);
        const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7519U) & S_QUARTER1);
        const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6979U) & S_QUARTER1);
        const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7069U) & S_QUARTER1);
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 8U) |
        (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
        aFoldWord = TwistMix32::DiffuseA(aFoldWord);
        aGrowBVaporLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
    }
    
    const std::size_t aFoldBaseA = 0U * S_QUARTER;
    const std::size_t aFoldBaseB = 1U * S_QUARTER;
    const std::size_t aFoldBaseC = 1U * S_QUARTER;
    const std::size_t aFoldBaseD = 2U * S_QUARTER;
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
        const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 3378U) & S_QUARTER1);
        const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7339U) & S_QUARTER1);
        const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3468U) & S_QUARTER1);
        const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2838U) & S_QUARTER1);
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aGrowBCrystalLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneB[aFoldIndexB]) << 0U) |
        (static_cast<std::uint32_t>(aGrowBCrystalLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBCrystalLaneD[aFoldIndexD]) << 24U);
        aFoldWord = TwistMix32::DiffuseC(aFoldWord);
        aGrowBVaporLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
    }
    
    const std::size_t aFoldBaseA = 0U * W_KEY;
    const std::size_t aFoldBaseB = 1U * W_KEY;
    const std::size_t aFoldBaseC = 2U * W_KEY;
    const std::size_t aFoldBaseD = 0U * W_KEY;
    for (;;/*W_KEY*/) {
        const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1195U) & W_KEY1);
        const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 880U) & W_KEY1);
        const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1015U) & W_KEY1);
        const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1060U) & W_KEY1);
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 16U) |
        (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 24U);
        aFoldWord = TwistMix32::DiffuseC(aFoldWord);
        aGrowBShadowLaneA[aIndex] = static_cast<std::uint8_t>(aFoldWord);
    }
    
    const std::size_t aFoldBaseA = 1U * W_KEY;
    const std::size_t aFoldBaseB = 0U * W_KEY;
    const std::size_t aFoldBaseC = 3U * W_KEY;
    const std::size_t aFoldBaseD = 1U * W_KEY;
    for (;;/*W_KEY*/) {
        const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 565U) & W_KEY1);
        const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 970U) & W_KEY1);
        const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 745U) & W_KEY1);
        const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 655U) & W_KEY1);
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 24U) |
        (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 8U);
        aFoldWord = TwistMix32::DiffuseB(aFoldWord);
        aGrowBShadowLaneB[aIndex] = static_cast<std::uint8_t>(aFoldWord);
    }
    
    const std::size_t aFoldBaseA = 3U * W_KEY;
    const std::size_t aFoldBaseB = 2U * W_KEY;
    const std::size_t aFoldBaseC = 1U * W_KEY;
    const std::size_t aFoldBaseD = 3U * W_KEY;
    for (;;/*W_KEY*/) {
        const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 835U) & W_KEY1);
        const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 790U) & W_KEY1);
        const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1285U) & W_KEY1);
        const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1240U) & W_KEY1);
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
        (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 16U);
        aFoldWord = TwistMix32::DiffuseB(aFoldWord);
        aGrowBShadowLaneC[aIndex] = static_cast<std::uint8_t>(aFoldWord);
    }
    
    const std::size_t aFoldBaseA = 2U * W_KEY;
    const std::size_t aFoldBaseB = 3U * W_KEY;
    const std::size_t aFoldBaseC = 0U * W_KEY;
    const std::size_t aFoldBaseD = 2U * W_KEY;
    for (;;/*W_KEY*/) {
        const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 520U) & W_KEY1);
        const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 925U) & W_KEY1);
        const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 700U) & W_KEY1);
        const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 430U) & W_KEY1);
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aGrowBVaporLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aGrowBVaporLaneB[aFoldIndexB]) << 8U) |
        (static_cast<std::uint32_t>(aGrowBVaporLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aGrowBVaporLaneD[aFoldIndexD]) << 0U);
        aFoldWord = TwistMix32::DiffuseA(aFoldWord);
        aGrowBShadowLaneD[aIndex] = static_cast<std::uint8_t>(aFoldWord);
    }
    
    for (;;/*W_KEY*/) {
        const std::size_t aFoldIndexA = (aIndex + 1150U) & W_KEY1;
        const std::size_t aFoldIndexB = (aIndex + 1105U) & W_KEY1;
        const std::size_t aFoldIndexC = (aIndex + 610U) & W_KEY1;
        const std::size_t aFoldIndexD = (aIndex + 475U) & W_KEY1;
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aGrowBShadowLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aGrowBShadowLaneB[aFoldIndexB]) << 16U) |
        (static_cast<std::uint32_t>(aGrowBShadowLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aGrowBShadowLaneD[aFoldIndexD]) << 24U);
        aFoldWord = TwistMix32::DiffuseB(aFoldWord);
        aGrowBKeyRowWrite[aIndex] = static_cast<std::uint8_t>(aFoldWord);
    }
    
}
