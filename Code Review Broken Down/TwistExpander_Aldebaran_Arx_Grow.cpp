
void TwistExpander_Aldebaran_Arx::GROW_A_A(TwistWorkSpace *pWorkSpace,
                     std::uint8_t *pCrossLaneA,
                     std::uint8_t *pCrossLaneB,
                     MUTABLE_PARAMS) {
    std::uint8_t *aSpiritLaneA = pWorkSpace->mSpiritLaneA;
    std::uint8_t *aSpiritLaneB = pWorkSpace->mSpiritLaneB;
    std::uint8_t *aSpiritLaneC = pWorkSpace->mSpiritLaneC;
    std::uint8_t *aSpiritLaneD = pWorkSpace->mSpiritLaneD;
    std::uint8_t *aEarthLaneA = pWorkSpace->mEarthLaneA;
    std::uint8_t *aEarthLaneC = pWorkSpace->mEarthLaneC;
    std::uint8_t *aAetherLaneA = pWorkSpace->mAetherLaneA;
    std::uint8_t *aAetherLaneC = pWorkSpace->mAetherLaneC;
    std::uint8_t *aArcaneLaneA = pWorkSpace->mArcaneLaneA;
    std::uint8_t *aArcaneLaneB = pWorkSpace->mArcaneLaneB;
    std::uint8_t *aArcaneLaneC = pWorkSpace->mArcaneLaneC;
    std::uint8_t *aArcaneLaneD = pWorkSpace->mArcaneLaneD;
    std::uint8_t *aLunarLaneA = pWorkSpace->mLunarLaneA;
    std::uint8_t *aLunarLaneC = pWorkSpace->mLunarLaneC;
    std::uint64_t *aOASaltA = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltA;
    std::uint64_t *aOASaltB = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltB;
    std::uint64_t *aOASaltC = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltC;
    std::uint64_t *aOASaltD = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltD;
    std::uint64_t *aOASaltE = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltE;
    std::uint64_t *aOASaltF = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltF;
    std::uint64_t *aOASaltG = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltG;
    std::uint64_t *aOASaltH = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltH;
    std::uint64_t *aOUSaltA = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltA;
    std::uint64_t *aOUSaltB = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltB;
    std::uint64_t *aOUSaltC = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltC;
    std::uint64_t *aOUSaltD = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltD;
    std::uint64_t *aOUSaltE = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltE;
    std::uint64_t *aOUSaltF = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltF;
    std::uint64_t *aOUSaltG = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltG;
    std::uint64_t *aOUSaltH = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltH;
    std::uint64_t *aWUSaltA = pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltA;
    std::uint64_t *aWUSaltB = pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltB;
    std::uint64_t *aWUSaltC = pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltC;
    std::uint64_t *aWUSaltD = pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltD;
    std::uint64_t *aWUSaltE = pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltE;
    std::uint64_t *aWUSaltF = pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltF;
    std::uint64_t *aWUSaltG = pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltG;
    std::uint64_t *aWUSaltH = pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltH;
    std::uint8_t *pCrossLaneA_A = pCrossLaneA + (W_KEY * 0U);
    std::uint8_t *pCrossLaneB_A = pCrossLaneB + (W_KEY * 0U);
    std::uint8_t *aAetherLaneA_A = aAetherLaneA + (W_KEY * 0U);
    std::uint8_t *aAetherLaneC_A = aAetherLaneC + (W_KEY * 0U);
    std::uint8_t *aArcaneLaneA_A = aArcaneLaneA + (W_KEY * 0U);
    std::uint8_t *aArcaneLaneB_A = aArcaneLaneB + (W_KEY * 0U);
    std::uint8_t *aArcaneLaneC_A = aArcaneLaneC + (W_KEY * 0U);
    std::uint8_t *aArcaneLaneD_A = aArcaneLaneD + (W_KEY * 0U);
    std::uint8_t *aLunarLaneA_A = aLunarLaneA + (W_KEY * 0U);
    std::uint8_t *aLunarLaneC_A = aLunarLaneC + (W_KEY * 0U);
    std::uint8_t *aSpiritLaneA_A = aSpiritLaneA + (W_KEY * 0U);
    std::uint8_t *aSpiritLaneB_A = aSpiritLaneB + (W_KEY * 0U);
    std::uint8_t *aSpiritLaneC_A = aSpiritLaneC + (W_KEY * 0U);
    std::uint8_t *aSpiritLaneD_A = aSpiritLaneD + (W_KEY * 0U);
    std::uint8_t *aEarthLaneA_A = aEarthLaneA + (W_KEY * 0U);
    std::uint8_t *aEarthLaneC_A = aEarthLaneC + (W_KEY * 0U);
    const std::uint64_t &aKeyRotateADomainWordIngress = pWorkSpace->mDomainBundle.mKeyRotateAConstants.mIngress;
    const std::uint64_t &aKeyRotateADomainWordScatter = pWorkSpace->mDomainBundle.mKeyRotateAConstants.mScatter;
    const std::uint64_t &aKeyRotateADomainWordCross = pWorkSpace->mDomainBundle.mKeyRotateAConstants.mCross;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [grow arx]
    READ_IN_MUTABLE_PARAMS;
    // GROW_A_A grow_a_loop_a (start)
    {
        //
        // File: nexus_11/loop_000204.bin
        //
        // Head:        [9, 1, 5, 8, 7, 3, 10, 2, 4, 6, 0]
        // Tail A:      [4, 9, 0, 2, 3, 6, 7, 10, 5, 1, 8]
        // Tail B:      [5, 4, 10, 8, 9, 1, 3, 7, 6, 2, 0]
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
        // Orbiters:    [FCDHKAGBEJI]
        // Wanderers:   [CAGBIKHDEFJ]
        //
        // Ingress:     aSpiritLaneD (-->), aSpiritLaneB (-->), pCrossLaneA (-->), aEarthLaneA (-->)
        //
        // Cross:       aSpiritLaneC (<--), aSpiritLaneA (<--), pCrossLaneA (<--), aEarthLaneC (<--)
        //
        // Destination: aArcaneLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSpiritLaneD_A[((aIndex + 1910U)) & W_KEY1], 58U) ^ RotL64(aSpiritLaneB_A[((aIndex + 187U)) & W_KEY1], 5U));
            aIngress ^= (RotL64(pCrossLaneA_A[((aIndex + 1866U)) & W_KEY1], 19U) ^ RotL64(aEarthLaneA_A[((aIndex + 990U)) & W_KEY1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aKeyRotateADomainWordIngress));
            //
            aCross = (RotL64(aSpiritLaneC_A[(((2047U - aIndex) + 620U)) & W_KEY1], 23U) ^ RotL64(aSpiritLaneA_A[(((2047U - aIndex) + 1076U)) & W_KEY1], 47U));
            aCross ^= (RotL64(pCrossLaneA_A[(((2047U - aIndex) + 171U)) & W_KEY1], 12U) ^ RotL64(aEarthLaneC_A[(((2047U - aIndex) + 1087U)) & W_KEY1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aKeyRotateADomainWordCross));
            //
            aScatter = (RotL64(aCross, 10U) + RotL64(aIngress, 23U)) ^ (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aKeyRotateADomainWordScatter));
            //
            aOrbiterF = ((aWandererF + RotL64(aIngress, 30U)) + RotL64(aCarry, 35U)) + 0x6C067109A4890A3EULL;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 19U)) + 0xD03366B8B3E38F4BULL) + aOASaltC[((aIndex + 465U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aPrevious, 43U)) + 0xA1C4D15EC459909EULL;
            aOrbiterH = (aWandererE + RotL64(aCross, 37U)) + 0xC779E5D9211F8B09ULL;
            aOrbiterK = (((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 41U)) + 0x92EC694ED76BB9E5ULL) + aOASaltG[((aIndex + 129U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aScatter, 53U)) + 0x8B328F33B64C8B61ULL;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 23U)) + 0xDB2B93575F0E08D6ULL;
            aOrbiterB = ((aWandererG + RotL64(aCross, 27U)) + 0x810DC3DD411428F8ULL) + aOASaltD[(((511U - aIndex) + 493U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 29U)) + 0x79E4E0578309857BULL;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 58U)) + 0x99CD9B42DBD85427ULL;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 35U)) + 0xF2EAA72132BD097DULL;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 0x21D8E8D7EC4184C5ULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 0xB0E274097CB355D5ULL;
            aOrbiterD = RotL64((aOrbiterD * 0x15102F9C68A78BCDULL), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 0x734AAC83956237D2ULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 0xE3142192DAAE9C59ULL;
            aOrbiterA = RotL64((aOrbiterA * 0xB89AA2172F9280CFULL), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 0x3933F1DAA4FAB7A0ULL) + aOUSaltB[(((511U - aIndex) + 53U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 0xB48877119BA44F94ULL;
            aOrbiterE = RotL64((aOrbiterE * 0x49C29AF6B6FCCDDFULL), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 0x9C77351CDF44347AULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 0x02784942EDE197D6ULL;
            aOrbiterF = RotL64((aOrbiterF * 0x8BB3E071BF278461ULL), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 0xDCD0B7D2F9D20C55ULL;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 0xFB18FA45B9F2904AULL) ^ aOUSaltC[(((511U - aIndex) + 180U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 0x6F12B44E81D5F815ULL), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 0x51CF444EA9A54570ULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 0xC658B9A1372394B6ULL;
            aOrbiterK = RotL64((aOrbiterK * 0x6D2996EDEACA5695ULL), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 0x551692A03DA36A93ULL) + aOUSaltA[(((511U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 0x714F6D5DA884C5B6ULL) ^ aOUSaltE[((aIndex + 257U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 0x508E1C5D93A3DCF3ULL), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 0xF578578468F32923ULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 0xF6AFB0A0C0857C1AULL;
            aOrbiterG = RotL64((aOrbiterG * 0x3B0F5D435B0FED7DULL), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 0x6E0DA0C2932A1AD9ULL;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 0xE056FB8962721DF7ULL;
            aOrbiterB = RotL64((aOrbiterB * 0x72A366CF65B0F375ULL), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 0x4D3CE8283036B8C3ULL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 0xB3F2CE850E083676ULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0x7D6E1BD922D8E9CDULL), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 0xB78C6D85ADC7472EULL;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 0x5D076533324CB689ULL;
            aOrbiterI = RotL64((aOrbiterI * 0x2FCE84320F435219ULL), 11U);
            //
            aIngress = RotL64(aOrbiterA, 41U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterF, 60U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 6U) + aOrbiterK) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterK, 41U)) + aWUSaltE[(((511U - aIndex) + 206U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterI, 56U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 5U)) + aOrbiterE) + aWUSaltC[((aIndex + 57U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterJ, 47U));
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 11U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aWUSaltD[(((511U - aIndex) + 81U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 3U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterB, 21U));
            aWandererE = aWandererE + (((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterG, 29U)) + aWUSaltB[((aIndex + 470U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 10U) + aOrbiterC) + RotL64(aOrbiterD, 51U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterF, 38U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 50U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 22U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aArcaneLaneA_A[(aIndex) & W_KEY1] = aIngress;
        }
    
        //
        // File: nexus_07/loop_000545.bin
        //
        // Head:        [0, 10, 6, 1, 2, 5, 3, 9, 4, 7, 8]
        // Tail A:      [2, 7, 8, 9, 5, 6, 4, 0, 3, 1, 10]
        // Tail B:      [1, 8, 0, 7, 6, 4, 9, 3, 2, 10, 5]
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
        // Orbiters:    [EIDCKFGAJBH]
        // Wanderers:   [KBEDHGJICFA]
        //
        // Ingress:     aArcaneLaneA (-->), aSpiritLaneC (-->), pCrossLaneB (-->), aLunarLaneA (-->)
        //
        // Cross:       aSpiritLaneD (<--), aSpiritLaneB (<--), pCrossLaneA (<--), aLunarLaneC (<--)
        //
        // Destination: aArcaneLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aArcaneLaneA_A[((aIndex + 1340U)) & W_KEY1], 27U) ^ RotL64(aSpiritLaneC_A[((aIndex + 738U)) & W_KEY1], 57U));
            aIngress ^= (RotL64(pCrossLaneB_A[((aIndex + 1471U)) & W_KEY1], 10U) ^ RotL64(aLunarLaneA_A[((aIndex + 143U)) & W_KEY1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aKeyRotateADomainWordIngress));
            //
            aCross = (RotL64(aSpiritLaneD_A[(((2047U - aIndex) + 303U)) & W_KEY1], 35U) ^ RotL64(aSpiritLaneB_A[(((2047U - aIndex) + 576U)) & W_KEY1], 3U));
            aCross ^= (RotL64(pCrossLaneA_A[(((2047U - aIndex) + 147U)) & W_KEY1], 12U) ^ RotL64(aLunarLaneC_A[(((2047U - aIndex) + 1002U)) & W_KEY1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aKeyRotateADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCarry, 3U)) + (RotL64(aCross, 27U) ^ RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aKeyRotateADomainWordScatter));
            //
            aOrbiterE = (aWandererK + RotL64(aScatter, 11U)) + 0xECAF3E88CC291BBDULL;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 41U)) + RotL64(aCarry, 27U)) + 0x7B8371C0F46EC356ULL;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 52U)) + 0xA831BEC30C22FB1FULL) + aOASaltC[(((511U - aIndex) + 354U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aIngress, 39U)) + 0x5B09B0984B057ED3ULL;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 47U)) + 0x68B3DD20CF34BE56ULL) + aOASaltB[(((511U - aIndex) + 203U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 43U)) + 0xCE56F55571B8C125ULL;
            aOrbiterG = (aWandererD + RotL64(aCross, 57U)) + 0x80D616514E5A64E2ULL;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 35U)) + 0x43651A09450394F3ULL) + aOASaltA[((aIndex + 141U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aScatter, 5U)) + 0x8DDF9B76119AE4A9ULL;
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 47U)) + 0x47130748283B05D2ULL) + aOASaltH[(((511U - aIndex) + 281U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aCross, 50U)) + 0x925D346FCAD84FE7ULL;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 0x583CE8DBC309DCC9ULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 0xB4A72E536C3B856CULL;
            aOrbiterD = RotL64((aOrbiterD * 0x5C6BDA26233BBCBDULL), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 0x93F6DE1B1D8F87A1ULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 0x42747E179633FB64ULL;
            aOrbiterF = RotL64((aOrbiterF * 0x48EFA6A356DC3D57ULL), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 0x10C3DF83D3C8A1BBULL) + aOUSaltC[((aIndex + 463U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 0xF79749F5E0DDD03EULL) ^ aOUSaltA[((aIndex + 447U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 0x1B5321153316390FULL), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 0x60EC09B5288F7B48ULL;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 0x25335E35422DB598ULL;
            aOrbiterB = RotL64((aOrbiterB * 0x2C47BEA2B838ADA1ULL), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 0x14CAFDC37462250FULL;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 0x41EC1484A7797BC6ULL;
            aOrbiterE = RotL64((aOrbiterE * 0xEA3DEFE3F05CABF9ULL), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 0xA93CF7F1BBEEFD1BULL) + aOUSaltG[(((511U - aIndex) + 436U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 0x7110EB680E595AC8ULL;
            aOrbiterK = RotL64((aOrbiterK * 0x050C2FE4C42285D9ULL), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 0x8716754646B1FC1CULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 0x7CB0B0D0CF7A4DF8ULL;
            aOrbiterG = RotL64((aOrbiterG * 0xF84F2B4A5C94A391ULL), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 0x51CB60449CF280E3ULL) + aOUSaltB[((aIndex + 157U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 0xD5691E460E66AA70ULL) ^ aOUSaltE[((aIndex + 223U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 0x6D3270AB52B414E7ULL), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 0xE9F7C4B5F8494759ULL) + aOUSaltF[((aIndex + 43U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 0xD30320F3216D5FB3ULL;
            aOrbiterH = RotL64((aOrbiterH * 0x2E0D3E0AE5D0BD05ULL), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 0xFC71B1EED47F6A06ULL;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 0x270DFC0597706D49ULL;
            aOrbiterI = RotL64((aOrbiterI * 0x6B345EF6A335E6BBULL), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 0x2053B1B90CECB831ULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 0x5C51C370E0444D40ULL;
            aOrbiterA = RotL64((aOrbiterA * 0x3C37534D01210B8FULL), 51U);
            //
            aIngress = RotL64(aOrbiterG, 51U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (RotL64(aOrbiterA, 60U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterD, 60U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterJ, 27U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterE, 11U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterB, 43U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterG, 20U));
            aWandererG = aWandererG + (((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 41U)) + aOrbiterK) + aWUSaltH[((aIndex + 250U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 29U)) + aOrbiterB) + aWUSaltC[((aIndex + 265U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterC, 3U)) + aWUSaltE[(((511U - aIndex) + 33U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 23U) + RotL64(aOrbiterC, 53U)) + aOrbiterD) + RotL64(aCarry, 27U)) + aWUSaltA[(((511U - aIndex) + 288U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterH, 35U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 42U) + aOrbiterH) + RotL64(aOrbiterF, 57U)) + aWUSaltG[(((511U - aIndex) + 70U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 18U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 36U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aArcaneLaneB_A[((2047U - aIndex)) & W_KEY1] = aIngress;
        }
    
        //
        // File: nexus_05/loop_000173.bin
        //
        // Head:        [10, 7, 5, 9, 1, 3, 6, 4, 2, 8, 0]
        // Tail A:      [5, 1, 2, 4, 9, 10, 3, 8, 0, 7, 6]
        // Tail B:      [7, 6, 8, 1, 5, 0, 10, 3, 4, 2, 9]
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
        // Orbiters:    [HJCKDFEGBAI]
        // Wanderers:   [ABHEJGFDKIC]
        //
        // Ingress:     aArcaneLaneB (-->), aSpiritLaneD (-->), aEarthLaneC (-->), aEarthLaneA (-->)
        //
        // Cross:       aArcaneLaneA (<--), aSpiritLaneC (<--), aAetherLaneC (<--), aAetherLaneA (<--)
        //
        // Destination: aArcaneLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aArcaneLaneB_A[((aIndex + 574U)) & W_KEY1], 46U) ^ RotL64(aSpiritLaneD_A[((aIndex + 1134U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(aEarthLaneC_A[((aIndex + 1230U)) & W_KEY1], 27U) ^ RotL64(aEarthLaneA_A[((aIndex + 327U)) & W_KEY1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aKeyRotateADomainWordIngress));
            //
            aCross = (RotL64(aArcaneLaneA_A[(((2047U - aIndex) + 1834U)) & W_KEY1], 56U) ^ RotL64(aSpiritLaneC_A[(((2047U - aIndex) + 380U)) & W_KEY1], 21U));
            aCross ^= (RotL64(aAetherLaneC_A[(((2047U - aIndex) + 1450U)) & W_KEY1], 29U) ^ RotL64(aAetherLaneA_A[(((2047U - aIndex) + 1374U)) & W_KEY1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aKeyRotateADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 5U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 24U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aKeyRotateADomainWordScatter));
            //
            aOrbiterH = (aWandererC + RotL64(aPrevious, 13U)) + 0x098B3F7DB2E6E2BFULL;
            aOrbiterJ = (aWandererD + RotL64(aCross, 3U)) + 0x462C65701E29279FULL;
            aOrbiterC = (((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 57U)) + 0x121EC7BF8ABB3E0FULL) + aOASaltD[((aIndex + 427U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aScatter, 35U)) + 0x80D2B4F111018B9BULL;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 46U)) + 0x6974786C76BF4766ULL;
            aOrbiterF = ((aWandererE + RotL64(aCross, 21U)) + 0x5F84A4A2FDB9D5D6ULL) + aOASaltA[((aIndex + 267U)) & S_SALT1];
            aOrbiterE = (((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 5U)) + 0xBEBCC9759069968EULL) + aOASaltE[((aIndex + 114U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aScatter, 29U)) + 0x7662842293DCA9BFULL;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 53U)) + 0x742D1AFEA62A7286ULL;
            aOrbiterA = ((aWandererK + RotL64(aCross, 57U)) + 0xF50476157494BF99ULL) + aOASaltB[((aIndex + 193U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aIngress, 24U)) + RotL64(aCarry, 39U)) + 0xC7349041C1CB6F7DULL;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 0xEF1F30FC367BC174ULL;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 0x6A2140CA6FE0A758ULL;
            aOrbiterC = RotL64((aOrbiterC * 0x0E87592ED90C5677ULL), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 0xDA721A2E966BE969ULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 0x2E540924D8B7D825ULL;
            aOrbiterF = RotL64((aOrbiterF * 0x7C072D2D4F8366A1ULL), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 0x876917D28A187C22ULL) + aOUSaltA[(((511U - aIndex) + 395U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 0x4726BDD3C3688DD5ULL;
            aOrbiterG = RotL64((aOrbiterG * 0x0FD22155D75B6457ULL), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 0xD279AC7CE8D8CC9DULL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 0xA128667EAAF1A8F3ULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0x7B14BE795C468CDFULL), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 0x69A92FB671E4D5F8ULL) + aOUSaltB[(((511U - aIndex) + 129U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 0x8E5EA8089C9D169AULL;
            aOrbiterD = RotL64((aOrbiterD * 0xE4CF3AAE2A9DDEBBULL), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 0x9F373456701D9DF0ULL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 0xE876640464CEE1ACULL) ^ aOUSaltH[((aIndex + 339U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 0x44BD715F0F4A72F3ULL), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 0x8DF0965E17839C5FULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 0xA86ECC9BA0B9CB10ULL;
            aOrbiterK = RotL64((aOrbiterK * 0xAF5A7A61B98642BBULL), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 0x23872C72CE826A9AULL) + aOUSaltD[(((511U - aIndex) + 63U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 0x70D149A91774DCAEULL;
            aOrbiterE = RotL64((aOrbiterE * 0xA0236A14DF363D0DULL), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 0x95BD6FD735663A3FULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 0xF5E138DC167F6BA0ULL;
            aOrbiterA = RotL64((aOrbiterA * 0xA9548B892762AB85ULL), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 0xD5316767353925F9ULL;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 0x66EC4743BE7C8437ULL;
            aOrbiterB = RotL64((aOrbiterB * 0x8E33F2717AC5C751ULL), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 0x16940EABB71C2819ULL;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 0x449055B89EB0B826ULL;
            aOrbiterI = RotL64((aOrbiterI * 0x7375231E643CDD1FULL), 37U);
            //
            aIngress = RotL64(aOrbiterG, 53U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (RotL64(aOrbiterF, 44U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterG, 52U)) + RotL64(aCarry, 37U)) + aWUSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 13U)) + aOrbiterE);
            aWandererH = aWandererH + ((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterB, 11U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 29U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aCross, 56U) + aOrbiterA) + RotL64(aOrbiterF, 5U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 19U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 39U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterK, 27U)) + aWUSaltF[((aIndex + 236U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterD, 47U)) + aWUSaltA[((aIndex + 450U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 24U) + RotL64(aOrbiterG, 37U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterA, 22U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 52U));
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + RotL64(aWandererA, 18U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aArcaneLaneC_A[(aIndex) & W_KEY1] = aIngress;
        }
    
        //
        // File: nexus_00/loop_000790.bin
        //
        // Head:        [10, 6, 2, 3, 1, 8, 0, 5, 7, 4, 9]
        // Tail A:      [9, 7, 1, 0, 4, 5, 8, 2, 3, 6, 10]
        // Tail B:      [7, 1, 10, 6, 2, 9, 0, 3, 8, 5, 4]
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
        // Orbiters:    [ICJDAKFBHGE]
        // Wanderers:   [JEACGHBKDIF]
        //
        // Ingress:     aArcaneLaneC (-->), aArcaneLaneA (-->), aEarthLaneA (-->), aLunarLaneC (-->)
        //
        // Cross:       aArcaneLaneB (<--), aSpiritLaneD (<--), aLunarLaneA (<--), aEarthLaneC (<--)
        //
        // Destination: aArcaneLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aArcaneLaneC_A[((aIndex + 1368U)) & W_KEY1], 47U) ^ RotL64(aArcaneLaneA_A[((aIndex + 994U)) & W_KEY1], 35U));
            aIngress ^= (RotL64(aEarthLaneA_A[((aIndex + 104U)) & W_KEY1], 56U) ^ RotL64(aLunarLaneC_A[((aIndex + 832U)) & W_KEY1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aKeyRotateADomainWordIngress));
            //
            aCross = (RotL64(aArcaneLaneB_A[(((2047U - aIndex) + 1694U)) & W_KEY1], 21U) ^ RotL64(aSpiritLaneD_A[(((2047U - aIndex) + 1768U)) & W_KEY1], 53U));
            aCross ^= (RotL64(aLunarLaneA_A[(((2047U - aIndex) + 1159U)) & W_KEY1], 10U) ^ RotL64(aEarthLaneC_A[(((2047U - aIndex) + 453U)) & W_KEY1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aKeyRotateADomainWordCross));
            //
            aScatter = (RotL64(aCross, 60U) ^ RotL64(aIngress, 11U)) + (RotL64(aCarry, 23U) + RotL64(aPrevious, 47U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aKeyRotateADomainWordScatter));
            //
            aOrbiterI = ((aWandererF + RotL64(aCross, 3U)) + RotL64(aCarry, 21U)) + 0xA90720A85DE9E112ULL;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 23U)) + 0x446091C42F55DC28ULL) + aOASaltF[((aIndex + 130U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aScatter, 30U)) + 0xBCA29A1B42882A26ULL;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 43U)) + 0x34A0BC54F863F1F5ULL;
            aOrbiterA = (aWandererE + RotL64(aCross, 27U)) + 0x32836D0D9A72CD8CULL;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 21U)) + 0x74908ADE5D22ED81ULL) + aOASaltH[((aIndex + 69U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aScatter, 35U)) + 0x089E052D3D93238EULL;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 37U)) + RotL64(aCarry, 13U)) + 0xB6CE52E7456982CBULL;
            aOrbiterH = (aWandererK + RotL64(aCross, 41U)) + 0x5B6D40E70B25B21AULL;
            aOrbiterG = (aWandererG + RotL64(aIngress, 6U)) + 0x68DF2F0184665A7FULL;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 47U)) + 0xAD86E92DF56F7AEDULL) + aOASaltC[(((511U - aIndex) + 106U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 0xAC301B5A2BB2CBABULL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 0x592F7E2E4F3A3EDCULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0x5BD68C0FC44EDF47ULL), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 0x378450BFA9B41C69ULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 0x8CEF445A1564C3A0ULL;
            aOrbiterK = RotL64((aOrbiterK * 0x8B90ABB07AB67417ULL), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 0x73216DD0D2DEC821ULL;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 0xAAD2C4F5F27F7123ULL) ^ aOUSaltA[((aIndex + 113U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 0x016146935BAE4809ULL), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 0xC5F48593C08BCFCAULL;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 0x0AC487AA4FE75EA3ULL;
            aOrbiterE = RotL64((aOrbiterE * 0xD66A9DE51BD27EC7ULL), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 0xA8630A2C0E3C05A4ULL;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 0x5D45E823AC720DF0ULL;
            aOrbiterI = RotL64((aOrbiterI * 0x5BC1D550C05FB8CBULL), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 0x8F09F39E8B54964CULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 0x2613E4DD4F0E225DULL;
            aOrbiterA = RotL64((aOrbiterA * 0x0CFBE03B2D55DD29ULL), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 0xCDA5B9CD3E47DDC4ULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 0x12A553C7A1E02B1BULL;
            aOrbiterD = RotL64((aOrbiterD * 0xD0F586578A57799DULL), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 0x48B16EBBD39C95F5ULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 0x9BA24B0E1569F23BULL;
            aOrbiterG = RotL64((aOrbiterG * 0x57B4E03E96A6C4FBULL), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 0x8E513BC367099A43ULL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 0x0CA5B0B0724B570FULL) ^ aOUSaltG[(((511U - aIndex) + 250U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 0x9BBD5D634CBA0361ULL), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 0xAFB167EDDA9F8297ULL) + aOUSaltD[((aIndex + 231U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 0x7B634F4C9E1A95CFULL) ^ aOUSaltE[((aIndex + 295U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 0x609BFB3C74A207C1ULL), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 0x2D32E39D2EF5AF03ULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 0xEE80B687F3BCC5EEULL;
            aOrbiterF = RotL64((aOrbiterF * 0xF9CF0123C2EACA79ULL), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 11U);
            aIngress = aIngress + (RotL64(aOrbiterB, 56U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterG, 42U)) + aOrbiterB) + aWUSaltE[(((511U - aIndex) + 125U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 53U)) + aOrbiterC) + aWUSaltF[((aIndex + 333U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 18U) + aOrbiterC) + RotL64(aOrbiterE, 21U)) + aWUSaltA[((aIndex + 229U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 11U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterJ, 40U));
            aWandererH = aWandererH + (((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 3U)) + aOrbiterG) + aWUSaltC[(((511U - aIndex) + 453U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 57U)) + aOrbiterI) + aWUSaltH[(((511U - aIndex) + 418U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 48U) + aOrbiterJ) + RotL64(aOrbiterD, 13U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterD, 29U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 51U)) + aOrbiterK) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterA, 27U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 52U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aArcaneLaneD_A[((2047U - aIndex)) & W_KEY1] = aIngress;
        }
    }
    // GROW_A_A grow_a_loop_a (end)
    WRITE_OUT_MUTABLE_PARAMS;
}

void TwistExpander_Aldebaran_Arx::GROW_A_B(TwistWorkSpace *pWorkSpace,
                     MUTABLE_PARAMS) {
    std::uint8_t *aSpiritLaneA = pWorkSpace->mSpiritLaneA;
    std::uint8_t *aSpiritLaneB = pWorkSpace->mSpiritLaneB;
    std::uint8_t *aSpiritLaneC = pWorkSpace->mSpiritLaneC;
    std::uint8_t *aSpiritLaneD = pWorkSpace->mSpiritLaneD;
    std::uint8_t *aPlasmaLaneA = pWorkSpace->mPlasmaLaneA;
    std::uint8_t *aPlasmaLaneB = pWorkSpace->mPlasmaLaneB;
    std::uint8_t *aPlasmaLaneC = pWorkSpace->mPlasmaLaneC;
    std::uint8_t *aPlasmaLaneD = pWorkSpace->mPlasmaLaneD;
    std::uint8_t *aArcaneLaneA = pWorkSpace->mArcaneLaneA;
    std::uint8_t *aArcaneLaneB = pWorkSpace->mArcaneLaneB;
    std::uint8_t *aArcaneLaneC = pWorkSpace->mArcaneLaneC;
    std::uint8_t *aArcaneLaneD = pWorkSpace->mArcaneLaneD;
    std::uint64_t *aOASaltA = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltA;
    std::uint64_t *aOASaltB = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltB;
    std::uint64_t *aOASaltC = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltC;
    std::uint64_t *aOASaltD = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltD;
    std::uint64_t *aOASaltE = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltE;
    std::uint64_t *aOASaltF = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltF;
    std::uint64_t *aOASaltG = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltG;
    std::uint64_t *aOASaltH = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltH;
    std::uint64_t *aOUSaltA = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltA;
    std::uint64_t *aOUSaltB = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltB;
    std::uint64_t *aOUSaltC = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltC;
    std::uint64_t *aOUSaltD = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltD;
    std::uint64_t *aOUSaltE = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltE;
    std::uint64_t *aOUSaltF = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltF;
    std::uint64_t *aOUSaltG = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltG;
    std::uint64_t *aOUSaltH = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltH;
    std::uint64_t *aWUSaltA = pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltA;
    std::uint64_t *aWUSaltB = pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltB;
    std::uint64_t *aWUSaltC = pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltC;
    std::uint64_t *aWUSaltD = pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltD;
    std::uint64_t *aWUSaltE = pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltE;
    std::uint64_t *aWUSaltF = pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltF;
    std::uint64_t *aWUSaltG = pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltG;
    std::uint64_t *aWUSaltH = pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltH;
    std::uint8_t *aArcaneLaneA_A = aArcaneLaneA + (W_KEY * 0U);
    std::uint8_t *aArcaneLaneB_A = aArcaneLaneB + (W_KEY * 0U);
    std::uint8_t *aArcaneLaneC_A = aArcaneLaneC + (W_KEY * 0U);
    std::uint8_t *aArcaneLaneD_A = aArcaneLaneD + (W_KEY * 0U);
    std::uint8_t *aSpiritLaneA_A = aSpiritLaneA + (W_KEY * 0U);
    std::uint8_t *aSpiritLaneB_A = aSpiritLaneB + (W_KEY * 0U);
    std::uint8_t *aSpiritLaneC_A = aSpiritLaneC + (W_KEY * 0U);
    std::uint8_t *aSpiritLaneD_A = aSpiritLaneD + (W_KEY * 0U);
    std::uint8_t *aPlasmaLaneA_A = aPlasmaLaneA + (W_KEY * 0U);
    std::uint8_t *aPlasmaLaneB_A = aPlasmaLaneB + (W_KEY * 0U);
    std::uint8_t *aPlasmaLaneC_A = aPlasmaLaneC + (W_KEY * 0U);
    std::uint8_t *aPlasmaLaneD_A = aPlasmaLaneD + (W_KEY * 0U);
    const std::uint64_t &aKeyRotateADomainWordIngress = pWorkSpace->mDomainBundle.mKeyRotateAConstants.mIngress;
    const std::uint64_t &aKeyRotateADomainWordScatter = pWorkSpace->mDomainBundle.mKeyRotateAConstants.mScatter;
    const std::uint64_t &aKeyRotateADomainWordCross = pWorkSpace->mDomainBundle.mKeyRotateAConstants.mCross;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [grow arx]
    READ_IN_MUTABLE_PARAMS;
    // GROW_A_B grow_a_loop_b (start)
    {
        //
        // File: nexus_02/loop_000214.bin
        //
        // Head:        [9, 4, 7, 6, 2, 1, 8, 0, 3, 10, 5]
        // Tail A:      [2, 0, 10, 3, 6, 5, 7, 4, 9, 1, 8]
        // Tail B:      [8, 9, 0, 6, 10, 7, 2, 1, 5, 3, 4]
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
        // Orbiters:    [ADGKIBHCEJF]
        // Wanderers:   [DIAFGJECKBH]
        //
        // Ingress:     aArcaneLaneD (-->), aArcaneLaneB (-->), aSpiritLaneB (<-?->)
        //
        // Cross:       aArcaneLaneC (<--), aArcaneLaneA (<--), aSpiritLaneC (<-?->)
        //
        // Destination: aPlasmaLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aArcaneLaneD_A[((aIndex + 945U)) & W_KEY1], 12U) ^ RotL64(aArcaneLaneB_A[((aIndex + 418U)) & W_KEY1], 23U));
            aIngress ^= RotL64(aSpiritLaneB_A[((aIndex + 411U)) & W_KEY1], 53U);
            aIngress = TwistMix64::DiffuseB((aIngress ^ aKeyRotateADomainWordIngress));
            //
            aCross = (RotL64(aArcaneLaneC_A[(((2047U - aIndex) + 967U)) & W_KEY1], 39U) ^ RotL64(aArcaneLaneA_A[(((2047U - aIndex) + 1892U)) & W_KEY1], 28U));
            aCross ^= RotL64(aSpiritLaneC_A[(((2047U - aIndex) + 220U)) & W_KEY1], 3U);
            aCross = TwistMix64::DiffuseA((aCross ^ aKeyRotateADomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 39U) + RotL64(aCarry, 20U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aKeyRotateADomainWordScatter));
            //
            aOrbiterA = (aWandererB + RotL64(aIngress, 53U)) + 0x999CDD5D8B6ED78AULL;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 39U)) + 0x15986CD231B23256ULL;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 57U)) + 0xB9838D2DA7A1F0A0ULL;
            aOrbiterK = (aWandererE + RotL64(aCross, 39U)) + 0x45B3C970D3383A7BULL;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 50U)) + RotL64(aCarry, 3U)) + 0x584CA305B4D29C19ULL;
            aOrbiterB = (aWandererI + RotL64(aScatter, 23U)) + 0x5D35285954D92B96ULL;
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 13U)) + 0x7D3CA3E08B7D70D1ULL) + aOASaltF[(((511U - aIndex) + 100U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aCross, 35U)) + 0x713B5CD84624C112ULL) + aOASaltB[((aIndex + 308U)) & S_SALT1];
            aOrbiterE = (((aWandererF + RotL64(aIngress, 46U)) + RotL64(aCarry, 57U)) + 0x7EE7753957EE1C8EULL) + aOASaltC[((aIndex + 317U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 27U)) + 0x94D4CF8963967BB3ULL) + aOASaltH[(((511U - aIndex) + 274U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 37U)) + 0x88E6B49AF8CDA78BULL;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 0x6CEC1EEA1835AE49ULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 0x3722681C9623E612ULL;
            aOrbiterG = RotL64((aOrbiterG * 0x33E43D24E941B80FULL), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 0x8CE58D466747A0F2ULL;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 0x1E94B82D0C55C5D2ULL;
            aOrbiterB = RotL64((aOrbiterB * 0x582A2EBB164F3955ULL), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 0x7CF351C93CCCD940ULL) + aOUSaltG[((aIndex + 127U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 0xBCFE50F7487BF392ULL) ^ aOUSaltA[(((511U - aIndex) + 290U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 0x5616A0A630B0DAE7ULL), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 0xEEC72FE304C0F1B1ULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 0x20B2726759B61F6BULL;
            aOrbiterD = RotL64((aOrbiterD * 0xF693C88B6FEB763BULL), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 0x02A494E735AE8AC3ULL) + aOUSaltD[((aIndex + 455U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 0xC39742C4CECEB7CCULL;
            aOrbiterI = RotL64((aOrbiterI * 0xD8BCACFACDA7E5A7ULL), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 0x2093C961A676EAFDULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 0xC0DF39960EE6AA2CULL;
            aOrbiterA = RotL64((aOrbiterA * 0xC97EF62470A4F90DULL), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 0xF7947D479F8CA627ULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 0x7C365CCCD9BF5A6EULL;
            aOrbiterK = RotL64((aOrbiterK * 0xF13A71E1CF5D6ED7ULL), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 0x1F33D0B6578477E2ULL;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 0xF2E8ECB9943D1BD4ULL;
            aOrbiterH = RotL64((aOrbiterH * 0x371DA616DC15F2B3ULL), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 0xA7D9F97AB5EEB9AFULL) + aOUSaltB[((aIndex + 43U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 0x9FDAB5491B48F126ULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0xE0AE5D518281AD57ULL), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 0xA9BC4D514AF9350FULL;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 0x72764B8B136D6870ULL;
            aOrbiterE = RotL64((aOrbiterE * 0x6D647ACD3A2A27D1ULL), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 0x73A3E32D0BC5916CULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 0xD88F148FCF3BB584ULL;
            aOrbiterF = RotL64((aOrbiterF * 0x1DFB145F05B7193DULL), 27U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 39U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 50U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterE, 41U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 19U)) + aOrbiterA);
            aWandererF = aWandererF ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterK, 43U)) + aOrbiterH) + aWUSaltA[(((511U - aIndex) + 88U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 42U) + aOrbiterH) + RotL64(aOrbiterF, 35U)) + aWUSaltF[(((511U - aIndex) + 353U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 56U)) + aOrbiterC);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 27U)) + aOrbiterG) + RotL64(aCarry, 35U)) + aWUSaltE[(((511U - aIndex) + 107U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterD, 23U)) + aWUSaltH[(((511U - aIndex) + 93U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterB, 51U)) + aWUSaltG[(((511U - aIndex) + 505U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterK, 39U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterE, 6U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 14U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 4U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aPlasmaLaneA_A[(aIndex) & W_KEY1] = aIngress;
        }
    
        //
        // File: nexus_09/loop_000416.bin
        //
        // Head:        [5, 6, 2, 10, 9, 3, 1, 0, 4, 8, 7]
        // Tail A:      [9, 2, 3, 4, 6, 5, 10, 7, 0, 8, 1]
        // Tail B:      [4, 7, 6, 2, 9, 8, 3, 0, 5, 1, 10]
        //
        // Heart:       [{ 0, 1, 2 },
        //               { 3, 4, 5 },
        //               { 6, 7, 8 },
        //               { 5, 2, 9 },
        //               { 10, 8, 0 },
        //               { 1, 6, 4 },
        //               { 9, 0, 3 },
        //               { 7, 5, 1 },
        //               { 2, 3, 10 },
        //               { 8, 9, 7 },
        //               { 4, 10, 6 }]
        //
        // Orbiters:    [DIJCEKAHGBF]
        // Wanderers:   [ECKIJHBDGFA]
        //
        // Ingress:     aPlasmaLaneA (-->), aArcaneLaneC (-->), aSpiritLaneD (<-?->)
        //
        // Cross:       aArcaneLaneD (<--), aArcaneLaneB (<--), aSpiritLaneA (<-?->)
        //
        // Destination: aPlasmaLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aPlasmaLaneA_A[((aIndex + 94U)) & W_KEY1], 47U) ^ RotL64(aArcaneLaneC_A[((aIndex + 1807U)) & W_KEY1], 3U));
            aIngress ^= RotL64(aSpiritLaneD_A[((aIndex + 1634U)) & W_KEY1], 28U);
            aIngress = TwistMix64::DiffuseA((aIngress ^ aKeyRotateADomainWordIngress));
            //
            aCross = (RotL64(aArcaneLaneD_A[(((2047U - aIndex) + 874U)) & W_KEY1], 57U) ^ RotL64(aArcaneLaneB_A[(((2047U - aIndex) + 339U)) & W_KEY1], 43U));
            aCross ^= RotL64(aSpiritLaneA_A[(((2047U - aIndex) + 1353U)) & W_KEY1], 26U);
            aCross = TwistMix64::DiffuseC((aCross ^ aKeyRotateADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 23U)) ^ (RotL64(aPrevious, 6U) + RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aKeyRotateADomainWordScatter));
            //
            aOrbiterD = (aWandererH + RotL64(aScatter, 51U)) + 0x76911F9B051DD14EULL;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 11U)) + 0x1251E6D40F8678AFULL) + aOASaltE[((aIndex + 190U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 37U)) + 0x573BD7EFD080B3CBULL;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 43U)) + 0xA44E3F31255EF867ULL) + aOASaltA[((aIndex + 478U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aScatter, 21U)) + 0x701209D1E6144884ULL;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 27U)) + RotL64(aCarry, 43U)) + 0x9AF74260F3572B4BULL;
            aOrbiterA = (aWandererC + RotL64(aCross, 6U)) + 0x9B328DD03D05AE56ULL;
            aOrbiterH = (aWandererE + RotL64(aIngress, 41U)) + 0x7252336A34C7588EULL;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 29U)) + 0x04F2F763A5EA199EULL) + aOASaltG[((aIndex + 325U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 39U)) + RotL64(aCarry, 21U)) + 0xD704D998AA5692FAULL;
            aOrbiterF = ((aWandererD + RotL64(aCross, 56U)) + 0xDE7F29925DB96481ULL) + aOASaltF[((aIndex + 192U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 0xE77773B14EDB17CDULL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 0xA43CE89CCFDBA999ULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0x524D1E229A3B1763ULL), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 0x33D6D223CB475C27ULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 0xF8237E1FB2E0EB3CULL;
            aOrbiterK = RotL64((aOrbiterK * 0xA709BAF6ADDF850BULL), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 0xCE6D58B484ECFA73ULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 0x8E66DF70DE77097AULL;
            aOrbiterG = RotL64((aOrbiterG * 0x98B2C6E7E053DA5DULL), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 0x2F0A0F8DE1C77E2BULL) + aOUSaltB[((aIndex + 340U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 0xBAEBE510B8A8D8B1ULL;
            aOrbiterB = RotL64((aOrbiterB * 0xA0EAAE654FCBF94BULL), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 0x42A7D98209D7E9F8ULL;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 0xA436E43892B3C91BULL) ^ aOUSaltC[(((511U - aIndex) + 319U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 0xEB59E1E20CE95B2FULL), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 0xF8270AB0CFB08C5AULL;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 0x6989212D0CE03286ULL;
            aOrbiterE = RotL64((aOrbiterE * 0x1D7F4E8B7015E787ULL), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 0x3EED7F3966B66DF8ULL;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 0x7B106AAF989BF0E7ULL;
            aOrbiterC = RotL64((aOrbiterC * 0x5795B63B0A78CAE7ULL), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 0x0C62B2688B84F311ULL) + aOUSaltE[((aIndex + 67U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 0x36C6DF382A836EE7ULL;
            aOrbiterI = RotL64((aOrbiterI * 0xAF4542CE0833C4E3ULL), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 0x458E46C326873591ULL;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 0x8C34D4BF09E502AFULL) ^ aOUSaltF[(((511U - aIndex) + 373U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 0x520FCA8BAAE33E79ULL), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 0x09B42D60F16666B7ULL) + aOUSaltG[(((511U - aIndex) + 69U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 0x1C62F522DC0424AEULL;
            aOrbiterH = RotL64((aOrbiterH * 0xCB876E9EFE40C48DULL), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 0x6AF2892334B83CB3ULL;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 0x3181EA9D5E552675ULL) ^ aOUSaltH[(((511U - aIndex) + 443U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 0x335DD8E7B9D6B973ULL), 57U);
            //
            aIngress = RotL64(aOrbiterG, 5U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterI, 48U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 37U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterH, 26U)) + aWUSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 51U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aCross, 4U) + RotL64(aOrbiterE, 21U)) + aOrbiterJ) + aWUSaltD[((aIndex + 242U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 5U));
            aWandererH = aWandererH + ((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 13U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 41U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterD, 28U)) + aWUSaltG[(((511U - aIndex) + 246U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 3U)) + aOrbiterK) + aWUSaltE[(((511U - aIndex) + 195U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 44U) + aOrbiterG) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 35U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 26U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 56U));
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aPlasmaLaneB_A[((2047U - aIndex)) & W_KEY1] = aIngress;
        }
    
        //
        // File: nexus_01/loop_000296.bin
        //
        // Head:        [1, 6, 8, 0, 5, 9, 10, 2, 4, 7, 3]
        // Tail A:      [1, 7, 8, 2, 5, 0, 3, 4, 6, 10, 9]
        // Tail B:      [7, 3, 6, 8, 0, 10, 9, 5, 4, 1, 2]
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
        // Orbiters:    [BJKCFHIAEDG]
        // Wanderers:   [GIBDEFJCAKH]
        //
        // Ingress:     aPlasmaLaneB (-->), aArcaneLaneD (-->)
        //
        // Cross:       aPlasmaLaneA (<--), aArcaneLaneC (<--)
        //
        // Destination: aPlasmaLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aPlasmaLaneB_A[((aIndex + 374U)) & W_KEY1], 21U) ^ RotL64(aArcaneLaneD_A[((aIndex + 1625U)) & W_KEY1], 56U);
            aIngress = TwistMix64::DiffuseC((aIngress ^ aKeyRotateADomainWordIngress));
            //
            aCross = RotL64(aPlasmaLaneA_A[(((2047U - aIndex) + 1121U)) & W_KEY1], 58U) ^ RotL64(aArcaneLaneC_A[(((2047U - aIndex) + 1485U)) & W_KEY1], 13U);
            aCross = TwistMix64::DiffuseB((aCross ^ aKeyRotateADomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCarry, 40U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aKeyRotateADomainWordScatter));
            //
            aOrbiterB = (aWandererI + RotL64(aPrevious, 54U)) + 0xC6DEB323AE788484ULL;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 21U)) + 0xA1145A368BADEAE5ULL) + aOASaltE[((aIndex + 310U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aIngress, 3U)) + 0xAFD306EF87AAC919ULL) + aOASaltA[((aIndex + 429U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 51U)) + 0xDF7ACE0F603FA84CULL;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 51U)) + 0xBA1C8EBECC88B5B6ULL;
            aOrbiterH = (aWandererK + RotL64(aCross, 36U)) + 0xA908E5B59F1BB41FULL;
            aOrbiterI = (((aWandererH + RotL64(aIngress, 41U)) + RotL64(aCarry, 13U)) + 0x82841EE064A86170ULL) + aOASaltC[((aIndex + 103U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aScatter, 39U)) + 0x0C48CAA17BACD3B2ULL;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 23U)) + 0x7EF7AC45BA43DA33ULL;
            aOrbiterD = ((aWandererC + RotL64(aCross, 19U)) + 0xB3B99D6610F8AD0DULL) + aOASaltD[(((511U - aIndex) + 236U)) & S_SALT1];
            aOrbiterG = (((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 0x83820F61718F3279ULL) + aOASaltG[(((511U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 0xBE952B936D24A6ADULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 0xE7E725AFD79FB1CCULL;
            aOrbiterK = RotL64((aOrbiterK * 0x457E592140E54995ULL), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 0xF6E2EA6AE48B4775ULL;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 0x70F33B3EF9DB10D8ULL;
            aOrbiterH = RotL64((aOrbiterH * 0xDB8ACA35D1A462A9ULL), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 0x1183F2322737CA99ULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 0xE9C0C8AAD8718AD5ULL;
            aOrbiterA = RotL64((aOrbiterA * 0x752C05B01C564F61ULL), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 0xB3F81A388AA7D95AULL;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 0xFDA21EA1A0AAC9CEULL) ^ aOUSaltA[((aIndex + 255U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 0x3AF5E4DA9B2391D9ULL), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 0x3ED0168A1B270CE4ULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 0xF07F776F9563034CULL;
            aOrbiterG = RotL64((aOrbiterG * 0x51DAF71A378FC8EFULL), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 0xBA0D58E323F1F1EAULL) + aOUSaltH[((aIndex + 279U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 0xBC6D13B45E9FD437ULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0xBDD8C73C5370D641ULL), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 0x54374E56FC9AD390ULL;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 0xCE9AA2995F165B44ULL;
            aOrbiterI = RotL64((aOrbiterI * 0x5C8B4F88631F0C47ULL), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 0xC0911C3146B9187BULL;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 0xA08DFC2DC406B7C2ULL) ^ aOUSaltB[(((511U - aIndex) + 166U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 0xBC5BCA3E48A30EC3ULL), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 0x1D2CF1ED28AB30C7ULL) + aOUSaltE[(((511U - aIndex) + 99U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 0x487405F461CEDB65ULL;
            aOrbiterE = RotL64((aOrbiterE * 0x49FD75FDD0D21F59ULL), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 0x83223DE5095A1704ULL;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 0x355095CAA3545D52ULL;
            aOrbiterB = RotL64((aOrbiterB * 0xF411C482B28B5395ULL), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 0x4CA0BAD022CE0D83ULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 0xF44B3E6FA4AC12DBULL;
            aOrbiterF = RotL64((aOrbiterF * 0xD8ACD30F0526462DULL), 51U);
            //
            aIngress = RotL64(aOrbiterG, 27U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 36U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterA, 47U));
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 58U) + RotL64(aOrbiterA, 37U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aWUSaltD[((aIndex + 293U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 5U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterK, 53U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterB, 24U)) + aWUSaltG[(((511U - aIndex) + 86U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 3U)) + aOrbiterG) + aWUSaltE[(((511U - aIndex) + 317U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 29U)) + aOrbiterD);
            aWandererC = aWandererC ^ (((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA + ((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterF, 39U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 57U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aPrevious, 46U) + RotL64(aOrbiterD, 22U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 52U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aPlasmaLaneC_A[(aIndex) & W_KEY1] = aIngress;
        }
    
        //
        // File: nexus_06/loop_000618.bin
        //
        // Head:        [5, 2, 9, 8, 4, 10, 3, 6, 7, 1, 0]
        // Tail A:      [2, 0, 8, 10, 9, 1, 6, 3, 4, 5, 7]
        // Tail B:      [5, 10, 3, 1, 6, 9, 4, 2, 7, 0, 8]
        //
        // Heart:       [{ 0, 1, 2 },
        //               { 3, 4, 5 },
        //               { 6, 0, 7 },
        //               { 8, 5, 9 },
        //               { 10, 2, 3 },
        //               { 7, 9, 1 },
        //               { 4, 8, 0 },
        //               { 1, 3, 6 },
        //               { 5, 7, 10 },
        //               { 2, 6, 8 },
        //               { 9, 10, 4 }]
        //
        // Orbiters:    [KCJBEADIGHF]
        // Wanderers:   [JKAGEHIFDCB]
        //
        // Ingress:     aPlasmaLaneC (-->), aPlasmaLaneA (<-?->)
        //
        // Cross:       aPlasmaLaneB (<--), aArcaneLaneD (<-?->)
        //
        // Destination: aPlasmaLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aPlasmaLaneC_A[((aIndex + 859U)) & W_KEY1], 27U) ^ RotL64(aPlasmaLaneA_A[(((2047U - aIndex) + 776U)) & W_KEY1], 40U);
            aIngress = TwistMix64::DiffuseA((aIngress ^ aKeyRotateADomainWordIngress));
            //
            aCross = RotL64(aPlasmaLaneB_A[(((2047U - aIndex) + 1189U)) & W_KEY1], 37U) ^ RotL64(aArcaneLaneD_A[((aIndex + 1028U)) & W_KEY1], 6U);
            aCross = TwistMix64::DiffuseA((aCross ^ aKeyRotateADomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 23U)) + (RotL64(aCarry, 42U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aKeyRotateADomainWordScatter));
            //
            aOrbiterK = (((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 0xA3E636BB911ED208ULL) + aOASaltE[((aIndex + 334U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aIngress, 30U)) + 0x18B159B2C0BBC99EULL;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 57U)) + 0x269894D443DE621EULL;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 43U)) + 0xA7ECE91F8D01ECA4ULL) + aOASaltG[(((511U - aIndex) + 433U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 11U)) + 0x8AF27F27C1C851E8ULL;
            aOrbiterA = (aWandererB + RotL64(aIngress, 28U)) + 0xCA33B40B6B410F8BULL;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 47U)) + 0xDF4E3EEA549953F8ULL) + aOASaltH[(((511U - aIndex) + 383U)) & S_SALT1];
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 53U)) + RotL64(aCarry, 53U)) + 0x17AEF7109AF1CC9DULL) + aOASaltB[((aIndex + 247U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aCross, 37U)) + 0x97A2C5EF358D9748ULL;
            aOrbiterH = (aWandererK + RotL64(aIngress, 19U)) + 0x3F9098B5AE7F0A2EULL;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 11U)) + 0x5207F55991E046C8ULL;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 0xADDC0707B103731FULL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 0xC1E8B0E899ACAB0CULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0x58C7C673D7E6B30BULL), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 0xCAB8F7041A93EC53ULL) + aOUSaltA[((aIndex + 186U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 0x1F8C74277D23953EULL;
            aOrbiterA = RotL64((aOrbiterA * 0xD9F5BC4289175193ULL), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 0x9F9363583C1B6206ULL;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 0xD977D89DEB0A84D5ULL;
            aOrbiterI = RotL64((aOrbiterI * 0xA62644DF4B0EAC7DULL), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 0xC649B0578A226B26ULL;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 0x21810899F5957B7BULL;
            aOrbiterH = RotL64((aOrbiterH * 0xA8CE16076CC5958DULL), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 0xDF7C7B5B8B6835C7ULL;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 0xED422838584CA278ULL;
            aOrbiterB = RotL64((aOrbiterB * 0x0BEAA4B890B1856FULL), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 0xF35C5A2127D1501CULL;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 0xDE2B7CA1D3C428E3ULL;
            aOrbiterC = RotL64((aOrbiterC * 0xEC0BD3450ADFAA4BULL), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 0x079EC40A977AAD1CULL;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 0xD7B98D27479CF979ULL) ^ aOUSaltB[(((511U - aIndex) + 162U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 0x62B93416AB1581C3ULL), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 0xBE608D975584BD0BULL) + aOUSaltC[(((511U - aIndex) + 117U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 0xAE5E95155F77173BULL;
            aOrbiterD = RotL64((aOrbiterD * 0xB64724C5D948428FULL), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 0x7DB63255C9106CA8ULL;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 0xB964E42DA35A3A40ULL) ^ aOUSaltH[((aIndex + 381U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 0x2A6DB42899A56413ULL), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 0x66126B4AD23B3A1BULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 0xBEBC1A37D81ED72CULL;
            aOrbiterG = RotL64((aOrbiterG * 0x1C07AC25F45AE413ULL), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 0xC516540F038EF080ULL;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 0xBCD5E2438A565091ULL;
            aOrbiterE = RotL64((aOrbiterE * 0x49298E95D5E7CA5BULL), 41U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 14U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterJ, 57U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 13U)) + aOrbiterF);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 29U)) + aOrbiterB) + aWUSaltG[(((511U - aIndex) + 71U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 3U) + RotL64(aOrbiterF, 6U)) + aOrbiterC);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 43U));
            aWandererH = aWandererH + (((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 47U)) + aOrbiterH) + aWUSaltA[(((511U - aIndex) + 415U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 21U)) + aOrbiterE) + aWUSaltF[((aIndex + 228U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 41U) + aOrbiterB) + RotL64(aOrbiterJ, 27U)) + aWUSaltC[((aIndex + 377U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 56U) + RotL64(aOrbiterE, 35U)) + aOrbiterI) + aWUSaltB[(((511U - aIndex) + 63U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 37U)) + aOrbiterK);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 4U)) + aOrbiterG) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 20U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aPlasmaLaneD_A[((2047U - aIndex)) & W_KEY1] = aIngress;
        }
    }
    // GROW_A_B grow_a_loop_b (end)
    WRITE_OUT_MUTABLE_PARAMS;
}

void TwistExpander_Aldebaran_Arx::GROW_A_C(TwistWorkSpace *pWorkSpace,
                     MUTABLE_PARAMS) {
    std::uint8_t *aWaterLaneA = pWorkSpace->mWaterLaneA;
    std::uint8_t *aWaterLaneB = pWorkSpace->mWaterLaneB;
    std::uint8_t *aWaterLaneC = pWorkSpace->mWaterLaneC;
    std::uint8_t *aWaterLaneD = pWorkSpace->mWaterLaneD;
    std::uint8_t *aRainbowLaneA = pWorkSpace->mRainbowLaneA;
    std::uint8_t *aRainbowLaneB = pWorkSpace->mRainbowLaneB;
    std::uint8_t *aRainbowLaneC = pWorkSpace->mRainbowLaneC;
    std::uint8_t *aRainbowLaneD = pWorkSpace->mRainbowLaneD;
    std::uint8_t *aArcaneLaneC = pWorkSpace->mArcaneLaneC;
    std::uint8_t *aArcaneLaneD = pWorkSpace->mArcaneLaneD;
    std::uint64_t *aOASaltA = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltA;
    std::uint64_t *aOASaltB = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltB;
    std::uint64_t *aOASaltC = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltC;
    std::uint64_t *aOASaltD = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltD;
    std::uint64_t *aOASaltE = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltE;
    std::uint64_t *aOASaltF = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltF;
    std::uint64_t *aOASaltG = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltG;
    std::uint64_t *aOASaltH = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltH;
    std::uint64_t *aOUSaltA = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltA;
    std::uint64_t *aOUSaltB = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltB;
    std::uint64_t *aOUSaltC = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltC;
    std::uint64_t *aOUSaltD = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltD;
    std::uint64_t *aOUSaltE = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltE;
    std::uint64_t *aOUSaltF = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltF;
    std::uint64_t *aOUSaltG = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltG;
    std::uint64_t *aOUSaltH = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltH;
    std::uint64_t *aWUSaltA = pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltA;
    std::uint64_t *aWUSaltB = pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltB;
    std::uint64_t *aWUSaltC = pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltC;
    std::uint64_t *aWUSaltD = pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltD;
    std::uint64_t *aWUSaltE = pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltE;
    std::uint64_t *aWUSaltF = pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltF;
    std::uint64_t *aWUSaltG = pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltG;
    std::uint64_t *aWUSaltH = pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltH;
    std::uint8_t *aArcaneLaneC_A = aArcaneLaneC + (W_KEY * 0U);
    std::uint8_t *aArcaneLaneD_A = aArcaneLaneD + (W_KEY * 0U);
    std::uint8_t *aRainbowLaneA_A = aRainbowLaneA + (W_KEY * 0U);
    std::uint8_t *aRainbowLaneB_A = aRainbowLaneB + (W_KEY * 0U);
    std::uint8_t *aRainbowLaneC_A = aRainbowLaneC + (W_KEY * 0U);
    std::uint8_t *aRainbowLaneD_A = aRainbowLaneD + (W_KEY * 0U);
    std::uint8_t *aWaterLaneA_A = aWaterLaneA + (W_KEY * 0U);
    std::uint8_t *aWaterLaneB_A = aWaterLaneB + (W_KEY * 0U);
    std::uint8_t *aWaterLaneC_A = aWaterLaneC + (W_KEY * 0U);
    std::uint8_t *aWaterLaneD_A = aWaterLaneD + (W_KEY * 0U);
    const std::uint64_t &aKeyRotateADomainWordIngress = pWorkSpace->mDomainBundle.mKeyRotateAConstants.mIngress;
    const std::uint64_t &aKeyRotateADomainWordScatter = pWorkSpace->mDomainBundle.mKeyRotateAConstants.mScatter;
    const std::uint64_t &aKeyRotateADomainWordCross = pWorkSpace->mDomainBundle.mKeyRotateAConstants.mCross;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [grow arx]
    READ_IN_MUTABLE_PARAMS;
    // GROW_A_C grow_a_loop_c (start)
    {
        //
        // File: nexus_02/loop_000237.bin
        //
        // Head:        [8, 6, 4, 9, 10, 0, 5, 2, 3, 7, 1]
        // Tail A:      [7, 0, 8, 6, 4, 9, 2, 5, 1, 10, 3]
        // Tail B:      [10, 8, 3, 9, 5, 4, 7, 2, 6, 0, 1]
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
        // Orbiters:    [AKCGBFEDJIH]
        // Wanderers:   [FHBJDKGAICE]
        //
        // Ingress:     aRainbowLaneA (-->), aRainbowLaneB (-->), aArcaneLaneD (<-?->)
        //
        // Cross:       aRainbowLaneC (<--), aRainbowLaneD (<--)
        //
        // Destination: aWaterLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aRainbowLaneA_A[((aIndex + 1792U)) & W_KEY1], 29U) ^ RotL64(aRainbowLaneB_A[((aIndex + 1588U)) & W_KEY1], 10U));
            aIngress ^= RotL64(aArcaneLaneD_A[(((2047U - aIndex) + 1224U)) & W_KEY1], 21U);
            aIngress = TwistMix64::DiffuseC((aIngress ^ aKeyRotateADomainWordIngress));
            //
            aCross = RotL64(aRainbowLaneC_A[(((2047U - aIndex) + 1907U)) & W_KEY1], 42U) ^ RotL64(aRainbowLaneD_A[(((2047U - aIndex) + 985U)) & W_KEY1], 21U);
            aCross = TwistMix64::DiffuseB((aCross ^ aKeyRotateADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 4U) + RotL64(aCross, 35U)) ^ (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aKeyRotateADomainWordScatter));
            //
            aOrbiterA = (aWandererI + RotL64(aIngress, 60U)) + 0xA4275628A3BD26CCULL;
            aOrbiterK = (((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 41U)) + 0x9060B9C536DAAD9FULL) + aOASaltF[(((511U - aIndex) + 465U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aPrevious, 27U)) + 0x24BF1B26DDF4BF6AULL;
            aOrbiterG = ((aWandererC + RotL64(aCross, 3U)) + 0xD394AD6270759C39ULL) + aOASaltE[((aIndex + 193U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aIngress, 43U)) + 0xE3ABF70B8C7AE2A8ULL) + aOASaltA[((aIndex + 281U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 23U)) + 0xB21EE5345C070FAAULL;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 19U)) + 0xF278ECA65AECE9A7ULL;
            aOrbiterD = ((aWandererB + RotL64(aCross, 35U)) + 0xC9F16D0A81E59EC3ULL) + aOASaltD[((aIndex + 238U)) & S_SALT1];
            aOrbiterJ = (((aWandererJ + RotL64(aIngress, 40U)) + RotL64(aCarry, 47U)) + 0x5D0BDC5EF09B17ABULL) + aOASaltG[(((511U - aIndex) + 331U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aScatter, 23U)) + 0x5D99D04334436E20ULL;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 53U)) + 0xC98C5115DE891B81ULL;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 0x58F23D3C63673E86ULL;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 0xF088B816723A703EULL;
            aOrbiterC = RotL64((aOrbiterC * 0x369A4228E1AF966DULL), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 0x75BB192C68949BF0ULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 0x122DB3124E698B12ULL;
            aOrbiterF = RotL64((aOrbiterF * 0x5BD9E9DB84D31D0BULL), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 0x16AE2052CEA07AE5ULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 0x10F07B52A298F156ULL;
            aOrbiterD = RotL64((aOrbiterD * 0x0CDAD38F6A33BEF5ULL), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 0x6B63B67445F80C0FULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 0x692ECA535B6C4BE1ULL;
            aOrbiterK = RotL64((aOrbiterK * 0xCF8C68D82C56C469ULL), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 0x1D50B1FD8AB23F7EULL) + aOUSaltF[(((511U - aIndex) + 40U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 0x439593E158A93308ULL;
            aOrbiterB = RotL64((aOrbiterB * 0x974E56819055B263ULL), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 0x5FDCE8D9985910F9ULL) + aOUSaltA[(((511U - aIndex) + 149U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 0xC2A65277F02164B3ULL;
            aOrbiterA = RotL64((aOrbiterA * 0x8E360593B6F1BEEFULL), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 0xB3039230F1C7E05DULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 0xD4E56B9537026F06ULL;
            aOrbiterG = RotL64((aOrbiterG * 0x7B932346D8BE6D7BULL), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 0x4D04E91324E5434DULL) + aOUSaltE[((aIndex + 362U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 0x28BC9F029ECE3A42ULL;
            aOrbiterE = RotL64((aOrbiterE * 0xD7ABAF42F3E3EF25ULL), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 0xB32318E436414DF1ULL;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 0xAD629D59E5980BD1ULL) ^ aOUSaltD[((aIndex + 231U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 0x749BB2E44255C125ULL), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 0xD9E4DB2702B37F3EULL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 0x797298E1C0B6A99CULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0x5AD6D06573A20F0BULL), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 0x8A2337F0CF5E6A4DULL;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 0x1DE15A4D2663A810ULL;
            aOrbiterH = RotL64((aOrbiterH * 0xD59E6519BD0A4DE7ULL), 53U);
            //
            aIngress = RotL64(aOrbiterC, 37U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 54U));
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 20U) + aOrbiterD) + RotL64(aOrbiterH, 3U)) + aWUSaltB[(((511U - aIndex) + 142U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterJ, 47U)) + aWUSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterI, 11U));
            aWandererD = aWandererD + ((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 35U)) + aOrbiterF);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 29U)) + aOrbiterB) + aWUSaltD[((aIndex + 363U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 57U) + RotL64(aOrbiterC, 42U)) + aOrbiterD) + aWUSaltF[(((511U - aIndex) + 177U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI + ((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterE, 5U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterA, 39U));
            aWandererE = aWandererE + (((RotL64(aCross, 18U) + aOrbiterG) + RotL64(aOrbiterK, 18U)) + aWUSaltE[((aIndex + 445U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 36U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWaterLaneA_A[(aIndex) & W_KEY1] = aIngress;
        }
    
        //
        // File: nexus_01/loop_000180.bin
        //
        // Head:        [3, 1, 8, 9, 4, 0, 6, 10, 2, 7, 5]
        // Tail A:      [8, 7, 3, 2, 10, 5, 9, 4, 0, 6, 1]
        // Tail B:      [0, 3, 6, 8, 7, 1, 2, 5, 10, 4, 9]
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
        // Orbiters:    [GCFKJDIABHE]
        // Wanderers:   [DEGJCKAFBIH]
        //
        // Ingress:     aWaterLaneA (-->), aRainbowLaneC (-->)
        //
        // Cross:       aRainbowLaneA (<--), aRainbowLaneB (<--)
        //
        // Destination: aWaterLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aWaterLaneA_A[((aIndex + 995U)) & W_KEY1], 21U) ^ RotL64(aRainbowLaneC_A[((aIndex + 201U)) & W_KEY1], 6U);
            aIngress = TwistMix64::DiffuseB((aIngress ^ aKeyRotateADomainWordIngress));
            //
            aCross = RotL64(aRainbowLaneA_A[(((2047U - aIndex) + 323U)) & W_KEY1], 35U) ^ RotL64(aRainbowLaneB_A[(((2047U - aIndex) + 1667U)) & W_KEY1], 10U);
            aCross = TwistMix64::DiffuseB((aCross ^ aKeyRotateADomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 3U)) + (RotL64(aIngress, 53U) + RotL64(aCarry, 18U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aKeyRotateADomainWordScatter));
            //
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 21U)) + 0xB9EB382FB6E3ECD2ULL) + aOASaltF[(((511U - aIndex) + 444U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 41U)) + 0x6116EBC629CF2F74ULL) + aOASaltG[((aIndex + 129U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 0x86FA14624B68C93DULL;
            aOrbiterK = (aWandererI + RotL64(aIngress, 6U)) + 0x1F2C0CECA89A7263ULL;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 53U)) + 0xEE3404745859AC56ULL;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 47U)) + 0xA8620D8CEAB5A197ULL) + aOASaltE[((aIndex + 315U)) & S_SALT1];
            aOrbiterI = (((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 27U)) + 0x5259D35FC154179FULL) + aOASaltC[((aIndex + 271U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aIngress, 11U)) + 0xA4EB314348503D72ULL;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 23U)) + 0x1AD7DC293016EC42ULL) + aOASaltB[((aIndex + 464U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 21U)) + 0x82A18A8782060FCFULL;
            aOrbiterE = (aWandererK + RotL64(aCross, 18U)) + 0x7477DFCAB5FD6C4CULL;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 0xBA9710BED61754A4ULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 0xDC9701CCE1DD1AA3ULL;
            aOrbiterF = RotL64((aOrbiterF * 0x39499A8D866FEFC3ULL), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 0x11A9A1AEDFD05FAEULL;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 0x1BEB326B5510A1CFULL) ^ aOUSaltG[((aIndex + 137U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 0x62E5D246613679F5ULL), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 0x20890E349F1B1BCAULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 0xE64F8B0E0F6D56E5ULL;
            aOrbiterA = RotL64((aOrbiterA * 0x62172C8F1AD21ECDULL), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 0x39ABD4A1BC3DAA03ULL;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 0xDF842AC71386E309ULL;
            aOrbiterH = RotL64((aOrbiterH * 0xCCA22BA9DB66C80BULL), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 0xEF0FBB6DA05782E3ULL;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 0x06A47B1EE44314D3ULL;
            aOrbiterE = RotL64((aOrbiterE * 0xCAB04DE9CA930D4DULL), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 0x9A30132D88530B9AULL) + aOUSaltA[(((511U - aIndex) + 417U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 0x30F93690A3B23189ULL;
            aOrbiterC = RotL64((aOrbiterC * 0xBB80FB4AC8787E57ULL), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 0xAFB1149913D7CA4CULL;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 0xE066D52377D6BB24ULL;
            aOrbiterI = RotL64((aOrbiterI * 0x61F972AD8DACCFB5ULL), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 0x6C5B35413EA208F3ULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 0x79429B4984A94D47ULL;
            aOrbiterK = RotL64((aOrbiterK * 0x864BE58DB3038FE1ULL), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 0x110F0B26AFABD7E3ULL;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 0x30596D1D42AFDD78ULL;
            aOrbiterB = RotL64((aOrbiterB * 0x65D3C5E922140BCFULL), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 0xD37938723AF99871ULL) + aOUSaltE[(((511U - aIndex) + 320U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 0xA64C4FCF24F21B3DULL;
            aOrbiterG = RotL64((aOrbiterG * 0xBF37665A9F6CB6F7ULL), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 0xA9DE9F13EFE1A3A0ULL) + aOUSaltF[((aIndex + 30U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 0xDC644F26DA912C14ULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0x85858C55AC178EB1ULL), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 53U);
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 27U)) + aOrbiterG) + aWUSaltE[(((511U - aIndex) + 171U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterK, 19U)) + aWUSaltC[(((511U - aIndex) + 175U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterI, 23U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterB, 60U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 3U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 11U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 44U) + RotL64(aOrbiterH, 41U)) + aOrbiterF) + aWUSaltH[(((511U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterD, 39U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 29U)) + aOrbiterE) + aWUSaltG[((aIndex + 495U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterJ, 47U)) + aWUSaltB[(((511U - aIndex) + 491U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 28U) + aOrbiterC) + RotL64(aOrbiterH, 14U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 12U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWaterLaneB_A[((2047U - aIndex)) & W_KEY1] = aIngress;
        }
    
        //
        // File: nexus_07/loop_000120.bin
        //
        // Head:        [7, 10, 5, 4, 0, 8, 3, 6, 2, 9, 1]
        // Tail A:      [10, 5, 0, 8, 1, 6, 4, 9, 7, 3, 2]
        // Tail B:      [6, 0, 3, 5, 2, 4, 9, 1, 8, 10, 7]
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
        // Orbiters:    [IEHFADBKGJC]
        // Wanderers:   [BCDAGFJIEKH]
        //
        // Ingress:     aWaterLaneB (-->), aRainbowLaneD (-->)
        //
        // Cross:       aWaterLaneA (<--), aRainbowLaneB (<-?->)
        //
        // Destination: aWaterLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aWaterLaneB_A[((aIndex + 834U)) & W_KEY1], 53U) ^ RotL64(aRainbowLaneD_A[((aIndex + 1848U)) & W_KEY1], 20U);
            aIngress = TwistMix64::DiffuseB((aIngress ^ aKeyRotateADomainWordIngress));
            //
            aCross = RotL64(aWaterLaneA_A[(((2047U - aIndex) + 1015U)) & W_KEY1], 58U) ^ RotL64(aRainbowLaneB_A[(((2047U - aIndex) + 1258U)) & W_KEY1], 13U);
            aCross = TwistMix64::DiffuseA((aCross ^ aKeyRotateADomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 28U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aKeyRotateADomainWordScatter));
            //
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 41U)) + 0x1C2517B80DBD5010ULL) + aOASaltC[(((511U - aIndex) + 255U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aCross, 37U)) + 0x792C72B73384ECA2ULL;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 11U)) + 0xDC2A9A5C821DE530ULL) + aOASaltG[((aIndex + 93U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aScatter, 18U)) + RotL64(aCarry, 39U)) + 0xE604B3253099664BULL;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 5U)) + 0x5CF546AF7B92A647ULL;
            aOrbiterD = ((aWandererE + RotL64(aCross, 13U)) + 0x4F81538130AB4112ULL) + aOASaltE[((aIndex + 286U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aIngress, 57U)) + 0xB3777AF376DF538AULL) + aOASaltD[((aIndex + 341U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 39U)) + RotL64(aCarry, 27U)) + 0x43B2A52C1AE95D36ULL;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 3U)) + 0xE2777C35CA6E9B2FULL;
            aOrbiterJ = (aWandererK + RotL64(aCross, 29U)) + 0xD30F8F22BF43AF56ULL;
            aOrbiterC = (((aWandererC + RotL64(aIngress, 50U)) + RotL64(aCarry, 21U)) + 0xF44461B4A58A6C44ULL) + aOASaltA[(((511U - aIndex) + 277U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 0xC149066B023654A4ULL) + aOUSaltH[(((511U - aIndex) + 381U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 0x8FCA2CE492DA14C7ULL) ^ aOUSaltE[((aIndex + 475U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 0x3531B33C342ABD19ULL), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 0xE03B66F8E12A6274ULL;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 0xFDBECAC1FC242E34ULL) ^ aOUSaltA[(((511U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 0x090CEF0BD521206FULL), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 0x975AC65CAAA0C241ULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 0x313127C5C730385FULL;
            aOrbiterG = RotL64((aOrbiterG * 0xF220E7018F516115ULL), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 0x4544F2CA34DD0C2DULL;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 0xADA4F72BA252C2D9ULL) ^ aOUSaltB[(((511U - aIndex) + 291U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 0x9ED58F86A61943B3ULL), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 0x9445347615DE7C66ULL;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 0x7232DCC732F8F377ULL;
            aOrbiterI = RotL64((aOrbiterI * 0x4886FD80C1D4FD6FULL), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 0x05AC93DB6607CACEULL;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 0x94DA032D1ED5E2ECULL) ^ aOUSaltC[(((511U - aIndex) + 130U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 0xEAED8313493F25AFULL), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 0xF782DD8D148E7135ULL;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 0xE0B83D8A8BB2C94CULL;
            aOrbiterB = RotL64((aOrbiterB * 0x49036123E2B46E8DULL), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 0x97BDC54F5C5355ECULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 0xE75D1ECC914C3ABDULL;
            aOrbiterF = RotL64((aOrbiterF * 0x40C70DEBE5A98BF1ULL), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 0x313503AD8C9F17A6ULL;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 0x0B59F863D398A578ULL;
            aOrbiterC = RotL64((aOrbiterC * 0x643616E0C856EF59ULL), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 0x90AFA25594AE8106ULL;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 0xBF2E0F6DAD66FD09ULL;
            aOrbiterE = RotL64((aOrbiterE * 0x8E8BC0746FA92185ULL), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 0xF7675631F18468F5ULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 0xB8B8ECED62C2A603ULL;
            aOrbiterK = RotL64((aOrbiterK * 0x69423C159BEA4587ULL), 5U);
            //
            aIngress = RotL64(aOrbiterG, 29U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 50U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 60U) + aOrbiterC) + RotL64(aOrbiterB, 58U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 37U)) + aOrbiterI);
            aWandererD = aWandererD + ((((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 37U)) + aWUSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterD, 11U));
            aWandererG = aWandererG + (((RotL64(aScatter, 38U) + RotL64(aOrbiterE, 3U)) + aOrbiterH) + aWUSaltH[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 39U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aCross, 19U) + RotL64(aOrbiterA, 53U)) + aOrbiterJ) + aWUSaltF[((aIndex + 218U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterE, 19U)) + aWUSaltA[(((511U - aIndex) + 379U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 51U)) + aOrbiterC);
            aWandererH = aWandererH + ((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterK, 24U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 18U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + RotL64(aWandererD, 12U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWaterLaneC_A[(aIndex) & W_KEY1] = aIngress;
        }
    
        //
        // File: nexus_08/loop_000505.bin
        //
        // Head:        [6, 4, 5, 0, 1, 7, 9, 2, 10, 8, 3]
        // Tail A:      [8, 6, 10, 5, 3, 1, 2, 9, 0, 7, 4]
        // Tail B:      [7, 10, 5, 8, 9, 6, 3, 1, 4, 0, 2]
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
        // Orbiters:    [GCHEBKAJFID]
        // Wanderers:   [IBAJKDHGFEC]
        //
        // Ingress:     aWaterLaneC (-->), aWaterLaneA (<-?->)
        //
        // Cross:       aWaterLaneB (<--), aArcaneLaneC (<-?->)
        //
        // Destination: aWaterLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aWaterLaneC_A[((aIndex + 1355U)) & W_KEY1], 23U) ^ RotL64(aWaterLaneA_A[(((2047U - aIndex) + 2005U)) & W_KEY1], 52U);
            aIngress = TwistMix64::DiffuseA((aIngress ^ aKeyRotateADomainWordIngress));
            //
            aCross = RotL64(aWaterLaneB_A[(((2047U - aIndex) + 880U)) & W_KEY1], 6U) ^ RotL64(aArcaneLaneC_A[((aIndex + 1358U)) & W_KEY1], 37U);
            aCross = TwistMix64::DiffuseA((aCross ^ aKeyRotateADomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 58U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aKeyRotateADomainWordScatter));
            //
            aOrbiterG = (((aWandererH + RotL64(aCross, 23U)) + RotL64(aCarry, 35U)) + 0xFB1F96CCC367BA31ULL) + aOASaltH[(((511U - aIndex) + 81U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aIngress, 27U)) + 0x38BD2A61044257A8ULL) + aOASaltG[(((511U - aIndex) + 339U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aScatter, 50U)) + 0x348A8F7E6D745437ULL;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 5U)) + 0x38F6A7CB97C9CA36ULL;
            aOrbiterB = (((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 23U)) + 0x60A8391258B0F226ULL) + aOASaltE[(((511U - aIndex) + 229U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aIngress, 29U)) + 0xCB7C3DC3D44B9CAFULL;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 35U)) + 0x164C0C2988FBF870ULL) + aOASaltC[((aIndex + 257U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 21U)) + 0x94EE693D913968ECULL;
            aOrbiterF = (((aWandererC + RotL64(aCross, 53U)) + RotL64(aCarry, 11U)) + 0x108378BDFB1B72B1ULL) + aOASaltA[((aIndex + 483U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aIngress, 42U)) + 0xCBB0C571BC391C35ULL;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 11U)) + 0xEB4C38CC196530DEULL;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 0x7BAF8154B484F535ULL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 0xC3305F680E3127BBULL) ^ aOUSaltA[(((511U - aIndex) + 328U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 0x814F7577E6D0E4C7ULL), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 0x3603A9DE3693E952ULL;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 0x38A6453F778F6BF5ULL) ^ aOUSaltC[(((511U - aIndex) + 344U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 0xF5056A8A3BBC3431ULL), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 0x74D06DB8E2F2C0BCULL;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 0xFDDE25EC95D54190ULL) ^ aOUSaltG[(((511U - aIndex) + 179U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 0x1FA3271B517335B9ULL), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 0x5F48F203943A880AULL) + aOUSaltH[((aIndex + 202U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 0x465976B5B3EE4D68ULL) ^ aOUSaltB[(((511U - aIndex) + 154U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 0x92EFA48DA9068341ULL), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 0x8C28FDB6047015DEULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 0xF5167EFA64B0B1E5ULL;
            aOrbiterG = RotL64((aOrbiterG * 0x50CBE6DE640CAEBFULL), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 0xEC1DEF9B457BFB6BULL;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 0x1F3DB6178B3F4832ULL;
            aOrbiterB = RotL64((aOrbiterB * 0x45B885904C5DB48DULL), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 0x2757580C0C45E381ULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 0xF29B7B8DF4D2B6EDULL;
            aOrbiterA = RotL64((aOrbiterA * 0x481B5EF29972BC91ULL), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 0x34DADDDC6E15019DULL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 0x605A4EEF91B9A39FULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0x7EA23516D49E24F1ULL), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 0x2606E0322A5F6495ULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 0x7D3F1DB37BABE7BAULL;
            aOrbiterD = RotL64((aOrbiterD * 0xC15F4B9701A7E5E9ULL), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 0x7795B0FC05E09E13ULL;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 0x6F2C4635924BCCD6ULL;
            aOrbiterC = RotL64((aOrbiterC * 0x70C9418E922F446DULL), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 0x0561D9286539B119ULL) + aOUSaltE[((aIndex + 123U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 0xFC314F4E433BB602ULL;
            aOrbiterE = RotL64((aOrbiterE * 0x6F3932F78F109787ULL), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 50U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 43U)) + aOrbiterJ) + RotL64(aCarry, 23U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 41U)) + aOrbiterD) + aWUSaltE[((aIndex + 357U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 60U) + aOrbiterD) + RotL64(aOrbiterK, 4U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterF, 39U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 57U)) + aOrbiterI) + aWUSaltC[((aIndex + 241U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 35U)) + aOrbiterA) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterH, 29U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterC, 19U)) + aWUSaltF[((aIndex + 426U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 27U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aPrevious, 6U) + RotL64(aOrbiterJ, 54U)) + aOrbiterG);
            aWandererC = aWandererC ^ ((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterH, 37U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 6U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 48U));
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWaterLaneD_A[((2047U - aIndex)) & W_KEY1] = aIngress;
        }
    }
    // GROW_A_C grow_a_loop_c (end)
    WRITE_OUT_MUTABLE_PARAMS;
}

void TwistExpander_Aldebaran_Arx::GROW_A_D(TwistWorkSpace *pWorkSpace,
                     MUTABLE_PARAMS) {
    std::uint8_t *aWaterLaneA = pWorkSpace->mWaterLaneA;
    std::uint8_t *aWaterLaneB = pWorkSpace->mWaterLaneB;
    std::uint8_t *aWaterLaneC = pWorkSpace->mWaterLaneC;
    std::uint8_t *aWaterLaneD = pWorkSpace->mWaterLaneD;
    std::uint8_t *aRainbowLaneB = pWorkSpace->mRainbowLaneB;
    std::uint8_t *aRainbowLaneD = pWorkSpace->mRainbowLaneD;
    std::uint8_t *aPlasmaLaneC = pWorkSpace->mPlasmaLaneC;
    std::uint8_t *aPlasmaLaneD = pWorkSpace->mPlasmaLaneD;
    std::uint8_t *aVaporLaneA = pWorkSpace->mVaporLaneA;
    std::uint8_t *aVaporLaneB = pWorkSpace->mVaporLaneB;
    std::uint8_t *aVaporLaneC = pWorkSpace->mVaporLaneC;
    std::uint8_t *aVaporLaneD = pWorkSpace->mVaporLaneD;
    std::uint64_t *aOASaltA = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltA;
    std::uint64_t *aOASaltB = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltB;
    std::uint64_t *aOASaltC = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltC;
    std::uint64_t *aOASaltD = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltD;
    std::uint64_t *aOASaltE = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltE;
    std::uint64_t *aOASaltF = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltF;
    std::uint64_t *aOASaltG = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltG;
    std::uint64_t *aOASaltH = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterAssign.mSaltH;
    std::uint64_t *aOUSaltA = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltA;
    std::uint64_t *aOUSaltB = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltB;
    std::uint64_t *aOUSaltC = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltC;
    std::uint64_t *aOUSaltD = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltD;
    std::uint64_t *aOUSaltE = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltE;
    std::uint64_t *aOUSaltF = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltF;
    std::uint64_t *aOUSaltG = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltG;
    std::uint64_t *aOUSaltH = pWorkSpace->mDomainBundle.mKeyRotateASalts.mOrbiterUpdate.mSaltH;
    std::uint64_t *aWUSaltA = pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltA;
    std::uint64_t *aWUSaltB = pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltB;
    std::uint64_t *aWUSaltC = pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltC;
    std::uint64_t *aWUSaltD = pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltD;
    std::uint64_t *aWUSaltE = pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltE;
    std::uint64_t *aWUSaltF = pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltF;
    std::uint64_t *aWUSaltG = pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltG;
    std::uint64_t *aWUSaltH = pWorkSpace->mDomainBundle.mKeyRotateASalts.mWandererUpdate.mSaltH;
    std::uint8_t *aVaporLaneA_A = aVaporLaneA + (W_KEY * 0U);
    std::uint8_t *aVaporLaneB_A = aVaporLaneB + (W_KEY * 0U);
    std::uint8_t *aVaporLaneC_A = aVaporLaneC + (W_KEY * 0U);
    std::uint8_t *aVaporLaneD_A = aVaporLaneD + (W_KEY * 0U);
    std::uint8_t *aRainbowLaneB_A = aRainbowLaneB + (W_KEY * 0U);
    std::uint8_t *aRainbowLaneD_A = aRainbowLaneD + (W_KEY * 0U);
    std::uint8_t *aWaterLaneA_A = aWaterLaneA + (W_KEY * 0U);
    std::uint8_t *aWaterLaneB_A = aWaterLaneB + (W_KEY * 0U);
    std::uint8_t *aWaterLaneC_A = aWaterLaneC + (W_KEY * 0U);
    std::uint8_t *aWaterLaneD_A = aWaterLaneD + (W_KEY * 0U);
    std::uint8_t *aPlasmaLaneC_A = aPlasmaLaneC + (W_KEY * 0U);
    std::uint8_t *aPlasmaLaneD_A = aPlasmaLaneD + (W_KEY * 0U);
    const std::uint64_t &aKeyRotateADomainWordIngress = pWorkSpace->mDomainBundle.mKeyRotateAConstants.mIngress;
    const std::uint64_t &aKeyRotateADomainWordScatter = pWorkSpace->mDomainBundle.mKeyRotateAConstants.mScatter;
    const std::uint64_t &aKeyRotateADomainWordCross = pWorkSpace->mDomainBundle.mKeyRotateAConstants.mCross;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [grow arx]
    READ_IN_MUTABLE_PARAMS;
    // GROW_A_D grow_a_loop_d (start)
    {
        //
        // File: nexus_13/loop_000660.bin
        //
        // Head:        [3, 4, 1, 7, 2, 9, 6, 0, 10, 5, 8]
        // Tail A:      [10, 9, 3, 2, 8, 1, 7, 6, 5, 4, 0]
        // Tail B:      [4, 6, 8, 5, 0, 3, 9, 10, 1, 2, 7]
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
        // Orbiters:    [KGAHJCEIBFD]
        // Wanderers:   [CDHKEGIAFJB]
        //
        // Ingress:     aWaterLaneD (-->), aWaterLaneB (-->), aPlasmaLaneD (<-?->)
        //
        // Cross:       aWaterLaneC (<--), aWaterLaneA (<--), aRainbowLaneD (<-?->)
        //
        // Destination: aVaporLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWaterLaneD_A[((aIndex + 591U)) & W_KEY1], 27U) ^ RotL64(aWaterLaneB_A[((aIndex + 220U)) & W_KEY1], 37U));
            aIngress ^= RotL64(aPlasmaLaneD_A[((aIndex + 1843U)) & W_KEY1], 52U);
            aIngress = TwistMix64::DiffuseA((aIngress ^ aKeyRotateADomainWordIngress));
            //
            aCross = (RotL64(aWaterLaneC_A[(((2047U - aIndex) + 1428U)) & W_KEY1], 39U) ^ RotL64(aWaterLaneA_A[(((2047U - aIndex) + 1727U)) & W_KEY1], 20U));
            aCross ^= RotL64(aRainbowLaneD_A[(((2047U - aIndex) + 403U)) & W_KEY1], 53U);
            aCross = TwistMix64::DiffuseA((aCross ^ aKeyRotateADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 5U)) ^ (RotL64(aIngress, 24U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aKeyRotateADomainWordScatter));
            //
            aOrbiterK = ((aWandererK + RotL64(aIngress, 39U)) + 0xB8B89EA189CB9F1EULL) + aOASaltD[((aIndex + 263U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aScatter, 5U)) + RotL64(aCarry, 43U)) + 0x1EAA158B54CDDF27ULL;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 51U)) + 0x320CB77DBC8DBF2FULL) + aOASaltE[((aIndex + 362U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aCross, 29U)) + 0xBB94060CA14C7280ULL) + aOASaltH[((aIndex + 265U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aIngress, 43U)) + 0xB5E6DA1E6B2E8EE4ULL;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 35U)) + 0xFDDC123C72428706ULL;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 14U)) + 0x1373639567D0E2BCULL;
            aOrbiterI = ((aWandererC + RotL64(aCross, 53U)) + 0xEDE219F3869535FDULL) + aOASaltF[(((511U - aIndex) + 72U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aIngress, 23U)) + 0x2A690E8B27D71BDBULL) + aOASaltG[(((511U - aIndex) + 195U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 0x86E466818195374EULL;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 56U)) + 0x3B7ADB6CCD608F67ULL;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 0xD52D2427121347E6ULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 0x870F84AD5F40F8F3ULL;
            aOrbiterA = RotL64((aOrbiterA * 0xD2E386DB627699E9ULL), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 0xECB873789ADEFE42ULL;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 0xC54FE4EA7D854ACCULL;
            aOrbiterC = RotL64((aOrbiterC * 0x57BA887485D23523ULL), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 0xE14610C31716C48BULL;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 0xA058A9C35A9A92FDULL) ^ aOUSaltE[((aIndex + 250U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 0x62946EF76ADC6B2FULL), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 0xA6BA2D520E9B240CULL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 0x97F0437AB8E6BD3FULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0x37AA8D2AC5A25A47ULL), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 0x340F1F34F91617A9ULL;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 0x6ED338EE829CF742ULL) ^ aOUSaltD[(((511U - aIndex) + 47U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 0x385E551808CC4611ULL), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 0xC11D7D44E8B4C7A5ULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 0x05BD937A9B275C95ULL;
            aOrbiterK = RotL64((aOrbiterK * 0xB27EB979232F2501ULL), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 0x0D565AAC937284A3ULL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 0x4085F0522F9B5461ULL) ^ aOUSaltA[(((511U - aIndex) + 419U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 0x86907E34C87301C1ULL), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 0x0711186DD90F33E5ULL) + aOUSaltC[(((511U - aIndex) + 254U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 0xA160D063A7E81AE7ULL;
            aOrbiterE = RotL64((aOrbiterE * 0x80B469A7C7B54A41ULL), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 0x20FB6C3DCB356A3AULL;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 0x315D307112C27043ULL;
            aOrbiterB = RotL64((aOrbiterB * 0xEC6DC610F8BEDA9DULL), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 0xCF3AB0311AFEA7A1ULL) + aOUSaltF[((aIndex + 231U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 0xB7AF890DAF108AD4ULL) ^ aOUSaltB[((aIndex + 507U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 0xF696BE164CD33355ULL), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 0x44EB5CF573DAD965ULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 0x0EB99B3DFC8C861EULL;
            aOrbiterD = RotL64((aOrbiterD * 0x4BD286AB5169C97FULL), 53U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 39U);
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 60U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterJ, 3U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 44U) + aOrbiterF) + RotL64(aOrbiterE, 6U));
            aWandererH = aWandererH + ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 47U)) + aOrbiterB);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 41U) + aOrbiterA) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 53U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 57U)) + aOrbiterK) + aWUSaltD[((aIndex + 214U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 14U) + RotL64(aOrbiterG, 51U)) + aOrbiterH) + aWUSaltE[(((511U - aIndex) + 383U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 13U)) + aOrbiterF);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterD, 41U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterA, 28U)) + aWUSaltG[(((511U - aIndex) + 142U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 39U)) + aOrbiterI) + aWUSaltA[((aIndex + 413U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 58U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aVaporLaneA_A[(aIndex) & W_KEY1] = aIngress;
        }
    
        //
        // File: nexus_03/loop_000088.bin
        //
        // Head:        [3, 8, 7, 6, 0, 4, 1, 10, 9, 5, 2]
        // Tail A:      [10, 1, 5, 6, 4, 3, 2, 9, 7, 0, 8]
        // Tail B:      [6, 2, 0, 9, 1, 7, 8, 4, 5, 10, 3]
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
        // Orbiters:    [HBAGKCJEFID]
        // Wanderers:   [HGKABJDICFE]
        //
        // Ingress:     aVaporLaneA (-->), aWaterLaneC (-->), aRainbowLaneB (<-?->)
        //
        // Cross:       aWaterLaneD (<--), aWaterLaneB (<--), aPlasmaLaneC (<-?->)
        //
        // Destination: aVaporLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aVaporLaneA_A[((aIndex + 1405U)) & W_KEY1], 27U) ^ RotL64(aWaterLaneC_A[((aIndex + 1362U)) & W_KEY1], 44U));
            aIngress ^= RotL64(aRainbowLaneB_A[(((2047U - aIndex) + 1551U)) & W_KEY1], 13U);
            aIngress = TwistMix64::DiffuseC((aIngress ^ aKeyRotateADomainWordIngress));
            //
            aCross = (RotL64(aWaterLaneD_A[(((2047U - aIndex) + 60U)) & W_KEY1], 43U) ^ RotL64(aWaterLaneB_A[(((2047U - aIndex) + 1828U)) & W_KEY1], 14U));
            aCross ^= RotL64(aPlasmaLaneC_A[(((2047U - aIndex) + 248U)) & W_KEY1], 5U);
            aCross = TwistMix64::DiffuseB((aCross ^ aKeyRotateADomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aIngress, 53U)) + (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aKeyRotateADomainWordScatter));
            //
            aOrbiterH = (aWandererA + RotL64(aScatter, 23U)) + 0xE565411D0459DCB8ULL;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 19U)) + 0x44D7BED766A79B2DULL;
            aOrbiterA = ((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 0x1ADA5328EF755438ULL;
            aOrbiterG = (aWandererD + RotL64(aIngress, 34U)) + 0xE71F3DC79E7C3E2BULL;
            aOrbiterK = (aWandererH + RotL64(aScatter, 13U)) + 0x46FE37E9CF524334ULL;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 37U)) + 0x8715D8B58D12B295ULL;
            aOrbiterJ = (((aWandererG + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 0xBB4A6227E910FB0AULL) + aOASaltB[(((511U - aIndex) + 142U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aIngress, 44U)) + 0x3E6036D7808A048EULL;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 21U)) + 0x989C47C83A27DB85ULL) + aOASaltF[((aIndex + 281U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 47U)) + 0xD9FB2F7872AD301EULL;
            aOrbiterD = (((aWandererK + RotL64(aCross, 53U)) + RotL64(aCarry, 47U)) + 0x3572D364F6720EE9ULL) + aOASaltC[(((511U - aIndex) + 367U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 0x90B040C6EDCAA35EULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 0x70579935B7EDBC5CULL;
            aOrbiterA = RotL64((aOrbiterA * 0x5C67560D59A82863ULL), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 0xAAAA0B4C25848DDFULL) + aOUSaltE[(((511U - aIndex) + 195U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 0x5AA523CD3BD0A718ULL;
            aOrbiterC = RotL64((aOrbiterC * 0x636C4749749BE0DBULL), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 0x91CDB3113E8BEEB4ULL;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 0x5235A2091642EAAEULL) ^ aOUSaltG[((aIndex + 208U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 0x457AD73D5D209B47ULL), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 0xC522905906D83DEDULL;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 0x42FD582C7F3C4A59ULL;
            aOrbiterB = RotL64((aOrbiterB * 0x882EA3F9BB72238DULL), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 0xC8E43853E31B5E79ULL;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 0x890E39C2DF54FBB4ULL) ^ aOUSaltB[(((511U - aIndex) + 400U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 0x2B38F8F29F713551ULL), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 0x446A44D72ECD7D39ULL;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 0x18CCCF27D46C2ABCULL;
            aOrbiterH = RotL64((aOrbiterH * 0xF596229682DF512BULL), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 0x1F8E70521F5BAE2FULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 0xF6AFA2338744A847ULL;
            aOrbiterG = RotL64((aOrbiterG * 0x74CCCEBFB7D463A5ULL), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 0x221E6D169A07DA5CULL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 0xF1BBB6DE772C7EC2ULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0x4C924559F37E4B89ULL), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 0x0C90FA8A8B3A2D14ULL;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 0x3DAA0F5B90C853F7ULL;
            aOrbiterI = RotL64((aOrbiterI * 0xBB051F3C996D99D5ULL), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 0x5C966E94AF89795DULL) + aOUSaltH[(((511U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 0x7915EA19A2A09F4AULL;
            aOrbiterF = RotL64((aOrbiterF * 0xA0A598F575CD2357ULL), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 0xB93BD9972D5F0B5FULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 0xED422E68824EBA61ULL;
            aOrbiterD = RotL64((aOrbiterD * 0x48DA4CA7A0F1EEE9ULL), 57U);
            //
            aIngress = RotL64(aOrbiterI, 27U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterB, 18U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 21U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererG = aWandererG + (((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterA, 43U)) + aWUSaltB[((aIndex + 126U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 39U)) + aOrbiterH) + aWUSaltG[((aIndex + 499U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterI, 27U)) + aWUSaltE[((aIndex + 262U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 58U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aCross, 3U) + RotL64(aOrbiterG, 11U)) + aOrbiterE);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterA, 41U)) + aOrbiterF) + RotL64(aCarry, 53U));
            aWandererI = aWandererI + ((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterK, 29U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 19U)) + aOrbiterC);
            aWandererF = aWandererF + ((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterD, 48U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 28U) + RotL64(aOrbiterF, 35U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 12U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 22U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aVaporLaneB_A[((2047U - aIndex)) & W_KEY1] = aIngress;
        }
    
        //
        // File: nexus_04/loop_000263.bin
        //
        // Head:        [8, 0, 5, 2, 10, 4, 1, 3, 6, 9, 7]
        // Tail A:      [10, 9, 8, 5, 3, 0, 6, 4, 7, 1, 2]
        // Tail B:      [2, 4, 0, 8, 6, 3, 1, 5, 9, 10, 7]
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
        // Orbiters:    [CKBDHFJAIEG]
        // Wanderers:   [HCGIKAEBDFJ]
        //
        // Ingress:     aVaporLaneB (-->), aWaterLaneD (-->)
        //
        // Cross:       aVaporLaneA (<--), aWaterLaneC (<--)
        //
        // Destination: aVaporLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aVaporLaneB_A[((aIndex + 1055U)) & W_KEY1], 35U) ^ RotL64(aWaterLaneD_A[((aIndex + 753U)) & W_KEY1], 20U);
            aIngress = TwistMix64::DiffuseB((aIngress ^ aKeyRotateADomainWordIngress));
            //
            aCross = RotL64(aVaporLaneA_A[(((2047U - aIndex) + 1493U)) & W_KEY1], 51U) ^ RotL64(aWaterLaneC_A[(((2047U - aIndex) + 1198U)) & W_KEY1], 40U);
            aCross = TwistMix64::DiffuseB((aCross ^ aKeyRotateADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 6U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aKeyRotateADomainWordScatter));
            //
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 53U)) + 0xD85C9E996E6FA0AEULL;
            aOrbiterK = ((aWandererH + RotL64(aCross, 29U)) + 0xAF911119511DD3C5ULL) + aOASaltE[(((511U - aIndex) + 252U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aIngress, 41U)) + 0x478159D1C5B349F2ULL;
            aOrbiterD = (((aWandererG + RotL64(aScatter, 11U)) + RotL64(aCarry, 47U)) + 0xDC469FB4D98C9F8BULL) + aOASaltG[((aIndex + 175U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 24U)) + 0xC379479699AD09A7ULL;
            aOrbiterF = ((aWandererK + RotL64(aCross, 51U)) + 0xBFA6D3DF63789495ULL) + aOASaltC[((aIndex + 143U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aIngress, 19U)) + 0xD7B58ADC33BAE188ULL;
            aOrbiterA = (((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 0x8158F1D84A5F04BCULL) + aOASaltF[((aIndex + 333U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aPrevious, 57U)) + 0x886CFB024CBD2476ULL;
            aOrbiterE = ((aWandererF + RotL64(aCross, 43U)) + 0x101B3219AC420CA3ULL) + aOASaltH[((aIndex + 249U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aIngress, 34U)) + 0xE5E14D45DE0A21BDULL;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 0x12640A74B6A910C8ULL;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 0xF49AF2AB4A4A9FD0ULL;
            aOrbiterB = RotL64((aOrbiterB * 0x8C2E3E86D34AC5DFULL), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 0xEC8B6D0D350995DEULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 0xC2C18FAB07C9E7F5ULL;
            aOrbiterF = RotL64((aOrbiterF * 0x432281F96F460F7BULL), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 0xD866735B7E2F97E6ULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 0xC757B19DD1E8F375ULL;
            aOrbiterA = RotL64((aOrbiterA * 0xB68FB85A546A8E9DULL), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 0x8E89CBE4834C1D96ULL;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 0xABC582BA6CD072A6ULL) ^ aOUSaltD[(((511U - aIndex) + 253U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 0xC66C2BF92994B7DFULL), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 0x3113A41C464593DDULL) + aOUSaltA[(((511U - aIndex) + 42U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 0xB668CA52F6EFD926ULL;
            aOrbiterK = RotL64((aOrbiterK * 0xB0564F9FC9D52B5FULL), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 0xB82F4CC2DAFCDA20ULL;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 0xE28B7F30CDB38A65ULL) ^ aOUSaltB[(((511U - aIndex) + 297U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 0xB734C9E2A7B88B3FULL), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 0x1F269EE18CD9F594ULL) + aOUSaltC[((aIndex + 453U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 0x8B410CEC42ECB40DULL) ^ aOUSaltE[((aIndex + 308U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 0x255FB373F16D19EDULL), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 0x966DD072F66EA7A3ULL;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 0x2CF7DFB774154AC5ULL;
            aOrbiterE = RotL64((aOrbiterE * 0x6E240D1A0F62319FULL), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 0xCD66B42FD6D8A8B8ULL;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 0x3B7475DF0714BC3CULL;
            aOrbiterI = RotL64((aOrbiterI * 0x535C97BD4CD15A53ULL), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 0x541C2FE548AAC917ULL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 0xDC0CDC21052FE485ULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0x4DEE0F55D0642405ULL), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 0xFD07E0AD5C2CE93DULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 0x5860C64EB33ED2B7ULL;
            aOrbiterD = RotL64((aOrbiterD * 0x4E3B84CBFA29BA3BULL), 27U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 18U);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 52U) + aOrbiterG) + RotL64(aOrbiterB, 30U)) + aWUSaltD[(((511U - aIndex) + 81U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterE, 41U)) + aOrbiterH);
            aWandererG = aWandererG + ((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 11U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 39U)) + aWUSaltC[(((511U - aIndex) + 112U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 3U)) + aOrbiterJ);
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterC, 35U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aIngress, 18U) + RotL64(aOrbiterJ, 51U)) + aOrbiterK) + aWUSaltB[(((511U - aIndex) + 178U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterF, 19U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterE, 60U)) + aWUSaltH[((aIndex + 35U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 29U) + RotL64(aOrbiterK, 43U)) + aOrbiterG) + RotL64(aCarry, 23U)) + aWUSaltG[(((511U - aIndex) + 429U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 39U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererC, 56U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 34U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aVaporLaneC_A[(aIndex) & W_KEY1] = aIngress;
        }
    
        //
        // File: nexus_01/loop_000085.bin
        //
        // Head:        [3, 0, 5, 2, 9, 10, 7, 1, 8, 6, 4]
        // Tail A:      [4, 2, 0, 5, 8, 6, 10, 1, 3, 9, 7]
        // Tail B:      [9, 8, 6, 1, 5, 10, 3, 7, 0, 2, 4]
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
        // Orbiters:    [AGJDBKCHIFE]
        // Wanderers:   [JCEKDFIAHGB]
        //
        // Ingress:     aVaporLaneC (-->), aVaporLaneA (<-?->)
        //
        // Cross:       aVaporLaneB (<--), aWaterLaneD (<-?->)
        //
        // Destination: aVaporLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = RotL64(aVaporLaneC_A[((aIndex + 603U)) & W_KEY1], 30U) ^ RotL64(aVaporLaneA_A[((aIndex + 15U)) & W_KEY1], 13U);
            aIngress = TwistMix64::DiffuseC((aIngress ^ aKeyRotateADomainWordIngress));
            //
            aCross = RotL64(aVaporLaneB_A[(((2047U - aIndex) + 1063U)) & W_KEY1], 20U) ^ RotL64(aWaterLaneD_A[(((2047U - aIndex) + 92U)) & W_KEY1], 57U);
            aCross = TwistMix64::DiffuseC((aCross ^ aKeyRotateADomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aIngress, 43U)) ^ (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 12U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aKeyRotateADomainWordScatter));
            //
            aOrbiterA = (aWandererK + RotL64(aCross, 20U)) + 0x1534BE895D39ED5DULL;
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 21U)) + 0xDAF2862491A34BBBULL) + aOASaltH[(((511U - aIndex) + 151U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aScatter, 5U)) + 0x56CA1F2D5F515AE8ULL;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 51U)) + 0x2335BC056A992C67ULL;
            aOrbiterB = (((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 57U)) + 0x982E27CD2C78689FULL) + aOASaltA[(((511U - aIndex) + 195U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aIngress, 11U)) + 0xE235D1E0C7F54ABCULL) + aOASaltG[(((511U - aIndex) + 123U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aScatter, 13U)) + 0x42B0AB9F52A36151ULL) + aOASaltF[((aIndex + 277U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aPrevious, 47U)) + 0x6E0DB0DDF4A92095ULL;
            aOrbiterI = ((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 3U)) + 0xE5F8ED63CD2476EEULL;
            aOrbiterF = (aWandererI + RotL64(aIngress, 39U)) + 0x0FE4DE30C38A4CECULL;
            aOrbiterE = (aWandererD + RotL64(aScatter, 22U)) + 0xD0D95D4C81505379ULL;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 0x09F9A39EBF94BF05ULL;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 0xA15245B826745D3CULL) ^ aOUSaltF[((aIndex + 511U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 0x4595364AD7DD3997ULL), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 0x39E0F63340B6571CULL) + aOUSaltE[((aIndex + 134U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 0x8F4EAD06D2E970C0ULL;
            aOrbiterK = RotL64((aOrbiterK * 0x4ABBF297E79496E7ULL), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 0x213A0D78C74A2839ULL;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 0xB0C4D8FC605843C9ULL;
            aOrbiterH = RotL64((aOrbiterH * 0xE1D1A25CB0DD18F5ULL), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 0x081C065237086ADAULL;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 0x87F13808287C70ECULL) ^ aOUSaltD[(((511U - aIndex) + 302U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 0x73279B57DD7B682FULL), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 0x8D0D3D108E5202D4ULL;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 0x58F9F060A749B22BULL;
            aOrbiterE = RotL64((aOrbiterE * 0xA2176DB42EE56A8DULL), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 0xAD7BB3030F198814ULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 0xFDFA110B3B9501F5ULL;
            aOrbiterG = RotL64((aOrbiterG * 0x65E25BC9C30EE045ULL), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 0x5F10EC18117BF7EEULL;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 0xE2D44385B191A0F7ULL;
            aOrbiterC = RotL64((aOrbiterC * 0x33737172E25791BBULL), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 0x12CE18EB73C48C8CULL;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 0x74F938D3E575DB08ULL) ^ aOUSaltG[((aIndex + 105U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 0x249E045E0745FD83ULL), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 0xF4B51E61A51BD815ULL;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 0xE70E1B5214AD553CULL;
            aOrbiterI = RotL64((aOrbiterI * 0xF51AC1BB2064E09DULL), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 0x66BDBB30578B3EA5ULL) + aOUSaltB[(((511U - aIndex) + 456U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 0x3D4C06D497DF273CULL;
            aOrbiterA = RotL64((aOrbiterA * 0x526580FBD09C0CEDULL), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 0x810A4A20F0B09A9BULL;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 0x2889AD916152E9B8ULL;
            aOrbiterB = RotL64((aOrbiterB * 0x66DC3EF4D542FEF9ULL), 23U);
            //
            aIngress = RotL64(aOrbiterK, 53U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 48U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 38U) + RotL64(aOrbiterB, 26U)) + aOrbiterF) + aWUSaltE[(((511U - aIndex) + 97U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 41U)) + aOrbiterI) + RotL64(aCarry, 13U)) + aWUSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 57U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterG, 5U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 21U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aCross, 3U) + RotL64(aOrbiterC, 37U)) + aOrbiterE) + aWUSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 53U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererA = aWandererA + ((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterH, 35U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 46U)) + aOrbiterA) + aWUSaltF[((aIndex + 128U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 13U) + RotL64(aOrbiterF, 19U)) + aOrbiterJ);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 42U) + RotL64(aOrbiterH, 51U)) + aOrbiterB) + aWUSaltD[((aIndex + 215U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aVaporLaneD_A[((2047U - aIndex)) & W_KEY1] = aIngress;
        }
    }
    // GROW_A_D grow_a_loop_d (end)
    WRITE_OUT_MUTABLE_PARAMS;
}
