
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
        // File: nexus_11/loop_000368.bin
        //
        // Head:        [6, 2, 5, 0, 1, 7, 8, 3, 10, 9, 4]
        // Tail A:      [0, 7, 4, 5, 3, 6, 8, 1, 9, 10, 2]
        // Tail B:      [4, 2, 9, 10, 6, 5, 0, 8, 3, 7, 1]
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
        // Orbiters:    [IKEAHCFDJBG]
        // Wanderers:   [FEBJDICHKGA]
        //
        // Ingress:     aSource (-->), aKeyRowReadA (-->)
        //
        // Cross:       aKeyRowReadB (<--), pCrossLaneC (<-?->)
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
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 1843U)) & W_KEY1], 60U) ^ RotL64(pCrossLaneC[((S_BLOCK1 - aIndex + 7222U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB((aCross ^ aTwistDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 19U)) + (RotL64(aCross, 51U) ^ RotL64(aIngress, 36U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aTwistDomainWordScatter));
            //
            aOrbiterI = (aWandererC + RotL64(aIngress, 53U)) + 0x3A1F29C79161E339ULL;
            aOrbiterK = (aWandererB + RotL64(aScatter, 43U)) + 0x103CCBB5A50D5AD5ULL;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 11U)) + 0x0C37854637109E81ULL) + aOASaltB[(((511U - aIndex) + 279U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aCross, 37U)) + RotL64(aCarry, 57U)) + 0xBFB90645C2D51B8CULL;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 46U)) + 0x76994FA0E3BEE9A0ULL) + aOASaltA[(((511U - aIndex) + 305U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aScatter, 3U)) + 0x56674D2939887E15ULL) + aOASaltD[((aIndex + 422U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aPrevious, 51U)) + 0xF3789985648A5C9BULL;
            aOrbiterD = (((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 23U)) + 0x8A763945C920EF86ULL) + aOASaltE[(((511U - aIndex) + 482U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aIngress, 27U)) + 0x88DB36068336F535ULL;
            aOrbiterB = (aWandererG + RotL64(aScatter, 60U)) + 0x46555FA7D6FE8438ULL;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 41U)) + 0x818693DC1DD41519ULL;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 0x7B0799717E7EF985ULL;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 0xBA657B75A6921799ULL;
            aOrbiterE = RotL64((aOrbiterE * 0x0B76C2E58FCD2191ULL), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 0x0CCFA6CBC407B9B9ULL) + aOUSaltD[((aIndex + 427U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 0x5C7E2B688F7B40F6ULL;
            aOrbiterC = RotL64((aOrbiterC * 0xCFB42D85A7750A69ULL), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 0xA1DDBD43DD1F64C8ULL) + aOUSaltG[(((511U - aIndex) + 293U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 0x606ED508AF5E96C1ULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0x0E04A3647DA1BE4BULL), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 0x7906539D6E1884B7ULL;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 0x4786F6CD9C55B7CFULL;
            aOrbiterI = RotL64((aOrbiterI * 0x1589EC0FAE2EEDF5ULL), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 0x883387AD05C8442CULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 0x30E979EB75F10328ULL;
            aOrbiterK = RotL64((aOrbiterK * 0xABCBA11868C30A59ULL), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 0x6570A0ABBBF3CDE3ULL) + aOUSaltH[((aIndex + 196U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 0x9171C109E5C9EDF0ULL;
            aOrbiterH = RotL64((aOrbiterH * 0x2D2B924E4E52EF8FULL), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 0xAAF5BF7AC05445A1ULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 0x8E85E16B598596F8ULL;
            aOrbiterA = RotL64((aOrbiterA * 0x276B7548FD2AF3A9ULL), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 0x21C784726440C57AULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 0xA1B7F672C7724977ULL;
            aOrbiterF = RotL64((aOrbiterF * 0xCAA98812D5863BE1ULL), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 0xB48CF2269223882DULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 0x862E66534A8791F3ULL;
            aOrbiterD = RotL64((aOrbiterD * 0x04A5DF4D52E1538FULL), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 0x3D18857B08090F65ULL;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 0xBF216180B6758833ULL;
            aOrbiterB = RotL64((aOrbiterB * 0xE32940C4CF84554DULL), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 0xE0FBEC62C7BB0668ULL;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 0xFB4AA032B030E789ULL) ^ aOUSaltC[(((511U - aIndex) + 139U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 0x94B6E37CE627559FULL), 43U);
            //
            aIngress = RotL64(aOrbiterG, 37U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 46U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterH, 37U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterE, 41U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterH, 23U)) + aOrbiterB) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterC, 39U)) + aOrbiterG) + aWUSaltC[(((511U - aIndex) + 80U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 46U)) + aOrbiterF) + aWUSaltG[((aIndex + 67U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterC, 29U)) + aWUSaltB[(((511U - aIndex) + 37U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 27U)) + aOrbiterI);
            aWandererH = aWandererH ^ ((RotL64(aCross, 48U) + aOrbiterK) + RotL64(aOrbiterJ, 43U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 27U)) + aWUSaltE[(((511U - aIndex) + 215U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterD, 5U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 18U)) + aOrbiterK);
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
        // File: nexus_10/loop_000102.bin
        //
        // Head:        [6, 10, 9, 3, 8, 2, 4, 0, 1, 5, 7]
        // Tail A:      [10, 5, 2, 1, 0, 3, 7, 4, 9, 6, 8]
        // Tail B:      [1, 9, 10, 5, 8, 6, 4, 2, 3, 0, 7]
        //
        // Heart:       [{ 0, 1, 2 },
        //               { 3, 4, 5 },
        //               { 6, 7, 8 },
        //               { 9, 10, 4 },
        //               { 7, 2, 1 },
        //               { 5, 8, 0 },
        //               { 1, 9, 3 },
        //               { 4, 5, 6 },
        //               { 10, 0, 7 },
        //               { 2, 6, 9 },
        //               { 8, 3, 10 }]
        //
        // Orbiters:    [GBFHKEACIJD]
        // Wanderers:   [HADFBIGEKCJ]
        //
        // Ingress:     aAetherLaneA (-->), aSource (-->), aKeyRowReadB (-->)
        //
        // Cross:       aKeyRowReadA (<--), pCrossLaneD (<-?->)
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
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 10745U)) & W_KEY1], 47U) ^ RotL64(pCrossLaneD[((S_BLOCK1 - aIndex + 10076U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseC((aCross ^ aTwistDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCross, 4U)) + (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aTwistDomainWordScatter));
            //
            aOrbiterG = ((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 51U)) + 0x3227DDE4689F1655ULL;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 10U)) + 0xF06515E215CE2F4EULL;
            aOrbiterF = (aWandererC + RotL64(aCross, 29U)) + 0xCA48D831C965111FULL;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 19U)) + 0x2DE0B6A56B9D05D7ULL) + aOASaltG[((aIndex + 89U)) & S_SALT1];
            aOrbiterK = (((aWandererK + RotL64(aScatter, 23U)) + RotL64(aCarry, 47U)) + 0x5F9412836A547EFEULL) + aOASaltH[((aIndex + 333U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aPrevious, 53U)) + 0x3094B861118D6817ULL;
            aOrbiterA = (aWandererB + RotL64(aCross, 35U)) + 0x050B65F124CCEFE2ULL;
            aOrbiterC = (aWandererH + RotL64(aIngress, 13U)) + 0xB2F652E273F8A0DBULL;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 21U)) + 0x168EEA0A66520438ULL;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 43U)) + 0x6CA7769E3306E741ULL;
            aOrbiterD = ((aWandererE + RotL64(aCross, 6U)) + 0x480852B736B960F3ULL) + aOASaltC[(((511U - aIndex) + 401U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 0xA73567E6F0306117ULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 0xFD3278875BE868C8ULL;
            aOrbiterF = RotL64((aOrbiterF * 0x8F1D62672BED496DULL), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 0xEF8898423C0CAD12ULL) + aOUSaltE[((aIndex + 283U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 0x455AE250A1C85346ULL) ^ aOUSaltD[(((511U - aIndex) + 250U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 0x824ADEBDAD3F89F9ULL), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 0xFB05CEFBA2AE1CCEULL) + aOUSaltH[((aIndex + 145U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 0x8534A9E8B4585A09ULL) ^ aOUSaltC[(((511U - aIndex) + 386U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 0x2C568E34068AC627ULL), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 0x60F552B4E6DDCE60ULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 0xB8CC5834DABF6D9AULL;
            aOrbiterK = RotL64((aOrbiterK * 0xE2ADAC66C96DDE47ULL), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 0x44B2EABCE572084DULL;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 0xDC26F1EEC30AF616ULL) ^ aOUSaltB[((aIndex + 78U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 0x43F0CBB2E793A8E1ULL), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 0xD09B583F7370169CULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 0xCC25CE611C1D843BULL;
            aOrbiterG = RotL64((aOrbiterG * 0xFDB269E8C8BE2FD5ULL), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 0x5CA9493EF1973EB0ULL) + aOUSaltG[((aIndex + 322U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 0x38E23ACEE59C1678ULL;
            aOrbiterH = RotL64((aOrbiterH * 0x41D507BBA73C963FULL), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 0xC8F0567464C11A4EULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 0xC175F5D76E5640E6ULL;
            aOrbiterA = RotL64((aOrbiterA * 0x31D5250FE4681195ULL), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 0xFB204E7D528B7054ULL;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 0x4DA78AF89EBC4A4BULL;
            aOrbiterC = RotL64((aOrbiterC * 0x3C64D5D25B9D0615ULL), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 0x2A45BF34DF652B47ULL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 0x4151010B031CB068ULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0xD3AB91AB589165C1ULL), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 0x288E62C36DA599F9ULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 0x1C3D6111AB51CC6AULL;
            aOrbiterD = RotL64((aOrbiterD * 0xF04553AC7358D19BULL), 39U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 19U);
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 10U));
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 6U) + RotL64(aOrbiterD, 5U)) + aOrbiterB) + RotL64(aCarry, 3U));
            aWandererA = aWandererA + ((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterJ, 56U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 53U)) + aOrbiterD) + aWUSaltD[(((511U - aIndex) + 357U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 51U) + RotL64(aOrbiterB, 39U)) + aOrbiterE);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 11U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 51U)) + aOrbiterK) + aWUSaltF[((aIndex + 156U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 48U) + aOrbiterK) + RotL64(aOrbiterF, 13U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 21U)) + aOrbiterH);
            aWandererC = aWandererC + ((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterG, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 60U)) + aOrbiterC) + aWUSaltA[(((511U - aIndex) + 363U)) & S_SALT1]);
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
        // File: nexus_07/loop_000413.bin
        //
        // Head:        [3, 6, 9, 4, 2, 7, 10, 5, 0, 1, 8]
        // Tail A:      [0, 3, 6, 4, 10, 9, 7, 1, 2, 8, 5]
        // Tail B:      [7, 0, 5, 6, 1, 4, 8, 2, 9, 3, 10]
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
        // Orbiters:    [FKGAIBEHDCJ]
        // Wanderers:   [KDCJHGAIFEB]
        //
        // Ingress:     aAetherLaneB (-->), aKeyRowReadA (-->), pCrossLaneA (<-?->)
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
            aIngress ^= RotL64(pCrossLaneA[((aIndex + 16680U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB((aIngress ^ aTwistDomainWordIngress));
            //
            aCross = (RotL64(aAetherLaneA[((S_BLOCK1 - aIndex + 18094U)) & S_BLOCK1], 20U) ^ RotL64(aSource[((S_BLOCK1 - aIndex + 23423U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aKeyRowReadB[(((2047U - aIndex) + 21975U)) & W_KEY1], 39U);
            aCross = TwistMix64::DiffuseB((aCross ^ aTwistDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 40U)) ^ (RotL64(aPrevious, 53U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aTwistDomainWordScatter));
            //
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 36U)) + 0x1CD341559E984EA6ULL;
            aOrbiterK = ((aWandererA + RotL64(aCross, 21U)) + RotL64(aCarry, 51U)) + 0x501C7CF78325CED2ULL;
            aOrbiterG = (aWandererE + RotL64(aIngress, 27U)) + 0xED4233ACB3F5565EULL;
            aOrbiterA = (aWandererH + RotL64(aScatter, 57U)) + 0x8B017A41A5E31282ULL;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 34U)) + 0x788F2664EEC69B35ULL) + aOASaltB[(((511U - aIndex) + 237U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 3U)) + 0xBEA808FEA930151BULL;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 51U)) + 0xB02B15CD259A2C0CULL) + aOASaltA[((aIndex + 75U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aScatter, 19U)) + 0x8E5666AE0B79D972ULL;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 47U)) + 0x30E3E4523549886CULL) + aOASaltC[(((511U - aIndex) + 408U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aCross, 23U)) + RotL64(aCarry, 13U)) + 0x77314BD0B557C29FULL;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 43U)) + 0xEBEE58FE104D9CF6ULL;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 0x2A96CA96FAD408D5ULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 0xE81BDF232BF5A579ULL;
            aOrbiterG = RotL64((aOrbiterG * 0xC6739E0F1A25E3A9ULL), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 0x61E79FDD5A5473BCULL) + aOUSaltD[((aIndex + 496U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 0xE1E8B10D6F09B8C8ULL;
            aOrbiterB = RotL64((aOrbiterB * 0x6A217064F46302EBULL), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 0x418FC665A33EF4D6ULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 0xD1F45B7B28223ECDULL;
            aOrbiterD = RotL64((aOrbiterD * 0x2430A623116FB38BULL), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 0xBAC99D3557ECEA91ULL;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 0x6B7E11B4BC9AF759ULL) ^ aOUSaltC[((aIndex + 130U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 0x77D714DB268C5AC3ULL), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 0x0E8F7A5FA41D37B1ULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 0x68D577B58726D8D2ULL;
            aOrbiterF = RotL64((aOrbiterF * 0x60DADE8B2363644FULL), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 0x8BC43E17F3D8DE59ULL;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 0xF10BE4FB25362A4EULL;
            aOrbiterI = RotL64((aOrbiterI * 0x31288C31DDFD2E75ULL), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 0xB14797B68A5A43ECULL;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 0x41606A1DC8111F44ULL) ^ aOUSaltG[(((511U - aIndex) + 163U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 0x2BB0439C094FA721ULL), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 0x4DD7A8ECB8FB21D8ULL;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 0x16E6B461F09013C3ULL) ^ aOUSaltF[((aIndex + 292U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 0x32A63E88B793C5BBULL), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 0xD8ED7EE290A07B6AULL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 0x92F1111B610BC544ULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0xC1E43DDFD333353DULL), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 0x6F64D729A8ED77DEULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 0xC0E8EEB12A07B4B3ULL;
            aOrbiterK = RotL64((aOrbiterK * 0x8BE7721B2E2DA545ULL), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 0x9278682F63F86392ULL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 0x86CE3F4AEBC3D175ULL) ^ aOUSaltA[((aIndex + 343U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 0x797DCA328DF32253ULL), 51U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 41U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 60U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterH, 19U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 5U)) + aOrbiterF);
            aWandererC = aWandererC + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 41U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 27U) + RotL64(aOrbiterI, 30U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aWUSaltH[((aIndex + 359U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 22U) + RotL64(aOrbiterJ, 39U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterI, 43U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 35U)) + aOrbiterD) + aWUSaltB[(((511U - aIndex) + 290U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterG, 23U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterC, 58U)) + RotL64(aCarry, 41U)) + aWUSaltE[((aIndex + 173U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 21U)) + aOrbiterA) + aWUSaltG[(((511U - aIndex) + 447U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 54U) + RotL64(aOrbiterB, 47U)) + aOrbiterJ);
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
        // File: nexus_01/loop_000513.bin
        //
        // Head:        [4, 0, 7, 10, 5, 2, 8, 9, 1, 3, 6]
        // Tail A:      [7, 3, 8, 2, 6, 0, 5, 1, 9, 4, 10]
        // Tail B:      [3, 0, 7, 4, 10, 6, 8, 5, 2, 9, 1]
        //
        // Heart:       [{ 0, 1, 2 },
        //               { 3, 4, 5 },
        //               { 6, 2, 7 },
        //               { 8, 3, 9 },
        //               { 5, 7, 10 },
        //               { 4, 0, 1 },
        //               { 9, 10, 6 },
        //               { 2, 5, 3 },
        //               { 1, 6, 8 },
        //               { 7, 9, 0 },
        //               { 10, 8, 4 }]
        //
        // Orbiters:    [FKDCGIEAJHB]
        // Wanderers:   [KADFJBCIEHG]
        //
        // Ingress:     aAetherLaneC (-->), aAetherLaneA (-->), aKeyRowReadB (-->), pCrossLaneB (<-?->)
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
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 24994U)) & W_KEY1], 5U) ^ RotL64(pCrossLaneB[((aIndex + 31912U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aTwistDomainWordIngress));
            //
            aCross = (RotL64(aAetherLaneB[((S_BLOCK1 - aIndex + 32443U)) & S_BLOCK1], 26U) ^ RotL64(aSource[((S_BLOCK1 - aIndex + 30590U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aKeyRowReadA[(((2047U - aIndex) + 27627U)) & W_KEY1], 47U);
            aCross = TwistMix64::DiffuseA((aCross ^ aTwistDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 52U) + RotL64(aCarry, 23U)) + (RotL64(aIngress, 3U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aTwistDomainWordScatter));
            //
            aOrbiterF = ((aWandererJ + RotL64(aCross, 41U)) + 0x8A5D7D10391FC2A8ULL) + aOASaltH[(((511U - aIndex) + 168U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aIngress, 23U)) + 0x3C3B0690889ADCC1ULL) + aOASaltA[(((511U - aIndex) + 356U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aScatter, 58U)) + RotL64(aCarry, 13U)) + 0x5112B2C62D7C98C0ULL;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 29U)) + 0x504EFB756EADCE0DULL;
            aOrbiterG = (aWandererB + RotL64(aCross, 3U)) + 0xCE4DF991A0AB0FBEULL;
            aOrbiterI = (aWandererD + RotL64(aIngress, 27U)) + 0x64B337D8C4592B98ULL;
            aOrbiterE = (((aWandererE + RotL64(aScatter, 18U)) + RotL64(aCarry, 29U)) + 0xCB95C65B439A4E91ULL) + aOASaltD[(((511U - aIndex) + 468U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aPrevious, 47U)) + 0x9014CD5CAB8214FEULL;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 21U)) + 0xA7B97A2FDA114850ULL) + aOASaltG[((aIndex + 301U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aIngress, 11U)) + 0x92459FD2F0DE8C24ULL) + aOASaltC[(((511U - aIndex) + 1U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 51U)) + 0x8C25F94F8CAF8BDDULL;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 0x982AD20A16501223ULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 0x1ADEAA7BD296D78AULL;
            aOrbiterD = RotL64((aOrbiterD * 0xFB772A2381A5A165ULL), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 0x38092AB5E9E26AA9ULL;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 0x9D75442FA3B19BE5ULL;
            aOrbiterI = RotL64((aOrbiterI * 0xE2249DFAEEC955E1ULL), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 0xB2CA4393594BBF8AULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 0xF1F2EF141BD64B5DULL;
            aOrbiterA = RotL64((aOrbiterA * 0x51D2FE3D4C77579DULL), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 0x5F0CCA91C0E8453BULL) + aOUSaltC[((aIndex + 454U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 0xDBC3EE6D231BF220ULL;
            aOrbiterH = RotL64((aOrbiterH * 0x7F28D6A686D65813ULL), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 0x47908F9C25A773B9ULL;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 0x9E87F64E48259A33ULL) ^ aOUSaltA[((aIndex + 171U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 0x03D8EE79A1FC66B5ULL), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 0xC1546FAF07C539BDULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 0x5BAAE53D20384736ULL;
            aOrbiterK = RotL64((aOrbiterK * 0x3D37D682E04592BFULL), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 0x1C537BBA7A394444ULL;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 0x8A0D3F2B783376BFULL;
            aOrbiterE = RotL64((aOrbiterE * 0x8643537969B55959ULL), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 0xAF0C7AFCE13936BDULL) + aOUSaltG[(((511U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 0x5DF14D9CBE123264ULL) ^ aOUSaltH[((aIndex + 322U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 0x2C8B02C06F6A621FULL), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 0x397C6C7F70B287CCULL;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 0xDCE3E50B2132E26FULL) ^ aOUSaltE[(((511U - aIndex) + 316U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 0xC9D4CD9021351CC1ULL), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 0x8D0F122F75F82CA9ULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 0xE68A45D120E0D0FEULL;
            aOrbiterF = RotL64((aOrbiterF * 0x167CE57D075F3B9BULL), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 0x222D7AC449980BB6ULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 0x4F63088607EE325BULL;
            aOrbiterG = RotL64((aOrbiterG * 0x811CDE1F89766225ULL), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 50U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 58U) + RotL64(aOrbiterA, 11U)) + aOrbiterC) + RotL64(aCarry, 47U)) + aWUSaltB[((aIndex + 177U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 53U)) + aOrbiterF);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 26U)) + aOrbiterA) + aWUSaltG[((aIndex + 79U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 3U) + RotL64(aOrbiterD, 43U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 5U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterE, 47U)) + aWUSaltE[((aIndex + 453U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 19U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererI = aWandererI + (((RotL64(aCross, 14U) + aOrbiterK) + RotL64(aOrbiterI, 50U)) + aWUSaltF[(((511U - aIndex) + 393U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 57U)) + aOrbiterD);
            aWandererH = aWandererH + ((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 23U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 13U)) + aOrbiterK);
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
        // File: nexus_08/loop_000563.bin
        //
        // Head:        [2, 7, 3, 9, 8, 5, 4, 1, 10, 6, 0]
        // Tail A:      [2, 1, 6, 10, 5, 4, 0, 9, 8, 7, 3]
        // Tail B:      [4, 6, 3, 1, 10, 8, 5, 7, 0, 2, 9]
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
        // Orbiters:    [BGAJICEDHKF]
        // Wanderers:   [GCEFDKBJAHI]
        //
        // Ingress:     aAetherLaneD (-->), aAetherLaneB (-->), pCrossLaneC (<-?->)
        //
        // Cross:       aAetherLaneC (<--), aAetherLaneA (<--), pCrossLaneA (<-?->)
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
            aCross ^= RotL64(pCrossLaneA[((S_BLOCK1 - aIndex + 5402U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC((aCross ^ aTwistDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCarry, 57U)) ^ (RotL64(aCross, 44U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aTwistDomainWordScatter));
            //
            aOrbiterB = ((aWandererE + RotL64(aIngress, 12U)) + RotL64(aCarry, 37U)) + 0x167A1FB8C2F063A1ULL;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 37U)) + 0xA3BC7B62AF8FAE89ULL;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 29U)) + 0xD8457517779713D3ULL;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 53U)) + 0x2456A59826F6CE32ULL;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 6U)) + 0x7E87336C845ABDB5ULL) + aOASaltB[((aIndex + 256U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aScatter, 27U)) + 0xF62D6C2F7D105316ULL;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 35U)) + 0x9651EE2911F2838DULL;
            aOrbiterD = (((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 0xF11F872362099D75ULL) + aOASaltD[((aIndex + 248U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aIngress, 39U)) + 0xA0388E644B8C32E4ULL) + aOASaltH[(((511U - aIndex) + 191U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aScatter, 3U)) + 0x4856A03E9D333778ULL;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 53U)) + 0xE409F9C5EA9BC6F0ULL;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 0x25859632590B2184ULL) + aOUSaltA[((aIndex + 241U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 0xE79A0F79F2BE8217ULL;
            aOrbiterA = RotL64((aOrbiterA * 0x32DD63D20A5A9E57ULL), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 0xA75D4E995E30A913ULL) + aOUSaltF[(((511U - aIndex) + 177U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 0x7D564F9318F4FC2AULL;
            aOrbiterC = RotL64((aOrbiterC * 0x5D37531B2F5D9649ULL), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 0x9DE1AAAB7B72EDD7ULL;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 0xD08628EB45FA38B2ULL;
            aOrbiterH = RotL64((aOrbiterH * 0x1B76211BC87AA347ULL), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 0x898FD6528BC48DD7ULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 0x44ED22A1CAFE8835ULL;
            aOrbiterK = RotL64((aOrbiterK * 0x6A8C371FCDCC6DFDULL), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 0x0BBEEC2BB3C42368ULL;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 0xCECACC1955B5A8DBULL) ^ aOUSaltE[(((511U - aIndex) + 260U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 0x581FC75162A7975BULL), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 0x4B82F86DDD74546CULL;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 0x38B6DF765B4AF2D8ULL) ^ aOUSaltD[(((511U - aIndex) + 243U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 0x0AE88DEF28958143ULL), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 0x8AAED3CB7014896CULL;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 0x3330A12BD43D20FBULL;
            aOrbiterE = RotL64((aOrbiterE * 0x8E478CBB36E531E3ULL), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 0x43F3EF914717F5DFULL;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 0xCAFCE503B45F6FC9ULL) ^ aOUSaltG[((aIndex + 277U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 0xE40DD3231C213111ULL), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 0xF43F42BCECC8B168ULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 0x7ED27A811A636E60ULL;
            aOrbiterF = RotL64((aOrbiterF * 0xEA5814E775BCBED5ULL), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 0x38EB080B7916CBE6ULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 0xB289B31DD38639EDULL;
            aOrbiterG = RotL64((aOrbiterG * 0x9627A6C5B98E2123ULL), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 0xD39BDF3057DA371CULL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 0x0E43F21715B619D5ULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0x98D45F5DBBD37F6BULL), 23U);
            //
            aIngress = RotL64(aOrbiterK, 27U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 18U));
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterI, 23U)) + aWUSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 14U) + aOrbiterG) + RotL64(aOrbiterE, 13U));
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterJ, 39U)) + aWUSaltA[((aIndex + 36U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD + (((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterF, 27U)) + aWUSaltH[(((511U - aIndex) + 493U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 6U)) + aOrbiterH) + aWUSaltD[(((511U - aIndex) + 273U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 44U) + RotL64(aOrbiterB, 51U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterD, 41U));
            aWandererA = aWandererA + ((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterB, 3U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 29U));
            aWandererI = aWandererI + ((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterK, 44U));
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
        // File: nexus_02/loop_000229.bin
        //
        // Head:        [7, 10, 8, 3, 0, 6, 1, 9, 4, 5, 2]
        // Tail A:      [6, 0, 3, 5, 4, 7, 1, 9, 10, 8, 2]
        // Tail B:      [1, 10, 0, 7, 8, 3, 4, 5, 6, 2, 9]
        //
        // Heart:       [{ 0, 1, 2 },
        //               { 3, 4, 5 },
        //               { 6, 2, 7 },
        //               { 8, 9, 1 },
        //               { 10, 5, 4 },
        //               { 7, 8, 0 },
        //               { 2, 10, 3 },
        //               { 4, 0, 6 },
        //               { 1, 7, 9 },
        //               { 5, 6, 8 },
        //               { 9, 3, 10 }]
        //
        // Orbiters:    [KHAJGFDCIEB]
        // Wanderers:   [JDFBCKEIHAG]
        //
        // Ingress:     aLunarLaneA (-->), aAetherLaneC (-->), pCrossLaneD (<-?->)
        //
        // Cross:       aAetherLaneD (<--), aAetherLaneB (<--), aSource (<-?->)
        //
        // Destination: aLunarLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aLunarLaneA[((aIndex + 16307U)) & S_BLOCK1], 13U) ^ RotL64(aAetherLaneC[((aIndex + 16322U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(pCrossLaneD[((aIndex + 8487U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC((aIngress ^ aTwistDomainWordIngress));
            //
            aCross = (RotL64(aAetherLaneD[((S_BLOCK1 - aIndex + 14409U)) & S_BLOCK1], 13U) ^ RotL64(aAetherLaneB[((S_BLOCK1 - aIndex + 15371U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aSource[((S_BLOCK1 - aIndex + 15805U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseC((aCross ^ aTwistDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aCross, 27U) + RotL64(aPrevious, 14U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aTwistDomainWordScatter));
            //
            aOrbiterK = (aWandererI + RotL64(aScatter, 13U)) + 0x57E45FAE8FE43482ULL;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 21U)) + 0x81C2E18BA2CBBB0DULL;
            aOrbiterA = (aWandererH + RotL64(aCross, 11U)) + 0xC84F2555E1B38431ULL;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 27U)) + 0x6062A3ED01B35EF8ULL;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 4U)) + RotL64(aCarry, 51U)) + 0xD1632C6C15E52739ULL;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 53U)) + 0xAC2CC544BCA8B56EULL;
            aOrbiterD = (aWandererD + RotL64(aCross, 37U)) + 0xAD405BCF2F8F0E50ULL;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 51U)) + 0xDC89EE84B31F394FULL) + aOASaltG[(((511U - aIndex) + 103U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 11U)) + 0xAB533A142CCCECCDULL;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 47U)) + 0x13130105B29FDD83ULL) + aOASaltF[((aIndex + 423U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aCross, 24U)) + 0x9C90764309061DC8ULL) + aOASaltH[(((511U - aIndex) + 6U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 0x42C154BB7A7C85FCULL;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 0x6AD77ED2F497C628ULL) ^ aOUSaltH[((aIndex + 261U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 0x53EC6F87EC24C607ULL), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 0xF84950B264A4ADE9ULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 0x314E905518DEAC07ULL;
            aOrbiterF = RotL64((aOrbiterF * 0xE8EC9892544BDF03ULL), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 0x326E2E0451B6AF25ULL;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 0xED7DAAEFBDE475DCULL) ^ aOUSaltG[(((511U - aIndex) + 485U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 0x54F4A1AB1069C865ULL), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 0x756408F6710E7A40ULL;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 0x65F9DFAE513C2F22ULL;
            aOrbiterH = RotL64((aOrbiterH * 0x2E71032D9AD0DD53ULL), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 0x8953DEF187EF1610ULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 0x18A7E7E2BE96853FULL;
            aOrbiterG = RotL64((aOrbiterG * 0x5347C4A8A5D637B1ULL), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 0xE4EB86ACEFD4478DULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 0xA7B0B9E9DEC7EAEBULL;
            aOrbiterK = RotL64((aOrbiterK * 0xCEEBAD0DD36CC949ULL), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 0x5066A9E6A07C42A5ULL;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 0x0CC7582FA75C350CULL) ^ aOUSaltB[((aIndex + 391U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 0x9D9926286170B301ULL), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 0x5C30924FD9D52214ULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 0x0DB78646AFAEA9CBULL;
            aOrbiterD = RotL64((aOrbiterD * 0x6A3ED2632F40DF61ULL), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 0xB175E91D8AFE4BEFULL;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 0x8A1EAF7E535FBA2BULL;
            aOrbiterE = RotL64((aOrbiterE * 0x58AA79719E4F1E4BULL), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 0x79114096095DF656ULL;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 0x7BFBD25956B5418EULL) ^ aOUSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 0x1B2FEA907D6902DFULL), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 0x37D2233ABF4D94E1ULL;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 0x16B204EABCA533CFULL;
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
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 26U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aPrevious, 38U) + aOrbiterK) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterK, 3U));
            aWandererB = aWandererB + ((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterC, 21U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterI, 23U)) + aWUSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 46U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((((RotL64(aCross, 46U) + RotL64(aOrbiterH, 51U)) + aOrbiterG) + RotL64(aCarry, 29U)) + aWUSaltA[(((511U - aIndex) + 115U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterF, 57U)) + aWUSaltD[(((511U - aIndex) + 124U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 11U)) + aOrbiterD) + aWUSaltE[((aIndex + 198U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterA, 41U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterE, 43U));
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
        // File: nexus_04/loop_000429.bin
        //
        // Head:        [2, 5, 8, 1, 10, 0, 4, 6, 9, 3, 7]
        // Tail A:      [10, 4, 1, 2, 6, 3, 9, 7, 8, 5, 0]
        // Tail B:      [3, 10, 7, 1, 8, 6, 5, 2, 0, 4, 9]
        //
        // Heart:       [{ 0, 1, 2 },
        //               { 3, 4, 5 },
        //               { 6, 2, 7 },
        //               { 8, 9, 10 },
        //               { 5, 6, 1 },
        //               { 10, 7, 0 },
        //               { 1, 3, 4 },
        //               { 2, 5, 9 },
        //               { 4, 0, 8 },
        //               { 9, 10, 6 },
        //               { 7, 8, 3 }]
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
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 19U)) + 0x5294A3AF2D4D9F47ULL;
            aOrbiterG = (aWandererK + RotL64(aCross, 11U)) + 0x0ED1B57B7695233EULL;
            aOrbiterE = (((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 53U)) + 0x2640E998BB5825A8ULL) + aOASaltG[((aIndex + 62U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aScatter, 26U)) + 0x732EC6478D9F21AAULL) + aOASaltA[(((511U - aIndex) + 39U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aPrevious, 29U)) + 0xD25454897E9A546FULL;
            aOrbiterC = (((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 47U)) + 0x08587AF9DEA9507BULL) + aOASaltF[((aIndex + 135U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aIngress, 39U)) + 0xDB86DBFA6BC6E7D6ULL;
            aOrbiterH = (aWandererI + RotL64(aScatter, 47U)) + 0x04C9670FB146602DULL;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 41U)) + 0x6898FDBC69273B09ULL;
            aOrbiterD = ((aWandererE + RotL64(aCross, 52U)) + RotL64(aCarry, 23U)) + 0x54720D63A89F9707ULL;
            aOrbiterB = (aWandererA + RotL64(aIngress, 57U)) + 0xB4DF78C30E0927F2ULL;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 0x4B36A28561CDAC81ULL;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 0x51207308452699B9ULL;
            aOrbiterE = RotL64((aOrbiterE * 0xA4A75152CB2ED03BULL), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 0x59DE8A12997CE63FULL;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 0x3754D60BDF663BF4ULL;
            aOrbiterC = RotL64((aOrbiterC * 0x7CB1095CB626745DULL), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 0xAA6BC36381FB6994ULL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 0x427B520CBB70F060ULL) ^ aOUSaltH[(((511U - aIndex) + 501U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 0xEE550DB83015698FULL), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 0x1ED418AE98A13F8FULL) + aOUSaltF[(((511U - aIndex) + 433U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 0x16496E5E8B1433E6ULL;
            aOrbiterB = RotL64((aOrbiterB * 0xC3BB9A54479BD911ULL), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 0xCF3596926F87C498ULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 0xC981AA9A5615FD38ULL;
            aOrbiterG = RotL64((aOrbiterG * 0x29FCBD6D13024DA5ULL), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 0xCDA88232B7EBD357ULL) + aOUSaltC[((aIndex + 33U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 0x1D2F0F5AE881AA83ULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0xE6D725E0C079DA05ULL), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 0x37CE3DE185B2D75CULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 0x3F8543845BCECA52ULL;
            aOrbiterK = RotL64((aOrbiterK * 0xE74D43E4A25EBAF5ULL), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 0x5B435FD98F7CBA0AULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 0xC16C3EF7F153EFD9ULL;
            aOrbiterD = RotL64((aOrbiterD * 0x8BA1DB2137809B3DULL), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 0x220D9E65E53E8DF0ULL;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 0x96490C9BFB11F3E9ULL;
            aOrbiterI = RotL64((aOrbiterI * 0xB65B9A7CAB5DDD83ULL), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 0xB60924998AF60689ULL) + aOUSaltA[((aIndex + 417U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 0x361146A48A44C629ULL;
            aOrbiterF = RotL64((aOrbiterF * 0xD28834F3D93EED05ULL), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 0xAF365F97109FA6D0ULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 0x8E4E0B1F41F6EF4FULL;
            aOrbiterA = RotL64((aOrbiterA * 0x0123F4FED23C4131ULL), 11U);
            //
            aIngress = RotL64(aOrbiterF, 5U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 10U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterA, 23U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 54U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterH, 41U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterG, 39U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 53U)) + aWUSaltH[(((511U - aIndex) + 469U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 37U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aCross, 44U) + RotL64(aOrbiterD, 3U)) + aOrbiterC) + aWUSaltD[(((511U - aIndex) + 337U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterE, 35U));
            aWandererB = aWandererB + ((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterJ, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 57U)) + aOrbiterK) + RotL64(aCarry, 27U));
            aWandererD = aWandererD + (((RotL64(aCross, 60U) + aOrbiterJ) + RotL64(aOrbiterD, 6U)) + aWUSaltF[(((511U - aIndex) + 136U)) & S_SALT1]);
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
        // File: nexus_03/loop_000269.bin
        //
        // Head:        [10, 6, 0, 1, 8, 4, 5, 9, 7, 2, 3]
        // Tail A:      [5, 8, 0, 9, 7, 3, 10, 4, 2, 1, 6]
        // Tail B:      [9, 6, 5, 4, 3, 8, 0, 1, 7, 2, 10]
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
            aOrbiterG = (aWandererG + RotL64(aCross, 24U)) + 0x5CB6DA63AE0CC04AULL;
            aOrbiterB = (aWandererD + RotL64(aIngress, 27U)) + 0xF8558B67D6264C68ULL;
            aOrbiterH = (aWandererK + RotL64(aScatter, 21U)) + 0x86BBA32BE08E2AD9ULL;
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 37U)) + RotL64(aCarry, 39U)) + 0x5019BF4D32176653ULL) + aOASaltG[(((511U - aIndex) + 249U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aCross, 48U)) + 0x0EC19D39069DF992ULL;
            aOrbiterI = (aWandererF + RotL64(aIngress, 13U)) + 0xA046746D85C36FB8ULL;
            aOrbiterE = (((aWandererE + RotL64(aScatter, 35U)) + RotL64(aCarry, 27U)) + 0xD4C2B7D98582CC48ULL) + aOASaltB[((aIndex + 371U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aPrevious, 51U)) + 0x13E9FBBD75962D6BULL;
            aOrbiterC = (aWandererC + RotL64(aCross, 57U)) + 0xAF7A25492FB53578ULL;
            aOrbiterF = (aWandererH + RotL64(aIngress, 53U)) + 0xF03BAC51074AB71AULL;
            aOrbiterA = (((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 47U)) + 0x69708D9E770CD80CULL) + aOASaltA[((aIndex + 1U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 0x4C266B3A022D2074ULL) + aOUSaltC[((aIndex + 391U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 0x3EEB8E8DF51145E2ULL;
            aOrbiterH = RotL64((aOrbiterH * 0x9A4641D1DC7228BFULL), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 0xB8589810BEE87ABDULL;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 0xC512506B1C6E877DULL;
            aOrbiterI = RotL64((aOrbiterI * 0xAB7A71F8C9D4364BULL), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 0xA06DBD639C1CF1BFULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 0x077C3849F8CB5B95ULL;
            aOrbiterK = RotL64((aOrbiterK * 0x6C4389DB2F6F31A5ULL), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 0xF07EE07E826B4C5EULL) + aOUSaltD[((aIndex + 116U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 0x62DC73B864AC3145ULL) ^ aOUSaltH[(((511U - aIndex) + 277U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 0x2625FAB305C385A7ULL), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 0xE4ED5546BD255C9AULL) + aOUSaltA[(((511U - aIndex) + 362U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 0xB80DCEC59D5BEF87ULL;
            aOrbiterD = RotL64((aOrbiterD * 0x232ACE3E505A0C63ULL), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 0x380B2CE8C7A02B2FULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 0xFE370A22288B99CCULL;
            aOrbiterG = RotL64((aOrbiterG * 0x96173072855561AFULL), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 0x8FAE8E40C584F5C5ULL;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 0x74493282039CA17DULL) ^ aOUSaltB[(((511U - aIndex) + 302U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 0xF5221C336A3A754BULL), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 0xEF4BDF7A5CC92CFEULL;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 0x2CA78D5EA4662B02ULL;
            aOrbiterE = RotL64((aOrbiterE * 0x14B115A1A64A132FULL), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 0x03051746D46695B1ULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 0x34BA786C8ECC70F8ULL;
            aOrbiterF = RotL64((aOrbiterF * 0x2626D4ED3057AE7FULL), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 0x8A5496E575711FB5ULL;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 0xA934576C9C8C0996ULL;
            aOrbiterC = RotL64((aOrbiterC * 0x8526CB2096A6C711ULL), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 0x6A24D4FC4EF6DA42ULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 0x79B0870918F7ED0CULL;
            aOrbiterA = RotL64((aOrbiterA * 0x107DF0C6321DD2A1ULL), 5U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 26U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 58U)) + aOrbiterF) + aWUSaltD[(((511U - aIndex) + 392U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 34U) + RotL64(aOrbiterC, 35U)) + aOrbiterE) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterI, 11U));
            aWandererB = aWandererB + ((RotL64(aIngress, 51U) + aOrbiterF) + RotL64(aOrbiterD, 51U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterJ, 19U)) + aWUSaltG[(((511U - aIndex) + 201U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 37U)) + aOrbiterC);
            aWandererD = aWandererD ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterA, 3U)) + aOrbiterG);
            aWandererC = aWandererC + ((((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 3U)) + aWUSaltB[(((511U - aIndex) + 149U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 27U)) + aOrbiterK) + aWUSaltA[((aIndex + 318U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 44U) + RotL64(aOrbiterB, 41U)) + aOrbiterH) + aWUSaltF[((aIndex + 343U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterA, 14U));
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
        // File: nexus_07/loop_000410.bin
        //
        // Head:        [1, 5, 8, 3, 10, 6, 4, 2, 7, 9, 0]
        // Tail A:      [1, 7, 8, 2, 3, 0, 10, 4, 6, 5, 9]
        // Tail B:      [6, 8, 5, 7, 10, 3, 9, 2, 4, 0, 1]
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
        // Orbiters:    [DABKEJICFGH]
        // Wanderers:   [DIEJCFHKAGB]
        //
        // Ingress:     aEarthLaneA (-->), aEarthLaneB (-->), aLunarLaneC (-->), pCrossLaneA (<-?->)
        //
        // Cross:       aEarthLaneC (<--), aEarthLaneD (<--), aLunarLaneA (<--), aLunarLaneB (<-?->)
        //
        // Destination: aCrystalLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aEarthLaneA[((aIndex + 2401U)) & S_BLOCK1], 21U) ^ RotL64(aEarthLaneB[((aIndex + 7195U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aLunarLaneC[((aIndex + 2874U)) & S_BLOCK1], 3U) ^ RotL64(pCrossLaneA[((aIndex + 1073U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aTwistDomainWordIngress));
            //
            aCross = (RotL64(aEarthLaneC[((S_BLOCK1 - aIndex + 3293U)) & S_BLOCK1], 52U) ^ RotL64(aEarthLaneD[((S_BLOCK1 - aIndex + 1967U)) & S_BLOCK1], 29U));
            aCross ^= (RotL64(aLunarLaneA[((S_BLOCK1 - aIndex + 8069U)) & S_BLOCK1], 13U) ^ RotL64(aLunarLaneB[((S_BLOCK1 - aIndex + 3510U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aTwistDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 23U)) ^ (RotL64(aCarry, 6U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aTwistDomainWordScatter));
            //
            aOrbiterD = ((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 51U)) + 0xD889B7414E149476ULL;
            aOrbiterA = (aWandererF + RotL64(aScatter, 24U)) + 0x121F771B2525D33FULL;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 19U)) + 0xBF8F9C8591434CB4ULL;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 13U)) + 0x2AA22FDF06B46630ULL) + aOASaltH[((aIndex + 300U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 13U)) + 0xF0D2D45A39BFB6A1ULL;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 29U)) + 0x632915BA17A71CF2ULL) + aOASaltA[((aIndex + 212U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 41U)) + 0xD06E809AB41CAAAFULL) + aOASaltC[(((511U - aIndex) + 401U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 0xA63E29E965AFEDC6ULL;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 34U)) + 0xF48DD6A494CE56CEULL) + aOASaltF[(((511U - aIndex) + 177U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aScatter, 39U)) + 0x94F5A1B67F2F0C0AULL;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 11U)) + 0xD0BA3F1979E05A74ULL;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 0xF1DA68455E4E467BULL) + aOUSaltA[(((511U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 0x7D543ED8FEEB7E99ULL;
            aOrbiterB = RotL64((aOrbiterB * 0x79DE1DE25561A5C7ULL), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 0xD2264959DB2D6658ULL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 0x8D5EB77C15746B73ULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0x5A5251E6AAB46A8FULL), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 0x5182A22A1B06B976ULL;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 0x7AB9F3AC82A97950ULL) ^ aOUSaltD[(((511U - aIndex) + 386U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 0xF246CDE4EF3B76B7ULL), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 0x344E9E53A5344E4CULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 0x3DC7945F980BCCBEULL;
            aOrbiterG = RotL64((aOrbiterG * 0x865DCA673EE172F5ULL), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 0x27A88D4048605F5DULL) + aOUSaltG[(((511U - aIndex) + 243U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 0xC8512E6B065661D8ULL;
            aOrbiterD = RotL64((aOrbiterD * 0x9212245CDDAC8C47ULL), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 0x36C08A3469998CF4ULL;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 0x088D83A66BD8F5E3ULL;
            aOrbiterE = RotL64((aOrbiterE * 0xFB4DD0A37EB7812DULL), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 0xA1DA58BF65265C7BULL;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 0x05D63024DD5697EBULL;
            aOrbiterI = RotL64((aOrbiterI * 0xC4C73F2202F54117ULL), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 0xB5DD8466F4585D89ULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 0xA16E744FC2BA3D33ULL;
            aOrbiterK = RotL64((aOrbiterK * 0x9F0D3825A2087567ULL), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 0x1C2EE74B0BAC6E8FULL;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 0xCE6C080B44666069ULL;
            aOrbiterH = RotL64((aOrbiterH * 0xF06A10544CAF25FDULL), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 0x8266A132DE45A494ULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 0x47946F484665925DULL;
            aOrbiterA = RotL64((aOrbiterA * 0xEE7BF18EC72D0653ULL), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 0x3AC261A9D54DF30BULL) + aOUSaltE[(((511U - aIndex) + 410U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 0xE33E6030D3B12F7CULL) ^ aOUSaltB[((aIndex + 201U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 0xF3CD7C1E787B1AA7ULL), 39U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 18U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 34U) + aOrbiterA) + RotL64(aOrbiterI, 44U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterF, 53U));
            aWandererE = aWandererE + (((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 27U)) + aOrbiterJ) + aWUSaltB[((aIndex + 305U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterC, 57U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 27U)) + aWUSaltG[((aIndex + 217U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterD, 21U)) + aOrbiterK) + aWUSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 51U)) + aOrbiterG);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterB, 5U)) + aWUSaltH[((aIndex + 481U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterE, 19U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterD, 29U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 10U) + RotL64(aOrbiterG, 10U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aWUSaltF[((aIndex + 279U)) & S_SALT1]);
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
        // File: nexus_00/loop_000429.bin
        //
        // Head:        [7, 3, 4, 8, 0, 1, 6, 10, 9, 2, 5]
        // Tail A:      [1, 8, 2, 10, 5, 0, 9, 6, 4, 7, 3]
        // Tail B:      [8, 2, 7, 6, 10, 4, 3, 9, 5, 0, 1]
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
        // Ingress:     aCrystalLaneA (-->), aEarthLaneC (-->), aAetherLaneB (-->), pCrossLaneD (<-?->)
        //
        // Cross:       aEarthLaneA (<--), aEarthLaneB (<--), aAetherLaneA (<--), pCrossLaneB (<-?->)
        //
        // Destination: aCrystalLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aCrystalLaneA[((aIndex + 11825U)) & S_BLOCK1], 13U) ^ RotL64(aEarthLaneC[((aIndex + 9269U)) & S_BLOCK1], 54U));
            aIngress ^= (RotL64(aAetherLaneB[((aIndex + 10675U)) & S_BLOCK1], 41U) ^ RotL64(pCrossLaneD[((aIndex + 9957U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aTwistDomainWordIngress));
            //
            aCross = (RotL64(aEarthLaneA[((S_BLOCK1 - aIndex + 13739U)) & S_BLOCK1], 47U) ^ RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 16342U)) & S_BLOCK1], 27U));
            aCross ^= (RotL64(aAetherLaneA[((S_BLOCK1 - aIndex + 13562U)) & S_BLOCK1], 3U) ^ RotL64(pCrossLaneB[((aIndex + 12417U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseB((aCross ^ aTwistDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 21U)) ^ (RotL64(aPrevious, 40U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aTwistDomainWordScatter));
            //
            aOrbiterK = (aWandererG + RotL64(aScatter, 3U)) + 0x71E69ED2D11D2DB3ULL;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 5U)) + 0x45FCDA14BF57EA97ULL;
            aOrbiterI = ((aWandererF + RotL64(aCross, 21U)) + 0x9BB81D77F6845984ULL) + aOASaltF[((aIndex + 319U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aIngress, 51U)) + 0x42213CDB8195BE77ULL;
            aOrbiterD = (aWandererE + RotL64(aScatter, 26U)) + 0xF935E37A4677DF11ULL;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 29U)) + 0x635E9BEF06636D9BULL;
            aOrbiterG = ((aWandererA + RotL64(aCross, 5U)) + 0xD20DDCDCA2586BBBULL) + aOASaltD[(((511U - aIndex) + 381U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aIngress, 43U)) + 0xCCC14C6FCA245BBDULL) + aOASaltE[(((511U - aIndex) + 46U)) & S_SALT1];
            aOrbiterF = (((aWandererB + RotL64(aScatter, 56U)) + RotL64(aCarry, 53U)) + 0x9AEE38B0DFC132DDULL) + aOASaltC[((aIndex + 368U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 23U)) + 0x3A6377A9D51EF053ULL) + aOASaltG[((aIndex + 285U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aCross, 47U)) + 0x6BBE0A23C20AA3D1ULL;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 0x063E195369C0EC8DULL;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 0x7E062248411035FBULL;
            aOrbiterI = RotL64((aOrbiterI * 0x3534D410B0453423ULL), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 0x5F4120C9F56ED83CULL) + aOUSaltG[((aIndex + 464U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 0x285A0B52DDC35304ULL;
            aOrbiterA = RotL64((aOrbiterA * 0x42181A675AA243B5ULL), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 0xDD78A2E92EB4BEA6ULL;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 0xC66F9567C570F8CCULL;
            aOrbiterE = RotL64((aOrbiterE * 0x1FBEC838A16933B9ULL), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 0x025AF67B4FAA5607ULL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 0xA1C5E1D8E8D0BF85ULL) ^ aOUSaltF[((aIndex + 468U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 0x6230C847268F9DD1ULL), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 0xB7795859ED641622ULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 0x3E76DB19EF74B33FULL;
            aOrbiterK = RotL64((aOrbiterK * 0xE6F09B552FB43B33ULL), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 0x232A1033CB89D73BULL) + aOUSaltB[(((511U - aIndex) + 207U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 0xB9A6828F3838FEA8ULL;
            aOrbiterD = RotL64((aOrbiterD * 0xC6DB4A99D4FDA2DDULL), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 0x51B63BD3F49D90CFULL;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 0xB19F7B7BD9FBF1D1ULL) ^ aOUSaltA[(((511U - aIndex) + 509U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 0xB2B258A7F3C53A35ULL), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 0x36274A9DABD85707ULL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 0xC9D60F3DDCE7432AULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0x84FB1D634E74B67DULL), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 0x5874EA6523C98AA4ULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 0xFB69F885848A4FD6ULL;
            aOrbiterF = RotL64((aOrbiterF * 0x527D9EAFB9F38691ULL), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 0x4730F5B902D2921BULL;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 0xEBAAC7A9309F78E4ULL;
            aOrbiterC = RotL64((aOrbiterC * 0x46E0B4994C8487CFULL), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 0x5905FC3EA134567BULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 0xD2E419F4E506670EULL;
            aOrbiterG = RotL64((aOrbiterG * 0x81975D6B5F519523ULL), 21U);
            //
            aIngress = RotL64(aOrbiterK, 52U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 36U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 43U)) + aOrbiterF) + aWUSaltE[((aIndex + 318U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 58U) + aOrbiterF) + RotL64(aOrbiterI, 3U)) + aWUSaltC[(((511U - aIndex) + 505U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 40U)) + aOrbiterE) + RotL64(aCarry, 47U));
            aWandererK = aWandererK + ((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterG, 5U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterH, 13U));
            aWandererI = aWandererI + (((RotL64(aCross, 37U) + RotL64(aOrbiterK, 21U)) + aOrbiterD) + aWUSaltA[((aIndex + 83U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 37U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 53U)) + aOrbiterA) + aWUSaltG[(((511U - aIndex) + 138U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterK, 51U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterB, 18U)) + aOrbiterC);
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
        // File: nexus_12/loop_000188.bin
        //
        // Head:        [7, 6, 5, 4, 2, 8, 10, 9, 3, 1, 0]
        // Tail A:      [4, 5, 1, 7, 9, 0, 2, 8, 3, 10, 6]
        // Tail B:      [5, 2, 10, 3, 7, 8, 9, 1, 6, 4, 0]
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
        // Orbiters:    [CFKJDBAEGIH]
        // Wanderers:   [HABKCIGFEJD]
        //
        // Ingress:     aCrystalLaneB (-->), aEarthLaneD (-->), pCrossLaneC (<-?->)
        //
        // Cross:       aCrystalLaneA (<--), aEarthLaneB (<--), aAetherLaneD (<-?->)
        //
        // Destination: aCrystalLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aCrystalLaneB[((aIndex + 24048U)) & S_BLOCK1], 13U) ^ RotL64(aEarthLaneD[((aIndex + 23079U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(pCrossLaneC[((aIndex + 21689U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB((aIngress ^ aTwistDomainWordIngress));
            //
            aCross = (RotL64(aCrystalLaneA[((S_BLOCK1 - aIndex + 20405U)) & S_BLOCK1], 52U) ^ RotL64(aEarthLaneB[((S_BLOCK1 - aIndex + 19598U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aAetherLaneD[((S_BLOCK1 - aIndex + 22605U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC((aCross ^ aTwistDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 56U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aTwistDomainWordScatter));
            //
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 13U)) + 0xBE7A980D515D366BULL) + aOASaltG[((aIndex + 262U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aCross, 35U)) + 0xDB45948B7AD0A583ULL;
            aOrbiterK = (((aWandererI + RotL64(aIngress, 38U)) + RotL64(aCarry, 35U)) + 0x557D3EBA18AE9BB7ULL) + aOASaltF[(((511U - aIndex) + 77U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 23U)) + 0x2DEB93A1BD44AEDFULL) + aOASaltE[(((511U - aIndex) + 274U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aPrevious, 51U)) + 0xDA69F1B23B81AA96ULL;
            aOrbiterB = (aWandererE + RotL64(aCross, 27U)) + 0x5FB6FAA24A0D5E43ULL;
            aOrbiterA = (((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 27U)) + 0x17D67DA36D23BDE5ULL) + aOASaltD[(((511U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 3U)) + 0x0C1F258183133B08ULL) + aOASaltH[((aIndex + 364U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aPrevious, 10U)) + 0x99C83A95D3784D8BULL;
            aOrbiterI = ((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 39U)) + 0xAC933CBC966E577DULL;
            aOrbiterH = (aWandererH + RotL64(aIngress, 57U)) + 0xC903883434D4F48CULL;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 0x8A49CA32998E054FULL) + aOUSaltE[((aIndex + 232U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 0x81C8E09A876935DDULL) ^ aOUSaltC[((aIndex + 91U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 0x139C3CDE6F9CB453ULL), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 0x12B23DB3791317ACULL) + aOUSaltF[((aIndex + 227U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 0xAABDA3F347552ECCULL;
            aOrbiterB = RotL64((aOrbiterB * 0x3F7C77EF4E684253ULL), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 0x3EAAB18E5B3FA1B6ULL;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 0x98BF5797EB1A6DEEULL) ^ aOUSaltG[((aIndex + 169U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 0xE89D68171F682F15ULL), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 0xB6B0BD7CBF87B50CULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 0x063E1F28A4D2EA72ULL;
            aOrbiterD = RotL64((aOrbiterD * 0xEC95B315E50FA305ULL), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 0x364FE8339435442FULL;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 0xB281729B208E6A10ULL;
            aOrbiterC = RotL64((aOrbiterC * 0xCF3B7923BAA04B9FULL), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 0x47A454D495B30457ULL;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 0x7607E9A88CA72992ULL;
            aOrbiterE = RotL64((aOrbiterE * 0x90542A3ABCC6BA47ULL), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 0xFC198F87C6BF4EB9ULL) + aOUSaltD[(((511U - aIndex) + 213U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 0x6E1F65DCBAADEF62ULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0x21B59B4B3B50D365ULL), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 0x6E8A8124FB1504CDULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 0x70BE376CF16296B2ULL;
            aOrbiterA = RotL64((aOrbiterA * 0x5F73D5B44385BD9FULL), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 0x9715B954E334B7CFULL) + aOUSaltB[((aIndex + 66U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 0x98EEFACB0EB4AD8EULL;
            aOrbiterF = RotL64((aOrbiterF * 0xE47DA7A4F238F7BDULL), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 0xB06EDC221B9896ACULL;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 0xE5E31C6D536232C9ULL;
            aOrbiterI = RotL64((aOrbiterI * 0x3E6C616393B4D2A9ULL), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 0x9A5F184C9A08EE10ULL;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 0x85ADD014B9BA8A59ULL;
            aOrbiterH = RotL64((aOrbiterH * 0x282964A147A75493ULL), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 60U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + RotL64(aOrbiterD, 28U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterB, 29U)) + aWUSaltA[((aIndex + 78U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 18U) + RotL64(aOrbiterB, 37U)) + aOrbiterK) + aWUSaltD[(((511U - aIndex) + 107U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 18U)) + aOrbiterH) + aWUSaltB[(((511U - aIndex) + 89U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterJ, 57U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterE, 13U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterC, 11U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererG = aWandererG + ((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 5U)) + aOrbiterI);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterF, 52U)) + aWUSaltE[(((511U - aIndex) + 387U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 44U) + aOrbiterJ) + RotL64(aOrbiterA, 35U)) + aWUSaltG[(((511U - aIndex) + 303U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterH, 23U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 27U)) + aOrbiterC) + RotL64(aCarry, 3U));
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
        // File: nexus_05/loop_000340.bin
        //
        // Head:        [0, 4, 1, 10, 7, 2, 9, 6, 8, 5, 3]
        // Tail A:      [5, 0, 6, 1, 3, 7, 10, 9, 4, 2, 8]
        // Tail B:      [9, 10, 8, 5, 7, 4, 3, 6, 2, 1, 0]
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
        // Orbiters:    [CBIKDHEFJAG]
        // Wanderers:   [BECJKGHADFI]
        //
        // Ingress:     aCrystalLaneC (-->), aCrystalLaneA (-->), aAetherLaneC (<-?->)
        //
        // Cross:       aCrystalLaneB (<--), aLunarLaneD (<--), aSource (<-?->)
        //
        // Destination: aCrystalLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aCrystalLaneC[((aIndex + 25057U)) & S_BLOCK1], 44U) ^ RotL64(aCrystalLaneA[((aIndex + 27571U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aAetherLaneC[((aIndex + 26671U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB((aIngress ^ aTwistDomainWordIngress));
            //
            aCross = (RotL64(aCrystalLaneB[((S_BLOCK1 - aIndex + 30824U)) & S_BLOCK1], 20U) ^ RotL64(aLunarLaneD[((S_BLOCK1 - aIndex + 30199U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aSource[((aIndex + 28152U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA((aCross ^ aTwistDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 36U) + RotL64(aCarry, 11U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aTwistDomainWordScatter));
            //
            aOrbiterC = ((aWandererB + RotL64(aCross, 5U)) + 0xE922119ABF68A7A9ULL) + aOASaltF[(((511U - aIndex) + 316U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aIngress, 47U)) + 0xD18E21EA98B0382AULL;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 3U)) + 0x9742ED29996312DAULL) + aOASaltH[(((511U - aIndex) + 327U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 60U)) + RotL64(aCarry, 13U)) + 0x08AA3A04D755CB4AULL;
            aOrbiterD = (aWandererA + RotL64(aCross, 19U)) + 0x79BDAD64D4666673ULL;
            aOrbiterH = (aWandererC + RotL64(aIngress, 21U)) + 0x16CEB96EBB162B62ULL;
            aOrbiterE = (aWandererF + RotL64(aScatter, 53U)) + 0x75C8E393779D957CULL;
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 23U)) + RotL64(aCarry, 29U)) + 0x46BF2614ECD050A4ULL) + aOASaltE[(((511U - aIndex) + 63U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aCross, 12U)) + 0x6DC90A3964234D72ULL) + aOASaltA[((aIndex + 125U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aIngress, 57U)) + 0x3C6BB6D78B5BBB12ULL;
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 19U)) + 0x097E2275466A03EEULL) + aOASaltG[(((511U - aIndex) + 437U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 0xC31F29884D57230EULL;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 0x51108CE486281F71ULL;
            aOrbiterI = RotL64((aOrbiterI * 0xF1D5975BF591A5EDULL), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 0x6B2BF1C78A2AB651ULL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 0x257914ABD2C1C511ULL) ^ aOUSaltB[(((511U - aIndex) + 300U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 0x657D35DC8A3DF383ULL), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 0x689D7F527CDC83CAULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 0x202295545EA8F1EDULL;
            aOrbiterF = RotL64((aOrbiterF * 0xAF660FDCEDF52935ULL), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 0x09939FCF47B7673AULL) + aOUSaltH[(((511U - aIndex) + 431U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 0x665250596E1574AFULL;
            aOrbiterB = RotL64((aOrbiterB * 0x12884E7D278BCA6FULL), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 0x84B88C4B3F2724ACULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 0xCD76EEA091621DACULL;
            aOrbiterD = RotL64((aOrbiterD * 0x20A6294C980B1767ULL), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 0xB06A8BD856491A60ULL) + aOUSaltE[((aIndex + 1U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 0xA4D67D347AB03BB6ULL) ^ aOUSaltG[(((511U - aIndex) + 221U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 0x9F2C6B3183F38B8DULL), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 0x27A9FAD54D5D852BULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 0xF06BCA9AED02A4E4ULL;
            aOrbiterK = RotL64((aOrbiterK * 0xD6B54758FAEEA915ULL), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 0x18AD8CB9F1256975ULL;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 0xD589E41A1B09CD59ULL;
            aOrbiterE = RotL64((aOrbiterE * 0xDAACE4A59873796BULL), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 0x9CCFD77EFEF642FDULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 0x1D1ECE1662F47126ULL;
            aOrbiterA = RotL64((aOrbiterA * 0x22148BC0F793B875ULL), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 0xA2FA33ADA9141BE2ULL) + aOUSaltA[((aIndex + 475U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 0x5EB8196D781A79C6ULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0x798825F9CD9EC6B1ULL), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 0x46C8E682584A620AULL;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 0x4E59FDE576BCEECCULL) ^ aOUSaltF[((aIndex + 260U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 0x0D482AE7C523EB2DULL), 11U);
            //
            aIngress = RotL64(aOrbiterK, 12U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 6U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 40U)) + aOrbiterA) + aWUSaltC[((aIndex + 483U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 37U) + RotL64(aOrbiterC, 21U)) + aOrbiterG) + aWUSaltG[((aIndex + 336U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 30U) + RotL64(aOrbiterE, 5U)) + aOrbiterJ) + RotL64(aCarry, 3U)) + aWUSaltH[((aIndex + 360U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterH, 57U)) + aWUSaltF[(((511U - aIndex) + 302U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterF, 27U));
            aWandererG = aWandererG + ((RotL64(aCross, 57U) + RotL64(aOrbiterF, 51U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 35U)) + aOrbiterK);
            aWandererA = aWandererA + ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterE, 10U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 13U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererF = aWandererF + (((RotL64(aCross, 10U) + RotL64(aOrbiterI, 23U)) + aOrbiterB) + aWUSaltE[((aIndex + 373U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 47U)) + aOrbiterC);
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
