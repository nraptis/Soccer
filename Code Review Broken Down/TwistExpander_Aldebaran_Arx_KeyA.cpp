void TwistExpander_Aldebaran_Arx::KEY_A_A_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS) {
    std::uint64_t *aOASaltA = pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterAssign.mSaltA;
    std::uint64_t *aOASaltB = pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterAssign.mSaltB;
    std::uint64_t *aOASaltC = pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterAssign.mSaltC;
    std::uint64_t *aOASaltD = pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterAssign.mSaltD;
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
    std::uint8_t *aCrystalLaneA = ALDEBARAN_KEY_A_A_CrystalLaneA;
    std::uint8_t *aCrystalLaneB = ALDEBARAN_KEY_A_A_CrystalLaneB;
    std::uint8_t *aCrystalLaneC = ALDEBARAN_KEY_A_A_CrystalLaneC;
    std::uint8_t *aCrystalLaneD = ALDEBARAN_KEY_A_A_CrystalLaneD;
    std::uint8_t *aSonicLaneC = ALDEBARAN_KEY_A_A_SonicLaneC;
    std::uint8_t *aPlanarLaneA = ALDEBARAN_KEY_A_A_PlanarLaneA;
    std::uint8_t *aArcaneLaneA = ALDEBARAN_KEY_A_A_ArcaneLaneA;
    std::uint8_t *aArcaneLaneB = ALDEBARAN_KEY_A_A_ArcaneLaneB;
    std::uint8_t *aArcaneLaneC = ALDEBARAN_KEY_A_A_ArcaneLaneC;
    std::uint8_t *aArcaneLaneD = ALDEBARAN_KEY_A_A_ArcaneLaneD;
    std::uint8_t *aRunicLaneC = ALDEBARAN_KEY_A_A_RunicLaneC;
    std::uint8_t *aAbjurationLaneA = ALDEBARAN_KEY_A_A_AbjurationLaneA;
    std::uint8_t *aEarthLaneA = ALDEBARAN_KEY_A_A_EarthLaneA;
    std::uint8_t *aEarthLaneB = ALDEBARAN_KEY_A_A_EarthLaneB;
    std::uint8_t *aEarthLaneC = ALDEBARAN_KEY_A_A_EarthLaneC;
    std::uint8_t *aEarthLaneD = ALDEBARAN_KEY_A_A_EarthLaneD;
    std::uint8_t *aWindLaneA = ALDEBARAN_KEY_A_A_WindLaneA;
    std::uint8_t *aLightningLaneB = ALDEBARAN_KEY_A_A_LightningLaneB;
    std::uint8_t *aLightningLaneD = ALDEBARAN_KEY_A_A_LightningLaneD;
    std::uint8_t *aAuguryLaneB = ALDEBARAN_KEY_A_A_AuguryLaneB;
    const std::uint64_t &aKeySpawnADomainWordIngress = pWorkSpace->mDomainBundle.mKeySpawnAConstants.mIngress;
    const std::uint64_t &aKeySpawnADomainWordScatter = pWorkSpace->mDomainBundle.mKeySpawnAConstants.mScatter;
    const std::uint64_t &aKeySpawnADomainWordCross = pWorkSpace->mDomainBundle.mKeySpawnAConstants.mCross;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [key arx]
    READ_IN_MUTABLE_PARAMS;
    const std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD010A73FB956AB2FULL + 0xFA5C57A666C5E5E1ULL);
    const std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xCACEBB2E58B31F75ULL + 0xB79A485BE9692353ULL);
    const std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xBC7F0D60AA2A6111ULL + 0x819ABB375E6358ADULL);
    const std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x97B5E07E9AD29937ULL + 0xC57C6F13BE5D7B14ULL);
    const std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x93F04D215BF0BF6FULL + 0xB64AF80C11781D3EULL);
    const std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8DB40F782E6A36FDULL + 0x800B99D2F552DA54ULL);
    const std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x86F0D0AC2B8D802BULL + 0xDBDBB166C0A2A847ULL);
    const std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9677CF0273097A09ULL + 0xECA8FA3F007B0FDEULL);
    const std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xBBE610242E43291BULL + 0xA46A47A5560D82ECULL);
    const std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xBEFE6BA7D08E249FULL + 0xB658810F318ADEAAULL);
    const std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB47D13E425B6CA2DULL + 0xB7F7F188178FDE8EULL);
    const std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xAC24A141930932B1ULL + 0xEBA384FBBB0FF0A1ULL);
    const std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x8F1EBA1D71167909ULL + 0xDDDE5CF72416D93AULL);
    const std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xCBFB75003F608DB5ULL + 0xE6CA49582DAE5FA4ULL);
    const std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xEEAA784FC399E1F3ULL + 0xEA2C1D609AD2569AULL);
    const std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xF1A425CC75D97BB1ULL + 0x838CEE94B5CB9A1FULL);
    {
        //
        // File: nexus_02/loop_000331.bin
        //
        // Head:        [7, 2, 1, 5, 0, 6, 3, 8, 9, 10, 4]
        // Tail A:      [7, 8, 10, 5, 0, 4, 2, 1, 6, 9, 3]
        // Tail B:      [10, 4, 6, 9, 8, 1, 7, 5, 3, 2, 0]
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
        // Orbiters:    [JCFGEKHBAID]
        // Wanderers:   [KFDEAHCBIJG]
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
            aIngress = (RotL64(aEarthLaneA[((aIndex + 1185U)) & W_KEY1], 23U) ^ RotL64(aEarthLaneB[((aIndex + 951U)) & W_KEY1], 5U));
            aIngress ^= (RotL64(aEarthLaneC[((aIndex + 1411U)) & W_KEY1], 39U) ^ RotL64(aEarthLaneD[((aIndex + 894U)) & W_KEY1], 58U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aKeySpawnADomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aCrystalLaneA[(((2047U - aIndex) + 481U)) & W_KEY1], 46U) ^ RotL64(aCrystalLaneB[(((2047U - aIndex) + 1534U)) & W_KEY1], 37U));
            aCross ^= (RotL64(aCrystalLaneC[(((2047U - aIndex) + 292U)) & W_KEY1], 27U) ^ RotL64(aCrystalLaneD[(((2047U - aIndex) + 1345U)) & W_KEY1], 11U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aKeySpawnADomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 5U)) + (RotL64(aCarry, 24U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aKeySpawnADomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = (aWandererB + RotL64(aIngress, 19U)) + 0x496CF381347B4791ULL;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 39U)) + 0x6F5DDBAA59B2A4A4ULL) + aOASaltH[(((511U - aIndex) + 429U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 12U)) + RotL64(aCarry, 47U)) + 0xA09D373F6968F445ULL;
            aOrbiterG = ((aWandererH + RotL64(aCross, 35U)) + 0x9A751C9E040C5B40ULL) + aOASaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aIngress, 37U)) + 0x77A830205CDF1768ULL;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 27U)) + 0x14D20A0A8F05A68EULL) + aNonceWordA;
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 0x8B0E187413E5DC09ULL) + aNonceWordK;
            aOrbiterB = (aWandererI + RotL64(aCross, 57U)) + 0x78B16F0D43028A9AULL;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 22U)) + 0xA68E5C353776AE91ULL;
            aOrbiterI = (((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 13U)) + 0x5D03A3D2661D5A37ULL) + aOASaltB[(((511U - aIndex) + 267U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aPrevious, 41U)) + 0x147B36FDCEF36091ULL;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 0x9888A02572C4549CULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 0x3F35EE45F2C883F0ULL;
            aOrbiterF = RotL64((aOrbiterF * 0x3CE92E4DD073D4ABULL), 37U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterE) + 0xA0EC61A5CC27CFE6ULL) + aOUSaltA[(((511U - aIndex) + 99U)) & S_SALT1]) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 0x9F7AD64A140C9C9AULL;
            aOrbiterK = RotL64((aOrbiterK * 0x9CBA2951C72874ABULL), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 0x17534E6D302C47A6ULL;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 0xAA1789B1CC27B98FULL) ^ aOUSaltG[((aIndex + 241U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 0x7DDF0F128193B78DULL), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 0xE98B3E3933A64C2DULL;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 0xC7F761711EDB0F29ULL;
            aOrbiterC = RotL64((aOrbiterC * 0x4911BE258984CE11ULL), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 0xE24ABC53BE1F8939ULL;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 0xE18DB81357BB0CFEULL) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 0x7ED7414A361A70C7ULL), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 0xA2453EA14EC9E483ULL) + aOUSaltE[((aIndex + 359U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 0x93C234B5DFBA2935ULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0x049E94EE4684D207ULL), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 0x9CCA9BC119F12391ULL;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 0xC82EA6ED1DBB12EFULL) ^ aOUSaltC[((aIndex + 496U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 0x287D0909236B6F6DULL), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 0x37B831C886B38A1DULL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 0xA862D4D936A93995ULL) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 0x04ED0143E68F660FULL), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 0x4E118D7DBBD08EDEULL) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 0x012CD53EC61AC6DBULL;
            aOrbiterI = RotL64((aOrbiterI * 0xCD3CA58B9E274769ULL), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 0x97513BAA6A0E2AD6ULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 0x291B43BDBD5C5418ULL;
            aOrbiterA = RotL64((aOrbiterA * 0x283F503B87F68D3FULL), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 0xCECDABA938B068CFULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 0x725E3D0E7E3EDA60ULL;
            aOrbiterD = RotL64((aOrbiterD * 0x2F3CC64D0307793FULL), 39U);
            //
            aIngress = RotL64(aOrbiterD, 5U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 30U));
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + RotL64(aOrbiterG, 10U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterD, 51U)) + aNonceWordD);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterE, 20U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 43U)) + aOrbiterH) + aWUSaltF[(((511U - aIndex) + 77U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterK, 13U)) + aOrbiterI) + aNonceWordP);
            aWandererA = aWandererA + ((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 27U)) + aOrbiterA);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 34U) + aOrbiterE) + RotL64(aOrbiterC, 22U)) + RotL64(aCarry, 27U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterB, 3U)) + aNonceWordB) + aWUSaltD[((aIndex + 474U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterK, 37U)) + aNonceWordL);
            aWandererI = aWandererI + (((RotL64(aIngress, 47U) + aOrbiterH) + RotL64(aOrbiterG, 35U)) + aWUSaltA[(((511U - aIndex) + 157U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 58U) + aOrbiterI) + RotL64(aOrbiterF, 11U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 29U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 58U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + RotL64(aWandererE, 21U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aArcaneLaneA[(aIndex) & W_KEY1] = aIngress;
        }
    
        //
        // File: nexus_09/loop_000526.bin
        //
        // Head:        [2, 4, 3, 0, 9, 8, 6, 7, 1, 10, 5]
        // Tail A:      [8, 9, 3, 10, 6, 7, 2, 5, 4, 1, 0]
        // Tail B:      [2, 1, 8, 7, 3, 0, 6, 4, 9, 10, 5]
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
        // Orbiters:    [ICDKBGEHJAF]
        // Wanderers:   [EHGIFDJBCKA]
        //
        // Ingress:     aArcaneLaneA (-->), aCrystalLaneA (-->), aCrystalLaneB (-->), aSonicLaneC (<-?->)
        //
        // Cross:       aEarthLaneA (<--), aEarthLaneB (<--), aAbjurationLaneA (<--), aLightningLaneB (<-?->)
        //
        // Destination: aArcaneLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aArcaneLaneA[((aIndex + 182U)) & W_KEY1], 29U) ^ RotL64(aCrystalLaneA[((aIndex + 1564U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(aCrystalLaneB[((aIndex + 660U)) & W_KEY1], 21U) ^ RotL64(aSonicLaneC[(((2047U - aIndex) + 9U)) & W_KEY1], 3U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aKeySpawnADomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aEarthLaneA[(((2047U - aIndex) + 1061U)) & W_KEY1], 47U) ^ RotL64(aEarthLaneB[(((2047U - aIndex) + 1505U)) & W_KEY1], 36U));
            aCross ^= (RotL64(aAbjurationLaneA[(((2047U - aIndex) + 1937U)) & W_KEY1], 21U) ^ RotL64(aLightningLaneB[((aIndex + 1602U)) & W_KEY1], 5U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aKeySpawnADomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 20U)) + (RotL64(aCross, 5U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aKeySpawnADomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterI = (aWandererG + RotL64(aScatter, 29U)) + 0x73577F67ECD9DD7BULL;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 47U)) + 0xAECF510D6A1BDB3AULL;
            aOrbiterD = (aWandererI + RotL64(aCross, 50U)) + 0x7DABE8C36176A520ULL;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 29U)) + 0x98F0C1DFD17C8DFDULL;
            aOrbiterB = (((aWandererK + RotL64(aScatter, 13U)) + 0x695860A0A6163EABULL) + aOASaltC[(((511U - aIndex) + 272U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 41U)) + 0xF6E560EAA5CF1140ULL) + aOASaltH[((aIndex + 265U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aCross, 23U)) + 0x439E3D1DEAA8A14BULL;
            aOrbiterH = (((aWandererB + RotL64(aIngress, 27U)) + RotL64(aCarry, 21U)) + 0xE602A8EA550F68C9ULL) + aOASaltD[((aIndex + 93U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aScatter, 35U)) + 0x06B8279F13890F36ULL;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 11U)) + 0x5DBA691090C33513ULL) + aNonceWordC;
            aOrbiterF = (((aWandererD + RotL64(aCross, 58U)) + RotL64(aCarry, 11U)) + 0x3168B2BC7F253CF6ULL) + aOASaltA[((aIndex + 319U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 0x8250DE5A887EF820ULL;
            aOrbiterD = (((aOrbiterD ^ aOrbiterI) ^ 0x1D059C4EFDDA0CABULL) ^ aOUSaltC[(((511U - aIndex) + 407U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 0x929E279BE9FBE6DFULL), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 0xE308447BA9D01E25ULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 0xB173C17A0B0E6F3CULL;
            aOrbiterG = RotL64((aOrbiterG * 0xD997D1888BBE1A41ULL), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 0x118BF0F82B23256BULL;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 0x2A774745D61849F8ULL) ^ aOUSaltB[((aIndex + 463U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 0xA39B94BE9FCD690DULL), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 0x13926AAF4921ADD9ULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 0xFA666D9B73D1EFCCULL;
            aOrbiterA = RotL64((aOrbiterA * 0x336B01C518F38DA7ULL), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 0x920B19DFAC07D934ULL;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 0x8861C6036BA826E7ULL;
            aOrbiterI = RotL64((aOrbiterI * 0x5828C25535DA25CDULL), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 0x1610182C0E46F7A4ULL;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 0x527EF498E41BA478ULL) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 0x0C2225E0F1DBF3E5ULL), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 0xD62F1EB50AF56939ULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 0x24296BDE9E15140FULL;
            aOrbiterK = RotL64((aOrbiterK * 0xB179FC3E1AC4CACFULL), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 0x992C3AE4939F0767ULL;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 0xB82E0B626618F32CULL;
            aOrbiterC = RotL64((aOrbiterC * 0x010EED857B79D2ABULL), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 0xCB977CB914E036F4ULL;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 0xE369BE6BFB2D3209ULL) ^ aOUSaltA[((aIndex + 328U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 0x7A63AE751CCE7BBFULL), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 0x2F591C69B37CC124ULL) + aNonceWordO;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 0xF018E9040A728B95ULL) ^ aOUSaltH[(((511U - aIndex) + 501U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 0xB5D3BBD1ADF946D7ULL), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 0x198B58AC5550572CULL;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 0x4DD9F4F422A3F68CULL) ^ aOUSaltF[(((511U - aIndex) + 166U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 0xAA89FC7CCF5A6283ULL), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 6U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 48U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 26U) + RotL64(aOrbiterJ, 39U)) + aOrbiterD);
            aWandererH = aWandererH + ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterC, 3U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 53U)) + aOrbiterJ) + RotL64(aCarry, 35U));
            aWandererI = aWandererI + (((RotL64(aCross, 11U) + RotL64(aOrbiterF, 47U)) + aOrbiterH) + aWUSaltH[(((511U - aIndex) + 394U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 41U)) + aOrbiterK) + aWUSaltC[(((511U - aIndex) + 436U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterI, 50U)) + aNonceWordK);
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterE, 57U)) + aNonceWordD) + aWUSaltG[((aIndex + 281U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 6U) + aOrbiterG) + RotL64(aOrbiterB, 5U));
            aWandererC = aWandererC ^ (((((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 13U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aNonceWordG) + aWUSaltE[((aIndex + 269U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterF, 20U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 43U)) + aOrbiterG) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aArcaneLaneB[((2047U - aIndex)) & W_KEY1] = aIngress;
        }
    
        //
        // File: nexus_00/loop_000559.bin
        //
        // Head:        [6, 7, 1, 3, 10, 2, 0, 5, 8, 4, 9]
        // Tail A:      [9, 0, 8, 7, 2, 3, 4, 6, 1, 5, 10]
        // Tail B:      [0, 4, 3, 1, 8, 9, 5, 10, 2, 6, 7]
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
        // Orbiters:    [AIDCHKBEGFJ]
        // Wanderers:   [BKHGDFEICJA]
        //
        // Ingress:     aArcaneLaneB (-->), aCrystalLaneC (-->), aPlanarLaneA (-->), aWindLaneA (<-?->)
        //
        // Cross:       aArcaneLaneA (<--), aEarthLaneC (<--), aAuguryLaneB (<--), aLightningLaneD (<-?->)
        //
        // Destination: aArcaneLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aArcaneLaneB[((aIndex + 1100U)) & W_KEY1], 13U) ^ RotL64(aCrystalLaneC[((aIndex + 785U)) & W_KEY1], 39U));
            aIngress ^= (RotL64(aPlanarLaneA[((aIndex + 1555U)) & W_KEY1], 47U) ^ RotL64(aWindLaneA[((aIndex + 1269U)) & W_KEY1], 5U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aKeySpawnADomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aArcaneLaneA[(((2047U - aIndex) + 625U)) & W_KEY1], 56U) ^ RotL64(aEarthLaneC[(((2047U - aIndex) + 1684U)) & W_KEY1], 21U));
            aCross ^= (RotL64(aAuguryLaneB[(((2047U - aIndex) + 1125U)) & W_KEY1], 13U) ^ RotL64(aLightningLaneD[((aIndex + 532U)) & W_KEY1], 29U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aKeySpawnADomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCarry, 57U) + RotL64(aIngress, 24U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aKeySpawnADomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterA = ((((aWandererE + RotL64(aPrevious, 41U)) + RotL64(aCarry, 21U)) + 0x348C2F1F742ACF25ULL) + aOASaltG[(((511U - aIndex) + 45U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = (aWandererI + RotL64(aCross, 53U)) + 0xABCD9CB5576BE5C8ULL;
            aOrbiterD = (aWandererK + RotL64(aIngress, 43U)) + 0x5D3B86C43F4B0902ULL;
            aOrbiterC = (((aWandererG + RotL64(aScatter, 24U)) + 0x34FE1435AAABB02EULL) + aOASaltH[(((511U - aIndex) + 254U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 13U)) + 0x24B964348781940DULL) + aOASaltF[((aIndex + 365U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aCross, 37U)) + 0x5F5168C9E4415821ULL;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 27U)) + 0xB5736394BD30F30DULL) + aOASaltA[((aIndex + 149U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aScatter, 19U)) + 0xAEC89CEDABB0A2C2ULL) + aOASaltB[(((511U - aIndex) + 337U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 39U)) + 0x44A6C72626C7D454ULL;
            aOrbiterF = ((aWandererD + RotL64(aCross, 58U)) + 0x2ABB34F6159B9D4BULL) + aNonceWordC;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 51U)) + 0x5CFA8D986A2AB464ULL) + aNonceWordE;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 0x151F988C4728D4B3ULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 0x9F5D669C50D91AF7ULL;
            aOrbiterD = RotL64((aOrbiterD * 0xC6E8C8EBA55C10C3ULL), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 0x69D2A82BF0DDA6DAULL) + aOUSaltB[((aIndex + 82U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 0xB15D3B1BA1EEA86DULL) ^ aOUSaltG[(((511U - aIndex) + 396U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 0x842A9A311F1C1E6DULL), 41U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterD) + 0x2BF01A38271FAC2AULL) + aOUSaltE[(((511U - aIndex) + 63U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 0xE29F4950E1A5BB2DULL) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 0x3F6E34FE9D18EC05ULL), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 0x47D2AC78893C70A6ULL) + aOUSaltH[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 0x72EC1BEC7F264914ULL) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 0x81728A0C169A3BA9ULL), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 0x834BA60244AC1F03ULL) + aOUSaltA[((aIndex + 495U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 0x42C6750B64791290ULL;
            aOrbiterA = RotL64((aOrbiterA * 0x5335372E36FEFEFDULL), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 0xA7CF2E3B0F4580D9ULL;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 0xE9F67CEF3686DC0CULL;
            aOrbiterH = RotL64((aOrbiterH * 0xED70A78D7A456F2BULL), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 0xEAEC5F572BE3B9ECULL) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 0xC6ADAD5EAA99FD2DULL;
            aOrbiterC = RotL64((aOrbiterC * 0x40DD6445878E9577ULL), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 0x4A0DDC49949E6EE4ULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 0x1DEB0BA51C59D326ULL;
            aOrbiterF = RotL64((aOrbiterF * 0x08DE5465DA3AC245ULL), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 0xE34B6D06EEBC8B60ULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 0xED6025622FAEF2F7ULL;
            aOrbiterG = RotL64((aOrbiterG * 0x21A1FC4CB8A399A9ULL), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 0x2ED2DDA9470D2A1CULL;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 0xDF49F137F68FD170ULL;
            aOrbiterI = RotL64((aOrbiterI * 0x08B37F5CCFE2BBADULL), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 0x698BA68EB9D2B714ULL) + aOUSaltF[((aIndex + 217U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 0x3DFDF07573E0F551ULL;
            aOrbiterB = RotL64((aOrbiterB * 0x603942AC823BF56BULL), 13U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 26U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 3U)) + aWUSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 11U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 5U)) + aOrbiterC);
            aWandererG = aWandererG ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 57U)) + aOrbiterI) + aNonceWordI);
            aWandererD = aWandererD + (((RotL64(aIngress, 20U) + RotL64(aOrbiterD, 43U)) + aOrbiterG) + aNonceWordP);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterF, 38U)) + RotL64(aCarry, 53U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterK, 29U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterJ, 41U));
            aWandererC = aWandererC + ((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterD, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 48U)) + aOrbiterB) + aWUSaltH[(((511U - aIndex) + 480U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 50U) + RotL64(aOrbiterJ, 53U)) + aOrbiterE) + aWUSaltB[((aIndex + 266U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 30U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererH, 44U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aArcaneLaneC[(aIndex) & W_KEY1] = aIngress;
        }
    
        //
        // File: nexus_03/loop_000272.bin
        //
        // Head:        [7, 2, 5, 0, 3, 1, 4, 10, 8, 9, 6]
        // Tail A:      [0, 6, 8, 5, 2, 4, 7, 9, 10, 3, 1]
        // Tail B:      [10, 9, 2, 7, 1, 8, 3, 4, 6, 0, 5]
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
        // Orbiters:    [FEJCIDAHBKG]
        // Wanderers:   [GBKECJFADIH]
        //
        // Ingress:     aArcaneLaneC (-->), aArcaneLaneA (-->), aCrystalLaneD (-->), aAuguryLaneB (<-?->)
        //
        // Cross:       aArcaneLaneB (<--), aEarthLaneD (<--), aLightningLaneD (<--), aRunicLaneC (<-?->)
        //
        // Destination: aArcaneLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aArcaneLaneC[((aIndex + 1301U)) & W_KEY1], 13U) ^ RotL64(aArcaneLaneA[((aIndex + 1986U)) & W_KEY1], 57U));
            aIngress ^= (RotL64(aCrystalLaneD[((aIndex + 517U)) & W_KEY1], 3U) ^ RotL64(aAuguryLaneB[((aIndex + 818U)) & W_KEY1], 46U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aKeySpawnADomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aArcaneLaneB[(((2047U - aIndex) + 1810U)) & W_KEY1], 19U) ^ RotL64(aEarthLaneD[(((2047U - aIndex) + 1481U)) & W_KEY1], 57U));
            aCross ^= (RotL64(aLightningLaneD[(((2047U - aIndex) + 182U)) & W_KEY1], 41U) ^ RotL64(aRunicLaneC[(((2047U - aIndex) + 597U)) & W_KEY1], 27U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aKeySpawnADomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 26U)) ^ (RotL64(aCarry, 41U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aKeySpawnADomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterF = (aWandererA + RotL64(aCross, 6U)) + 0xAEAC2EDB78615D98ULL;
            aOrbiterE = (((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 0x0CD4264FDAC1A445ULL) + aNonceWordE;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 43U)) + 0x7DE90CA44A2341E7ULL) + aOASaltA[(((511U - aIndex) + 180U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aPrevious, 39U)) + 0xE6CCCF6B5ACC8E07ULL;
            aOrbiterI = ((aWandererE + RotL64(aCross, 13U)) + 0xA4FA8920D97B610CULL) + aOASaltF[(((511U - aIndex) + 329U)) & S_SALT1];
            aOrbiterD = (((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 39U)) + 0xF1D915B7BCAE0882ULL) + aOASaltG[(((511U - aIndex) + 485U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aScatter, 21U)) + 0xF2D4439B896870FCULL;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 29U)) + 0x51B7230921B721A5ULL) + aNonceWordF;
            aOrbiterB = ((aWandererD + RotL64(aCross, 53U)) + 0xD0261DACDBA3D8ACULL) + aOASaltH[(((511U - aIndex) + 357U)) & S_SALT1];
            aOrbiterK = (((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 53U)) + 0xCF9C4678AF033F92ULL) + aNonceWordB;
            aOrbiterG = (((aWandererF + RotL64(aScatter, 10U)) + 0x3196476C09054A9FULL) + aOASaltC[((aIndex + 49U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 0xAFA46F57D0392D7DULL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 0xCFA684F8CD3CCB5BULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0x8E2E65F459BB5657ULL), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 0x7894F7981BE271B4ULL;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 0x1AE2FC475F7E580DULL) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 0x5DFC087316D9E839ULL), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 0x9D37D06A6951218FULL;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 0x2966F45A39BB93D2ULL;
            aOrbiterH = RotL64((aOrbiterH * 0x411CF8CA2A789D2BULL), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 0x562D5436EBAF1823ULL;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 0x631C63B1EAC4385CULL) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 0xB70556977F1D0D4DULL), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 0xD6D97C31DBB770F6ULL;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 0x10453CEC892BD8A6ULL;
            aOrbiterI = RotL64((aOrbiterI * 0x3A20F1E5B6E21657ULL), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 0x2182167A6E478A25ULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 0x959E229BEB353312ULL;
            aOrbiterF = RotL64((aOrbiterF * 0x5208FC4CCE38DE93ULL), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 0xD88171CF6CF14E4BULL) + aOUSaltF[((aIndex + 257U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 0xD2358B7E87B7AC0EULL) ^ aOUSaltG[(((511U - aIndex) + 251U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 0x133E61B2A394BDBBULL), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 0xF450794F13533387ULL) + aOUSaltD[(((511U - aIndex) + 361U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 0xB28673F6CF3ACA68ULL;
            aOrbiterA = RotL64((aOrbiterA * 0x69548685881177D7ULL), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 0x7844ED4501971CDFULL;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 0x82890DC8E1056467ULL) ^ aOUSaltH[(((511U - aIndex) + 224U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 0x60A29187DE1E5013ULL), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 0x73497CB5576FB5AEULL;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 0x4FBEC97464340BB5ULL;
            aOrbiterB = RotL64((aOrbiterB * 0x9CD9D86DC0CFB265ULL), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 0x61BDF36D0CE7099AULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 0x8BB043F9E0D6EBACULL;
            aOrbiterG = RotL64((aOrbiterG * 0x8F8830CCEC7E8B23ULL), 13U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 35U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 28U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 21U)) + aOrbiterG) + aWUSaltH[((aIndex + 318U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 56U)) + aOrbiterK) + aNonceWordM);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 11U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aCross, 21U) + RotL64(aOrbiterD, 29U)) + aOrbiterH) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 14U) + RotL64(aOrbiterJ, 27U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterB, 5U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterC, 46U)) + aWUSaltD[((aIndex + 403U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterI, 3U)) + aWUSaltC[(((511U - aIndex) + 109U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 4U) + RotL64(aOrbiterG, 43U)) + aOrbiterA) + RotL64(aCarry, 37U));
            aWandererI = aWandererI + (((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 41U)) + aOrbiterF) + aWUSaltB[((aIndex + 230U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterE, 13U)) + aOrbiterD) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererD, 44U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 22U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aArcaneLaneD[((2047U - aIndex)) & W_KEY1] = aIngress;
        }
    }
    WRITE_OUT_MUTABLE_PARAMS;
}


void TwistExpander_Aldebaran_Arx::KEY_A_A_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS) {
    std::uint64_t *aOASaltA = pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterAssign.mSaltA;
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
    std::uint64_t *aWUSaltC = pWorkSpace->mDomainBundle.mKeySpawnASalts.mWandererUpdate.mSaltC;
    std::uint64_t *aWUSaltD = pWorkSpace->mDomainBundle.mKeySpawnASalts.mWandererUpdate.mSaltD;
    std::uint64_t *aWUSaltE = pWorkSpace->mDomainBundle.mKeySpawnASalts.mWandererUpdate.mSaltE;
    std::uint64_t *aWUSaltF = pWorkSpace->mDomainBundle.mKeySpawnASalts.mWandererUpdate.mSaltF;
    std::uint64_t *aWUSaltG = pWorkSpace->mDomainBundle.mKeySpawnASalts.mWandererUpdate.mSaltG;
    std::uint64_t *aWUSaltH = pWorkSpace->mDomainBundle.mKeySpawnASalts.mWandererUpdate.mSaltH;
    std::uint8_t *aVaporLaneA = ALDEBARAN_KEY_A_A_VaporLaneA;
    std::uint8_t *aVaporLaneB = ALDEBARAN_KEY_A_A_VaporLaneB;
    std::uint8_t *aVaporLaneC = ALDEBARAN_KEY_A_A_VaporLaneC;
    std::uint8_t *aVaporLaneD = ALDEBARAN_KEY_A_A_VaporLaneD;
    std::uint8_t *aFrostLaneA = ALDEBARAN_KEY_A_A_FrostLaneA;
    std::uint8_t *aFrostLaneC = ALDEBARAN_KEY_A_A_FrostLaneC;
    std::uint8_t *aFrostLaneD = ALDEBARAN_KEY_A_A_FrostLaneD;
    std::uint8_t *aGloomLaneC = ALDEBARAN_KEY_A_A_GloomLaneC;
    std::uint8_t *aAbjurationLaneC = ALDEBARAN_KEY_A_A_AbjurationLaneC;
    std::uint8_t *aAbjurationLaneD = ALDEBARAN_KEY_A_A_AbjurationLaneD;
    std::uint8_t *aSpiritLaneB = ALDEBARAN_KEY_A_A_SpiritLaneB;
    std::uint8_t *aFireLaneA = ALDEBARAN_KEY_A_A_FireLaneA;
    std::uint8_t *aWaterLaneA = ALDEBARAN_KEY_A_A_WaterLaneA;
    std::uint8_t *aWaterLaneB = ALDEBARAN_KEY_A_A_WaterLaneB;
    std::uint8_t *aWaterLaneC = ALDEBARAN_KEY_A_A_WaterLaneC;
    std::uint8_t *aWaterLaneD = ALDEBARAN_KEY_A_A_WaterLaneD;
    std::uint8_t *aDivinationLaneB = ALDEBARAN_KEY_A_A_DivinationLaneB;
    std::uint8_t *aIceLaneA = ALDEBARAN_KEY_A_A_IceLaneA;
    std::uint8_t *aWindLaneD = ALDEBARAN_KEY_A_A_WindLaneD;
    std::uint8_t *aEvocationLaneA = ALDEBARAN_KEY_A_A_EvocationLaneA;
    std::uint8_t *aVoodooLaneC = ALDEBARAN_KEY_A_A_VoodooLaneC;
    const std::uint64_t &aKeySpawnADomainWordIngress = pWorkSpace->mDomainBundle.mKeySpawnAConstants.mIngress;
    const std::uint64_t &aKeySpawnADomainWordScatter = pWorkSpace->mDomainBundle.mKeySpawnAConstants.mScatter;
    const std::uint64_t &aKeySpawnADomainWordCross = pWorkSpace->mDomainBundle.mKeySpawnAConstants.mCross;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [key arx]
    READ_IN_MUTABLE_PARAMS;
    const std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9574A2314E23E9B5ULL + 0xF6FCA11B7027597BULL);
    const std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xFCC70C922B549603ULL + 0x87AD944FAABB145FULL);
    const std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC872F067285BE82BULL + 0xA14835BED2BCD6BAULL);
    const std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBD541CD328C86727ULL + 0xDB280D7D330935AFULL);
    const std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC5B4632E5F70EB11ULL + 0x9E9608831B3B8E88ULL);
    const std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8AB5303EEF01DF25ULL + 0xF4F0266F41C4E6E6ULL);
    const std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8D78978C78BDE4CBULL + 0xBA3BEBD0491FB361ULL);
    const std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9418606C9D09F255ULL + 0x9929181F32519301ULL);
    const std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD28CCE4CFF651737ULL + 0x81381650EEF6F307ULL);
    const std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x9374D7BBCE3D3E4FULL + 0xB3AE06FA6D38DF58ULL);
    const std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xEA469D9355295B7FULL + 0xF0036F5AD12D227EULL);
    const std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xA4819123149F9481ULL + 0xB25D08339266E59FULL);
    const std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xE6327780FE863CDDULL + 0xA6FEE10A845A951FULL);
    const std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xBA89B0BB59C35675ULL + 0x855597503EE33694ULL);
    const std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8C6EAC8AB0CE2189ULL + 0xFD98E1157EFB31AFULL);
    const std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD45452094DD30167ULL + 0x9D3F91D1CCEC5EC1ULL);
    {
        //
        // File: nexus_01/loop_000309.bin
        //
        // Head:        [5, 7, 3, 4, 10, 9, 1, 2, 8, 6, 0]
        // Tail A:      [5, 2, 8, 10, 4, 7, 1, 3, 9, 0, 6]
        // Tail B:      [8, 9, 4, 0, 6, 1, 2, 7, 5, 3, 10]
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
        // Orbiters:    [BDCKAEJGHFI]
        // Wanderers:   [ABKEGJDCIFH]
        //
        // Ingress:     aWaterLaneD (-->), aWaterLaneB (-->), aWindLaneD (-->), aFireLaneA (<-?->)
        //
        // Cross:       aWaterLaneC (<--), aWaterLaneA (<--), aFrostLaneD (<--), aVoodooLaneC (<-?->)
        //
        // Destination: aVaporLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWaterLaneD[((aIndex + 1543U)) & W_KEY1], 27U) ^ RotL64(aWaterLaneB[((aIndex + 1262U)) & W_KEY1], 35U));
            aIngress ^= (RotL64(aWindLaneD[((aIndex + 1793U)) & W_KEY1], 11U) ^ RotL64(aFireLaneA[(((2047U - aIndex) + 146U)) & W_KEY1], 3U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aKeySpawnADomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aWaterLaneC[(((2047U - aIndex) + 51U)) & W_KEY1], 53U) ^ RotL64(aWaterLaneA[(((2047U - aIndex) + 901U)) & W_KEY1], 28U));
            aCross ^= (RotL64(aFrostLaneD[(((2047U - aIndex) + 866U)) & W_KEY1], 37U) ^ RotL64(aVoodooLaneC[((aIndex + 741U)) & W_KEY1], 3U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aKeySpawnADomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 10U) + RotL64(aCross, 23U)) ^ (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aKeySpawnADomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterB = ((((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 35U)) + 0xCFC7C2EEFBE282C1ULL) + aOASaltC[((aIndex + 417U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = (aWandererC + RotL64(aScatter, 56U)) + 0x1CD912CBDCFEDB7FULL;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 23U)) + 0xF3F28096414448D5ULL;
            aOrbiterK = ((((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 47U)) + 0x98356F8260AB3106ULL) + aOASaltG[(((511U - aIndex) + 83U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 43U)) + 0x1697B0FAD2D799E6ULL) + aNonceWordM;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 3U)) + 0x19CA180B2DA7BC93ULL) + aOASaltB[((aIndex + 206U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 53U)) + 0x76122EB5A4705588ULL) + aOASaltH[(((511U - aIndex) + 182U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 19U)) + 0x832681CE7C6B2A0AULL;
            aOrbiterH = (aWandererI + RotL64(aIngress, 27U)) + 0x8127BA0574A3415FULL;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 13U)) + 0x0EDEF34FC4765162ULL) + aNonceWordD;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 60U)) + 0xDB7DF8AD25F60CF3ULL;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 0x0A60EC058475588AULL;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 0xE6B24B7E65169AB1ULL;
            aOrbiterC = RotL64((aOrbiterC * 0x4EF78C97E20950CDULL), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 0xAB23ED3D98743A08ULL) + aOUSaltH[((aIndex + 350U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 0x204DC32E919CC903ULL;
            aOrbiterE = RotL64((aOrbiterE * 0xF657EFC8514D0BB9ULL), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 0x5D26E1E20E29ED8FULL) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 0x6535AA4FC971CC66ULL;
            aOrbiterG = RotL64((aOrbiterG * 0x049A2A58E290277BULL), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 0x0F3521C9F2FCFD81ULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 0x6A88EECF1A3711F7ULL;
            aOrbiterF = RotL64((aOrbiterF * 0xEFD3F7DE5768566DULL), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 0x3E3934C6A7BB18F4ULL;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 0x1BCCD4663EDF568FULL) ^ aOUSaltF[(((511U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 0xEDBF8646A640940DULL), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 0x6CBAFE8AF77B538DULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 0x76A0D7AC636D2F52ULL;
            aOrbiterD = RotL64((aOrbiterD * 0x0758EC3CC6D30DEFULL), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 0xB90D15AA6A5C3DC8ULL;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 0x83D524638BD958C0ULL) ^ aOUSaltG[((aIndex + 156U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 0xCC55A4FDE66066EBULL), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 0x828A4DDF4FCD1A16ULL) + aNonceWordC;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 0x4FAD4C844F64C919ULL) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 0xEF7121BF5A74595DULL), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 0x73FA670445C9FCACULL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 0xEF3CEA5F79A76C3BULL) ^ aOUSaltE[(((511U - aIndex) + 189U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 0x4CBFA93983D35D9FULL), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 0x7BE671945BC132E6ULL) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 0x67105F331FD45B95ULL;
            aOrbiterB = RotL64((aOrbiterB * 0x768574A4EF941883ULL), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 0xEA705545FD7D6A76ULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 0xE3A93C1D327A1935ULL;
            aOrbiterA = RotL64((aOrbiterA * 0x9A13DA68B8B7AB19ULL), 35U);
            //
            aIngress = RotL64(aOrbiterF, 14U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aIngress, 50U) + aOrbiterE) + RotL64(aOrbiterH, 40U)) + aNonceWordH) + aWUSaltD[(((511U - aIndex) + 149U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterF, 3U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 27U)) + aOrbiterA) + aNonceWordO) + aWUSaltG[((aIndex + 39U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((((RotL64(aCross, 29U) + RotL64(aOrbiterI, 19U)) + aOrbiterB) + RotL64(aCarry, 29U)) + aWUSaltE[((aIndex + 289U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 57U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 58U) + aOrbiterG) + RotL64(aOrbiterD, 11U)) + aWUSaltF[(((511U - aIndex) + 308U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 29U)) + aOrbiterC);
            aWandererC = aWandererC ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterK, 23U)) + aOrbiterG) + aWUSaltC[(((511U - aIndex) + 60U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterE, 34U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 47U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (RotL64(aWandererH, 20U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aVaporLaneA[(aIndex) & W_KEY1] = aIngress;
        }
    
        //
        // File: nexus_10/loop_000112.bin
        //
        // Head:        [6, 4, 7, 1, 10, 3, 9, 0, 8, 5, 2]
        // Tail A:      [10, 6, 9, 3, 5, 2, 1, 8, 7, 4, 0]
        // Tail B:      [1, 0, 5, 2, 10, 8, 6, 4, 3, 7, 9]
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
        // Orbiters:    [KIBAGEDCFHJ]
        // Wanderers:   [GCEHKDAIBJF]
        //
        // Ingress:     aVaporLaneA (-->), aWaterLaneC (-->), aDivinationLaneB (-->), aSpiritLaneB (<-?->)
        //
        // Cross:       aWaterLaneD (<--), aWaterLaneB (<--), aFrostLaneA (<--), aGloomLaneC (<-?->)
        //
        // Destination: aVaporLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aVaporLaneA[((aIndex + 293U)) & W_KEY1], 27U) ^ RotL64(aWaterLaneC[((aIndex + 485U)) & W_KEY1], 47U));
            aIngress ^= (RotL64(aDivinationLaneB[((aIndex + 160U)) & W_KEY1], 57U) ^ RotL64(aSpiritLaneB[((aIndex + 1611U)) & W_KEY1], 35U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aKeySpawnADomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aWaterLaneD[(((2047U - aIndex) + 1271U)) & W_KEY1], 3U) ^ RotL64(aWaterLaneB[(((2047U - aIndex) + 1062U)) & W_KEY1], 29U));
            aCross ^= (RotL64(aFrostLaneA[(((2047U - aIndex) + 476U)) & W_KEY1], 18U) ^ RotL64(aGloomLaneC[(((2047U - aIndex) + 349U)) & W_KEY1], 51U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aKeySpawnADomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 19U) + RotL64(aCarry, 40U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aKeySpawnADomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = (((aWandererA + RotL64(aScatter, 18U)) + 0xF86E5E7073174219ULL) + aOASaltA[((aIndex + 381U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 13U)) + 0xCE8C84973FA821B1ULL;
            aOrbiterB = (((aWandererI + RotL64(aCross, 3U)) + 0x8B1EB45885795AF7ULL) + aOASaltG[((aIndex + 111U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 21U)) + 0x156030AF4191EF24ULL) + aNonceWordB;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 27U)) + RotL64(aCarry, 23U)) + 0x7D9D36C215B4D95AULL;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 37U)) + 0x488303B809318F0DULL;
            aOrbiterD = (aWandererJ + RotL64(aCross, 39U)) + 0x4457CCC45D44E1CCULL;
            aOrbiterC = (aWandererG + RotL64(aIngress, 43U)) + 0x2F5BC985AE0935E9ULL;
            aOrbiterF = (((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 0x6436F0FA9FB01C88ULL) + aOASaltH[(((511U - aIndex) + 36U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aPrevious, 23U)) + 0x1694EB044C34A26DULL;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 54U)) + 0x28930545D6CF32DAULL) + aOASaltD[((aIndex + 237U)) & S_SALT1];
            //
            aOrbiterK = (((aOrbiterK + aOrbiterI) + 0x8E4A6DAAEDB75E97ULL) + aOUSaltA[(((511U - aIndex) + 179U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 0xF6D34B7697576765ULL;
            aOrbiterB = RotL64((aOrbiterB * 0x552E392E71F24843ULL), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 0x791726988513A940ULL) + aOUSaltB[(((511U - aIndex) + 73U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 0xA1F0884784929A61ULL;
            aOrbiterE = RotL64((aOrbiterE * 0x9A2B209637680DE1ULL), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 0x6C206D9AD445E2F1ULL) + aOUSaltE[((aIndex + 46U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 0xCCDFCDB981B73D8BULL;
            aOrbiterF = RotL64((aOrbiterF * 0x31EBB891F0A19CEBULL), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 0x6CEF74765F97F0EDULL;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 0xE7BD411AF51DB790ULL) ^ aOUSaltH[(((511U - aIndex) + 497U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 0x5E55C398CD069CBFULL), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 0xD239FC268F6C37D2ULL) + aNonceWordJ;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 0x57C31FA368DC68EDULL;
            aOrbiterI = RotL64((aOrbiterI * 0xF930407947AE3BEDULL), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 0x8F7707A4E63E1484ULL) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 0xBD0C598C19A43A58ULL;
            aOrbiterK = RotL64((aOrbiterK * 0xA0EBECD1D0E6547DULL), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 0x89D40C4A6FC8B4EAULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 0x655A5AE2BF56EE28ULL;
            aOrbiterA = RotL64((aOrbiterA * 0x3FB32F178D28B87FULL), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 0xDBEB9338E2D26FC1ULL) + aOUSaltD[(((511U - aIndex) + 292U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 0xD0A941A9455C2DF0ULL) ^ aOUSaltC[((aIndex + 176U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 0x6D560B91933CD271ULL), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 0x63922BB1026213AEULL;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 0x5B6288B1E4C30783ULL;
            aOrbiterC = RotL64((aOrbiterC * 0x598F85AF7DAB81ABULL), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 0x060FD558C24275B1ULL;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 0x97681AC594CCFDBBULL;
            aOrbiterH = RotL64((aOrbiterH * 0x428FDF09413E2E3BULL), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 0xC98C516202F831EDULL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 0x6C7E7749C0A46340ULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0x85869CF5A2A86931ULL), 5U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 30U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 35U)) + aOrbiterI) + aNonceWordA);
            aWandererC = aWandererC + (((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 39U)) + aOrbiterE) + aWUSaltH[((aIndex + 119U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 5U) + RotL64(aOrbiterA, 19U)) + aOrbiterB);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 14U)) + aOrbiterJ) + aNonceWordM);
            aWandererD = aWandererD + (((RotL64(aScatter, 50U) + aOrbiterB) + RotL64(aOrbiterF, 21U)) + aWUSaltF[(((511U - aIndex) + 281U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 29U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererI = aWandererI + (((RotL64(aCross, 57U) + RotL64(aOrbiterF, 23U)) + aOrbiterG) + aWUSaltA[((aIndex + 390U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 43U)) + aOrbiterA) + aNonceWordO) + aWUSaltG[(((511U - aIndex) + 436U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterC, 56U)) + aNonceWordK);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterK, 53U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererB, 58U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 6U));
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aVaporLaneB[((2047U - aIndex)) & W_KEY1] = aIngress;
        }
    
        //
        // File: nexus_11/loop_000043.bin
        //
        // Head:        [9, 2, 7, 3, 10, 5, 1, 0, 4, 6, 8]
        // Tail A:      [0, 9, 7, 1, 2, 8, 10, 6, 5, 4, 3]
        // Tail B:      [8, 3, 10, 6, 1, 2, 0, 5, 4, 9, 7]
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
        // Orbiters:    [EJCADHIBGFK]
        // Wanderers:   [CEKABJIHGFD]
        //
        // Ingress:     aVaporLaneB (-->), aWaterLaneD (-->), aFrostLaneC (-->), aIceLaneA (<-?->)
        //
        // Cross:       aVaporLaneA (<--), aWaterLaneC (<--), aAbjurationLaneC (<-?->)
        //
        // Destination: aVaporLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aVaporLaneB[((aIndex + 1575U)) & W_KEY1], 43U) ^ RotL64(aWaterLaneD[((aIndex + 2000U)) & W_KEY1], 57U));
            aIngress ^= (RotL64(aFrostLaneC[((aIndex + 645U)) & W_KEY1], 4U) ^ RotL64(aIceLaneA[(((2047U - aIndex) + 43U)) & W_KEY1], 35U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aKeySpawnADomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aVaporLaneA[(((2047U - aIndex) + 55U)) & W_KEY1], 28U) ^ RotL64(aWaterLaneC[(((2047U - aIndex) + 1743U)) & W_KEY1], 3U));
            aCross ^= RotL64(aAbjurationLaneC[(((2047U - aIndex) + 1623U)) & W_KEY1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aKeySpawnADomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 3U)) ^ (RotL64(aPrevious, 26U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aKeySpawnADomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 43U)) + 0xDBB6387E0B59BCC8ULL) + aOASaltC[(((511U - aIndex) + 365U)) & S_SALT1];
            aOrbiterJ = (((aWandererK + RotL64(aCross, 5U)) + 0xE29AFAAA5E344DE2ULL) + aOASaltG[(((511U - aIndex) + 272U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = (((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 13U)) + 0xB0351323BA825B8EULL) + aOASaltF[(((511U - aIndex) + 57U)) & S_SALT1];
            aOrbiterA = (((aWandererA + RotL64(aScatter, 53U)) + 0x87A125431543638FULL) + aOASaltH[((aIndex + 120U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 27U)) + 0xB3BC7C7DF5128811ULL) + aNonceWordC;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 43U)) + 0x43548E452D06591AULL;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 10U)) + 0xD540426E91DF6898ULL) + aNonceWordP;
            aOrbiterB = (aWandererC + RotL64(aScatter, 3U)) + 0x346EFE472385C653ULL;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 23U)) + 0x275C1B82D3097016ULL;
            aOrbiterF = (((aWandererI + RotL64(aCross, 41U)) + RotL64(aCarry, 27U)) + 0xCF518E306A31DD6EULL) + aOASaltB[((aIndex + 384U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aIngress, 60U)) + 0x5A2F7795B63FA832ULL;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 0xC85E3EECE0462CA0ULL;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 0x5F4F122CB56DE77EULL;
            aOrbiterC = RotL64((aOrbiterC * 0x4F6F65D62051D2F1ULL), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 0x315FCB03B141903FULL;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 0x64D70B7441A4FE5BULL;
            aOrbiterH = RotL64((aOrbiterH * 0x8F693BDA21BEC36BULL), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 0xB58EA3886BFAF2A8ULL;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 0x7DCF64E8CAABCF34ULL) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 0xAB2F92E10A629E9DULL), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 0x3DFB48F36522E125ULL;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 0x9842570E873D1E37ULL) ^ aOUSaltA[(((511U - aIndex) + 41U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 0x34DA177261C2B9F7ULL), 3U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterC) + 0xD7A30F992BB5B99CULL) + aOUSaltH[((aIndex + 504U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 0xEEE8B195DD3087ADULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0x81572B8698FDE225ULL), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 0xA74F2DF558D04989ULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 0x980A2E1F3D29276AULL;
            aOrbiterD = RotL64((aOrbiterD * 0xE42311D2DBF3DF31ULL), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 0x276308EDEBAD0C17ULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 0xB6D5FC1B279E949DULL;
            aOrbiterA = RotL64((aOrbiterA * 0x85C4C0ECB60A9DEFULL), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 0x1073822B10F2DC10ULL;
            aOrbiterI = (((aOrbiterI ^ aOrbiterD) ^ 0xC9715E47DD0655F3ULL) ^ aOUSaltF[((aIndex + 101U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 0x88EE5462A0A69DA9ULL), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 0x53A75D6C1887B2B5ULL;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 0xDD609B191B88AA42ULL) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 0x52EF598DC42A0B97ULL), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 0xB2468E73309D8AB5ULL) + aOUSaltB[(((511U - aIndex) + 113U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 0x6D25696D0BCF4516ULL;
            aOrbiterF = RotL64((aOrbiterF * 0x127C480E1EDA9055ULL), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 0xDF38C3BD7F51369EULL;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 0xA3F8F53EE9A7D4D4ULL;
            aOrbiterK = RotL64((aOrbiterK * 0x290E9574F1BD7921ULL), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 44U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterG, 41U)) + aWUSaltD[(((511U - aIndex) + 396U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 27U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aPrevious, 24U) + RotL64(aOrbiterB, 18U)) + aOrbiterK) + aWUSaltA[((aIndex + 37U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 47U)) + aOrbiterI) + aWUSaltG[(((511U - aIndex) + 136U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 57U)) + aOrbiterJ) + RotL64(aCarry, 51U)) + aNonceWordL);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterC, 5U)) + aNonceWordG);
            aWandererI = aWandererI + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 37U)) + aOrbiterE) + aNonceWordA);
            aWandererH = aWandererH ^ ((((RotL64(aCross, 53U) + RotL64(aOrbiterI, 11U)) + aOrbiterH) + aNonceWordH) + aWUSaltC[((aIndex + 425U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterD, 43U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 22U)) + aOrbiterF) + RotL64(aCarry, 47U)) + aWUSaltE[(((511U - aIndex) + 307U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 20U) + RotL64(aOrbiterA, 51U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 14U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 58U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aVaporLaneC[(aIndex) & W_KEY1] = aIngress;
        }
    
        //
        // File: nexus_13/loop_000091.bin
        //
        // Head:        [7, 9, 4, 5, 6, 3, 10, 8, 2, 1, 0]
        // Tail A:      [3, 4, 0, 8, 1, 7, 6, 9, 5, 10, 2]
        // Tail B:      [8, 10, 7, 0, 3, 9, 5, 2, 1, 6, 4]
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
        // Orbiters:    [BEAHCDGKJFI]
        // Wanderers:   [JGFCKEIBDHA]
        //
        // Ingress:     aVaporLaneC (-->), aVaporLaneA (-->), aEvocationLaneA (<-?->)
        //
        // Cross:       aVaporLaneB (<--), aWaterLaneD (<--), aAbjurationLaneD (<-?->)
        //
        // Destination: aVaporLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aVaporLaneC[((aIndex + 1392U)) & W_KEY1], 29U) ^ RotL64(aVaporLaneA[((aIndex + 427U)) & W_KEY1], 18U));
            aIngress ^= RotL64(aEvocationLaneA[((aIndex + 624U)) & W_KEY1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aKeySpawnADomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aVaporLaneB[(((2047U - aIndex) + 999U)) & W_KEY1], 46U) ^ RotL64(aWaterLaneD[(((2047U - aIndex) + 1974U)) & W_KEY1], 29U));
            aCross ^= RotL64(aAbjurationLaneD[(((2047U - aIndex) + 1534U)) & W_KEY1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aKeySpawnADomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 10U) + RotL64(aPrevious, 53U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aKeySpawnADomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterB = ((aWandererB + RotL64(aCross, 5U)) + 0x276B01B7C46EBB16ULL) + aOASaltE[((aIndex + 199U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aIngress, 21U)) + 0x92B0EEAC523022C4ULL;
            aOrbiterA = (aWandererK + RotL64(aScatter, 43U)) + 0xF81822BFB68E2AAEULL;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 47U)) + 0x2ADA9AA74EF63624ULL;
            aOrbiterC = (aWandererI + RotL64(aCross, 39U)) + 0x05B24E5DF29D25FDULL;
            aOrbiterD = (aWandererC + RotL64(aIngress, 48U)) + 0x66BE3BB18C6036A0ULL;
            aOrbiterG = (((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 3U)) + 0x3FB94AB1BF7D0DDFULL) + aOASaltC[(((511U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 23U)) + 0x31D4D21E6AD5F73EULL) + aOASaltD[(((511U - aIndex) + 161U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aCross, 53U)) + 0xA2667ECD3DB9AAD9ULL) + aNonceWordC;
            aOrbiterF = (aWandererG + RotL64(aIngress, 18U)) + 0x60F931576A6A9648ULL;
            aOrbiterI = ((((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 41U)) + 0x4D36E8E02D47B57FULL) + aOASaltH[((aIndex + 58U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 0x3F056FE11E15A0F4ULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 0x18BC7B2F5F710D63ULL;
            aOrbiterA = RotL64((aOrbiterA * 0xB4A8BD1FACB2EE19ULL), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 0xA7BD6A2B22DD5128ULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 0x38C93666A5129F3EULL;
            aOrbiterD = RotL64((aOrbiterD * 0x6AAF824A5273D67DULL), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 0x7AAB5014407642DEULL) + aOUSaltE[((aIndex + 106U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 0xEAC304C33D80EB96ULL;
            aOrbiterK = RotL64((aOrbiterK * 0xB23CD2A19C084D7BULL), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 0x5F49ECEF22C05D85ULL;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 0x7D710A5229233224ULL) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 0x5CB5ACA84D74AA93ULL), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 0xD19248CFA82E5443ULL;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 0xA827C689B63D5AB7ULL;
            aOrbiterE = RotL64((aOrbiterE * 0x5B02B2139D901C91ULL), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 0xA982B13AD337B595ULL) + aOUSaltB[((aIndex + 31U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 0x539F167497319027ULL;
            aOrbiterB = RotL64((aOrbiterB * 0xA6335ADB20EE3E43ULL), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 0xC5AFD71ED72E7874ULL;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 0xD9A415B9B20EE694ULL;
            aOrbiterH = RotL64((aOrbiterH * 0x1D57C5D8664B0E95ULL), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 0x3552A66DD3BB96FCULL) + aOUSaltH[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 0xE8FEBF66A7C69729ULL;
            aOrbiterG = RotL64((aOrbiterG * 0x2BA4C5ABA3F304F3ULL), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 0xDC0EB95CBE0B09B1ULL) + aNonceWordO;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 0x23A5689434880FA1ULL) ^ aOUSaltF[(((511U - aIndex) + 452U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 0xA55BE12CA12CB0E3ULL), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 0x96C477CB5D2E798CULL;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 0x1A91DB37BBB4AE35ULL) ^ aOUSaltD[((aIndex + 317U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 0x1DC130A671554407ULL), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 0x1E39AB5536E59714ULL;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 0xF8EC4FE9331D7624ULL;
            aOrbiterI = RotL64((aOrbiterI * 0x116E11E452D8B363ULL), 47U);
            //
            aIngress = RotL64(aOrbiterD, 37U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (RotL64(aOrbiterF, 6U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 39U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 21U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 3U)) + aOrbiterK) + aNonceWordL);
            aWandererC = aWandererC + (((RotL64(aCross, 60U) + RotL64(aOrbiterJ, 43U)) + aOrbiterB) + aNonceWordF);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 19U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterF, 53U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 56U)) + aOrbiterD) + aNonceWordB);
            aWandererB = aWandererB + ((((RotL64(aCross, 3U) + RotL64(aOrbiterF, 13U)) + aOrbiterA) + RotL64(aCarry, 23U)) + aWUSaltG[(((511U - aIndex) + 237U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 26U) + RotL64(aOrbiterD, 37U)) + aOrbiterE) + aWUSaltF[(((511U - aIndex) + 194U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 47U)) + aOrbiterG) + aWUSaltD[(((511U - aIndex) + 125U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 34U)) + aOrbiterC) + aWUSaltA[((aIndex + 345U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aVaporLaneD[((2047U - aIndex)) & W_KEY1] = aIngress;
        }
    }
    WRITE_OUT_MUTABLE_PARAMS;
}

void TwistExpander_Aldebaran_Arx::KEY_A_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint8_t *aAetherLaneB = ALDEBARAN_KEY_A_A_AetherLaneB;
    std::uint8_t *aAetherLaneD = ALDEBARAN_KEY_A_A_AetherLaneD;
    std::uint8_t *aKineticLaneA = ALDEBARAN_KEY_A_A_KineticLaneA;
    std::uint8_t *aSonicLaneA = ALDEBARAN_KEY_A_A_SonicLaneA;
    std::uint8_t *aPlanarLaneB = ALDEBARAN_KEY_A_A_PlanarLaneB;
    std::uint8_t *aLunarLaneA = ALDEBARAN_KEY_A_A_LunarLaneA;
    std::uint8_t *aRunicLaneA = ALDEBARAN_KEY_A_A_RunicLaneA;
    std::uint8_t *aSpiritLaneA = ALDEBARAN_KEY_A_A_SpiritLaneA;
    std::uint8_t *aSpiritLaneC = ALDEBARAN_KEY_A_A_SpiritLaneC;
    std::uint8_t *aRainbowLaneA = ALDEBARAN_KEY_A_A_RainbowLaneA;
    std::uint8_t *aRainbowLaneB = ALDEBARAN_KEY_A_A_RainbowLaneB;
    std::uint8_t *aRainbowLaneC = ALDEBARAN_KEY_A_A_RainbowLaneC;
    std::uint8_t *aRainbowLaneD = ALDEBARAN_KEY_A_A_RainbowLaneD;
    std::uint8_t *aWaterLaneA = ALDEBARAN_KEY_A_A_WaterLaneA;
    std::uint8_t *aWaterLaneB = ALDEBARAN_KEY_A_A_WaterLaneB;
    std::uint8_t *aWaterLaneC = ALDEBARAN_KEY_A_A_WaterLaneC;
    std::uint8_t *aWaterLaneD = ALDEBARAN_KEY_A_A_WaterLaneD;
    std::uint8_t *aIceLaneD = ALDEBARAN_KEY_A_A_IceLaneD;
    std::uint8_t *aAlchemyLaneA = ALDEBARAN_KEY_A_A_AlchemyLaneA;
    std::uint8_t *aAuguryLaneA = ALDEBARAN_KEY_A_A_AuguryLaneA;
    std::uint8_t *aPsychicLaneD = ALDEBARAN_KEY_A_A_PsychicLaneD;
    const std::uint64_t &aKeySpawnADomainWordIngress = pWorkSpace->mDomainBundle.mKeySpawnAConstants.mIngress;
    const std::uint64_t &aKeySpawnADomainWordScatter = pWorkSpace->mDomainBundle.mKeySpawnAConstants.mScatter;
    const std::uint64_t &aKeySpawnADomainWordCross = pWorkSpace->mDomainBundle.mKeySpawnAConstants.mCross;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [key arx]
    READ_IN_MUTABLE_PARAMS;
    const std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA5F34A83FBF930ADULL + 0xCE7CD50CA0116A80ULL);
    const std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC60F61CAD18E26E5ULL + 0x9B9251A6BB2B7FAEULL);
    const std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xBEF365B592FC8213ULL + 0xD42F6B73E21CEB03ULL);
    const std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8CCA8CF9FC4580E7ULL + 0xA28013C0FADC9EAAULL);
    const std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD3B7077CDC00CEBFULL + 0xECAF7673090708E0ULL);
    const std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB113E08F86C2C063ULL + 0xA7393641C35CDA68ULL);
    const std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC220E8A6DBAF3FD9ULL + 0x994A3170B1B9DDB1ULL);
    const std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA8F7053CF25EC043ULL + 0xB3ED9CBE95A0790BULL);
    const std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9B83916F8983F4E7ULL + 0xA8DE49612FE9841FULL);
    const std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE572368E080E8795ULL + 0xDB83007DFBAB9757ULL);
    const std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD3ABB9A4D74D8D7DULL + 0xC45786E826651650ULL);
    const std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE9B3FAEE33DC2F7DULL + 0xF4B0E634FFF56B89ULL);
    const std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xAE535BCDE67F3579ULL + 0xDA9D4276D8830707ULL);
    const std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xCEF45CE043264339ULL + 0xA94F52772BA1C6E5ULL);
    const std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE27548288F0CBB25ULL + 0xEB43CED757D64861ULL);
    const std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xBAD5603CB541219DULL + 0x9C8551C945CC89FAULL);
    {
        //
        // File: nexus_06/loop_000247.bin
        //
        // Head:        [10, 6, 0, 8, 3, 5, 2, 7, 1, 4, 9]
        // Tail A:      [10, 1, 7, 6, 8, 3, 9, 2, 5, 0, 4]
        // Tail B:      [0, 10, 8, 9, 1, 7, 3, 4, 2, 5, 6]
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
        // Orbiters:    [KJFDBCAGHEI]
        // Wanderers:   [JIDHBAEFGKC]
        //
        // Ingress:     aRainbowLaneA (-->), aRainbowLaneB (-->), aPlanarLaneB (-->), aAuguryLaneA (<-?->)
        //
        // Cross:       aRainbowLaneC (<--), aRainbowLaneD (<--), aKineticLaneA (<--), aSpiritLaneA (<-?->)
        //
        // Destination: aWaterLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aRainbowLaneA[((aIndex + 960U)) & W_KEY1], 21U) ^ RotL64(aRainbowLaneB[((aIndex + 251U)) & W_KEY1], 58U));
            aIngress ^= (RotL64(aPlanarLaneB[((aIndex + 436U)) & W_KEY1], 3U) ^ RotL64(aAuguryLaneA[(((2047U - aIndex) + 837U)) & W_KEY1], 29U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aKeySpawnADomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aRainbowLaneC[(((2047U - aIndex) + 1101U)) & W_KEY1], 56U) ^ RotL64(aRainbowLaneD[(((2047U - aIndex) + 1857U)) & W_KEY1], 11U));
            aCross ^= (RotL64(aKineticLaneA[(((2047U - aIndex) + 1894U)) & W_KEY1], 37U) ^ RotL64(aSpiritLaneA[(((2047U - aIndex) + 982U)) & W_KEY1], 47U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aKeySpawnADomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 26U)) + (RotL64(aCross, 3U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aKeySpawnADomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterK = ((aWandererC + RotL64(aIngress, 22U)) + 0xE0A4C6D3207F1DEEULL) + aNonceWordE;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 19U)) + 0x152F315B6CC4ED90ULL) + aNonceWordB;
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 13U)) + 0xA55B13D24739907AULL) + aOASaltF[((aIndex + 421U)) & S_SALT1];
            aOrbiterD = (((aWandererG + RotL64(aCross, 41U)) + 0x662B84626B747DBFULL) + aOASaltE[(((511U - aIndex) + 123U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 37U)) + 0x56D10D0947C385E8ULL) + aOASaltC[((aIndex + 374U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aScatter, 60U)) + RotL64(aCarry, 21U)) + 0xC83B26103D1B8E19ULL;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 27U)) + 0x458A8B710A7DE138ULL) + aNonceWordN;
            aOrbiterG = (aWandererF + RotL64(aCross, 57U)) + 0x74C981AAF7EABFBCULL;
            aOrbiterH = (aWandererI + RotL64(aIngress, 13U)) + 0x1B4B2E58199A8A59ULL;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 47U)) + 0x3A98797528731AECULL) + aOASaltG[((aIndex + 294U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aPrevious, 5U)) + 0x1AED06981919F81BULL;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 0x7EF5110C61EB0793ULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 0xDE07C4656CE141AFULL;
            aOrbiterF = RotL64((aOrbiterF * 0x207CC7136CAD5B13ULL), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 0x381822F72AFB3E37ULL;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 0x98DB90524DA704A1ULL;
            aOrbiterC = RotL64((aOrbiterC * 0x71211E4C3E2B1371ULL), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 0x58798DDF18E5B93CULL;
            aOrbiterG = (((aOrbiterG ^ aOrbiterA) ^ 0xEAF4235D727EB0CCULL) ^ aOUSaltC[((aIndex + 166U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 0x1EA3F6C90A444EDBULL), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 0xA0B2341D3E778E0DULL;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 0x4F8F49EC9A55727BULL;
            aOrbiterE = RotL64((aOrbiterE * 0x8BDE1FC4475BF14BULL), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 0x40B98BAE226DFC13ULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 0x983CBCA95A04BC53ULL;
            aOrbiterD = RotL64((aOrbiterD * 0x5E83B81CCD2D4CCFULL), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 0x67E5C2E74187524AULL;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 0xCC5B37779AB48151ULL) ^ aOUSaltF[(((511U - aIndex) + 369U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 0x8BD79673BE2C51D3ULL), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 0xBCD3EFA15A38E319ULL) + aOUSaltH[(((511U - aIndex) + 395U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 0x33E8A0642AFE760FULL;
            aOrbiterK = RotL64((aOrbiterK * 0x47E7CCCEDF6C9695ULL), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 0x6E839F8E2C43E137ULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 0xDD2444DDCB7533DCULL;
            aOrbiterA = RotL64((aOrbiterA * 0x87BF6C202BD7E265ULL), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 0x0DB8215BCE5272AFULL;
            aOrbiterI = (((aOrbiterI ^ aOrbiterC) ^ 0xC1DA295C74FC591CULL) ^ aOUSaltD[(((511U - aIndex) + 465U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 0x317B3AD68E745583ULL), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 0xC8121DE08ADE6F49ULL) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 0xF6E9BE5A14E9BE25ULL;
            aOrbiterH = RotL64((aOrbiterH * 0x099666969CF8CDDFULL), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 0xCBED6C67E269CF14ULL) + aOUSaltB[(((511U - aIndex) + 193U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 0xE8783089DEC91F8FULL;
            aOrbiterB = RotL64((aOrbiterB * 0x0E15F6E2D8A55239ULL), 39U);
            //
            aIngress = RotL64(aOrbiterF, 41U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 6U));
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterK, 37U)) + aWUSaltE[(((511U - aIndex) + 311U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterI, 43U)) + aWUSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 3U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterA, 19U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aIngress, 34U) + RotL64(aOrbiterH, 51U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterG, 46U)) + aWUSaltG[(((511U - aIndex) + 189U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterD, 53U));
            aWandererF = aWandererF ^ ((((RotL64(aCross, 11U) + RotL64(aOrbiterF, 35U)) + aOrbiterB) + aNonceWordH) + aWUSaltF[((aIndex + 162U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterF, 13U));
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 60U) + aOrbiterK) + RotL64(aOrbiterC, 28U)) + RotL64(aCarry, 57U)) + aWUSaltD[(((511U - aIndex) + 206U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 57U)) + aOrbiterA) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 34U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWaterLaneA[(aIndex) & W_KEY1] = aIngress;
        }
    
        //
        // File: nexus_13/loop_000236.bin
        //
        // Head:        [2, 10, 0, 7, 3, 6, 8, 5, 1, 4, 9]
        // Tail A:      [10, 3, 0, 8, 5, 1, 4, 2, 7, 9, 6]
        // Tail B:      [4, 0, 10, 1, 2, 3, 7, 8, 9, 6, 5]
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
        // Orbiters:    [DJFIAHKEBGC]
        // Wanderers:   [FBGCKEADHIJ]
        //
        // Ingress:     aWaterLaneA (-->), aRainbowLaneC (-->), aAetherLaneB (-->), aLunarLaneA (<-?->)
        //
        // Cross:       aRainbowLaneA (<--), aRainbowLaneB (<--), aAlchemyLaneA (<--), aRunicLaneA (<-?->)
        //
        // Destination: aWaterLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWaterLaneA[((aIndex + 1924U)) & W_KEY1], 48U) ^ RotL64(aRainbowLaneC[((aIndex + 1598U)) & W_KEY1], 27U));
            aIngress ^= (RotL64(aAetherLaneB[((aIndex + 1619U)) & W_KEY1], 35U) ^ RotL64(aLunarLaneA[((aIndex + 1204U)) & W_KEY1], 57U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aKeySpawnADomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aRainbowLaneA[(((2047U - aIndex) + 1765U)) & W_KEY1], 20U) ^ RotL64(aRainbowLaneB[(((2047U - aIndex) + 1792U)) & W_KEY1], 57U));
            aCross ^= (RotL64(aAlchemyLaneA[(((2047U - aIndex) + 60U)) & W_KEY1], 47U) ^ RotL64(aRunicLaneA[((aIndex + 1283U)) & W_KEY1], 29U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aKeySpawnADomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 22U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aKeySpawnADomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterD = ((aWandererG + RotL64(aScatter, 53U)) + 0xDB62B4E203CA279EULL) + aNonceWordG;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 50U)) + 0xA9790C17957F78CAULL) + aOASaltH[(((511U - aIndex) + 279U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aCross, 37U)) + 0x57E2CB60D691A6E2ULL;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 5U)) + 0x9B4701C5D37685C9ULL;
            aOrbiterA = (aWandererC + RotL64(aScatter, 39U)) + 0xA8AEFAB8153DF107ULL;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 21U)) + 0xE4E293C1D45F5A92ULL) + aOASaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = (((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 47U)) + 0xDAD027C7EAC5E992ULL) + aNonceWordA;
            aOrbiterE = (aWandererE + RotL64(aIngress, 19U)) + 0x702C967933DD12A3ULL;
            aOrbiterB = (aWandererB + RotL64(aScatter, 28U)) + 0x96A0ECAD5285F5B3ULL;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 41U)) + 0x725F613D481A1B11ULL;
            aOrbiterC = (((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 23U)) + 0x26FDF985437818DFULL) + aOASaltF[(((511U - aIndex) + 403U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 0x85F42E12C9A588C5ULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 0x48BE46312C3E1B73ULL;
            aOrbiterF = RotL64((aOrbiterF * 0x682B4E2BB02B1523ULL), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 0xAB64E88AF16C772EULL;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 0x8390CB7C4D082C3DULL;
            aOrbiterH = RotL64((aOrbiterH * 0x8AA569F1164CFBF7ULL), 39U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterF) + 0x257497655F128A93ULL) + aOUSaltC[(((511U - aIndex) + 108U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 0xA31970CD56C0535AULL) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 0xF3F718AC06C08359ULL), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 0x3DF6777C0D8F08A4ULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 0x6EDD5308AAD71E8BULL;
            aOrbiterA = RotL64((aOrbiterA * 0xAC77909FA1072C33ULL), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 0x9C069C32A6C5C3C8ULL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 0xB0429A2429AAECBCULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0x9BAEF6FBCCCBE2B3ULL), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 0xA33114C910A0C32AULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 0x358C84B441CEF863ULL;
            aOrbiterD = RotL64((aOrbiterD * 0xF98E316594EA6BF1ULL), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 0xEFDDEA1F1AFB86C9ULL) + aOUSaltG[((aIndex + 461U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 0xE5415998A4343096ULL;
            aOrbiterI = RotL64((aOrbiterI * 0xA862DF078AAF63FBULL), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 0x6BB36F9F1BCD302FULL;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 0xE2908392FEC660C4ULL) ^ aOUSaltA[(((511U - aIndex) + 473U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 0x9472CF35A1071A95ULL), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 0xE3F80C049EBC30B9ULL;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 0xED2F9E5DFAC8882FULL;
            aOrbiterB = RotL64((aOrbiterB * 0xE489B7DCF610F321ULL), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 0x47F6D02217B57788ULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 0xF8A33F4EDC6A3D13ULL;
            aOrbiterG = RotL64((aOrbiterG * 0x9DFAF68DF1C72EC9ULL), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 0xEAA1E089EB63A3B4ULL;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 0xEA1592ACDD3C653CULL) ^ aOUSaltB[(((511U - aIndex) + 161U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 0xB961E3FADDF8FECDULL), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 39U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (RotL64(aOrbiterF, 24U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterC, 24U)) + aOrbiterA) + aNonceWordC);
            aWandererB = aWandererB + ((((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 53U)) + aNonceWordI);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 27U)) + aOrbiterC) + aWUSaltD[(((511U - aIndex) + 495U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 35U) + RotL64(aOrbiterB, 51U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 37U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterI, 57U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 24U) + aOrbiterA) + RotL64(aOrbiterE, 13U)) + aWUSaltG[((aIndex + 210U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 11U) + RotL64(aOrbiterF, 44U)) + aOrbiterB) + RotL64(aCarry, 37U)) + aWUSaltH[((aIndex + 50U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 35U)) + aOrbiterG) + aNonceWordH);
            aWandererI = aWandererI + ((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterK, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 21U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererG, 34U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 40U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWaterLaneB[((2047U - aIndex)) & W_KEY1] = aIngress;
        }
    
        //
        // File: nexus_06/loop_000335.bin
        //
        // Head:        [9, 6, 2, 1, 7, 0, 4, 5, 3, 8, 10]
        // Tail A:      [7, 4, 0, 2, 10, 8, 6, 9, 3, 1, 5]
        // Tail B:      [3, 6, 7, 5, 4, 1, 10, 2, 8, 9, 0]
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
        // Orbiters:    [CDAEBFKHIJG]
        // Wanderers:   [DAHCEJKGIFB]
        //
        // Ingress:     aWaterLaneB (-->), aRainbowLaneD (-->), aAetherLaneD (<-?->)
        //
        // Cross:       aWaterLaneA (<--), aRainbowLaneB (<--), aSonicLaneA (<-?->)
        //
        // Destination: aWaterLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWaterLaneB[((aIndex + 480U)) & W_KEY1], 5U) ^ RotL64(aRainbowLaneD[((aIndex + 1107U)) & W_KEY1], 57U));
            aIngress ^= RotL64(aAetherLaneD[(((2047U - aIndex) + 2005U)) & W_KEY1], 26U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aKeySpawnADomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWaterLaneA[(((2047U - aIndex) + 291U)) & W_KEY1], 30U) ^ RotL64(aRainbowLaneB[(((2047U - aIndex) + 896U)) & W_KEY1], 5U));
            aCross ^= RotL64(aSonicLaneA[((aIndex + 178U)) & W_KEY1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aKeySpawnADomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCarry, 21U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aKeySpawnADomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 19U)) + 0xF4AE8D113E4B4290ULL;
            aOrbiterD = ((aWandererK + RotL64(aCross, 58U)) + 0x6B7C4BA60698810AULL) + aOASaltH[(((511U - aIndex) + 185U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aIngress, 29U)) + 0xF5CACCDD6E440E60ULL) + aNonceWordB;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 41U)) + 0xB85772318B28AB3DULL) + aNonceWordP;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 43U)) + RotL64(aCarry, 5U)) + 0x5078DC563AEB47E9ULL;
            aOrbiterF = (aWandererD + RotL64(aCross, 19U)) + 0x708475A5E5C32E52ULL;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 27U)) + 0xAAB6E3A0330901F7ULL) + aOASaltG[((aIndex + 223U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 51U)) + 0x6C7B6531EDC05928ULL;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 51U)) + 0x858A541825A9F72FULL) + aOASaltD[((aIndex + 62U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aCross, 14U)) + 0x8B70C4335C3D2F4BULL) + aNonceWordL;
            aOrbiterG = (aWandererB + RotL64(aIngress, 23U)) + 0xC6035C1C54115BAFULL;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 0x60BCB0106048C093ULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 0x2755554FC1099D9DULL;
            aOrbiterA = RotL64((aOrbiterA * 0x7C67EBF53741698FULL), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 0x2D7C9206E3788384ULL;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 0xE682CF61D54B8B5AULL) ^ aOUSaltA[(((511U - aIndex) + 293U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 0x0EDB413AEAD77F65ULL), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 0xFC7112AE5F2C1F9CULL) + aOUSaltB[((aIndex + 57U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 0x18C6657EF4293C41ULL;
            aOrbiterH = RotL64((aOrbiterH * 0xEE4AAB824C79C4CDULL), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 0x6475B2879897F77BULL;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 0xAD12C4B49B224A9FULL) ^ aOUSaltH[((aIndex + 270U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 0x052684467DC087D5ULL), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 0xA39A9DDAEE1113C5ULL;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 0xA2C31CCF414CFC66ULL;
            aOrbiterE = RotL64((aOrbiterE * 0x50CD62035537C645ULL), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 0x72D23BD04DA1DACAULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 0xEE927532AA9780B7ULL;
            aOrbiterD = RotL64((aOrbiterD * 0x47D782F20A206CFDULL), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 0xF6EDEFCB9FAFE089ULL;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 0x90BB7BA2E2A5371EULL;
            aOrbiterC = RotL64((aOrbiterC * 0x09E0B699CF2D71B9ULL), 11U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterE) + 0x3867623EFD58EAF5ULL) + aOUSaltG[((aIndex + 503U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 0x932A47BF267621FDULL;
            aOrbiterK = RotL64((aOrbiterK * 0xD81B195772A791D3ULL), 3U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 0xA19EBA6E4AA6183DULL) + aOUSaltC[((aIndex + 432U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 0x75843AAA426797B0ULL;
            aOrbiterG = RotL64((aOrbiterG * 0xC8298BD0F8C26613ULL), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 0x88ABBDA6BEB92D9DULL) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 0x8F1E6EB3F586E7A8ULL;
            aOrbiterI = RotL64((aOrbiterI * 0x464C7882B1E18091ULL), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 0x7330742CECF587B3ULL;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 0xED7B3C2F2C77DF95ULL;
            aOrbiterB = RotL64((aOrbiterB * 0x98FEDF03EF189809ULL), 23U);
            //
            aIngress = RotL64(aOrbiterA, 37U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 56U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 10U) + aOrbiterH) + RotL64(aOrbiterE, 24U)) + aNonceWordF);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 29U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 21U)) + aOrbiterH) + aWUSaltE[(((511U - aIndex) + 80U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterA, 57U)) + aOrbiterF) + aNonceWordE);
            aWandererE = aWandererE + (((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 27U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterD, 19U)) + aWUSaltB[(((511U - aIndex) + 107U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterG, 41U)) + aNonceWordK);
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 11U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterI, 14U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 37U)) + aOrbiterJ) + aWUSaltF[(((511U - aIndex) + 1U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 38U) + RotL64(aOrbiterF, 5U)) + aOrbiterC) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 26U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 58U));
            aCarry = aCarry + RotL64(aWandererJ, 41U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWaterLaneC[(aIndex) & W_KEY1] = aIngress;
        }
    
        //
        // File: nexus_07/loop_000134.bin
        //
        // Head:        [10, 4, 0, 3, 7, 5, 9, 2, 1, 8, 6]
        // Tail A:      [0, 9, 4, 7, 5, 2, 6, 1, 3, 8, 10]
        // Tail B:      [7, 2, 6, 8, 10, 4, 3, 9, 0, 5, 1]
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
        // Orbiters:    [GDAFHJKCEIB]
        // Wanderers:   [CGEAHJKIDFB]
        //
        // Ingress:     aWaterLaneC (-->), aWaterLaneA (-->), aSpiritLaneC (<-?->)
        //
        // Cross:       aWaterLaneB (<--), aIceLaneD (<--), aPsychicLaneD (<-?->)
        //
        // Destination: aWaterLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWaterLaneC[((aIndex + 417U)) & W_KEY1], 53U) ^ RotL64(aWaterLaneA[((aIndex + 472U)) & W_KEY1], 35U));
            aIngress ^= RotL64(aSpiritLaneC[(((2047U - aIndex) + 1556U)) & W_KEY1], 26U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aKeySpawnADomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aWaterLaneB[(((2047U - aIndex) + 638U)) & W_KEY1], 60U) ^ RotL64(aIceLaneD[(((2047U - aIndex) + 888U)) & W_KEY1], 23U));
            aCross ^= RotL64(aPsychicLaneD[(((2047U - aIndex) + 1106U)) & W_KEY1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aKeySpawnADomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 43U)) + (RotL64(aCross, 14U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aKeySpawnADomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = (((aWandererB + RotL64(aCross, 51U)) + 0x666F9A15861DDDB4ULL) + aOASaltB[(((511U - aIndex) + 417U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 5U)) + 0xD8C5E1E83A59AD77ULL;
            aOrbiterA = (aWandererC + RotL64(aScatter, 3U)) + 0xBB72A8B9B0CD7D9EULL;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 35U)) + 0x788E0FEE7F40F5CFULL;
            aOrbiterH = ((aWandererI + RotL64(aCross, 30U)) + 0x89AFA3A7BD442631ULL) + aOASaltF[(((511U - aIndex) + 248U)) & S_SALT1];
            aOrbiterJ = ((((aWandererJ + RotL64(aIngress, 27U)) + RotL64(aCarry, 53U)) + 0x1A36BA630F0185F4ULL) + aOASaltD[((aIndex + 345U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = (aWandererF + RotL64(aScatter, 41U)) + 0xB0D31B981E1226E6ULL;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 53U)) + 0x8CEC76FBC90E5A3DULL) + aOASaltE[(((511U - aIndex) + 466U)) & S_SALT1];
            aOrbiterE = (((aWandererG + RotL64(aCross, 43U)) + RotL64(aCarry, 35U)) + 0x410595337AF7AB87ULL) + aNonceWordD;
            aOrbiterI = (aWandererD + RotL64(aIngress, 47U)) + 0x43B6B8CD74AEF6B5ULL;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 18U)) + 0xEC0DC9C2C8BC62A5ULL) + aNonceWordG;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 0xF288D79A978923B5ULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 0x1B1FD70D4A0304E8ULL;
            aOrbiterA = RotL64((aOrbiterA * 0xF940B681EEB0EF03ULL), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 0x37DD7A9B9162C5D2ULL) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 0x21BE0DF7EBA29CF2ULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0x5B0DAAF024C7B063ULL), 29U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterC) + 0xE50A58E2D4B8E1E2ULL) + aOUSaltC[((aIndex + 209U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 0x4A265341B4689816ULL;
            aOrbiterE = RotL64((aOrbiterE * 0xA4BF0429DB6C902DULL), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 0xF8C9FBCDBD3AE18AULL) + aOUSaltH[((aIndex + 174U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 0x0C124BB77F269A4AULL;
            aOrbiterI = RotL64((aOrbiterI * 0xB0A883A52F920CB3ULL), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 0x1FDCF7B4475F7021ULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 0xAA6AD498E1B9F8FEULL;
            aOrbiterG = RotL64((aOrbiterG * 0x2C93762B29F90AD5ULL), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 0x3C17DC136922AE50ULL) + aOUSaltG[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 0x8EF75064C3AF1CA1ULL) ^ aOUSaltB[(((511U - aIndex) + 373U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 0x0DD847ACD42DB5E3ULL), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 0xF6D4C532BB656FA6ULL;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 0x2181DA0B617D067BULL) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 0xB5BAA4C2F02CCC0DULL), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 0x3F79174F171813B3ULL) + aOUSaltD[((aIndex + 317U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 0xE1ACC5C2DB86A4CEULL;
            aOrbiterF = RotL64((aOrbiterF * 0x15267D31FB7318E7ULL), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 0x78D1880EA28BD30DULL;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 0x39D629F4B03C986EULL;
            aOrbiterB = RotL64((aOrbiterB * 0xE7492A5F9156A5F5ULL), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 0x5E7777AA9482A7A1ULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 0x9AEC55DCF941E87CULL;
            aOrbiterD = RotL64((aOrbiterD * 0x6325BF4DB35BB0C7ULL), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 0x0C51598310F8AA98ULL;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 0xF59064ED18CCECE3ULL) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 0x46FA2226AEF8D3E1ULL), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 35U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 26U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 41U)) + aOrbiterC) + aWUSaltB[((aIndex + 407U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 23U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 60U)) + aOrbiterK) + RotL64(aCarry, 41U)) + aWUSaltC[(((511U - aIndex) + 271U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 58U) + RotL64(aOrbiterC, 3U)) + aOrbiterE) + aNonceWordF) + aWUSaltG[(((511U - aIndex) + 403U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 13U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterH, 57U)) + aNonceWordO);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterF, 27U));
            aWandererI = aWandererI + (((RotL64(aCross, 21U) + RotL64(aOrbiterD, 6U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 42U) + RotL64(aOrbiterF, 37U)) + aOrbiterG) + aNonceWordH);
            aWandererF = aWandererF + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 51U)) + aOrbiterJ) + aNonceWordL) + aWUSaltA[((aIndex + 353U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 53U)) + aOrbiterD) + aWUSaltD[(((511U - aIndex) + 510U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 46U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + RotL64(aWandererE, 26U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWaterLaneD[((2047U - aIndex)) & W_KEY1] = aIngress;
        }
    }
    WRITE_OUT_MUTABLE_PARAMS;
}




void TwistExpander_Aldebaran_Arx::KEY_A_A_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     MUTABLE_PARAMS) {
    std::uint64_t *aOASaltA = pWorkSpace->mDomainBundle.mKeySpawnASalts.mOrbiterAssign.mSaltA;
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
    std::uint64_t *aWUSaltE = pWorkSpace->mDomainBundle.mKeySpawnASalts.mWandererUpdate.mSaltE;
    std::uint64_t *aWUSaltF = pWorkSpace->mDomainBundle.mKeySpawnASalts.mWandererUpdate.mSaltF;
    std::uint64_t *aWUSaltG = pWorkSpace->mDomainBundle.mKeySpawnASalts.mWandererUpdate.mSaltG;
    std::uint64_t *aWUSaltH = pWorkSpace->mDomainBundle.mKeySpawnASalts.mWandererUpdate.mSaltH;
    std::uint8_t *aShadowLaneD = ALDEBARAN_KEY_A_A_ShadowLaneD;
    std::uint8_t *aAetherLaneC = ALDEBARAN_KEY_A_A_AetherLaneC;
    std::uint8_t *aKineticLaneD = ALDEBARAN_KEY_A_A_KineticLaneD;
    std::uint8_t *aFrostLaneB = ALDEBARAN_KEY_A_A_FrostLaneB;
    std::uint8_t *aArcaneLaneA = ALDEBARAN_KEY_A_A_ArcaneLaneA;
    std::uint8_t *aArcaneLaneB = ALDEBARAN_KEY_A_A_ArcaneLaneB;
    std::uint8_t *aArcaneLaneC = ALDEBARAN_KEY_A_A_ArcaneLaneC;
    std::uint8_t *aArcaneLaneD = ALDEBARAN_KEY_A_A_ArcaneLaneD;
    std::uint8_t *aLunarLaneD = ALDEBARAN_KEY_A_A_LunarLaneD;
    std::uint8_t *aRunicLaneB = ALDEBARAN_KEY_A_A_RunicLaneB;
    std::uint8_t *aGloomLaneA = ALDEBARAN_KEY_A_A_GloomLaneA;
    std::uint8_t *aGloomLaneD = ALDEBARAN_KEY_A_A_GloomLaneD;
    std::uint8_t *aRainbowLaneD = ALDEBARAN_KEY_A_A_RainbowLaneD;
    std::uint8_t *aFireLaneD = ALDEBARAN_KEY_A_A_FireLaneD;
    std::uint8_t *aIceLaneB = ALDEBARAN_KEY_A_A_IceLaneB;
    std::uint8_t *aPlasmaLaneA = ALDEBARAN_KEY_A_A_PlasmaLaneA;
    std::uint8_t *aPlasmaLaneB = ALDEBARAN_KEY_A_A_PlasmaLaneB;
    std::uint8_t *aPlasmaLaneC = ALDEBARAN_KEY_A_A_PlasmaLaneC;
    std::uint8_t *aPlasmaLaneD = ALDEBARAN_KEY_A_A_PlasmaLaneD;
    std::uint8_t *aVoodooLaneA = ALDEBARAN_KEY_A_A_VoodooLaneA;
    std::uint8_t *aVoodooLaneD = ALDEBARAN_KEY_A_A_VoodooLaneD;
    const std::uint64_t &aKeySpawnADomainWordIngress = pWorkSpace->mDomainBundle.mKeySpawnAConstants.mIngress;
    const std::uint64_t &aKeySpawnADomainWordScatter = pWorkSpace->mDomainBundle.mKeySpawnAConstants.mScatter;
    const std::uint64_t &aKeySpawnADomainWordCross = pWorkSpace->mDomainBundle.mKeySpawnAConstants.mCross;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [key arx]
    READ_IN_MUTABLE_PARAMS;
    const std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD2C00634CCA81AB9ULL + 0xC6B8CCFA8AFF58A2ULL);
    const std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF5C9291976EE99F5ULL + 0xFE5BAB83258AD6FAULL);
    const std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xBD8C1D11F5BC9A67ULL + 0x916920DE0DBE4CF1ULL);
    const std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE9E93F61952079B1ULL + 0xF5A3C94500B101EDULL);
    const std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8AA36FCD3E94DB69ULL + 0xB6280D446F9C4AB5ULL);
    const std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x823E8E12C00E7031ULL + 0xBF576B5A30040382ULL);
    const std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC59162C0A2526A9DULL + 0xF866A7F01EC19FF6ULL);
    const std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC510B2F2CE717801ULL + 0x81A6F7E610FC411BULL);
    const std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9B055DB5D7005B39ULL + 0xCA44529D6B3EF17CULL);
    const std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x907FC2972B6BF5DBULL + 0xEF15CD7327F44C9EULL);
    const std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x8E1EB58CF27BF41FULL + 0xFBFDA80DABC2F449ULL);
    const std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x938BE1404F3CBECFULL + 0xB0652F89E4F30B78ULL);
    const std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xE927B4F14D6568D5ULL + 0xA2B6AD21A9AAA0ADULL);
    const std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD8B7C4BADC021595ULL + 0xC21CEC7D69D1C67CULL);
    const std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD86602EC4B4F91CBULL + 0xD67CA0FE92B1607BULL);
    const std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xA1566BB012051ED9ULL + 0x9311A6A75ED9E3CCULL);
    {
        //
        // File: nexus_10/loop_000001.bin
        //
        // Head:        [5, 0, 2, 4, 7, 9, 6, 8, 3, 10, 1]
        // Tail A:      [5, 4, 6, 1, 10, 2, 9, 8, 0, 3, 7]
        // Tail B:      [9, 1, 10, 2, 4, 5, 3, 0, 6, 7, 8]
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
        // Orbiters:    [BEFADKGJHCI]
        // Wanderers:   [KGFJEIHBCDA]
        //
        // Ingress:     aArcaneLaneD (-->), aArcaneLaneB (-->), aLunarLaneD (-->), aGloomLaneD (<-?->)
        //
        // Cross:       aArcaneLaneC (<--), aArcaneLaneA (<--), aIceLaneB (<--), aKineticLaneD (<-?->)
        //
        // Destination: aPlasmaLaneA
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aArcaneLaneD[((aIndex + 808U)) & W_KEY1], 19U) ^ RotL64(aArcaneLaneB[((aIndex + 1753U)) & W_KEY1], 27U));
            aIngress ^= (RotL64(aLunarLaneD[((aIndex + 633U)) & W_KEY1], 43U) ^ RotL64(aGloomLaneD[((aIndex + 22U)) & W_KEY1], 52U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aKeySpawnADomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aArcaneLaneC[(((2047U - aIndex) + 1666U)) & W_KEY1], 57U) ^ RotL64(aArcaneLaneA[(((2047U - aIndex) + 1417U)) & W_KEY1], 39U));
            aCross ^= (RotL64(aIceLaneB[(((2047U - aIndex) + 1237U)) & W_KEY1], 47U) ^ RotL64(aKineticLaneD[((aIndex + 1779U)) & W_KEY1], 18U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aKeySpawnADomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 22U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aKeySpawnADomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterB = (((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 23U)) + 0xF5B2C2466CB05E0DULL) + aNonceWordB;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 41U)) + 0x5D2C84B04694AE56ULL) + aNonceWordN;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 54U)) + 0x625F755E3340FDF0ULL;
            aOrbiterA = (((aWandererE + RotL64(aCross, 57U)) + 0x1ECF5ADF037CE7D1ULL) + aOASaltE[((aIndex + 259U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = (((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 0xCBC51952ED81D6D0ULL) + aOASaltF[(((511U - aIndex) + 378U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aScatter, 47U)) + 0x5B5063AF112A641DULL;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 43U)) + 0x9D8A924FDE0D5F88ULL) + aNonceWordP;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 21U)) + RotL64(aCarry, 3U)) + 0x96ED35ADA47CDD10ULL) + aOASaltD[((aIndex + 247U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aIngress, 29U)) + 0xD7B53643D7A484A1ULL;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 60U)) + 0x7099207E8479ECAEULL) + aOASaltC[(((511U - aIndex) + 471U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aPrevious, 39U)) + 0x8AEDA74D3951A20DULL;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 0x5AF627B96AAC4B25ULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 0xC52E46A16684B4BCULL;
            aOrbiterF = RotL64((aOrbiterF * 0x4D4CA843EFC8DC21ULL), 19U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterD) + 0x7CE530A30F443CC2ULL) + aOUSaltH[(((511U - aIndex) + 156U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 0xA0C09BF65DC98976ULL;
            aOrbiterK = RotL64((aOrbiterK * 0x2626ECE075705E8BULL), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 0x0D4BC6FE83D9CC87ULL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 0x7A4BB0EDA3785AA0ULL) ^ aOUSaltB[((aIndex + 461U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 0x0903F814FBB74361ULL), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 0x4BE7B43644EEE507ULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 0x1D79E44D19E1493FULL;
            aOrbiterD = RotL64((aOrbiterD * 0xF9A205D7C655C271ULL), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 0xA567899DAD1AF1CAULL;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 0x72B8BADA7A0FC986ULL;
            aOrbiterE = RotL64((aOrbiterE * 0xD205407A8D2D2CCDULL), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 0x57655B6FEA80AA7FULL;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 0xE523B709E8DEFD8CULL;
            aOrbiterB = RotL64((aOrbiterB * 0xB4564C8E5F097E15ULL), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 0xDB6F55CE80B34345ULL) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 0xD2E8C9F688869935ULL;
            aOrbiterA = RotL64((aOrbiterA * 0xB84F98085AE4DDADULL), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 0xBAF660D45C299A69ULL) + aOUSaltA[(((511U - aIndex) + 410U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 0x4A37408788B676A0ULL;
            aOrbiterG = RotL64((aOrbiterG * 0x8F2385EAC9F03AC3ULL), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 0x25C9D9A5C609CA07ULL;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 0x729435DCE0888F73ULL) ^ aOUSaltD[((aIndex + 231U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 0xD02EED9AF37B32E5ULL), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 0x33C7096F94865185ULL) + aOUSaltF[(((511U - aIndex) + 403U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 0x60CC9D8D6689ADD0ULL;
            aOrbiterC = RotL64((aOrbiterC * 0x2F82BCA671AD581BULL), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 0xB12361CF76EEF830ULL) + aOUSaltE[((aIndex + 289U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 0xD3D161A28DA06E70ULL;
            aOrbiterI = RotL64((aOrbiterI * 0xEF5E36C2D28F59C3ULL), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 51U);
            aIngress = aIngress + (RotL64(aOrbiterD, 6U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterC, 27U)) + aWUSaltA[((aIndex + 356U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 54U) + aOrbiterD) + RotL64(aOrbiterE, 3U)) + aWUSaltH[(((511U - aIndex) + 464U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 53U)) + aOrbiterI) + aNonceWordK);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterE, 29U)) + aOrbiterF);
            aWandererE = aWandererE + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 23U)) + aOrbiterD) + RotL64(aCarry, 11U)) + aNonceWordE);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterK, 38U)) + aWUSaltB[(((511U - aIndex) + 502U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 57U)) + aOrbiterA);
            aWandererB = aWandererB ^ ((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterB, 47U));
            aWandererC = aWandererC + ((RotL64(aIngress, 44U) + aOrbiterB) + RotL64(aOrbiterG, 11U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterJ, 35U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 18U)) + aOrbiterH) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 40U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aPlasmaLaneA[(aIndex) & W_KEY1] = aIngress;
        }
    
        //
        // File: nexus_03/loop_000058.bin
        //
        // Head:        [6, 5, 2, 10, 4, 1, 9, 8, 3, 0, 7]
        // Tail A:      [0, 6, 9, 10, 2, 3, 4, 1, 5, 7, 8]
        // Tail B:      [5, 10, 6, 0, 1, 8, 9, 7, 2, 3, 4]
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
        // Orbiters:    [HDABJGCIEFK]
        // Wanderers:   [EFGHDJAKBCI]
        //
        // Ingress:     aPlasmaLaneA (-->), aArcaneLaneC (-->), aGloomLaneA (-->), aVoodooLaneD (<-?->)
        //
        // Cross:       aArcaneLaneD (<--), aArcaneLaneB (<--), aFireLaneD (<--), aFrostLaneB (<-?->)
        //
        // Destination: aPlasmaLaneB
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aPlasmaLaneA[((aIndex + 741U)) & W_KEY1], 37U) ^ RotL64(aArcaneLaneC[((aIndex + 1775U)) & W_KEY1], 46U));
            aIngress ^= (RotL64(aGloomLaneA[((aIndex + 895U)) & W_KEY1], 57U) ^ RotL64(aVoodooLaneD[((aIndex + 1460U)) & W_KEY1], 29U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aKeySpawnADomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aArcaneLaneD[(((2047U - aIndex) + 2047U)) & W_KEY1], 3U) ^ RotL64(aArcaneLaneB[(((2047U - aIndex) + 1319U)) & W_KEY1], 13U));
            aCross ^= (RotL64(aFireLaneD[(((2047U - aIndex) + 1239U)) & W_KEY1], 22U) ^ RotL64(aFrostLaneB[(((2047U - aIndex) + 31U)) & W_KEY1], 37U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aKeySpawnADomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 21U)) + (RotL64(aPrevious, 52U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aKeySpawnADomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterH = (aWandererA + RotL64(aScatter, 50U)) + 0x64FA8757E44A1C68ULL;
            aOrbiterD = (((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 35U)) + 0x60CFD695FBAB7ABEULL) + aOASaltA[(((511U - aIndex) + 32U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aCross, 53U)) + 0x36EB71091FA5D24CULL) + aNonceWordF;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 23U)) + 0x31644B0B7B96AB5BULL) + aOASaltF[((aIndex + 92U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aScatter, 60U)) + 0xA49E89BD8DE89076ULL;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 0xCB9754B71E83D2C4ULL;
            aOrbiterC = (aWandererC + RotL64(aCross, 43U)) + 0xDAE46EABC875D11BULL;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 11U)) + 0xDD63972D458F1821ULL) + aNonceWordD;
            aOrbiterE = (((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 19U)) + 0x5A999D38E7C9D9D0ULL) + aOASaltG[((aIndex + 403U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aPrevious, 27U)) + 0xE374E171290AFEAEULL;
            aOrbiterK = ((aWandererK + RotL64(aCross, 19U)) + 0xFEDB85D833070CF0ULL) + aOASaltB[(((511U - aIndex) + 389U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 0xDEB18DE2115AC18BULL;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 0x1BF2310CC0B2254FULL;
            aOrbiterA = RotL64((aOrbiterA * 0x44F5B3AE2FCC99A9ULL), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 0x2FACA3F4611EF011ULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 0x458E1E9638A8CBE2ULL;
            aOrbiterG = RotL64((aOrbiterG * 0x1B1ACD62BF6D8A17ULL), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 0x98836AF6AEB17AE6ULL) + aOUSaltA[(((511U - aIndex) + 499U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 0xB6C45E1814230826ULL) ^ aOUSaltH[((aIndex + 324U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 0xBEDB8DF4EFC0F0CDULL), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 0x776D7E8CBAA8D69DULL;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 0x1635771189F4763AULL;
            aOrbiterD = RotL64((aOrbiterD * 0x6BC954E9B9B9DA83ULL), 53U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterG) + 0xF885AFEFC850C7D3ULL) + aOUSaltB[(((511U - aIndex) + 326U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 0xFA834D081BD6A55DULL) ^ aOUSaltG[(((511U - aIndex) + 225U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 0xBF63D0CF6E15BA27ULL), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 0x34EB7051557DA37AULL;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 0x56B77F0D1D0CCB62ULL;
            aOrbiterH = RotL64((aOrbiterH * 0x6302385B171E08D1ULL), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 0xF22E565BF7642816ULL;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 0x95DAC704D45481E1ULL;
            aOrbiterB = RotL64((aOrbiterB * 0xB69DCAE9129C33FBULL), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 0x3A9B527F5147AD36ULL) + aOUSaltE[(((511U - aIndex) + 193U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 0xE80A2162ECB571DEULL;
            aOrbiterC = RotL64((aOrbiterC * 0x0BFABA5066B8C835ULL), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 0x2E616AC69ED57B74ULL;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 0xE36D4C5A66F45F0FULL) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 0xE3A695AF2F360473ULL), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 0xCA58FC0E5EEC1B23ULL;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 0x847978F1102A3913ULL;
            aOrbiterE = RotL64((aOrbiterE * 0xBA29A3CFD645E853ULL), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 0xB6235C4C7E8E51F4ULL) + aNonceWordP;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 0x1209A2AFC49ED88DULL) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 0xA12A96BE6870F219ULL), 27U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 37U);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 35U)) + aOrbiterG) + aWUSaltF[((aIndex + 450U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 54U) + aOrbiterC) + RotL64(aOrbiterK, 14U)) + aNonceWordN);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 41U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererH = aWandererH + (((RotL64(aCross, 39U) + RotL64(aOrbiterK, 43U)) + aOrbiterH) + aNonceWordG);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 53U)) + aOrbiterD) + aNonceWordO) + aWUSaltB[(((511U - aIndex) + 51U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 18U) + aOrbiterB) + RotL64(aOrbiterE, 20U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 11U)) + aOrbiterF);
            aWandererK = aWandererK + ((((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterI, 37U)) + RotL64(aCarry, 57U)) + aWUSaltE[((aIndex + 199U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 23U)) + aOrbiterA);
            aWandererC = aWandererC + ((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterB, 27U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 51U)) + aOrbiterJ) + aWUSaltA[(((511U - aIndex) + 58U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 44U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aPlasmaLaneB[((2047U - aIndex)) & W_KEY1] = aIngress;
        }
    
        //
        // File: nexus_06/loop_000341.bin
        //
        // Head:        [5, 4, 8, 7, 0, 9, 1, 2, 6, 3, 10]
        // Tail A:      [3, 7, 9, 1, 8, 5, 10, 2, 0, 6, 4]
        // Tail B:      [6, 10, 2, 8, 3, 1, 0, 4, 5, 9, 7]
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
        // Orbiters:    [KGAIHFJEDBC]
        // Wanderers:   [JFHDCIAEBGK]
        //
        // Ingress:     aPlasmaLaneB (-->), aArcaneLaneD (-->), aAetherLaneC (-->), aShadowLaneD (<-?->)
        //
        // Cross:       aPlasmaLaneA (<--), aArcaneLaneC (<--), aRunicLaneB (<-?->)
        //
        // Destination: aPlasmaLaneC
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aPlasmaLaneB[((aIndex + 257U)) & W_KEY1], 11U) ^ RotL64(aArcaneLaneD[((aIndex + 129U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(aAetherLaneC[((aIndex + 128U)) & W_KEY1], 28U) ^ RotL64(aShadowLaneD[((aIndex + 1006U)) & W_KEY1], 41U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aKeySpawnADomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aPlasmaLaneA[(((2047U - aIndex) + 1483U)) & W_KEY1], 35U) ^ RotL64(aArcaneLaneC[(((2047U - aIndex) + 1005U)) & W_KEY1], 47U));
            aCross ^= RotL64(aRunicLaneB[((aIndex + 457U)) & W_KEY1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aKeySpawnADomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCross, 41U)) + (RotL64(aCarry, 54U) + RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aKeySpawnADomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 41U)) + 0xE5D2FCEBD785A5CCULL) + aNonceWordD;
            aOrbiterG = ((aWandererC + RotL64(aCross, 5U)) + 0x356112EDE28FEC0AULL) + aOASaltB[((aIndex + 335U)) & S_SALT1];
            aOrbiterA = (((aWandererB + RotL64(aIngress, 54U)) + RotL64(aCarry, 29U)) + 0xBA4C924D99EE43BBULL) + aOASaltG[(((511U - aIndex) + 170U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aScatter, 37U)) + 0x88AB7BEF5CC9F26FULL;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 21U)) + 0x0FBDF2BAFBE4C131ULL;
            aOrbiterF = ((aWandererG + RotL64(aCross, 29U)) + 0x0B4E2C2340520631ULL) + aOASaltA[((aIndex + 188U)) & S_SALT1];
            aOrbiterJ = (((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 37U)) + 0xBA7F28C58C988622ULL) + aOASaltE[(((511U - aIndex) + 361U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aScatter, 39U)) + 0x7AF046CD6A5A9E74ULL) + aOASaltH[(((511U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aPrevious, 56U)) + 0xE23297D57A423C3CULL;
            aOrbiterB = (((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 0x80FBBAC93CF32238ULL) + aNonceWordC;
            aOrbiterC = (aWandererK + RotL64(aIngress, 19U)) + 0x34A1F64C599246CCULL;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 0xC874E85AE9F84D65ULL) + aOUSaltA[((aIndex + 511U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 0xC7DF603B312D2DE5ULL;
            aOrbiterA = RotL64((aOrbiterA * 0x6155E07A4298F3C5ULL), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 0x2911584AFC89C357ULL;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 0x64182115670311B7ULL) ^ aOUSaltH[(((511U - aIndex) + 149U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 0x426A8363740DA599ULL), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 0xE47D716E10F6310EULL) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 0xA0EAE2BBE18F9A09ULL;
            aOrbiterE = RotL64((aOrbiterE * 0xDDEAA831FA676595ULL), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 0x63523F7BEF6DA5A4ULL;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 0xF8AEC3E4F2284418ULL) ^ aOUSaltC[((aIndex + 313U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 0x80BC9CBEDFB0EA9FULL), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 0x5450E46514BCF2D1ULL;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 0x140A2F82F5C6A891ULL;
            aOrbiterI = RotL64((aOrbiterI * 0x594E21A6B263AE33ULL), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 0x10C92637EA20CFD8ULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 0x0E2DFDBB1ABA87D8ULL;
            aOrbiterG = RotL64((aOrbiterG * 0xB6F8C7D5610EE475ULL), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 0xC52AD94CD18F0329ULL;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 0xE7ABBEE282AA8D8AULL) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 0xB04276C444076693ULL), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 0x87C7219AA61A68C5ULL) + aOUSaltF[(((511U - aIndex) + 446U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 0x711FAB6A5CB459F5ULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0xF03F42BCDDE2F62BULL), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 0x0293A3F927D94162ULL;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 0x5C851FC24C455A9BULL;
            aOrbiterC = RotL64((aOrbiterC * 0x964341FBB0926AE3ULL), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 0x14599EB76645E3ACULL) + aOUSaltD[(((511U - aIndex) + 481U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 0xEBC3C1E6F8B7A4F2ULL;
            aOrbiterD = RotL64((aOrbiterD * 0xA738F11E576E53AFULL), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 0xFDB8F9A96F9AC1A9ULL;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 0xA85F9FB0A8663CF5ULL;
            aOrbiterH = RotL64((aOrbiterH * 0xD7D3A0E1A3B6F1A7ULL), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 5U);
            aIngress = aIngress + (RotL64(aOrbiterG, 58U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterJ, 28U)) + aNonceWordA);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 21U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 11U)) + aOrbiterA) + aNonceWordF);
            aWandererD = aWandererD ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterG, 37U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aIngress, 58U) + RotL64(aOrbiterD, 53U)) + aOrbiterI) + aWUSaltB[((aIndex + 268U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterG, 18U)) + RotL64(aCarry, 13U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 35U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterH, 41U)) + aNonceWordK) + aWUSaltF[((aIndex + 381U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 6U) + aOrbiterK) + RotL64(aOrbiterF, 39U)) + aWUSaltE[(((511U - aIndex) + 311U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 51U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 23U)) + aOrbiterE) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 6U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererK, 41U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aPlasmaLaneC[(aIndex) & W_KEY1] = aIngress;
        }
    
        //
        // File: nexus_07/loop_000228.bin
        //
        // Head:        [2, 3, 0, 4, 10, 1, 7, 6, 8, 5, 9]
        // Tail A:      [6, 4, 7, 8, 0, 3, 10, 5, 2, 9, 1]
        // Tail B:      [4, 9, 8, 3, 6, 0, 5, 1, 7, 2, 10]
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
        // Orbiters:    [DGIBAHFKJEC]
        // Wanderers:   [FKDGJBIACHE]
        //
        // Ingress:     aPlasmaLaneC (-->), aPlasmaLaneA (-->), aRainbowLaneD (<-?->)
        //
        // Cross:       aPlasmaLaneB (<--), aArcaneLaneD (<--), aVoodooLaneA (<-?->)
        //
        // Destination: aPlasmaLaneD
        //
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(W_KEY); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aPlasmaLaneC[((aIndex + 1823U)) & W_KEY1], 34U) ^ RotL64(aPlasmaLaneA[((aIndex + 1151U)) & W_KEY1], 19U));
            aIngress ^= RotL64(aRainbowLaneD[((aIndex + 662U)) & W_KEY1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aKeySpawnADomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aPlasmaLaneB[(((2047U - aIndex) + 592U)) & W_KEY1], 51U) ^ RotL64(aArcaneLaneD[(((2047U - aIndex) + 1000U)) & W_KEY1], 22U));
            aCross ^= RotL64(aVoodooLaneA[(((2047U - aIndex) + 1085U)) & W_KEY1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aKeySpawnADomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 23U)) + (RotL64(aIngress, 38U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aKeySpawnADomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterD = (((aWandererD + RotL64(aCross, 35U)) + 0x78D8BB61AEC421A3ULL) + aOASaltE[((aIndex + 501U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 27U)) + 0x5613319822C0ECEBULL) + aOASaltD[((aIndex + 356U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aScatter, 21U)) + 0x3D4382A50B6B954DULL;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 3U)) + 0xFC39694378B7EBBDULL;
            aOrbiterA = ((aWandererE + RotL64(aCross, 57U)) + 0xE8675875F50910B3ULL) + aNonceWordA;
            aOrbiterH = (((aWandererK + RotL64(aIngress, 44U)) + 0x2F0DB745139C79EEULL) + aOASaltC[(((511U - aIndex) + 176U)) & S_SALT1]) + aNonceWordC;
            aOrbiterF = (aWandererA + RotL64(aScatter, 41U)) + 0x97C5C697C694540EULL;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 43U)) + 0x54A713DE31F0BB51ULL;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 11U)) + 0xFCF58FDA4AF58DEAULL) + aOASaltB[(((511U - aIndex) + 295U)) & S_SALT1];
            aOrbiterE = (((aWandererB + RotL64(aIngress, 23U)) + 0x905E386E59DAD71BULL) + aOASaltG[(((511U - aIndex) + 55U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 54U)) + RotL64(aCarry, 23U)) + 0x0FCF635ACD6491E8ULL;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 0x73A120293BBEB73BULL) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 0x08979DBD4A7488E3ULL;
            aOrbiterI = RotL64((aOrbiterI * 0x0A5D1172B85E46CFULL), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 0x5B4ADE1F30ADA331ULL) + aOUSaltD[((aIndex + 101U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterB) ^ 0x2E792C3270332707ULL) ^ aOUSaltH[(((511U - aIndex) + 43U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 0xB93C54FDA95DC53FULL), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 0x81A7F5867ED8C3C7ULL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 0xAF82D694A067DBAAULL;
            aOrbiterJ = RotL64((aOrbiterJ * 0x1E380B0AD8640AEFULL), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 0x8B0C25AA112FCB5BULL;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 0x2A23F7B10B197F6BULL) ^ aOUSaltE[((aIndex + 168U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 0xC2615FDABD06C687ULL), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 0x7A53065FC9AF4509ULL) + aOUSaltB[(((511U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 0xD6256D46F1B54720ULL;
            aOrbiterD = RotL64((aOrbiterD * 0x6A50FE6C4CAC2BE5ULL), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 0xB4416834F461C5F8ULL) + aOUSaltC[((aIndex + 79U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 0xC5B1DB51B7530E42ULL;
            aOrbiterA = RotL64((aOrbiterA * 0xA50E969ED250B70DULL), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 0x51C5CF6F277A7AF3ULL;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 0x1D8CAA2F8F4D6827ULL;
            aOrbiterF = RotL64((aOrbiterF * 0xE0D30E1B7EE558E3ULL), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 0x4C90B6CCCA38D82EULL;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 0x5606E6A43C8A2990ULL;
            aOrbiterB = RotL64((aOrbiterB * 0x985A4EAC483D2C27ULL), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 0xDBCE7D6569C5F1C1ULL;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 0xD21BA43920A06BF2ULL;
            aOrbiterC = RotL64((aOrbiterC * 0xBE3B3FB9E82C0A45ULL), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 0x04FCC2E379E922B9ULL;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 0x74185725F359B944ULL;
            aOrbiterG = RotL64((aOrbiterG * 0xD6D522974534DD7BULL), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 0xF9A94FD6E7DC0B58ULL) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 0xB06702293514F915ULL;
            aOrbiterK = RotL64((aOrbiterK * 0x558A553B9048578DULL), 47U);
            //
            aIngress = RotL64(aOrbiterG, 37U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 6U));
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterF, 14U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 37U)) + aOrbiterE) + aWUSaltB[(((511U - aIndex) + 273U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 41U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererG = aWandererG + ((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 29U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 43U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterD, 21U)) + aWUSaltG[((aIndex + 385U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 27U)) + aOrbiterH) + aNonceWordJ);
            aWandererA = aWandererA + ((RotL64(aCross, 28U) + aOrbiterH) + RotL64(aOrbiterG, 3U));
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 35U)) + aOrbiterK) + RotL64(aCarry, 3U)) + aNonceWordF);
            aWandererH = aWandererH + ((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 39U)) + aOrbiterI);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 24U)) + aOrbiterC) + aWUSaltA[(((511U - aIndex) + 131U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 42U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aPlasmaLaneD[((2047U - aIndex)) & W_KEY1] = aIngress;
        }
    }
    WRITE_OUT_MUTABLE_PARAMS;
}



