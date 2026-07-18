void TwistExpander_Arcturus::SquashInvestToKeyBoxes() {
    
    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 13U), *aFragmentB = aInvestLaneB + (W_KEY * 0U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 2U), *aFragmentD = aInvestLaneD + (W_KEY * 8U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 12U), *aFragmentF = aInvestLaneF + (W_KEY * 1U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 11U), *aFragmentH = aInvestLaneH + (W_KEY * 13U);
        std::uint8_t *aKeyRow = &(mWorkspace->mKeyBoxA[0][0]);
        for (W_KEY) {
            std::uint64_t aSquash =
                ((uint64)(aFragmentA[((aIndex + 101U) & W_KEY1)]) << 40U) | ((uint64)(aFragmentB[((aIndex + 664U) & W_KEY1)]) << 16U) |
                ((uint64)(aFragmentC[((aIndex + 1098U) & W_KEY1)]) << 8U) | ((uint64)(aFragmentD[((aIndex + 1968U) & W_KEY1)]) << 24U) |
                ((uint64)(aFragmentE[((aIndex + 50U) & W_KEY1)]) << 32U) | ((uint64)(aFragmentF[((aIndex + 1902U) & W_KEY1)]) << 56U) |
                ((uint64)(aFragmentG[((aIndex + 639U) & W_KEY1)]) << 48U) | ((uint64)(aFragmentH[((aIndex + 1167U) & W_KEY1)]) << 0U);
            
            aKeyRow[aIndex] = (byte)(TwistMix64::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 1U), *aFragmentB = aInvestLaneB + (W_KEY * 14U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 10U), *aFragmentD = aInvestLaneD + (W_KEY * 10U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 9U), *aFragmentF = aInvestLaneF + (W_KEY * 15U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 15U), *aFragmentH = aInvestLaneH + (W_KEY * 14U);
        std::uint8_t *aKeyRow = &(mWorkspace->mKeyBoxA[1][0]);
        for (W_KEY) {
            std::uint64_t aSquash =
                ((uint64)(aFragmentA[((aIndex + 1456U) & W_KEY1)]) << 48U) | ((uint64)(aFragmentB[((aIndex + 684U) & W_KEY1)]) << 0U) |
                ((uint64)(aFragmentC[((aIndex + 1724U) & W_KEY1)]) << 56U) | ((uint64)(aFragmentD[((aIndex + 1841U) & W_KEY1)]) << 16U) |
                ((uint64)(aFragmentE[((aIndex + 1885U) & W_KEY1)]) << 40U) | ((uint64)(aFragmentF[((aIndex + 1815U) & W_KEY1)]) << 24U) |
                ((uint64)(aFragmentG[((aIndex + 1371U) & W_KEY1)]) << 8U) | ((uint64)(aFragmentH[((aIndex + 620U) & W_KEY1)]) << 32U);
            
            aKeyRow[aIndex] = (byte)(TwistMix64::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 10U), *aFragmentB = aInvestLaneB + (W_KEY * 9U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 15U), *aFragmentD = aInvestLaneD + (W_KEY * 12U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 13U), *aFragmentF = aInvestLaneF + (W_KEY * 4U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 9U), *aFragmentH = aInvestLaneH + (W_KEY * 4U);
        std::uint8_t *aKeyRow = &(mWorkspace->mKeyBoxA[2][0]);
        for (W_KEY) {
            std::uint64_t aSquash =
                ((uint64)(aFragmentA[((aIndex + 490U) & W_KEY1)]) << 0U) | ((uint64)(aFragmentB[((aIndex + 326U) & W_KEY1)]) << 32U) |
                ((uint64)(aFragmentC[((aIndex + 256U) & W_KEY1)]) << 56U) | ((uint64)(aFragmentD[((aIndex + 723U) & W_KEY1)]) << 8U) |
                ((uint64)(aFragmentE[((aIndex + 1444U) & W_KEY1)]) << 16U) | ((uint64)(aFragmentF[((aIndex + 891U) & W_KEY1)]) << 40U) |
                ((uint64)(aFragmentG[((aIndex + 1054U) & W_KEY1)]) << 48U) | ((uint64)(aFragmentH[((aIndex + 711U) & W_KEY1)]) << 24U);
            
            aKeyRow[aIndex] = (byte)(TwistMix64::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 4U), *aFragmentB = aInvestLaneB + (W_KEY * 6U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 9U), *aFragmentD = aInvestLaneD + (W_KEY * 14U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 10U), *aFragmentF = aInvestLaneF + (W_KEY * 0U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 2U), *aFragmentH = aInvestLaneH + (W_KEY * 15U);
        std::uint8_t *aKeyRow = &(mWorkspace->mKeyBoxA[3][0]);
        for (W_KEY) {
            std::uint64_t aSquash =
                ((uint64)(aFragmentA[((aIndex + 2019U) & W_KEY1)]) << 32U) | ((uint64)(aFragmentB[((aIndex + 1215U) & W_KEY1)]) << 16U) |
                ((uint64)(aFragmentC[((aIndex + 1786U) & W_KEY1)]) << 0U) | ((uint64)(aFragmentD[((aIndex + 258U) & W_KEY1)]) << 8U) |
                ((uint64)(aFragmentE[((aIndex + 1982U) & W_KEY1)]) << 56U) | ((uint64)(aFragmentF[((aIndex + 1850U) & W_KEY1)]) << 48U) |
                ((uint64)(aFragmentG[((aIndex + 930U) & W_KEY1)]) << 40U) | ((uint64)(aFragmentH[((aIndex + 488U) & W_KEY1)]) << 24U);
            
            aKeyRow[aIndex] = (byte)(TwistMix64::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 3U), *aFragmentB = aInvestLaneB + (W_KEY * 15U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 8U), *aFragmentD = aInvestLaneD + (W_KEY * 5U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 14U), *aFragmentF = aInvestLaneF + (W_KEY * 6U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 0U), *aFragmentH = aInvestLaneH + (W_KEY * 10U);
        std::uint8_t *aKeyRow = &(mWorkspace->mKeyBoxA[4][0]);
        for (W_KEY) {
            std::uint64_t aSquash =
                ((uint64)(aFragmentA[((aIndex + 1123U) & W_KEY1)]) << 32U) | ((uint64)(aFragmentB[((aIndex + 1243U) & W_KEY1)]) << 24U) |
                ((uint64)(aFragmentC[((aIndex + 34U) & W_KEY1)]) << 0U) | ((uint64)(aFragmentD[((aIndex + 1637U) & W_KEY1)]) << 16U) |
                ((uint64)(aFragmentE[((aIndex + 99U) & W_KEY1)]) << 56U) | ((uint64)(aFragmentF[((aIndex + 1577U) & W_KEY1)]) << 8U) |
                ((uint64)(aFragmentG[((aIndex + 2004U) & W_KEY1)]) << 40U) | ((uint64)(aFragmentH[((aIndex + 1479U) & W_KEY1)]) << 48U);
            
            aKeyRow[aIndex] = (byte)(TwistMix64::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 0U), *aFragmentB = aInvestLaneB + (W_KEY * 5U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 13U), *aFragmentD = aInvestLaneD + (W_KEY * 6U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 7U), *aFragmentF = aInvestLaneF + (W_KEY * 3U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 12U), *aFragmentH = aInvestLaneH + (W_KEY * 6U);
        std::uint8_t *aKeyRow = &(mWorkspace->mKeyBoxA[5][0]);
        for (W_KEY) {
            std::uint64_t aSquash =
                ((uint64)(aFragmentA[((aIndex + 51U) & W_KEY1)]) << 16U) | ((uint64)(aFragmentB[((aIndex + 1331U) & W_KEY1)]) << 32U) |
                ((uint64)(aFragmentC[((aIndex + 925U) & W_KEY1)]) << 0U) | ((uint64)(aFragmentD[((aIndex + 154U) & W_KEY1)]) << 8U) |
                ((uint64)(aFragmentE[((aIndex + 1917U) & W_KEY1)]) << 56U) | ((uint64)(aFragmentF[((aIndex + 333U) & W_KEY1)]) << 48U) |
                ((uint64)(aFragmentG[((aIndex + 748U) & W_KEY1)]) << 40U) | ((uint64)(aFragmentH[((aIndex + 1816U) & W_KEY1)]) << 24U);
            
            aKeyRow[aIndex] = (byte)(TwistMix64::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 6U), *aFragmentB = aInvestLaneB + (W_KEY * 12U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 6U), *aFragmentD = aInvestLaneD + (W_KEY * 15U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 5U), *aFragmentF = aInvestLaneF + (W_KEY * 8U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 10U), *aFragmentH = aInvestLaneH + (W_KEY * 2U);
        std::uint8_t *aKeyRow = &(mWorkspace->mKeyBoxA[6][0]);
        for (W_KEY) {
            std::uint64_t aSquash =
                ((uint64)(aFragmentA[((aIndex + 83U) & W_KEY1)]) << 40U) | ((uint64)(aFragmentB[((aIndex + 1734U) & W_KEY1)]) << 56U) |
                ((uint64)(aFragmentC[((aIndex + 1771U) & W_KEY1)]) << 48U) | ((uint64)(aFragmentD[((aIndex + 1117U) & W_KEY1)]) << 24U) |
                ((uint64)(aFragmentE[((aIndex + 1903U) & W_KEY1)]) << 16U) | ((uint64)(aFragmentF[((aIndex + 622U) & W_KEY1)]) << 8U) |
                ((uint64)(aFragmentG[((aIndex + 1038U) & W_KEY1)]) << 0U) | ((uint64)(aFragmentH[((aIndex + 743U) & W_KEY1)]) << 32U);
            
            aKeyRow[aIndex] = (byte)(TwistMix64::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 8U), *aFragmentB = aInvestLaneB + (W_KEY * 8U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 5U), *aFragmentD = aInvestLaneD + (W_KEY * 7U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 0U), *aFragmentF = aInvestLaneF + (W_KEY * 9U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 5U), *aFragmentH = aInvestLaneH + (W_KEY * 11U);
        std::uint8_t *aKeyRow = &(mWorkspace->mKeyBoxA[7][0]);
        for (W_KEY) {
            std::uint64_t aSquash =
                ((uint64)(aFragmentA[((aIndex + 1730U) & W_KEY1)]) << 48U) | ((uint64)(aFragmentB[((aIndex + 1177U) & W_KEY1)]) << 32U) |
                ((uint64)(aFragmentC[((aIndex + 1498U) & W_KEY1)]) << 40U) | ((uint64)(aFragmentD[((aIndex + 561U) & W_KEY1)]) << 56U) |
                ((uint64)(aFragmentE[((aIndex + 1708U) & W_KEY1)]) << 16U) | ((uint64)(aFragmentF[((aIndex + 1415U) & W_KEY1)]) << 0U) |
                ((uint64)(aFragmentG[((aIndex + 313U) & W_KEY1)]) << 24U) | ((uint64)(aFragmentH[((aIndex + 959U) & W_KEY1)]) << 8U);
            
            aKeyRow[aIndex] = (byte)(TwistMix64::DiffuseA(aSquash));
        }
    }
    
    // ======================================

    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 5U), *aFragmentB = aInvestLaneB + (W_KEY * 11U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 11U), *aFragmentD = aInvestLaneD + (W_KEY * 3U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 11U), *aFragmentF = aInvestLaneF + (W_KEY * 11U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 6U), *aFragmentH = aInvestLaneH + (W_KEY * 1U);
        std::uint8_t *aKeyRow = &(mWorkspace->mKeyBoxB[0][0]);
        for (W_KEY) {
            std::uint64_t aSquash =
                ((uint64)(aFragmentA[((aIndex + 648U) & W_KEY1)]) << 24U) | ((uint64)(aFragmentB[((aIndex + 90U) & W_KEY1)]) << 40U) |
                ((uint64)(aFragmentC[((aIndex + 1045U) & W_KEY1)]) << 56U) | ((uint64)(aFragmentD[((aIndex + 1195U) & W_KEY1)]) << 8U) |
                ((uint64)(aFragmentE[((aIndex + 1406U) & W_KEY1)]) << 0U) | ((uint64)(aFragmentF[((aIndex + 1199U) & W_KEY1)]) << 48U) |
                ((uint64)(aFragmentG[((aIndex + 973U) & W_KEY1)]) << 16U) | ((uint64)(aFragmentH[((aIndex + 918U) & W_KEY1)]) << 32U);
            
            aKeyRow[aIndex] = (byte)(TwistMix64::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 14U), *aFragmentB = aInvestLaneB + (W_KEY * 1U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 3U), *aFragmentD = aInvestLaneD + (W_KEY * 9U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 15U), *aFragmentF = aInvestLaneF + (W_KEY * 14U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 13U), *aFragmentH = aInvestLaneH + (W_KEY * 3U);
        std::uint8_t *aKeyRow = &(mWorkspace->mKeyBoxB[1][0]);
        for (W_KEY) {
            std::uint64_t aSquash =
                ((uint64)(aFragmentA[((aIndex + 1370U) & W_KEY1)]) << 40U) | ((uint64)(aFragmentB[((aIndex + 788U) & W_KEY1)]) << 8U) |
                ((uint64)(aFragmentC[((aIndex + 646U) & W_KEY1)]) << 24U) | ((uint64)(aFragmentD[((aIndex + 708U) & W_KEY1)]) << 0U) |
                ((uint64)(aFragmentE[((aIndex + 296U) & W_KEY1)]) << 16U) | ((uint64)(aFragmentF[((aIndex + 13U) & W_KEY1)]) << 32U) |
                ((uint64)(aFragmentG[((aIndex + 605U) & W_KEY1)]) << 48U) | ((uint64)(aFragmentH[((aIndex + 540U) & W_KEY1)]) << 56U);
            
            aKeyRow[aIndex] = (byte)(TwistMix64::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 11U), *aFragmentB = aInvestLaneB + (W_KEY * 4U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 14U), *aFragmentD = aInvestLaneD + (W_KEY * 1U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 8U), *aFragmentF = aInvestLaneF + (W_KEY * 5U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 7U), *aFragmentH = aInvestLaneH + (W_KEY * 8U);
        std::uint8_t *aKeyRow = &(mWorkspace->mKeyBoxB[2][0]);
        for (W_KEY) {
            std::uint64_t aSquash =
                ((uint64)(aFragmentA[((aIndex + 1466U) & W_KEY1)]) << 32U) | ((uint64)(aFragmentB[((aIndex + 1202U) & W_KEY1)]) << 56U) |
                ((uint64)(aFragmentC[((aIndex + 645U) & W_KEY1)]) << 24U) | ((uint64)(aFragmentD[((aIndex + 519U) & W_KEY1)]) << 0U) |
                ((uint64)(aFragmentE[((aIndex + 180U) & W_KEY1)]) << 40U) | ((uint64)(aFragmentF[((aIndex + 678U) & W_KEY1)]) << 16U) |
                ((uint64)(aFragmentG[((aIndex + 1289U) & W_KEY1)]) << 8U) | ((uint64)(aFragmentH[((aIndex + 1134U) & W_KEY1)]) << 48U);
            
            aKeyRow[aIndex] = (byte)(TwistMix64::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 9U), *aFragmentB = aInvestLaneB + (W_KEY * 2U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 12U), *aFragmentD = aInvestLaneD + (W_KEY * 13U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 1U), *aFragmentF = aInvestLaneF + (W_KEY * 7U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 1U), *aFragmentH = aInvestLaneH + (W_KEY * 5U);
        std::uint8_t *aKeyRow = &(mWorkspace->mKeyBoxB[3][0]);
        for (W_KEY) {
            std::uint64_t aSquash =
                ((uint64)(aFragmentA[((aIndex + 654U) & W_KEY1)]) << 0U) | ((uint64)(aFragmentB[((aIndex + 875U) & W_KEY1)]) << 8U) |
                ((uint64)(aFragmentC[((aIndex + 629U) & W_KEY1)]) << 56U) | ((uint64)(aFragmentD[((aIndex + 425U) & W_KEY1)]) << 16U) |
                ((uint64)(aFragmentE[((aIndex + 1735U) & W_KEY1)]) << 24U) | ((uint64)(aFragmentF[((aIndex + 148U) & W_KEY1)]) << 48U) |
                ((uint64)(aFragmentG[((aIndex + 737U) & W_KEY1)]) << 32U) | ((uint64)(aFragmentH[((aIndex + 2027U) & W_KEY1)]) << 40U);
            
            aKeyRow[aIndex] = (byte)(TwistMix64::DiffuseB(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 12U), *aFragmentB = aInvestLaneB + (W_KEY * 7U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 0U), *aFragmentD = aInvestLaneD + (W_KEY * 0U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 4U), *aFragmentF = aInvestLaneF + (W_KEY * 13U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 8U), *aFragmentH = aInvestLaneH + (W_KEY * 0U);
        std::uint8_t *aKeyRow = &(mWorkspace->mKeyBoxB[4][0]);
        for (W_KEY) {
            std::uint64_t aSquash =
                ((uint64)(aFragmentA[((aIndex + 1431U) & W_KEY1)]) << 48U) | ((uint64)(aFragmentB[((aIndex + 591U) & W_KEY1)]) << 0U) |
                ((uint64)(aFragmentC[((aIndex + 1409U) & W_KEY1)]) << 24U) | ((uint64)(aFragmentD[((aIndex + 1183U) & W_KEY1)]) << 40U) |
                ((uint64)(aFragmentE[((aIndex + 632U) & W_KEY1)]) << 8U) | ((uint64)(aFragmentF[((aIndex + 232U) & W_KEY1)]) << 16U) |
                ((uint64)(aFragmentG[((aIndex + 124U) & W_KEY1)]) << 32U) | ((uint64)(aFragmentH[((aIndex + 1471U) & W_KEY1)]) << 56U);
            
            aKeyRow[aIndex] = (byte)(TwistMix64::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 15U), *aFragmentB = aInvestLaneB + (W_KEY * 13U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 1U), *aFragmentD = aInvestLaneD + (W_KEY * 4U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 6U), *aFragmentF = aInvestLaneF + (W_KEY * 10U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 14U), *aFragmentH = aInvestLaneH + (W_KEY * 7U);
        std::uint8_t *aKeyRow = &(mWorkspace->mKeyBoxB[5][0]);
        for (W_KEY) {
            std::uint64_t aSquash =
                ((uint64)(aFragmentA[((aIndex + 160U) & W_KEY1)]) << 56U) | ((uint64)(aFragmentB[((aIndex + 963U) & W_KEY1)]) << 48U) |
                ((uint64)(aFragmentC[((aIndex + 1527U) & W_KEY1)]) << 0U) | ((uint64)(aFragmentD[((aIndex + 1950U) & W_KEY1)]) << 8U) |
                ((uint64)(aFragmentE[((aIndex + 282U) & W_KEY1)]) << 24U) | ((uint64)(aFragmentF[((aIndex + 1362U) & W_KEY1)]) << 16U) |
                ((uint64)(aFragmentG[((aIndex + 371U) & W_KEY1)]) << 32U) | ((uint64)(aFragmentH[((aIndex + 1428U) & W_KEY1)]) << 40U);
            
            aKeyRow[aIndex] = (byte)(TwistMix64::DiffuseA(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 7U), *aFragmentB = aInvestLaneB + (W_KEY * 10U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 4U), *aFragmentD = aInvestLaneD + (W_KEY * 11U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 2U), *aFragmentF = aInvestLaneF + (W_KEY * 2U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 4U), *aFragmentH = aInvestLaneH + (W_KEY * 9U);
        std::uint8_t *aKeyRow = &(mWorkspace->mKeyBoxB[6][0]);
        for (W_KEY) {
            std::uint64_t aSquash =
                ((uint64)(aFragmentA[((aIndex + 728U) & W_KEY1)]) << 48U) | ((uint64)(aFragmentB[((aIndex + 701U) & W_KEY1)]) << 56U) |
                ((uint64)(aFragmentC[((aIndex + 933U) & W_KEY1)]) << 24U) | ((uint64)(aFragmentD[((aIndex + 638U) & W_KEY1)]) << 8U) |
                ((uint64)(aFragmentE[((aIndex + 1610U) & W_KEY1)]) << 0U) | ((uint64)(aFragmentF[((aIndex + 150U) & W_KEY1)]) << 32U) |
                ((uint64)(aFragmentG[((aIndex + 1667U) & W_KEY1)]) << 40U) | ((uint64)(aFragmentH[((aIndex + 1440U) & W_KEY1)]) << 16U);
            
            aKeyRow[aIndex] = (byte)(TwistMix64::DiffuseC(aSquash));
        }
    }

    {
        std::uint8_t *aFragmentA = aInvestLaneA + (W_KEY * 2U), *aFragmentB = aInvestLaneB + (W_KEY * 3U);
        std::uint8_t *aFragmentC = aInvestLaneC + (W_KEY * 7U), *aFragmentD = aInvestLaneD + (W_KEY * 2U);
        std::uint8_t *aFragmentE = aInvestLaneE + (W_KEY * 3U), *aFragmentF = aInvestLaneF + (W_KEY * 12U);
        std::uint8_t *aFragmentG = aInvestLaneG + (W_KEY * 3U), *aFragmentH = aInvestLaneH + (W_KEY * 12U);
        std::uint8_t *aKeyRow = &(mWorkspace->mKeyBoxB[7][0]);
        for (W_KEY) {
            std::uint64_t aSquash =
                ((uint64)(aFragmentA[((aIndex + 1325U) & W_KEY1)]) << 8U) | ((uint64)(aFragmentB[((aIndex + 582U) & W_KEY1)]) << 56U) |
                ((uint64)(aFragmentC[((aIndex + 389U) & W_KEY1)]) << 48U) | ((uint64)(aFragmentD[((aIndex + 894U) & W_KEY1)]) << 32U) |
                ((uint64)(aFragmentE[((aIndex + 1548U) & W_KEY1)]) << 16U) | ((uint64)(aFragmentF[((aIndex + 1818U) & W_KEY1)]) << 40U) |
                ((uint64)(aFragmentG[((aIndex + 426U) & W_KEY1)]) << 24U) | ((uint64)(aFragmentH[((aIndex + 889U) & W_KEY1)]) << 0U);
            
            aKeyRow[aIndex] = (byte)(TwistMix64::DiffuseC(aSquash));
        }
    }
}


void TwistExpander_Arcturus::GrowKeyA(TwistWorkSpace *pWorkSpace) {
    
    TwistShiftBox::ShiftKeyBoxA(pWorkSpace);
    {
        std::size_t aFoldBaseA = 2U * S_QUARTER;
        std::size_t aFoldBaseB = 0U * S_QUARTER;
        std::size_t aFoldBaseC = 1U * S_QUARTER;
        std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (S_QUARTER) {
            std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2622U) & S_QUARTER1);
            std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 5147U) & S_QUARTER1);
            std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 770U) & S_QUARTER1);
            std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 3306U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                ((uint32)(aExpandLaneA[aFoldIndexA]) << 16U) | ((uint32)(aExpandLaneB[aFoldIndexB]) << 24U) |
                ((uint32)(aExpandLaneC[aFoldIndexC]) << 8U) | ((uint32)(aExpandLaneD[aFoldIndexD]) << 0U);
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        std::size_t aFoldBaseA = 0U * S_QUARTER;
        std::size_t aFoldBaseB = 2U * S_QUARTER;
        std::size_t aFoldBaseC = 2U * S_QUARTER;
        std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (S_QUARTER) {
            std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2483U) & S_QUARTER1);
            std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 8129U) & S_QUARTER1);
            std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 5086U) & S_QUARTER1);
            std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 5275U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                ((uint32)(aExpandLaneA[aFoldIndexA]) << 0U) | ((uint32)(aExpandLaneB[aFoldIndexB]) << 16U) |
                ((uint32)(aExpandLaneC[aFoldIndexC]) << 24U) | ((uint32)(aExpandLaneD[aFoldIndexD]) << 8U);
            
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneB[aIndex] = aFoldWord;
        }
    }
    {
        std::size_t aFoldBaseA = 3U * S_QUARTER;
        std::size_t aFoldBaseB = 1U * S_QUARTER;
        std::size_t aFoldBaseC = 3U * S_QUARTER;
        std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (S_QUARTER) {
            std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7210U) & S_QUARTER1);
            std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6553U) & S_QUARTER1);
            std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7064U) & S_QUARTER1);
            std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6392U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                ((uint32)(aExpandLaneA[aFoldIndexA]) << 0U) | ((uint32)(aExpandLaneB[aFoldIndexB]) << 24U) |
                ((uint32)(aExpandLaneC[aFoldIndexC]) << 16U) | ((uint32)(aExpandLaneD[aFoldIndexD]) << 8U);
            
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneC[aIndex] = aFoldWord;
        }
    }
    {
        std::size_t aFoldBaseA = 1U * S_QUARTER;
        std::size_t aFoldBaseB = 3U * S_QUARTER;
        std::size_t aFoldBaseC = 0U * S_QUARTER;
        std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (S_QUARTER) {
            std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2207U) & S_QUARTER1);
            std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 2630U) & S_QUARTER1);
            std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3429U) & S_QUARTER1);
            std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 985U) & S_QUARTER1);
            std::uint32_t aFoldWord =
                ((uint32)(aExpandLaneA[aFoldIndexA]) << 8U) | ((uint32)(aExpandLaneB[aFoldIndexB]) << 0U) |
                ((uint32)(aExpandLaneC[aFoldIndexC]) << 16U) | ((uint32)(aExpandLaneD[aFoldIndexD]) << 24U);
            
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aScrapLaneD[aIndex] = aFoldWord;
        }
    }
    
    // ======================================
    
    {
        std::size_t aFoldBaseA = 0U * W_KEY;
        std::size_t aFoldBaseB = 3U * W_KEY;
        std::size_t aFoldBaseC = 2U * W_KEY;
        std::size_t aFoldBaseD = 0U * W_KEY;
        for (W_KEY) {
            std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 999U) & W_KEY1);
            std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1561U) & W_KEY1);
            std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 250U) & W_KEY1);
            std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 90U) & W_KEY1);
            std::uint32_t aFoldWord =
                ((uint32)(aScrapLaneA[aFoldIndexA]) << 8U) | ((uint32)(aScrapLaneB[aFoldIndexB]) << 16U) |
                ((uint32)(aScrapLaneC[aFoldIndexC]) << 24U) | ((uint32)(aScrapLaneD[aFoldIndexD]) << 0U);
            
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        std::size_t aFoldBaseA = 3U * W_KEY;
        std::size_t aFoldBaseB = 1U * W_KEY;
        std::size_t aFoldBaseC = 0U * W_KEY;
        std::size_t aFoldBaseD = 2U * W_KEY;
        for (W_KEY) {
            std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 231U) & W_KEY1);
            std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1972U) & W_KEY1);
            std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 176U) & W_KEY1);
            std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1729U) & W_KEY1);
            std::uint32_t aFoldWord =
                ((uint32)(aScrapLaneA[aFoldIndexA]) << 0U) | ((uint32)(aScrapLaneB[aFoldIndexB]) << 8U) |
                ((uint32)(aScrapLaneC[aFoldIndexC]) << 16U) | ((uint32)(aScrapLaneD[aFoldIndexD]) << 24U);
            
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        std::size_t aFoldBaseA = 1U * W_KEY;
        std::size_t aFoldBaseB = 0U * W_KEY;
        std::size_t aFoldBaseC = 1U * W_KEY;
        std::size_t aFoldBaseD = 3U * W_KEY;
        for (W_KEY) {
            std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1991U) & W_KEY1);
            std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1640U) & W_KEY1);
            std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 403U) & W_KEY1);
            std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1216U) & W_KEY1);
            std::uint32_t aFoldWord =
                ((uint32)(aScrapLaneA[aFoldIndexA]) << 0U) | ((uint32)(aScrapLaneB[aFoldIndexB]) << 24U) |
                ((uint32)(aScrapLaneC[aFoldIndexC]) << 16U) | ((uint32)(aScrapLaneD[aFoldIndexD]) << 8U);
            
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        std::size_t aFoldBaseA = 2U * W_KEY;
        std::size_t aFoldBaseB = 2U * W_KEY;
        std::size_t aFoldBaseC = 3U * W_KEY;
        std::size_t aFoldBaseD = 1U * W_KEY;
        for (W_KEY) {
            std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1915U) & W_KEY1);
            std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1643U) & W_KEY1);
            std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 1577U) & W_KEY1);
            std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 743U) & W_KEY1);
            std::uint32_t aFoldWord =
                ((uint32)(aScrapLaneA[aFoldIndexA]) << 24U) | ((uint32)(aScrapLaneB[aFoldIndexB]) << 8U) |
                ((uint32)(aScrapLaneC[aFoldIndexC]) << 16U) | ((uint32)(aScrapLaneD[aFoldIndexD]) << 0U);
            
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (W_KEY) {
            std::size_t aFoldIndexA = (aIndex + 1100U) & W_KEY1;
            std::size_t aFoldIndexB = (aIndex + 842U) & W_KEY1;
            std::size_t aFoldIndexC = (aIndex + 787U) & W_KEY1;
            std::size_t aFoldIndexD = (aIndex + 1433U) & W_KEY1;
            std::uint32_t aFoldWord =
                ((uint32)(aMergeLaneA[aFoldIndexA]) << 0U) | ((uint32)(aMergeLaneB[aFoldIndexB]) << 24U) |
                ((uint32)(aMergeLaneC[aFoldIndexC]) << 8U) | ((uint32)(aMergeLaneD[aFoldIndexD]) << 16U);
            
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aKeyRowWriteA[aIndex] = aFoldWord;
        }
    }
}

