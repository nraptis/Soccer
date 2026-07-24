
void TwistExpander_Achernar::SquashInvestToKeyBoxes(TwistWorkSpace *pWorkSpace) {
    
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;
    
    
    std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 14U), *aFragmentB = aIceLaneB + (W_KEY * 2U);
    std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 6U), *aFragmentD = aIceLaneD + (W_KEY * 10U);
    std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[0][0]);
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
        std::uint32_t aSquash =
        (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1639U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 313U) & W_KEY1)]) << 16U) |
        (static_cast<std::uint32_t>(aFragmentC[((aIndex + 698U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1781U) & W_KEY1)]) << 24U);
        aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
    }
    std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 6U), *aFragmentB = aIceLaneB + (W_KEY * 8U);
    std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 12U), *aFragmentD = aIceLaneD + (W_KEY * 3U);
    std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[1][0]);
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
        std::uint32_t aSquash =
        (static_cast<std::uint32_t>(aFragmentA[((aIndex + 706U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1603U) & W_KEY1)]) << 24U) |
        (static_cast<std::uint32_t>(aFragmentC[((aIndex + 525U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1769U) & W_KEY1)]) << 16U);
        aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
    }
    std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 2U), *aFragmentB = aIceLaneB + (W_KEY * 13U);
    std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 0U), *aFragmentD = aIceLaneD + (W_KEY * 9U);
    std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[2][0]);
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
        std::uint32_t aSquash =
        (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1581U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 989U) & W_KEY1)]) << 0U) |
        (static_cast<std::uint32_t>(aFragmentC[((aIndex + 516U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 633U) & W_KEY1)]) << 8U);
        aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
    }
    std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 7U), *aFragmentB = aIceLaneB + (W_KEY * 11U);
    std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 11U), *aFragmentD = aIceLaneD + (W_KEY * 5U);
    std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[3][0]);
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
        std::uint32_t aSquash =
        (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1145U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 990U) & W_KEY1)]) << 0U) |
        (static_cast<std::uint32_t>(aFragmentC[((aIndex + 126U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1430U) & W_KEY1)]) << 24U);
        aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
    }
    std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 5U), *aFragmentB = aIceLaneB + (W_KEY * 5U);
    std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 9U), *aFragmentD = aIceLaneD + (W_KEY * 13U);
    std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[4][0]);
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
        std::uint32_t aSquash =
        (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1793U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1531U) & W_KEY1)]) << 24U) |
        (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1778U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1801U) & W_KEY1)]) << 8U);
        aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
    }
    std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 1U), *aFragmentB = aIceLaneB + (W_KEY * 4U);
    std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 8U), *aFragmentD = aIceLaneD + (W_KEY * 12U);
    std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[5][0]);
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
        std::uint32_t aSquash =
        (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1080U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 165U) & W_KEY1)]) << 24U) |
        (static_cast<std::uint32_t>(aFragmentC[((aIndex + 40U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 48U) & W_KEY1)]) << 8U);
        aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
    }
    std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 11U), *aFragmentB = aIceLaneB + (W_KEY * 15U);
    std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 14U), *aFragmentD = aIceLaneD + (W_KEY * 1U);
    std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[6][0]);
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
        std::uint32_t aSquash =
        (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1779U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 360U) & W_KEY1)]) << 16U) |
        (static_cast<std::uint32_t>(aFragmentC[((aIndex + 27U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 777U) & W_KEY1)]) << 0U);
        aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
    }
    std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 0U), *aFragmentB = aIceLaneB + (W_KEY * 6U);
    std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 3U), *aFragmentD = aIceLaneD + (W_KEY * 4U);
    std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxA[7][0]);
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
        std::uint32_t aSquash =
        (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1162U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 834U) & W_KEY1)]) << 0U) |
        (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1214U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 930U) & W_KEY1)]) << 8U);
        aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
    }
    std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 15U), *aFragmentB = aIceLaneB + (W_KEY * 14U);
    std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 15U), *aFragmentD = aIceLaneD + (W_KEY * 6U);
    std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[0][0]);
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
        std::uint32_t aSquash =
        (static_cast<std::uint32_t>(aFragmentA[((aIndex + 183U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1454U) & W_KEY1)]) << 8U) |
        (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1734U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1787U) & W_KEY1)]) << 0U);
        aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
    }
    std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 13U), *aFragmentB = aIceLaneB + (W_KEY * 3U);
    std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 13U), *aFragmentD = aIceLaneD + (W_KEY * 7U);
    std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[1][0]);
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
        std::uint32_t aSquash =
        (static_cast<std::uint32_t>(aFragmentA[((aIndex + 194U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1348U) & W_KEY1)]) << 0U) |
        (static_cast<std::uint32_t>(aFragmentC[((aIndex + 864U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 278U) & W_KEY1)]) << 24U);
        aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
    }
    std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 3U), *aFragmentB = aIceLaneB + (W_KEY * 1U);
    std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 4U), *aFragmentD = aIceLaneD + (W_KEY * 14U);
    std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[2][0]);
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
        std::uint32_t aSquash =
        (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1387U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1092U) & W_KEY1)]) << 24U) |
        (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1668U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1817U) & W_KEY1)]) << 0U);
        aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseB(aSquash));
    }
    std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 10U), *aFragmentB = aIceLaneB + (W_KEY * 10U);
    std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 1U), *aFragmentD = aIceLaneD + (W_KEY * 0U);
    std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[3][0]);
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
        std::uint32_t aSquash =
        (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1890U) & W_KEY1)]) << 24U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1043U) & W_KEY1)]) << 16U) |
        (static_cast<std::uint32_t>(aFragmentC[((aIndex + 1600U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1718U) & W_KEY1)]) << 0U);
        aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
    }
    std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 9U), *aFragmentB = aIceLaneB + (W_KEY * 12U);
    std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 5U), *aFragmentD = aIceLaneD + (W_KEY * 2U);
    std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[4][0]);
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
        std::uint32_t aSquash =
        (static_cast<std::uint32_t>(aFragmentA[((aIndex + 474U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1228U) & W_KEY1)]) << 24U) |
        (static_cast<std::uint32_t>(aFragmentC[((aIndex + 527U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 675U) & W_KEY1)]) << 8U);
        aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
    }
    std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 8U), *aFragmentB = aIceLaneB + (W_KEY * 9U);
    std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 10U), *aFragmentD = aIceLaneD + (W_KEY * 15U);
    std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[5][0]);
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
        std::uint32_t aSquash =
        (static_cast<std::uint32_t>(aFragmentA[((aIndex + 177U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1622U) & W_KEY1)]) << 24U) |
        (static_cast<std::uint32_t>(aFragmentC[((aIndex + 85U) & W_KEY1)]) << 0U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 483U) & W_KEY1)]) << 8U);
        aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseC(aSquash));
    }
    std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 4U), *aFragmentB = aIceLaneB + (W_KEY * 7U);
    std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 7U), *aFragmentD = aIceLaneD + (W_KEY * 8U);
    std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[6][0]);
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
        std::uint32_t aSquash =
        (static_cast<std::uint32_t>(aFragmentA[((aIndex + 861U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 34U) & W_KEY1)]) << 0U) |
        (static_cast<std::uint32_t>(aFragmentC[((aIndex + 169U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 790U) & W_KEY1)]) << 24U);
        aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
    }
    std::uint8_t *aFragmentA = aIceLaneA + (W_KEY * 12U), *aFragmentB = aIceLaneB + (W_KEY * 0U);
    std::uint8_t *aFragmentC = aIceLaneC + (W_KEY * 2U), *aFragmentD = aIceLaneD + (W_KEY * 11U);
    std::uint8_t *aKeyRow = &(pWorkSpace->mKeyBoxB[7][0]);
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
        std::uint32_t aSquash =
        (static_cast<std::uint32_t>(aFragmentA[((aIndex + 1188U) & W_KEY1)]) << 8U) | (static_cast<std::uint32_t>(aFragmentB[((aIndex + 1464U) & W_KEY1)]) << 0U) |
        (static_cast<std::uint32_t>(aFragmentC[((aIndex + 854U) & W_KEY1)]) << 16U) | (static_cast<std::uint32_t>(aFragmentD[((aIndex + 1854U) & W_KEY1)]) << 24U);
        aKeyRow[aIndex] = static_cast<std::uint8_t>(TwistMix32::DiffuseA(aSquash));
    }
    
}


