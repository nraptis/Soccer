
void TwistExpander_Aldebaran_Arx::TWIST_A(TwistWorkSpace *pWorkSpace,
                     std::uint8_t *pSource,
                     std::uint8_t *pCrossLaneA,
                     std::uint8_t *pCrossLaneB,
                     std::uint8_t *pCrossLaneC,
                     std::uint8_t *pCrossLaneD,
                     MUTABLE_PARAMS) {
    std::uint8_t *aAetherLaneA = pWorkSpace->mAetherLaneA;
    std::uint8_t *aAetherLaneB = pWorkSpace->mAetherLaneB;
    std::uint8_t *aAetherLaneC = pWorkSpace->mAetherLaneC;
    std::uint8_t *aAetherLaneD = pWorkSpace->mAetherLaneD;
    std::uint8_t *aKeyRowReadA = &(pWorkSpace->mKeyBoxA[H_KEY - 1][0]);
    std::uint8_t *aKeyRowReadB = &(pWorkSpace->mKeyBoxB[H_KEY - 1][0]);
    std::uint64_t *aOASaltA = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltA;
    std::uint64_t *aOASaltB = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltB;
    std::uint64_t *aOASaltC = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltC;
    std::uint64_t *aOASaltD = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltD;
    std::uint64_t *aOASaltE = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltE;
    std::uint64_t *aOASaltG = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltG;
    std::uint64_t *aOASaltH = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltH;
    std::uint64_t *aOUSaltA = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltA;
    std::uint64_t *aOUSaltB = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltB;
    std::uint64_t *aOUSaltC = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltC;
    std::uint64_t *aOUSaltD = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltD;
    std::uint64_t *aOUSaltE = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltE;
    std::uint64_t *aOUSaltF = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltF;
    std::uint64_t *aOUSaltG = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltG;
    std::uint64_t *aOUSaltH = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltH;
    std::uint64_t *aWUSaltA = pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltA;
    std::uint64_t *aWUSaltB = pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltB;
    std::uint64_t *aWUSaltC = pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltC;
    std::uint64_t *aWUSaltD = pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltD;
    std::uint64_t *aWUSaltE = pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltE;
    std::uint64_t *aWUSaltF = pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltF;
    std::uint64_t *aWUSaltG = pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltG;
    std::uint64_t *aWUSaltH = pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltH;
    const std::uint64_t &aTwistDomainWordIngress = pWorkSpace->mDomainBundle.mTwistConstants.mIngress;
    const std::uint64_t &aTwistDomainWordScatter = pWorkSpace->mDomainBundle.mTwistConstants.mScatter;
    const std::uint64_t &aTwistDomainWordCross = pWorkSpace->mDomainBundle.mTwistConstants.mCross;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [twist arx]
    std::uint8_t *aSource = pSource;
    READ_IN_MUTABLE_PARAMS;
    // GTwistRunTwist_A twist_loop_a (start)
    {
        //
        // File: nexus_03/loop_000346.bin
        //
        // Head:        [4, 5, 9, 1, 2, 3, 6, 0, 10, 7, 8]
        // Tail A:      [1, 6, 7, 3, 0, 4, 2, 5, 8, 9, 10]
        // Tail B:      [2, 1, 5, 7, 10, 8, 9, 0, 3, 4, 6]
        //
        // Heart:       [{ 0, 1, 2 },
        //               { 3, 4, 5 },
        //               { 6, 2, 7 },
        //               { 8, 9, 1 },
        //               { 10, 5, 4 },
        //               { 7, 8, 0 },
        //               { 2, 10, 3 },
        //               { 4, 0, 6 },
        //               { 1, 3, 9 },
        //               { 5, 6, 8 },
        //               { 9, 7, 10 }]
        //
        // Orbiters:    [IKEAHCFDJBG]
        // Wanderers:   [FEBJDICHKGA]
        //
        // Ingress:     aSource (-->), aKeyRowReadA (-->)
        //
        // Cross:       aKeyRowReadB (<--), pCrossLaneA (<-?->)
        //
        // Destination: aAetherLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aSource[((aIndex + 490U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadA[((aIndex + 3747U)) & W_KEY1], 28U);
            aIngress = TwistMix64::DiffuseC((aIngress ^ aTwistDomainWordIngress));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 1843U)) & W_KEY1], 60U) ^ RotL64(pCrossLaneA[((S_BLOCK1 - aIndex + 7222U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB((aCross ^ aTwistDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 19U)) + (RotL64(aCross, 51U) ^ RotL64(aIngress, 36U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aTwistDomainWordScatter));
            //
            aOrbiterI = (aWandererD + RotL64(aIngress, 53U)) + 0xD3FB15AAD09D4B0CULL;
            aOrbiterK = (aWandererI + RotL64(aScatter, 43U)) + 0x2FAEEE9ACC23C67AULL;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 11U)) + 0xBA9DBF0BAA892B75ULL) + aOASaltB[(((511U - aIndex) + 279U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aCross, 37U)) + RotL64(aCarry, 57U)) + 0x3DE2E52226E0AC20ULL;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 46U)) + 0xCB4FD8669FA3E22CULL) + aOASaltA[(((511U - aIndex) + 305U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 3U)) + 0xFE79B91AA3B71856ULL) + aOASaltD[((aIndex + 422U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aPrevious, 51U)) + 0x276A93933784166EULL;
            aOrbiterD = (((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 23U)) + 0x568C4FB72033F208ULL) + aOASaltE[(((511U - aIndex) + 482U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aIngress, 27U)) + 0x154E8B24F96313E3ULL;
            aOrbiterB = (aWandererH + RotL64(aScatter, 60U)) + 0xBDE0944F288DAB98ULL;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 21U)) + RotL64(aCarry, 41U)) + 0x21E38DDB60365AD4ULL;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 0xE024381048B52FC8ULL;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 0x9B52851A8E44654FULL;
            aOrbiterE = RotL64((aOrbiterE * 0x70AA76CFCFA3A43BULL), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 0xB4D9D40526BD6EBEULL) + aOUSaltD[((aIndex + 427U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 0x53CAE8811B77B4D2ULL;
            aOrbiterC = RotL64((aOrbiterC * 0xCF359D7320E12425ULL), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 0xD0ADFDD5C556E525ULL) + aOUSaltG[(((511U - aIndex) + 293U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 0xEDBB66CB9CDE9C42ULL;
            aOrbiterD = RotL64((aOrbiterD * 0xEFD5A12594F8C2E1ULL), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 0x4BBECEB32A6DEEC2ULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 0x6B3CB2FDC983F86BULL;
            aOrbiterK = RotL64((aOrbiterK * 0x490D3773C3229BADULL), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 0xC95D4165E1695A13ULL;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 0x8CC9880AAD8D8659ULL;
            aOrbiterH = RotL64((aOrbiterH * 0xC1F6B2177C3CD87DULL), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 0x0795F0E5D80CDA86ULL) + aOUSaltH[((aIndex + 196U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 0xB33BBC887032F082ULL;
            aOrbiterI = RotL64((aOrbiterI * 0x32BE0F4BE1E2CF07ULL), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 0x6EA30259D2FAF043ULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 0x128FA3DEFABCD83CULL;
            aOrbiterA = RotL64((aOrbiterA * 0xD545F59373423EDDULL), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 0x78A6A280A03E43B1ULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 0xC9891DF5681F393AULL;
            aOrbiterF = RotL64((aOrbiterF * 0xD33E3876CFB3560BULL), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 0xA3B9C8E555EF358FULL;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 0x356E8DA2C159D045ULL;
            aOrbiterB = RotL64((aOrbiterB * 0x162844772F63ECD7ULL), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 0xBE8C5FB016759AD2ULL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 0x9D0263B25D587A9FULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0x2626FD728373035FULL), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 0x6B0861C8D4C84AC4ULL;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 0x8B15CE258AE3E0D5ULL) ^ aOUSaltC[(((511U - aIndex) + 139U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 0xE58D29EAC8E62255ULL), 43U);
            //
            aIngress = RotL64(aOrbiterG, 37U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 46U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterE, 37U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterK, 41U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterD, 23U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterA, 39U)) + aOrbiterD) + aWUSaltC[(((511U - aIndex) + 80U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 46U)) + aOrbiterG) + aWUSaltG[((aIndex + 67U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterJ, 29U)) + aWUSaltB[(((511U - aIndex) + 37U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 27U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aCross, 48U) + aOrbiterC) + RotL64(aOrbiterI, 43U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 27U)) + aWUSaltE[(((511U - aIndex) + 215U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterH, 5U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 18U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererA, 58U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (RotL64(aWandererI, 40U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aAetherLaneA[aIndex] = aIngress;
        }
    
        //
        // File: nexus_13/loop_000610.bin
        //
        // Head:        [9, 7, 1, 2, 10, 4, 6, 5, 8, 3, 0]
        // Tail A:      [8, 10, 9, 6, 1, 4, 5, 2, 0, 7, 3]
        // Tail B:      [0, 4, 6, 10, 7, 9, 2, 8, 3, 5, 1]
        //
        // Heart:       [{ 0, 1, 2 },
        //               { 3, 4, 5 },
        //               { 6, 2, 7 },
        //               { 8, 9, 4 },
        //               { 10, 7, 1 },
        //               { 9, 5, 0 },
        //               { 2, 10, 3 },
        //               { 4, 0, 6 },
        //               { 7, 3, 8 },
        //               { 1, 6, 9 },
        //               { 5, 8, 10 }]
        //
        // Orbiters:    [GBFHKEACIJD]
        // Wanderers:   [HADFBIGEKCJ]
        //
        // Ingress:     aAetherLaneA (-->), aSource (-->), aKeyRowReadB (-->)
        //
        // Cross:       aKeyRowReadA (<--), pCrossLaneB (<-?->)
        //
        // Destination: aAetherLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aAetherLaneA[((aIndex + 15256U)) & S_BLOCK1], 41U) ^ RotL64(aSource[((aIndex + 9401U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aKeyRowReadB[((aIndex + 12627U)) & W_KEY1], 29U);
            aIngress = TwistMix64::DiffuseC((aIngress ^ aTwistDomainWordIngress));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 10745U)) & W_KEY1], 47U) ^ RotL64(pCrossLaneB[((S_BLOCK1 - aIndex + 10076U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseC((aCross ^ aTwistDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 4U)) + (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aTwistDomainWordScatter));
            //
            aOrbiterG = ((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 51U)) + 0xCED9DEC9EF690B6DULL;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 10U)) + 0x3B305E13EEB1355DULL;
            aOrbiterF = (aWandererA + RotL64(aCross, 29U)) + 0xE52A8DBCAFD43834ULL;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 19U)) + 0xB142EDCB45ED4652ULL) + aOASaltG[((aIndex + 89U)) & S_SALT1];
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 23U)) + RotL64(aCarry, 47U)) + 0x3E4AD66AF7F34316ULL) + aOASaltH[((aIndex + 333U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aPrevious, 53U)) + 0x3259AE6E958B6962ULL;
            aOrbiterA = (aWandererG + RotL64(aCross, 35U)) + 0xAF5BDA7341061BEEULL;
            aOrbiterC = (aWandererI + RotL64(aIngress, 13U)) + 0xDD2B87F47E975815ULL;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 21U)) + RotL64(aCarry, 21U)) + 0xCDABD2529809B042ULL;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 43U)) + 0x4DB7B471B84CFB92ULL;
            aOrbiterD = ((aWandererH + RotL64(aCross, 6U)) + 0xA75DF66C39ADE97AULL) + aOASaltC[(((511U - aIndex) + 401U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 0x82C0C45F36488604ULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 0x03709557D4C36CA2ULL;
            aOrbiterF = RotL64((aOrbiterF * 0x839684620898E26DULL), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 0x81A9A972A4B02782ULL) + aOUSaltE[((aIndex + 283U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 0x67B6EFDA53337CBAULL) ^ aOUSaltD[(((511U - aIndex) + 250U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 0xBF88A8650CED1A33ULL), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 0xF421C5B8F708DBCAULL) + aOUSaltH[((aIndex + 145U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 0x2F6B8E733E705544ULL) ^ aOUSaltC[(((511U - aIndex) + 386U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 0x6E28AFC7A682D40DULL), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 0x12AE55EE72E3137FULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 0x6B8F95DCEFD63EBEULL;
            aOrbiterK = RotL64((aOrbiterK * 0xB7BC167A23FADA6DULL), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 0x55F3F1426FD23A85ULL;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 0x7CAC98FB8715C476ULL) ^ aOUSaltB[((aIndex + 78U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 0x2FA684468D4ECA05ULL), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 0x284A02EB3B42CB14ULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 0x8ACEFC9273DC3AC8ULL;
            aOrbiterG = RotL64((aOrbiterG * 0x38AEA296812F6C1FULL), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 0x9C85BBC5EC4D9CBFULL) + aOUSaltG[((aIndex + 322U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 0xCEE64DF8F0374699ULL;
            aOrbiterH = RotL64((aOrbiterH * 0x7BEEAB103A48D02BULL), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 0xD9885B275D2C96A8ULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 0x1F3F0B689D117916ULL;
            aOrbiterA = RotL64((aOrbiterA * 0xE379A896CB693065ULL), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 0x268124CDB07CA23DULL;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 0x87567936713B4A86ULL;
            aOrbiterI = RotL64((aOrbiterI * 0x9AD5BD9695A04105ULL), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 0x24EE1EE1DAA4A0AFULL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 0xF529AB2674EFB422ULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0x53E40AB0CDA2395BULL), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 0xD255CA965A11CA10ULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 0xD4309C58BF0D3DAFULL;
            aOrbiterD = RotL64((aOrbiterD * 0x0B254DF85C98FB23ULL), 39U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 19U);
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 10U));
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 6U) + RotL64(aOrbiterI, 5U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererA = aWandererA + ((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterK, 56U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 53U)) + aOrbiterA) + aWUSaltD[(((511U - aIndex) + 357U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 51U) + RotL64(aOrbiterA, 39U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 11U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 51U)) + aOrbiterF) + aWUSaltF[((aIndex + 156U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 48U) + aOrbiterF) + RotL64(aOrbiterI, 13U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 21U)) + aOrbiterH);
            aWandererC = aWandererC + ((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterE, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 60U)) + aOrbiterB) + aWUSaltA[(((511U - aIndex) + 363U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 36U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aAetherLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // File: nexus_08/loop_000386.bin
        //
        // Head:        [2, 4, 0, 7, 10, 6, 1, 8, 5, 9, 3]
        // Tail A:      [5, 10, 3, 6, 8, 2, 4, 7, 1, 0, 9]
        // Tail B:      [0, 4, 6, 5, 3, 9, 8, 2, 10, 7, 1]
        //
        // Heart:       [{ 0, 1, 2 },
        //               { 3, 4, 5 },
        //               { 6, 7, 8 },
        //               { 5, 2, 9 },
        //               { 10, 8, 0 },
        //               { 1, 3, 4 },
        //               { 9, 0, 6 },
        //               { 4, 5, 7 },
        //               { 2, 6, 10 },
        //               { 8, 9, 1 },
        //               { 7, 10, 3 }]
        //
        // Orbiters:    [FKGAIBEHDCJ]
        // Wanderers:   [KDCJHGAIFEB]
        //
        // Ingress:     aAetherLaneB (-->), aKeyRowReadA (-->), pCrossLaneC (<-?->)
        //
        // Cross:       aAetherLaneA (<--), aSource (<--), aKeyRowReadB (<--)
        //
        // Destination: aAetherLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aAetherLaneB[((aIndex + 16548U)) & S_BLOCK1], 52U) ^ RotL64(aKeyRowReadA[((aIndex + 22677U)) & W_KEY1], 41U));
            aIngress ^= RotL64(pCrossLaneC[((aIndex + 16680U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB((aIngress ^ aTwistDomainWordIngress));
            //
            aCross = (RotL64(aAetherLaneA[((S_BLOCK1 - aIndex + 18094U)) & S_BLOCK1], 20U) ^ RotL64(aSource[((S_BLOCK1 - aIndex + 23423U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aKeyRowReadB[(((2047U - aIndex) + 21975U)) & W_KEY1], 39U);
            aCross = TwistMix64::DiffuseB((aCross ^ aTwistDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 40U)) ^ (RotL64(aPrevious, 53U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aTwistDomainWordScatter));
            //
            aOrbiterF = (aWandererC + RotL64(aPrevious, 36U)) + 0x3AFE8D6A81C33D3DULL;
            aOrbiterK = ((aWandererH + RotL64(aCross, 21U)) + RotL64(aCarry, 51U)) + 0xD322C77B349E0658ULL;
            aOrbiterG = (aWandererK + RotL64(aIngress, 27U)) + 0xEE048FC73A8A067BULL;
            aOrbiterA = (aWandererI + RotL64(aScatter, 57U)) + 0x773B7C550EC4C2E2ULL;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 34U)) + 0xC27D45E64F2F8104ULL) + aOASaltB[(((511U - aIndex) + 237U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 3U)) + 0xFA651E1E6388AFA4ULL;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 51U)) + 0x0BD627F2C9EAD159ULL) + aOASaltA[((aIndex + 75U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aScatter, 19U)) + 0xD46EF0E52321F034ULL;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 47U)) + 0xF150B9A48B2EC884ULL) + aOASaltC[(((511U - aIndex) + 408U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 13U)) + 0x3ED247E3090B1BB1ULL;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 43U)) + 0xF1172E17E514B951ULL;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 0x4528E7AC0CDCDD87ULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 0x3A8ECD68F90C37F3ULL;
            aOrbiterG = RotL64((aOrbiterG * 0x370C3D59CFE891F7ULL), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 0x33B5E582F289C43EULL) + aOUSaltD[((aIndex + 496U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 0x951B8C14ED761F8CULL;
            aOrbiterB = RotL64((aOrbiterB * 0x113644509B417AB1ULL), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 0x8925BA9CEC46DDC0ULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 0x3D2751BF1B7A2526ULL;
            aOrbiterD = RotL64((aOrbiterD * 0xA1843D479F7708F7ULL), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 0x2D2F3191909E28D2ULL;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 0x6341D1716216730EULL) ^ aOUSaltC[((aIndex + 130U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 0xF507BB034B3E3CB5ULL), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 0xD65710FBC755BC83ULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 0x12677A16D4289B3EULL;
            aOrbiterF = RotL64((aOrbiterF * 0x264370C578A20E85ULL), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 0x35AF7711D4D5BF83ULL;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 0xBC9B5F5C10E75DD7ULL;
            aOrbiterI = RotL64((aOrbiterI * 0x4542A5F625841203ULL), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 0xD9C645362E2EE4A8ULL;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 0x75510E993F016C65ULL) ^ aOUSaltG[(((511U - aIndex) + 163U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 0x3EA701E7E59E8427ULL), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 0xD185CAD358A7042DULL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 0x5D5BDAF79A0A770FULL) ^ aOUSaltF[((aIndex + 292U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 0xF8467E376A08AB3BULL), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 0xB0B86A8B8B458D2DULL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 0x9926D763B9768B6CULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0xF9E3C679CC375A99ULL), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 0x4459159D4C810F99ULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 0x74F850C367010970ULL;
            aOrbiterK = RotL64((aOrbiterK * 0x6B9A44B839B3C713ULL), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 0x783F7E70D72A14DEULL;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 0x9338F7636CEEFE33ULL) ^ aOUSaltA[((aIndex + 343U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 0xA6618E265E5356BDULL), 51U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 41U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 60U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterF, 19U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 5U)) + aOrbiterI);
            aWandererC = aWandererC + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 41U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 27U) + RotL64(aOrbiterE, 30U)) + aOrbiterB) + RotL64(aCarry, 57U)) + aWUSaltH[((aIndex + 359U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 22U) + RotL64(aOrbiterD, 39U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterC, 43U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 35U)) + aOrbiterD) + aWUSaltB[(((511U - aIndex) + 290U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterG, 23U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterJ, 58U)) + RotL64(aCarry, 41U)) + aWUSaltE[((aIndex + 173U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 21U)) + aOrbiterH) + aWUSaltG[(((511U - aIndex) + 447U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 54U) + RotL64(aOrbiterC, 47U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 4U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aAetherLaneC[aIndex] = aIngress;
        }
    
        //
        // File: nexus_07/loop_000637.bin
        //
        // Head:        [7, 2, 4, 3, 10, 6, 8, 5, 0, 9, 1]
        // Tail A:      [3, 8, 10, 7, 6, 4, 9, 2, 0, 5, 1]
        // Tail B:      [10, 5, 6, 2, 1, 8, 7, 4, 3, 0, 9]
        //
        // Heart:       [{ 0, 1, 2 },
        //               { 3, 4, 5 },
        //               { 6, 7, 8 },
        //               { 5, 2, 9 },
        //               { 10, 8, 0 },
        //               { 1, 3, 4 },
        //               { 9, 0, 6 },
        //               { 7, 5, 3 },
        //               { 2, 6, 10 },
        //               { 8, 9, 1 },
        //               { 4, 10, 7 }]
        //
        // Orbiters:    [FKDCGIEAJHB]
        // Wanderers:   [KADFJBCIEHG]
        //
        // Ingress:     aAetherLaneC (-->), aAetherLaneA (-->), aKeyRowReadB (-->), pCrossLaneD (<-?->)
        //
        // Cross:       aAetherLaneB (<--), aSource (<--), aKeyRowReadA (<--)
        //
        // Destination: aAetherLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aAetherLaneC[((aIndex + 27215U)) & S_BLOCK1], 35U) ^ RotL64(aAetherLaneA[((aIndex + 28269U)) & S_BLOCK1], 24U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 24994U)) & W_KEY1], 5U) ^ RotL64(pCrossLaneD[((aIndex + 31912U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aTwistDomainWordIngress));
            //
            aCross = (RotL64(aAetherLaneB[((S_BLOCK1 - aIndex + 32443U)) & S_BLOCK1], 26U) ^ RotL64(aSource[((S_BLOCK1 - aIndex + 30590U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aKeyRowReadA[(((2047U - aIndex) + 27627U)) & W_KEY1], 47U);
            aCross = TwistMix64::DiffuseA((aCross ^ aTwistDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 52U) + RotL64(aCarry, 23U)) + (RotL64(aIngress, 3U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aTwistDomainWordScatter));
            //
            aOrbiterF = ((aWandererI + RotL64(aCross, 41U)) + 0xA5036CBC40E51CC3ULL) + aOASaltH[(((511U - aIndex) + 168U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aIngress, 23U)) + 0xDE42B34773705FD2ULL) + aOASaltA[(((511U - aIndex) + 356U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 58U)) + RotL64(aCarry, 13U)) + 0x6CDD5CD0E6D33875ULL;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 29U)) + 0x548A1BC5CBE6CE14ULL;
            aOrbiterG = (aWandererG + RotL64(aCross, 3U)) + 0x6E4611A129C3C2BBULL;
            aOrbiterI = (aWandererC + RotL64(aIngress, 27U)) + 0x7E4961161C2243EEULL;
            aOrbiterE = (((aWandererE + RotL64(aScatter, 18U)) + RotL64(aCarry, 29U)) + 0xC650EB7DC3F8322AULL) + aOASaltD[(((511U - aIndex) + 468U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aPrevious, 47U)) + 0x46658DADFA81FB60ULL;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 21U)) + 0xBDC28FA7497127DAULL) + aOASaltG[((aIndex + 301U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aIngress, 11U)) + 0x7F03F7583FB23E51ULL) + aOASaltC[(((511U - aIndex) + 1U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aScatter, 51U)) + RotL64(aCarry, 51U)) + 0xF9DBC32D0228C23AULL;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 0x932D01408A1EDEF8ULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 0xC3680EE448E4B257ULL;
            aOrbiterD = RotL64((aOrbiterD * 0x3D48B57D12E25D03ULL), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 0xA9FDE33C77A480ADULL;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 0xBC7DE7E103EE3CCAULL;
            aOrbiterI = RotL64((aOrbiterI * 0x3042A20A2A294A2FULL), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 0x7EB97A6D627173E2ULL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 0xECB7E63589C535E6ULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0x4C6B1C23D7B1C953ULL), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 0xC204AF2D1B35821AULL) + aOUSaltC[((aIndex + 454U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 0x5CE510D45CF0A857ULL;
            aOrbiterH = RotL64((aOrbiterH * 0xC4828942A8B6F55DULL), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 0xDE7A9B4E449CE558ULL;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 0xE7B131555DBE3A92ULL) ^ aOUSaltA[((aIndex + 171U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 0xD444AC610C99A485ULL), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 0x9DBFB312380B9717ULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 0xD8FA6B7EF045C1F9ULL;
            aOrbiterG = RotL64((aOrbiterG * 0x26D6B533C6DED97DULL), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 0xB8FC07C0E5DBD085ULL;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 0x8DA2A3C8F5F1A2CCULL;
            aOrbiterE = RotL64((aOrbiterE * 0x9D2CCA652663061DULL), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 0x86206A904B69B03AULL) + aOUSaltG[(((511U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 0xC65BB29224E92C0AULL) ^ aOUSaltH[((aIndex + 322U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 0xBEA78B2E4C3F85B9ULL), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 0x0B426D2FE362E105ULL;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 0x9B789C36DF7652ECULL) ^ aOUSaltE[(((511U - aIndex) + 316U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 0x180ECAEC727E59C9ULL), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 0x79857A80873999D4ULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 0xBF5CF7D9472D6CA4ULL;
            aOrbiterK = RotL64((aOrbiterK * 0x8B26094E79B4E99BULL), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 0x9C1390304705A2D2ULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 0xC19021687BB9E0BCULL;
            aOrbiterA = RotL64((aOrbiterA * 0x0230D0A2A584088DULL), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 50U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 58U) + RotL64(aOrbiterC, 11U)) + aOrbiterB) + RotL64(aCarry, 47U)) + aWUSaltB[((aIndex + 177U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 53U)) + aOrbiterI);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 26U)) + aOrbiterE) + aWUSaltG[((aIndex + 79U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 3U) + RotL64(aOrbiterA, 43U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 5U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterJ, 47U)) + aWUSaltE[((aIndex + 453U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 19U)) + aOrbiterA) + RotL64(aCarry, 29U));
            aWandererI = aWandererI + (((RotL64(aCross, 14U) + aOrbiterD) + RotL64(aOrbiterG, 50U)) + aWUSaltF[(((511U - aIndex) + 393U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 57U)) + aOrbiterC);
            aWandererH = aWandererH + ((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 23U)) + aOrbiterF);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 13U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 4U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aAetherLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_A twist_loop_a (end)
    WRITE_OUT_MUTABLE_PARAMS;
}

void TwistExpander_Aldebaran_Arx::TWIST_B(TwistWorkSpace *pWorkSpace,
                     std::uint8_t *pSource,
                     std::uint8_t *pCrossLaneA,
                     std::uint8_t *pCrossLaneB,
                     std::uint8_t *pCrossLaneC,
                     std::uint8_t *pCrossLaneD,
                     MUTABLE_PARAMS) {
    std::uint8_t *aAetherLaneA = pWorkSpace->mAetherLaneA;
    std::uint8_t *aAetherLaneB = pWorkSpace->mAetherLaneB;
    std::uint8_t *aAetherLaneC = pWorkSpace->mAetherLaneC;
    std::uint8_t *aAetherLaneD = pWorkSpace->mAetherLaneD;
    std::uint8_t *aLunarLaneA = pWorkSpace->mLunarLaneA;
    std::uint8_t *aLunarLaneB = pWorkSpace->mLunarLaneB;
    std::uint8_t *aLunarLaneC = pWorkSpace->mLunarLaneC;
    std::uint8_t *aLunarLaneD = pWorkSpace->mLunarLaneD;
    std::uint64_t *aOASaltA = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltA;
    std::uint64_t *aOASaltB = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltB;
    std::uint64_t *aOASaltD = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltD;
    std::uint64_t *aOASaltF = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltF;
    std::uint64_t *aOASaltG = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltG;
    std::uint64_t *aOASaltH = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltH;
    std::uint64_t *aOUSaltA = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltA;
    std::uint64_t *aOUSaltB = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltB;
    std::uint64_t *aOUSaltC = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltC;
    std::uint64_t *aOUSaltD = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltD;
    std::uint64_t *aOUSaltE = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltE;
    std::uint64_t *aOUSaltF = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltF;
    std::uint64_t *aOUSaltG = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltG;
    std::uint64_t *aOUSaltH = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltH;
    std::uint64_t *aWUSaltA = pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltA;
    std::uint64_t *aWUSaltB = pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltB;
    std::uint64_t *aWUSaltD = pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltD;
    std::uint64_t *aWUSaltE = pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltE;
    std::uint64_t *aWUSaltF = pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltF;
    std::uint64_t *aWUSaltG = pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltG;
    std::uint64_t *aWUSaltH = pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltH;
    const std::uint64_t &aTwistDomainWordIngress = pWorkSpace->mDomainBundle.mTwistConstants.mIngress;
    const std::uint64_t &aTwistDomainWordScatter = pWorkSpace->mDomainBundle.mTwistConstants.mScatter;
    const std::uint64_t &aTwistDomainWordCross = pWorkSpace->mDomainBundle.mTwistConstants.mCross;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [twist arx]
    std::uint8_t *aSource = pSource;
    READ_IN_MUTABLE_PARAMS;
    // GTwistRunTwist_B twist_loop_b (start)
    {
        //
        // File: nexus_03/loop_000327.bin
        //
        // Head:        [1, 10, 5, 8, 0, 9, 4, 3, 7, 2, 6]
        // Tail A:      [6, 4, 5, 8, 2, 10, 0, 7, 9, 1, 3]
        // Tail B:      [9, 8, 4, 3, 1, 0, 5, 10, 2, 6, 7]
        //
        // Heart:       [{ 0, 1, 2 },
        //               { 3, 4, 5 },
        //               { 6, 2, 7 },
        //               { 8, 9, 1 },
        //               { 10, 5, 4 },
        //               { 7, 8, 0 },
        //               { 2, 10, 3 },
        //               { 4, 0, 6 },
        //               { 1, 3, 9 },
        //               { 5, 6, 8 },
        //               { 9, 7, 10 }]
        //
        // Orbiters:    [BGAJICEDHKF]
        // Wanderers:   [GCEFDKBJAHI]
        //
        // Ingress:     aAetherLaneD (-->), aAetherLaneB (-->), pCrossLaneC (<-?->)
        //
        // Cross:       aAetherLaneC (<--), aAetherLaneA (<--), aSource (<-?->)
        //
        // Destination: aLunarLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aAetherLaneD[((aIndex + 7228U)) & S_BLOCK1], 47U) ^ RotL64(aAetherLaneB[((aIndex + 2553U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(pCrossLaneC[((aIndex + 342U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseA((aIngress ^ aTwistDomainWordIngress));
            //
            aCross = (RotL64(aAetherLaneC[((S_BLOCK1 - aIndex + 3536U)) & S_BLOCK1], 11U) ^ RotL64(aAetherLaneA[((S_BLOCK1 - aIndex + 7700U)) & S_BLOCK1], 46U));
            aCross ^= RotL64(aSource[((S_BLOCK1 - aIndex + 5402U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC((aCross ^ aTwistDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCarry, 57U)) ^ (RotL64(aCross, 44U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aTwistDomainWordScatter));
            //
            aOrbiterB = ((aWandererC + RotL64(aIngress, 12U)) + RotL64(aCarry, 37U)) + 0x0E651389609AF3BCULL;
            aOrbiterG = (aWandererI + RotL64(aScatter, 37U)) + 0xD8EE3BAC0B0DCADEULL;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 29U)) + 0x5A96BD8735BE6DBFULL;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 53U)) + 0x9663C5083E92A3E0ULL;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 6U)) + 0x6EEC0B5B8FDD221CULL) + aOASaltB[((aIndex + 256U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aScatter, 27U)) + 0x968443C0D2189159ULL;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 35U)) + 0xC769CA5E84A3CB1CULL;
            aOrbiterD = (((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 0x876B7F130113554BULL) + aOASaltD[((aIndex + 248U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 39U)) + 0x2589EAD313FAB4EAULL) + aOASaltH[(((511U - aIndex) + 191U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aScatter, 3U)) + 0xF9A235DD360722CEULL;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 53U)) + 0xAE4ED673C1B06505ULL;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 0xCBAC614BDAAB12F3ULL) + aOUSaltA[((aIndex + 241U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 0x1861BD51A64DDC7DULL;
            aOrbiterA = RotL64((aOrbiterA * 0xCC13D9972DF74251ULL), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 0x9F43A0E3797CF199ULL) + aOUSaltF[(((511U - aIndex) + 177U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 0x785D5738988B26FAULL;
            aOrbiterC = RotL64((aOrbiterC * 0x71A485D70B3584D5ULL), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 0x3D37440EBFAC929CULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 0xBE78EB9A33CBCE3DULL;
            aOrbiterD = RotL64((aOrbiterD * 0x8E4942B8A988742FULL), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 0xF4A25A4279B310D6ULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 0x4ECDB1A43573D110ULL;
            aOrbiterG = RotL64((aOrbiterG * 0x6E3148D38E5A29E9ULL), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 0xD0523857F2D6F28EULL;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 0x69B2F594253FB1F8ULL) ^ aOUSaltE[(((511U - aIndex) + 260U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 0x66E19501F7759DC5ULL), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 0x4B40BC8813D6811BULL;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 0x6A1D712A99396B3EULL) ^ aOUSaltD[(((511U - aIndex) + 243U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 0xA301D68780A1B4CDULL), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 0xA635A2FE0B771A91ULL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 0xCE25CE3591C4982AULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0xA0EC92F05D60A52FULL), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 0xF1DD72DAA9A23B82ULL;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 0x1602D489A271DC5EULL) ^ aOUSaltG[((aIndex + 277U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 0xF37E5A71D915D437ULL), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 0x7E41A120817A02CCULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 0x1B4A271E052890F5ULL;
            aOrbiterK = RotL64((aOrbiterK * 0x9A68B7EB6F5A178DULL), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 0x9DCD2226F1301603ULL;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 0x57547F602265246CULL;
            aOrbiterH = RotL64((aOrbiterH * 0x6A9E1DC5E1B4BFAFULL), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 0x7BFBD6FAF57CA7F0ULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 0x25CE9F97A9AF1DB9ULL;
            aOrbiterF = RotL64((aOrbiterF * 0x130361BEC5F35575ULL), 23U);
            //
            aIngress = RotL64(aOrbiterK, 27U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 18U));
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterK, 23U)) + aWUSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 14U) + aOrbiterI) + RotL64(aOrbiterH, 13U));
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterI, 39U)) + aWUSaltA[((aIndex + 36U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD + (((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterG, 27U)) + aWUSaltH[(((511U - aIndex) + 493U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 6U)) + aOrbiterB) + aWUSaltD[(((511U - aIndex) + 273U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 44U) + RotL64(aOrbiterB, 51U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterF, 41U));
            aWandererA = aWandererA + ((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterA, 3U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 29U));
            aWandererI = aWandererI + ((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterD, 44U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 50U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 12U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aLunarLaneA[aIndex] = aIngress;
        }
    
        //
        // File: nexus_11/loop_000737.bin
        //
        // Head:        [5, 3, 1, 9, 10, 8, 7, 2, 6, 0, 4]
        // Tail A:      [1, 4, 6, 2, 9, 7, 3, 5, 0, 8, 10]
        // Tail B:      [7, 5, 1, 3, 4, 10, 9, 6, 8, 2, 0]
        //
        // Heart:       [{ 0, 1, 2 },
        //               { 3, 4, 5 },
        //               { 6, 7, 8 },
        //               { 9, 5, 0 },
        //               { 10, 2, 1 },
        //               { 7, 8, 4 },
        //               { 1, 9, 3 },
        //               { 4, 10, 6 },
        //               { 5, 0, 7 },
        //               { 2, 6, 9 },
        //               { 8, 3, 10 }]
        //
        // Orbiters:    [KHAJGFDCIEB]
        // Wanderers:   [JDFBCKEIHAG]
        //
        // Ingress:     aLunarLaneA (-->), aAetherLaneC (-->), pCrossLaneA (<-?->)
        //
        // Cross:       aAetherLaneD (<--), aAetherLaneB (<--), pCrossLaneD (<-?->)
        //
        // Destination: aLunarLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aLunarLaneA[((aIndex + 16307U)) & S_BLOCK1], 13U) ^ RotL64(aAetherLaneC[((aIndex + 16322U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(pCrossLaneA[((aIndex + 8487U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC((aIngress ^ aTwistDomainWordIngress));
            //
            aCross = (RotL64(aAetherLaneD[((S_BLOCK1 - aIndex + 14409U)) & S_BLOCK1], 13U) ^ RotL64(aAetherLaneB[((S_BLOCK1 - aIndex + 15371U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(pCrossLaneD[((S_BLOCK1 - aIndex + 15805U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseC((aCross ^ aTwistDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aCross, 27U) + RotL64(aPrevious, 14U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aTwistDomainWordScatter));
            //
            aOrbiterK = (aWandererK + RotL64(aScatter, 13U)) + 0x57E45FAE8FE43482ULL;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 21U)) + 0x81C2E18BA2CBBB0DULL;
            aOrbiterA = (aWandererD + RotL64(aCross, 11U)) + 0xC84F2555E1B38431ULL;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 27U)) + 0x6062A3ED01B35EF8ULL;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 4U)) + RotL64(aCarry, 51U)) + 0xD1632C6C15E52739ULL;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 53U)) + 0xAC2CC544BCA8B56EULL;
            aOrbiterD = (aWandererI + RotL64(aCross, 37U)) + 0xAD405BCF2F8F0E50ULL;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 51U)) + 0xDC89EE84B31F394FULL) + aOASaltG[(((511U - aIndex) + 103U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 11U)) + 0xAB533A142CCCECCDULL;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 47U)) + 0x13130105B29FDD83ULL) + aOASaltF[((aIndex + 423U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aCross, 24U)) + 0x9C90764309061DC8ULL) + aOASaltH[(((511U - aIndex) + 6U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 0x42C154BB7A7C85FCULL;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 0x6AD77ED2F497C628ULL) ^ aOUSaltH[((aIndex + 261U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 0x53EC6F87EC24C607ULL), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 0xF84950B264A4ADE9ULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 0x314E905518DEAC07ULL;
            aOrbiterF = RotL64((aOrbiterF * 0xE8EC9892544BDF03ULL), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 0x326E2E0451B6AF25ULL;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 0xED7DAAEFBDE475DCULL) ^ aOUSaltG[(((511U - aIndex) + 485U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 0x54F4A1AB1069C865ULL), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 0x756408F6710E7A40ULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 0x65F9DFAE513C2F22ULL;
            aOrbiterK = RotL64((aOrbiterK * 0x2E71032D9AD0DD53ULL), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 0x8953DEF187EF1610ULL;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 0x18A7E7E2BE96853FULL;
            aOrbiterH = RotL64((aOrbiterH * 0x5347C4A8A5D637B1ULL), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 0xE4EB86ACEFD4478DULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 0xA7B0B9E9DEC7EAEBULL;
            aOrbiterG = RotL64((aOrbiterG * 0xCEEBAD0DD36CC949ULL), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 0x5066A9E6A07C42A5ULL;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 0x0CC7582FA75C350CULL) ^ aOUSaltB[((aIndex + 391U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 0x9D9926286170B301ULL), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 0x5C30924FD9D52214ULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 0x0DB78646AFAEA9CBULL;
            aOrbiterD = RotL64((aOrbiterD * 0x6A3ED2632F40DF61ULL), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 0xB175E91D8AFE4BEFULL;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 0x8A1EAF7E535FBA2BULL;
            aOrbiterC = RotL64((aOrbiterC * 0x58AA79719E4F1E4BULL), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 0x79114096095DF656ULL;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 0x7BFBD25956B5418EULL) ^ aOUSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 0x1B2FEA907D6902DFULL), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 0x37D2233ABF4D94E1ULL;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 0x16B204EABCA533CFULL;
            aOrbiterB = RotL64((aOrbiterB * 0x3CA7D2B42711FA29ULL), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 44U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 26U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aPrevious, 38U) + aOrbiterG) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterH, 3U));
            aWandererB = aWandererB + ((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterJ, 21U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterG, 23U)) + aWUSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 46U)) + aOrbiterB);
            aWandererE = aWandererE ^ ((((RotL64(aCross, 46U) + RotL64(aOrbiterJ, 51U)) + aOrbiterE) + RotL64(aCarry, 29U)) + aWUSaltA[(((511U - aIndex) + 115U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterD, 57U)) + aWUSaltD[(((511U - aIndex) + 124U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 11U)) + aOrbiterI) + aWUSaltE[((aIndex + 198U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterA, 41U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterK, 43U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 34U));
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 50U));
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aLunarLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // File: nexus_05/loop_000024.bin
        //
        // Head:        [6, 4, 3, 8, 1, 5, 9, 7, 2, 0, 10]
        // Tail A:      [0, 2, 6, 10, 8, 3, 5, 1, 7, 4, 9]
        // Tail B:      [3, 9, 10, 0, 2, 7, 8, 4, 1, 5, 6]
        //
        // Heart:       [{ 0, 1, 2 },
        //               { 3, 4, 5 },
        //               { 6, 2, 7 },
        //               { 8, 9, 1 },
        //               { 10, 5, 4 },
        //               { 7, 8, 0 },
        //               { 2, 10, 3 },
        //               { 5, 0, 6 },
        //               { 1, 3, 9 },
        //               { 4, 6, 8 },
        //               { 9, 7, 10 }]
        //
        // Orbiters:    [JGEAKCFHIDB]
        // Wanderers:   [FHGECKIABJD]
        //
        // Ingress:     aLunarLaneB (-->), aAetherLaneD (-->), pCrossLaneB (<-?->)
        //
        // Cross:       aLunarLaneA (<--), aAetherLaneC (<--)
        //
        // Destination: aLunarLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aLunarLaneB[((aIndex + 17892U)) & S_BLOCK1], 21U) ^ RotL64(aAetherLaneD[((aIndex + 18816U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(pCrossLaneB[((aIndex + 20893U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseC((aIngress ^ aTwistDomainWordIngress));
            //
            aCross = RotL64(aLunarLaneA[((S_BLOCK1 - aIndex + 22515U)) & S_BLOCK1], 26U) ^ RotL64(aAetherLaneC[((S_BLOCK1 - aIndex + 22183U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB((aCross ^ aTwistDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCross, 51U)) + (RotL64(aCarry, 19U) ^ RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aTwistDomainWordScatter));
            //
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 19U)) + 0xCFDFC86313BA70B0ULL;
            aOrbiterG = (aWandererC + RotL64(aCross, 11U)) + 0x90E69CDF5BBA72E6ULL;
            aOrbiterE = (((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 53U)) + 0xC2D151EF9F563CCBULL) + aOASaltG[((aIndex + 62U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aScatter, 26U)) + 0x24084819C0DD5B4EULL) + aOASaltA[(((511U - aIndex) + 39U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aPrevious, 29U)) + 0x9F48C5D3016DA3D8ULL;
            aOrbiterC = (((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 47U)) + 0xF88D8CBF92E0B48EULL) + aOASaltF[((aIndex + 135U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aIngress, 39U)) + 0x52860F62B71606A0ULL;
            aOrbiterH = (aWandererA + RotL64(aScatter, 47U)) + 0xF86CE510AC20B2A6ULL;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 41U)) + 0xC8C4A1A9371DD052ULL;
            aOrbiterD = ((aWandererF + RotL64(aCross, 52U)) + RotL64(aCarry, 23U)) + 0xC0774F71E0596941ULL;
            aOrbiterB = (aWandererD + RotL64(aIngress, 57U)) + 0x7B05E6B65374D767ULL;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 0x6C0D98AA76C0BED9ULL;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 0xADCE7906922D03E5ULL;
            aOrbiterE = RotL64((aOrbiterE * 0x9616E9553398C535ULL), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 0x5B3D8E22EC5FA31FULL;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 0x6BC882B64EE27D7DULL;
            aOrbiterC = RotL64((aOrbiterC * 0x6ADDFDE8BE3E945DULL), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 0x779BCAE3D2D1C345ULL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 0x1DC5E0212E969307ULL) ^ aOUSaltH[(((511U - aIndex) + 501U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 0x6735245F27D4F75BULL), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 0xF864791EB440BDB0ULL) + aOUSaltF[(((511U - aIndex) + 433U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 0x1523B5477484E638ULL;
            aOrbiterG = RotL64((aOrbiterG * 0x30AC18CFC3A859B7ULL), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 0x2B8D16939CBC610FULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 0xA782B2454E9902CAULL;
            aOrbiterK = RotL64((aOrbiterK * 0x7188DD0DB2C31E61ULL), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 0xAEA91B32EB173751ULL) + aOUSaltC[((aIndex + 33U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 0x17210578C15BC918ULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0x9330195C7F1688BDULL), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 0xFDA98CC74246D4C0ULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 0x4FC66EB4B9CDA108ULL;
            aOrbiterA = RotL64((aOrbiterA * 0xDF6E79EEF506E7DBULL), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 0x39EC778C93AE0A2BULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 0xE3C5111AB59E21C6ULL;
            aOrbiterF = RotL64((aOrbiterF * 0x95B913B329150DD5ULL), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 0x666A8ECAA138226CULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 0x8473F6E4FAF07491ULL;
            aOrbiterD = RotL64((aOrbiterD * 0x70613749E0274D5FULL), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 0x70C7A10AE9CD851AULL) + aOUSaltA[((aIndex + 417U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 0xBDAA17CADBE1AF4CULL;
            aOrbiterI = RotL64((aOrbiterI * 0xC8CFC55926BD1B4DULL), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 0xD9858DB8D7A4DBFAULL;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 0x449D41D1428C9F62ULL;
            aOrbiterB = RotL64((aOrbiterB * 0x5EFDFD59096D9461ULL), 11U);
            //
            aIngress = RotL64(aOrbiterF, 5U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 10U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterA, 23U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 54U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterB, 41U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterJ, 39U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 53U)) + aWUSaltH[(((511U - aIndex) + 469U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 37U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aCross, 44U) + RotL64(aOrbiterC, 3U)) + aOrbiterI) + aWUSaltD[(((511U - aIndex) + 337U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterK, 35U));
            aWandererB = aWandererB + ((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterG, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 57U)) + aOrbiterC) + RotL64(aCarry, 27U));
            aWandererD = aWandererD + (((RotL64(aCross, 60U) + aOrbiterD) + RotL64(aOrbiterF, 6U)) + aWUSaltF[(((511U - aIndex) + 136U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 6U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aLunarLaneC[aIndex] = aIngress;
        }
    
        //
        // File: nexus_11/loop_000164.bin
        //
        // Head:        [9, 7, 4, 6, 10, 3, 8, 1, 2, 5, 0]
        // Tail A:      [2, 5, 3, 8, 6, 7, 0, 9, 1, 4, 10]
        // Tail B:      [5, 1, 9, 2, 3, 10, 6, 4, 7, 8, 0]
        //
        // Heart:       [{ 0, 1, 2 },
        //               { 3, 4, 5 },
        //               { 6, 7, 8 },
        //               { 9, 5, 0 },
        //               { 10, 2, 1 },
        //               { 7, 8, 4 },
        //               { 1, 9, 3 },
        //               { 4, 10, 6 },
        //               { 5, 0, 7 },
        //               { 2, 6, 9 },
        //               { 8, 3, 10 }]
        //
        // Orbiters:    [GBHJDIEKCFA]
        // Wanderers:   [KAHBFEDCJIG]
        //
        // Ingress:     aLunarLaneC (-->), aLunarLaneA (<-?->)
        //
        // Cross:       aLunarLaneB (<--), aAetherLaneD (<-?->)
        //
        // Destination: aLunarLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aLunarLaneC[((aIndex + 30212U)) & S_BLOCK1], 60U) ^ RotL64(aLunarLaneA[((aIndex + 26375U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA((aIngress ^ aTwistDomainWordIngress));
            //
            aCross = RotL64(aLunarLaneB[((S_BLOCK1 - aIndex + 27168U)) & S_BLOCK1], 5U) ^ RotL64(aAetherLaneD[((S_BLOCK1 - aIndex + 29336U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseC((aCross ^ aTwistDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCross, 11U)) ^ (RotL64(aCarry, 54U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aTwistDomainWordScatter));
            //
            aOrbiterG = (aWandererI + RotL64(aCross, 24U)) + 0x3C6D6CA76638BD4BULL;
            aOrbiterB = (aWandererC + RotL64(aIngress, 27U)) + 0x33483881F27A482AULL;
            aOrbiterH = (aWandererF + RotL64(aScatter, 21U)) + 0x57D451A4723CD54DULL;
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 37U)) + RotL64(aCarry, 39U)) + 0x048FB2B22C48A6BDULL) + aOASaltG[(((511U - aIndex) + 249U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aCross, 48U)) + 0xB7E092274B983255ULL;
            aOrbiterI = (aWandererB + RotL64(aIngress, 13U)) + 0xA78B8DE5AF18CB2DULL;
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 27U)) + 0x64928F8CEE3EC0F7ULL) + aOASaltB[((aIndex + 371U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aPrevious, 51U)) + 0x97CFCDDE8F8567A8ULL;
            aOrbiterC = (aWandererH + RotL64(aCross, 57U)) + 0x210DD19953C0B4B3ULL;
            aOrbiterF = (aWandererE + RotL64(aIngress, 53U)) + 0xFBD4A19587A624B4ULL;
            aOrbiterA = (((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 47U)) + 0x1E110D129842628CULL) + aOASaltA[((aIndex + 1U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 0x582DBB19F57057ACULL) + aOUSaltC[((aIndex + 391U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 0x79A70769FAB4D177ULL;
            aOrbiterH = RotL64((aOrbiterH * 0xD3211C3AFE73114BULL), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 0x3667E4B5EC045378ULL;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 0x10A4C289CE2C8C43ULL;
            aOrbiterI = RotL64((aOrbiterI * 0xFB78A8D8648ADB1DULL), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 0xA749522E4B4C634BULL;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 0x27AC2B08D03D6167ULL;
            aOrbiterC = RotL64((aOrbiterC * 0x8704EB63E2F54F3DULL), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 0x8F7957D2FBEEA7ABULL) + aOUSaltD[((aIndex + 116U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 0x8F3385D489FA612AULL) ^ aOUSaltH[(((511U - aIndex) + 277U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 0x8FD27E7D55936733ULL), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 0x6AAE772967C59CB1ULL) + aOUSaltA[(((511U - aIndex) + 362U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 0xBC39386EDF459568ULL;
            aOrbiterB = RotL64((aOrbiterB * 0xCDE80957951741BBULL), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 0xF055A3E6A6421DADULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 0x1B3331086D6236A6ULL;
            aOrbiterD = RotL64((aOrbiterD * 0x901B699065A8C4DDULL), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 0x5F5B27BC72B534F0ULL;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 0xF47AD362B62E0EBCULL) ^ aOUSaltB[(((511U - aIndex) + 302U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 0xC7EACB3311BBD943ULL), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 0x7520644791B9EE4CULL;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 0x6B6E36DD75C9DAB9ULL;
            aOrbiterE = RotL64((aOrbiterE * 0x5122A990A7225523ULL), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 0x4D35A4D81B227734ULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 0xD05D9D9F08F1EDB2ULL;
            aOrbiterK = RotL64((aOrbiterK * 0xE96E79321BBF0CE5ULL), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 0x59C0F57E8372E9C8ULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 0x4F175EF3BEF4065AULL;
            aOrbiterF = RotL64((aOrbiterF * 0x9A3A5F2C8280EBDDULL), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 0x2BB0C8526A71BF6DULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 0x63CA2A616CCE42B7ULL;
            aOrbiterA = RotL64((aOrbiterA * 0x9080A89DCB4D2713ULL), 5U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 26U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 58U)) + aOrbiterI) + aWUSaltD[(((511U - aIndex) + 392U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 34U) + RotL64(aOrbiterI, 35U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterF, 11U));
            aWandererB = aWandererB + ((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterH, 51U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterJ, 19U)) + aWUSaltG[(((511U - aIndex) + 201U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 37U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterG, 3U)) + aOrbiterE);
            aWandererC = aWandererC + ((((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 3U)) + aWUSaltB[(((511U - aIndex) + 149U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 27U)) + aOrbiterK) + aWUSaltA[((aIndex + 318U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 44U) + RotL64(aOrbiterD, 41U)) + aOrbiterC) + aWUSaltF[((aIndex + 343U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterG, 14U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 46U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aLunarLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_B twist_loop_b (end)
    WRITE_OUT_MUTABLE_PARAMS;
}

void TwistExpander_Aldebaran_Arx::TWIST_C(TwistWorkSpace *pWorkSpace,
                     std::uint8_t *pSource,
                     std::uint8_t *pCrossLaneA,
                     std::uint8_t *pCrossLaneB,
                     std::uint8_t *pCrossLaneC,
                     std::uint8_t *pCrossLaneD,
                     MUTABLE_PARAMS) {
    std::uint8_t *aEarthLaneA = pWorkSpace->mEarthLaneA;
    std::uint8_t *aEarthLaneB = pWorkSpace->mEarthLaneB;
    std::uint8_t *aEarthLaneC = pWorkSpace->mEarthLaneC;
    std::uint8_t *aEarthLaneD = pWorkSpace->mEarthLaneD;
    std::uint8_t *aCrystalLaneA = pWorkSpace->mCrystalLaneA;
    std::uint8_t *aCrystalLaneB = pWorkSpace->mCrystalLaneB;
    std::uint8_t *aCrystalLaneC = pWorkSpace->mCrystalLaneC;
    std::uint8_t *aCrystalLaneD = pWorkSpace->mCrystalLaneD;
    std::uint8_t *aAetherLaneA = pWorkSpace->mAetherLaneA;
    std::uint8_t *aAetherLaneB = pWorkSpace->mAetherLaneB;
    std::uint8_t *aAetherLaneC = pWorkSpace->mAetherLaneC;
    std::uint8_t *aAetherLaneD = pWorkSpace->mAetherLaneD;
    std::uint8_t *aLunarLaneA = pWorkSpace->mLunarLaneA;
    std::uint8_t *aLunarLaneB = pWorkSpace->mLunarLaneB;
    std::uint8_t *aLunarLaneC = pWorkSpace->mLunarLaneC;
    std::uint8_t *aLunarLaneD = pWorkSpace->mLunarLaneD;
    std::uint64_t *aOASaltA = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltA;
    std::uint64_t *aOASaltC = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltC;
    std::uint64_t *aOASaltD = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltD;
    std::uint64_t *aOASaltE = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltE;
    std::uint64_t *aOASaltF = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltF;
    std::uint64_t *aOASaltG = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltG;
    std::uint64_t *aOASaltH = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterAssign.mSaltH;
    std::uint64_t *aOUSaltA = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltA;
    std::uint64_t *aOUSaltB = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltB;
    std::uint64_t *aOUSaltC = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltC;
    std::uint64_t *aOUSaltD = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltD;
    std::uint64_t *aOUSaltE = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltE;
    std::uint64_t *aOUSaltF = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltF;
    std::uint64_t *aOUSaltG = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltG;
    std::uint64_t *aOUSaltH = pWorkSpace->mDomainBundle.mTwistSalts.mOrbiterUpdate.mSaltH;
    std::uint64_t *aWUSaltA = pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltA;
    std::uint64_t *aWUSaltB = pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltB;
    std::uint64_t *aWUSaltC = pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltC;
    std::uint64_t *aWUSaltD = pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltD;
    std::uint64_t *aWUSaltE = pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltE;
    std::uint64_t *aWUSaltF = pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltF;
    std::uint64_t *aWUSaltG = pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltG;
    std::uint64_t *aWUSaltH = pWorkSpace->mDomainBundle.mTwistSalts.mWandererUpdate.mSaltH;
    const std::uint64_t &aTwistDomainWordIngress = pWorkSpace->mDomainBundle.mTwistConstants.mIngress;
    const std::uint64_t &aTwistDomainWordScatter = pWorkSpace->mDomainBundle.mTwistConstants.mScatter;
    const std::uint64_t &aTwistDomainWordCross = pWorkSpace->mDomainBundle.mTwistConstants.mCross;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [twist arx]
    std::uint8_t *aSource = pSource;
    READ_IN_MUTABLE_PARAMS;
    // GTwistRunTwist_C twist_loop_c (start)
    {
        //
        // File: nexus_12/loop_000545.bin
        //
        // Head:        [8, 0, 2, 10, 5, 9, 4, 6, 7, 3, 1]
        // Tail A:      [7, 4, 10, 1, 0, 8, 2, 5, 3, 6, 9]
        // Tail B:      [8, 9, 6, 5, 4, 0, 10, 2, 1, 3, 7]
        //
        // Heart:       [{ 0, 1, 2 },
        //               { 3, 4, 5 },
        //               { 6, 7, 8 },
        //               { 1, 9, 4 },
        //               { 10, 5, 0 },
        //               { 2, 8, 7 },
        //               { 9, 0, 3 },
        //               { 4, 2, 6 },
        //               { 7, 10, 1 },
        //               { 5, 6, 9 },
        //               { 8, 3, 10 }]
        //
        // Orbiters:    [DABKEJICFGH]
        // Wanderers:   [DIEJCFHKAGB]
        //
        // Ingress:     aEarthLaneA (-->), aEarthLaneB (-->), aLunarLaneD (-->), pCrossLaneB (<-?->)
        //
        // Cross:       aEarthLaneC (<--), aEarthLaneD (<--), aLunarLaneB (<--), pCrossLaneA (<-?->)
        //
        // Destination: aCrystalLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aEarthLaneA[((aIndex + 2401U)) & S_BLOCK1], 21U) ^ RotL64(aEarthLaneB[((aIndex + 7195U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aLunarLaneD[((aIndex + 2874U)) & S_BLOCK1], 3U) ^ RotL64(pCrossLaneB[((aIndex + 1073U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aTwistDomainWordIngress));
            //
            aCross = (RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 3293U)) & S_BLOCK1], 52U) ^ RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 1967U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aLunarLaneB[((S_BLOCK1 - aIndex + 8069U)) & S_BLOCK1], 13U) ^ RotL64(pCrossLaneA[((S_BLOCK1 - aIndex + 3510U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aTwistDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 23U)) ^ (RotL64(aCarry, 6U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aTwistDomainWordScatter));
            //
            aOrbiterD = ((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 51U)) + 0xB8895CD11642CC18ULL;
            aOrbiterA = (aWandererD + RotL64(aScatter, 24U)) + 0x32264D33898321A3ULL;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 19U)) + 0x81DBCEA1B71106B5ULL;
            aOrbiterK = ((aWandererB + RotL64(aCross, 13U)) + 0xCE3B24B19FA8BEADULL) + aOASaltH[((aIndex + 300U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 13U)) + 0xD345FB5B9A8A6775ULL;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 29U)) + 0x0CBED7732A2C7F55ULL) + aOASaltA[((aIndex + 212U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 41U)) + 0x1171D9B2F8E16A7EULL) + aOASaltC[(((511U - aIndex) + 401U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 0x6BF6D06A409226EEULL;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 34U)) + 0xD141DA999DF7AA9FULL) + aOASaltF[(((511U - aIndex) + 177U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aScatter, 39U)) + 0xDC8EFDA928C9AACDULL;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 11U)) + 0xA54C34DC7366498AULL;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 0x219041AF7D9BAD92ULL) + aOUSaltA[(((511U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 0x037DBBF2AF0B5A87ULL;
            aOrbiterB = RotL64((aOrbiterB * 0x41EE40E150557D67ULL), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 0xEB7836B1646A6B50ULL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 0x931C889502F5498FULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0x07137F0204F80DB5ULL), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 0x74C7DC5B0417C546ULL;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 0xDD6CC6247E53F5E1ULL) ^ aOUSaltD[(((511U - aIndex) + 386U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 0xF65FDA7A9D985221ULL), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 0xD62BF365F2C1A1E9ULL;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 0xCC0EBBF676E18B3DULL;
            aOrbiterE = RotL64((aOrbiterE * 0xF6BD4B9FC3923AB1ULL), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 0xEBCFA5452D3F1D05ULL) + aOUSaltG[(((511U - aIndex) + 243U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 0x2566B47ECA6D647FULL;
            aOrbiterD = RotL64((aOrbiterD * 0xE98A5EF466812997ULL), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 0x5BE3120506AD50BEULL;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 0x109CC31616A51F47ULL;
            aOrbiterC = RotL64((aOrbiterC * 0x41BCAC877E7869ABULL), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 0x47C0CD8C89F2983DULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 0x229D87AA66E76376ULL;
            aOrbiterK = RotL64((aOrbiterK * 0xEA63B8860B583629ULL), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 0x82575A64C77619EDULL;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 0xAEA0342647A3C478ULL;
            aOrbiterI = RotL64((aOrbiterI * 0xC330DA890DBE4A3DULL), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 0xC8D7B2E98F0C98EAULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 0x1A5522729A82D8DFULL;
            aOrbiterA = RotL64((aOrbiterA * 0x6678F03BA4DE581FULL), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 0x57B9557B1FA77671ULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 0x3487B2CD12F32866ULL;
            aOrbiterG = RotL64((aOrbiterG * 0xDC3D9F84FA1EBD0BULL), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 0x7845345BC54B0165ULL) + aOUSaltE[(((511U - aIndex) + 410U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 0x4D612FC7CE28A875ULL) ^ aOUSaltB[((aIndex + 201U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 0x21151B742CCE57BDULL), 39U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 18U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 34U) + aOrbiterC) + RotL64(aOrbiterF, 44U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterG, 53U));
            aWandererE = aWandererE + (((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 27U)) + aOrbiterI) + aWUSaltB[((aIndex + 305U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterJ, 57U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 27U)) + aWUSaltG[((aIndex + 217U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterF, 21U)) + aOrbiterD) + aWUSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 51U)) + aOrbiterH);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterB, 5U)) + aWUSaltH[((aIndex + 481U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterA, 19U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterK, 29U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 10U) + RotL64(aOrbiterG, 10U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aWUSaltF[((aIndex + 279U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 44U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + RotL64(aWandererF, 60U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aCrystalLaneA[aIndex] = aIngress;
        }
    
        //
        // File: nexus_00/loop_000651.bin
        //
        // Head:        [7, 10, 9, 8, 4, 6, 1, 2, 5, 0, 3]
        // Tail A:      [10, 5, 2, 0, 8, 1, 9, 3, 7, 6, 4]
        // Tail B:      [2, 4, 8, 6, 0, 5, 7, 9, 1, 3, 10]
        //
        // Heart:       [{ 0, 1, 2 },
        //               { 3, 4, 5 },
        //               { 6, 2, 7 },
        //               { 8, 9, 10 },
        //               { 5, 7, 0 },
        //               { 1, 6, 4 },
        //               { 10, 0, 3 },
        //               { 2, 5, 9 },
        //               { 7, 3, 8 },
        //               { 9, 10, 1 },
        //               { 4, 8, 6 }]
        //
        // Orbiters:    [KCIBDAGEFJH]
        // Wanderers:   [ECHKFIAGJBD]
        //
        // Ingress:     aCrystalLaneA (-->), aEarthLaneC (-->), aAetherLaneC (-->), aLunarLaneA (<-?->)
        //
        // Cross:       aEarthLaneA (<--), aEarthLaneB (<--), aLunarLaneC (<--), aSource (<-?->)
        //
        // Destination: aCrystalLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aCrystalLaneA[((aIndex + 11825U)) & S_BLOCK1], 13U) ^ RotL64(aEarthLaneC[((aIndex + 9269U)) & S_BLOCK1], 54U));
            aIngress ^= (RotL64(aAetherLaneC[((aIndex + 10675U)) & S_BLOCK1], 41U) ^ RotL64(aLunarLaneA[((aIndex + 9957U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aTwistDomainWordIngress));
            //
            aCross = (RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 13739U)) & S_BLOCK1], 47U) ^ RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 16342U)) & S_BLOCK1], 27U));
            aCross ^= (RotL64(aLunarLaneC[((S_BLOCK1 - aIndex + 13562U)) & S_BLOCK1], 3U) ^ RotL64(aSource[((aIndex + 12417U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseB((aCross ^ aTwistDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 21U)) ^ (RotL64(aPrevious, 40U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aTwistDomainWordScatter));
            //
            aOrbiterK = (aWandererG + RotL64(aScatter, 3U)) + 0xEF0726CE287425CAULL;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 19U)) + RotL64(aCarry, 5U)) + 0x0C8C9755092A1F45ULL;
            aOrbiterI = ((aWandererB + RotL64(aCross, 21U)) + 0x130E05F1D352BD7CULL) + aOASaltF[((aIndex + 319U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aIngress, 51U)) + 0x04CB7B954CDAA682ULL;
            aOrbiterD = (aWandererF + RotL64(aScatter, 26U)) + 0x468DB3BDC90CF8A3ULL;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 41U)) + RotL64(aCarry, 29U)) + 0xBE5FCC8D5D5BD97CULL;
            aOrbiterG = ((aWandererC + RotL64(aCross, 5U)) + 0x8440B35A4B102A12ULL) + aOASaltD[(((511U - aIndex) + 381U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aIngress, 43U)) + 0x76EC79B10D70E97CULL) + aOASaltE[(((511U - aIndex) + 46U)) & S_SALT1];
            aOrbiterF = (((aWandererI + RotL64(aScatter, 56U)) + RotL64(aCarry, 53U)) + 0xB8F5593E12D96A4CULL) + aOASaltC[((aIndex + 368U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 23U)) + 0x5A77A9E9A143DC95ULL) + aOASaltG[((aIndex + 285U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aCross, 47U)) + 0xD32421431C61991AULL;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 0x6C9282DCDC12E3DAULL;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 0x77498CCAA3ACD825ULL;
            aOrbiterI = RotL64((aOrbiterI * 0x9021FA8E4505D66BULL), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 0xDF57943363492D23ULL) + aOUSaltG[((aIndex + 464U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 0xD0F7B82ABA47B25BULL;
            aOrbiterA = RotL64((aOrbiterA * 0x83CD09669E1153CDULL), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 0x99223FB187BC6383ULL;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 0xE239C861194F678DULL;
            aOrbiterE = RotL64((aOrbiterE * 0x9DA07A90E8437263ULL), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 0x0B303B7042EB97B4ULL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 0x1FAF95F11D4E18DBULL) ^ aOUSaltF[((aIndex + 468U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 0x514B9E55250B5DBBULL), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 0x24DA3D3EBF12EEBBULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 0x82A878943A2579B5ULL;
            aOrbiterK = RotL64((aOrbiterK * 0x0EC5C323B3CE2AA7ULL), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 0xE63447F70E95826BULL) + aOUSaltB[(((511U - aIndex) + 207U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 0x78C779AA29D9E3B7ULL;
            aOrbiterD = RotL64((aOrbiterD * 0xC230B3B9B53B0C7DULL), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 0x41E9694A34CD0E2FULL;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 0x292B566196F8D0CEULL) ^ aOUSaltA[(((511U - aIndex) + 509U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 0x489F9612730E26D3ULL), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 0x98B494E5B99689FBULL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 0x15565FDAD2EC0BCBULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0xDA31667F1F748C07ULL), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 0x40E64DBAA4C3761CULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 0xA9A95DA7C271BD89ULL;
            aOrbiterF = RotL64((aOrbiterF * 0xD93D0E5ED3CCA411ULL), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 0x4AEE6BC3125289B8ULL;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 0xCEABF9A9909B6DCBULL;
            aOrbiterC = RotL64((aOrbiterC * 0x199E0AADFBF80831ULL), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 0x956F2222740C538DULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 0x28D12AD32C388B83ULL;
            aOrbiterG = RotL64((aOrbiterG * 0x9493F68FB8FE6511ULL), 21U);
            //
            aIngress = RotL64(aOrbiterK, 52U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 36U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 43U)) + aOrbiterI) + aWUSaltE[((aIndex + 318U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 58U) + aOrbiterA) + RotL64(aOrbiterD, 3U)) + aWUSaltC[(((511U - aIndex) + 505U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 40U)) + aOrbiterF) + RotL64(aCarry, 47U));
            aWandererK = aWandererK + ((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterG, 5U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterK, 13U));
            aWandererI = aWandererI + (((RotL64(aCross, 37U) + RotL64(aOrbiterC, 21U)) + aOrbiterA) + aWUSaltA[((aIndex + 83U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 37U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 53U)) + aOrbiterC) + aWUSaltG[(((511U - aIndex) + 138U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterB, 51U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterD, 18U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 22U));
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aCrystalLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        //
        // File: nexus_05/loop_000030.bin
        //
        // Head:        [10, 7, 8, 3, 6, 4, 2, 1, 0, 5, 9]
        // Tail A:      [4, 3, 9, 5, 8, 2, 0, 10, 1, 7, 6]
        // Tail B:      [0, 8, 3, 1, 2, 7, 10, 6, 4, 5, 9]
        //
        // Heart:       [{ 0, 1, 2 },
        //               { 3, 4, 5 },
        //               { 6, 2, 7 },
        //               { 8, 9, 1 },
        //               { 10, 5, 4 },
        //               { 7, 8, 0 },
        //               { 2, 10, 3 },
        //               { 5, 0, 6 },
        //               { 1, 3, 9 },
        //               { 4, 6, 8 },
        //               { 9, 7, 10 }]
        //
        // Orbiters:    [CFKJDBAEGIH]
        // Wanderers:   [HABKCIGFEJD]
        //
        // Ingress:     aCrystalLaneB (-->), aEarthLaneD (-->), aAetherLaneD (<-?->)
        //
        // Cross:       aCrystalLaneA (<--), aEarthLaneB (<--), pCrossLaneD (<-?->)
        //
        // Destination: aCrystalLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aCrystalLaneB[((aIndex + 24048U)) & S_BLOCK1], 13U) ^ RotL64(aEarthLaneD[((aIndex + 23079U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aAetherLaneD[((aIndex + 21689U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB((aIngress ^ aTwistDomainWordIngress));
            //
            aCross = (RotL64(aCrystalLaneA[((S_BLOCK1 - aIndex + 20405U)) & S_BLOCK1], 52U) ^ RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 19598U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(pCrossLaneD[((S_BLOCK1 - aIndex + 22605U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC((aCross ^ aTwistDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 56U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aTwistDomainWordScatter));
            //
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 13U)) + 0xD1EAB4215D910FB5ULL) + aOASaltG[((aIndex + 262U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aCross, 35U)) + 0xDD1966B239418334ULL;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 38U)) + RotL64(aCarry, 35U)) + 0xAE53B771A5132367ULL) + aOASaltF[(((511U - aIndex) + 77U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 23U)) + 0xA14F409BDB09418BULL) + aOASaltE[(((511U - aIndex) + 274U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aPrevious, 51U)) + 0x77E29CB0EB9B6876ULL;
            aOrbiterB = (aWandererC + RotL64(aCross, 27U)) + 0x2797301C88A5C671ULL;
            aOrbiterA = (((aWandererB + RotL64(aIngress, 41U)) + RotL64(aCarry, 27U)) + 0x5C49372F2E9A22C8ULL) + aOASaltD[(((511U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aScatter, 3U)) + 0x62F85EB8B4B69705ULL) + aOASaltH[((aIndex + 364U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aPrevious, 10U)) + 0x8C977E4B23357888ULL;
            aOrbiterI = ((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 39U)) + 0xE1570B10CB6EA696ULL;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 57U)) + 0x8438BC39AEEEFD1FULL;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 0xBC866933CEE50389ULL) + aOUSaltE[((aIndex + 232U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 0xA0544089C446FDCDULL) ^ aOUSaltC[((aIndex + 91U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 0xB656D34EC404DEEDULL), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 0x73A6B5450E9E297AULL) + aOUSaltF[((aIndex + 227U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 0x711A9D56B68EF8BAULL;
            aOrbiterB = RotL64((aOrbiterB * 0x3B8C0D719B010EF9ULL), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 0x6CC8DF719B513476ULL;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 0x868310F8A8D993EEULL) ^ aOUSaltG[((aIndex + 169U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 0xC0D5E47E9B4686F7ULL), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 0xA3F3875EB5D411B8ULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 0xF7678F63975554BAULL;
            aOrbiterF = RotL64((aOrbiterF * 0xA2F073AD549A606FULL), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 0x3A4CBDEE1C761846ULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 0xDE6B72534792F0C4ULL;
            aOrbiterD = RotL64((aOrbiterD * 0x0E9D821D07C34A19ULL), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 0x23991D3D9959B0D8ULL;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 0xE254E49B6FE99F91ULL;
            aOrbiterC = RotL64((aOrbiterC * 0xF59E8A22397EFD43ULL), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 0xCE303194A6FDD220ULL) + aOUSaltD[(((511U - aIndex) + 213U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 0xD131C1BEB6E0FE7DULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0xF1B1D474C8B06183ULL), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 0x58878604B869CBDBULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 0x5CF64E65D723F983ULL;
            aOrbiterA = RotL64((aOrbiterA * 0x78691B2D57CFB631ULL), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 0xD7ACB2D63DA1253CULL) + aOUSaltB[((aIndex + 66U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 0xA9EF102F8DA566FDULL;
            aOrbiterI = RotL64((aOrbiterI * 0x190E85C8D3BEEC95ULL), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 0xC22E56F04F5F8877ULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 0x6E67E9F76DC7AB7BULL;
            aOrbiterG = RotL64((aOrbiterG * 0xAF9493F514121D1BULL), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 0x7DD6745ACB18BDFBULL;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 0x5311CEA3435A5F88ULL;
            aOrbiterH = RotL64((aOrbiterH * 0xA5298425E2EA7179ULL), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 60U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + RotL64(aOrbiterD, 28U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterC, 29U)) + aWUSaltA[((aIndex + 78U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 18U) + RotL64(aOrbiterJ, 37U)) + aOrbiterG) + aWUSaltD[(((511U - aIndex) + 107U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 18U)) + aOrbiterJ) + aWUSaltB[(((511U - aIndex) + 89U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterF, 57U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterK, 13U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterK, 11U)) + aOrbiterE) + RotL64(aCarry, 39U));
            aWandererG = aWandererG + ((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 5U)) + aOrbiterH);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterA, 52U)) + aWUSaltE[(((511U - aIndex) + 387U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 44U) + aOrbiterF) + RotL64(aOrbiterD, 35U)) + aWUSaltG[(((511U - aIndex) + 303U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterE, 23U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 27U)) + aOrbiterI) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 54U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aCrystalLaneC[aIndex] = aIngress;
        }
    
        //
        // File: nexus_13/loop_000708.bin
        //
        // Head:        [7, 8, 1, 10, 4, 2, 0, 3, 9, 5, 6]
        // Tail A:      [8, 9, 4, 0, 2, 7, 1, 10, 6, 3, 5]
        // Tail B:      [1, 6, 7, 10, 8, 9, 3, 4, 5, 0, 2]
        //
        // Heart:       [{ 0, 1, 2 },
        //               { 3, 4, 5 },
        //               { 6, 2, 7 },
        //               { 8, 9, 4 },
        //               { 10, 7, 1 },
        //               { 9, 5, 0 },
        //               { 2, 10, 3 },
        //               { 4, 0, 6 },
        //               { 7, 3, 8 },
        //               { 1, 6, 9 },
        //               { 5, 8, 10 }]
        //
        // Orbiters:    [CBIKDHEFJAG]
        // Wanderers:   [BECJKGHADFI]
        //
        // Ingress:     aCrystalLaneC (-->), aCrystalLaneA (-->), aAetherLaneB (<-?->)
        //
        // Cross:       aCrystalLaneB (<--), aAetherLaneA (<--), pCrossLaneC (<-?->)
        //
        // Destination: aCrystalLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aCrystalLaneC[((aIndex + 25057U)) & S_BLOCK1], 44U) ^ RotL64(aCrystalLaneA[((aIndex + 27571U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aAetherLaneB[((aIndex + 26671U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB((aIngress ^ aTwistDomainWordIngress));
            //
            aCross = (RotL64(aCrystalLaneB[((S_BLOCK1 - aIndex + 30824U)) & S_BLOCK1], 20U) ^ RotL64(aAetherLaneA[((S_BLOCK1 - aIndex + 30199U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(pCrossLaneC[((aIndex + 28152U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA((aCross ^ aTwistDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 36U) + RotL64(aCarry, 11U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aTwistDomainWordScatter));
            //
            aOrbiterC = ((aWandererA + RotL64(aCross, 5U)) + 0x40638CECC46B63F8ULL) + aOASaltF[(((511U - aIndex) + 316U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aIngress, 47U)) + 0xDE3931A62D8B1240ULL;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 3U)) + 0x08C22434DACD3281ULL) + aOASaltH[(((511U - aIndex) + 327U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 60U)) + RotL64(aCarry, 13U)) + 0x0D75260C8B4D1BA4ULL;
            aOrbiterD = (aWandererK + RotL64(aCross, 19U)) + 0x7A17642CC1015A3CULL;
            aOrbiterH = (aWandererC + RotL64(aIngress, 21U)) + 0x95BE7B17EB58AA92ULL;
            aOrbiterE = (aWandererB + RotL64(aScatter, 53U)) + 0xBF4C8A0676508C60ULL;
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 29U)) + 0x562A56242ABF22ECULL) + aOASaltE[(((511U - aIndex) + 63U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aCross, 12U)) + 0x7088E34D38C7D9F7ULL) + aOASaltA[((aIndex + 125U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aIngress, 57U)) + 0x2F27A938538A5C25ULL;
            aOrbiterG = (((aWandererH + RotL64(aScatter, 27U)) + RotL64(aCarry, 19U)) + 0xE4D2A8DDD2553AF3ULL) + aOASaltG[(((511U - aIndex) + 437U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 0xC9BCB885923759AAULL;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 0x90FB361F9E50D46DULL;
            aOrbiterI = RotL64((aOrbiterI * 0x6D51384F3B79A7F3ULL), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 0xC92850E685CD1960ULL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 0x548EB3738A04ED85ULL) ^ aOUSaltB[(((511U - aIndex) + 300U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 0x66C65F85D27059A1ULL), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 0x75FAAB7207AF770CULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 0xF68A12E6DF4D9442ULL;
            aOrbiterF = RotL64((aOrbiterF * 0x97F7F0A6863DA205ULL), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 0x7C3DF7C9AE4E4FA2ULL) + aOUSaltH[(((511U - aIndex) + 431U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 0x977499DEC8A04BEBULL;
            aOrbiterD = RotL64((aOrbiterD * 0xE32D85CA88AD112BULL), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 0x5338D52628A61A5DULL;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 0xFAC7D34FD480D0DBULL;
            aOrbiterB = RotL64((aOrbiterB * 0xA17CF827E8C812E9ULL), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 0x28E0EC2F86D0F08AULL) + aOUSaltE[((aIndex + 1U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 0x8DC2AF90B475EFE1ULL) ^ aOUSaltG[(((511U - aIndex) + 221U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 0x35C94379493A48DFULL), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 0x0EF4CDC2F5A5B5B5ULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 0x8D772134A9E380CFULL;
            aOrbiterK = RotL64((aOrbiterK * 0x4D71BE1261DBF941ULL), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 0xB1D0DF48659197D0ULL;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 0xADC91E3502D11CF6ULL;
            aOrbiterE = RotL64((aOrbiterE * 0xF8214B78736D2AB5ULL), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 0xDF3722763EAF7550ULL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 0x484699E7663DBB5FULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0xA81E8256429F3BC3ULL), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 0xCE92489AC4B2E3F5ULL) + aOUSaltA[((aIndex + 475U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 0xCFE550D3E48FA6BAULL;
            aOrbiterA = RotL64((aOrbiterA * 0xBE8B50B050DCBA0BULL), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 0x91C5E63DDF0FC298ULL;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 0x5DFBD6C3763FB613ULL) ^ aOUSaltF[((aIndex + 260U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 0x42BF0E36891E1AC1ULL), 11U);
            //
            aIngress = RotL64(aOrbiterK, 12U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 6U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 40U)) + aOrbiterB) + aWUSaltC[((aIndex + 483U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 37U) + RotL64(aOrbiterA, 21U)) + aOrbiterE) + aWUSaltG[((aIndex + 336U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 30U) + RotL64(aOrbiterD, 5U)) + aOrbiterF) + RotL64(aCarry, 3U)) + aWUSaltH[((aIndex + 360U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterG, 57U)) + aWUSaltF[(((511U - aIndex) + 302U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterJ, 27U));
            aWandererG = aWandererG + ((RotL64(aCross, 57U) + RotL64(aOrbiterF, 51U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 35U)) + aOrbiterK);
            aWandererA = aWandererA + ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterD, 10U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 13U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererF = aWandererF + (((RotL64(aCross, 10U) + RotL64(aOrbiterK, 23U)) + aOrbiterC) + aWUSaltE[((aIndex + 373U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 47U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (RotL64(aWandererF, 50U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + RotL64(aWandererK, 20U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aCrystalLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    }
    // GTwistRunTwist_C twist_loop_c (end)
    WRITE_OUT_MUTABLE_PARAMS;
}
