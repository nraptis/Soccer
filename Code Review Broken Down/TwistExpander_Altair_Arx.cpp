void TwistExpander_Altair_Arx::KEY_A_A_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS) {
    std::uint64_t *aOASaltB = pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterAssign.mSaltB;
    std::uint64_t *aOASaltC = pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterAssign.mSaltC;
    std::uint64_t *aOASaltD = pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterAssign.mSaltD;
    std::uint64_t *aOASaltE = pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterAssign.mSaltE;
    std::uint64_t *aOASaltF = pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterAssign.mSaltF;
    std::uint64_t *aOASaltG = pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterAssign.mSaltG;
    std::uint64_t *aOASaltH = pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterAssign.mSaltH;
    std::uint64_t *aOUSaltA = pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterUpdate.mSaltA;
    std::uint64_t *aOUSaltB = pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterUpdate.mSaltB;
    std::uint64_t *aOUSaltC = pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterUpdate.mSaltC;
    std::uint64_t *aOUSaltD = pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterUpdate.mSaltD;
    std::uint64_t *aOUSaltE = pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterUpdate.mSaltE;
    std::uint64_t *aOUSaltF = pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterUpdate.mSaltF;
    std::uint64_t *aOUSaltG = pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterUpdate.mSaltG;
    std::uint64_t *aOUSaltH = pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterUpdate.mSaltH;
    std::uint64_t *aWUSaltA = pWorkSpace->mDomainBundle.mKeySpawnASalts.mWandererUpdate.mSaltA;
    std::uint64_t *aWUSaltB = pWorkSpace->mDomainBundle.mKeySpawnASalts.mWandererUpdate.mSaltB;
    std::uint64_t *aWUSaltC = pWorkSpace->mDomainBundle.mKeySpawnASalts.mWandererUpdate.mSaltC;
    std::uint64_t *aWUSaltD = pWorkSpace->mDomainBundle.mKeySpawnASalts.mWandererUpdate.mSaltD;
    std::uint64_t *aWUSaltE = pWorkSpace->mDomainBundle.mKeySpawnASalts.mWandererUpdate.mSaltE;
    std::uint64_t *aWUSaltF = pWorkSpace->mDomainBundle.mKeySpawnASalts.mWandererUpdate.mSaltF;
    std::uint64_t *aWUSaltG = pWorkSpace->mDomainBundle.mKeySpawnASalts.mWandererUpdate.mSaltG;
    std::uint64_t *aWUSaltH = pWorkSpace->mDomainBundle.mKeySpawnASalts.mWandererUpdate.mSaltH;
    std::uint8_t *aCrystalLaneA = ALTAIR_KEY_A_A_CrystalLaneA;
    std::uint8_t *aCrystalLaneB = ALTAIR_KEY_A_A_CrystalLaneB;
    std::uint8_t *aCrystalLaneC = ALTAIR_KEY_A_A_CrystalLaneC;
    std::uint8_t *aCrystalLaneD = ALTAIR_KEY_A_A_CrystalLaneD;
    std::uint8_t *aKineticLaneB = ALTAIR_KEY_A_A_KineticLaneB;
    std::uint8_t *aSonicLaneB = ALTAIR_KEY_A_A_SonicLaneB;
    std::uint8_t *aPlanarLaneA = ALTAIR_KEY_A_A_PlanarLaneA;
    std::uint8_t *aArcaneLaneA = ALTAIR_KEY_A_A_ArcaneLaneA;
    std::uint8_t *aArcaneLaneB = ALTAIR_KEY_A_A_ArcaneLaneB;
    std::uint8_t *aArcaneLaneC = ALTAIR_KEY_A_A_ArcaneLaneC;
    std::uint8_t *aArcaneLaneD = ALTAIR_KEY_A_A_ArcaneLaneD;
    std::uint8_t *aLunarLaneB = ALTAIR_KEY_A_A_LunarLaneB;
    std::uint8_t *aRunicLaneA = ALTAIR_KEY_A_A_RunicLaneA;
    std::uint8_t *aRunicLaneB = ALTAIR_KEY_A_A_RunicLaneB;
    std::uint8_t *aDivinationLaneC = ALTAIR_KEY_A_A_DivinationLaneC;
    std::uint8_t *aEarthLaneA = ALTAIR_KEY_A_A_EarthLaneA;
    std::uint8_t *aEarthLaneB = ALTAIR_KEY_A_A_EarthLaneB;
    std::uint8_t *aEarthLaneC = ALTAIR_KEY_A_A_EarthLaneC;
    std::uint8_t *aEarthLaneD = ALTAIR_KEY_A_A_EarthLaneD;
    std::uint8_t *aPsychicLaneA = ALTAIR_KEY_A_A_PsychicLaneA;
    const std::uint64_t &aKeySpawnADomainWordIngress = pWorkSpace->mDomainBundle.mKeySpawnAConstants.mIngress;
    const std::uint64_t &aKeySpawnADomainWordScatter = pWorkSpace->mDomainBundle.mKeySpawnAConstants.mScatter;
    const std::uint64_t &aKeySpawnADomainWordCross = pWorkSpace->mDomainBundle.mKeySpawnAConstants.mCross;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [key arx]
    READ_IN_MUTABLE_PARAMS;
    const std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBAC3F4384BBE74F9ULL + 0xA423F056F1AF369FULL);
    const std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC34CDBAB4D38E83FULL + 0xD3F7291A11F115CFULL);
    const std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x924A0F70EA7F346FULL + 0xAA47DB0CA5E3B8FBULL);
    const std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB4EF09B39A3239EDULL + 0xC43F6FCA56AA642EULL);
    const std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA2B8E18EEF538BBFULL + 0x80F62BD659F35B1DULL);
    const std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC4F8D85868688F7BULL + 0xFD1AA10D2E91DB2FULL);
    const std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE0814466972769E3ULL + 0xE73080FF7EFB6DC3ULL);
    const std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9BD5A64F85D000FDULL + 0x84896B58C3A2A116ULL);
    const std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xEC339C07B385503FULL + 0xD89581F345356612ULL);
    const std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xBA7286682E940451ULL + 0x95D6B9A1BCA440F6ULL);
    const std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xA95BCBA5EEFC7CB7ULL + 0xEB066A1EFC0DEA3AULL);
    const std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xC821EE6068D9A50FULL + 0x812FD55FA8DF2488ULL);
    const std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9D1BAC6C08992E49ULL + 0xA4DF6E2B56D18064ULL);
    const std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD567D9FE483D2713ULL + 0xAE1158BF426E02C3ULL);
    const std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xC269339EF10FF757ULL + 0xF0AA23E63975227EULL);
    const std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x93EF6ECF7CB86DCDULL + 0x999A3D9DBFF08CBDULL);
    {
        //
        // File: nexus_02/loop_000167.bin
        //
        // Head:        [5, 6, 4, 1, 3, 0, 9, 10, 8, 2, 7]
        // Tail A:      [1, 5, 4, 0, 8, 6, 3, 7, 10, 2, 9]
        // Tail B:      [10, 0, 5, 8, 3, 9, 7, 4, 6, 1, 2]
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
        // Orbiters:    [ABDHKEGJFIC]
        // Wanderers:   [JKADGBEHFIC]
        //
        // Ingress:     aEarthLaneA (-->), aEarthLaneB (-->), aEarthLaneC (-->), aEarthLaneD (-->)
        //
        // Cross:       aCrystalLaneA (<--), aCrystalLaneB (<--), aCrystalLaneC (<--), aCrystalLaneD (<--)
        //
        // Destination: aArcaneLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aEarthLaneA[((aIndex + 1465U)) & W_KEY1], 27U) ^ RotL64(aEarthLaneB[((aIndex + 742U)) & W_KEY1], 47U));
            aIngress ^= (RotL64(aEarthLaneC[((aIndex + 1048U)) & W_KEY1], 57U) ^ RotL64(aEarthLaneD[((aIndex + 1813U)) & W_KEY1], 38U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aKeySpawnADomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aCrystalLaneA[(((2047U - aIndex) + 1670U)) & W_KEY1], 53U) ^ RotL64(aCrystalLaneB[(((2047U - aIndex) + 1520U)) & W_KEY1], 19U));
            aCross ^= (RotL64(aCrystalLaneC[(((2047U - aIndex) + 476U)) & W_KEY1], 40U) ^ RotL64(aCrystalLaneD[(((2047U - aIndex) + 1954U)) & W_KEY1], 11U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aKeySpawnADomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 43U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 28U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aKeySpawnADomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = ((aWandererB + RotL64(aIngress, 53U)) + 0x66BE4B479678F8E4ULL) + aOASaltD[(((511U - aIndex) + 381U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aScatter, 58U)) + 0x43048D66B19A18E7ULL) + aOASaltB[(((511U - aIndex) + 321U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 0x78519C66C882D64DULL;
            aOrbiterH = (aWandererK + RotL64(aCross, 27U)) + 0x89A7B7033AD17A3CULL;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 19U)) + 0xE580EDBAE49E67E8ULL) + aOASaltE[(((511U - aIndex) + 472U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 19U)) + 0x3390DEA83755E287ULL;
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 37U)) + 0xEA06B1738CEA4EDEULL) + aOASaltC[((aIndex + 125U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = (aWandererC + RotL64(aCross, 51U)) + 0x38BD0368E5713A64ULL;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 21U)) + 0x13ADDC0AB1697016ULL) + aNonceWordB;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 56U)) + RotL64(aCarry, 51U)) + 0x75E5CC896E4E7589ULL;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 5U)) + 0x4FA0EC051F8B9533ULL) + aNonceWordH;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 0xCE2F88AD6F60F642ULL;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 0x5AF14C5D61D572F6ULL) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 0x79883B1BC78979EFULL), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 0xA2B8C85D1C4AE6D1ULL;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 0xF3DD1967AA1B5463ULL;
            aOrbiterE = RotL64((aOrbiterE * 0x2597AD7B4E5196C5ULL), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 0x63F3A406077C1E5AULL;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 0xE5BDA90F52C31C05ULL) ^ aOUSaltD[((aIndex + 145U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 0xCDF9BBDCECDAB603ULL), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 0xA37F4F3BE735BAAEULL;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 0xA8BEC481DF2C52A4ULL;
            aOrbiterB = RotL64((aOrbiterB * 0xBD65DB55018979FBULL), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 0x1B6E5CD5F66A5D3CULL;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 0x544EDC84EC398999ULL) ^ aOUSaltG[((aIndex + 173U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 0xB5591A755495D0C7ULL), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 0x37D33B49E936375AULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 0x784C5F4725D2AAF5ULL;
            aOrbiterA = RotL64((aOrbiterA * 0x297D5AAE26FD8CF7ULL), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 0x173D149697665CCFULL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 0x37904E8BDDD58218ULL) ^ aOUSaltE[((aIndex + 200U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 0xA2099537D05DC6DBULL), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 0x88FEB91D85419FACULL;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 0xD85D3ED4E7BD546AULL) ^ aOUSaltH[((aIndex + 191U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 0x81F0E85EAE04DD07ULL), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 0xF09F850B1B951DECULL) + aOUSaltC[(((511U - aIndex) + 133U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 0x67447C696DA52C3BULL;
            aOrbiterI = RotL64((aOrbiterI * 0x313560A936082ADBULL), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 0x9B7DAAC6231026C3ULL) + aNonceWordG;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 0x93DA15DD4D238ACDULL) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 0x2A4CE77C963340EFULL), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 0x973F7DCE4E7D4C31ULL;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 0x15A0EA0A189CE5CEULL;
            aOrbiterC = RotL64((aOrbiterC * 0xC17B03F3B9AE0D0FULL), 5U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 40U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterC, 11U)) + aWUSaltG[(((511U - aIndex) + 203U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterA, 30U)) + aNonceWordK) + aWUSaltH[((aIndex + 162U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 13U)) + aOrbiterE) + aNonceWordM) + aWUSaltF[((aIndex + 81U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterA, 19U)) + aOrbiterF) + aNonceWordP);
            aWandererG = aWandererG + ((((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 57U)) + aWUSaltE[(((511U - aIndex) + 283U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 24U)) + aOrbiterI) + aWUSaltB[(((511U - aIndex) + 242U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 20U) + aOrbiterH) + RotL64(aOrbiterJ, 41U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 43U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterG, 35U)) + aNonceWordD);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 37U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 40U) + RotL64(aOrbiterI, 47U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 14U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererI, 42U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aArcaneLaneA[(aIndex) & W_KEY1] = aIngress;
        }
    
        //
        // File: nexus_00/loop_000167.bin
        //
        // Head:        [4, 10, 5, 9, 0, 1, 2, 7, 6, 8, 3]
        // Tail A:      [5, 3, 9, 8, 1, 7, 0, 4, 2, 10, 6]
        // Tail B:      [8, 6, 7, 2, 5, 1, 9, 0, 3, 4, 10]
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
        // Orbiters:    [JCFEHDIGKBA]
        // Wanderers:   [KBJFCGHADIE]
        //
        // Ingress:     aArcaneLaneA (-->), aCrystalLaneA (-->), aCrystalLaneB (-->), aPsychicLaneA (<-?->)
        //
        // Cross:       aEarthLaneA (<--), aEarthLaneB (<--), aKineticLaneB (<--), aLunarLaneB (<-?->)
        //
        // Destination: aArcaneLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aArcaneLaneA[((aIndex + 1073U)) & W_KEY1], 35U) ^ RotL64(aCrystalLaneA[((aIndex + 243U)) & W_KEY1], 51U));
            aIngress ^= (RotL64(aCrystalLaneB[((aIndex + 1952U)) & W_KEY1], 27U) ^ RotL64(aPsychicLaneA[((aIndex + 409U)) & W_KEY1], 43U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aKeySpawnADomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aEarthLaneA[(((2047U - aIndex) + 1838U)) & W_KEY1], 43U) ^ RotL64(aEarthLaneB[(((2047U - aIndex) + 1164U)) & W_KEY1], 19U));
            aCross ^= (RotL64(aKineticLaneB[(((2047U - aIndex) + 1073U)) & W_KEY1], 27U) ^ RotL64(aLunarLaneB[((aIndex + 336U)) & W_KEY1], 5U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aKeySpawnADomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 56U)) + (RotL64(aIngress, 39U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aKeySpawnADomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterJ = (aWandererC + RotL64(aScatter, 37U)) + 0xD0DE9B4154A7E80EULL;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 43U)) + 0x32647DE36C4D55DCULL;
            aOrbiterF = (((aWandererG + RotL64(aCross, 29U)) + 0x0F2E68D584890715ULL) + aOASaltC[((aIndex + 107U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = (((aWandererI + RotL64(aIngress, 6U)) + RotL64(aCarry, 51U)) + 0x6B26E232ACD218A3ULL) + aOASaltF[((aIndex + 280U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aScatter, 23U)) + 0x3B2196D7893F71BFULL;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 41U)) + 0x249A81A3A8DD6B21ULL) + aNonceWordL;
            aOrbiterI = (((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 11U)) + 0x952D61A489679D06ULL) + aOASaltB[((aIndex + 89U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aIngress, 4U)) + 0xCC10933E1F446558ULL) + aNonceWordF;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 53U)) + 0xB6C2B31CE5DB6766ULL) + aOASaltG[(((511U - aIndex) + 510U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 47U)) + 0xA19D6E8549484210ULL) + aNonceWordA;
            aOrbiterA = ((aWandererF + RotL64(aCross, 11U)) + RotL64(aCarry, 21U)) + 0x3764F9669C1F3C76ULL;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 0x8C6244F770B8C772ULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 0xF938460901E2E40EULL;
            aOrbiterF = RotL64((aOrbiterF * 0xDC1A4360A551990FULL), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 0xA8BD61E31E2F4B17ULL) + aOUSaltG[(((511U - aIndex) + 299U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 0xDB435A35A3D93AC3ULL;
            aOrbiterD = RotL64((aOrbiterD * 0xA7CB0C4EFC256B47ULL), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 0x281918DC53A211E1ULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 0x756F468D299A5DB3ULL;
            aOrbiterG = RotL64((aOrbiterG * 0x61083AC0E73D40AFULL), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 0xBB5BC38B141CD37BULL) + aOUSaltF[((aIndex + 386U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 0x963E5CA364B9B8A0ULL;
            aOrbiterA = RotL64((aOrbiterA * 0x3622448B438A6545ULL), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 0xBAA525C364570F25ULL) + aOUSaltD[(((511U - aIndex) + 96U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 0xCE281647BE861EE8ULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0xD547DF0B71EFB075ULL), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 0x6463A5B5C9972B0DULL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 0xEE6CAA93BEDC2EF9ULL) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 0x9382EE06CC1D9915ULL), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 0xDC79D3CCF7653BACULL;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 0x41E27D4C478B8EDCULL;
            aOrbiterE = RotL64((aOrbiterE * 0xCFB3175E734B280DULL), 53U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterD) + 0xF2799C381D95EF0EULL) + aOUSaltA[((aIndex + 110U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 0xFE9DDCB2D53A8090ULL;
            aOrbiterB = RotL64((aOrbiterB * 0xB67B94F5BEC9EBCDULL), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 0x56D2E26532EC87D9ULL) + aOUSaltE[((aIndex + 217U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 0x2040EBDD8BAE9F4EULL;
            aOrbiterK = RotL64((aOrbiterK * 0x1C3737F314AB2953ULL), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 0x590D188A45E1050BULL;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 0xFC64B42F6970BA3AULL;
            aOrbiterC = RotL64((aOrbiterC * 0x2076BD21049EA10BULL), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 0xFC3A1D527F37D771ULL) + aNonceWordK;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 0xE7626748E5BE3861ULL) ^ aOUSaltH[((aIndex + 339U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 0x9BFB2FEE24CD2A0DULL), 37U);
            //
            aIngress = RotL64(aOrbiterH, 5U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 27U)) + aOrbiterK);
            aWandererB = aWandererB + ((((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 41U)) + aNonceWordN);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 22U) + RotL64(aOrbiterB, 53U)) + aOrbiterG) + aNonceWordH);
            aWandererF = aWandererF + (((RotL64(aCross, 57U) + RotL64(aOrbiterK, 18U)) + aOrbiterF) + aWUSaltA[(((511U - aIndex) + 487U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterD, 13U)) + aWUSaltH[(((511U - aIndex) + 69U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 51U)) + aOrbiterC);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 26U) + aOrbiterJ) + RotL64(aOrbiterB, 23U)) + aWUSaltD[(((511U - aIndex) + 172U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 53U) + RotL64(aOrbiterH, 47U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aWUSaltE[(((511U - aIndex) + 87U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 43U)) + aOrbiterE) + aNonceWordD);
            aWandererI = aWandererI + ((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterH, 41U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 4U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 14U));
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 40U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aArcaneLaneB[((2047U - aIndex)) & W_KEY1] = aIngress;
        }
    
        //
        // File: nexus_10/loop_000691.bin
        //
        // Head:        [3, 0, 6, 2, 7, 10, 4, 5, 1, 8, 9]
        // Tail A:      [3, 4, 2, 9, 10, 1, 0, 5, 6, 8, 7]
        // Tail B:      [6, 1, 4, 7, 5, 10, 8, 9, 0, 2, 3]
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
        // Orbiters:    [BFAIJGHKECD]
        // Wanderers:   [HCJFKEAGIBD]
        //
        // Ingress:     aArcaneLaneB (-->), aCrystalLaneC (-->), aPlanarLaneA (-->), aRunicLaneA (<-?->)
        //
        // Cross:       aArcaneLaneA (<--), aEarthLaneC (<--), aSonicLaneB (<--), aRunicLaneB (<-?->)
        //
        // Destination: aArcaneLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aArcaneLaneB[((aIndex + 1671U)) & W_KEY1], 3U) ^ RotL64(aCrystalLaneC[((aIndex + 452U)) & W_KEY1], 19U));
            aIngress ^= (RotL64(aPlanarLaneA[((aIndex + 1285U)) & W_KEY1], 41U) ^ RotL64(aRunicLaneA[((aIndex + 338U)) & W_KEY1], 11U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aKeySpawnADomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aArcaneLaneA[(((2047U - aIndex) + 1467U)) & W_KEY1], 47U) ^ RotL64(aEarthLaneC[(((2047U - aIndex) + 1089U)) & W_KEY1], 14U));
            aCross ^= (RotL64(aSonicLaneB[(((2047U - aIndex) + 1177U)) & W_KEY1], 39U) ^ RotL64(aRunicLaneB[(((2047U - aIndex) + 1911U)) & W_KEY1], 57U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aKeySpawnADomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aIngress, 43U)) + (RotL64(aPrevious, 29U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aKeySpawnADomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterB = (((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 27U)) + 0xD78D82C836D651F3ULL) + aNonceWordJ;
            aOrbiterF = (aWandererH + RotL64(aCross, 19U)) + 0x6386FE0FC7218CD8ULL;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 27U)) + 0x91BE6615DE118D65ULL) + aOASaltH[((aIndex + 322U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aScatter, 46U)) + 0xA8DE33A61D1EA12DULL;
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 37U)) + 0x2F0D351256B9F75AULL) + aNonceWordE;
            aOrbiterG = (((aWandererD + RotL64(aCross, 23U)) + 0x129B23BD4CCA4A54ULL) + aOASaltD[((aIndex + 180U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = (aWandererK + RotL64(aIngress, 41U)) + 0x3C715B264D7A977EULL;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 13U)) + 0xFC49BEF34ECD7686ULL;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 37U)) + 0xB6DC81904A624BA1ULL) + aOASaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aCross, 48U)) + 0x5F63390B925DDEEFULL;
            aOrbiterD = (aWandererB + RotL64(aIngress, 3U)) + 0x6A766F5C4DC52B29ULL;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 0x1C975CA56F30BE95ULL) + aOUSaltH[(((511U - aIndex) + 267U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 0x796A12DE11C153D8ULL) ^ aOUSaltC[(((511U - aIndex) + 393U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 0x5E14A6EF50D5AA4DULL), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 0xCCB739F435D88211ULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 0xE8F8D750FBB835C2ULL;
            aOrbiterG = RotL64((aOrbiterG * 0x97E96978A8EB576DULL), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 0xC9538BA1E1C9C61CULL) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 0x26E86D1A997B22F8ULL;
            aOrbiterE = RotL64((aOrbiterE * 0x4670B299D2C5BAF1ULL), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 0xDF759BBDC9CC6ECDULL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 0x0ADDD3164AF745F4ULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0xC6BBBC06D1A46613ULL), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 0x6390425A7BDD377FULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 0x7DA49025B78BF684ULL;
            aOrbiterF = RotL64((aOrbiterF * 0xD8851639F2541791ULL), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 0x3754273B38B4FA6FULL;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 0x78F5A527EAA2C6F4ULL;
            aOrbiterB = RotL64((aOrbiterB * 0x19B40E4A974BFBEDULL), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 0x8FCB0AFB8F0A979CULL;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 0x0234C9369CDA48CBULL;
            aOrbiterI = RotL64((aOrbiterI * 0xD1F926B4392880A7ULL), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 0x1EEC5FA96448A75DULL) + aNonceWordP;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 0x49EB0A52F56765E2ULL;
            aOrbiterH = RotL64((aOrbiterH * 0xA512B8F1EA0F7EBBULL), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 0x4566D3906BC7D363ULL;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 0xAE8621F996671113ULL) ^ aOUSaltA[((aIndex + 490U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 0x822575F561D71E4FULL), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 0x32E0E644330667BFULL;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 0x03F54D5C79E27AFDULL;
            aOrbiterC = RotL64((aOrbiterC * 0x2F323B78E65D9F99ULL), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 0xB40CF80AF89B5150ULL) + aOUSaltG[(((511U - aIndex) + 95U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 0x534BED22DE16DE70ULL) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 0xEB2DE7CFDA62E189ULL), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 22U);
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterH, 23U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 37U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 51U)) + aOrbiterJ);
            aWandererF = aWandererF ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterC, 43U)) + aOrbiterK) + aWUSaltC[(((511U - aIndex) + 293U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterG, 58U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 12U) + RotL64(aOrbiterF, 19U)) + aOrbiterD);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterE, 47U)) + aNonceWordH) + aWUSaltE[((aIndex + 213U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterG, 29U)) + aOrbiterC) + aNonceWordO);
            aWandererI = aWandererI + (((RotL64(aIngress, 23U) + aOrbiterH) + RotL64(aOrbiterB, 54U)) + aWUSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 11U)) + aOrbiterA) + aWUSaltB[(((511U - aIndex) + 28U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 46U) + RotL64(aOrbiterK, 13U)) + aOrbiterI) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 56U));
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 44U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aArcaneLaneC[(aIndex) & W_KEY1] = aIngress;
        }
    
        //
        // File: nexus_08/loop_000243.bin
        //
        // Head:        [4, 7, 3, 6, 5, 2, 8, 9, 1, 10, 0]
        // Tail A:      [3, 9, 2, 6, 4, 1, 8, 5, 7, 10, 0]
        // Tail B:      [8, 4, 7, 3, 6, 2, 0, 10, 9, 1, 5]
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
        // Orbiters:    [JGAFCBKHEDI]
        // Wanderers:   [GKDFAHIEJBC]
        //
        // Ingress:     aArcaneLaneC (-->), aArcaneLaneA (-->), aCrystalLaneD (-->), aSonicLaneB (<-?->)
        //
        // Cross:       aArcaneLaneB (<--), aEarthLaneD (<--), aRunicLaneB (<--), aDivinationLaneC (<-?->)
        //
        // Destination: aArcaneLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aArcaneLaneC[((aIndex + 23U)) & W_KEY1], 30U) ^ RotL64(aArcaneLaneA[((aIndex + 1094U)) & W_KEY1], 11U));
            aIngress ^= (RotL64(aCrystalLaneD[((aIndex + 795U)) & W_KEY1], 41U) ^ RotL64(aSonicLaneB[(((2047U - aIndex) + 241U)) & W_KEY1], 19U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aKeySpawnADomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aArcaneLaneB[(((2047U - aIndex) + 143U)) & W_KEY1], 37U) ^ RotL64(aEarthLaneD[(((2047U - aIndex) + 425U)) & W_KEY1], 51U));
            aCross ^= (RotL64(aRunicLaneB[(((2047U - aIndex) + 1798U)) & W_KEY1], 4U) ^ RotL64(aDivinationLaneC[(((2047U - aIndex) + 1967U)) & W_KEY1], 27U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aKeySpawnADomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 42U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aKeySpawnADomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterJ = ((aWandererA + RotL64(aCross, 5U)) + 0x49A7075690EAC2B3ULL) + aOASaltD[((aIndex + 368U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 0x09E10F13A8B03546ULL;
            aOrbiterA = (aWandererF + RotL64(aScatter, 37U)) + 0x4EEA717A7C638B35ULL;
            aOrbiterF = (((aWandererI + RotL64(aPrevious, 12U)) + 0xE384B84E6BD4ED0DULL) + aOASaltF[((aIndex + 40U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = (aWandererH + RotL64(aCross, 35U)) + 0x3072A83150E6E992ULL;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 37U)) + 0x84A5F44814989449ULL;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 23U)) + 0xCA5B5C591BD1A4CEULL;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 18U)) + 0xF5534A0ACC6F3D53ULL;
            aOrbiterE = (((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 11U)) + 0x2EF393C264CE8896ULL) + aNonceWordL;
            aOrbiterD = (aWandererC + RotL64(aIngress, 43U)) + 0x5242A8EA13ECAA53ULL;
            aOrbiterI = (((aWandererG + RotL64(aScatter, 57U)) + 0xBE081636F4208118ULL) + aOASaltG[((aIndex + 82U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 0x71D348DDDBB704A8ULL) + aOUSaltB[(((511U - aIndex) + 175U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 0x3F54CCA2741DD614ULL;
            aOrbiterA = RotL64((aOrbiterA * 0x2A0E439226525FCBULL), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 0xD8FE3B0354968249ULL) + aOUSaltA[((aIndex + 365U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 0xA351CA3A38574456ULL;
            aOrbiterB = RotL64((aOrbiterB * 0xD56C14AA6E43C649ULL), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 0x939DBF46A73D5D9CULL;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 0xEEE72F5D7E15D6DEULL;
            aOrbiterE = RotL64((aOrbiterE * 0xC89340C2B46F1645ULL), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 0x37B85829A87C8E32ULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 0xAD2F5269FB3AF132ULL;
            aOrbiterD = RotL64((aOrbiterD * 0x526E2EF3F70F924DULL), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 0xEEFA87D8BCCF727AULL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 0xF664D3CDC2B703FAULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0x29433041F382F1D7ULL), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 0xC263638916FD47B6ULL;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 0xD40EFA03D9E027E2ULL;
            aOrbiterC = RotL64((aOrbiterC * 0xEDBE2D4B57F46245ULL), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 0x75481B1D0B99A8DEULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 0x183E1521B2646B6AULL;
            aOrbiterK = RotL64((aOrbiterK * 0xCB0C3FA6FC1E4CB3ULL), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 0x5399612843AEFD2EULL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 0x4FC46BF8E7191B51ULL) ^ aOUSaltE[((aIndex + 64U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 0x8D670C3280A7A39DULL), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 0x2DA5EAC942FA2FBCULL;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 0x4DBE3123762A39BCULL) ^ aOUSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 0x1B4A4A891226ADAFULL), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 0x466BF76AB2914441ULL) + aOUSaltD[(((511U - aIndex) + 237U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 0xED88AE8B1BB69D47ULL;
            aOrbiterG = RotL64((aOrbiterG * 0x75AB15DDFB51E9E1ULL), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 0x2C078198293714B2ULL) + aNonceWordF;
            aOrbiterF = (((aOrbiterF ^ aOrbiterH) ^ 0x9D9E460EDAD34BD4ULL) ^ aOUSaltG[(((511U - aIndex) + 343U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 0xB12BA3365F45E5D3ULL), 27U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 18U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 37U)) + aOrbiterE) + aNonceWordJ);
            aWandererK = aWandererK + ((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 35U)) + aOrbiterC);
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 3U)) + aOrbiterH) + RotL64(aCarry, 29U)) + aNonceWordI);
            aWandererF = aWandererF + (((RotL64(aCross, 43U) + RotL64(aOrbiterK, 22U)) + aOrbiterF) + aWUSaltE[(((511U - aIndex) + 470U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterK, 53U)) + aWUSaltG[(((511U - aIndex) + 241U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 30U) + RotL64(aOrbiterG, 11U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterJ, 47U));
            aWandererE = aWandererE + (((RotL64(aCross, 23U) + RotL64(aOrbiterB, 5U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 28U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aScatter, 60U) + RotL64(aOrbiterI, 51U)) + aOrbiterG) + aWUSaltH[(((511U - aIndex) + 421U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 19U)) + aOrbiterB) + aWUSaltC[(((511U - aIndex) + 121U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 56U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 20U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aArcaneLaneD[((2047U - aIndex)) & W_KEY1] = aIngress;
        }
    }
    WRITE_OUT_MUTABLE_PARAMS;
}