void TwistExpander_Achernar::GrowKeyA(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aIceLaneA = pWorkSpace->mIceLaneA;
    std::uint8_t *aIceLaneB = pWorkSpace->mIceLaneB;
    std::uint8_t *aIceLaneC = pWorkSpace->mIceLaneC;
    std::uint8_t *aIceLaneD = pWorkSpace->mIceLaneD;
    std::uint8_t *aWaterLaneA = pWorkSpace->mWaterLaneA;
    std::uint8_t *aWaterLaneB = pWorkSpace->mWaterLaneB;
    std::uint8_t *aWaterLaneC = pWorkSpace->mWaterLaneC;
    std::uint8_t *aWaterLaneD = pWorkSpace->mWaterLaneD;
    std::uint8_t *aPoisonLaneA = pWorkSpace->mPoisonLaneA;
    std::uint8_t *aPoisonLaneB = pWorkSpace->mPoisonLaneB;
    std::uint8_t *aPoisonLaneC = pWorkSpace->mPoisonLaneC;
    std::uint8_t *aPoisonLaneD = pWorkSpace->mPoisonLaneD;
    std::uint8_t *aKeyRowWriteA = &(pWorkSpace->mKeyBoxA[0][0]);
    
    TwistShiftBox::ShiftKeyBoxA(pWorkSpace);
    
    
    const std::size_t aFoldBaseA = 3U * S_QUARTER;
    const std::size_t aFoldBaseB = 0U * S_QUARTER;
    const std::size_t aFoldBaseC = 1U * S_QUARTER;
    const std::size_t aFoldBaseD = 0U * S_QUARTER;
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
        const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1255U) & S_QUARTER1);
        const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6354U) & S_QUARTER1);
        const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1878U) & S_QUARTER1);
        const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 2148U) & S_QUARTER1);
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
        (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
        aFoldWord = TwistMix32::DiffuseC(aFoldWord);
        aWaterLaneA[aIndex] = aFoldWord;
    }
    
    const std::size_t aFoldBaseA = 1U * S_QUARTER;
    const std::size_t aFoldBaseB = 3U * S_QUARTER;
    const std::size_t aFoldBaseC = 2U * S_QUARTER;
    const std::size_t aFoldBaseD = 3U * S_QUARTER;
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
        const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 6739U) & S_QUARTER1);
        const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1069U) & S_QUARTER1);
        const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3370U) & S_QUARTER1);
        const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1422U) & S_QUARTER1);
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 8U) |
        (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 16U);
        aFoldWord = TwistMix32::DiffuseC(aFoldWord);
        aWaterLaneB[aIndex] = aFoldWord;
    }
    
    const std::size_t aFoldBaseA = 2U * S_QUARTER;
    const std::size_t aFoldBaseB = 1U * S_QUARTER;
    const std::size_t aFoldBaseC = 0U * S_QUARTER;
    const std::size_t aFoldBaseD = 1U * S_QUARTER;
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
        const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 5071U) & S_QUARTER1);
        const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 560U) & S_QUARTER1);
        const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3627U) & S_QUARTER1);
        const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5330U) & S_QUARTER1);
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 0U) |
        (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 24U);
        aFoldWord = TwistMix32::DiffuseB(aFoldWord);
        aWaterLaneC[aIndex] = aFoldWord;
    }
    
    const std::size_t aFoldBaseA = 0U * S_QUARTER;
    const std::size_t aFoldBaseB = 2U * S_QUARTER;
    const std::size_t aFoldBaseC = 3U * S_QUARTER;
    const std::size_t aFoldBaseD = 2U * S_QUARTER;
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
        const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 753U) & S_QUARTER1);
        const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5731U) & S_QUARTER1);
        const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 6626U) & S_QUARTER1);
        const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3580U) & S_QUARTER1);
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aIceLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aIceLaneB[aFoldIndexB]) << 24U) |
        (static_cast<std::uint32_t>(aIceLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aIceLaneD[aFoldIndexD]) << 0U);
        aFoldWord = TwistMix32::DiffuseA(aFoldWord);
        aWaterLaneD[aIndex] = aFoldWord;
    }
    
    const std::size_t aFoldBaseA = 1U * W_KEY;
    const std::size_t aFoldBaseB = 2U * W_KEY;
    const std::size_t aFoldBaseC = 2U * W_KEY;
    const std::size_t aFoldBaseD = 0U * W_KEY;
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
        const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 387U) & W_KEY1);
        const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 286U) & W_KEY1);
        const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1985U) & W_KEY1);
        const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1114U) & W_KEY1);
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
        (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 24U);
        aFoldWord = TwistMix32::DiffuseA(aFoldWord);
        aPoisonLaneA[aIndex] = aFoldWord;
    }
    
    const std::size_t aFoldBaseA = 0U * W_KEY;
    const std::size_t aFoldBaseB = 3U * W_KEY;
    const std::size_t aFoldBaseC = 0U * W_KEY;
    const std::size_t aFoldBaseD = 1U * W_KEY;
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
        const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 401U) & W_KEY1);
        const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1285U) & W_KEY1);
        const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1071U) & W_KEY1);
        const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 316U) & W_KEY1);
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
        (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
        aFoldWord = TwistMix32::DiffuseA(aFoldWord);
        aPoisonLaneB[aIndex] = aFoldWord;
    }
    
    const std::size_t aFoldBaseA = 2U * W_KEY;
    const std::size_t aFoldBaseB = 1U * W_KEY;
    const std::size_t aFoldBaseC = 3U * W_KEY;
    const std::size_t aFoldBaseD = 3U * W_KEY;
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
        const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 526U) & W_KEY1);
        const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 767U) & W_KEY1);
        const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 517U) & W_KEY1);
        const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 659U) & W_KEY1);
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
        (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
        aFoldWord = TwistMix32::DiffuseB(aFoldWord);
        aPoisonLaneC[aIndex] = aFoldWord;
    }
    
    const std::size_t aFoldBaseA = 3U * W_KEY;
    const std::size_t aFoldBaseB = 0U * W_KEY;
    const std::size_t aFoldBaseC = 1U * W_KEY;
    const std::size_t aFoldBaseD = 2U * W_KEY;
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
        const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1807U) & W_KEY1);
        const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 507U) & W_KEY1);
        const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1109U) & W_KEY1);
        const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 96U) & W_KEY1);
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 0U) |
        (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 16U);
        aFoldWord = TwistMix32::DiffuseB(aFoldWord);
        aPoisonLaneD[aIndex] = aFoldWord;
    }
    
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
        const std::size_t aFoldIndexA = (aIndex + 1030U) & W_KEY1;
        const std::size_t aFoldIndexB = (aIndex + 485U) & W_KEY1;
        const std::size_t aFoldIndexC = (aIndex + 1346U) & W_KEY1;
        const std::size_t aFoldIndexD = (aIndex + 966U) & W_KEY1;
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 16U) |
        (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 8U);
        aFoldWord = TwistMix32::DiffuseA(aFoldWord);
        aKeyRowWriteA[aIndex] = aFoldWord;
    }
}