// GrowB candidate 10 of 33
// Exploration cases: 50000000
// Total structural distance from earlier candidates: 4986; nearest pair: 516 / 674
void TwistExpander_Arcturus::GrowKeyB(TwistWorkSpace *pWorkSpace) {
    
    TwistShiftBox::ShiftKeyBoxB(pWorkSpace);
    {
        std::size_t aFoldBaseA = 3U * S_QUARTER;
        std::size_t aFoldBaseB = 1U * S_QUARTER;
        std::size_t aFoldBaseC = 0U * S_QUARTER;
        std::size_t aFoldBaseD = 2U * S_QUARTER;
        for (S_QUARTER) {
            std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7563U) & S_QUARTER1);
            std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 4797U) & S_QUARTER1);
            std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3039U) & S_QUARTER1);
            std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 7810U) & S_QUARTER1);
            std::uint32_t aFoldWord =
            ((uint32)(aWorkLaneA[aFoldIndexA]) << 16U) | ((uint32)(aWorkLaneB[aFoldIndexB]) << 24U) |
            ((uint32)(aWorkLaneC[aFoldIndexC]) << 0U) | ((uint32)(aWorkLaneD[aFoldIndexD]) << 8U);
            
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneA[aIndex] = aFoldWord;
        }
    }
    {
        std::size_t aFoldBaseA = 2U * S_QUARTER;
        std::size_t aFoldBaseB = 3U * S_QUARTER;
        std::size_t aFoldBaseC = 1U * S_QUARTER;
        std::size_t aFoldBaseD = 1U * S_QUARTER;
        for (S_QUARTER) {
            std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 7884U) & S_QUARTER1);
            std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 7029U) & S_QUARTER1);
            std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 7628U) & S_QUARTER1);
            std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6498U) & S_QUARTER1);
            std::uint32_t aFoldWord =
            ((uint32)(aWorkLaneA[aFoldIndexA]) << 8U) | ((uint32)(aWorkLaneB[aFoldIndexB]) << 0U) |
            ((uint32)(aWorkLaneC[aFoldIndexC]) << 24U) | ((uint32)(aWorkLaneD[aFoldIndexD]) << 16U);
            
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneB[aIndex] = aFoldWord;
        }
    }
    {
        std::size_t aFoldBaseA = 0U * S_QUARTER;
        std::size_t aFoldBaseB = 2U * S_QUARTER;
        std::size_t aFoldBaseC = 3U * S_QUARTER;
        std::size_t aFoldBaseD = 0U * S_QUARTER;
        for (S_QUARTER) {
            std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1815U) & S_QUARTER1);
            std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 6970U) & S_QUARTER1);
            std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 2874U) & S_QUARTER1);
            std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6407U) & S_QUARTER1);
            std::uint32_t aFoldWord =
            ((uint32)(aWorkLaneA[aFoldIndexA]) << 16U) | ((uint32)(aWorkLaneB[aFoldIndexB]) << 24U) |
            ((uint32)(aWorkLaneC[aFoldIndexC]) << 0U) | ((uint32)(aWorkLaneD[aFoldIndexD]) << 8U);
            
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aScrapLaneC[aIndex] = aFoldWord;
        }
    }
    {
        std::size_t aFoldBaseA = 1U * S_QUARTER;
        std::size_t aFoldBaseB = 0U * S_QUARTER;
        std::size_t aFoldBaseC = 2U * S_QUARTER;
        std::size_t aFoldBaseD = 3U * S_QUARTER;
        for (S_QUARTER) {
            std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 2321U) & S_QUARTER1);
            std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1195U) & S_QUARTER1);
            std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 3578U) & S_QUARTER1);
            std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 6044U) & S_QUARTER1);
            std::uint32_t aFoldWord =
            ((uint32)(aWorkLaneA[aFoldIndexA]) << 16U) | ((uint32)(aWorkLaneB[aFoldIndexB]) << 24U) |
            ((uint32)(aWorkLaneC[aFoldIndexC]) << 0U) | ((uint32)(aWorkLaneD[aFoldIndexD]) << 8U);
            
            aFoldWord = TwistMix32::DiffuseC(aFoldWord);
            aScrapLaneD[aIndex] = aFoldWord;
        }
    }
    
    // ======================================
    
    {
        std::size_t aFoldBaseA = 3U * W_KEY;
        std::size_t aFoldBaseB = 3U * W_KEY;
        std::size_t aFoldBaseC = 0U * W_KEY;
        std::size_t aFoldBaseD = 1U * W_KEY;
        for (W_KEY) {
            std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 218U) & W_KEY1);
            std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1020U) & W_KEY1);
            std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 830U) & W_KEY1);
            std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 467U) & W_KEY1);
            std::uint32_t aFoldWord =
            ((uint32)(aScrapLaneA[aFoldIndexA]) << 24U) | ((uint32)(aScrapLaneB[aFoldIndexB]) << 8U) |
            ((uint32)(aScrapLaneC[aFoldIndexC]) << 0U) | ((uint32)(aScrapLaneD[aFoldIndexD]) << 16U);
            
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneA[aIndex] = aFoldWord;
        }
    }
    {
        std::size_t aFoldBaseA = 2U * W_KEY;
        std::size_t aFoldBaseB = 2U * W_KEY;
        std::size_t aFoldBaseC = 1U * W_KEY;
        std::size_t aFoldBaseD = 0U * W_KEY;
        for (W_KEY) {
            std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1048U) & W_KEY1);
            std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 27U) & W_KEY1);
            std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 472U) & W_KEY1);
            std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 795U) & W_KEY1);
            std::uint32_t aFoldWord =
            ((uint32)(aScrapLaneA[aFoldIndexA]) << 24U) | ((uint32)(aScrapLaneB[aFoldIndexB]) << 16U) |
            ((uint32)(aScrapLaneC[aFoldIndexC]) << 8U) | ((uint32)(aScrapLaneD[aFoldIndexD]) << 0U);
            
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneB[aIndex] = aFoldWord;
        }
    }
    {
        std::size_t aFoldBaseA = 0U * W_KEY;
        std::size_t aFoldBaseB = 1U * W_KEY;
        std::size_t aFoldBaseC = 2U * W_KEY;
        std::size_t aFoldBaseD = 2U * W_KEY;
        for (W_KEY) {
            std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 1240U) & W_KEY1);
            std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1214U) & W_KEY1);
            std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 915U) & W_KEY1);
            std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1627U) & W_KEY1);
            std::uint32_t aFoldWord =
            ((uint32)(aScrapLaneA[aFoldIndexA]) << 16U) | ((uint32)(aScrapLaneB[aFoldIndexB]) << 24U) |
            ((uint32)(aScrapLaneC[aFoldIndexC]) << 8U) | ((uint32)(aScrapLaneD[aFoldIndexD]) << 0U);
            
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aMergeLaneC[aIndex] = aFoldWord;
        }
    }
    {
        std::size_t aFoldBaseA = 1U * W_KEY;
        std::size_t aFoldBaseB = 0U * W_KEY;
        std::size_t aFoldBaseC = 3U * W_KEY;
        std::size_t aFoldBaseD = 3U * W_KEY;
        for (W_KEY) {
            std::size_t aFoldIndexA = aFoldBaseA + ((aIndex + 583U) & W_KEY1);
            std::size_t aFoldIndexB = aFoldBaseB + ((aIndex + 1490U) & W_KEY1);
            std::size_t aFoldIndexC = aFoldBaseC + ((aIndex + 82U) & W_KEY1);
            std::size_t aFoldIndexD = aFoldBaseD + ((aIndex + 1411U) & W_KEY1);
            std::uint32_t aFoldWord =
            ((uint32)(aScrapLaneA[aFoldIndexA]) << 0U) | ((uint32)(aScrapLaneB[aFoldIndexB]) << 16U) |
            ((uint32)(aScrapLaneC[aFoldIndexC]) << 24U) | ((uint32)(aScrapLaneD[aFoldIndexD]) << 8U);
            
            aFoldWord = TwistMix32::DiffuseA(aFoldWord);
            aMergeLaneD[aIndex] = aFoldWord;
        }
    }
    {
        for (W_KEY) {
            std::size_t aFoldIndexA = (aIndex + 459U) & W_KEY1;
            std::size_t aFoldIndexB = (aIndex + 29U) & W_KEY1;
            std::size_t aFoldIndexC = (aIndex + 170U) & W_KEY1;
            std::size_t aFoldIndexD = (aIndex + 1040U) & W_KEY1;
            std::uint32_t aFoldWord =
            ((uint32)(aMergeLaneA[aFoldIndexA]) << 24U) | ((uint32)(aMergeLaneB[aFoldIndexB]) << 0U) |
            ((uint32)(aMergeLaneC[aFoldIndexC]) << 16U) | ((uint32)(aMergeLaneD[aFoldIndexD]) << 8U);
            
            aFoldWord = TwistMix32::DiffuseB(aFoldWord);
            aKeyRowWriteB[aIndex] = aFoldWord;
        }
    }
}