// GrowB candidate 1 of 33
// Exploration cases: 100000000
// Total structural distance: baseline candidate
void TwistExpander_Achernar::GrowKeyB(TwistWorkSpace *pWorkSpace) {
    if (pWorkSpace == nullptr) { return; }
    std::uint8_t *aSpiritLaneA = pWorkSpace->mSpiritLaneA;
    std::uint8_t *aSpiritLaneB = pWorkSpace->mSpiritLaneB;
    std::uint8_t *aSpiritLaneC = pWorkSpace->mSpiritLaneC;
    std::uint8_t *aSpiritLaneD = pWorkSpace->mSpiritLaneD;
    std::uint8_t *aWaterLaneA = pWorkSpace->mWaterLaneA;
    std::uint8_t *aWaterLaneB = pWorkSpace->mWaterLaneB;
    std::uint8_t *aWaterLaneC = pWorkSpace->mWaterLaneC;
    std::uint8_t *aWaterLaneD = pWorkSpace->mWaterLaneD;
    std::uint8_t *aPoisonLaneA = pWorkSpace->mPoisonLaneA;
    std::uint8_t *aPoisonLaneB = pWorkSpace->mPoisonLaneB;
    std::uint8_t *aPoisonLaneC = pWorkSpace->mPoisonLaneC;
    std::uint8_t *aPoisonLaneD = pWorkSpace->mPoisonLaneD;
    std::uint8_t *aKeyRowWriteB = &(pWorkSpace->mKeyBoxB[0][0]);
    
    TwistShiftBox::ShiftKeyBoxB(pWorkSpace);
    
    const std::size_t aFoldBaseA = 1U * S_QUARTER;
    const std::size_t aFoldBaseB = 2U * S_QUARTER;
    const std::size_t aFoldBaseC = 0U * S_QUARTER;
    const std::size_t aFoldBaseD = 1U * S_QUARTER;
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
        const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1199U) & S_QUARTER1);
        const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 704U) & S_QUARTER1);
        const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5970U) & S_QUARTER1);
        const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3590U) & S_QUARTER1);
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 0U) |
        (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 8U);
        aFoldWord = TwistMix32::DiffuseA(aFoldWord);
        aWaterLaneA[aIndex] = aFoldWord;
    }
    const std::size_t aFoldBaseA = 0U * S_QUARTER;
    const std::size_t aFoldBaseB = 0U * S_QUARTER;
    const std::size_t aFoldBaseC = 1U * S_QUARTER;
    const std::size_t aFoldBaseD = 3U * S_QUARTER;
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
        const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 63U) & S_QUARTER1);
        const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6818U) & S_QUARTER1);
        const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7190U) & S_QUARTER1);
        const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7332U) & S_QUARTER1);
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
        (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 16U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 0U);
        aFoldWord = TwistMix32::DiffuseA(aFoldWord);
        aWaterLaneB[aIndex] = aFoldWord;
    }
    const std::size_t aFoldBaseA = 3U * S_QUARTER;
    const std::size_t aFoldBaseB = 1U * S_QUARTER;
    const std::size_t aFoldBaseC = 3U * S_QUARTER;
    const std::size_t aFoldBaseD = 2U * S_QUARTER;
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
        const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7148U) & S_QUARTER1);
        const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 3049U) & S_QUARTER1);
        const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2557U) & S_QUARTER1);
        const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1609U) & S_QUARTER1);
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 16U) |
        (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 24U);
        aFoldWord = TwistMix32::DiffuseA(aFoldWord);
        aWaterLaneC[aIndex] = aFoldWord;
    }
    const std::size_t aFoldBaseA = 2U * S_QUARTER;
    const std::size_t aFoldBaseB = 3U * S_QUARTER;
    const std::size_t aFoldBaseC = 2U * S_QUARTER;
    const std::size_t aFoldBaseD = 0U * S_QUARTER;
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_QUARTER); aIndex += 1U) {
        const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 4023U) & S_QUARTER1);
        const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6964U) & S_QUARTER1);
        const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7875U) & S_QUARTER1);
        const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1082U) & S_QUARTER1);
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aSpiritLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aSpiritLaneB[aFoldIndexB]) << 24U) |
        (static_cast<std::uint32_t>(aSpiritLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aSpiritLaneD[aFoldIndexD]) << 16U);
        aFoldWord = TwistMix32::DiffuseC(aFoldWord);
        aWaterLaneD[aIndex] = aFoldWord;
    }
    const std::size_t aFoldBaseA = 0U * W_KEY;
    const std::size_t aFoldBaseB = 2U * W_KEY;
    const std::size_t aFoldBaseC = 2U * W_KEY;
    const std::size_t aFoldBaseD = 3U * W_KEY;
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
        const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 757U) & W_KEY1);
        const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1378U) & W_KEY1);
        const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1274U) & W_KEY1);
        const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 383U) & W_KEY1);
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 24U) |
        (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
        aFoldWord = TwistMix32::DiffuseA(aFoldWord);
        aPoisonLaneA[aIndex] = aFoldWord;
    }
    const std::size_t aFoldBaseA = 1U * W_KEY;
    const std::size_t aFoldBaseB = 3U * W_KEY;
    const std::size_t aFoldBaseC = 0U * W_KEY;
    const std::size_t aFoldBaseD = 1U * W_KEY;
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
        const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1568U) & W_KEY1);
        const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 884U) & W_KEY1);
        const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1857U) & W_KEY1);
        const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 429U) & W_KEY1);
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 16U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 8U) |
        (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
        aFoldWord = TwistMix32::DiffuseA(aFoldWord);
        aPoisonLaneB[aIndex] = aFoldWord;
    }
    const std::size_t aFoldBaseA = 3U * W_KEY;
    const std::size_t aFoldBaseB = 1U * W_KEY;
    const std::size_t aFoldBaseC = 3U * W_KEY;
    const std::size_t aFoldBaseD = 0U * W_KEY;
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
        const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 300U) & W_KEY1);
        const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1763U) & W_KEY1);
        const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1137U) & W_KEY1);
        const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 504U) & W_KEY1);
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
        (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 0U);
        aFoldWord = TwistMix32::DiffuseB(aFoldWord);
        aPoisonLaneC[aIndex] = aFoldWord;
    }
    const std::size_t aFoldBaseA = 2U * W_KEY;
    const std::size_t aFoldBaseB = 0U * W_KEY;
    const std::size_t aFoldBaseC = 1U * W_KEY;
    const std::size_t aFoldBaseD = 2U * W_KEY;
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
        const std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1868U) & W_KEY1);
        const std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1046U) & W_KEY1);
        const std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 448U) & W_KEY1);
        const std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 480U) & W_KEY1);
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aWaterLaneA[aFoldIndexA]) << 24U) | (static_cast<std::uint32_t>(aWaterLaneB[aFoldIndexB]) << 16U) |
        (static_cast<std::uint32_t>(aWaterLaneC[aFoldIndexC]) << 0U) | (static_cast<std::uint32_t>(aWaterLaneD[aFoldIndexD]) << 8U);
        aFoldWord = TwistMix32::DiffuseB(aFoldWord);
        aPoisonLaneD[aIndex] = aFoldWord;
    }
    for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
        const std::size_t aFoldIndexA = (aIndex + 667U) & W_KEY1;
        const std::size_t aFoldIndexB = (aIndex + 947U) & W_KEY1;
        const std::size_t aFoldIndexC = (aIndex + 250U) & W_KEY1;
        const std::size_t aFoldIndexD = (aIndex + 345U) & W_KEY1;
        std::uint32_t aFoldWord =
        (static_cast<std::uint32_t>(aPoisonLaneA[aFoldIndexA]) << 8U) | (static_cast<std::uint32_t>(aPoisonLaneB[aFoldIndexB]) << 0U) |
        (static_cast<std::uint32_t>(aPoisonLaneC[aFoldIndexC]) << 24U) | (static_cast<std::uint32_t>(aPoisonLaneD[aFoldIndexD]) << 16U);
        aFoldWord = TwistMix32::DiffuseC(aFoldWord);
        aKeyRowWriteB[aIndex] = aFoldWord;
    }
    
}
